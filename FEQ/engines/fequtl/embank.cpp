#include <feq/weir_flow.hpp>
#include <feq/power.hpp>
#include <cmath>
extern "C" int feq_submerged_weir(int,int,int,float,float,float,float,float,float,float,float*,float*,float*,float*,float*,float*,float*);
/* embank.f -- translated by f2c (version 20240504).
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

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* COMMON grvcom_ is declared in common.hpp. */

#define grvcom_1 grvcom_

/* COMMON subcom_ is declared in common.hpp. */

#define subcom_1 subcom_

/* COMMON embcmc_ is declared in common.hpp. */

#define embcmc_1 embcmc_

/* COMMON embcom_ is declared in common.hpp. */

#define embcom_1 embcom_

/* COMMON embq_ is declared in common.hpp. */

#define embq_1 embq_

/* COMMON upgrdc_ is declared in common.hpp. */

#define upgrdc_1 upgrdc_

/* COMMON embkitm_com__ is declared in common.hpp. */

#define feq_gen_embkitm_com_d_1 feq_gen_embkitm_com_d_

/* COMMON embkitm_comc__ is declared in common.hpp. */

#define feq_gen_embkitm_comc_d_1 feq_gen_embkitm_comc_d_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_0 = 0;
static doublereal c_b29 = .3333333;
static integer feq_gen_c_d_4 = 4;
static integer feq_gen_c_d_1000 = 1000;
static integer feq_gen_c_d_2 = 2;
static integer feq_gen_c_d_10002 = 10002;
static integer feq_gen_c_d_151 = 151;
static integer feq_gen_c_d_351 = 351;
static real c_b360 = (float)0.;
static real c_b367 = (float)-1.;
static integer feq_gen_c_d_10 = 10;
static real c_b395 = (float)2.5;
static real c_b404 = (float).5;
static doublereal c_b405 = 1.;
static integer feq_gen_c_d_7 = 7;




/* SOURCE embank.for:4 */
/*<       realfunctionfsbrat(adr) >*/
doublereal fsbrat_(integer *adr)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *ERR:600* TYPE=\002,i4,\002 invalid type f\
or submergence\002,\002 table.\002)";
    static char fmt_52[] = "(\002 *ERR:601* TABID=\002,a,\002 invalid submer\
gence values at\002,\002 table start.\002)";
    static char fmt_54[] = "(\002 *ERR:602* TABID=\002,a,\002 no submergence\
 in submergence\002,\002 table.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real ret_val, feq_gen_r_d_1;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer badr;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
    integer hadr;
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ioff, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    char tabid[16];
    extern integer lenstr_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__7 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__10 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__12 = { 0, 0, 0, fmt_54, 0 };


/*     + + + PURPOSE + + + */
/*     Find the submergence ratio for the submergence table */
/*     stored at address ADR */
/* SOURCE embank.for:11 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE embank.for:14 */
/*<       integeradr >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADR    - Address of submergence table */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE embank.for:20 */
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
/* INCLUDE embank.for:21 */
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
/* INCLUDE embank.for:22 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE embank.for:25 */
/*<       integerbadr,hadr,i,ioff,type >*/
/* SOURCE embank.for:26 */
/*<       charactertabid*16 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE embank.for:28 */
/*<       intrinsicabs >*/
/*     External names */
/* SOURCE embank.for:31 */
/*<       integerlenstr >*/
/* SOURCE embank.for:32 */
/*<       characterget_tabid*16 >*/
/* SOURCE embank.for:33 */
/*<       externallenstr,get_tabid >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE embank.for:36 */
/*<    50  >*/
/* SOURCE embank.for:38 */
/*<    52  >*/
/* SOURCE embank.for:40 */
/*<    54  >*/
/* *********************************************************************** */
/* SOURCE embank.for:43 */
/*<       type=itab(adr+2) >*/
/* L50: */
/* L52: */
/* L54: */
    feq_gen_type_d_ = itab[*adr + 2];
/* SOURCE embank.for:44 */
/*<       badr=adr+off234 >*/
    badr = *adr + 22;
/* SOURCE embank.for:45 */
/*<       hadr=itab(adr) >*/
    hadr = itab[*adr];
/* SOURCE embank.for:46 */
/*<       if(type.lt.2.or.type.gt.4)then >*/
    if (feq_gen_type_d_ < 2 || feq_gen_type_d_ > 4) {
/*       INVALID TYPE FOR SUBMERGENCE */
/* SOURCE embank.for:48 */
/*<       write(std6,50)type >*/
	feq_gen_io_d__7.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsfe(&feq_gen_io_d__7);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE embank.for:49 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE embank.for:50 */
/*<       endif >*/
    }
/* SOURCE embank.for:52 */
/*<       if(type.eq.2)then >*/
    if (feq_gen_type_d_ == 2) {
/* SOURCE embank.for:53 */
/*<       ioff=2 >*/
	ioff = 2;
/* SOURCE embank.for:54 */
/*<       else >*/
    } else {
/* SOURCE embank.for:55 */
/*<       ioff=3 >*/
	ioff = 3;
/* SOURCE embank.for:56 */
/*<       endif >*/
    }
/*     NOW SEARCH THE TABLE IN ORDER OF ADDRESSES(ASCENDING ARGUMENTS) */
/*     FOR THE HIGHEST ARGUMENT  WITH A FUNCTION VALUE OF 1.0 */
/*     CHECK FOR CONSISTENCY */
/* SOURCE embank.for:62 */
/*<       if(abs(ftab(badr+1)-1.0).ge.1.e-6.or.ftab(badr).ne.0.0)then >*/
    if ((feq_gen_r_d_1 = static_cast<double>(ftab[badr + 1]) - (float)1., dabs(feq_gen_r_d_1)) >= (float)1e-6 || 
	    ftab[badr] != (float)0.) {
/*       FIRST ARGUMENT IN TABLE MUST BE 0.0 AND FIRST FUNCTION VALUE */
/*       MUST BE 1.0. */
/* SOURCE embank.for:65 */
/*<       tabid=get_tabid(itab(adr+1)) >*/
	feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, itab.lease(*adr + 1).data());
	s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE embank.for:66 */
/*<       write(std6,52)tabid(1:lenstr(tabid)) >*/
	feq_gen_io_d__10.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsfe(&feq_gen_io_d__10);
	do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
	e_wsfe();
/* SOURCE embank.for:67 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE embank.for:68 */
/*<       endif >*/
    }
/* SOURCE embank.for:70 */
/*<       do100i=badr,hadr,ioff >*/
    feq_gen_i_d_1 = hadr;
    feq_gen_i_d_2 = ioff;
    for (feq_gen_i_d_ = badr; feq_gen_i_d_2 < 0 ? feq_gen_i_d_ >= feq_gen_i_d_1 : feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += feq_gen_i_d_2) {
/* SOURCE embank.for:71 */
/*<       if(1.0-ftab(i+1).gt.1.e-6)then >*/
	if (static_cast<double>((float)1.) - ftab[feq_gen_i_d_ + 1] > (float)1e-6) {
/*         FOUND FIRST FUNCTION VALUE < 1.0.  BACKUP ARGUMENT. */
/* SOURCE embank.for:74 */
/*<       fsbrat=ftab(i-ioff) >*/
	    ret_val = ftab[feq_gen_i_d_ - ioff];
/* SOURCE embank.for:75 */
/*<       return >*/
	    return ret_val;
/* SOURCE embank.for:76 */
/*<       endif >*/
	}
/* SOURCE embank.for:77 */
/*<   100 continue >*/
/* L100: */
    }
/*     FALL THROUGH INDICATES THAT THERE IS NO SUBMERGENCE! */
/* SOURCE embank.for:80 */
/*<       tabid=get_tabid(itab(adr+1)) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, itab.lease(*adr + 1).data());
    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE embank.for:81 */
/*<       write(std6,54)tabid(1:lenstr(tabid)) >*/
    feq_gen_io_d__12.ciunit = feq_gen_stdun_com_d_1.std6;
    s_wsfe(&feq_gen_io_d__12);
    do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
    e_wsfe();
/* SOURCE embank.for:82 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE embank.for:83 */
/*<       end >*/
    return ret_val;
} /* fsbrat_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE embank.for:87 */
/*<        >*/
/* Subroutine */ int ftothq_(integer *hcwtab, integer *lcwtab, real *hlcrit, 
	real *hlmax, real *srat, real *l, real *feq_gen_h_d_, real *depth, integer *
	hlflag, integer *hpflag, real *q, real *htot, real *ycrest, real *
	aelrat)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *WRN:545* Head to width ratio=\002,f8.3\
,\002 >\002,\002 maximum ratio=\002,f8.3)";
    static char fmt_52[] = "(/,\002 *WRN:553* (Piezometric head)/(weir heigh\
t)=\002,f8.2,\002 > 4.\002,\002  Weir\002,/,10x,\002flow may be INVALID.\002)"
	    ;

    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2;
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    double pow_dd(doublereal *, doublereal *);

    /* Local variables */
    real el, cw, qw, ael, pdv;
    integer knt;
    real head;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ntab;
    real qmax;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    real ratio, qwold;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__18 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__21 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__28 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__30 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__31 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Compute the free flow using the total head and coefficients */
/*     defined as a function of head and weir width. */
/* SOURCE embank.for:97 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE embank.for:100 */
/*<       integerhcwtab,hlflag,hpflag,lcwtab >*/
/* SOURCE embank.for:101 */
/*<       realaelrat,depth,h,hlcrit,hlmax,htot,l,q,srat,ycrest >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     HCWTAB - High head weir coefficient table */
/*     LCWTAB - Low head weir coefficient table */
/*     HLCRIT - Ratio of piezometric head to crest breadth at boundary */
/*              between low head and high head flow */
/*     HLMAX  - Maximum value of piezometric head to crest breadth ratio */
/*               above which a warning message is issued */
/*     SRAT   - Submergence ratio at the free flow limit */
/*     L      - Crest breadth for the embankment */
/*     H      - Piezometric head */
/*     DEPTH  - Depth of approaching flow */
/*     HLFLAG - Warning message suppression flag */
/*     HPFLAG - Warning message suppression flag for invalid weir flow */
/*     Q      - Flowrate */
/*     HTOT   - Total head */
/*     YCREST - Estimated depth on crest of the embankment */
/*     AELRAT - Estimated ratio of head loss to head loss at incipient */
/*              submergence */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE embank.for:123 */
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
/* INCLUDE embank.for:124 */
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
/* INCLUDE embank.for:125 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE embank.for:126 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE embank.for:129 */
/*<       integerknt,ntab >*/
/* SOURCE embank.for:130 */
/*<       realael,cw,el,head,pdv,qmax,qw,qwold,ratio >*/
/*     + + + INTRINSICS + + + */
/* SOURCE embank.for:133 */
/*<       intrinsicabs,sqrt >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE embank.for:136 */
/*<       externallktab >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE embank.for:139 */
/*<    50  >*/
/* SOURCE embank.for:141 */
/*<    52  >*/
/* *********************************************************************** */
/* SOURCE embank.for:144 */
/*<       knt=0 >*/
/* L50: */
/* L52: */
    knt = 0;
/*     USE LINEAR ITERATION TO INCLUDE THE EFFECT OF VELOCITY HEAD */
/* SOURCE embank.for:147 */
/*<       qwold=0.475812*sqrt_grav*h*sqrt(h) >*/
    qwold = static_cast<double>(static_cast<double>(grvcom_1.feq_gen_sqrt_grav_d_) * (float).475812) * *feq_gen_h_d_ * sqrt(*feq_gen_h_d_);
/* SOURCE embank.for:148 */
/*<       if(l.eq.0.0)then >*/
    if (*l == (float)0.) {
/* SOURCE embank.for:149 */
/*<       write(std6,*)' *BUG:XXX* L=0 IN FTOTHQ' >*/
	feq_gen_io_d__18.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsle(&feq_gen_io_d__18);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* L=0 IN FTOTHQ"), (ftnlen)24);
	e_wsle();
/* SOURCE embank.for:150 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE embank.for:151 */
/*<       endif >*/
    }
/* SOURCE embank.for:152 */
/*<       ratio=h/l >*/
    ratio = static_cast<double>(*feq_gen_h_d_) / *l;
/* SOURCE embank.for:154 */
/*<   100 continue >*/
L100:
/*       COMPUTE THE VELOCITY HEAD AND ADD TO THE PIEZOMETRIC HEAD */
/* SOURCE embank.for:158 */
/*<       head=h+(qwold/depth)**2/grav2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(qwold) / *depth;
    head = static_cast<double>(*feq_gen_h_d_) + static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / grvcom_1.grav2;
/*       FIND THE WEIR COEFFICIENT */
/* SOURCE embank.for:163 */
/*<       if(ratio.gt.hlcrit)then >*/
    if (ratio > *hlcrit) {
/* SOURCE embank.for:164 */
/*<       if(ratio.gt.hlmax)then >*/
	if (ratio > *hlmax) {
/* SOURCE embank.for:165 */
/*<       if(hlflag.eq.0)then >*/
	    if (*hlflag == 0) {
/* SOURCE embank.for:166 */
/*<       write(std6,50)ratio,hlmax >*/
		feq_gen_io_d__21.ciunit = feq_gen_stdun_com_d_1.std6;
		s_wsfe(&feq_gen_io_d__21);
		do_fio(&feq_gen_c_d_1, (char *)&ratio, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&(*hlmax), (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE embank.for:167 */
/*<       hlflag=1 >*/
		*hlflag = 1;
/* SOURCE embank.for:168 */
/*<       endif >*/
	    }
/* SOURCE embank.for:169 */
/*<       endif >*/
	}
/* SOURCE embank.for:170 */
/*<       calllktab(hcwtab,ratio,0,cw,ntab,pdv) >*/
	lktab_(hcwtab, &ratio, &feq_gen_c_d_0, &cw, &ntab, &pdv);
/* SOURCE embank.for:173 */
/*<       else >*/
    } else {
/* SOURCE embank.for:174 */
/*<       calllktab(lcwtab,head,0,cw,ntab,pdv) >*/
	lktab_(lcwtab, &head, &feq_gen_c_d_0, &cw, &ntab, &pdv);
/* SOURCE embank.for:177 */
/*<       endif >*/
    }
/* SOURCE embank.for:179 */
/*<       qw=cw*head*sqrt(head) >*/
    qw = static_cast<double>(cw) * head * sqrt(head);
/* SOURCE embank.for:181 */
/*<       if(abs(qw-qwold)/(0.5*(qwold+qw)).le.5.e-4)then >*/
    if ((feq_gen_r_d_1 = static_cast<double>(qw) - qwold, dabs(feq_gen_r_d_1)) / (static_cast<double>((static_cast<double>(qwold) + qw)) * (float).5) <= (
	    float)5e-4) {
/* SOURCE embank.for:182 */
/*<       q=qw >*/
	*q = qw;
/* SOURCE embank.for:183 */
/*<       htot=head >*/
	*htot = head;
/*         MAKE AN ESTIMATE OF THE CREST HEIGHT TO ESTIMATE */
/*         THE MOMENTUM FLUX */
/* SOURCE embank.for:187 */
/*<       ycrest=(cw**2*htot**3/grav)**0.3333333 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = cw;
/* Computing 3rd power */
	feq_gen_r_d_2 = *htot;
	feq_gen_d_d_1 = (doublereal) (static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * (static_cast<double>(feq_gen_r_d_2) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2))) / 
		grvcom_1.grav);
	*ycrest = pow_dd(&feq_gen_d_d_1, &c_b29);
/*         COMPUTE THE ENERGY LOSS IMPLIED BY THE FLOW OVER */
/*         THE WEIR IN THOSE CASES WHEN CRITICAL DEPTH OCCURS AT OR */
/*         NEAR THE CREST. */
/* SOURCE embank.for:192 */
/*<       ael=head-1.5*ycrest >*/
	ael = static_cast<double>(head) - static_cast<double>(*ycrest) * (float)1.5;
/* SOURCE embank.for:193 */
/*<       if(ael.lt.0.0)ael=0 >*/
	if (ael < (float)0.) {
	    ael = (float)0.;
	}
/*         COMPUTE THE HEAD LOSS AT INCIPIENT SUBMERGENCE */
/* SOURCE embank.for:196 */
/*<       el=head*(1.0-srat)-(qw/(depth-h+srat*head))**2/grav2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(qw) / (static_cast<double>(static_cast<double>(*depth) - *feq_gen_h_d_) + static_cast<double>(*srat) * head);
	el = static_cast<double>(static_cast<double>(head) * (static_cast<double>((float)1.) - *srat)) - static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / grvcom_1.grav2;
/* SOURCE embank.for:198 */
/*<       if(el.lt.0.0)then >*/
	if (el < (float)0.) {
/*           FORCE EFFECTIVE ZERO LOSS FOR COMPUTING CREST */
/*           ELEVATION */
/* SOURCE embank.for:201 */
/*<       el=1.0 >*/
	    el = (float)1.;
/* SOURCE embank.for:202 */
/*<       ael=0.0 >*/
	    ael = (float)0.;
/* SOURCE embank.for:203 */
/*<       endif >*/
	}
/*         NOW COMPUTE THE RATIO OF THE APPROACH HEAD LOSS TO THE */
/*         THE HEAD LOSS AT INCIPIENT SUBMERGENCE. */
/* SOURCE embank.for:207 */
/*<       aelrat=ael/el >*/
	*aelrat = static_cast<double>(ael) / el;
/* SOURCE embank.for:208 */
/*<       if(aelrat.le.0.0)then >*/
	if (*aelrat <= (float)0.) {
/* SOURCE embank.for:209 */
/*<       aelrat=0.005 >*/
	    *aelrat = (float).005;
/* SOURCE embank.for:210 */
/*<       endif >*/
	}
/* SOURCE embank.for:211 */
/*<       if(1.25*h.gt.depth)then >*/
	if (static_cast<double>(*feq_gen_h_d_) * (float)1.25 > *depth) {
/*           ISSUE WARNING: H/(WEIR HEIGHT) > 4.  WEIR FLOW MAY BE */
/*           INVALID. */
/* SOURCE embank.for:214 */
/*<       if(hpflag.eq.0)then >*/
	    if (*hpflag == 0) {
/* SOURCE embank.for:215 */
/*<       write(std6,52)h/(depth-h) >*/
		feq_gen_io_d__28.ciunit = feq_gen_stdun_com_d_1.std6;
		s_wsfe(&feq_gen_io_d__28);
		feq_gen_r_d_1 = static_cast<double>(*feq_gen_h_d_) / (static_cast<double>(*depth) - *feq_gen_h_d_);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE embank.for:216 */
/*<       hpflag=1 >*/
		*hpflag = 1;
/* SOURCE embank.for:217 */
/*<       endif >*/
	    }
/* SOURCE embank.for:218 */
/*<       endif >*/
	}
/*         CHECK FLOW AGAINST CRITICAL FLOW IN APPROACH SECTION */
/* SOURCE embank.for:220 */
/*<       qmax=depth*sqrt(grav*depth) >*/
	qmax = *depth * sqrt(static_cast<double>(grvcom_1.grav) * *depth);
/* SOURCE embank.for:221 */
/*<       if(q.gt.qmax)q=qmax >*/
	if (*q > qmax) {
	    *q = qmax;
	}
/* SOURCE embank.for:222 */
/*<       return >*/
	return 0;
/* SOURCE embank.for:223 */
/*<       else >*/
    } else {
/* SOURCE embank.for:224 */
/*<       qwold=qw >*/
	qwold = qw;
/* SOURCE embank.for:225 */
/*<       knt=knt+1 >*/
	++knt;
/* SOURCE embank.for:226 */
/*<       if(knt.gt.100)then >*/
	if (knt > 100) {
/* SOURCE embank.for:227 */
/*<       write(std6,*)' KNT > 100 IN FTOTHQ.' >*/
	    feq_gen_io_d__30.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsle(&feq_gen_io_d__30);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" KNT > 100 IN FTOTHQ."), (ftnlen)21);
	    e_wsle();
/* SOURCE embank.for:228 */
/*<        >*/
	    feq_gen_io_d__31.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsle(&feq_gen_io_d__31);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FTOTHQ: HEAD="), (ftnlen)14);
	    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&head, (ftnlen)sizeof(real));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" QW="), (ftnlen)4);
	    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&qw, (ftnlen)sizeof(real));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" QWOLD="), (ftnlen)7);
	    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&qwold, (ftnlen)sizeof(real));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" DEPTH="), (ftnlen)7);
	    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*depth), (ftnlen)sizeof(real));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" CW="), (ftnlen)4);
	    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&cw, (ftnlen)sizeof(real));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" H="), (ftnlen)3);
	    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*feq_gen_h_d_), (ftnlen)sizeof(real));
	    e_wsle();
/* SOURCE embank.for:230 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE embank.for:231 */
/*<       endif >*/
	}
/* SOURCE embank.for:233 */
/*<       goto100 >*/
	goto L100;
/* SOURCE embank.for:234 */
/*<       endif >*/
    }
/* SOURCE embank.for:236 */
/*<       end >*/
    return 0;
} /* ftothq_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE embank.for:240 */
/*<        >*/
/* Subroutine */ int stothq_(integer *hcwtab, integer *lcwtab, integer *
	subtab, real *hlcrit, real *l, real *feq_gen_h_d_, real *htail, real *depth, 
	real *htot, real *q)
{
    /* System generated locals */
    real feq_gen_r_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    real cw, qw, rat, pdv;
    integer knt;
    real head, frac;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ntab;
    real qmax;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    real ratio, qwold;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__41 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__46 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__47 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Compute the submerged flow using the total head and coefficients */
/*     defined as a function of head and weir width. On entry Q and HTOT */
/*     should have their free flow values.  Submerged values are */
/*     returned. */
/* SOURCE embank.for:252 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE embank.for:255 */
/*<       integerhcwtab,lcwtab,subtab >*/
/* SOURCE embank.for:256 */
/*<       realdepth,h,hlcrit,htail,htot,l,q >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     HCWTAB - High head weir coefficient table */
/*     LCWTAB - Low head weir coefficient table */
/*     SUBTAB - Address for submergence table */
/*     HLCRIT - Ratio of piezometric head to crest breadth at boundary */
/*              between low head and high head flow */
/*     L      - Crest breadth for the embankment */
/*     H      - Piezometric head */
/*     HTAIL  - Tailwater head */
/*     DEPTH  - Depth of approaching flow */
/*     HTOT   - Total head */
/*     Q      - Flowrate */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE embank.for:272 */
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
/* INCLUDE embank.for:273 */
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
/* INCLUDE embank.for:274 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE embank.for:275 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE embank.for:278 */
/*<       integerknt,ntab >*/
/* SOURCE embank.for:279 */
/*<       realcw,frac,head,pdv,qmax,qw,qwold,rat,ratio >*/
/*     + + + INTRINSICS + + + */
/* SOURCE embank.for:282 */
/*<       intrinsicabs,sqrt >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE embank.for:285 */
/*<       externallktab >*/
/* *********************************************************************** */
/* SOURCE embank.for:287 */
/*<       knt=0 >*/
    // Original-verified STOTHQ iteration; retain historical diagnostic output.
    const int feq_weir_error = feq_submerged_weir(*hcwtab,*lcwtab,*subtab,*hlcrit,*l,*feq_gen_h_d_,
        *htail,*depth,grvcom_1.grav,grvcom_1.grav2,htot,q,&head,&qw,&qwold,&cw,&frac);
    if (feq_weir_error == 1) {
/* SOURCE embank.for:314 */
/*<       write(std6,*)' L=0 IN STOTHQ' >*/
	feq_gen_io_d__41.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsle(&feq_gen_io_d__41);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" L=0 IN STOTHQ"), (ftnlen)14);
	e_wsle();
/* SOURCE embank.for:315 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE embank.for:316 */
/*<       endif >*/
    }
    if (feq_weir_error == 2) {
/* SOURCE embank.for:359 */
/*<       write(std6,*)' KNT > 100 IN STOTHQ.' >*/
	    feq_gen_io_d__46.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsle(&feq_gen_io_d__46);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" KNT > 100 IN STOTHQ."), (ftnlen)21);
	    e_wsle();
/* SOURCE embank.for:360 */
/*<        >*/
	    feq_gen_io_d__47.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsle(&feq_gen_io_d__47);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" STOTHQ: HEAD="), (ftnlen)14);
	    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&head, (ftnlen)sizeof(real));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FRAC="), (ftnlen)6);
	    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&frac, (ftnlen)sizeof(real));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" QW="), (ftnlen)4);
	    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&qw, (ftnlen)sizeof(real));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" QWOLD="), (ftnlen)7);
	    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&qwold, (ftnlen)sizeof(real));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" DEPTH="), (ftnlen)7);
	    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*depth), (ftnlen)sizeof(real));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" CW="), (ftnlen)4);
	    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&cw, (ftnlen)sizeof(real));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" H="), (ftnlen)3);
	    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*feq_gen_h_d_), (ftnlen)sizeof(real));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" HTAIL="), (ftnlen)7);
	    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&(*htail), (ftnlen)sizeof(real));
	    e_wsle();
