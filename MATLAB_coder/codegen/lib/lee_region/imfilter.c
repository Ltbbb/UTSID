/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * imfilter.c
 *
 * Code generation for function 'imfilter'
 *
 */

/* Include files */
#include "imfilter.h"
#include "lee_region_emxutil.h"
#include "lee_region_types.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"
#include "omp.h"
#include "rt_nonfinite.h"
#include <emmintrin.h>
#include <math.h>
#include <string.h>

/* Function Declarations */
static void padImage(const unsigned char a_tmp[220320], const double pad[2],
                     emxArray_uint8_T *a);

static double rt_roundd_snf(double u);

/* Function Definitions */
static void padImage(const unsigned char a_tmp[220320], const double pad[2],
                     emxArray_uint8_T *a)
{
  __m128i r;
  emxArray_int16_T *idxA;
  emxArray_int16_T *idxDir;
  double dv[2];
  double varargin_1[2];
  double d;
  double maxval;
  int b_i;
  int i;
  int j;
  int loop_ub;
  int unnamed_idx_1;
  short iv[8];
  short *idxA_data;
  short *idxDir_data;
  unsigned char *a_data;
  maxval = 2.0 * pad[0];
  d = 2.0 * pad[1];
  if ((maxval + 340.0 < d + 648.0) ||
      (rtIsNaN(maxval + 340.0) && (!rtIsNaN(d + 648.0)))) {
    maxval = d + 648.0;
  } else {
    maxval += 340.0;
  }
  emxInit_int16_T(&idxA);
  loop_ub = idxA->size[0] * idxA->size[1];
  idxA->size[0] = (int)maxval;
  idxA->size[1] = 2;
  emxEnsureCapacity_int16_T(idxA, loop_ub);
  idxA_data = idxA->data;
  unnamed_idx_1 = (int)pad[0];
  emxInit_int16_T(&idxDir);
  loop_ub = idxDir->size[0] * idxDir->size[1];
  idxDir->size[0] = 1;
  idxDir->size[1] = ((int)pad[0] + (int)pad[0]) + 340;
  emxEnsureCapacity_int16_T(idxDir, loop_ub);
  idxDir_data = idxDir->data;
  for (j = 0; j < unnamed_idx_1; j++) {
    idxDir_data[j] = 1;
  }
  for (j = 0; j <= 328; j += 8) {
    iv[0] = (short)j;
    iv[1] = (short)(j + 1);
    iv[2] = (short)(j + 2);
    iv[3] = (short)(j + 3);
    iv[4] = (short)(j + 4);
    iv[5] = (short)(j + 5);
    iv[6] = (short)(j + 6);
    iv[7] = (short)(j + 7);
    r = _mm_loadu_si128((const __m128i *)&iv[0]);
    _mm_storeu_si128((__m128i *)&idxDir_data[j + unnamed_idx_1],
                     _mm_add_epi16(_mm_set1_epi16(1), r));
  }
  idxDir_data[(int)pad[0] + 336] = 337;
  idxDir_data[(int)pad[0] + 337] = 338;
  idxDir_data[(int)pad[0] + 338] = 339;
  idxDir_data[(int)pad[0] + 339] = 340;
  for (j = 0; j < unnamed_idx_1; j++) {
    idxDir_data[(j + unnamed_idx_1) + 340] = 340;
  }
  loop_ub = idxDir->size[1];
  for (j = 0; j < loop_ub; j++) {
    idxA_data[j] = idxDir_data[j];
  }
  unnamed_idx_1 = (int)pad[1];
  loop_ub = idxDir->size[0] * idxDir->size[1];
  idxDir->size[0] = 1;
  idxDir->size[1] = ((int)pad[1] + (int)pad[1]) + 648;
  emxEnsureCapacity_int16_T(idxDir, loop_ub);
  idxDir_data = idxDir->data;
  for (j = 0; j < unnamed_idx_1; j++) {
    idxDir_data[j] = 1;
  }
  for (j = 0; j <= 640; j += 8) {
    iv[0] = (short)j;
    iv[1] = (short)(j + 1);
    iv[2] = (short)(j + 2);
    iv[3] = (short)(j + 3);
    iv[4] = (short)(j + 4);
    iv[5] = (short)(j + 5);
    iv[6] = (short)(j + 6);
    iv[7] = (short)(j + 7);
    r = _mm_loadu_si128((const __m128i *)&iv[0]);
    _mm_storeu_si128((__m128i *)&idxDir_data[j + unnamed_idx_1],
                     _mm_add_epi16(_mm_set1_epi16(1), r));
  }
  for (j = 0; j < unnamed_idx_1; j++) {
    idxDir_data[(j + unnamed_idx_1) + 648] = 648;
  }
  loop_ub = idxDir->size[1];
  for (j = 0; j < loop_ub; j++) {
    idxA_data[j + idxA->size[0]] = idxDir_data[j];
  }
  __m128d r1;
  emxFree_int16_T(&idxDir);
  dv[0] = 0.0;
  dv[1] = 1.0;
  r1 = _mm_loadu_pd(&dv[0]);
  _mm_storeu_pd(&varargin_1[0],
                _mm_add_pd(_mm_mul_pd(_mm_set1_pd(2.0), _mm_loadu_pd(&pad[0])),
                           _mm_add_pd(_mm_set1_pd(340.0),
                                      _mm_mul_pd(_mm_set1_pd(308.0), r1))));
  unnamed_idx_1 = (int)varargin_1[0];
  loop_ub = a->size[0] * a->size[1];
  a->size[0] = (int)varargin_1[0];
  i = (int)varargin_1[1];
  a->size[1] = (int)varargin_1[1];
  emxEnsureCapacity_uint8_T(a, loop_ub);
  a_data = a->data;
  for (j = 0; j < i; j++) {
    for (b_i = 0; b_i < unnamed_idx_1; b_i++) {
      a_data[b_i + a->size[0] * j] =
          a_tmp[(idxA_data[b_i] + 340 * (idxA_data[j + idxA->size[0]] - 1)) -
                1];
    }
  }
  emxFree_int16_T(&idxA);
}

