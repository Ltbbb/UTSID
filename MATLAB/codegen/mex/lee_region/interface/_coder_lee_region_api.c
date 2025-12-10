/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_lee_region_api.c
 *
 * Code generation for function '_coder_lee_region_api'
 *
 */

/* Include files */
#include "_coder_lee_region_api.h"
#include "lee_region.h"
#include "lee_region_data.h"
#include "lee_region_types.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static uint8_T (
    *b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                        const emlrtMsgIdentifier *parentId))[220320];

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier);

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static uint8_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[220320];

static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                  const char_T *identifier))[220320];

static const mxArray *emlrt_marshallOut(real_T u[220320]);

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

/* Function Definitions */
static uint8_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId))[220320]
{
  uint8_T(*y)[220320];
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static uint8_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId))[220320]
{
  static const int32_T dims[2] = {340, 648};
  int32_T iv[2];
  uint8_T(*ret)[220320];
  boolean_T bv[2] = {false, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "uint8", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret = (uint8_T(*)[220320])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *nullptr,
                                  const char_T *identifier))[220320]
{
  emlrtMsgIdentifier thisId;
  uint8_T(*y)[220320];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(nullptr), &thisId);
  emlrtDestroyArray(&nullptr);
  return y;
}

static const mxArray *emlrt_marshallOut(real_T u[220320])
{
  static const int32_T iv[2] = {0, 0};
  static const int32_T iv1[2] = {340, 648};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void lee_region_api(lee_regionStackData *SD, const mxArray *const prhs[3],
                    const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*region)[220320];
  real_T mask_h;
  real_T mask_w;
  uint8_T(*img)[220320];
  st.tls = emlrtRootTLSGlobal;
  region = (real_T(*)[220320])mxMalloc(sizeof(real_T[220320]));
  /* Marshall function inputs */
  img = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "img");
  mask_h = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "mask_h");
  mask_w = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "mask_w");
  /* Invoke the target function */
  lee_region(SD, &st, *img, mask_h, mask_w, *region);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(*region);
}

/* End of code generation (_coder_lee_region_api.c) */
