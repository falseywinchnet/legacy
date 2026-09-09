/* tdtchk_free.f -- translated by f2c (version 20240504).
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

/* COMMON bnrslt_ is declared in common.hpp. */

#define bnrslt_1 bnrslt_

/* COMMON enrslt_ is declared in common.hpp. */

#define enrslt_1 enrslt_

/* COMMON julian_ is declared in common.hpp. */

#define julian_1 julian_

/* COMMON inbr_ is declared in common.hpp. */

#define inbr_1 inbr_

/* COMMON inen_ is declared in common.hpp. */

#define inen_1 inen_

/* COMMON inenc_ is declared in common.hpp. */

#define inenc_1 inenc_

/* COMMON matcom_ is declared in common.hpp. */

#define matcom_1 matcom_

/* COMMON matcom2_ is declared in common.hpp. */

#define matcom2_1 matcom2_

/* Table of constant values */

static integer feq_gen_c_d_6 = 6;
static integer feq_gen_c_d_13 = 13;
static integer feq_gen_c_d_43 = 43;
static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_14 = 14;
static integer feq_gen_c_d_9 = 9;




/* SOURCE tdtchk_free.for:4 */
/*<        >*/
/* Subroutine */ int feq_gen_get14_free_d_(integer *stdout, integer *adr, integer *
	ztab, real *zd, real *q, doublereal *jt, real *hdatum, integer *tabn, 
	real *qmx, real *hmax, integer *free, integer *wspro, real *rover, 
	real *qf)
{
    /* Local variables */
    extern /* Subroutine */ int feq_gen_tdlk14_chk_d_(integer *, integer *, integer *, 
	    real *, real *, real *, real *, real *, integer *);
    real hu, pdv;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ntab;
    real qarg;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real qfree;
    integer tabtyp;
    extern /* Subroutine */ int lktstab_(integer *, doublereal *, real *, 
	    integer *, real *);

/*     + + + PURPOSE + + + */
/*     Find needed values for table of type 14 in a Code 5 Type 6 */
/*     instruction to check table state. */
/* SOURCE tdtchk_free.for:14 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE tdtchk_free.for:16 */
/*<       integeradr,free,stdout,tabn,wspro,ztab >*/
/* SOURCE tdtchk_free.for:17 */
/*<       realhdatum,hmax,q,qf,qmx,rover,zd >*/
/* SOURCE tdtchk_free.for:18 */
/*<       real*8jt >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - unit number for standatd output */
/*     ADR    - address of the function table in FTAB/ITAB */
/*     ZTAB   - address of table giving variable datum level */
/*     ZD     - elevation at downstream node */
/*     Q      - flow through the structure */
/*     JT     - julian time */
/*     HDATUM - datum for heads */
/*     HEAD   - maximum simulated head for this table */
/*     TABN   - table number */
/*     QMX    - maximum tabulated free flow in the table */
/*     HMAX   - maximum head tabulated in the table */
/*     FREE   - table state: 1--free flow, 0--submerged flow */
/*     WSPRO  - source of table: 1--from WSPRO; 0--otherwise */
/*     ROVER  - relative amount that QARG is over free flow. */
/*     QF     - free flow */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE tdtchk_free.for:38 */
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
/* INCLUDE tdtchk_free.for:39 */
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
/* INCLUDE tdtchk_free.for:40 */
/* ********************************************************************** */
/* SOURCE bnrslt.cmn:2 */
/*<       common/bnrslt/tqmax,tqmin,tzmax,qmax,qmin,zmax,vmax >*/
/* SOURCE bnrslt.cmn:5 */
/*<       realqmax(mnbn),qmin(mnbn),zmax(mnbn),vmax(mnbn) >*/
/* SOURCE bnrslt.cmn:7 */
/*<       doubleprecisiontqmax(mnbn),tqmin(mnbn),tzmax(mnbn) >*/
/* ********************************************************************** */
/* INCLUDE tdtchk_free.for:41 */
/* ********************************************************************** */
/* SOURCE enrslt.cmn:3 */
/*<        >*/
/* SOURCE enrslt.cmn:7 */
/*<       integertostore(mnex),flownode(mnex),othernode(mnex) >*/
/* SOURCE enrslt.cmn:9 */
/*<        >*/
/* SOURCE enrslt.cmn:12 */
/*<       doubleprecisionftqmax(mnex),ftqmin(mnex),ftzmax(mnex) >*/
/* ********************************************************************** */
/*     Definition of identifiers */
/*     FTQMAX - time of maximum flow at a free node */
/*     FTQMIM - time of minimum flow at a free node */
/*     FTZMAX - time of maximium elevation at a free node */
/*     FNQMAX - maximum flow at a free node */
/*     FNZMAX - maximum elevation at a free node */
/*     FNQMIN - minimum flow at a free node */
/*     FLOWNODE - flow node number (internal) for flow node */
/*     OTHERNODE- other node number (internal) for the other head node */
/*     TOSTORE - vector of pointers (vector indices) to the location */
/*              where the flow at the flow node and the elevation at */
/*              the other node are stored for a 2-D control structure */
/*              using  a Code 5 Type 6 instruction in */
/*              the Network Matrix Control Input. */
/*              Used to check state of 2-D tables  at the end of a run. */
/*     QSTORE - vector of flows at the flow node for the control structure */
/*               of Code 5 Type 6.  This is the flow at the time the maximun */
/*               elevation occurs at the node in FNZMAX */
/*     ZSTORE- vector of elevation at the other node  at the time of */
/*              maximum elevation at the node in FNZMAX. */
/* INCLUDE tdtchk_free.for:42 */
/* ********************************************************************** */
/* SOURCE julian.cmn:3 */
/*<        >*/
/* SOURCE julian.cmn:8 */
/*<       integeryr,mn,dy,syr,smn,sdy,eyr,emn,edy,reset,leap,dmyear,dmmn >*/
/* SOURCE julian.cmn:10 */
/*<        >*/
/* ********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE tdtchk_free.for:45 */
/*<       integerntab,tabtyp >*/
/* SOURCE tdtchk_free.for:46 */
/*<       realhu,pdv,qarg,qfree >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE tdtchk_free.for:49 */
/*<       externallktstab >*/
/* *********************************************************************** */
/* SOURCE tdtchk_free.for:51 */
/*<       qarg=q >*/
    qarg = *q;
/* SOURCE tdtchk_free.for:52 */
/*<       tabn=itab(adr+1) >*/
    *tabn = itab[*adr + 1];
/* SOURCE tdtchk_free.for:53 */
/*<       tabtyp=itab(adr+2) >*/
    tabtyp = itab[*adr + 2];
/* SOURCE tdtchk_free.for:54 */
/*<       qmx=ftab(adr+9) >*/
    *qmx = ftab[*adr + 9];
/* SOURCE tdtchk_free.for:55 */
/*<       hmax=ftab(adr+5) >*/
    *hmax = ftab[*adr + 5];
/* SOURCE tdtchk_free.for:56 */
/*<       wspro=itab(adr+7) >*/
    *wspro = itab[*adr + 7];
/* SOURCE tdtchk_free.for:57 */
/*<       if(ztab.gt.0)then >*/
    if (*ztab > 0) {
/* SOURCE tdtchk_free.for:58 */
/*<       calllktstab(ztab,jt,hdatum,ntab,pdv) >*/
	lktstab_(ztab, jt, hdatum, &ntab, &pdv);
/* SOURCE tdtchk_free.for:61 */
/*<       endif >*/
    }
/* SOURCE tdtchk_free.for:64 */
/*<       calltdlk14_chk(stdout,adr,tabtyp,zd,hdatum,qarg,hu,qfree,free) >*/
    feq_gen_tdlk14_chk_d_(stdout, adr, &tabtyp, zd, hdatum, &qarg, &hu, &qfree, free);
/* SOURCE tdtchk_free.for:69 */
/*<       rover=(qarg-qfree)/qfree >*/
    *rover = static_cast<double>((static_cast<double>(qarg) - qfree)) / qfree;
/* SOURCE tdtchk_free.for:70 */
/*<       qf=qfree >*/
    *qf = qfree;
/* SOURCE tdtchk_free.for:71 */
/*<       return >*/
    return 0;
/* SOURCE tdtchk_free.for:72 */
/*<       end >*/
} /* get14_free__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE tdtchk_free.for:76 */
/*<        >*/
/* Subroutine */ int feq_gen_get613_free_d_(integer *stdout, integer *adr, integer *
	ztab, real *zu, real *zd, doublereal *jt, real *hdatum, integer *tabn,
	 integer *tabtyp, real *hmax, integer *free)
{
    /* Local variables */
    real q, pdv;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
    real dqed;
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer mtab, ntab;
    real dqeu;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int tdlk6_(integer *, integer *, integer *, 
	    integer *, doublereal *, real *, real *, real *, real *, real *, 
	    real *, integer *), tdlk13_(integer *, integer *, integer *, 
	    integer *, doublereal *, real *, real *, real *, real *, real *, 
	    real *, integer *), tdlk43_(integer *, integer *, integer *, 
	    integer *, doublereal *, real *, real *, real *, real *, real *, 
	    real *, integer *), lktstab_(integer *, doublereal *, real *, 
	    integer *, real *);

/*     + + + PURPOSE + + + */
/*     Get needed items from tables of type 6 or 13 in a Code 5 Type 6 */
/*     instruction to check the table state. */
/* SOURCE tdtchk_free.for:85 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE tdtchk_free.for:87 */
/*<       integeradr,free,stdout,tabn,tabtyp,ztab >*/
/* SOURCE tdtchk_free.for:88 */
/*<       realhdatum,hmax,zd,zu >*/
/* SOURCE tdtchk_free.for:89 */
/*<       real*8jt >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - unit number for standatd output */
/*     ADR    - address of the function table in FTAB/ITAB */
/*     ZTAB   - address of table giving variable datum level */
/*     ZU     - upstream elevation */
/*     ZD     - downstream elevation */
/*     JT     - modified julian time of max. elev. */
/*     HDATUM - datum for heads */
/*     TABN   - table number */
/*     TABTYP - table type */
/*     HMAX   - maximum head tabulated in the table */
/*     FREE   - state of table: 1--free flow; 0--submerged */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE tdtchk_free.for:105 */
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
/* INCLUDE tdtchk_free.for:106 */
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
/* INCLUDE tdtchk_free.for:107 */
/* ********************************************************************** */
/* SOURCE bnrslt.cmn:2 */
/*<       common/bnrslt/tqmax,tqmin,tzmax,qmax,qmin,zmax,vmax >*/
/* SOURCE bnrslt.cmn:5 */
/*<       realqmax(mnbn),qmin(mnbn),zmax(mnbn),vmax(mnbn) >*/
/* SOURCE bnrslt.cmn:7 */
/*<       doubleprecisiontqmax(mnbn),tqmin(mnbn),tzmax(mnbn) >*/
/* ********************************************************************** */
/* INCLUDE tdtchk_free.for:108 */
/* ********************************************************************** */
/* SOURCE enrslt.cmn:3 */
/*<        >*/
/* SOURCE enrslt.cmn:7 */
/*<       integertostore(mnex),flownode(mnex),othernode(mnex) >*/
/* SOURCE enrslt.cmn:9 */
/*<        >*/
/* SOURCE enrslt.cmn:12 */
/*<       doubleprecisionftqmax(mnex),ftqmin(mnex),ftzmax(mnex) >*/
/* ********************************************************************** */
/*     Definition of identifiers */
/*     FTQMAX - time of maximum flow at a free node */
/*     FTQMIM - time of minimum flow at a free node */
/*     FTZMAX - time of maximium elevation at a free node */
/*     FNQMAX - maximum flow at a free node */
/*     FNZMAX - maximum elevation at a free node */
/*     FNQMIN - minimum flow at a free node */
/*     FLOWNODE - flow node number (internal) for flow node */
/*     OTHERNODE- other node number (internal) for the other head node */
/*     TOSTORE - vector of pointers (vector indices) to the location */
/*              where the flow at the flow node and the elevation at */
/*              the other node are stored for a 2-D control structure */
/*              using  a Code 5 Type 6 instruction in */
/*              the Network Matrix Control Input. */
/*              Used to check state of 2-D tables  at the end of a run. */
/*     QSTORE - vector of flows at the flow node for the control structure */
/*               of Code 5 Type 6.  This is the flow at the time the maximun */
/*               elevation occurs at the node in FNZMAX */
/*     ZSTORE- vector of elevation at the other node  at the time of */
/*              maximum elevation at the node in FNZMAX. */
/* INCLUDE tdtchk_free.for:109 */
/* ********************************************************************** */
/* SOURCE julian.cmn:3 */
/*<        >*/
/* SOURCE julian.cmn:8 */
/*<       integeryr,mn,dy,syr,smn,sdy,eyr,emn,edy,reset,leap,dmyear,dmmn >*/
/* SOURCE julian.cmn:10 */
/*<        >*/
/* ********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE tdtchk_free.for:112 */
/*<       integermtab,ntab >*/
/* SOURCE tdtchk_free.for:113 */
/*<       realpdv,q,dqed,dqeu >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE tdtchk_free.for:116 */
/*<       externallktstab >*/
/* *********************************************************************** */
/*     The optional time-serie table giving a factor on the flows in the */
/*     2-D table is ignored here.  We only want the table state. */
/* SOURCE tdtchk_free.for:120 */
/*<       mtab=0 >*/
    mtab = 0;
/*     Time is also ignored */
/* SOURCE tdtchk_free.for:123 */
/*<       tabn=itab(adr+1) >*/
    *tabn = itab[*adr + 1];
/* SOURCE tdtchk_free.for:124 */
/*<       tabtyp=itab(adr+2) >*/
    *tabtyp = itab[*adr + 2];
/* SOURCE tdtchk_free.for:125 */
/*<       hmax=ftab(adr+9) >*/
    *hmax = ftab[*adr + 9];
/* SOURCE tdtchk_free.for:126 */
/*<       if(ztab.gt.0)then >*/
    if (*ztab > 0) {
/* SOURCE tdtchk_free.for:127 */
/*<       calllktstab(ztab,jt,hdatum,ntab,pdv) >*/
	lktstab_(ztab, jt, hdatum, &ntab, &pdv);
/* SOURCE tdtchk_free.for:130 */
/*<       endif >*/
    }
/* SOURCE tdtchk_free.for:131 */
/*<       if(tabtyp.eq.6)then >*/
    if (*tabtyp == 6) {
/* SOURCE tdtchk_free.for:133 */
/*<       calltdlk6(stdout,adr,6,mtab,sjtime,zd,zu,hdatum,q,dqed,dqeu,free) >*/
	tdlk6_(stdout, adr, &feq_gen_c_d_6, &mtab, &julian_1.sjtime, zd, zu, hdatum, &
		q, &dqed, &dqeu, free);
/* SOURCE tdtchk_free.for:136 */
/*<       elseif(tabtyp.eq.13)then >*/
    } else if (*tabtyp == 13) {
/* SOURCE tdtchk_free.for:137 */
/*<        >*/
	tdlk13_(stdout, adr, &feq_gen_c_d_13, &mtab, &julian_1.sjtime, zd, zu, hdatum, 
		&q, &dqed, &dqeu, free);
/* SOURCE tdtchk_free.for:140 */
/*<       else >*/
    } else {
/* SOURCE tdtchk_free.for:141 */
/*<        >*/
	tdlk43_(stdout, adr, &feq_gen_c_d_43, &mtab, &julian_1.sjtime, zd, zu, hdatum, 
		&q, &dqed, &dqeu, free);
/* SOURCE tdtchk_free.for:145 */
/*<       endif >*/
    }
/* SOURCE tdtchk_free.for:147 */
/*<       return >*/
    return 0;
/* SOURCE tdtchk_free.for:148 */
/*<       end >*/
} /* get613_free__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE tdtchk_free.for:152 */
/*<       subroutinetdtchk_free(stdout,exnodt,nex,qchop,emc) >*/
/* Subroutine */ int feq_gen_tdtchk_free_d_(integer *stdout, integer *feq_storage_exnodt, integer *
	nex, real *qchop, integer *feq_storage_emc)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002  Two-D table states for Code 5 Type 6\
