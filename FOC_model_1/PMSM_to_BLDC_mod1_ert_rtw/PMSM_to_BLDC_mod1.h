/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.h
 *
 * Code generated for Simulink model 'PMSM_to_BLDC_mod1'.
 *
 * Model version                  : 4.665
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Wed Apr 22 17:47:26 2026
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

/* Block states (default storage) for system '<S8>/Bit Shift' */
typedef struct {
  int32_T sfEvent;                     /* '<S10>/bit_shift' */
  boolean_T doneDoubleBufferReInit;    /* '<S10>/bit_shift' */
} DW_BitShift_PMSM_to_BLDC_mod1_T;

/* Block states (default storage) for system '<S8>/Bit Shift1' */
typedef struct {
  int32_T sfEvent;                     /* '<S11>/bit_shift' */
  boolean_T doneDoubleBufferReInit;    /* '<S11>/bit_shift' */
} DW_BitShift1_PMSM_to_BLDC_mod_T;

/* Block signals (default storage) */
typedef struct {
  real_T En_State;                     /* '<Root>/Chart' */
  real_T Ctrl_flag2;                   /* '<Root>/Chart' */
  real_T Ctrl_flag1;                   /* '<Root>/Chart' */
  real_T read1;                        /* '<Root>/Chart' */
  real_T read2;                        /* '<Root>/Chart' */
  real_T spi_write1;                   /* '<Root>/Chart' */
  real_T spi_write2;                   /* '<Root>/Chart' */
  uint16_T DataTypeConversion;         /* '<S18>/Data Type Conversion' */
  uint16_T Delay;                      /* '<S9>/Delay' */
  uint16_T CCaller;                    /* '<S9>/C Caller' */
  uint16_T Delay_n;                    /* '<S8>/Delay' */
  uint16_T CCaller_h;                  /* '<S8>/C Caller' */
  uint16_T BitwiseOR;                  /* '<S8>/Bitwise OR' */
  boolean_T AND1;                      /* '<S4>/AND1' */
  boolean_T AND;                       /* '<S4>/AND' */
} B_PMSM_to_BLDC_mod1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_DigitalPortW_T obj; /* '<S7>/Digital Port Write' */
  real_T CS_val;                       /* '<Root>/Chart' */
  struct {
    void *LoggedData[7];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_b;                     /* '<S3>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<S3>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_m;                     /* '<S4>/Scope' */

  uint32_T is_c3_PMSM_to_BLDC_mod1;    /* '<Root>/Chart' */
  uint16_T Delay_DSTATE;               /* '<S9>/Delay' */
  uint16_T Delay_DSTATE_i;             /* '<S8>/Delay' */
  int8_T Ctrl_Reg_1_SubsysRanBC;       /* '<S4>/Ctrl_Reg_1' */
  int8_T Control_Reg_2_SubsysRanBC;    /* '<S4>/Control_Reg_2' */
  int8_T Control_Reg_2_read_SubsysRanBC;/* '<S3>/Control_Reg_2_read' */
  int8_T Control_Reg1_read_SubsysRanBC;/* '<S3>/Control_Reg1_read' */
  uint8_T is_active_c3_PMSM_to_BLDC_mod1;/* '<Root>/Chart' */
  uint8_T temporalCounter_i1;          /* '<Root>/Chart' */
  boolean_T Control_Reg_2_read_MODE;   /* '<S3>/Control_Reg_2_read' */
  boolean_T Control_Reg1_read_MODE;    /* '<S3>/Control_Reg1_read' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1_m;/* '<S9>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift_b;/* '<S9>/Bit Shift' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1;/* '<S8>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift;/* '<S8>/Bit Shift' */
} DW_PMSM_to_BLDC_mod1_T;

/* Invariant block signals (default storage) */
typedef struct {
  const uint16_T BitwiseAND;           /* '<S9>/Bitwise AND' */
  const uint16_T BitwiseAND_b;         /* '<S8>/Bitwise AND' */
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
      uint16_T TID[2];
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
 * Block '<S8>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S19>/Data Type Conversion1' : Eliminate redundant data type conversion
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
 * '<S2>'   : 'PMSM_to_BLDC_mod1/Subsystem3'
 * '<S3>'   : 'PMSM_to_BLDC_mod1/Subsystem4'
 * '<S4>'   : 'PMSM_to_BLDC_mod1/Subsystem5'
 * '<S5>'   : 'PMSM_to_BLDC_mod1/Subsystem3/Digital Port Write'
 * '<S6>'   : 'PMSM_to_BLDC_mod1/Subsystem3/Digital Port Write/ECSoC'
 * '<S7>'   : 'PMSM_to_BLDC_mod1/Subsystem3/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S8>'   : 'PMSM_to_BLDC_mod1/Subsystem4/Control_Reg1_read'
 * '<S9>'   : 'PMSM_to_BLDC_mod1/Subsystem4/Control_Reg_2_read'
 * '<S10>'  : 'PMSM_to_BLDC_mod1/Subsystem4/Control_Reg1_read/Bit Shift'
 * '<S11>'  : 'PMSM_to_BLDC_mod1/Subsystem4/Control_Reg1_read/Bit Shift1'
 * '<S12>'  : 'PMSM_to_BLDC_mod1/Subsystem4/Control_Reg1_read/Bit Shift/bit_shift'
 * '<S13>'  : 'PMSM_to_BLDC_mod1/Subsystem4/Control_Reg1_read/Bit Shift1/bit_shift'
 * '<S14>'  : 'PMSM_to_BLDC_mod1/Subsystem4/Control_Reg_2_read/Bit Shift'
 * '<S15>'  : 'PMSM_to_BLDC_mod1/Subsystem4/Control_Reg_2_read/Bit Shift1'
 * '<S16>'  : 'PMSM_to_BLDC_mod1/Subsystem4/Control_Reg_2_read/Bit Shift/bit_shift'
 * '<S17>'  : 'PMSM_to_BLDC_mod1/Subsystem4/Control_Reg_2_read/Bit Shift1/bit_shift'
 * '<S18>'  : 'PMSM_to_BLDC_mod1/Subsystem5/Control_Reg_2'
 * '<S19>'  : 'PMSM_to_BLDC_mod1/Subsystem5/Ctrl_Reg_1'
 */
#endif                                 /* PMSM_to_BLDC_mod1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
