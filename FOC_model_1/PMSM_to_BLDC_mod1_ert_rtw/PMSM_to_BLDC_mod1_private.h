/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1_private.h
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

#ifndef PMSM_to_BLDC_mod1_private_h_
#define PMSM_to_BLDC_mod1_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "PMSM_to_BLDC_mod1.h"
#include "PMSM_to_BLDC_mod1_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern void PMSM_to_BLDC_mod1_BitShift_Init(DW_BitShift_PMSM_to_BLDC_mod1_T
  *localDW);
extern void PMSM_to_BLDC_mod1_BitShift(uint16_T rtu_u, uint16_T *rty_y,
  DW_BitShift_PMSM_to_BLDC_mod1_T *localDW);
extern void PMSM_to_BLDC_mod_BitShift4_Init(DW_BitShift4_PMSM_to_BLDC_mod_T
  *localDW);
extern void PMSM_to_BLDC_mod1_BitShift4(uint16_T rtu_u, uint16_T *rty_y,
  DW_BitShift4_PMSM_to_BLDC_mod_T *localDW);

#endif                                 /* PMSM_to_BLDC_mod1_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
