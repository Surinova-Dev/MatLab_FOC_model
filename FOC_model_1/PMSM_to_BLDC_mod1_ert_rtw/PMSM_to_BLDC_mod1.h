/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.h
 *
 * Code generated for Simulink model 'PMSM_to_BLDC_mod1'.
 *
 * Model version                  : 4.830
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Tue Apr 28 19:01:54 2026
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

/* Block states (default storage) for system '<S17>/Bit Shift' */
typedef struct {
  int32_T sfEvent;                     /* '<S19>/bit_shift' */
  boolean_T doneDoubleBufferReInit;    /* '<S19>/bit_shift' */
} DW_BitShift_PMSM_to_BLDC_mod1_T;

/* Block states (default storage) for system '<S17>/Bit Shift1' */
typedef struct {
  int32_T sfEvent;                     /* '<S20>/bit_shift' */
  boolean_T doneDoubleBufferReInit;    /* '<S20>/bit_shift' */
} DW_BitShift1_PMSM_to_BLDC_mod_T;

/* Block states (default storage) for system '<S31>/SPI Transmit' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S31>/SPI Transmit' */
  boolean_T objisempty;                /* '<S31>/SPI Transmit' */
} DW_SPITransmit_PMSM_to_BLDC_m_T;

/* Block signals for system '<S32>/SPI Receive' */
typedef struct {
  uint16_T SPIReceive;                 /* '<S32>/SPI Receive' */
} B_SPIReceive_PMSM_to_BLDC_mod_T;

/* Block states (default storage) for system '<S32>/SPI Receive' */
typedef struct {
  stm32cube_blocks_SPIControl_b_T obj; /* '<S32>/SPI Receive' */
  boolean_T objisempty;                /* '<S32>/SPI Receive' */
} DW_SPIReceive_PMSM_to_BLDC_mo_T;

/* Block signals (default storage) */
typedef struct {
  real_T Constant2;                    /* '<S5>/Constant2' */
  real_T Constant3;                    /* '<S5>/Constant3' */
  real_T Gain1;                        /* '<S7>/Gain1' */
  real_T Gain;                         /* '<S6>/Gain' */
  real_T En_State;                     /* '<Root>/Chart' */
  real_T Ctrl_flag2;                   /* '<Root>/Chart' */
  real_T Ctrl_flag1;                   /* '<Root>/Chart' */
  real_T spi_write1;                   /* '<Root>/Chart' */
  real_T spi_write2;                   /* '<Root>/Chart' */
  real_T spi_write3;                   /* '<Root>/Chart' */
  real_T spi_write4;                   /* '<Root>/Chart' */
  uint16_T BitwiseOR;                  /* '<S37>/Bitwise OR' */
  uint16_T BitwiseOR_h;                /* '<S31>/Bitwise OR' */
  uint16_T BitwiseOR_e;                /* '<S18>/Bitwise OR' */
  uint16_T BitwiseOR_n;                /* '<S17>/Bitwise OR' */
  uint16_T DataTypeConversion;         /* '<S17>/Data Type Conversion' */
  boolean_T AND1;                      /* '<S4>/AND1' */
  boolean_T AND;                       /* '<S4>/AND' */
  boolean_T Compare;                   /* '<S28>/Compare' */
  boolean_T Compare_g;                 /* '<S27>/Compare' */
  B_SPIReceive_PMSM_to_BLDC_mod_T SPIReceive_pna;/* '<S32>/SPI Receive' */
  B_SPIReceive_PMSM_to_BLDC_mod_T SPIReceive_pn;/* '<S32>/SPI Receive' */
} B_PMSM_to_BLDC_mod1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_SPIControl_b_T obj; /* '<S31>/SPI Receive' */
  stm32cube_blocks_SPIControl_b_T obj_g;/* '<S18>/SPI Receive' */
  stm32cube_blocks_SPIControl_b_T obj_gk;/* '<S17>/SPI Receive' */
  stm32cube_blocks_SPIControlle_T obj_k;/* '<S37>/SPI Transmit' */
  stm32cube_blocks_SPIControlle_T obj_n;/* '<S18>/SPI Transmit' */
  stm32cube_blocks_SPIControlle_T obj_j;/* '<S17>/SPI Transmit' */
  stm32cube_blocks_AnalogInput__T obj_o;/* '<S13>/Analog to Digital Converter' */
  stm32cube_blocks_AnalogInput__T obj_d;/* '<S10>/Analog to Digital Converter' */
  stm32cube_blocks_DigitalPortW_T obj_ow;/* '<S16>/Digital Port Write' */
  real_T CS_val;                       /* '<Root>/Chart' */
  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<S5>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<S4>/Scope' */

  struct {
    void *LoggedData[6];
  } Scope_PWORK_e;                     /* '<Root>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_h;                     /* '<S5>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope2_PWORK;                      /* '<S5>/Scope2' */

  uint32_T is_c3_PMSM_to_BLDC_mod1;    /* '<Root>/Chart' */
  uint16_T temporalCounter_i1;         /* '<Root>/Chart' */
  int8_T Subsystem1_SubsysRanBC;       /* '<S30>/Subsystem1' */
  int8_T Subsystem_SubsysRanBC;        /* '<S30>/Subsystem' */
  int8_T Subsystem1_SubsysRanBC_n;     /* '<S29>/Subsystem1' */
  int8_T Subsystem_SubsysRanBC_i;      /* '<S29>/Subsystem' */
  int8_T Ctrl_Reg_1_SubsysRanBC;       /* '<S4>/Ctrl_Reg_1' */
  int8_T Control_Reg2_SubsysRanBC;     /* '<S4>/Control_Reg2' */
  int8_T Subsystem1_SubsysRanBC_c;     /* '<S2>/Subsystem1' */
  int8_T Subsystem_SubsysRanBC_g;      /* '<S2>/Subsystem' */
  uint8_T is_active_c3_PMSM_to_BLDC_mod1;/* '<Root>/Chart' */
  boolean_T Subsystem1_MODE;           /* '<S30>/Subsystem1' */
  boolean_T Subsystem_MODE;            /* '<S30>/Subsystem' */
  boolean_T Subsystem1_MODE_m;         /* '<S29>/Subsystem1' */
  boolean_T Subsystem_MODE_f;          /* '<S29>/Subsystem' */
  boolean_T Ctrl_Reg_1_MODE;           /* '<S4>/Ctrl_Reg_1' */
  boolean_T Control_Reg2_MODE;         /* '<S4>/Control_Reg2' */
  DW_SPITransmit_PMSM_to_BLDC_m_T SPITransmit_pnae;/* '<S31>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC_mo_T SPIReceive_pna;/* '<S32>/SPI Receive' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1_m;/* '<S37>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift_b;/* '<S37>/Bit Shift' */
  DW_SPITransmit_PMSM_to_BLDC_m_T SPITransmit_pn;/* '<S31>/SPI Transmit' */
  DW_SPIReceive_PMSM_to_BLDC_mo_T SPIReceive_pn;/* '<S32>/SPI Receive' */
  DW_SPITransmit_PMSM_to_BLDC_m_T SPITransmit_p;/* '<S31>/SPI Transmit' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1_p;/* '<S31>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift_hq;/* '<S31>/Bit Shift' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1_d;/* '<S18>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift_h;/* '<S18>/Bit Shift' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1;/* '<S17>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift;/* '<S17>/Bit Shift' */
} DW_PMSM_to_BLDC_mod1_T;

