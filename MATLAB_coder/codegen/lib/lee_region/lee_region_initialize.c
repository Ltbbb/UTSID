/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * lee_region_initialize.c
 *
 * Code generation for function 'lee_region_initialize'
 *
 */

/* Include files */
#include "lee_region_initialize.h"
#include "lee_region_data.h"
#include "rt_nonfinite.h"
#include "omp.h"

/* Function Definitions */
void lee_region_initialize(void)
{
  omp_init_nest_lock(&lee_region_nestLockGlobal);
  isInitialized_lee_region = true;
}

/* End of code generation (lee_region_initialize.c) */
