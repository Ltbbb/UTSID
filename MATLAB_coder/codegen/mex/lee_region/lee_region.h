/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * lee_region.h
 *
 * Code generation for function 'lee_region'
 *
 */

#pragma once

/* Include files */
#include "lee_region_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void lee_region(lee_regionStackData *SD, const emlrtStack *sp,
                const uint8_T img[220320], real_T mask_h, real_T mask_w,
                real_T region[220320]);

/* End of code generation (lee_region.h) */
