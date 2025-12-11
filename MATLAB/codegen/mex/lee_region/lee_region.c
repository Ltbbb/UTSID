/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * lee_region.c
 *
 * Code generation for function 'lee_region'
 *
 */

/* Include files */
#include "lee_region.h"
#include "imfilter.h"
#include "lee_region_data.h"
#include "lee_region_emxutil.h"
#include "lee_region_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    42,           /* lineNo */
    "lee_region", /* fcnName */
    "C:\\Users\\Gebruiker\\OneDrive - University of Twente\\year 4\\Research "
    "Project\\UTSID_repo\\UTSID\\MATLAB\\lee_region.m" /* pathName */
};

static emlrtBCInfo emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    39,           /* lineNo */
    6,            /* colNo */
    "mask",       /* aName */
    "lee_region", /* fName */
    "C:\\Users\\Gebruiker\\OneDrive - University of Twente\\year 4\\Research "
    "Project\\UTSID_repo\\UTSID\\MATLAB\\lee_region.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    39,           /* lineNo */
    6,            /* colNo */
    "lee_region", /* fName */
    "C:\\Users\\Gebruiker\\OneDrive - University of Twente\\year 4\\Research "
    "Project\\UTSID_repo\\UTSID\\MATLAB\\lee_region.m", /* pName */
    1                                                   /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    38,           /* lineNo */
    8,            /* colNo */
    "mask",       /* aName */
    "lee_region", /* fName */
    "C:\\Users\\Gebruiker\\OneDrive - University of Twente\\year 4\\Research "
    "Project\\UTSID_repo\\UTSID\\MATLAB\\lee_region.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    38,           /* lineNo */
    8,            /* colNo */
    "lee_region", /* fName */
    "C:\\Users\\Gebruiker\\OneDrive - University of Twente\\year 4\\Research "
    "Project\\UTSID_repo\\UTSID\\MATLAB\\lee_region.m", /* pName */
    1                                                   /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    38,           /* lineNo */
    6,            /* colNo */
    "mask",       /* aName */
    "lee_region", /* fName */
    "C:\\Users\\Gebruiker\\OneDrive - University of Twente\\year 4\\Research "
    "Project\\UTSID_repo\\UTSID\\MATLAB\\lee_region.m", /* pName */
    0                                                   /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    37,           /* lineNo */
    21,           /* colNo */
    "lee_region", /* fName */
    "C:\\Users\\Gebruiker\\OneDrive - University of Twente\\year 4\\Research "
    "Project\\UTSID_repo\\UTSID\\MATLAB\\lee_region.m", /* pName */
    1                                                   /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    37,           /* lineNo */
    21,           /* colNo */
    "lee_region", /* fName */
    "C:\\Users\\Gebruiker\\OneDrive - University of Twente\\year 4\\Research "
    "Project\\UTSID_repo\\UTSID\\MATLAB\\lee_region.m", /* pName */
    4                                                   /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    37,           /* lineNo */
    14,           /* colNo */
    "lee_region", /* fName */
    "C:\\Users\\Gebruiker\\OneDrive - University of Twente\\year 4\\Research "
    "Project\\UTSID_repo\\UTSID\\MATLAB\\lee_region.m", /* pName */
    1                                                   /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    37,           /* lineNo */
    14,           /* colNo */
    "lee_region", /* fName */
    "C:\\Users\\Gebruiker\\OneDrive - University of Twente\\year 4\\Research "
    "Project\\UTSID_repo\\UTSID\\MATLAB\\lee_region.m", /* pName */
    4                                                   /* checkKind */
};

static emlrtRTEInfo m_emlrtRTEI = {
    37,           /* lineNo */
    1,            /* colNo */
    "lee_region", /* fName */
    "C:\\Users\\Gebruiker\\OneDrive - University of Twente\\year 4\\Research "
    "Project\\UTSID_repo\\UTSID\\MATLAB\\lee_region.m" /* pName */
};

