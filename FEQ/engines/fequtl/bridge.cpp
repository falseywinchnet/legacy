/* bridge.f -- translated by f2c (version 20240504).
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

/* COMMON xscomb_ is declared in common.hpp. */

#define xscomb_1 xscomb_

/* COMMON bridge_ is declared in common.hpp. */

#define bridge_1 bridge_

/* COMMON xscomd_ is declared in common.hpp. */

#define xscomd_1 xscomd_

/* COMMON xscomu_ is declared in common.hpp. */

#define xscomu_1 xscomu_

/* COMMON nrdzcm_ is declared in common.hpp. */

#define nrdzcm_1 nrdzcm_

/* COMMON flotab_ is declared in common.hpp. */

#define flotab_1 flotab_

/* Table of constant values */

static integer feq_gen_c_d_20 = 20;
static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_6 = 6;
static integer feq_gen_c_d_4 = 4;
static integer feq_gen_c_d_0 = 0;




/* SOURCE bridge.for:4 */
/*<        >*/
/* Subroutine */ int cxselm_(real *zgive, integer *stdout, integer *npnt, 
	integer *nsub, integer *navm, real *zmin, real *zmax, real *feq_storage_x, real *
	feq_gen_feq_storage_z_d_, integer *feq_storage_sb, real *nfac, real *left, real *right, real *feq_storage_lsn, 
	real *feq_storage_sn, integer *eflag, real *feq_storage_n, real *feq_storage_xsv)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j;
    real sns[1001], kold[200], lsns[1001], xsub[1001], zsub[1001];
    integer nnys[200], wrn557, sbsub[1001];
    real tsold[200];
    integer feq_gen_nvars_d_[200], nsubs;
    real natys[1800]	/* was [9][200] */, yatns[1800]	/* was [9][200] */;
    integer npnts;
    extern /* Subroutine */ int compel_(real *, integer *, integer *, integer 
	    *, real *, real *, integer *, real *, char *, integer *, real *, 
	    integer *, real *, real *, integer *, real *, integer *, real *, 
	    real *, real *, real *, ftnlen);
    integer snflgs;
    real submin;
    char betopt[8];
    extern /* Subroutine */ int subset_(integer *, integer *, real *, real *, 
	    integer *, real *, real *, real *, real *, real *, integer *, 
	    integer *, real *, real *, integer *, real *, real *);

/*     + + + PURPOSE + + + */
/*     Compute cross section elements at a given elevation with a given */
/*     subset without changing the cross section data. */
/* SOURCE bridge.for:14 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE bridge.for:16 */
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
/* SOURCE bridge.for:19 */
/*<       integereflag,navm,npnt,nsub,stdout >*/
/* SOURCE bridge.for:20 */
/*<       integersb(npnt) >*/
/* SOURCE bridge.for:21 */
/*<        >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ZGIVE  - Water surface elevation for computing elements */
/*     STDOUT - Fortran unit number for user output and messages */
/*     NPNT   - Number of points on boundary of a cross section */
/*     NSUB   - Number of subsections */
/*     NAVM   - Flag for averaging roughness */
/*     ZMIN   - Minimum elevation */
/*     ZMAX   - Maximum elevation */
/*     X      - Offsets of points on cross section boundary */
/*     Z      - Elevation at points on cross section boundary */
/*     SB     - Subsection numbers for the line segments */
/*     NFAC   - Factor in Manning's formula(1.49 or 1.0) */
/*     LEFT   - Defines the left-most offset for a subset to be */
/*               taken out of a cross section.  If LEFT > RIGHT, then */
/*               no subset taken. */
/*     RIGHT  - Right hand limit for subset from a cross section. No */
/*              subset taken if RIGHT < LEFT. */
/*     LSN    - Line segment Manning's n value */
/*     SN     - Sinuousity at a point on a cross section boundary */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     N      - Manning's n values */
/*     XSV    - Vector of various elements of cross section */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE bridge.for:48 */
/*<       integeri,j,npnts,snflgs,wrn557,nsubs >*/
/* SOURCE bridge.for:49 */
/*<       integernnys(pmxsub),nvars(pmxsub),sbsub(pmxpnt+2) >*/
/* SOURCE bridge.for:50 */
/*<        >*/
/* SOURCE bridge.for:53 */
/*<       characterbetopt*8 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE bridge.for:56 */
/*<       externalcompel,subset >*/
/* *********************************************************************** */
/* SOURCE bridge.for:58 */
/*<       betopt='OLDBETA' >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> sn(feq_storage_sn, 1);

    feq::IndexedPointer<real> lsn(feq_storage_lsn, 1);

    feq::IndexedPointer<integer> sb(feq_storage_sb, 1);

    feq::IndexedPointer<real> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    feq::IndexedPointer<real> n(feq_storage_n, 1);

    feq::IndexedPointer<real> xsv(feq_storage_xsv, 1);

    /* Function Body */
    s_copy(betopt, const_cast<char*>("OLDBETA"), (ftnlen)8, (ftnlen)7);
/*     CHECK FOR SUBSET REQUEST. */
/* SOURCE bridge.for:62 */
/*<       submin=zmin >*/
    submin = *zmin;
/* SOURCE bridge.for:63 */
/*<       if(left.lt.right)then >*/
    if (*left < *right) {
/*       WE HAVE A SUBSET REQUEST */
/* SOURCE bridge.for:68 */
/*<       npnts=npnt+2 >*/
	npnts = *npnt + 2;
/* SOURCE bridge.for:69 */
/*<        >*/
	subset_(stdout, npnt, &x[1], &feq_gen_z_d_[1], &sb[1], zmax, &sn[1], &lsn[1], 
		left, right, eflag, &npnts, xsub, zsub, sbsub, sns, lsns);
/*       Added walls are treated as frictionless.  Thus we have added */
/*       two subsection numbers. */
/* SOURCE bridge.for:76 */
/*<       sbsub(1)=nsub+1 >*/
	sbsub[0] = *nsub + 1;
/* SOURCE bridge.for:77 */
/*<       sbsub(npnts-1)=nsub+2 >*/
	sbsub[npnts - 2] = *nsub + 2;
/* SOURCE bridge.for:78 */
/*<       nsubs=nsub+2 >*/
	nsubs = *nsub + 2;
/*       Clear the values that are used in the cross section */
/*       computations but that need default values. */
/* SOURCE bridge.for:83 */
/*<       do100i=1,nsubs >*/
	feq_gen_i_d_1 = nsubs;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE bridge.for:84 */
/*<       natys(1,i)=0.0 >*/
	    natys[feq_gen_i_d_ * 9 - 9] = (float)0.;
/* SOURCE bridge.for:85 */
/*<       yatns(1,i)=0.0 >*/
	    yatns[feq_gen_i_d_ * 9 - 9] = (float)0.;
/* SOURCE bridge.for:86 */
/*<       nnys(i)=0 >*/
	    nnys[feq_gen_i_d_ - 1] = 0;
/* SOURCE bridge.for:87 */
/*<       nvars(i)=0 >*/
	    feq_gen_nvars_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE bridge.for:88 */
/*<   100 continue >*/
/* L100: */
	}
/* SOURCE bridge.for:90 */
/*<       snflgs=0 >*/
	snflgs = 0;
/*      WRITE(STDOUT,93) LEFT, RIGHT */
/* 93    FORMAT('SUBSET results after subsection adjustment: */
/*     A      ',/,' LEFT=',F10.2,' RIGHT=',F10.2, ' NSUBS=',I5) */
/*      DO 500 I=1,NPNTS */
/*        WRITE(STDOUT,92) XSUB(I),ZSUB(I),SBSUB(I) */
/* 92      FORMAT(2F10.2,I5) */
/* 500   CONTINUE */
/* SOURCE bridge.for:101 */
/*<       submin=9999999.0 >*/
	submin = (float)9999999.;
/* SOURCE bridge.for:102 */
/*<       do140j=1,npnts >*/
	feq_gen_i_d_1 = npnts;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE bridge.for:103 */
/*<       if(zsub(j).lt.submin)submin=zsub(j) >*/
	    if (zsub[j - 1] < submin) {
		submin = zsub[j - 1];
	    }
/* SOURCE bridge.for:104 */
/*<   140 continue >*/
/* L140: */
	}
/* SOURCE bridge.for:105 */
/*<       do150i=1,nsubs >*/
	feq_gen_i_d_1 = nsubs;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE bridge.for:106 */
/*<       kold(i)=0.0 >*/
	    kold[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE bridge.for:107 */
/*<       tsold(i)=1.e30 >*/
	    tsold[feq_gen_i_d_ - 1] = (float)1e30;
/* SOURCE bridge.for:108 */
/*<   150 continue >*/
/* L150: */
	}
/* SOURCE bridge.for:109 */
/*<       wrn557=0 >*/
	wrn557 = 0;
/* SOURCE bridge.for:110 */
/*<        >*/
	compel_(zgive, &npnts, &nsubs, navm, xsub, zsub, sbsub, nfac, betopt, 
		&snflgs, lsns, feq_gen_nvars_d_, natys, yatns, nnys, sns, &wrn557, 
		kold, tsold, &n[1], &xsv[1], (ftnlen)8);
/* SOURCE bridge.for:116 */
/*<       xsv(1)=zgive-submin >*/
	xsv[1] = static_cast<double>(*zgive) - submin;
/* SOURCE bridge.for:117 */
/*<       else >*/
    } else {
/* SOURCE bridge.for:119 */
/*<       snflgs=0 >*/
	snflgs = 0;
/* SOURCE bridge.for:120 */
/*<       do160i=1,nsub >*/
	feq_gen_i_d_1 = *nsub;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE bridge.for:121 */
/*<       kold(i)=0.0 >*/
	    kold[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE bridge.for:122 */
/*<       tsold(i)=1.e30 >*/
	    tsold[feq_gen_i_d_ - 1] = (float)1e30;
/* SOURCE bridge.for:123 */
/*<       natys(1,i)=0.0 >*/
	    natys[feq_gen_i_d_ * 9 - 9] = (float)0.;
/* SOURCE bridge.for:124 */
/*<       yatns(1,i)=0.0 >*/
	    yatns[feq_gen_i_d_ * 9 - 9] = (float)0.;
/* SOURCE bridge.for:125 */
/*<       nnys(i)=0 >*/
	    nnys[feq_gen_i_d_ - 1] = 0;
/* SOURCE bridge.for:126 */
/*<       nvars(i)=0 >*/
	    feq_gen_nvars_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE bridge.for:127 */
/*<   160 continue >*/
/* L160: */
	}
/* SOURCE bridge.for:128 */
/*<       wrn557=0 >*/
	wrn557 = 0;
/* SOURCE bridge.for:129 */
/*<        >*/
	compel_(zgive, npnt, nsub, navm, &x[1], &feq_gen_z_d_[1], &sb[1], nfac, betopt,
		 &snflgs, &lsn[1], feq_gen_nvars_d_, natys, yatns, nnys, &sn[1], &
		wrn557, kold, tsold, &n[1], &xsv[1], (ftnlen)8);
/* SOURCE bridge.for:134 */
/*<       xsv(1)=zgive-submin >*/
	xsv[1] = static_cast<double>(*zgive) - submin;
/* SOURCE bridge.for:136 */
/*<       endif >*/
    }
/* SOURCE bridge.for:137 */
/*<       return >*/
    return 0;
/* SOURCE bridge.for:138 */
/*<       end >*/
} /* cxselm_ */




/* SOURCE bridge.for:142 */
/*<       realfunctionbwfsk(skew,m,n,sk,skmat) >*/
doublereal bwfsk_(real *skew, real *m, integer *n, real *feq_storage_sk, real *feq_storage_skmat)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    real ret_val;

    /* Local variables */
    integer feq_gen_i_d_, j;
    real p, s1, s2;
    integer jj;

/*     + + + PURPOSE + + + */
/*     Compute skew corrections. */
/* SOURCE bridge.for:148 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE bridge.for:151 */
/*<       integern >*/
/* SOURCE bridge.for:152 */
/*<       realm,sk(n),skew,skmat(5,n) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     SKEW   - Skew */
/*     M      - Contraction ratio */
/*     N      - Number of items in the skew table */
/*     SK     - Skew */
/*     SKMAT  - Matrix of skew adjustments */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE bridge.for:162 */
/*<       integeri,j,jj >*/
/* SOURCE bridge.for:163 */
/*<       realp,s1,s2 >*/
/* *********************************************************************** */
/* SOURCE bridge.for:165 */
/*<       do110j=2,n >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> skmat(feq_storage_skmat, 6);

    feq::IndexedPointer<real> sk(feq_storage_sk, 1);

    /* Function Body */
    feq_gen_i_d_1 = *n;
    for (j = 2; j <= feq_gen_i_d_1; ++j) {
/* SOURCE bridge.for:166 */
/*<       if(skew.le.sk(j))goto120 >*/
	if (*skew <= sk[j]) {
	    goto L120;
	}
/* SOURCE bridge.for:167 */
/*<   110 continue >*/
/* L110: */
    }