:\002,/,\002 Head-  Tail-   Table            Table   Flow    Flow \002,/,\
\002 water  water    id              Type    state   Ratio\002,/,\002 node  \
 node                                          \002,/,\002 -----  -----  ---\
-------------  -----  ------  ------\002)";
    static char fmt_52[] = "(a6,1x,a6,2x,a16,2x,i5,2x,a6,f7.2)";
    static char fmt_56[] = "(\002 *ERR:382* Table state in preceding line is\
 invalid.\002,/,11x,\002Flow exceeds max flow in WSPRO computations by mor\
e\002,\002 than 5 percent.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[16];
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(), 
	    s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();

    /* Local variables */
    integer feq_gen_free_knt_d_, feq_gen_sort_pnt_d_[8400], feq_gen_i_d_;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    extern /* Subroutine */ int feq_gen_get14_free_d_(integer *, integer *, integer *, 
	    real *, real *, doublereal *, real *, integer *, real *, real *, 
	    integer *, integer *, real *, real *);
    char feq_gen_tab_state_d_[6];
    extern /* Subroutine */ int feq_gen_get613_free_d_(integer *, integer *, integer *,
	     real *, real *, doublereal *, real *, integer *, integer *, real 
	    *, integer *);
    integer it;
    real zd;
    doublereal jt;
    real zu, feq_gen_flow_ratio_d_;
    integer dnn, unn;
    real qmx;
    char feq_gen_flag_d_[1];
    integer code;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer free, ioff, tabn;
    real hmax;
    integer ztab, ipnt, hout, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    integer sort[8400];
    char tabid[16];
    integer duadr, udadr;
    real qfree;
    integer npair;
    real qtemp;
    // Owned workspace avoids platform-dependent stack limits.
    std::vector<char> feq_heap_list54(453600);
    char *list54 = feq_heap_list54.data();
    real rover;
    integer sysgn, wspro;
    extern /* Subroutine */ int sort2i_(integer *, integer *, integer *);
    real hdatum;
    integer ientry, tabtyp;
    real qatmax, zdatmax;
    integer feq_gen_out_knt_d_;
    real zuatmax;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__32 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__63 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__64 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Check two-D tables appearing in Code 5 Type 6 to check the */
