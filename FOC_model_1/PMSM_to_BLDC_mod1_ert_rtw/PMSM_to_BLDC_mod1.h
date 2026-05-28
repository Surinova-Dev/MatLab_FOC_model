/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.h
 *
 * Code generated for Simulink model 'PMSM_to_BLDC_mod1'.
 *
 * Model version                  : 4.1040
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Thu May 28 16:12:04 2026
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
#include "math.h"
#include "ext_mode.h"
#include "main.h"
#include "mw_stm32_utils.h"
#include "MW_SPI.h"
#include "mw_stm32_spi_ll.h"
#endif                                 /* PMSM_to_BLDC_mod1_COMMON_INCLUDES_ */

#include "PMSM_to_BLDC_mod1_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
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
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
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

/* Block states (default storage) for system '<S21>/Bit Shift' */
typedef struct {
  int32_T sfEvent;                     /* '<S23>/bit_shift' */
  boolean_T doneDoubleBufferReInit;    /* '<S23>/bit_shift' */
} DW_BitShift_PMSM_to_BLDC_mod1_T;

/* Block states (default storage) for system '<S21>/Bit Shift1' */
typedef struct {
  int32_T sfEvent;                     /* '<S24>/bit_shift' */
  boolean_T doneDoubleBufferReInit;    /* '<S24>/bit_shift' */
} DW_BitShift1_PMSM_to_BLDC_mod_T;

/* Block states (default storage) for system '<S35>/SPI Receive' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S35>/SPI Receive' */
  boolean_T objisempty;                /* '<S35>/SPI Receive' */
} DW_SPIReceive_PMSM_to_BLDC_mo_T;

/* Block states (default storage) for system '<S35>/SPI Transmit' */
typedef struct {
  stm32cube_blocks_SPIControl_d_T obj; /* '<S35>/SPI Transmit' */
  boolean_T objisempty;                /* '<S35>/SPI Transmit' */
} DW_SPITransmit_PMSM_to_BLDC_m_T;

/* Block signals for system '<S36>/SPI Receive' */
typedef struct {
  uint16_T SPIReceive;                 /* '<S36>/SPI Receive' */
} B_SPIReceive_PMSM_to_BLDC_m_c_T;

/* Block states (default storage) for system '<S36>/SPI Receive' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S36>/SPI Receive' */
  boolean_T objisempty;                /* '<S36>/SPI Receive' */
} DW_SPIReceive_PMSM_to_BLDC__f_T;

/* Block signals for system '<S47>/SPI Receive' */
typedef struct {
  uint16_T SPIReceive[15];             /* '<S47>/SPI Receive' */
} B_SPIReceive_PMSM_to_BLDC__ca_T;

/* Block states (default storage) for system '<S47>/SPI Receive' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S47>/SPI Receive' */
  boolean_T objisempty;                /* '<S47>/SPI Receive' */
} DW_SPIReceive_PMSM_to_BLDC_fw_T;

/* Block states (default storage) for system '<S47>/SPI Transmit' */
typedef struct {
  stm32cube_blocks_SPIControl_d_T obj; /* '<S47>/SPI Transmit' */
  boolean_T objisempty;                /* '<S47>/SPI Transmit' */
} DW_SPITransmit_PMSM_to_BLDC_f_T;

