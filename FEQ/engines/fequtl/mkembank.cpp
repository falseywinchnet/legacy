/* mkembank.f -- translated by f2c (version 20240504).
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

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_5 = 5;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_3 = 3;




/* SOURCE mkembank.for:4 */
/*<       subroutinereverse_in_place_d(x,n) >*/
/* Subroutine */ int feq_gen_reverse_in_place_d_d_(doublereal *feq_storage_x, integer *n)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_;
    doublereal t;
    integer ie, is;

/*     Reverse the elements of a vector in place. */
/* SOURCE mkembank.for:8 */
/*<       implicitnone >*/
/* SOURCE mkembank.for:9 */
/*<       integern >*/
/* SOURCE mkembank.for:10 */
/*<       real*8x(n) >*/
/*     Local */
/* SOURCE mkembank.for:13 */
/*<       integeri,is,ie >*/
/* SOURCE mkembank.for:14 */
/*<       real*8t >*/
/* *********************************************************************** */
/* SOURCE mkembank.for:16 */
/*<       do100i=1,n/2 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> x(feq_storage_x, 1);

    /* Function Body */
    feq_gen_i_d_1 = *n / 2;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE mkembank.for:17 */
/*<       is=i >*/
	is = feq_gen_i_d_;
/* SOURCE mkembank.for:18 */
/*<       ie=n+1-i >*/
	ie = *n + 1 - feq_gen_i_d_;
/* SOURCE mkembank.for:19 */
/*<       t=x(is) >*/
	t = x[is];
/* SOURCE mkembank.for:20 */
/*<       x(is)=x(ie) >*/
	x[is] = x[ie];
/* SOURCE mkembank.for:21 */
/*<       x(ie)=t >*/
	x[ie] = t;
/* SOURCE mkembank.for:22 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE mkembank.for:23 */
/*<       return >*/
    return 0;
/* SOURCE mkembank.for:24 */
/*<       end >*/
} /* reverse_in_place_d__ */




/* SOURCE mkembank.for:29 */
/*<       subroutineintersect(ai,bi,ci,aj,bj,cj,status,xs,ys) >*/
/* Subroutine */ int intersect_(doublereal *ai, doublereal *bi, doublereal *
	ci, doublereal *aj, doublereal *bj, doublereal *cj, char *status, 
	doublereal *xs, doublereal *ys, ftnlen status_len)
{
    /* System generated locals */
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    doublereal feq_gen_d_d_, pdi, pdj, div, tpa, tpb, dist;

/*     Find the intersection between two lines in a plane */
/* SOURCE mkembank.for:34 */
/*<       implicitnone >*/
/* SOURCE mkembank.for:35 */
/*<       characterstatus*5 >*/
/* SOURCE mkembank.for:37 */
/*<       real*8ai,bi,ci,aj,bj,cj,xs,ys >*/
/*     Local */
/* SOURCE mkembank.for:41 */
/*<       real*8d,tpa,tpb,div,dist,pdi,pdj >*/
/* *********************************************************************** */
/*     The lines will intersect, be parallel, or be coincident */
/*     (a degenerate case of being parallel). */
/* SOURCE mkembank.for:46 */
/*<       tpa=ai*bj >*/
    tpa = *ai * *bj;
/* SOURCE mkembank.for:47 */
/*<       tpb=aj*bi >*/
    tpb = *aj * *bi;
/* SOURCE mkembank.for:48 */
/*<       div=max(abs(tpa),abs(tpb),1.0d0) >*/
/* Computing MAX */
    feq_gen_d_d_1 = abs(tpa), feq_gen_d_d_2 = abs(tpb), feq_gen_d_d_1 = max(feq_gen_d_d_1,feq_gen_d_d_2);
    div = max(feq_gen_d_d_1,1.);
/* SOURCE mkembank.for:49 */
/*<       d=tpa-tpb >*/
    feq_gen_d_d_ = tpa - tpb;
/* SOURCE mkembank.for:51 */
/*<       if(abs(d)/div.le.1.d-12)then >*/
    if (abs(feq_gen_d_d_) / div <= 1e-12) {
/*       Treat the lines as parallel.   Check for near coincidence. */
/*       Compute the perpendicular distance from the origin to */
/*       each line and compare.  If the distances are nearly equal, */
/*       the lines are coincident. */
/* SOURCE mkembank.for:57 */
/*<       status='PAR' >*/
	s_copy(status, const_cast<char*>("PAR"), (ftnlen)5, (ftnlen)3);
/* SOURCE mkembank.for:58 */
/*<       pdi=abs(ci)/sqrt(ai**2+bi**2) >*/
/* Computing 2nd power */
	feq_gen_d_d_1 = *ai;
/* Computing 2nd power */
	feq_gen_d_d_2 = *bi;
	pdi = abs(*ci) / sqrt(feq_gen_d_d_1 * feq_gen_d_d_1 + feq_gen_d_d_2 * feq_gen_d_d_2);
/* SOURCE mkembank.for:59 */
/*<       pdj=abs(cj)/sqrt(aj**2+bj**2) >*/
/* Computing 2nd power */
	feq_gen_d_d_1 = *aj;
/* Computing 2nd power */
	feq_gen_d_d_2 = *bj;
	pdj = abs(*cj) / sqrt(feq_gen_d_d_1 * feq_gen_d_d_1 + feq_gen_d_d_2 * feq_gen_d_d_2);
/* SOURCE mkembank.for:60 */
/*<       dist=abs(pdi-pdj) >*/
	dist = (feq_gen_d_d_1 = pdi - pdj, abs(feq_gen_d_d_1));
/* SOURCE mkembank.for:62 */
/*<       if(dist/pdi.le.1.e-10)then >*/
	if (dist / pdi <= (float)1e-10) {
/* SOURCE mkembank.for:63 */
/*<       status='SAME' >*/
	    s_copy(status, const_cast<char*>("SAME"), (ftnlen)5, (ftnlen)4);
/* SOURCE mkembank.for:64 */
/*<       endif >*/
	}
/* SOURCE mkembank.for:65 */
/*<       else >*/
    } else {
/*       Compute the intersection point */
/* SOURCE mkembank.for:68 */
/*<       status='CROSS' >*/
	s_copy(status, const_cast<char*>("CROSS"), (ftnlen)5, (ftnlen)5);
/* SOURCE mkembank.for:69 */
/*<       xs=(-ci*bj+cj*bi)/d >*/
	*xs = (-(*ci) * *bj + *cj * *bi) / feq_gen_d_d_;
/* SOURCE mkembank.for:70 */
/*<       ys=(-ai*cj+aj*ci)/d >*/
	*ys = (-(*ai) * *cj + *aj * *ci) / feq_gen_d_d_;
/* SOURCE mkembank.for:71 */
/*<       endif >*/
    }
/* SOURCE mkembank.for:72 */
/*<       return >*/
    return 0;
/* SOURCE mkembank.for:73 */
/*<       end >*/
} /* intersect_ */




