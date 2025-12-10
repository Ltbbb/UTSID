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
#include "lee_region_initialize.h"
#include "lee_region_types.h"
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void lee_region(const unsigned char img[220320], double mask_h, double mask_w,
                double region[220320])
{
  static unsigned char img_filt[220320];
  emxArray_real_T *mask;
  double d;
  double *mask_data;
  int idx[648];
  int y_up[648];
  int b_i;
  int b_loop_ub;
  int i;
  int i1;
  int loop_ub;
  unsigned char b_img_filt[110160];
  unsigned char ex[648];
  if (!isInitialized_lee_region) {
    lee_region_initialize();
  }
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
  emxInit_real_T(&mask, 2);
  loop_ub = mask->size[0] * mask->size[1];
  mask->size[0] = (int)mask_h;
  b_loop_ub = (int)mask_w;
  mask->size[1] = (int)mask_w;
  emxEnsureCapacity_real_T(mask, loop_ub);
  mask_data = mask->data;
  loop_ub = (int)mask_h * (int)mask_w;
  for (i = 0; i < loop_ub; i++) {
    mask_data[i] = 0.0;
  }
  d = mask_h / 2.0;
  if (d < 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = (int)d;
  }
  for (i = 0; i < b_loop_ub; i++) {
    for (b_i = 0; b_i < loop_ub; b_i++) {
      mask_data[b_i + mask->size[0] * i] = -1.0;
    }
  }
  if (d + 1.0 > mask->size[0]) {
    i1 = 0;
    loop_ub = 0;
  } else {
    i1 = (int)(d + 1.0) - 1;
    loop_ub = (int)mask_h;
  }
  loop_ub -= i1;
  for (i = 0; i < b_loop_ub; i++) {
    for (b_i = 0; b_i < loop_ub; b_i++) {
      mask_data[(i1 + b_i) + mask->size[0] * i] = 1.0;
    }
  }
  /*  Filter image using mask */
  imfilter(img, mask, img_filt);
  emxFree_real_T(&mask);
  /* figure; imshow(img_filt,[]) */
  /*  Upper part of filtred image */
  for (i = 0; i < 648; i++) {
    memcpy(&b_img_filt[i * 170], &img_filt[i * 340],
           170U * sizeof(unsigned char));
  }
  maximum(b_img_filt, ex, idx);
  /*  Lower part of filtred image */
  for (i = 0; i < 648; i++) {
    y_up[i] = idx[i];
    memcpy(&b_img_filt[i * 170], &img_filt[i * 340 + 170],
           170U * sizeof(unsigned char));
  }
  minimum(b_img_filt, ex, idx);
  /*  Fill region between upper and lower edges */
  memset(&region[0], 0, 220320U * sizeof(double));
  for (i = 0; i < 648; i++) {
    loop_ub = idx[i] - y_up[i];
    for (b_i = 0; b_i <= loop_ub + 170; b_i++) {
      region[((y_up[i] + b_i) + 340 * i) - 1] = 1.0;
    }
  }
  /*  Save y-position of finger edges */
}

/* End of code generation (lee_region.c) */