/* SOURCE embank.for:362 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE embank.for:363 */
/*<       endif >*/
	}
    return 0;
/* SOURCE embank.for:376 */
/*<       end >*/
} /* stothq_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE embank.for:380 */
/*<        >*/
/* Subroutine */ int embsub_(integer *minloc, real *mincrs, integer *noff, 
	char *feq_storage_surf, real *feq_storage_tothl, real *feq_storage_tothr, real *hu, real *hd, doublereal *
	freed, real *ed, ftnlen surf_len)
{
    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer iseg;
    real htot;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real ratio, ratiol, ratior;

/*     + + + PURPOSE + + + */
/*     Find the submergence ratio to use for flow over an embankment */
/*     and the elevation of the tailwater at which submergence */
/*     begins. HU is the piezometric head on the embankment, */
/*     ED is tailwater elevation at which submergence begins. */
/* SOURCE embank.for:390 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE embank.for:393 */
/*<       integerminloc,noff >*/
/* SOURCE embank.for:394 */
/*<       realed,hd,hu,mincrs,tothl(*),tothr(*) >*/
/* SOURCE embank.for:395 */
/*<       real*8freed >*/
/* SOURCE embank.for:396 */
/*<       charactersurf(*)*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     MINLOC - Offset of the minimum crest elevation */
/*     MINCRS - Minimum crest elevation */
/*     NOFF   - Number of offsets */
/*     SURF   - Nature of the embankment surface */
/*     TOTHL  - Total head at left hand end of segment */
/*     TOTHR  - Total head at right hand end of segment */
/*     HU     - Head upstream */
/*     HD     - Tailwater head at free flow limit */
/*     FREED  - Free drop */
/*     ED     - Downstream water surface elevation */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE embank.for:411 */
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
/* INCLUDE embank.for:412 */
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
/* INCLUDE embank.for:413 */
/*     COMMON FOR SUBMERGENCE RATIOS FOR WEIR COMPUTATIONS */
/* SOURCE subcom.cmn:3 */
/*<       common/subcom/prat,grat >*/
/* SOURCE subcom.cmn:5 */
/*<       realprat,grat >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE embank.for:416 */
/*<       integeriseg >*/
/* SOURCE embank.for:417 */
/*<       realhtot,ratio,ratiol,ratior >*/
/*     + + + INTRINSICS + + + */
/* SOURCE embank.for:420 */
/*<       intrinsicmax,min >*/
/* *********************************************************************** */
/*     FIND THE RATIO TO USE FOR DETERMNING THE FREE DROP VALUE */
/* SOURCE embank.for:424 */
/*<       if(minloc.eq.1)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> tothr(feq_storage_tothr, 1);

    feq::IndexedPointer<real> tothl(feq_storage_tothl, 1);

    feq::IndexedPointer<char> surf(feq_storage_surf, 8);

    /* Function Body */
    if (*minloc == 1) {
/* SOURCE embank.for:425 */
/*<       if(surf(minloc).eq.'PAVED')then >*/
	if (s_cmp(surf + (*minloc << 3), const_cast<char*>("PAVED"), (ftnlen)8, (ftnlen)5) == 0) 
		{
/* SOURCE embank.for:426 */
/*<       ratio=prat >*/
	    ratio = subcom_1.prat;
/* SOURCE embank.for:427 */
/*<       else >*/
	} else {
/* SOURCE embank.for:428 */
/*<       ratio=grat >*/
	    ratio = subcom_1.grat;
/* SOURCE embank.for:429 */
/*<       endif >*/
	}
/* SOURCE embank.for:430 */
/*<       elseif(minloc.eq.noff)then >*/
    } else if (*minloc == *noff) {
/* SOURCE embank.for:431 */
/*<       if(surf(minloc-1).eq.'PAVED')then >*/
	if (s_cmp(surf + (*minloc - 1 << 3), const_cast<char*>("PAVED"), (ftnlen)8, (ftnlen)5) ==
		 0) {
/* SOURCE embank.for:432 */
/*<       ratio=prat >*/
	    ratio = subcom_1.prat;
/* SOURCE embank.for:433 */
/*<       else >*/
	} else {
/* SOURCE embank.for:434 */
/*<       ratio=grat >*/
	    ratio = subcom_1.grat;
/* SOURCE embank.for:435 */
/*<       endif >*/
	}
/* SOURCE embank.for:436 */
/*<       else >*/
    } else {
/*       CHECK BOTH SEGMENTS */
/* SOURCE embank.for:438 */
/*<       if(surf(minloc).eq.'PAVED')then >*/
	if (s_cmp(surf + (*minloc << 3), const_cast<char*>("PAVED"), (ftnlen)8, (ftnlen)5) == 0) 
		{
/* SOURCE embank.for:439 */
/*<       ratior=prat >*/
	    ratior = subcom_1.prat;
/* SOURCE embank.for:440 */
/*<       else >*/
	} else {
/* SOURCE embank.for:441 */
/*<       ratior=grat >*/
	    ratior = subcom_1.grat;
/* SOURCE embank.for:442 */
/*<       endif >*/
	}
/* SOURCE embank.for:443 */
/*<       if(surf(minloc-1).eq.'PAVED')then >*/
	if (s_cmp(surf + (*minloc - 1 << 3), const_cast<char*>("PAVED"), (ftnlen)8, (ftnlen)5) ==
		 0) {
/* SOURCE embank.for:444 */
/*<       ratiol=prat >*/
	    ratiol = subcom_1.prat;
/* SOURCE embank.for:445 */
/*<       else >*/
	} else {
/* SOURCE embank.for:446 */
/*<       ratiol=grat >*/
	    ratiol = subcom_1.grat;
/* SOURCE embank.for:447 */
/*<       endif >*/
	}
/* SOURCE embank.for:448 */
/*<       ratio=min(ratiol,ratior) >*/
	ratio = dmin(ratiol,ratior);
/* SOURCE embank.for:449 */
/*<       endif >*/
    }
/*     COMPUTE THE DOWNSTREAM PIEZOMETRIC HEAD AT WHICH SUBMERGENCE */
/*     EFFECT BEGINS FOR AT LEAST ONE POINT ON THE WEIR. */
/*     FIND THE UPSTREAM TOTAL HEAD AT THE MINIMUM POINT */
/* SOURCE embank.for:456 */
/*<       iseg=minloc >*/
    iseg = *minloc;
/* SOURCE embank.for:457 */
/*<       if(minloc.eq.noff)iseg=minloc-1 >*/
    if (*minloc == *noff) {
	iseg = *minloc - 1;
    }
/* SOURCE embank.for:458 */
/*<       htot=max(tothl(iseg),tothr(iseg)) >*/
/* Computing MAX */
    feq_gen_r_d_1 = tothl[iseg], feq_gen_r_d_2 = tothr[iseg];
    htot = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/*      WRITE(STD6,*) ' HTOT AT MINCRS=',HTOT,' MINLOC=',MINLOC */
/*      WRITE(STD6,*) ' RATIO AT MINCRS=',RATIO */
/* SOURCE embank.for:463 */
/*<       hd=ratio*htot >*/
    *hd = static_cast<double>(ratio) * htot;
/* SOURCE embank.for:465 */
/*<       freed=dble(hu)-dble(ratio)*dble(htot) >*/
    *freed = (doublereal) (*hu) - (doublereal) ratio * (doublereal) htot;
/* SOURCE embank.for:467 */
/*<       ed=hd+mincrs >*/
    *ed = static_cast<double>(*hd) + *mincrs;
/* SOURCE embank.for:469 */
/*<       return >*/
    return 0;
/* SOURCE embank.for:470 */
/*<       end >*/
} /* embsub_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE embank.for:474 */
/*<        >*/
/* Subroutine */ int sbfemb_(integer *nfrac, real *eu, real *hu, real *mincrs,
	 integer *minloc, integer *plcwtb, integer *glcwtb, integer *phcwtb, 
	integer *ghcwtb, integer *psubtb, integer *gsubtb, integer *noff, 
	char *feq_storage_surf, real *hlcrit, real *feq_storage_xl, real *feq_storage_xr, real *feq_storage_hl, real *feq_storage_hm, 
	real *feq_storage_hr, real *feq_storage_ql, real *feq_storage_qm, real *feq_storage_qr, real *feq_storage_tothl, real *feq_storage_tothm, 
	real *feq_storage_tothr, real *feq_storage_appl, real *feq_storage_appm, real *feq_storage_appr, real *feq_storage_wl, real *feq_storage_wm, 
	real *feq_storage_wr, real *qfree, real *feq_storage_pfdvec, real *freed, real *feq_storage_qsbvec, 
	ftnlen surf_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:740* Drop to free flow=\002,f10.4\
,\002 < 0.0 in EMBANKQ.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    real ed, hd;
    integer ip;
    real dx, frac;
    integer iseg;
    real qmid, qseg;
    doublereal qsub;
    real depth;
    doublereal fdrop;
    real qleft, shtot;
    integer hcwtab, lcwtab;
    extern /* Subroutine */ int embsub_(integer *, real *, integer *, char *, 
	    real *, real *, real *, real *, doublereal *, real *, ftnlen);
    integer subtab;
    real qright;
    extern /* Subroutine */ int stothq_(integer *, integer *, integer *, real 
	    *, real *, real *, real *, real *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__60 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     SuBmerged Flow EMBankment- Find the submerged flows for */
/*        the given proportions of free drop and the free flow */
/*        parameters computed by FRFEMB. */
/* SOURCE embank.for:487 */
/*<       implicitnone >*/
/* INCLUDE embank.for:489 */
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
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE embank.for:492 */
/*<       integerghcwtb,glcwtb,gsubtb,minloc,nfrac,noff,phcwtb,plcwtb,psubtb >*/
/* SOURCE embank.for:494 */
/*<        >*/
/* SOURCE embank.for:498 */
/*<       charactersurf(*)*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NFRAC  - Number of fractions for defining partial free drop */
/*     EU     - Water surface elevation upstream. */
/*     HU     - Head upstream */
/*     MINCRS - Minimum crest elevation */
/*     MINLOC - Offset of the minimum crest elevation */
/*     PLCWTB - Paved low-head weir coefficient table */
/*     GLCWTB - Gravel surface low head weir coefficient table */
/*     PHCWTB - Paved high-head weir coefficient table */
/*     GHCWTB - Gravel surface high head weir coefficient table */
/*     PSUBTB - Paved submergence table */
/*     GSUBTB - Gravel surface submergence table */
/*     NOFF   - Number of offsets */
/*     SURF   - Nature of the embankment surface */
/*     HLCRIT - Ratio of piezometric head to crest breadth at boundary */
/*              between low head and high head flow */
/*     XL     - Offset at left hand end of segment */
/*     XR     - Offset at right hand end of segment */
/*     HL     - Piezometric head on left end of segment */
/*     HM     - Piezometric head on middle of segment */
/*     HR     - Piezometric head on right end of segment */
/*     QL     - Flow on left hand end of segment */
/*     QM     - Flow at middle of the segment */
/*     QR     - Flow on right hand end of segment */
/*     TOTHL  - Total head at left hand end of segment */
/*     TOTHM  - Total head at middle of segment */
/*     TOTHR  - Total head at right hand end of segment */
/*     APPL   - Elevation of approach at left end of line segment */
/*     APPM   - Elevation of approach at middle of line segment */
/*     APPR   - Elevation of approach at right end of line segment */
/*     WL     - Breadth of the crest at left hand end of segment */
/*     WM     - Breadth of the crest at middle of segment */
/*     WR     - Breadth of the crest at right hand end of segment */
/*     QFREE  - Free flow */
/*     PFDVEC - Partial free drop vector */
/*     FREED  - Free drop */
/*     QSBVEC - Submerged flow for each partial free drop */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE embank.for:539 */
/*<       integerhcwtab,ip,iseg,lcwtab,subtab >*/
/* SOURCE embank.for:540 */
/*<       realdepth,dx,ed,frac,hd,qleft,qmid,qright,qseg,shtot >*/
/* SOURCE embank.for:541 */
/*<       doubleprecisionqsub,fdrop >*/
/*     + + + INTRINSICS + + + */
/* SOURCE embank.for:544 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE embank.for:547 */
/*<       externalembsub,stothq >*/
/*     *******************************FORMATS**************************** */
/* SOURCE embank.for:549 */
/*<    50  >*/
/* *********************************************************************** */
/*         COMPUTE THE SUBMERGENCE EFFECT OVER THE RANGE OF TAIL WATER */
/*         ELEVATIONS WHICH CAN AFFECT THE FLOW OVER THE EMBANKMENT. */
/*         FOR THE GIVEN UPSTREAM PIEZOMETRIC HEAD, FIND THE */
/*         DROP BETWEEN THE UPSTREAM AND DOWNSTREAM PIEZOMETRIC HEADS */
/*         REQUIRED TO ENABLE FREE FLOW. */
/*         THE DOWNSTREAM EFFECT IS FIRST FELT AT THE POINT OF MAXIMUM */
/*         HEAD.  RATIO OF TAILWATER PIEZOMETRIC HEAD TO THE UPSTREAM */
/*         TOTAL HEAD IS THE ARGUMENT USED BY THE USGS. */
/* SOURCE embank.for:563 */
/*<       callembsub(minloc,mincrs,noff,surf,tothl,tothr,hu,hd,fdrop,ed) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> qsbvec(feq_storage_qsbvec, 1);

    feq::IndexedPointer<real> pfdvec(feq_storage_pfdvec, 1);

    feq::IndexedPointer<real> wr(feq_storage_wr, 1);

    feq::IndexedPointer<real> wm(feq_storage_wm, 1);

    feq::IndexedPointer<real> wl(feq_storage_wl, 1);

    feq::IndexedPointer<real> appr(feq_storage_appr, 1);

    feq::IndexedPointer<real> appm(feq_storage_appm, 1);

    feq::IndexedPointer<real> appl(feq_storage_appl, 1);

    feq::IndexedPointer<real> tothr(feq_storage_tothr, 1);

    feq::IndexedPointer<real> tothm(feq_storage_tothm, 1);

    feq::IndexedPointer<real> tothl(feq_storage_tothl, 1);

    feq::IndexedPointer<real> qr(feq_storage_qr, 1);

    feq::IndexedPointer<real> qm(feq_storage_qm, 1);

    feq::IndexedPointer<real> ql(feq_storage_ql, 1);

    feq::IndexedPointer<real> hr(feq_storage_hr, 1);

    feq::IndexedPointer<real> hm(feq_storage_hm, 1);

    feq::IndexedPointer<real> hl(feq_storage_hl, 1);

    feq::IndexedPointer<real> xr(feq_storage_xr, 1);

    feq::IndexedPointer<real> xl(feq_storage_xl, 1);

    feq::IndexedPointer<char> surf(feq_storage_surf, 8);

    /* Function Body */
/* L50: */
    embsub_(minloc, mincrs, noff, surf + 8, &tothl[1], &tothr[1], hu, &hd, &
	    fdrop, &ed, (ftnlen)8);
/* SOURCE embank.for:566 */
/*<       freed=fdrop >*/
    *freed = fdrop;
/* SOURCE embank.for:568 */
/*<       if(freed.lt.0.0)then >*/
    if (*freed < (float)0.) {
/* SOURCE embank.for:569 */
/*<       write(std6,50)freed >*/
	feq_gen_io_d__60.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsfe(&feq_gen_io_d__60);
	do_fio(&feq_gen_c_d_1, (char *)&(*freed), (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE embank.for:570 */
/*<       stop'Abnormal stop. Error found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Error found."), (ftnlen)27);
/* SOURCE embank.for:571 */
/*<       endif >*/
    }
/*          WRITE(STD6,*) ' ' */
/*          WRITE(STD6,*) ' AT FREE DROP. EU=',EU,' ED=',ED */
/*          WRITE(STD6,'('' FREE DROP='',F10.3)') FREED */
/*         NOW FOR A SERIES OF PROPORTIONS OF THE FREE DROP COMPUTE */
/*         THE FLOW OVER THE EMBANKMENT. AT ZERO PROPORTION OF FREE DROP */
/*         THE FLOW IS ZERO AND AT FREE DROP THE FLOW IS THE FREE FLOW. */
/*         THE ZERO FLOW AND THE FREE FLOW CONDITION ARE KNOWN SO THEY */
/*         ARE NOT RECOMPUTED. */
/* SOURCE embank.for:582 */
/*<       qsbvec(1)=0.0 >*/
    qsbvec[1] = (float)0.;
/* SOURCE embank.for:583 */
/*<       qsbvec(nfrac)=qfree >*/
    qsbvec[*nfrac] = *qfree;
/* SOURCE embank.for:584 */
/*<       do4500ip=nfrac-1,2,-1 >*/
    for (ip = *nfrac - 1; ip >= 2; --ip) {
/* SOURCE embank.for:585 */
/*<       qsub=0.d0 >*/
	qsub = 0.;
/* SOURCE embank.for:586 */
/*<       frac=pfdvec(ip) >*/
	frac = pfdvec[ip];
/*            WRITE(STDOUT,*) ' ' */
/*            WRITE(STDOUT,*) ' SUBMERGED FLOWS' */
/*            WRITE(STDOUT,*) ' FRAC=',FRAC */
/*           COMPUTE THE DOWNSTREAM WATER SURFACE ELEVATION FOR THIS */
/*           FRACTION OF THE FREE DROP */
/* SOURCE embank.for:595 */
/*<       ed=eu-dble(frac)*fdrop >*/
	ed = *eu - (doublereal) frac * fdrop;
/*            WRITE(STDOUT,'('' EU='',F10.4,'' ED='',F10.4)') EU, ED */
/*           FOR EACH SEGMENT OF THE WEIR FIND THE EFFECT OF THIS */
/*           VALUE OF DOWNSTREAM PIEZOMETRIC HEAD */
/* SOURCE embank.for:602 */
/*<       do4100iseg=1,noff-1 >*/
	feq_gen_i_d_1 = *noff - 1;
	for (iseg = 1; iseg <= feq_gen_i_d_1; ++iseg) {
/*              WRITE(STDOUT,*) ' ' */
/*              WRITE(STDOUT,*) ' ISEG=',ISEG */
/*             SELECT THE TABLE FOR SUBMERGENCE */
/* SOURCE embank.for:608 */
/*<       if(surf(iseg).eq.'PAVED')then >*/
	    if (s_cmp(surf + (iseg << 3), const_cast<char*>("PAVED"), (ftnlen)8, (ftnlen)5) == 0)
		     {
/* SOURCE embank.for:609 */
/*<       subtab=psubtb >*/
		subtab = *psubtb;
/* SOURCE embank.for:610 */
/*<       else >*/
	    } else {
/* SOURCE embank.for:611 */
/*<       subtab=gsubtb >*/
		subtab = *gsubtb;
/* SOURCE embank.for:612 */
/*<       endif >*/
	    }
/*             SELECT THE WEIR COEF. TABLES BASED ON THE SURFACE CONDITION. */
/* SOURCE embank.for:615 */
/*<       if(surf(iseg).eq.'PAVED')then >*/
	    if (s_cmp(surf + (iseg << 3), const_cast<char*>("PAVED"), (ftnlen)8, (ftnlen)5) == 0)
		     {
/* SOURCE embank.for:616 */
/*<       hcwtab=phcwtb >*/
		hcwtab = *phcwtb;
/* SOURCE embank.for:617 */
/*<       lcwtab=plcwtb >*/
		lcwtab = *plcwtb;
/* SOURCE embank.for:618 */
/*<       else >*/
	    } else {
/* SOURCE embank.for:619 */
/*<       hcwtab=ghcwtb >*/
		hcwtab = *ghcwtb;
/* SOURCE embank.for:620 */
/*<       lcwtab=glcwtb >*/
		lcwtab = *glcwtb;
/* SOURCE embank.for:621 */
/*<       endif >*/
	    }
/* SOURCE embank.for:622 */
/*<       if(hl(iseg).gt.0.0.or.hr(iseg).gt.0.0)then >*/
	    if (hl[iseg] > (float)0. || hr[iseg] > (float)0.) {
/*               SEGMENT HAS NON-ZERO FREE FLOW */
/* SOURCE embank.for:625 */
/*<       qleft=ql(iseg) >*/
		qleft = ql[iseg];
/* SOURCE embank.for:626 */
/*<       shtot=tothl(iseg) >*/
		shtot = tothl[iseg];
/* SOURCE embank.for:627 */
/*<       if(qleft.gt.0.0)then >*/
		if (qleft > (float)0.) {
/*                 NOTE THAT THE UPSTREAM WATER SURFACE ELEVATION */
/*                 LESS THE PIEZOMETRIC HEAD GIVES THE WEIR CREST */
/*                 ELEVATION */
/* SOURCE embank.for:632 */
/*<       hd=ed-(eu-hl(iseg)) >*/
		    hd = static_cast<double>(ed) - (static_cast<double>(*eu) - hl[iseg]);
/* SOURCE embank.for:633 */
/*<       if(hd.lt.0.0)hd=0.0 >*/
		    if (hd < (float)0.) {
			hd = (float)0.;
		    }
/* SOURCE embank.for:635 */
/*<       depth=eu-appl(iseg) >*/
		    depth = static_cast<double>(*eu) - appl[iseg];
/* SOURCE embank.for:636 */
/*<        >*/
		    stothq_(&hcwtab, &lcwtab, &subtab, hlcrit, &wl[iseg], &hl[
			    iseg], &hd, &depth, &shtot, &qleft);
/* SOURCE embank.for:641 */
/*<       else >*/
		} else {
/* SOURCE embank.for:642 */
/*<       qleft=0.0 >*/
		    qleft = (float)0.;
/* SOURCE embank.for:643 */
/*<       endif >*/
		}
/*               WRITE(STDOUT,*) ' LEFT: DEPTH=',DEPTH,' HD=',HD,' QLEFT=', */
/*    A                     QLEFT,' SHTOT=',SHTOT, ' HEAD=',HL(ISEG) */
/* SOURCE embank.for:648 */
/*<       qmid=qm(iseg) >*/
		qmid = qm[iseg];
/* SOURCE embank.for:649 */
/*<       shtot=tothm(iseg) >*/
		shtot = tothm[iseg];
/* SOURCE embank.for:650 */
/*<       if(qmid.gt.0.0)then >*/
		if (qmid > (float)0.) {
/* SOURCE embank.for:651 */
/*<       hd=ed-(eu-hm(iseg)) >*/
		    hd = static_cast<double>(ed) - (static_cast<double>(*eu) - hm[iseg]);
/* SOURCE embank.for:652 */
/*<       if(hd.lt.0.0)hd=0.0 >*/
		    if (hd < (float)0.) {
			hd = (float)0.;
		    }
/* SOURCE embank.for:653 */
/*<       depth=eu-appm(iseg) >*/
		    depth = static_cast<double>(*eu) - appm[iseg];
/* SOURCE embank.for:654 */
/*<        >*/
		    stothq_(&hcwtab, &lcwtab, &subtab, hlcrit, &wm[iseg], &hm[
			    iseg], &hd, &depth, &shtot, &qmid);
/* SOURCE embank.for:660 */
/*<       else >*/
		} else {
/* SOURCE embank.for:661 */
/*<       qmid=0.0 >*/
		    qmid = (float)0.;
/* SOURCE embank.for:662 */
/*<       endif >*/
		}
/*               WRITE(STDOUT,*) ' MID: DEPTH=',DEPTH,' HD=',HD,' QMID=', */
/*    A                     QMID,' SHTOT=',SHTOT, ' HEAD=',HM(ISEG) */
/* SOURCE embank.for:667 */
/*<       qright=qr(iseg) >*/
		qright = qr[iseg];
/* SOURCE embank.for:668 */
/*<       shtot=tothr(iseg) >*/
		shtot = tothr[iseg];
/* SOURCE embank.for:669 */
/*<       if(qright.gt.0.0)then >*/
		if (qright > (float)0.) {
/* SOURCE embank.for:670 */
/*<       hd=ed-(eu-hr(iseg)) >*/
		    hd = static_cast<double>(ed) - (static_cast<double>(*eu) - hr[iseg]);
/* SOURCE embank.for:671 */
/*<       if(hd.lt.0.0)hd=0.0 >*/
		    if (hd < (float)0.) {
			hd = (float)0.;
		    }
/* SOURCE embank.for:672 */
/*<       depth=eu-appr(iseg) >*/
		    depth = static_cast<double>(*eu) - appr[iseg];
/* SOURCE embank.for:673 */
/*<        >*/
		    stothq_(&hcwtab, &lcwtab, &subtab, hlcrit, &wr[iseg], &hr[
			    iseg], &hd, &depth, &shtot, &qright);
/* SOURCE embank.for:678 */
/*<       else >*/
		} else {
/* SOURCE embank.for:679 */
/*<       qright=0.0 >*/
		    qright = (float)0.;
/* SOURCE embank.for:680 */
/*<       endif >*/
		}
/*               WRITE(STDOUT,*) ' RIGHT: DEPTH=',DEPTH,' HD=',HD,' QRIGHT=', */
/*    A                     QRIGHT,' SHTOT=',SHTOT, ' HEAD=',HR(ISEG) */
/*               NOW COMPUTE THE FLOW AS AFFECTED BY SUBMERGENCE */
/* SOURCE embank.for:687 */
/*<       dx=abs(xr(iseg)-xl(iseg)) >*/
		// Qsegment = abs(XR-XL)*(Qleft+4*Qmid+Qright)/6.
        // Original 0x42ff92..0x42ffb5 retains the width and segment flow wide,
        // and multiplies by the REAL reciprocal at 0x56cf40 before adding QSUB.
        const double feq_width = (std::abs)(static_cast<double>(xr[iseg])-xl[iseg]);
        const double feq_flow = (static_cast<double>(qmid)*4.0+qleft)+qright;
        qsub += (feq_width*feq_flow)*static_cast<double>(0.1666666716337204F);
/* SOURCE embank.for:701 */
/*<       endif >*/
	    }
/* SOURCE embank.for:702 */
/*<  4100 continue >*/
/* L4100: */
	}
/*           STORE THE VALUE AT THIS FRACTION OF THE FREE DROP */
/* SOURCE embank.for:706 */
/*<       qsbvec(ip)=qsub >*/
	qsbvec[ip] = qsub;
/* SOURCE embank.for:707 */
/*<  4500 continue >*/
/* L4500: */
    }
/* SOURCE embank.for:710 */
/*<       return >*/
    return 0;
/* SOURCE embank.for:711 */
/*<       end >*/
} /* sbfemb_ */




/* SOURCE embank.for:715 */
/*<        >*/
/* Subroutine */ int frfemb_(real *hu, real *mincrs, integer *plcwtb, integer 
	*glcwtb, integer *phcwtb, integer *ghcwtb, integer *noff, real *feq_storage_off, 
	real *feq_storage_crest, real *feq_storage_width, real *feq_storage_approc, char *feq_storage_surf, real *rmffac, 
	real *hlcrit, real *hlmax, integer *hlflag, integer *hpflag, real *eu,
	 real *feq_storage_xl, real *feq_storage_xr, real *feq_storage_hl, real *feq_storage_hm, real *feq_storage_hr, real *feq_storage_ql, real *feq_storage_qm,
	 real *feq_storage_qr, real *feq_storage_tothl, real *feq_storage_tothm, real *feq_storage_tothr, real *feq_storage_yfl, real *
	feq_storage_yfm, real *feq_storage_yfr, real *feq_storage_appl, real *feq_storage_appm, real *feq_storage_appr, real *feq_storage_wl, real *
	feq_storage_wm, real *feq_storage_wr, real *feq_storage_aell, real *feq_storage_aelm, real *feq_storage_aelr, real *qfree, real *
	mfree, real *efree, ftnlen surf_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    doublereal ef, mf;
    integer il;
    doublereal qf;
    integer ir;
    real dx, eseg;
    integer iseg;
    real mseg, qseg, srat, depth, ratio;
    integer hcwtab, lcwtab;
    extern /* Subroutine */ int ftothq_(integer *, integer *, real *, real *, 
	    real *, real *, real *, real *, integer *, integer *, real *, 
	    real *, real *, real *);

/*     + + + PURPOSE + + + */
/*     FRee Flow EMBankment- Find free flow over an embankment */
/*     for a given upstream water surface elevation. */
/* SOURCE embank.for:729 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE embank.for:732 */
/*<       integerghcwtb,glcwtb,hlflag,hpflag,noff,phcwtb,plcwtb >*/
/* SOURCE embank.for:733 */
/*<        >*/
/* SOURCE embank.for:738 */
/*<       charactersurf(*)*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     HU     - Head upstream */
/*     MINCRS - Minimum crest elevation */
/*     PLCWTB - Paved low-head weir coefficient table */
/*     GLCWTB - Gravel surface low head weir coefficient table */
/*     PHCWTB - Paved high-head weir coefficient table */
/*     GHCWTB - Gravel surface high head weir coefficient table */
/*     NOFF   - Number of offsets */
/*     OFF    - Offsets for the crest of the embankment */
/*     CREST  - Crest profile for the high point on the embankment */
/*     WIDTH  - Breadth of the embankment crest */
/*     APPROC - Elevation of approach for the embankment */
/*     SURF   - Nature of the embankment surface */
/*     RMFFAC - Adjustment factor for roadway momentum flux */
/*     HLCRIT - Ratio of piezometric head to crest breadth at boundary */
/*              between low head and high head flow */
/*     HLMAX  - Maximum value of piezometric head to crest breadth ratio */
/*               above which a warning message is issued */
/*     HLFLAG - Warning message suppression flag */
/*     HPFLAG - Warning message suppression flag for invalid weir flow */
/*     EU     - Water surface elevation upstream. */
/*     XL     - Offset at left hand end of segment */
/*     XR     - Offset at right hand end of segment */
/*     HL     - Piezometric head on left end of segment */
/*     HM     - Piezometric head on middle of segment */
/*     HR     - Piezometric head on right end of segment */
/*     QL     - Flow on left hand end of segment */
/*     QM     - Flow at middle of the segment */
/*     QR     - Flow on right hand end of segment */
/*     TOTHL  - Total head at left hand end of segment */
/*     TOTHM  - Total head at middle of segment */
/*     TOTHR  - Total head at right hand end of segment */
/*     YFL    - Estimated depth at crest at left hand end of segment */
/*     YFM    - Estimated depth at crest at middle of segment */
/*     YFR    - Estimated depth at crest at right hand end of segment */
/*     APPL   - Elevation of approach at left end of line segment */
/*     APPM   - Elevation of approach at middle of line segment */
/*     APPR   - Elevation of approach at right end of line segment */
/*     WL     - Breadth of the crest at left hand end of segment */
/*     WM     - Breadth of the crest at middle of segment */
/*     WR     - Breadth of the crest at right hand end of segment */
/*     AELL   - Estimated ratio of head loss to head loss at incipient */
/*              submergence at left end of line segment */
/*     AELM   - Estimated ratio of head loss to head loss at incipient */
/*              submergence at middle of line segment */
/*     AELR   - Estimated ratio of head loss to head loss at incipient */
/*              submergence at right end of line segment */
/*     QFREE  - Free flow */
/*     MFREE  - Momentum flux over roadway for free flow */
/*     EFREE  - Estimated energy flux for free flow over the embankment */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE embank.for:792 */
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
/* INCLUDE embank.for:793 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE embank.for:794 */
/*     COMMON FOR SUBMERGENCE RATIOS FOR WEIR COMPUTATIONS */
/* SOURCE subcom.cmn:3 */
/*<       common/subcom/prat,grat >*/
/* SOURCE subcom.cmn:5 */
/*<       realprat,grat >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE embank.for:797 */
/*<       integerhcwtab,il,ir,iseg,lcwtab >*/
/* SOURCE embank.for:798 */
/*<       realdepth,dx,eseg,mseg,qseg,ratio,srat >*/
/* SOURCE embank.for:799 */
/*<       doubleprecisionef,mf,qf >*/
/*     + + + INTRINSICS + + + */
/* SOURCE embank.for:802 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE embank.for:805 */
/*<       externalftothq >*/
/* *********************************************************************** */
/*       COMPUTE THE ELEVATION OF THE UPSTREAM WATER SURFACE */
/* SOURCE embank.for:809 */
/*<       eu=hu+mincrs >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> aelr(feq_storage_aelr, 1);

    feq::IndexedPointer<real> aelm(feq_storage_aelm, 1);

    feq::IndexedPointer<real> aell(feq_storage_aell, 1);

    feq::IndexedPointer<real> wr(feq_storage_wr, 1);

    feq::IndexedPointer<real> wm(feq_storage_wm, 1);

    feq::IndexedPointer<real> wl(feq_storage_wl, 1);

    feq::IndexedPointer<real> appr(feq_storage_appr, 1);

    feq::IndexedPointer<real> appm(feq_storage_appm, 1);

    feq::IndexedPointer<real> appl(feq_storage_appl, 1);

    feq::IndexedPointer<real> yfr(feq_storage_yfr, 1);

    feq::IndexedPointer<real> yfm(feq_storage_yfm, 1);

    feq::IndexedPointer<real> yfl(feq_storage_yfl, 1);

    feq::IndexedPointer<real> tothr(feq_storage_tothr, 1);

    feq::IndexedPointer<real> tothm(feq_storage_tothm, 1);

    feq::IndexedPointer<real> tothl(feq_storage_tothl, 1);

    feq::IndexedPointer<real> qr(feq_storage_qr, 1);

    feq::IndexedPointer<real> qm(feq_storage_qm, 1);

    feq::IndexedPointer<real> ql(feq_storage_ql, 1);

    feq::IndexedPointer<real> hr(feq_storage_hr, 1);

    feq::IndexedPointer<real> hm(feq_storage_hm, 1);

    feq::IndexedPointer<real> hl(feq_storage_hl, 1);

    feq::IndexedPointer<real> xr(feq_storage_xr, 1);

    feq::IndexedPointer<real> xl(feq_storage_xl, 1);

    feq::IndexedPointer<char> surf(feq_storage_surf, 8);

    feq::IndexedPointer<real> approc(feq_storage_approc, 1);

    feq::IndexedPointer<real> width(feq_storage_width, 1);

    feq::IndexedPointer<real> crest(feq_storage_crest, 1);

    feq::IndexedPointer<real> off(feq_storage_off, 1);

    /* Function Body */
    *eu = static_cast<double>(*hu) + *mincrs;
/* SOURCE embank.for:811 */
/*<       qf=0.d0 >*/
    qf = 0.;
/* SOURCE embank.for:812 */
/*<       mf=0.d0 >*/
    mf = 0.;
/* SOURCE embank.for:813 */
/*<       ef=0.d0 >*/
    ef = 0.;
/* SOURCE embank.for:814 */
/*<       do4000iseg=1,noff-1 >*/
    feq_gen_i_d_1 = *noff - 1;
    for (iseg = 1; iseg <= feq_gen_i_d_1; ++iseg) {
/* SOURCE embank.for:815 */
/*<       il=iseg >*/
	il = iseg;
/* SOURCE embank.for:816 */
/*<       ir=iseg+1 >*/
	ir = iseg + 1;
/*         Compute free flow for each segment to get the total. */
/*         retain the intermediate values to use for subsequent */
/*         submergence computations. */
/*         For each straight line segment of the weir crest find the */
/*         left and right limits for the wetted length. Four cases: */
/*         entire crest is above water, entire crest is below water, */
/*         left end is below water and right end is above water, */
/*         and right end is below water and left end is above water. */
/*         Water level is taken at piezometric head level and not at */
/*         actual wetted length because actual wetted length is unknown */
/*         and limited tests show that using the piezometric head */
/*         yields values close to experiment for triangular weirs. */
/* SOURCE embank.for:832 */
/*<       if(eu.gt.crest(il).and.eu.gt.crest(ir))then >*/
	if (*eu > crest[il] && *eu > crest[ir]) {
/*           ENTIRE CREST BELOW WATER */
/* SOURCE embank.for:834 */
/*<       xl(iseg)=off(il) >*/
	    xl[iseg] = off[il];
/* SOURCE embank.for:835 */
/*<       xr(iseg)=off(ir) >*/
	    xr[iseg] = off[ir];
/* SOURCE embank.for:836 */
/*<       hl(iseg)=eu-crest(il) >*/
	    hl[iseg] = static_cast<double>(*eu) - crest[il];
/* SOURCE embank.for:837 */
/*<       hr(iseg)=eu-crest(ir) >*/
	    hr[iseg] = static_cast<double>(*eu) - crest[ir];
/* SOURCE embank.for:838 */
/*<       appl(iseg)=approc(il) >*/
	    appl[iseg] = approc[il];
/* SOURCE embank.for:839 */
/*<       appr(iseg)=approc(ir) >*/
	    appr[iseg] = approc[ir];
/* SOURCE embank.for:840 */
/*<       wl(iseg)=width(il) >*/
	    wl[iseg] = width[il];
/* SOURCE embank.for:841 */
/*<       wr(iseg)=width(ir) >*/
	    wr[iseg] = width[ir];
/* SOURCE embank.for:842 */
/*<       elseif(eu.gt.crest(il).and.eu.le.crest(ir))then >*/
	} else if (*eu > crest[il] && *eu <= crest[ir]) {
/*           LEFT END WET AND RIGHT END DRY */
/* SOURCE embank.for:844 */
/*<       xl(iseg)=off(il) >*/
	    xl[iseg] = off[il];
/* SOURCE embank.for:845 */
/*<       wl(iseg)=width(il) >*/
	    wl[iseg] = width[il];
/* SOURCE embank.for:846 */
/*<       appl(iseg)=approc(il) >*/
	    appl[iseg] = approc[il];
/* SOURCE embank.for:847 */
/*<       hl(iseg)=eu-crest(il) >*/
	    hl[iseg] = static_cast<double>(*eu) - crest[il];
/* SOURCE embank.for:849 */
/*<        >*/
	    xr[iseg] = static_cast<double>(off[il]) + static_cast<double>(static_cast<double>((static_cast<double>(off[ir]) - off[il])) * (static_cast<double>(*eu) - crest[il])) / (
		    static_cast<double>(crest[ir]) - crest[il]);
/* SOURCE embank.for:852 */
/*<       ratio=(xr(iseg)-off(il))/(off(ir)-off(il)) >*/
	    ratio = static_cast<double>((static_cast<double>(xr[iseg]) - off[il])) / (static_cast<double>(off[ir]) - off[il]);
/* SOURCE embank.for:853 */
/*<       wr(iseg)=width(il)+ratio*(width(ir)-width(il)) >*/
	    wr[iseg] = static_cast<double>(width[il]) + static_cast<double>(ratio) * (static_cast<double>(width[ir]) - width[il]);
/* SOURCE embank.for:854 */
/*<       appr(iseg)=approc(il)+ratio*(approc(ir)-approc(il)) >*/
	    appr[iseg] = static_cast<double>(approc[il]) + static_cast<double>(ratio) * (static_cast<double>(approc[ir]) - approc[il]);
/* SOURCE embank.for:855 */
/*<       hr(iseg)=0.0 >*/
	    hr[iseg] = (float)0.;
/* SOURCE embank.for:856 */
/*<       elseif(eu.le.crest(il).and.eu.gt.crest(ir))then >*/
	} else if (*eu <= crest[il] && *eu > crest[ir]) {
/*           LEFT END DRY AND RIGHT END WET */
/* SOURCE embank.for:858 */
/*<        >*/
	    xl[iseg] = static_cast<double>(off[ir]) + static_cast<double>(static_cast<double>((static_cast<double>(*eu) - crest[ir])) * (static_cast<double>(off[il]) - off[ir])) / (
		    static_cast<double>(crest[il]) - crest[ir]);
/* SOURCE embank.for:861 */
/*<       ratio=(xl(iseg)-off(ir))/(off(il)-off(ir)) >*/
	    ratio = static_cast<double>((static_cast<double>(xl[iseg]) - off[ir])) / (static_cast<double>(off[il]) - off[ir]);
/* SOURCE embank.for:862 */
/*<       wl(iseg)=width(ir)+ratio*(width(il)-width(ir)) >*/
	    wl[iseg] = static_cast<double>(width[ir]) + static_cast<double>(ratio) * (static_cast<double>(width[il]) - width[ir]);
/* SOURCE embank.for:863 */
/*<       appl(iseg)=approc(ir)+ratio*(approc(il)-approc(ir)) >*/
	    appl[iseg] = static_cast<double>(approc[ir]) + static_cast<double>(ratio) * (static_cast<double>(approc[il]) - approc[ir]);
/* SOURCE embank.for:864 */
/*<       hl(iseg)=0.0 >*/
	    hl[iseg] = (float)0.;
/* SOURCE embank.for:866 */
/*<       xr(iseg)=off(ir) >*/
	    xr[iseg] = off[ir];
/* SOURCE embank.for:867 */
/*<       wr(iseg)=width(ir) >*/
	    wr[iseg] = width[ir];
/* SOURCE embank.for:868 */
/*<       appr(iseg)=approc(ir) >*/
	    appr[iseg] = approc[ir];
/* SOURCE embank.for:869 */
/*<       hr(iseg)=eu-crest(ir) >*/
	    hr[iseg] = static_cast<double>(*eu) - crest[ir];
/* SOURCE embank.for:870 */
/*<       else >*/
	} else {
/*           LEFT END DRY AND RIGHT END DRY */
/* SOURCE embank.for:873 */
/*<       hl(iseg)=-1.0 >*/
	    hl[iseg] = (float)-1.;
/* SOURCE embank.for:874 */
/*<       hr(iseg)=-1.0 >*/
	    hr[iseg] = (float)-1.;
/* SOURCE embank.for:875 */
/*<       goto4000 >*/
	    goto L4000;
/* SOURCE embank.for:876 */
/*<       endif >*/
	}
/*         COMPUTE THE MIDPOINT VALUES */
/* SOURCE embank.for:881 */
/*<       hm(iseg)=0.5*(hr(iseg)+hl(iseg)) >*/
	hm[iseg] = static_cast<double>((static_cast<double>(hr[iseg]) + hl[iseg])) * (float).5;
/* SOURCE embank.for:882 */
/*<       wm(iseg)=0.5*(wr(iseg)+wl(iseg)) >*/
	wm[iseg] = static_cast<double>((static_cast<double>(wr[iseg]) + wl[iseg])) * (float).5;
/* SOURCE embank.for:883 */
/*<       appm(iseg)=0.5*(appl(iseg)+appr(iseg)) >*/
	appm[iseg] = static_cast<double>((static_cast<double>(appl[iseg]) + appr[iseg])) * (float).5;
/*          WRITE(STDOUT,*)  ' CHECK OF THE WEIR SEGMENT VALUES' */
/*          WRITE(STDOUT,*) ' ISEG=',ISEG */
/*          WRITE(STDOUT,'(''   X:'',2F10.2)') XL(ISEG), XR(ISEG) */
/*          WRITE(STDOUT,'(''   W:'',2F10.2)') WL(ISEG), WR(ISEG) */
/*          WRITE(STDOUT,'(''   H:'',2F10.4)') HL(ISEG), HR(ISEG) */
/*          WRITE(STDOUT,'('' APP:'',2F10.2)') APPL(ISEG), APPR(ISEG) */
/*         FOR EACH OF THE THREE LOCATIONS ALONG THIS SEGMENT COMPUTE */
/*         THE FLOW PER UNIT LENTH OF THE WEIR.  THE FLOW AT ZERO */
/*         PIEZOMETRIC HEAD IS TAKEN AS ZERO. */
/*         SELECT THE TABLES BASED ON THE SURFACE CONDITION. */
/* SOURCE embank.for:900 */
/*<       if(surf(iseg).eq.'PAVED')then >*/
	if (s_cmp(surf + (iseg << 3), const_cast<char*>("PAVED"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE embank.for:901 */
/*<       hcwtab=phcwtb >*/
	    hcwtab = *phcwtb;
/* SOURCE embank.for:902 */
/*<       lcwtab=plcwtb >*/
	    lcwtab = *plcwtb;
/* SOURCE embank.for:903 */
/*<       srat=prat >*/
	    srat = subcom_1.prat;
/* SOURCE embank.for:904 */
/*<       else >*/
	} else {
/* SOURCE embank.for:905 */
/*<       hcwtab=ghcwtb >*/
	    hcwtab = *ghcwtb;
/* SOURCE embank.for:906 */
/*<       lcwtab=glcwtb >*/
	    lcwtab = *glcwtb;
/* SOURCE embank.for:907 */
/*<       srat=grat >*/
	    srat = subcom_1.grat;
/* SOURCE embank.for:908 */
/*<       endif >*/
	}
/* SOURCE embank.for:911 */
/*<       if(hl(iseg).le.0.0)then >*/
	if (hl[iseg] <= (float)0.) {
/* SOURCE embank.for:912 */
/*<       ql(iseg)=0.0 >*/
	    ql[iseg] = (float)0.;
/* SOURCE embank.for:913 */
/*<       tothl(iseg)=0.0 >*/
	    tothl[iseg] = (float)0.;
/* SOURCE embank.for:914 */
/*<       yfl(iseg)=1.0 >*/
	    yfl[iseg] = (float)1.;
/* SOURCE embank.for:915 */
/*<       else >*/
	} else {
/* SOURCE embank.for:916 */
/*<       depth=eu-appl(iseg) >*/
	    depth = static_cast<double>(*eu) - appl[iseg];
/* SOURCE embank.for:917 */
/*<        >*/
	    ftothq_(&hcwtab, &lcwtab, hlcrit, hlmax, &srat, &wl[iseg], &hl[
		    iseg], &depth, hlflag, hpflag, &ql[iseg], &tothl[iseg], &
		    yfl[iseg], &aell[iseg]);
/* SOURCE embank.for:922 */
/*<       endif >*/
	}
/* SOURCE embank.for:925 */
/*<       if(hm(iseg).le.0.0)then >*/
	if (hm[iseg] <= (float)0.) {
/* SOURCE embank.for:926 */
/*<       qm(iseg)=0.0 >*/
	    qm[iseg] = (float)0.;
/* SOURCE embank.for:927 */
/*<       tothm(iseg)=0.0 >*/
	    tothm[iseg] = (float)0.;
/* SOURCE embank.for:928 */
/*<       yfm(iseg)=1.0 >*/
	    yfm[iseg] = (float)1.;
/* SOURCE embank.for:929 */
/*<       else >*/
	} else {
/* SOURCE embank.for:930 */
/*<       depth=eu-appm(iseg) >*/
	    depth = static_cast<double>(*eu) - appm[iseg];
/* SOURCE embank.for:931 */
/*<        >*/
	    ftothq_(&hcwtab, &lcwtab, hlcrit, hlmax, &srat, &wm[iseg], &hm[
		    iseg], &depth, hlflag, hpflag, &qm[iseg], &tothm[iseg], &
		    yfm[iseg], &aelm[iseg]);
/* SOURCE embank.for:936 */
/*<       endif >*/
	}
/* SOURCE embank.for:939 */
/*<       if(hr(iseg).le.0.0)then >*/
	if (hr[iseg] <= (float)0.) {
/* SOURCE embank.for:940 */
/*<       qr(iseg)=0.0 >*/
	    qr[iseg] = (float)0.;
/* SOURCE embank.for:941 */
/*<       tothr(iseg)=0.0 >*/
	    tothr[iseg] = (float)0.;
/* SOURCE embank.for:942 */
/*<       yfr(iseg)=1.0 >*/
	    yfr[iseg] = (float)1.;
/* SOURCE embank.for:943 */
/*<       else >*/
	} else {
/* SOURCE embank.for:944 */
/*<       depth=eu-appr(iseg) >*/
	    depth = static_cast<double>(*eu) - appr[iseg];
/* SOURCE embank.for:945 */
/*<        >*/
	    ftothq_(&hcwtab, &lcwtab, hlcrit, hlmax, &srat, &wr[iseg], &hr[
		    iseg], &depth, hlflag, hpflag, &qr[iseg], &tothr[iseg], &
		    yfr[iseg], &aelr[iseg]);
/* SOURCE embank.for:950 */
/*<       endif >*/
	}
/*          WRITE(STDOUT,'('' TOTH:'',1P3E10.3)') TOTHL(ISEG), */
/*    A         TOTHM(ISEG), TOTHR(ISEG) */
/*          WRITE(STDOUT,'('' YF:'',1P3E10.3)') YFL(ISEG), YFM(ISEG), */
/*    A                   YFR(ISEG) */
/*         NOW COMPUTE THE FREE FLOW, FREE FLOW */
/*         MOMENTUM FLUX, AND FREE FLOW ENERGY FLUX FOR THIS SEGMENT */
/* SOURCE embank.for:961 */
/*<       dx=abs(xr(iseg)-xl(iseg)) >*/
	dx = (feq_gen_r_d_1 = static_cast<double>(xr[iseg]) - xl[iseg], dabs(feq_gen_r_d_1));
/*         INTEGRATE OVER THE WETTED LENGTH USING SIMPSON'S RULE */
/* SOURCE embank.for:965 */
/*<       qseg=dx*(ql(iseg)+4.*qm(iseg)+qr(iseg))/6. >*/
	qseg = static_cast<double>(static_cast<double>(dx) * (static_cast<double>(static_cast<double>(ql[iseg]) + static_cast<double>(qm[iseg]) * (float)4.) + qr[iseg])) / (float)6.;
/* SOURCE embank.for:966 */
/*<        >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = ql[iseg];
/* Computing 2nd power */
	feq_gen_r_d_2 = qm[iseg];
/* Computing 2nd power */
	feq_gen_r_d_3 = qr[iseg];
	mseg = static_cast<double>(static_cast<double>(dx) * (static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / yfl[iseg]) + static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2) * (float)4.) / yfm[
		iseg]) + static_cast<double>(static_cast<double>(feq_gen_r_d_3) * feq_gen_r_d_3) / yfr[iseg])) / (float)6.;
/* SOURCE embank.for:969 */
/*<        >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(ql[iseg]) / yfl[iseg];
/* Computing 2nd power */
	feq_gen_r_d_2 = static_cast<double>(qm[iseg]) / yfm[iseg];
/* Computing 2nd power */
	feq_gen_r_d_3 = static_cast<double>(qr[iseg]) / yfr[iseg];
	eseg = static_cast<double>(static_cast<double>(dx) * (static_cast<double>(static_cast<double>(static_cast<double>(ql[iseg]) * (static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / grvcom_1.grav2) + (static_cast<double>(static_cast<double>(yfl[iseg]) + *
		eu) - hl[iseg]))) + static_cast<double>(static_cast<double>(qm[iseg]) * (float)4.) * (static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2) / 
		grvcom_1.grav2) + (static_cast<double>(static_cast<double>(yfm[iseg]) + *eu) - hm[iseg]))) + static_cast<double>(qr[iseg]) * (
		static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_3) * feq_gen_r_d_3) / grvcom_1.grav2) + (static_cast<double>(static_cast<double>(yfr[iseg]) + *eu) - hr[iseg])))) 
		/ (float)6.;
