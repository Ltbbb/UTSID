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
#include "eml_int_forloop_overflow_check.h"
#include "lee_region_data.h"
#include "lee_region_emxutil.h"
#include "lee_region_types.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo t_emlrtRSI = {
    14,    /* lineNo */
    "svd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" /* pathName
                                                                       */
};

static emlrtRSInfo u_emlrtRSI = {
    36,    /* lineNo */
    "svd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" /* pathName
                                                                       */
};

static emlrtRSInfo v_emlrtRSI = {
    29,             /* lineNo */
    "anyNonFinite", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\anyNonFinite."
    "m" /* pathName */
};

static emlrtRSInfo w_emlrtRSI =
    {
        45,          /* lineNo */
        "vAllOrAny", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\vAllOrAny.m" /* pathName */
};

static emlrtRSInfo x_emlrtRSI =
    {
        121,                  /* lineNo */
        "flatVectorAllOrAny", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\vAllOrAny.m" /* pathName */
};

static emlrtRSInfo y_emlrtRSI = {
    23,    /* lineNo */
    "svd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pathName
                                                                          */
};

static emlrtRSInfo ab_emlrtRSI = {
    52,    /* lineNo */
    "svd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pathName
                                                                          */
};

static emlrtRSInfo bb_emlrtRSI = {
    163,              /* lineNo */
    "getUSVForEmpty", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pathName
                                                                          */
};

static emlrtRSInfo cb_emlrtRSI = {
    171,              /* lineNo */
    "getUSVForEmpty", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pathName
                                                                          */
};

static emlrtRSInfo db_emlrtRSI =
    {
        50,    /* lineNo */
        "eye", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\elmat\\eye.m" /* pathName
                                                                          */
};

static emlrtRSInfo eb_emlrtRSI =
    {
        98,    /* lineNo */
        "eye", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\elmat\\eye.m" /* pathName
                                                                          */
};

static emlrtRSInfo gb_emlrtRSI = {
    89,           /* lineNo */
    "callLAPACK", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pathName
                                                                          */
};

static emlrtRSInfo hb_emlrtRSI = {
    81,           /* lineNo */
    "callLAPACK", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pathName
                                                                          */
};

static emlrtRSInfo ib_emlrtRSI = {
    209,      /* lineNo */
    "xgesdd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesdd.m" /* pathName */
};

static emlrtRSInfo jb_emlrtRSI = {
    31,       /* lineNo */
    "xgesvd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pathName */
};

static emlrtRSInfo kb_emlrtRSI = {
    205,            /* lineNo */
    "ceval_xgesvd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pathName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    111,          /* lineNo */
    5,            /* colNo */
    "callLAPACK", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pName
                                                                          */
};

static emlrtRTEInfo e_emlrtRTEI = {
    45,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    48,          /* lineNo */
    13,          /* colNo */
    "infocheck", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" /* pName */
};

static emlrtRTEInfo db_emlrtRTEI = {
    57,    /* lineNo */
    33,    /* colNo */
    "svd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pName
                                                                          */
};

static emlrtRTEInfo eb_emlrtRTEI = {
    162,   /* lineNo */
    1,     /* colNo */
    "svd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pName
                                                                          */
};

static emlrtRTEInfo fb_emlrtRTEI = {
    81,    /* lineNo */
    63,    /* colNo */
    "svd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pName
                                                                          */
};

static emlrtRTEInfo gb_emlrtRTEI = {
    45,       /* lineNo */
    24,       /* colNo */
    "xgesdd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesdd.m" /* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = {
    47,       /* lineNo */
    25,       /* colNo */
    "xgesdd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesdd.m" /* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = {
    57,       /* lineNo */
    20,       /* colNo */
    "xgesdd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesdd.m" /* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = {
    171,   /* lineNo */
    9,     /* colNo */
    "svd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" /* pName
                                                                          */
};

