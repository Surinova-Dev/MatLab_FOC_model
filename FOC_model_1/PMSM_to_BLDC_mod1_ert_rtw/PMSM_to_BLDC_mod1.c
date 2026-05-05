/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.c
 *
 * Code generated for Simulink model 'PMSM_to_BLDC_mod1'.
 *
 * Model version                  : 4.884
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Tue May  5 18:45:38 2026
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
#include <stddef.h>
#include "stm_adc_ll.h"
#include "stm_timer_ll.h"
#include "zero_crossing_types.h"
#include <float.h>

/* Named constants for Chart: '<Root>/Chart' */
#define PMSM_to_BLDC__IN_Initialization ((uint8_T)3U)
#define PMSM_to_BLDC_m_IN_Current_sense ((uint8_T)1U)
#define PMSM_to_BLDC_mod1_IN_En_Gate   ((uint8_T)2U)
#define PMSM_to_BLDC_mod1_IN_SPI_init1 ((uint8_T)4U)
#define PMSM_to_BLDC_mod1_IN_SPI_init2 ((uint8_T)5U)
#define PMSM_to_BLDC_mod1_IN_SPI_init3 ((uint8_T)6U)
#define PMSM_to_BLDC_mod1_IN_SPI_init4 ((uint8_T)7U)
#define PMSM_to_BLDC_mod1_IN_SPI_write ((uint8_T)8U)
#define PMSM_to_BLDC_mod1_IN_SPI_write2 ((uint8_T)10U)
#define PMSM_to_BLDC_mod1_IN_SPI_write5 ((uint8_T)11U)
#define PMSM_to_BLDC_mod1_IN_SPI_write6 ((uint8_T)12U)
#define PMSM_to_BLDC_mod1_IN_SPI_write7 ((uint8_T)13U)
#define PMSM_to_BLDC_mod1_IN_SPI_write8 ((uint8_T)14U)
#define PMSM_to_BLDC_mod1_IN_SPI_write9 ((uint8_T)15U)
#define PMSM_to_BLDC_mod_IN_SPI_write10 ((uint8_T)9U)

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
static void PMSM_to_SPIDrvBlock_setupImpl_e(stm32cube_blocks_SPIControl_d_T *obj);

/* Forward declaration for local functions */
static void PMSM_to_BL_SystemCore_setup_oxg(stm32cube_blocks_SPIControlle_T *obj);
static void PMSM_to_SPIDrvBlock_setupImpl_o(stm32cube_blocks_SPIControl_d_T *obj);
static void PMSM_to_BLD_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_PM_T *obj);
static void PMSM_to_B_SystemCore_setup_oxgk(stm32cube_blocks_SPIControlle_T *obj);
static void PMSM_to_BLDC_SystemCore_setup_o(stm32cube_blocks_AnalogInput__T *obj);
static void PMSM_to_BLD_SystemCore_setup_ox(stm32cube_blocks_AnalogInput__T *obj);
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
  if ((PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[3]) > 9999) {/* Sample time: [1.0s, 0.0s] */
    PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[3] = 0;
  }
}

/* Projection for root system: '<Root>' */
void PMSM_to_BLDC_mod1_projection(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  char *msg;
  real_T tmp_0[28];
  real_T time;
  int32_T tmp_2;
  int_T tmp_1[8];
  boolean_T tmp;

  /* Projection for Enabled SubSystem: '<Root>/Subsystem' */
  if (PMSM_to_BLDC_mod1_B.FOC_flag > 0.0) {
    /* Projection for SimscapeExecutionBlock: '<S416>/STATE_1' */
    simulationData = (NeslSimulationData *)PMSM_to_BLDC_mod1_DW.STATE_1_SimData;
    time = PMSM_to_BLDC_mod1_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 17;
    simulationData->mData->mContStates.mX =
      &PMSM_to_BLDC_mod1_X.PMSM_to_BLDC_mod1SubsystemFOCIn[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &PMSM_to_BLDC_mod1_DW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 11;
    simulationData->mData->mModeVector.mX = &PMSM_to_BLDC_mod1_DW.STATE_1_Modes
      [0];
    tmp = false;
    simulationData->mData->mFoundZcEvents = tmp;
    simulationData->mData->mHadEvents = false;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
      (PMSM_to_BLDC_mod1_M);
    tmp = false;
    simulationData->mData->mIsSolverAssertCheck = tmp;
    simulationData->mData->mIsSolverCheckingCIC = false;
    tmp = rtsiIsSolverComputingJacobian(&PMSM_to_BLDC_mod1_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = tmp;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
      (&PMSM_to_BLDC_mod1_M->solverInfo);
    tmp_1[0] = 0;
    tmp_0[0] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[0];
    tmp_0[1] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[1];
    tmp_0[2] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[2];
    tmp_0[3] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[3];
    tmp_1[1] = 4;
    tmp_0[4] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[0];
    tmp_0[5] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[1];
    tmp_0[6] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[2];
    tmp_0[7] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[3];
    tmp_1[2] = 8;
    tmp_0[8] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[0];
    tmp_0[9] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[1];
    tmp_0[10] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[2];
    tmp_0[11] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[3];
    tmp_1[3] = 12;
    tmp_0[12] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[0];
    tmp_0[13] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[1];
    tmp_0[14] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[2];
    tmp_0[15] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[3];
    tmp_1[4] = 16;
    tmp_0[16] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[0];
    tmp_0[17] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[1];
    tmp_0[18] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[2];
    tmp_0[19] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[3];
    tmp_1[5] = 20;
    tmp_0[20] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[0];
    tmp_0[21] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[1];
    tmp_0[22] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[2];
    tmp_0[23] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[3];
    tmp_1[6] = 24;
    tmp_0[24] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[0];
    tmp_0[25] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[1];
    tmp_0[26] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[2];
    tmp_0[27] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[3];
    tmp_1[7] = 28;
    simulationData->mData->mInputValues.mN = 28;
    simulationData->mData->mInputValues.mX = &tmp_0[0];
    simulationData->mData->mInputOffsets.mN = 8;
    simulationData->mData->mInputOffsets.mX = &tmp_1[0];
    diagnosticManager = (NeuDiagnosticManager *)
      PMSM_to_BLDC_mod1_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_2 = ne_simulator_method((NeslSimulator *)
      PMSM_to_BLDC_mod1_DW.STATE_1_Simulator, NESL_SIM_PROJECTION,
      simulationData, diagnosticManager);
    if (tmp_2 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(PMSM_to_BLDC_mod1_M));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(PMSM_to_BLDC_mod1_M, msg);
      }
    }

    /* End of Projection for SimscapeExecutionBlock: '<S416>/STATE_1' */
  }

  /* End of Projection for SubSystem: '<Root>/Subsystem' */
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
  int_T nXc = 21;
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

  PMSM_to_BLDC_mod1_step();
  PMSM_to_BLDC_mod1_projection();
  local_stateReduction(rtsiGetContStates(si), rtsiGetPeriodicContStateIndices(si),
                       1,
                       rtsiGetPeriodicContStateRanges(si));
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for atomic system:
 *    '<S19>/Bit Shift'
 *    '<S20>/Bit Shift'
 *    '<S33>/Bit Shift'
 *    '<S39>/Bit Shift'
 *    '<S45>/Bit Shift'
 *    '<S46>/Bit Shift'
 */
uint16_T PMSM_to_BLDC_mod1_BitShift(uint16_T rtu_u)
{
  /* MATLAB Function: '<S21>/bit_shift' */
  return (uint16_T)(rtu_u << 15);
}

/*
 * Output and update for atomic system:
 *    '<S19>/Bit Shift1'
 *    '<S20>/Bit Shift1'
 *    '<S33>/Bit Shift1'
 *    '<S39>/Bit Shift1'
 *    '<S45>/Bit Shift1'
 *    '<S46>/Bit Shift1'
 */
uint16_T PMSM_to_BLDC_mod1_BitShift1(uint16_T rtu_u)
{
  /* MATLAB Function: '<S22>/bit_shift' */
  return (uint16_T)(rtu_u << 11);
}

static void PMSM_to_BLDC_m_SystemCore_setup(stm32cube_blocks_SPIControlle_T *obj)
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
  obj->MW_SPI_BlockStruct.dataLength = 1.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
  obj->isSetupComplete = true;
}

/* System initialize for atomic system: */
void PMSM_to_BLDC_mo_SPIReceive_Init(DW_SPIReceive_PMSM_to_BLDC_mo_T *localDW)
{
  /* Start for MATLABSystem: '<S20>/SPI Receive' */
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

  /* MATLABSystem: '<S20>/SPI Receive' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    MW_SPI_Read_Databits(localDW->obj.MW_SPI_HANDLE, &localB->SPIReceive, 1U, 1,
                         1, 1U);
    LL_GPIO_SetOutputPin(GPIOC, 16384U);
  }

  /* End of MATLABSystem: '<S20>/SPI Receive' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC_mo_SPIReceive_Term(DW_SPIReceive_PMSM_to_BLDC_mo_T *localDW)
{
  /* Terminate for MATLABSystem: '<S20>/SPI Receive' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S20>/SPI Receive' */
}

static void PMSM_to_B_SPIDrvBlock_setupImpl(stm32cube_blocks_SPIControl_d_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;

  /* Start for MATLABSystem: '<S33>/SPI Transmit' */
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S33>/SPI Transmit' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S33>/SPI Transmit' */
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
  /* Start for MATLABSystem: '<S33>/SPI Transmit' */
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

  /* MATLABSystem: '<S33>/SPI Transmit' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    LL_GPIO_ResetOutputPin(GPIOC, 16384U);
    MW_SPI_Write_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0, 1U, 1, 1, 1U);
  }

  /* End of MATLABSystem: '<S33>/SPI Transmit' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC_m_SPITransmit_Term(DW_SPITransmit_PMSM_to_BLDC_m_T *localDW)
{
  /* Terminate for MATLABSystem: '<S33>/SPI Transmit' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/SPI Transmit' */
}

static void PMSM_to_BLDC_SystemCore_setup_n(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S45>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S45>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S45>/SPI Receive' */
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
  /* Start for MATLABSystem: '<S45>/SPI Receive' */
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

  /* MATLABSystem: '<S45>/SPI Receive' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    MW_SPI_Read_Databits(localDW->obj.MW_SPI_HANDLE, &tmp[0], 15U, 1, 1, 1U);
    LL_GPIO_SetOutputPin(GPIOC, 16384U);
  }

  /* End of MATLABSystem: '<S45>/SPI Receive' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC__SPIReceive_m_Term(DW_SPIReceive_PMSM_to_BLDC__f_T *localDW)
{
  /* Terminate for MATLABSystem: '<S45>/SPI Receive' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S45>/SPI Receive' */
}

static void PMSM_to_SPIDrvBlock_setupImpl_e(stm32cube_blocks_SPIControl_d_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;

  /* Start for MATLABSystem: '<S45>/SPI Transmit' */
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S45>/SPI Transmit' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S45>/SPI Transmit' */
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
  /* Start for MATLABSystem: '<S45>/SPI Transmit' */
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

  /* MATLABSystem: '<S45>/SPI Transmit' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    LL_GPIO_ResetOutputPin(GPIOC, 16384U);
    MW_SPI_Write_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0, 1U, 1, 1, 1U);
  }

  /* End of MATLABSystem: '<S45>/SPI Transmit' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC_SPITransmit_a_Term(DW_SPITransmit_PMSM_to_BLDC_f_T *localDW)
{
  /* Terminate for MATLABSystem: '<S45>/SPI Transmit' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S45>/SPI Transmit' */
}

/*
 * Output and update for action system:
 *    '<S195>/If Action Subsystem'
 *    '<S221>/If Action Subsystem'
 */
real_T PMSM_to_BLDC__IfActionSubsystem(real_T rtu_In1)
{
  real_T tmp;

  /* DataTypeConversion: '<S198>/Convert_uint16' */
  tmp = floor(rtu_In1);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* Sum: '<S198>/Sum' incorporates:
   *  DataTypeConversion: '<S198>/Convert_back'
   *  DataTypeConversion: '<S198>/Convert_uint16'
   */
  return rtu_In1 - (real_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
    -tmp : (int32_T)(int16_T)(uint16_T)tmp);
}

/*
 * Output and update for action system:
 *    '<S195>/If Action Subsystem1'
 *    '<S221>/If Action Subsystem1'
 */
real_T PMSM_to_BLDC_IfActionSubsystem1(real_T rtu_In1)
{
  real_T tmp;

  /* DataTypeConversion: '<S199>/Convert_uint16' */
  tmp = trunc(rtu_In1);
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

  /* Start for MATLABSystem: '<S19>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S19>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S19>/SPI Receive' */
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

  /* Start for MATLABSystem: '<S19>/SPI Transmit' incorporates:
   *  MATLABSystem: '<S20>/SPI Transmit'
   */
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S19>/SPI Transmit' incorporates:
   *  MATLABSystem: '<S20>/SPI Transmit'
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

  /* Start for MATLABSystem: '<S19>/SPI Transmit' incorporates:
   *  MATLABSystem: '<S20>/SPI Transmit'
   */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 1.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
}

static void PMSM_to_BLD_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_PM_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S474>/PWM Output' */
  b.PeripheralPtr = TIM8;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S474>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S474>/PWM Output' */
    enableCounter(obj->TimerHandle, true);
  }
}

static void PMSM_to_B_SystemCore_setup_oxgk(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S33>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S33>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S33>/SPI Receive' */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 15.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
  obj->isSetupComplete = true;
}