/*     MAY NEED AN ERROR MESSAGE HERE */
/* SOURCE bridge.for:171 */
/*<   120 continue >*/
L120:
/* SOURCE bridge.for:172 */
/*<       p=(skew-sk(j-1))/(sk(j)-sk(j-1)) >*/
    p = static_cast<double>((static_cast<double>(*skew) - sk[j - 1])) / (static_cast<double>(sk[j]) - sk[j - 1]);
/* SOURCE bridge.for:173 */
/*<       s1=skmat(5,j-1) >*/
    s1 = skmat[(j - 1) * 5 + 5];
/* SOURCE bridge.for:174 */
/*<       s2=skmat(5,j) >*/
    s2 = skmat[j * 5 + 5];
/* SOURCE bridge.for:175 */
/*<       do130i=1,4 >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 4; ++feq_gen_i_d_) {
/* SOURCE bridge.for:176 */
/*<       jj=5-i >*/
	jj = 5 - feq_gen_i_d_;
/* SOURCE bridge.for:177 */
/*<       s1=skmat(jj,j-1)+m*s1 >*/
	s1 = static_cast<double>(skmat[jj + (j - 1) * 5]) + static_cast<double>(*m) * s1;
/* SOURCE bridge.for:178 */
/*<       s2=skmat(jj,j)+m*s2 >*/
	s2 = static_cast<double>(skmat[jj + j * 5]) + static_cast<double>(*m) * s2;
/* SOURCE bridge.for:179 */
/*<   130 continue >*/
/* L130: */
    }
/* SOURCE bridge.for:181 */
/*<       bwfsk=p*s2+(1.-p)*s1 >*/
    ret_val = static_cast<double>(static_cast<double>(p) * s2) + static_cast<double>((static_cast<double>((float)1.) - p)) * s1;
/* SOURCE bridge.for:182 */
/*<       return >*/
    return ret_val;
/* SOURCE bridge.for:183 */
/*<       end >*/
} /* bwfsk_ */




/* SOURCE bridge.for:187 */
/*<       subroutinestdarg(argmin,argmax,n,arg) >*/
/* Subroutine */ int stdarg_(real *argmin, real *argmax, integer *n, real *
	feq_storage_arg)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_;
    real ymax;

/*     + + + PURPOSE + + + */
/*     Create a standard argument progression. */
/* SOURCE bridge.for:194 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE bridge.for:197 */
/*<       integern >*/
/* SOURCE bridge.for:198 */
/*<       realarg(n),argmax,argmin >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ARGMIN - Minimum argument value */
/*     ARGMAX - Maximum argument value */
/*     N      - Number of arguments */
/*     ARG    - Standard argument progression */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE bridge.for:207 */
/*<       integeri >*/
/* SOURCE bridge.for:208 */
/*<       realymax >*/
/*     + + + INTRINSICS + + + */
/* SOURCE bridge.for:211 */
/*<       intrinsicfloat >*/
/* *********************************************************************** */
/* SOURCE bridge.for:213 */
/*<       ymax=argmax-argmin >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> arg(feq_storage_arg, 1);

    /* Function Body */
    ymax = static_cast<double>(*argmax) - *argmin;
/* SOURCE bridge.for:215 */
/*<       do100i=1,n >*/
    feq_gen_i_d_1 = *n;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE bridge.for:216 */
/*<       arg(i)=argmin+ymax*float(i-1)/float(n-1) >*/
	arg[feq_gen_i_d_] = static_cast<double>(*argmin) + static_cast<double>(static_cast<double>(ymax) * (real) (feq_gen_i_d_ - 1)) / (real) (*n - 1);
/* SOURCE bridge.for:217 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE bridge.for:218 */
/*<       return >*/
    return 0;
/* SOURCE bridge.for:219 */
/*<       end >*/
} /* stdarg_ */




