#include "callbacks.hpp"
/* riserclv.f -- translated by f2c (version 20240504).
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

/* COMMON sf_frq__ is declared in common.hpp. */

#define feq_gen_sf_frq_d_1 feq_gen_sf_frq_d_

/* COMMON sf_frqc__ is declared in common.hpp. */

#define feq_gen_sf_frqc_d_1 feq_gen_sf_frqc_d_

/* COMMON ftable_ is declared in common.hpp. */

#define ftable_1 ftable_

/* COMMON ftablea_ is declared in common.hpp. */

#define ftablea_1 ftablea_

/* COMMON ftablec_ is declared in common.hpp. */

#define ftablec_1 ftablec_

/* COMMON epscom_ is declared in common.hpp. */

#define epscom_1 epscom_

/* Table of constant values */

static doublereal c_b2 = .5;
static doublereal c_b9 = 1.5;
static doublereal c_b10 = .385;
static doublereal c_b25 = .6667;
static doublereal c_b54 = 1.3333;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_10002 = 10002;
static integer feq_gen_c_d_151 = 151;
static integer feq_gen_c_d_351 = 351;
static integer feq_gen_c_d_13 = 13;

/*     *********** */
/*     *         * */
/*     * QCULCIR */
/*     *         * */
/*     *********** */
/* SOURCE riserclv.for:7 */
/*<       subroutineqculcir(yx,d,a,r,hd) >*/
/* Subroutine */ int qculcir_(real *yx, real *feq_gen_d_d_, real *a, real *feq_gen_r_d_, real *
	hd)
{
    /* System generated locals */
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *);

    /* Local variables */
    real t, y, feq_gen_z_d_, y1, wp, dab, dac, dep, phiy, angle;

/*     THIS SUBROUTINE COMPUTES AREA, HYDRAULIC RADIUS AND HYDRAULIC DEPTH */
/*     FOR THE NON-OVERLAP OF TWO CIRCLES */
/*     Dummy arguments */
/* SOURCE riserclv.for:14 */
/*<       realyx,d,a,r,hd >*/
/* ********************************************************************** */
/* SOURCE riserclv.for:17 */
/*<       z=d/2. >*/
    feq_gen_z_d_ = static_cast<double>(*feq_gen_d_d_) / (float)2.;
/* SOURCE riserclv.for:18 */
/*<       dep=yx >*/
    dep = *yx;
/* SOURCE riserclv.for:19 */
/*<       if(dep.ge.d)dep=0.9999*d >*/
    if (dep >= *feq_gen_d_d_) {
	dep = static_cast<double>(*feq_gen_d_d_) * (float).9999;
    }
/* SOURCE riserclv.for:20 */
/*<       if(dep.le.0.)dep=0.0001*d >*/
    if (dep <= (float)0.) {
	dep = static_cast<double>(*feq_gen_d_d_) * (float)1e-4;
    }
/* SOURCE riserclv.for:21 */
/*<       dab=dep-z >*/
    dab = static_cast<double>(dep) - feq_gen_z_d_;
/* SOURCE riserclv.for:22 */
/*<       y=dab/z >*/
    y = static_cast<double>(dab) / feq_gen_z_d_;
/* SOURCE riserclv.for:23 */
/*<       y1=abs(y) >*/
    y1 = dabs(y);
/* *****  ARCSIN APPROXIMATION */
/* SOURCE riserclv.for:25 */
/*<        >*/
    phiy = static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>((static_cast<double>((float).0193499) - static_cast<double>(y1) * (float).00433777)) * y1) - (float)
	    .0449589)) * y1) + (float).0878763)) * y1) - (float).214512)) * y1) + (
	    float)1.570796;
/* SOURCE riserclv.for:27 */
/*<       angle=1.570796-(1.0-y1)**0.5*phiy >*/
    feq_gen_d_d_1 = (doublereal) (static_cast<double>((float)1.) - y1);
    angle = (float)1.570796 - pow_dd(&feq_gen_d_d_1, &c_b2) * phiy;
/* SOURCE riserclv.for:28 */
/*<       if(y)10,20,20 >*/
    if (y >= (float)0.) {
	goto L20;
    } else {
	goto L10;
    }
/* SOURCE riserclv.for:29 */
/*<    10 angle=-angle >*/
L10:
    angle = -angle;
/* SOURCE riserclv.for:30 */
/*<    20 dac=angle+1.570796 >*/
L20:
    dac = static_cast<double>(angle) + (float)1.570796;
/* SOURCE riserclv.for:31 */
/*<       a=(dab*(d*dep-dep*dep)**0.5)+(z*z*dac) >*/
    feq_gen_d_d_1 = (doublereal) (static_cast<double>(static_cast<double>(*feq_gen_d_d_) * dep) - static_cast<double>(dep) * dep);
    *a = dab * pow_dd(&feq_gen_d_d_1, &c_b2) + static_cast<double>(static_cast<double>(feq_gen_z_d_) * feq_gen_z_d_) * dac;
/* SOURCE riserclv.for:32 */
/*<       if(a.le.0.)a=0.000001 >*/
    if (*a <= (float)0.) {
	*a = (float)1e-6;
    }
/* SOURCE riserclv.for:33 */
/*<       t=2.*(z*z-dab*dab)**0.5 >*/
    feq_gen_d_d_1 = (doublereal) (static_cast<double>(static_cast<double>(feq_gen_z_d_) * feq_gen_z_d_) - static_cast<double>(dab) * dab);
    t = pow_dd(&feq_gen_d_d_1, &c_b2) * (float)2.;
/* SOURCE riserclv.for:34 */
/*<       wp=d*dac >*/
    wp = static_cast<double>(*feq_gen_d_d_) * dac;
/* SOURCE riserclv.for:35 */
/*<       hd=a/t >*/
    *hd = static_cast<double>(*a) / t;
/* SOURCE riserclv.for:36 */
/*<       r=a/wp >*/
    *feq_gen_r_d_ = static_cast<double>(*a) / wp;
/* SOURCE riserclv.for:37 */
/*<       return >*/
    return 0;
/* SOURCE riserclv.for:38 */
/*<       end >*/
} /* qculcir_ */

/*     *********** */
/*     *         * */
/*     * QCULREC */
/*     *         * */
/*     *********** */
/* SOURCE riserclv.for:45 */
/*<       subroutineqculrec(y,d,w,a,r,hd) >*/
/* Subroutine */ int qculrec_(real *y, real *feq_gen_d_d_, real *w, real *a, real *feq_gen_r_d_,
	 real *hd)
{
    real dep;


/*     This subroutine computes area, depth, and hydraulic radius for */
/*     rectangular channel . */

/*     Dummy arguments. */
/* SOURCE riserclv.for:53 */
/*<       realy,d,w,a,r,hd >*/
/*     Local values */
/* SOURCE riserclv.for:57 */
/*<       realdep >*/
/* *********************************************************************** */
/* SOURCE riserclv.for:59 */
/*<       dep=y >*/
    dep = *y;
/* SOURCE riserclv.for:60 */
/*<       if(dep.ge.d)dep=0.9999*d >*/
    if (dep >= *feq_gen_d_d_) {
	dep = static_cast<double>(*feq_gen_d_d_) * (float).9999;
    }
/* SOURCE riserclv.for:61 */
/*<       if(dep.le.0.)dep=0.0001*d >*/
    if (dep <= (float)0.) {
	dep = static_cast<double>(*feq_gen_d_d_) * (float)1e-4;
    }
/* SOURCE riserclv.for:62 */
/*<       a=w*dep >*/
    *a = static_cast<double>(*w) * dep;
/* SOURCE riserclv.for:63 */
/*<       r=w*dep/(w+2.*dep) >*/
    *feq_gen_r_d_ = static_cast<double>(static_cast<double>(*w) * dep) / (static_cast<double>(*w) + static_cast<double>(dep) * (float)2.);
/* SOURCE riserclv.for:64 */
/*<       hd=dep >*/
    *hd = dep;
/* SOURCE riserclv.for:65 */
/*<       return >*/
    return 0;
/* SOURCE riserclv.for:66 */
/*<       end >*/
} /* qculrec_ */

/*     *********** */
/*     *         * */
/*     * QCULWEI */
/*     *         * */
/*     *********** */
/* SOURCE riserclv.for:73 */
/*<        >*/
/* Subroutine */ int qculwei_(real *qw, char *code, real *hwe, real *twe, 
	real *ggap, integer *barrel, integer *gtype, real *inel, real *outel, 
	real *l, real *feq_gen_d_d_, real *w, real *n, real *k, real *feq_gen_c_d_, real *hw, 
	real *tw, real *ke, real *wb, real *we, real *swb, real *swe, real *
	cw, real *a, real *aw, ftnlen code_len)
{
    /* System generated locals */
    real feq_gen_r_d_1;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *);

    /* Local variables */
    real feq_gen_h_d_, feq_gen_r_d_, hd, kwe, qsw;
    extern /* Subroutine */ int qculrec_(real *, real *, real *, real *, real 
	    *, real *), qculcir_(real *, real *, real *, real *, real *);

/*     This subroutine computes culvert flow when weir control exists */
/*     (flashboard and riser) */
/*     Dummy arguments */
/* SOURCE riserclv.for:83 */
/*<       integerbarrel,gtype >*/
/* SOURCE riserclv.for:84 */
/*<       realinel,l,n,k,ke,kwe >*/
/* SOURCE riserclv.for:85 */
/*<       charactercode*3 >*/
/* ********************************************************************** */
/* SOURCE riserclv.for:88 */
/*<       h=hwe-we >*/
    feq_gen_h_d_ = static_cast<double>(*hwe) - *we;
/* SOURCE riserclv.for:90 */
/*<       qw=cw*wb*h**1.5 >*/
    feq_gen_d_d_1 = (doublereal) feq_gen_h_d_;
    *qw = static_cast<double>(*cw) * *wb * pow_dd(&feq_gen_d_d_1, &c_b9);
/* SOURCE riserclv.for:91 */
/*<       if(twe.gt.we)qw=qw*(1.-((twe-we)/(hwe-we))**1.5)**0.385 >*/
    if (*twe > *we) {
	feq_gen_d_d_2 = (doublereal) (static_cast<double>((static_cast<double>(*twe) - *we)) / (static_cast<double>(*hwe) - *we));
	feq_gen_d_d_1 = (doublereal) ((float)1. - pow_dd(&feq_gen_d_d_2, &c_b9));
	*qw *= pow_dd(&feq_gen_d_d_1, &c_b10);
    }
/* SOURCE riserclv.for:92 */
/*<       if(hwe.gt.swe)then >*/
    if (*hwe > *swe) {
/* SOURCE riserclv.for:93 */
/*<       qsw=cw*swb*(hwe-swe)**1.5 >*/
	feq_gen_d_d_1 = (doublereal) (static_cast<double>(*hwe) - *swe);
	qsw = static_cast<double>(*cw) * *swb * pow_dd(&feq_gen_d_d_1, &c_b9);
/* SOURCE riserclv.for:94 */
/*<       if(twe.gt.swe)qsw=qsw*(1.-((twe-swe)/(hwe-swe))**1.5)**0.385 >*/
	if (*twe > *swe) {
	    feq_gen_d_d_2 = (doublereal) (static_cast<double>((static_cast<double>(*twe) - *swe)) / (static_cast<double>(*hwe) - *swe));
	    feq_gen_d_d_1 = (doublereal) ((float)1. - pow_dd(&feq_gen_d_d_2, &c_b9));
	    qsw *= pow_dd(&feq_gen_d_d_1, &c_b10);
	}
/* SOURCE riserclv.for:96 */
/*<       qw=qw+qsw >*/
	*qw += qsw;
/* SOURCE riserclv.for:97 */
/*<       endif >*/
    }
/* *****  MODIFY ENTRANCE LOSS COEFFICIENT FOR CULVERT FLOW COMPUTATION */
/* *****      ASSUME ENTRANCE LOSS COEFFICIENT OVER WEIR TO BE 0.10 */
/* SOURCE riserclv.for:100 */
/*<       kwe=0.10 >*/
    kwe = (float).1;
/* SOURCE riserclv.for:101 */
/*<       aw=wb*h >*/
    *aw = static_cast<double>(*wb) * feq_gen_h_d_;
/* SOURCE riserclv.for:102 */
/*<       if(hwe.gt.swe)aw=aw+(hwe-swe)*swb >*/
    if (*hwe > *swe) {
	*aw += static_cast<double>((static_cast<double>(*hwe) - *swe)) * *swb;
    }
/* SOURCE riserclv.for:103 */
/*<       if(barrel.eq.0)callqculcir(hw,d,a,r,hd) >*/
    if (*barrel == 0) {
	qculcir_(hw, feq_gen_d_d_, a, &feq_gen_r_d_, &hd);
    }
/* SOURCE riserclv.for:104 */
/*<       if(barrel.eq.1)callqculrec(hw,d,w,a,r,hd) >*/
    if (*barrel == 1) {
	qculrec_(hw, feq_gen_d_d_, w, a, &feq_gen_r_d_, &hd);
    }
/* SOURCE riserclv.for:105 */
/*<       ke=kwe*(a/aw)**2+k >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(*a) / *aw;
    *ke = static_cast<double>(static_cast<double>(kwe) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) + *k;
/* SOURCE riserclv.for:106 */
/*<       code(2:2)='U' >*/
    *(unsigned char *)&code[1] = 'U';
/* SOURCE riserclv.for:107 */
/*<       code(3:3)='F' >*/
    *(unsigned char *)&code[2] = 'F';
/* SOURCE riserclv.for:108 */
/*<       if(twe.gt.we)code(3:3)='S' >*/
    if (*twe > *we) {
	*(unsigned char *)&code[2] = 'S';
    }
/* SOURCE riserclv.for:109 */
/*<       return >*/
    return 0;
/* SOURCE riserclv.for:110 */
/*<       end >*/
} /* qculwei_ */

