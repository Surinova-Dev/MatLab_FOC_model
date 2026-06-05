/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.h
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

/* Block states (default storage) for system '<S22>/Bit Shift' */
typedef struct {
  int32_T sfEvent;                     /* '<S24>/bit_shift' */
  boolean_T doneDoubleBufferReInit;    /* '<S24>/bit_shift' */
} DW_BitShift_PMSM_to_BLDC_mod1_T;

/* Block states (default storage) for system '<S22>/Bit Shift1' */
typedef struct {
  int32_T sfEvent;                     /* '<S25>/bit_shift' */
  boolean_T doneDoubleBufferReInit;    /* '<S25>/bit_shift' */
} DW_BitShift1_PMSM_to_BLDC_mod_T;

/* Block states (default storage) for system '<S36>/SPI Receive' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S36>/SPI Receive' */
  boolean_T objisempty;                /* '<S36>/SPI Receive' */
} DW_SPIReceive_PMSM_to_BLDC_mo_T;

/* Block states (default storage) for system '<S36>/SPI Transmit' */
typedef struct {
  stm32cube_blocks_SPIControl_d_T obj; /* '<S36>/SPI Transmit' */
  boolean_T objisempty;                /* '<S36>/SPI Transmit' */
} DW_SPITransmit_PMSM_to_BLDC_m_T;

/* Block signals for system '<S37>/SPI Receive' */
typedef struct {
  uint16_T SPIReceive;                 /* '<S37>/SPI Receive' */
} B_SPIReceive_PMSM_to_BLDC_m_c_T;

/* Block states (default storage) for system '<S37>/SPI Receive' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S37>/SPI Receive' */
  boolean_T objisempty;                /* '<S37>/SPI Receive' */
} DW_SPIReceive_PMSM_to_BLDC__f_T;

/* Block signals for system '<S48>/SPI Receive' */
typedef struct {
  uint16_T SPIReceive[15];             /* '<S48>/SPI Receive' */
} B_SPIReceive_PMSM_to_BLDC__ca_T;

/* Block states (default storage) for system '<S48>/SPI Receive' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S48>/SPI Receive' */
  boolean_T objisempty;                /* '<S48>/SPI Receive' */
} DW_SPIReceive_PMSM_to_BLDC_fw_T;

/* Block states (default storage) for system '<S48>/SPI Transmit' */
typedef struct {
  stm32cube_blocks_SPIControl_d_T obj; /* '<S48>/SPI Transmit' */
  boolean_T objisempty;                /* '<S48>/SPI Transmit' */
} DW_SPITransmit_PMSM_to_BLDC_f_T;

/* Block states (default storage) for system '<S200>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S200>/If Action Subsystem' */
} DW_IfActionSubsystem_PMSM_to__T;

/* Block states (default storage) for system '<S200>/If Action Subsystem1' */
typedef struct {
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S200>/If Action Subsystem1' */
} DW_IfActionSubsystem1_PMSM_to_T;