/* SOURCE bridge.for:223 */
/*<       subroutineinelev(stdin,stdout,zmin,zmax,nft,zft,tab) >*/
/* Subroutine */ int inelev_(integer *stdin, integer *stdout, real *zmin, 
	real *zmax, integer *nft, real *feq_storage_zft, integer *tab)
{
    /* Format strings */
    static char fmt_1[] = "(20a4)";
    static char fmt_51[] = "(\002 \002,20a4)";
    static char fmt_52[] = "(\002 TABID=\002,a)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(), 
	    s_wsfe(cilist *), e_wsfe(), s_wsle(cilist *), do_lio(integer *, 
	    integer *, char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_read_tabid_d_(integer *, char *, char *, 
	    integer *, char *, integer *, ftnlen, ftnlen, ftnlen);
    integer head[20];
    char line[80];
    integer eflag;
    char tabid[16];
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen),
	     stdarg_(real *, real *, integer *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__30 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__33 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__34 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__35 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Input elevations for the flow table. */
/* SOURCE bridge.for:230 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE bridge.for:233 */
/*<       integernft,stdin,stdout,tab >*/
/* SOURCE bridge.for:234 */
/*<       realzft(nft),zmax,zmin >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     ZMIN   - Minimum elevation */
/*     ZMAX   - Maximum elevation */
/*     NFT    - Number of values in the bridge loss table */
/*     ZFT    - Tabulated values of elevation */
/*     TAB    - Table number */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE bridge.for:246 */
/*<       integerhead(20),eflag >*/
/* SOURCE bridge.for:247 */
/*<       characterline*80,tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE bridge.for:250 */
/*<       externalinline,stdarg >*/
/*     + + + INPUT FORMATS + + + */
/* SOURCE bridge.for:253 */
/*<     1 format(20a4) >*/
/* SOURCE bridge.for:254 */
/*<     2 format(7x,i5) >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE bridge.for:257 */
/*<    51 format(' ',20a4) >*/
/* SOURCE bridge.for:258 */
/*<    52 format(' TABID=',a) >*/
/* *********************************************************************** */
/* SOURCE bridge.for:260 */
/*<       callinline(stdin,stdout,line) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> zft(feq_storage_zft, 1);

    /* Function Body */
/* L1: */
/* L2: */
/* L51: */
/* L52: */
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE bridge.for:263 */
/*<       read(line,1,err=991)head >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_1;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_20, (char *)&head[0], (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE bridge.for:264 */
/*<       write(stdout,51)head >*/
    feq_gen_io_d__30.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__30);
    do_fio(&feq_gen_c_d_20, (char *)&head[0], (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE bridge.for:266 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE bridge.for:269 */
/*<       callread_tabid(stdout,line,'TAB',eflag,tabid,tab) >*/
    feq_gen_read_tabid_d_(stdout, line, const_cast<char*>("TAB"), &eflag, tabid, tab, (ftnlen)80, (ftnlen)
	    3, (ftnlen)16);
/*      READ(LINE,2,ERR=991) TAB */
/* SOURCE bridge.for:273 */
/*<       write(stdout,52)tabid >*/
    feq_gen_io_d__33.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__33);
    do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
    e_wsfe();
/* SOURCE bridge.for:274 */
/*<       callstdarg(zmin,zmax,nft,zft) >*/
    stdarg_(zmin, zmax, nft, &zft[1]);
/* SOURCE bridge.for:277 */
/*<       return >*/
    return 0;
/* SOURCE bridge.for:278 */
/*<   991 continue >*/
L991:
/* SOURCE bridge.for:279 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__34.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__34);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE bridge.for:280 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__35.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__35);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE bridge.for:281 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE bridge.for:282 */
/*<       end >*/
    return 0;
} /* inelev_ */




/* SOURCE bridge.for:286 */
/*<       subroutinebwcoef(bscurv,bskew,abtype,adjfac,ptype,m,ap,ab,bw) >*/
/* Subroutine */ int bwcoef_(integer *bscurv, real *bskew, integer *abtype, 
	real *adjfac, integer *ptype, real *m, real *ap, real *ab, real *bw)
{
    /* Initialized data */

    static real bsbw[15]	/* was [5][3] */ = { (float)4.139891,(float)
	    -10.52214,(float)14.56526,(float)-14.14747,(float)5.964457,(float)
	    3.965164,(float)-8.507644,(float)9.610875,(float)-9.256056,(float)
	    4.187662,(float)3.77454,(float)-5.689646,(float)1.324003,(float)
	    .289164,(float).301939 };
    static real prbw1[40]	/* was [5][8] */ = { (float).077,(float).1,(
	    float)1.69903,(float)5.19906,(float).89837,(float).056,(float).1,(
	    float)2.29032,(float)9.01086,(float)1.28111,(float).069,(float)
	    .15,(float)2.57732,(float)5.84647,(float)1.77051,(float).058,(
	    float).15,(float)3.125,(float)9.28954,(float)2.04741,(float).049,(
	    float).15,(float)3.78788,(float)14.8297,(float)2.33457,(float)
	    .043,(float).15,(float)4.62963,(float)26.5409,(float)2.34711,(
	    float).031,(float).15,(float)6.57895,(float)56.1367,(float)
	    3.09847,(float).026,(float).15,(float)8.06452,(float)88.2802,(
	    float)3.47395 };
    static real prbw2[24]	/* was [3][8] */ = { (float).233333,(float)
	    1.466666,(float)-.7,(float).216111,(float)1.389444,(float)
	    -.605556,(float).26889,(float)1.57111,(float)-.70556,(float)
	    .052778,(float)1.752778,(float)-.805556,(float)-.002222,(float)
	    1.857778,(float)-.855556,(float)-.057222,(float)1.962778,(float)
	    -.905556,(float)-.098889,(float)1.954444,(float)-.855556,(float)
	    -.136111,(float)1.963889,(float)-.827778 };
    static real ska[6] = { (float)0.,(float)10.,(float)20.,(float)30.,(float)
	    40.,(float)45. };
    static real skbwa[30]	/* was [5][6] */ = { (float)0.,(float)0.,(
	    float)0.,(float)0.,(float)0.,(float)-.368636,(float)1.49909,(
	    float)-2.550346,(float)2.060606,(float)-.640692,(float)-.664364,(
	    float)2.41155,(float)-3.603463,(float)2.548917,(float)-.69264,(
	    float)-.877909,(float)2.69016,(float)-3.938657,(float)3.286579,(
	    float)-1.160173,(float)-1.062273,(float)2.230758,(float)-1.222598,
	    (float)-.28355,(float).337662,(float)-1.427182,(float)3.776013,(
	    float)-3.919826,(float)1.822077,(float)-.251082 };
    static real skb[4] = { (float)0.,(float)15.,(float)30.,(float)45. };
    static real skbwb[20]	/* was [5][4] */ = { (float)0.,(float)0.,(
	    float)0.,(float)0.,(float)0.,(float).083,(float)-2.062048,(float)
	    7.720762,(float)-8.609524,(float)3.380952,(float).737,(float)
	    -7.94319,(float)22.95381,(float)-24.9381,(float)9.190476,(float)
	    -.606,(float)-3.204,(float)18.04333,(float)-23.56666,(float)
	    9.333333 };

    integer feq_gen_i_d_, j;
    real s, s1, jf;
    extern doublereal bwfsk_(real *, real *, integer *, real *, real *);

/*     + + + PURPOSE + + + */
/*     Compute backwater coef. */
/* SOURCE bridge.for:294 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE bridge.for:297 */
/*<       integerabtype,bscurv,ptype >*/
/* SOURCE bridge.for:298 */
/*<       realab,adjfac,ap,bskew,bw,m >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     BSCURV - Number for basic backwater coefficient curve(1:3) */
/*     BSKEW  - Skew of bridge crossing */
/*     ABTYPE - Code for abutment type */
/*     ADJFAC - Adjustment factor for backwater coefficient */
/*     PTYPE  - Code for pier type */
/*     M      - Contraction ratio */
/*     AP     - Area of piers */
/*     AB     - Area of bridge opening excluding piers */
/*     BW     - Backwater coefficient */
/*     + + + SAVED VALUES + + + */
/* SOURCE bridge.for:312 */
/*<        >*/
/* SOURCE bridge.for:314 */
/*<       savebsbw,prbw1,prbw2,ska,skb,skbwa,skbwb >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE bridge.for:317 */
/*<       integeri,j >*/
/* SOURCE bridge.for:318 */
/*<       realjf,s,s1 >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE bridge.for:321 */
/*<       realbwfsk >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE bridge.for:324 */
/*<       externalbwfsk >*/
/*     + + + DATA INITIALIZATIONS + + + */
/* *********************************************************************** */
/*     FIND BASE VALUE */
/* SOURCE bridge.for:327 */
/*<        >*/
/* SOURCE bridge.for:330 */
/*<        >*/
/* SOURCE bridge.for:339 */
/*<        >*/
/* SOURCE bridge.for:348 */
/*<       dataska/0.,10.,20.,30.,40.,45./ >*/
/* SOURCE bridge.for:349 */
/*<        >*/
/* SOURCE bridge.for:356 */
/*<       dataskb/0.,15.,30.,45./ >*/
/* SOURCE bridge.for:357 */
/*<        >*/
/* SOURCE bridge.for:365 */
/*<       s=bsbw(5,bscurv) >*/
    s = bsbw[(0 + (0 + (5 + *bscurv * 5 - 6 << 2))) / 4];
/* SOURCE bridge.for:366 */
/*<       do100i=1,4 >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 4; ++feq_gen_i_d_) {
/* SOURCE bridge.for:367 */
/*<       j=5-i >*/
	j = 5 - feq_gen_i_d_;
/* SOURCE bridge.for:368 */
/*<       s=bsbw(j,bscurv)+m*s >*/
	s = static_cast<double>(bsbw[j + *bscurv * 5 - 6]) + static_cast<double>(*m) * s;
/* SOURCE bridge.for:369 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE bridge.for:371 */
/*<       if(s.lt.0.)s=0. >*/
    if (s < (float)0.) {
	s = (float)0.;
    }
/* SOURCE bridge.for:372 */
/*<       bw=s >*/
    *bw = s;
/*     COMPUTE INCREMENT FOR PIERS */
/* SOURCE bridge.for:377 */
/*<       if(ptype.eq.0)goto500 >*/
    if (*ptype == 0) {
	goto L500;
    }
/* SOURCE bridge.for:378 */
/*<       jf=ap/ab >*/
    jf = static_cast<double>(*ap) / *ab;
/* SOURCE bridge.for:380 */
/*<       if(jf.gt.prbw1(1,ptype))goto120 >*/
    if (jf > prbw1[*ptype * 5 - 5]) {
	goto L120;
    }
/* SOURCE bridge.for:381 */
/*<       s=jf*(prbw1(5,ptype)+prbw1(4,ptype)*jf) >*/
    s = static_cast<double>(jf) * (static_cast<double>(prbw1[*ptype * 5 - 1]) + static_cast<double>(prbw1[*ptype * 5 - 2]) * jf);
/* SOURCE bridge.for:382 */
/*<       goto140 >*/
    goto L140;
/* SOURCE bridge.for:383 */
/*<   120 continue >*/
L120:
/* SOURCE bridge.for:384 */
/*<       s=prbw1(2,ptype)+prbw1(3,ptype)*(jf-prbw1(1,ptype)) >*/
    s = static_cast<double>(prbw1[*ptype * 5 - 4]) + static_cast<double>(prbw1[*ptype * 5 - 3]) * (static_cast<double>(jf) - prbw1[*ptype * 
	    5 - 5]);
/* SOURCE bridge.for:385 */
/*<   140 continue >*/
L140:
/* SOURCE bridge.for:387 */
/*<       s1=prbw2(1,ptype)+m*(prbw2(2,ptype)+m*prbw2(3,ptype)) >*/
    s1 = static_cast<double>(prbw2[*ptype * 3 - 3]) + static_cast<double>(*m) * (static_cast<double>(prbw2[*ptype * 3 - 2]) + static_cast<double>(*m) * prbw2[*
	    ptype * 3 - 1]);
/* SOURCE bridge.for:388 */
/*<       if(s1.lt.0.)s1=0. >*/
    if (s1 < (float)0.) {
	s1 = (float)0.;
    }
/* SOURCE bridge.for:389 */
/*<       s=s*s1 >*/
    s *= s1;
/* SOURCE bridge.for:390 */
/*<       bw=bw+s >*/
    *bw += s;
/* SOURCE bridge.for:391 */
/*<   500 continue >*/
L500:
/*       CORRECT FOR SKEW */
/* SOURCE bridge.for:395 */
/*<       if(bskew.le.0.)goto900 >*/
    if (*bskew <= (float)0.) {
	goto L900;
    }
/* SOURCE bridge.for:396 */
/*<       if(abtype.eq.1)goto600 >*/
    if (*abtype == 1) {
	goto L600;
    }
/*           ABUTMENTS PARALLEL TO FLOW HERE */
/* SOURCE bridge.for:400 */
/*<       bw=bw+bwfsk(bskew,m,6,ska,skbwa) >*/
    *bw += bwfsk_(bskew, m, &feq_gen_c_d_6, ska, skbwa);
/* SOURCE bridge.for:401 */
/*<       goto700 >*/
    goto L700;
/* SOURCE bridge.for:402 */
/*<   600 continue >*/
L600:
/*           ABUTMENTS NOT PARALLEL TO FLOW */
/* SOURCE bridge.for:406 */
/*<       bw=bw+bwfsk(bskew,m,4,skb,skbwb) >*/
    *bw += bwfsk_(bskew, m, &feq_gen_c_d_4, skb, skbwb);
/* SOURCE bridge.for:407 */
/*<   700 continue >*/
L700:
/* SOURCE bridge.for:408 */
/*<   900 continue >*/
L900:
/* SOURCE bridge.for:410 */
/*<       bw=bw*adjfac >*/
    *bw *= *adjfac;
/* SOURCE bridge.for:411 */
/*<       return >*/
    return 0;
/* SOURCE bridge.for:412 */
/*<       end >*/
} /* bwcoef_ */




/* SOURCE bridge.for:416 */
/*<        >*/
/* Subroutine */ int mcomp_(integer *stdout, real *cntr, real *t, real *zw, 
	real *k, integer *npnt, integer *nsub, integer *navm, real *feq_storage_x, real *
	feq_gen_feq_storage_z_d_, integer *feq_storage_sb, real *nfac, real *feq_storage_sn, real *feq_storage_lsn, integer *eflag, 
	real *feq_storage_n, real *m)
{
    /* Format strings */
    static char fmt_51[] = "(\002 *WRN:509* M > 1 IN MCOMP.K =\002,1pe12.5\
,\002 KSUB =\002,1pe12.5)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer feq_gen_i_d_;
    real xl, xr, xs[1001], zs[1001];
    integer sbs[1001];
    real sns[1001], xsv[22], kold[200], ksub, lsns[1001], zmax;
    integer nnys[200], wrn557;
    real tsold[200];
    integer feq_gen_nvars_d_[200], nsubs;
    real natys[1800]	/* was [9][200] */, yatns[1800]	/* was [9][200] */;
    integer npnts;
    extern /* Subroutine */ int compel_(real *, integer *, integer *, integer 
	    *, real *, real *, integer *, real *, char *, integer *, real *, 
	    integer *, real *, real *, integer *, real *, integer *, real *, 
	    real *, real *, real *, ftnlen);
    integer snflgs;
    char betopt[8];
    extern /* Subroutine */ int subset_(integer *, integer *, real *, real *, 
	    integer *, real *, real *, real *, real *, real *, integer *, 
	    integer *, real *, real *, integer *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__70 = { 0, 0, 0, fmt_51, 0 };


/*     + + + PURPOSE + + + */
/*     Compute the contraction ratio. */
/* SOURCE bridge.for:425 */
/*<       implicitnone >*/
/* INCLUDE bridge.for:426 */
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
/* SOURCE bridge.for:429 */
/*<       integereflag,navm,npnt,nsub,stdout >*/
/* SOURCE bridge.for:430 */
/*<       integersb(npnt) >*/
/* SOURCE bridge.for:431 */
/*<        >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     CNTR   - Offset in the approach section at the main channel */
/*               point of minimum elevation */
/*     T      - Bridge opening width */
/*     ZW     - Water surface elevation for computing contraction ratio */
/*     K      - conveyance */
/*     NPNT   - Number of points on boundary of a cross section */
/*     NSUB   - Number of subsections */
/*     NAVM   - Flag for averaging roughness */
/*     X      - Offsets of points on cross section boundary */
/*     Z      - Elevation at points on cross section boundary */
/*     SB     - Subsection numbers for the line segments */
/*     NFAC   - Factor in Manning's formula(1.49 or 1.0) */
/*     SN     - Sinuousity at a point on a cross section boundary */
/*     LSN    - Line segment Manning's n value */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     N      - Manning's n values */
/*     M      - Contraction ratio */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE bridge.for:456 */
/*<       integeri,npnts,nsubs,snflgs,wrn557 >*/
/* SOURCE bridge.for:457 */
/*<       integernnys(pmxsub),nvars(pmxsub),sbs(pmxpnt+2) >*/
/* SOURCE bridge.for:458 */
/*<        >*/
/* SOURCE bridge.for:461 */
/*<       characterbetopt*8 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE bridge.for:464 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE bridge.for:467 */
/*<       externalcompel,subset >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE bridge.for:470 */
/*<    51 format(' *WRN:509* M > 1 IN MCOMP.K =',1pe12.5,' KSUB =',1pe12.5) >*/
/* *********************************************************************** */
/* SOURCE bridge.for:472 */
/*<       betopt='OLDBETA' >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> lsn(feq_storage_lsn, 1);

    feq::IndexedPointer<real> sn(feq_storage_sn, 1);

    feq::IndexedPointer<integer> sb(feq_storage_sb, 1);

    feq::IndexedPointer<real> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    feq::IndexedPointer<real> n(feq_storage_n, 1);

    /* Function Body */
/* L51: */
    s_copy(betopt, const_cast<char*>("OLDBETA"), (ftnlen)8, (ftnlen)7);
/*     COMPUTE XL AND XR */
/* SOURCE bridge.for:475 */
/*<       xl=cntr-t/2. >*/
    xl = static_cast<double>(*cntr) - static_cast<double>(*t) / (float)2.;
/* SOURCE bridge.for:476 */
/*<       xr=cntr+t/2. >*/
    xr = static_cast<double>(*cntr) + static_cast<double>(*t) / (float)2.;
/*     DEVELOP SUBSET OF THE BASIC CROSS SECTION */
/* SOURCE bridge.for:481 */
/*<       zmax=z(1) >*/
    zmax = feq_gen_z_d_[1];
/* SOURCE bridge.for:483 */
/*<       npnts=pmxpnt+2 >*/
    npnts = 1001;
/* SOURCE bridge.for:484 */
/*<        >*/
    subset_(stdout, npnt, &x[1], &feq_gen_z_d_[1], &sb[1], &zmax, &sn[1], &lsn[1], &xl,
	     &xr, eflag, &npnts, xs, zs, sbs, sns, lsns);
/*      Force added walls to be frictionless */
/* SOURCE bridge.for:490 */
/*<       sbs(1)=nsub+1 >*/
    sbs[0] = *nsub + 1;
/* SOURCE bridge.for:491 */
/*<       sbs(npnts-1)=nsub+2 >*/
    sbs[npnts - 2] = *nsub + 2;
/* SOURCE bridge.for:492 */
/*<       nsubs=nsub+2 >*/
    nsubs = *nsub + 2;
/*     Set sinuousity and the Manning's n variation values to the */
/*     default values. */
/* SOURCE bridge.for:497 */
/*<       do100i=1,nsubs >*/
    feq_gen_i_d_1 = nsubs;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE bridge.for:498 */
/*<       natys(1,i)=0.0 >*/
	natys[feq_gen_i_d_ * 9 - 9] = (float)0.;
/* SOURCE bridge.for:499 */
/*<       yatns(1,i)=0.0 >*/
	yatns[feq_gen_i_d_ * 9 - 9] = (float)0.;
/* SOURCE bridge.for:500 */
/*<       nnys(i)=0 >*/
	nnys[feq_gen_i_d_ - 1] = 0;
/* SOURCE bridge.for:501 */
/*<       nvars(i)=0 >*/
	feq_gen_nvars_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE bridge.for:502 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE bridge.for:503 */
/*<       snflgs=0 >*/
    snflgs = 0;
/*     COMPUTE THE CONVEYANCE IN THE SUBSECTION */
/* SOURCE bridge.for:507 */
/*<       do110i=1,nsubs >*/
    feq_gen_i_d_1 = nsubs;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE bridge.for:508 */
/*<       kold(i)=0.0 >*/
	kold[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE bridge.for:509 */
/*<       tsold(i)=1.e30 >*/
	tsold[feq_gen_i_d_ - 1] = (float)1e30;
/* SOURCE bridge.for:510 */
/*<   110 continue >*/
/* L110: */
    }
/* SOURCE bridge.for:511 */
/*<       wrn557=0 >*/
    wrn557 = 0;
/* SOURCE bridge.for:512 */
/*<        >*/
    compel_(zw, &npnts, &nsubs, navm, xs, zs, sbs, nfac, betopt, &snflgs, 
	    lsns, feq_gen_nvars_d_, natys, yatns, nnys, sns, &wrn557, kold, tsold, &n[
	    1], xsv, (ftnlen)8);
/* SOURCE bridge.for:518 */
/*<       ksub=xsv(5)**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = xsv[4];
    ksub = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE bridge.for:519 */
/*<       m=ksub/k >*/
    *m = static_cast<double>(ksub) / *k;
/* SOURCE bridge.for:522 */
/*<       if(m.gt.1.0)then >*/
    if (*m > (float)1.) {
/* SOURCE bridge.for:523 */
/*<       m=1.0 >*/
	*m = (float)1.;
/* SOURCE bridge.for:524 */
/*<       if(abs(k-ksub)/k.gt.0.005)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(*k) - ksub, dabs(feq_gen_r_d_1)) / *k > (float).005) {
/* SOURCE bridge.for:525 */
/*<       write(stdout,51)k,ksub >*/
	    feq_gen_io_d__70.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__70);
	    do_fio(&feq_gen_c_d_1, (char *)&(*k), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&ksub, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE bridge.for:526 */
/*<       endif >*/
	}
/* SOURCE bridge.for:527 */
/*<       endif >*/
    }
/* SOURCE bridge.for:528 */
/*<       return >*/
    return 0;
/* SOURCE bridge.for:529 */
/*<       end >*/
} /* mcomp_ */




/* SOURCE bridge.for:533 */
/*<       subroutinecpta(n,z,pnum,pwidth,tpv,apv) >*/
/* Subroutine */ int cpta_(integer *n, real *feq_gen_feq_storage_z_d_, integer *feq_storage_pnum, real *feq_storage_pwidth,
	 real *feq_storage_tpv, real *feq_storage_apv)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer j;

/*     + + + PURPOSE + + + */
/*     Compute top width and area for piers. */
/* SOURCE bridge.for:540 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE bridge.for:543 */
/*<       integern >*/
/* SOURCE bridge.for:544 */
/*<       integerpnum(n) >*/
/* SOURCE bridge.for:545 */
/*<       realapv(n),pwidth(n),tpv(n),z(n) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     N      - Number of items in pier definition */
/*     Z      - Elevation values for pier widths */
/*     PNUM   - Number of piers */
/*     PWIDTH - Pier width */
/*     TPV    - Vector of values of total width of piers in bridge opening */
/*     APV    - Vector of values giving area of piers */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE bridge.for:556 */
/*<       integerj >*/
/* *********************************************************************** */
/* SOURCE bridge.for:558 */
/*<       tpv(1)=pnum(1)*pwidth(1) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> apv(feq_storage_apv, 1);

    feq::IndexedPointer<real> tpv(feq_storage_tpv, 1);

    feq::IndexedPointer<real> pwidth(feq_storage_pwidth, 1);

    feq::IndexedPointer<integer> pnum(feq_storage_pnum, 1);

    feq::IndexedPointer<real> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    /* Function Body */
    tpv[1] = static_cast<double>(pnum[1]) * pwidth[1];
/* SOURCE bridge.for:559 */
/*<       apv(1)=0. >*/
    apv[1] = (float)0.;
/* SOURCE bridge.for:560 */
/*<       do100j=2,n >*/
    feq_gen_i_d_1 = *n;
    for (j = 2; j <= feq_gen_i_d_1; ++j) {
/* SOURCE bridge.for:561 */
/*<       tpv(j)=pnum(j)*pwidth(j) >*/
	tpv[j] = static_cast<double>(pnum[j]) * pwidth[j];
/* SOURCE bridge.for:562 */
/*<       apv(j)=apv(j-1)+(z(j)-z(j-1))*(tpv(j-1)+tpv(j))/2. >*/
	apv[j] = static_cast<double>(apv[j - 1]) + static_cast<double>(static_cast<double>((static_cast<double>(feq_gen_z_d_[j]) - feq_gen_z_d_[j - 1])) * (static_cast<double>(tpv[j - 1]) + tpv[j])) / 
		(float)2.;
/* SOURCE bridge.for:563 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE bridge.for:564 */
/*<       return >*/
    return 0;
/* SOURCE bridge.for:565 */
/*<       end >*/
} /* cpta_ */




/* SOURCE bridge.for:569 */
/*<       subroutineskadj(bskew,pskew,ptype,plen,npz,npnt,pwidth,x) >*/
/* Subroutine */ int skadj_(real *bskew, real *pskew, integer *ptype, real *
	plen, integer *npz, integer *npnt, real *feq_storage_pwidth, real *feq_storage_x)
{
    /* Initialized data */

    static real drad = (float)57.3;

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    double sin(doublereal), cos(doublereal);

    /* Local variables */
    integer j;
    real pw, fac;

/*     + + + PURPOSE + + + */
/*     Adjust opening and piers for skew. */
/* SOURCE bridge.for:576 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE bridge.for:579 */
/*<       integernpnt,npz,ptype >*/
/* SOURCE bridge.for:580 */
/*<       realbskew,plen,pskew,pwidth(npz),x(npnt) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     BSKEW  - Skew of bridge crossing */
/*     PSKEW  - Pier skew */
/*     PTYPE  - Code for pier type */
/*     PLEN   - Pier length */
/*     NPZ    - Number of values */
/*     NPNT   - Number of points on boundary of a cross section */
/*     PWIDTH - Pier width */
/*     X      - Offsets defining bridge opening */
/*     + + + SAVED VALUES + + + */
/* SOURCE bridge.for:593 */
/*<       realdrad >*/
/* SOURCE bridge.for:594 */
/*<       savedrad >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE bridge.for:597 */
/*<       integerj >*/
/* SOURCE bridge.for:598 */
/*<       realfac,pw >*/
/*     + + + INTRINSICS + + + */
/* SOURCE bridge.for:601 */
/*<       intrinsiccos,sin >*/
/*     + + + DATA INITIALIZATIONS + + + */
/* *********************************************************************** */
/* SOURCE bridge.for:604 */
/*<       datadrad/57.3/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> pwidth(feq_storage_pwidth, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    /* Function Body */
/* SOURCE bridge.for:606 */
/*<       if(pskew.le.0.0.or.ptype.eq.0)goto300 >*/
    if (*pskew <= (float)0. || *ptype == 0) {
	goto L300;
    }
/*       ADJUST THE WIDTH OF PIER FOR SKEWNESS */
/* SOURCE bridge.for:610 */
/*<       fac=pskew/drad >*/
    fac = static_cast<double>(*pskew) / drad;
/* SOURCE bridge.for:611 */
/*<       fac=sin(fac)*plen >*/
    fac = sin(fac) * *plen;
/* SOURCE bridge.for:612 */
/*<       do200j=1,npz >*/
    feq_gen_i_d_1 = *npz;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE bridge.for:613 */
/*<       pw=pwidth(j) >*/
	pw = pwidth[j];
/* SOURCE bridge.for:614 */
/*<       if(fac.gt.2.*pw)goto100 >*/
	if (fac > static_cast<double>(pw) * (float)2.) {
	    goto L100;
	}
/* SOURCE bridge.for:615 */
/*<       pwidth(j)=pw+fac >*/
	pwidth[j] = static_cast<double>(pw) + fac;
/* SOURCE bridge.for:616 */
/*<       goto110 >*/
	goto L110;
/* SOURCE bridge.for:617 */
/*<   100 continue >*/
L100:
/* SOURCE bridge.for:618 */
/*<       pwidth(j)=3.*pw >*/
	pwidth[j] = static_cast<double>(pw) * (float)3.;
/* SOURCE bridge.for:619 */
/*<   110 continue >*/
L110:
/* SOURCE bridge.for:620 */
/*<   200 continue >*/
/* L200: */
	;
    }
/* SOURCE bridge.for:622 */
/*<   300 continue >*/
L300:
/* SOURCE bridge.for:624 */
/*<       if(bskew.le.0.0)goto500 >*/
    if (*bskew <= (float)0.) {
	goto L500;
    }
/*       ADJUST BRIDGE OPENING FOR SKEW BY MULTIPLYING */
/*       ALL OFFSETS BY THE COSINE OF THE SKEW ANGLE. */
/* SOURCE bridge.for:629 */
/*<       fac=bskew/drad >*/
    fac = static_cast<double>(*bskew) / drad;
/* SOURCE bridge.for:630 */
/*<       fac=cos(fac) >*/
    fac = cos(fac);
/* SOURCE bridge.for:631 */
/*<       do400j=1,npnt >*/
    feq_gen_i_d_1 = *npnt;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE bridge.for:632 */
/*<       x(j)=x(j)*fac >*/
	x[j] *= static_cast<double>(fac);
/* SOURCE bridge.for:633 */
/*<   400 continue >*/
/* L400: */
    }
