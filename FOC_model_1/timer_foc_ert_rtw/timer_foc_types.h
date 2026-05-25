/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: timer_foc_types.h
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

#ifndef timer_foc_types_h_
#define timer_foc_types_h_
#include "rtwtypes.h"
#include "stm_timer_ll.h"
#ifndef struct_tag_92DzsjXuaF7c99tFkgTmuB
#define struct_tag_92DzsjXuaF7c99tFkgTmuB

struct tag_92DzsjXuaF7c99tFkgTmuB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 /* struct_tag_92DzsjXuaF7c99tFkgTmuB */

#ifndef typedef_stm32cube_blocks_DigitalPortW_T
#define typedef_stm32cube_blocks_DigitalPortW_T

typedef struct tag_92DzsjXuaF7c99tFkgTmuB stm32cube_blocks_DigitalPortW_T;

#endif                             /* typedef_stm32cube_blocks_DigitalPortW_T */

#ifndef struct_tag_0RzKA0TA5eXyA1b3sjyvMG
#define struct_tag_0RzKA0TA5eXyA1b3sjyvMG

struct tag_0RzKA0TA5eXyA1b3sjyvMG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  TIM_Type_T* TimerHandle;
};

#endif                                 /* struct_tag_0RzKA0TA5eXyA1b3sjyvMG */

#ifndef typedef_stm32cube_blocks_PWMOutput_ti_T
#define typedef_stm32cube_blocks_PWMOutput_ti_T

typedef struct tag_0RzKA0TA5eXyA1b3sjyvMG stm32cube_blocks_PWMOutput_ti_T;

#endif                             /* typedef_stm32cube_blocks_PWMOutput_ti_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_timer_foc_T RT_MODEL_timer_foc_T;

#endif                                 /* timer_foc_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