/*     *********** */
/*     *         * */
/*     * QCULGAT */
/*     *         * */
/*     *********** */
/* SOURCE riserclv.for:118 */
/*<       subroutineqculgat(gtype,barrel,hw,ggap,d,w,k,ke,a,ag) >*/
/* Subroutine */ int qculgat_(integer *gtype, integer *barrel, real *hw, real 
	*ggap, real *feq_gen_d_d_, real *w, real *k, real *ke, real *a, real *ag)
{
    /* System generated locals */
    real feq_gen_r_d_1;

    /* Local variables */
    real feq_gen_r_d_, feq_gen_z_d_, a1, hd, ag1, ggap1;
    extern /* Subroutine */ int qculrec_(real *, real *, real *, real *, real 
	    *, real *), qculcir_(real *, real *, real *, real *, real *);


/*     THIS SUBROUTINE COMPUTES GATE CONTROL PARAMETERS FOR GENERAL */
/*     CULVERT ROUTINE <QCULV> */

/*     Dummy arguments */
/* SOURCE riserclv.for:125 */
/*<       realk,ke >*/
/* SOURCE riserclv.for:126 */
/*<       integerbarrel,gtype >*/
/* *********************************************************************** */
/* SOURCE riserclv.for:129 */
/*<       if(gtype.eq.0.and.barrel.eq.0)then >*/
    if (*gtype == 0 && *barrel == 0) {
/* SOURCE riserclv.for:130 */
/*<       z=d/2. >*/
	feq_gen_z_d_ = static_cast<double>(*feq_gen_d_d_) / (float)2.;
/* SOURCE riserclv.for:131 */
/*<       ggap1=z-ggap/2. >*/
	ggap1 = static_cast<double>(feq_gen_z_d_) - static_cast<double>(*ggap) / (float)2.;
/* SOURCE riserclv.for:132 */
/*<       callqculcir(ggap1,d,ag1,r,hd) >*/
	qculcir_(&ggap1, feq_gen_d_d_, &ag1, &feq_gen_r_d_, &hd);
/* SOURCE riserclv.for:133 */
/*<       a1=3.1416*z**2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = feq_gen_z_d_;
	a1 = static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * (float)3.1416;
/* SOURCE riserclv.for:134 */
/*<       ag=a1-2.*ag1 >*/
	*ag = static_cast<double>(a1) - static_cast<double>(ag1) * (float)2.;
/* SOURCE riserclv.for:135 */
/*<       callqculcir(hw,d,a,r,hd) >*/
	qculcir_(hw, feq_gen_d_d_, a, &feq_gen_r_d_, &hd);
/* SOURCE riserclv.for:136 */
/*<       ke=k*(a/ag)**2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(*a) / *ag;
	*ke = static_cast<double>(*k) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE riserclv.for:137 */
/*<       elseif(gtype.ge.1.and.barrel.eq.0)then >*/
    } else if (*gtype >= 1 && *barrel == 0) {
/* SOURCE riserclv.for:138 */
/*<       callqculcir(ggap,d,ag,r,hd) >*/
	qculcir_(ggap, feq_gen_d_d_, ag, &feq_gen_r_d_, &hd);
/* SOURCE riserclv.for:139 */
/*<       callqculcir(hw,d,a,r,hd) >*/
	qculcir_(hw, feq_gen_d_d_, a, &feq_gen_r_d_, &hd);
/* SOURCE riserclv.for:140 */
/*<       if(gtype.ne.2)ke=k*(a/ag)**2 >*/
	if (*gtype != 2) {
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(*a) / *ag;
	    *ke = static_cast<double>(*k) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
	}
/* SOURCE riserclv.for:141 */
/*<       else >*/
    } else {
/* SOURCE riserclv.for:142 */
/*<       ag=ggap*w >*/
	*ag = static_cast<double>(*ggap) * *w;
/* SOURCE riserclv.for:143 */
/*<       callqculrec(hw,d,w,a,r,hd) >*/
	qculrec_(hw, feq_gen_d_d_, w, a, &feq_gen_r_d_, &hd);
/* SOURCE riserclv.for:144 */
/*<       if(gtype.ne.2)ke=k*(a/ag)**2 >*/
	if (*gtype != 2) {
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(*a) / *ag;
	    *ke = static_cast<double>(*k) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
	}
/* SOURCE riserclv.for:145 */
/*<       endif >*/
    }

/* SOURCE riserclv.for:147 */
/*<       return >*/
    return 0;
/* SOURCE riserclv.for:148 */
/*<       end >*/
} /* qculgat_ */

/*     *********** */
/*     *         * */
/*     * QCULDIT */
/*     *         * */
/*     *********** */
/* SOURCE riserclv.for:156 */
/*<        >*/
/* Subroutine */ int qculdit_(real *qc, char *code, real *hwe, real *twe, 
	real *ggap, integer *barrel, integer *gtype, real *inel, real *outel, 
	real *l, real *feq_gen_d_d_, real *w, real *n, real *k, real *feq_gen_c_d_, real *hw, 
	real *tw, real *ke, ftnlen code_len)
{
    /* System generated locals */
    real feq_gen_r_d_1;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;

    /* Builtin functions */
    double sqrt(doublereal), pow_dd(doublereal *, doublereal *);

    /* Local variables */
    real a, f;
    integer feq_gen_i_d_;
    real q, s, a1, a2, q1, q2, q3, r1, r2, v1, v2, y1, y2, ag, sb, sc, y11, 
	    hd1, hd2, yc1, yc2, hw1, hd22, dev, dev1, dev2;
    integer iadj;
    real froude, convey;
    extern /* Subroutine */ int qculrec_(real *, real *, real *, real *, real 
	    *, real *), qculgat_(integer *, integer *, real *, real *, real *,
	     real *, real *, real *, real *, real *), qculcir_(real *, real *,
	     real *, real *, real *);


/*     This subroutine computes open channel flow through culvert */

/* SOURCE riserclv.for:162 */
/*<       integerbarrel,gtype >*/
/* SOURCE riserclv.for:163 */
/*<       realinel,l,n,k,ke,froude >*/
/* SOURCE riserclv.for:164 */
/*<       charactercode*3 >*/
/* *********************************************************************** */
/* SOURCE riserclv.for:166 */
/*<       a=-999.0 >*/
    a = (float)-999.;
/* SOURCE riserclv.for:167 */
/*<       ag=-99.0 >*/
    ag = (float)-99.;
/* SOURCE riserclv.for:168 */
/*<       q1=9999.0 >*/
    q1 = (float)9999.;
/* SOURCE riserclv.for:169 */
/*<       q2=9999.0 >*/
    q2 = (float)9999.;
/* SOURCE riserclv.for:170 */
/*<       q3=9999.0 >*/
    q3 = (float)9999.;
/* SOURCE riserclv.for:171 */
/*<       if(gtype.eq.2)then >*/
    if (*gtype == 2) {
/* SOURCE riserclv.for:172 */
/*<       ke=0.25*ke >*/
	*ke *= static_cast<double>((float).25);
/* SOURCE riserclv.for:173 */
/*<       elseif(hw.lt.1.3*ggap)then >*/
    } else if (*hw < static_cast<double>(*ggap) * (float)1.3) {
/* SOURCE riserclv.for:174 */
/*<       ke=0.25*k >*/
	*ke = static_cast<double>(*k) * (float).25;
/* SOURCE riserclv.for:175 */
/*<       else >*/
    } else {
/* SOURCE riserclv.for:176 */
/*<       callqculgat(gtype,barrel,hw,ggap,d,w,k,ke,a,ag) >*/
	qculgat_(gtype, barrel, hw, ggap, feq_gen_d_d_, w, k, ke, &a, &ag);
/* SOURCE riserclv.for:177 */
/*<       ke=0.25*ke >*/
	*ke *= static_cast<double>((float).25);
/* SOURCE riserclv.for:178 */
/*<       endif >*/
    }
/* ***** */
/* *****   INLET CONTROL */
/* ***** */
/* SOURCE riserclv.for:182 */
/*<       if(barrel.eq.1)goto30 >*/
    if (*barrel == 1) {
	goto L30;
    }
/* SOURCE riserclv.for:183 */
/*<       yc1=0.75*hw >*/
    yc1 = static_cast<double>(*hw) * (float).75;
/* *****  ITERATION FOR INLET CRITICAL DEPTH YC1 */
/* SOURCE riserclv.for:185 */
/*<       do10i=1,250 >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 250; ++feq_gen_i_d_) {
/* SOURCE riserclv.for:186 */
/*<       callqculcir(yc1,d,a1,r1,hd1) >*/
	qculcir_(&yc1, feq_gen_d_d_, &a1, &r1, &hd1);
/* SOURCE riserclv.for:187 */
/*<       hw1=yc1+(1.+ke)*hd1/2. >*/
	hw1 = static_cast<double>(yc1) + static_cast<double>(static_cast<double>((static_cast<double>(*ke) + (float)1.)) * hd1) / (float)2.;
/* SOURCE riserclv.for:188 */
/*<       dev=(hw-hw1) >*/
	dev = static_cast<double>(*hw) - hw1;
/* SOURCE riserclv.for:189 */
/*<       if(abs(dev).le.0.005)goto20 >*/
	if (dabs(dev) <= (float).005) {
	    goto L20;
	}
/* SOURCE riserclv.for:190 */
/*<       yc1=yc1+dev*0.1 >*/
	yc1 += static_cast<double>(static_cast<double>(dev) * (float).1);
/* SOURCE riserclv.for:191 */
/*<    10 continue >*/
/* L10: */
    }
/* ***** */
/* SOURCE riserclv.for:193 */
/*<    20 q=sqrt(32.2*hd1)*a1 >*/
L20:
    q = sqrt(static_cast<double>(hd1) * (float)32.2) * a1;
/* SOURCE riserclv.for:194 */
/*<       goto40 >*/
    goto L40;
/* SOURCE riserclv.for:195 */
/*<    30 yc1=2.*hw/(3.+ke) >*/
L30:
    yc1 = static_cast<double>(static_cast<double>(*hw) * (float)2.) / (static_cast<double>(*ke) + (float)3.);
/* SOURCE riserclv.for:196 */
/*<       callqculrec(yc1,d,w,a1,r1,hd1) >*/
    qculrec_(&yc1, feq_gen_d_d_, w, &a1, &r1, &hd1);
/* SOURCE riserclv.for:197 */
/*<       q=sqrt(32.2*hd1)*a1 >*/
    q = sqrt(static_cast<double>(hd1) * (float)32.2) * a1;
/* SOURCE riserclv.for:198 */
/*<    40 q1=q >*/
L40:
    q1 = q;
/* SOURCE riserclv.for:199 */
/*<       v1=q1/a1 >*/
    v1 = static_cast<double>(q1) / a1;
/* SOURCE riserclv.for:200 */
/*<       froude=v1/sqrt(32.2*hd1) >*/
    froude = v1 / sqrt(static_cast<double>(hd1) * (float)32.2);
/* SOURCE riserclv.for:201 */
/*<       if(twe.gt.yc1+inel)goto120 >*/
    if (*twe > static_cast<double>(yc1) + *inel) {
	goto L120;
    }
/* SOURCE riserclv.for:202 */
/*<       sc=(q*n/(1.49*a1*r1**.6667))**2 >*/
    feq_gen_d_d_1 = (doublereal) r1;
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(q) * *n / (static_cast<double>(a1) * (float)1.49 * pow_dd(&feq_gen_d_d_1, &c_b25));
    sc = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE riserclv.for:203 */
/*<       sb=(inel-outel)/l >*/
    sb = static_cast<double>((static_cast<double>(*inel) - *outel)) / *l;
/* SOURCE riserclv.for:204 */
/*<       if(sb.ge.sc)then >*/
    if (sb >= sc) {
/* SOURCE riserclv.for:205 */
/*<       qc=q1 >*/
	*qc = q1;
/* SOURCE riserclv.for:206 */
/*<       code(1:1)='H' >*/
	*(unsigned char *)code = 'H';
/* SOURCE riserclv.for:207 */
/*<       code(2:2)='U' >*/
	*(unsigned char *)&code[1] = 'U';
/* SOURCE riserclv.for:208 */
/*<       code(3:3)='F' >*/
	*(unsigned char *)&code[2] = 'F';
/* SOURCE riserclv.for:209 */
/*<       return >*/
	return 0;
/* SOURCE riserclv.for:210 */
/*<       endif >*/
    }
/* ***** */
/* *****  FREE FALL AT OUTLET */
/* ***** */
/* SOURCE riserclv.for:214 */
/*<       yc2=0.8*yc1 >*/
    yc2 = static_cast<double>(yc1) * (float).8;
/* SOURCE riserclv.for:215 */
/*<       y1=yc1+outel-inel >*/
    y1 = static_cast<double>(static_cast<double>(yc1) + *outel) - *inel;
/* SOURCE riserclv.for:216 */
/*<       v1=1e-20 >*/
    v1 = (float)1e-20;
/* SOURCE riserclv.for:217 */
/*<       v2=1e-20 >*/
    v2 = (float)1e-20;
/* *****  ITERATION FOR OUTLET CRITICAL DEPTH YC2 */
/* SOURCE riserclv.for:219 */
/*<       do80i=1,1000 >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 1000; ++feq_gen_i_d_) {
/* SOURCE riserclv.for:220 */
/*<       iadj=i/100+1 >*/
	iadj = feq_gen_i_d_ / 100 + 1;
/* SOURCE riserclv.for:221 */
/*<       if(y1.ge.hw)y1=0.999*hw >*/
	if (y1 >= *hw) {
	    y1 = static_cast<double>(*hw) * (float).999;
	}
/* SOURCE riserclv.for:222 */
/*<       if(yc2.ge.(y1+inel-outel))yc2=(y1+inel-outel)*0.999 >*/
	if (yc2 >= static_cast<double>(static_cast<double>(y1) + *inel) - *outel) {
	    yc2 = static_cast<double>((static_cast<double>(static_cast<double>(y1) + *inel) - *outel)) * (float).999;
	}
/* SOURCE riserclv.for:223 */
/*<       if(yc2.le.0.0)yc2=0.001 >*/
	if (yc2 <= (float)0.) {
	    yc2 = (float).001;
	}
/* SOURCE riserclv.for:224 */
/*<       if(y1.le.yc2+outel-inel)y1=(yc2+outel-inel)*1.001 >*/
	if (y1 <= static_cast<double>(static_cast<double>(yc2) + *outel) - *inel) {
	    y1 = static_cast<double>((static_cast<double>(static_cast<double>(yc2) + *outel) - *inel)) * (float)1.001;
	}
/* SOURCE riserclv.for:225 */
/*<       if(barrel.eq.0)then >*/
	if (*barrel == 0) {
/* SOURCE riserclv.for:226 */
/*<       callqculcir(y1,d,a1,r1,hd1) >*/
	    qculcir_(&y1, feq_gen_d_d_, &a1, &r1, &hd1);
/* SOURCE riserclv.for:227 */
/*<       callqculcir(yc2,d,a2,r2,hd2) >*/
	    qculcir_(&yc2, feq_gen_d_d_, &a2, &r2, &hd2);
/* SOURCE riserclv.for:228 */
/*<       else >*/
	} else {
/* SOURCE riserclv.for:229 */
/*<       callqculrec(y1,d,w,a1,r1,hd1) >*/
	    qculrec_(&y1, feq_gen_d_d_, w, &a1, &r1, &hd1);
/* SOURCE riserclv.for:230 */
/*<       callqculrec(yc2,d,w,a2,r2,hd2) >*/
	    qculrec_(&yc2, feq_gen_d_d_, w, &a2, &r2, &hd2);
/* SOURCE riserclv.for:231 */
/*<       endif >*/
	}
/* SOURCE riserclv.for:232 */
/*<       convey=1.49/n*sqrt(a1*r1**.6667*a2*r2**.6667) >*/
	feq_gen_d_d_1 = (doublereal) r1;
	feq_gen_d_d_2 = (doublereal) r2;
	convey = static_cast<double>((float)1.49) / *n * sqrt(a1 * pow_dd(&feq_gen_d_d_1, &c_b25) * a2 * 
		pow_dd(&feq_gen_d_d_2, &c_b25));
/* SOURCE riserclv.for:233 */
/*<       f=(y1+inel)-(yc2+outel) >*/
	f = static_cast<double>(static_cast<double>(y1) + *inel) - (static_cast<double>(yc2) + *outel);
/* SOURCE riserclv.for:234 */
/*<       s=f/l >*/
	s = static_cast<double>(f) / *l;