/* SOURCE bridge.for:634 */
/*<   500 continue >*/
L500:
/* SOURCE bridge.for:635 */
/*<       return >*/
    return 0;
/* SOURCE bridge.for:636 */
/*<       end >*/
} /* skadj_ */




/* SOURCE bridge.for:640 */
/*<       subroutineinbrid(stdin,stdout,tabdir,eflag,ftnum,label) >*/
/* Subroutine */ int inbrid_(integer *stdin, integer *stdout, integer *feq_storage_tabdir,
	 integer *eflag, integer *ftnum, integer *feq_storage_label)
{
    /* Initialized data */

    static char rdflow[8+1] = "RDFLOW  ";

    /* Format strings */
    static char fmt_1[] = "(20a4)";
    static char fmt_2[] = "(12x,i5)";
    static char fmt_3[] = "(19x,i5)";
    static char fmt_4[] = "(12x,f10.0)";
    static char fmt_5[] = "(18x,f10.0)";
    static char fmt_6[] = "(16x,f10.0)";
    static char fmt_7[] = "(18x,f10.0)";
    static char fmt_8[] = "(10x,i5)";
    static char fmt_9[] = "(12x,f10.0)";
    static char fmt_10[] = "(10x,f10.0)";
    static char fmt_11[] = "(f10.0,i5,f10.0)";
    static char fmt_12[] = "(5x,a8)";
    static char fmt_51[] = "(\002 \002,20a4)";
    static char fmt_52[] = "(\002 \002,\002BASE CURVE#=\002,i5)";
    static char fmt_53[] = "(\0020*ERR:513 BASE CURVE# > 3 OR < 1.\002)";
    static char fmt_54[] = "(\002 \002,\002ABUTMENT ALIGNMENT=\002,i5)";
    static char fmt_55[] = "(\002 BRIDGE SKEW=\002,f10.2)";
    static char fmt_56[] = "(\0020*WRN:507*BRIDGE SKEW < 0 OR > 45. RESET \
TO:\002,f8.1,\002 DEGREES.\002)";
    static char fmt_57[] = "(\002 ADJUSTMENT FACTOR=\002,f10.2)";
    static char fmt_58[] = "(\002 UPSTREAM OFFSET=\002,f10.2)";
    static char fmt_59[] = "(\002 DOWNSTREAM OFFSET=\002,f10.2)";
    static char fmt_60[] = "(\002 PIER TYPE=\002,i5)";
    static char fmt_61[] = "(\002 *ERR:514* PIER TYPE < 0 OR > 8.\002)";
    static char fmt_62[] = "(\002 PIER LENGTH=\002,f10.2)";
    static char fmt_63[] = "(\002 PIER SKEW=\002,f10.2)";
    static char fmt_64[] = "(\002 *WRN:508* PIER SKEW < 0. RESET TO:\002,f10\
.2)";
    static char fmt_65[] = "(\002 *ERR:515* NUMBER OF ENTRIES IN PIER NUMBER\
-WIDTH\002,\002 TABLE >\002,i5)";
    static char fmt_66[] = "(\002 \002,f10.2,i5,f10.2)";
    static char fmt_67[] = "(\0020*ERR:516* ELEVATION FOR PIER NUMBER-WIDTH \
TABLE IS\002,\002 DECREASING AT:\002,f10.2)";
    static char fmt_68[] = "(\002 BRIDGE TYPE=\002,a8)";
    static char fmt_69[] = "(\0020*ERR:517* ONLY TYPE RDFLOW IS VALID FOR A \
BRIDGE\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(), 
	    s_wsfe(cilist *), e_wsfe(), s_cmp(char *, char *, ftnlen, ftnlen),
	     s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer head[20], mode;
    char line[80];
    real left, zold;
    char zone[8];
    real zmax;
    char feq_gen_type_d_[8], hgrid[8];
    real right;
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen),
	     infeqx_(integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, real *, integer *, integer *, integer *, 
	    real *, real *, integer *, real *, real *, real *, char *, char *,
	     char *, real *, char *, char *, char *, char *, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen, ftnlen);
    char betopt[8], outopt[8], savopt[8], vdatum[8], unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__78 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__80 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__81 = { 0, 0, 0, fmt_69, 0 };
    static cilist feq_gen_io_d__82 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__83 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__84 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__85 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__86 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__87 = { 0, 0, 0, fmt_57, 0 };
    static cilist feq_gen_io_d__88 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__89 = { 0, 0, 0, fmt_59, 0 };
    static cilist feq_gen_io_d__90 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__91 = { 0, 0, 0, fmt_61, 0 };
    static cilist feq_gen_io_d__92 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__93 = { 0, 0, 0, fmt_63, 0 };
    static cilist feq_gen_io_d__94 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__96 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__97 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__99 = { 0, 0, 0, fmt_65, 0 };
    static cilist feq_gen_io_d__100 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__101 = { 0, 0, 0, fmt_67, 0 };
    static cilist feq_gen_io_d__113 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__114 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Input a bridge description. */
/* SOURCE bridge.for:648 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE bridge.for:651 */
/*<       integereflag,ftnum,stdin,stdout >*/
/* SOURCE bridge.for:652 */
/*<       integerlabel(20),tabdir(*) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     TABDIR - Table directory to remember table numbers */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     FTNUM  - function table counter */
/*     LABEL  - Label for identification */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE bridge.for:663 */
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
/* INCLUDE bridge.for:664 */
/*     COMMON FOR THE BRIDGE CROSS SECTION */

/* SOURCE xscomb.cmn:3 */
/*<       integernpntb,nsubb,navmb,tabb,ndepb,mxpntb >*/
/* SOURCE xscomb.cmn:4 */
/*<       integersbb(pmxpnt) >*/
/* SOURCE xscomb.cmn:5 */
/*<       realstatb,zminb,zmaxb >*/
/* SOURCE xscomb.cmn:6 */
/*<       realxb(pmxpnt),zb(pmxpnt),nb(pmxsub),xstb(pmxpnt,pmxelm) >*/

