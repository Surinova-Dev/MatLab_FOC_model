/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.c
 *
 * Code generated for Simulink model 'PMSM_to_BLDC_mod1'.
 *
 * Model version                  : 4.695
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Fri Apr 24 16:35:02 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PMSM_to_BLDC_mod1.h"
#include "rtwtypes.h"
#include "PMSM_to_BLDC_mod1_types.h"
#include "PMSM_to_BLDC_mod1_private.h"
#include "mw_stm32_spi_ll.h"

/* Named constants for MATLAB Function: '<S7>/bit_shift' */
#define PMSM_to_BLDC_mod1_CALL_EVENT   (-1)

/* Named constants for MATLAB Function: '<S8>/bit_shift' */
#define PMSM_to_BLDC_mod1_CALL_EVENT_j (-1)

/* Named constants for Chart: '<Root>/Chart' */
#define PMSM_to_BLDC__IN_Initialization (2U)
#define PMSM_to_BLDC_mod1_IN_En_Gate   (1U)
#define PMSM_to_BLDC_mod1_IN_SPI_init1 (4U)
#define PMSM_to_BLDC_mod1_IN_SPI_init2 (5U)
#define PMSM_to_BLDC_mod1_IN_SPI_init3 (6U)
#define PMSM_to_BLDC_mod1_IN_SPI_init4 (7U)
#define PMSM_to_BLDC_mod1_IN_SPI_start (8U)
#define PMSM_to_BLDC_mod1_IN_SPI_write (9U)
#define PMSM_to_BLDC_mod1_IN_SPI_write2 (10U)
#define PMSM_to_BLDC_mod1_IN_SPI_write5 (11U)
#define PMSM_to_BLDC_mod1_IN_SPI_write6 (12U)
#define PMSM_to_BLDC_mod_IN_SPI_Start2_ (3U)

/* Block signals (default storage) */
B_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_B;

/* Block states (default storage) */
DW_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_DW;

/* Real-time model */
static RT_MODEL_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_M_;
RT_MODEL_PMSM_to_BLDC_mod1_T *const PMSM_to_BLDC_mod1_M = &PMSM_to_BLDC_mod1_M_;

/* Forward declaration for local functions */
static void PMSM_to_BLDC_m_SystemCore_setup(stm32cube_blocks_SPIControlle_T *obj);