/*          WRITE(STDOUT,*) ' ' */
/*          WRITE(STDOUT,*) ' DX =',DX */
/*          WRITE(STDOUT,'('' SEG FLOWS:'',3F12.4)') QL(ISEG), QM(ISEG), */
/*     A                                  QR(ISEG) */
/*          WRITE(STDOUT,'('' ISEG='',I5,'' QSEG='',F12.4)') ISEG, QSEG */
/*          WRITE(STDOUT,'('' MSEG='',F12.4,'' ESEG='',F12.4)') */
/*     A                             MSEG, ESEG */
/*          WRITE(STDOUT,*) ' AELL=',AELL(ISEG),' AELM=',AELM(ISEG), */
/*     A                     ' AELR=',AELR(ISEG) */
/*          WRITE(STDOUT,*) ' YFL=',YFL(ISEG),' YFM=',YFM(ISEG), */
/*     A                    ' YFR=',YFR(ISEG) */
/* SOURCE embank.for:991 */
/*<       qf=qf+qseg >*/
	qf += qseg;
/* SOURCE embank.for:992 */
/*<       mf=mf+mseg >*/
	mf += mseg;
/* SOURCE embank.for:993 */
/*<       ef=ef+eseg >*/
	ef += eseg;
/* SOURCE embank.for:994 */
/*<  4000 continue >*/
L4000:
	;
    }