static emlrtRTEInfo kb_emlrtRTEI = {
    226,      /* lineNo */
    5,        /* colNo */
    "xgesvd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = {
    83,       /* lineNo */
    24,       /* colNo */
    "xgesvd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = {
    90,       /* lineNo */
    25,       /* colNo */
    "xgesvd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = {
    49,    /* lineNo */
    9,     /* colNo */
    "svd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" /* pName
                                                                       */
};

static emlrtRTEInfo ob_emlrtRTEI = {
    98,       /* lineNo */
    20,       /* colNo */
    "xgesvd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = {
    131,      /* lineNo */
    9,        /* colNo */
    "xgesvd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = {
    129,      /* lineNo */
    33,       /* colNo */
    "xgesvd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = {
    18,    /* lineNo */
    9,     /* colNo */
    "svd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" /* pName
                                                                       */
};

static emlrtRTEInfo sb_emlrtRTEI = {
    1,     /* lineNo */
    20,    /* colNo */
    "svd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\matfun\\svd.m" /* pName
                                                                       */
};

static emlrtRTEInfo tb_emlrtRTEI = {
    90,       /* lineNo */
    5,        /* colNo */
    "xgesvd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = {
    129,      /* lineNo */
    9,        /* colNo */
    "xgesvd", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" /* pName */
};

