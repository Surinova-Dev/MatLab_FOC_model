/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.h
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

#ifndef PMSM_to_BLDC_mod1_h_
#define PMSM_to_BLDC_mod1_h_
#ifndef PMSM_to_BLDC_mod1_COMMON_INCLUDES_
#define PMSM_to_BLDC_mod1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "nesl_rtw_rtp.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_gateway.h"
#include "nesl_rtw.h"
#endif                                 /* PMSM_to_BLDC_mod1_COMMON_INCLUDES_ */

#include "PMSM_to_BLDC_mod1_types.h"
#include <string.h>
#include "rtGetNaN.h"
#include <math.h>
#include "rt_matrixlib.h"
#include <stddef.h>
#include "zero_crossing_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMassMatrixIr
#define rtmGetMassMatrixIr(rtm)        ((rtm)->massMatrixIr)
#endif

#ifndef rtmSetMassMatrixIr
#define rtmSetMassMatrixIr(rtm, val)   ((rtm)->massMatrixIr = (val))
#endif

#ifndef rtmGetMassMatrixJc
#define rtmGetMassMatrixJc(rtm)        ((rtm)->massMatrixJc)
#endif

#ifndef rtmSetMassMatrixJc
#define rtmSetMassMatrixJc(rtm, val)   ((rtm)->massMatrixJc = (val))
#endif

#ifndef rtmGetMassMatrixNzMax
#define rtmGetMassMatrixNzMax(rtm)     ((rtm)->massMatrixNzMax)
#endif

#ifndef rtmSetMassMatrixNzMax
#define rtmSetMassMatrixNzMax(rtm, val) ((rtm)->massMatrixNzMax = (val))
#endif

#ifndef rtmGetMassMatrixPr
#define rtmGetMassMatrixPr(rtm)        ((rtm)->massMatrixPr)
#endif

#ifndef rtmSetMassMatrixPr
#define rtmSetMassMatrixPr(rtm, val)   ((rtm)->massMatrixPr = (val))
#endif

#ifndef rtmGetMassMatrixType
#define rtmGetMassMatrixType(rtm)      ((rtm)->massMatrixType)
#endif

#ifndef rtmSetMassMatrixType
#define rtmSetMassMatrixType(rtm, val) ((rtm)->massMatrixType = (val))
#endif

#ifndef rtmGetOdeDELTA
#define rtmGetOdeDELTA(rtm)            ((rtm)->odeDELTA)
#endif

#ifndef rtmSetOdeDELTA
#define rtmSetOdeDELTA(rtm, val)       ((rtm)->odeDELTA = (val))
#endif

#ifndef rtmGetOdeDFDX
#define rtmGetOdeDFDX(rtm)             ((rtm)->odeDFDX)
#endif

#ifndef rtmSetOdeDFDX
#define rtmSetOdeDFDX(rtm, val)        ((rtm)->odeDFDX = (val))
#endif

#ifndef rtmGetOdeE
#define rtmGetOdeE(rtm)                ((rtm)->odeE)
#endif

#ifndef rtmSetOdeE
#define rtmSetOdeE(rtm, val)           ((rtm)->odeE = (val))
#endif

#ifndef rtmGetOdeF0
#define rtmGetOdeF0(rtm)               ((rtm)->odeF0)
#endif

#ifndef rtmSetOdeF0
#define rtmSetOdeF0(rtm, val)          ((rtm)->odeF0 = (val))
#endif

#ifndef rtmGetOdeF1
#define rtmGetOdeF1(rtm)               ((rtm)->odeF1)
#endif

#ifndef rtmSetOdeF1
#define rtmSetOdeF1(rtm, val)          ((rtm)->odeF1 = (val))
#endif

#ifndef rtmGetOdeFAC
#define rtmGetOdeFAC(rtm)              ((rtm)->odeFAC)
#endif

#ifndef rtmSetOdeFAC
#define rtmSetOdeFAC(rtm, val)         ((rtm)->odeFAC = (val))
#endif

#ifndef rtmGetOdeMASSMATRIX_M
#define rtmGetOdeMASSMATRIX_M(rtm)     ((rtm)->odeMASSMATRIX_M)
#endif

#ifndef rtmSetOdeMASSMATRIX_M
#define rtmSetOdeMASSMATRIX_M(rtm, val) ((rtm)->odeMASSMATRIX_M = (val))
#endif

#ifndef rtmGetOdePIVOTS
#define rtmGetOdePIVOTS(rtm)           ((rtm)->odePIVOTS)
#endif

#ifndef rtmSetOdePIVOTS
#define rtmSetOdePIVOTS(rtm, val)      ((rtm)->odePIVOTS = (val))
#endif

#ifndef rtmGetOdeW
#define rtmGetOdeW(rtm)                ((rtm)->odeW)
#endif

#ifndef rtmSetOdeW
#define rtmSetOdeW(rtm, val)           ((rtm)->odeW = (val))
#endif

#ifndef rtmGetOdeX0
#define rtmGetOdeX0(rtm)               ((rtm)->odeX0)
#endif

#ifndef rtmSetOdeX0
#define rtmSetOdeX0(rtm, val)          ((rtm)->odeX0 = (val))
#endif

#ifndef rtmGetOdeX1START
#define rtmGetOdeX1START(rtm)          ((rtm)->odeX1START)
#endif

#ifndef rtmSetOdeX1START
#define rtmSetOdeX1START(rtm, val)     ((rtm)->odeX1START = (val))
#endif

#ifndef rtmGetOdeXTMP
#define rtmGetOdeXTMP(rtm)             ((rtm)->odeXTMP)
#endif

#ifndef rtmSetOdeXTMP
#define rtmSetOdeXTMP(rtm, val)        ((rtm)->odeXTMP = (val))
#endif

#ifndef rtmGetOdeZTMP
#define rtmGetOdeZTMP(rtm)             ((rtm)->odeZTMP)
#endif

#ifndef rtmSetOdeZTMP
#define rtmSetOdeZTMP(rtm, val)        ((rtm)->odeZTMP = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

/* user code (top of header file) */
#include "main.h"
#include "SPI_code.h"
#include "spi.h"
#include "dma.h"
#include "gpio.h"
#include "tim.h"
#include "adc.h"
#include "usart.h"