/* SOURCE embank.for:997 */
/*<       qfree=qf >*/
    *qfree = qf;
/* SOURCE embank.for:998 */
/*<       mfree=rmffac*mf >*/
    *mfree = *rmffac * mf;
/* SOURCE embank.for:999 */
/*<       efree=ef >*/
    *efree = ef;
/*      WRITE(STDOUT,*) ' QFREE=',QFREE,' MFREE=',MFREE,' EFREE=',EFREE */
/* SOURCE embank.for:1001 */
/*<       return >*/
    return 0;
/* SOURCE embank.for:1002 */
/*<       end >*/
} /* frfemb_ */




/* SOURCE embank.for:1006 */
/*<        >*/
/* Subroutine */ int inprdp_(integer *stdin, integer *stdout, real *zdatum, 
	integer *eflag, integer *noff, real *mincrs, integer *minloc, real *
	feq_storage_off, real *feq_storage_crest, real *feq_storage_width, real *feq_storage_approc, char *feq_storage_surf, ftnlen 
	surf_len)
{
    /* Format strings */
    static char fmt_1[] = "(a80)";
    static char fmt_2[] = "(4f10.0,1x,a8)";
    static char fmt_50[] = "(\002 \002,a80)";
    static char fmt_52[] = "(\002 \002,f10.1,f10.2,2f10.1,1x,a8)";
    static char fmt_54[] = "(\002 *ERR:543* Crest below approach invalid.\
\002)";
    static char fmt_56[] = "(\002 *ERR:544* Weir width must be positive.\002)"
	    ;
    static char fmt_58[] = "(\002 *ERR:545* More than \002,i5,\002 offsets f\
or embankment.\002)";
    static char fmt_60[] = "(\002 *ERR:546* Invalid surface option: need PAV\
ED or GRAVEL.\002)";
    static char fmt_64[] = "(/,\002 Minimum crest elevation=\002,f10.2)";
    static char fmt_66[] = "(\002 Minimum crest location=\002,f10.1)";
    static char fmt_68[] = "(\002 *ERR:702* Offset on crest non-increasing a\
t offset=\002,f10.2)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(), 
	    s_wsfe(cilist *), e_wsfe(), s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;
    char head[80], line[80];
    real oldoff;
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__92 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__95 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__96 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__97 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__98 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__99 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__100 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__101 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__102 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__103 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__104 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__105 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     INPut RoaDway Profile for computing flow over an embankment, */
/* SOURCE embank.for:1014 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE embank.for:1017 */
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
/* SOURCE embank.for:1020 */
/*<       integereflag,minloc,noff,stdin,stdout >*/
/* SOURCE embank.for:1021 */
/*<        >*/
/* SOURCE embank.for:1023 */
/*<       charactersurf(pmxoff)*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     ZDATUM - datum for local elevation */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     NOFF   - Number of offsets */
/*     MINCRS - Minimum crest elevation */
/*     MINLOC - Offset of the minimum crest elevation */
/*     OFF    - Offsets for the crest of the embankment */
/*     CREST  - Crest profile for the high point on the embankment */
/*     WIDTH  - Breadth of the embankment crest */
/*     APPROC - Elevation of approach for the embankment */
/*     SURF   - Nature of the embankment surface */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE embank.for:1040 */
/*<       integeri >*/
/* SOURCE embank.for:1041 */
/*<       realoldoff >*/
/* SOURCE embank.for:1042 */
/*<       characterhead*80,line*80 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE embank.for:1045 */
/*<       externalinline >*/
/*     + + + INPUT FORMATS + + + */
/* SOURCE embank.for:1048 */
/*<     1 format(a80) >*/
/* SOURCE embank.for:1049 */
/*<     2 format(4f10.0,1x,a8) >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE embank.for:1052 */
/*<    50 format(' ',a80) >*/
/* SOURCE embank.for:1053 */
/*<    52 format(' ',f10.1,f10.2,2f10.1,1x,a8) >*/
/* SOURCE embank.for:1054 */
/*<    54 format(' *ERR:543* Crest below approach invalid.') >*/
/* SOURCE embank.for:1055 */
/*<    56 format(' *ERR:544* Weir width must be positive.') >*/
/* SOURCE embank.for:1056 */
/*<    58 format(' *ERR:545* More than ',i5,' offsets for embankment.') >*/
/* SOURCE embank.for:1057 */
/*<    60 format(' *ERR:546* Invalid surface option: need PAVED or GRAVEL.') >*/
/* SOURCE embank.for:1058 */
/*<    64 format(/,' Minimum crest elevation=',f10.2) >*/
/* SOURCE embank.for:1059 */
/*<    66 format(' Minimum crest location=',f10.1) >*/
/* SOURCE embank.for:1060 */
/*<    68  >*/
/* *********************************************************************** */
/*     INPUT THE WEIR DEFINITION */
/* SOURCE embank.for:1065 */
/*<       callinline(stdin,stdout,line) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<char> surf(feq_storage_surf, 8);

    feq::IndexedPointer<real> approc(feq_storage_approc, 1);

    feq::IndexedPointer<real> width(feq_storage_width, 1);

    feq::IndexedPointer<real> crest(feq_storage_crest, 1);

    feq::IndexedPointer<real> off(feq_storage_off, 1);

    /* Function Body */
/* L1: */
/* L2: */
/* L50: */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
/* L60: */
/* L64: */
/* L66: */
/* L68: */
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE embank.for:1068 */
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE embank.for:1069 */
/*<       write(stdout,50)head >*/
    feq_gen_io_d__92.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__92);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_wsfe();
/* SOURCE embank.for:1071 */
/*<       i=1 >*/
    feq_gen_i_d_ = 1;
/* SOURCE embank.for:1072 */
/*<       oldoff=-1.e30 >*/
    oldoff = (float)-1e30;
/* SOURCE embank.for:1073 */
/*<       mincrs=1.e30 >*/
    *mincrs = (float)1e30;
/* SOURCE embank.for:1074 */
/*<   200 continue >*/
L200:
/* SOURCE embank.for:1076 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE embank.for:1079 */
/*<       read(line,2,err=991)off(i),crest(i),width(i),approc(i),surf(i) >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&off[feq_gen_i_d_], (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&crest[feq_gen_i_d_], (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&width[feq_gen_i_d_], (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&approc[feq_gen_i_d_], (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, surf + (feq_gen_i_d_ << 3), (ftnlen)8);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE embank.for:1082 */
/*<       if(off(i).le.oldoff)then >*/
    if (off[feq_gen_i_d_] <= oldoff) {
/* SOURCE embank.for:1083 */
/*<       write(stdout,68)off(i) >*/
	feq_gen_io_d__95.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__95);
	do_fio(&feq_gen_c_d_1, (char *)&off[feq_gen_i_d_], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE embank.for:1084 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE embank.for:1085 */
/*<       endif >*/
    }
/* SOURCE embank.for:1086 */
/*<       oldoff=off(i) >*/
    oldoff = off[feq_gen_i_d_];
/* SOURCE embank.for:1087 */
/*<       if(approc(i).ne.0.0)then >*/
    if (approc[feq_gen_i_d_] != (float)0.) {
/* SOURCE embank.for:1088 */
/*<       approc(i)=approc(i)-zdatum >*/
	approc[feq_gen_i_d_] -= static_cast<double>(*zdatum);
/* SOURCE embank.for:1089 */
/*<       endif >*/
    }
/*       PROPAGATE VALUES FROM ABOVE TO SAVE TYPING ON INPUT */
/* SOURCE embank.for:1091 */
/*<       if(width(i).eq.0.0.and.i.gt.1)width(i)=width(i-1) >*/
    if (width[feq_gen_i_d_] == (float)0. && feq_gen_i_d_ > 1) {
	width[feq_gen_i_d_] = width[feq_gen_i_d_ - 1];
    }
/* SOURCE embank.for:1092 */
/*<       if(approc(i).eq.0.0.and.i.gt.1)approc(i)=approc(i-1) >*/
    if (approc[feq_gen_i_d_] == (float)0. && feq_gen_i_d_ > 1) {
	approc[feq_gen_i_d_] = approc[feq_gen_i_d_ - 1];
    }
/* SOURCE embank.for:1093 */
/*<       if(surf(i).eq.'       '.and.i.gt.1)surf(i)=surf(i-1) >*/
    if (s_cmp(surf + (feq_gen_i_d_ << 3), const_cast<char*>("       "), (ftnlen)8, (ftnlen)7) == 0 && feq_gen_i_d_ 
	    > 1) {
	s_copy(surf + (feq_gen_i_d_ << 3), surf + (feq_gen_i_d_ - 1 << 3), (ftnlen)8, (ftnlen)8)
		;
    }
/* SOURCE embank.for:1094 */
/*<       write(stdout,52)off(i),crest(i),width(i),approc(i)+zdatum,surf(i) >*/
    feq_gen_io_d__96.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__96);
    do_fio(&feq_gen_c_d_1, (char *)&off[feq_gen_i_d_], (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&crest[feq_gen_i_d_], (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&width[feq_gen_i_d_], (ftnlen)sizeof(real));
    feq_gen_r_d_1 = static_cast<double>(approc[feq_gen_i_d_]) + *zdatum;
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, surf + (feq_gen_i_d_ << 3), (ftnlen)8);
    e_wsfe();
/*       Adjust for the elevation datum */
/* SOURCE embank.for:1098 */
/*<       crest(i)=crest(i)-zdatum >*/
    crest[feq_gen_i_d_] -= static_cast<double>(*zdatum);
/* SOURCE embank.for:1100 */
/*<       if(crest(i).le.approc(i))then >*/
    if (crest[feq_gen_i_d_] <= approc[feq_gen_i_d_]) {
/* SOURCE embank.for:1101 */
/*<       write(stdout,54) >*/
	feq_gen_io_d__97.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__97);
	e_wsfe();
/* SOURCE embank.for:1102 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE embank.for:1103 */
/*<       endif >*/
    }
/* SOURCE embank.for:1104 */
/*<       if(width(i).le.0.0)then >*/
    if (width[feq_gen_i_d_] <= (float)0.) {
/* SOURCE embank.for:1105 */
/*<       write(stdout,56) >*/
	feq_gen_io_d__98.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__98);
	e_wsfe();
/* SOURCE embank.for:1106 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE embank.for:1107 */
/*<       endif >*/
    }
/* SOURCE embank.for:1108 */
/*<       if(crest(i).lt.mincrs)then >*/
    if (crest[feq_gen_i_d_] < *mincrs) {
/* SOURCE embank.for:1109 */
/*<       mincrs=crest(i) >*/
	*mincrs = crest[feq_gen_i_d_];
/* SOURCE embank.for:1110 */
/*<       minloc=i >*/
	*minloc = feq_gen_i_d_;
/* SOURCE embank.for:1111 */
/*<       endif >*/
    }
/* SOURCE embank.for:1113 */
/*<       if(surf(i).eq.'END')then >*/
    if (s_cmp(surf + (feq_gen_i_d_ << 3), const_cast<char*>("END"), (ftnlen)8, (ftnlen)3) == 0) {
/* SOURCE embank.for:1114 */
/*<       noff=i >*/
	*noff = feq_gen_i_d_;
/* SOURCE embank.for:1115 */
/*<       goto210 >*/
	goto L210;
/* SOURCE embank.for:1116 */
/*<       elseif(surf(i).eq.'PAVED'.or.surf(i).eq.'GRAVEL')then >*/
    } else if (s_cmp(surf + (feq_gen_i_d_ << 3), const_cast<char*>("PAVED"), (ftnlen)8, (ftnlen)5) == 0 ||
	     s_cmp(surf + (feq_gen_i_d_ << 3), const_cast<char*>("GRAVEL"), (ftnlen)8, (ftnlen)6) == 0) {
/* SOURCE embank.for:1117 */
/*<       i=i+1 >*/
	++feq_gen_i_d_;
/* SOURCE embank.for:1119 */
/*<       if(i.gt.pmxoff)then >*/
	if (feq_gen_i_d_ > 1000) {
/* SOURCE embank.for:1120 */
/*<       write(stdout,58)pmxoff >*/
	    feq_gen_io_d__99.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__99);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_1000, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE embank.for:1121 */
/*<       i=pmxoff >*/
	    feq_gen_i_d_ = 1000;
/* SOURCE embank.for:1122 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE embank.for:1123 */
/*<       endif >*/
	}
/* SOURCE embank.for:1124 */
/*<       goto200 >*/
	goto L200;
/* SOURCE embank.for:1125 */
/*<       else >*/
    } else {
/* SOURCE embank.for:1126 */
/*<       write(stdout,60) >*/
	feq_gen_io_d__100.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__100);
	e_wsfe();
/* SOURCE embank.for:1127 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE embank.for:1128 */
/*<       surf(i)='GRAVEL' >*/
	s_copy(surf + (feq_gen_i_d_ << 3), const_cast<char*>("GRAVEL"), (ftnlen)8, (ftnlen)6);
/* SOURCE embank.for:1129 */
/*<       i=i+1 >*/
	++feq_gen_i_d_;
/* SOURCE embank.for:1130 */
/*<       if(i.gt.pmxoff)then >*/
	if (feq_gen_i_d_ > 1000) {
/* SOURCE embank.for:1131 */
/*<       write(stdout,58)pmxoff >*/
	    feq_gen_io_d__101.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__101);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_1000, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE embank.for:1132 */
/*<       i=pmxoff >*/
	    feq_gen_i_d_ = 1000;
/* SOURCE embank.for:1133 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE embank.for:1134 */
/*<       endif >*/
	}
/* SOURCE embank.for:1135 */
/*<       goto200 >*/
	goto L200;
/* SOURCE embank.for:1136 */
/*<       endif >*/
    }
/* SOURCE embank.for:1138 */
/*<   210 continue >*/
L210:
/* SOURCE embank.for:1140 */
/*<       write(stdout,64)mincrs+zdatum >*/
    feq_gen_io_d__102.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__102);
    feq_gen_r_d_1 = static_cast<double>(*mincrs) + *zdatum;
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE embank.for:1141 */
/*<       write(stdout,66)off(minloc) >*/
    feq_gen_io_d__103.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__103);
    do_fio(&feq_gen_c_d_1, (char *)&off[*minloc], (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE embank.for:1143 */
/*<       return >*/
    return 0;
/* SOURCE embank.for:1144 */
/*<   991 continue >*/
L991:
/* SOURCE embank.for:1145 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__104.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__104);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE embank.for:1146 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__105.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__105);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE embank.for:1147 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE embank.for:1148 */
/*<       end >*/
    return 0;
} /* inprdp_ */




/* SOURCE embank.for:1152 */
/*<        >*/
/* Subroutine */ int etabin_(integer *stdin, integer *stdout, integer *mftnum,
	 integer *feq_storage_ftpnt, integer *eflag, integer *plcwtb, integer *glcwtb, 
	integer *phcwtb, integer *ghcwtb, integer *psubtb, integer *gsubtb)
{
    /* Format strings */
    static char fmt_52[] = "(\0020*ERR:593* Weir Coef. Table Id must be give\
n.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(), 
	    s_wsfe(cilist *), e_wsfe(), s_cmp(char *, char *, ftnlen, ftnlen),
	     s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    integer feq_gen_i_d_, tab[6];
    char feq_gen_name_d_[7], line[80], tabid[16*6];
    extern /* Subroutine */ int chktab_(integer *, integer *, integer *, 
	    integer *, integer *, integer *), inline_(integer *, integer *, 
	    char *, ftnlen);
    extern doublereal fsbrat_(integer *);
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__111 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__112 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__113 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Input standard table numbers for weir coef. variation */
/*     for flow over embankment shaped weirs. */
/* SOURCE embank.for:1161 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE embank.for:1164 */
/*<        >*/
/* SOURCE embank.for:1166 */
/*<       integerftpnt(*) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     MFTNUM - Maximum allowed table number */
/*     FTPNT  - function table pointer giving the table address for each */
/*              table number.  If the address is zero the table does not */
/*              exist. */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     PLCWTB - Paved low-head weir coefficient table */
/*     GLCWTB - Gravel surface low head weir coefficient table */
/*     PHCWTB - Paved high-head weir coefficient table */
/*     GHCWTB - Gravel surface high head weir coefficient table */
/*     PSUBTB - Paved submergence table */
/*     GSUBTB - Gravel surface submergence table */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE embank.for:1184 */
/*     COMMON FOR SUBMERGENCE RATIOS FOR WEIR COMPUTATIONS */
/* SOURCE subcom.cmn:3 */
/*<       common/subcom/prat,grat >*/
/* SOURCE subcom.cmn:5 */
/*<       realprat,grat >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE embank.for:1187 */
/*<       integeri >*/
/* SOURCE embank.for:1188 */
/*<       integertab(6) >*/
/* SOURCE embank.for:1189 */
/*<       characterline*80,name*7,tabid(6)*16 >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE embank.for:1192 */
/*<       realfsbrat >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE embank.for:1195 */
/*<        >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE embank.for:1199 */
/*<    52 format('0*ERR:593* Weir Coef. Table Id must be given.') >*/
/* *********************************************************************** */
/* SOURCE embank.for:1201 */
/*<       do100i=1,6 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> ftpnt(feq_storage_ftpnt, 1);

    /* Function Body */
/* L52: */
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 6; ++feq_gen_i_d_) {
/* SOURCE embank.for:1202 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE embank.for:1205 */
/*<       read(line,'(A7,A)',err=991)name,tabid(i) >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(A7,A)");
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)7);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, tabid + (feq_gen_i_d_ - 1 << 4), (ftnlen)16);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE embank.for:1206 */
/*<       write(stdout,'(1X,A7,A)')name,tabid(i) >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(1X,A7,A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)7);
	do_fio(&feq_gen_c_d_1, tabid + (feq_gen_i_d_ - 1 << 4), (ftnlen)16);
	e_wsfe();
/* SOURCE embank.for:1207 */
/*<       callstrip_l_blanks(tabid(i)) >*/
	feq_gen_strip_l_blanks_d_(tabid + (feq_gen_i_d_ - 1 << 4), (ftnlen)16);
/* SOURCE embank.for:1209 */
/*<       if(tabid(i).ne.' ')then >*/
	if (s_cmp(tabid + (feq_gen_i_d_ - 1 << 4), const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/* SOURCE embank.for:1210 */
/*<       callget_internal_tab_number(stdout,tabid(i),eflag,tab(i)) >*/
	    feq_gen_get_internal_tab_number_d_(stdout, tabid + (feq_gen_i_d_ - 1 << 4), eflag, &
		    tab[feq_gen_i_d_ - 1], (ftnlen)16);
/* SOURCE embank.for:1214 */
/*<       else >*/
	} else {
/* SOURCE embank.for:1215 */
/*<       tab(i)=0 >*/
	    tab[feq_gen_i_d_ - 1] = 0;
/* SOURCE embank.for:1216 */
/*<       endif >*/
	}
/* SOURCE embank.for:1217 */
/*<       callchktab(2,stdout,ftpnt,mftnum,tab(i),eflag) >*/
	chktab_(&feq_gen_c_d_2, stdout, &ftpnt[1], mftnum, &tab[feq_gen_i_d_ - 1], eflag);
/* SOURCE embank.for:1221 */
/*<       if(i.le.4.and.tab(i).eq.0)then >*/
	if (feq_gen_i_d_ <= 4 && tab[feq_gen_i_d_ - 1] == 0) {
/* SOURCE embank.for:1222 */
/*<       write(stdout,52) >*/
	    feq_gen_io_d__111.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__111);
	    e_wsfe();
/* SOURCE embank.for:1223 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE embank.for:1224 */
/*<       endif >*/
	}
/* SOURCE embank.for:1225 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE embank.for:1226 */
/*<       if(eflag.gt.0)return >*/
    if (*eflag > 0) {
	return 0;
    }
/*     TRANSFER TO THE INDIVIDUAL VARIABLES */
/* SOURCE embank.for:1230 */
/*<       plcwtb=tab(1) >*/
    *plcwtb = tab[0];
/* SOURCE embank.for:1231 */
/*<       glcwtb=tab(2) >*/
    *glcwtb = tab[1];
/* SOURCE embank.for:1232 */
/*<       phcwtb=tab(3) >*/
    *phcwtb = tab[2];
/* SOURCE embank.for:1233 */
/*<       ghcwtb=tab(4) >*/
    *ghcwtb = tab[3];
/* SOURCE embank.for:1234 */
/*<       psubtb=tab(5) >*/
    *psubtb = tab[4];
/* SOURCE embank.for:1235 */
/*<       gsubtb=tab(6) >*/
    *gsubtb = tab[5];
/*     ESTABLISH THE TAILWATER RATIO AT WHICH SUBMERGENCE BEGINS. */
/* SOURCE embank.for:1238 */
/*<       if(psubtb.gt.0)then >*/
    if (*psubtb > 0) {
/* SOURCE embank.for:1239 */
/*<       prat=fsbrat(psubtb) >*/
	subcom_1.prat = fsbrat_(psubtb);
/* SOURCE embank.for:1240 */
/*<       endif >*/
    }
/* SOURCE embank.for:1241 */
/*<       if(gsubtb.gt.0)then >*/
    if (*gsubtb > 0) {
/* SOURCE embank.for:1242 */
/*<       grat=fsbrat(gsubtb) >*/
	subcom_1.grat = fsbrat_(gsubtb);
/* SOURCE embank.for:1243 */
/*<       endif >*/
    }
/* SOURCE embank.for:1246 */
/*<       return >*/
    return 0;
/* SOURCE embank.for:1247 */
/*<   991 continue >*/
L991:
/* SOURCE embank.for:1248 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__112.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__112);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE embank.for:1249 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__113.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__113);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE embank.for:1250 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE embank.for:1251 */
/*<       end >*/
    return 0;
} /* etabin_ */




/* SOURCE embank.for:1255 */
/*<       subroutineembank(stdin,stdout,stdtab,minq,eflag,ftp) >*/
/* Subroutine */ int embank_(integer *stdin, integer *stdout, integer *stdtab,
	 real *minq, integer *eflag, integer *ftp)
{
    /* Format strings */
    static char fmt_8[] = "(a6,1x,f10.0)";
    static char fmt_16[] = "(a5,1x,f10.0)";
    static char fmt_26[] = "(a5,1x,i5)";
    static char fmt_22[] = "(\002TABID=\002,a)";
    static char fmt_28[] = "(f10.5,f10.3)";
    static char fmt_29[] = "(\002TYPE=   -2\002)";
    static char fmt_30[] = "(/,\002 Datum for heads (minimum crest elevation\
)=\002,f10.3,\002 after scaling and possible crest shift.\002)";
    static char fmt_50[] = "(\002 TabId= \002,a,\002 TYPE=\002,i5,\002 H/L C\
rit ratio=\002,f7.2,\002 H/L max ratio=\002,f7.2,/,4x,\002Hor. scale factor\
=\002,f10.3,\002 Vert. scale factor=\002,f10.3,\002 Crest shift=\002,f9.3,/,\
4x,\002 Minimum flow target=\002,f10.3)";
    static char fmt_53[] = "(1x,\002 PartialFD      Drop  Dns Head      Flow\
  RelError\002)";
    static char fmt_55[] = "(1x,f10.6,f10.4,f10.4,2x,a8,f10.3)";
    static char fmt_60[] = "(\002   Free flow interpolation between head=\
\002,f8.3,\002 and \002,f8.3,/,\002   has estimated maximum relative\002,\
\002 error of\002,f6.3)";
    static char fmt_61[] = "(/,\002 Maximum estimated relative error=\002,f8\
.3,\002 is in free\002,\002 flow\002,/,5x,\002 between heads=\002,f8.3,\002 \
and \002,f8.3)";
    static char fmt_62[] = "(/,\002 Estimated root-mean-square error=\002,f8\
.3)";
    static char fmt_63[] = "(/,\002 Maximum estimated relative error=\002,f8\
.3,\002 is in \002,\002submerged flow\002,/,5x,\002at ups. head=\002,f8.3\
,\002 between PFD=\002,f8.4,\002 and \002,f8.4)";
    static char fmt_64[] = "(/,\002 \002,f5.2,\002 of checked points had err\
or > LIPREC and\002,f5.2,\002 had error > 2*LIPREC.\002)";
    static char fmt_66[] = "(\002 \002,a5,\002=\002,f10.2)";
    static char fmt_71[] = "(\0020 Table type 5 replaced by type 13.\002)";
    static char fmt_79[] = "(/,\002 Requested linear interpolation precisi\
on=\002,f5.3)";
    static char fmt_80[] = "(/,\002 Minimum partial free drop=\002,f8.3)";
    static char fmt_81[] = "(/,\002 Upstream Head=\002,f9.4,\002  Free Flow\
=\002,f10.3)";
    static char fmt_90[] = "(\002  Processing EMBANKQ TabId= \002,a)";
    static char fmt_92[] = "(\002; Flow defining minimum head=\002,f10.3)";
    static char fmt_94[] = "(/,1x,a5,\002=\002,i5)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;
    char feq_gen_ch_d_1[16];
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(), s_wsle(cilist *), do_lio(integer *, 
	    integer *, char *, ftnlen), e_wsle();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), s_rsfi(icilist *), e_rsfi(), 
	    s_cmp(char *, char *, ftnlen, ftnlen);
    double pow_dd(doublereal *, doublereal *), sqrt(doublereal);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    doublereal northing;
    integer feq_gen_i_d_, j, k, n;
    real q[53001]	/* was [151][351] */;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real feq_gen_rms_error_d_;
    char cq[8];
    real eu;
    extern /* Subroutine */ int feq_gen_tab_in_use_d_(char *, integer *, ftnlen);
    real feq_gen_local_minq_d_;
    integer feq_gen_n_gt_twice_d_, nhu;
    real hup;
    extern /* Subroutine */ int feq_gen_var_decimal_d_(real *, char *, ftnlen), 
	    feq_gen_embankq_opt_d_(integer *, real *, real *, integer *, real *, 
	    integer *, real *, integer *, real *, integer *);
    integer feq_gen_location_hu_d_;
    char head[80];
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    real fmid;
    integer feq_gen_n_gt_d_;
    char line[120];
    real xmid, drop, rerr;
    char zone[8];
    integer feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    integer feq_gen_location_pfd_d_;
    char char5[5], char6[6];
    real feq_gen_global_error_d_;
    char label[50];
    integer hflag;
    char tabid[16];
    real freed, efree;
    integer table, nfrac, sflag;
    real mfree, qfree;
    integer ftpup;
    real fdrop[151], huvec[151], power;
    char hgrid[8], basis[8];
    integer nfrac2;
    real hscale;
    extern /* Subroutine */ int etabin_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *), frfemb_(real *, real *, integer *, integer 
	    *, integer *, integer *, integer *, real *, real *, real *, real *
	    , char *, real *, real *, real *, integer *, integer *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, ftnlen), sbfemb_(integer *, real *, real *, real *
	    , integer *, integer *, integer *, integer *, integer *, integer *
	    , integer *, integer *, char *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, ftnlen);
    real pfdvec[351], liprec, qsbvec[351], zdatum, minpfd, vscale, cshift, 
	    zrhufd;
    doublereal siesqr;
    char vdatum[8];
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen),
	     inprdp_(integer *, integer *, real *, integer *, integer *, real 
	    *, integer *, real *, real *, real *, real *, char *, ftnlen), 
	    twdout_(integer *, integer *, integer *, char *, integer *, 
	    integer *, real *, real *, real *, real *, real *, integer *, 
	    char *, real *, char *, char *, char *, char *, char *, 
	    doublereal *, doublereal *, integer *, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen), feq_gen_get_embk_items_d_(integer *, 
	    integer *, integer *), feq_gen_set_embk_items_d_(integer *, integer *, 
	    integer *, real *, real *, real *, real *, real *, real *), 
	    feq_gen_get_lctn_items_d_(integer *, integer *, integer *), 
	    feq_gen_set_lctn_items_d_(char *, char *, char *, char *, char *, 
	    doublereal *, doublereal *, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen);
    real feq_gen_qd_span_d_;
    doublereal easting;
    integer verbose;
    extern /* Subroutine */ int twodfit_(integer *, integer *, integer *, 
	    integer *, real *, real *, real *, real *, real *, integer *, 
	    char *, real *, integer *, integer *, integer *, integer *, 
	    ftnlen);
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__123 = { 0, 0, 0, fmt_71, 0 };
    static cilist feq_gen_io_d__124 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__125 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__127 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__128 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__129 = { 0, 6, 0, fmt_90, 0 };
    static cilist feq_gen_io_d__142 = { 0, 0, 0, fmt_30, 0 };
    static cilist feq_gen_io_d__149 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__150 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__152 = { 0, 0, 0, fmt_79, 0 };
    static cilist feq_gen_io_d__154 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__155 = { 0, 0, 0, fmt_79, 0 };
    static cilist feq_gen_io_d__156 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__178 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__179 = { 0, 0, 0, fmt_81, 0 };
    static cilist feq_gen_io_d__180 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__185 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__188 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__189 = { 0, 0, 0, fmt_61, 0 };
    static cilist feq_gen_io_d__190 = { 0, 0, 0, fmt_63, 0 };
    static cilist feq_gen_io_d__192 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__194 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__198 = { 0, 0, 0, fmt_22, 0 };
    static cilist feq_gen_io_d__199 = { 0, 0, 0, fmt_29, 0 };
    static cilist feq_gen_io_d__200 = { 0, 0, 0, fmt_28, 0 };
    static cilist feq_gen_io_d__201 = { 0, 0, 0, fmt_28, 0 };
    static cilist feq_gen_io_d__202 = { 0, 0, 0, fmt_28, 0 };
    static cilist feq_gen_io_d__203 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__204 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Compute flow over embankment shaped weirs using the USGS */
