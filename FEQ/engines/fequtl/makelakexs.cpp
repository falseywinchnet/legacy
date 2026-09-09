/* makelakexs.f -- translated by f2c (version 20240504).
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

/* COMMON ftable_ is declared in common.hpp. */

#define ftable_1 ftable_

/* COMMON ftablea_ is declared in common.hpp. */

#define ftablea_1 ftablea_

/* COMMON ftablec_ is declared in common.hpp. */

#define ftablec_1 ftablec_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_2 = 2;
static integer feq_gen_c_d_10002 = 10002;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_5 = 5;
static integer feq_gen_c_d_3 = 3;
static integer c_n1 = -1;

/*     Code to help make estimated cross sections below a */
/*     reservoir when preconstruction topography is lost */
/* SOURCE makelakexs.for:5 */
/*<       subroutinemakelakexs(stdin,stdout,eflag) >*/
/* Subroutine */ int makelakexs_(integer *stdin, integer *stdout, integer *
	eflag)
{
    /* Format strings */
    static char fmt_50[] = "(a2,2x,f10.1,6f6.2,f10.0,2f10.1)";
    static char fmt_52[] = "(\002FEQX\002,/,\002TABID=\002,a6,\002 OUT22 NEW\
BETAM\002,/,\002STATION=\002,f10.4,/,\002NAVM=   0\002,/,\002NSUB 0.080 0.05\
 0.08\002,/,\002    OFFSET ELEVATION SUBS\002)";
    static char fmt_54[] = "(f10.2,f10.3,i5)";

    /* System generated locals */
    address feq_gen_a_d_1[2];
    integer feq_gen_i_d_1, feq_gen_i_d_2[2];
    real feq_gen_r_d_1, feq_gen_r_d_2;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2, feq_gen_d_d_3, feq_gen_d_d_4;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(), 
	    s_cmp(char *, char *, ftnlen, ftnlen);
    double pow_dd(doublereal *, doublereal *);
    integer s_wsfe(cilist *), e_wsfe(), s_wsle(cilist *), do_lio(integer *, 
	    integer *, char *, ftnlen), e_wsle();
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    char tabidlpr[16];
    real statconv;
    integer feq_gen_i_d_, j;
    doublereal p;
    real y[100], df, tp[100], ts[100], ys[100];
    doublereal sum;
    integer nxs;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ntab;
    char line[80];
    integer noff;
    char xsid[2*100];
    real zbot[100];
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    doublereal sumt;
    char tabid[16];
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    integer tabzs, tabsz;
    extern /* Subroutine */ int chktab_(integer *, integer *, integer *, 
	    integer *, integer *, integer *), inline_(integer *, integer *, 
	    char *, ftnlen);
    integer tablpr;
    real offset[600]	/* was [100][6] */, zatoff[6], offconv;
    char tabidzs[16], tabidsz[16];
    real station[100];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__28 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__30 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__31 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__34 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__35 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__36 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__37 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__39 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__40 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__41 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__42 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__43 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__44 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__45 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__46 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__47 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__48 = { 0, 0, 0, 0, 0 };


/*     Uses reservoir capacity table, invert description, and */
/*     above-water elevation offset data to estimate below-water */
/*     cross sections. */
/* SOURCE makelakexs.for:11 */
/*<       implicitnone >*/
/* SOURCE makelakexs.for:12 */
/*<       integereflag,stdin,stdout >*/
/* INCLUDE makelakexs.for:14 */
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
/* INCLUDE makelakexs.for:15 */
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
/*     Called program units */
/* SOURCE makelakexs.for:18 */
/*<       externalinline,strip_l_blanks >*/
/*     Local variables. */
/* SOURCE makelakexs.for:22 */
/*<       integeri,j,tabzs,tabsz,tablpr,noff,nxs,ntab >*/
/* SOURCE makelakexs.for:25 */
/*<        >*/
/* SOURCE makelakexs.for:29 */
/*<       real*8sum,sumt,p >*/
/* SOURCE makelakexs.for:31 */
/*<        >*/
/*     *****************************FORMATS****************************** */
/* SOURCE makelakexs.for:35 */
/*<    50 format(a2,2x,f10.1,6f6.2,f10.0,2f10.1) >*/
/* SOURCE makelakexs.for:36 */
/*<    52  >*/
/* SOURCE makelakexs.for:39 */
/*<    54 format(f10.2,f10.3,i5) >*/
/* *********************************************************************** */
/*     Get the tabids for the invert description. */
/* SOURCE makelakexs.for:43 */
/*<       callinline(stdin,stdout,line) >*/
/* L50: */
/* L52: */
/* L54: */
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE makelakexs.for:47 */
/*<       read(line,'(3A16)')tabidzs,tabidsz,tabidlpr >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(3A16)");
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, tabidzs, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, tabidsz, (ftnlen)16);
    do_fio(&feq_gen_c_d_1, tabidlpr, (ftnlen)16);
    e_rsfi();
/* SOURCE makelakexs.for:49 */
/*<       callget_internal_tab_number(stdout,tabidzs,eflag,tabzs) >*/
    feq_gen_get_internal_tab_number_d_(stdout, tabidzs, eflag, &tabzs, (ftnlen)16);
/* SOURCE makelakexs.for:53 */
/*<       callchktab(2,stdout,ftpnt,mftnum,tabzs,eflag) >*/
    chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &tabzs, eflag);