/* SOURCE xscomb.cmn:8 */
/*<        >*/
/* INCLUDE bridge.for:665 */
/*     COMMON FOR BRIDGES */
/* SOURCE bridge.cmn:3 */
/*<       integerbscurv,abtype,ptype,ftype,npz,maxnpz >*/
/* SOURCE bridge.cmn:4 */
/*<       integerpnum(25) >*/
/* SOURCE bridge.cmn:5 */
/*<       realbskew,pskew,plen,adjfac,cntru,cntrd >*/
/* SOURCE bridge.cmn:6 */
/*<       realpz(25),pwidth(25),tpv(25),apv(25) >*/
/* SOURCE bridge.cmn:8 */
/*<        >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE bridge.for:668 */
/*<       characterrdflow*8 >*/
/* SOURCE bridge.for:669 */
/*<       saverdflow >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE bridge.for:672 */
/*<       integermode >*/
/* SOURCE bridge.for:673 */
/*<       integerhead(20) >*/
/* SOURCE bridge.for:674 */
/*<       realleft,right,zmax,zold >*/
/* SOURCE bridge.for:675 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE bridge.for:679 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE bridge.for:682 */
/*<       externalinfeqx,inline >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + INPUT FORMATS + + + */
/* SOURCE bridge.for:685 */
/*<       datardflow/'RDFLOW'/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> label(feq_storage_label, 1);

    feq::IndexedPointer<integer> tabdir(feq_storage_tabdir, 1);

    /* Function Body */
/* SOURCE bridge.for:688 */
/*<     1 format(20a4) >*/
/* L1: */
/* SOURCE bridge.for:689 */
/*<     2 format(12x,i5) >*/
/* L2: */
/* SOURCE bridge.for:690 */
/*<     3 format(19x,i5) >*/
/* L3: */
/* SOURCE bridge.for:691 */
/*<     4 format(12x,f10.0) >*/
/* L4: */
/* SOURCE bridge.for:692 */
/*<     5 format(18x,f10.0) >*/
/* L5: */
/* SOURCE bridge.for:693 */
/*<     6 format(16x,f10.0) >*/
/* L6: */
/* SOURCE bridge.for:694 */
/*<     7 format(18x,f10.0) >*/
/* L7: */
/* SOURCE bridge.for:695 */
/*<     8 format(10x,i5) >*/
/* L8: */
/* SOURCE bridge.for:696 */
/*<     9 format(12x,f10.0) >*/
/* L9: */
/* SOURCE bridge.for:697 */
/*<    10 format(10x,f10.0) >*/
/* L10: */
/* SOURCE bridge.for:698 */
/*<    11 format(f10.0,i5,f10.0) >*/
/* L11: */
/* SOURCE bridge.for:699 */
/*<    12 format(5x,a8) >*/
/* L12: */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE bridge.for:702 */
/*<    51 format(' ',20a4) >*/
/* L51: */
/* SOURCE bridge.for:703 */
/*<    52 format(' ','BASE CURVE#=',i5) >*/
/* L52: */
/* SOURCE bridge.for:704 */
/*<    53 format('0*ERR:513 BASE CURVE# > 3 OR < 1.') >*/
/* L53: */
/* SOURCE bridge.for:705 */
/*<    54 format(' ','ABUTMENT ALIGNMENT=',i5) >*/
/* L54: */
/* SOURCE bridge.for:706 */
/*<    55 format(' BRIDGE SKEW=',f10.2) >*/
/* L55: */
/* SOURCE bridge.for:707 */
/*<    56  >*/
/* L56: */
/* SOURCE bridge.for:709 */
/*<    57 format(' ADJUSTMENT FACTOR=',f10.2) >*/
/* L57: */
/* SOURCE bridge.for:710 */
/*<    58 format(' UPSTREAM OFFSET=',f10.2) >*/
/* L58: */
/* SOURCE bridge.for:711 */
/*<    59 format(' DOWNSTREAM OFFSET=',f10.2) >*/
/* L59: */
/* SOURCE bridge.for:712 */
/*<    60 format(' PIER TYPE=',i5) >*/
/* L60: */
/* SOURCE bridge.for:713 */
/*<    61 format(' *ERR:514* PIER TYPE < 0 OR > 8.') >*/
/* L61: */
/* SOURCE bridge.for:714 */
/*<    62 format(' PIER LENGTH=',f10.2) >*/
/* L62: */
/* SOURCE bridge.for:715 */
/*<    63 format(' PIER SKEW=',f10.2) >*/
/* L63: */
/* SOURCE bridge.for:716 */
/*<    64 format(' *WRN:508* PIER SKEW < 0. RESET TO:',f10.2) >*/
/* L64: */
/* SOURCE bridge.for:717 */
/*<    65  >*/
/* L65: */
/* SOURCE bridge.for:719 */
/*<    66 format(' ',f10.2,i5,f10.2) >*/
/* L66: */
/* SOURCE bridge.for:720 */
/*<    67  >*/
/* L67: */
/* SOURCE bridge.for:722 */
/*<    68 format(' BRIDGE TYPE=',a8) >*/
/* L68: */
/* SOURCE bridge.for:723 */
/*<    69 format('0*ERR:517* ONLY TYPE RDFLOW IS VALID FOR A BRIDGE') >*/
/* L69: */
/* *********************************************************************** */
/* SOURCE bridge.for:725 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE bridge.for:728 */
/*<       read(line,1,err=991)label >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_1;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_20, (char *)&label[1], (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE bridge.for:729 */
/*<       write(stdout,51)label >*/
    feq_gen_io_d__78.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__78);
    do_fio(&feq_gen_c_d_20, (char *)&label[1], (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE bridge.for:731 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE bridge.for:734 */
/*<       read(line,12,err=991)type >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, feq_gen_type_d_, (ftnlen)8);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE bridge.for:735 */
/*<       write(stdout,68)type >*/
    feq_gen_io_d__80.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__80);
    do_fio(&feq_gen_c_d_1, feq_gen_type_d_, (ftnlen)8);
    e_wsfe();
/* SOURCE bridge.for:736 */
/*<       ftype=0 >*/
    bridge_1.ftype = 0;
/* SOURCE bridge.for:737 */
/*<       if(type.eq.rdflow)ftype=1 >*/
    if (s_cmp(feq_gen_type_d_, rdflow, (ftnlen)8, (ftnlen)8) == 0) {
	bridge_1.ftype = 1;
    }
/* SOURCE bridge.for:738 */
/*<       if(type.ne.rdflow)then >*/
    if (s_cmp(feq_gen_type_d_, rdflow, (ftnlen)8, (ftnlen)8) != 0) {
/* SOURCE bridge.for:739 */
/*<       write(stdout,69) >*/
	feq_gen_io_d__81.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__81);
	e_wsfe();
/* SOURCE bridge.for:740 */
/*<       eflag=eflag+1 >*/
	++(*eflag);
/* SOURCE bridge.for:741 */
/*<       endif >*/
    }
/* SOURCE bridge.for:742 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE bridge.for:745 */
/*<       read(line,2,err=991)bscurv >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&bridge_1.bscurv, (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE bridge.for:746 */
/*<       write(stdout,52)bscurv >*/
    feq_gen_io_d__82.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__82);
    do_fio(&feq_gen_c_d_1, (char *)&bridge_1.bscurv, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE bridge.for:747 */
/*<       if(bscurv.ge.1.and.bscurv.le.3)goto100 >*/
    if (bridge_1.bscurv >= 1 && bridge_1.bscurv <= 3) {
	goto L100;
    }
/* SOURCE bridge.for:748 */
/*<       bscurv=1 >*/
    bridge_1.bscurv = 1;
/* SOURCE bridge.for:749 */
/*<       write(stdout,53) >*/
    feq_gen_io_d__83.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__83);
    e_wsfe();
/* SOURCE bridge.for:750 */
/*<       eflag=eflag+1 >*/
    ++(*eflag);
/* SOURCE bridge.for:751 */
/*<   100 continue >*/
L100:
/* SOURCE bridge.for:753 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE bridge.for:756 */
/*<       read(line,3,err=991)abtype >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_3;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&bridge_1.abtype, (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE bridge.for:757 */
/*<       write(stdout,54)abtype >*/
    feq_gen_io_d__84.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__84);
    do_fio(&feq_gen_c_d_1, (char *)&bridge_1.abtype, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE bridge.for:758 */
/*<       if(abtype.gt.0)abtype=1 >*/
    if (bridge_1.abtype > 0) {
	bridge_1.abtype = 1;
    }
/* SOURCE bridge.for:760 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE bridge.for:763 */
/*<       read(line,4,err=991)bskew >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&bridge_1.bskew, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE bridge.for:764 */
/*<       write(stdout,55)bskew >*/
    feq_gen_io_d__85.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__85);
    do_fio(&feq_gen_c_d_1, (char *)&bridge_1.bskew, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE bridge.for:765 */
/*<       if(bskew.ge.0.and.bskew.le.45)goto110 >*/
    if (bridge_1.bskew >= (float)0. && bridge_1.bskew <= (float)45.) {
	goto L110;
    }
/* SOURCE bridge.for:766 */
/*<       if(bskew.lt.0)bskew=abs(bskew) >*/
    if (bridge_1.bskew < (float)0.) {
	bridge_1.bskew = dabs(bridge_1.bskew);
    }
/* SOURCE bridge.for:767 */
/*<       if(bskew.gt.45.)bskew=45. >*/
    if (bridge_1.bskew > (float)45.) {
	bridge_1.bskew = (float)45.;
    }
/* SOURCE bridge.for:768 */
/*<       write(stdout,56)bskew >*/
    feq_gen_io_d__86.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__86);
    do_fio(&feq_gen_c_d_1, (char *)&bridge_1.bskew, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE bridge.for:769 */
/*<   110 continue >*/
L110:
/* SOURCE bridge.for:771 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE bridge.for:774 */
/*<       read(line,5,err=991)adjfac >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_5;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&bridge_1.adjfac, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE bridge.for:775 */
/*<       write(stdout,57)adjfac >*/
    feq_gen_io_d__87.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__87);
    do_fio(&feq_gen_c_d_1, (char *)&bridge_1.adjfac, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE bridge.for:777 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE bridge.for:780 */
/*<       read(line,6,err=991)cntru >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&bridge_1.cntru, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE bridge.for:781 */
/*<       write(stdout,58)cntru >*/
    feq_gen_io_d__88.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__88);
    do_fio(&feq_gen_c_d_1, (char *)&bridge_1.cntru, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE bridge.for:783 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE bridge.for:786 */
/*<       read(line,7,err=991)cntrd >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_7;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&bridge_1.cntrd, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE bridge.for:787 */
/*<       write(stdout,59)cntrd >*/
    feq_gen_io_d__89.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__89);
    do_fio(&feq_gen_c_d_1, (char *)&bridge_1.cntrd, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE bridge.for:789 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE bridge.for:792 */
/*<       read(line,8,err=991)ptype >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&bridge_1.ptype, (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE bridge.for:793 */
/*<       write(stdout,60)ptype >*/
    feq_gen_io_d__90.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__90);
    do_fio(&feq_gen_c_d_1, (char *)&bridge_1.ptype, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE bridge.for:795 */
/*<       if(ptype.ge.0.and.ptype.le.8)goto120 >*/
    if (bridge_1.ptype >= 0 && bridge_1.ptype <= 8) {
	goto L120;
    }
/* SOURCE bridge.for:796 */
/*<       write(stdout,61) >*/
    feq_gen_io_d__91.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__91);
    e_wsfe();
/* SOURCE bridge.for:797 */
/*<       eflag=eflag+1 >*/
    ++(*eflag);
/* SOURCE bridge.for:798 */
/*<       ptype=1 >*/
    bridge_1.ptype = 1;
/* SOURCE bridge.for:799 */
/*<   120 continue >*/
L120:
/* SOURCE bridge.for:801 */
/*<       if(ptype.gt.0)goto130 >*/
    if (bridge_1.ptype > 0) {
	goto L130;
    }
/* SOURCE bridge.for:802 */
/*<       npz=0 >*/
    bridge_1.npz = 0;
/* SOURCE bridge.for:803 */
/*<       goto180 >*/
    goto L180;
