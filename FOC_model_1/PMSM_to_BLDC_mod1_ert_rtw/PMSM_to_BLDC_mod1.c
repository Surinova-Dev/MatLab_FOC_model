/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.c
 *
 * Code generated for Simulink model 'PMSM_to_BLDC_mod1'.
 *
 * Model version                  : 4.592
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Mon Apr 20 17:13:24 2026
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
#define PMSM_to_BLDC_mod1_IN_Reg1      (3U)
#define PMSM_to_BLDC_mod1_IN_Reg2      (4U)
#define PMSM_to_BLDC_mod_IN_SPI_Write_2 (5U)
#define PMSM_to_BLDC_mod_IN_SPI_write_1 (6U)

/* Block signals (default storage) */
B_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_B;

/* Block states (default storage) */
DW_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_DW;

/* Real-time model */
static RT_MODEL_PMSM_to_BLDC_mod1_T PMSM_to_BLDC_mod1_M_;
RT_MODEL_PMSM_to_BLDC_mod1_T *const PMSM_to_BLDC_mod1_M = &PMSM_to_BLDC_mod1_M_;

/* Forward declaration for local functions */
static void PMSM_to_B_SPIDrvBlock_setupImpl(stm32cube_blocks_SPIControlle_T *obj);

/* Forward declaration for local functions */
static void PMSM_to_SPIDrvBlock_setupImpl_e(stm32cube_blocks_SPIControlle_T *obj);

/* Forward declaration for local functions */
static void PMSM_to_SPIDrvBlock_setupImpl_o(stm32cube_blocks_SPIControl_o_T *obj);
static void PMSM_t_SPIDrvBlock_setupImpl_ox(stm32cube_blocks_SPIControl_o_T *obj);
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
 *    '<S6>/Bit Shift4'
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
 *    '<S6>/Bit Shift4'
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
 *    '<S6>/Bit Shift4'
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

static void PMSM_to_B_SPIDrvBlock_setupImpl(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;

  /* Start for MATLABSystem: '<S5>/SPI Transmit' */
  c.buffer.txBufferPtr = (uint16_T *)(&obj->spiTxInternalBuffer[0]);
  c.buffer.rxBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 2U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 128U;

  /* Start for MATLABSystem: '<S5>/SPI Transmit' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_INTERRUPT_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S5>/SPI Transmit' */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 1.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
}

/* System initialize for atomic system: */
void PMSM_to_BLDC_m_SPITransmit_Init(DW_SPITransmit_PMSM_to_BLDC_m_T *localDW)
{
  /* Start for MATLABSystem: '<S5>/SPI Transmit' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  PMSM_to_B_SPIDrvBlock_setupImpl(&localDW->obj);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void PMSM_to_BLDC_mod1_SPITransmit(uint16_T rtu_0,
  DW_SPITransmit_PMSM_to_BLDC_m_T *localDW)
{
  uint16_T spiWriteData;

  /* MATLABSystem: '<S5>/SPI Transmit' */
  spiWriteData = rtu_0;
  LL_GPIO_ResetOutputPin(GPIOC, 16384U);
  MW_SPI_TransmitUsingInterrupt(localDW->obj.MW_SPI_HANDLE, &spiWriteData, 1U,
    10U);
}

/* Termination for atomic system: */
void PMSM_to_BLDC_m_SPITransmit_Term(DW_SPITransmit_PMSM_to_BLDC_m_T *localDW)
{
  /* Terminate for MATLABSystem: '<S5>/SPI Transmit' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/SPI Transmit' */
}

static void PMSM_to_SPIDrvBlock_setupImpl_e(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;

  /* Start for MATLABSystem: '<S18>/SPI Transmit' */
  c.buffer.txBufferPtr = (uint16_T *)(&obj->spiTxInternalBuffer[0]);
  c.buffer.rxBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 2U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 128U;

  /* Start for MATLABSystem: '<S18>/SPI Transmit' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_INTERRUPT_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S18>/SPI Transmit' */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 1.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
}

