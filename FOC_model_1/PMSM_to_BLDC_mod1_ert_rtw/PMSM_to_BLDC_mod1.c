/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.c
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

#include "PMSM_to_BLDC_mod1.h"
#include "rtwtypes.h"
#include "PMSM_to_BLDC_mod1_types.h"
#include "PMSM_to_BLDC_mod1_private.h"
#include "mw_stm32_spi_ll.h"
#include "stm_adc_ll.h"
#include <stddef.h>

/* Named constants for MATLAB Function: '<S23>/bit_shift' */
#define PMSM_to_BLDC_mod1_CALL_EVENT   (-1)

/* Named constants for MATLAB Function: '<S24>/bit_shift' */
#define PMSM_to_BLDC_mod1_CALL_EVENT_j (-1)

/* Named constants for Chart: '<Root>/Chart' */
#define PMSM_to_BLDC__IN_Initialization (3U)
#define PMSM_to_BLDC_m_IN_Current_sense (1U)
#define PMSM_to_BLDC_mod1_IN_Dummy     (1U)
#define PMSM_to_BLDC_mod1_IN_En_Gate   (2U)
#define PMSM_to_BLDC_mod1_IN_SPI_init1 (4U)
#define PMSM_to_BLDC_mod1_IN_SPI_init2 (5U)
#define PMSM_to_BLDC_mod1_IN_SPI_init3 (6U)
#define PMSM_to_BLDC_mod1_IN_SPI_init4 (7U)
#define PMSM_to_BLDC_mod1_IN_SPI_write (2U)
#define PMSM_to_BLDC_mod1_IN_SPI_write2 (4U)
#define PMSM_to_BLDC_mod1_IN_SPI_write5 (5U)
#define PMSM_to_BLDC_mod1_IN_SPI_write6 (6U)
#define PMSM_to_BLDC_mod1_IN_SPI_write7 (7U)
#define PMSM_to_BLDC_mod1_IN_SPI_write8 (8U)
#define PMSM_to_BLDC_mod1_IN_SPI_write9 (9U)
#define PMSM_to_BLDC_mod_IN_SPI_write10 (3U)

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
static void PMSM_to_B_SPIDrvBlock_setupImpl(stm32cube_blocks_SPIControl_d_T *obj);

/* Forward declaration for local functions */
static void PMSM_to_BLDC_SystemCore_setup_n(stm32cube_blocks_SPIControlle_T *obj);

/* Forward declaration for local functions */
static void PMSM_to_BLD_SystemCore_setup_n2(stm32cube_blocks_SPIControlle_T *obj);

/* Forward declaration for local functions */
static void PMSM_to_SPIDrvBlock_setupImpl_e(stm32cube_blocks_SPIControl_d_T *obj);

/* Forward declaration for local functions */
static void PMSM_to_BL_SystemCore_setup_oxg(stm32cube_blocks_SPIControlle_T *obj);
static void PMSM_to_SPIDrvBlock_setupImpl_o(stm32cube_blocks_SPIControl_d_T *obj);
static void PMSM_to_B_SystemCore_setup_oxgk(stm32cube_blocks_SPIControlle_T *obj);
static void PMSM_to_BLDC_SystemCore_setup_o(stm32cube_blocks_AnalogInput__T *obj);
static void PMSM_to_BLD_SystemCore_setup_ox(stm32cube_blocks_AnalogInput__T *obj);
static void PMSM_to__SystemCore_setup_oxgkf(stm32cube_blocks_AnalogInput__T *obj);
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
  if ((PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.0001s, 0.0s] */
    PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] = 0;
  }

  (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2])++;
  if ((PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2]) > 19) {/* Sample time: [0.001s, 0.0s] */
    PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] = 0;
  }

  (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[3])++;
  if ((PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[3]) > 1999) {/* Sample time: [0.1s, 0.0s] */
    PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[3] = 0;
  }

  (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[4])++;
  if ((PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[4]) > 19999) {/* Sample time: [1.0s, 0.0s] */
    PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[4] = 0;
  }
}

/*
 * System initialize for atomic system:
 *    '<S21>/Bit Shift'
 *    '<S22>/Bit Shift'
 *    '<S35>/Bit Shift'
 *    '<S41>/Bit Shift'
 *    '<S47>/Bit Shift'
 *    '<S48>/Bit Shift'
 */
void PMSM_to_BLDC_mod1_BitShift_Init(DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* SystemInitialize for MATLAB Function: '<S23>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
}

/*
 * System reset for atomic system:
 *    '<S21>/Bit Shift'
 *    '<S22>/Bit Shift'
 *    '<S35>/Bit Shift'
 *    '<S41>/Bit Shift'
 *    '<S47>/Bit Shift'
 *    '<S48>/Bit Shift'
 */
void PMSM_to_BLDC_mod_BitShift_Reset(DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* SystemReset for MATLAB Function: '<S23>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
}

/*
 * Output and update for atomic system:
 *    '<S21>/Bit Shift'
 *    '<S22>/Bit Shift'
 *    '<S35>/Bit Shift'
 *    '<S41>/Bit Shift'
 *    '<S47>/Bit Shift'
 *    '<S48>/Bit Shift'
 */
void PMSM_to_BLDC_mod1_BitShift(uint16_T rtu_u, uint16_T *rty_y,
  DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* MATLAB Function: '<S23>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
  *rty_y = (uint16_T)(rtu_u << 15);
}

/*
 * System initialize for atomic system:
 *    '<S21>/Bit Shift1'
 *    '<S22>/Bit Shift1'
 *    '<S35>/Bit Shift1'
 *    '<S41>/Bit Shift1'
 *    '<S47>/Bit Shift1'
 *    '<S48>/Bit Shift1'
 */
void PMSM_to_BLDC_mod_BitShift1_Init(DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* SystemInitialize for MATLAB Function: '<S24>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_j;
}

/*
 * System reset for atomic system:
 *    '<S21>/Bit Shift1'
 *    '<S22>/Bit Shift1'
 *    '<S35>/Bit Shift1'
 *    '<S41>/Bit Shift1'
 *    '<S47>/Bit Shift1'
 *    '<S48>/Bit Shift1'
 */
void PMSM_to_BLDC_mo_BitShift1_Reset(DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* SystemReset for MATLAB Function: '<S24>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_j;
}

/*
 * Output and update for atomic system:
 *    '<S21>/Bit Shift1'
 *    '<S22>/Bit Shift1'
 *    '<S35>/Bit Shift1'
 *    '<S41>/Bit Shift1'
 *    '<S47>/Bit Shift1'
 *    '<S48>/Bit Shift1'
 */
void PMSM_to_BLDC_mod1_BitShift1(uint16_T rtu_u, uint16_T *rty_y,
  DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* MATLAB Function: '<S24>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_j;
  *rty_y = (uint16_T)(rtu_u << 11);
}

static void PMSM_to_BLDC_m_SystemCore_setup(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S35>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S35>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S35>/SPI Receive' */
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
  /* Start for MATLABSystem: '<S35>/SPI Receive' */
  localDW->obj.isInitialized = 0;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  PMSM_to_BLDC_m_SystemCore_setup(&localDW->obj);
}

/* Output and update for atomic system: */
void PMSM_to_BLDC_mod1_SPIReceive(DW_SPIReceive_PMSM_to_BLDC_mo_T *localDW)
{
  uint16_T tmp[15];
  uint16_T status;

  /* MATLABSystem: '<S35>/SPI Receive' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    MW_SPI_Read_Databits(localDW->obj.MW_SPI_HANDLE, &tmp[0], 15U, 1, 1, 1U);
    LL_GPIO_SetOutputPin(GPIOC, 16384U);
  }

  /* End of MATLABSystem: '<S35>/SPI Receive' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC_mo_SPIReceive_Term(DW_SPIReceive_PMSM_to_BLDC_mo_T *localDW)
{
  /* Terminate for MATLABSystem: '<S35>/SPI Receive' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/SPI Receive' */
}