/* Block signals (default storage) */
typedef struct {
  real_T Gain;                         /* '<S8>/Gain' */
  real_T Delay2[2];                    /* '<Root>/Delay2' */
  real_T RateTransition[2];            /* '<S58>/Rate Transition' */
  real_T DataTypeConversion[2];        /* '<S232>/Data Type  Conversion' */
  real_T Merge[2];                     /* '<S261>/Merge' */
  real_T Sum;                          /* '<S258>/Sum' */
  real_T Integrator;                   /* '<S303>/Integrator' */
  real_T DataTypeConversion_a;         /* '<S68>/Data Type Conversion' */
  real_T Mod;                          /* '<S74>/Mod' */
  real_T Saturation;                   /* '<S182>/Saturation' */
  real_T DataTypeConversion1;          /* '<S65>/Data Type Conversion1' */
  real_T ProportionalGain;             /* '<S444>/Proportional Gain' */
  real_T Sum_o;                        /* '<S448>/Sum' */
  real_T Saturation_f;                 /* '<S127>/Saturation' */
  real_T Gain_p[3];                    /* '<S209>/Gain' */
  real_T Gain_f[3];                    /* '<S67>/Gain' */
  real_T Gain5[3];                     /* '<S372>/Gain5' */
  real_T Gate_pulse[6];
  /* '<S63>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Codegen_at_outport_0Inport1' */
  real_T idq_ref[2];
  /* '<S58>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Speed_controls_at_outport_0Inport1' */
  real_T DataTypeConversion_e;         /* '<S75>/Data Type Conversion' */
  real_T DataTypeConversion1_i;        /* '<S75>/Data Type Conversion1' */
  real_T TmpSignalConversionAtDelayInpor[4];
                                /* '<S61>/TmpSignal ConversionAtDelayInport1' */
  real_T Int1;                         /* '<S379>/Int1' */
  real_T Gain_j;                       /* '<S373>/Gain' */
  real_T Gain2;                        /* '<S390>/Gain2' */
  real_T Gain1;                        /* '<S373>/Gain1' */
  real_T VectorConcatenate[3];         /* '<S378>/Vector Concatenate' */
  real_T DataTypeConversion_c[3];      /* '<S373>/Data Type Conversion' */
  real_T Product[3];                   /* '<S374>/Product' */
  real_T Add;                          /* '<S387>/Add' */
  real_T Add1;                         /* '<S387>/Add1' */
  real_T Add_h;                        /* '<S394>/Add' */
  real_T Add_d;                        /* '<S395>/Add' */
  real_T IntegralGain;                 /* '<S436>/Integral Gain' */
  real_T Ref_angular_vel;              /* '<S58>/Constant' */
  real_T Gain2_b;                      /* '<S64>/Gain2' */
  real_T Gain1_e;                      /* '<S375>/Gain1' */
  real_T Constant;                     /* '<S65>/Constant' */
  real_T algDD_o1;                     /* '<S221>/algDD' */
  real_T algDD_o2;                     /* '<S221>/algDD' */
  real_T algDD_o1_d;                   /* '<S197>/algDD' */
  real_T algDD_o2_a;                   /* '<S197>/algDD' */
  real_T Gain1_m;                      /* '<S12>/Gain1' */
  real_T Gain_k;                       /* '<S11>/Gain' */
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
  real_T spi_stat_1;                   /* '<Root>/Chart' */
  real_T spi_stat_2;                   /* '<Root>/Chart' */
  real32_T W_mes;                      /* '<S58>/Delay1' */
  real32_T SpeedGain;                  /* '<S234>/SpeedGain' */
  real32_T Gain3;                      /* '<S58>/Gain3' */
  real32_T DataTypeConversion_i;       /* '<S65>/Data Type Conversion' */
  uint16_T AnalogtoDigitalConverter;  /* '<S461>/Analog to Digital Converter' */
  uint16_T BitwiseOR;                  /* '<S49>/Bitwise OR' */
  uint16_T BitwiseOR_p;                /* '<S48>/Bitwise OR' */
  uint16_T DataTypeConversion_d;       /* '<S48>/Data Type Conversion' */
  uint16_T BitwiseOR_o;                /* '<S42>/Bitwise OR' */
  uint16_T BitwiseOR_h;                /* '<S36>/Bitwise OR' */
  uint16_T BitwiseOR_e;                /* '<S23>/Bitwise OR' */
  uint16_T BitwiseOR_n;                /* '<S22>/Bitwise OR' */
  uint16_T DataTypeConversion_m;       /* '<S22>/Data Type Conversion' */
  int16_T Switch;                      /* '<S254>/Switch' */
  boolean_T Delay;                     /* '<Root>/Delay' */
  boolean_T Delay1;                    /* '<Root>/Delay1' */
  boolean_T Compare;                   /* '<S266>/Compare' */
  boolean_T Compare_g;                 /* '<S32>/Compare' */
  boolean_T Compare_a;                 /* '<S33>/Compare' */
  boolean_T AND1;                      /* '<S4>/AND1' */
  boolean_T AND;                       /* '<S4>/AND' */
  B_SPIReceive_PMSM_to_BLDC__ca_T SPIReceive_pnaevv;/* '<S48>/SPI Receive' */
  B_SPIReceive_PMSM_to_BLDC__ca_T SPIReceive_pnaev;/* '<S48>/SPI Receive' */
  B_SPIReceive_PMSM_to_BLDC_m_c_T SPIReceive_pnae;/* '<S37>/SPI Receive' */
  B_SPIReceive_PMSM_to_BLDC_m_c_T SPIReceive_pn;/* '<S37>/SPI Receive' */
} B_PMSM_to_BLDC_mod1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_LowpassFilter_PM_T obj; /* '<S2>/Lowpass Filter' */
  stm32cube_blocks_SPIControlle_T obj_g;/* '<S23>/SPI Receive' */
  stm32cube_blocks_SPIControlle_T obj_gk;/* '<S22>/SPI Receive' */
  stm32cube_blocks_SPIControl_d_T obj_n;/* '<S23>/SPI Transmit' */
  stm32cube_blocks_SPIControl_d_T obj_j;/* '<S22>/SPI Transmit' */
  stm32cube_blocks_AnalogInput__T obj_p;
                                      /* '<S461>/Analog to Digital Converter' */
  stm32cube_blocks_AnalogInput__T obj_o;/* '<S18>/Analog to Digital Converter' */
  stm32cube_blocks_AnalogInput__T obj_d;/* '<S15>/Analog to Digital Converter' */
  stm32cube_blocks_DigitalPortW_T obj_ow;/* '<S21>/Digital Port Write' */
  stm32cube_blocks_PWMOutput_PM_T obj_e;/* '<S458>/PWM Output' */
  real_T Delay2_DSTATE;                /* '<Root>/Delay2' */
  real_T Delay_DSTATE[8];              /* '<S61>/Delay' */
  real_T Delay_DSTATE_c[2];            /* '<S238>/Delay' */
  real_T Delay_DSTATE_k[2];            /* '<S251>/Delay' */
  real_T Delay_DSTATE_a;               /* '<S334>/Delay' */
  real_T Delay_DSTATE_aj;              /* '<S358>/Delay' */
  real_T Integrator_DSTATE;            /* '<S303>/Integrator' */
  real_T Delay_DSTATE_ai;              /* '<S359>/Delay' */
  real_T Integrator_DSTATE_b;          /* '<S175>/Integrator' */
  real_T Integrator_DSTATE_n;          /* '<S120>/Integrator' */
  real_T Delay_DSTATE_g;               /* '<S265>/Delay' */
  real_T Delay2_DSTATE_h;              /* '<S345>/Delay2' */
  real_T Delay3_DSTATE;                /* '<S345>/Delay3' */
  real_T Delay_DSTATE_l;               /* '<S354>/Delay' */
  real_T Delay2_DSTATE_n;              /* '<S346>/Delay2' */
  real_T Delay3_DSTATE_f;              /* '<S346>/Delay3' */
  real_T Delay_DSTATE_aa;              /* '<S351>/Delay' */
  real_T Delay_DSTATE_d;               /* '<S344>/Delay' */
  real_T Delay1_DSTATE;                /* '<S337>/Delay1' */
  real_T Delay_DSTATE_i;               /* '<S337>/Delay' */
  real_T Delay_DSTATE_av;              /* '<S341>/Delay' */
  real_T Delay1_DSTATE_k;              /* '<S338>/Delay1' */
  real_T Delay_DSTATE_f;               /* '<S338>/Delay' */
  real_T RateTransition_Buffer0[2];    /* '<S58>/Rate Transition' */
  real_T CS_val;                       /* '<Root>/Chart' */
  real_T Drv_ok;                       /* '<Root>/Chart' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S8>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S8>/Scope1' */

  struct {
    void *LoggedData[8];
  } Scope_PWORK_i;                     /* '<Root>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK_n;                    /* '<Root>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_h;                     /* '<S6>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK_b;                    /* '<S6>/Scope1' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_c;                    /* '<S64>/Scope1' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_d;                    /* '<S65>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_k;                     /* '<S58>/Scope' */

  struct {
    void *LoggedData;
  } TimeScope1_PWORK;                  /* '<S58>/Time Scope1' */

  struct {
    void *LoggedData;
  } TimeScope2_PWORK;                  /* '<S58>/Time Scope2' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_g;                     /* '<S61>/Scope' */

  struct {
    void *LoggedData[3];
  } Scope1_PWORK_p;                    /* '<S61>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_hn;                    /* '<S66>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK_c2;                   /* '<S66>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_d;                     /* '<S74>/Scope' */

  struct {
    void *LoggedData[6];
  } Scope_PWORK_e;                     /* '<S369>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_a;                     /* '<S370>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_m;                     /* '<S373>/Scope' */

  struct {
    void *LoggedData[3];
  } Scope_PWORK_o;                     /* '<S375>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_b;                     /* '<S65>/Scope' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S65>/Scope2' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_hj;                    /* '<S5>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope2_PWORK_e;                    /* '<S5>/Scope2' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_hp;                    /* '<S4>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_c;                     /* '<S12>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_do;                    /* '<S11>/Scope' */

  real32_T Delay1_DSTATE_f;            /* '<S234>/Delay1' */
  real32_T Delay1_DSTATE_fx;           /* '<S58>/Delay1' */
  uint32_T is_Test2;                   /* '<Root>/Chart' */
  uint32_T is_Test;                    /* '<Root>/Chart' */
  uint32_T is_Test2_d;                 /* '<Root>/Chart' */
  uint16_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint16_T temporalCounter_i2;         /* '<Root>/Chart' */
  uint16_T temporalCounter_i3;         /* '<Root>/Chart' */
  boolean_T Delay_DSTATE_cn;           /* '<Root>/Delay' */
  boolean_T Delay1_DSTATE_fv;          /* '<Root>/Delay1' */
  int8_T Timer_SubsysRanBC;            /* '<Root>/Timer' */
  int8_T If_ActiveSubsystem;           /* '<S252>/If' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S261>/Switch Case' */
  int8_T If_ActiveSubsystem_g;         /* '<S258>/If' */
  int8_T SwitchCase_ActiveSubsystem_n; /* '<S260>/Switch Case' */
  int8_T If_ActiveSubsystem_e;         /* '<S363>/If' */
  int8_T Integrator_PrevResetState;    /* '<S303>/Integrator' */
  int8_T If_ActiveSubsystem_c;         /* '<S225>/If' */
  int8_T Integrator_PrevResetState_n;  /* '<S175>/Integrator' */
  int8_T Integrator_PrevResetState_nt; /* '<S120>/Integrator' */
  int8_T If_ActiveSubsystem_m;         /* '<S200>/If' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S363>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S363>/If Action Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanB_e;/* '<S261>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_a;/* '<S261>/If Action Subsystem' */
  int8_T OptimizedDifferentiationMethod_;
                                   /* '<S260>/OptimizedDifferentiationMethod' */
  int8_T IntegralMethod_SubsysRanBC;   /* '<S260>/IntegralMethod' */
  int8_T IfActionSubsystem_SubsysRanBC_b;/* '<S258>/If Action Subsystem' */
  int8_T Subsystem_SubsysRanBC;        /* '<S258>/Subsystem' */
  int8_T Subsystem3_SubsysRanBC;       /* '<S252>/Subsystem3' */
  int8_T Subsystem2_SubsysRanBC;       /* '<S252>/Subsystem2' */
  int8_T Dir_Sense_SubsysRanBC;        /* '<S252>/Dir_Sense' */
  int8_T Status_Reg_2_read_SubsysRanBC;/* '<S6>/Status_Reg_2_read' */
  int8_T Status_Reg1_read_SubsysRanBC; /* '<S6>/Status_Reg1_read' */
  int8_T Subsystem1_SubsysRanBC;       /* '<S35>/Subsystem1' */
  int8_T Subsystem_SubsysRanBC_f;      /* '<S35>/Subsystem' */
  int8_T Subsystem1_SubsysRanBC_n;     /* '<S34>/Subsystem1' */
  int8_T Subsystem_SubsysRanBC_i;      /* '<S34>/Subsystem' */
  int8_T Ctrl_Reg_1_SubsysRanBC;       /* '<S4>/Ctrl_Reg_1' */
  int8_T Control_Reg2_SubsysRanBC;     /* '<S4>/Control_Reg2' */
  int8_T Subsystem1_SubsysRanBC_c;     /* '<S2>/Subsystem1' */
  int8_T Subsystem_SubsysRanBC_g;      /* '<S2>/Subsystem' */
  uint8_T is_active_c3_PMSM_to_BLDC_mod1;/* '<Root>/Chart' */
  uint8_T is_active_Test2;             /* '<Root>/Chart' */
  uint8_T is_active_Test;              /* '<Root>/Chart' */
  uint8_T is_active_Test2_e;           /* '<Root>/Chart' */
  boolean_T icLoad;                    /* '<S251>/Delay' */
  boolean_T AlphaRelay_Mode;           /* '<S252>/AlphaRelay' */
  boolean_T BetaRelay_Mode;            /* '<S252>/BetaRelay' */
  boolean_T icLoad_f;                  /* '<S334>/Delay' */
  boolean_T icLoad_a;                  /* '<S359>/Delay' */
  boolean_T icLoad_b;                  /* '<S265>/Delay' */
  boolean_T Integrator_DWORK1;         /* '<S394>/Integrator' */
  boolean_T Integrator_DWORK1_g;       /* '<S395>/Integrator' */
  boolean_T icLoad_c;                  /* '<S354>/Delay' */
  boolean_T icLoad_b1;                 /* '<S351>/Delay' */
  boolean_T icLoad_k;                  /* '<S344>/Delay' */
  boolean_T icLoad_bd;                 /* '<S341>/Delay' */
  boolean_T isInitialized;             /* '<S2>/Lowpass Filter' */
  boolean_T isInitialized_g;           /* '<S2>/Lowpass Filter' */
  boolean_T Timer_MODE;                /* '<Root>/Timer' */
  boolean_T Status_Reg_2_read_MODE;    /* '<S6>/Status_Reg_2_read' */
  boolean_T Status_Reg1_read_MODE;     /* '<S6>/Status_Reg1_read' */
  boolean_T Subsystem1_MODE;           /* '<S35>/Subsystem1' */
  boolean_T Subsystem_MODE;            /* '<S35>/Subsystem' */
  boolean_T Subsystem1_MODE_m;         /* '<S34>/Subsystem1' */
  boolean_T Subsystem_MODE_f;          /* '<S34>/Subsystem' */
  boolean_T Ctrl_Reg_1_MODE;           /* '<S4>/Ctrl_Reg_1' */
  boolean_T Control_Reg2_MODE;         /* '<S4>/Control_Reg2' */
  boolean_T Subsystem1_MODE_b;         /* '<S2>/Subsystem1' */
  boolean_T Subsystem_MODE_n;          /* '<S2>/Subsystem' */
  DW_IfActionSubsystem1_PMSM_to_T IfActionSubsystem1_j;/* '<S225>/If Action Subsystem1' */
  DW_IfActionSubsystem_PMSM_to__T IfActionSubsystem_d;/* '<S225>/If Action Subsystem' */
  DW_IfActionSubsystem1_PMSM_to_T IfActionSubsystem1;/* '<S200>/If Action Subsystem1' */
  DW_IfActionSubsystem_PMSM_to__T IfActionSubsystem;/* '<S200>/If Action Subsystem' */
  DW_SPITransmit_PMSM_to_BLDC_f_T SPITransmit_pnaevv;/* '<S48>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC_fw_T SPIReceive_pnaevv;/* '<S48>/SPI Receive' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1_o;/* '<S49>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift_n;/* '<S49>/Bit Shift' */
  DW_SPITransmit_PMSM_to_BLDC_f_T SPITransmit_pnaev;/* '<S48>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC_fw_T SPIReceive_pnaev;/* '<S48>/SPI Receive' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1_j;/* '<S48>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift_p;/* '<S48>/Bit Shift' */
  DW_SPITransmit_PMSM_to_BLDC_m_T SPITransmit_pnae;/* '<S36>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC__f_T SPIReceive_pnae;/* '<S37>/SPI Receive' */
  DW_SPITransmit_PMSM_to_BLDC_m_T SPITransmit_pna;/* '<S36>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC_mo_T SPIReceive_pna;/* '<S36>/SPI Receive' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1_m;/* '<S42>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift_b;/* '<S42>/Bit Shift' */
  DW_SPITransmit_PMSM_to_BLDC_m_T SPITransmit_pn;/* '<S36>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC__f_T SPIReceive_pn;/* '<S37>/SPI Receive' */
  DW_SPITransmit_PMSM_to_BLDC_m_T SPITransmit_p;/* '<S36>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC_mo_T SPIReceive_p;/* '<S36>/SPI Receive' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1_p;/* '<S36>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift_hq;/* '<S36>/Bit Shift' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1_d;/* '<S23>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift_h;/* '<S23>/Bit Shift' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1;/* '<S22>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift;/* '<S22>/Bit Shift' */
} DW_PMSM_to_BLDC_mod1_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S439>/Integrator' */
  real_T Int1_CSTATE;                  /* '<S379>/Int1' */
  real_T Integrator_CSTATE_d;          /* '<S394>/Integrator' */
  real_T Integrator_CSTATE_l;          /* '<S395>/Integrator' */
} X_PMSM_to_BLDC_mod1_T;