/* SOURCE riserclv.for:235 */
/*<       if(s.le.0.)s=0.0001 >*/
	if (s <= (float)0.) {
	    s = (float)1e-4;
	}
/* SOURCE riserclv.for:236 */
/*<       q=convey*sqrt(s) >*/
	q = convey * sqrt(s);
/* SOURCE riserclv.for:237 */
/*<       v1=q/a1 >*/
	v1 = static_cast<double>(q) / a1;
/* SOURCE riserclv.for:238 */
/*<       v2=q/a2 >*/
	v2 = static_cast<double>(q) / a2;
/* SOURCE riserclv.for:239 */
/*<       froude=v2/sqrt(32.2*hd2) >*/
	froude = v2 / sqrt(static_cast<double>(hd2) * (float)32.2);
/* SOURCE riserclv.for:240 */
/*<       hd22=v2*v2/32.2 >*/
	hd22 = static_cast<double>(static_cast<double>(v2) * v2) / (float)32.2;
/* SOURCE riserclv.for:241 */
/*<       dev2=hd22-hd2 >*/
	dev2 = static_cast<double>(hd22) - hd2;
/* SOURCE riserclv.for:242 */
/*<       if(abs(dev2).le.0.005)goto70 >*/
	if (dabs(dev2) <= (float).005) {
	    goto L70;
	}
/* SOURCE riserclv.for:243 */
/*<       yc2=yc2+dev2*0.1/iadj >*/
	yc2 += static_cast<double>(static_cast<double>(static_cast<double>(dev2) * (float).1) / iadj);
/* SOURCE riserclv.for:244 */
/*<       goto80 >*/
	goto L80;
/* *****  ITERATION FOR Y1 */
/* SOURCE riserclv.for:246 */
/*<    70 y11=hw-(1.+ke)*v1**2/64.4 >*/
L70:
/* Computing 2nd power */
	feq_gen_r_d_1 = v1;
	y11 = static_cast<double>(*hw) - static_cast<double>(static_cast<double>((static_cast<double>(*ke) + (float)1.)) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / (float)64.4;
/* SOURCE riserclv.for:247 */
/*<       dev1=y11-y1 >*/
	dev1 = static_cast<double>(y11) - y1;
/* SOURCE riserclv.for:248 */
/*<       if(abs(dev1).le.0.005)goto90 >*/
	if (dabs(dev1) <= (float).005) {
	    goto L90;
	}
/* SOURCE riserclv.for:249 */
/*<       y1=y1+dev1*0.1/iadj >*/
	y1 += static_cast<double>(static_cast<double>(static_cast<double>(dev1) * (float).1) / iadj);
/* SOURCE riserclv.for:250 */
/*<    80 continue >*/
L80:
	;
    }
/* ***** */
/* SOURCE riserclv.for:252 */
/*<    90 q2=q >*/
L90:
    q2 = q;
/* SOURCE riserclv.for:253 */
/*<       code(2:2)='U' >*/
    *(unsigned char *)&code[1] = 'U';
/* SOURCE riserclv.for:254 */
/*<       if(ag.lt.a)code(2:2)='C' >*/
    if (ag < a) {
	*(unsigned char *)&code[1] = 'C';
    }
/* SOURCE riserclv.for:255 */
/*<       code(3:3)='F' >*/
    *(unsigned char *)&code[2] = 'F';
/* SOURCE riserclv.for:256 */
/*<       if(i.ge.1000)goto170 >*/
    if (feq_gen_i_d_ >= 1000) {
	goto L170;
    }
/* SOURCE riserclv.for:257 */
/*<       if(tw.gt.yc2)goto120 >*/
    if (*tw > yc2) {
	goto L120;
    }
/* SOURCE riserclv.for:258 */
/*<       if(q2.le.q1)then >*/
    if (q2 <= q1) {
/* SOURCE riserclv.for:259 */
/*<       qc=q2 >*/
	*qc = q2;
/* SOURCE riserclv.for:260 */
/*<       code(1:1)='T' >*/
	*(unsigned char *)code = 'T';
/* SOURCE riserclv.for:261 */
/*<       else >*/
    } else {
/* SOURCE riserclv.for:262 */
/*<       qc=q1 >*/
	*qc = q1;
/* SOURCE riserclv.for:263 */
/*<       code(1:1)='H' >*/
	*(unsigned char *)code = 'H';
/* SOURCE riserclv.for:264 */
/*<       endif >*/
    }
/* SOURCE riserclv.for:265 */
/*<       return >*/
    return 0;
/* ***** */
/* *****   TAILWATER EFFECT */
/* ***** */
/* SOURCE riserclv.for:269 */
/*<   120 y1=1.01*(twe-inel) >*/
L120:
    y1 = static_cast<double>((static_cast<double>(*twe) - *inel)) * (float)1.01;
/* SOURCE riserclv.for:270 */
/*<       code(2:2)='U' >*/
    *(unsigned char *)&code[1] = 'U';
/* SOURCE riserclv.for:271 */
/*<       if(ag.lt.a)code(2:2)='C' >*/
    if (ag < a) {
	*(unsigned char *)&code[1] = 'C';
    }
/* SOURCE riserclv.for:272 */
/*<       code(3:3)='S' >*/
    *(unsigned char *)&code[2] = 'S';
/* SOURCE riserclv.for:273 */
/*<       y2=tw >*/
    y2 = *tw;
/* SOURCE riserclv.for:274 */
/*<       v1=1e-20 >*/
    v1 = (float)1e-20;
/* SOURCE riserclv.for:275 */
/*<       v2=1e-20 >*/
    v2 = (float)1e-20;
/* *****  ITERATION FOR Y1 */
/* SOURCE riserclv.for:277 */
/*<       do130i=1,250 >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 250; ++feq_gen_i_d_) {
/* SOURCE riserclv.for:278 */
/*<       iadj=i/50+1 >*/
	iadj = feq_gen_i_d_ / 50 + 1;
/* SOURCE riserclv.for:279 */
/*<       if(y1.ge.hw)y1=hw*0.999 >*/
	if (y1 >= *hw) {
	    y1 = static_cast<double>(*hw) * (float).999;
	}
/* SOURCE riserclv.for:280 */
/*<       if(y1.le.(twe-inel))y1=(twe-inel)*1.001 >*/
	if (y1 <= static_cast<double>(*twe) - *inel) {
	    y1 = static_cast<double>((static_cast<double>(*twe) - *inel)) * (float)1.001;
	}
/* SOURCE riserclv.for:281 */
/*<       if(barrel.eq.0)then >*/
	if (*barrel == 0) {
/* SOURCE riserclv.for:282 */
/*<       callqculcir(y1,d,a1,r1,hd1) >*/
	    qculcir_(&y1, feq_gen_d_d_, &a1, &r1, &hd1);
/* SOURCE riserclv.for:283 */
/*<       callqculcir(y2,d,a2,r2,hd2) >*/
	    qculcir_(&y2, feq_gen_d_d_, &a2, &r2, &hd2);
/* SOURCE riserclv.for:284 */
/*<       else >*/
	} else {
/* SOURCE riserclv.for:285 */
/*<       callqculrec(y1,d,w,a1,r1,hd1) >*/
	    qculrec_(&y1, feq_gen_d_d_, w, &a1, &r1, &hd1);
/* SOURCE riserclv.for:286 */
/*<       callqculrec(y2,d,w,a2,r2,hd2) >*/
	    qculrec_(&y2, feq_gen_d_d_, w, &a2, &r2, &hd2);
/* SOURCE riserclv.for:287 */
/*<       endif >*/
	}
/* SOURCE riserclv.for:288 */
/*<       convey=1.49/n*sqrt(a1*r1**.6667*a2*r2**.6667) >*/
	feq_gen_d_d_1 = (doublereal) r1;
	feq_gen_d_d_2 = (doublereal) r2;
	convey = static_cast<double>((float)1.49) / *n * sqrt(a1 * pow_dd(&feq_gen_d_d_1, &c_b25) * a2 * 
		pow_dd(&feq_gen_d_d_2, &c_b25));
/* SOURCE riserclv.for:289 */
/*<       f=(y1+inel)-(y2+outel) >*/
	f = static_cast<double>(static_cast<double>(y1) + *inel) - (static_cast<double>(y2) + *outel);
/* SOURCE riserclv.for:290 */
/*<       s=f/l >*/
	s = static_cast<double>(f) / *l;
/* SOURCE riserclv.for:291 */
/*<       if(s.le.0.)s=0.0001 >*/
	if (s <= (float)0.) {
	    s = (float)1e-4;
	}
/* SOURCE riserclv.for:292 */
/*<       q=convey*sqrt(s) >*/
	q = convey * sqrt(s);
/* SOURCE riserclv.for:293 */
/*<       v1=q/a1 >*/
	v1 = static_cast<double>(q) / a1;
/* SOURCE riserclv.for:294 */
/*<       v2=q/a2 >*/
	v2 = static_cast<double>(q) / a2;
/* SOURCE riserclv.for:295 */
/*<       y11=hw-(1+ke)*v1**2/64.4 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = v1;
	y11 = static_cast<double>(*hw) - static_cast<double>(static_cast<double>((static_cast<double>(*ke) + 1)) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / (float)64.4;
/* SOURCE riserclv.for:296 */
/*<       dev=y11-y1 >*/
	dev = static_cast<double>(y11) - y1;
/* SOURCE riserclv.for:297 */
/*<       if(abs(dev).le.0.005)goto140 >*/
	if (dabs(dev) <= (float).005) {
	    goto L140;
	}
/* SOURCE riserclv.for:298 */
/*<       y1=y1+dev*0.1/iadj >*/
	y1 += static_cast<double>(static_cast<double>(static_cast<double>(dev) * (float).1) / iadj);
/* SOURCE riserclv.for:299 */
/*<   130 continue >*/
/* L130: */
    }
/* ***** */
/* SOURCE riserclv.for:301 */
/*<   140 q3=q >*/
L140:
    q3 = q;
/* SOURCE riserclv.for:302 */
/*<       if(i.ge.250)goto170 >*/
    if (feq_gen_i_d_ >= 250) {
	goto L170;
    }
/* SOURCE riserclv.for:303 */
/*<       if(q3.le.q1)then >*/
    if (q3 <= q1) {
/* SOURCE riserclv.for:304 */
/*<       qc=q3 >*/
	*qc = q3;
/* SOURCE riserclv.for:305 */
/*<       code(1:1)='T' >*/
	*(unsigned char *)code = 'T';
/* SOURCE riserclv.for:306 */
/*<       else >*/
    } else {
/* SOURCE riserclv.for:307 */
/*<       qc=q1 >*/
	*qc = q1;
/* SOURCE riserclv.for:308 */
/*<       code(1:1)='H' >*/
	*(unsigned char *)code = 'H';
/* SOURCE riserclv.for:309 */
/*<       endif >*/
    }
/* SOURCE riserclv.for:310 */
/*<       return >*/
    return 0;
/* *****  ERROR DETECTION */
/* SOURCE riserclv.for:312 */
/*<   170 qc=min(q1,q2,q3) >*/
L170:
/* Computing MIN */
    feq_gen_r_d_1 = min(q1,q2);
    *qc = dmin(feq_gen_r_d_1,q3);
/* SOURCE riserclv.for:313 */
/*<       code(1:1)='?' >*/
    *(unsigned char *)code = '?';
/* SOURCE riserclv.for:314 */
/*<       return >*/
    return 0;
/* SOURCE riserclv.for:315 */
/*<       end >*/
} /* qculdit_ */