/* SOURCE mkembank.for:77 */
/*<        >*/
/* Subroutine */ int feq_gen_find_intersect_d_(doublereal *feq_storage_xa, doublereal *feq_storage_ya, 
	doublereal *feq_storage_za, doublereal *feq_storage_aa, doublereal *feq_storage_ba, doublereal *feq_storage_ca, 
	integer *na, doublereal *a, doublereal *b, doublereal *feq_gen_c_d_, 
	doublereal *feq_storage_xll, doublereal *feq_storage_yll, doublereal *feq_storage_xur, doublereal *feq_storage_yur, 
	doublereal *xs, doublereal *ys, doublereal *zs, integer *feq_gen_flag_d_)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    doublereal feq_gen_d_d_;
    integer feq_gen_i_d_;
    extern /* Subroutine */ int intersect_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, char *, 
	    doublereal *, doublereal *, ftnlen);
    doublereal dist;
    char status[5];

/*     Find the point of intersection between the approach trace polyline */
/*     and the line given  by (A, B, C) */
/* SOURCE mkembank.for:83 */
/*<       implicitnone >*/
/* INCLUDE mkembank.for:85 */
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
/* SOURCE mkembank.for:86 */
/*<       integerna,flag >*/
/* SOURCE mkembank.for:87 */
/*<        >*/
/*     Called program units */
/* SOURCE mkembank.for:92 */
/*<       externalintersect >*/
/*     Local */
/* SOURCE mkembank.for:95 */
/*<       integeri >*/
/* SOURCE mkembank.for:97 */
/*<       real*8d,dist >*/
/* SOURCE mkembank.for:99 */
/*<       characterstatus*5 >*/
/* *********************************************************************** */
/*     Check each line segment until we find an intersection within one. */
/* SOURCE mkembank.for:103 */
/*<       do100i=1,na-1 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<doublereal> yur(feq_storage_yur, 1);

    feq::IndexedPointer<doublereal> xur(feq_storage_xur, 1);

    feq::IndexedPointer<doublereal> yll(feq_storage_yll, 1);

    feq::IndexedPointer<doublereal> xll(feq_storage_xll, 1);

    feq::IndexedPointer<doublereal> ca(feq_storage_ca, 1);

    feq::IndexedPointer<doublereal> ba(feq_storage_ba, 1);

    feq::IndexedPointer<doublereal> aa(feq_storage_aa, 1);

    feq::IndexedPointer<doublereal> za(feq_storage_za, 1);

    feq::IndexedPointer<doublereal> ya(feq_storage_ya, 1);

    feq::IndexedPointer<doublereal> xa(feq_storage_xa, 1);

    /* Function Body */
    feq_gen_i_d_1 = *na - 1;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*        WRITE(STD6,*) ' ' */
/*        WRITE(STD6,*) ' I=',I */
/*        WRITE(STD6,50) A, B, C */
/* 50    FORMAT(' A=',F15.3,' B=',F15.3,' C=',F15.3) */
/*        WRITE(STD6,52) AA(I), BA(I), CA(I) */
/* 52    FORMAT(' AA=',F15.3,' BA=',F15.3,' CA=',F15.3) */
/* SOURCE mkembank.for:111 */
/*<       callintersect(a,b,c,aa(i),ba(i),ca(i),status,xs,ys) >*/
	intersect_(a, b, feq_gen_c_d_, &aa[feq_gen_i_d_], &ba[feq_gen_i_d_], &ca[feq_gen_i_d_], status, xs, ys, (
		ftnlen)5);
/* SOURCE mkembank.for:113 */
/*<       if(status.eq.'CROSS')then >*/
	if (s_cmp(status, const_cast<char*>("CROSS"), (ftnlen)5, (ftnlen)5) == 0) {
/*         Check if it crosses within the line segment. */
/*          WRITE(STD6,54) XS, YS */
/* 54    FORMAT(' XS=',F15.2,' YS=',F15.2) */
/* SOURCE mkembank.for:119 */
/*<        >*/
	    if (*xs <= xur[feq_gen_i_d_] && *xs >= xll[feq_gen_i_d_] && *ys <= yur[feq_gen_i_d_] && *ys 
		    >= yll[feq_gen_i_d_]) {
/*           Find the elevation at this point. */
/* SOURCE mkembank.for:122 */
/*<       d=sqrt((xs-xa(i))**2+(ys-ya(i))**2) >*/
/* Computing 2nd power */
		feq_gen_d_d_1 = *xs - xa[feq_gen_i_d_];
/* Computing 2nd power */
		feq_gen_d_d_2 = *ys - ya[feq_gen_i_d_];
		feq_gen_d_d_ = sqrt(feq_gen_d_d_1 * feq_gen_d_d_1 + feq_gen_d_d_2 * feq_gen_d_d_2);
/* SOURCE mkembank.for:123 */
/*<       dist=sqrt((xa(i+1)-xa(i))**2+(ya(i+1)-ya(i))**2) >*/
/* Computing 2nd power */
		feq_gen_d_d_1 = xa[feq_gen_i_d_ + 1] - xa[feq_gen_i_d_];
/* Computing 2nd power */
		feq_gen_d_d_2 = ya[feq_gen_i_d_ + 1] - ya[feq_gen_i_d_];
		dist = sqrt(feq_gen_d_d_1 * feq_gen_d_d_1 + feq_gen_d_d_2 * feq_gen_d_d_2);
/* SOURCE mkembank.for:124 */
/*<       zs=za(i)+d*(za(i+1)-za(i))/dist >*/
		*zs = za[feq_gen_i_d_] + feq_gen_d_d_ * (za[feq_gen_i_d_ + 1] - za[feq_gen_i_d_]) / dist;
/* SOURCE mkembank.for:125 */
/*<       flag=1 >*/
		*feq_gen_flag_d_ = 1;
/* SOURCE mkembank.for:126 */
/*<       return >*/
		return 0;
/* SOURCE mkembank.for:127 */
/*<       endif >*/
	    }
/* SOURCE mkembank.for:128 */
/*<       endif >*/
	}
/* SOURCE mkembank.for:129 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE mkembank.for:130 */
/*<       flag=0 >*/
    *feq_gen_flag_d_ = 0;
/* SOURCE mkembank.for:131 */
/*<       return >*/
    return 0;
/* SOURCE mkembank.for:133 */
/*<       end >*/
} /* find_intersect__ */