static void PMSM_to_B_SPIDrvBlock_setupImpl(stm32cube_blocks_SPIControl_d_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;

  /* Start for MATLABSystem: '<S35>/SPI Transmit' */
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S35>/SPI Transmit' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S35>/SPI Transmit' */
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
  /* Start for MATLABSystem: '<S35>/SPI Transmit' */
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
  uint16_T status;

  /* MATLABSystem: '<S35>/SPI Transmit' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    LL_GPIO_ResetOutputPin(GPIOC, 16384U);
    MW_SPI_Write_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0, 1U, 1, 1, 1U);
  }

  /* End of MATLABSystem: '<S35>/SPI Transmit' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC_m_SPITransmit_Term(DW_SPITransmit_PMSM_to_BLDC_m_T *localDW)
{
  /* Terminate for MATLABSystem: '<S35>/SPI Transmit' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S35>/SPI Transmit' */
}

static void PMSM_to_BLDC_SystemCore_setup_n(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S36>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S36>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S36>/SPI Receive' */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 1.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
  obj->isSetupComplete = true;
}

/* System initialize for atomic system: */
void PMSM_to_BLDC__SPIReceive_e_Init(DW_SPIReceive_PMSM_to_BLDC__f_T *localDW)
{
  /* Start for MATLABSystem: '<S36>/SPI Receive' */
  localDW->obj.isInitialized = 0;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  PMSM_to_BLDC_SystemCore_setup_n(&localDW->obj);
}

/* Output and update for atomic system: */
void PMSM_to_BLDC_mod1_SPIReceive_p(B_SPIReceive_PMSM_to_BLDC_m_c_T *localB,
  DW_SPIReceive_PMSM_to_BLDC__f_T *localDW)
{
  uint16_T status;

  /* MATLABSystem: '<S36>/SPI Receive' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    MW_SPI_Read_Databits(localDW->obj.MW_SPI_HANDLE, &localB->SPIReceive, 1U, 1,
                         1, 1U);
    LL_GPIO_SetOutputPin(GPIOC, 16384U);
  }

  /* End of MATLABSystem: '<S36>/SPI Receive' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC__SPIReceive_m_Term(DW_SPIReceive_PMSM_to_BLDC__f_T *localDW)
{
  /* Terminate for MATLABSystem: '<S36>/SPI Receive' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S36>/SPI Receive' */
}

static void PMSM_to_BLD_SystemCore_setup_n2(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S47>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S47>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S47>/SPI Receive' */
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
void PMSM_to_BLDC__SPIReceive_k_Init(DW_SPIReceive_PMSM_to_BLDC_fw_T *localDW)
{
  /* Start for MATLABSystem: '<S47>/SPI Receive' */
  localDW->obj.isInitialized = 0;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  PMSM_to_BLD_SystemCore_setup_n2(&localDW->obj);
}

/* Output and update for atomic system: */
void PMSM_to_BLDC_mod1_SPIReceive_pn(B_SPIReceive_PMSM_to_BLDC__ca_T *localB,
  DW_SPIReceive_PMSM_to_BLDC_fw_T *localDW)
{
  uint16_T status;

  /* MATLABSystem: '<S47>/SPI Receive' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    MW_SPI_Read_Databits(localDW->obj.MW_SPI_HANDLE, &localB->SPIReceive[0], 15U,
                         1, 1, 1U);
    LL_GPIO_SetOutputPin(GPIOC, 16384U);
  }

  /* End of MATLABSystem: '<S47>/SPI Receive' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC__SPIReceive_c_Term(DW_SPIReceive_PMSM_to_BLDC_fw_T *localDW)
{
  /* Terminate for MATLABSystem: '<S47>/SPI Receive' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S47>/SPI Receive' */
}

static void PMSM_to_SPIDrvBlock_setupImpl_e(stm32cube_blocks_SPIControl_d_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;

  /* Start for MATLABSystem: '<S47>/SPI Transmit' */
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S47>/SPI Transmit' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S47>/SPI Transmit' */
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
  /* Start for MATLABSystem: '<S47>/SPI Transmit' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isSetupComplete = false;
  localDW->obj.isInitialized = 1;
  PMSM_to_SPIDrvBlock_setupImpl_e(&localDW->obj);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void PMSM_to_BLDC_mod1_SPITransmit_p(uint16_T rtu_0,
  DW_SPITransmit_PMSM_to_BLDC_f_T *localDW)
{
  uint16_T status;

  /* MATLABSystem: '<S47>/SPI Transmit' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    LL_GPIO_ResetOutputPin(GPIOC, 16384U);
    MW_SPI_Write_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0, 1U, 1, 1, 1U);
  }

  /* End of MATLABSystem: '<S47>/SPI Transmit' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC_SPITransmit_a_Term(DW_SPITransmit_PMSM_to_BLDC_f_T *localDW)
{
  /* Terminate for MATLABSystem: '<S47>/SPI Transmit' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S47>/SPI Transmit' */
}

static void PMSM_to_BL_SystemCore_setup_oxg(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S21>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S21>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S21>/SPI Receive' */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 16.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
  obj->isSetupComplete = true;
}

static void PMSM_to_SPIDrvBlock_setupImpl_o(stm32cube_blocks_SPIControl_d_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;

  /* Start for MATLABSystem: '<S21>/SPI Transmit' incorporates:
   *  MATLABSystem: '<S22>/SPI Transmit'
   */
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S21>/SPI Transmit' incorporates:
   *  MATLABSystem: '<S22>/SPI Transmit'
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

  /* Start for MATLABSystem: '<S21>/SPI Transmit' incorporates:
   *  MATLABSystem: '<S22>/SPI Transmit'
   */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 1.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
}

static void PMSM_to_B_SystemCore_setup_oxgk(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S22>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S22>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S22>/SPI Receive' */
  obj->MW_SPI_BlockStruct.gpioPin = 14U;
  obj->MW_SPI_BlockStruct.chipSelectActiveLow = true;
  obj->MW_SPI_BlockStruct.dataType = b_dataType;
  obj->MW_SPI_BlockStruct.dataLength = 1.0;
  spiBlock = (STM32_SPI_Struct_T *)(&obj->MW_SPI_BlockStruct);
  obj->MW_SPI_HANDLE = SPI_STM32_Init(&c, spiBlock);
  MW_STM32_SPI_SetFormat(obj->MW_SPI_HANDLE, 2U, 3840U, MW_SPI_MODE_3);
  obj->isSetupComplete = true;
}

static void PMSM_to_BLDC_SystemCore_setup_o(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S14>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S14>/Analog to Digital Converter' */
  adcStructLoc.InjectedNoOfConversion = 0U;
  adcStructLoc.peripheralPtr = ADC2;
  adcStructLoc.dmaPeripheralPtr = NULL;
  adcStructLoc.dmastream = 0;
  adcStructLoc.DataTransferMode = ADC_DR_TRANSFER;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_LIMITED;
  adcStructLoc.InternalBufferSize = 1U;
  adcStructLoc.RegularNoOfConversion = 1U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_NORMAL_MODE, 1,
    ADC_TRIGGER_AND_READ, LL_ADC_REG_SEQ_SCAN_DISABLE);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 1);
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

