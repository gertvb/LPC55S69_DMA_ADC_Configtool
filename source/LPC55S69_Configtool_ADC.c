 /**********************************************************************************************************************************\
 * Title : ADC_and_DMA_Config_Sample                                                                                                *
 *                                                                                                                                  *
 * Author : Gert van Biljon                                                                                                         *
 *                                                                                                                                  *
 * EMail : gertvb@gmail.com                                                                                                         *
 \**********************************************************************************************************************************/

 /**********************************************************************************************************************************\
 * What am I : Sample project where I've set up the LPC55S69's ADC and DMA with the Peripherals ConfigTool in MCUXpresso            *
 *                                                                                                                                  *
 *             The ADC is set up to periodically sample 6 inputs into FIFO 0, and results transferred to RAM via DMA when there are *
 *             more than the FIFO Watermark level of 5 samples in FIFO 0.                                                           *
 *             DMA plays continuous ping pong with 2 Transfer Control Descriptors called consecutively, each descriptor transferring*
 *             to a different RAM destination                                                                                       *
 *                                                                                                                                  *
 * Why : Although I've been involved with embedded stuff since since the 8051, I am new to the MCUXpresso and Config Tools          *
 *       environment, and I couldn't find much info/samples on using the ConfigTools to configure the ADC and DMA on the LPC55S69.  *
 *       I figured that if I battled to get it going, someone else might also be battling to do the same, and I hope this eases     *
 *       your way....                                                                                                               *                                                                                                                                  *
 *                                                                                                                                  *
 * ConfigTools : 1. Top Menu -> ConfigTools -> Peripherals                                                                          *
 *               2. Top Menu -> Configtools -> Pins                                                                                 *
 *               3. Top Menu -> Configtools -> Clocks                                                                               *
 *               4. Top Menu -> Configtools -> Update Code!!!                                                                       *
 *                                                                                                                                  *
 * How it works : 1. ADC set up with 4 conversion commands, 2 inputs each on command 1 and 2, and 1 input each on command 3 and 4   *
 *                   Command 1, Dual CH0 A & B                                                                                      *
 *                   Command 2, Dual CH3 A & B                                                                                      *
 *                   Command 3, Single CH2 A                                                                                        *
 *                   Command 4, Single CH4 A                                                                                        *
 *                2. ADC Conversions are triggered at 18kHz by ADC HW Trigger #5, eg CTimer 0, Match channel 3                      *
 *                3. ADC HW Trigger #5 is set up that the ADC results for Channel A and Channel B both go to FIFO 0                 *
 *                4. Watermerk level on FIFO 0 set to 5, thus the DMA will be triggered to transfer the moment when 6 inputs have   *
 *                   been sampled - Imagine the watermark being the ring of dried out tea near the top of an empty teacup           *                                                                                                   *
 *                5. DMA set up with 2 Transfer Control Descriptors (TCD), each descriptor transferring 6 ADC result values, the 2  *
 *                   TCDs continuously transfer alternately (ping/pong) to 2 different memory destinations.                         *
 *                6. Printing the consecutively sampled values to 2 different Virtual COM ports, one port displaying the numerical  *
 *                   values of the samples, the other plotting a  coloured * with left/right position dependent on value of the     *
 *                   sample (Colour values best displayed on Windows with Tera Term).                                               *
 *                                                                                                                                  *
 * Gotcha's : 1. POWER_DisablePD(kPDRUNCFG_PD_LDOGPADC); must be explicitly called, else the ADC only return 0 for the values....   *
 *                                                                                                                                  *
 * Note : 1. The OKDO E1 board that I am working with doesn't have a 32MHz crystal, hence me running the clock from the 12MHz       *
 *           Free running Oscillator via the PLL                                                                                    *
 *        2. I am NOT at ALL familiar with the NXP Toolchain nor with the LPC55S69, thus I have a lot of gaps in my knowledge in    *
 *           of using the LPC55s69.  Thus my setup of the ADC and DMA is definitely NOT optimal, and I would appreciate feedback on *
 *           my setup!!!                                                                                                            *
 *                                                                                                                                  *
 * Other Info : 1. Mark Dunnett from Embeddedpro has some nice videos on YouTube on the LPC55S69-evk and OKDO E1                    *
 *              2. Jennie Zhang's article on configuring the USB with Config Tool                                                   *
 *                 https://community.nxp.com/t5/LPC-Microcontrollers-Knowledge/Using-ConfigTool-to-create-USB-Project-From-Start/ta-p/1103294
 *              3. El Hughes's stuff on the Mini-monkey and Monkey Jam                                                              *
 *                                                                                                                                  *                                                                                                                        *
 \**********************************************************************************************************************************/
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC55S69_cm33_core0.h"
#include "fsl_debug_console.h"
#include "fsl_power.h"
#include "usb_device_cdc_acm.h" //USB_DeviceCdcAcmSend
#include "terminal_output_routines.h"

extern usb_device_composite_struct_t g_UsbDeviceComposite; //declared in usb_device_composite.c
#define hardcoded_string_length 1000u
#define Happy 1u

//DMA destination addresses, Used in the DMA setup in the Peripheral ConfigTool, for each of the TCD's (Transfer Control Descriptors)
volatile uint32_t u32_ADC_Conversion_Result_via_DMA0_TCD0[6];
volatile uint32_t u32_ADC_Conversion_Result_via_DMA0_TCD1[6];

static volatile bool b_DMA_CallBack_Transfer_Completed = false;
static volatile uint16_t u16_DMA_CallBack_last_TCD_used  = 0;

