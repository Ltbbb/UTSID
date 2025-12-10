/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * lee_region_initialize.c
 *
 * Code generation for function 'lee_region_initialize'
 *
 */

/* Include files */
#include "lee_region_initialize.h"
#include "_coder_lee_region_mex.h"
#include "lee_region_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void lee_region_once(void);

/* Function Definitions */
static void lee_region_once(void)
{
  mex_InitInfAndNan();
}

void lee_region_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtLicenseCheckR2022a(&st, "EMLRT:runTime:MexFunctionNeedsLicense",
                          "image_toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    lee_region_once();
  }
}

/* End of code generation (lee_region_initialize.c) */
