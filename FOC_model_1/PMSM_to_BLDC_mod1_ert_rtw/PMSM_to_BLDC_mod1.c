/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.c
 *
 * Code generated for Simulink model 'PMSM_to_BLDC_mod1'.
 *
 * Model version                  : 4.1012
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Tue May 26 17:31:20 2026
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
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>
#include "stm_adc_ll.h"
#include <stddef.h>
#include "stm_timer_ll.h"
#include "zero_crossing_types.h"
#include <float.h>

/* Named constants for MATLAB Function: '<S25>/bit_shift' */
#define PMSM_to_BLDC_mod1_CALL_EVENT   (-1)

/* Named constants for MATLAB Function: '<S26>/bit_shift' */
#define PMSM_to_BLDC_mod1_CALL_EVENT_j (-1)

/* Named constants for Chart: '<Root>/Chart' */
#define PMSM_to_BLDC__IN_Initialization (3U)
#define PMSM_to_BLDC_m_IN_Current_sense (1U)
#define PMSM_to_BLDC_mod1_IN_Dummy     (1U)
#define PMSM_to_BLDC_mod1_IN_En_Gate   (2U)
#define PMSM_to_BLDC_mod1_IN_SPI_init1 (4U)
#define PMSM_to_BLDC_mod1_IN_SPI_init2 (5U)
#define PMSM_to_BLDC_mod1_IN_SPI_init3 (6U)
#define PMSM_to_BLDC_mod1_IN_SPI_init4 (7U)
#define PMSM_to_BLDC_mod1_IN_SPI_write (2U)
#define PMSM_to_BLDC_mod1_IN_SPI_write2 (4U)
#define PMSM_to_BLDC_mod1_IN_SPI_write5 (5U)
#define PMSM_to_BLDC_mod1_IN_SPI_write6 (6U)
#define PMSM_to_BLDC_mod1_IN_SPI_write7 (7U)
#define PMSM_to_BLDC_mod1_IN_SPI_write8 (8U)
#define PMSM_to_BLDC_mod1_IN_SPI_write9 (9U)
#define PMSM_to_BLDC_mod_IN_SPI_write10 (3U)

/* Block signals (default storage) */
B_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_B;

/* Continuous states */
X_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_X;

/* Disabled State Vector */
XDis_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_XDis;

/* Block states (default storage) */
DW_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_PrevZCX;

/* Periodic continuous states */
PeriodicIndX_PMSM_to_BLDC_mod_T PMSM_to_BLDC_mod1_PeriodicIndX;
PeriodicRngX_PMSM_to_BLDC_mod_T PMSM_to_BLDC_mod1_PeriodicRngX;

/* Real-time model */
static RT_MODEL_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_M_;
RT_MODEL_PMSM_to_BLDC_mod1_T *const PMSM_to_BLDC_mod1_M = &PMSM_to_BLDC_mod1_M_;

/* Forward declaration for local functions */
static void PMSM_to_BLDC_m_SystemCore_setup(stm32cube_blocks_SPIControlle_T *obj);

/* Forward declaration for local functions */
static void PMSM_to_B_SPIDrvBlock_setupImpl(stm32cube_blocks_SPIControl_d_T *obj);

/* Forward declaration for local functions */
static void PMSM_to_BLDC_SystemCore_setup_n(stm32cube_blocks_SPIControlle_T *obj);

/* Forward declaration for local functions */
static void PMSM_to_BLD_SystemCore_setup_n2(stm32cube_blocks_SPIControlle_T *obj);

/* Forward declaration for local functions */
static void PMSM_to_SPIDrvBlock_setupImpl_e(stm32cube_blocks_SPIControl_d_T *obj);

/* Forward declaration for local functions */
static void PMSM_to_BL_SystemCore_setup_oxg(stm32cube_blocks_SPIControlle_T *obj);
static void PMSM_to_SPIDrvBlock_setupImpl_o(stm32cube_blocks_SPIControl_d_T *obj);
static void PMSM_to_B_SystemCore_setup_oxgk(stm32cube_blocks_SPIControlle_T *obj);
static void PMSM_to_BLDC_SystemCore_setup_o(stm32cube_blocks_AnalogInput__T *obj);
static void PMSM_to_BLD_SystemCore_setup_ox(stm32cube_blocks_AnalogInput__T *obj);
static void PMSM_to_BLD_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_PM_T *obj);
static void PMSM_to__SystemCore_setup_oxgkf(stm32cube_blocks_AnalogInput__T *obj);
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
  (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2])++;
  if ((PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2]) > 1) {/* Sample time: [0.0001s, 0.0s] */
    PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] = 0;
  }

  (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[3])++;
  if ((PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[3]) > 19) {/* Sample time: [0.001s, 0.0s] */
    PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[3] = 0;
  }

  (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[4])++;
  if ((PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[4]) > 1999) {/* Sample time: [0.1s, 0.0s] */
    PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[4] = 0;
  }

  (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[5])++;
  if ((PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[5]) > 19999) {/* Sample time: [1.0s, 0.0s] */
    PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[5] = 0;
  }
}