static double rt_roundd_snf(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }
  return y;
}

void imfilter(const unsigned char varargin_1[220320],
              const emxArray_real_T *varargin_2, unsigned char b[220320])
{
  static double bTmp[220320];
  emxArray_boolean_T *b_conn;
  emxArray_boolean_T *conn;
  emxArray_int32_T *r1;
  emxArray_int32_T *r3;
  emxArray_real_T *a;
  emxArray_real_T *a__2;
  emxArray_real_T *b_bTmp;
  emxArray_real_T *b_s;
  emxArray_real_T *hcol;
  emxArray_real_T *hrow;
  emxArray_real_T *s;
  emxArray_uint8_T *aTmp;
  double startT[2];
  const double *varargin_2_data;
  double *a__2_data;
  double *a_data;
  double *bTmp_data;
  double *hcol_data;
  double *hrow_data;
  double *s_data;
  int i;
  int i1;
  int i2;
  int i3;
  int k;
  int *r2;
  unsigned char *aTmp_data;
  boolean_T *conn_data;
  varargin_2_data = varargin_2->data;
  startT[0] = (double)varargin_2->size[0] -
              floor(((double)varargin_2->size[0] + 1.0) / 2.0);
  startT[1] = (double)varargin_2->size[1] -
              floor(((double)varargin_2->size[1] + 1.0) / 2.0);
  if ((varargin_2->size[0] == 0) || (varargin_2->size[1] == 0)) {
    memset(&b[0], 0, 220320U * sizeof(unsigned char));
  } else {
    double tol;
    int idx;
    int last;
    int loop_ub;
    int nz;
    boolean_T tooBig;
    loop_ub = varargin_2->size[0] * varargin_2->size[1];
    emxInit_real_T(&a, 2);
    emxInit_real_T(&a__2, 2);
    emxInit_real_T(&s, 2);
    emxInit_real_T(&b_s, 1);
    emxInit_boolean_T(&conn, 1);
    if (loop_ub >= 289) {
      boolean_T x[2];
      boolean_T exitg1;
      x[0] = (varargin_2->size[0] != 1);
      x[1] = (varargin_2->size[1] != 1);
      tooBig = true;
      nz = 0;
      exitg1 = false;
      while ((!exitg1) && (nz < 2)) {
        if (!x[nz]) {
          tooBig = false;
          exitg1 = true;
        } else {
          nz++;
        }
      }
      if (tooBig) {
        svd(varargin_2, a, s, a__2);
        bTmp_data = s->data;
        if ((s->size[0] == 1) && (s->size[1] == 1)) {
          nz = b_s->size[0];
          b_s->size[0] = 1;
          emxEnsureCapacity_real_T(b_s, nz);
          s_data = b_s->data;
          s_data[0] = bTmp_data[0];
        } else {
          nz = s->size[0];
          idx = s->size[1];
          if (nz <= idx) {
            idx = nz;
          }
          if (s->size[1] <= 0) {
            idx = 0;
          }
          nz = b_s->size[0];
          b_s->size[0] = idx;
          emxEnsureCapacity_real_T(b_s, nz);
          s_data = b_s->data;
          for (k = 0; k < idx; k++) {
            s_data[k] = bTmp_data[k + s->size[0] * k];
          }
        }
        last = b_s->size[0];
        if (b_s->size[0] <= 2) {
          if (b_s->size[0] == 1) {
            tol = s_data[0];
          } else {
            tol = s_data[b_s->size[0] - 1];
            if ((!(s_data[0] < tol)) &&
                ((!rtIsNaN(s_data[0])) || rtIsNaN(tol))) {
              tol = s_data[0];
            }
          }
        } else {
          if (!rtIsNaN(s_data[0])) {
            idx = 1;
          } else {
            idx = 0;
            nz = 2;
            exitg1 = false;
            while ((!exitg1) && (nz <= last)) {
              if (!rtIsNaN(s_data[nz - 1])) {
                idx = nz;
                exitg1 = true;
              } else {
                nz++;
              }
            }
          }
          if (idx == 0) {
            tol = s_data[0];
          } else {
            tol = s_data[idx - 1];
            nz = idx + 1;
            for (k = nz; k <= last; k++) {
              double d;
              d = s_data[k - 1];
              if (tol < d) {
                tol = d;
              }
            }
          }
        }
        nz = varargin_2->size[0];
        idx = varargin_2->size[1];
        if (nz >= idx) {
          idx = nz;
        }
        tol = (double)idx * tol * 2.2204460492503131E-16;
        nz = conn->size[0];
        conn->size[0] = b_s->size[0];
        emxEnsureCapacity_boolean_T(conn, nz);
        conn_data = conn->data;
        nz = b_s->size[0];
        if (b_s->size[0] < 1600) {
          for (i1 = 0; i1 < last; i1++) {
            conn_data[i1] = (s_data[i1] > tol);
          }
        } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

          for (i1 = 0; i1 < nz; i1++) {
            conn_data[i1] = (s_data[i1] > tol);
          }
        }
        nz = conn_data[0];
        for (k = 2; k <= last; k++) {
          nz += conn_data[k - 1];
        }
        tooBig = (nz == 1);
      } else {
        tooBig = false;
      }
    } else {
      tooBig = false;
    }
    emxInit_uint8_T(&aTmp);
    if (tooBig) {
      __m128d r;
      double connDimsT[2];
      double outSizeT[2];
      double padSizeT[2];
      double start[2];
      padImage(varargin_1, startT, aTmp);
      aTmp_data = aTmp->data;
      svd(varargin_2, a, s, a__2);
      a__2_data = a__2->data;
      bTmp_data = s->data;
      a_data = a->data;
      if ((s->size[0] == 1) && (s->size[1] == 1)) {
        nz = b_s->size[0];
        b_s->size[0] = 1;
        emxEnsureCapacity_real_T(b_s, nz);
        s_data = b_s->data;
        s_data[0] = bTmp_data[0];
      } else {
        nz = s->size[0];
        idx = s->size[1];
        if (nz <= idx) {
          idx = nz;
        }
        if (s->size[1] <= 0) {
          idx = 0;
        }
        nz = b_s->size[0];
        b_s->size[0] = idx;
        emxEnsureCapacity_real_T(b_s, nz);
        s_data = b_s->data;
        for (k = 0; k < idx; k++) {
          s_data[k] = bTmp_data[k + s->size[0] * k];
        }
      }
      tol = sqrt(s_data[0]);
      emxInit_real_T(&hcol, 1);
      last = a->size[0];
      nz = hcol->size[0];
      hcol->size[0] = a->size[0];
      emxEnsureCapacity_real_T(hcol, nz);
      hcol_data = hcol->data;
      idx = (a->size[0] / 2) << 1;
      nz = idx - 2;
      for (k = 0; k <= nz; k += 2) {
        r = _mm_loadu_pd(&a_data[k]);
        _mm_storeu_pd(&hcol_data[k], _mm_mul_pd(r, _mm_set1_pd(tol)));
      }
      for (k = idx; k < last; k++) {
        hcol_data[k] = a_data[k] * tol;
      }
      emxInit_real_T(&hrow, 2);
      nz = hrow->size[0] * hrow->size[1];
      hrow->size[0] = 1;
      last = a__2->size[0];
      hrow->size[1] = a__2->size[0];
      emxEnsureCapacity_real_T(hrow, nz);
      hrow_data = hrow->data;
      idx = (a__2->size[0] / 2) << 1;
      nz = idx - 2;
      for (k = 0; k <= nz; k += 2) {
        r = _mm_loadu_pd(&a__2_data[k]);
        _mm_storeu_pd(&hrow_data[k], _mm_mul_pd(r, _mm_set1_pd(tol)));
      }
      for (k = idx; k < last; k++) {
        hrow_data[k] = a__2_data[k] * tol;
      }
      nz = a->size[0] * a->size[1];
      a->size[0] = aTmp->size[0];
      a->size[1] = aTmp->size[1];
      emxEnsureCapacity_real_T(a, nz);
      a_data = a->data;
      nz = aTmp->size[0] * aTmp->size[1];
      for (k = 0; k < nz; k++) {
        a_data[k] = aTmp_data[k];
      }
      loop_ub = a->size[0];
      outSizeT[0] = a->size[0];
      outSizeT[1] = 648.0;
      start[0] = 0.0;
      start[1] = startT[1];
      emxInit_boolean_T(&b_conn, 2);
      nz = b_conn->size[0] * b_conn->size[1];
      b_conn->size[0] = 1;
      last = hrow->size[1];
      b_conn->size[1] = hrow->size[1];
      emxEnsureCapacity_boolean_T(b_conn, nz);
      conn_data = b_conn->data;
      idx = hrow->size[1];
      if (hrow->size[1] < 1600) {
        for (i2 = 0; i2 < last; i2++) {
          conn_data[i2] = (hrow_data[i2] != 0.0);
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (i2 = 0; i2 < idx; i2++) {
          conn_data[i2] = (hrow_data[i2] != 0.0);
        }
      }
      nz = 0;
      for (k = 0; k < last; k++) {
        if (conn_data[k]) {
          nz++;
        }
      }
      emxInit_int32_T(&r1);
      idx = r1->size[0];
      r1->size[0] = nz;
      emxEnsureCapacity_int32_T(r1, idx);
      r2 = r1->data;
      idx = 0;
      for (k = 0; k < last; k++) {
        if (conn_data[k]) {
          r2[idx] = k;
          idx++;
        }
      }
      idx = r1->size[0];
      nz = b_s->size[0];
      b_s->size[0] = r1->size[0];
      emxEnsureCapacity_real_T(b_s, nz);
      s_data = b_s->data;
      for (k = 0; k < idx; k++) {
        s_data[k] = hrow_data[r2[k]];
      }
      tooBig = true;
      for (k = 0; k < 2; k++) {
        if ((!tooBig) || ((int)outSizeT[k] <= 65500)) {
          tooBig = false;
        }
      }
      if (((double)r1->size[0] / (double)hrow->size[1] > 0.05) && (!tooBig)) {
        tooBig = true;
      } else {
        tooBig = false;
      }
      emxInit_real_T(&b_bTmp, 2);
      nz = b_bTmp->size[0] * b_bTmp->size[1];
      b_bTmp->size[0] = (int)outSizeT[0];
      b_bTmp->size[1] = 648;
      emxEnsureCapacity_real_T(b_bTmp, nz);
      bTmp_data = b_bTmp->data;
      if (tooBig) {
        padSizeT[0] = loop_ub;
        connDimsT[0] = 1.0;
        padSizeT[1] = a->size[1];
        connDimsT[1] = hrow->size[1];
        ippfilter_real64(&a_data[0], &bTmp_data[0], &outSizeT[0], 2.0,
                         &padSizeT[0], &hrow_data[0], &connDimsT[0], false);
      } else {
        padSizeT[0] = loop_ub;
        connDimsT[0] = 1.0;
        padSizeT[1] = a->size[1];
        connDimsT[1] = b_conn->size[1];
        imfilter_real64(&a_data[0], &bTmp_data[0], 2.0, &outSizeT[0], 2.0,
                        &padSizeT[0], &s_data[0], (double)r1->size[0],
                        &conn_data[0], 2.0, &connDimsT[0], &start[0], 2.0, true,
                        false);
      }
      emxFree_int32_T(&r1);
      emxFree_boolean_T(&b_conn);
      emxFree_real_T(&hrow);
      start[0] = startT[0];
      start[1] = 0.0;
      last = hcol->size[0];
      nz = conn->size[0];
      conn->size[0] = hcol->size[0];
      emxEnsureCapacity_boolean_T(conn, nz);
      conn_data = conn->data;
      nz = hcol->size[0];
      if (hcol->size[0] < 1600) {
        for (i3 = 0; i3 < last; i3++) {
          conn_data[i3] = (hcol_data[i3] != 0.0);
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (i3 = 0; i3 < nz; i3++) {
          conn_data[i3] = (hcol_data[i3] != 0.0);
        }
      }
      idx = 0;
      for (k = 0; k < last; k++) {
        if (conn_data[k]) {
          idx++;
        }
      }
      emxInit_int32_T(&r3);
      nz = r3->size[0];
      r3->size[0] = idx;
      emxEnsureCapacity_int32_T(r3, nz);
      r2 = r3->data;
      nz = 0;
      for (k = 0; k < last; k++) {
        if (conn_data[k]) {
          r2[nz] = k;
          nz++;
        }
      }
      idx = r3->size[0];
      nz = b_s->size[0];
      b_s->size[0] = r3->size[0];
      emxEnsureCapacity_real_T(b_s, nz);
      s_data = b_s->data;
      for (k = 0; k < idx; k++) {
        s_data[k] = hcol_data[r2[k]];
      }
      tooBig = ((double)r3->size[0] / (double)hcol->size[0] > 0.05);
      if (tooBig) {
        outSizeT[0] = 340.0;
        padSizeT[0] = b_bTmp->size[0];
        outSizeT[1] = 648.0;
        padSizeT[1] = 648.0;
        connDimsT[0] = hcol->size[0];
        connDimsT[1] = 1.0;
        ippfilter_real64(&bTmp_data[0], &bTmp[0], &outSizeT[0], 2.0,
                         &padSizeT[0], &hcol_data[0], &connDimsT[0], false);
      } else {
        outSizeT[0] = 340.0;
        padSizeT[0] = b_bTmp->size[0];
        outSizeT[1] = 648.0;
        padSizeT[1] = 648.0;
        connDimsT[0] = conn->size[0];
        connDimsT[1] = 1.0;
        imfilter_real64(&bTmp_data[0], &bTmp[0], 2.0, &outSizeT[0], 2.0,
                        &padSizeT[0], &s_data[0], (double)r3->size[0],
                        &conn_data[0], 2.0, &connDimsT[0], &start[0], 2.0, true,
                        false);
      }
      emxFree_int32_T(&r3);
      emxFree_real_T(&b_bTmp);
      emxFree_real_T(&hcol);
      for (k = 0; k < 220320; k++) {
        unsigned char u;
        tol = rt_roundd_snf(bTmp[k]);
        if (tol < 256.0) {
          if (tol >= 0.0) {
            u = (unsigned char)tol;
          } else {
            u = 0U;
          }
        } else if (tol >= 256.0) {
          u = MAX_uint8_T;
        } else {
          u = 0U;
        }
        b[k] = u;
      }
    } else {
      padImage(varargin_1, startT, aTmp);
      aTmp_data = aTmp->data;
      nz = a->size[0] * a->size[1];
      a->size[0] = aTmp->size[0];
      a->size[1] = aTmp->size[1];
      emxEnsureCapacity_real_T(a, nz);
      a_data = a->data;
      nz = aTmp->size[0] * aTmp->size[1];
      for (k = 0; k < nz; k++) {
        a_data[k] = aTmp_data[k];
      }
      emxInit_boolean_T(&b_conn, 2);
      nz = b_conn->size[0] * b_conn->size[1];
      b_conn->size[0] = varargin_2->size[0];
      b_conn->size[1] = varargin_2->size[1];
      emxEnsureCapacity_boolean_T(b_conn, nz);
      conn_data = b_conn->data;
      if (loop_ub < 1600) {
        for (i = 0; i < loop_ub; i++) {
          conn_data[i] = (varargin_2_data[i] != 0.0);
        }
      } else {
#pragma omp parallel for num_threads(omp_get_max_threads())

        for (i = 0; i < loop_ub; i++) {
          conn_data[i] = (varargin_2_data[i] != 0.0);
        }
      }
      tooBig = ((varargin_2->size[0] == 1) || (varargin_2->size[1] == 1));
      if (tooBig) {
        idx = 0;
        for (k = 0; k < loop_ub; k++) {
          if (conn_data[k]) {
            idx++;
          }
        }
        nz = b_s->size[0];
        b_s->size[0] = idx;
        emxEnsureCapacity_real_T(b_s, nz);
        s_data = b_s->data;
        nz = 0;
        for (k = 0; k < loop_ub; k++) {
          if (conn_data[k]) {
            s_data[nz] = varargin_2_data[k];
            nz++;
          }
        }
      } else {
        idx = 0;
        for (k = 0; k < loop_ub; k++) {
          if (conn_data[k]) {
            idx++;
          }
        }
        nz = b_s->size[0];
        b_s->size[0] = idx;
        emxEnsureCapacity_real_T(b_s, nz);
        s_data = b_s->data;
        nz = 0;
        for (k = 0; k < loop_ub; k++) {
          if (conn_data[k]) {
            s_data[nz] = varargin_2_data[k];
            nz++;
          }
        }
      }
      tooBig = ((double)b_s->size[0] / (double)loop_ub > 0.05);
      if (tooBig) {
        double connDimsT[2];
        double outSizeT[2];
        double padSizeT[2];
        outSizeT[0] = 340.0;
        padSizeT[0] = a->size[0];
        connDimsT[0] = varargin_2->size[0];
        outSizeT[1] = 648.0;
        padSizeT[1] = a->size[1];
        connDimsT[1] = varargin_2->size[1];
        ippfilter_real64(&a_data[0], &bTmp[0], &outSizeT[0], 2.0, &padSizeT[0],
                         &varargin_2_data[0], &connDimsT[0], false);
      } else {
        double connDimsT[2];
        double outSizeT[2];
        double padSizeT[2];
        outSizeT[0] = 340.0;
        padSizeT[0] = a->size[0];
        connDimsT[0] = b_conn->size[0];
        outSizeT[1] = 648.0;
        padSizeT[1] = a->size[1];
        connDimsT[1] = b_conn->size[1];
        imfilter_real64(&a_data[0], &bTmp[0], 2.0, &outSizeT[0], 2.0,
                        &padSizeT[0], &s_data[0], (double)b_s->size[0],
                        &conn_data[0], 2.0, &connDimsT[0], &startT[0], 2.0,
                        true, false);
      }
      emxFree_boolean_T(&b_conn);
      for (k = 0; k < 220320; k++) {
        unsigned char u;
        tol = rt_roundd_snf(bTmp[k]);
        if (tol < 256.0) {
          if (tol >= 0.0) {
            u = (unsigned char)tol;
          } else {
            u = 0U;
          }
        } else if (tol >= 256.0) {
          u = MAX_uint8_T;
        } else {
          u = 0U;
        }
        b[k] = u;
      }
    }
    emxFree_boolean_T(&conn);
    emxFree_real_T(&b_s);
    emxFree_real_T(&s);
    emxFree_real_T(&a__2);
    emxFree_real_T(&a);
    emxFree_uint8_T(&aTmp);
  }
}

/* End of code generation (imfilter.c) */
