/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.h
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

#ifndef PMSM_to_BLDC_mod1_h_
#define PMSM_to_BLDC_mod1_h_
#ifndef PMSM_to_BLDC_mod1_COMMON_INCLUDES_
#define PMSM_to_BLDC_mod1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "main.h"
#include "mw_stm32_utils.h"
#include "MW_SPI.h"
#include "mw_stm32_spi_ll.h"
#include "nesl_rtw_rtp.h"
#include "PMSM_to_BLDC_mod1_5da39267_1_gateway.h"
#include "nesl_rtw.h"
#endif                                 /* PMSM_to_BLDC_mod1_COMMON_INCLUDES_ */

#include "PMSM_to_BLDC_mod1_types.h"
#include <string.h>
#include "rtGetNaN.h"
#include <math.h>
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

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
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

/* Block signals for system '<S20>/SPI Receive' */
typedef struct {
  uint16_T SPIReceive;                 /* '<S20>/SPI Receive' */
} B_SPIReceive_PMSM_to_BLDC_mod_T;

/* Block states (default storage) for system '<S20>/SPI Receive' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S20>/SPI Receive' */
  boolean_T objisempty;                /* '<S20>/SPI Receive' */
} DW_SPIReceive_PMSM_to_BLDC_mo_T;

/* Block states (default storage) for system '<S33>/SPI Transmit' */
typedef struct {
  stm32cube_blocks_SPIControl_d_T obj; /* '<S33>/SPI Transmit' */
  boolean_T objisempty;                /* '<S33>/SPI Transmit' */
} DW_SPITransmit_PMSM_to_BLDC_m_T;

/* Block states (default storage) for system '<S45>/SPI Receive' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S45>/SPI Receive' */
  boolean_T objisempty;                /* '<S45>/SPI Receive' */
} DW_SPIReceive_PMSM_to_BLDC__f_T;

/* Block states (default storage) for system '<S45>/SPI Transmit' */
typedef struct {
  stm32cube_blocks_SPIControl_d_T obj; /* '<S45>/SPI Transmit' */
  boolean_T objisempty;                /* '<S45>/SPI Transmit' */
} DW_SPITransmit_PMSM_to_BLDC_f_T;

