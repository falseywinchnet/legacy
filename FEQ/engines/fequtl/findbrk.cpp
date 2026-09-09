#include "callbacks.hpp"
/* findbrk.f -- translated by f2c (version 20240504).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "common.hpp"
#ifdef __cplusplus
extern "C" {
#endif
#include "f2c.h"

/* Common Block Declarations */

/* COMMON good_brk__ is declared in common.hpp. */

#define feq_gen_good_brk_d_1 feq_gen_good_brk_d_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;

/*     *********** */
/*     *         * */
/*     * RATIOPNT */
/*     *         * */
/*     *********** */
/* SOURCE findbrk.for:7 */
/*<       subroutineratiopnt(n,a,b,tau) >*/
/* Subroutine */ int ratiopnt_(integer *n, doublereal *a, doublereal *b, 
	doublereal *feq_storage_tau)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    double log(doublereal), exp(doublereal);

    /* Local variables */
    integer j;
    doublereal feq_gen_r_d_;

/*     + + + PURPOSE + + + */
/*     Compute distribution of points that have a constant ratio. */
/* SOURCE findbrk.for:13 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE findbrk.for:16 */
/*<       integern >*/
/* SOURCE findbrk.for:18 */
/*<       real*8a,b,tau(n) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     N - number of points */
/*     A - lower limit of point range */
/*     B - upper limit of point range */
/*     TAU- sequence of points having a constant ratio. */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE findbrk.for:27 */
/*<       integerj >*/
/* SOURCE findbrk.for:29 */
/*<       real*8r >*/
/* *********************************************************************** */
/* SOURCE findbrk.for:32 */
/*<       r=exp(log(b/a)/dble(n-1)) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> tau(feq_storage_tau, 1);

    /* Function Body */
    feq_gen_r_d_ = exp(log(*b / *a) / (doublereal) (*n - 1));
/* SOURCE findbrk.for:33 */
/*<       tau(1)=a >*/
    tau[1] = *a;
/* SOURCE findbrk.for:34 */
/*<       do100j=2,n-1 >*/
    feq_gen_i_d_1 = *n - 1;
    for (j = 2; j <= feq_gen_i_d_1; ++j) {
/* SOURCE findbrk.for:35 */
/*<       tau(j)=tau(j-1)*r >*/
	tau[j] = tau[j - 1] * feq_gen_r_d_;
/* SOURCE findbrk.for:36 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE findbrk.for:37 */
/*<       tau(n)=b >*/
    tau[*n] = *b;
/* SOURCE findbrk.for:38 */
/*<       return >*/
    return 0;
/* SOURCE findbrk.for:39 */
/*<       end >*/
} /* ratiopnt_ */

/*     *********** */
/*     *         * */
/*     * CUBIC_XPLINE_LOOKUP */
/*     *         * */
/*     *********** */
/* SOURCE findbrk.for:47 */
/*<        >*/
/* Subroutine */ int feq_gen_cubic_spline_lookup_d_(doublereal *arg, integer *n, 
	doublereal *feq_storage_xvec, doublereal *feq_storage_fvec, doublereal *feq_storage_fpvec, doublereal *
	feq_storage_fppvec, integer *last, doublereal *f, doublereal *fp, doublereal *fpp)
{
    integer l;
    doublereal p, dx, fpl, fppl, halfdx;

/*     + + + PURPOSE + + + */
/*     Lookup an argument, ARG, in a cubic spline and return the */
/*     function value, first derivative, and second derivative. */
/*     We assume that FPVEC and FPPVEC have been computed properly. */
/* SOURCE findbrk.for:56 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE findbrk.for:59 */
/*<       integern,last >*/
/* SOURCE findbrk.for:61 */
/*<       real*8arg,xvec(n),fvec(n),fpvec(n),fppvec(n),f,fp,fpp >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ARG - argument at which values are to be found */
/*     N - number of breakpoints for cubic spline */
/*     XVEC - breakpoint argument sequence */
/*     FVEC - function value at breakpoints */
/*     FPVEC - first derivative values at breakpoints */
/*     FPPVEC - second derivative values at breakpoints */
/*     LAST - index to the breakpoint at the left of the */
/*            last breakpoint interval, panel, found on */
/*            previous call. */
/*     F - function value at ARG */
/*     FP - derivative value at ARG */
/*     FPP - second derivative value at ARG */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE findbrk.for:79 */
/*<       integerl >*/
/* SOURCE findbrk.for:80 */
/*<       real*8dx,halfdx,fpl,fppl,p >*/
/* *********************************************************************** */
/* SOURCE findbrk.for:82 */
/*<       l=last >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> fppvec(feq_storage_fppvec, 1);

    feq::IndexedPointer<doublereal> fpvec(feq_storage_fpvec, 1);

    feq::IndexedPointer<doublereal> fvec(feq_storage_fvec, 1);

    feq::IndexedPointer<doublereal> xvec(feq_storage_xvec, 1);

    /* Function Body */
    l = *last;
/*     Find the interval that contains the argument.  Assume well-behaved */
/*     calls, that is no checking for being outside of range. */
/* SOURCE findbrk.for:86 */
/*<       if(arg.ge.xvec(l))then >*/
    if (*arg >= xvec[l]) {
/* SOURCE findbrk.for:87 */
/*<   100 continue >*/
L100:
/* SOURCE findbrk.for:88 */
/*<       if(arg.gt.xvec(l+1))then >*/
	if (*arg > xvec[l + 1]) {
/* SOURCE findbrk.for:89 */
/*<       l=l+1 >*/
	    ++l;
/* SOURCE findbrk.for:90 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE findbrk.for:91 */
/*<       endif >*/
	}
/* SOURCE findbrk.for:92 */
/*<       else >*/
    } else {
/* SOURCE findbrk.for:93 */
/*<   200 continue >*/
L200:
/* SOURCE findbrk.for:94 */
/*<       l=l-1 >*/
	--l;
/* SOURCE findbrk.for:95 */
/*<       if(arg.lt.xvec(l))goto200 >*/
	if (*arg < xvec[l]) {
	    goto L200;
	}
/* SOURCE findbrk.for:96 */
/*<       endif >*/
    }
/* SOURCE findbrk.for:98 */
/*<       last=l >*/
    *last = l;
/*     L should point to the left end of the interval containing ARG. */
/* SOURCE findbrk.for:101 */
/*<       dx=arg-xvec(l) >*/
    dx = *arg - xvec[l];
/* SOURCE findbrk.for:102 */
/*<       halfdx=0.5*dx >*/
    halfdx = dx * (float).5;
/* SOURCE findbrk.for:103 */
/*<       p=dx/(xvec(l+1)-xvec(l)) >*/
    p = dx / (xvec[l + 1] - xvec[l]);
/* SOURCE findbrk.for:104 */
/*<       fpl=fpvec(l) >*/
    fpl = fpvec[l];
/* SOURCE findbrk.for:105 */
/*<       fppl=fppvec(l) >*/
    fppl = fppvec[l];
/* SOURCE findbrk.for:107 */
/*<       fpp=fppl+p*(fppvec(l+1)-fppl) >*/
    *fpp = fppl + p * (fppvec[l + 1] - fppl);
/* SOURCE findbrk.for:108 */
/*<       fp=fpl+halfdx*(fppl+fpp) >*/
    *fp = fpl + halfdx * (fppl + *fpp);
/* SOURCE findbrk.for:109 */
/*<       f=fvec(l)+halfdx*(fpl+fp-halfdx*(fpp-fppl)/3.d0) >*/
    *f = fvec[l] + halfdx * (fpl + *fp - halfdx * (*fpp - fppl) / 3.);
/* SOURCE findbrk.for:110 */
/*<       return >*/
    return 0;
/* SOURCE findbrk.for:111 */
/*<       end >*/
} /* cubic_spline_lookup__ */

/*     *********** */
/*     *         * */
/*     * PARABOLIC_SPLINE_LOOKUP */
/*     *         * */
/*     *********** */
/* SOURCE findbrk.for:119 */
/*<       subroutineparabolic_spline_lookup(arg,n,xvec,fvec,fpvec,last,f,fp) >*/
/* Subroutine */ int feq_gen_parabolic_spline_lookup_d_(doublereal *arg, integer *n, 
	doublereal *feq_storage_xvec, doublereal *feq_storage_fvec, doublereal *feq_storage_fpvec, integer *last, 
	doublereal *f, doublereal *fp)
{
    integer l;
    doublereal p, dx, fpl, halfdx;

/*     + + + PURPOSE + + + */
/*     Lookup an argument, ARG, in a parabolic spline and return the */
/*     function value, and first derivative */
/*     We assume that FPVEC  have been computed properly. */
/* SOURCE findbrk.for:128 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE findbrk.for:131 */
/*<       integern,last >*/
/* SOURCE findbrk.for:133 */
/*<       real*8arg,xvec(n),fvec(n),fpvec(n),f,fp >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ARG - argument at which values are to be found */
/*     N - number of breakpoints for cubic spline */
/*     XVEC - breakpoint argument sequence */
/*     FVEC - function value at breakpoints */
/*     FPVEC - first derivative values at breakpoints */
/*     LAST - index to the breakpoint at the left of the */
/*            last breakpoint interval, panel, found on */
/*            previous call. */
/*     F - function value at ARG */
/*     FP - derivative value at ARG */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE findbrk.for:148 */
/*<       integerl >*/
/* SOURCE findbrk.for:149 */
/*<       real*8dx,halfdx,fpl,p >*/
/* *********************************************************************** */
/* SOURCE findbrk.for:151 */
/*<       l=last >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> fpvec(feq_storage_fpvec, 1);

    feq::IndexedPointer<doublereal> fvec(feq_storage_fvec, 1);

    feq::IndexedPointer<doublereal> xvec(feq_storage_xvec, 1);

    /* Function Body */
    l = *last;
/*     Find the interval that contains the argument.  Assume well-behaved */
/*     calls. */
/* SOURCE findbrk.for:155 */
/*<       if(arg.ge.xvec(l))then >*/
    if (*arg >= xvec[l]) {
/* SOURCE findbrk.for:156 */
/*<   100 continue >*/
L100:
/* SOURCE findbrk.for:157 */
/*<       if(arg.gt.xvec(l+1))then >*/
	if (*arg > xvec[l + 1]) {
/* SOURCE findbrk.for:158 */
/*<       l=l+1 >*/
	    ++l;
/* SOURCE findbrk.for:159 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE findbrk.for:160 */
/*<       endif >*/
	}
/* SOURCE findbrk.for:161 */
/*<       else >*/
    } else {
/* SOURCE findbrk.for:162 */
/*<   200 continue >*/
L200:
/* SOURCE findbrk.for:163 */
/*<       l=l-1 >*/
	--l;
/* SOURCE findbrk.for:164 */
/*<       if(arg.lt.xvec(l))goto200 >*/
	if (*arg < xvec[l]) {
	    goto L200;
	}
/* SOURCE findbrk.for:165 */
/*<       endif >*/
    }
/* SOURCE findbrk.for:167 */
/*<       last=l >*/
    *last = l;
/*     L should point to the left end of the interval containing ARG. */
/* SOURCE findbrk.for:170 */
/*<       dx=arg-xvec(l) >*/
    dx = *arg - xvec[l];
/* SOURCE findbrk.for:171 */
/*<       halfdx=0.5*dx >*/
    halfdx = dx * (float).5;
/* SOURCE findbrk.for:172 */
/*<       p=dx/(xvec(l+1)-xvec(l)) >*/
    p = dx / (xvec[l + 1] - xvec[l]);
/* SOURCE findbrk.for:173 */
/*<       fpl=fpvec(l) >*/
    fpl = fpvec[l];
/* SOURCE findbrk.for:175 */
/*<       fp=fpl+p*(fpvec(l+1)-fpl) >*/
    *fp = fpl + p * (fpvec[l + 1] - fpl);
/* SOURCE findbrk.for:176 */
/*<       f=fvec(l)+halfdx*(fpl+fp) >*/
    *f = fvec[l] + halfdx * (fpl + *fp);
/* SOURCE findbrk.for:177 */
/*<       return >*/
    return 0;
/* SOURCE findbrk.for:178 */
/*<       end >*/
} /* parabolic_spline_lookup__ */