/* State reduction function */
void local_stateReduction(real_T* x, int_T* p, int_T n, real_T* r)
{
  int_T i, j;
  for (i = 0, j = 0; i < n; ++i, ++j) {
    int_T k = p[i];
    real_T lb = r[j++];
    real_T xk = x[k]-lb;
    real_T rk = r[j]-lb;
    int_T q = (int_T) floor(xk/rk);
    if (q) {
      x[k] = xk-q*rk+lb;
    }
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  PMSM_to_BLDC_mod1_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  PMSM_to_BLDC_mod1_step();
  PMSM_to_BLDC_mod1_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  PMSM_to_BLDC_mod1_step();
  PMSM_to_BLDC_mod1_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  local_stateReduction(rtsiGetContStates(si), rtsiGetPeriodicContStateIndices(si),
                       1,
                       rtsiGetPeriodicContStateRanges(si));
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * System initialize for atomic system:
 *    '<S23>/Bit Shift'
 *    '<S24>/Bit Shift'
 *    '<S37>/Bit Shift'
 *    '<S43>/Bit Shift'
 *    '<S49>/Bit Shift'
 *    '<S50>/Bit Shift'
 */
void PMSM_to_BLDC_mod1_BitShift_Init(DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* SystemInitialize for MATLAB Function: '<S25>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
}

/*
 * System reset for atomic system:
 *    '<S23>/Bit Shift'
 *    '<S24>/Bit Shift'
 *    '<S37>/Bit Shift'
 *    '<S43>/Bit Shift'
 *    '<S49>/Bit Shift'
 *    '<S50>/Bit Shift'
 */
void PMSM_to_BLDC_mod_BitShift_Reset(DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* SystemReset for MATLAB Function: '<S25>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
}

/*
 * Output and update for atomic system:
 *    '<S23>/Bit Shift'
 *    '<S24>/Bit Shift'
 *    '<S37>/Bit Shift'
 *    '<S43>/Bit Shift'
 *    '<S49>/Bit Shift'
 *    '<S50>/Bit Shift'
 */
void PMSM_to_BLDC_mod1_BitShift(uint16_T rtu_u, uint16_T *rty_y,
  DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* MATLAB Function: '<S25>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
  *rty_y = (uint16_T)(rtu_u << 15);
}

/*
 * System initialize for atomic system:
 *    '<S23>/Bit Shift1'
 *    '<S24>/Bit Shift1'
 *    '<S37>/Bit Shift1'
 *    '<S43>/Bit Shift1'
 *    '<S49>/Bit Shift1'
 *    '<S50>/Bit Shift1'
 */
void PMSM_to_BLDC_mod_BitShift1_Init(DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* SystemInitialize for MATLAB Function: '<S26>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_j;
}

/*
 * System reset for atomic system:
 *    '<S23>/Bit Shift1'
 *    '<S24>/Bit Shift1'
 *    '<S37>/Bit Shift1'
 *    '<S43>/Bit Shift1'
 *    '<S49>/Bit Shift1'
 *    '<S50>/Bit Shift1'
 */
void PMSM_to_BLDC_mo_BitShift1_Reset(DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* SystemReset for MATLAB Function: '<S26>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_j;
}

/*
 * Output and update for atomic system:
 *    '<S23>/Bit Shift1'
 *    '<S24>/Bit Shift1'
 *    '<S37>/Bit Shift1'
 *    '<S43>/Bit Shift1'
 *    '<S49>/Bit Shift1'
 *    '<S50>/Bit Shift1'
 */
void PMSM_to_BLDC_mod1_BitShift1(uint16_T rtu_u, uint16_T *rty_y,
  DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* MATLAB Function: '<S26>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_j;
  *rty_y = (uint16_T)(rtu_u << 11);
}

static void PMSM_to_BLDC_m_SystemCore_setup(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S37>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S37>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S37>/SPI Receive' */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 15.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
  obj->isSetupComplete = true;
}

/* System initialize for atomic system: */
void PMSM_to_BLDC_mo_SPIReceive_Init(DW_SPIReceive_PMSM_to_BLDC_mo_T *localDW)
{
  /* Start for MATLABSystem: '<S37>/SPI Receive' */
  localDW->obj.isInitialized = 0;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  PMSM_to_BLDC_m_SystemCore_setup(&localDW->obj);
}

/* Output and update for atomic system: */
void PMSM_to_BLDC_mod1_SPIReceive(DW_SPIReceive_PMSM_to_BLDC_mo_T *localDW)
{
  uint16_T tmp[15];
  uint16_T status;

  /* MATLABSystem: '<S37>/SPI Receive' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    MW_SPI_Read_Databits(localDW->obj.MW_SPI_HANDLE, &tmp[0], 15U, 1, 1, 1U);
    LL_GPIO_SetOutputPin(GPIOC, 16384U);
  }

  /* End of MATLABSystem: '<S37>/SPI Receive' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC_mo_SPIReceive_Term(DW_SPIReceive_PMSM_to_BLDC_mo_T *localDW)
{
  /* Terminate for MATLABSystem: '<S37>/SPI Receive' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S37>/SPI Receive' */
}

static void PMSM_to_B_SPIDrvBlock_setupImpl(stm32cube_blocks_SPIControl_d_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;

  /* Start for MATLABSystem: '<S37>/SPI Transmit' */
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S37>/SPI Transmit' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S37>/SPI Transmit' */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 1.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
}

/* System initialize for atomic system: */
void PMSM_to_BLDC_m_SPITransmit_Init(DW_SPITransmit_PMSM_to_BLDC_m_T *localDW)
{
  /* Start for MATLABSystem: '<S37>/SPI Transmit' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  PMSM_to_B_SPIDrvBlock_setupImpl(&localDW->obj);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void PMSM_to_BLDC_mod1_SPITransmit(uint16_T rtu_0,
  DW_SPITransmit_PMSM_to_BLDC_m_T *localDW)
{
  uint16_T status;

  /* MATLABSystem: '<S37>/SPI Transmit' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    LL_GPIO_ResetOutputPin(GPIOC, 16384U);
    MW_SPI_Write_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0, 1U, 1, 1, 1U);
  }

  /* End of MATLABSystem: '<S37>/SPI Transmit' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC_m_SPITransmit_Term(DW_SPITransmit_PMSM_to_BLDC_m_T *localDW)
{
  /* Terminate for MATLABSystem: '<S37>/SPI Transmit' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S37>/SPI Transmit' */
}

static void PMSM_to_BLDC_SystemCore_setup_n(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S38>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S38>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S38>/SPI Receive' */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 1.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
  obj->isSetupComplete = true;
}

/* System initialize for atomic system: */
void PMSM_to_BLDC__SPIReceive_e_Init(DW_SPIReceive_PMSM_to_BLDC__f_T *localDW)
{
  /* Start for MATLABSystem: '<S38>/SPI Receive' */
  localDW->obj.isInitialized = 0;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  PMSM_to_BLDC_SystemCore_setup_n(&localDW->obj);
}

/* Output and update for atomic system: */
void PMSM_to_BLDC_mod1_SPIReceive_p(B_SPIReceive_PMSM_to_BLDC_m_c_T *localB,
  DW_SPIReceive_PMSM_to_BLDC__f_T *localDW)
{
  uint16_T status;

  /* MATLABSystem: '<S38>/SPI Receive' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    MW_SPI_Read_Databits(localDW->obj.MW_SPI_HANDLE, &localB->SPIReceive, 1U, 1,
                         1, 1U);
    LL_GPIO_SetOutputPin(GPIOC, 16384U);
  }

  /* End of MATLABSystem: '<S38>/SPI Receive' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC__SPIReceive_m_Term(DW_SPIReceive_PMSM_to_BLDC__f_T *localDW)
{
  /* Terminate for MATLABSystem: '<S38>/SPI Receive' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S38>/SPI Receive' */
}

static void PMSM_to_BLD_SystemCore_setup_n2(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S49>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S49>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S49>/SPI Receive' */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 15.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
  obj->isSetupComplete = true;
}

/* System initialize for atomic system: */
void PMSM_to_BLDC__SPIReceive_k_Init(DW_SPIReceive_PMSM_to_BLDC_fw_T *localDW)
{
  /* Start for MATLABSystem: '<S49>/SPI Receive' */
  localDW->obj.isInitialized = 0;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  PMSM_to_BLD_SystemCore_setup_n2(&localDW->obj);
}

/* Output and update for atomic system: */
void PMSM_to_BLDC_mod1_SPIReceive_pn(B_SPIReceive_PMSM_to_BLDC__ca_T *localB,
  DW_SPIReceive_PMSM_to_BLDC_fw_T *localDW)
{
  uint16_T status;

  /* MATLABSystem: '<S49>/SPI Receive' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    MW_SPI_Read_Databits(localDW->obj.MW_SPI_HANDLE, &localB->SPIReceive[0], 15U,
                         1, 1, 1U);
    LL_GPIO_SetOutputPin(GPIOC, 16384U);
  }

  /* End of MATLABSystem: '<S49>/SPI Receive' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC__SPIReceive_c_Term(DW_SPIReceive_PMSM_to_BLDC_fw_T *localDW)
{
  /* Terminate for MATLABSystem: '<S49>/SPI Receive' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S49>/SPI Receive' */
}

static void PMSM_to_SPIDrvBlock_setupImpl_e(stm32cube_blocks_SPIControl_d_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;

  /* Start for MATLABSystem: '<S49>/SPI Transmit' */
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S49>/SPI Transmit' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S49>/SPI Transmit' */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 1.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
}

/* System initialize for atomic system: */
void PMSM_to_BLDC_SPITransmit_d_Init(DW_SPITransmit_PMSM_to_BLDC_f_T *localDW)
{
  /* Start for MATLABSystem: '<S49>/SPI Transmit' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  PMSM_to_SPIDrvBlock_setupImpl_e(&localDW->obj);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void PMSM_to_BLDC_mod1_SPITransmit_p(uint16_T rtu_0,
  DW_SPITransmit_PMSM_to_BLDC_f_T *localDW)
{
  uint16_T status;

  /* MATLABSystem: '<S49>/SPI Transmit' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    LL_GPIO_ResetOutputPin(GPIOC, 16384U);
    MW_SPI_Write_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0, 1U, 1, 1, 1U);
  }

  /* End of MATLABSystem: '<S49>/SPI Transmit' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC_SPITransmit_a_Term(DW_SPITransmit_PMSM_to_BLDC_f_T *localDW)
{
  /* Terminate for MATLABSystem: '<S49>/SPI Transmit' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S49>/SPI Transmit' */
}

/*
 * Output and update for action system:
 *    '<S199>/If Action Subsystem'
 *    '<S225>/If Action Subsystem'
 */
void PMSM_to_BLDC__IfActionSubsystem(real_T rtu_In1, real_T *rty_Out1)
{
  real_T tmp;

  /* DataTypeConversion: '<S202>/Convert_uint16' */
  tmp = floor(rtu_In1);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* Sum: '<S202>/Sum' incorporates:
   *  DataTypeConversion: '<S202>/Convert_back'
   *  DataTypeConversion: '<S202>/Convert_uint16'
   */
  *rty_Out1 = rtu_In1 - (real_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);
}

/*
 * Output and update for action system:
 *    '<S199>/If Action Subsystem1'
 *    '<S225>/If Action Subsystem1'
 */
void PMSM_to_BLDC_IfActionSubsystem1(real_T rtu_In1, real_T *rty_Out1)
{
  real_T tmp;

  /* DataTypeConversion: '<S203>/Convert_uint16' */
  tmp = trunc(rtu_In1);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* Sum: '<S203>/Sum' incorporates:
   *  DataTypeConversion: '<S203>/Convert_back'
   *  DataTypeConversion: '<S203>/Convert_uint16'
   */
  *rty_Out1 = rtu_In1 - (real_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      real_T q;
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

static void PMSM_to_BL_SystemCore_setup_oxg(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S23>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S23>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S23>/SPI Receive' */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 16.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
  obj->isSetupComplete = true;
}

static void PMSM_to_SPIDrvBlock_setupImpl_o(stm32cube_blocks_SPIControl_d_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;

  /* Start for MATLABSystem: '<S23>/SPI Transmit' incorporates:
   *  MATLABSystem: '<S24>/SPI Transmit'
   */
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S23>/SPI Transmit' incorporates:
   *  MATLABSystem: '<S24>/SPI Transmit'
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

  /* Start for MATLABSystem: '<S23>/SPI Transmit' incorporates:
   *  MATLABSystem: '<S24>/SPI Transmit'
   */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 1.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
}

static void PMSM_to_B_SystemCore_setup_oxgk(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S24>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S24>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S24>/SPI Receive' */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 1.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
  obj->isSetupComplete = true;
}

static void PMSM_to_BLDC_SystemCore_setup_o(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S16>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S16>/Analog to Digital Converter' */
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

static void PMSM_to_BLD_SystemCore_setup_ox(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S19>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S19>/Analog to Digital Converter' */
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

static void PMSM_to_BLD_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_PM_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S459>/PWM Output' */
  b.PeripheralPtr = TIM8;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S459>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S459>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void PMSM_to__SystemCore_setup_oxgkf(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S462>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S462>/Analog to Digital Converter' */
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
void PMSM_to_BLDC_mod1_step(void)
{
  /* local block i/o variables */
  real_T rtb_Add1[2];
  real_T rtb_Add1_e;
  real_T rtb_Switch2;
  real_T rtb_Add1_d;
  real_T rtb_Switch;
  real_T rtb_Switch_e;
  real_T rtb_Gain3_c;
  real32_T rtb_SpeedGain;
  real_T rtb_PhaseCurrent[2];
  GPIO_TypeDef * portNameLoc;
  TIM_TypeDef * timModule;
  uint32_T channelEnum;
  real_T rtb_CCR[6];
  real_T rtb_Add1_f;
  real_T rtb_Add3;
  real_T rtb_Gain4_g;
  real_T rtb_Gain4_i_tmp;
  real_T rtb_Gain_e;
  real_T rtb_Integrator_l;
  real_T rtb_Product1_o;
  real_T rtb_Product2_a;
  real_T rtb_Saturation2_idx_0;
  real_T rtb_Saturation_k;
  real_T rtb_Sum1_eq;
  real_T rtb_Sum4;
  real_T tmp_4;
  int32_T i;
  real32_T rtb_PositionGain;
  real32_T rtb_indexing;
  uint32_T C1_DC;
  uint32_T pinMask;
  uint16_T tmp[16];
  uint16_T status;
  uint16_T y_nb;
  int8_T rtAction;
  int8_T rtPrevAction;
  boolean_T guard1;
  boolean_T tmp_0;
  boolean_T tmp_1;
  boolean_T tmp_2;
  boolean_T tmp_3;
  if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&PMSM_to_BLDC_mod1_M->solverInfo,
                          ((PMSM_to_BLDC_mod1_M->Timing.clockTick0+1)*
      PMSM_to_BLDC_mod1_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(PMSM_to_BLDC_mod1_M)) {
    PMSM_to_BLDC_mod1_M->Timing.t[0] = rtsiGetT(&PMSM_to_BLDC_mod1_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_g);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_c);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_n);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_f);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Status_Reg1_read_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC
    (PMSM_to_BLDC_mod1_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Dir_Sense_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Subsystem2_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Subsystem3_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.IfActionSubsystem_SubsysRanBC_b);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.IntegralMethod_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.OptimizedDifferentiationMethod_);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.IfActionSubsystem_SubsysRanBC_a);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.IfActionSubsystem1_SubsysRanB_e);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.IfActionSubsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Timer_SubsysRanBC);
  if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
      PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Delay: '<Root>/Delay3' */
    PMSM_to_BLDC_mod1_B.Delay3 = PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_d;
  }

  tmp_0 = (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
           PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] == 0);
  if (tmp_0) {
    /* Delay: '<Root>/Delay' */
    PMSM_to_BLDC_mod1_B.Delay = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_cn;

    /* Delay: '<Root>/Delay1' */
    PMSM_to_BLDC_mod1_B.Delay1 = PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fv;
  }

  /* Outputs for Enabled SubSystem: '<Root>/Timer' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  tmp_1 = (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
           PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[3] == 0);

  /* End of Outputs for SubSystem: '<Root>/Timer' */
  if (tmp_1) {
    /* Chart: '<Root>/Chart' */
    if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 < 32767) {
      PMSM_to_BLDC_mod1_DW.temporalCounter_i1++;
    }

    if (PMSM_to_BLDC_mod1_DW.temporalCounter_i2 < 8191) {
      PMSM_to_BLDC_mod1_DW.temporalCounter_i2++;
    }

    if (PMSM_to_BLDC_mod1_DW.is_active_c3_PMSM_to_BLDC_mod1 == 0) {
      PMSM_to_BLDC_mod1_DW.is_active_c3_PMSM_to_BLDC_mod1 = 1U;
      PMSM_to_BLDC_mod1_DW.is_active_Test2 = 1U;
      PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
      PMSM_to_BLDC_mod1_DW.is_Test2 = PMSM_to_BLDC_mod1_IN_Dummy;
      PMSM_to_BLDC_mod1_DW.Drv_ok = 0.0;
      PMSM_to_BLDC_mod1_DW.is_active_Test = 1U;
      PMSM_to_BLDC_mod1_DW.temporalCounter_i2 = 0U;
      PMSM_to_BLDC_mod1_DW.is_Test = PMSM_to_BLDC__IN_Initialization;
      PMSM_to_BLDC_mod1_DW.CS_val = 1.0;
      PMSM_to_BLDC_mod1_B.En_State = 0.0;
    } else {
      switch (PMSM_to_BLDC_mod1_DW.is_Test2) {
       case PMSM_to_BLDC_mod1_IN_Dummy:
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 20000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test2 = PMSM_to_BLDC_mod1_IN_SPI_write;
          PMSM_to_BLDC_mod1_B.spi_write1 = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write:
        PMSM_to_BLDC_mod1_B.spi_write1 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test2 = PMSM_to_BLDC_mod1_IN_SPI_write2;
          PMSM_to_BLDC_mod1_B.spi_write1 = 0.0;
        }
        break;

       case PMSM_to_BLDC_mod_IN_SPI_write10:
        PMSM_to_BLDC_mod1_B.spi_write4 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test2 = PMSM_to_BLDC_mod1_IN_SPI_write;
          PMSM_to_BLDC_mod1_B.spi_write1 = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write2:
        PMSM_to_BLDC_mod1_B.spi_write1 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test2 = PMSM_to_BLDC_mod1_IN_SPI_write5;
          PMSM_to_BLDC_mod1_B.spi_write2 = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write5:
        PMSM_to_BLDC_mod1_B.spi_write2 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test2 = PMSM_to_BLDC_mod1_IN_SPI_write6;
          PMSM_to_BLDC_mod1_B.spi_write2 = 0.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write6:
        PMSM_to_BLDC_mod1_B.spi_write2 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test2 = PMSM_to_BLDC_mod1_IN_SPI_write7;
          PMSM_to_BLDC_mod1_B.spi_write3 = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write7:
        PMSM_to_BLDC_mod1_B.spi_write3 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test2 = PMSM_to_BLDC_mod1_IN_SPI_write8;
          PMSM_to_BLDC_mod1_B.spi_write3 = 0.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write8:
        PMSM_to_BLDC_mod1_B.spi_write3 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test2 = PMSM_to_BLDC_mod1_IN_SPI_write9;
          PMSM_to_BLDC_mod1_B.spi_write4 = 1.0;
        }
        break;

       default:
        /* case IN_SPI_write9: */
        PMSM_to_BLDC_mod1_B.spi_write4 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test2 = PMSM_to_BLDC_mod_IN_SPI_write10;
          PMSM_to_BLDC_mod1_B.spi_write4 = 0.0;
          PMSM_to_BLDC_mod1_DW.Drv_ok = 1.0;
        }
        break;
      }

      switch (PMSM_to_BLDC_mod1_DW.is_Test) {
       case PMSM_to_BLDC_m_IN_Current_sense:
        PMSM_to_BLDC_mod1_B.Ib_flag = 1.0;
        PMSM_to_BLDC_mod1_B.Ic_flag = 1.0;
        PMSM_to_BLDC_mod1_B.FOC_flag = 1.0;
        break;

       case PMSM_to_BLDC_mod1_IN_En_Gate:
        PMSM_to_BLDC_mod1_B.En_State = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i2 >= 4000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i2 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test = PMSM_to_BLDC_mod1_IN_SPI_init1;
          PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 1.0;
        }
        break;

       case PMSM_to_BLDC__IN_Initialization:
        PMSM_to_BLDC_mod1_B.En_State = 0.0;
        if ((PMSM_to_BLDC_mod1_DW.CS_val == 1.0) &&
            (PMSM_to_BLDC_mod1_DW.temporalCounter_i2 >= 40)) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i2 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test = PMSM_to_BLDC_mod1_IN_En_Gate;
          PMSM_to_BLDC_mod1_B.En_State = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_init1:
        PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i2 >= 5000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i2 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test = PMSM_to_BLDC_mod1_IN_SPI_init2;
          PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 0.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_init2:
        PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i2 >= 1000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i2 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test = PMSM_to_BLDC_mod1_IN_SPI_init3;
          PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_init3:
        PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i2 >= 3000) {
          PMSM_to_BLDC_mod1_DW.is_Test = PMSM_to_BLDC_mod1_IN_SPI_init4;
          PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 0.0;
        }
        break;

       default:
        /* case IN_SPI_init4: */
        PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.Drv_ok == 1.0) {
          PMSM_to_BLDC_mod1_DW.is_Test = PMSM_to_BLDC_m_IN_Current_sense;
          PMSM_to_BLDC_mod1_B.Ib_flag = 1.0;
          PMSM_to_BLDC_mod1_B.Ic_flag = 1.0;
          PMSM_to_BLDC_mod1_B.FOC_flag = 1.0;
        }
        break;
      }
    }

    /* End of Chart: '<Root>/Chart' */
  }

  if (tmp_0) {
    /* Outputs for Atomic SubSystem: '<Root>/SPI_Write' */
    /* Logic: '<S5>/AND1' */
    PMSM_to_BLDC_mod1_B.AND1 = ((PMSM_to_BLDC_mod1_B.En_State != 0.0) &&
      (PMSM_to_BLDC_mod1_B.Ctrl_flag2 != 0.0));

    /* Outputs for Enabled SubSystem: '<S5>/Control_Reg2' incorporates:
     *  EnablePort: '<S23>/Enable'
     */
    if (PMSM_to_BLDC_mod1_B.AND1) {
      if (!PMSM_to_BLDC_mod1_DW.Control_Reg2_MODE) {
        /* SystemReset for Atomic SubSystem: '<S23>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift);

        /* End of SystemReset for SubSystem: '<S23>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S23>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1);

        /* End of SystemReset for SubSystem: '<S23>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Control_Reg2_MODE = true;
      }

      /* MATLABSystem: '<S23>/SPI Receive' */
      status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_g.MW_SPI_HANDLE,
        2U, 3840U, MW_SPI_MODE_3);
      if (status == 0) {
        MW_SPI_Read_Databits(PMSM_to_BLDC_mod1_DW.obj_g.MW_SPI_HANDLE, &tmp[0],
                             16U, 1, 1, 1U);
        LL_GPIO_SetOutputPin(GPIOC, 16384U);
      }

      /* End of MATLABSystem: '<S23>/SPI Receive' */

      /* Outputs for Atomic SubSystem: '<S23>/Bit Shift' */
      /* Constant: '<S23>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(0, &status, &PMSM_to_BLDC_mod1_DW.BitShift);

      /* End of Outputs for SubSystem: '<S23>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S23>/Bit Shift1' */
      /* Constant: '<S23>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(3, &y_nb, &PMSM_to_BLDC_mod1_DW.BitShift1);

      /* End of Outputs for SubSystem: '<S23>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S23>/Bitwise OR' */
      PMSM_to_BLDC_mod1_B.BitwiseOR_n = (uint16_T)(status | y_nb |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_jx);

      /* DataTypeConversion: '<S23>/Data Type Conversion' */
      PMSM_to_BLDC_mod1_B.DataTypeConversion_m = PMSM_to_BLDC_mod1_B.BitwiseOR_n;

      /* MATLABSystem: '<S23>/SPI Transmit' */
      status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE,
        2U, 3840U, MW_SPI_MODE_3);
      if (status == 0) {
        LL_GPIO_ResetOutputPin(GPIOC, 16384U);
        MW_SPI_Write_Databits(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE,
                              &PMSM_to_BLDC_mod1_B.DataTypeConversion_m, 1U, 1,
                              1, 1000U);
      }

      /* End of MATLABSystem: '<S23>/SPI Transmit' */
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC);
    } else {
      PMSM_to_BLDC_mod1_DW.Control_Reg2_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S5>/Control_Reg2' */

    /* Logic: '<S5>/AND' */
    PMSM_to_BLDC_mod1_B.AND = ((PMSM_to_BLDC_mod1_B.En_State != 0.0) &&
      (PMSM_to_BLDC_mod1_B.Ctrl_flag1 != 0.0));

    /* Outputs for Enabled SubSystem: '<S5>/Ctrl_Reg_1' incorporates:
     *  EnablePort: '<S24>/Enable'
     */
    if (PMSM_to_BLDC_mod1_B.AND) {
      if (!PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_MODE) {
        /* SystemReset for Atomic SubSystem: '<S24>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_h);

        /* End of SystemReset for SubSystem: '<S24>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S24>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_d);

        /* End of SystemReset for SubSystem: '<S24>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_MODE = true;
      }

      /* Outputs for Atomic SubSystem: '<S24>/Bit Shift' */
      /* Constant: '<S24>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(0, &status, &PMSM_to_BLDC_mod1_DW.BitShift_h);

      /* End of Outputs for SubSystem: '<S24>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S24>/Bit Shift1' */
      /* Constant: '<S24>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(2, &y_nb, &PMSM_to_BLDC_mod1_DW.BitShift1_d);

      /* End of Outputs for SubSystem: '<S24>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S24>/Bitwise OR' */
      PMSM_to_BLDC_mod1_B.BitwiseOR_e = (uint16_T)(status | y_nb |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_e);

      /* MATLABSystem: '<S24>/SPI Transmit' */
      status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_n.MW_SPI_HANDLE,
        2U, 3840U, MW_SPI_MODE_3);
      if (status == 0) {
        LL_GPIO_ResetOutputPin(GPIOC, 16384U);
        MW_SPI_Write_Databits(PMSM_to_BLDC_mod1_DW.obj_n.MW_SPI_HANDLE,
                              &PMSM_to_BLDC_mod1_B.BitwiseOR_e, 1U, 1, 1, 10U);
      }

      /* End of MATLABSystem: '<S24>/SPI Transmit' */
      /* MATLABSystem: '<S24>/SPI Receive' */
      status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, 2U,
        3840U, MW_SPI_MODE_3);
      if (status == 0) {
        MW_SPI_Read_Databits(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, &status, 1U,
                             1, 1, 1U);
        LL_GPIO_SetOutputPin(GPIOC, 16384U);
      }

      /* End of MATLABSystem: '<S24>/SPI Receive' */
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC);
    } else {
      PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S5>/Ctrl_Reg_1' */
  }

  if (tmp_1) {
    /* Outputs for Enabled SubSystem: '<S7>/Status_Reg1_read' incorporates:
     *  EnablePort: '<S49>/Ctrl_flag1'
     */
    /* Outputs for Enabled SubSystem: '<S7>/Status_Reg_2_read' incorporates:
     *  EnablePort: '<S50>/Ctrl_flag2'
     */
    tmp_2 = rtsiIsModeUpdateTimeStep(&PMSM_to_BLDC_mod1_M->solverInfo);

    /* End of Outputs for SubSystem: '<S7>/Status_Reg1_read' */
    if (tmp_2) {
      if (PMSM_to_BLDC_mod1_B.spi_write2 > 0.0) {
        if (!PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_MODE) {
          /* SystemReset for Atomic SubSystem: '<S50>/Bit Shift' */
          PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_n);

          /* End of SystemReset for SubSystem: '<S50>/Bit Shift' */

          /* SystemReset for Atomic SubSystem: '<S50>/Bit Shift1' */
          PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_o);

          /* End of SystemReset for SubSystem: '<S50>/Bit Shift1' */
          PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_MODE = true;
        }
      } else if (PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_MODE) {
        for (i = 0; i < 15; i++) {
          /* Disable for MATLABSystem: '<S50>/SPI Receive' incorporates:
           *  Outport: '<S50>/Out1'
           */
          PMSM_to_BLDC_mod1_B.SPIReceive_pnaevv.SPIReceive[i] = 0U;
        }

        PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_MODE = false;
      }
    }

    if (PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_MODE) {
      PMSM_to_BLDC_mod1_SPIReceive_pn(&PMSM_to_BLDC_mod1_B.SPIReceive_pnaevv,
        &PMSM_to_BLDC_mod1_DW.SPIReceive_pnaevv);

      /* Outputs for Atomic SubSystem: '<S50>/Bit Shift' */
      /* Constant: '<S50>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(1, &status, &PMSM_to_BLDC_mod1_DW.BitShift_n);

      /* End of Outputs for SubSystem: '<S50>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S50>/Bit Shift1' */
      /* Constant: '<S50>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(1, &y_nb, &PMSM_to_BLDC_mod1_DW.BitShift1_o);

      /* End of Outputs for SubSystem: '<S50>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S50>/Bitwise OR' */
      PMSM_to_BLDC_mod1_B.BitwiseOR = (uint16_T)(status | y_nb |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND);
      PMSM_to_BLDC_mod1_SPITransmit_p(PMSM_to_BLDC_mod1_B.BitwiseOR,
        &PMSM_to_BLDC_mod1_DW.SPITransmit_pnaevv);
      if (tmp_2) {
        srUpdateBC(PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S7>/Status_Reg_2_read' */

    /* Outputs for Enabled SubSystem: '<S7>/Status_Reg1_read' incorporates:
     *  EnablePort: '<S49>/Ctrl_flag1'
     */
    if (tmp_2) {
      if (PMSM_to_BLDC_mod1_B.spi_write1 > 0.0) {
        if (!PMSM_to_BLDC_mod1_DW.Status_Reg1_read_MODE) {
          /* SystemReset for Atomic SubSystem: '<S49>/Bit Shift' */
          PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_p);

          /* End of SystemReset for SubSystem: '<S49>/Bit Shift' */

          /* SystemReset for Atomic SubSystem: '<S49>/Bit Shift1' */
          PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_j);

          /* End of SystemReset for SubSystem: '<S49>/Bit Shift1' */
          PMSM_to_BLDC_mod1_DW.Status_Reg1_read_MODE = true;
        }
      } else if (PMSM_to_BLDC_mod1_DW.Status_Reg1_read_MODE) {
        /* Disable for Outport: '<S49>/Out1' incorporates:
         *  MATLABSystem: '<S49>/SPI Receive'
         */
        for (i = 0; i < 15; i++) {
          PMSM_to_BLDC_mod1_B.SPIReceive_pnaev.SPIReceive[i] = 0U;
        }

        /* End of Disable for Outport: '<S49>/Out1' */
        PMSM_to_BLDC_mod1_DW.Status_Reg1_read_MODE = false;
      }
    }

    if (PMSM_to_BLDC_mod1_DW.Status_Reg1_read_MODE) {
      PMSM_to_BLDC_mod1_SPIReceive_pn(&PMSM_to_BLDC_mod1_B.SPIReceive_pnaev,
        &PMSM_to_BLDC_mod1_DW.SPIReceive_pnaev);

      /* Outputs for Atomic SubSystem: '<S49>/Bit Shift' */
      /* Constant: '<S49>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(1, &status, &PMSM_to_BLDC_mod1_DW.BitShift_p);

      /* End of Outputs for SubSystem: '<S49>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S49>/Bit Shift1' */
      /* Constant: '<S49>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(0, &y_nb, &PMSM_to_BLDC_mod1_DW.BitShift1_j);

      /* End of Outputs for SubSystem: '<S49>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S49>/Bitwise OR' */
      PMSM_to_BLDC_mod1_B.BitwiseOR_p = (uint16_T)(status | y_nb |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_m);

      /* DataTypeConversion: '<S49>/Data Type Conversion' */
      PMSM_to_BLDC_mod1_B.DataTypeConversion_d = PMSM_to_BLDC_mod1_B.BitwiseOR_p;
      PMSM_to_BLDC_mod1_SPITransmit_p(PMSM_to_BLDC_mod1_B.DataTypeConversion_d,
        &PMSM_to_BLDC_mod1_DW.SPITransmit_pnaev);
      if (tmp_2) {
        srUpdateBC(PMSM_to_BLDC_mod1_DW.Status_Reg1_read_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S7>/Status_Reg1_read' */
  }

  if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
      PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[5] == 0) {
  }

  /* Outputs for Atomic SubSystem: '<Root>/Current_sensing' */
  /* Outputs for Enabled SubSystem: '<S2>/Subsystem1' incorporates:
   *  EnablePort: '<S13>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S2>/Subsystem' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  tmp_2 = (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
           PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[3] == 0);

  /* End of Outputs for SubSystem: '<S2>/Subsystem1' */
  if (tmp_2) {
    PMSM_to_BLDC_mod1_DW.Subsystem_MODE_n = (PMSM_to_BLDC_mod1_B.Ib_flag > 0.0);
  }

  if (PMSM_to_BLDC_mod1_DW.Subsystem_MODE_n) {
    if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
        PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] == 0) {
      /* MATLABSystem: '<S16>/Analog to Digital Converter' */
      if (PMSM_to_BLDC_mod1_DW.obj_d.TunablePropsChanged) {
        PMSM_to_BLDC_mod1_DW.obj_d.TunablePropsChanged = false;
      }

      regularReadADCNormal(PMSM_to_BLDC_mod1_DW.obj_d.ADCHandle,
                           ADC_TRIGGER_AND_READ, &status);

      /* Gain: '<S12>/Gain' incorporates:
       *  DataTypeConversion: '<S12>/Data Type Conversion'
       *  MATLABSystem: '<S16>/Analog to Digital Converter'
       */
      PMSM_to_BLDC_mod1_B.Gain_k = 0.02442002442002442 * (real_T)status;
    }

    srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_g);
  }

  /* End of Outputs for SubSystem: '<S2>/Subsystem' */

  /* Outputs for Enabled SubSystem: '<S2>/Subsystem1' incorporates:
   *  EnablePort: '<S13>/Enable'
   */
  if (tmp_2) {
    PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_b = (PMSM_to_BLDC_mod1_B.Ic_flag > 0.0);
  }

  if (PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_b) {
    if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
        PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] == 0) {
      /* MATLABSystem: '<S19>/Analog to Digital Converter' */
      if (PMSM_to_BLDC_mod1_DW.obj_o.TunablePropsChanged) {
        PMSM_to_BLDC_mod1_DW.obj_o.TunablePropsChanged = false;
      }

      regularReadADCNormal(PMSM_to_BLDC_mod1_DW.obj_o.ADCHandle,
                           ADC_TRIGGER_AND_READ, &status);

      /* Gain: '<S13>/Gain1' incorporates:
       *  DataTypeConversion: '<S13>/Data Type Conversion1'
       *  MATLABSystem: '<S19>/Analog to Digital Converter'
       */
      PMSM_to_BLDC_mod1_B.Gain1_m = 0.02442002442002442 * (real_T)status;
    }

    srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_c);
  }

  /* End of Outputs for SubSystem: '<S2>/Subsystem1' */
  /* End of Outputs for SubSystem: '<Root>/Current_sensing' */
  if (tmp_0) {
    /* SignalConversion generated from: '<Root>/Delay2' */
    rtb_PhaseCurrent[0] = PMSM_to_BLDC_mod1_B.Gain_k;
    rtb_PhaseCurrent[1] = PMSM_to_BLDC_mod1_B.Gain1_m;

    /* Delay: '<Root>/Delay2' */
    PMSM_to_BLDC_mod1_B.Delay2[0] = PMSM_to_BLDC_mod1_DW.Delay2_DSTATE;
    PMSM_to_BLDC_mod1_B.Delay2[1] = rtb_PhaseCurrent[0];

    /* Outputs for Atomic SubSystem: '<Root>/SPI_read' */
    /* Outputs for Enabled SubSystem: '<S35>/Subsystem1' incorporates:
     *  EnablePort: '<S38>/Ctrl_flag2'
     */
    /* SignalConversion generated from: '<S38>/Ctrl_flag2' incorporates:
     *  Constant: '<S38>/Constant'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write2 > 0.0) {
      PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_m = true;
      PMSM_to_BLDC_mod1_SPIReceive_p(&PMSM_to_BLDC_mod1_B.SPIReceive_pn,
        &PMSM_to_BLDC_mod1_DW.SPIReceive_pn);
      PMSM_to_BLDC_mod1_SPITransmit(36864, &PMSM_to_BLDC_mod1_DW.SPITransmit_pn);
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_n);
    } else if (PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_m) {
      /* Disable for Outport: '<S38>/Out1' incorporates:
       *  MATLABSystem: '<S38>/SPI Receive'
       */
      PMSM_to_BLDC_mod1_B.SPIReceive_pn.SPIReceive = 0U;
      PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_m = false;
    }

    /* End of SignalConversion generated from: '<S38>/Ctrl_flag2' */
    /* End of Outputs for SubSystem: '<S35>/Subsystem1' */

    /* Outputs for Enabled SubSystem: '<S36>/Subsystem1' incorporates:
     *  EnablePort: '<S44>/Enable'
     */
    /* SignalConversion generated from: '<S44>/Enable' incorporates:
     *  Constant: '<S44>/Constant'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write4 > 0.0) {
      PMSM_to_BLDC_mod1_DW.Subsystem1_MODE = true;
      PMSM_to_BLDC_mod1_SPIReceive_p(&PMSM_to_BLDC_mod1_B.SPIReceive_pnae,
        &PMSM_to_BLDC_mod1_DW.SPIReceive_pnae);
      PMSM_to_BLDC_mod1_SPITransmit(38912,
        &PMSM_to_BLDC_mod1_DW.SPITransmit_pnae);
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC);
    } else if (PMSM_to_BLDC_mod1_DW.Subsystem1_MODE) {
      /* Disable for MATLABSystem: '<S44>/SPI Receive' incorporates:
       *  Outport: '<S44>/Out1'
       */
      PMSM_to_BLDC_mod1_B.SPIReceive_pnae.SPIReceive = 0U;
      PMSM_to_BLDC_mod1_DW.Subsystem1_MODE = false;
    }

    /* End of SignalConversion generated from: '<S44>/Enable' */
    /* End of Outputs for SubSystem: '<S36>/Subsystem1' */
    /* RelationalOperator: '<S34>/Compare' incorporates:
     *  Constant: '<S34>/Constant'
     */
    PMSM_to_BLDC_mod1_B.Compare_a =
      (PMSM_to_BLDC_mod1_B.SPIReceive_pnae.SPIReceive == 6148);

    /* RelationalOperator: '<S33>/Compare' incorporates:
     *  Constant: '<S33>/Constant'
     */
    PMSM_to_BLDC_mod1_B.Compare_g =
      (PMSM_to_BLDC_mod1_B.SPIReceive_pn.SPIReceive == 5456);

    /* Outputs for Enabled SubSystem: '<S35>/Subsystem' incorporates:
     *  EnablePort: '<S37>/Enable'
     */
    /* SignalConversion generated from: '<S37>/Enable' incorporates:
     *  Constant: '<S37>/Constant'
     *  Constant: '<S37>/Constant1'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write1 > 0.0) {
      if (!PMSM_to_BLDC_mod1_DW.Subsystem_MODE_f) {
        /* SystemReset for Atomic SubSystem: '<S37>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_hq);

        /* End of SystemReset for SubSystem: '<S37>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S37>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_p);

        /* End of SystemReset for SubSystem: '<S37>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Subsystem_MODE_f = true;
      }

      PMSM_to_BLDC_mod1_SPIReceive(&PMSM_to_BLDC_mod1_DW.SPIReceive_p);

      /* Outputs for Atomic SubSystem: '<S37>/Bit Shift' */
      PMSM_to_BLDC_mod1_BitShift(1, &status, &PMSM_to_BLDC_mod1_DW.BitShift_hq);

      /* End of Outputs for SubSystem: '<S37>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S37>/Bit Shift1' */
      PMSM_to_BLDC_mod1_BitShift1(2, &y_nb, &PMSM_to_BLDC_mod1_DW.BitShift1_p);

      /* End of Outputs for SubSystem: '<S37>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S37>/Bitwise OR' incorporates:
       *  Constant: '<S37>/Constant'
       *  Constant: '<S37>/Constant1'
       */
      PMSM_to_BLDC_mod1_B.BitwiseOR_h = (uint16_T)(status | y_nb |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_d);
      PMSM_to_BLDC_mod1_SPITransmit(PMSM_to_BLDC_mod1_B.BitwiseOR_h,
        &PMSM_to_BLDC_mod1_DW.SPITransmit_p);
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i);
    } else {
      PMSM_to_BLDC_mod1_DW.Subsystem_MODE_f = false;
    }

    /* End of SignalConversion generated from: '<S37>/Enable' */
    /* End of Outputs for SubSystem: '<S35>/Subsystem' */

    /* Outputs for Enabled SubSystem: '<S36>/Subsystem' incorporates:
     *  EnablePort: '<S43>/Enable'
     */
    /* SignalConversion generated from: '<S43>/Enable' incorporates:
     *  Constant: '<S43>/Constant'
     *  Constant: '<S43>/Constant1'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write3 > 0.0) {
      if (!PMSM_to_BLDC_mod1_DW.Subsystem_MODE) {
        /* SystemReset for Atomic SubSystem: '<S43>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_b);

        /* End of SystemReset for SubSystem: '<S43>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S43>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_m);

        /* End of SystemReset for SubSystem: '<S43>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Subsystem_MODE = true;
      }

      PMSM_to_BLDC_mod1_SPIReceive(&PMSM_to_BLDC_mod1_DW.SPIReceive_pna);

      /* Outputs for Atomic SubSystem: '<S43>/Bit Shift' */
      PMSM_to_BLDC_mod1_BitShift(1, &status, &PMSM_to_BLDC_mod1_DW.BitShift_b);

      /* End of Outputs for SubSystem: '<S43>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S43>/Bit Shift1' */
      PMSM_to_BLDC_mod1_BitShift1(3, &y_nb, &PMSM_to_BLDC_mod1_DW.BitShift1_m);

      /* End of Outputs for SubSystem: '<S43>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S43>/Bitwise OR' incorporates:
       *  Constant: '<S43>/Constant'
       *  Constant: '<S43>/Constant1'
       */
      PMSM_to_BLDC_mod1_B.BitwiseOR_o = (uint16_T)(status | y_nb |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_j);
      PMSM_to_BLDC_mod1_SPITransmit(PMSM_to_BLDC_mod1_B.BitwiseOR_o,
        &PMSM_to_BLDC_mod1_DW.SPITransmit_pna);
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_f);
    } else {
      PMSM_to_BLDC_mod1_DW.Subsystem_MODE = false;
    }

    /* End of SignalConversion generated from: '<S43>/Enable' */
    /* End of Outputs for SubSystem: '<S36>/Subsystem' */
    /* End of Outputs for SubSystem: '<Root>/SPI_read' */
  }

  /* Outputs for Enabled SubSystem: '<Root>/Timer' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (tmp_1 && rtsiIsModeUpdateTimeStep(&PMSM_to_BLDC_mod1_M->solverInfo)) {
    if (PMSM_to_BLDC_mod1_B.FOC_flag > 0.0) {
      if (!PMSM_to_BLDC_mod1_DW.Timer_MODE) {
        (void) memset(&(PMSM_to_BLDC_mod1_XDis.Integrator_CSTATE), 0,
                      4*sizeof(boolean_T));

        /* InitializeConditions for Delay: '<S59>/Delay' */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[0] = 0.0;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[1] = 0.0;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[2] = 0.0;

        /* InitializeConditions for Delay: '<S235>/Delay1' */
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f = 0.0F;

        /* InitializeConditions for Delay: '<S62>/Delay' */
        memset(&PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[0], 0, sizeof(real_T) << 3U);

        /* InitializeConditions for Delay: '<S239>/Delay' */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0] = 0.0;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1] = 0.0;

        /* InitializeConditions for Delay: '<S252>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad = true;

        /* InitializeConditions for Delay: '<S335>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_f = true;

        /* InitializeConditions for Delay: '<S359>/Delay' */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj = 0.0;

        /* InitializeConditions for DiscreteIntegrator: '<S304>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE = 0.0;
        PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState = 0;

        /* InitializeConditions for Delay: '<S360>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_a = true;

        /* InitializeConditions for DiscreteIntegrator: '<S174>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b =
          PMSM_to_BLDC_mod1_ConstB.Constant3_n;
        PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState_n = 0;

        /* InitializeConditions for Delay: '<S59>/Delay1' */
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx = 0.0F;

        /* InitializeConditions for Integrator: '<S440>/Integrator' */
        PMSM_to_BLDC_mod1_X.Integrator_CSTATE = 0.0;

        /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n =
          PMSM_to_BLDC_mod1_ConstB.Constant3;
        PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState_nt = 0;

        /* InitializeConditions for Delay: '<S266>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_b = true;

        /* InitializeConditions for Integrator: '<S380>/Int1' */
        PMSM_to_BLDC_mod1_X.Int1_CSTATE = 0.0;

        /* InitializeConditions for Integrator: '<S395>/Integrator' incorporates:
         *  Integrator: '<S396>/Integrator'
         */
        if (rtmIsFirstInitCond(PMSM_to_BLDC_mod1_M)) {
          PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d = 0.0;
          PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l = 0.0;
        }

        PMSM_to_BLDC_mod1_DW.Integrator_DWORK1 = true;

        /* End of InitializeConditions for Integrator: '<S395>/Integrator' */

        /* InitializeConditions for Integrator: '<S396>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DWORK1_g = true;
        PMSM_to_BLDC_mod1_DW.Timer_MODE = true;
      }
    } else {
      if (((PMSM_to_BLDC_mod1_M->Timing.clockTick3) * 0.001) == rtmGetTStart
          (PMSM_to_BLDC_mod1_M)) {
        (void) memset(&(PMSM_to_BLDC_mod1_XDis.Integrator_CSTATE), 1,
                      4*sizeof(boolean_T));
      }

      if (PMSM_to_BLDC_mod1_DW.Timer_MODE) {
        (void) memset(&(PMSM_to_BLDC_mod1_XDis.Integrator_CSTATE), 1,
                      4*sizeof(boolean_T));

        /* Disable for If: '<S253>/If' */
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem = -1;

        /* Disable for SwitchCase: '<S262>/Switch Case' */
        PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem = -1;

        /* Disable for If: '<S259>/If' */
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&PMSM_to_BLDC_mod1_M->solverInfo, true);
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_g = -1;

        /* Disable for SwitchCase: '<S261>/Switch Case' */
        PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem_n = -1;

        /* Disable for If: '<S364>/If' */
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_e = -1;

        /* Disable for If: '<S225>/If' */
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_c = -1;

        /* Disable for If: '<S199>/If' */
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_m = -1;
        PMSM_to_BLDC_mod1_DW.Timer_MODE = false;
      }
    }
  }

  if (PMSM_to_BLDC_mod1_DW.Timer_MODE) {
    tmp_2 = (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
             PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0);
    if (tmp_2) {
      /* DataTypeConversion: '<S233>/Data Type  Conversion' incorporates:
       *  Delay: '<S59>/Delay'
       */
      PMSM_to_BLDC_mod1_B.DataTypeConversion[0] =
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[0];
      PMSM_to_BLDC_mod1_B.DataTypeConversion[1] =
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[1];
      PMSM_to_BLDC_mod1_B.DataTypeConversion[2] =
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[2];

      /* Gain: '<S79>/one_by_3' incorporates:
       *  Sum: '<S79>/Sum'
       */
      rtb_Gain_e = ((PMSM_to_BLDC_mod1_B.DataTypeConversion[0] +
                     PMSM_to_BLDC_mod1_B.DataTypeConversion[1]) +
                    PMSM_to_BLDC_mod1_B.DataTypeConversion[2]) *
        0.33333333333333331;

      /* Gain: '<S79>/Kalphabeta0' incorporates:
       *  Gain: '<S79>/one_by_sqrt3_'
       *  Sum: '<S79>/Sum1'
       *  Sum: '<S79>/Sum2'
       */
      PMSM_to_BLDC_mod1_B.Kalphabeta0[0] =
        PMSM_to_BLDC_mod1_B.DataTypeConversion[0] - rtb_Gain_e;
      PMSM_to_BLDC_mod1_B.Kalphabeta0[1] =
        (PMSM_to_BLDC_mod1_B.DataTypeConversion[1] -
         PMSM_to_BLDC_mod1_B.DataTypeConversion[2]) * 0.57735026918962584;
      PMSM_to_BLDC_mod1_B.Kalphabeta0[2] = rtb_Gain_e;

      /* Delay: '<S235>/Delay1' */
      if (PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE == POS_ZCSIG) {
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f = 0.0F;
      }

      PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE = 0U;

      /* Gain: '<S241>/Gain' incorporates:
       *  Delay: '<S235>/Delay1'
       */
      rtb_Add3 = -0.0017999999690800905 * PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f;

      /* Gain: '<S248>/Gain1' incorporates:
       *  Delay: '<S62>/Delay'
       */
      rtb_Sum1_eq = 555.55555555555554 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[1];

      /* Gain: '<S248>/Gain' incorporates:
       *  Delay: '<S62>/Delay'
       */
      rtb_Gain_e = 555.55555555555554 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[0];

      /* Sum: '<S249>/Sum' incorporates:
       *  Product: '<S249>/Product'
       *  Product: '<S249>/Product2'
       *  UnaryMinus: '<S249>/Unary Minus'
       */
      rtb_Add1_f = -rtb_Add3 * rtb_Sum1_eq - rtb_Gain_e;

      /* Sum: '<S249>/Sum1' incorporates:
       *  Product: '<S249>/Product1'
       *  Product: '<S249>/Product3'
       */
      rtb_Add3 = rtb_Gain_e * rtb_Add3 - rtb_Sum1_eq;

      /* Gain: '<S240>/Gain' incorporates:
       *  Delay: '<S235>/Delay1'
       */
      rtb_Gain_e = -0.0017999999690800905 * PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f;

      /* Sum: '<S245>/Sum1' incorporates:
       *  Delay: '<S62>/Delay'
       *  Product: '<S245>/Product3'
       */
      rtb_Sum1_eq = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[2] * rtb_Gain_e -
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[3];

      /* Product: '<S266>/Product1' incorporates:
       *  Delay: '<S62>/Delay'
       *  Product: '<S245>/Product2'
       *  Sum: '<S245>/Sum'
       *  UnaryMinus: '<S245>/Unary Minus'
       */
      rtb_Product1_o = -rtb_Gain_e * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[3] -
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[2];

      /* Gain: '<S243>/Gain1' */
      rtb_Saturation_k = 555.55555555555554 * rtb_Sum1_eq;

      /* Gain: '<S243>/Gain' */
      rtb_Gain4_i_tmp = 555.55555555555554 * rtb_Product1_o;

      /* Sum: '<S246>/Sum1' incorporates:
       *  Gain: '<S243>/Gain'
       *  Gain: '<S243>/Gain1'
       *  Product: '<S246>/Product3'
       *  UnaryMinus: '<S243>/Unary Minus'
       */
      rtb_Gain4_g = -rtb_Gain4_i_tmp * rtb_Gain_e + rtb_Saturation_k;

      /* Gain: '<S388>/Gain3' incorporates:
       *  Constant: '<S242>/(Ld-Lq)_Ld'
       *  Constant: '<S242>/R_Ld'
       *  Delay: '<S235>/Delay1'
       *  Delay: '<S62>/Delay'
       *  Product: '<S242>/Product'
       *  Product: '<S242>/Product3'
       *  Product: '<S242>/Product5'
       *  Sum: '<S242>/Sum1'
       *  UnaryMinus: '<S242>/Unary Minus1'
       */
      rtb_Gain3_c = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[3] * -20.555555555555554;
      rtb_Gain3_c += PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[2] *
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f * 0.0;

      /* Product: '<S247>/Product2' incorporates:
       *  UnaryMinus: '<S247>/Unary Minus'
       */
      rtb_Product2_a = -rtb_Gain_e * rtb_Gain3_c;

      /* Sum: '<S242>/Sum' incorporates:
       *  Constant: '<S242>/(Ld-Lq)_Ld'
       *  Constant: '<S242>/R_Ld'
       *  Delay: '<S235>/Delay1'
       *  Delay: '<S62>/Delay'
       *  Product: '<S242>/Product1'
       *  Product: '<S242>/Product2'
       *  Product: '<S242>/Product4'
       *  UnaryMinus: '<S242>/Unary Minus'
       *  UnaryMinus: '<S242>/Unary Minus1'
       */
      rtb_Integrator_l = -(PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[3] *
                           PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f) * 0.0 +
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[2] * -20.555555555555554;

      /* Gain: '<S388>/Gain3' incorporates:
       *  Product: '<S247>/Product1'
       *  Product: '<S247>/Product3'
       *  Sum: '<S247>/Sum1'
       */
      rtb_Gain3_c = rtb_Integrator_l * rtb_Gain_e - rtb_Gain3_c;

      /* Delay: '<S239>/Delay' */
      if (PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE == POS_ZCSIG) {
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0] = 0.0;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1] = 0.0;
      }

      PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE = 0U;

      /* Sum: '<S239>/Sum2' incorporates:
       *  Delay: '<S239>/Delay'
       *  Sum: '<S239>/Sum'
       */
      rtb_Saturation2_idx_0 = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0];
      tmp_4 = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1];

      /* Gain: '<S239>/Gain2' incorporates:
       *  Delay: '<S235>/Delay1'
       *  Delay: '<S239>/Delay'
       *  Gain: '<S239>/Gain1'
       *  Product: '<S244>/Product'
       *  Product: '<S244>/Product1'
       *  Product: '<S246>/Product2'
       *  Product: '<S247>/Product'
       *  Sum: '<S239>/Sum'
       *  Sum: '<S239>/Sum2'
       *  Sum: '<S240>/Sum'
       *  Sum: '<S246>/Sum'
       *  Sum: '<S247>/Sum'
       *  UnaryMinus: '<S243>/Unary Minus1'
       *  UnaryMinus: '<S244>/Unary Minus'
       *  UnaryMinus: '<S246>/Unary Minus'
       */
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0] = ((((-(rtb_Sum1_eq *
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f) - (-rtb_Saturation_k * -rtb_Gain_e
        + rtb_Gain4_i_tmp)) - (rtb_Product2_a - rtb_Integrator_l)) - rtb_Add1_f)
        * 5.0E-5 + rtb_Saturation2_idx_0) * 0.972972972972973;
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1] = ((((rtb_Product1_o *
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f - rtb_Gain4_g) - rtb_Gain3_c) -
        rtb_Add3) * 5.0E-5 + tmp_4) * 0.972972972972973;

      /* Delay: '<S252>/Delay' incorporates:
       *  Constant: '<S237>/IC'
       */
      if (PMSM_to_BLDC_mod1_DW.icLoad) {
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[0] = 0.0;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[1] = 0.0;
      }

      /* Sum: '<S252>/Add1' incorporates:
       *  Constant: '<S235>/V_PU'
       *  Delay: '<S239>/Delay'
       *  Delay: '<S252>/Delay'
       *  Product: '<S235>/Product'
       *  Product: '<S252>/Product'
       *  Product: '<S252>/Product1'
       *  Sum: '<S239>/Sum1'
       */
      rtb_Add1[0] = (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0] + rtb_Product1_o) *
        0.020833333333333332 * 0.70204348915944692 +
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[0] * 0.29795651084055308;
      rtb_Add1[1] = (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1] + rtb_Sum1_eq) *
        0.020833333333333332 * 0.70204348915944692 + 0.29795651084055308 *
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[1];

      /* Relay: '<S253>/AlphaRelay' */
      PMSM_to_BLDC_mod1_DW.AlphaRelay_Mode = ((rtb_Add1[0] >= 0.02) ||
        ((!(rtb_Add1[0] <= -0.02)) && PMSM_to_BLDC_mod1_DW.AlphaRelay_Mode));

      /* Relay: '<S253>/BetaRelay' */
      PMSM_to_BLDC_mod1_DW.BetaRelay_Mode = ((rtb_Add1[1] >= 0.02) ||
        ((!(rtb_Add1[1] <= -0.02)) && PMSM_to_BLDC_mod1_DW.BetaRelay_Mode));

      /* Outputs for IfAction SubSystem: '<S262>/If Action Subsystem' incorporates:
       *  ActionPort: '<S356>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S262>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S357>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S253>/Subsystem2' incorporates:
       *  ActionPort: '<S256>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S253>/Subsystem3' incorporates:
       *  ActionPort: '<S257>/Action Port'
       */
      /* Outputs for Triggered SubSystem: '<S253>/Dir_Sense' incorporates:
       *  TriggerPort: '<S255>/Trigger'
       */
      /* If: '<S253>/If' incorporates:
       *  Relay: '<S253>/AlphaRelay'
       *  SwitchCase: '<S262>/Switch Case'
       */
      tmp_3 = rtsiIsModeUpdateTimeStep(&PMSM_to_BLDC_mod1_M->solverInfo);

      /* End of Outputs for SubSystem: '<S253>/Subsystem3' */
      /* End of Outputs for SubSystem: '<S253>/Subsystem2' */
      /* End of Outputs for SubSystem: '<S262>/If Action Subsystem1' */
      /* End of Outputs for SubSystem: '<S262>/If Action Subsystem' */
      if (tmp_3) {
        if (PMSM_to_BLDC_mod1_DW.AlphaRelay_Mode &&
            (PMSM_to_BLDC_mod1_PrevZCX.Dir_Sense_Trig_ZCE != POS_ZCSIG)) {
          /* Switch: '<S255>/Switch' incorporates:
           *  Relay: '<S253>/BetaRelay'
           */
          if (PMSM_to_BLDC_mod1_DW.BetaRelay_Mode) {
            /* Switch: '<S255>/Switch' incorporates:
             *  Constant: '<S255>/Constant'
             */
            PMSM_to_BLDC_mod1_B.Switch = -1;
          } else {
            /* Switch: '<S255>/Switch' incorporates:
             *  Constant: '<S255>/Constant1'
             */
            PMSM_to_BLDC_mod1_B.Switch = 1;
          }

          /* End of Switch: '<S255>/Switch' */
          PMSM_to_BLDC_mod1_DW.Dir_Sense_SubsysRanBC = 4;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Dir_Sense_Trig_ZCE =
          PMSM_to_BLDC_mod1_DW.AlphaRelay_Mode;
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem = (int8_T)
          (PMSM_to_BLDC_mod1_B.Switch <= 0);
      }

      /* End of Outputs for SubSystem: '<S253>/Dir_Sense' */
      guard1 = false;
      if (PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem == 0) {
        /* Outputs for IfAction SubSystem: '<S253>/Subsystem2' incorporates:
         *  ActionPort: '<S256>/Action Port'
         */
        /* UnaryMinus: '<S256>/Unary Minus' */
        rtb_Add1_f = -rtb_Add1[0];

        /* SignalConversion generated from: '<S256>/SigmaBeta' */
        rtb_Gain_e = rtb_Add1[1];

        /* End of Outputs for SubSystem: '<S253>/Subsystem2' */
        if (tmp_3) {
          /* Outputs for IfAction SubSystem: '<S253>/Subsystem2' incorporates:
           *  ActionPort: '<S256>/Action Port'
           */
          srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem2_SubsysRanBC);

          /* End of Outputs for SubSystem: '<S253>/Subsystem2' */
          guard1 = true;
        }
      } else {
        /* Outputs for IfAction SubSystem: '<S253>/Subsystem3' incorporates:
         *  ActionPort: '<S257>/Action Port'
         */
        /* UnaryMinus: '<S257>/Unary Minus' */
        rtb_Gain_e = -rtb_Add1[1];

        /* SignalConversion generated from: '<S257>/SigmaAlpha' */
        rtb_Add1_f = rtb_Add1[0];

        /* End of Outputs for SubSystem: '<S253>/Subsystem3' */
        if (tmp_3) {
          /* Outputs for IfAction SubSystem: '<S253>/Subsystem3' incorporates:
           *  ActionPort: '<S257>/Action Port'
           */
          srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem3_SubsysRanBC);

          /* End of Outputs for SubSystem: '<S253>/Subsystem3' */
          guard1 = true;
        }
      }

      if (guard1) {
        if ((int32_T)PMSM_to_BLDC_mod1_ConstB.DataTypeConversion == 1) {
          PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem = 0;
        } else {
          PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem = 1;
        }
      }

      /* End of If: '<S253>/If' */

      /* SwitchCase: '<S262>/Switch Case' */
      if (PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem == 0) {
        /* Outputs for IfAction SubSystem: '<S262>/If Action Subsystem' incorporates:
         *  ActionPort: '<S356>/Action Port'
         */
        /* Merge: '<S262>/Merge' incorporates:
         *  Constant: '<S262>/Constant'
         *  SignalConversion generated from: '<S356>/In1'
         *  SignalConversion generated from: '<S356>/Out1'
         */
        PMSM_to_BLDC_mod1_B.Merge[0] = 0.0;
        PMSM_to_BLDC_mod1_B.Merge[1] = 0.0;
        if (tmp_3) {
          srUpdateBC(PMSM_to_BLDC_mod1_DW.IfActionSubsystem_SubsysRanBC_a);
        }

        /* End of Outputs for SubSystem: '<S262>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S262>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S357>/Action Port'
         */
        /* Merge: '<S262>/Merge' incorporates:
         *  SignalConversion generated from: '<S357>/In1'
         */
        PMSM_to_BLDC_mod1_B.Merge[0] = rtb_Add1_f;
        PMSM_to_BLDC_mod1_B.Merge[1] = rtb_Gain_e;
        if (tmp_3) {
          srUpdateBC(PMSM_to_BLDC_mod1_DW.IfActionSubsystem1_SubsysRanB_e);
        }

        /* End of Outputs for SubSystem: '<S262>/If Action Subsystem1' */
      }

      /* Product: '<S259>/Product' */
      rtb_Gain_e = PMSM_to_BLDC_mod1_B.Merge[0] * PMSM_to_BLDC_mod1_B.Merge[0];

      /* Gain: '<S388>/Gain3' incorporates:
       *  Product: '<S259>/Product1'
       */
      rtb_Gain3_c = PMSM_to_BLDC_mod1_B.Merge[1] * PMSM_to_BLDC_mod1_B.Merge[1];

      /* Sum: '<S259>/Sum' */
      PMSM_to_BLDC_mod1_B.Sum = rtb_Gain_e + rtb_Gain3_c;

      /* RelationalOperator: '<S267>/Compare' incorporates:
       *  Constant: '<S267>/Constant'
       */
      PMSM_to_BLDC_mod1_B.Compare = (PMSM_to_BLDC_mod1_B.Sum > 0.0);
    }

    /* If: '<S259>/If' */
    rtPrevAction = PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_g;

    /* Outputs for IfAction SubSystem: '<S199>/If Action Subsystem' incorporates:
     *  ActionPort: '<S202>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S199>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S203>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S225>/If Action Subsystem' incorporates:
     *  ActionPort: '<S228>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S225>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S229>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S364>/If Action Subsystem' incorporates:
     *  ActionPort: '<S367>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S364>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S368>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S261>/IntegralMethod' incorporates:
     *  ActionPort: '<S325>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S261>/OptimizedDifferentiationMethod' incorporates:
     *  ActionPort: '<S328>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S259>/Subsystem' incorporates:
     *  ActionPort: '<S269>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S259>/If Action Subsystem' incorporates:
     *  ActionPort: '<S268>/Action Port'
     */
    /* If: '<S225>/If' incorporates:
     *  If: '<S199>/If'
     *  If: '<S259>/If'
     *  If: '<S364>/If'
     *  SwitchCase: '<S261>/Switch Case'
     */
    tmp_3 = rtsiIsModeUpdateTimeStep(&PMSM_to_BLDC_mod1_M->solverInfo);

    /* End of Outputs for SubSystem: '<S259>/If Action Subsystem' */
    /* End of Outputs for SubSystem: '<S259>/Subsystem' */
    /* End of Outputs for SubSystem: '<S261>/OptimizedDifferentiationMethod' */
    /* End of Outputs for SubSystem: '<S261>/IntegralMethod' */
    /* End of Outputs for SubSystem: '<S364>/If Action Subsystem1' */
    /* End of Outputs for SubSystem: '<S364>/If Action Subsystem' */
    /* End of Outputs for SubSystem: '<S225>/If Action Subsystem1' */
    /* End of Outputs for SubSystem: '<S225>/If Action Subsystem' */
    /* End of Outputs for SubSystem: '<S199>/If Action Subsystem1' */
    /* End of Outputs for SubSystem: '<S199>/If Action Subsystem' */

    /* If: '<S259>/If' */
    if (tmp_3) {
      rtAction = (int8_T)!PMSM_to_BLDC_mod1_B.Compare;
      PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_g = rtAction;
    } else {
      rtAction = PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_g;
    }

    if (rtPrevAction != rtAction) {
      rtsiSetBlockStateForSolverChangedAtMajorStep
        (&PMSM_to_BLDC_mod1_M->solverInfo, true);
    }

    if (rtAction == 0) {
      /* Outputs for IfAction SubSystem: '<S259>/Subsystem' incorporates:
       *  ActionPort: '<S269>/Action Port'
       */
      /* Sqrt: '<S269>/Sqrt' */
      rtb_Product1_o = sqrt(PMSM_to_BLDC_mod1_B.Sum);

      /* Merge: '<S259>/Merge1' incorporates:
       *  Product: '<S269>/Divide'
       *  SignalConversion generated from: '<S269>/Out2'
       */
      rtb_Add1_f = 1.0 / rtb_Product1_o * PMSM_to_BLDC_mod1_B.Merge[1];

      /* Merge: '<S259>/Merge' incorporates:
       *  Product: '<S269>/Divide1'
       *  SignalConversion generated from: '<S269>/Out1'
       */
      rtb_Product1_o = PMSM_to_BLDC_mod1_B.Merge[0] / rtb_Product1_o;
      if (tmp_3) {
        srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S259>/Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S259>/If Action Subsystem' incorporates:
       *  ActionPort: '<S268>/Action Port'
       */
      /* Merge: '<S259>/Merge' incorporates:
       *  DataTypeConversion: '<S268>/Data Type Conversion'
       *  SignalConversion generated from: '<S268>/Out1'
       */
      rtb_Product1_o = PMSM_to_BLDC_mod1_B.Merge[0];

      /* Merge: '<S259>/Merge1' incorporates:
       *  DataTypeConversion: '<S268>/Data Type Conversion1'
       *  SignalConversion generated from: '<S268>/Out2'
       */
      rtb_Add1_f = PMSM_to_BLDC_mod1_B.Merge[1];
      if (tmp_3) {
        srUpdateBC(PMSM_to_BLDC_mod1_DW.IfActionSubsystem_SubsysRanBC_b);
      }

      /* End of Outputs for SubSystem: '<S259>/If Action Subsystem' */
    }

    if (tmp_2) {
      /* SwitchCase: '<S261>/Switch Case' incorporates:
       *  Delay: '<S352>/Delay'
       */
      if (tmp_3) {
        rtAction = 1;
        PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem_n = 1;
      } else {
        rtAction = PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem_n;
      }

      if (rtAction == 0) {
        /* Outputs for IfAction SubSystem: '<S261>/IntegralMethod' incorporates:
         *  ActionPort: '<S325>/Action Port'
         */
        /* Delay: '<S342>/Delay' */
        if (PMSM_to_BLDC_mod1_DW.icLoad_bd) {
          /* Sum: '<S342>/Add1' incorporates:
           *  Constant: '<S336>/IC'
           */
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av = 0.0;
        }

        /* Sum: '<S342>/Add1' incorporates:
         *  Delay: '<S342>/Delay'
         *  Product: '<S342>/Product'
         *  Product: '<S342>/Product1'
         *  Switch: '<S342>/Switch'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av = rtb_Add1_f * 0.95650500031643548
          + 0.043494999683564517 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av;

        /* Delay: '<S339>/Delay1' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_p == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay1_DSTATE = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_p = 0U;

        /* Delay: '<S339>/Delay' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_h == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_f = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_h = 0U;

        /* Sum: '<S339>/Sum1' incorporates:
         *  Constant: '<S322>/I1Cnst'
         *  Constant: '<S322>/I2Cnst'
         *  Delay: '<S339>/Delay'
         *  Delay: '<S339>/Delay1'
         *  Product: '<S339>/Product'
         *  Product: '<S339>/Product1'
         *  Sum: '<S339>/Sum'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_f =
          (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av +
           PMSM_to_BLDC_mod1_DW.Delay1_DSTATE) * 2.4945142765920684E-5 +
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_f * 0.99561142127365465;

        /* Delay: '<S345>/Delay' */
        if (PMSM_to_BLDC_mod1_DW.icLoad_k) {
          /* Sum: '<S345>/Add1' incorporates:
           *  Constant: '<S337>/IC'
           */
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d = 0.0;
        }

        /* Sum: '<S345>/Add1' incorporates:
         *  Delay: '<S345>/Delay'
         *  Product: '<S345>/Product'
         *  Product: '<S345>/Product1'
         *  Switch: '<S345>/Switch'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d = rtb_Product1_o *
          0.95650500031643548 + 0.043494999683564517 *
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d;

        /* Delay: '<S338>/Delay1' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_i == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_o = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_i = 0U;

        /* Delay: '<S338>/Delay' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_k == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_k = 0U;

        /* Sum: '<S338>/Sum1' incorporates:
         *  Constant: '<S322>/I1Cnst'
         *  Constant: '<S322>/I2Cnst'
         *  Delay: '<S338>/Delay'
         *  Delay: '<S338>/Delay1'
         *  Product: '<S338>/Product'
         *  Product: '<S338>/Product1'
         *  Sum: '<S338>/Sum'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i =
          (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d +
           PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_o) * 2.4945142765920684E-5 +
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i * 0.99561142127365465;

        /* Math: '<S325>/Math Function' incorporates:
         *  Delay: '<S338>/Delay'
         *  Delay: '<S339>/Delay'
         *  Product: '<S325>/Product'
         *  Product: '<S325>/Product1'
         *  Sum: '<S325>/Sum'
         *
         * About '<S325>/Math Function':
         *  Operator: reciprocal
         */
        rtb_Gain4_g = 1.0 / (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_f *
                             rtb_Product1_o -
                             PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i * rtb_Add1_f);

        /* Switch: '<S325>/Switch1' incorporates:
         *  Abs: '<S325>/Abs'
         */
        if (fabs(rtb_Gain4_g) > 87964.5943005142) {
          /* Merge: '<S261>/Merge' incorporates:
           *  Constant: '<S325>/Constant'
           */
          rtb_Gain4_g = 0.0;
        }

        /* End of Switch: '<S325>/Switch1' */

        /* Update for Delay: '<S342>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_bd = false;

        /* Update for Delay: '<S339>/Delay1' */
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE =
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av;

        /* Update for Delay: '<S345>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_k = false;

        /* Update for Delay: '<S338>/Delay1' */
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_o =
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d;
        if (tmp_3) {
          srUpdateBC(PMSM_to_BLDC_mod1_DW.IntegralMethod_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S261>/IntegralMethod' */
      } else {
        /* Outputs for IfAction SubSystem: '<S261>/OptimizedDifferentiationMethod' incorporates:
         *  ActionPort: '<S328>/Action Port'
         */
        if (PMSM_to_BLDC_mod1_DW.icLoad_b1) {
          /* Sum: '<S352>/Add1' incorporates:
           *  Constant: '<S348>/IC'
           *  Delay: '<S352>/Delay'
           */
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aa = 0.0;
        }

        /* Sum: '<S352>/Add1' incorporates:
         *  Delay: '<S352>/Delay'
         *  Product: '<S352>/Product'
         *  Product: '<S352>/Product1'
         *  Switch: '<S352>/Switch'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aa = rtb_Add1_f * 0.95650500031643548
          + 0.043494999683564517 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aa;

        /* Product: '<S347>/Product' incorporates:
         *  Constant: '<S322>/OD1Cnst'
         */
        rtb_Gain_e = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aa *
          2.1991148575128554E+6;

        /* Delay: '<S347>/Delay2' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_n = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE = 0U;

        /* Delay: '<S347>/Delay3' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay3_DSTATE = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE = 0U;

        /* Product: '<S347>/Product1' incorporates:
         *  Constant: '<S322>/OD2Cnst'
         *  Delay: '<S347>/Delay2'
         *  Delay: '<S347>/Delay3'
         *  Sum: '<S347>/Sum1'
         */
        PMSM_to_BLDC_mod1_DW.Delay3_DSTATE =
          ((PMSM_to_BLDC_mod1_DW.Delay3_DSTATE + rtb_Gain_e) -
           PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_n) * 0.0090126024492556654;

        /* Delay: '<S346>/Delay2' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE_p == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_h = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE_p = 0U;
        rtb_Gain4_g = PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_h;

        /* Delay: '<S346>/Delay3' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE_k == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_p = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE_k = 0U;

        /* Delay: '<S355>/Delay' */
        if (PMSM_to_BLDC_mod1_DW.icLoad_c) {
          /* Sum: '<S355>/Add1' incorporates:
           *  Constant: '<S349>/IC'
           */
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_l = 0.0;
        }

        /* Sum: '<S355>/Add1' incorporates:
         *  Delay: '<S355>/Delay'
         *  Product: '<S355>/Product'
         *  Product: '<S355>/Product1'
         *  Switch: '<S355>/Switch'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_l = rtb_Product1_o *
          0.95650500031643548 + 0.043494999683564517 *
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_l;

        /* Product: '<S346>/Product' incorporates:
         *  Constant: '<S322>/OD1Cnst'
         *  Delay: '<S346>/Delay2'
         */
        PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_h =
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_l * 2.1991148575128554E+6;

        /* Product: '<S346>/Product1' incorporates:
         *  Constant: '<S322>/OD2Cnst'
         *  Delay: '<S346>/Delay2'
         *  Delay: '<S346>/Delay3'
         *  Sum: '<S346>/Sum1'
         */
        PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_p =
          ((PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_p +
            PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_h) - rtb_Gain4_g) *
          0.0090126024492556654;

        /* Merge: '<S261>/Merge' incorporates:
         *  Delay: '<S346>/Delay3'
         *  Delay: '<S347>/Delay3'
         *  Product: '<S328>/Product'
         *  Product: '<S328>/Product1'
         *  Sum: '<S328>/Sum'
         */
        rtb_Gain4_g = PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_p * rtb_Add1_f -
          PMSM_to_BLDC_mod1_DW.Delay3_DSTATE * rtb_Product1_o;

        /* Update for Delay: '<S352>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_b1 = false;

        /* Update for Delay: '<S347>/Delay2' */
        PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_n = rtb_Gain_e;

        /* Update for Delay: '<S355>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_c = false;
        if (tmp_3) {
          srUpdateBC(PMSM_to_BLDC_mod1_DW.OptimizedDifferentiationMethod_);
        }

        /* End of Outputs for SubSystem: '<S261>/OptimizedDifferentiationMethod' */
      }

      /* Gain: '<S388>/Gain3' incorporates:
       *  Constant: '<S261>/SpdFilterCoeff'
       *  Constant: '<S323>/One'
       *  Sum: '<S323>/Sum'
       */
      rtb_Gain3_c = 0.99530971347415453;

      /* Switch: '<S323>/Switch1' */
      rtb_Gain_e = rtb_Gain3_c;

      /* Delay: '<S335>/Delay' incorporates:
       *  Constant: '<S323>/IC'
       */
      if (PMSM_to_BLDC_mod1_DW.icLoad_f) {
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_a = 0.0;
      }

      /* Gain: '<S388>/Gain3' incorporates:
       *  Delay: '<S335>/Delay'
       *  Product: '<S335>/Product1'
       */
      rtb_Gain3_c = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_a;
      rtb_Gain3_c *= rtb_Gain_e;

      /* Sum: '<S335>/Add1' incorporates:
       *  Product: '<S335>/Product'
       *  Switch: '<S335>/Switch'
       */
      rtb_Add1_e = rtb_Gain4_g * 0.0046902865258454489 + rtb_Gain3_c;

      /* Delay: '<S359>/Delay' */
      if (PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_a == POS_ZCSIG) {
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj = 0.0;
      }

      PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_a = 0U;

      /* If: '<S364>/If' incorporates:
       *  Constant: '<S366>/Constant'
       *  DataTypeConversion: '<S359>/Data Type Conversion3'
       *  Delay: '<S359>/Delay'
       *  RelationalOperator: '<S366>/Compare'
       */
      if (tmp_3) {
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_e = (int8_T)!((real32_T)
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj < 0.0F);
      }

      if (PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_e == 0) {
        /* Outputs for IfAction SubSystem: '<S364>/If Action Subsystem' incorporates:
         *  ActionPort: '<S367>/Action Port'
         */
        /* DataTypeConversion: '<S367>/Convert_uint16' incorporates:
         *  DataTypeConversion: '<S359>/Data Type Conversion3'
         *  Delay: '<S359>/Delay'
         */
        rtb_PositionGain = floorf((real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj);
        if (rtIsNaNF(rtb_PositionGain) || rtIsInfF(rtb_PositionGain)) {
          rtb_PositionGain = 0.0F;
        } else {
          rtb_PositionGain = fmodf(rtb_PositionGain, 65536.0F);
        }

        /* Sum: '<S367>/Sum' incorporates:
         *  DataTypeConversion: '<S359>/Data Type Conversion3'
         *  DataTypeConversion: '<S367>/Convert_back'
         *  DataTypeConversion: '<S367>/Convert_uint16'
         *  Delay: '<S359>/Delay'
         */
        rtb_indexing = (real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj -
          (real32_T)(rtb_PositionGain < 0.0F ? (int32_T)(int16_T)-(int16_T)
                     (uint16_T)-rtb_PositionGain : (int32_T)(int16_T)(uint16_T)
                     rtb_PositionGain);
        if (tmp_3) {
          srUpdateBC(PMSM_to_BLDC_mod1_DW.IfActionSubsystem_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S364>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S364>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S368>/Action Port'
         */
        /* DataTypeConversion: '<S368>/Convert_uint16' incorporates:
         *  DataTypeConversion: '<S359>/Data Type Conversion3'
         *  Delay: '<S359>/Delay'
         */
        rtb_PositionGain = truncf((real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj);
        if (rtIsNaNF(rtb_PositionGain) || rtIsInfF(rtb_PositionGain)) {
          rtb_PositionGain = 0.0F;
        } else {
          rtb_PositionGain = fmodf(rtb_PositionGain, 65536.0F);
        }

        /* Sum: '<S368>/Sum' incorporates:
         *  DataTypeConversion: '<S359>/Data Type Conversion3'
         *  DataTypeConversion: '<S368>/Convert_back'
         *  DataTypeConversion: '<S368>/Convert_uint16'
         *  Delay: '<S359>/Delay'
         */
        rtb_indexing = (real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj -
          (real32_T)(rtb_PositionGain < 0.0F ? (int32_T)(int16_T)-(int16_T)
                     (uint16_T)-rtb_PositionGain : (int32_T)(int16_T)(uint16_T)
                     rtb_PositionGain);
        if (tmp_3) {
          srUpdateBC(PMSM_to_BLDC_mod1_DW.IfActionSubsystem1_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S364>/If Action Subsystem1' */
      }

      /* Gain: '<S362>/indexing' */
      rtb_indexing *= 800.0F;

      /* DataTypeConversion: '<S362>/Get_Integer' */
      rtb_PositionGain = truncf(rtb_indexing);
      if (rtIsNaNF(rtb_PositionGain) || rtIsInfF(rtb_PositionGain)) {
        rtb_PositionGain = 0.0F;
      } else {
        rtb_PositionGain = fmodf(rtb_PositionGain, 65536.0F);
      }

      status = (uint16_T)(rtb_PositionGain < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                          (uint16_T)-rtb_PositionGain : (int32_T)(uint16_T)
                          rtb_PositionGain);

      /* End of DataTypeConversion: '<S362>/Get_Integer' */

      /* Sum: '<S362>/Sum2' incorporates:
       *  DataTypeConversion: '<S362>/Data Type Conversion1'
       */
      rtb_PositionGain = rtb_indexing - (real32_T)status;

      /* Sum: '<S254>/Sum' incorporates:
       *  Constant: '<S362>/offset'
       *  Constant: '<S362>/sine_table_values'
       *  DataTypeConversion: '<S359>/Data Type Conversion'
       *  DataTypeConversion: '<S359>/Data Type Conversion1'
       *  Product: '<S254>/Product'
       *  Product: '<S254>/Product1'
       *  Product: '<S363>/Product'
       *  Product: '<S363>/Product1'
       *  Selector: '<S362>/Lookup'
       *  Sum: '<S362>/Sum'
       *  Sum: '<S363>/Sum3'
       *  Sum: '<S363>/Sum4'
       *  Sum: '<S363>/Sum5'
       *  Sum: '<S363>/Sum6'
       */
      rtb_Gain_e = ((PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[(int32_T)
                     (status + 201U)] -
                     PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[(int32_T)
                     (status + 200U)]) * rtb_PositionGain +
                    PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[(int32_T)
                    (status + 200U)]) * rtb_Product1_o -
        ((PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[(int32_T)(status + 1U)]
          - PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[status]) *
         rtb_PositionGain +
         PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[status]) * rtb_Add1_f;

      /* DiscreteIntegrator: '<S304>/Integrator' */
      if (PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState != 0) {
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE = 0.0;
      }

      /* DiscreteIntegrator: '<S304>/Integrator' incorporates:
       *  Gain: '<S301>/Integral Gain'
       */
      PMSM_to_BLDC_mod1_B.Integrator = 5.0 * rtb_Gain_e +
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE;

      /* Sum: '<S254>/Sum1' incorporates:
       *  Gain: '<S309>/Proportional Gain'
       *  Sum: '<S313>/Sum'
       */
      rtb_Gain_e = (250.0 * rtb_Gain_e + PMSM_to_BLDC_mod1_B.Integrator) +
        rtb_Add1_e;

      /* Gain: '<S388>/Gain3' incorporates:
       *  Gain: '<S359>/Gain'
       *  Product: '<S360>/Product'
       */
      rtb_Gain3_c = 7.9577471545947669E-6 * rtb_Gain_e;

      /* Delay: '<S360>/Delay' incorporates:
       *  Constant: '<S360>/InputGain'
       *  Constant: '<S360>/Offset'
       *  Product: '<S360>/Product1'
       *  Sum: '<S360>/Sum1'
       */
      if (PMSM_to_BLDC_mod1_DW.icLoad_a) {
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_ai = 0.0 - rtb_Gain3_c;
      }

      /* Sum: '<S360>/Sum' incorporates:
       *  Delay: '<S360>/Delay'
       */
      rtb_Switch2 = rtb_Gain3_c + PMSM_to_BLDC_mod1_DW.Delay_DSTATE_ai;

      /* Switch: '<S360>/Switch1' */
      if (!(rtb_Switch2 > 0.0)) {
        /* Sum: '<S360>/Sum' incorporates:
         *  Constant: '<S360>/Bias1'
         *  Sum: '<S360>/Sum2'
         */
        rtb_Switch2++;
      }

      /* End of Switch: '<S360>/Switch1' */

      /* Switch: '<S360>/Switch2' */
      if (rtb_Switch2 >= 1.0) {
        /* Sum: '<S360>/Sum' incorporates:
         *  Sum: '<S360>/Sum3'
         *  Switch: '<S360>/Switch2'
         */
        rtb_Switch2--;
      }

      /* End of Switch: '<S360>/Switch2' */

      /* Product: '<S360>/Product2' incorporates:
       *  Delay: '<S359>/Delay'
       */
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj = rtb_Switch2;

      /* DataTypeConversion: '<S67>/Data Type Conversion' incorporates:
       *  Delay: '<S359>/Delay'
       *  Gain: '<S254>/PositionGain'
       */
      PMSM_to_BLDC_mod1_B.DataTypeConversion_a = (real32_T)(6.2831853071795862 *
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj);

      /* Gain: '<S388>/Gain3' incorporates:
       *  Constant: '<S74>/Constant'
       *  Math: '<S74>/Mod'
       */
      rtb_Gain3_c = rt_modd_snf(PMSM_to_BLDC_mod1_B.DataTypeConversion_a, 6.282);

      /* DataTypeConversion: '<S74>/Data Type Conversion1' */
      PMSM_to_BLDC_mod1_B.DataTypeConversion1 = rtb_Gain3_c;

      /* Gain: '<S225>/convert_pu' */
      rtb_Gain4_g = 0.15915494309189535 *
        PMSM_to_BLDC_mod1_B.DataTypeConversion1;

      /* If: '<S225>/If' incorporates:
       *  Constant: '<S227>/Constant'
       *  RelationalOperator: '<S227>/Compare'
       */
      if (tmp_3) {
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_c = (int8_T)!(rtb_Gain4_g < 0.0);
      }

      if (PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_c == 0) {
        /* Outputs for IfAction SubSystem: '<S225>/If Action Subsystem' incorporates:
         *  ActionPort: '<S228>/Action Port'
         */
        PMSM_to_BLDC__IfActionSubsystem(rtb_Gain4_g, &rtb_Gain3_c);
        if (tmp_3) {
          srUpdateBC
            (PMSM_to_BLDC_mod1_DW.IfActionSubsystem_d.IfActionSubsystem_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S225>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S225>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S229>/Action Port'
         */
        PMSM_to_BLDC_IfActionSubsystem1(rtb_Gain4_g, &rtb_Gain3_c);
        if (tmp_3) {
          srUpdateBC
            (PMSM_to_BLDC_mod1_DW.IfActionSubsystem1_j.IfActionSubsystem1_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S225>/If Action Subsystem1' */
      }

      /* Gain: '<S388>/Gain3' incorporates:
       *  Gain: '<S223>/indexing'
       */
      rtb_Gain3_c *= 800.0;

      /* DataTypeConversion: '<S223>/Get_Integer' */
      rtb_Saturation2_idx_0 = trunc(rtb_Gain3_c);
      if (rtIsNaN(rtb_Saturation2_idx_0) || rtIsInf(rtb_Saturation2_idx_0)) {
        rtb_Saturation2_idx_0 = 0.0;
      } else {
        rtb_Saturation2_idx_0 = fmod(rtb_Saturation2_idx_0, 65536.0);
      }

      status = (uint16_T)(rtb_Saturation2_idx_0 < 0.0 ? (int32_T)(uint16_T)
                          -(int16_T)(uint16_T)-rtb_Saturation2_idx_0 : (int32_T)
                          (uint16_T)rtb_Saturation2_idx_0);

      /* End of DataTypeConversion: '<S223>/Get_Integer' */

      /* Sum: '<S223>/Sum2' incorporates:
       *  DataTypeConversion: '<S223>/Data Type Conversion1'
       */
      rtb_Gain4_g = rtb_Gain3_c - (real_T)status;

      /* Sum: '<S224>/Sum4' incorporates:
       *  Constant: '<S223>/offset'
       *  Constant: '<S223>/sine_table_values'
       *  Product: '<S224>/Product'
       *  Selector: '<S223>/Lookup'
       *  Sum: '<S223>/Sum'
       *  Sum: '<S224>/Sum3'
       */
      rtb_Sum4 = (PMSM_to_BLDC_mod1_ConstP.pooled17[(int32_T)(status + 1U)] -
                  PMSM_to_BLDC_mod1_ConstP.pooled17[status]) * rtb_Gain4_g +
        PMSM_to_BLDC_mod1_ConstP.pooled17[status];

      /* Gain: '<S388>/Gain3' incorporates:
       *  Constant: '<S223>/offset'
       *  Constant: '<S223>/sine_table_values'
       *  Product: '<S224>/Product1'
       *  Selector: '<S223>/Lookup'
       *  Sum: '<S223>/Sum'
       *  Sum: '<S224>/Sum5'
       */
      rtb_Gain3_c = PMSM_to_BLDC_mod1_ConstP.pooled17[(int32_T)(status + 201U)]
        - PMSM_to_BLDC_mod1_ConstP.pooled17[(int32_T)(status + 200U)];
      rtb_Gain3_c *= rtb_Gain4_g;

      /* Sum: '<S224>/Sum6' incorporates:
       *  Constant: '<S223>/offset'
       *  Constant: '<S223>/sine_table_values'
       *  Selector: '<S223>/Lookup'
       *  Sum: '<S223>/Sum'
       *  Sum: '<S224>/Sum5'
       */
      rtb_Gain4_g = PMSM_to_BLDC_mod1_ConstP.pooled17[(int32_T)(status + 200U)]
        + rtb_Gain3_c;

      /* Outputs for Atomic SubSystem: '<S221>/Two inputs CRL' */
      /* Gain: '<S388>/Gain3' incorporates:
       *  Product: '<S231>/acos'
       *  Product: '<S231>/bsin'
       *  Sum: '<S231>/sum_Ds'
       */
      rtb_Gain3_c = PMSM_to_BLDC_mod1_B.Kalphabeta0[0] * rtb_Gain4_g;
      rtb_Gain3_c += PMSM_to_BLDC_mod1_B.Kalphabeta0[1] * rtb_Sum4;

      /* AlgorithmDescriptorDelegate generated from: '<S231>/a16' incorporates:
       *  Switch: '<S232>/Switch'
       */
      PMSM_to_BLDC_mod1_B.algDD_o1 = rtb_Gain3_c;

      /* AlgorithmDescriptorDelegate generated from: '<S231>/a16' incorporates:
       *  Product: '<S231>/asin'
       *  Product: '<S231>/bcos'
       *  Sum: '<S231>/sum_Qs'
       */
      PMSM_to_BLDC_mod1_B.algDD_o2 = PMSM_to_BLDC_mod1_B.Kalphabeta0[1] *
        rtb_Gain4_g - PMSM_to_BLDC_mod1_B.Kalphabeta0[0] * rtb_Sum4;

      /* End of Outputs for SubSystem: '<S221>/Two inputs CRL' */

      /* Gain: '<S388>/Gain3' incorporates:
       *  Sum: '<S81>/Sum'
       */
      rtb_Gain3_c = PMSM_to_BLDC_mod1_B.algDD_o1 -
        PMSM_to_BLDC_mod1_B.Constant_a;

      /* DiscreteIntegrator: '<S174>/Integrator' */
      PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b =
        PMSM_to_BLDC_mod1_ConstB.Constant3_n;

      /* Sum: '<S183>/Sum' incorporates:
       *  Constant: '<S81>/Constant'
       *  DiscreteIntegrator: '<S174>/Integrator'
       *  Product: '<S179>/PProd Out'
       */
      rtb_Gain4_g = rtb_Gain3_c * 22.608 +
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b;

      /* Saturate: '<S181>/Saturation' */
      if (rtb_Gain4_g > 1.0) {
        rtb_Sum4 = 1.0;
      } else if (rtb_Gain4_g < -1.0) {
        rtb_Sum4 = -1.0;
      } else {
        rtb_Sum4 = rtb_Gain4_g;
      }

      /* End of Saturate: '<S181>/Saturation' */

      /* Sum: '<S64>/Add' incorporates:
       *  Delay: '<S59>/Delay1'
       */
      PMSM_to_BLDC_mod1_B.Add = PMSM_to_BLDC_mod1_ConstB.Gain4 -
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx;

      /* Gain: '<S445>/Proportional Gain' */
      PMSM_to_BLDC_mod1_B.ProportionalGain = 2.2553506814625575 *
        PMSM_to_BLDC_mod1_B.Add;
    }

    /* Sum: '<S449>/Sum' incorporates:
     *  Integrator: '<S440>/Integrator'
     */
    PMSM_to_BLDC_mod1_B.Sum_o = PMSM_to_BLDC_mod1_B.ProportionalGain +
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE;

    /* Sum: '<S80>/Sum' */
    rtb_Add3 = PMSM_to_BLDC_mod1_B.algDD_o2 - PMSM_to_BLDC_mod1_B.Sum_o;
    if (tmp_2) {
      /* DiscreteIntegrator: '<S119>/Integrator' */
      PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n =
        PMSM_to_BLDC_mod1_ConstB.Constant3;

      /* Sum: '<S128>/Sum' incorporates:
       *  Constant: '<S80>/Constant'
       *  DiscreteIntegrator: '<S119>/Integrator'
       *  Product: '<S124>/PProd Out'
       */
      rtb_Sum1_eq = rtb_Add3 * 22.608 + PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n;

      /* Saturate: '<S126>/Saturation' */
      if (rtb_Sum1_eq > 1.0) {
        rtb_Saturation_k = 1.0;
      } else if (rtb_Sum1_eq < -1.0) {
        rtb_Saturation_k = -1.0;
      } else {
        rtb_Saturation_k = rtb_Sum1_eq;
      }

      /* End of Saturate: '<S126>/Saturation' */

      /* Gain: '<S199>/convert_pu' */
      rtb_Add1_f = 0.15915494309189535 * PMSM_to_BLDC_mod1_B.DataTypeConversion1;

      /* If: '<S199>/If' incorporates:
       *  Constant: '<S201>/Constant'
       *  RelationalOperator: '<S201>/Compare'
       */
      if (tmp_3) {
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_m = (int8_T)!(rtb_Add1_f < 0.0);
      }

      if (PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_m == 0) {
        /* Outputs for IfAction SubSystem: '<S199>/If Action Subsystem' incorporates:
         *  ActionPort: '<S202>/Action Port'
         */
        PMSM_to_BLDC__IfActionSubsystem(rtb_Add1_f, &rtb_Product1_o);
        if (tmp_3) {
          srUpdateBC
            (PMSM_to_BLDC_mod1_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S199>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S199>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S203>/Action Port'
         */
        PMSM_to_BLDC_IfActionSubsystem1(rtb_Add1_f, &rtb_Product1_o);
        if (tmp_3) {
          srUpdateBC
            (PMSM_to_BLDC_mod1_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S199>/If Action Subsystem1' */
      }

      /* Product: '<S266>/Product1' incorporates:
       *  Gain: '<S197>/indexing'
       */
      rtb_Product1_o *= 800.0;

      /* DataTypeConversion: '<S197>/Get_Integer' */
      rtb_Saturation2_idx_0 = trunc(rtb_Product1_o);
      if (rtIsNaN(rtb_Saturation2_idx_0) || rtIsInf(rtb_Saturation2_idx_0)) {
        rtb_Saturation2_idx_0 = 0.0;
      } else {
        rtb_Saturation2_idx_0 = fmod(rtb_Saturation2_idx_0, 65536.0);
      }

      status = (uint16_T)(rtb_Saturation2_idx_0 < 0.0 ? (int32_T)(uint16_T)
                          -(int16_T)(uint16_T)-rtb_Saturation2_idx_0 : (int32_T)
                          (uint16_T)rtb_Saturation2_idx_0);

      /* End of DataTypeConversion: '<S197>/Get_Integer' */

      /* Sum: '<S197>/Sum2' incorporates:
       *  DataTypeConversion: '<S197>/Data Type Conversion1'
       */
      rtb_Add1_f = rtb_Product1_o - (real_T)status;

      /* Sum: '<S198>/Sum4' incorporates:
       *  Constant: '<S197>/offset'
       *  Constant: '<S197>/sine_table_values'
       *  Product: '<S198>/Product'
       *  Selector: '<S197>/Lookup'
       *  Sum: '<S197>/Sum'
       *  Sum: '<S198>/Sum3'
       */
      rtb_Product1_o = (PMSM_to_BLDC_mod1_ConstP.pooled17[(int32_T)(status + 1U)]
                        - PMSM_to_BLDC_mod1_ConstP.pooled17[status]) *
        rtb_Add1_f + PMSM_to_BLDC_mod1_ConstP.pooled17[status];

      /* Sum: '<S198>/Sum6' incorporates:
       *  Constant: '<S197>/offset'
       *  Constant: '<S197>/sine_table_values'
       *  Product: '<S198>/Product1'
       *  Selector: '<S197>/Lookup'
       *  Sum: '<S197>/Sum'
       *  Sum: '<S198>/Sum5'
       */
      rtb_Add1_f = (PMSM_to_BLDC_mod1_ConstP.pooled17[(int32_T)(status + 201U)]
                    - PMSM_to_BLDC_mod1_ConstP.pooled17[(int32_T)(status + 200U)])
        * rtb_Add1_f + PMSM_to_BLDC_mod1_ConstP.pooled17[(int32_T)(status + 200U)];

      /* Outputs for Atomic SubSystem: '<S196>/Two inputs CRL' */
      /* AlgorithmDescriptorDelegate generated from: '<S205>/a16' incorporates:
       *  Product: '<S205>/dcos'
       *  Product: '<S205>/qsin'
       *  Sum: '<S205>/sum_alpha'
       */
      PMSM_to_BLDC_mod1_B.algDD_o1_g = rtb_Sum4 * rtb_Add1_f - rtb_Saturation_k *
        rtb_Product1_o;

      /* AlgorithmDescriptorDelegate generated from: '<S205>/a16' incorporates:
       *  Product: '<S205>/dsin'
       *  Product: '<S205>/qcos'
       *  Sum: '<S205>/sum_beta'
       */
      PMSM_to_BLDC_mod1_B.algDD_o2_h = rtb_Saturation_k * rtb_Add1_f + rtb_Sum4 *
        rtb_Product1_o;

      /* End of Outputs for SubSystem: '<S196>/Two inputs CRL' */

      /* Product: '<S266>/Product1' incorporates:
       *  Gain: '<S216>/one_by_two'
       */
      rtb_Product1_o = 0.5 * PMSM_to_BLDC_mod1_B.algDD_o1_g;

      /* Gain: '<S216>/sqrt3_by_two' */
      rtb_Sum4 = 0.8660254037844386 * PMSM_to_BLDC_mod1_B.algDD_o2_h;

      /* Sum: '<S216>/add_b' */
      rtb_Add1_f = rtb_Sum4 - rtb_Product1_o;

      /* Product: '<S266>/Product1' incorporates:
       *  Sum: '<S216>/add_c'
       */
      rtb_Product1_o = (0.0 - rtb_Product1_o) - rtb_Sum4;

      /* Gain: '<S210>/one_by_two' incorporates:
       *  MinMax: '<S210>/Max'
       *  MinMax: '<S210>/Min'
       *  Sum: '<S210>/Add'
       */
      rtb_Sum4 = (fmax(fmax(PMSM_to_BLDC_mod1_B.algDD_o1_g, rtb_Add1_f),
                       rtb_Product1_o) + fmin(fmin
        (PMSM_to_BLDC_mod1_B.algDD_o1_g, rtb_Add1_f), rtb_Product1_o)) * -0.5;

      /* Gain: '<S209>/Gain' incorporates:
       *  Sum: '<S209>/Add1'
       *  Sum: '<S209>/Add2'
       *  Sum: '<S209>/Add3'
       */
      PMSM_to_BLDC_mod1_B.Gain_p[0] = (PMSM_to_BLDC_mod1_B.algDD_o1_g + rtb_Sum4)
        * 1.1547005383792517;
      PMSM_to_BLDC_mod1_B.Gain_p[1] = (rtb_Add1_f + rtb_Sum4) *
        1.1547005383792517;
      PMSM_to_BLDC_mod1_B.Gain_p[2] = (rtb_Sum4 + rtb_Product1_o) *
        1.1547005383792517;

      /* Gain: '<S68>/Gain' incorporates:
       *  Constant: '<S68>/Constant'
       *  Sum: '<S68>/Add'
       */
      rtb_Sum4 = (PMSM_to_BLDC_mod1_B.Gain_p[0] + 1.45) * 0.33333333333333331;
      PMSM_to_BLDC_mod1_B.Gain_f[0] = rtb_Sum4;

      /* Gain: '<S373>/Gain5' incorporates:
       *  Constant: '<S373>/Constant1'
       *  Gain: '<S372>/Gain1'
       *  Sum: '<S373>/Add'
       */
      PMSM_to_BLDC_mod1_B.Gain5[0] = -rtb_Sum4 + 1.0;

      /* Gain: '<S68>/Gain' incorporates:
       *  Constant: '<S68>/Constant'
       *  Sum: '<S68>/Add'
       */
      rtb_Sum4 = (PMSM_to_BLDC_mod1_B.Gain_p[1] + 1.45) * 0.33333333333333331;
      PMSM_to_BLDC_mod1_B.Gain_f[1] = rtb_Sum4;

      /* Gain: '<S373>/Gain5' incorporates:
       *  Constant: '<S373>/Constant1'
       *  Gain: '<S372>/Gain1'
       *  Sum: '<S373>/Add'
       */
      PMSM_to_BLDC_mod1_B.Gain5[1] = -rtb_Sum4 + 1.0;

      /* Gain: '<S68>/Gain' incorporates:
       *  Constant: '<S68>/Constant'
       *  Sum: '<S68>/Add'
       */
      rtb_Sum4 = (PMSM_to_BLDC_mod1_B.Gain_p[2] + 1.45) * 0.33333333333333331;
      PMSM_to_BLDC_mod1_B.Gain_f[2] = rtb_Sum4;

      /* Gain: '<S373>/Gain5' incorporates:
       *  Constant: '<S373>/Constant1'
       *  Gain: '<S372>/Gain1'
       *  Sum: '<S373>/Add'
       */
      PMSM_to_BLDC_mod1_B.Gain5[2] = -rtb_Sum4 + 1.0;

      /* SignalConversion generated from: '<S63>/Codegen' */
      PMSM_to_BLDC_mod1_B.Gate_pulse[0] = PMSM_to_BLDC_mod1_B.Gain_f[0];
      PMSM_to_BLDC_mod1_B.Gate_pulse[1] = PMSM_to_BLDC_mod1_B.Gain5[0];
      PMSM_to_BLDC_mod1_B.Gate_pulse[2] = PMSM_to_BLDC_mod1_B.Gain_f[1];
      PMSM_to_BLDC_mod1_B.Gate_pulse[3] = PMSM_to_BLDC_mod1_B.Gain5[1];
      PMSM_to_BLDC_mod1_B.Gate_pulse[4] = PMSM_to_BLDC_mod1_B.Gain_f[2];
      PMSM_to_BLDC_mod1_B.Gate_pulse[5] = PMSM_to_BLDC_mod1_B.Gain5[2];

      /* Gain: '<S61>/CCR' */
      for (i = 0; i < 6; i++) {
        rtb_CCR[i] = 4096.0 * PMSM_to_BLDC_mod1_B.Gate_pulse[i];
      }

      /* End of Gain: '<S61>/CCR' */

      /* MATLABSystem: '<S459>/PWM Output' */
      timModule = TIM8;

      /* DataTypeConversion: '<S61>/Data Type Conversion' */
      rtb_Saturation2_idx_0 = floor(rtb_CCR[0]);
      if (rtIsNaN(rtb_Saturation2_idx_0) || rtIsInf(rtb_Saturation2_idx_0)) {
        rtb_Saturation2_idx_0 = 0.0;
      } else {
        rtb_Saturation2_idx_0 = fmod(rtb_Saturation2_idx_0, 65536.0);
      }

      /* MATLABSystem: '<S459>/PWM Output' incorporates:
       *  DataTypeConversion: '<S61>/Data Type Conversion'
       */
      C1_DC = checkFrequencyAndDutyCycleLimits
        (PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, (uint32_T)
         (rtb_Saturation2_idx_0 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
          -rtb_Saturation2_idx_0 : (int32_T)(uint16_T)rtb_Saturation2_idx_0));
      setDutyCycleChannel1(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, C1_DC);
      channelEnum = LL_TIM_CHANNEL_CH1N;
      if (PMSM_to_BLDC_mod1_ConstB.DataTypeConversion_j) {
        LL_TIM_CC_EnableChannel(timModule, channelEnum);
      } else {
        LL_TIM_CC_DisableChannel(timModule, channelEnum);
      }

      /* DataTypeConversion: '<S61>/Data Type Conversion2' */
      rtb_Saturation2_idx_0 = floor(rtb_CCR[2]);
      if (rtIsNaN(rtb_Saturation2_idx_0) || rtIsInf(rtb_Saturation2_idx_0)) {
        rtb_Saturation2_idx_0 = 0.0;
      } else {
        rtb_Saturation2_idx_0 = fmod(rtb_Saturation2_idx_0, 65536.0);
      }

      /* MATLABSystem: '<S459>/PWM Output' incorporates:
       *  DataTypeConversion: '<S61>/Data Type Conversion2'
       */
      C1_DC = checkFrequencyAndDutyCycleLimits
        (PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, (uint32_T)
         (rtb_Saturation2_idx_0 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
          -rtb_Saturation2_idx_0 : (int32_T)(uint16_T)rtb_Saturation2_idx_0));
      setDutyCycleChannel2(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, C1_DC);
      channelEnum = LL_TIM_CHANNEL_CH2N;
      if (PMSM_to_BLDC_mod1_ConstB.DataTypeConversion_j) {
        LL_TIM_CC_EnableChannel(timModule, channelEnum);
      } else {
        LL_TIM_CC_DisableChannel(timModule, channelEnum);
      }

      /* DataTypeConversion: '<S61>/Data Type Conversion4' */
      rtb_Saturation2_idx_0 = floor(rtb_CCR[4]);
      if (rtIsNaN(rtb_Saturation2_idx_0) || rtIsInf(rtb_Saturation2_idx_0)) {
        rtb_Saturation2_idx_0 = 0.0;
      } else {
        rtb_Saturation2_idx_0 = fmod(rtb_Saturation2_idx_0, 65536.0);
      }

      /* MATLABSystem: '<S459>/PWM Output' incorporates:
       *  DataTypeConversion: '<S61>/Data Type Conversion4'
       */
      C1_DC = checkFrequencyAndDutyCycleLimits
        (PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, (uint32_T)
         (rtb_Saturation2_idx_0 < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
          -rtb_Saturation2_idx_0 : (int32_T)(uint16_T)rtb_Saturation2_idx_0));
      setDutyCycleChannel3(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, C1_DC);
      channelEnum = LL_TIM_CHANNEL_CH3N;
      if (PMSM_to_BLDC_mod1_ConstB.DataTypeConversion_j) {
        LL_TIM_CC_EnableChannel(timModule, channelEnum);
      } else {
        LL_TIM_CC_DisableChannel(timModule, channelEnum);
      }

      setMOEBitAccToInput(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle,
                          PMSM_to_BLDC_mod1_ConstB.DataTypeConversion_j);

      /* Product: '<S266>/Product' */
      rtb_Gain_e *= 0.0046902865258454489;

      /* Delay: '<S266>/Delay' incorporates:
       *  Constant: '<S258>/IC'
       */
      if (PMSM_to_BLDC_mod1_DW.icLoad_b) {
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_g = 0.0;
      }

      /* Sum: '<S266>/Add1' incorporates:
       *  Delay: '<S266>/Delay'
       *  Product: '<S266>/Product1'
       */
      rtb_Add1_d = 0.99530971347415453 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_g +
        rtb_Gain_e;

      /* Gain: '<S254>/FreqGain' incorporates:
       *  Delay: '<S235>/Delay1'
       */
      PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f = (real32_T)rtb_Add1_d;

      /* Gain: '<S235>/SpeedGain' incorporates:
       *  Delay: '<S235>/Delay1'
       */
      rtb_SpeedGain = 0.142857149F * PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f;

      /* Gain: '<S59>/Gain3' */
      PMSM_to_BLDC_mod1_B.Gain3 = 9.55F * rtb_SpeedGain;

      /* SignalConversion generated from: '<S59>/Speed_controls' */
      PMSM_to_BLDC_mod1_B.idq_ref[0] = PMSM_to_BLDC_mod1_B.Constant_a;
      PMSM_to_BLDC_mod1_B.idq_ref[1] = PMSM_to_BLDC_mod1_B.Sum_o;

      /* DataTypeConversion: '<S75>/Data Type Conversion' incorporates:
       *  Constant: '<S75>/Constant1'
       *  Math: '<S75>/Mod1'
       */
      PMSM_to_BLDC_mod1_B.DataTypeConversion_e = rt_modd_snf
        (PMSM_to_BLDC_mod1_B.algDD_o1, 6.282);

      /* DataTypeConversion: '<S75>/Data Type Conversion1' incorporates:
       *  Constant: '<S75>/Constant1'
       *  Math: '<S75>/Mod2'
       */
      PMSM_to_BLDC_mod1_B.DataTypeConversion1_i = rt_modd_snf
        (PMSM_to_BLDC_mod1_B.algDD_o2, 6.282);

      /* SignalConversion generated from: '<S62>/Delay' */
      PMSM_to_BLDC_mod1_B.TmpSignalConversionAtDelayInpor[0] =
        PMSM_to_BLDC_mod1_B.algDD_o1_g;
      PMSM_to_BLDC_mod1_B.TmpSignalConversionAtDelayInpor[1] =
        PMSM_to_BLDC_mod1_B.algDD_o2_h;
      PMSM_to_BLDC_mod1_B.TmpSignalConversionAtDelayInpor[2] =
        PMSM_to_BLDC_mod1_B.DataTypeConversion_e;
      PMSM_to_BLDC_mod1_B.TmpSignalConversionAtDelayInpor[3] =
        PMSM_to_BLDC_mod1_B.DataTypeConversion1_i;

      /* SignalConversion generated from: '<S66>/Inverse Park Transform1' */
      PMSM_to_BLDC_mod1_B.TmpSignalConversionAtTAQSigLogg[0] =
        PMSM_to_BLDC_mod1_B.algDD_o1_g;
      PMSM_to_BLDC_mod1_B.TmpSignalConversionAtTAQSigLogg[1] =
        PMSM_to_BLDC_mod1_B.algDD_o2_h;
      PMSM_to_BLDC_mod1_B.TmpSignalConversionAtTAQSigLogg[2] =
        PMSM_to_BLDC_mod1_B.Kalphabeta0[2];

      /* DeadZone: '<S111>/DeadZone' */
      if (rtb_Sum1_eq > 1.0) {
        rtb_Sum1_eq--;
      } else if (rtb_Sum1_eq >= -1.0) {
        rtb_Sum1_eq = 0.0;
      } else {
        rtb_Sum1_eq++;
      }

      /* End of DeadZone: '<S111>/DeadZone' */

      /* Product: '<S116>/IProd Out' incorporates:
       *  Constant: '<S80>/Constant1'
       */
      rtb_Gain_e = rtb_Add3 * 0.23235999999999998;

      /* Switch: '<S109>/Switch1' incorporates:
       *  Constant: '<S109>/Clamping_zero'
       *  Constant: '<S109>/Constant'
       *  Constant: '<S109>/Constant2'
       *  RelationalOperator: '<S109>/fix for DT propagation issue'
       */
      if (rtb_Sum1_eq > 0.0) {
        rtPrevAction = 1;
      } else {
        rtPrevAction = -1;
      }

      /* Switch: '<S109>/Switch2' incorporates:
       *  Constant: '<S109>/Clamping_zero'
       *  Constant: '<S109>/Constant3'
       *  Constant: '<S109>/Constant4'
       *  RelationalOperator: '<S109>/fix for DT propagation issue1'
       */
      if (rtb_Gain_e > 0.0) {
        rtAction = 1;
      } else {
        rtAction = -1;
      }

      /* Switch: '<S109>/Switch' incorporates:
       *  Constant: '<S109>/Clamping_zero'
       *  Logic: '<S109>/AND3'
       *  RelationalOperator: '<S109>/Equal1'
       *  RelationalOperator: '<S109>/Relational Operator'
       *  Switch: '<S109>/Switch1'
       *  Switch: '<S109>/Switch2'
       */
      if ((rtb_Sum1_eq != 0.0) && (rtPrevAction == rtAction)) {
        /* Switch: '<S109>/Switch' incorporates:
         *  Constant: '<S109>/Constant1'
         */
        rtb_Switch = 0.0;
      } else {
        /* Switch: '<S109>/Switch' */
        rtb_Switch = rtb_Gain_e;
      }

      /* End of Switch: '<S109>/Switch' */

      /* DeadZone: '<S166>/DeadZone' */
      if (rtb_Gain4_g > 1.0) {
        rtb_Gain4_g--;
      } else if (rtb_Gain4_g >= -1.0) {
        rtb_Gain4_g = 0.0;
      } else {
        rtb_Gain4_g++;
      }

      /* End of DeadZone: '<S166>/DeadZone' */

      /* Gain: '<S388>/Gain3' incorporates:
       *  Constant: '<S81>/Constant1'
       *  Product: '<S171>/IProd Out'
       */
      rtb_Gain3_c *= 0.23235999999999998;

      /* Switch: '<S164>/Switch1' incorporates:
       *  Constant: '<S164>/Clamping_zero'
       *  Constant: '<S164>/Constant'
       *  Constant: '<S164>/Constant2'
       *  RelationalOperator: '<S164>/fix for DT propagation issue'
       */
      if (rtb_Gain4_g > 0.0) {
        rtPrevAction = 1;
      } else {
        rtPrevAction = -1;
      }

      /* Switch: '<S164>/Switch2' incorporates:
       *  Constant: '<S164>/Clamping_zero'
       *  Constant: '<S164>/Constant3'
       *  Constant: '<S164>/Constant4'
       *  RelationalOperator: '<S164>/fix for DT propagation issue1'
       */
      if (rtb_Gain3_c > 0.0) {
        rtAction = 1;
      } else {
        rtAction = -1;
      }

      /* Switch: '<S164>/Switch' incorporates:
       *  Constant: '<S164>/Clamping_zero'
       *  Logic: '<S164>/AND3'
       *  RelationalOperator: '<S164>/Equal1'
       *  RelationalOperator: '<S164>/Relational Operator'
       *  Switch: '<S164>/Switch1'
       *  Switch: '<S164>/Switch2'
       */
      if ((rtb_Gain4_g != 0.0) && (rtPrevAction == rtAction)) {
        /* Switch: '<S164>/Switch' incorporates:
         *  Constant: '<S164>/Constant1'
         */
        rtb_Switch_e = 0.0;
      } else {
        /* Switch: '<S164>/Switch' */
        rtb_Switch_e = rtb_Gain3_c;
      }

      /* End of Switch: '<S164>/Switch' */
      /* Gain: '<S59>/Gain5' incorporates:
       *  Delay: '<Root>/Delay3'
       *  Delay: '<S59>/Delay1'
       */
      PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_d = 0.159235671F *
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx;
    }

    /* Integrator: '<S380>/Int1' */
    PMSM_to_BLDC_mod1_B.Int1 = PMSM_to_BLDC_mod1_X.Int1_CSTATE;

    /* Gain: '<S374>/Gain' */
    PMSM_to_BLDC_mod1_B.Gain_j = 57.324 * PMSM_to_BLDC_mod1_B.Int1;

    /* Integrator: '<S395>/Integrator' */
    /* Limited  Integrator  */
    if (PMSM_to_BLDC_mod1_DW.Integrator_DWORK1) {
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d =
        PMSM_to_BLDC_mod1_ConstB.IndexVector_a;
    }

    if (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d >= 1.0E+7) {
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d = 1.0E+7;
    } else if (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d <= -1.0E+7) {
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d = -1.0E+7;
    }

    /* Integrator: '<S396>/Integrator' */
    /* Limited  Integrator  */
    if (PMSM_to_BLDC_mod1_DW.Integrator_DWORK1_g) {
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l =
        PMSM_to_BLDC_mod1_ConstB.IndexVector_d;
    }

    if (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l >= 1.0E+7) {
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l = 1.0E+7;
    } else if (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l <= -1.0E+7) {
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l = -1.0E+7;
    }

    /* Gain: '<S391>/Gain2' incorporates:
     *  Gain: '<S391>/Gain1'
     *  Integrator: '<S395>/Integrator'
     *  Integrator: '<S396>/Integrator'
     *  Product: '<S391>/Product'
     *  Product: '<S394>/Product'
     *  Sum: '<S391>/Add'
     */
    PMSM_to_BLDC_mod1_B.Gain2 = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d *
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l * PMSM_to_BLDC_mod1_ConstB.Add +
      0.002386705174987 * PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l) * 10.5;

    /* Gain: '<S374>/Gain1' incorporates:
     *  Gain: '<S376>/Gain'
     */
    PMSM_to_BLDC_mod1_B.Gain1 = 0.0026539278131634818 *
      PMSM_to_BLDC_mod1_B.Gain2 * 9.549;
    if (tmp_2) {
    }

    /* Gain: '<S380>/Gain4' */
    rtb_Gain_e = 7.0 * PMSM_to_BLDC_mod1_B.Int1;

    /* Trigonometry: '<S382>/sine_cosine' */
    rtb_Gain4_g = sin(rtb_Gain_e);
    rtb_Sum4 = cos(rtb_Gain_e);

    /* Sum: '<S390>/Add1' incorporates:
     *  Integrator: '<S395>/Integrator'
     *  Integrator: '<S396>/Integrator'
     *  Product: '<S390>/Product2'
     *  Product: '<S390>/Product3'
     */
    rtb_Add1_f = PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d * rtb_Sum4 -
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l * rtb_Gain4_g;

    /* SignalConversion generated from: '<S379>/Vector Concatenate' incorporates:
     *  Concatenate: '<S379>/Vector Concatenate'
     */
    PMSM_to_BLDC_mod1_B.VectorConcatenate[0] = rtb_Add1_f;

    /* Sum: '<S390>/Add' incorporates:
     *  Integrator: '<S395>/Integrator'
     *  Integrator: '<S396>/Integrator'
     *  Product: '<S390>/Product'
     *  Product: '<S390>/Product1'
     */
    rtb_Gain_e = PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d * rtb_Gain4_g +
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l * rtb_Sum4;

    /* Gain: '<S389>/Gain2' incorporates:
     *  Gain: '<S389>/Gain1'
     */
    rtb_Add1_f *= -0.5;

    /* Sum: '<S389>/Subtract1' incorporates:
     *  Concatenate: '<S379>/Vector Concatenate'
     *  Gain: '<S389>/Gain2'
     *  Gain: '<S389>/Gain3'
     */
    PMSM_to_BLDC_mod1_B.VectorConcatenate[1] = 0.8660254037844386 * rtb_Gain_e +
      rtb_Add1_f;

    /* Sum: '<S389>/Subtract2' incorporates:
     *  Concatenate: '<S379>/Vector Concatenate'
     *  Gain: '<S389>/Gain4'
     */
    PMSM_to_BLDC_mod1_B.VectorConcatenate[2] = -0.8660254037844386 * rtb_Gain_e
      + rtb_Add1_f;

    /* DataTypeConversion: '<S374>/Data Type Conversion' */
    PMSM_to_BLDC_mod1_B.DataTypeConversion_c[0] =
      PMSM_to_BLDC_mod1_B.VectorConcatenate[0];
    PMSM_to_BLDC_mod1_B.DataTypeConversion_c[1] =
      PMSM_to_BLDC_mod1_B.VectorConcatenate[1];
    PMSM_to_BLDC_mod1_B.DataTypeConversion_c[2] =
      PMSM_to_BLDC_mod1_B.VectorConcatenate[2];
    if (tmp_2) {
      /* Saturate: '<S375>/Saturation2' */
      if (PMSM_to_BLDC_mod1_B.Gain_f[0] > 1.0) {
        rtb_Saturation2_idx_0 = 1.0;
      } else if (PMSM_to_BLDC_mod1_B.Gain_f[0] < 0.0) {
        rtb_Saturation2_idx_0 = 0.0;
      } else {
        rtb_Saturation2_idx_0 = PMSM_to_BLDC_mod1_B.Gain_f[0];
      }

      if (PMSM_to_BLDC_mod1_B.Gain_f[1] > 1.0) {
        rtb_Add1_f = 1.0;
      } else if (PMSM_to_BLDC_mod1_B.Gain_f[1] < 0.0) {
        rtb_Add1_f = 0.0;
      } else {
        rtb_Add1_f = PMSM_to_BLDC_mod1_B.Gain_f[1];
      }

      if (PMSM_to_BLDC_mod1_B.Gain_f[2] > 1.0) {
        rtb_Product1_o = 1.0;
      } else if (PMSM_to_BLDC_mod1_B.Gain_f[2] < 0.0) {
        rtb_Product1_o = 0.0;
      } else {
        rtb_Product1_o = PMSM_to_BLDC_mod1_B.Gain_f[2];
      }

      /* End of Saturate: '<S375>/Saturation2' */

      /* Gain: '<S375>/Gain' incorporates:
       *  Sum: '<S375>/Sum'
       */
      rtb_Gain_e = ((rtb_Add1_f + rtb_Product1_o) + rtb_Saturation2_idx_0) *
        0.33333333333333331;

      /* Gain: '<S388>/Gain3' incorporates:
       *  Sum: '<S375>/Sum1'
       */
      rtb_Gain3_c = rtb_Saturation2_idx_0 - rtb_Gain_e;

      /* Product: '<S375>/Product' incorporates:
       *  Sum: '<S375>/Sum2'
       *  Sum: '<S375>/Sum3'
       */
      PMSM_to_BLDC_mod1_B.Product[0] = rtb_Gain3_c *
        PMSM_to_BLDC_mod1_ConstB.Switch;
      PMSM_to_BLDC_mod1_B.Product[1] = (rtb_Add1_f - rtb_Gain_e) *
        PMSM_to_BLDC_mod1_ConstB.Switch;
      PMSM_to_BLDC_mod1_B.Product[2] = (rtb_Product1_o - rtb_Gain_e) *
        PMSM_to_BLDC_mod1_ConstB.Switch;

      /* Gain: '<S388>/Gain3' incorporates:
       *  Gain: '<S388>/Gain1'
       */
      rtb_Gain3_c = -0.33333333333333331 * PMSM_to_BLDC_mod1_B.Product[1];

      /* Sum: '<S388>/Add' incorporates:
       *  Gain: '<S388>/Gain'
       *  Gain: '<S388>/Gain4'
       */
      PMSM_to_BLDC_mod1_B.Add_a = (0.66666666666666663 *
        PMSM_to_BLDC_mod1_B.Product[0] + rtb_Gain3_c) + -0.33333333333333331 *
        PMSM_to_BLDC_mod1_B.Product[2];

      /* Gain: '<S388>/Gain3' */
      rtb_Gain3_c = -0.57735026918962573 * PMSM_to_BLDC_mod1_B.Product[2];

      /* Sum: '<S388>/Add1' incorporates:
       *  Gain: '<S388>/Gain2'
       */
      PMSM_to_BLDC_mod1_B.Add1 = 0.57735026918962573 *
        PMSM_to_BLDC_mod1_B.Product[1] + rtb_Gain3_c;
    }

    /* Sum: '<S395>/Add' incorporates:
     *  Constant: '<S399>/Constant'
     *  Integrator: '<S395>/Integrator'
     *  Integrator: '<S396>/Integrator'
     *  Product: '<S393>/Product2'
     *  Product: '<S393>/Product3'
     *  Product: '<S395>/Product'
     *  Product: '<S397>/Product'
     *  Product: '<S398>/Product'
     *  Product: '<S399>/Product'
     *  Sum: '<S393>/Add1'
     */
    PMSM_to_BLDC_mod1_B.Add_h = ((PMSM_to_BLDC_mod1_B.Add_a * rtb_Sum4 +
      PMSM_to_BLDC_mod1_B.Add1 * rtb_Gain4_g) /
      PMSM_to_BLDC_mod1_ConstB.IndexVector_b + PMSM_to_BLDC_mod1_ConstB.Gain *
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l *
      PMSM_to_BLDC_mod1_ConstB.IndexVector_ah /
      PMSM_to_BLDC_mod1_ConstB.IndexVector1_e) -
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d * 0.037 /
      PMSM_to_BLDC_mod1_ConstB.IndexVector_j;

    /* Sum: '<S396>/Add' incorporates:
     *  Constant: '<S403>/Constant'
     *  Integrator: '<S395>/Integrator'
     *  Integrator: '<S396>/Integrator'
     *  Product: '<S393>/Product'
     *  Product: '<S393>/Product1'
     *  Product: '<S396>/Product'
     *  Product: '<S400>/Product'
     *  Product: '<S401>/Product'
     *  Product: '<S403>/Product'
     *  Sum: '<S393>/Add'
     */
    PMSM_to_BLDC_mod1_B.Add_d = (((PMSM_to_BLDC_mod1_B.Add1 * rtb_Sum4 -
      PMSM_to_BLDC_mod1_B.Add_a * rtb_Gain4_g) /
      PMSM_to_BLDC_mod1_ConstB.IndexVector_k -
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d * PMSM_to_BLDC_mod1_ConstB.Gain *
      PMSM_to_BLDC_mod1_ConstB.IndexVector_m /
      PMSM_to_BLDC_mod1_ConstB.IndexVector1_g) -
      PMSM_to_BLDC_mod1_ConstB.Product) -
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l * 0.037 /
      PMSM_to_BLDC_mod1_ConstB.IndexVector_d3;
    if (tmp_2) {
      /* Gain: '<S437>/Integral Gain' */
      PMSM_to_BLDC_mod1_B.IntegralGain = 78.686679331027022 *
        PMSM_to_BLDC_mod1_B.Add;
    }

    if (tmp_3) {
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Timer_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Timer' */
  if (tmp_0) {
    /* Outputs for Atomic SubSystem: '<Root>/En_gate' */
    /* MATLABSystem: '<S22>/Digital Port Write' */
    portNameLoc = GPIOB;
    channelEnum = MW_GPIO_BIT_SHIFT;
    if (PMSM_to_BLDC_mod1_B.En_State != 0.0) {
      C1_DC = 4096U;
    } else {
      C1_DC = 0U;
    }

    C1_DC = mw_shift(C1_DC, channelEnum);
    pinMask = mw_shift(4096U, channelEnum);
    LL_GPIO_SetOutputPin(portNameLoc, C1_DC);
    LL_GPIO_ResetOutputPin(portNameLoc, ~C1_DC & pinMask);

    /* End of MATLABSystem: '<S22>/Digital Port Write' */
    /* End of Outputs for SubSystem: '<Root>/En_gate' */
  }

  if (tmp_1) {
  }

  if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
      PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[4] == 0) {
    /* MATLABSystem: '<S462>/Analog to Digital Converter' */
    if (PMSM_to_BLDC_mod1_DW.obj_p.TunablePropsChanged) {
      PMSM_to_BLDC_mod1_DW.obj_p.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S462>/Analog to Digital Converter' */
    regularReadADCNormal(PMSM_to_BLDC_mod1_DW.obj_p.ADCHandle,
                         ADC_TRIGGER_AND_READ,
                         &PMSM_to_BLDC_mod1_B.AnalogtoDigitalConverter);

    /* Gain: '<S9>/Gain' incorporates:
     *  DataTypeConversion: '<S9>/Data Type Conversion'
     */
    PMSM_to_BLDC_mod1_B.Gain = 0.015625 * (real_T)
      PMSM_to_BLDC_mod1_B.AnalogtoDigitalConverter;
  }

  if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M)) {
    if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
        PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] == 0) {
      /* Update for Delay: '<Root>/Delay' */
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_cn = PMSM_to_BLDC_mod1_B.Compare_g;

      /* Update for Delay: '<Root>/Delay1' */
      PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fv = PMSM_to_BLDC_mod1_B.Compare_a;

      /* Update for Delay: '<Root>/Delay2' */
      PMSM_to_BLDC_mod1_DW.Delay2_DSTATE = rtb_PhaseCurrent[1];
    }

    /* Update for Enabled SubSystem: '<Root>/Timer' incorporates:
     *  EnablePort: '<S8>/Enable'
     */
    if (PMSM_to_BLDC_mod1_DW.Timer_MODE) {
      if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
          PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0) {
        /* Update for Delay: '<S59>/Delay' */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[0] =
          PMSM_to_BLDC_mod1_B.DataTypeConversion_c[0];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[1] =
          PMSM_to_BLDC_mod1_B.DataTypeConversion_c[1];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[2] =
          PMSM_to_BLDC_mod1_B.DataTypeConversion_c[2];

        /* Update for Delay: '<S62>/Delay' */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[0] =
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[4];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[1] =
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[5];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[2] =
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[6];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[3] =
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[7];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[4] =
          PMSM_to_BLDC_mod1_B.TmpSignalConversionAtDelayInpor[0];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[5] =
          PMSM_to_BLDC_mod1_B.TmpSignalConversionAtDelayInpor[1];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[6] =
          PMSM_to_BLDC_mod1_B.TmpSignalConversionAtDelayInpor[2];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[7] =
          PMSM_to_BLDC_mod1_B.TmpSignalConversionAtDelayInpor[3];

        /* Update for Delay: '<S252>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad = false;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[0] = rtb_Add1[0];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[1] = rtb_Add1[1];

        /* Update for Delay: '<S335>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_f = false;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_a = rtb_Add1_e;

        /* Update for DiscreteIntegrator: '<S304>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE = PMSM_to_BLDC_mod1_B.Integrator;
        PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState = 0;

        /* Update for Delay: '<S360>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_a = false;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_ai = rtb_Switch2;

        /* Update for DiscreteIntegrator: '<S174>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b += rtb_Switch_e;
        PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState_n = 1;

        /* Update for Delay: '<S59>/Delay1' */
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx = rtb_SpeedGain;

        /* Update for DiscreteIntegrator: '<S119>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n += rtb_Switch;
        PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState_nt = 1;

        /* Update for Delay: '<S266>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_b = false;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_g = rtb_Add1_d;
      }

      /* Update for Integrator: '<S395>/Integrator' */
      PMSM_to_BLDC_mod1_DW.Integrator_DWORK1 = false;

      /* Update for Integrator: '<S396>/Integrator' */
      PMSM_to_BLDC_mod1_DW.Integrator_DWORK1_g = false;
    }

    /* End of Update for SubSystem: '<Root>/Timer' */
    if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
        PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [5e-05s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
        ((PMSM_to_BLDC_mod1_M->Timing.clockTick1) * 5.0E-5);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1, extmodeTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
        PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] == 0) {/* Sample time: [0.0001s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
        ((PMSM_to_BLDC_mod1_M->Timing.clockTick2) * 0.0001);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(2, extmodeTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
        PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[3] == 0) {/* Sample time: [0.001s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
        ((PMSM_to_BLDC_mod1_M->Timing.clockTick3) * 0.001);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(3, extmodeTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
        PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[4] == 0) {/* Sample time: [0.1s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
        ((PMSM_to_BLDC_mod1_M->Timing.clockTick4) * 0.1);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(4, extmodeTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
        PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[5] == 0) {/* Sample time: [1.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
        ((PMSM_to_BLDC_mod1_M->Timing.clockTick5) * 1.0);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(5, extmodeTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M)) {
    rt_ertODEUpdateContinuousStates(&PMSM_to_BLDC_mod1_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++PMSM_to_BLDC_mod1_M->Timing.clockTick0;
    PMSM_to_BLDC_mod1_M->Timing.t[0] = rtsiGetSolverStopTime
      (&PMSM_to_BLDC_mod1_M->solverInfo);

    {
      /* Update absolute timer for sample time: [5.0E-5s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 5.0E-5, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      PMSM_to_BLDC_mod1_M->Timing.clockTick1++;
    }

    if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
        PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] == 0) {
      /* Update absolute timer for sample time: [0.0001s, 0.0s] */
      /* The "clockTick2" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.0001, which is the step size
       * of the task. Size of "clockTick2" ensures timer will not overflow during the
       * application lifespan selected.
       */
      PMSM_to_BLDC_mod1_M->Timing.clockTick2++;
    }

    if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
        PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[3] == 0) {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick3" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick3" ensures timer will not overflow during the
       * application lifespan selected.
       */
      PMSM_to_BLDC_mod1_M->Timing.clockTick3++;
    }

    if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
        PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[4] == 0) {
      /* Update absolute timer for sample time: [0.1s, 0.0s] */
      /* The "clockTick4" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.1, which is the step size
       * of the task. Size of "clockTick4" ensures timer will not overflow during the
       * application lifespan selected.
       */
      PMSM_to_BLDC_mod1_M->Timing.clockTick4++;
    }

    if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
        PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[5] == 0) {
      /* Update absolute timer for sample time: [1.0s, 0.0s] */
      /* The "clockTick5" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 1.0, which is the step size
       * of the task. Size of "clockTick5" ensures timer will not overflow during the
       * application lifespan selected.
       */
      PMSM_to_BLDC_mod1_M->Timing.clockTick5++;
    }

    rate_scheduler();
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void PMSM_to_BLDC_mod1_derivatives(void)
{
  XDot_PMSM_to_BLDC_mod1_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_PMSM_to_BLDC_mod1_T *) PMSM_to_BLDC_mod1_M->derivs);

  /* Derivatives for Enabled SubSystem: '<Root>/Timer' */
  if (PMSM_to_BLDC_mod1_DW.Timer_MODE) {
    /* Derivatives for Integrator: '<S440>/Integrator' */
    _rtXdot->Integrator_CSTATE = PMSM_to_BLDC_mod1_B.IntegralGain;

    /* Derivatives for Integrator: '<S380>/Int1' incorporates:
     *  Constant: '<S376>/Speed_Angular_Vel'
     */
    _rtXdot->Int1_CSTATE = 100.0;

    /* Derivatives for Integrator: '<S395>/Integrator' */
    lsat = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d <= -1.0E+7);
    usat = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d >= 1.0E+7);
    if (((!lsat) && (!usat)) || (lsat && (PMSM_to_BLDC_mod1_B.Add_h > 0.0)) ||
        (usat && (PMSM_to_BLDC_mod1_B.Add_h < 0.0))) {
      _rtXdot->Integrator_CSTATE_d = PMSM_to_BLDC_mod1_B.Add_h;
    } else {
      /* in saturation */
      _rtXdot->Integrator_CSTATE_d = 0.0;
    }

    /* End of Derivatives for Integrator: '<S395>/Integrator' */

    /* Derivatives for Integrator: '<S396>/Integrator' */
    lsat = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l <= -1.0E+7);
    usat = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l >= 1.0E+7);
    if (((!lsat) && (!usat)) || (lsat && (PMSM_to_BLDC_mod1_B.Add_d > 0.0)) ||
        (usat && (PMSM_to_BLDC_mod1_B.Add_d < 0.0))) {
      _rtXdot->Integrator_CSTATE_l = PMSM_to_BLDC_mod1_B.Add_d;
    } else {
      /* in saturation */
      _rtXdot->Integrator_CSTATE_l = 0.0;
    }

    /* End of Derivatives for Integrator: '<S396>/Integrator' */
  } else {
    {
      real_T *dx;
      int_T i1;
      dx = &(((XDot_PMSM_to_BLDC_mod1_T *) PMSM_to_BLDC_mod1_M->derivs)
             ->Integrator_CSTATE);
      for (i1=0; i1 < 4; i1++) {
        dx[i1] = 0.0;
      }
    }
  }

  /* End of Derivatives for SubSystem: '<Root>/Timer' */
}

/* Model initialize function */
void PMSM_to_BLDC_mod1_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PMSM_to_BLDC_mod1_M->solverInfo,
                          &PMSM_to_BLDC_mod1_M->Timing.simTimeStep);
    rtsiSetTPtr(&PMSM_to_BLDC_mod1_M->solverInfo, &rtmGetTPtr
                (PMSM_to_BLDC_mod1_M));
    rtsiSetStepSizePtr(&PMSM_to_BLDC_mod1_M->solverInfo,
                       &PMSM_to_BLDC_mod1_M->Timing.stepSize0);
    rtsiSetdXPtr(&PMSM_to_BLDC_mod1_M->solverInfo, &PMSM_to_BLDC_mod1_M->derivs);
    rtsiSetContStatesPtr(&PMSM_to_BLDC_mod1_M->solverInfo, (real_T **)
                         &PMSM_to_BLDC_mod1_M->contStates);
    rtsiSetNumContStatesPtr(&PMSM_to_BLDC_mod1_M->solverInfo,
      &PMSM_to_BLDC_mod1_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&PMSM_to_BLDC_mod1_M->solverInfo,
      &PMSM_to_BLDC_mod1_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&PMSM_to_BLDC_mod1_M->solverInfo,
      &PMSM_to_BLDC_mod1_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&PMSM_to_BLDC_mod1_M->solverInfo,
      &PMSM_to_BLDC_mod1_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&PMSM_to_BLDC_mod1_M->solverInfo, (boolean_T**)
      &PMSM_to_BLDC_mod1_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&PMSM_to_BLDC_mod1_M->solverInfo, (&rtmGetErrorStatus
      (PMSM_to_BLDC_mod1_M)));
    rtsiSetRTModelPtr(&PMSM_to_BLDC_mod1_M->solverInfo, PMSM_to_BLDC_mod1_M);
  }

  rtsiSetSimTimeStep(&PMSM_to_BLDC_mod1_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&PMSM_to_BLDC_mod1_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&PMSM_to_BLDC_mod1_M->solverInfo, false);
  PMSM_to_BLDC_mod1_M->intgData.y = PMSM_to_BLDC_mod1_M->odeY;
  PMSM_to_BLDC_mod1_M->intgData.f[0] = PMSM_to_BLDC_mod1_M->odeF[0];
  PMSM_to_BLDC_mod1_M->intgData.f[1] = PMSM_to_BLDC_mod1_M->odeF[1];
  PMSM_to_BLDC_mod1_M->intgData.f[2] = PMSM_to_BLDC_mod1_M->odeF[2];
  PMSM_to_BLDC_mod1_M->contStates = ((X_PMSM_to_BLDC_mod1_T *)
    &PMSM_to_BLDC_mod1_X);
  PMSM_to_BLDC_mod1_M->contStateDisabled = ((XDis_PMSM_to_BLDC_mod1_T *)
    &PMSM_to_BLDC_mod1_XDis);
  PMSM_to_BLDC_mod1_M->Timing.tStart = (0.0);
  PMSM_to_BLDC_mod1_M->periodicContStateIndices = ((int_T*)
    PMSM_to_BLDC_mod1_PeriodicIndX);
  PMSM_to_BLDC_mod1_M->periodicContStateRanges = ((real_T*)
    PMSM_to_BLDC_mod1_PeriodicRngX);
  rtsiSetSolverData(&PMSM_to_BLDC_mod1_M->solverInfo, (void *)
                    &PMSM_to_BLDC_mod1_M->intgData);
  rtsiSetSolverName(&PMSM_to_BLDC_mod1_M->solverInfo,"ode3");
  rtmSetTPtr(PMSM_to_BLDC_mod1_M, &PMSM_to_BLDC_mod1_M->Timing.tArray[0]);
  rtmSetTFinal(PMSM_to_BLDC_mod1_M, -1);
  PMSM_to_BLDC_mod1_M->Timing.stepSize0 = 5.0E-5;
  rtmSetFirstInitCond(PMSM_to_BLDC_mod1_M, 1);

  /* External mode info */
  PMSM_to_BLDC_mod1_M->Sizes.checksums[0] = (122757583U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[1] = (3319857771U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[2] = (1860320142U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[3] = (707542565U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[89];
    PMSM_to_BLDC_mod1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_g;
    systemRan[3] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_g;
    systemRan[4] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_c;
    systemRan[5] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_c;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[16] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[17] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[18] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[19] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[20] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[21] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[22] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[25] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[26] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[27] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[28] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[29] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[30] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[31] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_n;
    systemRan[32] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_n;
    systemRan[33] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_n;
    systemRan[34] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_f;
    systemRan[35] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_f;
    systemRan[36] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_f;
    systemRan[37] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_f;
    systemRan[38] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_f;
    systemRan[39] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_f;
    systemRan[40] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_f;
    systemRan[41] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC;
    systemRan[42] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC;
    systemRan[43] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC;
    systemRan[44] = &rtAlwaysEnabled;
    systemRan[45] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg1_read_SubsysRanBC;
    systemRan[46] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg1_read_SubsysRanBC;
    systemRan[47] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg1_read_SubsysRanBC;
    systemRan[48] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg1_read_SubsysRanBC;
    systemRan[49] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg1_read_SubsysRanBC;
    systemRan[50] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg1_read_SubsysRanBC;
    systemRan[51] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg1_read_SubsysRanBC;
    systemRan[52] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_SubsysRanBC;
    systemRan[53] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_SubsysRanBC;
    systemRan[54] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_SubsysRanBC;
    systemRan[55] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_SubsysRanBC;
    systemRan[56] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_SubsysRanBC;
    systemRan[57] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_SubsysRanBC;
    systemRan[58] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_SubsysRanBC;
    systemRan[59] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[60] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC;
    systemRan[61] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Timer_SubsysRanBC;
    systemRan[62] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IfActionSubsystem_d.IfActionSubsystem_SubsysRanBC;
    systemRan[63] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IfActionSubsystem1_j.IfActionSubsystem1_SubsysRanBC;
    systemRan[64] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Timer_SubsysRanBC;
    systemRan[65] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Dir_Sense_SubsysRanBC;
    systemRan[66] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem2_SubsysRanBC;
    systemRan[67] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem3_SubsysRanBC;
    systemRan[68] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IfActionSubsystem_SubsysRanBC_b;
    systemRan[69] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC;
    systemRan[70] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IntegralMethod_SubsysRanBC;
    systemRan[71] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IntegralMethod_SubsysRanBC;
    systemRan[72] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IntegralMethod_SubsysRanBC;
    systemRan[73] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IntegralMethod_SubsysRanBC;
    systemRan[74] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IntegralMethod_SubsysRanBC;
    systemRan[75] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.OptimizedDifferentiationMethod_;
    systemRan[76] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.OptimizedDifferentiationMethod_;
    systemRan[77] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.OptimizedDifferentiationMethod_;
    systemRan[78] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.OptimizedDifferentiationMethod_;
    systemRan[79] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.OptimizedDifferentiationMethod_;
    systemRan[80] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IfActionSubsystem_SubsysRanBC_a;
    systemRan[81] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IfActionSubsystem1_SubsysRanB_e;
    systemRan[82] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Timer_SubsysRanBC;
    systemRan[83] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Timer_SubsysRanBC;
    systemRan[84] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[85] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[86] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Timer_SubsysRanBC;
    systemRan[87] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Timer_SubsysRanBC;
    systemRan[88] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PMSM_to_BLDC_mod1_M->extModeInfo,
      &PMSM_to_BLDC_mod1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PMSM_to_BLDC_mod1_M->extModeInfo,
                        PMSM_to_BLDC_mod1_M->Sizes.checksums);
    rteiSetTPtr(PMSM_to_BLDC_mod1_M->extModeInfo, rtmGetTPtr(PMSM_to_BLDC_mod1_M));
  }

  /* block I/O */
  {
    PMSM_to_BLDC_mod1_B.Constant = 21.76182191997469;
    PMSM_to_BLDC_mod1_B.Gain2_g = 1305.1435078285622;
    PMSM_to_BLDC_mod1_B.Gain1_e = 955.00000000000011;
  }

  PMSM_to_BLDC_mod1_PrevZCX.Dir_Sense_Trig_ZCE = POS_ZCSIG;
  PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_p = UNINITIALIZED_ZCSIG;
  PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_h = UNINITIALIZED_ZCSIG;
  PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_i = UNINITIALIZED_ZCSIG;
  PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_k = UNINITIALIZED_ZCSIG;
  PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE = UNINITIALIZED_ZCSIG;
  PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE = UNINITIALIZED_ZCSIG;
  PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE_p = UNINITIALIZED_ZCSIG;
  PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE_k = UNINITIALIZED_ZCSIG;
  PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE = UNINITIALIZED_ZCSIG;
  PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_a = UNINITIALIZED_ZCSIG;

  /* SystemInitialize for Atomic SubSystem: '<S23>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift);

  /* End of SystemInitialize for SubSystem: '<S23>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S23>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1);

  /* End of SystemInitialize for SubSystem: '<S23>/Bit Shift1' */

  /* Start for MATLABSystem: '<S23>/SPI Receive' */
  PMSM_to_BLDC_mod1_DW.obj_g.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj_g.matlabCodegenIsDeleted = false;
  PMSM_to_BL_SystemCore_setup_oxg(&PMSM_to_BLDC_mod1_DW.obj_g);

  /* Start for MATLABSystem: '<S23>/SPI Transmit' */
  PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete = false;
  PMSM_to_BLDC_mod1_DW.obj_j.isInitialized = 1;
  PMSM_to_SPIDrvBlock_setupImpl_o(&PMSM_to_BLDC_mod1_DW.obj_j);
  PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<S5>/Control_Reg2' */
  /* SystemInitialize for Atomic SubSystem: '<S24>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_h);

  /* End of SystemInitialize for SubSystem: '<S24>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S24>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_d);

  /* End of SystemInitialize for SubSystem: '<S24>/Bit Shift1' */

  /* Start for MATLABSystem: '<S24>/SPI Transmit' */
  PMSM_to_BLDC_mod1_DW.obj_n.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_n.isSetupComplete = false;
  PMSM_to_BLDC_mod1_DW.obj_n.isInitialized = 1;
  PMSM_to_SPIDrvBlock_setupImpl_o(&PMSM_to_BLDC_mod1_DW.obj_n);
  PMSM_to_BLDC_mod1_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S24>/SPI Receive' */
  PMSM_to_BLDC_mod1_DW.obj.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = false;
  PMSM_to_B_SystemCore_setup_oxgk(&PMSM_to_BLDC_mod1_DW.obj);

  /* End of SystemInitialize for SubSystem: '<S5>/Ctrl_Reg_1' */
  /* End of SystemInitialize for SubSystem: '<Root>/SPI_Write' */
  /* SystemInitialize for Atomic SubSystem: '<S50>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_n);

  /* End of SystemInitialize for SubSystem: '<S50>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S50>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_o);

  /* End of SystemInitialize for SubSystem: '<S50>/Bit Shift1' */
  PMSM_to_BLDC__SPIReceive_k_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaevv);
  PMSM_to_BLDC_SPITransmit_d_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnaevv);

  /* End of SystemInitialize for SubSystem: '<S7>/Status_Reg_2_read' */

  /* SystemInitialize for Atomic SubSystem: '<S49>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_p);

  /* End of SystemInitialize for SubSystem: '<S49>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S49>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_j);

  /* End of SystemInitialize for SubSystem: '<S49>/Bit Shift1' */
  PMSM_to_BLDC__SPIReceive_k_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaev);
  PMSM_to_BLDC_SPITransmit_d_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnaev);

  /* End of SystemInitialize for SubSystem: '<S7>/Status_Reg1_read' */

  /* Start for MATLABSystem: '<S16>/Analog to Digital Converter' */
  PMSM_to_BLDC_mod1_DW.obj_d.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj_d.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_SystemCore_setup_o(&PMSM_to_BLDC_mod1_DW.obj_d);

  /* End of SystemInitialize for SubSystem: '<S2>/Subsystem' */
  /* Start for MATLABSystem: '<S19>/Analog to Digital Converter' */
  PMSM_to_BLDC_mod1_DW.obj_o.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted = false;
  PMSM_to_BLD_SystemCore_setup_ox(&PMSM_to_BLDC_mod1_DW.obj_o);

  /* End of SystemInitialize for SubSystem: '<S2>/Subsystem1' */
  /* End of SystemInitialize for SubSystem: '<Root>/Current_sensing' */
  /* SystemInitialize for Enabled SubSystem: '<S35>/Subsystem1' */
  PMSM_to_BLDC__SPIReceive_e_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pn);
  PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pn);

  /* End of SystemInitialize for SubSystem: '<S35>/Subsystem1' */

  /* SystemInitialize for Enabled SubSystem: '<S36>/Subsystem1' */
  PMSM_to_BLDC__SPIReceive_e_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnae);
  PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnae);

  /* End of SystemInitialize for SubSystem: '<S36>/Subsystem1' */

  /* SystemInitialize for Atomic SubSystem: '<S37>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_hq);

  /* End of SystemInitialize for SubSystem: '<S37>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S37>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_p);

  /* End of SystemInitialize for SubSystem: '<S37>/Bit Shift1' */
  PMSM_to_BLDC_mo_SPIReceive_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_p);
  PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_p);

  /* End of SystemInitialize for SubSystem: '<S35>/Subsystem' */

  /* SystemInitialize for Atomic SubSystem: '<S43>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_b);

  /* End of SystemInitialize for SubSystem: '<S43>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S43>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_m);

  /* End of SystemInitialize for SubSystem: '<S43>/Bit Shift1' */
  PMSM_to_BLDC_mo_SPIReceive_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pna);
  PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pna);

  /* End of SystemInitialize for SubSystem: '<S36>/Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/SPI_read' */

  /* Start for If: '<S253>/If' */
  PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem = -1;

  /* Start for SwitchCase: '<S262>/Switch Case' */
  PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for If: '<S259>/If' */
  PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_g = -1;

  /* Start for SwitchCase: '<S261>/Switch Case' */
  PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem_n = -1;

  /* Start for If: '<S364>/If' */
  PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_e = -1;

  /* Start for If: '<S225>/If' */
  PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_c = -1;

  /* Start for If: '<S199>/If' */
  PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_m = -1;

  /* InitializeConditions for Delay: '<S252>/Delay' */
  PMSM_to_BLDC_mod1_DW.icLoad = true;

  /* InitializeConditions for Delay: '<S335>/Delay' */
  PMSM_to_BLDC_mod1_DW.icLoad_f = true;

  /* InitializeConditions for Delay: '<S360>/Delay' */
  PMSM_to_BLDC_mod1_DW.icLoad_a = true;

  /* InitializeConditions for DiscreteIntegrator: '<S174>/Integrator' */
  PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b =
    PMSM_to_BLDC_mod1_ConstB.Constant3_n;

  /* InitializeConditions for Integrator: '<S440>/Integrator' */
  PMSM_to_BLDC_mod1_X.Integrator_CSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S119>/Integrator' */
  PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n = PMSM_to_BLDC_mod1_ConstB.Constant3;

  /* InitializeConditions for Delay: '<S266>/Delay' */
  PMSM_to_BLDC_mod1_DW.icLoad_b = true;

  /* InitializeConditions for Integrator: '<S380>/Int1' */
  PMSM_to_BLDC_mod1_X.Int1_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S395>/Integrator' incorporates:
   *  Integrator: '<S396>/Integrator'
   */
  if (rtmIsFirstInitCond(PMSM_to_BLDC_mod1_M)) {
    PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d = 0.0;
    PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l = 0.0;
  }

  PMSM_to_BLDC_mod1_DW.Integrator_DWORK1 = true;

  /* End of InitializeConditions for Integrator: '<S395>/Integrator' */

  /* InitializeConditions for Integrator: '<S396>/Integrator' */
  PMSM_to_BLDC_mod1_DW.Integrator_DWORK1_g = true;

  /* SystemInitialize for IfAction SubSystem: '<S261>/IntegralMethod' */
  /* InitializeConditions for Delay: '<S342>/Delay' */
  PMSM_to_BLDC_mod1_DW.icLoad_bd = true;

  /* InitializeConditions for Delay: '<S345>/Delay' */
  PMSM_to_BLDC_mod1_DW.icLoad_k = true;

  /* End of SystemInitialize for SubSystem: '<S261>/IntegralMethod' */

  /* SystemInitialize for IfAction SubSystem: '<S261>/OptimizedDifferentiationMethod' */
  /* InitializeConditions for Delay: '<S352>/Delay' */
  PMSM_to_BLDC_mod1_DW.icLoad_b1 = true;

  /* InitializeConditions for Delay: '<S355>/Delay' */
  PMSM_to_BLDC_mod1_DW.icLoad_c = true;

  /* End of SystemInitialize for SubSystem: '<S261>/OptimizedDifferentiationMethod' */

  /* Start for MATLABSystem: '<S459>/PWM Output' */
  PMSM_to_BLDC_mod1_DW.obj_e.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_e.isSetupComplete = false;
  PMSM_to_BLDC_mod1_DW.obj_e.isInitialized = 1;
  PMSM_to_BLD_PWMOutput_setupImpl(&PMSM_to_BLDC_mod1_DW.obj_e);
  PMSM_to_BLDC_mod1_DW.obj_e.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<Root>/Timer' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/En_gate' */
  /* Start for MATLABSystem: '<S22>/Digital Port Write' */
  PMSM_to_BLDC_mod1_DW.obj_ow.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_ow.isInitialized = 1;
  PMSM_to_BLDC_mod1_DW.obj_ow.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<Root>/En_gate' */

  /* Start for MATLABSystem: '<S462>/Analog to Digital Converter' */
  PMSM_to_BLDC_mod1_DW.obj_p.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj_p.matlabCodegenIsDeleted = false;
  PMSM_to__SystemCore_setup_oxgkf(&PMSM_to_BLDC_mod1_DW.obj_p);

  /* ConstCode for Constant: '<S3>/Constant' */
  PMSM_to_BLDC_mod1_B.Constant = 21.76182191997469;

  /* ConstCode for Enabled SubSystem: '<Root>/Timer' */
  /* ConstCode for Gain: '<S59>/Gain2' */
  PMSM_to_BLDC_mod1_B.Gain2_g = 9.55 * PMSM_to_BLDC_mod1_ConstB.Gain4;

  /* ConstCode for Gain: '<S376>/Gain1' incorporates:
   *  Constant: '<S376>/Speed_Angular_Vel'
   */
  PMSM_to_BLDC_mod1_B.Gain1_e = 955.00000000000011;

  /* InitializeConditions for root-level periodic continuous states */
  {
    int_T rootPeriodicContStateIndices[1] = { 1 };

    real_T rootPeriodicContStateRanges[2] = { -3.1415926535897931,
      3.1415926535897931 };

    (void) memcpy((void*)PMSM_to_BLDC_mod1_PeriodicIndX,
                  rootPeriodicContStateIndices,
                  1*sizeof(int_T));
    (void) memcpy((void*)PMSM_to_BLDC_mod1_PeriodicRngX,
                  rootPeriodicContStateRanges,
                  2*sizeof(real_T));
  }

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(PMSM_to_BLDC_mod1_M)) {
    rtmSetFirstInitCond(PMSM_to_BLDC_mod1_M, 0);
  }
}

