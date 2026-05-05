/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'PMSM_to_BLDC_mod1'.
 *
 * Model version                  : 4.884
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Tue May  5 18:45:38 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PMSM_to_BLDC_mod1.h"
#include "rtwtypes.h"
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

  __enable_irq();
  PMSM_to_BLDC_mod1_step();

  /* Get model outputs here */
  __disable_irq();
  OverrunFlag--;
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(int argc, char **argv)
{
  float modelBaseRate = 0.0001;
  float systemClock = 144.0;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;

#if !defined(MW_FREERTOS) && defined(MW_MULTI_TASKING_MODE) && (MW_MULTI_TASKING_MODE == 1)

  MW_ASM (" SVC #1");

#endif

  ;

  // Start Peripheral initialization imported from STM32CubeMX project;
  HAL_Init();
  SystemClock_Config();
  PeriphCommonClock_Config();
  MX_DMA_Init();
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_USART2_UART_Init();
  MX_ADC2_Init();
  MX_TIM8_Init();
  MX_ADC3_Init();
  MX_SPI3_Init();

  // End Peripheral initialization imported from STM32CubeMX project;
  rtmSetErrorStatus(PMSM_to_BLDC_mod1_M, 0);
  PMSM_to_BLDC_mod1_initialize();
  __disable_irq();
  ARMCM_SysTick_Config(modelBaseRate);
  runModel =
    rtmGetErrorStatus(PMSM_to_BLDC_mod1_M) == (NULL)&& !rtmGetStopRequested
    (PMSM_to_BLDC_mod1_M);
  __enable_irq();
  __enable_irq();
  while (runModel) {
    stopRequested = !(
                      rtmGetErrorStatus(PMSM_to_BLDC_mod1_M) == (NULL)&&
                      !rtmGetStopRequested(PMSM_to_BLDC_mod1_M));
    if (stopRequested) {
      SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    }

    ;
  }

  /* Terminate model */
  PMSM_to_BLDC_mod1_terminate();

#if !defined(MW_FREERTOS) && !defined(USE_RTX)

  (void) systemClock;

#endif

  ;
  __disable_irq();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
