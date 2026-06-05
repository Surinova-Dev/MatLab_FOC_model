/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.c
 *
 * Code generated for Simulink model 'PMSM_to_BLDC_mod1'.
 *
 * Model version                  : 4.1160
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Fri Jun  5 12:36:16 2026
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

/* Named constants for MATLAB Function: '<S24>/bit_shift' */
#define PMSM_to_BLDC_mod1_CALL_EVENT   (-1)

/* Named constants for MATLAB Function: '<S25>/bit_shift' */
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
#define PMSM_to_BLDC_mod1_IN_SPI_write1 (3U)
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
static void PMSM_to_SPIDrvBlock_setupImpl_o(stm32cube_blocks_SPIControl_d_T *obj);
static void PMSM_to_BL_SystemCore_setup_oxg(stm32cube_blocks_SPIControlle_T *obj);
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
 *    '<S22>/Bit Shift'
 *    '<S23>/Bit Shift'
 *    '<S36>/Bit Shift'
 *    '<S42>/Bit Shift'
 *    '<S48>/Bit Shift'
 *    '<S49>/Bit Shift'
 */
void PMSM_to_BLDC_mod1_BitShift_Init(DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* SystemInitialize for MATLAB Function: '<S24>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
}

/*
 * System reset for atomic system:
 *    '<S22>/Bit Shift'
 *    '<S23>/Bit Shift'
 *    '<S36>/Bit Shift'
 *    '<S42>/Bit Shift'
 *    '<S48>/Bit Shift'
 *    '<S49>/Bit Shift'
 */
void PMSM_to_BLDC_mod_BitShift_Reset(DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* SystemReset for MATLAB Function: '<S24>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
}

/*
 * Output and update for atomic system:
 *    '<S22>/Bit Shift'
 *    '<S23>/Bit Shift'
 *    '<S36>/Bit Shift'
 *    '<S42>/Bit Shift'
 *    '<S48>/Bit Shift'
 *    '<S49>/Bit Shift'
 */
void PMSM_to_BLDC_mod1_BitShift(uint16_T rtu_u, uint16_T *rty_y,
  DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* MATLAB Function: '<S24>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
  *rty_y = (uint16_T)(rtu_u << 15);
}

/*
 * System initialize for atomic system:
 *    '<S22>/Bit Shift1'
 *    '<S23>/Bit Shift1'
 *    '<S36>/Bit Shift1'
 *    '<S42>/Bit Shift1'
 *    '<S48>/Bit Shift1'
 *    '<S49>/Bit Shift1'
 */
void PMSM_to_BLDC_mod_BitShift1_Init(DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* SystemInitialize for MATLAB Function: '<S25>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_j;
}

/*
 * System reset for atomic system:
 *    '<S22>/Bit Shift1'
 *    '<S23>/Bit Shift1'
 *    '<S36>/Bit Shift1'
 *    '<S42>/Bit Shift1'
 *    '<S48>/Bit Shift1'
 *    '<S49>/Bit Shift1'
 */
void PMSM_to_BLDC_mo_BitShift1_Reset(DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* SystemReset for MATLAB Function: '<S25>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_j;
}

/*
 * Output and update for atomic system:
 *    '<S22>/Bit Shift1'
 *    '<S23>/Bit Shift1'
 *    '<S36>/Bit Shift1'
 *    '<S42>/Bit Shift1'
 *    '<S48>/Bit Shift1'
 *    '<S49>/Bit Shift1'
 */
void PMSM_to_BLDC_mod1_BitShift1(uint16_T rtu_u, uint16_T *rty_y,
  DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* MATLAB Function: '<S25>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_j;
  *rty_y = (uint16_T)(rtu_u << 11);
}

static void PMSM_to_BLDC_m_SystemCore_setup(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S36>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S36>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S36>/SPI Receive' */
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
  /* Start for MATLABSystem: '<S36>/SPI Receive' */
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

  /* MATLABSystem: '<S36>/SPI Receive' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    MW_SPI_Read_Databits(localDW->obj.MW_SPI_HANDLE, &tmp[0], 15U, 1, 1, 1U);
    LL_GPIO_SetOutputPin(GPIOC, 16384U);
  }

  /* End of MATLABSystem: '<S36>/SPI Receive' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC_mo_SPIReceive_Term(DW_SPIReceive_PMSM_to_BLDC_mo_T *localDW)
{
  /* Terminate for MATLABSystem: '<S36>/SPI Receive' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/SPI Receive' */
}

static void PMSM_to_B_SPIDrvBlock_setupImpl(stm32cube_blocks_SPIControl_d_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;

  /* Start for MATLABSystem: '<S36>/SPI Transmit' */
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S36>/SPI Transmit' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S36>/SPI Transmit' */
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
  /* Start for MATLABSystem: '<S36>/SPI Transmit' */
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

  /* MATLABSystem: '<S36>/SPI Transmit' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    LL_GPIO_ResetOutputPin(GPIOC, 16384U);
    MW_SPI_Write_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0, 1U, 1, 1, 1U);
  }

  /* End of MATLABSystem: '<S36>/SPI Transmit' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC_m_SPITransmit_Term(DW_SPITransmit_PMSM_to_BLDC_m_T *localDW)
{
  /* Terminate for MATLABSystem: '<S36>/SPI Transmit' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/SPI Transmit' */
}

static void PMSM_to_BLDC_SystemCore_setup_n(stm32cube_blocks_SPIControlle_T *obj)
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
  obj->MW_SPI_BlockStruct.dataLength = 1.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
  obj->isSetupComplete = true;
}

/* System initialize for atomic system: */
void PMSM_to_BLDC__SPIReceive_e_Init(DW_SPIReceive_PMSM_to_BLDC__f_T *localDW)
{
  /* Start for MATLABSystem: '<S37>/SPI Receive' */
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

  /* MATLABSystem: '<S37>/SPI Receive' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    MW_SPI_Read_Databits(localDW->obj.MW_SPI_HANDLE, &localB->SPIReceive, 1U, 1,
                         1, 1U);
    LL_GPIO_SetOutputPin(GPIOC, 16384U);
  }

  /* End of MATLABSystem: '<S37>/SPI Receive' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC__SPIReceive_m_Term(DW_SPIReceive_PMSM_to_BLDC__f_T *localDW)
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

static void PMSM_to_BLD_SystemCore_setup_n2(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S48>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S48>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S48>/SPI Receive' */
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
  /* Start for MATLABSystem: '<S48>/SPI Receive' */
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

  /* MATLABSystem: '<S48>/SPI Receive' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    MW_SPI_Read_Databits(localDW->obj.MW_SPI_HANDLE, &localB->SPIReceive[0], 15U,
                         1, 1, 1U);
    LL_GPIO_SetOutputPin(GPIOC, 16384U);
  }

  /* End of MATLABSystem: '<S48>/SPI Receive' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC__SPIReceive_c_Term(DW_SPIReceive_PMSM_to_BLDC_fw_T *localDW)
{
  /* Terminate for MATLABSystem: '<S48>/SPI Receive' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S48>/SPI Receive' */
}

static void PMSM_to_SPIDrvBlock_setupImpl_e(stm32cube_blocks_SPIControl_d_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;

  /* Start for MATLABSystem: '<S48>/SPI Transmit' */
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S48>/SPI Transmit' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S48>/SPI Transmit' */
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
  /* Start for MATLABSystem: '<S48>/SPI Transmit' */
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

  /* MATLABSystem: '<S48>/SPI Transmit' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    LL_GPIO_ResetOutputPin(GPIOC, 16384U);
    MW_SPI_Write_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0, 1U, 1, 1, 1U);
  }

  /* End of MATLABSystem: '<S48>/SPI Transmit' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC_SPITransmit_a_Term(DW_SPITransmit_PMSM_to_BLDC_f_T *localDW)
{
  /* Terminate for MATLABSystem: '<S48>/SPI Transmit' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S48>/SPI Transmit' */
}

/*
 * Output and update for action system:
 *    '<S200>/If Action Subsystem'
 *    '<S225>/If Action Subsystem'
 */