/* SOURCE makelakexs.for:58 */
/*<       callget_internal_tab_number(stdout,tabidsz,eflag,tabsz) >*/
    feq_gen_get_internal_tab_number_d_(stdout, tabidsz, eflag, &tabsz, (ftnlen)16);
/* SOURCE makelakexs.for:62 */
/*<       callchktab(2,stdout,ftpnt,mftnum,tabsz,eflag) >*/
    chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &tabsz, eflag);
/* SOURCE makelakexs.for:67 */
/*<       callget_internal_tab_number(stdout,tabidlpr,eflag,tablpr) >*/
    feq_gen_get_internal_tab_number_d_(stdout, tabidlpr, eflag, &tablpr, (ftnlen)16);
/* SOURCE makelakexs.for:71 */
/*<       callchktab(2,stdout,ftpnt,mftnum,tablpr,eflag) >*/
    chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &tablpr, eflag);
/*     Hard code the elevations for now- on a tight schedule */
/* SOURCE makelakexs.for:79 */
/*<       noff=6 >*/
    noff = 6;
/* SOURCE makelakexs.for:80 */
/*<       zatoff(1)=800. >*/
    zatoff[0] = (float)800.;
/* SOURCE makelakexs.for:81 */
/*<       zatoff(2)=600.0 >*/
    zatoff[1] = (float)600.;
/* SOURCE makelakexs.for:82 */
/*<       zatoff(3)=435. >*/
    zatoff[2] = (float)435.;
/* SOURCE makelakexs.for:83 */
/*<       zatoff(4)=435. >*/
    zatoff[3] = (float)435.;
/* SOURCE makelakexs.for:84 */
/*<       zatoff(5)=600. >*/
    zatoff[4] = (float)600.;
/* SOURCE makelakexs.for:85 */
/*<       zatoff(6)=800.0 >*/
    zatoff[5] = (float)800.;
/*     Hardcode station conversion and offset conversion. */
/* SOURCE makelakexs.for:88 */
/*<       statconv=1.0 >*/
    statconv = (float)1.;
/* SOURCE makelakexs.for:89 */
/*<       offconv=2000.0 >*/
    offconv = (float)2e3;
/*     input the station and offset data in advancing station order. */
/*     Input the heading line */
/* SOURCE makelakexs.for:94 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE makelakexs.for:98 */
/*<       i=0 >*/
    feq_gen_i_d_ = 0;
/* SOURCE makelakexs.for:99 */
/*<   100 continue >*/
L100:
/* SOURCE makelakexs.for:101 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE makelakexs.for:105 */
/*<       if(line(1:3).ne.'END')then >*/
    if (s_cmp(line, const_cast<char*>("END"), (ftnlen)3, (ftnlen)3) != 0) {
/* SOURCE makelakexs.for:106 */
/*<       i=i+1 >*/
	++feq_gen_i_d_;
/* SOURCE makelakexs.for:107 */
/*<       read(line,'(A2,F8.0,6F5.0)')xsid(i),station(i),(offset(i,j),j=1,6) >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(A2,F8.0,6F5.0)");
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, xsid + (feq_gen_i_d_ - 1 << 1), (ftnlen)2);
	do_fio(&feq_gen_c_d_1, (char *)&station[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	for (j = 1; j <= 6; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&offset[feq_gen_i_d_ + j * 100 - 101], (ftnlen)
		    sizeof(real));
	}
	e_rsfi();
/* SOURCE makelakexs.for:109 */
/*<       goto100 >*/
	goto L100;
/* SOURCE makelakexs.for:110 */
/*<       endif >*/
    }
