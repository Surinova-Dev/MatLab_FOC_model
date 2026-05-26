/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.h
 *
 * Code generated for Simulink model 'PMSM_to_BLDC_mod1'.
 *
 * Model version                  : 4.1012
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Tue May 26 17:31:20 2026
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
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "ext_mode.h"
#include "main.h"
#include "mw_stm32_utils.h"
#include "MW_SPI.h"
#include "mw_stm32_spi_ll.h"
#endif                                 /* PMSM_to_BLDC_mod1_COMMON_INCLUDES_ */

#include "PMSM_to_BLDC_mod1_types.h"
#include <string.h>
#include "rtGetNaN.h"
#include <math.h>
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

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
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

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
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

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
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

/* Block states (default storage) for system '<S23>/Bit Shift' */
typedef struct {
  int32_T sfEvent;                     /* '<S25>/bit_shift' */
  boolean_T doneDoubleBufferReInit;    /* '<S25>/bit_shift' */
} DW_BitShift_PMSM_to_BLDC_mod1_T;

/* Block states (default storage) for system '<S23>/Bit Shift1' */
typedef struct {
  int32_T sfEvent;                     /* '<S26>/bit_shift' */
  boolean_T doneDoubleBufferReInit;    /* '<S26>/bit_shift' */
} DW_BitShift1_PMSM_to_BLDC_mod_T;

/* Block states (default storage) for system '<S37>/SPI Receive' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S37>/SPI Receive' */
  boolean_T objisempty;                /* '<S37>/SPI Receive' */
} DW_SPIReceive_PMSM_to_BLDC_mo_T;

/* Block states (default storage) for system '<S37>/SPI Transmit' */
typedef struct {
  stm32cube_blocks_SPIControl_d_T obj; /* '<S37>/SPI Transmit' */
  boolean_T objisempty;                /* '<S37>/SPI Transmit' */
} DW_SPITransmit_PMSM_to_BLDC_m_T;

/* Block signals for system '<S38>/SPI Receive' */
typedef struct {
  uint16_T SPIReceive;                 /* '<S38>/SPI Receive' */
} B_SPIReceive_PMSM_to_BLDC_m_c_T;

/* Block states (default storage) for system '<S38>/SPI Receive' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S38>/SPI Receive' */
  boolean_T objisempty;                /* '<S38>/SPI Receive' */
} DW_SPIReceive_PMSM_to_BLDC__f_T;

/* Block signals for system '<S49>/SPI Receive' */
typedef struct {
  uint16_T SPIReceive[15];             /* '<S49>/SPI Receive' */
} B_SPIReceive_PMSM_to_BLDC__ca_T;

/* Block states (default storage) for system '<S49>/SPI Receive' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S49>/SPI Receive' */
  boolean_T objisempty;                /* '<S49>/SPI Receive' */
} DW_SPIReceive_PMSM_to_BLDC_fw_T;

/* Block states (default storage) for system '<S49>/SPI Transmit' */
typedef struct {
  stm32cube_blocks_SPIControl_d_T obj; /* '<S49>/SPI Transmit' */
  boolean_T objisempty;                /* '<S49>/SPI Transmit' */
} DW_SPITransmit_PMSM_to_BLDC_f_T;

/* Block states (default storage) for system '<S199>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S199>/If Action Subsystem' */
} DW_IfActionSubsystem_PMSM_to__T;

/* Block states (default storage) for system '<S199>/If Action Subsystem1' */
typedef struct {
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S199>/If Action Subsystem1' */
} DW_IfActionSubsystem1_PMSM_to_T;

