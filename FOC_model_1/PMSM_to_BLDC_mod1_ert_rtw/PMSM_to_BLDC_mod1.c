/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.c
 *
 * Code generated for Simulink model 'PMSM_to_BLDC_mod1'.
 *
 * Model version                  : 4.843
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Sat May  2 12:34:52 2026
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
#include <string.h>
#include <stddef.h>
#include "stm_timer_ll.h"
#include "zero_crossing_types.h"
#include <float.h>

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

/* Mass Matrices */
MassMatrix_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_MassMatrix;

/* Real-time model */
static RT_MODEL_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_M_;
RT_MODEL_PMSM_to_BLDC_mod1_T *const PMSM_to_BLDC_mod1_M = &PMSM_to_BLDC_mod1_M_;

/* Forward declaration for local functions */
static void PMSM_to_BLD_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_PM_T *obj);

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

  /* Projection for SimscapeExecutionBlock: '<S364>/STATE_1' */
  simulationData = (NeslSimulationData *)PMSM_to_BLDC_mod1_DW.STATE_1_SimData;
  time = PMSM_to_BLDC_mod1_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 17;
  simulationData->mData->mContStates.mX =
    &PMSM_to_BLDC_mod1_X.PMSM_to_BLDC_mod1SubsystemInver[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &PMSM_to_BLDC_mod1_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 11;
  simulationData->mData->mModeVector.mX = &PMSM_to_BLDC_mod1_DW.STATE_1_Modes[0];
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
    PMSM_to_BLDC_mod1_DW.STATE_1_Simulator, NESL_SIM_PROJECTION, simulationData,
    diagnosticManager);
  if (tmp_2 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(PMSM_to_BLDC_mod1_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(PMSM_to_BLDC_mod1_M, msg);
    }
  }

  /* End of Projection for SimscapeExecutionBlock: '<S364>/STATE_1' */
}

/* ForcingFunction for root system: '<Root>' */
void PMSM_to_BLDC_mod1_forcingfunction(void)
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

  /* ForcingFunction for Integrator: '<S403>/Integrator' */
  _rtXdot->Integrator_CSTATE = PMSM_to_BLDC_mod1_B.IntegralGain;

  /* ForcingFunction for Integrator: '<S338>/Integrator' */
  lsat = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d <= -1.0E+7);
  usat = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d >= 1.0E+7);
  if (((!lsat) && (!usat)) || (lsat && (PMSM_to_BLDC_mod1_B.Add_h > 0.0)) ||
      (usat && (PMSM_to_BLDC_mod1_B.Add_h < 0.0))) {
    _rtXdot->Integrator_CSTATE_d = PMSM_to_BLDC_mod1_B.Add_h;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE_d = 0.0;
  }

  /* End of ForcingFunction for Integrator: '<S338>/Integrator' */

  /* ForcingFunction for Integrator: '<S323>/Int1' incorporates:
   *  Constant: '<S319>/Speed_Angular_Vel'
   */
  _rtXdot->Int1_CSTATE = 600.0;

  /* ForcingFunction for Integrator: '<S339>/Integrator' */
  lsat = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l <= -1.0E+7);
  usat = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l >= 1.0E+7);
  if (((!lsat) && (!usat)) || (lsat && (PMSM_to_BLDC_mod1_B.Add_d > 0.0)) ||
      (usat && (PMSM_to_BLDC_mod1_B.Add_d < 0.0))) {
    _rtXdot->Integrator_CSTATE_l = PMSM_to_BLDC_mod1_B.Add_d;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE_l = 0.0;
  }

  /* End of ForcingFunction for Integrator: '<S339>/Integrator' */

  /* ForcingFunction for SimscapeExecutionBlock: '<S364>/STATE_1' */
  simulationData = (NeslSimulationData *)PMSM_to_BLDC_mod1_DW.STATE_1_SimData;
  time = PMSM_to_BLDC_mod1_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 17;
  simulationData->mData->mContStates.mX =
    &PMSM_to_BLDC_mod1_X.PMSM_to_BLDC_mod1SubsystemInver[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &PMSM_to_BLDC_mod1_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 11;
  simulationData->mData->mModeVector.mX = &PMSM_to_BLDC_mod1_DW.STATE_1_Modes[0];
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
  simulationData->mData->mDx.mX = &_rtXdot->PMSM_to_BLDC_mod1SubsystemInver[0];
  diagnosticManager = (NeuDiagnosticManager *)
    PMSM_to_BLDC_mod1_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_1 = ne_simulator_method((NeslSimulator *)
    PMSM_to_BLDC_mod1_DW.STATE_1_Simulator, NESL_SIM_FORCINGFUNCTION,
    simulationData, diagnosticManager);
  if (tmp_1 != 0) {
    lsat = error_buffer_is_empty(rtmGetErrorStatus(PMSM_to_BLDC_mod1_M));
    if (lsat) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(PMSM_to_BLDC_mod1_M, msg);
    }
  }

  /* End of ForcingFunction for SimscapeExecutionBlock: '<S364>/STATE_1' */
}

/* MassMatrix for root system: '<Root>' */
void PMSM_to_BLDC_mod1_massmatrix(void)
{
  NeslSimulationData *simulationData;
  NeuDiagnosticManager *diagnosticManager;
  NeuDiagnosticTree *diagnosticTree;
  char *msg;
  real_T tmp_0[28];
  real_T time;
  real_T *tmp_2;
  real_T *tmp_3;
  int32_T tmp_4;
  int_T tmp_1[8];
  boolean_T tmp;

  /* MassMatrix for SimscapeExecutionBlock: '<S364>/STATE_1' */
  simulationData = (NeslSimulationData *)PMSM_to_BLDC_mod1_DW.STATE_1_SimData;
  time = PMSM_to_BLDC_mod1_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 17;
  simulationData->mData->mContStates.mX =
    &PMSM_to_BLDC_mod1_X.PMSM_to_BLDC_mod1SubsystemInver[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &PMSM_to_BLDC_mod1_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 11;
  simulationData->mData->mModeVector.mX = &PMSM_to_BLDC_mod1_DW.STATE_1_Modes[0];
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
  tmp_2 = PMSM_to_BLDC_mod1_M->massMatrixPr;
  tmp_3 = double_pointer_shift(tmp_2,
    PMSM_to_BLDC_mod1_DW.STATE_1_MASS_MATRIX_PR);
  simulationData->mData->mMassMatrixPr.mN = 5;
  simulationData->mData->mMassMatrixPr.mX = tmp_3;
  diagnosticManager = (NeuDiagnosticManager *)
    PMSM_to_BLDC_mod1_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_4 = ne_simulator_method((NeslSimulator *)
    PMSM_to_BLDC_mod1_DW.STATE_1_Simulator, NESL_SIM_MASSMATRIX, simulationData,
    diagnosticManager);
  if (tmp_4 != 0) {
    tmp = error_buffer_is_empty(rtmGetErrorStatus(PMSM_to_BLDC_mod1_M));
    if (tmp) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(PMSM_to_BLDC_mod1_M, msg);
    }
  }

  /* End of MassMatrix for SimscapeExecutionBlock: '<S364>/STATE_1' */
}

void local_evaluateMassMatrix(RTWSolverInfo *si, real_T *Mdest )
{
  /* Refresh global mass matrix */
  PMSM_to_BLDC_mod1_massmatrix();

  /* Copy the mass matrix from system to the destination, if needed. */
  if (Mdest != rtsiGetSolverMassMatrixPr(si)) {
    real_T *Msrc = rtsiGetSolverMassMatrixPr(si);
    int_T nzmax = rtsiGetSolverMassMatrixNzMax(si);
    (void) memcpy(Mdest, Msrc,
                  (uint_T)nzmax*sizeof(real_T));
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

/* Simplified version of numjac.cpp, for use with RTW. */
void local_numjac( RTWSolverInfo *si, real_T *y, const real_T *Fty, real_T *fac,
                  real_T *dFdy )
{
  /* constants */
  real_T THRESH = 1e-6;
  real_T EPS = 2.2e-16;                /* utGetEps(); */
  real_T BL = pow(EPS, 0.75);
  real_T BU = pow(EPS, 0.25);
  real_T FACMIN = pow(EPS, 0.78);
  real_T FACMAX = 0.1;
  int_T nx = 21;
  real_T *x = rtsiGetContStates(si);
  boolean_T *xdis = rtsiGetContStateDisabledPtr(si);
  real_T del;
  real_T difmax;
  real_T FdelRowmax;
  real_T temp;
  real_T Fdiff;
  real_T maybe;
  real_T xscale;
  real_T fscale;
  real_T *p;
  int_T rowmax;
  int_T i,j;
  if (x != y)
    (void) memcpy(x, y,
                  (uint_T)nx*sizeof(real_T));
  rtsiSetSolverComputingJacobian(si,true);
  for (p = dFdy, j = 0; j < nx; j++, p += nx) {
    /* Zero column j of dFdy if state j is currently disabled. */
    if (xdis[j]) {
      (void) memset(p, 0,
                    (uint_T)nx*sizeof(p[0]));
      continue;
    }

    /* Select an increment del for a difference approximation to
       column j of dFdy.  The vector fac accounts for experience
       gained in previous calls to numjac. */
    xscale = fabs(x[j]);
    if (xscale < THRESH)
      xscale = THRESH;
    temp = (x[j] + fac[j]*xscale);
    del = temp - y[j];
    while (del == 0.0) {
      if (fac[j] < FACMAX) {
        fac[j] *= 100.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
        temp = (x[j] + fac[j]*xscale);
        del = temp - x[j];
      } else {
        del = THRESH;                  /* thresh is nonzero */
        break;
      }
    }

    /* Keep del pointing into region. */
    if (Fty[j] >= 0.0)
      del = fabs(del);
    else
      del = -fabs(del);

    /* Form a difference approximation to column j of dFdy. */
    temp = x[j];
    x[j] += del;
    PMSM_to_BLDC_mod1_step();
    rtsiSetdX(si,p);
    PMSM_to_BLDC_mod1_forcingfunction();
    x[j] = temp;
    difmax = 0.0;
    rowmax = 0;
    FdelRowmax = p[0];
    temp = 1.0 / del;
    for (i = 0; i < nx; i++) {
      Fdiff = p[i] - Fty[i];
      maybe = fabs(Fdiff);
      if (maybe > difmax) {
        difmax = maybe;
        rowmax = i;
        FdelRowmax = p[i];
      }

      p[i] = temp * Fdiff;
    }

    /* Adjust fac for next call to numjac. */
    if (((FdelRowmax != 0.0) && (Fty[rowmax] != 0.0)) || (difmax == 0.0)) {
      fscale = fabs(FdelRowmax);
      if (fscale < fabs(Fty[rowmax]))
        fscale = fabs(Fty[rowmax]);
      if (difmax <= BL*fscale) {
        /* The difference is small, so increase the increment. */
        fac[j] *= 10.0;
        if (fac[j] > FACMAX)
          fac[j] = FACMAX;
      } else if (difmax > BU*fscale) {
        /* The difference is large, so reduce the increment. */
        fac[j] *= 0.1;
        if (fac[j] < FACMIN)
          fac[j] = FACMIN;
      }
    }
  }

  rtsiSetSolverComputingJacobian(si,false);
}                                      /* end local_numjac */

/*
 * This function updates continuous states using the ODE14X fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static int_T rt_ODE14x_N[4] = { 12, 8, 6, 4 };

  time_T t0 = rtsiGetT(si);
  time_T t1 = t0;
  time_T h = rtsiGetStepSize(si);
  real_T *x1 = rtsiGetContStates(si);
  int_T order = rtsiGetSolverExtrapolationOrder(si);
  int_T numIter = rtsiGetSolverNumberNewtonIterations(si);
  ODE14X_IntgData *id = (ODE14X_IntgData *)rtsiGetSolverData(si);
  real_T *x0 = id->x0;
  real_T *f0 = id->f0;
  real_T *x1start = id->x1start;
  real_T *f1 = id->f1;
  real_T *Delta = id->Delta;
  real_T *E = id->E;
  real_T *fac = id->fac;
  real_T *dfdx = id->DFDX;
  real_T *W = id->W;
  int_T *pivots = id->pivots;
  real_T *xtmp = id->xtmp;
  real_T *ztmp = id->ztmp;
  boolean_T *xdis = rtsiGetContStateDisabledPtr(si);
  int_T *Mpattern_ir = rtsiGetSolverMassMatrixIr(si);
  int_T *Mpattern_jc = rtsiGetSolverMassMatrixJc(si);
  real_T *M = id->M;
  int_T col,row,rowidx;
  int_T *N = &(rt_ODE14x_N[0]);
  int_T i,j,k,iter;
  int_T nx = 21;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(x0, x1,
                (uint_T)nx*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  if (id->isFirstStep) {
    local_evaluateMassMatrix(si,M );
    id->isFirstStep = false;
  }

  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  PMSM_to_BLDC_mod1_forcingfunction();
  local_numjac(si,x0,f0,fac,dfdx );
  for (j = 0; j < order; j++) {
    real_T *p;
    real_T hN = h/N[j];

    /* Get the iteration matrix and solution at t0 */

    /* [L,U] = lu(M - hN*J) */
    (void) memcpy(W, dfdx,
                  (uint_T)nx*(uint_T)nx*sizeof(real_T));
    for (p = W, i = 0; i < nx*nx; i++, p++) {
      *p *= (-hN);
    }

    for (col = 0, p = W; col < nx; col++, p += nx) {
      if (xdis[col]) {
        (void) memset(p, 0,
                      (uint_T)nx*sizeof(p[0]));
        p[col] = 1.0;
      } else {
        for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++) {
          real_T m_row_col = M[rowidx];
          row = Mpattern_ir[rowidx];
          p[row] += m_row_col;
        }
      }
    }

    rt_lu_real(W, nx,
               pivots);

    /* First Newton's iteration at t0. */
    /* rhs = hN*f0 */
    for (i = 0; i < nx; i++) {
      Delta[i] = hN*f0[i];
    }

    /* Delta = (U \ (L \ rhs)) */
    rt_ForwardSubstitutionRR_Dbl(W, Delta,
      f1, nx,
      1, pivots,
      1);
    rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
      Delta, nx,
      1, 0);

    /* ytmp = y0 + Delta
       ztmp = (ytmp-y0)/h
     */
    (void) memcpy(x1, x0,
                  (uint_T)nx*sizeof(real_T));
    for (i = 0; i < nx; i++) {
      x1[i] += Delta[i];
      ztmp[i] = Delta[i]/hN;
    }

    /* Additional Newton's iterations, if desired.
       for iter = 2:NewtIter
       rhs = hN*feval(odefun,tn,ytmp,extraArgs{:}) - M*(ytmp - yn);
       if statedepM   % only for state dep. Mdel ~= 0
       Mdel = M - feval(massfun,tn,ytmp);
       rhs = rhs + Mdel*ztmp*h;
       end
       Delta = ( U \ ( L \ rhs ) );
       ytmp = ytmp + Delta;
       ztmp = (ytmp - yn)/h
       end
     */
    rtsiSetT(si, t0);
    rtsiSetdX(si, f1);
    for (iter = 1; iter < numIter; iter++) {
      PMSM_to_BLDC_mod1_step();
      PMSM_to_BLDC_mod1_forcingfunction();
      for (i = 0; i < nx; i++) {
        Delta[i] = hN*f1[i];
        xtmp[i] = x1[i] - x0[i];
      }

      /* rhs = hN*f(tn,ytmp) - M*(ytmp-yn) */
      for (col = 0; col < nx; col++) {
        for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx++) {
          real_T m_row_col = M[rowidx];
          row = Mpattern_ir[rowidx];
          Delta[row] -= m_row_col*xtmp[col];
        }
      }

      rt_ForwardSubstitutionRR_Dbl(W, Delta,
        f1, nx,
        1, pivots,
        1);
      rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
        Delta, nx,
        1, 0);

      /* ytmp = ytmp + delta
         ztmp = (ytmp - yn)/h
       */
      for (i = 0; i < nx; i++) {
        x1[i] += Delta[i];
        ztmp[i] = (x1[i] - x0[i])/hN;
      }
    }

    /* Steps from t0+hN to t1 -- subintegration of N(j) steps for extrapolation
       ttmp = t0;
       for i = 2:N(j)
       ttmp = ttmp + hN
       ytmp0 = ytmp;
       for iter = 1:NewtIter
       rhs = (ytmp0 - ytmp) + hN*feval(odefun,ttmp,ytmp,extraArgs{:});
       Delta = ( U \ ( L \ rhs ) );
       ytmp = ytmp + Delta;
       end
       end
     */
    for (k = 1; k < N[j]; k++) {
      t1 = t0 + k*hN;
      (void) memcpy(x1start, x1,
                    (uint_T)nx*sizeof(real_T));
      rtsiSetT(si, t1);
      rtsiSetdX(si, f1);
      for (iter = 0; iter < numIter; iter++) {
        PMSM_to_BLDC_mod1_step();
        PMSM_to_BLDC_mod1_forcingfunction();
        if (iter == 0) {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
          }
        } else {
          for (i = 0; i < nx; i++) {
            Delta[i] = hN*f1[i];
            xtmp[i] = (x1[i]-x1start[i]);
          }

          /* rhs = hN*f(tn,ytmp) - M*(ytmp-yn) */
          for (col = 0; col < nx; col++) {
            for (rowidx = Mpattern_jc[col]; rowidx < Mpattern_jc[col+1]; rowidx
                 ++) {
              real_T m_row_col = M[rowidx];
              row = Mpattern_ir[rowidx];
              Delta[row] -= m_row_col*xtmp[col];
            }
          }
        }

        rt_ForwardSubstitutionRR_Dbl(W, Delta,
          f1, nx,
          1, pivots,
          1);
        rt_BackwardSubstitutionRR_Dbl(W+nx*nx-1, f1+nx-1,
          Delta, nx,
          1, 0);

        /* ytmp = ytmp + Delta
           ztmp = (ytmp - ytmp0)/h
         */
        for (i = 0; i < nx; i++) {
          x1[i] += Delta[i];
          ztmp[i] = (x1[i] - x1start[i])/hN;
        }
      }
    }

    /* Extrapolate to order j
       E(:,j) = ytmp
       for k = j:-1:2
       coef = N(k-1)/(N(j) - N(k-1))
       E(:,k-1) = E(:,k) + coef*( E(:,k) - E(:,k-1) )
       end
     */
    (void) memcpy(&(E[nx*j]), x1,
                  (uint_T)nx*sizeof(real_T));
    for (k = j; k > 0; k--) {
      real_T coef = (real_T)(N[k-1]) / (N[j]-N[k-1]);
      for (i = 0; i < nx; i++) {
        x1[i] = E[nx*k+i] + coef*(E[nx*k+i] - E[nx*(k-1)+i]);
      }

      (void) memcpy(&(E[nx*(k-1)]), x1,
                    (uint_T)nx*sizeof(real_T));
    }
  }

  /* x1 = E(:,1); */
  (void) memcpy(x1, E,
                (uint_T)nx*sizeof(real_T));

  /* t1 = t0 + h; */
  rtsiSetT(si,rtsiGetSolverStopTime(si));
  PMSM_to_BLDC_mod1_step();
  PMSM_to_BLDC_mod1_projection();
  local_stateReduction(rtsiGetContStates(si), rtsiGetPeriodicContStateIndices(si),
                       1,
                       rtsiGetPeriodicContStateRanges(si));
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for action system:
 *    '<S143>/If Action Subsystem'
 *    '<S169>/If Action Subsystem'
 */
