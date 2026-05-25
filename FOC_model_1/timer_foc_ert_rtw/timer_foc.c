/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: timer_foc.c
 *
 * Code generated for Simulink model 'timer_foc'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Wed May 20 13:24:45 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "timer_foc.h"
#include "timer_foc_types.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "stm_timer_ll.h"

/* Block states (default storage) */
DW_timer_foc_T timer_foc_DW;

/* Real-time model */
static RT_MODEL_timer_foc_T timer_foc_M_;
RT_MODEL_timer_foc_T *const timer_foc_M = &timer_foc_M_;

/* Forward declaration for local functions */
static void timer_foc_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_ti_T *obj);
static void timer_foc_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_ti_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S7>/PWM Output' */
  b.PeripheralPtr = TIM8;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S7>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S7>/PWM Output' */
    enableCounter(obj->TimerHandle, false);
  }
}

/* Model step function */
void timer_foc_step(void)
{
  GPIO_TypeDef * portNameLoc;
  uint32_T shiftVal;
  real_T temp;
  int32_T rtb_SquareWaveGenerator;
  uint32_T pinMask;
  uint32_T pinWriteLoc;

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S1>/Constant'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  timer_foc_DW.UnitDelay_DSTATE = 1.0 - timer_foc_DW.UnitDelay_DSTATE;

  /* MATLABSystem: '<S5>/Digital Port Write' */
  portNameLoc = GPIOB;
  shiftVal = MW_GPIO_BIT_SHIFT;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  temp = floor(timer_foc_DW.UnitDelay_DSTATE);
  if (rtIsNaN(temp) || rtIsInf(temp)) {
    temp = 0.0;
  } else {
    temp = fmod(temp, 256.0);
  }

  /* MATLABSystem: '<S5>/Digital Port Write' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  if ((temp < 0.0 ? (int32_T)(uint8_T)-(int8_T)(uint8_T)-temp : (int32_T)
       (uint8_T)temp) != 0) {
    pinWriteLoc = 4096U;
  } else {
    pinWriteLoc = 0U;
  }

  pinWriteLoc = mw_shift(pinWriteLoc, shiftVal);
  pinMask = mw_shift(4096U, shiftVal);
  LL_GPIO_SetOutputPin(portNameLoc, pinWriteLoc);
  LL_GPIO_ResetOutputPin(portNameLoc, ~pinWriteLoc & pinMask);

  /* SignalGenerator: '<Root>/Square Wave Generator' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  temp = 1000.0 * timer_foc_DW.UnitDelay_DSTATE;
  if (temp - floor(temp) >= 0.5) {
    rtb_SquareWaveGenerator = 1;
  } else {
    rtb_SquareWaveGenerator = -1;
  }

  /* End of SignalGenerator: '<Root>/Square Wave Generator' */

  /* MATLABSystem: '<S7>/PWM Output' */
  setDutyCycleInPercentageChannel1(timer_foc_DW.obj_e.TimerHandle, (real_T)
    rtb_SquareWaveGenerator);
  setDutyCycleInPercentageChannel2(timer_foc_DW.obj_e.TimerHandle, (real_T)
    rtb_SquareWaveGenerator);
  setDutyCycleInPercentageChannel3(timer_foc_DW.obj_e.TimerHandle, (real_T)
    rtb_SquareWaveGenerator);
}

/* Model initialize function */
void timer_foc_initialize(void)
{
  /* Start for MATLABSystem: '<S5>/Digital Port Write' */
  timer_foc_DW.obj.matlabCodegenIsDeleted = false;
  timer_foc_DW.obj.isInitialized = 1;
  timer_foc_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S7>/PWM Output' */
  timer_foc_DW.obj_e.matlabCodegenIsDeleted = false;
  timer_foc_DW.obj_e.isSetupComplete = false;
  timer_foc_DW.obj_e.isInitialized = 1;
  timer_foc_PWMOutput_setupImpl(&timer_foc_DW.obj_e);
  timer_foc_DW.obj_e.isSetupComplete = true;
}

/* Model terminate function */
void timer_foc_terminate(void)
{
  /* Terminate for MATLABSystem: '<S5>/Digital Port Write' */
  if (!timer_foc_DW.obj.matlabCodegenIsDeleted) {
    timer_foc_DW.obj.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S5>/Digital Port Write' */

  /* Terminate for MATLABSystem: '<S7>/PWM Output' */
  if (!timer_foc_DW.obj_e.matlabCodegenIsDeleted) {
    timer_foc_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((timer_foc_DW.obj_e.isInitialized == 1) &&
        timer_foc_DW.obj_e.isSetupComplete) {
      disableCounter(timer_foc_DW.obj_e.TimerHandle);
      disableTimerInterrupts(timer_foc_DW.obj_e.TimerHandle, 0);
      disableTimerChannel1(timer_foc_DW.obj_e.TimerHandle, ENABLE_CH);
      disableTimerChannel2(timer_foc_DW.obj_e.TimerHandle, ENABLE_CH);
      disableTimerChannel3(timer_foc_DW.obj_e.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/PWM Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
