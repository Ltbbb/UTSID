/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * svd.c
 *
 * Code generation for function 'svd'
 *
 */

/* Include files */
#include "svd.h"
#include "lee_region_emxutil.h"
#include "lee_region_types.h"
#include "rt_nonfinite.h"
#include "xzsvdc.h"

/* Function Definitions */
void svd(const emxArray_real_T *A, emxArray_real_T *U, emxArray_real_T *S,
         emxArray_real_T *V)
{
  emxArray_real_T *b_A;
  emxArray_real_T *s;
  const double *A_data;
  double *U_data;
  double *s_data;
  int b_i;
  int loop_ub;
  A_data = A->data;
  emxInit_real_T(&s, 1);
  s_data = s->data;
  if ((A->size[0] == 0) || (A->size[1] == 0)) {
    int i;
    int m;
    m = A->size[1];
    i = A->size[0];
    loop_ub = U->size[0] * U->size[1];
    U->size[0] = A->size[0];
    U->size[1] = A->size[0];
    emxEnsureCapacity_real_T(U, loop_ub);
    U_data = U->data;
    loop_ub = A->size[0] * A->size[0];
    for (b_i = 0; b_i < loop_ub; b_i++) {
      U_data[b_i] = 0.0;
    }
    for (b_i = 0; b_i < i; b_i++) {
      U_data[b_i + U->size[0] * b_i] = 1.0;
    }
    loop_ub = V->size[0] * V->size[1];
    V->size[0] = A->size[1];
    V->size[1] = A->size[1];
    emxEnsureCapacity_real_T(V, loop_ub);
    U_data = V->data;
    loop_ub = A->size[1] * A->size[1];
    for (b_i = 0; b_i < loop_ub; b_i++) {
      U_data[b_i] = 0.0;
    }
    if (A->size[1] > 0) {
      for (b_i = 0; b_i < m; b_i++) {
        U_data[b_i + V->size[0] * b_i] = 1.0;
      }
    }
    s->size[0] = 0;
  } else {
    emxInit_real_T(&b_A, 2);
    loop_ub = b_A->size[0] * b_A->size[1];
    b_A->size[0] = A->size[0];
    b_A->size[1] = A->size[1];
    emxEnsureCapacity_real_T(b_A, loop_ub);
    U_data = b_A->data;
    loop_ub = A->size[0] * A->size[1] - 1;
    for (b_i = 0; b_i <= loop_ub; b_i++) {
      U_data[b_i] = A_data[b_i];
    }
    xzsvdc(b_A, U, s, V);
    s_data = s->data;
    emxFree_real_T(&b_A);
  }
  loop_ub = S->size[0] * S->size[1];
  S->size[0] = U->size[1];
  S->size[1] = V->size[1];
  emxEnsureCapacity_real_T(S, loop_ub);
  U_data = S->data;
  loop_ub = U->size[1] * V->size[1];
  for (b_i = 0; b_i < loop_ub; b_i++) {
    U_data[b_i] = 0.0;
  }
  loop_ub = s->size[0];
  for (b_i = 0; b_i < loop_ub; b_i++) {
    U_data[b_i + S->size[0] * b_i] = s_data[b_i];
  }
  emxFree_real_T(&s);
}

/* End of code generation (svd.c) */