/*     *********** */
/*     *         * */
/*     * LINEAR_SPLINE_LOOKUP */
/*     *         * */
/*     *********** */
/* SOURCE findbrk.for:187 */
/*<       subroutinelinear_spline_lookup(arg,n,xvec,fvec,last,f) >*/
/* Subroutine */ int feq_gen_linear_spline_lookup_d_(doublereal *arg, integer *n, 
	doublereal *feq_storage_xvec, doublereal *feq_storage_fvec, integer *last, doublereal *f)
{
    integer l;
    doublereal p, fl, dx;

/*     + + + PURPOSE + + + */
/*     Lookup an argument, ARG, in a linear spline and return the */
/*     function value. */
/* SOURCE findbrk.for:195 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE findbrk.for:198 */
/*<       integern,last >*/
/* SOURCE findbrk.for:200 */
/*<       real*8arg,xvec(n),fvec(n),f >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ARG - argument at which values are to be found */
/*     N - number of breakpoints for cubic spline */
/*     XVEC - breakpoint argument sequence */
/*     FVEC - function value at breakpoints */
/*     LAST - index to the breakpoint at the left of the */
/*            last breakpoint interval, panel, found on */
/*            previous call. */
/*     F - function value at ARG */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE findbrk.for:213 */
/*<       integerl >*/
/* SOURCE findbrk.for:214 */
/*<       real*8dx,fl,p >*/
/* *********************************************************************** */
/* SOURCE findbrk.for:216 */
/*<       l=last >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> fvec(feq_storage_fvec, 1);

    feq::IndexedPointer<doublereal> xvec(feq_storage_xvec, 1);

    /* Function Body */
    l = *last;
/*     Find the interval that contains the argument.  Assume well-behaved */
/*     calls. */
/* SOURCE findbrk.for:220 */
/*<       if(arg.ge.xvec(l))then >*/
    if (*arg >= xvec[l]) {
/* SOURCE findbrk.for:221 */
/*<   100 continue >*/
L100:
/* SOURCE findbrk.for:222 */
/*<       if(arg.gt.xvec(l+1))then >*/
	if (*arg > xvec[l + 1]) {
/* SOURCE findbrk.for:223 */
/*<       l=l+1 >*/
	    ++l;
/* SOURCE findbrk.for:224 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE findbrk.for:225 */
/*<       endif >*/
	}
/* SOURCE findbrk.for:226 */
/*<       else >*/
    } else {
/* SOURCE findbrk.for:227 */
/*<   200 continue >*/
L200:
/* SOURCE findbrk.for:228 */
/*<       l=l-1 >*/
	--l;
/* SOURCE findbrk.for:229 */
/*<       if(arg.lt.xvec(l))goto200 >*/
	if (*arg < xvec[l]) {
	    goto L200;
	}
/* SOURCE findbrk.for:230 */
/*<       endif >*/
    }
/* SOURCE findbrk.for:232 */
/*<       last=l >*/
    *last = l;
/*     L should point to the left end of the interval containing ARG. */
/* SOURCE findbrk.for:235 */
/*<       dx=arg-xvec(l) >*/
    dx = *arg - xvec[l];
/* SOURCE findbrk.for:236 */
/*<       p=dx/(xvec(l+1)-xvec(l)) >*/
    p = dx / (xvec[l + 1] - xvec[l]);
/* SOURCE findbrk.for:237 */
/*<       fl=fvec(l) >*/
    fl = fvec[l];
/* SOURCE findbrk.for:239 */
/*<       f=fl+p*(fvec(l+1)-fl) >*/
    *f = fl + p * (fvec[l + 1] - fl);
/* SOURCE findbrk.for:240 */
/*<       return >*/
    return 0;
/* SOURCE findbrk.for:241 */
/*<       end >*/
} /* linear_spline_lookup__ */


/*     *********** */
/*     *         * */
/*     * FIND_FPP */
/*     *         * */
/*     *********** */
/* SOURCE findbrk.for:249 */
/*<       subroutinefind_fpp(n,x,f,fp,fpp) >*/
/* Subroutine */ int feq_gen_find_fpp_d_(integer *n, doublereal *feq_storage_x, doublereal *feq_storage_f, 
	doublereal *feq_storage_fp, doublereal *feq_storage_fpp)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    doublereal feq_gen_h_d_;
    integer j;

/*     + + + PURPOSE + + + */
/*     Compute the second derivative at the breakpoints of a cubic */
/*     spline given the first derivatives. */
/* SOURCE findbrk.for:256 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE findbrk.for:259 */
/*<       integern >*/
/* SOURCE findbrk.for:260 */
/*<       real*8x(n),f(n),fp(n),fpp(n) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     N - number breakpoints in the cubic spline */
/*     X - breakpoint sequence */
/*     F - function sequence */
/*     FP - derivative sequence */
/*     FPP - second derivative sequence */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE findbrk.for:270 */
/*<       integerj >*/
/* SOURCE findbrk.for:271 */
/*<       real*8h >*/
/* ******************************************************************* */
/*     Do all but last point using the panel to the right of */
/*     each point. */
/* SOURCE findbrk.for:275 */
/*<       do100j=1,n-1 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> fpp(feq_storage_fpp, 1);

    feq::IndexedPointer<doublereal> fp(feq_storage_fp, 1);

    feq::IndexedPointer<doublereal> f(feq_storage_f, 1);

    feq::IndexedPointer<doublereal> x(feq_storage_x, 1);

    /* Function Body */
    feq_gen_i_d_1 = *n - 1;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE findbrk.for:276 */
/*<       h=x(j+1)-x(j) >*/
	feq_gen_h_d_ = x[j + 1] - x[j];
/* SOURCE findbrk.for:277 */
/*<       fpp(j)=(6.*(f(j+1)-f(j))/h-4.*fp(j)-2.*fp(j+1))/h >*/
	fpp[j] = ((f[j + 1] - f[j]) * (float)6. / feq_gen_h_d_ - fp[j] * (float)4. - 
		fp[j + 1] * (float)2.) / feq_gen_h_d_;
/* SOURCE findbrk.for:278 */
/*<   100 continue >*/
/* L100: */
    }
/*     Do last point using the panel to the left of that point. */
/*     Note that the value of H is valid here. */
/* SOURCE findbrk.for:281 */
/*<       fpp(n)=(2.*fp(n-1)+4.*fp(n)-6.*(f(n)-f(n-1))/h)/h >*/
    fpp[*n] = (fp[*n - 1] * (float)2. + fp[*n] * (float)4. - (f[*n] - f[*n - 
	    1]) * (float)6. / feq_gen_h_d_) / feq_gen_h_d_;
/* SOURCE findbrk.for:282 */
/*<       return >*/
    return 0;
/* SOURCE findbrk.for:283 */
/*<       end >*/
} /* find_fpp__ */

/*     *********** */
/*     *         * */
/*     * LOOKUP_IG */
/*     *         * */
/*     *********** */
/* SOURCE findbrk.for:291 */
/*<       real*8functionlookup_ig(arg) >*/
doublereal feq_gen_lookup_ig_d_(doublereal *arg)
{
    /* System generated locals */
    doublereal ret_val;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    doublereal f, g;
    integer k, l;
    doublereal p, feq_gen_halfdx_cs_d_, fp, fpl, fpp, fppl, feq_gen_dx_cs_d_, feq_gen_dx_qd_d_, feq_gen_arg_qd_d_;

/*     + + + PURPOSE + + + */
/*     Lookup the indefinite integral computed using the mid-point */
/*     rule on the integrand, G, where G is computed from the */
/*     cubic-spline fit to a series of points describing the */
/*     function values. */
/* SOURCE findbrk.for:299 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE findbrk.for:302 */
/*<       real*8arg >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ARG - argument for the lookup */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE findbrk.for:308 */
/*     DEFINITION OF PARAMETERS USED TO SET SIZE OF ARRAYS AND VECTORS */
/*     IN FEQ AND FEQUTL.  THIS FILE MUST BE INCLUDED IF ANY ARRAYS */
/*     OR VECTORS ARE BEING DECLARED IN A PROGRAM UNIT. */

/* SHARED PARAMETERS BETWEEN FEQ AND FEQUTL */
/* SOURCE arsize.prm:7 */
/*<        >*/
/* SOURCE arsize.prm:10 */
/*<       parameter(mnbra=2200,mextra=4000) >*/
/* SOURCE arsize.prm:11 */
/*<        >*/

/* FEQ SPECIFIC PARAMETERS */
/* SOURCE arsize.prm:17 */
/*<        >*/
/* SOURCE arsize.prm:19 */
/*<        >*/
/* SOURCE arsize.prm:24 */
/*<        >*/
/* SOURCE arsize.prm:26 */
/*<       integermxn_irrig >*/
/* SOURCE arsize.prm:27 */
/*<       integerdptsf_rec_at_frst_ts_pnt,dptsf_rec_at_lkup_tab_start >*/
/* SOURCE arsize.prm:28 */
/*<        >*/
/* SOURCE arsize.prm:30 */
/*<       parameter(mnfree=4000) >*/
/* SOURCE arsize.prm:31 */
/*<       parameter(mnex=2*mnbra+mnfree) >*/
/* SOURCE arsize.prm:32 */
/*<        >*/
/* SOURCE arsize.prm:42 */
/*<        >*/
/* SOURCE arsize.prm:45 */
/*<        >*/
/* SOURCE arsize.prm:51 */
/*<       parameter(mxn_irrig=mnbra+mnfree/2) >*/

/* FEQUTL SPECIFIC PARAMETERS */
/* SOURCE arsize.prm:54 */
/*<        >*/
/* SOURCE arsize.prm:59 */
/*<        >*/
/*     TA_UNITS_PER_BRANCH - gives the assumed average number of */
/*       tributary area units per branch.  A unit is any collection */
/*       of tributrary areas flowing into a contiguous series of */
/*       computational elements on a branch.  If branch mode of */
/*       tributary input is used then the unit is the tributary */
/*       area for the branch.  If the station mode is used it */
/*       is the tributary area for each station interval.  Finally */
/*       if node mode is used it is the tributary area for a */
/*       single node on the branch.  These are all called */
/*       tributrary area units because the computations treat */
/*       them as a unit in the diffuse runoff calculations */
/*       of runoff amount, effect of detention reservoirs, and */
/*       effect of delay reservoirs. */
/*     MXR_TRIBA - maximum number of rows given to the TRIBA array. */
/*                 This is also the max number of trib-area units. */
/*     MXN_DTEN  - maximum number of detention reservoirs */
/*     MXN_DLAY  - maximum number of delay reservoirs */
/*     TAM_MXNI  - maximum number of entries in TAM_ITAB, the */
/*                 tributary area management integer vector. */
/*     TAM_MXNF  - maximum number of entries in TAM_FTAB, the */
/*                 tributrary area management floating point vector. */
/*     MNGATE- maximum number of gates/pumps for output of special values to */
/*             the special output file. */
/*     MNSPROW-maximum number of extra rows allowed in special output. */
/*             There are always 2 rows by default.  The rows defined */
/*             by this parameter are in addition to the original 2 */
/*             rows. */
/*     MXN_TS -maximum number of unique time-series references allowed. */
/*             The same time series may appear more than once but is */
/*             only counted once for MXN_TS accounting. */
/*     MXN_TS - maximum number of unique time-series allowed. */
/*              Excludes those involved in the diffuse inflow */
/*              computations.  Counts time series from files */
/*              as well as from function tables.  Each time */
/*              series is counted only once even if it is */
/*              used in more than one location.  In other words, */
/*              MXN_TS counts the number of unique sources for */
/*              time-series data.  The number of destinations, */
/*              that is, locations in the model, where a time */
/*              series of any kind is used, is counted  within */
/*              MXN_DEST. */

/*     MXN_DEST-maximum number of time-series destinations counting any */
/*              duplicates. Those counted are those that have */
/*              destinations of forced boundary, evaporation on */
/*              water surfaces, precipitation on water surfaces, */
/*              and others yet to come that will be attached at */
/*              various points in a FEQ model. */
/*     MXN_LU_G - maximum number of land uses per gage. */
/*     MXN_IRRIG -maximum number of tributary-area units supporting */
/*                irrigation withdrawals.  This will be set to */
/*                the sum of the number of branches plus one-half */
/*                number of free nodes. */
/*     MAXCMD- maximum number of commands for FEQUTL. */
/*     MCDT10- maximum number of columns in a 2-D table of type 10 */
/*     MRDT10- maximum number of rows in a 2-D table of type 10 */
/*             (used in INV_GATE to size 2-D arrays) */
/*     MFTNUM- same as PMXTAB- maximum table number */
/*     MNBN- maximum number of nodes on a culvert barrel in */
/*           the culvert command. */
/*     MNDEP- maximum number of depth values in an interpolated */
/*            cross section. */
/*     MNMID- maximum number of cross sections interpolated between */
/*            known cross sections. */
/*     MRFTAB- maximum row in function table.  Gives the */
/*             size of the vectors used to store function tables. */
/* 					This value should be an odd integer.  We declare the */
/*             single-precision vectors from 0.  Thus we need */
/* 					an even number of total elements to match exactly */
/*             the double-precision vector.  Example:  Take */
/*             MRFTAB to be 1001.  We allocate with (0:MRFTAB). */
/*             Thus there are 1002 4-byte reals and integers in */
/*             the function-table system.  To match exactly we need */
/*             501 8-byte values.  Since we allocate with the zero */
/*             element as well, we then have MDFTAB = (MRFTAB -1)/2 */
/* 	MDFTAB- maximum row in the double-precision part of the function-table */
/*             system= (MRFTAB -1)/2 */
/*     PMXELM- maximum number of cross section elements in an */
/*             internal table. */
/*     PMXFRC- maximum number of fractions of free drop or free */
/*             flow for computing two-D tables. */
/*     PMXNFL- maximum number of flow lines when defining */
/*             curvilinear elements. */
/*     PMXNHG- maximum number of gate openings for an underflow */
/*             gate.  Defines the maximum number of 2-D tables */
/*             of type 13 that appear in a table of type 15. */
/*     PMXNHU- maximu number of upstream or dnstream heads for */
/*             computing two-D tables. */
/*     PMXNIG- size of vectors used in computing the indefinite */
/*            integral of the breakpoint density when finding */
/*            optimum tables. */
/*     PMXOFF- maximum number of offsets for profile of an embankment */
/*             in EMBANKQ */
/*     PMXPNT- maximum number of points in a cross section. */
/*     PMXSEC- maximum number of cross sections in the function */
/*             table. */
/*     PMXSUB- maximum number of subsection in a cross section. */
/*     PMXTAB- maximum table number. */
/*     TDTIOFF- two-d table initial offset.  The offset of the */
/*              first value in the "body" of the table.  Made the */
/*              same for all two-d tables.  As of 7 march 2003 */
/*              these are 10, 13, 14, and 43.  We may be adding */
/*              40, and 44 in the near future. */
/*     XSCOML- length in 4-byte words of the common blocks for */
/*             cross sections. */
/*     XTIOFF- cross section table initial offset.  The offset */
/*             of the first value in the body of the table. */
/*     MRRBUF- size of the read buffer for all point time series */
/*             files attached to a model. */
/*     NPSLOT - number of points to use in interpolation for */
/*              cross section tables in any bottom slot. */
/* INCLUDE findbrk.for:309 */
/* SOURCE goodbrk.cmn:1 */
/*<       integern_qd,ig_last,qd_pnt(pmxnig) >*/
/* SOURCE goodbrk.cmn:3 */
/*<        >*/
/* SOURCE goodbrk.cmn:6 */
/*<        >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE findbrk.for:312 */
/*<       integerl,k >*/
/* SOURCE findbrk.for:313 */
/*<       real*8dx_cs,halfdx_cs,fpl,fppl,p,f,fp,fpp,arg_qd,dx_qd,g >*/
/* *********************************************************************** */
/* SOURCE findbrk.for:316 */
/*<       l=ig_last >*/
    l = feq_gen_good_brk_d_1.feq_gen_ig_last_d_;
/*     Find the interval that contains the argument.  Assume well-behaved */
/*     calls. */
/* SOURCE findbrk.for:320 */
/*<       if(arg.ge.xvec_qd(l))then >*/
    if (*arg >= feq_gen_good_brk_d_1.feq_gen_xvec_qd_d_[l - 1]) {
/* SOURCE findbrk.for:321 */
/*<   100 continue >*/
L100:
/* SOURCE findbrk.for:322 */
/*<       if(arg.gt.xvec_qd(l+1))then >*/
	if (*arg > feq_gen_good_brk_d_1.feq_gen_xvec_qd_d_[l]) {
/* SOURCE findbrk.for:323 */
/*<       l=l+1 >*/
	    ++l;
/* SOURCE findbrk.for:324 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE findbrk.for:325 */
/*<       endif >*/
	}
/* SOURCE findbrk.for:326 */
/*<       else >*/
    } else {
/* SOURCE findbrk.for:327 */
/*<   200 continue >*/
L200:
/* SOURCE findbrk.for:328 */
/*<       l=l-1 >*/
	--l;
/* SOURCE findbrk.for:329 */
/*<       if(arg.lt.xvec_qd(l))goto200 >*/
	if (*arg < feq_gen_good_brk_d_1.feq_gen_xvec_qd_d_[l - 1]) {
	    goto L200;
	}
/* SOURCE findbrk.for:330 */
/*<       endif >*/
    }
/* SOURCE findbrk.for:332 */
/*<       ig_last=l >*/
    feq_gen_good_brk_d_1.feq_gen_ig_last_d_ = l;
/*     L should point to the left end of the interval containing ARG. This is */
/*     in the argument series for the integral, NOT the argument series for */
/*     the cubic spline.  Compute the argument value for the evaluation of */
/*     the integrand. */
/* SOURCE findbrk.for:337 */
/*<       dx_qd=arg-xvec_qd(l) >*/
    feq_gen_dx_qd_d_ = *arg - feq_gen_good_brk_d_1.feq_gen_xvec_qd_d_[l - 1];
/* SOURCE findbrk.for:338 */
/*<       arg_qd=xvec_qd(l)+0.5*dx_qd >*/
    feq_gen_arg_qd_d_ = feq_gen_good_brk_d_1.feq_gen_xvec_qd_d_[l - 1] + feq_gen_dx_qd_d_ * (float).5;
/*     Find the integrand value at ARG_QD.  Get the cubic-spline pointer. */
/* SOURCE findbrk.for:342 */
/*<       k=qd_pnt(l) >*/
    k = feq_gen_good_brk_d_1.feq_gen_qd_pnt_d_[l - 1];
/* SOURCE findbrk.for:343 */
/*<       dx_cs=arg_qd-xvec_cs(k) >*/
    feq_gen_dx_cs_d_ = feq_gen_arg_qd_d_ - feq_gen_good_brk_d_1.feq_gen_xvec_cs_d_[k - 1];
/* SOURCE findbrk.for:344 */
/*<       halfdx_cs=0.5*dx_cs >*/
    feq_gen_halfdx_cs_d_ = feq_gen_dx_cs_d_ * (float).5;
/* SOURCE findbrk.for:345 */
/*<       p=dx_cs/(xvec_cs(k+1)-xvec_cs(k)) >*/
    p = feq_gen_dx_cs_d_ / (feq_gen_good_brk_d_1.feq_gen_xvec_cs_d_[k] - feq_gen_good_brk_d_1.feq_gen_xvec_cs_d_[k - 1]);
/* SOURCE findbrk.for:346 */
/*<       fpl=fpvec(k) >*/
    fpl = feq_gen_good_brk_d_1.fpvec[k - 1];
/* SOURCE findbrk.for:347 */
/*<       fppl=fppvec(k) >*/
    fppl = feq_gen_good_brk_d_1.fppvec[k - 1];
/* SOURCE findbrk.for:349 */
/*<       fpp=fppl+p*(fppvec(k+1)-fppl) >*/
    fpp = fppl + p * (feq_gen_good_brk_d_1.fppvec[k] - fppl);
/* SOURCE findbrk.for:350 */
/*<       fp=fpl+halfdx_cs*(fppl+fpp) >*/
    fp = fpl + feq_gen_halfdx_cs_d_ * (fppl + fpp);
/* SOURCE findbrk.for:351 */
/*<       f=fvec_cs(k)+halfdx_cs*(fpl+fp-halfdx_cs*(fpp-fppl)/3.d0) >*/
    f = feq_gen_good_brk_d_1.feq_gen_fvec_cs_d_[k - 1] + feq_gen_halfdx_cs_d_ * (fpl + fp - feq_gen_halfdx_cs_d_ *
	     (fpp - fppl) / 3.);
/* SOURCE findbrk.for:353 */
/*<       g=sqrt(abs(fpp)/f) >*/
    g = sqrt(abs(fpp) / f);
/* SOURCE findbrk.for:355 */
/*<       lookup_ig=igvec(l)+g*dx_qd >*/
    ret_val = feq_gen_good_brk_d_1.igvec[l - 1] + g * feq_gen_dx_qd_d_;
/* SOURCE findbrk.for:357 */
/*<       return >*/
    return ret_val;
/* SOURCE findbrk.for:358 */
/*<       end >*/
} /* lookup_ig__ */

