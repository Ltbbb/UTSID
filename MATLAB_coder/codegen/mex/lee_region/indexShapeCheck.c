/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * indexShapeCheck.c
 *
 * Code generation for function 'indexShapeCheck'
 *
 */

/* Include files */
#include "indexShapeCheck.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo jc_emlrtRSI = {
    58,                /* lineNo */
    "indexShapeCheck", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\indexShapeCheck.m" /* pathName */
};

static emlrtRSInfo kc_emlrtRSI = {
    51,                /* lineNo */
    "indexShapeCheck", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\indexShapeCheck.m" /* pathName */
};

static emlrtRTEInfo k_emlrtRTEI = {
    122,           /* lineNo */
    5,             /* colNo */
    "errOrWarnIf", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\indexShapeCheck.m" /* pName */
};

/* Function Definitions */
void indexShapeCheck(const emlrtStack *sp, const int32_T matrixSize[2],
                     const int32_T indexSize[2])
{
  emlrtStack st;
  boolean_T nonSingletonDimFound;
  st.prev = sp;
  st.tls = sp->tls;
  nonSingletonDimFound = (matrixSize[0] != 1);
  if (matrixSize[1] != 1) {
    if (nonSingletonDimFound) {
      nonSingletonDimFound = false;
    } else {
      nonSingletonDimFound = true;
    }
  }
  if (nonSingletonDimFound) {
    if (matrixSize[0] == 1) {
      nonSingletonDimFound = true;
    } else {
      nonSingletonDimFound = false;
      if (matrixSize[1] != 1) {
        nonSingletonDimFound = true;
      }
    }
    st.site = &kc_emlrtRSI;
    if (nonSingletonDimFound) {
      emlrtErrorWithMessageIdR2018a(
          &st, &k_emlrtRTEI, "Coder:FE:PotentialMatrixMatrix_MM_Logical1",
          "Coder:FE:PotentialMatrixMatrix_MM_Logical1", 0);
    }
  } else {
    nonSingletonDimFound = (indexSize[0] != 1);
    if (indexSize[1] != 1) {
      if (nonSingletonDimFound) {
        nonSingletonDimFound = false;
      } else {
        nonSingletonDimFound = true;
      }
    }
    if (nonSingletonDimFound) {
      if (indexSize[0] == 1) {
        nonSingletonDimFound = true;
      } else {
        nonSingletonDimFound = false;
        if (indexSize[1] != 1) {
          nonSingletonDimFound = true;
        }
      }
      st.site = &jc_emlrtRSI;
      if (nonSingletonDimFound) {
        emlrtErrorWithMessageIdR2018a(
            &st, &k_emlrtRTEI, "Coder:FE:PotentialMatrixMatrix_MM_Logical2",
            "Coder:FE:PotentialMatrixMatrix_MM_Logical2", 0);
      }
    }
  }
}

/* End of code generation (indexShapeCheck.c) */
