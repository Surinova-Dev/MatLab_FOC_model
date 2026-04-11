/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.c
 *
 * Code generated for Simulink model 'PMSM_to_BLDC_mod1'.
 *
 * Model version                  : 4.375
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Sat Apr 11 19:18:24 2026
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
#include <math.h>
#include "rt_nonfinite.h"
#include "mw_stm32_spi_ll.h"

/* Named constants for MATLAB Function: '<S4>/bit_shift' */
#define PMSM_to_BLDC_mod1_CALL_EVENT   (-1)

/* Named constants for MATLAB Function: '<S5>/bit_shift' */
#define PMSM_to_BLDC_mod1_CALL_EVENT_h (-1)

/* Block signals (default storage) */
B_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_B;

/* Block states (default storage) */
DW_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_DW;

/* Real-time model */
static RT_MODEL_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_M_;
RT_MODEL_PMSM_to_BLDC_mod1_T *const PMSM_to_BLDC_mod1_M = &PMSM_to_BLDC_mod1_M_;

/* Forward declaration for local functions */
static void PMSM_to_B_SPIDrvBlock_setupImpl(stm32cube_blocks_SPIControlle_T *obj);

/*
 * System initialize for atomic system:
 *    '<S2>/Bit Shift'
 *    '<S3>/Bit Shift1'
 */
void PMSM_to_BLDC_mod1_BitShift_Init(DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* SystemInitialize for MATLAB Function: '<S4>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
}

/*
 * Output and update for atomic system:
 *    '<S2>/Bit Shift'
 *    '<S3>/Bit Shift1'
 */
void PMSM_to_BLDC_mod1_BitShift(uint16_T rtu_u, uint16_T *rty_y,
  DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* MATLAB Function: '<S4>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
  *rty_y = (uint16_T)(rtu_u << 15);
}

/*
 * System initialize for atomic system:
 *    '<S2>/Bit Shift4'
 *    '<S3>/Bit Shift2'
 */
void PMSM_to_BLDC_mod_BitShift4_Init(DW_BitShift4_PMSM_to_BLDC_mod_T *localDW)
{
  /* SystemInitialize for MATLAB Function: '<S5>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_h;
}

/*
 * Output and update for atomic system:
 *    '<S2>/Bit Shift4'
 *    '<S3>/Bit Shift2'
 */
void PMSM_to_BLDC_mod1_BitShift4(uint16_T rtu_u, uint16_T *rty_y,
  DW_BitShift4_PMSM_to_BLDC_mod_T *localDW)
{
  /* MATLAB Function: '<S5>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_h;
  *rty_y = (uint16_T)(rtu_u << 11);
}

static void PMSM_to_B_SPIDrvBlock_setupImpl(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;

  /* Start for MATLABSystem: '<S1>/SPI Transmit' */
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S1>/SPI Transmit' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S1>/SPI Transmit' */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 1.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_2);
}