/* SOURCE bridge.for:804 */
/*<   130 continue >*/
L130:
/*     INPUT PIER DESCRIPTION */
/* SOURCE bridge.for:808 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE bridge.for:811 */
/*<       read(line,9,err=991)plen >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_9;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&bridge_1.plen, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE bridge.for:812 */
/*<       write(stdout,62)plen >*/
    feq_gen_io_d__92.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__92);
    do_fio(&feq_gen_c_d_1, (char *)&bridge_1.plen, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE bridge.for:814 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE bridge.for:817 */
/*<       read(line,10,err=991)pskew >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&bridge_1.pskew, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE bridge.for:818 */
/*<       write(stdout,63)pskew >*/
    feq_gen_io_d__93.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__93);
    do_fio(&feq_gen_c_d_1, (char *)&bridge_1.pskew, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE bridge.for:820 */
/*<       if(pskew.ge.0.)goto140 >*/
    if (bridge_1.pskew >= (float)0.) {
	goto L140;
    }
/* SOURCE bridge.for:821 */
/*<       pskew=abs(pskew) >*/
    bridge_1.pskew = dabs(bridge_1.pskew);
/* SOURCE bridge.for:822 */
/*<       write(stdout,64)pskew >*/
    feq_gen_io_d__94.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__94);
    do_fio(&feq_gen_c_d_1, (char *)&bridge_1.pskew, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE bridge.for:823 */
/*<   140 continue >*/
L140:
/* SOURCE bridge.for:825 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE bridge.for:828 */
/*<       read(line,1,err=991)head >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_1;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_20, (char *)&head[0], (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE bridge.for:829 */
/*<       write(stdout,51)head >*/
    feq_gen_io_d__96.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__96);
    do_fio(&feq_gen_c_d_20, (char *)&head[0], (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE bridge.for:831 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE bridge.for:834 */
/*<       read(line,1,err=991)head >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_1;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_20, (char *)&head[0], (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE bridge.for:835 */
/*<       write(stdout,51)head >*/
    feq_gen_io_d__97.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__97);
    do_fio(&feq_gen_c_d_20, (char *)&head[0], (ftnlen)sizeof(integer));
    e_wsfe();
/*     INPUT THE PIER NUMBER-WIDTH TABLE */
/* SOURCE bridge.for:839 */
/*<       npz=0 >*/
    bridge_1.npz = 0;
/* SOURCE bridge.for:840 */
/*<       zold=-1.e30 >*/
    zold = (float)-1e30;
/* SOURCE bridge.for:842 */
/*<   150 continue >*/
L150:
/* SOURCE bridge.for:843 */
/*<       npz=npz+1 >*/
    ++bridge_1.npz;
/* SOURCE bridge.for:844 */
/*<       if(npz.le.maxnpz)goto160 >*/
    if (bridge_1.npz <= bridge_1.maxnpz) {
	goto L160;
    }
/* SOURCE bridge.for:845 */
/*<       write(stdout,65)maxnpz >*/
    feq_gen_io_d__99.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__99);
    do_fio(&feq_gen_c_d_1, (char *)&bridge_1.maxnpz, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE bridge.for:846 */
/*<       npz=maxnpz >*/
    bridge_1.npz = bridge_1.maxnpz;
/* SOURCE bridge.for:847 */
/*<       eflag=eflag+1 >*/
    ++(*eflag);
/* SOURCE bridge.for:848 */
/*<   160 continue >*/
L160:
/* SOURCE bridge.for:850 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE bridge.for:853 */
/*<       read(line,11,err=991)pz(npz),pnum(npz),pwidth(npz) >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_11;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&bridge_1.pz[bridge_1.npz - 1], (ftnlen)
	    sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&bridge_1.pnum[bridge_1.npz - 1], (ftnlen)
	    sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&bridge_1.pwidth[bridge_1.npz - 1], (ftnlen)
	    sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE bridge.for:854 */
/*<       write(stdout,66)pz(npz),pnum(npz),pwidth(npz) >*/
    feq_gen_io_d__100.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__100);
    do_fio(&feq_gen_c_d_1, (char *)&bridge_1.pz[bridge_1.npz - 1], (ftnlen)sizeof(real)
	    );
    do_fio(&feq_gen_c_d_1, (char *)&bridge_1.pnum[bridge_1.npz - 1], (ftnlen)sizeof(
	    integer));
    do_fio(&feq_gen_c_d_1, (char *)&bridge_1.pwidth[bridge_1.npz - 1], (ftnlen)sizeof(
	    real));
    e_wsfe();
/* SOURCE bridge.for:856 */
/*<       if(pwidth(npz).lt.0.)goto180 >*/
    if (bridge_1.pwidth[bridge_1.npz - 1] < (float)0.) {
	goto L180;
    }
/* SOURCE bridge.for:857 */
/*<       if(pz(npz).gt.zold)goto170 >*/
    if (bridge_1.pz[bridge_1.npz - 1] > zold) {
	goto L170;
    }
/* SOURCE bridge.for:858 */
/*<       write(stdout,67)zold >*/
    feq_gen_io_d__101.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__101);
    do_fio(&feq_gen_c_d_1, (char *)&zold, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE bridge.for:859 */
/*<       eflag=eflag+1 >*/
    ++(*eflag);
/* SOURCE bridge.for:860 */
/*<   170 continue >*/
L170:
/* SOURCE bridge.for:861 */
/*<       zold=pz(npz) >*/
    zold = bridge_1.pz[bridge_1.npz - 1];
/* SOURCE bridge.for:862 */
/*<       goto150 >*/
    goto L150;
/* SOURCE bridge.for:864 */
/*<   180 continue >*/
L180:
/*     ADJUST NPZ FOR THE EXTRA LINE READ */
/* SOURCE bridge.for:868 */
/*<       npz=npz-1 >*/
    --bridge_1.npz;
/*     INPUT A STANDARD CROSS SECTION TABLE- */
/* SOURCE bridge.for:871 */
/*<       mode=2 >*/
    mode = 2;
/* SOURCE bridge.for:872 */
/*<        >*/
    infeqx_(stdin, stdout, &xscomb_1.mxpntb, &mode, &tabdir[1], eflag, &
	    xscomb_1.tabb, &xscomb_1.statb, &xscomb_1.npntb, &xscomb_1.nsubb, 
	    &xscomb_1.navmb, xscomb_1.xb, xscomb_1.zb, xscomb_1.sbb, 
	    xscomb_1.nb, &left, &right, savopt, outopt, betopt, &zmax, zone, 
	    hgrid, vdatum, unitsys, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)
	    8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE bridge.for:879 */
/*<       ftnum=tabb >*/
    *ftnum = xscomb_1.tabb;
/* SOURCE bridge.for:881 */
/*<       return >*/
    return 0;
/* SOURCE bridge.for:882 */
/*<   991 continue >*/
L991:
/* SOURCE bridge.for:883 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__113.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__113);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE bridge.for:884 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__114.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__114);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE bridge.for:885 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE bridge.for:886 */
/*<       end >*/
    return 0;
} /* inbrid_ */




