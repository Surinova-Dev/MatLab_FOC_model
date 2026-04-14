/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.c
 *
 * Code generated for Simulink model 'PMSM_to_BLDC_mod1'.
 *
 * Model version                  : 4.415
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Tue Apr 14 18:10:32 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PMSM_to_BLDC_mod1.h"
#include "rtwtypes.h"
#include "PMSM_to_BLDC_mod1_types.h"
#include "PMSM_to_BLDC_mod1_private.h"
#include "mw_stm32_spi_ll.h"
#include "stm_adc_ll.h"
#include <stddef.h>

/* Named constants for MATLAB Function: '<S14>/bit_shift' */
#define PMSM_to_BLDC_mod1_CALL_EVENT   (-1)

/* Named constants for MATLAB Function: '<S15>/bit_shift' */
#define PMSM_to_BLDC_mod1_CALL_EVENT_m (-1)

/* Block signals (default storage) */
B_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_B;

/* Block states (default storage) */
DW_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_DW;

/* Real-time model */
static RT_MODEL_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_M_;
RT_MODEL_PMSM_to_BLDC_mod1_T *const PMSM_to_BLDC_mod1_M = &PMSM_to_BLDC_mod1_M_;

/* Forward declaration for local functions */
static void PMSM_to_B_SPIDrvBlock_setupImpl(stm32cube_blocks_SPIControlle_T *obj);

/* Forward declaration for local functions */
static void PMSM_to_BLDC_m_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);
static void PMSM_to_BLDC_SystemCore_setup_o(stm32cube_blocks_AnalogInput__T *obj);
static void PMSM_to_BLD_SystemCore_setup_ox(stm32cube_blocks_AnalogInput__T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void PMSM_to_BLDC_mod1_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(PMSM_to_BLDC_mod1_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1])++;
  if ((PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [1.0s, 0.0s] */
    PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * System initialize for atomic system:
 *    '<S12>/Bit Shift'
 *    '<S13>/Bit Shift'
 */
void PMSM_to_BLDC__BitShift_Init(DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* SystemInitialize for MATLAB Function: '<S14>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
}

/*
 * Output and update for atomic system:
 *    '<S12>/Bit Shift'
 *    '<S13>/Bit Shift'
 */
void PMSM_to_BLDC_mod1_BitShift(uint16_T rtu_u, uint16_T *rty_y,
  DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* MATLAB Function: '<S14>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
  *rty_y = (uint16_T)(rtu_u << 15);
}

/*
 * System initialize for atomic system:
 *    '<S12>/Bit Shift1'
 *    '<S13>/Bit Shift1'
 */
void PMSM_to_BLDC_BitShift1_Init(DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* SystemInitialize for MATLAB Function: '<S15>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_m;
}

/*
 * Output and update for atomic system:
 *    '<S12>/Bit Shift1'
 *    '<S13>/Bit Shift1'
 */
void PMSM_to_BLDC_mod1_BitShift1(uint16_T rtu_u, uint16_T *rty_y,
  DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* MATLAB Function: '<S15>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_m;
  *rty_y = (uint16_T)(rtu_u << 11);
}

static void PMSM_to_B_SPIDrvBlock_setupImpl(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;

  /* Start for MATLABSystem: '<S12>/SPI Controller Transfer' */
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S12>/SPI Controller Transfer' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S12>/SPI Controller Transfer' */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 1.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_2);
}

/* System initialize for atomic system: */
void SPIControllerTransfer_Init(DW_SPIControllerTransfer_PMSM_T *localDW)
{
  /* Start for MATLABSystem: '<S12>/SPI Controller Transfer' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  PMSM_to_B_SPIDrvBlock_setupImpl(&localDW->obj);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void PMSM__SPIControllerTransfer(uint16_T rtu_0, B_SPIControllerTransfer_PMSM__T
  *localB, DW_SPIControllerTransfer_PMSM_T *localDW)
{
  uint16_T status;

  /* MATLABSystem: '<S12>/SPI Controller Transfer' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_2);
  if (status == 0) {
    GPIO_TypeDef * portNameLoc;
    portNameLoc = GPIOC;
    LL_GPIO_ResetOutputPin(portNameLoc, 16384U);
    MW_SPI_ControllerWriteRead_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0,
      &localB->SPIControllerTransfer, 1, 1U, 0, 1U);
    LL_GPIO_SetOutputPin(portNameLoc, 16384U);
  }

  /* End of MATLABSystem: '<S12>/SPI Controller Transfer' */
}

/* Termination for atomic system: */
void SPIControllerTransfer_Term(DW_SPIControllerTransfer_PMSM_T *localDW)
{
  /* Terminate for MATLABSystem: '<S12>/SPI Controller Transfer' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S12>/SPI Controller Transfer' */
}

static void PMSM_to_BLDC_m_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S7>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S7>/Analog to Digital Converter' */
  adcStructLoc.InjectedNoOfConversion = 0U;
  adcStructLoc.peripheralPtr = ADC2;
  adcStructLoc.dmaPeripheralPtr = NULL;
  adcStructLoc.dmastream = 0;
  adcStructLoc.DataTransferMode = ADC_DR_TRANSFER;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_LIMITED;
  adcStructLoc.InternalBufferSize = 1U;
  adcStructLoc.RegularNoOfConversion = 1U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_NORMAL_MODE, 1,
    ADC_TRIGGER_AND_READ, LL_ADC_REG_SEQ_SCAN_DISABLE);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 1);
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

