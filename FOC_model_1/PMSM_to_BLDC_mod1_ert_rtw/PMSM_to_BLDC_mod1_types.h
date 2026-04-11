/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1_types.h
 *
 * Code generated for Simulink model 'PMSM_to_BLDC_mod1'.
 *
 * Model version                  : 4.375
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Sat Apr 11 19:18:24 2026
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

#ifndef typedef_stm32cube_blocks_SPIControlle_T
#define typedef_stm32cube_blocks_SPIControlle_T

typedef struct tag_AkYSLo56SBzQIYxVc5esmB stm32cube_blocks_SPIControlle_T;

#endif                             /* typedef_stm32cube_blocks_SPIControlle_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_PMSM_to_BLDC_mod1_T RT_MODEL_PMSM_to_BLDC_mod1_T;

#endif                                 /* PMSM_to_BLDC_mod1_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
