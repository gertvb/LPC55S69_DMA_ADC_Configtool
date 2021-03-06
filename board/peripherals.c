/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Peripherals v9.0
processor: LPC55S69
package_id: LPC55S69JBD100
mcu_data: ksdk2_0
processor_version: 9.0.2
functionalGroups:
- name: BOARD_InitPeripherals
  UUID: 59a3ecc7-aa6a-4d2b-bae0-3711c51c4dbe
  called_from_default_init: true
  selectedCore: cm33_core0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'system'
- type_id: 'system_54b53072540eeeb8f8e9343e71f28176'
- global_system_definitions:
  - user_definitions: ''
  - user_includes: ''
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "peripherals.h"

/***********************************************************************************************************************
 * BOARD_InitPeripherals functional group
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * DMA0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'DMA0'
- type: 'lpc_dma'
- mode: 'basic'
- custom_name_enabled: 'false'
- type_id: 'lpc_dma_c13ca997a68f2ca6c666916ba13db7d7'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'DMA0'
- config_sets:
  - fsl_dma:
    - dma_table:
      - 0: []
    - dma_channels:
      - 0:
        - apiMode: 'trans'
        - dma_channel:
          - channel_prefix_id: 'CH0'
          - DMA_source: 'kDma0RequestADC0FIFO0'
          - init_channel_priority: 'false'
          - dma_priority: 'kDMA_ChannelPriority0'
          - enable_custom_name: 'false'
        - peripheral_request: 'true'
        - init_trigger_config: 'true'
        - trigger_config:
          - type: 'kDMA_LowLevelTrigger'
          - burst: 'kDMA_EdgeBurstTransfer8'
          - wrap: 'kDMA_DstWrap'
        - trans_config:
          - init_callback: 'true'
          - callback_function: 'DMA_Callback'
          - callback_user_data: ''
        - tcd_config:
          - 0:
            - tcdID: 'CH0_TCD0'
            - linkToNextTCD: '1'
            - transferCfg:
              - reload: 'true'
              - clrTrig: 'true'
              - intA: 'true'
              - intB: 'false'
              - width: 'kDMA_Transfer32BitWidth'
              - srcInc: 'kDMA_AddressInterleave0xWidth'
              - dstInc: 'kDMA_AddressInterleave1xWidth'
              - transBytes: '24'
            - srcAddr:
              - addrType: 'startAddr'
              - addr_expr: '(uint32_t)(&(ADC0-:RESFIFO[0]))'
              - addr_def: ''
            - dstAddr:
              - addrType: 'startAddr'
              - addr_expr: '(uint32_t)(&u32_ADC_Conversion_Result_via_DMA0_TCD0)'
              - addr_def: 'uint32_t u32_ADC_Conversion_Result_via_DMA0_TCD0[6]'
          - 1:
            - tcdID: 'CH0_TCD1'
            - linkToNextTCD: '0'
            - transferCfg:
              - reload: 'true'
              - clrTrig: 'true'
              - intA: 'false'
              - intB: 'true'
              - width: 'kDMA_Transfer32BitWidth'
              - srcInc: 'kDMA_AddressInterleave0xWidth'
              - dstInc: 'kDMA_AddressInterleave1xWidth'
              - transBytes: '24'
            - srcAddr:
              - addrType: 'startAddr'
              - addr_expr: '(uint32_t)(&(ADC0-:RESFIFO[0]))'
              - addr_def: ''
            - dstAddr:
              - addrType: 'startAddr'
              - addr_expr: '(uint32_t)(&u32_ADC_Conversion_Result_via_DMA0_TCD1)'
              - addr_def: 'uint32_t u32_ADC_Conversion_Result_via_DMA0_TCD1[6]'
        - allocateTCD: 'noncache'
        - initTCD: 'CH0_TCD0'
    - dma_interrupt_trans:
      - IRQn: 'DMA0_IRQn'
      - enable_priority: 'false'
      - priority: '0'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

  /* Channel CH0 global variables */