/* Block signals (default storage) */
typedef struct {
  real_T dv[56];
  real_T dv1[28];
  int_T iv[9];
  NeParameterBundle expl_temp;
  int_T iv1[8];
  real_T INPUT_4_1_1[4];               /* '<S416>/INPUT_4_1_1' */
  real_T INPUT_5_1_1[4];               /* '<S416>/INPUT_5_1_1' */
  real_T INPUT_6_1_1[4];               /* '<S416>/INPUT_6_1_1' */
  real_T INPUT_7_1_1[4];               /* '<S416>/INPUT_7_1_1' */
  real_T STATE_1[28];                  /* '<S416>/STATE_1' */
  uint16_T uv[16];
  real_T Merge[2];                     /* '<S258>/Merge' */
  real_T Sum;                          /* '<S255>/Sum' */
  real_T Integrator;                   /* '<S300>/Integrator' */
  real_T ProportionalGain;             /* '<S460>/Proportional Gain' */
  real_T Gain[3];                      /* '<S64>/Gain' */
  real_T Add[3];                       /* '<S418>/Add' */
  real_T Add_a;                        /* '<S383>/Add' */
  real_T Add1;                         /* '<S383>/Add1' */
  real_T Add_h;                        /* '<S390>/Add' */
  real_T Add_d;                        /* '<S391>/Add' */
  real_T VectorConcatenate[3];         /* '<S374>/Vector Concatenate' */
  real_T RTP_1;                        /* '<S407>/RTP_1' */
  real_T INPUT_1_1_1[4];               /* '<S416>/INPUT_1_1_1' */
  real_T INPUT_2_1_1[4];               /* '<S416>/INPUT_2_1_1' */
  real_T INPUT_3_1_1[4];               /* '<S416>/INPUT_3_1_1' */
  real_T IntegralGain;                 /* '<S452>/Integral Gain' */
  real_T algDD_o2;
  real_T En_State;                     /* '<Root>/Chart' */
  real_T Ctrl_flag2;                   /* '<Root>/Chart' */
  real_T Ctrl_flag1;                   /* '<Root>/Chart' */
  real_T spi_write1;                   /* '<Root>/Chart' */
  real_T spi_write2;                   /* '<Root>/Chart' */
  real_T Ib_flag;                      /* '<Root>/Chart' */
  real_T Ic_flag;                      /* '<Root>/Chart' */
  real_T spi_write3;                   /* '<Root>/Chart' */
  real_T spi_write4;                   /* '<Root>/Chart' */
  real_T FOC_flag;                     /* '<Root>/Chart' */
  int16_T Switch;                      /* '<S251>/Switch' */
  boolean_T Compare;                   /* '<S263>/Compare' */
  B_SPIReceive_PMSM_to_BLDC_mod_T SPIReceive_pna;/* '<S20>/SPI Receive' */
  B_SPIReceive_PMSM_to_BLDC_mod_T SPIReceive_pn;/* '<S20>/SPI Receive' */
  B_SPIReceive_PMSM_to_BLDC_mod_T SPIReceive_j;/* '<S20>/SPI Receive' */
} B_PMSM_to_BLDC_mod1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S33>/SPI Receive' */
  stm32cube_blocks_SPIControlle_T obj_g;/* '<S19>/SPI Receive' */
  stm32cube_blocks_SPIControl_d_T obj_n;/* '<S20>/SPI Transmit' */
  stm32cube_blocks_SPIControl_d_T obj_j;/* '<S19>/SPI Transmit' */
  stm32cube_blocks_AnalogInput__T obj_o;/* '<S15>/Analog to Digital Converter' */
  stm32cube_blocks_AnalogInput__T obj_d;/* '<S12>/Analog to Digital Converter' */
  stm32cube_blocks_DigitalPortW_T obj_ow;/* '<S18>/Digital Port Write' */
  stm32cube_blocks_PWMOutput_PM_T obj_e;/* '<S474>/PWM Output' */
  real_T Delay_DSTATE[3];              /* '<S55>/Delay' */
  real_T Delay_DSTATE_m[8];            /* '<S58>/Delay' */
  real_T Delay_DSTATE_c[2];            /* '<S235>/Delay' */
  real_T Delay_DSTATE_k[2];            /* '<S248>/Delay' */
  real_T Delay_DSTATE_a;               /* '<S331>/Delay' */
  real_T Delay_DSTATE_aj;              /* '<S355>/Delay' */
  real_T Integrator_DSTATE;            /* '<S300>/Integrator' */
  real_T Delay_DSTATE_ai;              /* '<S356>/Delay' */
  real_T Integrator_DSTATE_b;          /* '<S170>/Integrator' */
  real_T Integrator_DSTATE_n;          /* '<S115>/Integrator' */
  real_T Delay_DSTATE_g;               /* '<S262>/Delay' */
  real_T INPUT_1_1_1_Discrete_2356258676[2];/* '<S416>/INPUT_1_1_1' */
  real_T INPUT_2_1_1_Discrete_3419528612[2];/* '<S416>/INPUT_2_1_1' */
  real_T INPUT_3_1_1_Discrete_4138857492[2];/* '<S416>/INPUT_3_1_1' */
  real_T INPUT_4_1_1_Discrete_1150363652[2];/* '<S416>/INPUT_4_1_1' */
  real_T INPUT_5_1_1_Discrete_2045837748[2];/* '<S416>/INPUT_5_1_1' */
  real_T INPUT_6_1_1_Discrete_1045527396[2];/* '<S416>/INPUT_6_1_1' */
  real_T INPUT_7_1_1_Discrete_53564116[2];/* '<S416>/INPUT_7_1_1' */
  real_T Delay_DSTATE_aa;              /* '<S348>/Delay' */
  real_T Delay2_DSTATE;                /* '<S343>/Delay2' */
  real_T Delay3_DSTATE;                /* '<S343>/Delay3' */
  real_T Delay2_DSTATE_h;              /* '<S342>/Delay2' */
  real_T Delay3_DSTATE_p;              /* '<S342>/Delay3' */
  real_T Delay_DSTATE_l;               /* '<S351>/Delay' */
  real_T Delay_DSTATE_av;              /* '<S338>/Delay' */
  real_T Delay1_DSTATE;                /* '<S335>/Delay1' */
  real_T Delay_DSTATE_f;               /* '<S335>/Delay' */
  real_T Delay_DSTATE_d;               /* '<S341>/Delay' */
  real_T Delay1_DSTATE_o;              /* '<S334>/Delay1' */
  real_T Delay_DSTATE_i;               /* '<S334>/Delay' */
  real_T STATE_1_Discrete;             /* '<S416>/STATE_1' */
  real_T STATE_1_ZcValueStore;         /* '<S416>/STATE_1' */
  real_T OUTPUT_1_0_Discrete;          /* '<S416>/OUTPUT_1_0' */
  real_T OUTPUT_1_0_ZcValueStore;      /* '<S416>/OUTPUT_1_0' */
  real_T CS_val;                       /* '<Root>/Chart' */
  void* RTP_1_RtpManager;              /* '<S407>/RTP_1' */
  void* STATE_1_Simulator;             /* '<S416>/STATE_1' */
  void* STATE_1_SimData;               /* '<S416>/STATE_1' */
  void* STATE_1_DiagMgr;               /* '<S416>/STATE_1' */
  void* STATE_1_ZcLogger;              /* '<S416>/STATE_1' */
  void* STATE_1_TsInfo;                /* '<S416>/STATE_1' */
  void* OUTPUT_1_0_Simulator;          /* '<S416>/OUTPUT_1_0' */
  void* OUTPUT_1_0_SimData;            /* '<S416>/OUTPUT_1_0' */
  void* OUTPUT_1_0_DiagMgr;            /* '<S416>/OUTPUT_1_0' */
  void* OUTPUT_1_0_ZcLogger;           /* '<S416>/OUTPUT_1_0' */
  void* OUTPUT_1_0_TsInfo;             /* '<S416>/OUTPUT_1_0' */
  real32_T Delay1_DSTATE_f;            /* '<S231>/Delay1' */
  real32_T Delay1_DSTATE_fx;           /* '<S55>/Delay1' */
  int_T STATE_1_Modes[11];             /* '<S416>/STATE_1' */
  int_T OUTPUT_1_0_Modes;              /* '<S416>/OUTPUT_1_0' */
  uint16_T temporalCounter_i1;         /* '<Root>/Chart' */
  int8_T If_ActiveSubsystem;           /* '<S249>/If' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S258>/Switch Case' */
  int8_T If_ActiveSubsystem_g;         /* '<S255>/If' */
  int8_T SwitchCase_ActiveSubsystem_n; /* '<S257>/Switch Case' */
  int8_T If_ActiveSubsystem_e;         /* '<S360>/If' */
  int8_T Integrator_PrevResetState;    /* '<S300>/Integrator' */
  int8_T If_ActiveSubsystem_c;         /* '<S221>/If' */
  int8_T Integrator_PrevResetState_n;  /* '<S170>/Integrator' */
  int8_T Integrator_PrevResetState_nt; /* '<S115>/Integrator' */
  int8_T If_ActiveSubsystem_m;         /* '<S195>/If' */
  uint8_T STATE_1_ZcSignalDir;         /* '<S416>/STATE_1' */
  uint8_T STATE_1_ZcStateStore;        /* '<S416>/STATE_1' */
  uint8_T OUTPUT_1_0_ZcSignalDir;      /* '<S416>/OUTPUT_1_0' */
  uint8_T OUTPUT_1_0_ZcStateStore;     /* '<S416>/OUTPUT_1_0' */
  uint8_T is_active_c3_PMSM_to_BLDC_mod1;/* '<Root>/Chart' */
  uint8_T is_c3_PMSM_to_BLDC_mod1;     /* '<Root>/Chart' */
  boolean_T icLoad;                    /* '<S248>/Delay' */
  boolean_T AlphaRelay_Mode;           /* '<S249>/AlphaRelay' */
  boolean_T BetaRelay_Mode;            /* '<S249>/BetaRelay' */
  boolean_T icLoad_f;                  /* '<S331>/Delay' */
  boolean_T icLoad_a;                  /* '<S356>/Delay' */
  boolean_T icLoad_b;                  /* '<S262>/Delay' */
  boolean_T Integrator_DWORK1;         /* '<S390>/Integrator' */
  boolean_T Integrator_DWORK1_g;       /* '<S391>/Integrator' */
  boolean_T RTP_1_SetParametersNeeded; /* '<S407>/RTP_1' */
  boolean_T STATE_1_FirstOutput;       /* '<S416>/STATE_1' */
  boolean_T OUTPUT_1_0_FirstOutput;    /* '<S416>/OUTPUT_1_0' */
  boolean_T icLoad_b1;                 /* '<S348>/Delay' */
  boolean_T icLoad_c;                  /* '<S351>/Delay' */
  boolean_T icLoad_bd;                 /* '<S338>/Delay' */
  boolean_T icLoad_k;                  /* '<S341>/Delay' */
  boolean_T Subsystem_MODE;            /* '<Root>/Subsystem' */
  boolean_T Status_Reg_2_read_MODE;    /* '<S6>/Status_Reg_2_read' */
  boolean_T Status_Reg1_read_MODE;     /* '<S6>/Status_Reg1_read' */
  boolean_T Subsystem1_MODE;           /* '<S32>/Subsystem1' */
  boolean_T Subsystem1_MODE_g;         /* '<S31>/Subsystem1' */
  DW_SPITransmit_PMSM_to_BLDC_f_T SPITransmit_pnaevv;/* '<S45>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC__f_T SPIReceive_pnaev;/* '<S45>/SPI Receive' */
  DW_SPITransmit_PMSM_to_BLDC_f_T SPITransmit_pnaev;/* '<S45>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC__f_T SPIReceive_pnae;/* '<S45>/SPI Receive' */
  DW_SPITransmit_PMSM_to_BLDC_m_T SPITransmit_pnae;/* '<S33>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC_mo_T SPIReceive_pna;/* '<S20>/SPI Receive' */
  DW_SPITransmit_PMSM_to_BLDC_m_T SPITransmit_pna;/* '<S33>/SPI Transmit' */
  DW_SPITransmit_PMSM_to_BLDC_m_T SPITransmit_pn;/* '<S33>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC_mo_T SPIReceive_pn;/* '<S20>/SPI Receive' */
  DW_SPITransmit_PMSM_to_BLDC_m_T SPITransmit_p;/* '<S33>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC_mo_T SPIReceive_j;/* '<S20>/SPI Receive' */
} DW_PMSM_to_BLDC_mod1_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S455>/Integrator' */
  real_T Integrator_CSTATE_d;          /* '<S390>/Integrator' */
  real_T Int1_CSTATE;                  /* '<S375>/Int1' */
  real_T Integrator_CSTATE_l;          /* '<S391>/Integrator' */
  real_T PMSM_to_BLDC_mod1SubsystemFOCIn[17];/* '<S416>/STATE_1' */
} X_PMSM_to_BLDC_mod1_T;