/* System initialize for atomic system: */
void PMSM_to_BLDC_SPITransmit_d_Init(DW_SPITransmit_PMSM_to_BLDC_f_T *localDW)
{
  /* Start for MATLABSystem: '<S18>/SPI Transmit' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  PMSM_to_SPIDrvBlock_setupImpl_e(&localDW->obj);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void PMSM_to_BLDC_mod1_SPITransmit_p(uint16_T rtu_0,
  B_SPITransmit_PMSM_to_BLDC__c_T *localB, DW_SPITransmit_PMSM_to_BLDC_f_T
  *localDW)
{
  uint16_T spiWriteData;

  /* MATLABSystem: '<S18>/SPI Transmit' */
  spiWriteData = rtu_0;
  LL_GPIO_ResetOutputPin(GPIOC, 16384U);

  /* MATLABSystem: '<S18>/SPI Transmit' */
  localB->SPITransmit = MW_SPI_TransmitUsingInterrupt(localDW->obj.MW_SPI_HANDLE,
    &spiWriteData, 1U, 10U);
}

/* Termination for atomic system: */
void PMSM_to_BLDC_SPITransmit_a_Term(DW_SPITransmit_PMSM_to_BLDC_f_T *localDW)
{
  /* Terminate for MATLABSystem: '<S18>/SPI Transmit' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S18>/SPI Transmit' */
}

static void PMSM_to_SPIDrvBlock_setupImpl_o(stm32cube_blocks_SPIControl_o_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;

  /* Start for MATLABSystem: '<S23>/SPI Controller Transfer' */
  c.buffer.txBufferPtr = (uint16_T *)(&obj->spiTxInternalBuffer[0]);
  c.buffer.rxBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 2U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 128U;

  /* Start for MATLABSystem: '<S23>/SPI Controller Transfer' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_INTERRUPT_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S23>/SPI Controller Transfer' */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 1.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_2);
}

static void PMSM_t_SPIDrvBlock_setupImpl_ox(stm32cube_blocks_SPIControl_o_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;

  /* Start for MATLABSystem: '<S29>/SPI Controller Transfer' */
  c.buffer.txBufferPtr = (uint16_T *)(&obj->spiTxInternalBuffer[0]);
  c.buffer.rxBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 2U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 128U;

  /* Start for MATLABSystem: '<S29>/SPI Controller Transfer' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_INTERRUPT_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S29>/SPI Controller Transfer' */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 1.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
}