/*     *********** */
/*     *         * */
/*     * IG_RES */
/*     *         * */
/*     *********** */
/* SOURCE findbrk.for:365 */
/*<       real*8functionig_res(arg) >*/
doublereal feq_gen_ig_res_d_(doublereal *arg)
{
    /* System generated locals */
    doublereal ret_val;

    /* Local variables */
    extern doublereal feq_gen_lookup_ig_d_(doublereal *);

/*     + + + PURPOSE + + + */
/*     Residual function for finding good linear-spline breakpoints */
/* SOURCE findbrk.for:370 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE findbrk.for:373 */
/*<       real*8arg >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ARG - argument for the residual computation */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE findbrk.for:379 */
/*     DEFINITION OF PARAMETERS USED TO SET SIZE OF ARRAYS AND VECTORS */
/*     IN FEQ AND FEQUTL.  THIS FILE MUST BE INCLUDED IF ANY ARRAYS */
/*     OR VECTORS ARE BEING DECLARED IN A PROGRAM UNIT. */

/* SHARED PARAMETERS BETWEEN FEQ AND FEQUTL */
/* SOURCE arsize.prm:7 */
/*<        >*/
/* SOURCE arsize.prm:10 */
/*<       parameter(mnbra=2200,mextra=4000) >*/
/* SOURCE arsize.prm:11 */
/*<        >*/

/* FEQ SPECIFIC PARAMETERS */
/* SOURCE arsize.prm:17 */
/*<        >*/
/* SOURCE arsize.prm:19 */
/*<        >*/
/* SOURCE arsize.prm:24 */
/*<        >*/
/* SOURCE arsize.prm:26 */
/*<       integermxn_irrig >*/
/* SOURCE arsize.prm:27 */
/*<       integerdptsf_rec_at_frst_ts_pnt,dptsf_rec_at_lkup_tab_start >*/
/* SOURCE arsize.prm:28 */
/*<        >*/
/* SOURCE arsize.prm:30 */
/*<       parameter(mnfree=4000) >*/
/* SOURCE arsize.prm:31 */
/*<       parameter(mnex=2*mnbra+mnfree) >*/
/* SOURCE arsize.prm:32 */
/*<        >*/
/* SOURCE arsize.prm:42 */
/*<        >*/
/* SOURCE arsize.prm:45 */
/*<        >*/
/* SOURCE arsize.prm:51 */
/*<       parameter(mxn_irrig=mnbra+mnfree/2) >*/

/* FEQUTL SPECIFIC PARAMETERS */
/* SOURCE arsize.prm:54 */
/*<        >*/
/* SOURCE arsize.prm:59 */
/*<        >*/
/*     TA_UNITS_PER_BRANCH - gives the assumed average number of */
/*       tributary area units per branch.  A unit is any collection */
/*       of tributrary areas flowing into a contiguous series of */
/*       computational elements on a branch.  If branch mode of */
/*       tributary input is used then the unit is the tributary */
/*       area for the branch.  If the station mode is used it */
/*       is the tributary area for each station interval.  Finally */
/*       if node mode is used it is the tributary area for a */
/*       single node on the branch.  These are all called */
/*       tributrary area units because the computations treat */
/*       them as a unit in the diffuse runoff calculations */
/*       of runoff amount, effect of detention reservoirs, and */
/*       effect of delay reservoirs. */
/*     MXR_TRIBA - maximum number of rows given to the TRIBA array. */
/*                 This is also the max number of trib-area units. */
/*     MXN_DTEN  - maximum number of detention reservoirs */
/*     MXN_DLAY  - maximum number of delay reservoirs */
/*     TAM_MXNI  - maximum number of entries in TAM_ITAB, the */
/*                 tributary area management integer vector. */
/*     TAM_MXNF  - maximum number of entries in TAM_FTAB, the */
/*                 tributrary area management floating point vector. */
/*     MNGATE- maximum number of gates/pumps for output of special values to */
/*             the special output file. */
/*     MNSPROW-maximum number of extra rows allowed in special output. */
/*             There are always 2 rows by default.  The rows defined */
/*             by this parameter are in addition to the original 2 */
/*             rows. */
/*     MXN_TS -maximum number of unique time-series references allowed. */
/*             The same time series may appear more than once but is */
/*             only counted once for MXN_TS accounting. */
/*     MXN_TS - maximum number of unique time-series allowed. */
/*              Excludes those involved in the diffuse inflow */
/*              computations.  Counts time series from files */
/*              as well as from function tables.  Each time */
/*              series is counted only once even if it is */
/*              used in more than one location.  In other words, */
/*              MXN_TS counts the number of unique sources for */
/*              time-series data.  The number of destinations, */
/*              that is, locations in the model, where a time */
/*              series of any kind is used, is counted  within */
/*              MXN_DEST. */

/*     MXN_DEST-maximum number of time-series destinations counting any */
/*              duplicates. Those counted are those that have */
/*              destinations of forced boundary, evaporation on */
/*              water surfaces, precipitation on water surfaces, */
/*              and others yet to come that will be attached at */
/*              various points in a FEQ model. */
/*     MXN_LU_G - maximum number of land uses per gage. */
/*     MXN_IRRIG -maximum number of tributary-area units supporting */
/*                irrigation withdrawals.  This will be set to */
/*                the sum of the number of branches plus one-half */
/*                number of free nodes. */
/*     MAXCMD- maximum number of commands for FEQUTL. */
/*     MCDT10- maximum number of columns in a 2-D table of type 10 */
/*     MRDT10- maximum number of rows in a 2-D table of type 10 */
/*             (used in INV_GATE to size 2-D arrays) */
/*     MFTNUM- same as PMXTAB- maximum table number */
/*     MNBN- maximum number of nodes on a culvert barrel in */
/*           the culvert command. */
/*     MNDEP- maximum number of depth values in an interpolated */
/*            cross section. */
/*     MNMID- maximum number of cross sections interpolated between */
/*            known cross sections. */
/*     MRFTAB- maximum row in function table.  Gives the */
/*             size of the vectors used to store function tables. */
/* 					This value should be an odd integer.  We declare the */
/*             single-precision vectors from 0.  Thus we need */
/* 					an even number of total elements to match exactly */
/*             the double-precision vector.  Example:  Take */
/*             MRFTAB to be 1001.  We allocate with (0:MRFTAB). */
/*             Thus there are 1002 4-byte reals and integers in */
/*             the function-table system.  To match exactly we need */
/*             501 8-byte values.  Since we allocate with the zero */
/*             element as well, we then have MDFTAB = (MRFTAB -1)/2 */
/* 	MDFTAB- maximum row in the double-precision part of the function-table */
/*             system= (MRFTAB -1)/2 */
/*     PMXELM- maximum number of cross section elements in an */
/*             internal table. */
/*     PMXFRC- maximum number of fractions of free drop or free */
/*             flow for computing two-D tables. */
/*     PMXNFL- maximum number of flow lines when defining */
/*             curvilinear elements. */
/*     PMXNHG- maximum number of gate openings for an underflow */
/*             gate.  Defines the maximum number of 2-D tables */
/*             of type 13 that appear in a table of type 15. */
/*     PMXNHU- maximu number of upstream or dnstream heads for */
/*             computing two-D tables. */
/*     PMXNIG- size of vectors used in computing the indefinite */
/*            integral of the breakpoint density when finding */
/*            optimum tables. */
/*     PMXOFF- maximum number of offsets for profile of an embankment */
/*             in EMBANKQ */
/*     PMXPNT- maximum number of points in a cross section. */
/*     PMXSEC- maximum number of cross sections in the function */
/*             table. */
/*     PMXSUB- maximum number of subsection in a cross section. */
/*     PMXTAB- maximum table number. */
/*     TDTIOFF- two-d table initial offset.  The offset of the */
/*              first value in the "body" of the table.  Made the */
/*              same for all two-d tables.  As of 7 march 2003 */
/*              these are 10, 13, 14, and 43.  We may be adding */
/*              40, and 44 in the near future. */
/*     XSCOML- length in 4-byte words of the common blocks for */
/*             cross sections. */
/*     XTIOFF- cross section table initial offset.  The offset */
/*             of the first value in the body of the table. */
/*     MRRBUF- size of the read buffer for all point time series */
/*             files attached to a model. */
/*     NPSLOT - number of points to use in interpolation for */
/*              cross section tables in any bottom slot. */
/* INCLUDE findbrk.for:380 */
/* SOURCE goodbrk.cmn:1 */
/*<       integern_qd,ig_last,qd_pnt(pmxnig) >*/
/* SOURCE goodbrk.cmn:3 */
/*<        >*/
/* SOURCE goodbrk.cmn:6 */
/*<        >*/
/*     + + +FUNCTIONS+ + + */
/* SOURCE findbrk.for:383 */
/*<       real*8lookup_ig >*/
/* SOURCE findbrk.for:384 */
/*<       externallookup_ig >*/
/* ********************************************************************** */
/* SOURCE findbrk.for:386 */
/*<       ig_res=(igval-lookup_ig(arg))/igval >*/
    ret_val = (feq_gen_good_brk_d_1.igval - feq_gen_lookup_ig_d_(arg)) / feq_gen_good_brk_d_1.igval;
/* SOURCE findbrk.for:387 */
/*<       return >*/
    return ret_val;
/* SOURCE findbrk.for:388 */
/*<       end >*/
} /* ig_res__ */

