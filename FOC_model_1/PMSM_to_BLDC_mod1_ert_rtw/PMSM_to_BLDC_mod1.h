/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.h
 *
 * Code generated for Simulink model 'PMSM_to_BLDC_mod1'.
 *
 * Model version                  : 4.632
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Tue Apr 21 17:19:39 2026
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
#include "MW_SPI.h"
#include "mw_stm32_spi_ll.h"
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

/* Block states (default storage) for system '<S4>/Bit Shift' */
typedef struct {
  int32_T sfEvent;                     /* '<S6>/bit_shift' */
  boolean_T doneDoubleBufferReInit;    /* '<S6>/bit_shift' */
} DW_BitShift_PMSM_to_BLDC_mod1_T;

/* Block states (default storage) for system '<S4>/Bit Shift1' */
typedef struct {
  int32_T sfEvent;                     /* '<S7>/bit_shift' */
  boolean_T doneDoubleBufferReInit;    /* '<S7>/bit_shift' */
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
  uint16_T ctrl_reg1;                  /* '<S5>/Bitwise AND' */
  uint16_T BitwiseOR;                  /* '<S4>/Bitwise OR' */
  uint16_T DataTypeConversion;         /* '<S4>/Data Type Conversion' */
  boolean_T AND1;                      /* '<S2>/AND1' */
  boolean_T AND;                       /* '<S2>/AND' */
} B_PMSM_to_BLDC_mod1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S5>/SPI Transmit' */
  stm32cube_blocks_SPIControlle_T obj_j;/* '<S4>/SPI Transmit' */
  stm32cube_blocks_DigitalPortW_T obj_o;/* '<S16>/Digital Port Write' */
  real_T CS_val;                       /* '<Root>/Chart' */
  struct {
    void *LoggedData[7];
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<S2>/Scope' */

  uint32_T is_c3_PMSM_to_BLDC_mod1;    /* '<Root>/Chart' */
  uint16_T temporalCounter_i1;         /* '<Root>/Chart' */
  int8_T Ctrl_Reg_1_SubsysRanBC;       /* '<S2>/Ctrl_Reg_1' */
  int8_T Control_Reg1_read_SubsysRanBC;/* '<S2>/Control_Reg1_read' */
  uint8_T is_active_c3_PMSM_to_BLDC_mod1;/* '<Root>/Chart' */
  boolean_T Ctrl_Reg_1_MODE;           /* '<S2>/Ctrl_Reg_1' */
  boolean_T Control_Reg1_read_MODE;    /* '<S2>/Control_Reg1_read' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift4;/* '<S5>/Bit Shift4' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift_m;/* '<S5>/Bit Shift' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1;/* '<S4>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift;/* '<S4>/Bit Shift' */
} DW_PMSM_to_BLDC_mod1_T;

/* Invariant block signals (default storage) */
typedef struct {
  const uint16_T BitwiseOR;            /* '<S5>/Bitwise OR' */
  const uint16_T BitwiseAND;           /* '<S4>/Bitwise AND' */
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
 * Block '<S5>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * '<S2>'   : 'PMSM_to_BLDC_mod1/Subsystem2'
 * '<S3>'   : 'PMSM_to_BLDC_mod1/Subsystem3'
 * '<S4>'   : 'PMSM_to_BLDC_mod1/Subsystem2/Control_Reg1_read'
 * '<S5>'   : 'PMSM_to_BLDC_mod1/Subsystem2/Ctrl_Reg_1'
 * '<S6>'   : 'PMSM_to_BLDC_mod1/Subsystem2/Control_Reg1_read/Bit Shift'
 * '<S7>'   : 'PMSM_to_BLDC_mod1/Subsystem2/Control_Reg1_read/Bit Shift1'
 * '<S8>'   : 'PMSM_to_BLDC_mod1/Subsystem2/Control_Reg1_read/Bit Shift/bit_shift'
 * '<S9>'   : 'PMSM_to_BLDC_mod1/Subsystem2/Control_Reg1_read/Bit Shift1/bit_shift'
 * '<S10>'  : 'PMSM_to_BLDC_mod1/Subsystem2/Ctrl_Reg_1/Bit Shift'
 * '<S11>'  : 'PMSM_to_BLDC_mod1/Subsystem2/Ctrl_Reg_1/Bit Shift4'
 * '<S12>'  : 'PMSM_to_BLDC_mod1/Subsystem2/Ctrl_Reg_1/Bit Shift/bit_shift'
 * '<S13>'  : 'PMSM_to_BLDC_mod1/Subsystem2/Ctrl_Reg_1/Bit Shift4/bit_shift'
 * '<S14>'  : 'PMSM_to_BLDC_mod1/Subsystem3/Digital Port Write'
 * '<S15>'  : 'PMSM_to_BLDC_mod1/Subsystem3/Digital Port Write/ECSoC'
 * '<S16>'  : 'PMSM_to_BLDC_mod1/Subsystem3/Digital Port Write/ECSoC/ECSimCodegen'
 */
#endif                                 /* PMSM_to_BLDC_mod1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