/* Model step function */
void PMSM_to_BLDC_mod1_step(void)
{
  real_T tmp;
  uint16_T y_e;
  uint16_T y_l;

  /* Outputs for Atomic SubSystem: '<S2>/Bit Shift' */
  /* Constant: '<S2>/Constant5' */
  PMSM_to_BLDC_mod1_BitShift(0, &y_l, &PMSM_to_BLDC_mod1_DW.BitShift);

  /* End of Outputs for SubSystem: '<S2>/Bit Shift' */

  /* Outputs for Atomic SubSystem: '<S2>/Bit Shift4' */
  /* Constant: '<S2>/Constant6' */
  PMSM_to_BLDC_mod1_BitShift4(2, &y_e, &PMSM_to_BLDC_mod1_DW.BitShift4);

  /* End of Outputs for SubSystem: '<S2>/Bit Shift4' */

  /* S-Function (sfix_bitop): '<S2>/Bitwise AND' */
  PMSM_to_BLDC_mod1_B.BitwiseAND = (uint16_T)(y_l | y_e |
    PMSM_to_BLDC_mod1_ConstB.BitwiseOR);

  /* Outputs for Atomic SubSystem: '<S3>/Bit Shift1' */
  /* Constant: '<S3>/Constant2' */
  PMSM_to_BLDC_mod1_BitShift(0, &y_l, &PMSM_to_BLDC_mod1_DW.BitShift1);

  /* End of Outputs for SubSystem: '<S3>/Bit Shift1' */

  /* Outputs for Atomic SubSystem: '<S3>/Bit Shift2' */
  /* Constant: '<S3>/Constant3' */
  PMSM_to_BLDC_mod1_BitShift4(3, &y_e, &PMSM_to_BLDC_mod1_DW.BitShift2);

  /* End of Outputs for SubSystem: '<S3>/Bit Shift2' */

  /* S-Function (sfix_bitop): '<S3>/Bitwise AND1' */
  PMSM_to_BLDC_mod1_B.BitwiseAND1 = (uint16_T)(y_l | y_e |
    PMSM_to_BLDC_mod1_ConstB.BitwiseOR1);

  /* MultiPortSwitch: '<S1>/Multiport Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  Delay: '<S1>/Delay'
   *  Sum: '<S1>/Add'
   */
  switch ((int32_T)(PMSM_to_BLDC_mod1_DW.Delay_DSTATE + 1.0)) {
   case 1:
    /* MultiPortSwitch: '<S1>/Multiport Switch' */
    PMSM_to_BLDC_mod1_B.MultiportSwitch = PMSM_to_BLDC_mod1_B.BitwiseAND;
    break;

   case 2:
    /* MultiPortSwitch: '<S1>/Multiport Switch' */
    PMSM_to_BLDC_mod1_B.MultiportSwitch = PMSM_to_BLDC_mod1_B.BitwiseAND1;
    break;

   case 3:
    /* MultiPortSwitch: '<S1>/Multiport Switch' incorporates:
     *  Constant: '<S1>/Constant1'
     */
    PMSM_to_BLDC_mod1_B.MultiportSwitch = 0.0;
    break;

   default:
    /* MultiPortSwitch: '<S1>/Multiport Switch' incorporates:
     *  Constant: '<S1>/Constant1'
     */
    PMSM_to_BLDC_mod1_B.MultiportSwitch = 0.0;
    break;
  }

  /* End of MultiPortSwitch: '<S1>/Multiport Switch' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  tmp = floor(PMSM_to_BLDC_mod1_B.MultiportSwitch);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  y_l = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-tmp :
                   (int32_T)(uint16_T)tmp);

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* MATLABSystem: '<S1>/SPI Transmit' */
  PMSM_to_BLDC_mod1_B.SPITransmit = MW_STM32_SPI_SetFormat
    (PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_2);
  if (PMSM_to_BLDC_mod1_B.SPITransmit == 0) {
    LL_GPIO_ResetOutputPin(GPIOC, 16384U);

    /* MATLABSystem: '<S1>/SPI Transmit' */
    PMSM_to_BLDC_mod1_B.SPITransmit = MW_SPI_Write_Databits
      (PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, &y_l, 1U, 1, 0, 1U);
  }

  /* End of MATLABSystem: '<S1>/SPI Transmit' */
  /* Update for Delay: '<S1>/Delay' incorporates:
   *  Constant: '<S1>/Constant2'
   */
  PMSM_to_BLDC_mod1_DW.Delay_DSTATE = 1.0;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  PMSM_to_BLDC_mod1_M->Timing.taskTime0 =
    ((time_T)(++PMSM_to_BLDC_mod1_M->Timing.clockTick0)) *
    PMSM_to_BLDC_mod1_M->Timing.stepSize0;
}

/* Model initialize function */
void PMSM_to_BLDC_mod1_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(PMSM_to_BLDC_mod1_M, -1);
  PMSM_to_BLDC_mod1_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  PMSM_to_BLDC_mod1_M->Sizes.checksums[0] = (2773969534U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[1] = (674976530U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[2] = (2658295651U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[3] = (2620870612U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    PMSM_to_BLDC_mod1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PMSM_to_BLDC_mod1_M->extModeInfo,
      &PMSM_to_BLDC_mod1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PMSM_to_BLDC_mod1_M->extModeInfo,
                        PMSM_to_BLDC_mod1_M->Sizes.checksums);
    rteiSetTPtr(PMSM_to_BLDC_mod1_M->extModeInfo, rtmGetTPtr(PMSM_to_BLDC_mod1_M));
  }

  /* SystemInitialize for Atomic SubSystem: '<S2>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift);

  /* End of SystemInitialize for SubSystem: '<S2>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S2>/Bit Shift4' */
  PMSM_to_BLDC_mod_BitShift4_Init(&PMSM_to_BLDC_mod1_DW.BitShift4);

  /* End of SystemInitialize for SubSystem: '<S2>/Bit Shift4' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/Bit Shift1' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift1);

  /* End of SystemInitialize for SubSystem: '<S3>/Bit Shift1' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/Bit Shift2' */
  PMSM_to_BLDC_mod_BitShift4_Init(&PMSM_to_BLDC_mod1_DW.BitShift2);

  /* End of SystemInitialize for SubSystem: '<S3>/Bit Shift2' */

  /* Start for MATLABSystem: '<S1>/SPI Transmit' */
  PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj.isSetupComplete = false;
  PMSM_to_BLDC_mod1_DW.obj.isInitialized = 1;
  PMSM_to_B_SPIDrvBlock_setupImpl(&PMSM_to_BLDC_mod1_DW.obj);
  PMSM_to_BLDC_mod1_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void PMSM_to_BLDC_mod1_terminate(void)
{
  uint32_T SPIPinsLoc;

  /* Terminate for MATLABSystem: '<S1>/SPI Transmit' */
  if (!PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/SPI Transmit' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