/* Block signals (default storage) */
typedef struct {
  real_T Delay2[2];                    /* '<Root>/Delay2' */
  real_T Gain;                         /* '<S9>/Gain' */
  real_T Constant;                     /* '<S3>/Constant' */
  real_T DataTypeConversion[3];        /* '<S233>/Data Type  Conversion' */
  real_T Kalphabeta0[3];               /* '<S79>/Kalphabeta0' */
  real_T Merge[2];                     /* '<S262>/Merge' */
  real_T Sum;                          /* '<S259>/Sum' */
  real_T Integrator;                   /* '<S304>/Integrator' */
  real_T DataTypeConversion_a;         /* '<S67>/Data Type Conversion' */
  real_T DataTypeConversion1;          /* '<S74>/Data Type Conversion1' */
  real_T Add;                          /* '<S64>/Add' */
  real_T ProportionalGain;             /* '<S445>/Proportional Gain' */
  real_T Sum_o;                        /* '<S449>/Sum' */
  real_T Gain_p[3];                    /* '<S209>/Gain' */
  real_T Gain_f[3];                    /* '<S68>/Gain' */
  real_T Gain5[3];                     /* '<S373>/Gain5' */
  real_T Gate_pulse[6];
  /* '<S63>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Codegen_at_outport_0Inport1' */
  real_T idq_ref[2];
  /* '<S59>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Speed_controls_at_outport_0Inport1' */
  real_T DataTypeConversion_e;         /* '<S75>/Data Type Conversion' */
  real_T DataTypeConversion1_i;        /* '<S75>/Data Type Conversion1' */
  real_T TmpSignalConversionAtDelayInpor[4];
                                /* '<S62>/TmpSignal ConversionAtDelayInport1' */
  real_T TmpSignalConversionAtTAQSigLogg[3];
  /* '<S66>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Inverse Park Transform1_at_outport_0Inport1' */
  real_T Int1;                         /* '<S380>/Int1' */
  real_T Gain_j;                       /* '<S374>/Gain' */
  real_T Gain2;                        /* '<S391>/Gain2' */
  real_T Gain1;                        /* '<S374>/Gain1' */
  real_T VectorConcatenate[3];         /* '<S379>/Vector Concatenate' */
  real_T DataTypeConversion_c[3];      /* '<S374>/Data Type Conversion' */
  real_T Product[3];                   /* '<S375>/Product' */
  real_T Add_a;                        /* '<S388>/Add' */
  real_T Add1;                         /* '<S388>/Add1' */
  real_T Add_h;                        /* '<S395>/Add' */
  real_T Add_d;                        /* '<S396>/Add' */
  real_T IntegralGain;                 /* '<S437>/Integral Gain' */
  real_T Gain2_g;                      /* '<S59>/Gain2' */
  real_T Gain1_e;                      /* '<S376>/Gain1' */
  real_T Constant_a;                   /* '<S64>/Constant' */
  real_T algDD_o1;                     /* '<S231>/algDD' */
  real_T algDD_o2;                     /* '<S231>/algDD' */
  real_T algDD_o1_g;
  real_T algDD_o2_h;
  real_T Gain1_m;                      /* '<S13>/Gain1' */
  real_T Gain_k;                       /* '<S12>/Gain' */
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
  real32_T Delay3;                     /* '<Root>/Delay3' */
  real32_T Gain3;                      /* '<S59>/Gain3' */
  uint16_T AnalogtoDigitalConverter;  /* '<S462>/Analog to Digital Converter' */
  uint16_T BitwiseOR;                  /* '<S50>/Bitwise OR' */
  uint16_T BitwiseOR_p;                /* '<S49>/Bitwise OR' */
  uint16_T DataTypeConversion_d;       /* '<S49>/Data Type Conversion' */
  uint16_T BitwiseOR_o;                /* '<S43>/Bitwise OR' */
  uint16_T BitwiseOR_h;                /* '<S37>/Bitwise OR' */
  uint16_T BitwiseOR_e;                /* '<S24>/Bitwise OR' */
  uint16_T BitwiseOR_n;                /* '<S23>/Bitwise OR' */
  uint16_T DataTypeConversion_m;       /* '<S23>/Data Type Conversion' */
  int16_T Switch;                      /* '<S255>/Switch' */
  boolean_T Delay;                     /* '<Root>/Delay' */
  boolean_T Delay1;                    /* '<Root>/Delay1' */
  boolean_T Compare;                   /* '<S267>/Compare' */
  boolean_T Compare_a;                 /* '<S34>/Compare' */
  boolean_T Compare_g;                 /* '<S33>/Compare' */
  boolean_T AND1;                      /* '<S5>/AND1' */
  boolean_T AND;                       /* '<S5>/AND' */
  B_SPIReceive_PMSM_to_BLDC__ca_T SPIReceive_pnaevv;/* '<S49>/SPI Receive' */
  B_SPIReceive_PMSM_to_BLDC__ca_T SPIReceive_pnaev;/* '<S49>/SPI Receive' */
  B_SPIReceive_PMSM_to_BLDC_m_c_T SPIReceive_pnae;/* '<S38>/SPI Receive' */
  B_SPIReceive_PMSM_to_BLDC_m_c_T SPIReceive_pn;/* '<S38>/SPI Receive' */
} B_PMSM_to_BLDC_mod1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S24>/SPI Receive' */
  stm32cube_blocks_SPIControlle_T obj_g;/* '<S23>/SPI Receive' */
  stm32cube_blocks_SPIControl_d_T obj_n;/* '<S24>/SPI Transmit' */
  stm32cube_blocks_SPIControl_d_T obj_j;/* '<S23>/SPI Transmit' */
  stm32cube_blocks_AnalogInput__T obj_p;
                                      /* '<S462>/Analog to Digital Converter' */
  stm32cube_blocks_AnalogInput__T obj_o;/* '<S19>/Analog to Digital Converter' */
  stm32cube_blocks_AnalogInput__T obj_d;/* '<S16>/Analog to Digital Converter' */
  stm32cube_blocks_DigitalPortW_T obj_ow;/* '<S22>/Digital Port Write' */
  stm32cube_blocks_PWMOutput_PM_T obj_e;/* '<S459>/PWM Output' */
  real_T Delay2_DSTATE;                /* '<Root>/Delay2' */
  real_T Delay_DSTATE[3];              /* '<S59>/Delay' */
  real_T Delay_DSTATE_m[8];            /* '<S62>/Delay' */
  real_T Delay_DSTATE_c[2];            /* '<S239>/Delay' */
  real_T Delay_DSTATE_k[2];            /* '<S252>/Delay' */
  real_T Delay_DSTATE_a;               /* '<S335>/Delay' */
  real_T Delay_DSTATE_aj;              /* '<S359>/Delay' */
  real_T Integrator_DSTATE;            /* '<S304>/Integrator' */
  real_T Delay_DSTATE_ai;              /* '<S360>/Delay' */
  real_T Integrator_DSTATE_b;          /* '<S174>/Integrator' */
  real_T Integrator_DSTATE_n;          /* '<S119>/Integrator' */
  real_T Delay_DSTATE_g;               /* '<S266>/Delay' */
  real_T Delay_DSTATE_aa;              /* '<S352>/Delay' */
  real_T Delay2_DSTATE_n;              /* '<S347>/Delay2' */
  real_T Delay3_DSTATE;                /* '<S347>/Delay3' */
  real_T Delay2_DSTATE_h;              /* '<S346>/Delay2' */
  real_T Delay3_DSTATE_p;              /* '<S346>/Delay3' */
  real_T Delay_DSTATE_l;               /* '<S355>/Delay' */
  real_T Delay_DSTATE_av;              /* '<S342>/Delay' */
  real_T Delay1_DSTATE;                /* '<S339>/Delay1' */
  real_T Delay_DSTATE_f;               /* '<S339>/Delay' */
  real_T Delay_DSTATE_d;               /* '<S345>/Delay' */
  real_T Delay1_DSTATE_o;              /* '<S338>/Delay1' */
  real_T Delay_DSTATE_i;               /* '<S338>/Delay' */
  real_T CS_val;                       /* '<Root>/Chart' */
  real_T Drv_ok;                       /* '<Root>/Chart' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<S7>/Scope' */

  struct {
    void *LoggedData[8];
  } Scope_PWORK_i;                     /* '<Root>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<S7>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_h;                     /* '<S9>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_k;                     /* '<S59>/Scope' */

  struct {
    void *LoggedData;
  } TimeScope1_PWORK;                  /* '<S59>/Time Scope1' */

  struct {
    void *LoggedData;
  } TimeScope2_PWORK;                  /* '<S59>/Time Scope2' */

  struct {
    void *LoggedData;
  } Scope_PWORK_g;                     /* '<S62>/Scope' */

  struct {
    void *LoggedData[3];
  } Scope1_PWORK_p;                    /* '<S62>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_hn;                    /* '<S66>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_d;                     /* '<S74>/Scope' */

  struct {
    void *LoggedData[6];
  } Scope_PWORK_e;                     /* '<S370>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_a;                     /* '<S371>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_m;                     /* '<S374>/Scope' */

  struct {
    void *LoggedData[3];
  } Scope_PWORK_o;                     /* '<S376>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_b;                     /* '<S64>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_hj;                    /* '<S6>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope2_PWORK;                      /* '<S6>/Scope2' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_hp;                    /* '<S5>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_c;                     /* '<S13>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_do;                    /* '<S12>/Scope' */

  real32_T Delay3_DSTATE_d;            /* '<Root>/Delay3' */
  real32_T Delay1_DSTATE_f;            /* '<S235>/Delay1' */
  real32_T Delay1_DSTATE_fx;           /* '<S59>/Delay1' */
  uint32_T is_Test2;                   /* '<Root>/Chart' */
  uint32_T is_Test;                    /* '<Root>/Chart' */
  uint16_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint16_T temporalCounter_i2;         /* '<Root>/Chart' */
  boolean_T Delay_DSTATE_cn;           /* '<Root>/Delay' */
  boolean_T Delay1_DSTATE_fv;          /* '<Root>/Delay1' */
  int8_T Timer_SubsysRanBC;            /* '<Root>/Timer' */
  int8_T If_ActiveSubsystem;           /* '<S253>/If' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S262>/Switch Case' */
  int8_T If_ActiveSubsystem_g;         /* '<S259>/If' */
  int8_T SwitchCase_ActiveSubsystem_n; /* '<S261>/Switch Case' */
  int8_T If_ActiveSubsystem_e;         /* '<S364>/If' */
  int8_T Integrator_PrevResetState;    /* '<S304>/Integrator' */
  int8_T If_ActiveSubsystem_c;         /* '<S225>/If' */
  int8_T Integrator_PrevResetState_n;  /* '<S174>/Integrator' */
  int8_T Integrator_PrevResetState_nt; /* '<S119>/Integrator' */
  int8_T If_ActiveSubsystem_m;         /* '<S199>/If' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S364>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S364>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanB_e;/* '<S262>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_a;/* '<S262>/If Action Subsystem' */
  int8_T OptimizedDifferentiationMethod_;
                                   /* '<S261>/OptimizedDifferentiationMethod' */
  int8_T IntegralMethod_SubsysRanBC;   /* '<S261>/IntegralMethod' */
  int8_T IfActionSubsystem_SubsysRanBC_b;/* '<S259>/If Action Subsystem' */
  int8_T Subsystem_SubsysRanBC;        /* '<S259>/Subsystem' */
  int8_T Subsystem3_SubsysRanBC;       /* '<S253>/Subsystem3' */
  int8_T Subsystem2_SubsysRanBC;       /* '<S253>/Subsystem2' */
  int8_T Dir_Sense_SubsysRanBC;        /* '<S253>/Dir_Sense' */
  int8_T Status_Reg_2_read_SubsysRanBC;/* '<S7>/Status_Reg_2_read' */
  int8_T Status_Reg1_read_SubsysRanBC; /* '<S7>/Status_Reg1_read' */
  int8_T Subsystem1_SubsysRanBC;       /* '<S36>/Subsystem1' */
  int8_T Subsystem_SubsysRanBC_f;      /* '<S36>/Subsystem' */
  int8_T Subsystem1_SubsysRanBC_n;     /* '<S35>/Subsystem1' */
  int8_T Subsystem_SubsysRanBC_i;      /* '<S35>/Subsystem' */
  int8_T Ctrl_Reg_1_SubsysRanBC;       /* '<S5>/Ctrl_Reg_1' */
  int8_T Control_Reg2_SubsysRanBC;     /* '<S5>/Control_Reg2' */
  int8_T Subsystem1_SubsysRanBC_c;     /* '<S2>/Subsystem1' */
  int8_T Subsystem_SubsysRanBC_g;      /* '<S2>/Subsystem' */
  uint8_T is_active_c3_PMSM_to_BLDC_mod1;/* '<Root>/Chart' */
  uint8_T is_active_Test2;             /* '<Root>/Chart' */
  uint8_T is_active_Test;              /* '<Root>/Chart' */
  boolean_T icLoad;                    /* '<S252>/Delay' */
  boolean_T AlphaRelay_Mode;           /* '<S253>/AlphaRelay' */
  boolean_T BetaRelay_Mode;            /* '<S253>/BetaRelay' */
  boolean_T icLoad_f;                  /* '<S335>/Delay' */
  boolean_T icLoad_a;                  /* '<S360>/Delay' */
  boolean_T icLoad_b;                  /* '<S266>/Delay' */
  boolean_T Integrator_DWORK1;         /* '<S395>/Integrator' */
  boolean_T Integrator_DWORK1_g;       /* '<S396>/Integrator' */
  boolean_T icLoad_b1;                 /* '<S352>/Delay' */
  boolean_T icLoad_c;                  /* '<S355>/Delay' */
  boolean_T icLoad_bd;                 /* '<S342>/Delay' */
  boolean_T icLoad_k;                  /* '<S345>/Delay' */
  boolean_T Timer_MODE;                /* '<Root>/Timer' */
  boolean_T Status_Reg_2_read_MODE;    /* '<S7>/Status_Reg_2_read' */
  boolean_T Status_Reg1_read_MODE;     /* '<S7>/Status_Reg1_read' */
  boolean_T Subsystem1_MODE;           /* '<S36>/Subsystem1' */
  boolean_T Subsystem_MODE;            /* '<S36>/Subsystem' */
  boolean_T Subsystem1_MODE_m;         /* '<S35>/Subsystem1' */
  boolean_T Subsystem_MODE_f;          /* '<S35>/Subsystem' */
  boolean_T Ctrl_Reg_1_MODE;           /* '<S5>/Ctrl_Reg_1' */
  boolean_T Control_Reg2_MODE;         /* '<S5>/Control_Reg2' */
  boolean_T Subsystem1_MODE_b;         /* '<S2>/Subsystem1' */
  boolean_T Subsystem_MODE_n;          /* '<S2>/Subsystem' */
  DW_IfActionSubsystem1_PMSM_to_T IfActionSubsystem1_j;/* '<S225>/If Action Subsystem1' */
  DW_IfActionSubsystem_PMSM_to__T IfActionSubsystem_d;/* '<S225>/If Action Subsystem' */
  DW_IfActionSubsystem1_PMSM_to_T IfActionSubsystem1;/* '<S199>/If Action Subsystem1' */
  DW_IfActionSubsystem_PMSM_to__T IfActionSubsystem;/* '<S199>/If Action Subsystem' */
  DW_SPITransmit_PMSM_to_BLDC_f_T SPITransmit_pnaevv;/* '<S49>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC_fw_T SPIReceive_pnaevv;/* '<S49>/SPI Receive' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1_o;/* '<S50>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift_n;/* '<S50>/Bit Shift' */
  DW_SPITransmit_PMSM_to_BLDC_f_T SPITransmit_pnaev;/* '<S49>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC_fw_T SPIReceive_pnaev;/* '<S49>/SPI Receive' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1_j;/* '<S49>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift_p;/* '<S49>/Bit Shift' */
  DW_SPITransmit_PMSM_to_BLDC_m_T SPITransmit_pnae;/* '<S37>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC__f_T SPIReceive_pnae;/* '<S38>/SPI Receive' */
  DW_SPITransmit_PMSM_to_BLDC_m_T SPITransmit_pna;/* '<S37>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC_mo_T SPIReceive_pna;/* '<S37>/SPI Receive' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1_m;/* '<S43>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift_b;/* '<S43>/Bit Shift' */
  DW_SPITransmit_PMSM_to_BLDC_m_T SPITransmit_pn;/* '<S37>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC__f_T SPIReceive_pn;/* '<S38>/SPI Receive' */
  DW_SPITransmit_PMSM_to_BLDC_m_T SPITransmit_p;/* '<S37>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC_mo_T SPIReceive_p;/* '<S37>/SPI Receive' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1_p;/* '<S37>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift_hq;/* '<S37>/Bit Shift' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1_d;/* '<S24>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift_h;/* '<S24>/Bit Shift' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1;/* '<S23>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift;/* '<S23>/Bit Shift' */
} DW_PMSM_to_BLDC_mod1_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S440>/Integrator' */
  real_T Int1_CSTATE;                  /* '<S380>/Int1' */
  real_T Integrator_CSTATE_d;          /* '<S395>/Integrator' */
  real_T Integrator_CSTATE_l;          /* '<S396>/Integrator' */
} X_PMSM_to_BLDC_mod1_T;