/* Model terminate function */
void PMSM_to_BLDC_mod1_terminate(void)
{
  uint32_T SPIPinsLoc;

  /* Terminate for Atomic SubSystem: '<Root>/SPI_Write' */
  /* Terminate for Enabled SubSystem: '<S5>/Control_Reg2' */
  /* Terminate for MATLABSystem: '<S23>/SPI Receive' */
  if (!PMSM_to_BLDC_mod1_DW.obj_g.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_g.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_g.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_g.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S23>/SPI Receive' */
  /* Terminate for MATLABSystem: '<S23>/SPI Transmit' */
  if (!PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_j.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S23>/SPI Transmit' */
  /* Terminate for Enabled SubSystem: '<S5>/Ctrl_Reg_1' */
  /* Terminate for MATLABSystem: '<S24>/SPI Transmit' */
  if (!PMSM_to_BLDC_mod1_DW.obj_n.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_n.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_n.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_n.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S24>/SPI Transmit' */
  /* Terminate for MATLABSystem: '<S24>/SPI Receive' */
  if (!PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S24>/SPI Receive' */
  /* End of Terminate for SubSystem: '<S5>/Ctrl_Reg_1' */

  /* Terminate for Enabled SubSystem: '<S7>/Status_Reg_2_read' */
  PMSM_to_BLDC__SPIReceive_c_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaevv);
  PMSM_to_BLDC_SPITransmit_a_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnaevv);

  /* Terminate for Enabled SubSystem: '<S7>/Status_Reg1_read' */
  PMSM_to_BLDC__SPIReceive_c_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaev);
  PMSM_to_BLDC_SPITransmit_a_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnaev);

  /* Terminate for Atomic SubSystem: '<Root>/Current_sensing' */
  /* Terminate for Enabled SubSystem: '<S2>/Subsystem' */
  /* Terminate for MATLABSystem: '<S16>/Analog to Digital Converter' */
  if (!PMSM_to_BLDC_mod1_DW.obj_d.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_d.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_d.isSetupComplete) {
      ADC_Handle_Deinit(PMSM_to_BLDC_mod1_DW.obj_d.ADCHandle, ADC_NORMAL_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S16>/Analog to Digital Converter' */
  /* Terminate for Enabled SubSystem: '<S2>/Subsystem1' */
  /* Terminate for MATLABSystem: '<S19>/Analog to Digital Converter' */
  if (!PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_o.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_o.isSetupComplete) {
      ADC_Handle_Deinit(PMSM_to_BLDC_mod1_DW.obj_o.ADCHandle, ADC_NORMAL_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S19>/Analog to Digital Converter' */
  /* Terminate for Atomic SubSystem: '<Root>/SPI_read' */
  /* Terminate for Enabled SubSystem: '<S35>/Subsystem1' */
  PMSM_to_BLDC__SPIReceive_m_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pn);
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pn);

  /* End of Terminate for SubSystem: '<S35>/Subsystem1' */

  /* Terminate for Enabled SubSystem: '<S36>/Subsystem1' */
  PMSM_to_BLDC__SPIReceive_m_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnae);
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnae);

  /* End of Terminate for SubSystem: '<S36>/Subsystem1' */

  /* Terminate for Enabled SubSystem: '<S35>/Subsystem' */
  PMSM_to_BLDC_mo_SPIReceive_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_p);
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_p);

  /* Terminate for Enabled SubSystem: '<S36>/Subsystem' */
  PMSM_to_BLDC_mo_SPIReceive_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pna);
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pna);

  /* Terminate for MATLABSystem: '<S459>/PWM Output' */
  if (!PMSM_to_BLDC_mod1_DW.obj_e.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_e.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_e.isSetupComplete) {
      disableCounter(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle);
      disableTimerInterrupts(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, 0);
      disableTimerChannel1(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel2(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel3(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, ENABLE_CH_CHN);
    }
  }

  /* End of Terminate for MATLABSystem: '<S459>/PWM Output' */
  /* Terminate for Atomic SubSystem: '<Root>/En_gate' */
  /* Terminate for MATLABSystem: '<S22>/Digital Port Write' */
  if (!PMSM_to_BLDC_mod1_DW.obj_ow.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_ow.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S22>/Digital Port Write' */
  /* End of Terminate for SubSystem: '<Root>/En_gate' */
  /* Terminate for MATLABSystem: '<S462>/Analog to Digital Converter' */
  if (!PMSM_to_BLDC_mod1_DW.obj_p.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_p.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_p.isSetupComplete) {
      ADC_Handle_Deinit(PMSM_to_BLDC_mod1_DW.obj_p.ADCHandle, ADC_NORMAL_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S462>/Analog to Digital Converter' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
