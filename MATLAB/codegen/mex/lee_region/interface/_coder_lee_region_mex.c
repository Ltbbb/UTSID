/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_lee_region_mex.c
 *
 * Code generation for function '_coder_lee_region_mex'
 *
 */

/* Include files */
#include "_coder_lee_region_mex.h"
#include "_coder_lee_region_api.h"
#include "lee_region_data.h"
#include "lee_region_initialize.h"
#include "lee_region_terminate.h"
#include "lee_region_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void lee_region_mexFunction(lee_regionStackData *SD, int32_T nlhs,
                            mxArray *plhs[1], int32_T nrhs,
                            const mxArray *prhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        10, "lee_region");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 10,
                        "lee_region");
  }
  /* Call the function. */
  lee_region_api(SD, prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  lee_regionStackData *lee_regionStackDataGlobal = NULL;
  lee_regionStackDataGlobal = (lee_regionStackData *)emlrtMxCalloc(
      (size_t)1, (size_t)1U * sizeof(lee_regionStackData));
  mexAtExit(&lee_region_atexit);
  lee_region_initialize();
  lee_region_mexFunction(lee_regionStackDataGlobal, nlhs, plhs, nrhs, prhs);
  lee_region_terminate();
  emlrtMxFree(lee_regionStackDataGlobal);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, "windows-1252", true);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_lee_region_mex.c) */
