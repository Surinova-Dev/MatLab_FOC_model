/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.c
 *
 * Code generated for Simulink model 'PMSM_to_BLDC_mod1'.
 *
 * Model version                  : 4.632
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Tue Apr 21 17:19:39 2026
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

/* Named constants for MATLAB Function: '<S6>/bit_shift' */
#define PMSM_to_BLDC_mod1_CALL_EVENT   (-1)

/* Named constants for MATLAB Function: '<S7>/bit_shift' */
#define PMSM_to_BLDC_mod1_CALL_EVENT_j (-1)

/* Named constants for Chart: '<Root>/Chart' */
#define PMSM_to_BLDC__IN_Initialization (2U)
#define PMSM_to_BLDC_mod1_IN_En_Gate   (1U)
#define PMSM_to_BLDC_mod1_IN_SPI_init1 (3U)
#define PMSM_to_BLDC_mod1_IN_SPI_init2 (4U)
#define PMSM_to_BLDC_mod1_IN_SPI_write (5U)
#define PMSM_to_BLDC_mod1_IN_SPI_write2 (6U)
#define PMSM_to_BLDC_mod1_IN_SPI_write3 (7U)
#define PMSM_to_BLDC_mod_IN_SPI_write4_ (8U)

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
 *    '<S4>/Bit Shift'
 *    '<S5>/Bit Shift'
 */
void PMSM_to_BLDC_mod1_BitShift_Init(DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* SystemInitialize for MATLAB Function: '<S6>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
}

/*
 * System reset for atomic system:
 *    '<S4>/Bit Shift'
 *    '<S5>/Bit Shift'
 */
void PMSM_to_BLDC_mod_BitShift_Reset(DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* SystemReset for MATLAB Function: '<S6>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
}

/*
 * Output and update for atomic system:
 *    '<S4>/Bit Shift'
 *    '<S5>/Bit Shift'
 */
void PMSM_to_BLDC_mod1_BitShift(uint16_T rtu_u, uint16_T *rty_y,
  DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* MATLAB Function: '<S6>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
  *rty_y = (uint16_T)(rtu_u << 15);
}

/*
 * System initialize for atomic system:
 *    '<S4>/Bit Shift1'
 *    '<S5>/Bit Shift4'
 */
void PMSM_to_BLDC_mod_BitShift1_Init(DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* SystemInitialize for MATLAB Function: '<S7>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_j;
}

/*
 * System reset for atomic system:
 *    '<S4>/Bit Shift1'
 *    '<S5>/Bit Shift4'
 */
void PMSM_to_BLDC_mo_BitShift1_Reset(DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* SystemReset for MATLAB Function: '<S7>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_j;
}

/*
 * Output and update for atomic system:
 *    '<S4>/Bit Shift1'
 *    '<S5>/Bit Shift4'
 */
void PMSM_to_BLDC_mod1_BitShift1(uint16_T rtu_u, uint16_T *rty_y,
  DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* MATLAB Function: '<S7>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_j;
  *rty_y = (uint16_T)(rtu_u << 11);
}

static void PMSM_to_B_SPIDrvBlock_setupImpl(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;

  /* Start for MATLABSystem: '<S4>/SPI Transmit' incorporates:
   *  MATLABSystem: '<S5>/SPI Transmit'
   */
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S4>/SPI Transmit' incorporates:
   *  MATLABSystem: '<S5>/SPI Transmit'
   */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S4>/SPI Transmit' incorporates:
   *  MATLABSystem: '<S5>/SPI Transmit'
   */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 1.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
}