/*     *********** */
/*     *         * */
/*     * FIND_GOOD_POINTS */
/*     *         * */
/*     *********** */
/* SOURCE findbrk.for:396 */
/*<        >*/
/* Subroutine */ int feq_gen_find_good_points_d_(integer *stdout, integer *npnts, 
	doublereal *feq_storage_xvec, doublereal *feq_storage_fvec, doublereal *feq_gen_relative_error_d_, 
	doublereal *feq_gen_left_slope_d_, doublereal *feq_gen_right_slope_d_, integer *
	feq_gen_n_good_d_, doublereal *feq_gen_feq_storage_good_points_d_, integer *feq_gen_no_good_d_, doublereal *
	feq_gen_max_rerr_d_)
{
    /* Initialized data */

    static doublereal offset[3] = { .4,.5,.6 };
    static doublereal epsx = 1e-6;
    static doublereal epsf = 1e-5;

    /* Format strings */
    static char fmt_31[] = "(/,\002 *BUG in FIND_GOOD_POINTS: No sign change\
 on entry\002,\002 to FDBLRGF.\002)";
    static char fmt_32[] = "(/,\002 *BUG in FIND_GOOD_POINTS: More than 100 \
iterations\002,\002 in FDBLRGF.\002)";
    static char fmt_33[] = "(/,\002 *BUG in FIND_GOOD_POINTS: Argument colla\
pse with \002,\002residual more than twice EPSF in FDBLRGF.\002)";
    static char fmt_70[] = "(/,\002 *BUG in FIND_GOOD_POINTS: Space for inte\
gral of the\002,\002 breakpoint density exhausted.\002)";
    static char fmt_72[] = "(/,\002 Number of breakpoints=\002,i5,\002 > the\
 maximum allowed=\002,i5,\002.\002,\002 This should not happen and probably \
indicates a\002,/,\002  subtle error at some point.  Make sure that LIPREC is\
\002,\002  greater than 0.005 and NFRAC=60 or more.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal);
    integer do_fio(integer *, char *, ftnlen);

    /* Local variables */
    doublereal feq_gen_interval_length_d_;
    integer feq_gen_n_to_add_d_;
    doublereal feq_gen_delta_ig_d_;
    extern /* Subroutine */ int feq_gen_find_fpp_d_(integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);
    doublereal f, g;
    integer feq_gen_i_d_, j, k;
    doublereal p, fp, dx, xl, xr;
    integer feq_gen_n_good_max_d_;
    doublereal arg, fpl, rfl;
    integer nin;
    doublereal fpp, rfr;
    integer feq_gen_flag_d_;
    doublereal fhat;
    extern /* Subroutine */ int feq_gen_cubic_spline_lookup_d_(doublereal *, integer *,
	     doublereal *, doublereal *, doublereal *, doublereal *, integer *
	    , doublereal *, doublereal *, doublereal *);
    doublereal fppl;
    integer last;
    doublereal rerr, root;
    integer last2;
    extern /* Subroutine */ int feq_gen_linear_spline_lookup_d_(doublereal *, integer *
	    , doublereal *, doublereal *, integer *, doublereal *);
    doublereal xroot, halfdx;
    extern doublereal feq_gen_ig_res_d_(doublereal *);
    extern /* Subroutine */ int spline_(integer *, doublereal *, doublereal *,
	     integer *, integer *, doublereal *, integer *, doublereal *, 
	    doublereal *), fdblrgf_(doublereal *, doublereal *, FeqCallback1, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *);
    doublereal feq_gen_fvec_ls_d_[151];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__42 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__45 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__46 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__47 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__48 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__49 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__50 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__62 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__70 = { 0, 0, 0, fmt_31, 0 };
    static cilist feq_gen_io_d__71 = { 0, 0, 0, fmt_32, 0 };
    static cilist feq_gen_io_d__72 = { 0, 0, 0, fmt_33, 0 };


/*     + + + PURPOSE + + + */
/*     Given a series of arguments and function values, XVEC and FVEC, */
/*     find a sequence of good breakpoints for interpolating */
/*     the function represented by the given values using a linear */
/*     spline and with the target of having an interpolation error */
/*     of no more than RELATIVE_ERROR. */
/* SOURCE findbrk.for:408 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE findbrk.for:411 */
/*<       integernpnts,n_good,no_good,stdout >*/
/* SOURCE findbrk.for:412 */
/*<        >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - standard output unit */
/*     NPNTS - number of values in XVEC and FVEC */
/*     XVEC - series of argument values */
/*     FVEC - function values at arguments in XVEC */
/*     RELATIVE_ERROR - target relative error for linear spline */
/*                      interpolation in the function tabulated */
/*                      in XVEC and FVEC */
/*     LEFT_SLOPE - slope at left end of range */
/*     RIGHT_SLOPE - slope at right end of range */
/*     N_GOOD - number of points in the good sequence */
/*     GOOD_POINTS - the sequence of good breakpoints */
/*     NO_GOOD - error flag. =1 if failure, =0 otherwise */
/*     MAX_RERR - absolute value of the maximum relative error */
/*               in linear interpolation using the GOOD_POINTS */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE findbrk.for:432 */
/*     DEFINITION OF PARAMETERS USED TO SET SIZE OF ARRAYS AND VECTORS */
/*     IN FEQ AND FEQUTL.  THIS FILE MUST BE INCLUDED IF ANY ARRAYS */
/*     OR VECTORS ARE BEING DECLARED IN A PROGRAM UNIT. */

/* SHARED PARAMETERS BETWEEN FEQ AND FEQUTL */
/* SOURCE arsize.prm:7 */
/*<        >*/
/* SOURCE arsize.prm:10 */
/*<       parameter(mnbra=2200,mextra=4000) >*/
/* SOURCE arsize.prm:11 */
/*<        >*/

/* FEQ SPECIFIC PARAMETERS */
/* SOURCE arsize.prm:17 */
/*<        >*/
/* SOURCE arsize.prm:19 */
/*<        >*/
/* SOURCE arsize.prm:24 */
/*<        >*/
/* SOURCE arsize.prm:26 */
/*<       integermxn_irrig >*/
/* SOURCE arsize.prm:27 */
/*<       integerdptsf_rec_at_frst_ts_pnt,dptsf_rec_at_lkup_tab_start >*/
/* SOURCE arsize.prm:28 */
/*<        >*/
/* SOURCE arsize.prm:30 */
/*<       parameter(mnfree=4000) >*/
/* SOURCE arsize.prm:31 */
/*<       parameter(mnex=2*mnbra+mnfree) >*/
/* SOURCE arsize.prm:32 */
/*<        >*/
/* SOURCE arsize.prm:42 */
/*<        >*/
/* SOURCE arsize.prm:45 */
/*<        >*/
/* SOURCE arsize.prm:51 */
/*<       parameter(mxn_irrig=mnbra+mnfree/2) >*/

/* FEQUTL SPECIFIC PARAMETERS */
/* SOURCE arsize.prm:54 */
/*<        >*/
/* SOURCE arsize.prm:59 */
/*<        >*/
/*     TA_UNITS_PER_BRANCH - gives the assumed average number of */
/*       tributary area units per branch.  A unit is any collection */
/*       of tributrary areas flowing into a contiguous series of */
/*       computational elements on a branch.  If branch mode of */
/*       tributary input is used then the unit is the tributary */
/*       area for the branch.  If the station mode is used it */
/*       is the tributary area for each station interval.  Finally */
/*       if node mode is used it is the tributary area for a */
/*       single node on the branch.  These are all called */
/*       tributrary area units because the computations treat */
/*       them as a unit in the diffuse runoff calculations */
/*       of runoff amount, effect of detention reservoirs, and */
/*       effect of delay reservoirs. */
/*     MXR_TRIBA - maximum number of rows given to the TRIBA array. */
/*                 This is also the max number of trib-area units. */
/*     MXN_DTEN  - maximum number of detention reservoirs */
/*     MXN_DLAY  - maximum number of delay reservoirs */
/*     TAM_MXNI  - maximum number of entries in TAM_ITAB, the */
/*                 tributary area management integer vector. */
/*     TAM_MXNF  - maximum number of entries in TAM_FTAB, the */
/*                 tributrary area management floating point vector. */
/*     MNGATE- maximum number of gates/pumps for output of special values to */
/*             the special output file. */
/*     MNSPROW-maximum number of extra rows allowed in special output. */
/*             There are always 2 rows by default.  The rows defined */
/*             by this parameter are in addition to the original 2 */
/*             rows. */
/*     MXN_TS -maximum number of unique time-series references allowed. */
/*             The same time series may appear more than once but is */
/*             only counted once for MXN_TS accounting. */
/*     MXN_TS - maximum number of unique time-series allowed. */
/*              Excludes those involved in the diffuse inflow */
/*              computations.  Counts time series from files */
/*              as well as from function tables.  Each time */
/*              series is counted only once even if it is */
/*              used in more than one location.  In other words, */
/*              MXN_TS counts the number of unique sources for */
/*              time-series data.  The number of destinations, */
/*              that is, locations in the model, where a time */
/*              series of any kind is used, is counted  within */
/*              MXN_DEST. */

/*     MXN_DEST-maximum number of time-series destinations counting any */
/*              duplicates. Those counted are those that have */
/*              destinations of forced boundary, evaporation on */
/*              water surfaces, precipitation on water surfaces, */
/*              and others yet to come that will be attached at */
/*              various points in a FEQ model. */
/*     MXN_LU_G - maximum number of land uses per gage. */
/*     MXN_IRRIG -maximum number of tributary-area units supporting */
/*                irrigation withdrawals.  This will be set to */
/*                the sum of the number of branches plus one-half */
/*                number of free nodes. */
/*     MAXCMD- maximum number of commands for FEQUTL. */
/*     MCDT10- maximum number of columns in a 2-D table of type 10 */
/*     MRDT10- maximum number of rows in a 2-D table of type 10 */
/*             (used in INV_GATE to size 2-D arrays) */
/*     MFTNUM- same as PMXTAB- maximum table number */
/*     MNBN- maximum number of nodes on a culvert barrel in */
/*           the culvert command. */
/*     MNDEP- maximum number of depth values in an interpolated */
/*            cross section. */
/*     MNMID- maximum number of cross sections interpolated between */
/*            known cross sections. */
/*     MRFTAB- maximum row in function table.  Gives the */
/*             size of the vectors used to store function tables. */
/* 					This value should be an odd integer.  We declare the */
/*             single-precision vectors from 0.  Thus we need */
/* 					an even number of total elements to match exactly */
/*             the double-precision vector.  Example:  Take */
/*             MRFTAB to be 1001.  We allocate with (0:MRFTAB). */
/*             Thus there are 1002 4-byte reals and integers in */
/*             the function-table system.  To match exactly we need */
/*             501 8-byte values.  Since we allocate with the zero */
/*             element as well, we then have MDFTAB = (MRFTAB -1)/2 */
/* 	MDFTAB- maximum row in the double-precision part of the function-table */
/*             system= (MRFTAB -1)/2 */
/*     PMXELM- maximum number of cross section elements in an */
/*             internal table. */
/*     PMXFRC- maximum number of fractions of free drop or free */
/*             flow for computing two-D tables. */
/*     PMXNFL- maximum number of flow lines when defining */
/*             curvilinear elements. */
/*     PMXNHG- maximum number of gate openings for an underflow */
/*             gate.  Defines the maximum number of 2-D tables */
/*             of type 13 that appear in a table of type 15. */
/*     PMXNHU- maximu number of upstream or dnstream heads for */
/*             computing two-D tables. */
/*     PMXNIG- size of vectors used in computing the indefinite */
/*            integral of the breakpoint density when finding */
/*            optimum tables. */
/*     PMXOFF- maximum number of offsets for profile of an embankment */
/*             in EMBANKQ */
/*     PMXPNT- maximum number of points in a cross section. */
/*     PMXSEC- maximum number of cross sections in the function */
/*             table. */
/*     PMXSUB- maximum number of subsection in a cross section. */
/*     PMXTAB- maximum table number. */
/*     TDTIOFF- two-d table initial offset.  The offset of the */
/*              first value in the "body" of the table.  Made the */
/*              same for all two-d tables.  As of 7 march 2003 */
/*              these are 10, 13, 14, and 43.  We may be adding */
/*              40, and 44 in the near future. */
/*     XSCOML- length in 4-byte words of the common blocks for */
/*             cross sections. */
/*     XTIOFF- cross section table initial offset.  The offset */
/*             of the first value in the body of the table. */
/*     MRRBUF- size of the read buffer for all point time series */
/*             files attached to a model. */
/*     NPSLOT - number of points to use in interpolation for */
/*              cross section tables in any bottom slot. */
/* INCLUDE findbrk.for:433 */
/* SOURCE goodbrk.cmn:1 */
/*<       integern_qd,ig_last,qd_pnt(pmxnig) >*/
/* SOURCE goodbrk.cmn:3 */
/*<        >*/
/* SOURCE goodbrk.cmn:6 */
/*<        >*/
/*     + + + LOCAL VARIABLES + + + */
/*     Define some patterns because we need many different */
/*     but closely related values: */
/*     Values defining the cubic spline fit to the data */
/*     points */
/*       XVEC  - the argument values */
/*       FVEC  - the function values */
/*       FPVEC - the first derivative values */
/*       FPPVEC- the second derivative values. */
/*     FPVEC, and FPPVEC are in common block: goodbrk.cmn. */
/*     FVEC_CS and XVEC_CS are also in goodbrk.cmn and are the same */
/*     as FVEC and XVEC. */
/*     The indefinite integral variables are: */
/*     IGVEC - indefinite integral.  g(x) is the integrand */
/*             and so IG denotes 'integral of g' */
/*     XVEC_QD-  argument points for integral.  Contains */
/*               all points in XVEC plus more. */
/*     QD_PNT- pointer to the left panel point of the */
/*             cubic spline of the panel that contains */
/*             the point.  If XL is the left panel point */
/*             for a panel in the cubic spline, and XR is */
/*             the right panel point for the same panel, */
/*             then all points  XL <= x < XR will have */
/*             a pointer to the left panel point, XL. */
/*       These are in goodbrk.cmn. */
/*     We will also have a linear spline approximation. */
/*     GOOD_POINTS  - argument values */
/*     FVEC_LS  - Function values. */
/* SOURCE findbrk.for:471 */
/*<       integeri,j,k,flag,last,last2,n_good_max,nin,n_to_add,l,nbig,iflag >*/
/* SOURCE findbrk.for:473 */
/*<       parameter(nbig=2000) >*/
/* SOURCE findbrk.for:475 */
/*<        >*/
/*     + + + FUNCTIONS + + + */
/* SOURCE findbrk.for:482 */
/*<       real*8ig_res >*/
/* SOURCE findbrk.for:483 */
/*<       externalig_res >*/
/*     ******************************FORMATS***************************** */
/* SOURCE findbrk.for:485 */
/*<       dataoffset/0.4d0,0.5d0,0.6d0/,epsx/0.000001d0/,epsf/0.00001d0/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> fvec(feq_storage_fvec, 1);

    feq::IndexedPointer<doublereal> xvec(feq_storage_xvec, 1);

    feq::IndexedPointer<doublereal> feq_gen_good_points_d_(feq_gen_feq_storage_good_points_d_, 1);

    /* Function Body */
/* SOURCE findbrk.for:487 */
/*<    30 format(i5,f10.3,i5) >*/
/* L30: */
/* SOURCE findbrk.for:488 */
/*<    31  >*/
/* L31: */
/* SOURCE findbrk.for:490 */
/*<    32  >*/
/* L32: */
/* SOURCE findbrk.for:492 */
/*<    33  >*/
/* L33: */
/* SOURCE findbrk.for:494 */
/*<    50 format(' ',i5,f12.7,f10.4,1pe12.4,1pe12.4,1pe12.4,4(1pe12.4)) >*/
/* L50: */
/* SOURCE findbrk.for:495 */
/*<    52 format(' ',f12.7,1pe12.4,1pe12.4) >*/
/* L52: */
/* SOURCE findbrk.for:496 */
/*<    54 format(f10.6,f10.4,f10.4,f10.4) >*/
/* L54: */
/* SOURCE findbrk.for:497 */
/*<    58 format(/,' Results from cubic-spline fit.') >*/
/* L58: */
/* SOURCE findbrk.for:498 */
/*<    60  >*/
/* L60: */
/* SOURCE findbrk.for:500 */
/*<    62  >*/
/* L62: */
/* SOURCE findbrk.for:502 */
/*<    64  >*/
/* L64: */
/* SOURCE findbrk.for:504 */
/*<    66 format(' ',i5,f12.6,f12.6) >*/
/* L66: */
/* SOURCE findbrk.for:505 */
/*<    68 format(30x,f12.5,f12.5,1pe12.4,1pe12.4) >*/
/* L68: */
/* SOURCE findbrk.for:506 */
/*<    70  >*/
/* L70: */
/* SOURCE findbrk.for:508 */
/*<    72  >*/
/* L72: */
/* *********************************************************************** */
/* SOURCE findbrk.for:514 */
/*<       ig_last=1 >*/
    feq_gen_good_brk_d_1.feq_gen_ig_last_d_ = 1;
/* SOURCE findbrk.for:515 */
/*<       last=1 >*/
    last = 1;
/* SOURCE findbrk.for:516 */
/*<       n_good_max=n_good >*/
    feq_gen_n_good_max_d_ = *feq_gen_n_good_d_;
/*     Fit the points with a cubic spline using the supplied derivative */
/*     end conditions. */
/* SOURCE findbrk.for:520 */
/*<        >*/
    spline_(stdout, &xvec[1], &fvec[1], npnts, &feq_gen_c_d_1, feq_gen_left_slope_d_, &feq_gen_c_d_1, 
	    feq_gen_right_slope_d_, feq_gen_good_brk_d_1.fpvec);
/*     Compute the second derivatives. */
/* SOURCE findbrk.for:525 */
/*<       callfind_fpp(npnts,xvec,fvec,fpvec,fppvec) >*/
    feq_gen_find_fpp_d_(npnts, &xvec[1], &fvec[1], feq_gen_good_brk_d_1.fpvec, 
	    feq_gen_good_brk_d_1.fppvec);
/*      GAMMA = 2.5D0 */
/*      CALL TAUTSP ( XVEC, FVEC, NPNTS, GAMMA, NBIG, */
/*     O                    S, */
/*     O                    NEWX, COEF, L, K, IFLAG ) */

/*      CALL SPLINE */
/*     I           (STDOUT, XVEC, FPVEC, NPNTS, 3, 0.5D0, 3, 0.5D0, */
/*     O            TESTFPP) */


/*      WRITE(STDOUT,58) */
/*      WRITE(STDOUT,*) ' NPNTS=',NPNTS,' L=',L */
/*      WRITE(STDOUT,60) */
/*      DO 90 I=1,NPNTS */
/*        WRITE(STDOUT,50) I, XVEC(I), FVEC(I), FPVEC(I), */
/*     A                   FPPVEC(I), */
/*     B                   SQRT(ABS(FPPVEC(I))/FVEC(I)), */
/*     C      S(I,4), TESTFPP(I) */
/* 90    CONTINUE */
/*     Transfer FVEC and XVEC to the common-block values */
/*     FVEC_CS and XVEC_CS */
/* SOURCE findbrk.for:550 */
/*<       do100i=1,npnts >*/
    feq_gen_i_d_1 = *npnts;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE findbrk.for:551 */
/*<       fvec_cs(i)=fvec(i) >*/
	feq_gen_good_brk_d_1.feq_gen_fvec_cs_d_[feq_gen_i_d_ - 1] = fvec[feq_gen_i_d_];
/* SOURCE findbrk.for:552 */
/*<       xvec_cs(i)=xvec(i) >*/
	feq_gen_good_brk_d_1.feq_gen_xvec_cs_d_[feq_gen_i_d_ - 1] = xvec[feq_gen_i_d_];
/* SOURCE findbrk.for:553 */
/*<   100 continue >*/
/* L100: */
    }