/*     table state: free or submerged and list a table of these */
/*     states.  Count the number of tables in free state */
/*     and issue a warning message if any are in that state. */

/* SOURCE tdtchk_free.for:162 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE tdtchk_free.for:164 */
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
/* SOURCE tdtchk_free.for:167 */
/*<       integerstdout,nex >*/
/* SOURCE tdtchk_free.for:168 */
/*<       integeremc(mremc),exnodt(9,nex) >*/
/* SOURCE tdtchk_free.for:169 */
/*<       realqchop >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - unit number for standatd output */
/*     EXNODT - exterior node table.  Contains the following items */
/*              for each exterior node. */
/*              Row   Content */
/*               1    sign of the node */
/*               2    pointer into vectors for nodes on a branch */
/*               3    descriptive code: if -1 then a reservoir; */
/*                    if  0 then not on a branch and not a reservoir; */
/*                    if > 0 then a branch number */
/*               4    pointer to a cross section table if on a branch, */
/*                    to storage table if a reservoir, to other node if */
/*                    a dummy branch */
/*               5    gives the variable number(in the system matrix) for */
/*                    the flow at the exterior node. Also a junction */
/*                    pointer in initial processing of input */
/*     NEX    - number of exterior nodes in the model */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE tdtchk_free.for:191 */
/* ********************************************************************** */
/* SOURCE bnrslt.cmn:2 */
/*<       common/bnrslt/tqmax,tqmin,tzmax,qmax,qmin,zmax,vmax >*/
/* SOURCE bnrslt.cmn:5 */
/*<       realqmax(mnbn),qmin(mnbn),zmax(mnbn),vmax(mnbn) >*/
/* SOURCE bnrslt.cmn:7 */
/*<       doubleprecisiontqmax(mnbn),tqmin(mnbn),tzmax(mnbn) >*/
/* ********************************************************************** */
/* INCLUDE tdtchk_free.for:192 */
/* ********************************************************************** */
/* SOURCE enrslt.cmn:3 */
/*<        >*/
/* SOURCE enrslt.cmn:7 */
/*<       integertostore(mnex),flownode(mnex),othernode(mnex) >*/
/* SOURCE enrslt.cmn:9 */
/*<        >*/
/* SOURCE enrslt.cmn:12 */
/*<       doubleprecisionftqmax(mnex),ftqmin(mnex),ftzmax(mnex) >*/
/* ********************************************************************** */
/*     Definition of identifiers */
/*     FTQMAX - time of maximum flow at a free node */
/*     FTQMIM - time of minimum flow at a free node */
/*     FTZMAX - time of maximium elevation at a free node */
/*     FNQMAX - maximum flow at a free node */
/*     FNZMAX - maximum elevation at a free node */
/*     FNQMIN - minimum flow at a free node */
/*     FLOWNODE - flow node number (internal) for flow node */
/*     OTHERNODE- other node number (internal) for the other head node */
/*     TOSTORE - vector of pointers (vector indices) to the location */
/*              where the flow at the flow node and the elevation at */
/*              the other node are stored for a 2-D control structure */
/*              using  a Code 5 Type 6 instruction in */
/*              the Network Matrix Control Input. */
/*              Used to check state of 2-D tables  at the end of a run. */
/*     QSTORE - vector of flows at the flow node for the control structure */
/*               of Code 5 Type 6.  This is the flow at the time the maximun */
/*               elevation occurs at the node in FNZMAX */
/*     ZSTORE- vector of elevation at the other node  at the time of */
/*              maximum elevation at the node in FNZMAX. */
/* INCLUDE tdtchk_free.for:193 */
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
/* INCLUDE tdtchk_free.for:194 */
/*     COMMON BLOCKS FOR THE TRANSLATION FROM INTERNAL NODE AND BRANCH */
/*     NUMBERS TO THEIR USER DESIGINATION.  NEED TWO BLOCKS BECAUSE */
/*     OF FORTRAN RESTRICTIONS ON CHARACTER VARIABLES IN COMMON WITH */
/*     NON-CHARACTER VARIABLES. */
/*     ALSO INCLUDE THE MAPPING VECTOR SO THE OLD STYLE INPUT WILL */
/*     OUTPUT EXTERIOR NODES IN ASCENDING NUMERICAL ORDER. */
/* SOURCE inusnb.cmn:10 */
/*<       integerinbrus(9999),usnsrt(mnex) >*/
/* SOURCE inusnb.cmn:12 */
/*<       character*5inenus(mnex) >*/
/* SOURCE inusnb.cmn:14 */
/*<       common/inbr/inbrus >*/
/* SOURCE inusnb.cmn:16 */
/*<       common/inen/usnsrt >*/
/* SOURCE inusnb.cmn:18 */
/*<       common/inenc/inenus >*/

