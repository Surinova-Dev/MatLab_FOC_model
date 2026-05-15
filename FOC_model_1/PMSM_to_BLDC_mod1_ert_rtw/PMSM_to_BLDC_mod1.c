/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.c
 *
 * Code generated for Simulink model 'PMSM_to_BLDC_mod1'.
 *
 * Model version                  : 4.888
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Fri May 15 17:50:01 2026
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

/* Named constants for MATLAB Function: '<S22>/bit_shift' */
#define PMSM_to_BLDC_mod1_CALL_EVENT   (-1)

/* Named constants for MATLAB Function: '<S23>/bit_shift' */
#define PMSM_to_BLDC_mod1_CALL_EVENT_j (-1)

/* Named constants for Chart: '<Root>/Chart' */
#define PMSM_to_BLDC__IN_Initialization (3U)
#define PMSM_to_BLDC_m_IN_Current_sense (1U)
#define PMSM_to_BLDC_mod1_IN_En_Gate   (2U)
#define PMSM_to_BLDC_mod1_IN_SPI_init1 (4U)
#define PMSM_to_BLDC_mod1_IN_SPI_init2 (5U)
#define PMSM_to_BLDC_mod1_IN_SPI_init3 (6U)
#define PMSM_to_BLDC_mod1_IN_SPI_init4 (7U)
#define PMSM_to_BLDC_mod1_IN_SPI_write (8U)
#define PMSM_to_BLDC_mod1_IN_SPI_write2 (10U)
#define PMSM_to_BLDC_mod1_IN_SPI_write5 (11U)
#define PMSM_to_BLDC_mod1_IN_SPI_write6 (12U)
#define PMSM_to_BLDC_mod1_IN_SPI_write7 (13U)
#define PMSM_to_BLDC_mod1_IN_SPI_write8 (14U)
#define PMSM_to_BLDC_mod1_IN_SPI_write9 (15U)
#define PMSM_to_BLDC_mod_IN_SPI_write10 (9U)

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
static void PMSM_to_BLD_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_PM_T *obj);
static void PMSM_to_BLDC_SystemCore_setup_o(stm32cube_blocks_AnalogInput__T *obj);
static void PMSM_to_BLD_SystemCore_setup_ox(stm32cube_blocks_AnalogInput__T *obj);
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
  if ((PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.001s, 0.0s] */
    PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] = 0;
  }

  (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[3])++;
  if ((PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[3]) > 999) {/* Sample time: [0.1s, 0.0s] */
    PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[3] = 0;
  }

  (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[4])++;
  if ((PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[4]) > 9999) {/* Sample time: [1.0s, 0.0s] */
    PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[4] = 0;
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
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
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

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  PMSM_to_BLDC_mod1_step();
  PMSM_to_BLDC_mod1_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  PMSM_to_BLDC_mod1_step();
  PMSM_to_BLDC_mod1_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  PMSM_to_BLDC_mod1_step();
  PMSM_to_BLDC_mod1_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  local_stateReduction(rtsiGetContStates(si), rtsiGetPeriodicContStateIndices(si),
                       1,
                       rtsiGetPeriodicContStateRanges(si));
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * System initialize for atomic system:
 *    '<S20>/Bit Shift'
 *    '<S21>/Bit Shift'
 *    '<S34>/Bit Shift'
 *    '<S40>/Bit Shift'
 *    '<S46>/Bit Shift'
 *    '<S47>/Bit Shift'
 */
void PMSM_to_BLDC_mod1_BitShift_Init(DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* SystemInitialize for MATLAB Function: '<S22>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
}

/*
 * System reset for atomic system:
 *    '<S20>/Bit Shift'
 *    '<S21>/Bit Shift'
 *    '<S34>/Bit Shift'
 *    '<S40>/Bit Shift'
 *    '<S46>/Bit Shift'
 *    '<S47>/Bit Shift'
 */
void PMSM_to_BLDC_mod_BitShift_Reset(DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* SystemReset for MATLAB Function: '<S22>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
}

/*
 * Output and update for atomic system:
 *    '<S20>/Bit Shift'
 *    '<S21>/Bit Shift'
 *    '<S34>/Bit Shift'
 *    '<S40>/Bit Shift'
 *    '<S46>/Bit Shift'
 *    '<S47>/Bit Shift'
 */
void PMSM_to_BLDC_mod1_BitShift(uint16_T rtu_u, uint16_T *rty_y,
  DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* MATLAB Function: '<S22>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
  *rty_y = (uint16_T)(rtu_u << 15);
}

/*
 * System initialize for atomic system:
 *    '<S20>/Bit Shift1'
 *    '<S21>/Bit Shift1'
 *    '<S34>/Bit Shift1'
 *    '<S40>/Bit Shift1'
 *    '<S46>/Bit Shift1'
 *    '<S47>/Bit Shift1'
 */
void PMSM_to_BLDC_mod_BitShift1_Init(DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* SystemInitialize for MATLAB Function: '<S23>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_j;
}

/*
 * System reset for atomic system:
 *    '<S20>/Bit Shift1'
 *    '<S21>/Bit Shift1'
 *    '<S34>/Bit Shift1'
 *    '<S40>/Bit Shift1'
 *    '<S46>/Bit Shift1'
 *    '<S47>/Bit Shift1'
 */
void PMSM_to_BLDC_mo_BitShift1_Reset(DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* SystemReset for MATLAB Function: '<S23>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_j;
}

/*
 * Output and update for atomic system:
 *    '<S20>/Bit Shift1'
 *    '<S21>/Bit Shift1'
 *    '<S34>/Bit Shift1'
 *    '<S40>/Bit Shift1'
 *    '<S46>/Bit Shift1'
 *    '<S47>/Bit Shift1'
 */
void PMSM_to_BLDC_mod1_BitShift1(uint16_T rtu_u, uint16_T *rty_y,
  DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* MATLAB Function: '<S23>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_j;
  *rty_y = (uint16_T)(rtu_u << 11);
}

static void PMSM_to_BLDC_m_SystemCore_setup(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S34>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S34>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S34>/SPI Receive' */
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
  /* Start for MATLABSystem: '<S34>/SPI Receive' */
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

  /* MATLABSystem: '<S34>/SPI Receive' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    MW_SPI_Read_Databits(localDW->obj.MW_SPI_HANDLE, &tmp[0], 15U, 1, 1, 1U);
    LL_GPIO_SetOutputPin(GPIOC, 16384U);
  }

  /* End of MATLABSystem: '<S34>/SPI Receive' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC_mo_SPIReceive_Term(DW_SPIReceive_PMSM_to_BLDC_mo_T *localDW)
{
  /* Terminate for MATLABSystem: '<S34>/SPI Receive' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S34>/SPI Receive' */
}

static void PMSM_to_B_SPIDrvBlock_setupImpl(stm32cube_blocks_SPIControl_d_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;

  /* Start for MATLABSystem: '<S34>/SPI Transmit' */
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S34>/SPI Transmit' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S34>/SPI Transmit' */
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
  /* Start for MATLABSystem: '<S34>/SPI Transmit' */
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

  /* MATLABSystem: '<S34>/SPI Transmit' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    LL_GPIO_ResetOutputPin(GPIOC, 16384U);
    MW_SPI_Write_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0, 1U, 1, 1, 1U);
  }

  /* End of MATLABSystem: '<S34>/SPI Transmit' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC_m_SPITransmit_Term(DW_SPITransmit_PMSM_to_BLDC_m_T *localDW)
{
  /* Terminate for MATLABSystem: '<S34>/SPI Transmit' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S34>/SPI Transmit' */
}

static void PMSM_to_BLDC_SystemCore_setup_n(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S35>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S35>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S35>/SPI Receive' */
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
  /* Start for MATLABSystem: '<S35>/SPI Receive' */
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

  /* MATLABSystem: '<S35>/SPI Receive' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    MW_SPI_Read_Databits(localDW->obj.MW_SPI_HANDLE, &localB->SPIReceive, 1U, 1,
                         1, 1U);
    LL_GPIO_SetOutputPin(GPIOC, 16384U);
  }

  /* End of MATLABSystem: '<S35>/SPI Receive' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC__SPIReceive_m_Term(DW_SPIReceive_PMSM_to_BLDC__f_T *localDW)
{
  /* Terminate for MATLABSystem: '<S35>/SPI Receive' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/SPI Receive' */
}

static void PMSM_to_BLD_SystemCore_setup_n2(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S46>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S46>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S46>/SPI Receive' */
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
  /* Start for MATLABSystem: '<S46>/SPI Receive' */
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

  /* MATLABSystem: '<S46>/SPI Receive' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    MW_SPI_Read_Databits(localDW->obj.MW_SPI_HANDLE, &localB->SPIReceive[0], 15U,
                         1, 1, 1U);
    LL_GPIO_SetOutputPin(GPIOC, 16384U);
  }

  /* End of MATLABSystem: '<S46>/SPI Receive' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC__SPIReceive_c_Term(DW_SPIReceive_PMSM_to_BLDC_fw_T *localDW)
{
  /* Terminate for MATLABSystem: '<S46>/SPI Receive' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S46>/SPI Receive' */
}

static void PMSM_to_SPIDrvBlock_setupImpl_e(stm32cube_blocks_SPIControl_d_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;

  /* Start for MATLABSystem: '<S46>/SPI Transmit' */
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S46>/SPI Transmit' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S46>/SPI Transmit' */
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
  /* Start for MATLABSystem: '<S46>/SPI Transmit' */
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

  /* MATLABSystem: '<S46>/SPI Transmit' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    LL_GPIO_ResetOutputPin(GPIOC, 16384U);
    MW_SPI_Write_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0, 1U, 1, 1, 1U);
  }

  /* End of MATLABSystem: '<S46>/SPI Transmit' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC_SPITransmit_a_Term(DW_SPITransmit_PMSM_to_BLDC_f_T *localDW)
{
  /* Terminate for MATLABSystem: '<S46>/SPI Transmit' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S46>/SPI Transmit' */
}

/*
 * Output and update for action system:
 *    '<S196>/If Action Subsystem'
 *    '<S222>/If Action Subsystem'
 */
void PMSM_to_BLDC__IfActionSubsystem(real_T rtu_In1, real_T *rty_Out1)
{
  real_T tmp;

  /* DataTypeConversion: '<S199>/Convert_uint16' */
  tmp = floor(rtu_In1);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* Sum: '<S199>/Sum' incorporates:
   *  DataTypeConversion: '<S199>/Convert_back'
   *  DataTypeConversion: '<S199>/Convert_uint16'
   */
  *rty_Out1 = rtu_In1 - (real_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);
}

/*
 * Output and update for action system:
 *    '<S196>/If Action Subsystem1'
 *    '<S222>/If Action Subsystem1'
 */
void PMSM_to_BLDC_IfActionSubsystem1(real_T rtu_In1, real_T *rty_Out1)
{
  real_T tmp;

  /* DataTypeConversion: '<S200>/Convert_uint16' */
  tmp = trunc(rtu_In1);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* Sum: '<S200>/Sum' incorporates:
   *  DataTypeConversion: '<S200>/Convert_back'
   *  DataTypeConversion: '<S200>/Convert_uint16'
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

  /* Start for MATLABSystem: '<S20>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S20>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S20>/SPI Receive' */
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

  /* Start for MATLABSystem: '<S20>/SPI Transmit' incorporates:
   *  MATLABSystem: '<S21>/SPI Transmit'
   */
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S20>/SPI Transmit' incorporates:
   *  MATLABSystem: '<S21>/SPI Transmit'
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

  /* Start for MATLABSystem: '<S20>/SPI Transmit' incorporates:
   *  MATLABSystem: '<S21>/SPI Transmit'
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

  /* Start for MATLABSystem: '<S21>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S21>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S21>/SPI Receive' */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 1.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
  obj->isSetupComplete = true;
}

static void PMSM_to_BLD_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_PM_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S456>/PWM Output' */
  b.PeripheralPtr = TIM8;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S456>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S456>/PWM Output' */
    enableCounter(obj->TimerHandle, true);
  }
}