/*     Now define the argument points for the integral.  Expand on those */
/*     in XVEC. */
/* SOURCE findbrk.for:557 */
/*<       n_to_add=2 >*/
    feq_gen_n_to_add_d_ = 2;
/* SOURCE findbrk.for:558 */
/*<       k=0 >*/
    k = 0;
/* SOURCE findbrk.for:559 */
/*<       do105i=1,npnts-1 >*/
    feq_gen_i_d_1 = *npnts - 1;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*       Is there a sign change in FPP in the panel between */
/*       I and I + 1? */
/* SOURCE findbrk.for:562 */
/*<       if(fppvec(i)*fppvec(i+1).lt.0.0)then >*/
	if (feq_gen_good_brk_d_1.fppvec[feq_gen_i_d_ - 1] * feq_gen_good_brk_d_1.fppvec[feq_gen_i_d_] < (float)0.)
		 {
/*         There is a sign change.  This means that the integrand */
/*         has a weak singularity, that is, it has an infinite */
/*         derivative as its goes to zero.  This comes about because */
/*         of the sqrt of the absolute value involved in the */
/*         integrand.  Therefore we must introduce a point at the */
/*         zero of the integrand and also insert points in each */
/*         of the sub-intervals so formed. */
/* SOURCE findbrk.for:571 */
/*<        >*/
	    xroot = xvec[feq_gen_i_d_] - feq_gen_good_brk_d_1.fppvec[feq_gen_i_d_ - 1] * (xvec[feq_gen_i_d_ + 1] 
		    - xvec[feq_gen_i_d_]) / (feq_gen_good_brk_d_1.fppvec[feq_gen_i_d_] - 
		    feq_gen_good_brk_d_1.fppvec[feq_gen_i_d_ - 1]);
/*         Process the left-hand subinterval. */
/* SOURCE findbrk.for:574 */
/*<       k=k+1 >*/
	    ++k;
/* SOURCE findbrk.for:575 */
/*<       if(k.gt.pmxnig)then >*/
	    if (k > 906) {
/* SOURCE findbrk.for:576 */
/*<       write(stdout,70) >*/
		feq_gen_io_d__42.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__42);
		e_wsfe();
/* SOURCE findbrk.for:577 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE findbrk.for:578 */
/*<       endif >*/
	    }
/* SOURCE findbrk.for:579 */
/*<       xvec_qd(k)=xvec(i) >*/
	    feq_gen_good_brk_d_1.feq_gen_xvec_qd_d_[k - 1] = xvec[feq_gen_i_d_];
/* SOURCE findbrk.for:580 */
/*<       qd_pnt(k)=i >*/
	    feq_gen_good_brk_d_1.feq_gen_qd_pnt_d_[k - 1] = feq_gen_i_d_;
/*         Compute number of points to insert.  Minimum is one. */
/* SOURCE findbrk.for:582 */
/*<       nin=int(dble(n_to_add)*(xroot-xvec(i))/(xvec(i+1)-xvec(i))+1.0) >*/
	    nin = (integer) ((doublereal) feq_gen_n_to_add_d_ * (xroot - xvec[feq_gen_i_d_]) / (
		    xvec[feq_gen_i_d_ + 1] - xvec[feq_gen_i_d_]) + (float)1.);
/* SOURCE findbrk.for:584 */
/*<       do101j=1,nin >*/
	    feq_gen_i_d_2 = nin;
	    for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE findbrk.for:585 */
/*<       k=k+1 >*/
		++k;
/* SOURCE findbrk.for:586 */
/*<       if(k.gt.pmxnig)then >*/
		if (k > 906) {
/* SOURCE findbrk.for:587 */
/*<       write(stdout,70) >*/
		    feq_gen_io_d__45.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__45);
		    e_wsfe();
/* SOURCE findbrk.for:588 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE findbrk.for:589 */
/*<       endif >*/
		}
/* SOURCE findbrk.for:590 */
/*<       xvec_qd(k)=xvec(i)+dble(j)*(xroot-xvec(i))/dble(nin+1) >*/
		feq_gen_good_brk_d_1.feq_gen_xvec_qd_d_[k - 1] = xvec[feq_gen_i_d_] + (doublereal) j * (
			xroot - xvec[feq_gen_i_d_]) / (doublereal) (nin + 1);
/* SOURCE findbrk.for:592 */
/*<       qd_pnt(k)=i >*/
		feq_gen_good_brk_d_1.feq_gen_qd_pnt_d_[k - 1] = feq_gen_i_d_;
/* SOURCE findbrk.for:593 */
/*<   101 continue >*/
/* L101: */
	    }
/*         Process the right-hand subinterval. */
/* SOURCE findbrk.for:595 */
/*<       k=k+1 >*/
	    ++k;
/* SOURCE findbrk.for:596 */
/*<       if(k.gt.pmxnig)then >*/
	    if (k > 906) {
/* SOURCE findbrk.for:597 */
/*<       write(stdout,70) >*/
		feq_gen_io_d__46.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__46);
		e_wsfe();
/* SOURCE findbrk.for:598 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE findbrk.for:599 */
/*<       endif >*/
	    }
/* SOURCE findbrk.for:600 */
/*<       xvec_qd(k)=xroot >*/
	    feq_gen_good_brk_d_1.feq_gen_xvec_qd_d_[k - 1] = xroot;
/* SOURCE findbrk.for:601 */
/*<       qd_pnt(k)=i >*/
	    feq_gen_good_brk_d_1.feq_gen_qd_pnt_d_[k - 1] = feq_gen_i_d_;
/*         Compute number of points to insert.  Minimum is one. */
/* SOURCE findbrk.for:603 */
/*<       nin=int(dble(n_to_add)*(xvec(i+1)-xroot)/(xvec(i+1)-xvec(i))+1.0) >*/
	    nin = (integer) ((doublereal) feq_gen_n_to_add_d_ * (xvec[feq_gen_i_d_ + 1] - xroot)
		     / (xvec[feq_gen_i_d_ + 1] - xvec[feq_gen_i_d_]) + (float)1.);
