/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.c
 *
 * Code generated for Simulink model 'PMSM_to_BLDC_mod1'.
 *
 * Model version                  : 4.972
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Sat May 23 16:23:15 2026
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
#include "stm_adc_ll.h"
#include <stddef.h>
#include "stm_timer_ll.h"
#include "zero_crossing_types.h"
#include <float.h>

/* Named constants for Chart: '<Root>/Chart' */
#define PMSM_to_BLDC__IN_Initialization ((uint8_T)3U)
#define PMSM_to_BLDC_m_IN_Current_sense ((uint8_T)1U)
#define PMSM_to_BLDC_mod1_IN_Dummy     ((uint8_T)1U)
#define PMSM_to_BLDC_mod1_IN_En_Gate   ((uint8_T)2U)
#define PMSM_to_BLDC_mod1_IN_SPI_init1 ((uint8_T)4U)
#define PMSM_to_BLDC_mod1_IN_SPI_init2 ((uint8_T)5U)
#define PMSM_to_BLDC_mod1_IN_SPI_init3 ((uint8_T)6U)
#define PMSM_to_BLDC_mod1_IN_SPI_init4 ((uint8_T)7U)
#define PMSM_to_BLDC_mod1_IN_SPI_write ((uint8_T)2U)
#define PMSM_to_BLDC_mod1_IN_SPI_write2 ((uint8_T)4U)
#define PMSM_to_BLDC_mod1_IN_SPI_write5 ((uint8_T)5U)
#define PMSM_to_BLDC_mod1_IN_SPI_write6 ((uint8_T)6U)
#define PMSM_to_BLDC_mod1_IN_SPI_write7 ((uint8_T)7U)
#define PMSM_to_BLDC_mod1_IN_SPI_write8 ((uint8_T)8U)
#define PMSM_to_BLDC_mod1_IN_SPI_write9 ((uint8_T)9U)
#define PMSM_to_BLDC_mod_IN_SPI_write10 ((uint8_T)3U)

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
static void PMSM_to_BLDC_SystemCore_setup_n(stm32cube_blocks_SPIControlle_T *obj);

/* Forward declaration for local functions */
static void PMSM_to_B_SPIDrvBlock_setupImpl(stm32cube_blocks_SPIControl_d_T *obj);

/* Forward declaration for local functions */
static void PMSM_to_BLD_SystemCore_setup_n2(stm32cube_blocks_SPIControlle_T *obj);

/* Forward declaration for local functions */
static void PMSM_to_SPIDrvBlock_setupImpl_e(stm32cube_blocks_SPIControl_d_T *obj);

/* Forward declaration for local functions */
static void PMSM_to_BL_SystemCore_setup_oxg(stm32cube_blocks_SPIControlle_T *obj);
static void PMSM_to_SPIDrvBlock_setupImpl_o(stm32cube_blocks_SPIControl_d_T *obj);
static void PMSM_to_BLDC_SystemCore_setup_o(stm32cube_blocks_AnalogInput__T *obj);
static void PMSM_to_BLD_SystemCore_setup_ox(stm32cube_blocks_AnalogInput__T *obj);
static void PMSM_to_BLD_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_PM_T *obj);
static void PMSM_to_B_SystemCore_setup_oxgk(stm32cube_blocks_AnalogInput__T *obj);
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
 * Output and update for atomic system:
 *    '<S20>/Bit Shift'
 *    '<S21>/Bit Shift'
 *    '<S34>/Bit Shift'
 *    '<S40>/Bit Shift'
 *    '<S46>/Bit Shift'
 *    '<S47>/Bit Shift'
 */
uint16_T PMSM_to_BLDC_mod1_BitShift(uint16_T rtu_u)
{
  /* MATLAB Function: '<S22>/bit_shift' */
  return (uint16_T)(rtu_u << 15);
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
uint16_T PMSM_to_BLDC_mod1_BitShift1(uint16_T rtu_u)
{
  /* MATLAB Function: '<S23>/bit_shift' */
  return (uint16_T)(rtu_u << 11);
}

static void PMSM_to_BLDC_m_SystemCore_setup(stm32cube_blocks_SPIControlle_T *obj)
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

/* System initialize for atomic system: */
void PMSM_to_BLDC_mo_SPIReceive_Init(DW_SPIReceive_PMSM_to_BLDC_mo_T *localDW)
{
  /* Start for MATLABSystem: '<S21>/SPI Receive' */
  localDW->obj.isInitialized = 0;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  PMSM_to_BLDC_m_SystemCore_setup(&localDW->obj);
}

/* Output and update for atomic system: */
void PMSM_to_BLDC_mod1_SPIReceive(B_SPIReceive_PMSM_to_BLDC_mod_T *localB,
  DW_SPIReceive_PMSM_to_BLDC_mo_T *localDW)
{
  uint16_T status;

  /* MATLABSystem: '<S21>/SPI Receive' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    MW_SPI_Read_Databits(localDW->obj.MW_SPI_HANDLE, &localB->SPIReceive, 1U, 1,
                         1, 1U);
    LL_GPIO_SetOutputPin(GPIOC, 16384U);
  }

  /* End of MATLABSystem: '<S21>/SPI Receive' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC_mo_SPIReceive_Term(DW_SPIReceive_PMSM_to_BLDC_mo_T *localDW)
{
  /* Terminate for MATLABSystem: '<S21>/SPI Receive' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S21>/SPI Receive' */
}

static void PMSM_to_BLDC_SystemCore_setup_n(stm32cube_blocks_SPIControlle_T *obj)
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
void PMSM_to_BLDC__SPIReceive_e_Init(DW_SPIReceive_PMSM_to_BLDC__f_T *localDW)
{
  /* Start for MATLABSystem: '<S34>/SPI Receive' */
  localDW->obj.isInitialized = 0;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  PMSM_to_BLDC_SystemCore_setup_n(&localDW->obj);
}

/* Output and update for atomic system: */
void PMSM_to_BLDC_mod1_SPIReceive_p(DW_SPIReceive_PMSM_to_BLDC__f_T *localDW)
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
void PMSM_to_BLDC__SPIReceive_m_Term(DW_SPIReceive_PMSM_to_BLDC__f_T *localDW)
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
void PMSM_to_BLDC_mod1_SPIReceive_pn(DW_SPIReceive_PMSM_to_BLDC_fw_T *localDW)
{
  uint16_T tmp[15];
  uint16_T status;

  /* MATLABSystem: '<S46>/SPI Receive' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    MW_SPI_Read_Databits(localDW->obj.MW_SPI_HANDLE, &tmp[0], 15U, 1, 1, 1U);
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
real_T PMSM_to_BLDC__IfActionSubsystem(real_T rtu_In1)
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
  return rtu_In1 - (real_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
    -tmp : (int32_T)(int16_T)(uint16_T)tmp);
}

/*
 * Output and update for action system:
 *    '<S196>/If Action Subsystem1'
 *    '<S222>/If Action Subsystem1'
 */
real_T PMSM_to_BLDC_IfActionSubsystem1(real_T rtu_In1)
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
  return rtu_In1 - (real_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
    -tmp : (int32_T)(int16_T)(uint16_T)tmp);
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
    enableCounter(obj->TimerHandle, false);
  }
}