/* SOURCE mkembank.for:139 */
/*<       subroutinemkembank(stdin,stdout,eflag) >*/
/* Subroutine */ int mkembank_(integer *stdin, integer *stdout, integer *
	eflag)
{
    /* Initialized data */

    static doublereal eps = .001;

    /* Format strings */
    static char fmt_50[] = "(/,\002 WIDTH=\002,f10.2)";
    static char fmt_51[] = "(/,\002 Minimum weir height=\002,f10.3)";
    static char fmt_52[] = "(/,\002 SURFACE=\002,a8)";
    static char fmt_54[] = "(/,\002 *ERR:772* Line:\002,a,/,11x,\002 is unkn\
own in MKEMBANK.\002)";
    static char fmt_55[] = "(/,\002 SHIFT=\002,f10.3)";
    static char fmt_56[] = "(/,\002 *ERR:773* No approach trace intersection\
 at X=\002,f12.2,\002 Y=\002,f12.2)";
    static char fmt_58[] = "(\002    OFFSET     CREST     WIDTH  APPROACH SU\
RFACE\002)";
    static char fmt_60[] = "(f10.1,f10.3,f10.2,f10.2,1x,a8,5x,\002'\002,a)";
    static char fmt_61[] = "(\002App. surface <\002,f5.2,\002 below crest. S\
hifted \002,f5.2,\002 down.\002)";
    static char fmt_62[] = "(f10.1,f10.3,f10.1,\002 -99999.0 \002,1x,a8)";
    static char fmt_64[] = "(\002  Processing MKEMBANK\002)";
    static char fmt_65[] = "(\002ZONE=\002,a8,\002 HGRID=\002,a8,\002 VDAT\
UM=\002,a8,\002 UNITSYS=\002,a8,\002 BASIS=\002,a8,/,\002EASTING=\002,0pf15.\
3,\002 NORTHING=\002,f15.3)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;
    alist feq_gen_al_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(), s_cmp(char *, char *, ftnlen, ftnlen),
	     s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(), 
	    f_back(alist *), i_indx(char *, char *, ftnlen, ftnlen), s_rsli(
	    icilist *), do_lio(integer *, integer *, char *, ftnlen), e_rsli()
	    , s_wsle(cilist *), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfi(icilist *), e_wsfi();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    doublereal northing, a, b, feq_gen_c_d_;
    integer feq_gen_i_d_;
    doublereal s, x, y, feq_gen_z_d_, aa[1000], ba[1000], ca[1000];
    integer na, nc;
    doublereal ap, bp, cp, xa[1000], ya[1000], xc[1000], yc[1000], zc[1000], 
	    za[1000], wh, zl, xs, ys, zs, zr;
    extern /* Subroutine */ int feq_gen_reverse_in_place_d_d_(doublereal *, integer *),
	     feq_gen_find_perpendicular_d_(doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *);
    doublereal xll[1000], yll[1000], xur[1000], yur[1000];
    integer feq_gen_flag_d_;
    char line[80], note[80], zone[8];
    doublereal zmin;
    char hgrid[8], basis[8];
    real width;
    doublereal shift, minwh;
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen),
	     feq_gen_find_line_coef_d_(doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *);
    char vdatum[8];
    extern /* Subroutine */ int feq_gen_get_lctn_items_d_(integer *, integer *, 
	    integer *), feq_gen_find_intersect_d_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *), feq_gen_strip_l_blanks_d_(char *, 
	    ftnlen), feq_gen_set_lctn_items_d_(char *, char *, char *, char *, char *, 
	    doublereal *, doublereal *, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen);
    char surface[8];
    doublereal easting;
    integer reverse;
    doublereal xatzmin, yatzmin;
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__17 = { 0, 6, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__27 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__29 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__31 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__33 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__46 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__50 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__62 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__63 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__64 = { 0, 0, 0, fmt_65, 0 };
    static cilist feq_gen_io_d__65 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__76 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__79 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__80 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__81 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__82 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__83 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__84 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__85 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__86 = { 0, 0, 0, fmt_62, 0 };


/*     Reads an X, Y, Z trace for the crest of an overflow weir */
/*     and an optional trace for the approach surface upstream of the */
/*     weir and produces the properly formated embankment crest */
/*     definition for the EMBANKQ and CULVERT commands.  The weir */
/*     table references are not supplied and must be added by the */
/*     user. */
/* SOURCE mkembank.for:148 */
/*<       implicitnone >*/
/* SOURCE mkembank.for:149 */
/*<       integereflag,stdin,stdout >*/
/* INCLUDE mkembank.for:151 */
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
/*     Called program units */
/* SOURCE mkembank.for:154 */
/*<       externalinline,strip_l_blanks >*/
/*     Local variables. */
/* SOURCE mkembank.for:158 */
/*<       integernc,na,i,flag,reverse >*/
/* SOURCE mkembank.for:160 */
/*<       character*8zone,hgrid,vdatum,unitsys,basis >*/
/* SOURCE mkembank.for:161 */
/*<       realwidth >*/
/* SOURCE mkembank.for:162 */
/*<       real*8easting,northing,shift,zmin,xatzmin,yatzmin >*/
/*     XC, YC, and ZC give the trace of the crest and XA, YA, and ZA give */
/*     the trace for the approach.  The X and Y are in the horizontal plane */
/*     and Z is in the vertical. */
/*     We need to designate 2 different lines: */
/*     5. The line that is perpendicular to a line at a point. AP, BP, CP */
/*     6. A generic line.  A, B, C */
/* SOURCE mkembank.for:171 */
/*<        >*/
/* SOURCE mkembank.for:178 */
/*<       characterline*80,surface*8,note*80 >*/
/*     *****************************FORMATS****************************** */
/* SOURCE mkembank.for:180 */
/*<       dataeps/1.d-3/ >*/
/* SOURCE mkembank.for:182 */
/*<    50 format(/,' WIDTH=',f10.2) >*/
/* L50: */
/* SOURCE mkembank.for:183 */
/*<    51 format(/,' Minimum weir height=',f10.3) >*/
/* L51: */
/* SOURCE mkembank.for:184 */
/*<    52 format(/,' SURFACE=',a8) >*/
/* L52: */
/* SOURCE mkembank.for:185 */
/*<    54 format(/,' *ERR:772* Line:',a,/,11x,' is unknown in MKEMBANK.') >*/
/* L54: */
/* SOURCE mkembank.for:186 */
/*<    55 format(/,' SHIFT=',f10.3) >*/
/* L55: */
/* SOURCE mkembank.for:187 */
/*<    56  >*/
/* L56: */
/* SOURCE mkembank.for:189 */
/*<    58 format('    OFFSET     CREST     WIDTH  APPROACH SURFACE') >*/
/* L58: */
/* SOURCE mkembank.for:190 */
/*<    60 format(f10.1,f10.3,f10.2,f10.2,1x,a8,5x,'''',a) >*/
/* L60: */
/* SOURCE mkembank.for:191 */
/*<    61  >*/
/* L61: */
/* SOURCE mkembank.for:193 */
/*<    62 format(f10.1,f10.3,f10.1,' -99999.0 ',1x,a8) >*/
/* L62: */
/* SOURCE mkembank.for:194 */
/*<    64 format('  Processing MKEMBANK') >*/
/* L64: */
/* SOURCE mkembank.for:195 */
/*<    65  >*/
/* L65: */
/* *********************************************************************** */
/* SOURCE mkembank.for:200 */
/*<       write(*,64) >*/
    s_wsfe(&feq_gen_io_d__17);
    e_wsfe();
/* SOURCE mkembank.for:202 */
/*<       callget_lctn_items(stdin,stdout,eflag) >*/
    feq_gen_get_lctn_items_d_(stdin, stdout, eflag);
/* SOURCE mkembank.for:204 */
/*<        >*/
    feq_gen_set_lctn_items_d_(zone, hgrid, vdatum, unitsys, basis, &easting, &northing,
	     (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE mkembank.for:209 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE mkembank.for:212 */
/*<       shift=0.0 >*/
    shift = (float)0.;
/* SOURCE mkembank.for:213 */
/*<       if(line(1:5)=='SHIFT')then >*/
    if (s_cmp(line, const_cast<char*>("SHIFT"), (ftnlen)5, (ftnlen)5) == 0) {
/* SOURCE mkembank.for:214 */
/*<       read(line,'(6x,f10.0)')shift >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(6x,f10.0)");
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&shift, (ftnlen)sizeof(doublereal));
	e_rsfi();
/* SOURCE mkembank.for:215 */
/*<       else >*/
    } else {
/* SOURCE mkembank.for:216 */
/*<       backspace(stdin) >*/
	feq_gen_al_d_1.aerr = 0;
	feq_gen_al_d_1.aunit = *stdin;
	f_back(&feq_gen_al_d_1);
/* SOURCE mkembank.for:217 */
/*<       endif >*/
    }
/* SOURCE mkembank.for:219 */
/*<       write(stdout,55)shift >*/
    feq_gen_io_d__27.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__27);
    do_fio(&feq_gen_c_d_1, (char *)&shift, (ftnlen)sizeof(doublereal));
    e_wsfe();
/*     Input the constant width for the weir crest.  May add option for */
/*     varying width later */
/* SOURCE mkembank.for:223 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE mkembank.for:226 */
/*<       read(line,'(6X,F10.0)')width >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(6X,F10.0)");
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&width, (ftnlen)sizeof(real));
    e_rsfi();
/* SOURCE mkembank.for:227 */
/*<       write(stdout,50)width >*/
    feq_gen_io_d__29.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__29);
    do_fio(&feq_gen_c_d_1, (char *)&width, (ftnlen)sizeof(real));
    e_wsfe();
/*     Input the minimum weir height.  This will be imposed */
/*     with a message as to how much the approach surface was depressed to */
/*     attain it. */
/* SOURCE mkembank.for:233 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE mkembank.for:236 */
/*<       if(line(1:7).eq.'SURFACE')then >*/
    if (s_cmp(line, const_cast<char*>("SURFACE"), (ftnlen)7, (ftnlen)7) == 0) {
/*       User has not given a minimum weir height. */
/* SOURCE mkembank.for:238 */
/*<       minwh=0.0 >*/
	minwh = (float)0.;
/* SOURCE mkembank.for:239 */
/*<       backspace(stdin) >*/
	feq_gen_al_d_1.aerr = 0;
	feq_gen_al_d_1.aunit = *stdin;
	f_back(&feq_gen_al_d_1);
/* SOURCE mkembank.for:240 */
/*<       else >*/
    } else {
/* SOURCE mkembank.for:241 */
/*<       read(line,'(10X,F10.0)')minwh >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(10X,F10.0)");
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&minwh, (ftnlen)sizeof(doublereal));
	e_rsfi();
/* SOURCE mkembank.for:242 */
/*<       if(minwh.lt.0.0)minwh=0.0 >*/
	if (minwh < (float)0.) {
	    minwh = (float)0.;
	}
/* SOURCE mkembank.for:243 */
/*<       endif >*/
    }
/* SOURCE mkembank.for:244 */
/*<       write(stdout,51)minwh >*/
    feq_gen_io_d__31.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__31);
    do_fio(&feq_gen_c_d_1, (char *)&minwh, (ftnlen)sizeof(doublereal));
    e_wsfe();