static void PMSM_to_BLDC_SystemCore_setup_o(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S9>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S9>/Analog to Digital Converter' */
  adcStructLoc.InjectedNoOfConversion = 0U;
  adcStructLoc.peripheralPtr = ADC3;
  adcStructLoc.dmaPeripheralPtr = NULL;
  adcStructLoc.dmastream = 0;
  adcStructLoc.DataTransferMode = ADC_DR_TRANSFER;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_LIMITED;
  adcStructLoc.InternalBufferSize = 1U;
  adcStructLoc.RegularNoOfConversion = 1U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_NORMAL_MODE, 1,
    ADC_TRIGGER_AND_READ, LL_ADC_REG_SEQ_SCAN_DISABLE);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 1);
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

static void PMSM_to_BLD_SystemCore_setup_ox(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S24>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S24>/Analog to Digital Converter' */
  adcStructLoc.InjectedNoOfConversion = 0U;
  adcStructLoc.peripheralPtr = ADC1;
  adcStructLoc.dmaPeripheralPtr = NULL;
  adcStructLoc.dmastream = 0;
  adcStructLoc.DataTransferMode = ADC_DR_TRANSFER;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_LIMITED;
  adcStructLoc.InternalBufferSize = 1U;
  adcStructLoc.RegularNoOfConversion = 1U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_NORMAL_MODE, 1,
    ADC_TRIGGER_AND_READ, LL_ADC_REG_SEQ_SCAN_DISABLE);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 1);
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