static void PMSM_to_BLD_SystemCore_setup_ox(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S17>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S17>/Analog to Digital Converter' */
  adcStructLoc.InjectedNoOfConversion = 0U;
  adcStructLoc.peripheralPtr = ADC3;
  adcStructLoc.dmaPeripheralPtr = NULL;
  adcStructLoc.dmastream = 0;
  adcStructLoc.DataTransferMode = ADC_DR_TRANSFER;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_LIMITED;
  adcStructLoc.InternalBufferSize = 1U;
  adcStructLoc.RegularNoOfConversion = 1U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_NORMAL_MODE, 1,
    ADC_TRIGGER_AND_READ, LL_ADC_REG_SEQ_SCAN_DISABLE);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 1);
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

static void PMSM_to__SystemCore_setup_oxgkf(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S59>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S59>/Analog to Digital Converter' */
  adcStructLoc.InjectedNoOfConversion = 0U;
  adcStructLoc.peripheralPtr = ADC1;
  adcStructLoc.dmaPeripheralPtr = NULL;
  adcStructLoc.dmastream = 0;
  adcStructLoc.DataTransferMode = ADC_DR_TRANSFER;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_LIMITED;
  adcStructLoc.InternalBufferSize = 1U;
  adcStructLoc.RegularNoOfConversion = 1U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_NORMAL_MODE, 1,
    ADC_TRIGGER_AND_READ, LL_ADC_REG_SEQ_SCAN_DISABLE);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 1);
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