/* SOURCE makelakexs.for:111 */
/*<       nxs=i >*/
    nxs = feq_gen_i_d_;
/*     Dump values for checking */
/* SOURCE makelakexs.for:113 */
/*<       p=1.0d0 >*/
    p = 1.;
/* SOURCE makelakexs.for:115 */
/*<       do110i=1,nxs >*/
    feq_gen_i_d_1 = nxs;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*       Compute top width at water surface */
/* SOURCE makelakexs.for:117 */
/*<       ts(i)=offconv*(offset(i,4)-offset(i,3)) >*/
	ts[feq_gen_i_d_ - 1] = static_cast<double>(offconv) * (static_cast<double>(offset[feq_gen_i_d_ + 299]) - offset[feq_gen_i_d_ + 199]);
/*       Compute the elevation of the bottom */
/* SOURCE makelakexs.for:119 */
/*<       calllktab(tabzs,station(i),1,zbot(i),ntab,df) >*/
	lktab_(&tabzs, &station[feq_gen_i_d_ - 1], &feq_gen_c_d_1, &zbot[feq_gen_i_d_ - 1], &ntab, &df);
/*       Compute the depth. */
/* SOURCE makelakexs.for:123 */
/*<       ys(i)=zatoff(3)-zbot(i) >*/
	ys[feq_gen_i_d_ - 1] = static_cast<double>(zatoff[2]) - zbot[feq_gen_i_d_ - 1];
/*       Compute the parameter */
/* SOURCE makelakexs.for:126 */
/*<       tp(i)=ts(i)/(ys(i)**p) >*/
	feq_gen_d_d_1 = (doublereal) ys[feq_gen_i_d_ - 1];
	tp[feq_gen_i_d_ - 1] = ts[feq_gen_i_d_ - 1] / pow_dd(&feq_gen_d_d_1, &p);
/* SOURCE makelakexs.for:128 */
/*<        >*/
	feq_gen_io_d__28.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__28);
	do_fio(&feq_gen_c_d_1, xsid + (feq_gen_i_d_ - 1 << 1), (ftnlen)2);
	do_fio(&feq_gen_c_d_1, (char *)&station[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	for (j = 1; j <= 6; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&offset[feq_gen_i_d_ + j * 100 - 101], (ftnlen)
		    sizeof(real));
	}
	do_fio(&feq_gen_c_d_1, (char *)&ts[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&zbot[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&ys[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE makelakexs.for:130 */
/*<   110 continue >*/
/* L110: */
    }
/*     Compute the surface area. */
/* SOURCE makelakexs.for:134 */
/*<       sum=0.d0 >*/
    sum = 0.;
/* SOURCE makelakexs.for:135 */
/*<       do120i=2,nxs >*/
    feq_gen_i_d_1 = nxs;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE makelakexs.for:136 */
/*<       sum=sum+0.5d0*(ts(i)+ts(i-1))*(station(i)-station(i-1)) >*/
	sum += (static_cast<double>(ts[feq_gen_i_d_ - 1]) + ts[feq_gen_i_d_ - 2]) * .5 * (static_cast<double>(station[feq_gen_i_d_ - 1]) - station[
		feq_gen_i_d_ - 2]);
/* SOURCE makelakexs.for:138 */
/*<   120 continue >*/
/* L120: */
    }
/* SOURCE makelakexs.for:140 */
/*<       write(stdout,*)' Approx surface area at 435=',sum/43560.d0 >*/
    feq_gen_io_d__30.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__30);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Approx surface area at 435="), (ftnlen)28);
    feq_gen_d_d_1 = sum / 43560.;
    do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&feq_gen_d_d_1, (ftnlen)sizeof(doublereal));
    e_wsle();
/* SOURCE makelakexs.for:142 */
/*<       return >*/
    return 0;
/*     Compute volume assuming a generalized parabola */
/* SOURCE makelakexs.for:145 */
/*<       sum=0.d0 >*/
    sum = 0.;
/* SOURCE makelakexs.for:146 */
/*<       do130i=2,nxs >*/
    feq_gen_i_d_1 = nxs;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE makelakexs.for:147 */
/*<        >*/
	sum += (static_cast<double>(static_cast<double>(ts[feq_gen_i_d_ - 1]) * ys[feq_gen_i_d_ - 1]) + static_cast<double>(ts[feq_gen_i_d_ - 2]) * ys[feq_gen_i_d_ - 2]) * .5 / 
		(p + 1.) * (static_cast<double>(station[feq_gen_i_d_ - 1]) - station[feq_gen_i_d_ - 2]);
/* SOURCE makelakexs.for:149 */
/*<   130 continue >*/
/* L130: */
    }