/* Block signals (default storage) */
typedef struct {
  real_T dv[56];
  real_T dv1[28];
  NeParameterBundle expl_temp;
  real_T Merge[2];                     /* '<S206>/Merge' */
  real_T Sum;                          /* '<S203>/Sum' */
  real_T Integrator;                   /* '<S248>/Integrator' */
  real_T ProportionalGain;             /* '<S408>/Proportional Gain' */
  real_T Gain[3];                      /* '<S12>/Gain' */
  real_T Add;                          /* '<S331>/Add' */
  real_T Add1;                         /* '<S331>/Add1' */
  real_T Add_h;                        /* '<S338>/Add' */
  real_T Add_d;                        /* '<S339>/Add' */
  real_T VectorConcatenate[3];         /* '<S322>/Vector Concatenate' */
  real_T RTP_1;                        /* '<S355>/RTP_1' */
  real_T INPUT_1_1_1[4];               /* '<S364>/INPUT_1_1_1' */
  real_T Add_p[3];                     /* '<S366>/Add' */
  real_T INPUT_2_1_1[4];               /* '<S364>/INPUT_2_1_1' */
  real_T INPUT_3_1_1[4];               /* '<S364>/INPUT_3_1_1' */
  real_T INPUT_4_1_1[4];               /* '<S364>/INPUT_4_1_1' */
  real_T INPUT_5_1_1[4];               /* '<S364>/INPUT_5_1_1' */
  real_T INPUT_6_1_1[4];               /* '<S364>/INPUT_6_1_1' */
  real_T INPUT_7_1_1[4];               /* '<S364>/INPUT_7_1_1' */
  real_T STATE_1[28];                  /* '<S364>/STATE_1' */
  real_T IntegralGain;                 /* '<S400>/Integral Gain' */
  real_T algDD_o2;
  int16_T Switch;                      /* '<S199>/Switch' */
  boolean_T Compare;                   /* '<S211>/Compare' */
} B_PMSM_to_BLDC_mod1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_PWMOutput_PM_T obj; /* '<S5>/PWM Output' */
  real_T Delay_DSTATE[3];              /* '<S2>/Delay' */
  real_T Delay_DSTATE_m[8];            /* '<S6>/Delay' */
  real_T Delay_DSTATE_c[2];            /* '<S183>/Delay' */
  real_T Delay_DSTATE_k[2];            /* '<S196>/Delay' */
  real_T Delay_DSTATE_a;               /* '<S279>/Delay' */
  real_T Delay_DSTATE_aj;              /* '<S303>/Delay' */
  real_T Integrator_DSTATE;            /* '<S248>/Integrator' */
  real_T Delay_DSTATE_ai;              /* '<S304>/Delay' */
  real_T Integrator_DSTATE_b;          /* '<S118>/Integrator' */
  real_T Integrator_DSTATE_n;          /* '<S63>/Integrator' */
  real_T Delay_DSTATE_g;               /* '<S210>/Delay' */
  real_T INPUT_1_1_1_Discrete_1975384460[2];/* '<S364>/INPUT_1_1_1' */
  real_T INPUT_2_1_1_Discrete_840794972[2];/* '<S364>/INPUT_2_1_1' */
  real_T INPUT_3_1_1_Discrete_259893996[2];/* '<S364>/INPUT_3_1_1' */
  real_T INPUT_4_1_1_Discrete_3177019132[2];/* '<S364>/INPUT_4_1_1' */
  real_T INPUT_5_1_1_Discrete_2151505740[2];/* '<S364>/INPUT_5_1_1' */
  real_T INPUT_6_1_1_Discrete_3348964764[2];/* '<S364>/INPUT_6_1_1' */
  real_T INPUT_7_1_1_Discrete_4210887724[2];/* '<S364>/INPUT_7_1_1' */
  real_T Delay_DSTATE_aa;              /* '<S296>/Delay' */
  real_T Delay2_DSTATE;                /* '<S291>/Delay2' */
  real_T Delay3_DSTATE;                /* '<S291>/Delay3' */
  real_T Delay2_DSTATE_h;              /* '<S290>/Delay2' */
  real_T Delay3_DSTATE_p;              /* '<S290>/Delay3' */
  real_T Delay_DSTATE_l;               /* '<S299>/Delay' */
  real_T Delay_DSTATE_av;              /* '<S286>/Delay' */
  real_T Delay1_DSTATE;                /* '<S283>/Delay1' */
  real_T Delay_DSTATE_f;               /* '<S283>/Delay' */
  real_T Delay_DSTATE_d;               /* '<S289>/Delay' */
  real_T Delay1_DSTATE_o;              /* '<S282>/Delay1' */
  real_T Delay_DSTATE_i;               /* '<S282>/Delay' */
  real_T STATE_1_Discrete;             /* '<S364>/STATE_1' */
  real_T STATE_1_ZcValueStore;         /* '<S364>/STATE_1' */
  real_T OUTPUT_1_0_Discrete;          /* '<S364>/OUTPUT_1_0' */
  real_T OUTPUT_1_0_ZcValueStore;      /* '<S364>/OUTPUT_1_0' */
  void* RTP_1_RtpManager;              /* '<S355>/RTP_1' */
  void* STATE_1_Simulator;             /* '<S364>/STATE_1' */
  void* STATE_1_SimData;               /* '<S364>/STATE_1' */
  void* STATE_1_DiagMgr;               /* '<S364>/STATE_1' */
  void* STATE_1_ZcLogger;              /* '<S364>/STATE_1' */
  void* STATE_1_TsInfo;                /* '<S364>/STATE_1' */
  void* OUTPUT_1_0_Simulator;          /* '<S364>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SimData;            /* '<S364>/OUTPUT_1_0' */
  void* OUTPUT_1_0_DiagMgr;            /* '<S364>/OUTPUT_1_0' */
  void* OUTPUT_1_0_ZcLogger;           /* '<S364>/OUTPUT_1_0' */
  void* OUTPUT_1_0_TsInfo;             /* '<S364>/OUTPUT_1_0' */
  real32_T Delay1_DSTATE_f;            /* '<S179>/Delay1' */
  real32_T Delay1_DSTATE_fx;           /* '<S2>/Delay1' */
  int_T STATE_1_Modes[11];             /* '<S364>/STATE_1' */
  int_T OUTPUT_1_0_Modes;              /* '<S364>/OUTPUT_1_0' */
  int32_T STATE_1_MASS_MATRIX_PR;      /* '<S364>/STATE_1' */
  int8_T If_ActiveSubsystem;           /* '<S197>/If' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S206>/Switch Case' */
  int8_T If_ActiveSubsystem_g;         /* '<S203>/If' */
  int8_T SwitchCase_ActiveSubsystem_n; /* '<S205>/Switch Case' */
  int8_T If_ActiveSubsystem_e;         /* '<S308>/If' */
  int8_T Integrator_PrevResetState;    /* '<S248>/Integrator' */
  int8_T If_ActiveSubsystem_c;         /* '<S169>/If' */
  int8_T Integrator_PrevResetState_n;  /* '<S118>/Integrator' */
  int8_T Integrator_PrevResetState_nt; /* '<S63>/Integrator' */
  int8_T If_ActiveSubsystem_m;         /* '<S143>/If' */
  uint8_T STATE_1_ZcSignalDir;         /* '<S364>/STATE_1' */
  uint8_T STATE_1_ZcStateStore;        /* '<S364>/STATE_1' */
  uint8_T OUTPUT_1_0_ZcSignalDir;      /* '<S364>/OUTPUT_1_0' */
  uint8_T OUTPUT_1_0_ZcStateStore;     /* '<S364>/OUTPUT_1_0' */
  boolean_T icLoad;                    /* '<S196>/Delay' */
  boolean_T AlphaRelay_Mode;           /* '<S197>/AlphaRelay' */
  boolean_T BetaRelay_Mode;            /* '<S197>/BetaRelay' */
  boolean_T icLoad_f;                  /* '<S279>/Delay' */
  boolean_T icLoad_a;                  /* '<S304>/Delay' */
  boolean_T icLoad_b;                  /* '<S210>/Delay' */
  boolean_T Integrator_DWORK1;         /* '<S338>/Integrator' */
  boolean_T Integrator_DWORK1_g;       /* '<S339>/Integrator' */
  boolean_T RTP_1_SetParametersNeeded; /* '<S355>/RTP_1' */
  boolean_T STATE_1_FirstOutput;       /* '<S364>/STATE_1' */
  boolean_T OUTPUT_1_0_FirstOutput;    /* '<S364>/OUTPUT_1_0' */
  boolean_T icLoad_b1;                 /* '<S296>/Delay' */
  boolean_T icLoad_c;                  /* '<S299>/Delay' */
  boolean_T icLoad_bd;                 /* '<S286>/Delay' */
  boolean_T icLoad_k;                  /* '<S289>/Delay' */
} DW_PMSM_to_BLDC_mod1_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S403>/Integrator' */
  real_T Integrator_CSTATE_d;          /* '<S338>/Integrator' */
  real_T Int1_CSTATE;                  /* '<S323>/Int1' */
  real_T Integrator_CSTATE_l;          /* '<S339>/Integrator' */
  real_T PMSM_to_BLDC_mod1SubsystemInver[17];/* '<S364>/STATE_1' */
} X_PMSM_to_BLDC_mod1_T;

