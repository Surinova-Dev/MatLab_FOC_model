/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.h
 *
 * Code generated for Simulink model 'PMSM_to_BLDC_mod1'.
 *
 * Model version                  : 4.972
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Sat May 23 16:23:15 2026
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

/* Block signals for system '<S21>/SPI Receive' */
typedef struct {
  uint16_T SPIReceive;                 /* '<S21>/SPI Receive' */
} B_SPIReceive_PMSM_to_BLDC_mod_T;

/* Block states (default storage) for system '<S21>/SPI Receive' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S21>/SPI Receive' */
  boolean_T objisempty;                /* '<S21>/SPI Receive' */
} DW_SPIReceive_PMSM_to_BLDC_mo_T;

/* Block states (default storage) for system '<S34>/SPI Receive' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S34>/SPI Receive' */
  boolean_T objisempty;                /* '<S34>/SPI Receive' */
} DW_SPIReceive_PMSM_to_BLDC__f_T;

/* Block states (default storage) for system '<S34>/SPI Transmit' */
typedef struct {
  stm32cube_blocks_SPIControl_d_T obj; /* '<S34>/SPI Transmit' */
  boolean_T objisempty;                /* '<S34>/SPI Transmit' */
} DW_SPITransmit_PMSM_to_BLDC_m_T;

/* Block states (default storage) for system '<S46>/SPI Receive' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S46>/SPI Receive' */
  boolean_T objisempty;                /* '<S46>/SPI Receive' */
} DW_SPIReceive_PMSM_to_BLDC_fw_T;

/* Block states (default storage) for system '<S46>/SPI Transmit' */
typedef struct {
  stm32cube_blocks_SPIControl_d_T obj; /* '<S46>/SPI Transmit' */
  boolean_T objisempty;                /* '<S46>/SPI Transmit' */
} DW_SPITransmit_PMSM_to_BLDC_f_T;

/* Block signals (default storage) */
typedef struct {
  real_T Merge[2];                     /* '<S259>/Merge' */
  real_T Sum;                          /* '<S256>/Sum' */
  real_T Integrator;                   /* '<S301>/Integrator' */
  real_T ProportionalGain;             /* '<S442>/Proportional Gain' */
  real_T Add;                          /* '<S385>/Add' */
  real_T Add1;                         /* '<S385>/Add1' */
  real_T Add_h;                        /* '<S392>/Add' */
  real_T Add_d;                        /* '<S393>/Add' */
  real_T VectorConcatenate[3];         /* '<S376>/Vector Concatenate' */
  real_T IntegralGain;                 /* '<S434>/Integral Gain' */
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
  int16_T Switch;                      /* '<S252>/Switch' */
  boolean_T Compare;                   /* '<S264>/Compare' */
  B_SPIReceive_PMSM_to_BLDC_mod_T SPIReceive_pnae;/* '<S21>/SPI Receive' */
  B_SPIReceive_PMSM_to_BLDC_mod_T SPIReceive_pn;/* '<S21>/SPI Receive' */
  B_SPIReceive_PMSM_to_BLDC_mod_T SPIReceive_j;/* '<S21>/SPI Receive' */
} B_PMSM_to_BLDC_mod1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S20>/SPI Receive' */
  stm32cube_blocks_SPIControl_d_T obj_n;/* '<S21>/SPI Transmit' */
  stm32cube_blocks_SPIControl_d_T obj_j;/* '<S20>/SPI Transmit' */
  stm32cube_blocks_AnalogInput__T obj_p;
                                      /* '<S459>/Analog to Digital Converter' */
  stm32cube_blocks_AnalogInput__T obj_o;/* '<S16>/Analog to Digital Converter' */
  stm32cube_blocks_AnalogInput__T obj_d;/* '<S13>/Analog to Digital Converter' */
  stm32cube_blocks_DigitalPortW_T obj_ow;/* '<S19>/Digital Port Write' */
  stm32cube_blocks_PWMOutput_PM_T obj_e;/* '<S456>/PWM Output' */
  real_T Delay_DSTATE[3];              /* '<S56>/Delay' */
  real_T Delay_DSTATE_m[8];            /* '<S59>/Delay' */
  real_T Delay_DSTATE_c[2];            /* '<S236>/Delay' */
  real_T Delay_DSTATE_k[2];            /* '<S249>/Delay' */
  real_T Delay_DSTATE_a;               /* '<S332>/Delay' */
  real_T Delay_DSTATE_aj;              /* '<S356>/Delay' */
  real_T Integrator_DSTATE;            /* '<S301>/Integrator' */
  real_T Delay_DSTATE_ai;              /* '<S357>/Delay' */
  real_T Integrator_DSTATE_n;          /* '<S116>/Integrator' */
  real_T Integrator_DSTATE_b;          /* '<S171>/Integrator' */
  real_T Delay_DSTATE_g;               /* '<S263>/Delay' */
  real_T Delay_DSTATE_aa;              /* '<S349>/Delay' */
  real_T Delay2_DSTATE;                /* '<S344>/Delay2' */
  real_T Delay3_DSTATE;                /* '<S344>/Delay3' */
  real_T Delay2_DSTATE_h;              /* '<S343>/Delay2' */
  real_T Delay3_DSTATE_p;              /* '<S343>/Delay3' */
  real_T Delay_DSTATE_l;               /* '<S352>/Delay' */
  real_T Delay_DSTATE_av;              /* '<S339>/Delay' */
  real_T Delay1_DSTATE;                /* '<S336>/Delay1' */
  real_T Delay_DSTATE_f;               /* '<S336>/Delay' */
  real_T Delay_DSTATE_d;               /* '<S342>/Delay' */
  real_T Delay1_DSTATE_o;              /* '<S335>/Delay1' */
  real_T Delay_DSTATE_i;               /* '<S335>/Delay' */
  real_T CS_val;                       /* '<Root>/Chart' */
  real_T Drv_ok;                       /* '<Root>/Chart' */
  real32_T Delay1_DSTATE_f;            /* '<S232>/Delay1' */
  real32_T Delay1_DSTATE_fx;           /* '<S56>/Delay1' */
  uint16_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint16_T temporalCounter_i2;         /* '<Root>/Chart' */
  int8_T If_ActiveSubsystem;           /* '<S250>/If' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S259>/Switch Case' */
  int8_T If_ActiveSubsystem_g;         /* '<S256>/If' */
  int8_T SwitchCase_ActiveSubsystem_n; /* '<S258>/Switch Case' */
  int8_T If_ActiveSubsystem_e;         /* '<S361>/If' */
  int8_T Integrator_PrevResetState;    /* '<S301>/Integrator' */
  int8_T If_ActiveSubsystem_c;         /* '<S222>/If' */
  int8_T Integrator_PrevResetState_n;  /* '<S116>/Integrator' */
  int8_T Integrator_PrevResetState_nt; /* '<S171>/Integrator' */
  int8_T If_ActiveSubsystem_m;         /* '<S196>/If' */
  uint8_T is_active_c3_PMSM_to_BLDC_mod1;/* '<Root>/Chart' */
  uint8_T is_Test2;                    /* '<Root>/Chart' */
  uint8_T is_Test;                     /* '<Root>/Chart' */
  boolean_T icLoad;                    /* '<S249>/Delay' */
  boolean_T AlphaRelay_Mode;           /* '<S250>/AlphaRelay' */
  boolean_T BetaRelay_Mode;            /* '<S250>/BetaRelay' */
  boolean_T icLoad_f;                  /* '<S332>/Delay' */
  boolean_T icLoad_a;                  /* '<S357>/Delay' */
  boolean_T icLoad_b;                  /* '<S263>/Delay' */
  boolean_T Integrator_DWORK1;         /* '<S392>/Integrator' */
  boolean_T Integrator_DWORK1_g;       /* '<S393>/Integrator' */
  boolean_T icLoad_b1;                 /* '<S349>/Delay' */
  boolean_T icLoad_c;                  /* '<S352>/Delay' */
  boolean_T icLoad_bd;                 /* '<S339>/Delay' */
  boolean_T icLoad_k;                  /* '<S342>/Delay' */
  boolean_T Status_Reg_2_read_MODE;    /* '<S6>/Status_Reg_2_read' */
  boolean_T Status_Reg1_read_MODE;     /* '<S6>/Status_Reg1_read' */
  boolean_T Subsystem1_MODE;           /* '<S33>/Subsystem1' */
  boolean_T Subsystem1_MODE_g;         /* '<S32>/Subsystem1' */
  boolean_T Subsystem1_MODE_f;         /* '<S2>/Subsystem1' */
  boolean_T Subsystem_MODE_h;          /* '<S2>/Subsystem' */
  DW_SPITransmit_PMSM_to_BLDC_f_T SPITransmit_pnaevv;/* '<S46>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC_fw_T SPIReceive_pnaevv;/* '<S46>/SPI Receive' */
  DW_SPITransmit_PMSM_to_BLDC_f_T SPITransmit_pnaev;/* '<S46>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC_fw_T SPIReceive_pnaev;/* '<S46>/SPI Receive' */
  DW_SPITransmit_PMSM_to_BLDC_m_T SPITransmit_pnae;/* '<S34>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC_mo_T SPIReceive_pnae;/* '<S21>/SPI Receive' */
  DW_SPITransmit_PMSM_to_BLDC_m_T SPITransmit_pna;/* '<S34>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC__f_T SPIReceive_pna;/* '<S34>/SPI Receive' */
  DW_SPITransmit_PMSM_to_BLDC_m_T SPITransmit_pn;/* '<S34>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC_mo_T SPIReceive_pn;/* '<S21>/SPI Receive' */
  DW_SPITransmit_PMSM_to_BLDC_m_T SPITransmit_p;/* '<S34>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC__f_T SPIReceive_p;/* '<S34>/SPI Receive' */
  DW_SPIReceive_PMSM_to_BLDC_mo_T SPIReceive_j;/* '<S21>/SPI Receive' */
} DW_PMSM_to_BLDC_mod1_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S437>/Integrator' */
  real_T Integrator_CSTATE_d;          /* '<S392>/Integrator' */
  real_T Int1_CSTATE;                  /* '<S377>/Int1' */
  real_T Integrator_CSTATE_l;          /* '<S393>/Integrator' */
} X_PMSM_to_BLDC_mod1_T;