/*     procedure.  Tables required by this routine must have */
/*     been input using FTABIN before requesting the computation */
/*     of flow using this routine. */
/* SOURCE embank.for:1265 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE embank.for:1267 */
/*<       integereflag,ftp,stdin,stdout,stdtab >*/
/* SOURCE embank.for:1268 */
/*<       realminq >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     MINQ   - minimum target Q to define the minimum for auto-arguments */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE embank.for:1278 */
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
/* INCLUDE embank.for:1279 */
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
/* INCLUDE embank.for:1280 */
/*     COMMOM BLOCK FOR THE DESCRIPTION OF THE FLOW OVER AN EMBANKMENT */
/* SOURCE embcom.cmn:3 */
/*<       character*8surf(pmxoff) >*/
/* SOURCE embcom.cmn:5 */
/*<       integernoff,minloc,plcwtb,glcwtb,phcwtb,ghcwtb,psubtb,gsubtb >*/
/* SOURCE embcom.cmn:8 */
/*<       realmincrs,rmffac >*/
/* SOURCE embcom.cmn:10 */
/*<        >*/
/* SOURCE embcom.cmn:20 */
/*<       common/embcmc/surf >*/
/* SOURCE embcom.cmn:22 */
/*<        >*/
/* INCLUDE embank.for:1281 */
/*     Common block for key values describing the nature of weir */
/*     flow. */
/* SOURCE embwrq.cmn:4 */
/*<       integerhlflag,hpflag >*/
/* SOURCE embwrq.cmn:6 */
/*<       realhlcrit,hlmax >*/
/* SOURCE embwrq.cmn:8 */
/*<       common/embq/hlflag,hpflag,hlcrit,hlmax >*/
/* SOURCE embwrq.cmn:10 */
/*<       save/embq/ >*/
/*     HLCRIT  Ratio of piezometric head to crest breadth at boundary */
/*             between low head and high head flow in the USGS */
/*             embankment-shaped weir methodology. */
/*     HLMAX   Maximum value of piezometric head to crest breadth ratio */
/*             above which a warning message is issued. */
/*     HLFLAG  Warning message suppression flag for warnings about the */
/*             piezometric head to crest breadth ratio becoming greater */
/*             than HLMAX */
/*     HPFLAG  Warning message suppression flag for invalid weir flow */
/* INCLUDE embank.for:1282 */
/*     common for passing info for table upgrading-going from one form */
/*     to one that is smoother in its representation */
/* SOURCE tabupgrade.cmn:4 */
/*<       characterty13_to_ty43*4,twod_cubic_out*4,upgrade_xsec_tab*4 >*/
/* SOURCE tabupgrade.cmn:6 */
/*<       common/upgrdc/ty13_to_ty43,twod_cubic_out,upgrade_xsec_tab >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE embank.for:1285 */
/*<        >*/
/* SOURCE embank.for:1288 */
/*<        >*/
/* SOURCE embank.for:1294 */
/*<       real*8siesqr,easting,northing >*/
/* SOURCE embank.for:1296 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE embank.for:1301 */
/*<       intrinsicfloat >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE embank.for:1304 */
/*<       integerlenstr >*/
/* SOURCE embank.for:1305 */
/*<       characterget_tabid*16 >*/
/* SOURCE embank.for:1306 */
/*<        >*/
/*     + + + INPUT FORMATS + + + */
/* SOURCE embank.for:1311 */
/*<     8 format(a6,1x,f10.0) >*/
/* SOURCE embank.for:1312 */
/*<    16 format(a5,1x,f10.0) >*/
/* SOURCE embank.for:1313 */
/*<    26 format(a5,1x,i5) >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE embank.for:1316 */
/*<    22 format('TABID=',a) >*/
/* SOURCE embank.for:1317 */
/*<    28 format(f10.5,f10.3) >*/
/* SOURCE embank.for:1318 */
/*<    29 format('TYPE=   -2') >*/
/* SOURCE embank.for:1319 */
/*<    30  >*/
/* SOURCE embank.for:1321 */
/*<    50  >*/
/* SOURCE embank.for:1325 */
/*<    53 format(1x,' PartialFD      Drop  Dns Head      Flow  RelError') >*/
/* SOURCE embank.for:1326 */
/*<    55 format(1x,f10.6,f10.4,f10.4,2x,a8,f10.3) >*/
/* SOURCE embank.for:1327 */
/*<    60  >*/
/* SOURCE embank.for:1330 */
/*<    61  >*/
/* SOURCE embank.for:1332 */
/*<    62 format(/,' Estimated root-mean-square error=',f8.3) >*/
/* SOURCE embank.for:1333 */
/*<    63  >*/
/* SOURCE embank.for:1336 */
/*<    64  >*/
/* SOURCE embank.for:1338 */
/*<    66 format(' ',a5,'=',f10.2) >*/
/* SOURCE embank.for:1339 */
/*<    71 format('0 Table type 5 replaced by type 13.') >*/
/* SOURCE embank.for:1340 */
/*<    79 format(/,' Requested linear interpolation precision=',f5.3) >*/
/* SOURCE embank.for:1341 */
/*<    80 format(/,' Minimum partial free drop=',f8.3) >*/
/* SOURCE embank.for:1342 */
/*<    81 format(/,' Upstream Head=',f9.4,'  Free Flow=',f10.3) >*/
/* SOURCE embank.for:1343 */
/*<    90 format('  Processing EMBANKQ TabId= ',a) >*/
/* SOURCE embank.for:1344 */
/*<    92 format('; Flow defining minimum head=',f10.3) >*/
/* SOURCE embank.for:1345 */
/*<    94 format(/,1x,a5,'=',i5) >*/
/* *********************************************************************** */
/* SOURCE embank.for:1347 */
/*<       callget_embk_items(stdin,stdout,eflag) >*/
/* L8: */
/* L16: */
/* L26: */
/* L22: */
/* L28: */
/* L29: */
/* L30: */
/* L50: */
/* L53: */
/* L55: */
/* L60: */
/* L61: */
/* L62: */
/* L63: */
/* L64: */
/* L66: */
/* L71: */
/* L79: */
/* L80: */
/* L81: */
/* L90: */
/* L92: */
/* L94: */
    feq_gen_get_embk_items_d_(stdin, stdout, eflag);
/* SOURCE embank.for:1349 */
/*<        >*/
    feq_gen_set_embk_items_d_(eflag, &table, &feq_gen_type_d_, &embq_1.hlcrit, &embq_1.hlmax, &
	    hscale, &vscale, &cshift, &feq_gen_local_minq_d_);
/* SOURCE embank.for:1354 */
/*<       if(local_minq.eq.0.0)then >*/
    if (feq_gen_local_minq_d_ == (float)0.) {
/*       Use the global default value because a minimum Q of zero is */
/*       invalid. */
/* SOURCE embank.for:1357 */
/*<       local_minq=minq >*/
	feq_gen_local_minq_d_ = *minq;
/* SOURCE embank.for:1358 */
/*<       endif >*/
    }
/* SOURCE embank.for:1359 */
/*<       if(type.eq.5)then >*/
    if (feq_gen_type_d_ == 5) {
/* SOURCE embank.for:1360 */
/*<       write(stdout,71) >*/
	feq_gen_io_d__123.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__123);
	e_wsfe();
/* SOURCE embank.for:1361 */
/*<       type=13 >*/
	feq_gen_type_d_ = 13;
/* SOURCE embank.for:1362 */
/*<       endif >*/
    }
/* SOURCE embank.for:1363 */
/*<       if(hlcrit.lt.0.0)then >*/
    if (embq_1.hlcrit < (float)0.) {
/* SOURCE embank.for:1364 */
/*<       write(stdout,*)' *ERR:611* H/L CRIT RATIO < 0.0 IN EMBANK.' >*/
	feq_gen_io_d__124.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__124);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:611* H/L CRIT RATIO < 0.0 IN EMBANK."), (
		ftnlen)42);
	e_wsle();
/* SOURCE embank.for:1365 */
/*<       hlcrit=0.15 >*/
	embq_1.hlcrit = (float).15;
/* SOURCE embank.for:1366 */
/*<       endif >*/
    }
/* SOURCE embank.for:1367 */
/*<       if(hlmax.lt.0.0)then >*/
    if (embq_1.hlmax < (float)0.) {
/* SOURCE embank.for:1368 */
/*<       write(stdout,*)' *ERR:612* H/L MAX RATIO < 0.0 IN EMBANK.' >*/
	feq_gen_io_d__125.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__125);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:612* H/L MAX RATIO < 0.0 IN EMBANK."), (
		ftnlen)41);
	e_wsle();
/* SOURCE embank.for:1369 */
/*<       hlmax=0.32 >*/
	embq_1.hlmax = (float).32;
/* SOURCE embank.for:1370 */
/*<       endif >*/
    }
/* SOURCE embank.for:1371 */
/*<       tabid=get_tabid(table) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &table);
    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE embank.for:1372 */
/*<        >*/
    feq_gen_io_d__127.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__127);
    do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&embq_1.hlcrit, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&embq_1.hlmax, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&hscale, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&vscale, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&cshift, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_local_minq_d_, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE embank.for:1375 */
/*<       write(stdtab,92)local_minq >*/
    feq_gen_io_d__128.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__128);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_local_minq_d_, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE embank.for:1377 */
/*<       write(*,90)tabid >*/
    s_wsfe(&feq_gen_io_d__129);
    do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
    e_wsfe();
/*     MAKE SURE TABLE NUMBER IS NOT ALREADY USED IN THIS INPUT */
/* SOURCE embank.for:1381 */
/*<       if(ftpnt(table).ne.0)calltab_in_use(tabid,eflag) >*/
    if (ftablea_1.ftpnt[table - 1] != 0) {
	feq_gen_tab_in_use_d_(tabid, eflag, (ftnlen)16);
    }
/*     Get location items that may be present. If they are not present */
/*     they will be set to default values.  The default requests FEQUTL */
/*     to omit the items. */
/* SOURCE embank.for:1387 */
/*<       callget_lctn_items(stdin,stdout,eflag) >*/
    feq_gen_get_lctn_items_d_(stdin, stdout, eflag);
/* SOURCE embank.for:1389 */
/*<        >*/
    feq_gen_set_lctn_items_d_(zone, hgrid, vdatum, unitsys, basis, &easting, &northing,
	     (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/*     INPUT THE STANDARD TABLE NUMBERS */
/* SOURCE embank.for:1396 */
/*<        >*/
    etabin_(stdin, stdout, &feq_gen_c_d_10002, ftablea_1.ftpnt, eflag, &
	    embcom_1.plcwtb, &embcom_1.glcwtb, &embcom_1.phcwtb, &
	    embcom_1.ghcwtb, &embcom_1.psubtb, &embcom_1.gsubtb);
/* SOURCE embank.for:1400 */
/*<       if(psubtb.eq.0.or.gsubtb.eq.0)then >*/
    if (embcom_1.psubtb == 0 || embcom_1.gsubtb == 0) {
/* SOURCE embank.for:1401 */
/*<       sflag=0 >*/
	sflag = 0;
/* SOURCE embank.for:1402 */
/*<       else >*/
    } else {
/* SOURCE embank.for:1403 */
/*<       sflag=1 >*/
	sflag = 1;
/* SOURCE embank.for:1404 */
/*<       endif >*/
    }
/*     INPUT THE LABEL FOR THE TABLE */
/* SOURCE embank.for:1408 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)120);
/* SOURCE embank.for:1411 */
/*<       read(line,'(6X,A50)',err=991)label >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 120;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(6X,A50)");
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
/* SOURCE embank.for:1412 */
/*<       write(stdout,'('' LABEL='',A50)')label >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(' LABEL=',A50)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, label, (ftnlen)50);
    e_wsfe();
/*     INPUT THE WEIR DEFINITION */
/* SOURCE embank.for:1415 */
/*<       zdatum=0.0 >*/
    zdatum = (float)0.;
/* SOURCE embank.for:1416 */
/*<        >*/
    inprdp_(stdin, stdout, &zdatum, eflag, &embcom_1.noff, &embcom_1.mincrs, &
	    embcom_1.minloc, embcom_1.off, embcom_1.crest, embcom_1.width, 
	    embcom_1.approc, embcmc_1.surf, (ftnlen)8);
/*     Adjust the crest and approach elevation to force local datum */
/*     to MINCRS. */
/*     Adjust for shift in crest */
/* SOURCE embank.for:1425 */
/*<       mincrs=mincrs+cshift >*/
    embcom_1.mincrs += cshift;
/* SOURCE embank.for:1426 */
/*<       do100i=1,noff >*/
    feq_gen_i_d_1 = embcom_1.noff;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE embank.for:1427 */
/*<       crest(i)=crest(i)+cshift >*/
	embcom_1.crest[feq_gen_i_d_ - 1] += cshift;
/* SOURCE embank.for:1428 */
/*<       crest(i)=crest(i)-mincrs >*/
	embcom_1.crest[feq_gen_i_d_ - 1] -= embcom_1.mincrs;
/* SOURCE embank.for:1429 */
/*<       approc(i)=approc(i)-mincrs >*/
	embcom_1.approc[feq_gen_i_d_ - 1] -= embcom_1.mincrs;
/*       Now apply the scale factors */
/* SOURCE embank.for:1431 */
/*<       crest(i)=crest(i)*vscale >*/
	embcom_1.crest[feq_gen_i_d_ - 1] *= vscale;
/* SOURCE embank.for:1432 */
/*<       approc(i)=approc(i)*vscale >*/
	embcom_1.approc[feq_gen_i_d_ - 1] *= vscale;
/* SOURCE embank.for:1433 */
/*<       off(i)=off(i)*hscale >*/
	embcom_1.off[feq_gen_i_d_ - 1] *= hscale;
/* SOURCE embank.for:1434 */
/*<       width(i)=width(i)*hscale >*/
	embcom_1.width[feq_gen_i_d_ - 1] *= hscale;
/* SOURCE embank.for:1435 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE embank.for:1436 */
/*<       zdatum=mincrs >*/
    zdatum = embcom_1.mincrs;
/* SOURCE embank.for:1437 */
/*<       zdatum=vscale*zdatum >*/
    zdatum = static_cast<double>(vscale) * zdatum;
/* SOURCE embank.for:1438 */
/*<       mincrs=0.0 >*/
    embcom_1.mincrs = (float)0.;
/* SOURCE embank.for:1440 */
/*<       write(stdout,30)zdatum >*/
    feq_gen_io_d__142.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__142);
    do_fio(&feq_gen_c_d_1, (char *)&zdatum, (ftnlen)sizeof(real));
    e_wsfe();
/*     Input the upstream head sequence to use - piezometric head */
/*     Clear the flag to signal that the line with the first head */
/*     is already in hand. */
/* SOURCE embank.for:1446 */
/*<       hflag=0 >*/
    hflag = 0;
/*     Set defaults for NFRAC and POWER */
/* SOURCE embank.for:1449 */
/*<       nfrac=21 >*/
    nfrac = 21;
/* SOURCE embank.for:1450 */
/*<       power=2.0 >*/
    power = (float)2.;
/*     Clear the linear interpolation precision to use as a flag */
/* SOURCE embank.for:1453 */
/*<       liprec=0.0 >*/
    liprec = (float)0.;
/* SOURCE embank.for:1454 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)120);
/* SOURCE embank.for:1457 */
/*<       read(line,'(A80)',err=991)head >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 120;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(A80)");
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE embank.for:1458 */
/*<       write(stdout,'(1X,A80)')head >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(1X,A80)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_wsfe();
/*     Check for the input option. Next line may contain the first */
/*     of the heads or it may contain a definition of the number of */
/*     fractions of free drop TO USE or it may contain linear */
/*     interpolation precision. */
/* SOURCE embank.for:1465 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)120);
/* SOURCE embank.for:1468 */
/*<       if(line(1:5).eq.'NFRAC')then >*/
    if (s_cmp(line, const_cast<char*>("NFRAC"), (ftnlen)5, (ftnlen)5) == 0) {
/*       We have an explicit specification of the number of fractions */
/*       of free drop to use. */
/* SOURCE embank.for:1471 */
/*<       read(line,26,err=991)char5,nfrac >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 120;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_26;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&nfrac, (ftnlen)sizeof(integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE embank.for:1472 */
/*<       write(stdout,94)char5,nfrac >*/
	feq_gen_io_d__149.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__149);
	do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, (char *)&nfrac, (ftnlen)sizeof(integer));
	e_wsfe();
/*       Get the power to use */
/* SOURCE embank.for:1475 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)120);
/* SOURCE embank.for:1478 */
/*<       read(line,16,err=991)char5,power >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 120;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_16;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&power, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE embank.for:1479 */
/*<       write(stdout,66)char5,power >*/
	feq_gen_io_d__150.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__150);
	do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, (char *)&power, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE embank.for:1481 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)120);