/* INCLUDE tdtchk_free.for:195 */
/* *********************************************************************** */
/*     COMMON BLOCK FOR PROFILE MATRIX SOLUTION. */
/* SOURCE matcom.cmn:4 */
/*<        >*/
/* SOURCE matcom.cmn:8 */
/*<       common/matcom2/pdavec2,rhs2 >*/
/* SOURCE matcom.cmn:10 */
/*<       integermatblk,numeq,nentry >*/
/* SOURCE matcom.cmn:12 */
/*<        >*/
/* SOURCE matcom.cmn:16 */
/*<       realpdavec(mlpda),rhs(mrmat),hi_iq_ns_fac(mrmat) >*/
/*     Add second set to help in diagnostics-at least as a trial. */
/* SOURCE matcom.cmn:19 */
/*<       realpdavec2(mlpda),rhs2(mrmat) >*/
/* *********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE tdtchk_free.for:198 */
/*<        >*/
/* SOURCE tdtchk_free.for:201 */
/*<        >*/
/*     Note: ZU is maximum elevation at upstream node.  ZDATMAX is */
/*     the elevation at the downstream node at the same time. */
/*     ZD is the maximum elevation at the downstream node. */
/*     ZUATMAX is the elevation at the upstream node at the */
/*     same time. */
/* SOURCE tdtchk_free.for:209 */
/*<       real*8jt >*/
/* SOURCE tdtchk_free.for:211 */
/*<       charactertabid*16,tab_state*6,list54(mnex)*54,flag*1 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE tdtchk_free.for:214 */
/*<       characterget_tabid*16 >*/
/* SOURCE tdtchk_free.for:215 */
/*<       externalget14_free,get613_free,get_tabid >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE tdtchk_free.for:218 */
/*<    50  >*/
/* SOURCE tdtchk_free.for:223 */
/*<    52 format(a6,1x,a6,2x,a16,2x,i5,2x,a6,f7.2) >*/
/* SOURCE tdtchk_free.for:224 */
/*<    56  >*/
/* *********************************************************************** */
/*     Clear the heading flag.  Used to signal that a heading has been */
/*     written.  We only want one heading and we are in a loop searching */
/*     for items that may not appear. */
/* SOURCE tdtchk_free.for:231 */
/*<       hout=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* L50: */
/* L52: */
/* L56: */
    hout = 0;
/*     Clear count of tables in free state */
/* SOURCE tdtchk_free.for:234 */
/*<       free_knt=0 >*/
    feq_gen_free_knt_d_ = 0;
/*     Clear the count of output lines */
/* SOURCE tdtchk_free.for:237 */
/*<       out_knt=0 >*/
    feq_gen_out_knt_d_ = 0;
/*     Start search */
/* SOURCE tdtchk_free.for:240 */
/*<       ientry=0 >*/
    ientry = 0;
/* SOURCE tdtchk_free.for:241 */
/*<       type=6 >*/
    feq_gen_type_d_ = 6;
/* SOURCE tdtchk_free.for:242 */
/*<   100 continue >*/
L100:
/* SOURCE tdtchk_free.for:243 */
/*<       ientry=ientry+1 >*/
    ++ientry;
/* SOURCE tdtchk_free.for:244 */
/*<       ipnt=add(ientry) >*/
    ipnt = matcom_1.add[ientry - 1];
/* SOURCE tdtchk_free.for:245 */
/*<       code=emc(ipnt) >*/
    code = emc[ipnt];