/* Function Definitions */
void lee_region(lee_regionStackData *SD, const emlrtStack *sp,
                const uint8_T img[220320], real_T mask_h, real_T mask_w,
                real_T region[220320])
{
  emlrtStack st;
  emxArray_real_T *mask;
  real_T d;
  real_T *mask_data;
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T i;
  int32_T j;
  int32_T loop_ub;
  uint8_T idx[648];
  uint8_T y_up[648];
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*  Localise the finger region using Lee's method */
  /*  Parameters: */
  /*   img    - Input vascular image */
  /*   mask_h - Height of the mask */
  /*   mask_w - Width of the mask */
  /*  Returns: */
  /*   region - Binary mask indicating the finger region */
  /*   edges  - Matrix containing two rows, first row corresponds to the  */
  /*            y-positions of the upper finger edge and the second row */
  /*            corresponds to the y-positions of the lower finger edge. */
  /*  Reference: */
  /*  Finger vein recognition using minutia-based alignment and local binary */
  /*    pattern-based feature extraction */
  /*  E.C. Lee, H.C. Lee and K.R. Park */
  /*  International Journal of Imaging Systems and Technology */
  /*    Volume 19, Issue 3, September 2009, Pages 175-178    */
  /*  doi: 10.1002/ima.20193 */
  /*  Author:  Bram Ton <b.t.ton@alumnus.utwente.nl> */
  /*  Date:    20th March 2012 */
  /*  License: Simplified BSD License */
  /*  Determine lower half starting point */
  /*  Construct mask for filtering */
  if (!(mask_h >= 0.0)) {
    emlrtNonNegativeCheckR2012b(mask_h, &f_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (mask_h != (int32_T)muDoubleScalarFloor(mask_h)) {
    emlrtIntegerCheckR2012b(mask_h, &e_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (!(mask_w >= 0.0)) {
    emlrtNonNegativeCheckR2012b(mask_w, &d_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (mask_w != (int32_T)muDoubleScalarFloor(mask_w)) {
    emlrtIntegerCheckR2012b(mask_w, &c_emlrtDCI, (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &mask, 2, &m_emlrtRTEI);
  loop_ub = mask->size[0] * mask->size[1];
  mask->size[0] = (int32_T)mask_h;
  b_loop_ub = (int32_T)mask_w;
  mask->size[1] = (int32_T)mask_w;
  emxEnsureCapacity_real_T(sp, mask, loop_ub, &m_emlrtRTEI);
  mask_data = mask->data;
  loop_ub = (int32_T)mask_h * (int32_T)mask_w;
  for (i = 0; i < loop_ub; i++) {
    mask_data[i] = 0.0;
  }
  d = mask_h / 2.0;
  if (d < 1.0) {
    loop_ub = 0;
  } else {
    if ((int32_T)mask_h < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, (int32_T)mask_h, &c_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &b_emlrtDCI, (emlrtConstCTX)sp);
    }
    if (((int32_T)d < 1) || ((int32_T)d > (int32_T)mask_h)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, (int32_T)mask_h, &b_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub = (int32_T)d;
  }
  for (i = 0; i < b_loop_ub; i++) {
    for (j = 0; j < loop_ub; j++) {
      mask_data[j + mask->size[0] * i] = -1.0;
    }
  }
  if (d + 1.0 > mask->size[0]) {
    b_i = 0;
    loop_ub = 0;
  } else {
    if (d + 1.0 != muDoubleScalarFloor(d + 1.0)) {
      emlrtIntegerCheckR2012b(d + 1.0, &emlrtDCI, (emlrtConstCTX)sp);
    }
    if ((int32_T)(d + 1.0) > (int32_T)mask_h) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(d + 1.0), 1, (int32_T)mask_h,
                                    &emlrtBCI, (emlrtConstCTX)sp);
    }
    b_i = (int32_T)(d + 1.0) - 1;
    loop_ub = (int32_T)mask_h;
  }
  loop_ub -= b_i;
  for (i = 0; i < b_loop_ub; i++) {
    for (j = 0; j < loop_ub; j++) {
      mask_data[(b_i + j) + mask->size[0] * i] = 1.0;
    }
  }
  /*  Filter image using mask */
  st.site = &emlrtRSI;
  imfilter(SD, &st, img, mask, SD->f1.img_filt);
  emxFree_real_T(sp, &mask);
  /* figure; imshow(img_filt,[]) */
  /*  Upper part of filtred image */
  /*  Lower part of filtred image */
  for (j = 0; j < 648; j++) {
    uint8_T u;
    uint8_T u1;
    idx[j] = 1U;
    u = SD->f1.img_filt[340 * j];
    for (i = 0; i < 169; i++) {
      u1 = SD->f1.img_filt[(i + 340 * j) + 1];
      if (u < u1) {
        u = u1;
        idx[j] = (uint8_T)(i + 2);
      }
    }
    y_up[j] = idx[j];
    idx[j] = 1U;
    u = SD->f1.img_filt[340 * j + 170];
    for (i = 0; i < 169; i++) {
      u1 = SD->f1.img_filt[(i + 340 * j) + 171];
      if (u > u1) {
        u = u1;
        idx[j] = (uint8_T)(i + 2);
      }
    }
  }
  /*  Fill region between upper and lower edges */
  memset(&region[0], 0, 220320U * sizeof(real_T));
  for (i = 0; i < 648; i++) {
    loop_ub = idx[i] - y_up[i];
    for (j = 0; j <= loop_ub + 170; j++) {
      region[((y_up[i] + j) + 340 * i) - 1] = 1.0;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /*  Save y-position of finger edges */
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (lee_region.c) */