/*     Input the constant surface type.  Two types: PAVED, or  GRAVEL */
/* SOURCE mkembank.for:248 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE mkembank.for:251 */
/*<       read(line,'(8X,A8)')surface >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(8X,A8)");
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, surface, (ftnlen)8);
    e_rsfi();
/* SOURCE mkembank.for:252 */
/*<       callstrip_l_blanks(surface) >*/
    feq_gen_strip_l_blanks_d_(surface, (ftnlen)8);
/* SOURCE mkembank.for:254 */
/*<       write(stdout,52)surface >*/
    feq_gen_io_d__33.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__33);
    do_fio(&feq_gen_c_d_1, surface, (ftnlen)8);
    e_wsfe();
/*     Now get the points on the crest of the weir. */
/* SOURCE mkembank.for:258 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE mkembank.for:262 */
/*<       write(stdout,'(/,A)')line >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(/,A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
    e_wsfe();
/*     Test for need to reverse */
/* SOURCE mkembank.for:264 */
/*<       reverse=index(line,'REVERSE') >*/
    reverse = i_indx(line, const_cast<char*>("REVERSE"), (ftnlen)80, (ftnlen)7);
/* SOURCE mkembank.for:266 */
/*<       nc=0 >*/
    nc = 0;
/* SOURCE mkembank.for:267 */
/*<       na=0 >*/
    na = 0;
/* SOURCE mkembank.for:268 */
/*<       zmin=1.d50 >*/
    zmin = 1e50;
/* SOURCE mkembank.for:269 */
/*<   100 continue >*/
L100:
/* SOURCE mkembank.for:270 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE mkembank.for:273 */
/*<       if(line(1:3).ne.'END')then >*/
    if (s_cmp(line, const_cast<char*>("END"), (ftnlen)3, (ftnlen)3) != 0) {
/* SOURCE mkembank.for:274 */
/*<       read(line,*)x,y,z >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = 0;
	s_rsli(&feq_gen_ici_d_1);
	do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(doublereal));
	do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(doublereal));
	do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&feq_gen_z_d_, (ftnlen)sizeof(doublereal));
	e_rsli();
/* SOURCE mkembank.for:275 */
/*<       nc=nc+1 >*/
	++nc;
/* SOURCE mkembank.for:276 */
/*<       xc(nc)=x >*/
	xc[nc - 1] = x;
/* SOURCE mkembank.for:277 */
/*<       yc(nc)=y >*/
	yc[nc - 1] = y;
/* SOURCE mkembank.for:278 */
/*<       zc(nc)=z+shift >*/
	zc[nc - 1] = feq_gen_z_d_ + shift;
/* SOURCE mkembank.for:279 */
/*<       if(zc(nc)<zmin)then >*/
	if (zc[nc - 1] < zmin) {
/* SOURCE mkembank.for:280 */
/*<       zmin=zc(nc) >*/
	    zmin = zc[nc - 1];
/* SOURCE mkembank.for:281 */
/*<       xatzmin=xc(nc) >*/
	    xatzmin = xc[nc - 1];
/* SOURCE mkembank.for:282 */
/*<       yatzmin=yc(nc) >*/
	    yatzmin = yc[nc - 1];
/* SOURCE mkembank.for:283 */
/*<       endif >*/
	}
/* SOURCE mkembank.for:284 */
/*<       goto100 >*/
	goto L100;
/* SOURCE mkembank.for:285 */
/*<       endif >*/
    }