/* Model step function */
void PMSM_to_BLDC_mod1_step(void)
{
  GPIO_TypeDef * portNameLoc;
  uint32_T shiftVal;
  uint32_T pinMask;
  uint32_T pinWriteLoc;
  uint16_T rdDataRaw[2];
  uint16_T wrDataRaw1[2];
  uint16_T y_a;
  uint16_T y_n;

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC_k);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_b);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC);

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
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 5) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod_IN_SPI_write_1;
          PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 1.0;
          PMSM_to_BLDC_mod1_B.read1 = 0.0;
          PMSM_to_BLDC_mod1_B.read = 0.0;
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

       case PMSM_to_BLDC_mod1_IN_Reg1:
        PMSM_to_BLDC_mod1_B.read = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 3) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod_IN_SPI_Write_2;
          PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 1.0;
          PMSM_to_BLDC_mod1_B.read = 0.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_Reg2:
        PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 0.0;
        PMSM_to_BLDC_mod1_B.read1 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 3) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod_IN_SPI_write_1;
          PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 1.0;
          PMSM_to_BLDC_mod1_B.read1 = 0.0;
          PMSM_to_BLDC_mod1_B.read = 0.0;
        }
        break;

       case PMSM_to_BLDC_mod_IN_SPI_Write_2:
        PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 1.0;
        PMSM_to_BLDC_mod1_B.read = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 3) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_Reg2;
          PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 0.0;
          PMSM_to_BLDC_mod1_B.read1 = 1.0;
        }
        break;

       default:
        /* case IN_SPI_write_1: */
        PMSM_to_BLDC_mod1_B.read1 = 0.0;
        PMSM_to_BLDC_mod1_B.read = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 5) {
          PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 0.0;
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
            PMSM_to_BLDC_mod1_IN_Reg1;
          PMSM_to_BLDC_mod1_B.read = 1.0;
        }
        break;
      }
    }

    /* End of Chart: '<Root>/Chart' */

    /* Logic: '<S2>/AND1' */
    PMSM_to_BLDC_mod1_B.AND1 = ((PMSM_to_BLDC_mod1_B.En_State != 0.0) &&
      (PMSM_to_BLDC_mod1_B.Ctrl_flag2 != 0.0));

    /* Outputs for Enabled SubSystem: '<S2>/Control_Reg1_read' incorporates:
     *  EnablePort: '<S5>/Enable'
     */
    if (PMSM_to_BLDC_mod1_B.AND1) {
      if (!PMSM_to_BLDC_mod1_DW.Control_Reg1_read_MODE_c) {
        /* SystemReset for Atomic SubSystem: '<S5>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift);

        /* End of SystemReset for SubSystem: '<S5>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S5>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1);

        /* End of SystemReset for SubSystem: '<S5>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Control_Reg1_read_MODE_c = true;
      }

      /* Outputs for Atomic SubSystem: '<S5>/Bit Shift' */
      /* Constant: '<S5>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(0, &y_a, &PMSM_to_BLDC_mod1_DW.BitShift);

      /* End of Outputs for SubSystem: '<S5>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S5>/Bit Shift1' */
      /* Constant: '<S5>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(3, &y_n, &PMSM_to_BLDC_mod1_DW.BitShift1);

      /* End of Outputs for SubSystem: '<S5>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S5>/Bitwise OR' */
      PMSM_to_BLDC_mod1_B.BitwiseOR_n = (uint16_T)(y_a | y_n |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_j);
      PMSM_to_BLDC_mod1_SPITransmit(PMSM_to_BLDC_mod1_B.BitwiseOR_n,
        &PMSM_to_BLDC_mod1_DW.SPITransmit);
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC_k);
    } else {
      PMSM_to_BLDC_mod1_DW.Control_Reg1_read_MODE_c = false;
    }

    /* End of Outputs for SubSystem: '<S2>/Control_Reg1_read' */

    /* Logic: '<S2>/AND' */
    PMSM_to_BLDC_mod1_B.AND = ((PMSM_to_BLDC_mod1_B.En_State != 0.0) &&
      (PMSM_to_BLDC_mod1_B.Ctrl_flag1 != 0.0));

    /* Outputs for Enabled SubSystem: '<S2>/Ctrl_Reg_1' incorporates:
     *  EnablePort: '<S6>/Enable'
     */
    if (PMSM_to_BLDC_mod1_B.AND) {
      if (!PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_MODE) {
        /* InitializeConditions for Delay: '<S6>/Delay' */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_e = 0U;

        /* SystemReset for Atomic SubSystem: '<S6>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_m);

        /* End of SystemReset for SubSystem: '<S6>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S6>/Bit Shift4' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift4);

        /* End of SystemReset for SubSystem: '<S6>/Bit Shift4' */
        PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_MODE = true;
      }

      /* Delay: '<S6>/Delay' */
      PMSM_to_BLDC_mod1_SPITransmit(PMSM_to_BLDC_mod1_DW.Delay_DSTATE_e,
        &PMSM_to_BLDC_mod1_DW.SPITransmit_j);

      /* Outputs for Atomic SubSystem: '<S6>/Bit Shift' */
      /* Constant: '<S6>/Constant5' */
      PMSM_to_BLDC_mod1_BitShift(0, &y_a, &PMSM_to_BLDC_mod1_DW.BitShift_m);

      /* End of Outputs for SubSystem: '<S6>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S6>/Bit Shift4' */
      /* Constant: '<S6>/Constant6' */
      PMSM_to_BLDC_mod1_BitShift1(2, &y_n, &PMSM_to_BLDC_mod1_DW.BitShift4);

      /* End of Outputs for SubSystem: '<S6>/Bit Shift4' */

      /* S-Function (sfix_bitop): '<S6>/Bitwise AND' */
      PMSM_to_BLDC_mod1_B.BitwiseAND = (uint16_T)(y_a | y_n |
        PMSM_to_BLDC_mod1_ConstB.BitwiseOR);

      /* Update for Delay: '<S6>/Delay' */
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_e = PMSM_to_BLDC_mod1_B.BitwiseAND;
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC);
    } else {
      PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S2>/Ctrl_Reg_1' */

    /* Outputs for Enabled SubSystem: '<S4>/Control_Reg1_read' incorporates:
     *  EnablePort: '<S18>/Ctrl_flag1'
     */
    if (PMSM_to_BLDC_mod1_B.read > 0.0) {
      if (!PMSM_to_BLDC_mod1_DW.Control_Reg1_read_MODE) {
        /* InitializeConditions for Delay: '<S18>/Delay1' */
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_d[0] = false;
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_d[1] = false;

        /* InitializeConditions for Delay: '<S18>/Delay' */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i = 0U;

        /* SystemReset for Atomic SubSystem: '<S18>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_e);

        /* End of SystemReset for SubSystem: '<S18>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S18>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_l);

        /* End of SystemReset for SubSystem: '<S18>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Control_Reg1_read_MODE = true;
      }

      /* Logic: '<S18>/NOT' incorporates:
       *  Delay: '<S18>/Delay1'
       */
      PMSM_to_BLDC_mod1_B.NOT_k = !PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_d[0];

      /* Outputs for Enabled SubSystem: '<S18>/Subsystem' incorporates:
       *  EnablePort: '<S23>/Enable'
       */
      if (PMSM_to_BLDC_mod1_B.NOT_k) {
        /* MATLABSystem: '<S23>/SPI Controller Transfer' incorporates:
         *  Constant: '<S23>/Constant'
         */
        wrDataRaw1[0] = 2U;
        wrDataRaw1[1] = MAX_uint16_T;
        y_a = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_f.MW_SPI_HANDLE,
          2U, 3840U, MW_SPI_MODE_2);
        if (y_a == 0) {
          portNameLoc = GPIOC;
          LL_GPIO_ResetOutputPin(portNameLoc, 16384U);
          MW_SPI_ControllerWriteRead_Databits
            (PMSM_to_BLDC_mod1_DW.obj_f.MW_SPI_HANDLE, &wrDataRaw1[0],
             &rdDataRaw[0], 1, 2U, 1, 100U);
          LL_GPIO_SetOutputPin(portNameLoc, 16384U);
        }

        /* MATLABSystem: '<S23>/SPI Controller Transfer' */
        PMSM_to_BLDC_mod1_B.SPIControllerTransfer_b = rdDataRaw[1];
        srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_b);
      }

      /* End of Outputs for SubSystem: '<S18>/Subsystem' */

      /* SignalConversion generated from: '<S18>/Out1' */
      PMSM_to_BLDC_mod1_B.OutportBufferForOut1_b =
        PMSM_to_BLDC_mod1_B.SPIControllerTransfer_b;

      /* Delay: '<S18>/Delay' */
      PMSM_to_BLDC_mod1_B.Delay_n = PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i;
      PMSM_to_BLDC_mod1_SPITransmit_p(PMSM_to_BLDC_mod1_B.Delay_n,
        &PMSM_to_BLDC_mod1_B.SPITransmit_p, &PMSM_to_BLDC_mod1_DW.SPITransmit_p);

      /* Outputs for Atomic SubSystem: '<S18>/Bit Shift' */
      /* Constant: '<S18>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(1, &y_a, &PMSM_to_BLDC_mod1_DW.BitShift_e);

      /* End of Outputs for SubSystem: '<S18>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S18>/Bit Shift1' */
      /* Constant: '<S18>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(2, &y_n, &PMSM_to_BLDC_mod1_DW.BitShift1_l);

      /* End of Outputs for SubSystem: '<S18>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S18>/Bitwise OR' */
      PMSM_to_BLDC_mod1_B.BitwiseOR = (uint16_T)(y_a | y_n |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_b);

      /* Update for Delay: '<S18>/Delay1' incorporates:
       *  Constant: '<S22>/Constant'
       *  RelationalOperator: '<S22>/Compare'
       */
      PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_d[0] =
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_d[1];
      PMSM_to_BLDC_mod1_DW.Delay1_DSTATE_d[1] =
        (PMSM_to_BLDC_mod1_B.SPITransmit_p.SPITransmit == 0);

      /* Update for Delay: '<S18>/Delay' */
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE_i = PMSM_to_BLDC_mod1_B.BitwiseOR;
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC);
    } else {
      PMSM_to_BLDC_mod1_DW.Control_Reg1_read_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S4>/Control_Reg1_read' */

    /* Outputs for Enabled SubSystem: '<S4>/Control_Reg_2_read' incorporates:
     *  EnablePort: '<S19>/Ctrl_flag2'
     */
    if (PMSM_to_BLDC_mod1_B.read1 > 0.0) {
      if (!PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_MODE) {
        /* InitializeConditions for Delay: '<S19>/Delay1' */
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE[0] = false;
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE[1] = false;

        /* InitializeConditions for Delay: '<S19>/Delay' */
        PMSM_to_BLDC_mod1_DW.Delay_DSTATE = 0U;

        /* SystemReset for Atomic SubSystem: '<S19>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_b);

        /* End of SystemReset for SubSystem: '<S19>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S19>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_m);

        /* End of SystemReset for SubSystem: '<S19>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_MODE = true;
      }

      /* Logic: '<S19>/NOT' incorporates:
       *  Delay: '<S19>/Delay1'
       */
      PMSM_to_BLDC_mod1_B.NOT = !PMSM_to_BLDC_mod1_DW.Delay1_DSTATE[0];

      /* Outputs for Enabled SubSystem: '<S19>/Subsystem' incorporates:
       *  EnablePort: '<S29>/Enable'
       */
      if (PMSM_to_BLDC_mod1_B.NOT) {
        /* MATLABSystem: '<S29>/SPI Controller Transfer' incorporates:
         *  Constant: '<S29>/Constant'
         */
        wrDataRaw1[0] = 2U;
        wrDataRaw1[1] = MAX_uint16_T;
        y_a = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, 2U,
          3840U, MW_SPI_MODE_3);
        if (y_a == 0) {
          portNameLoc = GPIOC;
          LL_GPIO_ResetOutputPin(portNameLoc, 16384U);
          MW_SPI_ControllerWriteRead_Databits
            (PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, &wrDataRaw1[0], &rdDataRaw
             [0], 1, 2U, 1, 100U);
          LL_GPIO_SetOutputPin(portNameLoc, 16384U);
        }

        /* MATLABSystem: '<S29>/SPI Controller Transfer' */
        PMSM_to_BLDC_mod1_B.SPIControllerTransfer = rdDataRaw[1];
        srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S19>/Subsystem' */

      /* SignalConversion generated from: '<S19>/Out1' */
      PMSM_to_BLDC_mod1_B.OutportBufferForOut1 =
        PMSM_to_BLDC_mod1_B.SPIControllerTransfer;

      /* Delay: '<S19>/Delay' */
      PMSM_to_BLDC_mod1_B.Delay = PMSM_to_BLDC_mod1_DW.Delay_DSTATE;
      PMSM_to_BLDC_mod1_SPITransmit_p(PMSM_to_BLDC_mod1_B.Delay,
        &PMSM_to_BLDC_mod1_B.SPITransmit_pn,
        &PMSM_to_BLDC_mod1_DW.SPITransmit_pn);

      /* Outputs for Atomic SubSystem: '<S19>/Bit Shift' */
      /* Constant: '<S19>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(1, &y_a, &PMSM_to_BLDC_mod1_DW.BitShift_b);

      /* End of Outputs for SubSystem: '<S19>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S19>/Bit Shift1' */
      /* Constant: '<S19>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(3, &y_n, &PMSM_to_BLDC_mod1_DW.BitShift1_m);

      /* End of Outputs for SubSystem: '<S19>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S19>/Bitwise OR' incorporates:
       *  Delay: '<S19>/Delay'
       */
      PMSM_to_BLDC_mod1_DW.Delay_DSTATE = (uint16_T)(y_a | y_n |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND);

      /* Update for Delay: '<S19>/Delay1' incorporates:
       *  Constant: '<S28>/Constant'
       *  RelationalOperator: '<S28>/Compare'
       */
      PMSM_to_BLDC_mod1_DW.Delay1_DSTATE[0] =
        PMSM_to_BLDC_mod1_DW.Delay1_DSTATE[1];
      PMSM_to_BLDC_mod1_DW.Delay1_DSTATE[1] =
        (PMSM_to_BLDC_mod1_B.SPITransmit_pn.SPITransmit == 0);
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_SubsysRanBC);
    } else {
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
  PMSM_to_BLDC_mod1_M->Sizes.checksums[0] = (2985730536U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[1] = (968534479U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[2] = (517619648U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[3] = (1440956962U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[31];
    PMSM_to_BLDC_mod1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC_k;
    systemRan[3] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC_k;
    systemRan[4] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC_k;
    systemRan[5] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC_k;
    systemRan[6] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC_k;
    systemRan[7] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC_k;
    systemRan[8] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[9] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[10] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[11] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[12] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[13] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC;
    systemRan[18] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC;
    systemRan[19] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC;
    systemRan[20] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_b;
    systemRan[21] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_b;
    systemRan[22] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg1_read_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_SubsysRanBC;
    systemRan[24] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_SubsysRanBC;
    systemRan[25] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg_2_read_SubsysRanBC;
    systemRan[28] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC;
    systemRan[29] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC;
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
  PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit);

  /* End of SystemInitialize for SubSystem: '<S2>/Control_Reg1_read' */

  /* SystemInitialize for Atomic SubSystem: '<S6>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_m);

  /* End of SystemInitialize for SubSystem: '<S6>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S6>/Bit Shift4' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift4);

  /* End of SystemInitialize for SubSystem: '<S6>/Bit Shift4' */
  PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_j);

  /* End of SystemInitialize for SubSystem: '<S2>/Ctrl_Reg_1' */

  /* SystemInitialize for Enabled SubSystem: '<S18>/Subsystem' */
  /* Start for MATLABSystem: '<S23>/SPI Controller Transfer' */
  PMSM_to_BLDC_mod1_DW.obj_f.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_f.isSetupComplete = false;
  PMSM_to_BLDC_mod1_DW.obj_f.isInitialized = 1;
  PMSM_to_SPIDrvBlock_setupImpl_o(&PMSM_to_BLDC_mod1_DW.obj_f);
  PMSM_to_BLDC_mod1_DW.obj_f.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<S18>/Subsystem' */

  /* SystemInitialize for Atomic SubSystem: '<S18>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_e);

  /* End of SystemInitialize for SubSystem: '<S18>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S18>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_l);

  /* End of SystemInitialize for SubSystem: '<S18>/Bit Shift1' */
  PMSM_to_BLDC_SPITransmit_d_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_p);

  /* End of SystemInitialize for SubSystem: '<S4>/Control_Reg1_read' */

  /* Start for MATLABSystem: '<S29>/SPI Controller Transfer' */
  PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj.isSetupComplete = false;
  PMSM_to_BLDC_mod1_DW.obj.isInitialized = 1;
  PMSM_t_SPIDrvBlock_setupImpl_ox(&PMSM_to_BLDC_mod1_DW.obj);
  PMSM_to_BLDC_mod1_DW.obj.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<S19>/Subsystem' */

  /* SystemInitialize for Atomic SubSystem: '<S19>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_b);

  /* End of SystemInitialize for SubSystem: '<S19>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S19>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_m);

  /* End of SystemInitialize for SubSystem: '<S19>/Bit Shift1' */
  PMSM_to_BLDC_SPITransmit_d_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pn);

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

  /* Terminate for Enabled SubSystem: '<S2>/Control_Reg1_read' */
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit);

  /* Terminate for Enabled SubSystem: '<S2>/Ctrl_Reg_1' */
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_j);

  /* Terminate for Enabled SubSystem: '<S18>/Subsystem' */
  /* Terminate for MATLABSystem: '<S23>/SPI Controller Transfer' */
  if (!PMSM_to_BLDC_mod1_DW.obj_f.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_f.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_f.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_f.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S23>/SPI Controller Transfer' */
  /* End of Terminate for SubSystem: '<S18>/Subsystem' */
  PMSM_to_BLDC_SPITransmit_a_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_p);

  /* Terminate for Enabled SubSystem: '<S19>/Subsystem' */
  /* Terminate for MATLABSystem: '<S29>/SPI Controller Transfer' */
  if (!PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S29>/SPI Controller Transfer' */
  PMSM_to_BLDC_SPITransmit_a_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pn);

  /* End of Terminate for SubSystem: '<S4>/Control_Reg_2_read' */

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