/*        WRITE(STDOUT,*) ' CODE=',CODE */
/* SOURCE tdtchk_free.for:247 */
/*<       if(code.eq.5)then >*/
    if (code == 5) {
/*         CODE = 5.  Check for type. */
/*          WRITE(STDOUT,*) ' CODE=',CODE,' TYPE=',EMC(IPNT+1) */
/* SOURCE tdtchk_free.for:250 */
/*<       if(type.eq.emc(ipnt+1))then >*/
	if (feq_gen_type_d_ == emc[ipnt + 1]) {
/*           Found type 6.  Get the node numbers and the system sign. */
/* SOURCE tdtchk_free.for:252 */
/*<       unn=emc(ipnt+2) >*/
	    unn = emc[ipnt + 2];
/* SOURCE tdtchk_free.for:253 */
/*<       dnn=emc(ipnt+3) >*/
	    dnn = emc[ipnt + 3];
/* SOURCE tdtchk_free.for:254 */
/*<       sysgn=emc(ipnt+5) >*/
	    sysgn = emc[ipnt + 5];
/*            WRITE(STDOUT,*) ' TDTCHK_FREE: UNN=',INENUS(UNN), */
/*     A                      ' DNN=',INENUS(DNN),' SYSGN=',SYSGN */
/*           We need to check both directions because a structure could */
/*           experience large reverse flows in some models.  The flows */
/*           we check here may not be the maximum or minimum flow for */
/*           the structure--they are the flows that were present */
/*           at the time of the maximum head at the node being */
/*           checked. The flows have the proper sign for the */
/*           flow node.  We adjust using SYSGN to get the sign */
/*           that denotes the direction of flow between the ups */
/*           and dns nodes for this structure as given by the user. */
/*           Output the heading if not already done. */
/* SOURCE tdtchk_free.for:269 */
/*<       if(hout.eq.0)then >*/
	    if (hout == 0) {
/* SOURCE tdtchk_free.for:270 */
/*<       write(stdout,50) >*/
		feq_gen_io_d__32.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__32);
		e_wsfe();
/* SOURCE tdtchk_free.for:271 */
/*<       hout=1 >*/
		hout = 1;
/* SOURCE tdtchk_free.for:272 */
/*<       endif >*/
	    }
/*           Check the ups node. */
/* SOURCE tdtchk_free.for:275 */
/*<       it=tostore(unn) >*/
	    it = enrslt_1.tostore[unn - 1];
/*           Get the values for table lookup */
/* SOURCE tdtchk_free.for:277 */
/*<       qatmax=qstore(it) >*/
	    qatmax = enrslt_1.qstore[it - 1];
/* SOURCE tdtchk_free.for:278 */
/*<       if(sysgn.lt.0)then >*/
	    if (sysgn < 0) {
/* SOURCE tdtchk_free.for:279 */
/*<       qatmax=-qatmax >*/
		qatmax = -qatmax;
/* SOURCE tdtchk_free.for:280 */
/*<       endif >*/
	    }
/*            WRITE(STDOUT,*) ' TDTCHK_FREE: Chk ups node: QATMAX=',QATMAX */
/* SOURCE tdtchk_free.for:282 */
/*<       zdatmax=zstore(it) >*/
	    zdatmax = enrslt_1.zstore[it - 1];
/*           Find the max. elev. and its time at the upstream node. */
/* SOURCE tdtchk_free.for:284 */
/*<       it=exnodt(3,unn) >*/
	    it = exnodt[unn * 9 + 3];
/* SOURCE tdtchk_free.for:285 */
/*<       if(it.le.0)then >*/
	    if (it <= 0) {
/* SOURCE tdtchk_free.for:286 */
/*<       jt=ftzmax(unn) >*/
		jt = enrslt_1.ftzmax[unn - 1];
/* SOURCE tdtchk_free.for:287 */
/*<       zu=fnzmax(unn) >*/
		zu = enrslt_1.fnzmax[unn - 1];
/* SOURCE tdtchk_free.for:288 */
/*<       else >*/
	    } else {
/* SOURCE tdtchk_free.for:289 */
/*<       it=exnodt(2,unn) >*/
		it = exnodt[unn * 9 + 2];
/* SOURCE tdtchk_free.for:290 */
/*<       jt=tzmax(it) >*/
		jt = bnrslt_1.tzmax[it - 1];
/* SOURCE tdtchk_free.for:291 */
/*<       zu=zmax(it) >*/
		zu = bnrslt_1.zmax[it - 1];
/* SOURCE tdtchk_free.for:292 */
/*<       endif >*/
	    }
/*            WRITE(STDOUT,*) ' ZU=',ZU,' ZDATMAX=',ZDATMAX */
/*           If the number of flow paths is negative */
/*           then  tables of type 14 are involved. */
/* SOURCE tdtchk_free.for:296 */
/*<       npair=emc(ipnt+6) >*/
	    npair = emc[ipnt + 6];
/* SOURCE tdtchk_free.for:297 */
/*<       if(npair.lt.0)then >*/
	    if (npair < 0) {
/*             Tables are type 14.  At most two tables appear. */
/* SOURCE tdtchk_free.for:299 */
/*<       udadr=emc(ipnt+7) >*/
		udadr = emc[ipnt + 7];
/* SOURCE tdtchk_free.for:300 */
/*<       ztab=emc(ipnt+10) >*/
		ztab = emc[ipnt + 10];
/* SOURCE tdtchk_free.for:301 */
/*<       itmp=emc(ipnt+11) >*/
		ftablea_1.itmp = emc[ipnt + 11];
/* SOURCE tdtchk_free.for:302 */
/*<       hdatum=rtmp >*/
		hdatum = *rtmp;
/* SOURCE tdtchk_free.for:304 */
/*<       if(qatmax.gt.qchop*512.0)then >*/
		if (qatmax > static_cast<double>(*qchop) * (float)512.) {
/*               We have flow from ups node to dns node.  If the flow */
/*               is zero we skip since we are not interested.  If the */
/*               flow is negative we have flow from dns to ups.  This */
/*               means the head water is at the dns node.  The dns node */
/*               is checked below. */
/* SOURCE tdtchk_free.for:312 */
/*<        >*/
		    feq_gen_get14_free_d_(stdout, &udadr, &ztab, &zdatmax, &qatmax, &
			    jt, &hdatum, &tabn, &qmx, &hmax, &free, &wspro, &
			    rover, &qfree);
/* SOURCE tdtchk_free.for:316 */
/*<       if(free.eq.1)then >*/
		    if (free == 1) {
/* SOURCE tdtchk_free.for:317 */
/*<       tab_state=' Free ' >*/
			s_copy(feq_gen_tab_state_d_, const_cast<char*>(" Free "), (ftnlen)6, (ftnlen)6);
/* SOURCE tdtchk_free.for:318 */
/*<       free_knt=free_knt+1 >*/
			++feq_gen_free_knt_d_;
/* SOURCE tdtchk_free.for:319 */
/*<       if(wspro.eq.1)then >*/
			if (wspro == 1) {
/* SOURCE tdtchk_free.for:320 */
/*<       flow_ratio=qatmax/qfree >*/
			    feq_gen_flow_ratio_d_ = static_cast<double>(qatmax) / qfree;
/* SOURCE tdtchk_free.for:321 */
/*<       if(rover.gt.0.05)then >*/
			    if (rover > (float).05) {
/* SOURCE tdtchk_free.for:322 */
/*<       flag='-' >*/
				*(unsigned char *)feq_gen_flag_d_ = '-';
/* SOURCE tdtchk_free.for:324 */
/*<       elseif(rover.gt.0.0)then >*/
			    } else if (rover > (float)0.) {
/* SOURCE tdtchk_free.for:325 */
/*<       flag='*' >*/
				*(unsigned char *)feq_gen_flag_d_ = '*';
/* SOURCE tdtchk_free.for:326 */
/*<       else >*/
			    } else {
/* SOURCE tdtchk_free.for:327 */
/*<       flag=' ' >*/
				*(unsigned char *)feq_gen_flag_d_ = ' ';
/* SOURCE tdtchk_free.for:328 */
/*<       endif >*/
			    }
/* SOURCE tdtchk_free.for:329 */
/*<       endif >*/
			}
/* SOURCE tdtchk_free.for:330 */
/*<       else >*/
		    } else {
/* SOURCE tdtchk_free.for:331 */
/*<       tab_state=' Sub. ' >*/
			s_copy(feq_gen_tab_state_d_, const_cast<char*>(" Sub. "), (ftnlen)6, (ftnlen)6);
/* SOURCE tdtchk_free.for:332 */
/*<       if(wspro.eq.1)then >*/
			if (wspro == 1) {
/* SOURCE tdtchk_free.for:333 */
/*<       flow_ratio=qatmax/qfree >*/
			    feq_gen_flow_ratio_d_ = static_cast<double>(qatmax) / qfree;
/* SOURCE tdtchk_free.for:334 */
/*<       flag='+' >*/
			    *(unsigned char *)feq_gen_flag_d_ = '+';
/* SOURCE tdtchk_free.for:335 */
/*<       else >*/
			} else {
/* SOURCE tdtchk_free.for:336 */
/*<       flag=' ' >*/
			    *(unsigned char *)feq_gen_flag_d_ = ' ';
/* SOURCE tdtchk_free.for:337 */
/*<       endif >*/
			}
/* SOURCE tdtchk_free.for:338 */
/*<       endif >*/
		    }
/* SOURCE tdtchk_free.for:339 */
/*<       tabid=get_tabid(tabn) >*/
		    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &tabn);
		    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/*                WRITE(TABID,'(I6,10X)') TABN */
/* SOURCE tdtchk_free.for:342 */
/*<       out_knt=out_knt+1 >*/
		    ++feq_gen_out_knt_d_;
/* SOURCE tdtchk_free.for:343 */
/*<       sort(out_knt)=tabn >*/
		    sort[feq_gen_out_knt_d_ - 1] = tabn;
/* SOURCE tdtchk_free.for:344 */
/*<       sort_pnt(out_knt)=out_knt >*/
		    feq_gen_sort_pnt_d_[feq_gen_out_knt_d_ - 1] = feq_gen_out_knt_d_;
/* SOURCE tdtchk_free.for:345 */
/*<       if(wspro.eq.1)then >*/
		    if (wspro == 1) {
/* SOURCE tdtchk_free.for:346 */
/*<        >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 54;
			feq_gen_ici_d_1.iciunit = list54 + (feq_gen_out_knt_d_ - 1) * 54;
			feq_gen_ici_d_1.icifmt = fmt_52;
			s_wsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, inenc_1.inenus + (unn - 1) * 5, (ftnlen)
				5);
			do_fio(&feq_gen_c_d_1, inenc_1.inenus + (dnn - 1) * 5, (ftnlen)
				5);
			do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_14, (ftnlen)sizeof(integer))
				;
			do_fio(&feq_gen_c_d_1, feq_gen_tab_state_d_, (ftnlen)6);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_flow_ratio_d_, (ftnlen)sizeof(
				real));
			e_wsfi();
/* SOURCE tdtchk_free.for:349 */
/*<       list54(out_knt)(54:54)=flag >*/
			*(unsigned char *)&list54[(feq_gen_out_knt_d_ - 1) * 54 + 53] =
				 *(unsigned char *)feq_gen_flag_d_;
/* SOURCE tdtchk_free.for:350 */
/*<       else >*/
		    } else {
/* SOURCE tdtchk_free.for:351 */
/*<        >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 54;
			feq_gen_ici_d_1.iciunit = list54 + (feq_gen_out_knt_d_ - 1) * 54;
			feq_gen_ici_d_1.icifmt = fmt_52;
			s_wsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, inenc_1.inenus + (unn - 1) * 5, (ftnlen)
				5);
			do_fio(&feq_gen_c_d_1, inenc_1.inenus + (dnn - 1) * 5, (ftnlen)
				5);
			do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_14, (ftnlen)sizeof(integer))
				;
			do_fio(&feq_gen_c_d_1, feq_gen_tab_state_d_, (ftnlen)6);
			e_wsfi();
/* SOURCE tdtchk_free.for:353 */
/*<       endif >*/
		    }
/* SOURCE tdtchk_free.for:355 */
/*<       endif >*/
		}
/* SOURCE tdtchk_free.for:356 */
/*<       else >*/
	    } else {
/* SOURCE tdtchk_free.for:358 */
/*<       if(zu.ge.zdatmax)then >*/
		if (zu >= zdatmax) {
/*               Tables of type 6 or 13 may appear and there may be */
/*               multiple pairs. */
/* SOURCE tdtchk_free.for:361 */
/*<       ioff=0 >*/
		    ioff = 0;
/* SOURCE tdtchk_free.for:362 */
/*<       do200i=1,npair >*/
		    feq_gen_i_d_1 = npair;
		    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE tdtchk_free.for:363 */
/*<       udadr=emc(ipnt+ioff+7) >*/
			udadr = emc[ipnt + ioff + 7];
/* SOURCE tdtchk_free.for:364 */
/*<       ztab=emc(ipnt+ioff+10) >*/
			ztab = emc[ipnt + ioff + 10];
/* SOURCE tdtchk_free.for:366 */
/*<       itmp=emc(ipnt+ioff+11) >*/
			ftablea_1.itmp = emc[ipnt + ioff + 11];
/* SOURCE tdtchk_free.for:367 */
/*<       hdatum=rtmp >*/
			hdatum = *rtmp;
/* SOURCE tdtchk_free.for:368 */
/*<       if(qatmax.gt.0.0)then >*/
			if (qatmax > (float)0.) {
/*                   Flow was from ups to dns. */
/* SOURCE tdtchk_free.for:370 */
/*<        >*/
			    feq_gen_get613_free_d_(stdout, &udadr, &ztab, &zu, &
				    zdatmax, &jt, &hdatum, &tabn, &tabtyp, &
				    hmax, &free);
/* SOURCE tdtchk_free.for:376 */
/*<       if(free.eq.1)then >*/
			    if (free == 1) {
/* SOURCE tdtchk_free.for:377 */
/*<       tab_state=' Free ' >*/
				s_copy(feq_gen_tab_state_d_, const_cast<char*>(" Free "), (ftnlen)6, (
					ftnlen)6);
/* SOURCE tdtchk_free.for:378 */
/*<       free_knt=free_knt+1 >*/
				++feq_gen_free_knt_d_;
/* SOURCE tdtchk_free.for:379 */
/*<       else >*/
			    } else {
/* SOURCE tdtchk_free.for:380 */
/*<       tab_state=' Sub. ' >*/
				s_copy(feq_gen_tab_state_d_, const_cast<char*>(" Sub. "), (ftnlen)6, (
					ftnlen)6);
/* SOURCE tdtchk_free.for:381 */
/*<       endif >*/
			    }
/* SOURCE tdtchk_free.for:382 */
/*<       tabid=get_tabid(tabn) >*/
			    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &tabn);
			    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/*                    WRITE(TABID,'(I6,10X)') TABN */
/* SOURCE tdtchk_free.for:385 */
/*<       out_knt=out_knt+1 >*/
			    ++feq_gen_out_knt_d_;
/* SOURCE tdtchk_free.for:386 */
/*<       sort(out_knt)=tabn >*/
			    sort[feq_gen_out_knt_d_ - 1] = tabn;
/* SOURCE tdtchk_free.for:387 */
/*<       sort_pnt(out_knt)=out_knt >*/
			    feq_gen_sort_pnt_d_[feq_gen_out_knt_d_ - 1] = feq_gen_out_knt_d_;
/* SOURCE tdtchk_free.for:388 */
/*<        >*/
			    feq_gen_ici_d_1.icierr = 0;
			    feq_gen_ici_d_1.icirnum = 1;
			    feq_gen_ici_d_1.icirlen = 54;
			    feq_gen_ici_d_1.iciunit = list54 + (feq_gen_out_knt_d_ - 1) * 54;
			    feq_gen_ici_d_1.icifmt = fmt_52;
			    s_wsfi(&feq_gen_ici_d_1);
			    do_fio(&feq_gen_c_d_1, inenc_1.inenus + (unn - 1) * 5, (
				    ftnlen)5);
			    do_fio(&feq_gen_c_d_1, inenc_1.inenus + (dnn - 1) * 5, (
				    ftnlen)5);
			    do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
			    do_fio(&feq_gen_c_d_1, (char *)&tabtyp, (ftnlen)sizeof(
				    integer));
			    do_fio(&feq_gen_c_d_1, feq_gen_tab_state_d_, (ftnlen)6);
			    e_wsfi();
/* SOURCE tdtchk_free.for:391 */
/*<       endif >*/
			}
/* SOURCE tdtchk_free.for:392 */
/*<       ioff=ioff+cd5ty6 >*/
			ioff += 8;
/* SOURCE tdtchk_free.for:393 */
/*<   200 continue >*/
/* L200: */
		    }
