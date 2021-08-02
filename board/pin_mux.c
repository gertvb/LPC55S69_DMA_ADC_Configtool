/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v9.0
processor: LPC55S69
package_id: LPC55S69JBD100
mcu_data: ksdk2_0
processor_version: 9.0.2
pin_labels:
- {pin_num: '88', pin_signal: PIO0_5/FC4_RXD_SDA_MOSI_DATA/CTIMER3_MAT0/SCT_GPI5/FC3_RTS_SCL_SSEL1/MCLK/SECURE_GPIO0_5, label: ISP, identifier: sw_ISP}
- {pin_num: '10', pin_signal: PIO1_9/FC1_SCK/CT_INP4/SCT0_OUT2/FC4_CTS_SDA_SSEL0/ADC0_12, label: USER, identifier: sw_USER}
- {pin_num: '86', pin_signal: PIO0_4/FC4_SCK/CT_INP12/SCT_GPI4/FC3_CTS_SDA_SSEL0/SECURE_GPIO0_4, label: Red, identifier: led_RED}
- {pin_num: '89', pin_signal: PIO0_6/FC3_SCK/CT_INP13/CTIMER4_MAT0/SCT_GPI6/SECURE_GPIO0_6, label: Blue, identifier: led_BLUE}
- {pin_num: '6', pin_signal: PIO0_7/FC3_RTS_SCL_SSEL1/SD0_CLK/FC5_SCK/FC1_SCK/SECURE_GPIO0_7, label: Green, identifier: led_GREEN}
- {pin_num: '64', pin_signal: PIO1_18/SD1_POW_EN/SCT0_OUT5/PLU_OUT0, label: WAKE, identifier: sw_WAKE}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: cm33_core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '20', peripheral: ADC0, signal: 'CH, 0', pin_signal: PIO0_23/MCLK/CTIMER1_MAT2/CTIMER3_MAT3/SCT0_OUT4/FC0_CTS_SDA_SSEL0/SD1_D1/SECURE_GPIO0_23/ADC0_0}
  - {pin_num: '14', peripheral: ADC0, signal: 'CH, 8', pin_signal: PIO0_16/FC4_TXD_SCL_MISO_WS/CLKOUT/CT_INP4/SECURE_GPIO0_16/ADC0_8}
  - {pin_num: '22', peripheral: ADC0, signal: 'CH, 2', pin_signal: PIO0_15/FC6_CTS_SDA_SSEL0/UTICK_CAP2/CT_INP16/SCT0_OUT2/SD0_WR_PRT/SECURE_GPIO0_15/ADC0_2}
  - {pin_num: '24', peripheral: ADC0, signal: 'CH, 4', pin_signal: PIO1_8/FC0_CTS_SDA_SSEL0/SD0_CLK/SCT0_OUT1/FC4_SSEL2/ADC0_4}
  - {pin_num: '11', peripheral: ADC0, signal: 'CH, 11', pin_signal: PIO1_0/FC0_RTS_SCL_SSEL1/SD0_D3/CT_INP2/SCT_GPI4/PLU_OUT3/ADC0_11}
  - {pin_num: '23', peripheral: ADC0, signal: 'CH, 3', pin_signal: PIO0_31/FC0_CTS_SDA_SSEL0/SD0_D2/CTIMER0_MAT1/SCT0_OUT3/SECURE_GPIO0_31/ADC0_3}
  - {pin_num: '86', peripheral: GPIO, signal: 'PIO0, 4', pin_signal: PIO0_4/FC4_SCK/CT_INP12/SCT_GPI4/FC3_CTS_SDA_SSEL0/SECURE_GPIO0_4, direction: OUTPUT, gpio_init_state: 'true'}
  - {pin_num: '89', peripheral: GPIO, signal: 'PIO0, 6', pin_signal: PIO0_6/FC3_SCK/CT_INP13/CTIMER4_MAT0/SCT_GPI6/SECURE_GPIO0_6, direction: OUTPUT, gpio_init_state: 'true'}
  - {pin_num: '6', peripheral: GPIO, signal: 'PIO0, 7', pin_signal: PIO0_7/FC3_RTS_SCL_SSEL1/SD0_CLK/FC5_SCK/FC1_SCK/SECURE_GPIO0_7, direction: OUTPUT, gpio_init_state: 'true'}
  - {pin_num: '88', peripheral: GPIO, signal: 'PIO0, 5', pin_signal: PIO0_5/FC4_RXD_SDA_MOSI_DATA/CTIMER3_MAT0/SCT_GPI5/FC3_RTS_SCL_SSEL1/MCLK/SECURE_GPIO0_5, direction: INPUT,
    mode: inactive}
  - {pin_num: '10', peripheral: GPIO, signal: 'PIO1, 9', pin_signal: PIO1_9/FC1_SCK/CT_INP4/SCT0_OUT2/FC4_CTS_SDA_SSEL0/ADC0_12, direction: INPUT}
  - {pin_num: '64', peripheral: GPIO, signal: 'PIO1, 18', pin_signal: PIO1_18/SD1_POW_EN/SCT0_OUT5/PLU_OUT0, direction: INPUT}
  - {pin_num: '53', peripheral: RTC, signal: RTCXOUT, pin_signal: XTAL32K_N}
  - {pin_num: '52', peripheral: RTC, signal: RTCXIN, pin_signal: XTAL32K_P}
  - {pin_num: '78', peripheral: USBFSH, signal: USB_VBUS, pin_signal: PIO0_22/FC6_TXD_SCL_MISO_WS/UTICK_CAP1/CT_INP15/SCT0_OUT3/USB0_VBUS/SD1_D0/PLU_OUT7/SECURE_GPIO0_22}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M33 (Core #0) */
void BOARD_InitPins(void)
{
    /* Enables the clock for the I/O controller.: Enable Clock. */
    CLOCK_EnableClock(kCLOCK_Iocon);

    /* Enables the clock for the GPIO0 module */
    CLOCK_EnableClock(kCLOCK_Gpio0);

    /* Enables the clock for the GPIO1 module */
    CLOCK_EnableClock(kCLOCK_Gpio1);

    gpio_pin_config_t led_RED_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PIO0_4 (pin 86)  */
    GPIO_PinInit(BOARD_INITPINS_led_RED_GPIO, BOARD_INITPINS_led_RED_PORT, BOARD_INITPINS_led_RED_PIN, &led_RED_config);

    gpio_pin_config_t sw_ISP_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO0_5 (pin 88)  */
    GPIO_PinInit(BOARD_INITPINS_sw_ISP_GPIO, BOARD_INITPINS_sw_ISP_PORT, BOARD_INITPINS_sw_ISP_PIN, &sw_ISP_config);

    gpio_pin_config_t led_BLUE_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PIO0_6 (pin 89)  */
    GPIO_PinInit(BOARD_INITPINS_led_BLUE_GPIO, BOARD_INITPINS_led_BLUE_PORT, BOARD_INITPINS_led_BLUE_PIN, &led_BLUE_config);

    gpio_pin_config_t led_GREEN_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U
    };
    /* Initialize GPIO functionality on pin PIO0_7 (pin 6)  */
    GPIO_PinInit(BOARD_INITPINS_led_GREEN_GPIO, BOARD_INITPINS_led_GREEN_PORT, BOARD_INITPINS_led_GREEN_PIN, &led_GREEN_config);

    gpio_pin_config_t gpio0_pin22_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO0_15 (pin 22)  */
    GPIO_PinInit(GPIO, 0U, 15U, &gpio0_pin22_config);

    gpio_pin_config_t gpio0_pin14_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO0_16 (pin 14)  */
    GPIO_PinInit(GPIO, 0U, 16U, &gpio0_pin14_config);

    gpio_pin_config_t gpio0_pin20_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO0_23 (pin 20)  */
    GPIO_PinInit(GPIO, 0U, 23U, &gpio0_pin20_config);

    gpio_pin_config_t gpio0_pin23_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO0_31 (pin 23)  */
    GPIO_PinInit(GPIO, 0U, 31U, &gpio0_pin23_config);

    gpio_pin_config_t gpio1_pin11_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO1_0 (pin 11)  */
    GPIO_PinInit(GPIO, 1U, 0U, &gpio1_pin11_config);

    gpio_pin_config_t gpio1_pin24_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO1_8 (pin 24)  */
    GPIO_PinInit(GPIO, 1U, 8U, &gpio1_pin24_config);

    gpio_pin_config_t sw_USER_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO1_9 (pin 10)  */
    GPIO_PinInit(BOARD_INITPINS_sw_USER_GPIO, BOARD_INITPINS_sw_USER_PORT, BOARD_INITPINS_sw_USER_PIN, &sw_USER_config);

    gpio_pin_config_t sw_WAKE_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PIO1_18 (pin 64)  */
    GPIO_PinInit(BOARD_INITPINS_sw_WAKE_GPIO, BOARD_INITPINS_sw_WAKE_PORT, BOARD_INITPINS_sw_WAKE_PIN, &sw_WAKE_config);

    if (Chip_GetVersion()==1)
    {
        IOCON->PIO[0][15] = ((IOCON->PIO[0][15] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_MODE_MASK | IOCON_PIO_DIGIMODE_MASK | IOCON_PIO_ASW_MASK)))

                         /* Selects pin function.
                          * : PORT015 (pin 22) is configured as ADC0_2. */
                         | IOCON_PIO_FUNC(PIO0_15_FUNC_ALT0)

                         /* Selects function mode (on-chip pull-up/pull-down resistor control).
                          * : Inactive.
                          * Inactive (no pull-down/pull-up resistor enabled). */
                         | IOCON_PIO_MODE(PIO0_15_MODE_INACTIVE)

                         /* Select Digital mode.
                          * : Disable digital mode.
                          * Digital input set to 0. */
                         | IOCON_PIO_DIGIMODE(PIO0_15_DIGIMODE_ANALOG)

                         /* Analog switch input control.
                          * : For all pins except PIO0_9, PIO0_11, PIO0_12, PIO0_15, PIO0_18, PIO0_31, PIO1_0 and
                          * PIO1_9 analog switch is closed (enabled). */
                         | IOCON_PIO_ASW(PIO0_15_ASW_VALUE1));
    }
    else
    {
        IOCON->PIO[0][15] = ((IOCON->PIO[0][15] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_MODE_MASK | IOCON_PIO_DIGIMODE_MASK | IOCON_PIO_ASW_MASK)))

                         /* Selects pin function.
                          * : PORT015 (pin 22) is configured as ADC0_2. */
                         | IOCON_PIO_FUNC(PIO0_15_FUNC_ALT0)

                         /* Selects function mode (on-chip pull-up/pull-down resistor control).
                          * : Inactive.
                          * Inactive (no pull-down/pull-up resistor enabled). */
                         | IOCON_PIO_MODE(PIO0_15_MODE_INACTIVE)

                         /* Select Digital mode.
                          * : Disable digital mode.
                          * Digital input set to 0. */
                         | IOCON_PIO_DIGIMODE(PIO0_15_DIGIMODE_ANALOG)

                         /* Analog switch input control.
                          * : For all pins except PIO0_9, PIO0_11, PIO0_12, PIO0_15, PIO0_18, PIO0_31, PIO1_0 and
                          * PIO1_9 analog switch is closed (enabled). */
                         | IOCON_PIO_ASW(PIO0_15_ASW_VALUE0));
    }

    IOCON->PIO[0][16] = ((IOCON->PIO[0][16] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_MODE_MASK | IOCON_PIO_DIGIMODE_MASK | IOCON_PIO_ASW_MASK)))

                         /* Selects pin function.
                          * : PORT016 (pin 14) is configured as ADC0_8. */
                         | IOCON_PIO_FUNC(PIO0_16_FUNC_ALT0)

                         /* Selects function mode (on-chip pull-up/pull-down resistor control).
                          * : Inactive.
                          * Inactive (no pull-down/pull-up resistor enabled). */
                         | IOCON_PIO_MODE(PIO0_16_MODE_INACTIVE)

                         /* Select Digital mode.
                          * : Disable digital mode.
                          * Digital input set to 0. */
                         | IOCON_PIO_DIGIMODE(PIO0_16_DIGIMODE_ANALOG)

                         /* Analog switch input control.
                          * : For all pins except PIO0_9, PIO0_11, PIO0_12, PIO0_15, PIO0_18, PIO0_31, PIO1_0 and
                          * PIO1_9 analog switch is closed (enabled). */
                         | IOCON_PIO_ASW(PIO0_16_ASW_VALUE1));

    IOCON->PIO[0][22] = ((IOCON->PIO[0][22] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                         /* Selects pin function.
                          * : PORT022 (pin 78) is configured as USB0_VBUS. */
                         | IOCON_PIO_FUNC(PIO0_22_FUNC_ALT7)

                         /* Select Digital mode.
                          * : Enable Digital mode.
                          * Digital input is enabled. */
                         | IOCON_PIO_DIGIMODE(PIO0_22_DIGIMODE_DIGITAL));

    IOCON->PIO[0][23] = ((IOCON->PIO[0][23] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_MODE_MASK | IOCON_PIO_DIGIMODE_MASK | IOCON_PIO_ASW_MASK)))

                         /* Selects pin function.
                          * : PORT023 (pin 20) is configured as ADC0_0. */
                         | IOCON_PIO_FUNC(PIO0_23_FUNC_ALT0)

                         /* Selects function mode (on-chip pull-up/pull-down resistor control).
                          * : Inactive.
                          * Inactive (no pull-down/pull-up resistor enabled). */
                         | IOCON_PIO_MODE(PIO0_23_MODE_INACTIVE)

                         /* Select Digital mode.
                          * : Disable digital mode.
                          * Digital input set to 0. */
                         | IOCON_PIO_DIGIMODE(PIO0_23_DIGIMODE_ANALOG)

                         /* Analog switch input control.
                          * : For all pins except PIO0_9, PIO0_11, PIO0_12, PIO0_15, PIO0_18, PIO0_31, PIO1_0 and
                          * PIO1_9 analog switch is closed (enabled). */
                         | IOCON_PIO_ASW(PIO0_23_ASW_VALUE1));

    if (Chip_GetVersion()==1)
    {
        IOCON->PIO[0][31] = ((IOCON->PIO[0][31] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_MODE_MASK | IOCON_PIO_DIGIMODE_MASK | IOCON_PIO_ASW_MASK)))

                         /* Selects pin function.
                          * : PORT031 (pin 23) is configured as ADC0_3. */
                         | IOCON_PIO_FUNC(PIO0_31_FUNC_ALT0)

                         /* Selects function mode (on-chip pull-up/pull-down resistor control).
                          * : Inactive.
                          * Inactive (no pull-down/pull-up resistor enabled). */
                         | IOCON_PIO_MODE(PIO0_31_MODE_INACTIVE)

                         /* Select Digital mode.
                          * : Disable digital mode.
                          * Digital input set to 0. */
                         | IOCON_PIO_DIGIMODE(PIO0_31_DIGIMODE_ANALOG)

                         /* Analog switch input control.
                          * : For all pins except PIO0_9, PIO0_11, PIO0_12, PIO0_15, PIO0_18, PIO0_31, PIO1_0 and
                          * PIO1_9 analog switch is closed (enabled). */
                         | IOCON_PIO_ASW(PIO0_31_ASW_VALUE1));
    }
    else
    {
        IOCON->PIO[0][31] = ((IOCON->PIO[0][31] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_MODE_MASK | IOCON_PIO_DIGIMODE_MASK | IOCON_PIO_ASW_MASK)))

                         /* Selects pin function.
                          * : PORT031 (pin 23) is configured as ADC0_3. */
                         | IOCON_PIO_FUNC(PIO0_31_FUNC_ALT0)

                         /* Selects function mode (on-chip pull-up/pull-down resistor control).
                          * : Inactive.
                          * Inactive (no pull-down/pull-up resistor enabled). */
                         | IOCON_PIO_MODE(PIO0_31_MODE_INACTIVE)

                         /* Select Digital mode.
                          * : Disable digital mode.
                          * Digital input set to 0. */
                         | IOCON_PIO_DIGIMODE(PIO0_31_DIGIMODE_ANALOG)

                         /* Analog switch input control.
                          * : For all pins except PIO0_9, PIO0_11, PIO0_12, PIO0_15, PIO0_18, PIO0_31, PIO1_0 and
                          * PIO1_9 analog switch is closed (enabled). */
                         | IOCON_PIO_ASW(PIO0_31_ASW_VALUE0));
    }

    IOCON->PIO[0][4] = ((IOCON->PIO[0][4] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                        /* Selects pin function.
                         * : PORT04 (pin 86) is configured as PIO0_4. */
                        | IOCON_PIO_FUNC(PIO0_4_FUNC_ALT0)

                        /* Select Digital mode.
                         * : Enable Digital mode.
                         * Digital input is enabled. */
                        | IOCON_PIO_DIGIMODE(PIO0_4_DIGIMODE_DIGITAL));

    IOCON->PIO[0][5] = ((IOCON->PIO[0][5] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_MODE_MASK | IOCON_PIO_DIGIMODE_MASK)))

                        /* Selects pin function.
                         * : PORT05 (pin 88) is configured as PIO0_5. */
                        | IOCON_PIO_FUNC(PIO0_5_FUNC_ALT0)

                        /* Selects function mode (on-chip pull-up/pull-down resistor control).
                         * : Inactive.
                         * Inactive (no pull-down/pull-up resistor enabled). */
                        | IOCON_PIO_MODE(PIO0_5_MODE_INACTIVE)

                        /* Select Digital mode.
                         * : Enable Digital mode.
                         * Digital input is enabled. */
                        | IOCON_PIO_DIGIMODE(PIO0_5_DIGIMODE_DIGITAL));

    IOCON->PIO[0][6] = ((IOCON->PIO[0][6] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                        /* Selects pin function.
                         * : PORT06 (pin 89) is configured as PIO0_6. */
                        | IOCON_PIO_FUNC(PIO0_6_FUNC_ALT0)

                        /* Select Digital mode.
                         * : Enable Digital mode.
                         * Digital input is enabled. */
                        | IOCON_PIO_DIGIMODE(PIO0_6_DIGIMODE_DIGITAL));

    IOCON->PIO[0][7] = ((IOCON->PIO[0][7] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                        /* Selects pin function.
                         * : PORT07 (pin 6) is configured as PIO0_7. */
                        | IOCON_PIO_FUNC(PIO0_7_FUNC_ALT0)

                        /* Select Digital mode.
                         * : Enable Digital mode.
                         * Digital input is enabled. */
                        | IOCON_PIO_DIGIMODE(PIO0_7_DIGIMODE_DIGITAL));

    if (Chip_GetVersion()==1)
    {
        IOCON->PIO[1][0] = ((IOCON->PIO[1][0] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_MODE_MASK | IOCON_PIO_DIGIMODE_MASK | IOCON_PIO_ASW_MASK)))

                        /* Selects pin function.
                         * : PORT10 (pin 11) is configured as ADC0_11. */
                        | IOCON_PIO_FUNC(PIO1_0_FUNC_ALT0)

                        /* Selects function mode (on-chip pull-up/pull-down resistor control).
                         * : Inactive.
                         * Inactive (no pull-down/pull-up resistor enabled). */
                        | IOCON_PIO_MODE(PIO1_0_MODE_INACTIVE)

                        /* Select Digital mode.
                         * : Disable digital mode.
                         * Digital input set to 0. */
                        | IOCON_PIO_DIGIMODE(PIO1_0_DIGIMODE_ANALOG)

                        /* Analog switch input control.
                         * : For all pins except PIO0_9, PIO0_11, PIO0_12, PIO0_15, PIO0_18, PIO0_31, PIO1_0 and
                         * PIO1_9 analog switch is closed (enabled). */
                        | IOCON_PIO_ASW(PIO1_0_ASW_VALUE1));
    }
    else
    {
        IOCON->PIO[1][0] = ((IOCON->PIO[1][0] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_MODE_MASK | IOCON_PIO_DIGIMODE_MASK | IOCON_PIO_ASW_MASK)))

                        /* Selects pin function.
                         * : PORT10 (pin 11) is configured as ADC0_11. */
                        | IOCON_PIO_FUNC(PIO1_0_FUNC_ALT0)

                        /* Selects function mode (on-chip pull-up/pull-down resistor control).
                         * : Inactive.
                         * Inactive (no pull-down/pull-up resistor enabled). */
                        | IOCON_PIO_MODE(PIO1_0_MODE_INACTIVE)

                        /* Select Digital mode.
                         * : Disable digital mode.
                         * Digital input set to 0. */
                        | IOCON_PIO_DIGIMODE(PIO1_0_DIGIMODE_ANALOG)

                        /* Analog switch input control.
                         * : For all pins except PIO0_9, PIO0_11, PIO0_12, PIO0_15, PIO0_18, PIO0_31, PIO1_0 and
                         * PIO1_9 analog switch is closed (enabled). */
                        | IOCON_PIO_ASW(PIO1_0_ASW_VALUE0));
    }

    IOCON->PIO[1][18] = ((IOCON->PIO[1][18] &
                          /* Mask bits to zero which are setting */
                          (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                         /* Selects pin function.
                          * : PORT118 (pin 64) is configured as PIO1_18. */
                         | IOCON_PIO_FUNC(PIO1_18_FUNC_ALT0)

                         /* Select Digital mode.
                          * : Enable Digital mode.
                          * Digital input is enabled. */
                         | IOCON_PIO_DIGIMODE(PIO1_18_DIGIMODE_DIGITAL));

    IOCON->PIO[1][8] = ((IOCON->PIO[1][8] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_MODE_MASK | IOCON_PIO_DIGIMODE_MASK | IOCON_PIO_ASW_MASK)))

                        /* Selects pin function.
                         * : PORT18 (pin 24) is configured as ADC0_4. */
                        | IOCON_PIO_FUNC(PIO1_8_FUNC_ALT0)

                        /* Selects function mode (on-chip pull-up/pull-down resistor control).
                         * : Inactive.
                         * Inactive (no pull-down/pull-up resistor enabled). */
                        | IOCON_PIO_MODE(PIO1_8_MODE_INACTIVE)

                        /* Select Digital mode.
                         * : Disable digital mode.
                         * Digital input set to 0. */
                        | IOCON_PIO_DIGIMODE(PIO1_8_DIGIMODE_ANALOG)

                        /* Analog switch input control.
                         * : For all pins except PIO0_9, PIO0_11, PIO0_12, PIO0_15, PIO0_18, PIO0_31, PIO1_0 and
                         * PIO1_9 analog switch is closed (enabled). */
                        | IOCON_PIO_ASW(PIO1_8_ASW_VALUE1));

    if (Chip_GetVersion()==1)
    {
        IOCON->PIO[1][9] = ((IOCON->PIO[1][9] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                        /* Selects pin function.
                         * : PORT19 (pin 10) is configured as PIO1_9. */
                        | IOCON_PIO_FUNC(PIO1_9_FUNC_ALT0)

                        /* Select Digital mode.
                         * : Enable Digital mode.
                         * Digital input is enabled. */
                        | IOCON_PIO_DIGIMODE(PIO1_9_DIGIMODE_DIGITAL));
    }
    else
    {
        IOCON->PIO[1][9] = ((IOCON->PIO[1][9] &
                         /* Mask bits to zero which are setting */
                         (~(IOCON_PIO_FUNC_MASK | IOCON_PIO_DIGIMODE_MASK)))

                        /* Selects pin function.
                         * : PORT19 (pin 10) is configured as PIO1_9. */
                        | IOCON_PIO_FUNC(PIO1_9_FUNC_ALT0)

                        /* Select Digital mode.
                         * : Enable Digital mode.
                         * Digital input is enabled. */
                        | IOCON_PIO_DIGIMODE(PIO1_9_DIGIMODE_DIGITAL));
    }
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