/*     *********** */
/*     *         * */
/*     * QCULORI */
/*     *         * */
/*     *********** */
/* SOURCE riserclv.for:322 */
/*<        >*/
/* Subroutine */ int qculori_(real *qc, char *code, real *hwe, real *twe, 
	real *ggap, integer *barrel, integer *gtype, real *inel, real *outel, 
	real *l, real *feq_gen_d_d_, real *w, real *n, real *k, real *feq_gen_c_d_, real *hw, 
	real *tw, real *ke, ftnlen code_len)
{
    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2;
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    double sqrt(doublereal), pow_dd(doublereal *, doublereal *);

    /* Local variables */
    real a, feq_gen_h_d_, q, feq_gen_r_d_, q1, q2, ag, kf;
    extern /* Subroutine */ int qculgat_(integer *, integer *, real *, real *,
	     real *, real *, real *, real *, real *, real *);


/*     This subroutine computes culvert flow when only part of pipe is */
/*     full. */

/* SOURCE riserclv.for:329 */
/*<       integerbarrel,gtype >*/
/* SOURCE riserclv.for:330 */
/*<       realinel,l,n,k,ke,kf >*/
/* SOURCE riserclv.for:331 */
/*<       charactercode*3 >*/
/* ********************************************************************** */
/* SOURCE riserclv.for:334 */
/*<       callqculgat(gtype,barrel,hw,ggap,d,w,k,ke,a,ag) >*/
    qculgat_(gtype, barrel, hw, ggap, feq_gen_d_d_, w, k, ke, &a, &ag);
/* SOURCE riserclv.for:335 */
/*<       h=hw-0.6*ggap >*/
    feq_gen_h_d_ = static_cast<double>(*hw) - static_cast<double>(*ggap) * (float).6;
/* SOURCE riserclv.for:336 */
/*<       q=c*ag*sqrt(64.4*h) >*/
    q = static_cast<double>(*feq_gen_c_d_) * ag * sqrt(static_cast<double>(feq_gen_h_d_) * (float)64.4);
/* SOURCE riserclv.for:337 */
/*<       q1=q >*/
    q1 = q;
/* SOURCE riserclv.for:338 */
/*<       if(hw.lt.1.3*d)then >*/
    if (*hw < static_cast<double>(*feq_gen_d_d_) * (float)1.3) {
/* SOURCE riserclv.for:339 */
/*<       qc=q1 >*/
	*qc = q1;
/* SOURCE riserclv.for:340 */
/*<       code(1:1)='O' >*/
	*(unsigned char *)code = 'O';
/* SOURCE riserclv.for:341 */
/*<       code(2:2)='U' >*/
	*(unsigned char *)&code[1] = 'U';
/* SOURCE riserclv.for:342 */
/*<       code(3:3)='F' >*/
	*(unsigned char *)&code[2] = 'F';
/* SOURCE riserclv.for:343 */
/*<       return >*/
	return 0;
/* SOURCE riserclv.for:344 */
/*<       endif >*/
    }
/*     Note by ddf:  Appears to assume that the piezometric level */
/*     at the pipe outlet is always 0.7*D.  Therefore, the tailwater */
/*     level must exceed the elevation at 0.7*D at the outlet */
/*     before the flow defined by an the full pipe relationship is affected. */
/* SOURCE riserclv.for:351 */
/*<       h=min(hwe-(outel+0.7*d),hwe-twe) >*/
/* Computing MIN */
    feq_gen_r_d_1 = static_cast<double>(*hwe) - (static_cast<double>(*outel) + static_cast<double>(*feq_gen_d_d_) * (float).7), feq_gen_r_d_2 = static_cast<double>(*hwe) - *twe;
    feq_gen_h_d_ = dmin(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE riserclv.for:352 */
/*<       if(barrel.eq.0)r=d/4. >*/
    if (*barrel == 0) {
	feq_gen_r_d_ = static_cast<double>(*feq_gen_d_d_) / (float)4.;
    }
/* SOURCE riserclv.for:353 */
/*<       if(barrel.eq.1)r=(d*w)/(2*d+w) >*/
    if (*barrel == 1) {
	feq_gen_r_d_ = static_cast<double>(static_cast<double>(*feq_gen_d_d_) * *w) / (static_cast<double>(static_cast<double>(*feq_gen_d_d_) * 2) + *w);
    }
/* SOURCE riserclv.for:354 */
/*<       kf=29.1*n**2*l/r**1.3333 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = *n;
    feq_gen_d_d_1 = (doublereal) feq_gen_r_d_;
    kf = static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * (float)29.1) * *l / pow_dd(&feq_gen_d_d_1, &c_b54);
/* SOURCE riserclv.for:355 */
/*<       q=a*sqrt(64.4*h/(1.+ke+kf)) >*/
    q = a * sqrt(static_cast<double>(static_cast<double>(feq_gen_h_d_) * (float)64.4) / (static_cast<double>(static_cast<double>(*ke) + (float)1.) + kf));
/* SOURCE riserclv.for:356 */
/*<       q2=q >*/
    q2 = q;
/* SOURCE riserclv.for:357 */
/*<       if(q2.le.q1)then >*/
    if (q2 <= q1) {
/* SOURCE riserclv.for:358 */
/*<       qc=q2 >*/
	*qc = q2;
/* SOURCE riserclv.for:359 */
/*<       code(1:1)='P' >*/
	*(unsigned char *)code = 'P';
/* SOURCE riserclv.for:360 */
/*<       if(hwe-(outel+0.7*d).lt.hwe-twe)then >*/
	if (static_cast<double>(*hwe) - (static_cast<double>(*outel) + static_cast<double>(*feq_gen_d_d_) * (float).7) < static_cast<double>(*hwe) - *twe) {
/* SOURCE riserclv.for:361 */
/*<       code(3:3)='F' >*/
	    *(unsigned char *)&code[2] = 'F';
/* SOURCE riserclv.for:362 */
/*<       else >*/
	} else {
/* SOURCE riserclv.for:363 */
/*<       code(3:3)='S' >*/
	    *(unsigned char *)&code[2] = 'S';
/* SOURCE riserclv.for:364 */
/*<       endif >*/
	}
/* SOURCE riserclv.for:365 */
/*<       else >*/
    } else {
/* SOURCE riserclv.for:366 */
/*<       qc=q1 >*/
	*qc = q1;
/* SOURCE riserclv.for:367 */
/*<       code(1:1)='O' >*/
	*(unsigned char *)code = 'O';
/*        Improper class given here in orginal. Change to free flow. */
/*         CODE(3:3) = 'S' */
/* SOURCE riserclv.for:370 */
/*<       code(3:3)='F' >*/
	*(unsigned char *)&code[2] = 'F';
/* SOURCE riserclv.for:371 */
/*<       endif >*/
    }
/* SOURCE riserclv.for:372 */
/*<       code(2:2)='U' >*/
    *(unsigned char *)&code[1] = 'U';
/* SOURCE riserclv.for:373 */
/*<       if(ag.lt.a)code(2:2)='C' >*/
    if (ag < a) {
	*(unsigned char *)&code[1] = 'C';
    }
/* SOURCE riserclv.for:374 */
/*<       return >*/
    return 0;
/* SOURCE riserclv.for:375 */
/*<       end >*/
} /* qculori_ */

/*     *********** */
/*     *         * */
/*     * QCULPIP */
/*     *         * */
/*     *********** */
/* SOURCE riserclv.for:382 */
/*<        >*/
/* Subroutine */ int qculpip_(real *qc, char *code, real *hwe, real *twe, 
	real *ggap, integer *barrel, integer *gtype, real *inel, real *outel, 
	real *l, real *feq_gen_d_d_, real *w, real *n, real *k, real *feq_gen_c_d_, real *hw, 
	real *tw, real *ke, ftnlen code_len)
{
    /* System generated locals */
    real feq_gen_r_d_1;
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *), sqrt(doublereal);

    /* Local variables */
    real a, feq_gen_h_d_, q, feq_gen_r_d_, ag, kf;
    extern /* Subroutine */ int qculgat_(integer *, integer *, real *, real *,
	     real *, real *, real *, real *, real *, real *);


/*     THIS SUBROUTINE COMPUTES CULVERT FLOW WHEN PIPE IS FULL */

/* SOURCE riserclv.for:388 */
/*<       integerbarrel,gtype >*/
/* SOURCE riserclv.for:389 */
/*<       realinel,l,n,k,ke,kf >*/
/* SOURCE riserclv.for:390 */
/*<       charactercode*3 >*/
/* *********************************************************************** */
/* SOURCE riserclv.for:392 */
/*<       callqculgat(gtype,barrel,hw,ggap,d,w,k,ke,a,ag) >*/
    qculgat_(gtype, barrel, hw, ggap, feq_gen_d_d_, w, k, ke, &a, &ag);
/* SOURCE riserclv.for:393 */
/*<       h=hwe-twe >*/
    feq_gen_h_d_ = static_cast<double>(*hwe) - *twe;
/* SOURCE riserclv.for:394 */
/*<       if(hw.le.(1.3*ggap))ke=0.25*ke >*/
    if (*hw <= static_cast<double>(*ggap) * (float)1.3) {
	*ke *= static_cast<double>((float).25);
    }
/* SOURCE riserclv.for:395 */
/*<       if(barrel.eq.0)r=d/4. >*/
    if (*barrel == 0) {
	feq_gen_r_d_ = static_cast<double>(*feq_gen_d_d_) / (float)4.;
    }
/* SOURCE riserclv.for:396 */
/*<       if(barrel.eq.1)r=(d*w)/(2*d+w) >*/
    if (*barrel == 1) {
	feq_gen_r_d_ = static_cast<double>(static_cast<double>(*feq_gen_d_d_) * *w) / (static_cast<double>(static_cast<double>(*feq_gen_d_d_) * 2) + *w);
    }
/* SOURCE riserclv.for:397 */
/*<       kf=29.1*n**2*l/r**1.3333 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = *n;
    feq_gen_d_d_1 = (doublereal) feq_gen_r_d_;
    kf = static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * (float)29.1) * *l / pow_dd(&feq_gen_d_d_1, &c_b54);
/* SOURCE riserclv.for:398 */
/*<       q=a*sqrt(64.4*h/(1.+ke+kf)) >*/
    q = a * sqrt(static_cast<double>(static_cast<double>(feq_gen_h_d_) * (float)64.4) / (static_cast<double>(static_cast<double>(*ke) + (float)1.) + kf));
/* SOURCE riserclv.for:399 */
/*<       qc=q >*/
    *qc = q;
/* SOURCE riserclv.for:400 */
/*<       code(1:1)='F' >*/
    *(unsigned char *)code = 'F';
/* SOURCE riserclv.for:401 */
/*<       code(2:2)='U' >*/
    *(unsigned char *)&code[1] = 'U';
/* SOURCE riserclv.for:402 */
/*<       if(ag.lt.a)code(2:2)='C' >*/
    if (ag < a) {
	*(unsigned char *)&code[1] = 'C';
    }
/* SOURCE riserclv.for:403 */
/*<       code(3:3)='S' >*/
    *(unsigned char *)&code[2] = 'S';
/* SOURCE riserclv.for:404 */
/*<       return >*/
    return 0;
/* SOURCE riserclv.for:405 */
/*<       end >*/
} /* qculpip_ */

/*     *********** */
/*     *         * */
/*     * SFWMD_QCULV  * */
/*     *         * */
/*     *********** */
/* SOURCE riserclv.for:413 */
/*<        >*/
/* Subroutine */ int feq_gen_sfwmd_qculv_d_(char *code, integer *gtype, integer *
	barrel, real *board, real *feq_gen_c_d_, real *cw, real *feq_gen_d_d_, real *hwe, real *
	inel, real *k, real *l, real *n, real *outel, real *swb, real *swe, 
	real *twe, real *w, real *wb, real *qa, ftnlen code_len)
{
    /* System generated locals */
    real feq_gen_r_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    logical weirctrl;
    real a, ke, qc, aw, we, hw, qw, tw, ggap, elmax;
    extern /* Subroutine */ int qculdit_(real *, char *, real *, real *, real 
	    *, integer *, integer *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, ftnlen), qculwei_(
	    real *, char *, real *, real *, real *, integer *, integer *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, ftnlen), qculpip_(real *, char *, real *, real *, 
	    real *, integer *, integer *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, ftnlen), 
	    qculori_(real *, char *, real *, real *, real *, integer *, 
	    integer *, real *, real *, real *, real *, real *, real *, real *,
	     real *, real *, real *, real *, ftnlen);

/*     Dummy arguments */
/* SOURCE riserclv.for:419 */
/*<       charactercode*3 >*/
/* SOURCE riserclv.for:420 */
/*<       integergtype,barrel >*/
/* SOURCE riserclv.for:421 */
/*<       realboard,c,cw,d,hwe,inel,k,l,n,outel,swb,swe,twe,w,wb,qa >*/
/* ************************************************************************ */
/*                      I D E N T I F I C A T I O N */
/*                      --------------------------- */
/* SUBROUTINE NAME          - QCULV (ORIGINALLY PROGRAM <CULVERT>) */
/* SUBROUTINE DESCRIPTION   - COMPUTES THE DISCHARGE THROUGH GATED */
/*                            CULVERTS */
/* ORIGINAL PROGRAMMER      - ANDREW FAN */
/*                            WATER RESOURCES DIVISION */
/*                            RESOURCE PLANNING DEPARTMENT */
/*                            SOUTH FLORIDA WATER MANAGEMENT DISTRICT */
/* REFERENCE                - FAN, ANDREW, PROGRAM DOCUMENTATION, */
/*                            A GENERAL PROGRAM TO COMPUTE FLOW THROUGH */
/*                            GATED CULVERTS, TECHNICAL MEMORANDUM, */
/*                            SFWMD, OCTOBER 1985. */
/* ORIGINAL PRODUCTION DATE - 10/31/83 (ORIGINAL PROGRAM DONE 10/8/82) */
/* ************************************************************************ */
/*                 L I S T   O F   IDENTIFIERS */
/*                 --------------------------------- */
/* VARIABLE   TYPE            DESCRIPTION OF USE */
/* --------   -------------   ------------------------------------------- */

/* BARREL     INTEGER         CULVERT SHAPE (0 = CIRCLE; 1 = BOX) */
/* BOARD      REAL            BOARD ELEVATION (GATE-OPENING), IN FEET */

/* C          REAL            GATE CONSTRICTION FLOW COEFFICIENT */
/*                               (RANGE = 0.6 (SQUARE-EDGE) TO */
/*                                        0.9 (ROUND-EDGE)) */
/* CODE       CHAR*3          FLOW REGIME INDICATOR, OUTPUT VARIABLE, */
/*                               WHERE: */
/*                               CODE(1:1) = TYPE CULVERT FLOW */
/*                                              F = FULL PIPE FLOW */
/*                                              H = HEADWATER-CONTROLLED */
/*                                                     (OPEN CHANNEL - */
/*                                                        INLET CONTROL) */
/*                                                        FLOW */
/*                                              O = ORIFICE-CONTROLLED */
/*                                                     (PARTIAL PIPE - */
/*                                                        NON-INLET */
/*                                                        CONTROL) FLOW */
/*                                              P = PARTIAL PIPE FLOW - */
/*                                                     INLET CONTROL */
/*                                              T = TAILWATER CONTROLLED */
/*                                                     (OPEN CHANNEL - */
/*                                                        NON-INLET */
/*                                                        CONTROL) FLOW */
/*                                              W = WEIR CONTROL */
/*                                              ? = CHECK "ERRORF" FOR */
/*                                                     POSSIBLE PROBLEM */
/*                                                     IN CALCULATING */
/*                                                     FLOW */
/*                               CODE(2:2) = CONTROLLED ("C") OR */
/*                                              UNCONTROLLED ("U") FLOW */
/*                                              INDICATOR */
/*                               CODE(3:3) = SUBMERGED ("S") OR */
/*                                              FREE ("F") FLOW INDICATOR */
/* CW         REAL            WEIR COEFFICIENT (APPROX. 3.3) */

/* D          REAL            CULVERT DIAMETER (CIRCLE) OR CULVERT */
/*                               VERTICAL HEIGHT (BOX) */

/* GTYPE      INTEGER         GATE TYPE CODE (0 = CIRCLE; 1 = RECTANGLE; */
/*                               2 = WEIR) */

/* HWE        REAL            HEADWATER (UPSTREAM STAGE) ELEVATION, */
/*                               IN FEET M.S.L. */
/* INEL       REAL            INLET INVERT ELEVATION (FEET M.S.L.) */
/* K          REAL            INLET LOSS COEFFICIENT */
/*                               (FLUSH HEADWALL </= 0.5; */
/*                                  ROUNDED INLET = 0.04 TO 0.20; */
/*                                  PROJECTING INLET = 0.8 TO 0.9) */
/* L          REAL            CULVERT LENGTH */
/* N          REAL            MANNINGS' "N" COEFFICIENT */
/*                               (CONCRETE = 0.012 +/- 0.002; */
/*                                  CMP = 0.021 +/- 0.006) */
/* OUTEL      REAL            OUTLET INVERT ELEVATION (FEET M.S.L.) */

/* QA         REAL            CALCULATED DISCHARGE (OUTPUT VARIABLE) */
/* SWB        REAL            LENGTH OF OVERFLOW PORTION OF RISER */
/* SWE        REAL            ELEVATION OF OVERFLOW PORTION OF RISER */
/* TWE        REAL            TAILWATER (DOWNSTREAM STAGE) ELEVATION, */
/*                               IN FEET M.S.L. */
/* W          REAL            CULVERT DIAMETER (CIRCLE) OR CULVERT */
/*                               HORIZONTAL WIDTH (BOX) */
/* WB         REAL            WEIR WIDTH */
/* *********************************************************************** */
/* * THIS PROGRAM COMPUTES THE DISCHARGE THROUGH GATED CULVERTS */
/* * CODE: W=WEIR CONTROL; F=FULL PIPE FLOW; O = ORIFICE CONTROL; */
/* *       P = PARTIAL PIPE FLOW; H = HEAD WATER CONTROL; */
/* *       T = TAILWATER CONTROL; ? = CHECK "ERRORF" */
/* *                   A. FAN  10/8/82 */
/* ************************************************************* */
/*     Local variables */
/* SOURCE riserclv.for:536 */
/*<       logicalweirctrl >*/
/* SOURCE riserclv.for:538 */
/*<       realke,qw,qc,we,ggap,hw,tw,elmax >*/
/* ***----- INITIALIZATION FOR EACH NEW COMPUTATION ----- */
/* SOURCE riserclv.for:542 */
/*<       qw=0.0 >*/
    qw = (float)0.;
/* SOURCE riserclv.for:543 */
/*<       qc=0.0 >*/
    qc = (float)0.;
/* SOURCE riserclv.for:544 */
/*<       qa=0.0 >*/
    *qa = (float)0.;
/* SOURCE riserclv.for:546 */
/*<       code(1:3)='   ' >*/
    s_copy(code, const_cast<char*>("   "), (ftnlen)3, (ftnlen)3);
/* SOURCE riserclv.for:547 */
/*<       if(gtype.eq.2)then >*/
    if (*gtype == 2) {
/* SOURCE riserclv.for:548 */
/*<       we=board >*/
	we = *board;
/* SOURCE riserclv.for:549 */
/*<       ggap=d >*/
	ggap = *feq_gen_d_d_;
/* SOURCE riserclv.for:550 */
/*<       else >*/
    } else {
/* SOURCE riserclv.for:551 */
/*<       we=0.0 >*/
	we = (float)0.;
/* SOURCE riserclv.for:552 */
/*<       ggap=min(board,d) >*/
	ggap = dmin(*board,*feq_gen_d_d_);
/* SOURCE riserclv.for:553 */
/*<       endif >*/
    }
/* ***** */
/* SOURCE riserclv.for:557 */
/*<       hw=hwe-inel >*/
    hw = static_cast<double>(*hwe) - *inel;
/* SOURCE riserclv.for:558 */
/*<       tw=twe-outel >*/
    tw = static_cast<double>(*twe) - *outel;
/* SOURCE riserclv.for:559 */
/*<       elmax=max(inel,outel) >*/
    elmax = dmax(*inel,*outel);
/* SOURCE riserclv.for:560 */
/*<       if(ggap.le.0.)goto110 >*/
    if (ggap <= (float)0.) {
	goto L110;
    }
/* SOURCE riserclv.for:561 */
/*<       if(gtype.eq.2.and.hwe.le.we.and.twe.le.we)goto110 >*/
    if (*gtype == 2 && *hwe <= we && *twe <= we) {
	goto L110;
    }
/* SOURCE riserclv.for:562 */
/*<       if(abs(hwe-twe).le.0.0001)goto110 >*/
    if ((feq_gen_r_d_1 = static_cast<double>(*hwe) - *twe, dabs(feq_gen_r_d_1)) <= (float)1e-4) {
	goto L110;
    }
/* SOURCE riserclv.for:563 */
/*<       if(hwe.le.elmax.and.twe.le.elmax)goto110 >*/
    if (*hwe <= elmax && *twe <= elmax) {
	goto L110;
    }
/* --- Set weir control flag. (JMO 1/4/92) */
/* SOURCE riserclv.for:567 */
/*<       weirctrl=.false. >*/
    weirctrl = FALSE_;
/* SOURCE riserclv.for:569 */
/*<       if(gtype.eq.2)then >*/
    if (*gtype == 2) {
/* SOURCE riserclv.for:570 */
/*<        >*/
	qculwei_(&qw, code, hwe, twe, &ggap, barrel, gtype, inel, outel, l, 
		feq_gen_d_d_, w, n, k, feq_gen_c_d_, &hw, &tw, &ke, wb, &we, swb, swe, cw, &a, &
		aw, (ftnlen)3);
/* ------ Flow through culvert with flashboard is weir flow if flashboard control */
/*        is significant; or if flow is free, not submerged.  (JMO 1/4/92) */
/*         IF (AW/A .LT. 0.2 .OR. TWE .LT. BOARD) THEN */
/*            WEIRCTRL = .TRUE. */
/*            GO TO 100 */
/*         ENDIF */
/* SOURCE riserclv.for:585 */
/*<       endif >*/
    }
/* SOURCE riserclv.for:586 */
/*<       if(tw.ge.d)then >*/
    if (tw >= *feq_gen_d_d_) {
/* SOURCE riserclv.for:587 */
/*<        >*/
	qculpip_(&qc, code, hwe, twe, &ggap, barrel, gtype, inel, outel, l, 
		feq_gen_d_d_, w, n, k, feq_gen_c_d_, &hw, &tw, &ke, (ftnlen)3);
/* SOURCE riserclv.for:591 */
/*<       elseif(hw.ge.1.3*d.or.hw.ge.2.0*ggap)then >*/
    } else if (hw >= static_cast<double>(*feq_gen_d_d_) * (float)1.3 || hw >= static_cast<double>(ggap) * (float)2.) {
/* SOURCE riserclv.for:592 */
/*<        >*/
	qculori_(&qc, code, hwe, twe, &ggap, barrel, gtype, inel, outel, l, 
		feq_gen_d_d_, w, n, k, feq_gen_c_d_, &hw, &tw, &ke, (ftnlen)3);
/* SOURCE riserclv.for:597 */
/*<       else >*/
    } else {
/* SOURCE riserclv.for:598 */
/*<        >*/
	qculdit_(&qc, code, hwe, twe, &ggap, barrel, gtype, inel, outel, l, 
		feq_gen_d_d_, w, n, k, feq_gen_c_d_, &hw, &tw, &ke, (ftnlen)3);
/* SOURCE riserclv.for:603 */
/*<       endif >*/
    }
/* --- Flow through culvert is weir flow if flow is controlled by flashboard */
/*     either completely or primarily.  (JMO 1/4/92) */
/*  100 IF (WEIRCTRL .OR. (GTYPE .EQ. 2 .AND. QW. LE. QC) ) THEN */
/* SOURCE riserclv.for:610 */
/*<       if(qw.le.qc)then >*/
    if (qw <= qc) {
/*       Assume weir control. */
/* SOURCE riserclv.for:612 */
/*<       qa=qw >*/
	*qa = qw;
/* SOURCE riserclv.for:613 */
/*<       code(1:1)='W' >*/
	*(unsigned char *)code = 'W';
/* SOURCE riserclv.for:614 */
/*<       if(gtype.eq.2)then >*/
	if (*gtype == 2) {
/* SOURCE riserclv.for:615 */
/*<       if(twe.le.board)then >*/
	    if (*twe <= *board) {
/*           Make sure that the flow control state is free. */
/* SOURCE riserclv.for:617 */
/*<       code(3:3)='F' >*/
		*(unsigned char *)&code[2] = 'F';
/* SOURCE riserclv.for:618 */
/*<       else >*/
	    } else {
/* SOURCE riserclv.for:619 */
/*<       code(3:3)='S' >*/
		*(unsigned char *)&code[2] = 'S';
/* SOURCE riserclv.for:620 */
/*<       endif >*/
	    }
/* SOURCE riserclv.for:621 */
/*<       endif >*/
	}
/* SOURCE riserclv.for:622 */
/*<       else >*/
    } else {
/* SOURCE riserclv.for:623 */
/*<       qa=qc >*/
	*qa = qc;
/* SOURCE riserclv.for:624 */
/*<       endif >*/
    }
/* SOURCE riserclv.for:625 */
/*<   110 return >*/
L110:
    return 0;
/* SOURCE riserclv.for:626 */
/*<       end >*/
} /* sfwmd_qculv__ */