/* Periodic continuous state vector (global) */
typedef int_T PeriodicIndX_PMSM_to_BLDC_mod_T[1];
typedef real_T PeriodicRngX_PMSM_to_BLDC_mod_T[2];

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S439>/Integrator' */
  real_T Int1_CSTATE;                  /* '<S379>/Int1' */
  real_T Integrator_CSTATE_d;          /* '<S394>/Integrator' */
  real_T Integrator_CSTATE_l;          /* '<S395>/Integrator' */
} XDot_PMSM_to_BLDC_mod1_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S439>/Integrator' */
  boolean_T Int1_CSTATE;               /* '<S379>/Int1' */
  boolean_T Integrator_CSTATE_d;       /* '<S394>/Integrator' */
  boolean_T Integrator_CSTATE_l;       /* '<S395>/Integrator' */
} XDis_PMSM_to_BLDC_mod1_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Delay1_Reset_ZCE;         /* '<S234>/Delay1' */
  ZCSigState Delay_Reset_ZCE;          /* '<S238>/Delay' */
  ZCSigState Delay_Reset_ZCE_a;        /* '<S358>/Delay' */
  ZCSigState Delay2_Reset_ZCE;         /* '<S345>/Delay2' */
  ZCSigState Delay3_Reset_ZCE;         /* '<S345>/Delay3' */
  ZCSigState Delay2_Reset_ZCE_l;       /* '<S346>/Delay2' */
  ZCSigState Delay3_Reset_ZCE_m;       /* '<S346>/Delay3' */
  ZCSigState Delay1_Reset_ZCE_i;       /* '<S337>/Delay1' */
  ZCSigState Delay_Reset_ZCE_k;        /* '<S337>/Delay' */
  ZCSigState Delay1_Reset_ZCE_p;       /* '<S338>/Delay1' */
  ZCSigState Delay_Reset_ZCE_h;        /* '<S338>/Delay' */
  ZCSigState Dir_Sense_Trig_ZCE;       /* '<S252>/Dir_Sense' */
} PrevZCX_PMSM_to_BLDC_mod1_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Constant3;              /* '<S81>/Constant3' */
  const real_T Constant3_n;            /* '<S82>/Constant3' */
  const real_T Switch;                 /* '<S374>/Switch' */
  const real_T Gain;                   /* '<S379>/Gain' */
  const real_T IndexVector;            /* '<S393>/Index Vector' */
  const real_T IndexVector1;           /* '<S393>/Index Vector1' */
  const real_T Add;                    /* '<S393>/Add' */
  const real_T IndexVector_a;          /* '<S394>/Index Vector' */
  const real_T IndexVector_b;          /* '<S396>/Index Vector' */
  const real_T IndexVector_ah;         /* '<S397>/Index Vector' */
  const real_T IndexVector1_e;         /* '<S397>/Index Vector1' */
  const real_T IndexVector_j;          /* '<S398>/Index Vector' */
  const real_T IndexVector_d;          /* '<S395>/Index Vector' */
  const real_T IndexVector_k;          /* '<S399>/Index Vector' */
  const real_T IndexVector_m;          /* '<S400>/Index Vector' */
  const real_T IndexVector1_g;         /* '<S400>/Index Vector1' */
  const real_T IndexVector_bt;         /* '<S401>/Index Vector' */
  const real_T Product;                /* '<S401>/Product' */
  const real_T IndexVector_d3;         /* '<S402>/Index Vector' */
  const uint32_T DataTypeConversion;   /* '<S261>/Data Type Conversion' */
  const uint16_T BitwiseAND;           /* '<S49>/Bitwise AND' */
  const uint16_T BitwiseAND_m;         /* '<S48>/Bitwise AND' */
  const uint16_T BitwiseAND_j;         /* '<S42>/Bitwise AND' */
  const uint16_T BitwiseAND_d;         /* '<S36>/Bitwise AND' */
  const uint16_T BitwiseAND_e;         /* '<S23>/Bitwise AND' */
  const uint16_T BitwiseAND_jx;        /* '<S22>/Bitwise AND' */
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
   *   '<S198>/sine_table_values'
   *   '<S223>/sine_table_values'
   */
  real_T pooled16[1002];

  /* Computed Parameter: sine_table_values_Value
   * Referenced by: '<S361>/sine_table_values'
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
 * Block '<Root>/Delay3' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate' : Unused code path elimination
 * Block '<S71>/D' : Unused code path elimination
 * Block '<S198>/Data Type Duplicate' : Unused code path elimination
 * Block '<S198>/Data Type Propagation' : Unused code path elimination
 * Block '<S203>/Data Type Duplicate' : Unused code path elimination
 * Block '<S204>/Data Type Duplicate' : Unused code path elimination
 * Block '<S197>/Data Type Duplicate' : Unused code path elimination
 * Block '<S197>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Vc' : Unused code path elimination
 * Block '<S216>/Data Type Duplicate' : Unused code path elimination
 * Block '<S73>/D' : Unused code path elimination
 * Block '<S223>/Data Type Duplicate' : Unused code path elimination
 * Block '<S223>/Data Type Propagation' : Unused code path elimination
 * Block '<S228>/Data Type Duplicate' : Unused code path elimination
 * Block '<S229>/Data Type Duplicate' : Unused code path elimination
 * Block '<S221>/Data Type Duplicate' : Unused code path elimination
 * Block '<S221>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S234>/Data Type Propagation' : Unused code path elimination
 * Block '<S236>/Data Type Duplicate' : Unused code path elimination
 * Block '<S253>/Data Type Duplicate' : Unused code path elimination
 * Block '<S253>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S253>/Data Type Conversion' : Unused code path elimination
 * Block '<S253>/Data Type Conversion1' : Unused code path elimination
 * Block '<S257>/Data Type Duplicate' : Unused code path elimination
 * Block '<S258>/Data Type Duplicate' : Unused code path elimination
 * Block '<S258>/Data Type Propagation' : Unused code path elimination
 * Block '<S267>/Data Type Duplicate' : Unused code path elimination
 * Block '<S268>/Data Type Duplicate' : Unused code path elimination
 * Block '<S268>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S268>/Data Type Propagation' : Unused code path elimination
 * Block '<S260>/Data Type Duplicate' : Unused code path elimination
 * Block '<S260>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S321>/I1CnstDT' : Unused code path elimination
 * Block '<S321>/I2CnstDT' : Unused code path elimination
 * Block '<S329>/Bias' : Unused code path elimination
 * Block '<S329>/Bias1' : Unused code path elimination
 * Block '<S329>/Constant' : Unused code path elimination
 * Block '<S329>/Data Type Duplicate' : Unused code path elimination
 * Block '<S329>/Data Type Propagation' : Unused code path elimination
 * Block '<S329>/Data Type Propagation1' : Unused code path elimination
 * Block '<S329>/Divide' : Unused code path elimination
 * Block '<S329>/Divide1' : Unused code path elimination
 * Block '<S329>/OD1Cnst' : Unused code path elimination
 * Block '<S329>/OD1CnstDT' : Unused code path elimination
 * Block '<S329>/Product' : Unused code path elimination
 * Block '<S329>/Unary Minus' : Unused code path elimination
 * Block '<S321>/MaxFreqCnst' : Unused code path elimination
 * Block '<S321>/OD1CnstDT' : Unused code path elimination
 * Block '<S321>/OD2CnstDT' : Unused code path elimination
 * Block '<S330>/Bias' : Unused code path elimination
 * Block '<S330>/Constant' : Unused code path elimination
 * Block '<S330>/Data Type Duplicate' : Unused code path elimination
 * Block '<S330>/Data Type Propagation' : Unused code path elimination
 * Block '<S330>/Data Type Propagation1' : Unused code path elimination
 * Block '<S330>/Data Type Propagation2' : Unused code path elimination
 * Block '<S330>/Divide' : Unused code path elimination
 * Block '<S330>/OD1Cnst' : Unused code path elimination
 * Block '<S330>/OD1CnstDT' : Unused code path elimination
 * Block '<S330>/OD1CnstDT1' : Unused code path elimination
 * Block '<S330>/Product' : Unused code path elimination
 * Block '<S330>/Product1' : Unused code path elimination
 * Block '<S330>/SampleTime' : Unused code path elimination
 * Block '<S331>/Const' : Unused code path elimination
 * Block '<S331>/Data Type Propagation' : Unused code path elimination
 * Block '<S331>/Data Type Propagation1' : Unused code path elimination
 * Block '<S331>/MaxFreqDT' : Unused code path elimination
 * Block '<S331>/Product' : Unused code path elimination
 * Block '<S322>/Data Type Duplicate' : Unused code path elimination
 * Block '<S323>/Bias' : Unused code path elimination
 * Block '<S323>/Constant' : Unused code path elimination
 * Block '<S323>/Data Type Propagation' : Unused code path elimination
 * Block '<S323>/Data Type Propagation1' : Unused code path elimination
 * Block '<S323>/Divide' : Unused code path elimination
 * Block '<S323>/Product' : Unused code path elimination
 * Block '<S324>/Data Type Duplicate' : Unused code path elimination
 * Block '<S324>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S324>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S335>/Data Type Duplicate' : Unused code path elimination
 * Block '<S336>/Data Type Duplicate' : Unused code path elimination
 * Block '<S337>/Data Type Duplicate' : Unused code path elimination
 * Block '<S337>/Data Type Propagation' : Unused code path elimination
 * Block '<S337>/Data Type Propagation1' : Unused code path elimination
 * Block '<S338>/Data Type Duplicate' : Unused code path elimination
 * Block '<S338>/Data Type Propagation' : Unused code path elimination
 * Block '<S338>/Data Type Propagation1' : Unused code path elimination
 * Block '<S327>/Data Type Duplicate' : Unused code path elimination
 * Block '<S345>/Data Type Duplicate' : Unused code path elimination
 * Block '<S345>/Data Type Propagation' : Unused code path elimination
 * Block '<S346>/Data Type Duplicate' : Unused code path elimination
 * Block '<S346>/Data Type Propagation' : Unused code path elimination
 * Block '<S347>/Data Type Duplicate' : Unused code path elimination
 * Block '<S348>/Data Type Duplicate' : Unused code path elimination
 * Block '<S328>/Bias' : Unused code path elimination
 * Block '<S328>/Constant' : Unused code path elimination
 * Block '<S328>/Data Type Propagation' : Unused code path elimination
 * Block '<S328>/Data Type Propagation1' : Unused code path elimination
 * Block '<S328>/Divide' : Unused code path elimination
 * Block '<S328>/Product' : Unused code path elimination
 * Block '<S261>/Data Type Duplicate' : Unused code path elimination
 * Block '<S358>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S358>/Data Type Propagation' : Unused code path elimination
 * Block '<S359>/BooleanTypeCast' : Unused code path elimination
 * Block '<S359>/Data Type Duplicate' : Unused code path elimination
 * Block '<S359>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S359>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S359>/Data Type Duplicate3' : Unused code path elimination
 * Block '<S359>/Data Type Propagation' : Unused code path elimination
 * Block '<S359>/InpGainDatatype' : Unused code path elimination
 * Block '<S359>/OutGainDatatype' : Unused code path elimination
 * Block '<S359>/Reset' : Unused code path elimination
 * Block '<S361>/Data Type Duplicate' : Unused code path elimination
 * Block '<S361>/Data Type Propagation' : Unused code path elimination
 * Block '<S366>/Data Type Duplicate' : Unused code path elimination
 * Block '<S367>/Data Type Duplicate' : Unused code path elimination
 * Block '<S58>/Delay' : Unused code path elimination
 * Block '<S58>/Gain' : Unused code path elimination
 * Block '<S58>/Gain5' : Unused code path elimination
 * Block '<S379>/Constant' : Unused code path elimination
 * Block '<S380>/Add' : Unused code path elimination
 * Block '<S380>/Add2' : Unused code path elimination
 * Block '<S380>/Add4' : Unused code path elimination
 * Block '<S380>/Constant' : Unused code path elimination
 * Block '<S380>/Gain' : Unused code path elimination
 * Block '<S380>/Gain1' : Unused code path elimination
 * Block '<S380>/Gain2' : Unused code path elimination
 * Block '<S382>/Constant' : Unused code path elimination
 * Block '<S382>/Mod' : Unused code path elimination
 * Block '<S382>/polepair' : Unused code path elimination
 * Block '<S380>/Product' : Unused code path elimination
 * Block '<S380>/Product1' : Unused code path elimination
 * Block '<S380>/Product11' : Unused code path elimination
 * Block '<S380>/Product12' : Unused code path elimination
 * Block '<S380>/Product2' : Unused code path elimination
 * Block '<S380>/Product3' : Unused code path elimination
 * Block '<S380>/Product4' : Unused code path elimination
 * Block '<S60>/Data Type Conversion1' : Unused code path elimination
 * Block '<S60>/Data Type Conversion3' : Unused code path elimination
 * Block '<S60>/Data Type Conversion5' : Unused code path elimination
 * Block '<S23>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S79>/Kalpha' : Eliminated nontunable gain of 1
 * Block '<S79>/Kbeta' : Eliminated nontunable gain of 1
 * Block '<S198>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S216>/Ka' : Eliminated nontunable gain of 1
 * Block '<S216>/Kb' : Eliminated nontunable gain of 1
 * Block '<S216>/Kc' : Eliminated nontunable gain of 1
 * Block '<S223>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S61>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S234>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S236>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S253>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S257>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S268>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S268>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S268>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S260>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S322>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S335>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S336>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S347>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S348>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S361>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S363>/convert_pu' : Eliminated nontunable gain of 1
 * Block '<S368>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S58>/Gain1' : Eliminated nontunable gain of 1
 * Block '<S206>/Offset' : Unused code path elimination
 * Block '<S206>/Unary_Minus' : Unused code path elimination
 * Block '<S231>/Offset' : Unused code path elimination
 * Block '<S231>/Unary_Minus' : Unused code path elimination
 * Block '<S236>/One' : Unused code path elimination
 * Block '<S236>/Reset' : Unused code path elimination
 * Block '<S236>/Sum' : Unused code path elimination
 * Block '<S236>/UseInputPort' : Unused code path elimination
 * Block '<S236>/a' : Unused code path elimination
 * Block '<S257>/One' : Unused code path elimination
 * Block '<S257>/Reset' : Unused code path elimination
 * Block '<S257>/Sum' : Unused code path elimination
 * Block '<S257>/UseInputPort' : Unused code path elimination
 * Block '<S257>/a' : Unused code path elimination
 * Block '<S322>/FilterConstant' : Unused code path elimination
 * Block '<S322>/OneMinusFilterConstant' : Unused code path elimination
 * Block '<S322>/Reset' : Unused code path elimination
 * Block '<S322>/UseInputPort' : Unused code path elimination
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
 * '<S9>'   : 'PMSM_to_BLDC_mod1/untitledPanel'
 * '<S10>'  : 'PMSM_to_BLDC_mod1/untitledPanel1'
 * '<S11>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem'
 * '<S12>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem1'
 * '<S13>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem/Analog to Digital Converter1'
 * '<S14>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem/Analog to Digital Converter1/ECSoC'
 * '<S15>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem/Analog to Digital Converter1/ECSoC/ECSimCodegen'
 * '<S16>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem1/Analog to Digital Converter2'
 * '<S17>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem1/Analog to Digital Converter2/ECSoC'
 * '<S18>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem1/Analog to Digital Converter2/ECSoC/ECSimCodegen'
 * '<S19>'  : 'PMSM_to_BLDC_mod1/En_gate/Digital Port Write'
 * '<S20>'  : 'PMSM_to_BLDC_mod1/En_gate/Digital Port Write/ECSoC'
 * '<S21>'  : 'PMSM_to_BLDC_mod1/En_gate/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S22>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2'
 * '<S23>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1'
 * '<S24>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2/Bit Shift'
 * '<S25>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2/Bit Shift1'
 * '<S26>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2/Bit Shift/bit_shift'
 * '<S27>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2/Bit Shift1/bit_shift'
 * '<S28>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1/Bit Shift'
 * '<S29>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1/Bit Shift1'
 * '<S30>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1/Bit Shift/bit_shift'
 * '<S31>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1/Bit Shift1/bit_shift'
 * '<S32>'  : 'PMSM_to_BLDC_mod1/SPI_read/Compare To Constant'
 * '<S33>'  : 'PMSM_to_BLDC_mod1/SPI_read/Compare To Constant1'
 * '<S34>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read'
 * '<S35>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read'
 * '<S36>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem'
 * '<S37>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem1'
 * '<S38>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem/Bit Shift'
 * '<S39>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem/Bit Shift1'
 * '<S40>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem/Bit Shift/bit_shift'
 * '<S41>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem/Bit Shift1/bit_shift'
 * '<S42>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem'
 * '<S43>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem1'
 * '<S44>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem/Bit Shift'
 * '<S45>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem/Bit Shift1'
 * '<S46>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem/Bit Shift/bit_shift'
 * '<S47>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem/Bit Shift1/bit_shift'
 * '<S48>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read'
 * '<S49>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read'
 * '<S50>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read/Bit Shift'
 * '<S51>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read/Bit Shift1'
 * '<S52>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read/Bit Shift/bit_shift'
 * '<S53>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read/Bit Shift1/bit_shift'
 * '<S54>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read/Bit Shift'
 * '<S55>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read/Bit Shift1'
 * '<S56>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read/Bit Shift/bit_shift'
 * '<S57>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read/Bit Shift1/bit_shift'
 * '<S58>'  : 'PMSM_to_BLDC_mod1/Timer/FOC'
 * '<S59>'  : 'PMSM_to_BLDC_mod1/Timer/PWM Output'
 * '<S60>'  : 'PMSM_to_BLDC_mod1/Timer/Pulse to timer '
 * '<S61>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm '
 * '<S62>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Current_FB'
 * '<S63>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter'
 * '<S64>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/RPS'
 * '<S65>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls'
 * '<S66>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform'
 * '<S67>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Cycle'
 * '<S68>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle'
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
 * '<S79>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Clarke Transform/Variant/mcb/Clarke Transform/Two phase input'
 * '<S80>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Clarke Transform/Variant/mcb/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S81>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq'
 * '<S82>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id'
 * '<S83>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID'
 * '<S84>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Anti-windup'
 * '<S85>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/D Gain'
 * '<S86>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/External Derivative'
 * '<S87>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Filter'
 * '<S88>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Filter ICs'
 * '<S89>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/I Gain'
 * '<S90>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Ideal P Gain'
 * '<S91>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Ideal P Gain Fdbk'
 * '<S92>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Integrator'
 * '<S93>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Integrator ICs'
 * '<S94>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/N Copy'
 * '<S95>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/N Gain'
 * '<S96>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/P Copy'
 * '<S97>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Parallel P Gain'
 * '<S98>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Reset Signal'
 * '<S99>'  : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Saturation'
 * '<S100>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Saturation Fdbk'
 * '<S101>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Sum'
 * '<S102>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Sum Fdbk'
 * '<S103>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tracking Mode'
 * '<S104>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tracking Mode Sum'
 * '<S105>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tsamp - Integral'
 * '<S106>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tsamp - Ngain'
 * '<S107>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/postSat Signal'
 * '<S108>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/preInt Signal'
 * '<S109>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/preSat Signal'
 * '<S110>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel'
 * '<S111>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S112>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S113>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/D Gain/Disabled'
 * '<S114>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/External Derivative/Disabled'
 * '<S115>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Filter/Disabled'
 * '<S116>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Filter ICs/Disabled'
 * '<S117>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/I Gain/External Parameters'
 * '<S118>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Ideal P Gain/Passthrough'
 * '<S119>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Ideal P Gain Fdbk/Disabled'
 * '<S120>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Integrator/Discrete'
 * '<S121>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Integrator ICs/External IC'
 * '<S122>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/N Copy/Disabled wSignal Specification'
 * '<S123>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/N Gain/Disabled'
 * '<S124>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/P Copy/Disabled'
 * '<S125>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Parallel P Gain/External Parameters'
 * '<S126>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Reset Signal/External Reset'
 * '<S127>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Saturation/Enabled'
 * '<S128>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Saturation Fdbk/Disabled'
 * '<S129>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Sum/Sum_PI'
 * '<S130>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Sum Fdbk/Disabled'
 * '<S131>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tracking Mode/Disabled'
 * '<S132>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tracking Mode Sum/Passthrough'
 * '<S133>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tsamp - Integral/TsSignalSpecification'
 * '<S134>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/Tsamp - Ngain/Passthrough'
 * '<S135>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/postSat Signal/Forward_Path'
 * '<S136>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/preInt Signal/Internal PreInt'
 * '<S137>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI Control for Iq/Discrete Varying PID/preSat Signal/Forward_Path'
 * '<S138>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID'
 * '<S139>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Anti-windup'
 * '<S140>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/D Gain'
 * '<S141>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/External Derivative'
 * '<S142>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Filter'
 * '<S143>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Filter ICs'
 * '<S144>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/I Gain'
 * '<S145>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Ideal P Gain'
 * '<S146>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Ideal P Gain Fdbk'
 * '<S147>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Integrator'
 * '<S148>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Integrator ICs'
 * '<S149>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/N Copy'
 * '<S150>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/N Gain'
 * '<S151>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/P Copy'
 * '<S152>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Parallel P Gain'
 * '<S153>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Reset Signal'
 * '<S154>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Saturation'
 * '<S155>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Saturation Fdbk'
 * '<S156>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Sum'
 * '<S157>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Sum Fdbk'
 * '<S158>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tracking Mode'
 * '<S159>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tracking Mode Sum'
 * '<S160>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tsamp - Integral'
 * '<S161>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tsamp - Ngain'
 * '<S162>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/postSat Signal'
 * '<S163>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/preInt Signal'
 * '<S164>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/preSat Signal'
 * '<S165>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel'
 * '<S166>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S167>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S168>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/D Gain/Disabled'
 * '<S169>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/External Derivative/Disabled'
 * '<S170>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Filter/Disabled'
 * '<S171>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Filter ICs/Disabled'
 * '<S172>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/I Gain/External Parameters'
 * '<S173>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Ideal P Gain/Passthrough'
 * '<S174>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Ideal P Gain Fdbk/Disabled'
 * '<S175>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Integrator/Discrete'
 * '<S176>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Integrator ICs/External IC'
 * '<S177>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/N Copy/Disabled wSignal Specification'
 * '<S178>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/N Gain/Disabled'
 * '<S179>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/P Copy/Disabled'
 * '<S180>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Parallel P Gain/External Parameters'
 * '<S181>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Reset Signal/External Reset'
 * '<S182>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Saturation/Enabled'
 * '<S183>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Saturation Fdbk/Disabled'
 * '<S184>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Sum/Sum_PI'
 * '<S185>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Sum Fdbk/Disabled'
 * '<S186>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tracking Mode/Disabled'
 * '<S187>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tracking Mode Sum/Passthrough'
 * '<S188>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tsamp - Integral/TsSignalSpecification'
 * '<S189>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/Tsamp - Ngain/Passthrough'
 * '<S190>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/postSat Signal/Forward_Path'
 * '<S191>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/preInt Signal/Internal PreInt'
 * '<S192>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Idq control/PI control for Id/Discrete Varying PID/preSat Signal/Forward_Path'
 * '<S193>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant'
 * '<S194>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb'
 * '<S195>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform'
 * '<S196>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine'
 * '<S197>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Two inputs CRL'
 * '<S198>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup'
 * '<S199>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/Interpolation'
 * '<S200>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp'
 * '<S201>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/datatype'
 * '<S202>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S203>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S204>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S205>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Sine Cosine/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S206>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Inverse Park Transform1/Variant/mcb/Inverse Park Transform/Two inputs CRL/Switch_Axis'
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
 * '<S221>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Two inputs CRL'
 * '<S222>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup'
 * '<S223>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S224>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S225>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S226>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S227>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S228>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S229>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S230>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Sine Cosine/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S231>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Clark and park transform/Park Transform/Variant/mcb/Park Transform/Two inputs CRL/Switch_Axis'
 * '<S232>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Phase current Mesurement'
 * '<S233>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement'
 * '<S234>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer'
 * '<S235>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer'
 * '<S236>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/IIR Filter'
 * '<S237>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer'
 * '<S238>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)'
 * '<S239>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem'
 * '<S240>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem2'
 * '<S241>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/A11'
 * '<S242>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/A12'
 * '<S243>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/A22'
 * '<S244>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/L'
 * '<S245>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/L1'
 * '<S246>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem/L2'
 * '<S247>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem2/B'
 * '<S248>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/EEMF Observer/EEMF Observer (Mask)/Subsystem2/L'
 * '<S249>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/IIR Filter/IIR Filter'
 * '<S250>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S251>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S252>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/Direction_Latch'
 * '<S253>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL'
 * '<S254>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/Direction_Latch/Dir_Sense'
 * '<S255>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/Direction_Latch/Subsystem2'
 * '<S256>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/Direction_Latch/Subsystem3'
 * '<S257>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/IIR Filter'
 * '<S258>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Normalize'
 * '<S259>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller'
 * '<S260>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward'
 * '<S261>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Subsystem'
 * '<S262>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO'
 * '<S263>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter'
 * '<S264>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter/Low-pass'
 * '<S265>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S266>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Normalize/Compare To Zero'
 * '<S267>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Normalize/If Action Subsystem'
 * '<S268>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Normalize/Subsystem'
 * '<S269>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Anti-windup'
 * '<S270>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/D Gain'
 * '<S271>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/External Derivative'
 * '<S272>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter'
 * '<S273>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter ICs'
 * '<S274>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/I Gain'
 * '<S275>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain'
 * '<S276>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain Fdbk'
 * '<S277>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator'
 * '<S278>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator ICs'
 * '<S279>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Copy'
 * '<S280>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Gain'
 * '<S281>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/P Copy'
 * '<S282>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Parallel P Gain'
 * '<S283>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Reset Signal'
 * '<S284>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation'
 * '<S285>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation Fdbk'
 * '<S286>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum'
 * '<S287>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum Fdbk'
 * '<S288>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode'
 * '<S289>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode Sum'
 * '<S290>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Integral'
 * '<S291>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Ngain'
 * '<S292>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/postSat Signal'
 * '<S293>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/preInt Signal'
 * '<S294>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/preSat Signal'
 * '<S295>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Anti-windup/Passthrough'
 * '<S296>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/D Gain/Disabled'
 * '<S297>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/External Derivative/Disabled'
 * '<S298>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter/Disabled'
 * '<S299>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Filter ICs/Disabled'
 * '<S300>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/I Gain/Internal Parameters'
 * '<S301>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain/Passthrough'
 * '<S302>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S303>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator/Discrete'
 * '<S304>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Integrator ICs/Internal IC'
 * '<S305>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S306>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/N Gain/Disabled'
 * '<S307>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/P Copy/Disabled'
 * '<S308>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S309>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Reset Signal/External Reset'
 * '<S310>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation/Passthrough'
 * '<S311>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Saturation Fdbk/Disabled'
 * '<S312>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum/Sum_PI'
 * '<S313>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Sum Fdbk/Disabled'
 * '<S314>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode/Disabled'
 * '<S315>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S316>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S317>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S318>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/postSat Signal/Forward_Path'
 * '<S319>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/preInt Signal/Internal PreInt'
 * '<S320>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/PID Controller/preSat Signal/Forward_Path'
 * '<S321>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/GainSystem'
 * '<S322>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter'
 * '<S323>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/InpFilterFunc'
 * '<S324>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod'
 * '<S325>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/Nofunc'
 * '<S326>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/NofuncSpd'
 * '<S327>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod'
 * '<S328>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/SpdFilterFunc'
 * '<S329>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/GainSystem/IGains'
 * '<S330>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/GainSystem/ODGains'
 * '<S331>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/GainSystem/OutDTSetup'
 * '<S332>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter/IIR Filter'
 * '<S333>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter/IIR Filter/Low-pass'
 * '<S334>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S335>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1'
 * '<S336>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3'
 * '<S337>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/Integrator'
 * '<S338>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/Integrator2'
 * '<S339>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter'
 * '<S340>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S341>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S342>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter'
 * '<S343>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S344>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S345>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/Differentiator'
 * '<S346>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/Differentiator1'
 * '<S347>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1'
 * '<S348>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3'
 * '<S349>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter'
 * '<S350>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S351>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S352>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter'
 * '<S353>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S354>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S355>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Subsystem/If Action Subsystem'
 * '<S356>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/Subsystem/If Action Subsystem1'
 * '<S357>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem'
 * '<S358>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased'
 * '<S359>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Position Generator'
 * '<S360>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup'
 * '<S361>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S362>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S363>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S364>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S365>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S366>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S367>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S368>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Control Algorithm /Speed & Iab handle/Position and speed measurement/Extended EMF Observer/Speed Observer/PLL/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype backpropogation'
 * '<S369>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Codegen'
 * '<S370>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation'
 * '<S371>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Codegen/Subsystem'
 * '<S372>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Codegen/Subsystem/Gate_Inverter1'
 * '<S373>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model'
 * '<S374>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Average-Value Inverter'
 * '<S375>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model'
 * '<S376>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM'
 * '<S377>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous'
 * '<S378>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core'
 * '<S379>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Mechanical and Angle'
 * '<S380>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1'
 * '<S381>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic'
 * '<S382>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/MechToElect'
 * '<S383>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/Power Accounting Bus Creator'
 * '<S384>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/Power Accounting Bus Creator/PwrNotTrnsfrd Input'
 * '<S385>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/Power Accounting Bus Creator/PwrStored Input'
 * '<S386>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/Motor Units1/Power Accounting Bus Creator/PwrTrnsfrd Input'
 * '<S387>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Clarke Transform'
 * '<S388>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Inverse Clarke Transform'
 * '<S389>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Inverse Park Transform'
 * '<S390>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Machine Torque'
 * '<S391>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit'
 * '<S392>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Park Transform'
 * '<S393>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/Machine Torque/Subsystem'
 * '<S394>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage'
 * '<S395>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage'
 * '<S396>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem'
 * '<S397>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem1'
 * '<S398>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem2'
 * '<S399>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem'
 * '<S400>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem1'
 * '<S401>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem2'
 * '<S402>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Inverter/Simulation/Inverter&motor_Plant_model/Plant_model/Surface Mount PMSM/PMSM Speed Input Exterior Continuous/PMSM Speed Input Core/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem3'
 * '<S403>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control'
 * '<S404>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller'
 * '<S405>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Anti-windup'
 * '<S406>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/D Gain'
 * '<S407>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/External Derivative'
 * '<S408>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Filter'
 * '<S409>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Filter ICs'
 * '<S410>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/I Gain'
 * '<S411>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Ideal P Gain'
 * '<S412>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Ideal P Gain Fdbk'
 * '<S413>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Integrator'
 * '<S414>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Integrator ICs'
 * '<S415>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/N Copy'
 * '<S416>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/N Gain'
 * '<S417>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/P Copy'
 * '<S418>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Parallel P Gain'
 * '<S419>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Reset Signal'
 * '<S420>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Saturation'
 * '<S421>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Saturation Fdbk'
 * '<S422>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Sum'
 * '<S423>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Sum Fdbk'
 * '<S424>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Tracking Mode'
 * '<S425>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Tracking Mode Sum'
 * '<S426>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Tsamp - Integral'
 * '<S427>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Tsamp - Ngain'
 * '<S428>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/postSat Signal'
 * '<S429>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/preInt Signal'
 * '<S430>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/preSat Signal'
 * '<S431>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Anti-windup/Passthrough'
 * '<S432>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/D Gain/Disabled'
 * '<S433>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/External Derivative/Disabled'
 * '<S434>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Filter/Disabled'
 * '<S435>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Filter ICs/Disabled'
 * '<S436>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/I Gain/Internal Parameters'
 * '<S437>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Ideal P Gain/Passthrough'
 * '<S438>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S439>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Integrator/Continuous'
 * '<S440>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Integrator ICs/Internal IC'
 * '<S441>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S442>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/N Gain/Disabled'
 * '<S443>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/P Copy/Disabled'
 * '<S444>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S445>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Reset Signal/Disabled'
 * '<S446>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Saturation/Passthrough'
 * '<S447>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Saturation Fdbk/Disabled'
 * '<S448>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Sum/Sum_PI'
 * '<S449>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Sum Fdbk/Disabled'
 * '<S450>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Tracking Mode/Disabled'
 * '<S451>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S452>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S453>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S454>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/postSat Signal/Forward_Path'
 * '<S455>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/preInt Signal/Internal PreInt'
 * '<S456>' : 'PMSM_to_BLDC_mod1/Timer/FOC/Speed_controls/Speed Control/PID Controller/preSat Signal/Forward_Path'
 * '<S457>' : 'PMSM_to_BLDC_mod1/Timer/PWM Output/ECSoC'
 * '<S458>' : 'PMSM_to_BLDC_mod1/Timer/PWM Output/ECSoC/ECSimCodegen'
 * '<S459>' : 'PMSM_to_BLDC_mod1/V_sense/Analog to Digital Converter1'
 * '<S460>' : 'PMSM_to_BLDC_mod1/V_sense/Analog to Digital Converter1/ECSoC'
 * '<S461>' : 'PMSM_to_BLDC_mod1/V_sense/Analog to Digital Converter1/ECSoC/ECSimCodegen'
 */
#endif                                 /* PMSM_to_BLDC_mod1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
