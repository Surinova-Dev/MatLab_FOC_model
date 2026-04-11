/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Vsense_model.c
 *
 * Code generated for Simulink model 'Vsense_model'.
 *
 * Model version                  : 4.0
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Sat Apr 11 11:59:07 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Vsense_model.h"
#include "Vsense_model_types.h"
#include "rtwtypes.h"
#include "stm_adc_ll.h"
#include <stddef.h>
#include "Vsense_model_private.h"

/* Block signals (default storage) */
B_Vsense_model_T Vsense_model_B;

/* Block states (default storage) */
DW_Vsense_model_T Vsense_model_DW;

/* Real-time model */
static RT_MODEL_Vsense_model_T Vsense_model_M_;
RT_MODEL_Vsense_model_T *const Vsense_model_M = &Vsense_model_M_;

/* Forward declaration for local functions */
static void Vsense_model_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);
static void Vsense_model_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S3>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S3>/Analog to Digital Converter' */
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

/* Model step function */
void Vsense_model_step(void)
{
  uint16_T data;

  /* MATLABSystem: '<S3>/Analog to Digital Converter' */
  if (Vsense_model_DW.obj.TunablePropsChanged) {
    Vsense_model_DW.obj.TunablePropsChanged = false;
  }

  regularReadADCNormal(Vsense_model_DW.obj.ADCHandle, ADC_TRIGGER_AND_READ,
                       &data);

  /* Gain: '<Root>/Multiply1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  MATLABSystem: '<S3>/Analog to Digital Converter'
   */
  Vsense_model_B.Multiply1 = Vsense_model_P.Multiply1_Gain * (real_T)data;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Vsense_model_M->Timing.taskTime0 =
    ((time_T)(++Vsense_model_M->Timing.clockTick0)) *
    Vsense_model_M->Timing.stepSize0;
}

/* Model initialize function */
void Vsense_model_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Vsense_model_M, -1);
  Vsense_model_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Vsense_model_M->Sizes.checksums[0] = (1693096245U);
  Vsense_model_M->Sizes.checksums[1] = (485328149U);
  Vsense_model_M->Sizes.checksums[2] = (1344285047U);
  Vsense_model_M->Sizes.checksums[3] = (2096277349U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    Vsense_model_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Vsense_model_M->extModeInfo,
      &Vsense_model_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Vsense_model_M->extModeInfo,
                        Vsense_model_M->Sizes.checksums);
    rteiSetTPtr(Vsense_model_M->extModeInfo, rtmGetTPtr(Vsense_model_M));
  }

  /* Start for MATLABSystem: '<S3>/Analog to Digital Converter' */
  Vsense_model_DW.obj.isInitialized = 0;
  Vsense_model_DW.obj.matlabCodegenIsDeleted = false;
  Vsense_model_SystemCore_setup(&Vsense_model_DW.obj);
}

/* Model terminate function */
void Vsense_model_terminate(void)
{
  /* Terminate for MATLABSystem: '<S3>/Analog to Digital Converter' */
  if (!Vsense_model_DW.obj.matlabCodegenIsDeleted) {
    Vsense_model_DW.obj.matlabCodegenIsDeleted = true;
    if ((Vsense_model_DW.obj.isInitialized == 1) &&
        Vsense_model_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(Vsense_model_DW.obj.ADCHandle, ADC_NORMAL_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Analog to Digital Converter' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
