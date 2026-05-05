/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: F4_uart.c
 *
 * Code generated for Simulink model 'F4_uart'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Tue May  5 17:40:40 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "F4_uart.h"
#include "F4_uart_types.h"
#include "rtwtypes.h"
#include "F4_uart_private.h"

/* Block states (default storage) */
DW_F4_uart_T F4_uart_DW;

/* Real-time model */
static RT_MODEL_F4_uart_T F4_uart_M_;
RT_MODEL_F4_uart_T *const F4_uart_M = &F4_uart_M_;

/* Forward declaration for local functions */
static void F4_uart_UARTWrite_setupImpl(stm32cube_blocks_UARTWrite_F4_T *obj);
static void F4_uart_UARTWrite_setupImpl(stm32cube_blocks_UARTWrite_F4_T *obj)
{
  UART_Type_T b;
  b.buffer.txBufferPtr = (void*)(&obj->UARTInternalBuffer[0]);

  /* Start for MATLABSystem: '<Root>/UART//USART Write' */
  b.enableRxOrTx = 2U;
  b.mode = UART_TX_INTERRUPT_MODE;
  b.peripheralPtr = UART4;

  /* Start for MATLABSystem: '<Root>/UART//USART Write' */
  b.txdmaPeripheralPtr = NULL;
  b.txdmastream = 0;
  b.buffer.txBufferSize = 128U;
  obj->UARTHandle = MW_UART_Initialize(&b);
}

/* Model step function */
void F4_uart_step(void)
{
  uint32_T sentLength;
  uint8_T uartWriteData;

  /* MATLABSystem: '<Root>/UART//USART Write' */
  uartWriteData = F4_uart_ConstB.DataTypeConversion;
  MW_UART_TransmitUsingInterrupt(F4_uart_DW.obj.UARTHandle, &uartWriteData, 1U,
    100U, &sentLength);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  F4_uart_M->Timing.taskTime0 =
    ((time_T)(++F4_uart_M->Timing.clockTick0)) * F4_uart_M->Timing.stepSize0;
}

/* Model initialize function */
void F4_uart_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(F4_uart_M, 10.0);
  F4_uart_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  F4_uart_M->Sizes.checksums[0] = (2004498170U);
  F4_uart_M->Sizes.checksums[1] = (2035571155U);
  F4_uart_M->Sizes.checksums[2] = (4116151439U);
  F4_uart_M->Sizes.checksums[3] = (4012289440U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    F4_uart_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(F4_uart_M->extModeInfo,
      &F4_uart_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(F4_uart_M->extModeInfo, F4_uart_M->Sizes.checksums);
    rteiSetTPtr(F4_uart_M->extModeInfo, rtmGetTPtr(F4_uart_M));
  }

  /* Start for MATLABSystem: '<Root>/UART//USART Write' */
  F4_uart_DW.obj.matlabCodegenIsDeleted = false;
  F4_uart_DW.obj.isSetupComplete = false;
  F4_uart_DW.obj.isInitialized = 1;
  F4_uart_UARTWrite_setupImpl(&F4_uart_DW.obj);
  F4_uart_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void F4_uart_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/UART//USART Write' */
  if (!F4_uart_DW.obj.matlabCodegenIsDeleted) {
    F4_uart_DW.obj.matlabCodegenIsDeleted = true;
    if ((F4_uart_DW.obj.isInitialized == 1) && F4_uart_DW.obj.isSetupComplete) {
      MW_UART_DeInit(F4_uart_DW.obj.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/UART//USART Write' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