/* Function Definitions */
void svd(const emlrtStack *sp, const emxArray_real_T *A, emxArray_real_T *U,
         emxArray_real_T *S, emxArray_real_T *V)
{
  static const char_T b_fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                     '_', 'd', 'g', 'e', 's', 'v', 'd'};
  static const char_T fname[14] = {'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                   '_', 'd', 'g', 'e', 's', 'd', 'd'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_real_T *Vt;
  emxArray_real_T *b_A;
  emxArray_real_T *c_A;
  emxArray_real_T *s;
  emxArray_real_T *superb;
  const real_T *A_data;
  real_T *U_data;
  real_T *V_data;
  real_T *Vt_data;
  real_T *b_A_data;
  real_T *s_data;
  int32_T b_i;
  int32_T i;
  int32_T loop_ub;
  int32_T n;
  boolean_T overflow;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  A_data = A->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &t_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  c_st.site = &w_emlrtRSI;
  n = A->size[0] * A->size[1];
  d_st.site = &x_emlrtRSI;
  overflow = (n > 2147483646);
  if (overflow) {
    e_st.site = &s_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  st.site = &u_emlrtRSI;
  emxInit_real_T(&st, &s, 1, &rb_emlrtRTEI);
  s_data = s->data;
  if ((A->size[0] == 0) || (A->size[1] == 0)) {
    int32_T m;
    b_st.site = &y_emlrtRSI;
    n = A->size[0];
    m = A->size[1];
    loop_ub = U->size[0] * U->size[1];
    U->size[0] = A->size[0];
    U->size[1] = A->size[0];
    emxEnsureCapacity_real_T(&b_st, U, loop_ub, &eb_emlrtRTEI);
    U_data = U->data;
    loop_ub = A->size[0] * A->size[0];
    for (i = 0; i < loop_ub; i++) {
      U_data[i] = 0.0;
    }
    loop_ub = muIntScalarMin_sint32(n, n);
    c_st.site = &bb_emlrtRSI;
    overflow = (loop_ub > 2147483646);
    if (overflow) {
      d_st.site = &s_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (i = 0; i < loop_ub; i++) {
      U_data[i + U->size[0] * i] = 1.0;
    }
    c_st.site = &cb_emlrtRSI;
    d_st.site = &db_emlrtRSI;
    loop_ub = V->size[0] * V->size[1];
    V->size[0] = A->size[1];
    V->size[1] = A->size[1];
    emxEnsureCapacity_real_T(&c_st, V, loop_ub, &jb_emlrtRTEI);
    V_data = V->data;
    loop_ub = A->size[1] * A->size[1];
    for (i = 0; i < loop_ub; i++) {
      V_data[i] = 0.0;
    }
    if (A->size[1] > 0) {
      d_st.site = &eb_emlrtRSI;
      if (A->size[1] > 2147483646) {
        e_st.site = &s_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }
      for (i = 0; i < m; i++) {
        V_data[i + V->size[0] * i] = 1.0;
      }
    }
    s->size[0] = 0;
  } else {
    ptrdiff_t info_t;
    int32_T info;
    int32_T m;
    b_st.site = &ab_emlrtRSI;
    emxInit_real_T(&b_st, &b_A, 2, &sb_emlrtRTEI);
    m = A->size[0];
    loop_ub = b_A->size[0] * b_A->size[1];
    b_A->size[0] = A->size[0];
    info = A->size[1];
    b_A->size[1] = A->size[1];
    emxEnsureCapacity_real_T(&b_st, b_A, loop_ub, &db_emlrtRTEI);
    b_A_data = b_A->data;
    for (i = 0; i < n; i++) {
      b_A_data[i] = A_data[i];
    }
    c_st.site = &hb_emlrtRSI;
    emxInit_real_T(&c_st, &c_A, 2, &fb_emlrtRTEI);
    loop_ub = c_A->size[0] * c_A->size[1];
    c_A->size[0] = A->size[0];
    c_A->size[1] = A->size[1];
    emxEnsureCapacity_real_T(&c_st, c_A, loop_ub, &fb_emlrtRTEI);
    V_data = c_A->data;
    for (i = 0; i < n; i++) {
      V_data[i] = A_data[i];
    }
    n = muIntScalarMin_sint32(info, m);
    loop_ub = U->size[0] * U->size[1];
    U->size[0] = A->size[0];
    U->size[1] = A->size[0];
    emxEnsureCapacity_real_T(&c_st, U, loop_ub, &gb_emlrtRTEI);
    U_data = U->data;
    emxInit_real_T(&c_st, &Vt, 2, &tb_emlrtRTEI);
    loop_ub = Vt->size[0] * Vt->size[1];
    Vt->size[0] = A->size[1];
    Vt->size[1] = A->size[1];
    emxEnsureCapacity_real_T(&c_st, Vt, loop_ub, &hb_emlrtRTEI);
    Vt_data = Vt->data;
    loop_ub = s->size[0];
    s->size[0] = n;
    emxEnsureCapacity_real_T(&c_st, s, loop_ub, &ib_emlrtRTEI);
    s_data = s->data;
    info_t = LAPACKE_dgesdd(
        102, 'A', (ptrdiff_t)A->size[0], (ptrdiff_t)A->size[1], &V_data[0],
        (ptrdiff_t)A->size[0], &s_data[0], &U_data[0], (ptrdiff_t)A->size[0],
        &Vt_data[0], (ptrdiff_t)A->size[1]);
    emxFree_real_T(&c_st, &c_A);
    d_st.site = &ib_emlrtRSI;
    if ((int32_T)info_t < 0) {
      if ((int32_T)info_t == -1010) {
        emlrtErrorWithMessageIdR2018a(&d_st, &e_emlrtRTEI, "MATLAB:nomem",
                                      "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&d_st, &f_emlrtRTEI,
                                      "Coder:toolbox:LAPACKCallErrorInfo",
                                      "Coder:toolbox:LAPACKCallErrorInfo", 5, 4,
                                      14, &fname[0], 12, (int32_T)info_t);
      }
    }
    info = (int32_T)info_t;
    if ((int32_T)info_t > 0) {
      c_st.site = &gb_emlrtRSI;
      d_st.site = &jb_emlrtRSI;
      loop_ub = U->size[0] * U->size[1];
      U->size[0] = A->size[0];
      U->size[1] = A->size[0];
      emxEnsureCapacity_real_T(&d_st, U, loop_ub, &lb_emlrtRTEI);
      U_data = U->data;
      loop_ub = Vt->size[0] * Vt->size[1];
      Vt->size[0] = A->size[1];
      Vt->size[1] = A->size[1];
      emxEnsureCapacity_real_T(&d_st, Vt, loop_ub, &mb_emlrtRTEI);
      Vt_data = Vt->data;
      loop_ub = s->size[0];
      s->size[0] = n;
      emxEnsureCapacity_real_T(&d_st, s, loop_ub, &ob_emlrtRTEI);
      s_data = s->data;
      emxInit_real_T(&d_st, &superb, 1, &ub_emlrtRTEI);
      if (n > 1) {
        loop_ub = superb->size[0];
        superb->size[0] = n - 1;
        emxEnsureCapacity_real_T(&d_st, superb, loop_ub, &qb_emlrtRTEI);
        V_data = superb->data;
      } else {
        loop_ub = superb->size[0];
        superb->size[0] = 1;
        emxEnsureCapacity_real_T(&d_st, superb, loop_ub, &pb_emlrtRTEI);
        V_data = superb->data;
      }
      info_t = LAPACKE_dgesvd(102, 'A', 'A', (ptrdiff_t)A->size[0],
                              (ptrdiff_t)A->size[1], &b_A_data[0],
                              (ptrdiff_t)A->size[0], &s_data[0], &U_data[0],
                              (ptrdiff_t)A->size[0], &Vt_data[0],
                              (ptrdiff_t)A->size[1], &V_data[0]);
      emxFree_real_T(&d_st, &superb);
      n = Vt->size[1];
      loop_ub = V->size[0] * V->size[1];
      V->size[0] = Vt->size[1];
      m = Vt->size[0];
      V->size[1] = Vt->size[0];
      emxEnsureCapacity_real_T(&d_st, V, loop_ub, &kb_emlrtRTEI);
      V_data = V->data;
      for (i = 0; i < m; i++) {
        for (b_i = 0; b_i < n; b_i++) {
          V_data[b_i + V->size[0] * i] = Vt_data[i + Vt->size[0] * b_i];
        }
      }
      e_st.site = &kb_emlrtRSI;
      if ((int32_T)info_t < 0) {
        if ((int32_T)info_t == -1010) {
          emlrtErrorWithMessageIdR2018a(&e_st, &e_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(
              &e_st, &f_emlrtRTEI, "Coder:toolbox:LAPACKCallErrorInfo",
              "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, &b_fname[0], 12,
              (int32_T)info_t);
        }
      }
      info = (int32_T)info_t;
    } else {
      n = Vt->size[1];
      loop_ub = V->size[0] * V->size[1];
      V->size[0] = Vt->size[1];
      m = Vt->size[0];
      V->size[1] = Vt->size[0];
      emxEnsureCapacity_real_T(&b_st, V, loop_ub, &kb_emlrtRTEI);
      V_data = V->data;
      for (i = 0; i < m; i++) {
        for (b_i = 0; b_i < n; b_i++) {
          V_data[b_i + V->size[0] * i] = Vt_data[i + Vt->size[0] * b_i];
        }
      }
    }
    emxFree_real_T(&b_st, &Vt);
    emxFree_real_T(&b_st, &b_A);
    if (info > 0) {
      emlrtErrorWithMessageIdR2018a(&b_st, &d_emlrtRTEI,
                                    "Coder:MATLAB:svd_NoConvergence",
                                    "Coder:MATLAB:svd_NoConvergence", 0);
    }
  }
  loop_ub = S->size[0] * S->size[1];
  S->size[0] = U->size[1];
  S->size[1] = V->size[1];
  emxEnsureCapacity_real_T(sp, S, loop_ub, &nb_emlrtRTEI);
  V_data = S->data;
  loop_ub = U->size[1] * V->size[1];
  for (i = 0; i < loop_ub; i++) {
    V_data[i] = 0.0;
  }
  loop_ub = s->size[0];
  for (i = 0; i < loop_ub; i++) {
    V_data[i + S->size[0] * i] = s_data[i];
  }
  emxFree_real_T(sp, &s);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (svd.c) */