/* Periodic continuous state vector (global) */
typedef int_T PeriodicIndX_PMSM_to_BLDC_mod_T[1];
typedef real_T PeriodicRngX_PMSM_to_BLDC_mod_T[2];

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S403>/Integrator' */
  real_T Integrator_CSTATE_d;          /* '<S338>/Integrator' */
  real_T Int1_CSTATE;                  /* '<S323>/Int1' */
  real_T Integrator_CSTATE_l;          /* '<S339>/Integrator' */
  real_T PMSM_to_BLDC_mod1SubsystemInver[17];/* '<S364>/STATE_1' */
} XDot_PMSM_to_BLDC_mod1_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S403>/Integrator' */
  boolean_T Integrator_CSTATE_d;       /* '<S338>/Integrator' */
  boolean_T Int1_CSTATE;               /* '<S323>/Int1' */
  boolean_T Integrator_CSTATE_l;       /* '<S339>/Integrator' */
  boolean_T PMSM_to_BLDC_mod1SubsystemInver[17];/* '<S364>/STATE_1' */
} XDis_PMSM_to_BLDC_mod1_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Delay1_Reset_ZCE;         /* '<S179>/Delay1' */
  ZCSigState Delay_Reset_ZCE;          /* '<S183>/Delay' */
  ZCSigState Delay_Reset_ZCE_a;        /* '<S303>/Delay' */
  ZCSigState Delay2_Reset_ZCE;         /* '<S291>/Delay2' */
  ZCSigState Delay3_Reset_ZCE;         /* '<S291>/Delay3' */
  ZCSigState Delay2_Reset_ZCE_p;       /* '<S290>/Delay2' */
  ZCSigState Delay3_Reset_ZCE_k;       /* '<S290>/Delay3' */
  ZCSigState Delay1_Reset_ZCE_p;       /* '<S283>/Delay1' */
  ZCSigState Delay_Reset_ZCE_h;        /* '<S283>/Delay' */
  ZCSigState Delay1_Reset_ZCE_i;       /* '<S282>/Delay1' */
  ZCSigState Delay_Reset_ZCE_k;        /* '<S282>/Delay' */
  ZCSigState Dir_Sense_Trig_ZCE;       /* '<S197>/Dir_Sense' */
} PrevZCX_PMSM_to_BLDC_mod1_T;

/* Mass Matrix (global) */
typedef struct {
  int_T ir[9];
  int_T jc[22];
  real_T pr[9];
} MassMatrix_PMSM_to_BLDC_mod1_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Constant3;              /* '<S24>/Constant3' */
  const real_T Constant3_n;            /* '<S25>/Constant3' */
  const real_T Switch;                 /* '<S318>/Switch' */
  const real_T Gain;                   /* '<S323>/Gain' */
  const real_T IndexVector;            /* '<S338>/Index Vector' */
  const real_T IndexVector_b;          /* '<S340>/Index Vector' */
  const real_T IndexVector_a;          /* '<S341>/Index Vector' */
  const real_T IndexVector1;           /* '<S341>/Index Vector1' */
  const real_T IndexVector_j;          /* '<S342>/Index Vector' */
  const real_T IndexVector_d;          /* '<S339>/Index Vector' */
  const real_T IndexVector_k;          /* '<S343>/Index Vector' */
  const real_T IndexVector_m;          /* '<S344>/Index Vector' */
  const real_T IndexVector1_g;         /* '<S344>/Index Vector1' */
  const real_T IndexVector_bt;         /* '<S345>/Index Vector' */
  const real_T Product;                /* '<S345>/Product' */
  const real_T IndexVector_d3;         /* '<S346>/Index Vector' */
  const uint32_T DataTypeConversion;   /* '<S206>/Data Type Conversion' */
} ConstB_PMSM_to_BLDC_mod1_T;

#ifndef ODE14X_INTG
#define ODE14X_INTG

/* ODE14X Integration Data */
typedef struct {
  real_T *x0;
  real_T *f0;
  real_T *x1start;
  real_T *f1;
  real_T *Delta;
  real_T *E;
  real_T *fac;
  real_T *DFDX;
  real_T *W;
  int_T *pivots;
  real_T *xtmp;
  real_T *ztmp;
  real_T *M;
  real_T *M1;
  real_T *Edot;
  real_T *xdot;
  real_T *fminusMxdot;
  boolean_T isFirstStep;
} ODE14X_IntgData;

#endif

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: dlgSett.sin_table)
   * Referenced by:
   *   '<S141>/sine_table_values'
   *   '<S167>/sine_table_values'
   */
  real_T pooled13[1002];

  /* Computed Parameter: sine_table_values_Value
   * Referenced by: '<S306>/sine_table_values'
   */
  real32_T sine_table_values_Value[1002];
} ConstP_PMSM_to_BLDC_mod1_T;

