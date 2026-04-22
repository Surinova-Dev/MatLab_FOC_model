/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.c
 *
 * Code generated for Simulink model 'PMSM_to_BLDC_mod1'.
 *
 * Model version                  : 4.665
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Wed Apr 22 17:47:26 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PMSM_to_BLDC_mod1.h"
#include "rtwtypes.h"
#include "PMSM_to_BLDC_mod1_private.h"

/* Named constants for MATLAB Function: '<S10>/bit_shift' */
#define PMSM_to_BLDC_mod1_CALL_EVENT   (-1)

/* Named constants for MATLAB Function: '<S11>/bit_shift' */
#define PMSM_to_BLDC_mod1_CALL_EVENT_b (-1)

/* Named constants for Chart: '<Root>/Chart' */
#define PMSM_to_BLDC__IN_Initialization (2U)
#define PMSM_to_BLDC_mod1_IN_En_Gate   (1U)
#define PMSM_to_BLDC_mod1_IN_SPI_init1 (3U)
#define PMSM_to_BLDC_mod1_IN_SPI_init2 (4U)
#define PMSM_to_BLDC_mod1_IN_SPI_init3 (5U)
#define PMSM_to_BLDC_mod1_IN_SPI_init4 (6U)
#define PMSM_to_BLDC_mod1_IN_SPI_write (7U)
#define PMSM_to_BLDC_mod1_IN_SPI_write2 (8U)
#define PMSM_to_BLDC_mod1_IN_SPI_write3 (9U)
#define PMSM_to_BLDC_mod1_IN_SPI_write4 (10U)
#define PMSM_to_BLDC_mod1_IN_SPI_write5 (11U)
#define PMSM_to_BLDC_mod1_IN_SPI_write6 (12U)
#define PMSM_to_BLDC_mod1_IN_SPI_write7 (13U)
#define PMSM_to_BLDC_mod1_IN_SPI_write8 (14U)

/* Block signals (default storage) */
B_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_B;

/* Block states (default storage) */
DW_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_DW;