/* Periodic continuous state vector (global) */
typedef int_T PeriodicIndX_PMSM_to_BLDC_mod_T[1];
typedef real_T PeriodicRngX_PMSM_to_BLDC_mod_T[2];

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S437>/Integrator' */
  real_T Integrator_CSTATE_d;          /* '<S392>/Integrator' */
  real_T Int1_CSTATE;                  /* '<S377>/Int1' */
  real_T Integrator_CSTATE_l;          /* '<S393>/Integrator' */
} XDot_PMSM_to_BLDC_mod1_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S437>/Integrator' */
  boolean_T Integrator_CSTATE_d;       /* '<S392>/Integrator' */
  boolean_T Int1_CSTATE;               /* '<S377>/Int1' */
  boolean_T Integrator_CSTATE_l;       /* '<S393>/Integrator' */
} XDis_PMSM_to_BLDC_mod1_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Delay1_Reset_ZCE;         /* '<S232>/Delay1' */
  ZCSigState Delay_Reset_ZCE;          /* '<S236>/Delay' */
  ZCSigState Delay_Reset_ZCE_a;        /* '<S356>/Delay' */
  ZCSigState Delay2_Reset_ZCE;         /* '<S344>/Delay2' */
  ZCSigState Delay3_Reset_ZCE;         /* '<S344>/Delay3' */
  ZCSigState Delay2_Reset_ZCE_p;       /* '<S343>/Delay2' */
  ZCSigState Delay3_Reset_ZCE_k;       /* '<S343>/Delay3' */
  ZCSigState Delay1_Reset_ZCE_p;       /* '<S336>/Delay1' */
  ZCSigState Delay_Reset_ZCE_h;        /* '<S336>/Delay' */
  ZCSigState Delay1_Reset_ZCE_i;       /* '<S335>/Delay1' */
  ZCSigState Delay_Reset_ZCE_k;        /* '<S335>/Delay' */
  ZCSigState Dir_Sense_Trig_ZCE;       /* '<S250>/Dir_Sense' */
} PrevZCX_PMSM_to_BLDC_mod1_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Constant3;              /* '<S77>/Constant3' */
  const real_T Constant3_n;            /* '<S78>/Constant3' */
  const real_T Switch;                 /* '<S372>/Switch' */
  const real_T Gain;                   /* '<S377>/Gain' */
  const real_T IndexVector;            /* '<S392>/Index Vector' */
  const real_T IndexVector_b;          /* '<S394>/Index Vector' */
  const real_T IndexVector_a;          /* '<S395>/Index Vector' */
  const real_T IndexVector1;           /* '<S395>/Index Vector1' */
  const real_T IndexVector_j;          /* '<S396>/Index Vector' */
  const real_T IndexVector_d;          /* '<S393>/Index Vector' */
  const real_T IndexVector_k;          /* '<S397>/Index Vector' */
  const real_T IndexVector_m;          /* '<S398>/Index Vector' */
  const real_T IndexVector1_g;         /* '<S398>/Index Vector1' */
  const real_T IndexVector_bt;         /* '<S399>/Index Vector' */
  const real_T Product;                /* '<S399>/Product' */
  const real_T IndexVector_d3;         /* '<S400>/Index Vector' */
  const uint32_T DataTypeConversion;   /* '<S259>/Data Type Conversion' */
  const uint16_T DataTypeConversion1;  /* '<S7>/Data Type Conversion1' */
  const uint16_T BitwiseAND;           /* '<S47>/Bitwise AND' */
  const uint16_T BitwiseAND_m;         /* '<S46>/Bitwise AND' */
  const uint16_T BitwiseAND_j;         /* '<S40>/Bitwise AND' */
  const uint16_T BitwiseAND_d;         /* '<S34>/Bitwise AND' */
  const uint16_T BitwiseAND_e;         /* '<S21>/Bitwise AND' */
  const uint16_T BitwiseAND_jx;        /* '<S20>/Bitwise AND' */
  const boolean_T DataTypeConversion_j;/* '<S7>/Data Type Conversion' */
} ConstB_PMSM_to_BLDC_mod1_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: dlgSett.sin_table)
   * Referenced by:
   *   '<S194>/sine_table_values'
   *   '<S220>/sine_table_values'
   */
  real_T pooled16[1002];

  /* Computed Parameter: sine_table_values_Value
   * Referenced by: '<S359>/sine_table_values'
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
  real_T odeY[4];
  real_T odeF[3][4];
  ODE3_IntgData intgData;

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
    struct {
      uint16_T TID[6];
    } TaskCounters;

    time_T tStart;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[6];
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
 * Block '<S9>/Data Type Conversion' : Unused code path elimination
 * Block '<S9>/Display1' : Unused code path elimination
 * Block '<S9>/Gain' : Unused code path elimination
 * Block '<S10>/Data Type Conversion1' : Unused code path elimination
 * Block '<S10>/Display2' : Unused code path elimination
 * Block '<S10>/Gain1' : Unused code path elimination
 * Block '<S20>/Display' : Unused code path elimination
 * Block '<S21>/Display' : Unused code path elimination
 * Block '<S4>/Scope' : Unused code path elimination
 * Block '<S34>/Display' : Unused code path elimination
 * Block '<S40>/Display' : Unused code path elimination
 * Block '<S5>/Scope' : Unused code path elimination
 * Block '<S5>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<S6>/Scope' : Unused code path elimination
 * Block '<S6>/Scope1' : Unused code path elimination
 * Block '<S46>/Display' : Unused code path elimination
 * Block '<S46>/Display1' : Unused code path elimination
 * Block '<S47>/Display' : Unused code path elimination
 * Block '<S56>/Constant1' : Unused code path elimination
 * Block '<S66>/B' : Unused code path elimination
 * Block '<S76>/Data Type Duplicate' : Unused code path elimination
 * Block '<S63>/Display3' : Unused code path elimination
 * Block '<S68>/C' : Unused code path elimination
 * Block '<S68>/D' : Unused code path elimination
 * Block '<S194>/Data Type Duplicate' : Unused code path elimination
 * Block '<S194>/Data Type Propagation' : Unused code path elimination
 * Block '<S199>/Data Type Duplicate' : Unused code path elimination
 * Block '<S200>/Data Type Duplicate' : Unused code path elimination
 * Block '<S202>/Data Type Duplicate' : Unused code path elimination
 * Block '<S202>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S69>/Data Type Duplicate' : Unused code path elimination
 * Block '<S69>/Vc' : Unused code path elimination
 * Block '<S213>/Data Type Duplicate' : Unused code path elimination
 * Block '<S70>/C' : Unused code path elimination
 * Block '<S70>/D' : Unused code path elimination
 * Block '<S220>/Data Type Duplicate' : Unused code path elimination
 * Block '<S220>/Data Type Propagation' : Unused code path elimination
 * Block '<S225>/Data Type Duplicate' : Unused code path elimination
 * Block '<S226>/Data Type Duplicate' : Unused code path elimination
 * Block '<S228>/Data Type Duplicate' : Unused code path elimination
 * Block '<S228>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S71>/Display' : Unused code path elimination
 * Block '<S71>/Scope' : Unused code path elimination
 * Block '<S63>/Scope' : Unused code path elimination
 * Block '<S59>/Display1' : Unused code path elimination
 * Block '<S59>/Display2' : Unused code path elimination
 * Block '<S59>/Scope' : Unused code path elimination
 * Block '<S59>/Scope1' : Unused code path elimination
 * Block '<S232>/Data Type Propagation' : Unused code path elimination
 * Block '<S236>/Data Type Duplicate' : Unused code path elimination
 * Block '<S236>/Data Type Propagation' : Unused code path elimination
 * Block '<S239>/Data Type Duplicate' : Unused code path elimination
 * Block '<S239>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S239>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S239>/Data Type Propagation' : Unused code path elimination
 * Block '<S239>/Data Type Propagation1' : Unused code path elimination
 * Block '<S239>/Data Type Propagation2' : Unused code path elimination
 * Block '<S239>/Data Type Propagation3' : Unused code path elimination
 * Block '<S240>/Data Type Duplicate' : Unused code path elimination
 * Block '<S240>/Data Type Propagation' : Unused code path elimination
 * Block '<S241>/Data Type Duplicate' : Unused code path elimination
 * Block '<S241>/Data Type Propagation' : Unused code path elimination
 * Block '<S237>/Data Type Propagation' : Unused code path elimination
 * Block '<S242>/Data Type Duplicate' : Unused code path elimination
 * Block '<S242>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S242>/Data Type Propagation' : Unused code path elimination
 * Block '<S243>/Data Type Duplicate' : Unused code path elimination
 * Block '<S243>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S243>/Data Type Propagation' : Unused code path elimination
 * Block '<S244>/Data Type Duplicate' : Unused code path elimination
 * Block '<S244>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S244>/Data Type Propagation' : Unused code path elimination
 * Block '<S245>/Data Type Duplicate' : Unused code path elimination
 * Block '<S245>/Data Type Propagation' : Unused code path elimination
 * Block '<S238>/Data Type Propagation' : Unused code path elimination
 * Block '<S246>/Data Type Duplicate' : Unused code path elimination
 * Block '<S246>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S246>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S246>/Data Type Propagation' : Unused code path elimination
 * Block '<S246>/Data Type Propagation1' : Unused code path elimination
 * Block '<S234>/Data Type Duplicate' : Unused code path elimination
 * Block '<S251>/Data Type Duplicate' : Unused code path elimination
 * Block '<S251>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S251>/Data Type Conversion' : Unused code path elimination
 * Block '<S251>/Data Type Conversion1' : Unused code path elimination
 * Block '<S255>/Data Type Duplicate' : Unused code path elimination
 * Block '<S256>/Data Type Duplicate' : Unused code path elimination
 * Block '<S256>/Data Type Propagation' : Unused code path elimination
 * Block '<S265>/Data Type Duplicate' : Unused code path elimination
 * Block '<S266>/Data Type Duplicate' : Unused code path elimination
 * Block '<S266>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S266>/Data Type Propagation' : Unused code path elimination
 * Block '<S258>/Data Type Duplicate' : Unused code path elimination
 * Block '<S258>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S319>/I1CnstDT' : Unused code path elimination
 * Block '<S319>/I2CnstDT' : Unused code path elimination
 * Block '<S327>/Bias' : Unused code path elimination
 * Block '<S327>/Bias1' : Unused code path elimination
 * Block '<S327>/Constant' : Unused code path elimination
 * Block '<S327>/Data Type Duplicate' : Unused code path elimination
 * Block '<S327>/Data Type Propagation' : Unused code path elimination
 * Block '<S327>/Data Type Propagation1' : Unused code path elimination
 * Block '<S327>/Divide' : Unused code path elimination
 * Block '<S327>/Divide1' : Unused code path elimination
 * Block '<S327>/OD1Cnst' : Unused code path elimination
 * Block '<S327>/OD1CnstDT' : Unused code path elimination
 * Block '<S327>/Product' : Unused code path elimination
 * Block '<S327>/Unary Minus' : Unused code path elimination
 * Block '<S319>/MaxFreqCnst' : Unused code path elimination
 * Block '<S319>/OD1CnstDT' : Unused code path elimination
 * Block '<S319>/OD2CnstDT' : Unused code path elimination
 * Block '<S328>/Bias' : Unused code path elimination
 * Block '<S328>/Constant' : Unused code path elimination
 * Block '<S328>/Data Type Duplicate' : Unused code path elimination
 * Block '<S328>/Data Type Propagation' : Unused code path elimination
 * Block '<S328>/Data Type Propagation1' : Unused code path elimination
 * Block '<S328>/Data Type Propagation2' : Unused code path elimination
 * Block '<S328>/Divide' : Unused code path elimination
 * Block '<S328>/OD1Cnst' : Unused code path elimination
 * Block '<S328>/OD1CnstDT' : Unused code path elimination
 * Block '<S328>/OD1CnstDT1' : Unused code path elimination
 * Block '<S328>/Product' : Unused code path elimination
 * Block '<S328>/Product1' : Unused code path elimination
 * Block '<S328>/SampleTime' : Unused code path elimination
 * Block '<S329>/Const' : Unused code path elimination
 * Block '<S329>/Data Type Propagation' : Unused code path elimination
 * Block '<S329>/Data Type Propagation1' : Unused code path elimination
 * Block '<S329>/MaxFreqDT' : Unused code path elimination
 * Block '<S329>/Product' : Unused code path elimination
 * Block '<S320>/Data Type Duplicate' : Unused code path elimination
 * Block '<S321>/Bias' : Unused code path elimination
 * Block '<S321>/Constant' : Unused code path elimination
 * Block '<S321>/Data Type Propagation' : Unused code path elimination
 * Block '<S321>/Data Type Propagation1' : Unused code path elimination
 * Block '<S321>/Divide' : Unused code path elimination
 * Block '<S321>/Product' : Unused code path elimination
 * Block '<S322>/Data Type Duplicate' : Unused code path elimination
 * Block '<S322>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S322>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S333>/Data Type Duplicate' : Unused code path elimination
 * Block '<S334>/Data Type Duplicate' : Unused code path elimination
 * Block '<S335>/Data Type Duplicate' : Unused code path elimination
 * Block '<S335>/Data Type Propagation' : Unused code path elimination
 * Block '<S335>/Data Type Propagation1' : Unused code path elimination
 * Block '<S336>/Data Type Duplicate' : Unused code path elimination
 * Block '<S336>/Data Type Propagation' : Unused code path elimination
 * Block '<S336>/Data Type Propagation1' : Unused code path elimination
 * Block '<S325>/Data Type Duplicate' : Unused code path elimination
 * Block '<S343>/Data Type Duplicate' : Unused code path elimination
 * Block '<S343>/Data Type Propagation' : Unused code path elimination
 * Block '<S344>/Data Type Duplicate' : Unused code path elimination
 * Block '<S344>/Data Type Propagation' : Unused code path elimination
 * Block '<S345>/Data Type Duplicate' : Unused code path elimination
 * Block '<S346>/Data Type Duplicate' : Unused code path elimination
 * Block '<S326>/Bias' : Unused code path elimination
 * Block '<S326>/Constant' : Unused code path elimination
 * Block '<S326>/Data Type Propagation' : Unused code path elimination
 * Block '<S326>/Data Type Propagation1' : Unused code path elimination
 * Block '<S326>/Divide' : Unused code path elimination
 * Block '<S326>/Product' : Unused code path elimination
 * Block '<S259>/Data Type Duplicate' : Unused code path elimination
 * Block '<S356>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S356>/Data Type Propagation' : Unused code path elimination
 * Block '<S357>/BooleanTypeCast' : Unused code path elimination
 * Block '<S357>/Data Type Duplicate' : Unused code path elimination
 * Block '<S357>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S357>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S357>/Data Type Duplicate3' : Unused code path elimination
 * Block '<S357>/Data Type Propagation' : Unused code path elimination
 * Block '<S357>/InpGainDatatype' : Unused code path elimination
 * Block '<S357>/OutGainDatatype' : Unused code path elimination
 * Block '<S357>/Reset' : Unused code path elimination
 * Block '<S359>/Data Type Duplicate' : Unused code path elimination
 * Block '<S359>/Data Type Propagation' : Unused code path elimination
 * Block '<S364>/Data Type Duplicate' : Unused code path elimination
 * Block '<S365>/Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/Display' : Unused code path elimination
 * Block '<S56>/Display3' : Unused code path elimination
 * Block '<S56>/Display4' : Unused code path elimination
 * Block '<S56>/Gain2' : Unused code path elimination
 * Block '<S56>/Gain3' : Unused code path elimination
 * Block '<S367>/Scope' : Unused code path elimination
 * Block '<S369>/Gain1' : Unused code path elimination
 * Block '<S370>/Add' : Unused code path elimination
 * Block '<S370>/Constant1' : Unused code path elimination
 * Block '<S370>/Gain5' : Unused code path elimination
 * Block '<S371>/Display' : Unused code path elimination
 * Block '<S371>/Display1' : Unused code path elimination
 * Block '<S371>/Gain' : Unused code path elimination
 * Block '<S371>/Gain1' : Unused code path elimination
 * Block '<S373>/Display' : Unused code path elimination
 * Block '<S373>/Gain' : Unused code path elimination
 * Block '<S373>/Gain1' : Unused code path elimination
 * Block '<S373>/Scope' : Unused code path elimination
 * Block '<S377>/Constant' : Unused code path elimination
 * Block '<S378>/Add' : Unused code path elimination
 * Block '<S378>/Add2' : Unused code path elimination
 * Block '<S378>/Add4' : Unused code path elimination
 * Block '<S378>/Constant' : Unused code path elimination
 * Block '<S378>/Gain' : Unused code path elimination
 * Block '<S378>/Gain1' : Unused code path elimination
 * Block '<S378>/Gain2' : Unused code path elimination
 * Block '<S380>/Constant' : Unused code path elimination
 * Block '<S380>/Mod' : Unused code path elimination
 * Block '<S380>/polepair' : Unused code path elimination
 * Block '<S378>/Product' : Unused code path elimination
 * Block '<S378>/Product1' : Unused code path elimination
 * Block '<S378>/Product11' : Unused code path elimination
 * Block '<S378>/Product12' : Unused code path elimination
 * Block '<S378>/Product2' : Unused code path elimination
 * Block '<S378>/Product3' : Unused code path elimination
 * Block '<S378>/Product4' : Unused code path elimination
 * Block '<S388>/Add' : Unused code path elimination
 * Block '<S388>/Gain1' : Unused code path elimination
 * Block '<S388>/Gain2' : Unused code path elimination
 * Block '<S388>/Product' : Unused code path elimination
 * Block '<S391>/Add' : Unused code path elimination
 * Block '<S391>/Constant' : Unused code path elimination
 * Block '<S391>/Constant1' : Unused code path elimination
 * Block '<S391>/Constant2' : Unused code path elimination
 * Block '<S391>/Index Vector' : Unused code path elimination
 * Block '<S391>/Index Vector1' : Unused code path elimination
 * Block '<S391>/Product' : Unused code path elimination
 * Block '<S371>/Scope' : Unused code path elimination
 * Block '<S368>/Scope' : Unused code path elimination
 * Block '<S56>/Scope' : Unused code path elimination
 * Block '<S61>/Display' : Unused code path elimination
 * Block '<S61>/Scope' : Unused code path elimination
 * Block '<S56>/Time Scope1' : Unused code path elimination
 * Block '<S56>/Time Scope2' : Unused code path elimination
 * Block '<S58>/CCR' : Unused code path elimination
 * Block '<S58>/Constant' : Unused code path elimination
 * Block '<S58>/Data Type Conversion' : Unused code path elimination
 * Block '<S58>/Data Type Conversion1' : Unused code path elimination
 * Block '<S58>/Data Type Conversion2' : Unused code path elimination
 * Block '<S58>/Data Type Conversion3' : Unused code path elimination
 * Block '<S58>/Data Type Conversion4' : Unused code path elimination
 * Block '<S58>/Data Type Conversion5' : Unused code path elimination
 * Block '<S8>/Data Type Conversion' : Unused code path elimination
 * Block '<S8>/Display' : Unused code path elimination
 * Block '<S8>/Gain' : Unused code path elimination
 * Block '<S8>/Scope' : Unused code path elimination
 * Block '<S20>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S21>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S46>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S76>/Kalphabeta0' : Eliminated nontunable gain of 1
 * Block '<S194>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S213>/Ka' : Eliminated nontunable gain of 1
 * Block '<S213>/Kb' : Eliminated nontunable gain of 1
 * Block '<S213>/Kc' : Eliminated nontunable gain of 1
 * Block '<S220>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S71>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S72>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S72>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S59>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S230>/Data Type  Conversion' : Eliminate redundant data type conversion
 * Block '<S232>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S234>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S251>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S255>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S266>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S266>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S266>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S258>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S320>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S333>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S334>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S345>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S346>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S359>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S361>/convert_pu' : Eliminated nontunable gain of 1
 * Block '<S366>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S56>/Gain' : Eliminated nontunable gain of 1
 * Block '<S56>/Gain1' : Eliminated nontunable gain of 1
 * Block '<S371>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S203>/Offset' : Unused code path elimination
 * Block '<S203>/Unary_Minus' : Unused code path elimination
 * Block '<S229>/Offset' : Unused code path elimination
 * Block '<S229>/Unary_Minus' : Unused code path elimination
 * Block '<S234>/One' : Unused code path elimination
 * Block '<S234>/Reset' : Unused code path elimination
 * Block '<S234>/Sum' : Unused code path elimination
 * Block '<S234>/UseInputPort' : Unused code path elimination
 * Block '<S234>/a' : Unused code path elimination
 * Block '<S255>/One' : Unused code path elimination
 * Block '<S255>/Reset' : Unused code path elimination
 * Block '<S255>/Sum' : Unused code path elimination
 * Block '<S255>/UseInputPort' : Unused code path elimination
 * Block '<S255>/a' : Unused code path elimination
 * Block '<S320>/FilterConstant' : Unused code path elimination
 * Block '<S320>/OneMinusFilterConstant' : Unused code path elimination
 * Block '<S320>/Reset' : Unused code path elimination
 * Block '<S320>/UseInputPort' : Unused code path elimination
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
 * '<S7>'   : 'PMSM_to_BLDC_mod1/Timer'
 * '<S8>'   : 'PMSM_to_BLDC_mod1/V_sense'
 * '<S9>'   : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem'
 * '<S10>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem1'
 * '<S11>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem/Analog to Digital Converter1'
 * '<S12>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem/Analog to Digital Converter1/ECSoC'
 * '<S13>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem/Analog to Digital Converter1/ECSoC/ECSimCodegen'
 * '<S14>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem1/Analog to Digital Converter2'
 * '<S15>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem1/Analog to Digital Converter2/ECSoC'
 * '<S16>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem1/Analog to Digital Converter2/ECSoC/ECSimCodegen'
 * '<S17>'  : 'PMSM_to_BLDC_mod1/En_gate/Digital Port Write'
 * '<S18>'  : 'PMSM_to_BLDC_mod1/En_gate/Digital Port Write/ECSoC'
 * '<S19>'  : 'PMSM_to_BLDC_mod1/En_gate/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S20>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2'
 * '<S21>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1'
 * '<S22>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2/Bit Shift'
 * '<S23>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2/Bit Shift1'
 * '<S24>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2/Bit Shift/bit_shift'
 * '<S25>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2/Bit Shift1/bit_shift'
 * '<S26>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1/Bit Shift'
 * '<S27>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1/Bit Shift1'
 * '<S28>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1/Bit Shift/bit_shift'
 * '<S29>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1/Bit Shift1/bit_shift'
 * '<S30>'  : 'PMSM_to_BLDC_mod1/SPI_read/Compare To Constant'
 * '<S31>'  : 'PMSM_to_BLDC_mod1/SPI_read/Compare To Constant1'
 * '<S32>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read'
 * '<S33>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read'
 * '<S34>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem'
 * '<S35>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem1'
 * '<S36>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem/Bit Shift'
 * '<S37>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem/Bit Shift1'
 * '<S38>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem/Bit Shift/bit_shift'
 * '<S39>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem/Bit Shift1/bit_shift'
 * '<S40>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem'
 * '<S41>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem1'
 * '<S42>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem/Bit Shift'
 * '<S43>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem/Bit Shift1'
 * '<S44>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem/Bit Shift/bit_shift'
 * '<S45>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem/Bit Shift1/bit_shift'
 * '<S46>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read'
 * '<S47>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read'
 * '<S48>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read/Bit Shift'
 * '<S49>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read/Bit Shift1'
 * '<S50>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read/Bit Shift/bit_shift'
 * '<S51>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read/Bit Shift1/bit_shift'
 * '<S52>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read/Bit Shift'
 * '<S53>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read/Bit Shift1'
 * '<S54>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read/Bit Shift/bit_shift'
 * '<S55>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read/Bit Shift1/bit_shift'
 * '<S56>'  : 'PMSM_to_BLDC_mod1/Timer/FOC'
 * '<S57>'  : 'PMSM_to_BLDC_mod1/Timer/PWM Output'
 * '<S58>'  : 'PMSM_to_BLDC_mod1/Timer/Pulse to timer '
 * '<S59>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm '
 * '<S60>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter'
 * '<S61>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls'
 * '<S62>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Subsystem1'
 * '<S63>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform'
 * '<S64>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle'
 * '<S65>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Subsystem1'
 * '<S66>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Clarke Transform'
 * '<S67>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control'
 * '<S68>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1'
 * '<S69>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator'
 * '<S70>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform'
 * '<S71>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Position_Model'
 * '<S72>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/wrapping Mod'
 * '<S73>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Clarke Transform/Variant'
 * '<S74>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Clarke Transform/Variant/mcb'
 * '<S75>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Clarke Transform/Variant/mcb/Clarke Transform'
 * '<S76>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Clarke Transform/Variant/mcb/Clarke Transform/Three phase input'
 * '<S77>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq'
 * '<S78>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id'
 * '<S79>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID'
 * '<S80>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Anti-windup'
 * '<S81>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/D Gain'
 * '<S82>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/External Derivative'
 * '<S83>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Filter'
 * '<S84>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Filter ICs'
 * '<S85>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/I Gain'
 * '<S86>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Ideal P Gain'
 * '<S87>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Ideal P Gain Fdbk'
 * '<S88>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Integrator'
 * '<S89>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Integrator ICs'
 * '<S90>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/N Copy'
 * '<S91>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/N Gain'
 * '<S92>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/P Copy'
 * '<S93>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Parallel P Gain'
 * '<S94>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Reset Signal'
 * '<S95>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Saturation'
 * '<S96>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Saturation Fdbk'
 * '<S97>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Sum'
 * '<S98>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Sum Fdbk'
 * '<S99>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tracking Mode'
 * '<S100>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tracking Mode Sum'
 * '<S101>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tsamp - Integral'
 * '<S102>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tsamp - Ngain'
 * '<S103>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/postSat Signal'
 * '<S104>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/preInt Signal'
 * '<S105>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/preSat Signal'
 * '<S106>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel'
 * '<S107>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S108>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S109>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/D Gain/Disabled'
 * '<S110>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/External Derivative/Disabled'
 * '<S111>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Filter/Disabled'
 * '<S112>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Filter ICs/Disabled'
 * '<S113>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/I Gain/External Parameters'
 * '<S114>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Ideal P Gain/Passthrough'
 * '<S115>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Ideal P Gain Fdbk/Disabled'
 * '<S116>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Integrator/Discrete'
 * '<S117>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Integrator ICs/External IC'
 * '<S118>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/N Copy/Disabled wSignal Specification'
 * '<S119>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/N Gain/Disabled'
 * '<S120>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/P Copy/Disabled'
 * '<S121>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Parallel P Gain/External Parameters'
 * '<S122>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Reset Signal/External Reset'
 * '<S123>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Saturation/Enabled'
 * '<S124>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Saturation Fdbk/Disabled'
 * '<S125>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Sum/Sum_PI'
 * '<S126>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Sum Fdbk/Disabled'
 * '<S127>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tracking Mode/Disabled'
 * '<S128>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tracking Mode Sum/Passthrough'
 * '<S129>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tsamp - Integral/TsSignalSpecification'
 * '<S130>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tsamp - Ngain/Passthrough'
 * '<S131>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/postSat Signal/Forward_Path'
 * '<S132>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/preInt Signal/Internal PreInt'
 * '<S133>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/preSat Signal/Forward_Path'
 * '<S134>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID'
 * '<S135>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Anti-windup'
 * '<S136>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/D Gain'
 * '<S137>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/External Derivative'
 * '<S138>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Filter'
 * '<S139>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Filter ICs'
 * '<S140>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/I Gain'
 * '<S141>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Ideal P Gain'
 * '<S142>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Ideal P Gain Fdbk'
 * '<S143>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Integrator'
 * '<S144>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Integrator ICs'
 * '<S145>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/N Copy'
 * '<S146>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/N Gain'
 * '<S147>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/P Copy'
 * '<S148>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Parallel P Gain'
 * '<S149>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Reset Signal'
 * '<S150>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Saturation'
 * '<S151>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Saturation Fdbk'
 * '<S152>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Sum'
 * '<S153>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Sum Fdbk'
 * '<S154>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tracking Mode'
 * '<S155>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tracking Mode Sum'
 * '<S156>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tsamp - Integral'
 * '<S157>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tsamp - Ngain'
 * '<S158>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/postSat Signal'
 * '<S159>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/preInt Signal'
 * '<S160>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/preSat Signal'
 * '<S161>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel'
 * '<S162>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S163>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S164>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/D Gain/Disabled'
 * '<S165>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/External Derivative/Disabled'
 * '<S166>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Filter/Disabled'
 * '<S167>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Filter ICs/Disabled'
 * '<S168>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/I Gain/External Parameters'
 * '<S169>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Ideal P Gain/Passthrough'
 * '<S170>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Ideal P Gain Fdbk/Disabled'
 * '<S171>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Integrator/Discrete'
 * '<S172>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Integrator ICs/External IC'
 * '<S173>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/N Copy/Disabled wSignal Specification'
 * '<S174>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/N Gain/Disabled'
 * '<S175>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/P Copy/Disabled'
 * '<S176>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Parallel P Gain/External Parameters'
 * '<S177>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Reset Signal/External Reset'
 * '<S178>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Saturation/Enabled'
 * '<S179>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Saturation Fdbk/Disabled'
 * '<S180>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Sum/Sum_PI'
 * '<S181>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Sum Fdbk/Disabled'
 * '<S182>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tracking Mode/Disabled'
 * '<S183>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tracking Mode Sum/Passthrough'
 * '<S184>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tsamp - Integral/TsSignalSpecification'
 * '<S185>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tsamp - Ngain/Passthrough'
 * '<S186>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/postSat Signal/Forward_Path'
 * '<S187>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/preInt Signal/Internal PreInt'
 * '<S188>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/preSat Signal/Forward_Path'
 * '<S189>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant'
 * '<S190>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb'
 * '<S191>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform'
 * '<S192>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine'
 * '<S193>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Three inputs'
 * '<S194>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup'
 * '<S195>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/Interpolation'
 * '<S196>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp'
 * '<S197>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/datatype'
 * '<S198>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S199>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S200>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S201>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S202>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Three inputs/Two inputs CRL'
 * '<S203>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Three inputs/Two inputs CRL/Switch_Axis'
 * '<S204>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Modulation method'
 * '<S205>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input'
 * '<S206>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Modulation method/SVPWM'
 * '<S207>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S208>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input/Valphabeta'
 * '<S209>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S210>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Variant'
 * '<S211>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Variant/mcb'
 * '<S212>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Variant/mcb/Inverse Clarke Transform'
 * '<S213>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Variant/mcb/Inverse Clarke Transform/Two phase input'
 * '<S214>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant'
 * '<S215>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb'
 * '<S216>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform'
 * '<S217>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine'
 * '<S218>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Three inputs'
 * '<S219>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup'
 * '<S220>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S221>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S222>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S223>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S224>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S225>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S226>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S227>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S228>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Three inputs/Two inputs CRL'
 * '<S229>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Three inputs/Two inputs CRL/Switch_Axis'
 * '<S230>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Phase current Mesurement'
 * '<S231>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement'
 * '<S232>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer'
 * '<S233>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer'
 * '<S234>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/IIR Filter'
 * '<S235>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer'
 * '<S236>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)'
 * '<S237>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem'
 * '<S238>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem2'
 * '<S239>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/A11'
 * '<S240>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/A12'
 * '<S241>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/A22'
 * '<S242>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/L'
 * '<S243>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/L1'
 * '<S244>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/L2'
 * '<S245>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem2/B'
 * '<S246>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem2/L'
 * '<S247>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/IIR Filter/IIR Filter'
 * '<S248>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S249>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S250>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/Direction_Latch'
 * '<S251>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL'
 * '<S252>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/Direction_Latch/Dir_Sense'
 * '<S253>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/Direction_Latch/Subsystem2'
 * '<S254>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/Direction_Latch/Subsystem3'
 * '<S255>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/IIR Filter'
 * '<S256>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Normalize'
 * '<S257>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller'
 * '<S258>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward'
 * '<S259>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Subsystem'
 * '<S260>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO'
 * '<S261>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter'
 * '<S262>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter/Low-pass'
 * '<S263>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S264>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Normalize/Compare To Zero'
 * '<S265>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Normalize/If Action Subsystem'
 * '<S266>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Normalize/Subsystem'
 * '<S267>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Anti-windup'
 * '<S268>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/D Gain'
 * '<S269>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/External Derivative'
 * '<S270>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter'
 * '<S271>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter ICs'
 * '<S272>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/I Gain'
 * '<S273>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain'
 * '<S274>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain Fdbk'
 * '<S275>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator'
 * '<S276>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator ICs'
 * '<S277>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Copy'
 * '<S278>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Gain'
 * '<S279>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/P Copy'
 * '<S280>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Parallel P Gain'
 * '<S281>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Reset Signal'
 * '<S282>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation'
 * '<S283>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation Fdbk'
 * '<S284>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum'
 * '<S285>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum Fdbk'
 * '<S286>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode'
 * '<S287>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode Sum'
 * '<S288>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Integral'
 * '<S289>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Ngain'
 * '<S290>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/postSat Signal'
 * '<S291>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/preInt Signal'
 * '<S292>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/preSat Signal'
 * '<S293>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Anti-windup/Passthrough'
 * '<S294>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/D Gain/Disabled'
 * '<S295>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/External Derivative/Disabled'
 * '<S296>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter/Disabled'
 * '<S297>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter ICs/Disabled'
 * '<S298>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/I Gain/Internal Parameters'
 * '<S299>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain/Passthrough'
 * '<S300>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S301>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator/Discrete'
 * '<S302>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator ICs/Internal IC'
 * '<S303>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S304>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Gain/Disabled'
 * '<S305>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/P Copy/Disabled'
 * '<S306>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S307>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Reset Signal/External Reset'
 * '<S308>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation/Passthrough'
 * '<S309>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation Fdbk/Disabled'
 * '<S310>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum/Sum_PI'
 * '<S311>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum Fdbk/Disabled'
 * '<S312>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode/Disabled'
 * '<S313>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S314>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S315>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S316>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/postSat Signal/Forward_Path'
 * '<S317>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/preInt Signal/Internal PreInt'
 * '<S318>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/preSat Signal/Forward_Path'
 * '<S319>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/GainSystem'
 * '<S320>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter'
 * '<S321>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/InpFilterFunc'
 * '<S322>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod'
 * '<S323>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/Nofunc'
 * '<S324>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/NofuncSpd'
 * '<S325>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod'
 * '<S326>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/SpdFilterFunc'
 * '<S327>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/GainSystem/IGains'
 * '<S328>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/GainSystem/ODGains'
 * '<S329>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/GainSystem/OutDTSetup'
 * '<S330>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter/IIR Filter'
 * '<S331>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter/IIR Filter/Low-pass'
 * '<S332>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S333>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1'
 * '<S334>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3'
 * '<S335>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/Integrator'
 * '<S336>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/Integrator2'
 * '<S337>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter'
 * '<S338>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S339>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S340>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter'
 * '<S341>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S342>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S343>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/Differentiator'
 * '<S344>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/Differentiator1'
 * '<S345>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1'
 * '<S346>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3'
 * '<S347>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter'
 * '<S348>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S349>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S350>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter'
 * '<S351>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S352>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S353>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Subsystem/If Action Subsystem'
 * '<S354>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Subsystem/If Action Subsystem1'
 * '<S355>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem'
 * '<S356>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased'
 * '<S357>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Position Generator'
 * '<S358>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup'
 * '<S359>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S360>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S361>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S362>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S363>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S364>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S365>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S366>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype backpropogation'
 * '<S367>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Codegen'
 * '<S368>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation'
 * '<S369>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Codegen/Subsystem'
 * '<S370>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Codegen/Subsystem/Gate_Inverter1'
 * '<S371>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model'
 * '<S372>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Average-Value Inverter'
 * '<S373>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model'
 * '<S374>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM'
 * '<S375>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous'
 * '<S376>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core'
 * '<S377>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Mechanical and Angle'
 * '<S378>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1'
 * '<S379>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic'
 * '<S380>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/MechToElect'
 * '<S381>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/Power Accounting Bus Creator'
 * '<S382>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/Power Accounting Bus Creator/PwrNotTrnsfrd Input'
 * '<S383>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/Power Accounting Bus Creator/PwrStored Input'
 * '<S384>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/Power Accounting Bus Creator/PwrTrnsfrd Input'
 * '<S385>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Clarke Transform'
 * '<S386>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Inverse Clarke Transform'
 * '<S387>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Inverse Park Transform'
 * '<S388>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Machine Torque'
 * '<S389>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit'
 * '<S390>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Park Transform'
 * '<S391>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Machine Torque/Subsystem'
 * '<S392>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage'
 * '<S393>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage'
 * '<S394>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem'
 * '<S395>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem1'
 * '<S396>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem2'
 * '<S397>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem'
 * '<S398>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem1'
 * '<S399>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem2'
 * '<S400>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem3'
 * '<S401>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control'
 * '<S402>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller'
 * '<S403>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Anti-windup'
 * '<S404>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/D Gain'
 * '<S405>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/External Derivative'
 * '<S406>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Filter'
 * '<S407>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Filter ICs'
 * '<S408>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/I Gain'
 * '<S409>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Ideal P Gain'
 * '<S410>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Ideal P Gain Fdbk'
 * '<S411>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Integrator'
 * '<S412>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Integrator ICs'
 * '<S413>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/N Copy'
 * '<S414>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/N Gain'
 * '<S415>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/P Copy'
 * '<S416>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Parallel P Gain'
 * '<S417>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Reset Signal'
 * '<S418>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Saturation'
 * '<S419>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Saturation Fdbk'
 * '<S420>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Sum'
 * '<S421>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Sum Fdbk'
 * '<S422>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Tracking Mode'
 * '<S423>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Tracking Mode Sum'
 * '<S424>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Tsamp - Integral'
 * '<S425>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Tsamp - Ngain'
 * '<S426>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/postSat Signal'
 * '<S427>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/preInt Signal'
 * '<S428>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/preSat Signal'
 * '<S429>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Anti-windup/Passthrough'
 * '<S430>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/D Gain/Disabled'
 * '<S431>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/External Derivative/Disabled'
 * '<S432>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Filter/Disabled'
 * '<S433>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Filter ICs/Disabled'
 * '<S434>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/I Gain/Internal Parameters'
 * '<S435>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Ideal P Gain/Passthrough'
 * '<S436>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S437>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Integrator/Continuous'
 * '<S438>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Integrator ICs/Internal IC'
 * '<S439>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S440>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/N Gain/Disabled'
 * '<S441>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/P Copy/Disabled'
 * '<S442>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S443>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Reset Signal/Disabled'
 * '<S444>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Saturation/Passthrough'
 * '<S445>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Saturation Fdbk/Disabled'
 * '<S446>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Sum/Sum_PI'
 * '<S447>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Sum Fdbk/Disabled'
 * '<S448>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Tracking Mode/Disabled'
 * '<S449>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S450>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S451>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S452>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/postSat Signal/Forward_Path'
 * '<S453>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/preInt Signal/Internal PreInt'
 * '<S454>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/preSat Signal/Forward_Path'
 * '<S455>' : 'PMSM_to_BLDC_mod1/Timer/PWM Output/ECSoC'
 * '<S456>' : 'PMSM_to_BLDC_mod1/Timer/PWM Output/ECSoC/ECSimCodegen'
 * '<S457>' : 'PMSM_to_BLDC_mod1/V_sense/Analog to Digital Converter1'
 * '<S458>' : 'PMSM_to_BLDC_mod1/V_sense/Analog to Digital Converter1/ECSoC'
 * '<S459>' : 'PMSM_to_BLDC_mod1/V_sense/Analog to Digital Converter1/ECSoC/ECSimCodegen'
 */
#endif                                 /* PMSM_to_BLDC_mod1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
