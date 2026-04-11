/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Vsense_model_types.h
 *
 * Code generated for Simulink model 'Vsense_model'.
 *
 * Model version                  : 4.0
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Sat Apr 11 11:59:07 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Vsense_model_types_h_
#define Vsense_model_types_h_
#include "rtwtypes.h"
#include "stm_adc_ll.h"
#ifndef struct_tag_V8NuBFyzhXWrH9W8r74ibE
#define struct_tag_V8NuBFyzhXWrH9W8r74ibE

struct tag_V8NuBFyzhXWrH9W8r74ibE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  ADC_Type_T* ADCHandle;
};

#endif                                 /* struct_tag_V8NuBFyzhXWrH9W8r74ibE */

#ifndef typedef_stm32cube_blocks_AnalogInput__T
#define typedef_stm32cube_blocks_AnalogInput__T

typedef struct tag_V8NuBFyzhXWrH9W8r74ibE stm32cube_blocks_AnalogInput__T;

#endif                             /* typedef_stm32cube_blocks_AnalogInput__T */

/* Parameters (default storage) */
typedef struct P_Vsense_model_T_ P_Vsense_model_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Vsense_model_T RT_MODEL_Vsense_model_T;

#endif                                 /* Vsense_model_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
