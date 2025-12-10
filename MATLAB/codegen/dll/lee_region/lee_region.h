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

#ifndef LEE_REGION_H
#define LEE_REGION_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void lee_region(const unsigned char img[220320], double mask_h,
                       double mask_w, double region[220320]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (lee_region.h) */