/* Periodic continuous state vector (global) */
typedef int_T PeriodicIndX_PMSM_to_BLDC_mod_T[1];
typedef real_T PeriodicRngX_PMSM_to_BLDC_mod_T[2];

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S440>/Integrator' */
  real_T Int1_CSTATE;                  /* '<S380>/Int1' */
  real_T Integrator_CSTATE_d;          /* '<S395>/Integrator' */
  real_T Integrator_CSTATE_l;          /* '<S396>/Integrator' */
} XDot_PMSM_to_BLDC_mod1_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S440>/Integrator' */
  boolean_T Int1_CSTATE;               /* '<S380>/Int1' */
  boolean_T Integrator_CSTATE_d;       /* '<S395>/Integrator' */
  boolean_T Integrator_CSTATE_l;       /* '<S396>/Integrator' */
} XDis_PMSM_to_BLDC_mod1_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Delay1_Reset_ZCE;         /* '<S235>/Delay1' */
  ZCSigState Delay_Reset_ZCE;          /* '<S239>/Delay' */
  ZCSigState Delay_Reset_ZCE_a;        /* '<S359>/Delay' */
  ZCSigState Delay2_Reset_ZCE;         /* '<S347>/Delay2' */
  ZCSigState Delay3_Reset_ZCE;         /* '<S347>/Delay3' */
  ZCSigState Delay2_Reset_ZCE_p;       /* '<S346>/Delay2' */
  ZCSigState Delay3_Reset_ZCE_k;       /* '<S346>/Delay3' */
  ZCSigState Delay1_Reset_ZCE_p;       /* '<S339>/Delay1' */
  ZCSigState Delay_Reset_ZCE_h;        /* '<S339>/Delay' */
  ZCSigState Delay1_Reset_ZCE_i;       /* '<S338>/Delay1' */
  ZCSigState Delay_Reset_ZCE_k;        /* '<S338>/Delay' */
  ZCSigState Dir_Sense_Trig_ZCE;       /* '<S253>/Dir_Sense' */
} PrevZCX_PMSM_to_BLDC_mod1_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Gain4;                  /* '<S59>/Gain4' */
  const real_T Constant3;              /* '<S80>/Constant3' */
  const real_T Constant3_n;            /* '<S81>/Constant3' */
  const real_T Switch;                 /* '<S375>/Switch' */
  const real_T Gain;                   /* '<S380>/Gain' */
  const real_T IndexVector;            /* '<S394>/Index Vector' */
  const real_T IndexVector1;           /* '<S394>/Index Vector1' */
  const real_T Add;                    /* '<S394>/Add' */
  const real_T IndexVector_a;          /* '<S395>/Index Vector' */
  const real_T IndexVector_b;          /* '<S397>/Index Vector' */
  const real_T IndexVector_ah;         /* '<S398>/Index Vector' */
  const real_T IndexVector1_e;         /* '<S398>/Index Vector1' */
  const real_T IndexVector_j;          /* '<S399>/Index Vector' */
  const real_T IndexVector_d;          /* '<S396>/Index Vector' */
  const real_T IndexVector_k;          /* '<S400>/Index Vector' */
  const real_T IndexVector_m;          /* '<S401>/Index Vector' */
  const real_T IndexVector1_g;         /* '<S401>/Index Vector1' */
  const real_T IndexVector_bt;         /* '<S402>/Index Vector' */
  const real_T Product;                /* '<S402>/Product' */
  const real_T IndexVector_d3;         /* '<S403>/Index Vector' */
  const uint32_T DataTypeConversion;   /* '<S262>/Data Type Conversion' */
  const uint16_T BitwiseAND;           /* '<S50>/Bitwise AND' */
  const uint16_T BitwiseAND_m;         /* '<S49>/Bitwise AND' */
  const uint16_T BitwiseAND_j;         /* '<S43>/Bitwise AND' */
  const uint16_T BitwiseAND_d;         /* '<S37>/Bitwise AND' */
  const uint16_T BitwiseAND_e;         /* '<S24>/Bitwise AND' */
  const uint16_T BitwiseAND_jx;        /* '<S23>/Bitwise AND' */
  const boolean_T DataTypeConversion_j;/* '<S8>/Data Type Conversion' */
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
   *   '<S197>/sine_table_values'
   *   '<S223>/sine_table_values'
   */
  real_T pooled17[1002];

  /* Computed Parameter: sine_table_values_Value
   * Referenced by: '<S362>/sine_table_values'
   */
  real32_T sine_table_values_Value[1002];
} ConstP_PMSM_to_BLDC_mod1_T;