static void PMSM_to_BLDC_SystemCore_setup_o(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S12>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S12>/Analog to Digital Converter' */
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

  /* Start for MATLABSystem: '<S15>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S15>/Analog to Digital Converter' */
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
  real_T rtb_Gain4_i;
  real_T rtb_Gain3_c;
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

  {
    GPIO_TypeDef * portNameLoc;
    TIM_TypeDef * timModule;
    uint32_T channelEnum;
    NeslSimulationData *simulationData;
    NeuDiagnosticManager *diag;
    NeuDiagnosticTree *diagTree;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    char *msg;
    char *msg_0;
    char *msg_1;
    real_T Merge_i;
    real_T rtb_Add1_f;
    real_T rtb_Add2;
    real_T rtb_Add3;
    real_T rtb_Add_oj;
    real_T rtb_DeadZone;
    real_T rtb_Gain4_i_tmp;
    real_T rtb_Gain4_i_tmp_0;
    real_T rtb_Gain_e;
    real_T rtb_Integrator_l;
    real_T rtb_OUTPUT_1_0;
    real_T rtb_Product1_o;
    real_T rtb_Product2_a;
    real_T rtb_Product_fc;
    real_T rtb_Product_j_idx_1;
    real_T rtb_Saturation_k;
    real_T rtb_convert_pu_i;
    real_T rtb_one_by_sqrt3_;
    real_T rtb_uabc3;
    real_T time;
    real_T time_0;
    real_T time_1;
    real_T time_2;
    real_T tmp;
    real_T tmp_5;
    int32_T i;
    real32_T rtb_Saturation_or;
    real32_T rtb_indexing;
    uint32_T freq;
    uint32_T pinMask;
    uint16_T tmp_1[15];
    uint16_T rtb_y_e;
    uint16_T status;
    int8_T rtAction;
    int8_T rtPrevAction;
    boolean_T ok;
    boolean_T tmp_0;
    boolean_T tmp_2;
    boolean_T tmp_3;
    boolean_T tmp_4;
    tmp_2 = (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
             PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] == 0);
    if (tmp_2) {
      /* Chart: '<Root>/Chart' */
      if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 < 16383) {
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
          if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 10000) {
            PMSM_to_BLDC_mod1_B.FOC_flag = 0.0;
            PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
            PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
              PMSM_to_BLDC_mod1_IN_SPI_write;
            PMSM_to_BLDC_mod1_B.spi_write1 = 1.0;
          }
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
              PMSM_to_BLDC_m_IN_Current_sense;
            PMSM_to_BLDC_mod1_B.Ib_flag = 1.0;
            PMSM_to_BLDC_mod1_B.Ic_flag = 1.0;
            PMSM_to_BLDC_mod1_B.FOC_flag = 1.0;
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

    tmp_4 = (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
             PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0);
    if (tmp_4) {
      /* Outputs for Atomic SubSystem: '<Root>/SPI_Write' */
      /* Outputs for Enabled SubSystem: '<S4>/Control_Reg2' incorporates:
       *  EnablePort: '<S19>/Enable'
       */
      /* Logic: '<S4>/AND1' incorporates:
       *  Constant: '<S19>/Constant'
       *  Constant: '<S19>/Constant1'
       */
      if ((PMSM_to_BLDC_mod1_B.En_State != 0.0) &&
          (PMSM_to_BLDC_mod1_B.Ctrl_flag2 != 0.0)) {
        /* MATLABSystem: '<S19>/SPI Receive' */
        status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_g.MW_SPI_HANDLE,
          2U, 3840U, MW_SPI_MODE_3);
        if (status == 0) {
          MW_SPI_Read_Databits(PMSM_to_BLDC_mod1_DW.obj_g.MW_SPI_HANDLE,
                               &PMSM_to_BLDC_mod1_B.uv[0], 16U, 1, 1, 1U);
          LL_GPIO_SetOutputPin(GPIOC, 16384U);
        }

        /* End of MATLABSystem: '<S19>/SPI Receive' */

        /* Outputs for Atomic SubSystem: '<S19>/Bit Shift' */
        status = PMSM_to_BLDC_mod1_BitShift(0);

        /* End of Outputs for SubSystem: '<S19>/Bit Shift' */

        /* Outputs for Atomic SubSystem: '<S19>/Bit Shift1' */
        rtb_y_e = PMSM_to_BLDC_mod1_BitShift1(3);

        /* End of Outputs for SubSystem: '<S19>/Bit Shift1' */

        /* S-Function (sfix_bitop): '<S19>/Bitwise OR' incorporates:
         *  Constant: '<S19>/Constant'
         *  Constant: '<S19>/Constant1'
         */
        rtb_y_e = (uint16_T)(status | rtb_y_e |
                             PMSM_to_BLDC_mod1_ConstB.BitwiseAND_jx);

        /* MATLABSystem: '<S19>/SPI Transmit' */
        status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE,
          2U, 3840U, MW_SPI_MODE_3);
        if (status == 0) {
          LL_GPIO_ResetOutputPin(GPIOC, 16384U);
          MW_SPI_Write_Databits(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE,
                                &rtb_y_e, 1U, 1, 1, 1000U);
        }

        /* End of MATLABSystem: '<S19>/SPI Transmit' */
      }

      /* End of Logic: '<S4>/AND1' */
      /* End of Outputs for SubSystem: '<S4>/Control_Reg2' */

      /* Outputs for Enabled SubSystem: '<S4>/Ctrl_Reg_1' incorporates:
       *  EnablePort: '<S20>/Enable'
       */
      /* Logic: '<S4>/AND' incorporates:
       *  Constant: '<S20>/Constant'
       *  Constant: '<S20>/Constant1'
       */
      if ((PMSM_to_BLDC_mod1_B.En_State != 0.0) &&
          (PMSM_to_BLDC_mod1_B.Ctrl_flag1 != 0.0)) {
        /* Outputs for Atomic SubSystem: '<S20>/Bit Shift' */
        status = PMSM_to_BLDC_mod1_BitShift(0);

        /* End of Outputs for SubSystem: '<S20>/Bit Shift' */

        /* Outputs for Atomic SubSystem: '<S20>/Bit Shift1' */
        rtb_y_e = PMSM_to_BLDC_mod1_BitShift1(2);

        /* End of Outputs for SubSystem: '<S20>/Bit Shift1' */

        /* S-Function (sfix_bitop): '<S20>/Bitwise OR' incorporates:
         *  Constant: '<S20>/Constant'
         *  Constant: '<S20>/Constant1'
         */
        rtb_y_e = (uint16_T)(status | rtb_y_e |
                             PMSM_to_BLDC_mod1_ConstB.BitwiseAND_e);

        /* MATLABSystem: '<S20>/SPI Transmit' */
        status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_n.MW_SPI_HANDLE,
          2U, 3840U, MW_SPI_MODE_3);
        if (status == 0) {
          LL_GPIO_ResetOutputPin(GPIOC, 16384U);
          MW_SPI_Write_Databits(PMSM_to_BLDC_mod1_DW.obj_n.MW_SPI_HANDLE,
                                &rtb_y_e, 1U, 1, 1, 10U);
        }

        /* End of MATLABSystem: '<S20>/SPI Transmit' */
        PMSM_to_BLDC_mod1_SPIReceive(&PMSM_to_BLDC_mod1_B.SPIReceive_j,
          &PMSM_to_BLDC_mod1_DW.SPIReceive_j);
      }

      /* End of Logic: '<S4>/AND' */
      /* End of Outputs for SubSystem: '<S4>/Ctrl_Reg_1' */
      /* End of Outputs for SubSystem: '<Root>/SPI_Write' */
    }

    if (tmp_2) {
      /* Outputs for Enabled SubSystem: '<Root>/Subsystem' incorporates:
       *  EnablePort: '<S7>/Enable'
       */
      /* Outputs for Enabled SubSystem: '<S6>/Status_Reg_2_read' incorporates:
       *  EnablePort: '<S46>/Ctrl_flag2'
       */
      /* Outputs for Enabled SubSystem: '<S6>/Status_Reg1_read' incorporates:
       *  EnablePort: '<S45>/Ctrl_flag1'
       */
      tmp_2 = rtsiIsModeUpdateTimeStep(&PMSM_to_BLDC_mod1_M->solverInfo);

      /* End of Outputs for SubSystem: '<S6>/Status_Reg_2_read' */
      /* End of Outputs for SubSystem: '<Root>/Subsystem' */
      if (tmp_2) {
        PMSM_to_BLDC_mod1_DW.Status_Reg1_read_MODE =
          (PMSM_to_BLDC_mod1_B.spi_write1 > 0.0);
      }

      if (PMSM_to_BLDC_mod1_DW.Status_Reg1_read_MODE) {
        PMSM_to_BLDC_mod1_SPIReceive_p(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnae);

        /* Outputs for Atomic SubSystem: '<S45>/Bit Shift' */
        /* Constant: '<S45>/Constant' */
        status = PMSM_to_BLDC_mod1_BitShift(1);

        /* End of Outputs for SubSystem: '<S45>/Bit Shift' */

        /* Outputs for Atomic SubSystem: '<S45>/Bit Shift1' */
        /* Constant: '<S45>/Constant1' */
        rtb_y_e = PMSM_to_BLDC_mod1_BitShift1(0);

        /* End of Outputs for SubSystem: '<S45>/Bit Shift1' */

        /* S-Function (sfix_bitop): '<S45>/Bitwise OR' */
        PMSM_to_BLDC_mod1_SPITransmit_p((uint16_T)(status | rtb_y_e |
          PMSM_to_BLDC_mod1_ConstB.BitwiseAND_m),
          &PMSM_to_BLDC_mod1_DW.SPITransmit_pnaev);
      }

      /* End of Outputs for SubSystem: '<S6>/Status_Reg1_read' */

      /* Outputs for Enabled SubSystem: '<S6>/Status_Reg_2_read' incorporates:
       *  EnablePort: '<S46>/Ctrl_flag2'
       */
      if (tmp_2) {
        PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_MODE =
          (PMSM_to_BLDC_mod1_B.spi_write2 > 0.0);
      }

      if (PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_MODE) {
        PMSM_to_BLDC_mod1_SPIReceive_p(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaev);

        /* Outputs for Atomic SubSystem: '<S46>/Bit Shift' */
        /* Constant: '<S46>/Constant' */
        rtb_y_e = PMSM_to_BLDC_mod1_BitShift(1);

        /* End of Outputs for SubSystem: '<S46>/Bit Shift' */

        /* Outputs for Atomic SubSystem: '<S46>/Bit Shift1' */
        /* Constant: '<S46>/Constant1' */
        status = PMSM_to_BLDC_mod1_BitShift1(1);

        /* End of Outputs for SubSystem: '<S46>/Bit Shift1' */

        /* S-Function (sfix_bitop): '<S46>/Bitwise OR' */
        PMSM_to_BLDC_mod1_SPITransmit_p((uint16_T)(rtb_y_e | status |
          PMSM_to_BLDC_mod1_ConstB.BitwiseAND),
          &PMSM_to_BLDC_mod1_DW.SPITransmit_pnaevv);
      }

      /* End of Outputs for SubSystem: '<S6>/Status_Reg_2_read' */

      /* Outputs for Enabled SubSystem: '<Root>/Subsystem' incorporates:
       *  EnablePort: '<S7>/Enable'
       */
      if (tmp_2) {
        if (PMSM_to_BLDC_mod1_B.FOC_flag > 0.0) {
          if (!PMSM_to_BLDC_mod1_DW.Subsystem_MODE) {
            (void) memset(&(PMSM_to_BLDC_mod1_XDis.Integrator_CSTATE), 0,
                          21*sizeof(boolean_T));

            /* InitializeConditions for Delay: '<S55>/Delay' */
            PMSM_to_BLDC_mod1_DW.Delay_DSTATE[0] = 0.0;
            PMSM_to_BLDC_mod1_DW.Delay_DSTATE[1] = 0.0;
            PMSM_to_BLDC_mod1_DW.Delay_DSTATE[2] = 0.0;

            /* InitializeConditions for Delay: '<S231>/Delay1' */
            PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f = 0.0F;

            /* InitializeConditions for Delay: '<S58>/Delay' */
            memset(&PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[0], 0, sizeof(real_T) <<
                   3U);

            /* InitializeConditions for Delay: '<S235>/Delay' */
            PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0] = 0.0;
            PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1] = 0.0;

            /* InitializeConditions for Delay: '<S248>/Delay' */
            PMSM_to_BLDC_mod1_DW.icLoad = true;

            /* InitializeConditions for Delay: '<S331>/Delay' */
            PMSM_to_BLDC_mod1_DW.icLoad_f = true;

            /* InitializeConditions for Delay: '<S355>/Delay' */
            PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj = 0.0;

            /* InitializeConditions for DiscreteIntegrator: '<S300>/Integrator' */
            PMSM_to_BLDC_mod1_DW.Integrator_DSTATE = 0.0;
            PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState = 0;

            /* InitializeConditions for Delay: '<S356>/Delay' */
            PMSM_to_BLDC_mod1_DW.icLoad_a = true;

            /* InitializeConditions for DiscreteIntegrator: '<S170>/Integrator' */
            PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b =
              PMSM_to_BLDC_mod1_ConstB.Constant3_n;
            PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState_n = 0;

            /* InitializeConditions for Delay: '<S55>/Delay1' */
            PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx = 0.0F;

            /* InitializeConditions for Integrator: '<S455>/Integrator' */
            PMSM_to_BLDC_mod1_X.Integrator_CSTATE = 0.0;

            /* InitializeConditions for DiscreteIntegrator: '<S115>/Integrator' */
            PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n =
              PMSM_to_BLDC_mod1_ConstB.Constant3;
            PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState_nt = 0;

            /* InitializeConditions for Delay: '<S262>/Delay' */
            PMSM_to_BLDC_mod1_DW.icLoad_b = true;

            /* InitializeConditions for Integrator: '<S390>/Integrator' incorporates:
             *  Integrator: '<S391>/Integrator'
             */
            if (rtmIsFirstInitCond(PMSM_to_BLDC_mod1_M)) {
              PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d = 0.0;
              PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l = 0.0;
            }

            PMSM_to_BLDC_mod1_DW.Integrator_DWORK1 = true;

            /* End of InitializeConditions for Integrator: '<S390>/Integrator' */

            /* InitializeConditions for Integrator: '<S375>/Int1' */
            PMSM_to_BLDC_mod1_X.Int1_CSTATE = 0.0;

            /* InitializeConditions for Integrator: '<S391>/Integrator' */
            PMSM_to_BLDC_mod1_DW.Integrator_DWORK1_g = true;
            PMSM_to_BLDC_mod1_DW.Subsystem_MODE = true;
          }
        } else {
          if (((PMSM_to_BLDC_mod1_M->Timing.clockTick2) * 0.001) == rtmGetTStart
              (PMSM_to_BLDC_mod1_M)) {
            (void) memset(&(PMSM_to_BLDC_mod1_XDis.Integrator_CSTATE), 1,
                          21*sizeof(boolean_T));
          }

          if (PMSM_to_BLDC_mod1_DW.Subsystem_MODE) {
            (void) memset(&(PMSM_to_BLDC_mod1_XDis.Integrator_CSTATE), 1,
                          21*sizeof(boolean_T));

            /* Disable for If: '<S249>/If' */
            PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem = -1;

            /* Disable for SwitchCase: '<S258>/Switch Case' */
            PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem = -1;

            /* Disable for If: '<S255>/If' */
            rtsiSetBlockStateForSolverChangedAtMajorStep
              (&PMSM_to_BLDC_mod1_M->solverInfo, true);
            PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_g = -1;

            /* Disable for SwitchCase: '<S257>/Switch Case' */
            PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem_n = -1;

            /* Disable for If: '<S360>/If' */
            PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_e = -1;

            /* Disable for If: '<S221>/If' */
            PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_c = -1;

            /* Disable for If: '<S195>/If' */
            PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_m = -1;
            PMSM_to_BLDC_mod1_DW.Subsystem_MODE = false;
          }
        }
      }

      /* End of Outputs for SubSystem: '<Root>/Subsystem' */
    }

    /* Outputs for Enabled SubSystem: '<Root>/Subsystem' incorporates:
     *  EnablePort: '<S7>/Enable'
     */
    if (PMSM_to_BLDC_mod1_DW.Subsystem_MODE) {
      tmp_2 = (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
               PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0);
      if (tmp_2) {
        /* Sum: '<S75>/Sum2' incorporates:
         *  Delay: '<S55>/Delay'
         *  Gain: '<S75>/one_by_3'
         *  Sum: '<S75>/Sum'
         */
        rtb_uabc3 = PMSM_to_BLDC_mod1_DW.Delay_DSTATE[0] -
          ((PMSM_to_BLDC_mod1_DW.Delay_DSTATE[0] +
            PMSM_to_BLDC_mod1_DW.Delay_DSTATE[1]) +
           PMSM_to_BLDC_mod1_DW.Delay_DSTATE[2]) * 0.33333333333333331;

        /* Gain: '<S75>/one_by_sqrt3_' incorporates:
         *  Delay: '<S55>/Delay'
         *  Sum: '<S75>/Sum1'
         */
        rtb_one_by_sqrt3_ = (PMSM_to_BLDC_mod1_DW.Delay_DSTATE[1] -
                             PMSM_to_BLDC_mod1_DW.Delay_DSTATE[2]) *
          0.57735026918962584;

        /* Delay: '<S231>/Delay1' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f = 0.0F;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE = 0U;

        /* Gain: '<S237>/Gain' incorporates:
         *  Delay: '<S231>/Delay1'
         */
        rtb_Gain_e = -0.0017999999690800905 *
          PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f;

        /* Gain: '<S244>/Gain1' incorporates:
         *  Delay: '<S58>/Delay'
         */
        rtb_Add3 = 555.55555555555554 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[1];

        /* Gain: '<S244>/Gain' incorporates:
         *  Delay: '<S58>/Delay'
         */
        rtb_Add1_f = 555.55555555555554 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[0];

        /* Sum: '<S245>/Sum' incorporates:
         *  Product: '<S245>/Product'
         *  Product: '<S245>/Product2'
         *  UnaryMinus: '<S245>/Unary Minus'
         */
        rtb_Add2 = -rtb_Gain_e * rtb_Add3 - rtb_Add1_f;

        /* Sum: '<S245>/Sum1' incorporates:
         *  Product: '<S245>/Product1'
         *  Product: '<S245>/Product3'
         */
        rtb_Add1_f = rtb_Add1_f * rtb_Gain_e - rtb_Add3;

        /* Gain: '<S236>/Gain' incorporates:
         *  Delay: '<S231>/Delay1'
         */
        rtb_Gain_e = -0.0017999999690800905 *
          PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f;

        /* Sum: '<S241>/Sum1' incorporates:
         *  Delay: '<S58>/Delay'
         *  Product: '<S241>/Product3'
         */
        rtb_Add3 = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[2] * rtb_Gain_e -
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[3];

        /* Sum: '<S241>/Sum' incorporates:
         *  Delay: '<S58>/Delay'
         *  Product: '<S241>/Product2'
         *  UnaryMinus: '<S241>/Unary Minus'
         */
        rtb_Integrator_l = -rtb_Gain_e * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[3]
          - PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[2];

        /* Product: '<S240>/Product' incorporates:
         *  Delay: '<S231>/Delay1'
         */
        rtb_Add_oj = rtb_Integrator_l * PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f;

        /* Gain: '<S239>/Gain' */
        rtb_Gain4_i_tmp = 555.55555555555554 * rtb_Integrator_l;

        /* Gain: '<S239>/Gain1' */
        rtb_Gain4_i_tmp_0 = 555.55555555555554 * rtb_Add3;

        /* Gain: '<S383>/Gain4' incorporates:
         *  Gain: '<S239>/Gain'
         *  Gain: '<S239>/Gain1'
         *  Product: '<S242>/Product2'
         *  Sum: '<S242>/Sum'
         *  UnaryMinus: '<S239>/Unary Minus1'
         *  UnaryMinus: '<S242>/Unary Minus'
         */
        rtb_Gain4_i = -rtb_Gain4_i_tmp_0 * -rtb_Gain_e + rtb_Gain4_i_tmp;

        /* Gain: '<S383>/Gain3' incorporates:
         *  Constant: '<S238>/(Ld-Lq)_Ld'
         *  Constant: '<S238>/R_Ld'
         *  Delay: '<S231>/Delay1'
         *  Delay: '<S58>/Delay'
         *  Product: '<S238>/Product'
         *  Product: '<S238>/Product3'
         *  Product: '<S238>/Product5'
         *  Sum: '<S238>/Sum1'
         *  UnaryMinus: '<S238>/Unary Minus1'
         */
        rtb_Gain3_c = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[3] *
          -20.555555555555554;
        rtb_Gain3_c += PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[2] *
          PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f * 0.0;

        /* Product: '<S243>/Product2' incorporates:
         *  UnaryMinus: '<S243>/Unary Minus'
         */
        rtb_Product2_a = -rtb_Gain_e * rtb_Gain3_c;

        /* Sum: '<S238>/Sum' incorporates:
         *  Constant: '<S238>/(Ld-Lq)_Ld'
         *  Constant: '<S238>/R_Ld'
         *  Delay: '<S231>/Delay1'
         *  Delay: '<S58>/Delay'
         *  Product: '<S238>/Product1'
         *  Product: '<S238>/Product2'
         *  Product: '<S238>/Product4'
         *  UnaryMinus: '<S238>/Unary Minus'
         *  UnaryMinus: '<S238>/Unary Minus1'
         */
        rtb_Product1_o = -(PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[3] *
                           PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f) * 0.0 +
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[2] * -20.555555555555554;

        /* Gain: '<S383>/Gain3' incorporates:
         *  Product: '<S243>/Product1'
         *  Product: '<S243>/Product3'
         *  Sum: '<S243>/Sum1'
         */
        rtb_Gain3_c = rtb_Product1_o * rtb_Gain_e - rtb_Gain3_c;

        /* Delay: '<S235>/Delay' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0] = 0.0;
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1] = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE = 0U;

        /* Sum: '<S235>/Sum2' incorporates:
         *  Delay: '<S235>/Delay'
         *  Sum: '<S235>/Sum'
         */
        Merge_i = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0];
        tmp_5 = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1];

        /* Gain: '<S235>/Gain2' incorporates:
         *  Delay: '<S231>/Delay1'
         *  Delay: '<S235>/Delay'
         *  Gain: '<S235>/Gain1'
         *  Product: '<S240>/Product1'
         *  Product: '<S242>/Product3'
         *  Product: '<S243>/Product'
         *  Sum: '<S235>/Sum'
         *  Sum: '<S235>/Sum2'
         *  Sum: '<S236>/Sum'
         *  Sum: '<S242>/Sum1'
         *  Sum: '<S243>/Sum'
         *  UnaryMinus: '<S239>/Unary Minus'
         *  UnaryMinus: '<S240>/Unary Minus'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0] = ((((-(rtb_Add3 *
          PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f) - rtb_Gain4_i) - (rtb_Product2_a
          - rtb_Product1_o)) - rtb_Add2) * 5.0E-5 + Merge_i) * 0.972972972972973;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1] = ((((rtb_Add_oj -
          (-rtb_Gain4_i_tmp * rtb_Gain_e + rtb_Gain4_i_tmp_0)) - rtb_Gain3_c) -
          rtb_Add1_f) * 5.0E-5 + tmp_5) * 0.972972972972973;

        /* Delay: '<S248>/Delay' incorporates:
         *  Constant: '<S233>/IC'
         */
        if (PMSM_to_BLDC_mod1_DW.icLoad) {
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[0] = 0.0;
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[1] = 0.0;
        }

        /* Sum: '<S248>/Add1' incorporates:
         *  Constant: '<S231>/V_PU'
         *  Delay: '<S235>/Delay'
         *  Delay: '<S248>/Delay'
         *  Product: '<S231>/Product'
         *  Product: '<S248>/Product'
         *  Product: '<S248>/Product1'
         *  Sum: '<S235>/Sum1'
         */
        rtb_Add1[0] = (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0] + rtb_Integrator_l)
          * 0.020833333333333332 * 0.70204348915944692 +
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[0] * 0.29795651084055308;
        rtb_Add1[1] = (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1] + rtb_Add3) *
          0.020833333333333332 * 0.70204348915944692 + 0.29795651084055308 *
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[1];

        /* Relay: '<S249>/AlphaRelay' */
        PMSM_to_BLDC_mod1_DW.AlphaRelay_Mode = ((rtb_Add1[0] >= 0.02) ||
          ((!(rtb_Add1[0] <= -0.02)) && PMSM_to_BLDC_mod1_DW.AlphaRelay_Mode));

        /* Relay: '<S249>/BetaRelay' */
        PMSM_to_BLDC_mod1_DW.BetaRelay_Mode = ((rtb_Add1[1] >= 0.02) ||
          ((!(rtb_Add1[1] <= -0.02)) && PMSM_to_BLDC_mod1_DW.BetaRelay_Mode));

        /* Outputs for Triggered SubSystem: '<S249>/Dir_Sense' incorporates:
         *  TriggerPort: '<S251>/Trigger'
         */
        /* If: '<S249>/If' incorporates:
         *  Relay: '<S249>/AlphaRelay'
         *  SwitchCase: '<S258>/Switch Case'
         */
        if (rtsiIsModeUpdateTimeStep(&PMSM_to_BLDC_mod1_M->solverInfo)) {
          if (PMSM_to_BLDC_mod1_DW.AlphaRelay_Mode &&
              (PMSM_to_BLDC_mod1_PrevZCX.Dir_Sense_Trig_ZCE != POS_ZCSIG)) {
            /* Switch: '<S251>/Switch' incorporates:
             *  Relay: '<S249>/BetaRelay'
             */
            if (PMSM_to_BLDC_mod1_DW.BetaRelay_Mode) {
              /* Switch: '<S251>/Switch' incorporates:
               *  Constant: '<S251>/Constant'
               */
              PMSM_to_BLDC_mod1_B.Switch = -1;
            } else {
              /* Switch: '<S251>/Switch' incorporates:
               *  Constant: '<S251>/Constant1'
               */
              PMSM_to_BLDC_mod1_B.Switch = 1;
            }

            /* End of Switch: '<S251>/Switch' */
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

        /* End of Outputs for SubSystem: '<S249>/Dir_Sense' */
        if (PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem == 0) {
          /* Outputs for IfAction SubSystem: '<S249>/Subsystem2' incorporates:
           *  ActionPort: '<S252>/Action Port'
           */
          /* UnaryMinus: '<S252>/Unary Minus' */
          rtb_Add1_f = -rtb_Add1[0];

          /* SignalConversion generated from: '<S252>/SigmaBeta' */
          rtb_Gain_e = rtb_Add1[1];

          /* End of Outputs for SubSystem: '<S249>/Subsystem2' */
        } else {
          /* Outputs for IfAction SubSystem: '<S249>/Subsystem3' incorporates:
           *  ActionPort: '<S253>/Action Port'
           */
          /* UnaryMinus: '<S253>/Unary Minus' */
          rtb_Gain_e = -rtb_Add1[1];

          /* SignalConversion generated from: '<S253>/SigmaAlpha' */
          rtb_Add1_f = rtb_Add1[0];

          /* End of Outputs for SubSystem: '<S249>/Subsystem3' */
        }

        /* End of If: '<S249>/If' */

        /* SwitchCase: '<S258>/Switch Case' */
        if (PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem == 0) {
          /* Outputs for IfAction SubSystem: '<S258>/If Action Subsystem' incorporates:
           *  ActionPort: '<S352>/Action Port'
           */
          /* Merge: '<S258>/Merge' incorporates:
           *  Constant: '<S258>/Constant'
           *  SignalConversion generated from: '<S352>/In1'
           *  SignalConversion generated from: '<S352>/Out1'
           */
          PMSM_to_BLDC_mod1_B.Merge[0] = 0.0;
          PMSM_to_BLDC_mod1_B.Merge[1] = 0.0;

          /* End of Outputs for SubSystem: '<S258>/If Action Subsystem' */
        } else {
          /* Outputs for IfAction SubSystem: '<S258>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S353>/Action Port'
           */
          /* Merge: '<S258>/Merge' incorporates:
           *  SignalConversion generated from: '<S353>/In1'
           */
          PMSM_to_BLDC_mod1_B.Merge[0] = rtb_Add1_f;
          PMSM_to_BLDC_mod1_B.Merge[1] = rtb_Gain_e;

          /* End of Outputs for SubSystem: '<S258>/If Action Subsystem1' */
        }

        /* Product: '<S255>/Product' */
        rtb_Gain_e = PMSM_to_BLDC_mod1_B.Merge[0] * PMSM_to_BLDC_mod1_B.Merge[0];

        /* Gain: '<S383>/Gain3' incorporates:
         *  Product: '<S255>/Product1'
         */
        rtb_Gain3_c = PMSM_to_BLDC_mod1_B.Merge[1] * PMSM_to_BLDC_mod1_B.Merge[1];

        /* Sum: '<S255>/Sum' */
        PMSM_to_BLDC_mod1_B.Sum = rtb_Gain_e + rtb_Gain3_c;

        /* RelationalOperator: '<S263>/Compare' incorporates:
         *  Constant: '<S263>/Constant'
         */
        PMSM_to_BLDC_mod1_B.Compare = (PMSM_to_BLDC_mod1_B.Sum > 0.0);
      }

      /* If: '<S255>/If' */
      rtPrevAction = PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_g;

      /* If: '<S221>/If' incorporates:
       *  If: '<S195>/If'
       *  If: '<S255>/If'
       *  If: '<S360>/If'
       *  SimscapeExecutionBlock: '<S416>/OUTPUT_1_0'
       *  SimscapeExecutionBlock: '<S416>/STATE_1'
       *  SwitchCase: '<S257>/Switch Case'
       */
      tmp_3 = rtsiIsModeUpdateTimeStep(&PMSM_to_BLDC_mod1_M->solverInfo);

      /* If: '<S255>/If' */
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
        /* Outputs for IfAction SubSystem: '<S255>/Subsystem' incorporates:
         *  ActionPort: '<S265>/Action Port'
         */
        /* Sqrt: '<S265>/Sqrt' */
        Merge_i = sqrt(PMSM_to_BLDC_mod1_B.Sum);

        /* Merge: '<S255>/Merge1' incorporates:
         *  Product: '<S265>/Divide'
         *  SignalConversion generated from: '<S265>/Out2'
         */
        rtb_Add1_f = 1.0 / Merge_i * PMSM_to_BLDC_mod1_B.Merge[1];

        /* Merge: '<S255>/Merge' incorporates:
         *  Product: '<S265>/Divide1'
         *  SignalConversion generated from: '<S265>/Out1'
         */
        Merge_i = PMSM_to_BLDC_mod1_B.Merge[0] / Merge_i;

        /* End of Outputs for SubSystem: '<S255>/Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S255>/If Action Subsystem' incorporates:
         *  ActionPort: '<S264>/Action Port'
         */
        /* Merge: '<S255>/Merge' incorporates:
         *  DataTypeConversion: '<S264>/Data Type Conversion'
         *  SignalConversion generated from: '<S264>/Out1'
         */
        Merge_i = PMSM_to_BLDC_mod1_B.Merge[0];

        /* Merge: '<S255>/Merge1' incorporates:
         *  DataTypeConversion: '<S264>/Data Type Conversion1'
         *  SignalConversion generated from: '<S264>/Out2'
         */
        rtb_Add1_f = PMSM_to_BLDC_mod1_B.Merge[1];

        /* End of Outputs for SubSystem: '<S255>/If Action Subsystem' */
      }

      if (tmp_2) {
        /* SwitchCase: '<S257>/Switch Case' incorporates:
         *  Delay: '<S348>/Delay'
         */
        if (tmp_3) {
          rtAction = 1;
          PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem_n = 1;
        } else {
          rtAction = PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem_n;
        }

        if (rtAction == 0) {
          /* Outputs for IfAction SubSystem: '<S257>/IntegralMethod' incorporates:
           *  ActionPort: '<S321>/Action Port'
           */
          /* Delay: '<S338>/Delay' */
          if (PMSM_to_BLDC_mod1_DW.icLoad_bd) {
            /* Sum: '<S338>/Add1' incorporates:
             *  Constant: '<S332>/IC'
             */
            PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av = 0.0;
          }

          /* Sum: '<S338>/Add1' incorporates:
           *  Delay: '<S338>/Delay'
           *  Product: '<S338>/Product'
           *  Product: '<S338>/Product1'
           *  Switch: '<S338>/Switch'
           */
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av = rtb_Add1_f *
            0.95650500031643548 + 0.043494999683564517 *
            PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av;

          /* Delay: '<S335>/Delay1' */
          if (PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_p == POS_ZCSIG) {
            PMSM_to_BLDC_mod1_DW.Delay1_DSTATE = 0.0;
          }

          PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_p = 0U;

          /* Delay: '<S335>/Delay' */
          if (PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_h == POS_ZCSIG) {
            PMSM_to_BLDC_mod1_DW.Delay_DSTATE_f = 0.0;
          }

          PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_h = 0U;

          /* Sum: '<S335>/Sum1' incorporates:
           *  Constant: '<S318>/I1Cnst'
           *  Constant: '<S318>/I2Cnst'
           *  Delay: '<S335>/Delay'
           *  Delay: '<S335>/Delay1'
           *  Product: '<S335>/Product'
           *  Product: '<S335>/Product1'
           *  Sum: '<S335>/Sum'
           */
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_f =
            (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av +
             PMSM_to_BLDC_mod1_DW.Delay1_DSTATE) * 2.4945142765920684E-5 +
            PMSM_to_BLDC_mod1_DW.Delay_DSTATE_f * 0.99561142127365465;

          /* Delay: '<S341>/Delay' */
          if (PMSM_to_BLDC_mod1_DW.icLoad_k) {
            /* Sum: '<S341>/Add1' incorporates:
             *  Constant: '<S333>/IC'
             */
            PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d = 0.0;
          }

          /* Sum: '<S341>/Add1' incorporates:
           *  Delay: '<S341>/Delay'
           *  Product: '<S341>/Product'
           *  Product: '<S341>/Product1'
           *  Switch: '<S341>/Switch'
           */
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d = Merge_i * 0.95650500031643548 +
            0.043494999683564517 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d;

          /* Delay: '<S334>/Delay1' */
          if (PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_i == POS_ZCSIG) {
            PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_o = 0.0;
          }

          PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_i = 0U;

          /* Delay: '<S334>/Delay' */
          if (PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_k == POS_ZCSIG) {
            PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i = 0.0;
          }

          PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_k = 0U;

          /* Sum: '<S334>/Sum1' incorporates:
           *  Constant: '<S318>/I1Cnst'
           *  Constant: '<S318>/I2Cnst'
           *  Delay: '<S334>/Delay'
           *  Delay: '<S334>/Delay1'
           *  Product: '<S334>/Product'
           *  Product: '<S334>/Product1'
           *  Sum: '<S334>/Sum'
           */
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i =
            (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d +
             PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_o) * 2.4945142765920684E-5 +
            PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i * 0.99561142127365465;

          /* Math: '<S321>/Math Function' incorporates:
           *  Delay: '<S334>/Delay'
           *  Delay: '<S335>/Delay'
           *  Product: '<S321>/Product'
           *  Product: '<S321>/Product1'
           *  Sum: '<S321>/Sum'
           *
           * About '<S321>/Math Function':
           *  Operator: reciprocal
           */
          rtb_Add_oj = 1.0 / (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_f * Merge_i -
                              PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i * rtb_Add1_f);

          /* Switch: '<S321>/Switch1' incorporates:
           *  Abs: '<S321>/Abs'
           */
          if (fabs(rtb_Add_oj) > 87964.5943005142) {
            /* Merge: '<S257>/Merge' incorporates:
             *  Constant: '<S321>/Constant'
             */
            rtb_Add_oj = 0.0;
          }

          /* End of Switch: '<S321>/Switch1' */

          /* Update for Delay: '<S338>/Delay' */
          PMSM_to_BLDC_mod1_DW.icLoad_bd = false;

          /* Update for Delay: '<S335>/Delay1' */
          PMSM_to_BLDC_mod1_DW.Delay1_DSTATE =
            PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av;

          /* Update for Delay: '<S341>/Delay' */
          PMSM_to_BLDC_mod1_DW.icLoad_k = false;

          /* Update for Delay: '<S334>/Delay1' */
          PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_o =
            PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d;

          /* End of Outputs for SubSystem: '<S257>/IntegralMethod' */
        } else {
          /* Outputs for IfAction SubSystem: '<S257>/OptimizedDifferentiationMethod' incorporates:
           *  ActionPort: '<S324>/Action Port'
           */
          if (PMSM_to_BLDC_mod1_DW.icLoad_b1) {
            /* Sum: '<S348>/Add1' incorporates:
             *  Constant: '<S344>/IC'
             *  Delay: '<S348>/Delay'
             */
            PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aa = 0.0;
          }

          /* Sum: '<S348>/Add1' incorporates:
           *  Delay: '<S348>/Delay'
           *  Product: '<S348>/Product'
           *  Product: '<S348>/Product1'
           *  Switch: '<S348>/Switch'
           */
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aa = rtb_Add1_f *
            0.95650500031643548 + 0.043494999683564517 *
            PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aa;

          /* Product: '<S343>/Product' incorporates:
           *  Constant: '<S318>/OD1Cnst'
           */
          rtb_Product_fc = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aa *
            2.1991148575128554E+6;

          /* Delay: '<S343>/Delay2' */
          if (PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE == POS_ZCSIG) {
            PMSM_to_BLDC_mod1_DW.Delay2_DSTATE = 0.0;
          }

          PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE = 0U;

          /* Delay: '<S343>/Delay3' */
          if (PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE == POS_ZCSIG) {
            PMSM_to_BLDC_mod1_DW.Delay3_DSTATE = 0.0;
          }

          PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE = 0U;

          /* Product: '<S343>/Product1' incorporates:
           *  Constant: '<S318>/OD2Cnst'
           *  Delay: '<S343>/Delay2'
           *  Delay: '<S343>/Delay3'
           *  Sum: '<S343>/Sum1'
           */
          PMSM_to_BLDC_mod1_DW.Delay3_DSTATE =
            ((PMSM_to_BLDC_mod1_DW.Delay3_DSTATE + rtb_Product_fc) -
             PMSM_to_BLDC_mod1_DW.Delay2_DSTATE) * 0.0090126024492556654;

          /* Delay: '<S342>/Delay2' */
          if (PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE_p == POS_ZCSIG) {
            PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_h = 0.0;
          }

          PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE_p = 0U;
          rtb_Add_oj = PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_h;

          /* Delay: '<S342>/Delay3' */
          if (PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE_k == POS_ZCSIG) {
            PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_p = 0.0;
          }

          PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE_k = 0U;

          /* Delay: '<S351>/Delay' */
          if (PMSM_to_BLDC_mod1_DW.icLoad_c) {
            /* Sum: '<S351>/Add1' incorporates:
             *  Constant: '<S345>/IC'
             */
            PMSM_to_BLDC_mod1_DW.Delay_DSTATE_l = 0.0;
          }

          /* Sum: '<S351>/Add1' incorporates:
           *  Delay: '<S351>/Delay'
           *  Product: '<S351>/Product'
           *  Product: '<S351>/Product1'
           *  Switch: '<S351>/Switch'
           */
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_l = Merge_i * 0.95650500031643548 +
            0.043494999683564517 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_l;

          /* Product: '<S342>/Product' incorporates:
           *  Constant: '<S318>/OD1Cnst'
           *  Delay: '<S342>/Delay2'
           */
          PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_h =
            PMSM_to_BLDC_mod1_DW.Delay_DSTATE_l * 2.1991148575128554E+6;

          /* Product: '<S342>/Product1' incorporates:
           *  Constant: '<S318>/OD2Cnst'
           *  Delay: '<S342>/Delay2'
           *  Delay: '<S342>/Delay3'
           *  Sum: '<S342>/Sum1'
           */
          PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_p =
            ((PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_p +
              PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_h) - rtb_Add_oj) *
            0.0090126024492556654;

          /* Merge: '<S257>/Merge' incorporates:
           *  Delay: '<S342>/Delay3'
           *  Delay: '<S343>/Delay3'
           *  Product: '<S324>/Product'
           *  Product: '<S324>/Product1'
           *  Sum: '<S324>/Sum'
           */
          rtb_Add_oj = PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_p * rtb_Add1_f -
            PMSM_to_BLDC_mod1_DW.Delay3_DSTATE * Merge_i;

          /* Update for Delay: '<S348>/Delay' */
          PMSM_to_BLDC_mod1_DW.icLoad_b1 = false;

          /* Update for Delay: '<S343>/Delay2' */
          PMSM_to_BLDC_mod1_DW.Delay2_DSTATE = rtb_Product_fc;

          /* Update for Delay: '<S351>/Delay' */
          PMSM_to_BLDC_mod1_DW.icLoad_c = false;

          /* End of Outputs for SubSystem: '<S257>/OptimizedDifferentiationMethod' */
        }

        /* Gain: '<S383>/Gain3' incorporates:
         *  Constant: '<S257>/SpdFilterCoeff'
         *  Constant: '<S319>/One'
         *  Sum: '<S319>/Sum'
         */
        rtb_Gain3_c = 0.99530971347415453;

        /* Switch: '<S319>/Switch1' */
        rtb_Product_j_idx_1 = rtb_Gain3_c;

        /* Delay: '<S331>/Delay' incorporates:
         *  Constant: '<S319>/IC'
         */
        if (PMSM_to_BLDC_mod1_DW.icLoad_f) {
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_a = 0.0;
        }

        /* Gain: '<S383>/Gain3' incorporates:
         *  Delay: '<S331>/Delay'
         *  Product: '<S331>/Product1'
         */
        rtb_Gain3_c = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_a;
        rtb_Gain3_c *= rtb_Product_j_idx_1;

        /* Sum: '<S331>/Add1' incorporates:
         *  Product: '<S331>/Product'
         *  Switch: '<S331>/Switch'
         */
        rtb_Add1_e = rtb_Add_oj * 0.0046902865258454489 + rtb_Gain3_c;

        /* Delay: '<S355>/Delay' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_a == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_a = 0U;

        /* If: '<S360>/If' incorporates:
         *  Constant: '<S362>/Constant'
         *  DataTypeConversion: '<S355>/Data Type Conversion3'
         *  Delay: '<S355>/Delay'
         *  RelationalOperator: '<S362>/Compare'
         */
        if (tmp_3) {
          PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_e = (int8_T)!((real32_T)
            PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj < 0.0F);
        }

        if (PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_e == 0) {
          /* Outputs for IfAction SubSystem: '<S360>/If Action Subsystem' incorporates:
           *  ActionPort: '<S363>/Action Port'
           */
          /* DataTypeConversion: '<S363>/Convert_uint16' incorporates:
           *  DataTypeConversion: '<S355>/Data Type Conversion3'
           *  Delay: '<S355>/Delay'
           */
          rtb_Saturation_or = floorf((real32_T)
            PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj);
          if (rtIsNaNF(rtb_Saturation_or) || rtIsInfF(rtb_Saturation_or)) {
            rtb_Saturation_or = 0.0F;
          } else {
            rtb_Saturation_or = fmodf(rtb_Saturation_or, 65536.0F);
          }

          /* Sum: '<S363>/Sum' incorporates:
           *  DataTypeConversion: '<S355>/Data Type Conversion3'
           *  DataTypeConversion: '<S363>/Convert_back'
           *  DataTypeConversion: '<S363>/Convert_uint16'
           *  Delay: '<S355>/Delay'
           */
          rtb_indexing = (real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj -
            (real32_T)(rtb_Saturation_or < 0.0F ? (int32_T)(int16_T)-(int16_T)
                       (uint16_T)-rtb_Saturation_or : (int32_T)(int16_T)
                       (uint16_T)rtb_Saturation_or);

          /* End of Outputs for SubSystem: '<S360>/If Action Subsystem' */
        } else {
          /* Outputs for IfAction SubSystem: '<S360>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S364>/Action Port'
           */
          /* DataTypeConversion: '<S364>/Convert_uint16' incorporates:
           *  DataTypeConversion: '<S355>/Data Type Conversion3'
           *  Delay: '<S355>/Delay'
           */
          rtb_Saturation_or = truncf((real32_T)
            PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj);
          if (rtIsNaNF(rtb_Saturation_or) || rtIsInfF(rtb_Saturation_or)) {
            rtb_Saturation_or = 0.0F;
          } else {
            rtb_Saturation_or = fmodf(rtb_Saturation_or, 65536.0F);
          }

          /* Sum: '<S364>/Sum' incorporates:
           *  DataTypeConversion: '<S355>/Data Type Conversion3'
           *  DataTypeConversion: '<S364>/Convert_back'
           *  DataTypeConversion: '<S364>/Convert_uint16'
           *  Delay: '<S355>/Delay'
           */
          rtb_indexing = (real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj -
            (real32_T)(rtb_Saturation_or < 0.0F ? (int32_T)(int16_T)-(int16_T)
                       (uint16_T)-rtb_Saturation_or : (int32_T)(int16_T)
                       (uint16_T)rtb_Saturation_or);

          /* End of Outputs for SubSystem: '<S360>/If Action Subsystem1' */
        }

        /* Gain: '<S358>/indexing' */
        rtb_indexing *= 800.0F;

        /* DataTypeConversion: '<S358>/Get_Integer' */
        rtb_Saturation_or = truncf(rtb_indexing);
        if (rtIsNaNF(rtb_Saturation_or) || rtIsInfF(rtb_Saturation_or)) {
          rtb_Saturation_or = 0.0F;
        } else {
          rtb_Saturation_or = fmodf(rtb_Saturation_or, 65536.0F);
        }

        status = (uint16_T)(rtb_Saturation_or < 0.0F ? (int32_T)(uint16_T)
                            -(int16_T)(uint16_T)-rtb_Saturation_or : (int32_T)
                            (uint16_T)rtb_Saturation_or);

        /* End of DataTypeConversion: '<S358>/Get_Integer' */

        /* Sum: '<S358>/Sum2' incorporates:
         *  DataTypeConversion: '<S358>/Data Type Conversion1'
         */
        rtb_Saturation_or = rtb_indexing - (real32_T)status;

        /* Sum: '<S250>/Sum' incorporates:
         *  Constant: '<S358>/offset'
         *  Constant: '<S358>/sine_table_values'
         *  DataTypeConversion: '<S355>/Data Type Conversion'
         *  DataTypeConversion: '<S355>/Data Type Conversion1'
         *  Product: '<S250>/Product'
         *  Product: '<S250>/Product1'
         *  Product: '<S359>/Product'
         *  Product: '<S359>/Product1'
         *  Selector: '<S358>/Lookup'
         *  Sum: '<S358>/Sum'
         *  Sum: '<S359>/Sum3'
         *  Sum: '<S359>/Sum4'
         *  Sum: '<S359>/Sum5'
         *  Sum: '<S359>/Sum6'
         */
        rtb_Gain_e = ((PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[(int32_T)
                       (status + 201U)] -
                       PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[(int32_T)
                       (status + 200U)]) * rtb_Saturation_or +
                      PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[(int32_T)
                      (status + 200U)]) * Merge_i -
          ((PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[(int32_T)(status +
             1U)] - PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[status]) *
           rtb_Saturation_or +
           PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[status]) *
          rtb_Add1_f;

        /* DiscreteIntegrator: '<S300>/Integrator' */
        if (PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState != 0) {
          PMSM_to_BLDC_mod1_DW.Integrator_DSTATE = 0.0;
        }

        /* DiscreteIntegrator: '<S300>/Integrator' incorporates:
         *  Gain: '<S297>/Integral Gain'
         */
        PMSM_to_BLDC_mod1_B.Integrator = 5.0 * rtb_Gain_e +
          PMSM_to_BLDC_mod1_DW.Integrator_DSTATE;

        /* Sum: '<S250>/Sum1' incorporates:
         *  Gain: '<S305>/Proportional Gain'
         *  Sum: '<S309>/Sum'
         */
        rtb_Gain_e = (250.0 * rtb_Gain_e + PMSM_to_BLDC_mod1_B.Integrator) +
          rtb_Add1_e;

        /* Gain: '<S383>/Gain3' incorporates:
         *  Gain: '<S355>/Gain'
         *  Product: '<S356>/Product'
         */
        rtb_Gain3_c = 7.9577471545947669E-6 * rtb_Gain_e;

        /* Delay: '<S356>/Delay' incorporates:
         *  Constant: '<S356>/InputGain'
         *  Constant: '<S356>/Offset'
         *  Product: '<S356>/Product1'
         *  Sum: '<S356>/Sum1'
         */
        if (PMSM_to_BLDC_mod1_DW.icLoad_a) {
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_ai = 0.0 - rtb_Gain3_c;
        }

        /* Sum: '<S356>/Sum' incorporates:
         *  Delay: '<S356>/Delay'
         */
        rtb_Switch2 = rtb_Gain3_c + PMSM_to_BLDC_mod1_DW.Delay_DSTATE_ai;

        /* Switch: '<S356>/Switch1' */
        if (!(rtb_Switch2 > 0.0)) {
          /* Sum: '<S356>/Sum' incorporates:
           *  Constant: '<S356>/Bias1'
           *  Sum: '<S356>/Sum2'
           */
          rtb_Switch2++;
        }

        /* End of Switch: '<S356>/Switch1' */

        /* Switch: '<S356>/Switch2' */
        if (rtb_Switch2 >= 1.0) {
          /* Sum: '<S356>/Sum' incorporates:
           *  Sum: '<S356>/Sum3'
           *  Switch: '<S356>/Switch2'
           */
          rtb_Switch2--;
        }

        /* End of Switch: '<S356>/Switch2' */

        /* Product: '<S356>/Product2' incorporates:
         *  Delay: '<S355>/Delay'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj = rtb_Switch2;

        /* Gain: '<S383>/Gain3' incorporates:
         *  Constant: '<S70>/Constant'
         *  DataTypeConversion: '<S63>/Data Type Conversion'
         *  Delay: '<S355>/Delay'
         *  Gain: '<S250>/PositionGain'
         *  Math: '<S70>/Mod'
         */
        rtb_Gain3_c = (real32_T)(6.2831853071795862 *
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj);
        rtb_Gain3_c = rt_modd_snf(rtb_Gain3_c, 6.282);

        /* Gain: '<S221>/convert_pu' */
        rtb_Add_oj = 0.15915494309189535 * rtb_Gain3_c;

        /* If: '<S221>/If' incorporates:
         *  Constant: '<S223>/Constant'
         *  RelationalOperator: '<S223>/Compare'
         */
        if (tmp_3) {
          PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_c = (int8_T)!(rtb_Add_oj < 0.0);
        }

        if (PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_c == 0) {
          /* Outputs for IfAction SubSystem: '<S221>/If Action Subsystem' incorporates:
           *  ActionPort: '<S224>/Action Port'
           */
          rtb_Gain4_i = PMSM_to_BLDC__IfActionSubsystem(rtb_Add_oj);

          /* End of Outputs for SubSystem: '<S221>/If Action Subsystem' */
        } else {
          /* Outputs for IfAction SubSystem: '<S221>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S225>/Action Port'
           */
          rtb_Gain4_i = PMSM_to_BLDC_IfActionSubsystem1(rtb_Add_oj);

          /* End of Outputs for SubSystem: '<S221>/If Action Subsystem1' */
        }

        /* Gain: '<S383>/Gain4' incorporates:
         *  Gain: '<S219>/indexing'
         */
        rtb_Gain4_i *= 800.0;

        /* DataTypeConversion: '<S219>/Get_Integer' */
        Merge_i = trunc(rtb_Gain4_i);
        if (rtIsNaN(Merge_i) || rtIsInf(Merge_i)) {
          Merge_i = 0.0;
        } else {
          Merge_i = fmod(Merge_i, 65536.0);
        }

        status = (uint16_T)(Merge_i < 0.0 ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-Merge_i : (int32_T)(uint16_T)Merge_i);

        /* End of DataTypeConversion: '<S219>/Get_Integer' */

        /* Sum: '<S219>/Sum2' incorporates:
         *  DataTypeConversion: '<S219>/Data Type Conversion1'
         */
        rtb_Product1_o = rtb_Gain4_i - (real_T)status;

        /* Sum: '<S220>/Sum4' incorporates:
         *  Constant: '<S219>/offset'
         *  Constant: '<S219>/sine_table_values'
         *  Product: '<S220>/Product'
         *  Selector: '<S219>/Lookup'
         *  Sum: '<S219>/Sum'
         *  Sum: '<S220>/Sum3'
         */
        rtb_Add_oj = (PMSM_to_BLDC_mod1_ConstP.pooled16[(int32_T)(status + 1U)]
                      - PMSM_to_BLDC_mod1_ConstP.pooled16[status]) *
          rtb_Product1_o + PMSM_to_BLDC_mod1_ConstP.pooled16[status];

        /* Gain: '<S383>/Gain4' incorporates:
         *  Constant: '<S219>/offset'
         *  Constant: '<S219>/sine_table_values'
         *  Product: '<S220>/Product1'
         *  Selector: '<S219>/Lookup'
         *  Sum: '<S219>/Sum'
         *  Sum: '<S220>/Sum5'
         */
        rtb_Gain4_i = PMSM_to_BLDC_mod1_ConstP.pooled16[(int32_T)(status + 201U)]
          - PMSM_to_BLDC_mod1_ConstP.pooled16[(int32_T)(status + 200U)];
        rtb_Gain4_i *= rtb_Product1_o;

        /* Sum: '<S220>/Sum6' incorporates:
         *  Constant: '<S219>/offset'
         *  Constant: '<S219>/sine_table_values'
         *  Selector: '<S219>/Lookup'
         *  Sum: '<S219>/Sum'
         *  Sum: '<S220>/Sum5'
         */
        rtb_Product1_o = PMSM_to_BLDC_mod1_ConstP.pooled16[(int32_T)(status +
          200U)] + rtb_Gain4_i;

        /* Outputs for Atomic SubSystem: '<S217>/Two inputs CRL' */
        /* Gain: '<S383>/Gain4' incorporates:
         *  Product: '<S227>/acos'
         *  Product: '<S227>/bsin'
         *  Sum: '<S227>/sum_Ds'
         */
        rtb_Gain4_i = rtb_uabc3 * rtb_Product1_o + rtb_one_by_sqrt3_ *
          rtb_Add_oj;

        /* AlgorithmDescriptorDelegate generated from: '<S227>/a16' incorporates:
         *  Switch: '<S228>/Switch'
         */
        rtb_Product_fc = rtb_Gain4_i;

        /* AlgorithmDescriptorDelegate generated from: '<S227>/a16' incorporates:
         *  Product: '<S227>/asin'
         *  Product: '<S227>/bcos'
         *  Sum: '<S227>/sum_Qs'
         */
        PMSM_to_BLDC_mod1_B.algDD_o2 = rtb_one_by_sqrt3_ * rtb_Product1_o -
          rtb_uabc3 * rtb_Add_oj;

        /* End of Outputs for SubSystem: '<S217>/Two inputs CRL' */

        /* DiscreteIntegrator: '<S170>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b =
          PMSM_to_BLDC_mod1_ConstB.Constant3_n;

        /* Sum: '<S179>/Sum' incorporates:
         *  Constant: '<S77>/Constant'
         *  DiscreteIntegrator: '<S170>/Integrator'
         *  Product: '<S175>/PProd Out'
         */
        rtb_Product1_o = rtb_Gain4_i * 22.608 +
          PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b;

        /* Saturate: '<S177>/Saturation' */
        if (rtb_Product1_o > 1.0) {
          rtb_Product_j_idx_1 = 1.0;
        } else if (rtb_Product1_o < -1.0) {
          rtb_Product_j_idx_1 = -1.0;
        } else {
          rtb_Product_j_idx_1 = rtb_Product1_o;
        }

        /* End of Saturate: '<S177>/Saturation' */

        /* Saturate: '<S60>/Saturation' incorporates:
         *  Delay: '<S55>/Delay1'
         */
        if (PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx > 600.0F) {
          rtb_Saturation_or = 600.0F;
        } else if (PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx < -600.0F) {
          rtb_Saturation_or = -600.0F;
        } else {
          rtb_Saturation_or = PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx;
        }

        /* Sum: '<S60>/Add' incorporates:
         *  Constant: '<S55>/Constant'
         *  Saturate: '<S60>/Saturation'
         */
        rtb_Add_oj = 600.0 - rtb_Saturation_or;

        /* Saturate: '<S60>/Saturation' incorporates:
         *  Delay: '<S55>/Delay1'
         */
        if (PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx > 600.0F) {
          rtb_Saturation_or = 600.0F;
        } else if (PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx < -600.0F) {
          rtb_Saturation_or = -600.0F;
        } else {
          rtb_Saturation_or = PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx;
        }

        /* Gain: '<S460>/Proportional Gain' incorporates:
         *  Constant: '<S55>/Constant'
         *  Saturate: '<S60>/Saturation'
         *  Sum: '<S60>/Add'
         */
        PMSM_to_BLDC_mod1_B.ProportionalGain = (600.0 - rtb_Saturation_or) *
          0.31663865546218484;
      }

      /* Sum: '<S76>/Sum' incorporates:
       *  Integrator: '<S455>/Integrator'
       *  Sum: '<S464>/Sum'
       */
      rtb_uabc3 = PMSM_to_BLDC_mod1_B.algDD_o2 -
        (PMSM_to_BLDC_mod1_B.ProportionalGain +
         PMSM_to_BLDC_mod1_X.Integrator_CSTATE);
      if (tmp_2) {
        /* DiscreteIntegrator: '<S115>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n =
          PMSM_to_BLDC_mod1_ConstB.Constant3;

        /* Sum: '<S124>/Sum' incorporates:
         *  Constant: '<S76>/Constant'
         *  DiscreteIntegrator: '<S115>/Integrator'
         *  Product: '<S120>/PProd Out'
         */
        rtb_DeadZone = rtb_uabc3 * 22.608 +
          PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n;

        /* Saturate: '<S122>/Saturation' */
        if (rtb_DeadZone > 1.0) {
          rtb_Saturation_k = 1.0;
        } else if (rtb_DeadZone < -1.0) {
          rtb_Saturation_k = -1.0;
        } else {
          rtb_Saturation_k = rtb_DeadZone;
        }

        /* End of Saturate: '<S122>/Saturation' */

        /* Gain: '<S195>/convert_pu' */
        rtb_convert_pu_i = 0.15915494309189535 * rtb_Gain3_c;

        /* If: '<S195>/If' incorporates:
         *  Constant: '<S197>/Constant'
         *  RelationalOperator: '<S197>/Compare'
         */
        if (tmp_3) {
          PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_m = (int8_T)!(rtb_convert_pu_i
            < 0.0);
        }

        if (PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_m == 0) {
          /* Outputs for IfAction SubSystem: '<S195>/If Action Subsystem' incorporates:
           *  ActionPort: '<S198>/Action Port'
           */
          rtb_Gain3_c = PMSM_to_BLDC__IfActionSubsystem(rtb_convert_pu_i);

          /* End of Outputs for SubSystem: '<S195>/If Action Subsystem' */
        } else {
          /* Outputs for IfAction SubSystem: '<S195>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S199>/Action Port'
           */
          rtb_Gain3_c = PMSM_to_BLDC_IfActionSubsystem1(rtb_convert_pu_i);

          /* End of Outputs for SubSystem: '<S195>/If Action Subsystem1' */
        }

        /* Gain: '<S383>/Gain3' incorporates:
         *  Gain: '<S193>/indexing'
         */
        rtb_Gain3_c *= 800.0;

        /* DataTypeConversion: '<S193>/Get_Integer' */
        Merge_i = trunc(rtb_Gain3_c);
        if (rtIsNaN(Merge_i) || rtIsInf(Merge_i)) {
          Merge_i = 0.0;
        } else {
          Merge_i = fmod(Merge_i, 65536.0);
        }

        status = (uint16_T)(Merge_i < 0.0 ? (int32_T)(uint16_T)-(int16_T)
                            (uint16_T)-Merge_i : (int32_T)(uint16_T)Merge_i);

        /* End of DataTypeConversion: '<S193>/Get_Integer' */

        /* Sum: '<S193>/Sum2' incorporates:
         *  DataTypeConversion: '<S193>/Data Type Conversion1'
         */
        rtb_Add1_f = rtb_Gain3_c - (real_T)status;

        /* Sum: '<S194>/Sum4' incorporates:
         *  Constant: '<S193>/offset'
         *  Constant: '<S193>/sine_table_values'
         *  Product: '<S194>/Product'
         *  Selector: '<S193>/Lookup'
         *  Sum: '<S193>/Sum'
         *  Sum: '<S194>/Sum3'
         */
        rtb_convert_pu_i = (PMSM_to_BLDC_mod1_ConstP.pooled16[(int32_T)(status +
          1U)] - PMSM_to_BLDC_mod1_ConstP.pooled16[status]) * rtb_Add1_f +
          PMSM_to_BLDC_mod1_ConstP.pooled16[status];

        /* Gain: '<S383>/Gain3' incorporates:
         *  Constant: '<S193>/offset'
         *  Constant: '<S193>/sine_table_values'
         *  Product: '<S194>/Product1'
         *  Selector: '<S193>/Lookup'
         *  Sum: '<S193>/Sum'
         *  Sum: '<S194>/Sum5'
         */
        rtb_Gain3_c = PMSM_to_BLDC_mod1_ConstP.pooled16[(int32_T)(status + 201U)]
          - PMSM_to_BLDC_mod1_ConstP.pooled16[(int32_T)(status + 200U)];
        rtb_Gain3_c *= rtb_Add1_f;

        /* Sum: '<S194>/Sum6' incorporates:
         *  Constant: '<S193>/offset'
         *  Constant: '<S193>/sine_table_values'
         *  Selector: '<S193>/Lookup'
         *  Sum: '<S193>/Sum'
         *  Sum: '<S194>/Sum5'
         */
        rtb_one_by_sqrt3_ = PMSM_to_BLDC_mod1_ConstP.pooled16[(int32_T)(status +
          200U)] + rtb_Gain3_c;

        /* Outputs for Atomic SubSystem: '<S192>/Two inputs CRL' */
        /* Gain: '<S383>/Gain3' incorporates:
         *  Product: '<S201>/dsin'
         *  Product: '<S201>/qcos'
         *  Sum: '<S201>/sum_beta'
         */
        rtb_Gain3_c = rtb_Saturation_k * rtb_one_by_sqrt3_ + rtb_Product_j_idx_1
          * rtb_convert_pu_i;

        /* Switch: '<S202>/Switch' incorporates:
         *  Product: '<S201>/dcos'
         *  Product: '<S201>/qsin'
         *  Sum: '<S201>/sum_alpha'
         */
        rtb_Saturation_k = rtb_Product_j_idx_1 * rtb_one_by_sqrt3_ -
          rtb_Saturation_k * rtb_convert_pu_i;
        rtb_Product_j_idx_1 = rtb_Gain3_c;

        /* SignalConversion generated from: '<S58>/Delay' incorporates:
         *  AlgorithmDescriptorDelegate generated from: '<S201>/a16'
         *  Switch: '<S202>/Switch'
         */
        rtb_TmpSignalConversionAtDelayI[1] = rtb_Gain3_c;

        /* Gain: '<S383>/Gain3' incorporates:
         *  AlgorithmDescriptorDelegate generated from: '<S201>/a16'
         *  Gain: '<S212>/one_by_two'
         */
        rtb_Gain3_c = 0.5 * rtb_Saturation_k;

        /* Gain: '<S212>/sqrt3_by_two' incorporates:
         *  AlgorithmDescriptorDelegate generated from: '<S201>/a16'
         */
        rtb_Add2 = 0.8660254037844386 * rtb_Product_j_idx_1;

        /* End of Outputs for SubSystem: '<S192>/Two inputs CRL' */

        /* Sum: '<S212>/add_b' */
        rtb_Add1_f = rtb_Add2 - rtb_Gain3_c;

        /* Gain: '<S383>/Gain3' incorporates:
         *  Sum: '<S212>/add_c'
         */
        rtb_Gain3_c = (0.0 - rtb_Gain3_c) - rtb_Add2;

        /* Outputs for Atomic SubSystem: '<S192>/Two inputs CRL' */
        /* Gain: '<S206>/one_by_two' incorporates:
         *  AlgorithmDescriptorDelegate generated from: '<S201>/a16'
         *  MinMax: '<S206>/Max'
         *  MinMax: '<S206>/Min'
         *  Sum: '<S206>/Add'
         */
        rtb_Add2 = (fmax(fmax(rtb_Saturation_k, rtb_Add1_f), rtb_Gain3_c) + fmin
                    (fmin(rtb_Saturation_k, rtb_Add1_f), rtb_Gain3_c)) * -0.5;

        /* Gain: '<S64>/Gain' incorporates:
         *  AlgorithmDescriptorDelegate generated from: '<S201>/a16'
         *  Constant: '<S64>/Constant'
         *  Gain: '<S205>/Gain'
         *  Sum: '<S205>/Add1'
         *  Sum: '<S205>/Add2'
         *  Sum: '<S205>/Add3'
         *  Sum: '<S64>/Add'
         */
        PMSM_to_BLDC_mod1_B.Gain[0] = ((rtb_Saturation_k + rtb_Add2) *
          1.1547005383792517 + 1.45) * 0.33333333333333331;

        /* End of Outputs for SubSystem: '<S192>/Two inputs CRL' */
        PMSM_to_BLDC_mod1_B.Gain[1] = ((rtb_Add1_f + rtb_Add2) *
          1.1547005383792517 + 1.45) * 0.33333333333333331;
        PMSM_to_BLDC_mod1_B.Gain[2] = ((rtb_Add2 + rtb_Gain3_c) *
          1.1547005383792517 + 1.45) * 0.33333333333333331;

        /* Sum: '<S418>/Add' incorporates:
         *  Constant: '<S418>/Constant1'
         *  Gain: '<S417>/Gain1'
         */
        PMSM_to_BLDC_mod1_B.Add[0] = -PMSM_to_BLDC_mod1_B.Gain[0] + 1.0;
        PMSM_to_BLDC_mod1_B.Add[1] = -PMSM_to_BLDC_mod1_B.Gain[1] + 1.0;
        PMSM_to_BLDC_mod1_B.Add[2] = -PMSM_to_BLDC_mod1_B.Gain[2] + 1.0;

        /* MATLABSystem: '<S474>/PWM Output' incorporates:
         *  Constant: '<S7>/Constant'
         */
        timModule = TIM8;
        freq = checkFrequencyAndDutyCycleLimits
          (PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, 20000U);
        setFrequencyAccToInput(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle, freq);

        /* DataTypeConversion: '<S57>/Data Type Conversion' incorporates:
         *  Gain: '<S57>/Gain'
         */
        Merge_i = floor(100.0 * PMSM_to_BLDC_mod1_B.Gain[0]);
        if (rtIsNaN(Merge_i) || rtIsInf(Merge_i)) {
          Merge_i = 0.0;
        } else {
          Merge_i = fmod(Merge_i, 65536.0);
        }

        /* MATLABSystem: '<S474>/PWM Output' incorporates:
         *  DataTypeConversion: '<S57>/Data Type Conversion'
         */
        setDutyCycleInPercentageChannel1(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle,
          (uint16_T)(Merge_i < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                     -Merge_i : (int32_T)(uint16_T)Merge_i));
        channelEnum = LL_TIM_CHANNEL_CH1N;
        LL_TIM_CC_EnableChannel(timModule, channelEnum);

        /* DataTypeConversion: '<S57>/Data Type Conversion2' incorporates:
         *  Gain: '<S57>/Gain'
         */
        Merge_i = floor(100.0 * PMSM_to_BLDC_mod1_B.Gain[1]);
        if (rtIsNaN(Merge_i) || rtIsInf(Merge_i)) {
          Merge_i = 0.0;
        } else {
          Merge_i = fmod(Merge_i, 65536.0);
        }

        /* MATLABSystem: '<S474>/PWM Output' incorporates:
         *  DataTypeConversion: '<S57>/Data Type Conversion2'
         */
        setDutyCycleInPercentageChannel2(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle,
          (uint16_T)(Merge_i < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                     -Merge_i : (int32_T)(uint16_T)Merge_i));
        channelEnum = LL_TIM_CHANNEL_CH2N;
        LL_TIM_CC_EnableChannel(timModule, channelEnum);

        /* DataTypeConversion: '<S57>/Data Type Conversion4' incorporates:
         *  Gain: '<S57>/Gain'
         */
        Merge_i = floor(100.0 * PMSM_to_BLDC_mod1_B.Gain[2]);
        if (rtIsNaN(Merge_i) || rtIsInf(Merge_i)) {
          Merge_i = 0.0;
        } else {
          Merge_i = fmod(Merge_i, 65536.0);
        }

        /* MATLABSystem: '<S474>/PWM Output' incorporates:
         *  DataTypeConversion: '<S57>/Data Type Conversion4'
         */
        setDutyCycleInPercentageChannel3(PMSM_to_BLDC_mod1_DW.obj_e.TimerHandle,
          (uint16_T)(Merge_i < 0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
                     -Merge_i : (int32_T)(uint16_T)Merge_i));
        channelEnum = LL_TIM_CHANNEL_CH3N;
        LL_TIM_CC_EnableChannel(timModule, channelEnum);

        /* DeadZone: '<S107>/DeadZone' */
        if (rtb_DeadZone > 1.0) {
          rtb_DeadZone--;
        } else if (rtb_DeadZone >= -1.0) {
          rtb_DeadZone = 0.0;
        } else {
          rtb_DeadZone++;
        }

        /* End of DeadZone: '<S107>/DeadZone' */

        /* Gain: '<S383>/Gain3' incorporates:
         *  Constant: '<S76>/Constant1'
         *  Product: '<S112>/IProd Out'
         */
        rtb_Gain3_c = rtb_uabc3 * 0.23235999999999998;

        /* Switch: '<S105>/Switch1' incorporates:
         *  Constant: '<S105>/Clamping_zero'
         *  Constant: '<S105>/Constant'
         *  Constant: '<S105>/Constant2'
         *  RelationalOperator: '<S105>/fix for DT propagation issue'
         */
        if (rtb_DeadZone > 0.0) {
          rtPrevAction = 1;
        } else {
          rtPrevAction = -1;
        }

        /* Switch: '<S105>/Switch2' incorporates:
         *  Constant: '<S105>/Clamping_zero'
         *  Constant: '<S105>/Constant3'
         *  Constant: '<S105>/Constant4'
         *  RelationalOperator: '<S105>/fix for DT propagation issue1'
         */
        if (rtb_Gain3_c > 0.0) {
          rtAction = 1;
        } else {
          rtAction = -1;
        }

        /* Switch: '<S105>/Switch' incorporates:
         *  Constant: '<S105>/Clamping_zero'
         *  Logic: '<S105>/AND3'
         *  RelationalOperator: '<S105>/Equal1'
         *  RelationalOperator: '<S105>/Relational Operator'
         *  Switch: '<S105>/Switch1'
         *  Switch: '<S105>/Switch2'
         */
        if ((rtb_DeadZone != 0.0) && (rtPrevAction == rtAction)) {
          /* Switch: '<S105>/Switch' incorporates:
           *  Constant: '<S105>/Constant1'
           */
          rtb_Switch = 0.0;
        } else {
          /* Switch: '<S105>/Switch' */
          rtb_Switch = rtb_Gain3_c;
        }

        /* End of Switch: '<S105>/Switch' */

        /* DeadZone: '<S162>/DeadZone' */
        if (rtb_Product1_o > 1.0) {
          rtb_Product1_o--;
        } else if (rtb_Product1_o >= -1.0) {
          rtb_Product1_o = 0.0;
        } else {
          rtb_Product1_o++;
        }

        /* End of DeadZone: '<S162>/DeadZone' */

        /* Gain: '<S383>/Gain4' incorporates:
         *  Constant: '<S77>/Constant1'
         *  Product: '<S167>/IProd Out'
         */
        rtb_Gain4_i *= 0.23235999999999998;

        /* Switch: '<S160>/Switch1' incorporates:
         *  Constant: '<S160>/Clamping_zero'
         *  Constant: '<S160>/Constant'
         *  Constant: '<S160>/Constant2'
         *  RelationalOperator: '<S160>/fix for DT propagation issue'
         */
        if (rtb_Product1_o > 0.0) {
          rtPrevAction = 1;
        } else {
          rtPrevAction = -1;
        }

        /* Switch: '<S160>/Switch2' incorporates:
         *  Constant: '<S160>/Clamping_zero'
         *  Constant: '<S160>/Constant3'
         *  Constant: '<S160>/Constant4'
         *  RelationalOperator: '<S160>/fix for DT propagation issue1'
         */
        if (rtb_Gain4_i > 0.0) {
          rtAction = 1;
        } else {
          rtAction = -1;
        }

        /* Switch: '<S160>/Switch' incorporates:
         *  Constant: '<S160>/Clamping_zero'
         *  Logic: '<S160>/AND3'
         *  RelationalOperator: '<S160>/Equal1'
         *  RelationalOperator: '<S160>/Relational Operator'
         *  Switch: '<S160>/Switch1'
         *  Switch: '<S160>/Switch2'
         */
        if ((rtb_Product1_o != 0.0) && (rtPrevAction == rtAction)) {
          /* Switch: '<S160>/Switch' incorporates:
           *  Constant: '<S160>/Constant1'
           */
          rtb_Switch_e = 0.0;
        } else {
          /* Switch: '<S160>/Switch' */
          rtb_Switch_e = rtb_Gain4_i;
        }

        /* End of Switch: '<S160>/Switch' */

        /* Gain: '<S383>/Gain3' incorporates:
         *  Constant: '<S71>/Constant1'
         *  Math: '<S71>/Mod1'
         */
        rtb_Gain3_c = rt_modd_snf(rtb_Product_fc, 6.282);

        /* Gain: '<S383>/Gain4' incorporates:
         *  Constant: '<S71>/Constant1'
         *  Math: '<S71>/Mod2'
         */
        rtb_Gain4_i = rt_modd_snf(PMSM_to_BLDC_mod1_B.algDD_o2, 6.282);

        /* Product: '<S262>/Product' */
        rtb_Gain_e *= 0.0046902865258454489;

        /* Delay: '<S262>/Delay' incorporates:
         *  Constant: '<S254>/IC'
         */
        if (PMSM_to_BLDC_mod1_DW.icLoad_b) {
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_g = 0.0;
        }

        /* Sum: '<S262>/Add1' incorporates:
         *  Delay: '<S262>/Delay'
         *  Product: '<S262>/Product1'
         */
        rtb_Add1_d = 0.99530971347415453 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_g +
          rtb_Gain_e;

        /* Gain: '<S250>/FreqGain' incorporates:
         *  Delay: '<S231>/Delay1'
         */
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f = (real32_T)rtb_Add1_d;

        /* Gain: '<S231>/SpeedGain' incorporates:
         *  Delay: '<S231>/Delay1'
         *  Delay: '<S55>/Delay1'
         */
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx = 0.142857149F *
          PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f;

        /* Outputs for Atomic SubSystem: '<S192>/Two inputs CRL' */
        /* SignalConversion generated from: '<S58>/Delay' incorporates:
         *  AlgorithmDescriptorDelegate generated from: '<S201>/a16'
         */
        rtb_TmpSignalConversionAtDelayI[0] = rtb_Saturation_k;

        /* End of Outputs for SubSystem: '<S192>/Two inputs CRL' */
        rtb_TmpSignalConversionAtDelayI[2] = rtb_Gain3_c;
        rtb_TmpSignalConversionAtDelayI[3] = rtb_Gain4_i;

        /* Saturate: '<S370>/Saturation2' */
        if (PMSM_to_BLDC_mod1_B.Gain[0] > 1.0) {
          rtb_DeadZone = 1.0;
        } else if (PMSM_to_BLDC_mod1_B.Gain[0] < 0.0) {
          rtb_DeadZone = 0.0;
        } else {
          rtb_DeadZone = PMSM_to_BLDC_mod1_B.Gain[0];
        }

        if (PMSM_to_BLDC_mod1_B.Gain[1] > 1.0) {
          rtb_Saturation_k = 1.0;
        } else if (PMSM_to_BLDC_mod1_B.Gain[1] < 0.0) {
          rtb_Saturation_k = 0.0;
        } else {
          rtb_Saturation_k = PMSM_to_BLDC_mod1_B.Gain[1];
        }

        if (PMSM_to_BLDC_mod1_B.Gain[2] > 1.0) {
          rtb_convert_pu_i = 1.0;
        } else if (PMSM_to_BLDC_mod1_B.Gain[2] < 0.0) {
          rtb_convert_pu_i = 0.0;
        } else {
          rtb_convert_pu_i = PMSM_to_BLDC_mod1_B.Gain[2];
        }

        /* End of Saturate: '<S370>/Saturation2' */

        /* Gain: '<S370>/Gain' incorporates:
         *  Sum: '<S370>/Sum'
         */
        rtb_Gain_e = ((rtb_Saturation_k + rtb_convert_pu_i) + rtb_DeadZone) *
          0.33333333333333331;

        /* Gain: '<S383>/Gain3' incorporates:
         *  Sum: '<S370>/Sum1'
         */
        rtb_Gain3_c = rtb_DeadZone - rtb_Gain_e;

        /* Gain: '<S383>/Gain4' incorporates:
         *  Sum: '<S370>/Sum2'
         */
        rtb_Gain4_i = rtb_Saturation_k - rtb_Gain_e;

        /* Product: '<S370>/Product' incorporates:
         *  Sum: '<S370>/Sum3'
         */
        rtb_DeadZone = rtb_Gain3_c * PMSM_to_BLDC_mod1_ConstB.Switch;
        rtb_Saturation_k = rtb_Gain4_i * PMSM_to_BLDC_mod1_ConstB.Switch;
        rtb_convert_pu_i = (rtb_convert_pu_i - rtb_Gain_e) *
          PMSM_to_BLDC_mod1_ConstB.Switch;
      }

      /* Integrator: '<S390>/Integrator' */
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

      /* Gain: '<S375>/Gain4' incorporates:
       *  Integrator: '<S375>/Int1'
       */
      rtb_Product1_o = 7.0 * PMSM_to_BLDC_mod1_X.Int1_CSTATE;

      /* Trigonometry: '<S377>/sine_cosine' */
      rtb_Product_fc = sin(rtb_Product1_o);
      rtb_Product1_o = cos(rtb_Product1_o);

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

      /* Sum: '<S385>/Add1' incorporates:
       *  Integrator: '<S390>/Integrator'
       *  Integrator: '<S391>/Integrator'
       *  Product: '<S385>/Product2'
       *  Product: '<S385>/Product3'
       */
      rtb_uabc3 = PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d * rtb_Product1_o -
        PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l * rtb_Product_fc;

      /* SignalConversion generated from: '<S374>/Vector Concatenate' incorporates:
       *  Concatenate: '<S374>/Vector Concatenate'
       */
      PMSM_to_BLDC_mod1_B.VectorConcatenate[0] = rtb_uabc3;
      if (tmp_2) {
        /* Gain: '<S383>/Gain3' incorporates:
         *  Gain: '<S383>/Gain1'
         */
        rtb_Gain3_c = -0.33333333333333331 * rtb_Saturation_k;

        /* Gain: '<S383>/Gain4' */
        rtb_Gain4_i = -0.33333333333333331 * rtb_convert_pu_i;

        /* Sum: '<S383>/Add' incorporates:
         *  Gain: '<S383>/Gain'
         */
        PMSM_to_BLDC_mod1_B.Add_a = (0.66666666666666663 * rtb_DeadZone +
          rtb_Gain3_c) + rtb_Gain4_i;

        /* Gain: '<S383>/Gain3' */
        rtb_Gain3_c = -0.57735026918962573 * rtb_convert_pu_i;

        /* Sum: '<S383>/Add1' incorporates:
         *  Gain: '<S383>/Gain2'
         */
        PMSM_to_BLDC_mod1_B.Add1 = 0.57735026918962573 * rtb_Saturation_k +
          rtb_Gain3_c;
      }

      /* Gain: '<S384>/Gain1' */
      rtb_DeadZone = -0.5 * rtb_uabc3;

      /* Sum: '<S385>/Add' incorporates:
       *  Integrator: '<S390>/Integrator'
       *  Integrator: '<S391>/Integrator'
       *  Product: '<S385>/Product'
       *  Product: '<S385>/Product1'
       */
      rtb_uabc3 = PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d * rtb_Product_fc +
        PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l * rtb_Product1_o;

      /* Sum: '<S384>/Subtract1' incorporates:
       *  Concatenate: '<S374>/Vector Concatenate'
       *  Gain: '<S384>/Gain2'
       *  Gain: '<S384>/Gain3'
       */
      PMSM_to_BLDC_mod1_B.VectorConcatenate[1] = 0.8660254037844386 * rtb_uabc3
        + rtb_DeadZone;

      /* Sum: '<S384>/Subtract2' incorporates:
       *  Concatenate: '<S374>/Vector Concatenate'
       *  Gain: '<S384>/Gain4'
       */
      PMSM_to_BLDC_mod1_B.VectorConcatenate[2] = -0.8660254037844386 * rtb_uabc3
        + rtb_DeadZone;

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
      PMSM_to_BLDC_mod1_B.Add_h = ((PMSM_to_BLDC_mod1_B.Add_a * rtb_Product1_o +
        PMSM_to_BLDC_mod1_B.Add1 * rtb_Product_fc) /
        PMSM_to_BLDC_mod1_ConstB.IndexVector_b + PMSM_to_BLDC_mod1_ConstB.Gain *
        PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l *
        PMSM_to_BLDC_mod1_ConstB.IndexVector_a /
        PMSM_to_BLDC_mod1_ConstB.IndexVector1) -
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
      PMSM_to_BLDC_mod1_B.Add_d = (((PMSM_to_BLDC_mod1_B.Add1 * rtb_Product1_o -
        PMSM_to_BLDC_mod1_B.Add_a * rtb_Product_fc) /
        PMSM_to_BLDC_mod1_ConstB.IndexVector_k -
        PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d * PMSM_to_BLDC_mod1_ConstB.Gain *
        PMSM_to_BLDC_mod1_ConstB.IndexVector_m /
        PMSM_to_BLDC_mod1_ConstB.IndexVector1_g) -
        PMSM_to_BLDC_mod1_ConstB.Product) -
        PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l * 0.037 /
        PMSM_to_BLDC_mod1_ConstB.IndexVector_d3;
      if (tmp_2) {
        /* SimscapeRtp: '<S407>/RTP_1' incorporates:
         *  Constant: '<S369>/Subsystem_around_RTP_57D1A14D_v'
         */
        if (PMSM_to_BLDC_mod1_DW.RTP_1_SetParametersNeeded) {
          tmp = 0.0;
          diag = rtw_create_diagnostics();
          diagTree = neu_diagnostic_manager_get_initial_tree(diag);
          PMSM_to_BLDC_mod1_B.expl_temp.mRealParameters.mN = 1;
          PMSM_to_BLDC_mod1_B.expl_temp.mRealParameters.mX = &tmp;
          PMSM_to_BLDC_mod1_B.expl_temp.mLogicalParameters.mN = 0;
          PMSM_to_BLDC_mod1_B.expl_temp.mLogicalParameters.mX = NULL;
          PMSM_to_BLDC_mod1_B.expl_temp.mIntegerParameters.mN = 0;
          PMSM_to_BLDC_mod1_B.expl_temp.mIntegerParameters.mX = NULL;
          PMSM_to_BLDC_mod1_B.expl_temp.mIndexParameters.mN = 0;
          PMSM_to_BLDC_mod1_B.expl_temp.mIndexParameters.mX = NULL;
          ok = nesl_rtp_manager_set_rtps((NeslRtpManager *)
            PMSM_to_BLDC_mod1_DW.RTP_1_RtpManager, PMSM_to_BLDC_mod1_M->
            Timing.t[0], PMSM_to_BLDC_mod1_B.expl_temp, diag);
          if (!ok) {
            ok = error_buffer_is_empty(rtmGetErrorStatus(PMSM_to_BLDC_mod1_M));
            if (ok) {
              msg = rtw_diagnostics_msg(diagTree);
              rtmSetErrorStatus(PMSM_to_BLDC_mod1_M, msg);
            }
          }
        }

        PMSM_to_BLDC_mod1_DW.RTP_1_SetParametersNeeded = false;

        /* End of SimscapeRtp: '<S407>/RTP_1' */
      }

      /* SimscapeInputBlock: '<S416>/INPUT_1_1_1' incorporates:
       *  SimscapeExecutionBlock: '<S416>/OUTPUT_1_0'
       *  SimscapeExecutionBlock: '<S416>/STATE_1'
       *  SimscapeInputBlock: '<S416>/INPUT_2_1_1'
       *  SimscapeInputBlock: '<S416>/INPUT_3_1_1'
       *  SimscapeInputBlock: '<S416>/INPUT_4_1_1'
       *  SimscapeInputBlock: '<S416>/INPUT_5_1_1'
       *  SimscapeInputBlock: '<S416>/INPUT_6_1_1'
       *  SimscapeInputBlock: '<S416>/INPUT_7_1_1'
       */
      PMSM_to_BLDC_mod1_B.INPUT_1_1_1[0] = PMSM_to_BLDC_mod1_B.Gain[0];
      PMSM_to_BLDC_mod1_B.INPUT_1_1_1[1] = 0.0;
      PMSM_to_BLDC_mod1_B.INPUT_1_1_1[2] = 0.0;
      ok = rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M);
      if (ok) {
        PMSM_to_BLDC_mod1_DW.INPUT_1_1_1_Discrete_2356258676[0] =
          !(PMSM_to_BLDC_mod1_B.INPUT_1_1_1[0] ==
            PMSM_to_BLDC_mod1_DW.INPUT_1_1_1_Discrete_2356258676[1]);
        PMSM_to_BLDC_mod1_DW.INPUT_1_1_1_Discrete_2356258676[1] =
          PMSM_to_BLDC_mod1_B.INPUT_1_1_1[0];
      }

      PMSM_to_BLDC_mod1_B.INPUT_1_1_1[0] =
        PMSM_to_BLDC_mod1_DW.INPUT_1_1_1_Discrete_2356258676[1];
      PMSM_to_BLDC_mod1_B.INPUT_1_1_1[3] =
        PMSM_to_BLDC_mod1_DW.INPUT_1_1_1_Discrete_2356258676[0];

      /* End of SimscapeInputBlock: '<S416>/INPUT_1_1_1' */

      /* SimscapeInputBlock: '<S416>/INPUT_2_1_1' */
      PMSM_to_BLDC_mod1_B.INPUT_2_1_1[0] = PMSM_to_BLDC_mod1_B.Add[0];
      PMSM_to_BLDC_mod1_B.INPUT_2_1_1[1] = 0.0;
      PMSM_to_BLDC_mod1_B.INPUT_2_1_1[2] = 0.0;
      if (ok) {
        PMSM_to_BLDC_mod1_DW.INPUT_2_1_1_Discrete_3419528612[0] =
          !(PMSM_to_BLDC_mod1_B.INPUT_2_1_1[0] ==
            PMSM_to_BLDC_mod1_DW.INPUT_2_1_1_Discrete_3419528612[1]);
        PMSM_to_BLDC_mod1_DW.INPUT_2_1_1_Discrete_3419528612[1] =
          PMSM_to_BLDC_mod1_B.INPUT_2_1_1[0];
      }

      PMSM_to_BLDC_mod1_B.INPUT_2_1_1[0] =
        PMSM_to_BLDC_mod1_DW.INPUT_2_1_1_Discrete_3419528612[1];
      PMSM_to_BLDC_mod1_B.INPUT_2_1_1[3] =
        PMSM_to_BLDC_mod1_DW.INPUT_2_1_1_Discrete_3419528612[0];

      /* SimscapeInputBlock: '<S416>/INPUT_3_1_1' incorporates:
       *  Constant: '<S369>/Trq'
       */
      PMSM_to_BLDC_mod1_B.INPUT_3_1_1[0] = 10.0;
      PMSM_to_BLDC_mod1_B.INPUT_3_1_1[1] = 0.0;
      PMSM_to_BLDC_mod1_B.INPUT_3_1_1[2] = 0.0;
      if (ok) {
        PMSM_to_BLDC_mod1_DW.INPUT_3_1_1_Discrete_4138857492[0] =
          !(PMSM_to_BLDC_mod1_B.INPUT_3_1_1[0] ==
            PMSM_to_BLDC_mod1_DW.INPUT_3_1_1_Discrete_4138857492[1]);
        PMSM_to_BLDC_mod1_DW.INPUT_3_1_1_Discrete_4138857492[1] =
          PMSM_to_BLDC_mod1_B.INPUT_3_1_1[0];
      }

      PMSM_to_BLDC_mod1_B.INPUT_3_1_1[0] =
        PMSM_to_BLDC_mod1_DW.INPUT_3_1_1_Discrete_4138857492[1];
      PMSM_to_BLDC_mod1_B.INPUT_3_1_1[3] =
        PMSM_to_BLDC_mod1_DW.INPUT_3_1_1_Discrete_4138857492[0];

      /* SimscapeInputBlock: '<S416>/INPUT_4_1_1' */
      PMSM_to_BLDC_mod1_B.INPUT_4_1_1[0] = PMSM_to_BLDC_mod1_B.Gain[1];
      PMSM_to_BLDC_mod1_B.INPUT_4_1_1[1] = 0.0;
      PMSM_to_BLDC_mod1_B.INPUT_4_1_1[2] = 0.0;
      if (ok) {
        PMSM_to_BLDC_mod1_DW.INPUT_4_1_1_Discrete_1150363652[0] =
          !(PMSM_to_BLDC_mod1_B.INPUT_4_1_1[0] ==
            PMSM_to_BLDC_mod1_DW.INPUT_4_1_1_Discrete_1150363652[1]);
        PMSM_to_BLDC_mod1_DW.INPUT_4_1_1_Discrete_1150363652[1] =
          PMSM_to_BLDC_mod1_B.INPUT_4_1_1[0];
      }

      PMSM_to_BLDC_mod1_B.INPUT_4_1_1[0] =
        PMSM_to_BLDC_mod1_DW.INPUT_4_1_1_Discrete_1150363652[1];
      PMSM_to_BLDC_mod1_B.INPUT_4_1_1[3] =
        PMSM_to_BLDC_mod1_DW.INPUT_4_1_1_Discrete_1150363652[0];

      /* SimscapeInputBlock: '<S416>/INPUT_5_1_1' */
      PMSM_to_BLDC_mod1_B.INPUT_5_1_1[0] = PMSM_to_BLDC_mod1_B.Add[1];
      PMSM_to_BLDC_mod1_B.INPUT_5_1_1[1] = 0.0;
      PMSM_to_BLDC_mod1_B.INPUT_5_1_1[2] = 0.0;
      if (ok) {
        PMSM_to_BLDC_mod1_DW.INPUT_5_1_1_Discrete_2045837748[0] =
          !(PMSM_to_BLDC_mod1_B.INPUT_5_1_1[0] ==
            PMSM_to_BLDC_mod1_DW.INPUT_5_1_1_Discrete_2045837748[1]);
        PMSM_to_BLDC_mod1_DW.INPUT_5_1_1_Discrete_2045837748[1] =
          PMSM_to_BLDC_mod1_B.INPUT_5_1_1[0];
      }

      PMSM_to_BLDC_mod1_B.INPUT_5_1_1[0] =
        PMSM_to_BLDC_mod1_DW.INPUT_5_1_1_Discrete_2045837748[1];
      PMSM_to_BLDC_mod1_B.INPUT_5_1_1[3] =
        PMSM_to_BLDC_mod1_DW.INPUT_5_1_1_Discrete_2045837748[0];

      /* SimscapeInputBlock: '<S416>/INPUT_6_1_1' */
      PMSM_to_BLDC_mod1_B.INPUT_6_1_1[0] = PMSM_to_BLDC_mod1_B.Gain[2];
      PMSM_to_BLDC_mod1_B.INPUT_6_1_1[1] = 0.0;
      PMSM_to_BLDC_mod1_B.INPUT_6_1_1[2] = 0.0;
      if (ok) {
        PMSM_to_BLDC_mod1_DW.INPUT_6_1_1_Discrete_1045527396[0] =
          !(PMSM_to_BLDC_mod1_B.INPUT_6_1_1[0] ==
            PMSM_to_BLDC_mod1_DW.INPUT_6_1_1_Discrete_1045527396[1]);
        PMSM_to_BLDC_mod1_DW.INPUT_6_1_1_Discrete_1045527396[1] =
          PMSM_to_BLDC_mod1_B.INPUT_6_1_1[0];
      }

      PMSM_to_BLDC_mod1_B.INPUT_6_1_1[0] =
        PMSM_to_BLDC_mod1_DW.INPUT_6_1_1_Discrete_1045527396[1];
      PMSM_to_BLDC_mod1_B.INPUT_6_1_1[3] =
        PMSM_to_BLDC_mod1_DW.INPUT_6_1_1_Discrete_1045527396[0];

      /* SimscapeInputBlock: '<S416>/INPUT_7_1_1' */
      PMSM_to_BLDC_mod1_B.INPUT_7_1_1[0] = PMSM_to_BLDC_mod1_B.Add[2];
      PMSM_to_BLDC_mod1_B.INPUT_7_1_1[1] = 0.0;
      PMSM_to_BLDC_mod1_B.INPUT_7_1_1[2] = 0.0;
      if (ok) {
        PMSM_to_BLDC_mod1_DW.INPUT_7_1_1_Discrete_53564116[0] =
          !(PMSM_to_BLDC_mod1_B.INPUT_7_1_1[0] ==
            PMSM_to_BLDC_mod1_DW.INPUT_7_1_1_Discrete_53564116[1]);
        PMSM_to_BLDC_mod1_DW.INPUT_7_1_1_Discrete_53564116[1] =
          PMSM_to_BLDC_mod1_B.INPUT_7_1_1[0];
      }

      PMSM_to_BLDC_mod1_B.INPUT_7_1_1[0] =
        PMSM_to_BLDC_mod1_DW.INPUT_7_1_1_Discrete_53564116[1];
      PMSM_to_BLDC_mod1_B.INPUT_7_1_1[3] =
        PMSM_to_BLDC_mod1_DW.INPUT_7_1_1_Discrete_53564116[0];

      /* SimscapeExecutionBlock: '<S416>/STATE_1' incorporates:
       *  SimscapeExecutionBlock: '<S416>/OUTPUT_1_0'
       */
      simulationData = (NeslSimulationData *)
        PMSM_to_BLDC_mod1_DW.STATE_1_SimData;
      rtb_DeadZone = PMSM_to_BLDC_mod1_M->Timing.t[0];
      time = rtb_DeadZone;
      simulationData->mData->mTime.mN = 1;
      simulationData->mData->mTime.mX = &time;
      simulationData->mData->mContStates.mN = 17;
      simulationData->mData->mContStates.mX =
        &PMSM_to_BLDC_mod1_X.PMSM_to_BLDC_mod1SubsystemFOCIn[0];
      simulationData->mData->mDiscStates.mN = 0;
      simulationData->mData->mDiscStates.mX =
        &PMSM_to_BLDC_mod1_DW.STATE_1_Discrete;
      simulationData->mData->mModeVector.mN = 11;
      simulationData->mData->mModeVector.mX =
        &PMSM_to_BLDC_mod1_DW.STATE_1_Modes[0];
      tmp_0 = false;
      simulationData->mData->mFoundZcEvents = tmp_0;
      simulationData->mData->mHadEvents = false;
      simulationData->mData->mIsMajorTimeStep = ok;
      tmp_0 = false;
      simulationData->mData->mIsSolverAssertCheck = tmp_0;
      simulationData->mData->mIsSolverCheckingCIC = false;
      tmp_0 = rtsiIsSolverComputingJacobian(&PMSM_to_BLDC_mod1_M->solverInfo);
      simulationData->mData->mIsComputingJacobian = tmp_0;
      simulationData->mData->mIsEvaluatingF0 = false;
      simulationData->mData->mIsSolverRequestingReset = false;
      simulationData->mData->mIsModeUpdateTimeStep = tmp_3;
      PMSM_to_BLDC_mod1_B.iv1[0] = 0;
      PMSM_to_BLDC_mod1_B.dv1[0] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[0];
      PMSM_to_BLDC_mod1_B.dv1[1] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[1];
      PMSM_to_BLDC_mod1_B.dv1[2] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[2];
      PMSM_to_BLDC_mod1_B.dv1[3] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[3];
      PMSM_to_BLDC_mod1_B.iv1[1] = 4;
      PMSM_to_BLDC_mod1_B.dv1[4] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[0];
      PMSM_to_BLDC_mod1_B.dv1[5] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[1];
      PMSM_to_BLDC_mod1_B.dv1[6] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[2];
      PMSM_to_BLDC_mod1_B.dv1[7] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[3];
      PMSM_to_BLDC_mod1_B.iv1[2] = 8;
      PMSM_to_BLDC_mod1_B.dv1[8] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[0];
      PMSM_to_BLDC_mod1_B.dv1[9] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[1];
      PMSM_to_BLDC_mod1_B.dv1[10] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[2];
      PMSM_to_BLDC_mod1_B.dv1[11] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[3];
      PMSM_to_BLDC_mod1_B.iv1[3] = 12;
      PMSM_to_BLDC_mod1_B.dv1[12] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[0];
      PMSM_to_BLDC_mod1_B.dv1[13] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[1];
      PMSM_to_BLDC_mod1_B.dv1[14] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[2];
      PMSM_to_BLDC_mod1_B.dv1[15] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[3];
      PMSM_to_BLDC_mod1_B.iv1[4] = 16;
      PMSM_to_BLDC_mod1_B.dv1[16] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[0];
      PMSM_to_BLDC_mod1_B.dv1[17] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[1];
      PMSM_to_BLDC_mod1_B.dv1[18] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[2];
      PMSM_to_BLDC_mod1_B.dv1[19] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[3];
      PMSM_to_BLDC_mod1_B.iv1[5] = 20;
      PMSM_to_BLDC_mod1_B.dv1[20] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[0];
      PMSM_to_BLDC_mod1_B.dv1[21] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[1];
      PMSM_to_BLDC_mod1_B.dv1[22] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[2];
      PMSM_to_BLDC_mod1_B.dv1[23] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[3];
      PMSM_to_BLDC_mod1_B.iv1[6] = 24;
      PMSM_to_BLDC_mod1_B.dv1[24] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[0];
      PMSM_to_BLDC_mod1_B.dv1[25] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[1];
      PMSM_to_BLDC_mod1_B.dv1[26] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[2];
      PMSM_to_BLDC_mod1_B.dv1[27] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[3];
      PMSM_to_BLDC_mod1_B.iv1[7] = 28;
      simulationData->mData->mInputValues.mN = 28;
      simulationData->mData->mInputValues.mX = &PMSM_to_BLDC_mod1_B.dv1[0];
      simulationData->mData->mInputOffsets.mN = 8;
      simulationData->mData->mInputOffsets.mX = &PMSM_to_BLDC_mod1_B.iv1[0];
      simulationData->mData->mOutputs.mN = 28;
      simulationData->mData->mOutputs.mX = &PMSM_to_BLDC_mod1_B.STATE_1[0];
      simulationData->mData->mTolerances.mN = 0;
      simulationData->mData->mTolerances.mX = NULL;
      simulationData->mData->mCstateHasChanged = false;
      simulationData->mData->mDstateHasChanged = false;
      rtb_Saturation_k = PMSM_to_BLDC_mod1_M->Timing.t[0];
      time_0 = rtb_Saturation_k;
      simulationData->mData->mTime.mN = 1;
      simulationData->mData->mTime.mX = &time_0;
      simulationData->mData->mSampleHits.mN = 0;
      simulationData->mData->mSampleHits.mX = NULL;
      simulationData->mData->mIsFundamentalSampleHit = false;
      simulationData->mData->mHadEvents = false;
      diag = (NeuDiagnosticManager *)PMSM_to_BLDC_mod1_DW.STATE_1_DiagMgr;
      diagnosticTree = neu_diagnostic_manager_get_initial_tree(diag);
      i = ne_simulator_method((NeslSimulator *)
        PMSM_to_BLDC_mod1_DW.STATE_1_Simulator, NESL_SIM_OUTPUTS, simulationData,
        diag);
      if (i != 0) {
        tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(PMSM_to_BLDC_mod1_M));
        if (tmp_0) {
          msg_0 = rtw_diagnostics_msg(diagnosticTree);
          rtmSetErrorStatus(PMSM_to_BLDC_mod1_M, msg_0);
        }
      }

      /* SimscapeExecutionBlock: '<S416>/OUTPUT_1_0' */
      simulationData = (NeslSimulationData *)
        PMSM_to_BLDC_mod1_DW.OUTPUT_1_0_SimData;
      time_1 = rtb_DeadZone;
      simulationData->mData->mTime.mN = 1;
      simulationData->mData->mTime.mX = &time_1;
      simulationData->mData->mContStates.mN = 0;
      simulationData->mData->mContStates.mX = NULL;
      simulationData->mData->mDiscStates.mN = 0;
      simulationData->mData->mDiscStates.mX =
        &PMSM_to_BLDC_mod1_DW.OUTPUT_1_0_Discrete;
      simulationData->mData->mModeVector.mN = 0;
      simulationData->mData->mModeVector.mX =
        &PMSM_to_BLDC_mod1_DW.OUTPUT_1_0_Modes;
      tmp_0 = false;
      simulationData->mData->mFoundZcEvents = tmp_0;
      simulationData->mData->mHadEvents = false;
      simulationData->mData->mIsMajorTimeStep = ok;
      ok = false;
      simulationData->mData->mIsSolverAssertCheck = ok;
      simulationData->mData->mIsSolverCheckingCIC = false;
      simulationData->mData->mIsComputingJacobian = false;
      simulationData->mData->mIsEvaluatingF0 = false;
      simulationData->mData->mIsSolverRequestingReset = false;
      simulationData->mData->mIsModeUpdateTimeStep = tmp_3;
      PMSM_to_BLDC_mod1_B.iv[0] = 0;
      PMSM_to_BLDC_mod1_B.dv[0] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[0];
      PMSM_to_BLDC_mod1_B.dv[1] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[1];
      PMSM_to_BLDC_mod1_B.dv[2] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[2];
      PMSM_to_BLDC_mod1_B.dv[3] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[3];
      PMSM_to_BLDC_mod1_B.iv[1] = 4;
      PMSM_to_BLDC_mod1_B.dv[4] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[0];
      PMSM_to_BLDC_mod1_B.dv[5] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[1];
      PMSM_to_BLDC_mod1_B.dv[6] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[2];
      PMSM_to_BLDC_mod1_B.dv[7] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[3];
      PMSM_to_BLDC_mod1_B.iv[2] = 8;
      PMSM_to_BLDC_mod1_B.dv[8] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[0];
      PMSM_to_BLDC_mod1_B.dv[9] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[1];
      PMSM_to_BLDC_mod1_B.dv[10] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[2];
      PMSM_to_BLDC_mod1_B.dv[11] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[3];
      PMSM_to_BLDC_mod1_B.iv[3] = 12;
      PMSM_to_BLDC_mod1_B.dv[12] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[0];
      PMSM_to_BLDC_mod1_B.dv[13] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[1];
      PMSM_to_BLDC_mod1_B.dv[14] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[2];
      PMSM_to_BLDC_mod1_B.dv[15] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[3];
      PMSM_to_BLDC_mod1_B.iv[4] = 16;
      PMSM_to_BLDC_mod1_B.dv[16] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[0];
      PMSM_to_BLDC_mod1_B.dv[17] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[1];
      PMSM_to_BLDC_mod1_B.dv[18] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[2];
      PMSM_to_BLDC_mod1_B.dv[19] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[3];
      PMSM_to_BLDC_mod1_B.iv[5] = 20;
      PMSM_to_BLDC_mod1_B.dv[20] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[0];
      PMSM_to_BLDC_mod1_B.dv[21] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[1];
      PMSM_to_BLDC_mod1_B.dv[22] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[2];
      PMSM_to_BLDC_mod1_B.dv[23] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[3];
      PMSM_to_BLDC_mod1_B.iv[6] = 24;
      PMSM_to_BLDC_mod1_B.dv[24] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[0];
      PMSM_to_BLDC_mod1_B.dv[25] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[1];
      PMSM_to_BLDC_mod1_B.dv[26] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[2];
      PMSM_to_BLDC_mod1_B.dv[27] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[3];
      PMSM_to_BLDC_mod1_B.iv[7] = 28;
      memcpy(&PMSM_to_BLDC_mod1_B.dv[28], &PMSM_to_BLDC_mod1_B.STATE_1[0], 28U *
             sizeof(real_T));
      PMSM_to_BLDC_mod1_B.iv[8] = 56;
      simulationData->mData->mInputValues.mN = 56;
      simulationData->mData->mInputValues.mX = &PMSM_to_BLDC_mod1_B.dv[0];
      simulationData->mData->mInputOffsets.mN = 9;
      simulationData->mData->mInputOffsets.mX = &PMSM_to_BLDC_mod1_B.iv[0];
      simulationData->mData->mOutputs.mN = 1;
      simulationData->mData->mOutputs.mX = &rtb_OUTPUT_1_0;
      simulationData->mData->mTolerances.mN = 0;
      simulationData->mData->mTolerances.mX = NULL;
      simulationData->mData->mCstateHasChanged = false;
      simulationData->mData->mDstateHasChanged = false;
      time_2 = rtb_Saturation_k;
      simulationData->mData->mTime.mN = 1;
      simulationData->mData->mTime.mX = &time_2;
      simulationData->mData->mSampleHits.mN = 0;
      simulationData->mData->mSampleHits.mX = NULL;
      simulationData->mData->mIsFundamentalSampleHit = false;
      simulationData->mData->mHadEvents = false;
      diag = (NeuDiagnosticManager *)PMSM_to_BLDC_mod1_DW.OUTPUT_1_0_DiagMgr;
      diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diag);
      i = ne_simulator_method((NeslSimulator *)
        PMSM_to_BLDC_mod1_DW.OUTPUT_1_0_Simulator, NESL_SIM_OUTPUTS,
        simulationData, diag);
      if (i != 0) {
        tmp_3 = error_buffer_is_empty(rtmGetErrorStatus(PMSM_to_BLDC_mod1_M));
        if (tmp_3) {
          msg_1 = rtw_diagnostics_msg(diagnosticTree_0);
          rtmSetErrorStatus(PMSM_to_BLDC_mod1_M, msg_1);
        }
      }

      if (tmp_2) {
        /* Gain: '<S452>/Integral Gain' */
        PMSM_to_BLDC_mod1_B.IntegralGain = 11.047170868347338 * rtb_Add_oj;
      }
    }

    /* End of Outputs for SubSystem: '<Root>/Subsystem' */
    if (tmp_4) {
      /* Outputs for Atomic SubSystem: '<Root>/SPI_read' */
      /* Outputs for Enabled SubSystem: '<S31>/Subsystem1' incorporates:
       *  EnablePort: '<S34>/Ctrl_flag2'
       */
      /* SignalConversion generated from: '<S34>/Ctrl_flag2' incorporates:
       *  Constant: '<S34>/Constant'
       */
      if (PMSM_to_BLDC_mod1_B.spi_write2 > 0.0) {
        PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_g = true;
        PMSM_to_BLDC_mod1_SPIReceive(&PMSM_to_BLDC_mod1_B.SPIReceive_pn,
          &PMSM_to_BLDC_mod1_DW.SPIReceive_pn);
        PMSM_to_BLDC_mod1_SPITransmit(36864,
          &PMSM_to_BLDC_mod1_DW.SPITransmit_pn);
      } else if (PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_g) {
        /* Disable for MATLABSystem: '<S34>/SPI Receive' incorporates:
         *  Outport: '<S34>/Out1'
         */
        PMSM_to_BLDC_mod1_B.SPIReceive_pn.SPIReceive = 0U;
        PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_g = false;
      }

      /* End of SignalConversion generated from: '<S34>/Ctrl_flag2' */
      /* End of Outputs for SubSystem: '<S31>/Subsystem1' */

      /* Outputs for Enabled SubSystem: '<S31>/Subsystem' incorporates:
       *  EnablePort: '<S33>/Enable'
       */
      /* SignalConversion generated from: '<S33>/Enable' incorporates:
       *  Constant: '<S33>/Constant'
       *  Constant: '<S33>/Constant1'
       *  S-Function (sfix_bitop): '<S33>/Bitwise OR'
       */
      if (PMSM_to_BLDC_mod1_B.spi_write1 > 0.0) {
        /* MATLABSystem: '<S33>/SPI Receive' */
        status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE,
          2U, 3840U, MW_SPI_MODE_3);
        if (status == 0) {
          MW_SPI_Read_Databits(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, &tmp_1[0],
                               15U, 1, 1, 1U);
          LL_GPIO_SetOutputPin(GPIOC, 16384U);
        }

        /* End of MATLABSystem: '<S33>/SPI Receive' */

        /* Outputs for Atomic SubSystem: '<S33>/Bit Shift' */
        status = PMSM_to_BLDC_mod1_BitShift(1);

        /* End of Outputs for SubSystem: '<S33>/Bit Shift' */

        /* Outputs for Atomic SubSystem: '<S33>/Bit Shift1' */
        rtb_y_e = PMSM_to_BLDC_mod1_BitShift1(2);

        /* End of Outputs for SubSystem: '<S33>/Bit Shift1' */
        PMSM_to_BLDC_mod1_SPITransmit((uint16_T)(status | rtb_y_e |
          PMSM_to_BLDC_mod1_ConstB.BitwiseAND_d),
          &PMSM_to_BLDC_mod1_DW.SPITransmit_p);
      }

      /* End of SignalConversion generated from: '<S33>/Enable' */
      /* End of Outputs for SubSystem: '<S31>/Subsystem' */

      /* Outputs for Enabled SubSystem: '<S32>/Subsystem' incorporates:
       *  EnablePort: '<S39>/Enable'
       */
      /* SignalConversion generated from: '<S39>/Enable' incorporates:
       *  Constant: '<S39>/Constant'
       *  Constant: '<S39>/Constant1'
       *  S-Function (sfix_bitop): '<S39>/Bitwise OR'
       */
      if (PMSM_to_BLDC_mod1_B.spi_write3 > 0.0) {
        /* Outputs for Atomic SubSystem: '<S39>/Bit Shift' */
        rtb_y_e = PMSM_to_BLDC_mod1_BitShift(1);

        /* End of Outputs for SubSystem: '<S39>/Bit Shift' */

        /* Outputs for Atomic SubSystem: '<S39>/Bit Shift1' */
        status = PMSM_to_BLDC_mod1_BitShift1(3);

        /* End of Outputs for SubSystem: '<S39>/Bit Shift1' */
        PMSM_to_BLDC_mod1_SPITransmit((uint16_T)(rtb_y_e | status |
          PMSM_to_BLDC_mod1_ConstB.BitwiseAND_j),
          &PMSM_to_BLDC_mod1_DW.SPITransmit_pna);
      }

      /* End of SignalConversion generated from: '<S39>/Enable' */
      /* End of Outputs for SubSystem: '<S32>/Subsystem' */

      /* Outputs for Enabled SubSystem: '<S32>/Subsystem1' incorporates:
       *  EnablePort: '<S40>/Enable'
       */
      /* SignalConversion generated from: '<S40>/Enable' incorporates:
       *  Constant: '<S40>/Constant'
       */
      if (PMSM_to_BLDC_mod1_B.spi_write4 > 0.0) {
        PMSM_to_BLDC_mod1_DW.Subsystem1_MODE = true;
        PMSM_to_BLDC_mod1_SPIReceive(&PMSM_to_BLDC_mod1_B.SPIReceive_pna,
          &PMSM_to_BLDC_mod1_DW.SPIReceive_pna);
        PMSM_to_BLDC_mod1_SPITransmit(38912,
          &PMSM_to_BLDC_mod1_DW.SPITransmit_pnae);
      } else if (PMSM_to_BLDC_mod1_DW.Subsystem1_MODE) {
        /* Disable for MATLABSystem: '<S40>/SPI Receive' incorporates:
         *  Outport: '<S40>/Out1'
         */
        PMSM_to_BLDC_mod1_B.SPIReceive_pna.SPIReceive = 0U;
        PMSM_to_BLDC_mod1_DW.Subsystem1_MODE = false;
      }

      /* End of SignalConversion generated from: '<S40>/Enable' */
      /* End of Outputs for SubSystem: '<S32>/Subsystem1' */
      /* End of Outputs for SubSystem: '<Root>/SPI_read' */

      /* Outputs for Atomic SubSystem: '<Root>/En_gate' */
      /* MATLABSystem: '<S18>/Digital Port Write' */
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

      /* End of MATLABSystem: '<S18>/Digital Port Write' */
      /* End of Outputs for SubSystem: '<Root>/En_gate' */

      /* Outputs for Atomic SubSystem: '<Root>/Current_sensing' */
      /* Outputs for Enabled SubSystem: '<S2>/Subsystem' incorporates:
       *  EnablePort: '<S8>/Enable'
       */
      /* SignalConversion generated from: '<S8>/Enable' */
      if (PMSM_to_BLDC_mod1_B.Ib_flag > 0.0) {
        /* MATLABSystem: '<S12>/Analog to Digital Converter' */
        if (PMSM_to_BLDC_mod1_DW.obj_d.TunablePropsChanged) {
          PMSM_to_BLDC_mod1_DW.obj_d.TunablePropsChanged = false;
        }

        regularReadADCNormal(PMSM_to_BLDC_mod1_DW.obj_d.ADCHandle,
                             ADC_TRIGGER_AND_READ, &status);

        /* End of MATLABSystem: '<S12>/Analog to Digital Converter' */
      }

      /* End of SignalConversion generated from: '<S8>/Enable' */
      /* End of Outputs for SubSystem: '<S2>/Subsystem' */

      /* Outputs for Enabled SubSystem: '<S2>/Subsystem1' incorporates:
       *  EnablePort: '<S9>/Enable'
       */
      /* SignalConversion generated from: '<S9>/Enable' */
      if (PMSM_to_BLDC_mod1_B.Ic_flag > 0.0) {
        /* MATLABSystem: '<S15>/Analog to Digital Converter' */
        if (PMSM_to_BLDC_mod1_DW.obj_o.TunablePropsChanged) {
          PMSM_to_BLDC_mod1_DW.obj_o.TunablePropsChanged = false;
        }

        regularReadADCNormal(PMSM_to_BLDC_mod1_DW.obj_o.ADCHandle,
                             ADC_TRIGGER_AND_READ, &status);

        /* End of MATLABSystem: '<S15>/Analog to Digital Converter' */
      }

      /* End of SignalConversion generated from: '<S9>/Enable' */
      /* End of Outputs for SubSystem: '<S2>/Subsystem1' */
      /* End of Outputs for SubSystem: '<Root>/Current_sensing' */
    }
  }

  if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M)) {
    NeslSimulationData *simulationData;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    char *msg;
    real_T tmp_0[28];
    real_T time;
    int32_T tmp_2;
    int_T tmp_1[8];
    boolean_T tmp;

    /* Update for Enabled SubSystem: '<Root>/Subsystem' incorporates:
     *  EnablePort: '<S7>/Enable'
     */
    if (PMSM_to_BLDC_mod1_DW.Subsystem_MODE) {
      if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M) &&
          PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0) {
        /* Update for Delay: '<S55>/Delay' */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[0] =
          PMSM_to_BLDC_mod1_B.VectorConcatenate[0];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[1] =
          PMSM_to_BLDC_mod1_B.VectorConcatenate[1];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE[2] =
          PMSM_to_BLDC_mod1_B.VectorConcatenate[2];

        /* Update for Delay: '<S58>/Delay' */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[0] =
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[4];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[1] =
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[5];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[2] =
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[6];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[3] =
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[7];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[4] =
          rtb_TmpSignalConversionAtDelayI[0];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[5] =
          rtb_TmpSignalConversionAtDelayI[1];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[6] =
          rtb_TmpSignalConversionAtDelayI[2];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[7] =
          rtb_TmpSignalConversionAtDelayI[3];

        /* Update for Delay: '<S248>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad = false;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[0] = rtb_Add1[0];
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[1] = rtb_Add1[1];

        /* Update for Delay: '<S331>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_f = false;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_a = rtb_Add1_e;

        /* Update for DiscreteIntegrator: '<S300>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE = PMSM_to_BLDC_mod1_B.Integrator;
        PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState = 0;

        /* Update for Delay: '<S356>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_a = false;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_ai = rtb_Switch2;

        /* Update for DiscreteIntegrator: '<S170>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b += rtb_Switch_e;
        PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState_n = 1;

        /* Update for DiscreteIntegrator: '<S115>/Integrator' */
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n += rtb_Switch;
        PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState_nt = 1;

        /* Update for Delay: '<S262>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_b = false;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_g = rtb_Add1_d;
      }

      /* Update for Integrator: '<S390>/Integrator' */
      PMSM_to_BLDC_mod1_DW.Integrator_DWORK1 = false;

      /* Update for Integrator: '<S391>/Integrator' */
      PMSM_to_BLDC_mod1_DW.Integrator_DWORK1_g = false;

      /* Update for SimscapeExecutionBlock: '<S416>/STATE_1' */
      simulationData = (NeslSimulationData *)
        PMSM_to_BLDC_mod1_DW.STATE_1_SimData;
      time = PMSM_to_BLDC_mod1_M->Timing.t[0];
      simulationData->mData->mTime.mN = 1;
      simulationData->mData->mTime.mX = &time;
      simulationData->mData->mContStates.mN = 17;
      simulationData->mData->mContStates.mX =
        &PMSM_to_BLDC_mod1_X.PMSM_to_BLDC_mod1SubsystemFOCIn[0];
      simulationData->mData->mDiscStates.mN = 0;
      simulationData->mData->mDiscStates.mX =
        &PMSM_to_BLDC_mod1_DW.STATE_1_Discrete;
      simulationData->mData->mModeVector.mN = 11;
      simulationData->mData->mModeVector.mX =
        &PMSM_to_BLDC_mod1_DW.STATE_1_Modes[0];
      tmp = false;
      simulationData->mData->mFoundZcEvents = tmp;
      simulationData->mData->mHadEvents = false;
      simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
        (PMSM_to_BLDC_mod1_M);
      tmp = false;
      simulationData->mData->mIsSolverAssertCheck = tmp;
      simulationData->mData->mIsSolverCheckingCIC = false;
      tmp = rtsiIsSolverComputingJacobian(&PMSM_to_BLDC_mod1_M->solverInfo);
      simulationData->mData->mIsComputingJacobian = tmp;
      simulationData->mData->mIsEvaluatingF0 = false;
      simulationData->mData->mIsSolverRequestingReset = false;
      simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
        (&PMSM_to_BLDC_mod1_M->solverInfo);
      tmp_1[0] = 0;
      tmp_0[0] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[0];
      tmp_0[1] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[1];
      tmp_0[2] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[2];
      tmp_0[3] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[3];
      tmp_1[1] = 4;
      tmp_0[4] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[0];
      tmp_0[5] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[1];
      tmp_0[6] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[2];
      tmp_0[7] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[3];
      tmp_1[2] = 8;
      tmp_0[8] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[0];
      tmp_0[9] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[1];
      tmp_0[10] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[2];
      tmp_0[11] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[3];
      tmp_1[3] = 12;
      tmp_0[12] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[0];
      tmp_0[13] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[1];
      tmp_0[14] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[2];
      tmp_0[15] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[3];
      tmp_1[4] = 16;
      tmp_0[16] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[0];
      tmp_0[17] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[1];
      tmp_0[18] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[2];
      tmp_0[19] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[3];
      tmp_1[5] = 20;
      tmp_0[20] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[0];
      tmp_0[21] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[1];
      tmp_0[22] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[2];
      tmp_0[23] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[3];
      tmp_1[6] = 24;
      tmp_0[24] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[0];
      tmp_0[25] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[1];
      tmp_0[26] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[2];
      tmp_0[27] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[3];
      tmp_1[7] = 28;
      simulationData->mData->mInputValues.mN = 28;
      simulationData->mData->mInputValues.mX = &tmp_0[0];
      simulationData->mData->mInputOffsets.mN = 8;
      simulationData->mData->mInputOffsets.mX = &tmp_1[0];
      diagnosticManager = (NeuDiagnosticManager *)
        PMSM_to_BLDC_mod1_DW.STATE_1_DiagMgr;
      diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
      tmp_2 = ne_simulator_method((NeslSimulator *)
        PMSM_to_BLDC_mod1_DW.STATE_1_Simulator, NESL_SIM_UPDATE, simulationData,
        diagnosticManager);
      if (tmp_2 != 0) {
        tmp = error_buffer_is_empty(rtmGetErrorStatus(PMSM_to_BLDC_mod1_M));
        if (tmp) {
          msg = rtw_diagnostics_msg(diagnosticTree);
          rtmSetErrorStatus(PMSM_to_BLDC_mod1_M, msg);
        }
      }

      /* End of Update for SimscapeExecutionBlock: '<S416>/STATE_1' */
    }

    /* End of Update for SubSystem: '<Root>/Subsystem' */
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

    rate_scheduler();
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void PMSM_to_BLDC_mod1_derivatives(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  XDot_PMSM_to_BLDC_mod1_T *_rtXdot;
  char *msg;
  real_T tmp[28];
  real_T time;
  int32_T tmp_1;
  int_T tmp_0[8];
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_PMSM_to_BLDC_mod1_T *) PMSM_to_BLDC_mod1_M->derivs);

  /* Derivatives for Enabled SubSystem: '<Root>/Subsystem' */
  if (PMSM_to_BLDC_mod1_DW.Subsystem_MODE) {
    /* Derivatives for Integrator: '<S455>/Integrator' */
    _rtXdot->Integrator_CSTATE = PMSM_to_BLDC_mod1_B.IntegralGain;

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

    /* Derivatives for Integrator: '<S375>/Int1' incorporates:
     *  Constant: '<S371>/Speed_Angular_Vel'
     */
    _rtXdot->Int1_CSTATE = 600.0;

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

    /* Derivatives for SimscapeExecutionBlock: '<S416>/STATE_1' */
    simulationData = (NeslSimulationData *)PMSM_to_BLDC_mod1_DW.STATE_1_SimData;
    time = PMSM_to_BLDC_mod1_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 17;
    simulationData->mData->mContStates.mX =
      &PMSM_to_BLDC_mod1_X.PMSM_to_BLDC_mod1SubsystemFOCIn[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &PMSM_to_BLDC_mod1_DW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 11;
    simulationData->mData->mModeVector.mX = &PMSM_to_BLDC_mod1_DW.STATE_1_Modes
      [0];
    lsat = false;
    simulationData->mData->mFoundZcEvents = lsat;
    simulationData->mData->mHadEvents = false;
    simulationData->mData->mIsMajorTimeStep = rtmIsMajorTimeStep
      (PMSM_to_BLDC_mod1_M);
    lsat = false;
    simulationData->mData->mIsSolverAssertCheck = lsat;
    simulationData->mData->mIsSolverCheckingCIC = false;
    lsat = rtsiIsSolverComputingJacobian(&PMSM_to_BLDC_mod1_M->solverInfo);
    simulationData->mData->mIsComputingJacobian = lsat;
    simulationData->mData->mIsEvaluatingF0 = false;
    simulationData->mData->mIsSolverRequestingReset = false;
    simulationData->mData->mIsModeUpdateTimeStep = rtsiIsModeUpdateTimeStep
      (&PMSM_to_BLDC_mod1_M->solverInfo);
    tmp_0[0] = 0;
    tmp[0] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[0];
    tmp[1] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[1];
    tmp[2] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[2];
    tmp[3] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[3];
    tmp_0[1] = 4;
    tmp[4] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[0];
    tmp[5] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[1];
    tmp[6] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[2];
    tmp[7] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[3];
    tmp_0[2] = 8;
    tmp[8] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[0];
    tmp[9] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[1];
    tmp[10] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[2];
    tmp[11] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[3];
    tmp_0[3] = 12;
    tmp[12] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[0];
    tmp[13] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[1];
    tmp[14] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[2];
    tmp[15] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[3];
    tmp_0[4] = 16;
    tmp[16] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[0];
    tmp[17] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[1];
    tmp[18] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[2];
    tmp[19] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[3];
    tmp_0[5] = 20;
    tmp[20] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[0];
    tmp[21] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[1];
    tmp[22] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[2];
    tmp[23] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[3];
    tmp_0[6] = 24;
    tmp[24] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[0];
    tmp[25] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[1];
    tmp[26] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[2];
    tmp[27] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[3];
    tmp_0[7] = 28;
    simulationData->mData->mInputValues.mN = 28;
    simulationData->mData->mInputValues.mX = &tmp[0];
    simulationData->mData->mInputOffsets.mN = 8;
    simulationData->mData->mInputOffsets.mX = &tmp_0[0];
    simulationData->mData->mDx.mN = 17;
    simulationData->mData->mDx.mX = &_rtXdot->PMSM_to_BLDC_mod1SubsystemFOCIn[0];
    diagnosticManager = (NeuDiagnosticManager *)
      PMSM_to_BLDC_mod1_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_1 = ne_simulator_method((NeslSimulator *)
      PMSM_to_BLDC_mod1_DW.STATE_1_Simulator, NESL_SIM_DERIVATIVES,
      simulationData, diagnosticManager);
    if (tmp_1 != 0) {
      lsat = error_buffer_is_empty(rtmGetErrorStatus(PMSM_to_BLDC_mod1_M));
      if (lsat) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(PMSM_to_BLDC_mod1_M, msg);
      }
    }

    /* End of Derivatives for SimscapeExecutionBlock: '<S416>/STATE_1' */
  } else {
    {
      real_T *dx;
      int_T i1;
      dx = &(((XDot_PMSM_to_BLDC_mod1_T *) PMSM_to_BLDC_mod1_M->derivs)
             ->Integrator_CSTATE);
      for (i1=0; i1 < 21; i1++) {
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
  PMSM_to_BLDC_mod1_M->Timing.stepSize0 = 0.0001;
  rtmSetFirstInitCond(PMSM_to_BLDC_mod1_M, 1);

  {
    NeModelParameters modelParameters;
    NeModelParameters modelParameters_0;
    NeslRtpManager *manager;
    NeslRtpManager *manager_0;
    NeslSimulationData *tmp_1;
    NeslSimulator *tmp_0;
    NeuDiagnosticManager *diagnosticManager;
    NeuDiagnosticTree *diagnosticTree;
    NeuDiagnosticTree *diagnosticTree_0;
    char *msg;
    char *msg_0;
    real_T tmp_2;
    int32_T tmp_3;
    boolean_T tmp;
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
    /* Start for MATLABSystem: '<S19>/SPI Receive' */
    PMSM_to_BLDC_mod1_DW.obj_g.isInitialized = 0;
    PMSM_to_BLDC_mod1_DW.obj_g.matlabCodegenIsDeleted = false;
    PMSM_to_BL_SystemCore_setup_oxg(&PMSM_to_BLDC_mod1_DW.obj_g);

    /* Start for MATLABSystem: '<S19>/SPI Transmit' */
    PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted = false;
    PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete = false;
    PMSM_to_BLDC_mod1_DW.obj_j.isInitialized = 1;
    PMSM_to_SPIDrvBlock_setupImpl_o(&PMSM_to_BLDC_mod1_DW.obj_j);
    PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete = true;

    /* End of SystemInitialize for SubSystem: '<S4>/Control_Reg2' */

    /* SystemInitialize for Enabled SubSystem: '<S4>/Ctrl_Reg_1' */
    /* Start for MATLABSystem: '<S20>/SPI Transmit' */
    PMSM_to_BLDC_mod1_DW.obj_n.matlabCodegenIsDeleted = false;
    PMSM_to_BLDC_mod1_DW.obj_n.isSetupComplete = false;
    PMSM_to_BLDC_mod1_DW.obj_n.isInitialized = 1;
    PMSM_to_SPIDrvBlock_setupImpl_o(&PMSM_to_BLDC_mod1_DW.obj_n);
    PMSM_to_BLDC_mod1_DW.obj_n.isSetupComplete = true;
    PMSM_to_BLDC_mo_SPIReceive_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_j);

    /* End of SystemInitialize for SubSystem: '<S4>/Ctrl_Reg_1' */
    /* End of SystemInitialize for SubSystem: '<Root>/SPI_Write' */

    /* SystemInitialize for Enabled SubSystem: '<S6>/Status_Reg1_read' */
    PMSM_to_BLDC__SPIReceive_e_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnae);
    PMSM_to_BLDC_SPITransmit_d_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnaev);

    /* End of SystemInitialize for SubSystem: '<S6>/Status_Reg1_read' */

    /* SystemInitialize for Enabled SubSystem: '<S6>/Status_Reg_2_read' */
    PMSM_to_BLDC__SPIReceive_e_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaev);
    PMSM_to_BLDC_SPITransmit_d_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnaevv);

    /* End of SystemInitialize for SubSystem: '<S6>/Status_Reg_2_read' */

    /* SystemInitialize for Enabled SubSystem: '<Root>/Subsystem' */
    /* Start for If: '<S249>/If' */
    PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem = -1;

    /* Start for SwitchCase: '<S258>/Switch Case' */
    PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem = -1;

    /* Start for If: '<S255>/If' */
    PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_g = -1;

    /* Start for SwitchCase: '<S257>/Switch Case' */
    PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem_n = -1;

    /* Start for If: '<S360>/If' */
    PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_e = -1;

    /* Start for If: '<S221>/If' */
    PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_c = -1;

    /* Start for If: '<S195>/If' */
    PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_m = -1;

    /* Start for SimscapeRtp: '<S407>/RTP_1' */
    manager_0 = nesl_lease_rtp_manager(
      "PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration_1",
      0);
    manager = manager_0;
    tmp = pointer_is_null(manager_0);
    if (tmp) {
      PMSM_to_BLDC_mod1_5da39267_1_gateway();
      manager = nesl_lease_rtp_manager(
        "PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration_1",
        0);
    }

    PMSM_to_BLDC_mod1_DW.RTP_1_RtpManager = (void *)manager;
    PMSM_to_BLDC_mod1_DW.RTP_1_SetParametersNeeded = true;

    /* End of Start for SimscapeRtp: '<S407>/RTP_1' */

    /* Start for SimscapeExecutionBlock: '<S416>/STATE_1' */
    tmp_0 = nesl_lease_simulator(
      "PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration_1",
      0, 0);
    PMSM_to_BLDC_mod1_DW.STATE_1_Simulator = (void *)tmp_0;
    tmp = pointer_is_null(PMSM_to_BLDC_mod1_DW.STATE_1_Simulator);
    if (tmp) {
      PMSM_to_BLDC_mod1_5da39267_1_gateway();
      tmp_0 = nesl_lease_simulator(
        "PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration_1",
        0, 0);
      PMSM_to_BLDC_mod1_DW.STATE_1_Simulator = (void *)tmp_0;
    }

    tmp_1 = nesl_create_simulation_data();
    PMSM_to_BLDC_mod1_DW.STATE_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    PMSM_to_BLDC_mod1_DW.STATE_1_DiagMgr = (void *)diagnosticManager;
    modelParameters.mSolverType = NE_SOLVER_TYPE_ODE;
    modelParameters.mSolverTolerance = 0.001;
    modelParameters.mSolverAbsTol = 0.001;
    modelParameters.mSolverRelTol = 0.001;
    modelParameters.mVariableStepSolver = false;
    modelParameters.mIsUsingODEN = false;
    modelParameters.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters.mFixedStepSize = 0.0001;
    modelParameters.mStartTime = 0.0;
    modelParameters.mLoadInitialState = false;
    modelParameters.mUseSimState = false;
    modelParameters.mLinTrimCompile = false;
    modelParameters.mLoggingMode = SSC_LOGGING_OFF;
    modelParameters.mRTWModifiedTimeStamp = 6.9988766E+8;
    modelParameters.mZcDisabled = true;
    modelParameters.mUseModelRefSolver = false;
    modelParameters.mTargetFPGAHIL = false;
    tmp_2 = 0.001;
    modelParameters.mSolverTolerance = tmp_2;
    tmp_2 = 0.0001;
    modelParameters.mFixedStepSize = tmp_2;
    tmp = false;
    modelParameters.mVariableStepSolver = tmp;
    tmp = false;
    modelParameters.mIsUsingODEN = tmp;
    modelParameters.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)
      PMSM_to_BLDC_mod1_DW.STATE_1_DiagMgr;
    diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      PMSM_to_BLDC_mod1_DW.STATE_1_Simulator, &modelParameters,
      diagnosticManager);
    if (tmp_3 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(PMSM_to_BLDC_mod1_M));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(PMSM_to_BLDC_mod1_M, msg);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S416>/STATE_1' */

    /* Start for SimscapeExecutionBlock: '<S416>/OUTPUT_1_0' */
    tmp_0 = nesl_lease_simulator(
      "PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration_1",
      1, 0);
    PMSM_to_BLDC_mod1_DW.OUTPUT_1_0_Simulator = (void *)tmp_0;
    tmp = pointer_is_null(PMSM_to_BLDC_mod1_DW.OUTPUT_1_0_Simulator);
    if (tmp) {
      PMSM_to_BLDC_mod1_5da39267_1_gateway();
      tmp_0 = nesl_lease_simulator(
        "PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration_1",
        1, 0);
      PMSM_to_BLDC_mod1_DW.OUTPUT_1_0_Simulator = (void *)tmp_0;
    }

    tmp_1 = nesl_create_simulation_data();
    PMSM_to_BLDC_mod1_DW.OUTPUT_1_0_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    PMSM_to_BLDC_mod1_DW.OUTPUT_1_0_DiagMgr = (void *)diagnosticManager;
    modelParameters_0.mSolverType = NE_SOLVER_TYPE_ODE;
    modelParameters_0.mSolverTolerance = 0.001;
    modelParameters_0.mSolverAbsTol = 0.001;
    modelParameters_0.mSolverRelTol = 0.001;
    modelParameters_0.mVariableStepSolver = false;
    modelParameters_0.mIsUsingODEN = false;
    modelParameters_0.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_0.mFixedStepSize = 0.0001;
    modelParameters_0.mStartTime = 0.0;
    modelParameters_0.mLoadInitialState = false;
    modelParameters_0.mUseSimState = false;
    modelParameters_0.mLinTrimCompile = false;
    modelParameters_0.mLoggingMode = SSC_LOGGING_OFF;
    modelParameters_0.mRTWModifiedTimeStamp = 6.9988766E+8;
    modelParameters_0.mZcDisabled = true;
    modelParameters_0.mUseModelRefSolver = false;
    modelParameters_0.mTargetFPGAHIL = false;
    tmp_2 = 0.001;
    modelParameters_0.mSolverTolerance = tmp_2;
    tmp_2 = 0.0001;
    modelParameters_0.mFixedStepSize = tmp_2;
    tmp = false;
    modelParameters_0.mVariableStepSolver = tmp;
    tmp = false;
    modelParameters_0.mIsUsingODEN = tmp;
    modelParameters_0.mZcDisabled = true;
    diagnosticManager = (NeuDiagnosticManager *)
      PMSM_to_BLDC_mod1_DW.OUTPUT_1_0_DiagMgr;
    diagnosticTree_0 = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
    tmp_3 = nesl_initialize_simulator((NeslSimulator *)
      PMSM_to_BLDC_mod1_DW.OUTPUT_1_0_Simulator, &modelParameters_0,
      diagnosticManager);
    if (tmp_3 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(PMSM_to_BLDC_mod1_M));
      if (tmp) {
        msg_0 = rtw_diagnostics_msg(diagnosticTree_0);
        rtmSetErrorStatus(PMSM_to_BLDC_mod1_M, msg_0);
      }
    }

    /* End of Start for SimscapeExecutionBlock: '<S416>/OUTPUT_1_0' */

    /* InitializeConditions for Delay: '<S248>/Delay' */
    PMSM_to_BLDC_mod1_DW.icLoad = true;

    /* InitializeConditions for Delay: '<S331>/Delay' */
    PMSM_to_BLDC_mod1_DW.icLoad_f = true;

    /* InitializeConditions for Delay: '<S356>/Delay' */
    PMSM_to_BLDC_mod1_DW.icLoad_a = true;

    /* InitializeConditions for DiscreteIntegrator: '<S170>/Integrator' */
    PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b =
      PMSM_to_BLDC_mod1_ConstB.Constant3_n;

    /* InitializeConditions for Integrator: '<S455>/Integrator' */
    PMSM_to_BLDC_mod1_X.Integrator_CSTATE = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S115>/Integrator' */
    PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n =
      PMSM_to_BLDC_mod1_ConstB.Constant3;

    /* InitializeConditions for Delay: '<S262>/Delay' */
    PMSM_to_BLDC_mod1_DW.icLoad_b = true;

    /* InitializeConditions for Integrator: '<S390>/Integrator' incorporates:
     *  Integrator: '<S391>/Integrator'
     */
    if (rtmIsFirstInitCond(PMSM_to_BLDC_mod1_M)) {
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d = 0.0;
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l = 0.0;
    }

    PMSM_to_BLDC_mod1_DW.Integrator_DWORK1 = true;

    /* End of InitializeConditions for Integrator: '<S390>/Integrator' */

    /* InitializeConditions for Integrator: '<S375>/Int1' */
    PMSM_to_BLDC_mod1_X.Int1_CSTATE = 0.0;

    /* InitializeConditions for Integrator: '<S391>/Integrator' */
    PMSM_to_BLDC_mod1_DW.Integrator_DWORK1_g = true;

    /* SystemInitialize for IfAction SubSystem: '<S257>/IntegralMethod' */
    /* InitializeConditions for Delay: '<S338>/Delay' */
    PMSM_to_BLDC_mod1_DW.icLoad_bd = true;

    /* InitializeConditions for Delay: '<S341>/Delay' */
    PMSM_to_BLDC_mod1_DW.icLoad_k = true;

    /* End of SystemInitialize for SubSystem: '<S257>/IntegralMethod' */

    /* SystemInitialize for IfAction SubSystem: '<S257>/OptimizedDifferentiationMethod' */
    /* InitializeConditions for Delay: '<S348>/Delay' */
    PMSM_to_BLDC_mod1_DW.icLoad_b1 = true;

    /* InitializeConditions for Delay: '<S351>/Delay' */
    PMSM_to_BLDC_mod1_DW.icLoad_c = true;

    /* End of SystemInitialize for SubSystem: '<S257>/OptimizedDifferentiationMethod' */

    /* Start for MATLABSystem: '<S474>/PWM Output' */
    PMSM_to_BLDC_mod1_DW.obj_e.matlabCodegenIsDeleted = false;
    PMSM_to_BLDC_mod1_DW.obj_e.isSetupComplete = false;
    PMSM_to_BLDC_mod1_DW.obj_e.isInitialized = 1;
    PMSM_to_BLD_PWMOutput_setupImpl(&PMSM_to_BLDC_mod1_DW.obj_e);
    PMSM_to_BLDC_mod1_DW.obj_e.isSetupComplete = true;

    /* End of SystemInitialize for SubSystem: '<Root>/Subsystem' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/SPI_read' */
    /* SystemInitialize for Enabled SubSystem: '<S31>/Subsystem1' */
    PMSM_to_BLDC_mo_SPIReceive_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pn);
    PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pn);

    /* End of SystemInitialize for SubSystem: '<S31>/Subsystem1' */

    /* SystemInitialize for Enabled SubSystem: '<S31>/Subsystem' */
    /* Start for MATLABSystem: '<S33>/SPI Receive' */
    PMSM_to_BLDC_mod1_DW.obj.isInitialized = 0;
    PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = false;
    PMSM_to_B_SystemCore_setup_oxgk(&PMSM_to_BLDC_mod1_DW.obj);
    PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_p);

    /* End of SystemInitialize for SubSystem: '<S31>/Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S32>/Subsystem' */
    PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pna);

    /* End of SystemInitialize for SubSystem: '<S32>/Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S32>/Subsystem1' */
    PMSM_to_BLDC_mo_SPIReceive_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pna);
    PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnae);

    /* End of SystemInitialize for SubSystem: '<S32>/Subsystem1' */
    /* End of SystemInitialize for SubSystem: '<Root>/SPI_read' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/En_gate' */
    /* Start for MATLABSystem: '<S18>/Digital Port Write' */
    PMSM_to_BLDC_mod1_DW.obj_ow.matlabCodegenIsDeleted = false;
    PMSM_to_BLDC_mod1_DW.obj_ow.isInitialized = 1;
    PMSM_to_BLDC_mod1_DW.obj_ow.isSetupComplete = true;

    /* End of SystemInitialize for SubSystem: '<Root>/En_gate' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Current_sensing' */
    /* SystemInitialize for Enabled SubSystem: '<S2>/Subsystem' */
    /* Start for MATLABSystem: '<S12>/Analog to Digital Converter' */
    PMSM_to_BLDC_mod1_DW.obj_d.isInitialized = 0;
    PMSM_to_BLDC_mod1_DW.obj_d.matlabCodegenIsDeleted = false;
    PMSM_to_BLDC_SystemCore_setup_o(&PMSM_to_BLDC_mod1_DW.obj_d);

    /* End of SystemInitialize for SubSystem: '<S2>/Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S2>/Subsystem1' */
    /* Start for MATLABSystem: '<S15>/Analog to Digital Converter' */
    PMSM_to_BLDC_mod1_DW.obj_o.isInitialized = 0;
    PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted = false;
    PMSM_to_BLD_SystemCore_setup_ox(&PMSM_to_BLDC_mod1_DW.obj_o);

    /* End of SystemInitialize for SubSystem: '<S2>/Subsystem1' */
    /* End of SystemInitialize for SubSystem: '<Root>/Current_sensing' */

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
  /* Terminate for MATLABSystem: '<S19>/SPI Receive' */
  if (!PMSM_to_BLDC_mod1_DW.obj_g.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_g.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_g.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_g.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S19>/SPI Receive' */

  /* Terminate for MATLABSystem: '<S19>/SPI Transmit' */
  if (!PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_j.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S19>/SPI Transmit' */
  /* End of Terminate for SubSystem: '<S4>/Control_Reg2' */

  /* Terminate for Enabled SubSystem: '<S4>/Ctrl_Reg_1' */
  /* Terminate for MATLABSystem: '<S20>/SPI Transmit' */
  if (!PMSM_to_BLDC_mod1_DW.obj_n.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_n.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_n.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_n.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S20>/SPI Transmit' */
  PMSM_to_BLDC_mo_SPIReceive_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_j);

  /* End of Terminate for SubSystem: '<S4>/Ctrl_Reg_1' */
  /* End of Terminate for SubSystem: '<Root>/SPI_Write' */

  /* Terminate for Enabled SubSystem: '<S6>/Status_Reg1_read' */
  PMSM_to_BLDC__SPIReceive_m_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnae);
  PMSM_to_BLDC_SPITransmit_a_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnaev);

  /* End of Terminate for SubSystem: '<S6>/Status_Reg1_read' */

  /* Terminate for Enabled SubSystem: '<S6>/Status_Reg_2_read' */
  PMSM_to_BLDC__SPIReceive_m_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaev);
  PMSM_to_BLDC_SPITransmit_a_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnaevv);

  /* End of Terminate for SubSystem: '<S6>/Status_Reg_2_read' */

  /* Terminate for Enabled SubSystem: '<Root>/Subsystem' */
  /* Terminate for MATLABSystem: '<S474>/PWM Output' */
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

  /* End of Terminate for MATLABSystem: '<S474>/PWM Output' */

  /* Terminate for SimscapeExecutionBlock: '<S416>/STATE_1' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    PMSM_to_BLDC_mod1_DW.STATE_1_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    PMSM_to_BLDC_mod1_DW.STATE_1_SimData);
  nesl_erase_simulator("PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration_1");

  /* Terminate for SimscapeExecutionBlock: '<S416>/OUTPUT_1_0' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    PMSM_to_BLDC_mod1_DW.OUTPUT_1_0_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    PMSM_to_BLDC_mod1_DW.OUTPUT_1_0_SimData);
  nesl_erase_simulator("PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration_1");

  /* End of Terminate for SubSystem: '<Root>/Subsystem' */

  /* Terminate for Atomic SubSystem: '<Root>/SPI_read' */
  /* Terminate for Enabled SubSystem: '<S31>/Subsystem1' */
  PMSM_to_BLDC_mo_SPIReceive_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pn);
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pn);

  /* End of Terminate for SubSystem: '<S31>/Subsystem1' */

  /* Terminate for Enabled SubSystem: '<S31>/Subsystem' */
  /* Terminate for MATLABSystem: '<S33>/SPI Receive' */
  if (!PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S33>/SPI Receive' */
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_p);

  /* End of Terminate for SubSystem: '<S31>/Subsystem' */

  /* Terminate for Enabled SubSystem: '<S32>/Subsystem' */
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pna);

  /* End of Terminate for SubSystem: '<S32>/Subsystem' */

  /* Terminate for Enabled SubSystem: '<S32>/Subsystem1' */
  PMSM_to_BLDC_mo_SPIReceive_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pna);
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnae);

  /* End of Terminate for SubSystem: '<S32>/Subsystem1' */
  /* End of Terminate for SubSystem: '<Root>/SPI_read' */

  /* Terminate for Atomic SubSystem: '<Root>/En_gate' */
  /* Terminate for MATLABSystem: '<S18>/Digital Port Write' */
  if (!PMSM_to_BLDC_mod1_DW.obj_ow.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_ow.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S18>/Digital Port Write' */
  /* End of Terminate for SubSystem: '<Root>/En_gate' */

  /* Terminate for Atomic SubSystem: '<Root>/Current_sensing' */
  /* Terminate for Enabled SubSystem: '<S2>/Subsystem' */
  /* Terminate for MATLABSystem: '<S12>/Analog to Digital Converter' */
  if (!PMSM_to_BLDC_mod1_DW.obj_d.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_d.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_d.isSetupComplete) {
      ADC_Handle_Deinit(PMSM_to_BLDC_mod1_DW.obj_d.ADCHandle, ADC_NORMAL_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S12>/Analog to Digital Converter' */
  /* End of Terminate for SubSystem: '<S2>/Subsystem' */

  /* Terminate for Enabled SubSystem: '<S2>/Subsystem1' */
  /* Terminate for MATLABSystem: '<S15>/Analog to Digital Converter' */
  if (!PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_o.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_o.isSetupComplete) {
      ADC_Handle_Deinit(PMSM_to_BLDC_mod1_DW.obj_o.ADCHandle, ADC_NORMAL_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S15>/Analog to Digital Converter' */
  /* End of Terminate for SubSystem: '<S2>/Subsystem1' */
  /* End of Terminate for SubSystem: '<Root>/Current_sensing' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