real_T PMSM_to_BLDC__IfActionSubsystem(real_T rtu_In1)
{
  real_T tmp;

  /* DataTypeConversion: '<S146>/Convert_uint16' */
  tmp = floor(rtu_In1);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* Sum: '<S146>/Sum' incorporates:
   *  DataTypeConversion: '<S146>/Convert_back'
   *  DataTypeConversion: '<S146>/Convert_uint16'
   */
  return rtu_In1 - (real_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
    -tmp : (int32_T)(int16_T)(uint16_T)tmp);
}

/*
 * Output and update for action system:
 *    '<S143>/If Action Subsystem1'
 *    '<S169>/If Action Subsystem1'
 */
real_T PMSM_to_BLDC_IfActionSubsystem1(real_T rtu_In1)
{
  real_T tmp;

  /* DataTypeConversion: '<S147>/Convert_uint16' */
  tmp = trunc(rtu_In1);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* Sum: '<S147>/Sum' incorporates:
   *  DataTypeConversion: '<S147>/Convert_back'
   *  DataTypeConversion: '<S147>/Convert_uint16'
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

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void PMSM_to_BLD_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_PM_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S5>/PWM Output' */
  b.PeripheralPtr = TIM8;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S5>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S5>/PWM Output' */
    enableCounter(obj->TimerHandle, true);
  }
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
    real_T rtb_Add_k;
    real_T rtb_DeadZone;
    real_T rtb_Gain4_i_tmp;
    real_T rtb_Gain4_i_tmp_0;
    real_T rtb_Gain_e;
    real_T rtb_Integrator;
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
    real_T tmp_6;
    int32_T tmp_2;
    int_T tmp_3[9];
    int_T tmp_1[8];
    real32_T rtb_Saturation_or;
    real32_T rtb_indexing;
    uint32_T freq;
    uint16_T rtb_Get_Integer;
    int8_T rtAction;
    int8_T rtPrevAction;
    boolean_T ok;
    boolean_T tmp_0;
    boolean_T tmp_4;
    boolean_T tmp_5;
    tmp_5 = rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M);
    if (tmp_5) {
      /* Sum: '<S23>/Sum2' incorporates:
       *  Delay: '<S2>/Delay'
       *  Gain: '<S23>/one_by_3'
       *  Sum: '<S23>/Sum'
       */
      rtb_uabc3 = PMSM_to_BLDC_mod1_DW.Delay_DSTATE[0] -
        ((PMSM_to_BLDC_mod1_DW.Delay_DSTATE[0] +
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE[1]) +
         PMSM_to_BLDC_mod1_DW.Delay_DSTATE[2]) * 0.33333333333333331;

      /* Gain: '<S23>/one_by_sqrt3_' incorporates:
       *  Delay: '<S2>/Delay'
       *  Sum: '<S23>/Sum1'
       */
      rtb_one_by_sqrt3_ = (PMSM_to_BLDC_mod1_DW.Delay_DSTATE[1] -
                           PMSM_to_BLDC_mod1_DW.Delay_DSTATE[2]) *
        0.57735026918962584;

      /* Delay: '<S179>/Delay1' */
      if (PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE == POS_ZCSIG) {
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f = 0.0F;
      }

      PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE = 0U;

      /* Gain: '<S185>/Gain' incorporates:
       *  Delay: '<S179>/Delay1'
       */
      rtb_Gain_e = -0.0017999999690800905 * PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f;

      /* Gain: '<S192>/Gain1' incorporates:
       *  Delay: '<S6>/Delay'
       */
      rtb_Add3 = 555.55555555555554 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[1];

      /* Gain: '<S192>/Gain' incorporates:
       *  Delay: '<S6>/Delay'
       */
      rtb_Add1_f = 555.55555555555554 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[0];

      /* Sum: '<S193>/Sum' incorporates:
       *  Product: '<S193>/Product'
       *  Product: '<S193>/Product2'
       *  UnaryMinus: '<S193>/Unary Minus'
       */
      rtb_Add2 = -rtb_Gain_e * rtb_Add3 - rtb_Add1_f;

      /* Sum: '<S193>/Sum1' incorporates:
       *  Product: '<S193>/Product1'
       *  Product: '<S193>/Product3'
       */
      rtb_Add1_f = rtb_Add1_f * rtb_Gain_e - rtb_Add3;

      /* Gain: '<S184>/Gain' incorporates:
       *  Delay: '<S179>/Delay1'
       */
      rtb_Gain_e = -0.0017999999690800905 * PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f;

      /* Sum: '<S189>/Sum1' incorporates:
       *  Delay: '<S6>/Delay'
       *  Product: '<S189>/Product3'
       */
      rtb_Add3 = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[2] * rtb_Gain_e -
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[3];

      /* Sum: '<S189>/Sum' incorporates:
       *  Delay: '<S6>/Delay'
       *  Product: '<S189>/Product2'
       *  UnaryMinus: '<S189>/Unary Minus'
       */
      rtb_Integrator = -rtb_Gain_e * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[3] -
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[2];

      /* Product: '<S188>/Product' incorporates:
       *  Delay: '<S179>/Delay1'
       */
      rtb_Add_k = rtb_Integrator * PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f;

      /* Gain: '<S187>/Gain' */
      rtb_Gain4_i_tmp = 555.55555555555554 * rtb_Integrator;

      /* Gain: '<S187>/Gain1' */
      rtb_Gain4_i_tmp_0 = 555.55555555555554 * rtb_Add3;

      /* Gain: '<S331>/Gain4' incorporates:
       *  Gain: '<S187>/Gain'
       *  Gain: '<S187>/Gain1'
       *  Product: '<S190>/Product2'
       *  Sum: '<S190>/Sum'
       *  UnaryMinus: '<S187>/Unary Minus1'
       *  UnaryMinus: '<S190>/Unary Minus'
       */
      rtb_Gain4_i = -rtb_Gain4_i_tmp_0 * -rtb_Gain_e + rtb_Gain4_i_tmp;

      /* Gain: '<S331>/Gain3' incorporates:
       *  Constant: '<S186>/(Ld-Lq)_Ld'
       *  Constant: '<S186>/R_Ld'
       *  Delay: '<S179>/Delay1'
       *  Delay: '<S6>/Delay'
       *  Product: '<S186>/Product'
       *  Product: '<S186>/Product3'
       *  Product: '<S186>/Product5'
       *  Sum: '<S186>/Sum1'
       *  UnaryMinus: '<S186>/Unary Minus1'
       */
      rtb_Gain3_c = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[3] * -20.555555555555554;
      rtb_Gain3_c += PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[2] *
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f * 0.0;

      /* Product: '<S191>/Product2' incorporates:
       *  UnaryMinus: '<S191>/Unary Minus'
       */
      rtb_Product2_a = -rtb_Gain_e * rtb_Gain3_c;

      /* Sum: '<S186>/Sum' incorporates:
       *  Constant: '<S186>/(Ld-Lq)_Ld'
       *  Constant: '<S186>/R_Ld'
       *  Delay: '<S179>/Delay1'
       *  Delay: '<S6>/Delay'
       *  Product: '<S186>/Product1'
       *  Product: '<S186>/Product2'
       *  Product: '<S186>/Product4'
       *  UnaryMinus: '<S186>/Unary Minus'
       *  UnaryMinus: '<S186>/Unary Minus1'
       */
      rtb_Product1_o = -(PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[3] *
                         PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f) * 0.0 +
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_m[2] * -20.555555555555554;

      /* Gain: '<S331>/Gain3' incorporates:
       *  Product: '<S191>/Product1'
       *  Product: '<S191>/Product3'
       *  Sum: '<S191>/Sum1'
       */
      rtb_Gain3_c = rtb_Product1_o * rtb_Gain_e - rtb_Gain3_c;

      /* Delay: '<S183>/Delay' */
      if (PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE == POS_ZCSIG) {
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0] = 0.0;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1] = 0.0;
      }

      PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE = 0U;

      /* Sum: '<S183>/Sum2' incorporates:
       *  Delay: '<S183>/Delay'
       *  Sum: '<S183>/Sum'
       */
      Merge_i = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0];
      tmp_6 = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1];

      /* Gain: '<S183>/Gain2' incorporates:
       *  Delay: '<S179>/Delay1'
       *  Delay: '<S183>/Delay'
       *  Gain: '<S183>/Gain1'
       *  Product: '<S188>/Product1'
       *  Product: '<S190>/Product3'
       *  Product: '<S191>/Product'
       *  Sum: '<S183>/Sum'
       *  Sum: '<S183>/Sum2'
       *  Sum: '<S184>/Sum'
       *  Sum: '<S190>/Sum1'
       *  Sum: '<S191>/Sum'
       *  UnaryMinus: '<S187>/Unary Minus'
       *  UnaryMinus: '<S188>/Unary Minus'
       */
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0] = ((((-(rtb_Add3 *
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f) - rtb_Gain4_i) - (rtb_Product2_a -
        rtb_Product1_o)) - rtb_Add2) * 5.0E-5 + Merge_i) * 0.972972972972973;
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1] = ((((rtb_Add_k - (-rtb_Gain4_i_tmp
        * rtb_Gain_e + rtb_Gain4_i_tmp_0)) - rtb_Gain3_c) - rtb_Add1_f) * 5.0E-5
        + tmp_6) * 0.972972972972973;

      /* Delay: '<S196>/Delay' incorporates:
       *  Constant: '<S181>/IC'
       */
      if (PMSM_to_BLDC_mod1_DW.icLoad) {
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[0] = 0.0;
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[1] = 0.0;
      }

      /* Sum: '<S196>/Add1' incorporates:
       *  Constant: '<S179>/V_PU'
       *  Delay: '<S183>/Delay'
       *  Delay: '<S196>/Delay'
       *  Product: '<S179>/Product'
       *  Product: '<S196>/Product'
       *  Product: '<S196>/Product1'
       *  Sum: '<S183>/Sum1'
       */
      rtb_Add1[0] = (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[0] + rtb_Integrator) *
        0.020833333333333332 * 0.70204348915944692 +
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[0] * 0.29795651084055308;
      rtb_Add1[1] = (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_c[1] + rtb_Add3) *
        0.020833333333333332 * 0.70204348915944692 + 0.29795651084055308 *
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[1];

      /* Relay: '<S197>/AlphaRelay' */
      PMSM_to_BLDC_mod1_DW.AlphaRelay_Mode = ((rtb_Add1[0] >= 0.02) ||
        ((!(rtb_Add1[0] <= -0.02)) && PMSM_to_BLDC_mod1_DW.AlphaRelay_Mode));

      /* Relay: '<S197>/BetaRelay' */
      PMSM_to_BLDC_mod1_DW.BetaRelay_Mode = ((rtb_Add1[1] >= 0.02) ||
        ((!(rtb_Add1[1] <= -0.02)) && PMSM_to_BLDC_mod1_DW.BetaRelay_Mode));

      /* Outputs for Triggered SubSystem: '<S197>/Dir_Sense' incorporates:
       *  TriggerPort: '<S199>/Trigger'
       */
      /* If: '<S197>/If' incorporates:
       *  Relay: '<S197>/AlphaRelay'
       *  SwitchCase: '<S206>/Switch Case'
       */
      if (rtsiIsModeUpdateTimeStep(&PMSM_to_BLDC_mod1_M->solverInfo)) {
        if (PMSM_to_BLDC_mod1_DW.AlphaRelay_Mode &&
            (PMSM_to_BLDC_mod1_PrevZCX.Dir_Sense_Trig_ZCE != POS_ZCSIG)) {
          /* Switch: '<S199>/Switch' incorporates:
           *  Relay: '<S197>/BetaRelay'
           */
          if (PMSM_to_BLDC_mod1_DW.BetaRelay_Mode) {
            /* Switch: '<S199>/Switch' incorporates:
             *  Constant: '<S199>/Constant'
             */
            PMSM_to_BLDC_mod1_B.Switch = -1;
          } else {
            /* Switch: '<S199>/Switch' incorporates:
             *  Constant: '<S199>/Constant1'
             */
            PMSM_to_BLDC_mod1_B.Switch = 1;
          }

          /* End of Switch: '<S199>/Switch' */
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

      /* End of Outputs for SubSystem: '<S197>/Dir_Sense' */
      if (PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem == 0) {
        /* Outputs for IfAction SubSystem: '<S197>/Subsystem2' incorporates:
         *  ActionPort: '<S200>/Action Port'
         */
        /* UnaryMinus: '<S200>/Unary Minus' */
        rtb_Add1_f = -rtb_Add1[0];

        /* SignalConversion generated from: '<S200>/SigmaBeta' */
        rtb_Gain_e = rtb_Add1[1];

        /* End of Outputs for SubSystem: '<S197>/Subsystem2' */
      } else {
        /* Outputs for IfAction SubSystem: '<S197>/Subsystem3' incorporates:
         *  ActionPort: '<S201>/Action Port'
         */
        /* UnaryMinus: '<S201>/Unary Minus' */
        rtb_Gain_e = -rtb_Add1[1];

        /* SignalConversion generated from: '<S201>/SigmaAlpha' */
        rtb_Add1_f = rtb_Add1[0];

        /* End of Outputs for SubSystem: '<S197>/Subsystem3' */
      }

      /* End of If: '<S197>/If' */

      /* SwitchCase: '<S206>/Switch Case' */
      if (PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem == 0) {
        /* Outputs for IfAction SubSystem: '<S206>/If Action Subsystem' incorporates:
         *  ActionPort: '<S300>/Action Port'
         */
        /* Merge: '<S206>/Merge' incorporates:
         *  Constant: '<S206>/Constant'
         *  SignalConversion generated from: '<S300>/In1'
         *  SignalConversion generated from: '<S300>/Out1'
         */
        PMSM_to_BLDC_mod1_B.Merge[0] = 0.0;
        PMSM_to_BLDC_mod1_B.Merge[1] = 0.0;

        /* End of Outputs for SubSystem: '<S206>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S206>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S301>/Action Port'
         */
        /* Merge: '<S206>/Merge' incorporates:
         *  SignalConversion generated from: '<S301>/In1'
         */
        PMSM_to_BLDC_mod1_B.Merge[0] = rtb_Add1_f;
        PMSM_to_BLDC_mod1_B.Merge[1] = rtb_Gain_e;

        /* End of Outputs for SubSystem: '<S206>/If Action Subsystem1' */
      }

      /* Product: '<S203>/Product' */
      rtb_Gain_e = PMSM_to_BLDC_mod1_B.Merge[0] * PMSM_to_BLDC_mod1_B.Merge[0];

      /* Gain: '<S331>/Gain3' incorporates:
       *  Product: '<S203>/Product1'
       */
      rtb_Gain3_c = PMSM_to_BLDC_mod1_B.Merge[1] * PMSM_to_BLDC_mod1_B.Merge[1];

      /* Sum: '<S203>/Sum' */
      PMSM_to_BLDC_mod1_B.Sum = rtb_Gain_e + rtb_Gain3_c;

      /* RelationalOperator: '<S211>/Compare' incorporates:
       *  Constant: '<S211>/Constant'
       */
      PMSM_to_BLDC_mod1_B.Compare = (PMSM_to_BLDC_mod1_B.Sum > 0.0);
    }

    /* If: '<S203>/If' */
    rtPrevAction = PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_g;

    /* If: '<S169>/If' incorporates:
     *  If: '<S143>/If'
     *  If: '<S203>/If'
     *  If: '<S308>/If'
     *  SimscapeExecutionBlock: '<S364>/OUTPUT_1_0'
     *  SimscapeExecutionBlock: '<S364>/STATE_1'
     *  SwitchCase: '<S205>/Switch Case'
     */
    tmp_4 = rtsiIsModeUpdateTimeStep(&PMSM_to_BLDC_mod1_M->solverInfo);

    /* If: '<S203>/If' */
    if (tmp_4) {
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
      /* Outputs for IfAction SubSystem: '<S203>/Subsystem' incorporates:
       *  ActionPort: '<S213>/Action Port'
       */
      /* Sqrt: '<S213>/Sqrt' */
      Merge_i = sqrt(PMSM_to_BLDC_mod1_B.Sum);

      /* Merge: '<S203>/Merge1' incorporates:
       *  Product: '<S213>/Divide'
       *  SignalConversion generated from: '<S213>/Out2'
       */
      rtb_Add1_f = 1.0 / Merge_i * PMSM_to_BLDC_mod1_B.Merge[1];

      /* Merge: '<S203>/Merge' incorporates:
       *  Product: '<S213>/Divide1'
       *  SignalConversion generated from: '<S213>/Out1'
       */
      Merge_i = PMSM_to_BLDC_mod1_B.Merge[0] / Merge_i;

      /* End of Outputs for SubSystem: '<S203>/Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S203>/If Action Subsystem' incorporates:
       *  ActionPort: '<S212>/Action Port'
       */
      /* Merge: '<S203>/Merge' incorporates:
       *  DataTypeConversion: '<S212>/Data Type Conversion'
       *  SignalConversion generated from: '<S212>/Out1'
       */
      Merge_i = PMSM_to_BLDC_mod1_B.Merge[0];

      /* Merge: '<S203>/Merge1' incorporates:
       *  DataTypeConversion: '<S212>/Data Type Conversion1'
       *  SignalConversion generated from: '<S212>/Out2'
       */
      rtb_Add1_f = PMSM_to_BLDC_mod1_B.Merge[1];

      /* End of Outputs for SubSystem: '<S203>/If Action Subsystem' */
    }

    if (tmp_5) {
      /* SwitchCase: '<S205>/Switch Case' incorporates:
       *  Delay: '<S296>/Delay'
       */
      if (tmp_4) {
        rtAction = 1;
        PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem_n = 1;
      } else {
        rtAction = PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem_n;
      }

      if (rtAction == 0) {
        /* Outputs for IfAction SubSystem: '<S205>/IntegralMethod' incorporates:
         *  ActionPort: '<S269>/Action Port'
         */
        /* Delay: '<S286>/Delay' */
        if (PMSM_to_BLDC_mod1_DW.icLoad_bd) {
          /* Sum: '<S286>/Add1' incorporates:
           *  Constant: '<S280>/IC'
           */
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av = 0.0;
        }

        /* Sum: '<S286>/Add1' incorporates:
         *  Delay: '<S286>/Delay'
         *  Product: '<S286>/Product'
         *  Product: '<S286>/Product1'
         *  Switch: '<S286>/Switch'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av = rtb_Add1_f * 0.95650500031643548
          + 0.043494999683564517 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av;

        /* Delay: '<S283>/Delay1' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_p == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay1_DSTATE = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_p = 0U;

        /* Delay: '<S283>/Delay' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_h == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_f = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_h = 0U;

        /* Sum: '<S283>/Sum1' incorporates:
         *  Constant: '<S266>/I1Cnst'
         *  Constant: '<S266>/I2Cnst'
         *  Delay: '<S283>/Delay'
         *  Delay: '<S283>/Delay1'
         *  Product: '<S283>/Product'
         *  Product: '<S283>/Product1'
         *  Sum: '<S283>/Sum'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_f =
          (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av +
           PMSM_to_BLDC_mod1_DW.Delay1_DSTATE) * 2.4945142765920684E-5 +
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_f * 0.99561142127365465;

        /* Delay: '<S289>/Delay' */
        if (PMSM_to_BLDC_mod1_DW.icLoad_k) {
          /* Sum: '<S289>/Add1' incorporates:
           *  Constant: '<S281>/IC'
           */
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d = 0.0;
        }

        /* Sum: '<S289>/Add1' incorporates:
         *  Delay: '<S289>/Delay'
         *  Product: '<S289>/Product'
         *  Product: '<S289>/Product1'
         *  Switch: '<S289>/Switch'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d = Merge_i * 0.95650500031643548 +
          0.043494999683564517 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d;

        /* Delay: '<S282>/Delay1' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_i == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_o = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_i = 0U;

        /* Delay: '<S282>/Delay' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_k == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_k = 0U;

        /* Sum: '<S282>/Sum1' incorporates:
         *  Constant: '<S266>/I1Cnst'
         *  Constant: '<S266>/I2Cnst'
         *  Delay: '<S282>/Delay'
         *  Delay: '<S282>/Delay1'
         *  Product: '<S282>/Product'
         *  Product: '<S282>/Product1'
         *  Sum: '<S282>/Sum'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i =
          (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d +
           PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_o) * 2.4945142765920684E-5 +
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i * 0.99561142127365465;

        /* Math: '<S269>/Math Function' incorporates:
         *  Delay: '<S282>/Delay'
         *  Delay: '<S283>/Delay'
         *  Product: '<S269>/Product'
         *  Product: '<S269>/Product1'
         *  Sum: '<S269>/Sum'
         *
         * About '<S269>/Math Function':
         *  Operator: reciprocal
         */
        rtb_Add_k = 1.0 / (PMSM_to_BLDC_mod1_DW.Delay_DSTATE_f * Merge_i -
                           PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i * rtb_Add1_f);

        /* Switch: '<S269>/Switch1' incorporates:
         *  Abs: '<S269>/Abs'
         */
        if (fabs(rtb_Add_k) > 87964.5943005142) {
          /* Merge: '<S205>/Merge' incorporates:
           *  Constant: '<S269>/Constant'
           */
          rtb_Add_k = 0.0;
        }

        /* End of Switch: '<S269>/Switch1' */

        /* Update for Delay: '<S286>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_bd = false;

        /* Update for Delay: '<S283>/Delay1' */
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE =
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_av;

        /* Update for Delay: '<S289>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_k = false;

        /* Update for Delay: '<S282>/Delay1' */
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_o =
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_d;

        /* End of Outputs for SubSystem: '<S205>/IntegralMethod' */
      } else {
        /* Outputs for IfAction SubSystem: '<S205>/OptimizedDifferentiationMethod' incorporates:
         *  ActionPort: '<S272>/Action Port'
         */
        if (PMSM_to_BLDC_mod1_DW.icLoad_b1) {
          /* Sum: '<S296>/Add1' incorporates:
           *  Constant: '<S292>/IC'
           *  Delay: '<S296>/Delay'
           */
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aa = 0.0;
        }

        /* Sum: '<S296>/Add1' incorporates:
         *  Delay: '<S296>/Delay'
         *  Product: '<S296>/Product'
         *  Product: '<S296>/Product1'
         *  Switch: '<S296>/Switch'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aa = rtb_Add1_f * 0.95650500031643548
          + 0.043494999683564517 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aa;

        /* Product: '<S291>/Product' incorporates:
         *  Constant: '<S266>/OD1Cnst'
         */
        rtb_Product_fc = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aa *
          2.1991148575128554E+6;

        /* Delay: '<S291>/Delay2' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay2_DSTATE = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE = 0U;

        /* Delay: '<S291>/Delay3' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay3_DSTATE = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE = 0U;

        /* Product: '<S291>/Product1' incorporates:
         *  Constant: '<S266>/OD2Cnst'
         *  Delay: '<S291>/Delay2'
         *  Delay: '<S291>/Delay3'
         *  Sum: '<S291>/Sum1'
         */
        PMSM_to_BLDC_mod1_DW.Delay3_DSTATE =
          ((PMSM_to_BLDC_mod1_DW.Delay3_DSTATE + rtb_Product_fc) -
           PMSM_to_BLDC_mod1_DW.Delay2_DSTATE) * 0.0090126024492556654;

        /* Delay: '<S290>/Delay2' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE_p == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_h = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE_p = 0U;
        rtb_Add_k = PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_h;

        /* Delay: '<S290>/Delay3' */
        if (PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE_k == POS_ZCSIG) {
          PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_p = 0.0;
        }

        PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE_k = 0U;

        /* Delay: '<S299>/Delay' */
        if (PMSM_to_BLDC_mod1_DW.icLoad_c) {
          /* Sum: '<S299>/Add1' incorporates:
           *  Constant: '<S293>/IC'
           */
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_l = 0.0;
        }

        /* Sum: '<S299>/Add1' incorporates:
         *  Delay: '<S299>/Delay'
         *  Product: '<S299>/Product'
         *  Product: '<S299>/Product1'
         *  Switch: '<S299>/Switch'
         */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_l = Merge_i * 0.95650500031643548 +
          0.043494999683564517 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_l;

        /* Product: '<S290>/Product' incorporates:
         *  Constant: '<S266>/OD1Cnst'
         *  Delay: '<S290>/Delay2'
         */
        PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_h =
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_l * 2.1991148575128554E+6;

        /* Product: '<S290>/Product1' incorporates:
         *  Constant: '<S266>/OD2Cnst'
         *  Delay: '<S290>/Delay2'
         *  Delay: '<S290>/Delay3'
         *  Sum: '<S290>/Sum1'
         */
        PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_p =
          ((PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_p +
            PMSM_to_BLDC_mod1_DW.Delay2_DSTATE_h) - rtb_Add_k) *
          0.0090126024492556654;

        /* Merge: '<S205>/Merge' incorporates:
         *  Delay: '<S290>/Delay3'
         *  Delay: '<S291>/Delay3'
         *  Product: '<S272>/Product'
         *  Product: '<S272>/Product1'
         *  Sum: '<S272>/Sum'
         */
        rtb_Add_k = PMSM_to_BLDC_mod1_DW.Delay3_DSTATE_p * rtb_Add1_f -
          PMSM_to_BLDC_mod1_DW.Delay3_DSTATE * Merge_i;

        /* Update for Delay: '<S296>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_b1 = false;

        /* Update for Delay: '<S291>/Delay2' */
        PMSM_to_BLDC_mod1_DW.Delay2_DSTATE = rtb_Product_fc;

        /* Update for Delay: '<S299>/Delay' */
        PMSM_to_BLDC_mod1_DW.icLoad_c = false;

        /* End of Outputs for SubSystem: '<S205>/OptimizedDifferentiationMethod' */
      }

      /* Gain: '<S331>/Gain3' incorporates:
       *  Constant: '<S205>/SpdFilterCoeff'
       *  Constant: '<S267>/One'
       *  Sum: '<S267>/Sum'
       */
      rtb_Gain3_c = 0.99530971347415453;

      /* Switch: '<S267>/Switch1' */
      rtb_Product_j_idx_1 = rtb_Gain3_c;

      /* Delay: '<S279>/Delay' incorporates:
       *  Constant: '<S267>/IC'
       */
      if (PMSM_to_BLDC_mod1_DW.icLoad_f) {
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_a = 0.0;
      }

      /* Gain: '<S331>/Gain3' incorporates:
       *  Delay: '<S279>/Delay'
       *  Product: '<S279>/Product1'
       */
      rtb_Gain3_c = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_a;
      rtb_Gain3_c *= rtb_Product_j_idx_1;

      /* Sum: '<S279>/Add1' incorporates:
       *  Product: '<S279>/Product'
       *  Switch: '<S279>/Switch'
       */
      rtb_Add1_e = rtb_Add_k * 0.0046902865258454489 + rtb_Gain3_c;

      /* Delay: '<S303>/Delay' */
      if (PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_a == POS_ZCSIG) {
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj = 0.0;
      }

      PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_a = 0U;

      /* If: '<S308>/If' incorporates:
       *  Constant: '<S310>/Constant'
       *  DataTypeConversion: '<S303>/Data Type Conversion3'
       *  Delay: '<S303>/Delay'
       *  RelationalOperator: '<S310>/Compare'
       */
      if (tmp_4) {
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_e = (int8_T)!((real32_T)
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj < 0.0F);
      }

      if (PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_e == 0) {
        /* Outputs for IfAction SubSystem: '<S308>/If Action Subsystem' incorporates:
         *  ActionPort: '<S311>/Action Port'
         */
        /* DataTypeConversion: '<S311>/Convert_uint16' incorporates:
         *  DataTypeConversion: '<S303>/Data Type Conversion3'
         *  Delay: '<S303>/Delay'
         */
        rtb_Saturation_or = floorf((real32_T)
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj);
        if (rtIsNaNF(rtb_Saturation_or) || rtIsInfF(rtb_Saturation_or)) {
          rtb_Saturation_or = 0.0F;
        } else {
          rtb_Saturation_or = fmodf(rtb_Saturation_or, 65536.0F);
        }

        /* Sum: '<S311>/Sum' incorporates:
         *  DataTypeConversion: '<S303>/Data Type Conversion3'
         *  DataTypeConversion: '<S311>/Convert_back'
         *  DataTypeConversion: '<S311>/Convert_uint16'
         *  Delay: '<S303>/Delay'
         */
        rtb_indexing = (real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj -
          (real32_T)(rtb_Saturation_or < 0.0F ? (int32_T)(int16_T)-(int16_T)
                     (uint16_T)-rtb_Saturation_or : (int32_T)(int16_T)(uint16_T)
                     rtb_Saturation_or);

        /* End of Outputs for SubSystem: '<S308>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S308>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S312>/Action Port'
         */
        /* DataTypeConversion: '<S312>/Convert_uint16' incorporates:
         *  DataTypeConversion: '<S303>/Data Type Conversion3'
         *  Delay: '<S303>/Delay'
         */
        rtb_Saturation_or = truncf((real32_T)
          PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj);
        if (rtIsNaNF(rtb_Saturation_or) || rtIsInfF(rtb_Saturation_or)) {
          rtb_Saturation_or = 0.0F;
        } else {
          rtb_Saturation_or = fmodf(rtb_Saturation_or, 65536.0F);
        }

        /* Sum: '<S312>/Sum' incorporates:
         *  DataTypeConversion: '<S303>/Data Type Conversion3'
         *  DataTypeConversion: '<S312>/Convert_back'
         *  DataTypeConversion: '<S312>/Convert_uint16'
         *  Delay: '<S303>/Delay'
         */
        rtb_indexing = (real32_T)PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj -
          (real32_T)(rtb_Saturation_or < 0.0F ? (int32_T)(int16_T)-(int16_T)
                     (uint16_T)-rtb_Saturation_or : (int32_T)(int16_T)(uint16_T)
                     rtb_Saturation_or);

        /* End of Outputs for SubSystem: '<S308>/If Action Subsystem1' */
      }

      /* Gain: '<S306>/indexing' */
      rtb_indexing *= 800.0F;

      /* DataTypeConversion: '<S306>/Get_Integer' */
      rtb_Saturation_or = truncf(rtb_indexing);
      if (rtIsNaNF(rtb_Saturation_or) || rtIsInfF(rtb_Saturation_or)) {
        rtb_Saturation_or = 0.0F;
      } else {
        rtb_Saturation_or = fmodf(rtb_Saturation_or, 65536.0F);
      }

      rtb_Get_Integer = (uint16_T)(rtb_Saturation_or < 0.0F ? (int32_T)(uint16_T)
        -(int16_T)(uint16_T)-rtb_Saturation_or : (int32_T)(uint16_T)
        rtb_Saturation_or);

      /* End of DataTypeConversion: '<S306>/Get_Integer' */

      /* Sum: '<S306>/Sum2' incorporates:
       *  DataTypeConversion: '<S306>/Data Type Conversion1'
       */
      rtb_Saturation_or = rtb_indexing - (real32_T)rtb_Get_Integer;

      /* Sum: '<S198>/Sum' incorporates:
       *  Constant: '<S306>/offset'
       *  Constant: '<S306>/sine_table_values'
       *  DataTypeConversion: '<S303>/Data Type Conversion'
       *  DataTypeConversion: '<S303>/Data Type Conversion1'
       *  Product: '<S198>/Product'
       *  Product: '<S198>/Product1'
       *  Product: '<S307>/Product'
       *  Product: '<S307>/Product1'
       *  Selector: '<S306>/Lookup'
       *  Sum: '<S306>/Sum'
       *  Sum: '<S307>/Sum3'
       *  Sum: '<S307>/Sum4'
       *  Sum: '<S307>/Sum5'
       *  Sum: '<S307>/Sum6'
       */
      rtb_Gain_e = ((PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[(int32_T)
                     (rtb_Get_Integer + 201U)] -
                     PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[(int32_T)
                     (rtb_Get_Integer + 200U)]) * rtb_Saturation_or +
                    PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[(int32_T)
                    (rtb_Get_Integer + 200U)]) * Merge_i -
        ((PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[(int32_T)
          (rtb_Get_Integer + 1U)] -
          PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[rtb_Get_Integer]) *
         rtb_Saturation_or +
         PMSM_to_BLDC_mod1_ConstP.sine_table_values_Value[rtb_Get_Integer]) *
        rtb_Add1_f;

      /* DiscreteIntegrator: '<S248>/Integrator' */
      if (PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState != 0) {
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE = 0.0;
      }

      /* DiscreteIntegrator: '<S248>/Integrator' incorporates:
       *  Gain: '<S245>/Integral Gain'
       */
      PMSM_to_BLDC_mod1_B.Integrator = 5.0 * rtb_Gain_e +
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE;

      /* Sum: '<S198>/Sum1' incorporates:
       *  Gain: '<S253>/Proportional Gain'
       *  Sum: '<S257>/Sum'
       */
      rtb_Gain_e = (250.0 * rtb_Gain_e + PMSM_to_BLDC_mod1_B.Integrator) +
        rtb_Add1_e;

      /* Gain: '<S331>/Gain3' incorporates:
       *  Gain: '<S303>/Gain'
       *  Product: '<S304>/Product'
       */
      rtb_Gain3_c = 7.9577471545947669E-6 * rtb_Gain_e;

      /* Delay: '<S304>/Delay' incorporates:
       *  Constant: '<S304>/InputGain'
       *  Constant: '<S304>/Offset'
       *  Product: '<S304>/Product1'
       *  Sum: '<S304>/Sum1'
       */
      if (PMSM_to_BLDC_mod1_DW.icLoad_a) {
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_ai = 0.0 - rtb_Gain3_c;
      }

      /* Sum: '<S304>/Sum' incorporates:
       *  Delay: '<S304>/Delay'
       */
      rtb_Switch2 = rtb_Gain3_c + PMSM_to_BLDC_mod1_DW.Delay_DSTATE_ai;

      /* Switch: '<S304>/Switch1' */
      if (!(rtb_Switch2 > 0.0)) {
        /* Sum: '<S304>/Sum' incorporates:
         *  Constant: '<S304>/Bias1'
         *  Sum: '<S304>/Sum2'
         */
        rtb_Switch2++;
      }

      /* End of Switch: '<S304>/Switch1' */

      /* Switch: '<S304>/Switch2' */
      if (rtb_Switch2 >= 1.0) {
        /* Sum: '<S304>/Sum' incorporates:
         *  Sum: '<S304>/Sum3'
         *  Switch: '<S304>/Switch2'
         */
        rtb_Switch2--;
      }

      /* End of Switch: '<S304>/Switch2' */

      /* Product: '<S304>/Product2' incorporates:
       *  Delay: '<S303>/Delay'
       */
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj = rtb_Switch2;

      /* Gain: '<S331>/Gain3' incorporates:
       *  Constant: '<S18>/Constant'
       *  DataTypeConversion: '<S11>/Data Type Conversion'
       *  Delay: '<S303>/Delay'
       *  Gain: '<S198>/PositionGain'
       *  Math: '<S18>/Mod'
       */
      rtb_Gain3_c = (real32_T)(6.2831853071795862 *
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_aj);
      rtb_Gain3_c = rt_modd_snf(rtb_Gain3_c, 6.282);

      /* Gain: '<S169>/convert_pu' */
      rtb_Add_k = 0.15915494309189535 * rtb_Gain3_c;

      /* If: '<S169>/If' incorporates:
       *  Constant: '<S171>/Constant'
       *  RelationalOperator: '<S171>/Compare'
       */
      if (tmp_4) {
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_c = (int8_T)!(rtb_Add_k < 0.0);
      }

      if (PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_c == 0) {
        /* Outputs for IfAction SubSystem: '<S169>/If Action Subsystem' incorporates:
         *  ActionPort: '<S172>/Action Port'
         */
        rtb_Gain4_i = PMSM_to_BLDC__IfActionSubsystem(rtb_Add_k);

        /* End of Outputs for SubSystem: '<S169>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S169>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S173>/Action Port'
         */
        rtb_Gain4_i = PMSM_to_BLDC_IfActionSubsystem1(rtb_Add_k);

        /* End of Outputs for SubSystem: '<S169>/If Action Subsystem1' */
      }

      /* Gain: '<S331>/Gain4' incorporates:
       *  Gain: '<S167>/indexing'
       */
      rtb_Gain4_i *= 800.0;

      /* DataTypeConversion: '<S167>/Get_Integer' */
      Merge_i = trunc(rtb_Gain4_i);
      if (rtIsNaN(Merge_i) || rtIsInf(Merge_i)) {
        Merge_i = 0.0;
      } else {
        Merge_i = fmod(Merge_i, 65536.0);
      }

      rtb_Get_Integer = (uint16_T)(Merge_i < 0.0 ? (int32_T)(uint16_T)-(int16_T)
        (uint16_T)-Merge_i : (int32_T)(uint16_T)Merge_i);

      /* End of DataTypeConversion: '<S167>/Get_Integer' */

      /* Sum: '<S167>/Sum2' incorporates:
       *  DataTypeConversion: '<S167>/Data Type Conversion1'
       */
      rtb_Product1_o = rtb_Gain4_i - (real_T)rtb_Get_Integer;

      /* Sum: '<S168>/Sum4' incorporates:
       *  Constant: '<S167>/offset'
       *  Constant: '<S167>/sine_table_values'
       *  Product: '<S168>/Product'
       *  Selector: '<S167>/Lookup'
       *  Sum: '<S167>/Sum'
       *  Sum: '<S168>/Sum3'
       */
      rtb_Add_k = (PMSM_to_BLDC_mod1_ConstP.pooled13[(int32_T)(rtb_Get_Integer +
        1U)] - PMSM_to_BLDC_mod1_ConstP.pooled13[rtb_Get_Integer]) *
        rtb_Product1_o + PMSM_to_BLDC_mod1_ConstP.pooled13[rtb_Get_Integer];

      /* Gain: '<S331>/Gain4' incorporates:
       *  Constant: '<S167>/offset'
       *  Constant: '<S167>/sine_table_values'
       *  Product: '<S168>/Product1'
       *  Selector: '<S167>/Lookup'
       *  Sum: '<S167>/Sum'
       *  Sum: '<S168>/Sum5'
       */
      rtb_Gain4_i = PMSM_to_BLDC_mod1_ConstP.pooled13[(int32_T)(rtb_Get_Integer
        + 201U)] - PMSM_to_BLDC_mod1_ConstP.pooled13[(int32_T)(rtb_Get_Integer +
        200U)];
      rtb_Gain4_i *= rtb_Product1_o;

      /* Sum: '<S168>/Sum6' incorporates:
       *  Constant: '<S167>/offset'
       *  Constant: '<S167>/sine_table_values'
       *  Selector: '<S167>/Lookup'
       *  Sum: '<S167>/Sum'
       *  Sum: '<S168>/Sum5'
       */
      rtb_Product1_o = PMSM_to_BLDC_mod1_ConstP.pooled13[(int32_T)
        (rtb_Get_Integer + 200U)] + rtb_Gain4_i;

      /* Outputs for Atomic SubSystem: '<S165>/Two inputs CRL' */
      /* Gain: '<S331>/Gain4' incorporates:
       *  Product: '<S175>/acos'
       *  Product: '<S175>/bsin'
       *  Sum: '<S175>/sum_Ds'
       */
      rtb_Gain4_i = rtb_uabc3 * rtb_Product1_o + rtb_one_by_sqrt3_ * rtb_Add_k;

      /* AlgorithmDescriptorDelegate generated from: '<S175>/a16' incorporates:
       *  Switch: '<S176>/Switch'
       */
      rtb_Product_fc = rtb_Gain4_i;

      /* AlgorithmDescriptorDelegate generated from: '<S175>/a16' incorporates:
       *  Product: '<S175>/asin'
       *  Product: '<S175>/bcos'
       *  Sum: '<S175>/sum_Qs'
       */
      PMSM_to_BLDC_mod1_B.algDD_o2 = rtb_one_by_sqrt3_ * rtb_Product1_o -
        rtb_uabc3 * rtb_Add_k;

      /* End of Outputs for SubSystem: '<S165>/Two inputs CRL' */

      /* DiscreteIntegrator: '<S118>/Integrator' */
      PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b =
        PMSM_to_BLDC_mod1_ConstB.Constant3_n;

      /* Sum: '<S127>/Sum' incorporates:
       *  Constant: '<S25>/Constant'
       *  DiscreteIntegrator: '<S118>/Integrator'
       *  Product: '<S123>/PProd Out'
       */
      rtb_Product1_o = rtb_Gain4_i * 22.608 +
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b;

      /* Saturate: '<S125>/Saturation' */
      if (rtb_Product1_o > 1.0) {
        rtb_Product_j_idx_1 = 1.0;
      } else if (rtb_Product1_o < -1.0) {
        rtb_Product_j_idx_1 = -1.0;
      } else {
        rtb_Product_j_idx_1 = rtb_Product1_o;
      }

      /* End of Saturate: '<S125>/Saturation' */

      /* Saturate: '<S8>/Saturation' incorporates:
       *  Delay: '<S2>/Delay1'
       */
      if (PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx > 600.0F) {
        rtb_Saturation_or = 600.0F;
      } else if (PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx < -600.0F) {
        rtb_Saturation_or = -600.0F;
      } else {
        rtb_Saturation_or = PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx;
      }

      /* Sum: '<S8>/Add' incorporates:
       *  Constant: '<S2>/Constant'
       *  Saturate: '<S8>/Saturation'
       */
      rtb_Add_k = 600.0 - rtb_Saturation_or;

      /* Saturate: '<S8>/Saturation' incorporates:
       *  Delay: '<S2>/Delay1'
       */
      if (PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx > 600.0F) {
        rtb_Saturation_or = 600.0F;
      } else if (PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx < -600.0F) {
        rtb_Saturation_or = -600.0F;
      } else {
        rtb_Saturation_or = PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx;
      }

      /* Gain: '<S408>/Proportional Gain' incorporates:
       *  Constant: '<S2>/Constant'
       *  Saturate: '<S8>/Saturation'
       *  Sum: '<S8>/Add'
       */
      PMSM_to_BLDC_mod1_B.ProportionalGain = (600.0 - rtb_Saturation_or) *
        0.31663865546218484;
    }

    /* Sum: '<S24>/Sum' incorporates:
     *  Integrator: '<S403>/Integrator'
     *  Sum: '<S412>/Sum'
     */
    rtb_uabc3 = PMSM_to_BLDC_mod1_B.algDD_o2 -
      (PMSM_to_BLDC_mod1_B.ProportionalGain +
       PMSM_to_BLDC_mod1_X.Integrator_CSTATE);
    if (tmp_5) {
      /* DiscreteIntegrator: '<S63>/Integrator' */
      PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n =
        PMSM_to_BLDC_mod1_ConstB.Constant3;

      /* Sum: '<S72>/Sum' incorporates:
       *  Constant: '<S24>/Constant'
       *  DiscreteIntegrator: '<S63>/Integrator'
       *  Product: '<S68>/PProd Out'
       */
      rtb_DeadZone = rtb_uabc3 * 22.608 +
        PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n;

      /* Saturate: '<S70>/Saturation' */
      if (rtb_DeadZone > 1.0) {
        rtb_Saturation_k = 1.0;
      } else if (rtb_DeadZone < -1.0) {
        rtb_Saturation_k = -1.0;
      } else {
        rtb_Saturation_k = rtb_DeadZone;
      }

      /* End of Saturate: '<S70>/Saturation' */

      /* Gain: '<S143>/convert_pu' */
      rtb_convert_pu_i = 0.15915494309189535 * rtb_Gain3_c;

      /* If: '<S143>/If' incorporates:
       *  Constant: '<S145>/Constant'
       *  RelationalOperator: '<S145>/Compare'
       */
      if (tmp_4) {
        PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_m = (int8_T)!(rtb_convert_pu_i <
          0.0);
      }

      if (PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_m == 0) {
        /* Outputs for IfAction SubSystem: '<S143>/If Action Subsystem' incorporates:
         *  ActionPort: '<S146>/Action Port'
         */
        rtb_Gain3_c = PMSM_to_BLDC__IfActionSubsystem(rtb_convert_pu_i);

        /* End of Outputs for SubSystem: '<S143>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S143>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S147>/Action Port'
         */
        rtb_Gain3_c = PMSM_to_BLDC_IfActionSubsystem1(rtb_convert_pu_i);

        /* End of Outputs for SubSystem: '<S143>/If Action Subsystem1' */
      }

      /* Gain: '<S331>/Gain3' incorporates:
       *  Gain: '<S141>/indexing'
       */
      rtb_Gain3_c *= 800.0;

      /* DataTypeConversion: '<S141>/Get_Integer' */
      Merge_i = trunc(rtb_Gain3_c);
      if (rtIsNaN(Merge_i) || rtIsInf(Merge_i)) {
        Merge_i = 0.0;
      } else {
        Merge_i = fmod(Merge_i, 65536.0);
      }

      rtb_Get_Integer = (uint16_T)(Merge_i < 0.0 ? (int32_T)(uint16_T)-(int16_T)
        (uint16_T)-Merge_i : (int32_T)(uint16_T)Merge_i);

      /* End of DataTypeConversion: '<S141>/Get_Integer' */

      /* Sum: '<S141>/Sum2' incorporates:
       *  DataTypeConversion: '<S141>/Data Type Conversion1'
       */
      rtb_Add1_f = rtb_Gain3_c - (real_T)rtb_Get_Integer;

      /* Sum: '<S142>/Sum4' incorporates:
       *  Constant: '<S141>/offset'
       *  Constant: '<S141>/sine_table_values'
       *  Product: '<S142>/Product'
       *  Selector: '<S141>/Lookup'
       *  Sum: '<S141>/Sum'
       *  Sum: '<S142>/Sum3'
       */
      rtb_convert_pu_i = (PMSM_to_BLDC_mod1_ConstP.pooled13[(int32_T)
                          (rtb_Get_Integer + 1U)] -
                          PMSM_to_BLDC_mod1_ConstP.pooled13[rtb_Get_Integer]) *
        rtb_Add1_f + PMSM_to_BLDC_mod1_ConstP.pooled13[rtb_Get_Integer];

      /* Gain: '<S331>/Gain3' incorporates:
       *  Constant: '<S141>/offset'
       *  Constant: '<S141>/sine_table_values'
       *  Product: '<S142>/Product1'
       *  Selector: '<S141>/Lookup'
       *  Sum: '<S141>/Sum'
       *  Sum: '<S142>/Sum5'
       */
      rtb_Gain3_c = PMSM_to_BLDC_mod1_ConstP.pooled13[(int32_T)(rtb_Get_Integer
        + 201U)] - PMSM_to_BLDC_mod1_ConstP.pooled13[(int32_T)(rtb_Get_Integer +
        200U)];
      rtb_Gain3_c *= rtb_Add1_f;

      /* Sum: '<S142>/Sum6' incorporates:
       *  Constant: '<S141>/offset'
       *  Constant: '<S141>/sine_table_values'
       *  Selector: '<S141>/Lookup'
       *  Sum: '<S141>/Sum'
       *  Sum: '<S142>/Sum5'
       */
      rtb_one_by_sqrt3_ = PMSM_to_BLDC_mod1_ConstP.pooled13[(int32_T)
        (rtb_Get_Integer + 200U)] + rtb_Gain3_c;

      /* Outputs for Atomic SubSystem: '<S140>/Two inputs CRL' */
      /* Gain: '<S331>/Gain3' incorporates:
       *  Product: '<S149>/dsin'
       *  Product: '<S149>/qcos'
       *  Sum: '<S149>/sum_beta'
       */
      rtb_Gain3_c = rtb_Saturation_k * rtb_one_by_sqrt3_ + rtb_Product_j_idx_1 *
        rtb_convert_pu_i;

      /* Switch: '<S150>/Switch' incorporates:
       *  Product: '<S149>/dcos'
       *  Product: '<S149>/qsin'
       *  Sum: '<S149>/sum_alpha'
       */
      rtb_Saturation_k = rtb_Product_j_idx_1 * rtb_one_by_sqrt3_ -
        rtb_Saturation_k * rtb_convert_pu_i;
      rtb_Product_j_idx_1 = rtb_Gain3_c;

      /* SignalConversion generated from: '<S6>/Delay' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S149>/a16'
       *  Switch: '<S150>/Switch'
       */
      rtb_TmpSignalConversionAtDelayI[1] = rtb_Gain3_c;

      /* Gain: '<S331>/Gain3' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S149>/a16'
       *  Gain: '<S160>/one_by_two'
       */
      rtb_Gain3_c = 0.5 * rtb_Saturation_k;

      /* Gain: '<S160>/sqrt3_by_two' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S149>/a16'
       */
      rtb_Add2 = 0.8660254037844386 * rtb_Product_j_idx_1;

      /* End of Outputs for SubSystem: '<S140>/Two inputs CRL' */

      /* Sum: '<S160>/add_b' */
      rtb_Add1_f = rtb_Add2 - rtb_Gain3_c;

      /* Gain: '<S331>/Gain3' incorporates:
       *  Sum: '<S160>/add_c'
       */
      rtb_Gain3_c = (0.0 - rtb_Gain3_c) - rtb_Add2;

      /* Outputs for Atomic SubSystem: '<S140>/Two inputs CRL' */
      /* Gain: '<S154>/one_by_two' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S149>/a16'
       *  MinMax: '<S154>/Max'
       *  MinMax: '<S154>/Min'
       *  Sum: '<S154>/Add'
       */
      rtb_Add2 = (fmax(fmax(rtb_Saturation_k, rtb_Add1_f), rtb_Gain3_c) + fmin
                  (fmin(rtb_Saturation_k, rtb_Add1_f), rtb_Gain3_c)) * -0.5;

      /* Gain: '<S12>/Gain' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S149>/a16'
       *  Constant: '<S12>/Constant'
       *  Gain: '<S153>/Gain'
       *  Sum: '<S12>/Add'
       *  Sum: '<S153>/Add1'
       *  Sum: '<S153>/Add2'
       *  Sum: '<S153>/Add3'
       */
      PMSM_to_BLDC_mod1_B.Gain[0] = ((rtb_Saturation_k + rtb_Add2) *
        1.1547005383792517 + 1.45) * 0.33333333333333331;

      /* End of Outputs for SubSystem: '<S140>/Two inputs CRL' */
      PMSM_to_BLDC_mod1_B.Gain[1] = ((rtb_Add1_f + rtb_Add2) *
        1.1547005383792517 + 1.45) * 0.33333333333333331;
      PMSM_to_BLDC_mod1_B.Gain[2] = ((rtb_Add2 + rtb_Gain3_c) *
        1.1547005383792517 + 1.45) * 0.33333333333333331;

      /* MATLABSystem: '<S5>/PWM Output' incorporates:
       *  Constant: '<Root>/Constant'
       */
      freq = checkFrequencyAndDutyCycleLimits
        (PMSM_to_BLDC_mod1_DW.obj.TimerHandle, 20000U);
      setFrequencyAccToInput(PMSM_to_BLDC_mod1_DW.obj.TimerHandle, freq);
      Merge_i = rt_roundd_snf(PMSM_to_BLDC_mod1_B.Gain[0]);
      if (Merge_i < 4.294967296E+9) {
        if (Merge_i >= 0.0) {
          freq = (uint32_T)Merge_i;
        } else {
          freq = 0U;
        }
      } else {
        freq = MAX_uint32_T;
      }

      freq = checkFrequencyAndDutyCycleLimits
        (PMSM_to_BLDC_mod1_DW.obj.TimerHandle, freq);
      setDutyCycleChannel1(PMSM_to_BLDC_mod1_DW.obj.TimerHandle, freq);
      Merge_i = rt_roundd_snf(PMSM_to_BLDC_mod1_B.Gain[1]);
      if (Merge_i < 4.294967296E+9) {
        if (Merge_i >= 0.0) {
          freq = (uint32_T)Merge_i;
        } else {
          freq = 0U;
        }
      } else {
        freq = MAX_uint32_T;
      }

      freq = checkFrequencyAndDutyCycleLimits
        (PMSM_to_BLDC_mod1_DW.obj.TimerHandle, freq);
      setDutyCycleChannel2(PMSM_to_BLDC_mod1_DW.obj.TimerHandle, freq);
      Merge_i = rt_roundd_snf(PMSM_to_BLDC_mod1_B.Gain[2]);
      if (Merge_i < 4.294967296E+9) {
        if (Merge_i >= 0.0) {
          freq = (uint32_T)Merge_i;
        } else {
          freq = 0U;
        }
      } else {
        freq = MAX_uint32_T;
      }

      freq = checkFrequencyAndDutyCycleLimits
        (PMSM_to_BLDC_mod1_DW.obj.TimerHandle, freq);
      setDutyCycleChannel3(PMSM_to_BLDC_mod1_DW.obj.TimerHandle, freq);

      /* End of MATLABSystem: '<S5>/PWM Output' */

      /* DeadZone: '<S55>/DeadZone' */
      if (rtb_DeadZone > 1.0) {
        rtb_DeadZone--;
      } else if (rtb_DeadZone >= -1.0) {
        rtb_DeadZone = 0.0;
      } else {
        rtb_DeadZone++;
      }

      /* End of DeadZone: '<S55>/DeadZone' */

      /* Gain: '<S331>/Gain3' incorporates:
       *  Constant: '<S24>/Constant1'
       *  Product: '<S60>/IProd Out'
       */
      rtb_Gain3_c = rtb_uabc3 * 0.23235999999999998;

      /* Switch: '<S53>/Switch1' incorporates:
       *  Constant: '<S53>/Clamping_zero'
       *  Constant: '<S53>/Constant'
       *  Constant: '<S53>/Constant2'
       *  RelationalOperator: '<S53>/fix for DT propagation issue'
       */
      if (rtb_DeadZone > 0.0) {
        rtPrevAction = 1;
      } else {
        rtPrevAction = -1;
      }

      /* Switch: '<S53>/Switch2' incorporates:
       *  Constant: '<S53>/Clamping_zero'
       *  Constant: '<S53>/Constant3'
       *  Constant: '<S53>/Constant4'
       *  RelationalOperator: '<S53>/fix for DT propagation issue1'
       */
      if (rtb_Gain3_c > 0.0) {
        rtAction = 1;
      } else {
        rtAction = -1;
      }

      /* Switch: '<S53>/Switch' incorporates:
       *  Constant: '<S53>/Clamping_zero'
       *  Logic: '<S53>/AND3'
       *  RelationalOperator: '<S53>/Equal1'
       *  RelationalOperator: '<S53>/Relational Operator'
       *  Switch: '<S53>/Switch1'
       *  Switch: '<S53>/Switch2'
       */
      if ((rtb_DeadZone != 0.0) && (rtPrevAction == rtAction)) {
        /* Switch: '<S53>/Switch' incorporates:
         *  Constant: '<S53>/Constant1'
         */
        rtb_Switch = 0.0;
      } else {
        /* Switch: '<S53>/Switch' */
        rtb_Switch = rtb_Gain3_c;
      }

      /* End of Switch: '<S53>/Switch' */

      /* DeadZone: '<S110>/DeadZone' */
      if (rtb_Product1_o > 1.0) {
        rtb_Product1_o--;
      } else if (rtb_Product1_o >= -1.0) {
        rtb_Product1_o = 0.0;
      } else {
        rtb_Product1_o++;
      }

      /* End of DeadZone: '<S110>/DeadZone' */

      /* Gain: '<S331>/Gain4' incorporates:
       *  Constant: '<S25>/Constant1'
       *  Product: '<S115>/IProd Out'
       */
      rtb_Gain4_i *= 0.23235999999999998;

      /* Switch: '<S108>/Switch1' incorporates:
       *  Constant: '<S108>/Clamping_zero'
       *  Constant: '<S108>/Constant'
       *  Constant: '<S108>/Constant2'
       *  RelationalOperator: '<S108>/fix for DT propagation issue'
       */
      if (rtb_Product1_o > 0.0) {
        rtPrevAction = 1;
      } else {
        rtPrevAction = -1;
      }

      /* Switch: '<S108>/Switch2' incorporates:
       *  Constant: '<S108>/Clamping_zero'
       *  Constant: '<S108>/Constant3'
       *  Constant: '<S108>/Constant4'
       *  RelationalOperator: '<S108>/fix for DT propagation issue1'
       */
      if (rtb_Gain4_i > 0.0) {
        rtAction = 1;
      } else {
        rtAction = -1;
      }

      /* Switch: '<S108>/Switch' incorporates:
       *  Constant: '<S108>/Clamping_zero'
       *  Logic: '<S108>/AND3'
       *  RelationalOperator: '<S108>/Equal1'
       *  RelationalOperator: '<S108>/Relational Operator'
       *  Switch: '<S108>/Switch1'
       *  Switch: '<S108>/Switch2'
       */
      if ((rtb_Product1_o != 0.0) && (rtPrevAction == rtAction)) {
        /* Switch: '<S108>/Switch' incorporates:
         *  Constant: '<S108>/Constant1'
         */
        rtb_Switch_e = 0.0;
      } else {
        /* Switch: '<S108>/Switch' */
        rtb_Switch_e = rtb_Gain4_i;
      }

      /* End of Switch: '<S108>/Switch' */

      /* Gain: '<S331>/Gain3' incorporates:
       *  Constant: '<S19>/Constant1'
       *  Math: '<S19>/Mod1'
       */
      rtb_Gain3_c = rt_modd_snf(rtb_Product_fc, 6.282);

      /* Gain: '<S331>/Gain4' incorporates:
       *  Constant: '<S19>/Constant1'
       *  Math: '<S19>/Mod2'
       */
      rtb_Gain4_i = rt_modd_snf(PMSM_to_BLDC_mod1_B.algDD_o2, 6.282);

      /* Product: '<S210>/Product' */
      rtb_Gain_e *= 0.0046902865258454489;

      /* Delay: '<S210>/Delay' incorporates:
       *  Constant: '<S202>/IC'
       */
      if (PMSM_to_BLDC_mod1_DW.icLoad_b) {
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_g = 0.0;
      }

      /* Sum: '<S210>/Add1' incorporates:
       *  Delay: '<S210>/Delay'
       *  Product: '<S210>/Product1'
       */
      rtb_Add1_d = 0.99530971347415453 * PMSM_to_BLDC_mod1_DW.Delay_DSTATE_g +
        rtb_Gain_e;

      /* Gain: '<S198>/FreqGain' incorporates:
       *  Delay: '<S179>/Delay1'
       */
      PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f = (real32_T)rtb_Add1_d;

      /* Gain: '<S179>/SpeedGain' incorporates:
       *  Delay: '<S179>/Delay1'
       *  Delay: '<S2>/Delay1'
       */
      PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_fx = 0.142857149F *
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_f;

      /* Outputs for Atomic SubSystem: '<S140>/Two inputs CRL' */
      /* SignalConversion generated from: '<S6>/Delay' incorporates:
       *  AlgorithmDescriptorDelegate generated from: '<S149>/a16'
       */
      rtb_TmpSignalConversionAtDelayI[0] = rtb_Saturation_k;

      /* End of Outputs for SubSystem: '<S140>/Two inputs CRL' */
      rtb_TmpSignalConversionAtDelayI[2] = rtb_Gain3_c;
      rtb_TmpSignalConversionAtDelayI[3] = rtb_Gain4_i;

      /* Saturate: '<S318>/Saturation2' */
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

      /* End of Saturate: '<S318>/Saturation2' */

      /* Gain: '<S318>/Gain' incorporates:
       *  Sum: '<S318>/Sum'
       */
      rtb_Gain_e = ((rtb_Saturation_k + rtb_convert_pu_i) + rtb_DeadZone) *
        0.33333333333333331;

      /* Gain: '<S331>/Gain3' incorporates:
       *  Sum: '<S318>/Sum1'
       */
      rtb_Gain3_c = rtb_DeadZone - rtb_Gain_e;

      /* Gain: '<S331>/Gain4' incorporates:
       *  Sum: '<S318>/Sum2'
       */
      rtb_Gain4_i = rtb_Saturation_k - rtb_Gain_e;

      /* Product: '<S318>/Product' incorporates:
       *  Sum: '<S318>/Sum3'
       */
      rtb_DeadZone = rtb_Gain3_c * PMSM_to_BLDC_mod1_ConstB.Switch;
      rtb_Saturation_k = rtb_Gain4_i * PMSM_to_BLDC_mod1_ConstB.Switch;
      rtb_convert_pu_i = (rtb_convert_pu_i - rtb_Gain_e) *
        PMSM_to_BLDC_mod1_ConstB.Switch;
    }

    /* Integrator: '<S338>/Integrator' */
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

    /* Gain: '<S323>/Gain4' incorporates:
     *  Integrator: '<S323>/Int1'
     */
    rtb_Product1_o = 7.0 * PMSM_to_BLDC_mod1_X.Int1_CSTATE;

    /* Trigonometry: '<S325>/sine_cosine' */
    rtb_Product_fc = sin(rtb_Product1_o);
    rtb_Product1_o = cos(rtb_Product1_o);

    /* Integrator: '<S339>/Integrator' */
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

    /* Sum: '<S333>/Add1' incorporates:
     *  Integrator: '<S338>/Integrator'
     *  Integrator: '<S339>/Integrator'
     *  Product: '<S333>/Product2'
     *  Product: '<S333>/Product3'
     */
    rtb_uabc3 = PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d * rtb_Product1_o -
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l * rtb_Product_fc;

    /* SignalConversion generated from: '<S322>/Vector Concatenate' incorporates:
     *  Concatenate: '<S322>/Vector Concatenate'
     */
    PMSM_to_BLDC_mod1_B.VectorConcatenate[0] = rtb_uabc3;
    if (tmp_5) {
      /* Gain: '<S331>/Gain3' incorporates:
       *  Gain: '<S331>/Gain1'
       */
      rtb_Gain3_c = -0.33333333333333331 * rtb_Saturation_k;

      /* Gain: '<S331>/Gain4' */
      rtb_Gain4_i = -0.33333333333333331 * rtb_convert_pu_i;

      /* Sum: '<S331>/Add' incorporates:
       *  Gain: '<S331>/Gain'
       */
      PMSM_to_BLDC_mod1_B.Add = (0.66666666666666663 * rtb_DeadZone +
        rtb_Gain3_c) + rtb_Gain4_i;

      /* Gain: '<S331>/Gain3' */
      rtb_Gain3_c = -0.57735026918962573 * rtb_convert_pu_i;

      /* Sum: '<S331>/Add1' incorporates:
       *  Gain: '<S331>/Gain2'
       */
      PMSM_to_BLDC_mod1_B.Add1 = 0.57735026918962573 * rtb_Saturation_k +
        rtb_Gain3_c;
    }

    /* Gain: '<S332>/Gain1' */
    rtb_DeadZone = -0.5 * rtb_uabc3;

    /* Sum: '<S333>/Add' incorporates:
     *  Integrator: '<S338>/Integrator'
     *  Integrator: '<S339>/Integrator'
     *  Product: '<S333>/Product'
     *  Product: '<S333>/Product1'
     */
    rtb_uabc3 = PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d * rtb_Product_fc +
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l * rtb_Product1_o;

    /* Sum: '<S332>/Subtract1' incorporates:
     *  Concatenate: '<S322>/Vector Concatenate'
     *  Gain: '<S332>/Gain2'
     *  Gain: '<S332>/Gain3'
     */
    PMSM_to_BLDC_mod1_B.VectorConcatenate[1] = 0.8660254037844386 * rtb_uabc3 +
      rtb_DeadZone;

    /* Sum: '<S332>/Subtract2' incorporates:
     *  Concatenate: '<S322>/Vector Concatenate'
     *  Gain: '<S332>/Gain4'
     */
    PMSM_to_BLDC_mod1_B.VectorConcatenate[2] = -0.8660254037844386 * rtb_uabc3 +
      rtb_DeadZone;

    /* Sum: '<S338>/Add' incorporates:
     *  Constant: '<S342>/Constant'
     *  Integrator: '<S338>/Integrator'
     *  Integrator: '<S339>/Integrator'
     *  Product: '<S336>/Product2'
     *  Product: '<S336>/Product3'
     *  Product: '<S338>/Product'
     *  Product: '<S340>/Product'
     *  Product: '<S341>/Product'
     *  Product: '<S342>/Product'
     *  Sum: '<S336>/Add1'
     */
    PMSM_to_BLDC_mod1_B.Add_h = ((PMSM_to_BLDC_mod1_B.Add * rtb_Product1_o +
      PMSM_to_BLDC_mod1_B.Add1 * rtb_Product_fc) /
      PMSM_to_BLDC_mod1_ConstB.IndexVector_b + PMSM_to_BLDC_mod1_ConstB.Gain *
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l *
      PMSM_to_BLDC_mod1_ConstB.IndexVector_a /
      PMSM_to_BLDC_mod1_ConstB.IndexVector1) -
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d * 0.037 /
      PMSM_to_BLDC_mod1_ConstB.IndexVector_j;

    /* Sum: '<S339>/Add' incorporates:
     *  Constant: '<S346>/Constant'
     *  Integrator: '<S338>/Integrator'
     *  Integrator: '<S339>/Integrator'
     *  Product: '<S336>/Product'
     *  Product: '<S336>/Product1'
     *  Product: '<S339>/Product'
     *  Product: '<S343>/Product'
     *  Product: '<S344>/Product'
     *  Product: '<S346>/Product'
     *  Sum: '<S336>/Add'
     */
    PMSM_to_BLDC_mod1_B.Add_d = (((PMSM_to_BLDC_mod1_B.Add1 * rtb_Product1_o -
      PMSM_to_BLDC_mod1_B.Add * rtb_Product_fc) /
      PMSM_to_BLDC_mod1_ConstB.IndexVector_k -
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d * PMSM_to_BLDC_mod1_ConstB.Gain *
      PMSM_to_BLDC_mod1_ConstB.IndexVector_m /
      PMSM_to_BLDC_mod1_ConstB.IndexVector1_g) -
      PMSM_to_BLDC_mod1_ConstB.Product) -
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l * 0.037 /
      PMSM_to_BLDC_mod1_ConstB.IndexVector_d3;
    if (tmp_5) {
      /* SimscapeRtp: '<S355>/RTP_1' incorporates:
       *  Constant: '<S317>/Subsystem_around_RTP_57D1A14D_v'
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
          PMSM_to_BLDC_mod1_DW.RTP_1_RtpManager, PMSM_to_BLDC_mod1_M->Timing.t[0],
          PMSM_to_BLDC_mod1_B.expl_temp, diag);
        if (!ok) {
          ok = error_buffer_is_empty(rtmGetErrorStatus(PMSM_to_BLDC_mod1_M));
          if (ok) {
            msg = rtw_diagnostics_msg(diagTree);
            rtmSetErrorStatus(PMSM_to_BLDC_mod1_M, msg);
          }
        }
      }

      PMSM_to_BLDC_mod1_DW.RTP_1_SetParametersNeeded = false;

      /* End of SimscapeRtp: '<S355>/RTP_1' */
    }

    /* SimscapeInputBlock: '<S364>/INPUT_1_1_1' incorporates:
     *  SimscapeExecutionBlock: '<S364>/OUTPUT_1_0'
     *  SimscapeExecutionBlock: '<S364>/STATE_1'
     *  SimscapeInputBlock: '<S364>/INPUT_2_1_1'
     *  SimscapeInputBlock: '<S364>/INPUT_3_1_1'
     *  SimscapeInputBlock: '<S364>/INPUT_4_1_1'
     *  SimscapeInputBlock: '<S364>/INPUT_5_1_1'
     *  SimscapeInputBlock: '<S364>/INPUT_6_1_1'
     *  SimscapeInputBlock: '<S364>/INPUT_7_1_1'
     */
    PMSM_to_BLDC_mod1_B.INPUT_1_1_1[0] = PMSM_to_BLDC_mod1_B.Gain[0];
    PMSM_to_BLDC_mod1_B.INPUT_1_1_1[1] = 0.0;
    PMSM_to_BLDC_mod1_B.INPUT_1_1_1[2] = 0.0;
    ok = rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M);
    if (ok) {
      PMSM_to_BLDC_mod1_DW.INPUT_1_1_1_Discrete_1975384460[0] =
        !(PMSM_to_BLDC_mod1_B.INPUT_1_1_1[0] ==
          PMSM_to_BLDC_mod1_DW.INPUT_1_1_1_Discrete_1975384460[1]);
      PMSM_to_BLDC_mod1_DW.INPUT_1_1_1_Discrete_1975384460[1] =
        PMSM_to_BLDC_mod1_B.INPUT_1_1_1[0];
    }

    PMSM_to_BLDC_mod1_B.INPUT_1_1_1[0] =
      PMSM_to_BLDC_mod1_DW.INPUT_1_1_1_Discrete_1975384460[1];
    PMSM_to_BLDC_mod1_B.INPUT_1_1_1[3] =
      PMSM_to_BLDC_mod1_DW.INPUT_1_1_1_Discrete_1975384460[0];

    /* End of SimscapeInputBlock: '<S364>/INPUT_1_1_1' */
    if (tmp_5) {
      /* Sum: '<S366>/Add' incorporates:
       *  Constant: '<S366>/Constant1'
       *  Gain: '<S365>/Gain1'
       */
      PMSM_to_BLDC_mod1_B.Add_p[0] = -PMSM_to_BLDC_mod1_B.Gain[0] + 1.0;
      PMSM_to_BLDC_mod1_B.Add_p[1] = -PMSM_to_BLDC_mod1_B.Gain[1] + 1.0;
      PMSM_to_BLDC_mod1_B.Add_p[2] = -PMSM_to_BLDC_mod1_B.Gain[2] + 1.0;
    }

    /* SimscapeInputBlock: '<S364>/INPUT_2_1_1' */
    PMSM_to_BLDC_mod1_B.INPUT_2_1_1[0] = PMSM_to_BLDC_mod1_B.Add_p[0];
    PMSM_to_BLDC_mod1_B.INPUT_2_1_1[1] = 0.0;
    PMSM_to_BLDC_mod1_B.INPUT_2_1_1[2] = 0.0;
    if (ok) {
      PMSM_to_BLDC_mod1_DW.INPUT_2_1_1_Discrete_840794972[0] =
        !(PMSM_to_BLDC_mod1_B.INPUT_2_1_1[0] ==
          PMSM_to_BLDC_mod1_DW.INPUT_2_1_1_Discrete_840794972[1]);
      PMSM_to_BLDC_mod1_DW.INPUT_2_1_1_Discrete_840794972[1] =
        PMSM_to_BLDC_mod1_B.INPUT_2_1_1[0];
    }

    PMSM_to_BLDC_mod1_B.INPUT_2_1_1[0] =
      PMSM_to_BLDC_mod1_DW.INPUT_2_1_1_Discrete_840794972[1];
    PMSM_to_BLDC_mod1_B.INPUT_2_1_1[3] =
      PMSM_to_BLDC_mod1_DW.INPUT_2_1_1_Discrete_840794972[0];

    /* SimscapeInputBlock: '<S364>/INPUT_3_1_1' incorporates:
     *  Constant: '<S317>/Trq'
     */
    PMSM_to_BLDC_mod1_B.INPUT_3_1_1[0] = 10.0;
    PMSM_to_BLDC_mod1_B.INPUT_3_1_1[1] = 0.0;
    PMSM_to_BLDC_mod1_B.INPUT_3_1_1[2] = 0.0;
    if (ok) {
      PMSM_to_BLDC_mod1_DW.INPUT_3_1_1_Discrete_259893996[0] =
        !(PMSM_to_BLDC_mod1_B.INPUT_3_1_1[0] ==
          PMSM_to_BLDC_mod1_DW.INPUT_3_1_1_Discrete_259893996[1]);
      PMSM_to_BLDC_mod1_DW.INPUT_3_1_1_Discrete_259893996[1] =
        PMSM_to_BLDC_mod1_B.INPUT_3_1_1[0];
    }

    PMSM_to_BLDC_mod1_B.INPUT_3_1_1[0] =
      PMSM_to_BLDC_mod1_DW.INPUT_3_1_1_Discrete_259893996[1];
    PMSM_to_BLDC_mod1_B.INPUT_3_1_1[3] =
      PMSM_to_BLDC_mod1_DW.INPUT_3_1_1_Discrete_259893996[0];

    /* SimscapeInputBlock: '<S364>/INPUT_4_1_1' */
    PMSM_to_BLDC_mod1_B.INPUT_4_1_1[0] = PMSM_to_BLDC_mod1_B.Gain[1];
    PMSM_to_BLDC_mod1_B.INPUT_4_1_1[1] = 0.0;
    PMSM_to_BLDC_mod1_B.INPUT_4_1_1[2] = 0.0;
    if (ok) {
      PMSM_to_BLDC_mod1_DW.INPUT_4_1_1_Discrete_3177019132[0] =
        !(PMSM_to_BLDC_mod1_B.INPUT_4_1_1[0] ==
          PMSM_to_BLDC_mod1_DW.INPUT_4_1_1_Discrete_3177019132[1]);
      PMSM_to_BLDC_mod1_DW.INPUT_4_1_1_Discrete_3177019132[1] =
        PMSM_to_BLDC_mod1_B.INPUT_4_1_1[0];
    }

    PMSM_to_BLDC_mod1_B.INPUT_4_1_1[0] =
      PMSM_to_BLDC_mod1_DW.INPUT_4_1_1_Discrete_3177019132[1];
    PMSM_to_BLDC_mod1_B.INPUT_4_1_1[3] =
      PMSM_to_BLDC_mod1_DW.INPUT_4_1_1_Discrete_3177019132[0];

    /* SimscapeInputBlock: '<S364>/INPUT_5_1_1' */
    PMSM_to_BLDC_mod1_B.INPUT_5_1_1[0] = PMSM_to_BLDC_mod1_B.Add_p[1];
    PMSM_to_BLDC_mod1_B.INPUT_5_1_1[1] = 0.0;
    PMSM_to_BLDC_mod1_B.INPUT_5_1_1[2] = 0.0;
    if (ok) {
      PMSM_to_BLDC_mod1_DW.INPUT_5_1_1_Discrete_2151505740[0] =
        !(PMSM_to_BLDC_mod1_B.INPUT_5_1_1[0] ==
          PMSM_to_BLDC_mod1_DW.INPUT_5_1_1_Discrete_2151505740[1]);
      PMSM_to_BLDC_mod1_DW.INPUT_5_1_1_Discrete_2151505740[1] =
        PMSM_to_BLDC_mod1_B.INPUT_5_1_1[0];
    }

    PMSM_to_BLDC_mod1_B.INPUT_5_1_1[0] =
      PMSM_to_BLDC_mod1_DW.INPUT_5_1_1_Discrete_2151505740[1];
    PMSM_to_BLDC_mod1_B.INPUT_5_1_1[3] =
      PMSM_to_BLDC_mod1_DW.INPUT_5_1_1_Discrete_2151505740[0];

    /* SimscapeInputBlock: '<S364>/INPUT_6_1_1' */
    PMSM_to_BLDC_mod1_B.INPUT_6_1_1[0] = PMSM_to_BLDC_mod1_B.Gain[2];
    PMSM_to_BLDC_mod1_B.INPUT_6_1_1[1] = 0.0;
    PMSM_to_BLDC_mod1_B.INPUT_6_1_1[2] = 0.0;
    if (ok) {
      PMSM_to_BLDC_mod1_DW.INPUT_6_1_1_Discrete_3348964764[0] =
        !(PMSM_to_BLDC_mod1_B.INPUT_6_1_1[0] ==
          PMSM_to_BLDC_mod1_DW.INPUT_6_1_1_Discrete_3348964764[1]);
      PMSM_to_BLDC_mod1_DW.INPUT_6_1_1_Discrete_3348964764[1] =
        PMSM_to_BLDC_mod1_B.INPUT_6_1_1[0];
    }

    PMSM_to_BLDC_mod1_B.INPUT_6_1_1[0] =
      PMSM_to_BLDC_mod1_DW.INPUT_6_1_1_Discrete_3348964764[1];
    PMSM_to_BLDC_mod1_B.INPUT_6_1_1[3] =
      PMSM_to_BLDC_mod1_DW.INPUT_6_1_1_Discrete_3348964764[0];

    /* SimscapeInputBlock: '<S364>/INPUT_7_1_1' */
    PMSM_to_BLDC_mod1_B.INPUT_7_1_1[0] = PMSM_to_BLDC_mod1_B.Add_p[2];
    PMSM_to_BLDC_mod1_B.INPUT_7_1_1[1] = 0.0;
    PMSM_to_BLDC_mod1_B.INPUT_7_1_1[2] = 0.0;
    if (ok) {
      PMSM_to_BLDC_mod1_DW.INPUT_7_1_1_Discrete_4210887724[0] =
        !(PMSM_to_BLDC_mod1_B.INPUT_7_1_1[0] ==
          PMSM_to_BLDC_mod1_DW.INPUT_7_1_1_Discrete_4210887724[1]);
      PMSM_to_BLDC_mod1_DW.INPUT_7_1_1_Discrete_4210887724[1] =
        PMSM_to_BLDC_mod1_B.INPUT_7_1_1[0];
    }

    PMSM_to_BLDC_mod1_B.INPUT_7_1_1[0] =
      PMSM_to_BLDC_mod1_DW.INPUT_7_1_1_Discrete_4210887724[1];
    PMSM_to_BLDC_mod1_B.INPUT_7_1_1[3] =
      PMSM_to_BLDC_mod1_DW.INPUT_7_1_1_Discrete_4210887724[0];

    /* SimscapeExecutionBlock: '<S364>/STATE_1' incorporates:
     *  SimscapeExecutionBlock: '<S364>/OUTPUT_1_0'
     */
    simulationData = (NeslSimulationData *)PMSM_to_BLDC_mod1_DW.STATE_1_SimData;
    rtb_DeadZone = PMSM_to_BLDC_mod1_M->Timing.t[0];
    time = rtb_DeadZone;
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 17;
    simulationData->mData->mContStates.mX =
      &PMSM_to_BLDC_mod1_X.PMSM_to_BLDC_mod1SubsystemInver[0];
    simulationData->mData->mDiscStates.mN = 0;
    simulationData->mData->mDiscStates.mX =
      &PMSM_to_BLDC_mod1_DW.STATE_1_Discrete;
    simulationData->mData->mModeVector.mN = 11;
    simulationData->mData->mModeVector.mX = &PMSM_to_BLDC_mod1_DW.STATE_1_Modes
      [0];
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
    simulationData->mData->mIsModeUpdateTimeStep = tmp_4;
    tmp_1[0] = 0;
    PMSM_to_BLDC_mod1_B.dv1[0] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[0];
    PMSM_to_BLDC_mod1_B.dv1[1] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[1];
    PMSM_to_BLDC_mod1_B.dv1[2] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[2];
    PMSM_to_BLDC_mod1_B.dv1[3] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[3];
    tmp_1[1] = 4;
    PMSM_to_BLDC_mod1_B.dv1[4] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[0];
    PMSM_to_BLDC_mod1_B.dv1[5] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[1];
    PMSM_to_BLDC_mod1_B.dv1[6] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[2];
    PMSM_to_BLDC_mod1_B.dv1[7] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[3];
    tmp_1[2] = 8;
    PMSM_to_BLDC_mod1_B.dv1[8] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[0];
    PMSM_to_BLDC_mod1_B.dv1[9] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[1];
    PMSM_to_BLDC_mod1_B.dv1[10] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[2];
    PMSM_to_BLDC_mod1_B.dv1[11] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[3];
    tmp_1[3] = 12;
    PMSM_to_BLDC_mod1_B.dv1[12] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[0];
    PMSM_to_BLDC_mod1_B.dv1[13] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[1];
    PMSM_to_BLDC_mod1_B.dv1[14] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[2];
    PMSM_to_BLDC_mod1_B.dv1[15] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[3];
    tmp_1[4] = 16;
    PMSM_to_BLDC_mod1_B.dv1[16] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[0];
    PMSM_to_BLDC_mod1_B.dv1[17] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[1];
    PMSM_to_BLDC_mod1_B.dv1[18] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[2];
    PMSM_to_BLDC_mod1_B.dv1[19] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[3];
    tmp_1[5] = 20;
    PMSM_to_BLDC_mod1_B.dv1[20] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[0];
    PMSM_to_BLDC_mod1_B.dv1[21] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[1];
    PMSM_to_BLDC_mod1_B.dv1[22] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[2];
    PMSM_to_BLDC_mod1_B.dv1[23] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[3];
    tmp_1[6] = 24;
    PMSM_to_BLDC_mod1_B.dv1[24] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[0];
    PMSM_to_BLDC_mod1_B.dv1[25] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[1];
    PMSM_to_BLDC_mod1_B.dv1[26] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[2];
    PMSM_to_BLDC_mod1_B.dv1[27] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[3];
    tmp_1[7] = 28;
    simulationData->mData->mInputValues.mN = 28;
    simulationData->mData->mInputValues.mX = &PMSM_to_BLDC_mod1_B.dv1[0];
    simulationData->mData->mInputOffsets.mN = 8;
    simulationData->mData->mInputOffsets.mX = &tmp_1[0];
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
    tmp_2 = ne_simulator_method((NeslSimulator *)
      PMSM_to_BLDC_mod1_DW.STATE_1_Simulator, NESL_SIM_OUTPUTS, simulationData,
      diag);
    if (tmp_2 != 0) {
      tmp_0 = error_buffer_is_empty(rtmGetErrorStatus(PMSM_to_BLDC_mod1_M));
      if (tmp_0) {
        msg_0 = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(PMSM_to_BLDC_mod1_M, msg_0);
      }
    }

    /* SimscapeExecutionBlock: '<S364>/OUTPUT_1_0' */
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
    simulationData->mData->mIsModeUpdateTimeStep = tmp_4;
    tmp_3[0] = 0;
    PMSM_to_BLDC_mod1_B.dv[0] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[0];
    PMSM_to_BLDC_mod1_B.dv[1] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[1];
    PMSM_to_BLDC_mod1_B.dv[2] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[2];
    PMSM_to_BLDC_mod1_B.dv[3] = PMSM_to_BLDC_mod1_B.INPUT_1_1_1[3];
    tmp_3[1] = 4;
    PMSM_to_BLDC_mod1_B.dv[4] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[0];
    PMSM_to_BLDC_mod1_B.dv[5] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[1];
    PMSM_to_BLDC_mod1_B.dv[6] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[2];
    PMSM_to_BLDC_mod1_B.dv[7] = PMSM_to_BLDC_mod1_B.INPUT_2_1_1[3];
    tmp_3[2] = 8;
    PMSM_to_BLDC_mod1_B.dv[8] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[0];
    PMSM_to_BLDC_mod1_B.dv[9] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[1];
    PMSM_to_BLDC_mod1_B.dv[10] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[2];
    PMSM_to_BLDC_mod1_B.dv[11] = PMSM_to_BLDC_mod1_B.INPUT_3_1_1[3];
    tmp_3[3] = 12;
    PMSM_to_BLDC_mod1_B.dv[12] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[0];
    PMSM_to_BLDC_mod1_B.dv[13] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[1];
    PMSM_to_BLDC_mod1_B.dv[14] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[2];
    PMSM_to_BLDC_mod1_B.dv[15] = PMSM_to_BLDC_mod1_B.INPUT_4_1_1[3];
    tmp_3[4] = 16;
    PMSM_to_BLDC_mod1_B.dv[16] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[0];
    PMSM_to_BLDC_mod1_B.dv[17] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[1];
    PMSM_to_BLDC_mod1_B.dv[18] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[2];
    PMSM_to_BLDC_mod1_B.dv[19] = PMSM_to_BLDC_mod1_B.INPUT_5_1_1[3];
    tmp_3[5] = 20;
    PMSM_to_BLDC_mod1_B.dv[20] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[0];
    PMSM_to_BLDC_mod1_B.dv[21] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[1];
    PMSM_to_BLDC_mod1_B.dv[22] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[2];
    PMSM_to_BLDC_mod1_B.dv[23] = PMSM_to_BLDC_mod1_B.INPUT_6_1_1[3];
    tmp_3[6] = 24;
    PMSM_to_BLDC_mod1_B.dv[24] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[0];
    PMSM_to_BLDC_mod1_B.dv[25] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[1];
    PMSM_to_BLDC_mod1_B.dv[26] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[2];
    PMSM_to_BLDC_mod1_B.dv[27] = PMSM_to_BLDC_mod1_B.INPUT_7_1_1[3];
    tmp_3[7] = 28;
    memcpy(&PMSM_to_BLDC_mod1_B.dv[28], &PMSM_to_BLDC_mod1_B.STATE_1[0], 28U *
           sizeof(real_T));
    tmp_3[8] = 56;
    simulationData->mData->mInputValues.mN = 56;
    simulationData->mData->mInputValues.mX = &PMSM_to_BLDC_mod1_B.dv[0];
    simulationData->mData->mInputOffsets.mN = 9;
    simulationData->mData->mInputOffsets.mX = &tmp_3[0];
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
    tmp_2 = ne_simulator_method((NeslSimulator *)
      PMSM_to_BLDC_mod1_DW.OUTPUT_1_0_Simulator, NESL_SIM_OUTPUTS,
      simulationData, diag);
    if (tmp_2 != 0) {
      tmp_4 = error_buffer_is_empty(rtmGetErrorStatus(PMSM_to_BLDC_mod1_M));
      if (tmp_4) {
        msg_1 = rtw_diagnostics_msg(diagnosticTree_0);
        rtmSetErrorStatus(PMSM_to_BLDC_mod1_M, msg_1);
      }
    }

    if (tmp_5) {
      /* Gain: '<S400>/Integral Gain' */
      PMSM_to_BLDC_mod1_B.IntegralGain = 11.047170868347338 * rtb_Add_k;
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
    if (rtmIsMajorTimeStep(PMSM_to_BLDC_mod1_M)) {
      /* Update for Delay: '<S2>/Delay' */
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE[0] =
        PMSM_to_BLDC_mod1_B.VectorConcatenate[0];
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE[1] =
        PMSM_to_BLDC_mod1_B.VectorConcatenate[1];
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE[2] =
        PMSM_to_BLDC_mod1_B.VectorConcatenate[2];

      /* Update for Delay: '<S6>/Delay' */
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

      /* Update for Delay: '<S196>/Delay' */
      PMSM_to_BLDC_mod1_DW.icLoad = false;
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[0] = rtb_Add1[0];
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_k[1] = rtb_Add1[1];

      /* Update for Delay: '<S279>/Delay' */
      PMSM_to_BLDC_mod1_DW.icLoad_f = false;
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_a = rtb_Add1_e;

      /* Update for DiscreteIntegrator: '<S248>/Integrator' */
      PMSM_to_BLDC_mod1_DW.Integrator_DSTATE = PMSM_to_BLDC_mod1_B.Integrator;
      PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState = 0;

      /* Update for Delay: '<S304>/Delay' */
      PMSM_to_BLDC_mod1_DW.icLoad_a = false;
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_ai = rtb_Switch2;

      /* Update for DiscreteIntegrator: '<S118>/Integrator' */
      PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b += rtb_Switch_e;
      PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState_n = 1;

      /* Update for DiscreteIntegrator: '<S63>/Integrator' */
      PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n += rtb_Switch;
      PMSM_to_BLDC_mod1_DW.Integrator_PrevResetState_nt = 1;

      /* Update for Delay: '<S210>/Delay' */
      PMSM_to_BLDC_mod1_DW.icLoad_b = false;
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_g = rtb_Add1_d;
    }

    /* Update for Integrator: '<S338>/Integrator' */
    PMSM_to_BLDC_mod1_DW.Integrator_DWORK1 = false;

    /* Update for Integrator: '<S339>/Integrator' */
    PMSM_to_BLDC_mod1_DW.Integrator_DWORK1_g = false;

    /* Update for SimscapeExecutionBlock: '<S364>/STATE_1' */
    simulationData = (NeslSimulationData *)PMSM_to_BLDC_mod1_DW.STATE_1_SimData;
    time = PMSM_to_BLDC_mod1_M->Timing.t[0];
    simulationData->mData->mTime.mN = 1;
    simulationData->mData->mTime.mX = &time;
    simulationData->mData->mContStates.mN = 17;
    simulationData->mData->mContStates.mX =
      &PMSM_to_BLDC_mod1_X.PMSM_to_BLDC_mod1SubsystemInver[0];
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
      PMSM_to_BLDC_mod1_DW.STATE_1_Simulator, NESL_SIM_UPDATE, simulationData,
      diagnosticManager);
    if (tmp_2 != 0) {
      tmp = error_buffer_is_empty(rtmGetErrorStatus(PMSM_to_BLDC_mod1_M));
      if (tmp) {
        msg = rtw_diagnostics_msg(diagnosticTree);
        rtmSetErrorStatus(PMSM_to_BLDC_mod1_M, msg);
      }
    }

    /* End of Update for SimscapeExecutionBlock: '<S364>/STATE_1' */
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
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      PMSM_to_BLDC_mod1_M->Timing.clockTick1++;
    }
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

  /* Derivatives for Integrator: '<S403>/Integrator' */
  _rtXdot->Integrator_CSTATE = PMSM_to_BLDC_mod1_B.IntegralGain;

  /* Derivatives for Integrator: '<S338>/Integrator' */
  lsat = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d <= -1.0E+7);
  usat = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d >= 1.0E+7);
  if (((!lsat) && (!usat)) || (lsat && (PMSM_to_BLDC_mod1_B.Add_h > 0.0)) ||
      (usat && (PMSM_to_BLDC_mod1_B.Add_h < 0.0))) {
    _rtXdot->Integrator_CSTATE_d = PMSM_to_BLDC_mod1_B.Add_h;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE_d = 0.0;
  }

  /* End of Derivatives for Integrator: '<S338>/Integrator' */

  /* Derivatives for Integrator: '<S323>/Int1' incorporates:
   *  Constant: '<S319>/Speed_Angular_Vel'
   */
  _rtXdot->Int1_CSTATE = 600.0;

  /* Derivatives for Integrator: '<S339>/Integrator' */
  lsat = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l <= -1.0E+7);
  usat = (PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l >= 1.0E+7);
  if (((!lsat) && (!usat)) || (lsat && (PMSM_to_BLDC_mod1_B.Add_d > 0.0)) ||
      (usat && (PMSM_to_BLDC_mod1_B.Add_d < 0.0))) {
    _rtXdot->Integrator_CSTATE_l = PMSM_to_BLDC_mod1_B.Add_d;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE_l = 0.0;
  }

  /* End of Derivatives for Integrator: '<S339>/Integrator' */

  /* Derivatives for SimscapeExecutionBlock: '<S364>/STATE_1' */
  simulationData = (NeslSimulationData *)PMSM_to_BLDC_mod1_DW.STATE_1_SimData;
  time = PMSM_to_BLDC_mod1_M->Timing.t[0];
  simulationData->mData->mTime.mN = 1;
  simulationData->mData->mTime.mX = &time;
  simulationData->mData->mContStates.mN = 17;
  simulationData->mData->mContStates.mX =
    &PMSM_to_BLDC_mod1_X.PMSM_to_BLDC_mod1SubsystemInver[0];
  simulationData->mData->mDiscStates.mN = 0;
  simulationData->mData->mDiscStates.mX = &PMSM_to_BLDC_mod1_DW.STATE_1_Discrete;
  simulationData->mData->mModeVector.mN = 11;
  simulationData->mData->mModeVector.mX = &PMSM_to_BLDC_mod1_DW.STATE_1_Modes[0];
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
  simulationData->mData->mDx.mX = &_rtXdot->PMSM_to_BLDC_mod1SubsystemInver[0];
  diagnosticManager = (NeuDiagnosticManager *)
    PMSM_to_BLDC_mod1_DW.STATE_1_DiagMgr;
  diagnosticTree = neu_diagnostic_manager_get_initial_tree(diagnosticManager);
  tmp_1 = ne_simulator_method((NeslSimulator *)
    PMSM_to_BLDC_mod1_DW.STATE_1_Simulator, NESL_SIM_DERIVATIVES, simulationData,
    diagnosticManager);
  if (tmp_1 != 0) {
    lsat = error_buffer_is_empty(rtmGetErrorStatus(PMSM_to_BLDC_mod1_M));
    if (lsat) {
      msg = rtw_diagnostics_msg(diagnosticTree);
      rtmSetErrorStatus(PMSM_to_BLDC_mod1_M, msg);
    }
  }

  /* End of Derivatives for SimscapeExecutionBlock: '<S364>/STATE_1' */
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
    rtsiSetSolverMassMatrixIr(&PMSM_to_BLDC_mod1_M->solverInfo,
      PMSM_to_BLDC_mod1_MassMatrix.ir);
    rtsiSetSolverMassMatrixJc(&PMSM_to_BLDC_mod1_M->solverInfo,
      PMSM_to_BLDC_mod1_MassMatrix.jc);
    rtsiSetSolverMassMatrixPr(&PMSM_to_BLDC_mod1_M->solverInfo,
      PMSM_to_BLDC_mod1_MassMatrix.pr);
    rtsiSetRTModelPtr(&PMSM_to_BLDC_mod1_M->solverInfo, PMSM_to_BLDC_mod1_M);
  }

  rtsiSetSimTimeStep(&PMSM_to_BLDC_mod1_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&PMSM_to_BLDC_mod1_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&PMSM_to_BLDC_mod1_M->solverInfo, false);
  PMSM_to_BLDC_mod1_M->intgData.x0 = PMSM_to_BLDC_mod1_M->odeX0;
  PMSM_to_BLDC_mod1_M->intgData.f0 = PMSM_to_BLDC_mod1_M->odeF0;
  PMSM_to_BLDC_mod1_M->intgData.x1start = PMSM_to_BLDC_mod1_M->odeX1START;
  PMSM_to_BLDC_mod1_M->intgData.f1 = PMSM_to_BLDC_mod1_M->odeF1;
  PMSM_to_BLDC_mod1_M->intgData.Delta = PMSM_to_BLDC_mod1_M->odeDELTA;
  PMSM_to_BLDC_mod1_M->intgData.E = PMSM_to_BLDC_mod1_M->odeE;
  PMSM_to_BLDC_mod1_M->intgData.fac = PMSM_to_BLDC_mod1_M->odeFAC;

  /* initialize */
  {
    int_T i;
    real_T *f = PMSM_to_BLDC_mod1_M->intgData.fac;
    for (i = 0; i < (int_T)(sizeof(PMSM_to_BLDC_mod1_M->odeFAC)/sizeof(real_T));
         i++) {
      f[i] = 1.5e-8;
    }
  }

  PMSM_to_BLDC_mod1_M->intgData.DFDX = PMSM_to_BLDC_mod1_M->odeDFDX;
  PMSM_to_BLDC_mod1_M->intgData.W = PMSM_to_BLDC_mod1_M->odeW;
  PMSM_to_BLDC_mod1_M->intgData.pivots = PMSM_to_BLDC_mod1_M->odePIVOTS;
  PMSM_to_BLDC_mod1_M->intgData.xtmp = PMSM_to_BLDC_mod1_M->odeXTMP;
  PMSM_to_BLDC_mod1_M->intgData.ztmp = PMSM_to_BLDC_mod1_M->odeZTMP;
  PMSM_to_BLDC_mod1_M->intgData.M = PMSM_to_BLDC_mod1_M->odeMASSMATRIX_M;
  PMSM_to_BLDC_mod1_M->intgData.isFirstStep = true;
  rtsiSetSolverExtrapolationOrder(&PMSM_to_BLDC_mod1_M->solverInfo, 4);
  rtsiSetSolverNumberNewtonIterations(&PMSM_to_BLDC_mod1_M->solverInfo, 1);
  PMSM_to_BLDC_mod1_M->contStates = ((X_PMSM_to_BLDC_mod1_T *)
    &PMSM_to_BLDC_mod1_X);
  PMSM_to_BLDC_mod1_M->contStateDisabled = ((XDis_PMSM_to_BLDC_mod1_T *)
    &PMSM_to_BLDC_mod1_XDis);
  PMSM_to_BLDC_mod1_M->Timing.tStart = (0.0);
  PMSM_to_BLDC_mod1_M->periodicContStateIndices = ((int_T*)
    PMSM_to_BLDC_mod1_PeriodicIndX);
  PMSM_to_BLDC_mod1_M->periodicContStateRanges = ((real_T*)
    PMSM_to_BLDC_mod1_PeriodicRngX);
  PMSM_to_BLDC_mod1_M->massMatrixType = ((ssMatrixType)1);
  PMSM_to_BLDC_mod1_M->massMatrixNzMax = (9);
  PMSM_to_BLDC_mod1_M->massMatrixIr = (PMSM_to_BLDC_mod1_MassMatrix.ir);
  PMSM_to_BLDC_mod1_M->massMatrixJc = (PMSM_to_BLDC_mod1_MassMatrix.jc);
  PMSM_to_BLDC_mod1_M->massMatrixPr = (PMSM_to_BLDC_mod1_MassMatrix.pr);
  rtsiSetSolverMassMatrixType(&PMSM_to_BLDC_mod1_M->solverInfo, (ssMatrixType)1);
  rtsiSetSolverMassMatrixNzMax(&PMSM_to_BLDC_mod1_M->solverInfo, 9);
  rtsiSetSolverData(&PMSM_to_BLDC_mod1_M->solverInfo, (void *)
                    &PMSM_to_BLDC_mod1_M->intgData);
  rtsiSetSolverName(&PMSM_to_BLDC_mod1_M->solverInfo,"ode14x");
  rtmSetTPtr(PMSM_to_BLDC_mod1_M, &PMSM_to_BLDC_mod1_M->Timing.tArray[0]);
  PMSM_to_BLDC_mod1_M->Timing.stepSize0 = 0.001;
  rtmSetFirstInitCond(PMSM_to_BLDC_mod1_M, 1);

  /* Root-level init GlobalMassMatrixPr offset */
  {
    PMSM_to_BLDC_mod1_DW.STATE_1_MASS_MATRIX_PR = 4;/* '<S364>/STATE_1' */
  }

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
    int_T tmp_5;
    int_T tmp_6;
    int_T tmp_7;
    int_T tmp_8;
    int_T tmp_9;
    boolean_T tmp;
    boolean_T tmp_4;

    /* Start for If: '<S197>/If' */
    PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem = -1;

    /* Start for SwitchCase: '<S206>/Switch Case' */
    PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem = -1;

    /* Start for If: '<S203>/If' */
    PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_g = -1;

    /* Start for SwitchCase: '<S205>/Switch Case' */
    PMSM_to_BLDC_mod1_DW.SwitchCase_ActiveSubsystem_n = -1;

    /* Start for If: '<S308>/If' */
    PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_e = -1;

    /* Start for If: '<S169>/If' */
    PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_c = -1;

    /* Start for If: '<S143>/If' */
    PMSM_to_BLDC_mod1_DW.If_ActiveSubsystem_m = -1;

    /* Start for SimscapeRtp: '<S355>/RTP_1' */
    manager_0 = nesl_lease_rtp_manager(
      "PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration_1",
      0);
    manager = manager_0;
    tmp = pointer_is_null(manager_0);
    if (tmp) {
      PMSM_to_BLDC_mod1_5da39267_1_gateway();
      manager = nesl_lease_rtp_manager(
        "PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration_1",
        0);
    }

    PMSM_to_BLDC_mod1_DW.RTP_1_RtpManager = (void *)manager;
    PMSM_to_BLDC_mod1_DW.RTP_1_SetParametersNeeded = true;

    /* End of Start for SimscapeRtp: '<S355>/RTP_1' */

    /* Start for SimscapeExecutionBlock: '<S364>/STATE_1' */
    tmp_0 = nesl_lease_simulator(
      "PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration_1",
      0, 0);
    PMSM_to_BLDC_mod1_DW.STATE_1_Simulator = (void *)tmp_0;
    tmp = pointer_is_null(PMSM_to_BLDC_mod1_DW.STATE_1_Simulator);
    if (tmp) {
      PMSM_to_BLDC_mod1_5da39267_1_gateway();
      tmp_0 = nesl_lease_simulator(
        "PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration_1",
        0, 0);
      PMSM_to_BLDC_mod1_DW.STATE_1_Simulator = (void *)tmp_0;
    }

    tmp_1 = nesl_create_simulation_data();
    PMSM_to_BLDC_mod1_DW.STATE_1_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    PMSM_to_BLDC_mod1_DW.STATE_1_DiagMgr = (void *)diagnosticManager;
    modelParameters.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters.mSolverTolerance = 0.001;
    modelParameters.mSolverAbsTol = 0.001;
    modelParameters.mSolverRelTol = 0.001;
    modelParameters.mVariableStepSolver = false;
    modelParameters.mIsUsingODEN = false;
    modelParameters.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters.mFixedStepSize = 0.001;
    modelParameters.mStartTime = 0.0;
    modelParameters.mLoadInitialState = false;
    modelParameters.mUseSimState = false;
    modelParameters.mLinTrimCompile = false;
    modelParameters.mLoggingMode = SSC_LOGGING_OFF;
    modelParameters.mRTWModifiedTimeStamp = 6.99604815E+8;
    modelParameters.mZcDisabled = true;
    modelParameters.mUseModelRefSolver = false;
    modelParameters.mTargetFPGAHIL = false;
    tmp_2 = 0.001;
    modelParameters.mSolverTolerance = tmp_2;
    tmp_2 = 0.001;
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

    /* End of Start for SimscapeExecutionBlock: '<S364>/STATE_1' */

    /* Start for SimscapeExecutionBlock: '<S364>/OUTPUT_1_0' */
    tmp_0 = nesl_lease_simulator(
      "PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration_1",
      1, 0);
    PMSM_to_BLDC_mod1_DW.OUTPUT_1_0_Simulator = (void *)tmp_0;
    tmp = pointer_is_null(PMSM_to_BLDC_mod1_DW.OUTPUT_1_0_Simulator);
    if (tmp) {
      PMSM_to_BLDC_mod1_5da39267_1_gateway();
      tmp_0 = nesl_lease_simulator(
        "PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration_1",
        1, 0);
      PMSM_to_BLDC_mod1_DW.OUTPUT_1_0_Simulator = (void *)tmp_0;
    }

    tmp_1 = nesl_create_simulation_data();
    PMSM_to_BLDC_mod1_DW.OUTPUT_1_0_SimData = (void *)tmp_1;
    diagnosticManager = rtw_create_diagnostics();
    PMSM_to_BLDC_mod1_DW.OUTPUT_1_0_DiagMgr = (void *)diagnosticManager;
    modelParameters_0.mSolverType = NE_SOLVER_TYPE_DAE;
    modelParameters_0.mSolverTolerance = 0.001;
    modelParameters_0.mSolverAbsTol = 0.001;
    modelParameters_0.mSolverRelTol = 0.001;
    modelParameters_0.mVariableStepSolver = false;
    modelParameters_0.mIsUsingODEN = false;
    modelParameters_0.mSolverModifyAbsTol = NE_MODIFY_ABS_TOL_NO;
    modelParameters_0.mFixedStepSize = 0.001;
    modelParameters_0.mStartTime = 0.0;
    modelParameters_0.mLoadInitialState = false;
    modelParameters_0.mUseSimState = false;
    modelParameters_0.mLinTrimCompile = false;
    modelParameters_0.mLoggingMode = SSC_LOGGING_OFF;
    modelParameters_0.mRTWModifiedTimeStamp = 6.99604815E+8;
    modelParameters_0.mZcDisabled = true;
    modelParameters_0.mUseModelRefSolver = false;
    modelParameters_0.mTargetFPGAHIL = false;
    tmp_2 = 0.001;
    modelParameters_0.mSolverTolerance = tmp_2;
    tmp_2 = 0.001;
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

    /* End of Start for SimscapeExecutionBlock: '<S364>/OUTPUT_1_0' */
    PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE = UNINITIALIZED_ZCSIG;
    PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE = UNINITIALIZED_ZCSIG;
    PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_a = UNINITIALIZED_ZCSIG;
    PMSM_to_BLDC_mod1_PrevZCX.Dir_Sense_Trig_ZCE = POS_ZCSIG;
    PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_p = UNINITIALIZED_ZCSIG;
    PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_h = UNINITIALIZED_ZCSIG;
    PMSM_to_BLDC_mod1_PrevZCX.Delay1_Reset_ZCE_i = UNINITIALIZED_ZCSIG;
    PMSM_to_BLDC_mod1_PrevZCX.Delay_Reset_ZCE_k = UNINITIALIZED_ZCSIG;
    PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE = UNINITIALIZED_ZCSIG;
    PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE = UNINITIALIZED_ZCSIG;
    PMSM_to_BLDC_mod1_PrevZCX.Delay2_Reset_ZCE_p = UNINITIALIZED_ZCSIG;
    PMSM_to_BLDC_mod1_PrevZCX.Delay3_Reset_ZCE_k = UNINITIALIZED_ZCSIG;

    /* InitializeConditions for Delay: '<S196>/Delay' */
    PMSM_to_BLDC_mod1_DW.icLoad = true;

    /* InitializeConditions for Delay: '<S279>/Delay' */
    PMSM_to_BLDC_mod1_DW.icLoad_f = true;

    /* InitializeConditions for Delay: '<S304>/Delay' */
    PMSM_to_BLDC_mod1_DW.icLoad_a = true;

    /* InitializeConditions for DiscreteIntegrator: '<S118>/Integrator' */
    PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_b =
      PMSM_to_BLDC_mod1_ConstB.Constant3_n;

    /* InitializeConditions for Integrator: '<S403>/Integrator' */
    PMSM_to_BLDC_mod1_X.Integrator_CSTATE = 0.0;

    /* InitializeConditions for DiscreteIntegrator: '<S63>/Integrator' */
    PMSM_to_BLDC_mod1_DW.Integrator_DSTATE_n =
      PMSM_to_BLDC_mod1_ConstB.Constant3;

    /* InitializeConditions for Delay: '<S210>/Delay' */
    PMSM_to_BLDC_mod1_DW.icLoad_b = true;

    /* InitializeConditions for Integrator: '<S338>/Integrator' incorporates:
     *  Integrator: '<S339>/Integrator'
     */
    if (rtmIsFirstInitCond(PMSM_to_BLDC_mod1_M)) {
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_d = 0.0;
      PMSM_to_BLDC_mod1_X.Integrator_CSTATE_l = 0.0;
    }

    PMSM_to_BLDC_mod1_DW.Integrator_DWORK1 = true;

    /* End of InitializeConditions for Integrator: '<S338>/Integrator' */

    /* InitializeConditions for Integrator: '<S323>/Int1' */
    PMSM_to_BLDC_mod1_X.Int1_CSTATE = 0.0;

    /* InitializeConditions for Integrator: '<S339>/Integrator' */
    PMSM_to_BLDC_mod1_DW.Integrator_DWORK1_g = true;

    /* InitializeConditions for SimscapeExecutionBlock: '<S364>/STATE_1' */
    tmp = false;
    tmp_4 = false;
    if (tmp_4 || tmp) {
      tmp_3 = strcmp(rtsiGetSolverName(&PMSM_to_BLDC_mod1_M->solverInfo),
                     "daessc");
      tmp_5 = strcmp(rtsiGetSolverName(&PMSM_to_BLDC_mod1_M->solverInfo),
                     "ode14x");
      tmp_6 = strcmp(rtsiGetSolverName(&PMSM_to_BLDC_mod1_M->solverInfo),
                     "ode15s");
      tmp_7 = strcmp(rtsiGetSolverName(&PMSM_to_BLDC_mod1_M->solverInfo),
                     "ode1be");
      tmp_8 = strcmp(rtsiGetSolverName(&PMSM_to_BLDC_mod1_M->solverInfo),
                     "ode23t");
      tmp_9 = strcmp(rtsiGetSolverName(&PMSM_to_BLDC_mod1_M->solverInfo), "odeN");
      if ((boolean_T)((tmp_3 != 0) & (tmp_5 != 0) & (tmp_6 != 0) & (tmp_7 != 0)
                      & (tmp_8 != 0) & (tmp_9 != 0))) {
        rtmSetErrorStatus(PMSM_to_BLDC_mod1_M,
                          "Detected inconsistent solvers in the model reference hierarchy. Model built with ode14x requires one of {daessc, ode14x, ode15s, ode1be, ode23t, odeN} solvers to run. Use one of the required solvers in the top model.");
      }
    }

    /* End of InitializeConditions for SimscapeExecutionBlock: '<S364>/STATE_1' */

    /* SystemInitialize for IfAction SubSystem: '<S205>/IntegralMethod' */
    /* InitializeConditions for Delay: '<S286>/Delay' */
    PMSM_to_BLDC_mod1_DW.icLoad_bd = true;

    /* InitializeConditions for Delay: '<S289>/Delay' */
    PMSM_to_BLDC_mod1_DW.icLoad_k = true;

    /* End of SystemInitialize for SubSystem: '<S205>/IntegralMethod' */

    /* SystemInitialize for IfAction SubSystem: '<S205>/OptimizedDifferentiationMethod' */
    /* InitializeConditions for Delay: '<S296>/Delay' */
    PMSM_to_BLDC_mod1_DW.icLoad_b1 = true;

    /* InitializeConditions for Delay: '<S299>/Delay' */
    PMSM_to_BLDC_mod1_DW.icLoad_c = true;

    /* End of SystemInitialize for SubSystem: '<S205>/OptimizedDifferentiationMethod' */

    /* Start for MATLABSystem: '<S5>/PWM Output' */
    PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = false;
    PMSM_to_BLDC_mod1_DW.obj.isSetupComplete = false;
    PMSM_to_BLDC_mod1_DW.obj.isInitialized = 1;
    PMSM_to_BLD_PWMOutput_setupImpl(&PMSM_to_BLDC_mod1_DW.obj);
    PMSM_to_BLDC_mod1_DW.obj.isSetupComplete = true;

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

    /* Root-level InitSystemMatrices */
    {
      static int_T modelMassMatrixIr[9] = { 0, 1, 2, 3, 4, 14, 5, 6, 14 };

      static int_T modelMassMatrixJc[22] = { 0, 1, 2, 3, 4, 6, 7, 9, 9, 9, 9, 9,
        9, 9, 9, 9, 9, 9, 9, 9, 9, 9 };

      static real_T modelMassMatrixPr[9] = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0,
        1.0, 1.0 };

      (void) memcpy(PMSM_to_BLDC_mod1_MassMatrix.ir, modelMassMatrixIr,
                    9*sizeof(int_T));
      (void) memcpy(PMSM_to_BLDC_mod1_MassMatrix.jc, modelMassMatrixJc,
                    22*sizeof(int_T));
      (void) memcpy(PMSM_to_BLDC_mod1_MassMatrix.pr, modelMassMatrixPr,
                    9*sizeof(real_T));
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
  /* Terminate for MATLABSystem: '<S5>/PWM Output' */
  if (!PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj.isSetupComplete) {
      disableCounter(PMSM_to_BLDC_mod1_DW.obj.TimerHandle);
      disableTimerInterrupts(PMSM_to_BLDC_mod1_DW.obj.TimerHandle, 0);
      disableTimerChannel1(PMSM_to_BLDC_mod1_DW.obj.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel2(PMSM_to_BLDC_mod1_DW.obj.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel3(PMSM_to_BLDC_mod1_DW.obj.TimerHandle, ENABLE_CH_CHN);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/PWM Output' */

  /* Terminate for SimscapeExecutionBlock: '<S364>/STATE_1' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    PMSM_to_BLDC_mod1_DW.STATE_1_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    PMSM_to_BLDC_mod1_DW.STATE_1_SimData);
  nesl_erase_simulator("PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration_1");

  /* Terminate for SimscapeExecutionBlock: '<S364>/OUTPUT_1_0' */
  neu_destroy_diagnostic_manager((NeuDiagnosticManager *)
    PMSM_to_BLDC_mod1_DW.OUTPUT_1_0_DiagMgr);
  nesl_destroy_simulation_data((NeslSimulationData *)
    PMSM_to_BLDC_mod1_DW.OUTPUT_1_0_SimData);
  nesl_erase_simulator("PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration_1");
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