/* Model step function */
void PMSM_to_BLDC_mod1_step(void)
{
  GPIO_TypeDef * portNameLoc;
  uint32_T shiftVal;
  real_T rtb_PhaseCurrent_idx_2;
  int32_T i;
  uint32_T pinMask;
  uint32_T pinWriteLoc;
  uint16_T tmp[16];
  uint16_T status;
  uint16_T y_nb;
  boolean_T tmp_0;
  boolean_T tmp_1;
  boolean_T tmp_2;

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_g);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_c);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_n);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Status_Reg1_read_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_SubsysRanBC);
  tmp_0 = (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0);
  if (tmp_0) {
    /* Delay: '<Root>/Delay' */
    PMSM_to_BLDC_mod1_B.Delay = PMSM_to_BLDC_mod1_DW.Delay_DSTATE;

    /* Delay: '<Root>/Delay1' */
    PMSM_to_BLDC_mod1_B.Delay1 = PMSM_to_BLDC_mod1_DW.Delay1_DSTATE;
  }

  tmp_1 = (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] == 0);
  if (tmp_1) {
    /* Chart: '<Root>/Chart' */
    if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 < 32767) {
      PMSM_to_BLDC_mod1_DW.temporalCounter_i1++;
    }

    if (PMSM_to_BLDC_mod1_DW.temporalCounter_i2 < 8191) {
      PMSM_to_BLDC_mod1_DW.temporalCounter_i2++;
    }

    if (PMSM_to_BLDC_mod1_DW.is_active_c3_PMSM_to_BLDC_mod1 == 0) {
      PMSM_to_BLDC_mod1_DW.is_active_c3_PMSM_to_BLDC_mod1 = 1U;
      PMSM_to_BLDC_mod1_DW.is_active_Test2 = 1U;
      PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
      PMSM_to_BLDC_mod1_DW.is_Test2 = PMSM_to_BLDC_mod1_IN_Dummy;
      PMSM_to_BLDC_mod1_DW.Drv_ok = 0.0;
      PMSM_to_BLDC_mod1_DW.is_active_Test = 1U;
      PMSM_to_BLDC_mod1_DW.temporalCounter_i2 = 0U;
      PMSM_to_BLDC_mod1_DW.is_Test = PMSM_to_BLDC__IN_Initialization;
      PMSM_to_BLDC_mod1_DW.CS_val = 1.0;
      PMSM_to_BLDC_mod1_B.En_State = 0.0;
    } else {
      switch (PMSM_to_BLDC_mod1_DW.is_Test2) {
       case PMSM_to_BLDC_mod1_IN_Dummy:
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 20000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test2 = PMSM_to_BLDC_mod1_IN_SPI_write;
          PMSM_to_BLDC_mod1_B.spi_write1 = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write:
        PMSM_to_BLDC_mod1_B.spi_write1 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test2 = PMSM_to_BLDC_mod1_IN_SPI_write2;
          PMSM_to_BLDC_mod1_B.spi_write1 = 0.0;
        }
        break;

       case PMSM_to_BLDC_mod_IN_SPI_write10:
        PMSM_to_BLDC_mod1_B.spi_write4 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test2 = PMSM_to_BLDC_mod1_IN_SPI_write;
          PMSM_to_BLDC_mod1_B.spi_write1 = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write2:
        PMSM_to_BLDC_mod1_B.spi_write1 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test2 = PMSM_to_BLDC_mod1_IN_SPI_write5;
          PMSM_to_BLDC_mod1_B.spi_write2 = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write5:
        PMSM_to_BLDC_mod1_B.spi_write2 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test2 = PMSM_to_BLDC_mod1_IN_SPI_write6;
          PMSM_to_BLDC_mod1_B.spi_write2 = 0.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write6:
        PMSM_to_BLDC_mod1_B.spi_write2 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test2 = PMSM_to_BLDC_mod1_IN_SPI_write7;
          PMSM_to_BLDC_mod1_B.spi_write3 = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write7:
        PMSM_to_BLDC_mod1_B.spi_write3 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test2 = PMSM_to_BLDC_mod1_IN_SPI_write8;
          PMSM_to_BLDC_mod1_B.spi_write3 = 0.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_write8:
        PMSM_to_BLDC_mod1_B.spi_write3 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test2 = PMSM_to_BLDC_mod1_IN_SPI_write9;
          PMSM_to_BLDC_mod1_B.spi_write4 = 1.0;
        }
        break;

       default:
        /* case IN_SPI_write9: */
        PMSM_to_BLDC_mod1_B.spi_write4 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test2 = PMSM_to_BLDC_mod_IN_SPI_write10;
          PMSM_to_BLDC_mod1_B.spi_write4 = 0.0;
          PMSM_to_BLDC_mod1_DW.Drv_ok = 1.0;
        }
        break;
      }

      switch (PMSM_to_BLDC_mod1_DW.is_Test) {
       case PMSM_to_BLDC_m_IN_Current_sense:
        PMSM_to_BLDC_mod1_B.Ib_flag = 1.0;
        PMSM_to_BLDC_mod1_B.Ic_flag = 1.0;
        PMSM_to_BLDC_mod1_B.FOC_flag = 1.0;
        break;

       case PMSM_to_BLDC_mod1_IN_En_Gate:
        PMSM_to_BLDC_mod1_B.En_State = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i2 >= 4000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i2 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test = PMSM_to_BLDC_mod1_IN_SPI_init1;
          PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 1.0;
        }
        break;

       case PMSM_to_BLDC__IN_Initialization:
        PMSM_to_BLDC_mod1_B.En_State = 0.0;
        if ((PMSM_to_BLDC_mod1_DW.CS_val == 1.0) &&
            (PMSM_to_BLDC_mod1_DW.temporalCounter_i2 >= 40)) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i2 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test = PMSM_to_BLDC_mod1_IN_En_Gate;
          PMSM_to_BLDC_mod1_B.En_State = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_init1:
        PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i2 >= 5000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i2 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test = PMSM_to_BLDC_mod1_IN_SPI_init2;
          PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 0.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_init2:
        PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i2 >= 1000) {
          PMSM_to_BLDC_mod1_DW.temporalCounter_i2 = 0U;
          PMSM_to_BLDC_mod1_DW.is_Test = PMSM_to_BLDC_mod1_IN_SPI_init3;
          PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 1.0;
        }
        break;

       case PMSM_to_BLDC_mod1_IN_SPI_init3:
        PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 1.0;
        if (PMSM_to_BLDC_mod1_DW.temporalCounter_i2 >= 3000) {
          PMSM_to_BLDC_mod1_DW.is_Test = PMSM_to_BLDC_mod1_IN_SPI_init4;
          PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 0.0;
        }
        break;

       default:
        /* case IN_SPI_init4: */
        PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 0.0;
        if (PMSM_to_BLDC_mod1_DW.Drv_ok == 1.0) {
          PMSM_to_BLDC_mod1_DW.is_Test = PMSM_to_BLDC_m_IN_Current_sense;
          PMSM_to_BLDC_mod1_B.Ib_flag = 1.0;
          PMSM_to_BLDC_mod1_B.Ic_flag = 1.0;
          PMSM_to_BLDC_mod1_B.FOC_flag = 1.0;
        }
        break;
      }
    }

    /* End of Chart: '<Root>/Chart' */
  }

  if (tmp_0) {
    /* Outputs for Atomic SubSystem: '<Root>/SPI_Write' */
    /* Logic: '<S4>/AND1' */
    PMSM_to_BLDC_mod1_B.AND1 = ((PMSM_to_BLDC_mod1_B.En_State != 0.0) &&
      (PMSM_to_BLDC_mod1_B.Ctrl_flag2 != 0.0));

    /* Outputs for Enabled SubSystem: '<S4>/Control_Reg2' incorporates:
     *  EnablePort: '<S21>/Enable'
     */
    if (PMSM_to_BLDC_mod1_B.AND1) {
      if (!PMSM_to_BLDC_mod1_DW.Control_Reg2_MODE) {
        /* SystemReset for Atomic SubSystem: '<S21>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift);

        /* End of SystemReset for SubSystem: '<S21>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S21>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1);

        /* End of SystemReset for SubSystem: '<S21>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Control_Reg2_MODE = true;
      }

      /* MATLABSystem: '<S21>/SPI Receive' */
      status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_g.MW_SPI_HANDLE,
        2U, 3840U, MW_SPI_MODE_3);
      if (status == 0) {
        MW_SPI_Read_Databits(PMSM_to_BLDC_mod1_DW.obj_g.MW_SPI_HANDLE, &tmp[0],
                             16U, 1, 1, 1U);
        LL_GPIO_SetOutputPin(GPIOC, 16384U);
      }

      /* End of MATLABSystem: '<S21>/SPI Receive' */

      /* Outputs for Atomic SubSystem: '<S21>/Bit Shift' */
      /* Constant: '<S21>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(0, &status, &PMSM_to_BLDC_mod1_DW.BitShift);

      /* End of Outputs for SubSystem: '<S21>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S21>/Bit Shift1' */
      /* Constant: '<S21>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(3, &y_nb, &PMSM_to_BLDC_mod1_DW.BitShift1);

      /* End of Outputs for SubSystem: '<S21>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S21>/Bitwise OR' */
      PMSM_to_BLDC_mod1_B.BitwiseOR_n = (uint16_T)(status | y_nb |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_jx);

      /* DataTypeConversion: '<S21>/Data Type Conversion' */
      PMSM_to_BLDC_mod1_B.DataTypeConversion_m = PMSM_to_BLDC_mod1_B.BitwiseOR_n;

      /* MATLABSystem: '<S21>/SPI Transmit' */
      status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE,
        2U, 3840U, MW_SPI_MODE_3);
      if (status == 0) {
        LL_GPIO_ResetOutputPin(GPIOC, 16384U);
        MW_SPI_Write_Databits(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE,
                              &PMSM_to_BLDC_mod1_B.DataTypeConversion_m, 1U, 1,
                              1, 1000U);
      }

      /* End of MATLABSystem: '<S21>/SPI Transmit' */
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC);
    } else {
      PMSM_to_BLDC_mod1_DW.Control_Reg2_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S4>/Control_Reg2' */

    /* Logic: '<S4>/AND' */
    PMSM_to_BLDC_mod1_B.AND = ((PMSM_to_BLDC_mod1_B.En_State != 0.0) &&
      (PMSM_to_BLDC_mod1_B.Ctrl_flag1 != 0.0));

    /* Outputs for Enabled SubSystem: '<S4>/Ctrl_Reg_1' incorporates:
     *  EnablePort: '<S22>/Enable'
     */
    if (PMSM_to_BLDC_mod1_B.AND) {
      if (!PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_MODE) {
        /* SystemReset for Atomic SubSystem: '<S22>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_h);

        /* End of SystemReset for SubSystem: '<S22>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S22>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_d);

        /* End of SystemReset for SubSystem: '<S22>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_MODE = true;
      }

      /* Outputs for Atomic SubSystem: '<S22>/Bit Shift' */
      /* Constant: '<S22>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(0, &status, &PMSM_to_BLDC_mod1_DW.BitShift_h);

      /* End of Outputs for SubSystem: '<S22>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S22>/Bit Shift1' */
      /* Constant: '<S22>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(2, &y_nb, &PMSM_to_BLDC_mod1_DW.BitShift1_d);

      /* End of Outputs for SubSystem: '<S22>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S22>/Bitwise OR' */
      PMSM_to_BLDC_mod1_B.BitwiseOR_e = (uint16_T)(status | y_nb |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_e);

      /* MATLABSystem: '<S22>/SPI Transmit' */
      status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_n.MW_SPI_HANDLE,
        2U, 3840U, MW_SPI_MODE_3);
      if (status == 0) {
        LL_GPIO_ResetOutputPin(GPIOC, 16384U);
        MW_SPI_Write_Databits(PMSM_to_BLDC_mod1_DW.obj_n.MW_SPI_HANDLE,
                              &PMSM_to_BLDC_mod1_B.BitwiseOR_e, 1U, 1, 1, 10U);
      }

      /* End of MATLABSystem: '<S22>/SPI Transmit' */
      /* MATLABSystem: '<S22>/SPI Receive' */
      status = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, 2U,
        3840U, MW_SPI_MODE_3);
      if (status == 0) {
        MW_SPI_Read_Databits(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, &status, 1U,
                             1, 1, 1U);
        LL_GPIO_SetOutputPin(GPIOC, 16384U);
      }

      /* End of MATLABSystem: '<S22>/SPI Receive' */
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC);
    } else {
      PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S4>/Ctrl_Reg_1' */
  }

  if (tmp_1) {
    /* Outputs for Enabled SubSystem: '<S6>/Status_Reg_2_read' incorporates:
     *  EnablePort: '<S48>/Ctrl_flag2'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write2 > 0.0) {
      if (!PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_MODE) {
        /* SystemReset for Atomic SubSystem: '<S48>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_n);

        /* End of SystemReset for SubSystem: '<S48>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S48>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_o);

        /* End of SystemReset for SubSystem: '<S48>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_MODE = true;
      }

      PMSM_to_BLDC_mod1_SPIReceive_pn(&PMSM_to_BLDC_mod1_B.SPIReceive_pnaevv,
        &PMSM_to_BLDC_mod1_DW.SPIReceive_pnaevv);

      /* Outputs for Atomic SubSystem: '<S48>/Bit Shift' */
      /* Constant: '<S48>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(1, &status, &PMSM_to_BLDC_mod1_DW.BitShift_n);

      /* End of Outputs for SubSystem: '<S48>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S48>/Bit Shift1' */
      /* Constant: '<S48>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(1, &y_nb, &PMSM_to_BLDC_mod1_DW.BitShift1_o);

      /* End of Outputs for SubSystem: '<S48>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S48>/Bitwise OR' */
      PMSM_to_BLDC_mod1_B.BitwiseOR = (uint16_T)(status | y_nb |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND);
      PMSM_to_BLDC_mod1_SPITransmit_p(PMSM_to_BLDC_mod1_B.BitwiseOR,
        &PMSM_to_BLDC_mod1_DW.SPITransmit_pnaevv);
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_SubsysRanBC);
    } else if (PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_MODE) {
      for (i = 0; i < 15; i++) {
        /* Disable for MATLABSystem: '<S48>/SPI Receive' incorporates:
         *  Outport: '<S48>/Out1'
         */
        PMSM_to_BLDC_mod1_B.SPIReceive_pnaevv.SPIReceive[i] = 0U;
      }

      PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S6>/Status_Reg_2_read' */

    /* Outputs for Enabled SubSystem: '<S6>/Status_Reg1_read' incorporates:
     *  EnablePort: '<S47>/Ctrl_flag1'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write1 > 0.0) {
      if (!PMSM_to_BLDC_mod1_DW.Status_Reg1_read_MODE) {
        /* SystemReset for Atomic SubSystem: '<S47>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_p);

        /* End of SystemReset for SubSystem: '<S47>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S47>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_j);

        /* End of SystemReset for SubSystem: '<S47>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Status_Reg1_read_MODE = true;
      }

      PMSM_to_BLDC_mod1_SPIReceive_pn(&PMSM_to_BLDC_mod1_B.SPIReceive_pnaev,
        &PMSM_to_BLDC_mod1_DW.SPIReceive_pnaev);

      /* Outputs for Atomic SubSystem: '<S47>/Bit Shift' */
      /* Constant: '<S47>/Constant' */
      PMSM_to_BLDC_mod1_BitShift(1, &status, &PMSM_to_BLDC_mod1_DW.BitShift_p);

      /* End of Outputs for SubSystem: '<S47>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S47>/Bit Shift1' */
      /* Constant: '<S47>/Constant1' */
      PMSM_to_BLDC_mod1_BitShift1(0, &y_nb, &PMSM_to_BLDC_mod1_DW.BitShift1_j);

      /* End of Outputs for SubSystem: '<S47>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S47>/Bitwise OR' */
      PMSM_to_BLDC_mod1_B.BitwiseOR_p = (uint16_T)(status | y_nb |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_m);

      /* DataTypeConversion: '<S47>/Data Type Conversion' */
      PMSM_to_BLDC_mod1_B.DataTypeConversion = PMSM_to_BLDC_mod1_B.BitwiseOR_p;
      PMSM_to_BLDC_mod1_SPITransmit_p(PMSM_to_BLDC_mod1_B.DataTypeConversion,
        &PMSM_to_BLDC_mod1_DW.SPITransmit_pnaev);
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Status_Reg1_read_SubsysRanBC);
    } else if (PMSM_to_BLDC_mod1_DW.Status_Reg1_read_MODE) {
      /* Disable for Outport: '<S47>/Out1' incorporates:
       *  MATLABSystem: '<S47>/SPI Receive'
       */
      for (i = 0; i < 15; i++) {
        PMSM_to_BLDC_mod1_B.SPIReceive_pnaev.SPIReceive[i] = 0U;
      }

      /* End of Disable for Outport: '<S47>/Out1' */
      PMSM_to_BLDC_mod1_DW.Status_Reg1_read_MODE = false;
    }

    /* End of Outputs for SubSystem: '<S6>/Status_Reg1_read' */
  }

  if (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[4] == 0) {
  }

  /* Outputs for Atomic SubSystem: '<Root>/Current_sensing' */
  /* Outputs for Enabled SubSystem: '<S2>/Subsystem1' incorporates:
   *  EnablePort: '<S11>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S2>/Subsystem' incorporates:
   *  EnablePort: '<S10>/Enable'
   */
  tmp_2 = (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] == 0);

  /* End of Outputs for SubSystem: '<S2>/Subsystem1' */
  if (tmp_2) {
    PMSM_to_BLDC_mod1_DW.Subsystem_MODE_n = (PMSM_to_BLDC_mod1_B.Ib_flag > 0.0);
  }

  if (PMSM_to_BLDC_mod1_DW.Subsystem_MODE_n) {
    if (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0) {
      /* MATLABSystem: '<S14>/Analog to Digital Converter' */
      if (PMSM_to_BLDC_mod1_DW.obj_d.TunablePropsChanged) {
        PMSM_to_BLDC_mod1_DW.obj_d.TunablePropsChanged = false;
      }

      regularReadADCNormal(PMSM_to_BLDC_mod1_DW.obj_d.ADCHandle,
                           ADC_TRIGGER_AND_READ, &status);

      /* Gain: '<S10>/Gain' incorporates:
       *  DataTypeConversion: '<S10>/Data Type Conversion'
       *  MATLABSystem: '<S14>/Analog to Digital Converter'
       */
      PMSM_to_BLDC_mod1_B.Gain_k = 0.02442002442002442 * (real_T)status;
    }

    srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_g);
  }

  /* End of Outputs for SubSystem: '<S2>/Subsystem' */

  /* Outputs for Enabled SubSystem: '<S2>/Subsystem1' incorporates:
   *  EnablePort: '<S11>/Enable'
   */
  if (tmp_2) {
    PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_b = (PMSM_to_BLDC_mod1_B.Ic_flag > 0.0);
  }

  if (PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_b) {
    if (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0) {
      /* MATLABSystem: '<S17>/Analog to Digital Converter' */
      if (PMSM_to_BLDC_mod1_DW.obj_o.TunablePropsChanged) {
        PMSM_to_BLDC_mod1_DW.obj_o.TunablePropsChanged = false;
      }

      regularReadADCNormal(PMSM_to_BLDC_mod1_DW.obj_o.ADCHandle,
                           ADC_TRIGGER_AND_READ, &status);

      /* Gain: '<S11>/Gain1' incorporates:
       *  DataTypeConversion: '<S11>/Data Type Conversion1'
       *  MATLABSystem: '<S17>/Analog to Digital Converter'
       */
      PMSM_to_BLDC_mod1_B.Gain1 = 0.02442002442002442 * (real_T)status;
    }

    srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_c);
  }

  /* End of Outputs for SubSystem: '<S2>/Subsystem1' */
  if (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0) {
    /* SignalConversion generated from: '<Root>/Delay2' incorporates:
     *  Gain: '<S2>/Gain'
     *  Sum: '<S2>/Add'
     */
    rtb_PhaseCurrent_idx_2 = -(PMSM_to_BLDC_mod1_B.Gain_k +
      PMSM_to_BLDC_mod1_B.Gain1);

    /* Delay: '<Root>/Delay2' incorporates:
     *  SignalConversion generated from: '<Root>/Delay2'
     */
    PMSM_to_BLDC_mod1_B.Delay2[0] = PMSM_to_BLDC_mod1_DW.Delay2_DSTATE;
    PMSM_to_BLDC_mod1_B.Delay2[1] = PMSM_to_BLDC_mod1_B.Gain_k;
    PMSM_to_BLDC_mod1_B.Delay2[2] = PMSM_to_BLDC_mod1_B.Gain1;

    /* Outputs for Atomic SubSystem: '<Root>/SPI_read' */
    /* Outputs for Enabled SubSystem: '<S33>/Subsystem1' incorporates:
     *  EnablePort: '<S36>/Ctrl_flag2'
     */
    /* SignalConversion generated from: '<S36>/Ctrl_flag2' incorporates:
     *  Constant: '<S36>/Constant'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write2 > 0.0) {
      PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_m = true;
      PMSM_to_BLDC_mod1_SPIReceive_p(&PMSM_to_BLDC_mod1_B.SPIReceive_pn,
        &PMSM_to_BLDC_mod1_DW.SPIReceive_pn);
      PMSM_to_BLDC_mod1_SPITransmit(36864, &PMSM_to_BLDC_mod1_DW.SPITransmit_pn);
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_n);
    } else if (PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_m) {
      /* Disable for Outport: '<S36>/Out1' incorporates:
       *  MATLABSystem: '<S36>/SPI Receive'
       */
      PMSM_to_BLDC_mod1_B.SPIReceive_pn.SPIReceive = 0U;
      PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_m = false;
    }

    /* End of SignalConversion generated from: '<S36>/Ctrl_flag2' */
    /* End of Outputs for SubSystem: '<S33>/Subsystem1' */

    /* Outputs for Enabled SubSystem: '<S34>/Subsystem1' incorporates:
     *  EnablePort: '<S42>/Enable'
     */
    /* SignalConversion generated from: '<S42>/Enable' incorporates:
     *  Constant: '<S42>/Constant'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write4 > 0.0) {
      PMSM_to_BLDC_mod1_DW.Subsystem1_MODE = true;
      PMSM_to_BLDC_mod1_SPIReceive_p(&PMSM_to_BLDC_mod1_B.SPIReceive_pnae,
        &PMSM_to_BLDC_mod1_DW.SPIReceive_pnae);
      PMSM_to_BLDC_mod1_SPITransmit(38912,
        &PMSM_to_BLDC_mod1_DW.SPITransmit_pnae);
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC);
    } else if (PMSM_to_BLDC_mod1_DW.Subsystem1_MODE) {
      /* Disable for MATLABSystem: '<S42>/SPI Receive' incorporates:
       *  Outport: '<S42>/Out1'
       */
      PMSM_to_BLDC_mod1_B.SPIReceive_pnae.SPIReceive = 0U;
      PMSM_to_BLDC_mod1_DW.Subsystem1_MODE = false;
    }

    /* End of SignalConversion generated from: '<S42>/Enable' */
    /* End of Outputs for SubSystem: '<S34>/Subsystem1' */
    /* RelationalOperator: '<S32>/Compare' incorporates:
     *  Constant: '<S32>/Constant'
     */
    PMSM_to_BLDC_mod1_B.Compare =
      (PMSM_to_BLDC_mod1_B.SPIReceive_pnae.SPIReceive == 6148);

    /* RelationalOperator: '<S31>/Compare' incorporates:
     *  Constant: '<S31>/Constant'
     */
    PMSM_to_BLDC_mod1_B.Compare_g =
      (PMSM_to_BLDC_mod1_B.SPIReceive_pn.SPIReceive == 5456);

    /* Outputs for Enabled SubSystem: '<S33>/Subsystem' incorporates:
     *  EnablePort: '<S35>/Enable'
     */
    /* SignalConversion generated from: '<S35>/Enable' incorporates:
     *  Constant: '<S35>/Constant'
     *  Constant: '<S35>/Constant1'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write1 > 0.0) {
      if (!PMSM_to_BLDC_mod1_DW.Subsystem_MODE_f) {
        /* SystemReset for Atomic SubSystem: '<S35>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_hq);

        /* End of SystemReset for SubSystem: '<S35>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S35>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_p);

        /* End of SystemReset for SubSystem: '<S35>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Subsystem_MODE_f = true;
      }

      PMSM_to_BLDC_mod1_SPIReceive(&PMSM_to_BLDC_mod1_DW.SPIReceive_p);

      /* Outputs for Atomic SubSystem: '<S35>/Bit Shift' */
      PMSM_to_BLDC_mod1_BitShift(1, &status, &PMSM_to_BLDC_mod1_DW.BitShift_hq);

      /* End of Outputs for SubSystem: '<S35>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S35>/Bit Shift1' */
      PMSM_to_BLDC_mod1_BitShift1(2, &y_nb, &PMSM_to_BLDC_mod1_DW.BitShift1_p);

      /* End of Outputs for SubSystem: '<S35>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S35>/Bitwise OR' incorporates:
       *  Constant: '<S35>/Constant'
       *  Constant: '<S35>/Constant1'
       */
      PMSM_to_BLDC_mod1_B.BitwiseOR_h = (uint16_T)(status | y_nb |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_d);
      PMSM_to_BLDC_mod1_SPITransmit(PMSM_to_BLDC_mod1_B.BitwiseOR_h,
        &PMSM_to_BLDC_mod1_DW.SPITransmit_p);
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i);
    } else {
      PMSM_to_BLDC_mod1_DW.Subsystem_MODE_f = false;
    }

    /* End of SignalConversion generated from: '<S35>/Enable' */
    /* End of Outputs for SubSystem: '<S33>/Subsystem' */

    /* Outputs for Enabled SubSystem: '<S34>/Subsystem' incorporates:
     *  EnablePort: '<S41>/Enable'
     */
    /* SignalConversion generated from: '<S41>/Enable' incorporates:
     *  Constant: '<S41>/Constant'
     *  Constant: '<S41>/Constant1'
     */
    if (PMSM_to_BLDC_mod1_B.spi_write3 > 0.0) {
      if (!PMSM_to_BLDC_mod1_DW.Subsystem_MODE) {
        /* SystemReset for Atomic SubSystem: '<S41>/Bit Shift' */
        PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_b);

        /* End of SystemReset for SubSystem: '<S41>/Bit Shift' */

        /* SystemReset for Atomic SubSystem: '<S41>/Bit Shift1' */
        PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_m);

        /* End of SystemReset for SubSystem: '<S41>/Bit Shift1' */
        PMSM_to_BLDC_mod1_DW.Subsystem_MODE = true;
      }

      PMSM_to_BLDC_mod1_SPIReceive(&PMSM_to_BLDC_mod1_DW.SPIReceive_pna);

      /* Outputs for Atomic SubSystem: '<S41>/Bit Shift' */
      PMSM_to_BLDC_mod1_BitShift(1, &status, &PMSM_to_BLDC_mod1_DW.BitShift_b);

      /* End of Outputs for SubSystem: '<S41>/Bit Shift' */

      /* Outputs for Atomic SubSystem: '<S41>/Bit Shift1' */
      PMSM_to_BLDC_mod1_BitShift1(3, &y_nb, &PMSM_to_BLDC_mod1_DW.BitShift1_m);

      /* End of Outputs for SubSystem: '<S41>/Bit Shift1' */

      /* S-Function (sfix_bitop): '<S41>/Bitwise OR' incorporates:
       *  Constant: '<S41>/Constant'
       *  Constant: '<S41>/Constant1'
       */
      PMSM_to_BLDC_mod1_B.BitwiseOR_o = (uint16_T)(status | y_nb |
        PMSM_to_BLDC_mod1_ConstB.BitwiseAND_j);
      PMSM_to_BLDC_mod1_SPITransmit(PMSM_to_BLDC_mod1_B.BitwiseOR_o,
        &PMSM_to_BLDC_mod1_DW.SPITransmit_pna);
      srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC);
    } else {
      PMSM_to_BLDC_mod1_DW.Subsystem_MODE = false;
    }

    /* End of SignalConversion generated from: '<S41>/Enable' */
    /* End of Outputs for SubSystem: '<S34>/Subsystem' */
    /* End of Outputs for SubSystem: '<Root>/SPI_read' */

    /* Outputs for Atomic SubSystem: '<Root>/En_gate' */
    /* MATLABSystem: '<S20>/Digital Port Write' */
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

    /* End of MATLABSystem: '<S20>/Digital Port Write' */
    /* End of Outputs for SubSystem: '<Root>/En_gate' */
  }

  /* End of Outputs for SubSystem: '<Root>/Current_sensing' */
  if (tmp_1) {
  }

  if (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[3] == 0) {
    /* MATLABSystem: '<S59>/Analog to Digital Converter' */
    if (PMSM_to_BLDC_mod1_DW.obj_p.TunablePropsChanged) {
      PMSM_to_BLDC_mod1_DW.obj_p.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<S59>/Analog to Digital Converter' */
    regularReadADCNormal(PMSM_to_BLDC_mod1_DW.obj_p.ADCHandle,
                         ADC_TRIGGER_AND_READ,
                         &PMSM_to_BLDC_mod1_B.AnalogtoDigitalConverter);

    /* Gain: '<S7>/Gain' incorporates:
     *  DataTypeConversion: '<S7>/Data Type Conversion'
     */
    PMSM_to_BLDC_mod1_B.Gain = 0.015625 * (real_T)
      PMSM_to_BLDC_mod1_B.AnalogtoDigitalConverter;
  }

  if (tmp_0) {
    /* Update for Delay: '<Root>/Delay' */
    PMSM_to_BLDC_mod1_DW.Delay_DSTATE = PMSM_to_BLDC_mod1_B.Compare_g;

    /* Update for Delay: '<Root>/Delay1' */
    PMSM_to_BLDC_mod1_DW.Delay1_DSTATE = PMSM_to_BLDC_mod1_B.Compare;

    /* Update for Delay: '<Root>/Delay2' */
    PMSM_to_BLDC_mod1_DW.Delay2_DSTATE = rtb_PhaseCurrent_idx_2;
  }

  {                                    /* Sample time: [5e-05s, 0.0s] */
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

  if (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.0001s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((PMSM_to_BLDC_mod1_M->Timing.clockTick1) * 0.0001);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1, extmodeTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  if (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] == 0) {/* Sample time: [0.001s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((PMSM_to_BLDC_mod1_M->Timing.clockTick2) * 0.001);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(2, extmodeTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  if (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[3] == 0) {/* Sample time: [0.1s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((PMSM_to_BLDC_mod1_M->Timing.clockTick3) * 0.1);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(3, extmodeTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  if (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[4] == 0) {/* Sample time: [1.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((PMSM_to_BLDC_mod1_M->Timing.clockTick4) * 1.0);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(4, extmodeTime);
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
    /* Update absolute timer for sample time: [0.0001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.0001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    PMSM_to_BLDC_mod1_M->Timing.clockTick1++;
  }

  if (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick2" ensures timer will not overflow during the
     * application lifespan selected.
     */
    PMSM_to_BLDC_mod1_M->Timing.clockTick2++;
  }

  if (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[3] == 0) {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick3" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.1, which is the step size
     * of the task. Size of "clockTick3" ensures timer will not overflow during the
     * application lifespan selected.
     */
    PMSM_to_BLDC_mod1_M->Timing.clockTick3++;
  }

  if (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[4] == 0) {
    /* Update absolute timer for sample time: [1.0s, 0.0s] */
    /* The "clockTick4" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 1.0, which is the step size
     * of the task. Size of "clockTick4" ensures timer will not overflow during the
     * application lifespan selected.
     */
    PMSM_to_BLDC_mod1_M->Timing.clockTick4++;
  }

  rate_scheduler();
}

/* Model initialize function */
void PMSM_to_BLDC_mod1_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(PMSM_to_BLDC_mod1_M, -1);
  PMSM_to_BLDC_mod1_M->Timing.stepSize0 = 5.0E-5;

  /* External mode info */
  PMSM_to_BLDC_mod1_M->Sizes.checksums[0] = (4247167690U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[1] = (2814287463U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[2] = (172801364U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[3] = (4209059384U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[60];
    PMSM_to_BLDC_mod1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_g;
    systemRan[3] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_g;
    systemRan[4] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_c;
    systemRan[5] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_c;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[16] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[17] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[18] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[19] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[20] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[21] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[22] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[25] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[26] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[27] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[28] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[29] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[30] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[31] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_n;
    systemRan[32] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_n;
    systemRan[33] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_n;
    systemRan[34] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC;
    systemRan[35] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC;
    systemRan[36] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC;
    systemRan[37] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC;
    systemRan[38] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC;
    systemRan[39] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC;
    systemRan[40] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC;
    systemRan[41] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC;
    systemRan[42] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC;
    systemRan[43] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC;
    systemRan[44] = &rtAlwaysEnabled;
    systemRan[45] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg1_read_SubsysRanBC;
    systemRan[46] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg1_read_SubsysRanBC;
    systemRan[47] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg1_read_SubsysRanBC;
    systemRan[48] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg1_read_SubsysRanBC;
    systemRan[49] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg1_read_SubsysRanBC;
    systemRan[50] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg1_read_SubsysRanBC;
    systemRan[51] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg1_read_SubsysRanBC;
    systemRan[52] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_SubsysRanBC;
    systemRan[53] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_SubsysRanBC;
    systemRan[54] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_SubsysRanBC;
    systemRan[55] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_SubsysRanBC;
    systemRan[56] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_SubsysRanBC;
    systemRan[57] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_SubsysRanBC;
    systemRan[58] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Status_Reg_2_read_SubsysRanBC;
    systemRan[59] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PMSM_to_BLDC_mod1_M->extModeInfo,
      &PMSM_to_BLDC_mod1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PMSM_to_BLDC_mod1_M->extModeInfo,
                        PMSM_to_BLDC_mod1_M->Sizes.checksums);
    rteiSetTPtr(PMSM_to_BLDC_mod1_M->extModeInfo, rtmGetTPtr(PMSM_to_BLDC_mod1_M));
  }

  /* SystemInitialize for Atomic SubSystem: '<S21>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift);

  /* End of SystemInitialize for SubSystem: '<S21>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S21>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1);

  /* End of SystemInitialize for SubSystem: '<S21>/Bit Shift1' */

  /* Start for MATLABSystem: '<S21>/SPI Receive' */
  PMSM_to_BLDC_mod1_DW.obj_g.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj_g.matlabCodegenIsDeleted = false;
  PMSM_to_BL_SystemCore_setup_oxg(&PMSM_to_BLDC_mod1_DW.obj_g);

  /* Start for MATLABSystem: '<S21>/SPI Transmit' */
  PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete = false;
  PMSM_to_BLDC_mod1_DW.obj_j.isInitialized = 1;
  PMSM_to_SPIDrvBlock_setupImpl_o(&PMSM_to_BLDC_mod1_DW.obj_j);
  PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<S4>/Control_Reg2' */
  /* SystemInitialize for Atomic SubSystem: '<S22>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_h);

  /* End of SystemInitialize for SubSystem: '<S22>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S22>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_d);

  /* End of SystemInitialize for SubSystem: '<S22>/Bit Shift1' */

  /* Start for MATLABSystem: '<S22>/SPI Transmit' */
  PMSM_to_BLDC_mod1_DW.obj_n.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_n.isSetupComplete = false;
  PMSM_to_BLDC_mod1_DW.obj_n.isInitialized = 1;
  PMSM_to_SPIDrvBlock_setupImpl_o(&PMSM_to_BLDC_mod1_DW.obj_n);
  PMSM_to_BLDC_mod1_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S22>/SPI Receive' */
  PMSM_to_BLDC_mod1_DW.obj.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = false;
  PMSM_to_B_SystemCore_setup_oxgk(&PMSM_to_BLDC_mod1_DW.obj);

  /* End of SystemInitialize for SubSystem: '<S4>/Ctrl_Reg_1' */
  /* End of SystemInitialize for SubSystem: '<Root>/SPI_Write' */
  /* SystemInitialize for Atomic SubSystem: '<S48>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_n);

  /* End of SystemInitialize for SubSystem: '<S48>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S48>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_o);

  /* End of SystemInitialize for SubSystem: '<S48>/Bit Shift1' */
  PMSM_to_BLDC__SPIReceive_k_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaevv);
  PMSM_to_BLDC_SPITransmit_d_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnaevv);

  /* End of SystemInitialize for SubSystem: '<S6>/Status_Reg_2_read' */

  /* SystemInitialize for Atomic SubSystem: '<S47>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_p);

  /* End of SystemInitialize for SubSystem: '<S47>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S47>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_j);

  /* End of SystemInitialize for SubSystem: '<S47>/Bit Shift1' */
  PMSM_to_BLDC__SPIReceive_k_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaev);
  PMSM_to_BLDC_SPITransmit_d_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnaev);

  /* End of SystemInitialize for SubSystem: '<S6>/Status_Reg1_read' */

  /* Start for MATLABSystem: '<S14>/Analog to Digital Converter' */
  PMSM_to_BLDC_mod1_DW.obj_d.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj_d.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_SystemCore_setup_o(&PMSM_to_BLDC_mod1_DW.obj_d);

  /* End of SystemInitialize for SubSystem: '<S2>/Subsystem' */
  /* Start for MATLABSystem: '<S17>/Analog to Digital Converter' */
  PMSM_to_BLDC_mod1_DW.obj_o.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted = false;
  PMSM_to_BLD_SystemCore_setup_ox(&PMSM_to_BLDC_mod1_DW.obj_o);

  /* End of SystemInitialize for SubSystem: '<S2>/Subsystem1' */
  /* End of SystemInitialize for SubSystem: '<Root>/Current_sensing' */
  /* SystemInitialize for Enabled SubSystem: '<S33>/Subsystem1' */
  PMSM_to_BLDC__SPIReceive_e_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pn);
  PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pn);

  /* End of SystemInitialize for SubSystem: '<S33>/Subsystem1' */

  /* SystemInitialize for Enabled SubSystem: '<S34>/Subsystem1' */
  PMSM_to_BLDC__SPIReceive_e_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnae);
  PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnae);

  /* End of SystemInitialize for SubSystem: '<S34>/Subsystem1' */

  /* SystemInitialize for Atomic SubSystem: '<S35>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_hq);

  /* End of SystemInitialize for SubSystem: '<S35>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S35>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_p);

  /* End of SystemInitialize for SubSystem: '<S35>/Bit Shift1' */
  PMSM_to_BLDC_mo_SPIReceive_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_p);
  PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_p);

  /* End of SystemInitialize for SubSystem: '<S33>/Subsystem' */

  /* SystemInitialize for Atomic SubSystem: '<S41>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_b);

  /* End of SystemInitialize for SubSystem: '<S41>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S41>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_m);

  /* End of SystemInitialize for SubSystem: '<S41>/Bit Shift1' */
  PMSM_to_BLDC_mo_SPIReceive_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pna);
  PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pna);

  /* End of SystemInitialize for SubSystem: '<S34>/Subsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/SPI_read' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/En_gate' */
  /* Start for MATLABSystem: '<S20>/Digital Port Write' */
  PMSM_to_BLDC_mod1_DW.obj_ow.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_ow.isInitialized = 1;
  PMSM_to_BLDC_mod1_DW.obj_ow.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<Root>/En_gate' */

  /* Start for MATLABSystem: '<S59>/Analog to Digital Converter' */
  PMSM_to_BLDC_mod1_DW.obj_p.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj_p.matlabCodegenIsDeleted = false;
  PMSM_to__SystemCore_setup_oxgkf(&PMSM_to_BLDC_mod1_DW.obj_p);
}