/* SOURCE mkembank.for:286 */
/*<       easting=xatzmin >*/
    easting = xatzmin;
/* SOURCE mkembank.for:287 */
/*<       northing=yatzmin >*/
    northing = yatzmin;
/*       Check on reversing the order of the points on the crest trace */
/* SOURCE mkembank.for:289 */
/*<       if(reverse.gt.0)then >*/
    if (reverse > 0) {
/* SOURCE mkembank.for:290 */
/*<       write(stdout,*)' REVERSING CREST TRACE. NC=',nc >*/
	feq_gen_io_d__46.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__46);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" REVERSING CREST TRACE. NC="), (ftnlen)27);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&nc, (ftnlen)sizeof(integer));
	e_wsle();
/* SOURCE mkembank.for:291 */
/*<       callreverse_in_place_d(xc,nc) >*/
	feq_gen_reverse_in_place_d_d_(xc, &nc);
/* SOURCE mkembank.for:292 */
/*<       callreverse_in_place_d(yc,nc) >*/
	feq_gen_reverse_in_place_d_d_(yc, &nc);
/* SOURCE mkembank.for:293 */
/*<       callreverse_in_place_d(zc,nc) >*/
	feq_gen_reverse_in_place_d_d_(zc, &nc);
/* SOURCE mkembank.for:294 */
/*<       endif >*/
    }
/*     Get the next line of input.  Check for action to take. */
/* SOURCE mkembank.for:297 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE mkembank.for:300 */
/*<       write(stdout,'(/,A)')line >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(/,A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
    e_wsfe();
/* SOURCE mkembank.for:301 */
/*<       if(line(1:8).eq.'APPROACH')then >*/
    if (s_cmp(line, const_cast<char*>("APPROACH"), (ftnlen)8, (ftnlen)8) == 0) {
/*       Test for need to reverse */
/* SOURCE mkembank.for:303 */
/*<       reverse=index(line,'REVERSE') >*/
	reverse = i_indx(line, const_cast<char*>("REVERSE"), (ftnlen)80, (ftnlen)7);
/*       Read the approach trace.  We assume it extends beyond the end of the */
/*       crest trace so that we can find the proper point for computing the */
/*       approach elevation. */
/* SOURCE mkembank.for:308 */
/*<   110 continue >*/
L110:
/* SOURCE mkembank.for:309 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE mkembank.for:312 */
/*<       if(line(1:3).ne.'END')then >*/
	if (s_cmp(line, const_cast<char*>("END"), (ftnlen)3, (ftnlen)3) != 0) {
/* SOURCE mkembank.for:313 */
/*<       read(line,*)x,y,z >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 80;
	    feq_gen_ici_d_1.iciunit = line;
	    feq_gen_ici_d_1.icifmt = 0;
	    s_rsli(&feq_gen_ici_d_1);
	    do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(doublereal));
	    do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(doublereal));
	    do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&feq_gen_z_d_, (ftnlen)sizeof(doublereal));
	    e_rsli();
/* SOURCE mkembank.for:314 */
/*<       na=na+1 >*/
	    ++na;
/* SOURCE mkembank.for:315 */
/*<       xa(na)=x >*/
	    xa[na - 1] = x;
/* SOURCE mkembank.for:316 */
/*<       ya(na)=y >*/
	    ya[na - 1] = y;
/* SOURCE mkembank.for:317 */
/*<       za(na)=z+shift >*/
	    za[na - 1] = feq_gen_z_d_ + shift;
/* SOURCE mkembank.for:318 */
/*<       goto110 >*/
	    goto L110;
/* SOURCE mkembank.for:319 */
/*<       endif >*/
	}
/*       Check on reversing the order of the points on the approach trace */
/* SOURCE mkembank.for:322 */
/*<       if(reverse.gt.0)then >*/
	if (reverse > 0) {
/* SOURCE mkembank.for:323 */
/*<       write(stdout,*)' REVERSING APPROACH TRACE. NA=',na >*/
	    feq_gen_io_d__50.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__50);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" REVERSING APPROACH TRACE. NA="), (ftnlen)30)
		    ;
	    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&na, (ftnlen)sizeof(integer));
	    e_wsle();
/* SOURCE mkembank.for:324 */
/*<       callreverse_in_place_d(xa,na) >*/
	    feq_gen_reverse_in_place_d_d_(xa, &na);
/* SOURCE mkembank.for:325 */
/*<       callreverse_in_place_d(ya,na) >*/
	    feq_gen_reverse_in_place_d_d_(ya, &na);
/* SOURCE mkembank.for:326 */
/*<       callreverse_in_place_d(za,na) >*/
	    feq_gen_reverse_in_place_d_d_(za, &na);
/* SOURCE mkembank.for:327 */
/*<       endif >*/
	}
/*       Read the final END */
/* SOURCE mkembank.for:330 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/*       Set the windows for each line segment and find the */
/*       coefficients for the line through each line segment. */
/* SOURCE mkembank.for:336 */
/*<       do120i=1,na-1 >*/
	feq_gen_i_d_1 = na - 1;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE mkembank.for:337 */
/*<       xll(i)=min(xa(i),xa(i+1))-eps >*/
/* Computing MIN */
	    feq_gen_d_d_1 = xa[feq_gen_i_d_ - 1], feq_gen_d_d_2 = xa[feq_gen_i_d_];
	    xll[feq_gen_i_d_ - 1] = min(feq_gen_d_d_1,feq_gen_d_d_2) - eps;
/* SOURCE mkembank.for:338 */
/*<       yll(i)=min(ya(i),ya(i+1))-eps >*/
/* Computing MIN */
	    feq_gen_d_d_1 = ya[feq_gen_i_d_ - 1], feq_gen_d_d_2 = ya[feq_gen_i_d_];
	    yll[feq_gen_i_d_ - 1] = min(feq_gen_d_d_1,feq_gen_d_d_2) - eps;