/* Periodic continuous state vector (global) */
typedef int_T PeriodicIndX_PMSM_to_BLDC_mod_T[1];
typedef real_T PeriodicRngX_PMSM_to_BLDC_mod_T[2];

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S455>/Integrator' */
  real_T Integrator_CSTATE_d;          /* '<S390>/Integrator' */
  real_T Int1_CSTATE;                  /* '<S375>/Int1' */
  real_T Integrator_CSTATE_l;          /* '<S391>/Integrator' */
  real_T PMSM_to_BLDC_mod1SubsystemFOCIn[17];/* '<S416>/STATE_1' */
} XDot_PMSM_to_BLDC_mod1_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S455>/Integrator' */
  boolean_T Integrator_CSTATE_d;       /* '<S390>/Integrator' */
  boolean_T Int1_CSTATE;               /* '<S375>/Int1' */
  boolean_T Integrator_CSTATE_l;       /* '<S391>/Integrator' */
  boolean_T PMSM_to_BLDC_mod1SubsystemFOCIn[17];/* '<S416>/STATE_1' */
} XDis_PMSM_to_BLDC_mod1_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Delay1_Reset_ZCE;         /* '<S231>/Delay1' */
  ZCSigState Delay_Reset_ZCE;          /* '<S235>/Delay' */
  ZCSigState Delay_Reset_ZCE_a;        /* '<S355>/Delay' */
  ZCSigState Delay2_Reset_ZCE;         /* '<S343>/Delay2' */
  ZCSigState Delay3_Reset_ZCE;         /* '<S343>/Delay3' */
  ZCSigState Delay2_Reset_ZCE_p;       /* '<S342>/Delay2' */
  ZCSigState Delay3_Reset_ZCE_k;       /* '<S342>/Delay3' */
  ZCSigState Delay1_Reset_ZCE_p;       /* '<S335>/Delay1' */
  ZCSigState Delay_Reset_ZCE_h;        /* '<S335>/Delay' */
  ZCSigState Delay1_Reset_ZCE_i;       /* '<S334>/Delay1' */
  ZCSigState Delay_Reset_ZCE_k;        /* '<S334>/Delay' */
  ZCSigState Dir_Sense_Trig_ZCE;       /* '<S249>/Dir_Sense' */
} PrevZCX_PMSM_to_BLDC_mod1_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Constant3;              /* '<S76>/Constant3' */
  const real_T Constant3_n;            /* '<S77>/Constant3' */
  const real_T Switch;                 /* '<S370>/Switch' */
  const real_T Gain;                   /* '<S375>/Gain' */
  const real_T IndexVector;            /* '<S390>/Index Vector' */
  const real_T IndexVector_b;          /* '<S392>/Index Vector' */
  const real_T IndexVector_a;          /* '<S393>/Index Vector' */
  const real_T IndexVector1;           /* '<S393>/Index Vector1' */
  const real_T IndexVector_j;          /* '<S394>/Index Vector' */
  const real_T IndexVector_d;          /* '<S391>/Index Vector' */
  const real_T IndexVector_k;          /* '<S395>/Index Vector' */
  const real_T IndexVector_m;          /* '<S396>/Index Vector' */
  const real_T IndexVector1_g;         /* '<S396>/Index Vector1' */
  const real_T IndexVector_bt;         /* '<S397>/Index Vector' */
  const real_T Product;                /* '<S397>/Product' */
  const real_T IndexVector_d3;         /* '<S398>/Index Vector' */
  const uint32_T DataTypeConversion;   /* '<S258>/Data Type Conversion' */
  const uint16_T BitwiseAND;           /* '<S46>/Bitwise AND' */
  const uint16_T BitwiseAND_m;         /* '<S45>/Bitwise AND' */
  const uint16_T BitwiseAND_j;         /* '<S39>/Bitwise AND' */
  const uint16_T BitwiseAND_d;         /* '<S33>/Bitwise AND' */
  const uint16_T BitwiseAND_e;         /* '<S20>/Bitwise AND' */
  const uint16_T BitwiseAND_jx;        /* '<S19>/Bitwise AND' */
} ConstB_PMSM_to_BLDC_mod1_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: dlgSett.sin_table)
   * Referenced by:
   *   '<S193>/sine_table_values'
   *   '<S219>/sine_table_values'
   */
  real_T pooled16[1002];

  /* Computed Parameter: sine_table_values_Value
   * Referenced by: '<S358>/sine_table_values'
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
  real_T odeY[21];
  real_T odeF[4][21];
  ODE4_IntgData intgData;

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
    uint32_T clockTick2;
    boolean_T firstInitCondFlag;
    struct {
      uint16_T TID[4];
    } TaskCounters;

    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[4];
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
 * Block '<S8>/Data Type Conversion' : Unused code path elimination
 * Block '<S8>/Display1' : Unused code path elimination
 * Block '<S8>/Gain' : Unused code path elimination
 * Block '<S9>/Data Type Conversion1' : Unused code path elimination
 * Block '<S9>/Display2' : Unused code path elimination
 * Block '<S9>/Gain1' : Unused code path elimination
 * Block '<S19>/Display' : Unused code path elimination
 * Block '<S20>/Display' : Unused code path elimination
 * Block '<S4>/Scope' : Unused code path elimination
 * Block '<S33>/Display' : Unused code path elimination
 * Block '<S39>/Display' : Unused code path elimination
 * Block '<S5>/Scope' : Unused code path elimination
 * Block '<S5>/Scope1' : Unused code path elimination
 * Block '<S5>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<S6>/Scope' : Unused code path elimination
 * Block '<S6>/Scope1' : Unused code path elimination
 * Block '<S45>/Display' : Unused code path elimination
 * Block '<S45>/Display1' : Unused code path elimination
 * Block '<S46>/Display' : Unused code path elimination
 * Block '<S55>/Constant1' : Unused code path elimination
 * Block '<S65>/B' : Unused code path elimination
 * Block '<S75>/Data Type Duplicate' : Unused code path elimination
 * Block '<S62>/Display3' : Unused code path elimination
 * Block '<S67>/C' : Unused code path elimination
 * Block '<S67>/D' : Unused code path elimination
 * Block '<S193>/Data Type Duplicate' : Unused code path elimination
 * Block '<S193>/Data Type Propagation' : Unused code path elimination
 * Block '<S198>/Data Type Duplicate' : Unused code path elimination
 * Block '<S199>/Data Type Duplicate' : Unused code path elimination
 * Block '<S201>/Data Type Duplicate' : Unused code path elimination
 * Block '<S201>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S68>/Data Type Duplicate' : Unused code path elimination
 * Block '<S68>/Vc' : Unused code path elimination
 * Block '<S212>/Data Type Duplicate' : Unused code path elimination
 * Block '<S69>/C' : Unused code path elimination
 * Block '<S69>/D' : Unused code path elimination
 * Block '<S219>/Data Type Duplicate' : Unused code path elimination
 * Block '<S219>/Data Type Propagation' : Unused code path elimination
 * Block '<S224>/Data Type Duplicate' : Unused code path elimination
 * Block '<S225>/Data Type Duplicate' : Unused code path elimination
 * Block '<S227>/Data Type Duplicate' : Unused code path elimination
 * Block '<S227>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S70>/Display' : Unused code path elimination
 * Block '<S70>/Scope' : Unused code path elimination
 * Block '<S62>/Scope' : Unused code path elimination
 * Block '<S58>/Display1' : Unused code path elimination
 * Block '<S58>/Display2' : Unused code path elimination
 * Block '<S58>/Scope' : Unused code path elimination
 * Block '<S231>/Data Type Propagation' : Unused code path elimination
 * Block '<S235>/Data Type Duplicate' : Unused code path elimination
 * Block '<S235>/Data Type Propagation' : Unused code path elimination
 * Block '<S238>/Data Type Duplicate' : Unused code path elimination
 * Block '<S238>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S238>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S238>/Data Type Propagation' : Unused code path elimination
 * Block '<S238>/Data Type Propagation1' : Unused code path elimination
 * Block '<S238>/Data Type Propagation2' : Unused code path elimination
 * Block '<S238>/Data Type Propagation3' : Unused code path elimination
 * Block '<S239>/Data Type Duplicate' : Unused code path elimination
 * Block '<S239>/Data Type Propagation' : Unused code path elimination
 * Block '<S240>/Data Type Duplicate' : Unused code path elimination
 * Block '<S240>/Data Type Propagation' : Unused code path elimination
 * Block '<S236>/Data Type Propagation' : Unused code path elimination
 * Block '<S241>/Data Type Duplicate' : Unused code path elimination
 * Block '<S241>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S241>/Data Type Propagation' : Unused code path elimination
 * Block '<S242>/Data Type Duplicate' : Unused code path elimination
 * Block '<S242>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S242>/Data Type Propagation' : Unused code path elimination
 * Block '<S243>/Data Type Duplicate' : Unused code path elimination
 * Block '<S243>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S243>/Data Type Propagation' : Unused code path elimination
 * Block '<S244>/Data Type Duplicate' : Unused code path elimination
 * Block '<S244>/Data Type Propagation' : Unused code path elimination
 * Block '<S237>/Data Type Propagation' : Unused code path elimination
 * Block '<S245>/Data Type Duplicate' : Unused code path elimination
 * Block '<S245>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S245>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S245>/Data Type Propagation' : Unused code path elimination
 * Block '<S245>/Data Type Propagation1' : Unused code path elimination
 * Block '<S233>/Data Type Duplicate' : Unused code path elimination
 * Block '<S250>/Data Type Duplicate' : Unused code path elimination
 * Block '<S250>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S250>/Data Type Conversion' : Unused code path elimination
 * Block '<S250>/Data Type Conversion1' : Unused code path elimination
 * Block '<S254>/Data Type Duplicate' : Unused code path elimination
 * Block '<S255>/Data Type Duplicate' : Unused code path elimination
 * Block '<S255>/Data Type Propagation' : Unused code path elimination
 * Block '<S264>/Data Type Duplicate' : Unused code path elimination
 * Block '<S265>/Data Type Duplicate' : Unused code path elimination
 * Block '<S265>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S265>/Data Type Propagation' : Unused code path elimination
 * Block '<S257>/Data Type Duplicate' : Unused code path elimination
 * Block '<S257>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S318>/I1CnstDT' : Unused code path elimination
 * Block '<S318>/I2CnstDT' : Unused code path elimination
 * Block '<S326>/Bias' : Unused code path elimination
 * Block '<S326>/Bias1' : Unused code path elimination
 * Block '<S326>/Constant' : Unused code path elimination
 * Block '<S326>/Data Type Duplicate' : Unused code path elimination
 * Block '<S326>/Data Type Propagation' : Unused code path elimination
 * Block '<S326>/Data Type Propagation1' : Unused code path elimination
 * Block '<S326>/Divide' : Unused code path elimination
 * Block '<S326>/Divide1' : Unused code path elimination
 * Block '<S326>/OD1Cnst' : Unused code path elimination
 * Block '<S326>/OD1CnstDT' : Unused code path elimination
 * Block '<S326>/Product' : Unused code path elimination
 * Block '<S326>/Unary Minus' : Unused code path elimination
 * Block '<S318>/MaxFreqCnst' : Unused code path elimination
 * Block '<S318>/OD1CnstDT' : Unused code path elimination
 * Block '<S318>/OD2CnstDT' : Unused code path elimination
 * Block '<S327>/Bias' : Unused code path elimination
 * Block '<S327>/Constant' : Unused code path elimination
 * Block '<S327>/Data Type Duplicate' : Unused code path elimination
 * Block '<S327>/Data Type Propagation' : Unused code path elimination
 * Block '<S327>/Data Type Propagation1' : Unused code path elimination
 * Block '<S327>/Data Type Propagation2' : Unused code path elimination
 * Block '<S327>/Divide' : Unused code path elimination
 * Block '<S327>/OD1Cnst' : Unused code path elimination
 * Block '<S327>/OD1CnstDT' : Unused code path elimination
 * Block '<S327>/OD1CnstDT1' : Unused code path elimination
 * Block '<S327>/Product' : Unused code path elimination
 * Block '<S327>/Product1' : Unused code path elimination
 * Block '<S327>/SampleTime' : Unused code path elimination
 * Block '<S328>/Const' : Unused code path elimination
 * Block '<S328>/Data Type Propagation' : Unused code path elimination
 * Block '<S328>/Data Type Propagation1' : Unused code path elimination
 * Block '<S328>/MaxFreqDT' : Unused code path elimination
 * Block '<S328>/Product' : Unused code path elimination
 * Block '<S319>/Data Type Duplicate' : Unused code path elimination
 * Block '<S320>/Bias' : Unused code path elimination
 * Block '<S320>/Constant' : Unused code path elimination
 * Block '<S320>/Data Type Propagation' : Unused code path elimination
 * Block '<S320>/Data Type Propagation1' : Unused code path elimination
 * Block '<S320>/Divide' : Unused code path elimination
 * Block '<S320>/Product' : Unused code path elimination
 * Block '<S321>/Data Type Duplicate' : Unused code path elimination
 * Block '<S321>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S321>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S332>/Data Type Duplicate' : Unused code path elimination
 * Block '<S333>/Data Type Duplicate' : Unused code path elimination
 * Block '<S334>/Data Type Duplicate' : Unused code path elimination
 * Block '<S334>/Data Type Propagation' : Unused code path elimination
 * Block '<S334>/Data Type Propagation1' : Unused code path elimination
 * Block '<S335>/Data Type Duplicate' : Unused code path elimination
 * Block '<S335>/Data Type Propagation' : Unused code path elimination
 * Block '<S335>/Data Type Propagation1' : Unused code path elimination
 * Block '<S324>/Data Type Duplicate' : Unused code path elimination
 * Block '<S342>/Data Type Duplicate' : Unused code path elimination
 * Block '<S342>/Data Type Propagation' : Unused code path elimination
 * Block '<S343>/Data Type Duplicate' : Unused code path elimination
 * Block '<S343>/Data Type Propagation' : Unused code path elimination
 * Block '<S344>/Data Type Duplicate' : Unused code path elimination
 * Block '<S345>/Data Type Duplicate' : Unused code path elimination
 * Block '<S325>/Bias' : Unused code path elimination
 * Block '<S325>/Constant' : Unused code path elimination
 * Block '<S325>/Data Type Propagation' : Unused code path elimination
 * Block '<S325>/Data Type Propagation1' : Unused code path elimination
 * Block '<S325>/Divide' : Unused code path elimination
 * Block '<S325>/Product' : Unused code path elimination
 * Block '<S258>/Data Type Duplicate' : Unused code path elimination
 * Block '<S355>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S355>/Data Type Propagation' : Unused code path elimination
 * Block '<S356>/BooleanTypeCast' : Unused code path elimination
 * Block '<S356>/Data Type Duplicate' : Unused code path elimination
 * Block '<S356>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S356>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S356>/Data Type Duplicate3' : Unused code path elimination
 * Block '<S356>/Data Type Propagation' : Unused code path elimination
 * Block '<S356>/InpGainDatatype' : Unused code path elimination
 * Block '<S356>/OutGainDatatype' : Unused code path elimination
 * Block '<S356>/Reset' : Unused code path elimination
 * Block '<S358>/Data Type Duplicate' : Unused code path elimination
 * Block '<S358>/Data Type Propagation' : Unused code path elimination
 * Block '<S363>/Data Type Duplicate' : Unused code path elimination
 * Block '<S364>/Data Type Duplicate' : Unused code path elimination
 * Block '<S58>/Time Scope' : Unused code path elimination
 * Block '<S55>/Display' : Unused code path elimination
 * Block '<S55>/Display3' : Unused code path elimination
 * Block '<S55>/Display4' : Unused code path elimination
 * Block '<S55>/Gain2' : Unused code path elimination
 * Block '<S55>/Gain3' : Unused code path elimination
 * Block '<S368>/Display' : Unused code path elimination
 * Block '<S368>/Display1' : Unused code path elimination
 * Block '<S368>/Gain' : Unused code path elimination
 * Block '<S368>/Gain1' : Unused code path elimination
 * Block '<S371>/Display' : Unused code path elimination
 * Block '<S371>/Gain' : Unused code path elimination
 * Block '<S371>/Gain1' : Unused code path elimination
 * Block '<S371>/Scope' : Unused code path elimination
 * Block '<S375>/Constant' : Unused code path elimination
 * Block '<S376>/Add' : Unused code path elimination
 * Block '<S376>/Add2' : Unused code path elimination
 * Block '<S376>/Add4' : Unused code path elimination
 * Block '<S376>/Constant' : Unused code path elimination
 * Block '<S376>/Gain' : Unused code path elimination
 * Block '<S376>/Gain1' : Unused code path elimination
 * Block '<S376>/Gain2' : Unused code path elimination
 * Block '<S378>/Constant' : Unused code path elimination
 * Block '<S378>/Mod' : Unused code path elimination
 * Block '<S378>/polepair' : Unused code path elimination
 * Block '<S376>/Product' : Unused code path elimination
 * Block '<S376>/Product1' : Unused code path elimination
 * Block '<S376>/Product11' : Unused code path elimination
 * Block '<S376>/Product12' : Unused code path elimination
 * Block '<S376>/Product2' : Unused code path elimination
 * Block '<S376>/Product3' : Unused code path elimination
 * Block '<S376>/Product4' : Unused code path elimination
 * Block '<S386>/Add' : Unused code path elimination
 * Block '<S386>/Gain1' : Unused code path elimination
 * Block '<S386>/Gain2' : Unused code path elimination
 * Block '<S386>/Product' : Unused code path elimination
 * Block '<S389>/Add' : Unused code path elimination
 * Block '<S389>/Constant' : Unused code path elimination
 * Block '<S389>/Constant1' : Unused code path elimination
 * Block '<S389>/Constant2' : Unused code path elimination
 * Block '<S389>/Index Vector' : Unused code path elimination
 * Block '<S389>/Index Vector1' : Unused code path elimination
 * Block '<S389>/Product' : Unused code path elimination
 * Block '<S368>/Scope' : Unused code path elimination
 * Block '<S366>/Scope' : Unused code path elimination
 * Block '<S369>/Gain' : Unused code path elimination
 * Block '<S367>/Gate_pulse' : Unused code path elimination
 * Block '<S60>/Display' : Unused code path elimination
 * Block '<S60>/Scope' : Unused code path elimination
 * Block '<S55>/Time Scope1' : Unused code path elimination
 * Block '<S55>/Time Scope2' : Unused code path elimination
 * Block '<S57>/Data Type Conversion1' : Unused code path elimination
 * Block '<S57>/Data Type Conversion3' : Unused code path elimination
 * Block '<S57>/Data Type Conversion5' : Unused code path elimination
 * Block '<S19>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S20>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S45>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S75>/Kalphabeta0' : Eliminated nontunable gain of 1
 * Block '<S193>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S212>/Ka' : Eliminated nontunable gain of 1
 * Block '<S212>/Kb' : Eliminated nontunable gain of 1
 * Block '<S212>/Kc' : Eliminated nontunable gain of 1
 * Block '<S219>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S71>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S71>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S58>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S229>/Data Type  Conversion' : Eliminate redundant data type conversion
 * Block '<S231>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S233>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S250>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S254>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S265>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S265>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S265>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S257>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S319>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S332>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S333>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S344>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S345>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S358>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S360>/convert_pu' : Eliminated nontunable gain of 1
 * Block '<S365>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S55>/Gain' : Eliminated nontunable gain of 1
 * Block '<S55>/Gain1' : Eliminated nontunable gain of 1
 * Block '<S368>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S418>/Gain5' : Eliminated nontunable gain of 1
 * Block '<S202>/Offset' : Unused code path elimination
 * Block '<S202>/Unary_Minus' : Unused code path elimination
 * Block '<S228>/Offset' : Unused code path elimination
 * Block '<S228>/Unary_Minus' : Unused code path elimination
 * Block '<S233>/One' : Unused code path elimination
 * Block '<S233>/Reset' : Unused code path elimination
 * Block '<S233>/Sum' : Unused code path elimination
 * Block '<S233>/UseInputPort' : Unused code path elimination
 * Block '<S233>/a' : Unused code path elimination
 * Block '<S254>/One' : Unused code path elimination
 * Block '<S254>/Reset' : Unused code path elimination
 * Block '<S254>/Sum' : Unused code path elimination
 * Block '<S254>/UseInputPort' : Unused code path elimination
 * Block '<S254>/a' : Unused code path elimination
 * Block '<S319>/FilterConstant' : Unused code path elimination
 * Block '<S319>/OneMinusFilterConstant' : Unused code path elimination
 * Block '<S319>/Reset' : Unused code path elimination
 * Block '<S319>/UseInputPort' : Unused code path elimination
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
 * '<S1>'   : 'PMSM_to_BLDC_mod1/Chart'
 * '<S2>'   : 'PMSM_to_BLDC_mod1/Current_sensing'
 * '<S3>'   : 'PMSM_to_BLDC_mod1/En_gate'
 * '<S4>'   : 'PMSM_to_BLDC_mod1/SPI_Write'
 * '<S5>'   : 'PMSM_to_BLDC_mod1/SPI_read'
 * '<S6>'   : 'PMSM_to_BLDC_mod1/Status_reg_read'
 * '<S7>'   : 'PMSM_to_BLDC_mod1/Subsystem'
 * '<S8>'   : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem'
 * '<S9>'   : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem1'
 * '<S10>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem/Analog to Digital Converter1'
 * '<S11>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem/Analog to Digital Converter1/ECSoC'
 * '<S12>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem/Analog to Digital Converter1/ECSoC/ECSimCodegen'
 * '<S13>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem1/Analog to Digital Converter2'
 * '<S14>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem1/Analog to Digital Converter2/ECSoC'
 * '<S15>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem1/Analog to Digital Converter2/ECSoC/ECSimCodegen'
 * '<S16>'  : 'PMSM_to_BLDC_mod1/En_gate/Digital Port Write'
 * '<S17>'  : 'PMSM_to_BLDC_mod1/En_gate/Digital Port Write/ECSoC'
 * '<S18>'  : 'PMSM_to_BLDC_mod1/En_gate/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S19>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2'
 * '<S20>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1'
 * '<S21>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2/Bit Shift'
 * '<S22>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2/Bit Shift1'
 * '<S23>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2/Bit Shift/bit_shift'
 * '<S24>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2/Bit Shift1/bit_shift'
 * '<S25>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1/Bit Shift'
 * '<S26>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1/Bit Shift1'
 * '<S27>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1/Bit Shift/bit_shift'
 * '<S28>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1/Bit Shift1/bit_shift'
 * '<S29>'  : 'PMSM_to_BLDC_mod1/SPI_read/Compare To Constant'
 * '<S30>'  : 'PMSM_to_BLDC_mod1/SPI_read/Compare To Constant1'
 * '<S31>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read'
 * '<S32>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read'
 * '<S33>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem'
 * '<S34>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem1'
 * '<S35>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem/Bit Shift'
 * '<S36>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem/Bit Shift1'
 * '<S37>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem/Bit Shift/bit_shift'
 * '<S38>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem/Bit Shift1/bit_shift'
 * '<S39>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem'
 * '<S40>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem1'
 * '<S41>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem/Bit Shift'
 * '<S42>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem/Bit Shift1'
 * '<S43>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem/Bit Shift/bit_shift'
 * '<S44>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem/Bit Shift1/bit_shift'
 * '<S45>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read'
 * '<S46>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read'
 * '<S47>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read/Bit Shift'
 * '<S48>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read/Bit Shift1'
 * '<S49>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read/Bit Shift/bit_shift'
 * '<S50>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read/Bit Shift1/bit_shift'
 * '<S51>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read/Bit Shift'
 * '<S52>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read/Bit Shift1'
 * '<S53>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read/Bit Shift/bit_shift'
 * '<S54>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read/Bit Shift1/bit_shift'
 * '<S55>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC'
 * '<S56>'  : 'PMSM_to_BLDC_mod1/Subsystem/PWM Output'
 * '<S57>'  : 'PMSM_to_BLDC_mod1/Subsystem/Pulse to timer '
 * '<S58>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm '
 * '<S59>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter'
 * '<S60>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls'
 * '<S61>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Subsystem1'
 * '<S62>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform'
 * '<S63>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle'
 * '<S64>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Subsystem1'
 * '<S65>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Clarke Transform'
 * '<S66>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control'
 * '<S67>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1'
 * '<S68>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator'
 * '<S69>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Park Transform'
 * '<S70>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Position_Model'
 * '<S71>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/wrapping Mod'
 * '<S72>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Clarke Transform/Variant'
 * '<S73>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Clarke Transform/Variant/mcb'
 * '<S74>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Clarke Transform/Variant/mcb/Clarke Transform'
 * '<S75>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Clarke Transform/Variant/mcb/Clarke Transform/Three phase input'
 * '<S76>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq'
 * '<S77>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id'
 * '<S78>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID'
 * '<S79>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Anti-windup'
 * '<S80>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/D Gain'
 * '<S81>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/External Derivative'
 * '<S82>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Filter'
 * '<S83>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Filter ICs'
 * '<S84>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/I Gain'
 * '<S85>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Ideal P Gain'
 * '<S86>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Ideal P Gain Fdbk'
 * '<S87>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Integrator'
 * '<S88>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Integrator ICs'
 * '<S89>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/N Copy'
 * '<S90>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/N Gain'
 * '<S91>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/P Copy'
 * '<S92>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Parallel P Gain'
 * '<S93>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Reset Signal'
 * '<S94>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Saturation'
 * '<S95>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Saturation Fdbk'
 * '<S96>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Sum'
 * '<S97>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Sum Fdbk'
 * '<S98>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tracking Mode'
 * '<S99>'  : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tracking Mode Sum'
 * '<S100>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tsamp - Integral'
 * '<S101>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tsamp - Ngain'
 * '<S102>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/postSat Signal'
 * '<S103>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/preInt Signal'
 * '<S104>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/preSat Signal'
 * '<S105>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel'
 * '<S106>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S107>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S108>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/D Gain/Disabled'
 * '<S109>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/External Derivative/Disabled'
 * '<S110>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Filter/Disabled'
 * '<S111>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Filter ICs/Disabled'
 * '<S112>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/I Gain/External Parameters'
 * '<S113>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Ideal P Gain/Passthrough'
 * '<S114>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Ideal P Gain Fdbk/Disabled'
 * '<S115>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Integrator/Discrete'
 * '<S116>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Integrator ICs/External IC'
 * '<S117>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/N Copy/Disabled wSignal Specification'
 * '<S118>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/N Gain/Disabled'
 * '<S119>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/P Copy/Disabled'
 * '<S120>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Parallel P Gain/External Parameters'
 * '<S121>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Reset Signal/External Reset'
 * '<S122>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Saturation/Enabled'
 * '<S123>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Saturation Fdbk/Disabled'
 * '<S124>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Sum/Sum_PI'
 * '<S125>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Sum Fdbk/Disabled'
 * '<S126>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tracking Mode/Disabled'
 * '<S127>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tracking Mode Sum/Passthrough'
 * '<S128>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tsamp - Integral/TsSignalSpecification'
 * '<S129>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tsamp - Ngain/Passthrough'
 * '<S130>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/postSat Signal/Forward_Path'
 * '<S131>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/preInt Signal/Internal PreInt'
 * '<S132>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/preSat Signal/Forward_Path'
 * '<S133>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID'
 * '<S134>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Anti-windup'
 * '<S135>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/D Gain'
 * '<S136>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/External Derivative'
 * '<S137>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Filter'
 * '<S138>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Filter ICs'
 * '<S139>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/I Gain'
 * '<S140>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Ideal P Gain'
 * '<S141>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Ideal P Gain Fdbk'
 * '<S142>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Integrator'
 * '<S143>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Integrator ICs'
 * '<S144>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/N Copy'
 * '<S145>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/N Gain'
 * '<S146>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/P Copy'
 * '<S147>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Parallel P Gain'
 * '<S148>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Reset Signal'
 * '<S149>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Saturation'
 * '<S150>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Saturation Fdbk'
 * '<S151>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Sum'
 * '<S152>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Sum Fdbk'
 * '<S153>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tracking Mode'
 * '<S154>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tracking Mode Sum'
 * '<S155>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tsamp - Integral'
 * '<S156>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tsamp - Ngain'
 * '<S157>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/postSat Signal'
 * '<S158>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/preInt Signal'
 * '<S159>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/preSat Signal'
 * '<S160>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel'
 * '<S161>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S162>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S163>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/D Gain/Disabled'
 * '<S164>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/External Derivative/Disabled'
 * '<S165>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Filter/Disabled'
 * '<S166>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Filter ICs/Disabled'
 * '<S167>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/I Gain/External Parameters'
 * '<S168>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Ideal P Gain/Passthrough'
 * '<S169>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Ideal P Gain Fdbk/Disabled'
 * '<S170>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Integrator/Discrete'
 * '<S171>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Integrator ICs/External IC'
 * '<S172>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/N Copy/Disabled wSignal Specification'
 * '<S173>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/N Gain/Disabled'
 * '<S174>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/P Copy/Disabled'
 * '<S175>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Parallel P Gain/External Parameters'
 * '<S176>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Reset Signal/External Reset'
 * '<S177>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Saturation/Enabled'
 * '<S178>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Saturation Fdbk/Disabled'
 * '<S179>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Sum/Sum_PI'
 * '<S180>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Sum Fdbk/Disabled'
 * '<S181>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tracking Mode/Disabled'
 * '<S182>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tracking Mode Sum/Passthrough'
 * '<S183>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tsamp - Integral/TsSignalSpecification'
 * '<S184>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tsamp - Ngain/Passthrough'
 * '<S185>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/postSat Signal/Forward_Path'
 * '<S186>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/preInt Signal/Internal PreInt'
 * '<S187>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/preSat Signal/Forward_Path'
 * '<S188>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant'
 * '<S189>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb'
 * '<S190>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform'
 * '<S191>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine'
 * '<S192>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Three inputs'
 * '<S193>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup'
 * '<S194>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/Interpolation'
 * '<S195>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp'
 * '<S196>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/datatype'
 * '<S197>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S198>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S199>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S200>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S201>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Three inputs/Two inputs CRL'
 * '<S202>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Three inputs/Two inputs CRL/Switch_Axis'
 * '<S203>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Modulation method'
 * '<S204>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input'
 * '<S205>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Modulation method/SVPWM'
 * '<S206>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S207>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input/Valphabeta'
 * '<S208>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S209>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Variant'
 * '<S210>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Variant/mcb'
 * '<S211>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Variant/mcb/Inverse Clarke Transform'
 * '<S212>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Variant/mcb/Inverse Clarke Transform/Two phase input'
 * '<S213>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant'
 * '<S214>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb'
 * '<S215>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform'
 * '<S216>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine'
 * '<S217>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Three inputs'
 * '<S218>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup'
 * '<S219>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S220>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S221>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S222>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S223>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S224>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S225>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S226>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S227>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Three inputs/Two inputs CRL'
 * '<S228>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Three inputs/Two inputs CRL/Switch_Axis'
 * '<S229>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Phase current Mesurement'
 * '<S230>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement'
 * '<S231>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer'
 * '<S232>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer'
 * '<S233>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/IIR Filter'
 * '<S234>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer'
 * '<S235>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)'
 * '<S236>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem'
 * '<S237>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem2'
 * '<S238>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/A11'
 * '<S239>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/A12'
 * '<S240>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/A22'
 * '<S241>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/L'
 * '<S242>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/L1'
 * '<S243>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/L2'
 * '<S244>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem2/B'
 * '<S245>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem2/L'
 * '<S246>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/IIR Filter/IIR Filter'
 * '<S247>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S248>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S249>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/Direction_Latch'
 * '<S250>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL'
 * '<S251>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/Direction_Latch/Dir_Sense'
 * '<S252>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/Direction_Latch/Subsystem2'
 * '<S253>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/Direction_Latch/Subsystem3'
 * '<S254>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/IIR Filter'
 * '<S255>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Normalize'
 * '<S256>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller'
 * '<S257>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward'
 * '<S258>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Subsystem'
 * '<S259>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO'
 * '<S260>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter'
 * '<S261>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter/Low-pass'
 * '<S262>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S263>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Normalize/Compare To Zero'
 * '<S264>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Normalize/If Action Subsystem'
 * '<S265>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Normalize/Subsystem'
 * '<S266>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Anti-windup'
 * '<S267>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/D Gain'
 * '<S268>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/External Derivative'
 * '<S269>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter'
 * '<S270>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter ICs'
 * '<S271>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/I Gain'
 * '<S272>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain'
 * '<S273>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain Fdbk'
 * '<S274>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator'
 * '<S275>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator ICs'
 * '<S276>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Copy'
 * '<S277>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Gain'
 * '<S278>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/P Copy'
 * '<S279>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Parallel P Gain'
 * '<S280>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Reset Signal'
 * '<S281>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation'
 * '<S282>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation Fdbk'
 * '<S283>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum'
 * '<S284>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum Fdbk'
 * '<S285>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode'
 * '<S286>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode Sum'
 * '<S287>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Integral'
 * '<S288>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Ngain'
 * '<S289>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/postSat Signal'
 * '<S290>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/preInt Signal'
 * '<S291>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/preSat Signal'
 * '<S292>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Anti-windup/Passthrough'
 * '<S293>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/D Gain/Disabled'
 * '<S294>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/External Derivative/Disabled'
 * '<S295>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter/Disabled'
 * '<S296>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter ICs/Disabled'
 * '<S297>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/I Gain/Internal Parameters'
 * '<S298>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain/Passthrough'
 * '<S299>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S300>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator/Discrete'
 * '<S301>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator ICs/Internal IC'
 * '<S302>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S303>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Gain/Disabled'
 * '<S304>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/P Copy/Disabled'
 * '<S305>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S306>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Reset Signal/External Reset'
 * '<S307>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation/Passthrough'
 * '<S308>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation Fdbk/Disabled'
 * '<S309>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum/Sum_PI'
 * '<S310>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum Fdbk/Disabled'
 * '<S311>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode/Disabled'
 * '<S312>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S313>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S314>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S315>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/postSat Signal/Forward_Path'
 * '<S316>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/preInt Signal/Internal PreInt'
 * '<S317>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/preSat Signal/Forward_Path'
 * '<S318>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/GainSystem'
 * '<S319>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter'
 * '<S320>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/InpFilterFunc'
 * '<S321>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod'
 * '<S322>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/Nofunc'
 * '<S323>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/NofuncSpd'
 * '<S324>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod'
 * '<S325>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/SpdFilterFunc'
 * '<S326>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/GainSystem/IGains'
 * '<S327>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/GainSystem/ODGains'
 * '<S328>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/GainSystem/OutDTSetup'
 * '<S329>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter/IIR Filter'
 * '<S330>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter/IIR Filter/Low-pass'
 * '<S331>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S332>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1'
 * '<S333>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3'
 * '<S334>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/Integrator'
 * '<S335>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/Integrator2'
 * '<S336>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter'
 * '<S337>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S338>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S339>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter'
 * '<S340>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S341>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S342>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/Differentiator'
 * '<S343>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/Differentiator1'
 * '<S344>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1'
 * '<S345>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3'
 * '<S346>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter'
 * '<S347>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S348>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S349>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter'
 * '<S350>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S351>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S352>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Subsystem/If Action Subsystem'
 * '<S353>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Subsystem/If Action Subsystem1'
 * '<S354>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem'
 * '<S355>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased'
 * '<S356>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Position Generator'
 * '<S357>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup'
 * '<S358>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S359>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S360>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S361>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S362>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S363>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S364>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S365>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype backpropogation'
 * '<S366>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation'
 * '<S367>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Subsystem2'
 * '<S368>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model'
 * '<S369>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel'
 * '<S370>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Average-Value Inverter'
 * '<S371>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model'
 * '<S372>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM'
 * '<S373>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous'
 * '<S374>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core'
 * '<S375>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Mechanical and Angle'
 * '<S376>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1'
 * '<S377>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic'
 * '<S378>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/MechToElect'
 * '<S379>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/Power Accounting Bus Creator'
 * '<S380>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/Power Accounting Bus Creator/PwrNotTrnsfrd Input'
 * '<S381>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/Power Accounting Bus Creator/PwrStored Input'
 * '<S382>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/Power Accounting Bus Creator/PwrTrnsfrd Input'
 * '<S383>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Clarke Transform'
 * '<S384>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Inverse Clarke Transform'
 * '<S385>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Inverse Park Transform'
 * '<S386>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Machine Torque'
 * '<S387>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit'
 * '<S388>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Park Transform'
 * '<S389>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Machine Torque/Subsystem'
 * '<S390>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage'
 * '<S391>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage'
 * '<S392>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem'
 * '<S393>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem1'
 * '<S394>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem2'
 * '<S395>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem'
 * '<S396>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem1'
 * '<S397>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem2'
 * '<S398>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem3'
 * '<S399>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/PS-Simulink Converter1'
 * '<S400>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter1'
 * '<S401>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter2'
 * '<S402>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter3'
 * '<S403>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter4'
 * '<S404>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter5'
 * '<S405>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter6'
 * '<S406>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter7'
 * '<S407>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration'
 * '<S408>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/PS-Simulink Converter1/EVAL_KEY'
 * '<S409>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter1/EVAL_KEY'
 * '<S410>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter2/EVAL_KEY'
 * '<S411>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter3/EVAL_KEY'
 * '<S412>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter4/EVAL_KEY'
 * '<S413>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter5/EVAL_KEY'
 * '<S414>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter6/EVAL_KEY'
 * '<S415>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Simulink-PS Converter7/EVAL_KEY'
 * '<S416>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Simulation/Simscape_Plantmodel/Solver Configuration/EVAL_KEY'
 * '<S417>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Subsystem2/Subsystem'
 * '<S418>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Inverter/Subsystem2/Subsystem/Gate_Inverter1'
 * '<S419>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control'
 * '<S420>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller'
 * '<S421>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Anti-windup'
 * '<S422>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/D Gain'
 * '<S423>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/External Derivative'
 * '<S424>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Filter'
 * '<S425>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Filter ICs'
 * '<S426>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/I Gain'
 * '<S427>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Ideal P Gain'
 * '<S428>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Ideal P Gain Fdbk'
 * '<S429>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Integrator'
 * '<S430>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Integrator ICs'
 * '<S431>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/N Copy'
 * '<S432>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/N Gain'
 * '<S433>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/P Copy'
 * '<S434>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Parallel P Gain'
 * '<S435>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Reset Signal'
 * '<S436>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Saturation'
 * '<S437>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Saturation Fdbk'
 * '<S438>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Sum'
 * '<S439>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Sum Fdbk'
 * '<S440>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Tracking Mode'
 * '<S441>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Tracking Mode Sum'
 * '<S442>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Tsamp - Integral'
 * '<S443>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Tsamp - Ngain'
 * '<S444>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/postSat Signal'
 * '<S445>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/preInt Signal'
 * '<S446>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/preSat Signal'
 * '<S447>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Anti-windup/Passthrough'
 * '<S448>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/D Gain/Disabled'
 * '<S449>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/External Derivative/Disabled'
 * '<S450>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Filter/Disabled'
 * '<S451>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Filter ICs/Disabled'
 * '<S452>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/I Gain/Internal Parameters'
 * '<S453>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Ideal P Gain/Passthrough'
 * '<S454>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S455>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Integrator/Continuous'
 * '<S456>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Integrator ICs/Internal IC'
 * '<S457>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S458>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/N Gain/Disabled'
 * '<S459>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/P Copy/Disabled'
 * '<S460>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S461>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Reset Signal/Disabled'
 * '<S462>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Saturation/Passthrough'
 * '<S463>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Saturation Fdbk/Disabled'
 * '<S464>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Sum/Sum_PI'
 * '<S465>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Sum Fdbk/Disabled'
 * '<S466>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Tracking Mode/Disabled'
 * '<S467>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S468>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S469>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S470>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/postSat Signal/Forward_Path'
 * '<S471>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/preInt Signal/Internal PreInt'
 * '<S472>' : 'PMSM_to_BLDC_mod1/Subsystem/FOC/Speed_controls/Speed Control/PID Controller/preSat Signal/Forward_Path'
 * '<S473>' : 'PMSM_to_BLDC_mod1/Subsystem/PWM Output/ECSoC'
 * '<S474>' : 'PMSM_to_BLDC_mod1/Subsystem/PWM Output/ECSoC/ECSimCodegen'
 */
#endif                                 /* PMSM_to_BLDC_mod1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