/* Forward declaration for local functions */
static void PMSM_to_BLDC_SystemCore_setup_o(stm32cube_blocks_SPIControlle_T *obj);
static void PMSM_to_B_SPIDrvBlock_setupImpl(stm32cube_blocks_SPIControl_o_T *obj);
static void PMSM_to_BLD_SystemCore_setup_ox(stm32cube_blocks_SPIControlle_T *obj);
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1])++;
  if ((PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1]) > 999) {/* Sample time: [1.0s, 0.0s] */
    PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * System initialize for atomic system:
 *    '<S5>/Bit Shift'
 *    '<S6>/Bit Shift'
 *    '<S18>/Bit Shift'
 *    '<S19>/Bit Shift'
 */
void PMSM_to_BLDC_mod1_BitShift_Init(DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* SystemInitialize for MATLAB Function: '<S7>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
}

/*
 * System reset for atomic system:
 *    '<S5>/Bit Shift'
 *    '<S6>/Bit Shift'
 *    '<S18>/Bit Shift'
 *    '<S19>/Bit Shift'
 */
void PMSM_to_BLDC_mod_BitShift_Reset(DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* SystemReset for MATLAB Function: '<S7>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
}

/*
 * Output and update for atomic system:
 *    '<S5>/Bit Shift'
 *    '<S6>/Bit Shift'
 *    '<S18>/Bit Shift'
 *    '<S19>/Bit Shift'
 */
void PMSM_to_BLDC_mod1_BitShift(uint16_T rtu_u, uint16_T *rty_y,
  DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* MATLAB Function: '<S7>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
  *rty_y = (uint16_T)(rtu_u << 15);
}

/*
 * System initialize for atomic system:
 *    '<S5>/Bit Shift1'
 *    '<S6>/Bit Shift1'
 *    '<S18>/Bit Shift1'
 *    '<S19>/Bit Shift1'
 */
void PMSM_to_BLDC_mod_BitShift1_Init(DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* SystemInitialize for MATLAB Function: '<S8>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_j;
}

/*
 * System reset for atomic system:
 *    '<S5>/Bit Shift1'
 *    '<S6>/Bit Shift1'
 *    '<S18>/Bit Shift1'
 *    '<S19>/Bit Shift1'
 */
void PMSM_to_BLDC_mo_BitShift1_Reset(DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* SystemReset for MATLAB Function: '<S8>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_j;
}

/*
 * Output and update for atomic system:
 *    '<S5>/Bit Shift1'
 *    '<S6>/Bit Shift1'
 *    '<S18>/Bit Shift1'
 *    '<S19>/Bit Shift1'
 */
void PMSM_to_BLDC_mod1_BitShift1(uint16_T rtu_u, uint16_T *rty_y,
  DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* MATLAB Function: '<S8>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_j;
  *rty_y = (uint16_T)(rtu_u << 11);
}

static void PMSM_to_BLDC_m_SystemCore_setup(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S18>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S18>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S18>/SPI Receive' */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 15.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
  obj->isSetupComplete = true;
}

/* System initialize for atomic system: */
void PMSM_to_BLDC_mo_SPIReceive_Init(DW_SPIReceive_PMSM_to_BLDC_mo_T *localDW)
{
  /* Start for MATLABSystem: '<S18>/SPI Receive' */
  localDW->obj.isInitialized = 0;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  PMSM_to_BLDC_m_SystemCore_setup(&localDW->obj);
}

/* Output and update for atomic system: */
void PMSM_to_BLDC_mod1_SPIReceive(B_SPIReceive_PMSM_to_BLDC_mod_T *localB,
  DW_SPIReceive_PMSM_to_BLDC_mo_T *localDW)
{
  uint16_T status;

  /* MATLABSystem: '<S18>/SPI Receive' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    MW_SPI_Read_Databits(localDW->obj.MW_SPI_HANDLE, &localB->SPIReceive[0], 15U,
                         1, 1, 1U);
    LL_GPIO_SetOutputPin(GPIOC, 16384U);
  }

  /* End of MATLABSystem: '<S18>/SPI Receive' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC_mo_SPIReceive_Term(DW_SPIReceive_PMSM_to_BLDC_mo_T *localDW)
{
  /* Terminate for MATLABSystem: '<S18>/SPI Receive' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S18>/SPI Receive' */
}

static void PMSM_to_BLDC_SystemCore_setup_o(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S5>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S5>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S5>/SPI Receive' */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 16.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
  obj->isSetupComplete = true;
}

static void PMSM_to_B_SPIDrvBlock_setupImpl(stm32cube_blocks_SPIControl_o_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;

  /* Start for MATLABSystem: '<S5>/SPI Transmit' incorporates:
   *  MATLABSystem: '<S18>/SPI Transmit'
   *  MATLABSystem: '<S19>/SPI Transmit'
   *  MATLABSystem: '<S6>/SPI Transmit'
   */
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S5>/SPI Transmit' incorporates:
   *  MATLABSystem: '<S18>/SPI Transmit'
   *  MATLABSystem: '<S19>/SPI Transmit'
   *  MATLABSystem: '<S6>/SPI Transmit'
   */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S5>/SPI Transmit' incorporates:
   *  MATLABSystem: '<S18>/SPI Transmit'
   *  MATLABSystem: '<S19>/SPI Transmit'
   *  MATLABSystem: '<S6>/SPI Transmit'
   */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 1.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
}

static void PMSM_to_BLD_SystemCore_setup_ox(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S6>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S6>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S6>/SPI Receive' */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 1.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
  obj->isSetupComplete = true;
}

/* Model step function */
void PMSM_to_BLDC_mod1_step(void)
{
  GPIO_TypeDef * portNameLoc;
  uint32_T shiftVal;
  int32_T i;
  uint32_T pinMask;
  uint32_T pinWriteLoc;
  uint16_T tmp[16];
  uint16_T status;
  uint16_T y_n;

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_SubsysRanBC);
  if (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Chart: '<Root>/Chart' */
    if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 < 7) {
      PMSM_to_BLDC_mod1_DW.temporalCounter_i1++;
    }

    if (PMSM_to_BLDC_mod1_DW.is_active_c3_PMSM_to_BLDC_mod1 == 0) {
      PMSM_to_BLDC_mod1_DW.is_active_c3_PMSM_to_BLDC_mod1 = 1U;
      PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
      PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
        PMSM_to_BLDC__IN_Initialization;
      PMSM_to_BLDC_mod1_DW.CS_val = 1.0;
      PMSM_to_BLDC_mod1_B.En_State = 0.0;
    } else {
      switch (PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1) {
       case PMSM_to_BLDC_mod1_IN_En_Gate:
        PMSM_to_BLDC_mod1_B.En_State = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_start;
          PMSM_to_BLDC_mod1_B.SPI_int = 1.0;
        }
        break;

       case PMSM_to_BLDC__IN_Initialization:
        PMSM_to_BLDC_mod1_B.En_State = 0.0;
        if (PMSM_to_BLDC_mod1_DW.CS_val == 1.0) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_En_Gate;
          PMSM_to_BLDC_mod1_B.En_State = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod_IN_SPI_Start2_:
        PMSM_to_BLDC_mod1_B.SPI_int = 0.0;
        if ((PMSM_to_BLDC_mod1_B.En_State == 1.0) &&
            (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 5)) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_init1;
          PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_init1:
        PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 5) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_init2;
          PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 0.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_init2:
        PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 0.0;
        PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
        PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
          PMSM_to_BLDC_mod1_IN_SPI_init3;
        PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 1.0;
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_init3:
        PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 3) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_init4;
          PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 0.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_init4:
        PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 0.0;
        PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
        PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
          PMSM_to_BLDC_mod1_IN_SPI_write;
        PMSM_to_BLDC_mod1_B.spi_write1 = 1.0;
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_start:
        PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
        PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
          PMSM_to_BLDC_mod_IN_SPI_Start2_;
        PMSM_to_BLDC_mod1_B.SPI_int = 0.0;
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write:
        PMSM_to_BLDC_mod1_B.spi_write1 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_write2;
          PMSM_to_BLDC_mod1_B.spi_write1 = 0.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write2:
        PMSM_to_BLDC_mod1_B.spi_write1 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_write5;
          PMSM_to_BLDC_mod1_B.spi_write2 = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write5:
        PMSM_to_BLDC_mod1_B.spi_write2 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_write6;
          PMSM_to_BLDC_mod1_B.spi_write2 = 0.0;
        }
        break;

       default:
        /* case IN_SPI_write6: */
        PMSM_to_BLDC_mod1_B.spi_write2 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_SPI_write;
          PMSM_to_BLDC_mod1_B.spi_write1 = 1.0;
        }
        break;
      }
    }

    /* End of Chart: '<Root>/Chart' */

    /* Logic: '<S2>/AND' */
    PMSM_to_BLDC_mod1_B.AND = ((PMSM_to_BLDC_mod1_B.En_State != 0.0) &&
      (PMSM_to_BLDC_mod1_B.Ctrl_flag1 != 0.0));

    /* Logic: '<S2>/AND1' */
    PMSM_to_BLDC_mod1_B.AND1 = ((PMSM_to_BLDC_mod1_B.En_State != 0.0) &&
      (PMSM_to_BLDC_mod1_B.Ctrl_flag2 != 0.0));

    /* Outputs for Enabled SubSystem: '<S2>/Control_Reg2' incorporates:
     *  EnablePort: '<S5>/Enable'
     */
    if (PMSM_to_BLDC_mod1_B.AND1) {
      if (!PMSM_to_BLDC_mod1_DW.Control_Reg2_MODE) {
        /* SystemReset for Atomic SubSystem: '<S5>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift);

        /* End of SystemReset for SubSystem: '<S5>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S5>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1);

        /* End of SystemReset for SubSystem: '<S5>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Control_Reg2_MODE = true;
      }

      /* MATLABSystem: '<S5>/SPI Receive' */
      status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_g.MW_SPI_HANDLE,
        2U, 3840U, MW_SPI_MODE_3);
      if (status == 0) {
        MW_SPI_Read_Databits(PMSM_to_BLDC_mod1_DW.obj_g.MW_SPI_HANDLE, &tmp[0],
                             16U, 1, 1, 1U);
        LL_GPIO_SetOutputPin(GPIOC, 16384U);
      }

      /* End of MATLABSystem: '<S5>/SPI Receive' */

      /* Outputs for Atomic SubSystem: '<S5>/Bit Shift' */
      /* Constant: '<S5>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(0, &status, &PMSM_to_BLDC_mod1_DW.BitShift);

      /* End of Outputs for SubSystem: '<S5>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S5>/Bit Shift1' */
      /* Constant: '<S5>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(3, &y_n, &PMSM_to_BLDC_mod1_DW.BitShift1);

      /* End of Outputs for SubSystem: '<S5>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S5>/Bitwise OR' */
      PMSM_to_BLDC_mod1_B.BitwiseOR_nh = (uint16_T)(status | y_n |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_j);

      /* DataTypeConversion: '<S5>/Data Type Conversion' */
      PMSM_to_BLDC_mod1_B.DataTypeConversion_m =
        PMSM_to_BLDC_mod1_B.BitwiseOR_nh;

      /* MATLABSystem: '<S5>/SPI Transmit' */
      status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE,
        2U, 3840U, MW_SPI_MODE_3);
      if (status == 0) {
        LL_GPIO_ResetOutputPin(GPIOC, 16384U);
        MW_SPI_Write_Databits(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE,
                              &PMSM_to_BLDC_mod1_B.DataTypeConversion_m, 1U, 1,
                              1, 1000U);
      }

      /* End of MATLABSystem: '<S5>/SPI Transmit' */
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC);
    } else {
      PMSM_to_BLDC_mod1_DW.Control_Reg2_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S2>/Control_Reg2' */

    /* Outputs for Enabled SubSystem: '<S2>/Ctrl_Reg_1' incorporates:
     *  EnablePort: '<S6>/Enable'
     */
    if (PMSM_to_BLDC_mod1_B.AND) {
      if (!PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_MODE) {
        /* SystemReset for Atomic SubSystem: '<S6>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_h);

        /* End of SystemReset for SubSystem: '<S6>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S6>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_d);

        /* End of SystemReset for SubSystem: '<S6>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_MODE = true;
      }

      /* Outputs for Atomic SubSystem: '<S6>/Bit Shift' */
      /* Constant: '<S6>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(0, &status, &PMSM_to_BLDC_mod1_DW.BitShift_h);

      /* End of Outputs for SubSystem: '<S6>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S6>/Bit Shift1' */
      /* Constant: '<S6>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(2, &y_n, &PMSM_to_BLDC_mod1_DW.BitShift1_d);

      /* End of Outputs for SubSystem: '<S6>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S6>/Bitwise OR' */
      y_n = (uint16_T)(status | y_n | PMSM_to_BLDC_mod1_ConstB.BitwiseAND_e);

      /* MATLABSystem: '<S6>/SPI Transmit' */
      status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_n.MW_SPI_HANDLE,
        2U, 3840U, MW_SPI_MODE_3);
      if (status == 0) {
        LL_GPIO_ResetOutputPin(GPIOC, 16384U);
        MW_SPI_Write_Databits(PMSM_to_BLDC_mod1_DW.obj_n.MW_SPI_HANDLE, &y_n, 1U,
                              1, 1, 10U);
      }

      /* End of MATLABSystem: '<S6>/SPI Transmit' */

      /* MATLABSystem: '<S6>/SPI Receive' */
      status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, 2U,
        3840U, MW_SPI_MODE_3);
      if (status == 0) {
        MW_SPI_Read_Databits(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, &status, 1U,
                             1, 1, 1U);
        LL_GPIO_SetOutputPin(GPIOC, 16384U);
      }

      /* End of MATLABSystem: '<S6>/SPI Receive' */
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC);
    } else {
      PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S2>/Ctrl_Reg_1' */

    /* Outputs for Enabled SubSystem: '<S4>/Control_Reg1_read' incorporates:
     *  EnablePort: '<S18>/Ctrl_flag1'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write1 > 0.0) {
      if (!PMSM_to_BLDC_mod1_DW.Control_Reg1_read_MODE) {
        /* SystemReset for Atomic SubSystem: '<S18>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_e);

        /* End of SystemReset for SubSystem: '<S18>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S18>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_l);

        /* End of SystemReset for SubSystem: '<S18>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Control_Reg1_read_MODE = true;
      }

      PMSM_to_BLDC_mod1_SPIReceive(&PMSM_to_BLDC_mod1_B.SPIReceive_p,
        &PMSM_to_BLDC_mod1_DW.SPIReceive_p);

      /* Outputs for Atomic SubSystem: '<S18>/Bit Shift' */
      /* Constant: '<S18>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(1, &status, &PMSM_to_BLDC_mod1_DW.BitShift_e);

      /* End of Outputs for SubSystem: '<S18>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S18>/Bit Shift1' */
      /* Constant: '<S18>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(2, &y_n, &PMSM_to_BLDC_mod1_DW.BitShift1_l);

      /* End of Outputs for SubSystem: '<S18>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S18>/Bitwise OR' */
      PMSM_to_BLDC_mod1_B.BitwiseOR_n = (uint16_T)(status | y_n |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_b);

      /* DataTypeConversion: '<S18>/Data Type Conversion' */
      PMSM_to_BLDC_mod1_B.DataTypeConversion = PMSM_to_BLDC_mod1_B.BitwiseOR_n;

      /* MATLABSystem: '<S18>/SPI Transmit' */
      status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_f.MW_SPI_HANDLE,
        2U, 3840U, MW_SPI_MODE_3);
      if (status == 0) {
        LL_GPIO_ResetOutputPin(GPIOC, 16384U);
        MW_SPI_Write_Databits(PMSM_to_BLDC_mod1_DW.obj_f.MW_SPI_HANDLE,
                              &PMSM_to_BLDC_mod1_B.DataTypeConversion, 1U, 1, 1,
                              1U);
      }

      /* End of MATLABSystem: '<S18>/SPI Transmit' */
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC);
    } else if (PMSM_to_BLDC_mod1_DW.Control_Reg1_read_MODE) {
      /* Disable for Outport: '<S18>/Out1' incorporates:
       *  MATLABSystem: '<S18>/SPI Receive'
       */
      for (i = 0; i < 15; i++) {
        PMSM_to_BLDC_mod1_B.SPIReceive_p.SPIReceive[i] = 0U;
      }

      /* End of Disable for Outport: '<S18>/Out1' */
      PMSM_to_BLDC_mod1_DW.Control_Reg1_read_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S4>/Control_Reg1_read' */

    /* Outputs for Enabled SubSystem: '<S4>/Control_Reg_2_read' incorporates:
     *  EnablePort: '<S19>/Ctrl_flag2'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write2 > 0.0) {
      if (!PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_MODE) {
        /* SystemReset for Atomic SubSystem: '<S19>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_b);

        /* End of SystemReset for SubSystem: '<S19>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S19>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_m);

        /* End of SystemReset for SubSystem: '<S19>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_MODE = true;
      }

      PMSM_to_BLDC_mod1_SPIReceive(&PMSM_to_BLDC_mod1_B.SPIReceive_pn,
        &PMSM_to_BLDC_mod1_DW.SPIReceive_pn);

      /* Outputs for Atomic SubSystem: '<S19>/Bit Shift' */
      /* Constant: '<S19>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(1, &status, &PMSM_to_BLDC_mod1_DW.BitShift_b);

      /* End of Outputs for SubSystem: '<S19>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S19>/Bit Shift1' */
      /* Constant: '<S19>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(3, &y_n, &PMSM_to_BLDC_mod1_DW.BitShift1_m);

      /* End of Outputs for SubSystem: '<S19>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S19>/Bitwise OR' */
      PMSM_to_BLDC_mod1_B.BitwiseOR = (uint16_T)(status | y_n |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND);

      /* MATLABSystem: '<S19>/SPI Transmit' */
      status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_k.MW_SPI_HANDLE,
        2U, 3840U, MW_SPI_MODE_3);
      if (status == 0) {
        LL_GPIO_ResetOutputPin(GPIOC, 16384U);
        MW_SPI_Write_Databits(PMSM_to_BLDC_mod1_DW.obj_k.MW_SPI_HANDLE,
                              &PMSM_to_BLDC_mod1_B.BitwiseOR, 1U, 1, 1, 1U);
      }

      /* End of MATLABSystem: '<S19>/SPI Transmit' */
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_SubsysRanBC);
    } else if (PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_MODE) {
      for (i = 0; i < 15; i++) {
        /* Disable for MATLABSystem: '<S19>/SPI Receive' incorporates:
         *  Outport: '<S19>/Out1'
         */
        PMSM_to_BLDC_mod1_B.SPIReceive_pn.SPIReceive[i] = 0U;
      }

      PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S4>/Control_Reg_2_read' */
    /* MATLABSystem: '<S17>/Digital Port Write' */
    portNameLoc = GPIOB;
    shiftVal = MW_GPIO_BIT_SHIFT;
    if (PMSM_to_BLDC_mod1_B.En_State != 0.0) {
      pinWriteLoc = 4096U;
    } else {
      pinWriteLoc = 0U;
    }

    pinWriteLoc = mw_shift(pinWriteLoc, shiftVal);
    pinMask = mw_shift(4096U, shiftVal);
    LL_GPIO_SetOutputPin(portNameLoc, pinWriteLoc);
    LL_GPIO_ResetOutputPin(portNameLoc, ~pinWriteLoc & pinMask);

    /* End of MATLABSystem: '<S17>/Digital Port Write' */
  }

  {                                    /* Sample time: [0.001s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      PMSM_to_BLDC_mod1_M->Timing.taskTime0;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0, extmodeTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  if (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [1.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((PMSM_to_BLDC_mod1_M->Timing.clockTick1) * 1.0);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1, extmodeTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  PMSM_to_BLDC_mod1_M->Timing.taskTime0 =
    ((time_T)(++PMSM_to_BLDC_mod1_M->Timing.clockTick0)) *
    PMSM_to_BLDC_mod1_M->Timing.stepSize0;
  if (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [1.0s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 1.0, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    PMSM_to_BLDC_mod1_M->Timing.clockTick1++;
  }

  rate_scheduler();
}

/* Model initialize function */
void PMSM_to_BLDC_mod1_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(PMSM_to_BLDC_mod1_M, 100.0);
  PMSM_to_BLDC_mod1_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  PMSM_to_BLDC_mod1_M->Sizes.checksums[0] = (785991948U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[1] = (1320934759U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[2] = (2382660101U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[3] = (2770226397U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[31];
    PMSM_to_BLDC_mod1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[3] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[4] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[5] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[6] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[7] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[8] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[9] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[10] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[11] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[12] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[13] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[14] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[15] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC;
    systemRan[18] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC;
    systemRan[19] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC;
    systemRan[20] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC;
    systemRan[24] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_SubsysRanBC;
    systemRan[25] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_SubsysRanBC;
    systemRan[28] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_SubsysRanBC;
    systemRan[29] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_SubsysRanBC;
    systemRan[30] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_SubsysRanBC;
    rteiSetModelMappingInfoPtr(PMSM_to_BLDC_mod1_M->extModeInfo,
      &PMSM_to_BLDC_mod1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PMSM_to_BLDC_mod1_M->extModeInfo,
                        PMSM_to_BLDC_mod1_M->Sizes.checksums);
    rteiSetTPtr(PMSM_to_BLDC_mod1_M->extModeInfo, rtmGetTPtr(PMSM_to_BLDC_mod1_M));
  }

  /* SystemInitialize for Atomic SubSystem: '<S5>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift);

  /* End of SystemInitialize for SubSystem: '<S5>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S5>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1);

  /* End of SystemInitialize for SubSystem: '<S5>/Bit Shift1' */

  /* Start for MATLABSystem: '<S5>/SPI Receive' */
  PMSM_to_BLDC_mod1_DW.obj_g.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj_g.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_SystemCore_setup_o(&PMSM_to_BLDC_mod1_DW.obj_g);

  /* Start for MATLABSystem: '<S5>/SPI Transmit' */
  PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete = false;
  PMSM_to_BLDC_mod1_DW.obj_j.isInitialized = 1;
  PMSM_to_B_SPIDrvBlock_setupImpl(&PMSM_to_BLDC_mod1_DW.obj_j);
  PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<S2>/Control_Reg2' */

  /* SystemInitialize for Enabled SubSystem: '<S2>/Ctrl_Reg_1' */
  /* SystemInitialize for Atomic SubSystem: '<S6>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_h);

  /* End of SystemInitialize for SubSystem: '<S6>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S6>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_d);

  /* End of SystemInitialize for SubSystem: '<S6>/Bit Shift1' */

  /* Start for MATLABSystem: '<S6>/SPI Transmit' */
  PMSM_to_BLDC_mod1_DW.obj_n.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_n.isSetupComplete = false;
  PMSM_to_BLDC_mod1_DW.obj_n.isInitialized = 1;
  PMSM_to_B_SPIDrvBlock_setupImpl(&PMSM_to_BLDC_mod1_DW.obj_n);
  PMSM_to_BLDC_mod1_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S6>/SPI Receive' */
  PMSM_to_BLDC_mod1_DW.obj.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = false;
  PMSM_to_BLD_SystemCore_setup_ox(&PMSM_to_BLDC_mod1_DW.obj);

  /* End of SystemInitialize for SubSystem: '<S2>/Ctrl_Reg_1' */
  /* SystemInitialize for Atomic SubSystem: '<S18>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_e);

  /* End of SystemInitialize for SubSystem: '<S18>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S18>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_l);

  /* End of SystemInitialize for SubSystem: '<S18>/Bit Shift1' */
  PMSM_to_BLDC_mo_SPIReceive_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_p);

  /* Start for MATLABSystem: '<S18>/SPI Transmit' */
  PMSM_to_BLDC_mod1_DW.obj_f.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_f.isSetupComplete = false;
  PMSM_to_BLDC_mod1_DW.obj_f.isInitialized = 1;
  PMSM_to_B_SPIDrvBlock_setupImpl(&PMSM_to_BLDC_mod1_DW.obj_f);
  PMSM_to_BLDC_mod1_DW.obj_f.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<S4>/Control_Reg1_read' */
  /* SystemInitialize for Atomic SubSystem: '<S19>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_b);

  /* End of SystemInitialize for SubSystem: '<S19>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S19>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_m);

  /* End of SystemInitialize for SubSystem: '<S19>/Bit Shift1' */
  PMSM_to_BLDC_mo_SPIReceive_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pn);

  /* Start for MATLABSystem: '<S19>/SPI Transmit' */
  PMSM_to_BLDC_mod1_DW.obj_k.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_k.isSetupComplete = false;
  PMSM_to_BLDC_mod1_DW.obj_k.isInitialized = 1;
  PMSM_to_B_SPIDrvBlock_setupImpl(&PMSM_to_BLDC_mod1_DW.obj_k);
  PMSM_to_BLDC_mod1_DW.obj_k.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<S4>/Control_Reg_2_read' */

  /* Start for MATLABSystem: '<S17>/Digital Port Write' */
  PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_o.isInitialized = 1;
  PMSM_to_BLDC_mod1_DW.obj_o.isSetupComplete = true;
}

/* Model terminate function */
void PMSM_to_BLDC_mod1_terminate(void)
{
  uint32_T SPIPinsLoc;

  /* Terminate for Enabled SubSystem: '<S2>/Control_Reg2' */
  /* Terminate for MATLABSystem: '<S5>/SPI Receive' */
  if (!PMSM_to_BLDC_mod1_DW.obj_g.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_g.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_g.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_g.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/SPI Receive' */
  /* Terminate for MATLABSystem: '<S5>/SPI Transmit' */
  if (!PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_j.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/SPI Transmit' */
  /* Terminate for Enabled SubSystem: '<S2>/Ctrl_Reg_1' */
  /* Terminate for MATLABSystem: '<S6>/SPI Transmit' */
  if (!PMSM_to_BLDC_mod1_DW.obj_n.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_n.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_n.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_n.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/SPI Transmit' */

  /* Terminate for MATLABSystem: '<S6>/SPI Receive' */
  if (!PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S6>/SPI Receive' */
  /* End of Terminate for SubSystem: '<S2>/Ctrl_Reg_1' */

  /* Terminate for Enabled SubSystem: '<S4>/Control_Reg1_read' */
  PMSM_to_BLDC_mo_SPIReceive_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_p);

  /* Terminate for MATLABSystem: '<S18>/SPI Transmit' */
  if (!PMSM_to_BLDC_mod1_DW.obj_f.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_f.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_f.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_f.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S18>/SPI Transmit' */

  /* Terminate for Enabled SubSystem: '<S4>/Control_Reg_2_read' */
  PMSM_to_BLDC_mo_SPIReceive_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pn);

  /* Terminate for MATLABSystem: '<S19>/SPI Transmit' */
  if (!PMSM_to_BLDC_mod1_DW.obj_k.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_k.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_k.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_k.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S19>/SPI Transmit' */
  /* Terminate for MATLABSystem: '<S17>/Digital Port Write' */
  if (!PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S17>/Digital Port Write' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