/* SOURCE embank.for:1484 */
/*<       if(line(1:6).eq.'LIPREC')then >*/
	if (s_cmp(line, const_cast<char*>("LIPREC"), (ftnlen)6, (ftnlen)6) == 0) {
/*         The user wants table optimization. */
/* SOURCE embank.for:1486 */
/*<       read(line,8,err=991)char6,liprec >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 120;
	    feq_gen_ici_d_1.iciunit = line;
	    feq_gen_ici_d_1.icifmt = fmt_8;
	    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
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
/* SOURCE embank.for:1487 */
/*<       write(stdout,79)liprec >*/
	    feq_gen_io_d__152.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__152);
	    do_fio(&feq_gen_c_d_1, (char *)&liprec, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE embank.for:1488 */
/*<       callinline(stdin,stdout,line) >*/
	    inline_(stdin, stdout, line, (ftnlen)120);
/* SOURCE embank.for:1491 */
/*<       read(line,8,err=991)char6,minpfd >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 120;
	    feq_gen_ici_d_1.iciunit = line;
	    feq_gen_ici_d_1.icifmt = fmt_8;
	    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
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
/* SOURCE embank.for:1492 */
/*<       write(stdout,80)minpfd >*/
	    feq_gen_io_d__154.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__154);
	    do_fio(&feq_gen_c_d_1, (char *)&minpfd, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE embank.for:1493 */
/*<       else >*/
	} else {
/*         We have the first line for head. */
/* SOURCE embank.for:1495 */
/*<       hflag=1 >*/
	    hflag = 1;
/* SOURCE embank.for:1496 */
/*<       endif >*/
	}
/* SOURCE embank.for:1497 */
/*<       elseif(line(1:6).eq.'LIPREC')then >*/
    } else if (s_cmp(line, const_cast<char*>("LIPREC"), (ftnlen)6, (ftnlen)6) == 0) {
/*       The user  wants table optimization. */
/* SOURCE embank.for:1499 */
/*<       read(line,8,err=991)char6,liprec >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 120;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_8;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
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
/* SOURCE embank.for:1500 */
/*<       write(stdout,79)liprec >*/
	feq_gen_io_d__155.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__155);
	do_fio(&feq_gen_c_d_1, (char *)&liprec, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE embank.for:1501 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)120);
/* SOURCE embank.for:1504 */
/*<       read(line,8,err=991)char6,minpfd >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 120;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_8;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
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
/* SOURCE embank.for:1505 */
/*<       write(stdout,80)minpfd >*/
	feq_gen_io_d__156.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__156);
	do_fio(&feq_gen_c_d_1, (char *)&minpfd, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE embank.for:1506 */
/*<       else >*/
    } else {
/*       We have the first line for head. */
/* SOURCE embank.for:1508 */
/*<       hflag=1 >*/
	hflag = 1;
/* SOURCE embank.for:1509 */
/*<       endif >*/
    }
/* SOURCE embank.for:1511 */
/*<       i=1 >*/
    feq_gen_i_d_ = 1;
/* SOURCE embank.for:1512 */
/*<   300 continue >*/
L300:
/* SOURCE embank.for:1513 */
/*<       if(hflag.eq.0)then >*/
    if (hflag == 0) {
/* SOURCE embank.for:1514 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)120);
/* SOURCE embank.for:1517 */
/*<       endif >*/
    }
/*       Only skip reading the first time if HFLAG = 1 */
/* SOURCE embank.for:1519 */
/*<       hflag=0 >*/
    hflag = 0;
/* SOURCE embank.for:1520 */
/*<       read(line,'(F10.0)',err=991)huvec(i) >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 120;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.0)");
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&huvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE embank.for:1521 */
/*<       write(stdout,'('' '',F10.2)')huvec(i) >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(' ',F10.2)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&huvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE embank.for:1522 */
/*<       if(huvec(i).le.0.0)then >*/
    if (huvec[feq_gen_i_d_ - 1] <= (float)0.) {
/* SOURCE embank.for:1523 */
/*<       nhu=i-1 >*/
	nhu = feq_gen_i_d_ - 1;
/* SOURCE embank.for:1524 */
/*<       goto310 >*/
	goto L310;
/* SOURCE embank.for:1525 */
/*<       else >*/
    } else {
/* SOURCE embank.for:1526 */
/*<       i=i+1 >*/
	++feq_gen_i_d_;
/* SOURCE embank.for:1527 */
/*<       if(i.gt.pmxnhu)then >*/
	if (feq_gen_i_d_ > 151) {
/* SOURCE embank.for:1528 */
/*<        >*/
	    feq_gen_ci_d_1.cierr = 0;
	    feq_gen_ci_d_1.ciunit = *stdout;
	    feq_gen_ci_d_1.cifmt = const_cast<char*>("(' *ERR:548* MORE THAN ',I5,' UPSTREAM HEADS')");
	    s_wsfe(&feq_gen_ci_d_1);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_151, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE embank.for:1531 */
/*<       i=pmxnhu >*/
	    feq_gen_i_d_ = 151;
/* SOURCE embank.for:1532 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE embank.for:1533 */
/*<       endif >*/
	}
/* SOURCE embank.for:1535 */
/*<       goto300 >*/
	goto L300;
/* SOURCE embank.for:1536 */
/*<       endif >*/
    }
/* SOURCE embank.for:1537 */
/*<   310 continue >*/
L310:
/*     Apply scale factor to heads. */
/* SOURCE embank.for:1540 */
/*<       do312i=1,nhu >*/
    feq_gen_i_d_1 = nhu;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE embank.for:1541 */
/*<       huvec(i)=huvec(i)*vscale >*/
	huvec[feq_gen_i_d_ - 1] *= vscale;
/* SOURCE embank.for:1542 */
/*<   312 continue >*/
/* L312: */
    }
/*     All items have been read-  start the computations. */
/*     For each upstream head compute the discharge and also */
/*     SET THE ROADWAY MOMENTUM FLUX FACTOR TO 1.0. NEEDED BY */
/*     FRFEMB BUT MOMENTUM FLUX NOT USED FOR COMMAND EMBANK. */
/* SOURCE embank.for:1550 */
/*<       rmffac=1.0 >*/
    embcom_1.rmffac = (float)1.;
/*     Compute the submerged flow if requested */
/* SOURCE embank.for:1556 */
/*<       if(nfrac.gt.pmxfrc-1)then >*/
    if (nfrac > 350) {
/* SOURCE embank.for:1557 */
/*<        >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(' *ERR:549* MORE THAN ',I5,' FRACTIONS OF FREE DROP')")
		;
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_351, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE embank.for:1561 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE embank.for:1562 */
/*<       endif >*/
    }
/* SOURCE embank.for:1563 */
/*<       if(eflag.gt.0)return >*/
    if (*eflag > 0) {
	return 0;
    }
/* SOURCE embank.for:1566 */
/*<       if(liprec.eq.0.0)then >*/
    if (liprec == (float)0.) {
/*       COMPUTE THE PROPORTIONS OF FREE DROP TO USE. */
/* SOURCE embank.for:1569 */
/*<       do500i=1,nfrac >*/
	feq_gen_i_d_1 = nfrac;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE embank.for:1570 */
/*<       pfdvec(i)=(float(i-1)/float(nfrac-1))**power >*/
	    feq_gen_d_d_1 = (doublereal) (static_cast<double>((real) (feq_gen_i_d_ - 1)) / (real) (nfrac - 1));
	    feq_gen_d_d_2 = (doublereal) power;
	    // PFD = REAL((I-1)/(NFRAC-1)) ** REAL(POWER).
        // Original 0x431d10..0x431d4a uses a retained reciprocal and a
        // REAL argument store before the released REAL power kernel.
        pfdvec[feq_gen_i_d_ - 1] = feq::legacy_power(
            static_cast<float>(static_cast<double>(feq_gen_i_d_-1)*(1.0/static_cast<double>(nfrac-1))),power);
/* SOURCE embank.for:1571 */
/*<   500 continue >*/
/* L500: */
	}
/* SOURCE embank.for:1572 */
/*<       else >*/
    } else {
/*       Redefine the head sequence and the sequence of */
/*       partial free drops. */
/* SOURCE embank.for:1575 */
/*<        >*/
	feq_gen_embankq_opt_d_(stdout, &liprec, &minpfd, &sflag, &feq_gen_local_minq_d_, &nhu, 
		huvec, &nfrac, pfdvec, eflag);
/* SOURCE embank.for:1579 */
/*<       endif >*/
    }
/*     Expand the PFD sequence to include the points needed */
/*     for estimationg interpolation error. */
/* SOURCE embank.for:1583 */
/*<       if(sflag.gt.0)then >*/
    if (sflag > 0) {
/* SOURCE embank.for:1584 */
/*<       nfrac2=nfrac+nfrac-2 >*/
	nfrac2 = nfrac + nfrac - 2;
/* SOURCE embank.for:1585 */
/*<       if(nfrac2.gt.pmxfrc-1)then >*/
	if (nfrac2 > 350) {
/* SOURCE embank.for:1586 */
/*<        >*/
	    feq_gen_ci_d_1.cierr = 0;
	    feq_gen_ci_d_1.ciunit = *stdout;
	    feq_gen_ci_d_1.cifmt = const_cast<char*>("(' *ERR:549* MORE THAN ',I5,' FRACTIONS OF FREE D\
ROP')");
	    s_wsfe(&feq_gen_ci_d_1);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_351, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE embank.for:1590 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE embank.for:1591 */
/*<       return >*/
	    return 0;
/* SOURCE embank.for:1592 */
/*<       endif >*/
	}
/* SOURCE embank.for:1593 */
/*<       k=nfrac2 >*/
	k = nfrac2;
/* SOURCE embank.for:1594 */
/*<       do510i=nfrac,3,-1 >*/
	for (feq_gen_i_d_ = nfrac; feq_gen_i_d_ >= 3; --feq_gen_i_d_) {
/*         Move the I-th point to its new location. */
/* SOURCE embank.for:1596 */
/*<       pfdvec(k)=pfdvec(i) >*/
	    pfdvec[k - 1] = pfdvec[feq_gen_i_d_ - 1];
/*         Insert the new point */
/* SOURCE embank.for:1598 */
/*<       pfdvec(k-1)=0.5*(pfdvec(k)+pfdvec(i-1)) >*/
	    pfdvec[k - 2] = static_cast<double>((static_cast<double>(pfdvec[k - 1]) + pfdvec[feq_gen_i_d_ - 2])) * (float).5;
/*         Point to the next new location */
/* SOURCE embank.for:1600 */
/*<       k=k-2 >*/
	    k += -2;
/* SOURCE embank.for:1601 */
/*<   510 continue >*/
/* L510: */
	}
/* SOURCE embank.for:1602 */
/*<       else >*/
    } else {
/* SOURCE embank.for:1603 */
/*<       nfrac2=nfrac >*/
	nfrac2 = nfrac;
/* SOURCE embank.for:1604 */
/*<       endif >*/
    }
/* SOURCE embank.for:1605 */
/*<       global_error=0.0 >*/
    feq_gen_global_error_d_ = (float)0.;
/* SOURCE embank.for:1606 */
/*<       location_hu=0 >*/
    feq_gen_location_hu_d_ = 0;
/* SOURCE embank.for:1607 */
/*<       location_pfd=0 >*/
    feq_gen_location_pfd_d_ = 0;
/* SOURCE embank.for:1608 */
/*<       n_gt=0 >*/
    feq_gen_n_gt_d_ = 0;
/* SOURCE embank.for:1609 */
/*<       n_gt_twice=0 >*/
    feq_gen_n_gt_twice_d_ = 0;
/* SOURCE embank.for:1610 */
/*<       qd_span=0.0 >*/
    feq_gen_qd_span_d_ = (float)0.;
/* SOURCE embank.for:1611 */
/*<       siesqr=0.d0 >*/
    siesqr = 0.;
/* SOURCE embank.for:1613 */
/*<       do5000i=1,nhu >*/
    feq_gen_i_d_1 = nhu;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*       CLEAR FLAGS TO RESTRICT WARNINGS TO ONE MESSAGE PER UPSTREAM */
/*       HEAD */
/* SOURCE embank.for:1617 */
/*<       hlflag=0 >*/
	embq_1.hlflag = 0;
/* SOURCE embank.for:1618 */
/*<       hpflag=0 >*/
	embq_1.hpflag = 0;
/*       COMPUTE A FLOW FOR EACH OF THE GIVEN HEAD VALUES */
/* SOURCE embank.for:1622 */
/*<       qfree=0.0 >*/
	qfree = (float)0.;
/* SOURCE embank.for:1623 */
/*<       hup=huvec(i) >*/
	hup = huvec[feq_gen_i_d_ - 1];
/*       Set the flow at zero partial free drop to 0.0 */
/* SOURCE embank.for:1626 */
/*<       q(i,1)=0.0 >*/
	q[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE embank.for:1628 */
/*<       if(i.eq.1)then >*/
	if (feq_gen_i_d_ == 1) {
/* SOURCE embank.for:1630 */
/*<        >*/
	    frfemb_(&hup, &embcom_1.mincrs, &embcom_1.plcwtb, &
		    embcom_1.glcwtb, &embcom_1.phcwtb, &embcom_1.ghcwtb, &
		    embcom_1.noff, embcom_1.off, embcom_1.crest, 
		    embcom_1.width, embcom_1.approc, embcmc_1.surf, &
		    embcom_1.rmffac, &embq_1.hlcrit, &embq_1.hlmax, &
		    embq_1.hlflag, &embq_1.hpflag, &eu, embcom_1.xrdfl, 
		    embcom_1.xrdfr, embcom_1.hrdfl, embcom_1.hrdfm, 
		    embcom_1.hrdfr, embcom_1.qrdfl, embcom_1.qrdfm, 
		    embcom_1.qrdfr, embcom_1.tothl, embcom_1.tothm, 
		    embcom_1.tothr, embcom_1.yfl, embcom_1.yfm, embcom_1.yfr, 
		    embcom_1.appl, embcom_1.appm, embcom_1.appr, embcom_1.wl, 
		    embcom_1.wm, embcom_1.wr, embcom_1.aell, embcom_1.aelm, 
		    embcom_1.aelr, &qfree, &mfree, &efree, (ftnlen)8);
/* SOURCE embank.for:1640 */
/*<       q(i,nfrac)=qfree >*/
	    q[feq_gen_i_d_ + nfrac * 151 - 152] = qfree;
/* SOURCE embank.for:1641 */
/*<       else >*/
	} else {
/*         Compute an intermediate value for error estimation. */
/* SOURCE embank.for:1643 */
/*<       xmid=0.5*(hup+huvec(i-1)) >*/
	    xmid = static_cast<double>((static_cast<double>(hup) + huvec[feq_gen_i_d_ - 2])) * (float).5;
/* SOURCE embank.for:1644 */
/*<        >*/
	    frfemb_(&xmid, &embcom_1.mincrs, &embcom_1.plcwtb, &
		    embcom_1.glcwtb, &embcom_1.phcwtb, &embcom_1.ghcwtb, &
		    embcom_1.noff, embcom_1.off, embcom_1.crest, 
		    embcom_1.width, embcom_1.approc, embcmc_1.surf, &
		    embcom_1.rmffac, &embq_1.hlcrit, &embq_1.hlmax, &
		    embq_1.hlflag, &embq_1.hpflag, &eu, embcom_1.xrdfl, 
		    embcom_1.xrdfr, embcom_1.hrdfl, embcom_1.hrdfm, 
		    embcom_1.hrdfr, embcom_1.qrdfl, embcom_1.qrdfm, 
		    embcom_1.qrdfr, embcom_1.tothl, embcom_1.tothm, 
		    embcom_1.tothr, embcom_1.yfl, embcom_1.yfm, embcom_1.yfr, 
		    embcom_1.appl, embcom_1.appm, embcom_1.appr, embcom_1.wl, 
		    embcom_1.wm, embcom_1.wr, embcom_1.aell, embcom_1.aelm, 
		    embcom_1.aelr, &fmid, &mfree, &efree, (ftnlen)8);
/* SOURCE embank.for:1654 */
/*<        >*/
	    frfemb_(&hup, &embcom_1.mincrs, &embcom_1.plcwtb, &
		    embcom_1.glcwtb, &embcom_1.phcwtb, &embcom_1.ghcwtb, &
		    embcom_1.noff, embcom_1.off, embcom_1.crest, 
		    embcom_1.width, embcom_1.approc, embcmc_1.surf, &
		    embcom_1.rmffac, &embq_1.hlcrit, &embq_1.hlmax, &
		    embq_1.hlflag, &embq_1.hpflag, &eu, embcom_1.xrdfl, 
		    embcom_1.xrdfr, embcom_1.hrdfl, embcom_1.hrdfm, 
		    embcom_1.hrdfr, embcom_1.qrdfl, embcom_1.qrdfm, 
		    embcom_1.qrdfr, embcom_1.tothl, embcom_1.tothm, 
		    embcom_1.tothr, embcom_1.yfl, embcom_1.yfm, embcom_1.yfr, 
		    embcom_1.appl, embcom_1.appm, embcom_1.appr, embcom_1.wl, 
		    embcom_1.wm, embcom_1.wr, embcom_1.aell, embcom_1.aelm, 
		    embcom_1.aelr, &qfree, &mfree, &efree, (ftnlen)8);
/* SOURCE embank.for:1663 */
/*<       q(i,nfrac)=qfree >*/
	    q[feq_gen_i_d_ + nfrac * 151 - 152] = qfree;
/* SOURCE embank.for:1665 */
/*<       rerr=(0.5*(qfree+q(i-1,nfrac))-fmid)/fmid >*/
	    rerr = static_cast<double>((static_cast<double>(static_cast<double>((static_cast<double>(qfree) + q[feq_gen_i_d_ - 1 + nfrac * 151 - 152])) * (float).5) - 
		    fmid)) / fmid;
/* SOURCE embank.for:1666 */
/*<       qd_span=qd_span+hup-huvec(i-1) >*/
	    feq_gen_qd_span_d_ = static_cast<double>(static_cast<double>(feq_gen_qd_span_d_) + hup) - huvec[feq_gen_i_d_ - 2];
/* SOURCE embank.for:1667 */
/*<       siesqr=siesqr+0.6666667*rerr**2*(hup-huvec(i-1)) >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = rerr;
	    siesqr += static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * (float).6666667) * (static_cast<double>(hup) - huvec[feq_gen_i_d_ - 2]);
/* SOURCE embank.for:1668 */
/*<       write(stdout,60)huvec(i-1),hup,rerr >*/
	    feq_gen_io_d__178.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__178);
	    do_fio(&feq_gen_c_d_1, (char *)&huvec[feq_gen_i_d_ - 2], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&hup, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&rerr, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE embank.for:1669 */
/*<       if(abs(rerr).gt.liprec.and.liprec.gt.0.0)then >*/
	    if (dabs(rerr) > liprec && liprec > (float)0.) {
/* SOURCE embank.for:1670 */
/*<       n_gt=n_gt+1 >*/
		++feq_gen_n_gt_d_;
/* SOURCE embank.for:1671 */
/*<       if(abs(rerr).gt.2.*liprec)then >*/
		if (dabs(rerr) > static_cast<double>(liprec) * (float)2.) {
/* SOURCE embank.for:1672 */
/*<       n_gt_twice=n_gt_twice+1 >*/
		    ++feq_gen_n_gt_twice_d_;
/* SOURCE embank.for:1673 */
/*<       endif >*/
		}
/* SOURCE embank.for:1674 */
/*<       endif >*/
	    }
/* SOURCE embank.for:1675 */
/*<       if(abs(rerr).gt.global_error)then >*/
	    if (dabs(rerr) > feq_gen_global_error_d_) {
/* SOURCE embank.for:1676 */
/*<       global_error=abs(rerr) >*/
		feq_gen_global_error_d_ = dabs(rerr);
/* SOURCE embank.for:1677 */
/*<       location_hu=i-1 >*/
		feq_gen_location_hu_d_ = feq_gen_i_d_ - 1;
/* SOURCE embank.for:1678 */
/*<       location_pfd=nfrac2 >*/
		feq_gen_location_pfd_d_ = nfrac2;
/* SOURCE embank.for:1679 */
/*<       endif >*/
	    }
/* SOURCE embank.for:1680 */
/*<       endif >*/
	}
/* SOURCE embank.for:1682 */
/*<       write(stdout,81)hup,qfree >*/
	feq_gen_io_d__179.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__179);
	do_fio(&feq_gen_c_d_1, (char *)&hup, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&qfree, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE embank.for:1685 */
/*<       if(sflag.gt.0)then >*/
	if (sflag > 0) {
/* SOURCE embank.for:1686 */
/*<       write(stdout,53) >*/
	    feq_gen_io_d__180.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__180);
	    e_wsfe();
/* SOURCE embank.for:1688 */
/*<        >*/
	    sbfemb_(&nfrac2, &eu, &hup, &embcom_1.mincrs, &embcom_1.minloc, &
		    embcom_1.plcwtb, &embcom_1.glcwtb, &embcom_1.phcwtb, &
		    embcom_1.ghcwtb, &embcom_1.psubtb, &embcom_1.gsubtb, &
		    embcom_1.noff, embcmc_1.surf, &embq_1.hlcrit, 
		    embcom_1.xrdfl, embcom_1.xrdfr, embcom_1.hrdfl, 
		    embcom_1.hrdfm, embcom_1.hrdfr, embcom_1.qrdfl, 
		    embcom_1.qrdfm, embcom_1.qrdfr, embcom_1.tothl, 
		    embcom_1.tothm, embcom_1.tothr, embcom_1.appl, 
		    embcom_1.appm, embcom_1.appr, embcom_1.wl, embcom_1.wm, 
		    embcom_1.wr, &qfree, pfdvec, &freed, qsbvec, (ftnlen)8);
/* SOURCE embank.for:1696 */
/*<       fdrop(i)=freed >*/
	    fdrop[feq_gen_i_d_ - 1] = freed;
/* SOURCE embank.for:1697 */
/*<       callvar_decimal(qsbvec(nfrac2),cq) >*/
	    feq_gen_var_decimal_d_(&qsbvec[nfrac2 - 1], cq, (ftnlen)8);
/* SOURCE embank.for:1699 */
/*<       write(stdout,55)pfdvec(nfrac2),freed,hup-freed,cq >*/
	    feq_gen_io_d__185.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__185);
	    do_fio(&feq_gen_c_d_1, (char *)&pfdvec[nfrac2 - 1], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&freed, (ftnlen)sizeof(real));
	    feq_gen_r_d_1 = static_cast<double>(hup) - freed;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, cq, (ftnlen)8);
	    e_wsfe();
/*        Note that NFRAC2 is always an even integer! */
/* SOURCE embank.for:1702 */
/*<       q(i,nfrac2/2+1)=qsbvec(nfrac2) >*/
	    q[feq_gen_i_d_ + (nfrac2 / 2 + 1) * 151 - 152] = qsbvec[nfrac2 - 1];
/* SOURCE embank.for:1703 */
/*<       do600j=nfrac2-2,2,-2 >*/
	    for (j = nfrac2 - 2; j >= 2; j += -2) {
/* SOURCE embank.for:1704 */
/*<       q(i,j/2+1)=qsbvec(j) >*/
		q[feq_gen_i_d_ + (j / 2 + 1) * 151 - 152] = qsbvec[j - 1];
/* SOURCE embank.for:1706 */
/*<       rerr=(0.5*(qsbvec(j)+qsbvec(j+2))/qsbvec(j+1)-1.0) >*/
		rerr = static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>(qsbvec[j - 1]) + qsbvec[j + 1])) * (float).5) / qsbvec[j])
			 - (float)1.;
/*           Use XMID as a temp variable. */
/* SOURCE embank.for:1708 */
/*<       xmid=freed*(pfdvec(j+2)-pfdvec(j)) >*/
		xmid = static_cast<double>(freed) * (static_cast<double>(pfdvec[j + 1]) - pfdvec[j - 1]);
/* SOURCE embank.for:1709 */
/*<       qd_span=qd_span+xmid >*/
		feq_gen_qd_span_d_ += xmid;
/* SOURCE embank.for:1710 */
/*<       siesqr=siesqr+0.6666667*rerr**2*xmid >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = rerr;
		siesqr += static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * (float).6666667) * xmid;
/* SOURCE embank.for:1711 */
/*<       drop=freed*pfdvec(j) >*/
		drop = static_cast<double>(freed) * pfdvec[j - 1];
/* SOURCE embank.for:1712 */
/*<       callvar_decimal(qsbvec(j),cq) >*/
		feq_gen_var_decimal_d_(&qsbvec[j - 1], cq, (ftnlen)8);
/* SOURCE embank.for:1714 */
/*<       write(stdout,55)pfdvec(j),drop,hup-drop,cq,rerr >*/
		feq_gen_io_d__188.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__188);
		do_fio(&feq_gen_c_d_1, (char *)&pfdvec[j - 1], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&drop, (ftnlen)sizeof(real));
		feq_gen_r_d_1 = feq::weir_downstream_head(hup,freed,pfdvec[j - 1]);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, cq, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, (char *)&rerr, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE embank.for:1716 */