/* SOURCE findbrk.for:605 */
/*<       do102j=1,nin >*/
	    feq_gen_i_d_2 = nin;
	    for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE findbrk.for:606 */
/*<       k=k+1 >*/
		++k;
/* SOURCE findbrk.for:607 */
/*<       if(k.gt.pmxnig)then >*/
		if (k > 906) {
/* SOURCE findbrk.for:608 */
/*<       write(stdout,70) >*/
		    feq_gen_io_d__47.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__47);
		    e_wsfe();
/* SOURCE findbrk.for:609 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE findbrk.for:610 */
/*<       endif >*/
		}
/* SOURCE findbrk.for:611 */
/*<       xvec_qd(k)=xroot+dble(j)*(xvec(i+1)-xroot)/dble(nin+1) >*/
		feq_gen_good_brk_d_1.feq_gen_xvec_qd_d_[k - 1] = xroot + (doublereal) j * (xvec[
			feq_gen_i_d_ + 1] - xroot) / (doublereal) (nin + 1);
/* SOURCE findbrk.for:613 */
/*<       qd_pnt(k)=i >*/
		feq_gen_good_brk_d_1.feq_gen_qd_pnt_d_[k - 1] = feq_gen_i_d_;
/* SOURCE findbrk.for:614 */
/*<   102 continue >*/
/* L102: */
	    }
/* SOURCE findbrk.for:615 */
/*<       else >*/
	} else {
/*         There is no sign change.  Transfer the point at the beginning */
/*         of the current panel. */
/* SOURCE findbrk.for:618 */
/*<       k=k+1 >*/
	    ++k;
/* SOURCE findbrk.for:619 */
/*<       if(k.gt.pmxnig)then >*/
	    if (k > 906) {
/* SOURCE findbrk.for:620 */
/*<       write(stdout,70) >*/
		feq_gen_io_d__48.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__48);
		e_wsfe();
/* SOURCE findbrk.for:621 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE findbrk.for:622 */
/*<       endif >*/
	    }
/* SOURCE findbrk.for:623 */
/*<       xvec_qd(k)=xvec(i) >*/
	    feq_gen_good_brk_d_1.feq_gen_xvec_qd_d_[k - 1] = xvec[feq_gen_i_d_];
/* SOURCE findbrk.for:624 */
/*<       qd_pnt(k)=i >*/
	    feq_gen_good_brk_d_1.feq_gen_qd_pnt_d_[k - 1] = feq_gen_i_d_;
/*         Add the intermediate points. */
/* SOURCE findbrk.for:626 */
/*<       do104j=1,n_to_add >*/
	    feq_gen_i_d_2 = feq_gen_n_to_add_d_;
	    for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE findbrk.for:627 */
/*<       k=k+1 >*/
		++k;
/* SOURCE findbrk.for:628 */
/*<       if(k.gt.pmxnig)then >*/
		if (k > 906) {
/* SOURCE findbrk.for:629 */
/*<       write(stdout,70) >*/
		    feq_gen_io_d__49.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__49);
		    e_wsfe();
/* SOURCE findbrk.for:630 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE findbrk.for:631 */
/*<       endif >*/
		}
/* SOURCE findbrk.for:632 */
/*<       xvec_qd(k)=xvec(i)+dble(j)*(xvec(i+1)-xvec(i))/dble(n_to_add+1) >*/
		feq_gen_good_brk_d_1.feq_gen_xvec_qd_d_[k - 1] = xvec[feq_gen_i_d_] + (doublereal) j * (
			xvec[feq_gen_i_d_ + 1] - xvec[feq_gen_i_d_]) / (doublereal) (feq_gen_n_to_add_d_ 
			+ 1);
/* SOURCE findbrk.for:634 */
/*<       qd_pnt(k)=i >*/
		feq_gen_good_brk_d_1.feq_gen_qd_pnt_d_[k - 1] = feq_gen_i_d_;
/* SOURCE findbrk.for:636 */
/*<   104 continue >*/
/* L104: */
	    }
/* SOURCE findbrk.for:637 */
/*<       endif >*/
	}
/* SOURCE findbrk.for:638 */
/*<   105 continue >*/
/* L105: */
    }
/*     Transfer the last point. */
/* SOURCE findbrk.for:640 */
/*<       k=k+1 >*/
    ++k;
/* SOURCE findbrk.for:641 */
/*<       if(k.gt.pmxnig)then >*/
    if (k > 906) {
/* SOURCE findbrk.for:642 */
/*<       write(stdout,70) >*/
	feq_gen_io_d__50.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__50);
	e_wsfe();
/* SOURCE findbrk.for:643 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE findbrk.for:644 */
/*<       endif >*/
    }
/* SOURCE findbrk.for:645 */
/*<       xvec_qd(k)=xvec(npnts) >*/
    feq_gen_good_brk_d_1.feq_gen_xvec_qd_d_[k - 1] = xvec[*npnts];
/* SOURCE findbrk.for:646 */
/*<       qd_pnt(k)=npnts >*/
    feq_gen_good_brk_d_1.feq_gen_qd_pnt_d_[k - 1] = *npnts;
/* SOURCE findbrk.for:647 */
/*<       n_qd=k >*/
    feq_gen_good_brk_d_1.feq_gen_n_qd_d_ = k;
/*     Compute the indefinite integral using the mid-point rule. */
/*     This rule is more accurate in many cases than the trapezoidal */
/*     rule, especially when weak singularities are present in the */
/*     integrand. */
/*      WRITE(STDOUT,62) */
/*      WRITE(STDOUT,64) */
/* SOURCE findbrk.for:656 */
/*<       igvec(1)=0.d0 >*/
    feq_gen_good_brk_d_1.igvec[0] = 0.;
/*      WRITE(STDOUT,66) 1, XVEC_QD(1), IGVEC(1) */
/* SOURCE findbrk.for:658 */
/*<       do110i=1,n_qd-1 >*/
    feq_gen_i_d_1 = feq_gen_good_brk_d_1.feq_gen_n_qd_d_ - 1;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*       Find mid-point of current interval. */
/* SOURCE findbrk.for:660 */
/*<       interval_length=xvec_qd(i+1)-xvec_qd(i) >*/
	feq_gen_interval_length_d_ = feq_gen_good_brk_d_1.feq_gen_xvec_qd_d_[feq_gen_i_d_] - 
		feq_gen_good_brk_d_1.feq_gen_xvec_qd_d_[feq_gen_i_d_ - 1];
/* SOURCE findbrk.for:661 */
/*<       arg=xvec_qd(i)+0.5*interval_length >*/
	arg = feq_gen_good_brk_d_1.feq_gen_xvec_qd_d_[feq_gen_i_d_ - 1] + feq_gen_interval_length_d_ * (float).5;
/*       Compute the values for the cubic spline at argument */
/*       ARG. Get pointer into the cubic-spline description. */
/* SOURCE findbrk.for:665 */
/*<       k=qd_pnt(i) >*/
	k = feq_gen_good_brk_d_1.feq_gen_qd_pnt_d_[feq_gen_i_d_ - 1];
/* SOURCE findbrk.for:666 */
/*<       dx=arg-xvec(k) >*/
	dx = arg - xvec[k];
/* SOURCE findbrk.for:667 */
/*<       halfdx=0.5*dx >*/
	halfdx = dx * (float).5;
/* SOURCE findbrk.for:668 */
/*<       p=dx/(xvec(k+1)-xvec(k)) >*/
	p = dx / (xvec[k + 1] - xvec[k]);
/* SOURCE findbrk.for:669 */
/*<       fpl=fpvec(k) >*/
	fpl = feq_gen_good_brk_d_1.fpvec[k - 1];
/* SOURCE findbrk.for:670 */
/*<       fppl=fppvec(k) >*/
	fppl = feq_gen_good_brk_d_1.fppvec[k - 1];
/* SOURCE findbrk.for:672 */
/*<       fpp=fppl+p*(fppvec(k+1)-fppl) >*/
	fpp = fppl + p * (feq_gen_good_brk_d_1.fppvec[k] - fppl);
/* SOURCE findbrk.for:673 */
/*<       fp=fpl+halfdx*(fppl+fpp) >*/
	fp = fpl + halfdx * (fppl + fpp);
/* SOURCE findbrk.for:674 */
/*<       f=fvec(k)+halfdx*(fpl+fp-halfdx*(fpp-fppl)/3.d0) >*/
	f = fvec[k] + halfdx * (fpl + fp - halfdx * (fpp - fppl) / 3.);
/*       Compute the integrand value and the integral increment. */
/* SOURCE findbrk.for:677 */
/*<       g=sqrt(abs(fpp)/(f)) >*/
	g = sqrt(abs(fpp) / f);
/*        WRITE(STDOUT,68) G, F, FP, FPP */
/* SOURCE findbrk.for:680 */
/*<       igvec(i+1)=igvec(i)+g*interval_length >*/
	feq_gen_good_brk_d_1.igvec[feq_gen_i_d_] = feq_gen_good_brk_d_1.igvec[feq_gen_i_d_ - 1] + g * 
		feq_gen_interval_length_d_;
/*        WRITE(STDOUT,66) I+1, XVEC_QD(I+1), IGVEC(I+1) */
/* SOURCE findbrk.for:683 */
/*<   110 continue >*/
/* L110: */
    }
/*     Estimate the number of points needed. */
/* SOURCE findbrk.for:686 */
/*<       n_good=int(igvec(n_qd)/sqrt(8.0*relative_error)+1)+1 >*/
    *feq_gen_n_good_d_ = (integer) (feq_gen_good_brk_d_1.igvec[feq_gen_good_brk_d_1.feq_gen_n_qd_d_ - 1] / sqrt(*
	    feq_gen_relative_error_d_ * (float)8.) + 1) + 1;
/* SOURCE findbrk.for:687 */
/*<       if(n_good.gt.n_good_max)then >*/
    if (*feq_gen_n_good_d_ > feq_gen_n_good_max_d_) {
/*       Limit reached. */
/* SOURCE findbrk.for:689 */
/*<       write(stdout,72)n_good,n_good_max >*/
	feq_gen_io_d__62.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__62);
	do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_n_good_d_), (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_n_good_max_d_, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE findbrk.for:690 */
/*<       stop'Abnormal stop.  Errors Found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors Found."), (ftnlen)29);
/* SOURCE findbrk.for:691 */
/*<       endif >*/
    }
/* SOURCE findbrk.for:692 */
/*<   200 continue >*/
L200:
/*        WRITE(STDOUT,*) ' ' */
/*        WRITE(STDOUT,*) ' N_GOOD=', N_GOOD */
/*       Now assign the good breakpoints so that each panel of the */
/*       linear spline gets the same amount of the cumulative */
/*       error density. */
/* SOURCE findbrk.for:699 */
/*<       delta_ig=igvec(n_qd)/(n_good-1) >*/
    feq_gen_delta_ig_d_ = feq_gen_good_brk_d_1.igvec[feq_gen_good_brk_d_1.feq_gen_n_qd_d_ - 1] / (*feq_gen_n_good_d_ - 1);
/* SOURCE findbrk.for:700 */
/*<       good_points(1)=xvec(1) >*/
    feq_gen_good_points_d_[1] = xvec[1];
/* SOURCE findbrk.for:701 */
/*<       good_points(n_good)=xvec(npnts) >*/
    feq_gen_good_points_d_[*feq_gen_n_good_d_] = xvec[*npnts];
/* SOURCE findbrk.for:702 */
/*<       flag=0 >*/
    feq_gen_flag_d_ = 0;
/*        WRITE(STDOUT,30) 1, GOOD_POINTS(1), FLAG */
/* SOURCE findbrk.for:705 */
/*<       igval=0.0 >*/
    feq_gen_good_brk_d_1.igval = (float)0.;
/* SOURCE findbrk.for:706 */
/*<       do150i=2,n_good-1 >*/
    feq_gen_i_d_1 = *feq_gen_n_good_d_ - 1;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE findbrk.for:707 */
/*<       igval=igval+delta_ig >*/
	feq_gen_good_brk_d_1.igval += feq_gen_delta_ig_d_;
/* SOURCE findbrk.for:708 */
/*<       xl=good_points(i-1) >*/
	xl = feq_gen_good_points_d_[feq_gen_i_d_ - 1];
/* SOURCE findbrk.for:709 */
/*<       rfl=ig_res(xl) >*/
	rfl = feq_gen_ig_res_d_(&xl);
/* SOURCE findbrk.for:710 */
/*<       xr=good_points(n_good) >*/
	xr = feq_gen_good_points_d_[*feq_gen_n_good_d_];
/* SOURCE findbrk.for:711 */
/*<       rfr=igval-igvec(n_qd) >*/
	rfr = feq_gen_good_brk_d_1.igval - feq_gen_good_brk_d_1.igvec[feq_gen_good_brk_d_1.feq_gen_n_qd_d_ - 1];
/* SOURCE findbrk.for:713 */
/*<       callfdblrgf(epsx,epsf,ig_res,xl,xr,rfl,rfr,root,flag) >*/
	fdblrgf_(&epsx, &epsf, feq_gen_ig_res_d_, &xl, &xr, &rfl, &rfr, &root, &
		feq_gen_flag_d_);
/* SOURCE findbrk.for:717 */
/*<       if(flag.gt.0)then >*/
	if (feq_gen_flag_d_ > 0) {
/* SOURCE findbrk.for:718 */
/*<       no_good=1 >*/
	    *feq_gen_no_good_d_ = 1;
/* SOURCE findbrk.for:719 */
/*<       if(flag.eq.1)then >*/
	    if (feq_gen_flag_d_ == 1) {
/* SOURCE findbrk.for:720 */
/*<       write(stdout,31) >*/
		feq_gen_io_d__70.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__70);
		e_wsfe();
/* SOURCE findbrk.for:721 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE findbrk.for:722 */
/*<       elseif(flag.eq.2)then >*/
	    } else if (feq_gen_flag_d_ == 2) {
/* SOURCE findbrk.for:723 */
/*<       write(stdout,32) >*/
		feq_gen_io_d__71.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__71);
		e_wsfe();