/* Invariant block signals (default storage) */
typedef struct {
  const uint16_T BitwiseAND;           /* '<S37>/Bitwise AND' */
  const uint16_T BitwiseAND_d;         /* '<S31>/Bitwise AND' */
  const uint16_T BitwiseAND_e;         /* '<S18>/Bitwise AND' */
  const uint16_T BitwiseAND_j;         /* '<S17>/Bitwise AND' */
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
    struct {
      uint8_T TID[2];
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
 * Block '<S18>/Data Type Conversion1' : Eliminate redundant data type conversion
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
 * '<S6>'   : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem'
 * '<S7>'   : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem1'
 * '<S8>'   : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem/Analog to Digital Converter1'
 * '<S9>'   : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem/Analog to Digital Converter1/ECSoC'
 * '<S10>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem/Analog to Digital Converter1/ECSoC/ECSimCodegen'
 * '<S11>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem1/Analog to Digital Converter2'
 * '<S12>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem1/Analog to Digital Converter2/ECSoC'
 * '<S13>'  : 'PMSM_to_BLDC_mod1/Current_sensing/Subsystem1/Analog to Digital Converter2/ECSoC/ECSimCodegen'
 * '<S14>'  : 'PMSM_to_BLDC_mod1/En_gate/Digital Port Write'
 * '<S15>'  : 'PMSM_to_BLDC_mod1/En_gate/Digital Port Write/ECSoC'
 * '<S16>'  : 'PMSM_to_BLDC_mod1/En_gate/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S17>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2'
 * '<S18>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1'
 * '<S19>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2/Bit Shift'
 * '<S20>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2/Bit Shift1'
 * '<S21>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2/Bit Shift/bit_shift'
 * '<S22>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Control_Reg2/Bit Shift1/bit_shift'
 * '<S23>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1/Bit Shift'
 * '<S24>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1/Bit Shift1'
 * '<S25>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1/Bit Shift/bit_shift'
 * '<S26>'  : 'PMSM_to_BLDC_mod1/SPI_Write/Ctrl_Reg_1/Bit Shift1/bit_shift'
 * '<S27>'  : 'PMSM_to_BLDC_mod1/SPI_read/Compare To Constant'
 * '<S28>'  : 'PMSM_to_BLDC_mod1/SPI_read/Compare To Constant1'
 * '<S29>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read'
 * '<S30>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read'
 * '<S31>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem'
 * '<S32>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem1'
 * '<S33>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem/Bit Shift'
 * '<S34>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem/Bit Shift1'
 * '<S35>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem/Bit Shift/bit_shift'
 * '<S36>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_1_read/Subsystem/Bit Shift1/bit_shift'
 * '<S37>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem'
 * '<S38>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem1'
 * '<S39>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem/Bit Shift'
 * '<S40>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem/Bit Shift1'
 * '<S41>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem/Bit Shift/bit_shift'
 * '<S42>'  : 'PMSM_to_BLDC_mod1/SPI_read/Control_Reg_2_read/Subsystem/Bit Shift1/bit_shift'
 */
#endif                                 /* PMSM_to_BLDC_mod1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
