#include "callbacks.hpp"
/* ufgculv.f -- translated by f2c (version 20240504).
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

/* COMMON y43_to_y4__ is declared in common.hpp. */

#define feq_gen_y43_to_y4_d_1 feq_gen_y43_to_y4_d_

/* COMMON epscom_ is declared in common.hpp. */

#define epscom_1 epscom_

/* COMMON ufgc1_ is declared in common.hpp. */

#define ufgc1_1 ufgc1_

/* COMMON seqdc_ is declared in common.hpp. */

#define seqdc_1 seqdc_

/* COMMON so_flow__ is declared in common.hpp. */

#define feq_gen_so_flow_d_1 feq_gen_so_flow_d_

/* COMMON y4_to_43__ is declared in common.hpp. */

#define feq_gen_y4_to_43_d_1 feq_gen_y4_to_43_d_

/* COMMON y4swc_ is declared in common.hpp. */

#define y4swc_1 y4swc_

/* COMMON ufgated_ is declared in common.hpp. */

#define ufgated_1 ufgated_

/* COMMON fwcc_c__ is declared in common.hpp. */

#define feq_gen_fwcc_c_d_1 feq_gen_fwcc_c_d_

/* COMMON ftable_ is declared in common.hpp. */

#define ftable_1 ftable_

/* COMMON ftablea_ is declared in common.hpp. */

#define ftablea_1 ftablea_

/* COMMON ftablec_ is declared in common.hpp. */

#define ftablec_1 ftablec_

/* COMMON ufcom_ is declared in common.hpp. */

#define ufcom_1 ufcom_

/* COMMON ufgcitm_com__ is declared in common.hpp. */

#define feq_gen_ufgcitm_com_d_1 feq_gen_ufgcitm_com_d_

/* COMMON ufgcitm_comc__ is declared in common.hpp. */

#define feq_gen_ufgcitm_comc_d_1 feq_gen_ufgcitm_comc_d_

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* Table of constant values */

static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_0 = 0;
static integer feq_gen_c_d_500 = 500;
static integer feq_gen_c_d_4 = 4;
static integer feq_gen_c_d_13 = 13;
static real c_b72 = (float)0.;
static integer feq_gen_c_d_2000 = 2000;
static integer c_n1 = -1;
static integer feq_gen_c_d_43 = 43;
static integer feq_gen_c_d_5 = 5;
static integer feq_gen_c_d_10 = 10;
static integer feq_gen_c_d_12 = 12;
static integer feq_gen_c_d_10002 = 10002;
static doublereal c_b216 = 0.;
static integer feq_gen_c_d_6 = 6;
static integer feq_gen_c_d_2 = 2;
static integer feq_gen_c_d_351 = 351;
static integer feq_gen_c_d_151 = 151;
static real c_b477 = (float)1.;
static real c_b634 = (float)-1.;
static integer feq_gen_c_d_3 = 3;




/* SOURCE ufgculv.for:4 */
/*<       realfunctionfind_y4_from_y43_resid(y4) >*/
doublereal feq_gen_find_y4_from_y43_resid_d_(real *y4)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
    real a4, b4, j4, k4, m4, t4, db4, dk4, dt4;
    extern /* Subroutine */ int xlkt21_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *);

/*     Find conditions at section 4 given a depth */
/*     section 3 */
/* SOURCE ufgculv.for:10 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:11 */
/*<       realy4 >*/
/* INCLUDE ufgculv.for:13 */
/*     Common for FIND_Y4_FROM_Y43 */
/* SOURCE y43_to_4.cmn:2 */
/*<       integertab4,stdouta >*/
/* SOURCE y43_to_4.cmn:3 */
/*<       realmexit,qsqr,g >*/
/* SOURCE y43_to_4.cmn:5 */
/*<       common/y43_to_y4/mexit,qsqr,g,tab4,stdouta >*/
/*     Local */
/* SOURCE ufgculv.for:16 */
/*<       realm4,a4,t4,dt4,j4,k4,dk4,b4,db4 >*/
/*     common */
/* *********************************************************************** */
/*      WRITE(STDOUTA,*) ' Y4=',Y4,' QSQR=',QSQR */
/* SOURCE ufgculv.for:22 */
/*<       callxlkt21(tab4,y4,a4,t4,dt4,j4,k4,dk4,b4,db4) >*/
    xlkt21_(&feq_gen_y43_to_y4_d_1.tab4, y4, &a4, &t4, &dt4, &j4, &k4, &dk4, &b4, &db4)
	    ;
/* SOURCE ufgculv.for:27 */
/*<       m4=(b4*qsqr/a4)+g*j4 >*/
    m4 = static_cast<double>(static_cast<double>(static_cast<double>(b4) * feq_gen_y43_to_y4_d_1.qsqr) / a4) + static_cast<double>(feq_gen_y43_to_y4_d_1.g) * j4;
/*      WRITE(STDOUTA,*) ' M4=',M4,' MEXIT=',MEXIT */
/* SOURCE ufgculv.for:30 */
/*<       find_y4_from_y43_resid=(m4-mexit)/mexit >*/
    ret_val = static_cast<double>((static_cast<double>(m4) - feq_gen_y43_to_y4_d_1.mexit)) / feq_gen_y43_to_y4_d_1.mexit;
/* SOURCE ufgculv.for:31 */
/*<       return >*/
    return ret_val;
/* SOURCE ufgculv.for:32 */
/*<       end >*/
} /* find_y4_from_y43_resid__ */




/* SOURCE ufgculv.for:37 */
/*<        >*/
/* Subroutine */ int feq_gen_find_y4_from_y43_d_(integer *stdout, real *grav, real *q, 
	integer *deptab, real *z3b, real *z43b, real *y3, real *aflux, real *
	costheta, real *y4, integer *feq_gen_flag_d_)
{
    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;
    real a43, b43, j43, fl, k43, fr, t43, y43, yl, yr, db43, dk43, dt43;
    extern /* Subroutine */ int xlkt21_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *);
    extern doublereal feq_gen_find_y4_from_y43_resid_d_(real *);
    extern /* Subroutine */ int regflt_(real *, real *, FeqCallback3, real *, real *, 
	    real *, real *, real *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__23 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__25 = { 0, 0, 0, 0, 0 };


/*     Find the value of depth at Y3 given the flow and depth */
/*     in the departure section. */
/* SOURCE ufgculv.for:45 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:47 */
/*<       integerflag,stdout,deptab >*/
/* SOURCE ufgculv.for:49 */
/*<       realgrav,q,z3b,z43b,y3,costheta,y4,aflux >*/
/* INCLUDE ufgculv.for:52 */
/*     Common for FIND_Y4_FROM_Y43 */
/* SOURCE y43_to_4.cmn:2 */
/*<       integertab4,stdouta >*/
/* SOURCE y43_to_4.cmn:3 */
/*<       realmexit,qsqr,g >*/
/* SOURCE y43_to_4.cmn:5 */
/*<       common/y43_to_y4/mexit,qsqr,g,tab4,stdouta >*/
/* INCLUDE ufgculv.for:53 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/*     Functions */
/* SOURCE ufgculv.for:57 */
/*<       realfind_y4_from_y43_resid >*/
/* SOURCE ufgculv.for:58 */
/*<       externalfind_y4_from_y43_resid >*/
/*     Local */
/* SOURCE ufgculv.for:62 */
/*<       integeri >*/
/* SOURCE ufgculv.for:63 */
/*<       realyl,fl,yr,fr,y43,a43,t43,dt43,j43,k43,dk43,b43,db43 >*/
/* *********************************************************************** */
/* SOURCE ufgculv.for:68 */
/*<       qsqr=q*q >*/
    feq_gen_y43_to_y4_d_1.qsqr = static_cast<double>(*q) * *q;
/* SOURCE ufgculv.for:69 */
/*<       g=grav >*/
    feq_gen_y43_to_y4_d_1.g = *grav;
/* SOURCE ufgculv.for:71 */
/*<       y43=y3+z3b-z43b >*/
    y43 = static_cast<double>(static_cast<double>(*y3) + *z3b) - *z43b;
/* SOURCE ufgculv.for:72 */
/*<       callxlkt21(deptab,y43,a43,t43,dt43,j43,k43,dk43,b43,db43) >*/
    xlkt21_(deptab, &y43, &a43, &t43, &dt43, &j43, &k43, &dk43, &b43, &db43);
/* SOURCE ufgculv.for:77 */
/*<       mexit=costheta*qsqr/aflux+g*j43 >*/
    feq_gen_y43_to_y4_d_1.mexit = static_cast<double>(static_cast<double>(static_cast<double>(*costheta) * feq_gen_y43_to_y4_d_1.qsqr) / *aflux) + 
	    static_cast<double>(feq_gen_y43_to_y4_d_1.g) * j43;
/* SOURCE ufgculv.for:79 */
/*<       tab4=deptab >*/
    feq_gen_y43_to_y4_d_1.tab4 = *deptab;
/* SOURCE ufgculv.for:80 */
/*<       stdouta=stdout >*/
    feq_gen_y43_to_y4_d_1.stdouta = *stdout;
/*     Search for a change in sign of the residual. */
/* SOURCE ufgculv.for:84 */
/*<       i=50 >*/
    feq_gen_i_d_ = 50;
/* SOURCE ufgculv.for:85 */
/*<       yl=y3+z3b-z43b >*/
    yl = static_cast<double>(static_cast<double>(*y3) + *z3b) - *z43b;
/* SOURCE ufgculv.for:86 */
/*<       yr=-1.0 >*/
    yr = (float)-1.;
/* SOURCE ufgculv.for:87 */
/*<   100 continue >*/
L100:
/* SOURCE ufgculv.for:88 */
/*<       fl=find_y4_from_y43_resid(yl) >*/
    fl = feq_gen_find_y4_from_y43_resid_d_(&yl);
/*        WRITE(STDOUT,*) ' YL=',YL,' FL=',FL */
/* SOURCE ufgculv.for:90 */
/*<       i=i-1 >*/
    --feq_gen_i_d_;
/* SOURCE ufgculv.for:91 */
/*<       if(i.eq.0)then >*/
    if (feq_gen_i_d_ == 0) {
/* SOURCE ufgculv.for:92 */
/*<       write(stdout,*)' FIND_Y4_FROM_Y43: No neg. resid.' >*/
	feq_gen_io_d__23.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__23);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FIND_Y4_FROM_Y43: No neg. resid."), (ftnlen)33);
	e_wsle();
/* SOURCE ufgculv.for:93 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE ufgculv.for:94 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:95 */
/*<       if(fl.le.0.0d0)then >*/
    if (fl <= 0.) {
/* SOURCE ufgculv.for:96 */
/*<       goto110 >*/
	goto L110;
/* SOURCE ufgculv.for:97 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:98 */
/*<       yr=yl >*/
	yr = yl;
/* SOURCE ufgculv.for:99 */
/*<       fr=fl >*/
	fr = fl;
/* SOURCE ufgculv.for:100 */
/*<       yl=0.9*yl >*/
	yl *= static_cast<double>((float).9);
/* SOURCE ufgculv.for:101 */
/*<       goto100 >*/
	goto L100;
/* SOURCE ufgculv.for:102 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:103 */
/*<   110 continue >*/
L110:
/* SOURCE ufgculv.for:104 */
/*<       if(yr.lt.0.0d0)then >*/
    if (yr < 0.) {
/* SOURCE ufgculv.for:105 */
/*<       yr=yl >*/
	yr = yl;
/* SOURCE ufgculv.for:106 */
/*<   120 continue >*/
L120:
/* SOURCE ufgculv.for:107 */
/*<       yr=1.1*yr >*/
	yr *= static_cast<double>((float)1.1);
/* SOURCE ufgculv.for:108 */
/*<       fr=find_y4_from_y43_resid(yr) >*/
	fr = feq_gen_find_y4_from_y43_resid_d_(&yr);
/* SOURCE ufgculv.for:109 */
/*<       i=i-1 >*/
	--feq_gen_i_d_;
/* SOURCE ufgculv.for:110 */
/*<       if(i.eq.0)then >*/
	if (feq_gen_i_d_ == 0) {
/* SOURCE ufgculv.for:111 */
/*<       write(stdout,*)' FIND_Y4_FROM_Y43: No pos. resid.' >*/
	    feq_gen_io_d__25.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__25);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FIND_Y4_FROM_Y43: No pos. resid."), (ftnlen)
		    33);
	    e_wsle();
/* SOURCE ufgculv.for:112 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE ufgculv.for:113 */
/*<       endif >*/
	}
/*        WRITE(STDOUT,*) ' YR=',YR,' FR=',FR */
/* SOURCE ufgculv.for:115 */
/*<       if(fr.ge.0.0d0)then >*/
	if (fr >= 0.) {
/* SOURCE ufgculv.for:116 */
/*<       goto130 >*/
	    goto L130;
/* SOURCE ufgculv.for:117 */
/*<       else >*/
	} else {
/* SOURCE ufgculv.for:118 */
/*<       fl=fr >*/
	    fl = fr;
/* SOURCE ufgculv.for:119 */
/*<       yl=yr >*/
	    yl = yr;
/* SOURCE ufgculv.for:120 */
/*<       goto120 >*/
	    goto L120;
/* SOURCE ufgculv.for:121 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:122 */
/*<   130 continue >*/
L130:
/* SOURCE ufgculv.for:123 */
/*<       endif >*/
	;
    }
/*     Found an interval that contains a root. */
/*      WRITE(STDOUT,*) ' Calling REGFLT with: YL=',YL,' FL=',FL */
/*      WRITE(STDOUT,*) ' YR=',YR,' FR=',FR */
/* SOURCE ufgculv.for:129 */
/*<       callregflt(epsarg,epsf,find_y4_from_y43_resid,yl,yr,fl,fr,y4,flag) >*/
    regflt_(&epscom_1.epsarg, &epscom_1.epsf, feq_gen_find_y4_from_y43_resid_d_, 
	    &yl, &yr, &fl, &fr, y4, feq_gen_flag_d_);
/*      WRITE(STDOUT,*) ' FL=',FL */
/*      WRITE(STDOUT,*) ' Return from REGFLT with: FLAG=',FLAG */
/*      WRITE(STDOUT,*) ' Y3 =',Y3 */
/* SOURCE ufgculv.for:138 */
/*<       if(flag.eq.3)flag=0 >*/
    if (*feq_gen_flag_d_ == 3) {
	*feq_gen_flag_d_ = 0;
    }
/* SOURCE ufgculv.for:140 */
/*<       return >*/
    return 0;
/* SOURCE ufgculv.for:141 */
/*<       end >*/
} /* find_y4_from_y43__ */




/* SOURCE ufgculv.for:145 */
/*<       real*8functionfind_sequent_depth_resid(yb) >*/
doublereal feq_gen_find_sequent_depth_resid_d_(doublereal *yb)
{
    /* System generated locals */
    doublereal ret_val;

    /* Local variables */
    doublereal ab, jb, mb;
    extern /* Subroutine */ int feq_gen_lkt_jda_d_(integer *, doublereal *, doublereal 
	    *, doublereal *, doublereal *);

/*     Find the sequent depth for a super-critical flow in */
/*     conduit.  Ignores friction and gravity. */
/* SOURCE ufgculv.for:151 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:152 */
/*<       real*8yb >*/
/* INCLUDE ufgculv.for:154 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/* INCLUDE ufgculv.for:156 */
/*     Common block for FIND_SEQENT_DEPTH */
/* SOURCE seqd.cmn:3 */
/*<       real*8mvc,g,qsqr >*/
/* SOURCE seqd.cmn:5 */
/*<       common/seqdc/mvc,g,qsqr >*/
/*     Local */
/* SOURCE ufgculv.for:161 */
/*<       real*8ab,jb,mb >*/
/* *********************************************************************** */
/* SOURCE ufgculv.for:164 */
/*<       calllkt_jda(0,xloc,yb,ab,jb) >*/
    feq_gen_lkt_jda_d_(&feq_gen_c_d_0, &ufgc1_1.xloc, yb, &ab, &jb);
/* SOURCE ufgculv.for:168 */
/*<       mb=qsqr/ab+g*jb*cos_theta >*/
    mb = seqdc_1.qsqr / ab + seqdc_1.g * jb * ufgc1_1.feq_gen_cos_theta_d_;
/* SOURCE ufgculv.for:169 */
/*<       find_sequent_depth_resid=(mb-mvc)/mvc >*/
    ret_val = (mb - seqdc_1.mvc) / seqdc_1.mvc;
/* SOURCE ufgculv.for:170 */
/*<       return >*/
    return ret_val;
/* SOURCE ufgculv.for:171 */
/*<       end >*/
} /* find_sequent_depth_resid__ */




/* SOURCE ufgculv.for:175 */
/*<        >*/
/* Subroutine */ int feq_gen_find_sequent_depth_d_(integer *stdout, doublereal *grav, 
	doublereal *hg, doublereal *bg, doublereal *cc, doublereal *q, 
	doublereal *epsarg, doublereal *epsf, doublereal *yba)
{
    /* System generated locals */
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;
    extern doublereal feq_gen_find_sequent_depth_resid_d_(doublereal *);
    doublereal fl, fr, yl, yr, avc, jvc, yvc;
    integer feq_gen_flag_d_;
    doublereal qcvc, frdn2;
    extern /* Subroutine */ int fdblrgf_(doublereal *, doublereal *, FeqCallback1, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *), feq_gen_lkt_jda_d_(integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *), feq_gen_lkt_qcd_d_(integer *, 
	    doublereal *, doublereal *, doublereal *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__38 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__40 = { 0, 0, 0, 0, 0 };


/*     Find depth sequent to a super-critical flow */
/* SOURCE ufgculv.for:182 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:183 */
/*<       integerstdout >*/
/* SOURCE ufgculv.for:185 */
/*<       real*8hg,bg,cc,q,yba,grav,epsarg,epsf >*/
/* INCLUDE ufgculv.for:188 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/* INCLUDE ufgculv.for:189 */
/*     Common block for FIND_SEQENT_DEPTH */
/* SOURCE seqd.cmn:3 */
/*<       real*8mvc,g,qsqr >*/
/* SOURCE seqd.cmn:5 */
/*<       common/seqdc/mvc,g,qsqr >*/
/*     Subroutines and functions */
/* SOURCE ufgculv.for:192 */
/*<       real*8find_sequent_depth_resid >*/
/* SOURCE ufgculv.for:193 */
/*<       externalfind_sequent_depth_resid >*/
/*     Local variables */
/* SOURCE ufgculv.for:197 */
/*<       integeri,flag >*/
/* SOURCE ufgculv.for:199 */
/*<       real*8yl,fl,yr,fr,frdn2,yvc,avc,jvc,qcvc >*/
/* *********************************************************************** */
/* SOURCE ufgculv.for:202 */
/*<       g=grav >*/
    seqdc_1.g = *grav;
/* SOURCE ufgculv.for:203 */
/*<       qsqr=q*q >*/
    seqdc_1.qsqr = *q * *q;
/* SOURCE ufgculv.for:204 */
/*<       xloc=station(1)+hg >*/
    ufgc1_1.xloc = ufgc1_1.station[0] + *hg;
/* SOURCE ufgculv.for:205 */
/*<       yvc=cc*hg >*/
    yvc = *cc * *hg;
/* SOURCE ufgculv.for:206 */
/*<       calllkt_jda(1,xloc,yvc,avc,jvc) >*/
    feq_gen_lkt_jda_d_(&feq_gen_c_d_1, &ufgc1_1.xloc, &yvc, &avc, &jvc);
/* SOURCE ufgculv.for:210 */
/*<       mvc=qsqr/(yvc*bg)+g*jvc*cos_theta >*/
    seqdc_1.mvc = seqdc_1.qsqr / (yvc * *bg) + seqdc_1.g * jvc * 
	    ufgc1_1.feq_gen_cos_theta_d_;
/* SOURCE ufgculv.for:211 */
/*<       calllkt_qcd(0,xloc,yvc,qcvc) >*/
    feq_gen_lkt_qcd_d_(&feq_gen_c_d_0, &ufgc1_1.xloc, &yvc, &qcvc);
/* SOURCE ufgculv.for:215 */
/*<       frdn2=qsqr/qcvc**2 >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = qcvc;
    frdn2 = seqdc_1.qsqr / (feq_gen_d_d_1 * feq_gen_d_d_1);
/* SOURCE ufgculv.for:217 */
/*<       yl=0.5d0*yvc*(sqrt(1.d0+8.0d0*frdn2)-1.d0) >*/
    yl = yvc * .5 * (sqrt(frdn2 * 8. + 1.) - 1.);
/* SOURCE ufgculv.for:218 */
/*<       yr=-1.d0 >*/
    yr = -1.;
/* SOURCE ufgculv.for:219 */
/*<       i=100 >*/
    feq_gen_i_d_ = 100;
/* SOURCE ufgculv.for:220 */
/*<   100 continue >*/
L100:
/* SOURCE ufgculv.for:221 */
/*<       fl=find_sequent_depth_resid(yl) >*/
    fl = feq_gen_find_sequent_depth_resid_d_(&yl);
/* SOURCE ufgculv.for:222 */
/*<       i=i-1 >*/
    --feq_gen_i_d_;
/* SOURCE ufgculv.for:223 */
/*<       if(i.eq.0)then >*/
    if (feq_gen_i_d_ == 0) {
/* SOURCE ufgculv.for:224 */
/*<       write(stdout,*)' FIND_SEQUENT_DEPTH: No negative residual.' >*/
	feq_gen_io_d__38.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__38);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FIND_SEQUENT_DEPTH: No negative residual."), (
		ftnlen)42);
	e_wsle();
/* SOURCE ufgculv.for:225 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE ufgculv.for:226 */
/*<       endif >*/
    }
/*        WRITE(STDOUT,*) ' YL=',YL,' FL=',FL */
/* SOURCE ufgculv.for:228 */
/*<       if(fl.le.0.0d0)then >*/
    if (fl <= 0.) {
/* SOURCE ufgculv.for:229 */
/*<       goto110 >*/
	goto L110;
/* SOURCE ufgculv.for:230 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:231 */
/*<       yr=yl >*/
	yr = yl;
/* SOURCE ufgculv.for:232 */
/*<       fr=fl >*/
	fr = fl;
/* SOURCE ufgculv.for:233 */
/*<       yl=0.95d0*yl >*/
	yl *= .95;
/* SOURCE ufgculv.for:234 */
/*<       goto100 >*/
	goto L100;
/* SOURCE ufgculv.for:235 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:236 */
/*<   110 continue >*/
L110:
/* SOURCE ufgculv.for:238 */
/*<       if(yr.lt.0.0d0)then >*/
    if (yr < 0.) {
/* SOURCE ufgculv.for:239 */
/*<       yr=yl >*/
	yr = yl;
/* SOURCE ufgculv.for:240 */
/*<   120 continue >*/
L120:
/* SOURCE ufgculv.for:241 */
/*<       yr=1.1*yr >*/
	yr *= (float)1.1;
/* SOURCE ufgculv.for:242 */
/*<       fr=find_sequent_depth_resid(yr) >*/
	fr = feq_gen_find_sequent_depth_resid_d_(&yr);
/* SOURCE ufgculv.for:243 */
/*<       i=i-1 >*/
	--feq_gen_i_d_;
/* SOURCE ufgculv.for:244 */
/*<       if(i.eq.0)then >*/
	if (feq_gen_i_d_ == 0) {
/* SOURCE ufgculv.for:245 */
/*<       write(stdout,*)' FIND_SEQUENT_DEPTH: No positive residual.' >*/
	    feq_gen_io_d__40.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__40);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FIND_SEQUENT_DEPTH: No positive residual."),
		     (ftnlen)42);
	    e_wsle();
/* SOURCE ufgculv.for:246 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE ufgculv.for:247 */
/*<       endif >*/
	}
/*        WRITE(STDOUT,*) ' YR=',YR,' FR=',FR */
/* SOURCE ufgculv.for:249 */
/*<       if(fr.ge.0.0d0)then >*/
	if (fr >= 0.) {
/* SOURCE ufgculv.for:250 */
/*<       goto130 >*/
	    goto L130;
/* SOURCE ufgculv.for:251 */
/*<       else >*/
	} else {
/* SOURCE ufgculv.for:252 */
/*<       fl=fr >*/
	    fl = fr;
/* SOURCE ufgculv.for:253 */
/*<       yl=yr >*/
	    yl = yr;
/* SOURCE ufgculv.for:254 */
/*<       goto120 >*/
	    goto L120;
/* SOURCE ufgculv.for:255 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:256 */
/*<   130 continue >*/
L130:
/* SOURCE ufgculv.for:257 */
/*<       endif >*/
	;
    }
/*     Found an interval that contains a root. */
/*      WRITE(STDOUT,*) ' Calling FDBLRGF with: YL=',YL,' FL=',FL */
/*      WRITE(STDOUT,*) ' YR=',YR,' FR=',FR */
/* SOURCE ufgculv.for:264 */
/*<        >*/
    fdblrgf_(epsarg, epsf, feq_gen_find_sequent_depth_resid_d_, &yl, &yr, &fl, &
	    fr, yba, &feq_gen_flag_d_);
/*      WRITE(STDOUT,*) ' FL=',FL */
/*      WRITE(STDOUT,*) ' Return from FDBLRGF with: FLAG=',FLAG */
/*      WRITE(STDOUT,*) ' YBA =',YBA, ' KNT=',INT(FR) */
/* SOURCE ufgculv.for:273 */
/*<       if(flag.eq.3)flag=0 >*/
    if (feq_gen_flag_d_ == 3) {
	feq_gen_flag_d_ = 0;
    }
/* SOURCE ufgculv.for:275 */
/*<       return >*/
    return 0;
/* SOURCE ufgculv.for:276 */
/*<       end >*/
} /* find_sequent_depth__ */





/* SOURCE ufgculv.for:282 */
/*<       realfunctionfind_so_flow_resid(yvc) >*/
doublereal feq_gen_find_so_flow_resid_d_(real *yvc)
{
    /* System generated locals */
    real ret_val;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    extern doublereal e_(doublereal*, doublereal*);
    doublereal ab, jb;
    integer ne;
    doublereal ml, yb, mr;
    integer ns;
    doublereal ys;
    extern /* Subroutine */ int feq_gen_find_ycynym_d_(integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *);
    doublereal abvc, jbvc, epsf;
    extern doublereal rhse_(doublereal*, doublereal*);
    doublereal ymax, ycrit;
    extern /* Subroutine */ int sfwsp_(integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, FeqCallback2, FeqCallback2, FeqCallback4, integer *, integer *
	    , integer *, doublereal *, doublereal *, doublereal *, doublereal 
	    *, integer *);
    doublereal ynorm, epsabs, epsarg;
    extern /* Subroutine */ int feq_gen_lkt_jda_d_(integer *, doublereal *, doublereal 
	    *, doublereal *, doublereal *), feq_gen_find_y43_from_y4_d_(integer *, 
	    real *, real *, integer *, integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, integer *);

/*     Find the SO flow given tailwater at section 4 and the */
/*     headwater at section 1.  We use the depth at the vena */
/*     contracta to try to make the solution faster. */
/* SOURCE ufgculv.for:289 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:290 */
/*<       realyvc >*/
/* INCLUDE ufgculv.for:292 */
/*     Common block for SO_FLOW computations in UFGCULV */
/* SOURCE so_flow.cmn:3 */
/*<       integernmax >*/
/* SOURCE so_flow.cmn:4 */
/*<       parameter(nmax=500) >*/
/* SOURCE so_flow.cmn:5 */
/*<       integerdtab,etab,stdouta,rflag,yc_flag >*/
/* SOURCE so_flow.cmn:6 */
/*<       realafac,div,h1eff,qsqr,g,z3b,z4b,y3,y4,a4,b4,j4,costheta >*/
/* SOURCE so_flow.cmn:8 */
/*<        >*/
/* SOURCE so_flow.cmn:11 */
/*<        >*/
/* INCLUDE ufgculv.for:293 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/*     Functions and subroutines */
/* SOURCE ufgculv.for:296 */
/*<       real*8e,rhse >*/
/* SOURCE ufgculv.for:297 */
/*<       externale,rhse,find_ycynym >*/
/*     Local */
/* SOURCE ufgculv.for:300 */
/*<       integerns,ne >*/
/* SOURCE ufgculv.for:301 */
/*<        >*/
/* *********************************************************************** */
/* SOURCE ufgculv.for:306 */
/*<       epsarg=0.01d0*epsd >*/
    epsarg = feq_gen_so_flow_d_1.epsd * .01;
/* SOURCE ufgculv.for:307 */
/*<       epsf=0.00001d0*epsd >*/
    epsf = feq_gen_so_flow_d_1.epsd * 1e-5;
/* SOURCE ufgculv.for:308 */
/*<       epsabs=0.0001d0*epsd >*/
    epsabs = feq_gen_so_flow_d_1.epsd * 1e-4;
/*     Compute an estimate of the flow */
/*     Compute the flow from the given YVC and the energy equation. */
/*     Note that only valid values of YVC should appear here. */
/*      WRITE(STDOUTA,*) ' FIND_SO_FLOW_RESID: YVC=',YVC */
/*      WRITE(STDOUTA,*) ' AFAC=',AFAC, ' H1EFF=',H1EFF */
/*      WRITE(STDOUTA,*) ' DIV=',DIV,' COSTHETA=',COSTHETA */
/* SOURCE ufgculv.for:318 */
/*<       qsqr=afac*afac*((g+g)*(h1eff-yvc*costheta)/div) >*/
    feq_gen_so_flow_d_1.qsqr = static_cast<double>(static_cast<double>(feq_gen_so_flow_d_1.afac) * feq_gen_so_flow_d_1.afac) * (static_cast<double>(static_cast<double>((static_cast<double>(feq_gen_so_flow_d_1.g) + 
	    feq_gen_so_flow_d_1.g)) * (static_cast<double>(feq_gen_so_flow_d_1.h1eff) - static_cast<double>(*yvc) * feq_gen_so_flow_d_1.costheta)) / 
	    feq_gen_so_flow_d_1.div);
/*      WRITE(STDOUTA,*) ' FIND_SO_FLOW_RESID: Q=',SQRT(QSQR) */
/*     Now compute the conditions at the culvert exit from */
/*     the tailwater level and the just computed flow. */
/* SOURCE ufgculv.for:325 */
/*<        >*/
    feq_gen_find_y43_from_y4_d_(&feq_gen_so_flow_d_1.stdouta, &feq_gen_so_flow_d_1.g, &feq_gen_so_flow_d_1.qsqr, &
	    feq_gen_so_flow_d_1.dtab, &feq_gen_so_flow_d_1.etab, &feq_gen_so_flow_d_1.z3b, &
	    feq_gen_so_flow_d_1.z4b, &feq_gen_so_flow_d_1.y4, &feq_gen_so_flow_d_1.a4, &feq_gen_so_flow_d_1.b4, &
	    feq_gen_so_flow_d_1.j4, &feq_gen_so_flow_d_1.costheta, &feq_gen_so_flow_d_1.y3, &
	    feq_gen_so_flow_d_1.rflag);
/*     Next, compute water surface profile from barrel exit */
/*     to the vena contracta in the culvert barrel. */
/* SOURCE ufgculv.for:334 */
/*<       qd=sqrt(dble(qsqr)) >*/
    ufgc1_1.qd = sqrt((doublereal) feq_gen_so_flow_d_1.qsqr);
/*     Find critical depth and normal depth */
/* SOURCE ufgculv.for:337 */
/*<       ycrit=y3 >*/
    ycrit = feq_gen_so_flow_d_1.y3;
/* SOURCE ufgculv.for:338 */
/*<       ynorm=y3 >*/
    ynorm = feq_gen_so_flow_d_1.y3;
/* SOURCE ufgculv.for:339 */
/*<        >*/
    feq_gen_find_ycynym_d_(&feq_gen_so_flow_d_1.stdouta, &feq_gen_so_flow_d_1.xs, &epsarg, &epsf, &
	    epsabs, &ycrit, &ynorm, &ymax, &feq_gen_so_flow_d_1.rflag);
/* SOURCE ufgculv.for:344 */
/*<       if(y3.le.ycrit)then >*/
    if (feq_gen_so_flow_d_1.y3 <= ycrit) {
/* SOURCE ufgculv.for:345 */
/*<       ys=1.001*ycrit >*/
	ys = ycrit * (float)1.001;
/* SOURCE ufgculv.for:346 */
/*<       yc_flag=1 >*/
	feq_gen_so_flow_d_1.feq_gen_yc_flag_d_ = 1;
/*        WRITE(STDOUTA,*) ' Invalid Y3 in FIND_SO_FLOW_RESID.' */
/*        WRITE(STDOUTA,*) ' Y3=',Y3,' YCRIT=',YCRIT */
/*        WRITE(STDOUTA,*) ' QD=',QD */
/* SOURCE ufgculv.for:350 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:351 */
/*<       yc_flag=0 >*/
	feq_gen_so_flow_d_1.feq_gen_yc_flag_d_ = 0;
/* SOURCE ufgculv.for:352 */
/*<       ys=dble(y3) >*/
	ys = (doublereal) feq_gen_so_flow_d_1.y3;
/* SOURCE ufgculv.for:353 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:354 */
/*<        >*/
    sfwsp_(&feq_gen_so_flow_d_1.stdouta, &feq_gen_so_flow_d_1.xs, &feq_gen_so_flow_d_1.xe, &ys, &
	    feq_gen_so_flow_d_1.epsd, e_, rhse_, feq_gen_find_ycynym_d_, &
	    feq_gen_c_d_500, &ns, &ne, feq_gen_so_flow_d_1.xvec, feq_gen_so_flow_d_1.yvec, 
	    feq_gen_so_flow_d_1.ycvec, feq_gen_so_flow_d_1.ynvec, &feq_gen_so_flow_d_1.rflag);
/*     Check to see if the profile reached the goal */
/* SOURCE ufgculv.for:360 */
/*<       if(abs(xe-xvec(ns))/abs(xs-xe).gt.1.d-6)then >*/
    if ((feq_gen_d_d_1 = feq_gen_so_flow_d_1.xe - feq_gen_so_flow_d_1.xvec[ns - 1], abs(feq_gen_d_d_1)) / (feq_gen_d_d_2 = 
	    feq_gen_so_flow_d_1.xs - feq_gen_so_flow_d_1.xe, abs(feq_gen_d_d_2)) > 1e-6) {
/* SOURCE ufgculv.for:361 */
/*<       rflag=-9 >*/
	feq_gen_so_flow_d_1.rflag = -9;
/* SOURCE ufgculv.for:362 */
/*<       find_so_flow_resid=0.0 >*/
	ret_val = (float)0.;
/* SOURCE ufgculv.for:363 */
/*<       xe=xvec(ns) >*/
	feq_gen_so_flow_d_1.xe = feq_gen_so_flow_d_1.xvec[ns - 1];
/* SOURCE ufgculv.for:364 */
/*<       else >*/
    } else {
/*       Compute the residual from the momentum balance at the */
/*       vena contracta */
/* SOURCE ufgculv.for:369 */
/*<       yb=yvec(ns) >*/
	yb = feq_gen_so_flow_d_1.yvec[ns - 1];
/* SOURCE ufgculv.for:371 */
/*<       calllkt_jda(0,xe,yb,ab,jb) >*/
	feq_gen_lkt_jda_d_(&feq_gen_c_d_0, &feq_gen_so_flow_d_1.xe, &yb, &ab, &jb);
/* SOURCE ufgculv.for:375 */
/*<       calllkt_jda(0,xe,dble(yvc),abvc,jbvc) >*/
	feq_gen_d_d_1 = (doublereal) (*yvc);
	feq_gen_lkt_jda_d_(&feq_gen_c_d_0, &feq_gen_so_flow_d_1.xe, &feq_gen_d_d_1, &abvc, &jbvc);
/* SOURCE ufgculv.for:379 */
/*<       ml=qsqr/ajet+g*jbvc*costheta >*/
	ml = feq_gen_so_flow_d_1.qsqr / feq_gen_so_flow_d_1.ajet + feq_gen_so_flow_d_1.g * jbvc * 
		feq_gen_so_flow_d_1.costheta;
/* SOURCE ufgculv.for:380 */
/*<       mr=qsqr/ab+g*jb*costheta >*/
	mr = feq_gen_so_flow_d_1.qsqr / ab + feq_gen_so_flow_d_1.g * jb * feq_gen_so_flow_d_1.costheta;
/* SOURCE ufgculv.for:382 */
/*<       find_so_flow_resid=(mr-ml)/ml >*/
	ret_val = (mr - ml) / ml;
/* SOURCE ufgculv.for:383 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:384 */
/*<       return >*/
    return ret_val;
/* SOURCE ufgculv.for:385 */
/*<       end >*/
} /* find_so_flow_resid__ */




/* SOURCE ufgculv.for:389 */
/*<        >*/
/* Subroutine */ int feq_gen_find_so_flow_d_(integer *stdout, integer *deptab, integer 
	*exittab, real *grav, real *h1, real *hg, real *bg, real *cc, real *
	cd, real *feq_gen_sin_theta_d_, real *feq_gen_cos_theta_d_, real *z3ba, real *z4ba, 
	real *y4a, real *a4a, real *b4a, real *j4a, real *alpha1, real *a1, 
	integer *nxs, doublereal *feq_storage_station, doublereal *feq_gen_eps_d_d_, real *yvcold, 
	real *q, real *y3a, real *feq_gen_xe_r_d_, integer *feq_gen_flag_d_)
{
    /* System generated locals */
    real feq_gen_r_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    integer feq_gen_i_d_;
    real fl, fr, yl, yr;
    extern doublereal feq_gen_find_so_flow_resid_d_(real *);
    extern /* Subroutine */ int rgf_(real *, real *, FeqCallback3, real *, real *, 
	    real *, real *, real *, integer *);
    real yvc, feq_gen_yvc_min_d_, feq_gen_yvc_max_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__64 = { 0, 0, 0, 0, 0 };


/*     Compute the SO flows */
/* SOURCE ufgculv.for:399 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:400 */
/*<       integerstdout,deptab,exittab,flag,nxs >*/
/* SOURCE ufgculv.for:402 */
/*<        >*/
/* SOURCE ufgculv.for:406 */
/*<       real*8station(nxs),eps_d >*/
/* INCLUDE ufgculv.for:408 */
/*     Common block for SO_FLOW computations in UFGCULV */
/* SOURCE so_flow.cmn:3 */
/*<       integernmax >*/
/* SOURCE so_flow.cmn:4 */
/*<       parameter(nmax=500) >*/
/* SOURCE so_flow.cmn:5 */
/*<       integerdtab,etab,stdouta,rflag,yc_flag >*/
/* SOURCE so_flow.cmn:6 */
/*<       realafac,div,h1eff,qsqr,g,z3b,z4b,y3,y4,a4,b4,j4,costheta >*/
/* SOURCE so_flow.cmn:8 */
/*<        >*/
/* SOURCE so_flow.cmn:11 */
/*<        >*/
/* INCLUDE ufgculv.for:409 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/*     Functions and subroutines */
/* SOURCE ufgculv.for:412 */
/*<       realfind_so_flow_resid >*/
/* SOURCE ufgculv.for:413 */
/*<       externalfind_so_flow_resid >*/
/*     Local */
/* SOURCE ufgculv.for:417 */
/*<       integeri >*/
/* SOURCE ufgculv.for:418 */
/*<       realyl,fl,yr,fr,yvc_min,yvc_max,yvc >*/
/* *********************************************************************** */
/* SOURCE ufgculv.for:421 */
/*<       flag=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> station(feq_storage_station, 1);

    /* Function Body */
    *feq_gen_flag_d_ = 0;
/*      WRITE(STDOUT,*) ' FIND_SO_FLOW: H1=',H1,' Y4=',Y4A */
/*     Set values in the common block for the residual function */
/* SOURCE ufgculv.for:424 */
/*<       dtab=deptab >*/
    feq_gen_so_flow_d_1.dtab = *deptab;
/* SOURCE ufgculv.for:425 */
/*<       etab=exittab >*/
    feq_gen_so_flow_d_1.etab = *exittab;
/* SOURCE ufgculv.for:426 */
/*<       stdouta=stdout >*/
    feq_gen_so_flow_d_1.stdouta = *stdout;
/* SOURCE ufgculv.for:427 */
/*<       rflag=0 >*/
    feq_gen_so_flow_d_1.rflag = 0;
/* SOURCE ufgculv.for:428 */
/*<       g=grav >*/
    feq_gen_so_flow_d_1.g = *grav;
/* SOURCE ufgculv.for:430 */
/*<       ajet=dble(hg)*dble(bg)*dble(cc) >*/
    feq_gen_so_flow_d_1.ajet = (doublereal) (*hg) * (doublereal) (*bg) * (doublereal) (
	    *cc);
/* SOURCE ufgculv.for:431 */
/*<       afac=hg*bg*cc*cd >*/
    feq_gen_so_flow_d_1.afac = static_cast<double>(static_cast<double>(static_cast<double>(*hg) * *bg) * *cc) * *cd;
/* SOURCE ufgculv.for:432 */
/*<       div=1.0-alpha1*(afac/a1)**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(feq_gen_so_flow_d_1.afac) / *a1;
    feq_gen_so_flow_d_1.div = static_cast<double>((float)1.) - static_cast<double>(*alpha1) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE ufgculv.for:433 */
/*<       h1eff=h1+hg*sin_theta >*/
    feq_gen_so_flow_d_1.h1eff = static_cast<double>(*h1) + static_cast<double>(*hg) * *feq_gen_sin_theta_d_;
/* SOURCE ufgculv.for:434 */
/*<       costheta=cos_theta >*/
    feq_gen_so_flow_d_1.costheta = *feq_gen_cos_theta_d_;
/* SOURCE ufgculv.for:436 */
/*<       z3b=z3ba >*/
    feq_gen_so_flow_d_1.z3b = *z3ba;
/* SOURCE ufgculv.for:437 */
/*<       z4b=z4ba >*/
    feq_gen_so_flow_d_1.z4b = *z4ba;
/* SOURCE ufgculv.for:438 */
/*<       y4=y4a >*/
    feq_gen_so_flow_d_1.y4 = *y4a;
/* SOURCE ufgculv.for:439 */
/*<       a4=a4a >*/
    feq_gen_so_flow_d_1.a4 = *a4a;
/* SOURCE ufgculv.for:440 */
/*<       b4=b4a >*/
    feq_gen_so_flow_d_1.b4 = *b4a;
/* SOURCE ufgculv.for:441 */
/*<       j4=j4a >*/
    feq_gen_so_flow_d_1.j4 = *j4a;
/* SOURCE ufgculv.for:442 */
/*<       xs=station(nxs) >*/
    feq_gen_so_flow_d_1.xs = station[*nxs];
/* SOURCE ufgculv.for:443 */
/*<       xe=station(1)+hg >*/
    feq_gen_so_flow_d_1.xe = station[1] + *hg;
/* SOURCE ufgculv.for:444 */
/*<       epsd=eps_d >*/
    feq_gen_so_flow_d_1.epsd = *feq_gen_eps_d_d_;
/* SOURCE ufgculv.for:446 */
/*<       yvc_min=yvcold >*/
    feq_gen_yvc_min_d_ = *yvcold;
/* SOURCE ufgculv.for:447 */
/*<       yvc_max=0.9999*h1eff/cos_theta >*/
    feq_gen_yvc_max_d_ = static_cast<double>(static_cast<double>(feq_gen_so_flow_d_1.h1eff) * (float).9999) / *feq_gen_cos_theta_d_;
/*      WRITE(STDOUT,*) ' YVC_MIN=',YVC_MIN,' YVC_MAX=',YVC_MAX */
/* SOURCE ufgculv.for:450 */
/*<       yl=yvc_min >*/
    yl = feq_gen_yvc_min_d_;
/* SOURCE ufgculv.for:451 */
/*<       yr=-1.0 >*/
    yr = (float)-1.;
/* SOURCE ufgculv.for:452 */
/*<       i=100 >*/
    feq_gen_i_d_ = 100;
/* SOURCE ufgculv.for:453 */
/*<   100 continue >*/
L100:
/* SOURCE ufgculv.for:454 */
/*<       fl=find_so_flow_resid(yl) >*/
    fl = feq_gen_find_so_flow_resid_d_(&yl);
/* SOURCE ufgculv.for:455 */
/*<       i=i-1 >*/
    --feq_gen_i_d_;
/* SOURCE ufgculv.for:456 */
/*<       if(i.eq.0)then >*/
    if (feq_gen_i_d_ == 0) {
/* SOURCE ufgculv.for:457 */
/*<       write(stdout,*)' FIND_SO_FLOW: No negative residual.' >*/
	feq_gen_io_d__64.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__64);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FIND_SO_FLOW: No negative residual."), (ftnlen)
		36);
	e_wsle();
/* SOURCE ufgculv.for:458 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE ufgculv.for:459 */
/*<       endif >*/
    }
/*        WRITE(STDOUT,*) ' YL=',YL,' FL=',FL */
/* SOURCE ufgculv.for:461 */
/*<       if(fl.le.0.0d0)then >*/
    if (fl <= 0.) {
/* SOURCE ufgculv.for:462 */
/*<       goto110 >*/
	goto L110;
/* SOURCE ufgculv.for:463 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:464 */
/*<       yr=yl >*/
	yr = yl;
/* SOURCE ufgculv.for:465 */
/*<       fr=fl >*/
	fr = fl;
/* SOURCE ufgculv.for:466 */
/*<       yl=0.9*yl+0.1*yvc_max >*/
	yl = static_cast<double>(static_cast<double>(yl) * (float).9) + static_cast<double>(feq_gen_yvc_max_d_) * (float).1;
/* SOURCE ufgculv.for:467 */
/*<       goto100 >*/
	goto L100;
/* SOURCE ufgculv.for:468 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:469 */
/*<   110 continue >*/
L110:
/* SOURCE ufgculv.for:471 */
/*<       if(yr.lt.0.0d0)then >*/
    if (yr < 0.) {
/* SOURCE ufgculv.for:472 */
/*<       yr=yl >*/
	yr = yl;
/* SOURCE ufgculv.for:473 */
/*<   120 continue >*/
L120:
/* SOURCE ufgculv.for:474 */
/*<       yr=0.9*yr+0.1*yvc_max >*/
	yr = static_cast<double>(static_cast<double>(yr) * (float).9) + static_cast<double>(feq_gen_yvc_max_d_) * (float).1;
/* SOURCE ufgculv.for:475 */
/*<       fr=find_so_flow_resid(yr) >*/
	fr = feq_gen_find_so_flow_resid_d_(&yr);
/* SOURCE ufgculv.for:476 */
/*<       i=i-1 >*/
	--feq_gen_i_d_;
/* SOURCE ufgculv.for:477 */
/*<       if(i.eq.0)then >*/
	if (feq_gen_i_d_ == 0) {
/*            WRITE(STDOUT,*) ' FIND_SO_FLOW: No positive residual.' */
/*            WRITE(STDOUT,*) ' YL=',YL,' FL=',FL */
/*            WRITE(STDOUT,*) ' YR=',YR,' FR=',FR */
/* SOURCE ufgculv.for:481 */
/*<       flag=-10 >*/
	    *feq_gen_flag_d_ = -10;
/* SOURCE ufgculv.for:482 */
/*<       return >*/
	    return 0;
/* SOURCE ufgculv.for:484 */
/*<       endif >*/
	}
/*        WRITE(STDOUT,*) ' YR=',YR,' FR=',FR */
/* SOURCE ufgculv.for:486 */
/*<       if(fr.ge.0.0d0)then >*/
	if (fr >= 0.) {
/* SOURCE ufgculv.for:487 */
/*<       goto130 >*/
	    goto L130;
/* SOURCE ufgculv.for:488 */
/*<       else >*/
	} else {
/* SOURCE ufgculv.for:489 */
/*<       fl=fr >*/
	    fl = fr;
/* SOURCE ufgculv.for:490 */
/*<       yl=yr >*/
	    yl = yr;
/* SOURCE ufgculv.for:491 */
/*<       goto120 >*/
	    goto L120;
/* SOURCE ufgculv.for:492 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:493 */
/*<   130 continue >*/
L130:
/* SOURCE ufgculv.for:494 */
/*<       endif >*/
	;
    }
/* SOURCE ufgculv.for:496 */
/*<       if(rflag.eq.-9)then >*/
    if (feq_gen_so_flow_d_1.rflag == -9) {
/* SOURCE ufgculv.for:497 */
/*<       flag=-11 >*/
	*feq_gen_flag_d_ = -11;
/* SOURCE ufgculv.for:498 */
/*<       xe_r=xe >*/
	*feq_gen_xe_r_d_ = feq_gen_so_flow_d_1.xe;
/* SOURCE ufgculv.for:499 */
/*<       return >*/
	return 0;
/* SOURCE ufgculv.for:500 */
/*<       endif >*/
    }
/*     Found an interval that contains a root. */
/*      WRITE(STDOUT,*) ' Calling RGF with: YL=',YL,' FL=',FL */
/*      WRITE(STDOUT,*) ' YR=',YR,' FR=',FR */
/* SOURCE ufgculv.for:506 */
/*<       callrgf(epsarg,epsf,find_so_flow_resid,yl,yr,fl,fr,yvc,flag) >*/
    rgf_(&epscom_1.epsarg, &epscom_1.epsf, feq_gen_find_so_flow_resid_d_, &yl, &
	    yr, &fl, &fr, &yvc, feq_gen_flag_d_);
/*      WRITE(STDOUT,*) ' FL=',FL */
/*      WRITE(STDOUT,*) ' Return from RGF with: FLAG=',FLAG */
/*      WRITE(STDOUT,*) ' Y3 =',Y3 */
/* SOURCE ufgculv.for:515 */
/*<       if(flag.eq.3)flag=0 >*/
    if (*feq_gen_flag_d_ == 3) {
	*feq_gen_flag_d_ = 0;
    }
/* SOURCE ufgculv.for:517 */
/*<       yvcold=yvc >*/
    *yvcold = yvc;
/* SOURCE ufgculv.for:518 */
/*<       q=sqrt(qsqr) >*/
    *q = sqrt(feq_gen_so_flow_d_1.qsqr);
/* SOURCE ufgculv.for:519 */
/*<       y3a=y3 >*/
    *y3a = feq_gen_so_flow_d_1.y3;
/* SOURCE ufgculv.for:520 */
/*<       if(yc_flag.eq.1)flag=-12 >*/
    if (feq_gen_so_flow_d_1.feq_gen_yc_flag_d_ == 1) {
	*feq_gen_flag_d_ = -12;
    }
/* SOURCE ufgculv.for:522 */
/*<       return >*/
    return 0;
/* SOURCE ufgculv.for:523 */
/*<       end >*/
} /* find_so_flow__ */




/* SOURCE ufgculv.for:528 */
/*<       realfunctionfind_y43_from_y4_resid(y3) >*/
doublereal feq_gen_find_y43_from_y4_resid_d_(real *y3)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
    real a3, j43, y43;
    extern /* Subroutine */ int lkta_(integer *, real *, real *), lktj_(
	    integer *, real *, real *);
    real mexit;

/*     Find conditions at culvert exist given a depth in the */
/*     departure section and with the flow known. */
/* SOURCE ufgculv.for:534 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:535 */
/*<       realy3 >*/
/* INCLUDE ufgculv.for:537 */
/*     Common block for FIND_Y43_FROM_Y4 */
/* SOURCE y4_to_43.cmn:2 */
/*<       integertab43,tabexit >*/
/* SOURCE y4_to_43.cmn:3 */
/*<       realg,m4,qsqr,zb43,zb3,costheta >*/
/* SOURCE y4_to_43.cmn:5 */
/*<       common/y4_to_43/g,m4,qsqr,zb43,zb3,costheta,tab43,tabexit >*/
/*     Local */
/* SOURCE ufgculv.for:540 */
/*<       realj43,mexit,y43,a3 >*/
/* *********************************************************************** */
/*     Find first moment at section 43 */
/* SOURCE ufgculv.for:545 */
/*<       y43=y3+zb3-zb43 >*/
    y43 = static_cast<double>(static_cast<double>(*y3) + feq_gen_y4_to_43_d_1.zb3) - feq_gen_y4_to_43_d_1.zb43;
/* SOURCE ufgculv.for:546 */
/*<       calllktj(tab43,y43,j43) >*/
    lktj_(&feq_gen_y4_to_43_d_1.tab43, &y43, &j43);
/*     Find area in barrel exit. */
/* SOURCE ufgculv.for:552 */
/*<       calllkta(tabexit,y3,a3) >*/
    lkta_(&feq_gen_y4_to_43_d_1.tabexit, y3, &a3);
/* SOURCE ufgculv.for:557 */
/*<       mexit=qsqr/a3*costheta+g*j43 >*/
    mexit = static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_y4_to_43_d_1.qsqr) / a3) * feq_gen_y4_to_43_d_1.costheta) + static_cast<double>(feq_gen_y4_to_43_d_1.g) * 
	    j43;
/* SOURCE ufgculv.for:559 */
/*<       find_y43_from_y4_resid=(mexit-m4)/m4 >*/
    ret_val = static_cast<double>((static_cast<double>(mexit) - feq_gen_y4_to_43_d_1.m4)) / feq_gen_y4_to_43_d_1.m4;
/* SOURCE ufgculv.for:560 */
/*<       return >*/
    return ret_val;
/* SOURCE ufgculv.for:561 */
/*<       end >*/
} /* find_y43_from_y4_resid__ */




/* SOURCE ufgculv.for:566 */
/*<        >*/
/* Subroutine */ int feq_gen_find_y43_from_y4_d_(integer *stdout, real *grav, real *q2,
	 integer *deptab, integer *exittab, real *z3b, real *z4b, real *y4, 
	real *a4, real *b4, real *j4, real *feq_gen_cos_theta_d_, real *y3, integer *
	feq_gen_flag_d_)
{
    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    real fl, fr, yl, yr;
    extern doublereal feq_gen_find_y43_from_y4_resid_d_(real *);
    extern /* Subroutine */ int regflt_(real *, real *, FeqCallback3, real *, real *, 
	    real *, real *, real *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__75 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__76 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__77 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__78 = { 0, 0, 0, 0, 0 };


/*     Find the value of depth at Y3 given the flow and depth */
/*     in the departure section. */
/* SOURCE ufgculv.for:574 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:576 */
/*<       integerflag,stdout,exittab,deptab >*/
/* SOURCE ufgculv.for:578 */
/*<       realgrav,q2,z3b,z4b,a4,b4,j4,y3,cos_theta,y4 >*/
/* INCLUDE ufgculv.for:581 */
/*     Common block for FIND_Y43_FROM_Y4 */
/* SOURCE y4_to_43.cmn:2 */
/*<       integertab43,tabexit >*/
/* SOURCE y4_to_43.cmn:3 */
/*<       realg,m4,qsqr,zb43,zb3,costheta >*/
/* SOURCE y4_to_43.cmn:5 */
/*<       common/y4_to_43/g,m4,qsqr,zb43,zb3,costheta,tab43,tabexit >*/
/* INCLUDE ufgculv.for:582 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/*     Functions */
/* SOURCE ufgculv.for:586 */
/*<       realfind_y43_from_y4_resid >*/
/* SOURCE ufgculv.for:587 */
/*<       externalfind_y43_from_y4_resid >*/
/*     Local */
/* SOURCE ufgculv.for:591 */
/*<       realyl,fl,yr,fr >*/
/* *********************************************************************** */
/* SOURCE ufgculv.for:595 */
/*<       flag=0 >*/
    *feq_gen_flag_d_ = 0;
/* SOURCE ufgculv.for:596 */
/*<       qsqr=q2 >*/
    feq_gen_y4_to_43_d_1.qsqr = *q2;
/* SOURCE ufgculv.for:597 */
/*<       g=grav >*/
    feq_gen_y4_to_43_d_1.g = *grav;
/* SOURCE ufgculv.for:598 */
/*<       m4=b4*qsqr/a4+g*j4 >*/
    feq_gen_y4_to_43_d_1.m4 = static_cast<double>(static_cast<double>(static_cast<double>(*b4) * feq_gen_y4_to_43_d_1.qsqr) / *a4) + static_cast<double>(feq_gen_y4_to_43_d_1.g) * *j4;
/* SOURCE ufgculv.for:600 */
/*<       tab43=deptab >*/
    feq_gen_y4_to_43_d_1.tab43 = *deptab;
/* SOURCE ufgculv.for:601 */
/*<       tabexit=exittab >*/
    feq_gen_y4_to_43_d_1.tabexit = *exittab;
/* SOURCE ufgculv.for:602 */
/*<       zb43=z4b >*/
    feq_gen_y4_to_43_d_1.zb43 = *z4b;
/* SOURCE ufgculv.for:603 */
/*<       zb3=z3b >*/
    feq_gen_y4_to_43_d_1.zb3 = *z3b;
/* SOURCE ufgculv.for:604 */
/*<       costheta=cos_theta >*/
    feq_gen_y4_to_43_d_1.costheta = *feq_gen_cos_theta_d_;
/*     Search for a change in sign of the residual. */
/* SOURCE ufgculv.for:608 */
/*<       yl=y4 >*/
    yl = *y4;
/* SOURCE ufgculv.for:609 */
/*<       yr=-1.d0 >*/
    yr = (float)-1.;
/* SOURCE ufgculv.for:611 */
/*<   100 continue >*/
L100:
/* SOURCE ufgculv.for:612 */
/*<       fl=find_y43_from_y4_resid(yl) >*/
    fl = feq_gen_find_y43_from_y4_resid_d_(&yl);
/*        WRITE(STDOUT,*) ' YL=',YL,' FL=',FL */
/* SOURCE ufgculv.for:614 */
/*<       if(fl.le.0.0d0)then >*/
    if (fl <= 0.) {
/* SOURCE ufgculv.for:615 */
/*<       goto110 >*/
	goto L110;
/* SOURCE ufgculv.for:616 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:617 */
/*<       yr=yl >*/
	yr = yl;
/* SOURCE ufgculv.for:618 */
/*<       fr=fl >*/
	fr = fl;
/* SOURCE ufgculv.for:619 */
/*<       yl=0.98*yl >*/
	yl *= static_cast<double>((float).98);
/* SOURCE ufgculv.for:620 */
/*<       if(yl.lt.0.01)then >*/
	if (yl < (float).01) {
/* SOURCE ufgculv.for:621 */
/*<       write(stdout,*)' NO NEG RESIDUAL' >*/
	    feq_gen_io_d__75.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__75);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NO NEG RESIDUAL"), (ftnlen)16);
	    e_wsle();
/* SOURCE ufgculv.for:622 */
/*<       y3=0.d0 >*/
	    *y3 = (float)0.;
/* SOURCE ufgculv.for:623 */
/*<       flag=4 >*/
	    *feq_gen_flag_d_ = 4;
/* SOURCE ufgculv.for:624 */
/*<       return >*/
	    return 0;
/* SOURCE ufgculv.for:625 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:626 */
/*<       goto100 >*/
	goto L100;
/* SOURCE ufgculv.for:627 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:628 */
/*<   110 continue >*/
L110:
/* SOURCE ufgculv.for:629 */
/*<       if(yr.lt.0.0)then >*/
    if (yr < (float)0.) {
/* SOURCE ufgculv.for:630 */
/*<       if(abs(fl).le.epsf)then >*/
	if (dabs(fl) <= epscom_1.epsf) {
/* SOURCE ufgculv.for:631 */
/*<       y3=yl >*/
	    *y3 = yl;
/* SOURCE ufgculv.for:632 */
/*<       return >*/
	    return 0;
/* SOURCE ufgculv.for:633 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:634 */
/*<       write(stdout,*)'Problem in FIND_Y43_FROM_Y4' >*/
	feq_gen_io_d__76.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__76);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("Problem in FIND_Y43_FROM_Y4"), (ftnlen)27);
	e_wsle();
/* SOURCE ufgculv.for:635 */
/*<       write(stdout,*)'No positive residual found' >*/
	feq_gen_io_d__77.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__77);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("No positive residual found"), (ftnlen)26);
	e_wsle();
/* SOURCE ufgculv.for:636 */
/*<       write(stdout,*)' YL=',yl,' FL=',fl >*/
	feq_gen_io_d__78.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__78);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" YL="), (ftnlen)4);
	do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&yl, (ftnlen)sizeof(real));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FL="), (ftnlen)4);
	do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&fl, (ftnlen)sizeof(real));
	e_wsle();
/* SOURCE ufgculv.for:637 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE ufgculv.for:638 */
/*<       endif >*/
    }
/*     Found an interval that contains a root. */
/*      WRITE(STDOUT,*) ' Calling REGFLT with: YL=',YL,' FL=',FL */
/*      WRITE(STDOUT,*) ' YR=',YR,' FR=',FR */
/* SOURCE ufgculv.for:644 */
/*<       callregflt(epsarg,epsf,find_y43_from_y4_resid,yl,yr,fl,fr,y3,flag) >*/
    regflt_(&epscom_1.epsarg, &epscom_1.epsf, feq_gen_find_y43_from_y4_resid_d_, 
	    &yl, &yr, &fl, &fr, y3, feq_gen_flag_d_);
/*      WRITE(STDOUT,*) ' FL=',FL */
/*      WRITE(STDOUT,*) ' Return from REGFLT with: FLAG=',FLAG */
/*      WRITE(STDOUT,*) ' Y3 =',Y3 */
/* SOURCE ufgculv.for:653 */
/*<       if(flag.eq.3)flag=0 >*/
    if (*feq_gen_flag_d_ == 3) {
	*feq_gen_flag_d_ = 0;
    }
/* SOURCE ufgculv.for:655 */
/*<       return >*/
    return 0;
/* SOURCE ufgculv.for:656 */
/*<       end >*/
} /* find_y43_from_y4__ */




/* SOURCE ufgculv.for:664 */
/*<       real*8functionfind_y4sw_resid(y4sw) >*/
doublereal feq_gen_find_y4sw_resid_d_(doublereal *y4sw)
{
    /* System generated locals */
    doublereal ret_val;

    /* Local variables */
    real y2, z4, dqed;
    integer free;
    real dqeu;
    extern /* Subroutine */ int tdlk13_(integer *, integer *, integer *, 
	    integer *, real *, real *, real *, real *, real *, real *, real *,
	     integer *);

/*     Residual function for finding the level at section 4 that */
/*     causes submerged weir flow to contact the gate lip. */
/* SOURCE ufgculv.for:670 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:672 */
/*<       real*8y4sw >*/
/* INCLUDE ufgculv.for:674 */
/*     Common block for finding submerged weir flow contact */
/*     with gate lip in UFGCULV */
/* SOURCE y4sw.cmn:4 */
/*<       integerstd6,gety2 >*/
/* SOURCE y4sw.cmn:5 */
/*<       realhdatum,z4b,z1 >*/
/* SOURCE y4sw.cmn:6 */
/*<       real*8hg >*/
/* SOURCE y4sw.cmn:8 */
/*<       common/y4swc/hg,std6,gety2,hdatum,z4b,z1 >*/
/*     Local */
/* SOURCE ufgculv.for:678 */
/*<       integerfree >*/
/* SOURCE ufgculv.for:680 */
/*<       realz4,y2,dqed,dqeu >*/
/* *********************************************************************** */
/* SOURCE ufgculv.for:684 */
/*<       z4=y4sw+z4b >*/
    z4 = *y4sw + y4swc_1.z4b;
/*      WRITE(STD6,*) ' Z4=',Z4,' Z1=',Z1 */
/*      WRITE(STD6,*) ' GETY2=',GETY2 */
/* SOURCE ufgculv.for:688 */
/*<       calltdlk13(std6,gety2,13,0,0.0,z4,z1,hdatum,y2,dqed,dqeu,free) >*/
    tdlk13_(&y4swc_1.std6, &y4swc_1.gety2, &feq_gen_c_d_13, &feq_gen_c_d_0, &c_b72, &z4, &
	    y4swc_1.z1, &y4swc_1.hdatum, &y2, &dqed, &dqeu, &free);
/* SOURCE ufgculv.for:693 */
/*<       find_y4sw_resid=(hg-y2)/hg >*/
    ret_val = (y4swc_1.hg - y2) / y4swc_1.hg;
/* SOURCE ufgculv.for:694 */
/*<       return >*/
    return ret_val;
/* SOURCE ufgculv.for:695 */
/*<       end >*/
} /* find_y4sw_resid__ */




/* SOURCE ufgculv.for:700 */
/*<        >*/
/* Subroutine */ int feq_gen_find_y4sw_d_(integer *stdout, real *zup, real *zb2, real *
	zb4, integer *taby2, doublereal *feq_gen_hg_d_d_, doublereal *epsarg, 
	doublereal *epsf, doublereal *y4sw)
{
    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();

    /* Local variables */
    doublereal fl, fr, yl, yr;
    integer feq_gen_flag_d_;
    extern /* Subroutine */ int fdblrgf_(doublereal *, doublereal *, FeqCallback1, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *);
    extern doublereal feq_gen_find_y4sw_resid_d_(doublereal *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__88 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__90 = { 0, 0, 0, 0, 0 };


/*     Find the level at section 4 that causes submerged weir flow */
/*     to contact the gate lip. */
/* SOURCE ufgculv.for:708 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:710 */
/*<       integerstdout,taby2 >*/
/* SOURCE ufgculv.for:712 */
/*<       realzup,zb2,zb4 >*/
/* SOURCE ufgculv.for:713 */
/*<       real*8y4sw,epsarg,epsf >*/
/* INCLUDE ufgculv.for:715 */
/*     Common block for finding submerged weir flow contact */
/*     with gate lip in UFGCULV */
/* SOURCE y4sw.cmn:4 */
/*<       integerstd6,gety2 >*/
/* SOURCE y4sw.cmn:5 */
/*<       realhdatum,z4b,z1 >*/
/* SOURCE y4sw.cmn:6 */
/*<       real*8hg >*/
/* SOURCE y4sw.cmn:8 */
/*<       common/y4swc/hg,std6,gety2,hdatum,z4b,z1 >*/
/* SOURCE ufgculv.for:717 */
/*<       real*8hg_d >*/
/*     Functions */
/* SOURCE ufgculv.for:720 */
/*<       real*8find_y4sw_resid >*/
/* SOURCE ufgculv.for:721 */
/*<       externalfind_y4sw_resid >*/
/*     Local */
/* SOURCE ufgculv.for:725 */
/*<       integerflag >*/
/* SOURCE ufgculv.for:727 */
/*<       real*8yl,fl,yr,fr >*/
/* *********************************************************************** */
/*     Set the common block values for the residual function */
/* SOURCE ufgculv.for:732 */
/*<       hg=hg_d >*/
    y4swc_1.hg = *feq_gen_hg_d_d_;
/* SOURCE ufgculv.for:733 */
/*<       std6=stdout >*/
    y4swc_1.std6 = *stdout;
/* SOURCE ufgculv.for:734 */
/*<       gety2=taby2 >*/
    y4swc_1.gety2 = *taby2;
/* SOURCE ufgculv.for:735 */
/*<       hdatum=zb2 >*/
    y4swc_1.hdatum = *zb2;
/* SOURCE ufgculv.for:736 */
/*<       z4b=zb4 >*/
    y4swc_1.z4b = *zb4;
/* SOURCE ufgculv.for:737 */
/*<       z1=zup >*/
    y4swc_1.z1 = *zup;
/*     The elevation at section 4 will lie between ZUP and */
/*     and an unknown increment above Z4B.  Start at the upper */
/*     elevation and  search for a positive residual. */
/* SOURCE ufgculv.for:743 */
/*<       yl=zup-z4b >*/
    yl = static_cast<double>(*zup) - y4swc_1.z4b;
/* SOURCE ufgculv.for:744 */
/*<       yr=-1.d0 >*/
    yr = -1.;
/* SOURCE ufgculv.for:746 */
/*<   100 continue >*/
L100:
/* SOURCE ufgculv.for:747 */
/*<       fl=find_y4sw_resid(yl) >*/
    fl = feq_gen_find_y4sw_resid_d_(&yl);
/*        WRITE(STDOUT,*) ' YL=',YL,' FL=',FL */
/* SOURCE ufgculv.for:749 */
/*<       if(fl.le.0.0d0)then >*/
    if (fl <= 0.) {
/* SOURCE ufgculv.for:750 */
/*<       goto110 >*/
	goto L110;
/* SOURCE ufgculv.for:751 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:752 */
/*<       yr=yl >*/
	yr = yl;
/* SOURCE ufgculv.for:753 */
/*<       fr=fl >*/
	fr = fl;
/* SOURCE ufgculv.for:754 */
/*<       yl=0.9d0*yl >*/
	yl *= .9;
/* SOURCE ufgculv.for:755 */
/*<       if(yl.lt.0.01)then >*/
	if (yl < (float).01) {
/* SOURCE ufgculv.for:756 */
/*<       write(stdout,*)' NO NEG RESIDUAL' >*/
	    feq_gen_io_d__88.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__88);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NO NEG RESIDUAL"), (ftnlen)16);
	    e_wsle();
/* SOURCE ufgculv.for:757 */
/*<       y4sw=0.d0 >*/
	    *y4sw = 0.;
/* SOURCE ufgculv.for:758 */
/*<       flag=4 >*/
	    feq_gen_flag_d_ = 4;
/* SOURCE ufgculv.for:759 */
/*<       return >*/
	    return 0;
/* SOURCE ufgculv.for:760 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:761 */
/*<       goto100 >*/
	goto L100;
/* SOURCE ufgculv.for:762 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:763 */
/*<   110 continue >*/
L110:
/*     Negative residual found; search for positive residual. */
/* SOURCE ufgculv.for:766 */
/*<       if(yr.lt.0.0d0)then >*/
    if (yr < 0.) {
/* SOURCE ufgculv.for:767 */
/*<       yr=yl >*/
	yr = yl;
/* SOURCE ufgculv.for:768 */
/*<   120 continue >*/
L120:
/* SOURCE ufgculv.for:769 */
/*<       yr=0.9d0*yr >*/
	yr *= .9;
/* SOURCE ufgculv.for:770 */
/*<       if(yr.lt.0.01)then >*/
	if (yr < (float).01) {
/* SOURCE ufgculv.for:771 */
/*<       write(stdout,*)' NO POS RESIDUAL' >*/
	    feq_gen_io_d__90.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__90);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NO POS RESIDUAL"), (ftnlen)16);
	    e_wsle();
/* SOURCE ufgculv.for:772 */
/*<       flag=4 >*/
	    feq_gen_flag_d_ = 4;
/* SOURCE ufgculv.for:773 */
/*<       y4sw=0.d0 >*/
	    *y4sw = 0.;
/* SOURCE ufgculv.for:774 */
/*<       return >*/
	    return 0;
/* SOURCE ufgculv.for:775 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:776 */
/*<       fr=find_y4sw_resid(yr) >*/
	fr = feq_gen_find_y4sw_resid_d_(&yr);
/*        WRITE(STDOUT,*) ' YR=',YR,' FR=',FR */
/* SOURCE ufgculv.for:778 */
/*<       if(fr.ge.0.0d0)then >*/
	if (fr >= 0.) {
/* SOURCE ufgculv.for:779 */
/*<       goto130 >*/
	    goto L130;
/* SOURCE ufgculv.for:780 */
/*<       else >*/
	} else {
/* SOURCE ufgculv.for:781 */
/*<       fl=fr >*/
	    fl = fr;
/* SOURCE ufgculv.for:782 */
/*<       yl=yr >*/
	    yl = yr;
/* SOURCE ufgculv.for:783 */
/*<       goto120 >*/
	    goto L120;
/* SOURCE ufgculv.for:784 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:785 */
/*<   130 continue >*/
L130:
/* SOURCE ufgculv.for:786 */
/*<       endif >*/
	;
    }
/*     Found an interval that contains a root. */
/*      WRITE(STDOUT,*) ' Calling FDBLRGF with: YL=',YL,' FL=',FL */
/*      WRITE(STDOUT,*) ' YR=',YR,' FR=',FR */
/* SOURCE ufgculv.for:792 */
/*<       callfdblrgf(epsarg,epsf,find_y4sw_resid,yl,yr,fl,fr,y4sw,flag) >*/
    fdblrgf_(epsarg, epsf, feq_gen_find_y4sw_resid_d_, &yl, &yr, &fl, &fr, y4sw, 
	    &feq_gen_flag_d_);
/*      WRITE(STDOUT,*) ' FL=',FL */
/*      WRITE(STDOUT,*) ' Return from FDBLRGF with: FLAG=',FLAG */
/*      WRITE(STDOUT,*) ' Y4SW =',Y4SW, ' KNT=',INT(FR) */
/* SOURCE ufgculv.for:801 */
/*<       if(flag.eq.3)flag=0 >*/
    if (feq_gen_flag_d_ == 3) {
	feq_gen_flag_d_ = 0;
    }
/* SOURCE ufgculv.for:803 */
/*<       return >*/
    return 0;
/* SOURCE ufgculv.for:804 */
/*<       end >*/
} /* find_y4sw__ */




/* SOURCE ufgculv.for:808 */
/*<       subroutineprofile_ups(ycrit,ynorm,yvc,cc,flag) >*/
/* Subroutine */ int feq_gen_profile_ups_d_(doublereal *ycrit, doublereal *ynorm, 
	doublereal *yvc, doublereal *cc, integer *feq_gen_flag_d_)
{
    /* System generated locals */
    real feq_gen_r_d_1;
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    doublereal feq_gen_yc_ratio_d_;
    extern doublereal e_(doublereal*, doublereal*);
    doublereal p, ab, jb;
    integer ne;
    doublereal fr, ml, xe, mr;
    integer ns;
    doublereal xs, ys, ajc, jvc;
    extern /* Subroutine */ int feq_gen_find_ycynym_d_(integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *);
    doublereal abfb, jbfb, abfs;
    integer ntab;
    doublereal jbfs;
    extern doublereal rhse_(doublereal*, doublereal*);
    integer full;
    doublereal ybfs;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    real deriv;
    extern /* Subroutine */ int sfwsp_(integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, FeqCallback2, FeqCallback2, FeqCallback4, integer *, integer *
	    , integer *, doublereal *, doublereal *, doublereal *, doublereal 
	    *, integer *);
    real yoverd;
    extern /* Subroutine */ int feq_gen_lkt_jda_d_(integer *, doublereal *, doublereal 
	    *, doublereal *, doublereal *);

/*     Compute a profile upstream using either full flow */
/*     or part full flow */
/* SOURCE ufgculv.for:815 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:817 */
/*<       integerflag >*/
/* SOURCE ufgculv.for:819 */
/*<       real*8ycrit,ynorm,yvc,cc >*/
/* INCLUDE ufgculv.for:821 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/* INCLUDE ufgculv.for:822 */
/*     Common block for double precision functions involved in UFGCULV. */
/* SOURCE ufgate_d.cmn:4 */
/*<        >*/
/* SOURCE ufgate_d.cmn:6 */
/*<       parameter(nmax=2000) >*/
/* SOURCE ufgate_d.cmn:8 */
/*<        >*/
/* SOURCE ufgate_d.cmn:16 */
/*<       real*8xvec(nmax),yvec(nmax),ycvec(nmax),ynvec(nmax) >*/
/* SOURCE ufgate_d.cmn:18 */
/*<        >*/
/*     Local variables */
/* SOURCE ufgculv.for:826 */
/*<       integerns,ne,ntab,full >*/
/* SOURCE ufgculv.for:828 */
/*<       realyoverd,deriv >*/
/* SOURCE ufgculv.for:830 */
/*<        >*/
/*     Called functions */
/* SOURCE ufgculv.for:837 */
/*<       real*8e,rhse >*/
/* SOURCE ufgculv.for:839 */
/*<       externale,rhse,find_ycynym,get_ycynym,lkt_jda >*/
/* *********************************************************************** */
/* SOURCE ufgculv.for:844 */
/*<       xs=station(nxs) >*/
    xs = ufgc1_1.station[ufgc1_1.nxs - 1];
/* SOURCE ufgculv.for:845 */
/*<       xe=station(1)+hg_d >*/
    xe = ufgc1_1.station[0] + ufgated_1.feq_gen_hg_d_d_;
/*     Check on the relative depth to decide if we need to compute */
/*     a free-surface profile or we can use the full pipe approximation. */
/* SOURCE ufgculv.for:851 */
/*<       yc_ratio=ycrit/vert_d >*/
    feq_gen_yc_ratio_d_ = *ycrit / ufgc1_1.feq_gen_vert_d_d_;
/* SOURCE ufgculv.for:852 */
/*<       if(yc_ratio.lt.fb_ratio)then >*/
    if (feq_gen_yc_ratio_d_ < ufgated_1.feq_gen_fb_ratio_d_) {
/* SOURCE ufgculv.for:853 */
/*<       full=0 >*/
	full = 0;
/* SOURCE ufgculv.for:854 */
/*<       elseif(yc_ratio.lt.fs_ratio)then >*/
    } else if (feq_gen_yc_ratio_d_ < ufgated_1.feq_gen_fs_ratio_d_) {
/* SOURCE ufgculv.for:855 */
/*<       full=1 >*/
	full = 1;
/* SOURCE ufgculv.for:856 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:857 */
/*<       full=2 >*/
	full = 2;
/* SOURCE ufgculv.for:858 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:860 */
/*<       if(full.ge.1)then >*/
    if (full >= 1) {
/*       We compute the flow with the pipe flowing full and with */
/*       pieozometric level at the exit a function of the flow. */
/* SOURCE ufgculv.for:864 */
/*<       fr=qd/(afull_d*sqrt(grav_d*vert_d)) >*/
	fr = ufgc1_1.qd / (ufgated_1.feq_gen_afull_d_d_ * sqrt(ufgated_1.feq_gen_grav_d_d_ * 
		ufgc1_1.feq_gen_vert_d_d_));
/* SOURCE ufgculv.for:865 */
/*<       calllktab(adrs_yoverd,sngl(fr),0,yoverd,ntab,deriv) >*/
	feq_gen_r_d_1 = (real) fr;
	lktab_(&ufgated_1.feq_gen_adrs_yoverd_d_, &feq_gen_r_d_1, &feq_gen_c_d_0, &yoverd, &ntab, &deriv)
		;
/* SOURCE ufgculv.for:868 */
/*<       ys=yoverd*vert_d >*/
	ys = yoverd * ufgc1_1.feq_gen_vert_d_d_;
/*        YBFB =  (ZBEX_D + COS_THETA*YS + (XS - XE)* */
/*     A                            (QD/KFULL_D)**2 - ZBVC_D)/COS_THETA */
/* SOURCE ufgculv.for:871 */
/*<       abfb=afull_d >*/
	abfb = ufgated_1.feq_gen_afull_d_d_;
/* SOURCE ufgculv.for:872 */
/*<       jbfb=jfull_d >*/
	jbfb = ufgated_1.feq_gen_jfull_d_d_;
/* SOURCE ufgculv.for:873 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:874 */
/*<       if(full.le.1)then >*/
    if (full <= 1) {
/*       Compute water-surface profile to vena contracta starting at critical */
/*       depth. */
/* SOURCE ufgculv.for:877 */
/*<       ys=ycrit*1.001d0 >*/
	ys = *ycrit * 1.001;
/* SOURCE ufgculv.for:878 */
/*<        >*/
	sfwsp_(&ufgated_1.feq_gen_stdout_d_d_, &xs, &xe, &ys, &ufgated_1.feq_gen_eps_d_d_, e_, rhse_, feq_gen_find_ycynym_d_, &feq_gen_c_d_2000, &ns, &ne,
		 ufgated_1.xvec, ufgated_1.yvec, ufgated_1.ycvec, 
		ufgated_1.ynvec, &ufgated_1.feq_gen_rflag_d_d_);
/* SOURCE ufgculv.for:882 */
/*<       ns_return=ns >*/
	ufgated_1.feq_gen_ns_return_d_ = ns;
/* SOURCE ufgculv.for:883 */
/*<       ne_return=ne >*/
	ufgated_1.feq_gen_ne_return_d_ = ne;
/* SOURCE ufgculv.for:884 */
/*<       xe_return=xe >*/
	ufgated_1.feq_gen_xe_return_d_ = xe;
/* SOURCE ufgculv.for:886 */
/*<       ybfs=yvec(ns) >*/
	ybfs = ufgated_1.yvec[ns - 1];
/* SOURCE ufgculv.for:887 */
/*<       calllkt_jda(0,xe,ybfs,abfs,jbfs) >*/
	feq_gen_lkt_jda_d_(&feq_gen_c_d_0, &xe, &ybfs, &abfs, &jbfs);
/* SOURCE ufgculv.for:890 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:892 */
/*<       if(full.eq.0)then >*/
    if (full == 0) {
/*        YB = YBFS */
/* SOURCE ufgculv.for:894 */
/*<       ab=abfs >*/
	ab = abfs;
/* SOURCE ufgculv.for:895 */
/*<       jb=jbfs >*/
	jb = jbfs;
/* SOURCE ufgculv.for:896 */
/*<       elseif(full.eq.1)then >*/
    } else if (full == 1) {
/* SOURCE ufgculv.for:897 */
/*<       p=(yc_ratio-fb_ratio)/(fs_ratio-fb_ratio) >*/
	p = (feq_gen_yc_ratio_d_ - ufgated_1.feq_gen_fb_ratio_d_) / (ufgated_1.feq_gen_fs_ratio_d_ - 
		ufgated_1.feq_gen_fb_ratio_d_);
/*        YB = YBFS + P*(YBFB - YBFS) */
/* SOURCE ufgculv.for:899 */
/*<       ab=abfs+p*(abfb-abfs) >*/
	ab = abfs + p * (abfb - abfs);
/* SOURCE ufgculv.for:900 */
/*<       jb=jbfs+p*(jbfb-jbfs) >*/
	jb = jbfs + p * (jbfb - jbfs);
/* SOURCE ufgculv.for:901 */
/*<       else >*/
    } else {
/*        YB = YBFB */
/* SOURCE ufgculv.for:903 */
/*<       ab=abfb >*/
	ab = abfb;
/* SOURCE ufgculv.for:904 */
/*<       jb=jbfb >*/
	jb = jbfb;
/* SOURCE ufgculv.for:905 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:906 */
/*<       yc_return=ys >*/
    ufgated_1.feq_gen_yc_return_d_ = ys;
/* SOURCE ufgculv.for:907 */
/*<       full_return=full >*/
    ufgated_1.feq_gen_full_return_d_ = full;
/* SOURCE ufgculv.for:908 */
/*<       calllkt_jda(0,xe,yvc,ajc,jvc) >*/
    feq_gen_lkt_jda_d_(&feq_gen_c_d_0, &xe, yvc, &ajc, &jvc);
/*     Compute residual in the momentum balance. */
/* SOURCE ufgculv.for:914 */
/*<       ml=qd**2/(hg_d*bg_d*cc)+grav_d*jvc >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = ufgc1_1.qd;
    ml = feq_gen_d_d_1 * feq_gen_d_d_1 / (ufgated_1.feq_gen_hg_d_d_ * ufgated_1.feq_gen_bg_d_d_ * *cc) + 
	    ufgated_1.feq_gen_grav_d_d_ * jvc;
/* SOURCE ufgculv.for:915 */
/*<       mr=qd**2/ab+grav_d*jb >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = ufgc1_1.qd;
    mr = feq_gen_d_d_1 * feq_gen_d_d_1 / ab + ufgated_1.feq_gen_grav_d_d_ * jb;
/* SOURCE ufgculv.for:916 */
/*<       if(ml.ge.mr)then >*/
    if (ml >= mr) {
/*       Vena contracta is not drowned */
/* SOURCE ufgculv.for:918 */
/*<       flag=1 >*/
	*feq_gen_flag_d_ = 1;
/* SOURCE ufgculv.for:919 */
/*<       else >*/
    } else {
/*       Vena contracta is drowned. */
/* SOURCE ufgculv.for:921 */
/*<       flag=0 >*/
	*feq_gen_flag_d_ = 0;
/* SOURCE ufgculv.for:922 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:923 */
/*<       return >*/
    return 0;
/* SOURCE ufgculv.for:924 */
/*<       end >*/
} /* profile_ups__ */




/* SOURCE ufgculv.for:928 */
/*<       real*8functionfind_fb_ycrit_resid(yc) >*/
doublereal feq_gen_find_fb_ycrit_resid_d_(doublereal *yc)
{
    /* System generated locals */
    real feq_gen_r_d_1;
    doublereal ret_val, feq_gen_d_d_1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    doublereal fr, yb, ys, qcd;
    integer ntab;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    real deriv, yoverd;
    extern /* Subroutine */ int feq_gen_lkt_qcd_d_(integer *, doublereal *, doublereal 
	    *, doublereal *);

/*     Residual function for FIND_FB_YCRIT */
/* SOURCE ufgculv.for:933 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:934 */
/*<       real*8yc >*/
/* INCLUDE ufgculv.for:936 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/* INCLUDE ufgculv.for:937 */
/*     Common block for double precision functions involved in UFGCULV. */
/* SOURCE ufgate_d.cmn:4 */
/*<        >*/
/* SOURCE ufgate_d.cmn:6 */
/*<       parameter(nmax=2000) >*/
/* SOURCE ufgate_d.cmn:8 */
/*<        >*/
/* SOURCE ufgate_d.cmn:16 */
/*<       real*8xvec(nmax),yvec(nmax),ycvec(nmax),ynvec(nmax) >*/
/* SOURCE ufgate_d.cmn:18 */
/*<        >*/
/*     Local */
/* SOURCE ufgculv.for:941 */
/*<       integerntab >*/
/* SOURCE ufgculv.for:942 */
/*<       realyoverd,deriv >*/
/* SOURCE ufgculv.for:943 */
/*<       real*8qcd,fr,ys,yb >*/
/* *********************************************************************** */
/* SOURCE ufgculv.for:948 */
/*<       calllkt_qcd(1,xs_d,yc,qcd) >*/
    feq_gen_lkt_qcd_d_(&feq_gen_c_d_1, &ufgated_1.feq_gen_xs_d_d_, yc, &qcd);
/* SOURCE ufgculv.for:952 */
/*<       fr=qcd/(afull_d*sqrt(grav_d*vert_d)) >*/
    fr = qcd / (ufgated_1.feq_gen_afull_d_d_ * sqrt(ufgated_1.feq_gen_grav_d_d_ * 
	    ufgc1_1.feq_gen_vert_d_d_));
/* SOURCE ufgculv.for:954 */
/*<       if(fr.gt.55.d0)fr=55.d0 >*/
    if (fr > 55.) {
	fr = 55.;
    }
/* SOURCE ufgculv.for:955 */
/*<       calllktab(adrs_yoverd,sngl(fr),0,yoverd,ntab,deriv) >*/
    feq_gen_r_d_1 = (real) fr;
    lktab_(&ufgated_1.feq_gen_adrs_yoverd_d_, &feq_gen_r_d_1, &feq_gen_c_d_0, &yoverd, &ntab, &deriv);
/*      WRITE(STDOUT_D,*) ' FR=',SNGL(FR),' YOVERD=',YOVERD */
/*      WRITE(STDOUT_D,*) ' VERT_D=',VERT_D */
/*      WRITE(STDOUT_D,*) ' ZBEX_D=',ZBEX_D,' ZBVC_D=',ZBVC_D */
/*      WRITE(STDOUT_D,*) ' XS_D=',XS_D,' XE_D=',XE_D */
/*      WRITE(STDOUT_D,*) ' QCD=',QCD */
/*      WRITE(STDOUT_D,*) ' KFULL_D=',KFULL_D */
/* SOURCE ufgculv.for:964 */
/*<       ys=yoverd*vert_d >*/
    ys = yoverd * ufgc1_1.feq_gen_vert_d_d_;
/* SOURCE ufgculv.for:965 */
/*<        >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = qcd / ufgated_1.feq_gen_kfull_d_d_;
    yb = (ufgated_1.feq_gen_zbex_d_d_ + ufgc1_1.feq_gen_cos_theta_d_ * ys + (ufgated_1.feq_gen_xs_d_d_ - 
	    ufgated_1.feq_gen_xe_d_d_) * (feq_gen_d_d_1 * feq_gen_d_d_1) - ufgated_1.feq_gen_zbvc_d_d_) / 
	    ufgc1_1.feq_gen_cos_theta_d_;
/*      WRITE(STDOUT_D,*) ' YS=',YS,' YB=',YB */
/* SOURCE ufgculv.for:969 */
/*<       find_fb_ycrit_resid=(yb-vert_d)/vert_d >*/
    ret_val = (yb - ufgc1_1.feq_gen_vert_d_d_) / ufgc1_1.feq_gen_vert_d_d_;
/*      WRITE(STDOUT_D,*) ' RESID=',FIND_FB_YCRIT_RESID */
/*      WRITE(STDOUT_D,*) ' ' */
/* SOURCE ufgculv.for:973 */
/*<       return >*/
    return ret_val;
/* SOURCE ufgculv.for:974 */
/*<       end >*/
} /* find_fb_ycrit_resid__ */




/* SOURCE ufgculv.for:979 */
/*<       subroutinefind_fb_ycrit(stdout,root) >*/
/* Subroutine */ int feq_gen_find_fb_ycrit_d_(integer *stdout, doublereal *root)
{
    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    doublereal fl, fr, yl, yr;
    extern doublereal feq_gen_find_fb_ycrit_resid_d_(doublereal *);
    integer feq_gen_flag_d_;
    doublereal ratio;
    extern /* Subroutine */ int fdblrgf_(doublereal *, doublereal *, FeqCallback1, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__123 = { 0, 0, 0, 0, 0 };


/*     Find the critical depth  ratio that will cause the barrel to */
/*     flow flow with certainty. */
/* SOURCE ufgculv.for:986 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:987 */
/*<       integerstdout >*/
/* SOURCE ufgculv.for:988 */
/*<       real*8root >*/
/* INCLUDE ufgculv.for:990 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/* INCLUDE ufgculv.for:991 */
/*     Common block for double precision functions involved in UFGCULV. */
/* SOURCE ufgate_d.cmn:4 */
/*<        >*/
/* SOURCE ufgate_d.cmn:6 */
/*<       parameter(nmax=2000) >*/
/* SOURCE ufgate_d.cmn:8 */
/*<        >*/
/* SOURCE ufgate_d.cmn:16 */
/*<       real*8xvec(nmax),yvec(nmax),ycvec(nmax),ynvec(nmax) >*/
/* SOURCE ufgate_d.cmn:18 */
/*<        >*/
/*     Local */
/* SOURCE ufgculv.for:995 */
/*<       integerflag >*/
/* SOURCE ufgculv.for:996 */
/*<       real*8yl,fl,yr,fr,ratio >*/
/*     Functions */
/* SOURCE ufgculv.for:1000 */
/*<       real*8find_fb_ycrit_resid >*/
/* SOURCE ufgculv.for:1002 */
/*<       externalfind_fb_ycrit_resid >*/
/* *********************************************************************** */
/* SOURCE ufgculv.for:1007 */
/*<       xs_d=station(nxs) >*/
    ufgated_1.feq_gen_xs_d_d_ = ufgc1_1.station[ufgc1_1.nxs - 1];
/* SOURCE ufgculv.for:1008 */
/*<       xe_d=station(1)+hg_d >*/
    ufgated_1.feq_gen_xe_d_d_ = ufgc1_1.station[0] + ufgated_1.feq_gen_hg_d_d_;
/*     Find an interval with a sign change. The critical flow at VERT_D */
/*     must cause a positive residual.  Otherwise there may be no */
/*     solution */
/* SOURCE ufgculv.for:1015 */
/*<       yr=vert_d >*/
    yr = ufgc1_1.feq_gen_vert_d_d_;
/* SOURCE ufgculv.for:1016 */
/*<       fr=find_fb_ycrit_resid(yr) >*/
    fr = feq_gen_find_fb_ycrit_resid_d_(&yr);
/* SOURCE ufgculv.for:1017 */
/*<       if(fr.lt.0.d0)then >*/
    if (fr < 0.) {
/* SOURCE ufgculv.for:1018 */
/*<       write(stdout,*)' FIND_FB_YCRIT_RESID: No root. Max Qc too small.' >*/
	feq_gen_io_d__123.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__123);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FIND_FB_YCRIT_RESID: No root. Max Qc too smal\
l."), (ftnlen)48);
	e_wsle();
/* SOURCE ufgculv.for:1020 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE ufgculv.for:1021 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:1023 */
/*<       ratio=0.8d0 >*/
    ratio = .8;
/* SOURCE ufgculv.for:1024 */
/*<       yr=ratio*vert_d >*/
    yr = ratio * ufgc1_1.feq_gen_vert_d_d_;
/* SOURCE ufgculv.for:1025 */
/*<       yl=-1.d0 >*/
    yl = -1.;
/* SOURCE ufgculv.for:1026 */
/*<   100 continue >*/
L100:
/* SOURCE ufgculv.for:1027 */
/*<       fr=find_fb_ycrit_resid(yr) >*/
    fr = feq_gen_find_fb_ycrit_resid_d_(&yr);
/*        WRITE(STDOUT,*) ' YR=',YR,' FR=',FR */
/* SOURCE ufgculv.for:1029 */
/*<       if(fr.ge.0.0d0)then >*/
    if (fr >= 0.) {
/* SOURCE ufgculv.for:1030 */
/*<       goto110 >*/
	goto L110;
/* SOURCE ufgculv.for:1031 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:1032 */
/*<       yl=yr >*/
	yl = yr;
/* SOURCE ufgculv.for:1033 */
/*<       fl=fr >*/
	fl = fr;
/* SOURCE ufgculv.for:1034 */
/*<       ratio=0.5d0*(ratio+1.d0) >*/
	ratio = (ratio + 1.) * .5;
/* SOURCE ufgculv.for:1035 */
/*<       yr=ratio*vert_d >*/
	yr = ratio * ufgc1_1.feq_gen_vert_d_d_;
/* SOURCE ufgculv.for:1036 */
/*<       goto100 >*/
	goto L100;
/* SOURCE ufgculv.for:1037 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:1038 */
/*<   110 continue >*/
L110:
/*     POSITIVE RESIDUAL FOUND- SEARCH FOR NEGATIVE RESIDUAL */
/* SOURCE ufgculv.for:1041 */
/*<       if(yl.lt.0.0d0)then >*/
    if (yl < 0.) {
/* SOURCE ufgculv.for:1042 */
/*<   120 continue >*/
L120:
/* SOURCE ufgculv.for:1043 */
/*<       ratio=ratio-0.05d0 >*/
	ratio += -.05;
/* SOURCE ufgculv.for:1044 */
/*<       yl=ratio*vert_d >*/
	yl = ratio * ufgc1_1.feq_gen_vert_d_d_;
/* SOURCE ufgculv.for:1045 */
/*<       fl=find_fb_ycrit_resid(yl) >*/
	fl = feq_gen_find_fb_ycrit_resid_d_(&yl);
/*        WRITE(STDOUT,*) ' YL=',YL,' FL=',FL */
/* SOURCE ufgculv.for:1047 */
/*<       if(fl.le.0.0d0)then >*/
	if (fl <= 0.) {
/* SOURCE ufgculv.for:1048 */
/*<       goto130 >*/
	    goto L130;
/* SOURCE ufgculv.for:1049 */
/*<       else >*/
	} else {
/* SOURCE ufgculv.for:1050 */
/*<       fr=fl >*/
	    fr = fl;
/* SOURCE ufgculv.for:1051 */
/*<       yr=yl >*/
	    yr = yl;
/* SOURCE ufgculv.for:1052 */
/*<       goto120 >*/
	    goto L120;
/* SOURCE ufgculv.for:1053 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:1054 */
/*<   130 continue >*/
L130:
/* SOURCE ufgculv.for:1055 */
/*<       endif >*/
	;
    }
/*     Found an interval that contains a root. */
/*      WRITE(STDOUT,*) ' Calling FDBLRGF with: YL=',YL,' FL=',FL */
/*      WRITE(STDOUT,*) ' YR=',YR,' FR=',FR */
/* SOURCE ufgculv.for:1061 */
/*<        >*/
    fdblrgf_(&ufgated_1.feq_gen_epsarg_d_d_, &ufgated_1.feq_gen_epsf_d_d_, feq_gen_find_fb_ycrit_resid_d_, &yl, &yr, &fl, &fr, root, &feq_gen_flag_d_);
/*      WRITE(STDOUT,*) ' FL=',FL */
/*      WRITE(STDOUT,*) ' Return from FDBLRGF with: FLAG=',FLAG */
/*      WRITE(STDOUT,*) ' YC =',ROOT, ' KNT=',INT(FR) */
/* SOURCE ufgculv.for:1070 */
/*<       if(flag.eq.3)flag=0 >*/
    if (feq_gen_flag_d_ == 3) {
	feq_gen_flag_d_ = 0;
    }
/* SOURCE ufgculv.for:1071 */
/*<       root=root/vert_d >*/
    *root /= ufgc1_1.feq_gen_vert_d_d_;
/* SOURCE ufgculv.for:1072 */
/*<       return >*/
    return 0;
/* SOURCE ufgculv.for:1073 */
/*<       end >*/
} /* find_fb_ycrit__ */




/* SOURCE ufgculv.for:1077 */
/*<       subroutinebisect_d(stdout,epsx,epsf,f,yl,yr,fl,fr,root,flag) >*/
/* Subroutine */ int feq_gen_bisect_d_d_(integer *stdout, doublereal *epsx, doublereal 
	*epsf, FeqCallback1 f, doublereal *yl, doublereal *yr, doublereal *fl, 
	doublereal *fr, doublereal *root, integer *feq_gen_flag_d_)
{
    integer feq_gen_i_d_;
    doublereal fm, ym;

/*     Try bisection for a root. */
/* SOURCE ufgculv.for:1084 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:1085 */
/*<       integerflag,stdout >*/
/* SOURCE ufgculv.for:1087 */
/*<       real*8epsx,epsf,yl,yr,fl,fr,root >*/
/* INCLUDE ufgculv.for:1089 */
/*     Common block for double precision functions involved in UFGCULV. */
/* SOURCE ufgate_d.cmn:4 */
/*<        >*/
/* SOURCE ufgate_d.cmn:6 */
/*<       parameter(nmax=2000) >*/
/* SOURCE ufgate_d.cmn:8 */
/*<        >*/
/* SOURCE ufgate_d.cmn:16 */
/*<       real*8xvec(nmax),yvec(nmax),ycvec(nmax),ynvec(nmax) >*/
/* SOURCE ufgate_d.cmn:18 */
/*<        >*/
/* SOURCE ufgculv.for:1091 */
/*<       real*8f >*/
/* SOURCE ufgculv.for:1092 */
/*<       externalf >*/
/*     Local */
/* SOURCE ufgculv.for:1096 */
/*<       integeri >*/
/* SOURCE ufgculv.for:1098 */
/*<       real*8ym,fm >*/
/* *********************************************************************** */
/* SOURCE ufgculv.for:1100 */
/*<       flag=0 >*/
    *feq_gen_flag_d_ = 0;
/* SOURCE ufgculv.for:1101 */
/*<       i=50 >*/
    feq_gen_i_d_ = 50;
/* SOURCE ufgculv.for:1102 */
/*<   100 continue >*/
L100:
/* SOURCE ufgculv.for:1103 */
/*<       ym=0.5d0*(yl+yr) >*/
    ym = (*yl + *yr) * .5;
/* SOURCE ufgculv.for:1104 */
/*<       fm=f(ym) >*/
    fm = (*f)(&ym);
/*        WRITE(STDOUT,*) ' ' */
/*        WRITE(STDOUT,*) ' I=',I,' FULL=',FULL_RETURN */
/*        WRITE(STDOUT,*) ' YL=',YL,' YR=',YR */
/*        WRITE(STDOUT,*) ' FL=',FL,' FR=',FR */
/*        WRITE(STDOUT,*) ' YM=',YM,' FM=',FM */
/* SOURCE ufgculv.for:1110 */
/*<       if(fm.lt.0.d0)then >*/
    if (fm < 0.) {
/* SOURCE ufgculv.for:1111 */
/*<       if(fl.lt.0.d0)then >*/
	if (*fl < 0.) {
/* SOURCE ufgculv.for:1112 */
/*<       yl=ym >*/
	    *yl = ym;
/* SOURCE ufgculv.for:1113 */
/*<       fl=fm >*/
	    *fl = fm;
/* SOURCE ufgculv.for:1114 */
/*<       else >*/
	} else {
/* SOURCE ufgculv.for:1115 */
/*<       yr=ym >*/
	    *yr = ym;
/* SOURCE ufgculv.for:1116 */
/*<       fr=fm >*/
	    *fr = fm;
/* SOURCE ufgculv.for:1117 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:1118 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:1119 */
/*<       if(fl.lt.0.d0)then >*/
	if (*fl < 0.) {
/* SOURCE ufgculv.for:1120 */
/*<       yr=ym >*/
	    *yr = ym;
/* SOURCE ufgculv.for:1121 */
/*<       fr=fm >*/
	    *fr = fm;
/* SOURCE ufgculv.for:1122 */
/*<       else >*/
	} else {
/* SOURCE ufgculv.for:1123 */
/*<       yl=ym >*/
	    *yl = ym;
/* SOURCE ufgculv.for:1124 */
/*<       fl=fm >*/
	    *fl = fm;
/* SOURCE ufgculv.for:1125 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:1126 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:1127 */
/*<       if(abs(fm).lt.epsf)then >*/
    if (abs(fm) < *epsf) {
/* SOURCE ufgculv.for:1128 */
/*<       root=ym >*/
	*root = ym;
/* SOURCE ufgculv.for:1129 */
/*<       fl=fm >*/
	*fl = fm;
/* SOURCE ufgculv.for:1130 */
/*<       return >*/
	return 0;
/* SOURCE ufgculv.for:1131 */
/*<       endif >*/
    }
/*        IF(ABS(YR - YL)/(ABS(YL) + ABS(YR)).LT.EPSX) THEN */
/*          ROOT = YM */
/*          FL = FM */
/*          FLAG = 3 */
/*          RETURN */
/*        ENDIF */
/* SOURCE ufgculv.for:1139 */
/*<       i=i-1 >*/
    --feq_gen_i_d_;
/* SOURCE ufgculv.for:1140 */
/*<       if(i.eq.0)then >*/
    if (feq_gen_i_d_ == 0) {
/* SOURCE ufgculv.for:1141 */
/*<       flag=1 >*/
	*feq_gen_flag_d_ = 1;
/* SOURCE ufgculv.for:1142 */
/*<       root=ym >*/
	*root = ym;
/* SOURCE ufgculv.for:1143 */
/*<       fl=fm >*/
	*fl = fm;
/* SOURCE ufgculv.for:1144 */
/*<       return >*/
	return 0;
/* SOURCE ufgculv.for:1145 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:1146 */
/*<       goto100 >*/
    goto L100;
/* SOURCE ufgculv.for:1147 */
/*<       end >*/
} /* bisect_d__ */




/* SOURCE ufgculv.for:1151 */
/*<       subroutineconstruct_yoverd(stdout,ftpt,adrs_yoverd) >*/
/* Subroutine */ int feq_gen_construct_yoverd_d_(integer *stdout, integer *ftpt, 
	integer *feq_gen_adrs_yoverd_d_)
{
    /* Initialized data */

    static real arg[43] = { (float).040797,(float).44876,(float).67314,(float)
	    .89752,(float)1.1219,(float)1.3463,(float)1.5707,(float)1.795,(
	    float)2.0194,(float)2.2438,(float)2.4682,(float)2.6925,(float)
	    2.9169,(float)3.1413,(float)3.3657,(float)3.5901,(float)3.8144,(
	    float)4.0388,(float)4.2632,(float)4.4876,(float)4.712,(float)
	    4.9363,(float)5.1607,(float)5.3851,(float)5.6095,(float)5.8339,(
	    float)6.0582,(float)6.2826,(float)6.507,(float)6.7314,(float)
	    6.9557,(float)7.1801,(float)7.4045,(float)7.6289,(float)7.8533,(
	    float)8.0776,(float)8.302,(float)8.5264,(float)8.7508,(float)
	    8.9752,(float)9.1995,(float)22.438,(float)56.095 };
    static real f1[43] = { (float)1.,(float).9,(float).845,(float).773,(float)
	    .684,(float).641,(float).615,(float).6,(float).588,(float).581,(
	    float).575,(float).571,(float).567,(float).56238,(float).55899,(
	    float).55599,(float).55331,(float).5509,(float).54872,(float)
	    .54674,(float).54493,(float).54327,(float).54174,(float).54033,(
	    float).53902,(float).5378,(float).53666,(float).5356,(float).5346,
	    (float).53366,(float).53278,(float).53195,(float).53117,(float)
	    .53042,(float).52972,(float).52905,(float).52841,(float).5278,(
	    float).52722,(float).52667,(float).52615,(float).51271,(float)
	    .50605 };
    static real f2[43] = { (float)-.24893,(float)-.23751,(float)-.26664,(
	    float)-.39397,(float)-.31008,(float)-.13059,(float)-.09012,(float)
	    -.057113,(float)-.042426,(float)-.027218,(float)-.022517,(float)
	    -.016419,(float)-.018771,(float)-.015044,(float)-.01239,(float)
	    -.011371,(float)-.010182,(float)-.0092525,(float)-.0084272,(float)
	    -.0077166,(float)-.0070933,(float)-.0065453,(float)-.0060602,(
	    float)-.0056288,(float)-.0052432,(float)-.0048971,(float)
	    -.0045853,(float)-.0043032,(float)-.0040472,(float)-.0038141,(
	    float)-.0036012,(float)-.0034062,(float)-.0032271,(float)
	    -.0030622,(float)-.00291,(float)-.0027693,(float)-.0026389,(float)
	    -.0025175,(float)-.0024057,(float)-.0022973,(float)-.0022114,(
	    float)-3.429e-4,(float)-1.2507e-4 };

    extern /* Subroutine */ int put1d_(integer *, integer *, integer *, 
	    integer *, real *, real *, real *, integer *, integer *);

/*     Construct the table for the piezometric level versus discharge */
/*     for a closed conduit. Based on work of J. L. French, 1956. */
/*     Argument has been changed to be dimensionless.  Argument */
/*     extends to heads about 40 times the vertical diameter of the */
/*     conduit.  This should be sufficient for most culverts. */
/* SOURCE ufgculv.for:1162 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:1164 */
/*<       integerftpt,adrs_yoverd,stdout >*/
/*     Called program units */
/* SOURCE ufgculv.for:1169 */
/*<       externalput1d >*/
/*     Local */
/* SOURCE ufgculv.for:1173 */
/*<       integern >*/
/* SOURCE ufgculv.for:1174 */
/*<       parameter(n=43) >*/
/* SOURCE ufgculv.for:1176 */
/*<       realarg(n),f1(n),f2(n) >*/
/* *********************************************************************** */
/* SOURCE ufgculv.for:1178 */
/*<        >*/
/* SOURCE ufgculv.for:1186 */
/*<        >*/
/* SOURCE ufgculv.for:1194 */
/*<        >*/
/* SOURCE ufgculv.for:1204 */
/*<       callput1d(stdout,-1,4,n,arg,f1,f2,ftpt,adrs_yoverd) >*/
    put1d_(stdout, &c_n1, &feq_gen_c_d_4, &feq_gen_c_d_43, arg, f1, f2, ftpt, feq_gen_adrs_yoverd_d_);
/* SOURCE ufgculv.for:1208 */
/*<       return >*/
    return 0;
/* SOURCE ufgculv.for:1209 */
/*<       end >*/
} /* construct_yoverd__ */




/* SOURCE ufgculv.for:1213 */
/*<       real*8functionfind_fcq_resid(yvc) >*/
doublereal feq_gen_find_fcq_resid_d_(doublereal *yvc)
{
    /* System generated locals */
    real feq_gen_r_d_1;
    doublereal ret_val, feq_gen_d_d_1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    doublereal feq_gen_yc_ratio_d_;
    extern doublereal e_(doublereal*, doublereal*);
    doublereal p, ab, jb;
    integer ne;
    doublereal at, fr, ml, xe, mr;
    integer ns;
    doublereal xs, ys;
    extern /* Subroutine */ int feq_gen_get_ycynym_d_(integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *);
    doublereal ajc, jvc;
    extern /* Subroutine */ int feq_gen_find_ycynym_d_(integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *);
    doublereal abfb, jbfb, abfs;
    integer ntab;
    doublereal jbfs;
    extern doublereal rhse_(doublereal*, doublereal*);
    integer full;
    doublereal ybfs, ymax;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    real deriv;
    doublereal ycrit;
    extern /* Subroutine */ int sfwsp_(integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, FeqCallback2, FeqCallback2, FeqCallback4, integer *, integer *
	    , integer *, doublereal *, doublereal *, doublereal *, doublereal 
	    *, integer *);
    doublereal ynorm;
    real yoverd;
    extern /* Subroutine */ int feq_gen_lkt_jda_d_(integer *, doublereal *, doublereal 
	    *, doublereal *, doublereal *);

/*     Compute the residual function for subroutine FIND_FCQ. */
/*     The unknown is the depth at the vena contracta */
/* SOURCE ufgculv.for:1220 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:1222 */
/*<       real*8yvc >*/
/* INCLUDE ufgculv.for:1224 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/* INCLUDE ufgculv.for:1225 */
/*     Common block for double precision functions involved in UFGCULV. */
/* SOURCE ufgate_d.cmn:4 */
/*<        >*/
/* SOURCE ufgate_d.cmn:6 */
/*<       parameter(nmax=2000) >*/
/* SOURCE ufgate_d.cmn:8 */
/*<        >*/
/* SOURCE ufgate_d.cmn:16 */
/*<       real*8xvec(nmax),yvec(nmax),ycvec(nmax),ynvec(nmax) >*/
/* SOURCE ufgate_d.cmn:18 */
/*<        >*/
/*     Local variables */
/* SOURCE ufgculv.for:1229 */
/*<       integerns,ne,ntab,full >*/
/* SOURCE ufgculv.for:1231 */
/*<       realyoverd,deriv >*/
/* SOURCE ufgculv.for:1233 */
/*<        >*/
/*     Called functions */
/* SOURCE ufgculv.for:1240 */
/*<       real*8e,rhse >*/
/* SOURCE ufgculv.for:1242 */
/*<       externale,rhse,find_ycynym,get_ycynym,lkt_jda >*/
/* *********************************************************************** */
/* SOURCE ufgculv.for:1246 */
/*<       rflag_d=0 >*/
    ufgated_1.feq_gen_rflag_d_d_ = 0;
/*     Compute the flow from the given YVC and the energy equation. */
/*     Note that only valid values of YVC should appear here. */
/* SOURCE ufgculv.for:1251 */
/*<       at=hg_d*bg_d*cc_d*cd_d >*/
    at = ufgated_1.feq_gen_hg_d_d_ * ufgated_1.feq_gen_bg_d_d_ * ufgated_1.feq_gen_cc_d_d_ * 
	    ufgated_1.feq_gen_cd_d_d_;
/* SOURCE ufgculv.for:1252 */
/*<        >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = at / ufgated_1.feq_gen_a1_d_d_;
    ufgc1_1.qd = at * sqrt(ufgated_1.feq_gen_twog_d_d_ * (ufgated_1.feq_gen_h1_d_d_ - *yvc * 
	    ufgc1_1.feq_gen_cos_theta_d_ + ufgated_1.feq_gen_hg_d_d_ * ufgc1_1.feq_gen_sin_theta_d_) / (
	    1. - ufgated_1.feq_gen_alpha1_d_d_ * (feq_gen_d_d_1 * feq_gen_d_d_1)));
/*     Find the normal and critical depth at culvert exit. */
/* SOURCE ufgculv.for:1258 */
/*<       ycrit=yvc >*/
    ycrit = *yvc;
/* SOURCE ufgculv.for:1259 */
/*<       ynorm=0.5d0*(yvc+vert_d) >*/
    ynorm = (*yvc + ufgc1_1.feq_gen_vert_d_d_) * .5;
/* SOURCE ufgculv.for:1260 */
/*<        >*/
    feq_gen_get_ycynym_d_(&ufgated_1.feq_gen_stdout_d_d_, &ufgc1_1.station[ufgc1_1.nxs - 1], &
	    ufgated_1.feq_gen_epsarg_d_d_, &ufgated_1.feq_gen_epsf_d_d_, &ufgated_1.feq_gen_epsabs_d_d_, 
	    &ycrit, &ynorm, &ymax, &ufgated_1.feq_gen_rflag_d_d_);
/* SOURCE ufgculv.for:1267 */
/*<       if(ynorm.gt.0.d0)then >*/
    if (ynorm > 0.) {
/* SOURCE ufgculv.for:1268 */
/*<       if(ycrit.gt.ynorm)then >*/
	if (ycrit > ynorm) {
/*         The profile is supercritical. Some problem here. */
/* SOURCE ufgculv.for:1270 */
/*<       rflag_d=-1 >*/
	    ufgated_1.feq_gen_rflag_d_d_ = -1;
/* SOURCE ufgculv.for:1271 */
/*<       goto1000 >*/
	    goto L1000;
/* SOURCE ufgculv.for:1272 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:1273 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:1275 */
/*<       xs=station(nxs) >*/
    xs = ufgc1_1.station[ufgc1_1.nxs - 1];
/* SOURCE ufgculv.for:1276 */
/*<       xe=station(1)+hg_d >*/
    xe = ufgc1_1.station[0] + ufgated_1.feq_gen_hg_d_d_;
/*     Check on the relative depth to decide if we need to compute */
/*     a free-surface profile or we can use the full pipe approximation. */
/* SOURCE ufgculv.for:1282 */
/*<       yc_ratio=ycrit/vert_d >*/
    feq_gen_yc_ratio_d_ = ycrit / ufgc1_1.feq_gen_vert_d_d_;
/* SOURCE ufgculv.for:1283 */
/*<       if(yc_ratio.lt.fb_ratio)then >*/
    if (feq_gen_yc_ratio_d_ < ufgated_1.feq_gen_fb_ratio_d_) {
/* SOURCE ufgculv.for:1284 */
/*<       full=0 >*/
	full = 0;
/* SOURCE ufgculv.for:1285 */
/*<       elseif(yc_ratio.lt.fs_ratio)then >*/
    } else if (feq_gen_yc_ratio_d_ < ufgated_1.feq_gen_fs_ratio_d_) {
/* SOURCE ufgculv.for:1286 */
/*<       full=1 >*/
	full = 1;
/* SOURCE ufgculv.for:1287 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:1288 */
/*<       full=2 >*/
	full = 2;
/* SOURCE ufgculv.for:1289 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:1291 */
/*<       if(full.ge.1)then >*/
    if (full >= 1) {
/*       We compute the flow with the pipe flowing full and with */
/*       pieozometric level at the exit a function of the flow. */
/* SOURCE ufgculv.for:1295 */
/*<       fr=qd/(afull_d*sqrt(grav_d*vert_d)) >*/
	fr = ufgc1_1.qd / (ufgated_1.feq_gen_afull_d_d_ * sqrt(ufgated_1.feq_gen_grav_d_d_ * 
		ufgc1_1.feq_gen_vert_d_d_));
/* SOURCE ufgculv.for:1296 */
/*<       calllktab(adrs_yoverd,sngl(fr),0,yoverd,ntab,deriv) >*/
	feq_gen_r_d_1 = (real) fr;
	lktab_(&ufgated_1.feq_gen_adrs_yoverd_d_, &feq_gen_r_d_1, &feq_gen_c_d_0, &yoverd, &ntab, &deriv)
		;
/* SOURCE ufgculv.for:1299 */
/*<       ys=yoverd*vert_d >*/
	ys = yoverd * ufgc1_1.feq_gen_vert_d_d_;
/*        YBFB =  (ZBEX_D + COS_THETA*YS + (XS - XE)* */
/*     A                            (QD/KFULL_D)**2 - ZBVC_D)/COS_THETA */
/* SOURCE ufgculv.for:1302 */
/*<       abfb=afull_d >*/
	abfb = ufgated_1.feq_gen_afull_d_d_;
/* SOURCE ufgculv.for:1303 */
/*<       jbfb=jfull_d >*/
	jbfb = ufgated_1.feq_gen_jfull_d_d_;
/* SOURCE ufgculv.for:1304 */
/*<       y_return=ys >*/
	ufgated_1.feq_gen_y_return_d_ = ys;
/* SOURCE ufgculv.for:1305 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:1306 */
/*<       if(full.le.1)then >*/
    if (full <= 1) {
/*       Compute water-surface profile to vena contracta starting at critical */
/*       depth. */
/* SOURCE ufgculv.for:1309 */
/*<       ys=ycrit*1.001d0 >*/
	ys = ycrit * 1.001;
/* SOURCE ufgculv.for:1310 */
/*<        >*/
	sfwsp_(&ufgated_1.feq_gen_stdout_d_d_, &xs, &xe, &ys, &ufgated_1.feq_gen_eps_d_d_, e_, rhse_, feq_gen_find_ycynym_d_, &feq_gen_c_d_2000, &ns, &ne,
		 ufgated_1.xvec, ufgated_1.yvec, ufgated_1.ycvec, 
		ufgated_1.ynvec, &ufgated_1.feq_gen_rflag_d_d_);
/* SOURCE ufgculv.for:1314 */
/*<       ns_return=ns >*/
	ufgated_1.feq_gen_ns_return_d_ = ns;
/* SOURCE ufgculv.for:1315 */
/*<       ne_return=ne >*/
	ufgated_1.feq_gen_ne_return_d_ = ne;
/* SOURCE ufgculv.for:1316 */
/*<       xe_return=xe >*/
	ufgated_1.feq_gen_xe_return_d_ = xe;
/* SOURCE ufgculv.for:1318 */
/*<       ybfs=yvec(ns) >*/
	ybfs = ufgated_1.yvec[ns - 1];
/* SOURCE ufgculv.for:1319 */
/*<       calllkt_jda(0,xe,ybfs,abfs,jbfs) >*/
	feq_gen_lkt_jda_d_(&feq_gen_c_d_0, &xe, &ybfs, &abfs, &jbfs);
/* SOURCE ufgculv.for:1322 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:1324 */
/*<       if(full.eq.0)then >*/
    if (full == 0) {
/*        YB = YBFS */
/* SOURCE ufgculv.for:1326 */
/*<       ab=abfs >*/
	ab = abfs;
/* SOURCE ufgculv.for:1327 */
/*<       jb=jbfs >*/
	jb = jbfs;
/* SOURCE ufgculv.for:1328 */
/*<       elseif(full.eq.1)then >*/
    } else if (full == 1) {
/* SOURCE ufgculv.for:1329 */
/*<       p=(yc_ratio-fb_ratio)/(fs_ratio-fb_ratio) >*/
	p = (feq_gen_yc_ratio_d_ - ufgated_1.feq_gen_fb_ratio_d_) / (ufgated_1.feq_gen_fs_ratio_d_ - 
		ufgated_1.feq_gen_fb_ratio_d_);
/*        YB = YBFS + P*(YBFB - YBFS) */
/* SOURCE ufgculv.for:1331 */
/*<       ab=abfs+p*(abfb-abfs) >*/
	ab = abfs + p * (abfb - abfs);
/* SOURCE ufgculv.for:1332 */
/*<       jb=jbfs+p*(jbfb-jbfs) >*/
	jb = jbfs + p * (jbfb - jbfs);
/* SOURCE ufgculv.for:1333 */
/*<       else >*/
    } else {
/*        YB = YBFB */
/* SOURCE ufgculv.for:1335 */
/*<       ab=abfb >*/
	ab = abfb;
/* SOURCE ufgculv.for:1336 */
/*<       jb=jbfb >*/
	jb = jbfb;
/* SOURCE ufgculv.for:1337 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:1338 */
/*<       yc_return=ycrit >*/
    ufgated_1.feq_gen_yc_return_d_ = ycrit;
/* SOURCE ufgculv.for:1339 */
/*<       full_return=full >*/
    ufgated_1.feq_gen_full_return_d_ = full;
/* SOURCE ufgculv.for:1340 */
/*<       calllkt_jda(0,xe,yvc,ajc,jvc) >*/
    feq_gen_lkt_jda_d_(&feq_gen_c_d_0, &xe, yvc, &ajc, &jvc);
/*     Compute residual in the momentum balance. */
/* SOURCE ufgculv.for:1346 */
/*<       ml=qd**2/(hg_d*bg_d*cc_d)+grav_d*jvc*cos_theta >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = ufgc1_1.qd;
    ml = feq_gen_d_d_1 * feq_gen_d_d_1 / (ufgated_1.feq_gen_hg_d_d_ * ufgated_1.feq_gen_bg_d_d_ * 
	    ufgated_1.feq_gen_cc_d_d_) + ufgated_1.feq_gen_grav_d_d_ * jvc * 
	    ufgc1_1.feq_gen_cos_theta_d_;
/* SOURCE ufgculv.for:1347 */
/*<       mr=qd**2/ab+grav_d*jb*cos_theta >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = ufgc1_1.qd;
    mr = feq_gen_d_d_1 * feq_gen_d_d_1 / ab + ufgated_1.feq_gen_grav_d_d_ * jb * ufgc1_1.feq_gen_cos_theta_d_;
/* SOURCE ufgculv.for:1350 */
/*<       find_fcq_resid=(ml-mr)/mr >*/
    ret_val = (ml - mr) / mr;
/* SOURCE ufgculv.for:1352 */
/*<       return >*/
    return ret_val;
/* SOURCE ufgculv.for:1353 */
/*<  1000 continue >*/
L1000:
/*     Force the residual to be such that YC will be reduced. */
/* SOURCE ufgculv.for:1355 */
/*<       find_fcq_resid=1.d0 >*/
    ret_val = 1.;
/* SOURCE ufgculv.for:1356 */
/*<       return >*/
    return ret_val;
/* SOURCE ufgculv.for:1358 */
/*<       end >*/
} /* find_fcq_resid__ */




/* SOURCE ufgculv.for:1363 */
/*<       subroutinefind_fcq(stdout,cd,h1,fcq,yvc,rflag) >*/
/* Subroutine */ int feq_gen_find_fcq_d_(integer *stdout, doublereal *cd, doublereal *
	h1, doublereal *fcq, doublereal *yvc, integer *rflag)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    doublereal f;
    integer feq_gen_i_d_;
    doublereal y;
    real a1;
    doublereal y1, fl;
    real dt;
    doublereal fr;
    real jt, kt, tp, tt;
    integer neg;
    real dkt, qct;
    doublereal ycl, ycr;
    integer pos, feq_gen_flag_d_;
    real beta, dbeta;
    extern /* Subroutine */ int xlkt22_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *);
    real alpha1, dalpha;
    extern doublereal feq_gen_find_fcq_resid_d_(doublereal *);
    extern /* Subroutine */ int fdblrgf_(doublereal *, doublereal *, FeqCallback1, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *);
    doublereal feq_gen_yvc_min_d_, feq_gen_yvc_max_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__181 = { 0, 0, 0, 0, 0 };


/*     Find the flow when FC flow controls.  That is, critical depth */
/*     at the culvert exit drowns the orifice at the sluice gate. */
/* SOURCE ufgculv.for:1370 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:1372 */
/*<       integerstdout,rflag >*/
/* SOURCE ufgculv.for:1374 */
/*<       real*8cd,h1,fcq,yvc >*/
/* INCLUDE ufgculv.for:1376 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/* INCLUDE ufgculv.for:1377 */
/*     Common block for double precision functions involved in UFGCULV. */
/* SOURCE ufgate_d.cmn:4 */
/*<        >*/
/* SOURCE ufgate_d.cmn:6 */
/*<       parameter(nmax=2000) >*/
/* SOURCE ufgate_d.cmn:8 */
/*<        >*/
/* SOURCE ufgate_d.cmn:16 */
/*<       real*8xvec(nmax),yvec(nmax),ycvec(nmax),ynvec(nmax) >*/
/* SOURCE ufgate_d.cmn:18 */
/*<        >*/
/*     Local variables */
/* SOURCE ufgculv.for:1381 */
/*<       integeri,flag,neg,pos >*/
/* SOURCE ufgculv.for:1383 */
/*<       reala1,tt,dt,jt,kt,dkt,beta,dbeta,alpha1,dalpha,qct,tp >*/
/* SOURCE ufgculv.for:1385 */
/*<       real*8ycl,fl,ycr,fr,y1,y,f,yvc_min,yvc_max >*/
/*     External functions */
/* SOURCE ufgculv.for:1390 */
/*<       real*8find_fcq_resid >*/
/* SOURCE ufgculv.for:1392 */
/*<       externalfind_fcq_resid >*/
/*     ******************************FORMATS***************************** */
/* SOURCE ufgculv.for:1394 */
/*<    50 format(/,' *BUG:XXX* Positive residual not found for FIND_FCQ') >*/
/* SOURCE ufgculv.for:1395 */
/*<    52 format(/,' *BUG:XXX* Negative residual not found for FIND_FCQ') >*/
/* SOURCE ufgculv.for:1396 */
/*<    54  >*/
/* SOURCE ufgculv.for:1398 */
/*<    60 format(' *BUG:XXX* FDBLRGF ITERATION>100 IN FIND_FIND_FCQ') >*/
/* *********************************************************************** */
/*     Set values in common block ufgate_d.cmn */
/* SOURCE ufgculv.for:1401 */
/*<       cd_d=cd >*/
/* L50: */
/* L52: */
/* L54: */
/* L60: */
    ufgated_1.feq_gen_cd_d_d_ = *cd;
/* SOURCE ufgculv.for:1402 */
/*<       h1_d=dble(h1) >*/
    ufgated_1.feq_gen_h1_d_d_ = *h1;
/*     Find the conditions at section 1 */
/*      WRITE(STDOUT,*) ' Entering FIND_FCQ: CC=',CC,' CD=',CD */
/* SOURCE ufgculv.for:1406 */
/*<       y1=h1+hdatum_d-z1b_d >*/
    y1 = *h1 + ufgated_1.feq_gen_hdatum_d_d_ - ufgated_1.feq_gen_z1b_d_d_;
/* SOURCE ufgculv.for:1407 */
/*<       tp=sngl(y1) >*/
    tp = (real) y1;
/* SOURCE ufgculv.for:1408 */
/*<        >*/
    xlkt22_(&ufgated_1.feq_gen_apptab_d_d_, &tp, &a1, &tt, &dt, &jt, &kt, &dkt, &beta, 
	    &dbeta, &alpha1, &dalpha, &qct);
/* SOURCE ufgculv.for:1414 */
/*<       a1_d=dble(a1) >*/
    ufgated_1.feq_gen_a1_d_d_ = (doublereal) a1;
/* SOURCE ufgculv.for:1415 */
/*<       alpha1_d=dble(alpha1) >*/
    ufgated_1.feq_gen_alpha1_d_d_ = (doublereal) alpha1;
/* SOURCE ufgculv.for:1417 */
/*<       vert_d=vert_dvec(nxs) >*/
    ufgc1_1.feq_gen_vert_d_d_ = ufgc1_1.feq_gen_vert_dvec_d_[ufgc1_1.nxs - 1];
/* SOURCE ufgculv.for:1419 */
/*<       yvc_min=0.9999d0*hg_d*cc_d >*/
    feq_gen_yvc_min_d_ = ufgated_1.feq_gen_hg_d_d_ * .9999 * ufgated_1.feq_gen_cc_d_d_;
/* SOURCE ufgculv.for:1421 */
/*<       yvc_max=min(0.999d0*(h1_d+hg_d*sin_theta),vert_d) >*/
/* Computing MIN */
    feq_gen_d_d_1 = (ufgated_1.feq_gen_h1_d_d_ + ufgated_1.feq_gen_hg_d_d_ * ufgc1_1.feq_gen_sin_theta_d_) * .999;
    feq_gen_yvc_max_d_ = min(feq_gen_d_d_1,ufgc1_1.feq_gen_vert_d_d_);
/*     Explore the function */
/*      N = 50 */
/*      DO 90 I= 1,N */
/*        YCL = YVC_MIN + DBLE(I-1)*(0.8*YVC_MAX - YVC_MIN)/DBLE(N) */
/*        RESID = FIND_FCQ_RESID(YCL) */
/*        WRITE(STDOUT,9782) YCL, RESID, FULL_RETURN */
/* 9782  FORMAT(' YCL=',F10.4,' RESID=',1PE10.3,' FULL=',I5) */
/* 90    CONTINUE */
/* SOURCE ufgculv.for:1436 */
/*<       y=yvc_min >*/
    y = feq_gen_yvc_min_d_;
/* SOURCE ufgculv.for:1437 */
/*<       neg=0 >*/
    neg = 0;
/* SOURCE ufgculv.for:1438 */
/*<       pos=0 >*/
    pos = 0;
/* SOURCE ufgculv.for:1439 */
/*<       i=100 >*/
    feq_gen_i_d_ = 100;
/* SOURCE ufgculv.for:1440 */
/*<   100 continue >*/
L100:
/* SOURCE ufgculv.for:1441 */
/*<       if(neg+pos.lt.2)then >*/
    if (neg + pos < 2) {
/*       Evaluate the residual */
/* SOURCE ufgculv.for:1443 */
/*<       f=find_fcq_resid(y) >*/
	f = feq_gen_find_fcq_resid_d_(&y);
/* SOURCE ufgculv.for:1444 */
/*<       i=i-1 >*/
	--feq_gen_i_d_;
/* SOURCE ufgculv.for:1445 */
/*<       if(i.eq.0)then >*/
	if (feq_gen_i_d_ == 0) {
/* SOURCE ufgculv.for:1446 */
/*<       write(stdout,*)' NO SIGN CHANGE FOUND IN FIND_FCQ' >*/
	    feq_gen_io_d__181.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__181);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NO SIGN CHANGE FOUND IN FIND_FCQ"), (ftnlen)
		    33);
	    e_wsle();
/* SOURCE ufgculv.for:1447 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE ufgculv.for:1448 */
/*<       endif >*/
	}
/*        WRITE(STDOUT,9787) I, Y, F, FULL_RETURN */
/* 9787  FORMAT(' I=',I5,' Y=',F10.4,' F=',1PE10.3,' FULL=',I5) */
/* SOURCE ufgculv.for:1452 */
/*<       if(f.lt.0.d0)then >*/
	if (f < 0.) {
/* SOURCE ufgculv.for:1453 */
/*<       fl=f >*/
	    fl = f;
/* SOURCE ufgculv.for:1454 */
/*<       ycl=y >*/
	    ycl = y;
/* SOURCE ufgculv.for:1455 */
/*<       neg=1 >*/
	    neg = 1;
/* SOURCE ufgculv.for:1456 */
/*<       y=0.7d0*ycl+0.3d0*yvc_max >*/
	    y = ycl * .7 + feq_gen_yvc_max_d_ * .3;
/* SOURCE ufgculv.for:1457 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE ufgculv.for:1458 */
/*<       else >*/
	} else {
/* SOURCE ufgculv.for:1459 */
/*<       fr=f >*/
	    fr = f;
/* SOURCE ufgculv.for:1460 */
/*<       ycr=y >*/
	    ycr = y;
/* SOURCE ufgculv.for:1461 */
/*<       pos=1 >*/
	    pos = 1;
/* SOURCE ufgculv.for:1462 */
/*<       y=1.002d0*ycr >*/
	    y = ycr * 1.002;
/* SOURCE ufgculv.for:1463 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE ufgculv.for:1464 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:1465 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' Calling FDBLRGF with: YCL=',YCL,' FL=',FL */
/*      WRITE(STDOUT,*) ' YCR=',YCR,' FR=',FR */
/* SOURCE ufgculv.for:1471 */
/*<       callfdblrgf(epsarg_d,epsf_d,find_fcq_resid,ycl,ycr,fl,fr,yvc,flag) >*/
    fdblrgf_(&ufgated_1.feq_gen_epsarg_d_d_, &ufgated_1.feq_gen_epsf_d_d_, feq_gen_find_fcq_resid_d_, &ycl, &ycr, &fl, &fr, yvc, &feq_gen_flag_d_);
/*      WRITE(STDOUT,*) ' FL=',FL */
/*      WRITE(STDOUT,*) ' Return from FDBLRGF with: FLAG=',FLAG */
/*      WRITE(STDOUT,*) ' YVC =',YVC, ' KNT=',INT(FR) */
/* SOURCE ufgculv.for:1480 */
/*<       if(flag.eq.3)flag=0 >*/
    if (feq_gen_flag_d_ == 3) {
	feq_gen_flag_d_ = 0;
    }
/*     Find the station when the barrel is full. */
/* SOURCE ufgculv.for:1483 */
/*<       full_barrel_station=-1.d0 >*/
    ufgated_1.feq_gen_full_barrel_station_d_ = -1.;
/*      WRITE(STDOUT,*) ' XE_RETURN=',XE_RETURN */

/*      DO 800 I=NS_RETURN,NE_RETURN */
/*        WRITE(STDOUT,5678) XVEC(I), YVEC(I) */
/* 5678  FORMAT(F12.6,F12.6) */
/* 800   CONTINUE */
/* SOURCE ufgculv.for:1491 */
/*<       do900i=ne_return,ns_return,-1 >*/
    feq_gen_i_d_1 = ufgated_1.feq_gen_ns_return_d_;
    for (feq_gen_i_d_ = ufgated_1.feq_gen_ne_return_d_; feq_gen_i_d_ >= feq_gen_i_d_1; --feq_gen_i_d_) {
/* SOURCE ufgculv.for:1492 */
/*<       if(yvec(i).ge.vert_d)then >*/
	if (ufgated_1.yvec[feq_gen_i_d_ - 1] >= ufgc1_1.feq_gen_vert_d_d_) {
/* SOURCE ufgculv.for:1493 */
/*<       full_barrel_station=xvec(i) >*/
	    ufgated_1.feq_gen_full_barrel_station_d_ = ufgated_1.xvec[feq_gen_i_d_ - 1];
/* SOURCE ufgculv.for:1494 */
/*<       goto901 >*/
	    goto L901;
/* SOURCE ufgculv.for:1495 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:1496 */
/*<   900 continue >*/
/* L900: */
    }
/* SOURCE ufgculv.for:1497 */
/*<   901 continue >*/
L901:
/* SOURCE ufgculv.for:1499 */
/*<       fcq=qd >*/
    *fcq = ufgc1_1.qd;
/* SOURCE ufgculv.for:1501 */
/*<       return >*/
    return 0;
/* SOURCE ufgculv.for:1502 */
/*<       end >*/
} /* find_fcq__ */




/* SOURCE ufgculv.for:1506 */
/*<       real*8functionfind_foll_resid(h) >*/
doublereal feq_gen_find_foll_resid_d_(doublereal *feq_gen_h_d_)
{
    /* System generated locals */
    real feq_gen_r_d_1;
    doublereal ret_val, feq_gen_d_d_1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    doublereal feq_gen_yc_ratio_d_;
    extern doublereal e_(doublereal*, doublereal*);
    doublereal p, ab, jb, mb;
    integer ne;
    doublereal fr;
    real rg;
    doublereal yb, xe;
    integer ns;
    doublereal xs, ys;
    extern /* Subroutine */ int feq_gen_ufg_fndfoq_d_(integer *, integer *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *), 
	    feq_gen_get_ycynym_d_(integer *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *)
	    ;
    doublereal avc, jvc, mvc, yvc;
    extern /* Subroutine */ int feq_gen_find_ycynym_d_(integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *);
    doublereal abfb, jbfb, abfs, ybfb;
    integer ntab;
    doublereal jbfs;
    extern doublereal rhse_(doublereal*, doublereal*);
    integer full;
    doublereal ybfs, ymax;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    real deriv;
    doublereal ycrit;
    extern /* Subroutine */ int sfwsp_(integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, FeqCallback2, FeqCallback2, FeqCallback4, integer *, integer *
	    , integer *, doublereal *, doublereal *, doublereal *, doublereal 
	    *, integer *);
    doublereal ynorm;
    extern doublereal findcc_(real *, real *, integer *);
    real yoverd;
    extern /* Subroutine */ int feq_gen_lkt_jda_d_(integer *, doublereal *, doublereal 
	    *, doublereal *, doublereal *);

/*     Compute the residual function for subroutine FIND_FOLL */
/* SOURCE ufgculv.for:1511 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:1513 */
/*<       real*8h >*/
/* INCLUDE ufgculv.for:1515 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/* INCLUDE ufgculv.for:1516 */
/*     Common block for double precision functions involved in UFGCULV. */
/* SOURCE ufgate_d.cmn:4 */
/*<        >*/
/* SOURCE ufgate_d.cmn:6 */
/*<       parameter(nmax=2000) >*/
/* SOURCE ufgate_d.cmn:8 */
/*<        >*/
/* SOURCE ufgate_d.cmn:16 */
/*<       real*8xvec(nmax),yvec(nmax),ycvec(nmax),ynvec(nmax) >*/
/* SOURCE ufgate_d.cmn:18 */
/*<        >*/
/*     Local variables */
/* SOURCE ufgculv.for:1520 */
/*<       integerns,ne,ntab,full >*/
/* SOURCE ufgculv.for:1522 */
/*<       realderiv,yoverd,rg >*/
/* SOURCE ufgculv.for:1524 */
/*<        >*/
/*     Called functions */
/* SOURCE ufgculv.for:1530 */
/*<       real*4findcc >*/
/* SOURCE ufgculv.for:1532 */
/*<       real*8e,rhse >*/
/* SOURCE ufgculv.for:1534 */
/*<       externale,rhse,find_ycynym,get_ycynym,lkt_jda,findcc >*/
/* *********************************************************************** */
/* SOURCE ufgculv.for:1537 */
/*<       rg=hg_d/h >*/
    rg = ufgated_1.feq_gen_hg_d_d_ / *feq_gen_h_d_;
/* SOURCE ufgculv.for:1538 */
/*<       if(rg.gt.1.0)rg=1.0 >*/
    if (rg > (float)1.) {
	rg = (float)1.;
    }
/* SOURCE ufgculv.for:1539 */
/*<       cc_d=findcc(rg,sngl(concc_d),cctab_d) >*/
    feq_gen_r_d_1 = (real) ufgated_1.feq_gen_concc_d_d_;
    ufgated_1.feq_gen_cc_d_d_ = findcc_(&rg, &feq_gen_r_d_1, &ufgated_1.feq_gen_cctab_d_d_);
/* SOURCE ufgculv.for:1540 */
/*<       rflag_d=0 >*/
    ufgated_1.feq_gen_rflag_d_d_ = 0;
/*     Find FO flow */
/* SOURCE ufgculv.for:1542 */
/*<        >*/
    feq_gen_ufg_fndfoq_d_(&ufgated_1.feq_gen_stdout_d_d_, &ufgated_1.feq_gen_apptab_d_d_, feq_gen_h_d_, &
	    ufgated_1.feq_gen_hdatum_d_d_, &ufgated_1.feq_gen_hg_d_d_, &ufgated_1.feq_gen_bg_d_d_, &
	    ufgated_1.feq_gen_z1b_d_d_, &ufgated_1.feq_gen_cc_d_d_, &ufgated_1.feq_gen_cd_d_d_, &
	    ufgated_1.feq_gen_twog_d_d_, &ufgc1_1.qd);
/*     Find the critical and normal depths at the culvert exit. */
/* SOURCE ufgculv.for:1548 */
/*<       vert_d=vert_dvec(nxs) >*/
    ufgc1_1.feq_gen_vert_d_d_ = ufgc1_1.feq_gen_vert_dvec_d_[ufgc1_1.nxs - 1];
/* SOURCE ufgculv.for:1549 */
/*<       ycrit=0.5d0*vert_d >*/
    ycrit = ufgc1_1.feq_gen_vert_d_d_ * .5;
/* SOURCE ufgculv.for:1550 */
/*<       ynorm=0.5d0*vert_d >*/
    ynorm = ufgc1_1.feq_gen_vert_d_d_ * .5;
/* SOURCE ufgculv.for:1551 */
/*<        >*/
    feq_gen_get_ycynym_d_(&ufgated_1.feq_gen_stdout_d_d_, &ufgc1_1.station[ufgc1_1.nxs - 1], &
	    ufgated_1.feq_gen_epsarg_d_d_, &ufgated_1.feq_gen_epsf_d_d_, &ufgated_1.feq_gen_epsabs_d_d_, 
	    &ycrit, &ynorm, &ymax, &ufgated_1.feq_gen_rflag_d_d_);
/* SOURCE ufgculv.for:1557 */
/*<       if(ynorm.gt.0.d0)then >*/
    if (ynorm > 0.) {
/* SOURCE ufgculv.for:1558 */
/*<       if(ycrit.gt.ynorm)then >*/
	if (ycrit > ynorm) {
/*         The profile is supercritical.  H is probably too large */
/* SOURCE ufgculv.for:1560 */
/*<       rflag_d=-1 >*/
	    ufgated_1.feq_gen_rflag_d_d_ = -1;
/* SOURCE ufgculv.for:1561 */
/*<       goto1000 >*/
	    goto L1000;
/* SOURCE ufgculv.for:1562 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:1563 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:1565 */
/*<       yc_return=ycrit >*/
    ufgated_1.feq_gen_yc_return_d_ = ycrit;
/* SOURCE ufgculv.for:1567 */
/*<       xs=station(nxs) >*/
    xs = ufgc1_1.station[ufgc1_1.nxs - 1];
/* SOURCE ufgculv.for:1568 */
/*<       xe=station(1)+hg_d >*/
    xe = ufgc1_1.station[0] + ufgated_1.feq_gen_hg_d_d_;
/*     Check on the relative depth to decide if we need to compute */
/*     a free-surface profile or we can use the full pipe approximation. */
/* SOURCE ufgculv.for:1573 */
/*<       yc_ratio=ycrit/vert_d >*/
    feq_gen_yc_ratio_d_ = ycrit / ufgc1_1.feq_gen_vert_d_d_;
/* SOURCE ufgculv.for:1574 */
/*<       if(yc_ratio.lt.fb_ratio)then >*/
    if (feq_gen_yc_ratio_d_ < ufgated_1.feq_gen_fb_ratio_d_) {
/* SOURCE ufgculv.for:1575 */
/*<       full=0 >*/
	full = 0;
/* SOURCE ufgculv.for:1576 */
/*<       elseif(yc_ratio.lt.fs_ratio)then >*/
    } else if (feq_gen_yc_ratio_d_ < ufgated_1.feq_gen_fs_ratio_d_) {
/* SOURCE ufgculv.for:1577 */
/*<       full=1 >*/
	full = 1;
/* SOURCE ufgculv.for:1578 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:1579 */
/*<       full=2 >*/
	full = 2;
/* SOURCE ufgculv.for:1580 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:1581 */
/*<       if(full.ge.1)then >*/
    if (full >= 1) {
/*       We compute the flow with the pipe flowing full and with */
/*       pieozometric level at the exit a function of the flow. */
/* SOURCE ufgculv.for:1585 */
/*<       fr=qd/(afull_d*sqrt(grav_d*vert_d)) >*/
	fr = ufgc1_1.qd / (ufgated_1.feq_gen_afull_d_d_ * sqrt(ufgated_1.feq_gen_grav_d_d_ * 
		ufgc1_1.feq_gen_vert_d_d_));
/* SOURCE ufgculv.for:1586 */
/*<       calllktab(adrs_yoverd,sngl(fr),0,yoverd,ntab,deriv) >*/
	feq_gen_r_d_1 = (real) fr;
	lktab_(&ufgated_1.feq_gen_adrs_yoverd_d_, &feq_gen_r_d_1, &feq_gen_c_d_0, &yoverd, &ntab, &deriv)
		;
/* SOURCE ufgculv.for:1589 */
/*<       ys=yoverd*vert_d >*/
	ys = yoverd * ufgc1_1.feq_gen_vert_d_d_;
/* SOURCE ufgculv.for:1590 */
/*<        >*/
/* Computing 2nd power */
	feq_gen_d_d_1 = ufgc1_1.qd / ufgated_1.feq_gen_kfull_d_d_;
	ybfb = (ufgated_1.feq_gen_zbex_d_d_ + ufgc1_1.feq_gen_cos_theta_d_ * ys + (xs - xe) * (
		feq_gen_d_d_1 * feq_gen_d_d_1) - ufgated_1.feq_gen_zbvc_d_d_) / ufgc1_1.feq_gen_cos_theta_d_;
/* SOURCE ufgculv.for:1592 */
/*<       abfb=afull_d >*/
	abfb = ufgated_1.feq_gen_afull_d_d_;
/* SOURCE ufgculv.for:1593 */
/*<       jbfb=jfull_d >*/
	jbfb = ufgated_1.feq_gen_jfull_d_d_;
/* SOURCE ufgculv.for:1594 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:1595 */
/*<       if(full.le.1)then >*/
    if (full <= 1) {
/*       Compute water-surface profile to vena contracta starting at critical */
/*       depth. */
/* SOURCE ufgculv.for:1598 */
/*<       ys=ycrit*1.001d0 >*/
	ys = ycrit * 1.001;
/* SOURCE ufgculv.for:1599 */
/*<        >*/
	sfwsp_(&ufgated_1.feq_gen_stdout_d_d_, &xs, &xe, &ys, &ufgated_1.feq_gen_eps_d_d_, e_, rhse_, feq_gen_find_ycynym_d_, &feq_gen_c_d_2000, &ns, &ne,
		 ufgated_1.xvec, ufgated_1.yvec, ufgated_1.ycvec, 
		ufgated_1.ynvec, &ufgated_1.feq_gen_rflag_d_d_);
/* SOURCE ufgculv.for:1603 */
/*<       ns_return=ns >*/
	ufgated_1.feq_gen_ns_return_d_ = ns;
/* SOURCE ufgculv.for:1604 */
/*<       ne_return=ne >*/
	ufgated_1.feq_gen_ne_return_d_ = ne;
/* SOURCE ufgculv.for:1605 */
/*<       xe_return=xe >*/
	ufgated_1.feq_gen_xe_return_d_ = xe;
/* SOURCE ufgculv.for:1607 */
/*<       ybfs=yvec(ns) >*/
	ybfs = ufgated_1.yvec[ns - 1];
/* SOURCE ufgculv.for:1608 */
/*<       calllkt_jda(0,xe,ybfs,abfs,jbfs) >*/
	feq_gen_lkt_jda_d_(&feq_gen_c_d_0, &xe, &ybfs, &abfs, &jbfs);
/* SOURCE ufgculv.for:1611 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:1612 */
/*<       yc_return=ys >*/
    ufgated_1.feq_gen_yc_return_d_ = ys;
/* SOURCE ufgculv.for:1613 */
/*<       full_return=full >*/
    ufgated_1.feq_gen_full_return_d_ = full;
/* SOURCE ufgculv.for:1614 */
/*<       if(full.eq.0)then >*/
    if (full == 0) {
/* SOURCE ufgculv.for:1615 */
/*<       yb=ybfs >*/
	yb = ybfs;
/* SOURCE ufgculv.for:1616 */
/*<       ab=abfs >*/
	ab = abfs;
/* SOURCE ufgculv.for:1617 */
/*<       jb=jbfs >*/
	jb = jbfs;
/* SOURCE ufgculv.for:1618 */
/*<       elseif(full.eq.1)then >*/
    } else if (full == 1) {
/* SOURCE ufgculv.for:1619 */
/*<       p=(yc_ratio-fb_ratio)/(fs_ratio-fb_ratio) >*/
	p = (feq_gen_yc_ratio_d_ - ufgated_1.feq_gen_fb_ratio_d_) / (ufgated_1.feq_gen_fs_ratio_d_ - 
		ufgated_1.feq_gen_fb_ratio_d_);
/* SOURCE ufgculv.for:1620 */
/*<       yb=ybfs+p*(ybfb-ybfs) >*/
	yb = ybfs + p * (ybfb - ybfs);
/* SOURCE ufgculv.for:1621 */
/*<       ab=abfs+p*(abfb-abfs) >*/
	ab = abfs + p * (abfb - abfs);
/* SOURCE ufgculv.for:1622 */
/*<       jb=jbfs+p*(jbfb-jbfs) >*/
	jb = jbfs + p * (jbfb - jbfs);
/* SOURCE ufgculv.for:1623 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:1624 */
/*<       yb=ybfb >*/
	yb = ybfb;
/* SOURCE ufgculv.for:1625 */
/*<       ab=abfb >*/
	ab = abfb;
/* SOURCE ufgculv.for:1626 */
/*<       jb=jbfb >*/
	jb = jbfb;
/* SOURCE ufgculv.for:1627 */
/*<       endif >*/
    }
/*     Compute simple momentum balance at the vena contracta.  Add */
/*     gravity force later for rectangular channels with free surface */
/*     flow. */
/* SOURCE ufgculv.for:1634 */
/*<       y_return=yb >*/
    ufgated_1.feq_gen_y_return_d_ = yb;
/* SOURCE ufgculv.for:1636 */
/*<       yvc=cc_d*hg_d >*/
    yvc = ufgated_1.feq_gen_cc_d_d_ * ufgated_1.feq_gen_hg_d_d_;
/* SOURCE ufgculv.for:1637 */
/*<       calllkt_jda(0,xe,yvc,avc,jvc) >*/
    feq_gen_lkt_jda_d_(&feq_gen_c_d_0, &xe, &yvc, &avc, &jvc);
/* SOURCE ufgculv.for:1641 */
/*<       mvc=qd**2/avc+grav_d*jvc*cos_theta >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = ufgc1_1.qd;
    mvc = feq_gen_d_d_1 * feq_gen_d_d_1 / avc + ufgated_1.feq_gen_grav_d_d_ * jvc * ufgc1_1.feq_gen_cos_theta_d_;
/* SOURCE ufgculv.for:1642 */
/*<       mb=qd**2/ab+grav_d*jb*cos_theta >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = ufgc1_1.qd;
    mb = feq_gen_d_d_1 * feq_gen_d_d_1 / ab + ufgated_1.feq_gen_grav_d_d_ * jb * ufgc1_1.feq_gen_cos_theta_d_;
/* SOURCE ufgculv.for:1644 */
/*<       find_foll_resid=(mvc-mb)/mb >*/
    ret_val = (mvc - mb) / mb;
/* SOURCE ufgculv.for:1645 */
/*<       return >*/
    return ret_val;
/* SOURCE ufgculv.for:1646 */
/*<  1000 continue >*/
L1000:
/*     Force the residual to be such that H will be reduced. */
/* SOURCE ufgculv.for:1648 */
/*<       find_foll_resid=1.d50 >*/
    ret_val = 1e50;
/* SOURCE ufgculv.for:1649 */
/*<       return >*/
    return ret_val;
/* SOURCE ufgculv.for:1651 */
/*<       end >*/
} /* find_foll_resid__ */




/* SOURCE ufgculv.for:1655 */
/*<       subroutinefind_foll(stdout,cd,max_h1,h1,rflag) >*/
/* Subroutine */ int feq_gen_find_foll_d_(integer *stdout, doublereal *cd, doublereal *
	feq_gen_max_h1_d_, doublereal *h1, integer *rflag)
{
    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();

    /* Local variables */
    doublereal fl, hl, fr, hr;
    integer feq_gen_flag_d_;
    doublereal feq_gen_resid_at_max_h1_d_;
    extern /* Subroutine */ int fdblrgf_(doublereal *, doublereal *, FeqCallback1, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *);
    doublereal feq_gen_resid_at_h1fwul_d_;
    extern doublereal feq_gen_find_foll_resid_d_(doublereal *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__224 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__225 = { 0, 0, 0, 0, 0 };


/*     Find the head at section 1 for the lower limit of FO flow when */
/*     FC flow is found to exist. */
/* SOURCE ufgculv.for:1663 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:1665 */
/*<       integerstdout,rflag >*/
/* SOURCE ufgculv.for:1667 */
/*<       real*8cd,h1,max_h1 >*/
/* INCLUDE ufgculv.for:1669 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/* INCLUDE ufgculv.for:1670 */
/*     Common block for double precision functions involved in UFGCULV. */
/* SOURCE ufgate_d.cmn:4 */
/*<        >*/
/* SOURCE ufgate_d.cmn:6 */
/*<       parameter(nmax=2000) >*/
/* SOURCE ufgate_d.cmn:8 */
/*<        >*/
/* SOURCE ufgate_d.cmn:16 */
/*<       real*8xvec(nmax),yvec(nmax),ycvec(nmax),ynvec(nmax) >*/
/* SOURCE ufgate_d.cmn:18 */
/*<        >*/
/*     Local variables */
/* SOURCE ufgculv.for:1674 */
/*<       integerflag >*/
/* SOURCE ufgculv.for:1676 */
/*<       real*8hl,fl,hr,fr,resid_at_h1fwul,resid_at_max_h1 >*/
/*     External functions */
/* SOURCE ufgculv.for:1680 */
/*<       real*8find_foll_resid >*/
/* SOURCE ufgculv.for:1682 */
/*<       externalfind_foll_resid >*/
/*     ******************************FORMATS***************************** */
/* SOURCE ufgculv.for:1684 */
/*<    50 format(/,' *BUG:XXX* Positive residual not found for FIND_FOLL') >*/
/* SOURCE ufgculv.for:1685 */
/*<    52 format(/,' *BUG:XXX* Negative residual not found for FIND_FOLL') >*/
/* SOURCE ufgculv.for:1686 */
/*<    54  >*/
/* SOURCE ufgculv.for:1688 */
/*<    60 format(' *BUG:XXX* FDBLRGF ITERATION>100 IN FIND_FIND_FOLL') >*/
/* *********************************************************************** */
/*     Set values in common block ufgate_d.cmn */
/* SOURCE ufgculv.for:1691 */
/*<       cd_d=cd >*/
/* L50: */
/* L52: */
/* L54: */
/* L60: */
    ufgated_1.feq_gen_cd_d_d_ = *cd;
/*     Evaluate the residual at the initial value of H1.  This should */
/*     be H1FWUL. */
/* SOURCE ufgculv.for:1695 */
/*<       resid_at_h1fwul=find_foll_resid(h1) >*/
    feq_gen_resid_at_h1fwul_d_ = feq_gen_find_foll_resid_d_(h1);
/* SOURCE ufgculv.for:1696 */
/*<       resid_at_max_h1=find_foll_resid(max_h1) >*/
    feq_gen_resid_at_max_h1_d_ = feq_gen_find_foll_resid_d_(feq_gen_max_h1_d_);
/* SOURCE ufgculv.for:1697 */
/*<       if(resid_at_h1fwul.lt.0.d0)then >*/
    if (feq_gen_resid_at_h1fwul_d_ < 0.) {
/*       FO with normal CC is submerged at H1FWUL.  H1FOLL exists */
/* SOURCE ufgculv.for:1699 */
/*<       if(resid_at_max_h1.gt.0.d0)then >*/
	if (feq_gen_resid_at_max_h1_d_ > 0.) {
/*         Maximum head is greater than H1FOLL.  We appear to have */
/*         a root.  Experiments indicate there is only one in this */
/*         case. */
/* SOURCE ufgculv.for:1704 */
/*<       hl=h1 >*/
	    hl = *h1;
/* SOURCE ufgculv.for:1705 */
/*<       fl=resid_at_h1fwul >*/
	    fl = feq_gen_resid_at_h1fwul_d_;
/* SOURCE ufgculv.for:1706 */
/*<       hr=max_h1 >*/
	    hr = *feq_gen_max_h1_d_;
/* SOURCE ufgculv.for:1707 */
/*<       fr=resid_at_max_h1 >*/
	    fr = feq_gen_resid_at_max_h1_d_;
/*         Try bisection here */
/*          CALL BISECT_D */
/*     I                (STDOUT, EPSARG_D, EPSF_D, FIND_FOLL_RESID, */
/*     M                 HL, HR, FL, FR, */
/*     O                 H1, FLAG) */
/*          WRITE(STDOUT,*) ' BISECTION: H1FOLL=',H1,' FLAG=',FLAG */
/*          WRITE(STDOUT,*) ' FL=',FL */
/*          WRITE(STDOUT,*) ' Calling FDBLRGF with: HL=',HL,' FL=',FL */
/*          WRITE(STDOUT,*) ' HR=',HR,' FR=',FR */
/* SOURCE ufgculv.for:1722 */
/*<       callfdblrgf(epsarg_d,epsf_d,find_foll_resid,hl,hr,fl,fr,h1,flag) >*/
	    fdblrgf_(&ufgated_1.feq_gen_epsarg_d_d_, &ufgated_1.feq_gen_epsf_d_d_, feq_gen_find_foll_resid_d_, &hl, &hr, &fl, &fr, h1, &feq_gen_flag_d_);
/*           WRITE(STDOUT,*) ' FL=',FL,' FULL=',FULL_RETURN */
/*           WRITE(STDOUT,*) ' Return from FDBLRGF with: FLAG=',FLAG */
/*           WRITE(STDOUT,*) ' H1FOLL =',H1, ' KNT=',INT(FR) */
/* SOURCE ufgculv.for:1733 */
/*<       if(flag.eq.3)flag=0 >*/
	    if (feq_gen_flag_d_ == 3) {
		feq_gen_flag_d_ = 0;
	    }
/* SOURCE ufgculv.for:1736 */
/*<       else >*/
	} else {
/*         Maximum head is less than H1FOLL.  Thus the free flow */
/*         at this gate opening is always FC. */
/* SOURCE ufgculv.for:1740 */
/*<       write(stdout,*)' H1FOLL > maximum head at section 1.' >*/
	    feq_gen_io_d__224.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__224);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" H1FOLL > maximum head at section 1."), (
		    ftnlen)36);
	    e_wsle();
/* SOURCE ufgculv.for:1741 */
/*<       h1=max_h1 >*/
	    *h1 = *feq_gen_max_h1_d_;
/* SOURCE ufgculv.for:1742 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:1743 */
/*<       else >*/
    } else {
/*       Probable that H1FOLL does not exist.  If the */
/*       residual has an initial decline as the head is increased */
/*       slightly, we may have a two root solution.  Skip */
/*       for now unless we can define it more closely */
/* SOURCE ufgculv.for:1749 */
/*<       write(stdout,*)' H1FOLL may not exist. Flow is always FO' >*/
	feq_gen_io_d__225.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__225);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" H1FOLL may not exist. Flow is always FO"), (
		ftnlen)40);
	e_wsle();
/* SOURCE ufgculv.for:1750 */
/*<       h1=0.d0 >*/
	*h1 = 0.;
/* SOURCE ufgculv.for:1751 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:1753 */
/*<       return >*/
    return 0;
/* SOURCE ufgculv.for:1755 */
/*<       end >*/
} /* find_foll__ */




/* SOURCE ufgculv.for:1761 */
/*<        >*/
/* Subroutine */ int feq_gen_ufg_fndfoq_d_(integer *stdout, integer *apptab, 
	doublereal *h1, doublereal *hdatum, doublereal *hg, doublereal *bg, 
	doublereal *z1b, doublereal *cc, doublereal *cd, doublereal *twog, 
	doublereal *q)
{
    /* System generated locals */
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    real a1;
    doublereal y1, at;
    real dt, jt, kt, tp, tt;
    doublereal hvc;
    real dkt, qct, beta, dbeta;
    extern /* Subroutine */ int xlkt22_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *);
    real alpha1, dalpha;

/*     + + + PURPOSE + + + */
/*     Find the free orifice flow. */
/* SOURCE ufgculv.for:1769 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ufgculv.for:1772 */
/*<       integerapptab,stdout >*/
/* SOURCE ufgculv.for:1773 */
/*<       real*8h1,hdatum,q,hg,bg,z1b,cc,cd,twog >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     H1     - head at section 1 */
/*     HDATUM - Datum for measuring head */
/*     Q      - Flowrate */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ufgculv.for:1781 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ufgculv.for:1784 */
/*<       reala1,tt,dt,jt,kt,dkt,beta,dbeta,alpha1,dalpha,qct,tp >*/
/* SOURCE ufgculv.for:1786 */
/*<       real*8hvc,y1,at >*/
/*     + + + INTRINSICS + + + */
/* SOURCE ufgculv.for:1789 */
/*<       intrinsicsqrt,sngl >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ufgculv.for:1792 */
/*<       externalxlkt22 >*/
/* *********************************************************************** */
/* SOURCE ufgculv.for:1795 */
/*<       y1=h1+hdatum-z1b >*/
    y1 = *h1 + *hdatum - *z1b;
/* SOURCE ufgculv.for:1796 */
/*<       tp=sngl(y1) >*/
    tp = (real) y1;
/* SOURCE ufgculv.for:1797 */
/*<        >*/
    xlkt22_(apptab, &tp, &a1, &tt, &dt, &jt, &kt, &dkt, &beta, &dbeta, &
	    alpha1, &dalpha, &qct);
/*      WRITE(STDOUT,*) ' Y1=',Y1,' A1=',A1 */
/*      WRITE(STDOUT,*) ' ALPHA1=',ALPHA1 */
/*      WRITE(STDOUT,*) ' SIN_THETA=',SIN_THETA */
/* SOURCE ufgculv.for:1806 */
/*<       at=cd*cc*bg*hg >*/
    at = *cd * *cc * *bg * *hg;
/* SOURCE ufgculv.for:1807 */
/*<       hvc=cc*hg-sin_theta*hg >*/
    hvc = *cc * *hg - ufgc1_1.feq_gen_sin_theta_d_ * *hg;
/*      WRITE(STDOUT,*) ' HVC=',HVC */
/* SOURCE ufgculv.for:1809 */
/*<       q=at*sqrt(twog*(h1-hvc)/(1.d0-dble(alpha1)*(at/dble(a1))**2)) >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = at / (doublereal) a1;
    *q = at * sqrt(*twog * (*h1 - hvc) / (1. - (doublereal) alpha1 * (feq_gen_d_d_1 * 
	    feq_gen_d_d_1)));
/* SOURCE ufgculv.for:1813 */
/*<       return >*/
    return 0;
/* SOURCE ufgculv.for:1814 */
/*<       end >*/
} /* ufg_fndfoq__ */




/*      REAL*8 FUNCTION FW_CC_FO_RESID( */
/*     I                            CC) */

/* C     Compute values for the free-weir contraction coefficient */
/* C     residual function. */

/*      IMPLICIT NONE */

/*      REAL*8 CC */

/*      INCLUDE 'fwcc.cmn' */
/* C*********************************************************************** */

/*      FW_CC_FO_RESID =  M1/CC**2 + CC - E_AT_1 */
/*      RETURN */
/*      END */
/* C */
/* C */
/* C */
/*      SUBROUTINE FIND_FW_CC_FO( */
/*     I                  STDOUT, EPSARG, EPSF, EPSABS, APPTAB, GRAV, */
/*     I              H1FWULA, HDATUM, Z1B, STATION_1, HG, BG, Y2HAT, */
/*     O                  CD, FW_CC, FOFLAG, FLAG) */

/* C     Find the contraction coefficient that forces the FO equation */
/* C     to produce the same flow as the flow at the FW limit. */

/*      IMPLICIT NONE */

/*      INTEGER APPTAB, STDOUT, FLAG, FOFLAG */

/*      REAL*8 EPSARG, EPSF, EPSABS, GRAV, H1FWULA, Z1B, STATION_1, */
/*     A       HG, FW_CC, Y2HAT, BG, CD, HDATUM, CC */


/*      INCLUDE 'barrel.cmn' */
/*      INCLUDE 'fwcc.cmn' */


/* C     Local variables */

/*      INTEGER I */

/*      REAL*8 TWOG, YL, YR, FL, FR, L12, H1FWUL, */
/*     A       FR2VC, YSEQ, Q */
/*      REAL A1, T1, DT1, J1, K1, DK1, BETA1, DBETA1, ALPHA1, */
/*     A     DALPHA1, QC1, AB, TB, DTB, JB, KB, DKB, BETAB, DBETAB, */
/*     B     ALPHAB, DALPHAB, QCB */

/* C     External program units */

/*      REAL*8 FW_CC_FO_RESID */
/*      EXTERNAL XLKT22, FW_CC_FO_RESID, FDBLRGF */
/* C     *****************************FORMATS****************************** */
/* 50    FORMAT(/,' *BUG:XXX* Positive residual not found for FW_CC_FO') */
/* 52    FORMAT(/,' *BUG:XXX* Negative residual not found for FW_CC_FO') */
/* 54   FORMAT(' *BUG:XXX* SIGN CHNG ON ENTRY BUT FDBLRGF CLAIMS NONE IN', */
/*     A       ' FIND_FW_CC_FO.') */
/* 60   FORMAT(' *BUG:XXX* FDBLRGF ITERATION>100 IN FIND_FW_CC_FO') */
/* C*********************************************************************** */
/*      FLAG = 0 */
/*      TWOG = 2.D0*GRAV */

/* C     Increment the section 1 limit */

/*      H1FWUL = H1FWULA */
/* C     Find elements at section 1 */
/*      WRITE(STDOUT,*) ' H1=',H1FWUL */

/*      CALL XLKT22 */
/*     I           (APPTAB, */
/*     M            SNGL(H1FWUL + HDATUM - Z1B), */
/*     O            A1, T1, DT1, J1, K1, DK1, BETA1, DBETA1, ALPHA1, */
/*     O            DALPHA1, QC1) */

/* C     Find elements at section 2 */
/*      CALL XLKT22 */
/*     I           (XSEC_ADRS(1), */
/*     M            SNGL(HG), */
/*     O            AB, TB, DTB, JB, KB, DKB, BETAB, DBETAB, ALPHAB, */
/*     O            DALPHAB, QCB) */

/* C     Compute loss term for approach reach. */

/*      L12 = STATION(1) - STATION_1 */
/*      LOSS = L12*QD**2/(DBLE(K1)*DBLE(KB)) */

/* C     Compute the RHS of the equation.  Put in E_AT_1 */

/*      E_AT_1 = DBLE(ALPHA1)*(QD/DBLE(A1))**2/TWOG + H1FWUL */
/*     A          + SIN_THETA*HG  - LOSS */

/* C     Compute the velocity head factor at the vena contract */

/*      M1 = (QD/(BG*HG))**2/TWOG */


/* C     Rescale by HG */

/*      E_AT_1 = E_AT_1/HG */

/*      M1 = M1/HG */


/* C     Now setup for solving for FW_CC_FO */

/* C     Explore the function */

/* C      YR = 0.01D0 */
/* C      DO 90 I= 1,101 */
/* C        WRITE(STDOUT,*) ' YR=',YR,' RESID=',FW_CC_FO_RESID(YR) */
/* C        YR = YR + 0.01D0 */
/* C90    CONTINUE */
/* C     SEARCH FOR A positive RESIDUAL */
/*      YR = 1.1D0 */
/*      YL = -1.D0 */
/* 100  CONTINUE */
/*        FR = FW_CC_FO_RESID(YR) */
/* C        WRITE(STDOUT,*) ' YR=',YR,' FR=',FR */
/*        IF(FR.GE.0.0D0) THEN */
/*          GOTO 110 */
/*        ELSE */
/*          IF(FR.GT.-1.D5) THEN */
/*            YL = YR */
/*            FL = FR */
/*          ENDIF */
/*          YR = YR  - 0.01D0 */
/*          IF(YR.LT.0.01D0) THEN */
/*            WRITE(STDOUT,50) */
/*            FLAG = 1 */
/*            GOTO 1000 */
/*          ENDIF */
/*          GOTO 100 */
/*        ENDIF */
/* 110  CONTINUE */
/* C     POSITIVE RESIDUAL FOUND- SEARCH FOR NEGATIVE RESIDUAL */

/*      IF(YL.LT.0.0D0) THEN */
/*        YL = YR */
/* 120    CONTINUE */
/*          YL = YL - 0.01D0 */
/*          IF(YL.LE.0.01D0) THEN */
/*            WRITE(STDOUT, 52) */
/*            FLAG = 1 */
/*            GOTO 1000 */
/*          ENDIF */
/*          FL = FW_CC_FO_RESID(YL) */
/* C        WRITE(STDOUT,*) ' YL=',YL,' FL=',FL */
/*          IF(FL.LE.0.0D0) THEN */
/*            GOTO 130 */
/*          ELSE */
/*            FR = FL */
/*            YR = YL */
/*            GOTO 120 */
/*          ENDIF */
/* 130    CONTINUE */
/*      ENDIF */

/* C     WE HAVE A SIGN CHANGE OR ONE OR BOTH POINTS HAVE ZERO RESIDUAL */

/* C      WRITE(STDOUT,*) ' Calling FDBLRGF with: YL=',YL,' FL=',FL */
/* C      WRITE(STDOUT,*) ' YR=',YR,' FR=',FR */

/*      CALL FDBLRGF */
/*     I            (EPSARG, EPSF, FW_CC_FO_RESID, */
/*     M             YL, YR, FL, FR, */
/*     O             FW_CC, FLAG) */


/* C      WRITE(STDOUT,*) ' FL=',FL */
/* C      WRITE(STDOUT,*) ' Return from FDBLRGF with: FLAG=',FLAG */
/* C      WRITE(STDOUT,*) ' FW_CC_FO =',FW_CC */
/*      IF(FLAG.EQ.3)  FLAG = 0 */

/* C     Compute sequent depth for a jump from the jet implied by */
/* C     FW_CC. */

/*      FR2VC = QD**2/(BG**2*(HG*FW_CC)**3*GRAV) */
/*      YSEQ = FW_CC*HG*0.5D0*(SQRT(1.D0 + 8.D0*FR2VC) - 1.D0) */

/*      IF(YSEQ.GT.HG) THEN */
/*        WRITE(STDOUT,*) ' FO passed test' */
/*        FOFLAG = 1 */
/*      ELSE */
/*        FOFLAG = 0 */
/*      ENDIF */

/* C      WRITE(STDOUT,*) ' YSEQ=',YSEQ,' HG=',HG */
/* C     Compute a coefficient of discharge applied to the velocity head */
/* C     at the vena contracta to approximate the losses for all heads for */
/* C     this gate opening. */



/*      CD = SQRT(1.D0/(1.D0 + TWOG*L12*(HG*BG*FW_CC)**2/ */
/*     A                      (DBLE(K1)*DBLE(KB)))) */


/*      WRITE(STDOUT,*) ' CD=',CD */

/* C     Try to compute Q from the basic FO solution */

/*      Q = HG*BG*FW_CC*SQRT((TWOG*(H1FWUL - FW_CC*HG + SIN_THETA*HG))/ */
/*     A   (1. - ALPHA1*(HG*BG*FW_CC/A1)**2 + */
/*     B   TWOG*(HG*BG*FW_CC)**2*L12/(K1*KB))) */

/*      WRITE(STDOUT,*) ' Q FO inverse=',Q */


/*      IF(FLAG.EQ.1) THEN */
/*        WRITE(STDOUT, 54) */
/*      ELSEIF(FLAG.EQ.2) THEN */
/*        WRITE(STDOUT,60) */
/*      ENDIF */

/* 1000  CONTINUE */
/*      RETURN */
/*      END */



/* SOURCE ufgculv.for:2041 */
/*<       real*8functionfw_cc_so_resid(cc) >*/
doublereal feq_gen_fw_cc_so_resid_d_(doublereal *cc)
{
    /* System generated locals */
    doublereal ret_val, feq_gen_d_d_1;

    /* Local variables */
    doublereal ajc, yvc, jvcl, jvcr;
    extern /* Subroutine */ int feq_gen_lkt_jda_d_(integer *, doublereal *, doublereal 
	    *, doublereal *, doublereal *);

/*     Compute values for the free-weir contraction coefficient */
/*     residual function. */
/* SOURCE ufgculv.for:2047 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:2049 */
/*<       real*8cc >*/
/*     Local variables */
/* SOURCE ufgculv.for:2053 */
/*<       real*8jvcr,jvcl,yvc,ajc >*/
/* INCLUDE ufgculv.for:2055 */
/*     Common block to transfer data to the residual function */
/*     used to solve the the free weir limit contraction */
/*     coefficient. */
/* SOURCE fwcc.cmn:5 */
/*<       real*8econ,efac,m1,m2,hgt,staup >*/
/* SOURCE fwcc.cmn:7 */
/*<       common/fwcc_c/econ,efac,m1,m2,hgt,staup >*/
/* *********************************************************************** */
/* SOURCE ufgculv.for:2057 */
/*<       yvc=econ-efac/cc**2 >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = *cc;
    yvc = feq_gen_fwcc_c_d_1.econ - feq_gen_fwcc_c_d_1.efac / (feq_gen_d_d_1 * feq_gen_d_d_1);
/* SOURCE ufgculv.for:2058 */
/*<       calllkt_jda(0,staup+hgt,yvc,ajc,jvcl) >*/
    feq_gen_d_d_1 = feq_gen_fwcc_c_d_1.staup + feq_gen_fwcc_c_d_1.hgt;
    feq_gen_lkt_jda_d_(&feq_gen_c_d_0, &feq_gen_d_d_1, &yvc, &ajc, &jvcl);
/* SOURCE ufgculv.for:2062 */
/*<       jvcr=m1-m2/cc >*/
    jvcr = feq_gen_fwcc_c_d_1.m1 - feq_gen_fwcc_c_d_1.m2 / *cc;
/* SOURCE ufgculv.for:2064 */
/*<       fw_cc_so_resid=(jvcr-jvcl)/jvcr >*/
    ret_val = (jvcr - jvcl) / jvcr;
/* SOURCE ufgculv.for:2066 */
/*<       return >*/
    return ret_val;
/* SOURCE ufgculv.for:2067 */
/*<       end >*/
} /* fw_cc_so_resid__ */




/* SOURCE ufgculv.for:2071 */
/*<        >*/
/* Subroutine */ int feq_gen_find_fw_cc_so_d_(integer *stdout, doublereal *epsarg, 
	doublereal *epsf, doublereal *epsabs, integer *apptab, doublereal *
	grav, doublereal *z1fwula, doublereal *z1b, doublereal *feq_gen_station_1_d_, 
	doublereal *hg, doublereal *bg, doublereal *y2hat, doublereal *cd, 
	doublereal *feq_gen_fw_cc_d_, integer *soflag, integer *feq_gen_flag_d_)
{
    /* Format strings */
    static char fmt_54[] = "(\002 *BUG:XXX* SIGN CHNG ON ENTRY BUT FDBLRGF C\
LAIMS NONE IN\002,\002 FIND_FW_CC_SO.\002)";
    static char fmt_60[] = "(\002 *BUG:XXX* FDBLRGF ITERATION>100 IN FIND_FW\
_CC_SO\002)";

    /* System generated locals */
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(), s_wsfe(cilist *), e_wsfe();

    /* Local variables */
    real a, j, a1, j1, k1, t1;
    doublereal ab, jb, l12, fl;
    real tb;
    doublereal fr;
    real tp;
    doublereal yl, yr;
    real dk1, qc1, dt1, dkb, qcb, dtb;
    doublereal yvc, twog, loss;
    real beta1, betab;
    doublereal ccmin;
    extern /* Subroutine */ int xlkt22_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *);
    real kloss, dbeta1, alpha1, dbetab, alphab;
    doublereal z1fwul;
    extern doublereal feq_gen_fw_cc_so_resid_d_(doublereal *);
    real dalpha1, dalphab;
    extern /* Subroutine */ int fdblrgf_(doublereal *, doublereal *, FeqCallback1, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *), feq_gen_lkt_jda_d_(integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__280 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__281 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__282 = { 0, 0, 0, fmt_60, 0 };


/*     Find the contraction coefficient that forces the SO equation */
/*     to produce the same flow as the flow at the FW limit. */
/* SOURCE ufgculv.for:2079 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:2081 */
/*<       integerapptab,stdout,flag,soflag >*/
/* SOURCE ufgculv.for:2083 */
/*<        >*/
/* INCLUDE ufgculv.for:2087 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/* INCLUDE ufgculv.for:2088 */
/*     Common block to transfer data to the residual function */
/*     used to solve the the free weir limit contraction */
/*     coefficient. */
/* SOURCE fwcc.cmn:5 */
/*<       real*8econ,efac,m1,m2,hgt,staup >*/
/* SOURCE fwcc.cmn:7 */
/*<       common/fwcc_c/econ,efac,m1,m2,hgt,staup >*/
/*     Local variables */
/* SOURCE ufgculv.for:2093 */
/*<       real*8twog,yl,yr,fl,fr,yvc,l12,ccmin,z1fwul,loss,ab,jb >*/
/* SOURCE ufgculv.for:2096 */
/*<        >*/
/*     External program units */
/* SOURCE ufgculv.for:2102 */
/*<       real*8fw_cc_so_resid >*/
/* SOURCE ufgculv.for:2103 */
/*<       externalxlkt22,fw_cc_so_resid,fdblrgf >*/
/*     *****************************FORMATS****************************** */
/* SOURCE ufgculv.for:2105 */
/*<    50 format(/,' *BUG:XXX* Positive residual not found for FW_CC_SO') >*/
/* SOURCE ufgculv.for:2106 */
/*<    52 format(/,' *BUG:XXX* Negative residual not found for FW_CC_SO') >*/
/* SOURCE ufgculv.for:2107 */
/*<    54  >*/
/* SOURCE ufgculv.for:2109 */
/*<    60 format(' *BUG:XXX* FDBLRGF ITERATION>100 IN FIND_FW_CC_SO') >*/
/* *********************************************************************** */
/* SOURCE ufgculv.for:2111 */
/*<       flag=0 >*/
/* L50: */
/* L52: */
/* L54: */
/* L60: */
    *feq_gen_flag_d_ = 0;
/* SOURCE ufgculv.for:2112 */
/*<       twog=2.d0*grav >*/
    twog = *grav * 2.;
/* SOURCE ufgculv.for:2114 */
/*<       staup=station(1) >*/
    feq_gen_fwcc_c_d_1.staup = ufgc1_1.station[0];
/* SOURCE ufgculv.for:2115 */
/*<       hgt=hg >*/
    feq_gen_fwcc_c_d_1.hgt = *hg;
/* SOURCE ufgculv.for:2116 */
/*<       z1fwul=z1fwula >*/
    z1fwul = *z1fwula;
/*     Find elements at section 1 */
/* SOURCE ufgculv.for:2119 */
/*<       tp=sngl(z1fwul-z1b) >*/
    tp = (real) (z1fwul - *z1b);
/* SOURCE ufgculv.for:2120 */
/*<        >*/
    xlkt22_(apptab, &tp, &a1, &t1, &dt1, &j1, &k1, &dk1, &beta1, &dbeta1, &
	    alpha1, &dalpha1, &qc1);
/*     Find elements at section 2 at the depth computed from SFWSP */
/*     excluding the distributed entrance losses. */
/* SOURCE ufgculv.for:2129 */
/*<       calllkt_jda(1,staup+hgt,y2hat,ab,jb) >*/
    feq_gen_d_d_1 = feq_gen_fwcc_c_d_1.staup + feq_gen_fwcc_c_d_1.hgt;
    feq_gen_lkt_jda_d_(&feq_gen_c_d_1, &feq_gen_d_d_1, y2hat, &ab, &jb);
/*     Find elements at the level used for computing approach friction */
/*     losses in CULVERT */
/* SOURCE ufgculv.for:2136 */
/*<       tp=sngl(hg) >*/
    tp = (real) (*hg);
/* SOURCE ufgculv.for:2137 */
/*<        >*/
    xlkt22_(ufgc1_1.feq_gen_xsec_adrs_d_, &tp, &a, &tb, &dtb, &j, &kloss, &dkb, &betab,
	     &dbetab, &alphab, &dalphab, &qcb);
/*     Compute loss term for approach reach. */
/* SOURCE ufgculv.for:2145 */
/*<       l12=station(1)-station_1 >*/
    l12 = ufgc1_1.station[0] - *feq_gen_station_1_d_;
/* SOURCE ufgculv.for:2147 */
/*<       loss=l12*qd**2/(dble(k1)*dble(kloss)) >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = ufgc1_1.qd;
    loss = l12 * (feq_gen_d_d_1 * feq_gen_d_d_1) / ((doublereal) k1 * (doublereal) kloss);
/* SOURCE ufgculv.for:2149 */
/*<        >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = ufgc1_1.qd / (doublereal) a1;
    feq_gen_fwcc_c_d_1.econ = ((doublereal) alpha1 * (feq_gen_d_d_1 * feq_gen_d_d_1) / twog + z1fwul + 
	    ufgc1_1.feq_gen_sin_theta_d_ * *hg - ufgc1_1.feq_gen_invert_z_d_[0] - loss) / 
	    ufgc1_1.feq_gen_cos_theta_d_;
/* SOURCE ufgculv.for:2152 */
/*<       efac=(qd/(hg*bg))**2/(twog*cos_theta) >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = ufgc1_1.qd / (*hg * *bg);
    feq_gen_fwcc_c_d_1.efac = feq_gen_d_d_1 * feq_gen_d_d_1 / (twog * ufgc1_1.feq_gen_cos_theta_d_);
/*     Compute the first momentum based term */
/* SOURCE ufgculv.for:2157 */
/*<       m1=qd**2/(grav*ab*cos_theta)+jb >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = ufgc1_1.qd;
    feq_gen_fwcc_c_d_1.m1 = feq_gen_d_d_1 * feq_gen_d_d_1 / (*grav * ab * ufgc1_1.feq_gen_cos_theta_d_) + jb;
/*     Compute the second momentum based term */
/* SOURCE ufgculv.for:2161 */
/*<       m2=qd**2/(grav*hg*bg*cos_theta) >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = ufgc1_1.qd;
    feq_gen_fwcc_c_d_1.m2 = feq_gen_d_d_1 * feq_gen_d_d_1 / (*grav * *hg * *bg * ufgc1_1.feq_gen_cos_theta_d_);
/* SOURCE ufgculv.for:2164 */
/*<       ccmin=max(sqrt(efac/econ),m2/m1) >*/
/* Computing MAX */
    feq_gen_d_d_1 = sqrt(feq_gen_fwcc_c_d_1.efac / feq_gen_fwcc_c_d_1.econ), feq_gen_d_d_2 = feq_gen_fwcc_c_d_1.m2 / 
	    feq_gen_fwcc_c_d_1.m1;
    ccmin = max(feq_gen_d_d_1,feq_gen_d_d_2);
/* SOURCE ufgculv.for:2166 */
/*<       ccmin=1.0001d0*ccmin >*/
    ccmin *= 1.0001;
/*     Now setup for solving for FW_CC */
/*     Explore the function */
/*      YR = 0.01D0 */
/*      DO 90 I= 1,101 */
/*        WRITE(STDOUT,*) ' YR=',YR,' RESID=',FW_CC_SO_RESID(YR) */
/*        YR = YR + 0.01D0 */
/* 90    CONTINUE */
/*     SEARCH FOR A positive RESIDUAL */
/* SOURCE ufgculv.for:2180 */
/*<       yr=1.1d0 >*/
    yr = 1.1;
/* SOURCE ufgculv.for:2181 */
/*<       yl=-1.d0 >*/
    yl = -1.;
/* SOURCE ufgculv.for:2182 */
/*<   100 continue >*/
L100:
/* SOURCE ufgculv.for:2183 */
/*<       fr=fw_cc_so_resid(yr) >*/
    fr = feq_gen_fw_cc_so_resid_d_(&yr);
/*        WRITE(STDOUT,*) ' YR=',YR,' FR=',FR */
/* SOURCE ufgculv.for:2185 */
/*<       if(fr.ge.0.0d0)then >*/
    if (fr >= 0.) {
/* SOURCE ufgculv.for:2186 */
/*<       goto110 >*/
	goto L110;
/* SOURCE ufgculv.for:2187 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:2188 */
/*<       if(fr.gt.-1.d5)then >*/
	if (fr > -1e5) {
/* SOURCE ufgculv.for:2189 */
/*<       yl=yr >*/
	    yl = yr;
/* SOURCE ufgculv.for:2190 */
/*<       fl=fr >*/
	    fl = fr;
/* SOURCE ufgculv.for:2191 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:2192 */
/*<       yr=yr-0.1d0 >*/
	yr += -.1;
/* SOURCE ufgculv.for:2193 */
/*<       if(yr.lt.ccmin)then >*/
	if (yr < ccmin) {
/*            WRITE(STDOUT,50) */
/* SOURCE ufgculv.for:2195 */
/*<       flag=1 >*/
	    *feq_gen_flag_d_ = 1;
/* SOURCE ufgculv.for:2196 */
/*<       goto1000 >*/
	    goto L1000;
/* SOURCE ufgculv.for:2197 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:2198 */
/*<       goto100 >*/
	goto L100;
/* SOURCE ufgculv.for:2199 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:2200 */
/*<   110 continue >*/
L110:
/*     POSITIVE RESIDUAL FOUND- SEARCH FOR NEGATIVE RESIDUAL */
/* SOURCE ufgculv.for:2203 */
/*<       if(yl.lt.0.0d0)then >*/
    if (yl < 0.) {
/* SOURCE ufgculv.for:2204 */
/*<       yl=yr >*/
	yl = yr;
/* SOURCE ufgculv.for:2205 */
/*<   120 continue >*/
L120:
/* SOURCE ufgculv.for:2206 */
/*<       yl=yl-0.1d0 >*/
	yl += -.1;
/* SOURCE ufgculv.for:2207 */
/*<       if(yl.le.ccmin)then >*/
	if (yl <= ccmin) {
/*            WRITE(STDOUT, 52) */
/* SOURCE ufgculv.for:2209 */
/*<       flag=1 >*/
	    *feq_gen_flag_d_ = 1;
/* SOURCE ufgculv.for:2210 */
/*<       goto1000 >*/
	    goto L1000;
/* SOURCE ufgculv.for:2211 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:2212 */
/*<       fl=fw_cc_so_resid(yl) >*/
	fl = feq_gen_fw_cc_so_resid_d_(&yl);
/*        WRITE(STDOUT,*) ' YL=',YL,' FL=',FL */
/* SOURCE ufgculv.for:2214 */
/*<       if(fl.le.0.0d0)then >*/
	if (fl <= 0.) {
/* SOURCE ufgculv.for:2215 */
/*<       goto130 >*/
	    goto L130;
/* SOURCE ufgculv.for:2216 */
/*<       else >*/
	} else {
/* SOURCE ufgculv.for:2217 */
/*<       fr=fl >*/
	    fr = fl;
/* SOURCE ufgculv.for:2218 */
/*<       yr=yl >*/
	    yr = yl;
/* SOURCE ufgculv.for:2219 */
/*<       goto120 >*/
	    goto L120;
/* SOURCE ufgculv.for:2220 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:2221 */
/*<   130 continue >*/
L130:
/* SOURCE ufgculv.for:2222 */
/*<       endif >*/
	;
    }
/*     WE HAVE A SIGN CHANGE OR ONE OR BOTH POINTS HAVE ZERO RESIDUAL */
/*      WRITE(STDOUT,*) ' Calling FDBLRGF with: YL=',YL,' FL=',FL */
/*      WRITE(STDOUT,*) ' YR=',YR,' FR=',FR */
/* SOURCE ufgculv.for:2229 */
/*<       callfdblrgf(epsarg,epsf,fw_cc_so_resid,yl,yr,fl,fr,fw_cc,flag) >*/
    fdblrgf_(epsarg, epsf, feq_gen_fw_cc_so_resid_d_, &yl, &yr, &fl, &fr, 
	    feq_gen_fw_cc_d_, feq_gen_flag_d_);
/* SOURCE ufgculv.for:2234 */
/*<       if(flag.eq.3)flag=0 >*/
    if (*feq_gen_flag_d_ == 3) {
	*feq_gen_flag_d_ = 0;
    }
/* SOURCE ufgculv.for:2236 */
/*<       yvc=sqrt(m1-m2/fw_cc) >*/
    yvc = sqrt(feq_gen_fwcc_c_d_1.m1 - feq_gen_fwcc_c_d_1.m2 / *feq_gen_fw_cc_d_);
/*      WRITE(STDOUT,*) ' Return from FDBLRGF with: FLAG=',FLAG */
/*      WRITE(STDOUT,*) ' FW_CC_SO =',FW_CC,' YVC=',YVC */
/* SOURCE ufgculv.for:2239 */
/*<       soflag=0 >*/
    *soflag = 0;
/* SOURCE ufgculv.for:2240 */
/*<       if(yvc.gt.hg*fw_cc)then >*/
    if (yvc > *hg * *feq_gen_fw_cc_d_) {
/* SOURCE ufgculv.for:2241 */
/*<       write(stdout,*)' SO flow passed test.' >*/
	feq_gen_io_d__280.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__280);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" SO flow passed test."), (ftnlen)21);
	e_wsle();
/* SOURCE ufgculv.for:2242 */
/*<       soflag=1 >*/
	*soflag = 1;
/* SOURCE ufgculv.for:2243 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:2245 */
/*<       if(flag.eq.1)then >*/
    if (*feq_gen_flag_d_ == 1) {
/* SOURCE ufgculv.for:2246 */
/*<       write(stdout,54) >*/
	feq_gen_io_d__281.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__281);
	e_wsfe();
/* SOURCE ufgculv.for:2247 */
/*<       elseif(flag.eq.2)then >*/
    } else if (*feq_gen_flag_d_ == 2) {
/* SOURCE ufgculv.for:2248 */
/*<       write(stdout,60) >*/
	feq_gen_io_d__282.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__282);
	e_wsfe();
/* SOURCE ufgculv.for:2249 */
/*<       endif >*/
    }
/*     Compute a coefficient of discharge applied to the velocity head */
/*     at the vena contracta to approximate the losses for all heads for */
/*     this gate opening. */
/* SOURCE ufgculv.for:2257 */
/*<        >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = *hg * *bg * *feq_gen_fw_cc_d_;
    *cd = sqrt(1. / (twog * l12 * (feq_gen_d_d_1 * feq_gen_d_d_1) / ((doublereal) k1 * (
	    doublereal) kloss) + 1.));
/*      WRITE(STDOUT,*) ' CD=',CD, ' A1=',A1 */
/* SOURCE ufgculv.for:2262 */
/*<       return >*/
    return 0;
/* SOURCE ufgculv.for:2264 */
/*<  1000 continue >*/
L1000:
/*     Compute a loss CD using a contraction coef of 1.0 */
/* SOURCE ufgculv.for:2266 */
/*<       cd=sqrt(1.d0/(1.d0+twog*l12*(hg*bg)**2/(dble(k1)*dble(kloss)))) >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = *hg * *bg;
    *cd = sqrt(1. / (twog * l12 * (feq_gen_d_d_1 * feq_gen_d_d_1) / ((doublereal) k1 * (
	    doublereal) kloss) + 1.));
/* SOURCE ufgculv.for:2268 */
/*<       fw_cc=0.d0 >*/
    *feq_gen_fw_cc_d_ = 0.;
/* SOURCE ufgculv.for:2269 */
/*<       return >*/
    return 0;
/* SOURCE ufgculv.for:2270 */
/*<       end >*/
} /* find_fw_cc_so__ */




/* SOURCE ufgculv.for:2276 */
/*<       integerfunctionfind_barrel_interval(x) >*/
integer feq_gen_find_barrel_interval_d_(doublereal *x)
{
    /* Initialized data */

    static integer oldloc = 1;

    /* System generated locals */
    integer ret_val;

    /* Local variables */
    integer loc;

/*     Find the barrel interval containing X. */
/*     LOC points to the index for the upstream end of the barrel. */
/* SOURCE ufgculv.for:2282 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:2284 */
/*<       real*8x >*/
/* INCLUDE ufgculv.for:2286 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/*     Local variables */
/* SOURCE ufgculv.for:2290 */
/*<       integeroldloc,loc >*/
/* *********************************************************************** */
/* SOURCE ufgculv.for:2291 */
/*<       dataoldloc/1/ >*/
/* SOURCE ufgculv.for:2294 */
/*<   100 continue >*/
L100:
/* SOURCE ufgculv.for:2295 */
/*<       if(x.ge.station(oldloc))then >*/
    if (*x >= ufgc1_1.station[oldloc - 1]) {
/* SOURCE ufgculv.for:2296 */
/*<       if(x.le.station(oldloc+1))then >*/
	if (*x <= ufgc1_1.station[oldloc]) {
/* SOURCE ufgculv.for:2297 */
/*<       loc=oldloc >*/
	    loc = oldloc;
/* SOURCE ufgculv.for:2298 */
/*<       goto110 >*/
	    goto L110;
/* SOURCE ufgculv.for:2299 */
/*<       else >*/
	} else {
/* SOURCE ufgculv.for:2300 */
/*<       oldloc=oldloc+1 >*/
	    ++oldloc;
/* SOURCE ufgculv.for:2301 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:2302 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:2303 */
/*<       oldloc=oldloc-1 >*/
	--oldloc;
/* SOURCE ufgculv.for:2304 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:2305 */
/*<       goto100 >*/
    goto L100;
/* SOURCE ufgculv.for:2306 */
/*<   110 continue >*/
L110:
/* SOURCE ufgculv.for:2307 */
/*<       find_barrel_interval=loc >*/
    ret_val = loc;
/* SOURCE ufgculv.for:2308 */
/*<       return >*/
    return ret_val;
/* SOURCE ufgculv.for:2309 */
/*<       end >*/
} /* find_barrel_interval__ */




/* SOURCE ufgculv.for:2313 */
/*<       subroutineset_barrel_interval(i) >*/
/* Subroutine */ int feq_gen_set_barrel_interval_d_(integer *feq_gen_i_d_)
{
/*     Set the values needed for integration and computations in the */
/*     barrel cross section interval with upstream-end index I. */
/* SOURCE ufgculv.for:2319 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:2320 */
/*<       integeri >*/
/* INCLUDE ufgculv.for:2322 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/* *********************************************************************** */
/* SOURCE ufgculv.for:2325 */
/*<       x_l=station(i) >*/
    ufgc1_1.feq_gen_x_l_d_ = ufgc1_1.station[*feq_gen_i_d_ - 1];
/* SOURCE ufgculv.for:2326 */
/*<       z_l=invert_z(i) >*/
    ufgc1_1.feq_gen_z_l_d_ = ufgc1_1.feq_gen_invert_z_d_[*feq_gen_i_d_ - 1];
/* SOURCE ufgculv.for:2327 */
/*<       adrs_l=xsec_adrs(i) >*/
    ufgc1_1.feq_gen_adrs_l_d_ = ufgc1_1.feq_gen_xsec_adrs_d_[*feq_gen_i_d_ - 1];
/* SOURCE ufgculv.for:2328 */
/*<       ymax_l=xsec_ymax(i) >*/
    ufgc1_1.feq_gen_ymax_l_d_ = ufgc1_1.feq_gen_xsec_ymax_d_[*feq_gen_i_d_ - 1];
/* SOURCE ufgculv.for:2329 */
/*<       x_r=station(i+1) >*/
    ufgc1_1.feq_gen_x_r_d_ = ufgc1_1.station[*feq_gen_i_d_];
/* SOURCE ufgculv.for:2330 */
/*<       z_r=invert_z(i+1) >*/
    ufgc1_1.feq_gen_z_r_d_ = ufgc1_1.feq_gen_invert_z_d_[*feq_gen_i_d_];
/* SOURCE ufgculv.for:2331 */
/*<       adrs_r=xsec_adrs(i+1) >*/
    ufgc1_1.feq_gen_adrs_r_d_ = ufgc1_1.feq_gen_xsec_adrs_d_[*feq_gen_i_d_];
/* SOURCE ufgculv.for:2332 */
/*<       ymax_r=xsec_ymax(i+1) >*/
    ufgc1_1.feq_gen_ymax_r_d_ = ufgc1_1.feq_gen_xsec_ymax_d_[*feq_gen_i_d_];
/*     SLOPE_FLAG =0: slope is constant between cross sections. */
/*     SLOPE_FLAG >0: slope varies between cross sections. */
/* SOURCE ufgculv.for:2336 */
/*<       slope_flag=invert_slope_cat(i)+invert_slope_cat(i+1) >*/
    ufgc1_1.feq_gen_slope_flag_d_ = ufgc1_1.feq_gen_invert_slope_cat_d_[*feq_gen_i_d_ - 1] + 
	    ufgc1_1.feq_gen_invert_slope_cat_d_[*feq_gen_i_d_];
/* SOURCE ufgculv.for:2337 */
/*<       pris_flag=channel_variation(i) >*/
    ufgc1_1.feq_gen_pris_flag_d_ = ufgc1_1.feq_gen_channel_variation_d_[*feq_gen_i_d_ - 1];
/* SOURCE ufgculv.for:2338 */
/*<       if(slope_flag.eq.0)then >*/
    if (ufgc1_1.feq_gen_slope_flag_d_ == 0) {
/* SOURCE ufgculv.for:2339 */
/*<       sin_theta=sine_theta(i) >*/
	ufgc1_1.feq_gen_sin_theta_d_ = ufgc1_1.feq_gen_sine_theta_d_[*feq_gen_i_d_ - 1];
/* SOURCE ufgculv.for:2340 */
/*<       cos_theta=cosine_theta(i) >*/
	ufgc1_1.feq_gen_cos_theta_d_ = ufgc1_1.feq_gen_cosine_theta_d_[*feq_gen_i_d_ - 1];
/* SOURCE ufgculv.for:2341 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:2342 */
/*<       return >*/
    return 0;
/* SOURCE ufgculv.for:2343 */
/*<       end >*/
} /* set_barrel_interval__ */




/* SOURCE ufgculv.for:2347 */
/*<        >*/
/* Subroutine */ int sfwsp_(integer *stdout, doublereal *xs, doublereal *xe, 
	doublereal *ys, doublereal *eps, FeqCallback2 p, FeqCallback2 f, FeqCallback4 feq_gen_find_ycynym_d_, 
	integer *nmax, integer *ns, integer *ne, doublereal *feq_storage_xvec, doublereal 
	*feq_storage_yvec, doublereal *feq_storage_ycvec, doublereal *feq_storage_ynvec, integer *eflag)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    doublereal feq_gen_d_d_1;

    /* Local variables */
    integer feq_gen_i_d_, n, ie, is, loc, dir;
    extern /* Subroutine */ int feq_gen_set_barrel_interval_d_(integer *);
    doublereal epsf;
    extern integer feq_gen_find_barrel_interval_d_(doublereal *);
    integer rflag;
    doublereal hmina, dhlim, hmaxa, ysfac, ymaxa, feq_gen_loc_xe_d_, epsabs, epsarg, 
	    feq_gen_loc_xs_d_, feq_gen_loc_ys_d_, ycrita;
    integer extrap;
    doublereal ynorma;
    extern /* Subroutine */ int imptrap_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, FeqCallback2, FeqCallback2, FeqCallback4, 
	    integer *, doublereal *, doublereal *, integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *)
	    ;

/*     Compute a steady-flow water-surface profile.  See IMPTRAP */
/*     for definition of dummy arguments. */
/* SOURCE ufgculv.for:2355 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:2357 */
/*<       integerns,ne,nmax,eflag,stdout >*/
/* SOURCE ufgculv.for:2358 */
/*<       real*8xs,xe,ys,eps >*/
/* SOURCE ufgculv.for:2359 */
/*<       real*8xvec(nmax),yvec(nmax),ycvec(nmax),ynvec(nmax) >*/
/* SOURCE ufgculv.for:2361 */
/*<       real*8f,p >*/
/* SOURCE ufgculv.for:2362 */
/*<       externalf,p,find_ycynym >*/
/* INCLUDE ufgculv.for:2364 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/*     Local variables */
/* SOURCE ufgculv.for:2368 */
/*<       integerdir,i,loc,n,is,ie,extrap,rflag >*/
/* SOURCE ufgculv.for:2369 */
/*<        >*/
/*     Called program units */
/* SOURCE ufgculv.for:2375 */
/*<       integerfind_barrel_interval >*/
/* SOURCE ufgculv.for:2376 */
/*<       externalfind_barrel_interval,set_barrel_interval >*/
/* *********************************************************************** */
/*     Set the local values to control the computation */
/* SOURCE ufgculv.for:2381 */
/*<       epsarg=0.01d0*eps >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> ynvec(feq_storage_ynvec, 1);

    feq::IndexedPointer<doublereal> ycvec(feq_storage_ycvec, 1);

    feq::IndexedPointer<doublereal> yvec(feq_storage_yvec, 1);

    feq::IndexedPointer<doublereal> xvec(feq_storage_xvec, 1);

    /* Function Body */
    epsarg = *eps * .01;
/* SOURCE ufgculv.for:2382 */
/*<       epsf=0.00001d0*eps >*/
    epsf = *eps * 1e-5;
/* SOURCE ufgculv.for:2383 */
/*<       epsabs=0.0001d0*eps >*/
    epsabs = *eps * 1e-4;
/* SOURCE ufgculv.for:2385 */
/*<       hmina=0.01d0*ys >*/
    hmina = *ys * .01;
/* SOURCE ufgculv.for:2386 */
/*<       if(hmina.gt.0.001d0)hmina=0.0001d0 >*/
    if (hmina > .001) {
	hmina = 1e-4;
    }
/* SOURCE ufgculv.for:2387 */
/*<       hmaxa=0.2d0*abs(xe-xs) >*/
    hmaxa = (feq_gen_d_d_1 = *xe - *xs, abs(feq_gen_d_d_1)) * .2;
/* SOURCE ufgculv.for:2389 */
/*<       ysfac=1.0d0 >*/
    ysfac = 1.;
/* SOURCE ufgculv.for:2390 */
/*<       dhlim=2.0d0 >*/
    dhlim = 2.;
/* SOURCE ufgculv.for:2391 */
/*<       extrap=1 >*/
    extrap = 1;
/*     Set the direction computation.  Note that we now require that the */
/*     stationing increase downstream.  Thus we can infer the direction */
/*     of computation from the relationship between the starting and */
/*     ending station. */
/* SOURCE ufgculv.for:2398 */
/*<       if(xs.gt.xe)then >*/
    if (*xs > *xe) {
/*       We are computing upstream on a subcritical profile. */
/* SOURCE ufgculv.for:2400 */
/*<       dir=-1 >*/
	dir = -1;
/* SOURCE ufgculv.for:2401 */
/*<       ne=nmax >*/
	*ne = *nmax;
/* SOURCE ufgculv.for:2402 */
/*<       n=ne >*/
	n = *ne;
/* SOURCE ufgculv.for:2403 */
/*<       else >*/
    } else {
/*       We are computing downstream on a super critical profile. */
/* SOURCE ufgculv.for:2405 */
/*<       dir=1 >*/
	dir = 1;
/* SOURCE ufgculv.for:2406 */
/*<       ns=1 >*/
	*ns = 1;
/* SOURCE ufgculv.for:2407 */
/*<       n=ns >*/
	n = *ns;
/* SOURCE ufgculv.for:2408 */
/*<       endif >*/
    }
/*     Find the interval in the channel description that contains */
/*     the starting position. */
/* SOURCE ufgculv.for:2413 */
/*<       loc=find_barrel_interval(xs) >*/
    loc = feq_gen_find_barrel_interval_d_(xs);
/*     LOC gives the index that is at or upstream of the starting */
/*     location.  Start the loop over the channel description. */
/* SOURCE ufgculv.for:2419 */
/*<       if(dir.gt.0)then >*/
    if (dir > 0) {
/* SOURCE ufgculv.for:2420 */
/*<       is=loc >*/
	is = loc;
/* SOURCE ufgculv.for:2421 */
/*<       ie=nxs-1 >*/
	ie = ufgc1_1.nxs - 1;
/* SOURCE ufgculv.for:2422 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:2423 */
/*<       is=loc >*/
	is = loc;
/* SOURCE ufgculv.for:2424 */
/*<       ie=1 >*/
	ie = 1;
/* SOURCE ufgculv.for:2425 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:2427 */
/*<       loc_xs=xs >*/
    feq_gen_loc_xs_d_ = *xs;
/* SOURCE ufgculv.for:2428 */
/*<       loc_ys=ys >*/
    feq_gen_loc_ys_d_ = *ys;
/* SOURCE ufgculv.for:2429 */
/*<       do500i=is,ie,dir >*/
    feq_gen_i_d_1 = ie;
    feq_gen_i_d_2 = dir;
    for (feq_gen_i_d_ = is; feq_gen_i_d_2 < 0 ? feq_gen_i_d_ >= feq_gen_i_d_1 : feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += feq_gen_i_d_2) {
/*       The left point is always set to the ups end of the */
/*       channel interval being computed. */
/* SOURCE ufgculv.for:2433 */
/*<       callset_barrel_interval(i) >*/
	feq_gen_set_barrel_interval_d_(&feq_gen_i_d_);
/*       Find the critical and normal depths at the starting */
/*       location.  YMAXA is recomputed in this case. */
/* SOURCE ufgculv.for:2439 */
/*<       if(i.eq.is)then >*/
	if (feq_gen_i_d_ == is) {
/*         Provide starting values for the solution. */
/* SOURCE ufgculv.for:2441 */
/*<       ycrita=ys >*/
	    ycrita = *ys;
/* SOURCE ufgculv.for:2442 */
/*<       ynorma=ys >*/
	    ynorma = *ys;
/* SOURCE ufgculv.for:2443 */
/*<        >*/
	    (*feq_gen_find_ycynym_d_)(stdout, xs, &epsarg, &epsf, &epsabs, &ycrita, &
		    ynorma, &ymaxa, &rflag);
/* SOURCE ufgculv.for:2447 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:2450 */
/*<       if(dir.gt.0)then >*/
	if (dir > 0) {
/* SOURCE ufgculv.for:2451 */
/*<       loc_xe=x_r >*/
	    feq_gen_loc_xe_d_ = ufgc1_1.feq_gen_x_r_d_;
/* SOURCE ufgculv.for:2452 */
/*<       if(loc_xe.gt.xe)loc_xe=xe >*/
	    if (feq_gen_loc_xe_d_ > *xe) {
		feq_gen_loc_xe_d_ = *xe;
	    }
/* SOURCE ufgculv.for:2453 */
/*<       else >*/
	} else {
/* SOURCE ufgculv.for:2454 */
/*<       loc_xe=x_l >*/
	    feq_gen_loc_xe_d_ = ufgc1_1.feq_gen_x_l_d_;
/* SOURCE ufgculv.for:2455 */
/*<       if(loc_xe.lt.xe)loc_xe=xe >*/
	    if (feq_gen_loc_xe_d_ < *xe) {
		feq_gen_loc_xe_d_ = *xe;
	    }
/* SOURCE ufgculv.for:2456 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:2457 */
/*<        >*/
	imptrap_(stdout, &ufgc1_1.feq_gen_pris_flag_d_, &feq_gen_loc_xs_d_, &feq_gen_loc_xe_d_, &
		feq_gen_loc_ys_d_, eps, &epsarg, &epsf, &epsabs, &hmina, &hmaxa, &
		ycrita, &ynorma, &ymaxa, p, f, feq_gen_find_ycynym_d_, &extrap, &ysfac, &dhlim, nmax, &n, &xvec[1], &
		yvec[1], &ycvec[1], &ynvec[1], &rflag);
/* SOURCE ufgculv.for:2465 */
/*<       if(rflag.lt.1)then >*/
	if (rflag < 1) {
/* SOURCE ufgculv.for:2466 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE ufgculv.for:2467 */
/*<       if(dir.gt.0)then >*/
	    if (dir > 0) {
/* SOURCE ufgculv.for:2468 */
/*<       ne=n >*/
		*ne = n;
/* SOURCE ufgculv.for:2469 */
/*<       else >*/
	    } else {
/* SOURCE ufgculv.for:2470 */
/*<       ns=n >*/
		*ns = n;
/* SOURCE ufgculv.for:2471 */
/*<       endif >*/
	    }
/* SOURCE ufgculv.for:2472 */
/*<       goto1000 >*/
	    goto L1000;
/* SOURCE ufgculv.for:2473 */
/*<       elseif(rflag.eq.2)then >*/
	} else if (rflag == 2) {
/*         Stopped at critical depth. */
/* SOURCE ufgculv.for:2475 */
/*<       if(dir.gt.0)then >*/
	    if (dir > 0) {
/* SOURCE ufgculv.for:2476 */
/*<       ne=n >*/
		*ne = n;
/* SOURCE ufgculv.for:2477 */
/*<       else >*/
	    } else {
/* SOURCE ufgculv.for:2478 */
/*<       ns=n >*/
		*ns = n;
/* SOURCE ufgculv.for:2479 */
/*<       endif >*/
	    }
/* SOURCE ufgculv.for:2480 */
/*<       goto1000 >*/
	    goto L1000;
/* SOURCE ufgculv.for:2481 */
/*<       endif >*/
	}
/*       Update values for the next segment. */
/* SOURCE ufgculv.for:2484 */
/*<       if(i.ne.ie)then >*/
	if (feq_gen_i_d_ != ie) {
/* SOURCE ufgculv.for:2485 */
/*<       loc_xs=loc_xe >*/
	    feq_gen_loc_xs_d_ = feq_gen_loc_xe_d_;
/* SOURCE ufgculv.for:2486 */
/*<       loc_ys=yvec(n) >*/
	    feq_gen_loc_ys_d_ = yvec[n];
/* SOURCE ufgculv.for:2487 */
/*<       ycrita=ycvec(n) >*/
	    ycrita = ycvec[n];
/* SOURCE ufgculv.for:2488 */
/*<       ynorma=ynvec(n) >*/
	    ynorma = ynvec[n];
/*          N = N + DIR */
/* SOURCE ufgculv.for:2490 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:2492 */
/*<   500 continue >*/
/* L500: */
    }
/* SOURCE ufgculv.for:2493 */
/*<       if(dir.gt.0)then >*/
    if (dir > 0) {
/* SOURCE ufgculv.for:2494 */
/*<       ne=n >*/
	*ne = n;
/* SOURCE ufgculv.for:2495 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:2496 */
/*<       ns=n >*/
	*ns = n;
/* SOURCE ufgculv.for:2497 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:2498 */
/*<  1000 continue >*/
L1000:
/* SOURCE ufgculv.for:2499 */
/*<       return >*/
    return 0;
/* SOURCE ufgculv.for:2500 */
/*<       end >*/
} /* sfwsp_ */




/* SOURCE ufgculv.for:2504 */
/*<       subroutineinput_barrel(stdin,stdout,sfac,eflag) >*/
/* Subroutine */ int feq_gen_input_barrel_d_(integer *stdin, integer *stdout, 
	doublereal *sfac, integer *eflag)
{
    /* Format strings */
    static char fmt_1[] = "(5x,f10.0)";
    static char fmt_51[] = "(/,\002 Station factor=\002,1pe12.5)";
    static char fmt_52[] = "(i5,1x,a8,1x,a16,1x,f10.3,f10.3)";
    static char fmt_53[] = "(\002 Node   NodeId Table Identifier    Station \
Elevation\002)";
    static char fmt_80[] = "(/,\002 *ERR:XXX* More than \002,i5,\002 cross s\
ections in a \002,\002barrel description for UFGCULV.\002)";

    /* System generated locals */
    doublereal feq_gen_d_d_1;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(), 
	    s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();

    /* Local variables */
    integer feq_gen_old_node_d_, feq_gen_item_end_d_[5], n;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    doublereal elevation;
    extern /* Subroutine */ int feq_gen_read_barrel_items_d_(integer *, char *, 
	    integer *, integer *, integer *, integer *, integer *, char *, 
	    integer *, doublereal *, doublereal *, ftnlen, ftnlen);
    integer feq_gen_item_start_d_[5];
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    extern doublereal getd_(integer *, integer *);
    integer tabn, node;
    char line[80];
    doublereal stat;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    char just[5];
    doublereal slope;
    extern /* Subroutine */ int chktab_(integer *, integer *, integer *, 
	    integer *, integer *, integer *);
    char nodeid[16];
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen);
    extern doublereal fmxarg_(integer *);
    extern /* Subroutine */ int feq_gen_get_item_limits_d_(integer *, char *, integer *
	    , char *, integer *, integer *, integer *, ftnlen, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__310 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__315 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__322 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__323 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__325 = { 0, 0, 0, 0, 0 };


/*     Input the barrel description. */
/* SOURCE ufgculv.for:2510 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:2512 */
/*<       integerstdin,stdout,eflag >*/
/* SOURCE ufgculv.for:2514 */
/*<       real*8sfac >*/
/* INCLUDE ufgculv.for:2517 */
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
/* INCLUDE ufgculv.for:2518 */
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
/* INCLUDE ufgculv.for:2519 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/*     Local variables */
/* SOURCE ufgculv.for:2523 */
/*<       integermaxn >*/
/* SOURCE ufgculv.for:2524 */
/*<       parameter(maxn=5) >*/
/* SOURCE ufgculv.for:2526 */
/*<       integernode,old_node,tabn,n >*/
/* SOURCE ufgculv.for:2527 */
/*<       integeritem_start(maxn),item_end(maxn) >*/
/* SOURCE ufgculv.for:2529 */
/*<       real*8stat,elevation,slope >*/
/* SOURCE ufgculv.for:2531 */
/*<       characterline*80,nodeid*16,just*5 >*/
/*     Called program units */
/* SOURCE ufgculv.for:2534 */
/*<       realfmxarg,getd >*/
/* SOURCE ufgculv.for:2535 */
/*<       characterget_tabid*16 >*/
/* SOURCE ufgculv.for:2536 */
/*<        >*/
/*     *************************FORMATS********************************** */
/* SOURCE ufgculv.for:2539 */
/*<     1 format(5x,f10.0) >*/
/* SOURCE ufgculv.for:2540 */
/*<     2 format(i5,1x,a8,1x,i5,2f10.0) >*/
/* SOURCE ufgculv.for:2541 */
/*<    50 format(/,a) >*/
/* SOURCE ufgculv.for:2542 */
/*<    51 format(/,' Station factor=',1pe12.5) >*/
/* SOURCE ufgculv.for:2543 */
/*<    52 format(i5,1x,a8,1x,a16,1x,f10.3,f10.3) >*/
/* SOURCE ufgculv.for:2544 */
/*<    53 format(' Node   NodeId Table Identifier    Station Elevation') >*/
/* SOURCE ufgculv.for:2546 */
/*<    80  >*/
/* *********************************************************************** */
/*     Get the station factor. */
/* SOURCE ufgculv.for:2551 */
/*<       callinline(stdin,stdout,line) >*/
/* L1: */
/* L2: */
/* L50: */
/* L51: */
/* L52: */
/* L53: */
/* L80: */
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgculv.for:2555 */
/*<       read(line,1)sfac >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_1;
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*sfac), (ftnlen)sizeof(doublereal));
    e_rsfi();
/* SOURCE ufgculv.for:2556 */
/*<       if(sfac.eq.0.d0)sfac=1.d0 >*/
    if (*sfac == 0.) {
	*sfac = 1.;
    }
/* SOURCE ufgculv.for:2557 */
/*<       write(stdout,51)sfac >*/
    feq_gen_io_d__310.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__310);
    do_fio(&feq_gen_c_d_1, (char *)&(*sfac), (ftnlen)sizeof(doublereal));
    e_wsfe();
/*     Read the heading line */
/* SOURCE ufgculv.for:2560 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgculv.for:2563 */
/*<       just='RIGHT' >*/
    s_copy(just, const_cast<char*>("RIGHT"), (ftnlen)5, (ftnlen)5);
/* SOURCE ufgculv.for:2564 */
/*<       callget_item_limits(stdout,line,maxn,just,n,item_start,item_end) >*/
    feq_gen_get_item_limits_d_(stdout, line, &feq_gen_c_d_5, just, &n, feq_gen_item_start_d_, feq_gen_item_end_d_,
	     (ftnlen)80, (ftnlen)5);
/*     Output new standard heading */
/* SOURCE ufgculv.for:2569 */
/*<       write(stdout,53) >*/
    feq_gen_io_d__315.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__315);
    e_wsfe();
/*     Input the cross section references along the barrel. */
/* SOURCE ufgculv.for:2572 */
/*<       nxs=0 >*/
    ufgc1_1.nxs = 0;
/* SOURCE ufgculv.for:2573 */
/*<   100 continue >*/
L100:
/* SOURCE ufgculv.for:2575 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/*        READ(LINE,2) NODE, NODEID, TABN, STAT, ELEVATION */
/* SOURCE ufgculv.for:2579 */
/*<        >*/
    feq_gen_read_barrel_items_d_(stdout, line, &n, feq_gen_item_start_d_, feq_gen_item_end_d_, eflag, &
	    node, nodeid, &tabn, &stat, &elevation, (ftnlen)80, (ftnlen)16);
/* SOURCE ufgculv.for:2585 */
/*<       if(node.eq.0)node=old_node+1 >*/
    if (node == 0) {
	node = feq_gen_old_node_d_ + 1;
    }
/* SOURCE ufgculv.for:2587 */
/*<       if(node.gt.0)then >*/
    if (node > 0) {
/* SOURCE ufgculv.for:2588 */
/*<       write(stdout,52)node,nodeid,get_tabid(tabn),stat,elevation >*/
	feq_gen_io_d__322.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__322);
	do_fio(&feq_gen_c_d_1, (char *)&node, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, nodeid, (ftnlen)16);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tabn);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&stat, (ftnlen)sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, (char *)&elevation, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* SOURCE ufgculv.for:2590 */
/*<       nxs=nxs+1 >*/
	++ufgc1_1.nxs;
/* SOURCE ufgculv.for:2591 */
/*<       if(nxs.gt.mxnxs)then >*/
	if (ufgc1_1.nxs > 10) {
/* SOURCE ufgculv.for:2592 */
/*<       write(stdout,80)mxnxs >*/
	    feq_gen_io_d__323.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__323);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_10, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE ufgculv.for:2593 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE ufgculv.for:2594 */
/*<       nxs=nxs-1 >*/
	    --ufgc1_1.nxs;
/* SOURCE ufgculv.for:2595 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:2596 */
/*<       callchktab(12,stdout,ftpnt,mftnum,tabn,eflag) >*/
	chktab_(&feq_gen_c_d_12, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &tabn, eflag);
/* SOURCE ufgculv.for:2600 */
/*<       xsec_adrs(nxs)=tabn >*/
	ufgc1_1.feq_gen_xsec_adrs_d_[ufgc1_1.nxs - 1] = tabn;
/* SOURCE ufgculv.for:2601 */
/*<       station(nxs)=stat*sfac >*/
	ufgc1_1.station[ufgc1_1.nxs - 1] = stat * *sfac;
/* SOURCE ufgculv.for:2602 */
/*<       invert_z(nxs)=elevation >*/
	ufgc1_1.feq_gen_invert_z_d_[ufgc1_1.nxs - 1] = elevation;
/*         Set the slope category to discontinuous. */
/* SOURCE ufgculv.for:2604 */
/*<       invert_slope_cat(nxs)=0 >*/
	ufgc1_1.feq_gen_invert_slope_cat_d_[ufgc1_1.nxs - 1] = 0;
/* SOURCE ufgculv.for:2605 */
/*<       invert_dzdx(nxs)=0.d0 >*/
	ufgc1_1.feq_gen_invert_dzdx_d_[ufgc1_1.nxs - 1] = 0.;
/* SOURCE ufgculv.for:2606 */
/*<       if(tabn.gt.0.and.eflag.eq.0)then >*/
	if (tabn > 0 && *eflag == 0) {
/*           Get the maximum argument from the table */
/* SOURCE ufgculv.for:2608 */
/*<       xsec_ymax(nxs)=dble(fmxarg(tabn)) >*/
	    ufgc1_1.feq_gen_xsec_ymax_d_[ufgc1_1.nxs - 1] = (doublereal) fmxarg_(&tabn)
		    ;
/*           Get the vertical diameter */
/* SOURCE ufgculv.for:2610 */
/*<       vert_dvec(nxs)=getd(tabn,stdout) >*/
	    ufgc1_1.feq_gen_vert_dvec_d_[ufgc1_1.nxs - 1] = getd_(&tabn, stdout);
/* SOURCE ufgculv.for:2611 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:2612 */
/*<       if(nxs.gt.1)then >*/
	if (ufgc1_1.nxs > 1) {
/*           Set some of the values that depend on the nature */
/*           of the channel between cross sections as infered */
/*           from the information given. */
/* SOURCE ufgculv.for:2616 */
/*<       if(xsec_adrs(nxs).eq.xsec_adrs(nxs-1))then >*/
	    if (ufgc1_1.feq_gen_xsec_adrs_d_[ufgc1_1.nxs - 1] == ufgc1_1.feq_gen_xsec_adrs_d_[
		    ufgc1_1.nxs - 2]) {
/*             This interval is prismatic.  We have not implemented */
/*             continuous slopes for this command. */
/* SOURCE ufgculv.for:2619 */
/*<       channel_variation(nxs-1)=1 >*/
		ufgc1_1.feq_gen_channel_variation_d_[ufgc1_1.nxs - 2] = 1;
/* SOURCE ufgculv.for:2620 */
/*<       endif >*/
	    }
/*           Since continuous slope at cross sections has not */
/*           been implemented for this command, every intra-section */
/*           interval has a constant slope. Compute the sine and */
/*           cosine of the angle of inclination treating a */
/*           decline in elevation from ups to dns as a positive */
/*           angle. */
/* SOURCE ufgculv.for:2628 */
/*<        >*/
	    slope = (ufgc1_1.feq_gen_invert_z_d_[ufgc1_1.nxs - 2] - ufgc1_1.feq_gen_invert_z_d_[
		    ufgc1_1.nxs - 1]) / (ufgc1_1.station[ufgc1_1.nxs - 1] - 
		    ufgc1_1.station[ufgc1_1.nxs - 2]);
/* SOURCE ufgculv.for:2630 */
/*<       sine_theta(nxs-1)=slope/sqrt(1.d0+slope**2) >*/
/* Computing 2nd power */
	    feq_gen_d_d_1 = slope;
	    ufgc1_1.feq_gen_sine_theta_d_[ufgc1_1.nxs - 2] = slope / sqrt(feq_gen_d_d_1 * feq_gen_d_d_1 
		    + 1.);
/* SOURCE ufgculv.for:2631 */
/*<       cosine_theta(nxs-1)=1.d0/sqrt(1.d0+slope**2) >*/
/* Computing 2nd power */
	    feq_gen_d_d_1 = slope;
	    ufgc1_1.feq_gen_cosine_theta_d_[ufgc1_1.nxs - 2] = 1. / sqrt(feq_gen_d_d_1 * feq_gen_d_d_1 + 
		    1.);
/* SOURCE ufgculv.for:2632 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:2633 */
/*<       old_node=node >*/
	feq_gen_old_node_d_ = node;
/* SOURCE ufgculv.for:2634 */
/*<       goto100 >*/
	goto L100;
/* SOURCE ufgculv.for:2635 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:2636 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__325.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__325);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE ufgculv.for:2638 */
/*<       return >*/
    return 0;
/* SOURCE ufgculv.for:2639 */
/*<       end >*/
} /* input_barrel__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE ufgculv.for:2649 */
/*<       subroutineget_h1_vs_y2(adrs,n,y2culv,h1culv) >*/
/* Subroutine */ int feq_gen_get_h1_vs_y2_d_(integer *adrs, integer *n, doublereal *
	feq_storage_y2culv, doublereal *feq_storage_h1culv)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;

    /* Local variables */
    integer feq_gen_i_d_;
    real y2;
    integer nhu, phu;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ppfd;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real y2old;

/*     Extract the values of Y2, depth at culvert entrance, and */
/*     H1, head at section 1 for the culvert, from the 2-D table */
/*     of Type 13.  This table has been computed and stored */
/*     by a CULVERT command occurring earlier in the input. */
/* SOURCE ufgculv.for:2659 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:2661 */
/*<       integeradrs,n >*/
/* SOURCE ufgculv.for:2662 */
/*<       real*8y2culv(n),h1culv(n) >*/
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ufgculv.for:2665 */
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
/* INCLUDE ufgculv.for:2666 */
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
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS - address for the table */
/*     N    - on entry gives the maximum number of elements in the vectors */
/*     Y2CULV - contains the values of entrance depth */
/*     H1CULV - contains the values of head at section 1 */
/*     Local variables */
/* SOURCE ufgculv.for:2676 */
/*<       integeri,nhu,phu,ppfd >*/
/* SOURCE ufgculv.for:2678 */
/*<       realy2old,y2 >*/
/* *********************************************************************** */
/*     Get the address for zero upstream head, and the address for the first */
/*     freedop sequence. */
/*     head. */
/* SOURCE ufgculv.for:2683 */
/*<       phu=itab(adrs+3) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> h1culv(feq_storage_h1culv, 1);

    feq::IndexedPointer<doublereal> y2culv(feq_storage_y2culv, 1);

    /* Function Body */
    phu = itab[*adrs + 3];
/* SOURCE ufgculv.for:2684 */
/*<       ppfd=itab(adrs+5) >*/
    ppfd = itab[*adrs + 5];
/*     Compute the number of upstream heads( includes zero head) */
/* SOURCE ufgculv.for:2687 */
/*<       nhu=(ppfd-phu)/4 >*/
    nhu = (ppfd - phu) / 4;
/*     Now extract the values until two consecutive values for Y2 match */
/*     or the end of the list has been found. */
/* SOURCE ufgculv.for:2691 */
/*<       y2old=-1.0 >*/
    y2old = (float)-1.;
/* SOURCE ufgculv.for:2692 */
/*<       do100i=1,nhu >*/
    feq_gen_i_d_1 = nhu;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ufgculv.for:2693 */
/*<       y2=ftab(phu+2) >*/
	y2 = ftab[phu + 2];
/* SOURCE ufgculv.for:2694 */
/*<       if(abs((y2-y2old)/y2old).le.1.e-5)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>((static_cast<double>(y2) - y2old)) / y2old, dabs(feq_gen_r_d_1)) <= (float)1e-5) {
/*         Presume we have a match.  The current */
/*         value is discarded. */
/* SOURCE ufgculv.for:2697 */
/*<       n=i-1 >*/
	    *n = feq_gen_i_d_ - 1;
/* SOURCE ufgculv.for:2698 */
/*<       goto102 >*/
	    goto L102;
/* SOURCE ufgculv.for:2699 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:2701 */
/*<       y2culv(i)=y2 >*/
	y2culv[feq_gen_i_d_] = y2;
/* SOURCE ufgculv.for:2702 */
/*<       h1culv(i)=ftab(phu) >*/
	h1culv[feq_gen_i_d_] = ftab[phu];
/* SOURCE ufgculv.for:2703 */
/*<       y2old=y2 >*/
	y2old = y2;
/* SOURCE ufgculv.for:2704 */
/*<       if(y2old.eq.0.0)then >*/
	if (y2old == (float)0.) {
/* SOURCE ufgculv.for:2705 */
/*<       y2old=0.1 >*/
	    y2old = (float).1;
/* SOURCE ufgculv.for:2706 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:2707 */
/*<       phu=phu+4 >*/
	phu += 4;
/* SOURCE ufgculv.for:2708 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE ufgculv.for:2709 */
/*<       n=nhu >*/
    *n = nhu;
/* SOURCE ufgculv.for:2711 */
/*<   102 continue >*/
L102:
/* SOURCE ufgculv.for:2712 */
/*<       return >*/
    return 0;
/* SOURCE ufgculv.for:2713 */
/*<       end >*/
} /* get_h1_vs_y2__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE ufgculv.for:2717 */
/*<        >*/
/* Subroutine */ int feq_gen_make_h1_vs_y2_for_culv_d_(integer *stdout, integer *gety2,
	 integer *ftptemp, integer *h1vsy2, integer *eflag)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_;
    doublereal m[151];
    integer n;
    real f1[151], f2[151];
    extern /* Subroutine */ int feq_gen_get_h1_vs_y2_d_(integer *, integer *, 
	    doublereal *, doublereal *);
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int put1d_(integer *, integer *, integer *, 
	    integer *, real *, real *, real *, integer *, integer *);
    doublereal slope, h1culv[151], y2culv[151];
    char adjloc[1*151];
    real argvec[151];
    extern /* Subroutine */ int vlchpp_(integer *, integer *, doublereal *, 
	    doublereal *, integer *, doublereal *, integer *, doublereal *, 
	    doublereal *, char *, ftnlen);

/*     Make a 1-D table of H1 versus Y2 for for culvert flow */
/*     for use in computations for an underflow gate on a culvert. */
/* SOURCE ufgculv.for:2725 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:2727 */
/*<       integereflag,ftptemp,gety2,h1vsy2,stdout >*/
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ufgculv.for:2730 */
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
/* INCLUDE ufgculv.for:2731 */
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
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - unit for standard output */
/*     GETY2 - address of table of type 13 containing the Y2 values */
/*             for the culvert. */
/*     FTPTEMP- temp value for the function table pointer. */
/*     H1VSY2- address for the resulting 1-D table. */
/*     EFLAG- error flag. */
/*     Local variables. */
/* SOURCE ufgculv.for:2744 */
/*<       integeri,n >*/
/* SOURCE ufgculv.for:2746 */
/*<       realargvec(pmxnhu),f1(pmxnhu),f2(pmxnhu) >*/
/* SOURCE ufgculv.for:2748 */
/*<       real*8y2culv(pmxnhu),h1culv(pmxnhu),m(pmxnhu),slope >*/
/* SOURCE ufgculv.for:2750 */
/*<       character*1adjloc(pmxnhu) >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ufgculv.for:2753 */
/*<       externalget_h1_vs_y2,vlchpp,put1d >*/
/* *********************************************************************** */
/*     Extract the values from the table of Y2 */
/* SOURCE ufgculv.for:2757 */
/*<       n=pmxnhu >*/
    n = 151;
/* SOURCE ufgculv.for:2758 */
/*<       callget_h1_vs_y2(gety2,n,y2culv,h1culv) >*/
    feq_gen_get_h1_vs_y2_d_(gety2, &n, y2culv, h1culv);
/*     Compute a variation limited cubic spline.  Use linear approx to */
/*     derivative for the left end condition and a derivative of zero */
/*     for the right end condition. */
/* SOURCE ufgculv.for:2767 */
/*<       slope=(h1culv(2)-h1culv(1))/(y2culv(2)-y2culv(1)) >*/
    slope = (h1culv[1] - h1culv[0]) / (y2culv[1] - y2culv[0]);
/* SOURCE ufgculv.for:2768 */
/*<       callvlchpp(stdout,n,y2culv,h1culv,1,slope,1,0.d0,m,adjloc) >*/
    vlchpp_(stdout, &n, y2culv, h1culv, &feq_gen_c_d_1, &slope, &feq_gen_c_d_1, &c_b216, m, 
	    adjloc, (ftnlen)1);
/*     Transfer to single-precision values. */
/* SOURCE ufgculv.for:2773 */
/*<       do100i=1,n >*/
    feq_gen_i_d_1 = n;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ufgculv.for:2774 */
/*<       argvec(i)=y2culv(i) >*/
	argvec[feq_gen_i_d_ - 1] = y2culv[feq_gen_i_d_ - 1];
/* SOURCE ufgculv.for:2775 */
/*<       f1(i)=h1culv(i) >*/
	f1[feq_gen_i_d_ - 1] = h1culv[feq_gen_i_d_ - 1];
/* SOURCE ufgculv.for:2776 */
/*<       f2(i)=m(i) >*/
	f2[feq_gen_i_d_ - 1] = m[feq_gen_i_d_ - 1];
/* SOURCE ufgculv.for:2777 */
/*<   100 continue >*/
/* L100: */
    }
/*     Store as table of type 4 using a table number of -1. */
/* SOURCE ufgculv.for:2780 */
/*<       callput1d(stdout,-1,4,n,argvec,f1,f2,ftptemp,h1vsy2) >*/
    put1d_(stdout, &c_n1, &feq_gen_c_d_4, &n, argvec, f1, f2, ftptemp, h1vsy2);
/* SOURCE ufgculv.for:2785 */
/*<       return >*/
    return 0;
/* SOURCE ufgculv.for:2786 */
/*<       end >*/
} /* make_h1_vs_y2_for_culv__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE ufgculv.for:2790 */
/*<       subroutineufgculv(grav,stdin,stdout,stdtab,ftp,eflag,tabdir) >*/
/* Subroutine */ int ufgculv_(real *grav, integer *stdin, integer *stdout, 
	integer *stdtab, integer *ftp, integer *eflag, integer *feq_storage_tabdir)
{
    /* Format strings */
    static char fmt_2[] = "(6x,a)";
    static char fmt_8[] = "(9x,f10.0)";
    static char fmt_10[] = "(10x,f10.0)";
    static char fmt_12[] = "(3x,f10.0)";
    static char fmt_16[] = "(7x,f10.0)";
    static char fmt_18[] = "(7x,f10.0)";
    static char fmt_19[] = "(9x,f10.0)";
    static char fmt_20[] = "(8x,f10.0)";
    static char fmt_21[] = "(8x,f10.0)";
    static char fmt_22[] = "(10x,f10.0)";
    static char fmt_50[] = "(/,\002 Table id= \002,a,\002 for type 15 table \
for underflow\002,\002 gate/culvert.\002)";
    static char fmt_51[] = "(/,\002 *ERR:XXX* Culvert flow TabId= \002,a,\
\002 given but GETY2\002,\002 value is missing.\002)";
    static char fmt_52[] = "(/,\002 Label=\002,a50)";
    static char fmt_53[] = "(/,\002 *ERR:XXX* TabId for depth at culvert exi\
t= \002,a,\002 given but GETQ value is missing.\002)";
    static char fmt_54[] = "(/,\002 Approach section table id=\002,a)";
    static char fmt_55[] = "(/,\002 *ERR:XXX* GETQ and GETY2 values are miss\
ing.\002)";
    static char fmt_56[] = "(/,\002 Departure section table id= \002,a)";
    static char fmt_57[] = "(/,\002 Table id's for culvert flow= \002,a,\002\
 and for entrance depth= \002,a)";
    static char fmt_58[] = "(/,\002 Elevation of gate sill=\002,f10.3)";
    static char fmt_59[] = "(/,\002 FC flow cannot match FW flow at the FW l\
imit.\002/,\002 May be a discontinuity in flow at the FW limit.\002)";
    static char fmt_60[] = "(/,\002 Total gate opening width=\002,f10.3)";
    static char fmt_61[] = "(/,\002 FC flow matches FW flow at FW limit with\
 CC=\002,f10.3)";
    static char fmt_62[] = "(/,\002 User input of discharge coeff. read but \
ignored\002,\002 in UFGCULV.\002)";
    static char fmt_63[] = "(/,\002 Coefficient of discharge for FC, FO, and\
 SO flows=\002,f10.4)";
    static char fmt_64[] = "(/,\002 Contraction coefficient table id= \002,a)"
	    ;
    static char fmt_65[] = "(/\002 Critical depth/vert. dia. ratio>=\002,f10\
.5,\002 for full-barrel flow.\002,/,\002 Critical depth/vert. dia. ratio<\
=\002,f10.5,\002 upper limit for free-surface flow.\002)";
    static char fmt_66[] = "(/,\002 Minimum partial free drop=\002,f10.5)";
    static char fmt_67[] = "(/,\002 Partial free drop at power breakpoint\
=\002,f10.5)";
    static char fmt_68[] = "(/,\002 Limiting partial free drop=\002,f10.3)";
    static char fmt_69[] = "(/,\002 Final local power for partial free dro\
ps=\002,f10.3)";
    static char fmt_70[] = "(/,\002Two-D table computations for gate openi\
ng=\002,f8.3,\002  Two-D table number=\002,i6)";
    static char fmt_71[] = "(5x,\002Head at section 1 for FW/FO-FC boundary\
=\002,f9.4,/,5x,\002Head-relative gate opening at FW/FO-FC boundary=\002,f9.\
4)";
    static char fmt_72[] = "(/,\002Upstream head=\002,f9.4,\002 Elevation\
=\002,f10.4,/,2x,\002Depth at section 1=\002,f8.4,\002 Gate opening=\002,f8.\
4)";
    static char fmt_73[] = "(6x,\002Processing gate opening=\002,f8.3)";
    static char fmt_74[] = "(/,\002  Partial  Drop    Head    Head   Flow Co\
nt.  Discharge  Local\002,\002  Energy\002,/,\002   free    sect.   sect.   \
sect.  type coef.             power\002,\002   loss\002,/,\002   drop    1->\
4     3       4           Cc  \002,17x,\002    1->4\002,/,\002 --------  ---\
---  ------  ------  ---  ---- ----------- -----\002,\002  ------\002)";
    static char fmt_75[] = "(1x,f8.4,f8.3,a8,f8.3,3x,a2,a6,1x,a11,f6.3,f8.3)";
    static char fmt_76[] = "(1x,f8.4,f8.3,f8.3,f8.3,3x,a2,a6,1x,a11,6x,f8.3)";
    static char fmt_77[] = "(/,\002 *WRN:592* Please review results.  One or\
 more\002,\002 cases with energy gain found.\002)";
    static char fmt_78[] = "(1x,f8.4,f8.3,a8,f8.3,3x,a2,a6,1x,a11,6x,f8.3)";
    static char fmt_79[] = "(/,\002 Free weir to free orifice transition fra\
ction=\002,f8.2)";
    static char fmt_80[] = "(/,\002 Maximum upstream head=\002,f8.2)";
    static char fmt_81[] = "(/,\002 Minimum non-zero upstream head=\002,f8.2)"
	    ;
    static char fmt_82[] = "(/,\002 Linear interpolation precision=\002,f8.3)"
	    ;
    static char fmt_83[] = "(/,\002 Flow at the FW limit=\002,f10.2)";
    static char fmt_86[] = "(/,\002 Maximum relative error=\002,f6.3,\002 Ga\
te opening=\002,f8.4,/,\002   Upstream head=\002,f9.4,\002 Partial free drop=\
\002,f8.5)";
    static char fmt_87[] = "(/,\002 *ERR:607* TABLE# <= 0\002)";
    static char fmt_88[] = "(/\002 Root-mean-squared error=\002,f6.3,\002 N \
in sample=\002,i5)";
    static char fmt_89[] = "(\002  Processing UFGCULV TabId= \002,a)";
    static char fmt_90[] = "(/,\002 *ERR:712* Gate sill elevation=\002,f10\
.3,\002 <  elevation\002,\002 of floor of\002,/,11x,\002 departure reach=\
\002,f10.3)";
    static char fmt_91[] = "(/,\002 *ERR:713* Gate opening width=\002,f10.3\
,\002 <= 0.0\002)";
    static char fmt_93[] = "(/,\002 *ERR:715* Contraction coef.=\002,f10.3\
,\002 <= 0.0 or > 1.0\002)";
    static char fmt_95[] = "(\002TABID=\002,a,/,\002TYPE=  -15\002,/,\002REF\
L=\002,7x,\0020.0 LABEL=\002,a50,/,\002   OPENING Table Identifier    H1FWUL\
R   H4FWULR H4SWSOMDR\002)";
    static char fmt_96[] = "(f10.3,1x,a16,1x,3f10.6)";
    static char fmt_98[] = "(/,\002 *ERR:717* Gate sill elevation=\002,f10\
.3,\002 <  elevation\002,\002 of floor of\002,/,11x,\002 approach reach=\002\
,f10.3)";
    static char fmt_99[] = "(/,\002 *ERR:635* Interpolation precision tables\
 missing.\002,\002 Check for version\002,/,11x,\002of file: TYPE5.TAB.\002)";

    /* System generated locals */
    address feq_gen_a_d_1[2];
    integer feq_gen_i_d_1, feq_gen_i_d_2[2], feq_gen_i_d_3, feq_gen_i_d_4;
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3, feq_gen_r_d_4;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2, feq_gen_d_d_3, feq_gen_d_d_4, feq_gen_d_d_5;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16], feq_gen_ch_d_3[16], feq_gen_ch_d_4[16], feq_gen_ch_d_5[10];
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(), do_fio(integer *, char *, ftnlen), 
	    s_rsfi(icilist *), e_rsfi(), s_wsle(cilist *), do_lio(integer *, 
	    integer *, char *, ftnlen), e_wsle(), s_wsfi(icilist *), e_wsfi();
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_stop(char *, ftnlen);
    double log(doublereal), sqrt(doublereal);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen), feq_gen_find_fcq_d_(integer *, doublereal *,
	     doublereal *, doublereal *, doublereal *, integer *);
    char deptabid[16];
    doublereal feq_gen_fw_cc_so_d_;
    integer feq_gen_item_end_d_[4];
    char apptabid[16];
    integer colwidth;
    doublereal northing;
    real b;
    extern doublereal e_(doublereal*, doublereal*);
    integer feq_gen_i_d_, j, n;
    real p, q, feq_gen_hdatum_for_h1vsy2_d_;
    doublereal feq_gen_station_1_d_;
    extern /* Subroutine */ int feq_gen_find_y4sw_d_(integer *, real *, real *, real *,
	     integer *, doublereal *, doublereal *, doublereal *, doublereal *
	    );
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    extern /* Subroutine */ int feq_gen_find_foll_d_(integer *, doublereal *, 
	    doublereal *, doublereal *, integer *);
    real a3, h1, h3, h4;
    extern /* Subroutine */ int feq_gen_construct_yoverd_d_(integer *, integer *, 
	    integer *), feq_gen_td13_fdrop_d_(integer *, integer *, integer *, real *, 
	    real *, real *);
    real z1;
    extern /* Subroutine */ int feq_gen_read_ufgate_items_d_(integer *, char *, 
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    integer *, real *, real *, ftnlen);
    real db;
    integer ef;
    char id[16];
    real dk;
    integer ne;
    char cq[11];
    real dt, rg;
    doublereal xe;
    integer ns;
    extern /* Subroutine */ int feq_gen_read_tabid_d_(integer *, char *, char *, 
	    integer *, char *, integer *, ftnlen, ftnlen, ftnlen);
    real tp;
    doublereal xs, ys;
    extern /* Subroutine */ int feq_gen_ufg_fndfoq_d_(integer *, integer *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *);
    real h4f, y4f;
    integer feq_gen_item_start_d_[4];
    real zw4;
    extern /* Subroutine */ int feq_gen_get_ycynym_d_(integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *), feq_gen_find_sequent_depth_d_(
	    integer *, doublereal *, doublereal *, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *);
    integer tab, ihg, nhg, ihu, nhu;
    char key[16];
    real rms;
    doublereal yvc;
    real pow, qtt;
    char lab2[50];
    extern /* Subroutine */ int feq_gen_profile_ups_d_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *), feq_gen_find_ycynym_d_(integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *);
    real y2fw, zw4f, y4sw;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
    doublereal sfac;
    real dqed;
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer free, ipfd;
    doublereal feq_gen_yb_d_d_;
    integer ntab;
    char line[80];
    real prec;
    extern /* Subroutine */ int lkta_(integer *, real *, real *);
    integer getq;
    // Owned workspace avoids platform-dependent stack limits.
    std::vector<real> feq_heap_qmat(53001);
    real herr, qhat, drop, *qmat = feq_heap_qmat.data()	/* was [151][351] */, rerr, xbrk[351],
	     dqeu;
    integer nrms;
    real feq_gen_xe_r_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real work[351];
    doublereal ymax;
    char just[5], zone[8];
    extern doublereal rhse_(doublereal*, doublereal*);
    extern /* Character */ VOID put10_(char *, ftnlen, real *);
    integer tab2d[40];
    char char6[6], char8[8];
    extern /* Subroutine */ int feq_gen_find_so_flow_d_(integer *, integer *, integer *
	    , real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    integer *, doublereal *, doublereal *, real *, real *, real *, 
	    real *, integer *), feq_gen_input_barrel_d_(integer *, integer *, 
	    doublereal *, integer *);
    doublereal y2hat;
    integer gety2, cctab;
    char hglab[10], label[50], tabid[16];
    real angle[40], concc;
    integer nfrac, idlen;
    real ccval[40], fdvec[151], de1to4;
    integer tabgt;
    real hgvec[40];
    integer tablt, tptab, nitem;
    real fdrop, humax;
    integer h1vsy2;
    real humin, huvec[151], maxhu, minhu, oldhg, power, qfree, deriv;
    integer rflag;
    real afull, kfull, jfull, aflux;
    doublereal ycrit, ynorm;
    char ftype[2], idout[32], hgrid[8], basis[8];
    real h1foll;
    extern /* Subroutine */ int xlkt22_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *), lktab_(integer *, real *, integer *, real *, integer *, 
	    real *), tdlk13_(integer *, integer *, integer *, integer *, real 
	    *, real *, real *, real *, real *, real *, real *, integer *), 
	    feq_gen_find_fw_cc_so_d_(integer *, doublereal *, doublereal *, doublereal 
	    *, integer *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *), xlkt21_(
	    integer *, real *, real *, real *, real *, real *, real *, real *,
	     real *, real *), feq_gen_find_fb_ycrit_d_(integer *, doublereal *), 
	    sfwsp_(integer *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, FeqCallback2, FeqCallback2, FeqCallback4, integer *, integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *)
	    ;
    real h1fwul;
    doublereal feq_gen_y4sw_d_d_;
    integer fcflag;
    extern /* Subroutine */ int feq_gen_make_h1_vs_y2_for_culv_d_(integer *, integer *,
	     integer *, integer *, integer *);
    extern doublereal findcc_(real *, real *, integer *);
    real z1fwul;
    integer elflag;
    extern /* Subroutine */ int chktab_(integer *, integer *, integer *, 
	    integer *, integer *, integer *);
    extern doublereal gethdd_(integer *);
    integer ihgerr, soflag;
    real bigerr, brkpfd, finpow, fwfotr, hdatum, hstuff[120]	/* was [40][3]
	     */, limpfd, liprec, lipvec[40], minpfd, mnhvec[40], offset, 
	    pfdvec[351], rgfwul, zrhufd, yvcold;
    char vdatum[8];
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int fndelv_(integer *, integer *, integer *, real 
	    *), inline_(integer *, integer *, char *, ftnlen), lstopf_(
	    integer *, integer *, integer *, real *, real *, real *, real *, 
	    real *, integer *, integer *, real *, integer *), tabchk_(integer 
	    *, integer *, integer *, integer *, integer *), twdout_(integer *,
	     integer *, integer *, char *, integer *, integer *, real *, real 
	    *, real *, real *, real *, integer *, char *, real *, char *, 
	    char *, char *, char *, char *, doublereal *, doublereal *, 
	    integer *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen)
	    , fndsta_(integer *, integer *, integer *, real *);
    char cctabid[16];
    extern /* Subroutine */ int feq_gen_get_lctn_items_d_(integer *, integer *, 
	    integer *), feq_gen_set_lctn_items_d_(char *, char *, char *, char *, char 
	    *, doublereal *, doublereal *, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen), feq_gen_lkt_zb_d_(integer *, doublereal *, doublereal *), 
	    feq_gen_find_y4_from_y43_d_(integer *, real *, real *, integer *, real *, 
	    real *, real *, real *, real *, real *, integer *);
    doublereal feq_gen_cd_culv_d_, easting;
    extern /* Subroutine */ int feq_gen_get_ufgc_tabids_d_(integer *, integer *, 
	    integer *);
    integer ftptemp;
    extern /* Subroutine */ int feq_gen_set_ufgc_tabids_d_(integer *, integer *, 
	    integer *, integer *);
    doublereal feq_gen_h1foll_d_d_, feq_gen_h1fwul_d_d_;
    extern /* Subroutine */ int feq_gen_get_item_limits_d_(integer *, char *, integer *
	    , char *, integer *, integer *, integer *, ftnlen, ftnlen);
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__355 = { 0, 0, 0, fmt_99, 0 };
    static cilist feq_gen_io_d__359 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__360 = { 0, 6, 0, fmt_89, 0 };
    static cilist feq_gen_io_d__361 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__362 = { 0, 0, 0, fmt_57, 0 };
    static cilist feq_gen_io_d__363 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__364 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__374 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__376 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__377 = { 0, 0, 0, fmt_87, 0 };
    static cilist feq_gen_io_d__383 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__384 = { 0, 0, 0, fmt_87, 0 };
    static cilist feq_gen_io_d__385 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__386 = { 0, 0, 0, fmt_90, 0 };
    static cilist feq_gen_io_d__387 = { 0, 0, 0, fmt_98, 0 };
    static cilist feq_gen_io_d__388 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__389 = { 0, 0, 0, fmt_91, 0 };
    static cilist feq_gen_io_d__390 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__393 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__394 = { 0, 0, 0, fmt_87, 0 };
    static cilist feq_gen_io_d__396 = { 0, 0, 0, fmt_79, 0 };
    static cilist feq_gen_io_d__398 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__400 = { 0, 0, 0, fmt_81, 0 };
    static cilist feq_gen_io_d__402 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__403 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__420 = { 0, 0, 0, fmt_93, 0 };
    static cilist feq_gen_io_d__421 = { 0, 0, 0, fmt_98, 0 };
    static cilist feq_gen_io_d__423 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__425 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__427 = { 0, 0, 0, fmt_67, 0 };
    static cilist feq_gen_io_d__429 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__431 = { 0, 0, 0, fmt_69, 0 };
    static cilist feq_gen_io_d__459 = { 0, 6, 0, fmt_73, 0 };
    static cilist feq_gen_io_d__460 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__468 = { 0, 0, 0, fmt_71, 0 };
    static cilist feq_gen_io_d__473 = { 0, 0, 0, fmt_83, 0 };
    static cilist feq_gen_io_d__477 = { 0, 0, 0, fmt_65, 0 };
    static cilist feq_gen_io_d__482 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__492 = { 0, 0, 0, fmt_59, 0 };
    static cilist feq_gen_io_d__493 = { 0, 0, 0, fmt_61, 0 };
    static cilist feq_gen_io_d__494 = { 0, 0, 0, fmt_63, 0 };
    static cilist feq_gen_io_d__506 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__507 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__521 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__527 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__528 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__532 = { 0, 0, 0, fmt_75, 0 };
    static cilist feq_gen_io_d__536 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__537 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__538 = { 0, 0, 0, fmt_75, 0 };
    static cilist feq_gen_io_d__539 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__540 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__541 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__542 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__543 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__546 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__547 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__548 = { 0, 0, 0, fmt_75, 0 };
    static cilist feq_gen_io_d__555 = { 0, 0, 0, fmt_77, 0 };
    static cilist feq_gen_io_d__556 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__557 = { 0, 0, 0, fmt_88, 0 };
    static cilist feq_gen_io_d__559 = { 0, 0, 0, fmt_95, 0 };
    static cilist feq_gen_io_d__560 = { 0, 0, 0, fmt_96, 0 };
    static cilist feq_gen_io_d__561 = { 0, 0, 0, fmt_96, 0 };
    static cilist feq_gen_io_d__562 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__563 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Compute the function tables needed to define the flow */
/*     for an underflow gate on the upstream face of a */
/*     culvert. */
/* SOURCE ufgculv.for:2799 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ufgculv.for:2802 */
/*<       integereflag,ftp,stdin,stdout,stdtab >*/
/* SOURCE ufgculv.for:2803 */
/*<       integertabdir(*) >*/
/* SOURCE ufgculv.for:2804 */
/*<       realgrav >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     GRAV   - value of acceleration due to gravity */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     TABDIR - Table directory to remember table numbers */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ufgculv.for:2815 */
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
/* INCLUDE ufgculv.for:2816 */
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
/* INCLUDE ufgculv.for:2817 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE ufgculv.for:2818 */
/*     Common block for underflow gate computations.  These values */
/*     are often used in residual functions. */
/* SOURCE ufgate.cmn:4 */
/*<       integerapptab,deptab >*/
/* SOURCE ufgate.cmn:6 */
/*<        >*/
/* SOURCE ufgate.cmn:11 */
/*<        >*/
/* INCLUDE ufgculv.for:2819 */
/*     Common block for double precision functions involved in UFGCULV. */
/* SOURCE ufgate_d.cmn:4 */
/*<        >*/
/* SOURCE ufgate_d.cmn:6 */
/*<       parameter(nmax=2000) >*/
/* SOURCE ufgate_d.cmn:8 */
/*<        >*/
/* SOURCE ufgate_d.cmn:16 */
/*<       real*8xvec(nmax),yvec(nmax),ycvec(nmax),ynvec(nmax) >*/
/* SOURCE ufgate_d.cmn:18 */
/*<        >*/
/* INCLUDE ufgculv.for:2820 */
/*     Common block to use with the water-surface profile */
/*     computation in the UFGCULV command and perhaps others. */
/*     Values that apply at a cross section location. */
/*     STATION( ) - distance along the channel, increasing */
/*                  from upstream to downstream (may be relaxed */
/*                  later).  Flow from upstream to downstream */
/*                  is treated as positive. */
/*     XSEC_ADRS()- initially contains the id number for the */
/*                  cross-section function table and later */
/*                  the address for the table. */
/*     INVERT_Z()- elevation of the cross section invert at */
/*                 location in STATION(). */
/*     VERT_DVEC()- vertical diameter of the barrel. */
/*     INVERT_DZDX()- value of slope at the location in */
/*                 STATION if the slope is continuous. */
/*                 For future expansion or experimentation. */
/*     INVERT_SLOPE_CAT()- category for the invert slope: */
/*                 1 means continuous slope so that the slope */
/*                 continuous at each STATION; and 0 means */
/*                 a discontinuous slope at each station */
/*     MXNXS- maximum number of cross sections allowed */
/*                 in a description */
/*     NXS-  number of cross sections. */
/*     XLOC- station value for those functions that cannot be */
/*           passed the station value */
/*     QD- flow in double precision. */
/*     VERT_D - vertical diameter of culvert */
/*     Values that apply between adjacent sections. */
/*     CHANNEL_VARIATION()- 1 prismatic channel, 0 non-prismatic channel */
/*     SINE_THETA()- sine of the inclination angle of the invert when */
/*                  the slope is discontinuous at both ends. */
/*     COSINE_THETA()- cosine of inclination angle */
/*     Values that are used as local values in the lookup process for */
/*     cross section elements. */
/*     At the left end of a segment between adjacent cross sections. */
/*     Left is taken as upstream end. */
/*     X_L- station */
/*     Z_L- invert elevation */
/*     DZDX_L- slope */
/*     ADRS_L- cross-section table address */
/*     YMAX_L- maximum depth argument */
/*     Similar values with an _R apply on the right end as well */
/*     Values that apply between the section on the left and the section */
/*     on the right. */
/*     SIN_THETA- sine of inclination angle. */
/*     COS_THETA- cosine of inclination angle. */
/*     SLOPE_FLAG- 1 slope varies between sections; and 0 */
/*                   slope is constant between sections. */
/* SOURCE barrel.cmn:70 */
/*<       integermxnxs,mxnxsm1,nxs >*/
/* SOURCE barrel.cmn:71 */
/*<       parameter(mxnxs=10,mxnxsm1=mxnxs-1) >*/
/* SOURCE barrel.cmn:73 */
/*<        >*/
/* SOURCE barrel.cmn:76 */
/*<        >*/
/* SOURCE barrel.cmn:81 */
/*<       integerpris_flag,slope_flag,adrs_l,adrs_r >*/
/* SOURCE barrel.cmn:83 */
/*<        >*/
/* SOURCE barrel.cmn:88 */
/*<        >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ufgculv.for:2823 */
/*<        >*/
/* SOURCE ufgculv.for:2828 */
/*<       integermaxn >*/
/* SOURCE ufgculv.for:2829 */
/*<       parameter(maxn=4) >*/
/* SOURCE ufgculv.for:2830 */
/*<       integertab2d(pmxnhg),item_start(maxn),item_end(maxn) >*/
/* SOURCE ufgculv.for:2831 */
/*<        >*/
/* SOURCE ufgculv.for:2843 */
/*<       real*8sfac >*/
/* SOURCE ufgculv.for:2845 */
/*<       integerns,ne,rflag,free >*/
/* SOURCE ufgculv.for:2846 */
/*<        >*/
/* SOURCE ufgculv.for:2848 */
/*<        >*/
/* SOURCE ufgculv.for:2853 */
/*<       real*8dble >*/
/* SOURCE ufgculv.for:2855 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE ufgculv.for:2861 */
/*<       intrinsicabs,float,log,sqrt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ufgculv.for:2864 */
/*<       integerfind_barrel_interval,lenstr >*/
/* SOURCE ufgculv.for:2865 */
/*<       realfindcc,gethdd >*/
/* SOURCE ufgculv.for:2866 */
/*<       real*8e,rhse,find_foll_resid >*/
/* SOURCE ufgculv.for:2867 */
/*<       characterput10*10,get_tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ufgculv.for:2870 */
/*<        >*/
/*     + + + INPUT FORMATS + + + */
/* SOURCE ufgculv.for:2880 */
/*<     1 format(7x,i5,6x,i5,7x,i5) >*/
/* SOURCE ufgculv.for:2881 */
/*<     2 format(6x,a) >*/
/* SOURCE ufgculv.for:2882 */
/*<     4 format(7x,i5) >*/
/* SOURCE ufgculv.for:2883 */
/*<     6 format(7x,i5) >*/
/* SOURCE ufgculv.for:2884 */
/*<     8 format(9x,f10.0) >*/
/* SOURCE ufgculv.for:2885 */
/*<    10 format(10x,f10.0) >*/
/* SOURCE ufgculv.for:2886 */
/*<    12 format(3x,f10.0) >*/
/* SOURCE ufgculv.for:2887 */
/*<    14 format(6x,i5) >*/
/* SOURCE ufgculv.for:2888 */
/*<    16 format(7x,f10.0) >*/
/* SOURCE ufgculv.for:2889 */
/*<    18 format(7x,f10.0) >*/
/* SOURCE ufgculv.for:2890 */
/*<    19 format(9x,f10.0) >*/
/* SOURCE ufgculv.for:2891 */
/*<    20 format(8x,f10.0) >*/
/* SOURCE ufgculv.for:2892 */
/*<    21 format(8x,f10.0) >*/
/* SOURCE ufgculv.for:2893 */
/*<    22 format(10x,f10.0) >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ufgculv.for:2896 */
/*<    50  >*/
/* SOURCE ufgculv.for:2898 */
/*<    51  >*/
/* SOURCE ufgculv.for:2900 */
/*<    52 format(/,' Label=',a50) >*/
/* SOURCE ufgculv.for:2901 */
/*<    53  >*/
/* SOURCE ufgculv.for:2903 */
/*<    54 format(/,' Approach section table id=',a) >*/
/* SOURCE ufgculv.for:2904 */
/*<    55 format(/,' *ERR:XXX* GETQ and GETY2 values are missing.') >*/
/* SOURCE ufgculv.for:2905 */
/*<    56 format(/,' Departure section table id= ',a) >*/
/* SOURCE ufgculv.for:2906 */
/*<    57  >*/
/* SOURCE ufgculv.for:2908 */
/*<    58 format(/,' Elevation of gate sill=',f10.3) >*/
/* SOURCE ufgculv.for:2909 */
/*<    59  >*/
/* SOURCE ufgculv.for:2911 */
/*<    60 format(/,' Total gate opening width=',f10.3) >*/
/* SOURCE ufgculv.for:2912 */
/*<    61 format(/,' FC flow matches FW flow at FW limit with CC=',f10.3) >*/
/* SOURCE ufgculv.for:2913 */
/*<    62  >*/
/* SOURCE ufgculv.for:2915 */
/*<    63  >*/
/* SOURCE ufgculv.for:2917 */
/*<    64 format(/,' Contraction coefficient table id= ',a) >*/
/* SOURCE ufgculv.for:2918 */
/*<    65  >*/
/* SOURCE ufgculv.for:2922 */
/*<    66 format(/,' Minimum partial free drop=',f10.5) >*/
/* SOURCE ufgculv.for:2923 */
/*<    67 format(/,' Partial free drop at power breakpoint=',f10.5) >*/
/* SOURCE ufgculv.for:2924 */
/*<    68 format(/,' Limiting partial free drop=',f10.3) >*/
/* SOURCE ufgculv.for:2925 */
/*<    69 format(/,' Final local power for partial free drops=',f10.3) >*/
/* SOURCE ufgculv.for:2926 */
/*<    70  >*/
/* SOURCE ufgculv.for:2928 */
/*<    71  >*/
/* SOURCE ufgculv.for:2930 */
/*<    72  >*/
/* SOURCE ufgculv.for:2933 */
/*<    73 format(6x,'Processing gate opening=',f8.3) >*/
/* SOURCE ufgculv.for:2934 */
/*<    74  >*/
/* SOURCE ufgculv.for:2942 */
/*<    75 format(1x,f8.4,f8.3,a8,f8.3,3x,a2,a6,1x,a11,f6.3,f8.3) >*/
/* SOURCE ufgculv.for:2943 */
/*<    76 format(1x,f8.4,f8.3,f8.3,f8.3,3x,a2,a6,1x,a11,6x,f8.3) >*/
/* SOURCE ufgculv.for:2944 */
/*<    77  >*/
/* SOURCE ufgculv.for:2946 */
/*<    78 format(1x,f8.4,f8.3,a8,f8.3,3x,a2,a6,1x,a11,6x,f8.3) >*/
/* SOURCE ufgculv.for:2947 */
/*<    79 format(/,' Free weir to free orifice transition fraction=',f8.2) >*/
/* SOURCE ufgculv.for:2948 */
/*<    80 format(/,' Maximum upstream head=',f8.2) >*/
/* SOURCE ufgculv.for:2949 */
/*<    81 format(/,' Minimum non-zero upstream head=',f8.2) >*/
/* SOURCE ufgculv.for:2950 */
/*<    82 format(/,' Linear interpolation precision=',f8.3) >*/
/* SOURCE ufgculv.for:2951 */
/*<    83 format(/,' Flow at the FW limit=',f10.2) >*/
/* SOURCE ufgculv.for:2952 */
/*<    86  >*/
/* SOURCE ufgculv.for:2955 */
/*<    87 format(/,' *ERR:607* TABLE# <= 0') >*/
/* SOURCE ufgculv.for:2956 */
/*<    88 format(/' Root-mean-squared error=',f6.3,' N in sample=',i5) >*/
/* SOURCE ufgculv.for:2957 */
/*<    89 format('  Processing UFGCULV TabId= ',a) >*/
/* SOURCE ufgculv.for:2958 */
/*<    90  >*/
/* SOURCE ufgculv.for:2960 */
/*<    91 format(/,' *ERR:713* Gate opening width=',f10.3,' <= 0.0') >*/
/* SOURCE ufgculv.for:2961 */
/*<    92 format(/,' *ERR:714* Approach loss Cd <=0.0 or > 1.0') >*/
/* SOURCE ufgculv.for:2962 */
/*<    93 format(/,' *ERR:715* Contraction coef.=',f10.3,' <= 0.0 or > 1.0') >*/
/* SOURCE ufgculv.for:2963 */
/*<    94 format(/,' *ERR:716* In UFGATE: FLAG=',i3,' No solution',a) >*/
/* SOURCE ufgculv.for:2964 */
/*<    95  >*/
/* SOURCE ufgculv.for:2966 */
/*<    96 format(f10.3,1x,a16,1x,3f10.6) >*/
/* SOURCE ufgculv.for:2967 */
/*<    97 format(/,' *BUG:XXX* In UFGATE no root in 16 tries for:',a) >*/
/* SOURCE ufgculv.for:2968 */
/*<    98  >*/
/* SOURCE ufgculv.for:2970 */
/*<    99  >*/
/* *********************************************************************** */
/* SOURCE ufgculv.for:2973 */
/*<       eps_d=0.0005d0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> tabdir(feq_storage_tabdir, 1);

    /* Function Body */
/* L1: */
/* L2: */
/* L4: */
/* L6: */
/* L8: */
/* L10: */
/* L12: */
/* L14: */
/* L16: */
/* L18: */
/* L19: */
/* L20: */
/* L21: */
/* L22: */
/* L50: */
/* L51: */
/* L52: */
/* L53: */
/* L54: */
/* L55: */
/* L56: */
/* L57: */
/* L58: */
/* L59: */
/* L60: */
/* L61: */
/* L62: */
/* L63: */
/* L64: */
/* L65: */
/* L66: */
/* L67: */
/* L68: */
/* L69: */
/* L70: */
/* L71: */
/* L72: */
/* L73: */
/* L74: */
/* L75: */
/* L76: */
/* L77: */
/* L78: */
/* L79: */
/* L80: */
/* L81: */
/* L82: */
/* L83: */
/* L86: */
/* L87: */
/* L88: */
/* L89: */
/* L90: */
/* L91: */
/* L92: */
/* L93: */
/* L94: */
/* L95: */
/* L96: */
/* L97: */
/* L98: */
/* L99: */
    ufgated_1.feq_gen_eps_d_d_ = 5e-4;
/* SOURCE ufgculv.for:2974 */
/*<       epsarg_d=0.01d0*eps_d >*/
    ufgated_1.feq_gen_epsarg_d_d_ = ufgated_1.feq_gen_eps_d_d_ * .01;
/* SOURCE ufgculv.for:2975 */
/*<       epsf_d=0.00001d0*eps_d >*/
    ufgated_1.feq_gen_epsf_d_d_ = ufgated_1.feq_gen_eps_d_d_ * 1e-5;
/* SOURCE ufgculv.for:2976 */
/*<       epsabs_d=0.0001d0*eps_d >*/
    ufgated_1.feq_gen_epsabs_d_d_ = ufgated_1.feq_gen_eps_d_d_ * 1e-4;
/* SOURCE ufgculv.for:2978 */
/*<       stdout_d=stdout >*/
    ufgated_1.feq_gen_stdout_d_d_ = *stdout;
/*     Establish the function for piezometric level for a full conduit */
/* SOURCE ufgculv.for:2981 */
/*<       ftptemp=ftp >*/
    ftptemp = *ftp;
/* SOURCE ufgculv.for:2983 */
/*<       callconstruct_yoverd(stdout,ftptemp,adrs_yoverd) >*/
    feq_gen_construct_yoverd_d_(stdout, &ftptemp, &ufgated_1.feq_gen_adrs_yoverd_d_);
/*     Define the linear interpolation precision tables. */
/* SOURCE ufgculv.for:2989 */
/*<       key='10001' >*/
    s_copy(key, const_cast<char*>("10001"), (ftnlen)16, (ftnlen)5);
/* SOURCE ufgculv.for:2990 */
/*<       callget_internal_tab_number(stdout,key,eflag,tablt) >*/
    feq_gen_get_internal_tab_number_d_(stdout, key, eflag, &tablt, (ftnlen)16);
/* SOURCE ufgculv.for:2994 */
/*<       tablt=ftpnt(tablt) >*/
    tablt = ftablea_1.ftpnt[tablt - 1];
/* SOURCE ufgculv.for:2995 */
/*<       key='10002' >*/
    s_copy(key, const_cast<char*>("10002"), (ftnlen)16, (ftnlen)5);
/* SOURCE ufgculv.for:2996 */
/*<       callget_internal_tab_number(stdout,key,eflag,tabgt) >*/
    feq_gen_get_internal_tab_number_d_(stdout, key, eflag, &tabgt, (ftnlen)16);
/* SOURCE ufgculv.for:3000 */
/*<       tabgt=ftpnt(tabgt) >*/
    tabgt = ftablea_1.ftpnt[tabgt - 1];
/* SOURCE ufgculv.for:3001 */
/*<       if(tablt.lt.1.or.tabgt.lt.1)then >*/
    if (tablt < 1 || tabgt < 1) {
/* SOURCE ufgculv.for:3002 */
/*<       write(stdout,99) >*/
	feq_gen_io_d__355.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__355);
	e_wsfe();
/* SOURCE ufgculv.for:3003 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE ufgculv.for:3004 */
/*<       return >*/
	return 0;
/* SOURCE ufgculv.for:3005 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:3006 */
/*<       g=grav >*/
    ufcom_1.g = *grav;
/* SOURCE ufgculv.for:3007 */
/*<       grav_d=dble(grav) >*/
    ufgated_1.feq_gen_grav_d_d_ = (doublereal) (*grav);
/* SOURCE ufgculv.for:3008 */
/*<       twog=2.*grav >*/
    ufcom_1.twog = static_cast<double>(*grav) * (float)2.;
/* SOURCE ufgculv.for:3009 */
/*<       twog_d=2.d0*grav_d >*/
    ufgated_1.feq_gen_twog_d_d_ = ufgated_1.feq_gen_grav_d_d_ * 2.;
/*      CALL inline */
/*     I          (STDIN, STDOUT, */
/*     O           LINE) */
/*      READ(LINE,1,ERR=991) TAB, GETQ, GETY2 */
/* SOURCE ufgculv.for:3014 */
/*<       callget_ufgc_tabids(stdin,stdout,eflag) >*/
    feq_gen_get_ufgc_tabids_d_(stdin, stdout, eflag);
/* SOURCE ufgculv.for:3016 */
/*<       callset_ufgc_tabids(tab,getq,gety2,eflag) >*/
    feq_gen_set_ufgc_tabids_d_(&tab, &getq, &gety2, eflag);
/* SOURCE ufgculv.for:3019 */
/*<       write(stdout,50)get_tabid(tab) >*/
    feq_gen_io_d__359.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__359);
    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
    e_wsfe();
/* SOURCE ufgculv.for:3020 */
/*<       write(*,89)get_tabid(tab) >*/
    s_wsfe(&feq_gen_io_d__360);
    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab);
    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
    e_wsfe();
/* SOURCE ufgculv.for:3022 */
/*<       calltabchk(stdout,pmxtab,tab,tabdir,eflag) >*/
    tabchk_(stdout, &feq_gen_c_d_10002, &tab, &tabdir[1], eflag);
/*     Check the GETQ and GETY2 table numbers.  If positive, the tables */
/*     must already exist in the FTAB/ITAB system.  Also both must be */
/*     positive, that is, both tables must be specified. */
/* SOURCE ufgculv.for:3029 */
/*<       if(getq.gt.0)then >*/
    if (getq > 0) {
/* SOURCE ufgculv.for:3030 */
/*<       if(gety2.le.0)then >*/
	if (gety2 <= 0) {
/*         Table for depth at culvert entrance missing. */
/* SOURCE ufgculv.for:3032 */
/*<       write(stdout,51)get_tabid(getq) >*/
	    feq_gen_io_d__361.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__361);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &getq);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    e_wsfe();
/* SOURCE ufgculv.for:3033 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE ufgculv.for:3034 */
/*<       else >*/
	} else {
/*         Both table numbers are positive.  Check to see if the tables */
/*         exist. */
/* SOURCE ufgculv.for:3037 */
/*<       write(stdout,57)get_tabid(getq),get_tabid(gety2) >*/
	    feq_gen_io_d__362.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__362);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &getq);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_4, (ftnlen)16, &gety2);
	    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)16);
	    e_wsfe();
/* SOURCE ufgculv.for:3038 */
/*<       callchktab(6,stdout,ftpnt,mftnum,getq,eflag) >*/
	    chktab_(&feq_gen_c_d_6, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &getq, eflag);
/* SOURCE ufgculv.for:3042 */
/*<       callchktab(6,stdout,ftpnt,mftnum,gety2,eflag) >*/
	    chktab_(&feq_gen_c_d_6, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &gety2, eflag);
/* SOURCE ufgculv.for:3046 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:3047 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:3048 */
/*<       if(gety2.le.0)then >*/
	if (gety2 <= 0) {
/*         Both tables missing. */
/* SOURCE ufgculv.for:3050 */
/*<       write(stdout,55) >*/
	    feq_gen_io_d__363.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__363);
	    e_wsfe();
/* SOURCE ufgculv.for:3051 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE ufgculv.for:3052 */
/*<       else >*/
	} else {
/* SOURCE ufgculv.for:3053 */
/*<       write(stdout,53)get_tabid(gety2) >*/
	    feq_gen_io_d__364.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__364);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &gety2);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    e_wsfe();
/*         Table for culvert flow is missing. */
/* SOURCE ufgculv.for:3055 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE ufgculv.for:3056 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:3057 */
/*<       endif >*/
    }
/*     Get location items that may be present. If they are not present */
/*     they will be set to default values.  The default requests FEQUTL */
/*     to omit the items. */
/* SOURCE ufgculv.for:3062 */
/*<       callget_lctn_items(stdin,stdout,eflag) >*/
    feq_gen_get_lctn_items_d_(stdin, stdout, eflag);
/* SOURCE ufgculv.for:3064 */
/*<        >*/
    feq_gen_set_lctn_items_d_(zone, hgrid, vdatum, unitsys, basis, &easting, &northing,
	     (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE ufgculv.for:3069 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgculv.for:3072 */
/*<       read(line,2,err=991)lab2 >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, lab2, (ftnlen)50);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ufgculv.for:3073 */
/*<       write(stdout,52)lab2 >*/
    feq_gen_io_d__374.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__374);
    do_fio(&feq_gen_c_d_1, lab2, (ftnlen)50);
    e_wsfe();
/* SOURCE ufgculv.for:3075 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgculv.for:3078 */
/*<       callread_tabid(stdout,line,'APPTAB',eflag,apptabid,apptab) >*/
    feq_gen_read_tabid_d_(stdout, line, const_cast<char*>("APPTAB"), eflag, apptabid, &ufcom_1.apptab, (
	    ftnlen)80, (ftnlen)6, (ftnlen)16);
/* SOURCE ufgculv.for:3081 */
/*<       write(stdout,54)apptabid >*/
    feq_gen_io_d__376.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__376);
    do_fio(&feq_gen_c_d_1, apptabid, (ftnlen)16);
    e_wsfe();
/* SOURCE ufgculv.for:3084 */
/*<       if(apptab.le.0)then >*/
    if (ufcom_1.apptab <= 0) {
/* SOURCE ufgculv.for:3085 */
/*<       write(stdout,87) >*/
	feq_gen_io_d__377.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__377);
	e_wsfe();
/* SOURCE ufgculv.for:3086 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE ufgculv.for:3087 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:3088 */
/*<       ef=0 >*/
	ef = 0;
/* SOURCE ufgculv.for:3089 */
/*<       tptab=apptab >*/
	tptab = ufcom_1.apptab;
/* SOURCE ufgculv.for:3090 */
/*<       callchktab(12,stdout,ftpnt,mftnum,apptab,ef) >*/
	chktab_(&feq_gen_c_d_12, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &ufcom_1.apptab, &
		ef);
/* SOURCE ufgculv.for:3094 */
/*<       if(ef.eq.0)then >*/
	if (ef == 0) {
/* SOURCE ufgculv.for:3095 */
/*<       apptab_d=apptab >*/
	    ufgated_1.feq_gen_apptab_d_d_ = ufcom_1.apptab;
/*         Find the invert elevation and station  from the table */
/* SOURCE ufgculv.for:3097 */
/*<       callfndelv(tptab,stdout,eflag,z1b) >*/
	    fndelv_(&tptab, stdout, eflag, &ufcom_1.z1b);
/* SOURCE ufgculv.for:3100 */
/*<       z1b_d=dble(z1b) >*/
	    ufgated_1.feq_gen_z1b_d_d_ = (doublereal) ufcom_1.z1b;
/* SOURCE ufgculv.for:3102 */
/*<       callfndsta(tptab,stdout,eflag,tp) >*/
	    fndsta_(&tptab, stdout, eflag, &tp);
/* SOURCE ufgculv.for:3105 */
/*<       station_1=dble(tp) >*/
	    feq_gen_station_1_d_ = (doublereal) tp;
/* SOURCE ufgculv.for:3107 */
/*<       else >*/
	} else {
/* SOURCE ufgculv.for:3108 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE ufgculv.for:3109 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:3110 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:3113 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgculv.for:3116 */
/*<       callread_tabid(stdout,line,'DEPTAB',eflag,deptabid,deptab) >*/
    feq_gen_read_tabid_d_(stdout, line, const_cast<char*>("DEPTAB"), eflag, deptabid, &ufcom_1.deptab, (
	    ftnlen)80, (ftnlen)6, (ftnlen)16);
/* SOURCE ufgculv.for:3119 */
/*<       write(stdout,56)deptabid >*/
    feq_gen_io_d__383.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__383);
    do_fio(&feq_gen_c_d_1, deptabid, (ftnlen)16);
    e_wsfe();
/* SOURCE ufgculv.for:3121 */
/*<       if(deptab.le.0)then >*/
    if (ufcom_1.deptab <= 0) {
/* SOURCE ufgculv.for:3122 */
/*<       write(stdout,87) >*/
	feq_gen_io_d__384.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__384);
	e_wsfe();
/* SOURCE ufgculv.for:3123 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE ufgculv.for:3124 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:3125 */
/*<       ef=0 >*/
	ef = 0;
/* SOURCE ufgculv.for:3126 */
/*<       tptab=deptab >*/
	tptab = ufcom_1.deptab;
/* SOURCE ufgculv.for:3127 */
/*<       callchktab(1,stdout,ftpnt,mftnum,deptab,ef) >*/
	chktab_(&feq_gen_c_d_1, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &ufcom_1.deptab, &
		ef);
/* SOURCE ufgculv.for:3131 */
/*<       if(ef.eq.0)then >*/
	if (ef == 0) {
/*         Find the invert elevation from the table */
/* SOURCE ufgculv.for:3133 */
/*<       callfndelv(tptab,stdout,eflag,z4b) >*/
	    fndelv_(&tptab, stdout, eflag, &ufcom_1.z4b);
/* SOURCE ufgculv.for:3136 */
/*<       else >*/
	} else {
/* SOURCE ufgculv.for:3137 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE ufgculv.for:3138 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:3139 */
/*<       endif >*/
    }
/*     For the moment make Z3B the same as Z4B.  Note that */
/*     the table called the departure table will give the */
/*     cross section that defines the upstream hydrostatic pressure */
/*     force on the control volume downstream of the underflow */
/*     gate.  An optional table, to be added later will give */
/*     the table for computing the momentum flux exiting from the */
/*     control volume. */
/* SOURCE ufgculv.for:3149 */
/*<       z3b=z4b >*/
    ufcom_1.z3b = ufcom_1.z4b;
/* SOURCE ufgculv.for:3151 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgculv.for:3154 */
/*<       read(line,8,err=991)z2b >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_8;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.z2b, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ufgculv.for:3156 */
/*<       write(stdout,58)z2b >*/
    feq_gen_io_d__385.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__385);
    do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.z2b, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE ufgculv.for:3158 */
/*<       if(z2b.lt.z4b)then >*/
    if (ufcom_1.z2b < ufcom_1.z4b) {
/* SOURCE ufgculv.for:3159 */
/*<       write(stdout,90)z2b,z4b >*/
	feq_gen_io_d__386.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__386);
	do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.z2b, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.z4b, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE ufgculv.for:3160 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE ufgculv.for:3161 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:3162 */
/*<       if(z2b.lt.z1b)then >*/
    if (ufcom_1.z2b < ufcom_1.z1b) {
/* SOURCE ufgculv.for:3163 */
/*<       write(stdout,98)z2b,z1b >*/
	feq_gen_io_d__387.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__387);
	do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.z2b, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.z1b, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE ufgculv.for:3164 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE ufgculv.for:3165 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:3167 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgculv.for:3170 */
/*<       read(line,10,err=991)bg >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_10;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.bg, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ufgculv.for:3171 */
/*<       write(stdout,60)bg >*/
    feq_gen_io_d__388.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__388);
    do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.bg, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE ufgculv.for:3173 */
/*<       if(bg.le.0.0)then >*/
    if (ufcom_1.bg <= (float)0.) {
/* SOURCE ufgculv.for:3174 */
/*<       write(stdout,91)bg >*/
	feq_gen_io_d__389.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__389);
	do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.bg, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE ufgculv.for:3175 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE ufgculv.for:3176 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:3177 */
/*<       bg_d=bg >*/
    ufgated_1.feq_gen_bg_d_d_ = ufcom_1.bg;
/* SOURCE ufgculv.for:3179 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgculv.for:3182 */
/*<       read(line,12,err=991)cd >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_12;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.cd, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ufgculv.for:3183 */
/*<       write(stdout,62) >*/
    feq_gen_io_d__390.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__390);
    e_wsfe();
/*      IF(CD.LE.0.0.OR.CD.GT.1.0) THEN */
/*        WRITE(STDOUT,92) CD */
/*        EFLAG = 1 */
/*      ENDIF */
/* SOURCE ufgculv.for:3190 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgculv.for:3193 */
/*<       callread_tabid(stdout,line,'CCTAB',eflag,cctabid,cctab) >*/
    feq_gen_read_tabid_d_(stdout, line, const_cast<char*>("CCTAB"), eflag, cctabid, &cctab, (ftnlen)80, (
	    ftnlen)5, (ftnlen)16);
/* SOURCE ufgculv.for:3196 */
/*<       write(stdout,64)cctabid >*/
    feq_gen_io_d__393.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__393);
    do_fio(&feq_gen_c_d_1, cctabid, (ftnlen)16);
    e_wsfe();
/* SOURCE ufgculv.for:3197 */
/*<       if(cctab.lt.0)then >*/
    if (cctab < 0) {
/* SOURCE ufgculv.for:3198 */
/*<       write(stdout,87) >*/
	feq_gen_io_d__394.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__394);
	e_wsfe();
/* SOURCE ufgculv.for:3199 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE ufgculv.for:3200 */
/*<       elseif(cctab.gt.0)then >*/
    } else if (cctab > 0) {
/* SOURCE ufgculv.for:3201 */
/*<       callchktab(2,stdout,ftpnt,mftnum,cctab,eflag) >*/
	chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &cctab, eflag);
/* SOURCE ufgculv.for:3205 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:3207 */
/*<       cctab_d=cctab >*/
    ufgated_1.feq_gen_cctab_d_d_ = cctab;
/*     Get the size of the transition between FW and FO flow. */
/* SOURCE ufgculv.for:3210 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgculv.for:3213 */
/*<       read(line,19,err=991)fwfotr >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_19;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&fwfotr, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ufgculv.for:3214 */
/*<       if(fwfotr.eq.0.0)fwfotr=0.1 >*/
    if (fwfotr == (float)0.) {
	fwfotr = (float).1;
    }
/* SOURCE ufgculv.for:3215 */
/*<       write(stdout,79)fwfotr >*/
    feq_gen_io_d__396.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__396);
    do_fio(&feq_gen_c_d_1, (char *)&fwfotr, (ftnlen)sizeof(real));
    e_wsfe();
/*     Get the maximum upstream head */
/* SOURCE ufgculv.for:3219 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgculv.for:3222 */
/*<       read(line,20,err=991)maxhu >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_20;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&maxhu, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ufgculv.for:3223 */
/*<       write(stdout,80)maxhu >*/
    feq_gen_io_d__398.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__398);
    do_fio(&feq_gen_c_d_1, (char *)&maxhu, (ftnlen)sizeof(real));
    e_wsfe();
/*     Get the smallest non-zero upstream head */
/* SOURCE ufgculv.for:3226 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgculv.for:3229 */
/*<       read(line,21,err=991)minhu >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_21;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&minhu, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ufgculv.for:3230 */
/*<       if(minhu.eq.0.0)minhu=0.1 >*/
    if (minhu == (float)0.) {
	minhu = (float).1;
    }
/* SOURCE ufgculv.for:3231 */
/*<       write(stdout,81)minhu >*/
    feq_gen_io_d__400.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__400);
    do_fio(&feq_gen_c_d_1, (char *)&minhu, (ftnlen)sizeof(real));
    e_wsfe();
/*     Get the global linear interpolation precisions */
/* SOURCE ufgculv.for:3234 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgculv.for:3237 */
/*<       read(line,22,err=991)liprec >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_22;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
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
/* SOURCE ufgculv.for:3238 */
/*<       if(liprec.eq.0.0)liprec=0.02 >*/
    if (liprec == (float)0.) {
	liprec = (float).02;
    }
/* SOURCE ufgculv.for:3239 */
/*<       write(stdout,82)liprec >*/
    feq_gen_io_d__402.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__402);
    do_fio(&feq_gen_c_d_1, (char *)&liprec, (ftnlen)sizeof(real));
    e_wsfe();
/*     Process the gate opening table. */
/* SOURCE ufgculv.for:3242 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgculv.for:3245 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__403.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__403);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE ufgculv.for:3246 */
/*<       write(stdout,'(A)')line >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
    e_wsfe();
/* SOURCE ufgculv.for:3249 */
/*<       just='RIGHT' >*/
    s_copy(just, const_cast<char*>("RIGHT"), (ftnlen)5, (ftnlen)5);
/* SOURCE ufgculv.for:3250 */
/*<        >*/
    feq_gen_get_item_limits_d_(stdout, line, &feq_gen_c_d_4, just, &nitem, feq_gen_item_start_d_, 
	    feq_gen_item_end_d_, (ftnlen)80, (ftnlen)5);
/*     Set the  column width */
/* SOURCE ufgculv.for:3254 */
/*<       colwidth=item_end(2)-item_start(2)+1 >*/
    colwidth = feq_gen_item_end_d_[1] - feq_gen_item_start_d_[1] + 1;
/* SOURCE ufgculv.for:3257 */
/*<       oldhg=0.0 >*/
    oldhg = (float)0.;
/* SOURCE ufgculv.for:3258 */
/*<       nhg=1 >*/
    nhg = 1;
/* SOURCE ufgculv.for:3259 */
/*<       idlen=0 >*/
    idlen = 0;
/* SOURCE ufgculv.for:3260 */
/*<   100 continue >*/
L100:
/* SOURCE ufgculv.for:3261 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgculv.for:3264 */
/*<        >*/
    feq_gen_read_ufgate_items_d_(stdout, line, &nitem, feq_gen_item_start_d_, feq_gen_item_end_d_, eflag,
	     &idlen, &hgvec[nhg - 1], &tab2d[nhg - 1], &ccval[nhg - 1], &
	    angle[nhg - 1], (ftnlen)80);
/*        READ(LINE,'(F10.0, I10, 4F10.0)') HGVEC(NHG), TAB2D(NHG), */
/*     A                      CCVAL(NHG), ANGLE(NHG) */
/*     B                      MNHVEC(NHG), LIPVEC(NHG) */
/* SOURCE ufgculv.for:3272 */
/*<       mnhvec(nhg)=0.0 >*/
    mnhvec[nhg - 1] = (float)0.;
/* SOURCE ufgculv.for:3273 */
/*<       lipvec(nhg)=0.0 >*/
    lipvec[nhg - 1] = (float)0.;
/* SOURCE ufgculv.for:3274 */
/*<       if(hgvec(nhg).le.oldhg)then >*/
    if (hgvec[nhg - 1] <= oldhg) {
/*         Input complete. */
/* SOURCE ufgculv.for:3276 */
/*<       nhg=nhg-1 >*/
	--nhg;
/* SOURCE ufgculv.for:3277 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:3278 */
/*<       oldhg=hgvec(nhg) >*/
	oldhg = hgvec[nhg - 1];
/* SOURCE ufgculv.for:3279 */
/*<       if(mnhvec(nhg).eq.0.0)then >*/
	if (mnhvec[nhg - 1] == (float)0.) {
/* SOURCE ufgculv.for:3280 */
/*<       mnhvec(nhg)=minhu >*/
	    mnhvec[nhg - 1] = minhu;
/* SOURCE ufgculv.for:3281 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:3282 */
/*<       if(lipvec(nhg).eq.0.0)then >*/
	if (lipvec[nhg - 1] == (float)0.) {
/* SOURCE ufgculv.for:3283 */
/*<       lipvec(nhg)=liprec >*/
	    lipvec[nhg - 1] = liprec;
/* SOURCE ufgculv.for:3284 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:3285 */
/*<       id=get_tabid(tab2d(nhg)) >*/
	feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &tab2d[nhg - 1]);
	s_copy(id, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE ufgculv.for:3286 */
/*<       idout=' ' >*/
	s_copy(idout, const_cast<char*>(" "), (ftnlen)32, (ftnlen)1);
/* SOURCE ufgculv.for:3287 */
/*<       idout(colwidth-idlen+1:colwidth)=id(1:idlen) >*/
	feq_gen_i_d_1 = colwidth - idlen;
	s_copy(idout + feq_gen_i_d_1, id, colwidth - feq_gen_i_d_1, idlen);
/* SOURCE ufgculv.for:3288 */
/*<        >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(F10.3,A,F10.3,F10.1,F10.2,F10.3)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&hgvec[nhg - 1], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, idout, colwidth);
	do_fio(&feq_gen_c_d_1, (char *)&ccval[nhg - 1], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&angle[nhg - 1], (ftnlen)sizeof(real));
	e_wsfe();
/*     C           MNHVEC(NHG), LIPVEC(NHG) */
/* SOURCE ufgculv.for:3292 */
/*<       calltabchk(stdout,pmxtab,tab2d(nhg),tabdir,eflag) >*/
	tabchk_(stdout, &feq_gen_c_d_10002, &tab2d[nhg - 1], &tabdir[1], eflag);
/* SOURCE ufgculv.for:3295 */
/*<       if(cctab.eq.0.0)then >*/
	if ((real) cctab == (float)0.) {
/*           If no table is given for contraction coefficient, then */
/*           a value must be given by the user. */
/* SOURCE ufgculv.for:3298 */
/*<       if(ccval(nhg).le.0.0.or.ccval(nhg).gt.1.0)then >*/
	    if (ccval[nhg - 1] <= (float)0. || ccval[nhg - 1] > (float)1.) {
/* SOURCE ufgculv.for:3299 */
/*<       write(stdout,93)ccval(nhg) >*/
		feq_gen_io_d__420.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__420);
		do_fio(&feq_gen_c_d_1, (char *)&ccval[nhg - 1], (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE ufgculv.for:3300 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE ufgculv.for:3301 */
/*<       endif >*/
	    }
/* SOURCE ufgculv.for:3302 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:3303 */
/*<       nhg=nhg+1 >*/
	++nhg;
/* SOURCE ufgculv.for:3304 */
/*<       goto100 >*/
	goto L100;
/* SOURCE ufgculv.for:3305 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:3307 */
/*<       if(nhg.lt.2)then >*/
    if (nhg < 2) {
/* SOURCE ufgculv.for:3308 */
/*<       write(stdout,98) >*/
	feq_gen_io_d__421.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__421);
	e_wsfe();
/* SOURCE ufgculv.for:3309 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE ufgculv.for:3310 */
/*<       endif >*/
    }
/*     Now get the description of the barrel.  The descriptive values */
/*     are stored in common block in the include file UFGC.COM */
/* SOURCE ufgculv.for:3315 */
/*<       callinput_barrel(stdin,stdout,sfac,eflag) >*/
    feq_gen_input_barrel_d_(stdin, stdout, &sfac, eflag);
/*     Adjust the station at the approach section now that SFAC is */
/*     available. */
/* SOURCE ufgculv.for:3322 */
/*<       station_1=station_1*sfac >*/
    feq_gen_station_1_d_ *= sfac;
/*     INPUT THE FACTORS CONTROLLING THE DISTRIBUTION OF DROPS */
/* SOURCE ufgculv.for:3328 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgculv.for:3331 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__423.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__423);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE ufgculv.for:3332 */
/*<       write(stdout,'(A)')line >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
    e_wsfe();
/* SOURCE ufgculv.for:3334 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgculv.for:3337 */
/*<       read(line,16,err=991)minpfd >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_16;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&minpfd, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ufgculv.for:3338 */
/*<       write(stdout,66)minpfd >*/
    feq_gen_io_d__425.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__425);
    do_fio(&feq_gen_c_d_1, (char *)&minpfd, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE ufgculv.for:3340 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgculv.for:3343 */
/*<       read(line,16,err=991)brkpfd >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_16;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&brkpfd, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ufgculv.for:3344 */
/*<       write(stdout,67)brkpfd >*/
    feq_gen_io_d__427.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__427);
    do_fio(&feq_gen_c_d_1, (char *)&brkpfd, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE ufgculv.for:3346 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgculv.for:3349 */
/*<       read(line,18,err=991)limpfd >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_18;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&limpfd, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ufgculv.for:3350 */
/*<       write(stdout,68)limpfd >*/
    feq_gen_io_d__429.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__429);
    do_fio(&feq_gen_c_d_1, (char *)&limpfd, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE ufgculv.for:3352 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgculv.for:3355 */
/*<       read(line,16,err=991)finpow >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_16;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&finpow, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ufgculv.for:3356 */
/*<       write(stdout,69)finpow >*/
    feq_gen_io_d__431.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__431);
    do_fio(&feq_gen_c_d_1, (char *)&finpow, (ftnlen)sizeof(real));
    e_wsfe();
/*     COMPUTE THE PROPORTIONS OF FREE DROP */
/* SOURCE ufgculv.for:3361 */
/*<       pow=0.5 >*/
    pow = (float).5;
/* SOURCE ufgculv.for:3362 */
/*<       offset=0.0 >*/
    offset = (float)0.;
/* SOURCE ufgculv.for:3363 */
/*<        >*/
    lstopf_(stdout, &tablt, &tabgt, &pow, &offset, &minpfd, &brkpfd, &liprec, 
	    &feq_gen_c_d_351, &n, xbrk, eflag);
/* SOURCE ufgculv.for:3368 */
/*<       work(1)=0.0 >*/
    work[0] = (float)0.;
/* SOURCE ufgculv.for:3369 */
/*<       do195i=1,n >*/
    feq_gen_i_d_1 = n;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ufgculv.for:3370 */
/*<       work(i+1)=xbrk(i) >*/
	work[feq_gen_i_d_] = xbrk[feq_gen_i_d_ - 1];
/* SOURCE ufgculv.for:3371 */
/*<   195 continue >*/
/* L195: */
    }
/* SOURCE ufgculv.for:3372 */
/*<       nfrac=n+1 >*/
    nfrac = n + 1;
/*      OFFSET = 0.9*BRKPFD */
/* SOURCE ufgculv.for:3374 */
/*<       offset=0.0 >*/
    offset = (float)0.;
/* SOURCE ufgculv.for:3375 */
/*<        >*/
    lstopf_(stdout, &tablt, &tabgt, &finpow, &offset, &brkpfd, &limpfd, &
	    liprec, &feq_gen_c_d_351, &n, xbrk, eflag);
/* SOURCE ufgculv.for:3379 */
/*<       do196i=2,n >*/
    feq_gen_i_d_1 = n;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ufgculv.for:3380 */
/*<       work(nfrac+i-1)=xbrk(i) >*/
	work[nfrac + feq_gen_i_d_ - 2] = xbrk[feq_gen_i_d_ - 1];
/* SOURCE ufgculv.for:3381 */
/*<   196 continue >*/
/* L196: */
    }
/* SOURCE ufgculv.for:3382 */
/*<       nfrac=nfrac+n-1 >*/
    nfrac = nfrac + n - 1;
/*      WORK(N+2) = 0.95 */
/*      WORK(N+3) = 0.975 */
/*      WORK(N+4) = 0.98 */
/*      WORK(N+5) = 0.99 */
/* SOURCE ufgculv.for:3388 */
/*<       work(nfrac+1)=1.0 >*/
    work[nfrac] = (float)1.;
/* SOURCE ufgculv.for:3389 */
/*<       nfrac=nfrac+1 >*/
    ++nfrac;
/* SOURCE ufgculv.for:3391 */
/*<       pfdvec(1)=work(1) >*/
    pfdvec[0] = work[0];
/* SOURCE ufgculv.for:3392 */
/*<       pfdvec(2)=work(2) >*/
    pfdvec[1] = work[1];
/* SOURCE ufgculv.for:3393 */
/*<       j=2 >*/
    j = 2;
/* SOURCE ufgculv.for:3394 */
/*<       do201i=3,nfrac-1 >*/
    feq_gen_i_d_1 = nfrac - 1;
    for (feq_gen_i_d_ = 3; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ufgculv.for:3395 */
/*<       j=j+1 >*/
	++j;
/* SOURCE ufgculv.for:3396 */
/*<       pfdvec(j)=0.5*(work(i)+work(i-1)) >*/
	pfdvec[j - 1] = static_cast<double>((static_cast<double>(work[feq_gen_i_d_ - 1]) + work[feq_gen_i_d_ - 2])) * (float).5;
/* SOURCE ufgculv.for:3397 */
/*<       j=j+1 >*/
	++j;
/* SOURCE ufgculv.for:3398 */
/*<       pfdvec(j)=work(i) >*/
	pfdvec[j - 1] = work[feq_gen_i_d_ - 1];
/* SOURCE ufgculv.for:3399 */
/*<   201 continue >*/
/* L201: */
    }
/* SOURCE ufgculv.for:3400 */
/*<       pfdvec(j+1)=work(nfrac) >*/
    pfdvec[j] = work[nfrac - 1];
/* SOURCE ufgculv.for:3401 */
/*<       nfrac=j+1 >*/
    nfrac = j + 1;
/*      DO 202 I=1,NFRAC */
/*        WRITE(STDOUT,*) ' I=',I,' PFDVEC(I)=',PFDVEC(I) */
/* 202   CONTINUE */
/* SOURCE ufgculv.for:3406 */
/*<       if(eflag.ne.0)return >*/
    if (*eflag != 0) {
	return 0;
    }
/*     INPUT OF DATA COMPLETE.  BEGIN THE COMPUTATIONS. */
/* SOURCE ufgculv.for:3409 */
/*<       hdatum=z2b >*/
    hdatum = ufcom_1.z2b;
/* SOURCE ufgculv.for:3410 */
/*<       hdatum_d=dble(hdatum) >*/
    ufgated_1.feq_gen_hdatum_d_d_ = (doublereal) hdatum;
/*     Prepare a 1-D table giving the head at section 1 as a */
/*     function of the depth in the entrance to the culvert */
/*     for culvert flow. */
/* SOURCE ufgculv.for:3415 */
/*<       callmake_h1_vs_y2_for_culv(stdout,gety2,ftptemp,h1vsy2,eflag) >*/
    feq_gen_make_h1_vs_y2_for_culv_d_(stdout, &gety2, &ftptemp, &h1vsy2, eflag);
/*     Set the head datum for the heads in the table, H1VSY2. */
/*     They may differ from the head here. */
/* SOURCE ufgculv.for:3423 */
/*<       hdatum_for_h1vsy2=gethdd(gety2) >*/
    feq_gen_hdatum_for_h1vsy2_d_ = gethdd_(&gety2);
/*     Lookup the characteristics of the full barrel.  We assume */
/*     a prismatic barrel. */
/* SOURCE ufgculv.for:3427 */
/*<       vert_d=vert_dvec(nxs) >*/
    ufgc1_1.feq_gen_vert_d_d_ = ufgc1_1.feq_gen_vert_dvec_d_[ufgc1_1.nxs - 1];
/* SOURCE ufgculv.for:3428 */
/*<       tp=sngl(vert_d) >*/
    tp = (real) ufgc1_1.feq_gen_vert_d_d_;
/* SOURCE ufgculv.for:3429 */
/*<       callxlkt21(xsec_adrs(nxs),tp,afull,tt,dtt,jfull,kfull,dk,b,db) >*/
    xlkt21_(&ufgc1_1.feq_gen_xsec_adrs_d_[ufgc1_1.nxs - 1], &tp, &afull, &ufcom_1.tt, &
	    ufcom_1.dtt, &jfull, &kfull, &dk, &b, &db);
/* SOURCE ufgculv.for:3433 */
/*<       afull_d=dble(afull) >*/
    ufgated_1.feq_gen_afull_d_d_ = (doublereal) afull;
/* SOURCE ufgculv.for:3434 */
/*<       jfull_d=dble(jfull) >*/
    ufgated_1.feq_gen_jfull_d_d_ = (doublereal) jfull;
/* SOURCE ufgculv.for:3435 */
/*<       kfull_d=dble(kfull) >*/
    ufgated_1.feq_gen_kfull_d_d_ = (doublereal) kfull;
/*     Find the elevation of the exit invert */
/* SOURCE ufgculv.for:3438 */
/*<       zbex_d=invert_z(nxs) >*/
    ufgated_1.feq_gen_zbex_d_d_ = ufgc1_1.feq_gen_invert_z_d_[ufgc1_1.nxs - 1];
/* SOURCE ufgculv.for:3440 */
/*<       z3b=zbex_d >*/
    ufcom_1.z3b = ufgated_1.feq_gen_zbex_d_d_;
/* SOURCE ufgculv.for:3442 */
/*<       bigerr=0.0 >*/
    bigerr = (float)0.;
/* SOURCE ufgculv.for:3443 */
/*<       rms=0.0 >*/
    rms = (float)0.;
/* SOURCE ufgculv.for:3444 */
/*<       nrms=0 >*/
    nrms = 0;
/* SOURCE ufgculv.for:3445 */
/*<       oldhg=0.0 >*/
    oldhg = (float)0.;
/* SOURCE ufgculv.for:3446 */
/*<       do1000ihg=1,nhg >*/
    feq_gen_i_d_1 = nhg;
    for (ihg = 1; ihg <= feq_gen_i_d_1; ++ihg) {
/* SOURCE ufgculv.for:3447 */
/*<       elflag=0 >*/
	elflag = 0;
/* SOURCE ufgculv.for:3448 */
/*<       hg=hgvec(ihg) >*/
	ufcom_1.hg = hgvec[ihg - 1];
/* SOURCE ufgculv.for:3449 */
/*<       hg_d=dble(hg) >*/
	ufgated_1.feq_gen_hg_d_d_ = (doublereal) ufcom_1.hg;
/* SOURCE ufgculv.for:3450 */
/*<       write(hglab,'(''Hg='',F6.3,'':'')')hg >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 10;
	feq_gen_ici_d_1.iciunit = hglab;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("('Hg=',F6.3,':')");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.hg, (ftnlen)sizeof(real));
	e_wsfi();
/* SOURCE ufgculv.for:3451 */
/*<       label=hglab//lab2 >*/
/* Writing concatenation */
	feq_gen_i_d_2[0] = 10, feq_gen_a_d_1[0] = hglab;
	feq_gen_i_d_2[1] = 50, feq_gen_a_d_1[1] = lab2;
	s_cat(label, feq_gen_a_d_1, feq_gen_i_d_2, &feq_gen_c_d_2, (ftnlen)50);
/* SOURCE ufgculv.for:3452 */
/*<       minhu=mnhvec(ihg) >*/
	minhu = mnhvec[ihg - 1];
/* SOURCE ufgculv.for:3453 */
/*<       prec=lipvec(ihg) >*/
	prec = lipvec[ihg - 1];
/* SOURCE ufgculv.for:3454 */
/*<       concc=ccval(ihg) >*/
	concc = ccval[ihg - 1];
/* SOURCE ufgculv.for:3455 */
/*<       concc_d=concc >*/
	ufgated_1.feq_gen_concc_d_d_ = concc;
/* SOURCE ufgculv.for:3457 */
/*<       write(*,73)hg >*/
	s_wsfe(&feq_gen_io_d__459);
	do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.hg, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE ufgculv.for:3458 */
/*<       write(stdout,70)hg,tab2d(ihg) >*/
	feq_gen_io_d__460.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__460);
	do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.hg, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&tab2d[ihg - 1], (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE ufgculv.for:3460 */
/*<       ag=bg*hg >*/
	ufcom_1.ag = static_cast<double>(ufcom_1.bg) * ufcom_1.hg;
/*       Find the free  flow(FW flow ) that exists when critical depth */
/*       in the gate opening equals the gate opening. */
/* SOURCE ufgculv.for:3464 */
/*<       y2=hg >*/
	ufcom_1.y2 = ufcom_1.hg;
/* SOURCE ufgculv.for:3465 */
/*<       calllktab(h1vsy2,y2,0,h1fwul,ntab,deriv) >*/
	lktab_(&h1vsy2, &ufcom_1.y2, &feq_gen_c_d_0, &h1fwul, &ntab, &deriv);
/* SOURCE ufgculv.for:3469 */
/*<       z1fwul=h1fwul+hdatum_for_h1vsy2 >*/
	z1fwul = static_cast<double>(h1fwul) + feq_gen_hdatum_for_h1vsy2_d_;
/* SOURCE ufgculv.for:3470 */
/*<       h1fwul=z1fwul-hdatum >*/
	h1fwul = static_cast<double>(z1fwul) - hdatum;
/* SOURCE ufgculv.for:3471 */
/*<       hstuff(ihg,1)=h1fwul/hg >*/
	hstuff[ihg - 1] = static_cast<double>(h1fwul) / ufcom_1.hg;
/* SOURCE ufgculv.for:3472 */
/*<       h1fwul_d=dble(h1fwul) >*/
	feq_gen_h1fwul_d_d_ = (doublereal) h1fwul;
/*       Compute the gate-opening ratio for the free-weir flow limit. */
/* SOURCE ufgculv.for:3474 */
/*<       rgfwul=hg/h1fwul >*/
	rgfwul = static_cast<double>(ufcom_1.hg) / h1fwul;
/* SOURCE ufgculv.for:3476 */
/*<       write(stdout,71)h1fwul,rgfwul >*/
	feq_gen_io_d__468.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__468);
	do_fio(&feq_gen_c_d_1, (char *)&h1fwul, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&rgfwul, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE ufgculv.for:3478 */
/*<        >*/
	tdlk13_(stdout, &getq, &feq_gen_c_d_13, &feq_gen_c_d_0, &c_b72, &c_b72, &z1fwul, &
		feq_gen_hdatum_for_h1vsy2_d_, &q, &dqed, &dqeu, &free);
/* SOURCE ufgculv.for:3482 */
/*<       qd=q >*/
	ufgc1_1.qd = q;
/* SOURCE ufgculv.for:3483 */
/*<       write(stdout,83)q >*/
	feq_gen_io_d__473.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__473);
	do_fio(&feq_gen_c_d_1, (char *)&q, (ftnlen)sizeof(real));
	e_wsfe();
/*       Find the tailwater elevation at the limit of FW flow */
/*       at the upper limit for FW flow at section 1, that is, H1FWUL. */
/* SOURCE ufgculv.for:3488 */
/*<       calltd13_fdrop(stdout,gety2,13,h1fwul,hdatum_for_h1vsy2,fdrop) >*/
	feq_gen_td13_fdrop_d_(stdout, &gety2, &feq_gen_c_d_13, &h1fwul, &feq_gen_hdatum_for_h1vsy2_d_, &
		fdrop);
/* SOURCE ufgculv.for:3493 */
/*<       hstuff(ihg,2)=(h1fwul-fdrop)/hg >*/
	hstuff[ihg + 39] = static_cast<double>((static_cast<double>(h1fwul) - fdrop)) / ufcom_1.hg;
/*       Find the tailwater level that causes the water to contact */
/*       the gate lip when the head at section 1 is midway between */
/*       HG and H1FWUL. */
/* SOURCE ufgculv.for:3498 */
/*<       z1=0.5*(hg+h1fwul)+hdatum >*/
	z1 = static_cast<double>(static_cast<double>((static_cast<double>(ufcom_1.hg) + h1fwul)) * (float).5) + hdatum;
/* SOURCE ufgculv.for:3500 */
/*<       callfind_y4sw(stdout,z1,z2b,z4b,gety2,hg_d,epsarg_d,epsf_d,y4sw_d) >*/
	feq_gen_find_y4sw_d_(stdout, &z1, &ufcom_1.z2b, &ufcom_1.z4b, &gety2, &
		ufgated_1.feq_gen_hg_d_d_, &ufgated_1.feq_gen_epsarg_d_d_, &ufgated_1.feq_gen_epsf_d_d_, 
		&feq_gen_y4sw_d_d_);
/* SOURCE ufgculv.for:3505 */
/*<       hstuff(ihg,3)=(y4sw_d+z4b-hdatum)/hg >*/
	hstuff[ihg + 79] = (feq_gen_y4sw_d_d_ + ufcom_1.z4b - hdatum) / ufcom_1.hg;
/*       Find the elevation at the vc for the current gate opening */
/* SOURCE ufgculv.for:3508 */
/*<       calllkt_zb(1,station(1)+hg_d,zbvc_d) >*/
	feq_gen_d_d_1 = ufgc1_1.station[0] + ufgated_1.feq_gen_hg_d_d_;
	feq_gen_lkt_zb_d_(&feq_gen_c_d_1, &feq_gen_d_d_1, &ufgated_1.feq_gen_zbvc_d_d_);
/*       Determine if FC flow exists and find its limits.  FC flow */
/*       is flow at the barrel exit that drowns flow under the gate. */
/*       The flow can be critical at the exit or the barrel can be */
/*       full and barrel resistance can cause the flow under the */
/*       gate to be drowned. */
/*       Find the the contraction coefficient that causes the flow */
/*       at the FW limit to be matched by the SO equation. */
/*       Find the critical depth that will support full barrel */
/*       flow */
/* SOURCE ufgculv.for:3524 */
/*<       callfind_fb_ycrit(stdout,fb_ratio) >*/
	feq_gen_find_fb_ycrit_d_(stdout, &ufgated_1.feq_gen_fb_ratio_d_);
/*       Set an increment above the full-barrel ratio for critical */
/*       depth for overlap between full-barrel computations and */
/*       free-surface computations. */
/* SOURCE ufgculv.for:3531 */
/*<       fs_ratio=fb_ratio+0.125d0*(1.d0-fb_ratio) >*/
	ufgated_1.feq_gen_fs_ratio_d_ = ufgated_1.feq_gen_fb_ratio_d_ + (1. - 
		ufgated_1.feq_gen_fb_ratio_d_) * .125;
/* SOURCE ufgculv.for:3533 */
/*<       write(stdout,65)fb_ratio,fs_ratio >*/
	feq_gen_io_d__477.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__477);
	do_fio(&feq_gen_c_d_1, (char *)&ufgated_1.feq_gen_fb_ratio_d_, (ftnlen)sizeof(
		doublereal));
	do_fio(&feq_gen_c_d_1, (char *)&ufgated_1.feq_gen_fs_ratio_d_, (ftnlen)sizeof(
		doublereal));
	e_wsfe();
/*       Find the critical and normal depths. Make starting guesses. */
/* SOURCE ufgculv.for:3537 */
/*<       ycrit=dble(y2) >*/
	ycrit = (doublereal) ufcom_1.y2;
/* SOURCE ufgculv.for:3538 */
/*<       ynorm=0.5d0*vert_d >*/
	ynorm = ufgc1_1.feq_gen_vert_d_d_ * .5;
/* SOURCE ufgculv.for:3539 */
/*<        >*/
	feq_gen_get_ycynym_d_(stdout, &ufgc1_1.station[ufgc1_1.nxs - 1], &
		ufgated_1.feq_gen_epsarg_d_d_, &ufgated_1.feq_gen_epsf_d_d_, &
		ufgated_1.feq_gen_epsabs_d_d_, &ycrit, &ynorm, &ymax, &rflag);
/* SOURCE ufgculv.for:3544 */
/*<       if(rflag.lt.0)then >*/
	if (rflag < 0) {
/* SOURCE ufgculv.for:3545 */
/*<       write(stdout,*)' Problem with critical depth comp. FC flow' >*/
	    feq_gen_io_d__482.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__482);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Problem with critical depth comp. FC flow"),
		     (ftnlen)42);
	    e_wsle();
/* SOURCE ufgculv.for:3546 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE ufgculv.for:3547 */
/*<       endif >*/
	}
/*        WRITE(STDOUT,*) ' YCRIT=',YCRIT */
/*        WRITE(STDOUT,*) ' YNORM=',YNORM */
/* SOURCE ufgculv.for:3552 */
/*<       if(ynorm.gt.ycrit.or.ynorm.lt.0.d0)then >*/
	if (ynorm > ycrit || ynorm < 0.) {
/* SOURCE ufgculv.for:3553 */
/*<       ys=ycrit*1.0001d0 >*/
	    ys = ycrit * 1.0001;
/* SOURCE ufgculv.for:3554 */
/*<       xs=station(nxs) >*/
	    xs = ufgc1_1.station[ufgc1_1.nxs - 1];
/* SOURCE ufgculv.for:3555 */
/*<       xe=station(1)+hg_d >*/
	    xe = ufgc1_1.station[0] + ufgated_1.feq_gen_hg_d_d_;
/* SOURCE ufgculv.for:3556 */
/*<        >*/
	    sfwsp_(stdout, &xs, &xe, &ys, &ufgated_1.feq_gen_eps_d_d_, e_, rhse_, feq_gen_find_ycynym_d_, &feq_gen_c_d_2000, &ns, &ne, 
		    ufgated_1.xvec, ufgated_1.yvec, ufgated_1.ycvec, 
		    ufgated_1.ynvec, eflag);
/* SOURCE ufgculv.for:3561 */
/*<       y2hat=yvec(ns) >*/
	    y2hat = ufgated_1.yvec[ns - 1];
/* SOURCE ufgculv.for:3562 */
/*<       else >*/
	} else {
/* SOURCE ufgculv.for:3563 */
/*<       y2hat=y2 >*/
	    y2hat = ufcom_1.y2;
/* SOURCE ufgculv.for:3564 */
/*<       endif >*/
	}
/*       Current assumption is that FC only occurs on mild or horizontal */
/*       conduit slopes.  Adverse slopes not supported.  We make also */
/*       try for steep slopes to define CD_CULV. */
/*        WRITE(STDOUT,*) ' Seeking FC limit: YCRIT=',SNGL(YCRIT) */
/*        WRITE(STDOUT,*) ' YNORM=',SNGL(YNORM) */
/* SOURCE ufgculv.for:3572 */
/*<        >*/
	feq_gen_d_d_1 = (doublereal) z1fwul;
	feq_gen_find_fw_cc_so_d_(stdout, &ufgated_1.feq_gen_epsarg_d_d_, &ufgated_1.feq_gen_epsf_d_d_, &
		ufgated_1.feq_gen_epsabs_d_d_, &ufcom_1.apptab, &ufgated_1.feq_gen_grav_d_d_, &
		feq_gen_d_d_1, &ufgated_1.feq_gen_z1b_d_d_, &feq_gen_station_1_d_, &ufgated_1.feq_gen_hg_d_d_, &
		ufgated_1.feq_gen_bg_d_d_, &y2hat, &feq_gen_cd_culv_d_, &feq_gen_fw_cc_so_d_, &soflag, &
		rflag);
/* SOURCE ufgculv.for:3577 */
/*<       if(rflag.ne.0)then >*/
	if (rflag != 0) {
/*          WRITE(STDOUT,*) ' Problem finding FW_CC_SO' */
/* SOURCE ufgculv.for:3580 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:3581 */
/*<       if(fw_cc_so.eq.0.0)then >*/
	if (feq_gen_fw_cc_so_d_ == (float)0.) {
/* SOURCE ufgculv.for:3582 */
/*<       write(stdout,59) >*/
	    feq_gen_io_d__492.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__492);
	    e_wsfe();
/* SOURCE ufgculv.for:3583 */
/*<       else >*/
	} else {
/* SOURCE ufgculv.for:3584 */
/*<       write(stdout,61)fw_cc_so >*/
	    feq_gen_io_d__493.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__493);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_fw_cc_so_d_, (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* SOURCE ufgculv.for:3585 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:3587 */
/*<       write(stdout,63)cd_culv >*/
	feq_gen_io_d__494.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__494);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_cd_culv_d_, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* SOURCE ufgculv.for:3588 */
/*<       cd_d=cd_culv >*/
	ufgated_1.feq_gen_cd_d_d_ = feq_gen_cd_culv_d_;
/* SOURCE ufgculv.for:3590 */
/*<       if(ynorm.gt.ycrit.or.ynorm.lt.0.d0)then >*/
	if (ynorm > ycrit || ynorm < 0.) {
/*         Seek the lower limit of FO flow assuming the standard */
/*         contraction coefficient */
/* SOURCE ufgculv.for:3594 */
/*<       h1foll_d=h1fwul_d >*/
	    feq_gen_h1foll_d_d_ = feq_gen_h1fwul_d_d_;
/* SOURCE ufgculv.for:3595 */
/*<       callfind_foll(stdout,cd_culv,dble(maxhu),h1foll_d,rflag) >*/
	    feq_gen_d_d_1 = (doublereal) maxhu;
	    feq_gen_find_foll_d_(stdout, &feq_gen_cd_culv_d_, &feq_gen_d_d_1, &feq_gen_h1foll_d_d_, &rflag);
/* SOURCE ufgculv.for:3599 */
/*<       else >*/
	} else {
/*         Barrel slope is steep.  FO assumed to start immediately */
/* SOURCE ufgculv.for:3601 */
/*<       h1foll_d=0.d0 >*/
	    feq_gen_h1foll_d_d_ = 0.;
/* SOURCE ufgculv.for:3603 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:3607 */
/*<       h1foll=sngl(h1foll_d) >*/
	h1foll = (real) feq_gen_h1foll_d_d_;
/* SOURCE ufgculv.for:3608 */
/*<       if(h1foll_d.eq.0.d0)then >*/
	if (feq_gen_h1foll_d_d_ == 0.) {
/*         Do transition over a user-given fraction of the gate */
/*         opening */
/* SOURCE ufgculv.for:3611 */
/*<       h1foll_d=h1fwul_d+fwfotr*hg_d >*/
	    feq_gen_h1foll_d_d_ = feq_gen_h1fwul_d_d_ + fwfotr * ufgated_1.feq_gen_hg_d_d_;
/* SOURCE ufgculv.for:3612 */
/*<       h1foll=h1foll_d >*/
	    h1foll = feq_gen_h1foll_d_d_;
/*         We cannot compute flows between H1FWUL and H1FOLL */
/* SOURCE ufgculv.for:3614 */
/*<       fcflag=0 >*/
	    fcflag = 0;
/* SOURCE ufgculv.for:3615 */
/*<       else >*/
	} else {
/* SOURCE ufgculv.for:3616 */
/*<       fcflag=1 >*/
	    fcflag = 1;
/* SOURCE ufgculv.for:3617 */
/*<       endif >*/
	}
/*       Assign the upstream heads for this gate opening.  The */
/*       ranges are: MINHU to HG, HG to H1FWUL, H1FWUL to H1FOLL, */
/*       and H1FOLL to MAXHU. */
/* SOURCE ufgculv.for:3622 */
/*<       power=1.5 >*/
	power = (float)1.5;
/* SOURCE ufgculv.for:3623 */
/*<       offset=0.0 >*/
	offset = (float)0.;
/* SOURCE ufgculv.for:3624 */
/*<       if(minhu.ge.hg)then >*/
	if (minhu >= ufcom_1.hg) {
/* SOURCE ufgculv.for:3625 */
/*<       minhu=0.5*hg >*/
	    minhu = static_cast<double>(ufcom_1.hg) * (float).5;
/* SOURCE ufgculv.for:3626 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:3627 */
/*<       humin=minhu >*/
	humin = minhu;
/* SOURCE ufgculv.for:3628 */
/*<        >*/
	lstopf_(stdout, &tablt, &tabgt, &power, &offset, &humin, &ufcom_1.hg, 
		&prec, &feq_gen_c_d_151, &n, xbrk, eflag);
/* SOURCE ufgculv.for:3632 */
/*<       do210i=1,n >*/
	feq_gen_i_d_3 = n;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_3; ++feq_gen_i_d_) {
/* SOURCE ufgculv.for:3633 */
/*<       huvec(i)=xbrk(i) >*/
	    huvec[feq_gen_i_d_ - 1] = xbrk[feq_gen_i_d_ - 1];
/* SOURCE ufgculv.for:3634 */
/*<   210 continue >*/
/* L210: */
	}
/* SOURCE ufgculv.for:3635 */
/*<       nhu=n >*/
	nhu = n;
/* SOURCE ufgculv.for:3637 */
/*<        >*/
	lstopf_(stdout, &tablt, &tabgt, &power, &offset, &ufcom_1.hg, &h1fwul,
		 &prec, &feq_gen_c_d_151, &n, xbrk, eflag);
/* SOURCE ufgculv.for:3641 */
/*<       if(n.eq.2)then >*/
	if (n == 2) {
/* SOURCE ufgculv.for:3642 */
/*<       xbrk(3)=xbrk(2) >*/
	    xbrk[2] = xbrk[1];
/* SOURCE ufgculv.for:3643 */
/*<       xbrk(2)=0.5*(xbrk(1)+xbrk(3)) >*/
	    xbrk[1] = static_cast<double>((static_cast<double>(xbrk[0]) + xbrk[2])) * (float).5;
/* SOURCE ufgculv.for:3644 */
/*<       n=3 >*/
	    n = 3;
/* SOURCE ufgculv.for:3645 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:3646 */
/*<       do212i=2,n >*/
	feq_gen_i_d_3 = n;
	for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_3; ++feq_gen_i_d_) {
/* SOURCE ufgculv.for:3647 */
/*<       nhu=nhu+1 >*/
	    ++nhu;
/* SOURCE ufgculv.for:3648 */
/*<       huvec(nhu)=xbrk(i) >*/
	    huvec[nhu - 1] = xbrk[feq_gen_i_d_ - 1];
/* SOURCE ufgculv.for:3649 */
/*<   212 continue >*/
/* L212: */
	}
/* SOURCE ufgculv.for:3650 */
/*<       offset=-cc*hg >*/
	offset = static_cast<double>(-ufcom_1.cc) * ufcom_1.hg;
/*       Flow varies as the .5 power of the head - offset.  However, */
/*       the drop to free flow varies more nearly like the 1.5 power. */
/*       The spacing for the 1.5 power is smaller than for .5 power; */
/*       so we use 1.5 power. */
/* SOURCE ufgculv.for:3655 */
/*<       power=1.5 >*/
	power = (float)1.5;
/* SOURCE ufgculv.for:3656 */
/*<       if(fcflag.eq.1)then >*/
	if (fcflag == 1) {
/* SOURCE ufgculv.for:3657 */
/*<        >*/
	    lstopf_(stdout, &tablt, &tabgt, &power, &offset, &h1fwul, &h1foll,
		     &prec, &feq_gen_c_d_151, &n, xbrk, eflag);
/* SOURCE ufgculv.for:3661 */
/*<       if(n.eq.2)then >*/
	    if (n == 2) {
/* SOURCE ufgculv.for:3662 */
/*<       xbrk(3)=xbrk(2) >*/
		xbrk[2] = xbrk[1];
/* SOURCE ufgculv.for:3663 */
/*<       xbrk(2)=0.5*(xbrk(1)+xbrk(3)) >*/
		xbrk[1] = static_cast<double>((static_cast<double>(xbrk[0]) + xbrk[2])) * (float).5;
/* SOURCE ufgculv.for:3664 */
/*<       n=3 >*/
		n = 3;
/* SOURCE ufgculv.for:3665 */
/*<       endif >*/
	    }
/* SOURCE ufgculv.for:3666 */
/*<       else >*/
	} else {
/*         Can only compute at the end points here. */
/* SOURCE ufgculv.for:3668 */
/*<       n=2 >*/
	    n = 2;
/* SOURCE ufgculv.for:3669 */
/*<       xbrk(1)=h1fwul >*/
	    xbrk[0] = h1fwul;
/* SOURCE ufgculv.for:3670 */
/*<       xbrk(2)=h1foll >*/
	    xbrk[1] = h1foll;
/* SOURCE ufgculv.for:3671 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:3672 */
/*<       do213i=2,n >*/
	feq_gen_i_d_3 = n;
	for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_3; ++feq_gen_i_d_) {
/* SOURCE ufgculv.for:3673 */
/*<       nhu=nhu+1 >*/
	    ++nhu;
/* SOURCE ufgculv.for:3674 */
/*<       huvec(nhu)=xbrk(i) >*/
	    huvec[nhu - 1] = xbrk[feq_gen_i_d_ - 1];
/* SOURCE ufgculv.for:3675 */
/*<   213 continue >*/
/* L213: */
	}
/* SOURCE ufgculv.for:3676 */
/*<       if(oldhg.gt.0.0)then >*/
	if (oldhg > (float)0.) {
/* SOURCE ufgculv.for:3677 */
/*<       humax=maxhu*hg/oldhg >*/
	    humax = static_cast<double>(static_cast<double>(maxhu) * ufcom_1.hg) / oldhg;
/* SOURCE ufgculv.for:3678 */
/*<       else >*/
	} else {
/* SOURCE ufgculv.for:3679 */
/*<       humax=maxhu >*/
	    humax = maxhu;
/* SOURCE ufgculv.for:3680 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:3681 */
/*<       if(humax.le.h1foll)then >*/
	if (humax <= h1foll) {
/*         The maximum requested head is less than the head at section */
/*         1 at the lower limit of FO flow. */
/* SOURCE ufgculv.for:3684 */
/*<       humax=h1foll*1.10 >*/
	    humax = static_cast<double>(h1foll) * (float)1.1;
/* SOURCE ufgculv.for:3685 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:3686 */
/*<       oldhg=hg >*/
	oldhg = ufcom_1.hg;
/* SOURCE ufgculv.for:3687 */
/*<        >*/
	lstopf_(stdout, &tablt, &tabgt, &power, &offset, &h1foll, &humax, &
		prec, &feq_gen_c_d_151, &n, xbrk, eflag);
/* SOURCE ufgculv.for:3691 */
/*<       do214i=2,n >*/
	feq_gen_i_d_3 = n;
	for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_3; ++feq_gen_i_d_) {
/* SOURCE ufgculv.for:3692 */
/*<       nhu=nhu+1 >*/
	    ++nhu;
/* SOURCE ufgculv.for:3693 */
/*<       huvec(nhu)=xbrk(i) >*/
	    huvec[nhu - 1] = xbrk[feq_gen_i_d_ - 1];
/* SOURCE ufgculv.for:3694 */
/*<   214 continue >*/
/* L214: */
	}
/*       Now compute the free flow for each of the upstream heads */
/* SOURCE ufgculv.for:3698 */
/*<       do900ihu=1,nhu >*/
	feq_gen_i_d_3 = nhu;
	for (ihu = 1; ihu <= feq_gen_i_d_3; ++ihu) {
/* SOURCE ufgculv.for:3699 */
/*<       z1=huvec(ihu)+hdatum >*/
	    z1 = static_cast<double>(huvec[ihu - 1]) + hdatum;
/* SOURCE ufgculv.for:3700 */
/*<       h1=z1-z2b >*/
	    h1 = static_cast<double>(z1) - ufcom_1.z2b;
/* SOURCE ufgculv.for:3701 */
/*<       h1_d=dble(h1) >*/
	    ufgated_1.feq_gen_h1_d_d_ = (doublereal) h1;
/* SOURCE ufgculv.for:3702 */
/*<       y1=h1+z2b-z1b >*/
	    ufcom_1.y1 = static_cast<double>(static_cast<double>(h1) + ufcom_1.z2b) - ufcom_1.z1b;
/* SOURCE ufgculv.for:3703 */
/*<       rg=hg/h1 >*/
	    rg = static_cast<double>(ufcom_1.hg) / h1;
/* SOURCE ufgculv.for:3704 */
/*<       if(rg.gt.1.0)rg=1.0 >*/
	    if (rg > (float)1.) {
		rg = (float)1.;
	    }
/* SOURCE ufgculv.for:3705 */
/*<       cc=findcc(rg,concc,cctab) >*/
	    ufcom_1.cc = findcc_(&rg, &concc, &cctab);
/* SOURCE ufgculv.for:3707 */
/*<       write(stdout,72)huvec(ihu),h1+z2b,y1,hg >*/
	    feq_gen_io_d__506.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__506);
	    do_fio(&feq_gen_c_d_1, (char *)&huvec[ihu - 1], (ftnlen)sizeof(real));
	    feq_gen_r_d_1 = static_cast<double>(h1) + ufcom_1.z2b;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.y1, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.hg, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE ufgculv.for:3708 */
/*<       write(stdout,74) >*/
	    feq_gen_io_d__507.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__507);
	    e_wsfe();
/*         Set the flow for zero partial free drop to 0.0 */
/* SOURCE ufgculv.for:3710 */
/*<       qmat(ihu,1)=0.0 >*/
	    qmat[ihu - 1] = (float)0.;
/*         Find conditions at section 1 */
/* SOURCE ufgculv.for:3712 */
/*<        >*/
	    xlkt22_(&ufcom_1.apptab, &ufcom_1.y1, &ufcom_1.a1, &ufcom_1.tt, &
		    dt, &ufcom_1.jt, &ufcom_1.kt, &ufcom_1.dkt, &ufcom_1.beta,
		     &ufcom_1.dbeta, &ufcom_1.alpha1, &ufcom_1.dalpha, &
		    ufcom_1.qct);
/* SOURCE ufgculv.for:3717 */
/*<       a1_d=dble(a1) >*/
	    ufgated_1.feq_gen_a1_d_d_ = (doublereal) ufcom_1.a1;
/* SOURCE ufgculv.for:3718 */
/*<       alpha1_d=dble(alpha1) >*/
	    ufgated_1.feq_gen_alpha1_d_d_ = (doublereal) ufcom_1.alpha1;
/* SOURCE ufgculv.for:3720 */
/*<       if(h1.le.h1fwul)then >*/
	    if (h1 <= h1fwul) {
/*           Flow is free weir flow. */
/* SOURCE ufgculv.for:3722 */
/*<       ftype='FW' >*/
		s_copy(ftype, const_cast<char*>("FW"), (ftnlen)2, (ftnlen)2);
/* SOURCE ufgculv.for:3724 */
/*<        >*/
		tdlk13_(stdout, &getq, &feq_gen_c_d_13, &feq_gen_c_d_0, &c_b72, &c_b72, &z1, &
			feq_gen_hdatum_for_h1vsy2_d_, &qfree, &dqed, &dqeu, &free);
/* SOURCE ufgculv.for:3728 */
/*<        >*/
		tdlk13_(stdout, &gety2, &feq_gen_c_d_13, &feq_gen_c_d_0, &c_b72, &c_b72, &z1, &
			feq_gen_hdatum_for_h1vsy2_d_, &y2fw, &dqed, &dqeu, &free);
/*            WRITE(STDOUT,*) ' H1=',H1,' FW Q=', QFREE,' Y2FW=',Y2FW */
/*           Now find the level at section 4 that defines */
/*           the limit of free weir flow, Y4F. Define the constant */
/*           values. */
/* SOURCE ufgculv.for:3739 */
/*<       calltd13_fdrop(stdout,gety2,13,h1,hdatum_for_h1vsy2,fdrop) >*/
		feq_gen_td13_fdrop_d_(stdout, &gety2, &feq_gen_c_d_13, &h1, &
			feq_gen_hdatum_for_h1vsy2_d_, &fdrop);
/*           Submerged weir flow can transition to submerged orifice */
/*           flow if the water level at section 1 is above the */
/*           elevation of the gate lip. */
/* SOURCE ufgculv.for:3747 */
/*<       if((h1-hg)/hg.gt.5.e-5)then >*/
		if (static_cast<double>((static_cast<double>(h1) - ufcom_1.hg)) / ufcom_1.hg > (float)5e-5) {
/*            IF(Y1 + Z1B.GT.HG+Z2B) THEN */
/*              WRITE(STDOUT,*) ' H1=',H1,' H1FWUL=',H1FWUL */
/* SOURCE ufgculv.for:3750 */
/*<       if((h1-h1fwul)/h1fwul.le.-epsf)then >*/
		    if (static_cast<double>((static_cast<double>(h1) - h1fwul)) / h1fwul <= -epscom_1.epsf) {
/*               Find the tailwater level that causes the water to */
/*               contact the lip. */
/* SOURCE ufgculv.for:3753 */
/*<       callfind_y4sw(stdout,z1,z2b,z4b,gety2,hg_d,epsarg_d,epsf_d,y4sw_d) >*/
			feq_gen_find_y4sw_d_(stdout, &z1, &ufcom_1.z2b, &ufcom_1.z4b, &
				gety2, &ufgated_1.feq_gen_hg_d_d_, &
				ufgated_1.feq_gen_epsarg_d_d_, &ufgated_1.feq_gen_epsf_d_d_, &
				feq_gen_y4sw_d_d_);
/* SOURCE ufgculv.for:3757 */
/*<       y4sw=y4sw_d >*/
			y4sw = feq_gen_y4sw_d_d_;
/* SOURCE ufgculv.for:3758 */
/*<       else >*/
		    } else {
/*               Water is in contact already. */
/* SOURCE ufgculv.for:3760 */
/*<       y4sw=z1-fdrop-z4b >*/
			y4sw = static_cast<double>(static_cast<double>(z1) - fdrop) - ufcom_1.z4b;
/* SOURCE ufgculv.for:3761 */
/*<       endif >*/
		    }
/* SOURCE ufgculv.for:3762 */
/*<       else >*/
		} else {
/*             Set level to the zero flow level, that is, to the level */
/*             at section 1. */
/* SOURCE ufgculv.for:3765 */
/*<       y4sw=y1+z1b-z4b >*/
		    y4sw = static_cast<double>(static_cast<double>(ufcom_1.y1) + ufcom_1.z1b) - ufcom_1.z4b;
/* SOURCE ufgculv.for:3766 */
/*<       endif >*/
		}
/*            WRITE(STDOUT,*) ' Y4SW=',Y4SW,' FDROP=',FDROP */
/* SOURCE ufgculv.for:3770 */
/*<       h4f=z1-fdrop-hdatum >*/
		h4f = static_cast<double>(static_cast<double>(z1) - fdrop) - hdatum;
/* SOURCE ufgculv.for:3771 */
/*<       y4f=h4f+hdatum-z4b >*/
		y4f = static_cast<double>(static_cast<double>(h4f) + hdatum) - ufcom_1.z4b;
/* SOURCE ufgculv.for:3772 */
/*<        >*/
		xlkt22_(&ufcom_1.deptab, &y4f, &ufcom_1.a4, &ufcom_1.tt, &dt, 
			&ufcom_1.jt, &ufcom_1.kt, &ufcom_1.dkt, &ufcom_1.beta,
			 &ufcom_1.dbeta, &ufcom_1.alpha4, &ufcom_1.dalpha, &
			ufcom_1.qct);
/* SOURCE ufgculv.for:3778 */
/*<        >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = static_cast<double>(qfree) / ufcom_1.a1;
/* Computing 2nd power */
		feq_gen_r_d_2 = static_cast<double>(qfree) / ufcom_1.a4;
		de1to4 = static_cast<double>(static_cast<double>(h1) + static_cast<double>(static_cast<double>(ufcom_1.alpha1) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / ufcom_1.twog) - 
			(static_cast<double>(h4f) + static_cast<double>(static_cast<double>(ufcom_1.alpha4) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) / ufcom_1.twog);
/* SOURCE ufgculv.for:3780 */
/*<       if(de1to4.lt.0.0)elflag=1 >*/
		if (de1to4 < (float)0.) {
		    elflag = 1;
		}
/* SOURCE ufgculv.for:3782 */
/*<       char8='   ---  ' >*/
		s_copy(char8, const_cast<char*>("   ---  "), (ftnlen)8, (ftnlen)8);
/* SOURCE ufgculv.for:3783 */
/*<       qmat(ihu,nfrac)=qfree >*/
		qmat[ihu + nfrac * 151 - 152] = qfree;
/* SOURCE ufgculv.for:3784 */
/*<       fdvec(ihu)=fdrop >*/
		fdvec[ihu - 1] = fdrop;
/* SOURCE ufgculv.for:3785 */
/*<       char6='  --- ' >*/
		s_copy(char6, const_cast<char*>("  --- "), (ftnlen)6, (ftnlen)6);
/* SOURCE ufgculv.for:3786 */
/*<       cq(1:10)=put10(qfree) >*/
		put10_(feq_gen_ch_d_5, (ftnlen)10, &qfree);
		s_copy(cq, feq_gen_ch_d_5, (ftnlen)10, (ftnlen)10);
/* SOURCE ufgculv.for:3787 */
/*<       cq(11:11)=' ' >*/
		*(unsigned char *)&cq[10] = ' ';
/* SOURCE ufgculv.for:3788 */
/*<       write(stdout,78)1.00,fdrop,char8,h4f,ftype,char6,cq,de1to4 >*/
		feq_gen_io_d__521.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__521);
		do_fio(&feq_gen_c_d_1, (char *)&c_b477, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&fdrop, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, char8, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, (char *)&h4f, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, ftype, (ftnlen)2);
		do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
		do_fio(&feq_gen_c_d_1, cq, (ftnlen)11);
		do_fio(&feq_gen_c_d_1, (char *)&de1to4, (ftnlen)sizeof(real));
		e_wsfe();
/*            OLDH3 = Y3 + Z3B - HDATUM */
/*           Compute the submerged flows.  They may be of two types: */
/*           SO or SW. */
/* SOURCE ufgculv.for:3794 */
/*<       yvcold=cc*hg >*/
		yvcold = static_cast<double>(ufcom_1.cc) * ufcom_1.hg;
/* SOURCE ufgculv.for:3795 */
/*<       do400j=nfrac-1,2,-1 >*/
		for (j = nfrac - 1; j >= 2; --j) {
/* SOURCE ufgculv.for:3796 */
/*<       drop=fdrop*pfdvec(j) >*/
		    drop = static_cast<double>(fdrop) * pfdvec[j - 1];
/* SOURCE ufgculv.for:3797 */
/*<       zw4=z1b+y1-drop >*/
		    zw4 = static_cast<double>(static_cast<double>(ufcom_1.z1b) + ufcom_1.y1) - drop;
/* SOURCE ufgculv.for:3798 */
/*<       y4=zw4-z4b >*/
		    ufcom_1.y4 = static_cast<double>(zw4) - ufcom_1.z4b;
/* SOURCE ufgculv.for:3799 */
/*<       h4=zw4-hdatum >*/
		    h4 = static_cast<double>(zw4) - hdatum;
/* SOURCE ufgculv.for:3800 */
/*<        >*/
		    xlkt22_(&ufcom_1.deptab, &ufcom_1.y4, &ufcom_1.a4, &
			    ufcom_1.tt, &dt, &ufcom_1.j4, &ufcom_1.kt, &
			    ufcom_1.dkt, &ufcom_1.beta4, &ufcom_1.dbeta, &
			    ufcom_1.alpha4, &ufcom_1.dalpha, &ufcom_1.qct);
/* SOURCE ufgculv.for:3805 */
/*<       if((y4-y4sw)/y4sw.le.1.e-5)then >*/
		    if (static_cast<double>((static_cast<double>(ufcom_1.y4) - y4sw)) / y4sw <= (float)1e-5) {
/*               Flow can only be submerged weir flow.  Look it up */
/*               in the table transfered from CULVERT. */
/* SOURCE ufgculv.for:3809 */
/*<       ftype='SW' >*/
			s_copy(ftype, const_cast<char*>("SW"), (ftnlen)2, (ftnlen)2);
/* SOURCE ufgculv.for:3810 */
/*<       char6='  --- ' >*/
			s_copy(char6, const_cast<char*>("  --- "), (ftnlen)6, (ftnlen)6);
/* SOURCE ufgculv.for:3811 */
/*<       char8='   ---  ' >*/
			s_copy(char8, const_cast<char*>("   ---  "), (ftnlen)8, (ftnlen)8);
/* SOURCE ufgculv.for:3812 */
/*<       calltdlk13(stdout,getq,13,0,0.0,zw4,z1,hdatum,q,dqed,dqeu,free) >*/
			tdlk13_(stdout, &getq, &feq_gen_c_d_13, &feq_gen_c_d_0, &c_b72, &zw4, &
				z1, &hdatum, &q, &dqed, &dqeu, &free);
/* SOURCE ufgculv.for:3816 */
/*<       rflag=0 >*/
			rflag = 0;
/* SOURCE ufgculv.for:3817 */
/*<       else >*/
		    } else {
/*               The flow is SO (we think).  We might have problems */
/*               because the CULVERT routines thinks it is but the */
/*               computations here may not.  In this case the tailwater */
/*               is at section 4 */

/* SOURCE ufgculv.for:3823 */
/*<       ftype='SO' >*/
			s_copy(ftype, const_cast<char*>("SO"), (ftnlen)2, (ftnlen)2);
/* SOURCE ufgculv.for:3824 */
/*<       write(char6,'(F6.3)')cc >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 6;
			feq_gen_ici_d_1.iciunit = char6;
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(F6.3)");
			s_wsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.cc, (ftnlen)sizeof(
				real));
			e_wsfi();
/* SOURCE ufgculv.for:3826 */
/*<        >*/
			feq_gen_r_d_1 = (real) feq_gen_cd_culv_d_;
			feq_gen_r_d_2 = (real) ufgc1_1.feq_gen_sin_theta_d_;
			feq_gen_r_d_3 = (real) ufgc1_1.feq_gen_cos_theta_d_;
			feq_gen_r_d_4 = (real) ufgc1_1.feq_gen_invert_z_d_[ufgc1_1.nxs - 1];
			feq_gen_find_so_flow_d_(stdout, &ufcom_1.deptab, &
				ufgc1_1.feq_gen_xsec_adrs_d_[ufgc1_1.nxs - 1], grav, &
				h1, &ufcom_1.hg, &ufcom_1.bg, &ufcom_1.cc, &
				feq_gen_r_d_1, &feq_gen_r_d_2, &feq_gen_r_d_3, &feq_gen_r_d_4, &ufcom_1.z4b, &
				ufcom_1.y4, &ufcom_1.a4, &ufcom_1.beta4, &
				ufcom_1.j4, &ufcom_1.alpha1, &ufcom_1.a1, &
				ufgc1_1.nxs, ufgc1_1.station, &
				ufgated_1.feq_gen_eps_d_d_, &yvcold, &q, &ufcom_1.y3, &
				feq_gen_xe_r_d_, &rflag);
/* SOURCE ufgculv.for:3835 */
/*<       if(rflag.eq.-11)then >*/
			if (rflag == -11) {
/* SOURCE ufgculv.for:3836 */
/*<       write(stdout,*)' SO FLOW is not SO!: XE_R=',xe_r >*/
			    feq_gen_io_d__527.ciunit = *stdout;
			    s_wsle(&feq_gen_io_d__527);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" SO FLOW is not SO!: XE_R="),
				     (ftnlen)26);
			    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&feq_gen_xe_r_d_, (ftnlen)
				    sizeof(real));
			    e_wsle();
/* SOURCE ufgculv.for:3837 */
/*<       q=qfree >*/
			    q = qfree;
/* SOURCE ufgculv.for:3838 */
/*<       yvcold=hg*cc >*/
			    yvcold = static_cast<double>(ufcom_1.hg) * ufcom_1.cc;
/* SOURCE ufgculv.for:3839 */
/*<       elseif(rflag.eq.-10)then >*/
			} else if (rflag == -10) {
/* SOURCE ufgculv.for:3840 */
/*<       write(stdout,*)' SO FLOW is not SO!' >*/
			    feq_gen_io_d__528.ciunit = *stdout;
			    s_wsle(&feq_gen_io_d__528);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" SO FLOW is not SO!"), (
				    ftnlen)19);
			    e_wsle();
/* SOURCE ufgculv.for:3841 */
/*<       q=qfree >*/
			    q = qfree;
/* SOURCE ufgculv.for:3842 */
/*<       yvcold=hg*cc >*/
			    yvcold = static_cast<double>(ufcom_1.hg) * ufcom_1.cc;
/* SOURCE ufgculv.for:3843 */
/*<       endif >*/
			}
/* SOURCE ufgculv.for:3844 */
/*<       h3=y3+z3b-hdatum >*/
			h3 = static_cast<double>(static_cast<double>(ufcom_1.y3) + ufcom_1.z3b) - hdatum;
/* SOURCE ufgculv.for:3845 */
/*<       write(char8,'(F8.3)')h3 >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 8;
			feq_gen_ici_d_1.iciunit = char8;
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.3)");
			s_wsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&h3, (ftnlen)sizeof(real));
			e_wsfi();
/* SOURCE ufgculv.for:3847 */
/*<       endif >*/
		    }
/* SOURCE ufgculv.for:3848 */
/*<       qmat(ihu,j)=q >*/
		    qmat[ihu + j * 151 - 152] = q;
/*             Prevent problems wiht local power, P, if one */
/*             of the flows should be zero. */
/* SOURCE ufgculv.for:3852 */
/*<       if(q.le.0.0)then >*/
		    if (q <= (float)0.) {
/* SOURCE ufgculv.for:3853 */
/*<       qtt=0.1*qmat(ihu,j+1) >*/
			qtt = static_cast<double>(qmat[ihu + (j + 1) * 151 - 152]) * (float).1;
/* SOURCE ufgculv.for:3854 */
/*<       else >*/
		    } else {
/* SOURCE ufgculv.for:3855 */
/*<       qtt=q >*/
			qtt = q;
/* SOURCE ufgculv.for:3856 */
/*<       endif >*/
		    }
/* SOURCE ufgculv.for:3857 */
/*<       p=log(qtt/qmat(ihu,j+1))/log(pfdvec(j)/pfdvec(j+1)) >*/
		    p = log(static_cast<double>(qtt) / qmat[ihu + (j + 1) * 151 - 152]) / log(
			    static_cast<double>(pfdvec[j - 1]) / pfdvec[j]);
/* SOURCE ufgculv.for:3858 */
/*<       de1to4=h1+alpha1*(q/a1)**2/twog-(h4+alpha4*(q/a4)**2/twog) >*/
/* Computing 2nd power */
		    feq_gen_r_d_1 = static_cast<double>(q) / ufcom_1.a1;
/* Computing 2nd power */
		    feq_gen_r_d_2 = static_cast<double>(q) / ufcom_1.a4;
		    de1to4 = static_cast<double>(static_cast<double>(h1) + static_cast<double>(static_cast<double>(ufcom_1.alpha1) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / 
			    ufcom_1.twog) - (static_cast<double>(h4) + static_cast<double>(static_cast<double>(ufcom_1.alpha4) * (static_cast<double>(feq_gen_r_d_2) * 
			    feq_gen_r_d_2)) / ufcom_1.twog);
/* SOURCE ufgculv.for:3860 */
/*<       if(de1to4.lt.0.0)elflag=1 >*/
		    if (de1to4 < (float)0.) {
			elflag = 1;
		    }
/* SOURCE ufgculv.for:3862 */
/*<       cq(1:10)=put10(q) >*/
		    put10_(feq_gen_ch_d_5, (ftnlen)10, &q);
		    s_copy(cq, feq_gen_ch_d_5, (ftnlen)10, (ftnlen)10);
/* SOURCE ufgculv.for:3863 */
/*<       if(rflag.eq.-12)then >*/
		    if (rflag == -12) {
/* SOURCE ufgculv.for:3864 */
/*<       cq(11:11)='*' >*/
			*(unsigned char *)&cq[10] = '*';
/* SOURCE ufgculv.for:3865 */
/*<       else >*/
		    } else {
/* SOURCE ufgculv.for:3866 */
/*<       cq(11:11)=' ' >*/
			*(unsigned char *)&cq[10] = ' ';
/* SOURCE ufgculv.for:3867 */
/*<       endif >*/
		    }
/* SOURCE ufgculv.for:3868 */
/*<       write(stdout,75)pfdvec(j),drop,char8,h4,ftype,char6,cq,p,de1to4 >*/
		    feq_gen_io_d__532.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__532);
		    do_fio(&feq_gen_c_d_1, (char *)&pfdvec[j - 1], (ftnlen)sizeof(real)
			    );
		    do_fio(&feq_gen_c_d_1, (char *)&drop, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, char8, (ftnlen)8);
		    do_fio(&feq_gen_c_d_1, (char *)&h4, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, ftype, (ftnlen)2);
		    do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
		    do_fio(&feq_gen_c_d_1, cq, (ftnlen)11);
		    do_fio(&feq_gen_c_d_1, (char *)&p, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&de1to4, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE ufgculv.for:3870 */
/*<   400 continue >*/
/* L400: */
		}
/* SOURCE ufgculv.for:3871 */
/*<       elseif(h1.lt.h1foll.and.fcflag.eq.1)then >*/
	    } else if (h1 < h1foll && fcflag == 1) {
/* SOURCE ufgculv.for:3872 */
/*<       if(fcflag.eq.1)then >*/
		if (fcflag == 1) {
/*             FC flow */
/* SOURCE ufgculv.for:3874 */
/*<       ftype='FC' >*/
		    s_copy(ftype, const_cast<char*>("FC"), (ftnlen)2, (ftnlen)2);
/*             Define the contraction coefficient to use. */
/*             If FW_CC_SO > 0 then use linear interpolation */
/*             between it and CC over  H1FWUL TO H1FOLL */
/* SOURCE ufgculv.for:3881 */
/*<       if(fw_cc_so.gt.0)then >*/
		    if (feq_gen_fw_cc_so_d_ > 0.) {
/* SOURCE ufgculv.for:3882 */
/*<        >*/
			ufgated_1.feq_gen_cc_d_d_ = feq_gen_fw_cc_so_d_ + (ufgated_1.feq_gen_h1_d_d_ - 
				feq_gen_h1fwul_d_d_) * ((doublereal) ufcom_1.cc - 
				feq_gen_fw_cc_so_d_) / (feq_gen_h1foll_d_d_ - feq_gen_h1fwul_d_d_);
/* SOURCE ufgculv.for:3884 */
/*<       else >*/
		    } else {
/* SOURCE ufgculv.for:3885 */
/*<       cc_d=dble(cc) >*/
			ufgated_1.feq_gen_cc_d_d_ = (doublereal) ufcom_1.cc;
/* SOURCE ufgculv.for:3886 */
/*<       endif >*/
		    }
/* SOURCE ufgculv.for:3888 */
/*<       callfind_fcq(stdout,cd_culv,h1_d,qd,yvc,rflag) >*/
		    feq_gen_find_fcq_d_(stdout, &feq_gen_cd_culv_d_, &ufgated_1.feq_gen_h1_d_d_, &
			    ufgc1_1.qd, &yvc, &rflag);
/* SOURCE ufgculv.for:3892 */
/*<       qfree=qd >*/
		    qfree = ufgc1_1.qd;
/*             Compute the tailwater for the current flow.  The */
/*             exit contion can be either of 3 cases: FULL=0, */
/*             FULL=1, or FULL=2.  When FULL=1 we have a weighted */
/*             average of full-barrel flow and part-full-barrel flow. */
/* SOURCE ufgculv.for:3898 */
/*<       if(full_return.eq.0)then >*/
		    if (ufgated_1.feq_gen_full_return_d_ == 0) {
/*               We have critical depth at the exit and a free */
/*               surface. */
/* SOURCE ufgculv.for:3901 */
/*<       y3=yc_return >*/
			ufcom_1.y3 = ufgated_1.feq_gen_yc_return_d_;
/* SOURCE ufgculv.for:3902 */
/*<       calllkta(xsec_adrs(nxs),y3,aflux) >*/
			lkta_(&ufgc1_1.feq_gen_xsec_adrs_d_[ufgc1_1.nxs - 1], &
				ufcom_1.y3, &aflux);
/* SOURCE ufgculv.for:3906 */
/*<       else >*/
		    } else {
/*               We have  a full pipe with piezometric surface less */
/*               than vertical diameter from invert.  Ignore the */
/*               the small region of averaging the free surface */
/*               and the full flow. */
/* SOURCE ufgculv.for:3911 */
/*<       y3=y_return >*/
			ufcom_1.y3 = ufgated_1.feq_gen_y_return_d_;
/* SOURCE ufgculv.for:3912 */
/*<       aflux=afull >*/
			aflux = afull;
/* SOURCE ufgculv.for:3913 */
/*<       endif >*/
		    }
/*             Next compute the water level at section 4 from the */
/*             water level at section 3. */
/* SOURCE ufgculv.for:3917 */
/*<        >*/
		    feq_gen_r_d_1 = (real) ufgc1_1.feq_gen_cos_theta_d_;
		    feq_gen_find_y4_from_y43_d_(stdout, grav, &qfree, &ufcom_1.deptab, 
			    &ufcom_1.z3b, &ufcom_1.z4b, &ufcom_1.y3, &aflux, &
			    feq_gen_r_d_1, &y4f, eflag);
/* SOURCE ufgculv.for:3922 */
/*<       zw4f=y4f+z4b >*/
		    zw4f = static_cast<double>(y4f) + ufcom_1.z4b;
/* SOURCE ufgculv.for:3923 */
/*<       h4f=zw4f-hdatum >*/
		    h4f = static_cast<double>(zw4f) - hdatum;
/* SOURCE ufgculv.for:3924 */
/*<        >*/
		    xlkt22_(&ufcom_1.deptab, &y4f, &ufcom_1.a4, &ufcom_1.tt, &
			    dt, &ufcom_1.j4, &ufcom_1.kt, &ufcom_1.dkt, &
			    ufcom_1.beta4, &ufcom_1.dbeta, &ufcom_1.alpha4, &
			    ufcom_1.dalpha, &ufcom_1.qct);
/* SOURCE ufgculv.for:3929 */
/*<        >*/
/* Computing 2nd power */
		    feq_gen_r_d_1 = static_cast<double>(qfree) / ufcom_1.a1;
/* Computing 2nd power */
		    feq_gen_r_d_2 = static_cast<double>(qfree) / ufcom_1.a4;
		    de1to4 = static_cast<double>(static_cast<double>(h1) + static_cast<double>(static_cast<double>(ufcom_1.alpha1) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / 
			    ufcom_1.twog) - (static_cast<double>(h4f) + static_cast<double>(static_cast<double>(ufcom_1.alpha4) * (static_cast<double>(feq_gen_r_d_2) * 
			    feq_gen_r_d_2)) / ufcom_1.twog);
/* SOURCE ufgculv.for:3931 */
/*<       if(de1to4.lt.0.0)elflag=1 >*/
		    if (de1to4 < (float)0.) {
			elflag = 1;
		    }
/* SOURCE ufgculv.for:3932 */
/*<       qmat(ihu,nfrac)=qfree >*/
		    qmat[ihu + nfrac * 151 - 152] = qfree;
/* SOURCE ufgculv.for:3933 */
/*<       fdrop=y1+z1b-zw4f >*/
		    fdrop = static_cast<double>(static_cast<double>(ufcom_1.y1) + ufcom_1.z1b) - zw4f;
/* SOURCE ufgculv.for:3934 */
/*<       fdvec(ihu)=fdrop >*/
		    fdvec[ihu - 1] = fdrop;
/* SOURCE ufgculv.for:3935 */
/*<       cq(1:10)=put10(qfree) >*/
		    put10_(feq_gen_ch_d_5, (ftnlen)10, &qfree);
		    s_copy(cq, feq_gen_ch_d_5, (ftnlen)10, (ftnlen)10);
/* SOURCE ufgculv.for:3936 */
/*<       cq(11:11)=' ' >*/
		    *(unsigned char *)&cq[10] = ' ';
/* SOURCE ufgculv.for:3937 */
/*<       write(char6,'(F6.3)')cc_d >*/
		    feq_gen_ici_d_1.icierr = 0;
		    feq_gen_ici_d_1.icirnum = 1;
		    feq_gen_ici_d_1.icirlen = 6;
		    feq_gen_ici_d_1.iciunit = char6;
		    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F6.3)");
		    s_wsfi(&feq_gen_ici_d_1);
		    do_fio(&feq_gen_c_d_1, (char *)&ufgated_1.feq_gen_cc_d_d_, (ftnlen)sizeof(
			    doublereal));
		    e_wsfi();
/* SOURCE ufgculv.for:3938 */
/*<       write(stdout,76)1.00,fdrop,y3+z3b-hdatum,h4f,ftype,char6,cq,de1to4 >*/
		    feq_gen_io_d__536.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__536);
		    do_fio(&feq_gen_c_d_1, (char *)&c_b477, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&fdrop, (ftnlen)sizeof(real));
		    feq_gen_r_d_1 = static_cast<double>(static_cast<double>(ufcom_1.y3) + ufcom_1.z3b) - hdatum;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&h4f, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, ftype, (ftnlen)2);
		    do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
		    do_fio(&feq_gen_c_d_1, cq, (ftnlen)11);
		    do_fio(&feq_gen_c_d_1, (char *)&de1to4, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE ufgculv.for:3940 */
/*<       ftype='SO' >*/
		    s_copy(ftype, const_cast<char*>("SO"), (ftnlen)2, (ftnlen)2);
/* SOURCE ufgculv.for:3941 */
/*<       yvcold=cc*hg >*/
		    yvcold = static_cast<double>(ufcom_1.cc) * ufcom_1.hg;
/* SOURCE ufgculv.for:3942 */
/*<       do450j=nfrac-1,2,-1 >*/
		    for (j = nfrac - 1; j >= 2; --j) {
/* SOURCE ufgculv.for:3943 */
/*<       drop=fdrop*pfdvec(j) >*/
			drop = static_cast<double>(fdrop) * pfdvec[j - 1];
/* SOURCE ufgculv.for:3944 */
/*<       zw4=z1b+y1-drop >*/
			zw4 = static_cast<double>(static_cast<double>(ufcom_1.z1b) + ufcom_1.y1) - drop;
/* SOURCE ufgculv.for:3945 */
/*<       y4=zw4-z4b >*/
			ufcom_1.y4 = static_cast<double>(zw4) - ufcom_1.z4b;
/* SOURCE ufgculv.for:3946 */
/*<        >*/
			xlkt22_(&ufcom_1.deptab, &ufcom_1.y4, &ufcom_1.a4, &
				ufcom_1.tt, &dt, &ufcom_1.j4, &ufcom_1.kt, &
				ufcom_1.dkt, &ufcom_1.beta4, &ufcom_1.dbeta, &
				ufcom_1.alpha4, &ufcom_1.dalpha, &ufcom_1.qct)
				;
/* SOURCE ufgculv.for:3951 */
/*<       h4=zw4-hdatum >*/
			h4 = static_cast<double>(zw4) - hdatum;
/* SOURCE ufgculv.for:3952 */
/*<        >*/
			feq_gen_r_d_1 = (real) feq_gen_cd_culv_d_;
			feq_gen_r_d_2 = (real) ufgc1_1.feq_gen_sin_theta_d_;
			feq_gen_r_d_3 = (real) ufgc1_1.feq_gen_cos_theta_d_;
			feq_gen_r_d_4 = (real) ufgc1_1.feq_gen_invert_z_d_[ufgc1_1.nxs - 1];
			feq_gen_find_so_flow_d_(stdout, &ufcom_1.deptab, &
				ufgc1_1.feq_gen_xsec_adrs_d_[ufgc1_1.nxs - 1], grav, &
				h1, &ufcom_1.hg, &ufcom_1.bg, &ufcom_1.cc, &
				feq_gen_r_d_1, &feq_gen_r_d_2, &feq_gen_r_d_3, &feq_gen_r_d_4, &ufcom_1.z4b, &
				ufcom_1.y4, &ufcom_1.a4, &ufcom_1.beta4, &
				ufcom_1.j4, &ufcom_1.alpha1, &ufcom_1.a1, &
				ufgc1_1.nxs, ufgc1_1.station, &
				ufgated_1.feq_gen_eps_d_d_, &yvcold, &q, &ufcom_1.y3, &
				feq_gen_xe_r_d_, &rflag);
/* SOURCE ufgculv.for:3961 */
/*<       if(rflag.eq.-10)then >*/
			if (rflag == -10) {
/* SOURCE ufgculv.for:3962 */
/*<       write(stdout,*)' SO FLOW is not SO!: XE_R=',xe_r >*/
			    feq_gen_io_d__537.ciunit = *stdout;
			    s_wsle(&feq_gen_io_d__537);
			    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" SO FLOW is not SO!: XE_R="),
				     (ftnlen)26);
			    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&feq_gen_xe_r_d_, (ftnlen)
				    sizeof(real));
			    e_wsle();
/* SOURCE ufgculv.for:3963 */
/*<       q=qfree >*/
			    q = qfree;
/* SOURCE ufgculv.for:3964 */
/*<       yvcold=hg*cc >*/
			    yvcold = static_cast<double>(ufcom_1.hg) * ufcom_1.cc;
/* SOURCE ufgculv.for:3965 */
/*<       endif >*/
			}
/* SOURCE ufgculv.for:3966 */
/*<       qmat(ihu,j)=q >*/
			qmat[ihu + j * 151 - 152] = q;
/* SOURCE ufgculv.for:3967 */
/*<       h3=y3+z3b-hdatum >*/
			h3 = static_cast<double>(static_cast<double>(ufcom_1.y3) + ufcom_1.z3b) - hdatum;
/* SOURCE ufgculv.for:3968 */
/*<       write(char8,'(F8.3)')h3 >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 8;
			feq_gen_ici_d_1.iciunit = char8;
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.3)");
			s_wsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&h3, (ftnlen)sizeof(real));
			e_wsfi();
/* SOURCE ufgculv.for:3969 */
/*<       p=log(q/qmat(ihu,j+1))/log(pfdvec(j)/pfdvec(j+1)) >*/
			p = log(static_cast<double>(q) / qmat[ihu + (j + 1) * 151 - 152]) / log(
				static_cast<double>(pfdvec[j - 1]) / pfdvec[j]);
/* SOURCE ufgculv.for:3970 */
/*<       de1to4=h1+alpha1*(q/a1)**2/twog-(h4+alpha4*(q/a4)**2/twog) >*/
/* Computing 2nd power */
			feq_gen_r_d_1 = static_cast<double>(q) / ufcom_1.a1;
/* Computing 2nd power */
			feq_gen_r_d_2 = static_cast<double>(q) / ufcom_1.a4;
			de1to4 = static_cast<double>(static_cast<double>(h1) + static_cast<double>(static_cast<double>(ufcom_1.alpha1) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / 
				ufcom_1.twog) - (static_cast<double>(h4) + static_cast<double>(static_cast<double>(ufcom_1.alpha4) * (static_cast<double>(feq_gen_r_d_2) * 
				feq_gen_r_d_2)) / ufcom_1.twog);
/* SOURCE ufgculv.for:3972 */
/*<       if(de1to4.lt.0.0)elflag=1 >*/
			if (de1to4 < (float)0.) {
			    elflag = 1;
			}
/* SOURCE ufgculv.for:3974 */
/*<       cq(1:10)=put10(q) >*/
			put10_(feq_gen_ch_d_5, (ftnlen)10, &q);
			s_copy(cq, feq_gen_ch_d_5, (ftnlen)10, (ftnlen)10);
/* SOURCE ufgculv.for:3975 */
/*<       if(rflag.eq.-12)then >*/
			if (rflag == -12) {
/* SOURCE ufgculv.for:3976 */
/*<       cq(11:11)='*' >*/
			    *(unsigned char *)&cq[10] = '*';
/* SOURCE ufgculv.for:3977 */
/*<       else >*/
			} else {
/* SOURCE ufgculv.for:3978 */
/*<       cq(11:11)=' ' >*/
			    *(unsigned char *)&cq[10] = ' ';
/* SOURCE ufgculv.for:3979 */
/*<       endif >*/
			}
/* SOURCE ufgculv.for:3980 */
/*<       write(stdout,75)pfdvec(j),drop,char8,h4,ftype,char6,cq,p,de1to4 >*/
			feq_gen_io_d__538.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__538);
			do_fio(&feq_gen_c_d_1, (char *)&pfdvec[j - 1], (ftnlen)sizeof(
				real));
			do_fio(&feq_gen_c_d_1, (char *)&drop, (ftnlen)sizeof(real));
			do_fio(&feq_gen_c_d_1, char8, (ftnlen)8);
			do_fio(&feq_gen_c_d_1, (char *)&h4, (ftnlen)sizeof(real));
			do_fio(&feq_gen_c_d_1, ftype, (ftnlen)2);
			do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
			do_fio(&feq_gen_c_d_1, cq, (ftnlen)11);
			do_fio(&feq_gen_c_d_1, (char *)&p, (ftnlen)sizeof(real));
			do_fio(&feq_gen_c_d_1, (char *)&de1to4, (ftnlen)sizeof(real));
			e_wsfe();
/* SOURCE ufgculv.for:3982 */
/*<   450 continue >*/
/* L450: */
		    }
/* SOURCE ufgculv.for:3984 */
/*<       else >*/
		} else {
/*             Should not get here. */
/* SOURCE ufgculv.for:3986 */
/*<       write(stdout,*)' no FC flow wrong branch.' >*/
		    feq_gen_io_d__539.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__539);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" no FC flow wrong branch."), (ftnlen)
			    25);
		    e_wsle();
/* SOURCE ufgculv.for:3987 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE ufgculv.for:3988 */
/*<       endif >*/
		}
/* SOURCE ufgculv.for:3990 */
/*<       else >*/
	    } else {
/*           Free flow is FO here */
/* SOURCE ufgculv.for:3993 */
/*<       ftype='FO' >*/
		s_copy(ftype, const_cast<char*>("FO"), (ftnlen)2, (ftnlen)2);
/* SOURCE ufgculv.for:3994 */
/*<       rg=hg/h1 >*/
		rg = static_cast<double>(ufcom_1.hg) / h1;
/* SOURCE ufgculv.for:3997 */
/*<       write(char6,'(F6.3)')cc >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 6;
		feq_gen_ici_d_1.iciunit = char6;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(F6.3)");
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.cc, (ftnlen)sizeof(real));
		e_wsfi();
/* SOURCE ufgculv.for:3999 */
/*<        >*/
		feq_gen_d_d_1 = (doublereal) hdatum;
		feq_gen_d_d_2 = (doublereal) ufcom_1.hg;
		feq_gen_d_d_3 = (doublereal) ufcom_1.bg;
		feq_gen_d_d_4 = (doublereal) ufcom_1.z1b;
		feq_gen_d_d_5 = (doublereal) ufcom_1.cc;
		feq_gen_ufg_fndfoq_d_(stdout, &ufcom_1.apptab, &ufgated_1.feq_gen_h1_d_d_, &
			feq_gen_d_d_1, &feq_gen_d_d_2, &feq_gen_d_d_3, &feq_gen_d_d_4, &feq_gen_d_d_5, &feq_gen_cd_culv_d_, &
			ufgated_1.feq_gen_twog_d_d_, &ufgc1_1.qd);
/* SOURCE ufgculv.for:4005 */
/*<       qfree=sngl(qd) >*/
		qfree = (real) ufgc1_1.qd;
/* SOURCE ufgculv.for:4006 */
/*<       y2=cc*hg >*/
		ufcom_1.y2 = static_cast<double>(ufcom_1.cc) * ufcom_1.hg;
/*           Find the water depth at the culvert exit and also check */
/*           to make sure the vena contracta is not drowned. */
/* SOURCE ufgculv.for:4011 */
/*<       ycrit=0.5d0*vert_d >*/
		ycrit = ufgc1_1.feq_gen_vert_d_d_ * .5;
/* SOURCE ufgculv.for:4012 */
/*<       ynorm=ycrit >*/
		ynorm = ycrit;
/* SOURCE ufgculv.for:4013 */
/*<        >*/
		feq_gen_get_ycynym_d_(stdout, &ufgc1_1.station[ufgc1_1.nxs - 1], &
			ufgated_1.feq_gen_epsarg_d_d_, &ufgated_1.feq_gen_epsf_d_d_, &
			ufgated_1.feq_gen_epsabs_d_d_, &ycrit, &ynorm, &ymax, &rflag);
/* SOURCE ufgculv.for:4019 */
/*<       yvc=hg_d*dble(cc) >*/
		yvc = ufgated_1.feq_gen_hg_d_d_ * (doublereal) ufcom_1.cc;
/* SOURCE ufgculv.for:4020 */
/*<       if(ynorm.lt.0.d0.or.ycrit.lt.ynorm)then >*/
		if (ynorm < 0. || ycrit < ynorm) {
/*             The slope is mild or flat.  To check for possible */
/*             drowning of the vena contract, compute a profile */
/*             upstream using the same methods as in FIND_FOLL and */
/*             FIND_FCQ. */
/* SOURCE ufgculv.for:4026 */
/*<       y3=ycrit >*/
		    ufcom_1.y3 = ycrit;
/* SOURCE ufgculv.for:4028 */
/*<       callprofile_ups(ycrit,ynorm,yvc,dble(cc),rflag) >*/
		    feq_gen_d_d_1 = (doublereal) ufcom_1.cc;
		    feq_gen_profile_ups_d_(&ycrit, &ynorm, &yvc, &feq_gen_d_d_1, &rflag);
/* SOURCE ufgculv.for:4032 */
/*<       if(rflag.eq.0)then >*/
		    if (rflag == 0) {
/*                WRITE(STDOUT,*) ' Vena contracta is drowned.' */
/* SOURCE ufgculv.for:4034 */
/*<       else >*/
		    } else {
/*                WRITE(STDOUT,*) ' Vena contracta is free.' */
/* SOURCE ufgculv.for:4036 */
/*<       endif >*/
		    }
/* SOURCE ufgculv.for:4037 */
/*<       else >*/
		} else {
/*             The slope is steep.  Compute a free surface */
/*             profile from the vena contracta towards the exit. */
/* SOURCE ufgculv.for:4040 */
/*<       ys=yvc >*/
		    ys = yvc;
/* SOURCE ufgculv.for:4041 */
/*<       xe=station(nxs) >*/
		    xe = ufgc1_1.station[ufgc1_1.nxs - 1];
/* SOURCE ufgculv.for:4042 */
/*<       xs=station(1)+hg_d >*/
		    xs = ufgc1_1.station[0] + ufgated_1.feq_gen_hg_d_d_;
/* SOURCE ufgculv.for:4043 */
/*<        >*/
		    sfwsp_(stdout, &xs, &xe, &ys, &ufgated_1.feq_gen_eps_d_d_, e_, rhse_, feq_gen_find_ycynym_d_, &feq_gen_c_d_2000, &
			    ns, &ne, ufgated_1.xvec, ufgated_1.yvec, 
			    ufgated_1.ycvec, ufgated_1.ynvec, eflag);
/* SOURCE ufgculv.for:4047 */
/*<       if(abs((xvec(ne)-xe)/xe).lt.0.001)then >*/
		    if ((feq_gen_d_d_1 = (ufgated_1.xvec[ne - 1] - xe) / xe, abs(feq_gen_d_d_1))
			     < (float).001) {
/*                WRITE(STDOUT,*) ' Super critical flow to end. Y=', */
/*     A                     SNGL(YVEC(NE)) */
/* SOURCE ufgculv.for:4051 */
/*<       y3=yvec(ne) >*/
			ufcom_1.y3 = ufgated_1.yvec[ne - 1];
/* SOURCE ufgculv.for:4052 */
/*<       else >*/
		    } else {
/* SOURCE ufgculv.for:4053 */
/*<       write(stdout,*)' Jump expected when none should appear' >*/
			feq_gen_io_d__540.ciunit = *stdout;
			s_wsle(&feq_gen_io_d__540);
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Jump expected when none shoul\
d appear"), (ftnlen)38);
			e_wsle();
/* SOURCE ufgculv.for:4054 */
/*<       write(stdout,*)' YCRIT=',ycrit,' YNORM=',ynorm >*/
			feq_gen_io_d__541.ciunit = *stdout;
			s_wsle(&feq_gen_io_d__541);
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" YCRIT="), (ftnlen)7);
			do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&ycrit, (ftnlen)sizeof(
				doublereal));
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" YNORM="), (ftnlen)7);
			do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&ynorm, (ftnlen)sizeof(
				doublereal));
			e_wsle();
/* SOURCE ufgculv.for:4055 */
/*<       write(stdout,*)' XVEC(NE)=',xvec(ne),' YE=',yvec(ne) >*/
			feq_gen_io_d__542.ciunit = *stdout;
			s_wsle(&feq_gen_io_d__542);
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" XVEC(NE)="), (ftnlen)10);
			do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&ufgated_1.xvec[ne - 1], 
				(ftnlen)sizeof(doublereal));
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" YE="), (ftnlen)4);
			do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&ufgated_1.yvec[ne - 1], 
				(ftnlen)sizeof(doublereal));
			e_wsle();
/* SOURCE ufgculv.for:4057 */
/*<       write(stdout,*)' QD=',qd >*/
			feq_gen_io_d__543.ciunit = *stdout;
			s_wsle(&feq_gen_io_d__543);
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" QD="), (ftnlen)4);
			do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&ufgc1_1.qd, (ftnlen)
				sizeof(doublereal));
			e_wsle();
/* SOURCE ufgculv.for:4058 */
/*<       stop'Abnormal stop. Errors found.' >*/
			s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE ufgculv.for:4059 */
/*<       endif >*/
		    }
/* SOURCE ufgculv.for:4061 */
/*<       endif >*/
		}
/*           Now find the level at section 4 that defines */
/*           the limit of free orifice flow, Y4F. Define the constant */
/*           values.  First, find the sequent depth at the vena */
/*           contracta */
/* SOURCE ufgculv.for:4068 */
/*<        >*/
		feq_gen_d_d_1 = (doublereal) ufcom_1.cc;
		feq_gen_find_sequent_depth_d_(stdout, &ufgated_1.feq_gen_grav_d_d_, &
			ufgated_1.feq_gen_hg_d_d_, &ufgated_1.feq_gen_bg_d_d_, &feq_gen_d_d_1, &
			ufgc1_1.qd, &ufgated_1.feq_gen_epsarg_d_d_, &
			ufgated_1.feq_gen_epsf_d_d_, &feq_gen_yb_d_d_);
/*            WRITE(STDOUT,*) ' SEQUENT DEPTH=',YB_D */
/*           Now try to compute a water-surface profile */
/*           downstream from the sequent depth to the */
/*           culvert exit. */
/* SOURCE ufgculv.for:4078 */
/*<       ys=yb_d >*/
		ys = feq_gen_yb_d_d_;
/* SOURCE ufgculv.for:4079 */
/*<       xe=station(nxs) >*/
		xe = ufgc1_1.station[ufgc1_1.nxs - 1];
/* SOURCE ufgculv.for:4080 */
/*<       xs=station(1)+hg_d >*/
		xs = ufgc1_1.station[0] + ufgated_1.feq_gen_hg_d_d_;
/* SOURCE ufgculv.for:4081 */
/*<        >*/
		sfwsp_(stdout, &xs, &xe, &ys, &ufgated_1.feq_gen_eps_d_d_, e_, rhse_, feq_gen_find_ycynym_d_, &feq_gen_c_d_2000, &ns, &ne, 
			ufgated_1.xvec, ufgated_1.yvec, ufgated_1.ycvec, 
			ufgated_1.ynvec, eflag);
/*            WRITE(STDOUT,*) ' Y3F=',YVEC(NE) */
/* SOURCE ufgculv.for:4086 */
/*<       y3=yvec(ne) >*/
		ufcom_1.y3 = ufgated_1.yvec[ne - 1];
/* SOURCE ufgculv.for:4087 */
/*<       calllkta(xsec_adrs(nxs),y3,a3) >*/
		lkta_(&ufgc1_1.feq_gen_xsec_adrs_d_[ufgc1_1.nxs - 1], &ufcom_1.y3, &a3)
			;
/*           Next compute the water level at section 4 from the */
/*           water level at section 3. */
/* SOURCE ufgculv.for:4094 */
/*<        >*/
		feq_gen_r_d_1 = (real) ufgc1_1.feq_gen_cos_theta_d_;
		feq_gen_find_y4_from_y43_d_(stdout, grav, &qfree, &ufcom_1.deptab, &
			ufcom_1.z3b, &ufcom_1.z4b, &ufcom_1.y3, &a3, &feq_gen_r_d_1, &
			y4f, eflag);
/*            WRITE(STDOUT,*) ' Y4F=',Y4F */
/* SOURCE ufgculv.for:4103 */
/*<       zw4f=y4f+z4b >*/
		zw4f = static_cast<double>(y4f) + ufcom_1.z4b;
/* SOURCE ufgculv.for:4104 */
/*<       h4f=zw4f-hdatum >*/
		h4f = static_cast<double>(zw4f) - hdatum;
/* SOURCE ufgculv.for:4105 */
/*<        >*/
		xlkt22_(&ufcom_1.deptab, &y4f, &ufcom_1.a4, &ufcom_1.tt, &dt, 
			&ufcom_1.j4, &ufcom_1.kt, &ufcom_1.dkt, &
			ufcom_1.beta4, &ufcom_1.dbeta, &ufcom_1.alpha4, &
			ufcom_1.dalpha, &ufcom_1.qct);
/* SOURCE ufgculv.for:4111 */
/*<        >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = static_cast<double>(qfree) / ufcom_1.a1;
/* Computing 2nd power */
		feq_gen_r_d_2 = static_cast<double>(qfree) / ufcom_1.a4;
		de1to4 = static_cast<double>(static_cast<double>(h1) + static_cast<double>(static_cast<double>(ufcom_1.alpha1) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / ufcom_1.twog) - 
			(static_cast<double>(h4f) + static_cast<double>(static_cast<double>(ufcom_1.alpha4) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) / ufcom_1.twog);
/* SOURCE ufgculv.for:4113 */
/*<       if(de1to4.lt.0.0)elflag=1 >*/
		if (de1to4 < (float)0.) {
		    elflag = 1;
		}
/* SOURCE ufgculv.for:4114 */
/*<       qmat(ihu,nfrac)=qfree >*/
		qmat[ihu + nfrac * 151 - 152] = qfree;
/* SOURCE ufgculv.for:4115 */
/*<       fdrop=y1+z1b-zw4f >*/
		fdrop = static_cast<double>(static_cast<double>(ufcom_1.y1) + ufcom_1.z1b) - zw4f;
/* SOURCE ufgculv.for:4116 */
/*<       fdvec(ihu)=fdrop >*/
		fdvec[ihu - 1] = fdrop;
/* SOURCE ufgculv.for:4117 */
/*<       cq=put10(qfree) >*/
		put10_(feq_gen_ch_d_5, (ftnlen)10, &qfree);
		s_copy(cq, feq_gen_ch_d_5, (ftnlen)11, (ftnlen)10);
/* SOURCE ufgculv.for:4118 */
/*<       cq(11:11)=' ' >*/
		*(unsigned char *)&cq[10] = ' ';
/* SOURCE ufgculv.for:4119 */
/*<       write(stdout,76)1.00,fdrop,y3+z3b-hdatum,h4f,ftype,char6,cq,de1to4 >*/
		feq_gen_io_d__546.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__546);
		do_fio(&feq_gen_c_d_1, (char *)&c_b477, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&fdrop, (ftnlen)sizeof(real));
		feq_gen_r_d_1 = static_cast<double>(static_cast<double>(ufcom_1.y3) + ufcom_1.z3b) - hdatum;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&h4f, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, ftype, (ftnlen)2);
		do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
		do_fio(&feq_gen_c_d_1, cq, (ftnlen)11);
		do_fio(&feq_gen_c_d_1, (char *)&de1to4, (ftnlen)sizeof(real));
		e_wsfe();
/*            OLDH3 = Y3 + Z3B - HDATUM */
/* SOURCE ufgculv.for:4122 */
/*<       ftype='SO' >*/
		s_copy(ftype, const_cast<char*>("SO"), (ftnlen)2, (ftnlen)2);
/*            AT = CD*CC*AG */
/* SOURCE ufgculv.for:4124 */
/*<       yvcold=cc*hg >*/
		yvcold = static_cast<double>(ufcom_1.cc) * ufcom_1.hg;
/* SOURCE ufgculv.for:4125 */
/*<       do500j=nfrac-1,2,-1 >*/
		for (j = nfrac - 1; j >= 2; --j) {
/* SOURCE ufgculv.for:4126 */
/*<       drop=fdrop*pfdvec(j) >*/
		    drop = static_cast<double>(fdrop) * pfdvec[j - 1];
/* SOURCE ufgculv.for:4127 */
/*<       zw4=z1b+y1-drop >*/
		    zw4 = static_cast<double>(static_cast<double>(ufcom_1.z1b) + ufcom_1.y1) - drop;
/* SOURCE ufgculv.for:4128 */
/*<       y4=zw4-z4b >*/
		    ufcom_1.y4 = static_cast<double>(zw4) - ufcom_1.z4b;
/* SOURCE ufgculv.for:4129 */
/*<        >*/
		    xlkt22_(&ufcom_1.deptab, &ufcom_1.y4, &ufcom_1.a4, &
			    ufcom_1.tt, &dt, &ufcom_1.j4, &ufcom_1.kt, &
			    ufcom_1.dkt, &ufcom_1.beta4, &ufcom_1.dbeta, &
			    ufcom_1.alpha4, &ufcom_1.dalpha, &ufcom_1.qct);
/* SOURCE ufgculv.for:4134 */
/*<       h4=zw4-hdatum >*/
		    h4 = static_cast<double>(zw4) - hdatum;
/* SOURCE ufgculv.for:4135 */
/*<        >*/
		    feq_gen_r_d_1 = (real) feq_gen_cd_culv_d_;
		    feq_gen_r_d_2 = (real) ufgc1_1.feq_gen_sin_theta_d_;
		    feq_gen_r_d_3 = (real) ufgc1_1.feq_gen_cos_theta_d_;
		    feq_gen_r_d_4 = (real) ufgc1_1.feq_gen_invert_z_d_[ufgc1_1.nxs - 1];
		    feq_gen_find_so_flow_d_(stdout, &ufcom_1.deptab, &
			    ufgc1_1.feq_gen_xsec_adrs_d_[ufgc1_1.nxs - 1], grav, &h1, &
			    ufcom_1.hg, &ufcom_1.bg, &ufcom_1.cc, &feq_gen_r_d_1, &
			    feq_gen_r_d_2, &feq_gen_r_d_3, &feq_gen_r_d_4, &ufcom_1.z4b, &ufcom_1.y4, &
			    ufcom_1.a4, &ufcom_1.beta4, &ufcom_1.j4, &
			    ufcom_1.alpha1, &ufcom_1.a1, &ufgc1_1.nxs, 
			    ufgc1_1.station, &ufgated_1.feq_gen_eps_d_d_, &yvcold, &q, 
			    &ufcom_1.y3, &feq_gen_xe_r_d_, &rflag);
/* SOURCE ufgculv.for:4144 */
/*<       if(rflag.eq.-10)then >*/
		    if (rflag == -10) {
/* SOURCE ufgculv.for:4145 */
/*<       write(stdout,*)' SO FLOW is not SO!: XE_R=',xe_r >*/
			feq_gen_io_d__547.ciunit = *stdout;
			s_wsle(&feq_gen_io_d__547);
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" SO FLOW is not SO!: XE_R="), (
				ftnlen)26);
			do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&feq_gen_xe_r_d_, (ftnlen)sizeof(
				real));
			e_wsle();
/* SOURCE ufgculv.for:4146 */
/*<       q=qfree >*/
			q = qfree;
/* SOURCE ufgculv.for:4147 */
/*<       yvcold=hg*cc >*/
			yvcold = static_cast<double>(ufcom_1.hg) * ufcom_1.cc;
/* SOURCE ufgculv.for:4148 */
/*<       endif >*/
		    }
/* SOURCE ufgculv.for:4149 */
/*<       qmat(ihu,j)=q >*/
		    qmat[ihu + j * 151 - 152] = q;
/* SOURCE ufgculv.for:4150 */
/*<       h3=y3+z3b-hdatum >*/
		    h3 = static_cast<double>(static_cast<double>(ufcom_1.y3) + ufcom_1.z3b) - hdatum;
/* SOURCE ufgculv.for:4151 */
/*<       write(char8,'(F8.3)')h3 >*/
		    feq_gen_ici_d_1.icierr = 0;
		    feq_gen_ici_d_1.icirnum = 1;
		    feq_gen_ici_d_1.icirlen = 8;
		    feq_gen_ici_d_1.iciunit = char8;
		    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.3)");
		    s_wsfi(&feq_gen_ici_d_1);
		    do_fio(&feq_gen_c_d_1, (char *)&h3, (ftnlen)sizeof(real));
		    e_wsfi();
/* SOURCE ufgculv.for:4152 */
/*<       p=log(q/qmat(ihu,j+1))/log(pfdvec(j)/pfdvec(j+1)) >*/
		    p = log(static_cast<double>(q) / qmat[ihu + (j + 1) * 151 - 152]) / log(static_cast<double>(pfdvec[
			    j - 1]) / pfdvec[j]);
/* SOURCE ufgculv.for:4153 */
/*<       de1to4=h1+alpha1*(q/a1)**2/twog-(h4+alpha4*(q/a4)**2/twog) >*/
/* Computing 2nd power */
		    feq_gen_r_d_1 = static_cast<double>(q) / ufcom_1.a1;
/* Computing 2nd power */
		    feq_gen_r_d_2 = static_cast<double>(q) / ufcom_1.a4;
		    de1to4 = static_cast<double>(static_cast<double>(h1) + static_cast<double>(static_cast<double>(ufcom_1.alpha1) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / 
			    ufcom_1.twog) - (static_cast<double>(h4) + static_cast<double>(static_cast<double>(ufcom_1.alpha4) * (static_cast<double>(feq_gen_r_d_2) * 
			    feq_gen_r_d_2)) / ufcom_1.twog);
/* SOURCE ufgculv.for:4155 */
/*<       if(de1to4.lt.0.0)elflag=1 >*/
		    if (de1to4 < (float)0.) {
			elflag = 1;
		    }
/* SOURCE ufgculv.for:4157 */
/*<       cq=put10(q) >*/
		    put10_(feq_gen_ch_d_5, (ftnlen)10, &q);
		    s_copy(cq, feq_gen_ch_d_5, (ftnlen)11, (ftnlen)10);
/* SOURCE ufgculv.for:4158 */
/*<       if(rflag.eq.-12)then >*/
		    if (rflag == -12) {
/* SOURCE ufgculv.for:4159 */
/*<       cq(11:11)='*' >*/
			*(unsigned char *)&cq[10] = '*';
/* SOURCE ufgculv.for:4160 */
/*<       else >*/
		    } else {
/* SOURCE ufgculv.for:4161 */
/*<       cq(11:11)=' ' >*/
			*(unsigned char *)&cq[10] = ' ';
/* SOURCE ufgculv.for:4162 */
/*<       endif >*/
		    }
/* SOURCE ufgculv.for:4163 */
/*<       write(stdout,75)pfdvec(j),drop,char8,h4,ftype,char6,cq,p,de1to4 >*/
		    feq_gen_io_d__548.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__548);
		    do_fio(&feq_gen_c_d_1, (char *)&pfdvec[j - 1], (ftnlen)sizeof(real)
			    );
		    do_fio(&feq_gen_c_d_1, (char *)&drop, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, char8, (ftnlen)8);
		    do_fio(&feq_gen_c_d_1, (char *)&h4, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, ftype, (ftnlen)2);
		    do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
		    do_fio(&feq_gen_c_d_1, cq, (ftnlen)11);
		    do_fio(&feq_gen_c_d_1, (char *)&p, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&de1to4, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE ufgculv.for:4165 */
/*<   500 continue >*/
/* L500: */
		}
/* SOURCE ufgculv.for:4167 */
/*<       endif >*/
	    }
/*         Compute approximate maximum error and report */
/* SOURCE ufgculv.for:4170 */
/*<       do600j=3,nfrac-2,2 >*/
	    feq_gen_i_d_4 = nfrac - 2;
	    for (j = 3; j <= feq_gen_i_d_4; j += 2) {
/* SOURCE ufgculv.for:4171 */
/*<       qhat=0.5*(qmat(ihu,j-1)+qmat(ihu,j+1)) >*/
		qhat = static_cast<double>((static_cast<double>(qmat[ihu + (j - 1) * 151 - 152]) + qmat[ihu + (j + 1) *
			 151 - 152])) * (float).5;
/* SOURCE ufgculv.for:4172 */
/*<       rerr=abs(qhat-qmat(ihu,j))/qmat(ihu,j) >*/
		rerr = (feq_gen_r_d_1 = static_cast<double>(qhat) - qmat[ihu + j * 151 - 152], dabs(feq_gen_r_d_1)) /
			 qmat[ihu + j * 151 - 152];
/* SOURCE ufgculv.for:4173 */
/*<       rms=rms+rerr*rerr >*/
		rms += static_cast<double>(rerr) * rerr;
/* SOURCE ufgculv.for:4174 */
/*<       nrms=nrms+1 >*/
		++nrms;
/* SOURCE ufgculv.for:4175 */
/*<       if(rerr.gt.bigerr)then >*/
		if (rerr > bigerr) {
/* SOURCE ufgculv.for:4176 */
/*<       bigerr=rerr >*/
		    bigerr = rerr;
/* SOURCE ufgculv.for:4177 */
/*<       herr=h1 >*/
		    herr = h1;
/* SOURCE ufgculv.for:4178 */
/*<       ipfd=j >*/
		    ipfd = j;
/* SOURCE ufgculv.for:4179 */
/*<       ihgerr=ihg >*/
		    ihgerr = ihg;
/* SOURCE ufgculv.for:4180 */
/*<       endif >*/
		}
/* SOURCE ufgculv.for:4181 */
/*<   600 continue >*/
/* L600: */
	    }
/* C         Eliminate the checking values from QMAT */
/*          JBASE = 3 */
/*          DO 700 J=4,NFRAC-1,2 */
/*            QMAT(IHU,JBASE) = QMAT(IHU,J) */
/*            JBASE = JBASE + 1 */
/* 700      CONTINUE */
/*          QMAT(IHU,JBASE) = QMAT(IHU,NFRAC) */
/* SOURCE ufgculv.for:4191 */
/*<   900 continue >*/
/* L900: */
	}
/*        PFDTMP(1) = PFDVEC(1) */
/*        PFDTMP(2) = PFDVEC(2) */
/*        JBASE = 3 */
/*        DO 910 J=4,NFRAC-1,2 */
/*          PFDTMP(JBASE) = PFDVEC(J) */
/*          JBASE = JBASE + 1 */
/* 910    CONTINUE */
/*        PFDTMP(JBASE) = PFDVEC(NFRAC) */
/* SOURCE ufgculv.for:4201 */
/*<       zrhufd=0.0 >*/
	zrhufd = (float)0.;
/* SOURCE ufgculv.for:4202 */
/*<        >*/
	twdout_(stdout, stdtab, &tab2d[ihg - 1], label, &nhu, &nfrac, huvec, 
		fdvec, pfdvec, qmat, &hdatum, &feq_gen_c_d_13, const_cast<char*>(" UFGCULV"), &zrhufd, 
		zone, hgrid, vdatum, unitsys, basis, &easting, &northing, 
		eflag, (ftnlen)50, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8,
		 (ftnlen)8, (ftnlen)8);
/* SOURCE ufgculv.for:4210 */
/*<       if(elflag.gt.0)then >*/
	if (elflag > 0) {
/* SOURCE ufgculv.for:4211 */
/*<       write(stdout,77) >*/
	    feq_gen_io_d__555.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__555);
	    e_wsfe();
/* SOURCE ufgculv.for:4212 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:4213 */
/*<  1000 continue >*/
/* L1000: */
    }
/* SOURCE ufgculv.for:4217 */
/*<       write(stdout,86)bigerr,hgvec(ihgerr),herr,pfdvec(ipfd) >*/
    feq_gen_io_d__556.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__556);
    do_fio(&feq_gen_c_d_1, (char *)&bigerr, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&hgvec[ihgerr - 1], (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&herr, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&pfdvec[ipfd - 1], (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE ufgculv.for:4220 */
/*<       rms=sqrt(rms/float(nrms)) >*/
    rms = sqrt(static_cast<double>(rms) / (real) nrms);
/* SOURCE ufgculv.for:4221 */
/*<       write(stdout,88)rms,nrms >*/
    feq_gen_io_d__557.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__557);
    do_fio(&feq_gen_c_d_1, (char *)&rms, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&nrms, (ftnlen)sizeof(integer));
    e_wsfe();
/*     Output the table of type 15 to the table file */
/* SOURCE ufgculv.for:4224 */
/*<       tabid=get_tabid(tab) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &tab);
    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE ufgculv.for:4225 */
/*<       write(stdtab,95)tabid(1:lenstr(tabid)),lab2 >*/
    feq_gen_io_d__559.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__559);
    do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
    do_fio(&feq_gen_c_d_1, lab2, (ftnlen)50);
    e_wsfe();
/* SOURCE ufgculv.for:4226 */
/*<       do1005i=1,nhg >*/
    feq_gen_i_d_1 = nhg;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ufgculv.for:4227 */
/*<       write(stdtab,96)hgvec(i),get_tabid(tab2d(i)),(hstuff(i,j),j=1,3) >*/
	feq_gen_io_d__560.ciunit = *stdtab;
	s_wsfe(&feq_gen_io_d__560);
	do_fio(&feq_gen_c_d_1, (char *)&hgvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tab2d[feq_gen_i_d_ - 1]);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	for (j = 1; j <= 3; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&hstuff[feq_gen_i_d_ + j * 40 - 41], (ftnlen)sizeof(
		    real));
	}
	e_wsfe();
/* SOURCE ufgculv.for:4229 */
/*<  1005 continue >*/
/* L1005: */
    }
/* SOURCE ufgculv.for:4230 */
/*<       write(stdtab,96)-1.0 >*/
    feq_gen_io_d__561.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__561);
    do_fio(&feq_gen_c_d_1, (char *)&c_b634, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE ufgculv.for:4231 */
/*<       return >*/
    return 0;
/* SOURCE ufgculv.for:4232 */
/*<   991 continue >*/
L991:
/* SOURCE ufgculv.for:4233 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__562.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__562);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE ufgculv.for:4234 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__563.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__563);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE ufgculv.for:4235 */
/*<       stop'Abnormal stop.  Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE ufgculv.for:4236 */
/*<       end >*/
    return 0;
} /* ufgculv_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE ufgculv.for:4240 */
/*<       subroutineset_ufgc_tabids_defaults() >*/
/* Subroutine */ int feq_gen_set_ufgc_tabids_defaults_d_()
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     Set the default values in the vectors used to process a */
/*     deparature reach table spec. */
/* SOURCE ufgculv.for:4244 */
/*<       implicitnone >*/
/* INCLUDE ufgculv.for:4245 */
/* SOURCE ufgcitm.cmn:1 */
/*<       integermaxr_ufgcitm,maxc_ufgcitm,maxdp_ufgcitm >*/
/* SOURCE ufgcitm.cmn:2 */
/*<       parameter(maxr_ufgcitm=1,maxc_ufgcitm=4,maxdp_ufgcitm=1) >*/
/* SOURCE ufgcitm.cmn:3 */
/*<       integerufgcitmitab(maxr_ufgcitm) >*/
/* SOURCE ufgcitm.cmn:4 */
/*<       realufgcitmftab(maxr_ufgcitm) >*/
/* SOURCE ufgcitm.cmn:5 */
/*<       real*8ufgcitmdtab(maxdp_ufgcitm) >*/
/* SOURCE ufgcitm.cmn:6 */
/*<       character*64ufgcitmctab(maxc_ufgcitm) >*/
/* SOURCE ufgcitm.cmn:8 */
/*<       common/ufgcitm_com/ufgcitmdtab,ufgcitmitab,ufgcitmftab >*/
/* SOURCE ufgcitm.cmn:10 */
/*<       common/ufgcitm_comc/ufgcitmctab >*/
/* *********************************************************************** */
/*     Default for: TABID */
/* SOURCE ufgculv.for:4249 */
/*<       ufgcitmctab(1)='    ' >*/
    s_copy(feq_gen_ufgcitm_comc_d_1.ufgcitmctab, const_cast<char*>("    "), (ftnlen)64, (ftnlen)4);
/*     Default for: TABLE - note # is ignored in the standard scanner */
/* SOURCE ufgculv.for:4251 */
/*<       ufgcitmctab(2)='    ' >*/
    s_copy(feq_gen_ufgcitm_comc_d_1.ufgcitmctab + 64, const_cast<char*>("    "), (ftnlen)64, (ftnlen)4);
/*     Default for: GETQ */
/* SOURCE ufgculv.for:4253 */
/*<       ufgcitmctab(3)='    ' >*/
    s_copy(feq_gen_ufgcitm_comc_d_1.ufgcitmctab + 128, const_cast<char*>("    "), (ftnlen)64, (ftnlen)4);
/*     Default for: GETY2 */
/* SOURCE ufgculv.for:4255 */
/*<       ufgcitmctab(4)='    ' >*/
    s_copy(feq_gen_ufgcitm_comc_d_1.ufgcitmctab + 192, const_cast<char*>("    "), (ftnlen)64, (ftnlen)4);
/* SOURCE ufgculv.for:4256 */
/*<       return >*/
    return 0;
/* SOURCE ufgculv.for:4257 */
/*<       end >*/
} /* set_ufgc_tabids_defaults__ */




/* SOURCE ufgculv.for:4261 */
/*<       subroutineset_ufgc_tabids(tab,getq,gety2,eflag) >*/
/* Subroutine */ int feq_gen_set_ufgc_tabids_d_(integer *tab, integer *getq, integer *
	gety2, integer *eflag)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    char key[16], key1[16], key2[16];

/*     Set items UFGCULV */
/*     All values not set explicitly by user are at their default value. */
/* SOURCE ufgculv.for:4268 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:4270 */
/*<       integertab,getq,gety2,eflag >*/
/*     Local */
/* SOURCE ufgculv.for:4274 */
/*<       character*16key,key1,key2 >*/
/* INCLUDE ufgculv.for:4276 */
/* SOURCE ufgcitm.cmn:1 */
/*<       integermaxr_ufgcitm,maxc_ufgcitm,maxdp_ufgcitm >*/
/* SOURCE ufgcitm.cmn:2 */
/*<       parameter(maxr_ufgcitm=1,maxc_ufgcitm=4,maxdp_ufgcitm=1) >*/
/* SOURCE ufgcitm.cmn:3 */
/*<       integerufgcitmitab(maxr_ufgcitm) >*/
/* SOURCE ufgcitm.cmn:4 */
/*<       realufgcitmftab(maxr_ufgcitm) >*/
/* SOURCE ufgcitm.cmn:5 */
/*<       real*8ufgcitmdtab(maxdp_ufgcitm) >*/
/* SOURCE ufgcitm.cmn:6 */
/*<       character*64ufgcitmctab(maxc_ufgcitm) >*/
/* SOURCE ufgcitm.cmn:8 */
/*<       common/ufgcitm_com/ufgcitmdtab,ufgcitmitab,ufgcitmftab >*/
/* SOURCE ufgcitm.cmn:10 */
/*<       common/ufgcitm_comc/ufgcitmctab >*/
/* INCLUDE ufgculv.for:4277 */
/*     These I/O units will NOT have the number implied by their name. */
/*     The number will be assigned in FEQ/FEQUTL and will not be the same */
/*     as the old historic standard numbers. */
/*     This common block is retained in order to make transition to */
/*     internal assignment of I/O unit numbers easier. */
/* SOURCE stdun.cmn:7 */
/*<       integerstd5,std6,std7,std10,std48,std49,std50 >*/
/* SOURCE stdun.cmn:9 */
/*<       common/stdun_com/std5,std6,std7,std10,std48,std49,std50 >*/
/* SOURCE stdun.cmn:11 */
/*<       save/stdun_com/ >*/
/* *********************************************************************** */
/* SOURCE ufgculv.for:4279 */
/*<       key1=ufgcitmctab(1) >*/
    s_copy(key1, feq_gen_ufgcitm_comc_d_1.ufgcitmctab, (ftnlen)16, (ftnlen)64);
/* SOURCE ufgculv.for:4280 */
/*<       key2=ufgcitmctab(2) >*/
    s_copy(key2, feq_gen_ufgcitm_comc_d_1.ufgcitmctab + 64, (ftnlen)16, (ftnlen)64);
/* SOURCE ufgculv.for:4281 */
/*<       if(key1.ne.' ')then >*/
    if (s_cmp(key1, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/* SOURCE ufgculv.for:4282 */
/*<       callget_internal_tab_number(std6,key1,eflag,tab) >*/
	feq_gen_get_internal_tab_number_d_(&feq_gen_stdun_com_d_1.std6, key1, eflag, tab, (
		ftnlen)16);
/* SOURCE ufgculv.for:4286 */
/*<       elseif(key2.ne.' ')then >*/
    } else if (s_cmp(key2, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/* SOURCE ufgculv.for:4287 */
/*<       callget_internal_tab_number(std6,key2,eflag,tab) >*/
	feq_gen_get_internal_tab_number_d_(&feq_gen_stdun_com_d_1.std6, key2, eflag, tab, (
		ftnlen)16);
/* SOURCE ufgculv.for:4291 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:4292 */
/*<       tab=0 >*/
	*tab = 0;
/* SOURCE ufgculv.for:4293 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:4294 */
/*<       key=ufgcitmctab(3) >*/
    s_copy(key, feq_gen_ufgcitm_comc_d_1.ufgcitmctab + 128, (ftnlen)16, (ftnlen)64);
/* SOURCE ufgculv.for:4295 */
/*<       if(key.ne.' ')then >*/
    if (s_cmp(key, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/* SOURCE ufgculv.for:4296 */
/*<       callget_internal_tab_number(std6,key,eflag,getq) >*/
	feq_gen_get_internal_tab_number_d_(&feq_gen_stdun_com_d_1.std6, key, eflag, getq, (
		ftnlen)16);
/* SOURCE ufgculv.for:4300 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:4301 */
/*<       getq=0 >*/
	*getq = 0;
/* SOURCE ufgculv.for:4302 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:4303 */
/*<       key=ufgcitmctab(4) >*/
    s_copy(key, feq_gen_ufgcitm_comc_d_1.ufgcitmctab + 192, (ftnlen)16, (ftnlen)64);
/* SOURCE ufgculv.for:4304 */
/*<       if(key.ne.' ')then >*/
    if (s_cmp(key, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/* SOURCE ufgculv.for:4305 */
/*<       callget_internal_tab_number(std6,key,eflag,gety2) >*/
	feq_gen_get_internal_tab_number_d_(&feq_gen_stdun_com_d_1.std6, key, eflag, gety2, (
		ftnlen)16);
/* SOURCE ufgculv.for:4309 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:4310 */
/*<       gety2=0 >*/
	*gety2 = 0;
/* SOURCE ufgculv.for:4311 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:4312 */
/*<       return >*/
    return 0;
/* SOURCE ufgculv.for:4313 */
/*<       end >*/
} /* set_ufgc_tabids__ */




/* SOURCE ufgculv.for:4317 */
/*<       subroutineget_ufgc_tabids(stdin,stdout,eflag) >*/
/* Subroutine */ int feq_gen_get_ufgc_tabids_d_(integer *stdin, integer *stdout, 
	integer *eflag)
{
    /* Initialized data */

    static char feq_gen_symbol_table_d_[16*4+1] = "TABID           TABLE           GE\
TQ            GETY2           ";
    static integer group[4] = { 1,1,1,1 };
    static integer feq_gen_group_index_d_[4] = { 1,2,3,4 };
    static integer feq_gen_response_type_d_[4] = { 4,4,4,4 };
    static integer feq_gen_convert_rule_d_[4] = { 1,1,1,1 };

    integer feq_gen_max_line_d_;
    extern /* Subroutine */ int feq_gen_set_ufgc_tabids_defaults_d_(), 
	    feq_gen_get_named_items_d_(integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, char *, integer *, 
	    integer *, integer *, char *, integer *, real *, doublereal *, 
	    char *, integer *, ftnlen, ftnlen, ftnlen);

/*     Get the table ids for the a culvert with an underflow gate */
/* SOURCE ufgculv.for:4322 */
/*<       implicitnone >*/
/* INCLUDE ufgculv.for:4324 */
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
/* SOURCE ufgculv.for:4326 */
/*<       integerstdin,stdout,eflag >*/
/* INCLUDE ufgculv.for:4328 */
/* SOURCE ufgcitm.cmn:1 */
/*<       integermaxr_ufgcitm,maxc_ufgcitm,maxdp_ufgcitm >*/
/* SOURCE ufgcitm.cmn:2 */
/*<       parameter(maxr_ufgcitm=1,maxc_ufgcitm=4,maxdp_ufgcitm=1) >*/
/* SOURCE ufgcitm.cmn:3 */
/*<       integerufgcitmitab(maxr_ufgcitm) >*/
/* SOURCE ufgcitm.cmn:4 */
/*<       realufgcitmftab(maxr_ufgcitm) >*/
/* SOURCE ufgcitm.cmn:5 */
/*<       real*8ufgcitmdtab(maxdp_ufgcitm) >*/
/* SOURCE ufgcitm.cmn:6 */
/*<       character*64ufgcitmctab(maxc_ufgcitm) >*/
/* SOURCE ufgcitm.cmn:8 */
/*<       common/ufgcitm_com/ufgcitmdtab,ufgcitmitab,ufgcitmftab >*/
/* SOURCE ufgcitm.cmn:10 */
/*<       common/ufgcitm_comc/ufgcitmctab >*/
/*     Local */
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE ufgculv.for:4333 */
/*<        >*/
/* SOURCE ufgculv.for:4336 */
/*<        >*/
/* SOURCE ufgculv.for:4340 */
/*<       integermax_line >*/
/* SOURCE ufgculv.for:4343 */
/*<       externalget_named_items,set_ufgc_tabids_defaults >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE ufgculv.for:4346 */
/*<        >*/
/* SOURCE ufgculv.for:4348 */
/*<       charactersymbol_table(n_symbol)*16 >*/
/* SOURCE ufgculv.for:4350 */
/*<       savesymbol_table,group,response_type,convert_rule,group_index >*/
/* *********************************************************************** */
/*     Set Defaults */
/* SOURCE ufgculv.for:4353 */
/*<       datasymbol_table/'TABID','TABLE','GETQ','GETY2'/ >*/
/* SOURCE ufgculv.for:4356 */
/*<       datagroup/char,char,char,char/ >*/
/* SOURCE ufgculv.for:4359 */
/*<       datagroup_index/1,2,3,4/ >*/
/* SOURCE ufgculv.for:4362 */
/*<       dataresponse_type/chrval,chrval,chrval,chrval/ >*/
/* SOURCE ufgculv.for:4365 */
/*<       dataconvert_rule/lower,lower,lower,lower/ >*/
/* SOURCE ufgculv.for:4371 */
/*<       callset_ufgc_tabids_defaults() >*/
    feq_gen_set_ufgc_tabids_defaults_d_();
/* SOURCE ufgculv.for:4373 */
/*<       max_line=1 >*/
    feq_gen_max_line_d_ = 1;
/* SOURCE ufgculv.for:4374 */
/*<        >*/
    feq_gen_get_named_items_d_(stdin, stdout, &feq_gen_max_line_d_, &feq_gen_c_d_4, group, 
	    feq_gen_response_type_d_, feq_gen_convert_rule_d_, feq_gen_group_index_d_, feq_gen_symbol_table_d_, &
	    feq_gen_c_d_1, &feq_gen_c_d_1, &feq_gen_c_d_4, const_cast<char*>("UFGCULV items"), feq_gen_ufgcitm_com_d_1.ufgcitmitab, 
	    feq_gen_ufgcitm_com_d_1.ufgcitmftab, feq_gen_ufgcitm_com_d_1.ufgcitmdtab, 
	    feq_gen_ufgcitm_comc_d_1.ufgcitmctab, eflag, (ftnlen)16, (ftnlen)13, (
	    ftnlen)64);
/* SOURCE ufgculv.for:4381 */
/*<       return >*/
    return 0;
/* SOURCE ufgculv.for:4383 */
/*<       end >*/
} /* get_ufgc_tabids__ */




/* SOURCE ufgculv.for:4387 */
/*<        >*/
/* Subroutine */ int feq_gen_read_barrel_items_d_(integer *stdout, char *line, integer 
	*nitem, integer *feq_gen_feq_storage_item_start_d_, integer *feq_gen_feq_storage_item_end_d_, integer *eflag, 
	integer *node, char *feq_gen_name_d_, integer *tabn, doublereal *stat, 
	doublereal *elev, ftnlen line_len, ftnlen name_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:XXX* Only \002,i3,\002 items given \
in \002,\002ufgculv-barrel description line.  Need at least five items.\002)";
    static char fmt_52[] = "(/,\002 *ERR:XXX* No interpolation allowed for a\
 culvert\002,\002 barrel for UFGCULV.\002)";
    static char fmt_54[] = "(/,\002 *ERR:XXX* Cross-section id missing for a\
 culvert\002,\002 barrel for UFGCULV.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_rsli(icilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_rsli(), s_cmp(char *, char *, ftnlen, ftnlen), s_rsfi(icilist *)
	    , e_rsfi(), s_wsle(cilist *), e_wsle();

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    integer n, ie, is;
    char tpc[20], key[16];
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__573 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__579 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__580 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__581 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__582 = { 0, 0, 0, 0, 0 };


/*     Get the items of data from a barrel input line in UFGCULV */
/* SOURCE ufgculv.for:4396 */
/*<       implicitnone >*/
/* SOURCE ufgculv.for:4397 */
/*<        >*/
/* SOURCE ufgculv.for:4400 */
/*<       real*8stat,elev >*/
/* SOURCE ufgculv.for:4402 */
/*<       characterline*80,name*8 >*/
/*     Local */
/* SOURCE ufgculv.for:4406 */
/*<       integerie,is,itab,lkey,n >*/
/* SOURCE ufgculv.for:4407 */
/*<       charactertpc*20,key*16 >*/
/*     Called program units */
/* SOURCE ufgculv.for:4410 */
/*<       externalstrip_l_blanks,get_internal_tab_number >*/
/*     ***********************FORMATS************************************ */
/* SOURCE ufgculv.for:4412 */
/*<    50  >*/
/* SOURCE ufgculv.for:4414 */
/*<    52  >*/
/* SOURCE ufgculv.for:4416 */
/*<    54  >*/
/* *********************************************************************** */
/* SOURCE ufgculv.for:4419 */
/*<       if(nitem.lt.5)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_item_end_d_(feq_gen_feq_storage_item_end_d_, 1);

    feq::IndexedPointer<integer> feq_gen_item_start_d_(feq_gen_feq_storage_item_start_d_, 1);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
    if (*nitem < 5) {
/* SOURCE ufgculv.for:4420 */
/*<       write(stdout,50)nitem >*/
	feq_gen_io_d__573.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__573);
	do_fio(&feq_gen_c_d_1, (char *)&(*nitem), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE ufgculv.for:4421 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE ufgculv.for:4422 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:4424 */
/*<       n=1 >*/
    n = 1;
/*     Process the NODE */
/* SOURCE ufgculv.for:4426 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE ufgculv.for:4427 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE ufgculv.for:4428 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE ufgculv.for:4429 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE ufgculv.for:4431 */
/*<       if(tpc(1:1).eq.' ')then >*/
    if (*(unsigned char *)tpc == ' ') {
/* SOURCE ufgculv.for:4432 */
/*<       node=0 >*/
	*node = 0;
/* SOURCE ufgculv.for:4433 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:4434 */
/*<       read(tpc,*)node >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 20;
	feq_gen_ici_d_1.iciunit = tpc;
	feq_gen_ici_d_1.icifmt = 0;
	s_rsli(&feq_gen_ici_d_1);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*node), (ftnlen)sizeof(integer));
	e_rsli();
/* SOURCE ufgculv.for:4435 */
/*<       endif >*/
    }
/* SOURCE ufgculv.for:4437 */
/*<       if(node.lt.0)return >*/
    if (*node < 0) {
	return 0;
    }
/*     Process the node id */
/* SOURCE ufgculv.for:4440 */
/*<       n=2 >*/
    n = 2;
/* SOURCE ufgculv.for:4441 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE ufgculv.for:4442 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE ufgculv.for:4443 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE ufgculv.for:4444 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE ufgculv.for:4446 */
/*<       name=tpc >*/
    s_copy(feq_gen_name_d_, tpc, (ftnlen)8, (ftnlen)20);
/*     Process the table id */
/* SOURCE ufgculv.for:4449 */
/*<       n=3 >*/
    n = 3;
/* SOURCE ufgculv.for:4450 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE ufgculv.for:4451 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE ufgculv.for:4452 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE ufgculv.for:4453 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE ufgculv.for:4455 */
/*<       key=tpc >*/
    s_copy(key, tpc, (ftnlen)16, (ftnlen)20);
/*     Convert from the table id to an internal number. */
/* SOURCE ufgculv.for:4457 */
/*<       if(key.ne.' ')then >*/
    if (s_cmp(key, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/* SOURCE ufgculv.for:4458 */
/*<       if(key(1:1).ne.'-')then >*/
	if (*(unsigned char *)key != '-') {
/*         We have an id given. */
/* SOURCE ufgculv.for:4460 */
/*<       callget_internal_tab_number(stdout,key,eflag,tabn) >*/
	    feq_gen_get_internal_tab_number_d_(stdout, key, eflag, tabn, (ftnlen)16);
/* SOURCE ufgculv.for:4465 */
/*<       else >*/
	} else {
/* SOURCE ufgculv.for:4466 */
/*<       write(stdout,52) >*/
	    feq_gen_io_d__579.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__579);
	    e_wsfe();
/* SOURCE ufgculv.for:4467 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE ufgculv.for:4468 */
/*<       endif >*/
	}
/* SOURCE ufgculv.for:4469 */
/*<       else >*/
    } else {
/* SOURCE ufgculv.for:4470 */
/*<       write(stdout,54) >*/
	feq_gen_io_d__580.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__580);
	e_wsfe();
/* SOURCE ufgculv.for:4471 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE ufgculv.for:4472 */
/*<       endif >*/
    }
/*     Process the station */
/* SOURCE ufgculv.for:4475 */
/*<       n=4 >*/
    n = 4;
/* SOURCE ufgculv.for:4476 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE ufgculv.for:4477 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE ufgculv.for:4478 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE ufgculv.for:4479 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE ufgculv.for:4481 */
/*<       read(tpc,'(F12.0)',err=991)stat >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 20;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F12.0)");
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&(*stat), (ftnlen)sizeof(doublereal));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/*     Process the invert elevation */
/* SOURCE ufgculv.for:4484 */
/*<       n=5 >*/
    n = 5;
/* SOURCE ufgculv.for:4485 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE ufgculv.for:4486 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE ufgculv.for:4487 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE ufgculv.for:4488 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE ufgculv.for:4490 */
/*<       read(tpc,'(F12.0)',err=991)elev >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 20;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F12.0)");
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&(*elev), (ftnlen)sizeof(doublereal));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ufgculv.for:4492 */
/*<       return >*/
    return 0;
/* SOURCE ufgculv.for:4493 */
/*<   991 continue >*/
L991:
/* SOURCE ufgculv.for:4494 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__581.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__581);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE ufgculv.for:4495 */
/*<       write(stdout,*)tpc >*/
    feq_gen_io_d__582.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__582);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, tpc, (ftnlen)20);
    e_wsle();
/* SOURCE ufgculv.for:4496 */
/*<       stop'Abnormal stop.  Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE ufgculv.for:4498 */
/*<       end >*/
    return 0;
} /* read_barrel_items__ */

#ifdef __cplusplus
	}
#endif