dma_handle_t DMA0_CH0_Handle;
const dma_channel_trigger_t DMA0_CH0_trigger_config = {
  .type = kDMA_LowLevelTrigger,
  .burst = kDMA_EdgeBurstTransfer8,
  .wrap = kDMA_DstWrap
};
/* CH0_TCD0 destination address extern definition */
extern uint32_t u32_ADC_Conversion_Result_via_DMA0_TCD0[6];
/* CH0_TCD1 destination address extern definition */
extern uint32_t u32_ADC_Conversion_Result_via_DMA0_TCD1[6];
AT_NONCACHEABLE_SECTION_ALIGN( dma_descriptor_t DMA0_CH0_TCDs_config[2], FSL_FEATURE_DMA_LINK_DESCRIPTOR_ALIGN_SIZE )
 = {
  {
    .xfercfg = DMA_CHANNEL_XFER(true, true, true, false, kDMA_Transfer32BitWidth, kDMA_AddressInterleave0xWidth, kDMA_AddressInterleave1xWidth, 24U),
    .srcEndAddr = (void *)DMA_DESCRIPTOR_END_ADDRESS((uint32_t)(&(ADC0->RESFIFO[0])), (uint32_t)kDMA_AddressInterleave0xWidth, 24U, (uint32_t)kDMA_Transfer32BitWidth),
    .dstEndAddr = (void *)DMA_DESCRIPTOR_END_ADDRESS((uint32_t)(&u32_ADC_Conversion_Result_via_DMA0_TCD0), (uint32_t)kDMA_AddressInterleave1xWidth, 24U, (uint32_t)kDMA_Transfer32BitWidth),
    .linkToNextDesc = &DMA0_CH0_TCD1_config
  },
  {
    .xfercfg = DMA_CHANNEL_XFER(true, true, false, true, kDMA_Transfer32BitWidth, kDMA_AddressInterleave0xWidth, kDMA_AddressInterleave1xWidth, 24U),
    .srcEndAddr = (void *)DMA_DESCRIPTOR_END_ADDRESS((uint32_t)(&(ADC0->RESFIFO[0])), (uint32_t)kDMA_AddressInterleave0xWidth, 24U, (uint32_t)kDMA_Transfer32BitWidth),
    .dstEndAddr = (void *)DMA_DESCRIPTOR_END_ADDRESS((uint32_t)(&u32_ADC_Conversion_Result_via_DMA0_TCD1), (uint32_t)kDMA_AddressInterleave1xWidth, 24U, (uint32_t)kDMA_Transfer32BitWidth),
    .linkToNextDesc = &DMA0_CH0_TCD0_config
  }
};

static void DMA0_init(void) {

  /* Channel CH0 initialization */
  /* Enable the DMA 21channel in the DMA */
  DMA_EnableChannel(DMA0_DMA_BASEADDR, DMA0_CH0_DMA_CHANNEL);
  /* Create the DMA DMA0_CH0_Handlehandle */
  DMA_CreateHandle(&DMA0_CH0_Handle, DMA0_DMA_BASEADDR, DMA0_CH0_DMA_CHANNEL);
  DMA_SetCallback(&DMA0_CH0_Handle, DMA_Callback, NULL);
  /* Configuration of the channel trigger and peripheral request */
  DMA_SetChannelConfig(DMA0_DMA_BASEADDR, DMA0_CH0_DMA_CHANNEL, (dma_channel_trigger_t *)&DMA0_CH0_trigger_config, true);
  /* DMA0 transfer submit */
  DMA_SubmitChannelDescriptor(&DMA0_CH0_Handle, &DMA0_CH0_TCD0_config);
}

