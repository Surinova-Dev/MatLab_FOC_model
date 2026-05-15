/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PMSM_to_BLDC_mod1.c
 *
 * Code generated for Simulink model 'PMSM_to_BLDC_mod1'.
 *
 * Model version                  : 4.837
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Fri May 15 17:04:09 2026
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

/* Named constants for MATLAB Function: '<S19>/bit_shift' */
#define PMSM_to_BLDC_mod1_CALL_EVENT   (-1)

/* Named constants for MATLAB Function: '<S20>/bit_shift' */
#define PMSM_to_BLDC_mod1_CALL_EVENT_j (-1)

/* Named constants for Chart: '<Root>/Chart' */
#define PMSM_to_BLDC__IN_Initialization (3U)
#define PMSM_to_BLDC_m_IN_Current_sense (1U)
#define PMSM_to_BLDC_mod1_IN_En_Gate   (2U)
#define PMSM_to_BLDC_mod1_IN_SPI_init1 (4U)
#define PMSM_to_BLDC_mod1_IN_SPI_init2 (5U)
#define PMSM_to_BLDC_mod1_IN_SPI_init3 (6U)
#define PMSM_to_BLDC_mod1_IN_SPI_init4 (7U)
#define PMSM_to_BLDC_mod1_IN_SPI_write (8U)
#define PMSM_to_BLDC_mod1_IN_SPI_write2 (10U)
#define PMSM_to_BLDC_mod1_IN_SPI_write5 (11U)
#define PMSM_to_BLDC_mod1_IN_SPI_write6 (12U)
#define PMSM_to_BLDC_mod1_IN_SPI_write7 (13U)
#define PMSM_to_BLDC_mod1_IN_SPI_write8 (14U)
#define PMSM_to_BLDC_mod1_IN_SPI_write9 (15U)
#define PMSM_to_BLDC_mod_IN_SPI_write10 (9U)

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
static void PMSM_to_BLDC_SystemCore_setup_o(stm32cube_blocks_AnalogInput__T *obj);
static void PMSM_to_BLD_SystemCore_setup_ox(stm32cube_blocks_AnalogInput__T *obj);
static void PMSM_to_BL_SystemCore_setup_oxg(stm32cube_blocks_SPIControlle_T *obj);
static void PMSM_to_SPIDrvBlock_setupImpl_o(stm32cube_blocks_SPIControl_d_T *obj);
static void PMSM_to_B_SystemCore_setup_oxgk(stm32cube_blocks_SPIControlle_T *obj);
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
  if ((PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * System initialize for atomic system:
 *    '<S17>/Bit Shift'
 *    '<S18>/Bit Shift'
 *    '<S31>/Bit Shift'
 *    '<S37>/Bit Shift'
 */
void PMSM_to_BLDC_mod1_BitShift_Init(DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* SystemInitialize for MATLAB Function: '<S19>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
}

/*
 * System reset for atomic system:
 *    '<S17>/Bit Shift'
 *    '<S18>/Bit Shift'
 *    '<S31>/Bit Shift'
 *    '<S37>/Bit Shift'
 */
void PMSM_to_BLDC_mod_BitShift_Reset(DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* SystemReset for MATLAB Function: '<S19>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
}

/*
 * Output and update for atomic system:
 *    '<S17>/Bit Shift'
 *    '<S18>/Bit Shift'
 *    '<S31>/Bit Shift'
 *    '<S37>/Bit Shift'
 */
void PMSM_to_BLDC_mod1_BitShift(uint16_T rtu_u, uint16_T *rty_y,
  DW_BitShift_PMSM_to_BLDC_mod1_T *localDW)
{
  /* MATLAB Function: '<S19>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT;
  *rty_y = (uint16_T)(rtu_u << 15);
}

/*
 * System initialize for atomic system:
 *    '<S17>/Bit Shift1'
 *    '<S18>/Bit Shift1'
 *    '<S31>/Bit Shift1'
 *    '<S37>/Bit Shift1'
 */
void PMSM_to_BLDC_mod_BitShift1_Init(DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* SystemInitialize for MATLAB Function: '<S20>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_j;
}

/*
 * System reset for atomic system:
 *    '<S17>/Bit Shift1'
 *    '<S18>/Bit Shift1'
 *    '<S31>/Bit Shift1'
 *    '<S37>/Bit Shift1'
 */
void PMSM_to_BLDC_mo_BitShift1_Reset(DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* SystemReset for MATLAB Function: '<S20>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_j;
}

/*
 * Output and update for atomic system:
 *    '<S17>/Bit Shift1'
 *    '<S18>/Bit Shift1'
 *    '<S31>/Bit Shift1'
 *    '<S37>/Bit Shift1'
 */
void PMSM_to_BLDC_mod1_BitShift1(uint16_T rtu_u, uint16_T *rty_y,
  DW_BitShift1_PMSM_to_BLDC_mod_T *localDW)
{
  /* MATLAB Function: '<S20>/bit_shift' */
  localDW->sfEvent = PMSM_to_BLDC_mod1_CALL_EVENT_j;
  *rty_y = (uint16_T)(rtu_u << 11);
}

static void PMSM_to_BLDC_m_SystemCore_setup(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S31>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S31>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S31>/SPI Receive' */
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
  /* Start for MATLABSystem: '<S31>/SPI Receive' */
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

  /* MATLABSystem: '<S31>/SPI Receive' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    MW_SPI_Read_Databits(localDW->obj.MW_SPI_HANDLE, &tmp[0], 15U, 1, 1, 1U);
    LL_GPIO_SetOutputPin(GPIOC, 16384U);
  }

  /* End of MATLABSystem: '<S31>/SPI Receive' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC_mo_SPIReceive_Term(DW_SPIReceive_PMSM_to_BLDC_mo_T *localDW)
{
  /* Terminate for MATLABSystem: '<S31>/SPI Receive' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S31>/SPI Receive' */
}

static void PMSM_to_B_SPIDrvBlock_setupImpl(stm32cube_blocks_SPIControl_d_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;

  /* Start for MATLABSystem: '<S31>/SPI Transmit' */
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S31>/SPI Transmit' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S31>/SPI Transmit' */
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
  /* Start for MATLABSystem: '<S31>/SPI Transmit' */
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

  /* MATLABSystem: '<S31>/SPI Transmit' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    LL_GPIO_ResetOutputPin(GPIOC, 16384U);
    MW_SPI_Write_Databits(localDW->obj.MW_SPI_HANDLE, &rtu_0, 1U, 1, 1, 1U);
  }

  /* End of MATLABSystem: '<S31>/SPI Transmit' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC_m_SPITransmit_Term(DW_SPITransmit_PMSM_to_BLDC_m_T *localDW)
{
  /* Terminate for MATLABSystem: '<S31>/SPI Transmit' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S31>/SPI Transmit' */
}

static void PMSM_to_BLDC_SystemCore_setup_n(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S32>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S32>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S32>/SPI Receive' */
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
  /* Start for MATLABSystem: '<S32>/SPI Receive' */
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

  /* MATLABSystem: '<S32>/SPI Receive' */
  status = MW_STM32_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 2U, 3840U,
    MW_SPI_MODE_3);
  if (status == 0) {
    MW_SPI_Read_Databits(localDW->obj.MW_SPI_HANDLE, &localB->SPIReceive, 1U, 1,
                         1, 1U);
    LL_GPIO_SetOutputPin(GPIOC, 16384U);
  }

  /* End of MATLABSystem: '<S32>/SPI Receive' */
}

/* Termination for atomic system: */
void PMSM_to_BLDC__SPIReceive_m_Term(DW_SPIReceive_PMSM_to_BLDC__f_T *localDW)
{
  /* Terminate for MATLABSystem: '<S32>/SPI Receive' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      uint32_T SPIPinsLoc;
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S32>/SPI Receive' */
}

static void PMSM_to_BLDC_SystemCore_setup_o(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S10>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S10>/Analog to Digital Converter' */
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

  /* Start for MATLABSystem: '<S13>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S13>/Analog to Digital Converter' */
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

static void PMSM_to_BL_SystemCore_setup_oxg(stm32cube_blocks_SPIControlle_T *obj)
{
  MW_STM32_SPI_FIFO_Access_type b_dataType;
  STM32_SPI_Struct_T * spiBlock;
  STM32_SPI_ModuleStruct_T c;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S17>/SPI Receive' */
  obj->isInitialized = 1;
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S17>/SPI Receive' */
  c.rxMode = SPI_RX_POLLING_MODE;
  c.txMode = SPI_TX_POLLING_MODE;
  c.rxdmaPeripheralPtr = NULL;
  c.rxdmastream = 0;
  c.txdmaPeripheralPtr = NULL;
  c.txdmastream = 0;
  obj->MW_SPI_BlockStruct.h_spi = NULL;
  obj->MW_SPI_BlockStruct.gpioPort = GPIOC;
  b_dataType = FIFO_ACCESS_16BIT;

  /* Start for MATLABSystem: '<S17>/SPI Receive' */
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

  /* Start for MATLABSystem: '<S17>/SPI Transmit' incorporates:
   *  MATLABSystem: '<S18>/SPI Transmit'
   */
  c.buffer.rxBufferPtr = NULL;
  c.buffer.txBufferPtr = NULL;
  c.PeripheralPtr = SPI3;
  c.enableRxOrTx = 0U;
  c.buffer.rxBufferSize = 0U;
  c.buffer.txBufferSize = 0U;

  /* Start for MATLABSystem: '<S17>/SPI Transmit' incorporates:
   *  MATLABSystem: '<S18>/SPI Transmit'
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

  /* Start for MATLABSystem: '<S17>/SPI Transmit' incorporates:
   *  MATLABSystem: '<S18>/SPI Transmit'
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
  uint32_T pinMask;
  uint32_T pinWriteLoc;
  uint16_T tmp[16];
  uint16_T data;
  uint16_T y_n;

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

  /* Delay: '<Root>/Delay' */
  PMSM_to_BLDC_mod1_B.Delay = PMSM_to_BLDC_mod1_DW.Delay_DSTATE;

  /* Delay: '<Root>/Delay1' */
  PMSM_to_BLDC_mod1_B.Delay1 = PMSM_to_BLDC_mod1_DW.Delay1_DSTATE;

  /* Chart: '<Root>/Chart' */
  if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 < 8191) {
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
     case PMSM_to_BLDC_m_IN_Current_sense:
      PMSM_to_BLDC_mod1_B.Ib_flag = 1.0;
      PMSM_to_BLDC_mod1_B.Ic_flag = 1.0;
      if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 1000) {
        PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
        PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
          PMSM_to_BLDC_mod1_IN_SPI_write;
        PMSM_to_BLDC_mod1_B.spi_write1 = 1.0;
      }
      break;

     case PMSM_to_BLDC_mod1_IN_En_Gate:
      PMSM_to_BLDC_mod1_B.En_State = 1.0;
      if ((PMSM_to_BLDC_mod1_B.En_State == 1.0) &&
          (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 5000)) {
        PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
        PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
          PMSM_to_BLDC_mod1_IN_SPI_init1;
        PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 1.0;
      }
      break;

     case PMSM_to_BLDC__IN_Initialization:
      PMSM_to_BLDC_mod1_B.En_State = 0.0;
      if ((PMSM_to_BLDC_mod1_DW.CS_val == 1.0) &&
          (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 40)) {
        PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
        PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
          PMSM_to_BLDC_mod1_IN_En_Gate;
        PMSM_to_BLDC_mod1_B.En_State = 1.0;
      }
      break;

     case PMSM_to_BLDC_mod1_IN_SPI_init1:
      PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 1.0;
      if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 5000) {
        PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
        PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
          PMSM_to_BLDC_mod1_IN_SPI_init2;
        PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 0.0;
      }
      break;

     case PMSM_to_BLDC_mod1_IN_SPI_init2:
      PMSM_to_BLDC_mod1_B.Ctrl_flag1 = 0.0;
      if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 1000) {
        PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
        PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
          PMSM_to_BLDC_mod1_IN_SPI_init3;
        PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 1.0;
      }
      break;

     case PMSM_to_BLDC_mod1_IN_SPI_init3:
      PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 1.0;
      if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 3000) {
        PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
          PMSM_to_BLDC_mod1_IN_SPI_init4;
        PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 0.0;
      }
      break;

     case PMSM_to_BLDC_mod1_IN_SPI_init4:
      PMSM_to_BLDC_mod1_B.Ctrl_flag2 = 0.0;
      PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
      PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
        PMSM_to_BLDC_m_IN_Current_sense;
      PMSM_to_BLDC_mod1_B.Ib_flag = 1.0;
      PMSM_to_BLDC_mod1_B.Ic_flag = 1.0;
      break;

     case PMSM_to_BLDC_mod1_IN_SPI_write:
      PMSM_to_BLDC_mod1_B.spi_write1 = 1.0;
      if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
        PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
        PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
          PMSM_to_BLDC_mod1_IN_SPI_write2;
        PMSM_to_BLDC_mod1_B.spi_write1 = 0.0;
      }
      break;

     case PMSM_to_BLDC_mod_IN_SPI_write10:
      PMSM_to_BLDC_mod1_B.spi_write4 = 0.0;
      PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
      PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
        PMSM_to_BLDC_mod1_IN_SPI_write;
      PMSM_to_BLDC_mod1_B.spi_write1 = 1.0;
      break;

     case PMSM_to_BLDC_mod1_IN_SPI_write2:
      PMSM_to_BLDC_mod1_B.spi_write1 = 0.0;
      if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
        PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
        PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
          PMSM_to_BLDC_mod1_IN_SPI_write5;
        PMSM_to_BLDC_mod1_B.spi_write2 = 1.0;
      }
      break;

     case PMSM_to_BLDC_mod1_IN_SPI_write5:
      PMSM_to_BLDC_mod1_B.spi_write2 = 1.0;
      if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
        PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
        PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
          PMSM_to_BLDC_mod1_IN_SPI_write6;
        PMSM_to_BLDC_mod1_B.spi_write2 = 0.0;
      }
      break;

     case PMSM_to_BLDC_mod1_IN_SPI_write6:
      PMSM_to_BLDC_mod1_B.spi_write2 = 0.0;
      if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
        PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
        PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
          PMSM_to_BLDC_mod1_IN_SPI_write7;
        PMSM_to_BLDC_mod1_B.spi_write3 = 1.0;
      }
      break;

     case PMSM_to_BLDC_mod1_IN_SPI_write7:
      PMSM_to_BLDC_mod1_B.spi_write3 = 1.0;
      if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
        PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
        PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
          PMSM_to_BLDC_mod1_IN_SPI_write8;
        PMSM_to_BLDC_mod1_B.spi_write3 = 0.0;
      }
      break;

     case PMSM_to_BLDC_mod1_IN_SPI_write8:
      PMSM_to_BLDC_mod1_B.spi_write3 = 0.0;
      if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
        PMSM_to_BLDC_mod1_DW.temporalCounter_i1 = 0U;
        PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
          PMSM_to_BLDC_mod1_IN_SPI_write9;
        PMSM_to_BLDC_mod1_B.spi_write4 = 1.0;
      }
      break;

     default:
      /* case IN_SPI_write9: */
      PMSM_to_BLDC_mod1_B.spi_write4 = 1.0;
      if (PMSM_to_BLDC_mod1_DW.temporalCounter_i1 >= 2000) {
        PMSM_to_BLDC_mod1_DW.is_c3_PMSM_to_BLDC_mod1 =
          PMSM_to_BLDC_mod_IN_SPI_write10;
        PMSM_to_BLDC_mod1_B.spi_write4 = 0.0;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* Outputs for Enabled SubSystem: '<S2>/Subsystem' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (PMSM_to_BLDC_mod1_B.Ib_flag > 0.0) {
    if (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0) {
      /* MATLABSystem: '<S10>/Analog to Digital Converter' */
      if (PMSM_to_BLDC_mod1_DW.obj_d.TunablePropsChanged) {
        PMSM_to_BLDC_mod1_DW.obj_d.TunablePropsChanged = false;
      }

      regularReadADCNormal(PMSM_to_BLDC_mod1_DW.obj_d.ADCHandle,
                           ADC_TRIGGER_AND_READ, &data);

      /* Gain: '<S6>/Gain' incorporates:
       *  DataTypeConversion: '<S6>/Data Type Conversion'
       *  MATLABSystem: '<S10>/Analog to Digital Converter'
       */
      PMSM_to_BLDC_mod1_B.Gain = 0.02442002442002442 * (real_T)data;
    }

    srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_g);
  }

  /* End of Outputs for SubSystem: '<S2>/Subsystem' */

  /* Outputs for Enabled SubSystem: '<S2>/Subsystem1' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (PMSM_to_BLDC_mod1_B.Ic_flag > 0.0) {
    if (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0) {
      /* MATLABSystem: '<S13>/Analog to Digital Converter' */
      if (PMSM_to_BLDC_mod1_DW.obj_o.TunablePropsChanged) {
        PMSM_to_BLDC_mod1_DW.obj_o.TunablePropsChanged = false;
      }

      regularReadADCNormal(PMSM_to_BLDC_mod1_DW.obj_o.ADCHandle,
                           ADC_TRIGGER_AND_READ, &data);

      /* Gain: '<S7>/Gain1' incorporates:
       *  DataTypeConversion: '<S7>/Data Type Conversion1'
       *  MATLABSystem: '<S13>/Analog to Digital Converter'
       */
      PMSM_to_BLDC_mod1_B.Gain1 = 0.02442002442002442 * (real_T)data;
    }

    srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_c);
  }

  /* End of Outputs for SubSystem: '<S2>/Subsystem1' */

  /* MATLABSystem: '<S16>/Digital Port Write' */
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

  /* End of MATLABSystem: '<S16>/Digital Port Write' */

  /* Logic: '<S4>/AND1' */
  PMSM_to_BLDC_mod1_B.AND1 = ((PMSM_to_BLDC_mod1_B.En_State != 0.0) &&
    (PMSM_to_BLDC_mod1_B.Ctrl_flag2 != 0.0));

  /* Outputs for Enabled SubSystem: '<S4>/Control_Reg2' incorporates:
   *  EnablePort: '<S17>/Enable'
   */
  if (PMSM_to_BLDC_mod1_B.AND1) {
    if (!PMSM_to_BLDC_mod1_DW.Control_Reg2_MODE) {
      /* SystemReset for Atomic SubSystem: '<S17>/Bit Shift' */
      PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift);

      /* End of SystemReset for SubSystem: '<S17>/Bit Shift' */

      /* SystemReset for Atomic SubSystem: '<S17>/Bit Shift1' */
      PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1);

      /* End of SystemReset for SubSystem: '<S17>/Bit Shift1' */
      PMSM_to_BLDC_mod1_DW.Control_Reg2_MODE = true;
    }

    /* MATLABSystem: '<S17>/SPI Receive' */
    data = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_g.MW_SPI_HANDLE, 2U,
      3840U, MW_SPI_MODE_3);
    if (data == 0) {
      MW_SPI_Read_Databits(PMSM_to_BLDC_mod1_DW.obj_g.MW_SPI_HANDLE, &tmp[0],
                           16U, 1, 1, 1U);
      LL_GPIO_SetOutputPin(GPIOC, 16384U);
    }

    /* End of MATLABSystem: '<S17>/SPI Receive' */

    /* Outputs for Atomic SubSystem: '<S17>/Bit Shift' */
    /* Constant: '<S17>/Constant' */
    PMSM_to_BLDC_mod1_BitShift(0, &data, &PMSM_to_BLDC_mod1_DW.BitShift);

    /* End of Outputs for SubSystem: '<S17>/Bit Shift' */

    /* Outputs for Atomic SubSystem: '<S17>/Bit Shift1' */
    /* Constant: '<S17>/Constant1' */
    PMSM_to_BLDC_mod1_BitShift1(3, &y_n, &PMSM_to_BLDC_mod1_DW.BitShift1);

    /* End of Outputs for SubSystem: '<S17>/Bit Shift1' */

    /* S-Function (sfix_bitop): '<S17>/Bitwise OR' */
    PMSM_to_BLDC_mod1_B.BitwiseOR_n = (uint16_T)(data | y_n |
      PMSM_to_BLDC_mod1_ConstB.BitwiseAND_j);

    /* DataTypeConversion: '<S17>/Data Type Conversion' */
    PMSM_to_BLDC_mod1_B.DataTypeConversion = PMSM_to_BLDC_mod1_B.BitwiseOR_n;

    /* MATLABSystem: '<S17>/SPI Transmit' */
    data = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE, 2U,
      3840U, MW_SPI_MODE_3);
    if (data == 0) {
      LL_GPIO_ResetOutputPin(GPIOC, 16384U);
      MW_SPI_Write_Databits(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE,
                            &PMSM_to_BLDC_mod1_B.DataTypeConversion, 1U, 1, 1,
                            1000U);
    }

    /* End of MATLABSystem: '<S17>/SPI Transmit' */
    srUpdateBC(PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC);
  } else {
    PMSM_to_BLDC_mod1_DW.Control_Reg2_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S4>/Control_Reg2' */

  /* Logic: '<S4>/AND' */
  PMSM_to_BLDC_mod1_B.AND = ((PMSM_to_BLDC_mod1_B.En_State != 0.0) &&
    (PMSM_to_BLDC_mod1_B.Ctrl_flag1 != 0.0));

  /* Outputs for Enabled SubSystem: '<S4>/Ctrl_Reg_1' incorporates:
   *  EnablePort: '<S18>/Enable'
   */
  if (PMSM_to_BLDC_mod1_B.AND) {
    if (!PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_MODE) {
      /* SystemReset for Atomic SubSystem: '<S18>/Bit Shift' */
      PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_h);

      /* End of SystemReset for SubSystem: '<S18>/Bit Shift' */

      /* SystemReset for Atomic SubSystem: '<S18>/Bit Shift1' */
      PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_d);

      /* End of SystemReset for SubSystem: '<S18>/Bit Shift1' */
      PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_MODE = true;
    }

    /* Outputs for Atomic SubSystem: '<S18>/Bit Shift' */
    /* Constant: '<S18>/Constant' */
    PMSM_to_BLDC_mod1_BitShift(0, &data, &PMSM_to_BLDC_mod1_DW.BitShift_h);

    /* End of Outputs for SubSystem: '<S18>/Bit Shift' */

    /* Outputs for Atomic SubSystem: '<S18>/Bit Shift1' */
    /* Constant: '<S18>/Constant1' */
    PMSM_to_BLDC_mod1_BitShift1(2, &y_n, &PMSM_to_BLDC_mod1_DW.BitShift1_d);

    /* End of Outputs for SubSystem: '<S18>/Bit Shift1' */

    /* S-Function (sfix_bitop): '<S18>/Bitwise OR' */
    PMSM_to_BLDC_mod1_B.BitwiseOR_e = (uint16_T)(data | y_n |
      PMSM_to_BLDC_mod1_ConstB.BitwiseAND_e);

    /* MATLABSystem: '<S18>/SPI Transmit' */
    data = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj_n.MW_SPI_HANDLE, 2U,
      3840U, MW_SPI_MODE_3);
    if (data == 0) {
      LL_GPIO_ResetOutputPin(GPIOC, 16384U);
      MW_SPI_Write_Databits(PMSM_to_BLDC_mod1_DW.obj_n.MW_SPI_HANDLE,
                            &PMSM_to_BLDC_mod1_B.BitwiseOR_e, 1U, 1, 1, 10U);
    }

    /* End of MATLABSystem: '<S18>/SPI Transmit' */
    /* MATLABSystem: '<S18>/SPI Receive' */
    data = MW_STM32_SPI_SetFormat(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, 2U,
      3840U, MW_SPI_MODE_3);
    if (data == 0) {
      MW_SPI_Read_Databits(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, &data, 1U, 1,
                           1, 1U);
      LL_GPIO_SetOutputPin(GPIOC, 16384U);
    }

    /* End of MATLABSystem: '<S18>/SPI Receive' */
    srUpdateBC(PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC);
  } else {
    PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S4>/Ctrl_Reg_1' */

  /* Outputs for Enabled SubSystem: '<S29>/Subsystem' incorporates:
   *  EnablePort: '<S31>/Enable'
   */
  if (PMSM_to_BLDC_mod1_B.spi_write1 > 0.0) {
    if (!PMSM_to_BLDC_mod1_DW.Subsystem_MODE_f) {
      /* SystemReset for Atomic SubSystem: '<S31>/Bit Shift' */
      PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_hq);

      /* End of SystemReset for SubSystem: '<S31>/Bit Shift' */

      /* SystemReset for Atomic SubSystem: '<S31>/Bit Shift1' */
      PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_p);

      /* End of SystemReset for SubSystem: '<S31>/Bit Shift1' */
      PMSM_to_BLDC_mod1_DW.Subsystem_MODE_f = true;
    }

    PMSM_to_BLDC_mod1_SPIReceive(&PMSM_to_BLDC_mod1_DW.SPIReceive_p);

    /* Outputs for Atomic SubSystem: '<S31>/Bit Shift' */
    /* Constant: '<S31>/Constant' */
    PMSM_to_BLDC_mod1_BitShift(1, &data, &PMSM_to_BLDC_mod1_DW.BitShift_hq);

    /* End of Outputs for SubSystem: '<S31>/Bit Shift' */

    /* Outputs for Atomic SubSystem: '<S31>/Bit Shift1' */
    /* Constant: '<S31>/Constant1' */
    PMSM_to_BLDC_mod1_BitShift1(2, &y_n, &PMSM_to_BLDC_mod1_DW.BitShift1_p);

    /* End of Outputs for SubSystem: '<S31>/Bit Shift1' */

    /* S-Function (sfix_bitop): '<S31>/Bitwise OR' */
    PMSM_to_BLDC_mod1_B.BitwiseOR_h = (uint16_T)(data | y_n |
      PMSM_to_BLDC_mod1_ConstB.BitwiseAND_d);
    PMSM_to_BLDC_mod1_SPITransmit(PMSM_to_BLDC_mod1_B.BitwiseOR_h,
      &PMSM_to_BLDC_mod1_DW.SPITransmit_p);
    srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i);
  } else {
    PMSM_to_BLDC_mod1_DW.Subsystem_MODE_f = false;
  }

  /* End of Outputs for SubSystem: '<S29>/Subsystem' */

  /* Outputs for Enabled SubSystem: '<S30>/Subsystem' incorporates:
   *  EnablePort: '<S37>/Enable'
   */
  if (PMSM_to_BLDC_mod1_B.spi_write3 > 0.0) {
    if (!PMSM_to_BLDC_mod1_DW.Subsystem_MODE) {
      /* SystemReset for Atomic SubSystem: '<S37>/Bit Shift' */
      PMSM_to_BLDC_mod_BitShift_Reset(&PMSM_to_BLDC_mod1_DW.BitShift_b);

      /* End of SystemReset for SubSystem: '<S37>/Bit Shift' */

      /* SystemReset for Atomic SubSystem: '<S37>/Bit Shift1' */
      PMSM_to_BLDC_mo_BitShift1_Reset(&PMSM_to_BLDC_mod1_DW.BitShift1_m);

      /* End of SystemReset for SubSystem: '<S37>/Bit Shift1' */
      PMSM_to_BLDC_mod1_DW.Subsystem_MODE = true;
    }

    PMSM_to_BLDC_mod1_SPIReceive(&PMSM_to_BLDC_mod1_DW.SPIReceive_pna);

    /* Outputs for Atomic SubSystem: '<S37>/Bit Shift' */
    /* Constant: '<S37>/Constant' */
    PMSM_to_BLDC_mod1_BitShift(1, &data, &PMSM_to_BLDC_mod1_DW.BitShift_b);

    /* End of Outputs for SubSystem: '<S37>/Bit Shift' */

    /* Outputs for Atomic SubSystem: '<S37>/Bit Shift1' */
    /* Constant: '<S37>/Constant1' */
    PMSM_to_BLDC_mod1_BitShift1(3, &y_n, &PMSM_to_BLDC_mod1_DW.BitShift1_m);

    /* End of Outputs for SubSystem: '<S37>/Bit Shift1' */

    /* S-Function (sfix_bitop): '<S37>/Bitwise OR' */
    PMSM_to_BLDC_mod1_B.BitwiseOR = (uint16_T)(data | y_n |
      PMSM_to_BLDC_mod1_ConstB.BitwiseAND);
    PMSM_to_BLDC_mod1_SPITransmit(PMSM_to_BLDC_mod1_B.BitwiseOR,
      &PMSM_to_BLDC_mod1_DW.SPITransmit_pna);
    srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC);
  } else {
    PMSM_to_BLDC_mod1_DW.Subsystem_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S30>/Subsystem' */
  /* Outputs for Enabled SubSystem: '<S29>/Subsystem1' incorporates:
   *  EnablePort: '<S32>/Ctrl_flag2'
   */
  if (PMSM_to_BLDC_mod1_B.spi_write2 > 0.0) {
    PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_m = true;
    PMSM_to_BLDC_mod1_SPIReceive_p(&PMSM_to_BLDC_mod1_B.SPIReceive_pn,
      &PMSM_to_BLDC_mod1_DW.SPIReceive_pn);

    /* Constant: '<S32>/Constant' */
    PMSM_to_BLDC_mod1_SPITransmit(36864, &PMSM_to_BLDC_mod1_DW.SPITransmit_pn);
    srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_n);
  } else if (PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_m) {
    /* Disable for Outport: '<S32>/Out1' incorporates:
     *  MATLABSystem: '<S32>/SPI Receive'
     */
    PMSM_to_BLDC_mod1_B.SPIReceive_pn.SPIReceive = 0U;
    PMSM_to_BLDC_mod1_DW.Subsystem1_MODE_m = false;
  }

  /* End of Outputs for SubSystem: '<S29>/Subsystem1' */

  /* Outputs for Enabled SubSystem: '<S30>/Subsystem1' incorporates:
   *  EnablePort: '<S38>/Enable'
   */
  if (PMSM_to_BLDC_mod1_B.spi_write4 > 0.0) {
    PMSM_to_BLDC_mod1_DW.Subsystem1_MODE = true;
    PMSM_to_BLDC_mod1_SPIReceive_p(&PMSM_to_BLDC_mod1_B.SPIReceive_pnae,
      &PMSM_to_BLDC_mod1_DW.SPIReceive_pnae);

    /* Constant: '<S38>/Constant' */
    PMSM_to_BLDC_mod1_SPITransmit(38912, &PMSM_to_BLDC_mod1_DW.SPITransmit_pnae);
    srUpdateBC(PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC);
  } else if (PMSM_to_BLDC_mod1_DW.Subsystem1_MODE) {
    /* Disable for MATLABSystem: '<S38>/SPI Receive' incorporates:
     *  Outport: '<S38>/Out1'
     */
    PMSM_to_BLDC_mod1_B.SPIReceive_pnae.SPIReceive = 0U;
    PMSM_to_BLDC_mod1_DW.Subsystem1_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S30>/Subsystem1' */
  /* RelationalOperator: '<S28>/Compare' incorporates:
   *  Constant: '<S28>/Constant'
   */
  PMSM_to_BLDC_mod1_B.Compare = (PMSM_to_BLDC_mod1_B.SPIReceive_pnae.SPIReceive ==
    6148);

  /* RelationalOperator: '<S27>/Compare' incorporates:
   *  Constant: '<S27>/Constant'
   */
  PMSM_to_BLDC_mod1_B.Compare_g = (PMSM_to_BLDC_mod1_B.SPIReceive_pn.SPIReceive ==
    5456);

  /* Update for Delay: '<Root>/Delay' */
  PMSM_to_BLDC_mod1_DW.Delay_DSTATE = PMSM_to_BLDC_mod1_B.Compare_g;

  /* Update for Delay: '<Root>/Delay1' */
  PMSM_to_BLDC_mod1_DW.Delay1_DSTATE = PMSM_to_BLDC_mod1_B.Compare;

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

  if (PMSM_to_BLDC_mod1_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.1s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((PMSM_to_BLDC_mod1_M->Timing.clockTick1) * 0.1);

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
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.1, which is the step size
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
  PMSM_to_BLDC_mod1_M->Sizes.checksums[0] = (4125489174U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[1] = (1600332196U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[2] = (2775076071U);
  PMSM_to_BLDC_mod1_M->Sizes.checksums[3] = (1220016116U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[41];
    PMSM_to_BLDC_mod1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_g;
    systemRan[3] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_g;
    systemRan[4] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_c;
    systemRan[5] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_c;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[8] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[9] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Control_Reg2_SubsysRanBC;
    systemRan[14] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[15] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[16] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[17] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[18] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[19] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[20] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Ctrl_Reg_1_SubsysRanBC;
    systemRan[21] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[22] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[23] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[24] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[25] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[26] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[27] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC_i;
    systemRan[28] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_n;
    systemRan[29] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_n;
    systemRan[30] = (sysRanDType *)
      &PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC_n;
    systemRan[31] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC;
    systemRan[32] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC;
    systemRan[33] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC;
    systemRan[34] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC;
    systemRan[35] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC;
    systemRan[36] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC;
    systemRan[37] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem_SubsysRanBC;
    systemRan[38] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC;
    systemRan[39] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC;
    systemRan[40] = (sysRanDType *)&PMSM_to_BLDC_mod1_DW.Subsystem1_SubsysRanBC;
    rteiSetModelMappingInfoPtr(PMSM_to_BLDC_mod1_M->extModeInfo,
      &PMSM_to_BLDC_mod1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PMSM_to_BLDC_mod1_M->extModeInfo,
                        PMSM_to_BLDC_mod1_M->Sizes.checksums);
    rteiSetTPtr(PMSM_to_BLDC_mod1_M->extModeInfo, rtmGetTPtr(PMSM_to_BLDC_mod1_M));
  }

  /* Start for MATLABSystem: '<S10>/Analog to Digital Converter' */
  PMSM_to_BLDC_mod1_DW.obj_d.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj_d.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_SystemCore_setup_o(&PMSM_to_BLDC_mod1_DW.obj_d);

  /* End of SystemInitialize for SubSystem: '<S2>/Subsystem' */
  /* Start for MATLABSystem: '<S13>/Analog to Digital Converter' */
  PMSM_to_BLDC_mod1_DW.obj_o.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted = false;
  PMSM_to_BLD_SystemCore_setup_ox(&PMSM_to_BLDC_mod1_DW.obj_o);

  /* End of SystemInitialize for SubSystem: '<S2>/Subsystem1' */
  /* SystemInitialize for Atomic SubSystem: '<S17>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift);

  /* End of SystemInitialize for SubSystem: '<S17>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S17>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1);

  /* End of SystemInitialize for SubSystem: '<S17>/Bit Shift1' */

  /* Start for MATLABSystem: '<S17>/SPI Receive' */
  PMSM_to_BLDC_mod1_DW.obj_g.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj_g.matlabCodegenIsDeleted = false;
  PMSM_to_BL_SystemCore_setup_oxg(&PMSM_to_BLDC_mod1_DW.obj_g);

  /* Start for MATLABSystem: '<S17>/SPI Transmit' */
  PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete = false;
  PMSM_to_BLDC_mod1_DW.obj_j.isInitialized = 1;
  PMSM_to_SPIDrvBlock_setupImpl_o(&PMSM_to_BLDC_mod1_DW.obj_j);
  PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<S4>/Control_Reg2' */
  /* SystemInitialize for Atomic SubSystem: '<S18>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_h);

  /* End of SystemInitialize for SubSystem: '<S18>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S18>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_d);

  /* End of SystemInitialize for SubSystem: '<S18>/Bit Shift1' */

  /* Start for MATLABSystem: '<S18>/SPI Transmit' */
  PMSM_to_BLDC_mod1_DW.obj_n.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_n.isSetupComplete = false;
  PMSM_to_BLDC_mod1_DW.obj_n.isInitialized = 1;
  PMSM_to_SPIDrvBlock_setupImpl_o(&PMSM_to_BLDC_mod1_DW.obj_n);
  PMSM_to_BLDC_mod1_DW.obj_n.isSetupComplete = true;

  /* Start for MATLABSystem: '<S18>/SPI Receive' */
  PMSM_to_BLDC_mod1_DW.obj.isInitialized = 0;
  PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = false;
  PMSM_to_B_SystemCore_setup_oxgk(&PMSM_to_BLDC_mod1_DW.obj);

  /* End of SystemInitialize for SubSystem: '<S4>/Ctrl_Reg_1' */
  /* SystemInitialize for Atomic SubSystem: '<S31>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_hq);

  /* End of SystemInitialize for SubSystem: '<S31>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S31>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_p);

  /* End of SystemInitialize for SubSystem: '<S31>/Bit Shift1' */
  PMSM_to_BLDC_mo_SPIReceive_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_p);
  PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_p);

  /* End of SystemInitialize for SubSystem: '<S29>/Subsystem' */

  /* SystemInitialize for Atomic SubSystem: '<S37>/Bit Shift' */
  PMSM_to_BLDC_mod1_BitShift_Init(&PMSM_to_BLDC_mod1_DW.BitShift_b);

  /* End of SystemInitialize for SubSystem: '<S37>/Bit Shift' */

  /* SystemInitialize for Atomic SubSystem: '<S37>/Bit Shift1' */
  PMSM_to_BLDC_mod_BitShift1_Init(&PMSM_to_BLDC_mod1_DW.BitShift1_m);

  /* End of SystemInitialize for SubSystem: '<S37>/Bit Shift1' */
  PMSM_to_BLDC_mo_SPIReceive_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pna);
  PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pna);

  /* End of SystemInitialize for SubSystem: '<S30>/Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S29>/Subsystem1' */
  PMSM_to_BLDC__SPIReceive_e_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pn);
  PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pn);

  /* End of SystemInitialize for SubSystem: '<S29>/Subsystem1' */

  /* SystemInitialize for Enabled SubSystem: '<S30>/Subsystem1' */
  PMSM_to_BLDC__SPIReceive_e_Init(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnae);
  PMSM_to_BLDC_m_SPITransmit_Init(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnae);

  /* End of SystemInitialize for SubSystem: '<S30>/Subsystem1' */

  /* Start for MATLABSystem: '<S16>/Digital Port Write' */
  PMSM_to_BLDC_mod1_DW.obj_ow.matlabCodegenIsDeleted = false;
  PMSM_to_BLDC_mod1_DW.obj_ow.isInitialized = 1;
  PMSM_to_BLDC_mod1_DW.obj_ow.isSetupComplete = true;
}