/* Block signals (default storage) */
typedef struct {
  real_T Delay2[3];                    /* '<Root>/Delay2' */
  real_T Gain;                         /* '<S7>/Gain' */
  real_T Gain1;                        /* '<S11>/Gain1' */
  real_T Gain_k;                       /* '<S10>/Gain' */
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
  uint16_T AnalogtoDigitalConverter;   /* '<S59>/Analog to Digital Converter' */
  uint16_T BitwiseOR;                  /* '<S48>/Bitwise OR' */
  uint16_T BitwiseOR_p;                /* '<S47>/Bitwise OR' */
  uint16_T DataTypeConversion;         /* '<S47>/Data Type Conversion' */
  uint16_T BitwiseOR_o;                /* '<S41>/Bitwise OR' */
  uint16_T BitwiseOR_h;                /* '<S35>/Bitwise OR' */
  uint16_T BitwiseOR_e;                /* '<S22>/Bitwise OR' */
  uint16_T BitwiseOR_n;                /* '<S21>/Bitwise OR' */
  uint16_T DataTypeConversion_m;       /* '<S21>/Data Type Conversion' */
  boolean_T Delay;                     /* '<Root>/Delay' */
  boolean_T Delay1;                    /* '<Root>/Delay1' */
  boolean_T Compare;                   /* '<S32>/Compare' */
  boolean_T Compare_g;                 /* '<S31>/Compare' */
  boolean_T AND1;                      /* '<S4>/AND1' */
  boolean_T AND;                       /* '<S4>/AND' */
  B_SPIReceive_PMSM_to_BLDC__ca_T SPIReceive_pnaevv;/* '<S47>/SPI Receive' */
  B_SPIReceive_PMSM_to_BLDC__ca_T SPIReceive_pnaev;/* '<S47>/SPI Receive' */
  B_SPIReceive_PMSM_to_BLDC_m_c_T SPIReceive_pnae;/* '<S36>/SPI Receive' */
  B_SPIReceive_PMSM_to_BLDC_m_c_T SPIReceive_pn;/* '<S36>/SPI Receive' */
} B_PMSM_to_BLDC_mod1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S22>/SPI Receive' */
  stm32cube_blocks_SPIControlle_T obj_g;/* '<S21>/SPI Receive' */
  stm32cube_blocks_SPIControl_d_T obj_n;/* '<S22>/SPI Transmit' */
  stm32cube_blocks_SPIControl_d_T obj_j;/* '<S21>/SPI Transmit' */
  stm32cube_blocks_AnalogInput__T obj_p;/* '<S59>/Analog to Digital Converter' */
  stm32cube_blocks_AnalogInput__T obj_o;/* '<S17>/Analog to Digital Converter' */
  stm32cube_blocks_AnalogInput__T obj_d;/* '<S14>/Analog to Digital Converter' */
  stm32cube_blocks_DigitalPortW_T obj_ow;/* '<S20>/Digital Port Write' */
  real_T Delay2_DSTATE;                /* '<Root>/Delay2' */
  real_T CS_val;                       /* '<Root>/Chart' */
  real_T Drv_ok;                       /* '<Root>/Chart' */
  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<S6>/Scope' */

  struct {
    void *LoggedData[8];
  } Scope_PWORK_i;                     /* '<Root>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<S6>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_h;                     /* '<S7>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_hj;                    /* '<S5>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope2_PWORK;                      /* '<S5>/Scope2' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_hp;                    /* '<S4>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_c;                     /* '<S11>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_d;                     /* '<S10>/Scope' */

  uint32_T is_Test2;                   /* '<Root>/Chart' */
  uint32_T is_Test;                    /* '<Root>/Chart' */
  uint16_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint16_T temporalCounter_i2;         /* '<Root>/Chart' */
  boolean_T Delay_DSTATE;              /* '<Root>/Delay' */
  boolean_T Delay1_DSTATE;             /* '<Root>/Delay1' */
  int8_T Status_Reg_2_read_SubsysRanBC;/* '<S6>/Status_Reg_2_read' */
  int8_T Status_Reg1_read_SubsysRanBC; /* '<S6>/Status_Reg1_read' */
  int8_T Subsystem1_SubsysRanBC;       /* '<S34>/Subsystem1' */
  int8_T Subsystem_SubsysRanBC;        /* '<S34>/Subsystem' */
  int8_T Subsystem1_SubsysRanBC_n;     /* '<S33>/Subsystem1' */
  int8_T Subsystem_SubsysRanBC_i;      /* '<S33>/Subsystem' */
  int8_T Ctrl_Reg_1_SubsysRanBC;       /* '<S4>/Ctrl_Reg_1' */
  int8_T Control_Reg2_SubsysRanBC;     /* '<S4>/Control_Reg2' */
  int8_T Subsystem1_SubsysRanBC_c;     /* '<S2>/Subsystem1' */
  int8_T Subsystem_SubsysRanBC_g;      /* '<S2>/Subsystem' */
  uint8_T is_active_c3_PMSM_to_BLDC_mod1;/* '<Root>/Chart' */
  uint8_T is_active_Test2;             /* '<Root>/Chart' */
  uint8_T is_active_Test;              /* '<Root>/Chart' */
  boolean_T Status_Reg_2_read_MODE;    /* '<S6>/Status_Reg_2_read' */
  boolean_T Status_Reg1_read_MODE;     /* '<S6>/Status_Reg1_read' */
  boolean_T Subsystem1_MODE;           /* '<S34>/Subsystem1' */
  boolean_T Subsystem_MODE;            /* '<S34>/Subsystem' */
  boolean_T Subsystem1_MODE_m;         /* '<S33>/Subsystem1' */
  boolean_T Subsystem_MODE_f;          /* '<S33>/Subsystem' */
  boolean_T Ctrl_Reg_1_MODE;           /* '<S4>/Ctrl_Reg_1' */
  boolean_T Control_Reg2_MODE;         /* '<S4>/Control_Reg2' */
  boolean_T Subsystem1_MODE_b;         /* '<S2>/Subsystem1' */
  boolean_T Subsystem_MODE_n;          /* '<S2>/Subsystem' */
  DW_SPITransmit_PMSM_to_BLDC_f_T SPITransmit_pnaevv;/* '<S47>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC_fw_T SPIReceive_pnaevv;/* '<S47>/SPI Receive' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1_o;/* '<S48>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift_n;/* '<S48>/Bit Shift' */
  DW_SPITransmit_PMSM_to_BLDC_f_T SPITransmit_pnaev;/* '<S47>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC_fw_T SPIReceive_pnaev;/* '<S47>/SPI Receive' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1_j;/* '<S47>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift_p;/* '<S47>/Bit Shift' */
  DW_SPITransmit_PMSM_to_BLDC_m_T SPITransmit_pnae;/* '<S35>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC__f_T SPIReceive_pnae;/* '<S36>/SPI Receive' */
  DW_SPITransmit_PMSM_to_BLDC_m_T SPITransmit_pna;/* '<S35>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC_mo_T SPIReceive_pna;/* '<S35>/SPI Receive' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1_m;/* '<S41>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift_b;/* '<S41>/Bit Shift' */
  DW_SPITransmit_PMSM_to_BLDC_m_T SPITransmit_pn;/* '<S35>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC__f_T SPIReceive_pn;/* '<S36>/SPI Receive' */
  DW_SPITransmit_PMSM_to_BLDC_m_T SPITransmit_p;/* '<S35>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC_mo_T SPIReceive_p;/* '<S35>/SPI Receive' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1_p;/* '<S35>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift_hq;/* '<S35>/Bit Shift' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1_d;/* '<S22>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift_h;/* '<S22>/Bit Shift' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1;/* '<S21>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift;/* '<S21>/Bit Shift' */
} DW_PMSM_to_BLDC_mod1_T;

