/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: timer_foc.h
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

#ifndef timer_foc_h_
#define timer_foc_h_
#ifndef timer_foc_COMMON_INCLUDES_
#define timer_foc_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "main.h"
#include "mw_stm32_utils.h"
#endif                                 /* timer_foc_COMMON_INCLUDES_ */

#include "timer_foc_types.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_DigitalPortW_T obj; /* '<S5>/Digital Port Write' */
  stm32cube_blocks_PWMOutput_ti_T obj_e;/* '<S7>/PWM Output' */
  real_T UnitDelay_DSTATE;             /* '<S1>/Unit Delay' */
} DW_timer_foc_T;

/* Real-time Model Data Structure */
struct tag_RTM_timer_foc_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_timer_foc_T timer_foc_DW;

/* Model entry point functions */
extern void timer_foc_initialize(void);
extern void timer_foc_step(void);
extern void timer_foc_terminate(void);

/* Real-time Model object */
extern RT_MODEL_timer_foc_T *const timer_foc_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'timer_foc'
 * '<S1>'   : 'timer_foc/Clock'
 * '<S2>'   : 'timer_foc/Digital Port Write'
 * '<S3>'   : 'timer_foc/PWM Output'
 * '<S4>'   : 'timer_foc/Digital Port Write/ECSoC'
 * '<S5>'   : 'timer_foc/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S6>'   : 'timer_foc/PWM Output/ECSoC'
 * '<S7>'   : 'timer_foc/PWM Output/ECSoC/ECSimCodegen'
 */
#endif                                 /* timer_foc_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