/* Model step function */
void PMSM_to_BLDC_mod1_step(void)
{
  GPIO_TypeDef * portNameLoc;
  uint32_T shiftVal;
  uint32_T pinMask;
  uint32_T rtb_DataTypeConversion1;
  uint16_T y_a;
  uint16_T y_n;

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC);

  /* Chart: '<Root>/Chart' */
  if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 < 511) {
    PMSM_to_BLDC_mod1_DW.temporalCounter_i1++;
  }

  if (PMSM_to_BLDC_mod1_DW.is_active_c3_PMSM_to_BLDC_mod1 == 0) {
    PMSM_to_BLDC_mod1_DW.is_active_c3_PMSM_to_BLDC_mod1 = 1U;
    PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
    PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
      PMSM_to_BLDC__IN_Initialization;
    PMSM_to_BLDC_mod1_DW.CS_val = 1.0;
    PMSM_to_BLDC_mod1_B.En_State = 0.0;
  } else {
    switch (PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1) {
     case PMSM_to_BLDC_mod1_IN_En_Gate:
      PMSM_to_BLDC_mod1_B.En_State = 1.0;
      if ((PMSM_to_BLDC_mod1_B.En_State == 1.0) &&
          (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 500)) {
        PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
        PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
          PMSM_to_BLDC_mod1_IN_SPI_init1;
        PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 1.0;
      }
      break;

     case PMSM_to_BLDC__IN_Initialization:
      PMSM_to_BLDC_mod1_B.En_State = 0.0;
      if ((PMSM_to_BLDC_mod1_DW.CS_val == 1.0) &&
          (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 4)) {
        PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
        PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
          PMSM_to_BLDC_mod1_IN_En_Gate;
        PMSM_to_BLDC_mod1_B.En_State = 1.0;
      }
      break;

     case PMSM_to_BLDC_mod1_IN_SPI_init1:
      PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 1.0;
      if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 500) {
        PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
        PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
          PMSM_to_BLDC_mod1_IN_SPI_init2;
        PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 0.0;
      }
      break;

     case PMSM_to_BLDC_mod1_IN_SPI_init2:
      PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 0.0;
      if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 300) {
        PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 0.0;
        PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
        PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
          PMSM_to_BLDC_mod1_IN_SPI_write;
      } else {
        PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 1.0;
      }
      break;

     case PMSM_to_BLDC_mod1_IN_SPI_write:
      if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 200) {
        PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
        PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
          PMSM_to_BLDC_mod1_IN_SPI_write2;
        PMSM_to_BLDC_mod1_B.spi_write1 = 0.0;
      } else {
        PMSM_to_BLDC_mod1_B.spi_write1 = 1.0;
      }
      break;

     case PMSM_to_BLDC_mod1_IN_SPI_write2:
      if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 200) {
        PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
        PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
          PMSM_to_BLDC_mod1_IN_SPI_write3;
        PMSM_to_BLDC_mod1_B.read1 = 0.0;
      } else {
        PMSM_to_BLDC_mod1_B.read1 = 1.0;
      }
      break;

     case PMSM_to_BLDC_mod1_IN_SPI_write3:
      if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 200) {
        PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
        PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
          PMSM_to_BLDC_mod_IN_SPI_write4_;
        PMSM_to_BLDC_mod1_B.spi_write2 = 0.0;
      } else {
        PMSM_to_BLDC_mod1_B.spi_write2 = 1.0;
      }
      break;

     default:
      /* case IN_SPI_write4_: */
      if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 200) {
        PMSM_to_BLDC_mod1_B.read2 = 0.0;
        PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
        PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
          PMSM_to_BLDC_mod1_IN_SPI_write;
      } else {
        PMSM_to_BLDC_mod1_B.read2 = 1.0;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */
  /* Logic: '<S2>/AND1' */
  PMSM_to_BLDC_mod1_B.AND1 = ((PMSM_to_BLDC_mod1_B.En_State != 0.0) &&
    (PMSM_to_BLDC_mod1_B.Ctrl_flag2 != 0.0));

  /* Outputs for Enabled SubSystem: '<S2>/Control_Reg1_read' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  if (PMSM_to_BLDC_mod1_B.AND1) {
    if (!PMSM_to_BLDC_mod1_DW.Control_Reg1_read_MODE) {
      /* SystemReset for Atomic SubSystem: '<S4>/Bit Shift' */
      PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift);

      /* End of SystemReset for SubSystem: '<S4>/Bit Shift' */

      /* SystemReset for Atomic SubSystem: '<S4>/Bit Shift1' */
      PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1);

      /* End of SystemReset for SubSystem: '<S4>/Bit Shift1' */
      PMSM_to_BLDC_mod1_DW.Control_Reg1_read_MODE = true;
    }

    /* Outputs for Atomic SubSystem: '<S4>/Bit Shift' */
    /* Constant: '<S4>/Constant' */
    PMSM_to_BLDC_mod1_BitShift(0, &y_a, &PMSM_to_BLDC_mod1_DW.BitShift);

    /* End of Outputs for SubSystem: '<S4>/Bit Shift' */

    /* Outputs for Atomic SubSystem: '<S4>/Bit Shift1' */
    /* Constant: '<S4>/Constant1' */
    PMSM_to_BLDC_mod1_BitShift1(3, &y_n, &PMSM_to_BLDC_mod1_DW.BitShift1);

    /* End of Outputs for SubSystem: '<S4>/Bit Shift1' */

    /* S-Function (sfix_bitop): '<S4>/Bitwise OR' */
    PMSM_to_BLDC_mod1_B.BitwiseOR = (uint16_T)(y_a | y_n |
      PMSM_to_BLDC_mod1_ConstB.BitwiseAND);

    /* DataTypeConversion: '<S4>/Data Type Conversion' */
    PMSM_to_BLDC_mod1_B.DataTypeConversion = PMSM_to_BLDC_mod1_B.BitwiseOR;

    /* MATLABSystem: '<S4>/SPI Transmit' */
    y_a = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE, 2U,
      3840U, MW_SPI_MODE_3);
    if (y_a == 0) {
      LL_GPIO_ResetOutputPin(GPIOC, 16384U);
      MW_SPI_Write_Databits(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE,
                            &PMSM_to_BLDC_mod1_B.DataTypeConversion, 1U, 1, 1,
                            1000U);
    }

    /* End of MATLABSystem: '<S4>/SPI Transmit' */
    srUpdateBC(PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC);
  } else {
    PMSM_to_BLDC_mod1_DW.Control_Reg1_read_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S2>/Control_Reg1_read' */

  /* Logic: '<S2>/AND' */
  PMSM_to_BLDC_mod1_B.AND = ((PMSM_to_BLDC_mod1_B.En_State != 0.0) &&
    (PMSM_to_BLDC_mod1_B.Ctrl_flag1 != 0.0));

  /* Outputs for Enabled SubSystem: '<S2>/Ctrl_Reg_1' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (PMSM_to_BLDC_mod1_B.AND) {
    if (!PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_MODE) {
      /* SystemReset for Atomic SubSystem: '<S5>/Bit Shift' */
      PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_m);

      /* End of SystemReset for SubSystem: '<S5>/Bit Shift' */

      /* SystemReset for Atomic SubSystem: '<S5>/Bit Shift4' */
      PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift4);

      /* End of SystemReset for SubSystem: '<S5>/Bit Shift4' */
      PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_MODE = true;
    }

    /* Outputs for Atomic SubSystem: '<S5>/Bit Shift' */
    /* Constant: '<S5>/Constant5' */
    PMSM_to_BLDC_mod1_BitShift(0, &y_a, &PMSM_to_BLDC_mod1_DW.BitShift_m);

    /* End of Outputs for SubSystem: '<S5>/Bit Shift' */

    /* Outputs for Atomic SubSystem: '<S5>/Bit Shift4' */
    /* Constant: '<S5>/Constant6' */
    PMSM_to_BLDC_mod1_BitShift1(2, &y_n, &PMSM_to_BLDC_mod1_DW.BitShift4);

    /* End of Outputs for SubSystem: '<S5>/Bit Shift4' */

    /* S-Function (sfix_bitop): '<S5>/Bitwise AND' */
    PMSM_to_BLDC_mod1_B.ctrl_reg1 = (uint16_T)(y_a | y_n |
      PMSM_to_BLDC_mod1_ConstB.BitwiseOR);

    /* DataTypeConversion: '<S5>/Data Type Conversion1' */
    rtb_DataTypeConversion1 = PMSM_to_BLDC_mod1_B.ctrl_reg1;

    /* MATLABSystem: '<S5>/SPI Transmit' */
    y_a = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, 2U,
      3840U, MW_SPI_MODE_3);
    if (y_a == 0) {
      LL_GPIO_ResetOutputPin(GPIOC, 16384U);
      MW_SPI_Write_Databits(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE,
                            &rtb_DataTypeConversion1, 1U, 2, 1, 1000U);
    }

    /* End of MATLABSystem: '<S5>/SPI Transmit' */
    srUpdateBC(PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC);
  } else {
    PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S2>/Ctrl_Reg_1' */
  /* MATLABSystem: '<S16>/Digital Port Write' */
  portNameLoc = GPIOB;
  shiftVal = MW_GPIO_BIT_SHIFT;
  if (PMSM_to_BLDC_mod1_B.En_State != 0.0) {
    rtb_DataTypeConversion1 = 4096U;
  } else {
    rtb_DataTypeConversion1 = 0U;
  }

  rtb_DataTypeConversion1 = mw_shift(rtb_DataTypeConversion1, shiftVal);
  pinMask = mw_shift(4096U, shiftVal);
  LL_GPIO_SetOutputPin(portNameLoc, rtb_DataTypeConversion1);
  LL_GPIO_ResetOutputPin(portNameLoc, ~rtb_DataTypeConversion1 & pinMask);

  /* End of MATLABSystem: '<S16>/Digital Port Write' */

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
  rtmSetTFinal(PMSM_to_BLDC_mod1_M, 100.0);
  PMSM_to_BLDC_mod1_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  PMSM_to_BLDC_mod1_M->Sizes.checksums[0] = (3519009478U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[1] = (3820469967U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[2] = (3929514537U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[3] = (60807518U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[15];
    PMSM_to_BLDC_mod1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC;
    systemRan[7] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC;
    systemRan[8] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[9] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[10] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[11] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[12] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[13] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[14] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PMSM_to_BLDC_mod1_M->extModeInfo,
      &PMSM_to_BLDC_mod1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PMSM_to_BLDC_mod1_M->extModeInfo,
                        PMSM_to_BLDC_mod1_M->Sizes.checksums);
    rteiSetTPtr(PMSM_to_BLDC_mod1_M->extModeInfo, rtmGetTPtr(PMSM_to_BLDC_mod1_M));
  }

  /* SystemInitialize for Atomic SubSystem: '<S4>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift);

  /* End of SystemInitialize for SubSystem: '<S4>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S4>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1);

  /* End of SystemInitialize for SubSystem: '<S4>/Bit Shift1' */

  /* Start for MATLABSystem: '<S4>/SPI Transmit' */
  PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete = false;
  PMSM_to_BLDC_mod1_DW.obj_j.isInitialized = 1;
  PMSM_to_B_SPIDrvBlock_setupImpl(&PMSM_to_BLDC_mod1_DW.obj_j);
  PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<S2>/Control_Reg1_read' */
  /* SystemInitialize for Atomic SubSystem: '<S5>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_m);

  /* End of SystemInitialize for SubSystem: '<S5>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S5>/Bit Shift4' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift4);

  /* End of SystemInitialize for SubSystem: '<S5>/Bit Shift4' */

  /* Start for MATLABSystem: '<S5>/SPI Transmit' */
  PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj.isSetupComplete = false;
  PMSM_to_BLDC_mod1_DW.obj.isInitialized = 1;
  PMSM_to_B_SPIDrvBlock_setupImpl(&PMSM_to_BLDC_mod1_DW.obj);
  PMSM_to_BLDC_mod1_DW.obj.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<S2>/Ctrl_Reg_1' */

  /* Start for MATLABSystem: '<S16>/Digital Port Write' */
  PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_o.isInitialized = 1;
  PMSM_to_BLDC_mod1_DW.obj_o.isSetupComplete = true;
}

/* Model terminate function */
void PMSM_to_BLDC_mod1_terminate(void)
{
  uint32_T SPIPinsLoc;

  /* Terminate for MATLABSystem: '<S4>/SPI Transmit' */
  if (!PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_j.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/SPI Transmit' */
  /* Terminate for Enabled SubSystem: '<S2>/Ctrl_Reg_1' */
  /* Terminate for MATLABSystem: '<S5>/SPI Transmit' */
  if (!PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/SPI Transmit' */
  /* Terminate for MATLABSystem: '<S16>/Digital Port Write' */
  if (!PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S16>/Digital Port Write' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