/* Real-time Model Data Structure */
struct tag_RTM_PMSM_to_BLDC_mod1_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_PMSM_to_BLDC_mod1_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_PMSM_to_BLDC_mod1_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  int_T massMatrixType;
  int_T massMatrixNzMax;
  int_T *massMatrixIr;
  int_T *massMatrixJc;
  real_T *massMatrixPr;
  real_T odeX0[21];
  real_T odeF0[21];
  real_T odeX1START[21];
  real_T odeF1[21];
  real_T odeDELTA[21];
  real_T odeE[4*21];
  real_T odeFAC[21];
  real_T odeDFDX[21*21];
  real_T odeW[21*21];
  int_T odePIVOTS[21];
  real_T odeXTMP[21];
  real_T odeZTMP[21];
  real_T odeMASSMATRIX_M[9];
  ODE14X_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    boolean_T firstInitCondFlag;
    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_B;

/* Continuous states (default storage) */
extern X_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_X;

/* Disabled states (default storage) */
extern XDis_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_XDis;

/* Block states (default storage) */
extern DW_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_PrevZCX;

/* global MassMatrix */
extern MassMatrix_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_MassMatrix;
extern const ConstB_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_ConstP;

/* Model entry point functions */
extern void PMSM_to_BLDC_mod1_initialize(void);
extern void PMSM_to_BLDC_mod1_step(void);
extern void PMSM_to_BLDC_mod1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PMSM_to_BLDC_mod1_T *const PMSM_to_BLDC_mod1_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Constant1' : Unused code path elimination
 * Block '<S13>/B' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/Display3' : Unused code path elimination
 * Block '<S15>/C' : Unused code path elimination
 * Block '<S15>/D' : Unused code path elimination
 * Block '<S141>/Data Type Duplicate' : Unused code path elimination
 * Block '<S141>/Data Type Propagation' : Unused code path elimination
 * Block '<S146>/Data Type Duplicate' : Unused code path elimination
 * Block '<S147>/Data Type Duplicate' : Unused code path elimination
 * Block '<S149>/Data Type Duplicate' : Unused code path elimination
 * Block '<S149>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S16>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Vc' : Unused code path elimination
 * Block '<S160>/Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/C' : Unused code path elimination
 * Block '<S17>/D' : Unused code path elimination
 * Block '<S167>/Data Type Duplicate' : Unused code path elimination
 * Block '<S167>/Data Type Propagation' : Unused code path elimination
 * Block '<S172>/Data Type Duplicate' : Unused code path elimination
 * Block '<S173>/Data Type Duplicate' : Unused code path elimination
 * Block '<S175>/Data Type Duplicate' : Unused code path elimination
 * Block '<S175>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S18>/Display' : Unused code path elimination
 * Block '<S18>/Scope' : Unused code path elimination
 * Block '<S10>/Scope' : Unused code path elimination
 * Block '<S6>/Display1' : Unused code path elimination
 * Block '<S6>/Display2' : Unused code path elimination
 * Block '<S6>/Scope' : Unused code path elimination
 * Block '<S179>/Data Type Propagation' : Unused code path elimination
 * Block '<S183>/Data Type Duplicate' : Unused code path elimination
 * Block '<S183>/Data Type Propagation' : Unused code path elimination
 * Block '<S186>/Data Type Duplicate' : Unused code path elimination
 * Block '<S186>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S186>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S186>/Data Type Propagation' : Unused code path elimination
 * Block '<S186>/Data Type Propagation1' : Unused code path elimination
 * Block '<S186>/Data Type Propagation2' : Unused code path elimination
 * Block '<S186>/Data Type Propagation3' : Unused code path elimination
 * Block '<S187>/Data Type Duplicate' : Unused code path elimination
 * Block '<S187>/Data Type Propagation' : Unused code path elimination
 * Block '<S188>/Data Type Duplicate' : Unused code path elimination
 * Block '<S188>/Data Type Propagation' : Unused code path elimination
 * Block '<S184>/Data Type Propagation' : Unused code path elimination
 * Block '<S189>/Data Type Duplicate' : Unused code path elimination
 * Block '<S189>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S189>/Data Type Propagation' : Unused code path elimination
 * Block '<S190>/Data Type Duplicate' : Unused code path elimination
 * Block '<S190>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S190>/Data Type Propagation' : Unused code path elimination
 * Block '<S191>/Data Type Duplicate' : Unused code path elimination
 * Block '<S191>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S191>/Data Type Propagation' : Unused code path elimination
 * Block '<S192>/Data Type Duplicate' : Unused code path elimination
 * Block '<S192>/Data Type Propagation' : Unused code path elimination
 * Block '<S185>/Data Type Propagation' : Unused code path elimination
 * Block '<S193>/Data Type Duplicate' : Unused code path elimination
 * Block '<S193>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S193>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S193>/Data Type Propagation' : Unused code path elimination
 * Block '<S193>/Data Type Propagation1' : Unused code path elimination
 * Block '<S181>/Data Type Duplicate' : Unused code path elimination
 * Block '<S198>/Data Type Duplicate' : Unused code path elimination
 * Block '<S198>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S198>/Data Type Conversion' : Unused code path elimination
 * Block '<S198>/Data Type Conversion1' : Unused code path elimination
 * Block '<S202>/Data Type Duplicate' : Unused code path elimination
 * Block '<S203>/Data Type Duplicate' : Unused code path elimination
 * Block '<S203>/Data Type Propagation' : Unused code path elimination
 * Block '<S212>/Data Type Duplicate' : Unused code path elimination
 * Block '<S213>/Data Type Duplicate' : Unused code path elimination
 * Block '<S213>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S213>/Data Type Propagation' : Unused code path elimination
 * Block '<S205>/Data Type Duplicate' : Unused code path elimination
 * Block '<S205>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S266>/I1CnstDT' : Unused code path elimination
 * Block '<S266>/I2CnstDT' : Unused code path elimination
 * Block '<S274>/Bias' : Unused code path elimination
 * Block '<S274>/Bias1' : Unused code path elimination
 * Block '<S274>/Constant' : Unused code path elimination
 * Block '<S274>/Data Type Duplicate' : Unused code path elimination
 * Block '<S274>/Data Type Propagation' : Unused code path elimination
 * Block '<S274>/Data Type Propagation1' : Unused code path elimination
 * Block '<S274>/Divide' : Unused code path elimination
 * Block '<S274>/Divide1' : Unused code path elimination
 * Block '<S274>/OD1Cnst' : Unused code path elimination
 * Block '<S274>/OD1CnstDT' : Unused code path elimination
 * Block '<S274>/Product' : Unused code path elimination
 * Block '<S274>/Unary Minus' : Unused code path elimination
 * Block '<S266>/MaxFreqCnst' : Unused code path elimination
 * Block '<S266>/OD1CnstDT' : Unused code path elimination
 * Block '<S266>/OD2CnstDT' : Unused code path elimination
 * Block '<S275>/Bias' : Unused code path elimination
 * Block '<S275>/Constant' : Unused code path elimination
 * Block '<S275>/Data Type Duplicate' : Unused code path elimination
 * Block '<S275>/Data Type Propagation' : Unused code path elimination
 * Block '<S275>/Data Type Propagation1' : Unused code path elimination
 * Block '<S275>/Data Type Propagation2' : Unused code path elimination
 * Block '<S275>/Divide' : Unused code path elimination
 * Block '<S275>/OD1Cnst' : Unused code path elimination
 * Block '<S275>/OD1CnstDT' : Unused code path elimination
 * Block '<S275>/OD1CnstDT1' : Unused code path elimination
 * Block '<S275>/Product' : Unused code path elimination
 * Block '<S275>/Product1' : Unused code path elimination
 * Block '<S275>/SampleTime' : Unused code path elimination
 * Block '<S276>/Const' : Unused code path elimination
 * Block '<S276>/Data Type Propagation' : Unused code path elimination
 * Block '<S276>/Data Type Propagation1' : Unused code path elimination
 * Block '<S276>/MaxFreqDT' : Unused code path elimination
 * Block '<S276>/Product' : Unused code path elimination
 * Block '<S267>/Data Type Duplicate' : Unused code path elimination
 * Block '<S268>/Bias' : Unused code path elimination
 * Block '<S268>/Constant' : Unused code path elimination
 * Block '<S268>/Data Type Propagation' : Unused code path elimination
 * Block '<S268>/Data Type Propagation1' : Unused code path elimination
 * Block '<S268>/Divide' : Unused code path elimination
 * Block '<S268>/Product' : Unused code path elimination
 * Block '<S269>/Data Type Duplicate' : Unused code path elimination
 * Block '<S269>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S269>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S280>/Data Type Duplicate' : Unused code path elimination
 * Block '<S281>/Data Type Duplicate' : Unused code path elimination
 * Block '<S282>/Data Type Duplicate' : Unused code path elimination
 * Block '<S282>/Data Type Propagation' : Unused code path elimination
 * Block '<S282>/Data Type Propagation1' : Unused code path elimination
 * Block '<S283>/Data Type Duplicate' : Unused code path elimination
 * Block '<S283>/Data Type Propagation' : Unused code path elimination
 * Block '<S283>/Data Type Propagation1' : Unused code path elimination
 * Block '<S272>/Data Type Duplicate' : Unused code path elimination
 * Block '<S290>/Data Type Duplicate' : Unused code path elimination
 * Block '<S290>/Data Type Propagation' : Unused code path elimination
 * Block '<S291>/Data Type Duplicate' : Unused code path elimination
 * Block '<S291>/Data Type Propagation' : Unused code path elimination
 * Block '<S292>/Data Type Duplicate' : Unused code path elimination
 * Block '<S293>/Data Type Duplicate' : Unused code path elimination
 * Block '<S273>/Bias' : Unused code path elimination
 * Block '<S273>/Constant' : Unused code path elimination
 * Block '<S273>/Data Type Propagation' : Unused code path elimination
 * Block '<S273>/Data Type Propagation1' : Unused code path elimination
 * Block '<S273>/Divide' : Unused code path elimination
 * Block '<S273>/Product' : Unused code path elimination
 * Block '<S206>/Data Type Duplicate' : Unused code path elimination
 * Block '<S303>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S303>/Data Type Propagation' : Unused code path elimination
 * Block '<S304>/BooleanTypeCast' : Unused code path elimination
 * Block '<S304>/Data Type Duplicate' : Unused code path elimination
 * Block '<S304>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S304>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S304>/Data Type Duplicate3' : Unused code path elimination
 * Block '<S304>/Data Type Propagation' : Unused code path elimination
 * Block '<S304>/InpGainDatatype' : Unused code path elimination
 * Block '<S304>/OutGainDatatype' : Unused code path elimination
 * Block '<S304>/Reset' : Unused code path elimination
 * Block '<S306>/Data Type Duplicate' : Unused code path elimination
 * Block '<S306>/Data Type Propagation' : Unused code path elimination
 * Block '<S311>/Data Type Duplicate' : Unused code path elimination
 * Block '<S312>/Data Type Duplicate' : Unused code path elimination
 * Block '<S6>/Time Scope' : Unused code path elimination
 * Block '<S2>/Display' : Unused code path elimination
 * Block '<S2>/Display3' : Unused code path elimination
 * Block '<S2>/Display4' : Unused code path elimination
 * Block '<S2>/Gain2' : Unused code path elimination
 * Block '<S2>/Gain3' : Unused code path elimination
 * Block '<S316>/Display' : Unused code path elimination
 * Block '<S316>/Display1' : Unused code path elimination
 * Block '<S316>/Gain' : Unused code path elimination
 * Block '<S316>/Gain1' : Unused code path elimination
 * Block '<S319>/Display' : Unused code path elimination
 * Block '<S319>/Gain' : Unused code path elimination
 * Block '<S319>/Gain1' : Unused code path elimination
 * Block '<S319>/Scope' : Unused code path elimination
 * Block '<S323>/Constant' : Unused code path elimination
 * Block '<S324>/Add' : Unused code path elimination
 * Block '<S324>/Add2' : Unused code path elimination
 * Block '<S324>/Add4' : Unused code path elimination
 * Block '<S324>/Constant' : Unused code path elimination
 * Block '<S324>/Gain' : Unused code path elimination
 * Block '<S324>/Gain1' : Unused code path elimination
 * Block '<S324>/Gain2' : Unused code path elimination
 * Block '<S326>/Constant' : Unused code path elimination
 * Block '<S326>/Mod' : Unused code path elimination
 * Block '<S326>/polepair' : Unused code path elimination
 * Block '<S324>/Product' : Unused code path elimination
 * Block '<S324>/Product1' : Unused code path elimination
 * Block '<S324>/Product11' : Unused code path elimination
 * Block '<S324>/Product12' : Unused code path elimination
 * Block '<S324>/Product2' : Unused code path elimination
 * Block '<S324>/Product3' : Unused code path elimination
 * Block '<S324>/Product4' : Unused code path elimination
 * Block '<S334>/Add' : Unused code path elimination
 * Block '<S334>/Gain1' : Unused code path elimination
 * Block '<S334>/Gain2' : Unused code path elimination
 * Block '<S334>/Product' : Unused code path elimination
 * Block '<S337>/Add' : Unused code path elimination
 * Block '<S337>/Constant' : Unused code path elimination
 * Block '<S337>/Constant1' : Unused code path elimination
 * Block '<S337>/Constant2' : Unused code path elimination
 * Block '<S337>/Index Vector' : Unused code path elimination
 * Block '<S337>/Index Vector1' : Unused code path elimination
 * Block '<S337>/Product' : Unused code path elimination
 * Block '<S316>/Scope' : Unused code path elimination
 * Block '<S314>/Scope' : Unused code path elimination
 * Block '<S317>/Gain' : Unused code path elimination
 * Block '<S314>/Time Scope' : Unused code path elimination
 * Block '<S315>/Gate_pulse' : Unused code path elimination
 * Block '<S8>/Display' : Unused code path elimination
 * Block '<S8>/Scope' : Unused code path elimination
 * Block '<S2>/Time Scope1' : Unused code path elimination
 * Block '<S2>/Time Scope2' : Unused code path elimination
 * Block '<S23>/Kalphabeta0' : Eliminated nontunable gain of 1
 * Block '<S141>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S160>/Ka' : Eliminated nontunable gain of 1
 * Block '<S160>/Kb' : Eliminated nontunable gain of 1
 * Block '<S160>/Kc' : Eliminated nontunable gain of 1
 * Block '<S167>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S18>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S19>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S19>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S6>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S177>/Data Type  Conversion' : Eliminate redundant data type conversion
 * Block '<S179>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S181>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S198>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S202>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S213>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S213>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S213>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S205>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S267>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S280>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S281>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S292>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S293>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S306>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S308>/convert_pu' : Eliminated nontunable gain of 1
 * Block '<S313>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S2>/Gain' : Eliminated nontunable gain of 1
 * Block '<S2>/Gain1' : Eliminated nontunable gain of 1
 * Block '<S316>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S366>/Gain5' : Eliminated nontunable gain of 1
 * Block '<S150>/Offset' : Unused code path elimination
 * Block '<S150>/Unary_Minus' : Unused code path elimination
 * Block '<S176>/Offset' : Unused code path elimination
 * Block '<S176>/Unary_Minus' : Unused code path elimination
 * Block '<S181>/One' : Unused code path elimination
 * Block '<S181>/Reset' : Unused code path elimination
 * Block '<S181>/Sum' : Unused code path elimination
 * Block '<S181>/UseInputPort' : Unused code path elimination
 * Block '<S181>/a' : Unused code path elimination
 * Block '<S202>/One' : Unused code path elimination
 * Block '<S202>/Reset' : Unused code path elimination
 * Block '<S202>/Sum' : Unused code path elimination
 * Block '<S202>/UseInputPort' : Unused code path elimination
 * Block '<S202>/a' : Unused code path elimination
 * Block '<S267>/FilterConstant' : Unused code path elimination
 * Block '<S267>/OneMinusFilterConstant' : Unused code path elimination
 * Block '<S267>/Reset' : Unused code path elimination
 * Block '<S267>/UseInputPort' : Unused code path elimination
 */

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
 * '<Root>' : 'PMSM_to_BLDC_mod1'
 * '<S1>'   : 'PMSM_to_BLDC_mod1/PWM Output'
 * '<S2>'   : 'PMSM_to_BLDC_mod1/Subsystem'
 * '<S3>'   : 'PMSM_to_BLDC_mod1/Subsystem1'
 * '<S4>'   : 'PMSM_to_BLDC_mod1/PWM Output/ECSoC'
 * '<S5>'   : 'PMSM_to_BLDC_mod1/PWM Output/ECSoC/ECSimCodegen'
 * '<S6>'   : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm '
 * '<S7>'   : 'PMSM_to_BLDC_mod1/Subsystem/Inverter'
 * '<S8>'   : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls'
 * '<S9>'   : 'PMSM_to_BLDC_mod1/Subsystem/Subsystem1'
 * '<S10>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform'
 * '<S11>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle'
 * '<S12>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Subsystem1'
 * '<S13>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Clarke Transform'
 * '<S14>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control'
 * '<S15>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Inverse Park Transform1'
 * '<S16>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/PWM Reference Generator'
 * '<S17>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Park Transform'
 * '<S18>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Position_Model'
 * '<S19>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/wrapping Mod'
 * '<S20>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Clarke Transform/Variant'
 * '<S21>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Clarke Transform/Variant/mcb'
 * '<S22>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Clarke Transform/Variant/mcb/Clarke Transform'
 * '<S23>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Clarke Transform/Variant/mcb/Clarke Transform/Three phase input'
 * '<S24>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq'
 * '<S25>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id'
 * '<S26>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID'
 * '<S27>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Anti-windup'
 * '<S28>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/D Gain'
 * '<S29>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/External Derivative'
 * '<S30>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Filter'
 * '<S31>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Filter ICs'
 * '<S32>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/I Gain'
 * '<S33>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Ideal P Gain'
 * '<S34>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Ideal P Gain Fdbk'
 * '<S35>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Integrator'
 * '<S36>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Integrator ICs'
 * '<S37>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/N Copy'
 * '<S38>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/N Gain'
 * '<S39>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/P Copy'
 * '<S40>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Parallel P Gain'
 * '<S41>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Reset Signal'
 * '<S42>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Saturation'
 * '<S43>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Saturation Fdbk'
 * '<S44>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Sum'
 * '<S45>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Sum Fdbk'
 * '<S46>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tracking Mode'
 * '<S47>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tracking Mode Sum'
 * '<S48>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tsamp - Integral'
 * '<S49>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tsamp - Ngain'
 * '<S50>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/postSat Signal'
 * '<S51>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/preInt Signal'
 * '<S52>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/preSat Signal'
 * '<S53>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel'
 * '<S54>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S55>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S56>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/D Gain/Disabled'
 * '<S57>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/External Derivative/Disabled'
 * '<S58>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Filter/Disabled'
 * '<S59>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Filter ICs/Disabled'
 * '<S60>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/I Gain/External Parameters'
 * '<S61>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Ideal P Gain/Passthrough'
 * '<S62>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Ideal P Gain Fdbk/Disabled'
 * '<S63>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Integrator/Discrete'
 * '<S64>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Integrator ICs/External IC'
 * '<S65>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/N Copy/Disabled wSignal Specification'
 * '<S66>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/N Gain/Disabled'
 * '<S67>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/P Copy/Disabled'
 * '<S68>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Parallel P Gain/External Parameters'
 * '<S69>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Reset Signal/External Reset'
 * '<S70>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Saturation/Enabled'
 * '<S71>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Saturation Fdbk/Disabled'
 * '<S72>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Sum/Sum_PI'
 * '<S73>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Sum Fdbk/Disabled'
 * '<S74>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tracking Mode/Disabled'
 * '<S75>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tracking Mode Sum/Passthrough'
 * '<S76>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tsamp - Integral/TsSignalSpecification'
 * '<S77>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tsamp - Ngain/Passthrough'
 * '<S78>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/postSat Signal/Forward_Path'
 * '<S79>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/preInt Signal/Internal PreInt'
 * '<S80>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/preSat Signal/Forward_Path'
 * '<S81>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID'
 * '<S82>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Anti-windup'
 * '<S83>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/D Gain'
 * '<S84>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/External Derivative'
 * '<S85>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Filter'
 * '<S86>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Filter ICs'
 * '<S87>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/I Gain'
 * '<S88>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Ideal P Gain'
 * '<S89>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Ideal P Gain Fdbk'
 * '<S90>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Integrator'
 * '<S91>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Integrator ICs'
 * '<S92>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/N Copy'
 * '<S93>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/N Gain'
 * '<S94>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/P Copy'
 * '<S95>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Parallel P Gain'
 * '<S96>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Reset Signal'
 * '<S97>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Saturation'
 * '<S98>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Saturation Fdbk'
 * '<S99>'  : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Sum'
 * '<S100>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Sum Fdbk'
 * '<S101>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tracking Mode'
 * '<S102>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tracking Mode Sum'
 * '<S103>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tsamp - Integral'
 * '<S104>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tsamp - Ngain'
 * '<S105>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/postSat Signal'
 * '<S106>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/preInt Signal'
 * '<S107>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/preSat Signal'
 * '<S108>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel'
 * '<S109>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S110>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S111>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/D Gain/Disabled'
 * '<S112>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/External Derivative/Disabled'
 * '<S113>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Filter/Disabled'
 * '<S114>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Filter ICs/Disabled'
 * '<S115>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/I Gain/External Parameters'
 * '<S116>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Ideal P Gain/Passthrough'
 * '<S117>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Ideal P Gain Fdbk/Disabled'
 * '<S118>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Integrator/Discrete'
 * '<S119>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Integrator ICs/External IC'
 * '<S120>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/N Copy/Disabled wSignal Specification'
 * '<S121>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/N Gain/Disabled'
 * '<S122>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/P Copy/Disabled'
 * '<S123>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Parallel P Gain/External Parameters'
 * '<S124>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Reset Signal/External Reset'
 * '<S125>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Saturation/Enabled'
 * '<S126>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Saturation Fdbk/Disabled'
 * '<S127>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Sum/Sum_PI'
 * '<S128>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Sum Fdbk/Disabled'
 * '<S129>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tracking Mode/Disabled'
 * '<S130>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tracking Mode Sum/Passthrough'
 * '<S131>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tsamp - Integral/TsSignalSpecification'
 * '<S132>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tsamp - Ngain/Passthrough'
 * '<S133>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/postSat Signal/Forward_Path'
 * '<S134>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/preInt Signal/Internal PreInt'
 * '<S135>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/preSat Signal/Forward_Path'
 * '<S136>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant'
 * '<S137>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb'
 * '<S138>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform'
 * '<S139>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine'
 * '<S140>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Three inputs'
 * '<S141>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup'
 * '<S142>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/Interpolation'
 * '<S143>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp'
 * '<S144>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/datatype'
 * '<S145>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S146>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S147>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S148>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S149>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Three inputs/Two inputs CRL'
 * '<S150>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Three inputs/Two inputs CRL/Switch_Axis'
 * '<S151>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/PWM Reference Generator/Modulation method'
 * '<S152>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input'
 * '<S153>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/PWM Reference Generator/Modulation method/SVPWM'
 * '<S154>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/PWM Reference Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S155>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input/Valphabeta'
 * '<S156>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S157>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Variant'
 * '<S158>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Variant/mcb'
 * '<S159>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Variant/mcb/Inverse Clarke Transform'
 * '<S160>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Variant/mcb/Inverse Clarke Transform/Two phase input'
 * '<S161>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Park Transform/Variant'
 * '<S162>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb'
 * '<S163>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform'
 * '<S164>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine'
 * '<S165>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Three inputs'
 * '<S166>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup'
 * '<S167>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S168>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S169>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S170>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S171>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S172>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S173>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S174>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S175>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Three inputs/Two inputs CRL'
 * '<S176>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Three inputs/Two inputs CRL/Switch_Axis'
 * '<S177>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Phase current Mesurement'
 * '<S178>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement'
 * '<S179>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer'
 * '<S180>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer'
 * '<S181>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/IIR Filter'
 * '<S182>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer'
 * '<S183>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)'
 * '<S184>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem'
 * '<S185>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem2'
 * '<S186>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/A11'
 * '<S187>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/A12'
 * '<S188>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/A22'
 * '<S189>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/L'
 * '<S190>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/L1'
 * '<S191>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/L2'
 * '<S192>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem2/B'
 * '<S193>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem2/L'
 * '<S194>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/IIR Filter/IIR Filter'
 * '<S195>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S196>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S197>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/Direction_Latch'
 * '<S198>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL'
 * '<S199>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/Direction_Latch/Dir_Sense'
 * '<S200>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/Direction_Latch/Subsystem2'
 * '<S201>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/Direction_Latch/Subsystem3'
 * '<S202>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/IIR Filter'
 * '<S203>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Normalize'
 * '<S204>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller'
 * '<S205>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward'
 * '<S206>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Subsystem'
 * '<S207>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO'
 * '<S208>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter'
 * '<S209>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter/Low-pass'
 * '<S210>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S211>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Normalize/Compare To Zero'
 * '<S212>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Normalize/If Action Subsystem'
 * '<S213>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Normalize/Subsystem'
 * '<S214>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Anti-windup'
 * '<S215>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/D Gain'
 * '<S216>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/External Derivative'
 * '<S217>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter'
 * '<S218>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter ICs'
 * '<S219>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/I Gain'
 * '<S220>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain'
 * '<S221>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain Fdbk'
 * '<S222>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator'
 * '<S223>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator ICs'
 * '<S224>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Copy'
 * '<S225>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Gain'
 * '<S226>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/P Copy'
 * '<S227>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Parallel P Gain'
 * '<S228>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Reset Signal'
 * '<S229>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation'
 * '<S230>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation Fdbk'
 * '<S231>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum'
 * '<S232>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum Fdbk'
 * '<S233>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode'
 * '<S234>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode Sum'
 * '<S235>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Integral'
 * '<S236>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Ngain'
 * '<S237>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/postSat Signal'
 * '<S238>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/preInt Signal'
 * '<S239>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/preSat Signal'
 * '<S240>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Anti-windup/Passthrough'
 * '<S241>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/D Gain/Disabled'
 * '<S242>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/External Derivative/Disabled'
 * '<S243>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter/Disabled'
 * '<S244>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter ICs/Disabled'
 * '<S245>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/I Gain/Internal Parameters'
 * '<S246>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain/Passthrough'
 * '<S247>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S248>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator/Discrete'
 * '<S249>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator ICs/Internal IC'
 * '<S250>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S251>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Gain/Disabled'
 * '<S252>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/P Copy/Disabled'
 * '<S253>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S254>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Reset Signal/External Reset'
 * '<S255>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation/Passthrough'
 * '<S256>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation Fdbk/Disabled'
 * '<S257>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum/Sum_PI'
 * '<S258>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum Fdbk/Disabled'
 * '<S259>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode/Disabled'
 * '<S260>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S261>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S262>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S263>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/postSat Signal/Forward_Path'
 * '<S264>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/preInt Signal/Internal PreInt'
 * '<S265>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/preSat Signal/Forward_Path'
 * '<S266>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/GainSystem'
 * '<S267>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter'
 * '<S268>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/InpFilterFunc'
 * '<S269>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod'
 * '<S270>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/Nofunc'
 * '<S271>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/NofuncSpd'
 * '<S272>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod'
 * '<S273>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/SpdFilterFunc'
 * '<S274>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/GainSystem/IGains'
 * '<S275>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/GainSystem/ODGains'
 * '<S276>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/GainSystem/OutDTSetup'
 * '<S277>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter/IIR Filter'
 * '<S278>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter/IIR Filter/Low-pass'
 * '<S279>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S280>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1'
 * '<S281>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3'
 * '<S282>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/Integrator'
 * '<S283>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/Integrator2'
 * '<S284>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter'
 * '<S285>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S286>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S287>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter'
 * '<S288>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S289>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S290>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/Differentiator'
 * '<S291>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/Differentiator1'
 * '<S292>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1'
 * '<S293>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3'
 * '<S294>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter'
 * '<S295>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S296>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S297>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter'
 * '<S298>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S299>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S300>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Subsystem/If Action Subsystem'
 * '<S301>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Subsystem/If Action Subsystem1'
 * '<S302>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem'
 * '<S303>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased'
 * '<S304>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Position Generator'
 * '<S305>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup'
 * '<S306>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S307>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S308>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S309>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S310>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S311>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S312>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S313>' : 'PMSM_to_BLDC_mod1/Subsystem/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype backpropogation'
 * '<S314>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation'
 * '<S315>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Subsystem2'
 * '<S316>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model'
 * '<S317>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel'
 * '<S318>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Average-Value Inverter'
 * '<S319>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model'
 * '<S320>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM'
 * '<S321>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous'
 * '<S322>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core'
 * '<S323>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Mechanical and Angle'
 * '<S324>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1'
 * '<S325>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic'
 * '<S326>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/MechToElect'
 * '<S327>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/Power Accounting Bus Creator'
 * '<S328>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/Power Accounting Bus Creator/PwrNotTrnsfrd Input'
 * '<S329>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/Power Accounting Bus Creator/PwrStored Input'
 * '<S330>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/Power Accounting Bus Creator/PwrTrnsfrd Input'
 * '<S331>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Clarke Transform'
 * '<S332>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Inverse Clarke Transform'
 * '<S333>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Inverse Park Transform'
 * '<S334>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Machine Torque'
 * '<S335>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit'
 * '<S336>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Park Transform'
 * '<S337>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Machine Torque/Subsystem'
 * '<S338>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage'
 * '<S339>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage'
 * '<S340>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem'
 * '<S341>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem1'
 * '<S342>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem2'
 * '<S343>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem'
 * '<S344>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem1'
 * '<S345>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem2'
 * '<S346>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem3'
 * '<S347>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/PS-Simulink Converter1'
 * '<S348>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter1'
 * '<S349>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter2'
 * '<S350>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter3'
 * '<S351>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter4'
 * '<S352>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter5'
 * '<S353>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter6'
 * '<S354>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter7'
 * '<S355>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration'
 * '<S356>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/PS-Simulink Converter1/EVAL_KEY'
 * '<S357>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter1/EVAL_KEY'
 * '<S358>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter2/EVAL_KEY'
 * '<S359>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter3/EVAL_KEY'
 * '<S360>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter4/EVAL_KEY'
 * '<S361>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter5/EVAL_KEY'
 * '<S362>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter6/EVAL_KEY'
 * '<S363>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter7/EVAL_KEY'
 * '<S364>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration/EVAL_KEY'
 * '<S365>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Subsystem2/Subsystem'
 * '<S366>' : 'PMSM_to_BLDC_mod1/Subsystem/Inverter/Subsystem2/Subsystem/Gate_Inverter1'
 * '<S367>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control'
 * '<S368>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller'
 * '<S369>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Anti-windup'
 * '<S370>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/D Gain'
 * '<S371>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/External Derivative'
 * '<S372>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Filter'
 * '<S373>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Filter ICs'
 * '<S374>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/I Gain'
 * '<S375>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Ideal P Gain'
 * '<S376>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Ideal P Gain Fdbk'
 * '<S377>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Integrator'
 * '<S378>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Integrator ICs'
 * '<S379>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/N Copy'
 * '<S380>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/N Gain'
 * '<S381>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/P Copy'
 * '<S382>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Parallel P Gain'
 * '<S383>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Reset Signal'
 * '<S384>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Saturation'
 * '<S385>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Saturation Fdbk'
 * '<S386>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Sum'
 * '<S387>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Sum Fdbk'
 * '<S388>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Tracking Mode'
 * '<S389>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Tracking Mode Sum'
 * '<S390>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Tsamp - Integral'
 * '<S391>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Tsamp - Ngain'
 * '<S392>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/postSat Signal'
 * '<S393>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/preInt Signal'
 * '<S394>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/preSat Signal'
 * '<S395>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Anti-windup/Passthrough'
 * '<S396>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/D Gain/Disabled'
 * '<S397>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/External Derivative/Disabled'
 * '<S398>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Filter/Disabled'
 * '<S399>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Filter ICs/Disabled'
 * '<S400>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/I Gain/Internal Parameters'
 * '<S401>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Ideal P Gain/Passthrough'
 * '<S402>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S403>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Integrator/Continuous'
 * '<S404>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Integrator ICs/Internal IC'
 * '<S405>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S406>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/N Gain/Disabled'
 * '<S407>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/P Copy/Disabled'
 * '<S408>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S409>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Reset Signal/Disabled'
 * '<S410>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Saturation/Passthrough'
 * '<S411>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Saturation Fdbk/Disabled'
 * '<S412>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Sum/Sum_PI'
 * '<S413>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Sum Fdbk/Disabled'
 * '<S414>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Tracking Mode/Disabled'
 * '<S415>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S416>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S417>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S418>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/postSat Signal/Forward_Path'
 * '<S419>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/preInt Signal/Internal PreInt'
 * '<S420>' : 'PMSM_to_BLDC_mod1/Subsystem/Speed_controls/Speed Control/PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* PMSM_to_BLDC_mod1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