/*     *********** */
/*     *         * */
/*     * RES_SFWMD_FIND_FREE */
/*     *         * */
/*     *********** */
/* SOURCE riserclv.for:632 */
/*<       realfunctionres_sfwmd_find_free(z) >*/
doublereal feq_gen_res_sfwmd_find_free_d_(real *feq_gen_z_d_)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
    extern /* Subroutine */ int feq_gen_sfwmd_qculv_d_(char *, integer *, integer *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    ftnlen);

/*     Residual function for finding the free flow values for */
/*     the SFWMD gated culvert routine.  We will use a bisection */
/*     method.  This routine then returns two distinct values. */
/*     +1 if the flow is called free and -1 if the flow is called */
/*     submerged. */
/* SOURCE riserclv.for:640 */
/*<       realz >*/
/* INCLUDE riserclv.for:642 */
/*     Common block for finding free flow. */
/* SOURCE sfwmdqcv.cmn:3 */
/*<       character*3code >*/
/* SOURCE sfwmdqcv.cmn:5 */
/*<       integergtype,barrel >*/
/* SOURCE sfwmdqcv.cmn:7 */
/*<       realboard,c,cw,d,hwe,inel,k,l,n,outel,swb,swe,w,wb,qa >*/
/* SOURCE sfwmdqcv.cmn:10 */
/*<        >*/
/* SOURCE sfwmdqcv.cmn:13 */
/*<       common/sf_frqc/code >*/
/* SOURCE sfwmdqcv.cmn:15 */
/*<       save/sf_frq/,/sf_frqc/ >*/
/* SOURCE riserclv.for:643 */
/*<    50 format(' CHK: HWE=',f8.2,' TWE=',f8.2,' FLOW=',f8.2,' CODE=',a3) >*/
/* ********************************************************************** */
/* SOURCE riserclv.for:647 */
/*<        >*/
/* L50: */
    feq_gen_sfwmd_qculv_d_(feq_gen_sf_frqc_d_1.code, &feq_gen_sf_frq_d_1.gtype, &feq_gen_sf_frq_d_1.barrel, &
	    feq_gen_sf_frq_d_1.board, &feq_gen_sf_frq_d_1.feq_gen_c_d_, &feq_gen_sf_frq_d_1.cw, &feq_gen_sf_frq_d_1.feq_gen_d_d_, &
	    feq_gen_sf_frq_d_1.hwe, &feq_gen_sf_frq_d_1.inel, &feq_gen_sf_frq_d_1.k, &feq_gen_sf_frq_d_1.l, &
	    feq_gen_sf_frq_d_1.n, &feq_gen_sf_frq_d_1.outel, &feq_gen_sf_frq_d_1.swb, &feq_gen_sf_frq_d_1.swe, 
	    feq_gen_z_d_, &feq_gen_sf_frq_d_1.w, &feq_gen_sf_frq_d_1.wb, &feq_gen_sf_frq_d_1.qa, (ftnlen)3);
/* SOURCE riserclv.for:650 */
/*<       if(code(3:3).eq.'F')then >*/
    if (*(unsigned char *)&feq_gen_sf_frqc_d_1.code[2] == 'F') {
/* SOURCE riserclv.for:651 */
/*<       res_sfwmd_find_free=1 >*/
	ret_val = (float)1.;
/* SOURCE riserclv.for:652 */
/*<       else >*/
    } else {
/* SOURCE riserclv.for:653 */
/*<       res_sfwmd_find_free=-1 >*/
	ret_val = (float)-1.;
/* SOURCE riserclv.for:654 */
/*<       endif >*/
    }
/* SOURCE riserclv.for:655 */
/*<       return >*/
    return ret_val;
/* SOURCE riserclv.for:656 */
/*<       end >*/
} /* res_sfwmd_find_free__ */

/*     *********** */
/*     *         * */
/*     * BISECT */
/*     *         * */
/*     *********** */
/* SOURCE riserclv.for:663 */
/*<       subroutinebisect(eps,fbase,zbase,zl,fl,zr,fr,f,zroot,eflag) >*/
/* Subroutine */ int bisect_(real *eps, real *fbase, real *zbase, real *zl, 
	real *fl, real *zr, real *fr, FeqCallback3 f, real *zroot, integer *eflag)
{
    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2;

    /* Local variables */
    real fm, zm;
    integer knt;

/*     Find a root of a function by bisection.  EFLAG returned as 0 */
/*     if convergence.  Otherwise returned as > 0. */
/* SOURCE riserclv.for:670 */
/*<       integereflag >*/
/* SOURCE riserclv.for:672 */
/*<       realeps,fbase,zbase,zl,fl,zr,fr,zroot >*/
/* SOURCE riserclv.for:674 */
/*<       realf >*/
/* SOURCE riserclv.for:675 */
/*<       externalf >*/
/*     Local */
/* SOURCE riserclv.for:679 */
/*<       integerknt >*/
/* SOURCE riserclv.for:680 */
/*<       realzm,fm >*/
/* *********************************************************************** */
/*     On entry FL and FR must be of differing sign and ZL and ZR must */
/*     be distinct.  The function, F, may never become small.  Therefore, */
/*     we must use convergence testing that checks for smallness of */
/*     the interval as well as the function. */
/* SOURCE riserclv.for:687 */
/*<       eflag=0 >*/
    *eflag = 0;
/* SOURCE riserclv.for:688 */
/*<       knt=0 >*/
    knt = 0;
/* SOURCE riserclv.for:689 */
/*<   100 continue >*/
L100:
/* SOURCE riserclv.for:690 */
/*<       zm=0.5*(zl+zr) >*/
    zm = static_cast<double>((static_cast<double>(*zl) + *zr)) * (float).5;
/* SOURCE riserclv.for:691 */
/*<       fm=f(zm) >*/
    fm = (*f)(&zm);
/* SOURCE riserclv.for:692 */
/*<       if(fm*fl.lt.0.0)then >*/
    if (static_cast<double>(fm) * *fl < (float)0.) {
/*         Retain the the sign change in the interval. */
/* SOURCE riserclv.for:694 */
/*<       fr=fm >*/
	*fr = fm;
/* SOURCE riserclv.for:695 */
/*<       zr=zm >*/
	*zr = zm;
/* SOURCE riserclv.for:696 */
/*<       else >*/
    } else {
/* SOURCE riserclv.for:697 */
/*<       fl=fm >*/
	*fl = fm;
/* SOURCE riserclv.for:698 */
/*<       zl=zm >*/
	*zl = zm;
/* SOURCE riserclv.for:699 */
/*<       endif >*/
    }
/* SOURCE riserclv.for:701 */
/*<       if(abs(fm/fbase).lt.eps.or.abs(zl-zr)/zbase.lt.eps)then >*/
    if ((feq_gen_r_d_1 = static_cast<double>(fm) / *fbase, dabs(feq_gen_r_d_1)) < *eps || (feq_gen_r_d_2 = static_cast<double>(*zl) - *zr, dabs(
	    feq_gen_r_d_2)) / *zbase < *eps) {
/*         Return the L value in order to get free flow case */
/* SOURCE riserclv.for:704 */
/*<       zroot=zl >*/
	*zroot = *zl;
/*         Evaluate the residual once more to make sure we */
/*         have the flow that agrees */
/* SOURCE riserclv.for:707 */
/*<       fl=f(zl) >*/
	*fl = (*f)(zl);
/* SOURCE riserclv.for:709 */
/*<       return >*/
	return 0;
/* SOURCE riserclv.for:710 */
/*<       endif >*/
    }
/* SOURCE riserclv.for:711 */
/*<       knt=knt+1 >*/
    ++knt;
/* SOURCE riserclv.for:712 */
/*<       if(knt.gt.25)then >*/
    if (knt > 25) {
/* SOURCE riserclv.for:713 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE riserclv.for:714 */
/*<       zroot=zm >*/
	*zroot = zm;
/* SOURCE riserclv.for:715 */
/*<       return >*/
	return 0;
/* SOURCE riserclv.for:716 */
/*<       endif >*/
    }
/* SOURCE riserclv.for:717 */
/*<       goto100 >*/
    goto L100;
/* SOURCE riserclv.for:718 */
/*<       end >*/
} /* bisect_ */