/* SOURCE bridge.for:890 */
/*<       subroutinespbrid(stdin,stdout,stdtab,nfac,tabdir,eflag) >*/
/* Subroutine */ int spbrid_(integer *stdin, integer *stdout, integer *stdtab,
	 real *nfac, integer *feq_storage_tabdir, integer *eflag)
{
    /* Format strings */
    static char fmt_20[] = "(\002*ERR:511* UPSTREAM CROSS SECTION MISSING FO\
R BRIDGE\002)";
    static char fmt_30[] = "(\0020*ERR:512* DOWNSTREAM CROSS SECTION MISSIN\
G\002,\002 FOR BRIDGE\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    char betaflag[1*999];
    integer feq_gen_i_d_, j;
    real m;
    char alphaflag[1*999];
    real ab, ad, ap, tb, ku, tp, bwb, bwd, snb[999];
    integer ftp;
    real zup, xsv[22];
    integer ltab;
    extern /* Subroutine */ int cpta_(integer *, real *, integer *, real *, 
	    real *, real *);
    real kold[200], left, lsnb[999];
    extern /* Subroutine */ int xlka_(real *, integer *, real *, real *, real 
	    *, real *, real *);
    integer nnyb[200];
    char zone[8];
    real zdwn;
    integer wrn557, label[20];
    extern /* Subroutine */ int skadj_(real *, real *, integer *, real *, 
	    integer *, integer *, real *, real *);
    char hgrid[8], basis[8];
    integer ftnum, nvarb[200];
    real natyb[1800]	/* was [9][200] */, right, tbmax, tsold[200], yatnb[
	    1800]	/* was [9][200] */;
    extern /* Subroutine */ int mcomp_(integer *, real *, real *, real *, 
	    real *, integer *, integer *, integer *, real *, real *, integer *
	    , real *, real *, real *, integer *, real *, real *);
    integer eflagi;
    real alphab, alphad;
    char maflag[1*999], khflag[1*999];
    extern /* Subroutine */ int bwcoef_(integer *, real *, integer *, real *, 
	    integer *, real *, real *, real *, real *);
    char mqflag[1*999];
    real alphau;
    integer snflgb;
    extern /* Subroutine */ int compel_(real *, integer *, integer *, integer 
	    *, real *, real *, integer *, real *, char *, integer *, real *, 
	    integer *, real *, real *, integer *, real *, integer *, real *, 
	    real *, real *, real *, ftnlen), cxstab_(integer *, integer *, 
	    integer *, real *, integer *, real *, real *, char *, integer *, 
	    integer *, real *, real *, integer *, integer *, real *, real *, 
	    real *, real *, integer *, integer *, real *, real *, real *, 
	    integer *, real *, ftnlen), inbrid_(integer *, integer *, integer 
	    *, integer *, integer *, integer *);
    integer npztmp;
    char betopt[8], outopt[8], savopt[8], vdatum[8];
    extern /* Subroutine */ int inelev_(integer *, integer *, real *, real *, 
	    integer *, real *, integer *), sptout_(integer *, integer *, 
	    integer *, integer *, integer *, real *, real *), tabout_(integer 
	    *, integer *, integer *, real *, real *, integer *, char *, char *
	    , char *, char *, char *, char *, char *, char *, char *, char *, 
	    char *, char *, char *, integer *, real *, integer *, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen), xlkall_(integer *, integer *, 
	    real *, real *), xsecfit_(integer *, integer *, integer *, real *,
	     char *, char *, char *, char *, char *, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen);
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__126 = { 0, 0, 0, fmt_20, 0 };
    static cilist feq_gen_io_d__127 = { 0, 0, 0, fmt_30, 0 };


/*     + + + PURPOSE + + + */
/*     Compute special bridge table giving the energy loss coef. */
/*     for application to the downstream velocity head(FTYPE=0) */
/*     or to the nominal velocity head in the bridge opening(FTYPE=1). */
/*     all elevations(in bridge opening, in upstream cross section, and */
/*     in downstream cross section) are computed from the depth in the */
/*     bridge opening.  Note that the theory also requires that the */
/*     elements of the upstream cross section be computed at the */
/*     downstream depth.  All this implies that the elevation of the */
/*     minimum point in the bridge opening, in the upstream cross */
/*     section, and in the downstream cross section must be identical */
/*     when the generated tables are used in FEQ. */
/* SOURCE bridge.for:907 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE bridge.for:910 */
/*<       integereflag,stdin,stdout,stdtab >*/
/* SOURCE bridge.for:911 */
/*<       integertabdir(*) >*/
/* SOURCE bridge.for:912 */
/*<       realnfac >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     NFAC   - Factor in Manning's formula(1.49 or 1.0) */
/*     TABDIR - Table directory to remember table numbers */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE bridge.for:923 */
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
/* INCLUDE bridge.for:924 */
/*     COMMON FOR THE DOWNSTREAM CROSS SECTION */

/* SOURCE xscomd.cmn:3 */
/*<       integernpntd,nsubd,navmd,tabd,ndepd,mxpntd,usgsd,snflgd >*/
/* SOURCE xscomd.cmn:4 */
/*<       integersbd(pmxpnt),nvard(pmxsub),nnyd(pmxsub) >*/
/* SOURCE xscomd.cmn:5 */
/*<       realstatd,zmind,zmaxd >*/
/* SOURCE xscomd.cmn:6 */
/*<        >*/

/* SOURCE xscomd.cmn:10 */
/*<        >*/
/*     SNFLGD- FLAG FOR SINUOSITY ELEMENTS: 0-none; 1-sinuosity */
/*             piecewise linear between boundary points; and 2-sinuousity */
/*             piecewise constant between boundary points.  For piecewise */
/*             constant variation, the value of sinuousity for the line */
/*             segment is given at the start point for the line segment. */
/*     SND- SINUOITY AT POINTS OR SUBSECTIONS */
/*     LSND- LINE SEGMENT N VALUE */
/*     NVARD- VARIATION OF N WITH DEPTH FLAG.  THREE CASES: N IS CONSTANT, */
/*           N VARIES WITH HYDRAULIC DEPTH IN EACH SUBSECTION, AND */
/*           N VARIES WITH MAXIMUM DEPTH IN EACH SUBSECTION. */
/*     NATYD-  SUBSECTION N VALUE VARING WITH DEPTH.  DEPTH CAN BE */
/*           MAXIMUM DEPTH IN THE SUBSECTION OR HYDRAULIC DEPTH */
/*           IN THE SUBSECTION */
/*     YATND- DEPTH IN THE SUBSECTION FOR EACH N VALUE, NATY. */
/*     NNYD- NUMBER OF PAIRS OF N AND Y IN EACH SUBSECTION DEFINING */
/*          THE VARIATION OF ROUGHNESS. */
/*     YSMXD- MAXIMUM DEPTH IN EACH SUBSECTION */
/* INCLUDE bridge.for:925 */
/*     COMMON FOR THE UPSTREAM CROSS SECTION */

/* SOURCE xscomu.cmn:3 */
/*<       integernpntu,nsubu,navmu,tabu,ndepu,mxpntu,usgsu,snflgu >*/
/* SOURCE xscomu.cmn:4 */
/*<       integersbu(pmxpnt),nvaru(pmxsub),nnyu(pmxsub) >*/
/* SOURCE xscomu.cmn:5 */
/*<       realstatu,zminu,zmaxu >*/
/* SOURCE xscomu.cmn:6 */
/*<        >*/

/* SOURCE xscomu.cmn:10 */
/*<        >*/
/*     SNFLGU- FLAG FOR SINUOSITY ELEMENTS: 0-none; 1-sinuosity */
/*             piecewise linear between boundary points; and 2-sinuousity */
/*             piecewise constant between boundary points. */
/*     SNU- SINUOITY AT POINTS OR SUBSECTIONS */
/*     LSNU- LINE SEGMENT N VALUE */
/*     NVARU- VARIATION OF N WITH DEPTH FLAG.  THREE CASES: 0-N IS CONSTANT, */
/*           1-N VARIES WITH HYDRAULIC DEPTH IN EACH SUBSECTION, AND */
/*           2-N VARIES WITH MAXIMUM DEPTH IN EACH SUBSECTION. */
/*           IF N VARIES WITH DEPTH, THE N VALUE APPLIES TO THE WHOLE */
/*           SUBSECTION.  NO VARIATION OF ROUGHNESS PERMITTED ON LINE SEGMENTS */
/*           IN THE SUBSECTION. */
/*     NATYU-  SUBSECTION N VALUE VARING WITH DEPTH.  DEPTH CAN BE */
/*           MAXIMUM DEPTH IN THE SUBSECTION OR HYDRAULIC DEPTH */
/*           IN THE SUBSECTION */
/*     YATNU- DEPTH IN THE SUBSECTION FOR EACH N VALUE, NATY. */
/*     NNYU- NUMBER OF PAIRS OF N AND Y IN EACH SUBSECTION DEFINING */
/*          THE VARIATION OF ROUGHNESS.  VALUE IS ZERO IF NVARU FOR THE */
/*          SUBSECTION IS ZERO.  THE N DEPTH PAIR AT ZERO DEPTH IS STORED */
/*          AND COUNTED WITH NVARU > 0 FOR THE SUBSECTION. */
/*     YSMXU- MAXIMUM DEPTH IN EACH SUBSECTION. */
/* INCLUDE bridge.for:926 */
/*     COMMON FOR THE BRIDGE CROSS SECTION */

/* SOURCE xscomb.cmn:3 */
/*<       integernpntb,nsubb,navmb,tabb,ndepb,mxpntb >*/
/* SOURCE xscomb.cmn:4 */
/*<       integersbb(pmxpnt) >*/
/* SOURCE xscomb.cmn:5 */
/*<       realstatb,zminb,zmaxb >*/
/* SOURCE xscomb.cmn:6 */
/*<       realxb(pmxpnt),zb(pmxpnt),nb(pmxsub),xstb(pmxpnt,pmxelm) >*/

/* SOURCE xscomb.cmn:8 */
/*<        >*/
/* INCLUDE bridge.for:927 */
/*     NEAR ZERO DEPTH AND DZ COMMON.  ALSO HAS OTHER ITEMS */
/* SOURCE nrdzcm.cmn:3 */
/*<       integerextend,gxtend,nocm,iusgs >*/
/* SOURCE nrdzcm.cmn:5 */
/*<       realnrzero,dzlim,slot >*/
/* SOURCE nrdzcm.cmn:7 */
/*<       common/nrdzcm/nrzero,dzlim,nocm,slot,iusgs,extend,gxtend >*/
/* INCLUDE bridge.for:928 */
/*     COMMON FOR BRIDGES */
/* SOURCE bridge.cmn:3 */
/*<       integerbscurv,abtype,ptype,ftype,npz,maxnpz >*/
/* SOURCE bridge.cmn:4 */
/*<       integerpnum(25) >*/
/* SOURCE bridge.cmn:5 */
/*<       realbskew,pskew,plen,adjfac,cntru,cntrd >*/
/* SOURCE bridge.cmn:6 */
/*<       realpz(25),pwidth(25),tpv(25),apv(25) >*/
/* SOURCE bridge.cmn:8 */
/*<        >*/
/* INCLUDE bridge.for:929 */
/*     COMMON FOR THE FLOW TABLE */
/* SOURCE flotab.cmn:3 */
/*<       integernft,maxnft >*/
/* SOURCE flotab.cmn:4 */
/*<       realzft(25),ftable(20,20),qcritv(25) >*/
/* SOURCE flotab.cmn:6 */
/*<       common/flotab/nft,maxnft,zft,ftable,qcritv >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE bridge.for:932 */
/*<       integereflagi,ftnum,ftp,i,j,ltab,npztmp,snflgb,wrn557 >*/
/* SOURCE bridge.for:933 */
/*<       integerlabel(20),nnyb(pmxsub),nvarb(pmxsub) >*/
/* SOURCE bridge.for:934 */
/*<        >*/
/* SOURCE bridge.for:938 */
/*<        >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE bridge.for:945 */
/*<        >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE bridge.for:949 */
/*<    20 format('*ERR:511* UPSTREAM CROSS SECTION MISSING FOR BRIDGE') >*/
/* SOURCE bridge.for:950 */
/*<    30  >*/
/* *********************************************************************** */
/* SOURCE bridge.for:953 */
/*<       zone='NONE' >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> tabdir(feq_storage_tabdir, 1);

    /* Function Body */
/* L20: */
/* L30: */
    s_copy(zone, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE bridge.for:954 */
/*<       hgrid='NONE' >*/
    s_copy(hgrid, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE bridge.for:955 */
/*<       vdatum='NONE' >*/
    s_copy(vdatum, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE bridge.for:956 */
/*<       unitsys='NONE' >*/
    s_copy(unitsys, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE bridge.for:957 */
/*<       basis='NONE' >*/
    s_copy(basis, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/*     ENABLE CONVEYANCE MESSAGES */
/* SOURCE bridge.for:960 */
/*<       nocm=0 >*/
    nrdzcm_1.nocm = 0;
/* SOURCE bridge.for:961 */
/*<       slot=1.e30 >*/
    nrdzcm_1.slot = (float)1e30;
/*     NULLIFY THE SAVING FUNCTION IN TABOUT */
/* SOURCE bridge.for:963 */
/*<       savopt='NOSAVE' >*/
    s_copy(savopt, const_cast<char*>("NOSAVE"), (ftnlen)8, (ftnlen)6);
/* SOURCE bridge.for:964 */
/*<       outopt='OUT1' >*/
    s_copy(outopt, const_cast<char*>("OUT1"), (ftnlen)8, (ftnlen)4);
/* SOURCE bridge.for:965 */
/*<       betopt='OLDBETA' >*/
    s_copy(betopt, const_cast<char*>("OLDBETA"), (ftnlen)8, (ftnlen)7);
/* SOURCE bridge.for:966 */
/*<       ftp=0 >*/
    ftp = 0;
/*     ENABLE AUTOMATIC EXTENSION */
/* SOURCE bridge.for:969 */
/*<       extend=1 >*/
    nrdzcm_1.extend = 1;
/*     INPUT THE BRIDGE DESCRIPTION */
/* SOURCE bridge.for:973 */
/*<       callinbrid(stdin,stdout,tabdir,eflag,ftnum,label) >*/
    inbrid_(stdin, stdout, &tabdir[1], eflag, &ftnum, label);
/*     CHECK TO MAKE SURE NEEDED UPSTREAM AND DOWNSTREAM CROSS */
/*     SECTIONS ARE DEFINED. */
/* SOURCE bridge.for:981 */
/*<       if(npntu.gt.0)goto50 >*/
    if (xscomu_1.npntu > 0) {
	goto L50;
    }
/* SOURCE bridge.for:982 */
/*<       write(stdout,20) >*/
    feq_gen_io_d__126.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__126);
    e_wsfe();
/* SOURCE bridge.for:983 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE bridge.for:984 */
/*<    50 continue >*/
L50:
/* SOURCE bridge.for:985 */
/*<       if(npntd.gt.0)goto100 >*/
    if (xscomd_1.npntd > 0) {
	goto L100;
    }
/* SOURCE bridge.for:986 */
/*<       write(stdout,30) >*/
    feq_gen_io_d__127.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__127);
    e_wsfe();
/* SOURCE bridge.for:987 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE bridge.for:988 */
/*<   100 continue >*/
L100:
/*     SET THE EXTENDED CROSS SECTION DESCRIPTORS TO THE NULL VALUES. */
/*     THIS ROUTINE IS HOPEFULLY DOOMED SOON! */
/* SOURCE bridge.for:993 */
/*<       snflgb=0 >*/
    snflgb = 0;
/* SOURCE bridge.for:994 */
/*<       snflgu=0 >*/
    xscomu_1.snflgu = 0;
/* SOURCE bridge.for:995 */
/*<       do90i=1,nsubb >*/
    feq_gen_i_d_1 = xscomb_1.nsubb;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE bridge.for:996 */
/*<       natyb(1,i)=0.0 >*/
	natyb[feq_gen_i_d_ * 9 - 9] = (float)0.;
/* SOURCE bridge.for:997 */
/*<       yatnb(1,i)=0.0 >*/
	yatnb[feq_gen_i_d_ * 9 - 9] = (float)0.;
/* SOURCE bridge.for:998 */
/*<       nvarb(i)=0 >*/
	nvarb[feq_gen_i_d_ - 1] = 0;
/* SOURCE bridge.for:999 */
/*<       nnyb(i)=0 >*/
	nnyb[feq_gen_i_d_ - 1] = 0;
/* SOURCE bridge.for:1000 */
/*<       nvaru(i)=0 >*/
	xscomu_1.nvaru[feq_gen_i_d_ - 1] = 0;
/* SOURCE bridge.for:1001 */
/*<       nnyu(i)=0 >*/
	xscomu_1.nnyu[feq_gen_i_d_ - 1] = 0;
/* SOURCE bridge.for:1002 */
/*<    90 continue >*/
/* L90: */
    }
/* SOURCE bridge.for:1003 */
/*<       do91i=1,npntb-1 >*/
    feq_gen_i_d_1 = xscomb_1.npntb - 1;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE bridge.for:1004 */
/*<       lsnb(i)=nb(sbb(i)) >*/
	lsnb[feq_gen_i_d_ - 1] = xscomb_1.nb[xscomb_1.sbb[feq_gen_i_d_ - 1] - 1];
/* SOURCE bridge.for:1005 */
/*<       snb(i)=1.0 >*/
	snb[feq_gen_i_d_ - 1] = (float)1.;
/* SOURCE bridge.for:1006 */
/*<    91 continue >*/
/* L91: */
    }
/* SOURCE bridge.for:1007 */
/*<       lsnb(npntb)=0 >*/
    lsnb[xscomb_1.npntb - 1] = (float)0.;
/* SOURCE bridge.for:1008 */
/*<       snb(npntb)=1.0 >*/
    snb[xscomb_1.npntb - 1] = (float)1.;
/* SOURCE bridge.for:1009 */
/*<       do92i=1,npntu-1 >*/
    feq_gen_i_d_1 = xscomu_1.npntu - 1;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE bridge.for:1010 */
/*<       lsnu(i)=nu(sbu(i)) >*/
	xscomu_1.lsnu[feq_gen_i_d_ - 1] = xscomu_1.nu[xscomu_1.sbu[feq_gen_i_d_ - 1] - 1];
/* SOURCE bridge.for:1011 */
/*<       snu(i)=1.0 >*/
	xscomu_1.snu[feq_gen_i_d_ - 1] = (float)1.;
/* SOURCE bridge.for:1012 */
/*<    92 continue >*/
/* L92: */
    }
/* SOURCE bridge.for:1013 */
/*<       lsnu(npntu)=0 >*/
    xscomu_1.lsnu[xscomu_1.npntu - 1] = (float)0.;
/* SOURCE bridge.for:1014 */
/*<       snu(npntu)=1.0 >*/
    xscomu_1.snu[xscomu_1.npntu - 1] = (float)1.;
/* SOURCE bridge.for:1016 */
/*<       eflagi=0 >*/
    eflagi = 0;
/*     ADJUST BRIDGE OPENING AND BRIDGE PIERS FOR SKEWNESS */
/*     AVOID PROBLEM W/ ZERO DIMENSION */
/* SOURCE bridge.for:1021 */
/*<       npztmp=npz >*/
    npztmp = bridge_1.npz;
/* SOURCE bridge.for:1022 */
/*<       if(npz.le.0)npztmp=1 >*/
    if (bridge_1.npz <= 0) {
	npztmp = 1;
    }
/* SOURCE bridge.for:1024 */
/*<       callskadj(bskew,pskew,ptype,plen,npztmp,npntb,pwidth,xb) >*/
    skadj_(&bridge_1.bskew, &bridge_1.pskew, &bridge_1.ptype, &bridge_1.plen, 
	    &npztmp, &xscomb_1.npntb, bridge_1.pwidth, xscomb_1.xb);
/*     COMPUTE CROSS SECTION TABLE FOR BRIDGE OPENING */
/* SOURCE bridge.for:1030 */
/*<       right=0.0 >*/
    right = (float)0.;
/* SOURCE bridge.for:1031 */
/*<       left=0.0 >*/
    left = (float)0.;
/* SOURCE bridge.for:1032 */
/*<       zminb=9999999.0 >*/
    xscomb_1.zminb = (float)9999999.;
/* SOURCE bridge.for:1033 */
/*<       zmaxb=-9999999.0 >*/
    xscomb_1.zmaxb = (float)-9999999.;
/* SOURCE bridge.for:1034 */
/*<       do140j=1,npntb >*/
    feq_gen_i_d_1 = xscomb_1.npntb;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE bridge.for:1035 */
/*<       if(zb(j).lt.zminb)zminb=zb(j) >*/
	if (xscomb_1.zb[j - 1] < xscomb_1.zminb) {
	    xscomb_1.zminb = xscomb_1.zb[j - 1];
	}
/* SOURCE bridge.for:1036 */
/*<       if(zb(j).gt.zmaxb)zmaxb=zb(j) >*/
	if (xscomb_1.zb[j - 1] > xscomb_1.zmaxb) {
	    xscomb_1.zmaxb = xscomb_1.zb[j - 1];
	}
/* SOURCE bridge.for:1037 */
/*<   140 continue >*/
/* L140: */
    }