/***********************************************************************************************************************
 * ADC0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'ADC0'
- type: 'lpadc'
- mode: 'LPADC'
- custom_name_enabled: 'false'
- type_id: 'lpadc_37e603c0367b4bb173ded9b76a178984'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'ADC0'
- config_sets:
  - fsl_lpadc:
    - lpadcConfig:
      - clockSource: 'AsynchronousFunctionClock'
      - clockSourceFreq: 'BOARD_BootClockRUN'
      - enableInDozeMode: 'true'
      - conversionAverageMode: 'kLPADC_ConversionAverage128'
      - offsetCalibration: 'yes'
      - autoCalibrate: 'true'
      - enableAnalogPreliminary: 'true'
      - powerUpDelay: '0x80'
      - referenceVoltageSource: 'kLPADC_ReferenceVoltageAlt2'
      - powerLevelMode: 'kLPADC_PowerLevelAlt4'
      - triggerPriorityPolicy: 'kLPADC_TriggerPriorityPreemptSubsequently'
      - enableConvPause: 'false'
      - convPauseDelay: '0'
      - FIFO0Watermark: '6'
      - FIFO1Watermark: '0'
      - FIFO0WatermarkDMA: 'true'
      - FIFO1WatermarkDMA: 'false'
    - lpadcConvCommandConfig:
      - 0:
        - commandId: '1'
        - chainedNextCommandNumber: '2'
        - sampleChannelMode: 'kLPADC_SampleChannelDualSingleEndBothSide'
        - channelNumber: 'CH.0'
        - enableAutoChannelIncrement: 'false'
        - loopCount: '0'
        - hardwareAverageMode: 'kLPADC_HardwareAverageCount4'
        - sampleTimeMode: 'kLPADC_SampleTimeADCK7'
        - hardwareCompareMode: 'kLPADC_HardwareCompareDisabled'
        - hardwareCompareValueHigh: '0'
        - hardwareCompareValueLow: '0'
        - conversionResoultuionMode: 'kLPADC_ConversionResolutionHigh'
        - enableWaitTrigger: 'false'
      - 1:
        - commandId: '2'
        - chainedNextCommandNumber: '3'
        - sampleChannelMode: 'kLPADC_SampleChannelDualSingleEndBothSide'
        - channelNumber: 'CH.3'
        - enableAutoChannelIncrement: 'false'
        - loopCount: '0'
        - hardwareAverageMode: 'kLPADC_HardwareAverageCount4'
        - sampleTimeMode: 'kLPADC_SampleTimeADCK7'
        - hardwareCompareMode: 'kLPADC_HardwareCompareDisabled'
        - hardwareCompareValueHigh: '0'
        - hardwareCompareValueLow: '0'
        - conversionResoultuionMode: 'kLPADC_ConversionResolutionHigh'
        - enableWaitTrigger: 'false'
      - 2:
        - commandId: '3'
        - chainedNextCommandNumber: '4'
        - sampleChannelMode: 'kLPADC_SampleChannelSingleEndSideA'
        - channelNumber: 'CH.2'
        - enableAutoChannelIncrement: 'false'
        - loopCount: '0'
        - hardwareAverageMode: 'kLPADC_HardwareAverageCount4'
        - sampleTimeMode: 'kLPADC_SampleTimeADCK7'
        - hardwareCompareMode: 'kLPADC_HardwareCompareDisabled'
        - hardwareCompareValueHigh: '0'
        - hardwareCompareValueLow: '0'
        - conversionResoultuionMode: 'kLPADC_ConversionResolutionHigh'
        - enableWaitTrigger: 'false'
      - 3:
        - commandId: '4'
        - chainedNextCommandNumber: '0'
        - sampleChannelMode: 'kLPADC_SampleChannelSingleEndSideA'
        - channelNumber: 'CH.4'
        - enableAutoChannelIncrement: 'false'
        - loopCount: '0'
        - hardwareAverageMode: 'kLPADC_HardwareAverageCount4'
        - sampleTimeMode: 'kLPADC_SampleTimeADCK7'
        - hardwareCompareMode: 'kLPADC_HardwareCompareDisabled'
        - hardwareCompareValueHigh: '0'
        - hardwareCompareValueLow: '0'
        - conversionResoultuionMode: 'kLPADC_ConversionResolutionHigh'
        - enableWaitTrigger: 'false'
    - lpadcConvTriggerConfig:
      - 0:
        - triggerId: '5'
        - targetCommandId: '1'
        - delayPower: '0'
        - priority: 'false'
        - channelAFIFOSelect: '0'
        - channelBFIFOSelect: '0'
        - enableHardwareTrigger: 'true'
    - IRQ_cfg:
      - interrupt_type: ''
      - enable_irq: 'false'
      - adc_interrupt:
        - IRQn: 'ADC0_IRQn'
        - enable_interrrupt: 'enabled'
        - enable_priority: 'false'
        - priority: '0'
        - enable_custom_name: 'false'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const lpadc_config_t ADC0_config = {
  .enableInDozeMode = true,
  .conversionAverageMode = kLPADC_ConversionAverage128,
  .enableAnalogPreliminary = true,
  .powerUpDelay = 0x80UL,
  .referenceVoltageSource = kLPADC_ReferenceVoltageAlt2,
  .powerLevelMode = kLPADC_PowerLevelAlt4,
  .triggerPriorityPolicy = kLPADC_TriggerPriorityPreemptSubsequently,
  .enableConvPause = false,
  .convPauseDelay = 0UL,
  .FIFO0Watermark = 6UL,
  .FIFO1Watermark = 0UL
};
lpadc_conv_command_config_t ADC0_commandsConfig[4] = {
  {
    .sampleChannelMode = kLPADC_SampleChannelDualSingleEndBothSide,
    .channelNumber = 0U,
    .chainedNextCommandNumber = 2,
    .enableAutoChannelIncrement = false,
    .loopCount = 0UL,
    .hardwareAverageMode = kLPADC_HardwareAverageCount4,
    .sampleTimeMode = kLPADC_SampleTimeADCK7,
    .hardwareCompareMode = kLPADC_HardwareCompareDisabled,
    .hardwareCompareValueHigh = 0UL,
    .hardwareCompareValueLow = 0UL,
    .conversionResolutionMode = kLPADC_ConversionResolutionHigh,
    .enableWaitTrigger = false
  },
  {
    .sampleChannelMode = kLPADC_SampleChannelDualSingleEndBothSide,
    .channelNumber = 3U,
    .chainedNextCommandNumber = 3,
    .enableAutoChannelIncrement = false,
    .loopCount = 0UL,
    .hardwareAverageMode = kLPADC_HardwareAverageCount4,
    .sampleTimeMode = kLPADC_SampleTimeADCK7,
    .hardwareCompareMode = kLPADC_HardwareCompareDisabled,
    .hardwareCompareValueHigh = 0UL,
    .hardwareCompareValueLow = 0UL,
    .conversionResolutionMode = kLPADC_ConversionResolutionHigh,
    .enableWaitTrigger = false
  },
  {
    .sampleChannelMode = kLPADC_SampleChannelSingleEndSideA,
    .channelNumber = 2U,
    .chainedNextCommandNumber = 4,
    .enableAutoChannelIncrement = false,
    .loopCount = 0UL,
    .hardwareAverageMode = kLPADC_HardwareAverageCount4,
    .sampleTimeMode = kLPADC_SampleTimeADCK7,
    .hardwareCompareMode = kLPADC_HardwareCompareDisabled,
    .hardwareCompareValueHigh = 0UL,
    .hardwareCompareValueLow = 0UL,
    .conversionResolutionMode = kLPADC_ConversionResolutionHigh,
    .enableWaitTrigger = false
  },
  {
    .sampleChannelMode = kLPADC_SampleChannelSingleEndSideA,
    .channelNumber = 4U,
    .chainedNextCommandNumber = 0,
    .enableAutoChannelIncrement = false,
    .loopCount = 0UL,
    .hardwareAverageMode = kLPADC_HardwareAverageCount4,
    .sampleTimeMode = kLPADC_SampleTimeADCK7,
    .hardwareCompareMode = kLPADC_HardwareCompareDisabled,
    .hardwareCompareValueHigh = 0UL,
    .hardwareCompareValueLow = 0UL,
    .conversionResolutionMode = kLPADC_ConversionResolutionHigh,
    .enableWaitTrigger = false
  }
};
lpadc_conv_trigger_config_t ADC0_triggersConfig[1] = {
  {
    .targetCommandId = 1,
    .delayPower = 0UL,
    .channelAFIFOSelect = 0,
    .channelBFIFOSelect = 0,
    .priority = 1,
    .enableHardwareTrigger = true
  }
};

static void ADC0_init(void) {
  /* Initialize LPADC converter */
  LPADC_Init(ADC0_PERIPHERAL, &ADC0_config);
  /* Perform offset calibration */
  LPADC_DoOffsetCalibration(ADC0_PERIPHERAL);
  /* Perform auto calibration */
  LPADC_DoAutoCalibration(ADC0_PERIPHERAL);
  /* Enable DMA request on FIFO 0 watermark event */
  LPADC_EnableFIFO0WatermarkDMA(ADC0_PERIPHERAL, true);
  /* Configure conversion command 1. */
  LPADC_SetConvCommandConfig(ADC0_PERIPHERAL, 1, &ADC0_commandsConfig[0]);
  /* Configure conversion command 2. */
  LPADC_SetConvCommandConfig(ADC0_PERIPHERAL, 2, &ADC0_commandsConfig[1]);
  /* Configure conversion command 3. */
  LPADC_SetConvCommandConfig(ADC0_PERIPHERAL, 3, &ADC0_commandsConfig[2]);
  /* Configure conversion command 4. */
  LPADC_SetConvCommandConfig(ADC0_PERIPHERAL, 4, &ADC0_commandsConfig[3]);
  /* Configure trigger 5. */
  LPADC_SetConvTriggerConfig(ADC0_PERIPHERAL, 5, &ADC0_triggersConfig[0]);
}