/* SOURCE mkembank.for:339 */
/*<       xur(i)=max(xa(i),xa(i+1))+eps >*/
/* Computing MAX */
	    feq_gen_d_d_1 = xa[feq_gen_i_d_ - 1], feq_gen_d_d_2 = xa[feq_gen_i_d_];
	    xur[feq_gen_i_d_ - 1] = max(feq_gen_d_d_1,feq_gen_d_d_2) + eps;
/* SOURCE mkembank.for:340 */
/*<       yur(i)=max(ya(i),ya(i+1))+eps >*/
/* Computing MAX */
	    feq_gen_d_d_1 = ya[feq_gen_i_d_ - 1], feq_gen_d_d_2 = ya[feq_gen_i_d_];
	    yur[feq_gen_i_d_ - 1] = max(feq_gen_d_d_1,feq_gen_d_d_2) + eps;
/* SOURCE mkembank.for:341 */
/*<       callfind_line_coef(xa(i),ya(i),xa(i+1),ya(i+1),a,b,c) >*/
	    feq_gen_find_line_coef_d_(&xa[feq_gen_i_d_ - 1], &ya[feq_gen_i_d_ - 1], &xa[feq_gen_i_d_], &ya[feq_gen_i_d_], &
		    a, &b, &feq_gen_c_d_);
/* SOURCE mkembank.for:343 */
/*<       aa(i)=a >*/
	    aa[feq_gen_i_d_ - 1] = a;
/* SOURCE mkembank.for:344 */
/*<       ba(i)=b >*/
	    ba[feq_gen_i_d_ - 1] = b;
/* SOURCE mkembank.for:345 */
/*<       ca(i)=c >*/
	    ca[feq_gen_i_d_ - 1] = feq_gen_c_d_;
/* SOURCE mkembank.for:346 */
/*<   120 continue >*/
/* L120: */
	}
/* SOURCE mkembank.for:348 */
/*<       elseif(line(1:3).eq.'END')then >*/
    } else if (s_cmp(line, const_cast<char*>("END"), (ftnlen)3, (ftnlen)3) == 0) {
/*       No approach trace given.  Approach elevation will be set to */
/*       a large negative value to produce a neglibible velocity of */
/*       approach */
/* SOURCE mkembank.for:352 */
/*<       else >*/
    } else {
/* SOURCE mkembank.for:353 */
/*<       write(stdout,54)line >*/
	feq_gen_io_d__62.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__62);
	do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
	e_wsfe();
/* SOURCE mkembank.for:354 */
/*<       stop'Abnormal stop.  Error found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Error found."), (ftnlen)28);
/* SOURCE mkembank.for:355 */
/*<       endif >*/
    }
/* SOURCE mkembank.for:357 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__63.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__63);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE mkembank.for:358 */
/*<       if(zone/='NONE')then >*/
    if (s_cmp(zone, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4) != 0) {
/* SOURCE mkembank.for:359 */
/*<       write(stdout,65)zone,hgrid,vdatum,unitsys,basis,easting,northing >*/
	feq_gen_io_d__64.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__64);
	do_fio(&feq_gen_c_d_1, zone, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, hgrid, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, vdatum, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, unitsys, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, basis, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&easting, (ftnlen)sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, (char *)&northing, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* SOURCE mkembank.for:361 */
/*<       endif >*/
    }
/* SOURCE mkembank.for:363 */
/*<       write(stdout,58) >*/
    feq_gen_io_d__65.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__65);
    e_wsfe();