/* SOURCE bridge.for:1039 */
/*<        >*/
    cxstab_(stdout, &xscomb_1.nsubb, &xscomb_1.navmb, nfac, &xscomb_1.mxpntb, 
	    &left, &right, betopt, &snflgb, nvarb, natyb, yatnb, nnyb, &
	    xscomb_1.npntb, &xscomb_1.zminb, &xscomb_1.zmaxb, xscomb_1.xb, 
	    xscomb_1.zb, xscomb_1.sbb, &eflagi, lsnb, snb, xscomb_1.nb, &
	    xscomb_1.ndepb, xscomb_1.xstb, (ftnlen)8);
/* SOURCE bridge.for:1045 */
/*<       if(ftype.eq.1)then >*/
    if (bridge_1.ftype == 1) {
/*     compute derivatives of square root of conveyance, alpha, beta, */
/*     da, and dq */
/* SOURCE bridge.for:1050 */
/*<        >*/
	xsecfit_(stdout, &feq_gen_c_d_0, &xscomu_1.ndepu, xscomu_1.xstu, khflag, 
		alphaflag, betaflag, maflag, mqflag, (ftnlen)1, (ftnlen)1, (
		ftnlen)1, (ftnlen)1, (ftnlen)1);
/* SOURCE bridge.for:1055 */
/*<        >*/
	tabout_(stdout, stdtab, &xscomb_1.tabb, &xscomb_1.statb, &
		xscomb_1.zminb, &feq_gen_c_d_0, savopt, outopt, betopt, zone, hgrid, 
		vdatum, unitsys, basis, khflag, alphaflag, betaflag, maflag, 
		mqflag, &xscomb_1.ndepb, xscomb_1.xstb, &ftp, (ftnlen)8, (
		ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)
		8, (ftnlen)8, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1, (
		ftnlen)1);
/* SOURCE bridge.for:1061 */
/*<       endif >*/
    }
/*     COMPUTE WIDTH AND AREA OF PIERS */
/*      WRITE(STDOUT,*) 'IN SPBRID PTYPE=',PTYPE, ' NPZ=',NPZ */
/* SOURCE bridge.for:1066 */
/*<       if(ptype.gt.0)callcpta(npz,pz,pnum,pwidth,tpv,apv) >*/
    if (bridge_1.ptype > 0) {
	cpta_(&bridge_1.npz, bridge_1.pz, bridge_1.pnum, bridge_1.pwidth, 
		bridge_1.tpv, bridge_1.apv);
    }
/*      WRITE(STDOUT,*) ' APV(NPZ)=',APV(NPZ) */
/*     INPUT THE ELEVATIONS FOR THE ENERGY LOSS TABLES */
/* SOURCE bridge.for:1074 */
/*<       nft=21 >*/
    flotab_1.nft = 21;
/* SOURCE bridge.for:1076 */
/*<       callinelev(stdin,stdout,zminb,zmaxb,nft,zft,ltab) >*/
    inelev_(stdin, stdout, &xscomb_1.zminb, &xscomb_1.zmaxb, &flotab_1.nft, 
	    flotab_1.zft, &ltab);
/*     COMPUTE THE ENTRIES IN THE TABLE. FIRST ELEVATION IS AT */
/*     BOTTOM OF THE CHANNEL */
/*     USE MAXIMUM BRIDGE OPENING WIDTH ENCOUNTERED FOR COMPUTATION */
/*     OF M.  TBMAX WILL GIVE THAT VALUE. */
/* SOURCE bridge.for:1086 */
/*<       tbmax=0.0 >*/
    tbmax = (float)0.;
/* SOURCE bridge.for:1088 */
/*<       wrn557=1 >*/
    wrn557 = 1;
/* SOURCE bridge.for:1089 */
/*<       do1000i=2,nft >*/
    feq_gen_i_d_1 = flotab_1.nft;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE bridge.for:1090 */
/*<       zdwn=zft(i) >*/
	zdwn = flotab_1.zft[feq_gen_i_d_ - 1];
/*       FIND ELEMENTS AT DOWNSTREAM SECTION */
/* SOURCE bridge.for:1094 */
/*<       xsv(1)=zdwn-zminb >*/
	xsv[0] = static_cast<double>(zdwn) - xscomb_1.zminb;
/* SOURCE bridge.for:1095 */
/*<       callxlkall(ndepd,mxpntd,xstd,xsv) >*/
	xlkall_(&xscomd_1.ndepd, &xscomd_1.mxpntd, xscomd_1.xstd, xsv);
/* SOURCE bridge.for:1099 */
/*<       ad=xsv(3) >*/
	ad = xsv[2];
/* SOURCE bridge.for:1100 */
/*<       alphad=xsv(7) >*/
	alphad = xsv[6];
/*       FIND ELEMENTS IN BRIDGE OPENING USING DOWNSTREAM DEPTH */
/* SOURCE bridge.for:1104 */
/*<       xsv(1)=zdwn-zminb >*/
	xsv[0] = static_cast<double>(zdwn) - xscomb_1.zminb;
/* SOURCE bridge.for:1105 */
/*<       callxlkall(ndepb,mxpntb,xstb,xsv) >*/
	xlkall_(&xscomb_1.ndepb, &xscomb_1.mxpntb, xscomb_1.xstb, xsv);
/* SOURCE bridge.for:1108 */
/*<       tb=xsv(2) >*/
	tb = xsv[1];
/* SOURCE bridge.for:1109 */
/*<       ab=xsv(3) >*/
	ab = xsv[2];
/*       FIND CURRENT MAXIMUM BRIDGE OPENING WIDTH */
/* SOURCE bridge.for:1113 */
/*<       if(tb.gt.tbmax)tbmax=tb >*/
	if (tb > tbmax) {
	    tbmax = tb;
	}
/*       COMPUTE UPSTREAM ELEMENTS AT THE DOWNSTREAM DEPTH */
/* SOURCE bridge.for:1117 */
/*<       zup=zdwn-zminb+zminu >*/
	zup = static_cast<double>(static_cast<double>(zdwn) - xscomb_1.zminb) + xscomu_1.zminu;
/* SOURCE bridge.for:1118 */
/*<       do110j=1,nsubu >*/
	feq_gen_i_d_2 = xscomu_1.nsubu;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE bridge.for:1119 */
/*<       kold(j)=0.0 >*/
	    kold[j - 1] = (float)0.;
/* SOURCE bridge.for:1120 */
/*<       tsold(j)=1.e30 >*/
	    tsold[j - 1] = (float)1e30;
/* SOURCE bridge.for:1121 */
/*<   110 continue >*/
/* L110: */
	}
/* SOURCE bridge.for:1123 */
/*<        >*/
	compel_(&zup, &xscomu_1.npntu, &xscomu_1.nsubu, &xscomu_1.navmu, 
		xscomu_1.xu, xscomu_1.zu, xscomu_1.sbu, nfac, betopt, &
		xscomu_1.snflgu, xscomu_1.lsnu, xscomu_1.nvaru, 
		xscomu_1.natyu, xscomu_1.yatnu, xscomu_1.nnyu, xscomu_1.snu, &
		wrn557, kold, tsold, xscomu_1.nu, xsv, (ftnlen)8);
/* SOURCE bridge.for:1128 */
/*<       ku=xsv(5)**2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = xsv[4];
	ku = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE bridge.for:1129 */
/*<       alphau=xsv(7) >*/
	alphau = xsv[6];
/*       COMPUTE AREA AND TOP WIDTH OF THE PIERS */
/* SOURCE bridge.for:1133 */
/*<       zup=zdwn-zminb >*/
	zup = static_cast<double>(zdwn) - xscomb_1.zminb;
/* SOURCE bridge.for:1135 */
/*<       tp=0.0 >*/
	tp = (float)0.;
/* SOURCE bridge.for:1136 */
/*<       ap=0.0 >*/
	ap = (float)0.;
/*        WRITE(STDOUT,*) 'BEFORE CALL TO XLKA PTYPE=',PTYPE, ' NPZ=',NPZ */
/*        WRITE(STDOUT,*) 'PZ(1)=',PZ(1),' PZ(NPZ)=',PZ(NPZ) */
/* SOURCE bridge.for:1140 */
/*<       if(ptype.gt.0)callxlka(zup,npz,pz,tpv,apv,tp,ap) >*/
	if (bridge_1.ptype > 0) {
	    xlka_(&zup, &bridge_1.npz, bridge_1.pz, bridge_1.tpv, 
		    bridge_1.apv, &tp, &ap);
	}
/*       COMPUTE CONTRACTION RATIO */
/* SOURCE bridge.for:1146 */
/*<       zup=zdwn-zminb+zminu >*/
	zup = static_cast<double>(static_cast<double>(zdwn) - xscomb_1.zminb) + xscomu_1.zminu;
/* SOURCE bridge.for:1148 */
/*<        >*/
	mcomp_(stdout, &bridge_1.cntru, &tbmax, &zup, &ku, &xscomu_1.npntu, &
		xscomu_1.nsubu, &xscomu_1.navmu, xscomu_1.xu, xscomu_1.zu, 
		xscomu_1.sbu, nfac, xscomu_1.snu, xscomu_1.lsnu, eflag, 
		xscomu_1.nu, &m);
/*     COMPUTE VELOCITY HEAD COEF IN BRIDGE OPENING */
/* SOURCE bridge.for:1157 */
/*<       alphab=1.0+m*(alphau-1.0) >*/
	alphab = static_cast<double>(static_cast<double>(m) * (static_cast<double>(alphau) - (float)1.)) + (float)1.;
/*       COMPUTE BACK WATER COEF FOR THE NOMINAL VELOCITY HEAD */
/*       IN THE BRIDGE OPENING */
/* SOURCE bridge.for:1162 */
/*<       callbwcoef(bscurv,bskew,abtype,adjfac,ptype,m,ap,ab,bwb) >*/
	bwcoef_(&bridge_1.bscurv, &bridge_1.bskew, &bridge_1.abtype, &
		bridge_1.adjfac, &bridge_1.ptype, &m, &ap, &ab, &bwb);
/*       COMPUTE THE COEF TO APPLY TO THE DOWNSTREAM VELOCITY HEAD */
/* SOURCE bridge.for:1168 */
/*<       if(ftype.eq.1)goto500 >*/
	if (bridge_1.ftype == 1) {
	    goto L500;
	}
/* SOURCE bridge.for:1169 */
/*<       bwd=(alphab*bwb*(ad/ab)**2)/alphad >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(ad) / ab;
	bwd = static_cast<double>(static_cast<double>(static_cast<double>(alphab) * bwb) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / alphad;
/* SOURCE bridge.for:1170 */
/*<       goto600 >*/
	goto L600;
/* SOURCE bridge.for:1171 */
/*<   500 continue >*/
L500:
/* SOURCE bridge.for:1172 */
/*<       bwd=alphab*bwb >*/
	bwd = static_cast<double>(alphab) * bwb;
/* SOURCE bridge.for:1173 */
/*<   600 continue >*/
L600:
/*       STORE IN QCRITV */
/* SOURCE bridge.for:1177 */
/*<       qcritv(i)=bwd >*/
	flotab_1.qcritv[feq_gen_i_d_ - 1] = bwd;
/* SOURCE bridge.for:1178 */
/*<  1000 continue >*/
/* L1000: */
    }
/*     SET THE ZERO DEPTH ENTRY TO THE SAME VALUE AS THE FIRST */
/*     NON-ZERO DEPTH */
/* SOURCE bridge.for:1183 */
/*<       qcritv(1)=qcritv(2) >*/
    flotab_1.qcritv[0] = flotab_1.qcritv[1];
/*     OUTPUT THE TABLE */
/* SOURCE bridge.for:1187 */
/*<       callsptout(stdout,stdtab,nft,ltab,label,zft,qcritv) >*/
    sptout_(stdout, stdtab, &flotab_1.nft, &ltab, label, flotab_1.zft, 
	    flotab_1.qcritv);
/* SOURCE bridge.for:1190 */
/*<       return >*/
    return 0;
/* SOURCE bridge.for:1191 */
/*<       end >*/
} /* spbrid_ */

#ifdef __cplusplus
	}
#endif