void DMA_Callback(dma_handle_t *handle, void *param, bool transferDone, uint32_t tcds)
{
    if (transferDone)
    {
    	u16_DMA_CallBack_last_TCD_used = tcds;//Which transfer control descriptor was it that did the last transfer?
    							              //I need to read from the one that is NOT currently being used for transferring, else I may corrupt some of my sample data
    	b_DMA_CallBack_Transfer_Completed = true;
    }
    transferDone = false;
}

int main(void)
{
	BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    PRINTF("Hello All! LPC55S69 MCU; USB, ADC and DMA configured with MCUXpresso ConfigTools\n");
    PRINTF("Printing to USB!!!\n");

    volatile static uint32_t i = 0 ;
    static uint16_t u16_Formatted_chars_in_VCom0_Send_Buffer;
    static uint16_t u16_Formatted_chars_in_VCom2_Send_Buffer;
	static uint8_t s_VCom0_Send_Buffer[hardcoded_string_length];
	static uint8_t s_VCom2_Send_Buffer[hardcoded_string_length];

	usb_device_composite_struct_t *ptr_UsbDeviceComposite;
	ptr_UsbDeviceComposite = &g_UsbDeviceComposite;

	// Enable the GPADC's Low Drop Out Regulator, thus enabling the GPADC
    // Confusingly there are GPADC (bit15) and this one LDOGPADC (bit 19)
    // Seems like the LDOGPADC powers the ADC Analog references
    // UM11126   Table290   Page282   and   Table299 on page 289
    // Bit 19 of the PDRUNCFG0 register
    // Symbol : Confusingly called AUXBIAS?
    // Description : ADC Analog References
    POWER_DisablePD(kPDRUNCFG_PD_LDOGPADC);

    while(Happy)//Oelof, net vir jou!
    {
    	if (b_DMA_CallBack_Transfer_Completed)
    	//Which transfer control descriptor was it that did the last transfer?
        //I need to read from the one that is NOT currently being used for transferring, else I may corrupt some of my sample data
    	{
    		b_DMA_CallBack_Transfer_Completed = false;

    		u16_Formatted_chars_in_VCom0_Send_Buffer = 0;
        	u16_Formatted_chars_in_VCom2_Send_Buffer = 0;

    		if (u16_DMA_CallBack_last_TCD_used == 0)//Meaning that the DMA is now potentially busy with TCD 1
    		{
    	      	u16_Formatted_chars_in_VCom0_Send_Buffer = format_values_into_rainbow_string(s_VCom0_Send_Buffer, hardcoded_string_length, i, 32768, (u32_ADC_Conversion_Result_via_DMA0_TCD0[0] & ADC_RESFIFO_D_MASK), (u32_ADC_Conversion_Result_via_DMA0_TCD0[1] & ADC_RESFIFO_D_MASK), (u32_ADC_Conversion_Result_via_DMA0_TCD0[2] & ADC_RESFIFO_D_MASK), (u32_ADC_Conversion_Result_via_DMA0_TCD0[3] & ADC_RESFIFO_D_MASK), (u32_ADC_Conversion_Result_via_DMA0_TCD0[4] & ADC_RESFIFO_D_MASK), (u32_ADC_Conversion_Result_via_DMA0_TCD0[5] & ADC_RESFIFO_D_MASK));
    	        if (u16_Formatted_chars_in_VCom0_Send_Buffer > 0)
    	        {
    	        	USB_DeviceCdcAcmSend(ptr_UsbDeviceComposite->interface0CicVcomHandle, 2, s_VCom0_Send_Buffer, u16_Formatted_chars_in_VCom0_Send_Buffer);
    	        }
    		}
    		else if  (u16_DMA_CallBack_last_TCD_used == 1)//DMA potentially now using TCD 0
    		{
    	       	u16_Formatted_chars_in_VCom2_Send_Buffer = format_values_into_rainbow_seismograph_line(s_VCom2_Send_Buffer, hardcoded_string_length, (u32_ADC_Conversion_Result_via_DMA0_TCD1[0] & ADC_RESFIFO_D_MASK), (u32_ADC_Conversion_Result_via_DMA0_TCD1[1] & ADC_RESFIFO_D_MASK), (u32_ADC_Conversion_Result_via_DMA0_TCD1[2] & ADC_RESFIFO_D_MASK), (u32_ADC_Conversion_Result_via_DMA0_TCD1[3] & ADC_RESFIFO_D_MASK), (u32_ADC_Conversion_Result_via_DMA0_TCD1[4] & ADC_RESFIFO_D_MASK), (u32_ADC_Conversion_Result_via_DMA0_TCD1[5] & ADC_RESFIFO_D_MASK));
    	        if (u16_Formatted_chars_in_VCom2_Send_Buffer > 0)
    	        {
    	        	USB_DeviceCdcAcmSend(ptr_UsbDeviceComposite->interface2CicVcomHandle, 4, s_VCom2_Send_Buffer, u16_Formatted_chars_in_VCom2_Send_Buffer);
    	        }
    		}
        	else//I should not have come here . . . .
        	{
        		PRINTF("Invalid TCD from DMA!!!!\n");
        	}

    	}//if (b_DMA_CallBack_Transfer_Completed)
    	else
    	{
    		PRINTF("DMA STALLED!!!!\n");
    	}

    	//__asm volatile ("nop");

		i++ ;
    }//while(1)

    return 0 ;
}

//        if (GPIO_PinRead(GPIO, 1, 9))