/*<       if(abs(rerr).gt.liprec.and.liprec.gt.0.0)then >*/
		if (dabs(rerr) > liprec && liprec > (float)0.) {
/* SOURCE embank.for:1717 */
/*<       n_gt=n_gt+1 >*/
		    ++feq_gen_n_gt_d_;
/* SOURCE embank.for:1718 */
/*<       if(abs(rerr).gt.2.*liprec)then >*/
		    if (dabs(rerr) > static_cast<double>(liprec) * (float)2.) {
/* SOURCE embank.for:1719 */
/*<       n_gt_twice=n_gt_twice+1 >*/
			++feq_gen_n_gt_twice_d_;
/* SOURCE embank.for:1720 */
/*<       endif >*/
		    }
/* SOURCE embank.for:1721 */
/*<       endif >*/
		}
/* SOURCE embank.for:1722 */
/*<       if(abs(rerr).gt.global_error)then >*/
		if (dabs(rerr) > feq_gen_global_error_d_) {
/* SOURCE embank.for:1723 */
/*<       global_error=abs(rerr) >*/
		    feq_gen_global_error_d_ = dabs(rerr);
/* SOURCE embank.for:1724 */
/*<       location_hu=i >*/
		    feq_gen_location_hu_d_ = feq_gen_i_d_;
/* SOURCE embank.for:1725 */
/*<       location_pfd=j >*/
		    feq_gen_location_pfd_d_ = j;
/* SOURCE embank.for:1726 */
/*<       endif >*/
		}
/* SOURCE embank.for:1727 */
/*<   600 continue >*/
/* L600: */
	    }
/* SOURCE embank.for:1728 */
/*<       endif >*/
	}
/* SOURCE embank.for:1729 */
/*<  5000 continue >*/
/* L5000: */
    }
/* SOURCE embank.for:1731 */
/*<       if(location_pfd.eq.nfrac2)then >*/
    if (feq_gen_location_pfd_d_ == nfrac2) {
/* SOURCE embank.for:1732 */
/*<        >*/
	feq_gen_io_d__189.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__189);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_global_error_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&huvec[feq_gen_location_hu_d_ - 1], (ftnlen)sizeof(real))
		;
	do_fio(&feq_gen_c_d_1, (char *)&huvec[feq_gen_location_hu_d_], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE embank.for:1734 */
/*<       else >*/
    } else {
/* SOURCE embank.for:1735 */
/*<        >*/
	feq_gen_io_d__190.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__190);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_global_error_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&huvec[feq_gen_location_hu_d_ - 1], (ftnlen)sizeof(real))
		;
	do_fio(&feq_gen_c_d_1, (char *)&pfdvec[feq_gen_location_pfd_d_ - 1], (ftnlen)sizeof(
		real));
	do_fio(&feq_gen_c_d_1, (char *)&pfdvec[feq_gen_location_pfd_d_ + 1], (ftnlen)sizeof(
		real));
	e_wsfe();
/* SOURCE embank.for:1737 */
/*<       endif >*/
    }
/* SOURCE embank.for:1738 */
/*<       rms_error=sqrt(siesqr/qd_span) >*/
    feq_gen_rms_error_d_ = sqrt(siesqr / feq_gen_qd_span_d_);
/* SOURCE embank.for:1739 */
/*<       write(stdout,62)rms_error >*/
    feq_gen_io_d__192.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__192);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_rms_error_d_, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE embank.for:1740 */
/*<       if(liprec.gt.0.0)then >*/
    if (liprec > (float)0.) {
/* SOURCE embank.for:1741 */
/*<       if(sflag.gt.0)then >*/
	if (sflag > 0) {
/* SOURCE embank.for:1742 */
/*<       n=nhu-1+nhu*(nfrac-1) >*/
	    n = nhu - 1 + nhu * (nfrac - 1);
/* SOURCE embank.for:1743 */
/*<       else >*/
	} else {
/* SOURCE embank.for:1744 */
/*<       n=nhu-1 >*/
	    n = nhu - 1;
/* SOURCE embank.for:1745 */
/*<       endif >*/
	}
/* SOURCE embank.for:1747 */
/*<       write(stdout,64)float(n_gt)/n,float(n_gt_twice)/n >*/
	feq_gen_io_d__194.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__194);
	feq_gen_r_d_1 = static_cast<double>((real) feq_gen_n_gt_d_) / n;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	feq_gen_r_d_2 = static_cast<double>((real) feq_gen_n_gt_twice_d_) / n;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE embank.for:1748 */
/*<       endif >*/
    }
/* SOURCE embank.for:1750 */
/*<       if(sflag.eq.1)then >*/
    if (sflag == 1) {
/*       Squeeze out the extra PFD values */
/* SOURCE embank.for:1752 */
/*<       do5010i=4,nfrac2,2 >*/
	feq_gen_i_d_1 = nfrac2;
	for (feq_gen_i_d_ = 4; feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += 2) {
/* SOURCE embank.for:1753 */
/*<       pfdvec(i/2+1)=pfdvec(i) >*/
	    pfdvec[feq_gen_i_d_ / 2] = pfdvec[feq_gen_i_d_ - 1];
/* SOURCE embank.for:1754 */
/*<  5010 continue >*/
/* L5010: */
	}
/*       NOW OUTPUT THE TABLE TO STDTAB */
/* SOURCE embank.for:1759 */
/*<       zrhufd=0.0 >*/
	zrhufd = (float)0.;
/* SOURCE embank.for:1760 */
/*<        >*/
	feq_gen_r_d_1 = static_cast<double>(embcom_1.mincrs) + zdatum;
	twdout_(stdout, stdtab, &table, label, &nhu, &nfrac, huvec, fdrop, 
		pfdvec, q, &feq_gen_r_d_1, &feq_gen_type_d_, const_cast<char*>(" EMBANKQ"), &zrhufd, zone, hgrid, 
		vdatum, unitsys, basis, &easting, &northing, eflag, (ftnlen)
		50, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (
		ftnlen)8);
/* SOURCE embank.for:1768 */
/*<       if(twod_cubic_out.eq.'YES')then >*/
	if (s_cmp(upgrdc_1.feq_gen_twod_cubic_out_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3) == 
		0) {
/* SOURCE embank.for:1769 */
/*<       verbose=1 >*/
	    verbose = 1;
/* SOURCE embank.for:1770 */
/*<        >*/
	    feq_gen_r_d_1 = static_cast<double>(embcom_1.mincrs) + zdatum;
	    twodfit_(stdout, &table, &nhu, &nfrac, huvec, fdrop, pfdvec, q, &
		    feq_gen_r_d_1, &feq_gen_type_d_, const_cast<char*>(" EMBANKQ"), &zrhufd, &verbose, ftp, eflag, 
		    &ftpup, (ftnlen)8);
/* SOURCE embank.for:1776 */
/*<       endif >*/
	}
/* SOURCE embank.for:1777 */
/*<       else >*/
    } else {
/* SOURCE embank.for:1778 */
/*<       write(stdtab,22)tabid(1:lenstr(tabid)) >*/
	feq_gen_io_d__198.ciunit = *stdtab;
	s_wsfe(&feq_gen_io_d__198);
	do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
	e_wsfe();
/* SOURCE embank.for:1779 */
/*<       write(stdtab,29) >*/
	feq_gen_io_d__199.ciunit = *stdtab;
	s_wsfe(&feq_gen_io_d__199);
	e_wsfe();
/* SOURCE embank.for:1780 */
/*<       write(stdtab,'(''REFL= 0.0'')') >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdtab;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("('REFL= 0.0')");
	s_wsfe(&feq_gen_ci_d_1);
	e_wsfe();
/* SOURCE embank.for:1781 */
/*<       write(stdtab,'(''      HEAD DISCHARGE'')') >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdtab;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("('      HEAD DISCHARGE')");
	s_wsfe(&feq_gen_ci_d_1);
	e_wsfe();
/* SOURCE embank.for:1782 */
/*<       write(stdtab,28)0.0,0.0 >*/
	feq_gen_io_d__200.ciunit = *stdtab;
	s_wsfe(&feq_gen_io_d__200);
	do_fio(&feq_gen_c_d_1, (char *)&c_b360, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&c_b360, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE embank.for:1783 */
/*<       do2300i=1,nhu >*/
	feq_gen_i_d_1 = nhu;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE embank.for:1784 */
/*<       write(stdtab,28)huvec(i),q(i,nfrac) >*/
	    feq_gen_io_d__201.ciunit = *stdtab;
	    s_wsfe(&feq_gen_io_d__201);
	    do_fio(&feq_gen_c_d_1, (char *)&huvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&q[feq_gen_i_d_ + nfrac * 151 - 152], (ftnlen)sizeof(
		    real));
	    e_wsfe();
/* SOURCE embank.for:1785 */
/*<  2300 continue >*/
/* L2300: */
	}
/* SOURCE embank.for:1786 */
/*<       write(stdtab,28)-1.0,0.0 >*/
	feq_gen_io_d__202.ciunit = *stdtab;
	s_wsfe(&feq_gen_io_d__202);
	do_fio(&feq_gen_c_d_1, (char *)&c_b367, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&c_b360, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE embank.for:1787 */
/*<       endif >*/
    }
/* SOURCE embank.for:1789 */
/*<       return >*/
    return 0;
/* SOURCE embank.for:1790 */
/*<   991 continue >*/
L991:
/* SOURCE embank.for:1791 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__203.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__203);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE embank.for:1792 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__204.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__204);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)120);
    e_wsle();
/* SOURCE embank.for:1793 */
/*<       stop'Abnormal stop.  Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE embank.for:1794 */
/*<       end >*/
    return 0;
} /* embank_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE embank.for:1798 */
/*<        >*/
/* Subroutine */ int feq_gen_embankq_opt_d_(integer *stdout, real *liprec, real *
	minpfd, integer *sflag, real *minq, integer *nhu, real *feq_storage_huvec, 
	integer *nfrac, real *feq_storage_pfdvec, integer *eflag)
{
    /* Format strings */
    static char fmt_70[] = "(/,\002 EMBANKQ will use \002,i5,\002 upstream h\
eads for the 2-D\002,\002 table.\002,/,\002  The maximum estimated relative\
 \002,\002interpolation error is:\002,f10.3)";
    static char fmt_71[] = "(/,\002 EMBANKQ will use \002,i5,\002 partial fr\
ee drops for \002,\002the 2-D table.\002,/,\002  The maximum estimated\002\
,\002 relative interpolation error is:\002,f10.3)";
    static char fmt_72[] = "(/,\002 Using upstream head=\002,f8.3,\002 to de\
fine partial\002,\002 free drops.\002)";
    static char fmt_73[] = "(/,\002 Minimum head revised to: \002,f10.3,\002\
 for target flow=\002,f10.3)";
    static char fmt_99[] = "(/,\002 *ERR:635* Interpolation precision tables\
 missing.\002,\002 Check for version\002,/,11x,\002of file: TYPE5.TAB.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), e_wsfe();
    double log(doublereal), pow_dd(doublereal *, doublereal *);
    integer do_fio(integer *, char *, ftnlen), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle();

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    doublereal feq_gen_max_rerr_d_;
    extern /* Subroutine */ int ratiopnt_(integer *, doublereal *, doublereal 
	    *, doublereal *);
    real b;
    integer feq_gen_i_d_, j, n, feq_gen_nfrac_old_d_;
    real h1, h2, q1, q2, eu, hup;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    doublereal fvec[151], xvec[151];
    char temp[16];
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    doublereal feq_gen_break_points_d_[151];
    real freed, efree, dfcol, mfree;
    integer tabgt, tablt;
    real dfrow, qfree;
    extern /* Subroutine */ int tdlk10_(integer *, integer *, integer *, real 
	    *, real *, real *, real *, real *), frfemb_(real *, real *, 
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    real *, real *, real *, char *, real *, real *, real *, integer *,
	     integer *, real *, real *, real *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, ftnlen), sbfemb_(integer *, real *
	    , real *, real *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, char *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, ftnlen);
    real argrat, qsbvec[151];
    extern /* Subroutine */ int findbrk_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *, 
	    doublereal *, integer *, doublereal *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__211 = { 0, 0, 0, fmt_99, 0 };
    static cilist feq_gen_io_d__221 = { 0, 0, 0, fmt_73, 0 };
    static cilist feq_gen_io_d__233 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__234 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__237 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__239 = { 0, 0, 0, fmt_71, 0 };


/*     Compute a sequence for upstream head and partial free drops */
/*     to produce an optimized table for EMBANKQ. */
/* SOURCE embank.for:1806 */
/*<       implicitnone >*/
/* INCLUDE embank.for:1808 */
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
/* SOURCE embank.for:1811 */
/*<       integereflag,nfrac,nhu,stdout,sflag >*/
/* SOURCE embank.for:1812 */
/*<       realliprec,minpfd,minq,huvec(pmxnhu),pfdvec(pmxfrc) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     LIPREC - requested linear interpolation precision */
/*     MINPFD - minimum value of partial free drop in the 2-D table */
/*     SFLAG - =1 if submerged flows are to be computed, =0 otherwise */
/*     MINQ  - target minimum flow to re-define minimum head */
/*     NHU - number of upstream heads. */
/*     HUVEC - upstream head sequence */
/*     NFRAC - number of partial free drops */
/*     PFDVEC - sequence of partial free drops */
/*     EFLAG - error flag */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE embank.for:1828 */
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
/* INCLUDE embank.for:1829 */
/*     COMMOM BLOCK FOR THE DESCRIPTION OF THE FLOW OVER AN EMBANKMENT */
/* SOURCE embcom.cmn:3 */
/*<       character*8surf(pmxoff) >*/
/* SOURCE embcom.cmn:5 */
/*<       integernoff,minloc,plcwtb,glcwtb,phcwtb,ghcwtb,psubtb,gsubtb >*/
/* SOURCE embcom.cmn:8 */
/*<       realmincrs,rmffac >*/
/* SOURCE embcom.cmn:10 */
/*<        >*/
/* SOURCE embcom.cmn:20 */
/*<       common/embcmc/surf >*/
/* SOURCE embcom.cmn:22 */
/*<        >*/
/* INCLUDE embank.for:1830 */
/*     Common block for key values describing the nature of weir */
/*     flow. */
/* SOURCE embwrq.cmn:4 */
/*<       integerhlflag,hpflag >*/
/* SOURCE embwrq.cmn:6 */
/*<       realhlcrit,hlmax >*/
/* SOURCE embwrq.cmn:8 */
/*<       common/embq/hlflag,hpflag,hlcrit,hlmax >*/
/* SOURCE embwrq.cmn:10 */
/*<       save/embq/ >*/
/*     HLCRIT  Ratio of piezometric head to crest breadth at boundary */
/*             between low head and high head flow in the USGS */
/*             embankment-shaped weir methodology. */
/*     HLMAX   Maximum value of piezometric head to crest breadth ratio */
/*             above which a warning message is issued. */
/*     HLFLAG  Warning message suppression flag for warnings about the */
/*             piezometric head to crest breadth ratio becoming greater */
/*             than HLMAX */
/*     HPFLAG  Warning message suppression flag for invalid weir flow */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE embank.for:1834 */
/*<       integeri,j,tablt,tabgt,n,nfrac_old >*/
/* SOURCE embank.for:1835 */
/*<        >*/
/* SOURCE embank.for:1838 */
/*<       real*8xvec(pmxnhu),fvec(pmxnhu),break_points(pmxnhu),max_rerr >*/
/* SOURCE embank.for:1841 */
/*<       character*16temp >*/
/*     Call sub programs */
/* SOURCE embank.for:1844 */
/*<       externalget_internal_tab_number >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE embank.for:1847 */
/*<    70  >*/
/* SOURCE embank.for:1850 */
/*<    71  >*/
/* SOURCE embank.for:1853 */
/*<    72  >*/
/* SOURCE embank.for:1855 */
/*<    73  >*/
/* SOURCE embank.for:1857 */
/*<    98 format(1pe14.6,1pe14.6) >*/
/* SOURCE embank.for:1858 */
/*<    99  >*/
/* *********************************************************************** */
/*     Define the power-function interpolation precision tables. */
/* SOURCE embank.for:1863 */
/*<       temp='10001' >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> pfdvec(feq_storage_pfdvec, 1);

    feq::IndexedPointer<real> huvec(feq_storage_huvec, 1);

    /* Function Body */
/* L70: */
/* L71: */
/* L72: */
/* L73: */
/* L98: */
/* L99: */
    s_copy(temp, const_cast<char*>("10001"), (ftnlen)16, (ftnlen)5);
/* SOURCE embank.for:1864 */
/*<       callget_internal_tab_number(stdout,temp,eflag,tablt) >*/
    feq_gen_get_internal_tab_number_d_(stdout, temp, eflag, &tablt, (ftnlen)16);
/* SOURCE embank.for:1868 */
/*<       temp='10002' >*/
    s_copy(temp, const_cast<char*>("10002"), (ftnlen)16, (ftnlen)5);
/* SOURCE embank.for:1869 */
/*<       callget_internal_tab_number(stdout,temp,eflag,tabgt) >*/
    feq_gen_get_internal_tab_number_d_(stdout, temp, eflag, &tabgt, (ftnlen)16);
/* SOURCE embank.for:1873 */
/*<       tablt=ftpnt(tablt) >*/
    tablt = ftablea_1.ftpnt[tablt - 1];
/* SOURCE embank.for:1874 */
/*<       tabgt=ftpnt(tabgt) >*/
    tabgt = ftablea_1.ftpnt[tabgt - 1];
/* SOURCE embank.for:1875 */
/*<       if(tablt.lt.1.or.tabgt.lt.1)then >*/
    if (tablt < 1 || tabgt < 1) {
/* SOURCE embank.for:1876 */
/*<       write(stdout,99) >*/
	feq_gen_io_d__211.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__211);
	e_wsfe();
/* SOURCE embank.for:1877 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE embank.for:1878 */
/*<       return >*/
	return 0;
/* SOURCE embank.for:1879 */
/*<       endif >*/
    }
/*     Save entry value of NFRAC for lower limit of point set. */
/* SOURCE embank.for:1882 */
/*<       nfrac_old=nfrac >*/
    feq_gen_nfrac_old_d_ = *nfrac;
/*     Define a better minimum head.  Compute free flow at .5 and 1.0 */
/*     times the user-given minimum head value.  Find the power in */
/*     a simple power-function fit to these two points.    Then compute */
/*     the min-head value that would give a desired minimum flow. */
/*     The desired minimum flow is under user control but has a */
/*     default value. */
/* SOURCE embank.for:1890 */
/*<       h2=huvec(1) >*/
    h2 = huvec[1];
/* SOURCE embank.for:1891 */
/*<       h1=h2/2.0 >*/
    h1 = static_cast<double>(h2) / (float)2.;
/* SOURCE embank.for:1892 */
/*<        >*/
    frfemb_(&h1, &embcom_1.mincrs, &embcom_1.plcwtb, &embcom_1.glcwtb, &
	    embcom_1.phcwtb, &embcom_1.ghcwtb, &embcom_1.noff, embcom_1.off, 
	    embcom_1.crest, embcom_1.width, embcom_1.approc, embcmc_1.surf, &
	    embcom_1.rmffac, &embq_1.hlcrit, &embq_1.hlmax, &embq_1.hlflag, &
	    embq_1.hpflag, &eu, embcom_1.xrdfl, embcom_1.xrdfr, 
	    embcom_1.hrdfl, embcom_1.hrdfm, embcom_1.hrdfr, embcom_1.qrdfl, 
	    embcom_1.qrdfm, embcom_1.qrdfr, embcom_1.tothl, embcom_1.tothm, 
	    embcom_1.tothr, embcom_1.yfl, embcom_1.yfm, embcom_1.yfr, 
	    embcom_1.appl, embcom_1.appm, embcom_1.appr, embcom_1.wl, 
	    embcom_1.wm, embcom_1.wr, embcom_1.aell, embcom_1.aelm, 
	    embcom_1.aelr, &q1, &mfree, &efree, (ftnlen)8);
/* SOURCE embank.for:1901 */
/*<        >*/
    frfemb_(&h2, &embcom_1.mincrs, &embcom_1.plcwtb, &embcom_1.glcwtb, &
	    embcom_1.phcwtb, &embcom_1.ghcwtb, &embcom_1.noff, embcom_1.off, 
	    embcom_1.crest, embcom_1.width, embcom_1.approc, embcmc_1.surf, &
	    embcom_1.rmffac, &embq_1.hlcrit, &embq_1.hlmax, &embq_1.hlflag, &
	    embq_1.hpflag, &eu, embcom_1.xrdfl, embcom_1.xrdfr, 
	    embcom_1.hrdfl, embcom_1.hrdfm, embcom_1.hrdfr, embcom_1.qrdfl, 
	    embcom_1.qrdfm, embcom_1.qrdfr, embcom_1.tothl, embcom_1.tothm, 
	    embcom_1.tothr, embcom_1.yfl, embcom_1.yfm, embcom_1.yfr, 
	    embcom_1.appl, embcom_1.appm, embcom_1.appr, embcom_1.wl, 
	    embcom_1.wm, embcom_1.wr, embcom_1.aell, embcom_1.aelm, 
	    embcom_1.aelr, &q2, &mfree, &efree, (ftnlen)8);
/*     Compute the power of the simple power function that fits */
/*     these two points (and (0,0) as well). */
/* SOURCE embank.for:1913 */
/*<       b=log(q1/q2)/log(h1/h2) >*/
    b = log(static_cast<double>(q1) / q2) / log(static_cast<double>(h1) / h2);
/* SOURCE embank.for:1914 */
/*<       h1=h2*(minq/q2)**(1.0/b) >*/
    feq_gen_d_d_1 = (doublereal) (static_cast<double>(*minq) / q2);
    feq_gen_d_d_2 = (doublereal) (static_cast<double>((float)1.) / b);
    h1 = h2 * pow_dd(&feq_gen_d_d_1, &feq_gen_d_d_2);
/* SOURCE embank.for:1915 */
/*<       write(stdout,73)h1,minq >*/
    feq_gen_io_d__221.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__221);
    do_fio(&feq_gen_c_d_1, (char *)&h1, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&(*minq), (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE embank.for:1916 */
/*<       huvec(1)=h1 >*/
    huvec[1] = h1;
/*     Define the point set for computing the free flows to fit with */
/*     a cubic spline. Find the argument ratio, ARGRAT, for a power */
/*     of 2.5, close to the maximum for EMBANKQ. */
/* SOURCE embank.for:1922 */
/*<       calltdlk10(stdout,tabgt,10,2.5,liprec,argrat,dfrow,dfcol) >*/
    tdlk10_(stdout, &tabgt, &feq_gen_c_d_10, &c_b395, liprec, &argrat, &dfrow, &dfcol);
/*     Use the maximum and minimum head from the user and ARGRAT to */
/*     compute the number of heads to use and compute a new head */
/*     sequence. */
/* SOURCE embank.for:1929 */
/*<       n=int(log(huvec(nhu)/huvec(1))/log(argrat)+1.0)+1 >*/
    n = (integer) (log(static_cast<double>(huvec[*nhu]) / huvec[1]) / log(argrat) + (float)1.) + 1;
/* SOURCE embank.for:1930 */
/*<       if(n.lt.nfrac_old)n=nfrac_old >*/
    if (n < feq_gen_nfrac_old_d_) {
	n = feq_gen_nfrac_old_d_;
    }
/* SOURCE embank.for:1931 */
/*<       callratiopnt(n,dble(huvec(1)),dble(huvec(nhu)),xvec) >*/
    feq_gen_d_d_1 = (doublereal) huvec[1];
    feq_gen_d_d_2 = (doublereal) huvec[*nhu];
    ratiopnt_(&n, &feq_gen_d_d_1, &feq_gen_d_d_2, xvec);
/* SOURCE embank.for:1934 */
/*<       nhu=n >*/
    *nhu = n;
/*     Now compute the free flows for this sequence of heads. Set flags */
/*     to suppress warning messages. */
/* SOURCE embank.for:1938 */
/*<       hlflag=1 >*/
    embq_1.hlflag = 1;
/* SOURCE embank.for:1939 */
/*<       hpflag=1 >*/
    embq_1.hpflag = 1;
/* SOURCE embank.for:1940 */
/*<       rmffac=1.0 >*/
    embcom_1.rmffac = (float)1.;
/* SOURCE embank.for:1941 */
/*<       do110i=1,nhu >*/
    feq_gen_i_d_1 = *nhu;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE embank.for:1943 */
/*<       hup=real(xvec(i)) >*/
	hup = (real) xvec[feq_gen_i_d_ - 1];
/* SOURCE embank.for:1945 */
/*<        >*/
	frfemb_(&hup, &embcom_1.mincrs, &embcom_1.plcwtb, &embcom_1.glcwtb, &
		embcom_1.phcwtb, &embcom_1.ghcwtb, &embcom_1.noff, 
		embcom_1.off, embcom_1.crest, embcom_1.width, embcom_1.approc,
		 embcmc_1.surf, &embcom_1.rmffac, &embq_1.hlcrit, &
		embq_1.hlmax, &embq_1.hlflag, &embq_1.hpflag, &eu, 
		embcom_1.xrdfl, embcom_1.xrdfr, embcom_1.hrdfl, 
		embcom_1.hrdfm, embcom_1.hrdfr, embcom_1.qrdfl, 
		embcom_1.qrdfm, embcom_1.qrdfr, embcom_1.tothl, 
		embcom_1.tothm, embcom_1.tothr, embcom_1.yfl, embcom_1.yfm, 
		embcom_1.yfr, embcom_1.appl, embcom_1.appm, embcom_1.appr, 
		embcom_1.wl, embcom_1.wm, embcom_1.wr, embcom_1.aell, 
		embcom_1.aelm, embcom_1.aelr, &qfree, &mfree, &efree, (ftnlen)
		8);
/* SOURCE embank.for:1955 */
/*<       if(eflag.ne.0)then >*/
	if (*eflag != 0) {
/* SOURCE embank.for:1956 */
/*<       return >*/
	    return 0;
/* SOURCE embank.for:1957 */
/*<       endif >*/
	}
/* SOURCE embank.for:1958 */
/*<       fvec(i)=dble(qfree) >*/
	fvec[feq_gen_i_d_ - 1] = (doublereal) qfree;
/* SOURCE embank.for:1959 */
/*<   110 continue >*/
/* L110: */
    }
/*      WRITE(STDOUT,*) ' DUMP OF POINTS FOR TESTING' */
/*      WRITE(STDOUT,*)' NHU=',NHU */
/*      DO 111 I=1,NHU */
/*        WRITE(STDOUT,98) XVEC(I), FVEC(I) */
/* 111   CONTINUE */
/*     Try to find improved breakpoints. */
/* SOURCE embank.for:1969 */
/*<        >*/
    feq_gen_d_d_1 = (doublereal) (*liprec);
    findbrk_(stdout, nhu, xvec, fvec, &feq_gen_d_d_1, &feq_gen_c_d_1, &feq_gen_c_d_1, &n, feq_gen_break_points_d_,
	     eflag, &feq_gen_max_rerr_d_);
/* SOURCE embank.for:1974 */
/*<       if(eflag.ne.0)then >*/
    if (*eflag != 0) {
/* SOURCE embank.for:1975 */
/*<       return >*/
	return 0;
/* SOURCE embank.for:1976 */
/*<       endif >*/
    }
/* SOURCE embank.for:1977 */
/*<       nhu=n >*/
    *nhu = n;
/* SOURCE embank.for:1978 */
/*<       do120i=1,n >*/
    feq_gen_i_d_1 = n;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE embank.for:1979 */
/*<       huvec(i)=real(break_points(i)) >*/
	huvec[feq_gen_i_d_] = (real) feq_gen_break_points_d_[feq_gen_i_d_ - 1];
/* SOURCE embank.for:1980 */
/*<   120 continue >*/
/* L120: */
    }