/* Model terminate function */
void PMSM_to_BLDC_mod1_terminate(void)
{
  uint32_T SPIPinsLoc;

  /* Terminate for Atomic SubSystem: '<Root>/SPI_Write' */
  /* Terminate for Enabled SubSystem: '<S4>/Control_Reg2' */
  /* Terminate for MATLABSystem: '<S21>/SPI Receive' */
  if (!PMSM_to_BLDC_mod1_DW.obj_g.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_g.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_g.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_g.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S21>/SPI Receive' */
  /* Terminate for MATLABSystem: '<S21>/SPI Transmit' */
  if (!PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_j.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S21>/SPI Transmit' */
  /* Terminate for Enabled SubSystem: '<S4>/Ctrl_Reg_1' */
  /* Terminate for MATLABSystem: '<S22>/SPI Transmit' */
  if (!PMSM_to_BLDC_mod1_DW.obj_n.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_n.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_n.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_n.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S22>/SPI Transmit' */
  /* Terminate for MATLABSystem: '<S22>/SPI Receive' */
  if (!PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S22>/SPI Receive' */
  /* End of Terminate for SubSystem: '<S4>/Ctrl_Reg_1' */

  /* Terminate for Enabled SubSystem: '<S6>/Status_Reg_2_read' */
  PMSM_to_BLDC__SPIReceive_c_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaevv);
  PMSM_to_BLDC_SPITransmit_a_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnaevv);

  /* Terminate for Enabled SubSystem: '<S6>/Status_Reg1_read' */
  PMSM_to_BLDC__SPIReceive_c_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnaev);
  PMSM_to_BLDC_SPITransmit_a_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnaev);

  /* Terminate for Atomic SubSystem: '<Root>/Current_sensing' */
  /* Terminate for Enabled SubSystem: '<S2>/Subsystem' */
  /* Terminate for MATLABSystem: '<S14>/Analog to Digital Converter' */
  if (!PMSM_to_BLDC_mod1_DW.obj_d.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_d.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_d.isSetupComplete) {
      ADC_Handle_Deinit(PMSM_to_BLDC_mod1_DW.obj_d.ADCHandle, ADC_NORMAL_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S14>/Analog to Digital Converter' */
  /* Terminate for Enabled SubSystem: '<S2>/Subsystem1' */
  /* Terminate for MATLABSystem: '<S17>/Analog to Digital Converter' */
  if (!PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_o.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_o.isSetupComplete) {
      ADC_Handle_Deinit(PMSM_to_BLDC_mod1_DW.obj_o.ADCHandle, ADC_NORMAL_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S17>/Analog to Digital Converter' */
  /* Terminate for Atomic SubSystem: '<Root>/SPI_read' */
  /* Terminate for Enabled SubSystem: '<S33>/Subsystem1' */
  PMSM_to_BLDC__SPIReceive_m_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pn);
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pn);

  /* End of Terminate for SubSystem: '<S33>/Subsystem1' */

  /* Terminate for Enabled SubSystem: '<S34>/Subsystem1' */
  PMSM_to_BLDC__SPIReceive_m_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnae);
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnae);

  /* End of Terminate for SubSystem: '<S34>/Subsystem1' */

  /* Terminate for Enabled SubSystem: '<S33>/Subsystem' */
  PMSM_to_BLDC_mo_SPIReceive_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_p);
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_p);

  /* Terminate for Enabled SubSystem: '<S34>/Subsystem' */
  PMSM_to_BLDC_mo_SPIReceive_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pna);
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pna);

  /* Terminate for Atomic SubSystem: '<Root>/En_gate' */
  /* Terminate for MATLABSystem: '<S20>/Digital Port Write' */
  if (!PMSM_to_BLDC_mod1_DW.obj_ow.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_ow.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S20>/Digital Port Write' */
  /* End of Terminate for SubSystem: '<Root>/En_gate' */
  /* Terminate for MATLABSystem: '<S59>/Analog to Digital Converter' */
  if (!PMSM_to_BLDC_mod1_DW.obj_p.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_p.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_p.isSetupComplete) {
      ADC_Handle_Deinit(PMSM_to_BLDC_mod1_DW.obj_p.ADCHandle, ADC_NORMAL_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S59>/Analog to Digital Converter' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