/*     The basic data is now available. */
/* SOURCE mkembank.for:366 */
/*<       if(na.gt.0)then >*/
    if (na > 0) {
/*       The approach trace is given. */
/* SOURCE mkembank.for:369 */
/*<       zl=-1.d0 >*/
	zl = -1.;
/* SOURCE mkembank.for:370 */
/*<       zr=-1.d0 >*/
	zr = -1.;
/* SOURCE mkembank.for:371 */
/*<       zs=-1.d0 >*/
	zs = -1.;
/* SOURCE mkembank.for:372 */
/*<       s=0.d0 >*/
	s = 0.;
/*       At the end points of the crest trace find the elevation */
/*       in the approach trace where the perpendicular to the */
/*       crest trace intersects the  approach trace. */
/*       Find the coef for the line through the first two points on */
/*       the crest trace. */
/* SOURCE mkembank.for:379 */
/*<       callfind_line_coef(xc(1),yc(1),xc(2),yc(2),a,b,c) >*/
	feq_gen_find_line_coef_d_(xc, yc, &xc[1], &yc[1], &a, &b, &feq_gen_c_d_);
/*       Find the line perpendicular to the line (A, B, C) and passing */
/*       through point ( XC(1), YC(1) ) */
/* SOURCE mkembank.for:384 */
/*<       callfind_perpendicular(xc(1),yc(1),a,b,c,ap,bp,cp) >*/
	feq_gen_find_perpendicular_d_(xc, yc, &a, &b, &feq_gen_c_d_, &ap, &bp, &cp);
/* SOURCE mkembank.for:386 */
/*<        >*/
	feq_gen_find_intersect_d_(xa, ya, za, aa, ba, ca, &na, &ap, &bp, &cp, xll, yll,
		 xur, yur, &xs, &ys, &zs, &feq_gen_flag_d_);
/* SOURCE mkembank.for:389 */
/*<       if(flag.eq.0)then >*/
	if (feq_gen_flag_d_ == 0) {
/* SOURCE mkembank.for:390 */
/*<       write(stdout,56)xc(1),yc(1) >*/
	    feq_gen_io_d__76.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__76);
	    do_fio(&feq_gen_c_d_1, (char *)&xc[0], (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&yc[0], (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* SOURCE mkembank.for:391 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE mkembank.for:392 */
/*<       else >*/
	} else {
/* SOURCE mkembank.for:393 */
/*<       wh=zc(1)-zs >*/
	    wh = zc[0] - zs;
/* SOURCE mkembank.for:394 */
/*<       if(wh.lt.minwh)then >*/
	    if (wh < minwh) {
/* SOURCE mkembank.for:395 */
/*<       write(note,61)minwh,minwh-wh >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 80;
		feq_gen_ici_d_1.iciunit = note;
		feq_gen_ici_d_1.icifmt = fmt_61;
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&minwh, (ftnlen)sizeof(doublereal));
		feq_gen_d_d_1 = minwh - wh;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_d_d_1, (ftnlen)sizeof(doublereal));
		e_wsfi();
/* SOURCE mkembank.for:396 */
/*<       zs=zc(1)-minwh >*/
		zs = zc[0] - minwh;
/* SOURCE mkembank.for:397 */
/*<       else >*/
	    } else {
/* SOURCE mkembank.for:398 */
/*<       note=' ' >*/
		s_copy(note, const_cast<char*>(" "), (ftnlen)80, (ftnlen)1);
/* SOURCE mkembank.for:399 */
/*<       endif >*/
	    }
/* SOURCE mkembank.for:400 */
/*<       write(stdout,60)s,zc(1),width,zs,surface,note >*/
	    feq_gen_io_d__79.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__79);
	    do_fio(&feq_gen_c_d_1, (char *)&s, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&zc[0], (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&width, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&zs, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, surface, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, note, (ftnlen)80);
	    e_wsfe();
/*          WRITE(STDOUT,60) S, ZC(1), WIDTH, ZS, SURFACE */
/* SOURCE mkembank.for:402 */
/*<       endif >*/
	}
/*       Do for the interior points. Find the elevation for the perpendicular */
/*       for each line segment and take the average. */
/* SOURCE mkembank.for:405 */
/*<       do200i=2,nc-1 >*/
	feq_gen_i_d_1 = nc - 1;
	for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE mkembank.for:406 */
/*<       s=s+sqrt((xc(i)-xc(i-1))**2+(yc(i)-yc(i-1))**2) >*/
/* Computing 2nd power */
	    feq_gen_d_d_1 = xc[feq_gen_i_d_ - 1] - xc[feq_gen_i_d_ - 2];
/* Computing 2nd power */
	    feq_gen_d_d_2 = yc[feq_gen_i_d_ - 1] - yc[feq_gen_i_d_ - 2];
	    s += sqrt(feq_gen_d_d_1 * feq_gen_d_d_1 + feq_gen_d_d_2 * feq_gen_d_d_2);
/*         Left-hand line segment */
/* SOURCE mkembank.for:409 */
/*<       callfind_line_coef(xc(i-1),yc(i-1),xc(i),yc(i),a,b,c) >*/
	    feq_gen_find_line_coef_d_(&xc[feq_gen_i_d_ - 2], &yc[feq_gen_i_d_ - 2], &xc[feq_gen_i_d_ - 1], &yc[
		    feq_gen_i_d_ - 1], &a, &b, &feq_gen_c_d_);
/*         Find the line perpendicular to the line (A, B, C) and passing */
/*         through point ( XC(I), YC(I) ) */
/* SOURCE mkembank.for:414 */
/*<       callfind_perpendicular(xc(i),yc(i),a,b,c,ap,bp,cp) >*/
	    feq_gen_find_perpendicular_d_(&xc[feq_gen_i_d_ - 1], &yc[feq_gen_i_d_ - 1], &a, &b, &feq_gen_c_d_, &
		    ap, &bp, &cp);
/* SOURCE mkembank.for:416 */
/*<        >*/
	    feq_gen_find_intersect_d_(xa, ya, za, aa, ba, ca, &na, &ap, &bp, &cp, xll, 
		    yll, xur, yur, &xs, &ys, &zl, &feq_gen_flag_d_);
/* SOURCE mkembank.for:419 */
/*<       if(flag.eq.0)then >*/
	    if (feq_gen_flag_d_ == 0) {
/* SOURCE mkembank.for:420 */
/*<       write(stdout,56)xc(i),yc(i) >*/
		feq_gen_io_d__80.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__80);
		do_fio(&feq_gen_c_d_1, (char *)&xc[feq_gen_i_d_ - 1], (ftnlen)sizeof(doublereal)
			);
		do_fio(&feq_gen_c_d_1, (char *)&yc[feq_gen_i_d_ - 1], (ftnlen)sizeof(doublereal)
			);
		e_wsfe();
/* SOURCE mkembank.for:421 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE mkembank.for:422 */
/*<       endif >*/
	    }
/*         Right-hand line segment */
/* SOURCE mkembank.for:425 */
/*<       callfind_line_coef(xc(i),yc(i),xc(i+1),yc(i+1),a,b,c) >*/
	    feq_gen_find_line_coef_d_(&xc[feq_gen_i_d_ - 1], &yc[feq_gen_i_d_ - 1], &xc[feq_gen_i_d_], &yc[feq_gen_i_d_], &
		    a, &b, &feq_gen_c_d_);
/*         Find the line perpendicular to the line (A, B, C) and passing */
/*         through point ( XC(I), YC(I) ) */
/* SOURCE mkembank.for:430 */
/*<       callfind_perpendicular(xc(i),yc(i),a,b,c,ap,bp,cp) >*/
	    feq_gen_find_perpendicular_d_(&xc[feq_gen_i_d_ - 1], &yc[feq_gen_i_d_ - 1], &a, &b, &feq_gen_c_d_, &
		    ap, &bp, &cp);
/* SOURCE mkembank.for:432 */
/*<        >*/
	    feq_gen_find_intersect_d_(xa, ya, za, aa, ba, ca, &na, &ap, &bp, &cp, xll, 
		    yll, xur, yur, &xs, &ys, &zr, &feq_gen_flag_d_);
/* SOURCE mkembank.for:435 */
/*<       if(flag.eq.0)then >*/
	    if (feq_gen_flag_d_ == 0) {
/* SOURCE mkembank.for:436 */
/*<       write(stdout,56)xc(i),yc(i) >*/
		feq_gen_io_d__81.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__81);
		do_fio(&feq_gen_c_d_1, (char *)&xc[feq_gen_i_d_ - 1], (ftnlen)sizeof(doublereal)
			);
		do_fio(&feq_gen_c_d_1, (char *)&yc[feq_gen_i_d_ - 1], (ftnlen)sizeof(doublereal)
			);
		e_wsfe();
/* SOURCE mkembank.for:437 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE mkembank.for:438 */
/*<       endif >*/
	    }
/*         Output the line */
/* SOURCE mkembank.for:441 */
/*<       zs=0.5*(zl+zr) >*/
	    zs = (zl + zr) * (float).5;
/* SOURCE mkembank.for:442 */
/*<       wh=zc(i)-zs >*/
	    wh = zc[feq_gen_i_d_ - 1] - zs;
/* SOURCE mkembank.for:443 */
/*<       if(wh.lt.minwh)then >*/
	    if (wh < minwh) {
/* SOURCE mkembank.for:444 */
/*<       write(note,61)minwh,minwh-wh >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 80;
		feq_gen_ici_d_1.iciunit = note;
		feq_gen_ici_d_1.icifmt = fmt_61;
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&minwh, (ftnlen)sizeof(doublereal));
		feq_gen_d_d_1 = minwh - wh;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_d_d_1, (ftnlen)sizeof(doublereal));
		e_wsfi();
/* SOURCE mkembank.for:445 */
/*<       zs=zc(i)-minwh >*/
		zs = zc[feq_gen_i_d_ - 1] - minwh;
/* SOURCE mkembank.for:446 */
/*<       else >*/
	    } else {
/* SOURCE mkembank.for:447 */
/*<       note=' ' >*/
		s_copy(note, const_cast<char*>(" "), (ftnlen)80, (ftnlen)1);
/* SOURCE mkembank.for:448 */
/*<       endif >*/
	    }
/* SOURCE mkembank.for:449 */
/*<       write(stdout,60)s,zc(i),width,zs,surface,note >*/
	    feq_gen_io_d__82.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__82);
	    do_fio(&feq_gen_c_d_1, (char *)&s, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&zc[feq_gen_i_d_ - 1], (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&width, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&zs, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, surface, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, note, (ftnlen)80);
	    e_wsfe();
/* SOURCE mkembank.for:450 */
/*<   200 continue >*/
/* L200: */
	}