/* SOURCE tdtchk_free.for:394 */
/*<       endif >*/
		}
/* SOURCE tdtchk_free.for:395 */
/*<       endif >*/
	    }
/*           Check the dns node. */
/* SOURCE tdtchk_free.for:398 */
/*<       it=tostore(dnn) >*/
	    it = enrslt_1.tostore[dnn - 1];
/*           Get the values for table lookup */
/* SOURCE tdtchk_free.for:400 */
/*<       qatmax=qstore(it) >*/
	    qatmax = enrslt_1.qstore[it - 1];
/* SOURCE tdtchk_free.for:401 */
/*<       if(sysgn.lt.0)then >*/
	    if (sysgn < 0) {
/* SOURCE tdtchk_free.for:402 */
/*<       qatmax=-qatmax >*/
		qatmax = -qatmax;
/* SOURCE tdtchk_free.for:403 */
/*<       endif >*/
	    }
/*            WRITE(STDOUT,*) ' TDTCHK_FREE: Chk dns node: QATMAX=',QATMAX */
/* SOURCE tdtchk_free.for:405 */
/*<       zuatmax=zstore(it) >*/
	    zuatmax = enrslt_1.zstore[it - 1];
/*           Find the max. elev. and its time at the down stream node. */
/* SOURCE tdtchk_free.for:407 */
/*<       it=exnodt(3,dnn) >*/
	    it = exnodt[dnn * 9 + 3];