/***********************************************************************************************************************
 * GPIO initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'GPIO'
- type: 'lpc_gpio'
- mode: 'GPIO'
- custom_name_enabled: 'false'
- type_id: 'lpc_gpio_8c9ab9b3668a514c1f4609fe43001865'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'GPIO'
- config_sets:
  - lpc_gpio: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/* Empty initialization function (commented out)
static void GPIO_init(void) {
} */

/***********************************************************************************************************************
 * RTC initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'RTC'
- type: 'lpc_rtc'
- mode: 'general'
- custom_name_enabled: 'false'
- type_id: 'lpc_rtc_607bd7331c2c81c0037fe4624be881b6'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'RTC'
- config_sets:
  - fsl_rtc:
    - rtc_config:
      - setDateTime: 'true'
      - rtc_datetime:
        - year: '2020'
        - month: '10'
        - day: '27'
        - hour: '16'
        - minute: '0'
        - second: '0'
      - setAlarmTime: 'false'
      - setWakeup: 'false'
      - alarm_wake_up_enable: 'false'
      - wake_up_enable: 'false'
      - start: 'false'
    - rtc_interrupt:
      - interrupt_vectors:
        - enable_irq: 'false'
        - interrupt:
          - IRQn: 'RTC_IRQn'
          - enable_interrrupt: 'enabled'
          - enable_priority: 'false'
          - priority: '0'
          - enable_custom_name: 'false'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
rtc_datetime_t RTC_dateTimeStruct = {
  .year = 2020U,
  .month = 10U,
  .day = 27U,
  .hour = 16U,
  .minute = 0U,
  .second = 0U
};

static void RTC_init(void) {
  /* RTC initialization */
  RTC_Init(RTC_PERIPHERAL);
  /* Stop RTC timer */
  RTC_StopTimer(RTC_PERIPHERAL);
  /* Date and time initialization */
  RTC_SetDatetime(RTC_PERIPHERAL, &RTC_dateTimeStruct);
}