/* SOURCE findbrk.for:724 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE findbrk.for:725 */
/*<       else >*/
	    } else {
/* SOURCE findbrk.for:726 */
/*<       write(stdout,33) >*/
		feq_gen_io_d__72.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__72);
		e_wsfe();
/* SOURCE findbrk.for:727 */
/*<       endif >*/
	    }
/* SOURCE findbrk.for:728 */
/*<       endif >*/
	}
/* SOURCE findbrk.for:730 */
/*<       good_points(i)=root >*/
	feq_gen_good_points_d_[feq_gen_i_d_] = root;
/*          WRITE(STDOUT,30) I, ROOT, FLAG */
/* SOURCE findbrk.for:732 */
/*<   150 continue >*/
/* L150: */
    }
/*        WRITE(STDOUT,30) N_GOOD, GOOD_POINTS(N_GOOD), 0 */
/*       Do a check computation */
/*       Get function value at the breakpoints for the linear spline. */
/* SOURCE findbrk.for:737 */
/*<       do170i=1,n_good >*/
    feq_gen_i_d_1 = *feq_gen_n_good_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE findbrk.for:738 */
/*<        >*/
	feq_gen_cubic_spline_lookup_d_(&feq_gen_good_points_d_[feq_gen_i_d_], npnts, &xvec[1], &fvec[1], 
		feq_gen_good_brk_d_1.fpvec, feq_gen_good_brk_d_1.fppvec, &last, &feq_gen_fvec_ls_d_[feq_gen_i_d_ 
		- 1], &fp, &fpp);
/* SOURCE findbrk.for:742 */
/*<   170 continue >*/
/* L170: */
    }
/* SOURCE findbrk.for:744 */
/*<       last=1 >*/
    last = 1;
/* SOURCE findbrk.for:745 */
/*<       last2=1 >*/
    last2 = 1;
/* SOURCE findbrk.for:746 */
/*<       max_rerr=0.d0 >*/
    *feq_gen_max_rerr_d_ = 0.;
/* SOURCE findbrk.for:747 */
/*<       xl=good_points(1) >*/
    xl = feq_gen_good_points_d_[1];
/* SOURCE findbrk.for:748 */
/*<       do180i=2,n_good >*/
    feq_gen_i_d_1 = *feq_gen_n_good_d_;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE findbrk.for:749 */
/*<       xr=good_points(i) >*/
	xr = feq_gen_good_points_d_[feq_gen_i_d_];
/* SOURCE findbrk.for:750 */
/*<       dx=xr-xl >*/
	dx = xr - xl;
/* SOURCE findbrk.for:751 */
/*<       do175j=1,3 >*/
	for (j = 1; j <= 3; ++j) {
/* SOURCE findbrk.for:752 */
/*<       arg=xl+dx*offset(j) >*/
	    arg = xl + dx * offset[j - 1];
/* SOURCE findbrk.for:753 */
/*<        >*/
	    feq_gen_cubic_spline_lookup_d_(&arg, npnts, &xvec[1], &fvec[1], 
		    feq_gen_good_brk_d_1.fpvec, feq_gen_good_brk_d_1.fppvec, &last, &f, &fp, &
		    fpp);
/* SOURCE findbrk.for:757 */
/*<        >*/
	    feq_gen_linear_spline_lookup_d_(&arg, feq_gen_n_good_d_, &feq_gen_good_points_d_[1], 
		    feq_gen_fvec_ls_d_, &last2, &fhat);
/* SOURCE findbrk.for:760 */
/*<       rerr=(fhat-f)/f >*/
	    rerr = (fhat - f) / f;
/* SOURCE findbrk.for:761 */
/*<       max_rerr=max(abs(rerr),max_rerr) >*/
/* Computing MAX */
	    feq_gen_d_d_1 = abs(rerr);
	    *feq_gen_max_rerr_d_ = max(feq_gen_d_d_1,*feq_gen_max_rerr_d_);
/* SOURCE findbrk.for:762 */
/*<   175 continue >*/
/* L175: */
	}
/* SOURCE findbrk.for:763 */
/*<       xl=xr >*/
	xl = xr;
/* SOURCE findbrk.for:764 */
/*<   180 continue >*/
/* L180: */
    }
/* SOURCE findbrk.for:765 */
/*<       if(max_rerr.gt.relative_error)then >*/
    if (*feq_gen_max_rerr_d_ > *feq_gen_relative_error_d_) {
/* SOURCE findbrk.for:766 */
/*<       if(n_good.lt.n_good_max)then >*/
	if (*feq_gen_n_good_d_ < feq_gen_n_good_max_d_) {
/*           Add another breakpoint and try again. */
/* SOURCE findbrk.for:768 */
/*<       n_good=n_good+1 >*/
	    ++(*feq_gen_n_good_d_);
/* SOURCE findbrk.for:769 */
/*<       goto200 >*/
	    goto L200;
/* SOURCE findbrk.for:770 */
/*<       endif >*/
	}
/* SOURCE findbrk.for:771 */
/*<       endif >*/
    }
/* SOURCE findbrk.for:773 */
/*<       return >*/
    return 0;
/* SOURCE findbrk.for:774 */
/*<       end >*/
} /* find_good_points__ */

/*     *********** */
/*     *         * */
/*     * FIND_POWER_FUNCTION_DERIVATIVE  * */
/*     *         * */
/*     *********** */
/* SOURCE findbrk.for:782 */
/*<       subroutinefind_power_function_derivative(n,k,x,f,fp) >*/
/* Subroutine */ int feq_gen_find_power_function_derivative_d_(integer *n, integer *k, 
	doublereal *feq_storage_x, doublereal *feq_storage_f, doublereal *fp)
{
    /* Builtin functions */
    double log(doublereal);

    /* Local variables */
    doublereal b, h1, h2, hsum;

/*     + + + PURPOSE + + + */
/*     Find derivative at index K of the function tabulated in X and F */
/*     by computing the slope in log-log space and using the derivative */
/*     at that point of the simple power function defined by the */
/*     log-log slope. */
/* SOURCE findbrk.for:792 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE findbrk.for:795 */
/*<       integern,k >*/
/* SOURCE findbrk.for:796 */
/*<       real*8x(n),f(n),fp >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     N - number of points in X and F */
/*     K - index of point in X at which derivative is needed */
/*     X - sequence of arguments */
/*     F - sequence of function values; all > 0 */
/*     FP - computed derivative of power function at K */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE findbrk.for:806 */
/*<       real*8b,h1,h2,hsum >*/
/* *********************************************************************** */
/*     The three points involved in computing the slope of a */
/*     parabola are by:    X0, X0 + H1, and X0 + H1 + H2 */
/* SOURCE findbrk.for:812 */
/*<       if(k.eq.1)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> f(feq_storage_f, 1);

    feq::IndexedPointer<doublereal> x(feq_storage_x, 1);

    /* Function Body */
    if (*k == 1) {
/*       WE ARE AT X0. */
/* SOURCE findbrk.for:814 */
/*<       h1=log(x(k+1)/x(k)) >*/
	h1 = log(x[*k + 1] / x[*k]);
/* SOURCE findbrk.for:815 */
/*<       h2=log(x(k+2)/x(k+1)) >*/
	h2 = log(x[*k + 2] / x[*k + 1]);
/* SOURCE findbrk.for:816 */
/*<       hsum=h1+h2 >*/
	hsum = h1 + h2;
/* SOURCE findbrk.for:817 */
/*<        >*/
	b = -(h1 * (float)2. + h2) * log(f[*k]) / (h1 * hsum) + hsum * log(f[*
		k + 1]) / (h1 * h2) - h1 * log(f[*k + 2]) / (hsum * h2);
/* SOURCE findbrk.for:821 */
/*<       elseif(k.eq.n)then >*/
    } else if (*k == *n) {
/*       WE ARE AT X0+H1+H2 */
/* SOURCE findbrk.for:823 */
/*<       h1=log(x(k-1)/x(k-2)) >*/
	h1 = log(x[*k - 1] / x[*k - 2]);
/* SOURCE findbrk.for:824 */
/*<       h2=log(x(k)/x(k-1)) >*/
	h2 = log(x[*k] / x[*k - 1]);
/* SOURCE findbrk.for:825 */
/*<       hsum=h1+h2 >*/
	hsum = h1 + h2;
/* SOURCE findbrk.for:826 */
/*<        >*/
	b = h2 * log(f[*k - 2]) / (h1 * hsum) - hsum * log(f[*k - 1]) / (h1 * 
		h2) + (h2 * (float)2. + h1) * log(f[*k]) / (hsum * h2);
/* SOURCE findbrk.for:829 */
/*<       else >*/
    } else {
/*       WE ARE AT X0+H1 */
/* SOURCE findbrk.for:831 */
/*<       h1=log(x(k)/x(k-1)) >*/
	h1 = log(x[*k] / x[*k - 1]);
/* SOURCE findbrk.for:832 */
/*<       h2=log(x(k+1)/x(k)) >*/
	h2 = log(x[*k + 1] / x[*k]);
/* SOURCE findbrk.for:833 */
/*<       hsum=h1+h2 >*/
	hsum = h1 + h2;
/* SOURCE findbrk.for:834 */
/*<        >*/
	b = -h2 * log(f[*k - 1]) / (h1 * hsum) + (h2 - h1) * log(f[*k]) / (h1 
		* h2) + h1 * log(f[*k + 1]) / (hsum * h2);
/* SOURCE findbrk.for:837 */
/*<       endif >*/
    }
/* SOURCE findbrk.for:839 */
/*<       fp=b*f(k)/x(k) >*/
    *fp = b * f[*k] / x[*k];
/* SOURCE findbrk.for:840 */
/*<       return >*/
    return 0;
/* SOURCE findbrk.for:841 */
/*<       end >*/
} /* find_power_function_derivative__ */

/*     *********** */
/*     *         * */
/*     * FIND_PARABOLIC_DERIVATIVE  * */
/*     *         * */
/*     *********** */
/* SOURCE findbrk.for:848 */
/*<       subroutinefind_parabolic_derivative(n,k,x,f,fp) >*/
/* Subroutine */ int feq_gen_find_parabolic_derivative_d_(integer *n, integer *k, 
	doublereal *feq_storage_x, doublereal *feq_storage_f, doublereal *fp)
{
    doublereal h1, h2, hsum;

/*     + + + PURPOSE + + + */
/*     Find derivative at index K of the function tabulated in X and F */
/*     by computing the slope of the parabola fitted to the point */
/*     at K and the two points nearest to the point at index K. */
/* SOURCE findbrk.for:856 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE findbrk.for:859 */
/*<       integern,k >*/
/* SOURCE findbrk.for:860 */
/*<       real*8x(n),f(n),fp >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     N - number of points in X and F */
/*     K - index of point in X at which derivative is needed */
/*     X - sequence of arguments */
/*     F - sequence of function values; all > 0 */
/*     FP - computed derivative at K */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE findbrk.for:871 */
/*<       real*8h1,h2,hsum >*/
/* *********************************************************************** */
/*     The three points involved in computing the slope of a */
/*     parabola are denoted by:  X0, X0 + H1, and X0 + H1 + H2 */
/* SOURCE findbrk.for:876 */
/*<       if(k.eq.1)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> f(feq_storage_f, 1);

    feq::IndexedPointer<doublereal> x(feq_storage_x, 1);

    /* Function Body */
    if (*k == 1) {
/*       WE ARE AT X0. */
/* SOURCE findbrk.for:878 */
/*<       h1=x(k+1)-x(k) >*/
	h1 = x[*k + 1] - x[*k];
/* SOURCE findbrk.for:879 */
/*<       h2=x(k+2)-x(k+1) >*/
	h2 = x[*k + 2] - x[*k + 1];
/* SOURCE findbrk.for:880 */
/*<       hsum=h1+h2 >*/
	hsum = h1 + h2;
/* SOURCE findbrk.for:881 */
/*<        >*/
	*fp = -(h1 * (float)2. + h2) * f[*k] / (h1 * hsum) + hsum * f[*k + 1] 
		/ (h1 * h2) - h1 * f[*k + 2] / (hsum * h2);
/* SOURCE findbrk.for:885 */
/*<       elseif(k.eq.n)then >*/
    } else if (*k == *n) {
/*       WE ARE AT X0+H1+H2 */
/* SOURCE findbrk.for:887 */
/*<       h1=x(k-1)-x(k-2) >*/
	h1 = x[*k - 1] - x[*k - 2];
/* SOURCE findbrk.for:888 */
/*<       h2=x(k)-x(k-1) >*/
	h2 = x[*k] - x[*k - 1];
/* SOURCE findbrk.for:889 */
/*<       hsum=h1+h2 >*/
	hsum = h1 + h2;
/* SOURCE findbrk.for:890 */
/*<        >*/
	*fp = h2 * f[*k - 2] / (h1 * hsum) - hsum * f[*k - 1] / (h1 * h2) + (
		h2 * (float)2. + h1) * f[*k] / (hsum * h2);
/* SOURCE findbrk.for:893 */
/*<       else >*/
    } else {
/*       WE ARE AT X0+H1 */
/* SOURCE findbrk.for:895 */
/*<       h1=x(k)-x(k-1) >*/
	h1 = x[*k] - x[*k - 1];
/* SOURCE findbrk.for:896 */
/*<       h2=x(k+1)-x(k) >*/
	h2 = x[*k + 1] - x[*k];
/* SOURCE findbrk.for:897 */
/*<       hsum=h1+h2 >*/
	hsum = h1 + h2;
/* SOURCE findbrk.for:898 */
/*<       fp=-h2*f(k-1)/(h1*hsum)+(h2-h1)*f(k)/(h1*h2)+h1*f(k+1)/(hsum*h2) >*/
	*fp = -h2 * f[*k - 1] / (h1 * hsum) + (h2 - h1) * f[*k] / (h1 * h2) + 
		h1 * f[*k + 1] / (hsum * h2);
/* SOURCE findbrk.for:901 */
/*<       endif >*/
    }
/* SOURCE findbrk.for:902 */
/*<       return >*/
    return 0;
/* SOURCE findbrk.for:903 */
/*<       end >*/
} /* find_parabolic_derivative__ */