/* SOURCE makelakexs.for:151 */
/*<       write(stdout,*)'Approx volume at 435=',sum/43560.d0 >*/
    feq_gen_io_d__31.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__31);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("Approx volume at 435="), (ftnlen)21);
    feq_gen_d_d_1 = sum / 43560.;
    do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&feq_gen_d_d_1, (ftnlen)sizeof(doublereal));
    e_wsle();
/*     Compute volume at 421 feet. */
/* SOURCE makelakexs.for:154 */
/*<       do140i=1,nxs >*/
    feq_gen_i_d_1 = nxs;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE makelakexs.for:155 */
/*<       y(i)=421.0-zbot(i) >*/
	y[feq_gen_i_d_ - 1] = static_cast<double>((float)421.) - zbot[feq_gen_i_d_ - 1];
/* SOURCE makelakexs.for:156 */
/*<   140 continue >*/
/* L140: */
    }
/* SOURCE makelakexs.for:158 */
/*<       sum=0.d0 >*/
    sum = 0.;
/* SOURCE makelakexs.for:159 */
/*<       sumt=0.d0 >*/
    sumt = 0.;
/* SOURCE makelakexs.for:160 */
/*<       do150i=2,nxs >*/
    feq_gen_i_d_1 = nxs;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE makelakexs.for:161 */
/*<        >*/
	feq_gen_d_d_1 = (doublereal) y[feq_gen_i_d_ - 1];
	feq_gen_d_d_2 = p + 1.;
	feq_gen_d_d_3 = (doublereal) y[feq_gen_i_d_ - 2];
	feq_gen_d_d_4 = p + 1.;
	sum += (tp[feq_gen_i_d_ - 1] * pow_dd(&feq_gen_d_d_1, &feq_gen_d_d_2) + tp[feq_gen_i_d_ - 2] * pow_dd(&
		feq_gen_d_d_3, &feq_gen_d_d_4)) * .5 / (p + 1.) * (static_cast<double>(station[feq_gen_i_d_ - 1]) - station[
		feq_gen_i_d_ - 2]);
/* SOURCE makelakexs.for:164 */
/*<        >*/
	feq_gen_d_d_1 = (doublereal) y[feq_gen_i_d_ - 1];
	feq_gen_d_d_2 = (doublereal) y[feq_gen_i_d_ - 2];
	sumt += (tp[feq_gen_i_d_ - 1] * pow_dd(&feq_gen_d_d_1, &p) + tp[feq_gen_i_d_ - 2] * pow_dd(&feq_gen_d_d_2,
		 &p)) * .5 * (static_cast<double>(station[feq_gen_i_d_ - 1]) - station[feq_gen_i_d_ - 2]);
/* SOURCE makelakexs.for:167 */
/*<   150 continue >*/
/* L150: */
    }
/* SOURCE makelakexs.for:169 */
/*<       write(stdout,*)'Approx area at 421=',sumt/43560.d0 >*/
    feq_gen_io_d__34.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__34);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("Approx area at 421="), (ftnlen)19);
    feq_gen_d_d_1 = sumt / 43560.;
    do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&feq_gen_d_d_1, (ftnlen)sizeof(doublereal));
    e_wsle();
