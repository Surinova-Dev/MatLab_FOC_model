/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.h
 *
 * Code generated for Simulink model 'PMSM_to_BLDC_mod1'.
 *
 * Model version                  : 4.415
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Tue Apr 14 18:10:32 2026
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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block states (default storage) for system '<S12>/Bit Shift' */
typedef struct {
  int32_T sfEvent;                     /* '<S14>/bit_shift' */
  boolean_T doneDoubleBufferReInit;    /* '<S14>/bit_shift' */
} DW_BitShift_PMSM_to_BLDC_mod1_T;

/* Block states (default storage) for system '<S12>/Bit Shift1' */
typedef struct {
  int32_T sfEvent;                     /* '<S15>/bit_shift' */
  boolean_T doneDoubleBufferReInit;    /* '<S15>/bit_shift' */
} DW_BitShift1_PMSM_to_BLDC_mod_T;

/* Block signals for system '<S12>/SPI Controller Transfer' */
typedef struct {
  uint16_T SPIControllerTransfer;      /* '<S12>/SPI Controller Transfer' */
} B_SPIControllerTransfer_PMSM__T;

/* Block states (default storage) for system '<S12>/SPI Controller Transfer' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S12>/SPI Controller Transfer' */
  boolean_T objisempty;                /* '<S12>/SPI Controller Transfer' */
} DW_SPIControllerTransfer_PMSM_T;

/* Block signals (default storage) */
typedef struct {
  real_T Gain;                         /* '<S1>/Gain' */
  real_T Gain1;                        /* '<S1>/Gain1' */
  real_T Gain_g;                       /* '<S3>/Gain' */
  uint16_T AnalogtoDigitalConverter;   /* '<S24>/Analog to Digital Converter' */
  uint16_T BitwiseOR;                  /* '<S12>/Bitwise OR' */
  uint16_T DataTypeConversion;         /* '<S12>/Data Type Conversion' */
  uint16_T BitwiseOR_e;                /* '<S13>/Bitwise OR' */
  uint16_T BitwiseAND1;                /* '<S13>/Bitwise AND1' */
  uint16_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<S11>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux_at_outport_0Inport1' */
  B_SPIControllerTransfer_PMSM__T SPIControllerTransfer_p;/* '<S12>/SPI Controller Transfer' */
  B_SPIControllerTransfer_PMSM__T SPIControllerTransfer;/* '<S12>/SPI Controller Transfer' */
} B_PMSM_to_BLDC_mod1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S24>/Analog to Digital Converter' */
  stm32cube_blocks_AnalogInput__T obj_o;/* '<S9>/Analog to Digital Converter' */
  stm32cube_blocks_AnalogInput__T obj_d;/* '<S7>/Analog to Digital Converter' */
  real_T Delay_DSTATE;                 /* '<S2>/Delay' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S3>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_k;                     /* '<S11>/Scope' */

  int8_T SPI_read_SubsysRanBC;         /* '<S2>/SPI_read' */
  DW_SPIControllerTransfer_PMSM_T SPIControllerTransfer_p;/* '<S12>/SPI Controller Transfer' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1_i;/* '<S13>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift_j;/* '<S13>/Bit Shift' */
  DW_SPIControllerTransfer_PMSM_T SPIControllerTransfer;/* '<S12>/SPI Controller Transfer' */
  DW_BitShift1_PMSM_to_BLDC_mod_T BitShift1;/* '<S12>/Bit Shift1' */
  DW_BitShift_PMSM_to_BLDC_mod1_T BitShift;/* '<S12>/Bit Shift' */
} DW_PMSM_to_BLDC_mod1_T;

/* Invariant block signals (default storage) */
typedef struct {
  const uint16_T BitwiseAND;           /* '<S12>/Bitwise AND' */
  const uint16_T BitwiseAND_k;         /* '<S13>/Bitwise AND' */
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

/* External function called from main */
extern void PMSM_to_BLDC_mod1_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void PMSM_to_BLDC_mod1_initialize(void);
extern void PMSM_to_BLDC_mod1_step0(void);/* Sample time: [0.1s, 0.0s] */
extern void PMSM_to_BLDC_mod1_step1(void);/* Sample time: [1.0s, 0.0s] */
extern void PMSM_to_BLDC_mod1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PMSM_to_BLDC_mod1_T *const PMSM_to_BLDC_mod1_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<S1>'   : 'PMSM_to_BLDC_mod1/Current_sensing'
 * '<S2>'   : 'PMSM_to_BLDC_mod1/Spi_read(check)'
 * '<S3>'   : 'PMSM_to_BLDC_mod1/V_sense'
 * '<S4>'   : 'PMSM_to_BLDC_mod1/Current_sensing/Analog to Digital Converter1'
 * '<S5>'   : 'PMSM_to_BLDC_mod1/Current_sensing/Analog to Digital Converter2'
 * '<S6>'   : 'PMSM_to_BLDC_mod1/Current_sensing/Analog to Digital Converter1/ECSoC'
 * '<S7>'   : 'PMSM_to_BLDC_mod1/Current_sensing/Analog to Digital Converter1/ECSoC/ECSimCodegen'
 * '<S8>'   : 'PMSM_to_BLDC_mod1/Current_sensing/Analog to Digital Converter2/ECSoC'
 * '<S9>'   : 'PMSM_to_BLDC_mod1/Current_sensing/Analog to Digital Converter2/ECSoC/ECSimCodegen'
 * '<S10>'  : 'PMSM_to_BLDC_mod1/Spi_read(check)/Compare To Constant'
 * '<S11>'  : 'PMSM_to_BLDC_mod1/Spi_read(check)/SPI_read'
 * '<S12>'  : 'PMSM_to_BLDC_mod1/Spi_read(check)/SPI_read/Control_Reg1_read'
 * '<S13>'  : 'PMSM_to_BLDC_mod1/Spi_read(check)/SPI_read/Control_Reg_2_read'
 * '<S14>'  : 'PMSM_to_BLDC_mod1/Spi_read(check)/SPI_read/Control_Reg1_read/Bit Shift'
 * '<S15>'  : 'PMSM_to_BLDC_mod1/Spi_read(check)/SPI_read/Control_Reg1_read/Bit Shift1'
 * '<S16>'  : 'PMSM_to_BLDC_mod1/Spi_read(check)/SPI_read/Control_Reg1_read/Bit Shift/bit_shift'
 * '<S17>'  : 'PMSM_to_BLDC_mod1/Spi_read(check)/SPI_read/Control_Reg1_read/Bit Shift1/bit_shift'
 * '<S18>'  : 'PMSM_to_BLDC_mod1/Spi_read(check)/SPI_read/Control_Reg_2_read/Bit Shift'
 * '<S19>'  : 'PMSM_to_BLDC_mod1/Spi_read(check)/SPI_read/Control_Reg_2_read/Bit Shift1'
 * '<S20>'  : 'PMSM_to_BLDC_mod1/Spi_read(check)/SPI_read/Control_Reg_2_read/Bit Shift/bit_shift'
 * '<S21>'  : 'PMSM_to_BLDC_mod1/Spi_read(check)/SPI_read/Control_Reg_2_read/Bit Shift1/bit_shift'
 * '<S22>'  : 'PMSM_to_BLDC_mod1/V_sense/Analog to Digital Converter1'
 * '<S23>'  : 'PMSM_to_BLDC_mod1/V_sense/Analog to Digital Converter1/ECSoC'
 * '<S24>'  : 'PMSM_to_BLDC_mod1/V_sense/Analog to Digital Converter1/ECSoC/ECSimCodegen'
 */
#endif                                 /* PMSM_to_BLDC_mod1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