/* Model step function for TID0 */
void PMSM_to_BLDC_mod1_step0(void)     /* Sample time: [0.1s, 0.0s] */
{
  uint16_T data;

  {                                    /* Sample time: [0.1s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* MATLABSystem: '<S7>/Analog to Digital Converter' */
  if (PMSM_to_BLDC_mod1_DW.obj_d.TunablePropsChanged) {
    PMSM_to_BLDC_mod1_DW.obj_d.TunablePropsChanged = false;
  }

  regularReadADCNormal(PMSM_to_BLDC_mod1_DW.obj_d.ADCHandle,
                       ADC_TRIGGER_AND_READ, &data);

  /* Gain: '<S1>/Gain' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  MATLABSystem: '<S7>/Analog to Digital Converter'
   */
  PMSM_to_BLDC_mod1_B.Gain = 0.02442002442002442 * (real_T)data;

  /* MATLABSystem: '<S9>/Analog to Digital Converter' */
  if (PMSM_to_BLDC_mod1_DW.obj_o.TunablePropsChanged) {
    PMSM_to_BLDC_mod1_DW.obj_o.TunablePropsChanged = false;
  }

  regularReadADCNormal(PMSM_to_BLDC_mod1_DW.obj_o.ADCHandle,
                       ADC_TRIGGER_AND_READ, &data);

  /* Gain: '<S1>/Gain1' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion1'
   *  MATLABSystem: '<S9>/Analog to Digital Converter'
   */
  PMSM_to_BLDC_mod1_B.Gain1 = 0.02442002442002442 * (real_T)data;

  /* MATLABSystem: '<S24>/Analog to Digital Converter' */
  if (PMSM_to_BLDC_mod1_DW.obj.TunablePropsChanged) {
    PMSM_to_BLDC_mod1_DW.obj.TunablePropsChanged = false;
  }

  /* MATLABSystem: '<S24>/Analog to Digital Converter' */
  regularReadADCNormal(PMSM_to_BLDC_mod1_DW.obj.ADCHandle, ADC_TRIGGER_AND_READ,
                       &PMSM_to_BLDC_mod1_B.AnalogtoDigitalConverter);

  /* Gain: '<S3>/Gain' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  PMSM_to_BLDC_mod1_B.Gain_g = 0.015625 * (real_T)
    PMSM_to_BLDC_mod1_B.AnalogtoDigitalConverter;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  PMSM_to_BLDC_mod1_M->Timing.taskTime0 =
    ((time_T)(++PMSM_to_BLDC_mod1_M->Timing.clockTick0)) *
    PMSM_to_BLDC_mod1_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void PMSM_to_BLDC_mod1_step1(void)     /* Sample time: [1.0s, 0.0s] */
{
  uint16_T y_l;
  uint16_T y_p;

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.SPI_read_SubsysRanBC);

  /* Sum: '<S2>/Add' incorporates:
   *  Constant: '<S2>/Constant'
   *  Delay: '<S2>/Delay'
   */
  PMSM_to_BLDC_mod1_DW.Delay_DSTATE++;

  /* Outputs for Enabled SubSystem: '<S2>/SPI_read' incorporates:
   *  EnablePort: '<S11>/Enable'
   */
  /* RelationalOperator: '<S10>/Compare' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S12>/Constant'
   *  Constant: '<S12>/Constant1'
   *  Constant: '<S13>/Constant'
   *  Constant: '<S13>/Constant1'
   *  Delay: '<S2>/Delay'
   */
  if (PMSM_to_BLDC_mod1_DW.Delay_DSTATE >= 5.0) {
    /* Outputs for Atomic SubSystem: '<S12>/Bit Shift' */
    PMSM_to_BLDC_mod1_BitShift(1, &y_l, &PMSM_to_BLDC_mod1_DW.BitShift);

    /* End of Outputs for SubSystem: '<S12>/Bit Shift' */

    /* Outputs for Atomic SubSystem: '<S12>/Bit Shift1' */
    PMSM_to_BLDC_mod1_BitShift1(2, &y_p, &PMSM_to_BLDC_mod1_DW.BitShift1);

    /* End of Outputs for SubSystem: '<S12>/Bit Shift1' */

    /* S-Function (sfix_bitop): '<S12>/Bitwise OR' incorporates:
     *  Constant: '<S12>/Constant'
     *  Constant: '<S12>/Constant1'
     */
    PMSM_to_BLDC_mod1_B.BitwiseOR = (uint16_T)(y_l | y_p |
      PMSM_to_BLDC_mod1_ConstB.BitwiseAND);
    PMSM__SPIControllerTransfer(PMSM_to_BLDC_mod1_B.BitwiseOR,
      &PMSM_to_BLDC_mod1_B.SPIControllerTransfer,
      &PMSM_to_BLDC_mod1_DW.SPIControllerTransfer);

    /* DataTypeConversion: '<S12>/Data Type Conversion' incorporates:
     *  Constant: '<S12>/Constant3'
     *  S-Function (sfix_bitop): '<S12>/Bitwise AND1'
     */
    PMSM_to_BLDC_mod1_B.DataTypeConversion = (uint16_T)
      (PMSM_to_BLDC_mod1_B.SPIControllerTransfer.SPIControllerTransfer & 32767);

    /* Outputs for Atomic SubSystem: '<S13>/Bit Shift' */
    PMSM_to_BLDC_mod1_BitShift(1, &y_l, &PMSM_to_BLDC_mod1_DW.BitShift_j);

    /* End of Outputs for SubSystem: '<S13>/Bit Shift' */

    /* Outputs for Atomic SubSystem: '<S13>/Bit Shift1' */
    PMSM_to_BLDC_mod1_BitShift1(3, &y_p, &PMSM_to_BLDC_mod1_DW.BitShift1_i);

    /* End of Outputs for SubSystem: '<S13>/Bit Shift1' */

    /* S-Function (sfix_bitop): '<S13>/Bitwise OR' incorporates:
     *  Constant: '<S13>/Constant'
     *  Constant: '<S13>/Constant1'
     */
    PMSM_to_BLDC_mod1_B.BitwiseOR_e = (uint16_T)(y_l | y_p |
      PMSM_to_BLDC_mod1_ConstB.BitwiseAND_k);
    PMSM__SPIControllerTransfer(PMSM_to_BLDC_mod1_B.BitwiseOR_e,
      &PMSM_to_BLDC_mod1_B.SPIControllerTransfer_p,
      &PMSM_to_BLDC_mod1_DW.SPIControllerTransfer_p);

    /* S-Function (sfix_bitop): '<S13>/Bitwise AND1' incorporates:
     *  Constant: '<S13>/Constant3'
     */
    PMSM_to_BLDC_mod1_B.BitwiseAND1 = (uint16_T)
      (PMSM_to_BLDC_mod1_B.SPIControllerTransfer_p.SPIControllerTransfer & 32767);

    /* SignalConversion generated from: '<S11>/Mux' */
    PMSM_to_BLDC_mod1_B.TmpSignalConversionAtTAQSigLogg[0] =
      PMSM_to_BLDC_mod1_B.DataTypeConversion;
    PMSM_to_BLDC_mod1_B.TmpSignalConversionAtTAQSigLogg[1] =
      PMSM_to_BLDC_mod1_B.BitwiseAND1;
    srUpdateBC(PMSM_to_BLDC_mod1_DW.SPI_read_SubsysRanBC);
  }

  /* End of RelationalOperator: '<S10>/Compare' */
  /* End of Outputs for SubSystem: '<S2>/SPI_read' */

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 1.0, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  PMSM_to_BLDC_mod1_M->Timing.clockTick1++;
}

/* Model initialize function */
void PMSM_to_BLDC_mod1_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(PMSM_to_BLDC_mod1_M, -1);
  PMSM_to_BLDC_mod1_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  PMSM_to_BLDC_mod1_M->Sizes.checksums[0] = (700090253U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[1] = (4146239713U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[2] = (1505113797U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[3] = (1647220208U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[15];
    PMSM_to_BLDC_mod1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.SPI_read_SubsysRanBC;
    systemRan[4] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.SPI_read_SubsysRanBC;
    systemRan[5] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.SPI_read_SubsysRanBC;
    systemRan[6] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.SPI_read_SubsysRanBC;
    systemRan[7] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.SPI_read_SubsysRanBC;
    systemRan[8] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.SPI_read_SubsysRanBC;
    systemRan[9] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.SPI_read_SubsysRanBC;
    systemRan[10] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.SPI_read_SubsysRanBC;
    systemRan[11] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.SPI_read_SubsysRanBC;
    systemRan[12] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.SPI_read_SubsysRanBC;
    systemRan[13] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.SPI_read_SubsysRanBC;
    systemRan[14] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PMSM_to_BLDC_mod1_M->extModeInfo,
      &PMSM_to_BLDC_mod1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PMSM_to_BLDC_mod1_M->extModeInfo,
                        PMSM_to_BLDC_mod1_M->Sizes.checksums);
    rteiSetTPtr(PMSM_to_BLDC_mod1_M->extModeInfo, rtmGetTPtr(PMSM_to_BLDC_mod1_M));
  }

  /* SystemInitialize for Atomic SubSystem: '<S12>/Bit Shift' */
  PMSM_to_BLDC__BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift);

  /* End of SystemInitialize for SubSystem: '<S12>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S12>/Bit Shift1' */
  PMSM_to_BLDC_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1);

  /* End of SystemInitialize for SubSystem: '<S12>/Bit Shift1' */

  /* SystemInitialize for Atomic SubSystem: '<S13>/Bit Shift' */
  PMSM_to_BLDC__BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_j);

  /* End of SystemInitialize for SubSystem: '<S13>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S13>/Bit Shift1' */
  PMSM_to_BLDC_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_i);

  /* End of SystemInitialize for SubSystem: '<S13>/Bit Shift1' */
  SPIControllerTransfer_Init(&PMSM_to_BLDC_mod1_DW.SPIControllerTransfer);
  SPIControllerTransfer_Init(&PMSM_to_BLDC_mod1_DW.SPIControllerTransfer_p);

  /* End of SystemInitialize for SubSystem: '<S2>/SPI_read' */

  /* Start for MATLABSystem: '<S7>/Analog to Digital Converter' */
  PMSM_to_BLDC_mod1_DW.obj_d.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj_d.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_m_SystemCore_setup(&PMSM_to_BLDC_mod1_DW.obj_d);

  /* Start for MATLABSystem: '<S9>/Analog to Digital Converter' */
  PMSM_to_BLDC_mod1_DW.obj_o.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_SystemCore_setup_o(&PMSM_to_BLDC_mod1_DW.obj_o);

  /* Start for MATLABSystem: '<S24>/Analog to Digital Converter' */
  PMSM_to_BLDC_mod1_DW.obj.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = false;
  PMSM_to_BLD_SystemCore_setup_ox(&PMSM_to_BLDC_mod1_DW.obj);
}