/***********************************************************************************************************************
 * NVIC initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'NVIC'
- type: 'nvic'
- mode: 'general'
- custom_name_enabled: 'false'
- type_id: 'nvic_57b5eef3774cc60acaede6f5b8bddc67'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'NVIC'
- config_sets:
  - nvic:
    - interrupt_table:
      - 0: []
    - interrupts: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/* Empty initialization function (commented out)
static void NVIC_init(void) {
} */

/***********************************************************************************************************************
 * CTIMER0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'CTIMER0'
- type: 'ctimer'
- mode: 'Capture_Match'
- custom_name_enabled: 'false'
- type_id: 'ctimer_72ecb1f82fe6700da71dde4e8bc60e39'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'CTIMER0'
- config_sets:
  - fsl_ctimer:
    - ctimerConfig:
      - mode: 'kCTIMER_TimerMode'
      - clockSource: 'FunctionClock'
      - clockSourceFreq: 'BOARD_BootClockRUN'
      - timerPrescaler: '150MHz'
    - EnableTimerInInit: 'true'
    - matchChannels:
      - 0:
        - matchChannelPrefixId: 'Match_0'
        - matchChannel: 'kCTIMER_Match_3'
        - matchValueStr: '36khz'
        - enableCounterReset: 'true'
        - enableCounterStop: 'false'
        - outControl: 'kCTIMER_Output_Toggle'
        - outPinInitValue: 'low'
        - enableInterrupt: 'false'
    - interruptCallbackConfig:
      - interrupt:
        - IRQn: 'CTIMER0_IRQn'
        - enable_priority: 'false'
        - priority: '0'
      - callback: 'kCTIMER_NoCallback'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const ctimer_config_t CTIMER0_config = {
  .mode = kCTIMER_TimerMode,
  .input = kCTIMER_Capture_0,
  .prescale = 0
};
const ctimer_match_config_t CTIMER0_Match_0_config = {
  .matchValue = 4165,
  .enableCounterReset = true,
  .enableCounterStop = false,
  .outControl = kCTIMER_Output_Toggle,
  .outPinInitState = false,
  .enableInterrupt = false
};

static void CTIMER0_init(void) {
  /* CTIMER0 peripheral initialization */
  CTIMER_Init(CTIMER0_PERIPHERAL, &CTIMER0_config);
  /* Match channel 3 of CTIMER0 peripheral initialization */
  CTIMER_SetupMatch(CTIMER0_PERIPHERAL, CTIMER0_MATCH_0_CHANNEL, &CTIMER0_Match_0_config);
  /* Start the timer */
  CTIMER_StartTimer(CTIMER0_PERIPHERAL);
}

