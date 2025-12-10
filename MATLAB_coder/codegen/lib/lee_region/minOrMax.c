/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * minOrMax.c
 *
 * Code generation for function 'minOrMax'
 *
 */

/* Include files */
#include "minOrMax.h"
#include "rt_nonfinite.h"
#include "omp.h"

/* Function Definitions */
void maximum(const unsigned char x[110160], unsigned char ex[648], int idx[648])
{
  int i;
  int j;
  unsigned char u;
  unsigned char u1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(u, u1, i)

  for (j = 0; j < 648; j++) {
    idx[j] = 1;
    u1 = x[170 * j];
    for (i = 0; i < 169; i++) {
      u = x[(i + 170 * j) + 1];
      if (u1 < u) {
        u1 = u;
        idx[j] = i + 2;
      }
    }
    ex[j] = u1;
  }
}

void minimum(const unsigned char x[110160], unsigned char ex[648], int idx[648])
{
  int i;
  int j;
  unsigned char u;
  unsigned char u1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(u, u1, i)

  for (j = 0; j < 648; j++) {
    idx[j] = 1;
    u1 = x[170 * j];
    for (i = 0; i < 169; i++) {
      u = x[(i + 170 * j) + 1];
      if (u1 > u) {
        u1 = u;
        idx[j] = i + 2;
      }
    }
    ex[j] = u1;
  }
}

/* End of code generation (minOrMax.c) */