/* Model terminate function */
void PMSM_to_BLDC_mod1_terminate(void)
{
  /* Terminate for MATLABSystem: '<S7>/Analog to Digital Converter' */
  if (!PMSM_to_BLDC_mod1_DW.obj_d.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_d.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_d.isSetupComplete) {
      ADC_Handle_Deinit(PMSM_to_BLDC_mod1_DW.obj_d.ADCHandle, ADC_NORMAL_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/Analog to Digital Converter' */
  /* Terminate for MATLABSystem: '<S9>/Analog to Digital Converter' */
  if (!PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_o.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_o.isSetupComplete) {
      ADC_Handle_Deinit(PMSM_to_BLDC_mod1_DW.obj_o.ADCHandle, ADC_NORMAL_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S9>/Analog to Digital Converter' */
  /* Terminate for MATLABSystem: '<S24>/Analog to Digital Converter' */
  if (!PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(PMSM_to_BLDC_mod1_DW.obj.ADCHandle, ADC_NORMAL_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S24>/Analog to Digital Converter' */
  /* Terminate for Enabled SubSystem: '<S2>/SPI_read' */
  SPIControllerTransfer_Term(&PMSM_to_BLDC_mod1_DW.SPIControllerTransfer);
  SPIControllerTransfer_Term(&PMSM_to_BLDC_mod1_DW.SPIControllerTransfer_p);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
