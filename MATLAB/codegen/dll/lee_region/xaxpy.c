/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xaxpy.c
 *
 * Code generation for function 'xaxpy'
 *
 */

/* Include files */
#include "xaxpy.h"
#include "lee_region_types.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>

/* Function Definitions */
void b_xaxpy(int n, double a, const emxArray_real_T *x, int ix0,
             emxArray_real_T *y, int iy0)
{
  const double *x_data;
  double *y_data;
  int k;
  y_data = y->data;
  x_data = x->data;
  if ((n >= 1) && (!(a == 0.0))) {
    int scalarLB;
    int vectorUB;
    scalarLB = (n / 2) << 1;
    vectorUB = scalarLB - 2;
    for (k = 0; k <= vectorUB; k += 2) {
      __m128d r;
      int i;
      i = (iy0 + k) - 1;
      r = _mm_loadu_pd(&y_data[i]);
      _mm_storeu_pd(
          &y_data[i],
          _mm_add_pd(r, _mm_mul_pd(_mm_set1_pd(a),
                                   _mm_loadu_pd(&x_data[(ix0 + k) - 1]))));
    }
    for (k = scalarLB; k < n; k++) {
      vectorUB = (iy0 + k) - 1;
      y_data[vectorUB] += a * x_data[(ix0 + k) - 1];
    }
  }
}

void xaxpy(int n, double a, int ix0, emxArray_real_T *y, int iy0)
{
  double *y_data;
  int k;
  y_data = y->data;
  if ((n >= 1) && (!(a == 0.0))) {
    for (k = 0; k < n; k++) {
      int i;
      i = (iy0 + k) - 1;
      y_data[i] += a * y_data[(ix0 + k) - 1];
    }
  }
}

/* End of code generation (xaxpy.c) */