void PMSM_to_BLDC__IfActionSubsystem(real_T rtu_In1, real_T *rty_Out1)
{
  real_T tmp;

  /* DataTypeConversion: '<S203>/Convert_uint16' */
  tmp = floor(rtu_In1);
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

/*
 * Output and update for action system:
 *    '<S200>/If Action Subsystem1'
 *    '<S225>/If Action Subsystem1'
 */
void PMSM_to_BLDC_IfActionSubsystem1(real_T rtu_In1, real_T *rty_Out1)
{
  real_T tmp;

  /* DataTypeConversion: '<S204>/Convert_uint16' */
  tmp = trunc(rtu_In1);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* Sum: '<S204>/Sum' incorporates:
   *  DataTypeConversion: '<S204>/Convert_back'
   *  DataTypeConversion: '<S204>/Convert_uint16'
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

static void PMSM_to_SPIDrvBlock_setupImpl_o(stm32cube_blocks_SPIControl_d_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;

  /* Start for MATLABSystem: '<S22>/SPI Transmit' incorporates:
   *  MATLABSystem: '<S23>/SPI Transmit'
   */
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S22>/SPI Transmit' incorporates:
   *  MATLABSystem: '<S23>/SPI Transmit'
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

  /* Start for MATLABSystem: '<S22>/SPI Transmit' incorporates:
   *  MATLABSystem: '<S23>/SPI Transmit'
   */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 1.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
}

static void PMSM_to_BL_SystemCore_setup_oxg(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S22>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S22>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S22>/SPI Receive' */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 16.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
  obj->isSetupComplete = true;
}

static void PMSM_to_B_SystemCore_setup_oxgk(stm32cube_blocks_SPIControlle_T *obj)
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

  /* Start for MATLABSystem: '<S15>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S15>/Analog to Digital Converter' */
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

  /* Start for MATLABSystem: '<S18>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S18>/Analog to Digital Converter' */
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

  /* Start for MATLABSystem: '<S458>/PWM Output' */
  b.PeripheralPtr = TIM8;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S458>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S458>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

static void PMSM_to__SystemCore_setup_oxgkf(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S461>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S461>/Analog to Digital Converter' */
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
  real_T rtb_DeadZone_m;
  real_T rtb_PhaseCurrent[2];
  GPIO_TypeDef * portNameLoc;
  TIM_TypeDef * timModule;
  uint32_T shiftVal;
  real_T rtb_CCR[6];
  real_T Merge1;
  real_T rtb_Add1_f;
  real_T rtb_Delay2;
  real_T rtb_Merge;
  real_T rtb_Merge1;
  real_T rtb_algDD_o1;
  real_T rtb_algDD_o2;
  int32_T i;
  real32_T rtb_Gain1_m;
  real32_T rtb_Gain_e;
  real32_T rtb_Gain_f;
  real32_T rtb_Sum1_eq;
  real32_T rtb_Sum1_k;
  real32_T rtb_Sum6_n;
  real32_T rtb_Sum_dz;
  real32_T rtb_Sum_h;
  real32_T rtb_Sum_n;
  uint32_T pinMask;
  uint32_T pinWriteLoc;
  uint16_T tmp[16];
  uint16_T y_aa;
  uint16_T y_nb;
  int8_T rtAction;
  int8_T rtPrevAction;
  boolean_T guard1;
  boolean_T tmp_0;
  boolean_T tmp_1;
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
      PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[4] == 0) {
    /* MATLABSystem: '<S461>/Analog to Digital Converter' */
    if (PMSM_to_BLDC_mod1_DW.obj_p.TunablePropsChanged) {
      PMSM_to_BLDC_mod1_DW.obj_p.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S461>/Analog to Digital Converter' */
    regularReadADCNormal(PMSM_to_BLDC_mod1_DW.obj_p.ADCHandle,
                         ADC_TRIGGER_AND_READ,
                         &PMSM_to_BLDC_mod1_B.AnalogtoDigitalConverter);

    /* Gain: '<S8>/Gain' incorporates:
     *  DataTypeConversion: '<S8>/Data Type Conversion'
     */
    PMSM_to_BLDC_mod1_B.Gain = 0.015625 * (real_T)
      PMSM_to_BLDC_mod1_B.AnalogtoDigitalConverter;
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
   *  EnablePort: '<S7>/Enable'
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

    if (PMSM_to_BLDC_mod1_DW.temporalCounter_i3 < 65535U) {
      PMSM_to_BLDC_mod1_DW.temporalCounter_i3++;
    }

    if (PMSM_to_BLDC_mod1_DW.is_active_c3_PMSM_to_BLDC_mod1 == 0) {
      PMSM_to_BLDC_mod1_DW.is_active_c3_PMSM_to_BLDC_mod1 = 1U;
      PMSM_to_BLDC_mod1_DW.is_active_Test2 = 1U;
      PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
      PMSM_to_BLDC_mod1_DW.is_Test2 = PMSM_to_BLDC_mod1_IN_Dummy;
      PMSM_to_BLDC_mod1_DW.is_active_Test = 1U;
      PMSM_to_BLDC_mod1_DW.temporalCounter_i2 = 0U;
      PMSM_to_BLDC_mod1_DW.is_Test = PMSM_to_BLDC__IN_Initialization;
      PMSM_to_BLDC_mod1_DW.CS_val = 1.0;
      PMSM_to_BLDC_mod1_B.En_State = 0.0;
      PMSM_to_BLDC_mod1_DW.is_active_Test2_e = 1U;
      PMSM_to_BLDC_mod1_DW.temporalCounter_i3 = 0U;
      PMSM_to_BLDC_mod1_DW.is_Test2_d = PMSM_to_BLDC_mod1_IN_Dummy;
      PMSM_to_BLDC_mod1_DW.Drv_ok = 0.0;
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

      switch (PMSM_to_BLDC_mod1_DW.is_Test2_d) {
       case PMSM_to_BLDC_mod1_IN_Dummy:
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i3 >= 34000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i3 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test2_d = PMSM_to_BLDC_mod1_IN_SPI_write;
          PMSM_to_BLDC_mod1_B.spi_stat_1 = 1.0;
          PMSM_to_BLDC_mod1_B.spi_stat_2 = 0.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write:
        PMSM_to_BLDC_mod1_B.spi_stat_1 = 1.0;
        PMSM_to_BLDC_mod1_B.spi_stat_2 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i3 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i3 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test2_d = PMSM_to_BLDC_mod1_IN_SPI_write1;
          PMSM_to_BLDC_mod1_B.spi_stat_1 = 0.0;
          PMSM_to_BLDC_mod1_B.spi_stat_2 = 1.0;
        }
        break;

       default:
        /* case IN_SPI_write1: */
        PMSM_to_BLDC_mod1_B.spi_stat_1 = 0.0;
        PMSM_to_BLDC_mod1_B.spi_stat_2 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i3 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i3 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test2_d = PMSM_to_BLDC_mod1_IN_SPI_write;
          PMSM_to_BLDC_mod1_B.spi_stat_1 = 1.0;
          PMSM_to_BLDC_mod1_B.spi_stat_2 = 0.0;
        }
        break;
      }
    }

    /* End of Chart: '<Root>/Chart' */
  }

  if (tmp_0) {
    /* Outputs for Atomic SubSystem: '<Root>/En_gate' */
    /* MATLABSystem: '<S21>/Digital Port Write' */
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

    /* End of MATLABSystem: '<S21>/Digital Port Write' */
    /* End of Outputs for SubSystem: '<Root>/En_gate' */

    /* Outputs for Atomic SubSystem: '<Root>/SPI_Write' */
    /* Logic: '<S4>/AND1' */
    PMSM_to_BLDC_mod1_B.AND1 = ((PMSM_to_BLDC_mod1_B.En_State != 0.0) &&
      (PMSM_to_BLDC_mod1_B.Ctrl_flag2 != 0.0));

    /* Outputs for Enabled SubSystem: '<S4>/Control_Reg2' incorporates:
     *  EnablePort: '<S22>/Enable'
     */
    if (PMSM_to_BLDC_mod1_B.AND1) {
      if (!PMSM_to_BLDC_mod1_DW.Control_Reg2_MODE) {
        /* SystemReset for Atomic SubSystem: '<S22>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift);

        /* End of SystemReset for SubSystem: '<S22>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S22>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1);

        /* End of SystemReset for SubSystem: '<S22>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Control_Reg2_MODE = true;
      }

      /* Outputs for Atomic SubSystem: '<S22>/Bit Shift' */
      /* Constant: '<S22>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(0, &y_aa, &PMSM_to_BLDC_mod1_DW.BitShift);

      /* End of Outputs for SubSystem: '<S22>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S22>/Bit Shift1' */
      /* Constant: '<S22>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(3, &y_nb, &PMSM_to_BLDC_mod1_DW.BitShift1);

      /* End of Outputs for SubSystem: '<S22>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S22>/Bitwise OR' */
      PMSM_to_BLDC_mod1_B.BitwiseOR_n = (uint16_T)(y_aa | y_nb |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_jx);

      /* DataTypeConversion: '<S22>/Data Type Conversion' */
      PMSM_to_BLDC_mod1_B.DataTypeConversion_m = PMSM_to_BLDC_mod1_B.BitwiseOR_n;

      /* MATLABSystem: '<S22>/SPI Transmit' */
      y_aa = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE, 2U,
        3840U, MW_SPI_MODE_3);
      if (y_aa == 0) {
        LL_GPIO_ResetOutputPin(GPIOC, 16384U);
        MW_SPI_Write_Databits(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE,
                              &PMSM_to_BLDC_mod1_B.DataTypeConversion_m, 1U, 1,
                              1, 1000U);
      }

      /* End of MATLABSystem: '<S22>/SPI Transmit' */
      /* MATLABSystem: '<S22>/SPI Receive' */
      y_aa = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_gk.MW_SPI_HANDLE,
        2U, 3840U, MW_SPI_MODE_3);
      if (y_aa == 0) {
        MW_SPI_Read_Databits(PMSM_to_BLDC_mod1_DW.obj_gk.MW_SPI_HANDLE, &tmp[0],
                             16U, 1, 1, 1U);
        LL_GPIO_SetOutputPin(GPIOC, 16384U);
      }

      /* End of MATLABSystem: '<S22>/SPI Receive' */
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC);
    } else {
      PMSM_to_BLDC_mod1_DW.Control_Reg2_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S4>/Control_Reg2' */

    /* Logic: '<S4>/AND' */
    PMSM_to_BLDC_mod1_B.AND = ((PMSM_to_BLDC_mod1_B.En_State != 0.0) &&
      (PMSM_to_BLDC_mod1_B.Ctrl_flag1 != 0.0));

    /* Outputs for Enabled SubSystem: '<S4>/Ctrl_Reg_1' incorporates:
     *  EnablePort: '<S23>/Enable'
     */
    if (PMSM_to_BLDC_mod1_B.AND) {
      if (!PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_MODE) {
        /* SystemReset for Atomic SubSystem: '<S23>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_h);

        /* End of SystemReset for SubSystem: '<S23>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S23>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_d);

        /* End of SystemReset for SubSystem: '<S23>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_MODE = true;
      }

      /* Outputs for Atomic SubSystem: '<S23>/Bit Shift' */
      /* Constant: '<S23>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(0, &y_aa, &PMSM_to_BLDC_mod1_DW.BitShift_h);

      /* End of Outputs for SubSystem: '<S23>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S23>/Bit Shift1' */
      /* Constant: '<S23>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(2, &y_nb, &PMSM_to_BLDC_mod1_DW.BitShift1_d);

      /* End of Outputs for SubSystem: '<S23>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S23>/Bitwise OR' */
      PMSM_to_BLDC_mod1_B.BitwiseOR_e = (uint16_T)(y_aa | y_nb |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_e);

      /* MATLABSystem: '<S23>/SPI Transmit' */
      y_aa = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_n.MW_SPI_HANDLE, 2U,
        3840U, MW_SPI_MODE_3);
      if (y_aa == 0) {
        LL_GPIO_ResetOutputPin(GPIOC, 16384U);
        MW_SPI_Write_Databits(PMSM_to_BLDC_mod1_DW.obj_n.MW_SPI_HANDLE,
                              &PMSM_to_BLDC_mod1_B.BitwiseOR_e, 1U, 1, 1, 10U);
      }

      /* End of MATLABSystem: '<S23>/SPI Transmit' */
      /* MATLABSystem: '<S23>/SPI Receive' */
      y_aa = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_g.MW_SPI_HANDLE, 2U,
        3840U, MW_SPI_MODE_3);
      if (y_aa == 0) {
        MW_SPI_Read_Databits(PMSM_to_BLDC_mod1_DW.obj_g.MW_SPI_HANDLE, &y_aa, 1U,
                             1, 1, 1U);
        LL_GPIO_SetOutputPin(GPIOC, 16384U);
      }

      /* End of MATLABSystem: '<S23>/SPI Receive' */
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC);
    } else {
      PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S4>/Ctrl_Reg_1' */
  }

  if (tmp_1) {
    /* Outputs for Enabled SubSystem: '<S6>/Status_Reg1_read' incorporates:
     *  EnablePort: '<S48>/Ctrl_flag1'
     */
    /* Outputs for Enabled SubSystem: '<S6>/Status_Reg_2_read' incorporates:
     *  EnablePort: '<S49>/Ctrl_flag2'
     */
    tmp_0 = rtsiIsModeUpdateTimeStep(&PMSM_to_BLDC_mod1_M->solverInfo);

    /* End of Outputs for SubSystem: '<S6>/Status_Reg1_read' */
    if (tmp_0) {
      if (PMSM_to_BLDC_mod1_B.spi_stat_2 > 0.0) {
        if (!PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_MODE) {
          /* SystemReset for Atomic SubSystem: '<S49>/Bit Shift' */
          PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_n);

          /* End of SystemReset for SubSystem: '<S49>/Bit Shift' */

          /* SystemReset for Atomic SubSystem: '<S49>/Bit Shift1' */
          PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_o);

          /* End of SystemReset for SubSystem: '<S49>/Bit Shift1' */
          PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_MODE = true;
        }
      } else if (PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_MODE) {
        for (i = 0; i < 15; i++) {
          /* Disable for MATLABSystem: '<S49>/SPI Receive' incorporates:
           *  Outport: '<S49>/Out1'
           */
          PMSM_to_BLDC_mod1_B.SPIReceive_pnaevv.SPIReceive[i] = 0U;
        }

        PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_MODE = false;
      }
    }

    if (PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_MODE) {
      PMSM_to_BLDC_mod1_SPIReceive_pn(&PMSM_to_BLDC_mod1_B.SPIReceive_pnaevv,
        &PMSM_to_BLDC_mod1_DW.SPIReceive_pnaevv);

      /* Outputs for Atomic SubSystem: '<S49>/Bit Shift' */
      /* Constant: '<S49>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(1, &y_aa, &PMSM_to_BLDC_mod1_DW.BitShift_n);

      /* End of Outputs for SubSystem: '<S49>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S49>/Bit Shift1' */
      /* Constant: '<S49>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(1, &y_nb, &PMSM_to_BLDC_mod1_DW.BitShift1_o);

      /* End of Outputs for SubSystem: '<S49>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S49>/Bitwise OR' */
      PMSM_to_BLDC_mod1_B.BitwiseOR = (uint16_T)(y_aa | y_nb |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND);
      PMSM_to_BLDC_mod1_SPITransmit_p(PMSM_to_BLDC_mod1_B.BitwiseOR,
        &PMSM_to_BLDC_mod1_DW.SPITransmit_pnaevv);
      if (tmp_0) {
        srUpdateBC(PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S6>/Status_Reg_2_read' */

    /* Outputs for Enabled SubSystem: '<S6>/Status_Reg1_read' incorporates:
     *  EnablePort: '<S48>/Ctrl_flag1'
     */
    if (tmp_0) {
      if (PMSM_to_BLDC_mod1_B.spi_stat_1 > 0.0) {
        if (!PMSM_to_BLDC_mod1_DW.Status_Reg1_read_MODE) {
          /* SystemReset for Atomic SubSystem: '<S48>/Bit Shift' */
          PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_p);

          /* End of SystemReset for SubSystem: '<S48>/Bit Shift' */

          /* SystemReset for Atomic SubSystem: '<S48>/Bit Shift1' */
          PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_j);

          /* End of SystemReset for SubSystem: '<S48>/Bit Shift1' */
          PMSM_to_BLDC_mod1_DW.Status_Reg1_read_MODE = true;
        }
      } else if (PMSM_to_BLDC_mod1_DW.Status_Reg1_read_MODE) {
        /* Disable for Outport: '<S48>/Out1' incorporates:
         *  MATLABSystem: '<S48>/SPI Receive'
         */
        for (i = 0; i < 15; i++) {
          PMSM_to_BLDC_mod1_B.SPIReceive_pnaev.SPIReceive[i] = 0U;
        }

        /* End of Disable for Outport: '<S48>/Out1' */
        PMSM_to_BLDC_mod1_DW.Status_Reg1_read_MODE = false;
      }
    }

    if (PMSM_to_BLDC_mod1_DW.Status_Reg1_read_MODE) {
      PMSM_to_BLDC_mod1_SPIReceive_pn(&PMSM_to_BLDC_mod1_B.SPIReceive_pnaev,
        &PMSM_to_BLDC_mod1_DW.SPIReceive_pnaev);

      /* Outputs for Atomic SubSystem: '<S48>/Bit Shift' */
      /* Constant: '<S48>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(1, &y_aa, &PMSM_to_BLDC_mod1_DW.BitShift_p);

      /* End of Outputs for SubSystem: '<S48>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S48>/Bit Shift1' */
      /* Constant: '<S48>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(0, &y_nb, &PMSM_to_BLDC_mod1_DW.BitShift1_j);

      /* End of Outputs for SubSystem: '<S48>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S48>/Bitwise OR' */
      PMSM_to_BLDC_mod1_B.BitwiseOR_p = (uint16_T)(y_aa | y_nb |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_m);

      /* DataTypeConversion: '<S48>/Data Type Conversion' */
      PMSM_to_BLDC_mod1_B.DataTypeConversion_d = PMSM_to_BLDC_mod1_B.BitwiseOR_p;
      PMSM_to_BLDC_mod1_SPITransmit_p(PMSM_to_BLDC_mod1_B.DataTypeConversion_d,
        &PMSM_to_BLDC_mod1_DW.SPITransmit_pnaev);
      if (tmp_0) {
        srUpdateBC(PMSM_to_BLDC_mod1_DW.Status_Reg1_read_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S6>/Status_Reg1_read' */
  }

  if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
      PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[5] == 0) {
  }

  if (tmp_1) {
    /* Outputs for Atomic SubSystem: '<Root>/Current_sensing' */
    /* Outputs for Enabled SubSystem: '<S2>/Subsystem' incorporates:
     *  EnablePort: '<S11>/Enable'
     */
    PMSM_to_BLDC_mod1_DW.Subsystem_MODE_n = (PMSM_to_BLDC_mod1_B.Ib_flag > 0.0);

    /* End of Outputs for SubSystem: '<S2>/Subsystem' */
    /* End of Outputs for SubSystem: '<Root>/Current_sensing' */
  }

  /* Outputs for Atomic SubSystem: '<Root>/Current_sensing' */
  /* Outputs for Enabled SubSystem: '<S2>/Subsystem' incorporates:
   *  EnablePort: '<S11>/Enable'
   */
  if (PMSM_to_BLDC_mod1_DW.Subsystem_MODE_n) {
    if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
        PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] == 0) {
      /* MATLABSystem: '<S15>/Analog to Digital Converter' */
      if (PMSM_to_BLDC_mod1_DW.obj_d.TunablePropsChanged) {
        PMSM_to_BLDC_mod1_DW.obj_d.TunablePropsChanged = false;
      }

      regularReadADCNormal(PMSM_to_BLDC_mod1_DW.obj_d.ADCHandle,
                           ADC_TRIGGER_AND_READ, &y_aa);

      /* Gain: '<S11>/Gain' incorporates:
       *  Constant: '<S11>/Constant'
       *  DataTypeConversion: '<S11>/Data Type Conversion'
       *  MATLABSystem: '<S15>/Analog to Digital Converter'
       *  Sum: '<S11>/Add'
       */
      PMSM_to_BLDC_mod1_B.Gain_k = ((real_T)y_aa - 2048.0) * 0.1611328125;
    }

    srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_g);
  }

  /* End of Outputs for SubSystem: '<S2>/Subsystem' */

  /* Outputs for Enabled SubSystem: '<S2>/Subsystem1' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
      PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[3] == 0) {
    PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_b = (PMSM_to_BLDC_mod1_B.Ic_flag > 0.0);
  }

  if (PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_b) {
    if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
        PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] == 0) {
      /* MATLABSystem: '<S18>/Analog to Digital Converter' */
      if (PMSM_to_BLDC_mod1_DW.obj_o.TunablePropsChanged) {
        PMSM_to_BLDC_mod1_DW.obj_o.TunablePropsChanged = false;
      }

      regularReadADCNormal(PMSM_to_BLDC_mod1_DW.obj_o.ADCHandle,
                           ADC_TRIGGER_AND_READ, &y_aa);

      /* Gain: '<S12>/Gain1' incorporates:
       *  Constant: '<S12>/Constant'
       *  DataTypeConversion: '<S12>/Data Type Conversion1'
       *  MATLABSystem: '<S18>/Analog to Digital Converter'
       *  Sum: '<S12>/Add'
       */
      PMSM_to_BLDC_mod1_B.Gain1_m = ((real_T)y_aa - 2048.0) * 0.1611328125;
    }

    srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_c);
  }

  /* End of Outputs for SubSystem: '<S2>/Subsystem1' */
  if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
      PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] == 0) {
    /* MATLABSystem: '<S2>/Lowpass Filter' */
    if (PMSM_to_BLDC_mod1_DW.obj.FilterObj->isInitialized != 1) {
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->isSetupComplete = false;
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->isInitialized = 1;
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->isSetupComplete = true;

      /* System object Initialization function: dsp.SOSFilter */
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W0_ZERO_STATES[0] =
        PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P0_ICRTP;
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W0_ZERO_STATES[1] =
        PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P0_ICRTP;
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W0_ZERO_STATES[2] =
        PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P0_ICRTP;
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W0_ZERO_STATES[3] =
        PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P0_ICRTP;
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W1_POLE_STATES[0] =
        PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P4_IC2RTP;
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W1_POLE_STATES[1] =
        PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P4_IC2RTP;
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W1_POLE_STATES[2] =
        PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P4_IC2RTP;
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W1_POLE_STATES[3] =
        PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P4_IC2RTP;
    }

    /* System object Outputs function: dsp.SOSFilter */
    rtb_Merge = PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P3_RTP3COEFF[0U]
      * 0.0;
    Merge1 = PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P1_RTP1COEFF[0] *
      rtb_Merge;
    Merge1 += PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W0_ZERO_STATES[0] *
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P1_RTP1COEFF[2];
    Merge1 += PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W0_ZERO_STATES[1] *
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P1_RTP1COEFF[4];
    Merge1 -= PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W1_POLE_STATES[0] *
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P2_RTP2COEFF[2];
    Merge1 -= PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W1_POLE_STATES[1] *
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P2_RTP2COEFF[4];
    PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W0_ZERO_STATES[1] =
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W0_ZERO_STATES[0];
    PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W0_ZERO_STATES[0] =
      rtb_Merge;
    PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W1_POLE_STATES[1] =
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W1_POLE_STATES[0];
    PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W1_POLE_STATES[0] = Merge1;
    rtb_Merge = PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P3_RTP3COEFF[1U]
      * Merge1;
    Merge1 = PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P1_RTP1COEFF[1] *
      rtb_Merge;
    Merge1 += PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W0_ZERO_STATES[2] *
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P1_RTP1COEFF[3];
    Merge1 += PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W0_ZERO_STATES[3] *
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P1_RTP1COEFF[5];
    Merge1 -= PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W1_POLE_STATES[2] *
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P2_RTP2COEFF[3];
    Merge1 -= PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W1_POLE_STATES[3] *
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P2_RTP2COEFF[5];
    PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W0_ZERO_STATES[3] =
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W0_ZERO_STATES[2];
    PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W0_ZERO_STATES[2] =
      rtb_Merge;
    PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W1_POLE_STATES[3] =
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W1_POLE_STATES[2];
    PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W1_POLE_STATES[2] = Merge1;

    /* End of MATLABSystem: '<S2>/Lowpass Filter' */

    /* SignalConversion generated from: '<Root>/Delay2' */
    rtb_PhaseCurrent[0] = PMSM_to_BLDC_mod1_B.Gain_k;
    rtb_PhaseCurrent[1] = PMSM_to_BLDC_mod1_B.Gain1_m;

    /* Delay: '<Root>/Delay2' */
    PMSM_to_BLDC_mod1_B.Delay2[0] = PMSM_to_BLDC_mod1_DW.Delay2_DSTATE;
    PMSM_to_BLDC_mod1_B.Delay2[1] = rtb_PhaseCurrent[0];

    /* Outputs for Atomic SubSystem: '<Root>/SPI_read' */
    /* Outputs for Enabled SubSystem: '<S34>/Subsystem1' incorporates:
     *  EnablePort: '<S37>/Ctrl_flag2'
     */
    /* SignalConversion generated from: '<S37>/Ctrl_flag2' incorporates:
     *  Constant: '<S37>/Constant'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write2 > 0.0) {
      PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_m = true;
      PMSM_to_BLDC_mod1_SPIReceive_p(&PMSM_to_BLDC_mod1_B.SPIReceive_pn,
        &PMSM_to_BLDC_mod1_DW.SPIReceive_pn);
      PMSM_to_BLDC_mod1_SPITransmit(36864, &PMSM_to_BLDC_mod1_DW.SPITransmit_pn);
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_n);
    } else if (PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_m) {
      /* Disable for Outport: '<S37>/Out1' incorporates:
       *  MATLABSystem: '<S37>/SPI Receive'
       */
      PMSM_to_BLDC_mod1_B.SPIReceive_pn.SPIReceive = 0U;
      PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_m = false;
    }

    /* End of SignalConversion generated from: '<S37>/Ctrl_flag2' */
    /* End of Outputs for SubSystem: '<S34>/Subsystem1' */

    /* Outputs for Enabled SubSystem: '<S35>/Subsystem1' incorporates:
     *  EnablePort: '<S43>/Enable'
     */
    /* SignalConversion generated from: '<S43>/Enable' incorporates:
     *  Constant: '<S43>/Constant'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write4 > 0.0) {
      PMSM_to_BLDC_mod1_DW.Subsystem1_MODE = true;
      PMSM_to_BLDC_mod1_SPIReceive_p(&PMSM_to_BLDC_mod1_B.SPIReceive_pnae,
        &PMSM_to_BLDC_mod1_DW.SPIReceive_pnae);
      PMSM_to_BLDC_mod1_SPITransmit(38912,
        &PMSM_to_BLDC_mod1_DW.SPITransmit_pnae);
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC);
    } else if (PMSM_to_BLDC_mod1_DW.Subsystem1_MODE) {
      /* Disable for MATLABSystem: '<S43>/SPI Receive' incorporates:
       *  Outport: '<S43>/Out1'
       */
      PMSM_to_BLDC_mod1_B.SPIReceive_pnae.SPIReceive = 0U;
      PMSM_to_BLDC_mod1_DW.Subsystem1_MODE = false;
    }

    /* End of SignalConversion generated from: '<S43>/Enable' */
    /* End of Outputs for SubSystem: '<S35>/Subsystem1' */
    /* RelationalOperator: '<S32>/Compare' incorporates:
     *  Constant: '<S32>/Constant'
     */
    PMSM_to_BLDC_mod1_B.Compare_g =
      (PMSM_to_BLDC_mod1_B.SPIReceive_pn.SPIReceive == 5456);

    /* RelationalOperator: '<S33>/Compare' incorporates:
     *  Constant: '<S33>/Constant'
     */
    PMSM_to_BLDC_mod1_B.Compare_a =
      (PMSM_to_BLDC_mod1_B.SPIReceive_pnae.SPIReceive == 6148);

    /* Outputs for Enabled SubSystem: '<S34>/Subsystem' incorporates:
     *  EnablePort: '<S36>/Enable'
     */
    /* SignalConversion generated from: '<S36>/Enable' incorporates:
     *  Constant: '<S36>/Constant'
     *  Constant: '<S36>/Constant1'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write1 > 0.0) {
      if (!PMSM_to_BLDC_mod1_DW.Subsystem_MODE_f) {
        /* SystemReset for Atomic SubSystem: '<S36>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_hq);

        /* End of SystemReset for SubSystem: '<S36>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S36>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_p);

        /* End of SystemReset for SubSystem: '<S36>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Subsystem_MODE_f = true;
      }

      /* Outputs for Atomic SubSystem: '<S36>/Bit Shift' */
      PMSM_to_BLDC_mod1_BitShift(1, &y_aa, &PMSM_to_BLDC_mod1_DW.BitShift_hq);

      /* End of Outputs for SubSystem: '<S36>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S36>/Bit Shift1' */
      PMSM_to_BLDC_mod1_BitShift1(2, &y_nb, &PMSM_to_BLDC_mod1_DW.BitShift1_p);

      /* End of Outputs for SubSystem: '<S36>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S36>/Bitwise OR' incorporates:
       *  Constant: '<S36>/Constant'
       *  Constant: '<S36>/Constant1'
       */
      PMSM_to_BLDC_mod1_B.BitwiseOR_h = (uint16_T)(y_aa | y_nb |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_d);
      PMSM_to_BLDC_mod1_SPITransmit(PMSM_to_BLDC_mod1_B.BitwiseOR_h,
        &PMSM_to_BLDC_mod1_DW.SPITransmit_p);
      PMSM_to_BLDC_mod1_SPIReceive(&PMSM_to_BLDC_mod1_DW.SPIReceive_p);
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i);
    } else {
      PMSM_to_BLDC_mod1_DW.Subsystem_MODE_f = false;
    }

    /* End of SignalConversion generated from: '<S36>/Enable' */
    /* End of Outputs for SubSystem: '<S34>/Subsystem' */

    /* Outputs for Enabled SubSystem: '<S35>/Subsystem' incorporates:
     *  EnablePort: '<S42>/Enable'
     */
    /* SignalConversion generated from: '<S42>/Enable' incorporates:
     *  Constant: '<S42>/Constant'
     *  Constant: '<S42>/Constant1'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write3 > 0.0) {
      if (!PMSM_to_BLDC_mod1_DW.Subsystem_MODE) {
        /* SystemReset for Atomic SubSystem: '<S42>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_b);

        /* End of SystemReset for SubSystem: '<S42>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S42>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_m);

        /* End of SystemReset for SubSystem: '<S42>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Subsystem_MODE = true;
      }

      /* Outputs for Atomic SubSystem: '<S42>/Bit Shift' */
      PMSM_to_BLDC_mod1_BitShift(1, &y_aa, &PMSM_to_BLDC_mod1_DW.BitShift_b);

      /* End of Outputs for SubSystem: '<S42>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S42>/Bit Shift1' */
      PMSM_to_BLDC_mod1_BitShift1(3, &y_nb, &PMSM_to_BLDC_mod1_DW.BitShift1_m);

      /* End of Outputs for SubSystem: '<S42>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S42>/Bitwise OR' incorporates:
       *  Constant: '<S42>/Constant'
       *  Constant: '<S42>/Constant1'
       */
      PMSM_to_BLDC_mod1_B.BitwiseOR_o = (uint16_T)(y_aa | y_nb |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_j);
      PMSM_to_BLDC_mod1_SPITransmit(PMSM_to_BLDC_mod1_B.BitwiseOR_o,
        &PMSM_to_BLDC_mod1_DW.SPITransmit_pna);
      PMSM_to_BLDC_mod1_SPIReceive(&PMSM_to_BLDC_mod1_DW.SPIReceive_pna);
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_f);
    } else {
      PMSM_to_BLDC_mod1_DW.Subsystem_MODE = false;
    }

    /* End of SignalConversion generated from: '<S42>/Enable' */
    /* End of Outputs for SubSystem: '<S35>/Subsystem' */
    /* End of Outputs for SubSystem: '<Root>/SPI_read' */
  }

  /* End of Outputs for SubSystem: '<Root>/Current_sensing' */

  /* Outputs for Enabled SubSystem: '<Root>/Timer' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (tmp_1 && rtsiIsModeUpdateTimeStep(&PMSM_to_BLDC_mod1_M->solverInfo)) {
    if (PMSM_to_BLDC_mod1_B.FOC_flag > 0.0) {
      if (!PMSM_to_BLDC_mod1_DW.Timer_MODE) {
        (void) memset(&(PMSM_to_BLDC_mod1_XDis.Integrator_CSTATE), 0,
                      4*sizeof(boolean_T));

        /* InitializeConditions for RateTransition: '<S58>/Rate Transition' */
        PMSM_to_BLDC_mod1_DW.RateTransition_Buffer0[0] = 0.0;
        PMSM_to_BLDC_mod1_DW.RateTransition_Buffer0[1] = 0.0;

        /* InitializeConditions for Delay: '<S234>/Delay1' */
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f = 0.0F;

        /* InitializeConditions for Delay: '<S61>/Delay' */
        memset(&PMSM_to_BLDC_mod1_DW.Delay_DSTATE[0], 0, sizeof(real_T) << 3U);

        /* InitializeConditions for Delay: '<S238>/Delay' */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0] = 0.0;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1] = 0.0;

        /* InitializeConditions for Delay: '<S251>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad = true;

        /* InitializeConditions for Delay: '<S334>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_f = true;

        /* InitializeConditions for Delay: '<S358>/Delay' */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj = 0.0;

        /* InitializeConditions for DiscreteIntegrator: '<S303>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE = 0.0;
        PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState = 0;

        /* InitializeConditions for Delay: '<S359>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_a = true;

        /* InitializeConditions for DiscreteIntegrator: '<S175>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b =
          PMSM_to_BLDC_mod1_ConstB.Constant3_n;
        PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState_n = 0;

        /* InitializeConditions for Delay: '<S58>/Delay1' */
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx = 0.0F;

        /* InitializeConditions for Integrator: '<S439>/Integrator' */
        PMSM_to_BLDC_mod1_X.Integrator_CSTATE = 0.0;

        /* InitializeConditions for DiscreteIntegrator: '<S120>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n =
          PMSM_to_BLDC_mod1_ConstB.Constant3;
        PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState_nt = 0;

        /* InitializeConditions for Delay: '<S265>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_b = true;

        /* InitializeConditions for Integrator: '<S379>/Int1' */
        PMSM_to_BLDC_mod1_X.Int1_CSTATE = 0.0;

        /* InitializeConditions for Integrator: '<S394>/Integrator' incorporates:
         *  Integrator: '<S395>/Integrator'
         */
        if (rtmIsFirstInitCond(PMSM_to_BLDC_mod1_M)) {
          PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d = 0.0;
          PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l = 0.0;
        }

        PMSM_to_BLDC_mod1_DW.Integrator_DWORK1 = true;

        /* End of InitializeConditions for Integrator: '<S394>/Integrator' */

        /* InitializeConditions for Integrator: '<S395>/Integrator' */
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

        /* Disable for If: '<S252>/If' */
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem = -1;

        /* Disable for SwitchCase: '<S261>/Switch Case' */
        PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem = -1;

        /* Disable for If: '<S258>/If' */
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&PMSM_to_BLDC_mod1_M->solverInfo, true);
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_g = -1;

        /* Disable for SwitchCase: '<S260>/Switch Case' */
        PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem_n = -1;

        /* Disable for If: '<S363>/If' */
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_e = -1;

        /* Disable for If: '<S225>/If' */
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_c = -1;

        /* Disable for If: '<S200>/If' */
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_m = -1;
        PMSM_to_BLDC_mod1_DW.Timer_MODE = false;
      }
    }
  }

  if (PMSM_to_BLDC_mod1_DW.Timer_MODE) {
    /* RateTransition: '<S58>/Rate Transition' */
    tmp_0 = (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
             PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0);
    if (tmp_0) {
      if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
          PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] == 0) {
        /* RateTransition: '<S58>/Rate Transition' */
        PMSM_to_BLDC_mod1_B.RateTransition[0] =
          PMSM_to_BLDC_mod1_DW.RateTransition_Buffer0[0];
        PMSM_to_BLDC_mod1_B.RateTransition[1] =
          PMSM_to_BLDC_mod1_DW.RateTransition_Buffer0[1];
      }

      /* Saturate: '<S61>/Saturation' incorporates:
       *  Gain: '<S62>/Gain'
       */
      if (-PMSM_to_BLDC_mod1_B.RateTransition[0] > 20.0) {
        /* DataTypeConversion: '<S232>/Data Type  Conversion' */
        PMSM_to_BLDC_mod1_B.DataTypeConversion[0] = 20.0;
      } else if (-PMSM_to_BLDC_mod1_B.RateTransition[0] < -20.0) {
        /* DataTypeConversion: '<S232>/Data Type  Conversion' */
        PMSM_to_BLDC_mod1_B.DataTypeConversion[0] = -20.0;
      } else {
        /* DataTypeConversion: '<S232>/Data Type  Conversion' */
        PMSM_to_BLDC_mod1_B.DataTypeConversion[0] =
          -PMSM_to_BLDC_mod1_B.RateTransition[0];
      }

      if (-PMSM_to_BLDC_mod1_B.RateTransition[1] > 20.0) {
        /* DataTypeConversion: '<S232>/Data Type  Conversion' */
        PMSM_to_BLDC_mod1_B.DataTypeConversion[1] = 20.0;
      } else if (-PMSM_to_BLDC_mod1_B.RateTransition[1] < -20.0) {
        /* DataTypeConversion: '<S232>/Data Type  Conversion' */
        PMSM_to_BLDC_mod1_B.DataTypeConversion[1] = -20.0;
      } else {
        /* DataTypeConversion: '<S232>/Data Type  Conversion' */
        PMSM_to_BLDC_mod1_B.DataTypeConversion[1] =
          -PMSM_to_BLDC_mod1_B.RateTransition[1];
      }

      /* End of Saturate: '<S61>/Saturation' */

      /* Outputs for Atomic SubSystem: '<S79>/Two phase CRL wrap' */
      /* AlgorithmDescriptorDelegate generated from: '<S80>/a16' incorporates:
       *  Gain: '<S80>/one_by_sqrt3'
       *  Sum: '<S80>/a_plus_2b'
       */
      rtb_algDD_o1 = PMSM_to_BLDC_mod1_B.DataTypeConversion[0];
      rtb_algDD_o2 = ((PMSM_to_BLDC_mod1_B.DataTypeConversion[0] +
                       PMSM_to_BLDC_mod1_B.DataTypeConversion[1]) +
                      PMSM_to_BLDC_mod1_B.DataTypeConversion[1]) *
        0.57735026918962584;

      /* End of Outputs for SubSystem: '<S79>/Two phase CRL wrap' */

      /* Delay: '<S234>/Delay1' */
      if (PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE == POS_ZCSIG) {
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f = 0.0F;
      }

      PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE = 0U;

      /* Gain: '<S240>/Gain' incorporates:
       *  Delay: '<S234>/Delay1'
       */
      rtb_Gain_e = -0.0036F * PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f;

      /* Gain: '<S247>/Gain1' incorporates:
       *  DataTypeConversion: '<S68>/Data Type Conversion1'
       *  Delay: '<S61>/Delay'
       */
      rtb_Sum1_eq = 277.777771F * (real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE[1];

      /* Gain: '<S247>/Gain' incorporates:
       *  DataTypeConversion: '<S68>/Data Type Conversion1'
       *  Delay: '<S61>/Delay'
       */
      rtb_Sum1_k = 277.777771F * (real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE[0];

      /* Sum: '<S248>/Sum' incorporates:
       *  Constant: '<S248>/alpha'
       *  Product: '<S248>/Product'
       *  Product: '<S248>/Product2'
       *  UnaryMinus: '<S248>/Unary Minus'
       */
      rtb_Sum_n = -rtb_Gain_e * rtb_Sum1_eq + -3.0F * rtb_Sum1_k;

      /* Sum: '<S248>/Sum1' incorporates:
       *  Constant: '<S248>/alpha'
       *  Product: '<S248>/Product1'
       *  Product: '<S248>/Product3'
       */
      rtb_Sum1_k = rtb_Sum1_eq * -3.0F + rtb_Sum1_k * rtb_Gain_e;

      /* Gain: '<S239>/Gain' incorporates:
       *  Delay: '<S234>/Delay1'
       */
      rtb_Gain_e = -0.0036F * PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f;

      /* Sum: '<S244>/Sum1' incorporates:
       *  Constant: '<S244>/alpha'
       *  DataTypeConversion: '<S68>/Data Type Conversion1'
       *  Delay: '<S61>/Delay'
       *  Product: '<S244>/Product1'
       *  Product: '<S244>/Product3'
       */
      rtb_Sum1_eq = (real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE[3] * -3.0F +
        (real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE[2] * rtb_Gain_e;

      /* Sum: '<S244>/Sum' incorporates:
       *  Constant: '<S244>/alpha'
       *  DataTypeConversion: '<S68>/Data Type Conversion1'
       *  Delay: '<S61>/Delay'
       *  Product: '<S244>/Product'
       *  Product: '<S244>/Product2'
       *  UnaryMinus: '<S244>/Unary Minus'
       */
      rtb_Sum_h = -rtb_Gain_e * (real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE[3] +
        -3.0F * (real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE[2];

      /* Gain: '<S242>/Gain1' */
      rtb_Gain1_m = 277.777771F * rtb_Sum1_eq;

      /* Gain: '<S242>/Gain' */
      rtb_Gain_f = 277.777771F * rtb_Sum_h;

      /* Sum: '<S241>/Sum1' incorporates:
       *  Constant: '<S241>/(Ld-Lq)_Ld'
       *  Constant: '<S241>/R_Ld'
       *  DataTypeConversion: '<S68>/Data Type Conversion1'
       *  Delay: '<S234>/Delay1'
       *  Delay: '<S61>/Delay'
       *  Product: '<S241>/Product'
       *  Product: '<S241>/Product3'
       *  Product: '<S241>/Product5'
       *  UnaryMinus: '<S241>/Unary Minus1'
       */
      rtb_Sum6_n = (real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE[2] *
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f * 0.0F + (real32_T)
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[3] * -10.2777777F;

      /* Sum: '<S241>/Sum' incorporates:
       *  Constant: '<S241>/(Ld-Lq)_Ld'
       *  Constant: '<S241>/R_Ld'
       *  DataTypeConversion: '<S68>/Data Type Conversion1'
       *  Delay: '<S234>/Delay1'
       *  Delay: '<S61>/Delay'
       *  Product: '<S241>/Product1'
       *  Product: '<S241>/Product2'
       *  Product: '<S241>/Product4'
       *  UnaryMinus: '<S241>/Unary Minus'
       *  UnaryMinus: '<S241>/Unary Minus1'
       */
      rtb_Sum_dz = -((real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE[3] *
                     PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f) * 0.0F + (real32_T)
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[2] * -10.2777777F;

      /* Delay: '<S238>/Delay' */
      if (PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE == POS_ZCSIG) {
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0] = 0.0;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1] = 0.0;
      }

      PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE = 0U;

      /* Sum: '<S238>/Sum2' incorporates:
       *  Delay: '<S238>/Delay'
       *  Sum: '<S238>/Sum'
       */
      rtb_Merge = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0];
      rtb_Merge1 = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1];

      /* Gain: '<S238>/Gain2' incorporates:
       *  Constant: '<S245>/alpha'
       *  Constant: '<S246>/alpha'
       *  Delay: '<S234>/Delay1'
       *  Delay: '<S238>/Delay'
       *  Gain: '<S238>/Gain1'
       *  Product: '<S243>/Product'
       *  Product: '<S243>/Product1'
       *  Product: '<S245>/Product'
       *  Product: '<S245>/Product1'
       *  Product: '<S245>/Product2'
       *  Product: '<S245>/Product3'
       *  Product: '<S246>/Product'
       *  Product: '<S246>/Product1'
       *  Product: '<S246>/Product2'
       *  Product: '<S246>/Product3'
       *  Sum: '<S238>/Sum'
       *  Sum: '<S238>/Sum2'
       *  Sum: '<S239>/Sum'
       *  Sum: '<S245>/Sum'
       *  Sum: '<S245>/Sum1'
       *  Sum: '<S246>/Sum'
       *  Sum: '<S246>/Sum1'
       *  UnaryMinus: '<S242>/Unary Minus'
       *  UnaryMinus: '<S242>/Unary Minus1'
       *  UnaryMinus: '<S243>/Unary Minus'
       *  UnaryMinus: '<S245>/Unary Minus'
       *  UnaryMinus: '<S246>/Unary Minus'
       */
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0] = ((((-(rtb_Sum1_eq *
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f) - (-rtb_Gain_e * -rtb_Gain1_m +
        -3.0F * -rtb_Gain_f)) - (-rtb_Gain_e * rtb_Sum6_n + -3.0F * rtb_Sum_dz))
        - rtb_Sum_n) * 5.0E-5F + rtb_Merge) * 0.96;
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1] = ((((rtb_Sum_h *
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f - (-rtb_Gain1_m * -3.0F +
        -rtb_Gain_f * rtb_Gain_e)) - (rtb_Sum6_n * -3.0F + rtb_Sum_dz *
        rtb_Gain_e)) - rtb_Sum1_k) * 5.0E-5F + rtb_Merge1) * 0.96;

      /* Delay: '<S251>/Delay' incorporates:
       *  Constant: '<S236>/IC'
       */
      if (PMSM_to_BLDC_mod1_DW.icLoad) {
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[0] = 0.0;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[1] = 0.0;
      }

      /* Sum: '<S251>/Add1' incorporates:
       *  Delay: '<S238>/Delay'
       *  Delay: '<S251>/Delay'
       *  Product: '<S234>/Product'
       *  Product: '<S251>/Product'
       *  Product: '<S251>/Product1'
       *  Sum: '<S238>/Sum1'
       */
      rtb_Add1[0] = (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0] + rtb_Sum_h) *
        0.045454546809196472 * 0.48519360065807832 +
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[0] * 0.51480639934192163;
      rtb_Add1[1] = (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1] + rtb_Sum1_eq) *
        0.045454546809196472 * 0.48519360065807832 + 0.51480639934192163 *
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[1];

      /* Relay: '<S252>/AlphaRelay' */
      PMSM_to_BLDC_mod1_DW.AlphaRelay_Mode = ((rtb_Add1[0] >= 0.02) ||
        ((!(rtb_Add1[0] <= -0.02)) && PMSM_to_BLDC_mod1_DW.AlphaRelay_Mode));

      /* Relay: '<S252>/BetaRelay' */
      PMSM_to_BLDC_mod1_DW.BetaRelay_Mode = ((rtb_Add1[1] >= 0.02) ||
        ((!(rtb_Add1[1] <= -0.02)) && PMSM_to_BLDC_mod1_DW.BetaRelay_Mode));

      /* Outputs for IfAction SubSystem: '<S261>/If Action Subsystem' incorporates:
       *  ActionPort: '<S355>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S261>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S356>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S252>/Subsystem2' incorporates:
       *  ActionPort: '<S255>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S252>/Subsystem3' incorporates:
       *  ActionPort: '<S256>/Action Port'
       */
      /* Outputs for Triggered SubSystem: '<S252>/Dir_Sense' incorporates:
       *  TriggerPort: '<S254>/Trigger'
       */
      /* If: '<S252>/If' incorporates:
       *  Relay: '<S252>/AlphaRelay'
       *  SwitchCase: '<S261>/Switch Case'
       */
      tmp_1 = rtsiIsModeUpdateTimeStep(&PMSM_to_BLDC_mod1_M->solverInfo);

      /* End of Outputs for SubSystem: '<S252>/Subsystem3' */
      /* End of Outputs for SubSystem: '<S252>/Subsystem2' */
      /* End of Outputs for SubSystem: '<S261>/If Action Subsystem1' */
      /* End of Outputs for SubSystem: '<S261>/If Action Subsystem' */
      if (tmp_1) {
        if (PMSM_to_BLDC_mod1_DW.AlphaRelay_Mode &&
            (PMSM_to_BLDC_mod1_PrevZCX.Dir_Sense_Trig_ZCE != POS_ZCSIG)) {
          /* Switch: '<S254>/Switch' incorporates:
           *  Relay: '<S252>/BetaRelay'
           */
          if (PMSM_to_BLDC_mod1_DW.BetaRelay_Mode) {
            /* Switch: '<S254>/Switch' incorporates:
             *  Constant: '<S254>/Constant'
             */
            PMSM_to_BLDC_mod1_B.Switch = -1;
          } else {
            /* Switch: '<S254>/Switch' incorporates:
             *  Constant: '<S254>/Constant1'
             */
            PMSM_to_BLDC_mod1_B.Switch = 1;
          }

          /* End of Switch: '<S254>/Switch' */
          PMSM_to_BLDC_mod1_DW.Dir_Sense_SubsysRanBC = 4;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Dir_Sense_Trig_ZCE =
          PMSM_to_BLDC_mod1_DW.AlphaRelay_Mode;
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem = (int8_T)
          (PMSM_to_BLDC_mod1_B.Switch <= 0);
      }

      /* End of Outputs for SubSystem: '<S252>/Dir_Sense' */
      guard1 = false;
      if (PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem == 0) {
        /* Outputs for IfAction SubSystem: '<S252>/Subsystem2' incorporates:
         *  ActionPort: '<S255>/Action Port'
         */
        /* UnaryMinus: '<S255>/Unary Minus' */
        rtb_Merge = -rtb_Add1[0];

        /* SignalConversion generated from: '<S255>/SigmaBeta' */
        rtb_Merge1 = rtb_Add1[1];

        /* End of Outputs for SubSystem: '<S252>/Subsystem2' */
        if (tmp_1) {
          /* Outputs for IfAction SubSystem: '<S252>/Subsystem2' incorporates:
           *  ActionPort: '<S255>/Action Port'
           */
          srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem2_SubsysRanBC);

          /* End of Outputs for SubSystem: '<S252>/Subsystem2' */
          guard1 = true;
        }
      } else {
        /* Outputs for IfAction SubSystem: '<S252>/Subsystem3' incorporates:
         *  ActionPort: '<S256>/Action Port'
         */
        /* UnaryMinus: '<S256>/Unary Minus' */
        rtb_Merge1 = -rtb_Add1[1];

        /* SignalConversion generated from: '<S256>/SigmaAlpha' */
        rtb_Merge = rtb_Add1[0];

        /* End of Outputs for SubSystem: '<S252>/Subsystem3' */
        if (tmp_1) {
          /* Outputs for IfAction SubSystem: '<S252>/Subsystem3' incorporates:
           *  ActionPort: '<S256>/Action Port'
           */
          srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem3_SubsysRanBC);

          /* End of Outputs for SubSystem: '<S252>/Subsystem3' */
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

      /* End of If: '<S252>/If' */

      /* SwitchCase: '<S261>/Switch Case' */
      if (PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem == 0) {
        /* Outputs for IfAction SubSystem: '<S261>/If Action Subsystem' incorporates:
         *  ActionPort: '<S355>/Action Port'
         */
        /* Merge: '<S261>/Merge' incorporates:
         *  Constant: '<S261>/Constant'
         *  SignalConversion generated from: '<S355>/In1'
         *  SignalConversion generated from: '<S355>/Out1'
         */
        PMSM_to_BLDC_mod1_B.Merge[0] = 0.0;
        PMSM_to_BLDC_mod1_B.Merge[1] = 0.0;
        if (tmp_1) {
          srUpdateBC(PMSM_to_BLDC_mod1_DW.IfActionSubsystem_SubsysRanBC_a);
        }

        /* End of Outputs for SubSystem: '<S261>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S261>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S356>/Action Port'
         */
        /* Merge: '<S261>/Merge' incorporates:
         *  SignalConversion generated from: '<S356>/In1'
         */
        PMSM_to_BLDC_mod1_B.Merge[0] = rtb_Merge;
        PMSM_to_BLDC_mod1_B.Merge[1] = rtb_Merge1;
        if (tmp_1) {
          srUpdateBC(PMSM_to_BLDC_mod1_DW.IfActionSubsystem1_SubsysRanB_e);
        }

        /* End of Outputs for SubSystem: '<S261>/If Action Subsystem1' */
      }

      /* DeadZone: '<S167>/DeadZone' incorporates:
       *  Product: '<S258>/Product'
       */
      rtb_DeadZone_m = PMSM_to_BLDC_mod1_B.Merge[0] * PMSM_to_BLDC_mod1_B.Merge
        [0];

      /* Product: '<S258>/Product1' */
      rtb_Merge1 = PMSM_to_BLDC_mod1_B.Merge[1] * PMSM_to_BLDC_mod1_B.Merge[1];

      /* Sum: '<S258>/Sum' */
      PMSM_to_BLDC_mod1_B.Sum = rtb_DeadZone_m + rtb_Merge1;

      /* RelationalOperator: '<S266>/Compare' incorporates:
       *  Constant: '<S266>/Constant'
       */
      PMSM_to_BLDC_mod1_B.Compare = (PMSM_to_BLDC_mod1_B.Sum > 0.0);
    }

    /* End of RateTransition: '<S58>/Rate Transition' */

    /* If: '<S258>/If' */
    rtPrevAction = PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_g;

    /* Outputs for IfAction SubSystem: '<S200>/If Action Subsystem' incorporates:
     *  ActionPort: '<S203>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S200>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S204>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S225>/If Action Subsystem' incorporates:
     *  ActionPort: '<S228>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S225>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S229>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S363>/If Action Subsystem' incorporates:
     *  ActionPort: '<S366>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S363>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S367>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S260>/IntegralMethod' incorporates:
     *  ActionPort: '<S324>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S260>/OptimizedDifferentiationMethod' incorporates:
     *  ActionPort: '<S327>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S258>/Subsystem' incorporates:
     *  ActionPort: '<S268>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S258>/If Action Subsystem' incorporates:
     *  ActionPort: '<S267>/Action Port'
     */
    /* If: '<S225>/If' incorporates:
     *  If: '<S200>/If'
     *  If: '<S258>/If'
     *  If: '<S363>/If'
     *  SwitchCase: '<S260>/Switch Case'
     */
    tmp_1 = rtsiIsModeUpdateTimeStep(&PMSM_to_BLDC_mod1_M->solverInfo);

    /* End of Outputs for SubSystem: '<S258>/If Action Subsystem' */
    /* End of Outputs for SubSystem: '<S258>/Subsystem' */
    /* End of Outputs for SubSystem: '<S260>/OptimizedDifferentiationMethod' */
    /* End of Outputs for SubSystem: '<S260>/IntegralMethod' */
    /* End of Outputs for SubSystem: '<S363>/If Action Subsystem1' */
    /* End of Outputs for SubSystem: '<S363>/If Action Subsystem' */
    /* End of Outputs for SubSystem: '<S225>/If Action Subsystem1' */
    /* End of Outputs for SubSystem: '<S225>/If Action Subsystem' */
    /* End of Outputs for SubSystem: '<S200>/If Action Subsystem1' */
    /* End of Outputs for SubSystem: '<S200>/If Action Subsystem' */

    /* If: '<S258>/If' */
    if (tmp_1) {
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
      /* Outputs for IfAction SubSystem: '<S258>/Subsystem' incorporates:
       *  ActionPort: '<S268>/Action Port'
       */
      /* Sqrt: '<S268>/Sqrt' */
      Merge1 = sqrt(PMSM_to_BLDC_mod1_B.Sum);

      /* Merge: '<S258>/Merge' incorporates:
       *  Product: '<S268>/Divide1'
       *  SignalConversion generated from: '<S268>/Out1'
       */
      rtb_Merge = PMSM_to_BLDC_mod1_B.Merge[0] / Merge1;

      /* Merge: '<S258>/Merge1' incorporates:
       *  Product: '<S268>/Divide'
       *  SignalConversion generated from: '<S268>/Out2'
       */
      Merge1 = 1.0 / Merge1 * PMSM_to_BLDC_mod1_B.Merge[1];
      if (tmp_1) {
        srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S258>/Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S258>/If Action Subsystem' incorporates:
       *  ActionPort: '<S267>/Action Port'
       */
      /* Merge: '<S258>/Merge' incorporates:
       *  DataTypeConversion: '<S267>/Data Type Conversion'
       *  SignalConversion generated from: '<S267>/Out1'
       */
      rtb_Merge = PMSM_to_BLDC_mod1_B.Merge[0];

      /* Merge: '<S258>/Merge1' incorporates:
       *  DataTypeConversion: '<S267>/Data Type Conversion1'
       *  SignalConversion generated from: '<S267>/Out2'
       */
      Merge1 = PMSM_to_BLDC_mod1_B.Merge[1];
      if (tmp_1) {
        srUpdateBC(PMSM_to_BLDC_mod1_DW.IfActionSubsystem_SubsysRanBC_b);
      }

      /* End of Outputs for SubSystem: '<S258>/If Action Subsystem' */
    }

    if (tmp_0) {
      /* SwitchCase: '<S260>/Switch Case' incorporates:
       *  Delay: '<S345>/Delay2'
       */
      if (tmp_1) {
        rtAction = 1;
        PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem_n = 1;
      } else {
        rtAction = PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem_n;
      }

      if (rtAction == 0) {
        /* Outputs for IfAction SubSystem: '<S260>/IntegralMethod' incorporates:
         *  ActionPort: '<S324>/Action Port'
         */
        /* Delay: '<S344>/Delay' */
        if (PMSM_to_BLDC_mod1_DW.icLoad_k) {
          /* Sum: '<S344>/Add1' incorporates:
           *  Constant: '<S336>/IC'
           */
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d = 0.0;
        }

        /* Sum: '<S344>/Add1' incorporates:
         *  Delay: '<S344>/Delay'
         *  Product: '<S344>/Product'
         *  Product: '<S344>/Product1'
         *  Switch: '<S344>/Switch'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d = rtb_Merge * 0.95650500031643548 +
          0.043494999683564517 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d;

        /* Delay: '<S337>/Delay1' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_i == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay1_DSTATE = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_i = 0U;

        /* Delay: '<S337>/Delay' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_k == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_k = 0U;

        /* Sum: '<S337>/Sum1' incorporates:
         *  Constant: '<S321>/I1Cnst'
         *  Constant: '<S321>/I2Cnst'
         *  Delay: '<S337>/Delay'
         *  Delay: '<S337>/Delay1'
         *  Product: '<S337>/Product'
         *  Product: '<S337>/Product1'
         *  Sum: '<S337>/Sum'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i =
          (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d +
           PMSM_to_BLDC_mod1_DW.Delay1_DSTATE) * 2.4945142765920684E-5 +
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i * 0.99561142127365465;

        /* Delay: '<S341>/Delay' */
        if (PMSM_to_BLDC_mod1_DW.icLoad_bd) {
          /* Sum: '<S341>/Add1' incorporates:
           *  Constant: '<S335>/IC'
           */
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av = 0.0;
        }

        /* Sum: '<S341>/Add1' incorporates:
         *  Delay: '<S341>/Delay'
         *  Product: '<S341>/Product'
         *  Product: '<S341>/Product1'
         *  Switch: '<S341>/Switch'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av = Merge1 * 0.95650500031643548 +
          0.043494999683564517 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av;

        /* Delay: '<S338>/Delay1' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_p == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_k = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_p = 0U;

        /* Delay: '<S338>/Delay' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_h == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_f = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_h = 0U;

        /* Sum: '<S338>/Sum1' incorporates:
         *  Constant: '<S321>/I1Cnst'
         *  Constant: '<S321>/I2Cnst'
         *  Delay: '<S338>/Delay'
         *  Delay: '<S338>/Delay1'
         *  Product: '<S338>/Product'
         *  Product: '<S338>/Product1'
         *  Sum: '<S338>/Sum'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_f =
          (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av +
           PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_k) * 2.4945142765920684E-5 +
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_f * 0.99561142127365465;

        /* Math: '<S324>/Math Function' incorporates:
         *  Delay: '<S337>/Delay'
         *  Delay: '<S338>/Delay'
         *  Product: '<S324>/Product'
         *  Product: '<S324>/Product1'
         *  Sum: '<S324>/Sum'
         *
         * About '<S324>/Math Function':
         *  Operator: reciprocal
         */
        rtb_Delay2 = 1.0 / (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_f * rtb_Merge -
                            PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i * Merge1);

        /* Switch: '<S324>/Switch1' incorporates:
         *  Abs: '<S324>/Abs'
         */
        if (fabs(rtb_Delay2) > 87964.5943005142) {
          /* Merge: '<S260>/Merge' incorporates:
           *  Constant: '<S324>/Constant'
           */
          rtb_Delay2 = 0.0;
        }

        /* End of Switch: '<S324>/Switch1' */

        /* Update for Delay: '<S344>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_k = false;

        /* Update for Delay: '<S337>/Delay1' */
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d;

        /* Update for Delay: '<S341>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_bd = false;

        /* Update for Delay: '<S338>/Delay1' */
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_k =
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av;
        if (tmp_1) {
          srUpdateBC(PMSM_to_BLDC_mod1_DW.IntegralMethod_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S260>/IntegralMethod' */
      } else {
        /* Outputs for IfAction SubSystem: '<S260>/OptimizedDifferentiationMethod' incorporates:
         *  ActionPort: '<S327>/Action Port'
         */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE == POS_ZCSIG) {
          /* Delay: '<S345>/Delay2' */
          PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_h = 0.0;
        }

        /* Delay: '<S345>/Delay2' */
        PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE = 0U;
        rtb_Delay2 = PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_h;

        /* Delay: '<S345>/Delay3' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay3_DSTATE = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE = 0U;

        /* Delay: '<S354>/Delay' */
        if (PMSM_to_BLDC_mod1_DW.icLoad_c) {
          /* Sum: '<S354>/Add1' incorporates:
           *  Constant: '<S348>/IC'
           */
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_l = 0.0;
        }

        /* Sum: '<S354>/Add1' incorporates:
         *  Delay: '<S354>/Delay'
         *  Product: '<S354>/Product'
         *  Product: '<S354>/Product1'
         *  Switch: '<S354>/Switch'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_l = rtb_Merge * 0.95650500031643548 +
          0.043494999683564517 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_l;

        /* Product: '<S345>/Product' incorporates:
         *  Constant: '<S321>/OD1Cnst'
         *  Delay: '<S345>/Delay2'
         */
        PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_h =
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_l * 2.1991148575128554E+6;

        /* Product: '<S345>/Product1' incorporates:
         *  Constant: '<S321>/OD2Cnst'
         *  Delay: '<S345>/Delay2'
         *  Delay: '<S345>/Delay3'
         *  Sum: '<S345>/Sum1'
         */
        PMSM_to_BLDC_mod1_DW.Delay3_DSTATE =
          ((PMSM_to_BLDC_mod1_DW.Delay3_DSTATE +
            PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_h) - rtb_Delay2) *
          0.0090126024492556654;

        /* Delay: '<S346>/Delay2' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE_l == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_n = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE_l = 0U;
        rtb_Delay2 = PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_n;

        /* Delay: '<S346>/Delay3' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE_m == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_f = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE_m = 0U;

        /* Delay: '<S351>/Delay' */
        if (PMSM_to_BLDC_mod1_DW.icLoad_b1) {
          /* Sum: '<S351>/Add1' incorporates:
           *  Constant: '<S347>/IC'
           */
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aa = 0.0;
        }

        /* Sum: '<S351>/Add1' incorporates:
         *  Delay: '<S351>/Delay'
         *  Product: '<S351>/Product'
         *  Product: '<S351>/Product1'
         *  Switch: '<S351>/Switch'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aa = Merge1 * 0.95650500031643548 +
          0.043494999683564517 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aa;

        /* Product: '<S346>/Product' incorporates:
         *  Constant: '<S321>/OD1Cnst'
         *  Delay: '<S346>/Delay2'
         */
        PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_n =
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aa * 2.1991148575128554E+6;

        /* Product: '<S346>/Product1' incorporates:
         *  Constant: '<S321>/OD2Cnst'
         *  Delay: '<S346>/Delay2'
         *  Delay: '<S346>/Delay3'
         *  Sum: '<S346>/Sum1'
         */
        PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_f =
          ((PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_f +
            PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_n) - rtb_Delay2) *
          0.0090126024492556654;

        /* Merge: '<S260>/Merge' incorporates:
         *  Delay: '<S345>/Delay3'
         *  Delay: '<S346>/Delay3'
         *  Product: '<S327>/Product'
         *  Product: '<S327>/Product1'
         *  Sum: '<S327>/Sum'
         */
        rtb_Delay2 = PMSM_to_BLDC_mod1_DW.Delay3_DSTATE * Merge1 -
          PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_f * rtb_Merge;

        /* Update for Delay: '<S354>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_c = false;

        /* Update for Delay: '<S351>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_b1 = false;
        if (tmp_1) {
          srUpdateBC(PMSM_to_BLDC_mod1_DW.OptimizedDifferentiationMethod_);
        }

        /* End of Outputs for SubSystem: '<S260>/OptimizedDifferentiationMethod' */
      }

      /* DeadZone: '<S167>/DeadZone' incorporates:
       *  Constant: '<S260>/SpdFilterCoeff'
       *  Constant: '<S322>/One'
       *  Sum: '<S322>/Sum'
       */
      rtb_DeadZone_m = 0.99530971347415453;

      /* Switch: '<S322>/Switch1' */
      rtb_Merge1 = rtb_DeadZone_m;

      /* Delay: '<S334>/Delay' incorporates:
       *  Constant: '<S322>/IC'
       */
      if (PMSM_to_BLDC_mod1_DW.icLoad_f) {
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_a = 0.0;
      }

      /* DeadZone: '<S167>/DeadZone' incorporates:
       *  Delay: '<S334>/Delay'
       *  Product: '<S334>/Product1'
       */
      rtb_DeadZone_m = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_a;
      rtb_DeadZone_m *= rtb_Merge1;

      /* Sum: '<S334>/Add1' incorporates:
       *  Product: '<S334>/Product'
       *  Switch: '<S334>/Switch'
       */
      rtb_Add1_e = rtb_Delay2 * 0.0046902865258454489 + rtb_DeadZone_m;

      /* Delay: '<S358>/Delay' */
      if (PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_a == POS_ZCSIG) {
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj = 0.0;
      }

      PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_a = 0U;

      /* If: '<S363>/If' incorporates:
       *  Constant: '<S365>/Constant'
       *  DataTypeConversion: '<S358>/Data Type Conversion3'
       *  Delay: '<S358>/Delay'
       *  RelationalOperator: '<S365>/Compare'
       */
      if (tmp_1) {
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_e = (int8_T)!((real32_T)
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj < 0.0F);
      }

      if (PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_e == 0) {
        /* Outputs for IfAction SubSystem: '<S363>/If Action Subsystem' incorporates:
         *  ActionPort: '<S366>/Action Port'
         */
        /* DataTypeConversion: '<S366>/Convert_uint16' incorporates:
         *  DataTypeConversion: '<S358>/Data Type Conversion3'
         *  Delay: '<S358>/Delay'
         */
        rtb_Gain_e = floorf((real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj);
        if (rtIsNaNF(rtb_Gain_e) || rtIsInfF(rtb_Gain_e)) {
          rtb_Gain_e = 0.0F;
        } else {
          rtb_Gain_e = fmodf(rtb_Gain_e, 65536.0F);
        }

        /* Sum: '<S366>/Sum' incorporates:
         *  DataTypeConversion: '<S358>/Data Type Conversion3'
         *  DataTypeConversion: '<S366>/Convert_back'
         *  DataTypeConversion: '<S366>/Convert_uint16'
         *  Delay: '<S358>/Delay'
         */
        rtb_Sum1_eq = (real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj - (real32_T)
          (rtb_Gain_e < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-rtb_Gain_e
           : (int32_T)(int16_T)(uint16_T)rtb_Gain_e);
        if (tmp_1) {
          srUpdateBC(PMSM_to_BLDC_mod1_DW.IfActionSubsystem_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S363>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S363>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S367>/Action Port'
         */
        /* DataTypeConversion: '<S367>/Convert_uint16' incorporates:
         *  DataTypeConversion: '<S358>/Data Type Conversion3'
         *  Delay: '<S358>/Delay'
         */
        rtb_Gain_e = truncf((real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj);
        if (rtIsNaNF(rtb_Gain_e) || rtIsInfF(rtb_Gain_e)) {
          rtb_Gain_e = 0.0F;
        } else {
          rtb_Gain_e = fmodf(rtb_Gain_e, 65536.0F);
        }

        /* Sum: '<S367>/Sum' incorporates:
         *  DataTypeConversion: '<S358>/Data Type Conversion3'
         *  DataTypeConversion: '<S367>/Convert_back'
         *  DataTypeConversion: '<S367>/Convert_uint16'
         *  Delay: '<S358>/Delay'
         */
        rtb_Sum1_eq = (real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj - (real32_T)
          (rtb_Gain_e < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-rtb_Gain_e
           : (int32_T)(int16_T)(uint16_T)rtb_Gain_e);
        if (tmp_1) {
          srUpdateBC(PMSM_to_BLDC_mod1_DW.IfActionSubsystem1_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S363>/If Action Subsystem1' */
      }

      /* Gain: '<S361>/indexing' */
      rtb_Sum1_eq *= 800.0F;

      /* DataTypeConversion: '<S361>/Get_Integer' */
      rtb_Gain_e = truncf(rtb_Sum1_eq);
      if (rtIsNaNF(rtb_Gain_e) || rtIsInfF(rtb_Gain_e)) {
        rtb_Gain_e = 0.0F;
      } else {
        rtb_Gain_e = fmodf(rtb_Gain_e, 65536.0F);
      }

      y_aa = (uint16_T)(rtb_Gain_e < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                        (uint16_T)-rtb_Gain_e : (int32_T)(uint16_T)rtb_Gain_e);

      /* End of DataTypeConversion: '<S361>/Get_Integer' */

      /* Sum: '<S361>/Sum2' incorporates:
       *  DataTypeConversion: '<S361>/Data Type Conversion1'
       */
      rtb_Gain_e = rtb_Sum1_eq - (real32_T)y_aa;

      /* Sum: '<S253>/Sum' incorporates:
       *  Constant: '<S361>/offset'
       *  Constant: '<S361>/sine_table_values'
       *  DataTypeConversion: '<S358>/Data Type Conversion'
       *  DataTypeConversion: '<S358>/Data Type Conversion1'
       *  Product: '<S253>/Product'
       *  Product: '<S253>/Product1'
       *  Product: '<S362>/Product'
       *  Product: '<S362>/Product1'
       *  Selector: '<S361>/Lookup'
       *  Sum: '<S361>/Sum'
       *  Sum: '<S362>/Sum3'
       *  Sum: '<S362>/Sum4'
       *  Sum: '<S362>/Sum5'
       *  Sum: '<S362>/Sum6'
       */
      rtb_Merge1 = ((PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[(int32_T)
                     (y_aa + 201U)] -
                     PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[(int32_T)
                     (y_aa + 200U)]) * rtb_Gain_e +
                    PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[(int32_T)
                    (y_aa + 200U)]) * rtb_Merge -
        ((PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[(int32_T)(y_aa + 1U)]
          - PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[y_aa]) * rtb_Gain_e
         + PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[y_aa]) * Merge1;

      /* DiscreteIntegrator: '<S303>/Integrator' */
      if (PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState != 0) {
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE = 0.0;
      }

      /* DiscreteIntegrator: '<S303>/Integrator' incorporates:
       *  Gain: '<S300>/Integral Gain'
       */
      PMSM_to_BLDC_mod1_B.Integrator = 0.4 * rtb_Merge1 +
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE;

      /* Sum: '<S253>/Sum1' incorporates:
       *  Gain: '<S308>/Proportional Gain'
       *  Sum: '<S312>/Sum'
       */
      rtb_Merge1 = (150.0 * rtb_Merge1 + PMSM_to_BLDC_mod1_B.Integrator) +
        rtb_Add1_e;

      /* DeadZone: '<S167>/DeadZone' incorporates:
       *  Gain: '<S358>/Gain'
       *  Product: '<S359>/Product'
       */
      rtb_DeadZone_m = 7.9577471545947669E-6 * rtb_Merge1;

      /* Delay: '<S359>/Delay' incorporates:
       *  Constant: '<S359>/InputGain'
       *  Constant: '<S359>/Offset'
       *  Product: '<S359>/Product1'
       *  Sum: '<S359>/Sum1'
       */
      if (PMSM_to_BLDC_mod1_DW.icLoad_a) {
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_ai = 0.0 - rtb_DeadZone_m;
      }

      /* Sum: '<S359>/Sum' incorporates:
       *  Delay: '<S359>/Delay'
       */
      rtb_Switch2 = rtb_DeadZone_m + PMSM_to_BLDC_mod1_DW.Delay_DSTATE_ai;

      /* Switch: '<S359>/Switch1' */
      if (!(rtb_Switch2 > 0.0)) {
        /* Sum: '<S359>/Sum' incorporates:
         *  Constant: '<S359>/Bias1'
         *  Sum: '<S359>/Sum2'
         */
        rtb_Switch2++;
      }

      /* End of Switch: '<S359>/Switch1' */

      /* Switch: '<S359>/Switch2' */
      if (rtb_Switch2 >= 1.0) {
        /* Sum: '<S359>/Sum' incorporates:
         *  Sum: '<S359>/Sum3'
         *  Switch: '<S359>/Switch2'
         */
        rtb_Switch2--;
      }

      /* End of Switch: '<S359>/Switch2' */

      /* Product: '<S359>/Product2' incorporates:
       *  Delay: '<S358>/Delay'
       */
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj = rtb_Switch2;

      /* DataTypeConversion: '<S68>/Data Type Conversion' incorporates:
       *  Delay: '<S358>/Delay'
       *  Gain: '<S253>/PositionGain'
       */
      PMSM_to_BLDC_mod1_B.DataTypeConversion_a = (real32_T)(6.2831853071795862 *
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj);

      /* Math: '<S74>/Mod' incorporates:
       *  Constant: '<S74>/Constant'
       */
      PMSM_to_BLDC_mod1_B.Mod = rt_modd_snf
        (PMSM_to_BLDC_mod1_B.DataTypeConversion_a, 6.282);

      /* Gain: '<S225>/convert_pu' */
      rtb_Delay2 = 0.15915494309189535 * PMSM_to_BLDC_mod1_B.Mod;

      /* If: '<S225>/If' incorporates:
       *  Constant: '<S227>/Constant'
       *  RelationalOperator: '<S227>/Compare'
       */
      if (tmp_1) {
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_c = (int8_T)!(rtb_Delay2 < 0.0);
      }

      if (PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_c == 0) {
        /* Outputs for IfAction SubSystem: '<S225>/If Action Subsystem' incorporates:
         *  ActionPort: '<S228>/Action Port'
         */
        PMSM_to_BLDC__IfActionSubsystem(rtb_Delay2, &rtb_DeadZone_m);
        if (tmp_1) {
          srUpdateBC
            (PMSM_to_BLDC_mod1_DW.IfActionSubsystem_d.IfActionSubsystem_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S225>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S225>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S229>/Action Port'
         */
        PMSM_to_BLDC_IfActionSubsystem1(rtb_Delay2, &rtb_DeadZone_m);
        if (tmp_1) {
          srUpdateBC
            (PMSM_to_BLDC_mod1_DW.IfActionSubsystem1_j.IfActionSubsystem1_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S225>/If Action Subsystem1' */
      }

      /* DeadZone: '<S167>/DeadZone' incorporates:
       *  Gain: '<S223>/indexing'
       */
      rtb_DeadZone_m *= 800.0;

      /* DataTypeConversion: '<S223>/Get_Integer' */
      rtb_Merge = trunc(rtb_DeadZone_m);
      if (rtIsNaN(rtb_Merge) || rtIsInf(rtb_Merge)) {
        rtb_Merge = 0.0;
      } else {
        rtb_Merge = fmod(rtb_Merge, 65536.0);
      }

      y_aa = (uint16_T)(rtb_Merge < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                        -rtb_Merge : (int32_T)(uint16_T)rtb_Merge);

      /* End of DataTypeConversion: '<S223>/Get_Integer' */

      /* Sum: '<S223>/Sum2' incorporates:
       *  DataTypeConversion: '<S223>/Data Type Conversion1'
       */
      rtb_Delay2 = rtb_DeadZone_m - (real_T)y_aa;

      /* Sum: '<S224>/Sum4' incorporates:
       *  Constant: '<S223>/offset'
       *  Constant: '<S223>/sine_table_values'
       *  Product: '<S224>/Product'
       *  Selector: '<S223>/Lookup'
       *  Sum: '<S223>/Sum'
       *  Sum: '<S224>/Sum3'
       */
      rtb_Merge = (PMSM_to_BLDC_mod1_ConstP.pooled16[(int32_T)(y_aa + 1U)] -
                   PMSM_to_BLDC_mod1_ConstP.pooled16[y_aa]) * rtb_Delay2 +
        PMSM_to_BLDC_mod1_ConstP.pooled16[y_aa];

      /* Sum: '<S224>/Sum6' incorporates:
       *  Constant: '<S223>/offset'
       *  Constant: '<S223>/sine_table_values'
       *  Product: '<S224>/Product1'
       *  Selector: '<S223>/Lookup'
       *  Sum: '<S223>/Sum'
       *  Sum: '<S224>/Sum5'
       */
      rtb_Delay2 = (PMSM_to_BLDC_mod1_ConstP.pooled16[(int32_T)(y_aa + 201U)] -
                    PMSM_to_BLDC_mod1_ConstP.pooled16[(int32_T)(y_aa + 200U)]) *
        rtb_Delay2 + PMSM_to_BLDC_mod1_ConstP.pooled16[(int32_T)(y_aa + 200U)];

      /* Outputs for Atomic SubSystem: '<S219>/Two inputs CRL' */
      /* AlgorithmDescriptorDelegate generated from: '<S221>/a16' incorporates:
       *  Product: '<S221>/acos'
       *  Product: '<S221>/bsin'
       *  Sum: '<S221>/sum_Ds'
       */
      PMSM_to_BLDC_mod1_B.algDD_o1 = rtb_algDD_o1 * rtb_Delay2 + rtb_algDD_o2 *
        rtb_Merge;

      /* AlgorithmDescriptorDelegate generated from: '<S221>/a16' incorporates:
       *  Product: '<S221>/asin'
       *  Product: '<S221>/bcos'
       *  Sum: '<S221>/sum_Qs'
       */
      PMSM_to_BLDC_mod1_B.algDD_o2 = rtb_algDD_o2 * rtb_Delay2 - rtb_algDD_o1 *
        rtb_Merge;

      /* End of Outputs for SubSystem: '<S219>/Two inputs CRL' */

      /* Sum: '<S82>/Sum' */
      rtb_Delay2 = PMSM_to_BLDC_mod1_B.algDD_o1 - PMSM_to_BLDC_mod1_B.Constant;

      /* DiscreteIntegrator: '<S175>/Integrator' */
      PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b =
        PMSM_to_BLDC_mod1_ConstB.Constant3_n;

      /* DeadZone: '<S167>/DeadZone' incorporates:
       *  Constant: '<S82>/Constant'
       *  DiscreteIntegrator: '<S175>/Integrator'
       *  Product: '<S180>/PProd Out'
       *  Sum: '<S184>/Sum'
       */
      rtb_DeadZone_m = rtb_Delay2 * 45.216 +
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b;

      /* Saturate: '<S182>/Saturation' */
      if (rtb_DeadZone_m > 1.0) {
        /* Saturate: '<S182>/Saturation' */
        PMSM_to_BLDC_mod1_B.Saturation = 1.0;
      } else if (rtb_DeadZone_m < -1.0) {
        /* Saturate: '<S182>/Saturation' */
        PMSM_to_BLDC_mod1_B.Saturation = -1.0;
      } else {
        /* Saturate: '<S182>/Saturation' */
        PMSM_to_BLDC_mod1_B.Saturation = rtb_DeadZone_m;
      }

      /* End of Saturate: '<S182>/Saturation' */

      /* Delay: '<S58>/Delay1' */
      PMSM_to_BLDC_mod1_B.W_mes = PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx;

      /* DataTypeConversion: '<S65>/Data Type Conversion1' incorporates:
       *  Sum: '<S65>/Add'
       */
      PMSM_to_BLDC_mod1_B.DataTypeConversion1 =
        PMSM_to_BLDC_mod1_B.DataTypeConversion_i - PMSM_to_BLDC_mod1_B.W_mes;

      /* Gain: '<S444>/Proportional Gain' */
      PMSM_to_BLDC_mod1_B.ProportionalGain = 1.3024091804638622 *
        PMSM_to_BLDC_mod1_B.DataTypeConversion1;
    }

    /* Sum: '<S448>/Sum' incorporates:
     *  Integrator: '<S439>/Integrator'
     */
    PMSM_to_BLDC_mod1_B.Sum_o = PMSM_to_BLDC_mod1_B.ProportionalGain +
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE;

    /* Sum: '<S81>/Sum' */
    rtb_algDD_o2 = PMSM_to_BLDC_mod1_B.algDD_o2 - PMSM_to_BLDC_mod1_B.Sum_o;
    if (tmp_0) {
      /* DiscreteIntegrator: '<S120>/Integrator' */
      PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n =
        PMSM_to_BLDC_mod1_ConstB.Constant3;

      /* Sum: '<S129>/Sum' incorporates:
       *  Constant: '<S81>/Constant'
       *  DiscreteIntegrator: '<S120>/Integrator'
       *  Product: '<S125>/PProd Out'
       */
      Merge1 = rtb_algDD_o2 * 45.216 + PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n;

      /* Saturate: '<S127>/Saturation' */
      if (Merge1 > 1.0) {
        /* Saturate: '<S127>/Saturation' */
        PMSM_to_BLDC_mod1_B.Saturation_f = 1.0;
      } else if (Merge1 < -1.0) {
        /* Saturate: '<S127>/Saturation' */
        PMSM_to_BLDC_mod1_B.Saturation_f = -1.0;
      } else {
        /* Saturate: '<S127>/Saturation' */
        PMSM_to_BLDC_mod1_B.Saturation_f = Merge1;
      }

      /* End of Saturate: '<S127>/Saturation' */

      /* Gain: '<S200>/convert_pu' */
      rtb_algDD_o1 = 0.15915494309189535 * PMSM_to_BLDC_mod1_B.Mod;

      /* If: '<S200>/If' incorporates:
       *  Constant: '<S202>/Constant'
       *  RelationalOperator: '<S202>/Compare'
       */
      if (tmp_1) {
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_m = (int8_T)!(rtb_algDD_o1 < 0.0);
      }

      if (PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_m == 0) {
        /* Outputs for IfAction SubSystem: '<S200>/If Action Subsystem' incorporates:
         *  ActionPort: '<S203>/Action Port'
         */
        PMSM_to_BLDC__IfActionSubsystem(rtb_algDD_o1, &rtb_Add1_f);
        if (tmp_1) {
          srUpdateBC
            (PMSM_to_BLDC_mod1_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S200>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S200>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S204>/Action Port'
         */
        PMSM_to_BLDC_IfActionSubsystem1(rtb_algDD_o1, &rtb_Add1_f);
        if (tmp_1) {
          srUpdateBC
            (PMSM_to_BLDC_mod1_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S200>/If Action Subsystem1' */
      }

      /* Sum: '<S209>/Add1' incorporates:
       *  Gain: '<S198>/indexing'
       */
      rtb_Add1_f *= 800.0;

      /* DataTypeConversion: '<S198>/Get_Integer' */
      rtb_Merge = trunc(rtb_Add1_f);
      if (rtIsNaN(rtb_Merge) || rtIsInf(rtb_Merge)) {
        rtb_Merge = 0.0;
      } else {
        rtb_Merge = fmod(rtb_Merge, 65536.0);
      }

      y_aa = (uint16_T)(rtb_Merge < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                        -rtb_Merge : (int32_T)(uint16_T)rtb_Merge);

      /* End of DataTypeConversion: '<S198>/Get_Integer' */

      /* Sum: '<S198>/Sum2' incorporates:
       *  DataTypeConversion: '<S198>/Data Type Conversion1'
       */
      rtb_Merge = rtb_Add1_f - (real_T)y_aa;

      /* Sum: '<S199>/Sum4' incorporates:
       *  Constant: '<S198>/offset'
       *  Constant: '<S198>/sine_table_values'
       *  Product: '<S199>/Product'
       *  Selector: '<S198>/Lookup'
       *  Sum: '<S198>/Sum'
       *  Sum: '<S199>/Sum3'
       */
      rtb_algDD_o1 = (PMSM_to_BLDC_mod1_ConstP.pooled16[(int32_T)(y_aa + 1U)] -
                      PMSM_to_BLDC_mod1_ConstP.pooled16[y_aa]) * rtb_Merge +
        PMSM_to_BLDC_mod1_ConstP.pooled16[y_aa];

      /* Sum: '<S199>/Sum6' incorporates:
       *  Constant: '<S198>/offset'
       *  Constant: '<S198>/sine_table_values'
       *  Product: '<S199>/Product1'
       *  Selector: '<S198>/Lookup'
       *  Sum: '<S198>/Sum'
       *  Sum: '<S199>/Sum5'
       */
      rtb_Merge = (PMSM_to_BLDC_mod1_ConstP.pooled16[(int32_T)(y_aa + 201U)] -
                   PMSM_to_BLDC_mod1_ConstP.pooled16[(int32_T)(y_aa + 200U)]) *
        rtb_Merge + PMSM_to_BLDC_mod1_ConstP.pooled16[(int32_T)(y_aa + 200U)];

      /* Outputs for Atomic SubSystem: '<S195>/Two inputs CRL' */
      /* AlgorithmDescriptorDelegate generated from: '<S197>/a16' incorporates:
       *  Product: '<S197>/dcos'
       *  Product: '<S197>/qsin'
       *  Sum: '<S197>/sum_alpha'
       */
      PMSM_to_BLDC_mod1_B.algDD_o1_d = PMSM_to_BLDC_mod1_B.Saturation *
        rtb_Merge - PMSM_to_BLDC_mod1_B.Saturation_f * rtb_algDD_o1;

      /* AlgorithmDescriptorDelegate generated from: '<S197>/a16' incorporates:
       *  Product: '<S197>/dsin'
       *  Product: '<S197>/qcos'
       *  Sum: '<S197>/sum_beta'
       */
      PMSM_to_BLDC_mod1_B.algDD_o2_a = PMSM_to_BLDC_mod1_B.Saturation_f *
        rtb_Merge + PMSM_to_BLDC_mod1_B.Saturation * rtb_algDD_o1;

      /* End of Outputs for SubSystem: '<S195>/Two inputs CRL' */

      /* Gain: '<S216>/one_by_two' */
      rtb_Merge = 0.5 * PMSM_to_BLDC_mod1_B.algDD_o1_d;

      /* Gain: '<S216>/sqrt3_by_two' */
      rtb_algDD_o1 = 0.8660254037844386 * PMSM_to_BLDC_mod1_B.algDD_o2_a;

      /* Sum: '<S209>/Add1' incorporates:
       *  Sum: '<S216>/add_b'
       */
      rtb_Add1_f = rtb_algDD_o1 - rtb_Merge;

      /* Sum: '<S216>/add_c' */
      rtb_Merge = (0.0 - rtb_Merge) - rtb_algDD_o1;

      /* Gain: '<S210>/one_by_two' incorporates:
       *  MinMax: '<S210>/Max'
       *  MinMax: '<S210>/Min'
       *  Sum: '<S210>/Add'
       */
      rtb_algDD_o1 = (fmax(fmax(PMSM_to_BLDC_mod1_B.algDD_o1_d, rtb_Add1_f),
                           rtb_Merge) + fmin(fmin(PMSM_to_BLDC_mod1_B.algDD_o1_d,
        rtb_Add1_f), rtb_Merge)) * -0.5;

      /* Gain: '<S209>/Gain' incorporates:
       *  Sum: '<S209>/Add1'
       *  Sum: '<S209>/Add2'
       *  Sum: '<S209>/Add3'
       */
      PMSM_to_BLDC_mod1_B.Gain_p[0] = (PMSM_to_BLDC_mod1_B.algDD_o1_d +
        rtb_algDD_o1) * 1.1547005383792517;
      PMSM_to_BLDC_mod1_B.Gain_p[1] = (rtb_Add1_f + rtb_algDD_o1) *
        1.1547005383792517;
      PMSM_to_BLDC_mod1_B.Gain_p[2] = (rtb_algDD_o1 + rtb_Merge) *
        1.1547005383792517;

      /* Gain: '<S67>/Gain' incorporates:
       *  Constant: '<S67>/Constant'
       *  Sum: '<S67>/Add'
       */
      rtb_algDD_o1 = (PMSM_to_BLDC_mod1_B.Gain_p[0] + 1.45) *
        0.33333333333333331;
      PMSM_to_BLDC_mod1_B.Gain_f[0] = rtb_algDD_o1;

      /* Gain: '<S372>/Gain5' incorporates:
       *  Constant: '<S372>/Constant1'
       *  Gain: '<S371>/Gain1'
       *  Sum: '<S372>/Add'
       */
      PMSM_to_BLDC_mod1_B.Gain5[0] = -rtb_algDD_o1 + 1.0;

      /* Gain: '<S67>/Gain' incorporates:
       *  Constant: '<S67>/Constant'
       *  Sum: '<S67>/Add'
       */
      rtb_algDD_o1 = (PMSM_to_BLDC_mod1_B.Gain_p[1] + 1.45) *
        0.33333333333333331;
      PMSM_to_BLDC_mod1_B.Gain_f[1] = rtb_algDD_o1;

      /* Gain: '<S372>/Gain5' incorporates:
       *  Constant: '<S372>/Constant1'
       *  Gain: '<S371>/Gain1'
       *  Sum: '<S372>/Add'
       */
      PMSM_to_BLDC_mod1_B.Gain5[1] = -rtb_algDD_o1 + 1.0;

      /* Gain: '<S67>/Gain' incorporates:
       *  Constant: '<S67>/Constant'
       *  Sum: '<S67>/Add'
       */
      rtb_algDD_o1 = (PMSM_to_BLDC_mod1_B.Gain_p[2] + 1.45) *
        0.33333333333333331;
      PMSM_to_BLDC_mod1_B.Gain_f[2] = rtb_algDD_o1;

      /* Gain: '<S372>/Gain5' incorporates:
       *  Constant: '<S372>/Constant1'
       *  Gain: '<S371>/Gain1'
       *  Sum: '<S372>/Add'
       */
      PMSM_to_BLDC_mod1_B.Gain5[2] = -rtb_algDD_o1 + 1.0;

      /* SignalConversion generated from: '<S63>/Codegen' */
      PMSM_to_BLDC_mod1_B.Gate_pulse[0] = PMSM_to_BLDC_mod1_B.Gain_f[0];
      PMSM_to_BLDC_mod1_B.Gate_pulse[1] = PMSM_to_BLDC_mod1_B.Gain5[0];
      PMSM_to_BLDC_mod1_B.Gate_pulse[2] = PMSM_to_BLDC_mod1_B.Gain_f[1];
      PMSM_to_BLDC_mod1_B.Gate_pulse[3] = PMSM_to_BLDC_mod1_B.Gain5[1];
      PMSM_to_BLDC_mod1_B.Gate_pulse[4] = PMSM_to_BLDC_mod1_B.Gain_f[2];
      PMSM_to_BLDC_mod1_B.Gate_pulse[5] = PMSM_to_BLDC_mod1_B.Gain5[2];

      /* Gain: '<S60>/CCR' */
      for (i = 0; i < 6; i++) {
        rtb_CCR[i] = 4096.0 * PMSM_to_BLDC_mod1_B.Gate_pulse[i];
      }

      /* End of Gain: '<S60>/CCR' */

      /* MATLABSystem: '<S458>/PWM Output' */
      timModule = TIM8;

      /* DataTypeConversion: '<S60>/Data Type Conversion' */
      rtb_Merge = floor(rtb_CCR[0]);
      if (rtIsNaN(rtb_Merge) || rtIsInf(rtb_Merge)) {
        rtb_Merge = 0.0;
      } else {
        rtb_Merge = fmod(rtb_Merge, 65536.0);
      }

      /* MATLABSystem: '<S458>/PWM Output' incorporates:
       *  DataTypeConversion: '<S60>/Data Type Conversion'
       */
      pinWriteLoc = checkFrequencyAndDutyCycleLimits
        (PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, (uint32_T)(rtb_Merge < 0.0 ?
          (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Merge : (int32_T)(uint16_T)
          rtb_Merge));
      setDutyCycleChannel1(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, pinWriteLoc);
      shiftVal = LL_TIM_CHANNEL_CH1N;
      if (PMSM_to_BLDC_mod1_ConstB.DataTypeConversion_j) {
        LL_TIM_CC_EnableChannel(timModule, shiftVal);
      } else {
        LL_TIM_CC_DisableChannel(timModule, shiftVal);
      }

      /* DataTypeConversion: '<S60>/Data Type Conversion2' */
      rtb_Merge = floor(rtb_CCR[2]);
      if (rtIsNaN(rtb_Merge) || rtIsInf(rtb_Merge)) {
        rtb_Merge = 0.0;
      } else {
        rtb_Merge = fmod(rtb_Merge, 65536.0);
      }

      /* MATLABSystem: '<S458>/PWM Output' incorporates:
       *  DataTypeConversion: '<S60>/Data Type Conversion2'
       */
      pinWriteLoc = checkFrequencyAndDutyCycleLimits
        (PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, (uint32_T)(rtb_Merge < 0.0 ?
          (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Merge : (int32_T)(uint16_T)
          rtb_Merge));
      setDutyCycleChannel2(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, pinWriteLoc);
      shiftVal = LL_TIM_CHANNEL_CH2N;
      if (PMSM_to_BLDC_mod1_ConstB.DataTypeConversion_j) {
        LL_TIM_CC_EnableChannel(timModule, shiftVal);
      } else {
        LL_TIM_CC_DisableChannel(timModule, shiftVal);
      }

      /* DataTypeConversion: '<S60>/Data Type Conversion4' */
      rtb_Merge = floor(rtb_CCR[4]);
      if (rtIsNaN(rtb_Merge) || rtIsInf(rtb_Merge)) {
        rtb_Merge = 0.0;
      } else {
        rtb_Merge = fmod(rtb_Merge, 65536.0);
      }

      /* MATLABSystem: '<S458>/PWM Output' incorporates:
       *  DataTypeConversion: '<S60>/Data Type Conversion4'
       */
      pinWriteLoc = checkFrequencyAndDutyCycleLimits
        (PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, (uint32_T)(rtb_Merge < 0.0 ?
          (int32_T)(uint16_T)-(int16_T)(uint16_T)-rtb_Merge : (int32_T)(uint16_T)
          rtb_Merge));
      setDutyCycleChannel3(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, pinWriteLoc);
      shiftVal = LL_TIM_CHANNEL_CH3N;
      if (PMSM_to_BLDC_mod1_ConstB.DataTypeConversion_j) {
        LL_TIM_CC_EnableChannel(timModule, shiftVal);
      } else {
        LL_TIM_CC_DisableChannel(timModule, shiftVal);
      }

      setMOEBitAccToInput(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle,
                          PMSM_to_BLDC_mod1_ConstB.DataTypeConversion_j);

      /* Product: '<S265>/Product' */
      rtb_Merge1 *= 0.0046902865258454489;

      /* Delay: '<S265>/Delay' incorporates:
       *  Constant: '<S257>/IC'
       */
      if (PMSM_to_BLDC_mod1_DW.icLoad_b) {
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_g = 0.0;
      }

      /* Sum: '<S265>/Add1' incorporates:
       *  Delay: '<S265>/Delay'
       *  Product: '<S265>/Product1'
       */
      rtb_Add1_d = 0.99530971347415453 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_g +
        rtb_Merge1;

      /* Gain: '<S253>/FreqGain' incorporates:
       *  Delay: '<S234>/Delay1'
       */
      PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f = (real32_T)rtb_Add1_d;

      /* Gain: '<S234>/SpeedGain' incorporates:
       *  Delay: '<S234>/Delay1'
       */
      PMSM_to_BLDC_mod1_B.SpeedGain = 0.142857149F *
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f;

      /* Gain: '<S58>/Gain3' */
      PMSM_to_BLDC_mod1_B.Gain3 = 9.55F * PMSM_to_BLDC_mod1_B.SpeedGain;

      /* SignalConversion generated from: '<S58>/Speed_controls' */
      PMSM_to_BLDC_mod1_B.idq_ref[0] = PMSM_to_BLDC_mod1_B.Constant;
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

      /* SignalConversion generated from: '<S61>/Delay' */
      PMSM_to_BLDC_mod1_B.TmpSignalConversionAtDelayInpor[0] =
        PMSM_to_BLDC_mod1_B.algDD_o1_d;
      PMSM_to_BLDC_mod1_B.TmpSignalConversionAtDelayInpor[1] =
        PMSM_to_BLDC_mod1_B.algDD_o2_a;
      PMSM_to_BLDC_mod1_B.TmpSignalConversionAtDelayInpor[2] =
        PMSM_to_BLDC_mod1_B.DataTypeConversion_e;
      PMSM_to_BLDC_mod1_B.TmpSignalConversionAtDelayInpor[3] =
        PMSM_to_BLDC_mod1_B.DataTypeConversion1_i;

      /* DeadZone: '<S112>/DeadZone' */
      if (Merge1 > 1.0) {
        Merge1--;
      } else if (Merge1 >= -1.0) {
        Merge1 = 0.0;
      } else {
        Merge1++;
      }

      /* End of DeadZone: '<S112>/DeadZone' */

      /* Product: '<S117>/IProd Out' incorporates:
       *  Constant: '<S81>/Constant1'
       */
      rtb_algDD_o1 = rtb_algDD_o2 * 0.23235999999999998;

      /* Switch: '<S110>/Switch1' incorporates:
       *  Constant: '<S110>/Clamping_zero'
       *  Constant: '<S110>/Constant'
       *  Constant: '<S110>/Constant2'
       *  RelationalOperator: '<S110>/fix for DT propagation issue'
       */
      if (Merge1 > 0.0) {
        rtPrevAction = 1;
      } else {
        rtPrevAction = -1;
      }

      /* Switch: '<S110>/Switch2' incorporates:
       *  Constant: '<S110>/Clamping_zero'
       *  Constant: '<S110>/Constant3'
       *  Constant: '<S110>/Constant4'
       *  RelationalOperator: '<S110>/fix for DT propagation issue1'
       */
      if (rtb_algDD_o1 > 0.0) {
        rtAction = 1;
      } else {
        rtAction = -1;
      }

      /* Switch: '<S110>/Switch' incorporates:
       *  Constant: '<S110>/Clamping_zero'
       *  Logic: '<S110>/AND3'
       *  RelationalOperator: '<S110>/Equal1'
       *  RelationalOperator: '<S110>/Relational Operator'
       *  Switch: '<S110>/Switch1'
       *  Switch: '<S110>/Switch2'
       */
      if ((Merge1 != 0.0) && (rtPrevAction == rtAction)) {
        /* Switch: '<S110>/Switch' incorporates:
         *  Constant: '<S110>/Constant1'
         */
        rtb_Switch = 0.0;
      } else {
        /* Switch: '<S110>/Switch' */
        rtb_Switch = rtb_algDD_o1;
      }

      /* End of Switch: '<S110>/Switch' */

      /* DeadZone: '<S167>/DeadZone' */
      if (rtb_DeadZone_m > 1.0) {
        /* DeadZone: '<S167>/DeadZone' */
        rtb_DeadZone_m--;
      } else if (rtb_DeadZone_m >= -1.0) {
        /* DeadZone: '<S167>/DeadZone' */
        rtb_DeadZone_m = 0.0;
      } else {
        /* DeadZone: '<S167>/DeadZone' */
        rtb_DeadZone_m++;
      }

      /* End of DeadZone: '<S167>/DeadZone' */

      /* Product: '<S172>/IProd Out' incorporates:
       *  Constant: '<S82>/Constant1'
       */
      rtb_Delay2 *= 0.23235999999999998;

      /* Switch: '<S165>/Switch1' incorporates:
       *  Constant: '<S165>/Clamping_zero'
       *  Constant: '<S165>/Constant'
       *  Constant: '<S165>/Constant2'
       *  RelationalOperator: '<S165>/fix for DT propagation issue'
       */
      if (rtb_DeadZone_m > 0.0) {
        rtPrevAction = 1;
      } else {
        rtPrevAction = -1;
      }

      /* Switch: '<S165>/Switch2' incorporates:
       *  Constant: '<S165>/Clamping_zero'
       *  Constant: '<S165>/Constant3'
       *  Constant: '<S165>/Constant4'
       *  RelationalOperator: '<S165>/fix for DT propagation issue1'
       */
      if (rtb_Delay2 > 0.0) {
        rtAction = 1;
      } else {
        rtAction = -1;
      }

      /* Switch: '<S165>/Switch' incorporates:
       *  Constant: '<S165>/Clamping_zero'
       *  Logic: '<S165>/AND3'
       *  RelationalOperator: '<S165>/Equal1'
       *  RelationalOperator: '<S165>/Relational Operator'
       *  Switch: '<S165>/Switch1'
       *  Switch: '<S165>/Switch2'
       */
      if ((rtb_DeadZone_m != 0.0) && (rtPrevAction == rtAction)) {
        /* Switch: '<S165>/Switch' incorporates:
         *  Constant: '<S165>/Constant1'
         */
        rtb_Switch_e = 0.0;
      } else {
        /* Switch: '<S165>/Switch' */
        rtb_Switch_e = rtb_Delay2;
      }

      /* End of Switch: '<S165>/Switch' */
    }

    /* Integrator: '<S379>/Int1' */
    PMSM_to_BLDC_mod1_B.Int1 = PMSM_to_BLDC_mod1_X.Int1_CSTATE;

    /* Gain: '<S373>/Gain' */
    PMSM_to_BLDC_mod1_B.Gain_j = 57.324 * PMSM_to_BLDC_mod1_B.Int1;

    /* Integrator: '<S394>/Integrator' */
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

    /* Integrator: '<S395>/Integrator' */
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

    /* Gain: '<S390>/Gain2' incorporates:
     *  Gain: '<S390>/Gain1'
     *  Integrator: '<S394>/Integrator'
     *  Integrator: '<S395>/Integrator'
     *  Product: '<S390>/Product'
     *  Product: '<S393>/Product'
     *  Sum: '<S390>/Add'
     */
    PMSM_to_BLDC_mod1_B.Gain2 = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d *
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l * PMSM_to_BLDC_mod1_ConstB.Add +
      0.004133 * PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l) * 10.5;

    /* Gain: '<S373>/Gain1' incorporates:
     *  Gain: '<S375>/Gain'
     */
    PMSM_to_BLDC_mod1_B.Gain1 = 0.0026539278131634818 *
      PMSM_to_BLDC_mod1_B.Gain2 * 9.549;
    if (tmp_0) {
    }

    /* Gain: '<S379>/Gain4' */
    rtb_Merge1 = 7.0 * PMSM_to_BLDC_mod1_B.Int1;

    /* Trigonometry: '<S381>/sine_cosine' */
    rtb_Delay2 = sin(rtb_Merge1);
    rtb_Merge1 = cos(rtb_Merge1);

    /* Sum: '<S389>/Add1' incorporates:
     *  Integrator: '<S394>/Integrator'
     *  Integrator: '<S395>/Integrator'
     *  Product: '<S389>/Product2'
     *  Product: '<S389>/Product3'
     */
    rtb_algDD_o2 = PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d * rtb_Merge1 -
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l * rtb_Delay2;

    /* SignalConversion generated from: '<S378>/Vector Concatenate' incorporates:
     *  Concatenate: '<S378>/Vector Concatenate'
     */
    PMSM_to_BLDC_mod1_B.VectorConcatenate[0] = rtb_algDD_o2;

    /* Sum: '<S389>/Add' incorporates:
     *  Integrator: '<S394>/Integrator'
     *  Integrator: '<S395>/Integrator'
     *  Product: '<S389>/Product'
     *  Product: '<S389>/Product1'
     */
    rtb_algDD_o1 = PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d * rtb_Delay2 +
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l * rtb_Merge1;

    /* Gain: '<S388>/Gain2' incorporates:
     *  Gain: '<S388>/Gain1'
     */
    rtb_algDD_o2 *= -0.5;

    /* Sum: '<S388>/Subtract1' incorporates:
     *  Concatenate: '<S378>/Vector Concatenate'
     *  Gain: '<S388>/Gain2'
     *  Gain: '<S388>/Gain3'
     */
    PMSM_to_BLDC_mod1_B.VectorConcatenate[1] = 0.8660254037844386 * rtb_algDD_o1
      + rtb_algDD_o2;

    /* Sum: '<S388>/Subtract2' incorporates:
     *  Concatenate: '<S378>/Vector Concatenate'
     *  Gain: '<S388>/Gain4'
     */
    PMSM_to_BLDC_mod1_B.VectorConcatenate[2] = -0.8660254037844386 *
      rtb_algDD_o1 + rtb_algDD_o2;

    /* DataTypeConversion: '<S373>/Data Type Conversion' */
    PMSM_to_BLDC_mod1_B.DataTypeConversion_c[0] =
      PMSM_to_BLDC_mod1_B.VectorConcatenate[0];
    PMSM_to_BLDC_mod1_B.DataTypeConversion_c[1] =
      PMSM_to_BLDC_mod1_B.VectorConcatenate[1];
    PMSM_to_BLDC_mod1_B.DataTypeConversion_c[2] =
      PMSM_to_BLDC_mod1_B.VectorConcatenate[2];
    if (tmp_0) {
      /* Saturate: '<S374>/Saturation2' */
      if (PMSM_to_BLDC_mod1_B.Gain_f[0] > 1.0) {
        rtb_algDD_o2 = 1.0;
      } else if (PMSM_to_BLDC_mod1_B.Gain_f[0] < 0.0) {
        rtb_algDD_o2 = 0.0;
      } else {
        rtb_algDD_o2 = PMSM_to_BLDC_mod1_B.Gain_f[0];
      }

      if (PMSM_to_BLDC_mod1_B.Gain_f[1] > 1.0) {
        rtb_Merge = 1.0;
      } else if (PMSM_to_BLDC_mod1_B.Gain_f[1] < 0.0) {
        rtb_Merge = 0.0;
      } else {
        rtb_Merge = PMSM_to_BLDC_mod1_B.Gain_f[1];
      }

      if (PMSM_to_BLDC_mod1_B.Gain_f[2] > 1.0) {
        Merge1 = 1.0;
      } else if (PMSM_to_BLDC_mod1_B.Gain_f[2] < 0.0) {
        Merge1 = 0.0;
      } else {
        Merge1 = PMSM_to_BLDC_mod1_B.Gain_f[2];
      }

      /* End of Saturate: '<S374>/Saturation2' */

      /* Gain: '<S374>/Gain' incorporates:
       *  Sum: '<S374>/Sum'
       */
      rtb_algDD_o1 = ((rtb_Merge + Merge1) + rtb_algDD_o2) * 0.33333333333333331;

      /* Product: '<S374>/Product' incorporates:
       *  Sum: '<S374>/Sum1'
       *  Sum: '<S374>/Sum2'
       *  Sum: '<S374>/Sum3'
       */
      PMSM_to_BLDC_mod1_B.Product[0] = (rtb_algDD_o2 - rtb_algDD_o1) *
        PMSM_to_BLDC_mod1_ConstB.Switch;
      PMSM_to_BLDC_mod1_B.Product[1] = (rtb_Merge - rtb_algDD_o1) *
        PMSM_to_BLDC_mod1_ConstB.Switch;
      PMSM_to_BLDC_mod1_B.Product[2] = (Merge1 - rtb_algDD_o1) *
        PMSM_to_BLDC_mod1_ConstB.Switch;

      /* Sum: '<S387>/Add' incorporates:
       *  Gain: '<S387>/Gain'
       *  Gain: '<S387>/Gain1'
       *  Gain: '<S387>/Gain4'
       */
      PMSM_to_BLDC_mod1_B.Add = (0.66666666666666663 *
        PMSM_to_BLDC_mod1_B.Product[0] + -0.33333333333333331 *
        PMSM_to_BLDC_mod1_B.Product[1]) + -0.33333333333333331 *
        PMSM_to_BLDC_mod1_B.Product[2];

      /* Sum: '<S387>/Add1' incorporates:
       *  Gain: '<S387>/Gain2'
       *  Gain: '<S387>/Gain3'
       */
      PMSM_to_BLDC_mod1_B.Add1 = 0.57735026918962573 *
        PMSM_to_BLDC_mod1_B.Product[1] + -0.57735026918962573 *
        PMSM_to_BLDC_mod1_B.Product[2];
    }

    /* Sum: '<S394>/Add' incorporates:
     *  Constant: '<S398>/Constant'
     *  Integrator: '<S394>/Integrator'
     *  Integrator: '<S395>/Integrator'
     *  Product: '<S392>/Product2'
     *  Product: '<S392>/Product3'
     *  Product: '<S394>/Product'
     *  Product: '<S396>/Product'
     *  Product: '<S397>/Product'
     *  Product: '<S398>/Product'
     *  Sum: '<S392>/Add1'
     */
    PMSM_to_BLDC_mod1_B.Add_h = ((PMSM_to_BLDC_mod1_B.Add * rtb_Merge1 +
      PMSM_to_BLDC_mod1_B.Add1 * rtb_Delay2) /
      PMSM_to_BLDC_mod1_ConstB.IndexVector_b + PMSM_to_BLDC_mod1_ConstB.Gain *
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l *
      PMSM_to_BLDC_mod1_ConstB.IndexVector_ah /
      PMSM_to_BLDC_mod1_ConstB.IndexVector1_e) -
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d * 0.037 /
      PMSM_to_BLDC_mod1_ConstB.IndexVector_j;

    /* Sum: '<S395>/Add' incorporates:
     *  Constant: '<S402>/Constant'
     *  Integrator: '<S394>/Integrator'
     *  Integrator: '<S395>/Integrator'
     *  Product: '<S392>/Product'
     *  Product: '<S392>/Product1'
     *  Product: '<S395>/Product'
     *  Product: '<S399>/Product'
     *  Product: '<S400>/Product'
     *  Product: '<S402>/Product'
     *  Sum: '<S392>/Add'
     */
    PMSM_to_BLDC_mod1_B.Add_d = (((PMSM_to_BLDC_mod1_B.Add1 * rtb_Merge1 -
      PMSM_to_BLDC_mod1_B.Add * rtb_Delay2) /
      PMSM_to_BLDC_mod1_ConstB.IndexVector_k -
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d * PMSM_to_BLDC_mod1_ConstB.Gain *
      PMSM_to_BLDC_mod1_ConstB.IndexVector_m /
      PMSM_to_BLDC_mod1_ConstB.IndexVector1_g) -
      PMSM_to_BLDC_mod1_ConstB.Product) -
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l * 0.037 /
      PMSM_to_BLDC_mod1_ConstB.IndexVector_d3;
    if (tmp_0) {
      /* Gain: '<S436>/Integral Gain' */
      PMSM_to_BLDC_mod1_B.IntegralGain = 45.439609185072527 *
        PMSM_to_BLDC_mod1_B.DataTypeConversion1;
    }

    if (tmp_1) {
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Timer_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Timer' */
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
     *  EnablePort: '<S7>/Enable'
     */
    if (PMSM_to_BLDC_mod1_DW.Timer_MODE) {
      /* Update for RateTransition: '<S58>/Rate Transition' */
      if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
          PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] == 0) {
        PMSM_to_BLDC_mod1_DW.RateTransition_Buffer0[0] =
          PMSM_to_BLDC_mod1_B.Delay2[0];
        PMSM_to_BLDC_mod1_DW.RateTransition_Buffer0[1] =
          PMSM_to_BLDC_mod1_B.Delay2[1];
      }

      /* End of Update for RateTransition: '<S58>/Rate Transition' */
      if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
          PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0) {
        /* Update for Delay: '<S61>/Delay' */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[0] =
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE[4];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[1] =
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE[5];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[2] =
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE[6];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[3] =
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE[7];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[4] =
          PMSM_to_BLDC_mod1_B.TmpSignalConversionAtDelayInpor[0];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[5] =
          PMSM_to_BLDC_mod1_B.TmpSignalConversionAtDelayInpor[1];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[6] =
          PMSM_to_BLDC_mod1_B.TmpSignalConversionAtDelayInpor[2];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[7] =
          PMSM_to_BLDC_mod1_B.TmpSignalConversionAtDelayInpor[3];

        /* Update for Delay: '<S251>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad = false;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[0] = rtb_Add1[0];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[1] = rtb_Add1[1];

        /* Update for Delay: '<S334>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_f = false;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_a = rtb_Add1_e;

        /* Update for DiscreteIntegrator: '<S303>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE = PMSM_to_BLDC_mod1_B.Integrator;
        PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState = 0;

        /* Update for Delay: '<S359>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_a = false;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_ai = rtb_Switch2;

        /* Update for DiscreteIntegrator: '<S175>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b += rtb_Switch_e;
        PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState_n = 1;

        /* Update for Delay: '<S58>/Delay1' */
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx = PMSM_to_BLDC_mod1_B.SpeedGain;

        /* Update for DiscreteIntegrator: '<S120>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n += rtb_Switch;
        PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState_nt = 1;

        /* Update for Delay: '<S265>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_b = false;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_g = rtb_Add1_d;
      }

      /* Update for Integrator: '<S394>/Integrator' */
      PMSM_to_BLDC_mod1_DW.Integrator_DWORK1 = false;

      /* Update for Integrator: '<S395>/Integrator' */
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
    /* Derivatives for Integrator: '<S439>/Integrator' */
    _rtXdot->Integrator_CSTATE = PMSM_to_BLDC_mod1_B.IntegralGain;

    /* Derivatives for Integrator: '<S379>/Int1' incorporates:
     *  Constant: '<S375>/Speed_Angular_Vel'
     */
    _rtXdot->Int1_CSTATE = 200.0;

    /* Derivatives for Integrator: '<S394>/Integrator' */
    lsat = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d <= -1.0E+7);
    usat = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d >= 1.0E+7);
    if (((!lsat) && (!usat)) || (lsat && (PMSM_to_BLDC_mod1_B.Add_h > 0.0)) ||
        (usat && (PMSM_to_BLDC_mod1_B.Add_h < 0.0))) {
      _rtXdot->Integrator_CSTATE_d = PMSM_to_BLDC_mod1_B.Add_h;
    } else {
      /* in saturation */
      _rtXdot->Integrator_CSTATE_d = 0.0;
    }

    /* End of Derivatives for Integrator: '<S394>/Integrator' */

    /* Derivatives for Integrator: '<S395>/Integrator' */
    lsat = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l <= -1.0E+7);
    usat = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l >= 1.0E+7);
    if (((!lsat) && (!usat)) || (lsat && (PMSM_to_BLDC_mod1_B.Add_d > 0.0)) ||
        (usat && (PMSM_to_BLDC_mod1_B.Add_d < 0.0))) {
      _rtXdot->Integrator_CSTATE_l = PMSM_to_BLDC_mod1_B.Add_d;
    } else {
      /* in saturation */
      _rtXdot->Integrator_CSTATE_l = 0.0;
    }

    /* End of Derivatives for Integrator: '<S395>/Integrator' */
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
  rtmSetTFinal(PMSM_to_BLDC_mod1_M, 100.0);
  PMSM_to_BLDC_mod1_M->Timing.stepSize0 = 5.0E-5;
  rtmSetFirstInitCond(PMSM_to_BLDC_mod1_M, 1);

  /* External mode info */
  PMSM_to_BLDC_mod1_M->Sizes.checksums[0] = (3867839094U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[1] = (2000073604U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[2] = (2826146683U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[3] = (2775657481U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[91];
    PMSM_to_BLDC_mod1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_g;
    systemRan[4] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_g;
    systemRan[5] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_c;
    systemRan[6] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_c;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
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
    systemRan[16] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[17] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[18] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[19] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[20] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[21] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[22] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[23] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[26] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[27] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[28] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[29] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[30] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[31] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[32] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_n;
    systemRan[33] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_n;
    systemRan[34] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_n;
    systemRan[35] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_f;
    systemRan[36] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_f;
    systemRan[37] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_f;
    systemRan[38] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_f;
    systemRan[39] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_f;
    systemRan[40] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_f;
    systemRan[41] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_f;
    systemRan[42] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC;
    systemRan[43] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC;
    systemRan[44] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC;
    systemRan[45] = &rtAlwaysEnabled;
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
      &PMSM_to_BLDC_mod1_DW.Status_Reg1_read_SubsysRanBC;
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
      &PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_SubsysRanBC;
    systemRan[60] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Timer_SubsysRanBC;
    systemRan[61] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[62] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC;
    systemRan[63] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Timer_SubsysRanBC;
    systemRan[64] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IfActionSubsystem_d.IfActionSubsystem_SubsysRanBC;
    systemRan[65] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IfActionSubsystem1_j.IfActionSubsystem1_SubsysRanBC;
    systemRan[66] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Timer_SubsysRanBC;
    systemRan[67] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Dir_Sense_SubsysRanBC;
    systemRan[68] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem2_SubsysRanBC;
    systemRan[69] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem3_SubsysRanBC;
    systemRan[70] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IfActionSubsystem_SubsysRanBC_b;
    systemRan[71] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC;
    systemRan[72] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IntegralMethod_SubsysRanBC;
    systemRan[73] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IntegralMethod_SubsysRanBC;
    systemRan[74] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IntegralMethod_SubsysRanBC;
    systemRan[75] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IntegralMethod_SubsysRanBC;
    systemRan[76] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IntegralMethod_SubsysRanBC;
    systemRan[77] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.OptimizedDifferentiationMethod_;
    systemRan[78] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.OptimizedDifferentiationMethod_;
    systemRan[79] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.OptimizedDifferentiationMethod_;
    systemRan[80] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.OptimizedDifferentiationMethod_;
    systemRan[81] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.OptimizedDifferentiationMethod_;
    systemRan[82] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IfActionSubsystem_SubsysRanBC_a;
    systemRan[83] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IfActionSubsystem1_SubsysRanB_e;
    systemRan[84] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Timer_SubsysRanBC;
    systemRan[85] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Timer_SubsysRanBC;
    systemRan[86] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[87] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[88] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Timer_SubsysRanBC;
    systemRan[89] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Timer_SubsysRanBC;
    systemRan[90] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PMSM_to_BLDC_mod1_M->extModeInfo,
      &PMSM_to_BLDC_mod1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PMSM_to_BLDC_mod1_M->extModeInfo,
                        PMSM_to_BLDC_mod1_M->Sizes.checksums);
    rteiSetTPtr(PMSM_to_BLDC_mod1_M->extModeInfo, rtmGetTPtr(PMSM_to_BLDC_mod1_M));
  }

  /* block I/O */
  {
    PMSM_to_BLDC_mod1_B.Ref_angular_vel = 200.0;
    PMSM_to_BLDC_mod1_B.Gain2_b = 31.847133757961782;
    PMSM_to_BLDC_mod1_B.Gain1_e = 1910.0000000000002;
    PMSM_to_BLDC_mod1_B.DataTypeConversion_i = 200.0F;
  }

  {
    int32_T i;
    static const real_T tmp[6] = { 0.1738649311409407, 0.14497518005452667,
      -0.131660917710016, 0.11721513748315816, 0.17386493114094065,
      0.14497518005452664 };

    static const real_T tmp_0[6] = { 1.0, 1.0, -1.3555444224208766,
      -1.2150445927978653, 0.7833530425883195, 0.42306875853794279 };

    PMSM_to_BLDC_mod1_PrevZCX.Dir_Sense_Trig_ZCE = POS_ZCSIG;
    PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_i = UNINITIALIZED_ZCSIG;
    PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_k = UNINITIALIZED_ZCSIG;
    PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_p = UNINITIALIZED_ZCSIG;
    PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_h = UNINITIALIZED_ZCSIG;
    PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE = UNINITIALIZED_ZCSIG;
    PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE = UNINITIALIZED_ZCSIG;
    PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE_l = UNINITIALIZED_ZCSIG;
    PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE_m = UNINITIALIZED_ZCSIG;
    PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE = UNINITIALIZED_ZCSIG;
    PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE = UNINITIALIZED_ZCSIG;
    PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_a = UNINITIALIZED_ZCSIG;

    /* SystemInitialize for Atomic SubSystem: '<Root>/En_gate' */
    /* Start for MATLABSystem: '<S21>/Digital Port Write' */
    PMSM_to_BLDC_mod1_DW.obj_ow.matlabCodegenIsDeleted = false;
    PMSM_to_BLDC_mod1_DW.obj_ow.isInitialized = 1;
    PMSM_to_BLDC_mod1_DW.obj_ow.isSetupComplete = true;

    /* End of SystemInitialize for SubSystem: '<Root>/En_gate' */
    /* SystemInitialize for Atomic SubSystem: '<S22>/Bit Shift' */
    PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift);

    /* End of SystemInitialize for SubSystem: '<S22>/Bit Shift' */

    /* SystemInitialize for Atomic SubSystem: '<S22>/Bit Shift1' */
    PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1);

    /* End of SystemInitialize for SubSystem: '<S22>/Bit Shift1' */

    /* Start for MATLABSystem: '<S22>/SPI Transmit' */
    PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted = false;
    PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete = false;
    PMSM_to_BLDC_mod1_DW.obj_j.isInitialized = 1;
    PMSM_to_SPIDrvBlock_setupImpl_o(&PMSM_to_BLDC_mod1_DW.obj_j);
    PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S22>/SPI Receive' */
    PMSM_to_BLDC_mod1_DW.obj_gk.isInitialized = 0;
    PMSM_to_BLDC_mod1_DW.obj_gk.matlabCodegenIsDeleted = false;
    PMSM_to_BL_SystemCore_setup_oxg(&PMSM_to_BLDC_mod1_DW.obj_gk);

    /* End of SystemInitialize for SubSystem: '<S4>/Control_Reg2' */
    /* SystemInitialize for Atomic SubSystem: '<S23>/Bit Shift' */
    PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_h);

    /* End of SystemInitialize for SubSystem: '<S23>/Bit Shift' */

    /* SystemInitialize for Atomic SubSystem: '<S23>/Bit Shift1' */
    PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_d);

    /* End of SystemInitialize for SubSystem: '<S23>/Bit Shift1' */

    /* Start for MATLABSystem: '<S23>/SPI Transmit' */
    PMSM_to_BLDC_mod1_DW.obj_n.matlabCodegenIsDeleted = false;
    PMSM_to_BLDC_mod1_DW.obj_n.isSetupComplete = false;
    PMSM_to_BLDC_mod1_DW.obj_n.isInitialized = 1;
    PMSM_to_SPIDrvBlock_setupImpl_o(&PMSM_to_BLDC_mod1_DW.obj_n);
    PMSM_to_BLDC_mod1_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S23>/SPI Receive' */
    PMSM_to_BLDC_mod1_DW.obj_g.isInitialized = 0;
    PMSM_to_BLDC_mod1_DW.obj_g.matlabCodegenIsDeleted = false;
    PMSM_to_B_SystemCore_setup_oxgk(&PMSM_to_BLDC_mod1_DW.obj_g);

    /* End of SystemInitialize for SubSystem: '<S4>/Ctrl_Reg_1' */
    /* End of SystemInitialize for SubSystem: '<Root>/SPI_Write' */
    /* SystemInitialize for Atomic SubSystem: '<S49>/Bit Shift' */
    PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_n);

    /* End of SystemInitialize for SubSystem: '<S49>/Bit Shift' */

    /* SystemInitialize for Atomic SubSystem: '<S49>/Bit Shift1' */
    PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_o);

    /* End of SystemInitialize for SubSystem: '<S49>/Bit Shift1' */
    PMSM_to_BLDC__SPIReceive_k_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaevv);
    PMSM_to_BLDC_SPITransmit_d_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnaevv);

    /* End of SystemInitialize for SubSystem: '<S6>/Status_Reg_2_read' */

    /* SystemInitialize for Atomic SubSystem: '<S48>/Bit Shift' */
    PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_p);

    /* End of SystemInitialize for SubSystem: '<S48>/Bit Shift' */

    /* SystemInitialize for Atomic SubSystem: '<S48>/Bit Shift1' */
    PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_j);

    /* End of SystemInitialize for SubSystem: '<S48>/Bit Shift1' */
    PMSM_to_BLDC__SPIReceive_k_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaev);
    PMSM_to_BLDC_SPITransmit_d_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnaev);

    /* End of SystemInitialize for SubSystem: '<S6>/Status_Reg1_read' */

    /* Start for MATLABSystem: '<S15>/Analog to Digital Converter' */
    PMSM_to_BLDC_mod1_DW.obj_d.isInitialized = 0;
    PMSM_to_BLDC_mod1_DW.obj_d.matlabCodegenIsDeleted = false;
    PMSM_to_BLDC_SystemCore_setup_o(&PMSM_to_BLDC_mod1_DW.obj_d);

    /* End of SystemInitialize for SubSystem: '<S2>/Subsystem' */
    /* Start for MATLABSystem: '<S18>/Analog to Digital Converter' */
    PMSM_to_BLDC_mod1_DW.obj_o.isInitialized = 0;
    PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted = false;
    PMSM_to_BLD_SystemCore_setup_ox(&PMSM_to_BLDC_mod1_DW.obj_o);

    /* End of SystemInitialize for SubSystem: '<S2>/Subsystem1' */

    /* Start for MATLABSystem: '<S2>/Lowpass Filter' */
    PMSM_to_BLDC_mod1_DW.obj.NumChannels = -1;
    PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = false;
    PMSM_to_BLDC_mod1_DW.obj.isInitialized = 1;
    if (PMSM_to_BLDC_mod1_DW.obj.NumChannels == -1) {
      PMSM_to_BLDC_mod1_DW.obj.NumChannels = 1;
    }

    PMSM_to_BLDC_mod1_DW.obj.coder_buffer_pobj0.isInitialized = 0;

    /* System object Constructor function: dsp.SOSFilter */
    PMSM_to_BLDC_mod1_DW.obj.coder_buffer_pobj0.cSFunObject.P0_ICRTP = 0.0;
    PMSM_to_BLDC_mod1_DW.obj.coder_buffer_pobj0.cSFunObject.P4_IC2RTP = 0.0;
    for (i = 0; i < 6; i++) {
      PMSM_to_BLDC_mod1_DW.obj.coder_buffer_pobj0.cSFunObject.P1_RTP1COEFF[i] =
        tmp[i];
    }

    for (i = 0; i < 6; i++) {
      PMSM_to_BLDC_mod1_DW.obj.coder_buffer_pobj0.cSFunObject.P2_RTP2COEFF[i] =
        tmp_0[i];
    }

    PMSM_to_BLDC_mod1_DW.obj.coder_buffer_pobj0.cSFunObject.P3_RTP3COEFF[0] =
      1.0;
    PMSM_to_BLDC_mod1_DW.obj.coder_buffer_pobj0.cSFunObject.P3_RTP3COEFF[1] =
      1.0;
    PMSM_to_BLDC_mod1_DW.obj.coder_buffer_pobj0.cSFunObject.P3_RTP3COEFF[2] =
      1.0;
    PMSM_to_BLDC_mod1_DW.obj.FilterObj =
      &PMSM_to_BLDC_mod1_DW.obj.coder_buffer_pobj0;
    PMSM_to_BLDC_mod1_DW.obj.isSetupComplete = true;

    /* InitializeConditions for MATLABSystem: '<S2>/Lowpass Filter' */
    if (PMSM_to_BLDC_mod1_DW.obj.FilterObj->isInitialized == 1) {
      /* System object Initialization function: dsp.SOSFilter */
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W0_ZERO_STATES[0] =
        PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P0_ICRTP;
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W0_ZERO_STATES[1] =
        PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P0_ICRTP;
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W0_ZERO_STATES[2] =
        PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P0_ICRTP;
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W0_ZERO_STATES[3] =
        PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P0_ICRTP;
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W1_POLE_STATES[0] =
        PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P4_IC2RTP;
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W1_POLE_STATES[1] =
        PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P4_IC2RTP;
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W1_POLE_STATES[2] =
        PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P4_IC2RTP;
      PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.W1_POLE_STATES[3] =
        PMSM_to_BLDC_mod1_DW.obj.FilterObj->cSFunObject.P4_IC2RTP;
    }

    /* End of InitializeConditions for MATLABSystem: '<S2>/Lowpass Filter' */
    /* End of SystemInitialize for SubSystem: '<Root>/Current_sensing' */
    /* SystemInitialize for Enabled SubSystem: '<S34>/Subsystem1' */
    PMSM_to_BLDC__SPIReceive_e_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pn);
    PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pn);

    /* End of SystemInitialize for SubSystem: '<S34>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S35>/Subsystem1' */
    PMSM_to_BLDC__SPIReceive_e_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnae);
    PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnae);

    /* End of SystemInitialize for SubSystem: '<S35>/Subsystem1' */

    /* SystemInitialize for Atomic SubSystem: '<S36>/Bit Shift' */
    PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_hq);

    /* End of SystemInitialize for SubSystem: '<S36>/Bit Shift' */

    /* SystemInitialize for Atomic SubSystem: '<S36>/Bit Shift1' */
    PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_p);

    /* End of SystemInitialize for SubSystem: '<S36>/Bit Shift1' */
    PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_p);
    PMSM_to_BLDC_mo_SPIReceive_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_p);

    /* End of SystemInitialize for SubSystem: '<S34>/Subsystem' */

    /* SystemInitialize for Atomic SubSystem: '<S42>/Bit Shift' */
    PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_b);

    /* End of SystemInitialize for SubSystem: '<S42>/Bit Shift' */

    /* SystemInitialize for Atomic SubSystem: '<S42>/Bit Shift1' */
    PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_m);

    /* End of SystemInitialize for SubSystem: '<S42>/Bit Shift1' */
    PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pna);
    PMSM_to_BLDC_mo_SPIReceive_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pna);

    /* End of SystemInitialize for SubSystem: '<S35>/Subsystem' */
    /* End of SystemInitialize for SubSystem: '<Root>/SPI_read' */

    /* Start for If: '<S252>/If' */
    PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem = -1;

    /* Start for SwitchCase: '<S261>/Switch Case' */
    PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem = -1;

    /* Start for If: '<S258>/If' */
    PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_g = -1;

    /* Start for SwitchCase: '<S260>/Switch Case' */
    PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem_n = -1;

    /* Start for If: '<S363>/If' */
    PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_e = -1;

    /* Start for If: '<S225>/If' */
    PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_c = -1;

    /* Start for If: '<S200>/If' */
    PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_m = -1;

    /* InitializeConditions for Delay: '<S251>/Delay' */
    PMSM_to_BLDC_mod1_DW.icLoad = true;

    /* InitializeConditions for Delay: '<S334>/Delay' */
    PMSM_to_BLDC_mod1_DW.icLoad_f = true;

    /* InitializeConditions for Delay: '<S359>/Delay' */
    PMSM_to_BLDC_mod1_DW.icLoad_a = true;

    /* InitializeConditions for DiscreteIntegrator: '<S175>/Integrator' */
    PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b =
      PMSM_to_BLDC_mod1_ConstB.Constant3_n;

    /* InitializeConditions for Integrator: '<S439>/Integrator' */
    PMSM_to_BLDC_mod1_X.Integrator_CSTATE = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S120>/Integrator' */
    PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n =
      PMSM_to_BLDC_mod1_ConstB.Constant3;

    /* InitializeConditions for Delay: '<S265>/Delay' */
    PMSM_to_BLDC_mod1_DW.icLoad_b = true;

    /* InitializeConditions for Integrator: '<S379>/Int1' */
    PMSM_to_BLDC_mod1_X.Int1_CSTATE = 0.0;

    /* InitializeConditions for Integrator: '<S394>/Integrator' incorporates:
     *  Integrator: '<S395>/Integrator'
     */
    if (rtmIsFirstInitCond(PMSM_to_BLDC_mod1_M)) {
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d = 0.0;
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l = 0.0;
    }

    PMSM_to_BLDC_mod1_DW.Integrator_DWORK1 = true;

    /* End of InitializeConditions for Integrator: '<S394>/Integrator' */

    /* InitializeConditions for Integrator: '<S395>/Integrator' */
    PMSM_to_BLDC_mod1_DW.Integrator_DWORK1_g = true;

    /* SystemInitialize for IfAction SubSystem: '<S260>/IntegralMethod' */
    /* InitializeConditions for Delay: '<S344>/Delay' */
    PMSM_to_BLDC_mod1_DW.icLoad_k = true;

    /* InitializeConditions for Delay: '<S341>/Delay' */
    PMSM_to_BLDC_mod1_DW.icLoad_bd = true;

    /* End of SystemInitialize for SubSystem: '<S260>/IntegralMethod' */

    /* SystemInitialize for IfAction SubSystem: '<S260>/OptimizedDifferentiationMethod' */
    /* InitializeConditions for Delay: '<S354>/Delay' */
    PMSM_to_BLDC_mod1_DW.icLoad_c = true;

    /* InitializeConditions for Delay: '<S351>/Delay' */
    PMSM_to_BLDC_mod1_DW.icLoad_b1 = true;

    /* End of SystemInitialize for SubSystem: '<S260>/OptimizedDifferentiationMethod' */

    /* Start for MATLABSystem: '<S458>/PWM Output' */
    PMSM_to_BLDC_mod1_DW.obj_e.matlabCodegenIsDeleted = false;
    PMSM_to_BLDC_mod1_DW.obj_e.isSetupComplete = false;
    PMSM_to_BLDC_mod1_DW.obj_e.isInitialized = 1;
    PMSM_to_BLD_PWMOutput_setupImpl(&PMSM_to_BLDC_mod1_DW.obj_e);
    PMSM_to_BLDC_mod1_DW.obj_e.isSetupComplete = true;

    /* End of SystemInitialize for SubSystem: '<Root>/Timer' */

    /* Start for MATLABSystem: '<S461>/Analog to Digital Converter' */
    PMSM_to_BLDC_mod1_DW.obj_p.isInitialized = 0;
    PMSM_to_BLDC_mod1_DW.obj_p.matlabCodegenIsDeleted = false;
    PMSM_to__SystemCore_setup_oxgkf(&PMSM_to_BLDC_mod1_DW.obj_p);

    /* ConstCode for Enabled SubSystem: '<Root>/Timer' */
    /* ConstCode for Constant: '<S58>/Constant' */
    PMSM_to_BLDC_mod1_B.Ref_angular_vel = 200.0;

    /* ConstCode for Gain: '<S64>/Gain2' */
    PMSM_to_BLDC_mod1_B.Gain2_b = 0.15923566878980891 *
      PMSM_to_BLDC_mod1_B.Ref_angular_vel;

    /* ConstCode for Gain: '<S375>/Gain1' incorporates:
     *  Constant: '<S375>/Speed_Angular_Vel'
     */
    PMSM_to_BLDC_mod1_B.Gain1_e = 1910.0000000000002;

    /* ConstCode for DataTypeConversion: '<S65>/Data Type Conversion' */
    PMSM_to_BLDC_mod1_B.DataTypeConversion_i = (real32_T)
      PMSM_to_BLDC_mod1_B.Ref_angular_vel;

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

  /* Terminate for MATLABSystem: '<S461>/Analog to Digital Converter' */
  if (!PMSM_to_BLDC_mod1_DW.obj_p.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_p.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_p.isSetupComplete) {
      ADC_Handle_Deinit(PMSM_to_BLDC_mod1_DW.obj_p.ADCHandle, ADC_NORMAL_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S461>/Analog to Digital Converter' */
  /* Terminate for Atomic SubSystem: '<Root>/En_gate' */
  /* Terminate for MATLABSystem: '<S21>/Digital Port Write' */
  if (!PMSM_to_BLDC_mod1_DW.obj_ow.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_ow.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S21>/Digital Port Write' */
  /* End of Terminate for SubSystem: '<Root>/En_gate' */

  /* Terminate for Atomic SubSystem: '<Root>/SPI_Write' */
  /* Terminate for Enabled SubSystem: '<S4>/Control_Reg2' */
  /* Terminate for MATLABSystem: '<S22>/SPI Transmit' */
  if (!PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_j.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S22>/SPI Transmit' */
  /* Terminate for MATLABSystem: '<S22>/SPI Receive' */
  if (!PMSM_to_BLDC_mod1_DW.obj_gk.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_gk.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_gk.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_gk.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_gk.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S22>/SPI Receive' */
  /* End of Terminate for SubSystem: '<S4>/Control_Reg2' */

  /* Terminate for Enabled SubSystem: '<S4>/Ctrl_Reg_1' */
  /* Terminate for MATLABSystem: '<S23>/SPI Transmit' */
  if (!PMSM_to_BLDC_mod1_DW.obj_n.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_n.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_n.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_n.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S23>/SPI Transmit' */
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
  /* End of Terminate for SubSystem: '<S4>/Ctrl_Reg_1' */

  /* Terminate for Enabled SubSystem: '<S6>/Status_Reg_2_read' */
  PMSM_to_BLDC__SPIReceive_c_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaevv);
  PMSM_to_BLDC_SPITransmit_a_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnaevv);

  /* Terminate for Enabled SubSystem: '<S6>/Status_Reg1_read' */
  PMSM_to_BLDC__SPIReceive_c_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaev);
  PMSM_to_BLDC_SPITransmit_a_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnaev);

  /* Terminate for Atomic SubSystem: '<Root>/Current_sensing' */
  /* Terminate for Enabled SubSystem: '<S2>/Subsystem' */
  /* Terminate for MATLABSystem: '<S15>/Analog to Digital Converter' */
  if (!PMSM_to_BLDC_mod1_DW.obj_d.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_d.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_d.isSetupComplete) {
      ADC_Handle_Deinit(PMSM_to_BLDC_mod1_DW.obj_d.ADCHandle, ADC_NORMAL_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S15>/Analog to Digital Converter' */
  /* Terminate for Enabled SubSystem: '<S2>/Subsystem1' */
  /* Terminate for MATLABSystem: '<S18>/Analog to Digital Converter' */
  if (!PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_o.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_o.isSetupComplete) {
      ADC_Handle_Deinit(PMSM_to_BLDC_mod1_DW.obj_o.ADCHandle, ADC_NORMAL_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S18>/Analog to Digital Converter' */
  /* Terminate for MATLABSystem: '<S2>/Lowpass Filter' */
  if (!PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj.isSetupComplete) {
      if (PMSM_to_BLDC_mod1_DW.obj.FilterObj->isInitialized == 1) {
        PMSM_to_BLDC_mod1_DW.obj.FilterObj->isInitialized = 2;
      }

      PMSM_to_BLDC_mod1_DW.obj.NumChannels = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Lowpass Filter' */
  /* End of Terminate for SubSystem: '<Root>/Current_sensing' */
  /* Terminate for Atomic SubSystem: '<Root>/SPI_read' */
  /* Terminate for Enabled SubSystem: '<S34>/Subsystem1' */
  PMSM_to_BLDC__SPIReceive_m_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pn);
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pn);

  /* End of Terminate for SubSystem: '<S34>/Subsystem1' */

  /* Terminate for Enabled SubSystem: '<S35>/Subsystem1' */
  PMSM_to_BLDC__SPIReceive_m_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnae);
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnae);

  /* End of Terminate for SubSystem: '<S35>/Subsystem1' */

  /* Terminate for Enabled SubSystem: '<S34>/Subsystem' */
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_p);
  PMSM_to_BLDC_mo_SPIReceive_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_p);

  /* End of Terminate for SubSystem: '<S34>/Subsystem' */

  /* Terminate for Enabled SubSystem: '<S35>/Subsystem' */
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pna);
  PMSM_to_BLDC_mo_SPIReceive_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pna);

  /* End of Terminate for SubSystem: '<S35>/Subsystem' */
  /* End of Terminate for SubSystem: '<Root>/SPI_read' */

  /* Terminate for MATLABSystem: '<S458>/PWM Output' */
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

  /* End of Terminate for MATLABSystem: '<S458>/PWM Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