/*     *********** */
/*     *         * */
/*     * SFWMD_FIND_FREE */
/*     *         * */
/*     *********** */
/* SOURCE riserclv.for:725 */
/*<       subroutinesfwmd_find_free(stdout,zup,zdn,qfree) >*/
/* Subroutine */ int feq_gen_sfwmd_find_free_d_(integer *stdout, real *zup, real *zdn, 
	real *qfree)
{
    /* System generated locals */
    real feq_gen_r_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    real fl, fr, zl, zr, eps;
    extern doublereal feq_gen_res_sfwmd_find_free_d_(real *);
    real drop;
    integer eflag;
    real fbase, zbase, zroot;
    extern /* Subroutine */ int bisect_(real *, real *, real *, real *, real *
	    , real *, real *, FeqCallback3, real *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__88 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__94 = { 0, 0, 0, 0, 0 };


/*     Find the free flow values for a SFWMD gated culvert. */
/* SOURCE riserclv.for:730 */
/*<       integerstdout >*/
/* SOURCE riserclv.for:732 */
/*<       realzup,zdn,qfree >*/
/* INCLUDE riserclv.for:734 */
/*     Common block for finding free flow. */
/* SOURCE sfwmdqcv.cmn:3 */
/*<       character*3code >*/
/* SOURCE sfwmdqcv.cmn:5 */
/*<       integergtype,barrel >*/
/* SOURCE sfwmdqcv.cmn:7 */
/*<       realboard,c,cw,d,hwe,inel,k,l,n,outel,swb,swe,w,wb,qa >*/
/* SOURCE sfwmdqcv.cmn:10 */
/*<        >*/
/* SOURCE sfwmdqcv.cmn:13 */
/*<       common/sf_frqc/code >*/
/* SOURCE sfwmdqcv.cmn:15 */
/*<       save/sf_frq/,/sf_frqc/ >*/
/*     Local */
/* SOURCE riserclv.for:738 */
/*<       integereflag >*/
/* SOURCE riserclv.for:740 */
/*<       realeps,fbase,zbase,fl,fr,zl,zr,drop >*/
/* SOURCE riserclv.for:742 */
/*<       realres_sfwmd_find_free >*/
/* SOURCE riserclv.for:743 */
/*<       externalres_sfwmd_find_free >*/
/* *********************************************************************** */
/* SOURCE riserclv.for:746 */
/*<       hwe=zup >*/
    feq_gen_sf_frq_d_1.hwe = *zup;
/*     Find a sign change in the residual function and then use */
/*     bisection to find the boundary between free and submerged flow. */
/*     The flow will always be free if the drop from the headwater */
/*     level to the tailwater level is small enough.  Put the tailwater */
/*     at the exit level from the culvert barrel. */
/* SOURCE riserclv.for:754 */
/*<       zl=outel >*/
    zl = feq_gen_sf_frq_d_1.outel;
/* SOURCE riserclv.for:755 */
/*<       fl=res_sfwmd_find_free(zl) >*/
    fl = feq_gen_res_sfwmd_find_free_d_(&zl);
/*     Culvert will probably be submerged if the tailwater is */
/*     within .005 of the drop from the high point of the culvert */
/*     invert. */
/* SOURCE riserclv.for:761 */
/*<       drop=0.005*(zup-max(inel,outel)) >*/
    drop = (*zup - dmax(feq_gen_sf_frq_d_1.inel,feq_gen_sf_frq_d_1.outel)) * (float).005;
/* SOURCE riserclv.for:762 */
/*<       zr=zup-drop >*/
    zr = static_cast<double>(*zup) - drop;
/* SOURCE riserclv.for:763 */
/*<       fr=res_sfwmd_find_free(zr) >*/
    fr = feq_gen_res_sfwmd_find_free_d_(&zr);
/* SOURCE riserclv.for:765 */
/*<       if(fr*fl.ge.0.0)then >*/
    if (static_cast<double>(fr) * fl >= (float)0.) {
/* SOURCE riserclv.for:766 */
/*<       write(stdout,*)' Problem in sign change in SFWMD_FIND_FREE.' >*/
	feq_gen_io_d__88.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__88);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Problem in sign change in SFWMD_FIND_FREE."), (
		ftnlen)43);
	e_wsle();
/* SOURCE riserclv.for:767 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE riserclv.for:768 */
/*<       endif >*/
    }
/* SOURCE riserclv.for:770 */
/*<       fbase=1 >*/
    fbase = (float)1.;
/* SOURCE riserclv.for:771 */
/*<       zbase=zup-max(inel,outel,board) >*/
/* Computing MAX */
    feq_gen_r_d_1 = max(feq_gen_sf_frq_d_1.inel,feq_gen_sf_frq_d_1.outel);
    zbase = *zup - dmax(feq_gen_r_d_1,feq_gen_sf_frq_d_1.board);
/* SOURCE riserclv.for:772 */
/*<       eps=0.001 >*/
    eps = (float).001;
/* SOURCE riserclv.for:773 */
/*<        >*/
    bisect_(&eps, &fbase, &zbase, &zl, &fl, &zr, &fr, feq_gen_res_sfwmd_find_free_d_, &zroot, &eflag);
/* SOURCE riserclv.for:777 */
/*<       if(eflag.gt.0)then >*/
    if (eflag > 0) {
/* SOURCE riserclv.for:778 */
/*<       write(stdout,*)' No convergence in SFWMD_FIND_FREE.' >*/
	feq_gen_io_d__94.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__94);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" No convergence in SFWMD_FIND_FREE."), (ftnlen)
		35);
	e_wsle();
/* SOURCE riserclv.for:779 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE riserclv.for:780 */
/*<       endif >*/
    }
/* SOURCE riserclv.for:781 */
/*<       zdn=zroot >*/
    *zdn = zroot;
/* SOURCE riserclv.for:782 */
/*<       qfree=qa >*/
    *qfree = feq_gen_sf_frq_d_1.qa;
/* SOURCE riserclv.for:783 */
/*<       return >*/
    return 0;
/* SOURCE riserclv.for:784 */
/*<       end >*/
} /* sfwmd_find_free__ */

/*     *********** */
/*     *         * */
/*     * RISERCLV */
/*     *         * */
/*     *********** */
/* SOURCE riserclv.for:790 */
/*<       subroutineriserclv(grav,stdin,stdout,stdtab,eflag,tabdir) >*/
/* Subroutine */ int riserclv_(real *grav, integer *stdin, integer *stdout, 
	integer *stdtab, integer *eflag, integer *feq_storage_tabdir)
{
    /* Format strings */
    static char fmt_2[] = "(6x,a)";
    static char fmt_4[] = "(i6,a6,7f6.0)";
    static char fmt_6[] = "(10f6.0)";
    static char fmt_50[] = "(/,\002 Table id= \002,a,\002 for type 13 table \
for riser\002,\002 culvert.\002)";
    static char fmt_52[] = "(/,\002 Label=\002,a50)";
    static char fmt_54[] = "(\002 \002,a80)";
    static char fmt_56[] = "(1x,i6,a6,f6.2,2f6.1,2f6.1,f6.1,f6.3)";
    static char fmt_58[] = "(1x,f6.1,f6.1,f6.1,f6.1,f6.1,f6.1,f6.2,f6.2,f6.3\
,f6.3)";
    static char fmt_60[] = "(/,\002 Datum for defining heads=\002,f10.2)";
    static char fmt_72[] = "(/,\002Upstream head=\002,f9.4,\002 Elevation\
=\002,f10.4)";
    static char fmt_74[] = "(/,\002  Partial  Drop    Elev.   Head    Flow D\
ischarge Local\002,/,\002   free    sect.   sect.   sect.   Code           p\
ower\002,/,\002   drop    1->4     4       4\002,/,\002 --------  ------  --\
----  ------   --- --------- ------\002)";
    static char fmt_75[] = "(1x,f8.4,f8.3,f8.3,f8.3,3x,a3,f10.1,f7.2)";
    static char fmt_78[] = "(/,\002  *ERR:634* Maximum ups head=\002,f8.2\
,\002 <= 0.\002,\002 Max ups elev=\002,f8.2,\002 and head datum=\002,f8.2)";
    static char fmt_80[] = "(/,\002 *WRN:595* Minimum non-zero upstream he\
ad=\002,f8.2,\002 <= 0.\002,\002 Setting to 0.15\002)";
    static char fmt_86[] = "(/,\002 Maximum relative error=\002,f6.3,\002  U\
pstream head=\002,f9.4,/,\002  and partial free drop=\002,f8.5)";
    static char fmt_88[] = "(/\002 Root-mean-squared error=\002,f6.3,\002 N \
in sample=\002,i5)";
    static char fmt_89[] = "(\002  Processing RISERCLV TabId= \002,a)";
    static char fmt_99[] = "(/,\002 *ERR:635* Interpolation precision tables\
 missing.\002,\002 Check for version\002,/,11x,\002of file: TYPE5.TAB.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(), do_fio(integer *, char *, ftnlen), 
	    s_rsfi(icilist *), e_rsfi(), s_cmp(char *, char *, ftnlen, ftnlen)
	    ;
    double log(doublereal), sqrt(doublereal);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    integer feq_gen_n_global_d_;
    doublereal northing;
    integer feq_gen_i_d_, j, nn;
    extern /* Subroutine */ int feq_gen_read_tabid_d_(integer *, char *, char *, 
	    integer *, char *, integer *, ftnlen, ftnlen, ftnlen);
    real hw, feq_gen_head_datum_d_, feq_gen_rms_global_d_;
    integer tab;
    real pfd;
    char key[16];
    real twe, pow;
    extern /* Subroutine */ int feq_gen_sfwmd_qculv_d_(char *, integer *, integer *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    ftnlen);
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ipfd;
    char line[80];
    real qhat, herr, qmat[53001]	/* was [151][351] */, drop;
    integer ihup;
    real xbrk[351], twef;
    integer nhup;
    real rerr;
    char zone[8];
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real work[351];
    char label[50], tabid[16];
    integer jbase, nfrac;
    real fdvec[151];
    char hgrid[8], shape[6];
    integer tabgt;
    real qfree;
    integer tablt;
    real fdrop, htemp;
    char basis[8];
    extern /* Subroutine */ int tabchk_(integer *, integer *, integer *, 
	    integer *, integer *);
    real bigerr, limpfd, liprec, minpfd, pfdvec[351], hupvec[151], maxzup, 
	    maxhup, minhup, pfdtmp[351], zrhufd;
    char vdatum[8];
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen),
	     lstopf_(integer *, integer *, integer *, real *, real *, real *, 
	    real *, real *, integer *, integer *, real *, integer *), twdout_(
	    integer *, integer *, integer *, char *, integer *, integer *, 
	    real *, real *, real *, real *, real *, integer *, char *, real *,
	     char *, char *, char *, char *, char *, doublereal *, doublereal 
	    *, integer *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen), feq_gen_get_lctn_items_d_(integer *, integer *, integer *);
    integer number;
    real offset;
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen), 
	    feq_gen_set_lctn_items_d_(char *, char *, char *, char *, doublereal *, 
	    char *, doublereal *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen);
    doublereal easting;
    real fnumber;
    extern /* Subroutine */ int feq_gen_sfwmd_find_free_d_(integer *, real *, real *, 
	    real *);
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__101 = { 0, 0, 0, fmt_99, 0 };
    static cilist feq_gen_io_d__105 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__106 = { 0, 6, 0, fmt_89, 0 };
    static cilist feq_gen_io_d__115 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__116 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__119 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__121 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__127 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__129 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__131 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__132 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__155 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__156 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__157 = { 0, 0, 0, fmt_75, 0 };
    static cilist feq_gen_io_d__161 = { 0, 0, 0, fmt_75, 0 };
    static cilist feq_gen_io_d__169 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__170 = { 0, 0, 0, fmt_88, 0 };
    static cilist feq_gen_io_d__171 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__172 = { 0, 0, 0, 0, 0 };


/*     Compute a 2-D table of type 13 for one or more SFWMD riser */
/*     culverts. Uses SFWMD methods for culvert flow. */
/*     Dummy arguments */
/* SOURCE riserclv.for:797 */
/*<       integereflag,stdin,stdout,stdtab >*/
/* SOURCE riserclv.for:798 */
/*<       integertabdir(*) >*/
/* SOURCE riserclv.for:799 */
/*<       realgrav >*/
/*     DEFINITIONS */
/*     GRAV   - value of acceleration due to gravity */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     TABDIR - Table directory to remember table numbers */
/* INCLUDE riserclv.for:809 */
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
/* INCLUDE riserclv.for:810 */
/* ********************************************************************** */
/* SOURCE ftable.cmn:2 */
/*<       common/ftable/dtab >*/
/* SOURCE ftable.cmn:3 */
/*<       common/ftablea/longdummy,itmp,knt_of_ftabs,ftpnt >*/
/* SOURCE ftable.cmn:4 */
/*<       common/ftablec/ft_loc_status >*/
/* SOURCE ftable.cmn:6 */
/*<       integerftpnt(mftnum+5) >*/
/* SOURCE ftable.cmn:7 */
/*<       character*1ft_loc_status(mftnum) >*/
/* SOURCE ftable.cmn:9 */
/*<       realftab(0:mrftab) >*/
/* SOURCE ftable.cmn:10 */
/*<       real*8dtab(0:mdftab) >*/
/* SOURCE ftable.cmn:12 */
/*<       real*8longdummy >*/
/* SOURCE ftable.cmn:14 */
/*<       integeritmp,itab(0:mrftab),knt_of_ftabs >*/
/* SOURCE ftable.cmn:16 */
/*<       realrtmp >*/
/* SOURCE ftable.cmn:18 */
/*<       equivalence(dtab,ftab,itab) >*/
/* SOURCE ftable.cmn:19 */
/*<       equivalence(itmp,rtmp) >*/
/* SOURCE ftable.cmn:21 */
/*<       save/ftable/,/ftablea/,/ftablec/ >*/
/* ********************************************************************** */
/* INCLUDE riserclv.for:811 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE riserclv.for:812 */
/*     Common block for finding free flow. */
/* SOURCE sfwmdqcv.cmn:3 */
/*<       character*3code >*/
/* SOURCE sfwmdqcv.cmn:5 */
/*<       integergtype,barrel >*/
/* SOURCE sfwmdqcv.cmn:7 */
/*<       realboard,c,cw,d,hwe,inel,k,l,n,outel,swb,swe,w,wb,qa >*/
/* SOURCE sfwmdqcv.cmn:10 */
/*<        >*/
/* SOURCE sfwmdqcv.cmn:13 */
/*<       common/sf_frqc/code >*/
/* SOURCE sfwmdqcv.cmn:15 */
/*<       save/sf_frq/,/sf_frqc/ >*/
/*     Local */
/* SOURCE riserclv.for:815 */
/*<       integeri,ihup,ipfd,j,jbase,nfrac,nhup,n_global,tab,tablt,tabgt,nn >*/
/* SOURCE riserclv.for:818 */
/*<        >*/
/* SOURCE riserclv.for:824 */
/*<       real*8easting,northing >*/
/* SOURCE riserclv.for:825 */
/*<        >*/
/*     Intrinsics */
/* SOURCE riserclv.for:829 */
/*<       intrinsicabs,float,log,sqrt >*/
/*     External names */
/* SOURCE riserclv.for:833 */
/*<       integerlenstr >*/
/* SOURCE riserclv.for:834 */
/*<       externalchktab,inline,lstopf,tabchk,twdout,read_tabid,lenstr >*/
/*     ************************************FORMATS********************** */
/* SOURCE riserclv.for:837 */
/*<     1 format(7x,i5) >*/
/* SOURCE riserclv.for:838 */
/*<     2 format(6x,a) >*/
/* SOURCE riserclv.for:839 */
/*<     4 format(i6,a6,7f6.0) >*/
/* SOURCE riserclv.for:840 */
/*<     6 format(10f6.0) >*/
/* SOURCE riserclv.for:842 */
/*<    50  >*/
/* SOURCE riserclv.for:844 */
/*<    52 format(/,' Label=',a50) >*/
/* SOURCE riserclv.for:845 */
/*<    54 format(' ',a80) >*/
/* SOURCE riserclv.for:846 */
/*<    56 format(1x,i6,a6,f6.2,2f6.1,2f6.1,f6.1,f6.3) >*/
/* SOURCE riserclv.for:847 */
/*<    58 format(1x,f6.1,f6.1,f6.1,f6.1,f6.1,f6.1,f6.2,f6.2,f6.3,f6.3) >*/
/* SOURCE riserclv.for:848 */
/*<    60 format(/,' Datum for defining heads=',f10.2) >*/
/* SOURCE riserclv.for:849 */
/*<    72 format(/,'Upstream head=',f9.4,' Elevation=',f10.4) >*/
/* SOURCE riserclv.for:850 */
/*<    74  >*/
/* SOURCE riserclv.for:855 */
/*<    75 format(1x,f8.4,f8.3,f8.3,f8.3,3x,a3,f10.1,f7.2) >*/
/* SOURCE riserclv.for:856 */
/*<    78  >*/
/* SOURCE riserclv.for:858 */
/*<    80  >*/
/* SOURCE riserclv.for:860 */
/*<    86  >*/
/* SOURCE riserclv.for:862 */
/*<    88 format(/' Root-mean-squared error=',f6.3,' N in sample=',i5) >*/
/* SOURCE riserclv.for:863 */
/*<    89 format('  Processing RISERCLV TabId= ',a) >*/
/* SOURCE riserclv.for:864 */
/*<    99  >*/
/* ********************************************************************** */
/*     Define the linear interpolation precision tables. */
/* SOURCE riserclv.for:868 */
/*<       key='10001' >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> tabdir(feq_storage_tabdir, 1);

    /* Function Body */