/* Model terminate function */
void PMSM_to_BLDC_mod1_terminate(void)
{
  uint32_T SPIPinsLoc;

  /* Terminate for Enabled SubSystem: '<S2>/Subsystem' */
  /* Terminate for MATLABSystem: '<S10>/Analog to Digital Converter' */
  if (!PMSM_to_BLDC_mod1_DW.obj_d.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_d.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_d.isSetupComplete) {
      ADC_Handle_Deinit(PMSM_to_BLDC_mod1_DW.obj_d.ADCHandle, ADC_NORMAL_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S10>/Analog to Digital Converter' */
  /* Terminate for Enabled SubSystem: '<S2>/Subsystem1' */
  /* Terminate for MATLABSystem: '<S13>/Analog to Digital Converter' */
  if (!PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_o.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_o.isSetupComplete) {
      ADC_Handle_Deinit(PMSM_to_BLDC_mod1_DW.obj_o.ADCHandle, ADC_NORMAL_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S13>/Analog to Digital Converter' */
  /* Terminate for MATLABSystem: '<S16>/Digital Port Write' */
  if (!PMSM_to_BLDC_mod1_DW.obj_ow.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_ow.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<S16>/Digital Port Write' */

  /* Terminate for Enabled SubSystem: '<S4>/Control_Reg2' */
  /* Terminate for MATLABSystem: '<S17>/SPI Receive' */
  if (!PMSM_to_BLDC_mod1_DW.obj_g.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_g.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_g.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_g.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S17>/SPI Receive' */
  /* Terminate for MATLABSystem: '<S17>/SPI Transmit' */
  if (!PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_j.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_j.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_j.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S17>/SPI Transmit' */
  /* Terminate for Enabled SubSystem: '<S4>/Ctrl_Reg_1' */
  /* Terminate for MATLABSystem: '<S18>/SPI Transmit' */
  if (!PMSM_to_BLDC_mod1_DW.obj_n.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj_n.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj_n.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj_n.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S18>/SPI Transmit' */
  /* Terminate for MATLABSystem: '<S18>/SPI Receive' */
  if (!PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted) {
    PMSM_to_BLDC_mod1_DW.obj.matlabCodegenIsDeleted = true;
    if ((PMSM_to_BLDC_mod1_DW.obj.isInitialized == 1) &&
        PMSM_to_BLDC_mod1_DW.obj.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(PMSM_to_BLDC_mod1_DW.obj.MW_SPI_HANDLE, SPIPinsLoc,
                   SPIPinsLoc, SPIPinsLoc, 14U);
    }
  }

  /* End of Terminate for MATLABSystem: '<S18>/SPI Receive' */
  /* End of Terminate for SubSystem: '<S4>/Ctrl_Reg_1' */

  /* Terminate for Enabled SubSystem: '<S29>/Subsystem' */
  PMSM_to_BLDC_mo_SPIReceive_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_p);
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_p);

  /* Terminate for Enabled SubSystem: '<S30>/Subsystem' */
  PMSM_to_BLDC_mo_SPIReceive_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pna);
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pna);

  /* Terminate for Enabled SubSystem: '<S29>/Subsystem1' */
  PMSM_to_BLDC__SPIReceive_m_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pn);
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pn);

  /* End of Terminate for SubSystem: '<S29>/Subsystem1' */

  /* Terminate for Enabled SubSystem: '<S30>/Subsystem1' */
  PMSM_to_BLDC__SPIReceive_m_Term(&PMSM_to_BLDC_mod1_DW.SPIReceive_pnae);
  PMSM_to_BLDC_m_SPITransmit_Term(&PMSM_to_BLDC_mod1_DW.SPITransmit_pnae);

  /* End of Terminate for SubSystem: '<S30>/Subsystem1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