static void PMSM_to_BLDC_SystemCore_setup_o(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S13>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S13>/Analog to Digital Converter' */
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

  /* Start for MATLABSystem: '<S16>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S16>/Analog to Digital Converter' */
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

static void PMSM_to__SystemCore_setup_oxgkf(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S459>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S459>/Analog to Digital Converter' */
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
  GPIO_TypeDef * portNameLoc;
  TIM_TypeDef * timModule;
  uint32_T channelEnum;
  real_T rtb_Gain_h[6];
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
  real32_T rtb_Saturation_or;
  real32_T rtb_indexing;
  uint32_T freq;
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
  srClearBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_o);

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
  srClearBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC);
  tmp_0 = (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
           PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0);
  if (tmp_0) {
    /* Delay: '<Root>/Delay' */
    PMSM_to_BLDC_mod1_B.Delay = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_cn;

    /* Delay: '<Root>/Delay1' */
    PMSM_to_BLDC_mod1_B.Delay1 = PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fv;
  }

  /* Outputs for Enabled SubSystem: '<Root>/Subsystem' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  tmp_1 = (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
           PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] == 0);

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */
  if (tmp_1) {
    /* Chart: '<Root>/Chart' */
    if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 < 8191) {
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
       case PMSM_to_BLDC_m_IN_Current_sense:
        PMSM_to_BLDC_mod1_B.Ib_flag = 1.0;
        PMSM_to_BLDC_mod1_B.Ic_flag = 1.0;
        PMSM_to_BLDC_mod1_B.FOC_flag = 1.0;
        break;

       case PMSM_to_BLDC_mod1_IN_En_Gate:
        PMSM_to_BLDC_mod1_B.En_State = 1.0;
        if ((PMSM_to_BLDC_mod1_B.En_State == 1.0) &&
            (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 5000)) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_init1;
          PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 1.0;
        }
        break;

       case PMSM_to_BLDC__IN_Initialization:
        PMSM_to_BLDC_mod1_B.En_State = 0.0;
        if ((PMSM_to_BLDC_mod1_DW.CS_val == 1.0) &&
            (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 40)) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_En_Gate;
          PMSM_to_BLDC_mod1_B.En_State = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_init1:
        PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 5000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_init2;
          PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 0.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_init2:
        PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 1000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_init3;
          PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_init3:
        PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 3000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_init4;
          PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 0.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_init4:
        PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 1000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_write;
          PMSM_to_BLDC_mod1_B.spi_write1 = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write:
        PMSM_to_BLDC_mod1_B.spi_write1 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_write2;
          PMSM_to_BLDC_mod1_B.spi_write1 = 0.0;
        }
        break;

       case PMSM_to_BLDC_mod_IN_SPI_write10:
        PMSM_to_BLDC_mod1_B.spi_write4 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 1000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_write;
          PMSM_to_BLDC_mod1_B.spi_write1 = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write2:
        PMSM_to_BLDC_mod1_B.spi_write1 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_write5;
          PMSM_to_BLDC_mod1_B.spi_write2 = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write5:
        PMSM_to_BLDC_mod1_B.spi_write2 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_write6;
          PMSM_to_BLDC_mod1_B.spi_write2 = 0.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write6:
        PMSM_to_BLDC_mod1_B.spi_write2 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_write7;
          PMSM_to_BLDC_mod1_B.spi_write3 = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write7:
        PMSM_to_BLDC_mod1_B.spi_write3 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_write8;
          PMSM_to_BLDC_mod1_B.spi_write3 = 0.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write8:
        PMSM_to_BLDC_mod1_B.spi_write3 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_write9;
          PMSM_to_BLDC_mod1_B.spi_write4 = 1.0;
        }
        break;

       default:
        /* case IN_SPI_write9: */
        PMSM_to_BLDC_mod1_B.spi_write4 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod_IN_SPI_write10;
          PMSM_to_BLDC_mod1_B.spi_write4 = 0.0;
        }
        break;
      }
    }

    /* End of Chart: '<Root>/Chart' */
  }

  if (tmp_0) {
    /* Outputs for Atomic SubSystem: '<Root>/SPI_Write' */
    /* Logic: '<S4>/AND1' */
    PMSM_to_BLDC_mod1_B.AND1 = ((PMSM_to_BLDC_mod1_B.En_State != 0.0) &&
      (PMSM_to_BLDC_mod1_B.Ctrl_flag2 != 0.0));

    /* Outputs for Enabled SubSystem: '<S4>/Control_Reg2' incorporates:
     *  EnablePort: '<S20>/Enable'
     */
    if (PMSM_to_BLDC_mod1_B.AND1) {
      if (!PMSM_to_BLDC_mod1_DW.Control_Reg2_MODE) {
        /* SystemReset for Atomic SubSystem: '<S20>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift);

        /* End of SystemReset for SubSystem: '<S20>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S20>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1);

        /* End of SystemReset for SubSystem: '<S20>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Control_Reg2_MODE = true;
      }

      /* MATLABSystem: '<S20>/SPI Receive' */
      status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_g.MW_SPI_HANDLE,
        2U, 3840U, MW_SPI_MODE_3);
      if (status == 0) {
        MW_SPI_Read_Databits(PMSM_to_BLDC_mod1_DW.obj_g.MW_SPI_HANDLE, &tmp[0],
                             16U, 1, 1, 1U);
        LL_GPIO_SetOutputPin(GPIOC, 16384U);
      }

      /* End of MATLABSystem: '<S20>/SPI Receive' */

      /* Outputs for Atomic SubSystem: '<S20>/Bit Shift' */
      /* Constant: '<S20>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(0, &status, &PMSM_to_BLDC_mod1_DW.BitShift);

      /* End of Outputs for SubSystem: '<S20>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S20>/Bit Shift1' */
      /* Constant: '<S20>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(3, &y_nb, &PMSM_to_BLDC_mod1_DW.BitShift1);

      /* End of Outputs for SubSystem: '<S20>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S20>/Bitwise OR' */
      PMSM_to_BLDC_mod1_B.BitwiseOR_n = (uint16_T)(status | y_nb |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_jx);

      /* DataTypeConversion: '<S20>/Data Type Conversion' */
      PMSM_to_BLDC_mod1_B.DataTypeConversion_m = PMSM_to_BLDC_mod1_B.BitwiseOR_n;

      /* MATLABSystem: '<S20>/SPI Transmit' */
      status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE,
        2U, 3840U, MW_SPI_MODE_3);
      if (status == 0) {
        LL_GPIO_ResetOutputPin(GPIOC, 16384U);
        MW_SPI_Write_Databits(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE,
                              &PMSM_to_BLDC_mod1_B.DataTypeConversion_m, 1U, 1,
                              1, 1000U);
      }

      /* End of MATLABSystem: '<S20>/SPI Transmit' */
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC);
    } else {
      PMSM_to_BLDC_mod1_DW.Control_Reg2_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S4>/Control_Reg2' */

    /* Logic: '<S4>/AND' */
    PMSM_to_BLDC_mod1_B.AND = ((PMSM_to_BLDC_mod1_B.En_State != 0.0) &&
      (PMSM_to_BLDC_mod1_B.Ctrl_flag1 != 0.0));

    /* Outputs for Enabled SubSystem: '<S4>/Ctrl_Reg_1' incorporates:
     *  EnablePort: '<S21>/Enable'
     */
    if (PMSM_to_BLDC_mod1_B.AND) {
      if (!PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_MODE) {
        /* SystemReset for Atomic SubSystem: '<S21>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_h);

        /* End of SystemReset for SubSystem: '<S21>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S21>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_d);

        /* End of SystemReset for SubSystem: '<S21>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_MODE = true;
      }

      /* Outputs for Atomic SubSystem: '<S21>/Bit Shift' */
      /* Constant: '<S21>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(0, &status, &PMSM_to_BLDC_mod1_DW.BitShift_h);

      /* End of Outputs for SubSystem: '<S21>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S21>/Bit Shift1' */
      /* Constant: '<S21>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(2, &y_nb, &PMSM_to_BLDC_mod1_DW.BitShift1_d);

      /* End of Outputs for SubSystem: '<S21>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S21>/Bitwise OR' */
      PMSM_to_BLDC_mod1_B.BitwiseOR_e = (uint16_T)(status | y_nb |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_e);

      /* MATLABSystem: '<S21>/SPI Transmit' */
      status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_n.MW_SPI_HANDLE,
        2U, 3840U, MW_SPI_MODE_3);
      if (status == 0) {
        LL_GPIO_ResetOutputPin(GPIOC, 16384U);
        MW_SPI_Write_Databits(PMSM_to_BLDC_mod1_DW.obj_n.MW_SPI_HANDLE,
                              &PMSM_to_BLDC_mod1_B.BitwiseOR_e, 1U, 1, 1, 10U);
      }

      /* End of MATLABSystem: '<S21>/SPI Transmit' */
      /* MATLABSystem: '<S21>/SPI Receive' */
      status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, 2U,
        3840U, MW_SPI_MODE_3);
      if (status == 0) {
        MW_SPI_Read_Databits(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, &status, 1U,
                             1, 1, 1U);
        LL_GPIO_SetOutputPin(GPIOC, 16384U);
      }

      /* End of MATLABSystem: '<S21>/SPI Receive' */
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC);
    } else {
      PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S4>/Ctrl_Reg_1' */
  }

  if (tmp_1) {
    /* Outputs for Enabled SubSystem: '<S6>/Status_Reg1_read' incorporates:
     *  EnablePort: '<S46>/Ctrl_flag1'
     */
    /* Outputs for Enabled SubSystem: '<S6>/Status_Reg_2_read' incorporates:
     *  EnablePort: '<S47>/Ctrl_flag2'
     */
    tmp_2 = rtsiIsModeUpdateTimeStep(&PMSM_to_BLDC_mod1_M->solverInfo);

    /* End of Outputs for SubSystem: '<S6>/Status_Reg1_read' */
    if (tmp_2) {
      if (PMSM_to_BLDC_mod1_B.spi_write2 > 0.0) {
        if (!PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_MODE) {
          /* SystemReset for Atomic SubSystem: '<S47>/Bit Shift' */
          PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_n);

          /* End of SystemReset for SubSystem: '<S47>/Bit Shift' */

          /* SystemReset for Atomic SubSystem: '<S47>/Bit Shift1' */
          PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_o);

          /* End of SystemReset for SubSystem: '<S47>/Bit Shift1' */
          PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_MODE = true;
        }
      } else if (PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_MODE) {
        for (i = 0; i < 15; i++) {
          /* Disable for MATLABSystem: '<S47>/SPI Receive' incorporates:
           *  Outport: '<S47>/Out1'
           */
          PMSM_to_BLDC_mod1_B.SPIReceive_pnaevv.SPIReceive[i] = 0U;
        }

        PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_MODE = false;
      }
    }

    if (PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_MODE) {
      PMSM_to_BLDC_mod1_SPIReceive_pn(&PMSM_to_BLDC_mod1_B.SPIReceive_pnaevv,
        &PMSM_to_BLDC_mod1_DW.SPIReceive_pnaevv);

      /* Outputs for Atomic SubSystem: '<S47>/Bit Shift' */
      /* Constant: '<S47>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(1, &status, &PMSM_to_BLDC_mod1_DW.BitShift_n);

      /* End of Outputs for SubSystem: '<S47>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S47>/Bit Shift1' */
      /* Constant: '<S47>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(1, &y_nb, &PMSM_to_BLDC_mod1_DW.BitShift1_o);

      /* End of Outputs for SubSystem: '<S47>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S47>/Bitwise OR' */
      PMSM_to_BLDC_mod1_B.BitwiseOR = (uint16_T)(status | y_nb |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND);
      PMSM_to_BLDC_mod1_SPITransmit_p(PMSM_to_BLDC_mod1_B.BitwiseOR,
        &PMSM_to_BLDC_mod1_DW.SPITransmit_pnaevv);
      if (tmp_2) {
        srUpdateBC(PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S6>/Status_Reg_2_read' */

    /* Outputs for Enabled SubSystem: '<S6>/Status_Reg1_read' incorporates:
     *  EnablePort: '<S46>/Ctrl_flag1'
     */
    if (tmp_2) {
      if (PMSM_to_BLDC_mod1_B.spi_write1 > 0.0) {
        if (!PMSM_to_BLDC_mod1_DW.Status_Reg1_read_MODE) {
          /* SystemReset for Atomic SubSystem: '<S46>/Bit Shift' */
          PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_p);

          /* End of SystemReset for SubSystem: '<S46>/Bit Shift' */

          /* SystemReset for Atomic SubSystem: '<S46>/Bit Shift1' */
          PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_j);

          /* End of SystemReset for SubSystem: '<S46>/Bit Shift1' */
          PMSM_to_BLDC_mod1_DW.Status_Reg1_read_MODE = true;
        }
      } else if (PMSM_to_BLDC_mod1_DW.Status_Reg1_read_MODE) {
        /* Disable for Outport: '<S46>/Out1' incorporates:
         *  MATLABSystem: '<S46>/SPI Receive'
         */
        for (i = 0; i < 15; i++) {
          PMSM_to_BLDC_mod1_B.SPIReceive_pnaev.SPIReceive[i] = 0U;
        }

        /* End of Disable for Outport: '<S46>/Out1' */
        PMSM_to_BLDC_mod1_DW.Status_Reg1_read_MODE = false;
      }
    }

    if (PMSM_to_BLDC_mod1_DW.Status_Reg1_read_MODE) {
      PMSM_to_BLDC_mod1_SPIReceive_pn(&PMSM_to_BLDC_mod1_B.SPIReceive_pnaev,
        &PMSM_to_BLDC_mod1_DW.SPIReceive_pnaev);

      /* Outputs for Atomic SubSystem: '<S46>/Bit Shift' */
      /* Constant: '<S46>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(1, &status, &PMSM_to_BLDC_mod1_DW.BitShift_p);

      /* End of Outputs for SubSystem: '<S46>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S46>/Bit Shift1' */
      /* Constant: '<S46>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(0, &y_nb, &PMSM_to_BLDC_mod1_DW.BitShift1_j);

      /* End of Outputs for SubSystem: '<S46>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S46>/Bitwise OR' */
      PMSM_to_BLDC_mod1_B.BitwiseOR_p = (uint16_T)(status | y_nb |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_m);

      /* DataTypeConversion: '<S46>/Data Type Conversion' */
      PMSM_to_BLDC_mod1_B.DataTypeConversion_d = PMSM_to_BLDC_mod1_B.BitwiseOR_p;
      PMSM_to_BLDC_mod1_SPITransmit_p(PMSM_to_BLDC_mod1_B.DataTypeConversion_d,
        &PMSM_to_BLDC_mod1_DW.SPITransmit_pnaev);
      if (tmp_2) {
        srUpdateBC(PMSM_to_BLDC_mod1_DW.Status_Reg1_read_SubsysRanBC);
      }
    }

    /* End of Outputs for SubSystem: '<S6>/Status_Reg1_read' */
  }

  if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
      PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[4] == 0) {
  }

  /* Outputs for Enabled SubSystem: '<Root>/Subsystem' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (tmp_1 && rtsiIsModeUpdateTimeStep(&PMSM_to_BLDC_mod1_M->solverInfo)) {
    if (PMSM_to_BLDC_mod1_B.FOC_flag > 0.0) {
      if (!PMSM_to_BLDC_mod1_DW.Subsystem_MODE) {
        (void) memset(&(PMSM_to_BLDC_mod1_XDis.Integrator_CSTATE), 0,
                      4*sizeof(boolean_T));

        /* InitializeConditions for Delay: '<S56>/Delay' */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[0] = 0.0;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[1] = 0.0;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[2] = 0.0;

        /* InitializeConditions for Delay: '<S232>/Delay1' */
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f = 0.0F;

        /* InitializeConditions for Delay: '<S59>/Delay' */
        memset(&PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[0], 0, sizeof(real_T) << 3U);

        /* InitializeConditions for Delay: '<S236>/Delay' */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0] = 0.0;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1] = 0.0;

        /* InitializeConditions for Delay: '<S249>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad = true;

        /* InitializeConditions for Delay: '<S332>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_f = true;

        /* InitializeConditions for Delay: '<S356>/Delay' */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj = 0.0;

        /* InitializeConditions for DiscreteIntegrator: '<S301>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE = 0.0;
        PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState = 0;

        /* InitializeConditions for Delay: '<S357>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_a = true;

        /* InitializeConditions for DiscreteIntegrator: '<S171>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b =
          PMSM_to_BLDC_mod1_ConstB.Constant3_n;
        PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState_n = 0;

        /* InitializeConditions for Delay: '<S56>/Delay1' */
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx = 0.0F;

        /* InitializeConditions for Integrator: '<S437>/Integrator' */
        PMSM_to_BLDC_mod1_X.Integrator_CSTATE = 0.0;

        /* InitializeConditions for DiscreteIntegrator: '<S116>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n =
          PMSM_to_BLDC_mod1_ConstB.Constant3;
        PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState_nt = 0;

        /* InitializeConditions for Delay: '<S263>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_b = true;

        /* InitializeConditions for Integrator: '<S375>/Int1' */
        PMSM_to_BLDC_mod1_X.Int1_CSTATE = 0.0;

        /* InitializeConditions for Integrator: '<S390>/Integrator' incorporates:
         *  Integrator: '<S391>/Integrator'
         */
        if (rtmIsFirstInitCond(PMSM_to_BLDC_mod1_M)) {
          PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d = 0.0;
          PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l = 0.0;
        }

        PMSM_to_BLDC_mod1_DW.Integrator_DWORK1 = true;

        /* End of InitializeConditions for Integrator: '<S390>/Integrator' */

        /* InitializeConditions for Integrator: '<S391>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DWORK1_g = true;
        PMSM_to_BLDC_mod1_DW.Subsystem_MODE = true;
      }
    } else {
      if (((PMSM_to_BLDC_mod1_M->Timing.clockTick2) * 0.001) == rtmGetTStart
          (PMSM_to_BLDC_mod1_M)) {
        (void) memset(&(PMSM_to_BLDC_mod1_XDis.Integrator_CSTATE), 1,
                      4*sizeof(boolean_T));
      }

      if (PMSM_to_BLDC_mod1_DW.Subsystem_MODE) {
        (void) memset(&(PMSM_to_BLDC_mod1_XDis.Integrator_CSTATE), 1,
                      4*sizeof(boolean_T));

        /* Disable for If: '<S250>/If' */
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem = -1;

        /* Disable for SwitchCase: '<S259>/Switch Case' */
        PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem = -1;

        /* Disable for If: '<S256>/If' */
        rtsiSetBlockStateForSolverChangedAtMajorStep
          (&PMSM_to_BLDC_mod1_M->solverInfo, true);
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_g = -1;

        /* Disable for SwitchCase: '<S258>/Switch Case' */
        PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem_n = -1;

        /* Disable for If: '<S361>/If' */
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_e = -1;

        /* Disable for If: '<S222>/If' */
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_c = -1;

        /* Disable for If: '<S196>/If' */
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_m = -1;
        PMSM_to_BLDC_mod1_DW.Subsystem_MODE = false;
      }
    }
  }

  if (PMSM_to_BLDC_mod1_DW.Subsystem_MODE) {
    tmp_2 = (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
             PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0);
    if (tmp_2) {
      /* DataTypeConversion: '<S230>/Data Type  Conversion' incorporates:
       *  Delay: '<S56>/Delay'
       */
      PMSM_to_BLDC_mod1_B.DataTypeConversion[0] =
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[0];
      PMSM_to_BLDC_mod1_B.DataTypeConversion[1] =
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[1];
      PMSM_to_BLDC_mod1_B.DataTypeConversion[2] =
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[2];

      /* Gain: '<S76>/one_by_3' incorporates:
       *  Sum: '<S76>/Sum'
       */
      rtb_Gain_e = ((PMSM_to_BLDC_mod1_B.DataTypeConversion[0] +
                     PMSM_to_BLDC_mod1_B.DataTypeConversion[1]) +
                    PMSM_to_BLDC_mod1_B.DataTypeConversion[2]) *
        0.33333333333333331;

      /* Gain: '<S76>/Kalphabeta0' incorporates:
       *  Gain: '<S76>/one_by_sqrt3_'
       *  Sum: '<S76>/Sum1'
       *  Sum: '<S76>/Sum2'
       */
      PMSM_to_BLDC_mod1_B.Kalphabeta0[0] =
        PMSM_to_BLDC_mod1_B.DataTypeConversion[0] - rtb_Gain_e;
      PMSM_to_BLDC_mod1_B.Kalphabeta0[1] =
        (PMSM_to_BLDC_mod1_B.DataTypeConversion[1] -
         PMSM_to_BLDC_mod1_B.DataTypeConversion[2]) * 0.57735026918962584;
      PMSM_to_BLDC_mod1_B.Kalphabeta0[2] = rtb_Gain_e;

      /* Delay: '<S232>/Delay1' */
      if (PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE == POS_ZCSIG) {
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f = 0.0F;
      }

      PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE = 0U;

      /* Gain: '<S238>/Gain' incorporates:
       *  Delay: '<S232>/Delay1'
       */
      rtb_Add3 = -0.0017999999690800905 * PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f;

      /* Gain: '<S245>/Gain1' incorporates:
       *  Delay: '<S59>/Delay'
       */
      rtb_Sum1_eq = 555.55555555555554 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[1];

      /* Gain: '<S245>/Gain' incorporates:
       *  Delay: '<S59>/Delay'
       */
      rtb_Gain_e = 555.55555555555554 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[0];

      /* Sum: '<S246>/Sum' incorporates:
       *  Product: '<S246>/Product'
       *  Product: '<S246>/Product2'
       *  UnaryMinus: '<S246>/Unary Minus'
       */
      rtb_Add1_f = -rtb_Add3 * rtb_Sum1_eq - rtb_Gain_e;

      /* Sum: '<S246>/Sum1' incorporates:
       *  Product: '<S246>/Product1'
       *  Product: '<S246>/Product3'
       */
      rtb_Add3 = rtb_Gain_e * rtb_Add3 - rtb_Sum1_eq;

      /* Gain: '<S237>/Gain' incorporates:
       *  Delay: '<S232>/Delay1'
       */
      rtb_Gain_e = -0.0017999999690800905 * PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f;

      /* Sum: '<S242>/Sum1' incorporates:
       *  Delay: '<S59>/Delay'
       *  Product: '<S242>/Product3'
       */
      rtb_Sum1_eq = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[2] * rtb_Gain_e -
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[3];

      /* Product: '<S263>/Product1' incorporates:
       *  Delay: '<S59>/Delay'
       *  Product: '<S242>/Product2'
       *  Sum: '<S242>/Sum'
       *  UnaryMinus: '<S242>/Unary Minus'
       */
      rtb_Product1_o = -rtb_Gain_e * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[3] -
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[2];

      /* Gain: '<S240>/Gain1' */
      rtb_Saturation_k = 555.55555555555554 * rtb_Sum1_eq;

      /* Gain: '<S240>/Gain' */
      rtb_Gain4_i_tmp = 555.55555555555554 * rtb_Product1_o;

      /* Sum: '<S243>/Sum1' incorporates:
       *  Gain: '<S240>/Gain'
       *  Gain: '<S240>/Gain1'
       *  Product: '<S243>/Product3'
       *  UnaryMinus: '<S240>/Unary Minus'
       */
      rtb_Gain4_g = -rtb_Gain4_i_tmp * rtb_Gain_e + rtb_Saturation_k;

      /* Gain: '<S383>/Gain3' incorporates:
       *  Constant: '<S239>/(Ld-Lq)_Ld'
       *  Constant: '<S239>/R_Ld'
       *  Delay: '<S232>/Delay1'
       *  Delay: '<S59>/Delay'
       *  Product: '<S239>/Product'
       *  Product: '<S239>/Product3'
       *  Product: '<S239>/Product5'
       *  Sum: '<S239>/Sum1'
       *  UnaryMinus: '<S239>/Unary Minus1'
       */
      rtb_Gain3_c = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[3] * -20.555555555555554;
      rtb_Gain3_c += PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[2] *
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f * 0.0;

      /* Product: '<S244>/Product2' incorporates:
       *  UnaryMinus: '<S244>/Unary Minus'
       */
      rtb_Product2_a = -rtb_Gain_e * rtb_Gain3_c;

      /* Sum: '<S239>/Sum' incorporates:
       *  Constant: '<S239>/(Ld-Lq)_Ld'
       *  Constant: '<S239>/R_Ld'
       *  Delay: '<S232>/Delay1'
       *  Delay: '<S59>/Delay'
       *  Product: '<S239>/Product1'
       *  Product: '<S239>/Product2'
       *  Product: '<S239>/Product4'
       *  UnaryMinus: '<S239>/Unary Minus'
       *  UnaryMinus: '<S239>/Unary Minus1'
       */
      rtb_Integrator_l = -(PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[3] *
                           PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f) * 0.0 +
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[2] * -20.555555555555554;

      /* Gain: '<S383>/Gain3' incorporates:
       *  Product: '<S244>/Product1'
       *  Product: '<S244>/Product3'
       *  Sum: '<S244>/Sum1'
       */
      rtb_Gain3_c = rtb_Integrator_l * rtb_Gain_e - rtb_Gain3_c;

      /* Delay: '<S236>/Delay' */
      if (PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE == POS_ZCSIG) {
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0] = 0.0;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1] = 0.0;
      }

      PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE = 0U;

      /* Sum: '<S236>/Sum2' incorporates:
       *  Delay: '<S236>/Delay'
       *  Sum: '<S236>/Sum'
       */
      rtb_Saturation2_idx_0 = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0];
      tmp_4 = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1];

      /* Gain: '<S236>/Gain2' incorporates:
       *  Delay: '<S232>/Delay1'
       *  Delay: '<S236>/Delay'
       *  Gain: '<S236>/Gain1'
       *  Product: '<S241>/Product'
       *  Product: '<S241>/Product1'
       *  Product: '<S243>/Product2'
       *  Product: '<S244>/Product'
       *  Sum: '<S236>/Sum'
       *  Sum: '<S236>/Sum2'
       *  Sum: '<S237>/Sum'
       *  Sum: '<S243>/Sum'
       *  Sum: '<S244>/Sum'
       *  UnaryMinus: '<S240>/Unary Minus1'
       *  UnaryMinus: '<S241>/Unary Minus'
       *  UnaryMinus: '<S243>/Unary Minus'
       */
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0] = ((((-(rtb_Sum1_eq *
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f) - (-rtb_Saturation_k * -rtb_Gain_e
        + rtb_Gain4_i_tmp)) - (rtb_Product2_a - rtb_Integrator_l)) - rtb_Add1_f)
        * 5.0E-5 + rtb_Saturation2_idx_0) * 0.972972972972973;
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1] = ((((rtb_Product1_o *
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f - rtb_Gain4_g) - rtb_Gain3_c) -
        rtb_Add3) * 5.0E-5 + tmp_4) * 0.972972972972973;

      /* Delay: '<S249>/Delay' incorporates:
       *  Constant: '<S234>/IC'
       */
      if (PMSM_to_BLDC_mod1_DW.icLoad) {
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[0] = 0.0;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[1] = 0.0;
      }

      /* Sum: '<S249>/Add1' incorporates:
       *  Constant: '<S232>/V_PU'
       *  Delay: '<S236>/Delay'
       *  Delay: '<S249>/Delay'
       *  Product: '<S232>/Product'
       *  Product: '<S249>/Product'
       *  Product: '<S249>/Product1'
       *  Sum: '<S236>/Sum1'
       */
      rtb_Add1[0] = (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0] + rtb_Product1_o) *
        0.020833333333333332 * 0.70204348915944692 +
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[0] * 0.29795651084055308;
      rtb_Add1[1] = (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1] + rtb_Sum1_eq) *
        0.020833333333333332 * 0.70204348915944692 + 0.29795651084055308 *
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[1];

      /* Relay: '<S250>/AlphaRelay' */
      PMSM_to_BLDC_mod1_DW.AlphaRelay_Mode = ((rtb_Add1[0] >= 0.02) ||
        ((!(rtb_Add1[0] <= -0.02)) && PMSM_to_BLDC_mod1_DW.AlphaRelay_Mode));

      /* Relay: '<S250>/BetaRelay' */
      PMSM_to_BLDC_mod1_DW.BetaRelay_Mode = ((rtb_Add1[1] >= 0.02) ||
        ((!(rtb_Add1[1] <= -0.02)) && PMSM_to_BLDC_mod1_DW.BetaRelay_Mode));

      /* Outputs for IfAction SubSystem: '<S259>/If Action Subsystem' incorporates:
       *  ActionPort: '<S353>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S259>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S354>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S250>/Subsystem2' incorporates:
       *  ActionPort: '<S253>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S250>/Subsystem3' incorporates:
       *  ActionPort: '<S254>/Action Port'
       */
      /* Outputs for Triggered SubSystem: '<S250>/Dir_Sense' incorporates:
       *  TriggerPort: '<S252>/Trigger'
       */
      /* If: '<S250>/If' incorporates:
       *  Relay: '<S250>/AlphaRelay'
       *  SwitchCase: '<S259>/Switch Case'
       */
      tmp_3 = rtsiIsModeUpdateTimeStep(&PMSM_to_BLDC_mod1_M->solverInfo);

      /* End of Outputs for SubSystem: '<S250>/Subsystem3' */
      /* End of Outputs for SubSystem: '<S250>/Subsystem2' */
      /* End of Outputs for SubSystem: '<S259>/If Action Subsystem1' */
      /* End of Outputs for SubSystem: '<S259>/If Action Subsystem' */
      if (tmp_3) {
        if (PMSM_to_BLDC_mod1_DW.AlphaRelay_Mode &&
            (PMSM_to_BLDC_mod1_PrevZCX.Dir_Sense_Trig_ZCE != POS_ZCSIG)) {
          /* Switch: '<S252>/Switch' incorporates:
           *  Relay: '<S250>/BetaRelay'
           */
          if (PMSM_to_BLDC_mod1_DW.BetaRelay_Mode) {
            /* Switch: '<S252>/Switch' incorporates:
             *  Constant: '<S252>/Constant'
             */
            PMSM_to_BLDC_mod1_B.Switch = -1;
          } else {
            /* Switch: '<S252>/Switch' incorporates:
             *  Constant: '<S252>/Constant1'
             */
            PMSM_to_BLDC_mod1_B.Switch = 1;
          }

          /* End of Switch: '<S252>/Switch' */
          PMSM_to_BLDC_mod1_DW.Dir_Sense_SubsysRanBC = 4;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Dir_Sense_Trig_ZCE =
          PMSM_to_BLDC_mod1_DW.AlphaRelay_Mode;
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem = (int8_T)
          (PMSM_to_BLDC_mod1_B.Switch <= 0);
      }

      /* End of Outputs for SubSystem: '<S250>/Dir_Sense' */
      guard1 = false;
      if (PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem == 0) {
        /* Outputs for IfAction SubSystem: '<S250>/Subsystem2' incorporates:
         *  ActionPort: '<S253>/Action Port'
         */
        /* UnaryMinus: '<S253>/Unary Minus' */
        rtb_Add1_f = -rtb_Add1[0];

        /* SignalConversion generated from: '<S253>/SigmaBeta' */
        rtb_Gain_e = rtb_Add1[1];

        /* End of Outputs for SubSystem: '<S250>/Subsystem2' */
        if (tmp_3) {
          /* Outputs for IfAction SubSystem: '<S250>/Subsystem2' incorporates:
           *  ActionPort: '<S253>/Action Port'
           */
          srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem2_SubsysRanBC);

          /* End of Outputs for SubSystem: '<S250>/Subsystem2' */
          guard1 = true;
        }
      } else {
        /* Outputs for IfAction SubSystem: '<S250>/Subsystem3' incorporates:
         *  ActionPort: '<S254>/Action Port'
         */
        /* UnaryMinus: '<S254>/Unary Minus' */
        rtb_Gain_e = -rtb_Add1[1];

        /* SignalConversion generated from: '<S254>/SigmaAlpha' */
        rtb_Add1_f = rtb_Add1[0];

        /* End of Outputs for SubSystem: '<S250>/Subsystem3' */
        if (tmp_3) {
          /* Outputs for IfAction SubSystem: '<S250>/Subsystem3' incorporates:
           *  ActionPort: '<S254>/Action Port'
           */
          srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem3_SubsysRanBC);

          /* End of Outputs for SubSystem: '<S250>/Subsystem3' */
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

      /* End of If: '<S250>/If' */

      /* SwitchCase: '<S259>/Switch Case' */
      if (PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem == 0) {
        /* Outputs for IfAction SubSystem: '<S259>/If Action Subsystem' incorporates:
         *  ActionPort: '<S353>/Action Port'
         */
        /* Merge: '<S259>/Merge' incorporates:
         *  Constant: '<S259>/Constant'
         *  SignalConversion generated from: '<S353>/In1'
         *  SignalConversion generated from: '<S353>/Out1'
         */
        PMSM_to_BLDC_mod1_B.Merge[0] = 0.0;
        PMSM_to_BLDC_mod1_B.Merge[1] = 0.0;
        if (tmp_3) {
          srUpdateBC(PMSM_to_BLDC_mod1_DW.IfActionSubsystem_SubsysRanBC_a);
        }

        /* End of Outputs for SubSystem: '<S259>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S259>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S354>/Action Port'
         */
        /* Merge: '<S259>/Merge' incorporates:
         *  SignalConversion generated from: '<S354>/In1'
         */
        PMSM_to_BLDC_mod1_B.Merge[0] = rtb_Add1_f;
        PMSM_to_BLDC_mod1_B.Merge[1] = rtb_Gain_e;
        if (tmp_3) {
          srUpdateBC(PMSM_to_BLDC_mod1_DW.IfActionSubsystem1_SubsysRanB_e);
        }

        /* End of Outputs for SubSystem: '<S259>/If Action Subsystem1' */
      }

      /* Product: '<S256>/Product' */
      rtb_Gain_e = PMSM_to_BLDC_mod1_B.Merge[0] * PMSM_to_BLDC_mod1_B.Merge[0];

      /* Gain: '<S383>/Gain3' incorporates:
       *  Product: '<S256>/Product1'
       */
      rtb_Gain3_c = PMSM_to_BLDC_mod1_B.Merge[1] * PMSM_to_BLDC_mod1_B.Merge[1];

      /* Sum: '<S256>/Sum' */
      PMSM_to_BLDC_mod1_B.Sum = rtb_Gain_e + rtb_Gain3_c;

      /* RelationalOperator: '<S264>/Compare' incorporates:
       *  Constant: '<S264>/Constant'
       */
      PMSM_to_BLDC_mod1_B.Compare = (PMSM_to_BLDC_mod1_B.Sum > 0.0);
    }

    /* If: '<S256>/If' */
    rtPrevAction = PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_g;

    /* Outputs for IfAction SubSystem: '<S196>/If Action Subsystem' incorporates:
     *  ActionPort: '<S199>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S196>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S200>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S222>/If Action Subsystem' incorporates:
     *  ActionPort: '<S225>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S222>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S226>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S361>/If Action Subsystem' incorporates:
     *  ActionPort: '<S364>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S361>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S365>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S258>/IntegralMethod' incorporates:
     *  ActionPort: '<S322>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S258>/OptimizedDifferentiationMethod' incorporates:
     *  ActionPort: '<S325>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S256>/Subsystem' incorporates:
     *  ActionPort: '<S266>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S256>/If Action Subsystem' incorporates:
     *  ActionPort: '<S265>/Action Port'
     */
    /* If: '<S222>/If' incorporates:
     *  If: '<S196>/If'
     *  If: '<S256>/If'
     *  If: '<S361>/If'
     *  SwitchCase: '<S258>/Switch Case'
     */
    tmp_3 = rtsiIsModeUpdateTimeStep(&PMSM_to_BLDC_mod1_M->solverInfo);

    /* End of Outputs for SubSystem: '<S256>/If Action Subsystem' */
    /* End of Outputs for SubSystem: '<S256>/Subsystem' */
    /* End of Outputs for SubSystem: '<S258>/OptimizedDifferentiationMethod' */
    /* End of Outputs for SubSystem: '<S258>/IntegralMethod' */
    /* End of Outputs for SubSystem: '<S361>/If Action Subsystem1' */
    /* End of Outputs for SubSystem: '<S361>/If Action Subsystem' */
    /* End of Outputs for SubSystem: '<S222>/If Action Subsystem1' */
    /* End of Outputs for SubSystem: '<S222>/If Action Subsystem' */
    /* End of Outputs for SubSystem: '<S196>/If Action Subsystem1' */
    /* End of Outputs for SubSystem: '<S196>/If Action Subsystem' */

    /* If: '<S256>/If' */
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
      /* Outputs for IfAction SubSystem: '<S256>/Subsystem' incorporates:
       *  ActionPort: '<S266>/Action Port'
       */
      /* Sqrt: '<S266>/Sqrt' */
      rtb_Product1_o = sqrt(PMSM_to_BLDC_mod1_B.Sum);

      /* Merge: '<S256>/Merge1' incorporates:
       *  Product: '<S266>/Divide'
       *  SignalConversion generated from: '<S266>/Out2'
       */
      rtb_Add1_f = 1.0 / rtb_Product1_o * PMSM_to_BLDC_mod1_B.Merge[1];

      /* Merge: '<S256>/Merge' incorporates:
       *  Product: '<S266>/Divide1'
       *  SignalConversion generated from: '<S266>/Out1'
       */
      rtb_Product1_o = PMSM_to_BLDC_mod1_B.Merge[0] / rtb_Product1_o;
      if (tmp_3) {
        srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_o);
      }

      /* End of Outputs for SubSystem: '<S256>/Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S256>/If Action Subsystem' incorporates:
       *  ActionPort: '<S265>/Action Port'
       */
      /* Merge: '<S256>/Merge' incorporates:
       *  DataTypeConversion: '<S265>/Data Type Conversion'
       *  SignalConversion generated from: '<S265>/Out1'
       */
      rtb_Product1_o = PMSM_to_BLDC_mod1_B.Merge[0];

      /* Merge: '<S256>/Merge1' incorporates:
       *  DataTypeConversion: '<S265>/Data Type Conversion1'
       *  SignalConversion generated from: '<S265>/Out2'
       */
      rtb_Add1_f = PMSM_to_BLDC_mod1_B.Merge[1];
      if (tmp_3) {
        srUpdateBC(PMSM_to_BLDC_mod1_DW.IfActionSubsystem_SubsysRanBC_b);
      }

      /* End of Outputs for SubSystem: '<S256>/If Action Subsystem' */
    }

    if (tmp_2) {
      /* SwitchCase: '<S258>/Switch Case' incorporates:
       *  Delay: '<S349>/Delay'
       */
      if (tmp_3) {
        rtAction = 1;
        PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem_n = 1;
      } else {
        rtAction = PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem_n;
      }

      if (rtAction == 0) {
        /* Outputs for IfAction SubSystem: '<S258>/IntegralMethod' incorporates:
         *  ActionPort: '<S322>/Action Port'
         */
        /* Delay: '<S339>/Delay' */
        if (PMSM_to_BLDC_mod1_DW.icLoad_bd) {
          /* Sum: '<S339>/Add1' incorporates:
           *  Constant: '<S333>/IC'
           */
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av = 0.0;
        }

        /* Sum: '<S339>/Add1' incorporates:
         *  Delay: '<S339>/Delay'
         *  Product: '<S339>/Product'
         *  Product: '<S339>/Product1'
         *  Switch: '<S339>/Switch'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av = rtb_Add1_f * 0.95650500031643548
          + 0.043494999683564517 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av;

        /* Delay: '<S336>/Delay1' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_p == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay1_DSTATE = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_p = 0U;

        /* Delay: '<S336>/Delay' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_h == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_f = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_h = 0U;

        /* Sum: '<S336>/Sum1' incorporates:
         *  Constant: '<S319>/I1Cnst'
         *  Constant: '<S319>/I2Cnst'
         *  Delay: '<S336>/Delay'
         *  Delay: '<S336>/Delay1'
         *  Product: '<S336>/Product'
         *  Product: '<S336>/Product1'
         *  Sum: '<S336>/Sum'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_f =
          (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av +
           PMSM_to_BLDC_mod1_DW.Delay1_DSTATE) * 2.4945142765920684E-5 +
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_f * 0.99561142127365465;

        /* Delay: '<S342>/Delay' */
        if (PMSM_to_BLDC_mod1_DW.icLoad_k) {
          /* Sum: '<S342>/Add1' incorporates:
           *  Constant: '<S334>/IC'
           */
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d = 0.0;
        }

        /* Sum: '<S342>/Add1' incorporates:
         *  Delay: '<S342>/Delay'
         *  Product: '<S342>/Product'
         *  Product: '<S342>/Product1'
         *  Switch: '<S342>/Switch'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d = rtb_Product1_o *
          0.95650500031643548 + 0.043494999683564517 *
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d;

        /* Delay: '<S335>/Delay1' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_i == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_o = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_i = 0U;

        /* Delay: '<S335>/Delay' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_k == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_k = 0U;

        /* Sum: '<S335>/Sum1' incorporates:
         *  Constant: '<S319>/I1Cnst'
         *  Constant: '<S319>/I2Cnst'
         *  Delay: '<S335>/Delay'
         *  Delay: '<S335>/Delay1'
         *  Product: '<S335>/Product'
         *  Product: '<S335>/Product1'
         *  Sum: '<S335>/Sum'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i =
          (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d +
           PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_o) * 2.4945142765920684E-5 +
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i * 0.99561142127365465;

        /* Math: '<S322>/Math Function' incorporates:
         *  Delay: '<S335>/Delay'
         *  Delay: '<S336>/Delay'
         *  Product: '<S322>/Product'
         *  Product: '<S322>/Product1'
         *  Sum: '<S322>/Sum'
         *
         * About '<S322>/Math Function':
         *  Operator: reciprocal
         */
        rtb_Gain4_g = 1.0 / (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_f *
                             rtb_Product1_o -
                             PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i * rtb_Add1_f);

        /* Switch: '<S322>/Switch1' incorporates:
         *  Abs: '<S322>/Abs'
         */
        if (fabs(rtb_Gain4_g) > 87964.5943005142) {
          /* Merge: '<S258>/Merge' incorporates:
           *  Constant: '<S322>/Constant'
           */
          rtb_Gain4_g = 0.0;
        }

        /* End of Switch: '<S322>/Switch1' */

        /* Update for Delay: '<S339>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_bd = false;

        /* Update for Delay: '<S336>/Delay1' */
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE =
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av;

        /* Update for Delay: '<S342>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_k = false;

        /* Update for Delay: '<S335>/Delay1' */
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_o =
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d;
        if (tmp_3) {
          srUpdateBC(PMSM_to_BLDC_mod1_DW.IntegralMethod_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S258>/IntegralMethod' */
      } else {
        /* Outputs for IfAction SubSystem: '<S258>/OptimizedDifferentiationMethod' incorporates:
         *  ActionPort: '<S325>/Action Port'
         */
        if (PMSM_to_BLDC_mod1_DW.icLoad_b1) {
          /* Sum: '<S349>/Add1' incorporates:
           *  Constant: '<S345>/IC'
           *  Delay: '<S349>/Delay'
           */
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aa = 0.0;
        }

        /* Sum: '<S349>/Add1' incorporates:
         *  Delay: '<S349>/Delay'
         *  Product: '<S349>/Product'
         *  Product: '<S349>/Product1'
         *  Switch: '<S349>/Switch'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aa = rtb_Add1_f * 0.95650500031643548
          + 0.043494999683564517 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aa;

        /* Product: '<S344>/Product' incorporates:
         *  Constant: '<S319>/OD1Cnst'
         */
        rtb_Gain_e = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aa *
          2.1991148575128554E+6;

        /* Delay: '<S344>/Delay2' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay2_DSTATE = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE = 0U;

        /* Delay: '<S344>/Delay3' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay3_DSTATE = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE = 0U;

        /* Product: '<S344>/Product1' incorporates:
         *  Constant: '<S319>/OD2Cnst'
         *  Delay: '<S344>/Delay2'
         *  Delay: '<S344>/Delay3'
         *  Sum: '<S344>/Sum1'
         */
        PMSM_to_BLDC_mod1_DW.Delay3_DSTATE =
          ((PMSM_to_BLDC_mod1_DW.Delay3_DSTATE + rtb_Gain_e) -
           PMSM_to_BLDC_mod1_DW.Delay2_DSTATE) * 0.0090126024492556654;

        /* Delay: '<S343>/Delay2' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE_p == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_h = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE_p = 0U;
        rtb_Gain4_g = PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_h;

        /* Delay: '<S343>/Delay3' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE_k == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_p = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE_k = 0U;

        /* Delay: '<S352>/Delay' */
        if (PMSM_to_BLDC_mod1_DW.icLoad_c) {
          /* Sum: '<S352>/Add1' incorporates:
           *  Constant: '<S346>/IC'
           */
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_l = 0.0;
        }

        /* Sum: '<S352>/Add1' incorporates:
         *  Delay: '<S352>/Delay'
         *  Product: '<S352>/Product'
         *  Product: '<S352>/Product1'
         *  Switch: '<S352>/Switch'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_l = rtb_Product1_o *
          0.95650500031643548 + 0.043494999683564517 *
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_l;

        /* Product: '<S343>/Product' incorporates:
         *  Constant: '<S319>/OD1Cnst'
         *  Delay: '<S343>/Delay2'
         */
        PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_h =
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_l * 2.1991148575128554E+6;

        /* Product: '<S343>/Product1' incorporates:
         *  Constant: '<S319>/OD2Cnst'
         *  Delay: '<S343>/Delay2'
         *  Delay: '<S343>/Delay3'
         *  Sum: '<S343>/Sum1'
         */
        PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_p =
          ((PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_p +
            PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_h) - rtb_Gain4_g) *
          0.0090126024492556654;

        /* Merge: '<S258>/Merge' incorporates:
         *  Delay: '<S343>/Delay3'
         *  Delay: '<S344>/Delay3'
         *  Product: '<S325>/Product'
         *  Product: '<S325>/Product1'
         *  Sum: '<S325>/Sum'
         */
        rtb_Gain4_g = PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_p * rtb_Add1_f -
          PMSM_to_BLDC_mod1_DW.Delay3_DSTATE * rtb_Product1_o;

        /* Update for Delay: '<S349>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_b1 = false;

        /* Update for Delay: '<S344>/Delay2' */
        PMSM_to_BLDC_mod1_DW.Delay2_DSTATE = rtb_Gain_e;

        /* Update for Delay: '<S352>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_c = false;
        if (tmp_3) {
          srUpdateBC(PMSM_to_BLDC_mod1_DW.OptimizedDifferentiationMethod_);
        }

        /* End of Outputs for SubSystem: '<S258>/OptimizedDifferentiationMethod' */
      }

      /* Gain: '<S383>/Gain3' incorporates:
       *  Constant: '<S258>/SpdFilterCoeff'
       *  Constant: '<S320>/One'
       *  Sum: '<S320>/Sum'
       */
      rtb_Gain3_c = 0.99530971347415453;

      /* Switch: '<S320>/Switch1' */
      rtb_Gain_e = rtb_Gain3_c;

      /* Delay: '<S332>/Delay' incorporates:
       *  Constant: '<S320>/IC'
       */
      if (PMSM_to_BLDC_mod1_DW.icLoad_f) {
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_a = 0.0;
      }

      /* Gain: '<S383>/Gain3' incorporates:
       *  Delay: '<S332>/Delay'
       *  Product: '<S332>/Product1'
       */
      rtb_Gain3_c = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_a;
      rtb_Gain3_c *= rtb_Gain_e;

      /* Sum: '<S332>/Add1' incorporates:
       *  Product: '<S332>/Product'
       *  Switch: '<S332>/Switch'
       */
      rtb_Add1_e = rtb_Gain4_g * 0.0046902865258454489 + rtb_Gain3_c;

      /* Delay: '<S356>/Delay' */
      if (PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_a == POS_ZCSIG) {
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj = 0.0;
      }

      PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_a = 0U;

      /* If: '<S361>/If' incorporates:
       *  Constant: '<S363>/Constant'
       *  DataTypeConversion: '<S356>/Data Type Conversion3'
       *  Delay: '<S356>/Delay'
       *  RelationalOperator: '<S363>/Compare'
       */
      if (tmp_3) {
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_e = (int8_T)!((real32_T)
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj < 0.0F);
      }

      if (PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_e == 0) {
        /* Outputs for IfAction SubSystem: '<S361>/If Action Subsystem' incorporates:
         *  ActionPort: '<S364>/Action Port'
         */
        /* DataTypeConversion: '<S364>/Convert_uint16' incorporates:
         *  DataTypeConversion: '<S356>/Data Type Conversion3'
         *  Delay: '<S356>/Delay'
         */
        rtb_Saturation_or = floorf((real32_T)
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj);
        if (rtIsNaNF(rtb_Saturation_or) || rtIsInfF(rtb_Saturation_or)) {
          rtb_Saturation_or = 0.0F;
        } else {
          rtb_Saturation_or = fmodf(rtb_Saturation_or, 65536.0F);
        }

        /* Sum: '<S364>/Sum' incorporates:
         *  DataTypeConversion: '<S356>/Data Type Conversion3'
         *  DataTypeConversion: '<S364>/Convert_back'
         *  DataTypeConversion: '<S364>/Convert_uint16'
         *  Delay: '<S356>/Delay'
         */
        rtb_indexing = (real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj -
          (real32_T)(rtb_Saturation_or < 0.0F ? (int32_T)(int16_T)-(int16_T)
                     (uint16_T)-rtb_Saturation_or : (int32_T)(int16_T)(uint16_T)
                     rtb_Saturation_or);
        if (tmp_3) {
          srUpdateBC(PMSM_to_BLDC_mod1_DW.IfActionSubsystem_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S361>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S361>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S365>/Action Port'
         */
        /* DataTypeConversion: '<S365>/Convert_uint16' incorporates:
         *  DataTypeConversion: '<S356>/Data Type Conversion3'
         *  Delay: '<S356>/Delay'
         */
        rtb_Saturation_or = truncf((real32_T)
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj);
        if (rtIsNaNF(rtb_Saturation_or) || rtIsInfF(rtb_Saturation_or)) {
          rtb_Saturation_or = 0.0F;
        } else {
          rtb_Saturation_or = fmodf(rtb_Saturation_or, 65536.0F);
        }

        /* Sum: '<S365>/Sum' incorporates:
         *  DataTypeConversion: '<S356>/Data Type Conversion3'
         *  DataTypeConversion: '<S365>/Convert_back'
         *  DataTypeConversion: '<S365>/Convert_uint16'
         *  Delay: '<S356>/Delay'
         */
        rtb_indexing = (real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj -
          (real32_T)(rtb_Saturation_or < 0.0F ? (int32_T)(int16_T)-(int16_T)
                     (uint16_T)-rtb_Saturation_or : (int32_T)(int16_T)(uint16_T)
                     rtb_Saturation_or);
        if (tmp_3) {
          srUpdateBC(PMSM_to_BLDC_mod1_DW.IfActionSubsystem1_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S361>/If Action Subsystem1' */
      }

      /* Gain: '<S359>/indexing' */
      rtb_indexing *= 800.0F;

      /* DataTypeConversion: '<S359>/Get_Integer' */
      rtb_Saturation_or = truncf(rtb_indexing);
      if (rtIsNaNF(rtb_Saturation_or) || rtIsInfF(rtb_Saturation_or)) {
        rtb_Saturation_or = 0.0F;
      } else {
        rtb_Saturation_or = fmodf(rtb_Saturation_or, 65536.0F);
      }

      status = (uint16_T)(rtb_Saturation_or < 0.0F ? (int32_T)(uint16_T)
                          -(int16_T)(uint16_T)-rtb_Saturation_or : (int32_T)
                          (uint16_T)rtb_Saturation_or);

      /* End of DataTypeConversion: '<S359>/Get_Integer' */

      /* Sum: '<S359>/Sum2' incorporates:
       *  DataTypeConversion: '<S359>/Data Type Conversion1'
       */
      rtb_Saturation_or = rtb_indexing - (real32_T)status;

      /* Sum: '<S251>/Sum' incorporates:
       *  Constant: '<S359>/offset'
       *  Constant: '<S359>/sine_table_values'
       *  DataTypeConversion: '<S356>/Data Type Conversion'
       *  DataTypeConversion: '<S356>/Data Type Conversion1'
       *  Product: '<S251>/Product'
       *  Product: '<S251>/Product1'
       *  Product: '<S360>/Product'
       *  Product: '<S360>/Product1'
       *  Selector: '<S359>/Lookup'
       *  Sum: '<S359>/Sum'
       *  Sum: '<S360>/Sum3'
       *  Sum: '<S360>/Sum4'
       *  Sum: '<S360>/Sum5'
       *  Sum: '<S360>/Sum6'
       */
      rtb_Gain_e = ((PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[(int32_T)
                     (status + 201U)] -
                     PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[(int32_T)
                     (status + 200U)]) * rtb_Saturation_or +
                    PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[(int32_T)
                    (status + 200U)]) * rtb_Product1_o -
        ((PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[(int32_T)(status + 1U)]
          - PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[status]) *
         rtb_Saturation_or +
         PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[status]) * rtb_Add1_f;

      /* DiscreteIntegrator: '<S301>/Integrator' */
      if (PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState != 0) {
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE = 0.0;
      }

      /* DiscreteIntegrator: '<S301>/Integrator' incorporates:
       *  Gain: '<S298>/Integral Gain'
       */
      PMSM_to_BLDC_mod1_B.Integrator = 5.0 * rtb_Gain_e +
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE;

      /* Sum: '<S251>/Sum1' incorporates:
       *  Gain: '<S306>/Proportional Gain'
       *  Sum: '<S310>/Sum'
       */
      rtb_Gain_e = (250.0 * rtb_Gain_e + PMSM_to_BLDC_mod1_B.Integrator) +
        rtb_Add1_e;

      /* Gain: '<S383>/Gain3' incorporates:
       *  Gain: '<S356>/Gain'
       *  Product: '<S357>/Product'
       */
      rtb_Gain3_c = 7.9577471545947669E-6 * rtb_Gain_e;

      /* Delay: '<S357>/Delay' incorporates:
       *  Constant: '<S357>/InputGain'
       *  Constant: '<S357>/Offset'
       *  Product: '<S357>/Product1'
       *  Sum: '<S357>/Sum1'
       */
      if (PMSM_to_BLDC_mod1_DW.icLoad_a) {
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_ai = 0.0 - rtb_Gain3_c;
      }

      /* Sum: '<S357>/Sum' incorporates:
       *  Delay: '<S357>/Delay'
       */
      rtb_Switch2 = rtb_Gain3_c + PMSM_to_BLDC_mod1_DW.Delay_DSTATE_ai;

      /* Switch: '<S357>/Switch1' */
      if (!(rtb_Switch2 > 0.0)) {
        /* Sum: '<S357>/Sum' incorporates:
         *  Constant: '<S357>/Bias1'
         *  Sum: '<S357>/Sum2'
         */
        rtb_Switch2++;
      }

      /* End of Switch: '<S357>/Switch1' */

      /* Switch: '<S357>/Switch2' */
      if (rtb_Switch2 >= 1.0) {
        /* Sum: '<S357>/Sum' incorporates:
         *  Sum: '<S357>/Sum3'
         *  Switch: '<S357>/Switch2'
         */
        rtb_Switch2--;
      }

      /* End of Switch: '<S357>/Switch2' */

      /* Product: '<S357>/Product2' incorporates:
       *  Delay: '<S356>/Delay'
       */
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj = rtb_Switch2;

      /* DataTypeConversion: '<S64>/Data Type Conversion' incorporates:
       *  Delay: '<S356>/Delay'
       *  Gain: '<S251>/PositionGain'
       */
      PMSM_to_BLDC_mod1_B.DataTypeConversion_a = (real32_T)(6.2831853071795862 *
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj);

      /* Gain: '<S383>/Gain3' incorporates:
       *  Constant: '<S71>/Constant'
       *  Math: '<S71>/Mod'
       */
      rtb_Gain3_c = rt_modd_snf(PMSM_to_BLDC_mod1_B.DataTypeConversion_a, 6.282);

      /* DataTypeConversion: '<S71>/Data Type Conversion1' */
      PMSM_to_BLDC_mod1_B.DataTypeConversion1 = rtb_Gain3_c;

      /* Gain: '<S222>/convert_pu' */
      rtb_Gain4_g = 0.15915494309189535 *
        PMSM_to_BLDC_mod1_B.DataTypeConversion1;

      /* If: '<S222>/If' incorporates:
       *  Constant: '<S224>/Constant'
       *  RelationalOperator: '<S224>/Compare'
       */
      if (tmp_3) {
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_c = (int8_T)!(rtb_Gain4_g < 0.0);
      }

      if (PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_c == 0) {
        /* Outputs for IfAction SubSystem: '<S222>/If Action Subsystem' incorporates:
         *  ActionPort: '<S225>/Action Port'
         */
        PMSM_to_BLDC__IfActionSubsystem(rtb_Gain4_g, &rtb_Gain3_c);
        if (tmp_3) {
          srUpdateBC
            (PMSM_to_BLDC_mod1_DW.IfActionSubsystem_d.IfActionSubsystem_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S222>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S222>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S226>/Action Port'
         */
        PMSM_to_BLDC_IfActionSubsystem1(rtb_Gain4_g, &rtb_Gain3_c);
        if (tmp_3) {
          srUpdateBC
            (PMSM_to_BLDC_mod1_DW.IfActionSubsystem1_j.IfActionSubsystem1_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S222>/If Action Subsystem1' */
      }

      /* Gain: '<S383>/Gain3' incorporates:
       *  Gain: '<S220>/indexing'
       */
      rtb_Gain3_c *= 800.0;

      /* DataTypeConversion: '<S220>/Get_Integer' */
      rtb_Saturation2_idx_0 = trunc(rtb_Gain3_c);
      if (rtIsNaN(rtb_Saturation2_idx_0) || rtIsInf(rtb_Saturation2_idx_0)) {
        rtb_Saturation2_idx_0 = 0.0;
      } else {
        rtb_Saturation2_idx_0 = fmod(rtb_Saturation2_idx_0, 65536.0);
      }

      status = (uint16_T)(rtb_Saturation2_idx_0 < 0.0 ? (int32_T)(uint16_T)
                          -(int16_T)(uint16_T)-rtb_Saturation2_idx_0 : (int32_T)
                          (uint16_T)rtb_Saturation2_idx_0);

      /* End of DataTypeConversion: '<S220>/Get_Integer' */

      /* Sum: '<S220>/Sum2' incorporates:
       *  DataTypeConversion: '<S220>/Data Type Conversion1'
       */
      rtb_Gain4_g = rtb_Gain3_c - (real_T)status;

      /* Sum: '<S221>/Sum4' incorporates:
       *  Constant: '<S220>/offset'
       *  Constant: '<S220>/sine_table_values'
       *  Product: '<S221>/Product'
       *  Selector: '<S220>/Lookup'
       *  Sum: '<S220>/Sum'
       *  Sum: '<S221>/Sum3'
       */
      rtb_Sum4 = (PMSM_to_BLDC_mod1_ConstP.pooled18[(int32_T)(status + 1U)] -
                  PMSM_to_BLDC_mod1_ConstP.pooled18[status]) * rtb_Gain4_g +
        PMSM_to_BLDC_mod1_ConstP.pooled18[status];

      /* Gain: '<S383>/Gain3' incorporates:
       *  Constant: '<S220>/offset'
       *  Constant: '<S220>/sine_table_values'
       *  Product: '<S221>/Product1'
       *  Selector: '<S220>/Lookup'
       *  Sum: '<S220>/Sum'
       *  Sum: '<S221>/Sum5'
       */
      rtb_Gain3_c = PMSM_to_BLDC_mod1_ConstP.pooled18[(int32_T)(status + 201U)]
        - PMSM_to_BLDC_mod1_ConstP.pooled18[(int32_T)(status + 200U)];
      rtb_Gain3_c *= rtb_Gain4_g;

      /* Sum: '<S221>/Sum6' incorporates:
       *  Constant: '<S220>/offset'
       *  Constant: '<S220>/sine_table_values'
       *  Selector: '<S220>/Lookup'
       *  Sum: '<S220>/Sum'
       *  Sum: '<S221>/Sum5'
       */
      rtb_Gain4_g = PMSM_to_BLDC_mod1_ConstP.pooled18[(int32_T)(status + 200U)]
        + rtb_Gain3_c;

      /* Outputs for Atomic SubSystem: '<S218>/Two inputs CRL' */
      /* Gain: '<S383>/Gain3' incorporates:
       *  Product: '<S228>/acos'
       *  Product: '<S228>/bsin'
       *  Sum: '<S228>/sum_Ds'
       */
      rtb_Gain3_c = PMSM_to_BLDC_mod1_B.Kalphabeta0[0] * rtb_Gain4_g;
      rtb_Gain3_c += PMSM_to_BLDC_mod1_B.Kalphabeta0[1] * rtb_Sum4;

      /* AlgorithmDescriptorDelegate generated from: '<S228>/a16' incorporates:
       *  Switch: '<S229>/Switch'
       */
      PMSM_to_BLDC_mod1_B.algDD_o1 = rtb_Gain3_c;

      /* AlgorithmDescriptorDelegate generated from: '<S228>/a16' incorporates:
       *  Product: '<S228>/asin'
       *  Product: '<S228>/bcos'
       *  Sum: '<S228>/sum_Qs'
       */
      PMSM_to_BLDC_mod1_B.algDD_o2 = PMSM_to_BLDC_mod1_B.Kalphabeta0[1] *
        rtb_Gain4_g - PMSM_to_BLDC_mod1_B.Kalphabeta0[0] * rtb_Sum4;

      /* End of Outputs for SubSystem: '<S218>/Two inputs CRL' */

      /* Gain: '<S383>/Gain3' incorporates:
       *  Sum: '<S78>/Sum'
       */
      rtb_Gain3_c = PMSM_to_BLDC_mod1_B.algDD_o1 - PMSM_to_BLDC_mod1_B.Constant;

      /* DiscreteIntegrator: '<S171>/Integrator' */
      PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b =
        PMSM_to_BLDC_mod1_ConstB.Constant3_n;

      /* Sum: '<S180>/Sum' incorporates:
       *  Constant: '<S78>/Constant'
       *  DiscreteIntegrator: '<S171>/Integrator'
       *  Product: '<S176>/PProd Out'
       */
      rtb_Gain4_g = rtb_Gain3_c * 22.608 +
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b;

      /* Saturate: '<S178>/Saturation' */
      if (rtb_Gain4_g > 1.0) {
        rtb_Sum4 = 1.0;
      } else if (rtb_Gain4_g < -1.0) {
        rtb_Sum4 = -1.0;
      } else {
        rtb_Sum4 = rtb_Gain4_g;
      }

      /* End of Saturate: '<S178>/Saturation' */

      /* Saturate: '<S61>/Saturation' incorporates:
       *  Delay: '<S56>/Delay1'
       */
      if (PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx > 600.0F) {
        rtb_Saturation_or = 600.0F;
      } else if (PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx < -600.0F) {
        rtb_Saturation_or = -600.0F;
      } else {
        rtb_Saturation_or = PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx;
      }

      /* Sum: '<S61>/Add' incorporates:
       *  Constant: '<S56>/Constant'
       *  Saturate: '<S61>/Saturation'
       */
      PMSM_to_BLDC_mod1_B.Add = 600.0 - rtb_Saturation_or;

      /* Gain: '<S442>/Proportional Gain' */
      PMSM_to_BLDC_mod1_B.ProportionalGain = 0.31663865546218484 *
        PMSM_to_BLDC_mod1_B.Add;
    }

    /* Sum: '<S446>/Sum' incorporates:
     *  Integrator: '<S437>/Integrator'
     */
    PMSM_to_BLDC_mod1_B.Sum_o = PMSM_to_BLDC_mod1_B.ProportionalGain +
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE;

    /* Sum: '<S77>/Sum' */
    rtb_Add3 = PMSM_to_BLDC_mod1_B.algDD_o2 - PMSM_to_BLDC_mod1_B.Sum_o;
    if (tmp_2) {
      /* DiscreteIntegrator: '<S116>/Integrator' */
      PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n =
        PMSM_to_BLDC_mod1_ConstB.Constant3;

      /* Sum: '<S125>/Sum' incorporates:
       *  Constant: '<S77>/Constant'
       *  DiscreteIntegrator: '<S116>/Integrator'
       *  Product: '<S121>/PProd Out'
       */
      rtb_Sum1_eq = rtb_Add3 * 22.608 + PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n;

      /* Saturate: '<S123>/Saturation' */
      if (rtb_Sum1_eq > 1.0) {
        rtb_Saturation_k = 1.0;
      } else if (rtb_Sum1_eq < -1.0) {
        rtb_Saturation_k = -1.0;
      } else {
        rtb_Saturation_k = rtb_Sum1_eq;
      }

      /* End of Saturate: '<S123>/Saturation' */

      /* Gain: '<S196>/convert_pu' */
      rtb_Add1_f = 0.15915494309189535 * PMSM_to_BLDC_mod1_B.DataTypeConversion1;

      /* If: '<S196>/If' incorporates:
       *  Constant: '<S198>/Constant'
       *  RelationalOperator: '<S198>/Compare'
       */
      if (tmp_3) {
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_m = (int8_T)!(rtb_Add1_f < 0.0);
      }

      if (PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_m == 0) {
        /* Outputs for IfAction SubSystem: '<S196>/If Action Subsystem' incorporates:
         *  ActionPort: '<S199>/Action Port'
         */
        PMSM_to_BLDC__IfActionSubsystem(rtb_Add1_f, &rtb_Product1_o);
        if (tmp_3) {
          srUpdateBC
            (PMSM_to_BLDC_mod1_DW.IfActionSubsystem.IfActionSubsystem_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S196>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S196>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S200>/Action Port'
         */
        PMSM_to_BLDC_IfActionSubsystem1(rtb_Add1_f, &rtb_Product1_o);
        if (tmp_3) {
          srUpdateBC
            (PMSM_to_BLDC_mod1_DW.IfActionSubsystem1.IfActionSubsystem1_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S196>/If Action Subsystem1' */
      }

      /* Product: '<S263>/Product1' incorporates:
       *  Gain: '<S194>/indexing'
       */
      rtb_Product1_o *= 800.0;

      /* DataTypeConversion: '<S194>/Get_Integer' */
      rtb_Saturation2_idx_0 = trunc(rtb_Product1_o);
      if (rtIsNaN(rtb_Saturation2_idx_0) || rtIsInf(rtb_Saturation2_idx_0)) {
        rtb_Saturation2_idx_0 = 0.0;
      } else {
        rtb_Saturation2_idx_0 = fmod(rtb_Saturation2_idx_0, 65536.0);
      }

      status = (uint16_T)(rtb_Saturation2_idx_0 < 0.0 ? (int32_T)(uint16_T)
                          -(int16_T)(uint16_T)-rtb_Saturation2_idx_0 : (int32_T)
                          (uint16_T)rtb_Saturation2_idx_0);

      /* End of DataTypeConversion: '<S194>/Get_Integer' */

      /* Sum: '<S194>/Sum2' incorporates:
       *  DataTypeConversion: '<S194>/Data Type Conversion1'
       */
      rtb_Add1_f = rtb_Product1_o - (real_T)status;

      /* Sum: '<S195>/Sum4' incorporates:
       *  Constant: '<S194>/offset'
       *  Constant: '<S194>/sine_table_values'
       *  Product: '<S195>/Product'
       *  Selector: '<S194>/Lookup'
       *  Sum: '<S194>/Sum'
       *  Sum: '<S195>/Sum3'
       */
      rtb_Product1_o = (PMSM_to_BLDC_mod1_ConstP.pooled18[(int32_T)(status + 1U)]
                        - PMSM_to_BLDC_mod1_ConstP.pooled18[status]) *
        rtb_Add1_f + PMSM_to_BLDC_mod1_ConstP.pooled18[status];

      /* Sum: '<S195>/Sum6' incorporates:
       *  Constant: '<S194>/offset'
       *  Constant: '<S194>/sine_table_values'
       *  Product: '<S195>/Product1'
       *  Selector: '<S194>/Lookup'
       *  Sum: '<S194>/Sum'
       *  Sum: '<S195>/Sum5'
       */
      rtb_Add1_f = (PMSM_to_BLDC_mod1_ConstP.pooled18[(int32_T)(status + 201U)]
                    - PMSM_to_BLDC_mod1_ConstP.pooled18[(int32_T)(status + 200U)])
        * rtb_Add1_f + PMSM_to_BLDC_mod1_ConstP.pooled18[(int32_T)(status + 200U)];

      /* Outputs for Atomic SubSystem: '<S193>/Two inputs CRL' */
      /* AlgorithmDescriptorDelegate generated from: '<S202>/a16' incorporates:
       *  Product: '<S202>/dcos'
       *  Product: '<S202>/qsin'
       *  Sum: '<S202>/sum_alpha'
       */
      PMSM_to_BLDC_mod1_B.algDD_o1_g = rtb_Sum4 * rtb_Add1_f - rtb_Saturation_k *
        rtb_Product1_o;

      /* AlgorithmDescriptorDelegate generated from: '<S202>/a16' incorporates:
       *  Product: '<S202>/dsin'
       *  Product: '<S202>/qcos'
       *  Sum: '<S202>/sum_beta'
       */
      PMSM_to_BLDC_mod1_B.algDD_o2_h = rtb_Saturation_k * rtb_Add1_f + rtb_Sum4 *
        rtb_Product1_o;

      /* End of Outputs for SubSystem: '<S193>/Two inputs CRL' */

      /* Product: '<S263>/Product1' incorporates:
       *  Gain: '<S213>/one_by_two'
       */
      rtb_Product1_o = 0.5 * PMSM_to_BLDC_mod1_B.algDD_o1_g;

      /* Gain: '<S213>/sqrt3_by_two' */
      rtb_Sum4 = 0.8660254037844386 * PMSM_to_BLDC_mod1_B.algDD_o2_h;

      /* Sum: '<S213>/add_b' */
      rtb_Add1_f = rtb_Sum4 - rtb_Product1_o;

      /* Product: '<S263>/Product1' incorporates:
       *  Sum: '<S213>/add_c'
       */
      rtb_Product1_o = (0.0 - rtb_Product1_o) - rtb_Sum4;

      /* Gain: '<S207>/one_by_two' incorporates:
       *  MinMax: '<S207>/Max'
       *  MinMax: '<S207>/Min'
       *  Sum: '<S207>/Add'
       */
      rtb_Sum4 = (fmax(fmax(PMSM_to_BLDC_mod1_B.algDD_o1_g, rtb_Add1_f),
                       rtb_Product1_o) + fmin(fmin
        (PMSM_to_BLDC_mod1_B.algDD_o1_g, rtb_Add1_f), rtb_Product1_o)) * -0.5;

      /* Gain: '<S206>/Gain' incorporates:
       *  Sum: '<S206>/Add1'
       *  Sum: '<S206>/Add2'
       *  Sum: '<S206>/Add3'
       */
      PMSM_to_BLDC_mod1_B.Gain_p[0] = (PMSM_to_BLDC_mod1_B.algDD_o1_g + rtb_Sum4)
        * 1.1547005383792517;
      PMSM_to_BLDC_mod1_B.Gain_p[1] = (rtb_Add1_f + rtb_Sum4) *
        1.1547005383792517;
      PMSM_to_BLDC_mod1_B.Gain_p[2] = (rtb_Sum4 + rtb_Product1_o) *
        1.1547005383792517;

      /* Gain: '<S65>/Gain' incorporates:
       *  Constant: '<S65>/Constant'
       *  Sum: '<S65>/Add'
       */
      rtb_Sum4 = (PMSM_to_BLDC_mod1_B.Gain_p[0] + 1.45) * 0.33333333333333331;
      PMSM_to_BLDC_mod1_B.Gain_f[0] = rtb_Sum4;

      /* Gain: '<S400>/Gain5' incorporates:
       *  Constant: '<S400>/Constant1'
       *  Gain: '<S399>/Gain1'
       *  Sum: '<S400>/Add'
       */
      PMSM_to_BLDC_mod1_B.Gain5[0] = -rtb_Sum4 + 1.0;

      /* Gain: '<S65>/Gain' incorporates:
       *  Constant: '<S65>/Constant'
       *  Sum: '<S65>/Add'
       */
      rtb_Sum4 = (PMSM_to_BLDC_mod1_B.Gain_p[1] + 1.45) * 0.33333333333333331;
      PMSM_to_BLDC_mod1_B.Gain_f[1] = rtb_Sum4;

      /* Gain: '<S400>/Gain5' incorporates:
       *  Constant: '<S400>/Constant1'
       *  Gain: '<S399>/Gain1'
       *  Sum: '<S400>/Add'
       */
      PMSM_to_BLDC_mod1_B.Gain5[1] = -rtb_Sum4 + 1.0;

      /* Gain: '<S65>/Gain' incorporates:
       *  Constant: '<S65>/Constant'
       *  Sum: '<S65>/Add'
       */
      rtb_Sum4 = (PMSM_to_BLDC_mod1_B.Gain_p[2] + 1.45) * 0.33333333333333331;
      PMSM_to_BLDC_mod1_B.Gain_f[2] = rtb_Sum4;

      /* Gain: '<S400>/Gain5' incorporates:
       *  Constant: '<S400>/Constant1'
       *  Gain: '<S399>/Gain1'
       *  Sum: '<S400>/Add'
       */
      PMSM_to_BLDC_mod1_B.Gain5[2] = -rtb_Sum4 + 1.0;

      /* SignalConversion generated from: '<S60>/Subsystem2' */
      PMSM_to_BLDC_mod1_B.Gate_pulse[0] = PMSM_to_BLDC_mod1_B.Gain_f[0];
      PMSM_to_BLDC_mod1_B.Gate_pulse[1] = PMSM_to_BLDC_mod1_B.Gain5[0];
      PMSM_to_BLDC_mod1_B.Gate_pulse[2] = PMSM_to_BLDC_mod1_B.Gain_f[1];
      PMSM_to_BLDC_mod1_B.Gate_pulse[3] = PMSM_to_BLDC_mod1_B.Gain5[1];
      PMSM_to_BLDC_mod1_B.Gate_pulse[4] = PMSM_to_BLDC_mod1_B.Gain_f[2];
      PMSM_to_BLDC_mod1_B.Gate_pulse[5] = PMSM_to_BLDC_mod1_B.Gain5[2];

      /* Gain: '<S58>/Gain' */
      for (i = 0; i < 6; i++) {
        rtb_Gain_h[i] = 100.0 * PMSM_to_BLDC_mod1_B.Gate_pulse[i];
      }

      /* End of Gain: '<S58>/Gain' */

      /* MATLABSystem: '<S456>/PWM Output' incorporates:
       *  Constant: '<S7>/Constant'
       */
      timModule = TIM8;
      freq = checkFrequencyAndDutyCycleLimits
        (PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, 20000U);
      setFrequencyAccToInput(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, freq);

      /* DataTypeConversion: '<S58>/Data Type Conversion' */
      rtb_Saturation2_idx_0 = floor(rtb_Gain_h[0]);
      if (rtIsNaN(rtb_Saturation2_idx_0) || rtIsInf(rtb_Saturation2_idx_0)) {
        rtb_Saturation2_idx_0 = 0.0;
      } else {
        rtb_Saturation2_idx_0 = fmod(rtb_Saturation2_idx_0, 65536.0);
      }

      /* MATLABSystem: '<S456>/PWM Output' incorporates:
       *  DataTypeConversion: '<S58>/Data Type Conversion'
       */
      setDutyCycleInPercentageChannel1(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle,
        (uint16_T)(rtb_Saturation2_idx_0 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
                   (uint16_T)-rtb_Saturation2_idx_0 : (int32_T)(uint16_T)
                   rtb_Saturation2_idx_0));
      channelEnum = LL_TIM_CHANNEL_CH1N;
      LL_TIM_CC_EnableChannel(timModule, channelEnum);

      /* DataTypeConversion: '<S58>/Data Type Conversion2' */
      rtb_Saturation2_idx_0 = floor(rtb_Gain_h[2]);
      if (rtIsNaN(rtb_Saturation2_idx_0) || rtIsInf(rtb_Saturation2_idx_0)) {
        rtb_Saturation2_idx_0 = 0.0;
      } else {
        rtb_Saturation2_idx_0 = fmod(rtb_Saturation2_idx_0, 65536.0);
      }

      /* MATLABSystem: '<S456>/PWM Output' incorporates:
       *  DataTypeConversion: '<S58>/Data Type Conversion2'
       */
      setDutyCycleInPercentageChannel2(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle,
        (uint16_T)(rtb_Saturation2_idx_0 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
                   (uint16_T)-rtb_Saturation2_idx_0 : (int32_T)(uint16_T)
                   rtb_Saturation2_idx_0));
      channelEnum = LL_TIM_CHANNEL_CH2N;
      LL_TIM_CC_EnableChannel(timModule, channelEnum);

      /* DataTypeConversion: '<S58>/Data Type Conversion4' */
      rtb_Saturation2_idx_0 = floor(rtb_Gain_h[4]);
      if (rtIsNaN(rtb_Saturation2_idx_0) || rtIsInf(rtb_Saturation2_idx_0)) {
        rtb_Saturation2_idx_0 = 0.0;
      } else {
        rtb_Saturation2_idx_0 = fmod(rtb_Saturation2_idx_0, 65536.0);
      }

      /* MATLABSystem: '<S456>/PWM Output' incorporates:
       *  DataTypeConversion: '<S58>/Data Type Conversion4'
       */
      setDutyCycleInPercentageChannel3(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle,
        (uint16_T)(rtb_Saturation2_idx_0 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
                   (uint16_T)-rtb_Saturation2_idx_0 : (int32_T)(uint16_T)
                   rtb_Saturation2_idx_0));
      channelEnum = LL_TIM_CHANNEL_CH3N;
      LL_TIM_CC_EnableChannel(timModule, channelEnum);

      /* Product: '<S263>/Product' */
      rtb_Gain_e *= 0.0046902865258454489;

      /* Delay: '<S263>/Delay' incorporates:
       *  Constant: '<S255>/IC'
       */
      if (PMSM_to_BLDC_mod1_DW.icLoad_b) {
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_g = 0.0;
      }

      /* Sum: '<S263>/Add1' incorporates:
       *  Delay: '<S263>/Delay'
       *  Product: '<S263>/Product1'
       */
      rtb_Add1_d = 0.99530971347415453 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_g +
        rtb_Gain_e;

      /* Gain: '<S251>/FreqGain' incorporates:
       *  Delay: '<S232>/Delay1'
       */
      PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f = (real32_T)rtb_Add1_d;

      /* Gain: '<S232>/SpeedGain' incorporates:
       *  Delay: '<S232>/Delay1'
       *  Delay: '<S56>/Delay1'
       */
      PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx = 0.142857149F *
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f;

      /* Gain: '<S56>/Gain3' incorporates:
       *  Delay: '<S56>/Delay1'
       */
      PMSM_to_BLDC_mod1_B.Gain3 = 9.55F * PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx;

      /* SignalConversion generated from: '<S56>/Speed_controls' */
      PMSM_to_BLDC_mod1_B.idq_ref[0] = PMSM_to_BLDC_mod1_B.Constant;
      PMSM_to_BLDC_mod1_B.idq_ref[1] = PMSM_to_BLDC_mod1_B.Sum_o;

      /* DataTypeConversion: '<S72>/Data Type Conversion' incorporates:
       *  Constant: '<S72>/Constant1'
       *  Math: '<S72>/Mod1'
       */
      PMSM_to_BLDC_mod1_B.DataTypeConversion_e = rt_modd_snf
        (PMSM_to_BLDC_mod1_B.algDD_o1, 6.282);

      /* DataTypeConversion: '<S72>/Data Type Conversion1' incorporates:
       *  Constant: '<S72>/Constant1'
       *  Math: '<S72>/Mod2'
       */
      PMSM_to_BLDC_mod1_B.DataTypeConversion1_i = rt_modd_snf
        (PMSM_to_BLDC_mod1_B.algDD_o2, 6.282);

      /* SignalConversion generated from: '<S59>/Delay' */
      PMSM_to_BLDC_mod1_B.TmpSignalConversionAtDelayInpor[0] =
        PMSM_to_BLDC_mod1_B.algDD_o1_g;
      PMSM_to_BLDC_mod1_B.TmpSignalConversionAtDelayInpor[1] =
        PMSM_to_BLDC_mod1_B.algDD_o2_h;
      PMSM_to_BLDC_mod1_B.TmpSignalConversionAtDelayInpor[2] =
        PMSM_to_BLDC_mod1_B.DataTypeConversion_e;
      PMSM_to_BLDC_mod1_B.TmpSignalConversionAtDelayInpor[3] =
        PMSM_to_BLDC_mod1_B.DataTypeConversion1_i;

      /* SignalConversion generated from: '<S63>/Inverse Park Transform1' */
      PMSM_to_BLDC_mod1_B.TmpSignalConversionAtTAQSigLogg[0] =
        PMSM_to_BLDC_mod1_B.algDD_o1_g;
      PMSM_to_BLDC_mod1_B.TmpSignalConversionAtTAQSigLogg[1] =
        PMSM_to_BLDC_mod1_B.algDD_o2_h;
      PMSM_to_BLDC_mod1_B.TmpSignalConversionAtTAQSigLogg[2] =
        PMSM_to_BLDC_mod1_B.Kalphabeta0[2];

      /* DeadZone: '<S108>/DeadZone' */
      if (rtb_Sum1_eq > 1.0) {
        rtb_Sum1_eq--;
      } else if (rtb_Sum1_eq >= -1.0) {
        rtb_Sum1_eq = 0.0;
      } else {
        rtb_Sum1_eq++;
      }

      /* End of DeadZone: '<S108>/DeadZone' */

      /* Product: '<S113>/IProd Out' incorporates:
       *  Constant: '<S77>/Constant1'
       */
      rtb_Gain_e = rtb_Add3 * 0.23235999999999998;

      /* Switch: '<S106>/Switch1' incorporates:
       *  Constant: '<S106>/Clamping_zero'
       *  Constant: '<S106>/Constant'
       *  Constant: '<S106>/Constant2'
       *  RelationalOperator: '<S106>/fix for DT propagation issue'
       */
      if (rtb_Sum1_eq > 0.0) {
        rtPrevAction = 1;
      } else {
        rtPrevAction = -1;
      }

      /* Switch: '<S106>/Switch2' incorporates:
       *  Constant: '<S106>/Clamping_zero'
       *  Constant: '<S106>/Constant3'
       *  Constant: '<S106>/Constant4'
       *  RelationalOperator: '<S106>/fix for DT propagation issue1'
       */
      if (rtb_Gain_e > 0.0) {
        rtAction = 1;
      } else {
        rtAction = -1;
      }

      /* Switch: '<S106>/Switch' incorporates:
       *  Constant: '<S106>/Clamping_zero'
       *  Logic: '<S106>/AND3'
       *  RelationalOperator: '<S106>/Equal1'
       *  RelationalOperator: '<S106>/Relational Operator'
       *  Switch: '<S106>/Switch1'
       *  Switch: '<S106>/Switch2'
       */
      if ((rtb_Sum1_eq != 0.0) && (rtPrevAction == rtAction)) {
        /* Switch: '<S106>/Switch' incorporates:
         *  Constant: '<S106>/Constant1'
         */
        rtb_Switch = 0.0;
      } else {
        /* Switch: '<S106>/Switch' */
        rtb_Switch = rtb_Gain_e;
      }

      /* End of Switch: '<S106>/Switch' */

      /* DeadZone: '<S163>/DeadZone' */
      if (rtb_Gain4_g > 1.0) {
        rtb_Gain4_g--;
      } else if (rtb_Gain4_g >= -1.0) {
        rtb_Gain4_g = 0.0;
      } else {
        rtb_Gain4_g++;
      }

      /* End of DeadZone: '<S163>/DeadZone' */

      /* Gain: '<S383>/Gain3' incorporates:
       *  Constant: '<S78>/Constant1'
       *  Product: '<S168>/IProd Out'
       */
      rtb_Gain3_c *= 0.23235999999999998;

      /* Switch: '<S161>/Switch1' incorporates:
       *  Constant: '<S161>/Clamping_zero'
       *  Constant: '<S161>/Constant'
       *  Constant: '<S161>/Constant2'
       *  RelationalOperator: '<S161>/fix for DT propagation issue'
       */
      if (rtb_Gain4_g > 0.0) {
        rtPrevAction = 1;
      } else {
        rtPrevAction = -1;
      }

      /* Switch: '<S161>/Switch2' incorporates:
       *  Constant: '<S161>/Clamping_zero'
       *  Constant: '<S161>/Constant3'
       *  Constant: '<S161>/Constant4'
       *  RelationalOperator: '<S161>/fix for DT propagation issue1'
       */
      if (rtb_Gain3_c > 0.0) {
        rtAction = 1;
      } else {
        rtAction = -1;
      }

      /* Switch: '<S161>/Switch' incorporates:
       *  Constant: '<S161>/Clamping_zero'
       *  Logic: '<S161>/AND3'
       *  RelationalOperator: '<S161>/Equal1'
       *  RelationalOperator: '<S161>/Relational Operator'
       *  Switch: '<S161>/Switch1'
       *  Switch: '<S161>/Switch2'
       */
      if ((rtb_Gain4_g != 0.0) && (rtPrevAction == rtAction)) {
        /* Switch: '<S161>/Switch' incorporates:
         *  Constant: '<S161>/Constant1'
         */
        rtb_Switch_e = 0.0;
      } else {
        /* Switch: '<S161>/Switch' */
        rtb_Switch_e = rtb_Gain3_c;
      }

      /* End of Switch: '<S161>/Switch' */
    }

    /* Integrator: '<S375>/Int1' */
    PMSM_to_BLDC_mod1_B.Int1 = PMSM_to_BLDC_mod1_X.Int1_CSTATE;

    /* Gain: '<S369>/Gain' */
    PMSM_to_BLDC_mod1_B.Gain_j = 57.324 * PMSM_to_BLDC_mod1_B.Int1;

    /* Integrator: '<S390>/Integrator' */
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

    /* Integrator: '<S391>/Integrator' */
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

    /* Gain: '<S386>/Gain2' incorporates:
     *  Gain: '<S386>/Gain1'
     *  Integrator: '<S390>/Integrator'
     *  Integrator: '<S391>/Integrator'
     *  Product: '<S386>/Product'
     *  Product: '<S389>/Product'
     *  Sum: '<S386>/Add'
     */
    PMSM_to_BLDC_mod1_B.Gain2 = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d *
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l * PMSM_to_BLDC_mod1_ConstB.Add +
      0.017 * PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l) * 10.5;

    /* Gain: '<S369>/Gain1' incorporates:
     *  Gain: '<S371>/Gain'
     */
    PMSM_to_BLDC_mod1_B.Gain1 = 0.0026539278131634818 *
      PMSM_to_BLDC_mod1_B.Gain2 * 9.549;
    if (tmp_2) {
    }

    /* Gain: '<S375>/Gain4' */
    rtb_Gain_e = 7.0 * PMSM_to_BLDC_mod1_B.Int1;

    /* Trigonometry: '<S377>/sine_cosine' */
    rtb_Gain4_g = sin(rtb_Gain_e);
    rtb_Sum4 = cos(rtb_Gain_e);

    /* Sum: '<S385>/Add1' incorporates:
     *  Integrator: '<S390>/Integrator'
     *  Integrator: '<S391>/Integrator'
     *  Product: '<S385>/Product2'
     *  Product: '<S385>/Product3'
     */
    rtb_Add1_f = PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d * rtb_Sum4 -
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l * rtb_Gain4_g;

    /* SignalConversion generated from: '<S374>/Vector Concatenate' incorporates:
     *  Concatenate: '<S374>/Vector Concatenate'
     */
    PMSM_to_BLDC_mod1_B.VectorConcatenate[0] = rtb_Add1_f;

    /* Sum: '<S385>/Add' incorporates:
     *  Integrator: '<S390>/Integrator'
     *  Integrator: '<S391>/Integrator'
     *  Product: '<S385>/Product'
     *  Product: '<S385>/Product1'
     */
    rtb_Gain_e = PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d * rtb_Gain4_g +
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l * rtb_Sum4;

    /* Gain: '<S384>/Gain2' incorporates:
     *  Gain: '<S384>/Gain1'
     */
    rtb_Add1_f *= -0.5;

    /* Sum: '<S384>/Subtract1' incorporates:
     *  Concatenate: '<S374>/Vector Concatenate'
     *  Gain: '<S384>/Gain2'
     *  Gain: '<S384>/Gain3'
     */
    PMSM_to_BLDC_mod1_B.VectorConcatenate[1] = 0.8660254037844386 * rtb_Gain_e +
      rtb_Add1_f;

    /* Sum: '<S384>/Subtract2' incorporates:
     *  Concatenate: '<S374>/Vector Concatenate'
     *  Gain: '<S384>/Gain4'
     */
    PMSM_to_BLDC_mod1_B.VectorConcatenate[2] = -0.8660254037844386 * rtb_Gain_e
      + rtb_Add1_f;

    /* DataTypeConversion: '<S369>/Data Type Conversion' */
    PMSM_to_BLDC_mod1_B.DataTypeConversion_c[0] =
      PMSM_to_BLDC_mod1_B.VectorConcatenate[0];
    PMSM_to_BLDC_mod1_B.DataTypeConversion_c[1] =
      PMSM_to_BLDC_mod1_B.VectorConcatenate[1];
    PMSM_to_BLDC_mod1_B.DataTypeConversion_c[2] =
      PMSM_to_BLDC_mod1_B.VectorConcatenate[2];
    if (tmp_2) {
      /* Saturate: '<S370>/Saturation2' */
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

      /* End of Saturate: '<S370>/Saturation2' */

      /* Gain: '<S370>/Gain' incorporates:
       *  Sum: '<S370>/Sum'
       */
      rtb_Gain_e = ((rtb_Add1_f + rtb_Product1_o) + rtb_Saturation2_idx_0) *
        0.33333333333333331;

      /* Gain: '<S383>/Gain3' incorporates:
       *  Sum: '<S370>/Sum1'
       */
      rtb_Gain3_c = rtb_Saturation2_idx_0 - rtb_Gain_e;

      /* Product: '<S370>/Product' incorporates:
       *  Sum: '<S370>/Sum2'
       *  Sum: '<S370>/Sum3'
       */
      PMSM_to_BLDC_mod1_B.Product[0] = rtb_Gain3_c *
        PMSM_to_BLDC_mod1_ConstB.Switch;
      PMSM_to_BLDC_mod1_B.Product[1] = (rtb_Add1_f - rtb_Gain_e) *
        PMSM_to_BLDC_mod1_ConstB.Switch;
      PMSM_to_BLDC_mod1_B.Product[2] = (rtb_Product1_o - rtb_Gain_e) *
        PMSM_to_BLDC_mod1_ConstB.Switch;

      /* Gain: '<S383>/Gain3' incorporates:
       *  Gain: '<S383>/Gain1'
       */
      rtb_Gain3_c = -0.33333333333333331 * PMSM_to_BLDC_mod1_B.Product[1];

      /* Sum: '<S383>/Add' incorporates:
       *  Gain: '<S383>/Gain'
       *  Gain: '<S383>/Gain4'
       */
      PMSM_to_BLDC_mod1_B.Add_a = (0.66666666666666663 *
        PMSM_to_BLDC_mod1_B.Product[0] + rtb_Gain3_c) + -0.33333333333333331 *
        PMSM_to_BLDC_mod1_B.Product[2];

      /* Gain: '<S383>/Gain3' */
      rtb_Gain3_c = -0.57735026918962573 * PMSM_to_BLDC_mod1_B.Product[2];

      /* Sum: '<S383>/Add1' incorporates:
       *  Gain: '<S383>/Gain2'
       */
      PMSM_to_BLDC_mod1_B.Add1 = 0.57735026918962573 *
        PMSM_to_BLDC_mod1_B.Product[1] + rtb_Gain3_c;
    }

    /* Sum: '<S390>/Add' incorporates:
     *  Constant: '<S394>/Constant'
     *  Integrator: '<S390>/Integrator'
     *  Integrator: '<S391>/Integrator'
     *  Product: '<S388>/Product2'
     *  Product: '<S388>/Product3'
     *  Product: '<S390>/Product'
     *  Product: '<S392>/Product'
     *  Product: '<S393>/Product'
     *  Product: '<S394>/Product'
     *  Sum: '<S388>/Add1'
     */
    PMSM_to_BLDC_mod1_B.Add_h = ((PMSM_to_BLDC_mod1_B.Add_a * rtb_Sum4 +
      PMSM_to_BLDC_mod1_B.Add1 * rtb_Gain4_g) /
      PMSM_to_BLDC_mod1_ConstB.IndexVector_b + PMSM_to_BLDC_mod1_ConstB.Gain *
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l *
      PMSM_to_BLDC_mod1_ConstB.IndexVector_ah /
      PMSM_to_BLDC_mod1_ConstB.IndexVector1_e) -
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d * 0.037 /
      PMSM_to_BLDC_mod1_ConstB.IndexVector_j;

    /* Sum: '<S391>/Add' incorporates:
     *  Constant: '<S398>/Constant'
     *  Integrator: '<S390>/Integrator'
     *  Integrator: '<S391>/Integrator'
     *  Product: '<S388>/Product'
     *  Product: '<S388>/Product1'
     *  Product: '<S391>/Product'
     *  Product: '<S395>/Product'
     *  Product: '<S396>/Product'
     *  Product: '<S398>/Product'
     *  Sum: '<S388>/Add'
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
      /* Gain: '<S434>/Integral Gain' */
      PMSM_to_BLDC_mod1_B.IntegralGain = 11.047170868347338 *
        PMSM_to_BLDC_mod1_B.Add;
    }

    if (tmp_3) {
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Subsystem' */
  if (tmp_0) {
    /* Outputs for Atomic SubSystem: '<Root>/SPI_read' */
    /* Outputs for Enabled SubSystem: '<S32>/Subsystem1' incorporates:
     *  EnablePort: '<S35>/Ctrl_flag2'
     */
    /* SignalConversion generated from: '<S35>/Ctrl_flag2' incorporates:
     *  Constant: '<S35>/Constant'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write2 > 0.0) {
      PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_m = true;
      PMSM_to_BLDC_mod1_SPIReceive_p(&PMSM_to_BLDC_mod1_B.SPIReceive_pn,
        &PMSM_to_BLDC_mod1_DW.SPIReceive_pn);
      PMSM_to_BLDC_mod1_SPITransmit(36864, &PMSM_to_BLDC_mod1_DW.SPITransmit_pn);
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_n);
    } else if (PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_m) {
      /* Disable for Outport: '<S35>/Out1' incorporates:
       *  MATLABSystem: '<S35>/SPI Receive'
       */
      PMSM_to_BLDC_mod1_B.SPIReceive_pn.SPIReceive = 0U;
      PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_m = false;
    }

    /* End of SignalConversion generated from: '<S35>/Ctrl_flag2' */
    /* End of Outputs for SubSystem: '<S32>/Subsystem1' */

    /* Outputs for Enabled SubSystem: '<S33>/Subsystem1' incorporates:
     *  EnablePort: '<S41>/Enable'
     */
    /* SignalConversion generated from: '<S41>/Enable' incorporates:
     *  Constant: '<S41>/Constant'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write4 > 0.0) {
      PMSM_to_BLDC_mod1_DW.Subsystem1_MODE = true;
      PMSM_to_BLDC_mod1_SPIReceive_p(&PMSM_to_BLDC_mod1_B.SPIReceive_pnae,
        &PMSM_to_BLDC_mod1_DW.SPIReceive_pnae);
      PMSM_to_BLDC_mod1_SPITransmit(38912,
        &PMSM_to_BLDC_mod1_DW.SPITransmit_pnae);
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC);
    } else if (PMSM_to_BLDC_mod1_DW.Subsystem1_MODE) {
      /* Disable for MATLABSystem: '<S41>/SPI Receive' incorporates:
       *  Outport: '<S41>/Out1'
       */
      PMSM_to_BLDC_mod1_B.SPIReceive_pnae.SPIReceive = 0U;
      PMSM_to_BLDC_mod1_DW.Subsystem1_MODE = false;
    }

    /* End of SignalConversion generated from: '<S41>/Enable' */
    /* End of Outputs for SubSystem: '<S33>/Subsystem1' */
    /* RelationalOperator: '<S31>/Compare' incorporates:
     *  Constant: '<S31>/Constant'
     */
    PMSM_to_BLDC_mod1_B.Compare_a =
      (PMSM_to_BLDC_mod1_B.SPIReceive_pnae.SPIReceive == 6148);

    /* RelationalOperator: '<S30>/Compare' incorporates:
     *  Constant: '<S30>/Constant'
     */
    PMSM_to_BLDC_mod1_B.Compare_g =
      (PMSM_to_BLDC_mod1_B.SPIReceive_pn.SPIReceive == 5456);

    /* Outputs for Enabled SubSystem: '<S32>/Subsystem' incorporates:
     *  EnablePort: '<S34>/Enable'
     */
    /* SignalConversion generated from: '<S34>/Enable' incorporates:
     *  Constant: '<S34>/Constant'
     *  Constant: '<S34>/Constant1'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write1 > 0.0) {
      if (!PMSM_to_BLDC_mod1_DW.Subsystem_MODE_f) {
        /* SystemReset for Atomic SubSystem: '<S34>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_hq);

        /* End of SystemReset for SubSystem: '<S34>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S34>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_p);

        /* End of SystemReset for SubSystem: '<S34>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Subsystem_MODE_f = true;
      }

      PMSM_to_BLDC_mod1_SPIReceive(&PMSM_to_BLDC_mod1_DW.SPIReceive_p);

      /* Outputs for Atomic SubSystem: '<S34>/Bit Shift' */
      PMSM_to_BLDC_mod1_BitShift(1, &status, &PMSM_to_BLDC_mod1_DW.BitShift_hq);

      /* End of Outputs for SubSystem: '<S34>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S34>/Bit Shift1' */
      PMSM_to_BLDC_mod1_BitShift1(2, &y_nb, &PMSM_to_BLDC_mod1_DW.BitShift1_p);

      /* End of Outputs for SubSystem: '<S34>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S34>/Bitwise OR' incorporates:
       *  Constant: '<S34>/Constant'
       *  Constant: '<S34>/Constant1'
       */
      PMSM_to_BLDC_mod1_B.BitwiseOR_h = (uint16_T)(status | y_nb |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_d);
      PMSM_to_BLDC_mod1_SPITransmit(PMSM_to_BLDC_mod1_B.BitwiseOR_h,
        &PMSM_to_BLDC_mod1_DW.SPITransmit_p);
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i);
    } else {
      PMSM_to_BLDC_mod1_DW.Subsystem_MODE_f = false;
    }

    /* End of SignalConversion generated from: '<S34>/Enable' */
    /* End of Outputs for SubSystem: '<S32>/Subsystem' */

    /* Outputs for Enabled SubSystem: '<S33>/Subsystem' incorporates:
     *  EnablePort: '<S40>/Enable'
     */
    /* SignalConversion generated from: '<S40>/Enable' incorporates:
     *  Constant: '<S40>/Constant'
     *  Constant: '<S40>/Constant1'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write3 > 0.0) {
      if (!PMSM_to_BLDC_mod1_DW.Subsystem_MODE_b) {
        /* SystemReset for Atomic SubSystem: '<S40>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_b);

        /* End of SystemReset for SubSystem: '<S40>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S40>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_m);

        /* End of SystemReset for SubSystem: '<S40>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Subsystem_MODE_b = true;
      }

      PMSM_to_BLDC_mod1_SPIReceive(&PMSM_to_BLDC_mod1_DW.SPIReceive_pna);

      /* Outputs for Atomic SubSystem: '<S40>/Bit Shift' */
      PMSM_to_BLDC_mod1_BitShift(1, &status, &PMSM_to_BLDC_mod1_DW.BitShift_b);

      /* End of Outputs for SubSystem: '<S40>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S40>/Bit Shift1' */
      PMSM_to_BLDC_mod1_BitShift1(3, &y_nb, &PMSM_to_BLDC_mod1_DW.BitShift1_m);

      /* End of Outputs for SubSystem: '<S40>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S40>/Bitwise OR' incorporates:
       *  Constant: '<S40>/Constant'
       *  Constant: '<S40>/Constant1'
       */
      PMSM_to_BLDC_mod1_B.BitwiseOR_o = (uint16_T)(status | y_nb |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_j);
      PMSM_to_BLDC_mod1_SPITransmit(PMSM_to_BLDC_mod1_B.BitwiseOR_o,
        &PMSM_to_BLDC_mod1_DW.SPITransmit_pna);
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_f);
    } else {
      PMSM_to_BLDC_mod1_DW.Subsystem_MODE_b = false;
    }

    /* End of SignalConversion generated from: '<S40>/Enable' */
    /* End of Outputs for SubSystem: '<S33>/Subsystem' */
    /* End of Outputs for SubSystem: '<Root>/SPI_read' */

    /* Outputs for Atomic SubSystem: '<Root>/En_gate' */
    /* MATLABSystem: '<S19>/Digital Port Write' */
    portNameLoc = GPIOB;
    channelEnum = MW_GPIO_BIT_SHIFT;
    if (PMSM_to_BLDC_mod1_B.En_State != 0.0) {
      freq = 4096U;
    } else {
      freq = 0U;
    }

    freq = mw_shift(freq, channelEnum);
    pinMask = mw_shift(4096U, channelEnum);
    LL_GPIO_SetOutputPin(portNameLoc, freq);
    LL_GPIO_ResetOutputPin(portNameLoc, ~freq & pinMask);

    /* End of MATLABSystem: '<S19>/Digital Port Write' */
    /* End of Outputs for SubSystem: '<Root>/En_gate' */
  }

  if (tmp_1) {
  }

  if (tmp_0) {
    /* Outputs for Atomic SubSystem: '<Root>/Current_sensing' */
    /* Outputs for Enabled SubSystem: '<S2>/Subsystem' incorporates:
     *  EnablePort: '<S9>/Enable'
     */
    /* SignalConversion generated from: '<S9>/Enable' */
    if (PMSM_to_BLDC_mod1_B.Ib_flag > 0.0) {
      /* MATLABSystem: '<S13>/Analog to Digital Converter' */
      if (PMSM_to_BLDC_mod1_DW.obj_d.TunablePropsChanged) {
        PMSM_to_BLDC_mod1_DW.obj_d.TunablePropsChanged = false;
      }

      regularReadADCNormal(PMSM_to_BLDC_mod1_DW.obj_d.ADCHandle,
                           ADC_TRIGGER_AND_READ, &status);

      /* Gain: '<S9>/Gain' incorporates:
       *  DataTypeConversion: '<S9>/Data Type Conversion'
       *  MATLABSystem: '<S13>/Analog to Digital Converter'
       */
      PMSM_to_BLDC_mod1_B.Gain_k = 0.02442002442002442 * (real_T)status;
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_g);
    }

    /* End of SignalConversion generated from: '<S9>/Enable' */
    /* End of Outputs for SubSystem: '<S2>/Subsystem' */

    /* Outputs for Enabled SubSystem: '<S2>/Subsystem1' incorporates:
     *  EnablePort: '<S10>/Enable'
     */
    /* SignalConversion generated from: '<S10>/Enable' */
    if (PMSM_to_BLDC_mod1_B.Ic_flag > 0.0) {
      /* MATLABSystem: '<S16>/Analog to Digital Converter' */
      if (PMSM_to_BLDC_mod1_DW.obj_o.TunablePropsChanged) {
        PMSM_to_BLDC_mod1_DW.obj_o.TunablePropsChanged = false;
      }

      regularReadADCNormal(PMSM_to_BLDC_mod1_DW.obj_o.ADCHandle,
                           ADC_TRIGGER_AND_READ, &status);

      /* Gain: '<S10>/Gain1' incorporates:
       *  DataTypeConversion: '<S10>/Data Type Conversion1'
       *  MATLABSystem: '<S16>/Analog to Digital Converter'
       */
      PMSM_to_BLDC_mod1_B.Gain1_m = 0.02442002442002442 * (real_T)status;
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_c);
    }

    /* End of SignalConversion generated from: '<S10>/Enable' */
    /* End of Outputs for SubSystem: '<S2>/Subsystem1' */
    /* End of Outputs for SubSystem: '<Root>/Current_sensing' */
  }

  if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
      PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[3] == 0) {
    /* MATLABSystem: '<S459>/Analog to Digital Converter' */
    if (PMSM_to_BLDC_mod1_DW.obj_p.TunablePropsChanged) {
      PMSM_to_BLDC_mod1_DW.obj_p.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S459>/Analog to Digital Converter' */
    regularReadADCNormal(PMSM_to_BLDC_mod1_DW.obj_p.ADCHandle,
                         ADC_TRIGGER_AND_READ,
                         &PMSM_to_BLDC_mod1_B.AnalogtoDigitalConverter);

    /* Gain: '<S8>/Gain' incorporates:
     *  DataTypeConversion: '<S8>/Data Type Conversion'
     */
    PMSM_to_BLDC_mod1_B.Gain = 0.015625 * (real_T)
      PMSM_to_BLDC_mod1_B.AnalogtoDigitalConverter;
  }

  if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M)) {
    if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
        PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for Delay: '<Root>/Delay' */
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_cn = PMSM_to_BLDC_mod1_B.Compare_g;

      /* Update for Delay: '<Root>/Delay1' */
      PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fv = PMSM_to_BLDC_mod1_B.Compare_a;
    }

    /* Update for Enabled SubSystem: '<Root>/Subsystem' incorporates:
     *  EnablePort: '<S7>/Enable'
     */
    if (PMSM_to_BLDC_mod1_DW.Subsystem_MODE) {
      if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
          PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0) {
        /* Update for Delay: '<S56>/Delay' */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[0] =
          PMSM_to_BLDC_mod1_B.DataTypeConversion_c[0];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[1] =
          PMSM_to_BLDC_mod1_B.DataTypeConversion_c[1];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[2] =
          PMSM_to_BLDC_mod1_B.DataTypeConversion_c[2];

        /* Update for Delay: '<S59>/Delay' */
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

        /* Update for Delay: '<S249>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad = false;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[0] = rtb_Add1[0];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[1] = rtb_Add1[1];

        /* Update for Delay: '<S332>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_f = false;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_a = rtb_Add1_e;

        /* Update for DiscreteIntegrator: '<S301>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE = PMSM_to_BLDC_mod1_B.Integrator;
        PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState = 0;

        /* Update for Delay: '<S357>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_a = false;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_ai = rtb_Switch2;

        /* Update for DiscreteIntegrator: '<S171>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b += rtb_Switch_e;
        PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState_n = 1;

        /* Update for DiscreteIntegrator: '<S116>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n += rtb_Switch;
        PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState_nt = 1;

        /* Update for Delay: '<S263>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_b = false;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_g = rtb_Add1_d;
      }

      /* Update for Integrator: '<S390>/Integrator' */
      PMSM_to_BLDC_mod1_DW.Integrator_DWORK1 = false;

      /* Update for Integrator: '<S391>/Integrator' */
      PMSM_to_BLDC_mod1_DW.Integrator_DWORK1_g = false;
    }

    /* End of Update for SubSystem: '<Root>/Subsystem' */
    if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
        PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.0001s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
        ((PMSM_to_BLDC_mod1_M->Timing.clockTick1) * 0.0001);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1, extmodeTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
        PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] == 0) {/* Sample time: [0.001s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
        ((PMSM_to_BLDC_mod1_M->Timing.clockTick2) * 0.001);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(2, extmodeTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
        PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[3] == 0) {/* Sample time: [0.1s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
        ((PMSM_to_BLDC_mod1_M->Timing.clockTick3) * 0.1);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(3, extmodeTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
        PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[4] == 0) {/* Sample time: [1.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
        ((PMSM_to_BLDC_mod1_M->Timing.clockTick4) * 1.0);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(4, extmodeTime);
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
      /* Update absolute timer for sample time: [0.0001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.0001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      PMSM_to_BLDC_mod1_M->Timing.clockTick1++;
    }

    if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
        PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] == 0) {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick2" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick2" ensures timer will not overflow during the
       * application lifespan selected.
       */
      PMSM_to_BLDC_mod1_M->Timing.clockTick2++;
    }

    if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
        PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[3] == 0) {
      /* Update absolute timer for sample time: [0.1s, 0.0s] */
      /* The "clockTick3" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.1, which is the step size
       * of the task. Size of "clockTick3" ensures timer will not overflow during the
       * application lifespan selected.
       */
      PMSM_to_BLDC_mod1_M->Timing.clockTick3++;
    }

    if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
        PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[4] == 0) {
      /* Update absolute timer for sample time: [1.0s, 0.0s] */
      /* The "clockTick4" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 1.0, which is the step size
       * of the task. Size of "clockTick4" ensures timer will not overflow during the
       * application lifespan selected.
       */
      PMSM_to_BLDC_mod1_M->Timing.clockTick4++;
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

  /* Derivatives for Enabled SubSystem: '<Root>/Subsystem' */
  if (PMSM_to_BLDC_mod1_DW.Subsystem_MODE) {
    /* Derivatives for Integrator: '<S437>/Integrator' */
    _rtXdot->Integrator_CSTATE = PMSM_to_BLDC_mod1_B.IntegralGain;

    /* Derivatives for Integrator: '<S375>/Int1' incorporates:
     *  Constant: '<S371>/Speed_Angular_Vel'
     */
    _rtXdot->Int1_CSTATE = 600.0;

    /* Derivatives for Integrator: '<S390>/Integrator' */
    lsat = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d <= -1.0E+7);
    usat = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d >= 1.0E+7);
    if (((!lsat) && (!usat)) || (lsat && (PMSM_to_BLDC_mod1_B.Add_h > 0.0)) ||
        (usat && (PMSM_to_BLDC_mod1_B.Add_h < 0.0))) {
      _rtXdot->Integrator_CSTATE_d = PMSM_to_BLDC_mod1_B.Add_h;
    } else {
      /* in saturation */
      _rtXdot->Integrator_CSTATE_d = 0.0;
    }

    /* End of Derivatives for Integrator: '<S390>/Integrator' */

    /* Derivatives for Integrator: '<S391>/Integrator' */
    lsat = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l <= -1.0E+7);
    usat = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l >= 1.0E+7);
    if (((!lsat) && (!usat)) || (lsat && (PMSM_to_BLDC_mod1_B.Add_d > 0.0)) ||
        (usat && (PMSM_to_BLDC_mod1_B.Add_d < 0.0))) {
      _rtXdot->Integrator_CSTATE_l = PMSM_to_BLDC_mod1_B.Add_d;
    } else {
      /* in saturation */
      _rtXdot->Integrator_CSTATE_l = 0.0;
    }

    /* End of Derivatives for Integrator: '<S391>/Integrator' */
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

  /* End of Derivatives for SubSystem: '<Root>/Subsystem' */
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
  PMSM_to_BLDC_mod1_M->intgData.f[3] = PMSM_to_BLDC_mod1_M->odeF[3];
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
  rtsiSetSolverName(&PMSM_to_BLDC_mod1_M->solverInfo,"ode4");
  rtmSetTPtr(PMSM_to_BLDC_mod1_M, &PMSM_to_BLDC_mod1_M->Timing.tArray[0]);
  rtmSetTFinal(PMSM_to_BLDC_mod1_M, 100.0);
  PMSM_to_BLDC_mod1_M->Timing.stepSize0 = 0.0001;
  rtmSetFirstInitCond(PMSM_to_BLDC_mod1_M, 1);

  /* External mode info */
  PMSM_to_BLDC_mod1_M->Sizes.checksums[0] = (814011125U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[1] = (2900702292U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[2] = (3688883448U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[3] = (1043117470U);

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
    systemRan[61] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC;
    systemRan[62] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IfActionSubsystem_d.IfActionSubsystem_SubsysRanBC;
    systemRan[63] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IfActionSubsystem1_j.IfActionSubsystem1_SubsysRanBC;
    systemRan[64] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC;
    systemRan[65] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Dir_Sense_SubsysRanBC;
    systemRan[66] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem2_SubsysRanBC;
    systemRan[67] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem3_SubsysRanBC;
    systemRan[68] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IfActionSubsystem_SubsysRanBC_b;
    systemRan[69] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_o;
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
    systemRan[82] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC;
    systemRan[83] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC;
    systemRan[84] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[85] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[86] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC;
    systemRan[87] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC;
    systemRan[88] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PMSM_to_BLDC_mod1_M->extModeInfo,
      &PMSM_to_BLDC_mod1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PMSM_to_BLDC_mod1_M->extModeInfo,
                        PMSM_to_BLDC_mod1_M->Sizes.checksums);
    rteiSetTPtr(PMSM_to_BLDC_mod1_M->extModeInfo, rtmGetTPtr(PMSM_to_BLDC_mod1_M));
  }

  /* block I/O */
  {
    PMSM_to_BLDC_mod1_B.Gain2_g = 5730.0;
    PMSM_to_BLDC_mod1_B.Gain1_e = 5730.0;
    PMSM_to_BLDC_mod1_B.Constant1 = 95.541401273885342;
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

  /* SystemInitialize for Atomic SubSystem: '<S20>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift);

  /* End of SystemInitialize for SubSystem: '<S20>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S20>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1);

  /* End of SystemInitialize for SubSystem: '<S20>/Bit Shift1' */

  /* Start for MATLABSystem: '<S20>/SPI Receive' */
  PMSM_to_BLDC_mod1_DW.obj_g.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj_g.matlabCodegenIsDeleted = false;
  PMSM_to_BL_SystemCore_setup_oxg(&PMSM_to_BLDC_mod1_DW.obj_g);

  /* Start for MATLABSystem: '<S20>/SPI Transmit' */
  PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete = false;
  PMSM_to_BLDC_mod1_DW.obj_j.isInitialized = 1;
  PMSM_to_SPIDrvBlock_setupImpl_o(&PMSM_to_BLDC_mod1_DW.obj_j);
  PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<S4>/Control_Reg2' */
  /* SystemInitialize for Atomic SubSystem: '<S21>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_h);

  /* End of SystemInitialize for SubSystem: '<S21>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S21>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_d);

  /* End of SystemInitialize for SubSystem: '<S21>/Bit Shift1' */

  /* Start for MATLABSystem: '<S21>/SPI Transmit' */
  PMSM_to_BLDC_mod1_DW.obj_n.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_n.isSetupComplete = false;
  PMSM_to_BLDC_mod1_DW.obj_n.isInitialized = 1;
  PMSM_to_SPIDrvBlock_setupImpl_o(&PMSM_to_BLDC_mod1_DW.obj_n);
  PMSM_to_BLDC_mod1_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S21>/SPI Receive' */
  PMSM_to_BLDC_mod1_DW.obj.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = false;
  PMSM_to_B_SystemCore_setup_oxgk(&PMSM_to_BLDC_mod1_DW.obj);

  /* End of SystemInitialize for SubSystem: '<S4>/Ctrl_Reg_1' */
  /* End of SystemInitialize for SubSystem: '<Root>/SPI_Write' */
  /* SystemInitialize for Atomic SubSystem: '<S47>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_n);

  /* End of SystemInitialize for SubSystem: '<S47>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S47>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_o);

  /* End of SystemInitialize for SubSystem: '<S47>/Bit Shift1' */
  PMSM_to_BLDC__SPIReceive_k_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaevv);
  PMSM_to_BLDC_SPITransmit_d_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnaevv);

  /* End of SystemInitialize for SubSystem: '<S6>/Status_Reg_2_read' */

  /* SystemInitialize for Atomic SubSystem: '<S46>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_p);

  /* End of SystemInitialize for SubSystem: '<S46>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S46>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_j);

  /* End of SystemInitialize for SubSystem: '<S46>/Bit Shift1' */
  PMSM_to_BLDC__SPIReceive_k_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaev);
  PMSM_to_BLDC_SPITransmit_d_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnaev);

  /* End of SystemInitialize for SubSystem: '<S6>/Status_Reg1_read' */

  /* Start for If: '<S250>/If' */
  PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem = -1;

  /* Start for SwitchCase: '<S259>/Switch Case' */
  PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for If: '<S256>/If' */
  PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_g = -1;

  /* Start for SwitchCase: '<S258>/Switch Case' */
  PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem_n = -1;

  /* Start for If: '<S361>/If' */
  PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_e = -1;

  /* Start for If: '<S222>/If' */
  PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_c = -1;

  /* Start for If: '<S196>/If' */
  PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_m = -1;

  /* InitializeConditions for Delay: '<S249>/Delay' */
  PMSM_to_BLDC_mod1_DW.icLoad = true;

  /* InitializeConditions for Delay: '<S332>/Delay' */
  PMSM_to_BLDC_mod1_DW.icLoad_f = true;

  /* InitializeConditions for Delay: '<S357>/Delay' */
  PMSM_to_BLDC_mod1_DW.icLoad_a = true;

  /* InitializeConditions for DiscreteIntegrator: '<S171>/Integrator' */
  PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b =
    PMSM_to_BLDC_mod1_ConstB.Constant3_n;

  /* InitializeConditions for Integrator: '<S437>/Integrator' */
  PMSM_to_BLDC_mod1_X.Integrator_CSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S116>/Integrator' */
  PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n = PMSM_to_BLDC_mod1_ConstB.Constant3;

  /* InitializeConditions for Delay: '<S263>/Delay' */
  PMSM_to_BLDC_mod1_DW.icLoad_b = true;

  /* InitializeConditions for Integrator: '<S375>/Int1' */
  PMSM_to_BLDC_mod1_X.Int1_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S390>/Integrator' incorporates:
   *  Integrator: '<S391>/Integrator'
   */
  if (rtmIsFirstInitCond(PMSM_to_BLDC_mod1_M)) {
    PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d = 0.0;
    PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l = 0.0;
  }

  PMSM_to_BLDC_mod1_DW.Integrator_DWORK1 = true;

  /* End of InitializeConditions for Integrator: '<S390>/Integrator' */

  /* InitializeConditions for Integrator: '<S391>/Integrator' */
  PMSM_to_BLDC_mod1_DW.Integrator_DWORK1_g = true;

  /* SystemInitialize for IfAction SubSystem: '<S258>/IntegralMethod' */
  /* InitializeConditions for Delay: '<S339>/Delay' */
  PMSM_to_BLDC_mod1_DW.icLoad_bd = true;

  /* InitializeConditions for Delay: '<S342>/Delay' */
  PMSM_to_BLDC_mod1_DW.icLoad_k = true;

  /* End of SystemInitialize for SubSystem: '<S258>/IntegralMethod' */

  /* SystemInitialize for IfAction SubSystem: '<S258>/OptimizedDifferentiationMethod' */
  /* InitializeConditions for Delay: '<S349>/Delay' */
  PMSM_to_BLDC_mod1_DW.icLoad_b1 = true;

  /* InitializeConditions for Delay: '<S352>/Delay' */
  PMSM_to_BLDC_mod1_DW.icLoad_c = true;

  /* End of SystemInitialize for SubSystem: '<S258>/OptimizedDifferentiationMethod' */

  /* Start for MATLABSystem: '<S456>/PWM Output' */
  PMSM_to_BLDC_mod1_DW.obj_e.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_e.isSetupComplete = false;
  PMSM_to_BLDC_mod1_DW.obj_e.isInitialized = 1;
  PMSM_to_BLD_PWMOutput_setupImpl(&PMSM_to_BLDC_mod1_DW.obj_e);
  PMSM_to_BLDC_mod1_DW.obj_e.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<Root>/Subsystem' */
  /* SystemInitialize for Enabled SubSystem: '<S32>/Subsystem1' */
  PMSM_to_BLDC__SPIReceive_e_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pn);
  PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pn);

  /* End of SystemInitialize for SubSystem: '<S32>/Subsystem1' */

  /* SystemInitialize for Enabled SubSystem: '<S33>/Subsystem1' */
  PMSM_to_BLDC__SPIReceive_e_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnae);
  PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnae);

  /* End of SystemInitialize for SubSystem: '<S33>/Subsystem1' */

  /* SystemInitialize for Atomic SubSystem: '<S34>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_hq);

  /* End of SystemInitialize for SubSystem: '<S34>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S34>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_p);

  /* End of SystemInitialize for SubSystem: '<S34>/Bit Shift1' */
  PMSM_to_BLDC_mo_SPIReceive_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_p);
  PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_p);

  /* End of SystemInitialize for SubSystem: '<S32>/Subsystem' */

  /* SystemInitialize for Atomic SubSystem: '<S40>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_b);

  /* End of SystemInitialize for SubSystem: '<S40>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S40>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_m);

  /* End of SystemInitialize for SubSystem: '<S40>/Bit Shift1' */
  PMSM_to_BLDC_mo_SPIReceive_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pna);
  PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pna);

  /* End of SystemInitialize for SubSystem: '<S33>/Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/SPI_read' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/En_gate' */
  /* Start for MATLABSystem: '<S19>/Digital Port Write' */
  PMSM_to_BLDC_mod1_DW.obj_ow.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_ow.isInitialized = 1;
  PMSM_to_BLDC_mod1_DW.obj_ow.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<Root>/En_gate' */
  /* Start for MATLABSystem: '<S13>/Analog to Digital Converter' */
  PMSM_to_BLDC_mod1_DW.obj_d.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj_d.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_SystemCore_setup_o(&PMSM_to_BLDC_mod1_DW.obj_d);

  /* End of SystemInitialize for SubSystem: '<S2>/Subsystem' */
  /* Start for MATLABSystem: '<S16>/Analog to Digital Converter' */
  PMSM_to_BLDC_mod1_DW.obj_o.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted = false;
  PMSM_to_BLD_SystemCore_setup_ox(&PMSM_to_BLDC_mod1_DW.obj_o);

  /* End of SystemInitialize for SubSystem: '<S2>/Subsystem1' */
  /* End of SystemInitialize for SubSystem: '<Root>/Current_sensing' */

  /* Start for MATLABSystem: '<S459>/Analog to Digital Converter' */
  PMSM_to_BLDC_mod1_DW.obj_p.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj_p.matlabCodegenIsDeleted = false;
  PMSM_to__SystemCore_setup_oxgkf(&PMSM_to_BLDC_mod1_DW.obj_p);

  /* ConstCode for Enabled SubSystem: '<Root>/Subsystem' */
  /* ConstCode for Gain: '<S56>/Gain2' incorporates:
   *  Constant: '<S56>/Constant'
   */
  PMSM_to_BLDC_mod1_B.Gain2_g = 5730.0;

  /* ConstCode for Gain: '<S371>/Gain1' incorporates:
   *  Constant: '<S371>/Speed_Angular_Vel'
   */
  PMSM_to_BLDC_mod1_B.Gain1_e = 5730.0;

  /* ConstCode for Constant: '<S56>/Constant1' */
  PMSM_to_BLDC_mod1_B.Constant1 = 95.541401273885342;

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
  /* Terminate for Enabled SubSystem: '<S4>/Control_Reg2' */
  /* Terminate for MATLABSystem: '<S20>/SPI Receive' */
  if (!PMSM_to_BLDC_mod1_DW.obj_g.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_g.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_g.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_g.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S20>/SPI Receive' */
  /* Terminate for MATLABSystem: '<S20>/SPI Transmit' */
  if (!PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_j.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S20>/SPI Transmit' */
  /* Terminate for Enabled SubSystem: '<S4>/Ctrl_Reg_1' */
  /* Terminate for MATLABSystem: '<S21>/SPI Transmit' */
  if (!PMSM_to_BLDC_mod1_DW.obj_n.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_n.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_n.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_n.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S21>/SPI Transmit' */
  /* Terminate for MATLABSystem: '<S21>/SPI Receive' */
  if (!PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S21>/SPI Receive' */
  /* End of Terminate for SubSystem: '<S4>/Ctrl_Reg_1' */

  /* Terminate for Enabled SubSystem: '<S6>/Status_Reg_2_read' */
  PMSM_to_BLDC__SPIReceive_c_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaevv);
  PMSM_to_BLDC_SPITransmit_a_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnaevv);

  /* Terminate for Enabled SubSystem: '<S6>/Status_Reg1_read' */
  PMSM_to_BLDC__SPIReceive_c_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaev);
  PMSM_to_BLDC_SPITransmit_a_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnaev);

  /* Terminate for MATLABSystem: '<S456>/PWM Output' */
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

  /* End of Terminate for MATLABSystem: '<S456>/PWM Output' */

  /* Terminate for Atomic SubSystem: '<Root>/SPI_read' */
  /* Terminate for Enabled SubSystem: '<S32>/Subsystem1' */
  PMSM_to_BLDC__SPIReceive_m_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pn);
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pn);

  /* End of Terminate for SubSystem: '<S32>/Subsystem1' */

  /* Terminate for Enabled SubSystem: '<S33>/Subsystem1' */
  PMSM_to_BLDC__SPIReceive_m_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnae);
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnae);

  /* End of Terminate for SubSystem: '<S33>/Subsystem1' */

  /* Terminate for Enabled SubSystem: '<S32>/Subsystem' */
  PMSM_to_BLDC_mo_SPIReceive_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_p);
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_p);

  /* Terminate for Enabled SubSystem: '<S33>/Subsystem' */
  PMSM_to_BLDC_mo_SPIReceive_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pna);
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pna);

  /* Terminate for Atomic SubSystem: '<Root>/En_gate' */
  /* Terminate for MATLABSystem: '<S19>/Digital Port Write' */
  if (!PMSM_to_BLDC_mod1_DW.obj_ow.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_ow.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S19>/Digital Port Write' */
  /* End of Terminate for SubSystem: '<Root>/En_gate' */
  /* Terminate for Atomic SubSystem: '<Root>/Current_sensing' */
  /* Terminate for Enabled SubSystem: '<S2>/Subsystem' */
  /* Terminate for MATLABSystem: '<S13>/Analog to Digital Converter' */
  if (!PMSM_to_BLDC_mod1_DW.obj_d.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_d.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_d.isSetupComplete) {
      ADC_Handle_Deinit(PMSM_to_BLDC_mod1_DW.obj_d.ADCHandle, ADC_NORMAL_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S13>/Analog to Digital Converter' */
  /* Terminate for Enabled SubSystem: '<S2>/Subsystem1' */
  /* Terminate for MATLABSystem: '<S16>/Analog to Digital Converter' */
  if (!PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_o.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_o.isSetupComplete) {
      ADC_Handle_Deinit(PMSM_to_BLDC_mod1_DW.obj_o.ADCHandle, ADC_NORMAL_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S16>/Analog to Digital Converter' */
  /* Terminate for MATLABSystem: '<S459>/Analog to Digital Converter' */
  if (!PMSM_to_BLDC_mod1_DW.obj_p.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_p.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_p.isSetupComplete) {
      ADC_Handle_Deinit(PMSM_to_BLDC_mod1_DW.obj_p.ADCHandle, ADC_NORMAL_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S459>/Analog to Digital Converter' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
