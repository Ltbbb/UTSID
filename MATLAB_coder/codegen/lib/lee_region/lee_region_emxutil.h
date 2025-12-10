/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * lee_region_emxutil.h
 *
 * Code generation for function 'lee_region_emxutil'
 *
 */

#ifndef LEE_REGION_EMXUTIL_H
#define LEE_REGION_EMXUTIL_H

/* Include files */
#include "lee_region_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void emxEnsureCapacity_boolean_T(emxArray_boolean_T *emxArray,
                                        int oldNumel);

extern void emxEnsureCapacity_int16_T(emxArray_int16_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);

extern void emxEnsureCapacity_uint8_T(emxArray_uint8_T *emxArray, int oldNumel);

extern void emxFree_boolean_T(emxArray_boolean_T **pEmxArray);

extern void emxFree_int16_T(emxArray_int16_T **pEmxArray);

extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);

extern void emxFree_real_T(emxArray_real_T **pEmxArray);

extern void emxFree_uint8_T(emxArray_uint8_T **pEmxArray);

extern void emxInit_boolean_T(emxArray_boolean_T **pEmxArray,
                              int numDimensions);

extern void emxInit_int16_T(emxArray_int16_T **pEmxArray);

extern void emxInit_int32_T(emxArray_int32_T **pEmxArray);

extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

extern void emxInit_uint8_T(emxArray_uint8_T **pEmxArray);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (lee_region_emxutil.h) */