/***********************************************************************************************************************
 * USB0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'USB0'
- type: 'usb'
- mode: 'device'
- custom_name_enabled: 'false'
- type_id: 'usb_49b3e4c7d25fbcd298641994d1b911e9'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'USB0'
- config_sets:
  - deviceSetting:
    - vendor_id: '0x1FC9'
    - product_id: '0x0094'
    - manufacturer_string: 'NXP'
    - product_string: 'VCOM'
    - self_powered: 'true'
    - max_power: '100'
    - interfaces:
      - 0:
        - interface_class: 'kClassCic'
        - setting_cic:
          - interface_name: 'CIC VCOM'
          - subclass: 'kSubclassAcm'
          - protocol: 'kProtocolNone'
          - implementation: 'kImplementationCicVcom'
          - endpoints_settings:
            - 0:
              - setting_name: 'Default'
              - endpoints:
                - 0:
                  - direction: 'kIn'
                  - transfer_type: 'kInterrupt'
                  - synchronization: 'kNoSynchronization'
                  - usage: 'kData'
                  - max_packet_size_fs: 'k16'
                  - polling_interval_fs: '8'
                  - bRefresh: '0'
                  - bSynchAddress: 'NoSynchronization'
          - data_interface_count: '1'
          - quick_selection: 'QS_INTERFACE_CIC_VCOM'
      - 1:
        - interface_class: 'kClassDic'
        - setting_dic:
          - interface_name: 'DIC VCOM'
          - subclass: 'kSubclassNone'
          - protocol: 'kProtocolNone'
          - implementation: 'kImplementationDicVcom'
          - endpoints_settings:
            - 0:
              - setting_name: 'Default'
              - endpoints:
                - 0:
                  - direction: 'kIn'
                  - transfer_type: 'kBulk'
                  - synchronization: 'kNoSynchronization'
                  - usage: 'kData'
                  - max_packet_size_fs: 'k64'
                  - polling_interval_fs: '0'
                  - bRefresh: '0'
                  - bSynchAddress: 'NoSynchronization'
                - 1:
                  - direction: 'kOut'
                  - transfer_type: 'kBulk'
                  - synchronization: 'kNoSynchronization'
                  - usage: 'kData'
                  - max_packet_size_fs: 'k64'
                  - polling_interval_fs: '0'
                  - bRefresh: '0'
                  - bSynchAddress: 'NoSynchronization'
          - quick_selection: 'QS_INTERFACE_DIC_VCOM'
      - 2:
        - interface_class: 'kClassCic'
        - setting_cic:
          - interface_name: 'CIC VCOM'
          - subclass: 'kSubclassAcm'
          - protocol: 'kProtocolNone'
          - implementation: 'kImplementationCicVcom'
          - endpoints_settings:
            - 0:
              - setting_name: 'Default'
              - endpoints:
                - 0:
                  - direction: 'kIn'
                  - transfer_type: 'kInterrupt'
                  - synchronization: 'kNoSynchronization'
                  - usage: 'kData'
                  - max_packet_size_fs: 'k16'
                  - polling_interval_fs: '8'
                  - bRefresh: '0'
                  - bSynchAddress: 'NoSynchronization'
          - data_interface_count: '1'
          - quick_selection: 'QS_INTERFACE_CIC_VCOM'
      - 3:
        - interface_class: 'kClassDic'
        - setting_dic:
          - interface_name: 'DIC VCOM'
          - subclass: 'kSubclassNone'
          - protocol: 'kProtocolNone'
          - implementation: 'kImplementationDicVcom'
          - endpoints_settings:
            - 0:
              - setting_name: 'Default'
              - endpoints:
                - 0:
                  - direction: 'kIn'
                  - transfer_type: 'kBulk'
                  - synchronization: 'kNoSynchronization'
                  - usage: 'kData'
                  - max_packet_size_fs: 'k64'
                  - polling_interval_fs: '0'
                  - bRefresh: '0'
                  - bSynchAddress: 'NoSynchronization'
                - 1:
                  - direction: 'kOut'
                  - transfer_type: 'kBulk'
                  - synchronization: 'kNoSynchronization'
                  - usage: 'kData'
                  - max_packet_size_fs: 'k64'
                  - polling_interval_fs: '0'
                  - bRefresh: '0'
                  - bSynchAddress: 'NoSynchronization'
          - quick_selection: 'QS_INTERFACE_DIC_VCOM'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

static void USB0_init(void) {
  USB_DeviceApplicationInit();
}

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/
void BOARD_InitPeripherals(void)
{
  /* Global initialization */
  DMA_Init(DMA0_DMA_BASEADDR);

  /* Initialize components */
  DMA0_init();
  ADC0_init();
  RTC_init();
  CTIMER0_init();
  USB0_init();
}

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void)
{
  BOARD_InitPeripherals();
}
