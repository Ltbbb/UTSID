/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * diag.c
 *
 * Code generation for function 'diag'
 *
 */

/* Include files */
#include "diag.h"
#include "lee_region_emxutil.h"
#include "lee_region_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRTEInfo g_emlrtRTEI = {
    103,    /* lineNo */
    19,     /* colNo */
    "diag", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\elmat\\diag.m" /* pName
                                                                       */
};

static emlrtRTEInfo vb_emlrtRTEI = {
    101,    /* lineNo */
    5,      /* colNo */
    "diag", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\elmat\\diag.m" /* pName
                                                                       */
};

static emlrtRTEInfo wb_emlrtRTEI = {
    110,    /* lineNo */
    24,     /* colNo */
    "diag", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\elmat\\diag.m" /* pName
                                                                       */
};

/* Function Definitions */
void diag(const emlrtStack *sp, const emxArray_real_T *v, emxArray_real_T *d)
{
  const real_T *v_data;
  real_T *d_data;
  int32_T k;
  v_data = v->data;
  if ((v->size[0] == 1) && (v->size[1] == 1)) {
    int32_T m;
    m = d->size[0];
    d->size[0] = 1;
    emxEnsureCapacity_real_T(sp, d, m, &vb_emlrtRTEI);
    d_data = d->data;
    d_data[0] = v_data[0];
  } else {
    int32_T m;
    int32_T n;
    if ((v->size[0] == 1) || (v->size[1] == 1)) {
      emlrtErrorWithMessageIdR2018a(
          sp, &g_emlrtRTEI, "Coder:toolbox:diag_varsizedMatrixVector",
          "Coder:toolbox:diag_varsizedMatrixVector", 0);
    }
    m = v->size[0];
    n = v->size[1];
    if (v->size[1] > 0) {
      n = muIntScalarMin_sint32(m, n);
    } else {
      n = 0;
    }
    m = d->size[0];
    d->size[0] = n;
    emxEnsureCapacity_real_T(sp, d, m, &wb_emlrtRTEI);
    d_data = d->data;
    for (k = 0; k < n; k++) {
      d_data[k] = v_data[k + v->size[0] * k];
    }
  }
}

/* End of code generation (diag.c) */