/* L1: */
/* L2: */
/* L4: */
/* L6: */
/* L50: */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
/* L60: */
/* L72: */
/* L74: */
/* L75: */
/* L78: */
/* L80: */
/* L86: */
/* L88: */
/* L89: */
/* L99: */
    s_copy(key, const_cast<char*>("10001"), (ftnlen)16, (ftnlen)5);
/* SOURCE riserclv.for:869 */
/*<       callget_internal_tab_number(stdout,key,eflag,tablt) >*/
    feq_gen_get_internal_tab_number_d_(stdout, key, eflag, &tablt, (ftnlen)16);
/* SOURCE riserclv.for:873 */
/*<       tablt=ftpnt(tablt) >*/
    tablt = ftablea_1.ftpnt[tablt - 1];
/* SOURCE riserclv.for:874 */
/*<       key='10002' >*/
    s_copy(key, const_cast<char*>("10002"), (ftnlen)16, (ftnlen)5);
/* SOURCE riserclv.for:875 */
/*<       callget_internal_tab_number(stdout,key,eflag,tabgt) >*/
    feq_gen_get_internal_tab_number_d_(stdout, key, eflag, &tabgt, (ftnlen)16);
/* SOURCE riserclv.for:879 */
/*<       tabgt=ftpnt(tabgt) >*/
    tabgt = ftablea_1.ftpnt[tabgt - 1];
/* SOURCE riserclv.for:880 */
/*<       if(tablt.lt.1.or.tabgt.lt.1)then >*/
    if (tablt < 1 || tabgt < 1) {
/* SOURCE riserclv.for:881 */
/*<       write(stdout,99) >*/
	feq_gen_io_d__101.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__101);
	e_wsfe();
/* SOURCE riserclv.for:882 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE riserclv.for:883 */
/*<       return >*/
	return 0;
/* SOURCE riserclv.for:884 */
/*<       endif >*/
    }
/* SOURCE riserclv.for:885 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE riserclv.for:887 */
/*<       callread_tabid(stdout,line,'TAB',eflag,tabid,tab) >*/
    feq_gen_read_tabid_d_(stdout, line, const_cast<char*>("TAB"), eflag, tabid, &tab, (ftnlen)80, (ftnlen)
	    3, (ftnlen)16);
/*      READ(LINE,1,ERR=991) TAB */
/* SOURCE riserclv.for:891 */
/*<       write(stdout,50)tabid(1:lenstr(tabid)) >*/
    feq_gen_io_d__105.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__105);
    do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
    e_wsfe();
/* SOURCE riserclv.for:892 */
/*<       write(*,89)tabid(1:lenstr(tabid)) >*/
    s_wsfe(&feq_gen_io_d__106);
    do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
    e_wsfe();
/* SOURCE riserclv.for:894 */
/*<       calltabchk(stdout,pmxtab,tab,tabdir,eflag) >*/
    tabchk_(stdout, &feq_gen_c_d_10002, &tab, &tabdir[1], eflag);
/*     Get location items that may be present. If they are not present */
/*     they will be set to default values.  The default requests FEQUTL */
/*     to omit the items. */
/* SOURCE riserclv.for:900 */
/*<       callget_lctn_items(stdin,stdout,eflag) >*/
    feq_gen_get_lctn_items_d_(stdin, stdout, eflag);
/* SOURCE riserclv.for:902 */
/*<        >*/
    feq_gen_set_lctn_items_d_(zone, hgrid, vdatum, unitsys, &easting, basis, &northing,
	     (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE riserclv.for:907 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE riserclv.for:909 */
/*<       read(line,2,err=991)label >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_2;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, label, (ftnlen)50);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE riserclv.for:910 */
/*<       write(stdout,52)label >*/
    feq_gen_io_d__115.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__115);
    do_fio(&feq_gen_c_d_1, label, (ftnlen)50);
    e_wsfe();
/*     Get the heading line. */
/* SOURCE riserclv.for:913 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE riserclv.for:915 */
/*<       write(stdout,54)line >*/
    feq_gen_io_d__116.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__116);
    do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
    e_wsfe();
/* SOURCE riserclv.for:917 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE riserclv.for:920 */
/*<       read(line,4,err=991)number,shape,k,d,w,inel,outel,l,n >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_4;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&number, (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, shape, (ftnlen)6);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.k, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.feq_gen_d_d_, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.w, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.inel, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.outel, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.l, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.n, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE riserclv.for:921 */
/*<       write(stdout,56)number,shape,k,d,w,inel,outel,l,n >*/
    feq_gen_io_d__119.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__119);
    do_fio(&feq_gen_c_d_1, (char *)&number, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, shape, (ftnlen)6);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.k, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.feq_gen_d_d_, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.w, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.inel, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.outel, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.l, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.n, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE riserclv.for:922 */
/*<       callstrip_l_blanks(shape) >*/
    feq_gen_strip_l_blanks_d_(shape, (ftnlen)6);
/* SOURCE riserclv.for:923 */
/*<       if(shape.eq.'PIPE')then >*/
    if (s_cmp(shape, const_cast<char*>("PIPE"), (ftnlen)6, (ftnlen)4) == 0) {
/* SOURCE riserclv.for:924 */
/*<       w=d >*/
	feq_gen_sf_frq_d_1.w = feq_gen_sf_frq_d_1.feq_gen_d_d_;
/* SOURCE riserclv.for:925 */
/*<       endif >*/
    }
/* SOURCE riserclv.for:927 */
/*<       fnumber=number >*/
    fnumber = (real) number;
/*     Get the heading line. */
/* SOURCE riserclv.for:929 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE riserclv.for:931 */
/*<       write(stdout,54)line >*/
    feq_gen_io_d__121.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__121);
    do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
    e_wsfe();
/* SOURCE riserclv.for:933 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE riserclv.for:935 */
/*<        >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_6;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.cw, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.board, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.wb, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.swe, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.swb, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&maxzup, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&minhup, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&limpfd, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&minpfd, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&liprec, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE riserclv.for:937 */
/*<        >*/
    feq_gen_io_d__127.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__127);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.cw, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.board, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.wb, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.swe, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.swb, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&maxzup, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&minhup, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&limpfd, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&minpfd, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&liprec, (ftnlen)sizeof(real));
    e_wsfe();
/*     Gate option not used.  Set value of contraction coefficient */
/*     to avoid side effects. */
/* SOURCE riserclv.for:942 */
/*<       c=0.6 >*/
    feq_gen_sf_frq_d_1.feq_gen_c_d_ = (float).6;
/* SOURCE riserclv.for:943 */
/*<       if(eflag.ne.0)return >*/
    if (*eflag != 0) {
	return 0;
    }
/*     INPUT OF DATA COMPLETE.  BEGIN THE COMPUTATIONS. */
/* SOURCE riserclv.for:947 */
/*<       if(shape.eq.'PIPE')then >*/
    if (s_cmp(shape, const_cast<char*>("PIPE"), (ftnlen)6, (ftnlen)4) == 0) {
/* SOURCE riserclv.for:948 */
/*<       barrel=0 >*/
	feq_gen_sf_frq_d_1.barrel = 0;
/* SOURCE riserclv.for:949 */
/*<       else >*/
    } else {
/* SOURCE riserclv.for:950 */
/*<       barrel=1 >*/
	feq_gen_sf_frq_d_1.barrel = 1;
/* SOURCE riserclv.for:951 */
/*<       endif >*/
    }
/*     Force to riser culvert only.  Gated culverts done elsewhere. */
/* SOURCE riserclv.for:954 */
/*<       gtype=2 >*/
    feq_gen_sf_frq_d_1.gtype = 2;
/*     Compute the upstream head sequence.  First, find the head */
/*     range requested. */
/* SOURCE riserclv.for:958 */
/*<       head_datum=max(board,inel,outel) >*/
/* Computing MAX */
    feq_gen_r_d_1 = max(feq_gen_sf_frq_d_1.board,feq_gen_sf_frq_d_1.inel);
    feq_gen_head_datum_d_ = dmax(feq_gen_r_d_1,feq_gen_sf_frq_d_1.outel);
/* SOURCE riserclv.for:959 */
/*<       write(stdout,60)head_datum >*/
    feq_gen_io_d__129.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__129);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_head_datum_d_, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE riserclv.for:960 */
/*<       maxhup=maxzup-head_datum >*/
    maxhup = static_cast<double>(maxzup) - feq_gen_head_datum_d_;
/* SOURCE riserclv.for:961 */
/*<       if(maxhup.le.0.0)then >*/
    if (maxhup <= (float)0.) {
/* SOURCE riserclv.for:962 */
/*<       write(stdout,78)maxhup,maxzup,head_datum >*/
	feq_gen_io_d__131.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__131);
	do_fio(&feq_gen_c_d_1, (char *)&maxhup, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&maxzup, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_head_datum_d_, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE riserclv.for:963 */
/*<       maxhup=2.0 >*/
	maxhup = (float)2.;
/* SOURCE riserclv.for:964 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE riserclv.for:965 */
/*<       endif >*/
    }
/* SOURCE riserclv.for:966 */
/*<       if(minhup.le.0.0)then >*/
    if (minhup <= (float)0.) {
/* SOURCE riserclv.for:967 */
/*<       write(stdout,80)minhup >*/
	feq_gen_io_d__132.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__132);
	do_fio(&feq_gen_c_d_1, (char *)&minhup, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE riserclv.for:968 */
/*<       minhup=0.15 >*/
	minhup = (float).15;
/* SOURCE riserclv.for:969 */
/*<       endif >*/
    }
/*     Use power of 1.5 because is requires closer spacing than */
/*     power of .5. */
/* SOURCE riserclv.for:972 */
/*<       pow=1.5 >*/
    pow = (float)1.5;
/* SOURCE riserclv.for:973 */
/*<       offset=0.0 >*/
    offset = (float)0.;
/* SOURCE riserclv.for:974 */
/*<       htemp=swe-head_datum >*/
    htemp = static_cast<double>(feq_gen_sf_frq_d_1.swe) - feq_gen_head_datum_d_;
/* SOURCE riserclv.for:975 */
/*<       if(htemp+minhup.lt.maxhup)then >*/
    if (static_cast<double>(htemp) + minhup < maxhup) {
/*       Define ups head sequence in two parts: MINHUP to HTEMP, */
/*       and then from HTEMP+MINHUP to MAXHUP */
/* SOURCE riserclv.for:978 */
/*<        >*/
	lstopf_(stdout, &tablt, &tabgt, &pow, &offset, &minhup, &htemp, &
		liprec, &feq_gen_c_d_151, &nhup, xbrk, eflag);
/* SOURCE riserclv.for:982 */
/*<       do190i=1,nhup >*/
	feq_gen_i_d_1 = nhup;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE riserclv.for:983 */
/*<       hupvec(i)=xbrk(i) >*/
	    hupvec[feq_gen_i_d_ - 1] = xbrk[feq_gen_i_d_ - 1];
/* SOURCE riserclv.for:984 */
/*<   190 continue >*/
/* L190: */
	}
/* SOURCE riserclv.for:986 */
/*<        >*/
	feq_gen_r_d_1 = static_cast<double>(htemp) + minhup;
	lstopf_(stdout, &tablt, &tabgt, &pow, &offset, &feq_gen_r_d_1, &maxhup, &
		liprec, &feq_gen_c_d_151, &nn, xbrk, eflag);
/* SOURCE riserclv.for:990 */
/*<       do191i=1,nn >*/
	feq_gen_i_d_1 = nn;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE riserclv.for:991 */
/*<       nhup=nhup+1 >*/
	    ++nhup;
/* SOURCE riserclv.for:992 */
/*<       hupvec(nhup)=xbrk(i) >*/
	    hupvec[nhup - 1] = xbrk[feq_gen_i_d_ - 1];
/* SOURCE riserclv.for:993 */
/*<   191 continue >*/
/* L191: */
	}
/* SOURCE riserclv.for:994 */
/*<       else >*/
    } else {
/*       Define head sequence for whole range: MINHUP to MAXHUP. */
/* SOURCE riserclv.for:996 */
/*<        >*/
	lstopf_(stdout, &tablt, &tabgt, &pow, &offset, &minhup, &maxhup, &
		liprec, &feq_gen_c_d_151, &nhup, hupvec, eflag);
/* SOURCE riserclv.for:999 */
/*<       endif >*/
    }
/*     Compute the proportions of free drop. */
/* SOURCE riserclv.for:1002 */
/*<       pow=0.5 >*/
    pow = (float).5;
/* SOURCE riserclv.for:1003 */
/*<       offset=0.0 >*/
    offset = (float)0.;
/* SOURCE riserclv.for:1004 */
/*<        >*/
    lstopf_(stdout, &tablt, &tabgt, &pow, &offset, &minpfd, &limpfd, &liprec, 
	    &feq_gen_c_d_351, &nn, xbrk, eflag);
/* SOURCE riserclv.for:1008 */
/*<       work(1)=0.0 >*/
    work[0] = (float)0.;