/* SOURCE makelakexs.for:170 */
/*<       write(stdout,*)'Approx volume at 421=',sum/43560.d0 >*/
    feq_gen_io_d__35.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__35);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("Approx volume at 421="), (ftnlen)21);
    feq_gen_d_d_1 = sum / 43560.;
    do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&feq_gen_d_d_1, (ftnlen)sizeof(doublereal));
    e_wsle();
/*     Compute volume at 384. feet. */
/* SOURCE makelakexs.for:175 */
/*<       do160i=1,17 >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 17; ++feq_gen_i_d_) {
/* SOURCE makelakexs.for:176 */
/*<       y(i)=384.0-zbot(i) >*/
	y[feq_gen_i_d_ - 1] = static_cast<double>((float)384.) - zbot[feq_gen_i_d_ - 1];
/* SOURCE makelakexs.for:177 */
/*<   160 continue >*/
/* L160: */
    }
/* SOURCE makelakexs.for:179 */
/*<       sum=0.d0 >*/
    sum = 0.;
/* SOURCE makelakexs.for:180 */
/*<       sumt=0.d0 >*/
    sumt = 0.;
/* SOURCE makelakexs.for:181 */
/*<       do170i=2,17 >*/
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= 17; ++feq_gen_i_d_) {
/* SOURCE makelakexs.for:182 */
/*<        >*/
	feq_gen_d_d_1 = (doublereal) y[feq_gen_i_d_ - 1];
	feq_gen_d_d_2 = p + 1.;
	feq_gen_d_d_3 = (doublereal) y[feq_gen_i_d_ - 2];
	feq_gen_d_d_4 = p + 1.;
	sum += (tp[feq_gen_i_d_ - 1] * pow_dd(&feq_gen_d_d_1, &feq_gen_d_d_2) + tp[feq_gen_i_d_ - 2] * pow_dd(&
		feq_gen_d_d_3, &feq_gen_d_d_4)) * .5 / (p + 1.) * (static_cast<double>(station[feq_gen_i_d_ - 1]) - station[
		feq_gen_i_d_ - 2]);
/* SOURCE makelakexs.for:185 */
/*<        >*/
	feq_gen_d_d_1 = (doublereal) y[feq_gen_i_d_ - 1];
	feq_gen_d_d_2 = (doublereal) y[feq_gen_i_d_ - 2];
	sumt += (tp[feq_gen_i_d_ - 1] * pow_dd(&feq_gen_d_d_1, &p) + tp[feq_gen_i_d_ - 2] * pow_dd(&feq_gen_d_d_2,
		 &p)) * .5 * (static_cast<double>(station[feq_gen_i_d_ - 1]) - station[feq_gen_i_d_ - 2]);
/* SOURCE makelakexs.for:188 */
/*<   170 continue >*/
/* L170: */
    }
/* SOURCE makelakexs.for:190 */
/*<       write(stdout,*)'Approx area at 384=',sumt/43560.d0 >*/
    feq_gen_io_d__36.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__36);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("Approx area at 384="), (ftnlen)19);
    feq_gen_d_d_1 = sumt / 43560.;
    do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&feq_gen_d_d_1, (ftnlen)sizeof(doublereal));
    e_wsle();
/* SOURCE makelakexs.for:191 */
/*<       write(stdout,*)'Approx volume at 384=',sum/43560.d0 >*/
    feq_gen_io_d__37.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__37);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("Approx volume at 384="), (ftnlen)21);
    feq_gen_d_d_1 = sum / 43560.;
    do_lio(&feq_gen_c_d_5, &feq_gen_c_d_1, (char *)&feq_gen_d_d_1, (ftnlen)sizeof(doublereal));
    e_wsle();
/*     Output FEQX format using a triangular channel for the */
/*     below water portion. */
/* SOURCE makelakexs.for:197 */
/*<       do180i=1,nxs >*/
    feq_gen_i_d_1 = nxs;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE makelakexs.for:198 */
/*<       tabid='RDXS'//xsid(i) >*/
/* Writing concatenation */
	feq_gen_i_d_2[0] = 4, feq_gen_a_d_1[0] = const_cast<char*>("RDXS");
	feq_gen_i_d_2[1] = 2, feq_gen_a_d_1[1] = xsid + (feq_gen_i_d_ - 1 << 1);
	s_cat(tabid, feq_gen_a_d_1, feq_gen_i_d_2, &feq_gen_c_d_2, (ftnlen)16);