/* SOURCE tdtchk_free.for:408 */
/*<       if(it.le.0)then >*/
	    if (it <= 0) {
/* SOURCE tdtchk_free.for:409 */
/*<       jt=ftzmax(dnn) >*/
		jt = enrslt_1.ftzmax[dnn - 1];
/* SOURCE tdtchk_free.for:410 */
/*<       zd=fnzmax(dnn) >*/
		zd = enrslt_1.fnzmax[dnn - 1];
/* SOURCE tdtchk_free.for:411 */
/*<       else >*/
	    } else {
/* SOURCE tdtchk_free.for:412 */
/*<       it=exnodt(2,dnn) >*/
		it = exnodt[dnn * 9 + 2];
/* SOURCE tdtchk_free.for:413 */
/*<       jt=tzmax(it) >*/
		jt = bnrslt_1.tzmax[it - 1];
/* SOURCE tdtchk_free.for:414 */
/*<       zd=zmax(it) >*/
		zd = bnrslt_1.zmax[it - 1];
/* SOURCE tdtchk_free.for:415 */
/*<       endif >*/
	    }
/*            WRITE(STDOUT,*) ' ZD=',ZD,' ZUATMAX=',ZUATMAX */
/*           If the number of flow paths is negative */
/*           then  tables of type 14 are involved. */
/* SOURCE tdtchk_free.for:420 */
/*<       npair=emc(ipnt+6) >*/
	    npair = emc[ipnt + 6];
/* SOURCE tdtchk_free.for:421 */
/*<       if(npair.lt.0)then >*/
	    if (npair < 0) {
/*             Tables are type 14.  At most two tables appear. */
/* SOURCE tdtchk_free.for:423 */
/*<       duadr=emc(ipnt+8) >*/
		duadr = emc[ipnt + 8];
/* SOURCE tdtchk_free.for:424 */
/*<       ztab=emc(ipnt+10) >*/
		ztab = emc[ipnt + 10];
/* SOURCE tdtchk_free.for:425 */
/*<       itmp=emc(ipnt+11) >*/
		ftablea_1.itmp = emc[ipnt + 11];
/* SOURCE tdtchk_free.for:426 */
/*<       hdatum=rtmp >*/
		hdatum = *rtmp;
/* SOURCE tdtchk_free.for:428 */
/*<       if(qatmax.lt.-qchop*512.0)then >*/
		if (qatmax < static_cast<double>(-(*qchop)) * (float)512.) {
/*               We have flow from dns node to ups node.  If the flow */
/*               is zero we skip since we are not interested.  If the */
/*               flow is negative we have flow from dns to ups. */
/* SOURCE tdtchk_free.for:433 */
/*<       qtemp=abs(qatmax) >*/
		    qtemp = dabs(qatmax);
/* SOURCE tdtchk_free.for:434 */
/*<        >*/
		    feq_gen_get14_free_d_(stdout, &duadr, &ztab, &zuatmax, &qtemp, &jt,
			     &hdatum, &tabn, &qmx, &hmax, &free, &wspro, &
			    rover, &qfree);
/* SOURCE tdtchk_free.for:439 */
/*<       flow_ratio=abs(qatmax)/qfree >*/
		    feq_gen_flow_ratio_d_ = dabs(qatmax) / qfree;
/* SOURCE tdtchk_free.for:440 */
/*<       if(free.eq.1)then >*/
		    if (free == 1) {
/* SOURCE tdtchk_free.for:441 */
/*<       free_knt=free_knt+1 >*/
			++feq_gen_free_knt_d_;
/* SOURCE tdtchk_free.for:442 */
/*<       tab_state=' Free ' >*/
			s_copy(feq_gen_tab_state_d_, const_cast<char*>(" Free "), (ftnlen)6, (ftnlen)6);
/* SOURCE tdtchk_free.for:443 */
/*<       if(wspro.eq.1)then >*/
			if (wspro == 1) {
/* SOURCE tdtchk_free.for:444 */
/*<       if(rover.gt.0.05)then >*/
			    if (rover > (float).05) {
/* SOURCE tdtchk_free.for:445 */
/*<       flag='-' >*/
				*(unsigned char *)feq_gen_flag_d_ = '-';
/* SOURCE tdtchk_free.for:446 */
/*<       elseif(rover.gt.0.0)then >*/
			    } else if (rover > (float)0.) {
/* SOURCE tdtchk_free.for:447 */
/*<       flag='*' >*/
				*(unsigned char *)feq_gen_flag_d_ = '*';
/* SOURCE tdtchk_free.for:448 */
/*<       else >*/
			    } else {
/* SOURCE tdtchk_free.for:449 */
/*<       flag=' ' >*/
				*(unsigned char *)feq_gen_flag_d_ = ' ';
/* SOURCE tdtchk_free.for:450 */
/*<       endif >*/
			    }
/* SOURCE tdtchk_free.for:451 */
/*<       endif >*/
			}
/* SOURCE tdtchk_free.for:452 */
/*<       else >*/
		    } else {
/* SOURCE tdtchk_free.for:453 */
/*<       tab_state=' Sub. ' >*/
			s_copy(feq_gen_tab_state_d_, const_cast<char*>(" Sub. "), (ftnlen)6, (ftnlen)6);
/* SOURCE tdtchk_free.for:454 */
/*<       if(wspro.eq.1)then >*/
			if (wspro == 1) {
/* SOURCE tdtchk_free.for:455 */
/*<       flag='+' >*/
			    *(unsigned char *)feq_gen_flag_d_ = '+';
/* SOURCE tdtchk_free.for:456 */
/*<       else >*/
			} else {
/* SOURCE tdtchk_free.for:457 */
/*<       flag=' ' >*/
			    *(unsigned char *)feq_gen_flag_d_ = ' ';
/* SOURCE tdtchk_free.for:458 */
/*<       endif >*/
			}
/* SOURCE tdtchk_free.for:459 */
/*<       endif >*/
		    }
/* SOURCE tdtchk_free.for:460 */
/*<       tabid=get_tabid(tabn) >*/
		    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &tabn);
		    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/*                WRITE(TABID,'(I6,10X)') TABN */
/* SOURCE tdtchk_free.for:463 */
/*<       out_knt=out_knt+1 >*/
		    ++feq_gen_out_knt_d_;
/* SOURCE tdtchk_free.for:464 */
/*<       sort(out_knt)=tabn >*/
		    sort[feq_gen_out_knt_d_ - 1] = tabn;
/* SOURCE tdtchk_free.for:465 */
/*<       sort_pnt(out_knt)=out_knt >*/
		    feq_gen_sort_pnt_d_[feq_gen_out_knt_d_ - 1] = feq_gen_out_knt_d_;
/* SOURCE tdtchk_free.for:466 */
/*<        >*/
		    feq_gen_ici_d_1.icierr = 0;
		    feq_gen_ici_d_1.icirnum = 1;
		    feq_gen_ici_d_1.icirlen = 54;
		    feq_gen_ici_d_1.iciunit = list54 + (feq_gen_out_knt_d_ - 1) * 54;
		    feq_gen_ici_d_1.icifmt = fmt_52;
		    s_wsfi(&feq_gen_ici_d_1);
		    do_fio(&feq_gen_c_d_1, inenc_1.inenus + (dnn - 1) * 5, (ftnlen)5);
		    do_fio(&feq_gen_c_d_1, inenc_1.inenus + (unn - 1) * 5, (ftnlen)5);
		    do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_14, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, feq_gen_tab_state_d_, (ftnlen)6);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_flow_ratio_d_, (ftnlen)sizeof(real))
			    ;
		    e_wsfi();