/* SOURCE embank.for:1982 */
/*<       write(stdout,70)nhu,max_rerr >*/
    feq_gen_io_d__233.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__233);
    do_fio(&feq_gen_c_d_1, (char *)&(*nhu), (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_max_rerr_d_, (ftnlen)sizeof(doublereal));
    e_wsfe();
/* SOURCE embank.for:1983 */
/*<       if(sflag.eq.0)return >*/
    if (*sflag == 0) {
	return 0;
    }
/*     Select a head near the middle of the vector and compute the */
/*     free and submerged flows for that head to define the */
/*     basis for finding good breakpoints for the partial free */
/*     drops. */
/* SOURCE embank.for:1990 */
/*<       i=float(2*nhu)/3.+1. >*/
    feq_gen_i_d_ = static_cast<double>(static_cast<double>((real) (*nhu << 1)) / (float)3.) + (float)1.;
/* SOURCE embank.for:1991 */
/*<       if(i.gt.nhu)i=nhu >*/
    if (feq_gen_i_d_ > *nhu) {
	feq_gen_i_d_ = *nhu;
    }
/* SOURCE embank.for:1992 */
/*<       hup=huvec(i) >*/
    hup = huvec[feq_gen_i_d_];
/* SOURCE embank.for:1993 */
/*<        >*/
    frfemb_(&hup, &embcom_1.mincrs, &embcom_1.plcwtb, &embcom_1.glcwtb, &
	    embcom_1.phcwtb, &embcom_1.ghcwtb, &embcom_1.noff, embcom_1.off, 
	    embcom_1.crest, embcom_1.width, embcom_1.approc, embcmc_1.surf, &
	    embcom_1.rmffac, &embq_1.hlcrit, &embq_1.hlmax, &embq_1.hlflag, &
	    embq_1.hpflag, &eu, embcom_1.xrdfl, embcom_1.xrdfr, 
	    embcom_1.hrdfl, embcom_1.hrdfm, embcom_1.hrdfr, embcom_1.qrdfl, 
	    embcom_1.qrdfm, embcom_1.qrdfr, embcom_1.tothl, embcom_1.tothm, 
	    embcom_1.tothr, embcom_1.yfl, embcom_1.yfm, embcom_1.yfr, 
	    embcom_1.appl, embcom_1.appm, embcom_1.appr, embcom_1.wl, 
	    embcom_1.wm, embcom_1.wr, embcom_1.aell, embcom_1.aelm, 
	    embcom_1.aelr, &qfree, &mfree, &efree, (ftnlen)8);
/* SOURCE embank.for:2002 */
/*<       write(stdout,72)hup >*/
    feq_gen_io_d__234.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__234);
    do_fio(&feq_gen_c_d_1, (char *)&hup, (ftnlen)sizeof(real));
    e_wsfe();
/*     Define the sequence of partial free drops to use. */
/* SOURCE embank.for:2007 */
/*<       calltdlk10(stdout,tablt,10,0.5,liprec,argrat,dfrow,dfcol) >*/
    tdlk10_(stdout, &tablt, &feq_gen_c_d_10, &c_b404, liprec, &argrat, &dfrow, &dfcol);
/*     Use the maximum PFD, 1.0, and the MINPFD to compute */
/*     the number of PFD's. */
/* SOURCE embank.for:2014 */
/*<       n=int(log(1.0/minpfd)/log(argrat)+1.0)+1 >*/
    n = (integer) (log(static_cast<double>((float)1.) / *minpfd) / log(argrat) + (float)1.) + 1;
/* SOURCE embank.for:2015 */
/*<       if(n.lt.nfrac_old)n=nfrac_old >*/
    if (n < feq_gen_nfrac_old_d_) {
	n = feq_gen_nfrac_old_d_;
    }
/* SOURCE embank.for:2016 */
/*<       callratiopnt(n,dble(minpfd),1.d0,xvec) >*/
    feq_gen_d_d_1 = (doublereal) (*minpfd);
    ratiopnt_(&n, &feq_gen_d_d_1, &c_b405, xvec);
/*     Note: XVEC does not contain the zero point; PFDVEC does! */
/*     History has come back to haunt us! */
/* SOURCE embank.for:2021 */
/*<       nfrac=n+1 >*/
    *nfrac = n + 1;
/* SOURCE embank.for:2022 */
/*<       pfdvec(1)=0.0 >*/
    pfdvec[1] = (float)0.;
/* SOURCE embank.for:2023 */
/*<       do115i=2,nfrac >*/
    feq_gen_i_d_1 = *nfrac;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE embank.for:2024 */
/*<       pfdvec(i)=real(xvec(i-1)) >*/
	pfdvec[feq_gen_i_d_] = (real) xvec[feq_gen_i_d_ - 2];
/* SOURCE embank.for:2025 */
/*<   115 continue >*/
/* L115: */
    }
/* SOURCE embank.for:2026 */
/*<        >*/
    sbfemb_(nfrac, &eu, &hup, &embcom_1.mincrs, &embcom_1.minloc, &
	    embcom_1.plcwtb, &embcom_1.glcwtb, &embcom_1.phcwtb, &
	    embcom_1.ghcwtb, &embcom_1.psubtb, &embcom_1.gsubtb, &
	    embcom_1.noff, embcmc_1.surf, &embq_1.hlcrit, embcom_1.xrdfl, 
	    embcom_1.xrdfr, embcom_1.hrdfl, embcom_1.hrdfm, embcom_1.hrdfr, 
	    embcom_1.qrdfl, embcom_1.qrdfm, embcom_1.qrdfr, embcom_1.tothl, 
	    embcom_1.tothm, embcom_1.tothr, embcom_1.appl, embcom_1.appm, 
	    embcom_1.appr, embcom_1.wl, embcom_1.wm, embcom_1.wr, &qfree, &
	    pfdvec[1], &freed, qsbvec, (ftnlen)8);
/* SOURCE embank.for:2033 */
/*<       do116i=nfrac,2,-1 >*/
    for (feq_gen_i_d_ = *nfrac; feq_gen_i_d_ >= 2; --feq_gen_i_d_) {
/* SOURCE embank.for:2034 */
/*<       fvec(i-1)=qsbvec(i) >*/
	fvec[feq_gen_i_d_ - 2] = qsbvec[feq_gen_i_d_ - 1];
/* SOURCE embank.for:2035 */
/*<   116 continue >*/
/* L116: */
    }
/*     Try to find improved breakpoints. */
/* SOURCE embank.for:2039 */
/*<        >*/
    feq_gen_d_d_1 = (doublereal) (*liprec);
    findbrk_(stdout, &n, xvec, fvec, &feq_gen_d_d_1, &feq_gen_c_d_1, &feq_gen_c_d_1, nfrac, 
	    feq_gen_break_points_d_, eflag, &feq_gen_max_rerr_d_);
/* SOURCE embank.for:2043 */
/*<       if(eflag.ne.0)then >*/
    if (*eflag != 0) {
/* SOURCE embank.for:2044 */
/*<       write(stdout,*)' FINDBRK failure' >*/
	feq_gen_io_d__237.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__237);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FINDBRK failure"), (ftnlen)16);
	e_wsle();
/* SOURCE embank.for:2045 */
/*<       return >*/
	return 0;
/* SOURCE embank.for:2046 */
/*<       endif >*/
    }
/* SOURCE embank.for:2047 */
/*<       nfrac=nfrac+1 >*/
    ++(*nfrac);
/* SOURCE embank.for:2048 */
/*<       pfdvec(1)=0.0 >*/
    pfdvec[1] = (float)0.;
/* SOURCE embank.for:2049 */
/*<       do150j=2,nfrac >*/
    feq_gen_i_d_1 = *nfrac;
    for (j = 2; j <= feq_gen_i_d_1; ++j) {
/* SOURCE embank.for:2050 */
/*<       pfdvec(j)=break_points(j-1) >*/
	pfdvec[j] = feq_gen_break_points_d_[j - 2];
/* SOURCE embank.for:2051 */
/*<   150 continue >*/
/* L150: */
    }
/* SOURCE embank.for:2052 */
/*<       write(stdout,71)nfrac,max_rerr >*/
    feq_gen_io_d__239.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__239);
    do_fio(&feq_gen_c_d_1, (char *)&(*nfrac), (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_max_rerr_d_, (ftnlen)sizeof(doublereal));
    e_wsfe();
/* SOURCE embank.for:2054 */
/*<       return >*/
    return 0;
/* SOURCE embank.for:2055 */
/*<       end >*/
} /* embankq_opt__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE embank.for:2059 */
/*<       subroutineset_embk_item_defaults() >*/
/* Subroutine */ int feq_gen_set_embk_item_defaults_d_()
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     Set the default values in the vectors used to */
/* SOURCE embank.for:2062 */
/*<       implicitnone >*/
/* INCLUDE embank.for:2063 */
/* SOURCE embkitm.cmn:1 */
/*<       integermaxr_embkitm,maxc_embkitm,maxdp_embkitm >*/
/* SOURCE embkitm.cmn:2 */
/*<       parameter(maxr_embkitm=7,maxc_embkitm=2,maxdp_embkitm=1) >*/
/* SOURCE embkitm.cmn:3 */
/*<       integerembkitmitab(maxr_embkitm) >*/
/* SOURCE embkitm.cmn:4 */
/*<       realembkitmftab(maxr_embkitm) >*/
/* SOURCE embkitm.cmn:5 */
/*<       real*8embkitmdtab(maxdp_embkitm) >*/
/* SOURCE embkitm.cmn:6 */
/*<       character*64embkitmctab(maxc_embkitm) >*/
/* SOURCE embkitm.cmn:8 */
/*<       common/embkitm_com/embkitmdtab,embkitmitab,embkitmftab >*/
/* SOURCE embkitm.cmn:10 */
/*<       common/embkitm_comc/embkitmctab >*/
/* *********************************************************************** */
/*     Default for: TABID */
/* SOURCE embank.for:2067 */
/*<       embkitmctab(1)='    ' >*/
    s_copy(feq_gen_embkitm_comc_d_1.embkitmctab, const_cast<char*>("    "), (ftnlen)64, (ftnlen)4);
/*     Default for: TABLE - note # is ignored in the standard scanner */
/* SOURCE embank.for:2069 */
/*<       embkitmctab(2)='    ' >*/
    s_copy(feq_gen_embkitm_comc_d_1.embkitmctab + 64, const_cast<char*>("    "), (ftnlen)64, (ftnlen)4);
/*     Default for: TYPE */
/* SOURCE embank.for:2071 */
/*<       embkitmitab(1)=13 >*/
    feq_gen_embkitm_com_d_1.embkitmitab[0] = 13;
/*     Default for: HLCRIT */
/* SOURCE embank.for:2073 */
/*<       embkitmftab(2)=0.15 >*/
    feq_gen_embkitm_com_d_1.embkitmftab[1] = (float).15;
/*     Default for: HLMAX */
/* SOURCE embank.for:2075 */
/*<       embkitmftab(3)=0.32 >*/
    feq_gen_embkitm_com_d_1.embkitmftab[2] = (float).32;
/*     Default for: HSCALE */
/* SOURCE embank.for:2077 */
/*<       embkitmftab(4)=1.0 >*/
    feq_gen_embkitm_com_d_1.embkitmftab[3] = (float)1.;
/*     Default for: VSCALE */
/* SOURCE embank.for:2079 */
/*<       embkitmftab(5)=1.0 >*/
    feq_gen_embkitm_com_d_1.embkitmftab[4] = (float)1.;
/*     Default for: CSHIFT */
/* SOURCE embank.for:2081 */
/*<       embkitmftab(6)=0.0 >*/
    feq_gen_embkitm_com_d_1.embkitmftab[5] = (float)0.;
/*     Default for: LOCAL_MINQ */
/* SOURCE embank.for:2083 */
/*<       embkitmftab(7)=0.0 >*/
    feq_gen_embkitm_com_d_1.embkitmftab[6] = (float)0.;
/* SOURCE embank.for:2085 */
/*<       return >*/
    return 0;
/* SOURCE embank.for:2086 */
/*<       end >*/
} /* set_embk_item_defaults__ */




/* SOURCE embank.for:2090 */
/*<        >*/
/* Subroutine */ int feq_gen_set_embk_items_d_(integer *eflag, integer *tab, integer *
	feq_gen_type_d_, real *hlcrit, real *hlmax, real *hscale, real *vscale, real *
	cshift, real *feq_gen_local_minq_d_)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    char key1[16], key2[16];

/*     Set items in EMBANK */
/*     All values not set explicitly by user are at their default value. */
/* SOURCE embank.for:2098 */
/*<       implicitnone >*/
/* SOURCE embank.for:2100 */
/*<       integertab,type,getq,gety2,eflag >*/
/* SOURCE embank.for:2101 */
/*<       realhlcrit,hlmax,hscale,vscale,cshift,local_minq >*/
/*     Local */
/* SOURCE embank.for:2105 */
/*<       character*16key1,key2 >*/
/* INCLUDE embank.for:2107 */
/* SOURCE embkitm.cmn:1 */
/*<       integermaxr_embkitm,maxc_embkitm,maxdp_embkitm >*/
/* SOURCE embkitm.cmn:2 */
/*<       parameter(maxr_embkitm=7,maxc_embkitm=2,maxdp_embkitm=1) >*/
/* SOURCE embkitm.cmn:3 */
/*<       integerembkitmitab(maxr_embkitm) >*/
/* SOURCE embkitm.cmn:4 */
/*<       realembkitmftab(maxr_embkitm) >*/
/* SOURCE embkitm.cmn:5 */
/*<       real*8embkitmdtab(maxdp_embkitm) >*/
/* SOURCE embkitm.cmn:6 */
/*<       character*64embkitmctab(maxc_embkitm) >*/
/* SOURCE embkitm.cmn:8 */
/*<       common/embkitm_com/embkitmdtab,embkitmitab,embkitmftab >*/
/* SOURCE embkitm.cmn:10 */
/*<       common/embkitm_comc/embkitmctab >*/
/* INCLUDE embank.for:2108 */
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
/*     Set the table id.  There  are two strings allowed as the variable name: */
/*     TABID or TABLE */
/* SOURCE embank.for:2112 */
/*<       key1=embkitmctab(1) >*/
    s_copy(key1, feq_gen_embkitm_comc_d_1.embkitmctab, (ftnlen)16, (ftnlen)64);
/* SOURCE embank.for:2113 */
/*<       key2=embkitmctab(2) >*/
    s_copy(key2, feq_gen_embkitm_comc_d_1.embkitmctab + 64, (ftnlen)16, (ftnlen)64);
/* SOURCE embank.for:2114 */
/*<       if(key1.ne.' ')then >*/
    if (s_cmp(key1, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/* SOURCE embank.for:2115 */
/*<       callget_internal_tab_number(std6,key1,eflag,tab) >*/
	feq_gen_get_internal_tab_number_d_(&feq_gen_stdun_com_d_1.std6, key1, eflag, tab, (
		ftnlen)16);
/* SOURCE embank.for:2119 */
/*<       elseif(key2.ne.' ')then >*/
    } else if (s_cmp(key2, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/* SOURCE embank.for:2120 */
/*<       callget_internal_tab_number(std6,key2,eflag,tab) >*/
	feq_gen_get_internal_tab_number_d_(&feq_gen_stdun_com_d_1.std6, key2, eflag, tab, (
		ftnlen)16);
/* SOURCE embank.for:2124 */
/*<       else >*/
    } else {
/* SOURCE embank.for:2125 */
/*<       tab=0 >*/
	*tab = 0;
/* SOURCE embank.for:2126 */
/*<       endif >*/
    }
/*     Set the value for TYPE */
/* SOURCE embank.for:2129 */
/*<       type=embkitmitab(1) >*/
    *feq_gen_type_d_ = feq_gen_embkitm_com_d_1.embkitmitab[0];
/*     Set the value for HLCRIT */
/* SOURCE embank.for:2131 */
/*<       hlcrit=embkitmftab(2) >*/
    *hlcrit = feq_gen_embkitm_com_d_1.embkitmftab[1];
/*     Set the value for HLMAX */
/* SOURCE embank.for:2133 */
/*<       hlmax=embkitmftab(3) >*/
    *hlmax = feq_gen_embkitm_com_d_1.embkitmftab[2];
/*     Set the value for HSCALE */
/* SOURCE embank.for:2135 */
/*<       hscale=embkitmftab(4) >*/
    *hscale = feq_gen_embkitm_com_d_1.embkitmftab[3];
/*     Set the value for VSCALE */
/* SOURCE embank.for:2137 */
/*<       vscale=embkitmftab(5) >*/
    *vscale = feq_gen_embkitm_com_d_1.embkitmftab[4];
/*     Set the value for CSHIFT */
/* SOURCE embank.for:2139 */
/*<       cshift=embkitmftab(6) >*/
    *cshift = feq_gen_embkitm_com_d_1.embkitmftab[5];
/*     Set the value for the local MINQ */
/* SOURCE embank.for:2141 */
/*<       local_minq=embkitmftab(7) >*/
    *feq_gen_local_minq_d_ = feq_gen_embkitm_com_d_1.embkitmftab[6];
/* SOURCE embank.for:2143 */
/*<       return >*/
    return 0;
/* SOURCE embank.for:2144 */
/*<       end >*/
} /* set_embk_items__ */




/* SOURCE embank.for:2148 */
/*<       subroutineget_embk_items(stdin,stdout,eflag) >*/
/* Subroutine */ int feq_gen_get_embk_items_d_(integer *stdin, integer *stdout, 
	integer *eflag)
{
    /* Initialized data */

    static char feq_gen_symbol_table_d_[16*9+1] = "TABID           TABLE           TY\
PE            HLCRIT          HLMAX           HSCALE          VSCALE        \
  CSHIFT          MINQ            ";
    static integer group[9] = { 1,1,0,0,0,0,0,0,0 };
    static integer feq_gen_group_index_d_[9] = { 1,2,1,2,3,4,5,6,7 };
    static integer feq_gen_response_type_d_[9] = { 4,4,1,2,2,2,2,2,2 };
    static integer feq_gen_convert_rule_d_[9] = { 1,1,0,1,1,1,1,1,1 };

    integer feq_gen_max_line_d_;
    extern /* Subroutine */ int feq_gen_set_embk_item_defaults_d_(), feq_gen_get_named_items_d_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, char *, integer *, integer *, integer *, 
	    char *, integer *, real *, doublereal *, char *, integer *, 
	    ftnlen, ftnlen, ftnlen);

/*     Get the table id and various options for EMBANKQ command */
/* SOURCE embank.for:2153 */
/*<       implicitnone >*/
/* INCLUDE embank.for:2155 */
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
/* SOURCE embank.for:2157 */
/*<       integerstdin,stdout,eflag >*/
/* INCLUDE embank.for:2159 */
/* SOURCE embkitm.cmn:1 */
/*<       integermaxr_embkitm,maxc_embkitm,maxdp_embkitm >*/
/* SOURCE embkitm.cmn:2 */
/*<       parameter(maxr_embkitm=7,maxc_embkitm=2,maxdp_embkitm=1) >*/
/* SOURCE embkitm.cmn:3 */
/*<       integerembkitmitab(maxr_embkitm) >*/
/* SOURCE embkitm.cmn:4 */
/*<       realembkitmftab(maxr_embkitm) >*/
/* SOURCE embkitm.cmn:5 */
/*<       real*8embkitmdtab(maxdp_embkitm) >*/
/* SOURCE embkitm.cmn:6 */
/*<       character*64embkitmctab(maxc_embkitm) >*/
/* SOURCE embkitm.cmn:8 */
/*<       common/embkitm_com/embkitmdtab,embkitmitab,embkitmftab >*/
/* SOURCE embkitm.cmn:10 */
/*<       common/embkitm_comc/embkitmctab >*/
/*     Local */
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE embank.for:2164 */
/*<        >*/
/* SOURCE embank.for:2167 */
/*<        >*/
/* SOURCE embank.for:2171 */
/*<       integermax_line >*/
/* SOURCE embank.for:2174 */
/*<       externalget_named_items,set_embk_item_defaults >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE embank.for:2177 */
/*<        >*/
/* SOURCE embank.for:2179 */
/*<       charactersymbol_table(n_symbol)*16 >*/
/* SOURCE embank.for:2181 */
/*<       savesymbol_table,group,response_type,convert_rule,group_index >*/
/* *********************************************************************** */
/*     Set Defaults */
/* SOURCE embank.for:2184 */
/*<        >*/
/* SOURCE embank.for:2188 */
/*<       datagroup/char,char,7*numeric/ >*/
/* SOURCE embank.for:2191 */
/*<       datagroup_index/1,2,1,2,3,4,5,6,7/ >*/
/* SOURCE embank.for:2194 */
/*<       dataresponse_type/chrval,chrval,intval,6*reaval/ >*/
/* SOURCE embank.for:2197 */
/*<       dataconvert_rule/lower,lower,exact,6*lower/ >*/
/* SOURCE embank.for:2203 */
/*<       callset_embk_item_defaults() >*/
    feq_gen_set_embk_item_defaults_d_();
/* SOURCE embank.for:2205 */
/*<       max_line=1 >*/
    feq_gen_max_line_d_ = 1;
/* SOURCE embank.for:2206 */
/*<        >*/
    feq_gen_get_named_items_d_(stdin, stdout, &feq_gen_max_line_d_, &feq_gen_c_d_9, group, 
	    feq_gen_response_type_d_, feq_gen_convert_rule_d_, feq_gen_group_index_d_, feq_gen_symbol_table_d_, &
	    feq_gen_c_d_7, &feq_gen_c_d_1, &feq_gen_c_d_2, const_cast<char*>("EMBANKQ items"), feq_gen_embkitm_com_d_1.embkitmitab, 
	    feq_gen_embkitm_com_d_1.embkitmftab, feq_gen_embkitm_com_d_1.embkitmdtab, 
	    feq_gen_embkitm_comc_d_1.embkitmctab, eflag, (ftnlen)16, (ftnlen)13, (
	    ftnlen)64);
/* SOURCE embank.for:2213 */
/*<       return >*/
    return 0;
/* SOURCE embank.for:2215 */
/*<       end >*/
} /* get_embk_items__ */

#ifdef __cplusplus
	}
#endif
