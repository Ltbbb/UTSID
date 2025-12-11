/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * imfilter.h
 *
 * Code generation for function 'imfilter'
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
void imfilter(lee_regionStackData *SD, const emlrtStack *sp,
              const uint8_T varargin_1[220320],
              const emxArray_real_T *varargin_2, uint8_T b[220320]);

/* End of code generation (imfilter.h) */