static void PMSM_to_B_SystemCore_setup_oxgk(stm32cube_blocks_AnalogInput__T *obj)
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
  real_T rtb_Switch;
  real_T rtb_Switch_e;
  real_T rtb_Add1_d;
  real_T rtb_TmpSignalConversionAtDelayI[4];
  real_T rtb_Add_km;
  real_T rtb_Gain3_c;
  GPIO_TypeDef * portNameLoc;
  TIM_TypeDef * timModule;
  uint32_T shiftVal;
  real_T rtb_Add_km_tmp;
  real_T rtb_Add_km_tmp_0;
  real_T rtb_Delay2_g;
  real_T rtb_Gain4_g;
  real_T rtb_Gain_e;
  real_T rtb_Min;
  real_T rtb_Product1_o;
  real_T rtb_Product2_a;
  real_T rtb_Product_j_idx_1;
  real_T rtb_Saturation;
  real_T rtb_Sum1_eq;
  real_T rtb_Sum1_k;
  real_T rtb_Sum6_g;
  real_T rtb_Sum_n;
  real_T rtb_one_by_sqrt3_;
  real_T rtb_uabc3;
  real_T tmp_2;
  real32_T rtb_Saturation_l;
  real32_T rtb_indexing;
  uint32_T pinMask;
  uint32_T pinWriteLoc;
  uint16_T tmp[16];
  uint16_T rtb_y_e;
  uint16_T status;
  int8_T rtAction;
  int8_T rtPrevAction;
  boolean_T rtb_RelationalOperator;
  boolean_T rtb_fixforDTpropagationissue;
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

  tmp_0 = (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
           PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[3] == 0);
  if (tmp_0) {
    /* Chart: '<Root>/Chart' */
    if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 < 32767) {
      PMSM_to_BLDC_mod1_DW.temporalCounter_i1++;
    }

    if (PMSM_to_BLDC_mod1_DW.temporalCounter_i2 < 8191) {
      PMSM_to_BLDC_mod1_DW.temporalCounter_i2++;
    }

    if (PMSM_to_BLDC_mod1_DW.is_active_c3_PMSM_to_BLDC_mod1 == 0) {
      PMSM_to_BLDC_mod1_DW.is_active_c3_PMSM_to_BLDC_mod1 = 1U;
      PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
      PMSM_to_BLDC_mod1_DW.is_Test2 = PMSM_to_BLDC_mod1_IN_Dummy;
      PMSM_to_BLDC_mod1_DW.Drv_ok = 0.0;
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
        }
        break;
      }
    }

    /* End of Chart: '<Root>/Chart' */
  }

  tmp_1 = (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
           PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] == 0);
  if (tmp_1) {
    /* Outputs for Atomic SubSystem: '<Root>/SPI_Write' */
    /* Outputs for Enabled SubSystem: '<S4>/Control_Reg2' incorporates:
     *  EnablePort: '<S20>/Enable'
     */
    /* Logic: '<S4>/AND1' incorporates:
     *  Constant: '<S20>/Constant'
     *  Constant: '<S20>/Constant1'
     */
    if ((PMSM_to_BLDC_mod1_B.En_State != 0.0) && (PMSM_to_BLDC_mod1_B.Ctrl_flag2
         != 0.0)) {
      /* MATLABSystem: '<S20>/SPI Receive' */
      status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, 2U,
        3840U, MW_SPI_MODE_3);
      if (status == 0) {
        MW_SPI_Read_Databits(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, &tmp[0],
                             16U, 1, 1, 1U);
        LL_GPIO_SetOutputPin(GPIOC, 16384U);
      }

      /* End of MATLABSystem: '<S20>/SPI Receive' */

      /* Outputs for Atomic SubSystem: '<S20>/Bit Shift' */
      status = PMSM_to_BLDC_mod1_BitShift(0);

      /* End of Outputs for SubSystem: '<S20>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S20>/Bit Shift1' */
      rtb_y_e = PMSM_to_BLDC_mod1_BitShift1(3);

      /* End of Outputs for SubSystem: '<S20>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S20>/Bitwise OR' incorporates:
       *  Constant: '<S20>/Constant'
       *  Constant: '<S20>/Constant1'
       */
      rtb_y_e = (uint16_T)(status | rtb_y_e |
                           PMSM_to_BLDC_mod1_ConstB.BitwiseAND_jx);

      /* MATLABSystem: '<S20>/SPI Transmit' */
      status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE,
        2U, 3840U, MW_SPI_MODE_3);
      if (status == 0) {
        LL_GPIO_ResetOutputPin(GPIOC, 16384U);
        MW_SPI_Write_Databits(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE, &rtb_y_e,
                              1U, 1, 1, 1000U);
      }

      /* End of MATLABSystem: '<S20>/SPI Transmit' */
    }

    /* End of Logic: '<S4>/AND1' */
    /* End of Outputs for SubSystem: '<S4>/Control_Reg2' */

    /* Outputs for Enabled SubSystem: '<S4>/Ctrl_Reg_1' incorporates:
     *  EnablePort: '<S21>/Enable'
     */
    /* Logic: '<S4>/AND' incorporates:
     *  Constant: '<S21>/Constant'
     *  Constant: '<S21>/Constant1'
     */
    if ((PMSM_to_BLDC_mod1_B.En_State != 0.0) && (PMSM_to_BLDC_mod1_B.Ctrl_flag1
         != 0.0)) {
      /* Outputs for Atomic SubSystem: '<S21>/Bit Shift' */
      status = PMSM_to_BLDC_mod1_BitShift(0);

      /* End of Outputs for SubSystem: '<S21>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S21>/Bit Shift1' */
      rtb_y_e = PMSM_to_BLDC_mod1_BitShift1(2);

      /* End of Outputs for SubSystem: '<S21>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S21>/Bitwise OR' incorporates:
       *  Constant: '<S21>/Constant'
       *  Constant: '<S21>/Constant1'
       */
      rtb_y_e = (uint16_T)(status | rtb_y_e |
                           PMSM_to_BLDC_mod1_ConstB.BitwiseAND_e);

      /* MATLABSystem: '<S21>/SPI Transmit' */
      status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_n.MW_SPI_HANDLE,
        2U, 3840U, MW_SPI_MODE_3);
      if (status == 0) {
        LL_GPIO_ResetOutputPin(GPIOC, 16384U);
        MW_SPI_Write_Databits(PMSM_to_BLDC_mod1_DW.obj_n.MW_SPI_HANDLE, &rtb_y_e,
                              1U, 1, 1, 10U);
      }

      /* End of MATLABSystem: '<S21>/SPI Transmit' */
      PMSM_to_BLDC_mod1_SPIReceive(&PMSM_to_BLDC_mod1_B.SPIReceive_j,
        &PMSM_to_BLDC_mod1_DW.SPIReceive_j);
    }

    /* End of Logic: '<S4>/AND' */
    /* End of Outputs for SubSystem: '<S4>/Ctrl_Reg_1' */
    /* End of Outputs for SubSystem: '<Root>/SPI_Write' */
  }

  if (tmp_0) {
    /* Outputs for Enabled SubSystem: '<S6>/Status_Reg_2_read' incorporates:
     *  EnablePort: '<S47>/Ctrl_flag2'
     */
    /* Outputs for Enabled SubSystem: '<S6>/Status_Reg1_read' incorporates:
     *  EnablePort: '<S46>/Ctrl_flag1'
     */
    tmp_0 = rtsiIsModeUpdateTimeStep(&PMSM_to_BLDC_mod1_M->solverInfo);

    /* End of Outputs for SubSystem: '<S6>/Status_Reg_2_read' */
    if (tmp_0) {
      PMSM_to_BLDC_mod1_DW.Status_Reg1_read_MODE =
        (PMSM_to_BLDC_mod1_B.spi_write1 > 0.0);
    }

    if (PMSM_to_BLDC_mod1_DW.Status_Reg1_read_MODE) {
      PMSM_to_BLDC_mod1_SPIReceive_pn(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaev);

      /* Outputs for Atomic SubSystem: '<S46>/Bit Shift' */
      /* Constant: '<S46>/Constant' */
      status = PMSM_to_BLDC_mod1_BitShift(1);

      /* End of Outputs for SubSystem: '<S46>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S46>/Bit Shift1' */
      /* Constant: '<S46>/Constant1' */
      rtb_y_e = PMSM_to_BLDC_mod1_BitShift1(0);

      /* End of Outputs for SubSystem: '<S46>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S46>/Bitwise OR' */
      PMSM_to_BLDC_mod1_SPITransmit_p((uint16_T)(status | rtb_y_e |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_m),
        &PMSM_to_BLDC_mod1_DW.SPITransmit_pnaev);
    }

    /* End of Outputs for SubSystem: '<S6>/Status_Reg1_read' */

    /* Outputs for Enabled SubSystem: '<S6>/Status_Reg_2_read' incorporates:
     *  EnablePort: '<S47>/Ctrl_flag2'
     */
    if (tmp_0) {
      PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_MODE =
        (PMSM_to_BLDC_mod1_B.spi_write2 > 0.0);
    }

    if (PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_MODE) {
      PMSM_to_BLDC_mod1_SPIReceive_pn(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaevv);

      /* Outputs for Atomic SubSystem: '<S47>/Bit Shift' */
      /* Constant: '<S47>/Constant' */
      rtb_y_e = PMSM_to_BLDC_mod1_BitShift(1);

      /* End of Outputs for SubSystem: '<S47>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S47>/Bit Shift1' */
      /* Constant: '<S47>/Constant1' */
      status = PMSM_to_BLDC_mod1_BitShift1(1);

      /* End of Outputs for SubSystem: '<S47>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S47>/Bitwise OR' */
      PMSM_to_BLDC_mod1_SPITransmit_p((uint16_T)(rtb_y_e | status |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND),
        &PMSM_to_BLDC_mod1_DW.SPITransmit_pnaevv);
    }

    /* End of Outputs for SubSystem: '<S6>/Status_Reg_2_read' */
  }

  if (tmp_1) {
    /* Outputs for Atomic SubSystem: '<Root>/SPI_read' */
    /* Outputs for Enabled SubSystem: '<S32>/Subsystem1' incorporates:
     *  EnablePort: '<S35>/Ctrl_flag2'
     */
    /* SignalConversion generated from: '<S35>/Ctrl_flag2' incorporates:
     *  Constant: '<S35>/Constant'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write2 > 0.0) {
      PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_g = true;
      PMSM_to_BLDC_mod1_SPIReceive(&PMSM_to_BLDC_mod1_B.SPIReceive_pn,
        &PMSM_to_BLDC_mod1_DW.SPIReceive_pn);
      PMSM_to_BLDC_mod1_SPITransmit(36864, &PMSM_to_BLDC_mod1_DW.SPITransmit_pn);
    } else if (PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_g) {
      /* Disable for MATLABSystem: '<S35>/SPI Receive' incorporates:
       *  Outport: '<S35>/Out1'
       */
      PMSM_to_BLDC_mod1_B.SPIReceive_pn.SPIReceive = 0U;
      PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_g = false;
    }

    /* End of SignalConversion generated from: '<S35>/Ctrl_flag2' */
    /* End of Outputs for SubSystem: '<S32>/Subsystem1' */

    /* Outputs for Enabled SubSystem: '<S32>/Subsystem' incorporates:
     *  EnablePort: '<S34>/Enable'
     */
    /* SignalConversion generated from: '<S34>/Enable' incorporates:
     *  Constant: '<S34>/Constant'
     *  Constant: '<S34>/Constant1'
     *  S-Function (sfix_bitop): '<S34>/Bitwise OR'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write1 > 0.0) {
      PMSM_to_BLDC_mod1_SPIReceive_p(&PMSM_to_BLDC_mod1_DW.SPIReceive_p);

      /* Outputs for Atomic SubSystem: '<S34>/Bit Shift' */
      status = PMSM_to_BLDC_mod1_BitShift(1);

      /* End of Outputs for SubSystem: '<S34>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S34>/Bit Shift1' */
      rtb_y_e = PMSM_to_BLDC_mod1_BitShift1(2);

      /* End of Outputs for SubSystem: '<S34>/Bit Shift1' */
      PMSM_to_BLDC_mod1_SPITransmit((uint16_T)(status | rtb_y_e |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_d),
        &PMSM_to_BLDC_mod1_DW.SPITransmit_p);
    }

    /* End of SignalConversion generated from: '<S34>/Enable' */
    /* End of Outputs for SubSystem: '<S32>/Subsystem' */

    /* Outputs for Enabled SubSystem: '<S33>/Subsystem' incorporates:
     *  EnablePort: '<S40>/Enable'
     */
    /* SignalConversion generated from: '<S40>/Enable' incorporates:
     *  Constant: '<S40>/Constant'
     *  Constant: '<S40>/Constant1'
     *  S-Function (sfix_bitop): '<S40>/Bitwise OR'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write3 > 0.0) {
      PMSM_to_BLDC_mod1_SPIReceive_p(&PMSM_to_BLDC_mod1_DW.SPIReceive_pna);

      /* Outputs for Atomic SubSystem: '<S40>/Bit Shift' */
      rtb_y_e = PMSM_to_BLDC_mod1_BitShift(1);

      /* End of Outputs for SubSystem: '<S40>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S40>/Bit Shift1' */
      status = PMSM_to_BLDC_mod1_BitShift1(3);

      /* End of Outputs for SubSystem: '<S40>/Bit Shift1' */
      PMSM_to_BLDC_mod1_SPITransmit((uint16_T)(rtb_y_e | status |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_j),
        &PMSM_to_BLDC_mod1_DW.SPITransmit_pna);
    }

    /* End of SignalConversion generated from: '<S40>/Enable' */
    /* End of Outputs for SubSystem: '<S33>/Subsystem' */

    /* Outputs for Enabled SubSystem: '<S33>/Subsystem1' incorporates:
     *  EnablePort: '<S41>/Enable'
     */
    /* SignalConversion generated from: '<S41>/Enable' incorporates:
     *  Constant: '<S41>/Constant'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write4 > 0.0) {
      PMSM_to_BLDC_mod1_DW.Subsystem1_MODE = true;
      PMSM_to_BLDC_mod1_SPIReceive(&PMSM_to_BLDC_mod1_B.SPIReceive_pnae,
        &PMSM_to_BLDC_mod1_DW.SPIReceive_pnae);
      PMSM_to_BLDC_mod1_SPITransmit(38912,
        &PMSM_to_BLDC_mod1_DW.SPITransmit_pnae);
    } else if (PMSM_to_BLDC_mod1_DW.Subsystem1_MODE) {
      /* Disable for MATLABSystem: '<S41>/SPI Receive' incorporates:
       *  Outport: '<S41>/Out1'
       */
      PMSM_to_BLDC_mod1_B.SPIReceive_pnae.SPIReceive = 0U;
      PMSM_to_BLDC_mod1_DW.Subsystem1_MODE = false;
    }

    /* End of SignalConversion generated from: '<S41>/Enable' */
    /* End of Outputs for SubSystem: '<S33>/Subsystem1' */
    /* End of Outputs for SubSystem: '<Root>/SPI_read' */
  }

  /* Outputs for Atomic SubSystem: '<Root>/Current_sensing' */
  /* Outputs for Enabled SubSystem: '<S2>/Subsystem1' incorporates:
   *  EnablePort: '<S10>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S2>/Subsystem' incorporates:
   *  EnablePort: '<S9>/Enable'
   */
  tmp_0 = (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
           PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[3] == 0);

  /* End of Outputs for SubSystem: '<S2>/Subsystem1' */
  if (tmp_0) {
    PMSM_to_BLDC_mod1_DW.Subsystem_MODE_h = (PMSM_to_BLDC_mod1_B.Ib_flag > 0.0);
  }

  if (PMSM_to_BLDC_mod1_DW.Subsystem_MODE_h && (rtmIsMajorTimeStep
       (PMSM_to_BLDC_mod1_M) &&
       PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] == 0)) {
    /* MATLABSystem: '<S13>/Analog to Digital Converter' */
    if (PMSM_to_BLDC_mod1_DW.obj_d.TunablePropsChanged) {
      PMSM_to_BLDC_mod1_DW.obj_d.TunablePropsChanged = false;
    }

    regularReadADCNormal(PMSM_to_BLDC_mod1_DW.obj_d.ADCHandle,
                         ADC_TRIGGER_AND_READ, &status);

    /* End of MATLABSystem: '<S13>/Analog to Digital Converter' */
  }

  /* End of Outputs for SubSystem: '<S2>/Subsystem' */

  /* Outputs for Enabled SubSystem: '<S2>/Subsystem1' incorporates:
   *  EnablePort: '<S10>/Enable'
   */
  if (tmp_0) {
    PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_f = (PMSM_to_BLDC_mod1_B.Ic_flag > 0.0);
  }

  if (PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_f && (rtmIsMajorTimeStep
       (PMSM_to_BLDC_mod1_M) &&
       PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] == 0)) {
    /* MATLABSystem: '<S16>/Analog to Digital Converter' */
    if (PMSM_to_BLDC_mod1_DW.obj_o.TunablePropsChanged) {
      PMSM_to_BLDC_mod1_DW.obj_o.TunablePropsChanged = false;
    }

    regularReadADCNormal(PMSM_to_BLDC_mod1_DW.obj_o.ADCHandle,
                         ADC_TRIGGER_AND_READ, &status);

    /* End of MATLABSystem: '<S16>/Analog to Digital Converter' */
  }

  /* End of Outputs for SubSystem: '<S2>/Subsystem1' */
  /* End of Outputs for SubSystem: '<Root>/Current_sensing' */
  if (tmp_1) {
    /* Outputs for Atomic SubSystem: '<Root>/En_gate' */
    /* MATLABSystem: '<S19>/Digital Port Write' */
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

    /* End of MATLABSystem: '<S19>/Digital Port Write' */
    /* End of Outputs for SubSystem: '<Root>/En_gate' */
  }

  /* Outputs for Atomic SubSystem: '<Root>/Timer' */
  tmp_0 = (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
           PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0);
  if (tmp_0) {
    /* MATLABSystem: '<S456>/PWM Output' */
    timModule = TIM8;
    pinWriteLoc = checkFrequencyAndDutyCycleLimits
      (PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, (uint32_T)
       PMSM_to_BLDC_mod1_ConstB.DataTypeConversion1);
    setDutyCycleChannel1(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, pinWriteLoc);
    shiftVal = LL_TIM_CHANNEL_CH1N;
    if (PMSM_to_BLDC_mod1_ConstB.DataTypeConversion_j) {
      LL_TIM_CC_EnableChannel(timModule, shiftVal);
    } else {
      LL_TIM_CC_DisableChannel(timModule, shiftVal);
    }

    pinWriteLoc = checkFrequencyAndDutyCycleLimits
      (PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, (uint32_T)
       PMSM_to_BLDC_mod1_ConstB.DataTypeConversion1);
    setDutyCycleChannel2(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, pinWriteLoc);
    shiftVal = LL_TIM_CHANNEL_CH2N;
    if (PMSM_to_BLDC_mod1_ConstB.DataTypeConversion_j) {
      LL_TIM_CC_EnableChannel(timModule, shiftVal);
    } else {
      LL_TIM_CC_DisableChannel(timModule, shiftVal);
    }

    pinWriteLoc = checkFrequencyAndDutyCycleLimits
      (PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, (uint32_T)
       PMSM_to_BLDC_mod1_ConstB.DataTypeConversion1);
    setDutyCycleChannel3(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, pinWriteLoc);
    shiftVal = LL_TIM_CHANNEL_CH3N;
    if (PMSM_to_BLDC_mod1_ConstB.DataTypeConversion_j) {
      LL_TIM_CC_EnableChannel(timModule, shiftVal);
    } else {
      LL_TIM_CC_DisableChannel(timModule, shiftVal);
    }

    setMOEBitAccToInput(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle,
                        PMSM_to_BLDC_mod1_ConstB.DataTypeConversion_j);

    /* End of MATLABSystem: '<S456>/PWM Output' */

    /* Sum: '<S76>/Sum2' incorporates:
     *  Delay: '<S56>/Delay'
     *  Gain: '<S76>/one_by_3'
     *  Sum: '<S76>/Sum'
     */
    rtb_uabc3 = PMSM_to_BLDC_mod1_DW.Delay_DSTATE[0] -
      ((PMSM_to_BLDC_mod1_DW.Delay_DSTATE[0] +
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[1]) +
       PMSM_to_BLDC_mod1_DW.Delay_DSTATE[2]) * 0.33333333333333331;

    /* Gain: '<S76>/one_by_sqrt3_' incorporates:
     *  Delay: '<S56>/Delay'
     *  Sum: '<S76>/Sum1'
     */
    rtb_one_by_sqrt3_ = (PMSM_to_BLDC_mod1_DW.Delay_DSTATE[1] -
                         PMSM_to_BLDC_mod1_DW.Delay_DSTATE[2]) *
      0.57735026918962584;

    /* Delay: '<S232>/Delay1' */
    if (PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE == POS_ZCSIG) {
      PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f = 0.0F;
    }

    PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE = 0U;

    /* Gain: '<S238>/Gain' incorporates:
     *  Delay: '<S232>/Delay1'
     */
    rtb_Sum1_eq = -0.0017999999690800905 * PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f;

    /* Gain: '<S245>/Gain1' incorporates:
     *  Delay: '<S59>/Delay'
     */
    rtb_Gain_e = 555.55555555555554 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[1];

    /* Gain: '<S245>/Gain' incorporates:
     *  Delay: '<S59>/Delay'
     */
    rtb_Sum1_k = 555.55555555555554 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[0];

    /* Sum: '<S246>/Sum' incorporates:
     *  Product: '<S246>/Product'
     *  Product: '<S246>/Product2'
     *  UnaryMinus: '<S246>/Unary Minus'
     */
    rtb_Sum_n = -rtb_Sum1_eq * rtb_Gain_e - rtb_Sum1_k;

    /* Sum: '<S246>/Sum1' incorporates:
     *  Product: '<S246>/Product1'
     *  Product: '<S246>/Product3'
     */
    rtb_Sum1_k = rtb_Sum1_k * rtb_Sum1_eq - rtb_Gain_e;

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

    /* Sum: '<S242>/Sum' incorporates:
     *  Delay: '<S59>/Delay'
     *  Product: '<S242>/Product2'
     *  UnaryMinus: '<S242>/Unary Minus'
     */
    rtb_Product1_o = -rtb_Gain_e * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[3] -
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[2];

    /* Gain: '<S240>/Gain' */
    rtb_Add_km_tmp = 555.55555555555554 * rtb_Product1_o;

    /* Gain: '<S240>/Gain1' */
    rtb_Add_km_tmp_0 = 555.55555555555554 * rtb_Sum1_eq;

    /* Sum: '<S61>/Add' incorporates:
     *  Gain: '<S240>/Gain'
     *  Gain: '<S240>/Gain1'
     *  Product: '<S243>/Product2'
     *  Sum: '<S243>/Sum'
     *  UnaryMinus: '<S240>/Unary Minus1'
     *  UnaryMinus: '<S243>/Unary Minus'
     */
    rtb_Add_km = -rtb_Add_km_tmp_0 * -rtb_Gain_e + rtb_Add_km_tmp;

    /* Gain: '<S385>/Gain3' incorporates:
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
    rtb_Gain4_g = -(PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[3] *
                    PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f) * 0.0 +
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[2] * -20.555555555555554;

    /* Gain: '<S385>/Gain3' incorporates:
     *  Product: '<S244>/Product1'
     *  Product: '<S244>/Product3'
     *  Sum: '<S244>/Sum1'
     */
    rtb_Gain3_c = rtb_Gain4_g * rtb_Gain_e - rtb_Gain3_c;

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
    rtb_Product_j_idx_1 = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0];
    tmp_2 = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1];

    /* Gain: '<S236>/Gain2' incorporates:
     *  Delay: '<S232>/Delay1'
     *  Delay: '<S236>/Delay'
     *  Gain: '<S236>/Gain1'
     *  Product: '<S241>/Product'
     *  Product: '<S241>/Product1'
     *  Product: '<S243>/Product3'
     *  Product: '<S244>/Product'
     *  Sum: '<S236>/Sum'
     *  Sum: '<S236>/Sum2'
     *  Sum: '<S237>/Sum'
     *  Sum: '<S243>/Sum1'
     *  Sum: '<S244>/Sum'
     *  UnaryMinus: '<S240>/Unary Minus'
     *  UnaryMinus: '<S241>/Unary Minus'
     */
    PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0] = ((((-(rtb_Sum1_eq *
      PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f) - rtb_Add_km) - (rtb_Product2_a -
      rtb_Gain4_g)) - rtb_Sum_n) * 5.0E-5 + rtb_Product_j_idx_1) *
      0.972972972972973;
    PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1] = ((((rtb_Product1_o *
      PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f - (-rtb_Add_km_tmp * rtb_Gain_e +
      rtb_Add_km_tmp_0)) - rtb_Gain3_c) - rtb_Sum1_k) * 5.0E-5 + tmp_2) *
      0.972972972972973;

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

    /* Outputs for Triggered SubSystem: '<S250>/Dir_Sense' incorporates:
     *  TriggerPort: '<S252>/Trigger'
     */
    /* If: '<S250>/If' incorporates:
     *  Relay: '<S250>/AlphaRelay'
     *  SwitchCase: '<S259>/Switch Case'
     */
    if (rtsiIsModeUpdateTimeStep(&PMSM_to_BLDC_mod1_M->solverInfo)) {
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
      }

      PMSM_to_BLDC_mod1_PrevZCX.Dir_Sense_Trig_ZCE =
        PMSM_to_BLDC_mod1_DW.AlphaRelay_Mode;
      PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem = (int8_T)
        (PMSM_to_BLDC_mod1_B.Switch <= 0);
      if ((int32_T)PMSM_to_BLDC_mod1_ConstB.DataTypeConversion == 1) {
        PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem = 0;
      } else {
        PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem = 1;
      }
    }

    /* End of Outputs for SubSystem: '<S250>/Dir_Sense' */
    if (PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem == 0) {
      /* Outputs for IfAction SubSystem: '<S250>/Subsystem2' incorporates:
       *  ActionPort: '<S253>/Action Port'
       */
      /* UnaryMinus: '<S253>/Unary Minus' */
      rtb_Sum1_eq = -rtb_Add1[0];

      /* SignalConversion generated from: '<S253>/SigmaBeta' */
      rtb_Product1_o = rtb_Add1[1];

      /* End of Outputs for SubSystem: '<S250>/Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S250>/Subsystem3' incorporates:
       *  ActionPort: '<S254>/Action Port'
       */
      /* UnaryMinus: '<S254>/Unary Minus' */
      rtb_Product1_o = -rtb_Add1[1];

      /* SignalConversion generated from: '<S254>/SigmaAlpha' */
      rtb_Sum1_eq = rtb_Add1[0];

      /* End of Outputs for SubSystem: '<S250>/Subsystem3' */
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

      /* End of Outputs for SubSystem: '<S259>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S259>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S354>/Action Port'
       */
      /* Merge: '<S259>/Merge' incorporates:
       *  SignalConversion generated from: '<S354>/In1'
       */
      PMSM_to_BLDC_mod1_B.Merge[0] = rtb_Sum1_eq;
      PMSM_to_BLDC_mod1_B.Merge[1] = rtb_Product1_o;

      /* End of Outputs for SubSystem: '<S259>/If Action Subsystem1' */
    }

    /* Product: '<S256>/Product' */
    rtb_Sum1_eq = PMSM_to_BLDC_mod1_B.Merge[0] * PMSM_to_BLDC_mod1_B.Merge[0];

    /* Gain: '<S385>/Gain3' incorporates:
     *  Product: '<S256>/Product1'
     */
    rtb_Gain3_c = PMSM_to_BLDC_mod1_B.Merge[1] * PMSM_to_BLDC_mod1_B.Merge[1];

    /* Sum: '<S256>/Sum' */
    PMSM_to_BLDC_mod1_B.Sum = rtb_Sum1_eq + rtb_Gain3_c;

    /* RelationalOperator: '<S264>/Compare' incorporates:
     *  Constant: '<S264>/Constant'
     */
    PMSM_to_BLDC_mod1_B.Compare = (PMSM_to_BLDC_mod1_B.Sum > 0.0);
  }

  /* If: '<S256>/If' */
  rtPrevAction = PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_g;

  /* If: '<S222>/If' incorporates:
   *  If: '<S196>/If'
   *  If: '<S256>/If'
   *  If: '<S361>/If'
   *  SwitchCase: '<S258>/Switch Case'
   */
  tmp_1 = rtsiIsModeUpdateTimeStep(&PMSM_to_BLDC_mod1_M->solverInfo);

  /* If: '<S256>/If' */
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
    /* Outputs for IfAction SubSystem: '<S256>/Subsystem' incorporates:
     *  ActionPort: '<S266>/Action Port'
     */
    /* Sqrt: '<S266>/Sqrt' */
    rtb_Gain4_g = sqrt(PMSM_to_BLDC_mod1_B.Sum);

    /* Merge: '<S256>/Merge1' incorporates:
     *  Product: '<S266>/Divide'
     *  SignalConversion generated from: '<S266>/Out2'
     */
    rtb_Product1_o = 1.0 / rtb_Gain4_g * PMSM_to_BLDC_mod1_B.Merge[1];

    /* Merge: '<S256>/Merge' incorporates:
     *  Product: '<S266>/Divide1'
     *  SignalConversion generated from: '<S266>/Out1'
     */
    rtb_Gain4_g = PMSM_to_BLDC_mod1_B.Merge[0] / rtb_Gain4_g;

    /* End of Outputs for SubSystem: '<S256>/Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S256>/If Action Subsystem' incorporates:
     *  ActionPort: '<S265>/Action Port'
     */
    /* Merge: '<S256>/Merge' incorporates:
     *  DataTypeConversion: '<S265>/Data Type Conversion'
     *  SignalConversion generated from: '<S265>/Out1'
     */
    rtb_Gain4_g = PMSM_to_BLDC_mod1_B.Merge[0];

    /* Merge: '<S256>/Merge1' incorporates:
     *  DataTypeConversion: '<S265>/Data Type Conversion1'
     *  SignalConversion generated from: '<S265>/Out2'
     */
    rtb_Product1_o = PMSM_to_BLDC_mod1_B.Merge[1];

    /* End of Outputs for SubSystem: '<S256>/If Action Subsystem' */
  }

  if (tmp_0) {
    /* SwitchCase: '<S258>/Switch Case' incorporates:
     *  Delay: '<S349>/Delay'
     */
    if (tmp_1) {
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
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av = rtb_Product1_o *
        0.95650500031643548 + 0.043494999683564517 *
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av;

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
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d = rtb_Gain4_g * 0.95650500031643548 +
        0.043494999683564517 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d;

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
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i = (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d
        + PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_o) * 2.4945142765920684E-5 +
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
      rtb_Delay2_g = 1.0 / (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_f * rtb_Gain4_g -
                            PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i * rtb_Product1_o);

      /* Switch: '<S322>/Switch1' incorporates:
       *  Abs: '<S322>/Abs'
       */
      if (fabs(rtb_Delay2_g) > 87964.5943005142) {
        /* Merge: '<S258>/Merge' incorporates:
         *  Constant: '<S322>/Constant'
         */
        rtb_Delay2_g = 0.0;
      }

      /* End of Switch: '<S322>/Switch1' */

      /* Update for Delay: '<S339>/Delay' */
      PMSM_to_BLDC_mod1_DW.icLoad_bd = false;

      /* Update for Delay: '<S336>/Delay1' */
      PMSM_to_BLDC_mod1_DW.Delay1_DSTATE = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av;

      /* Update for Delay: '<S342>/Delay' */
      PMSM_to_BLDC_mod1_DW.icLoad_k = false;

      /* Update for Delay: '<S335>/Delay1' */
      PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_o = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d;

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
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aa = rtb_Product1_o *
        0.95650500031643548 + 0.043494999683564517 *
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aa;

      /* Product: '<S344>/Product' incorporates:
       *  Constant: '<S319>/OD1Cnst'
       */
      rtb_Sum1_eq = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aa * 2.1991148575128554E+6;

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
      PMSM_to_BLDC_mod1_DW.Delay3_DSTATE = ((PMSM_to_BLDC_mod1_DW.Delay3_DSTATE
        + rtb_Sum1_eq) - PMSM_to_BLDC_mod1_DW.Delay2_DSTATE) *
        0.0090126024492556654;

      /* Delay: '<S343>/Delay2' */
      if (PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE_p == POS_ZCSIG) {
        PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_h = 0.0;
      }

      PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE_p = 0U;
      rtb_Delay2_g = PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_h;

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
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_l = rtb_Gain4_g * 0.95650500031643548 +
        0.043494999683564517 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_l;

      /* Product: '<S343>/Product' incorporates:
       *  Constant: '<S319>/OD1Cnst'
       *  Delay: '<S343>/Delay2'
       */
      PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_h = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_l
        * 2.1991148575128554E+6;

      /* Product: '<S343>/Product1' incorporates:
       *  Constant: '<S319>/OD2Cnst'
       *  Delay: '<S343>/Delay2'
       *  Delay: '<S343>/Delay3'
       *  Sum: '<S343>/Sum1'
       */
      PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_p =
        ((PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_p +
          PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_h) - rtb_Delay2_g) *
        0.0090126024492556654;

      /* Merge: '<S258>/Merge' incorporates:
       *  Delay: '<S343>/Delay3'
       *  Delay: '<S344>/Delay3'
       *  Product: '<S325>/Product'
       *  Product: '<S325>/Product1'
       *  Sum: '<S325>/Sum'
       */
      rtb_Delay2_g = PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_p * rtb_Product1_o -
        PMSM_to_BLDC_mod1_DW.Delay3_DSTATE * rtb_Gain4_g;

      /* Update for Delay: '<S349>/Delay' */
      PMSM_to_BLDC_mod1_DW.icLoad_b1 = false;

      /* Update for Delay: '<S344>/Delay2' */
      PMSM_to_BLDC_mod1_DW.Delay2_DSTATE = rtb_Sum1_eq;

      /* Update for Delay: '<S352>/Delay' */
      PMSM_to_BLDC_mod1_DW.icLoad_c = false;

      /* End of Outputs for SubSystem: '<S258>/OptimizedDifferentiationMethod' */
    }

    /* Gain: '<S385>/Gain3' incorporates:
     *  Constant: '<S258>/SpdFilterCoeff'
     *  Constant: '<S320>/One'
     *  Sum: '<S320>/Sum'
     */
    rtb_Gain3_c = 0.99530971347415453;

    /* Switch: '<S320>/Switch1' */
    rtb_Product_j_idx_1 = rtb_Gain3_c;

    /* Delay: '<S332>/Delay' incorporates:
     *  Constant: '<S320>/IC'
     */
    if (PMSM_to_BLDC_mod1_DW.icLoad_f) {
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_a = 0.0;
    }

    /* Gain: '<S385>/Gain3' incorporates:
     *  Delay: '<S332>/Delay'
     *  Product: '<S332>/Product1'
     */
    rtb_Gain3_c = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_a;
    rtb_Gain3_c *= rtb_Product_j_idx_1;

    /* Sum: '<S332>/Add1' incorporates:
     *  Product: '<S332>/Product'
     *  Switch: '<S332>/Switch'
     */
    rtb_Add1_e = rtb_Delay2_g * 0.0046902865258454489 + rtb_Gain3_c;

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
    if (tmp_1) {
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
      rtb_Saturation_l = floorf((real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj);
      if (rtIsNaNF(rtb_Saturation_l) || rtIsInfF(rtb_Saturation_l)) {
        rtb_Saturation_l = 0.0F;
      } else {
        rtb_Saturation_l = fmodf(rtb_Saturation_l, 65536.0F);
      }

      /* Sum: '<S364>/Sum' incorporates:
       *  DataTypeConversion: '<S356>/Data Type Conversion3'
       *  DataTypeConversion: '<S364>/Convert_back'
       *  DataTypeConversion: '<S364>/Convert_uint16'
       *  Delay: '<S356>/Delay'
       */
      rtb_indexing = (real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj - (real32_T)
        (rtb_Saturation_l < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
         -rtb_Saturation_l : (int32_T)(int16_T)(uint16_T)rtb_Saturation_l);

      /* End of Outputs for SubSystem: '<S361>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S361>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S365>/Action Port'
       */
      /* DataTypeConversion: '<S365>/Convert_uint16' incorporates:
       *  DataTypeConversion: '<S356>/Data Type Conversion3'
       *  Delay: '<S356>/Delay'
       */
      rtb_Saturation_l = truncf((real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj);
      if (rtIsNaNF(rtb_Saturation_l) || rtIsInfF(rtb_Saturation_l)) {
        rtb_Saturation_l = 0.0F;
      } else {
        rtb_Saturation_l = fmodf(rtb_Saturation_l, 65536.0F);
      }

      /* Sum: '<S365>/Sum' incorporates:
       *  DataTypeConversion: '<S356>/Data Type Conversion3'
       *  DataTypeConversion: '<S365>/Convert_back'
       *  DataTypeConversion: '<S365>/Convert_uint16'
       *  Delay: '<S356>/Delay'
       */
      rtb_indexing = (real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj - (real32_T)
        (rtb_Saturation_l < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
         -rtb_Saturation_l : (int32_T)(int16_T)(uint16_T)rtb_Saturation_l);

      /* End of Outputs for SubSystem: '<S361>/If Action Subsystem1' */
    }

    /* Gain: '<S359>/indexing' */
    rtb_indexing *= 800.0F;

    /* DataTypeConversion: '<S359>/Get_Integer' */
    rtb_Saturation_l = truncf(rtb_indexing);
    if (rtIsNaNF(rtb_Saturation_l) || rtIsInfF(rtb_Saturation_l)) {
      rtb_Saturation_l = 0.0F;
    } else {
      rtb_Saturation_l = fmodf(rtb_Saturation_l, 65536.0F);
    }

    status = (uint16_T)(rtb_Saturation_l < 0.0F ? (int32_T)(uint16_T)-(int16_T)
                        (uint16_T)-rtb_Saturation_l : (int32_T)(uint16_T)
                        rtb_Saturation_l);

    /* End of DataTypeConversion: '<S359>/Get_Integer' */

    /* Sum: '<S359>/Sum2' incorporates:
     *  DataTypeConversion: '<S359>/Data Type Conversion1'
     */
    rtb_Saturation_l = rtb_indexing - (real32_T)status;

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
    rtb_Sum1_eq = ((PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[(int32_T)
                    (status + 201U)] -
                    PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[(int32_T)
                    (status + 200U)]) * rtb_Saturation_l +
                   PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[(int32_T)
                   (status + 200U)]) * rtb_Gain4_g -
      ((PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[(int32_T)(status + 1U)]
        - PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[status]) *
       rtb_Saturation_l +
       PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[status]) *
      rtb_Product1_o;

    /* DiscreteIntegrator: '<S301>/Integrator' */
    if (PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState != 0) {
      PMSM_to_BLDC_mod1_DW.Integrator_DSTATE = 0.0;
    }

    /* DiscreteIntegrator: '<S301>/Integrator' incorporates:
     *  Gain: '<S298>/Integral Gain'
     */
    PMSM_to_BLDC_mod1_B.Integrator = 5.0 * rtb_Sum1_eq +
      PMSM_to_BLDC_mod1_DW.Integrator_DSTATE;

    /* Sum: '<S251>/Sum1' incorporates:
     *  Gain: '<S306>/Proportional Gain'
     *  Sum: '<S310>/Sum'
     */
    rtb_Sum1_eq = (250.0 * rtb_Sum1_eq + PMSM_to_BLDC_mod1_B.Integrator) +
      rtb_Add1_e;

    /* Gain: '<S385>/Gain3' incorporates:
     *  Gain: '<S356>/Gain'
     *  Product: '<S357>/Product'
     */
    rtb_Gain3_c = 7.9577471545947669E-6 * rtb_Sum1_eq;

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

    /* Gain: '<S385>/Gain3' incorporates:
     *  Constant: '<S71>/Constant'
     *  DataTypeConversion: '<S64>/Data Type Conversion'
     *  Delay: '<S356>/Delay'
     *  Gain: '<S251>/PositionGain'
     *  Math: '<S71>/Mod'
     */
    rtb_Gain3_c = (real32_T)(6.2831853071795862 *
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj);
    rtb_Gain3_c = rt_modd_snf(rtb_Gain3_c, 6.282);

    /* Gain: '<S222>/convert_pu' */
    rtb_Delay2_g = 0.15915494309189535 * rtb_Gain3_c;

    /* If: '<S222>/If' incorporates:
     *  Constant: '<S224>/Constant'
     *  RelationalOperator: '<S224>/Compare'
     */
    if (tmp_1) {
      PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_c = (int8_T)!(rtb_Delay2_g < 0.0);
    }

    if (PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_c == 0) {
      /* Outputs for IfAction SubSystem: '<S222>/If Action Subsystem' incorporates:
       *  ActionPort: '<S225>/Action Port'
       */
      rtb_Add_km = PMSM_to_BLDC__IfActionSubsystem(rtb_Delay2_g);

      /* End of Outputs for SubSystem: '<S222>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S222>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S226>/Action Port'
       */
      rtb_Add_km = PMSM_to_BLDC_IfActionSubsystem1(rtb_Delay2_g);

      /* End of Outputs for SubSystem: '<S222>/If Action Subsystem1' */
    }

    /* Sum: '<S61>/Add' incorporates:
     *  Gain: '<S220>/indexing'
     */
    rtb_Add_km *= 800.0;

    /* DataTypeConversion: '<S220>/Get_Integer' */
    rtb_Product_j_idx_1 = trunc(rtb_Add_km);
    if (rtIsNaN(rtb_Product_j_idx_1) || rtIsInf(rtb_Product_j_idx_1)) {
      rtb_Product_j_idx_1 = 0.0;
    } else {
      rtb_Product_j_idx_1 = fmod(rtb_Product_j_idx_1, 65536.0);
    }

    status = (uint16_T)(rtb_Product_j_idx_1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
                        (uint16_T)-rtb_Product_j_idx_1 : (int32_T)(uint16_T)
                        rtb_Product_j_idx_1);

    /* End of DataTypeConversion: '<S220>/Get_Integer' */

    /* Sum: '<S220>/Sum2' incorporates:
     *  DataTypeConversion: '<S220>/Data Type Conversion1'
     */
    rtb_Gain4_g = rtb_Add_km - (real_T)status;

    /* Sum: '<S221>/Sum4' incorporates:
     *  Constant: '<S220>/offset'
     *  Constant: '<S220>/sine_table_values'
     *  Product: '<S221>/Product'
     *  Selector: '<S220>/Lookup'
     *  Sum: '<S220>/Sum'
     *  Sum: '<S221>/Sum3'
     */
    rtb_Product1_o = (PMSM_to_BLDC_mod1_ConstP.pooled16[(int32_T)(status + 1U)]
                      - PMSM_to_BLDC_mod1_ConstP.pooled16[status]) * rtb_Gain4_g
      + PMSM_to_BLDC_mod1_ConstP.pooled16[status];

    /* Sum: '<S61>/Add' incorporates:
     *  Constant: '<S220>/offset'
     *  Constant: '<S220>/sine_table_values'
     *  Product: '<S221>/Product1'
     *  Selector: '<S220>/Lookup'
     *  Sum: '<S220>/Sum'
     *  Sum: '<S221>/Sum5'
     */
    rtb_Add_km = PMSM_to_BLDC_mod1_ConstP.pooled16[(int32_T)(status + 201U)] -
      PMSM_to_BLDC_mod1_ConstP.pooled16[(int32_T)(status + 200U)];
    rtb_Add_km *= rtb_Gain4_g;

    /* Sum: '<S221>/Sum6' incorporates:
     *  Constant: '<S220>/offset'
     *  Constant: '<S220>/sine_table_values'
     *  Selector: '<S220>/Lookup'
     *  Sum: '<S220>/Sum'
     *  Sum: '<S221>/Sum5'
     */
    rtb_Gain4_g = PMSM_to_BLDC_mod1_ConstP.pooled16[(int32_T)(status + 200U)] +
      rtb_Add_km;

    /* Outputs for Atomic SubSystem: '<S218>/Two inputs CRL' */
    /* Sum: '<S61>/Add' incorporates:
     *  Product: '<S228>/acos'
     *  Product: '<S228>/bsin'
     *  Sum: '<S228>/sum_Ds'
     */
    rtb_Add_km = rtb_uabc3 * rtb_Gain4_g + rtb_one_by_sqrt3_ * rtb_Product1_o;

    /* AlgorithmDescriptorDelegate generated from: '<S228>/a16' incorporates:
     *  Switch: '<S229>/Switch'
     */
    rtb_Delay2_g = rtb_Add_km;

    /* AlgorithmDescriptorDelegate generated from: '<S228>/a16' incorporates:
     *  Product: '<S228>/asin'
     *  Product: '<S228>/bcos'
     *  Sum: '<S228>/sum_Qs'
     */
    PMSM_to_BLDC_mod1_B.algDD_o2 = rtb_one_by_sqrt3_ * rtb_Gain4_g - rtb_uabc3 *
      rtb_Product1_o;

    /* End of Outputs for SubSystem: '<S218>/Two inputs CRL' */

    /* Saturate: '<S61>/Saturation' incorporates:
     *  Delay: '<S56>/Delay1'
     */
    if (PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx > 600.0F) {
      rtb_Saturation_l = 600.0F;
    } else if (PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx < -600.0F) {
      rtb_Saturation_l = -600.0F;
    } else {
      rtb_Saturation_l = PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx;
    }

    /* Sum: '<S61>/Add' incorporates:
     *  Constant: '<S56>/Constant'
     *  Saturate: '<S61>/Saturation'
     */
    rtb_Add_km = 600.0 - rtb_Saturation_l;

    /* Gain: '<S442>/Proportional Gain' */
    PMSM_to_BLDC_mod1_B.ProportionalGain = 0.31663865546218484 * rtb_Add_km;
  }

  /* Sum: '<S77>/Sum' incorporates:
   *  Integrator: '<S437>/Integrator'
   *  Sum: '<S446>/Sum'
   */
  rtb_uabc3 = PMSM_to_BLDC_mod1_B.algDD_o2 -
    (PMSM_to_BLDC_mod1_B.ProportionalGain +
     PMSM_to_BLDC_mod1_X.Integrator_CSTATE);
  if (tmp_0) {
    /* DiscreteIntegrator: '<S116>/Integrator' */
    PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n =
      PMSM_to_BLDC_mod1_ConstB.Constant3;

    /* Sum: '<S125>/Sum' incorporates:
     *  Constant: '<S77>/Constant'
     *  DiscreteIntegrator: '<S116>/Integrator'
     *  Product: '<S121>/PProd Out'
     */
    rtb_Gain4_g = rtb_uabc3 * 22.608 + PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n;

    /* DeadZone: '<S108>/DeadZone' */
    if (rtb_Gain4_g > 1.0) {
      /* DiscreteIntegrator: '<S171>/Integrator' */
      rtb_Switch = rtb_Gain4_g - 1.0;
    } else if (rtb_Gain4_g >= -1.0) {
      /* DiscreteIntegrator: '<S171>/Integrator' */
      rtb_Switch = 0.0;
    } else {
      /* DiscreteIntegrator: '<S171>/Integrator' */
      rtb_Switch = rtb_Gain4_g - -1.0;
    }

    /* End of DeadZone: '<S108>/DeadZone' */

    /* RelationalOperator: '<S106>/Relational Operator' incorporates:
     *  Constant: '<S106>/Clamping_zero'
     */
    rtb_RelationalOperator = (rtb_Switch != 0.0);

    /* RelationalOperator: '<S106>/fix for DT propagation issue' incorporates:
     *  Constant: '<S106>/Clamping_zero'
     */
    rtb_fixforDTpropagationissue = (rtb_Switch > 0.0);

    /* DiscreteIntegrator: '<S171>/Integrator' incorporates:
     *  Constant: '<S77>/Constant1'
     *  Product: '<S113>/IProd Out'
     */
    rtb_Switch = rtb_uabc3 * 0.23235999999999998;

    /* Switch: '<S106>/Switch1' incorporates:
     *  Constant: '<S106>/Constant'
     *  Constant: '<S106>/Constant2'
     */
    if (rtb_fixforDTpropagationissue) {
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
    if (rtb_Switch > 0.0) {
      rtAction = 1;
    } else {
      rtAction = -1;
    }

    /* Switch: '<S106>/Switch' incorporates:
     *  Logic: '<S106>/AND3'
     *  RelationalOperator: '<S106>/Equal1'
     *  Switch: '<S106>/Switch1'
     *  Switch: '<S106>/Switch2'
     */
    if (rtb_RelationalOperator && (rtPrevAction == rtAction)) {
      /* DiscreteIntegrator: '<S171>/Integrator' incorporates:
       *  Constant: '<S106>/Constant1'
       *  Switch: '<S106>/Switch'
       */
      rtb_Switch = 0.0;
    }

    /* End of Switch: '<S106>/Switch' */

    /* Saturate: '<S123>/Saturation' */
    if (rtb_Gain4_g > 1.0) {
      rtb_Saturation = 1.0;
    } else if (rtb_Gain4_g < -1.0) {
      rtb_Saturation = -1.0;
    } else {
      rtb_Saturation = rtb_Gain4_g;
    }

    /* End of Saturate: '<S123>/Saturation' */

    /* DiscreteIntegrator: '<S171>/Integrator' */
    PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b =
      PMSM_to_BLDC_mod1_ConstB.Constant3_n;

    /* Sum: '<S180>/Sum' incorporates:
     *  Constant: '<S78>/Constant'
     *  DiscreteIntegrator: '<S171>/Integrator'
     *  Product: '<S176>/PProd Out'
     *  Sum: '<S78>/Sum'
     */
    rtb_Product1_o = rtb_Delay2_g * 22.608 +
      PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b;

    /* DeadZone: '<S163>/DeadZone' */
    if (rtb_Product1_o > 1.0) {
      rtb_Min = rtb_Product1_o - 1.0;
    } else if (rtb_Product1_o >= -1.0) {
      rtb_Min = 0.0;
    } else {
      rtb_Min = rtb_Product1_o - -1.0;
    }

    /* End of DeadZone: '<S163>/DeadZone' */

    /* Product: '<S168>/IProd Out' incorporates:
     *  Constant: '<S78>/Constant1'
     *  Sum: '<S78>/Sum'
     */
    rtb_Gain4_g = rtb_Delay2_g * 0.23235999999999998;

    /* Switch: '<S161>/Switch1' incorporates:
     *  Constant: '<S161>/Clamping_zero'
     *  Constant: '<S161>/Constant'
     *  Constant: '<S161>/Constant2'
     *  RelationalOperator: '<S161>/fix for DT propagation issue'
     */
    if (rtb_Min > 0.0) {
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
    if (rtb_Gain4_g > 0.0) {
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
    if ((rtb_Min != 0.0) && (rtPrevAction == rtAction)) {
      /* Switch: '<S161>/Switch' incorporates:
       *  Constant: '<S161>/Constant1'
       */
      rtb_Switch_e = 0.0;
    } else {
      /* Switch: '<S161>/Switch' */
      rtb_Switch_e = rtb_Gain4_g;
    }

    /* End of Switch: '<S161>/Switch' */

    /* Saturate: '<S178>/Saturation' */
    if (rtb_Product1_o > 1.0) {
      rtb_Product1_o = 1.0;
    } else if (rtb_Product1_o < -1.0) {
      rtb_Product1_o = -1.0;
    }

    /* End of Saturate: '<S178>/Saturation' */

    /* Gain: '<S196>/convert_pu' */
    rtb_Min = 0.15915494309189535 * rtb_Gain3_c;

    /* If: '<S196>/If' incorporates:
     *  Constant: '<S198>/Constant'
     *  RelationalOperator: '<S198>/Compare'
     */
    if (tmp_1) {
      PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_m = (int8_T)!(rtb_Min < 0.0);
    }

    if (PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_m == 0) {
      /* Outputs for IfAction SubSystem: '<S196>/If Action Subsystem' incorporates:
       *  ActionPort: '<S199>/Action Port'
       */
      rtb_Gain3_c = PMSM_to_BLDC__IfActionSubsystem(rtb_Min);

      /* End of Outputs for SubSystem: '<S196>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S196>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S200>/Action Port'
       */
      rtb_Gain3_c = PMSM_to_BLDC_IfActionSubsystem1(rtb_Min);

      /* End of Outputs for SubSystem: '<S196>/If Action Subsystem1' */
    }

    /* Gain: '<S385>/Gain3' incorporates:
     *  Gain: '<S194>/indexing'
     */
    rtb_Gain3_c *= 800.0;

    /* DataTypeConversion: '<S194>/Get_Integer' */
    rtb_Product_j_idx_1 = trunc(rtb_Gain3_c);
    if (rtIsNaN(rtb_Product_j_idx_1) || rtIsInf(rtb_Product_j_idx_1)) {
      rtb_Product_j_idx_1 = 0.0;
    } else {
      rtb_Product_j_idx_1 = fmod(rtb_Product_j_idx_1, 65536.0);
    }

    status = (uint16_T)(rtb_Product_j_idx_1 < 0.0 ? (int32_T)(uint16_T)-(int16_T)
                        (uint16_T)-rtb_Product_j_idx_1 : (int32_T)(uint16_T)
                        rtb_Product_j_idx_1);

    /* End of DataTypeConversion: '<S194>/Get_Integer' */

    /* Sum: '<S194>/Sum2' incorporates:
     *  DataTypeConversion: '<S194>/Data Type Conversion1'
     */
    rtb_Gain4_g = rtb_Gain3_c - (real_T)status;

    /* Gain: '<S385>/Gain3' incorporates:
     *  Constant: '<S194>/offset'
     *  Constant: '<S194>/sine_table_values'
     *  Product: '<S195>/Product1'
     *  Selector: '<S194>/Lookup'
     *  Sum: '<S194>/Sum'
     *  Sum: '<S195>/Sum5'
     */
    rtb_Gain3_c = PMSM_to_BLDC_mod1_ConstP.pooled16[(int32_T)(status + 201U)] -
      PMSM_to_BLDC_mod1_ConstP.pooled16[(int32_T)(status + 200U)];
    rtb_Gain3_c *= rtb_Gain4_g;

    /* Sum: '<S195>/Sum4' incorporates:
     *  Constant: '<S194>/offset'
     *  Constant: '<S194>/sine_table_values'
     *  Product: '<S195>/Product'
     *  Selector: '<S194>/Lookup'
     *  Sum: '<S194>/Sum'
     *  Sum: '<S195>/Sum3'
     */
    rtb_Min = (PMSM_to_BLDC_mod1_ConstP.pooled16[(int32_T)(status + 1U)] -
               PMSM_to_BLDC_mod1_ConstP.pooled16[status]) * rtb_Gain4_g +
      PMSM_to_BLDC_mod1_ConstP.pooled16[status];

    /* Sum: '<S195>/Sum6' incorporates:
     *  Constant: '<S194>/offset'
     *  Constant: '<S194>/sine_table_values'
     *  Selector: '<S194>/Lookup'
     *  Sum: '<S194>/Sum'
     *  Sum: '<S195>/Sum5'
     */
    rtb_Sum6_g = PMSM_to_BLDC_mod1_ConstP.pooled16[(int32_T)(status + 200U)] +
      rtb_Gain3_c;

    /* Outputs for Atomic SubSystem: '<S193>/Two inputs CRL' */
    /* Gain: '<S385>/Gain3' incorporates:
     *  Product: '<S202>/dsin'
     *  Product: '<S202>/qcos'
     *  Sum: '<S202>/sum_beta'
     */
    rtb_Gain3_c = rtb_Saturation * rtb_Sum6_g + rtb_Product1_o * rtb_Min;

    /* Switch: '<S203>/Switch' incorporates:
     *  Product: '<S202>/dcos'
     *  Product: '<S202>/qsin'
     *  Sum: '<S202>/sum_alpha'
     */
    rtb_Min = rtb_Product1_o * rtb_Sum6_g - rtb_Saturation * rtb_Min;
    rtb_Product_j_idx_1 = rtb_Gain3_c;

    /* SignalConversion generated from: '<S59>/Delay' incorporates:
     *  AlgorithmDescriptorDelegate generated from: '<S202>/a16'
     *  Switch: '<S203>/Switch'
     */
    rtb_TmpSignalConversionAtDelayI[1] = rtb_Gain3_c;

    /* Gain: '<S385>/Gain3' incorporates:
     *  AlgorithmDescriptorDelegate generated from: '<S202>/a16'
     *  Gain: '<S213>/one_by_two'
     */
    rtb_Gain3_c = 0.5 * rtb_Min;

    /* Gain: '<S213>/sqrt3_by_two' incorporates:
     *  AlgorithmDescriptorDelegate generated from: '<S202>/a16'
     */
    rtb_Gain4_g = 0.8660254037844386 * rtb_Product_j_idx_1;

    /* End of Outputs for SubSystem: '<S193>/Two inputs CRL' */

    /* Sum: '<S213>/add_b' */
    rtb_Product1_o = rtb_Gain4_g - rtb_Gain3_c;

    /* Gain: '<S385>/Gain3' incorporates:
     *  Sum: '<S213>/add_c'
     */
    rtb_Gain3_c = (0.0 - rtb_Gain3_c) - rtb_Gain4_g;

    /* Outputs for Atomic SubSystem: '<S193>/Two inputs CRL' */
    /* Gain: '<S207>/one_by_two' incorporates:
     *  AlgorithmDescriptorDelegate generated from: '<S202>/a16'
     *  MinMax: '<S207>/Max'
     *  MinMax: '<S207>/Min'
     *  Sum: '<S207>/Add'
     */
    rtb_Gain4_g = (fmax(fmax(rtb_Min, rtb_Product1_o), rtb_Gain3_c) + fmin(fmin
      (rtb_Min, rtb_Product1_o), rtb_Gain3_c)) * -0.5;

    /* End of Outputs for SubSystem: '<S193>/Two inputs CRL' */

    /* Gain: '<S385>/Gain3' incorporates:
     *  Sum: '<S206>/Add2'
     */
    rtb_Gain3_c += rtb_Gain4_g;

    /* Gain: '<S206>/Gain' */
    rtb_Saturation = 1.1547005383792517 * rtb_Gain3_c;

    /* Gain: '<S385>/Gain3' incorporates:
     *  Constant: '<S72>/Constant1'
     *  Math: '<S72>/Mod1'
     */
    rtb_Gain3_c = rt_modd_snf(rtb_Delay2_g, 6.282);

    /* Product: '<S263>/Product' */
    rtb_Sum1_eq *= 0.0046902865258454489;

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
      rtb_Sum1_eq;

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

    /* Outputs for Atomic SubSystem: '<S193>/Two inputs CRL' */
    /* SignalConversion generated from: '<S59>/Delay' incorporates:
     *  AlgorithmDescriptorDelegate generated from: '<S202>/a16'
     *  Constant: '<S72>/Constant1'
     *  Math: '<S72>/Mod2'
     */
    rtb_TmpSignalConversionAtDelayI[0] = rtb_Min;

    /* End of Outputs for SubSystem: '<S193>/Two inputs CRL' */
    rtb_TmpSignalConversionAtDelayI[2] = rtb_Gain3_c;
    rtb_TmpSignalConversionAtDelayI[3] = rt_modd_snf
      (PMSM_to_BLDC_mod1_B.algDD_o2, 6.282);

    /* Outputs for Atomic SubSystem: '<S193>/Two inputs CRL' */
    /* Saturate: '<S372>/Saturation2' incorporates:
     *  AlgorithmDescriptorDelegate generated from: '<S202>/a16'
     *  Constant: '<S65>/Constant'
     *  Gain: '<S206>/Gain'
     *  Gain: '<S65>/Gain'
     *  Sum: '<S206>/Add1'
     *  Sum: '<S206>/Add3'
     *  Sum: '<S65>/Add'
     */
    rtb_Min = ((rtb_Min + rtb_Gain4_g) * 1.1547005383792517 + 1.45) *
      0.33333333333333331;

    /* End of Outputs for SubSystem: '<S193>/Two inputs CRL' */
    if (rtb_Min > 1.0) {
      rtb_Min = 1.0;
    } else if (rtb_Min < 0.0) {
      rtb_Min = 0.0;
    }

    rtb_Sum6_g = ((rtb_Product1_o + rtb_Gain4_g) * 1.1547005383792517 + 1.45) *
      0.33333333333333331;
    if (rtb_Sum6_g > 1.0) {
      rtb_Sum6_g = 1.0;
    } else if (rtb_Sum6_g < 0.0) {
      rtb_Sum6_g = 0.0;
    }

    rtb_Saturation = (rtb_Saturation + 1.45) * 0.33333333333333331;
    if (rtb_Saturation > 1.0) {
      rtb_Saturation = 1.0;
    } else if (rtb_Saturation < 0.0) {
      rtb_Saturation = 0.0;
    }

    /* End of Saturate: '<S372>/Saturation2' */

    /* Gain: '<S372>/Gain' incorporates:
     *  Sum: '<S372>/Sum'
     */
    rtb_Sum1_eq = ((rtb_Sum6_g + rtb_Saturation) + rtb_Min) *
      0.33333333333333331;

    /* Gain: '<S385>/Gain3' incorporates:
     *  Sum: '<S372>/Sum1'
     */
    rtb_Gain3_c = rtb_Min - rtb_Sum1_eq;

    /* Product: '<S372>/Product' incorporates:
     *  Sum: '<S372>/Sum2'
     *  Sum: '<S372>/Sum3'
     */
    rtb_Min = rtb_Gain3_c * PMSM_to_BLDC_mod1_ConstB.Switch;
    rtb_Sum6_g = (rtb_Sum6_g - rtb_Sum1_eq) * PMSM_to_BLDC_mod1_ConstB.Switch;
    rtb_Saturation = (rtb_Saturation - rtb_Sum1_eq) *
      PMSM_to_BLDC_mod1_ConstB.Switch;
  }

  /* Integrator: '<S392>/Integrator' */
  /* Limited  Integrator  */
  if (PMSM_to_BLDC_mod1_DW.Integrator_DWORK1) {
    PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d =
      PMSM_to_BLDC_mod1_ConstB.IndexVector;
  }

  if (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d >= 1.0E+7) {
    PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d = 1.0E+7;
  } else if (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d <= -1.0E+7) {
    PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d = -1.0E+7;
  }

  /* Gain: '<S377>/Gain4' incorporates:
   *  Integrator: '<S377>/Int1'
   */
  rtb_uabc3 = 7.0 * PMSM_to_BLDC_mod1_X.Int1_CSTATE;

  /* Trigonometry: '<S379>/sine_cosine' */
  rtb_Delay2_g = sin(rtb_uabc3);
  rtb_uabc3 = cos(rtb_uabc3);

  /* Integrator: '<S393>/Integrator' */
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

  /* Sum: '<S387>/Add1' incorporates:
   *  Integrator: '<S392>/Integrator'
   *  Integrator: '<S393>/Integrator'
   *  Product: '<S387>/Product2'
   *  Product: '<S387>/Product3'
   */
  rtb_one_by_sqrt3_ = PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d * rtb_uabc3 -
    PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l * rtb_Delay2_g;

  /* SignalConversion generated from: '<S376>/Vector Concatenate' incorporates:
   *  Concatenate: '<S376>/Vector Concatenate'
   */
  PMSM_to_BLDC_mod1_B.VectorConcatenate[0] = rtb_one_by_sqrt3_;
  if (tmp_0) {
    /* Gain: '<S385>/Gain3' incorporates:
     *  Gain: '<S385>/Gain1'
     */
    rtb_Gain3_c = -0.33333333333333331 * rtb_Sum6_g;

    /* Sum: '<S385>/Add' incorporates:
     *  Gain: '<S385>/Gain'
     *  Gain: '<S385>/Gain4'
     */
    PMSM_to_BLDC_mod1_B.Add = (0.66666666666666663 * rtb_Min + rtb_Gain3_c) +
      -0.33333333333333331 * rtb_Saturation;

    /* Gain: '<S385>/Gain3' */
    rtb_Gain3_c = -0.57735026918962573 * rtb_Saturation;

    /* Sum: '<S385>/Add1' incorporates:
     *  Gain: '<S385>/Gain2'
     */
    PMSM_to_BLDC_mod1_B.Add1 = 0.57735026918962573 * rtb_Sum6_g + rtb_Gain3_c;

    /* Gain: '<S434>/Integral Gain' */
    PMSM_to_BLDC_mod1_B.IntegralGain = 11.047170868347338 * rtb_Add_km;
  }

  /* Gain: '<S386>/Gain1' */
  rtb_Saturation = -0.5 * rtb_one_by_sqrt3_;

  /* Sum: '<S387>/Add' incorporates:
   *  Integrator: '<S392>/Integrator'
   *  Integrator: '<S393>/Integrator'
   *  Product: '<S387>/Product'
   *  Product: '<S387>/Product1'
   */
  rtb_one_by_sqrt3_ = PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d * rtb_Delay2_g +
    PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l * rtb_uabc3;

  /* Sum: '<S386>/Subtract1' incorporates:
   *  Concatenate: '<S376>/Vector Concatenate'
   *  Gain: '<S386>/Gain2'
   *  Gain: '<S386>/Gain3'
   */
  PMSM_to_BLDC_mod1_B.VectorConcatenate[1] = 0.8660254037844386 *
    rtb_one_by_sqrt3_ + rtb_Saturation;

  /* Sum: '<S386>/Subtract2' incorporates:
   *  Concatenate: '<S376>/Vector Concatenate'
   *  Gain: '<S386>/Gain4'
   */
  PMSM_to_BLDC_mod1_B.VectorConcatenate[2] = -0.8660254037844386 *
    rtb_one_by_sqrt3_ + rtb_Saturation;

  /* Sum: '<S392>/Add' incorporates:
   *  Constant: '<S396>/Constant'
   *  Integrator: '<S392>/Integrator'
   *  Integrator: '<S393>/Integrator'
   *  Product: '<S390>/Product2'
   *  Product: '<S390>/Product3'
   *  Product: '<S392>/Product'
   *  Product: '<S394>/Product'
   *  Product: '<S395>/Product'
   *  Product: '<S396>/Product'
   *  Sum: '<S390>/Add1'
   */
  PMSM_to_BLDC_mod1_B.Add_h = ((PMSM_to_BLDC_mod1_B.Add * rtb_uabc3 +
    PMSM_to_BLDC_mod1_B.Add1 * rtb_Delay2_g) /
    PMSM_to_BLDC_mod1_ConstB.IndexVector_b + PMSM_to_BLDC_mod1_ConstB.Gain *
    PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l *
    PMSM_to_BLDC_mod1_ConstB.IndexVector_a /
    PMSM_to_BLDC_mod1_ConstB.IndexVector1) -
    PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d * 0.037 /
    PMSM_to_BLDC_mod1_ConstB.IndexVector_j;

  /* Sum: '<S393>/Add' incorporates:
   *  Constant: '<S400>/Constant'
   *  Integrator: '<S392>/Integrator'
   *  Integrator: '<S393>/Integrator'
   *  Product: '<S390>/Product'
   *  Product: '<S390>/Product1'
   *  Product: '<S393>/Product'
   *  Product: '<S397>/Product'
   *  Product: '<S398>/Product'
   *  Product: '<S400>/Product'
   *  Sum: '<S390>/Add'
   */
  PMSM_to_BLDC_mod1_B.Add_d = (((PMSM_to_BLDC_mod1_B.Add1 * rtb_uabc3 -
    PMSM_to_BLDC_mod1_B.Add * rtb_Delay2_g) /
    PMSM_to_BLDC_mod1_ConstB.IndexVector_k -
    PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d * PMSM_to_BLDC_mod1_ConstB.Gain *
    PMSM_to_BLDC_mod1_ConstB.IndexVector_m /
    PMSM_to_BLDC_mod1_ConstB.IndexVector1_g) - PMSM_to_BLDC_mod1_ConstB.Product)
    - PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l * 0.037 /
    PMSM_to_BLDC_mod1_ConstB.IndexVector_d3;

  /* End of Outputs for SubSystem: '<Root>/Timer' */
  if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
      PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[4] == 0) {
    /* MATLABSystem: '<S459>/Analog to Digital Converter' */
    if (PMSM_to_BLDC_mod1_DW.obj_p.TunablePropsChanged) {
      PMSM_to_BLDC_mod1_DW.obj_p.TunablePropsChanged = false;
    }

    regularReadADCNormal(PMSM_to_BLDC_mod1_DW.obj_p.ADCHandle,
                         ADC_TRIGGER_AND_READ, &status);

    /* End of MATLABSystem: '<S459>/Analog to Digital Converter' */
  }

  if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M)) {
    /* Update for Atomic SubSystem: '<Root>/Timer' */
    if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
        PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for Delay: '<S56>/Delay' */
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE[0] =
        PMSM_to_BLDC_mod1_B.VectorConcatenate[0];
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE[1] =
        PMSM_to_BLDC_mod1_B.VectorConcatenate[1];
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE[2] =
        PMSM_to_BLDC_mod1_B.VectorConcatenate[2];

      /* Update for Delay: '<S59>/Delay' */
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[0] =
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[4];
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[1] =
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[5];
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[2] =
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[6];
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[3] =
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[7];
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[4] = rtb_TmpSignalConversionAtDelayI[0];
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[5] = rtb_TmpSignalConversionAtDelayI[1];
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[6] = rtb_TmpSignalConversionAtDelayI[2];
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[7] = rtb_TmpSignalConversionAtDelayI[3];

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

      /* Update for DiscreteIntegrator: '<S116>/Integrator' */
      PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n += rtb_Switch;
      PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState_n = 1;

      /* Update for DiscreteIntegrator: '<S171>/Integrator' */
      PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b += rtb_Switch_e;
      PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState_nt = 1;

      /* Update for Delay: '<S263>/Delay' */
      PMSM_to_BLDC_mod1_DW.icLoad_b = false;
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_g = rtb_Add1_d;
    }

    /* Update for Integrator: '<S392>/Integrator' */
    PMSM_to_BLDC_mod1_DW.Integrator_DWORK1 = false;

    /* Update for Integrator: '<S393>/Integrator' */
    PMSM_to_BLDC_mod1_DW.Integrator_DWORK1_g = false;

    /* End of Update for SubSystem: '<Root>/Timer' */
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

  /* Derivatives for Atomic SubSystem: '<Root>/Timer' */
  /* Derivatives for Integrator: '<S437>/Integrator' */
  _rtXdot->Integrator_CSTATE = PMSM_to_BLDC_mod1_B.IntegralGain;

  /* Derivatives for Integrator: '<S392>/Integrator' */
  lsat = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d <= -1.0E+7);
  usat = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d >= 1.0E+7);
  if (((!lsat) && (!usat)) || (lsat && (PMSM_to_BLDC_mod1_B.Add_h > 0.0)) ||
      (usat && (PMSM_to_BLDC_mod1_B.Add_h < 0.0))) {
    _rtXdot->Integrator_CSTATE_d = PMSM_to_BLDC_mod1_B.Add_h;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE_d = 0.0;
  }

  /* End of Derivatives for Integrator: '<S392>/Integrator' */

  /* Derivatives for Integrator: '<S377>/Int1' incorporates:
   *  Constant: '<S373>/Speed_Angular_Vel'
   */
  _rtXdot->Int1_CSTATE = 600.0;

  /* Derivatives for Integrator: '<S393>/Integrator' */
  lsat = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l <= -1.0E+7);
  usat = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l >= 1.0E+7);
  if (((!lsat) && (!usat)) || (lsat && (PMSM_to_BLDC_mod1_B.Add_d > 0.0)) ||
      (usat && (PMSM_to_BLDC_mod1_B.Add_d < 0.0))) {
    _rtXdot->Integrator_CSTATE_l = PMSM_to_BLDC_mod1_B.Add_d;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE_l = 0.0;
  }

  /* End of Derivatives for Integrator: '<S393>/Integrator' */
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
  PMSM_to_BLDC_mod1_M->Timing.stepSize0 = 5.0E-5;
  rtmSetFirstInitCond(PMSM_to_BLDC_mod1_M, 1);
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

  /* SystemInitialize for Atomic SubSystem: '<Root>/SPI_Write' */
  /* SystemInitialize for Enabled SubSystem: '<S4>/Control_Reg2' */
  /* Start for MATLABSystem: '<S20>/SPI Receive' */
  PMSM_to_BLDC_mod1_DW.obj.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = false;
  PMSM_to_BL_SystemCore_setup_oxg(&PMSM_to_BLDC_mod1_DW.obj);

  /* Start for MATLABSystem: '<S20>/SPI Transmit' */
  PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete = false;
  PMSM_to_BLDC_mod1_DW.obj_j.isInitialized = 1;
  PMSM_to_SPIDrvBlock_setupImpl_o(&PMSM_to_BLDC_mod1_DW.obj_j);
  PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<S4>/Control_Reg2' */

  /* SystemInitialize for Enabled SubSystem: '<S4>/Ctrl_Reg_1' */
  /* Start for MATLABSystem: '<S21>/SPI Transmit' */
  PMSM_to_BLDC_mod1_DW.obj_n.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_n.isSetupComplete = false;
  PMSM_to_BLDC_mod1_DW.obj_n.isInitialized = 1;
  PMSM_to_SPIDrvBlock_setupImpl_o(&PMSM_to_BLDC_mod1_DW.obj_n);
  PMSM_to_BLDC_mod1_DW.obj_n.isSetupComplete = true;
  PMSM_to_BLDC_mo_SPIReceive_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_j);

  /* End of SystemInitialize for SubSystem: '<S4>/Ctrl_Reg_1' */
  /* End of SystemInitialize for SubSystem: '<Root>/SPI_Write' */

  /* SystemInitialize for Enabled SubSystem: '<S6>/Status_Reg1_read' */
  PMSM_to_BLDC__SPIReceive_k_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaev);
  PMSM_to_BLDC_SPITransmit_d_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnaev);

  /* End of SystemInitialize for SubSystem: '<S6>/Status_Reg1_read' */

  /* SystemInitialize for Enabled SubSystem: '<S6>/Status_Reg_2_read' */
  PMSM_to_BLDC__SPIReceive_k_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaevv);
  PMSM_to_BLDC_SPITransmit_d_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnaevv);

  /* End of SystemInitialize for SubSystem: '<S6>/Status_Reg_2_read' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/SPI_read' */
  /* SystemInitialize for Enabled SubSystem: '<S32>/Subsystem1' */
  PMSM_to_BLDC_mo_SPIReceive_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pn);
  PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pn);

  /* End of SystemInitialize for SubSystem: '<S32>/Subsystem1' */

  /* SystemInitialize for Enabled SubSystem: '<S32>/Subsystem' */
  PMSM_to_BLDC__SPIReceive_e_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_p);
  PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_p);

  /* End of SystemInitialize for SubSystem: '<S32>/Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S33>/Subsystem' */
  PMSM_to_BLDC__SPIReceive_e_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pna);
  PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pna);

  /* End of SystemInitialize for SubSystem: '<S33>/Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S33>/Subsystem1' */
  PMSM_to_BLDC_mo_SPIReceive_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnae);
  PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnae);

  /* End of SystemInitialize for SubSystem: '<S33>/Subsystem1' */
  /* End of SystemInitialize for SubSystem: '<Root>/SPI_read' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Current_sensing' */
  /* SystemInitialize for Enabled SubSystem: '<S2>/Subsystem' */
  /* Start for MATLABSystem: '<S13>/Analog to Digital Converter' */
  PMSM_to_BLDC_mod1_DW.obj_d.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj_d.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_SystemCore_setup_o(&PMSM_to_BLDC_mod1_DW.obj_d);

  /* End of SystemInitialize for SubSystem: '<S2>/Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S2>/Subsystem1' */
  /* Start for MATLABSystem: '<S16>/Analog to Digital Converter' */
  PMSM_to_BLDC_mod1_DW.obj_o.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted = false;
  PMSM_to_BLD_SystemCore_setup_ox(&PMSM_to_BLDC_mod1_DW.obj_o);

  /* End of SystemInitialize for SubSystem: '<S2>/Subsystem1' */
  /* End of SystemInitialize for SubSystem: '<Root>/Current_sensing' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/En_gate' */
  /* Start for MATLABSystem: '<S19>/Digital Port Write' */
  PMSM_to_BLDC_mod1_DW.obj_ow.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_ow.isInitialized = 1;
  PMSM_to_BLDC_mod1_DW.obj_ow.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<Root>/En_gate' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Timer' */
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

  /* InitializeConditions for Integrator: '<S437>/Integrator' */
  PMSM_to_BLDC_mod1_X.Integrator_CSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S116>/Integrator' */
  PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n = PMSM_to_BLDC_mod1_ConstB.Constant3;

  /* InitializeConditions for DiscreteIntegrator: '<S171>/Integrator' */
  PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b =
    PMSM_to_BLDC_mod1_ConstB.Constant3_n;

  /* InitializeConditions for Delay: '<S263>/Delay' */
  PMSM_to_BLDC_mod1_DW.icLoad_b = true;

  /* InitializeConditions for Integrator: '<S392>/Integrator' incorporates:
   *  Integrator: '<S393>/Integrator'
   */
  if (rtmIsFirstInitCond(PMSM_to_BLDC_mod1_M)) {
    PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d = 0.0;
    PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l = 0.0;
  }

  PMSM_to_BLDC_mod1_DW.Integrator_DWORK1 = true;

  /* End of InitializeConditions for Integrator: '<S392>/Integrator' */

  /* InitializeConditions for Integrator: '<S377>/Int1' */
  PMSM_to_BLDC_mod1_X.Int1_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S393>/Integrator' */
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

  /* End of SystemInitialize for SubSystem: '<Root>/Timer' */

  /* Start for MATLABSystem: '<S459>/Analog to Digital Converter' */
  PMSM_to_BLDC_mod1_DW.obj_p.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj_p.matlabCodegenIsDeleted = false;
  PMSM_to_B_SystemCore_setup_oxgk(&PMSM_to_BLDC_mod1_DW.obj_p);

  /* InitializeConditions for root-level periodic continuous states */
  {
    int_T rootPeriodicContStateIndices[1] = { 2 };

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
  if (!PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, SPIPinsLoc,
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
  /* End of Terminate for SubSystem: '<S4>/Control_Reg2' */

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
  PMSM_to_BLDC_mo_SPIReceive_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_j);

  /* End of Terminate for SubSystem: '<S4>/Ctrl_Reg_1' */
  /* End of Terminate for SubSystem: '<Root>/SPI_Write' */

  /* Terminate for Enabled SubSystem: '<S6>/Status_Reg1_read' */
  PMSM_to_BLDC__SPIReceive_c_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaev);
  PMSM_to_BLDC_SPITransmit_a_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnaev);

  /* End of Terminate for SubSystem: '<S6>/Status_Reg1_read' */

  /* Terminate for Enabled SubSystem: '<S6>/Status_Reg_2_read' */
  PMSM_to_BLDC__SPIReceive_c_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaevv);
  PMSM_to_BLDC_SPITransmit_a_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnaevv);

  /* End of Terminate for SubSystem: '<S6>/Status_Reg_2_read' */

  /* Terminate for Atomic SubSystem: '<Root>/SPI_read' */
  /* Terminate for Enabled SubSystem: '<S32>/Subsystem1' */
  PMSM_to_BLDC_mo_SPIReceive_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pn);
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pn);

  /* End of Terminate for SubSystem: '<S32>/Subsystem1' */

  /* Terminate for Enabled SubSystem: '<S32>/Subsystem' */
  PMSM_to_BLDC__SPIReceive_m_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_p);
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_p);

  /* End of Terminate for SubSystem: '<S32>/Subsystem' */

  /* Terminate for Enabled SubSystem: '<S33>/Subsystem' */
  PMSM_to_BLDC__SPIReceive_m_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pna);
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pna);

  /* End of Terminate for SubSystem: '<S33>/Subsystem' */

  /* Terminate for Enabled SubSystem: '<S33>/Subsystem1' */
  PMSM_to_BLDC_mo_SPIReceive_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnae);
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnae);

  /* End of Terminate for SubSystem: '<S33>/Subsystem1' */
  /* End of Terminate for SubSystem: '<Root>/SPI_read' */

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
  /* End of Terminate for SubSystem: '<S2>/Subsystem' */

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
  /* End of Terminate for SubSystem: '<S2>/Subsystem1' */
  /* End of Terminate for SubSystem: '<Root>/Current_sensing' */

  /* Terminate for Atomic SubSystem: '<Root>/En_gate' */
  /* Terminate for MATLABSystem: '<S19>/Digital Port Write' */
  if (!PMSM_to_BLDC_mod1_DW.obj_ow.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_ow.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S19>/Digital Port Write' */
  /* End of Terminate for SubSystem: '<Root>/En_gate' */

  /* Terminate for Atomic SubSystem: '<Root>/Timer' */
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
  /* End of Terminate for SubSystem: '<Root>/Timer' */

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
