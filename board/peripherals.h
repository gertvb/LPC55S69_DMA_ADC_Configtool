/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PERIPHERALS_H_
#define _PERIPHERALS_H_

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "fsl_dma.h"
#include "fsl_common.h"
#include "fsl_lpadc.h"
#include "fsl_gpio.h"
#include "fsl_rtc.h"
#include "fsl_ctimer.h"
#include "fsl_clock.h"
#include "usb_device_composite.h"

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/
/* Definitions for BOARD_InitPeripherals functional group */
/* Used DMA device. */
#define DMA0_DMA_BASEADDR DMA0
/* DMA0 interrupt vector ID (number). */
#define DMA0_IRQN DMA0_IRQn

  /* Channel CH0 definitions */
/* Selected DMA channel number. */
#define DMA0_CH0_DMA_CHANNEL 21
/* TCD structure index 0 definition */
#define DMA0_CH0_TCD0_config DMA0_CH0_TCDs_config[0]
/* TCD structure index 1 definition */
#define DMA0_CH0_TCD1_config DMA0_CH0_TCDs_config[1]
/* Alias for ADC0 peripheral */
#define ADC0_PERIPHERAL ADC0
/* Definition of peripheral ID */
#define GPIO_GPIO GPIO
/* Definition of peripheral ID */
#define RTC_PERIPHERAL RTC
/* Definition of peripheral ID */
#define CTIMER0_PERIPHERAL CTIMER0
/* Timer tick frequency in Hz (input frequency of the timer) */
#define CTIMER0_TICK_FREQ 150000000UL
/* Timer tick period in ns (input period of the timer) */
#define CTIMER0_TICK_PERIOD 7UL
/* Definition of PWM period channel. */
#define CTIMER0_PWM_PERIOD_CH kCTIMER_Match_0
/* Definition of channel 3 ID */
#define CTIMER0_MATCH_0_CHANNEL kCTIMER_Match_3

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/
extern dma_handle_t DMA0_CH0_Handle;
/* DMA0 channel CH0 TCD array */
extern dma_descriptor_t DMA0_CH0_TCDs_config[2];
extern const lpadc_config_t ADC0_config;
extern lpadc_conv_command_config_t ADC0_commandsConfig[4];
extern lpadc_conv_trigger_config_t ADC0_triggersConfig[1];
/* Date and time structure */
extern rtc_datetime_t RTC_dateTimeStruct;
extern const ctimer_config_t CTIMER0_config;
extern const ctimer_match_config_t CTIMER0_Match_0_config;

/***********************************************************************************************************************
 * Callback functions
 **********************************************************************************************************************/
/* DMA callback function for the 21 channel.*/
extern void DMA_Callback(struct _dma_handle *, void *, bool, uint32_t);

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/

void BOARD_InitPeripherals(void);

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void);

#if defined(__cplusplus)
}
#endif

#endif /* _PERIPHERALS_H_ */
