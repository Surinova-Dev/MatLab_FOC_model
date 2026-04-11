/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.h
 *
 * Code generated for Simulink model 'PMSM_to_BLDC_mod1'.
 *
 * Model version                  : 4.375
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Sat Apr 11 19:18:24 2026
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
#include "rt_nonfinite.h"
#include "math.h"
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

/* Block states (default storage) for system '<S2>/Bit Shift' */
typedef struct {
  int32_T sfEvent;                     /* '<S4>/bit_shift' */
  boolean_T doneDoubleBufferReInit;    /* '<S4>/bit_shift' */
} DW_BitShift_PMSM_to_BLDC_mod1_T;

/* Block states (default storage) for system '<S2>/Bit Shift4' */
typedef struct {
  int32_T sfEvent;                     /* '<S5>/bit_shift' */
  boolean_T doneDoubleBufferReInit;    /* '<S5>/bit_shift' */
} DW_BitShift4_PMSM_to_BLDC_mod_T;

/* Block signals (default storage) */
typedef struct {
  real_T MultiportSwitch;              /* '<S1>/Multiport Switch' */
  uint16_T BitwiseAND;                 /* '<S2>/Bitwise AND' */
  uint16_T BitwiseAND1;                /* '<S3>/Bitwise AND1' */
  uint16_T SPITransmit;                /* '<S1>/SPI Transmit' */
} B_PMSM_to_BLDC_mod1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S1>/SPI Transmit' */
  real_T Delay_DSTATE;                 /* '<S1>/Delay' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S1>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S1>/Scope1' */

  DW_BitShift4_PMSM_to_BLDC_mod_T BitShift2;/* '<S3>/Bit Shift2' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift1;/* '<S3>/Bit Shift1' */
  DW_BitShift4_PMSM_to_BLDC_mod_T BitShift4;/* '<S2>/Bit Shift4' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift;/* '<S2>/Bit Shift' */
} DW_PMSM_to_BLDC_mod1_T;

/* Invariant block signals (default storage) */
typedef struct {
  const uint16_T BitwiseOR;            /* '<S2>/Bitwise OR' */
  const uint16_T BitwiseOR1;           /* '<S3>/Bitwise OR1' */
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
 * Block '<S2>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S1>'   : 'PMSM_to_BLDC_mod1/SPI_Section'
 * '<S2>'   : 'PMSM_to_BLDC_mod1/SPI_Section/Ctrl_Reg_1'
 * '<S3>'   : 'PMSM_to_BLDC_mod1/SPI_Section/Ctrl_reg_2'
 * '<S4>'   : 'PMSM_to_BLDC_mod1/SPI_Section/Ctrl_Reg_1/Bit Shift'
 * '<S5>'   : 'PMSM_to_BLDC_mod1/SPI_Section/Ctrl_Reg_1/Bit Shift4'
 * '<S6>'   : 'PMSM_to_BLDC_mod1/SPI_Section/Ctrl_Reg_1/Bit Shift/bit_shift'
 * '<S7>'   : 'PMSM_to_BLDC_mod1/SPI_Section/Ctrl_Reg_1/Bit Shift4/bit_shift'
 * '<S8>'   : 'PMSM_to_BLDC_mod1/SPI_Section/Ctrl_reg_2/Bit Shift1'
 * '<S9>'   : 'PMSM_to_BLDC_mod1/SPI_Section/Ctrl_reg_2/Bit Shift2'
 * '<S10>'  : 'PMSM_to_BLDC_mod1/SPI_Section/Ctrl_reg_2/Bit Shift1/bit_shift'
 * '<S11>'  : 'PMSM_to_BLDC_mod1/SPI_Section/Ctrl_reg_2/Bit Shift2/bit_shift'
 */
#endif                                 /* PMSM_to_BLDC_mod1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