/* Invariant block signals (default storage) */
typedef struct {
  const uint16_T BitwiseAND;           /* '<S48>/Bitwise AND' */
  const uint16_T BitwiseAND_m;         /* '<S47>/Bitwise AND' */
  const uint16_T BitwiseAND_j;         /* '<S41>/Bitwise AND' */
  const uint16_T BitwiseAND_d;         /* '<S35>/Bitwise AND' */
  const uint16_T BitwiseAND_e;         /* '<S22>/Bitwise AND' */
  const uint16_T BitwiseAND_jx;        /* '<S21>/Bitwise AND' */
} ConstB_PMSM_to_BLDC_mod1_T;

/* Real-time Model Data Structure */
struct tag_RTM_PMSM_to_BLDC_mod1_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
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
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTick2;
    uint32_T clockTick3;
    uint32_T clockTick4;
    struct {
      uint16_T TID[5];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (default storage) */
extern B_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_B;

/* Block states (default storage) */
extern DW_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_DW;
extern const ConstB_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_ConstB;/* constant block i/o */

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
 * Block '<S22>/Data Type Conversion1' : Eliminate redundant data type conversion
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
 * '<S7>'   : 'PMSM_to_BLDC_mod1/V_sense'
 * '<S8>'   : 'PMSM_to_BLDC_mod1/untitledPanel'
 * '<S9>'   : 'PMSM_to_BLDC_mod1/untitledPanel1'
 * '<S10>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem'
 * '<S11>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem1'
 * '<S12>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem/Analog to Digital Converter1'
 * '<S13>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem/Analog to Digital Converter1/ECSoC'
 * '<S14>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem/Analog to Digital Converter1/ECSoC/ECSimCodegen'
 * '<S15>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem1/Analog to Digital Converter2'
 * '<S16>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem1/Analog to Digital Converter2/ECSoC'
 * '<S17>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem1/Analog to Digital Converter2/ECSoC/ECSimCodegen'
 * '<S18>'  : 'PMSM_to_BLDC_mod1/En_gate/Digital Port Write'
 * '<S19>'  : 'PMSM_to_BLDC_mod1/En_gate/Digital Port Write/ECSoC'
 * '<S20>'  : 'PMSM_to_BLDC_mod1/En_gate/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S21>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2'
 * '<S22>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1'
 * '<S23>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2/Bit Shift'
 * '<S24>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2/Bit Shift1'
 * '<S25>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2/Bit Shift/bit_shift'
 * '<S26>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2/Bit Shift1/bit_shift'
 * '<S27>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1/Bit Shift'
 * '<S28>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1/Bit Shift1'
 * '<S29>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1/Bit Shift/bit_shift'
 * '<S30>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1/Bit Shift1/bit_shift'
 * '<S31>'  : 'PMSM_to_BLDC_mod1/SPI_read/Compare To Constant'
 * '<S32>'  : 'PMSM_to_BLDC_mod1/SPI_read/Compare To Constant1'
 * '<S33>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read'
 * '<S34>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read'
 * '<S35>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem'
 * '<S36>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem1'
 * '<S37>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem/Bit Shift'
 * '<S38>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem/Bit Shift1'
 * '<S39>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem/Bit Shift/bit_shift'
 * '<S40>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem/Bit Shift1/bit_shift'
 * '<S41>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem'
 * '<S42>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem1'
 * '<S43>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem/Bit Shift'
 * '<S44>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem/Bit Shift1'
 * '<S45>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem/Bit Shift/bit_shift'
 * '<S46>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem/Bit Shift1/bit_shift'
 * '<S47>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read'
 * '<S48>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read'
 * '<S49>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read/Bit Shift'
 * '<S50>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read/Bit Shift1'
 * '<S51>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read/Bit Shift/bit_shift'
 * '<S52>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg1_read/Bit Shift1/bit_shift'
 * '<S53>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read/Bit Shift'
 * '<S54>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read/Bit Shift1'
 * '<S55>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read/Bit Shift/bit_shift'
 * '<S56>'  : 'PMSM_to_BLDC_mod1/Status_reg_read/Status_Reg_2_read/Bit Shift1/bit_shift'
 * '<S57>'  : 'PMSM_to_BLDC_mod1/V_sense/Analog to Digital Converter1'
 * '<S58>'  : 'PMSM_to_BLDC_mod1/V_sense/Analog to Digital Converter1/ECSoC'
 * '<S59>'  : 'PMSM_to_BLDC_mod1/V_sense/Analog to Digital Converter1/ECSoC/ECSimCodegen'
 */
#endif                                 /* PMSM_to_BLDC_mod1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
