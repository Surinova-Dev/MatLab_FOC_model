/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1_private.h
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

#ifndef PMSM_to_BLDC_mod1_private_h_
#define PMSM_to_BLDC_mod1_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "PMSM_to_BLDC_mod1.h"
#include "PMSM_to_BLDC_mod1_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetFirstInitCond
#define rtmSetFirstInitCond(rtm, val)  ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
#define rtmIsFirstInitCond(rtm)        ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T rt_modd_snf(real_T u0, real_T u1);
extern uint16_T PMSM_to_BLDC_mod1_BitShift(uint16_T rtu_u);
extern uint16_T PMSM_to_BLDC_mod1_BitShift1(uint16_T rtu_u);
extern void PMSM_to_BLDC_mo_SPIReceive_Init(DW_SPIReceive_PMSM_to_BLDC_mo_T
  *localDW);
extern void PMSM_to_BLDC_mod1_SPIReceive(B_SPIReceive_PMSM_to_BLDC_mod_T *localB,
  DW_SPIReceive_PMSM_to_BLDC_mo_T *localDW);
extern void PMSM_to_BLDC_m_SPITransmit_Init(DW_SPITransmit_PMSM_to_BLDC_m_T
  *localDW);
extern void PMSM_to_BLDC_mod1_SPITransmit(uint16_T rtu_0,
  DW_SPITransmit_PMSM_to_BLDC_m_T *localDW);
extern void PMSM_to_BLDC__SPIReceive_e_Init(DW_SPIReceive_PMSM_to_BLDC__f_T
  *localDW);
extern void PMSM_to_BLDC_mod1_SPIReceive_p(DW_SPIReceive_PMSM_to_BLDC__f_T
  *localDW);
extern void PMSM_to_BLDC_SPITransmit_d_Init(DW_SPITransmit_PMSM_to_BLDC_f_T
  *localDW);
extern void PMSM_to_BLDC_mod1_SPITransmit_p(uint16_T rtu_0,
  DW_SPITransmit_PMSM_to_BLDC_f_T *localDW);
extern real_T PMSM_to_BLDC__IfActionSubsystem(real_T rtu_In1);
extern real_T PMSM_to_BLDC_IfActionSubsystem1(real_T rtu_In1);
extern void PMSM_to_BLDC_mo_SPIReceive_Term(DW_SPIReceive_PMSM_to_BLDC_mo_T
  *localDW);
extern void PMSM_to_BLDC_m_SPITransmit_Term(DW_SPITransmit_PMSM_to_BLDC_m_T
  *localDW);
extern void PMSM_to_BLDC__SPIReceive_m_Term(DW_SPIReceive_PMSM_to_BLDC__f_T
  *localDW);
extern void PMSM_to_BLDC_SPITransmit_a_Term(DW_SPITransmit_PMSM_to_BLDC_f_T
  *localDW);

/* private model entry point functions */
extern void PMSM_to_BLDC_mod1_derivatives(void);

#endif                                 /* PMSM_to_BLDC_mod1_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