/* SOURCE riserclv.for:1009 */
/*<       do195i=1,nn >*/
    feq_gen_i_d_1 = nn;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE riserclv.for:1010 */
/*<       work(i+1)=xbrk(i) >*/
	work[feq_gen_i_d_] = xbrk[feq_gen_i_d_ - 1];
/* SOURCE riserclv.for:1011 */
/*<   195 continue >*/
/* L195: */
    }
/* SOURCE riserclv.for:1012 */
/*<       nfrac=nn+1 >*/
    nfrac = nn + 1;
/* SOURCE riserclv.for:1014 */
/*<       work(nfrac+1)=1.0 >*/
    work[nfrac] = (float)1.;
/* SOURCE riserclv.for:1015 */
/*<       nfrac=nfrac+1 >*/
    ++nfrac;
/*     Transfer to PFDVEC and insert the intermediate points for computing */
/*     an estimated interpolation error. */
/* SOURCE riserclv.for:1019 */
/*<       pfdvec(1)=work(1) >*/
    pfdvec[0] = work[0];
/* SOURCE riserclv.for:1020 */
/*<       pfdvec(2)=work(2) >*/
    pfdvec[1] = work[1];
/* SOURCE riserclv.for:1021 */
/*<       j=2 >*/
    j = 2;
/* SOURCE riserclv.for:1022 */
/*<       do201i=3,nfrac-1 >*/
    feq_gen_i_d_1 = nfrac - 1;
    for (feq_gen_i_d_ = 3; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE riserclv.for:1023 */
/*<       j=j+1 >*/
	++j;
/* SOURCE riserclv.for:1024 */
/*<       pfdvec(j)=0.5*(work(i)+work(i-1)) >*/
	pfdvec[j - 1] = static_cast<double>((static_cast<double>(work[feq_gen_i_d_ - 1]) + work[feq_gen_i_d_ - 2])) * (float).5;
/* SOURCE riserclv.for:1025 */
/*<       j=j+1 >*/
	++j;
/* SOURCE riserclv.for:1026 */
/*<       pfdvec(j)=work(i) >*/
	pfdvec[j - 1] = work[feq_gen_i_d_ - 1];
/* SOURCE riserclv.for:1027 */
/*<   201 continue >*/
/* L201: */
    }
/* SOURCE riserclv.for:1028 */
/*<       pfdvec(j+1)=work(nfrac) >*/
    pfdvec[j] = work[nfrac - 1];
/* SOURCE riserclv.for:1029 */
/*<       nfrac=j+1 >*/
    nfrac = j + 1;
/*      DO 202 I=1,NFRAC */
/*        WRITE(STDOUT,*) ' I=',I,' PFDVEC(I)=',PFDVEC(I) */
/* 202   CONTINUE */
/* SOURCE riserclv.for:1034 */
/*<       rms_global=0.0 >*/
    feq_gen_rms_global_d_ = (float)0.;
/* SOURCE riserclv.for:1035 */
/*<       n_global=0.0 >*/
    feq_gen_n_global_d_ = (float)0.;
/* SOURCE riserclv.for:1036 */
/*<       bigerr=0.0 >*/
    bigerr = (float)0.;
/* SOURCE riserclv.for:1038 */
/*<       do1000ihup=1,nhup >*/
    feq_gen_i_d_1 = nhup;
    for (ihup = 1; ihup <= feq_gen_i_d_1; ++ihup) {
/* SOURCE riserclv.for:1039 */
/*<       hw=hupvec(ihup) >*/
	hw = hupvec[ihup - 1];
/* SOURCE riserclv.for:1041 */
/*<       hwe=hw+head_datum >*/
	feq_gen_sf_frq_d_1.hwe = static_cast<double>(hw) + feq_gen_head_datum_d_;
/*       Find the free flow values. */
/* SOURCE riserclv.for:1044 */
/*<       callsfwmd_find_free(stdout,hwe,twef,qfree) >*/
	feq_gen_sfwmd_find_free_d_(stdout, &feq_gen_sf_frq_d_1.hwe, &twef, &qfree);
/* SOURCE riserclv.for:1046 */
/*<       fdrop=hwe-twef >*/
	fdrop = static_cast<double>(feq_gen_sf_frq_d_1.hwe) - twef;
/* SOURCE riserclv.for:1048 */
/*<       qfree=qfree*fnumber >*/
	qfree *= fnumber;
/* SOURCE riserclv.for:1049 */
/*<       qmat(ihup,nfrac)=qfree >*/
	qmat[ihup + nfrac * 151 - 152] = qfree;
/*       Set flow to zero at this ups head for zero partial free drop */
/* SOURCE riserclv.for:1051 */
/*<       qmat(ihup,1)=0.0 >*/
	qmat[ihup - 1] = (float)0.;
/* SOURCE riserclv.for:1053 */
/*<       fdvec(ihup)=fdrop >*/
	fdvec[ihup - 1] = fdrop;
/* SOURCE riserclv.for:1055 */
/*<       write(stdout,72)hw,hwe >*/
	feq_gen_io_d__155.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__155);
	do_fio(&feq_gen_c_d_1, (char *)&hw, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.hwe, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE riserclv.for:1056 */
/*<       write(stdout,74) >*/
	feq_gen_io_d__156.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__156);
	e_wsfe();
/* SOURCE riserclv.for:1057 */
/*<        >*/
	feq_gen_io_d__157.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__157);
	do_fio(&feq_gen_c_d_1, (char *)&pfdvec[nfrac - 1], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&fdrop, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&twef, (ftnlen)sizeof(real));
	feq_gen_r_d_1 = static_cast<double>(twef) - feq_gen_head_datum_d_;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, feq_gen_sf_frqc_d_1.code, (ftnlen)3);
	do_fio(&feq_gen_c_d_1, (char *)&qfree, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE riserclv.for:1060 */
/*<       do400j=nfrac-1,2,-1 >*/
	for (j = nfrac - 1; j >= 2; --j) {
/* SOURCE riserclv.for:1061 */
/*<       pfd=pfdvec(j) >*/
	    pfd = pfdvec[j - 1];
/* SOURCE riserclv.for:1062 */
/*<       drop=fdrop*pfd >*/
	    drop = static_cast<double>(fdrop) * pfd;
/* SOURCE riserclv.for:1063 */
/*<       twe=hwe-drop >*/
	    twe = static_cast<double>(feq_gen_sf_frq_d_1.hwe) - drop;
/* SOURCE riserclv.for:1064 */
/*<        >*/
	    feq_gen_sfwmd_qculv_d_(feq_gen_sf_frqc_d_1.code, &feq_gen_sf_frq_d_1.gtype, &
		    feq_gen_sf_frq_d_1.barrel, &feq_gen_sf_frq_d_1.board, &feq_gen_sf_frq_d_1.feq_gen_c_d_, &
		    feq_gen_sf_frq_d_1.cw, &feq_gen_sf_frq_d_1.feq_gen_d_d_, &feq_gen_sf_frq_d_1.hwe, &
		    feq_gen_sf_frq_d_1.inel, &feq_gen_sf_frq_d_1.k, &feq_gen_sf_frq_d_1.l, &feq_gen_sf_frq_d_1.n, 
		    &feq_gen_sf_frq_d_1.outel, &feq_gen_sf_frq_d_1.swb, &feq_gen_sf_frq_d_1.swe, &twe, &
		    feq_gen_sf_frq_d_1.w, &feq_gen_sf_frq_d_1.wb, &feq_gen_sf_frq_d_1.qa, (ftnlen)3);
/* SOURCE riserclv.for:1067 */
/*<       qa=qa*fnumber >*/
	    feq_gen_sf_frq_d_1.qa *= fnumber;
/* SOURCE riserclv.for:1068 */
/*<       qmat(ihup,j)=qa >*/
	    qmat[ihup + j * 151 - 152] = feq_gen_sf_frq_d_1.qa;
/* SOURCE riserclv.for:1069 */
/*<       pow=log(qa/qmat(ihup,j+1))/log(pfdvec(j)/pfdvec(j+1)) >*/
	    pow = log(static_cast<double>(feq_gen_sf_frq_d_1.qa) / qmat[ihup + (j + 1) * 151 - 152]) / log(
		    static_cast<double>(pfdvec[j - 1]) / pfdvec[j]);
/* SOURCE riserclv.for:1070 */
/*<       write(stdout,75)pfdvec(j),drop,twe,twe-head_datum,code,qa,pow >*/
	    feq_gen_io_d__161.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__161);
	    do_fio(&feq_gen_c_d_1, (char *)&pfdvec[j - 1], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&drop, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&twe, (ftnlen)sizeof(real));
	    feq_gen_r_d_1 = static_cast<double>(twe) - feq_gen_head_datum_d_;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, feq_gen_sf_frqc_d_1.code, (ftnlen)3);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_sf_frq_d_1.qa, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&pow, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE riserclv.for:1072 */
/*<   400 continue >*/
/* L400: */
	}
/*       Compute approximate maximum error and report */
/* SOURCE riserclv.for:1075 */
/*<       do600j=3,nfrac-2,2 >*/
	feq_gen_i_d_2 = nfrac - 2;
	for (j = 3; j <= feq_gen_i_d_2; j += 2) {
/* SOURCE riserclv.for:1076 */
/*<       qhat=0.5*(qmat(ihup,j-1)+qmat(ihup,j+1)) >*/
	    qhat = static_cast<double>((static_cast<double>(qmat[ihup + (j - 1) * 151 - 152]) + qmat[ihup + (j + 1) * 
		    151 - 152])) * (float).5;
/* SOURCE riserclv.for:1077 */
/*<       rerr=abs(qhat-qmat(ihup,j))/qmat(ihup,j) >*/
	    rerr = (feq_gen_r_d_1 = static_cast<double>(qhat) - qmat[ihup + j * 151 - 152], dabs(feq_gen_r_d_1)) / 
		    qmat[ihup + j * 151 - 152];
/* SOURCE riserclv.for:1078 */
/*<       rms_global=rms_global+rerr*rerr >*/
	    feq_gen_rms_global_d_ += static_cast<double>(rerr) * rerr;
/* SOURCE riserclv.for:1079 */
/*<       n_global=n_global+1 >*/
	    ++feq_gen_n_global_d_;
/* SOURCE riserclv.for:1080 */
/*<       if(rerr.gt.bigerr)then >*/
	    if (rerr > bigerr) {
/* SOURCE riserclv.for:1081 */
/*<       bigerr=rerr >*/
		bigerr = rerr;
/* SOURCE riserclv.for:1082 */
/*<       herr=hw >*/
		herr = hw;
/* SOURCE riserclv.for:1083 */
/*<       ipfd=j >*/
		ipfd = j;
/* SOURCE riserclv.for:1084 */
/*<       endif >*/
	    }
/* SOURCE riserclv.for:1085 */
/*<   600 continue >*/
/* L600: */
	}
/*       Eliminate the checking values from QMAT */
/* SOURCE riserclv.for:1088 */
/*<       jbase=3 >*/
	jbase = 3;
/* SOURCE riserclv.for:1089 */
/*<       do700j=4,nfrac-1,2 >*/
	feq_gen_i_d_2 = nfrac - 1;
	for (j = 4; j <= feq_gen_i_d_2; j += 2) {
/* SOURCE riserclv.for:1090 */
/*<       qmat(ihup,jbase)=qmat(ihup,j) >*/
	    qmat[ihup + jbase * 151 - 152] = qmat[ihup + j * 151 - 152];
/* SOURCE riserclv.for:1091 */
/*<       jbase=jbase+1 >*/
	    ++jbase;
/* SOURCE riserclv.for:1092 */
/*<   700 continue >*/
/* L700: */
	}
/* SOURCE riserclv.for:1093 */
/*<       qmat(ihup,jbase)=qmat(ihup,nfrac) >*/
	qmat[ihup + jbase * 151 - 152] = qmat[ihup + nfrac * 151 - 152];
/* SOURCE riserclv.for:1095 */
/*<  1000 continue >*/
/* L1000: */
    }
/* SOURCE riserclv.for:1097 */
/*<   900 continue >*/
/* L900: */
/* SOURCE riserclv.for:1098 */
/*<       pfdtmp(1)=pfdvec(1) >*/
    pfdtmp[0] = pfdvec[0];
/* SOURCE riserclv.for:1099 */
/*<       pfdtmp(2)=pfdvec(2) >*/
    pfdtmp[1] = pfdvec[1];
/*       Eliminate checking values of PFD */
/* SOURCE riserclv.for:1101 */
/*<       jbase=3 >*/
    jbase = 3;
/* SOURCE riserclv.for:1102 */
/*<       do910j=4,nfrac-1,2 >*/
    feq_gen_i_d_1 = nfrac - 1;
    for (j = 4; j <= feq_gen_i_d_1; j += 2) {
/* SOURCE riserclv.for:1103 */
/*<       pfdtmp(jbase)=pfdvec(j) >*/
	pfdtmp[jbase - 1] = pfdvec[j - 1];
/* SOURCE riserclv.for:1104 */
/*<       jbase=jbase+1 >*/
	++jbase;
/* SOURCE riserclv.for:1105 */
/*<   910 continue >*/
/* L910: */
    }
/* SOURCE riserclv.for:1106 */
/*<       pfdtmp(jbase)=pfdvec(nfrac) >*/
    pfdtmp[jbase - 1] = pfdvec[nfrac - 1];
/* SOURCE riserclv.for:1108 */
/*<       zrhufd=0.0 >*/
    zrhufd = (float)0.;
/* SOURCE riserclv.for:1109 */
/*<        >*/
    twdout_(stdout, stdtab, &tab, label, &nhup, &jbase, hupvec, fdvec, pfdtmp,
	     qmat, &feq_gen_head_datum_d_, &feq_gen_c_d_13, const_cast<char*>(" RISERCLV"), &zrhufd, zone, hgrid, 
	    vdatum, unitsys, basis, &easting, &northing, eflag, (ftnlen)50, (
	    ftnlen)9, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE riserclv.for:1116 */
/*<       write(stdout,86)bigerr,herr,pfdvec(ipfd) >*/
    feq_gen_io_d__169.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__169);
    do_fio(&feq_gen_c_d_1, (char *)&bigerr, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&herr, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&pfdvec[ipfd - 1], (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE riserclv.for:1119 */
/*<       rms_global=sqrt(rms_global/float(n_global)) >*/
    feq_gen_rms_global_d_ = sqrt(static_cast<double>(feq_gen_rms_global_d_) / (real) feq_gen_n_global_d_);
/* SOURCE riserclv.for:1120 */
/*<       write(stdout,88)rms_global,n_global >*/
    feq_gen_io_d__170.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__170);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_rms_global_d_, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_n_global_d_, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE riserclv.for:1122 */
/*<       return >*/
    return 0;
/* SOURCE riserclv.for:1123 */
/*<   991 continue >*/
L991:
/* SOURCE riserclv.for:1124 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__171.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__171);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE riserclv.for:1125 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__172.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__172);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE riserclv.for:1126 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE riserclv.for:1127 */
/*<       end >*/
    return 0;
} /* riserclv_ */

#undef rtmp
#undef itab
#undef ftab


#ifdef __cplusplus
	}
#endif
