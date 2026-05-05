/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: F4_uart_types.h
 *
 * Code generated for Simulink model 'F4_uart'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Tue May  5 17:40:40 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef F4_uart_types_h_
#define F4_uart_types_h_
#include "rtwtypes.h"
#ifndef struct_tag_Iq1q13TLZGLVDFrOgJGfXH
#define struct_tag_Iq1q13TLZGLVDFrOgJGfXH

struct tag_Iq1q13TLZGLVDFrOgJGfXH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  UART_Type_T* UARTHandle;
  uint8_T UARTInternalBuffer[128];
};

#endif                                 /* struct_tag_Iq1q13TLZGLVDFrOgJGfXH */

#ifndef typedef_stm32cube_blocks_UARTWrite_F4_T
#define typedef_stm32cube_blocks_UARTWrite_F4_T

typedef struct tag_Iq1q13TLZGLVDFrOgJGfXH stm32cube_blocks_UARTWrite_F4_T;

#endif                             /* typedef_stm32cube_blocks_UARTWrite_F4_T */

/* Forward declaration for rtModel */
typedef struct tag_RTM_F4_uart_T RT_MODEL_F4_uart_T;

#endif                                 /* F4_uart_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