/*       Do the last point */
/* SOURCE mkembank.for:452 */
/*<       i=nc >*/
	feq_gen_i_d_ = nc;
/* SOURCE mkembank.for:453 */
/*<       s=s+sqrt((xc(i)-xc(i-1))**2+(yc(i)-yc(i-1))**2) >*/
/* Computing 2nd power */
	feq_gen_d_d_1 = xc[feq_gen_i_d_ - 1] - xc[feq_gen_i_d_ - 2];
/* Computing 2nd power */
	feq_gen_d_d_2 = yc[feq_gen_i_d_ - 1] - yc[feq_gen_i_d_ - 2];
	s += sqrt(feq_gen_d_d_1 * feq_gen_d_d_1 + feq_gen_d_d_2 * feq_gen_d_d_2);
/* SOURCE mkembank.for:454 */
/*<       callfind_line_coef(xc(nc-1),yc(nc-1),xc(nc),yc(nc),a,b,c) >*/
	feq_gen_find_line_coef_d_(&xc[nc - 2], &yc[nc - 2], &xc[nc - 1], &yc[nc - 1], &
		a, &b, &feq_gen_c_d_);
/*       Find the line perpendicular to the line (A, B, C) and passing */
/*       through point ( XC(NC), YC(NC) ) */
/* SOURCE mkembank.for:459 */
/*<       callfind_perpendicular(xc(nc),yc(nc),a,b,c,ap,bp,cp) >*/
	feq_gen_find_perpendicular_d_(&xc[nc - 1], &yc[nc - 1], &a, &b, &feq_gen_c_d_, &ap, &bp,
		 &cp);
/* SOURCE mkembank.for:461 */
/*<        >*/
	feq_gen_find_intersect_d_(xa, ya, za, aa, ba, ca, &na, &ap, &bp, &cp, xll, yll,
		 xur, yur, &xs, &ys, &zs, &feq_gen_flag_d_);
/* SOURCE mkembank.for:464 */
/*<       if(flag.eq.0)then >*/
	if (feq_gen_flag_d_ == 0) {
/* SOURCE mkembank.for:465 */
/*<       write(stdout,56)xc(nc),yc(nc) >*/
	    feq_gen_io_d__83.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__83);
	    do_fio(&feq_gen_c_d_1, (char *)&xc[nc - 1], (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&yc[nc - 1], (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* SOURCE mkembank.for:466 */
/*<       else >*/
	} else {
/* SOURCE mkembank.for:467 */
/*<       wh=zc(nc)-zs >*/
	    wh = zc[nc - 1] - zs;
/* SOURCE mkembank.for:468 */
/*<       if(wh.lt.minwh)then >*/
	    if (wh < minwh) {
/* SOURCE mkembank.for:469 */
/*<       write(note,61)minwh,minwh-wh >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 80;
		feq_gen_ici_d_1.iciunit = note;
		feq_gen_ici_d_1.icifmt = fmt_61;
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&minwh, (ftnlen)sizeof(doublereal));
		feq_gen_d_d_1 = minwh - wh;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_d_d_1, (ftnlen)sizeof(doublereal));
		e_wsfi();
/* SOURCE mkembank.for:470 */
/*<       zs=zc(nc)-minwh >*/
		zs = zc[nc - 1] - minwh;
/* SOURCE mkembank.for:471 */
/*<       else >*/
	    } else {
/* SOURCE mkembank.for:472 */
/*<       note=' ' >*/
		s_copy(note, const_cast<char*>(" "), (ftnlen)80, (ftnlen)1);
/* SOURCE mkembank.for:473 */
/*<       endif >*/
	    }
/* SOURCE mkembank.for:474 */
/*<       write(stdout,60)s,zc(nc),width,zs,'END     ',note >*/
	    feq_gen_io_d__84.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__84);
	    do_fio(&feq_gen_c_d_1, (char *)&s, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&zc[nc - 1], (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&width, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&zs, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, const_cast<char*>("END     "), (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, note, (ftnlen)80);
	    e_wsfe();
/* SOURCE mkembank.for:475 */
/*<       endif >*/
	}
/* SOURCE mkembank.for:477 */
/*<       else >*/
    } else {
/*      The approach trace is not given. */
/* SOURCE mkembank.for:479 */
/*<       s=0.d0 >*/
	s = 0.;
/* SOURCE mkembank.for:480 */
/*<       do300i=1,nc-1 >*/
	feq_gen_i_d_1 = nc - 1;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE mkembank.for:481 */
/*<       write(stdout,62)s,zc(i),width,surface >*/
	    feq_gen_io_d__85.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__85);
	    do_fio(&feq_gen_c_d_1, (char *)&s, (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&zc[feq_gen_i_d_ - 1], (ftnlen)sizeof(doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&width, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, surface, (ftnlen)8);
	    e_wsfe();
/* SOURCE mkembank.for:482 */
/*<       s=s+sqrt((xc(i)-xc(i+1))**2+(yc(i)-yc(i+1))**2) >*/
/* Computing 2nd power */
	    feq_gen_d_d_1 = xc[feq_gen_i_d_ - 1] - xc[feq_gen_i_d_];
/* Computing 2nd power */
	    feq_gen_d_d_2 = yc[feq_gen_i_d_ - 1] - yc[feq_gen_i_d_];
	    s += sqrt(feq_gen_d_d_1 * feq_gen_d_d_1 + feq_gen_d_d_2 * feq_gen_d_d_2);
/* SOURCE mkembank.for:483 */
/*<   300 continue >*/
/* L300: */
	}
/* SOURCE mkembank.for:484 */
/*<       write(stdout,62)s,zc(nc),width,'END     ' >*/
	feq_gen_io_d__86.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__86);
	do_fio(&feq_gen_c_d_1, (char *)&s, (ftnlen)sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, (char *)&zc[nc - 1], (ftnlen)sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, (char *)&width, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, const_cast<char*>("END     "), (ftnlen)8);
	e_wsfe();
/* SOURCE mkembank.for:485 */
/*<       endif >*/
    }
/* SOURCE mkembank.for:487 */
/*<       return >*/
    return 0;
/* SOURCE mkembank.for:488 */
/*<       end >*/
} /* mkembank_ */

#ifdef __cplusplus
	}
#endif