/* SOURCE findbrk.for:909 */
/*<        >*/
/* Subroutine */ int findbrk_(integer *stdout, integer *npnts, doublereal *
	feq_storage_xvec, doublereal *feq_storage_fvec, doublereal *feq_gen_relative_error_d_, integer *
	feq_gen_left_option_d_, integer *feq_gen_right_option_d_, integer *feq_gen_n_good_d_, doublereal 
	*feq_gen_feq_storage_good_points_d_, integer *feq_gen_no_good_d_, doublereal *feq_gen_max_rerr_d_)
{
    extern /* Subroutine */ int feq_gen_find_good_points_d_(integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, doublereal *, integer *, doublereal *), 
	    feq_gen_find_parabolic_derivative_d_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *);
    doublereal feq_gen_left_slope_d_, feq_gen_right_slope_d_;
    extern /* Subroutine */ int feq_gen_find_power_function_derivative_d_(integer *, 
	    integer *, doublereal *, doublereal *, doublereal *);

/*     + + + PURPOSE + + + */
/*     Find a series of breakpoints that will hopefully result */
/*     in a relative error of linear interpolation of no greater than */
/*     RELATIVE_ERROR.  The function is assumed to be defined */
/*     by the point set in (XVEC, FVEC) as fitted by a cubic */
/*     spline.  The only requirement is that a cubic spline */
/*     interpolate the function with accuracy much better than */
/*     the requested linear-interpolation error. */
/* SOURCE findbrk.for:923 */
/*<       implicitnone >*/
/* INCLUDE findbrk.for:925 */
/*     DEFINITION OF PARAMETERS USED TO SET SIZE OF ARRAYS AND VECTORS */
/*     IN FEQ AND FEQUTL.  THIS FILE MUST BE INCLUDED IF ANY ARRAYS */
/*     OR VECTORS ARE BEING DECLARED IN A PROGRAM UNIT. */

/* SHARED PARAMETERS BETWEEN FEQ AND FEQUTL */
/* SOURCE arsize.prm:7 */
/*<        >*/
/* SOURCE arsize.prm:10 */
/*<       parameter(mnbra=2200,mextra=4000) >*/
/* SOURCE arsize.prm:11 */
/*<        >*/

/* FEQ SPECIFIC PARAMETERS */
/* SOURCE arsize.prm:17 */
/*<        >*/
/* SOURCE arsize.prm:19 */
/*<        >*/
/* SOURCE arsize.prm:24 */
/*<        >*/
/* SOURCE arsize.prm:26 */
/*<       integermxn_irrig >*/
/* SOURCE arsize.prm:27 */
/*<       integerdptsf_rec_at_frst_ts_pnt,dptsf_rec_at_lkup_tab_start >*/
/* SOURCE arsize.prm:28 */
/*<        >*/
/* SOURCE arsize.prm:30 */
/*<       parameter(mnfree=4000) >*/
/* SOURCE arsize.prm:31 */
/*<       parameter(mnex=2*mnbra+mnfree) >*/
/* SOURCE arsize.prm:32 */
/*<        >*/
/* SOURCE arsize.prm:42 */
/*<        >*/
/* SOURCE arsize.prm:45 */
/*<        >*/
/* SOURCE arsize.prm:51 */
/*<       parameter(mxn_irrig=mnbra+mnfree/2) >*/

/* FEQUTL SPECIFIC PARAMETERS */
/* SOURCE arsize.prm:54 */
/*<        >*/
/* SOURCE arsize.prm:59 */
/*<        >*/
/*     TA_UNITS_PER_BRANCH - gives the assumed average number of */
/*       tributary area units per branch.  A unit is any collection */
/*       of tributrary areas flowing into a contiguous series of */
/*       computational elements on a branch.  If branch mode of */
/*       tributary input is used then the unit is the tributary */
/*       area for the branch.  If the station mode is used it */
/*       is the tributary area for each station interval.  Finally */
/*       if node mode is used it is the tributary area for a */
/*       single node on the branch.  These are all called */
/*       tributrary area units because the computations treat */
/*       them as a unit in the diffuse runoff calculations */
/*       of runoff amount, effect of detention reservoirs, and */
/*       effect of delay reservoirs. */
/*     MXR_TRIBA - maximum number of rows given to the TRIBA array. */
/*                 This is also the max number of trib-area units. */
/*     MXN_DTEN  - maximum number of detention reservoirs */
/*     MXN_DLAY  - maximum number of delay reservoirs */
/*     TAM_MXNI  - maximum number of entries in TAM_ITAB, the */
/*                 tributary area management integer vector. */
/*     TAM_MXNF  - maximum number of entries in TAM_FTAB, the */
/*                 tributrary area management floating point vector. */
/*     MNGATE- maximum number of gates/pumps for output of special values to */
/*             the special output file. */
/*     MNSPROW-maximum number of extra rows allowed in special output. */
/*             There are always 2 rows by default.  The rows defined */
/*             by this parameter are in addition to the original 2 */
/*             rows. */
/*     MXN_TS -maximum number of unique time-series references allowed. */
/*             The same time series may appear more than once but is */
/*             only counted once for MXN_TS accounting. */
/*     MXN_TS - maximum number of unique time-series allowed. */
/*              Excludes those involved in the diffuse inflow */
/*              computations.  Counts time series from files */
/*              as well as from function tables.  Each time */
/*              series is counted only once even if it is */
/*              used in more than one location.  In other words, */
/*              MXN_TS counts the number of unique sources for */
/*              time-series data.  The number of destinations, */
/*              that is, locations in the model, where a time */
/*              series of any kind is used, is counted  within */
/*              MXN_DEST. */

/*     MXN_DEST-maximum number of time-series destinations counting any */
/*              duplicates. Those counted are those that have */
/*              destinations of forced boundary, evaporation on */
/*              water surfaces, precipitation on water surfaces, */
/*              and others yet to come that will be attached at */
/*              various points in a FEQ model. */
/*     MXN_LU_G - maximum number of land uses per gage. */
/*     MXN_IRRIG -maximum number of tributary-area units supporting */
/*                irrigation withdrawals.  This will be set to */
/*                the sum of the number of branches plus one-half */
/*                number of free nodes. */
/*     MAXCMD- maximum number of commands for FEQUTL. */
/*     MCDT10- maximum number of columns in a 2-D table of type 10 */
/*     MRDT10- maximum number of rows in a 2-D table of type 10 */
/*             (used in INV_GATE to size 2-D arrays) */
/*     MFTNUM- same as PMXTAB- maximum table number */
/*     MNBN- maximum number of nodes on a culvert barrel in */
/*           the culvert command. */
/*     MNDEP- maximum number of depth values in an interpolated */
/*            cross section. */
/*     MNMID- maximum number of cross sections interpolated between */
/*            known cross sections. */
/*     MRFTAB- maximum row in function table.  Gives the */
/*             size of the vectors used to store function tables. */
/* 					This value should be an odd integer.  We declare the */
/*             single-precision vectors from 0.  Thus we need */
/* 					an even number of total elements to match exactly */
/*             the double-precision vector.  Example:  Take */
/*             MRFTAB to be 1001.  We allocate with (0:MRFTAB). */
/*             Thus there are 1002 4-byte reals and integers in */
/*             the function-table system.  To match exactly we need */
/*             501 8-byte values.  Since we allocate with the zero */
/*             element as well, we then have MDFTAB = (MRFTAB -1)/2 */
/* 	MDFTAB- maximum row in the double-precision part of the function-table */
/*             system= (MRFTAB -1)/2 */
/*     PMXELM- maximum number of cross section elements in an */
/*             internal table. */
/*     PMXFRC- maximum number of fractions of free drop or free */
/*             flow for computing two-D tables. */
/*     PMXNFL- maximum number of flow lines when defining */
/*             curvilinear elements. */
/*     PMXNHG- maximum number of gate openings for an underflow */
/*             gate.  Defines the maximum number of 2-D tables */
/*             of type 13 that appear in a table of type 15. */
/*     PMXNHU- maximu number of upstream or dnstream heads for */
/*             computing two-D tables. */
/*     PMXNIG- size of vectors used in computing the indefinite */
/*            integral of the breakpoint density when finding */
/*            optimum tables. */
/*     PMXOFF- maximum number of offsets for profile of an embankment */
/*             in EMBANKQ */
/*     PMXPNT- maximum number of points in a cross section. */
/*     PMXSEC- maximum number of cross sections in the function */
/*             table. */
/*     PMXSUB- maximum number of subsection in a cross section. */
/*     PMXTAB- maximum table number. */
/*     TDTIOFF- two-d table initial offset.  The offset of the */
/*              first value in the "body" of the table.  Made the */
/*              same for all two-d tables.  As of 7 march 2003 */
/*              these are 10, 13, 14, and 43.  We may be adding */
/*              40, and 44 in the near future. */
/*     XSCOML- length in 4-byte words of the common blocks for */
/*             cross sections. */
/*     XTIOFF- cross section table initial offset.  The offset */
/*             of the first value in the body of the table. */
/*     MRRBUF- size of the read buffer for all point time series */
/*             files attached to a model. */
/*     NPSLOT - number of points to use in interpolation for */
/*              cross section tables in any bottom slot. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE findbrk.for:929 */
/*<       integernpnts,stdout,n_good,no_good,left_option,right_option >*/
/* SOURCE findbrk.for:931 */
/*<        >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - standard output unit */
/*     NPNTS - number of values in XVEC and FVEC */
/*     XVEC - series of argument values */
/*     FVEC - function values at arguments in XVEC */
/*     RELATIVE_ERROR - target relative error for linear spline */
/*                      interpolation in the function tabulated */
/*                      in XVEC and FVEC */
/*     LEFT_OPTION - code for the slope at left end of range */
/*     RIGHT_OPTION - code for the slope at right end of range */
/*     N_GOOD - number of points in the good sequence */
/*     GOOD_POINTS - the sequence of good breakpoints */
/*     NO_GOOD - error flag. =1 if failure, =0 otherwise */
/*     MAX_RERR - absolute value of the maximum relative error */
/*               in linear interpolation using the GOOD_POINTS */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE findbrk.for:951 */
/*<       real*8left_slope,right_slope >*/
/* *********************************************************************** */
/*     Define the end conditions.  Use derivative of simple power */
/*     function fitted to three points. */
/* SOURCE findbrk.for:955 */
/*<       if(left_option.eq.1)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> feq_gen_good_points_d_(feq_gen_feq_storage_good_points_d_, 1);

    feq::IndexedPointer<doublereal> fvec(feq_storage_fvec, 1);

    feq::IndexedPointer<doublereal> xvec(feq_storage_xvec, 1);

    /* Function Body */
    if (*feq_gen_left_option_d_ == 1) {
/*       Compute derivative using values as is. */
/* SOURCE findbrk.for:957 */
/*<       callfind_parabolic_derivative(npnts,1,xvec,fvec,left_slope) >*/
	feq_gen_find_parabolic_derivative_d_(npnts, &feq_gen_c_d_1, &xvec[1], &fvec[1], &
		feq_gen_left_slope_d_);
/* SOURCE findbrk.for:959 */
/*<       else >*/
    } else {
/*       Compute derivative using a fitted power function. */
/* SOURCE findbrk.for:961 */
/*<       callfind_power_function_derivative(npnts,1,xvec,fvec,left_slope) >*/
	feq_gen_find_power_function_derivative_d_(npnts, &feq_gen_c_d_1, &xvec[1], &fvec[1], &
		feq_gen_left_slope_d_);
/* SOURCE findbrk.for:963 */
/*<       endif >*/
    }
/* SOURCE findbrk.for:964 */
/*<       if(right_option.eq.1)then >*/
    if (*feq_gen_right_option_d_ == 1) {
/* SOURCE findbrk.for:965 */
/*<       callfind_parabolic_derivative(npnts,npnts,xvec,fvec,right_slope) >*/
	feq_gen_find_parabolic_derivative_d_(npnts, npnts, &xvec[1], &fvec[1], &
		feq_gen_right_slope_d_);
/* SOURCE findbrk.for:967 */
/*<       else >*/
    } else {
/* SOURCE findbrk.for:968 */
/*<        >*/
	feq_gen_find_power_function_derivative_d_(npnts, npnts, &xvec[1], &fvec[1], &
		feq_gen_right_slope_d_);
/* SOURCE findbrk.for:970 */
/*<       endif >*/
    }
/* SOURCE findbrk.for:972 */
/*<       n_good=npnts >*/
    *feq_gen_n_good_d_ = *npnts;
/* SOURCE findbrk.for:973 */
/*<        >*/
    feq_gen_find_good_points_d_(stdout, npnts, &xvec[1], &fvec[1], feq_gen_relative_error_d_, &
	    feq_gen_left_slope_d_, &feq_gen_right_slope_d_, feq_gen_n_good_d_, &feq_gen_good_points_d_[1], 
	    feq_gen_no_good_d_, feq_gen_max_rerr_d_);
/* SOURCE findbrk.for:978 */
/*<       return >*/
    return 0;
/* SOURCE findbrk.for:979 */
/*<       end >*/
} /* findbrk_ */

#ifdef __cplusplus
	}
#endif