/* SOURCE makelakexs.for:199 */
/*<       write(stdout,52)tabid,station(i)/3280.84 >*/
	feq_gen_io_d__39.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__39);
	do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
	feq_gen_r_d_1 = static_cast<double>(station[feq_gen_i_d_ - 1]) / (float)3280.84;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE makelakexs.for:201 */
/*<       write(stdout,54)offset(i,1)*609.60,zatoff(1)*0.3048,1 >*/
	feq_gen_io_d__40.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__40);
	feq_gen_r_d_1 = static_cast<double>(offset[feq_gen_i_d_ - 1]) * (float)609.6;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	feq_gen_r_d_2 = static_cast<double>(zatoff[0]) * (float).3048;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_1, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE makelakexs.for:202 */
/*<       write(stdout,54)offset(i,2)*609.60,zatoff(2)*0.3048,1 >*/
	feq_gen_io_d__41.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__41);
	feq_gen_r_d_1 = static_cast<double>(offset[feq_gen_i_d_ + 99]) * (float)609.6;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	feq_gen_r_d_2 = static_cast<double>(zatoff[1]) * (float).3048;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_1, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE makelakexs.for:203 */
/*<       write(stdout,54)offset(i,3)*609.60,zatoff(3)*0.3048,2 >*/
	feq_gen_io_d__42.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__42);
	feq_gen_r_d_1 = static_cast<double>(offset[feq_gen_i_d_ + 199]) * (float)609.6;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	feq_gen_r_d_2 = static_cast<double>(zatoff[2]) * (float).3048;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_2, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE makelakexs.for:204 */
/*<        >*/
	feq_gen_io_d__43.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__43);
	feq_gen_r_d_1 = static_cast<double>(static_cast<double>((static_cast<double>(offset[feq_gen_i_d_ + 199]) + offset[feq_gen_i_d_ + 299])) * (float)609.6) / (
		float)2.;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	feq_gen_r_d_2 = static_cast<double>(zbot[feq_gen_i_d_ - 1]) * (float).3048;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_2, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE makelakexs.for:206 */
/*<       write(stdout,54)offset(i,4)*609.60,zatoff(4)*0.3048,3 >*/
	feq_gen_io_d__44.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__44);
	feq_gen_r_d_1 = static_cast<double>(offset[feq_gen_i_d_ + 299]) * (float)609.6;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	feq_gen_r_d_2 = static_cast<double>(zatoff[3]) * (float).3048;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_3, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE makelakexs.for:207 */
/*<       write(stdout,54)offset(i,5)*609.60,zatoff(5)*0.3048,3 >*/
	feq_gen_io_d__45.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__45);
	feq_gen_r_d_1 = static_cast<double>(offset[feq_gen_i_d_ + 399]) * (float)609.6;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	feq_gen_r_d_2 = static_cast<double>(zatoff[4]) * (float).3048;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_3, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE makelakexs.for:208 */
/*<       write(stdout,54)offset(i,6)*609.60,zatoff(6)*0.3048,-1 >*/
	feq_gen_io_d__46.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__46);
	feq_gen_r_d_1 = static_cast<double>(offset[feq_gen_i_d_ + 499]) * (float)609.6;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	feq_gen_r_d_2 = static_cast<double>(zatoff[5]) * (float).3048;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&c_n1, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE makelakexs.for:209 */
/*<       write(stdout,*)' ' >*/
	feq_gen_io_d__47.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__47);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	e_wsle();
/* SOURCE makelakexs.for:210 */
/*<       write(stdout,*)' ' >*/
	feq_gen_io_d__48.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__48);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	e_wsle();
/* SOURCE makelakexs.for:211 */
/*<   180 continue >*/
/* L180: */
    }
/* SOURCE makelakexs.for:214 */
/*<       return >*/
    return 0;
/* SOURCE makelakexs.for:216 */
/*<       end >*/
} /* makelakexs_ */

#undef rtmp
#undef itab
#undef ftab


#ifdef __cplusplus
	}
#endif
