/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_lee_region_api.h
 *
 * Code generation for function 'lee_region'
 *
 */

#ifndef _CODER_LEE_REGION_API_H
#define _CODER_LEE_REGION_API_H

/* Include files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void lee_region(uint8_T img[220320], real_T mask_h, real_T mask_w,
                real_T region[220320]);

void lee_region_api(const mxArray *const prhs[3], const mxArray **plhs);

void lee_region_atexit(void);

void lee_region_initialize(void);

void lee_region_terminate(void);

void lee_region_xil_shutdown(void);

void lee_region_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_lee_region_api.h) */