/* SOURCE tdtchk_free.for:469 */
/*<       list54(out_knt)(54:54)=flag >*/
		    *(unsigned char *)&list54[(feq_gen_out_knt_d_ - 1) * 54 + 53] = *(
			    unsigned char *)feq_gen_flag_d_;
/* SOURCE tdtchk_free.for:470 */
/*<       endif >*/
		}
/* SOURCE tdtchk_free.for:471 */
/*<       else >*/
	    } else {
/* SOURCE tdtchk_free.for:473 */
/*<       if(zd.ge.zuatmax)then >*/
		if (zd >= zuatmax) {
/*               Tables of type 6 or 13 may appear and there may be multiple pairs. */
/* SOURCE tdtchk_free.for:475 */
/*<       ioff=0 >*/
		    ioff = 0;
/* SOURCE tdtchk_free.for:476 */
/*<       do210i=1,npair >*/
		    feq_gen_i_d_1 = npair;
		    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE tdtchk_free.for:477 */
/*<       duadr=emc(ipnt+ioff+8) >*/
			duadr = emc[ipnt + ioff + 8];
/* SOURCE tdtchk_free.for:478 */
/*<       ztab=emc(ipnt+ioff+10) >*/
			ztab = emc[ipnt + ioff + 10];
/* SOURCE tdtchk_free.for:480 */
/*<       itmp=emc(ipnt+ioff+11) >*/
			ftablea_1.itmp = emc[ipnt + ioff + 11];
/* SOURCE tdtchk_free.for:481 */
/*<       hdatum=rtmp >*/
			hdatum = *rtmp;
/* SOURCE tdtchk_free.for:482 */
/*<       if(qatmax.lt.0.0)then >*/
			if (qatmax < (float)0.) {
/*                   Flow was from dns to ups. */
/* SOURCE tdtchk_free.for:484 */
/*<        >*/
			    feq_gen_get613_free_d_(stdout, &duadr, &ztab, &zd, &
				    zuatmax, &jt, &hdatum, &tabn, &tabtyp, &
				    hmax, &free);
/* SOURCE tdtchk_free.for:489 */
/*<       if(free.eq.1)then >*/
			    if (free == 1) {
/* SOURCE tdtchk_free.for:490 */
/*<       tab_state=' Free ' >*/
				s_copy(feq_gen_tab_state_d_, const_cast<char*>(" Free "), (ftnlen)6, (
					ftnlen)6);
/* SOURCE tdtchk_free.for:491 */
/*<       free_knt=free_knt+1 >*/
				++feq_gen_free_knt_d_;
/* SOURCE tdtchk_free.for:492 */
/*<       else >*/
			    } else {
/* SOURCE tdtchk_free.for:493 */
/*<       tab_state=' Sub. ' >*/
				s_copy(feq_gen_tab_state_d_, const_cast<char*>(" Sub. "), (ftnlen)6, (
					ftnlen)6);
/* SOURCE tdtchk_free.for:494 */
/*<       endif >*/
			    }
/* SOURCE tdtchk_free.for:495 */
/*<       tabid=get_tabid(tabn) >*/
			    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &tabn);
			    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/*                    WRITE(TABID,'(I6,10X)') TABN */
/* SOURCE tdtchk_free.for:498 */
/*<       out_knt=out_knt+1 >*/
			    ++feq_gen_out_knt_d_;
/* SOURCE tdtchk_free.for:499 */
/*<       sort(out_knt)=tabn >*/
			    sort[feq_gen_out_knt_d_ - 1] = tabn;
/* SOURCE tdtchk_free.for:500 */
/*<       sort_pnt(out_knt)=out_knt >*/
			    feq_gen_sort_pnt_d_[feq_gen_out_knt_d_ - 1] = feq_gen_out_knt_d_;
/* SOURCE tdtchk_free.for:501 */
/*<        >*/
			    feq_gen_ici_d_1.icierr = 0;
			    feq_gen_ici_d_1.icirnum = 1;
			    feq_gen_ici_d_1.icirlen = 54;
			    feq_gen_ici_d_1.iciunit = list54 + (feq_gen_out_knt_d_ - 1) * 54;
			    feq_gen_ici_d_1.icifmt = fmt_52;
			    s_wsfi(&feq_gen_ici_d_1);
			    do_fio(&feq_gen_c_d_1, inenc_1.inenus + (dnn - 1) * 5, (
				    ftnlen)5);
			    do_fio(&feq_gen_c_d_1, inenc_1.inenus + (unn - 1) * 5, (
				    ftnlen)5);
			    do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
			    do_fio(&feq_gen_c_d_1, (char *)&tabtyp, (ftnlen)sizeof(
				    integer));
			    do_fio(&feq_gen_c_d_1, feq_gen_tab_state_d_, (ftnlen)6);
			    e_wsfi();
/* SOURCE tdtchk_free.for:503 */
/*<       endif >*/
			}
/* SOURCE tdtchk_free.for:504 */
/*<       ioff=ioff+cd5ty6 >*/
			ioff += 8;
/* SOURCE tdtchk_free.for:505 */
/*<   210 continue >*/
/* L210: */
		    }
/* SOURCE tdtchk_free.for:506 */
/*<       endif >*/
		}
/* SOURCE tdtchk_free.for:507 */
/*<       endif >*/
	    }
/* SOURCE tdtchk_free.for:509 */
/*<       endif >*/
	}
/* SOURCE tdtchk_free.for:510 */
/*<       endif >*/
    }
/* SOURCE tdtchk_free.for:511 */
/*<       if(code.gt.0)then >*/
    if (code > 0) {
/*         Continue the search. */
/* SOURCE tdtchk_free.for:513 */
/*<       goto100 >*/
	goto L100;
/* SOURCE tdtchk_free.for:514 */
/*<       endif >*/
    }
/*     Sort on table number. */
/* SOURCE tdtchk_free.for:517 */
/*<       callsort2i(out_knt,sort,sort_pnt) >*/
    sort2i_(&feq_gen_out_knt_d_, sort, feq_gen_sort_pnt_d_);
/*     Output the lines. */
/* SOURCE tdtchk_free.for:521 */
/*<       do300i=1,out_knt >*/
    feq_gen_i_d_1 = feq_gen_out_knt_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE tdtchk_free.for:522 */
/*<       write(stdout,'(A54)')list54(sort_pnt(i)) >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(A54)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, list54 + (feq_gen_sort_pnt_d_[feq_gen_i_d_ - 1] - 1) * 54, (ftnlen)54);
	e_wsfe();
/* SOURCE tdtchk_free.for:523 */
/*<       if(list54(sort_pnt(i))(54:54).eq.'-')then >*/
	if (*(unsigned char *)&list54[(feq_gen_sort_pnt_d_[feq_gen_i_d_ - 1] - 1) * 54 + 53] == 
		'-') {
/* SOURCE tdtchk_free.for:524 */
/*<       write(stdout,56) >*/
	    feq_gen_io_d__63.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__63);
	    e_wsfe();
/* SOURCE tdtchk_free.for:525 */
/*<       write(stdout,*)' ' >*/
	    feq_gen_io_d__64.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__64);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	    e_wsle();
/* SOURCE tdtchk_free.for:526 */
/*<       endif >*/
	}
/* SOURCE tdtchk_free.for:527 */
/*<   300 continue >*/
/* L300: */
    }
/* SOURCE tdtchk_free.for:529 */
/*<       return >*/
    return 0;
/* SOURCE tdtchk_free.for:530 */
/*<       end >*/
} /* tdtchk_free__ */

#undef rtmp
#undef itab
#undef ftab


#ifdef __cplusplus
	}
#endif
