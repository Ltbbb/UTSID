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
#include "diag.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "lee_region_data.h"
#include "lee_region_emxutil.h"
#include "lee_region_types.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "libmwimfilter.h"
#include "libmwippfilter.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo b_emlrtRSI = {
    65,         /* lineNo */
    "imfilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo c_emlrtRSI = {
    69,         /* lineNo */
    "imfilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo d_emlrtRSI = {
    74,         /* lineNo */
    "imfilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo e_emlrtRSI = {
    76,         /* lineNo */
    "imfilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo f_emlrtRSI = {
    77,         /* lineNo */
    "imfilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo g_emlrtRSI = {
    78,         /* lineNo */
    "imfilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo h_emlrtRSI = {
    94,         /* lineNo */
    "imfilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo i_emlrtRSI = {
    98,         /* lineNo */
    "imfilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo j_emlrtRSI = {
    115,        /* lineNo */
    "imfilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo k_emlrtRSI = {
    127,        /* lineNo */
    "imfilter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo l_emlrtRSI = {
    714,           /* lineNo */
    "isSeparable", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo m_emlrtRSI = {
    717,           /* lineNo */
    "isSeparable", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo n_emlrtRSI = {
    720,           /* lineNo */
    "isSeparable", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo o_emlrtRSI = {
    721,           /* lineNo */
    "isSeparable", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo p_emlrtRSI = {
    722,           /* lineNo */
    "isSeparable", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo q_emlrtRSI =
    {
        13,    /* lineNo */
        "all", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\ops\\all.m" /* pathName
                                                                        */
};

static emlrtRSInfo r_emlrtRSI =
    {
        143,        /* lineNo */
        "allOrAny", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny."
        "m" /* pathName */
};

static emlrtRSInfo lb_emlrtRSI = {
    15,    /* lineNo */
    "max", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" /* pathName
                                                                        */
};

static emlrtRSInfo mb_emlrtRSI =
    {
        73,         /* lineNo */
        "minOrMax", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

static emlrtRSInfo nb_emlrtRSI =
    {
        108,       /* lineNo */
        "maximum", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

static emlrtRSInfo ob_emlrtRSI = {
    255,             /* lineNo */
    "unaryMinOrMax", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo pb_emlrtRSI = {
    966,                    /* lineNo */
    "maxRealVectorOmitNaN", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo qb_emlrtRSI = {
    73,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo rb_emlrtRSI = {
    65,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo sb_emlrtRSI = {
    114,         /* lineNo */
    "findFirst", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo tb_emlrtRSI = {
    131,                        /* lineNo */
    "minOrMaxRealVectorKernel", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo ub_emlrtRSI = {
    15,    /* lineNo */
    "sum", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" /* pathName
                                                                        */
};

static emlrtRSInfo vb_emlrtRSI = {
    99,        /* lineNo */
    "sumprod", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumpro"
    "d.m" /* pathName */
};

static emlrtRSInfo wb_emlrtRSI = {
    149,                     /* lineNo */
    "combineVectorElements", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" /* pathName */
};

static emlrtRSInfo xb_emlrtRSI = {
    209,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" /* pathName */
};

static emlrtRSInfo yb_emlrtRSI = {
    814,        /* lineNo */
    "padImage", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo ac_emlrtRSI = {
    20,         /* lineNo */
    "padarray", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\padarray.m" /* pathName
                                                                       */
};

static emlrtRSInfo bc_emlrtRSI = {
    137,        /* lineNo */
    "padarray", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\padarray.m" /* pathName
                                                                       */
};

static emlrtRSInfo cc_emlrtRSI = {
    93,                   /* lineNo */
    "validateattributes", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes"
    ".m" /* pathName */
};

static emlrtRSInfo dc_emlrtRSI = {
    1255,                /* lineNo */
    "getPaddingIndices", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\padarray.m" /* pathName
                                                                       */
};

static emlrtRSInfo ec_emlrtRSI = {
    888,                 /* lineNo */
    "filterPartOrWhole", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo fc_emlrtRSI = {
    962,            /* lineNo */
    "imfiltercore", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo gc_emlrtRSI = {
    990,                /* lineNo */
    "imfiltercoreAlgo", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo hc_emlrtRSI = {
    1002,               /* lineNo */
    "imfiltercoreAlgo", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtRSInfo ic_emlrtRSI = {
    868,                 /* lineNo */
    "filterPartOrWhole", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pathName
                                                                       */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    865,                 /* lineNo */
    27,                  /* colNo */
    "",                  /* aName */
    "filterPartOrWhole", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m", /* pName
                                                                        */
    0 /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    868,                 /* lineNo */
    9,                   /* colNo */
    "",                  /* aName */
    "filterPartOrWhole", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m", /* pName
                                                                        */
    0 /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                  /* iFirst */
    -1,                  /* iLast */
    865,                 /* lineNo */
    9,                   /* colNo */
    "",                  /* aName */
    "filterPartOrWhole", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m", /* pName
                                                                        */
    0 /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    13,     /* lineNo */
    9,      /* colNo */
    "sqrt", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" /* pName
                                                                       */
};

static emlrtRTEInfo b_emlrtRTEI = {
    198,             /* lineNo */
    27,              /* colNo */
    "unaryMinOrMax", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pName */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    78,         /* lineNo */
    33,         /* colNo */
    "",         /* aName */
    "imfilter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m", /* pName
                                                                        */
    0 /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    78,         /* lineNo */
    20,         /* colNo */
    "",         /* aName */
    "imfilter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m", /* pName
                                                                        */
    0 /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    77,         /* lineNo */
    32,         /* colNo */
    "",         /* aName */
    "imfilter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m", /* pName
                                                                        */
    0 /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    77,         /* lineNo */
    20,         /* colNo */
    "",         /* aName */
    "imfilter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m", /* pName
                                                                        */
    0 /* checkKind */
};

static emlrtECInfo emlrtECI = {
    -1,             /* nDims */
    1365,           /* lineNo */
    9,              /* colNo */
    "ReplicatePad", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\padarray.m" /* pName
                                                                       */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    1365,           /* lineNo */
    16,             /* colNo */
    "",             /* aName */
    "ReplicatePad", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\padarray.m", /* pName
                                                                        */
    0 /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    1365,           /* lineNo */
    14,             /* colNo */
    "",             /* aName */
    "ReplicatePad", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\padarray.m", /* pName
                                                                        */
    0 /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    1355,           /* lineNo */
    32,             /* colNo */
    "ReplicatePad", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\padarray.m", /* pName
                                                                        */
    4 /* checkKind */
};

static emlrtRTEInfo h_emlrtRTEI = {
    14,               /* lineNo */
    37,               /* colNo */
    "validatenonnan", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatenonnan.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    14,                    /* lineNo */
    37,                    /* colNo */
    "validatenonnegative", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatenonnegative.m" /* pName */
};

static emlrtRTEInfo j_emlrtRTEI = {
    13,                /* lineNo */
    37,                /* colNo */
    "validateinteger", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validateinteger.m" /* pName */
};

static emlrtDCInfo h_emlrtDCI = {
    1349,           /* lineNo */
    33,             /* colNo */
    "ReplicatePad", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\padarray.m", /* pName
                                                                        */
    1 /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    1349,           /* lineNo */
    33,             /* colNo */
    "ReplicatePad", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\padarray.m", /* pName
                                                                        */
    4 /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    1,          /* iFirst */
    340,        /* iLast */
    156,        /* lineNo */
    36,         /* colNo */
    "",         /* aName */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\padarray.m", /* pName
                                                                        */
    0 /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    156,        /* lineNo */
    41,         /* colNo */
    "",         /* aName */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\padarray.m", /* pName
                                                                        */
    0 /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    156,        /* lineNo */
    52,         /* colNo */
    "",         /* aName */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\padarray.m", /* pName
                                                                        */
    0 /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    156,        /* lineNo */
    27,         /* colNo */
    "",         /* aName */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\padarray.m", /* pName
                                                                        */
    0 /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    156,        /* lineNo */
    29,         /* colNo */
    "",         /* aName */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\padarray.m", /* pName
                                                                        */
    0 /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = {
    139,        /* lineNo */
    61,         /* colNo */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\padarray.m", /* pName
                                                                        */
    4 /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = {
    139,        /* lineNo */
    61,         /* colNo */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\padarray.m", /* pName
                                                                        */
    1 /* checkKind */
};

static emlrtRTEInfo n_emlrtRTEI = {
    121,        /* lineNo */
    13,         /* colNo */
    "imfilter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pName
                                                                       */
};

static emlrtRTEInfo o_emlrtRTEI = {
    859,        /* lineNo */
    1,          /* colNo */
    "imfilter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pName
                                                                       */
};

static emlrtRTEInfo p_emlrtRTEI = {
    77,         /* lineNo */
    9,          /* colNo */
    "imfilter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pName
                                                                       */
};

static emlrtRTEInfo q_emlrtRTEI = {
    865,        /* lineNo */
    9,          /* colNo */
    "imfilter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pName
                                                                       */
};

static emlrtRTEInfo r_emlrtRTEI = {
    868,        /* lineNo */
    9,          /* colNo */
    "imfilter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pName
                                                                       */
};

static emlrtRTEInfo s_emlrtRTEI = {
    78,         /* lineNo */
    9,          /* colNo */
    "imfilter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pName
                                                                       */
};

static emlrtRTEInfo t_emlrtRTEI = {
    85,         /* lineNo */
    13,         /* colNo */
    "imfilter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pName
                                                                       */
};

static emlrtRTEInfo u_emlrtRTEI = {
    722,        /* lineNo */
    16,         /* colNo */
    "imfilter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pName
                                                                       */
};

static emlrtRTEInfo v_emlrtRTEI = {
    865,        /* lineNo */
    27,         /* colNo */
    "imfilter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pName
                                                                       */
};

static emlrtRTEInfo w_emlrtRTEI = {
    984,        /* lineNo */
    26,         /* colNo */
    "imfilter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pName
                                                                       */
};

static emlrtRTEInfo x_emlrtRTEI = {
    69,         /* lineNo */
    9,          /* colNo */
    "imfilter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pName
                                                                       */
};

static emlrtRTEInfo y_emlrtRTEI = {
    94,         /* lineNo */
    9,          /* colNo */
    "imfilter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pName
                                                                       */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    1,          /* lineNo */
    14,         /* colNo */
    "imfilter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pName
                                                                       */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    720,        /* lineNo */
    14,         /* colNo */
    "imfilter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pName
                                                                       */
};

static emlrtRTEInfo cb_emlrtRTEI = {
    717,        /* lineNo */
    8,          /* colNo */
    "imfilter", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\imfilter.m" /* pName
                                                                       */
};

static emlrtRTEInfo xb_emlrtRTEI = {
    1349,       /* lineNo */
    27,         /* colNo */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\padarray.m" /* pName
                                                                       */
};

static emlrtRTEInfo yb_emlrtRTEI = {
    1364,       /* lineNo */
    9,          /* colNo */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\padarray.m" /* pName
                                                                       */
};

static emlrtRTEInfo ac_emlrtRTEI = {
    139,        /* lineNo */
    32,         /* colNo */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\padarray.m" /* pName
                                                                       */
};

static emlrtRTEInfo bc_emlrtRTEI = {
    108,        /* lineNo */
    9,          /* colNo */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\padarray.m" /* pName
                                                                       */
};

static emlrtRTEInfo cc_emlrtRTEI = {
    1358,       /* lineNo */
    9,          /* colNo */
    "padarray", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2025b\\toolbox\\images\\images\\eml\\padarray.m" /* pName
                                                                       */
};

/* Function Declarations */
static void padImage(const emlrtStack *sp, const uint8_T a_tmp[220320],
                     const real_T pad[2], emxArray_uint8_T *a);

/* Function Definitions */
static void padImage(const emlrtStack *sp, const uint8_T a_tmp[220320],
                     const real_T pad[2], emxArray_uint8_T *a)
{
  __m128d r1;
  __m128i r;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_int16_T *idxA;
  emxArray_int16_T *idxDir;
  real_T dv[2];
  real_T dv1[2];
  real_T varargin_1[2];
  real_T d;
  real_T maxval;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T j;
  int32_T k;
  int32_T unnamed_idx_1_tmp;
  int16_T iv[8];
  int16_T *idxA_data;
  int16_T *idxDir_data;
  uint8_T *a_data;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &yb_emlrtRSI;
  b_st.site = &ac_emlrtRSI;
  c_st.site = &cc_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!muDoubleScalarIsNaN(pad[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:padarray:expectedNonNaN", 3, 4, 24, "input number 2, PADSIZE,");
  }
  c_st.site = &cc_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(pad[k] < 0.0)) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &i_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonnegative",
        "MATLAB:padarray:expectedNonnegative", 3, 4, 24,
        "input number 2, PADSIZE,");
  }
  c_st.site = &cc_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsNaN(pad[k])) &&
        (muDoubleScalarFloor(pad[k]) == pad[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &j_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedInteger",
        "MATLAB:padarray:expectedInteger", 3, 4, 24,
        "input number 2, PADSIZE,");
  }
  b_st.site = &bc_emlrtRSI;
  c_st.site = &dc_emlrtRSI;
  maxval = 2.0 * pad[0];
  d = 2.0 * pad[1];
  if ((maxval + 340.0 < d + 648.0) || (muDoubleScalarIsNaN(maxval + 340.0) &&
                                       (!muDoubleScalarIsNaN(d + 648.0)))) {
    maxval = d + 648.0;
  } else {
    maxval += 340.0;
  }
  if (!(maxval >= 0.0)) {
    emlrtNonNegativeCheckR2012b(maxval, &i_emlrtDCI, &c_st);
  }
  if (maxval != (int32_T)muDoubleScalarFloor(maxval)) {
    emlrtIntegerCheckR2012b(maxval, &h_emlrtDCI, &c_st);
  }
  emxInit_int16_T(&c_st, &idxA, &bc_emlrtRTEI);
  k = idxA->size[0] * idxA->size[1];
  idxA->size[0] = (int32_T)maxval;
  idxA->size[1] = 2;
  emxEnsureCapacity_int16_T(&c_st, idxA, k, &xb_emlrtRTEI);
  idxA_data = idxA->data;
  if (!(pad[0] >= 0.0)) {
    emlrtNonNegativeCheckR2012b(pad[0], &g_emlrtDCI, &c_st);
  }
  unnamed_idx_1_tmp = (int32_T)pad[0];
  emxInit_int16_T(&c_st, &idxDir, &cc_emlrtRTEI);
  k = idxDir->size[0] * idxDir->size[1];
  idxDir->size[0] = 1;
  idxDir->size[1] = ((int32_T)pad[0] + (int32_T)pad[0]) + 340;
  emxEnsureCapacity_int16_T(&c_st, idxDir, k, &yb_emlrtRTEI);
  idxDir_data = idxDir->data;
  for (j = 0; j < unnamed_idx_1_tmp; j++) {
    idxDir_data[j] = 1;
  }
  for (j = 0; j <= 328; j += 8) {
    iv[0] = (int16_T)j;
    iv[1] = (int16_T)(j + 1);
    iv[2] = (int16_T)(j + 2);
    iv[3] = (int16_T)(j + 3);
    iv[4] = (int16_T)(j + 4);
    iv[5] = (int16_T)(j + 5);
    iv[6] = (int16_T)(j + 6);
    iv[7] = (int16_T)(j + 7);
    r = _mm_loadu_si128((const __m128i *)&iv[0]);
    _mm_storeu_si128((__m128i *)&idxDir_data[j + unnamed_idx_1_tmp],
                     _mm_add_epi16(_mm_set1_epi16(1), r));
  }
  idxDir_data[(int32_T)pad[0] + 336] = 337;
  idxDir_data[(int32_T)pad[0] + 337] = 338;
  idxDir_data[(int32_T)pad[0] + 338] = 339;
  idxDir_data[(int32_T)pad[0] + 339] = 340;
  for (j = 0; j < unnamed_idx_1_tmp; j++) {
    idxDir_data[(j + unnamed_idx_1_tmp) + 340] = 340;
  }
  if ((int32_T)maxval < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, (int32_T)maxval, &l_emlrtBCI, &c_st);
  }
  k = idxDir->size[1];
  if ((idxDir->size[1] < 1) || (idxDir->size[1] > (int32_T)maxval)) {
    emlrtDynamicBoundsCheckR2012b(idxDir->size[1], 1, (int32_T)maxval,
                                  &k_emlrtBCI, &c_st);
  }
  emlrtSubAssignSizeCheckR2012b(&idxDir->size[1], 1, &idxDir->size[0], 2,
                                &emlrtECI, &c_st);
  for (j = 0; j < k; j++) {
    idxA_data[j] = idxDir_data[j];
  }
  if (!(pad[1] >= 0.0)) {
    emlrtNonNegativeCheckR2012b(pad[1], &g_emlrtDCI, &c_st);
  }
  unnamed_idx_1_tmp = (int32_T)pad[1];
  k = idxDir->size[0] * idxDir->size[1];
  idxDir->size[0] = 1;
  idxDir->size[1] = ((int32_T)pad[1] + (int32_T)pad[1]) + 648;
  emxEnsureCapacity_int16_T(&c_st, idxDir, k, &yb_emlrtRTEI);
  idxDir_data = idxDir->data;
  for (j = 0; j < unnamed_idx_1_tmp; j++) {
    idxDir_data[j] = 1;
  }
  for (j = 0; j <= 640; j += 8) {
    iv[0] = (int16_T)j;
    iv[1] = (int16_T)(j + 1);
    iv[2] = (int16_T)(j + 2);
    iv[3] = (int16_T)(j + 3);
    iv[4] = (int16_T)(j + 4);
    iv[5] = (int16_T)(j + 5);
    iv[6] = (int16_T)(j + 6);
    iv[7] = (int16_T)(j + 7);
    r = _mm_loadu_si128((const __m128i *)&iv[0]);
    _mm_storeu_si128((__m128i *)&idxDir_data[j + unnamed_idx_1_tmp],
                     _mm_add_epi16(_mm_set1_epi16(1), r));
  }
  for (j = 0; j < unnamed_idx_1_tmp; j++) {
    idxDir_data[(j + unnamed_idx_1_tmp) + 648] = 648;
  }
  i = idxA->size[0];
  if (idxA->size[0] < 1) {
    emlrtDynamicBoundsCheckR2012b(1, 1, idxA->size[0], &l_emlrtBCI, &c_st);
  }
  k = idxDir->size[1];
  if ((idxDir->size[1] < 1) || (idxDir->size[1] > idxA->size[0])) {
    emlrtDynamicBoundsCheckR2012b(idxDir->size[1], 1, idxA->size[0],
                                  &k_emlrtBCI, &c_st);
  }
  emlrtSubAssignSizeCheckR2012b(&idxDir->size[1], 1, &idxDir->size[0], 2,
                                &emlrtECI, &c_st);
  for (j = 0; j < k; j++) {
    idxA_data[j + idxA->size[0]] = idxDir_data[j];
  }
  emxFree_int16_T(&c_st, &idxDir);
  dv[0] = 0.0;
  dv[1] = 1.0;
  r1 = _mm_loadu_pd(&dv[0]);
  _mm_storeu_pd(&dv1[0],
                _mm_add_pd(_mm_mul_pd(_mm_set1_pd(2.0), _mm_loadu_pd(&pad[0])),
                           _mm_add_pd(_mm_set1_pd(340.0),
                                      _mm_mul_pd(_mm_set1_pd(308.0), r1))));
  if (!(dv1[0] >= 0.0)) {
    emlrtNonNegativeCheckR2012b(dv1[0], &j_emlrtDCI, &st);
  }
  if (!(dv1[1] >= 0.0)) {
    emlrtNonNegativeCheckR2012b(dv1[1], &j_emlrtDCI, &st);
  }
  if (dv1[0] != (int32_T)muDoubleScalarFloor(dv1[0])) {
    emlrtIntegerCheckR2012b(dv1[0], &k_emlrtDCI, &st);
  }
  dv[0] = dv1[0];
  if (dv1[1] != (int32_T)muDoubleScalarFloor(dv1[1])) {
    emlrtIntegerCheckR2012b(dv1[1], &k_emlrtDCI, &st);
  }
  dv[1] = dv1[1];
  r1 = _mm_loadu_pd(&dv[0]);
  _mm_storeu_pd(&varargin_1[0], r1);
  k = a->size[0] * a->size[1];
  a->size[0] = (int32_T)varargin_1[0];
  i1 = (int32_T)varargin_1[1];
  a->size[1] = (int32_T)varargin_1[1];
  emxEnsureCapacity_uint8_T(&st, a, k, &ac_emlrtRTEI);
  a_data = a->data;
  for (j = 0; j < i1; j++) {
    k = a->size[0];
    for (b_i = 0; b_i < k; b_i++) {
      if (b_i + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i, &n_emlrtBCI, &st);
      }
      unnamed_idx_1_tmp = idxA_data[b_i];
      if ((unnamed_idx_1_tmp < 1) || (unnamed_idx_1_tmp > 340)) {
        emlrtDynamicBoundsCheckR2012b(unnamed_idx_1_tmp, 1, 340, &m_emlrtBCI,
                                      &st);
      }
      if ((j + 1 < 1) || (j + 1 > i)) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, i, &o_emlrtBCI, &st);
      }
      if (b_i + 1 > a->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, a->size[0], &p_emlrtBCI, &st);
      }
      if ((j + 1 < 1) || (j + 1 > a->size[1])) {
        emlrtDynamicBoundsCheckR2012b(j + 1, 1, a->size[1], &q_emlrtBCI, &st);
      }
      a_data[b_i + a->size[0] * j] =
          a_tmp[(unnamed_idx_1_tmp + 340 * (idxA_data[j + idxA->size[0]] - 1)) -
                1];
    }
  }
  emxFree_int16_T(&st, &idxA);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void imfilter(lee_regionStackData *SD, const emlrtStack *sp,
              const uint8_T varargin_1[220320],
              const emxArray_real_T *varargin_2, uint8_T b[220320])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack st;
  emxArray_boolean_T *b_conn;
  emxArray_boolean_T *conn;
  emxArray_int32_T *r1;
  emxArray_int32_T *r3;
  emxArray_real_T *a;
  emxArray_real_T *a__2;
  emxArray_real_T *bTmp;
  emxArray_real_T *b_s;
  emxArray_real_T *hcol;
  emxArray_real_T *hrow;
  emxArray_real_T *s;
  emxArray_uint8_T *aTmp;
  real_T startT[2];
  const real_T *varargin_2_data;
  real_T *a__2_data;
  real_T *a_data;
  real_T *bTmp_data;
  real_T *hcol_data;
  real_T *hrow_data;
  real_T *s_data;
  int32_T i;
  int32_T k;
  int32_T *r2;
  uint8_T *aTmp_data;
  boolean_T *conn_data;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  varargin_2_data = varargin_2->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  startT[0] = (real_T)varargin_2->size[0] -
              muDoubleScalarFloor(((real_T)varargin_2->size[0] + 1.0) / 2.0);
  startT[1] = (real_T)varargin_2->size[1] -
              muDoubleScalarFloor(((real_T)varargin_2->size[1] + 1.0) / 2.0);
  if ((varargin_2->size[0] == 0) || (varargin_2->size[1] == 0)) {
    memset(&b[0], 0, 220320U * sizeof(uint8_T));
  } else {
    real_T tol;
    int32_T idx;
    int32_T loop_ub;
    int32_T n;
    int32_T nz;
    boolean_T overflow;
    st.site = &b_emlrtRSI;
    loop_ub = varargin_2->size[0] * varargin_2->size[1];
    emxInit_real_T(&st, &a, 2, &t_emlrtRTEI);
    emxInit_real_T(&st, &a__2, 2, &ab_emlrtRTEI);
    emxInit_real_T(&st, &s, 2, &bb_emlrtRTEI);
    emxInit_real_T(&st, &b_s, 1, &cb_emlrtRTEI);
    emxInit_boolean_T(&st, &conn, 1, &o_emlrtRTEI);
    if (loop_ub >= 289) {
      boolean_T x[2];
      boolean_T exitg1;
      x[0] = (varargin_2->size[0] != 1);
      x[1] = (varargin_2->size[1] != 1);
      overflow = true;
      nz = 0;
      exitg1 = false;
      while ((!exitg1) && (nz < 2)) {
        if (!x[nz]) {
          overflow = false;
          exitg1 = true;
        } else {
          nz++;
        }
      }
      if (overflow) {
        int32_T last;
        b_st.site = &l_emlrtRSI;
        c_st.site = &q_emlrtRSI;
        d_st.site = &r_emlrtRSI;
        if (loop_ub > 2147483646) {
          e_st.site = &s_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }
        b_st.site = &m_emlrtRSI;
        svd(&b_st, varargin_2, a, s, a__2);
        bTmp_data = s->data;
        nz = s->size[0];
        idx = s->size[1];
        for (k = 0; k < idx; k++) {
          for (i = 0; i < nz; i++) {
            bTmp_data[i + nz * k] = bTmp_data[i + s->size[0] * k];
          }
        }
        b_st.site = &n_emlrtRSI;
        diag(&b_st, s, b_s);
        s_data = b_s->data;
        if (varargin_2->size[0] > varargin_2->size[1]) {
          n = varargin_2->size[0];
        } else {
          n = varargin_2->size[1];
        }
        b_st.site = &o_emlrtRSI;
        c_st.site = &lb_emlrtRSI;
        d_st.site = &mb_emlrtRSI;
        e_st.site = &nb_emlrtRSI;
        if (b_s->size[0] < 1) {
          emlrtErrorWithMessageIdR2018a(
              &e_st, &b_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
              "Coder:toolbox:eml_min_or_max_varDimZero", 0);
        }
        f_st.site = &ob_emlrtRSI;
        g_st.site = &pb_emlrtRSI;
        last = b_s->size[0];
        if (b_s->size[0] <= 2) {
          if (b_s->size[0] == 1) {
            tol = s_data[0];
          } else if ((s_data[0] < s_data[1]) ||
                     (muDoubleScalarIsNaN(s_data[0]) &&
                      (!muDoubleScalarIsNaN(s_data[1])))) {
            tol = s_data[1];
          } else {
            tol = s_data[0];
          }
        } else {
          h_st.site = &rb_emlrtRSI;
          if (!muDoubleScalarIsNaN(s_data[0])) {
            idx = 1;
          } else {
            idx = 0;
            i_st.site = &sb_emlrtRSI;
            if (b_s->size[0] > 2147483646) {
              j_st.site = &s_emlrtRSI;
              check_forloop_overflow_error(&j_st);
            }
            nz = 2;
            exitg1 = false;
            while ((!exitg1) && (nz <= last)) {
              if (!muDoubleScalarIsNaN(s_data[nz - 1])) {
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
            h_st.site = &qb_emlrtRSI;
            tol = s_data[idx - 1];
            nz = idx + 1;
            i_st.site = &tb_emlrtRSI;
            overflow =
                ((idx + 1 <= b_s->size[0]) && (b_s->size[0] > 2147483646));
            if (overflow) {
              j_st.site = &s_emlrtRSI;
              check_forloop_overflow_error(&j_st);
            }
            for (k = nz; k <= last; k++) {
              real_T d;
              d = s_data[k - 1];
              if (tol < d) {
                tol = d;
              }
            }
          }
        }
        tol = (real_T)n * tol * 2.2204460492503131E-16;
        b_st.site = &p_emlrtRSI;
        nz = conn->size[0];
        conn->size[0] = b_s->size[0];
        emxEnsureCapacity_boolean_T(&b_st, conn, nz, &u_emlrtRTEI);
        conn_data = conn->data;
        for (k = 0; k < last; k++) {
          conn_data[k] = (s_data[k] > tol);
        }
        c_st.site = &ub_emlrtRSI;
        d_st.site = &vb_emlrtRSI;
        e_st.site = &wb_emlrtRSI;
        nz = conn_data[0];
        f_st.site = &xb_emlrtRSI;
        overflow = (conn->size[0] > 2147483646);
        if (overflow) {
          g_st.site = &s_emlrtRSI;
          check_forloop_overflow_error(&g_st);
        }
        for (k = 2; k <= last; k++) {
          nz += conn_data[k - 1];
        }
        overflow = (nz == 1);
      } else {
        overflow = false;
      }
    } else {
      overflow = false;
    }
    emxInit_uint8_T(sp, &aTmp, &x_emlrtRTEI);
    if (overflow) {
      __m128d r;
      real_T connDimsT[2];
      real_T outSizeT[2];
      real_T padSizeT[2];
      real_T start[2];
      boolean_T tooBig;
      st.site = &c_emlrtRSI;
      padImage(&st, varargin_1, startT, aTmp);
      aTmp_data = aTmp->data;
      st.site = &d_emlrtRSI;
      svd(&st, varargin_2, a, s, a__2);
      a__2_data = a__2->data;
      bTmp_data = s->data;
      a_data = a->data;
      idx = s->size[0];
      nz = s->size[1];
      for (k = 0; k < nz; k++) {
        for (i = 0; i < idx; i++) {
          bTmp_data[i + idx * k] = bTmp_data[i + s->size[0] * k];
        }
      }
      st.site = &e_emlrtRSI;
      diag(&st, s, b_s);
      s_data = b_s->data;
      if (a->size[1] < 1) {
        emlrtDynamicBoundsCheckR2012b(1, 1, a->size[1], &j_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (b_s->size[0] < 1) {
        emlrtDynamicBoundsCheckR2012b(1, 1, b_s->size[0], &i_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      st.site = &f_emlrtRSI;
      if (s_data[0] < 0.0) {
        emlrtErrorWithMessageIdR2018a(
            &st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
            "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
      }
      tol = muDoubleScalarSqrt(s_data[0]);
      emxInit_real_T(sp, &hcol, 1, &p_emlrtRTEI);
      n = a->size[0];
      nz = hcol->size[0];
      hcol->size[0] = a->size[0];
      emxEnsureCapacity_real_T(sp, hcol, nz, &p_emlrtRTEI);
      hcol_data = hcol->data;
      nz = (a->size[0] / 2) << 1;
      idx = nz - 2;
      for (k = 0; k <= idx; k += 2) {
        r = _mm_loadu_pd(&a_data[k]);
        _mm_storeu_pd(&hcol_data[k], _mm_mul_pd(r, _mm_set1_pd(tol)));
      }
      for (k = nz; k < n; k++) {
        hcol_data[k] = a_data[k] * tol;
      }
      if (a__2->size[1] < 1) {
        emlrtDynamicBoundsCheckR2012b(1, 1, a__2->size[1], &h_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (b_s->size[0] < 1) {
        emlrtDynamicBoundsCheckR2012b(1, 1, b_s->size[0], &g_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      st.site = &g_emlrtRSI;
      if (s_data[0] < 0.0) {
        emlrtErrorWithMessageIdR2018a(
            &st, &emlrtRTEI, "Coder:toolbox:ElFunDomainError",
            "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
      }
      emxInit_real_T(sp, &hrow, 2, &s_emlrtRTEI);
      nz = hrow->size[0] * hrow->size[1];
      hrow->size[0] = 1;
      n = a__2->size[0];
      hrow->size[1] = a__2->size[0];
      emxEnsureCapacity_real_T(sp, hrow, nz, &s_emlrtRTEI);
      hrow_data = hrow->data;
      nz = (a__2->size[0] / 2) << 1;
      idx = nz - 2;
      for (k = 0; k <= idx; k += 2) {
        r = _mm_loadu_pd(&a__2_data[k]);
        _mm_storeu_pd(&hrow_data[k], _mm_mul_pd(r, _mm_set1_pd(tol)));
      }
      for (k = nz; k < n; k++) {
        hrow_data[k] = a__2_data[k] * tol;
      }
      nz = a->size[0] * a->size[1];
      a->size[0] = aTmp->size[0];
      a->size[1] = aTmp->size[1];
      emxEnsureCapacity_real_T(sp, a, nz, &t_emlrtRTEI);
      a_data = a->data;
      nz = aTmp->size[0] * aTmp->size[1];
      for (k = 0; k < nz; k++) {
        a_data[k] = aTmp_data[k];
      }
      outSizeT[0] = a->size[0];
      outSizeT[1] = 648.0;
      start[0] = 0.0;
      start[1] = startT[1];
      st.site = &h_emlrtRSI;
      emxInit_boolean_T(&st, &b_conn, 2, &o_emlrtRTEI);
      nz = b_conn->size[0] * b_conn->size[1];
      b_conn->size[0] = 1;
      n = hrow->size[1];
      b_conn->size[1] = hrow->size[1];
      emxEnsureCapacity_boolean_T(&st, b_conn, nz, &o_emlrtRTEI);
      conn_data = b_conn->data;
      for (k = 0; k < n; k++) {
        conn_data[k] = (hrow_data[k] != 0.0);
      }
      idx = 0;
      for (k = 0; k < n; k++) {
        if (conn_data[k]) {
          idx++;
        }
      }
      emxInit_int32_T(&st, &r1, &v_emlrtRTEI);
      nz = r1->size[0];
      r1->size[0] = idx;
      emxEnsureCapacity_int32_T(&st, r1, nz, &v_emlrtRTEI);
      r2 = r1->data;
      nz = 0;
      for (k = 0; k < n; k++) {
        if (conn_data[k]) {
          r2[nz] = k;
          nz++;
        }
      }
      idx = r1->size[0];
      nz = b_s->size[0];
      b_s->size[0] = r1->size[0];
      emxEnsureCapacity_real_T(&st, b_s, nz, &q_emlrtRTEI);
      s_data = b_s->data;
      for (k = 0; k < idx; k++) {
        if (r2[k] > hrow->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(r2[k], 0, hrow->size[1] - 1,
                                        &d_emlrtBCI, &st);
        }
        s_data[k] = hrow_data[r2[k]];
      }
      b_st.site = &ec_emlrtRSI;
      overflow = ((real_T)r1->size[0] / (real_T)hrow->size[1] > 0.05);
      tooBig = true;
      for (k = 0; k < 2; k++) {
        if ((!tooBig) || ((int32_T)outSizeT[k] <= 65500)) {
          tooBig = false;
        }
      }
      if (overflow && (!tooBig)) {
        overflow = true;
      } else {
        overflow = false;
      }
      c_st.site = &fc_emlrtRSI;
      emxInit_real_T(&c_st, &bTmp, 2, &y_emlrtRTEI);
      nz = bTmp->size[0] * bTmp->size[1];
      bTmp->size[0] = aTmp->size[0];
      bTmp->size[1] = 648;
      emxEnsureCapacity_real_T(&c_st, bTmp, nz, &w_emlrtRTEI);
      bTmp_data = bTmp->data;
      if (overflow) {
        d_st.site = &gc_emlrtRSI;
        padSizeT[0] = a->size[0];
        connDimsT[0] = 1.0;
        padSizeT[1] = a->size[1];
        connDimsT[1] = hrow->size[1];
        ippfilter_real64(&a_data[0], &bTmp_data[0], &outSizeT[0], 2.0,
                         &padSizeT[0], &hrow_data[0], &connDimsT[0], false);
      } else {
        d_st.site = &hc_emlrtRSI;
        padSizeT[0] = a->size[0];
        connDimsT[0] = 1.0;
        padSizeT[1] = a->size[1];
        connDimsT[1] = b_conn->size[1];
        imfilter_real64(&a_data[0], &bTmp_data[0], 2.0, &outSizeT[0], 2.0,
                        &padSizeT[0], &s_data[0], (real_T)r1->size[0],
                        &conn_data[0], 2.0, &connDimsT[0], &start[0], 2.0, true,
                        false);
      }
      emxFree_int32_T(&c_st, &r1);
      emxFree_boolean_T(&c_st, &b_conn);
      emxFree_real_T(&c_st, &hrow);
      start[0] = startT[0];
      start[1] = 0.0;
      st.site = &i_emlrtRSI;
      n = hcol->size[0];
      nz = conn->size[0];
      conn->size[0] = hcol->size[0];
      emxEnsureCapacity_boolean_T(&st, conn, nz, &o_emlrtRTEI);
      conn_data = conn->data;
      for (k = 0; k < n; k++) {
        conn_data[k] = (hcol_data[k] != 0.0);
      }
      idx = 0;
      for (k = 0; k < n; k++) {
        if (conn_data[k]) {
          idx++;
        }
      }
      emxInit_int32_T(&st, &r3, &v_emlrtRTEI);
      nz = r3->size[0];
      r3->size[0] = idx;
      emxEnsureCapacity_int32_T(&st, r3, nz, &v_emlrtRTEI);
      r2 = r3->data;
      nz = 0;
      for (k = 0; k < n; k++) {
        if (conn_data[k]) {
          r2[nz] = k;
          nz++;
        }
      }
      idx = r3->size[0];
      nz = b_s->size[0];
      b_s->size[0] = r3->size[0];
      emxEnsureCapacity_real_T(&st, b_s, nz, &q_emlrtRTEI);
      s_data = b_s->data;
      for (k = 0; k < idx; k++) {
        if (r2[k] > hcol->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(r2[k], 0, hcol->size[0] - 1,
                                        &d_emlrtBCI, &st);
        }
        s_data[k] = hcol_data[r2[k]];
      }
      b_st.site = &ec_emlrtRSI;
      overflow = ((real_T)r3->size[0] / (real_T)hcol->size[0] > 0.05);
      c_st.site = &fc_emlrtRSI;
      if (overflow) {
        d_st.site = &gc_emlrtRSI;
        outSizeT[0] = 340.0;
        padSizeT[0] = bTmp->size[0];
        outSizeT[1] = 648.0;
        padSizeT[1] = 648.0;
        connDimsT[0] = hcol->size[0];
        connDimsT[1] = 1.0;
        ippfilter_real64(&bTmp_data[0], &SD->f0.bTmp[0], &outSizeT[0], 2.0,
                         &padSizeT[0], &hcol_data[0], &connDimsT[0], false);
      } else {
        d_st.site = &hc_emlrtRSI;
        outSizeT[0] = 340.0;
        padSizeT[0] = bTmp->size[0];
        outSizeT[1] = 648.0;
        padSizeT[1] = 648.0;
        connDimsT[0] = conn->size[0];
        connDimsT[1] = 1.0;
        imfilter_real64(&bTmp_data[0], &SD->f0.bTmp[0], 2.0, &outSizeT[0], 2.0,
                        &padSizeT[0], &s_data[0], (real_T)r3->size[0],
                        &conn_data[0], 2.0, &connDimsT[0], &start[0], 2.0, true,
                        false);
      }
      emxFree_int32_T(&c_st, &r3);
      emxFree_real_T(&c_st, &bTmp);
      emxFree_real_T(&c_st, &hcol);
      for (k = 0; k < 220320; k++) {
        uint8_T u;
        tol = muDoubleScalarRound(SD->f0.bTmp[k]);
        if (tol < 256.0) {
          if (tol >= 0.0) {
            u = (uint8_T)tol;
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
      st.site = &j_emlrtRSI;
      padImage(&st, varargin_1, startT, aTmp);
      aTmp_data = aTmp->data;
      nz = a->size[0] * a->size[1];
      a->size[0] = aTmp->size[0];
      a->size[1] = aTmp->size[1];
      emxEnsureCapacity_real_T(sp, a, nz, &n_emlrtRTEI);
      a_data = a->data;
      nz = aTmp->size[0] * aTmp->size[1];
      for (k = 0; k < nz; k++) {
        a_data[k] = aTmp_data[k];
      }
      st.site = &k_emlrtRSI;
      emxInit_boolean_T(&st, &b_conn, 2, &o_emlrtRTEI);
      nz = b_conn->size[0] * b_conn->size[1];
      b_conn->size[0] = varargin_2->size[0];
      b_conn->size[1] = varargin_2->size[1];
      emxEnsureCapacity_boolean_T(&st, b_conn, nz, &o_emlrtRTEI);
      conn_data = b_conn->data;
      for (k = 0; k < loop_ub; k++) {
        conn_data[k] = (varargin_2_data[k] != 0.0);
      }
      overflow = ((varargin_2->size[0] == 1) || (varargin_2->size[1] == 1));
      if (overflow) {
        idx = 0;
        for (k = 0; k < loop_ub; k++) {
          if (conn_data[k]) {
            idx++;
          }
        }
        nz = b_s->size[0];
        b_s->size[0] = idx;
        emxEnsureCapacity_real_T(&st, b_s, nz, &q_emlrtRTEI);
        s_data = b_s->data;
        nz = 0;
        for (k = 0; k < loop_ub; k++) {
          if (conn_data[k]) {
            if (k > loop_ub - 1) {
              emlrtDynamicBoundsCheckR2012b(k, 0, loop_ub - 1, &f_emlrtBCI,
                                            &st);
            }
            s_data[nz] = varargin_2_data[k];
            nz++;
          }
        }
      } else {
        b_st.site = &ic_emlrtRSI;
        indexShapeCheck(&b_st, varargin_2->size, b_conn->size);
        idx = 0;
        for (k = 0; k < loop_ub; k++) {
          if (conn_data[k]) {
            idx++;
          }
        }
        nz = b_s->size[0];
        b_s->size[0] = idx;
        emxEnsureCapacity_real_T(&st, b_s, nz, &r_emlrtRTEI);
        s_data = b_s->data;
        nz = 0;
        for (k = 0; k < loop_ub; k++) {
          if (conn_data[k]) {
            if (k > loop_ub - 1) {
              emlrtDynamicBoundsCheckR2012b(k, 0, loop_ub - 1, &e_emlrtBCI,
                                            &st);
            }
            s_data[nz] = varargin_2_data[k];
            nz++;
          }
        }
      }
      b_st.site = &ec_emlrtRSI;
      overflow = ((real_T)b_s->size[0] / (real_T)loop_ub > 0.05);
      c_st.site = &fc_emlrtRSI;
      if (overflow) {
        real_T connDimsT[2];
        real_T outSizeT[2];
        real_T padSizeT[2];
        d_st.site = &gc_emlrtRSI;
        outSizeT[0] = 340.0;
        padSizeT[0] = a->size[0];
        connDimsT[0] = varargin_2->size[0];
        outSizeT[1] = 648.0;
        padSizeT[1] = a->size[1];
        connDimsT[1] = varargin_2->size[1];
        ippfilter_real64(&a_data[0], &SD->f0.bTmp[0], &outSizeT[0], 2.0,
                         &padSizeT[0], &varargin_2_data[0], &connDimsT[0],
                         false);
      } else {
        real_T connDimsT[2];
        real_T outSizeT[2];
        real_T padSizeT[2];
        d_st.site = &hc_emlrtRSI;
        outSizeT[0] = 340.0;
        padSizeT[0] = a->size[0];
        connDimsT[0] = b_conn->size[0];
        outSizeT[1] = 648.0;
        padSizeT[1] = a->size[1];
        connDimsT[1] = b_conn->size[1];
        imfilter_real64(&a_data[0], &SD->f0.bTmp[0], 2.0, &outSizeT[0], 2.0,
                        &padSizeT[0], &s_data[0], (real_T)b_s->size[0],
                        &conn_data[0], 2.0, &connDimsT[0], &startT[0], 2.0,
                        true, false);
      }
      emxFree_boolean_T(&c_st, &b_conn);
      for (k = 0; k < 220320; k++) {
        uint8_T u;
        tol = muDoubleScalarRound(SD->f0.bTmp[k]);
        if (tol < 256.0) {
          if (tol >= 0.0) {
            u = (uint8_T)tol;
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
    emxFree_boolean_T(sp, &conn);
    emxFree_real_T(sp, &b_s);
    emxFree_real_T(sp, &s);
    emxFree_real_T(sp, &a__2);
    emxFree_real_T(sp, &a);
    emxFree_uint8_T(sp, &aTmp);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (imfilter.c) */
