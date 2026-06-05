/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1_types.h
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

#ifndef PMSM_to_BLDC_mod1_types_h_
#define PMSM_to_BLDC_mod1_types_h_
#include "rtwtypes.h"
#include "mw_stm32_spi_ll.h"
#include "stm_timer_ll.h"
#include "stm_adc_ll.h"
#ifndef struct_tag_mOVAabJjflwVpJ1RH3zpfC
#define struct_tag_mOVAabJjflwVpJ1RH3zpfC

struct tag_mOVAabJjflwVpJ1RH3zpfC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  STM32_SPI_Struct_T * MW_SPI_HANDLE;
  STM32_SPI_Struct_T MW_SPI_BlockStruct;
};

#endif                                 /* struct_tag_mOVAabJjflwVpJ1RH3zpfC */

#ifndef typedef_stm32cube_blocks_SPIControlle_T
#define typedef_stm32cube_blocks_SPIControlle_T

typedef struct tag_mOVAabJjflwVpJ1RH3zpfC stm32cube_blocks_SPIControlle_T;

#endif                             /* typedef_stm32cube_blocks_SPIControlle_T */

#ifndef struct_tag_AkYSLo56SBzQIYxVc5esmB
#define struct_tag_AkYSLo56SBzQIYxVc5esmB

struct tag_AkYSLo56SBzQIYxVc5esmB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  STM32_SPI_Struct_T * MW_SPI_HANDLE;
  STM32_SPI_Struct_T MW_SPI_BlockStruct;
};

#endif                                 /* struct_tag_AkYSLo56SBzQIYxVc5esmB */

#ifndef typedef_stm32cube_blocks_SPIControl_d_T
#define typedef_stm32cube_blocks_SPIControl_d_T

typedef struct tag_AkYSLo56SBzQIYxVc5esmB stm32cube_blocks_SPIControl_d_T;

#endif                             /* typedef_stm32cube_blocks_SPIControl_d_T */

#ifndef struct_tag_ifjF8yNW8GOgwK0Aett2gB
#define struct_tag_ifjF8yNW8GOgwK0Aett2gB

struct tag_ifjF8yNW8GOgwK0Aett2gB
{
  int32_T S0_isInitialized;
  real_T W0_ZERO_STATES[4];
  real_T W1_POLE_STATES[4];
  int32_T W2_PreviousNumChannels;
  real_T P0_ICRTP;
  real_T P1_RTP1COEFF[6];
  real_T P2_RTP2COEFF[6];
  real_T P3_RTP3COEFF[3];
  real_T P4_IC2RTP;
};

#endif                                 /* struct_tag_ifjF8yNW8GOgwK0Aett2gB */

#ifndef typedef_b_dsp_SOSFilter_0_PMSM_to_BLD_T
#define typedef_b_dsp_SOSFilter_0_PMSM_to_BLD_T

typedef struct tag_ifjF8yNW8GOgwK0Aett2gB b_dsp_SOSFilter_0_PMSM_to_BLD_T;

#endif                             /* typedef_b_dsp_SOSFilter_0_PMSM_to_BLD_T */

#ifndef struct_tag_4nIVXvaQgAt8pwY454plpD
#define struct_tag_4nIVXvaQgAt8pwY454plpD

struct tag_4nIVXvaQgAt8pwY454plpD
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_SOSFilter_0_PMSM_to_BLD_T cSFunObject;
};

#endif                                 /* struct_tag_4nIVXvaQgAt8pwY454plpD */

#ifndef typedef_b_dsp_SOSFilter_PMSM_to_BLDC__T
#define typedef_b_dsp_SOSFilter_PMSM_to_BLDC__T

typedef struct tag_4nIVXvaQgAt8pwY454plpD b_dsp_SOSFilter_PMSM_to_BLDC__T;

#endif                             /* typedef_b_dsp_SOSFilter_PMSM_to_BLDC__T */

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

#ifndef typedef_stm32cube_blocks_PWMOutput_PM_T
#define typedef_stm32cube_blocks_PWMOutput_PM_T

typedef struct tag_0RzKA0TA5eXyA1b3sjyvMG stm32cube_blocks_PWMOutput_PM_T;

#endif                             /* typedef_stm32cube_blocks_PWMOutput_PM_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_PMSM_to_BLDC_mod1_T
#define typedef_cell_wrap_PMSM_to_BLDC_mod1_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_PMSM_to_BLDC_mod1_T;

#endif                               /* typedef_cell_wrap_PMSM_to_BLDC_mod1_T */

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

#ifndef struct_tag_litERXNx1MFl7BtWqo0TqG
#define struct_tag_litERXNx1MFl7BtWqo0TqG

struct tag_litERXNx1MFl7BtWqo0TqG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_PMSM_to_BLDC_mod1_T inputVarSize;
  int32_T NumChannels;
  b_dsp_SOSFilter_PMSM_to_BLDC__T *FilterObj;
  b_dsp_SOSFilter_PMSM_to_BLDC__T coder_buffer_pobj0;
};

#endif                                 /* struct_tag_litERXNx1MFl7BtWqo0TqG */

#ifndef typedef_dsp_simulink_LowpassFilter_PM_T
#define typedef_dsp_simulink_LowpassFilter_PM_T

typedef struct tag_litERXNx1MFl7BtWqo0TqG dsp_simulink_LowpassFilter_PM_T;

#endif                             /* typedef_dsp_simulink_LowpassFilter_PM_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_PMSM_to_BLDC_mod1_T RT_MODEL_PMSM_to_BLDC_mod1_T;

#endif                                 /* PMSM_to_BLDC_mod1_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