/* Real-time model */
static RT_MODEL_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_M_;
RT_MODEL_PMSM_to_BLDC_mod1_T *const PMSM_to_BLDC_mod1_M = &PMSM_to_BLDC_mod1_M_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1])++;
  if ((PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1]) > 999) {/* Sample time: [1.0s, 0.0s] */
    PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * System initialize for atomic system:
 *    '<S8>/Bit Shift'
 *    '<S9>/Bit Shift'
 */
void PMSM_to_BLDC_mod1_BitShift_Init(DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* SystemInitialize for MATLAB Function: '<S10>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
}

/*
 * System reset for atomic system:
 *    '<S8>/Bit Shift'
 *    '<S9>/Bit Shift'
 */
void PMSM_to_BLDC_mod_BitShift_Reset(DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* SystemReset for MATLAB Function: '<S10>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
}

/*
 * Output and update for atomic system:
 *    '<S8>/Bit Shift'
 *    '<S9>/Bit Shift'
 */
void PMSM_to_BLDC_mod1_BitShift(uint16_T rtu_u, uint16_T *rty_y,
  DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* MATLAB Function: '<S10>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
  *rty_y = (uint16_T)(rtu_u << 15);
}

/*
 * System initialize for atomic system:
 *    '<S8>/Bit Shift1'
 *    '<S9>/Bit Shift1'
 */
void PMSM_to_BLDC_mod_BitShift1_Init(DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* SystemInitialize for MATLAB Function: '<S11>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_b;
}

/*
 * System reset for atomic system:
 *    '<S8>/Bit Shift1'
 *    '<S9>/Bit Shift1'
 */
void PMSM_to_BLDC_mo_BitShift1_Reset(DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* SystemReset for MATLAB Function: '<S11>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_b;
}

/*
 * Output and update for atomic system:
 *    '<S8>/Bit Shift1'
 *    '<S9>/Bit Shift1'
 */
void PMSM_to_BLDC_mod1_BitShift1(uint16_T rtu_u, uint16_T *rty_y,
  DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* MATLAB Function: '<S11>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_b;
  *rty_y = (uint16_T)(rtu_u << 11);
}

/* Model step function */
void PMSM_to_BLDC_mod1_step(void)
{
  GPIO_TypeDef * portNameLoc;
  uint32_T shiftVal;
  uint32_T pinMask;
  uint32_T pinWriteLoc;
  uint16_T y_m;
  uint16_T y_o;

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Control_Reg_2_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC);
  if (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Chart: '<Root>/Chart' */
    if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 < 7) {
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
            (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 5)) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_init1;
          PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 1.0;
        }
        break;

       case PMSM_to_BLDC__IN_Initialization:
        PMSM_to_BLDC_mod1_B.En_State = 0.0;
        if ((PMSM_to_BLDC_mod1_DW.CS_val == 1.0) &&
            (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 1)) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_En_Gate;
          PMSM_to_BLDC_mod1_B.En_State = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_init1:
        PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 5) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_init2;
          PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 0.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_init2:
        PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 1) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_init3;
          PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_init3:
        PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 3) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_init4;
          PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 0.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_init4:
        PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 1) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_write;
          PMSM_to_BLDC_mod1_B.spi_write1 = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write:
        PMSM_to_BLDC_mod1_B.spi_write1 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_write2;
          PMSM_to_BLDC_mod1_B.spi_write1 = 0.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write2:
        PMSM_to_BLDC_mod1_B.spi_write1 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_write3;
          PMSM_to_BLDC_mod1_B.read1 = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write3:
        PMSM_to_BLDC_mod1_B.read1 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_write4;
          PMSM_to_BLDC_mod1_B.read1 = 0.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write4:
        PMSM_to_BLDC_mod1_B.read1 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_write5;
          PMSM_to_BLDC_mod1_B.spi_write2 = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write5:
        PMSM_to_BLDC_mod1_B.spi_write2 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_write6;
          PMSM_to_BLDC_mod1_B.spi_write2 = 0.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write6:
        PMSM_to_BLDC_mod1_B.spi_write2 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_write7;
          PMSM_to_BLDC_mod1_B.read2 = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write7:
        PMSM_to_BLDC_mod1_B.read2 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_write8;
          PMSM_to_BLDC_mod1_B.read2 = 0.0;
        }
        break;

       default:
        /* case IN_SPI_write8: */
        PMSM_to_BLDC_mod1_B.read2 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_write;
          PMSM_to_BLDC_mod1_B.spi_write1 = 1.0;
        }
        break;
      }
    }

    /* End of Chart: '<Root>/Chart' */
    /* MATLABSystem: '<S7>/Digital Port Write' */
    portNameLoc = GPIOB;
    shiftVal = MW_GPIO_BIT_SHIFT;
    if (PMSM_to_BLDC_mod1_B.En_State != 0.0) {
      pinWriteLoc = 4096U;
    } else {
      pinWriteLoc = 0U;
    }

    pinWriteLoc = mw_shift(pinWriteLoc, shiftVal);
    pinMask = mw_shift(4096U, shiftVal);
    LL_GPIO_SetOutputPin(portNameLoc, pinWriteLoc);
    LL_GPIO_ResetOutputPin(portNameLoc, ~pinWriteLoc & pinMask);

    /* End of MATLABSystem: '<S7>/Digital Port Write' */

    /* Outputs for Enabled SubSystem: '<S3>/Control_Reg1_read' incorporates:
     *  EnablePort: '<S8>/Ctrl_flag1'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write1 > 0.0) {
      if (!PMSM_to_BLDC_mod1_DW.Control_Reg1_read_MODE) {
        /* InitializeConditions for Delay: '<S8>/Delay' */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i = 0U;

        /* SystemReset for Atomic SubSystem: '<S8>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift);

        /* End of SystemReset for SubSystem: '<S8>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S8>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1);

        /* End of SystemReset for SubSystem: '<S8>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Control_Reg1_read_MODE = true;
      }

      /* Delay: '<S8>/Delay' */
      PMSM_to_BLDC_mod1_B.Delay_n = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i;

      /* CCaller: '<S8>/C Caller' */
      PMSM_to_BLDC_mod1_B.CCaller_h = SPI_ReadReg(PMSM_to_BLDC_mod1_B.Delay_n);

      /* Outputs for Atomic SubSystem: '<S8>/Bit Shift' */
      /* Constant: '<S8>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(1, &y_m, &PMSM_to_BLDC_mod1_DW.BitShift);

      /* End of Outputs for SubSystem: '<S8>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S8>/Bit Shift1' */
      /* Constant: '<S8>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(2, &y_o, &PMSM_to_BLDC_mod1_DW.BitShift1);

      /* End of Outputs for SubSystem: '<S8>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S8>/Bitwise OR' */
      PMSM_to_BLDC_mod1_B.BitwiseOR = (uint16_T)(y_m | y_o |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_b);

      /* Update for Delay: '<S8>/Delay' */
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i = PMSM_to_BLDC_mod1_B.BitwiseOR;
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC);
    } else if (PMSM_to_BLDC_mod1_DW.Control_Reg1_read_MODE) {
      /* Disable for CCaller: '<S8>/C Caller' incorporates:
       *  Outport: '<S8>/Out1'
       */
      PMSM_to_BLDC_mod1_B.CCaller_h = 0U;
      PMSM_to_BLDC_mod1_DW.Control_Reg1_read_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S3>/Control_Reg1_read' */

    /* Outputs for Enabled SubSystem: '<S3>/Control_Reg_2_read' incorporates:
     *  EnablePort: '<S9>/Ctrl_flag2'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write2 > 0.0) {
      if (!PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_MODE) {
        /* InitializeConditions for Delay: '<S9>/Delay' */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE = 0U;

        /* SystemReset for Atomic SubSystem: '<S9>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_b);

        /* End of SystemReset for SubSystem: '<S9>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S9>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_m);

        /* End of SystemReset for SubSystem: '<S9>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_MODE = true;
      }

      /* Delay: '<S9>/Delay' */
      PMSM_to_BLDC_mod1_B.Delay = PMSM_to_BLDC_mod1_DW.Delay_DSTATE;

      /* CCaller: '<S9>/C Caller' */
      PMSM_to_BLDC_mod1_B.CCaller = SPI_ReadReg(PMSM_to_BLDC_mod1_B.Delay);

      /* Outputs for Atomic SubSystem: '<S9>/Bit Shift' */
      /* Constant: '<S9>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(1, &y_m, &PMSM_to_BLDC_mod1_DW.BitShift_b);

      /* End of Outputs for SubSystem: '<S9>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S9>/Bit Shift1' */
      /* Constant: '<S9>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(3, &y_o, &PMSM_to_BLDC_mod1_DW.BitShift1_m);

      /* End of Outputs for SubSystem: '<S9>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S9>/Bitwise OR' incorporates:
       *  Delay: '<S9>/Delay'
       */
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE = (uint16_T)(y_m | y_o |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND);
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_SubsysRanBC);
    } else if (PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_MODE) {
      /* Disable for CCaller: '<S9>/C Caller' incorporates:
       *  Outport: '<S9>/Out1'
       */
      PMSM_to_BLDC_mod1_B.CCaller = 0U;
      PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S3>/Control_Reg_2_read' */
    /* Logic: '<S4>/AND1' */
    PMSM_to_BLDC_mod1_B.AND1 = ((PMSM_to_BLDC_mod1_B.En_State != 0.0) &&
      (PMSM_to_BLDC_mod1_B.Ctrl_flag2 != 0.0));

    /* Outputs for Enabled SubSystem: '<S4>/Control_Reg_2' incorporates:
     *  EnablePort: '<S18>/Enable'
     */
    if (PMSM_to_BLDC_mod1_B.AND1) {
      /* DataTypeConversion: '<S18>/Data Type Conversion' incorporates:
       *  Constant: '<S18>/Constant3'
       */
      PMSM_to_BLDC_mod1_B.DataTypeConversion = 6148U;

      /* CCaller: '<S18>/C Caller' */
      SPI_WriteReg(PMSM_to_BLDC_mod1_B.DataTypeConversion);
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Control_Reg_2_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S4>/Control_Reg_2' */

    /* Logic: '<S4>/AND' */
    PMSM_to_BLDC_mod1_B.AND = ((PMSM_to_BLDC_mod1_B.En_State != 0.0) &&
      (PMSM_to_BLDC_mod1_B.Ctrl_flag1 != 0.0));

    /* Outputs for Enabled SubSystem: '<S4>/Ctrl_Reg_1' incorporates:
     *  EnablePort: '<S19>/Enable'
     */
    if (PMSM_to_BLDC_mod1_B.AND) {
      /* CCaller: '<S19>/C Caller' incorporates:
       *  Constant: '<S19>/Constant'
       */
      SPI_WriteReg(5456U);
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S4>/Ctrl_Reg_1' */
  }

  {                                    /* Sample time: [0.001s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      PMSM_to_BLDC_mod1_M->Timing.taskTime0;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0, extmodeTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  if (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [1.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((PMSM_to_BLDC_mod1_M->Timing.clockTick1) * 1.0);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1, extmodeTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  PMSM_to_BLDC_mod1_M->Timing.taskTime0 =
    ((time_T)(++PMSM_to_BLDC_mod1_M->Timing.clockTick0)) *
    PMSM_to_BLDC_mod1_M->Timing.stepSize0;
  if (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [1.0s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 1.0, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    PMSM_to_BLDC_mod1_M->Timing.clockTick1++;
  }

  rate_scheduler();
}

/* Model initialize function */
void PMSM_to_BLDC_mod1_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(PMSM_to_BLDC_mod1_M, 100.0);
  PMSM_to_BLDC_mod1_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  PMSM_to_BLDC_mod1_M->Sizes.checksums[0] = (821751645U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[1] = (194484485U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[2] = (231222924U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[3] = (2541526671U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[15];
    PMSM_to_BLDC_mod1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
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
    systemRan[8] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_SubsysRanBC;
    systemRan[9] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg_2_SubsysRanBC;
    systemRan[14] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    rteiSetModelMappingInfoPtr(PMSM_to_BLDC_mod1_M->extModeInfo,
      &PMSM_to_BLDC_mod1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PMSM_to_BLDC_mod1_M->extModeInfo,
                        PMSM_to_BLDC_mod1_M->Sizes.checksums);
    rteiSetTPtr(PMSM_to_BLDC_mod1_M->extModeInfo, rtmGetTPtr(PMSM_to_BLDC_mod1_M));
  }

  /* SystemInitialize for Atomic SubSystem: '<S8>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift);

  /* End of SystemInitialize for SubSystem: '<S8>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S8>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1);

  /* End of SystemInitialize for SubSystem: '<S8>/Bit Shift1' */
  /* End of SystemInitialize for SubSystem: '<S3>/Control_Reg1_read' */

  /* SystemInitialize for Atomic SubSystem: '<S9>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_b);

  /* End of SystemInitialize for SubSystem: '<S9>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S9>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_m);

  /* End of SystemInitialize for SubSystem: '<S9>/Bit Shift1' */
  /* End of SystemInitialize for SubSystem: '<S3>/Control_Reg_2_read' */

  /* Start for MATLABSystem: '<S7>/Digital Port Write' */
  PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj.isInitialized = 1;
  PMSM_to_BLDC_mod1_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void PMSM_to_BLDC_mod1_terminate(void)
{
  /* Terminate for MATLABSystem: '<S7>/Digital Port Write' */
  if (!PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S7>/Digital Port Write' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
