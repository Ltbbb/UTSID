/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzsvdc.c
 *
 * Code generation for function 'xzsvdc'
 *
 */

/* Include files */
#include "xzsvdc.h"
#include "lee_region_emxutil.h"
#include "lee_region_types.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xnrm2.h"
#include "xrotg.h"
#include <emmintrin.h>
#include <math.h>

/* Function Definitions */
void xzsvdc(emxArray_real_T *A, emxArray_real_T *U, emxArray_real_T *S,
            emxArray_real_T *V)
{
  emxArray_real_T *e;
  emxArray_real_T *s;
  emxArray_real_T *work;
  double b;
  double f;
  double scale;
  double sm;
  double sn;
  double sqds;
  double *A_data;
  double *U_data;
  double *V_data;
  double *e_data;
  double *s_data;
  double *work_data;
  int ii;
  int k;
  int minnp;
  int n;
  int ns;
  int p;
  int q;
  int qp1jj;
  A_data = A->data;
  n = A->size[0];
  p = A->size[1];
  qp1jj = A->size[0] + 1;
  ns = A->size[1];
  if (qp1jj <= ns) {
    ns = qp1jj;
  }
  qp1jj = A->size[0];
  minnp = A->size[1];
  if (qp1jj <= minnp) {
    minnp = qp1jj;
  }
  emxInit_real_T(&s, 1);
  qp1jj = s->size[0];
  s->size[0] = ns;
  emxEnsureCapacity_real_T(s, qp1jj);
  s_data = s->data;
  for (ii = 0; ii < ns; ii++) {
    s_data[ii] = 0.0;
  }
  emxInit_real_T(&e, 1);
  qp1jj = e->size[0];
  e->size[0] = A->size[1];
  emxEnsureCapacity_real_T(e, qp1jj);
  e_data = e->data;
  for (ii = 0; ii < p; ii++) {
    e_data[ii] = 0.0;
  }
  emxInit_real_T(&work, 1);
  qp1jj = work->size[0];
  work->size[0] = A->size[0];
  emxEnsureCapacity_real_T(work, qp1jj);
  work_data = work->data;
  for (ii = 0; ii < n; ii++) {
    work_data[ii] = 0.0;
  }
  qp1jj = U->size[0] * U->size[1];
  U->size[0] = A->size[0];
  U->size[1] = A->size[0];
  emxEnsureCapacity_real_T(U, qp1jj);
  U_data = U->data;
  qp1jj = A->size[0] * A->size[0];
  for (ii = 0; ii < qp1jj; ii++) {
    U_data[ii] = 0.0;
  }
  qp1jj = V->size[0] * V->size[1];
  V->size[0] = A->size[1];
  V->size[1] = A->size[1];
  emxEnsureCapacity_real_T(V, qp1jj);
  V_data = V->data;
  qp1jj = A->size[1] * A->size[1];
  for (ii = 0; ii < qp1jj; ii++) {
    V_data[ii] = 0.0;
  }
  if ((A->size[0] == 0) || (A->size[1] == 0)) {
    for (ii = 0; ii < n; ii++) {
      U_data[ii + U->size[0] * ii] = 1.0;
    }
    for (ii = 0; ii < p; ii++) {
      V_data[ii + V->size[0] * ii] = 1.0;
    }
  } else {
    __m128d r;
    double b_r;
    double nrm;
    double snorm;
    int iter;
    int m;
    int nct;
    int nctp1;
    int nmq;
    int nrt;
    int pmq;
    int qp1;
    int qq;
    if (A->size[1] >= 2) {
      qp1jj = A->size[1] - 2;
    } else {
      qp1jj = 0;
    }
    nrt = A->size[0];
    if (qp1jj <= nrt) {
      nrt = qp1jj;
    }
    qp1jj = A->size[0] - 1;
    nct = A->size[1];
    if (qp1jj <= nct) {
      nct = qp1jj;
    }
    nctp1 = nct + 1;
    if (nct >= nrt) {
      iter = nct;
    } else {
      iter = nrt;
    }
    for (q = 0; q < iter; q++) {
      boolean_T apply_transform;
      qp1 = q + 2;
      qq = (q + n * q) + 1;
      nmq = (n - q) - 1;
      apply_transform = false;
      if (q + 1 <= nct) {
        nrm = xnrm2(nmq + 1, A, qq);
        if (nrm > 0.0) {
          apply_transform = true;
          if (A_data[qq - 1] < 0.0) {
            nrm = -nrm;
          }
          s_data[q] = nrm;
          if (fabs(nrm) >= 1.0020841800044864E-292) {
            nrm = 1.0 / nrm;
            ns = qq + nmq;
            qp1jj = ((((ns - qq) + 1) / 2) << 1) + qq;
            pmq = qp1jj - 2;
            for (ii = qq; ii <= pmq; ii += 2) {
              r = _mm_loadu_pd(&A_data[ii - 1]);
              _mm_storeu_pd(&A_data[ii - 1], _mm_mul_pd(_mm_set1_pd(nrm), r));
            }
            for (ii = qp1jj; ii <= ns; ii++) {
              A_data[ii - 1] *= nrm;
            }
          } else {
            ns = qq + nmq;
            qp1jj = ((((ns - qq) + 1) / 2) << 1) + qq;
            pmq = qp1jj - 2;
            for (ii = qq; ii <= pmq; ii += 2) {
              r = _mm_loadu_pd(&A_data[ii - 1]);
              _mm_storeu_pd(&A_data[ii - 1],
                            _mm_div_pd(r, _mm_set1_pd(s_data[q])));
            }
            for (ii = qp1jj; ii <= ns; ii++) {
              A_data[ii - 1] /= s_data[q];
            }
          }
          A_data[qq - 1]++;
          s_data[q] = -s_data[q];
        } else {
          s_data[q] = 0.0;
        }
      }
      for (ii = qp1; ii <= p; ii++) {
        ns = q + n * (ii - 1);
        if (apply_transform) {
          nrm = 0.0;
          if (nmq >= 0) {
            for (k = 0; k <= nmq; k++) {
              nrm += A_data[(qq + k) - 1] * A_data[ns + k];
            }
          }
          nrm = -(nrm / A_data[q + A->size[0] * q]);
          xaxpy(nmq + 1, nrm, qq, A, ns + 1);
          A_data = A->data;
        }
        e_data[ii - 1] = A_data[ns];
      }
      if (q + 1 <= nct) {
        for (ii = q + 1; ii <= n; ii++) {
          U_data[(ii + U->size[0] * q) - 1] = A_data[(ii + A->size[0] * q) - 1];
        }
      }
      if (q + 1 <= nrt) {
        pmq = p - q;
        nrm = xnrm2(pmq - 1, e, q + 2);
        if (nrm == 0.0) {
          e_data[q] = 0.0;
        } else {
          if (e_data[q + 1] < 0.0) {
            e_data[q] = -nrm;
          } else {
            e_data[q] = nrm;
          }
          nrm = e_data[q];
          if (fabs(e_data[q]) >= 1.0020841800044864E-292) {
            nrm = 1.0 / e_data[q];
            ns = q + pmq;
            qp1jj = (((((ns - q) - 1) / 2) << 1) + q) + 2;
            pmq = qp1jj - 2;
            for (ii = qp1; ii <= pmq; ii += 2) {
              r = _mm_loadu_pd(&e_data[ii - 1]);
              _mm_storeu_pd(&e_data[ii - 1], _mm_mul_pd(_mm_set1_pd(nrm), r));
            }
            for (ii = qp1jj; ii <= ns; ii++) {
              e_data[ii - 1] *= nrm;
            }
          } else {
            ns = q + pmq;
            qp1jj = (((((ns - q) - 1) / 2) << 1) + q) + 2;
            pmq = qp1jj - 2;
            for (ii = qp1; ii <= pmq; ii += 2) {
              r = _mm_loadu_pd(&e_data[ii - 1]);
              _mm_storeu_pd(&e_data[ii - 1], _mm_div_pd(r, _mm_set1_pd(nrm)));
            }
            for (ii = qp1jj; ii <= ns; ii++) {
              e_data[ii - 1] /= nrm;
            }
          }
          e_data[q + 1]++;
          e_data[q] = -e_data[q];
          if (q + 2 <= n) {
            for (ii = qp1; ii <= n; ii++) {
              work_data[ii - 1] = 0.0;
            }
            for (ii = qp1; ii <= p; ii++) {
              b_xaxpy(nmq, e_data[ii - 1], A, (q + n * (ii - 1)) + 2, work,
                      q + 2);
              work_data = work->data;
            }
            for (ii = qp1; ii <= p; ii++) {
              b_xaxpy(nmq, -e_data[ii - 1] / e_data[q + 1], work, q + 2, A,
                      (q + n * (ii - 1)) + 2);
              A_data = A->data;
            }
          }
        }
        for (ii = qp1; ii <= p; ii++) {
          V_data[(ii + V->size[0] * q) - 1] = e_data[ii - 1];
        }
      }
    }
    if (A->size[1] <= A->size[0] + 1) {
      m = A->size[1] - 1;
    } else {
      m = A->size[0];
    }
    if (nct < A->size[1]) {
      s_data[nct] = A_data[nct + A->size[0] * nct];
    }
    if (A->size[0] < m + 1) {
      s_data[m] = 0.0;
    }
    if (nrt + 1 < m + 1) {
      e_data[nrt] = A_data[nrt + A->size[0] * m];
    }
    e_data[m] = 0.0;
    if (nct + 1 <= A->size[0]) {
      for (ii = nctp1; ii <= n; ii++) {
        for (k = 0; k < n; k++) {
          U_data[k + U->size[0] * (ii - 1)] = 0.0;
        }
        U_data[(ii + U->size[0] * (ii - 1)) - 1] = 1.0;
      }
    }
    for (q = nct; q >= 1; q--) {
      qp1 = q + 1;
      nmq = n - q;
      qq = (q + n * (q - 1)) - 1;
      if (s_data[q - 1] != 0.0) {
        for (ii = qp1; ii <= n; ii++) {
          ns = q + n * (ii - 1);
          nrm = 0.0;
          if (nmq >= 0) {
            for (k = 0; k <= nmq; k++) {
              nrm += U_data[qq + k] * U_data[(ns + k) - 1];
            }
          }
          nrm = -(nrm / U_data[qq]);
          xaxpy(nmq + 1, nrm, qq + 1, U, ns);
          U_data = U->data;
        }
        ns = (((nmq + 1) / 2) << 1) + q;
        qp1jj = ns - 2;
        for (ii = q; ii <= qp1jj; ii += 2) {
          r = _mm_loadu_pd(&U_data[(ii + U->size[0] * (q - 1)) - 1]);
          _mm_storeu_pd(&U_data[(ii + U->size[0] * (q - 1)) - 1],
                        _mm_mul_pd(r, _mm_set1_pd(-1.0)));
        }
        for (ii = ns; ii <= n; ii++) {
          U_data[(ii + U->size[0] * (q - 1)) - 1] =
              -U_data[(ii + U->size[0] * (q - 1)) - 1];
        }
        U_data[qq]++;
        for (ii = 0; ii <= q - 2; ii++) {
          U_data[ii + U->size[0] * (q - 1)] = 0.0;
        }
      } else {
        for (ii = 0; ii < n; ii++) {
          U_data[ii + U->size[0] * (q - 1)] = 0.0;
        }
        U_data[qq] = 1.0;
      }
    }
    for (q = p; q >= 1; q--) {
      if ((q <= nrt) && (e_data[q - 1] != 0.0)) {
        qp1 = q + 1;
        pmq = p - q;
        ns = q + p * (q - 1);
        for (ii = qp1; ii <= p; ii++) {
          qp1jj = q + p * (ii - 1);
          nrm = 0.0;
          if (pmq >= 1) {
            for (k = 0; k < pmq; k++) {
              nrm += V_data[ns + k] * V_data[qp1jj + k];
            }
          }
          nrm = -(nrm / V_data[ns]);
          xaxpy(pmq, nrm, ns + 1, V, qp1jj + 1);
          V_data = V->data;
        }
      }
      for (ii = 0; ii < p; ii++) {
        V_data[ii + V->size[0] * (q - 1)] = 0.0;
      }
      V_data[(q + V->size[0] * (q - 1)) - 1] = 1.0;
    }
    nmq = m;
    iter = 0;
    snorm = 0.0;
    for (q = 0; q <= m; q++) {
      if (s_data[q] != 0.0) {
        nrm = fabs(s_data[q]);
        b_r = s_data[q] / nrm;
        s_data[q] = nrm;
        if (q + 1 < m + 1) {
          e_data[q] /= b_r;
        }
        if (q + 1 <= n) {
          ns = n * q;
          pmq = ns + n;
          qq = ((((pmq - ns) / 2) << 1) + ns) + 1;
          qp1jj = qq - 2;
          for (ii = ns + 1; ii <= qp1jj; ii += 2) {
            r = _mm_loadu_pd(&U_data[ii - 1]);
            _mm_storeu_pd(&U_data[ii - 1], _mm_mul_pd(_mm_set1_pd(b_r), r));
          }
          for (ii = qq; ii <= pmq; ii++) {
            U_data[ii - 1] *= b_r;
          }
        }
      }
      if ((q + 1 < m + 1) && (e_data[q] != 0.0)) {
        nrm = fabs(e_data[q]);
        b_r = nrm / e_data[q];
        e_data[q] = nrm;
        s_data[q + 1] *= b_r;
        ns = p * (q + 1);
        pmq = ns + p;
        qp1jj = ((((pmq - ns) / 2) << 1) + ns) + 1;
        qq = qp1jj - 2;
        for (ii = ns + 1; ii <= qq; ii += 2) {
          r = _mm_loadu_pd(&V_data[ii - 1]);
          _mm_storeu_pd(&V_data[ii - 1], _mm_mul_pd(_mm_set1_pd(b_r), r));
        }
        for (ii = qp1jj; ii <= pmq; ii++) {
          V_data[ii - 1] *= b_r;
        }
      }
      snorm = fmax(snorm, fmax(fabs(s_data[q]), fabs(e_data[q])));
    }
    while ((m + 1 > 0) && (iter < 75)) {
      boolean_T exitg1;
      nctp1 = m;
      exitg1 = false;
      while (!(exitg1 || (nctp1 == 0))) {
        nrm = fabs(e_data[nctp1 - 1]);
        if ((nrm <= 2.2204460492503131E-16 *
                        (fabs(s_data[nctp1 - 1]) + fabs(s_data[nctp1]))) ||
            (nrm <= 1.0020841800044864E-292) ||
            ((iter > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
          e_data[nctp1 - 1] = 0.0;
          exitg1 = true;
        } else {
          nctp1--;
        }
      }
      if (nctp1 == m) {
        qp1jj = 4;
      } else {
        pmq = m + 1;
        ns = m + 1;
        exitg1 = false;
        while ((!exitg1) && (ns >= nctp1)) {
          pmq = ns;
          if (ns == nctp1) {
            exitg1 = true;
          } else {
            nrm = 0.0;
            if (ns < m + 1) {
              nrm = fabs(e_data[ns - 1]);
            }
            if (ns > nctp1 + 1) {
              nrm += fabs(e_data[ns - 2]);
            }
            b_r = fabs(s_data[ns - 1]);
            if ((b_r <= 2.2204460492503131E-16 * nrm) ||
                (b_r <= 1.0020841800044864E-292)) {
              s_data[ns - 1] = 0.0;
              exitg1 = true;
            } else {
              ns--;
            }
          }
        }
        if (pmq == nctp1) {
          qp1jj = 3;
        } else if (pmq == m + 1) {
          qp1jj = 1;
        } else {
          qp1jj = 2;
          nctp1 = pmq;
        }
      }
      switch (qp1jj) {
      case 1:
        f = e_data[m - 1];
        e_data[m - 1] = 0.0;
        for (ii = m; ii >= nctp1 + 1; ii--) {
          sqds = xrotg(&s_data[ii - 1], &f, &b);
          if (ii > nctp1 + 1) {
            nrm = e_data[ii - 2];
            f = -b * nrm;
            e_data[ii - 2] = nrm * sqds;
          }
          if (p >= 1) {
            ns = p * (ii - 1);
            qp1jj = p * m;
            for (k = 0; k < p; k++) {
              pmq = qp1jj + k;
              nrm = V_data[pmq];
              qq = ns + k;
              b_r = V_data[qq];
              V_data[pmq] = sqds * nrm - b * b_r;
              V_data[qq] = sqds * b_r + b * nrm;
            }
          }
        }
        break;
      case 2:
        f = e_data[nctp1 - 1];
        e_data[nctp1 - 1] = 0.0;
        for (ii = nctp1 + 1; ii <= m + 1; ii++) {
          sqds = xrotg(&s_data[ii - 1], &f, &b);
          nrm = e_data[ii - 1];
          f = -b * nrm;
          e_data[ii - 1] = nrm * sqds;
          if (n >= 1) {
            ns = n * (ii - 1);
            qp1jj = n * (nctp1 - 1);
            for (k = 0; k < n; k++) {
              pmq = qp1jj + k;
              nrm = U_data[pmq];
              qq = ns + k;
              b_r = U_data[qq];
              U_data[pmq] = sqds * nrm - b * b_r;
              U_data[qq] = sqds * b_r + b * nrm;
            }
          }
        }
        break;
      case 3:
        nrm = s_data[m - 1];
        b_r = e_data[m - 1];
        scale = fmax(fmax(fmax(fmax(fabs(s_data[m]), fabs(nrm)), fabs(b_r)),
                          fabs(s_data[nctp1])),
                     fabs(e_data[nctp1]));
        sm = s_data[m] / scale;
        nrm /= scale;
        b_r /= scale;
        sqds = s_data[nctp1] / scale;
        b = ((nrm + sm) * (nrm - sm) + b_r * b_r) / 2.0;
        nrm = sm * b_r;
        nrm *= nrm;
        if ((b != 0.0) || (nrm != 0.0)) {
          b_r = sqrt(b * b + nrm);
          if (b < 0.0) {
            b_r = -b_r;
          }
          b_r = nrm / (b + b_r);
        } else {
          b_r = 0.0;
        }
        f = (sqds + sm) * (sqds - sm) + b_r;
        sqds *= e_data[nctp1] / scale;
        for (k = nctp1 + 1; k <= m; k++) {
          sm = xrotg(&f, &sqds, &sn);
          if (k > nctp1 + 1) {
            e_data[k - 2] = f;
          }
          nrm = e_data[k - 1];
          b_r = s_data[k - 1];
          e_data[k - 1] = sm * nrm - sn * b_r;
          scale = sn * s_data[k];
          s_data[k] *= sm;
          if (p >= 1) {
            ns = p * (k - 1);
            qp1jj = p * k;
            for (ii = 0; ii < p; ii++) {
              pmq = qp1jj + ii;
              b = V_data[pmq];
              qq = ns + ii;
              sqds = V_data[qq];
              V_data[pmq] = sm * b - sn * sqds;
              V_data[qq] = sm * sqds + sn * b;
            }
          }
          s_data[k - 1] = sm * b_r + sn * nrm;
          b = xrotg(&s_data[k - 1], &scale, &sm);
          nrm = e_data[k - 1];
          f = b * nrm + sm * s_data[k];
          s_data[k] = -sm * nrm + b * s_data[k];
          sqds = sm * e_data[k];
          e_data[k] *= b;
          if ((k < n) && (n >= 1)) {
            ns = n * (k - 1);
            qp1jj = n * k;
            for (ii = 0; ii < n; ii++) {
              pmq = qp1jj + ii;
              nrm = U_data[pmq];
              qq = ns + ii;
              b_r = U_data[qq];
              U_data[pmq] = b * nrm - sm * b_r;
              U_data[qq] = b * b_r + sm * nrm;
            }
          }
        }
        e_data[m - 1] = f;
        iter++;
        break;
      default:
        if (s_data[nctp1] < 0.0) {
          s_data[nctp1] = -s_data[nctp1];
          ns = p * nctp1;
          qp1jj = ns + p;
          pmq = ((((qp1jj - ns) / 2) << 1) + ns) + 1;
          qq = pmq - 2;
          for (ii = ns + 1; ii <= qq; ii += 2) {
            r = _mm_loadu_pd(&V_data[ii - 1]);
            _mm_storeu_pd(&V_data[ii - 1], _mm_mul_pd(r, _mm_set1_pd(-1.0)));
          }
          for (ii = pmq; ii <= qp1jj; ii++) {
            V_data[ii - 1] = -V_data[ii - 1];
          }
        }
        qp1 = nctp1 + 1;
        while ((nctp1 + 1 < nmq + 1) && (s_data[nctp1] < s_data[qp1])) {
          nrm = s_data[nctp1];
          s_data[nctp1] = s_data[qp1];
          s_data[qp1] = nrm;
          if (nctp1 + 1 < p) {
            ns = p * nctp1;
            pmq = p * (nctp1 + 1);
            for (ii = 0; ii < p; ii++) {
              qp1jj = ns + ii;
              nrm = V_data[qp1jj];
              qq = pmq + ii;
              V_data[qp1jj] = V_data[qq];
              V_data[qq] = nrm;
            }
          }
          if (nctp1 + 1 < n) {
            qq = n * nctp1;
            ns = n * (nctp1 + 1);
            for (ii = 0; ii < n; ii++) {
              qp1jj = qq + ii;
              nrm = U_data[qp1jj];
              pmq = ns + ii;
              U_data[qp1jj] = U_data[pmq];
              U_data[pmq] = nrm;
            }
          }
          nctp1 = qp1;
          qp1++;
        }
        iter = 0;
        m--;
        break;
      }
    }
  }
  emxFree_real_T(&work);
  emxFree_real_T(&e);
  qp1jj = S->size[0];
  S->size[0] = minnp;
  emxEnsureCapacity_real_T(S, qp1jj);
  A_data = S->data;
  for (ii = 0; ii < minnp; ii++) {
    A_data[ii] = s_data[ii];
  }
  emxFree_real_T(&s);
}

/* End of code generation (xzsvdc.c) */