/* Real-time Model Data Structure */
struct tag_RTM_PMSM_to_BLDC_mod1_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
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
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

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
    uint32_T clockTick3;
    uint32_T clockTick4;
    uint32_T clockTick5;
    boolean_T firstInitCondFlag;
    struct {
      uint16_T TID[6];
    } TaskCounters;

    time_T tStart;
    time_T tFinal;
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
 * Block '<S69>/B' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate' : Unused code path elimination
 * Block '<S71>/C' : Unused code path elimination
 * Block '<S71>/D' : Unused code path elimination
 * Block '<S197>/Data Type Duplicate' : Unused code path elimination
 * Block '<S197>/Data Type Propagation' : Unused code path elimination
 * Block '<S202>/Data Type Duplicate' : Unused code path elimination
 * Block '<S203>/Data Type Duplicate' : Unused code path elimination
 * Block '<S205>/Data Type Duplicate' : Unused code path elimination
 * Block '<S205>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Vc' : Unused code path elimination
 * Block '<S216>/Data Type Duplicate' : Unused code path elimination
 * Block '<S73>/C' : Unused code path elimination
 * Block '<S73>/D' : Unused code path elimination
 * Block '<S223>/Data Type Duplicate' : Unused code path elimination
 * Block '<S223>/Data Type Propagation' : Unused code path elimination
 * Block '<S228>/Data Type Duplicate' : Unused code path elimination
 * Block '<S229>/Data Type Duplicate' : Unused code path elimination
 * Block '<S231>/Data Type Duplicate' : Unused code path elimination
 * Block '<S231>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S235>/Data Type Propagation' : Unused code path elimination
 * Block '<S239>/Data Type Duplicate' : Unused code path elimination
 * Block '<S239>/Data Type Propagation' : Unused code path elimination
 * Block '<S242>/Data Type Duplicate' : Unused code path elimination
 * Block '<S242>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S242>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S242>/Data Type Propagation' : Unused code path elimination
 * Block '<S242>/Data Type Propagation1' : Unused code path elimination
 * Block '<S242>/Data Type Propagation2' : Unused code path elimination
 * Block '<S242>/Data Type Propagation3' : Unused code path elimination
 * Block '<S243>/Data Type Duplicate' : Unused code path elimination
 * Block '<S243>/Data Type Propagation' : Unused code path elimination
 * Block '<S244>/Data Type Duplicate' : Unused code path elimination
 * Block '<S244>/Data Type Propagation' : Unused code path elimination
 * Block '<S240>/Data Type Propagation' : Unused code path elimination
 * Block '<S245>/Data Type Duplicate' : Unused code path elimination
 * Block '<S245>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S245>/Data Type Propagation' : Unused code path elimination
 * Block '<S246>/Data Type Duplicate' : Unused code path elimination
 * Block '<S246>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S246>/Data Type Propagation' : Unused code path elimination
 * Block '<S247>/Data Type Duplicate' : Unused code path elimination
 * Block '<S247>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S247>/Data Type Propagation' : Unused code path elimination
 * Block '<S248>/Data Type Duplicate' : Unused code path elimination
 * Block '<S248>/Data Type Propagation' : Unused code path elimination
 * Block '<S241>/Data Type Propagation' : Unused code path elimination
 * Block '<S249>/Data Type Duplicate' : Unused code path elimination
 * Block '<S249>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S249>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S249>/Data Type Propagation' : Unused code path elimination
 * Block '<S249>/Data Type Propagation1' : Unused code path elimination
 * Block '<S237>/Data Type Duplicate' : Unused code path elimination
 * Block '<S254>/Data Type Duplicate' : Unused code path elimination
 * Block '<S254>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S254>/Data Type Conversion' : Unused code path elimination
 * Block '<S254>/Data Type Conversion1' : Unused code path elimination
 * Block '<S258>/Data Type Duplicate' : Unused code path elimination
 * Block '<S259>/Data Type Duplicate' : Unused code path elimination
 * Block '<S259>/Data Type Propagation' : Unused code path elimination
 * Block '<S268>/Data Type Duplicate' : Unused code path elimination
 * Block '<S269>/Data Type Duplicate' : Unused code path elimination
 * Block '<S269>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S269>/Data Type Propagation' : Unused code path elimination
 * Block '<S261>/Data Type Duplicate' : Unused code path elimination
 * Block '<S261>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S322>/I1CnstDT' : Unused code path elimination
 * Block '<S322>/I2CnstDT' : Unused code path elimination
 * Block '<S330>/Bias' : Unused code path elimination
 * Block '<S330>/Bias1' : Unused code path elimination
 * Block '<S330>/Constant' : Unused code path elimination
 * Block '<S330>/Data Type Duplicate' : Unused code path elimination
 * Block '<S330>/Data Type Propagation' : Unused code path elimination
 * Block '<S330>/Data Type Propagation1' : Unused code path elimination
 * Block '<S330>/Divide' : Unused code path elimination
 * Block '<S330>/Divide1' : Unused code path elimination
 * Block '<S330>/OD1Cnst' : Unused code path elimination
 * Block '<S330>/OD1CnstDT' : Unused code path elimination
 * Block '<S330>/Product' : Unused code path elimination
 * Block '<S330>/Unary Minus' : Unused code path elimination
 * Block '<S322>/MaxFreqCnst' : Unused code path elimination
 * Block '<S322>/OD1CnstDT' : Unused code path elimination
 * Block '<S322>/OD2CnstDT' : Unused code path elimination
 * Block '<S331>/Bias' : Unused code path elimination
 * Block '<S331>/Constant' : Unused code path elimination
 * Block '<S331>/Data Type Duplicate' : Unused code path elimination
 * Block '<S331>/Data Type Propagation' : Unused code path elimination
 * Block '<S331>/Data Type Propagation1' : Unused code path elimination
 * Block '<S331>/Data Type Propagation2' : Unused code path elimination
 * Block '<S331>/Divide' : Unused code path elimination
 * Block '<S331>/OD1Cnst' : Unused code path elimination
 * Block '<S331>/OD1CnstDT' : Unused code path elimination
 * Block '<S331>/OD1CnstDT1' : Unused code path elimination
 * Block '<S331>/Product' : Unused code path elimination
 * Block '<S331>/Product1' : Unused code path elimination
 * Block '<S331>/SampleTime' : Unused code path elimination
 * Block '<S332>/Const' : Unused code path elimination
 * Block '<S332>/Data Type Propagation' : Unused code path elimination
 * Block '<S332>/Data Type Propagation1' : Unused code path elimination
 * Block '<S332>/MaxFreqDT' : Unused code path elimination
 * Block '<S332>/Product' : Unused code path elimination
 * Block '<S323>/Data Type Duplicate' : Unused code path elimination
 * Block '<S324>/Bias' : Unused code path elimination
 * Block '<S324>/Constant' : Unused code path elimination
 * Block '<S324>/Data Type Propagation' : Unused code path elimination
 * Block '<S324>/Data Type Propagation1' : Unused code path elimination
 * Block '<S324>/Divide' : Unused code path elimination
 * Block '<S324>/Product' : Unused code path elimination
 * Block '<S325>/Data Type Duplicate' : Unused code path elimination
 * Block '<S325>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S325>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S336>/Data Type Duplicate' : Unused code path elimination
 * Block '<S337>/Data Type Duplicate' : Unused code path elimination
 * Block '<S338>/Data Type Duplicate' : Unused code path elimination
 * Block '<S338>/Data Type Propagation' : Unused code path elimination
 * Block '<S338>/Data Type Propagation1' : Unused code path elimination
 * Block '<S339>/Data Type Duplicate' : Unused code path elimination
 * Block '<S339>/Data Type Propagation' : Unused code path elimination
 * Block '<S339>/Data Type Propagation1' : Unused code path elimination
 * Block '<S328>/Data Type Duplicate' : Unused code path elimination
 * Block '<S346>/Data Type Duplicate' : Unused code path elimination
 * Block '<S346>/Data Type Propagation' : Unused code path elimination
 * Block '<S347>/Data Type Duplicate' : Unused code path elimination
 * Block '<S347>/Data Type Propagation' : Unused code path elimination
 * Block '<S348>/Data Type Duplicate' : Unused code path elimination
 * Block '<S349>/Data Type Duplicate' : Unused code path elimination
 * Block '<S329>/Bias' : Unused code path elimination
 * Block '<S329>/Constant' : Unused code path elimination
 * Block '<S329>/Data Type Propagation' : Unused code path elimination
 * Block '<S329>/Data Type Propagation1' : Unused code path elimination
 * Block '<S329>/Divide' : Unused code path elimination
 * Block '<S329>/Product' : Unused code path elimination
 * Block '<S262>/Data Type Duplicate' : Unused code path elimination
 * Block '<S359>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S359>/Data Type Propagation' : Unused code path elimination
 * Block '<S360>/BooleanTypeCast' : Unused code path elimination
 * Block '<S360>/Data Type Duplicate' : Unused code path elimination
 * Block '<S360>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S360>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S360>/Data Type Duplicate3' : Unused code path elimination
 * Block '<S360>/Data Type Propagation' : Unused code path elimination
 * Block '<S360>/InpGainDatatype' : Unused code path elimination
 * Block '<S360>/OutGainDatatype' : Unused code path elimination
 * Block '<S360>/Reset' : Unused code path elimination
 * Block '<S362>/Data Type Duplicate' : Unused code path elimination
 * Block '<S362>/Data Type Propagation' : Unused code path elimination
 * Block '<S367>/Data Type Duplicate' : Unused code path elimination
 * Block '<S368>/Data Type Duplicate' : Unused code path elimination
 * Block '<S380>/Constant' : Unused code path elimination
 * Block '<S381>/Add' : Unused code path elimination
 * Block '<S381>/Add2' : Unused code path elimination
 * Block '<S381>/Add4' : Unused code path elimination
 * Block '<S381>/Constant' : Unused code path elimination
 * Block '<S381>/Gain' : Unused code path elimination
 * Block '<S381>/Gain1' : Unused code path elimination
 * Block '<S381>/Gain2' : Unused code path elimination
 * Block '<S383>/Constant' : Unused code path elimination
 * Block '<S383>/Mod' : Unused code path elimination
 * Block '<S383>/polepair' : Unused code path elimination
 * Block '<S381>/Product' : Unused code path elimination
 * Block '<S381>/Product1' : Unused code path elimination
 * Block '<S381>/Product11' : Unused code path elimination
 * Block '<S381>/Product12' : Unused code path elimination
 * Block '<S381>/Product2' : Unused code path elimination
 * Block '<S381>/Product3' : Unused code path elimination
 * Block '<S381>/Product4' : Unused code path elimination
 * Block '<S61>/Data Type Conversion1' : Unused code path elimination
 * Block '<S61>/Data Type Conversion3' : Unused code path elimination
 * Block '<S61>/Data Type Conversion5' : Unused code path elimination
 * Block '<S24>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S197>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S216>/Ka' : Eliminated nontunable gain of 1
 * Block '<S216>/Kb' : Eliminated nontunable gain of 1
 * Block '<S216>/Kc' : Eliminated nontunable gain of 1
 * Block '<S223>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S62>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S235>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S237>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S254>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S258>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S269>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S269>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S269>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S261>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S323>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S336>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S337>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S348>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S349>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S362>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S364>/convert_pu' : Eliminated nontunable gain of 1
 * Block '<S369>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S59>/Gain' : Eliminated nontunable gain of 1
 * Block '<S59>/Gain1' : Eliminated nontunable gain of 1
 * Block '<S206>/Offset' : Unused code path elimination
 * Block '<S206>/Unary_Minus' : Unused code path elimination
 * Block '<S232>/Offset' : Unused code path elimination
 * Block '<S232>/Unary_Minus' : Unused code path elimination
 * Block '<S237>/One' : Unused code path elimination
 * Block '<S237>/Reset' : Unused code path elimination
 * Block '<S237>/Sum' : Unused code path elimination
 * Block '<S237>/UseInputPort' : Unused code path elimination
 * Block '<S237>/a' : Unused code path elimination
 * Block '<S258>/One' : Unused code path elimination
 * Block '<S258>/Reset' : Unused code path elimination
 * Block '<S258>/Sum' : Unused code path elimination
 * Block '<S258>/UseInputPort' : Unused code path elimination
 * Block '<S258>/a' : Unused code path elimination
 * Block '<S323>/FilterConstant' : Unused code path elimination
 * Block '<S323>/OneMinusFilterConstant' : Unused code path elimination
 * Block '<S323>/Reset' : Unused code path elimination
 * Block '<S323>/UseInputPort' : Unused code path elimination
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
 * '<S3>'   : 'PMSM_to_BLDC_mod1/Dashboard'
 * '<S4>'   : 'PMSM_to_BLDC_mod1/En_gate'
 * '<S5>'   : 'PMSM_to_BLDC_mod1/SPI_Write'
 * '<S6>'   : 'PMSM_to_BLDC_mod1/SPI_read'
 * '<S7>'   : 'PMSM_to_BLDC_mod1/Status_reg_read'
 * '<S8>'   : 'PMSM_to_BLDC_mod1/Timer'
 * '<S9>'   : 'PMSM_to_BLDC_mod1/V_sense'
 * '<S10>'  : 'PMSM_to_BLDC_mod1/untitledPanel'
 * '<S11>'  : 'PMSM_to_BLDC_mod1/untitledPanel1'
 * '<S12>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem'
 * '<S13>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem1'
 * '<S14>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem/Analog to Digital Converter1'
 * '<S15>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem/Analog to Digital Converter1/ECSoC'
 * '<S16>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem/Analog to Digital Converter1/ECSoC/ECSimCodegen'
 * '<S17>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem1/Analog to Digital Converter2'
 * '<S18>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem1/Analog to Digital Converter2/ECSoC'
 * '<S19>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem1/Analog to Digital Converter2/ECSoC/ECSimCodegen'
 * '<S20>'  : 'PMSM_to_BLDC_mod1/En_gate/Digital Port Write'
 * '<S21>'  : 'PMSM_to_BLDC_mod1/En_gate/Digital Port Write/ECSoC'
 * '<S22>'  : 'PMSM_to_BLDC_mod1/En_gate/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S23>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2'
 * '<S24>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1'
 * '<S25>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2/Bit Shift'
 * '<S26>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2/Bit Shift1'
 * '<S27>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2/Bit Shift/bit_shift'
 * '<S28>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2/Bit Shift1/bit_shift'
 * '<S29>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1/Bit Shift'
 * '<S30>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1/Bit Shift1'
 * '<S31>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1/Bit Shift/bit_shift'
 * '<S32>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1/Bit Shift1/bit_shift'
 * '<S33>'  : 'PMSM_to_BLDC_mod1/SPI_read/Compare To Constant'
 * '<S34>'  : 'PMSM_to_BLDC_mod1/SPI_read/Compare To Constant1'
 * '<S35>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read'
 * '<S36>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read'
 * '<S37>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem'
 * '<S38>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem1'
 * '<S39>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem/Bit Shift'
 * '<S40>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem/Bit Shift1'
 * '<S41>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem/Bit Shift/bit_shift'
 * '<S42>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem/Bit Shift1/bit_shift'
 * '<S43>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem'
 * '<S44>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem1'
 * '<S45>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem/Bit Shift'
 * '<S46>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem/Bit Shift1'
 * '<S47>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem/Bit Shift/bit_shift'
 * '<S48>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem/Bit Shift1/bit_shift'
 * '<S49>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read'
 * '<S50>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read'
 * '<S51>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read/Bit Shift'
 * '<S52>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read/Bit Shift1'
 * '<S53>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read/Bit Shift/bit_shift'
 * '<S54>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read/Bit Shift1/bit_shift'
 * '<S55>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read/Bit Shift'
 * '<S56>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read/Bit Shift1'
 * '<S57>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read/Bit Shift/bit_shift'
 * '<S58>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read/Bit Shift1/bit_shift'
 * '<S59>'  : 'PMSM_to_BLDC_mod1/Timer/FOC'
 * '<S60>'  : 'PMSM_to_BLDC_mod1/Timer/PWM Output'
 * '<S61>'  : 'PMSM_to_BLDC_mod1/Timer/Pulse to timer '
 * '<S62>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm '
 * '<S63>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter'
 * '<S64>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls'
 * '<S65>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Subsystem1'
 * '<S66>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform'
 * '<S67>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle'
 * '<S68>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Subsystem1'
 * '<S69>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Clarke Transform'
 * '<S70>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control'
 * '<S71>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1'
 * '<S72>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator'
 * '<S73>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform'
 * '<S74>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Position_Model'
 * '<S75>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/wrapping Mod'
 * '<S76>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Clarke Transform/Variant'
 * '<S77>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Clarke Transform/Variant/mcb'
 * '<S78>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Clarke Transform/Variant/mcb/Clarke Transform'
 * '<S79>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Clarke Transform/Variant/mcb/Clarke Transform/Three phase input'
 * '<S80>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq'
 * '<S81>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id'
 * '<S82>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID'
 * '<S83>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Anti-windup'
 * '<S84>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/D Gain'
 * '<S85>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/External Derivative'
 * '<S86>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Filter'
 * '<S87>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Filter ICs'
 * '<S88>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/I Gain'
 * '<S89>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Ideal P Gain'
 * '<S90>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Ideal P Gain Fdbk'
 * '<S91>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Integrator'
 * '<S92>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Integrator ICs'
 * '<S93>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/N Copy'
 * '<S94>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/N Gain'
 * '<S95>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/P Copy'
 * '<S96>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Parallel P Gain'
 * '<S97>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Reset Signal'
 * '<S98>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Saturation'
 * '<S99>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Saturation Fdbk'
 * '<S100>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Sum'
 * '<S101>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Sum Fdbk'
 * '<S102>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tracking Mode'
 * '<S103>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tracking Mode Sum'
 * '<S104>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tsamp - Integral'
 * '<S105>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tsamp - Ngain'
 * '<S106>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/postSat Signal'
 * '<S107>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/preInt Signal'
 * '<S108>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/preSat Signal'
 * '<S109>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel'
 * '<S110>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S111>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S112>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/D Gain/Disabled'
 * '<S113>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/External Derivative/Disabled'
 * '<S114>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Filter/Disabled'
 * '<S115>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Filter ICs/Disabled'
 * '<S116>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/I Gain/External Parameters'
 * '<S117>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Ideal P Gain/Passthrough'
 * '<S118>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Ideal P Gain Fdbk/Disabled'
 * '<S119>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Integrator/Discrete'
 * '<S120>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Integrator ICs/External IC'
 * '<S121>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/N Copy/Disabled wSignal Specification'
 * '<S122>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/N Gain/Disabled'
 * '<S123>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/P Copy/Disabled'
 * '<S124>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Parallel P Gain/External Parameters'
 * '<S125>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Reset Signal/External Reset'
 * '<S126>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Saturation/Enabled'
 * '<S127>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Saturation Fdbk/Disabled'
 * '<S128>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Sum/Sum_PI'
 * '<S129>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Sum Fdbk/Disabled'
 * '<S130>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tracking Mode/Disabled'
 * '<S131>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tracking Mode Sum/Passthrough'
 * '<S132>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tsamp - Integral/TsSignalSpecification'
 * '<S133>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tsamp - Ngain/Passthrough'
 * '<S134>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/postSat Signal/Forward_Path'
 * '<S135>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/preInt Signal/Internal PreInt'
 * '<S136>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/preSat Signal/Forward_Path'
 * '<S137>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID'
 * '<S138>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Anti-windup'
 * '<S139>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/D Gain'
 * '<S140>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/External Derivative'
 * '<S141>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Filter'
 * '<S142>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Filter ICs'
 * '<S143>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/I Gain'
 * '<S144>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Ideal P Gain'
 * '<S145>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Ideal P Gain Fdbk'
 * '<S146>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Integrator'
 * '<S147>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Integrator ICs'
 * '<S148>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/N Copy'
 * '<S149>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/N Gain'
 * '<S150>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/P Copy'
 * '<S151>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Parallel P Gain'
 * '<S152>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Reset Signal'
 * '<S153>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Saturation'
 * '<S154>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Saturation Fdbk'
 * '<S155>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Sum'
 * '<S156>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Sum Fdbk'
 * '<S157>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tracking Mode'
 * '<S158>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tracking Mode Sum'
 * '<S159>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tsamp - Integral'
 * '<S160>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tsamp - Ngain'
 * '<S161>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/postSat Signal'
 * '<S162>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/preInt Signal'
 * '<S163>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/preSat Signal'
 * '<S164>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel'
 * '<S165>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S166>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S167>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/D Gain/Disabled'
 * '<S168>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/External Derivative/Disabled'
 * '<S169>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Filter/Disabled'
 * '<S170>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Filter ICs/Disabled'
 * '<S171>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/I Gain/External Parameters'
 * '<S172>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Ideal P Gain/Passthrough'
 * '<S173>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Ideal P Gain Fdbk/Disabled'
 * '<S174>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Integrator/Discrete'
 * '<S175>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Integrator ICs/External IC'
 * '<S176>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/N Copy/Disabled wSignal Specification'
 * '<S177>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/N Gain/Disabled'
 * '<S178>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/P Copy/Disabled'
 * '<S179>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Parallel P Gain/External Parameters'
 * '<S180>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Reset Signal/External Reset'
 * '<S181>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Saturation/Enabled'
 * '<S182>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Saturation Fdbk/Disabled'
 * '<S183>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Sum/Sum_PI'
 * '<S184>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Sum Fdbk/Disabled'
 * '<S185>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tracking Mode/Disabled'
 * '<S186>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tracking Mode Sum/Passthrough'
 * '<S187>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tsamp - Integral/TsSignalSpecification'
 * '<S188>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tsamp - Ngain/Passthrough'
 * '<S189>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/postSat Signal/Forward_Path'
 * '<S190>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/preInt Signal/Internal PreInt'
 * '<S191>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/preSat Signal/Forward_Path'
 * '<S192>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant'
 * '<S193>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb'
 * '<S194>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform'
 * '<S195>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine'
 * '<S196>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Three inputs'
 * '<S197>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup'
 * '<S198>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/Interpolation'
 * '<S199>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp'
 * '<S200>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/datatype'
 * '<S201>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S202>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S203>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S204>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S205>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Three inputs/Two inputs CRL'
 * '<S206>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Three inputs/Two inputs CRL/Switch_Axis'
 * '<S207>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Modulation method'
 * '<S208>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input'
 * '<S209>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Modulation method/SVPWM'
 * '<S210>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S211>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input/Valphabeta'
 * '<S212>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S213>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Variant'
 * '<S214>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Variant/mcb'
 * '<S215>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Variant/mcb/Inverse Clarke Transform'
 * '<S216>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Variant/mcb/Inverse Clarke Transform/Two phase input'
 * '<S217>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant'
 * '<S218>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb'
 * '<S219>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform'
 * '<S220>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine'
 * '<S221>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Three inputs'
 * '<S222>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup'
 * '<S223>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S224>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S225>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S226>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S227>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S228>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S229>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S230>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S231>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Three inputs/Two inputs CRL'
 * '<S232>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Three inputs/Two inputs CRL/Switch_Axis'
 * '<S233>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Phase current Mesurement'
 * '<S234>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement'
 * '<S235>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer'
 * '<S236>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer'
 * '<S237>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/IIR Filter'
 * '<S238>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer'
 * '<S239>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)'
 * '<S240>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem'
 * '<S241>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem2'
 * '<S242>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/A11'
 * '<S243>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/A12'
 * '<S244>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/A22'
 * '<S245>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/L'
 * '<S246>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/L1'
 * '<S247>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/L2'
 * '<S248>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem2/B'
 * '<S249>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem2/L'
 * '<S250>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/IIR Filter/IIR Filter'
 * '<S251>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S252>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S253>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/Direction_Latch'
 * '<S254>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL'
 * '<S255>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/Direction_Latch/Dir_Sense'
 * '<S256>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/Direction_Latch/Subsystem2'
 * '<S257>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/Direction_Latch/Subsystem3'
 * '<S258>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/IIR Filter'
 * '<S259>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Normalize'
 * '<S260>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller'
 * '<S261>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward'
 * '<S262>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Subsystem'
 * '<S263>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO'
 * '<S264>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter'
 * '<S265>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter/Low-pass'
 * '<S266>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S267>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Normalize/Compare To Zero'
 * '<S268>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Normalize/If Action Subsystem'
 * '<S269>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Normalize/Subsystem'
 * '<S270>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Anti-windup'
 * '<S271>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/D Gain'
 * '<S272>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/External Derivative'
 * '<S273>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter'
 * '<S274>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter ICs'
 * '<S275>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/I Gain'
 * '<S276>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain'
 * '<S277>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain Fdbk'
 * '<S278>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator'
 * '<S279>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator ICs'
 * '<S280>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Copy'
 * '<S281>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Gain'
 * '<S282>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/P Copy'
 * '<S283>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Parallel P Gain'
 * '<S284>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Reset Signal'
 * '<S285>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation'
 * '<S286>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation Fdbk'
 * '<S287>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum'
 * '<S288>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum Fdbk'
 * '<S289>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode'
 * '<S290>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode Sum'
 * '<S291>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Integral'
 * '<S292>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Ngain'
 * '<S293>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/postSat Signal'
 * '<S294>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/preInt Signal'
 * '<S295>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/preSat Signal'
 * '<S296>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Anti-windup/Passthrough'
 * '<S297>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/D Gain/Disabled'
 * '<S298>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/External Derivative/Disabled'
 * '<S299>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter/Disabled'
 * '<S300>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter ICs/Disabled'
 * '<S301>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/I Gain/Internal Parameters'
 * '<S302>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain/Passthrough'
 * '<S303>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S304>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator/Discrete'
 * '<S305>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator ICs/Internal IC'
 * '<S306>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S307>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Gain/Disabled'
 * '<S308>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/P Copy/Disabled'
 * '<S309>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S310>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Reset Signal/External Reset'
 * '<S311>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation/Passthrough'
 * '<S312>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation Fdbk/Disabled'
 * '<S313>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum/Sum_PI'
 * '<S314>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum Fdbk/Disabled'
 * '<S315>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode/Disabled'
 * '<S316>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S317>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S318>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S319>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/postSat Signal/Forward_Path'
 * '<S320>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/preInt Signal/Internal PreInt'
 * '<S321>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/preSat Signal/Forward_Path'
 * '<S322>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/GainSystem'
 * '<S323>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter'
 * '<S324>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/InpFilterFunc'
 * '<S325>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod'
 * '<S326>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/Nofunc'
 * '<S327>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/NofuncSpd'
 * '<S328>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod'
 * '<S329>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/SpdFilterFunc'
 * '<S330>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/GainSystem/IGains'
 * '<S331>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/GainSystem/ODGains'
 * '<S332>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/GainSystem/OutDTSetup'
 * '<S333>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter/IIR Filter'
 * '<S334>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter/IIR Filter/Low-pass'
 * '<S335>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S336>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1'
 * '<S337>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3'
 * '<S338>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/Integrator'
 * '<S339>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/Integrator2'
 * '<S340>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter'
 * '<S341>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S342>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S343>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter'
 * '<S344>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S345>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S346>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/Differentiator'
 * '<S347>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/Differentiator1'
 * '<S348>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1'
 * '<S349>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3'
 * '<S350>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter'
 * '<S351>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S352>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S353>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter'
 * '<S354>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S355>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S356>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Subsystem/If Action Subsystem'
 * '<S357>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Subsystem/If Action Subsystem1'
 * '<S358>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem'
 * '<S359>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased'
 * '<S360>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Position Generator'
 * '<S361>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup'
 * '<S362>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S363>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S364>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S365>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S366>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S367>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S368>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S369>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype backpropogation'
 * '<S370>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Codegen'
 * '<S371>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation'
 * '<S372>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Codegen/Subsystem'
 * '<S373>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Codegen/Subsystem/Gate_Inverter1'
 * '<S374>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model'
 * '<S375>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Average-Value Inverter'
 * '<S376>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model'
 * '<S377>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM'
 * '<S378>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous'
 * '<S379>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core'
 * '<S380>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Mechanical and Angle'
 * '<S381>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1'
 * '<S382>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic'
 * '<S383>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/MechToElect'
 * '<S384>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/Power Accounting Bus Creator'
 * '<S385>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/Power Accounting Bus Creator/PwrNotTrnsfrd Input'
 * '<S386>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/Power Accounting Bus Creator/PwrStored Input'
 * '<S387>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/Power Accounting Bus Creator/PwrTrnsfrd Input'
 * '<S388>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Clarke Transform'
 * '<S389>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Inverse Clarke Transform'
 * '<S390>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Inverse Park Transform'
 * '<S391>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Machine Torque'
 * '<S392>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit'
 * '<S393>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Park Transform'
 * '<S394>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Machine Torque/Subsystem'
 * '<S395>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage'
 * '<S396>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage'
 * '<S397>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem'
 * '<S398>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem1'
 * '<S399>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem2'
 * '<S400>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem'
 * '<S401>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem1'
 * '<S402>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem2'
 * '<S403>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem3'
 * '<S404>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control'
 * '<S405>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller'
 * '<S406>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Anti-windup'
 * '<S407>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/D Gain'
 * '<S408>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/External Derivative'
 * '<S409>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Filter'
 * '<S410>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Filter ICs'
 * '<S411>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/I Gain'
 * '<S412>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Ideal P Gain'
 * '<S413>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Ideal P Gain Fdbk'
 * '<S414>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Integrator'
 * '<S415>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Integrator ICs'
 * '<S416>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/N Copy'
 * '<S417>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/N Gain'
 * '<S418>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/P Copy'
 * '<S419>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Parallel P Gain'
 * '<S420>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Reset Signal'
 * '<S421>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Saturation'
 * '<S422>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Saturation Fdbk'
 * '<S423>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Sum'
 * '<S424>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Sum Fdbk'
 * '<S425>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Tracking Mode'
 * '<S426>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Tracking Mode Sum'
 * '<S427>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Tsamp - Integral'
 * '<S428>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Tsamp - Ngain'
 * '<S429>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/postSat Signal'
 * '<S430>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/preInt Signal'
 * '<S431>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/preSat Signal'
 * '<S432>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Anti-windup/Passthrough'
 * '<S433>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/D Gain/Disabled'
 * '<S434>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/External Derivative/Disabled'
 * '<S435>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Filter/Disabled'
 * '<S436>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Filter ICs/Disabled'
 * '<S437>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/I Gain/Internal Parameters'
 * '<S438>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Ideal P Gain/Passthrough'
 * '<S439>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S440>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Integrator/Continuous'
 * '<S441>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Integrator ICs/Internal IC'
 * '<S442>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S443>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/N Gain/Disabled'
 * '<S444>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/P Copy/Disabled'
 * '<S445>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S446>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Reset Signal/Disabled'
 * '<S447>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Saturation/Passthrough'
 * '<S448>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Saturation Fdbk/Disabled'
 * '<S449>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Sum/Sum_PI'
 * '<S450>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Sum Fdbk/Disabled'
 * '<S451>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Tracking Mode/Disabled'
 * '<S452>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S453>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S454>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S455>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/postSat Signal/Forward_Path'
 * '<S456>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/preInt Signal/Internal PreInt'
 * '<S457>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/preSat Signal/Forward_Path'
 * '<S458>' : 'PMSM_to_BLDC_mod1/Timer/PWM Output/ECSoC'
 * '<S459>' : 'PMSM_to_BLDC_mod1/Timer/PWM Output/ECSoC/ECSimCodegen'
 * '<S460>' : 'PMSM_to_BLDC_mod1/V_sense/Analog to Digital Converter1'
 * '<S461>' : 'PMSM_to_BLDC_mod1/V_sense/Analog to Digital Converter1/ECSoC'
 * '<S462>' : 'PMSM_to_BLDC_mod1/V_sense/Analog to Digital Converter1/ECSoC/ECSimCodegen'
 */
#endif                                 /* PMSM_to_BLDC_mod1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
