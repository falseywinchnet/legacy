/* runinit.f -- translated by f2c (version 20240504).
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

/* COMMON bnelem_ is declared in common.hpp. */

#define bnelem_1 bnelem_

/* COMMON bnothr_ is declared in common.hpp. */

#define bnothr_1 bnothr_

/* COMMON bnothc_ is declared in common.hpp. */

#define bnothc_1 bnothc_

/* COMMON enelem_ is declared in common.hpp. */

#define enelem_1 enelem_

/* COMMON tsfcom_ is declared in common.hpp. */

#define tsfcom_1 tsfcom_

/* COMMON julian_ is declared in common.hpp. */

#define julian_1 julian_

/* COMMON difcom_ is declared in common.hpp. */

#define difcom_1 difcom_

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* COMMON dssdif_ is declared in common.hpp. */

#define dssdif_1 dssdif_

/* COMMON dssdifc_ is declared in common.hpp. */

#define dssdifc_1 dssdifc_

/* COMMON bnpond_ is declared in common.hpp. */

#define bnpond_1 bnpond_

/* COMMON tamcom_ is declared in common.hpp. */

#define tamcom_1 tamcom_

/* COMMON miscon_ is declared in common.hpp. */

#define miscon_1 miscon_

/* COMMON rdcom_ is declared in common.hpp. */

#define rdcom_1 rdcom_

/* COMMON rdcomc_ is declared in common.hpp. */

#define rdcomc_1 rdcomc_

/* COMMON ts_mngt_n__ is declared in common.hpp. */

#define feq_gen_ts_mngt_n_d_1 feq_gen_ts_mngt_n_d_

/* COMMON ts_mngt_c__ is declared in common.hpp. */

#define feq_gen_ts_mngt_c_d_1 feq_gen_ts_mngt_c_d_

/* COMMON endrun_ is declared in common.hpp. */

#define endrun_1 endrun_

/* COMMON xscom_ is declared in common.hpp. */

#define xscom_1 xscom_

/* COMMON namcom_ is declared in common.hpp. */

#define namcom_1 namcom_

/* COMMON enothr_ is declared in common.hpp. */

#define enothr_1 enothr_

/* COMMON enothc_ is declared in common.hpp. */

#define enothc_1 enothc_

/* COMMON wrcom_ is declared in common.hpp. */

#define wrcom_1 wrcom_

/* COMMON wrcomc_ is declared in common.hpp. */

#define wrcomc_1 wrcomc_

/* COMMON wrcomd_ is declared in common.hpp. */

#define wrcomd_1 wrcomd_

/* COMMON offcom_ is declared in common.hpp. */

#define offcom_1 offcom_

/* COMMON datetime_ is declared in common.hpp. */

#define datetime_1 datetime_

/* COMMON svncom_ is declared in common.hpp. */

#define svncom_1 svncom_

/* COMMON svncomc_ is declared in common.hpp. */

#define svncomc_1 svncomc_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_6 = 6;
static integer feq_gen_c_d_0 = 0;
static integer feq_gen_c_d_14 = 14;
static integer feq_gen_c_d_2 = 2;
static integer feq_gen_c_d_100 = 100;
static integer feq_gen_c_d_10002 = 10002;
static integer feq_gen_c_d_128 = 128;
static integer feq_gen_c_d_3 = 3;
static integer feq_gen_c_d_30 = 30;

/* Routines used in initialization of the run */



/* SOURCE runinit.for:6 */
/*<       subroutineset_initial_oper_blk(nblk,opblk,jtime,ept,emc) >*/
/* Subroutine */ int feq_gen_set_initial_oper_blk_d_(integer *nblk, integer *feq_storage_opblk, 
	doublereal *jtime, integer *ept, integer *feq_storage_emc)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_blk_adrs_d_, feq_gen_i_d_, feq_gen_table_adrs_d_;
    real val, pdv;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ntab;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    integer feq_gen_ts_blk_number_d_, feq_gen_emc_pnt_d_;
    extern /* Subroutine */ int lktstab_(integer *, doublereal *, real *, 
	    integer *, real *);

/*     Set the initial block value for control structures */
/*     that use more than one operation block */
/* SOURCE runinit.for:12 */
/*<       implicitnone >*/
/* INCLUDE runinit.for:13 */
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
/* SOURCE runinit.for:15 */
/*<       integerept,nblk,opblk(nblk),emc(ept) >*/
/* SOURCE runinit.for:17 */
/*<       real*8jtime >*/
/* INCLUDE runinit.for:19 */
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
/*     Local */
/* SOURCE runinit.for:23 */
/*<       integeri,blk_adrs,emc_pnt,table_adrs,ntab,ts_blk_number >*/
/* SOURCE runinit.for:26 */
/*<       realval,pdv >*/
/*     Called subprograms */
/* SOURCE runinit.for:29 */
/*<       externallktab >*/
/* *********************************************************************** */
/* SOURCE runinit.for:32 */
/*<       do100i=1,nblk >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> opblk(feq_storage_opblk, 1);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
    feq_gen_i_d_1 = *nblk;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:33 */
/*<       blk_adrs=opblk(i) >*/
	feq_gen_blk_adrs_d_ = opblk[feq_gen_i_d_];
/* SOURCE runinit.for:34 */
/*<       table_adrs=itab(blk_adrs+7) >*/
	feq_gen_table_adrs_d_ = itab[feq_gen_blk_adrs_d_ + 7];
/* SOURCE runinit.for:35 */
/*<       if(table_adrs.gt.0)then >*/
	if (feq_gen_table_adrs_d_ > 0) {
/*         Find the block number at this time from the table. */
/* SOURCE runinit.for:38 */
/*<       calllktstab(table_adrs,jtime,val,ntab,pdv) >*/
	    lktstab_(&feq_gen_table_adrs_d_, jtime, &val, &ntab, &pdv);
/* SOURCE runinit.for:41 */
/*<       ts_blk_number=int(val+0.5) >*/
	    feq_gen_ts_blk_number_d_ = (integer) (static_cast<double>(val) + (float).5);
/* SOURCE runinit.for:42 */
/*<       if(ts_blk_number.eq.i)then >*/
	    if (feq_gen_ts_blk_number_d_ == feq_gen_i_d_) {
/*           We have a match.  Set the block number into */
/*           EMC to signal which block is currently active. */
/*           Get the pointer into EMC */
/* SOURCE runinit.for:46 */
/*<       emc_pnt=itab(blk_adrs+8) >*/
		feq_gen_emc_pnt_d_ = itab[feq_gen_blk_adrs_d_ + 8];
/* SOURCE runinit.for:48 */
/*<       emc(emc_pnt)=i >*/
		emc[feq_gen_emc_pnt_d_] = feq_gen_i_d_;
/* SOURCE runinit.for:49 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:50 */
/*<       endif >*/
	}
/* SOURCE runinit.for:51 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE runinit.for:52 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:53 */
/*<       end >*/
} /* set_initial_oper_blk__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE runinit.for:57 */
/*<       subroutineadj234(adrs,zbot,flag) >*/
/* Subroutine */ int adj234_(integer *adrs, real *zbot, integer *feq_gen_flag_d_)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Local variables */
    integer feq_gen_i_d_, fa, la, off;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern integer gettyp_(integer *);

/*     + + + PURPOSE + + + */
/*     Adjust the arguments to tables of types 2, 3, or 4 such that */
/*     they are maximum depth, relative to the first argument in the */
/*     table on entry.  Return the first argument in ZBOT and set */
/*     FLAG to 1 if an adjustment is allowed. */
/* SOURCE runinit.for:67 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE runinit.for:69 */
/*<       integeradrs,flag >*/
/* SOURCE runinit.for:70 */
/*<       realzbot >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADRS   - address of the function table in FTAB/ITAB */
/*     ZBOT   - bottom elevation */
/*     FLAG   - flag for adjustment */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE runinit.for:78 */
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
/* INCLUDE runinit.for:79 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE runinit.for:82 */
/*<       integerfa,i,la,off,type >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE runinit.for:85 */
/*<       integergettyp >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE runinit.for:88 */
/*<       externalgettyp >*/
/* *********************************************************************** */
/*     Get the first argument in the table.  If it is 0.0 then no */
/*     adjustment is made.  Otherwise, FEQ assumes that an adjustment */
/*     is to be made to the argument sequence. */
/* SOURCE runinit.for:93 */
/*<       zbot=ftab(adrs+off234) >*/
    *zbot = ftab[*adrs + 22];
/* SOURCE runinit.for:94 */
/*<       if(zbot.eq.0.0)then >*/
    if (*zbot == (float)0.) {
/* SOURCE runinit.for:95 */
/*<       flag=0 >*/
	*feq_gen_flag_d_ = 0;
/* SOURCE runinit.for:96 */
/*<       else >*/
    } else {
/* SOURCE runinit.for:97 */
/*<       flag=1 >*/
	*feq_gen_flag_d_ = 1;
/*       Make the adjustment.  Get the type. */
/* SOURCE runinit.for:99 */
/*<       type=gettyp(adrs) >*/
	feq_gen_type_d_ = gettyp_(adrs);
/* SOURCE runinit.for:100 */
/*<       if(type.eq.2)then >*/
	if (feq_gen_type_d_ == 2) {
/* SOURCE runinit.for:101 */
/*<       off=2 >*/
	    off = 2;
/* SOURCE runinit.for:102 */
/*<       else >*/
	} else {
/* SOURCE runinit.for:103 */
/*<       off=3 >*/
	    off = 3;
/* SOURCE runinit.for:104 */
/*<       endif >*/
	}
/* SOURCE runinit.for:105 */
/*<       fa=adrs+off234 >*/
	fa = *adrs + 22;
/* SOURCE runinit.for:106 */
/*<       la=itab(adrs) >*/
	la = itab[*adrs];
/* SOURCE runinit.for:107 */
/*<       do100i=fa,la,off >*/
	feq_gen_i_d_1 = la;
	feq_gen_i_d_2 = off;
	for (feq_gen_i_d_ = fa; feq_gen_i_d_2 < 0 ? feq_gen_i_d_ >= feq_gen_i_d_1 : feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += feq_gen_i_d_2) {
/* SOURCE runinit.for:108 */
/*<       ftab(i)=ftab(i)-zbot >*/
	    ftab[feq_gen_i_d_] -= *zbot;
/* SOURCE runinit.for:109 */
/*<   100 continue >*/
/* L100: */
	}
/* SOURCE runinit.for:110 */
/*<       endif >*/
    }
/* SOURCE runinit.for:111 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:112 */
/*<       end >*/
} /* adj234_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE runinit.for:116 */
/*<        >*/
/* Subroutine */ int bckwtr_(real *epsb, real *grav, integer *in, integer *
	stdout, integer *maxit, integer *nbra, integer *nbn, integer *nex, 
	integer *output, doublereal *jtime, real *sfac, integer *feq_storage_brpt, 
	integer *feq_storage_emc, real *qeps, integer *ept, real *feq_gen_dz_for_output_d_, 
	integer *feq_storage_exnodt, integer *eflag)
{
    /* Format strings */
    static char fmt_1010[] = "(14x,i5)";
    static char fmt_1060[] = "(a5,a5,f10.0,a5)";
    static char fmt_1070[] = "(10x,f10.0)";
    static char fmt_2000[] = "(\002 \002,a80)";
    static char fmt_2001[] = "(/,\002 \002,a80)";
    static char fmt_2010[] = "(/,\002 BRANCH NUMBER = \002,i5)";
    static char fmt_2110[] = "(/,\002 *ERR:94* Downstream depth missing\
 \002,\002for branch\002,i5)";
    static char fmt_2120[] = "(1x,a5,a5,f10.2,a5)";
    static char fmt_2160[] = "(/,\002 *ERR:96* Fatal errors encountered.\002)"
	    ;
    static char fmt_2170[] = "(/,\002 Backwater analysis for branch#\002,i5,\
/,1x,\002 STATION\002,1x,\002IT\002,5x,\002YL\002,6x,\002QL\002,6x,\002AL\
\002,5x,\002TL\002,5x,\002DZ\002,5x,\002DX\002,5x,\002ELEV\002,6x,\002RES\
\002,\002  FR\002,\002 Tabid-----------\002)";
    static char fmt_2190[] = "(1x,\002*ERR:97* Elevation undefined at\002\
,\002  EXN = \002,a5)";
    static char fmt_2200[] = "(\002 Discharge = \002,f10.3)";
    static char fmt_2210[] = "(\002 *ERR:105* Value for branch node already \
present.\002,\002 Check node number= \002,a5,/,11x,\002 in CODE column.\002)";
    static char fmt_2214[] = "(/,\002*ERR:248* CODE field must be non-zero i\
f BRA field\002,\002 is zero or blank.\002)";
    static char fmt_2216[] = "(/,\002*ERR:249* CODE=\002,i5,\002 invalid opt\
ion.\002)";
    static char fmt_2218[] = "(\002 *ERR:250* Branch=\002,i5,\002 previously\
 processed.\002)";
    static char fmt_3001[] = "(/,\002 *ERR:99* Invalid exterior node. EXN =\
 \002,a5)";
    static char fmt_3003[] = "(/,\002*ERR:102* Invalid exterior node given w\
hen BRA=0\002,\002 EXN = \002,a5)";
    static char fmt_3004[] = "(/,\002*ERR:100* EXN# with BRA = 0 and ICODE =\
 -3\002,\002 is not a free node. EXN# = \002,a5)";
    static char fmt_3005[] = "(/,\002*ERR:404* Branch=\002,i5,\002 not compu\
ted in BACKWATER input\002)";
    static char fmt_3006[] = "(/,\002 Starting final check for unknown free \
nodes on dummy branches.\002)";
    static char fmt_3008[] = "(/,\002 Final check for unknown free nodes on \
dummy\002,\002 branches completed.\002)";
    static char fmt_3010[] = "(/,\002 *ERR:405* One or more free nodes given\
 in the list\002,\002 above have unknown elevations.\002,/,9x,\002  Please m\
ake sure\002,\002 that elevations are assigned to these free nodes in the\
\002,\002 BACKWATER block.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3;
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5];
    icilist feq_gen_ici_d_1;
    static real equiv_0[1];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_rsfi(icilist *), e_rsfi(), s_wsle(cilist *), do_lio(integer *, 
	    integer *, char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer ye1known[8400];
    real a, b;
    integer feq_gen_i_d_, j;
    real t, y, db, ak, ma;
    integer nb;
    real dk;
    integer dn, fn;
    real dt;
    integer ln;
    real qr, zi, yl, yr, yt;
    integer feq_gen_other_node_d_;
    real dma, arg;
    integer geq, nbr;
    real dmq, pdv, vol, mqt;
    extern /* Subroutine */ int fnd5_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);
    integer ntab;
    char line[80];
    integer adrs, dexn;
#define idum (feq::BitView<integer>(equiv_0, sizeof(equiv_0)))
    integer ipnt, usnb;
#define rdum (equiv_0)
    integer uexn;
    extern /* Subroutine */ int cd4qy_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, doublereal *, integer *, integer 
	    *, integer *, integer *, real *, integer *, integer *, real *), 
	    fndcd_(integer *, integer *, real *, real *, real *, real *, 
	    integer *);
    integer icode;
    real disch;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    integer snode;
    real selev;
    char usnbc[5];
    extern /* Subroutine */ int cd56qy_(integer *, integer *, integer *, 
	    doublereal *, integer *, integer *, real *, real *, real *, 
	    integer *, real *), xlkt23_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *), doeqz_(integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), getinb_(
	    integer *, integer *, integer *);
    char uscode[5];
    extern /* Subroutine */ int getinn_(char *, integer *, integer *, ftnlen);
    integer upsnod;
    char usnode[5];
    extern integer getusb_(integer *);
    extern /* Character */ VOID gettok_(char *, ftnlen, char *, ftnlen), 
	    getusn_(char *, ftnlen, integer *);
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen),
	     sfpsbm_(integer *, integer *, integer *, integer *, integer *, 
	    integer *, real *, real *, real *, real *, integer *, real *, 
	    real *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__25 = { 0, 0, 0, fmt_2000, 0 };
    static cilist feq_gen_io_d__28 = { 0, 0, 0, fmt_2010, 0 };
    static cilist feq_gen_io_d__30 = { 0, 0, 0, fmt_2200, 0 };
    static cilist feq_gen_io_d__33 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__34 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__35 = { 0, 0, 0, fmt_2001, 0 };
    static cilist feq_gen_io_d__42 = { 0, 0, 0, fmt_2120, 0 };
    static cilist feq_gen_io_d__45 = { 0, 0, 0, fmt_3003, 0 };
    static cilist feq_gen_io_d__46 = { 0, 0, 0, fmt_2190, 0 };
    static cilist feq_gen_io_d__49 = { 0, 0, 0, fmt_2210, 0 };
    static cilist feq_gen_io_d__50 = { 0, 0, 0, fmt_2214, 0 };
    static cilist feq_gen_io_d__51 = { 0, 0, 0, fmt_3004, 0 };
    static cilist feq_gen_io_d__53 = { 0, 0, 0, fmt_2216, 0 };
    static cilist feq_gen_io_d__59 = { 0, 0, 0, fmt_2218, 0 };
    static cilist feq_gen_io_d__61 = { 0, 0, 0, fmt_3001, 0 };
    static cilist feq_gen_io_d__62 = { 0, 0, 0, fmt_2190, 0 };
    static cilist feq_gen_io_d__63 = { 0, 0, 0, fmt_2110, 0 };
    static cilist feq_gen_io_d__64 = { 0, 0, 0, fmt_3001, 0 };
    static cilist feq_gen_io_d__66 = { 0, 0, 0, fmt_2190, 0 };
    static cilist feq_gen_io_d__67 = { 0, 0, 0, fmt_2110, 0 };
    static cilist feq_gen_io_d__68 = { 0, 0, 0, fmt_3001, 0 };
    static cilist feq_gen_io_d__71 = { 0, 0, 0, fmt_2190, 0 };
    static cilist feq_gen_io_d__72 = { 0, 0, 0, fmt_2216, 0 };
    static cilist feq_gen_io_d__73 = { 0, 0, 0, fmt_2170, 0 };
    static cilist feq_gen_io_d__74 = { 0, 0, 0, fmt_3001, 0 };
    static cilist feq_gen_io_d__75 = { 0, 0, 0, fmt_2190, 0 };
    static cilist feq_gen_io_d__76 = { 0, 0, 0, fmt_2216, 0 };
    static cilist feq_gen_io_d__77 = { 0, 0, 0, fmt_3005, 0 };
    static cilist feq_gen_io_d__78 = { 0, 0, 0, fmt_2160, 0 };
    static cilist feq_gen_io_d__96 = { 0, 0, 0, fmt_3005, 0 };
    static cilist feq_gen_io_d__97 = { 0, 0, 0, fmt_3006, 0 };
    static cilist feq_gen_io_d__98 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__99 = { 0, 0, 0, fmt_3010, 0 };
    static cilist feq_gen_io_d__100 = { 0, 0, 0, fmt_3008, 0 };
    static cilist feq_gen_io_d__101 = { 0, 0, 0, fmt_2160, 0 };
    static cilist feq_gen_io_d__102 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__103 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     This subroutine takes specified initial discharges */
/*     and initial downstream depth and computes initial */
/*     depths by steady flow analysis restrictions: */
/*     i)  Only applicable to dendritic networks */
/*     ii) Many network matrix relationships are ignored. */
/*     iii) Initial point and diffuse loading ignored */
/* SOURCE runinit.for:131 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE runinit.for:133 */
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
/* SOURCE runinit.for:136 */
/*<       integereflag,in,stdout,maxit,nbn,nbra,nex,output,ept >*/
/* SOURCE runinit.for:137 */
/*<       integerbrpt(8,nbra),emc(ept),exnodt(9,nex) >*/
/* SOURCE runinit.for:138 */
/*<       realepsb,grav,qeps,sfac,dz_for_output >*/
/* SOURCE runinit.for:139 */
/*<       real*8jtime >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     EPSB   - convergence limit for steady flow computations */
/*     GRAV   - value of acceleration due to gravity */
/*     IN     - unit number for the user input file */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     MAXIT  - maximum number of iterations at a node for finding */
/*               steady flow profile */
/*     NBRA   - number of branches in the model */
/*     NBN    - total number on nodes on branches in the model */
/*     NEX    - number of exterior nodes in the model */
/*     OUTPUT - output level for diagnostic work */
/*     TIME   - elapsed time in seconds from start of run */
/*     SFAC   - conversion factor from user stations to internal stations */
/*     BRPT   - branch pointer table.  Values for each branch are: */
/*              ROW       Meaning */
/*              1         upstream user node number */
/*              2         downstream user node number */
/*              3         pointer into branch vector for upstream node */
/*              4         pointer into branch vector for downstream node */
/*              5         upstream exterior node number */
/*              6         downstream exterior node number */
/*              7         pointer to address in EMC for the branch */
/*              8         number of unknowns at a node for the branch */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     QEPS   - value of flow to prevent zero divide when computing */
/*               relative correction */
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
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE runinit.for:184 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE runinit.for:185 */
/* SOURCE bnothr.cmn:1 */
/*<        >*/
/* SOURCE bnothr.cmn:6 */
/*<       common/bnothc/bnodid >*/
/* SOURCE bnothr.cmn:8 */
/*<       character*16bnodid(mnbn) >*/
/* SOURCE bnothr.cmn:10 */
/*<        >*/
/* SOURCE bnothr.cmn:13 */
/*<        >*/
/* INCLUDE runinit.for:186 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE runinit.for:189 */
/*<        >*/
/* SOURCE runinit.for:192 */
/*<        >*/
/* SOURCE runinit.for:194 */
/*<       characterline*80,uscode*5,usnbc*5,usnode*5 >*/
/*     + + + EQUIVALENCES + + + */
/* SOURCE runinit.for:197 */
/*<       equivalence(idum,rdum) >*/
/*     + + + INTRINSICS + + + */
/* SOURCE runinit.for:200 */
/*<       intrinsiciabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE runinit.for:203 */
/*<       integergetusb >*/
/*      CHARACTER GET_TABID*16 */
/* SOURCE runinit.for:205 */
/*<       charactergettok*5,getusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE runinit.for:208 */
/*<        >*/
/*     + + + INPUT FORMATS + + + */
/* 1000 FORMAT(20A4) */
/* SOURCE runinit.for:213 */
/*<  1010 format(14x,i5) >*/
/* SOURCE runinit.for:214 */
/*<  1060 format(a5,a5,f10.0,a5) >*/
/* SOURCE runinit.for:215 */
/*<  1070 format(10x,f10.0) >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE runinit.for:218 */
/*<  2000 format(' ',a80) >*/
/* SOURCE runinit.for:219 */
/*<  2001 format(/,' ',a80) >*/
/* SOURCE runinit.for:220 */
/*<  2010 format(/,' BRANCH NUMBER = ',i5) >*/
/* SOURCE runinit.for:221 */
/*<  2110 format(/,' *ERR:94* Downstream depth missing ','for branch',i5) >*/
/* SOURCE runinit.for:223 */
/*<  2120 format(1x,a5,a5,f10.2,a5) >*/
/* SOURCE runinit.for:224 */
/*<  2160 format(/,' *ERR:96* Fatal errors encountered.') >*/
/* SOURCE runinit.for:225 */
/*<  2170  >*/
/* SOURCE runinit.for:229 */
/*<  2190 format(1x,'*ERR:97* Elevation undefined at','  EXN = ',a5) >*/
/* SOURCE runinit.for:231 */
/*<  2200 format(' Discharge = ',f10.3) >*/
/* SOURCE runinit.for:232 */
/*<  2210  >*/
/* SOURCE runinit.for:234 */
/*<  2214  >*/
/* SOURCE runinit.for:236 */
/*<  2216 format(/,'*ERR:249* CODE=',i5,' invalid option.') >*/
/* SOURCE runinit.for:237 */
/*<  2218 format(' *ERR:250* Branch=',i5,' previously processed.') >*/
/* SOURCE runinit.for:238 */
/*<  3001 format(/,' *ERR:99* Invalid exterior node. EXN = ',a5) >*/
/* SOURCE runinit.for:239 */
/*<  3003  >*/
/* SOURCE runinit.for:241 */
/*<  3004  >*/
/* SOURCE runinit.for:243 */
/*<  3005  >*/
/* SOURCE runinit.for:245 */
/*<  3006  >*/
/* SOURCE runinit.for:247 */
/*<  3008  >*/
/* SOURCE runinit.for:249 */
/*<  3010  >*/
/* *********************************************************************** */
/*     SET YE1(*) FOR ERROR CHECKS */
/* SOURCE runinit.for:255 */
/*<       do300j=1,nex >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* L1010: */
/* L1060: */
/* L1070: */
/* L2000: */
/* L2001: */
/* L2010: */
/* L2110: */
/* L2120: */
/* L2160: */
/* L2170: */
/* L2190: */
/* L2200: */
/* L2210: */
/* L2214: */
/* L2216: */
/* L2218: */
/* L3001: */
/* L3003: */
/* L3004: */
/* L3005: */
/* L3006: */
/* L3008: */
/* L3010: */
    feq_gen_i_d_1 = *nex;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE runinit.for:256 */
/*<       if(exnodt(3,j).lt.0)then >*/
	if (exnodt[j * 9 + 3] < 0) {
/*         We have a reservoir node.  Leave YE1 at the input value because */
/*         it might be needed below. */
/* SOURCE runinit.for:260 */
/*<       elseif(exnodt(3,j).eq.0)then >*/
	} else if (exnodt[j * 9 + 3] == 0) {
/*         We have a node on a dummy branch or an inflow node to a LPR */
/* SOURCE runinit.for:262 */
/*<       if(exnodt(4,j).eq.0)then >*/
	    if (exnodt[j * 9 + 4] == 0) {
/*           We have an inflow node to an LPR.  Force its depth */
/*           to match the reservoir node. */
/* SOURCE runinit.for:265 */
/*<       other_node=exnodt(2,j) >*/
		feq_gen_other_node_d_ = exnodt[j * 9 + 2];
/* SOURCE runinit.for:266 */
/*<       ye1(j)=ye1(other_node)+ze(other_node)-ze(j) >*/
		enelem_1.ye1[j - 1] = static_cast<double>(static_cast<double>(enelem_1.ye1[feq_gen_other_node_d_ - 1]) + 
			enelem_1.ze[feq_gen_other_node_d_ - 1]) - enelem_1.ze[j - 1];
/* SOURCE runinit.for:267 */
/*<       else >*/
	    } else {
/*           This is node on a dummy branch.  It could */
/*           be involved in a code 6 type 2 and then */
/*           the initial value is to be kept. */
/* SOURCE runinit.for:271 */
/*<       if(exnodt(9,j).eq.62)then >*/
		if (exnodt[j * 9 + 9] == 62) {
/*             We have a hit.  Get the other node */
/*             and if its flag is NOT set to 62, */
/*             transfer the depth and set its flag. */
/* SOURCE runinit.for:275 */
/*<       if(exnodt(9,exnodt(4,j)).eq.0)then >*/
		    if (exnodt[exnodt[j * 9 + 4] * 9 + 9] == 0) {
/*               Make the changes. */
/* SOURCE runinit.for:277 */
/*<       ye1(exnodt(4,j))=ye1(j)+ze(j)-ze(exnodt(4,j)) >*/
			enelem_1.ye1[exnodt[j * 9 + 4] - 1] = static_cast<double>(static_cast<double>(enelem_1.ye1[j 
				- 1]) + enelem_1.ze[j - 1]) - enelem_1.ze[
				exnodt[j * 9 + 4] - 1];
/* SOURCE runinit.for:278 */
/*<       exnodt(9,exnodt(4,j))=62 >*/
			exnodt[exnodt[j * 9 + 4] * 9 + 9] = 62;
/* SOURCE runinit.for:279 */
/*<       endif >*/
		    }
/* SOURCE runinit.for:280 */
/*<       else >*/
		} else {
/* SOURCE runinit.for:281 */
/*<       ye1(j)=-1.e20 >*/
		    enelem_1.ye1[j - 1] = (float)-1e20;
/* SOURCE runinit.for:282 */
/*<       endif >*/
		}
/* SOURCE runinit.for:283 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:284 */
/*<       else >*/
	} else {
/*        Exterior nodes on branches here */
/* SOURCE runinit.for:286 */
/*<       ye1(j)=-1.e20 >*/
	    enelem_1.ye1[j - 1] = (float)-1e20;
/* SOURCE runinit.for:287 */
/*<       endif >*/
	}
/* SOURCE runinit.for:288 */
/*<   300 continue >*/
/* L300: */
    }
/*     SET Y1(*) FOR ERROR CHECK */
/* SOURCE runinit.for:291 */
/*<       do310j=1,nbn >*/
    feq_gen_i_d_1 = *nbn;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE runinit.for:292 */
/*<       y1(j)=-1.e20 >*/
	bnelem_1.y1[j - 1] = (float)-1e20;
/* SOURCE runinit.for:293 */
/*<   310 continue >*/
/* L310: */
    }
/*     READ TITLE CARD */
/* SOURCE runinit.for:296 */
/*<       callinline(in,stdout,line) >*/
    inline_(in, stdout, line, (ftnlen)80);
/* SOURCE runinit.for:299 */
/*<       write(stdout,2000)line >*/
    feq_gen_io_d__25.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__25);
    do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
    e_wsfe();
/*     BRANCH LOOP */
/* SOURCE runinit.for:303 */
/*<       eflag=0 >*/
    *eflag = 0;
/* SOURCE runinit.for:304 */
/*<       do100nb=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (nb = 1; nb <= feq_gen_i_d_1; ++nb) {
/* SOURCE runinit.for:305 */
/*<       callinline(in,stdout,line) >*/
	inline_(in, stdout, line, (ftnlen)80);
/* SOURCE runinit.for:308 */
/*<       read(line,1010,err=991)nbr >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_1010;
	feq_gen_i_d_2 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_2 != 0) {
	    goto L991;
	}
	feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&nbr, (ftnlen)sizeof(integer));
	if (feq_gen_i_d_2 != 0) {
	    goto L991;
	}
	feq_gen_i_d_2 = e_rsfi();
	if (feq_gen_i_d_2 != 0) {
	    goto L991;
	}
/* SOURCE runinit.for:309 */
/*<       if(nbr.gt.0)goto7 >*/
	if (nbr > 0) {
	    goto L7;
	}
/* SOURCE runinit.for:310 */
/*<       nbr=iabs(nbr) >*/
	nbr = abs(nbr);
/* SOURCE runinit.for:311 */
/*<       write(stdout,2010)nbr >*/
	feq_gen_io_d__28.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__28);
	do_fio(&feq_gen_c_d_1, (char *)&nbr, (ftnlen)sizeof(integer));
	e_wsfe();
/*         NBR = GETINB(NBR, EFLAG) */
/* SOURCE runinit.for:313 */
/*<       callgetinb(nbr,eflag,nbr) >*/
	getinb_(&nbr, eflag, &nbr);
/* SOURCE runinit.for:316 */
/*<       callinline(in,stdout,line) >*/
	inline_(in, stdout, line, (ftnlen)80);
/* SOURCE runinit.for:319 */
/*<       read(line,1070,err=991)disch >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_1070;
	feq_gen_i_d_2 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_2 != 0) {
	    goto L991;
	}
	feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&disch, (ftnlen)sizeof(real));
	if (feq_gen_i_d_2 != 0) {
	    goto L991;
	}
	feq_gen_i_d_2 = e_rsfi();
	if (feq_gen_i_d_2 != 0) {
	    goto L991;
	}
/* SOURCE runinit.for:320 */
/*<       write(stdout,2200)disch >*/
	feq_gen_io_d__30.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__30);
	do_fio(&feq_gen_c_d_1, (char *)&disch, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE runinit.for:321 */
/*<       fn=brpt(3,nbr) >*/
	fn = brpt[(nbr << 3) + 3];
/* SOURCE runinit.for:322 */
/*<       ln=brpt(4,nbr) >*/
	ln = brpt[(nbr << 3) + 4];
/* SOURCE runinit.for:323 */
/*<       do5j=fn,ln >*/
	feq_gen_i_d_2 = ln;
	for (j = fn; j <= feq_gen_i_d_2; ++j) {
/* SOURCE runinit.for:324 */
/*<       q1(j)=disch >*/
	    bnelem_1.q1[j - 1] = disch;
/* SOURCE runinit.for:325 */
/*<       q2(j)=disch >*/
	    bnelem_1.q2[j - 1] = disch;
/* SOURCE runinit.for:326 */
/*<     5 continue >*/
/* L5: */
	}
/* SOURCE runinit.for:327 */
/*<       qe1(brpt(5,nbr))=q1(fn) >*/
	enelem_1.qe1[brpt[(nbr << 3) + 5] - 1] = bnelem_1.q1[fn - 1];
/* SOURCE runinit.for:328 */
/*<       qe1(brpt(6,nbr))=q1(ln) >*/
	enelem_1.qe1[brpt[(nbr << 3) + 6] - 1] = bnelem_1.q1[ln - 1];
/* SOURCE runinit.for:329 */
/*<       goto100 >*/
	goto L100;
/* SOURCE runinit.for:330 */
/*<     7 continue >*/
L7:
/* SOURCE runinit.for:331 */
/*<       write(stdout,*)' DO NOT USE THIS BACKWATER OPTION.' >*/
	feq_gen_io_d__33.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__33);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" DO NOT USE THIS BACKWATER OPTION."), (ftnlen)34)
		;
	e_wsle();
/* SOURCE runinit.for:332 */
/*<       write(stdout,*)' ALWAYS USE NEGATIVE BRANCH NUMBERS.' >*/
	feq_gen_io_d__34.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__34);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" ALWAYS USE NEGATIVE BRANCH NUMBERS."), (ftnlen)
		36);
	e_wsle();
/* SOURCE runinit.for:333 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:334 */
/*<   100 continue >*/
L100:
	;
    }
/* SOURCE runinit.for:336 */
/*<       callinline(in,stdout,line) >*/
    inline_(in, stdout, line, (ftnlen)80);
/* SOURCE runinit.for:339 */
/*<       write(stdout,2001)line >*/
    feq_gen_io_d__35.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__35);
    do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
    e_wsfe();
/*     NOW START COMPUTATION LOOP */
/*     START LOOP FOR BACKWATER ANALYSIS: Read the next instruction. */
/* SOURCE runinit.for:346 */
/*<   160 continue >*/
L160:
/* SOURCE runinit.for:347 */
/*<       callinline(in,stdout,line) >*/
    inline_(in, stdout, line, (ftnlen)80);
/* SOURCE runinit.for:350 */
/*<       read(line,1060,err=991)usnbc,uscode,selev,usnode >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_1060;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, usnbc, (ftnlen)5);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, uscode, (ftnlen)5);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&selev, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, usnode, (ftnlen)5);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/*       Decode USNBC.  It can be a branch number, it can be */
/*       a new style exterior node number or it can be the negative */
/*       of an old style exterior node number or it can be a -1 */
/*       with nothing else on the line. */
/*       Strip leading blanks from USNBC */
/* SOURCE runinit.for:356 */
/*<       usnbc=gettok(usnbc) >*/
    gettok_(feq_gen_ch_d_1, (ftnlen)5, usnbc, (ftnlen)5);
    s_copy(usnbc, feq_gen_ch_d_1, (ftnlen)5, (ftnlen)5);
/* SOURCE runinit.for:357 */
/*<        >*/
    if (*(unsigned char *)usnbc == 'U' || *(unsigned char *)usnbc == 'D' || *(
	    unsigned char *)usnbc == 'F') {
/*          The item is a new style exterior node label.  Convert it */
/*          to internal form. */
/* SOURCE runinit.for:361 */
/*<       callgetinn(usnbc,eflag,upsnod) >*/
	getinn_(usnbc, eflag, &upsnod, (ftnlen)5);
/*          Set the internal branch number to zero. */
/* SOURCE runinit.for:365 */
/*<       nb=0 >*/
	nb = 0;
/* SOURCE runinit.for:366 */
/*<       usnb=0 >*/
	usnb = 0;
/* SOURCE runinit.for:367 */
/*<       else >*/
    } else {
/*          The item is a number of some sort.   Read it as such. */
/* SOURCE runinit.for:369 */
/*<       read(usnbc,'(I5)',err=991)usnb >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 5;
	feq_gen_ici_d_1.iciunit = usnbc;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(I5)");
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&usnb, (ftnlen)sizeof(integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/*          Check if it is a branch number. */
/* SOURCE runinit.for:371 */
/*<       if(usnb.ge.0)then >*/
	if (usnb >= 0) {
/*            Convert it to internal form.  GETINB can handle a zero */
/*            value for the branch number. */
/* SOURCE runinit.for:374 */
/*<       callgetinb(usnb,eflag,nb) >*/
	    getinb_(&usnb, eflag, &nb);
/* SOURCE runinit.for:377 */
/*<       upsnod=0 >*/
	    upsnod = 0;
/* SOURCE runinit.for:378 */
/*<       else >*/
	} else {
/*            Check for it being an end of input flag. */
/* SOURCE runinit.for:380 */
/*<       if(uscode.eq.' '.and.selev.eq.0.0.and.usnode.eq.' ')then >*/
	    if (s_cmp(uscode, const_cast<char*>(" "), (ftnlen)5, (ftnlen)1) == 0 && selev == (
		    float)0. && s_cmp(usnode, const_cast<char*>(" "), (ftnlen)5, (ftnlen)1) == 0)
		     {
/*              Nothing else on the line.  Take it to be end of input */
/*              flag. */
/* SOURCE runinit.for:383 */
/*<       goto200 >*/
		goto L200;
/* SOURCE runinit.for:384 */
/*<       else >*/
	    } else {
/*             Take it to be an exterior node number in the old */
/*             style.  Remove the unary minus from the number. */
/* SOURCE runinit.for:387 */
/*<       usnbc(1:1)=' ' >*/
		*(unsigned char *)usnbc = ' ';
/* SOURCE runinit.for:388 */
/*<       callgetinn(usnbc,eflag,upsnod) >*/
		getinn_(usnbc, eflag, &upsnod, (ftnlen)5);
/* SOURCE runinit.for:391 */
/*<       nb=0 >*/
		nb = 0;
/* SOURCE runinit.for:392 */
/*<       usnb=0 >*/
		usnb = 0;
/* SOURCE runinit.for:393 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:394 */
/*<       endif >*/
	}
/* SOURCE runinit.for:395 */
/*<       endif >*/
    }
/* SOURCE runinit.for:396 */
/*<       write(stdout,2120)usnbc,uscode,selev,usnode >*/
    feq_gen_io_d__42.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__42);
    do_fio(&feq_gen_c_d_1, usnbc, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, uscode, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, (char *)&selev, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, usnode, (ftnlen)5);
    e_wsfe();
/*       CONVERT USCODE AND USNODE. STRIP BLANKS FROM USCODE */
/* SOURCE runinit.for:399 */
/*<       uscode=gettok(uscode) >*/
    gettok_(feq_gen_ch_d_1, (ftnlen)5, uscode, (ftnlen)5);
    s_copy(uscode, feq_gen_ch_d_1, (ftnlen)5, (ftnlen)5);
/* SOURCE runinit.for:400 */
/*<       if(upsnod.eq.0)then >*/
    if (upsnod == 0) {
/* SOURCE runinit.for:401 */
/*<       if(nb.eq.0)then >*/
	if (nb == 0) {
/* SOURCE runinit.for:402 */
/*<       if(uscode(1:1).eq.'-')then >*/
	    if (*(unsigned char *)uscode == '-') {
/*             NUMERICAL CODE.  READ IT. */
/* SOURCE runinit.for:404 */
/*<       read(uscode,'(I5)',err=991)icode >*/
		feq_gen_ici_d_1.icierr = 1;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 5;
		feq_gen_ici_d_1.iciunit = uscode;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(I5)");
		feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
		if (feq_gen_i_d_1 != 0) {
		    goto L991;
		}
		feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&icode, (ftnlen)sizeof(integer));
		if (feq_gen_i_d_1 != 0) {
		    goto L991;
		}
		feq_gen_i_d_1 = e_rsfi();
		if (feq_gen_i_d_1 != 0) {
		    goto L991;
		}
/* SOURCE runinit.for:405 */
/*<       else >*/
	    } else {
/*             SHOULD BE A NODE. CONVERT IT TO INTERNAL FORM. */
/* SOURCE runinit.for:407 */
/*<       callgetinn(uscode,eflag,icode) >*/
		getinn_(uscode, eflag, &icode, (ftnlen)5);
/* SOURCE runinit.for:410 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:411 */
/*<       else >*/
	} else {
/*           NUMERICAL CODE */
/* SOURCE runinit.for:413 */
/*<       read(uscode,'(I5)',err=991)icode >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 5;
	    feq_gen_ici_d_1.iciunit = uscode;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(I5)");
	    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&icode, (ftnlen)sizeof(integer));
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_1 = e_rsfi();
	    if (feq_gen_i_d_1 != 0) {
		goto L991;
	    }
/* SOURCE runinit.for:414 */
/*<       endif >*/
	}
/* SOURCE runinit.for:415 */
/*<       else >*/
    } else {
/*         CODE is a numerical value denoting an action and */
/*         not a node label. */
/* SOURCE runinit.for:418 */
/*<       read(uscode,'(I5)',err=991)icode >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 5;
	feq_gen_ici_d_1.iciunit = uscode;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(I5)");
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&icode, (ftnlen)sizeof(integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE runinit.for:419 */
/*<       endif >*/
    }
/* SOURCE runinit.for:421 */
/*<       if(usnode.eq.'     ')then >*/
    if (s_cmp(usnode, const_cast<char*>("     "), (ftnlen)5, (ftnlen)5) == 0) {
/* SOURCE runinit.for:422 */
/*<       snode=0 >*/
	snode = 0;
/* SOURCE runinit.for:423 */
/*<       else >*/
    } else {
/*         SHOULD BE AN EXTERIOR NODE */
/* SOURCE runinit.for:425 */
/*<       callgetinn(usnode,eflag,snode) >*/
	getinn_(usnode, eflag, &snode, (ftnlen)5);
/* SOURCE runinit.for:428 */
/*<       endif >*/
    }
/*        WRITE(STDOUT,*) ' UPSNOD=',UPSNOD,' NB=',NB,' ICODE=',ICODE */
/* SOURCE runinit.for:431 */
/*<       if(upsnod.eq.0)then >*/
    if (upsnod == 0) {
/*         2-D relationship with a free node is not involved. */
/* SOURCE runinit.for:433 */
/*<       if(nb.eq.0)then >*/
	if (nb == 0) {
/*           User supplied a zero or a blank in the BRA column. */
/* SOURCE runinit.for:435 */
/*<       if(icode.gt.0)then >*/
	    if (icode > 0) {
/*             ICODE contains an exterior node number giving the */
/*             node to receive an elevation.  SNODE gives the exterior */
/*             node number from which the elevation is taken. */
/* SOURCE runinit.for:439 */
/*<       if(snode.le.0.or.snode.gt.nex)then >*/
		if (snode <= 0 || snode > *nex) {
/*               SNODE is invalid. */
/* SOURCE runinit.for:441 */
/*<       write(stdout,3003)usnode >*/
		    feq_gen_io_d__45.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__45);
		    do_fio(&feq_gen_c_d_1, usnode, (ftnlen)5);
		    e_wsfe();
/* SOURCE runinit.for:442 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:443 */
/*<       endif >*/
		}
/* SOURCE runinit.for:444 */
/*<       if(ye1(snode).le.0.0)then >*/
		if (enelem_1.ye1[snode - 1] <= (float)0.) {
/*               Value not known at the source node. */
/* SOURCE runinit.for:446 */
/*<       write(stdout,2190)usnode >*/
		    feq_gen_io_d__46.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__46);
		    do_fio(&feq_gen_c_d_1, usnode, (ftnlen)5);
		    e_wsfe();
/* SOURCE runinit.for:447 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:448 */
/*<       else >*/
		} else {
/*               Value at source node is known.  Transfer it to the */
/*               destination node. */
/* SOURCE runinit.for:451 */
/*<       ye1(icode)=ye1(snode)+ze(snode)-ze(icode)+selev >*/
		    enelem_1.ye1[icode - 1] = static_cast<double>(static_cast<double>(static_cast<double>(enelem_1.ye1[snode - 1]) + 
			    enelem_1.ze[snode - 1]) - enelem_1.ze[icode - 1]) + 
			    selev;
/* SOURCE runinit.for:453 */
/*<       ye1known(icode)=1 >*/
		    ye1known[icode - 1] = 1;
/* SOURCE runinit.for:454 */
/*<       if(exnodt(3,icode).gt.0)then >*/
		    if (exnodt[icode * 9 + 3] > 0) {
/*                 Destination node is on a branch.  Get pointer into */
/*                 the branch vectors. */
/* SOURCE runinit.for:457 */
/*<       i=exnodt(2,icode) >*/
			feq_gen_i_d_ = exnodt[icode * 9 + 2];
/* SOURCE runinit.for:458 */
/*<       if(y1(i).gt.0.0)then >*/
			if (bnelem_1.y1[feq_gen_i_d_ - 1] > (float)0.) {
/*                   Branch vector already has a value. */
/* SOURCE runinit.for:460 */
/*<       write(stdout,2210)uscode >*/
			    feq_gen_io_d__49.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__49);
			    do_fio(&feq_gen_c_d_1, uscode, (ftnlen)5);
			    e_wsfe();
/* SOURCE runinit.for:461 */
/*<       stop'Abnormal stop: errors found.' >*/
			    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28)
				    ;
/* SOURCE runinit.for:462 */
/*<       else >*/
			} else {
/*                   Make the depth the same in the branch */
/*                   vectors. */
/* SOURCE runinit.for:465 */
/*<       y1(i)=ye1(icode) >*/
			    bnelem_1.y1[feq_gen_i_d_ - 1] = enelem_1.ye1[icode - 1];
/* SOURCE runinit.for:466 */
/*<       endif >*/
			}
/* SOURCE runinit.for:467 */
/*<       endif >*/
		    }
/* SOURCE runinit.for:468 */
/*<       endif >*/
		}
/* SOURCE runinit.for:469 */
/*<       elseif(icode.eq.0)then >*/
	    } else if (icode == 0) {
/*             Code field must be non-zero if the BRA field is zero. */
/* SOURCE runinit.for:471 */
/*<       write(stdout,2214) >*/
		feq_gen_io_d__50.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__50);
		e_wsfe();
/* SOURCE runinit.for:472 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:473 */
/*<       else >*/
	    } else {
/*             CODE field gives an action to follow.  -3 only action */
/*             currently supported. */
/* SOURCE runinit.for:476 */
/*<       if(icode.eq.-3)then >*/
		if (icode == -3) {
/*               Compute the stage at a free node given that there */
/*               is a Code 4 specified at the node. */
/* SOURCE runinit.for:479 */
/*<       if(exnodt(3,snode).gt.0)then >*/
		    if (exnodt[snode * 9 + 3] > 0) {
/* SOURCE runinit.for:480 */
/*<       write(stdout,3004)usnode >*/
			feq_gen_io_d__51.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__51);
			do_fio(&feq_gen_c_d_1, usnode, (ftnlen)5);
			e_wsfe();
/* SOURCE runinit.for:481 */
/*<       stop'Abnormal stop: errors found.' >*/
			s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:482 */
/*<       else >*/
		    } else {
/* SOURCE runinit.for:483 */
/*<       yr=ye1(snode) >*/
			yr = enelem_1.ye1[snode - 1];
/* SOURCE runinit.for:484 */
/*<        >*/
			cd4qy_(stdout, &nb, &snode, nbra, nex, nbn, jtime, &
				brpt[9], &exnodt[10], &emc[1], maxit, epsb, 
				output, ept, &yr);
/*                 On return YR contains the depth at the node.  The */
/*                 value is also stored in YE1(SNODE). */
/* SOURCE runinit.for:491 */
/*<       ye1known(snode)=1 >*/
			ye1known[snode - 1] = 1;
/* SOURCE runinit.for:492 */
/*<       endif >*/
		    }
/* SOURCE runinit.for:493 */
/*<       else >*/
		} else {
/* SOURCE runinit.for:494 */
/*<       write(stdout,2216)icode >*/
		    feq_gen_io_d__53.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__53);
		    do_fio(&feq_gen_c_d_1, (char *)&icode, (ftnlen)sizeof(integer));
		    e_wsfe();
/* SOURCE runinit.for:495 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:496 */
/*<       endif >*/
		}
/* SOURCE runinit.for:497 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:498 */
/*<       else >*/
	} else {
/*           Branch is to be processed.  Set limits for this branch. */
/* SOURCE runinit.for:500 */
/*<       ln=brpt(4,nb) >*/
	    ln = brpt[(nb << 3) + 4];
/* SOURCE runinit.for:501 */
/*<       fn=brpt(3,nb) >*/
	    fn = brpt[(nb << 3) + 3];
/* SOURCE runinit.for:502 */
/*<       dn=brpt(2,nb) >*/
	    dn = brpt[(nb << 3) + 2];
/* SOURCE runinit.for:503 */
/*<       dexn=brpt(6,nb) >*/
	    dexn = brpt[(nb << 3) + 6];
/* SOURCE runinit.for:504 */
/*<       uexn=brpt(5,nb) >*/
	    uexn = brpt[(nb << 3) + 5];
/* SOURCE runinit.for:505 */
/*<       adrs=nsec(ln) >*/
	    adrs = bnothr_1.nsec[ln - 1];
/* SOURCE runinit.for:506 */
/*<       qr=qe1(dexn) >*/
	    qr = enelem_1.qe1[dexn - 1];
/*           Establish downstream conditions.  Check if branch has */
/*           already been processed. */
/* SOURCE runinit.for:510 */
/*<       if(y1(ln).gt.0.0)then >*/
	    if (bnelem_1.y1[ln - 1] > (float)0.) {
/*             BRANCH NODE ALREADY HAS A VALUE. */
/*             DESTINATION NODE NUMBER. */
/* SOURCE runinit.for:513 */
/*<       write(stdout,2218)usnb >*/
		feq_gen_io_d__59.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__59);
		do_fio(&feq_gen_c_d_1, (char *)&usnb, (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE runinit.for:514 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:515 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:517 */
/*<       zi=zivec(nb) >*/
	    zi = bnothr_1.zivec[nb - 1];
/* SOURCE runinit.for:519 */
/*<       if(icode.eq.0)then >*/
	    if (icode == 0) {
/*             Water-surface elevation given by sum of SELEV and the */
/*             elevation of the node given in SNODE.  The resulting */
/*             depth is then placed in the branch vector and in the */
/*             exterior-node  vector. */
/* SOURCE runinit.for:524 */
/*<       if(snode.le.0.or.snode.gt.nex)then >*/
		if (snode <= 0 || snode > *nex) {
/* SOURCE runinit.for:525 */
/*<       write(stdout,3001)usnode >*/
		    feq_gen_io_d__61.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__61);
		    do_fio(&feq_gen_c_d_1, usnode, (ftnlen)5);
		    e_wsfe();
/* SOURCE runinit.for:526 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:527 */
/*<       else >*/
		} else {
/*               SNODE valid here. */
/* SOURCE runinit.for:529 */
/*<       if(ye1(snode).gt.0.0)then >*/
		    if (enelem_1.ye1[snode - 1] > (float)0.) {
/*                 Value is known at exterior node */
/* SOURCE runinit.for:531 */
/*<       ye1(dexn)=ye1(snode)+ze(snode)-ze(dexn)+selev >*/
			enelem_1.ye1[dexn - 1] = static_cast<double>(static_cast<double>(static_cast<double>(enelem_1.ye1[snode - 1]) + 
				enelem_1.ze[snode - 1]) - enelem_1.ze[dexn - 1])
				 + selev;
/* SOURCE runinit.for:533 */
/*<       ye1known(dexn)=1 >*/
			ye1known[dexn - 1] = 1;
/* SOURCE runinit.for:534 */
/*<       y1(ln)=ye1(dexn) >*/
			bnelem_1.y1[ln - 1] = enelem_1.ye1[dexn - 1];
/* SOURCE runinit.for:535 */
/*<       yr=ye1(dexn) >*/
			yr = enelem_1.ye1[dexn - 1];
/* SOURCE runinit.for:536 */
/*<       else >*/
		    } else {
/*                 Value unknown at exterior node. */
/* SOURCE runinit.for:538 */
/*<       write(stdout,2190)usnode >*/
			feq_gen_io_d__62.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__62);
			do_fio(&feq_gen_c_d_1, usnode, (ftnlen)5);
			e_wsfe();
/* SOURCE runinit.for:539 */
/*<       stop'Abnormal stop: errors found.' >*/
			s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:540 */
/*<       endif >*/
		    }
/* SOURCE runinit.for:541 */
/*<       endif >*/
		}
/* SOURCE runinit.for:542 */
/*<       elseif(icode.eq.1)then >*/
	    } else if (icode == 1) {
/*             Water-surface elevation given directly by SELEV */
/* SOURCE runinit.for:544 */
/*<       yr=selev-ze(dexn) >*/
		yr = static_cast<double>(selev) - enelem_1.ze[dexn - 1];
/* SOURCE runinit.for:545 */
/*<       y1(ln)=yr >*/
		bnelem_1.y1[ln - 1] = yr;
/* SOURCE runinit.for:546 */
/*<       ye1(dexn)=yr >*/
		enelem_1.ye1[dexn - 1] = yr;
/* SOURCE runinit.for:547 */
/*<       ye1known(dexn)=1 >*/
		ye1known[dexn - 1] = 1;
/* SOURCE runinit.for:548 */
/*<       elseif(icode.eq.2.or.icode.eq.5)then >*/
	    } else if (icode == 2 || icode == 5) {
/*             Find critical depth. */
/* SOURCE runinit.for:551 */
/*<       yr=selev-ze(dexn) >*/
		yr = static_cast<double>(selev) - enelem_1.ze[dexn - 1];
/* SOURCE runinit.for:552 */
/*<       if(yr.le.0.0)then >*/
		if (yr <= (float)0.) {
/* SOURCE runinit.for:553 */
/*<       write(stdout,2110)usnb >*/
		    feq_gen_io_d__63.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__63);
		    do_fio(&feq_gen_c_d_1, (char *)&usnb, (ftnlen)sizeof(integer));
		    e_wsfe();
/* SOURCE runinit.for:554 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:555 */
/*<       else >*/
		} else {
/*                WRITE(STDOUT,*) ' CALLING FNDCD: YR=',YR,' QR=',QR */
/* SOURCE runinit.for:557 */
/*<       callfndcd(stdout,adrs,grav,epsb,qr,yr,eflag) >*/
		    fndcd_(stdout, &adrs, grav, epsb, &qr, &yr, eflag);
/*                WRITE(STDOUT,*) ' RETURN FROM FNDCD: YR=',YR */
/* SOURCE runinit.for:562 */
/*<       if(eflag.ne.0)stop'Abnormal stop: errors found.' >*/
		    if (*eflag != 0) {
			s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
		    }
/* SOURCE runinit.for:563 */
/*<       ye1(dexn)=yr >*/
		    enelem_1.ye1[dexn - 1] = yr;
/* SOURCE runinit.for:564 */
/*<       ye1known(dexn)=1 >*/
		    ye1known[dexn - 1] = 1;
/* SOURCE runinit.for:565 */
/*<       y1(ln)=yr >*/
		    bnelem_1.y1[ln - 1] = yr;
/* SOURCE runinit.for:566 */
/*<       if(icode.eq.5)then >*/
		    if (icode == 5) {
/*                 Check for drowning from  SNODE */
/* SOURCE runinit.for:568 */
/*<       if(snode.le.0.or.snode.gt.nex)then >*/
			if (snode <= 0 || snode > *nex) {
/* SOURCE runinit.for:569 */
/*<       write(stdout,3001)usnode >*/
			    feq_gen_io_d__64.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__64);
			    do_fio(&feq_gen_c_d_1, usnode, (ftnlen)5);
			    e_wsfe();
/* SOURCE runinit.for:570 */
/*<       stop'Abnormal stop: errors found.' >*/
			    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28)
				    ;
/* SOURCE runinit.for:571 */
/*<       else >*/
			} else {
/*                   SNODE valid here. */
/* SOURCE runinit.for:573 */
/*<       if(ye1(snode).gt.0.0)then >*/
			    if (enelem_1.ye1[snode - 1] > (float)0.) {
/*                     Value is known at exterior node */
/* SOURCE runinit.for:575 */
/*<       yt=ye1(snode)+ze(snode) >*/
				yt = static_cast<double>(enelem_1.ye1[snode - 1]) + enelem_1.ze[
					snode - 1];
/* SOURCE runinit.for:576 */
/*<       if(yt.gt.yr+ze(dexn))then >*/
				if (yt > static_cast<double>(yr) + enelem_1.ze[dexn - 1]) {
/* SOURCE runinit.for:577 */
/*<       yr=yt-ze(dexn) >*/
				    yr = static_cast<double>(yt) - enelem_1.ze[dexn - 1];
/* SOURCE runinit.for:578 */
/*<       ye1(dexn)=yr >*/
				    enelem_1.ye1[dexn - 1] = yr;
/* SOURCE runinit.for:579 */
/*<       ye1known(dexn)=1 >*/
				    ye1known[dexn - 1] = 1;
/* SOURCE runinit.for:580 */
/*<       y1(ln)=yr >*/
				    bnelem_1.y1[ln - 1] = yr;
/* SOURCE runinit.for:581 */
/*<       endif >*/
				}
/* SOURCE runinit.for:582 */
/*<       else >*/
			    } else {
/*                     Value unknown at exterior node. */
/* SOURCE runinit.for:584 */
/*<       write(stdout,2190)usnode >*/
				feq_gen_io_d__66.ciunit = *stdout;
				s_wsfe(&feq_gen_io_d__66);
				do_fio(&feq_gen_c_d_1, usnode, (ftnlen)5);
				e_wsfe();
/* SOURCE runinit.for:585 */
/*<       stop'Abnormal stop: errors found.' >*/
				s_stop(const_cast<char*>("Abnormal stop: errors found."), (
					ftnlen)28);
/* SOURCE runinit.for:586 */
/*<       endif >*/
			    }
/* SOURCE runinit.for:587 */
/*<       endif >*/
			}
/* SOURCE runinit.for:588 */
/*<       endif >*/
		    }
/* SOURCE runinit.for:589 */
/*<       endif >*/
		}
/* SOURCE runinit.for:591 */
/*<       elseif(icode.eq.3)then >*/
	    } else if (icode == 3) {
/*             Compute the depth from a rating curve given by */
/*             Code 4 types 1, 2, or 3. */
/* SOURCE runinit.for:594 */
/*<       yr=selev-ze(dexn) >*/
		yr = static_cast<double>(selev) - enelem_1.ze[dexn - 1];
/* SOURCE runinit.for:595 */
/*<       if(yr.le.0.0)then >*/
		if (yr <= (float)0.) {
/* SOURCE runinit.for:596 */
/*<       write(stdout,2110)usnb >*/
		    feq_gen_io_d__67.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__67);
		    do_fio(&feq_gen_c_d_1, (char *)&usnb, (ftnlen)sizeof(integer));
		    e_wsfe();
/* SOURCE runinit.for:597 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:598 */
/*<       else >*/
		} else {
/* SOURCE runinit.for:599 */
/*<        >*/
		    cd4qy_(stdout, &nb, &dexn, nbra, nex, nbn, jtime, &brpt[9]
			    , &exnodt[10], &emc[1], maxit, epsb, output, ept, 
			    &yr);
/*                On return YR contains the depth at the node.  The */
/*                value is also stored in YE1(DEXN). */
/* SOURCE runinit.for:605 */
/*<       ye1known(dexn)=1 >*/
		    ye1known[dexn - 1] = 1;
/* SOURCE runinit.for:606 */
/*<       endif >*/
		}
/* SOURCE runinit.for:607 */
/*<       elseif(icode.eq.6)then >*/
	    } else if (icode == 6) {
/*             2-D table given with a branch.  DEXN is the */
/*             upstream node for the control structure and */
/*             SNODE is the downstream node. */
/* SOURCE runinit.for:611 */
/*<       if(snode.le.0.or.snode.gt.nex)then >*/
		if (snode <= 0 || snode > *nex) {
/* SOURCE runinit.for:612 */
/*<       write(stdout,3001)usnode >*/
		    feq_gen_io_d__68.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__68);
		    do_fio(&feq_gen_c_d_1, usnode, (ftnlen)5);
		    e_wsfe();
/* SOURCE runinit.for:613 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:614 */
/*<       else >*/
		} else {
/*               SNODE valid here. */
/* SOURCE runinit.for:616 */
/*<       if(ye1(snode).gt.0.0)then >*/
		    if (enelem_1.ye1[snode - 1] > (float)0.) {
/*                 Find the entry in EMC. */
/* SOURCE runinit.for:618 */
/*<       callfnd5(stdout,6,dexn,snode,emc,ept,ipnt) >*/
			fnd5_(stdout, &feq_gen_c_d_6, &dexn, &snode, &emc[1], ept, &
				ipnt);
/* SOURCE runinit.for:622 */
/*<       yl=selev-ze(dexn) >*/
			yl = static_cast<double>(selev) - enelem_1.ze[dexn - 1];
/* SOURCE runinit.for:623 */
/*<       yr=ye1(snode) >*/
			yr = enelem_1.ye1[snode - 1];
/* SOURCE runinit.for:624 */
/*<       callcd56qy(stdout,ipnt,nex,jtime,emc,maxit,yr,epsb,qeps,ept,yl) >*/
			cd56qy_(stdout, &ipnt, nex, jtime, &emc[1], maxit, &
				yr, epsb, qeps, ept, &yl);
/* SOURCE runinit.for:629 */
/*<       yr=ye2(dexn) >*/
			yr = enelem_1.ye2[dexn - 1];
/* SOURCE runinit.for:630 */
/*<       ye1(dexn)=yr >*/
			enelem_1.ye1[dexn - 1] = yr;
/* SOURCE runinit.for:631 */
/*<       ye1known(dexn)=1 >*/
			ye1known[dexn - 1] = 1;
/* SOURCE runinit.for:632 */
/*<       else >*/
		    } else {
/*                 Value unknown at exterior node. */
/* SOURCE runinit.for:634 */
/*<       write(stdout,2190)usnode >*/
			feq_gen_io_d__71.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__71);
			do_fio(&feq_gen_c_d_1, usnode, (ftnlen)5);
			e_wsfe();
/* SOURCE runinit.for:635 */
/*<       stop'Abnormal stop: errors found.' >*/
			s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:636 */
/*<       endif >*/
		    }
/* SOURCE runinit.for:637 */
/*<       endif >*/
		}
/* SOURCE runinit.for:638 */
/*<       else >*/
	    } else {
/* SOURCE runinit.for:639 */
/*<       write(stdout,2216)icode >*/
		feq_gen_io_d__72.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__72);
		do_fio(&feq_gen_c_d_1, (char *)&icode, (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE runinit.for:640 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:641 */
/*<       endif >*/
	    }
/*          Initial condition at downstream end of branch is known. */
/*          Compute the steady-flow water-surface profile in the */
/*          branch. */
/* SOURCE runinit.for:648 */
/*<       write(stdout,2170)usnb >*/
	    feq_gen_io_d__73.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__73);
	    do_fio(&feq_gen_c_d_1, (char *)&usnb, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE runinit.for:650 */
/*<        >*/
	    sfpsbm_(stdout, &usnb, &fn, &ln, &dn, &uexn, sfac, grav, epsb, &
		    yr, maxit, &zi, feq_gen_dz_for_output_d_, eflag);
/* SOURCE runinit.for:654 */
/*<       if(eflag.ne.0)stop'Abnormal stop: errors found.' >*/
	    if (*eflag != 0) {
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
	    }
/* SOURCE runinit.for:655 */
/*<       endif >*/
	}
/* SOURCE runinit.for:656 */
/*<       else >*/
    } else {
/*         2-D table is involved in defining water-surface elevation */
/*         at a free node. */
/* SOURCE runinit.for:660 */
/*<       if(icode.eq.6)then >*/
	if (icode == 6) {
/*           Find the stage for given flow in a 2-D table. */
/* SOURCE runinit.for:662 */
/*<       if(snode.le.0.or.snode.gt.nex)then >*/
	    if (snode <= 0 || snode > *nex) {
/* SOURCE runinit.for:663 */
/*<       write(stdout,3001)usnode >*/
		feq_gen_io_d__74.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__74);
		do_fio(&feq_gen_c_d_1, usnode, (ftnlen)5);
		e_wsfe();
/* SOURCE runinit.for:664 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:665 */
/*<       else >*/
	    } else {
/*             SNODE valid here. */
/* SOURCE runinit.for:667 */
/*<       if(ye1(snode).gt.0.0)then >*/
		if (enelem_1.ye1[snode - 1] > (float)0.) {
/*               Value is known at exterior node */
/* SOURCE runinit.for:669 */
/*<       dexn=upsnod >*/
		    dexn = upsnod;
/* SOURCE runinit.for:670 */
/*<       callfnd5(stdout,6,dexn,snode,emc,ept,ipnt) >*/
		    fnd5_(stdout, &feq_gen_c_d_6, &dexn, &snode, &emc[1], ept, &ipnt);
/* SOURCE runinit.for:674 */
/*<       yl=selev-ze(dexn) >*/
		    yl = static_cast<double>(selev) - enelem_1.ze[dexn - 1];
/* SOURCE runinit.for:675 */
/*<       yr=ye1(snode) >*/
		    yr = enelem_1.ye1[snode - 1];
/* SOURCE runinit.for:676 */
/*<       callcd56qy(stdout,ipnt,nex,jtime,emc,maxit,yr,epsb,qeps,ept,yl) >*/
		    cd56qy_(stdout, &ipnt, nex, jtime, &emc[1], maxit, &yr, 
			    epsb, qeps, ept, &yl);
/* SOURCE runinit.for:681 */
/*<       ye1(dexn)=ye2(dexn) >*/
		    enelem_1.ye1[dexn - 1] = enelem_1.ye2[dexn - 1];
/* SOURCE runinit.for:682 */
/*<       ye1known(dexn)=1 >*/
		    ye1known[dexn - 1] = 1;
/* SOURCE runinit.for:683 */
/*<       else >*/
		} else {
/*               Value unknown at exterior node. */
/* SOURCE runinit.for:685 */
/*<       write(stdout,2190)usnode >*/
		    feq_gen_io_d__75.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__75);
		    do_fio(&feq_gen_c_d_1, usnode, (ftnlen)5);
		    e_wsfe();
/* SOURCE runinit.for:686 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:687 */
/*<       endif >*/
		}
/* SOURCE runinit.for:689 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:691 */
/*<       else >*/
	} else {
/* SOURCE runinit.for:692 */
/*<       write(stdout,2216)icode >*/
	    feq_gen_io_d__76.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__76);
	    do_fio(&feq_gen_c_d_1, (char *)&icode, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE runinit.for:693 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:694 */
/*<       endif >*/
	}
/* SOURCE runinit.for:695 */
/*<       endif >*/
    }
/* SOURCE runinit.for:698 */
/*<       goto160 >*/
    goto L160;
/* SOURCE runinit.for:700 */
/*<   200 continue >*/
L200:
/*     ASSIGN VARIABLES FOR EXTERIOR NODES */
/* SOURCE runinit.for:704 */
/*<       do500i=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:705 */
/*<       if(y1(brpt(3,i)).lt.0.0)then >*/
	if (bnelem_1.y1[brpt[(feq_gen_i_d_ << 3) + 3] - 1] < (float)0.) {
/* SOURCE runinit.for:706 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE runinit.for:707 */
/*<       write(stdout,3005)getusb(i) >*/
	    feq_gen_io_d__77.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__77);
	    feq_gen_i_d_2 = getusb_(&feq_gen_i_d_);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_2, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE runinit.for:708 */
/*<       goto500 >*/
	    goto L500;
/* SOURCE runinit.for:709 */
/*<       endif >*/
	}
/* SOURCE runinit.for:711 */
/*<       ye1(brpt(5,i))=y1(brpt(3,i)) >*/
	enelem_1.ye1[brpt[(feq_gen_i_d_ << 3) + 5] - 1] = bnelem_1.y1[brpt[(feq_gen_i_d_ << 3) 
		+ 3] - 1];
/* SOURCE runinit.for:712 */
/*<       ye1(brpt(6,i))=y1(brpt(4,i)) >*/
	enelem_1.ye1[brpt[(feq_gen_i_d_ << 3) + 6] - 1] = bnelem_1.y1[brpt[(feq_gen_i_d_ << 3) 
		+ 4] - 1];
/* SOURCE runinit.for:713 */
/*<       te1(brpt(5,i))=t1(brpt(3,i)) >*/
	enelem_1.te1[brpt[(feq_gen_i_d_ << 3) + 5] - 1] = bnelem_1.t1[brpt[(feq_gen_i_d_ << 3) 
		+ 3] - 1];
/* SOURCE runinit.for:714 */
/*<       te2(brpt(6,i))=t1(brpt(4,i)) >*/
	enelem_1.te2[brpt[(feq_gen_i_d_ << 3) + 6] - 1] = bnelem_1.t1[brpt[(feq_gen_i_d_ << 3) 
		+ 4] - 1];
/* SOURCE runinit.for:715 */
/*<       ae1(brpt(5,i))=a1(brpt(3,i)) >*/
	enelem_1.ae1[brpt[(feq_gen_i_d_ << 3) + 5] - 1] = bnelem_1.a1[brpt[(feq_gen_i_d_ << 3) 
		+ 3] - 1];
/* SOURCE runinit.for:716 */
/*<       ae1(brpt(6,i))=a1(brpt(4,i)) >*/
	enelem_1.ae1[brpt[(feq_gen_i_d_ << 3) + 6] - 1] = bnelem_1.a1[brpt[(feq_gen_i_d_ << 3) 
		+ 4] - 1];
/* SOURCE runinit.for:717 */
/*<   500 continue >*/
L500:
	;
    }
/* SOURCE runinit.for:719 */
/*<       if(eflag.gt.0)then >*/
    if (*eflag > 0) {
/* SOURCE runinit.for:720 */
/*<       write(stdout,2160) >*/
	feq_gen_io_d__78.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__78);
	e_wsfe();
/* SOURCE runinit.for:721 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:722 */
/*<       endif >*/
    }
/*     GET INITIAL VOLUMES FOR RESERVIORS */
/* SOURCE runinit.for:725 */
/*<       do505i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:726 */
/*<       if(exnodt(3,i).eq.-1)then >*/
	if (exnodt[feq_gen_i_d_ * 9 + 3] == -1) {
/* SOURCE runinit.for:727 */
/*<       adrs=exnodt(4,i) >*/
	    adrs = exnodt[feq_gen_i_d_ * 9 + 4];
/* SOURCE runinit.for:728 */
/*<       arg=ye1(i) >*/
	    arg = enelem_1.ye1[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:729 */
/*<       calllktab(adrs,arg,0,vol,ntab,pdv) >*/
	    lktab_(&adrs, &arg, &feq_gen_c_d_0, &vol, &ntab, &pdv);
/* SOURCE runinit.for:732 */
/*<       ae1(i)=-vol >*/
	    enelem_1.ae1[feq_gen_i_d_ - 1] = -vol;
/*         STORE THE SURFACE AREA IN TE1. */
/* SOURCE runinit.for:734 */
/*<       te1(i)=pdv >*/
	    enelem_1.te1[feq_gen_i_d_ - 1] = pdv;
/* SOURCE runinit.for:735 */
/*<       elseif(exnodt(3,i).eq.0)then >*/
	} else if (exnodt[feq_gen_i_d_ * 9 + 3] == 0) {
/*         Clear all values to avoid errors when checking */
/*         for undefined variables */
/* SOURCE runinit.for:738 */
/*<       ae1(i)=0.0 >*/
	    enelem_1.ae1[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE runinit.for:739 */
/*<       ae2(i)=0.0 >*/
	    enelem_1.ae2[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE runinit.for:740 */
/*<       te1(i)=0.0 >*/
	    enelem_1.te1[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE runinit.for:741 */
/*<       te2(i)=0.0 >*/
	    enelem_1.te2[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE runinit.for:742 */
/*<       endif >*/
	}
/* SOURCE runinit.for:743 */
/*<   505 continue >*/
/* L505: */
    }
/* SOURCE runinit.for:746 */
/*<       do510i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:747 */
/*<       ye2(i)=ye1(i) >*/
	enelem_1.ye2[feq_gen_i_d_ - 1] = enelem_1.ye1[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:748 */
/*<       ae2(i)=ae1(i) >*/
	enelem_1.ae2[feq_gen_i_d_ - 1] = enelem_1.ae1[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:749 */
/*<       qe2(i)=qe1(i) >*/
	enelem_1.qe2[feq_gen_i_d_ - 1] = enelem_1.qe1[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:750 */
/*<   510 continue >*/
/* L510: */
    }
/*     COMPUTE CURVILINEAR ELEMENTS FOR THOSE BRANCHES NEEDING THEM. */
/*     Set the others to the value of 1.0 to avoid errors when */
/*     checking for undefined variables. */
/* SOURCE runinit.for:758 */
/*<       do514i=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:759 */
/*<       fn=brpt(3,i) >*/
	fn = brpt[(feq_gen_i_d_ << 3) + 3];
/* SOURCE runinit.for:760 */
/*<       ln=brpt(4,i) >*/
	ln = brpt[(feq_gen_i_d_ << 3) + 4];
/* SOURCE runinit.for:761 */
/*<       geq=geqvec(i) >*/
	geq = bnothr_1.geqvec[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:762 */
/*<       if(geq.eq.3.or.geq.eq.4)then >*/
	if (geq == 3 || geq == 4) {
/* SOURCE runinit.for:763 */
/*<       do512j=fn,ln >*/
	    feq_gen_i_d_2 = ln;
	    for (j = fn; j <= feq_gen_i_d_2; ++j) {
/* SOURCE runinit.for:764 */
/*<       y=y2(j) >*/
		y = bnelem_1.y2[j - 1];
/* SOURCE runinit.for:765 */
/*<       adrs=nsec(j) >*/
		adrs = bnothr_1.nsec[j - 1];
/* SOURCE runinit.for:766 */
/*<       callxlkt23(adrs,y,a,t,dt,ak,dk,b,db,ma,dma,mqt,dmq) >*/
		xlkt23_(&adrs, &y, &a, &t, &dt, &ak, &dk, &b, &db, &ma, &dma, 
			&mqt, &dmq);
/* SOURCE runinit.for:770 */
/*<       ma1(j)=ma >*/
		bnelem_1.ma1[j - 1] = ma;
/* SOURCE runinit.for:771 */
/*<       ma2(j)=ma >*/
		bnelem_1.ma2[j - 1] = ma;
/* SOURCE runinit.for:772 */
/*<       mq1(j)=mqt >*/
		bnelem_1.mq1[j - 1] = mqt;
/* SOURCE runinit.for:773 */
/*<       mq2(j)=mqt >*/
		bnelem_1.mq2[j - 1] = mqt;
/* SOURCE runinit.for:774 */
/*<   512 continue >*/
/* L512: */
	    }
/* SOURCE runinit.for:775 */
/*<       else >*/
	} else {
/* SOURCE runinit.for:776 */
/*<       do513j=fn,ln >*/
	    feq_gen_i_d_2 = ln;
	    for (j = fn; j <= feq_gen_i_d_2; ++j) {
/* SOURCE runinit.for:777 */
/*<       ma1(j)=1.0 >*/
		bnelem_1.ma1[j - 1] = (float)1.;
/* SOURCE runinit.for:778 */
/*<       ma2(j)=1.0 >*/
		bnelem_1.ma2[j - 1] = (float)1.;
/* SOURCE runinit.for:779 */
/*<       mq1(j)=1.0 >*/
		bnelem_1.mq1[j - 1] = (float)1.;
/* SOURCE runinit.for:780 */
/*<       mq2(j)=1.0 >*/
		bnelem_1.mq2[j - 1] = (float)1.;
/* SOURCE runinit.for:781 */
/*<   513 continue >*/
/* L513: */
	    }
/* SOURCE runinit.for:783 */
/*<       endif >*/
	}
/* SOURCE runinit.for:784 */
/*<   514 continue >*/
/* L514: */
    }
/*     Check for a branch having values that are not set.  Y1(*) was set */
/*     to a large negative value at start. */
/* SOURCE runinit.for:789 */
/*<       do950nbr=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (nbr = 1; nbr <= feq_gen_i_d_1; ++nbr) {
/* SOURCE runinit.for:790 */
/*<       fn=brpt(3,nbr) >*/
	fn = brpt[(nbr << 3) + 3];
/* SOURCE runinit.for:791 */
/*<       ln=brpt(4,nbr) >*/
	ln = brpt[(nbr << 3) + 4];
/* SOURCE runinit.for:792 */
/*<       do945j=fn,ln >*/
	feq_gen_i_d_2 = ln;
	for (j = fn; j <= feq_gen_i_d_2; ++j) {
/* SOURCE runinit.for:793 */
/*<       if(y1(j).lt.0.0)then >*/
	    if (bnelem_1.y1[j - 1] < (float)0.) {
/* SOURCE runinit.for:794 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE runinit.for:795 */
/*<       write(stdout,3005)getusb(nbr) >*/
		feq_gen_io_d__96.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__96);
		feq_gen_i_d_3 = getusb_(&nbr);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_3, (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE runinit.for:796 */
/*<       goto950 >*/
		goto L950;
/* SOURCE runinit.for:797 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:798 */
/*<   945 continue >*/
/* L945: */
	}
/* SOURCE runinit.for:799 */
/*<   950 continue >*/
L950:
	;
    }
/*     Now scan the network matrix control vector for EqZ instructions */
/*     and make the assignments if one of the nodes is unknown.  This */
/*     should make assignments to free nodes only since all */
/*     exterior nodes on a branch should be computed in the initial */
/*     conditions computations. */
/* SOURCE runinit.for:807 */
/*<       if(eflag.eq.0)then >*/
    if (*eflag == 0) {
/*       Update YE1KNOWN to reflect any values that have been set */
/*       in the course of the branch and LPR computations.  Some */
/*       dummy branches may have values set as well as needed */
/*       in computing other information. */
/* SOURCE runinit.for:812 */
/*<       do955j=1,nex >*/
	feq_gen_i_d_1 = *nex;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE runinit.for:813 */
/*<       if(ye1(j).gt.-1.e10)then >*/
	    if (enelem_1.ye1[j - 1] > (float)-1e10) {
/* SOURCE runinit.for:814 */
/*<       ye1known(j)=1 >*/
		ye1known[j - 1] = 1;
/* SOURCE runinit.for:815 */
/*<       else >*/
	    } else {
/* SOURCE runinit.for:816 */
/*<       ye1known(j)=0 >*/
		ye1known[j - 1] = 0;
/* SOURCE runinit.for:817 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:818 */
/*<   955 continue >*/
/* L955: */
	}
/* SOURCE runinit.for:820 */
/*<       calldoeqz(stdout,nbra,nbn,nex,exnodt,emc,ept,ye1known,eflag) >*/
	doeqz_(stdout, nbra, nbn, nex, &exnodt[10], &emc[1], ept, ye1known, 
		eflag);
/* SOURCE runinit.for:823 */
/*<       endif >*/
    }
/*     Check for unknown values that remain and must be set in the initial */
/*     conditions block */
/* SOURCE runinit.for:827 */
/*<       write(stdout,3006) >*/
    feq_gen_io_d__97.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__97);
    e_wsfe();
/* SOURCE runinit.for:828 */
/*<       idum=0 >*/
    *idum = 0;
/* SOURCE runinit.for:829 */
/*<       do960j=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE runinit.for:830 */
/*<       if(ye1known(j).eq.0)then >*/
	if (ye1known[j - 1] == 0) {
/*         Check if the other end is known. */
/* SOURCE runinit.for:832 */
/*<       if(exnodt(3,j).eq.0)then >*/
	    if (exnodt[j * 9 + 3] == 0) {
/* SOURCE runinit.for:833 */
/*<       if(exnodt(4,j).gt.0)then >*/
		if (exnodt[j * 9 + 4] > 0) {
/*             We have a node on a dummy branch. */
/* SOURCE runinit.for:835 */
/*<       if(ye1known(exnodt(4,j)).eq.1)then >*/
		    if (ye1known[exnodt[j * 9 + 4] - 1] == 1) {
/*               Other end is known. */
/* SOURCE runinit.for:837 */
/*<       ye1(j)=ye1(exnodt(4,j))+ze(exnodt(4,j))-ze(j) >*/
			enelem_1.ye1[j - 1] = static_cast<double>(static_cast<double>(enelem_1.ye1[exnodt[j * 9 + 4] 
				- 1]) + enelem_1.ze[exnodt[j * 9 + 4] - 1]) - 
				enelem_1.ze[j - 1];
/* SOURCE runinit.for:838 */
/*<       else >*/
		    } else {
/* SOURCE runinit.for:839 */
/*<       idum=1 >*/
			*idum = 1;
/* SOURCE runinit.for:840 */
/*<       write(stdout,*)' Node: ',getusn(j),' is unknown' >*/
			feq_gen_io_d__98.ciunit = *stdout;
			s_wsle(&feq_gen_io_d__98);
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Node: "), (ftnlen)7);
			getusn_(feq_gen_ch_d_2, (ftnlen)5, &j);
			s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" is unknown"), (ftnlen)11);
			e_wsle();
/* SOURCE runinit.for:841 */
/*<       endif >*/
		    }
/* SOURCE runinit.for:842 */
/*<       endif >*/
		}
/* SOURCE runinit.for:843 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:844 */
/*<       endif >*/
	}
/* SOURCE runinit.for:845 */
/*<   960 continue >*/
/* L960: */
    }
/* SOURCE runinit.for:846 */
/*<       if(idum.gt.0)then >*/
    if (*idum > 0) {
/* SOURCE runinit.for:847 */
/*<       write(stdout,3010) >*/
	feq_gen_io_d__99.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__99);
	e_wsfe();
/* SOURCE runinit.for:848 */
/*<       stop'Adjust initial conditions for free nodes.' >*/
	s_stop(const_cast<char*>("Adjust initial conditions for free nodes."), (ftnlen)41);
/* SOURCE runinit.for:849 */
/*<       endif >*/
    }
/* SOURCE runinit.for:850 */
/*<       write(stdout,3008) >*/
    feq_gen_io_d__100.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__100);
    e_wsfe();
/* SOURCE runinit.for:853 */
/*<       if(eflag.eq.0)goto520 >*/
    if (*eflag == 0) {
	goto L520;
    }
/* SOURCE runinit.for:854 */
/*<       write(stdout,2160) >*/
    feq_gen_io_d__101.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__101);
    e_wsfe();
/* SOURCE runinit.for:855 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:856 */
/*<   520 continue >*/
L520:
/* SOURCE runinit.for:858 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:860 */
/*<   991 continue >*/
L991:
/* SOURCE runinit.for:861 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__102.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__102);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE runinit.for:862 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__103.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__103);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE runinit.for:863 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:864 */
/*<       end >*/
    return 0;
} /* bckwtr_ */

#undef rdum
#undef idum





/* SOURCE runinit.for:868 */
/*<       subroutinebfinit(dt) >*/
/* Subroutine */ int bfinit_(doublereal *dt)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *BUG:04* INVALID JTIME FOR TSF RECORD JT\
IME = \002,1pd25.16)";
    static char fmt_52[] = "(/,\002Forecasting with DTSF: Start time NOT res\
et to event start\002)";
    static char fmt_54[] = "(\002 Skipping event with start jtime=\002,f17.1\
0,\002 and end jtime=\002,f17.10,/,5x,\002 that does not contain the current\
 run start jtime=\002,f17.10,\002.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    static doublereal equiv_0[64];

    /* Builtin functions */
    integer s_rdue(cilist *), do_uio(integer *, char *, ftnlen), e_rdue(), 
	    s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j;
    doublereal ri[128], dyf;
    integer mnt, dyt, yrt, wyr, fsmn, fsdy, fsyr;
    extern integer iwyr_(integer *, integer *);
    doublereal tsfdt;
    extern /* Subroutine */ int lktsf_(integer *, doublereal *, doublereal *, 
	    doublereal *, integer *);
#define dummy (equiv_0)
    doublereal fsfrac;
#define runoff (feq::BitView<real>(equiv_0, sizeof(equiv_0)))
    extern integer lpyear_(integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__106 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__112 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__113 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__114 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__119 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__120 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__122 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Initialize the TSF buffer system and initialize the */
/*     time as given in the TSF. */
/* SOURCE runinit.for:874 */
/*<       implicitnone >*/
/* SOURCE runinit.for:876 */
/*<       real*8dt >*/
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE runinit.for:878 */
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
/* INCLUDE runinit.for:879 */
/* *********************************************************************** */
/* SOURCE tsfcom.cmn:2 */
/*<        >*/
/* SOURCE tsfcom.cmn:6 */
/*<        >*/
/* SOURCE tsfcom.cmn:8 */
/*<       integerbwyr(mndbuf),bord(mndbuf),gend(0:mxgage),gstart(0:mxgage) >*/
/* SOURCE tsfcom.cmn:10 */
/*<       realdtend >*/
/* SOURCE tsfcom.cmn:11 */
/*<       realtriba(mxr_triba,mxn_lu_g),tsfrat(mndbuf,mndifa),tafac(mnbra) >*/
/* SOURCE tsfcom.cmn:14 */
/*<       real*8tsfbuf(mndbuf,mndifa),bjtime(mndbuf) >*/
/* *********************************************************************** */
/* INCLUDE runinit.for:880 */
/* ********************************************************************** */
/* SOURCE julian.cmn:3 */
/*<        >*/
/* SOURCE julian.cmn:8 */
/*<       integeryr,mn,dy,syr,smn,sdy,eyr,emn,edy,reset,leap,dmyear,dmmn >*/
/* SOURCE julian.cmn:10 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE runinit.for:881 */
/* ********************************************************************** */
/* SOURCE difcom.cmn:3 */
/*<       common/difcom/clsr1,clsr2 >*/
/* SOURCE difcom.cmn:5 */
/*<       real*8clsr1(mndifa),clsr2(mndifa) >*/
/* ********************************************************************** */
/* INCLUDE runinit.for:882 */
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
/* SOURCE runinit.for:885 */
/*<       integerdyt,i,j,mnt,yrt,fsyr,fsmn,fsdy,wyr >*/
/* SOURCE runinit.for:886 */
/*<       realrunoff(mndifa) >*/
/* SOURCE runinit.for:887 */
/*<       real*8dummy,dyf,ri(mndifa),tsfdt,fsfrac >*/
/*     + + + EQUIVALENCES + + + */
/* SOURCE runinit.for:890 */
/*<       equivalence(dummy,runoff(1)) >*/
/*     + + + INTRINSICS + + + */
/* SOURCE runinit.for:893 */
/*<       intrinsicdabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE runinit.for:896 */
/*<       integeriwyr,lpyear >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE runinit.for:899 */
/*<       externaliwyr,lpyear,lktsf >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE runinit.for:902 */
/*<    50  >*/
/* SOURCE runinit.for:904 */
/*<    52  >*/
/* SOURCE runinit.for:906 */
/*<    54  >*/
/* *********************************************************************** */
/*     DEFINE NUMBER OF BUFFERS */
/* SOURCE runinit.for:912 */
/*<       nbuff=mndbuf >*/
/* L50: */
/* L52: */
/* L54: */
    tsfcom_1.nbuff = 512;
/*     GET FIRST DATA RECORD FROM THE TSF-DOCUMENTATION RECORDS */
/*     HAVE BEEN READ PREVIOUSLY */
/* SOURCE runinit.for:917 */
/*<    90 continue >*/
L90:
/* SOURCE runinit.for:919 */
/*<        >*/
    feq_gen_io_d__106.ciunit = tsfcom_1.tsfdsn;
    feq_gen_io_d__106.cirec = tsfcom_1.feq_gen_dtsf_rec_d_;
    s_rdue(&feq_gen_io_d__106);
    do_uio(&feq_gen_c_d_1, (char *)&tsfcom_1.bjtime[0], (ftnlen)sizeof(doublereal));
    do_uio(&feq_gen_c_d_1, (char *)&fsfrac, (ftnlen)sizeof(doublereal));
    do_uio(&feq_gen_c_d_1, (char *)&fsyr, (ftnlen)sizeof(integer));
    do_uio(&feq_gen_c_d_1, (char *)&fsmn, (ftnlen)sizeof(integer));
    do_uio(&feq_gen_c_d_1, (char *)&fsdy, (ftnlen)sizeof(integer));
    feq_gen_i_d_1 = tsfcom_1.ndfval;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
	do_uio(&feq_gen_c_d_1, (char *)runoff.lease(j - 1).data(), (ftnlen)sizeof(real));
    }
    e_rdue();
/* SOURCE runinit.for:922 */
/*<       dtsf_rec=dtsf_rec+1 >*/
    ++tsfcom_1.feq_gen_dtsf_rec_d_;
/* SOURCE runinit.for:923 */
/*<       do105j=1,ndfval >*/
    feq_gen_i_d_1 = tsfcom_1.ndfval;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE runinit.for:924 */
/*<       tsfbuf(1,j)=runoff(j) >*/
	tsfcom_1.tsfbuf[(j << 9) - 512] = runoff[j - 1];
/* SOURCE runinit.for:925 */
/*<   105 continue >*/
/* L105: */
    }
/* SOURCE runinit.for:927 */
/*<       if(lagtsf.gt.0)then >*/
    if (tsfcom_1.lagtsf > 0) {
/*         INITIALIZE TSFRAT TO STANDARD VALUE OF 0.0 */
/* SOURCE runinit.for:929 */
/*<       do107j=1,ndfval >*/
	feq_gen_i_d_1 = tsfcom_1.ndfval;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE runinit.for:930 */
/*<       tsfrat(1,j)=0.0 >*/
	    tsfcom_1.tsfrat[(j << 9) - 512] = (float)0.;
/* SOURCE runinit.for:931 */
/*<   107 continue >*/
/* L107: */
	}
/* SOURCE runinit.for:932 */
/*<       endif >*/
    }
/* SOURCE runinit.for:934 */
/*<       if(bjtime(1).lt.0.d0)goto100 >*/
    if (tsfcom_1.bjtime[0] < 0.) {
	goto L100;
    }
/* SOURCE runinit.for:936 */
/*<       if(bjtime(1).eq.0.d0)then >*/
    if (tsfcom_1.bjtime[0] == 0.) {
/* SOURCE runinit.for:937 */
/*<       reset=-1 >*/
	julian_1.reset = -1;
/* SOURCE runinit.for:938 */
/*<       return >*/
	return 0;
/* SOURCE runinit.for:939 */
/*<       endif >*/
    }
/* SOURCE runinit.for:940 */
/*<       write(std6,50)bjtime(1) >*/
    feq_gen_io_d__112.ciunit = feq_gen_stdun_com_d_1.std6;
    s_wsfe(&feq_gen_io_d__112);
    do_fio(&feq_gen_c_d_1, (char *)&tsfcom_1.bjtime[0], (ftnlen)sizeof(doublereal));
    e_wsfe();
/* SOURCE runinit.for:941 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:942 */
/*<   100 continue >*/
L100:
/*       SET THE END TIME FOR THIS SEGMENT(FRAME) AND CLEAR BUFFER ENTRY */
/* SOURCE runinit.for:945 */
/*<       ejtime=dummy >*/
    julian_1.ejtime = *dummy;
/* SOURCE runinit.for:946 */
/*<       tsfbuf(1,1)=0.d0 >*/
    tsfcom_1.tsfbuf[0] = 0.;
/* SOURCE runinit.for:948 */
/*<       leap=lpyear(yr) >*/
    julian_1.leap = lpyear_(&julian_1.yr);
/*       MAKE SURE THAT END OF THIS SEGMENT DOES NOT EXTEND BEYOND */
/*       END OF RUN */
/* SOURCE runinit.for:953 */
/*<       if(ejtime.gt.vjtime)then >*/
    if (julian_1.ejtime > julian_1.vjtime) {
/* SOURCE runinit.for:954 */
/*<       ejtime=vjtime >*/
	julian_1.ejtime = julian_1.vjtime;
/* SOURCE runinit.for:955 */
/*<       endif >*/
    }
/* SOURCE runinit.for:957 */
/*<       bjtime(1)=dabs(bjtime(1)) >*/
    tsfcom_1.bjtime[0] = abs(tsfcom_1.bjtime[0]);
/*       See if we can get a start time later than the start time */
/*       of the event when we have only one event in the DTSF */
/* SOURCE runinit.for:960 */
/*<       if(frcst==1)then >*/
    if (tsfcom_1.frcst == 1) {
/* SOURCE runinit.for:961 */
/*<       write(std6,52) >*/
	feq_gen_io_d__113.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsfe(&feq_gen_io_d__113);
	e_wsfe();
/* SOURCE runinit.for:963 */
/*<       else >*/
    } else {
/* SOURCE runinit.for:964 */
/*<       sjtime=bjtime(1) >*/
	julian_1.sjtime = tsfcom_1.bjtime[0];
/* SOURCE runinit.for:965 */
/*<       sfrac=fsfrac >*/
	julian_1.sfrac = fsfrac;
/* SOURCE runinit.for:966 */
/*<       dyfrac=sfrac >*/
	julian_1.dyfrac = julian_1.sfrac;
/* SOURCE runinit.for:967 */
/*<       syr=fsyr >*/
	julian_1.syr = fsyr;
/* SOURCE runinit.for:968 */
/*<       smn=fsmn >*/
	julian_1.smn = fsmn;
/* SOURCE runinit.for:969 */
/*<       sdy=fsdy >*/
	julian_1.sdy = fsdy;
/* SOURCE runinit.for:970 */
/*<       endif >*/
    }
/*       CHECK IF THE START TIME OF THIS EVENT IS AFTER THE ENDING */
/*       TIME SET FOR THE RUN */
/* SOURCE runinit.for:974 */
/*<       if(sjtime.ge.vjtime)then >*/
    if (julian_1.sjtime >= julian_1.vjtime) {
/* SOURCE runinit.for:975 */
/*<       reset=-1 >*/
	julian_1.reset = -1;
/* SOURCE runinit.for:976 */
/*<       return >*/
	return 0;
/* SOURCE runinit.for:977 */
/*<       endif >*/
    }
/* SOURCE runinit.for:978 */
/*<       if(frcst==0)then >*/
    if (tsfcom_1.frcst == 0) {
/* SOURCE runinit.for:979 */
/*<       if(sjtime.lt.ujtime.and.syr.ne.dmyear)then >*/
	if (julian_1.sjtime < julian_1.ujtime && julian_1.syr != 
		julian_1.dmyear) {
/*           SKIP THIS EVENT */
/* SOURCE runinit.for:981 */
/*<   110 continue >*/
L110:
/* SOURCE runinit.for:982 */
/*<        >*/
	    feq_gen_io_d__114.ciunit = tsfcom_1.tsfdsn;
	    feq_gen_io_d__114.cirec = tsfcom_1.feq_gen_dtsf_rec_d_;
	    s_rdue(&feq_gen_io_d__114);
	    do_uio(&feq_gen_c_d_1, (char *)&tsfcom_1.bjtime[0], (ftnlen)sizeof(
		    doublereal));
	    do_uio(&feq_gen_c_d_1, (char *)&dyf, (ftnlen)sizeof(doublereal));
	    do_uio(&feq_gen_c_d_1, (char *)&yrt, (ftnlen)sizeof(integer));
	    do_uio(&feq_gen_c_d_1, (char *)&mnt, (ftnlen)sizeof(integer));
	    do_uio(&feq_gen_c_d_1, (char *)&dyt, (ftnlen)sizeof(integer));
	    feq_gen_i_d_1 = tsfcom_1.ndfval;
	    for (j = 1; j <= feq_gen_i_d_1; ++j) {
		do_uio(&feq_gen_c_d_1, (char *)runoff.lease(j - 1).data(), (ftnlen)sizeof(real));
	    }
	    e_rdue();
/* SOURCE runinit.for:984 */
/*<       dtsf_rec=dtsf_rec+1 >*/
	    ++tsfcom_1.feq_gen_dtsf_rec_d_;
/* SOURCE runinit.for:985 */
/*<       if(bjtime(1).ne.ejtime)then >*/
	    if (tsfcom_1.bjtime[0] != julian_1.ejtime) {
/* SOURCE runinit.for:986 */
/*<       goto110 >*/
		goto L110;
/* SOURCE runinit.for:987 */
/*<       else >*/
	    } else {
/* SOURCE runinit.for:988 */
/*<       goto90 >*/
		goto L90;
/* SOURCE runinit.for:989 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:990 */
/*<       endif >*/
	}
/* SOURCE runinit.for:991 */
/*<       else >*/
    } else {
/*         Here we skip over events until we find the one containing */
/*         the value of sjtime and we assume that this will be the single */
/*         event involved. */
/*          IF(SJTIME.LT.UJTIME.AND.SYR.NE.DMYEAR) THEN */
/* SOURCE runinit.for:996 */
/*<       if(.not.(sjtime<=ejtime.and.sjtime>=bjtime(1)))then >*/
	if (! (julian_1.sjtime <= julian_1.ejtime && julian_1.sjtime >= 
		tsfcom_1.bjtime[0])) {
/*           SKIP THIS EVENT */
/* SOURCE runinit.for:998 */
/*<       write(std6,54)bjtime(1),ejtime,sjtime >*/
	    feq_gen_io_d__119.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsfe(&feq_gen_io_d__119);
	    do_fio(&feq_gen_c_d_1, (char *)&tsfcom_1.bjtime[0], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&feq_gen_c_d_1, (char *)&julian_1.ejtime, (ftnlen)sizeof(doublereal)
		    );
	    do_fio(&feq_gen_c_d_1, (char *)&julian_1.sjtime, (ftnlen)sizeof(doublereal)
		    );
	    e_wsfe();
/* SOURCE runinit.for:999 */
/*<   120 continue >*/
L120:
/* SOURCE runinit.for:1000 */
/*<        >*/
	    feq_gen_io_d__120.ciunit = tsfcom_1.tsfdsn;
	    feq_gen_io_d__120.cirec = tsfcom_1.feq_gen_dtsf_rec_d_;
	    s_rdue(&feq_gen_io_d__120);
	    do_uio(&feq_gen_c_d_1, (char *)&tsfcom_1.bjtime[0], (ftnlen)sizeof(
		    doublereal));
	    do_uio(&feq_gen_c_d_1, (char *)&dyf, (ftnlen)sizeof(doublereal));
	    do_uio(&feq_gen_c_d_1, (char *)&yrt, (ftnlen)sizeof(integer));
	    do_uio(&feq_gen_c_d_1, (char *)&mnt, (ftnlen)sizeof(integer));
	    do_uio(&feq_gen_c_d_1, (char *)&dyt, (ftnlen)sizeof(integer));
	    feq_gen_i_d_1 = tsfcom_1.ndfval;
	    for (j = 1; j <= feq_gen_i_d_1; ++j) {
		do_uio(&feq_gen_c_d_1, (char *)runoff.lease(j - 1).data(), (ftnlen)sizeof(real));
	    }
	    e_rdue();
/* SOURCE runinit.for:1002 */
/*<       dtsf_rec=dtsf_rec+1 >*/
	    ++tsfcom_1.feq_gen_dtsf_rec_d_;
/* SOURCE runinit.for:1003 */
/*<       if(bjtime(1).ne.ejtime)then >*/
	    if (tsfcom_1.bjtime[0] != julian_1.ejtime) {
/* SOURCE runinit.for:1004 */
/*<       goto120 >*/
		goto L120;
/* SOURCE runinit.for:1005 */
/*<       else >*/
	    } else {
/* SOURCE runinit.for:1006 */
/*<       goto90 >*/
		goto L90;
/* SOURCE runinit.for:1007 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:1008 */
/*<       endif >*/
	}
/* SOURCE runinit.for:1009 */
/*<       endif >*/
    }
/* SOURCE runinit.for:1012 */
/*<       bwyr(1)=iwyr(syr,smn) >*/
    tsfcom_1.bwyr[0] = iwyr_(&julian_1.syr, &julian_1.smn);
/*     FILL THE REMAINDER OF THE BUFFER SET */
/* SOURCE runinit.for:1016 */
/*<       do200i=2,nbuff >*/
    feq_gen_i_d_1 = tsfcom_1.nbuff;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:1018 */
/*<        >*/
	feq_gen_io_d__122.ciunit = tsfcom_1.tsfdsn;
	feq_gen_io_d__122.cirec = tsfcom_1.feq_gen_dtsf_rec_d_;
	s_rdue(&feq_gen_io_d__122);
	do_uio(&feq_gen_c_d_1, (char *)&tsfcom_1.bjtime[feq_gen_i_d_ - 1], (ftnlen)sizeof(
		doublereal));
	do_uio(&feq_gen_c_d_1, (char *)&dyf, (ftnlen)sizeof(doublereal));
	do_uio(&feq_gen_c_d_1, (char *)&yrt, (ftnlen)sizeof(integer));
	do_uio(&feq_gen_c_d_1, (char *)&mnt, (ftnlen)sizeof(integer));
	do_uio(&feq_gen_c_d_1, (char *)&dyt, (ftnlen)sizeof(integer));
	feq_gen_i_d_2 = tsfcom_1.ndfval;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
	    do_uio(&feq_gen_c_d_1, (char *)runoff.lease(j - 1).data(), (ftnlen)sizeof(real));
	}
	e_rdue();
/* SOURCE runinit.for:1020 */
/*<       dtsf_rec=dtsf_rec+1 >*/
	++tsfcom_1.feq_gen_dtsf_rec_d_;
/* SOURCE runinit.for:1021 */
/*<       do106j=1,ndfval >*/
	feq_gen_i_d_2 = tsfcom_1.ndfval;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE runinit.for:1022 */
/*<       ri(j)=runoff(j) >*/
	    ri[j - 1] = runoff[j - 1];
/* SOURCE runinit.for:1023 */
/*<   106 continue >*/
/* L106: */
	}
/* SOURCE runinit.for:1025 */
/*<       bwyr(i)=iwyr(yrt,mnt) >*/
	tsfcom_1.bwyr[feq_gen_i_d_ - 1] = iwyr_(&yrt, &mnt);
/*       COMPUTE CUMULATIVE VALUES */
/* SOURCE runinit.for:1029 */
/*<       tsfdt=86400.e0*(bjtime(i)-bjtime(i-1)) >*/
	tsfdt = (tsfcom_1.bjtime[feq_gen_i_d_ - 1] - tsfcom_1.bjtime[feq_gen_i_d_ - 2]) * (
		float)86400.;
/* SOURCE runinit.for:1030 */
/*<       if(lagtsf.eq.0)then >*/
	if (tsfcom_1.lagtsf == 0) {
/* SOURCE runinit.for:1031 */
/*<       do150j=1,ndfval >*/
	    feq_gen_i_d_2 = tsfcom_1.ndfval;
	    for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE runinit.for:1032 */
/*<       tsfbuf(i,j)=tsfbuf(i-1,j)+tsfdt*ri(j) >*/
		tsfcom_1.tsfbuf[feq_gen_i_d_ + (j << 9) - 513] = tsfcom_1.tsfbuf[feq_gen_i_d_ - 
			1 + (j << 9) - 513] + tsfdt * ri[j - 1];
/* SOURCE runinit.for:1033 */
/*<   150 continue >*/
/* L150: */
	    }
/* SOURCE runinit.for:1034 */
/*<       else >*/
	} else {
/* SOURCE runinit.for:1035 */
/*<       tsfdt=0.5*tsfdt >*/
	    tsfdt *= (float).5;
/* SOURCE runinit.for:1036 */
/*<       do160j=1,ndfval >*/
	    feq_gen_i_d_2 = tsfcom_1.ndfval;
	    for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE runinit.for:1037 */
/*<       tsfrat(i,j)=ri(j) >*/
		tsfcom_1.tsfrat[feq_gen_i_d_ + (j << 9) - 513] = ri[j - 1];
/* SOURCE runinit.for:1038 */
/*<       tsfbuf(i,j)=tsfbuf(i-1,j)+tsfdt*(ri(j)+tsfrat(i-1,j)) >*/
		tsfcom_1.tsfbuf[feq_gen_i_d_ + (j << 9) - 513] = tsfcom_1.tsfbuf[feq_gen_i_d_ - 
			1 + (j << 9) - 513] + tsfdt * (ri[j - 1] + 
			tsfcom_1.tsfrat[feq_gen_i_d_ - 1 + (j << 9) - 513]);
/* SOURCE runinit.for:1040 */
/*<   160 continue >*/
/* L160: */
	    }
/* SOURCE runinit.for:1041 */
/*<       endif >*/
	}
/*       Added to try to handle the buffer being larger than an event. */
/*       December 4, 1996. */
/* SOURCE runinit.for:1044 */
/*<       if(bjtime(i).ge.ejtime)then >*/
	if (tsfcom_1.bjtime[feq_gen_i_d_ - 1] >= julian_1.ejtime) {
/*         WE HAVE REACHED THE END OF THE EVENT BEFORE THE END OF THE */
/*         BUFFER.  STOP AT THIS POINT AND LEAVE THE BUFFER ONLY */
/*         PARTIALLY FULL. */
/* SOURCE runinit.for:1048 */
/*<       goto210 >*/
	    goto L210;
/* SOURCE runinit.for:1049 */
/*<       endif >*/
	}
/* SOURCE runinit.for:1050 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE runinit.for:1052 */
/*<   210 continue >*/
L210:
/*     SET DEFAULT LAST ENTRY */
/* SOURCE runinit.for:1056 */
/*<       lentry=1 >*/
    tsfcom_1.lentry = 1;
/* SOURCE runinit.for:1057 */
/*<       lhead=1 >*/
    tsfcom_1.lhead = 1;
/*     SET VALUE OF THE  DIFFUSE FLOW BUFFER */
/* SOURCE runinit.for:1060 */
/*<       calllktsf(std6,sjtime,dt,clsr1,wyr) >*/
    lktsf_(&feq_gen_stdun_com_d_1.std6, &julian_1.sjtime, dt, difcom_1.clsr1, &wyr);
/*      DO 300 I=1,NLUSE */
/*        CLSR1(I) = 0.D0 */
/* 300  CONTINUE */
/* SOURCE runinit.for:1069 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:1071 */
/*<       end >*/
} /* bfinit_ */

#undef runoff
#undef dummy





/* SOURCE runinit.for:1075 */
/*<       subroutinebfinit_dss() >*/
/* Subroutine */ int feq_gen_bfinit_dss_d_()
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *BUG:XXX* Times do not match for runoff \
in \002,\002BFINT_DSS.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_hecdss_block_d_(integer *, char *, integer 
	    *, integer *, char *, doublereal *, integer *, integer *, 
	    doublereal *, real *, integer *, ftnlen, ftnlen);
    integer feq_gen_i_d_, j;
    doublereal jt;
    integer got, need;
    extern integer iwyr_(integer *, integer *);
    doublereal feq_gen_con_fac_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__132 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Initialize the diffuse flows buffer system  when the source is */
/*     one or more HECDSS files. */
/* SOURCE runinit.for:1081 */
/*<       implicitnone >*/
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE runinit.for:1083 */
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
/* INCLUDE runinit.for:1084 */
/* *********************************************************************** */
/* SOURCE tsfcom.cmn:2 */
/*<        >*/
/* SOURCE tsfcom.cmn:6 */
/*<        >*/
/* SOURCE tsfcom.cmn:8 */
/*<       integerbwyr(mndbuf),bord(mndbuf),gend(0:mxgage),gstart(0:mxgage) >*/
/* SOURCE tsfcom.cmn:10 */
/*<       realdtend >*/
/* SOURCE tsfcom.cmn:11 */
/*<       realtriba(mxr_triba,mxn_lu_g),tsfrat(mndbuf,mndifa),tafac(mnbra) >*/
/* SOURCE tsfcom.cmn:14 */
/*<       real*8tsfbuf(mndbuf,mndifa),bjtime(mndbuf) >*/
/* *********************************************************************** */
/* INCLUDE runinit.for:1085 */
/* ********************************************************************** */
/* SOURCE julian.cmn:3 */
/*<        >*/
/* SOURCE julian.cmn:8 */
/*<       integeryr,mn,dy,syr,smn,sdy,eyr,emn,edy,reset,leap,dmyear,dmmn >*/
/* SOURCE julian.cmn:10 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE runinit.for:1086 */
/* ********************************************************************** */
/* SOURCE difcom.cmn:3 */
/*<       common/difcom/clsr1,clsr2 >*/
/* SOURCE difcom.cmn:5 */
/*<       real*8clsr1(mndifa),clsr2(mndifa) >*/
/* ********************************************************************** */
/* INCLUDE runinit.for:1087 */
/* *********************************************************************** */
/* SOURCE dssdif.cmn:2 */
/*<        >*/
/* SOURCE dssdif.cmn:5 */
/*<       common/dssdifc/path_name_diff >*/
/* SOURCE dssdif.cmn:7 */
/*<       character*80path_name_diff(mndifa) >*/
/* SOURCE dssdif.cmn:9 */
/*<       integerdss_index_diff(mxn_ts),time_step_diff(mxn_ts) >*/
/* SOURCE dssdif.cmn:12 */
/*<       realtmpvec(mndbuf+1) >*/
/* SOURCE dssdif.cmn:14 */
/*<       doubleprecisionjtvec(mndbuf+1),tsfdt_dss,half_tsfdt_dss,buf_dt >*/
/* *********************************************************************** */
/* INCLUDE runinit.for:1088 */
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
/* SOURCE runinit.for:1091 */
/*<       integeri,j,got,need >*/
/* SOURCE runinit.for:1092 */
/*<       real*8con_fac,jt >*/
/*     + + + INTRINSICS + + + */
/* SOURCE runinit.for:1096 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE runinit.for:1099 */
/*<       integeriwyr >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE runinit.for:1102 */
/*<       externaliwyr >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE runinit.for:1105 */
/*<    50  >*/
/* *********************************************************************** */
/*     DEFINE NUMBER OF BUFFERS */
/* SOURCE runinit.for:1110 */
/*<       nbuff=mndbuf >*/
/* L50: */
    tsfcom_1.nbuff = 512;
/*     Set the first row of the buffer to zeros and the time to the */
/*     start time of the run.  The buffer will contain cumulative */
/*     values so that the runoff in any time interval can be */
/*     computed by subtraction. */
/* SOURCE runinit.for:1116 */
/*<       do990j=1,nluse >*/
    feq_gen_i_d_1 = tsfcom_1.nluse;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE runinit.for:1117 */
/*<       tsfbuf(1,j)=0.d0 >*/
	tsfcom_1.tsfbuf[(j << 9) - 512] = 0.;
/* SOURCE runinit.for:1118 */
/*<       tsfrat(1,j)=0.0 >*/
	tsfcom_1.tsfrat[(j << 9) - 512] = (float)0.;
/* SOURCE runinit.for:1119 */
/*<   990 continue >*/
/* L990: */
    }
/* SOURCE runinit.for:1120 */
/*<       bjtime(1)=sjtime >*/
    tsfcom_1.bjtime[0] = julian_1.sjtime;
/*     Set 0.75 of the time interval in the diffuse buffer. */
/*     Units are days.  Used to access data from HECDSS to */
/*     avoid getting the same value twice. */
/* SOURCE runinit.for:1125 */
/*<       buf_dt=0.75*dble(time_step_diff(1))/1440.d0 >*/
    dssdif_1.feq_gen_buf_dt_d_ = (doublereal) dssdif_1.feq_gen_time_step_diff_d_[0] * (float)
	    .75 / 1440.;
/*     Compute conversion factor from inches per interval to */
/*     feet per second(english unit system).  Note: Time step */
/*     is in minutes and is the same for all diffuse runoff */
/*     series. */
/* SOURCE runinit.for:1131 */
/*<       con_fac=1.0d0/(720.d0*dble(time_step_diff(1))) >*/
    feq_gen_con_fac_d_ = 1. / ((doublereal) dssdif_1.feq_gen_time_step_diff_d_[0] * 720.);
/* SOURCE runinit.for:1133 */
/*<       do1000j=1,nluse >*/
    feq_gen_i_d_1 = tsfcom_1.nluse;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/*       The run starts at julian time, SJTIME.  However, we do not */
/*       need the value of the starting time point because the */
/*       runoff intensity files are given in terms of depth units */
/*       per interval.   Increment the start time slightly */
/*       to hopefully get the correct  values from the DSS. */
/* SOURCE runinit.for:1139 */
/*<       jt=sjtime+0.75d0/1440.d0 >*/
	jt = julian_1.sjtime + 5.2083333333333333e-4;
/* SOURCE runinit.for:1140 */
/*<       need=nbuff-1 >*/
	need = tsfcom_1.nbuff - 1;
/* SOURCE runinit.for:1141 */
/*<        >*/
	feq_gen_i_d_2 = tsfcom_1.nbuff + 1;
	feq_gen_get_hecdss_block_d_(&feq_gen_stdun_com_d_1.std6, dssdifc_1.feq_gen_path_name_diff_d_ + (
		j - 1) * 80, &dssdif_1.feq_gen_dss_index_diff_d_[j - 1], &
		dssdif_1.feq_gen_time_step_diff_d_[j - 1], const_cast<char*>("PER-CUM "), &jt, &need, &
		got, dssdif_1.jtvec, dssdif_1.tmpvec, &feq_gen_i_d_2, (ftnlen)80, (
		ftnlen)8);
/* SOURCE runinit.for:1145 */
/*<       if(j.eq.1)then >*/
	if (j == 1) {
/*         Store both the times and the values. */
/* SOURCE runinit.for:1147 */
/*<       do100i=1,got >*/
	    feq_gen_i_d_2 = got;
	    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_2; ++feq_gen_i_d_) {
/* SOURCE runinit.for:1148 */
/*<       tsfbuf(i+1,j)=tmpvec(i) >*/
		tsfcom_1.tsfbuf[feq_gen_i_d_ + 1 + (j << 9) - 513] = dssdif_1.tmpvec[
			feq_gen_i_d_ - 1];
/* SOURCE runinit.for:1149 */
/*<       bjtime(i+1)=jtvec(i) >*/
		tsfcom_1.bjtime[feq_gen_i_d_] = dssdif_1.jtvec[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:1150 */
/*<   100 continue >*/
/* L100: */
	    }
/* SOURCE runinit.for:1151 */
/*<       else >*/
	} else {
/*         Store the values and compare the times. */
/* SOURCE runinit.for:1153 */
/*<       do200i=1,got >*/
	    feq_gen_i_d_2 = got;
	    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_2; ++feq_gen_i_d_) {
/* SOURCE runinit.for:1154 */
/*<       tsfbuf(i+1,j)=tmpvec(i) >*/
		tsfcom_1.tsfbuf[feq_gen_i_d_ + 1 + (j << 9) - 513] = dssdif_1.tmpvec[
			feq_gen_i_d_ - 1];
/* SOURCE runinit.for:1155 */
/*<       if(abs(bjtime(i+1)-jtvec(i)).gt.1.d-5)then >*/
		if ((feq_gen_d_d_1 = tsfcom_1.bjtime[feq_gen_i_d_] - dssdif_1.jtvec[feq_gen_i_d_ - 1], 
			abs(feq_gen_d_d_1)) > 1e-5) {
/*             Problem in time steps. */
/* SOURCE runinit.for:1157 */
/*<       write(std6,50) >*/
		    feq_gen_io_d__132.ciunit = feq_gen_stdun_com_d_1.std6;
		    s_wsfe(&feq_gen_io_d__132);
		    e_wsfe();
/* SOURCE runinit.for:1158 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:1159 */
/*<       endif >*/
		}
/* SOURCE runinit.for:1160 */
/*<   200 continue >*/
/* L200: */
	    }
/* SOURCE runinit.for:1161 */
/*<       endif >*/
	}
/* SOURCE runinit.for:1162 */
/*<  1000 continue >*/
/* L1000: */
    }
/* SOURCE runinit.for:1164 */
/*<       bwyr(1)=iwyr(syr,smn) >*/
    tsfcom_1.bwyr[0] = iwyr_(&julian_1.syr, &julian_1.smn);
/*     Form the factors that include unit conversion AND the */
/*     time step.  60.D0 converts from time step in minutes */
/*     to time step in seconds. */
/* SOURCE runinit.for:1169 */
/*<       tsfdt_dss=con_fac*60.d0*dble(time_step_diff(1)) >*/
    dssdif_1.feq_gen_tsfdt_dss_d_ = feq_gen_con_fac_d_ * 60. * (doublereal) 
	    dssdif_1.feq_gen_time_step_diff_d_[0];
/* SOURCE runinit.for:1170 */
/*<       half_tsfdt_dss=0.5d0*tsfdt_dss >*/
    dssdif_1.feq_gen_half_tsfdt_dss_d_ = dssdif_1.feq_gen_tsfdt_dss_d_ * .5;
/* SOURCE runinit.for:1171 */
/*<       do300i=2,nbuff >*/
    feq_gen_i_d_1 = tsfcom_1.nbuff;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:1172 */
/*<       bwyr(i)=bwyr(1) >*/
	tsfcom_1.bwyr[feq_gen_i_d_ - 1] = tsfcom_1.bwyr[0];
/*       COMPUTE CUMULATIVE VALUES */
/* SOURCE runinit.for:1176 */
/*<       if(lagtsf.eq.0)then >*/
	if (tsfcom_1.lagtsf == 0) {
/* SOURCE runinit.for:1177 */
/*<       do250j=1,ndfval >*/
	    feq_gen_i_d_2 = tsfcom_1.ndfval;
	    for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE runinit.for:1178 */
/*<       tsfbuf(i,j)=tsfbuf(i-1,j)+tsfdt_dss*tsfbuf(i,j) >*/
		tsfcom_1.tsfbuf[feq_gen_i_d_ + (j << 9) - 513] = tsfcom_1.tsfbuf[feq_gen_i_d_ - 
			1 + (j << 9) - 513] + dssdif_1.feq_gen_tsfdt_dss_d_ * 
			tsfcom_1.tsfbuf[feq_gen_i_d_ + (j << 9) - 513];
/* SOURCE runinit.for:1179 */
/*<   250 continue >*/
/* L250: */
	    }
/* SOURCE runinit.for:1180 */
/*<       else >*/
	} else {
/* SOURCE runinit.for:1181 */
/*<       do260j=1,ndfval >*/
	    feq_gen_i_d_2 = tsfcom_1.ndfval;
	    for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE runinit.for:1182 */
/*<       tsfrat(i,j)=tsfbuf(i,j) >*/
		tsfcom_1.tsfrat[feq_gen_i_d_ + (j << 9) - 513] = tsfcom_1.tsfbuf[feq_gen_i_d_ + 
			(j << 9) - 513];
/* SOURCE runinit.for:1183 */
/*<        >*/
		tsfcom_1.tsfbuf[feq_gen_i_d_ + (j << 9) - 513] = tsfcom_1.tsfbuf[feq_gen_i_d_ - 
			1 + (j << 9) - 513] + dssdif_1.feq_gen_half_tsfdt_dss_d_ * (
			tsfcom_1.tsfbuf[feq_gen_i_d_ + (j << 9) - 513] + 
			tsfcom_1.tsfrat[feq_gen_i_d_ - 1 + (j << 9) - 513]);
/* SOURCE runinit.for:1185 */
/*<   260 continue >*/
/* L260: */
	    }
/* SOURCE runinit.for:1186 */
/*<       endif >*/
	}
/* SOURCE runinit.for:1187 */
/*<   300 continue >*/
/* L300: */
    }
/*     SET DEFAULT LAST ENTRY */
/* SOURCE runinit.for:1191 */
/*<       lentry=1 >*/
    tsfcom_1.lentry = 1;
/* SOURCE runinit.for:1192 */
/*<       lhead=1 >*/
    tsfcom_1.lhead = 1;
/*     SET VALUE OF THE  DIFFUSE FLOW BUFFER */
/* SOURCE runinit.for:1196 */
/*<       do400j=1,nluse >*/
    feq_gen_i_d_1 = tsfcom_1.nluse;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE runinit.for:1197 */
/*<       clsr1(j)=0.d0 >*/
	difcom_1.clsr1[j - 1] = 0.;
/* SOURCE runinit.for:1198 */
/*<   400 continue >*/
/* L400: */
    }
/* SOURCE runinit.for:1200 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:1201 */
/*<       end >*/
} /* bfinit_dss__ */




/* SOURCE runinit.for:1205 */
/*<       subroutinebwget(bwfdsn,nbra,nbn,nex,mblk,nblk,opblk,bwrec,wt) >*/
/* Subroutine */ int bwget_(integer *bwfdsn, integer *nbra, integer *nbn, 
	integer *nex, integer *mblk, integer *nblk, integer *feq_storage_opblk, integer *
	bwrec, real *wt)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_rdue(cilist *), do_uio(integer *, char *, ftnlen), e_rdue();

    /* Local variables */
    integer feq_gen_i_d_, it, feq_gen_control_node_state_offset_d_, feq_gen_control_node_state_d_;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    integer feq_gen_old_lev_offset_d_;
    real feq_gen_old_lev_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__136 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__138 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__139 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__140 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__141 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__142 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__143 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__144 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__145 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__146 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__147 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__149 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__150 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__151 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__154 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__157 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__158 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__159 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__160 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__161 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Get the state of the system from the dataset given by BWFDSN. */
/* SOURCE runinit.for:1213 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE runinit.for:1215 */
/*<       integerbwfdsn,bwrec,mblk,nblk,nbn,nbra,nex >*/
/* SOURCE runinit.for:1216 */
/*<       integeropblk(mblk) >*/
/* SOURCE runinit.for:1217 */
/*<       realwt >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     BWFDSN - unit number for the initial conditions file */
/*     NBRA   - number of branches in the model */
/*     NBN    - total number on nodes on branches in the model */
/*     NEX    - number of exterior nodes in the model */
/*     MBLK   - maximum number of operation blocks permitted */
/*     NBLK   - number of operation blocks */
/*     OPBLK  - pointer into the function table storage(FTAB/ITAB) for */
/*               each operation block. */
/*     WT     - weight factor for approximating time integrals */
/*     bwrec  - record pointer for storing information */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE runinit.for:1232 */
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
/* INCLUDE runinit.for:1233 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE runinit.for:1234 */
/* ********************************************************************** */
/* SOURCE bnpond.cmn:3 */
/*<       common/bnpond/coefin,pond1,pond2,ycut,bpond,bpmax >*/
/* SOURCE bnpond.cmn:5 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE runinit.for:1235 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE runinit.for:1236 */
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
/* INCLUDE runinit.for:1237 */
/*     Values for management of tributary area */
/* SOURCE tam.cmn:3 */
/*<        >*/
/* SOURCE tam.cmn:7 */
/*<       integertam_itab(tam_mxni) >*/
/* SOURCE tam.cmn:9 */
/*<       realtam_ftab(tam_mxnf) >*/
/*     Variables to use in computing a water balance. */
/* SOURCE tam.cmn:14 */
/*<       real*8l_tai,l_taq,l_taqbn,l_wsi,l_wsq >*/
/*     Description of detention reservoirs */
/* SOURCE tam.cmn:18 */
/*<       integerdten_rout_tab(mxn_dten) >*/
/* SOURCE tam.cmn:19 */
/*<       integerdten_uadv_tab(mxn_dten),dten_orf_tab(mxn_dten) >*/
/* SOURCE tam.cmn:21 */
/*<        >*/
/*     Description of delay reservoirs. */
/* SOURCE tam.cmn:30 */
/*<       integerdlay_qpnt(mxn_dlay),dlay_nlr(0:mxn_dlay) >*/
/* SOURCE tam.cmn:32 */
/*<        >*/
/* SOURCE tam.cmn:36 */
/*<        >*/
/* SOURCE tam.cmn:49 */
/*<       save/tamcom/ >*/
/*     Definitions */
/*     TAM_IPNT  - pointer to next open slot in TAM_ITAB */
/*     TAM_FPNT  - pointer to next open slot in in  TAM_FTAB */
/*     DTEN_KNT  - count of the number of detention reservoirs */
/*     DLAY_KNT  - count of the number of delay reservoirs */
/*     DTEN_ORFCD - coefficient of discharge for the orifice */
/*     DTEN_ROUT_TAB - address of the type 4 routing table */
/*     DTEN_YD  - design depth for the reservoir */
/*     DTEN_WZ  - slope of the overflow weir in horizontal extent */
/*                per unit vertical extent. */
/*     DTEN_BZ  - design size slope for basin */
/*     DTEN_WC  - dimensionless weir coef for overflow */
/*     DTEN_UAQ - design unit-area flow */
/*     DTEN_AVDA- average drainage area for a basin. Also becomes the */
/*                number of average basins in the unit. */
/*     DTEN_UAVD_TAB- table number and later table addres for */
/*                   the table of type 10 giving the unit-area */
/*                   detention volume. */
/*     DTEN_ORF_TAB- table number and later table address for */
/*                   table of type 4 giving the orifice */
/*                   flow function. */
/*     DTEN_Q1  - outflow at start of time step */
/*     DTEN_Q1P - derivative of Q1 wrt S at start of time step, ie. Q1 */
/*     DTEN_Q2  - outflow at end of time step */
/*     DTEN_Q2P - derivative of Q2 wrt S at end of time step, ie. Q1 */
/*     DTEN_S1  - storage at start of time step */
/*     DTEN_S2  - storage at end of time step */
/*     DLAY_NLR - number of linear reservoirs in the delay */
/*     DLAY_K   - storage constant for each of the reservoirs. */
/*     DLAY_Q1  - outflow at start of time step for single */
/*                reservoir.  The one reservoir case is */
/*                distinct from the multiple reservoir case. */
/*     DLAY_Q2  - outflow at end of time step for a single */
/*                reservoir. */
/*     DLAY_QPNT - pointer into TAM_FTAB for the outflows for */
/*                 multiple reservoir case. There are two */
/*                 outflow values per reservoir.  Multiple */
/*                 reservoir case does NOT use the single */
/*                 reservoir locations for outflow.  May not */
/*                 implemented. */
/*     Patterns in TAM_ITAB.  TAM_ITAB is an integer vector that contains */
/*     descriptions of the various tributary-area units (TAM's) in the */
/*     model.  There are currently three categories of TAM's: tributary areas */
/*     to branches, tributary areas to leve-pool reservoirs, and tributary */
/*     areas to boundary nodes.   Each of these categories has its own */
/*     pattern in TAM_ITAB.  These are all described in a generic sense */
/*     as tributary area units.  At tributary area unit could be as small */
/*     as the area tributary to a single computational element on a branch */
/*     or as large as the tributary area to the whole branch.  Thus the number */
/*     tributary-area units in a model depends on how the user has described */
/*     the tributary area.  Each tributary-area unit has a number assigned */
/*     sequentially in order of appearance of the unit as the input is */
/*     processed.  This pointer is an index into TAM_ITAB.  Offsets from */
/*     this index are then used to access information describing a */
/*     tributary-area unit. */
/*     For tributary areas to a branch. */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal branch number */
/*        1          Cat. Code: for a branch = 1 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          internal node number of dns end of first computational */
/*                   element to get flow */
/*        8          internal node number of dns end of last computational */
/*                   element to get flow */
/*        9          pointer into TAM_FTAB for the first distribution factor. */
/*                   There will be as many factors as there are computational */
/*                   elements in this tributary-area unit. */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into vector QPVEC for storing the flow */
/*                   that goes to the LPR */
/*        8          pointer into RWTA, RTAB, etc. to maintain */
/*                   pre-existing systems. */
/*     For tributary areas to a boundary node */
/*     For tributary areas to a level-pool reservoir (LPR) */
/*     Offset from   Description of contents of location in TAM_ITAB */
/*     pointer */
/*     -----------   ------------------------------------------------- */
/*        0          Internal node number for the LPR */
/*        1          Cat. Code: for a LPR = 2 */
/*        2          Pointer to next tributary-unit description */
/*        3          Pointer into array TRIBA for the land-use areas */
/*        4          gage number for this tributary area */
/*        5          pointer to detention description, 0 if none */
/*        6          pointer to delay description, 0 if none */
/*        7          pointer into QPVEC for summation of flows */
/*        8          pointer to location in EMC where the boundary */
/*                   flow is stored. */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE runinit.for:1240 */
/*<        >*/
/* SOURCE runinit.for:1242 */
/*<       realold_lev >*/
/* *********************************************************************** */
/*      READ(BWFDSN) WT */
/*      DO 100 I=1,NBN */

/*        READ(BWFDSN) Q1(I), Y1(I), T1(I), A1(I), K1(I), B1(I), WXVEC(I), */
/*     A      POND1(I), DXVEC(I), DZVEC(I), MY(I), MQ(I), MA1(I), MQ1(I) */

/* 100  CONTINUE */
/* SOURCE runinit.for:1252 */
/*<       read(bwfdsn,rec=bwrec)wt >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> opblk(feq_storage_opblk, 1);

    /* Function Body */
    feq_gen_io_d__136.ciunit = *bwfdsn;
    feq_gen_io_d__136.cirec = *bwrec;
    s_rdue(&feq_gen_io_d__136);
    do_uio(&feq_gen_c_d_1, (char *)&(*wt), (ftnlen)sizeof(real));
    e_rdue();
/* SOURCE runinit.for:1253 */
/*<       bwrec=bwrec+1 >*/
    ++(*bwrec);
/* SOURCE runinit.for:1254 */
/*<       do100i=1,nbn >*/
    feq_gen_i_d_1 = *nbn;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:1255 */
/*<       read(bwfdsn,rec=bwrec)q1(i),y1(i) >*/
	feq_gen_io_d__138.ciunit = *bwfdsn;
	feq_gen_io_d__138.cirec = *bwrec;
	s_rdue(&feq_gen_io_d__138);
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.q1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.y1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_rdue();
/* SOURCE runinit.for:1256 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE runinit.for:1257 */
/*<       read(bwfdsn,rec=bwrec)t1(i),a1(i) >*/
	feq_gen_io_d__139.ciunit = *bwfdsn;
	feq_gen_io_d__139.cirec = *bwrec;
	s_rdue(&feq_gen_io_d__139);
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.t1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.a1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_rdue();
/* SOURCE runinit.for:1258 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE runinit.for:1259 */
/*<       read(bwfdsn,rec=bwrec)k1(i),b1(i) >*/
	feq_gen_io_d__140.ciunit = *bwfdsn;
	feq_gen_io_d__140.cirec = *bwrec;
	s_rdue(&feq_gen_io_d__140);
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.k1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.b1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_rdue();
/* SOURCE runinit.for:1260 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE runinit.for:1261 */
/*<       read(bwfdsn,rec=bwrec)wxvec(i),pond1(i) >*/
	feq_gen_io_d__141.ciunit = *bwfdsn;
	feq_gen_io_d__141.cirec = *bwrec;
	s_rdue(&feq_gen_io_d__141);
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.wxvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_uio(&feq_gen_c_d_1, (char *)&bnpond_1.pond1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_rdue();
/* SOURCE runinit.for:1262 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE runinit.for:1263 */
/*<       read(bwfdsn,rec=bwrec)dxvec(i),dzvec(i) >*/
	feq_gen_io_d__142.ciunit = *bwfdsn;
	feq_gen_io_d__142.cirec = *bwrec;
	s_rdue(&feq_gen_io_d__142);
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.dxvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.dzvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_rdue();
/* SOURCE runinit.for:1264 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE runinit.for:1265 */
/*<       read(bwfdsn,rec=bwrec)my(i),mq(i) >*/
	feq_gen_io_d__143.ciunit = *bwfdsn;
	feq_gen_io_d__143.cirec = *bwrec;
	s_rdue(&feq_gen_io_d__143);
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.my[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.mq[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_rdue();
/* SOURCE runinit.for:1266 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE runinit.for:1267 */
/*<       read(bwfdsn,rec=bwrec)ma1(i),mq1(i) >*/
	feq_gen_io_d__144.ciunit = *bwfdsn;
	feq_gen_io_d__144.cirec = *bwrec;
	s_rdue(&feq_gen_io_d__144);
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.ma1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.mq1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_rdue();
/* SOURCE runinit.for:1268 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE runinit.for:1270 */
/*<   100 continue >*/
/* L100: */
    }
/*      DO 200 I=1,NEX */
/*        READ(BWFDSN) QE1(I), YE1(I), AE1(I), MYE(I), MQE(I), TE1(I) */
/* 200  CONTINUE */
/* SOURCE runinit.for:1277 */
/*<       do200i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*        WRITE(BWFDSN) QE1(I), YE1(I), AE1(I), MYE(I), MQE(I), TE1(I) */
/* SOURCE runinit.for:1279 */
/*<       read(bwfdsn,rec=bwrec)qe1(i),ye1(i) >*/
	feq_gen_io_d__145.ciunit = *bwfdsn;
	feq_gen_io_d__145.cirec = *bwrec;
	s_rdue(&feq_gen_io_d__145);
	do_uio(&feq_gen_c_d_1, (char *)&enelem_1.qe1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_uio(&feq_gen_c_d_1, (char *)&enelem_1.ye1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_rdue();
/* SOURCE runinit.for:1280 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE runinit.for:1281 */
/*<       read(bwfdsn,rec=bwrec)ae1(i),mye(i) >*/
	feq_gen_io_d__146.ciunit = *bwfdsn;
	feq_gen_io_d__146.cirec = *bwrec;
	s_rdue(&feq_gen_io_d__146);
	do_uio(&feq_gen_c_d_1, (char *)&enelem_1.ae1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_uio(&feq_gen_c_d_1, (char *)&enelem_1.mye[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_rdue();
/* SOURCE runinit.for:1282 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE runinit.for:1283 */
/*<       read(bwfdsn,rec=bwrec)mqe(i),te1(i) >*/
	feq_gen_io_d__147.ciunit = *bwfdsn;
	feq_gen_io_d__147.cirec = *bwrec;
	s_rdue(&feq_gen_io_d__147);
	do_uio(&feq_gen_c_d_1, (char *)&enelem_1.mqe[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_uio(&feq_gen_c_d_1, (char *)&enelem_1.te1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_rdue();
/* SOURCE runinit.for:1284 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE runinit.for:1286 */
/*<   200 continue >*/
/* L200: */
    }
/*     RESETTING EMC CAUSES PROBLEMS WITH FORECASTING.  TRY TO */
/*     GET BY WITHOUT IT AND SETTING THE STATE LIKE WE DO WHEN */
/*     STARTING FROM BACKWATER COMPUTATIONS. */
/*      READ(BWFDSN) EMC */
/*     COPY TO THE COMPANION SET. */
/* SOURCE runinit.for:1297 */
/*<       do300i=1,nbn >*/
    feq_gen_i_d_1 = *nbn;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:1298 */
/*<       q2(i)=q1(i) >*/
	bnelem_1.q2[feq_gen_i_d_ - 1] = bnelem_1.q1[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:1299 */
/*<       y2(i)=y1(i) >*/
	bnelem_1.y2[feq_gen_i_d_ - 1] = bnelem_1.y1[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:1300 */
/*<       a2(i)=a1(i) >*/
	bnelem_1.a2[feq_gen_i_d_ - 1] = bnelem_1.a1[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:1301 */
/*<       k2(i)=k1(i) >*/
	bnelem_1.k2[feq_gen_i_d_ - 1] = bnelem_1.k1[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:1302 */
/*<       b2(i)=b1(i) >*/
	bnelem_1.b2[feq_gen_i_d_ - 1] = bnelem_1.b1[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:1303 */
/*<       t2(i)=t1(i) >*/
	bnelem_1.t2[feq_gen_i_d_ - 1] = bnelem_1.t1[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:1304 */
/*<       ma2(i)=ma1(i) >*/
	bnelem_1.ma2[feq_gen_i_d_ - 1] = bnelem_1.ma1[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:1305 */
/*<       mq2(i)=mq1(i) >*/
	bnelem_1.mq2[feq_gen_i_d_ - 1] = bnelem_1.mq1[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:1306 */
/*<   300 continue >*/
/* L300: */
    }
/* SOURCE runinit.for:1308 */
/*<       do400i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:1309 */
/*<       qe2(i)=qe1(i) >*/
	enelem_1.qe2[feq_gen_i_d_ - 1] = enelem_1.qe1[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:1310 */
/*<       ye2(i)=ye1(i) >*/
	enelem_1.ye2[feq_gen_i_d_ - 1] = enelem_1.ye1[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:1311 */
/*<       ae2(i)=ae1(i) >*/
	enelem_1.ae2[feq_gen_i_d_ - 1] = enelem_1.ae1[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:1312 */
/*<       te2(i)=te1(i) >*/
	enelem_1.te2[feq_gen_i_d_ - 1] = enelem_1.te1[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:1313 */
/*<   400 continue >*/
/* L400: */
    }
/*      DO 500 I=1,NBLK */
/*        IT = OPBLK(I) + 1 */
/*        READ(BWFDSN) FTAB(IT), FTAB(IT+1) */
/* 500  CONTINUE */


/*      READ(BWFDSN) (BPOND(I), I=1,NBRA) */

/*      IF(DLAY_KNT.GT.0) READ(BWFDSN) (DLAY_Q1(I),I=1,DLAY_KNT) */

/*      DO 600  I=1,DTEN_KNT */
/*        READ(BWFDSN) DTEN_S1(I), DTEN_Q1(I), DTEN_Q1P(I) */
/* 600   CONTINUE */
/* SOURCE runinit.for:1329 */
/*<       doi=1,nblk >*/
    feq_gen_i_d_1 = *nblk;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:1330 */
/*<       it=opblk(i) >*/
	it = opblk[feq_gen_i_d_];
/* SOURCE runinit.for:1331 */
/*<       read(bwfdsn,rec=bwrec)ftab(it+1),ftab(it+2) >*/
	feq_gen_io_d__149.ciunit = *bwfdsn;
	feq_gen_io_d__149.cirec = *bwrec;
	s_rdue(&feq_gen_io_d__149);
	do_uio(&feq_gen_c_d_1, (char *)ftab.lease(it + 1).data(), (ftnlen)sizeof(real));
	do_uio(&feq_gen_c_d_1, (char *)ftab.lease(it + 2).data(), (ftnlen)sizeof(real));
	e_rdue();
/* SOURCE runinit.for:1332 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE runinit.for:1333 */
/*<       read(bwfdsn,rec=bwrec)ftab(it+5) >*/
	feq_gen_io_d__150.ciunit = *bwfdsn;
	feq_gen_io_d__150.cirec = *bwrec;
	s_rdue(&feq_gen_io_d__150);
	do_uio(&feq_gen_c_d_1, (char *)ftab.lease(it + 5).data(), (ftnlen)sizeof(real));
	e_rdue();
/* SOURCE runinit.for:1334 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/*       Blocks of type 3, GATETABL, have values for each control point */
/*       that need to be remembered as well. */
/* SOURCE runinit.for:1337 */
/*<       if(itab(it+3)==3)then >*/
	if (itab[it + 3] == 3) {
/*         Restore the  value for old level and  the control-node state. */
/* SOURCE runinit.for:1339 */
/*<   500 continue >*/
L500:
/* SOURCE runinit.for:1340 */
/*<       read(bwfdsn,rec=bwrec)old_lev_offset,old_lev >*/
	    feq_gen_io_d__151.ciunit = *bwfdsn;
	    feq_gen_io_d__151.cirec = *bwrec;
	    s_rdue(&feq_gen_io_d__151);
	    do_uio(&feq_gen_c_d_1, (char *)&feq_gen_old_lev_offset_d_, (ftnlen)sizeof(integer));
	    do_uio(&feq_gen_c_d_1, (char *)&feq_gen_old_lev_d_, (ftnlen)sizeof(real));
	    e_rdue();
/* SOURCE runinit.for:1341 */
/*<       bwrec=bwrec+1 >*/
	    ++(*bwrec);
/* SOURCE runinit.for:1342 */
/*<       if(old_lev_offset>0)then >*/
	    if (feq_gen_old_lev_offset_d_ > 0) {
/* SOURCE runinit.for:1343 */
/*<       ftab(it+old_lev_offset)=old_lev >*/
		ftab[it + feq_gen_old_lev_offset_d_] = feq_gen_old_lev_d_;
/* SOURCE runinit.for:1344 */
/*<       read(bwfdsn,rec=bwrec)control_node_state_offset,control_node_state >*/
		feq_gen_io_d__154.ciunit = *bwfdsn;
		feq_gen_io_d__154.cirec = *bwrec;
		s_rdue(&feq_gen_io_d__154);
		do_uio(&feq_gen_c_d_1, (char *)&feq_gen_control_node_state_offset_d_, (ftnlen)
			sizeof(integer));
		do_uio(&feq_gen_c_d_1, (char *)&feq_gen_control_node_state_d_, (ftnlen)sizeof(
			integer));
		e_rdue();
/* SOURCE runinit.for:1346 */
/*<       bwrec=bwrec+1 >*/
		++(*bwrec);
/* SOURCE runinit.for:1347 */
/*<       itab(it+control_node_state_offset)=control_node_state >*/
		itab[it + feq_gen_control_node_state_offset_d_] = feq_gen_control_node_state_d_;
/* SOURCE runinit.for:1349 */
/*<       goto500 >*/
		goto L500;
/* SOURCE runinit.for:1350 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:1351 */
/*<       endif >*/
	}
/* SOURCE runinit.for:1353 */
/*<       enddo >*/
    }
/* SOURCE runinit.for:1355 */
/*<       doi=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:1356 */
/*<       read(bwfdsn,rec=bwrec)bpond(i) >*/
	feq_gen_io_d__157.ciunit = *bwfdsn;
	feq_gen_io_d__157.cirec = *bwrec;
	s_rdue(&feq_gen_io_d__157);
	do_uio(&feq_gen_c_d_1, (char *)&bnpond_1.bpond[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_rdue();
/* SOURCE runinit.for:1357 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE runinit.for:1358 */
/*<       enddo >*/
    }
/* SOURCE runinit.for:1359 */
/*<       doi=1,dlay_knt >*/
    feq_gen_i_d_1 = tamcom_1.feq_gen_dlay_knt_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:1360 */
/*<       read(bwfdsn,rec=bwrec)dlay_q1(i) >*/
	feq_gen_io_d__158.ciunit = *bwfdsn;
	feq_gen_io_d__158.cirec = *bwrec;
	s_rdue(&feq_gen_io_d__158);
	do_uio(&feq_gen_c_d_1, (char *)&tamcom_1.feq_gen_dlay_q1_d_[feq_gen_i_d_ - 1], (ftnlen)sizeof(
		doublereal));
	e_rdue();
/* SOURCE runinit.for:1361 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE runinit.for:1362 */
/*<       enddo >*/
    }
/* SOURCE runinit.for:1364 */
/*<       doi=1,dten_knt >*/
    feq_gen_i_d_1 = tamcom_1.feq_gen_dten_knt_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:1365 */
/*<       read(bwfdsn,rec=bwrec)dten_s1(i) >*/
	feq_gen_io_d__159.ciunit = *bwfdsn;
	feq_gen_io_d__159.cirec = *bwrec;
	s_rdue(&feq_gen_io_d__159);
	do_uio(&feq_gen_c_d_1, (char *)&tamcom_1.feq_gen_dten_s1_d_[feq_gen_i_d_ - 1], (ftnlen)sizeof(
		real));
	e_rdue();
/* SOURCE runinit.for:1366 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE runinit.for:1367 */
/*<       read(bwfdsn,rec=bwrec)dten_q1(i) >*/
	feq_gen_io_d__160.ciunit = *bwfdsn;
	feq_gen_io_d__160.cirec = *bwrec;
	s_rdue(&feq_gen_io_d__160);
	do_uio(&feq_gen_c_d_1, (char *)&tamcom_1.feq_gen_dten_q1_d_[feq_gen_i_d_ - 1], (ftnlen)sizeof(
		real));
	e_rdue();
/* SOURCE runinit.for:1368 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE runinit.for:1369 */
/*<       read(bwfdsn,rec=bwrec)dten_q1p(i) >*/
	feq_gen_io_d__161.ciunit = *bwfdsn;
	feq_gen_io_d__161.cirec = *bwrec;
	s_rdue(&feq_gen_io_d__161);
	do_uio(&feq_gen_c_d_1, (char *)&tamcom_1.feq_gen_dten_q1p_d_[feq_gen_i_d_ - 1], (ftnlen)sizeof(
		real));
	e_rdue();
/* SOURCE runinit.for:1370 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE runinit.for:1371 */
/*<       enddo >*/
    }
/* SOURCE runinit.for:1374 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:1375 */
/*<       end >*/
} /* bwget_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE runinit.for:1379 */
/*<        >*/
/* Subroutine */ int cd4qy_(integer *stdout, integer *nb, integer *hdnode, 
	integer *nbra, integer *nex, integer *nbn, doublereal *jtime, integer 
	*feq_storage_brpt, integer *feq_storage_exnodt, integer *feq_storage_emc, integer *maxit, real *epsb, 
	integer *output, integer *ept, real *yr)
{
    /* Format strings */
    static char fmt_2130[] = "(/,\002 *ERR:95* Maximum iterations exceeded f\
or \002,\002Backwater Analysis\002)";
    static char fmt_2140[] = "(/,\002 CODE 4 Inversion Head Node=\002,a5,/,4\
x,\002IT\002,4x,\002    Depth\002,5x,\002Residual\002,3x,\002Derivative\002,\
4x,\002Discharge\002)";
    static char fmt_2150[] = "(1x,i5,4(1pe13.5))";
    static char fmt_2212[] = "(\002 *ERR:160* Zero divide. Check that ELEVAT\
ION >\002,\002 crest elevation\002,/,11x,\002 at exterior node: \002,a5)";

    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2;
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5];

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    real f;
    integer ln, it;
    real pdv, yta;
    extern /* Subroutine */ int fnd4_(integer *, integer *, integer *, 
	    integer *, integer *);
    integer ipnt;
    real disch, qbase;
    integer qnode;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);
    extern /* Subroutine */ int contrl_(integer *, integer *, integer *, 
	    integer *, integer *, doublereal *, integer *, integer *, real *, 
	    real *, real *, integer *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__167 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__168 = { 0, 0, 0, fmt_2140, 0 };
    static cilist feq_gen_io_d__171 = { 0, 0, 0, fmt_2212, 0 };
    static cilist feq_gen_io_d__173 = { 0, 0, 0, fmt_2150, 0 };
    static cilist feq_gen_io_d__175 = { 0, 0, 0, fmt_2130, 0 };


/*     + + + PURPOSE + + + */
/*     Find the stage(depth) at a Code 4 stage-discharge relationship */
/*     for computing a steady-flow water-surface profile. */
/* SOURCE runinit.for:1388 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE runinit.for:1390 */
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
/* SOURCE runinit.for:1393 */
/*<       integerhdnode,stdout,maxit,nb,nbn,nbra,nex,output,ept >*/
/* SOURCE runinit.for:1394 */
/*<       integerbrpt(8,nbra),emc(ept),exnodt(9,nex) >*/
/* SOURCE runinit.for:1395 */
/*<       realepsb,yr >*/
/* SOURCE runinit.for:1396 */
/*<       real*8jtime >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     NB     - branch number */
/*     HDNODE - head node */
/*     NBRA   - number of branches in the model */
/*     NEX    - number of exterior nodes in the model */
/*     NBN    - total number on nodes on branches in the model */
/*     TIME   - elapsed time in seconds from start of run */
/*     BRPT   - branch pointer table.  Values for each branch are: */
/*              ROW       Meaning */
/*              1         upstream user node number */
/*              2         downstream user node number */
/*              3         pointer into branch vector for upstream node */
/*              4         pointer into branch vector for downstream node */
/*              5         upstream exterior node number */
/*              6         downstream exterior node number */
/*              7         pointer to address in EMC for the branch */
/*              8         number of unknowns at a node for the branch */
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
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     MAXIT  - maximum number of interations */
/*     EPSB   - convergence limit for steady flow computations */
/*     OUTPUT - output level for diagnostic work */
/*     YR     - depth being sought */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE runinit.for:1437 */
/*     Miscellaneous control parameters */
/* SOURCE misccon.cmn:3 */
/*<       integerpagesp,pndflg >*/
/* SOURCE misccon.cmn:5 */
/*<        >*/
/* SOURCE misccon.cmn:8 */
/*<        >*/
/* INCLUDE runinit.for:1438 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE runinit.for:1439 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE runinit.for:1442 */
/*<       integeripnt,it,ln,qnode >*/
/* SOURCE runinit.for:1443 */
/*<       realdisch,f,pdv,qbase,yta >*/
/*     + + + INTRINSICS + + + */
/* SOURCE runinit.for:1446 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE runinit.for:1449 */
/*<       charactergetusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE runinit.for:1452 */
/*<       externalcontrl,fnd4,getusn >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE runinit.for:1455 */
/*<  2130  >*/
/* SOURCE runinit.for:1457 */
/*<  2140  >*/
/* SOURCE runinit.for:1460 */
/*<  2150 format(1x,i5,4(1pe13.5)) >*/
/* SOURCE runinit.for:1461 */
/*<  2212  >*/
/* *********************************************************************** */
/*     Find the pointer into the Network-Matrix Control structure for */
/*     the current node. */
/* SOURCE runinit.for:1466 */
/*<       callfnd4(stdout,hdnode,emc,ept,ipnt) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* L2130: */
/* L2140: */
/* L2150: */
/* L2212: */
    fnd4_(stdout, hdnode, &emc[1], ept, &ipnt);
/* SOURCE runinit.for:1470 */
/*<       it=0 >*/
    it = 0;
/*     Place values in the locations needed by subroutine CONTRL. */
/* SOURCE runinit.for:1474 */
/*<       ye2(hdnode)=yr >*/
    enelem_1.ye2[*hdnode - 1] = *yr;
/* SOURCE runinit.for:1475 */
/*<       if(nb.gt.0)then >*/
    if (*nb > 0) {
/*       Must deal with a branch.  May require evaluation of water- */
/*       surface slope at previous time step.  Make it same as bottom */
/*       slope. */
/* SOURCE runinit.for:1480 */
/*<       ln=brpt(4,nb) >*/
	ln = brpt[(*nb << 3) + 4];
/* SOURCE runinit.for:1481 */
/*<       y1(ln)=yr >*/
	bnelem_1.y1[ln - 1] = *yr;
/* SOURCE runinit.for:1482 */
/*<       y1(ln-1)=yr >*/
	bnelem_1.y1[ln - 2] = *yr;
/* SOURCE runinit.for:1483 */
/*<       dxvec(ln)=abs(xvec(ln)-xvec(ln-1)) >*/
	bnelem_1.dxvec[ln - 1] = (feq_gen_r_d_1 = static_cast<double>(bnelem_1.xvec[ln - 1]) - 
		bnelem_1.xvec[ln - 2], dabs(feq_gen_r_d_1));
/* SOURCE runinit.for:1484 */
/*<       endif >*/
    }
/*     Get the discharge defining the stage. */
/* SOURCE runinit.for:1487 */
/*<       qnode=emc(ipnt+4) >*/
    qnode = emc[ipnt + 4];
/* SOURCE runinit.for:1488 */
/*<       qbase=qe1(qnode) >*/
    qbase = enelem_1.qe1[qnode - 1];
/* SOURCE runinit.for:1490 */
/*<       if(qbase.eq.0)then >*/
    if (qbase == (float)0.) {
/* SOURCE runinit.for:1491 */
/*<       write(stdout,*)' FLOW IS ZERO IN BRANCH OR AT FREE NODE' >*/
	feq_gen_io_d__167.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__167);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FLOW IS ZERO IN BRANCH OR AT FREE NODE"), (
		ftnlen)39);
	e_wsle();
/* SOURCE runinit.for:1492 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:1493 */
/*<       endif >*/
    }
/* SOURCE runinit.for:1495 */
/*<       write(stdout,2140)getusn(hdnode) >*/
    feq_gen_io_d__168.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__168);
    getusn_(feq_gen_ch_d_2, (ftnlen)5, hdnode);
    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
    e_wsfe();
/* SOURCE runinit.for:1497 */
/*<   135 continue >*/
L135:
/*       FIND DISCHARGE AT THE INPUT ELEVATION. */
/* SOURCE runinit.for:1501 */
/*<        >*/
    contrl_(&ipnt, stdout, nbn, nex, output, jtime, &exnodt[10], &emc[1], 
	    bnelem_1.y1, bnelem_1.zvec, bnelem_1.dxvec, ept, &pdv, &disch);
/* SOURCE runinit.for:1505 */
/*<       if(pdv.eq.0.0)then >*/
    if (pdv == (float)0.) {
/* SOURCE runinit.for:1506 */
/*<       write(stdout,2212)getusn(hdnode) >*/
	feq_gen_io_d__171.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__171);
	getusn_(feq_gen_ch_d_2, (ftnlen)5, hdnode);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	e_wsfe();
/* SOURCE runinit.for:1507 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:1508 */
/*<       endif >*/
    }
/*       Compute the residual for the rating. */
/* SOURCE runinit.for:1510 */
/*<       f=disch-qbase >*/
    f = static_cast<double>(disch) - qbase;
/* SOURCE runinit.for:1511 */
/*<       write(stdout,2150)it,yr,f,pdv,qbase >*/
    feq_gen_io_d__173.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__173);
    do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&(*yr), (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&f, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&pdv, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&qbase, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE runinit.for:1512 */
/*<       if(abs(f/qbase).gt.epsb.and.abs(f/pdv).gt.epsb2)then >*/
    if ((feq_gen_r_d_1 = static_cast<double>(f) / qbase, dabs(feq_gen_r_d_1)) > *epsb && (feq_gen_r_d_2 = static_cast<double>(f) / pdv, dabs(feq_gen_r_d_2))
	     > miscon_1.epsb2) {
/*         Compute the next estimate */
/* SOURCE runinit.for:1514 */
/*<       yta=yr-f/pdv >*/
	yta = static_cast<double>(*yr) - static_cast<double>(f) / pdv;
/* SOURCE runinit.for:1515 */
/*<       if(yta.le.0.0)yta=0.5*yr >*/
	if (yta <= (float)0.) {
	    yta = static_cast<double>(*yr) * (float).5;
	}
/* SOURCE runinit.for:1516 */
/*<       yr=yta >*/
	*yr = yta;
/* SOURCE runinit.for:1517 */
/*<       ye2(hdnode)=yr >*/
	enelem_1.ye2[*hdnode - 1] = *yr;
/* SOURCE runinit.for:1518 */
/*<       it=it+1 >*/
	++it;
/* SOURCE runinit.for:1519 */
/*<       if(it.gt.maxit)then >*/
	if (it > *maxit) {
/*           Iteration count exhausted. */
/* SOURCE runinit.for:1521 */
/*<       write(stdout,2130) >*/
	    feq_gen_io_d__175.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__175);
	    e_wsfe();
/* SOURCE runinit.for:1522 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:1523 */
/*<       else >*/
	} else {
/* SOURCE runinit.for:1524 */
/*<       goto135 >*/
	    goto L135;
/* SOURCE runinit.for:1525 */
/*<       endif >*/
	}
/* SOURCE runinit.for:1526 */
/*<       else >*/
    } else {
/* SOURCE runinit.for:1527 */
/*<       ye1(hdnode)=yr >*/
	enelem_1.ye1[*hdnode - 1] = *yr;
/* SOURCE runinit.for:1528 */
/*<       endif >*/
    }
/* SOURCE runinit.for:1530 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:1531 */
/*<       end >*/
} /* cd4qy_ */




/* SOURCE runinit.for:1535 */
/*<        >*/
/* Subroutine */ int cd56qy_(integer *stdout, integer *ipnt, integer *nex, 
	doublereal *jtime, integer *feq_storage_emc, integer *maxit, real *yr, real *epsb,
	 real *qeps, integer *ept, real *yl)
{
    /* Format strings */
    static char fmt_2130[] = "(/,\002 *ERR:95* Maximum iterations exceeded f\
or \002,\002Backwater Analysis\002)";
    static char fmt_2140[] = "(/,\002 CODE 5 Inversion: Head Nodes=\002,a5,1\
x,a5,/,4x,\002IT\002,4x,\002    Depth\002,5x,\002Residual\002,3x,\002Derivat\
ive\002,4x,\002Discharge\002)";
    static char fmt_2145[] = "(/,\002 CODE 5 Lookup: Head Nodes=\002,2a5,/\
,\002 Dns Depth=\002,f10.3,\002 Flow=\002,f10.1,\002 Ups Depth=\002,f10.3)";
    static char fmt_2150[] = "(1x,i5,4(1pe13.5))";
    static char fmt_2160[] = "(/,\002*ERR:246* Flow at flow node for Code 5 \
Type 6 is zero.\002,\002  Unable to continue.\002)";
    static char fmt_2170[] = "(/,\002*WRN:50* Flow direction and head differ\
ence\002,\002 inconsistent. Adjusting\002,10x,/,\002 upstream water level an\
d \002,\002attempting to continue.\002)";
    static char fmt_2180[] = "(/,\002*ERR:247* At depth=\002,f10.3,\002 and \
 flow=\002,f10.1,\002 rate of\002,10x,/,\002change of flow with respect to u\
pstream head\002,\002 is zero\002,10x,/,\002for Code 5 Type 6.  Cannot conti\
nue.\002)";

    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2;
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5], feq_gen_ch_d_3[5], feq_gen_ch_d_4[5];
    static real equiv_0[1];

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen);

    /* Local variables */
    real ed;
    integer it;
    real dy, hu, tp, fac, pdv, pql, res, pqr, pyl, ylt, pyr;
    integer free, ntab, adrs, fsgn, dexn;
#define idum (feq::BitView<integer>(equiv_0, sizeof(equiv_0)))
    integer ztab;
    real dhuq, flow;
#define rdum (equiv_0)
    real yold;
    integer uexn;
    extern /* Subroutine */ int twod6_(integer *, integer *, doublereal *, 
	    integer *, integer *, integer *, real *, real *, real *, real *, 
	    real *, real *, real *, real *);
    real hbase;
    integer dnode;
    real dhued;
    integer npath, qnode, unode;
    extern /* Subroutine */ int tdlk14_(integer *, integer *, integer *, real 
	    *, real *, real *, real *, real *, real *, integer *);
    integer sysgn;
    real resold;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);
    extern /* Subroutine */ int lktstab_(integer *, doublereal *, real *, 
	    integer *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__184 = { 0, 0, 0, fmt_2160, 0 };
    static cilist feq_gen_io_d__188 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__189 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__190 = { 0, 0, 0, fmt_2170, 0 };
    static cilist feq_gen_io_d__194 = { 0, 0, 0, fmt_2140, 0 };
    static cilist feq_gen_io_d__200 = { 0, 0, 0, fmt_2150, 0 };
    static cilist feq_gen_io_d__201 = { 0, 0, 0, fmt_2180, 0 };
    static cilist feq_gen_io_d__205 = { 0, 0, 0, fmt_2130, 0 };
    static cilist feq_gen_io_d__217 = { 0, 0, 0, fmt_2145, 0 };


/*     + + + PURPOSE + + + */
/*     Find the stage(depth) at the upstream node of a 2-D control */
/*     structure for initial conditions. */
/* SOURCE runinit.for:1544 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE runinit.for:1546 */
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
/* SOURCE runinit.for:1549 */
/*<       integerept,ipnt,stdout,maxit,nex >*/
/* SOURCE runinit.for:1550 */
/*<       integeremc(ept) >*/
/* SOURCE runinit.for:1551 */
/*<       realepsb,qeps,yl,yr >*/
/* SOURCE runinit.for:1552 */
/*<       real*8jtime >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     IPNT   - pointer into EMC for description of control structure */
/*     NEX    - number of exterior nodes in the model */
/*     TIME   - elapsed time in seconds from start of run */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     MAXIT  - maximum number of interations */
/*     YR     - downstream depth */
/*     EPSB   - convergence limit for steady flow computations */
/*     QEPS   - value of flow to prevent zero divide when computing */
/*               relative correction */
/*     YL     - upstream depth */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE runinit.for:1568 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE runinit.for:1571 */
/*<        >*/
/* SOURCE runinit.for:1573 */
/*<        >*/
/*     + + + EQUIVALENCES + + + */
/* SOURCE runinit.for:1577 */
/*<       equivalence(idum,rdum) >*/
/*     + + + INTRINSICS + + + */
/* SOURCE runinit.for:1580 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE runinit.for:1583 */
/*<       charactergetusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE runinit.for:1586 */
/*<       externalgetusn,lktab,tdlk14,twod6 >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE runinit.for:1589 */
/*<  2130  >*/
/* SOURCE runinit.for:1591 */
/*<  2140  >*/
/* SOURCE runinit.for:1594 */
/*<  2145  >*/
/* SOURCE runinit.for:1596 */
/*<  2150 format(1x,i5,4(1pe13.5)) >*/
/* SOURCE runinit.for:1597 */
/*<  2160  >*/
/* SOURCE runinit.for:1599 */
/*<  2170  >*/
/* SOURCE runinit.for:1602 */
/*<  2180  >*/
/* *********************************************************************** */
/*     This routine assumes that the flow is non-zero.  Its sign */
/*     will be consistent with the way the two-node control structure */
/*     is placed between the two exterior nodes.  The upstream, UEXN, */
/*     and downstream, DEXN, exterior nodes are nominal only. */
/*     However, the input values of depth at the downstream node, YR, */
/*     and at the upstream node, YL, are true, that is the flow is */
/*     physically moving from the upstream node to the downstream node. */
/*     A flow of zero is excluded because in that case the user */
/*     will know the elevations and must supply them explicitly in */
/*     the initial condition portion of the input to FEQ. */
/* SOURCE runinit.for:1619 */
/*<       uexn=emc(ipnt+2) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* L2130: */
/* L2140: */
/* L2145: */
/* L2150: */
/* L2160: */
/* L2170: */
/* L2180: */
    uexn = emc[*ipnt + 2];
/* SOURCE runinit.for:1620 */
/*<       dexn=emc(ipnt+3) >*/
    dexn = emc[*ipnt + 3];
/* SOURCE runinit.for:1621 */
/*<       qnode=emc(ipnt+4) >*/
    qnode = emc[*ipnt + 4];
/* SOURCE runinit.for:1622 */
/*<       sysgn=emc(ipnt+5) >*/
    sysgn = emc[*ipnt + 5];
/* SOURCE runinit.for:1623 */
/*<       npath=emc(ipnt+6) >*/
    npath = emc[*ipnt + 6];
/* SOURCE runinit.for:1624 */
/*<       flow=qe1(qnode) >*/
    flow = enelem_1.qe1[qnode - 1];
/* SOURCE runinit.for:1625 */
/*<       qe2(qnode)=flow >*/
    enelem_1.qe2[qnode - 1] = flow;
/* SOURCE runinit.for:1627 */
/*<       if(flow.eq.0.0)then >*/
    if (flow == (float)0.) {
/* SOURCE runinit.for:1628 */
/*<       write(stdout,2160) >*/
	feq_gen_io_d__184.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__184);
	e_wsfe();
/* SOURCE runinit.for:1629 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:1630 */
/*<       endif >*/
    }
/* SOURCE runinit.for:1631 */
/*<       if(flow.lt.0.0)then >*/
    if (flow < (float)0.) {
/* SOURCE runinit.for:1632 */
/*<       fsgn=-sysgn >*/
	fsgn = -sysgn;
/* SOURCE runinit.for:1633 */
/*<       else >*/
    } else {
/* SOURCE runinit.for:1634 */
/*<       fsgn=sysgn >*/
	fsgn = sysgn;
/* SOURCE runinit.for:1635 */
/*<       endif >*/
    }
/* SOURCE runinit.for:1637 */
/*<       if(fsgn.ge.0)then >*/
    if (fsgn >= 0) {
/*       Flow is physically from nominal upstream node to */
/*       nominal downstream node. */
/* SOURCE runinit.for:1640 */
/*<       ye2(uexn)=yl >*/
	enelem_1.ye2[uexn - 1] = *yl;
/* SOURCE runinit.for:1641 */
/*<       ye2(dexn)=yr >*/
	enelem_1.ye2[dexn - 1] = *yr;
/* SOURCE runinit.for:1642 */
/*<       unode=uexn >*/
	unode = uexn;
/* SOURCE runinit.for:1643 */
/*<       dnode=dexn >*/
	dnode = dexn;
/* SOURCE runinit.for:1644 */
/*<       write(stdout,*)' FLOW U -> D' >*/
	feq_gen_io_d__188.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__188);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FLOW U -> D"), (ftnlen)12);
	e_wsle();
/* SOURCE runinit.for:1645 */
/*<       else >*/
    } else {
/* SOURCE runinit.for:1646 */
/*<       ye2(dexn)=yl >*/
	enelem_1.ye2[dexn - 1] = *yl;
/* SOURCE runinit.for:1647 */
/*<       ye2(uexn)=yr >*/
	enelem_1.ye2[uexn - 1] = *yr;
/* SOURCE runinit.for:1648 */
/*<       unode=dexn >*/
	unode = dexn;
/* SOURCE runinit.for:1649 */
/*<       dnode=uexn >*/
	dnode = uexn;
/* SOURCE runinit.for:1650 */
/*<       write(stdout,*)' FLOW D -> U' >*/
	feq_gen_io_d__189.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__189);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FLOW D -> U"), (ftnlen)12);
	e_wsle();
/* SOURCE runinit.for:1651 */
/*<       endif >*/
    }
/* SOURCE runinit.for:1653 */
/*<       if(npath.gt.0)then >*/
    if (npath > 0) {
/*       Tables are of type 6 or type 13.  Solution is iterative. */
/*       First estimate is already in the vectors for exterior nodes. */
/* SOURCE runinit.for:1656 */
/*<       if(ye2(unode)+ze(unode).le.ye2(dnode)+ze(dnode))then >*/
	if (static_cast<double>(enelem_1.ye2[unode - 1]) + enelem_1.ze[unode - 1] <= static_cast<double>(enelem_1.ye2[
		dnode - 1]) + enelem_1.ze[dnode - 1]) {
/*         Head difference does not agree with the flow direction. */
/* SOURCE runinit.for:1659 */
/*<       write(stdout,2170) >*/
	    feq_gen_io_d__190.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__190);
	    e_wsfe();
/*         Make the average depth .02 greater upstream */
/*         than downstream. */
/* SOURCE runinit.for:1662 */
/*<       ye2(unode)=1.02*ye2(dnode)+1.01*(ze(dnode)-ze(unode)) >*/
	    enelem_1.ye2[unode - 1] = static_cast<double>(static_cast<double>(enelem_1.ye2[dnode - 1]) * (float)1.02) + 
		    static_cast<double>((static_cast<double>(enelem_1.ze[dnode - 1]) - enelem_1.ze[unode - 1])) * (
		    float)1.01;
/* SOURCE runinit.for:1663 */
/*<       endif >*/
	}
/* SOURCE runinit.for:1664 */
/*<       it=0 >*/
	it = 0;
/* SOURCE runinit.for:1665 */
/*<       resold=0.0 >*/
	resold = (float)0.;
/* SOURCE runinit.for:1666 */
/*<       fac=0.01 >*/
	fac = (float).01;
/* SOURCE runinit.for:1667 */
/*<       write(stdout,2140)getusn(uexn),getusn(dexn) >*/
	feq_gen_io_d__194.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__194);
	getusn_(feq_gen_ch_d_2, (ftnlen)5, &uexn);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	getusn_(feq_gen_ch_d_4, (ftnlen)5, &dexn);
	s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)5);
	e_wsfe();
/* SOURCE runinit.for:1668 */
/*<   100 continue >*/
L100:
/* SOURCE runinit.for:1669 */
/*<        >*/
	twod6_(ipnt, stdout, jtime, nex, ept, &emc[1], enelem_1.qe2, 
		enelem_1.ye2, enelem_1.ze, &res, &pyl, &pql, &pyr, &pqr);
/*         RES gives the residual between the known flow at the */
/*         flow node and the flow defined by the upstream and */
/*         and downstream elevations.  PYL gives the rate of change */
/*         of the residual with respect to changes at the upstream */
/*         node. */
/* SOURCE runinit.for:1679 */
/*<       write(stdout,2150)it,yl,res,pyl,flow >*/
	feq_gen_io_d__200.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__200);
	do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&(*yl), (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&res, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&pyl, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&flow, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE runinit.for:1681 */
/*<       if(pyl.eq.0.0)then >*/
	if (pyl == (float)0.) {
/* SOURCE runinit.for:1682 */
/*<       write(stdout,2180)yl,flow >*/
	    feq_gen_io_d__201.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__201);
	    do_fio(&feq_gen_c_d_1, (char *)&(*yl), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&flow, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE runinit.for:1683 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:1684 */
/*<       endif >*/
	}
/* SOURCE runinit.for:1685 */
/*<       dy=res/pyl >*/
	dy = static_cast<double>(res) / pyl;
/* SOURCE runinit.for:1686 */
/*<       if(abs(res/(abs(flow)+qeps)).gt.epsb.and.abs(dy/yl).gt.epsb)then >*/
	if ((feq_gen_r_d_1 = res / (dabs(flow) + *qeps), dabs(feq_gen_r_d_1)) > *epsb && (feq_gen_r_d_2 =
		 static_cast<double>(dy) / *yl, dabs(feq_gen_r_d_2)) > *epsb) {
/* SOURCE runinit.for:1688 */
/*<       if(it.gt.5.and.res*resold.lt.0.0)then >*/
	    if (it > 5 && static_cast<double>(res) * resold < (float)0.) {
/*             We have a sign change and the iteration count is getting */
/*             large.  Make next estimate on linear fit to last */
/*             two residuals. */
/* SOURCE runinit.for:1693 */
/*<       yold=yl >*/
		yold = *yl;
/* SOURCE runinit.for:1694 */
/*<       yl=yold-resold*(yl-yold)/(res-resold) >*/
		*yl = static_cast<double>(yold) - static_cast<double>(static_cast<double>(resold) * (static_cast<double>(*yl) - yold)) / (static_cast<double>(res) - resold);
/* SOURCE runinit.for:1695 */
/*<       resold=res >*/
		resold = res;
/* SOURCE runinit.for:1696 */
/*<       it=it+1 >*/
		++it;
/* SOURCE runinit.for:1697 */
/*<       ye2(unode)=yl >*/
		enelem_1.ye2[unode - 1] = *yl;
/* SOURCE runinit.for:1698 */
/*<       else >*/
	    } else {
/* SOURCE runinit.for:1699 */
/*<       resold=res >*/
		resold = res;
/* SOURCE runinit.for:1700 */
/*<       yold=yl >*/
		yold = *yl;
/*             Make correction to the current depth value. */
/* SOURCE runinit.for:1702 */
/*<       ylt=yl-dy >*/
		ylt = static_cast<double>(*yl) - dy;
/* SOURCE runinit.for:1704 */
/*<       it=it+1 >*/
		++it;
/* SOURCE runinit.for:1705 */
/*<       yl=ylt >*/
		*yl = ylt;
/* SOURCE runinit.for:1706 */
/*<       ye2(unode)=yl >*/
		enelem_1.ye2[unode - 1] = *yl;
/* SOURCE runinit.for:1707 */
/*<       if(ye2(unode)+ze(unode).le.ye2(dnode)+ze(dnode))then >*/
		if (static_cast<double>(enelem_1.ye2[unode - 1]) + enelem_1.ze[unode - 1] <= 
			static_cast<double>(enelem_1.ye2[dnode - 1]) + enelem_1.ze[dnode - 1]) {
/*               Head difference does not agree with the flow direction. */
/*               Make the average depth FAC greater upstream */
/*               than downstream. */
/* SOURCE runinit.for:1712 */
/*<       yl=(1.+fac)*ye2(dnode)+(1.+.5*fac)*(ze(dnode)-ze(unode)) >*/
		    *yl = static_cast<double>(static_cast<double>((static_cast<double>(fac) + (float)1.)) * enelem_1.ye2[dnode - 1]) + static_cast<double>((static_cast<double>(static_cast<double>(fac) *
			     (float).5) + (float)1.)) * (static_cast<double>(enelem_1.ze[dnode - 1]) 
			    - enelem_1.ze[unode - 1]);
/* SOURCE runinit.for:1714 */
/*<       ye2(unode)=yl >*/
		    enelem_1.ye2[unode - 1] = *yl;
/* SOURCE runinit.for:1715 */
/*<       fac=.5*fac >*/
		    fac *= static_cast<double>((float).5);
/* SOURCE runinit.for:1716 */
/*<       endif >*/
		}
/* SOURCE runinit.for:1717 */
/*<       if(it.gt.maxit)then >*/
		if (it > *maxit) {
/* SOURCE runinit.for:1718 */
/*<       write(stdout,2130) >*/
		    feq_gen_io_d__205.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__205);
		    e_wsfe();
/* SOURCE runinit.for:1719 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:1720 */
/*<       endif >*/
		}
/* SOURCE runinit.for:1721 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:1722 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE runinit.for:1723 */
/*<       endif >*/
	}
/*       Solution here.  Stored in YE2(UNODE) */
/* SOURCE runinit.for:1725 */
/*<       else >*/
    } else {
/*       Table of type 14. */
/* SOURCE runinit.for:1728 */
/*<       ztab=emc(ipnt+10) >*/
	ztab = emc[*ipnt + 10];
/* SOURCE runinit.for:1729 */
/*<       if(ztab.gt.0)then >*/
	if (ztab > 0) {
/*         Time variable head datum.  Find head datum for current time. */
/* SOURCE runinit.for:1731 */
/*<       calllktstab(ztab,jtime,hbase,ntab,pdv) >*/
	    lktstab_(&ztab, jtime, &hbase, &ntab, &pdv);
/* SOURCE runinit.for:1734 */
/*<       else >*/
	} else {
/* SOURCE runinit.for:1735 */
/*<       idum=emc(ipnt+11) >*/
	    *idum = emc[*ipnt + 11];
/* SOURCE runinit.for:1736 */
/*<       hbase=rdum >*/
	    hbase = *rdum;
/* SOURCE runinit.for:1737 */
/*<       endif >*/
	}
/* SOURCE runinit.for:1739 */
/*<       if(fsgn.ge.0)then >*/
	if (fsgn >= 0) {
/* SOURCE runinit.for:1740 */
/*<       adrs=emc(ipnt+7) >*/
	    adrs = emc[*ipnt + 7];
/* SOURCE runinit.for:1741 */
/*<       else >*/
	} else {
/* SOURCE runinit.for:1742 */
/*<       adrs=emc(ipnt+8) >*/
	    adrs = emc[*ipnt + 8];
/* SOURCE runinit.for:1743 */
/*<       endif >*/
	}
/* SOURCE runinit.for:1745 */
/*<       ed=yr+ze(dnode) >*/
	ed = static_cast<double>(*yr) + enelem_1.ze[dnode - 1];
/* SOURCE runinit.for:1747 */
/*<       tp=abs(flow) >*/
	tp = dabs(flow);
/* SOURCE runinit.for:1748 */
/*<       calltdlk14(stdout,adrs,14,ed,hbase,tp,hu,dhued,dhuq,free) >*/
	tdlk14_(stdout, &adrs, &feq_gen_c_d_14, &ed, &hbase, &tp, &hu, &dhued, &dhuq, &
		free);
/* SOURCE runinit.for:1752 */
/*<       ye2(unode)=hu+hbase-ze(unode) >*/
	enelem_1.ye2[unode - 1] = static_cast<double>(static_cast<double>(hu) + hbase) - enelem_1.ze[unode - 1];
/* SOURCE runinit.for:1753 */
/*<       write(stdout,2145)getusn(uexn),getusn(dexn),yr,flow,ye2(unode) >*/
	feq_gen_io_d__217.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__217);
	getusn_(feq_gen_ch_d_2, (ftnlen)5, &uexn);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	getusn_(feq_gen_ch_d_4, (ftnlen)5, &dexn);
	s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, (char *)&(*yr), (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&flow, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&enelem_1.ye2[unode - 1], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE runinit.for:1756 */
/*<       endif >*/
    }
/* SOURCE runinit.for:1758 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:1759 */
/*<       end >*/
} /* cd56qy_ */

#undef rdum
#undef idum





/* SOURCE runinit.for:1763 */
/*<        >*/
/* Subroutine */ int feq_gen_read_free_node_items_d_(integer *stdout, char *line, 
	integer *nitem, integer *feq_gen_feq_storage_item_start_d_, integer *feq_gen_feq_storage_item_end_d_, integer *
	eflag, char *usnode, char *feq_gen_name_d_, real *depth, real *discharge, real 
	*feq_gen_elev_of_datum_d_, char *feq_gen_base_node_d_, char *xoffstring, char *
	yoffstring, char *cstation, ftnlen line_len, ftnlen usnode_len, 
	ftnlen name_len, ftnlen base_node_len, ftnlen xoffstring_len, ftnlen 
	yoffstring_len, ftnlen cstation_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:381* \002,i3,\002 items given in a \
FREE-NODE\002,\002 INITIAL CONDITIONS BLOCK  line.  Need exactly 5 or 9 item\
s.\002)";
    static char fmt_52[] = "(/,\002 *ERR:500* Conversion error in: \002,a)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_rsfi(icilist *), e_rsfi();

    /* Local variables */
    integer n, ie, is;
    char tpc[20];
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen), 
	    feq_gen_strip_blanks_and_zeros_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__218 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__223 = { 0, 0, 0, fmt_52, 0 };


/*     Get the items of data from a line of input to Free-Node Table */
/* SOURCE runinit.for:1772 */
/*<       implicitnone >*/
/* SOURCE runinit.for:1773 */
/*<       integerstdout,nitem,item_start(nitem),item_end(nitem),eflag >*/
/* SOURCE runinit.for:1775 */
/*<       realdepth,discharge,elev_of_datum >*/
/* SOURCE runinit.for:1776 */
/*<        >*/
/*     Local */
/* SOURCE runinit.for:1781 */
/*<       integerie,is,n >*/
/* SOURCE runinit.for:1782 */
/*<       charactertpc*20 >*/
/*     Called program units */
/* SOURCE runinit.for:1786 */
/*<       externalstrip_l_blanks,strip_blanks_and_zeros >*/
/*     ***********************FORMATS************************************ */
/* SOURCE runinit.for:1789 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE runinit.for:1792 */
/*<       if(nitem.ne.5.and.nitem.ne.9)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_item_end_d_(feq_gen_feq_storage_item_end_d_, 1);

    feq::IndexedPointer<integer> feq_gen_item_start_d_(feq_gen_feq_storage_item_start_d_, 1);

    /* Function Body */
/* L50: */
    if (*nitem != 5 && *nitem != 9) {
/* SOURCE runinit.for:1793 */
/*<       write(stdout,50)nitem >*/
	feq_gen_io_d__218.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__218);
	do_fio(&feq_gen_c_d_1, (char *)&(*nitem), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE runinit.for:1794 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE runinit.for:1795 */
/*<       endif >*/
    }
/* SOURCE runinit.for:1797 */
/*<       n=1 >*/
    n = 1;
/*     Process the node field */
/* SOURCE runinit.for:1799 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE runinit.for:1800 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE runinit.for:1801 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE runinit.for:1802 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE runinit.for:1804 */
/*<       usnode=tpc >*/
    s_copy(usnode, tpc, (ftnlen)5, (ftnlen)20);
/*     Process the node id field */
/* SOURCE runinit.for:1807 */
/*<       n=2 >*/
    n = 2;
/* SOURCE runinit.for:1808 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE runinit.for:1809 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE runinit.for:1810 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE runinit.for:1811 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE runinit.for:1813 */
/*<       name=tpc >*/
    s_copy(feq_gen_name_d_, tpc, (ftnlen)16, (ftnlen)20);
/*     Process the initial depth */
/* SOURCE runinit.for:1816 */
/*<       n=3 >*/
    n = 3;
/* SOURCE runinit.for:1817 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE runinit.for:1818 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE runinit.for:1819 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE runinit.for:1820 */
/*<       callstrip_blanks_and_zeros(tpc) >*/
    feq_gen_strip_blanks_and_zeros_d_(tpc, (ftnlen)20);
/* SOURCE runinit.for:1822 */
/*<       read(tpc,'(f20.0)',err=991)depth >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 20;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(f20.0)");
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&(*depth), (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/*     Process the discharge */
/* SOURCE runinit.for:1825 */
/*<       n=4 >*/
    n = 4;
/* SOURCE runinit.for:1826 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE runinit.for:1827 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE runinit.for:1828 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE runinit.for:1829 */
/*<       callstrip_blanks_and_zeros(tpc) >*/
    feq_gen_strip_blanks_and_zeros_d_(tpc, (ftnlen)20);
/* SOURCE runinit.for:1831 */
/*<       read(tpc,'(f20.0)',err=991)discharge >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 20;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(f20.0)");
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&(*discharge), (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/*     Process the datum elevation */
/* SOURCE runinit.for:1834 */
/*<       n=5 >*/
    n = 5;
/* SOURCE runinit.for:1835 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE runinit.for:1836 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE runinit.for:1837 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE runinit.for:1838 */
/*<       callstrip_blanks_and_zeros(tpc) >*/
    feq_gen_strip_blanks_and_zeros_d_(tpc, (ftnlen)20);
/* SOURCE runinit.for:1840 */
/*<       read(tpc,'(F12.0)',err=991)elev_of_datum >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_elev_of_datum_d_), (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/*     There are old inputs that will still have the column for the */
/*     node sign present.  That will make the heading count 6.  However, */
/*     we want to ignore that column.  The optional items, if present */
/*     must all be present.  Thus the item count will be 9 when the */
/*     optional items are present. */
/* SOURCE runinit.for:1847 */
/*<       if(nitem.eq.9)then >*/
    if (*nitem == 9) {
/*       Optional inputs are present. */
/* SOURCE runinit.for:1850 */
/*<       n=6 >*/
	n = 6;
/*       Process the base-node value */
/* SOURCE runinit.for:1852 */
/*<       is=item_start(n) >*/
	is = feq_gen_item_start_d_[n];
/* SOURCE runinit.for:1853 */
/*<       ie=item_end(n) >*/
	ie = feq_gen_item_end_d_[n];
/* SOURCE runinit.for:1854 */
/*<       tpc=line(is:ie) >*/
	s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE runinit.for:1855 */
/*<       callstrip_l_blanks(tpc) >*/
	feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE runinit.for:1857 */
/*<       base_node=tpc >*/
	s_copy(feq_gen_base_node_d_, tpc, (ftnlen)5, (ftnlen)20);
/* SOURCE runinit.for:1859 */
/*<       n=7 >*/
	n = 7;
/*       Process the x-location information */
/* SOURCE runinit.for:1861 */
/*<       is=item_start(n) >*/
	is = feq_gen_item_start_d_[n];
/* SOURCE runinit.for:1862 */
/*<       ie=item_end(n) >*/
	ie = feq_gen_item_end_d_[n];
/* SOURCE runinit.for:1863 */
/*<       tpc=line(is:ie) >*/
	s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE runinit.for:1864 */
/*<       callstrip_l_blanks(tpc) >*/
	feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE runinit.for:1866 */
/*<       xoffstring=tpc >*/
	s_copy(xoffstring, tpc, (ftnlen)15, (ftnlen)20);
/* SOURCE runinit.for:1868 */
/*<       n=8 >*/
	n = 8;
/*       Process the y-location information */
/* SOURCE runinit.for:1870 */
/*<       is=item_start(n) >*/
	is = feq_gen_item_start_d_[n];
/* SOURCE runinit.for:1871 */
/*<       ie=item_end(n) >*/
	ie = feq_gen_item_end_d_[n];
/* SOURCE runinit.for:1872 */
/*<       tpc=line(is:ie) >*/
	s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE runinit.for:1873 */
/*<       callstrip_l_blanks(tpc) >*/
	feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE runinit.for:1875 */
/*<       yoffstring=tpc >*/
	s_copy(yoffstring, tpc, (ftnlen)15, (ftnlen)20);
/* SOURCE runinit.for:1877 */
/*<       n=9 >*/
	n = 9;
/*       Process the node-station information */
/* SOURCE runinit.for:1879 */
/*<       is=item_start(n) >*/
	is = feq_gen_item_start_d_[n];
/* SOURCE runinit.for:1880 */
/*<       ie=item_end(n) >*/
	ie = feq_gen_item_end_d_[n];
/* SOURCE runinit.for:1881 */
/*<       tpc=line(is:ie) >*/
	s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE runinit.for:1882 */
/*<       callstrip_l_blanks(tpc) >*/
	feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE runinit.for:1884 */
/*<       cstation=tpc >*/
	s_copy(cstation, tpc, (ftnlen)10, (ftnlen)20);
/* SOURCE runinit.for:1886 */
/*<       endif >*/
    }
/* SOURCE runinit.for:1887 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:1888 */
/*<   991 continue >*/
L991:
/* SOURCE runinit.for:1889 */
/*<       write(stdout,52)tpc >*/
    feq_gen_io_d__223.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__223);
    do_fio(&feq_gen_c_d_1, tpc, (ftnlen)20);
    e_wsfe();
/* SOURCE runinit.for:1890 */
/*<    52 format(/,' *ERR:500* Conversion error in: ',a) >*/
/* SOURCE runinit.for:1891 */
/*<       eflag=1 >*/
    *eflag = 1;
/* SOURCE runinit.for:1892 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:1894 */
/*<       end >*/
} /* read_free_node_items__ */




/* SOURCE runinit.for:1898 */
/*<        >*/
/* Subroutine */ int exinit_(integer *in, integer *stdout, integer *nex, 
	integer *nbra, integer *mremc, integer *feq_storage_emc, integer *feq_storage_exnodt, integer 
	*eflag, integer *nfree, real *feq_storage_ye1, real *feq_storage_ze, real *feq_storage_qe1, char *feq_storage_enodid, 
	integer *feq_gen_feq_storage_base_node_vec_d_, ftnlen enodid_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:365* Free node table appears to be \
missing.\002,\002 Make sure that\002,/,5x,\002input block heading starts with\
\002,\002 FREE\002)";
    static char fmt_2030[] = "(//,1x,a)";
    static char fmt_2042[] = "(1x,a5,1x,a16,1x,3f10.2)";
    static char fmt_2043[] = "(1x,a5,1x,a16,1x,3f10.2,1x,a6,1x,a14,a15)";
    static char fmt_2050[] = "(/,\002 *ERR:125* Invalid node number \002,a5)";
    static char fmt_2070[] = "(/,\002 *ERR:126* Invalid initial depth \002,f\
10.2,/,1x,\002Depth must be positive non-zero \002)";
    static char fmt_2075[] = "(/,\002 *WRN:57* Initial depth=\002,f10.2,\002\
 < 0.  Value is\002,\002 only valid if node is an inflow node to an LPR.\002)"
	    ;
    static char fmt_2080[] = "(/,\002 *ERR:127* Number of exterior nodes giv\
en\002,\002 by branches exceeds expected number of \002,i5)";
    static char fmt_2090[] = "(/,\002 *ERR:128* Exterior node \002,a5,\002 p\
reviously \002,\002initialized to \002,f10.2,/,1x,\002Check Branch-Exterior \
Node Table\002)";
    static char fmt_2095[] = "(/,\002 *ERR:129* Exterior node \002,a5,\002 i\
s not free.\002,\002  It is on branch#\002,i5)";
    static char fmt_2114[] = "(1x,\002 Node Node Id_________      Depth Disc\
harge  DatumElv\002)";
    static char fmt_2115[] = "(1x,\002 Node Node Id_________      Depth Disc\
harge  DatumElv\002,\002 Bnode   X or Xoffset   Y or Yoffset   Station\002)";
    static char fmt_2120[] = "(/,\002 *ERR:397 Node= \002,a5,\002 is missing\
 Yoffset value.\002)";

    /* System generated locals */
    address feq_gen_a_d_1[2];
    integer feq_gen_i_d_1, feq_gen_i_d_2[2], feq_gen_i_d_3;
    doublereal feq_gen_d_d_1;
    char feq_gen_ch_d_1[6], feq_gen_ch_d_2[5], feq_gen_ch_d_3[5];
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen), s_cat(char *, char **, 
	    integer *, integer *, ftnlen);
    integer s_rsfi(icilist *), e_rsfi(), i_dnnt(doublereal *), s_wsle(cilist *
	    ), do_lio(integer *, integer *, char *, ftnlen), e_wsle();

    /* Local variables */
    integer feq_gen_item_end_d_[9];
    char cstation[10];
    integer feq_gen_base_node_number_d_;
    doublereal dstation;
    integer feq_gen_i_d_;
    char feq_gen_base_node_d_[5];
    extern /* Subroutine */ int feq_gen_find_code7_d_(integer *, integer *, integer *, 
	    integer *, integer *);
    integer nb, feq_gen_item_start_d_[9];
    char xoffstring[15], yoffstring[15];
    real elv;
    char feq_gen_name_d_[16];
    integer node;
    char line[120], just[5];
    extern /* Subroutine */ int feq_gen_read_free_node_items_d_(integer *, char *, 
	    integer *, integer *, integer *, integer *, char *, char *, real *
	    , real *, real *, char *, char *, char *, char *, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen, ftnlen);
    real disch;
    integer inode;
    real depth;
    integer nitem;
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen),
	     getinn_(char *, integer *, integer *, ftnlen);
    extern integer getusb_(integer *);
    char usnode[5];
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);
    doublereal xoffset, yoffset;
    extern /* Subroutine */ int feq_gen_get_item_limits_d_(integer *, char *, integer *
	    , char *, integer *, integer *, integer *, ftnlen, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__225 = { 0, 0, 0, fmt_2080, 0 };
    static cilist feq_gen_io_d__228 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__229 = { 0, 0, 0, fmt_2030, 0 };
    static cilist feq_gen_io_d__233 = { 0, 0, 0, fmt_2114, 0 };
    static cilist feq_gen_io_d__234 = { 0, 0, 0, fmt_2115, 0 };
    static cilist feq_gen_io_d__245 = { 0, 0, 0, fmt_2042, 0 };
    static cilist feq_gen_io_d__246 = { 0, 0, 0, fmt_2043, 0 };
    static cilist feq_gen_io_d__248 = { 0, 0, 0, fmt_2050, 0 };
    static cilist feq_gen_io_d__249 = { 0, 0, 0, fmt_2090, 0 };
    static cilist feq_gen_io_d__250 = { 0, 0, 0, fmt_2095, 0 };
    static cilist feq_gen_io_d__251 = { 0, 0, 0, fmt_2070, 0 };
    static cilist feq_gen_io_d__252 = { 0, 0, 0, fmt_2075, 0 };
    static cilist feq_gen_io_d__255 = { 0, 0, 0, fmt_2120, 0 };
    static cilist feq_gen_io_d__259 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__260 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Input initial conditions for exterior nodes not on a */
/*     branch. */
/* SOURCE runinit.for:1908 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE runinit.for:1910 */
/*<       integereflag,in,stdout,nbra,nex,nfree,mremc >*/
/* SOURCE runinit.for:1911 */
/*<       integerexnodt(9,nex),base_node_vec(nex),emc(mremc) >*/
/* SOURCE runinit.for:1912 */
/*<       realqe1(nex),ye1(nex),ze(nex) >*/
/* SOURCE runinit.for:1913 */
/*<       characterenodid(nex)*16 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IN     - unit number for the user input file */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     NEX    - number of exterior nodes in the model */
/*     NBRA   - number of branches in the model */
/*     MREMC  - maximum length of EMC(*) */
/*     EMC    - network-matrix control vector. */
/*     EXNODT - exterior node table.  Contains the following items */
/*              for each exterior node. */
/*              Row   Content */
/*               1    sign of the node */
/*               2    pointer into vectors for nodes on a branch, */
/*                    pointer to the other node if on a level-pool reservoir, */
/*                    0 if on a dummy branch. */
/*               3    descriptive code: if -1 then a reservoir node; */
/*                    if  0 then not on a branch and not a reservoir node; */
/*                    if > 0 then a branch number.  The inflow node */
/*                    to a reservoir has the value of 0.  The way it is */
/*                    distinguished from a free node on a dummy branch */
/*                    is that EXNODT(4, ) is zero for a reservoir-inflow */
/*                    node but is positive for a free node on a dummy */
/*                    branch. */
/*               4    pointer to a cross section table if on a branch, */
/*                    to storage table if a reservoir, to other node if */
/*                    a dummy branch, 0 if the inflow node to a reservoir. */
/*               5    gives the variable number(in the system matrix) for */
/*                    the flow at the exterior node. Also a junction */
/*                    pointer in initial processing of input */
/*               6    X location of the node in a cartesian coordinate system */
/*               7    Y location of the node in a cartesian coordinate system. */
/*                   The (X,Y) are scaled upward by 100.  That is */
/*                   a coordinate value of 1234.51 becomes then integer */
/*                   123451.  If the coordinate value is -(2**31 -1) it */
/*                   indicates that no value for a coordinate exists. */
/*                   The scaling permits a maximum value of 2**31/100 */
/*                   distance units.  When the length unit is feet the */
/*                   maximum coordinate is 21,474,836.48 feet or */
/*                   about 4067 miles.  This appears to be adequate */
/*                   for any reasonable purpose! */
/*                8  Contains the station for the free node.  These */
/*                   stations are assigned by the user.  The utility */
/*                   program OVERFLOW, used to compute outflows/inflows */
/*                   between adjacent flow paths, assigns the station */
/*                   of the source location to the upstream node */
/*                   and the station of the sink to the downstream */
/*                   node, if either exist.  If neither exists it */
/*                   assigns -(2**31 - 1).  The station is */
/*                   multiplied by 10,000 and rounded before */
/*                   being placed in the integer location.  This */
/*                   gives a maximum station of at least 40 miles */
/*                   if feet are being used for the stations.  This */
/*                   should be adequate because using feet for stationing */
/*                   over such a distance would be unusual. */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     NFREE  - number of free nodes */
/*     YE1    - depths at exterior nodes at start of time step */
/*     ZE     - elevation of datum for depth at exterior node */
/*     QE1    - flow at exterior nodes at start of time step */
/*     ENODID - exterior node identification string given by user */
/*     BASE_NODE_VEC - value of base node to use in defining the */
/*                     location of the node */

/*     + + + LOCAL VARIABLES + + + */
/* SOURCE runinit.for:1979 */
/*<       integermxitem >*/
/* SOURCE runinit.for:1980 */
/*<       parameter(mxitem=9) >*/
/* SOURCE runinit.for:1981 */
/*<        >*/
/* SOURCE runinit.for:1983 */
/*<       realdepth,disch,elv >*/
/* SOURCE runinit.for:1984 */
/*<        >*/
/* SOURCE runinit.for:1987 */
/*<       real*8xoffset,yoffset,dstation >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE runinit.for:1990 */
/*<       integergetusb >*/
/* SOURCE runinit.for:1991 */
/*<       charactergetusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE runinit.for:1994 */
/*<        >*/
/*     + + + INPUT FORMATS + + + */
/* 1000 FORMAT(20A4) */
/* 1030 FORMAT(A5,3F10.0,I5) */
/* 1032 FORMAT(A5,1X,A16,1X,3F10.0,I5) */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE runinit.for:2003 */
/*<    50  >*/
/* SOURCE runinit.for:2006 */
/*<  2030 format(//,1x,a) >*/
/* SOURCE runinit.for:2007 */
/*<  2042 format(1x,a5,1x,a16,1x,3f10.2) >*/
/* SOURCE runinit.for:2008 */
/*<  2043 format(1x,a5,1x,a16,1x,3f10.2,1x,a6,1x,a14,a15) >*/
/* SOURCE runinit.for:2009 */
/*<  2050 format(/,' *ERR:125* Invalid node number ',a5) >*/
/* SOURCE runinit.for:2010 */
/*<  2070  >*/
/* SOURCE runinit.for:2012 */
/*<  2075  >*/
/* SOURCE runinit.for:2014 */
/*<  2080  >*/
/* SOURCE runinit.for:2016 */
/*<  2090  >*/
/* SOURCE runinit.for:2019 */
/*<  2095  >*/
/* SOURCE runinit.for:2021 */
/*<  2114 format(1x,' Node Node Id_________      Depth Discharge  DatumElv') >*/
/* SOURCE runinit.for:2022 */
/*<  2115  >*/
/* SOURCE runinit.for:2024 */
/*<  2120 format(/,' *ERR:397 Node= ',a5,' is missing Yoffset value.') >*/
/* *********************************************************************** */
/*     Set justification for the heading-dependent format */
/* SOURCE runinit.for:2027 */
/*<       just='RIGHT' >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_base_node_vec_d_(feq_gen_feq_storage_base_node_vec_d_, 1);

    feq::IndexedPointer<char> enodid(feq_storage_enodid, 16);

    feq::IndexedPointer<real> qe1(feq_storage_qe1, 1);

    feq::IndexedPointer<real> ze(feq_storage_ze, 1);

    feq::IndexedPointer<real> ye1(feq_storage_ye1, 1);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* L50: */
/* L2030: */
/* L2042: */
/* L2043: */
/* L2050: */
/* L2070: */
/* L2075: */
/* L2080: */
/* L2090: */
/* L2095: */
/* L2114: */
/* L2115: */
/* L2120: */
    s_copy(just, const_cast<char*>("RIGHT"), (ftnlen)5, (ftnlen)5);
/*     CHECK FOR EXTERIOR NODES NOT ON A BRANCH */
/* SOURCE runinit.for:2030 */
/*<       nfree=nex-2*nbra >*/
    *nfree = *nex - (*nbra << 1);
/* SOURCE runinit.for:2031 */
/*<       if(nfree.ge.0)goto105 >*/
    if (*nfree >= 0) {
	goto L105;
    }
/* SOURCE runinit.for:2032 */
/*<       write(stdout,2080)nex >*/
    feq_gen_io_d__225.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__225);
    do_fio(&feq_gen_c_d_1, (char *)&(*nex), (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE runinit.for:2033 */
/*<       eflag=1 >*/
    *eflag = 1;
/* SOURCE runinit.for:2035 */
/*<   105 continue >*/
L105:
/* SOURCE runinit.for:2036 */
/*<       if(nfree.le.0)goto210 >*/
    if (*nfree <= 0) {
	goto L210;
    }
/*     SET YE1 TO ZERO FOR USE IN LATER CHECKING OF INPUT */
/*     Clear BASE_NODE_VEC to pass over nodes on branches */
/*     in later processing. */
/* SOURCE runinit.for:2042 */
/*<       do107i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:2043 */
/*<       ye1(i)=0.0 >*/
	ye1[feq_gen_i_d_] = (float)0.;
/* SOURCE runinit.for:2044 */
/*<       base_node_vec(i)=0 >*/
	feq_gen_base_node_vec_d_[feq_gen_i_d_] = 0;
/* SOURCE runinit.for:2045 */
/*<   107 continue >*/
/* L107: */
    }
/*     HEADINGS FOR EXTERIOR NODES NOT ON  A BRANCH */
/* SOURCE runinit.for:2049 */
/*<       callinline(in,stdout,line) >*/
    inline_(in, stdout, line, (ftnlen)120);
/* SOURCE runinit.for:2052 */
/*<       if(line(1:4).ne.'FREE')then >*/
    if (s_cmp(line, const_cast<char*>("FREE"), (ftnlen)4, (ftnlen)4) != 0) {
/*       Missing lines of input or input out of order. */
/* SOURCE runinit.for:2054 */
/*<       write(stdout,50) >*/
	feq_gen_io_d__228.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__228);
	e_wsfe();
/* SOURCE runinit.for:2055 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:2056 */
/*<       endif >*/
    }
/* SOURCE runinit.for:2057 */
/*<       write(stdout,2030)line >*/
    feq_gen_io_d__229.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__229);
    do_fio(&feq_gen_c_d_1, line, (ftnlen)120);
    e_wsfe();
/* SOURCE runinit.for:2058 */
/*<       callinline(in,stdout,line) >*/
    inline_(in, stdout, line, (ftnlen)120);
/*     Define the limits for the items on a line. */
/* SOURCE runinit.for:2062 */
/*<        >*/
    feq_gen_get_item_limits_d_(stdout, line, &feq_gen_c_d_9, just, &nitem, feq_gen_item_start_d_, 
	    feq_gen_item_end_d_, (ftnlen)120, (ftnlen)5);
/*     Output standard heading in place of user's heading */
/* SOURCE runinit.for:2067 */
/*<       if(nitem.le.6)then >*/
    if (nitem <= 6) {
/* SOURCE runinit.for:2068 */
/*<       write(stdout,2114) >*/
	feq_gen_io_d__233.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__233);
	e_wsfe();
/* SOURCE runinit.for:2069 */
/*<       else >*/
    } else {
/* SOURCE runinit.for:2070 */
/*<       write(stdout,2115) >*/
	feq_gen_io_d__234.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__234);
	e_wsfe();
/* SOURCE runinit.for:2071 */
/*<       endif >*/
    }
/* SOURCE runinit.for:2073 */
/*<       do200nb=1,nfree >*/
    feq_gen_i_d_1 = *nfree;
    for (nb = 1; nb <= feq_gen_i_d_1; ++nb) {
/* SOURCE runinit.for:2074 */
/*<       callinline(in,stdout,line) >*/
	inline_(in, stdout, line, (ftnlen)120);
/* SOURCE runinit.for:2077 */
/*<        >*/
	feq_gen_read_free_node_items_d_(stdout, line, &nitem, feq_gen_item_start_d_, feq_gen_item_end_d_,
		 eflag, usnode, feq_gen_name_d_, &depth, &disch, &elv, feq_gen_base_node_d_, 
		xoffstring, yoffstring, cstation, (ftnlen)120, (ftnlen)5, (
		ftnlen)16, (ftnlen)5, (ftnlen)15, (ftnlen)15, (ftnlen)10);
/* SOURCE runinit.for:2083 */
/*<       if(nitem.le.6)then >*/
	if (nitem <= 6) {
/* SOURCE runinit.for:2084 */
/*<       write(stdout,2042)usnode,name,depth,disch,elv >*/
	    feq_gen_io_d__245.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__245);
	    do_fio(&feq_gen_c_d_1, usnode, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&depth, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&disch, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&elv, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE runinit.for:2085 */
/*<       else >*/
	} else {
/* SOURCE runinit.for:2086 */
/*<        >*/
	    feq_gen_io_d__246.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__246);
	    do_fio(&feq_gen_c_d_1, usnode, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&depth, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&disch, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&elv, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, feq_gen_base_node_d_, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, xoffstring, (ftnlen)15);
	    do_fio(&feq_gen_c_d_1, yoffstring, (ftnlen)15);
	    do_fio(&feq_gen_c_d_1, cstation, (ftnlen)10);
	    e_wsfe();
/* SOURCE runinit.for:2089 */
/*<       endif >*/
	}
/* SOURCE runinit.for:2091 */
/*<       callgetinn(usnode,eflag,node) >*/
	getinn_(usnode, eflag, &node, (ftnlen)5);
/* SOURCE runinit.for:2094 */
/*<       if(node.le.0)then >*/
	if (node <= 0) {
/* SOURCE runinit.for:2095 */
/*<       write(stdout,2050)'-'//getusn(-node) >*/
	    feq_gen_io_d__248.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__248);
/* Writing concatenation */
	    feq_gen_i_d_2[0] = 1, feq_gen_a_d_1[0] = const_cast<char*>("-");
	    feq_gen_i_d_3 = -node;
	    getusn_(feq_gen_ch_d_2, (ftnlen)5, &feq_gen_i_d_3);
	    feq_gen_i_d_2[1] = 5, feq_gen_a_d_1[1] = feq_gen_ch_d_2;
	    s_cat(feq_gen_ch_d_1, feq_gen_a_d_1, feq_gen_i_d_2, &feq_gen_c_d_2, (ftnlen)6);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)6);
	    e_wsfe();
/* SOURCE runinit.for:2096 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:2097 */
/*<       endif >*/
	}
/*       CHECK FOR DUPLICATION OF NODE NUMBERING */
/* SOURCE runinit.for:2101 */
/*<   110 if(ye1(node).eq.0.)goto120 >*/
/* L110: */
	if (ye1[node] == (float)0.) {
	    goto L120;
	}
/* SOURCE runinit.for:2102 */
/*<       write(stdout,2090)getusn(node),ye1(node) >*/
	feq_gen_io_d__249.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__249);
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &node);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, (char *)&ye1[node], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE runinit.for:2103 */
/*<       eflag=1 >*/
	*eflag = 1;
/*       IS GIVEN NODE A FREE NODE? */
/* SOURCE runinit.for:2107 */
/*<   120 continue >*/
L120:
/* SOURCE runinit.for:2108 */
/*<       if(exnodt(3,node).le.0)goto125 >*/
	if (exnodt[node * 9 + 3] <= 0) {
	    goto L125;
	}
/* SOURCE runinit.for:2109 */
/*<       write(stdout,2095)getusn(node),getusb(exnodt(3,node)) >*/
	feq_gen_io_d__250.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__250);
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &node);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	feq_gen_i_d_3 = getusb_(&exnodt[node * 9 + 3]);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_3, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE runinit.for:2110 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE runinit.for:2111 */
/*<   125 continue >*/
L125:
/* SOURCE runinit.for:2112 */
/*<       if(depth.gt.0.)goto130 >*/
	if (depth > (float)0.) {
	    goto L130;
	}
/*       If the node is a reservoir node or an inflow node to a reservoir, */
/*       then a negative depth is really an elevation if the depth datum */
/*       for the node is 0.0.  At this point there is no sure way of establishing */
/*       that a node is an inflow node because when we see the inflow node */
/*       there is no flag that says so.  Changing EXNODT(3,*) is complex */
/*       because it is heavily used in the development of the solution matrices. */
/*       We do the following: 1. if the node is a reservoir node-no message */
/*       if the depth datum is 0.0. 2. for other nodes issue a warning */
/*       if depth is less than 0.0 and the depth datum is zero.  3. */
/*       Issue an error message in other cases. */
/* SOURCE runinit.for:2123 */
/*<       if(exnodt(3,node).ne.-1)then >*/
	if (exnodt[node * 9 + 3] != -1) {
/* SOURCE runinit.for:2124 */
/*<       if(elv.ne.0.0)then >*/
	    if (elv != (float)0.) {
/* SOURCE runinit.for:2125 */
/*<       write(stdout,2070)depth >*/
		feq_gen_io_d__251.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__251);
		do_fio(&feq_gen_c_d_1, (char *)&depth, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE runinit.for:2126 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE runinit.for:2127 */
/*<       else >*/
	    } else {
/* SOURCE runinit.for:2128 */
/*<       write(stdout,2075)depth >*/
		feq_gen_io_d__252.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__252);
		do_fio(&feq_gen_c_d_1, (char *)&depth, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE runinit.for:2129 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:2130 */
/*<       endif >*/
	}
/* SOURCE runinit.for:2132 */
/*<   130 ye1(node)=depth >*/
L130:
	ye1[node] = depth;
/* SOURCE runinit.for:2133 */
/*<       qe1(node)=disch >*/
	qe1[node] = disch;
/* SOURCE runinit.for:2134 */
/*<       ze(node)=elv >*/
	ze[node] = elv;
/* SOURCE runinit.for:2135 */
/*<       enodid(node)=name >*/
	s_copy(enodid + (node << 4), feq_gen_name_d_, (ftnlen)16, (ftnlen)16);
/*       Process optional items if present. */
/* SOURCE runinit.for:2138 */
/*<       if(nitem.eq.9)then >*/
	if (nitem == 9) {
/*         Optional input here.  We can only process partially here */
/*         because the standard linkage to the cross-section function */
/*         tables does not yet exist.  If the BASE_NODE is non-blank */
/*         convert to the internal number and store for later processing */
/* SOURCE runinit.for:2143 */
/*<       if(base_node.ne.' ')then >*/
	    if (s_cmp(feq_gen_base_node_d_, const_cast<char*>(" "), (ftnlen)5, (ftnlen)1) != 0) {
/* SOURCE runinit.for:2144 */
/*<       callgetinn(base_node,eflag,base_node_number) >*/
		getinn_(feq_gen_base_node_d_, eflag, &feq_gen_base_node_number_d_, (ftnlen)5);
/* SOURCE runinit.for:2148 */
/*<       base_node_vec(node)=base_node_number >*/
		feq_gen_base_node_vec_d_[node] = feq_gen_base_node_number_d_;
/* SOURCE runinit.for:2149 */
/*<       else >*/
	    } else {
/* SOURCE runinit.for:2150 */
/*<       base_node_vec(node)=0 >*/
		feq_gen_base_node_vec_d_[node] = 0;
/* SOURCE runinit.for:2151 */
/*<       endif >*/
	    }
/*         The headings for the offsets may be present even when no */
/*         values are given.  Thus it is possible that a blank could */
/*         exist in all fields as the model is being developed. */
/*         We only convert non-blank fields to numbers.  All values */
/*         have been set to null in subroutine BRIN so that we */
/*         can assume that the null values are present. */
/* SOURCE runinit.for:2158 */
/*<       if(xoffstring.ne.' ')then >*/
	    if (s_cmp(xoffstring, const_cast<char*>(" "), (ftnlen)15, (ftnlen)1) != 0) {
/*           Use LINE so that the standard error message will work. */
/* SOURCE runinit.for:2160 */
/*<       line=xoffstring >*/
		s_copy(line, xoffstring, (ftnlen)120, (ftnlen)15);
/* SOURCE runinit.for:2161 */
/*<       read(line(1:15),'(F15.0)',err=991)xoffset >*/
		feq_gen_ici_d_1.icierr = 1;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 15;
		feq_gen_ici_d_1.iciunit = line;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(F15.0)");
		feq_gen_i_d_3 = s_rsfi(&feq_gen_ici_d_1);
		if (feq_gen_i_d_3 != 0) {
		    goto L991;
		}
		feq_gen_i_d_3 = do_fio(&feq_gen_c_d_1, (char *)&xoffset, (ftnlen)sizeof(
			doublereal));
		if (feq_gen_i_d_3 != 0) {
		    goto L991;
		}
		feq_gen_i_d_3 = e_rsfi();
		if (feq_gen_i_d_3 != 0) {
		    goto L991;
		}
/* SOURCE runinit.for:2162 */
/*<       exnodt(6,node)=nint(xoffset*100.d0) >*/
		feq_gen_d_d_1 = xoffset * 100.;
		exnodt[node * 9 + 6] = i_dnnt(&feq_gen_d_d_1);
/* SOURCE runinit.for:2163 */
/*<       if(yoffstring.eq.' ')then >*/
		if (s_cmp(yoffstring, const_cast<char*>(" "), (ftnlen)15, (ftnlen)1) == 0) {
/* SOURCE runinit.for:2164 */
/*<       write(stdout,2120)usnode >*/
		    feq_gen_io_d__255.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__255);
		    do_fio(&feq_gen_c_d_1, usnode, (ftnlen)5);
		    e_wsfe();
/* SOURCE runinit.for:2165 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE runinit.for:2166 */
/*<       else >*/
		} else {
/* SOURCE runinit.for:2167 */
/*<       line=yoffstring >*/
		    s_copy(line, yoffstring, (ftnlen)120, (ftnlen)15);
/* SOURCE runinit.for:2168 */
/*<       read(line(1:15),'(F15.0)',err=991)yoffset >*/
		    feq_gen_ici_d_1.icierr = 1;
		    feq_gen_ici_d_1.iciend = 0;
		    feq_gen_ici_d_1.icirnum = 1;
		    feq_gen_ici_d_1.icirlen = 15;
		    feq_gen_ici_d_1.iciunit = line;
		    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F15.0)");
		    feq_gen_i_d_3 = s_rsfi(&feq_gen_ici_d_1);
		    if (feq_gen_i_d_3 != 0) {
			goto L991;
		    }
		    feq_gen_i_d_3 = do_fio(&feq_gen_c_d_1, (char *)&yoffset, (ftnlen)sizeof(
			    doublereal));
		    if (feq_gen_i_d_3 != 0) {
			goto L991;
		    }
		    feq_gen_i_d_3 = e_rsfi();
		    if (feq_gen_i_d_3 != 0) {
			goto L991;
		    }
/* SOURCE runinit.for:2169 */
/*<       exnodt(7,node)=nint(yoffset*100.d0) >*/
		    feq_gen_d_d_1 = yoffset * 100.;
		    exnodt[node * 9 + 7] = i_dnnt(&feq_gen_d_d_1);
/* SOURCE runinit.for:2170 */
/*<       endif >*/
		}
/* SOURCE runinit.for:2171 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:2173 */
/*<       if(cstation.ne.' ')then >*/
	    if (s_cmp(cstation, const_cast<char*>(" "), (ftnlen)10, (ftnlen)1) != 0) {
/* SOURCE runinit.for:2174 */
/*<       line=cstation >*/
		s_copy(line, cstation, (ftnlen)120, (ftnlen)10);
/* SOURCE runinit.for:2175 */
/*<       read(line(1:10),'(F10.0)',err=991)dstation >*/
		feq_gen_ici_d_1.icierr = 1;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 10;
		feq_gen_ici_d_1.iciunit = line;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.0)");
		feq_gen_i_d_3 = s_rsfi(&feq_gen_ici_d_1);
		if (feq_gen_i_d_3 != 0) {
		    goto L991;
		}
		feq_gen_i_d_3 = do_fio(&feq_gen_c_d_1, (char *)&dstation, (ftnlen)sizeof(
			doublereal));
		if (feq_gen_i_d_3 != 0) {
		    goto L991;
		}
		feq_gen_i_d_3 = e_rsfi();
		if (feq_gen_i_d_3 != 0) {
		    goto L991;
		}
/* SOURCE runinit.for:2176 */
/*<       exnodt(8,node)=nint(dstation*1.d4) >*/
		feq_gen_d_d_1 = dstation * 1e4;
		exnodt[node * 9 + 8] = i_dnnt(&feq_gen_d_d_1);
/* SOURCE runinit.for:2177 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:2178 */
/*<       endif >*/
	}


/*       Catch the LPR nodes, that is, the dns free node of an LPR, and */
/*       set EXNODT(2,*) so that the dns node entry points to the upstream */
/*       node and the upstream node (inflow node) points to the dns node. */
/* SOURCE runinit.for:2186 */
/*<       if(exnodt(3,node).eq.0)then >*/
	if (exnodt[node * 9 + 3] == 0) {
/*         Node is not an LPR node.  Either on a dummy branch or */
/*         inflow node to a LPR. */
/* SOURCE runinit.for:2189 */
/*<       if(exnodt(4,node).gt.0)then >*/
	    if (exnodt[node * 9 + 4] > 0) {
/*           It is on a dummy branch.  We then clear EXNODT(2,*) */
/*           Clear the pointer in slot 2.  Used earlier in */
/*           constructing the pattern in the solution matrix. May */
/*           cause problems later if non-zero.  A check has been made */
/*           to try to catch all occurences of use but clear to be */
/*           sure. */
/* SOURCE runinit.for:2196 */
/*<       exnodt(2,node)=0 >*/
		exnodt[node * 9 + 2] = 0;
/* SOURCE runinit.for:2197 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:2198 */
/*<       else >*/
	} else {
/*         Here the node is an LPR node.  We only see free nodes in this routine. */
/*         If EXNODT(3,NODE) is not zero, then it must by -1, because if */
/*         EXNODT(3,NODE) is positive, then NODE is on a branch. */
/*         However, the user might be confused and we may have reported an error */
/*         above so we must check here as well to protect against further errors */
/*         being generated. */
/* SOURCE runinit.for:2205 */
/*<       if(exnodt(3,node).eq.-1)then >*/
	    if (exnodt[node * 9 + 3] == -1) {
/*           We don't know the inflow node.  The two nodes are stored in EMC. */
/*           We cannot set EXNODT(2,*) in EXIN because there that slot is used */
/*           for a pointer into EMC so that the matrix formation routines can find */
/*           there information.  Thus, we must set the values here to avoid */
/*           conflict.  The evolution of a software product adds to its complexity! */
/*           Thus we search EMC for a code 7 with the NODE as the LPR node. */
/* SOURCE runinit.for:2213 */
/*<       callfind_code7(stdout,node,mremc,emc,inode) >*/
		feq_gen_find_code7_d_(stdout, &node, mremc, &emc[1], &inode);
/*           Now have the two nodes on the LPR point to each other. */
/* SOURCE runinit.for:2216 */
/*<       exnodt(2,node)=inode >*/
		exnodt[node * 9 + 2] = inode;
/* SOURCE runinit.for:2217 */
/*<       exnodt(2,inode)=node >*/
		exnodt[inode * 9 + 2] = node;
/* SOURCE runinit.for:2218 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:2219 */
/*<       endif >*/
	}
/* SOURCE runinit.for:2221 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE runinit.for:2223 */
/*<   210 return >*/
L210:
    return 0;
/* SOURCE runinit.for:2224 */
/*<   991 continue >*/
L991:
/* SOURCE runinit.for:2225 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__259.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__259);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE runinit.for:2226 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__260.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__260);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)120);
    e_wsle();
/* SOURCE runinit.for:2227 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:2228 */
/*<       end >*/
    return 0;
} /* exinit_ */




/* SOURCE runinit.for:2232 */
/*<       subroutinefndcd(stdout,adrs,grav,epsb,qr,yr,eflag) >*/
/* Subroutine */ int fndcd_(integer *stdout, integer *adrs, real *grav, real *
	epsb, real *qr, real *yr, integer *eflag)
{
    /* Format strings */
    static char fmt_2130[] = "(/,\002 *ERR:95* Maximum iterations exceeded f\
or \002,\002Backwater Analysis\002)";
    static char fmt_2140[] = "(/,\002 Critical depth Debug: \002,/,4x,\002I\
T\002,4x,\002New Depth\002,4x,\002Old Depth\002,5x,\002Residual\002,3x,\002D\
erivative\002,4x,\002Discharge\002)";
    static char fmt_2150[] = "(1x,i5,5(1pe13.5))";

    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    real f, df, ar, br;
    integer it;
    real kr, tr, dbr, dkr, dtr, yta;
    integer iflag;
    extern /* Subroutine */ int xlkt20_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *);
    real qrsqr, yrsave;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__275 = { 0, 0, 0, fmt_2150, 0 };
    static cilist feq_gen_io_d__276 = { 0, 0, 0, fmt_2130, 0 };
    static cilist feq_gen_io_d__277 = { 0, 0, 0, fmt_2140, 0 };


/*     + + + PURPOSE + + + */
/*     Find critical depth in the cross section given by ADRS and */
/*     for the flow given by QR.  Computed ignoring non-uniform */
/*     velocity distribution to be compatible with past usage */
/*     in BCKWTR.  Used only for initial conditions. */
/* SOURCE runinit.for:2243 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE runinit.for:2245 */
/*<       integeradrs,eflag,stdout >*/
/* SOURCE runinit.for:2246 */
/*<       realepsb,grav,qr,yr >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     ADRS   - address of the function table in FTAB/ITAB */
/*     GRAV   - value of acceleration due to gravity */
/*     EPSB   - convergence limit for steady flow computations */
/*     QR     - flow */
/*     YR     - critical depth estimate and final value */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE runinit.for:2258 */
/*<       integeriflag,it >*/
/* SOURCE runinit.for:2259 */
/*<       realar,br,dbr,df,dkr,dtr,f,kr,qrsqr,tr,yrsave,yta >*/
/*     + + + INTRINSICS + + + */
/* SOURCE runinit.for:2262 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE runinit.for:2265 */
/*<       externalxlkt20 >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE runinit.for:2268 */
/*<  2130  >*/
/* SOURCE runinit.for:2270 */
/*<  2140  >*/
/* SOURCE runinit.for:2273 */
/*<  2150 format(1x,i5,5(1pe13.5)) >*/
/* *********************************************************************** */
/*      WRITE(STDOUT,*) ' ENTERING FNDCD: YR=',YR */
/*     Find the elements at the initial estimate, YR. */
/* SOURCE runinit.for:2277 */
/*<       callxlkt20(adrs,yr,ar,tr,dtr,kr,dkr,br,dbr) >*/
/* L2130: */
/* L2140: */
/* L2150: */
    xlkt20_(adrs, yr, &ar, &tr, &dtr, &kr, &dkr, &br, &dbr);
/*     Save the initial estimate for debugging dump */
/* SOURCE runinit.for:2283 */
/*<       yrsave=yr >*/
    yrsave = *yr;
/* SOURCE runinit.for:2284 */
/*<       iflag=0 >*/
    iflag = 0;
/* SOURCE runinit.for:2285 */
/*<       it=0 >*/
    it = 0;
/* SOURCE runinit.for:2286 */
/*<       qrsqr=qr*qr >*/
    qrsqr = static_cast<double>(*qr) * *qr;
/* SOURCE runinit.for:2287 */
/*<   125 continue >*/
L125:
/* SOURCE runinit.for:2288 */
/*<       f=qrsqr-grav*ar**3/tr >*/
/* Computing 3rd power */
    feq_gen_r_d_1 = ar;
    f = static_cast<double>(qrsqr) - static_cast<double>(static_cast<double>(*grav) * (static_cast<double>(feq_gen_r_d_1) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1))) / tr;
/*        WRITE(STDOUT,*) ' F=',F */
/* SOURCE runinit.for:2290 */
/*<       if(abs(f)/qrsqr.gt.epsb)then >*/
    if (dabs(f) / qrsqr > *epsb) {
/* SOURCE runinit.for:2291 */
/*<       df=-grav*ar**2*(3.0-ar*dtr/tr**2) >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = ar;
/* Computing 2nd power */
	feq_gen_r_d_2 = tr;
	df = static_cast<double>(static_cast<double>(-(*grav)) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) * (static_cast<double>((float)3.) - static_cast<double>(static_cast<double>(ar) * dtr) / (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2))
		;
/* SOURCE runinit.for:2292 */
/*<       yta=yr-f/df >*/
	yta = static_cast<double>(*yr) - static_cast<double>(f) / df;
/* SOURCE runinit.for:2293 */
/*<       if(iflag.eq.1)write(stdout,2150)it,yta,yr,f,df >*/
	if (iflag == 1) {
	    feq_gen_io_d__275.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__275);
	    do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&yta, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&(*yr), (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&f, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&df, (ftnlen)sizeof(real));
	    e_wsfe();
	}
/* SOURCE runinit.for:2294 */
/*<       if(yta.lt.0.0)yta=0.5*yr >*/
	if (yta < (float)0.) {
	    yta = static_cast<double>(*yr) * (float).5;
	}
/* SOURCE runinit.for:2295 */
/*<       yr=yta >*/
	*yr = yta;
/* SOURCE runinit.for:2296 */
/*<       callxlkt20(adrs,yr,ar,tr,dtr,kr,dkr,br,dbr) >*/
	xlkt20_(adrs, yr, &ar, &tr, &dtr, &kr, &dkr, &br, &dbr);
/* SOURCE runinit.for:2300 */
/*<       it=it+1 >*/
	++it;
/* SOURCE runinit.for:2301 */
/*<       if(it.gt.100)then >*/
	if (it > 100) {
/* SOURCE runinit.for:2302 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE runinit.for:2303 */
/*<       if(iflag.eq.0)then >*/
	    if (iflag == 0) {
/* SOURCE runinit.for:2304 */
/*<       write(stdout,2130) >*/
		feq_gen_io_d__276.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__276);
		e_wsfe();
/* SOURCE runinit.for:2305 */
/*<       write(stdout,2140) >*/
		feq_gen_io_d__277.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__277);
		e_wsfe();
/* SOURCE runinit.for:2306 */
/*<       iflag=1 >*/
		iflag = 1;
/* SOURCE runinit.for:2307 */
/*<       it=0 >*/
		it = 0;
/* SOURCE runinit.for:2308 */
/*<       yr=yrsave >*/
		*yr = yrsave;
/* SOURCE runinit.for:2309 */
/*<       callxlkt20(adrs,yr,ar,tr,dtr,kr,dkr,br,dbr) >*/
		xlkt20_(adrs, yr, &ar, &tr, &dtr, &kr, &dkr, &br, &dbr);
/* SOURCE runinit.for:2313 */
/*<       goto125 >*/
		goto L125;
/* SOURCE runinit.for:2314 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:2315 */
/*<       else >*/
	} else {
/* SOURCE runinit.for:2316 */
/*<       goto125 >*/
	    goto L125;
/* SOURCE runinit.for:2317 */
/*<       endif >*/
	}
/* SOURCE runinit.for:2318 */
/*<       endif >*/
    }
/* SOURCE runinit.for:2319 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:2320 */
/*<       end >*/
} /* fndcd_ */




/* SOURCE runinit.for:2324 */
/*<        >*/
/* Subroutine */ int getic_(integer *stdout, integer *getdsn, char *feq_gen_name_d_, 
	integer *nbra, integer *nbn, integer *nex, doublereal *jtime, integer 
	*nblk, integer *feq_storage_opblk, integer *bnode, real *wt, real *siter, 
	doublereal *dt, integer *feq_storage_exnodt, ftnlen name_len)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *ERR:199* Expected \002,i4,\002 branches b\
ut found \002,i4,\002 in GETIC file:\002/,11x,a)";
    static char fmt_52[] = "(\002 *ERR:200* Expected \002,i4,\002 exterior n\
odes but found \002,i4,\002 in GETIC file:\002/,11x,a)";
    static char fmt_54[] = "(\002 *ERR:201* Expected \002,i4,\002 nodes on b\
ranches but \002,\002found \002,i4,\002 in GETIC file:\002/,11x,a)";
    static char fmt_56[] = "(\002 *ERR:202* Unable to continue because model\
 in GETIC\002,\002 file differs\002,/,11x,\002 from current model.\002)";
    static char fmt_58[] = "(\002 *WRN:45* Start time leads time in GETIC fi\
le\002,\002 by \002,1pe10.3,\002 seconds.\002)";
    static char fmt_60[] = "(/,\002 Initial conditions read at JTIME=\002,f2\
0.10)";
    static char fmt_62[] = "(\002 *ERR:216* Expected BNODE=\002,a5,\002 but\
 \002,\002found BNODE=\002,a5,\002 in GETIC file:\002/,11x,a)";

    /* System generated locals */
    doublereal feq_gen_d_d_1;
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5], feq_gen_ch_d_3[5], feq_gen_ch_d_4[5];
    olist feq_gen_o_d_1;
    inlist feq_gen_ioin_d_1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), f_open(olist *), f_inqu(
	    inlist *), s_wsle(cilist *), do_lio(integer *, integer *, char *, 
	    ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_rdue(cilist *), do_uio(integer *, char *, ftnlen), e_rdue(), 
	    s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_free_unit_d_(integer *, integer *);
    integer it, feq_gen_flag_d_, fnbn, fnex;
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);
    integer fnbra, bwrec;
    logical there;
    extern /* Subroutine */ int bwget_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, real *);
    integer dummy, fbnode;
    doublereal fjtime;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__280 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__281 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__283 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__286 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__288 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__291 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__293 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__295 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__296 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__297 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__298 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__299 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__300 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__301 = { 0, 0, 0, fmt_60, 0 };


/*     + + + PURPOSE + + + */
/*     Get current state of system from dataset given by GETDSN. */
/* SOURCE runinit.for:2332 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE runinit.for:2334 */
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
/* SOURCE runinit.for:2337 */
/*<       integerbnode,getdsn,nblk,nbn,nbra,nex,stdout >*/
/* SOURCE runinit.for:2338 */
/*<       integerexnodt(9,nex),opblk(mnblk) >*/
/* SOURCE runinit.for:2339 */
/*<       realsiter,wt >*/
/* SOURCE runinit.for:2340 */
/*<       real*8dt,jtime >*/
/* SOURCE runinit.for:2341 */
/*<       charactername*256 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - standard output unit for user messages */
/*     GETDSN - unit number for reading initial conditions */
/*     NAME   - name of the file containing the initial conditions */
/*     NBRA   - number of branches in the model */
/*     NBN    - total number on nodes on branches in the model */
/*     NEX    - number of exterior nodes in the model */
/*     JTIME  - current modified julian time in the model */
/*     NBLK   - number of operation blocks */
/*     OPBLK  - pointer into the function table storage(FTAB/ITAB) for */
/*               each operation block. */
/*     BNODE  - boundary node number at which to start defining the */
/*               coefficient matrix */

/*     WT     - weight factor for approximating time integrals */
/*     SITER  - weighted sum of iterations to convergence */
/*     DT     - time step in seconds */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE runinit.for:2362 */
/*<       integerfbnode,flag,fnbn,fnbra,fnex,bwrec,dummy,it >*/
/* SOURCE runinit.for:2363 */
/*<       real*8fjtime >*/
/* SOURCE runinit.for:2364 */
/*<       logicalthere >*/
/*     + + + INTRINSICS + + + */
/* SOURCE runinit.for:2367 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE runinit.for:2370 */
/*<       charactergetusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE runinit.for:2373 */
/*<       externalbwget,getusn,free_unit >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE runinit.for:2324 */
/*<       integer feq_len_trim >*/
/* SOURCE runinit.for:2324 */
/*<       external feq_len_trim >*/
/* SOURCE runinit.for:2376 */
/*<    50  >*/
/* SOURCE runinit.for:2378 */
/*<    52  >*/
/* SOURCE runinit.for:2380 */
/*<    54  >*/
/* SOURCE runinit.for:2382 */
/*<    56  >*/
/* SOURCE runinit.for:2384 */
/*<    58  >*/
/* SOURCE runinit.for:2386 */
/*<    60 format(/,' Initial conditions read at JTIME=',f20.10) >*/
/* SOURCE runinit.for:2387 */
/*<    62  >*/
/* *********************************************************************** */
/* SOURCE runinit.for:2390 */
/*<       if(name.eq.' ')then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> opblk(feq_storage_opblk, 1);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
/* L60: */
/* L62: */
    if (s_cmp(feq_gen_name_d_, const_cast<char*>(" "), (ftnlen)256, (ftnlen)1) == 0) {
/* SOURCE runinit.for:2391 */
/*<        >*/
	feq_gen_o_d_1.oerr = 0;
	feq_gen_o_d_1.ounit = *getdsn;
	feq_gen_o_d_1.ofnmlen = 4;
	feq_gen_o_d_1.ofnm = const_cast<char*>("GETD");
	feq_gen_o_d_1.orl = 8;
	feq_gen_o_d_1.osta = const_cast<char*>("OLD");
	feq_gen_o_d_1.oacc = const_cast<char*>("direct");
	feq_gen_o_d_1.ofm = const_cast<char*>("UNFORMATTED");
	feq_gen_o_d_1.oblnk = 0;
	f_open(&feq_gen_o_d_1);
/* SOURCE runinit.for:2393 */
/*<       else >*/
    } else {
/* SOURCE runinit.for:2394 */
/*<       inquire(file=name,exist=there) >*/
	feq_gen_ioin_d_1.inerr = 0;
	feq_gen_ioin_d_1.infilen = 256;
	feq_gen_ioin_d_1.infile = feq_gen_name_d_;
	feq_gen_ioin_d_1.inex = &there;
	feq_gen_ioin_d_1.inopen = 0;
	feq_gen_ioin_d_1.innum = 0;
	feq_gen_ioin_d_1.innamed = 0;
	feq_gen_ioin_d_1.inname = 0;
	feq_gen_ioin_d_1.inacc = 0;
	feq_gen_ioin_d_1.inseq = 0;
	feq_gen_ioin_d_1.indir = 0;
	feq_gen_ioin_d_1.infmt = 0;
	feq_gen_ioin_d_1.inform = 0;
	feq_gen_ioin_d_1.inunf = 0;
	feq_gen_ioin_d_1.inrecl = 0;
	feq_gen_ioin_d_1.innrec = 0;
	feq_gen_ioin_d_1.inblank = 0;
	f_inqu(&feq_gen_ioin_d_1);
/* SOURCE runinit.for:2395 */
/*<       if(there)then >*/
	if (there) {
/* SOURCE runinit.for:2396 */
/*<        >*/
	    feq_gen_o_d_1.oerr = 0;
	    feq_gen_o_d_1.ounit = *getdsn;
	    feq_gen_o_d_1.ofnmlen = 256;
	    feq_gen_o_d_1.ofnm = feq_gen_name_d_;
	    feq_gen_o_d_1.orl = 8;
	    feq_gen_o_d_1.osta = const_cast<char*>("OLD");
	    feq_gen_o_d_1.oacc = const_cast<char*>("direct");
	    feq_gen_o_d_1.ofm = const_cast<char*>("UNFORMATTED");
	    feq_gen_o_d_1.oblnk = 0;
	    f_open(&feq_gen_o_d_1);
/* SOURCE runinit.for:2398 */
/*<       else >*/
	} else {
/* SOURCE runinit.for:2399 */
/*<       it=feq_len_trim(name) >*/
	    it = feq_gen_feq_len_trim_d_(feq_gen_name_d_, (ftnlen)256);
/* SOURCE runinit.for:2400 */
/*<       write(stdout,*)' FILE NAMED:',name(1:it),' NOT FOUND.' >*/
	    feq_gen_io_d__280.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__280);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FILE NAMED:"), (ftnlen)12);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_name_d_, it);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NOT FOUND."), (ftnlen)11);
	    e_wsle();
/* SOURCE runinit.for:2401 */
/*<       write(stdout,*)' CHECK SPELLING OF GETIC FILE.' >*/
	    feq_gen_io_d__281.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__281);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" CHECK SPELLING OF GETIC FILE."), (ftnlen)30)
		    ;
	    e_wsle();
/* SOURCE runinit.for:2402 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:2403 */
/*<       endif >*/
	}
/* SOURCE runinit.for:2404 */
/*<       endif >*/
    }
/*     READ THE FIRST BLOCK OF DATA FOR CHECKING */
/*      READ(GETDSN) FNBRA, FNBN, FNEX, FJTIME, SITER, DT, FBNODE */
/* SOURCE runinit.for:2409 */
/*<       bwrec=1 >*/
    bwrec = 1;
/* SOURCE runinit.for:2410 */
/*<       read(getdsn,rec=bwrec)fnbra,fnbn >*/
    feq_gen_io_d__283.ciunit = *getdsn;
    feq_gen_io_d__283.cirec = bwrec;
    s_rdue(&feq_gen_io_d__283);
    do_uio(&feq_gen_c_d_1, (char *)&fnbra, (ftnlen)sizeof(integer));
    do_uio(&feq_gen_c_d_1, (char *)&fnbn, (ftnlen)sizeof(integer));
    e_rdue();
/* SOURCE runinit.for:2411 */
/*<       bwrec=bwrec+1 >*/
    ++bwrec;
/* SOURCE runinit.for:2412 */
/*<       read(getdsn,rec=bwrec)fnex,siter >*/
    feq_gen_io_d__286.ciunit = *getdsn;
    feq_gen_io_d__286.cirec = bwrec;
    s_rdue(&feq_gen_io_d__286);
    do_uio(&feq_gen_c_d_1, (char *)&fnex, (ftnlen)sizeof(integer));
    do_uio(&feq_gen_c_d_1, (char *)&(*siter), (ftnlen)sizeof(real));
    e_rdue();
/* SOURCE runinit.for:2413 */
/*<       bwrec=bwrec+1 >*/
    ++bwrec;
/* SOURCE runinit.for:2414 */
/*<       read(getdsn,rec=bwrec)fbnode,dummy >*/
    feq_gen_io_d__288.ciunit = *getdsn;
    feq_gen_io_d__288.cirec = bwrec;
    s_rdue(&feq_gen_io_d__288);
    do_uio(&feq_gen_c_d_1, (char *)&fbnode, (ftnlen)sizeof(integer));
    do_uio(&feq_gen_c_d_1, (char *)&dummy, (ftnlen)sizeof(integer));
    e_rdue();
/* SOURCE runinit.for:2415 */
/*<       bwrec=bwrec+1 >*/
    ++bwrec;
/* SOURCE runinit.for:2416 */
/*<       read(getdsn,rec=bwrec)fjtime >*/
    feq_gen_io_d__291.ciunit = *getdsn;
    feq_gen_io_d__291.cirec = bwrec;
    s_rdue(&feq_gen_io_d__291);
    do_uio(&feq_gen_c_d_1, (char *)&fjtime, (ftnlen)sizeof(doublereal));
    e_rdue();
/* SOURCE runinit.for:2417 */
/*<       bwrec=bwrec+1 >*/
    ++bwrec;
/* SOURCE runinit.for:2418 */
/*<       read(getdsn,rec=bwrec)dt >*/
    feq_gen_io_d__293.ciunit = *getdsn;
    feq_gen_io_d__293.cirec = bwrec;
    s_rdue(&feq_gen_io_d__293);
    do_uio(&feq_gen_c_d_1, (char *)&(*dt), (ftnlen)sizeof(doublereal));
    e_rdue();
/* SOURCE runinit.for:2419 */
/*<       bwrec=bwrec+1 >*/
    ++bwrec;
/* SOURCE runinit.for:2421 */
/*<       flag=0 >*/
    feq_gen_flag_d_ = 0;
/* SOURCE runinit.for:2422 */
/*<       if(fnbra.ne.nbra)then >*/
    if (fnbra != *nbra) {
/* SOURCE runinit.for:2423 */
/*<       write(stdout,50)nbra,fnbra,name >*/
	feq_gen_io_d__295.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__295);
	do_fio(&feq_gen_c_d_1, (char *)&(*nbra), (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&fnbra, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)256);
	e_wsfe();
/* SOURCE runinit.for:2424 */
/*<       flag=1 >*/
	feq_gen_flag_d_ = 1;
/* SOURCE runinit.for:2425 */
/*<       endif >*/
    }
/* SOURCE runinit.for:2426 */
/*<       if(fnex.ne.nex)then >*/
    if (fnex != *nex) {
/* SOURCE runinit.for:2427 */
/*<       write(stdout,52)nex,fnex,name >*/
	feq_gen_io_d__296.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__296);
	do_fio(&feq_gen_c_d_1, (char *)&(*nex), (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&fnex, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)256);
	e_wsfe();
/* SOURCE runinit.for:2428 */
/*<       flag=1 >*/
	feq_gen_flag_d_ = 1;
/* SOURCE runinit.for:2429 */
/*<       endif >*/
    }
/* SOURCE runinit.for:2430 */
/*<       if(fnbn.ne.nbn)then >*/
    if (fnbn != *nbn) {
/* SOURCE runinit.for:2431 */
/*<       write(stdout,54)nbn,fnbn,name >*/
	feq_gen_io_d__297.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__297);
	do_fio(&feq_gen_c_d_1, (char *)&(*nbn), (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&fnbn, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)256);
	e_wsfe();
/* SOURCE runinit.for:2432 */
/*<       flag=1 >*/
	feq_gen_flag_d_ = 1;
/* SOURCE runinit.for:2433 */
/*<       endif >*/
    }
/* SOURCE runinit.for:2434 */
/*<       if(fbnode.ne.bnode)then >*/
    if (fbnode != *bnode) {
/* SOURCE runinit.for:2435 */
/*<       write(stdout,62)getusn(bnode),getusn(fbnode),name >*/
	feq_gen_io_d__298.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__298);
	getusn_(feq_gen_ch_d_2, (ftnlen)5, bnode);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	getusn_(feq_gen_ch_d_4, (ftnlen)5, &fbnode);
	s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)256);
	e_wsfe();
/* SOURCE runinit.for:2436 */
/*<       flag=1 >*/
	feq_gen_flag_d_ = 1;
/* SOURCE runinit.for:2437 */
/*<       endif >*/
    }
/* SOURCE runinit.for:2438 */
/*<       if(flag.ne.0)then >*/
    if (feq_gen_flag_d_ != 0) {
/* SOURCE runinit.for:2439 */
/*<       write(stdout,56) >*/
	feq_gen_io_d__299.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__299);
	e_wsfe();
/* SOURCE runinit.for:2440 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:2441 */
/*<       endif >*/
    }
/* SOURCE runinit.for:2443 */
/*<       if(abs(jtime-fjtime).gt.2.e-4)then >*/
    if ((feq_gen_d_d_1 = *jtime - fjtime, abs(feq_gen_d_d_1)) > (float)2e-4) {
/*       TIME MISMATCH BETWEEN THE TIME OF INITIAL CONDITIONS IN THE */
/*       GETIC FILE AND THE TIME OF START OF THE RUN */
/* SOURCE runinit.for:2446 */
/*<       write(stdout,58)86400.*(jtime-fjtime) >*/
	feq_gen_io_d__300.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__300);
	feq_gen_d_d_1 = (*jtime - fjtime) * (float)86400.;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_d_d_1, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* SOURCE runinit.for:2447 */
/*<       endif >*/
    }
/* SOURCE runinit.for:2449 */
/*<       callbwget(getdsn,nbra,nbn,nex,mnblk,nblk,opblk,bwrec,wt) >*/
    bwget_(getdsn, nbra, nbn, nex, &feq_gen_c_d_100, nblk, &opblk[1], &bwrec, wt);
/* SOURCE runinit.for:2454 */
/*<       callfree_unit(stdout,getdsn) >*/
    feq_gen_free_unit_d_(stdout, getdsn);
/* SOURCE runinit.for:2455 */
/*<       write(stdout,60)jtime >*/
    feq_gen_io_d__301.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__301);
    do_fio(&feq_gen_c_d_1, (char *)&(*jtime), (ftnlen)sizeof(doublereal));
    e_wsfe();
/* SOURCE runinit.for:2456 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:2457 */
/*<       end >*/
} /* getic_ */

/*  *********************************************************************** */
/*  *  Warning:  This program is large and complex and  extensive         * */
/*  *  knowledge of its design, purpose, and limitations is required      * */
/*  *  in order to apply it properly.  Application of this program by an  * */
/*  *  unqualified user for any other purpose than an educational one is  * */
/*  *  not only unwise but is also unethical.  The user of this           * */
/*  *  program is totally responsible for its use and application and for * */
/*  *  any actions or events which follow therefrom.  Any user of this    * */
/*  *  program  holds the developer of the program harmless from          * */
/*  *  damages of any kind.                                               * */
/*  *                                                                     * */
/*  *  The developer has used reasonable care in the construction and     * */
/*  *  testing of the program.  However, in a program of this size and    * */
/*  *  complexity, it is impossible to verify more than a minute number of* */
/*  *  possible options or applications.  The developer is continuing to  * */
/*  *  modify and use the program and is interested in information on     * */
/*  *  operational problems encountered in its application.  However, the * */
/*  *  developer gives no assurance that the problem can or will be       * */
/*  *  rectified.                                                         * */
/*  *                                                                     * */
/*  *  This program is not to be sold in any form modified or otherwise.  * */
/*  *********************************************************************** */



/* SOURCE runinit.for:2486 */
/*<       subroutinemkqctb(stdout,tabn,ftp,ftknt,eflag) >*/
/* Subroutine */ int mkqctb_(integer *stdout, integer *tabn, integer *ftp, 
	integer *ftknt, integer *eflag)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:81* TABLE Id=\002,a,\002 does not e\
xist.\002)";
    static char fmt_51[] = "(/,\002 *ERR:173* TABLE Id=\002,a,\002 and TYPE\
=\002,i5,\002 does not \002,\002 have critical flow.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();
    double log(doublereal);

    /* Local variables */
    integer feq_gen_i_d_;
    doublereal m[1000], y[1000];
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    doublereal qc[1000], lgy[1000];
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ndep, adrs, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern integer nextn_();
    extern /* Subroutine */ int strty5_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *);
    integer newtab;
    extern /* Subroutine */ int getyqc_(integer *, integer *, integer *, 
	    doublereal *, doublereal *);
    extern integer gettyp_(integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__306 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__315 = { 0, 0, 0, fmt_51, 0 };


/*     + + + PURPOSE + + + */
/*     Make a critical flow table if a cross section table has been */
/*     provided.  Otherwise process the table number like in CHKTAB. */
/* SOURCE runinit.for:2495 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE runinit.for:2497 */
/*<       integereflag,ftknt,ftp,stdout,tabn >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     TABN   - table number */
/*     FTP    - next open location in the function table storage */
/*     FTKNT  - function table counter */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE runinit.for:2506 */
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
/* INCLUDE runinit.for:2507 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE runinit.for:2510 */
/*<       integeradrs,i,ndep,newtab,oldtab,type >*/
/*      REAL A, ALP, B, DALP, DB, DK, DT, FJ, FK, PDV, QCNEW, QCOLD, */
/*     A     QCTRUE, RERRNW, RERROD, T, YT */
/* SOURCE runinit.for:2513 */
/*<       real*8lgy(mndep),m(mndep),qc(mndep),y(mndep) >*/
/*      REAL*8 DY, P(0:4) */
/*     + + + INTRINSICS + + + */
/* SOURCE runinit.for:2517 */
/*<       intrinsiclog,sqrt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE runinit.for:2520 */
/*<       characterget_tabid*16 >*/
/* SOURCE runinit.for:2521 */
/*<       integergettyp,nextn >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE runinit.for:2524 */
/*<       externalgettyp,getyqc,lktab,nextn,strty5,xlkt22,get_tabid >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE runinit.for:2527 */
/*<    50 format(/,' *ERR:81* TABLE Id=',a,' does not exist.') >*/
/* SOURCE runinit.for:2528 */
/*<    51  >*/
/* SOURCE runinit.for:2530 */
/*<    60 format(' Checking TABLE Id=',a,' taken from TABLE Id=',a) >*/
/* SOURCE runinit.for:2531 */
/*<    61 format(1x,'     DEPTH    LDEPTH         FLOW        DERIV') >*/
/* SOURCE runinit.for:2532 */
/*<    62 format(1x,2f10.5,1pe13.5,1pe13.5) >*/
/* SOURCE runinit.for:2533 */
/*<    63 format(1x,f10.5,1pe13.5,1pe13.5,1pe13.5,1pe13.5,1pe13.5) >*/
/* SOURCE runinit.for:2534 */
/*<    64  >*/
/* *********************************************************************** */
/*     Table number already checked for valid range.  Does the table */
/*     exist? */
/* SOURCE runinit.for:2539 */
/*<       adrs=ftpnt(tabn) >*/
/* L50: */
/* L51: */
/* L60: */
/* L61: */
/* L62: */
/* L63: */
/* L64: */
    adrs = ftablea_1.ftpnt[*tabn - 1];
/* SOURCE runinit.for:2540 */
/*<       if(adrs.le.0)then >*/
    if (adrs <= 0) {
/*       Table missing */
/* SOURCE runinit.for:2542 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE runinit.for:2543 */
/*<       write(stdout,50)get_tabid(tabn) >*/
	feq_gen_io_d__306.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__306);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, tabn);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	e_wsfe();
/* SOURCE runinit.for:2544 */
/*<       else >*/
    } else {
/*       Branch on table type */
/* SOURCE runinit.for:2546 */
/*<       type=gettyp(adrs) >*/
	feq_gen_type_d_ = gettyp_(&adrs);
/* SOURCE runinit.for:2547 */
/*<       if(type.le.4.and.type.ge.2)then >*/
	if (feq_gen_type_d_ <= 4 && feq_gen_type_d_ >= 2) {
/*         Proper table already supplied.  Put table address in */
/*         table number. */
/* SOURCE runinit.for:2551 */
/*<       tabn=adrs >*/
	    *tabn = adrs;
/* SOURCE runinit.for:2552 */
/*<       elseif(type.eq.22.or.type.eq.25)then >*/
	} else if (feq_gen_type_d_ == 22 || feq_gen_type_d_ == 25) {
/*         Cross section table containing critical flow values given. */
/*         Extract the depth and the critical flow.  Also determine if */
/*         cross section represents a closed conduit or an open channel */
/*         with EXT different from zero. */
/* SOURCE runinit.for:2558 */
/*<       callgetyqc(adrs,type,ndep,y,qc) >*/
	    getyqc_(&adrs, &feq_gen_type_d_, &ndep, y, qc);
/*         Compute logarithms of the values */
/* SOURCE runinit.for:2564 */
/*<       do90i=2,ndep >*/
	    feq_gen_i_d_1 = ndep;
	    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:2565 */
/*<       lgy(i)=log(y(i)) >*/
		lgy[feq_gen_i_d_ - 1] = log(y[feq_gen_i_d_ - 1]);
/* SOURCE runinit.for:2566 */
/*<       qc(i)=log(qc(i)) >*/
		qc[feq_gen_i_d_ - 1] = log(qc[feq_gen_i_d_ - 1]);
/* SOURCE runinit.for:2567 */
/*<    90 continue >*/
/* L90: */
	    }
/* SOURCE runinit.for:2568 */
/*<       lgy(1)=log(1.e-8) >*/
	    lgy[0] = log((float)1e-8);
/* SOURCE runinit.for:2569 */
/*<       qc(1)=log(1.e-7) >*/
	    qc[0] = log((float)1e-7);
/*         Compute the slope of the logarithms and store at the lower */
/*         point for each panel.  First panel has no slope. */
/* SOURCE runinit.for:2573 */
/*<       do92i=2,ndep-1 >*/
	    feq_gen_i_d_1 = ndep - 1;
	    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:2574 */
/*<       m(i)=(qc(i+1)-qc(i))/(lgy(i+1)-lgy(i)) >*/
		m[feq_gen_i_d_ - 1] = (qc[feq_gen_i_d_] - qc[feq_gen_i_d_ - 1]) / (lgy[feq_gen_i_d_] - lgy[feq_gen_i_d_ - 
			1]);
/* SOURCE runinit.for:2575 */
/*<    92 continue >*/
/* L92: */
	    }
/* SOURCE runinit.for:2576 */
/*<       m(1)=0.d0 >*/
	    m[0] = 0.;
/* SOURCE runinit.for:2577 */
/*<       m(ndep)=0.d0 >*/
	    m[ndep - 1] = 0.;
/*         Store a new table of type 5 in FTAB.  Get a table number for */
/*         the table. */
/* SOURCE runinit.for:2583 */
/*<       newtab=nextn() >*/
	    newtab = nextn_();
/* SOURCE runinit.for:2585 */
/*<       callstrty5(newtab,ndep,lgy,qc,m,ftp,ftknt,eflag) >*/
	    strty5_(&newtab, &ndep, lgy, qc, m, ftp, ftknt, eflag);
/*         Put the table address into the table number */
/*          OLDTAB = TABN */
/* SOURCE runinit.for:2592 */
/*<       tabn=ftpnt(newtab) >*/
	    *tabn = ftablea_1.ftpnt[newtab - 1];
/* C         Output the table for checking. */
/*          WRITE(STDOUT,*) ' ' */
/*          WRITE(STDOUT,60) GET_TABID(ITAB(TABN+1)), GET_TABID(OLDTAB) */
/*          WRITE(STDOUT,61) */

/*          DO 100 I=1,NDEP */
/*            WRITE(STDOUT,62) Y(I), LGY(I), QC(I), M(I) */
/* 100      CONTINUE */
/* C         Now compare the values obtained by LKTAB and XLKT22.  Do */
/* C         five intermediate values. */
/*          P(0) = 1.D-2 */
/*          P(1) = 0.25D0 */
/*          P(2) = 0.50D0 */
/*          P(3) = 0.75D0 */
/*          P(4) = 0.99D0 */
/*          WRITE(STDOUT,*) ' NDEP=',NDEP */
/*          WRITE(STDOUT,64) */
/*          DO 110 I=1,NDEP-1 */
/*            DY = Y(I+1) - Y(I) */
/*            DO 105 J=0,4 */
/*              YT = Y(I) +  P(J)*DY */
/* C             Get the value from the new table. */
/*              CALL LKTAB */
/*     I                  (TABN, YT, 1, */
/*     O                   QCNEW, NTAB, PDV) */

/* C             Get value from the cross section table */
/*              CALL XLKT22 */
/*     I                   (FTPNT(OLDTAB), */
/*     M                    YT, */
/*     O                    A, T, DT, FJ, FK, DK, B, DB, ALP, DALP, QCOLD) */
/*              QCTRUE = A*SQRT(32.2*A/T) */
/*              IF(QCTRUE.GT.0.0) THEN */
/*                RERRNW = (QCNEW - QCTRUE)/QCTRUE */
/*                RERROD = (QCOLD - QCTRUE)/QCTRUE */
/*              ELSE */
/*                RERRNW = 0.0 */
/*                RERROD = 0.0 */
/*              ENDIF */
/*              WRITE(STDOUT,63) YT, QCNEW, QCOLD, RERRNW, RERROD, PDV */
/* 105        CONTINUE */
/* 110      CONTINUE */
/* SOURCE runinit.for:2638 */
/*<       else >*/
	} else {
/*         Invalid table type for critical flow. */
/* SOURCE runinit.for:2640 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE runinit.for:2641 */
/*<       write(stdout,51)get_tabid(tabn),type >*/
	    feq_gen_io_d__315.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__315);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, tabn);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE runinit.for:2642 */
/*<       endif >*/
	}
/* SOURCE runinit.for:2643 */
/*<       endif >*/
    }
/* SOURCE runinit.for:2645 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:2646 */
/*<       end >*/
} /* mkqctb_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE runinit.for:2650 */
/*<       subroutineopinit(nblk,opblk) >*/
/* Subroutine */ int opinit_(integer *nblk, integer *feq_storage_opblk)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_, nd, feq_gen_block_type_d_, key, ipt;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer node;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

/*     + + + PURPOSE + + + */
/*     Initialize the dynamically varied control structures. Set the */
/*     sensed level values if at least the minimum time has elapsed. */
/* SOURCE runinit.for:2657 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE runinit.for:2659 */
/*<       integernblk >*/
/* SOURCE runinit.for:2660 */
/*<       integeropblk(nblk) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NBLK   - number of operation blocks */
/*     OPBLK  - pointer into the function table storage(FTAB/ITAB) for */
/*               each operation block. */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE runinit.for:2668 */
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
/* INCLUDE runinit.for:2669 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE runinit.for:2670 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE runinit.for:2671 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE runinit.for:2674 */
/*<       integeri,ipt,key,nd,node,block_type >*/
/*     + + + INTRINSICS + + + */
/* SOURCE runinit.for:2677 */
/*<       intrinsicabs >*/
/* *********************************************************************** */
/* SOURCE runinit.for:2679 */
/*<       do500i=1,nblk >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> opblk(feq_storage_opblk, 1);

    /* Function Body */
    feq_gen_i_d_1 = *nblk;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:2680 */
/*<       ipt=opblk(i) >*/
	ipt = opblk[feq_gen_i_d_];
/* SOURCE runinit.for:2681 */
/*<       block_type=itab(ipt+3) >*/
	feq_gen_block_type_d_ = itab[ipt + 3];
/*       WRITE(STD6,1) IPT */
/* 1       FORMAT(' IPT = ',I5) */
/* SOURCE runinit.for:2684 */
/*<       if(ftab(ipt+5).lt.ftab(ipt+4))then >*/
	if (ftab[ipt + 5] < ftab[ipt + 4]) {
/*         Minimum time not yet elapsed.  Levels unchanged. */
/* SOURCE runinit.for:2686 */
/*<       goto500 >*/
	    goto L500;
/* SOURCE runinit.for:2687 */
/*<       endif >*/
	}
/*       Change the levels.  Also must clear elapsed time. */
/* SOURCE runinit.for:2689 */
/*<       ftab(ipt+5)=0.0 >*/
	ftab[ipt + 5] = (float)0.;
/* SOURCE runinit.for:2690 */
/*<       ipt=ipt+12 >*/
	ipt += 12;
/* SOURCE runinit.for:2691 */
/*<    90 continue >*/
L90:
/* SOURCE runinit.for:2692 */
/*<       node=itab(ipt) >*/
	node = itab[ipt];
/* SOURCE runinit.for:2693 */
/*<       if(node.eq.0)goto500 >*/
	if (node == 0) {
	    goto L500;
	}
/* SOURCE runinit.for:2694 */
/*<       key=itab(ipt+1) >*/
	key = itab[ipt + 1];
/* SOURCE runinit.for:2695 */
/*<       if(node.lt.0)goto200 >*/
	if (node < 0) {
	    goto L200;
	}
/*         INTERIOR NODE */
/* SOURCE runinit.for:2699 */
/*<       if(key.eq.1)goto100 >*/
	if (key == 1) {
	    goto L100;
	}
/*             ELEVATION */
/* SOURCE runinit.for:2701 */
/*<       ftab(ipt+4)=y1(node)+zvec(node) >*/
	ftab[ipt + 4] = static_cast<double>(bnelem_1.y1[node - 1]) + bnelem_1.zvec[node - 1];
/* SOURCE runinit.for:2702 */
/*<       goto110 >*/
	goto L110;
/* SOURCE runinit.for:2703 */
/*<   100 continue >*/
L100:
/*             FLOW RATE */
/* SOURCE runinit.for:2705 */
/*<       ftab(ipt+4)=q1(node) >*/
	ftab[ipt + 4] = bnelem_1.q1[node - 1];
/* SOURCE runinit.for:2706 */
/*<       goto110 >*/
	goto L110;
/* SOURCE runinit.for:2707 */
/*<   110 goto210 >*/
L110:
	goto L210;
/* SOURCE runinit.for:2708 */
/*<   200 continue >*/
L200:
/*         EXTERIOR NODE */
/* SOURCE runinit.for:2712 */
/*<       node=abs(node) >*/
	node = abs(node);
/* SOURCE runinit.for:2713 */
/*<       if(key.ge.1)goto150 >*/
	if (key >= 1) {
	    goto L150;
	}
/*           ELEVATION or elevation difference */
/* SOURCE runinit.for:2715 */
/*<       if(key.eq.0)then >*/
	if (key == 0) {
/*             Elevation. */
/* SOURCE runinit.for:2717 */
/*<       ftab(ipt+4)=ye1(node)+ze(node) >*/
	    ftab[ipt + 4] = static_cast<double>(enelem_1.ye1[node - 1]) + enelem_1.ze[node - 1];
/* SOURCE runinit.for:2718 */
/*<       else >*/
	} else {
/* SOURCE runinit.for:2719 */
/*<       nd=abs(key) >*/
	    nd = abs(key);
/*             Elevation difference. */
/* SOURCE runinit.for:2721 */
/*<       ftab(ipt+4)=ye1(node)+ze(node)-(ye1(nd)+ze(nd)) >*/
	    ftab[ipt + 4] = static_cast<double>(static_cast<double>(enelem_1.ye1[node - 1]) + enelem_1.ze[node - 1]) - (
		    static_cast<double>(enelem_1.ye1[nd - 1]) + enelem_1.ze[nd - 1]);
/* SOURCE runinit.for:2723 */
/*<       endif >*/
	}
/* SOURCE runinit.for:2725 */
/*<       goto160 >*/
	goto L160;
/* SOURCE runinit.for:2726 */
/*<   150 continue >*/
L150:
/*           FLOW */
/* SOURCE runinit.for:2728 */
/*<       ftab(ipt+4)=qe1(node) >*/
	ftab[ipt + 4] = enelem_1.qe1[node - 1];
/*           IF VARIABLE NULL ZONE, CHANGE INCREMENT.  NULL ZONE LIMITS */
/*           ARE RECOMPUTED DYNAMICALLY IN OPER IN THIS CASE */
/* SOURCE runinit.for:2731 */
/*<       if(key.eq.2)then >*/
	if (key == 2) {
/* SOURCE runinit.for:2732 */
/*<       itmp=itab(ipt+14) >*/
	    ftablea_1.itmp = itab[ipt + 14];
/*             Set the new offset value so that when 17 is added to it */
/*             that the increment will be 15 + 2*ITMP. */
/* SOURCE runinit.for:2735 */
/*<       ipt=ipt-2+2*itmp >*/
	    ipt = ipt - 2 + (ftablea_1.itmp << 1);
/* SOURCE runinit.for:2736 */
/*<       endif >*/
	}
/* SOURCE runinit.for:2737 */
/*<       goto160 >*/
	goto L160;
/* SOURCE runinit.for:2738 */
/*<   160 continue >*/
L160:
/* SOURCE runinit.for:2739 */
/*<   210 continue >*/
L210:
/* SOURCE runinit.for:2740 */
/*<       ipt=ipt+17 >*/
	ipt += 17;
/* SOURCE runinit.for:2741 */
/*<       goto90 >*/
	goto L90;
/* SOURCE runinit.for:2742 */
/*<   500 continue >*/
L500:
	;
    }
/* SOURCE runinit.for:2743 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:2744 */
/*<       end >*/
} /* opinit_ */

#undef rtmp
#undef itab
#undef ftab


/*     *********** */
/*     *         * */
/*     * CHK_TS_FILE_REFERENCES */
/*     *         * */
/*     *********** */
/* SOURCE runinit.for:2751 */
/*<       subroutinechk_ts_file_references(stdout,eflag) >*/
/* Subroutine */ int feq_gen_chk_ts_file_references_d_(integer *stdout, integer *eflag)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:299* Time-series id \002,a,\002 ref\
ers to a file\002,/,5x,\002but the file name is not found in the INPUT FILE\
S\002,\002 BLOCK.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer feq_gen_i_d_, ip, tab;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int lstab_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), chktab_(integer *, integer *, integer *, integer 
	    *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__330 = { 0, 0, 0, fmt_50, 0 };


/*     Establish the source addresses for the time-series */
/*     references in the time-series management system. */
/* SOURCE runinit.for:2757 */
/*<       implicitnone >*/
/* SOURCE runinit.for:2758 */
/*<       integerstdout,eflag >*/
/* INCLUDE runinit.for:2760 */
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
/* INCLUDE runinit.for:2761 */
/*     Parameter defintion for time-series management in FEQ */
/* SOURCE ts_mngt.prm:3 */
/*<        >*/
/* SOURCE ts_mngt.prm:5 */
/*<        >*/
/* INCLUDE runinit.for:2762 */
/* *********************************************************************** */
/* SOURCE rdcom.cmn:2 */
/*<        >*/
/* SOURCE rdcom.cmn:7 */
/*<       common/rdcomc/namin,ts_id_for_file_table >*/
/* SOURCE rdcom.cmn:9 */
/*<       characternamin(mxn_ts_f)*256,ts_id_for_file_table(mxn_ts)*16 >*/
/* SOURCE rdcom.cmn:11 */
/*<       integernum_ts_f,id_knt >*/
/* SOURCE rdcom.cmn:13 */
/*<        >*/
/* SOURCE rdcom.cmn:18 */
/*<       realvalain(mrrbuf),tmpvec(mrrbuf+5),ts_conversion_factor(mxn_ts) >*/
/* SOURCE rdcom.cmn:21 */
/*<        >*/
/* *********************************************************************** */
/* INCLUDE runinit.for:2763 */
/*     Common block for management of time series in FEQ.  Keeps track */
/*     of time series references as well as the places where the */
/*     time-series values are needed. */
/* SOURCE ts_mngt.cmn:5 */
/*<       integernum_ts,num_dest,next_link >*/
/* SOURCE ts_mngt.cmn:7 */
/*<        >*/
/* SOURCE ts_mngt.cmn:11 */
/*<       character*16ts_id(mxn_ts) >*/
/* SOURCE ts_mngt.cmn:13 */
/*<        >*/
/* SOURCE ts_mngt.cmn:16 */
/*<       common/ts_mngt_c/ts_id >*/
/* SOURCE ts_mngt.cmn:18 */
/*<       save/ts_mngt_n/,/ts_mngt_c/ >*/
/*     Definitions: */
/*     TS_ID-  unique label used for refering to a time series that will */
/*             be referenced in FEQ. */
/*     SOURCE_CAT- category of the source of the time series: from table */
/*                 or from a file. */
/*     SOURCE_ADDRESS- "address" of the source.  This will contain the */
/*                  index into the time-series file table for time-series */
/*                  found in files.  For time series found in tables it */
/*                  will be the table number and later the address */
/*                  of the table. */
/*     DEST_CAT- category of the destination: level-pool reservoir rainfall/ */
/*              evaporation or branch evaporation/rainfall, forced bdy. */
/*     DEST_LINK- pointer that allows there to be more than one destination */
/*                from a time-series.  If DEST_LINK(i) is 0, then the */
/*                destination in row i is the last one in the list. */
/*                If DEST_LINK(i) > 0, then the next destination is */
/*                described in row DEST_LINK(i).  We reserve one value for each of */
/*                the MXN_TS time series. Therefore MXN_DEST > MXN_TS if */
/*                a time series is to have more than one destination */
/*     NEXT_LINK- Next open link in the destination overflow area. */
/*     The file handling routines will keep track of the different file */
/*     systems that may be used for the time series. */
/* INCLUDE runinit.for:2764 */
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
/*     Local */
/* SOURCE runinit.for:2767 */
/*<       integeri,ip,tab >*/
/*     *******************************Formats**************************** */
/* SOURCE runinit.for:2769 */
/*<    50  >*/
/* *********************************************************************** */
/*     Scan all time series references with a file given as its source */
/*     and make sure that the time-series id appears in the list */
/*     of ids found in the time-series file input block. */
/* SOURCE runinit.for:2777 */
/*<       do100i=1,num_ts >*/
/* L50: */
    feq_gen_i_d_1 = feq_gen_ts_mngt_n_d_1.feq_gen_num_ts_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:2778 */
/*<       if(source_cat(i).eq.ts_from_file)then >*/
	if (feq_gen_ts_mngt_n_d_1.feq_gen_source_cat_d_[feq_gen_i_d_ - 1] == 1003) {
/* SOURCE runinit.for:2780 */
/*<       calllstab(ts_id(i),ts_id_for_file_table,id_knt,ip) >*/
	    lstab_(feq_gen_ts_mngt_c_d_1.feq_gen_ts_id_d_ + (feq_gen_i_d_ - 1 << 4), 
		    rdcomc_1.feq_gen_ts_id_for_file_table_d_, &rdcom_1.feq_gen_id_knt_d_, &ip, (
		    ftnlen)16, (ftnlen)16);
/* SOURCE runinit.for:2783 */
/*<       if(ip.eq.0)then >*/
	    if (ip == 0) {
/*           Time-series id for a time-series stored in */
/*           a file not found in the list of time-series */
/*           files from the input-files block. */
/* SOURCE runinit.for:2787 */
/*<       write(stdout,50)ts_id(i) >*/
		feq_gen_io_d__330.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__330);
		do_fio(&feq_gen_c_d_1, feq_gen_ts_mngt_c_d_1.feq_gen_ts_id_d_ + (feq_gen_i_d_ - 1 << 4), (ftnlen)
			16);
		e_wsfe();
/* SOURCE runinit.for:2788 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE runinit.for:2789 */
/*<       else >*/
	    } else {
/*           Source address is the row number in the time-series */
/*           file table. This gives access to the unit number if */
/*           it is not a HECDSS file and to the items needed */
/*           for HECDSS file access as well as the control values */
/*           for the read buffers. */
/* SOURCE runinit.for:2795 */
/*<       source_address(i)=ip >*/
		feq_gen_ts_mngt_n_d_1.feq_gen_source_address_d_[feq_gen_i_d_ - 1] = ip;
/* SOURCE runinit.for:2796 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:2797 */
/*<       else >*/
	} else {
/*         Check for existence of the time-series table and */
/*         its correct type. */
/* SOURCE runinit.for:2800 */
/*<       tab=source_address(i) >*/
	    tab = feq_gen_ts_mngt_n_d_1.feq_gen_source_address_d_[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:2801 */
/*<       callchktab(2,stdout,ftpnt,mftnum,tab,eflag) >*/
	    chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &tab, eflag);
/* SOURCE runinit.for:2805 */
/*<       if(eflag.eq.0)then >*/
	    if (*eflag == 0) {
/* SOURCE runinit.for:2806 */
/*<       source_address(i)=tab >*/
		feq_gen_ts_mngt_n_d_1.feq_gen_source_address_d_[feq_gen_i_d_ - 1] = tab;
/* SOURCE runinit.for:2807 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:2808 */
/*<       endif >*/
	}
/* SOURCE runinit.for:2809 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE runinit.for:2810 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:2811 */
/*<       end >*/
} /* chk_ts_file_references__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE runinit.for:2815 */
/*<       subroutinerdinit(stdout) >*/
/* Subroutine */ int rdinit_(integer *stdout)
{
    /* Format strings */
    static char fmt_51[] = "(\0020*ERR:152* Input file\002,i4,\002 has a sta\
rt time=\002,1pd20.13,\002 > run start time=\002,1pd20.13)";
    static char fmt_56[] = "(\002 Opening time-series Id=\002,a,\002 and fil\
ling buffer number=\002,i4,/,\002 from file or path with name=\002,5x,a)";
    static char fmt_57[] = "(\002 Path name=\002,/,1x,a)";
    static char fmt_58[] = "(/,\002 *ERR:259* Input file with unit=\002,i4\
,\002 and path name=\002,/,1x,a,/,1x,\002has no data at start time of run\
.\002)";
    static char fmt_59[] = "(/,\002 File named:\002,a,/,11x,\002 not found. \
 Check spelling\002,\002 of an input time-series file.\002)";
    static char fmt_60[] = "(36x,\002Written by: \002,a,\002 version: \002\
,a,\002 dated: \002,a,\002 on \002,a,\002 at \002,a)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    olist feq_gen_o_d_1;
    cllist feq_gen_cl_d_1;
    inlist feq_gen_ioin_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    f_inqu(inlist *), f_open(olist *), s_rdue(cilist *), do_uio(
	    integer *, char *, ftnlen), e_rdue(), f_clos(cllist *), i_indx(
	    char *, char *, ftnlen, ftnlen);

    /* Local variables */
    char feq_gen_program_version_d_[12];
    extern /* Subroutine */ int feq_gen_get_hecdss_block_d_(integer *, char *, integer 
	    *, integer *, char *, doublereal *, integer *, integer *, 
	    doublereal *, real *, integer *, ftnlen, ftnlen);
    integer feq_gen_i_d_, j, n1, n2, n3, n4, n5;
    extern /* Subroutine */ int feq_gen_chk_hecdss_record_d_(integer *, char *, 
	    integer *, integer *, char *, doublereal *, doublereal *, integer 
	    *, ftnlen, ftnlen);
    integer it;
    doublereal jt;
    integer un, feq_gen_rd_rec_len_d_;
    doublereal feq_gen_start_time_d_;
    integer feq_gen_feql_index1_d_, got;
    char feq_gen_date_of_run_d_[12], feq_gen_time_of_run_d_[12];
    integer feq_gen_tmpvec_size_d_, each, need;
    char what[1];
    integer minr;
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);
    char feq_gen_program_name_d_[12], feq_gen_version_date_d_[12];
    shortint feq_gen_file_version_d_;
    integer feq_gen_first_ts_pnt_d_, eflag;
    logical there;
    char unused[1];
    extern /* Subroutine */ int feq_gen_chk_ts_file_references_d_(integer *, integer *)
	    ;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__338 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__341 = { 0, 0, 0, 0, 1 };
    static cilist feq_gen_io_d__343 = { 0, 0, 0, fmt_59, 0 };
    static cilist feq_gen_io_d__345 = { 0, 0, 0, 0, 1 };
    static cilist feq_gen_io_d__350 = { 0, 0, 0, 0, 9 };
    static cilist feq_gen_io_d__353 = { 0, 0, 0, 0, 10 };
    static cilist feq_gen_io_d__356 = { 0, 0, 0, 0, 11 };
    static cilist feq_gen_io_d__359 = { 0, 0, 0, 0, 12 };
    static cilist feq_gen_io_d__362 = { 0, 0, 0, 0, 13 };
    static cilist feq_gen_io_d__365 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__367 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__370 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__371 = { 0, 0, 0, fmt_57, 0 };
    static cilist feq_gen_io_d__372 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__375 = { 0, 0, 0, fmt_51, 0 };


/*     + + + PURPOSE + + + */
/*     Initialize the fields, pointers, and buffers to be used */
/*     for time series input.  Must be called after all input */
/*     is processed and checked. */
/* SOURCE runinit.for:2824 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE runinit.for:2826 */
/*<       integerstdout >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     + + + PARAMETERS + + + */
/* INCLUDE runinit.for:2833 */
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
/* INCLUDE runinit.for:2834 */
/*     Parameter defintion for time-series management in FEQ */
/* SOURCE ts_mngt.prm:3 */
/*<        >*/
/* SOURCE ts_mngt.prm:5 */
/*<        >*/
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE runinit.for:2837 */
/* *********************************************************************** */
/* SOURCE rdcom.cmn:2 */
/*<        >*/
/* SOURCE rdcom.cmn:7 */
/*<       common/rdcomc/namin,ts_id_for_file_table >*/
/* SOURCE rdcom.cmn:9 */
/*<       characternamin(mxn_ts_f)*256,ts_id_for_file_table(mxn_ts)*16 >*/
/* SOURCE rdcom.cmn:11 */
/*<       integernum_ts_f,id_knt >*/
/* SOURCE rdcom.cmn:13 */
/*<        >*/
/* SOURCE rdcom.cmn:18 */
/*<       realvalain(mrrbuf),tmpvec(mrrbuf+5),ts_conversion_factor(mxn_ts) >*/
/* SOURCE rdcom.cmn:21 */
/*<        >*/
/* *********************************************************************** */
/* INCLUDE runinit.for:2838 */
/*     Common block for management of time series in FEQ.  Keeps track */
/*     of time series references as well as the places where the */
/*     time-series values are needed. */
/* SOURCE ts_mngt.cmn:5 */
/*<       integernum_ts,num_dest,next_link >*/
/* SOURCE ts_mngt.cmn:7 */
/*<        >*/
/* SOURCE ts_mngt.cmn:11 */
/*<       character*16ts_id(mxn_ts) >*/
/* SOURCE ts_mngt.cmn:13 */
/*<        >*/
/* SOURCE ts_mngt.cmn:16 */
/*<       common/ts_mngt_c/ts_id >*/
/* SOURCE ts_mngt.cmn:18 */
/*<       save/ts_mngt_n/,/ts_mngt_c/ >*/
/*     Definitions: */
/*     TS_ID-  unique label used for refering to a time series that will */
/*             be referenced in FEQ. */
/*     SOURCE_CAT- category of the source of the time series: from table */
/*                 or from a file. */
/*     SOURCE_ADDRESS- "address" of the source.  This will contain the */
/*                  index into the time-series file table for time-series */
/*                  found in files.  For time series found in tables it */
/*                  will be the table number and later the address */
/*                  of the table. */
/*     DEST_CAT- category of the destination: level-pool reservoir rainfall/ */
/*              evaporation or branch evaporation/rainfall, forced bdy. */
/*     DEST_LINK- pointer that allows there to be more than one destination */
/*                from a time-series.  If DEST_LINK(i) is 0, then the */
/*                destination in row i is the last one in the list. */
/*                If DEST_LINK(i) > 0, then the next destination is */
/*                described in row DEST_LINK(i).  We reserve one value for each of */
/*                the MXN_TS time series. Therefore MXN_DEST > MXN_TS if */
/*                a time series is to have more than one destination */
/*     NEXT_LINK- Next open link in the destination overflow area. */
/*     The file handling routines will keep track of the different file */
/*     systems that may be used for the time series. */
/* INCLUDE runinit.for:2839 */
/* ********************************************************************** */
/* SOURCE julian.cmn:3 */
/*<        >*/
/* SOURCE julian.cmn:8 */
/*<       integeryr,mn,dy,syr,smn,sdy,eyr,emn,edy,reset,leap,dmyear,dmmn >*/
/* SOURCE julian.cmn:10 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE runinit.for:2840 */
/* SOURCE endrun.cmn:2 */
/*<       integerjde_run,moff_end_run >*/
/* SOURCE endrun.cmn:4 */
/*<       common/endrun/jde_run,moff_end_run >*/
/* SOURCE endrun.cmn:7 */
/*<       save/endrun/ >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE runinit.for:2843 */
/*<       integer*2file_version >*/
/* SOURCE runinit.for:2844 */
/*<        >*/
/* SOURCE runinit.for:2846 */
/*<       real*8jt,start_time >*/
/* SOURCE runinit.for:2847 */
/*<        >*/
/* SOURCE runinit.for:2850 */
/*<       logicalthere >*/
/*     + + + OUTPUT FORMATS + + + */
/* 50   FORMAT('0*ERR:151* File number in input list not in forced', */
/*     A       ' boundary list. UNIT=',I4) */
/* SOURCE runinit.for:2815 */
/*<       integer feql_index1 >*/
/* SOURCE runinit.for:2815 */
/*<       integer feq_len_trim >*/
/* SOURCE runinit.for:2815 */
/*<       external feq_len_trim >*/
/* SOURCE runinit.for:2855 */
/*<    51  >*/
/* 52   FORMAT('0*ERR:153* File number in forced boundary not in', */
/*     A       ' input list. UNIT=',I4) */
/* 54   FORMAT('0*ERR:193* Number of input files=',I3,' not same as', */
/*     A  ' number of file requests=',I4) */
/* SOURCE runinit.for:2861 */
/*<    56  >*/
/* SOURCE runinit.for:2865 */
/*<    57 format(' Path name=',/,1x,a) >*/
/* SOURCE runinit.for:2866 */
/*<    58  >*/
/* SOURCE runinit.for:2868 */
/*<    59  >*/
/* SOURCE runinit.for:2870 */
/*<    60  >*/
/* *********************************************************************** */
/*     Compute the end time of the run in terms of HECDSS */
/* SOURCE runinit.for:2874 */
/*<       jde_run=int(ejtime) >*/
/* L51: */
/* L56: */
/* L57: */
/* L58: */
/* L59: */
/* L60: */
    endrun_1.feq_gen_jde_run_d_ = (integer) julian_1.ejtime;
/* SOURCE runinit.for:2875 */
/*<       moff_end_run=int((ejtime-dble(jde_run))*1440.d0+0.5) >*/
    endrun_1.feq_gen_moff_end_run_d_ = (integer) ((julian_1.ejtime - (doublereal) 
	    endrun_1.feq_gen_jde_run_d_) * 1440. + (float).5);
/* SOURCE runinit.for:2876 */
/*<       jde_run=jde_run-15019 >*/
    endrun_1.feq_gen_jde_run_d_ += -15019;
/* SOURCE runinit.for:2877 */
/*<       if(moff_end_run.eq.0)then >*/
    if (endrun_1.feq_gen_moff_end_run_d_ == 0) {
/*       HECDSS treats the boundary between days as belonging only */
/*       to the previous day when retrieving data. */
/* SOURCE runinit.for:2880 */
/*<       moff_end_run=1440 >*/
	endrun_1.feq_gen_moff_end_run_d_ = 1440;
/* SOURCE runinit.for:2881 */
/*<       jde_run=jde_run-1 >*/
	--endrun_1.feq_gen_jde_run_d_;
/* SOURCE runinit.for:2882 */
/*<       endif >*/
    }
/* SOURCE runinit.for:2885 */
/*<       tmpvec_size=mrrbuf+5 >*/
    feq_gen_tmpvec_size_d_ = 6005;
/* SOURCE runinit.for:2887 */
/*<       eflag=0 >*/
    eflag = 0;
/*     Check that all time-series references exist and */
/*     establish addresses for their sources. */
/* SOURCE runinit.for:2891 */
/*<       callchk_ts_file_references(stdout,eflag) >*/
    feq_gen_chk_ts_file_references_d_(stdout, &eflag);
/* SOURCE runinit.for:2893 */
/*<       if(eflag.ne.0)then >*/
    if (eflag != 0) {
/* SOURCE runinit.for:2894 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:2895 */
/*<       endif >*/
    }
/* SOURCE runinit.for:2897 */
/*<       if(num_ts_f.gt.0)then >*/
    if (rdcom_1.feq_gen_num_ts_f_d_ > 0) {
/*       Clear the delete on close list */
/* SOURCE runinit.for:2899 */
/*<       dofeql_index1=1,mxn_ts_f >*/
	for (feq_gen_feql_index1_d_ = 1; feq_gen_feql_index1_d_ <= 160; ++feq_gen_feql_index1_d_) {
/* SOURCE runinit.for:2899 */
/*<       delete_list(feql_index1)=0 >*/
	    rdcom_1.feq_gen_delete_list_d_[feq_gen_feql_index1_d_ - 1] = 0;
/* SOURCE runinit.for:2899 */
/*<       enddo >*/
	}
/*       ALLOCATE THE AVAILABLE BUFFER SPACE AMOMG THE INPUT FILES */
/* SOURCE runinit.for:2902 */
/*<       each=mrrbuf/num_ts_f >*/
	each = 6000 / rdcom_1.feq_gen_num_ts_f_d_;
/* SOURCE runinit.for:2904 */
/*<       minr=1 >*/
	minr = 1;
/* SOURCE runinit.for:2905 */
/*<       do500i=1,num_ts_f >*/
	feq_gen_i_d_1 = rdcom_1.feq_gen_num_ts_f_d_;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:2907 */
/*<       write(stdout,56)ts_id_for_file_table(i),i,namin(i) >*/
	    feq_gen_io_d__338.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__338);
	    do_fio(&feq_gen_c_d_1, rdcomc_1.feq_gen_ts_id_for_file_table_d_ + (feq_gen_i_d_ - 1 << 4), (
		    ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, rdcomc_1.namin + (feq_gen_i_d_ - 1 << 8), (ftnlen)256);
	    e_wsfe();
/* SOURCE runinit.for:2908 */
/*<       if(eflag.eq.1)stop'Abnormal stop: errors found.' >*/
	    if (eflag == 1) {
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
	    }
/* SOURCE runinit.for:2909 */
/*<       if(dss_index_in(i).eq.0)then >*/
	    if (rdcom_1.feq_gen_dss_index_in_d_[feq_gen_i_d_ - 1] == 0) {
/*           This is a traditional time-series file. */
/* SOURCE runinit.for:2911 */
/*<       inquire(file=namin(i),exist=there) >*/
		feq_gen_ioin_d_1.inerr = 0;
		feq_gen_ioin_d_1.infilen = 256;
		feq_gen_ioin_d_1.infile = rdcomc_1.namin + (feq_gen_i_d_ - 1 << 8);
		feq_gen_ioin_d_1.inex = &there;
		feq_gen_ioin_d_1.inopen = 0;
		feq_gen_ioin_d_1.innum = 0;
		feq_gen_ioin_d_1.innamed = 0;
		feq_gen_ioin_d_1.inname = 0;
		feq_gen_ioin_d_1.inacc = 0;
		feq_gen_ioin_d_1.inseq = 0;
		feq_gen_ioin_d_1.indir = 0;
		feq_gen_ioin_d_1.infmt = 0;
		feq_gen_ioin_d_1.inform = 0;
		feq_gen_ioin_d_1.inunf = 0;
		feq_gen_ioin_d_1.inrecl = 0;
		feq_gen_ioin_d_1.innrec = 0;
		feq_gen_ioin_d_1.inblank = 0;
		f_inqu(&feq_gen_ioin_d_1);
/* SOURCE runinit.for:2912 */
/*<       un=unin(i) >*/
		un = rdcom_1.unin[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:2914 */
/*<       if(there)then >*/
		if (there) {
/* SOURCE runinit.for:2915 */
/*<        >*/
		    feq_gen_o_d_1.oerr = 0;
		    feq_gen_o_d_1.ounit = un;
		    feq_gen_o_d_1.ofnmlen = 256;
		    feq_gen_o_d_1.ofnm = rdcomc_1.namin + (feq_gen_i_d_ - 1 << 8);
		    feq_gen_o_d_1.orl = 4;
		    feq_gen_o_d_1.osta = const_cast<char*>("OLD");
		    feq_gen_o_d_1.oacc = const_cast<char*>("direct");
		    feq_gen_o_d_1.ofm = const_cast<char*>("UNFORMATTED");
		    feq_gen_o_d_1.oblnk = 0;
		    f_open(&feq_gen_o_d_1);
/*             Get the record length of the file.  First 4 bytes */
/*             of record number 1. */
/* SOURCE runinit.for:2919 */
/*<       read(un,rec=1)rd_rec_len >*/
		    feq_gen_io_d__341.ciunit = un;
		    s_rdue(&feq_gen_io_d__341);
		    do_uio(&feq_gen_c_d_1, (char *)&feq_gen_rd_rec_len_d_, (ftnlen)sizeof(
			    integer));
		    e_rdue();
/* SOURCE runinit.for:2920 */
/*<       close(un) >*/
		    feq_gen_cl_d_1.cerr = 0;
		    feq_gen_cl_d_1.cunit = un;
		    feq_gen_cl_d_1.csta = 0;
		    f_clos(&feq_gen_cl_d_1);
/* SOURCE runinit.for:2921 */
/*<        >*/
		    feq_gen_o_d_1.oerr = 0;
		    feq_gen_o_d_1.ounit = un;
		    feq_gen_o_d_1.ofnmlen = 256;
		    feq_gen_o_d_1.ofnm = rdcomc_1.namin + (feq_gen_i_d_ - 1 << 8);
		    feq_gen_o_d_1.orl = feq_gen_rd_rec_len_d_;
		    feq_gen_o_d_1.osta = const_cast<char*>("OLD");
		    feq_gen_o_d_1.oacc = const_cast<char*>("direct");
		    feq_gen_o_d_1.ofm = const_cast<char*>("UNFORMATTED");
		    feq_gen_o_d_1.oblnk = 0;
		    f_open(&feq_gen_o_d_1);
/* SOURCE runinit.for:2923 */
/*<       else >*/
		} else {
/* SOURCE runinit.for:2924 */
/*<       write(stdout,59)namin(i) >*/
		    feq_gen_io_d__343.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__343);
		    do_fio(&feq_gen_c_d_1, rdcomc_1.namin + (feq_gen_i_d_ - 1 << 8), (ftnlen)
			    256);
		    e_wsfe();
/* SOURCE runinit.for:2925 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:2926 */
/*<       endif >*/
		}
/*           Check if user has requested delete on close */
/* SOURCE runinit.for:2929 */
/*<       it=index(namin(i),'._doc_') >*/
		it = i_indx(rdcomc_1.namin + (feq_gen_i_d_ - 1 << 8), const_cast<char*>("._doc_"), (
			ftnlen)256, (ftnlen)6);
/* SOURCE runinit.for:2930 */
/*<       if(it>0)then >*/
		if (it > 0) {
/*             signal delete on close for this file */
/* SOURCE runinit.for:2932 */
/*<       delete_list(i)=1 >*/
		    rdcom_1.feq_gen_delete_list_d_[feq_gen_i_d_ - 1] = 1;
/* SOURCE runinit.for:2933 */
/*<       endif >*/
		}
/*           Get the first record number with time-series data */
/*           and get the code for the values stored. */
/* SOURCE runinit.for:2937 */
/*<       read(un,rec=1)rd_rec_len,file_version,what,unused,first_ts_pnt >*/
		feq_gen_io_d__345.ciunit = un;
		s_rdue(&feq_gen_io_d__345);
		do_uio(&feq_gen_c_d_1, (char *)&feq_gen_rd_rec_len_d_, (ftnlen)sizeof(integer));
		do_uio(&feq_gen_c_d_1, (char *)&feq_gen_file_version_d_, (ftnlen)sizeof(
			shortint));
		do_uio(&feq_gen_c_d_1, what, (ftnlen)1);
		do_uio(&feq_gen_c_d_1, unused, (ftnlen)1);
		do_uio(&feq_gen_c_d_1, (char *)&feq_gen_first_ts_pnt_d_, (ftnlen)sizeof(integer)
			);
		e_rdue();
/*           Output information on the creating program, etc. */
/*           We read the information, strip trailing blanks and */
/*           output.  Detials of what these fields contain is */
/*           in subroutine wropen() for feq. */
/* SOURCE runinit.for:2945 */
/*<       read(un,rec=9)program_name >*/
		feq_gen_io_d__350.ciunit = un;
		s_rdue(&feq_gen_io_d__350);
		do_uio(&feq_gen_c_d_1, feq_gen_program_name_d_, (ftnlen)12);
		e_rdue();
/* SOURCE runinit.for:2946 */
/*<       n1=feq_len_trim(program_name) >*/
		n1 = feq_gen_feq_len_trim_d_(feq_gen_program_name_d_, (ftnlen)12);
/* SOURCE runinit.for:2947 */
/*<       read(un,rec=10)program_version >*/
		feq_gen_io_d__353.ciunit = un;
		s_rdue(&feq_gen_io_d__353);
		do_uio(&feq_gen_c_d_1, feq_gen_program_version_d_, (ftnlen)12);
		e_rdue();
/* SOURCE runinit.for:2948 */
/*<       n2=feq_len_trim(program_version) >*/
		n2 = feq_gen_feq_len_trim_d_(feq_gen_program_version_d_, (ftnlen)12);
/* SOURCE runinit.for:2949 */
/*<       read(un,rec=11)version_date >*/
		feq_gen_io_d__356.ciunit = un;
		s_rdue(&feq_gen_io_d__356);
		do_uio(&feq_gen_c_d_1, feq_gen_version_date_d_, (ftnlen)12);
		e_rdue();
/* SOURCE runinit.for:2950 */
/*<       n3=feq_len_trim(version_date) >*/
		n3 = feq_gen_feq_len_trim_d_(feq_gen_version_date_d_, (ftnlen)12);
/* SOURCE runinit.for:2951 */
/*<       read(un,rec=12)date_of_run >*/
		feq_gen_io_d__359.ciunit = un;
		s_rdue(&feq_gen_io_d__359);
		do_uio(&feq_gen_c_d_1, feq_gen_date_of_run_d_, (ftnlen)12);
		e_rdue();
/* SOURCE runinit.for:2952 */
/*<       n4=feq_len_trim(date_of_run) >*/
		n4 = feq_gen_feq_len_trim_d_(feq_gen_date_of_run_d_, (ftnlen)12);
/* SOURCE runinit.for:2953 */
/*<       read(un,rec=13)time_of_run >*/
		feq_gen_io_d__362.ciunit = un;
		s_rdue(&feq_gen_io_d__362);
		do_uio(&feq_gen_c_d_1, feq_gen_time_of_run_d_, (ftnlen)12);
		e_rdue();
/* SOURCE runinit.for:2954 */
/*<       n5=feq_len_trim(time_of_run) >*/
		n5 = feq_gen_feq_len_trim_d_(feq_gen_time_of_run_d_, (ftnlen)12);
/* SOURCE runinit.for:2955 */
/*<        >*/
		feq_gen_io_d__365.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__365);
		do_fio(&feq_gen_c_d_1, feq_gen_program_name_d_, n1);
		do_fio(&feq_gen_c_d_1, feq_gen_program_version_d_, n2);
		do_fio(&feq_gen_c_d_1, feq_gen_version_date_d_, n3);
		do_fio(&feq_gen_c_d_1, feq_gen_date_of_run_d_, n4);
		do_fio(&feq_gen_c_d_1, feq_gen_time_of_run_d_, n5);
		e_wsfe();
/*           Set rd_rec to the first record */
/* SOURCE runinit.for:2963 */
/*<       rd_rec(i)=first_ts_pnt >*/
		rdcom_1.feq_gen_rd_rec_d_[feq_gen_i_d_ - 1] = feq_gen_first_ts_pnt_d_;
/* SOURCE runinit.for:2965 */
/*<       endif >*/
	    }
/*         INITIALIZE THE CIRCULAR BUFFER CONTROL VALUES */
/* SOURCE runinit.for:2968 */
/*<       lsthd(i)=minr >*/
	    rdcom_1.lsthd[feq_gen_i_d_ - 1] = minr;
/* SOURCE runinit.for:2969 */
/*<       ltry(i)=minr >*/
	    rdcom_1.ltry[feq_gen_i_d_ - 1] = minr;
/* SOURCE runinit.for:2970 */
/*<       minrow(i)=minr >*/
	    rdcom_1.minrow[feq_gen_i_d_ - 1] = minr;
/* SOURCE runinit.for:2971 */
/*<       maxrow(i)=minr+each-1 >*/
	    rdcom_1.maxrow[feq_gen_i_d_ - 1] = minr + each - 1;
/* SOURCE runinit.for:2972 */
/*<       minr=minr+each >*/
	    minr += each;
/*         FILL THE CURRENT BUFFER FROM THE FILE */
/* SOURCE runinit.for:2976 */
/*<       if(dss_index_in(i).eq.0)then >*/
	    if (rdcom_1.feq_gen_dss_index_in_d_[feq_gen_i_d_ - 1] == 0) {
/* SOURCE runinit.for:2977 */
/*<       do150j=minrow(i),maxrow(i) >*/
		feq_gen_i_d_2 = rdcom_1.maxrow[feq_gen_i_d_ - 1];
		for (j = rdcom_1.minrow[feq_gen_i_d_ - 1]; j <= feq_gen_i_d_2; ++j) {
/* SOURCE runinit.for:2978 */
/*<       read(un,rec=rd_rec(i))jt,valain(j) >*/
		    feq_gen_io_d__367.ciunit = un;
		    feq_gen_io_d__367.cirec = rdcom_1.feq_gen_rd_rec_d_[feq_gen_i_d_ - 1];
		    s_rdue(&feq_gen_io_d__367);
		    do_uio(&feq_gen_c_d_1, (char *)&jt, (ftnlen)sizeof(doublereal));
		    do_uio(&feq_gen_c_d_1, (char *)&rdcom_1.valain[j - 1], (ftnlen)
			    sizeof(real));
		    e_rdue();
/* SOURCE runinit.for:2979 */
/*<       rd_rec(i)=rd_rec(i)+1 >*/
		    ++rdcom_1.feq_gen_rd_rec_d_[feq_gen_i_d_ - 1];
/*             Check for end of file. */
/* SOURCE runinit.for:2982 */
/*<       if(jt.eq.0.d0)goto160 >*/
		    if (jt == 0.) {
			goto L160;
		    }
/* SOURCE runinit.for:2983 */
/*<       jtin(j)=jt >*/
		    rdcom_1.jtin[j - 1] = jt;
/* SOURCE runinit.for:2984 */
/*<   150 continue >*/
/* L150: */
		}
/* SOURCE runinit.for:2985 */
/*<       j=maxrow(i) >*/
		j = rdcom_1.maxrow[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:2986 */
/*<   160 continue >*/
L160:
/*           Reset the list head so that it always points to the */
/*           first invalid value when traversing the buffer clockwise. */
/*           If buffer is full the first invalid value is the first */
/*           value in the buffer.  However, if the buffer is not */
/*           full, then the first invalid value is the value next */
/*           after the last value. */
/* SOURCE runinit.for:2993 */
/*<       j=j+1 >*/
		++j;
/* SOURCE runinit.for:2994 */
/*<       if(j.gt.maxrow(i))j=minrow(i) >*/
		if (j > rdcom_1.maxrow[feq_gen_i_d_ - 1]) {
		    j = rdcom_1.minrow[feq_gen_i_d_ - 1];
		}
/* SOURCE runinit.for:2995 */
/*<       lsthd(i)=j >*/
		rdcom_1.lsthd[feq_gen_i_d_ - 1] = j;
/* SOURCE runinit.for:2997 */
/*<       else >*/
	    } else {
/*           Fill the buffer from the HECDSS path name. */
/* SOURCE runinit.for:2999 */
/*<       jt=sjtime >*/
		jt = julian_1.sjtime;
/* SOURCE runinit.for:3000 */
/*<        >*/
		feq_gen_chk_hecdss_record_d_(stdout, rdcomc_1.namin + (feq_gen_i_d_ - 1 << 8), &
			rdcom_1.feq_gen_dss_index_in_d_[feq_gen_i_d_ - 1], &
			rdcom_1.feq_gen_time_step_in_d_[feq_gen_i_d_ - 1], const_cast<char*>("INST-VAL"), &jt, &
			feq_gen_start_time_d_, &eflag, (ftnlen)256, (ftnlen)8);
/* SOURCE runinit.for:3004 */
/*<       if(eflag.eq.1)then >*/
		if (eflag == 1) {
/* SOURCE runinit.for:3005 */
/*<       write(stdout,51)unin(i),start_time,sjtime >*/
		    feq_gen_io_d__370.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__370);
		    do_fio(&feq_gen_c_d_1, (char *)&rdcom_1.unin[feq_gen_i_d_ - 1], (ftnlen)
			    sizeof(integer));
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_start_time_d_, (ftnlen)sizeof(
			    doublereal));
		    do_fio(&feq_gen_c_d_1, (char *)&julian_1.sjtime, (ftnlen)sizeof(
			    doublereal));
		    e_wsfe();
/* SOURCE runinit.for:3006 */
/*<       write(stdout,57)namin(i) >*/
		    feq_gen_io_d__371.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__371);
		    do_fio(&feq_gen_c_d_1, rdcomc_1.namin + (feq_gen_i_d_ - 1 << 8), (ftnlen)
			    256);
		    e_wsfe();
/* SOURCE runinit.for:3007 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:3008 */
/*<       elseif(eflag.eq.2)then >*/
		} else if (eflag == 2) {
/* SOURCE runinit.for:3009 */
/*<       write(stdout,58)unin(i),namin(i) >*/
		    feq_gen_io_d__372.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__372);
		    do_fio(&feq_gen_c_d_1, (char *)&rdcom_1.unin[feq_gen_i_d_ - 1], (ftnlen)
			    sizeof(integer));
		    do_fio(&feq_gen_c_d_1, rdcomc_1.namin + (feq_gen_i_d_ - 1 << 8), (ftnlen)
			    256);
		    e_wsfe();
/* SOURCE runinit.for:3010 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:3011 */
/*<       endif >*/
		}
/* SOURCE runinit.for:3012 */
/*<       need=maxrow(i)-minrow(i)+1 >*/
		need = rdcom_1.maxrow[feq_gen_i_d_ - 1] - rdcom_1.minrow[feq_gen_i_d_ - 1] + 1;
/* SOURCE runinit.for:3013 */
/*<       jt=start_time >*/
		jt = feq_gen_start_time_d_;
/* SOURCE runinit.for:3014 */
/*<        >*/
		feq_gen_get_hecdss_block_d_(stdout, rdcomc_1.namin + (feq_gen_i_d_ - 1 << 8), &
			rdcom_1.feq_gen_dss_index_in_d_[feq_gen_i_d_ - 1], &
			rdcom_1.feq_gen_time_step_in_d_[feq_gen_i_d_ - 1], const_cast<char*>("INST-VAL"), &jt, &
			need, &got, rdcom_1.jtvec, rdcom_1.tmpvec, &
			feq_gen_tmpvec_size_d_, (ftnlen)256, (ftnlen)8);
/* SOURCE runinit.for:3018 */
/*<       do170j=1,got >*/
		feq_gen_i_d_2 = got;
		for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE runinit.for:3019 */
/*<       jtin(minrow(i)+j-1)=jtvec(j) >*/
		    rdcom_1.jtin[rdcom_1.minrow[feq_gen_i_d_ - 1] + j - 2] = 
			    rdcom_1.jtvec[j - 1];
/* SOURCE runinit.for:3020 */
/*<       valain(minrow(i)+j-1)=tmpvec(j) >*/
		    rdcom_1.valain[rdcom_1.minrow[feq_gen_i_d_ - 1] + j - 2] = 
			    rdcom_1.tmpvec[j - 1];
/* SOURCE runinit.for:3021 */
/*<   170 continue >*/
/* L170: */
		}
/*           Reset the list head so that it always points to the */
/*           first invalid value when traversing the buffer clockwise. */
/*           If buffer is full the first invalid value is the first */
/*           value in the buffer.  However, if the buffer is not */
/*           full, then the first invalid value is the value next */
/*           after the last value. */
/* SOURCE runinit.for:3028 */
/*<       j=minrow(i)+got-1 >*/
		j = rdcom_1.minrow[feq_gen_i_d_ - 1] + got - 1;
/* SOURCE runinit.for:3029 */
/*<       j=j+1 >*/
		++j;
/* SOURCE runinit.for:3030 */
/*<       if(j.gt.maxrow(i))j=minrow(i) >*/
		if (j > rdcom_1.maxrow[feq_gen_i_d_ - 1]) {
		    j = rdcom_1.minrow[feq_gen_i_d_ - 1];
		}
/* SOURCE runinit.for:3031 */
/*<       lsthd(i)=j >*/
		rdcom_1.lsthd[feq_gen_i_d_ - 1] = j;
/* SOURCE runinit.for:3033 */
/*<       endif >*/
	    }
/*         MAKE SURE THAT THE START TIME FOR EACH INPUT FILE IS AT OR */
/*         BEFORE THE START TIME OF THE RUN. */
/* SOURCE runinit.for:3038 */
/*<       if(sjtime.lt.jtin(minrow(i)))then >*/
	    if (julian_1.sjtime < rdcom_1.jtin[rdcom_1.minrow[feq_gen_i_d_ - 1] - 1]) {
/* SOURCE runinit.for:3039 */
/*<       write(stdout,51)unin(i),jtin(minrow(i)),sjtime >*/
		feq_gen_io_d__375.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__375);
		do_fio(&feq_gen_c_d_1, (char *)&rdcom_1.unin[feq_gen_i_d_ - 1], (ftnlen)sizeof(
			integer));
		do_fio(&feq_gen_c_d_1, (char *)&rdcom_1.jtin[rdcom_1.minrow[feq_gen_i_d_ - 1] - 
			1], (ftnlen)sizeof(doublereal));
		do_fio(&feq_gen_c_d_1, (char *)&julian_1.sjtime, (ftnlen)sizeof(
			doublereal));
		e_wsfe();
/* SOURCE runinit.for:3040 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:3041 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:3043 */
/*<   500 continue >*/
/* L500: */
	}
/* SOURCE runinit.for:3045 */
/*<       endif >*/
    }
/* SOURCE runinit.for:3046 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:3047 */
/*<       end >*/
} /* rdinit_ */




/* SOURCE runinit.for:3051 */
/*<       subroutinereadoc() >*/
/* Subroutine */ int readoc_()
{
    /* Format strings */
    static char fmt_10[] = "(/,\002This TSF was created on \002,i4,\002/\002\
,i2,\002/\002,i2,\002 AT \002,i4,\002 and has \002,i3,\002 LSRO values.\002)";
    static char fmt_11[] = "(\002 \002,\002Simulation for the \002,\002runof\
f values began on \002,i4,\002/\002,i2,\002/\002,i2,\002 and ended on \002,i\
4,\002/\002,i2,\002/\002,i2,\002.\002)";
    static char fmt_14[] = "(/,32a4)";
    static char fmt_16[] = "(4x,\002LSRO# \002,i2,\002:\002,20a4)";
    static char fmt_20[] = "(/,\002*****************************************\
********\002)";
    static char fmt_50[] = "(/,\002*ERR:154* There are\002,i3,\002 values in\
 each record of\002,/,\002       the diffuse TSF but only\002,i3,\002 values\
 allowed in FEQ.\002)";
    static char fmt_60[] = "(/,\002*ERR:155* There are\002,i3,\002 diffuse f\
lows in the\002,/,\002       diffuse flow file but \002,i3,\002 land uses in\
 FEQ.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(), s_rdue(cilist *), do_uio(integer *, 
	    char *, ftnlen), e_rdue(), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer a[135];
    char feq_gen_c_d_[4*135];
    integer feq_gen_i_d_, j, temp[10], limit;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__376 = { 0, 0, 0, fmt_20, 0 };
    static cilist feq_gen_io_d__377 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__380 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__381 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__383 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__385 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__386 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__388 = { 0, 0, 0, fmt_14, 0 };
    static cilist feq_gen_io_d__389 = { 0, 0, 0, fmt_10, 0 };
    static cilist feq_gen_io_d__390 = { 0, 0, 0, fmt_11, 0 };
    static cilist feq_gen_io_d__391 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__393 = { 0, 0, 0, fmt_16, 0 };
    static cilist feq_gen_io_d__394 = { 0, 0, 0, fmt_20, 0 };


/*     + + + PURPOSE + + + */
/*     Read documentation information from header of TSFDSN. */
/* SOURCE runinit.for:3056 */
/*<       implicitnone >*/
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE runinit.for:3058 */
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
/* INCLUDE runinit.for:3059 */
/* *********************************************************************** */
/* SOURCE tsfcom.cmn:2 */
/*<        >*/
/* SOURCE tsfcom.cmn:6 */
/*<        >*/
/* SOURCE tsfcom.cmn:8 */
/*<       integerbwyr(mndbuf),bord(mndbuf),gend(0:mxgage),gstart(0:mxgage) >*/
/* SOURCE tsfcom.cmn:10 */
/*<       realdtend >*/
/* SOURCE tsfcom.cmn:11 */
/*<       realtriba(mxr_triba,mxn_lu_g),tsfrat(mndbuf,mndifa),tafac(mnbra) >*/
/* SOURCE tsfcom.cmn:14 */
/*<       real*8tsfbuf(mndbuf,mndifa),bjtime(mndbuf) >*/
/* *********************************************************************** */
/* INCLUDE runinit.for:3060 */
/* ********************************************************************** */
/* SOURCE xscom.cmn:2 */
/*<       integereflag,in,stdout,output,prout,lout >*/
/* SOURCE xscom.cmn:4 */
/*<       realsseps >*/
/* SOURCE xscom.cmn:6 */
/*<       real*8time >*/
/* SOURCE xscom.cmn:8 */
/*<       common/xscom/time,eflag,sseps,in,stdout,output,prout,lout >*/
/* ********************************************************************** */
/* INCLUDE runinit.for:3061 */
/*     NAMES FOR VARIOUS OPTIONAL FILES AND SPECIAL OUTPUT FILE */
/*     HEADINGS */
/* SOURCE namcom.cmn:5 */
/*<       character*7sphead(mnsout,2) >*/
/* SOURCE namcom.cmn:7 */
/*<       character*256bwfnam,fffnam,tsfnam,putnam,getnam >*/
/* SOURCE namcom.cmn:9 */
/*<       common/namcom/bwfnam,fffnam,tsfnam,sphead,putnam,getnam >*/
/* INCLUDE runinit.for:3062 */
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
/* SOURCE runinit.for:3066 */
/*<       integeri,j,limit >*/
/* SOURCE runinit.for:3067 */
/*<       integera(7+mndifa),temp(10) >*/
/* SOURCE runinit.for:3068 */
/*<       characterc(7+mndifa)*4 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE runinit.for:3073 */
/*<       intrinsicmin >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE runinit.for:3076 */
/*<    10  >*/
/* SOURCE runinit.for:3079 */
/*<    11  >*/
/* SOURCE runinit.for:3082 */
/*<    14 format(/,32a4) >*/
/* SOURCE runinit.for:3083 */
/*<    16 format(4x,'LSRO# ',i2,':',20a4) >*/
/* SOURCE runinit.for:3084 */
/*<    20 format(/,'*************************************************') >*/
/* SOURCE runinit.for:3085 */
/*<    50  >*/
/* SOURCE runinit.for:3087 */
/*<    60  >*/
/* *********************************************************************** */
/* SOURCE runinit.for:3090 */
/*<       write(std6,20) >*/
/* L10: */
/* L11: */
/* L14: */
/* L16: */
/* L20: */
/* L50: */
/* L60: */
    feq_gen_io_d__376.ciunit = feq_gen_stdun_com_d_1.std6;
    s_wsfe(&feq_gen_io_d__376);
    e_wsfe();
/*     READ THE FIRST PART OF THE second RECORD TO ESTABLISH THE FORMAT OF */
/*     THE DTSF */
/* SOURCE runinit.for:3095 */
/*<       read(tsfdsn,rec=dtsf_rec)(a(i),i=1,7) >*/
    feq_gen_io_d__377.ciunit = tsfcom_1.tsfdsn;
    feq_gen_io_d__377.cirec = tsfcom_1.feq_gen_dtsf_rec_d_;
    s_rdue(&feq_gen_io_d__377);
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 7; ++feq_gen_i_d_) {
	do_uio(&feq_gen_c_d_1, (char *)&a[feq_gen_i_d_ - 1], (ftnlen)sizeof(integer));
    }
    e_rdue();
/* SOURCE runinit.for:3096 */
/*<       dtsf_rec=dtsf_rec+1 >*/
    ++tsfcom_1.feq_gen_dtsf_rec_d_;
/*      NREC = A(5) */
/* SOURCE runinit.for:3099 */
/*<       ndfval=a(6) >*/
    tsfcom_1.ndfval = a[5];
/* SOURCE runinit.for:3100 */
/*<       tsftyp=a(7) >*/
    tsfcom_1.tsftyp = a[6];
/*      IF(TSFTYP.EQ.0) THEN */
/*        WRITE(STD6,*) ' ' */
/*        WRITE(STD6,*) ' TSF uses 8 bytes per runoff value' */
/*      ELSE */
/*        WRITE(STD6,*) ' ' */
/*        WRITE(STD6,*) ' TSF uses 4 bytes per runoff value' */
/*      ENDIF */
/* SOURCE runinit.for:3111 */
/*<       if(ndfval.gt.mndifa)then >*/
    if (tsfcom_1.ndfval > 128) {
/* SOURCE runinit.for:3112 */
/*<       write(std6,50)ndfval,mndifa >*/
	feq_gen_io_d__380.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsfe(&feq_gen_io_d__380);
	do_fio(&feq_gen_c_d_1, (char *)&tsfcom_1.ndfval, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_128, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE runinit.for:3113 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:3114 */
/*<       endif >*/
    }
/* SOURCE runinit.for:3116 */
/*<       if(ndfval.ne.nluse)then >*/
    if (tsfcom_1.ndfval != tsfcom_1.nluse) {
/* SOURCE runinit.for:3117 */
/*<       write(stdout,60)ndfval,nluse >*/
	feq_gen_io_d__381.ciunit = xscom_1.stdout;
	s_wsfe(&feq_gen_io_d__381);
	do_fio(&feq_gen_c_d_1, (char *)&tsfcom_1.ndfval, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&tsfcom_1.nluse, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE runinit.for:3118 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:3119 */
/*<       endif >*/
    }
/* SOURCE runinit.for:3121 */
/*<       limit=7+nluse >*/
    limit = tsfcom_1.nluse + 7;
/* SOURCE runinit.for:3123 */
/*<       dtsf_rec=2 >*/
    tsfcom_1.feq_gen_dtsf_rec_d_ = 2;
/* SOURCE runinit.for:3124 */
/*<       read(tsfdsn,rec=dtsf_rec)(a(i),i=1,limit) >*/
    feq_gen_io_d__383.ciunit = tsfcom_1.tsfdsn;
    feq_gen_io_d__383.cirec = tsfcom_1.feq_gen_dtsf_rec_d_;
    s_rdue(&feq_gen_io_d__383);
    feq_gen_i_d_1 = limit;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
	do_uio(&feq_gen_c_d_1, (char *)&a[feq_gen_i_d_ - 1], (ftnlen)sizeof(integer));
    }
    e_rdue();
/* SOURCE runinit.for:3125 */
/*<       dtsf_rec=dtsf_rec+1 >*/
    ++tsfcom_1.feq_gen_dtsf_rec_d_;
/* SOURCE runinit.for:3127 */
/*<       do12i=1,4 >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 4; ++feq_gen_i_d_) {
/* SOURCE runinit.for:3128 */
/*<       temp(i)=a(i) >*/
	temp[feq_gen_i_d_ - 1] = a[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:3129 */
/*<    12 continue >*/
/* L12: */
    }
/* SOURCE runinit.for:3131 */
/*<       read(tsfdsn,rec=dtsf_rec)(a(i),i=1,limit) >*/
    feq_gen_io_d__385.ciunit = tsfcom_1.tsfdsn;
    feq_gen_io_d__385.cirec = tsfcom_1.feq_gen_dtsf_rec_d_;
    s_rdue(&feq_gen_io_d__385);
    feq_gen_i_d_1 = limit;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
	do_uio(&feq_gen_c_d_1, (char *)&a[feq_gen_i_d_ - 1], (ftnlen)sizeof(integer));
    }
    e_rdue();
/* SOURCE runinit.for:3132 */
/*<       dtsf_rec=dtsf_rec+1 >*/
    ++tsfcom_1.feq_gen_dtsf_rec_d_;
/* SOURCE runinit.for:3133 */
/*<       do13i=5,10 >*/
    for (feq_gen_i_d_ = 5; feq_gen_i_d_ <= 10; ++feq_gen_i_d_) {
/* SOURCE runinit.for:3134 */
/*<       temp(i)=a(i-4) >*/
	temp[feq_gen_i_d_ - 1] = a[feq_gen_i_d_ - 5];
/* SOURCE runinit.for:3135 */
/*<    13 continue >*/
/* L13: */
    }
/* SOURCE runinit.for:3137 */
/*<       read(tsfdsn,rec=dtsf_rec)(c(i),i=1,limit) >*/
    feq_gen_io_d__386.ciunit = tsfcom_1.tsfdsn;
    feq_gen_io_d__386.cirec = tsfcom_1.feq_gen_dtsf_rec_d_;
    s_rdue(&feq_gen_io_d__386);
    feq_gen_i_d_1 = limit;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
	do_uio(&feq_gen_c_d_1, feq_gen_c_d_ + (feq_gen_i_d_ - 1 << 2), (ftnlen)4);
    }
    e_rdue();
/* SOURCE runinit.for:3138 */
/*<       dtsf_rec=dtsf_rec+1 >*/
    ++tsfcom_1.feq_gen_dtsf_rec_d_;
/* SOURCE runinit.for:3139 */
/*<       write(std6,14)(c(i),i=1,min(32,limit)) >*/
    feq_gen_io_d__388.ciunit = feq_gen_stdun_com_d_1.std6;
    s_wsfe(&feq_gen_io_d__388);
    feq_gen_i_d_1 = min(32,limit);
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
	do_fio(&feq_gen_c_d_1, feq_gen_c_d_ + (feq_gen_i_d_ - 1 << 2), (ftnlen)4);
    }
    e_wsfe();
/* SOURCE runinit.for:3140 */
/*<       write(std6,10)(temp(i),i=1,4),ndfval >*/
    feq_gen_io_d__389.ciunit = feq_gen_stdun_com_d_1.std6;
    s_wsfe(&feq_gen_io_d__389);
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 4; ++feq_gen_i_d_) {
	do_fio(&feq_gen_c_d_1, (char *)&temp[feq_gen_i_d_ - 1], (ftnlen)sizeof(integer));
    }
    do_fio(&feq_gen_c_d_1, (char *)&tsfcom_1.ndfval, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE runinit.for:3141 */
/*<       write(std6,11)(temp(i),i=5,10) >*/
    feq_gen_io_d__390.ciunit = feq_gen_stdun_com_d_1.std6;
    s_wsfe(&feq_gen_io_d__390);
    for (feq_gen_i_d_ = 5; feq_gen_i_d_ <= 10; ++feq_gen_i_d_) {
	do_fio(&feq_gen_c_d_1, (char *)&temp[feq_gen_i_d_ - 1], (ftnlen)sizeof(integer));
    }
    e_wsfe();
/* SOURCE runinit.for:3143 */
/*<       do15i=1,ndfval >*/
    feq_gen_i_d_1 = tsfcom_1.ndfval;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:3144 */
/*<       read(tsfdsn,rec=dtsf_rec)(c(j),j=1,limit) >*/
	feq_gen_io_d__391.ciunit = tsfcom_1.tsfdsn;
	feq_gen_io_d__391.cirec = tsfcom_1.feq_gen_dtsf_rec_d_;
	s_rdue(&feq_gen_io_d__391);
	feq_gen_i_d_2 = limit;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
	    do_uio(&feq_gen_c_d_1, feq_gen_c_d_ + (j - 1 << 2), (ftnlen)4);
	}
	e_rdue();
/* SOURCE runinit.for:3145 */
/*<       dtsf_rec=dtsf_rec+1 >*/
	++tsfcom_1.feq_gen_dtsf_rec_d_;
/* SOURCE runinit.for:3146 */
/*<       write(std6,16)i,(c(j),j=1,min(20,limit)) >*/
	feq_gen_io_d__393.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsfe(&feq_gen_io_d__393);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	feq_gen_i_d_2 = min(20,limit);
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
	    do_fio(&feq_gen_c_d_1, feq_gen_c_d_ + (j - 1 << 2), (ftnlen)4);
	}
	e_wsfe();
/* SOURCE runinit.for:3147 */
/*<    15 continue >*/
/* L15: */
    }
/* SOURCE runinit.for:3149 */
/*<       write(std6,20) >*/
    feq_gen_io_d__394.ciunit = feq_gen_stdun_com_d_1.std6;
    s_wsfe(&feq_gen_io_d__394);
    e_wsfe();
/* SOURCE runinit.for:3152 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:3154 */
/*<       end >*/
} /* readoc_ */




/* SOURCE runinit.for:3158 */
/*<       subroutinertbadj(stdout,nex,exnodt,mremc,emc,ftknt,ftpnt,ze,ye1) >*/
/* Subroutine */ int rtbadj_(integer *stdout, integer *nex, integer *feq_storage_exnodt, 
	integer *mremc, integer *feq_storage_emc, integer *ftknt, integer *feq_storage_ftpnt, real *
	feq_storage_ze, real *feq_storage_ye1)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 Adjustment of table argument for Level-P\
ool \002,\002Reservoirs\002,/,5x,\002 Elevation transformed to maximum dept\
h\002,/,\002 LPR Node TableId_________  Base Elev\002)";
    static char fmt_52[] = "(4x,a5,1x,a16,1x,f10.3)";
    static char fmt_54[] = "(\002 No level-pool reservoirs found to adjust\
.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5], feq_gen_ch_d_3[16], feq_gen_ch_d_4[16];

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    extern /* Subroutine */ int fnd7_(integer *, integer *, integer *, 
	    integer *, integer *, integer *);
    integer feq_gen_flag_d_, adrs;
    real zbot;
    extern /* Subroutine */ int adj234_(integer *, real *, integer *);
    integer nflag, inode, rnode;
    extern integer gettbn_(integer *);
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__396 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__403 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__404 = { 0, 0, 0, fmt_54, 0 };


/*     + + + PURPOSE + + + */
/*     Adjust the reservoir storage table to allow the user to select */
/*     treating reservoirs like cross sections.  That is, the argument */
/*     to the table is depth, and the minimum point in the reservoir */
/*     is the point of zero depth. */
/* SOURCE runinit.for:3168 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE runinit.for:3170 */
/*<       integerftknt,stdout,mremc,nex >*/
/* SOURCE runinit.for:3171 */
/*<       integeremc(mremc),exnodt(9,nex),ftpnt(ftknt) >*/
/* SOURCE runinit.for:3172 */
/*<       realye1(nex),ze(nex) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NEX    - number of exterior nodes in the model */
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
/*     MREMC  - maximum length of EMC(*). Same as LEMC */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     FTKNT  - count of number of function tables currently in the */
/*              function-table system */
/*     FTPNT  - vector of addresses(indices) into function-table system */
/*              for a given internal table number. */
/*     ZE     - elevation of datum for depth at exterior node */
/*     YE1    - depths at exterior nodes at start of time step */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE runinit.for:3200 */
/*<       integeradrs,flag,i,inode,nflag,rnode >*/
/* SOURCE runinit.for:3201 */
/*<       realzbot >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE runinit.for:3204 */
/*<       integergettbn >*/
/* SOURCE runinit.for:3205 */
/*<       charactergetusn*5,get_tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE runinit.for:3208 */
/*<       externaladj234,fnd7,gettbn,getusn,get_tabid >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE runinit.for:3211 */
/*<    50  >*/
/* SOURCE runinit.for:3214 */
/*<    52 format(4x,a5,1x,a16,1x,f10.3) >*/
/* SOURCE runinit.for:3215 */
/*<    54 format(' No level-pool reservoirs found to adjust.') >*/
/* *********************************************************************** */
/*     Scan for level-pool reservoirs.  May not be any. */
/* SOURCE runinit.for:3218 */
/*<       nflag=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> ye1(feq_storage_ye1, 1);

    feq::IndexedPointer<real> ze(feq_storage_ze, 1);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    feq::IndexedPointer<integer> ftpnt(feq_storage_ftpnt, 1);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
    nflag = 0;
/* SOURCE runinit.for:3219 */
/*<       write(stdout,50) >*/
    feq_gen_io_d__396.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__396);
    e_wsfe();
/* SOURCE runinit.for:3220 */
/*<       do500i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:3221 */
/*<       if(exnodt(3,i).lt.0)then >*/
	if (exnodt[feq_gen_i_d_ * 9 + 3] < 0) {
/*         We have a level-pool reservoir.  Find the other values */
/*         from EMC */
/* SOURCE runinit.for:3224 */
/*<       rnode=i >*/
	    rnode = feq_gen_i_d_;
/* SOURCE runinit.for:3225 */
/*<       callfnd7(stdout,rnode,emc,mremc,inode,adrs) >*/
	    fnd7_(stdout, &rnode, &emc[1], mremc, &inode, &adrs);
/*         Convert an internal table number to the address */
/*         for that table.  Subroutine CHKEX makes the conversion */
/*         in EMC(*) but this routine is now called before CHKEX! */
/* SOURCE runinit.for:3232 */
/*<       adrs=ftpnt(adrs) >*/
	    adrs = ftpnt[adrs];
/* SOURCE runinit.for:3233 */
/*<       if(ze(rnode).eq.0.0.and.ze(inode).eq.0.0)then >*/
	    if (ze[rnode] == (float)0. && ze[inode] == (float)0.) {
/*           Possible request for adustment of the table and */
/*           value output for depth for level-pool reservoirs. */
/* SOURCE runinit.for:3236 */
/*<       calladj234(adrs,zbot,flag) >*/
		adj234_(&adrs, &zbot, &feq_gen_flag_d_);
/* SOURCE runinit.for:3239 */
/*<       if(flag.gt.0)then >*/
		if (feq_gen_flag_d_ > 0) {
/*             We have an adjustment request.  The table has already */
/*             been adjusted.  Adjust the values for depth and */
/*             bottom elevation. */
/* SOURCE runinit.for:3243 */
/*<       nflag=1 >*/
		    nflag = 1;
/* SOURCE runinit.for:3244 */
/*<       ze(rnode)=zbot >*/
		    ze[rnode] = zbot;
/* SOURCE runinit.for:3245 */
/*<       ze(inode)=zbot >*/
		    ze[inode] = zbot;
/* SOURCE runinit.for:3246 */
/*<       ye1(rnode)=ye1(rnode)-zbot >*/
		    ye1[rnode] -= static_cast<double>(zbot);
/* SOURCE runinit.for:3247 */
/*<       ye1(inode)=ye1(inode)-zbot >*/
		    ye1[inode] -= static_cast<double>(zbot);
/* SOURCE runinit.for:3248 */
/*<       write(stdout,52)getusn(rnode),get_tabid(gettbn(adrs)),zbot >*/
		    feq_gen_io_d__403.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__403);
		    getusn_(feq_gen_ch_d_2, (ftnlen)5, &rnode);
		    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		    feq_gen_i_d_2 = gettbn_(&adrs);
		    feq_gen_get_tabid_d_(feq_gen_ch_d_4, (ftnlen)16, &feq_gen_i_d_2);
		    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)16, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, (char *)&zbot, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE runinit.for:3250 */
/*<       endif >*/
		}
/* SOURCE runinit.for:3251 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:3252 */
/*<       endif >*/
	}
/* SOURCE runinit.for:3253 */
/*<   500 continue >*/
/* L500: */
    }
/* SOURCE runinit.for:3254 */
/*<       if(nflag.eq.0)then >*/
    if (nflag == 0) {
/* SOURCE runinit.for:3255 */
/*<       write(stdout,54) >*/
	feq_gen_io_d__404.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__404);
	e_wsfe();
/* SOURCE runinit.for:3256 */
/*<       endif >*/
    }
/* SOURCE runinit.for:3257 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:3258 */
/*<       end >*/
} /* rtbadj_ */

/*     *********** */
/*     *         * */
/*     * SET_NDFVAL  * */
/*     *         * */
/*     *********** */
/* SOURCE runinit.for:3265 */
/*<       subroutineset_ndfval(n) >*/
/* Subroutine */ int feq_gen_set_ndfval_d_(integer *n)
{
/*     Set the value of NDFVAL in its common block when the diffuse */
/*     flows come from a HECDSS. */
/* SOURCE runinit.for:3270 */
/*<       implicitnone >*/
/* SOURCE runinit.for:3271 */
/*<       integern >*/
/* INCLUDE runinit.for:3273 */
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
/* INCLUDE runinit.for:3274 */
/* *********************************************************************** */
/* SOURCE tsfcom.cmn:2 */
/*<        >*/
/* SOURCE tsfcom.cmn:6 */
/*<        >*/
/* SOURCE tsfcom.cmn:8 */
/*<       integerbwyr(mndbuf),bord(mndbuf),gend(0:mxgage),gstart(0:mxgage) >*/
/* SOURCE tsfcom.cmn:10 */
/*<       realdtend >*/
/* SOURCE tsfcom.cmn:11 */
/*<       realtriba(mxr_triba,mxn_lu_g),tsfrat(mndbuf,mndifa),tafac(mnbra) >*/
/* SOURCE tsfcom.cmn:14 */
/*<       real*8tsfbuf(mndbuf,mndifa),bjtime(mndbuf) >*/
/* *********************************************************************** */
/* *********************************************************************** */
/* SOURCE runinit.for:3276 */
/*<       ndfval=n >*/
    tsfcom_1.ndfval = *n;
/* SOURCE runinit.for:3277 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:3278 */
/*<       end >*/
} /* set_ndfval__ */




/* SOURCE runinit.for:3282 */
/*<       subroutinesetcon(nex,emc,exnodt,bdynum,resnum) >*/
/* Subroutine */ int setcon_(integer *nex, integer *feq_storage_emc, integer *feq_storage_exnodt, 
	integer *bdynum, integer *resnum)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer j, k, n, code, node;
    extern /* Subroutine */ int iasort_(integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__407 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__411 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Establish the values needed for checking the system */
/*     wide conservation of water volume. */
/* SOURCE runinit.for:3290 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE runinit.for:3292 */
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
/* SOURCE runinit.for:3295 */
/*<       integerbdynum,nex,resnum >*/
/* SOURCE runinit.for:3296 */
/*<       integeremc(mremc),exnodt(9,nex) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NEX    - number of exterior nodes in the model */
/*     EMC    - vector containing coded form of the Matrix Control Input */
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
/*     BDYNUM - number of boundary nodes in the model */
/*     RESNUM - number of level-pool reservoirs */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE runinit.for:3319 */
/* ********************************************************************** */
/* SOURCE enothr.cmn:3 */
/*<        >*/
/* SOURCE enothr.cmn:6 */
/*<       common/enothc/enodid >*/
/* SOURCE enothr.cmn:8 */
/*<       character*16enodid(mnex) >*/
/* SOURCE enothr.cmn:10 */
/*<       integerbdyvec(mnex),resvec(mnex),non_conv_enode(mnex) >*/
/* SOURCE enothr.cmn:12 */
/*<       realencorq(mnex),encory(mnex),enmaxy(mnex),enminy(mnex) >*/
/* ********************************************************************** */
/* INCLUDE runinit.for:3320 */
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
/* SOURCE runinit.for:3323 */
/*<       integercode,j,k,n,node >*/
/*     + + + INTRINSICS + + + */
/* SOURCE runinit.for:3326 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE runinit.for:3329 */
/*<       externaliasort >*/
/* *********************************************************************** */
/*     USE RESVEC FOR WORK SPACE INITIALLY */
/* SOURCE runinit.for:3333 */
/*<       do100j=1,nex >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
    feq_gen_i_d_1 = *nex;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/*       NODES APPEAR AT MOST ONCE IN CODE 2.  TO BE CONNECTED TO THE */
/*       SYSTEM A NODE MUST APPEAR IN CODE 2, OTHERWISE THE NODE */
/*       IS A BOUNDARY NODE. */
/* SOURCE runinit.for:3338 */
/*<       resvec(j)=1 >*/
	enothr_1.resvec[j - 1] = 1;
/* SOURCE runinit.for:3339 */
/*<   100 continue >*/
/* L100: */
    }
/*     START LOOP OVER ENTRIES IN NETWORK-MATRIX CONTROL */
/*     DELETE ALL NODES OCCURING IN THE NODE LISTS FOR CODE 2. */
/*     ONLY ONE INFLOW NODE WILL BE ALLOWED FOR A RESERVOIR. */
/*     IF IT DOES NOT APPEAR IN CODE 2 IT IS A BOUNDARY NODE. */
/* SOURCE runinit.for:3345 */
/*<       j=emc(1) >*/
    j = emc[1];
/* SOURCE runinit.for:3346 */
/*<  1000 continue >*/
L1000:
/* SOURCE runinit.for:3347 */
/*<       code=emc(j) >*/
    code = emc[j];
/* SOURCE runinit.for:3348 */
/*<       if(code.eq.-1)goto2000 >*/
    if (code == -1) {
	goto L2000;
    }
/* SOURCE runinit.for:3349 */
/*<        >*/
    switch (code) {
	case 1:  goto L1500;
	case 2:  goto L2;
	case 3:  goto L1500;
	case 4:  goto L1500;
	case 5:  goto L500;
	case 6:  goto L1500;
	case 7:  goto L1500;
	case 8:  goto L1500;
	case 9:  goto L1500;
	case 10:  goto L1500;
	case 11:  goto L1500;
	case 12:  goto L1500;
	case 13:  goto L1500;
	case 14:  goto L1500;
	case 15:  goto L1500;
    }
/* SOURCE runinit.for:3351 */
/*<       write(std6,*)' *BUG:15* INVALID EMC CODE IN SETCON. CODE=',code >*/
    feq_gen_io_d__407.ciunit = feq_gen_stdun_com_d_1.std6;
    s_wsle(&feq_gen_io_d__407);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:15* INVALID EMC CODE IN SETCON. CODE="), (
	    ftnlen)43);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE runinit.for:3353 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:3355 */
/*<     2 continue >*/
L2:
/* SOURCE runinit.for:3357 */
/*<       n=emc(j+1) >*/
    n = emc[j + 1];
/* SOURCE runinit.for:3358 */
/*<       do200k=1,n >*/
    feq_gen_i_d_1 = n;
    for (k = 1; k <= feq_gen_i_d_1; ++k) {
/* SOURCE runinit.for:3359 */
/*<       node=abs(emc(j+1+k)) >*/
	node = (feq_gen_i_d_2 = emc[j + 1 + k], abs(feq_gen_i_d_2));
/* SOURCE runinit.for:3360 */
/*<       resvec(node)=0 >*/
	enothr_1.resvec[node - 1] = 0;
/* SOURCE runinit.for:3361 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE runinit.for:3362 */
/*<       j=j+emc(j+1) >*/
    j += emc[j + 1];
/* SOURCE runinit.for:3363 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE runinit.for:3365 */
/*<   500 continue >*/
L500:
/* SOURCE runinit.for:3366 */
/*<       goto(10,20,30,40,50,60,70,80,90),emc(j+1) >*/
    switch (emc[j + 1]) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L40;
	case 5:  goto L50;
	case 6:  goto L60;
	case 7:  goto L70;
	case 8:  goto L80;
	case 9:  goto L90;
    }
/* SOURCE runinit.for:3367 */
/*<        >*/
    feq_gen_io_d__411.ciunit = feq_gen_stdun_com_d_1.std6;
    s_wsle(&feq_gen_io_d__411);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:40* INVALID CODE 5 TYPE IN SETCON."), (ftnlen)
	    40);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" TYPE="), (ftnlen)6);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&emc[j + 1], (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE runinit.for:3369 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:3370 */
/*<    10 continue >*/
L10:
/* SOURCE runinit.for:3371 */
/*<       j=j+cd5ty1 >*/
    j += 7;
/* SOURCE runinit.for:3372 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE runinit.for:3373 */
/*<    20 continue >*/
L20:
/* SOURCE runinit.for:3374 */
/*<       j=j+cd5ty2 >*/
    j += 12;
/* SOURCE runinit.for:3375 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE runinit.for:3376 */
/*<    30 continue >*/
L30:
/* SOURCE runinit.for:3377 */
/*<       j=j+cd5ty3 >*/
    j += 17;
/* SOURCE runinit.for:3378 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE runinit.for:3379 */
/*<    40 continue >*/
L40:
/* SOURCE runinit.for:3380 */
/*<       j=j+cd5ty4 >*/
    j += 10;
/* SOURCE runinit.for:3381 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE runinit.for:3382 */
/*<    50 continue >*/
L50:
/* SOURCE runinit.for:3383 */
/*<       j=j+cd5ty5 >*/
    j += 3;
/* SOURCE runinit.for:3384 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE runinit.for:3385 */
/*<    60 continue >*/
L60:
/* SOURCE runinit.for:3386 */
/*<       j=j+1+abs(emc(j+6))*cd5ty6 >*/
    j = j + 1 + ((feq_gen_i_d_1 = emc[j + 6], abs(feq_gen_i_d_1)) << 3);
/* SOURCE runinit.for:3387 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE runinit.for:3388 */
/*<    70 continue >*/
L70:
/* SOURCE runinit.for:3389 */
/*<       j=j+cd5ty7 >*/
    j += 10;
/* SOURCE runinit.for:3390 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE runinit.for:3391 */
/*<    80 continue >*/
L80:
/* SOURCE runinit.for:3392 */
/*<       j=j+cd5ty8 >*/
    j += 7;
/* SOURCE runinit.for:3393 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE runinit.for:3394 */
/*<    90 continue >*/
L90:
/* SOURCE runinit.for:3395 */
/*<       j=j+cd5ty9 >*/
    j += 11;
/* SOURCE runinit.for:3396 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE runinit.for:3398 */
/*<  1500 continue >*/
L1500:
/* SOURCE runinit.for:3399 */
/*<       j=j+emc(code+1) >*/
    j += emc[code + 1];
/* SOURCE runinit.for:3400 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE runinit.for:3402 */
/*<  2000 continue >*/
L2000:
/*     ESTABLISH LIST OF NODES ON THE BOUNDARY OF THE SYSTEM */
/*      WRITE(STD6,*) ' LIST OF BOUNDARY NODES' */
/*      WRITE(STD6,'(A)') ' NUM NODE' */
/* SOURCE runinit.for:3408 */
/*<       bdynum=0 >*/
    *bdynum = 0;
/* SOURCE runinit.for:3409 */
/*<       do2100j=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE runinit.for:3410 */
/*<       if(resvec(j).gt.0)then >*/
	if (enothr_1.resvec[j - 1] > 0) {
/* SOURCE runinit.for:3411 */
/*<       bdynum=bdynum+1 >*/
	    ++(*bdynum);
/* SOURCE runinit.for:3412 */
/*<       bdyvec(bdynum)=j >*/
	    enothr_1.bdyvec[*bdynum - 1] = j;
/*          WRITE(STD6,'(I5,1X,A4)') BDYNUM, GETUSN(J) */
/* SOURCE runinit.for:3414 */
/*<       endif >*/
	}
/* SOURCE runinit.for:3415 */
/*<  2100 continue >*/
/* L2100: */
    }
/*     ESTABLISH CORRECT VALUES IN RESVEC */
/* SOURCE runinit.for:3421 */
/*<       resnum=0 >*/
    *resnum = 0;
/* SOURCE runinit.for:3422 */
/*<       do2200j=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE runinit.for:3423 */
/*<       if(exnodt(3,j).ge.0)goto2200 >*/
	if (exnodt[j * 9 + 3] >= 0) {
	    goto L2200;
	}
/* SOURCE runinit.for:3424 */
/*<       resnum=resnum+1 >*/
	++(*resnum);
/* SOURCE runinit.for:3425 */
/*<       resvec(resnum)=j >*/
	enothr_1.resvec[*resnum - 1] = j;
/* SOURCE runinit.for:3426 */
/*<  2200 continue >*/
L2200:
	;
    }
/*     SORT RESERVOIR NODE LIST INTO ASCENDING ORDER */
/* SOURCE runinit.for:3430 */
/*<       if(resnum.gt.0)calliasort(resnum,resvec) >*/
    if (*resnum > 0) {
	iasort_(resnum, enothr_1.resvec);
    }
/* SOURCE runinit.for:3434 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:3435 */
/*<       end >*/
} /* setcon_ */




/* SOURCE runinit.for:3439 */
/*<        >*/
/* Subroutine */ int sfpsbm_(integer *stdout, integer *usnb, integer *fn, 
	integer *ln, integer *dn, integer *uexn, real *sfac, real *grav, real 
	*epsb, real *yd, integer *maxit, real *zi, real *feq_gen_dz_for_output_d_, 
	integer *eflag)
{
    // SFPSBM holds hydraulic temporaries in 53-bit registers.
    // In particular KM squared must not pass through a binary32 translation temporary.
    // Output statements store separate REAL argument copies, as in the original assembly.
    real feq_output_dg, feq_output_div, feq_output_feq_gen_r_d_1, feq_output_res, feq_output_yta;

    /* Format strings */
    static char fmt_2110[] = "(/,\002 *ERR:94* Downstream depth missing\
 \002,\002for branch\002,i5)";
    static char fmt_2130[] = "(/,\002 *ERR:95* Maximum iterations exceeded f\
or \002,\002Backwater Analysis\002)";
    static char fmt_2140[] = "(/,\002 Backwater Analysis Debug: Branch\002,i\
5,\002 NODE\002,i7/,4x,\002IT\002,11x,\002Y3\002,11x,\002YL\002,10x,\002RE\
S\002,11x,\002DG\002,10x,\002DIV\002)";
    static char fmt_2150[] = "(1x,i5,5(1pe13.5))";
    static char fmt_14000[] = "(1x,f8.0,i3,a7,a8,f8.1,f7.1,f7.3,f7.1,f9.3,1p\
e9.1,0pf4.1,1x,a)";
    static char fmt_14100[] = "(1x,f8.1,i3,a7,a8,f8.1,f7.1,f7.3,f7.1,f9.3,1p\
e9.1,0pf4.1,1x,a)";
    static char fmt_14200[] = "(1x,f8.2,i3,a7,a8,f8.1,f7.1,f7.3,f7.1,f9.3,1p\
e9.1,0pf4.1,1x,a)";
    static char fmt_14300[] = "(1x,f8.3,i3,a7,a8,f8.1,f7.1,f7.3,f7.1,f9.3,1p\
e9.1,0pf4.1,1x,a)";
    static char fmt_14400[] = "(1x,f8.4,i3,a7,a8,f8.1,f7.1,f7.3,f7.1,f9.3,1p\
e9.1,0pf4.1,1x,a)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    doublereal feq_gen_r_d_1, feq_gen_r_d_2;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    double r_lg10(real *);
    integer i_nint(real *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    real feq_gen_d_d_, f;
    integer k;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    doublereal dg;
    integer id;
    real al, bl;
    doublereal am;
    integer nd;
    real ar, br, kl;
    doublereal ck, km;
    char cq[8];
    integer nn, it;
    real dx, dz, kr, ql, qr, st, tl, tr, yl, ym, yr;
    doublereal dy, qm, vl, vr, wx, xl, xr, zl, zr;
    char cy[7];
    integer ln1;
    real dbl;
    doublereal fac;
    integer nad;
    real dbr, dkl;
    doublereal dem;
    integer ita;
    real khl, dkr, dtl, dtr;
    doublereal div, sfm, dvm, res, yta;
    extern /* Subroutine */ int feq_gen_var_decimal_d_(real *, char *, ftnlen);
    integer feq_gen_feql_select2_d_, feq_gen_feql_select3_d_, itab;
    real dkhl;
    integer ntab, adrs;
    real zout;
    doublereal elev;
    integer iflag;
    char tabid[16];
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    doublereal sgndv;
    extern /* Subroutine */ int xlkt20_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *);
    extern integer gettbn_(integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__418 = { 0, 0, 0, fmt_2110, 0 };
    static cilist feq_gen_io_d__439 = { 0, 0, 0, fmt_14000, 0 };
    static cilist feq_gen_io_d__440 = { 0, 0, 0, fmt_14100, 0 };
    static cilist feq_gen_io_d__441 = { 0, 0, 0, fmt_14200, 0 };
    static cilist feq_gen_io_d__442 = { 0, 0, 0, fmt_14300, 0 };
    static cilist feq_gen_io_d__443 = { 0, 0, 0, fmt_14400, 0 };
    static cilist feq_gen_io_d__454 = { 0, 0, 0, fmt_2140, 0 };
    static cilist feq_gen_io_d__483 = { 0, 0, 0, fmt_2150, 0 };
    static cilist feq_gen_io_d__484 = { 0, 0, 0, fmt_2130, 0 };
    static cilist feq_gen_io_d__486 = { 0, 0, 0, fmt_2130, 0 };
    static cilist feq_gen_io_d__487 = { 0, 0, 0, fmt_2150, 0 };
    static cilist feq_gen_io_d__489 = { 0, 0, 0, fmt_14000, 0 };
    static cilist feq_gen_io_d__490 = { 0, 0, 0, fmt_14100, 0 };
    static cilist feq_gen_io_d__491 = { 0, 0, 0, fmt_14200, 0 };
    static cilist feq_gen_io_d__492 = { 0, 0, 0, fmt_14300, 0 };
    static cilist feq_gen_io_d__493 = { 0, 0, 0, fmt_14400, 0 };


/*     + + + PURPOSE + + + */
/*     Compute steady-flow water-surface profile in a branch. */
/* SOURCE runinit.for:3447 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE runinit.for:3449 */
/*<       integerdn,eflag,fn,ln,stdout,maxit,uexn,usnb >*/
/* SOURCE runinit.for:3450 */
/*<       realepsb,grav,sfac,yd,zi,dz_for_output >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     USNB   - user branch number */
/*     FN     - first node on the branch */
/*     LN     - last node on the branch */
/*     DN     - downstream user node number */
/*     UEXN   - upstream exterior node */
/*     SFAC   - conversion factor from user stations to internal stations */
/*     GRAV   - value of acceleration due to gravity */
/*     EPSB   - convergence limit for steady flow computations */
/*     YD     - depth at downstream section */
/*     MAXIT  - maximum number of interations */
/*     ZI     - inertia factor */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE runinit.for:3467 */
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
/* INCLUDE runinit.for:3468 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE runinit.for:3469 */
/* SOURCE bnothr.cmn:1 */
/*<        >*/
/* SOURCE bnothr.cmn:6 */
/*<       common/bnothc/bnodid >*/
/* SOURCE bnothr.cmn:8 */
/*<       character*16bnodid(mnbn) >*/
/* SOURCE bnothr.cmn:10 */
/*<        >*/
/* SOURCE bnothr.cmn:13 */
/*<        >*/
/* INCLUDE runinit.for:3470 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE runinit.for:3473 */
/*<       integeradrs,id,iflag,it,ita,itab,k,ln1,nad,nd,nn,ntab >*/
/* SOURCE runinit.for:3474 */
/*<        >*/
/* SOURCE runinit.for:3478 */
/*<       charactercy*7,cq*8,tabid*16 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE runinit.for:3481 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE runinit.for:3484 */
/*<       integergettbn >*/
/* SOURCE runinit.for:3485 */
/*<       characterget_tabid*16 >*/
/* SOURCE runinit.for:3486 */
/*<       externallktab,xlkt20,var_decimal,get_tabid,gettbn >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE runinit.for:3439 */
/*<       integer feql_select2 >*/
/* SOURCE runinit.for:3439 */
/*<       integer feql_select3 >*/
/* SOURCE runinit.for:3489 */
/*<  2110 format(/,' *ERR:94* Downstream depth missing ','for branch',i5) >*/
/* SOURCE runinit.for:3491 */
/*<  2130  >*/
/* SOURCE runinit.for:3493 */
/*<  2140  >*/
/* SOURCE runinit.for:3496 */
/*<  2150 format(1x,i5,5(1pe13.5)) >*/
/* SOURCE runinit.for:3497 */
/*< 14000  >*/
/* SOURCE runinit.for:3499 */
/*< 14100  >*/
/* SOURCE runinit.for:3501 */
/*< 14200  >*/
/* SOURCE runinit.for:3503 */
/*< 14300  >*/
/* SOURCE runinit.for:3505 */
/*< 14400  >*/
/* *********************************************************************** */
/*     Compute the format selection index */
/* SOURCE runinit.for:3509 */
/*<       id=nint(log10(sfac)) >*/
/* L2110: */
/* L2130: */
/* L2140: */
/* L2150: */
/* L14000: */
/* L14100: */
/* L14200: */
/* L14300: */
/* L14400: */
    feq_gen_r_d_1 = r_lg10(sfac);
    id = (feq_output_feq_gen_r_d_1 = static_cast<float>(feq_gen_r_d_1), i_nint(&feq_output_feq_gen_r_d_1));
/* SOURCE runinit.for:3512 */
/*<       yr=yd >*/
    yr = *yd;
/* SOURCE runinit.for:3513 */
/*<       adrs=nsec(ln) >*/
    adrs = bnothr_1.nsec[*ln - 1];
/* SOURCE runinit.for:3514 */
/*<       tabid=get_tabid(gettbn(adrs)) >*/
    feq_gen_i_d_1 = gettbn_(&adrs);
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_1);
    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE runinit.for:3515 */
/*<       xr=xvec(ln) >*/
    xr = bnelem_1.xvec[*ln - 1];
/* SOURCE runinit.for:3516 */
/*<       zr=zvec(ln) >*/
    zr = bnelem_1.zvec[*ln - 1];
/* SOURCE runinit.for:3517 */
/*<       if(yr.le.0)then >*/
    if (yr <= (float)0.) {
/* SOURCE runinit.for:3518 */
/*<       write(stdout,2110)usnb >*/
	feq_gen_io_d__418.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__418);
	do_fio(&feq_gen_c_d_1, (char *)&(*usnb), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE runinit.for:3519 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE runinit.for:3520 */
/*<       return >*/
	return 0;
/* SOURCE runinit.for:3521 */
/*<       endif >*/
    }
/* SOURCE runinit.for:3522 */
/*<       qr=q1(ln) >*/
    qr = bnelem_1.q1[*ln - 1];
/* SOURCE runinit.for:3523 */
/*<       q2(ln)=qr >*/
    bnelem_1.q2[*ln - 1] = qr;
/* SOURCE runinit.for:3524 */
/*<       y1(ln)=yr >*/
    bnelem_1.y1[*ln - 1] = yr;
/* SOURCE runinit.for:3526 */
/*<       callxlkt20(adrs,yr,ar,tr,dtr,kr,dkr,br,dbr) >*/
    xlkt20_(&adrs, &yr, &ar, &tr, &dtr, &kr, &dkr, &br, &dbr);
/* SOURCE runinit.for:3531 */
/*<       y1(ln)=yr >*/
    bnelem_1.y1[*ln - 1] = yr;
/* SOURCE runinit.for:3532 */
/*<       y2(ln)=yr >*/
    bnelem_1.y2[*ln - 1] = yr;
/* SOURCE runinit.for:3533 */
/*<       a1(ln)=ar >*/
    bnelem_1.a1[*ln - 1] = ar;
/* SOURCE runinit.for:3534 */
/*<       a2(ln)=ar >*/
    bnelem_1.a2[*ln - 1] = ar;
/* SOURCE runinit.for:3535 */
/*<       vr=qr/ar >*/
    vr = static_cast<double>(qr) / ar;
/* SOURCE runinit.for:3536 */
/*<       t1(ln)=tr >*/
    bnelem_1.t1[*ln - 1] = tr;
/* SOURCE runinit.for:3537 */
/*<       t2(ln)=tr >*/
    bnelem_1.t2[*ln - 1] = tr;
/* SOURCE runinit.for:3538 */
/*<       k1(ln)=kr >*/
    bnelem_1.k1[*ln - 1] = kr;
/* SOURCE runinit.for:3539 */
/*<       k2(ln)=kr >*/
    bnelem_1.k2[*ln - 1] = kr;
/* SOURCE runinit.for:3540 */
/*<       b1(ln)=br >*/
    bnelem_1.b1[*ln - 1] = br;
/* SOURCE runinit.for:3541 */
/*<       b2(ln)=br >*/
    bnelem_1.b2[*ln - 1] = br;
/* SOURCE runinit.for:3542 */
/*<       elev=yr+zr >*/
    elev = static_cast<double>(yr) + zr;
/* SOURCE runinit.for:3543 */
/*<       it=0 >*/
    it = 0;
/* SOURCE runinit.for:3544 */
/*<       dx=0.0 >*/
    dx = (float)0.;
/* SOURCE runinit.for:3545 */
/*<       dz=0.0 >*/
    dz = (float)0.;
/* SOURCE runinit.for:3546 */
/*<       st=xr/sfac >*/
    st = static_cast<double>(xr) / *sfac;
/* SOURCE runinit.for:3547 */
/*<       f=qr**2*tr/(grav*ar**3) >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = qr;
/* Computing 3rd power */
    feq_gen_r_d_2 = ar;
    f = static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * tr) / (static_cast<double>(*grav) * (static_cast<double>(feq_gen_r_d_2) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)));
/* SOURCE runinit.for:3548 */
/*<       d=0.0 >*/
    feq_gen_d_d_ = (float)0.;
/* SOURCE runinit.for:3549 */
/*<       callvar_decimal(yr,cy) >*/
    feq_gen_var_decimal_d_(&yr, cy, (ftnlen)7);
/* SOURCE runinit.for:3551 */
/*<       callvar_decimal(qr,cq) >*/
    feq_gen_var_decimal_d_(&qr, cq, (ftnlen)8);
/* SOURCE runinit.for:3554 */
/*<       zout=elev+dz_for_output >*/
    zout = static_cast<double>(elev) + *feq_gen_dz_for_output_d_;
/* SOURCE runinit.for:3555 */
/*<       feql_select2=id >*/
    feq_gen_feql_select2_d_ = id;
/* SOURCE runinit.for:3555 */
/*<       if(feql_select2.eq.0)then >*/
    if (feq_gen_feql_select2_d_ == 0) {
/* SOURCE runinit.for:3557 */
/*<       write(stdout,14000)st,it,cy,cq,ar,tr,dz,dx,zout,d,f,tabid >*/
	feq_gen_io_d__439.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__439);
	do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, cy, (ftnlen)7);
	do_fio(&feq_gen_c_d_1, cq, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&ar, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&tr, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&dz, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&dx, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&zout, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_d_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&f, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
	e_wsfe();
/* SOURCE runinit.for:3555 */
/*<       elseif(feql_select2.eq.1)then >*/
    } else if (feq_gen_feql_select2_d_ == 1) {
/* SOURCE runinit.for:3560 */
/*<       write(stdout,14100)st,it,cy,cq,ar,tr,dz,dx,zout,d,f,tabid >*/
	feq_gen_io_d__440.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__440);
	do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, cy, (ftnlen)7);
	do_fio(&feq_gen_c_d_1, cq, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&ar, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&tr, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&dz, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&dx, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&zout, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_d_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&f, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
	e_wsfe();
/* SOURCE runinit.for:3555 */
/*<       elseif(feql_select2.eq.2)then >*/
    } else if (feq_gen_feql_select2_d_ == 2) {
/* SOURCE runinit.for:3563 */
/*<       write(stdout,14200)st,it,cy,cq,ar,tr,dz,dx,zout,d,f,tabid >*/
	feq_gen_io_d__441.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__441);
	do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, cy, (ftnlen)7);
	do_fio(&feq_gen_c_d_1, cq, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&ar, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&tr, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&dz, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&dx, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&zout, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_d_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&f, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
	e_wsfe();
/* SOURCE runinit.for:3555 */
/*<       elseif(feql_select2.eq.3)then >*/
    } else if (feq_gen_feql_select2_d_ == 3) {
/* SOURCE runinit.for:3566 */
/*<       write(stdout,14300)st,it,cy,cq,ar,tr,dz,dx,zout,d,f,tabid >*/
	feq_gen_io_d__442.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__442);
	do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, cy, (ftnlen)7);
	do_fio(&feq_gen_c_d_1, cq, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&ar, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&tr, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&dz, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&dx, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&zout, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_d_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&f, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
	e_wsfe();
/* SOURCE runinit.for:3555 */
/*<       else >*/
    } else {
/* SOURCE runinit.for:3569 */
/*<       write(stdout,14400)st,it,cy,cq,ar,tr,dz,dx,zout,d,f,tabid >*/
	feq_gen_io_d__443.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__443);
	do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, cy, (ftnlen)7);
	do_fio(&feq_gen_c_d_1, cq, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&ar, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&tr, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&dz, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&dx, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&zout, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_d_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&f, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
	e_wsfe();
/* SOURCE runinit.for:3571 */
/*<       endif >*/
    }
/*     SETUP FOR ESTIMATE OF UPSTREAM DEPTH */
/* SOURCE runinit.for:3576 */
/*<       nd=ln >*/
    nd = *ln;
/* SOURCE runinit.for:3577 */
/*<       ln1=ln-1 >*/
    ln1 = *ln - 1;
/*     INTERIOR LOOP FOR BRANCH */
/* SOURCE runinit.for:3581 */
/*<       do150nad=fn,ln1 >*/
    feq_gen_i_d_1 = ln1;
    for (nad = *fn; nad <= feq_gen_i_d_1; ++nad) {
/* SOURCE runinit.for:3582 */
/*<       k=nd >*/
	k = nd;
/* SOURCE runinit.for:3583 */
/*<       nd=nd-1 >*/
	--nd;
/* SOURCE runinit.for:3584 */
/*<       nn=dn-nad+fn-1 >*/
	nn = *dn - nad + *fn - 1;
/* SOURCE runinit.for:3585 */
/*<       adrs=nsec(nd) >*/
	adrs = bnothr_1.nsec[nd - 1];
/* SOURCE runinit.for:3586 */
/*<       tabid=get_tabid(gettbn(adrs)) >*/
	feq_gen_i_d_2 = gettbn_(&adrs);
	feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_2);
	s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE runinit.for:3587 */
/*<       itab=hltab(k) >*/
	itab = bnothr_1.hltab[k - 1];
/* SOURCE runinit.for:3588 */
/*<       xl=xvec(nd) >*/
	xl = bnelem_1.xvec[nd - 1];
/* SOURCE runinit.for:3589 */
/*<       zl=zvec(nd) >*/
	zl = bnelem_1.zvec[nd - 1];
/* SOURCE runinit.for:3590 */
/*<       dx=abs(xl-xr) >*/
	dx = (feq_gen_r_d_1 = static_cast<double>(xl) - xr, dabs(feq_gen_r_d_1));
/* SOURCE runinit.for:3591 */
/*<       dxvec(k)=dx >*/
	bnelem_1.dxvec[k - 1] = dx;
/* SOURCE runinit.for:3592 */
/*<       dz=zr-zl >*/
	dz = static_cast<double>(zr) - zl;
/* SOURCE runinit.for:3593 */
/*<       dzvec(k)=dz >*/
	bnelem_1.dzvec[k - 1] = dz;
/* SOURCE runinit.for:3594 */
/*<       iflag=0 >*/
	iflag = 0;
/*       ESTIMATE DEPTH AT NEXT UPSTREAM NODE */
/* SOURCE runinit.for:3598 */
/*<    60 continue >*/
L60:
/* SOURCE runinit.for:3599 */
/*<       fac=1.0 >*/
	fac = (float)1.;
/* SOURCE runinit.for:3600 */
/*<       if(iflag.eq.1)write(stdout,2140)usnb,nn >*/
	if (iflag == 1) {
	    feq_gen_io_d__454.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__454);
	    do_fio(&feq_gen_c_d_1, (char *)&(*usnb), (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&nn, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
/* SOURCE runinit.for:3601 */
/*<       yl=yr >*/
	yl = yr;
/* SOURCE runinit.for:3602 */
/*<       ql=q1(nd) >*/
	ql = bnelem_1.q1[nd - 1];
/* SOURCE runinit.for:3603 */
/*<       q2(nd)=ql >*/
	bnelem_1.q2[nd - 1] = ql;
/* SOURCE runinit.for:3604 */
/*<       it=1 >*/
	it = 1;
/*         START ITERATIVE LOOP FOR BACKWATER */
/* SOURCE runinit.for:3608 */
/*<    70 continue >*/
L70:
/* SOURCE runinit.for:3609 */
/*<       callxlkt20(adrs,yl,al,tl,dtl,kl,dkl,bl,dbl) >*/
	xlkt20_(&adrs, &yl, &al, &tl, &dtl, &kl, &dkl, &bl, &dbl);
/*           COMPUTE RESIDUAL FOR MOMENTUM EQUATION */
/*           LOOKUP POINT VELOCITY-HEAD LOSS COEF. */
/* SOURCE runinit.for:3618 */
/*<       if(itab.gt.0)then >*/
	if (itab > 0) {
/* SOURCE runinit.for:3619 */
/*<       ym=0.5*(yl+yr) >*/
	    ym = static_cast<double>((static_cast<double>(yl) + yr)) * (float).5;
/* SOURCE runinit.for:3620 */
/*<       calllktab(itab,ym,0,khl,ntab,dkhl) >*/
	    lktab_(&itab, &ym, &feq_gen_c_d_0, &khl, &ntab, &dkhl);
/* SOURCE runinit.for:3623 */
/*<       else >*/
	} else {
/* SOURCE runinit.for:3624 */
/*<       khl=0.0 >*/
	    khl = (float)0.;
/* SOURCE runinit.for:3625 */
/*<       dkhl=0.0 >*/
	    dkhl = (float)0.;
/* SOURCE runinit.for:3626 */
/*<       endif >*/
	}
/* SOURCE runinit.for:3627 */
/*<       vl=ql/al >*/
	vl = static_cast<double>(ql) / al;
/* SOURCE runinit.for:3628 */
/*<       qm=ql+0.5*(qr-ql) >*/
	qm = static_cast<double>(ql) + static_cast<double>((static_cast<double>(qr) - ql)) * (float).5;
/*           SELECT NEW VALUE OF WX. */
/* SOURCE runinit.for:3630 */
/*<       km=0.5*(kl+kr) >*/
	km = static_cast<double>((static_cast<double>(kl) + kr)) * (float).5;
/* SOURCE runinit.for:3631 */
/*<       if(geqopt.ge.1)then >*/
	if (bnothr_1.geqopt >= 1) {
/* SOURCE runinit.for:3632 */
/*<       if(qm.ge.0.0)then >*/
	    if (qm >= (float)0.) {
/*               FLOW IS FROM LEFT TO RIGHT. UPSTREAM END IS ON LEFT. */
/* SOURCE runinit.for:3634 */
/*<       if(dkr*(-(yr-yl)-dz)-km.ge.0.0)then >*/
		if (static_cast<double>(static_cast<double>(dkr) * (static_cast<double>(-(static_cast<double>(yr) - yl)) - dz)) - km >= (float)0.) {
/*                 SHIFT TO UPSTREAM CONVEYANCE. */
/* SOURCE runinit.for:3636 */
/*<       wx=0.4*kl/(dkr*(-(yr-yl)-dz)-0.5*(kr-kl)) >*/
		    wx = static_cast<double>(static_cast<double>(kl) * (float).4) / (static_cast<double>(static_cast<double>(dkr) * (static_cast<double>(-(static_cast<double>(yr) - yl)) - dz)) - static_cast<double>((static_cast<double>(kr) - kl))
			     * (float).5);
/* SOURCE runinit.for:3637 */
/*<       km=kl+wx*(kr-kl) >*/
		    km = static_cast<double>(kl) + static_cast<double>(wx) * (static_cast<double>(kr) - kl);
/* SOURCE runinit.for:3638 */
/*<       else >*/
		} else {
/* SOURCE runinit.for:3639 */
/*<       wx=0.5 >*/
		    wx = (float).5;
/* SOURCE runinit.for:3640 */
/*<       endif >*/
		}
/* SOURCE runinit.for:3641 */
/*<       else >*/
	    } else {
/*               FLOW IS FROM RIGHT TO LEFT. UPSTREAM END IS ON RIGHT. */
/* SOURCE runinit.for:3643 */
/*<       if(dkl*(yr-yl+dz)-km.ge.0.0)then >*/
		if (static_cast<double>(static_cast<double>(dkl) * (static_cast<double>(static_cast<double>(yr) - yl) + dz)) - km >= (float)0.) {
/*                 SHIFT TO UPSTREAM CONVEYANCE */
/* SOURCE runinit.for:3645 */
/*<       wx=1.0 >*/
		    wx = (float)1.;
/* SOURCE runinit.for:3646 */
/*<       km=kr >*/
		    km = kr;
/* SOURCE runinit.for:3647 */
/*<       else >*/
		} else {
/* SOURCE runinit.for:3648 */
/*<       wx=0.5 >*/
		    wx = (float).5;
/* SOURCE runinit.for:3649 */
/*<       endif >*/
		}
/* SOURCE runinit.for:3650 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:3651 */
/*<       wxvec(k)=wx >*/
	    bnelem_1.wxvec[k - 1] = wx;
/* SOURCE runinit.for:3652 */
/*<       else >*/
	} else {
/* SOURCE runinit.for:3653 */
/*<       wx=0.5 >*/
	    wx = (float).5;
/* SOURCE runinit.for:3654 */
/*<       endif >*/
	}
/* SOURCE runinit.for:3655 */
/*<       dvm=vr-vl >*/
	dvm = static_cast<double>(vr) - vl;
/* SOURCE runinit.for:3656 */
/*<       sgndv=1. >*/
	sgndv = (float)1.;
/* SOURCE runinit.for:3657 */
/*<       ck=ka(k) >*/
	ck = bnelem_1.ka[k - 1];
/* SOURCE runinit.for:3658 */
/*<       if(dvm.le.0.0)then >*/
	if (dvm <= (float)0.) {
/* SOURCE runinit.for:3659 */
/*<       sgndv=-1. >*/
	    sgndv = (float)-1.;
/* SOURCE runinit.for:3660 */
/*<       ck=kd(k) >*/
	    ck = bnelem_1.kd[k - 1];
/* SOURCE runinit.for:3661 */
/*<       dvm=abs(dvm) >*/
	    dvm = dabs(dvm);
/* SOURCE runinit.for:3662 */
/*<       endif >*/
	}
/* SOURCE runinit.for:3663 */
/*<       am=al+0.5*(ar-al) >*/
	am = static_cast<double>(al) + static_cast<double>((static_cast<double>(ar) - al)) * (float).5;
/* SOURCE runinit.for:3665 */
/*<       dem=yr-yl+dz >*/
	dem = static_cast<double>(static_cast<double>(yr) - yl) + dz;
/* SOURCE runinit.for:3666 */
/*<       sfm=qm*abs(qm)/km**2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = km;
	sfm = qm * dabs(qm) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE runinit.for:3667 */
/*<       div=zi*br*qr**2/ar+grav*am*(yr+dx*sfm) >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = qr;
	div = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(*zi) * br) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / ar) + static_cast<double>(static_cast<double>(*grav) * am) * (static_cast<double>(yr) + static_cast<double>(dx) * sfm);
/* SOURCE runinit.for:3668 */
/*<        >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = qr;
	res = static_cast<double>(static_cast<double>(static_cast<double>(*zi) * (static_cast<double>(static_cast<double>(static_cast<double>(br) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / ar) - static_cast<double>(static_cast<double>(bl) * ql) * vl)) + static_cast<double>(static_cast<double>(*grav) * am) * (
		static_cast<double>(dem) + static_cast<double>(dx) * sfm)) + static_cast<double>(static_cast<double>(ck) * dvm) * qm + static_cast<double>(static_cast<double>(khl) * (float).5) * qm * dabs(
		qm) / am;
/* SOURCE runinit.for:3670 */
/*<        >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = vl;
/* Computing 2nd power */
	feq_gen_r_d_2 = al;
	dg = static_cast<double>(static_cast<double>(static_cast<double>(*zi) * (static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * (static_cast<double>(static_cast<double>(bl) * tl) - static_cast<double>(al) * dbl))) + static_cast<double>(*grav) * (static_cast<double>(static_cast<double>(static_cast<double>(tl) * (
		float).5) * (static_cast<double>(dem) + static_cast<double>(dx) * sfm)) - static_cast<double>(am) * (static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - wx)) * (float)
		2.) * dx) * sfm) * dkl) / km) + (float)1.))) + static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(ck) * qm) * sgndv) * ql) 
		* tl) / (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2) + static_cast<double>(qm) * (float).25 * dabs(qm) * (static_cast<double>(dkhl) - 
		static_cast<double>(static_cast<double>(khl) * tl) / am) / am;
/* SOURCE runinit.for:3675 */
/*<       if(dg.ge.0.0)then >*/
	if (dg >= (float)0.) {
/*             SEARCH FOR YL WHICH YIELDS DG < 0. */
/* SOURCE runinit.for:3678 */
/*<       yta=yl*1.05 >*/
	    yta = static_cast<double>(yl) * (float)1.05;
/* SOURCE runinit.for:3679 */
/*<       fac=0.5*fac >*/
	    fac *= static_cast<double>((float).5);
/* SOURCE runinit.for:3680 */
/*<       it=it+1 >*/
	    ++it;
/* SOURCE runinit.for:3681 */
/*<       ita=-it >*/
	    ita = -it;
/* SOURCE runinit.for:3682 */
/*<       if(iflag.eq.1)write(stdout,2150)ita,yta,yl,res,dg,div >*/
	    if (iflag == 1) {
		feq_gen_io_d__483.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__483);
		do_fio(&feq_gen_c_d_1, (char *)&ita, (ftnlen)sizeof(integer));
		(feq_output_yta = static_cast<float>(yta), do_fio(&feq_gen_c_d_1, (char *)&feq_output_yta, (ftnlen)sizeof(real)));
		do_fio(&feq_gen_c_d_1, (char *)&yl, (ftnlen)sizeof(real));
		(feq_output_res = static_cast<float>(res), do_fio(&feq_gen_c_d_1, (char *)&feq_output_res, (ftnlen)sizeof(real)));
		(feq_output_dg = static_cast<float>(dg), do_fio(&feq_gen_c_d_1, (char *)&feq_output_dg, (ftnlen)sizeof(real)));
		(feq_output_div = static_cast<float>(div), do_fio(&feq_gen_c_d_1, (char *)&feq_output_div, (ftnlen)sizeof(real)));
		e_wsfe();
	    }
/* SOURCE runinit.for:3684 */
/*<       yl=yta >*/
	    yl = yta;
/* SOURCE runinit.for:3685 */
/*<       if(it.gt.maxit)then >*/
	    if (it > *maxit) {
/* SOURCE runinit.for:3686 */
/*<       write(stdout,2130) >*/
		feq_gen_io_d__484.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__484);
		e_wsfe();
/* SOURCE runinit.for:3687 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE runinit.for:3688 */
/*<       if(iflag.eq.1)return >*/
		if (iflag == 1) {
		    return 0;
		}
/* SOURCE runinit.for:3689 */
/*<       iflag=1 >*/
		iflag = 1;
/* SOURCE runinit.for:3690 */
/*<       goto60 >*/
		goto L60;
/* SOURCE runinit.for:3691 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:3692 */
/*<       goto70 >*/
	    goto L70;
/* SOURCE runinit.for:3693 */
/*<       endif >*/
	}
/*           CORRECT THE DEPTH VALUE */
/* SOURCE runinit.for:3697 */
/*<       dy=fac*res/dg >*/
	dy = static_cast<double>(static_cast<double>(fac) * res) / dg;
/* SOURCE runinit.for:3698 */
/*<       if(abs(res/div).le.epsb.or.abs(dy/yl).le.epsb)goto80 >*/
	if ((feq_gen_r_d_1 = static_cast<double>(res) / div, dabs(feq_gen_r_d_1)) <= *epsb || (feq_gen_r_d_2 = static_cast<double>(dy) / yl, dabs(
		feq_gen_r_d_2)) <= *epsb) {
	    goto L80;
	}
/* SOURCE runinit.for:3699 */
/*<       if(it.gt.maxit)then >*/
	if (it > *maxit) {
/* SOURCE runinit.for:3700 */
/*<       write(stdout,2130) >*/
	    feq_gen_io_d__486.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__486);
	    e_wsfe();
/* SOURCE runinit.for:3701 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE runinit.for:3702 */
/*<       if(iflag.eq.1)return >*/
	    if (iflag == 1) {
		return 0;
	    }
/* SOURCE runinit.for:3703 */
/*<       iflag=1 >*/
	    iflag = 1;
/*             REPEAT RUN WITH DETAILED OUTPUT */
/* SOURCE runinit.for:3707 */
/*<       goto60 >*/
	    goto L60;
/* SOURCE runinit.for:3708 */
/*<       endif >*/
	}
/* SOURCE runinit.for:3710 */
/*<       yta=yl-dy >*/
	yta = static_cast<double>(yl) - dy;
/* SOURCE runinit.for:3711 */
/*<       if(iflag.eq.1)write(stdout,2150)it,yta,yl,res,dg,div >*/
	if (iflag == 1) {
	    feq_gen_io_d__487.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__487);
	    do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	    (feq_output_yta = static_cast<float>(yta), do_fio(&feq_gen_c_d_1, (char *)&feq_output_yta, (ftnlen)sizeof(real)));
	    do_fio(&feq_gen_c_d_1, (char *)&yl, (ftnlen)sizeof(real));
	    (feq_output_res = static_cast<float>(res), do_fio(&feq_gen_c_d_1, (char *)&feq_output_res, (ftnlen)sizeof(real)));
	    (feq_output_dg = static_cast<float>(dg), do_fio(&feq_gen_c_d_1, (char *)&feq_output_dg, (ftnlen)sizeof(real)));
	    (feq_output_div = static_cast<float>(div), do_fio(&feq_gen_c_d_1, (char *)&feq_output_div, (ftnlen)sizeof(real)));
	    e_wsfe();
	}
/* SOURCE runinit.for:3712 */
/*<       if(yta.le.0.)yta=0.5*yl >*/
	if (yta <= (float)0.) {
	    yta = static_cast<double>(yl) * (float).5;
	}
/* SOURCE runinit.for:3713 */
/*<       yl=yta >*/
	yl = yta;
/* SOURCE runinit.for:3714 */
/*<       it=it+1 >*/
	++it;
/* SOURCE runinit.for:3715 */
/*<       goto70 >*/
	goto L70;
/*       CONVERGENCE O.K. */
/*       ASSIGN VALUES TO VECTORS */
/* SOURCE runinit.for:3719 */
/*<    80 continue >*/
L80:
/* SOURCE runinit.for:3720 */
/*<       y1(nd)=yl >*/
	bnelem_1.y1[nd - 1] = yl;
/* SOURCE runinit.for:3721 */
/*<       y2(nd)=yl >*/
	bnelem_1.y2[nd - 1] = yl;
/* SOURCE runinit.for:3722 */
/*<       a1(nd)=al >*/
	bnelem_1.a1[nd - 1] = al;
/* SOURCE runinit.for:3723 */
/*<       a2(nd)=al >*/
	bnelem_1.a2[nd - 1] = al;
/* SOURCE runinit.for:3724 */
/*<       t1(nd)=tl >*/
	bnelem_1.t1[nd - 1] = tl;
/* SOURCE runinit.for:3725 */
/*<       t2(nd)=tl >*/
	bnelem_1.t2[nd - 1] = tl;
/* SOURCE runinit.for:3726 */
/*<       k1(nd)=kl >*/
	bnelem_1.k1[nd - 1] = kl;
/* SOURCE runinit.for:3727 */
/*<       k2(nd)=kl >*/
	bnelem_1.k2[nd - 1] = kl;
/* SOURCE runinit.for:3728 */
/*<       b1(nd)=bl >*/
	bnelem_1.b1[nd - 1] = bl;
/* SOURCE runinit.for:3729 */
/*<       b2(nd)=bl >*/
	bnelem_1.b2[nd - 1] = bl;
/*       TRANSFER VALUES */
/* SOURCE runinit.for:3733 */
/*<       qr=ql >*/
	qr = ql;
/* SOURCE runinit.for:3734 */
/*<       yr=yl >*/
	yr = yl;
/* SOURCE runinit.for:3735 */
/*<       ar=al >*/
	ar = al;
/* SOURCE runinit.for:3736 */
/*<       tr=tl >*/
	tr = tl;
/* SOURCE runinit.for:3737 */
/*<       zr=zl >*/
	zr = zl;
/* SOURCE runinit.for:3738 */
/*<       xr=xl >*/
	xr = xl;
/* SOURCE runinit.for:3739 */
/*<       vr=vl >*/
	vr = vl;
/* SOURCE runinit.for:3740 */
/*<       kr=kl >*/
	kr = kl;
/* SOURCE runinit.for:3741 */
/*<       dkr=dkl >*/
	dkr = dkl;
/* SOURCE runinit.for:3742 */
/*<       br=bl >*/
	br = bl;
/* SOURCE runinit.for:3743 */
/*<       elev=zl+yl >*/
	elev = static_cast<double>(zl) + yl;
/*       OUTPUT */
/* SOURCE runinit.for:3747 */
/*<       st=xl/sfac >*/
	st = static_cast<double>(xl) / *sfac;
/* SOURCE runinit.for:3748 */
/*<       f=ql**2*tl/(grav*al**3) >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = ql;
/* Computing 3rd power */
	feq_gen_r_d_2 = al;
	f = static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * tl) / (static_cast<double>(*grav) * (static_cast<double>(feq_gen_r_d_2) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)));
/* SOURCE runinit.for:3749 */
/*<       callvar_decimal(yl,cy) >*/
	feq_gen_var_decimal_d_(&yl, cy, (ftnlen)7);
/* SOURCE runinit.for:3751 */
/*<       callvar_decimal(ql,cq) >*/
	feq_gen_var_decimal_d_(&ql, cq, (ftnlen)8);
/* SOURCE runinit.for:3753 */
/*<       zout=elev+dz_for_output >*/
	zout = static_cast<double>(elev) + *feq_gen_dz_for_output_d_;
/* SOURCE runinit.for:3754 */
/*<       feql_select3=id >*/
	feq_gen_feql_select3_d_ = id;
/* SOURCE runinit.for:3754 */
/*<       if(feql_select3.eq.0)then >*/
	if (feq_gen_feql_select3_d_ == 0) {
/* SOURCE runinit.for:3756 */
/*<       write(stdout,14000)st,it,cy,cq,al,tl,dz,dx,zout,res,f,tabid >*/
	    feq_gen_io_d__489.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__489);
	    do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, cy, (ftnlen)7);
	    do_fio(&feq_gen_c_d_1, cq, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, (char *)&al, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&tl, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&dz, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&dx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&zout, (ftnlen)sizeof(real));
	    (feq_output_res = static_cast<float>(res), do_fio(&feq_gen_c_d_1, (char *)&feq_output_res, (ftnlen)sizeof(real)));
	    do_fio(&feq_gen_c_d_1, (char *)&f, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
	    e_wsfe();
/* SOURCE runinit.for:3754 */
/*<       elseif(feql_select3.eq.1)then >*/
	} else if (feq_gen_feql_select3_d_ == 1) {
/* SOURCE runinit.for:3759 */
/*<       write(stdout,14100)st,it,cy,cq,al,tl,dz,dx,zout,res,f,tabid >*/
	    feq_gen_io_d__490.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__490);
	    do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, cy, (ftnlen)7);
	    do_fio(&feq_gen_c_d_1, cq, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, (char *)&al, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&tl, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&dz, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&dx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&zout, (ftnlen)sizeof(real));
	    (feq_output_res = static_cast<float>(res), do_fio(&feq_gen_c_d_1, (char *)&feq_output_res, (ftnlen)sizeof(real)));
	    do_fio(&feq_gen_c_d_1, (char *)&f, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
	    e_wsfe();
/* SOURCE runinit.for:3754 */
/*<       elseif(feql_select3.eq.2)then >*/
	} else if (feq_gen_feql_select3_d_ == 2) {
/* SOURCE runinit.for:3762 */
/*<       write(stdout,14200)st,it,cy,cq,al,tl,dz,dx,zout,res,f,tabid >*/
	    feq_gen_io_d__491.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__491);
	    do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, cy, (ftnlen)7);
	    do_fio(&feq_gen_c_d_1, cq, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, (char *)&al, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&tl, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&dz, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&dx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&zout, (ftnlen)sizeof(real));
	    (feq_output_res = static_cast<float>(res), do_fio(&feq_gen_c_d_1, (char *)&feq_output_res, (ftnlen)sizeof(real)));
	    do_fio(&feq_gen_c_d_1, (char *)&f, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
	    e_wsfe();
/* SOURCE runinit.for:3754 */
/*<       elseif(feql_select3.eq.3)then >*/
	} else if (feq_gen_feql_select3_d_ == 3) {
/* SOURCE runinit.for:3765 */
/*<       write(stdout,14300)st,it,cy,cq,al,tl,dz,dx,zout,res,f,tabid >*/
	    feq_gen_io_d__492.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__492);
	    do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, cy, (ftnlen)7);
	    do_fio(&feq_gen_c_d_1, cq, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, (char *)&al, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&tl, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&dz, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&dx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&zout, (ftnlen)sizeof(real));
	    (feq_output_res = static_cast<float>(res), do_fio(&feq_gen_c_d_1, (char *)&feq_output_res, (ftnlen)sizeof(real)));
	    do_fio(&feq_gen_c_d_1, (char *)&f, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
	    e_wsfe();
/* SOURCE runinit.for:3754 */
/*<       else >*/
	} else {
/* SOURCE runinit.for:3768 */
/*<       write(stdout,14400)st,it,cy,cq,al,tl,dz,dx,zout,res,f,tabid >*/
	    feq_gen_io_d__493.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__493);
	    do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, cy, (ftnlen)7);
	    do_fio(&feq_gen_c_d_1, cq, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, (char *)&al, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&tl, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&dz, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&dx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&zout, (ftnlen)sizeof(real));
	    (feq_output_res = static_cast<float>(res), do_fio(&feq_gen_c_d_1, (char *)&feq_output_res, (ftnlen)sizeof(real)));
	    do_fio(&feq_gen_c_d_1, (char *)&f, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
	    e_wsfe();
/* SOURCE runinit.for:3770 */
/*<       endif >*/
	}
/* SOURCE runinit.for:3772 */
/*<   150 continue >*/
/* L150: */
    }
/*     Set the depth in the exterior node at the upstream end of */
/*     this branch. */
/* SOURCE runinit.for:3776 */
/*<       ye1(uexn)=yl >*/
    enelem_1.ye1[*uexn - 1] = yl;
/* SOURCE runinit.for:3778 */
/*<       dxvec(nd)=0. >*/
    bnelem_1.dxvec[nd - 1] = (float)0.;
/* SOURCE runinit.for:3779 */
/*<       dzvec(nd)=0. >*/
    bnelem_1.dzvec[nd - 1] = (float)0.;
/* SOURCE runinit.for:3781 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:3782 */
/*<       end >*/
} /* sfpsbm_ */




/* SOURCE runinit.for:3786 */
/*<       subroutinestexag(nbra,nex,brpt,exnodt) >*/
/* Subroutine */ int stexag_(integer *nbra, integer *nex, integer *feq_storage_brpt, 
	integer *feq_storage_exnodt)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Local variables */
    integer feq_gen_i_d_, j, je, js;
    extern doublereal fmnarg_(integer *), fmxarg_(integer *);

/*     + + + PURPOSE + + + */
/*     Set the extreme argument values.  For a branch this is the */
/*     maximum argument value because the minimum is always zero. */
/*     For a reservoir node there is both the maximum and the minimum. */
/*     For remaining free nodes set the max and the minimum by */
/*     convention. */
/* SOURCE runinit.for:3796 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE runinit.for:3798 */
/*<       integernbra,nex >*/
/* SOURCE runinit.for:3799 */
/*<       integerbrpt(8,nbra),exnodt(9,nex) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NBRA   - number of branches in the model */
/*     NEX    - number of exterior nodes in the model */
/*     BRPT   - branch pointer table.  Values for each branch are: */
/*              ROW       Meaning */
/*              1         upstream user node number */
/*              2         downstream user node number */
/*              3         pointer into branch vector for upstream node */
/*              4         pointer into branch vector for downstream node */
/*              5         upstream exterior node number */
/*              6         downstream exterior node number */
/*              7         pointer to address in EMC for the branch */
/*              8         number of unknowns at a node for the branch */
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
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE runinit.for:3830 */
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
/* INCLUDE runinit.for:3831 */
/* SOURCE bnothr.cmn:1 */
/*<        >*/
/* SOURCE bnothr.cmn:6 */
/*<       common/bnothc/bnodid >*/
/* SOURCE bnothr.cmn:8 */
/*<       character*16bnodid(mnbn) >*/
/* SOURCE bnothr.cmn:10 */
/*<        >*/
/* SOURCE bnothr.cmn:13 */
/*<        >*/
/* INCLUDE runinit.for:3832 */
/* ********************************************************************** */
/* SOURCE enothr.cmn:3 */
/*<        >*/
/* SOURCE enothr.cmn:6 */
/*<       common/enothc/enodid >*/
/* SOURCE enothr.cmn:8 */
/*<       character*16enodid(mnex) >*/
/* SOURCE enothr.cmn:10 */
/*<       integerbdyvec(mnex),resvec(mnex),non_conv_enode(mnex) >*/
/* SOURCE enothr.cmn:12 */
/*<       realencorq(mnex),encory(mnex),enmaxy(mnex),enminy(mnex) >*/
/* ********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE runinit.for:3835 */
/*<       integeri,j,je,js >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE runinit.for:3838 */
/*<       realfmnarg,fmxarg >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE runinit.for:3841 */
/*<       externalfmnarg,fmxarg >*/
/* *********************************************************************** */
/*     FIND THE MAXIMUM VALID DEPTH VALUE FOR NODES ON BRANCHES */
/* SOURCE runinit.for:3845 */
/*<       do200i=1,nbra >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    /* Function Body */
    feq_gen_i_d_1 = *nbra;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:3846 */
/*<       js=brpt(3,i) >*/
	js = brpt[(feq_gen_i_d_ << 3) + 3];
/* SOURCE runinit.for:3847 */
/*<       je=brpt(4,i) >*/
	je = brpt[(feq_gen_i_d_ << 3) + 4];
/* SOURCE runinit.for:3848 */
/*<       do100j=js,je >*/
	feq_gen_i_d_2 = je;
	for (j = js; j <= feq_gen_i_d_2; ++j) {
/* SOURCE runinit.for:3849 */
/*<       bnmaxy(j)=fmxarg(nsec(j)) >*/
	    bnothr_1.bnmaxy[j - 1] = fmxarg_(&bnothr_1.nsec[j - 1]);
/* SOURCE runinit.for:3850 */
/*<   100 continue >*/
/* L100: */
	}
/* SOURCE runinit.for:3851 */
/*<       enmaxy(brpt(5,i))=bnmaxy(js) >*/
	enothr_1.enmaxy[brpt[(feq_gen_i_d_ << 3) + 5] - 1] = bnothr_1.bnmaxy[js - 1];
/* SOURCE runinit.for:3852 */
/*<       enmaxy(brpt(6,i))=bnmaxy(je) >*/
	enothr_1.enmaxy[brpt[(feq_gen_i_d_ << 3) + 6] - 1] = bnothr_1.bnmaxy[je - 1];
/* SOURCE runinit.for:3853 */
/*<       enminy(brpt(5,i))=0.0 >*/
	enothr_1.enminy[brpt[(feq_gen_i_d_ << 3) + 5] - 1] = (float)0.;
/* SOURCE runinit.for:3854 */
/*<       enminy(brpt(6,i))=0.0 >*/
	enothr_1.enminy[brpt[(feq_gen_i_d_ << 3) + 6] - 1] = (float)0.;
/* SOURCE runinit.for:3855 */
/*<   200 continue >*/
/* L200: */
    }
/*     FIND THE MAXIMUM AND MINIMUM VALID  VALUE FOR RESERVOIR NODES AND */
/*     SET NON-RESERVOIR FREE NODES TO LARGE POSITIVE VALUE */
/* SOURCE runinit.for:3860 */
/*<       do300i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:3861 */
/*<       if(exnodt(3,i).eq.-1)then >*/
	if (exnodt[feq_gen_i_d_ * 9 + 3] == -1) {
/*         RESERVOIR NODE */
/* SOURCE runinit.for:3863 */
/*<       enmaxy(i)=fmxarg(exnodt(4,i)) >*/
	    enothr_1.enmaxy[feq_gen_i_d_ - 1] = fmxarg_(&exnodt[feq_gen_i_d_ * 9 + 4]);
/* SOURCE runinit.for:3864 */
/*<       enminy(i)=fmnarg(exnodt(4,i)) >*/
	    enothr_1.enminy[feq_gen_i_d_ - 1] = fmnarg_(&exnodt[feq_gen_i_d_ * 9 + 4]);
/* SOURCE runinit.for:3865 */
/*<       elseif(exnodt(3,i).eq.0)then >*/
	} else if (exnodt[feq_gen_i_d_ * 9 + 3] == 0) {
/*         NON-RESERVOIR FREE NODE. SET TO MAX ELEVATION ON EARTH'S */
/*         SURFACE IN FEET. */
/* SOURCE runinit.for:3868 */
/*<       enmaxy(i)=35000. >*/
	    enothr_1.enmaxy[feq_gen_i_d_ - 1] = (float)3.5e4;
/*         SET THE MINIMUM TO ZERO */
/* SOURCE runinit.for:3871 */
/*<       enminy(i)=0.0 >*/
	    enothr_1.enminy[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE runinit.for:3872 */
/*<       endif >*/
	}
/* SOURCE runinit.for:3873 */
/*<   300 continue >*/
/* L300: */
    }
/* SOURCE runinit.for:3875 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:3876 */
/*<       end >*/
} /* stexag_ */




/* SOURCE runinit.for:3880 */
/*<        >*/
/* Subroutine */ int stint_(integer *tsfdsn, integer *stdout, integer *nbra, 
	integer *nex, integer *feq_storage_brpt, integer *feq_storage_exnodt, integer *eflag, real *
	epsb, real *grav, integer *in, integer *maxit, integer *nbn, integer *
	output, doublereal *jtime, real *sfac, integer *nblk, integer *feq_storage_opblk, 
	integer *bwfdsn, integer *fffdsn, char *diffus, char *underf, integer 
	*ifrz, doublereal *dt, integer *getdsn, integer *putdsn, doublereal *
	ujtime, integer *ept, integer *bnode, real *qeps, real *
	feq_gen_dz_for_output_d_, integer *feq_storage_emc, integer *feq_gen_dtsf_rec_d_, real *wt, real *
	siter, ftnlen diffus_len, ftnlen underf_len)
{
    /* Initialized data */

    static char yes[4+1] = "YES ";
    static char off[4+1] = "OFF ";

    /* System generated locals */
    olist feq_gen_o_d_1;
    cllist feq_gen_cl_d_1;
    inlist feq_gen_ioin_d_1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer f_inqu(inlist *), f_open(olist *), s_rdue(cilist *), do_uio(
	    integer *, char *, ftnlen), e_rdue(), f_clos(cllist *), s_wsle(
	    cilist *), do_lio(integer *, integer *, char *, ftnlen), e_wsle();

    /* Local variables */
    extern /* Subroutine */ int feq_gen_free_unit_d_(integer *, integer *);
    integer feq_gen_record_len_d_;
    extern /* Subroutine */ int feq_gen_bfinit_dss_d_(), feq_gen_set_initial_oper_blk_d_(
	    integer *, integer *, doublereal *, integer *, integer *), chkic_(
	    integer *, integer *, integer *), getic_(integer *, integer *, 
	    char *, integer *, integer *, integer *, doublereal *, integer *, 
	    integer *, integer *, real *, real *, doublereal *, integer *, 
	    ftnlen);
    integer bwrec;
    logical there;
    extern /* Subroutine */ int bwput_(integer *, real *, integer *, integer *
	    , integer *, integer *, integer *, integer *);
    integer ioflag;
    extern /* Subroutine */ int readoc_(), bckwtr_(real *, real *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    doublereal *, real *, integer *, integer *, real *, integer *, 
	    real *, integer *, integer *), bfinit_(doublereal *), opinit_(
	    integer *, integer *), rdinit_(integer *), setsta_(integer *, 
	    integer *, real *, integer *, integer *, integer *), wropen_(
	    integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__501 = { 0, 0, 0, 0, 1 };
    static cilist feq_gen_io_d__503 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__504 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__506 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__507 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__508 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__509 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__510 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__512 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Do static(one per run) initializations. */
/* SOURCE runinit.for:3892 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE runinit.for:3894 */
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
/* SOURCE runinit.for:3897 */
/*<        >*/
/* SOURCE runinit.for:3900 */
/*<       integerbrpt(8,nbra),emc(ept),exnodt(9,nex),opblk(mnblk) >*/
/* SOURCE runinit.for:3902 */
/*<       realepsb,grav,qeps,sfac,siter,wt,dz_for_output >*/
/* SOURCE runinit.for:3903 */
/*<       real*8dt,ujtime,jtime >*/
/* SOURCE runinit.for:3904 */
/*<       characterdiffus*4,underf*4 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     TSFDSN - unit number for the time series file */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     NBRA   - number of branches in the model */
/*     NEX    - number of exterior nodes in the model */
/*     BRPT   - branch pointer table.  Values for each branch are: */
/*              ROW       Meaning */
/*              1         upstream user node number */
/*              2         downstream user node number */
/*              3         pointer into branch vector for upstream node */
/*              4         pointer into branch vector for downstream node */
/*              5         upstream exterior node number */
/*              6         downstream exterior node number */
/*              7         pointer to address in EMC for the branch */
/*              8         number of unknowns at a node for the branch */
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
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     EPSB   - convergence limit for steady flow computations */
/*     GRAV   - value of acceleration due to gravity */
/*     IN     - unit number for the user input file */
/*     MAXIT  - maximum number of iterations at a node for finding */
/*               steady flow profile */
/*     NBN    - total number on nodes on branches in the model */
/*     OUTPUT - output level for diagnostic work */
/*     JTIME   - julian time in days */
/*     SFAC   - conversion factor from user stations to internal stations */
/*     NBLK   - number of operation blocks */
/*     OPBLK  - pointer into the function table storage(FTAB/ITAB) for */
/*               each operation block. */
/*     BWFDSN - unit number for the initial conditions file */
/*     FFFDSN - unit number for output of the flood frequency file */
/*     DIFFUS - indicator if tributary area is present.  YES if so */
/*     UNDERF - underflow flag */
/*     IFRZ   - count of frozen time steps */
/*     DT     - time step in seconds */
/*     GETDSN - unit number for reading initial conditions */
/*     UJTIME - modified julian time for the start of the time period */
/*              of simulation. */
/*     EPT    - current length of EMC(*) */
/*     BNODE  - boundary node number at which to start defining the */
/*               coefficient matrix */

/*     QEPS   - value of flow to prevent zero divide when computing */
/*               relative correction */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     dtsf_rec - record number for the single dtsf file used when DIFFUS='YES' */
/*     WT     - weight factor for approximating time integrals */
/*     SITER  - weighted sum of iterations to convergence */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE runinit.for:3969 */
/* *********************************************************************** */
/* SOURCE rdcom.cmn:2 */
/*<        >*/
/* SOURCE rdcom.cmn:7 */
/*<       common/rdcomc/namin,ts_id_for_file_table >*/
/* SOURCE rdcom.cmn:9 */
/*<       characternamin(mxn_ts_f)*256,ts_id_for_file_table(mxn_ts)*16 >*/
/* SOURCE rdcom.cmn:11 */
/*<       integernum_ts_f,id_knt >*/
/* SOURCE rdcom.cmn:13 */
/*<        >*/
/* SOURCE rdcom.cmn:18 */
/*<       realvalain(mrrbuf),tmpvec(mrrbuf+5),ts_conversion_factor(mxn_ts) >*/
/* SOURCE rdcom.cmn:21 */
/*<        >*/
/* *********************************************************************** */
/* INCLUDE runinit.for:3970 */
/* *********************************************************************** */
/* SOURCE wrcom.cmn:2 */
/*<        >*/
/* SOURCE wrcom.cmn:6 */
/*<       common/wrcomc/namout >*/
/* SOURCE wrcom.cmn:7 */
/*<       common/wrcomd/runquad,oldf,quadfactor >*/
/* SOURCE wrcom.cmn:9 */
/*<       character*256namout(mnfout) >*/
/* SOURCE wrcom.cmn:11 */
/*<       integernfout,dss_out_count,irr_dt >*/
/* SOURCE wrcom.cmn:12 */
/*<        >*/
/* SOURCE wrcom.cmn:17 */
/*<       real*8runquad(mnfout),oldf(mnfout),quadfactor >*/
/* *********************************************************************** */
/* INCLUDE runinit.for:3971 */
/*     NAMES FOR VARIOUS OPTIONAL FILES AND SPECIAL OUTPUT FILE */
/*     HEADINGS */
/* SOURCE namcom.cmn:5 */
/*<       character*7sphead(mnsout,2) >*/
/* SOURCE namcom.cmn:7 */
/*<       character*256bwfnam,fffnam,tsfnam,putnam,getnam >*/
/* SOURCE namcom.cmn:9 */
/*<       common/namcom/bwfnam,fffnam,tsfnam,sphead,putnam,getnam >*/
/* INCLUDE runinit.for:3972 */
/*     Common block for management of time series in FEQ.  Keeps track */
/*     of time series references as well as the places where the */
/*     time-series values are needed. */
/* SOURCE ts_mngt.cmn:5 */
/*<       integernum_ts,num_dest,next_link >*/
/* SOURCE ts_mngt.cmn:7 */
/*<        >*/
/* SOURCE ts_mngt.cmn:11 */
/*<       character*16ts_id(mxn_ts) >*/
/* SOURCE ts_mngt.cmn:13 */
/*<        >*/
/* SOURCE ts_mngt.cmn:16 */
/*<       common/ts_mngt_c/ts_id >*/
/* SOURCE ts_mngt.cmn:18 */
/*<       save/ts_mngt_n/,/ts_mngt_c/ >*/
/*     Definitions: */
/*     TS_ID-  unique label used for refering to a time series that will */
/*             be referenced in FEQ. */
/*     SOURCE_CAT- category of the source of the time series: from table */
/*                 or from a file. */
/*     SOURCE_ADDRESS- "address" of the source.  This will contain the */
/*                  index into the time-series file table for time-series */
/*                  found in files.  For time series found in tables it */
/*                  will be the table number and later the address */
/*                  of the table. */
/*     DEST_CAT- category of the destination: level-pool reservoir rainfall/ */
/*              evaporation or branch evaporation/rainfall, forced bdy. */
/*     DEST_LINK- pointer that allows there to be more than one destination */
/*                from a time-series.  If DEST_LINK(i) is 0, then the */
/*                destination in row i is the last one in the list. */
/*                If DEST_LINK(i) > 0, then the next destination is */
/*                described in row DEST_LINK(i).  We reserve one value for each of */
/*                the MXN_TS time series. Therefore MXN_DEST > MXN_TS if */
/*                a time series is to have more than one destination */
/*     NEXT_LINK- Next open link in the destination overflow area. */
/*     The file handling routines will keep track of the different file */
/*     systems that may be used for the time series. */
/*     + + + SAVED VALUES + + + */
/* SOURCE runinit.for:3975 */
/*<       characteroff*4,yes*4 >*/
/* SOURCE runinit.for:3976 */
/*<       saveoff,yes >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE runinit.for:3979 */
/*<       integerioflag,record_len,bwrec >*/
/* SOURCE runinit.for:3980 */
/*<       logicalthere >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE runinit.for:3983 */
/*<        >*/
/*     + + + DATA INITIALIZATIONS + + + */
/* *********************************************************************** */
/*     SET ERROR HANDLING FOR UNDERFLOW PROBLEMS */
/* SOURCE runinit.for:3987 */
/*<       datayes/'YES'/,off/'OFF'/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> opblk(feq_storage_opblk, 1);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* SOURCE runinit.for:3991 */
/*<       if(underf.ne.off)goto4 >*/
    if (s_cmp(underf, off, (ftnlen)4, (ftnlen)4) != 0) {
	goto L4;
    }
/* SOURCE runinit.for:3992 */
/*<     4 continue >*/
L4:
/*     INITIALIZE ANY INPUT FILES. MUST BE DONE HERE TO AVOID CONFLICT */
/*     IF GETDSN > 0. */
/* SOURCE runinit.for:3998 */
/*<       if(num_ts_f.gt.0.or.num_ts.gt.0)then >*/
    if (rdcom_1.feq_gen_num_ts_f_d_ > 0 || feq_gen_ts_mngt_n_d_1.feq_gen_num_ts_d_ > 0) {
/* SOURCE runinit.for:3999 */
/*<       callrdinit(stdout) >*/
	rdinit_(stdout);
/* SOURCE runinit.for:4001 */
/*<       endif >*/
    }
/* SOURCE runinit.for:4003 */
/*<       if(getdsn.gt.0)then >*/
    if (*getdsn > 0) {
/*       READ THE INITIAL CONDITIONS FROM A FILE. */
/* SOURCE runinit.for:4005 */
/*<        >*/
	getic_(stdout, getdsn, namcom_1.getnam, nbra, nbn, nex, ujtime, nblk, 
		&opblk[1], bnode, wt, siter, dt, &exnodt[10], (ftnlen)256);
/*       CHECK THE INITIAL CONDITION FOR AGREEMENT WITH THE BOTTOM */
/*       PROFILE AND THE STATIONING. */
/* SOURCE runinit.for:4013 */
/*<       callchkic(stdout,nbra,brpt) >*/
	chkic_(stdout, nbra, &brpt[9]);
/* SOURCE runinit.for:4016 */
/*<       callsetsta(stdout,nex,grav,exnodt,ept,emc) >*/
	setsta_(stdout, nex, grav, &exnodt[10], ept, &emc[1]);
/* SOURCE runinit.for:4020 */
/*<       else >*/
    } else {
/*       PERFORM BACKWATER CALCS FOR INITIAL CONDITIONS */
/* SOURCE runinit.for:4023 */
/*<        >*/
	bckwtr_(epsb, grav, in, stdout, maxit, nbra, nbn, nex, output, jtime, 
		sfac, &brpt[9], &emc[1], qeps, ept, feq_gen_dz_for_output_d_, &exnodt[
		10], eflag);
/* SOURCE runinit.for:4030 */
/*<       if(eflag.ne.0)stop'Abnormal stop: errors found.' >*/
	if (*eflag != 0) {
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
	}
/*       SET THE STATES IN EMC WHICH DEPEND ON INITIAL CONDITIONS */
/* SOURCE runinit.for:4035 */
/*<       callsetsta(stdout,nex,grav,exnodt,ept,emc) >*/
	setsta_(stdout, nex, grav, &exnodt[10], ept, &emc[1]);
/* SOURCE runinit.for:4038 */
/*<       endif >*/
    }
/*     Close the user input file */
/* SOURCE runinit.for:4041 */
/*<       callfree_unit(stdout,in) >*/
    feq_gen_free_unit_d_(stdout, in);
/* SOURCE runinit.for:4043 */
/*<       if(nblk.gt.0)then >*/
    if (*nblk > 0) {
/* SOURCE runinit.for:4044 */
/*<       callopinit(nblk,opblk) >*/
	opinit_(nblk, &opblk[1]);
/* SOURCE runinit.for:4045 */
/*<       callset_initial_oper_blk(nblk,opblk,jtime,ept,emc) >*/
	feq_gen_set_initial_oper_blk_d_(nblk, &opblk[1], jtime, ept, &emc[1]);
/* SOURCE runinit.for:4047 */
/*<       endif >*/
    }
/* SOURCE runinit.for:4048 */
/*<       if(diffus.eq.yes)then >*/
    if (s_cmp(diffus, yes, (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE runinit.for:4049 */
/*<       inquire(file=tsfnam,exist=there) >*/
	feq_gen_ioin_d_1.inerr = 0;
	feq_gen_ioin_d_1.infilen = 256;
	feq_gen_ioin_d_1.infile = namcom_1.tsfnam;
	feq_gen_ioin_d_1.inex = &there;
	feq_gen_ioin_d_1.inopen = 0;
	feq_gen_ioin_d_1.innum = 0;
	feq_gen_ioin_d_1.innamed = 0;
	feq_gen_ioin_d_1.inname = 0;
	feq_gen_ioin_d_1.inacc = 0;
	feq_gen_ioin_d_1.inseq = 0;
	feq_gen_ioin_d_1.indir = 0;
	feq_gen_ioin_d_1.infmt = 0;
	feq_gen_ioin_d_1.inform = 0;
	feq_gen_ioin_d_1.inunf = 0;
	feq_gen_ioin_d_1.inrecl = 0;
	feq_gen_ioin_d_1.innrec = 0;
	feq_gen_ioin_d_1.inblank = 0;
	f_inqu(&feq_gen_ioin_d_1);
/* SOURCE runinit.for:4050 */
/*<       if(there)then >*/
	if (there) {
/* SOURCE runinit.for:4051 */
/*<        >*/
	    feq_gen_o_d_1.oerr = 0;
	    feq_gen_o_d_1.ounit = *tsfdsn;
	    feq_gen_o_d_1.ofnmlen = 256;
	    feq_gen_o_d_1.ofnm = namcom_1.tsfnam;
	    feq_gen_o_d_1.orl = 4;
	    feq_gen_o_d_1.osta = const_cast<char*>("OLD");
	    feq_gen_o_d_1.oacc = const_cast<char*>("direct");
	    feq_gen_o_d_1.ofm = const_cast<char*>("UNFORMATTED");
	    feq_gen_o_d_1.oblnk = 0;
	    f_open(&feq_gen_o_d_1);
/* SOURCE runinit.for:4053 */
/*<       dtsf_rec=1 >*/
	    *feq_gen_dtsf_rec_d_ = 1;
/* SOURCE runinit.for:4054 */
/*<       read(tsfdsn,rec=1)record_len >*/
	    feq_gen_io_d__501.ciunit = *tsfdsn;
	    s_rdue(&feq_gen_io_d__501);
	    do_uio(&feq_gen_c_d_1, (char *)&feq_gen_record_len_d_, (ftnlen)sizeof(integer));
	    e_rdue();
/* SOURCE runinit.for:4055 */
/*<       close(tsfdsn) >*/
	    feq_gen_cl_d_1.cerr = 0;
	    feq_gen_cl_d_1.cunit = *tsfdsn;
	    feq_gen_cl_d_1.csta = 0;
	    f_clos(&feq_gen_cl_d_1);
/* SOURCE runinit.for:4056 */
/*<        >*/
	    feq_gen_o_d_1.oerr = 0;
	    feq_gen_o_d_1.ounit = *tsfdsn;
	    feq_gen_o_d_1.ofnmlen = 256;
	    feq_gen_o_d_1.ofnm = namcom_1.tsfnam;
	    feq_gen_o_d_1.orl = feq_gen_record_len_d_;
	    feq_gen_o_d_1.osta = const_cast<char*>("OLD");
	    feq_gen_o_d_1.oacc = const_cast<char*>("direct");
	    feq_gen_o_d_1.ofm = const_cast<char*>("UNFORMATTED");
	    feq_gen_o_d_1.oblnk = 0;
	    f_open(&feq_gen_o_d_1);
/*         update record pointer to point to second record */
/* SOURCE runinit.for:4059 */
/*<       dtsf_rec=dtsf_rec+1 >*/
	    ++(*feq_gen_dtsf_rec_d_);
/* SOURCE runinit.for:4060 */
/*<       else >*/
	} else {
/* SOURCE runinit.for:4061 */
/*<       write(stdout,*)' FILE NAMED:',tsfnam,' NOT FOUND.' >*/
	    feq_gen_io_d__503.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__503);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FILE NAMED:"), (ftnlen)12);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, namcom_1.tsfnam, (ftnlen)256);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NOT FOUND."), (ftnlen)11);
	    e_wsle();
/* SOURCE runinit.for:4062 */
/*<       write(stdout,*)' CHECK SPELLING OF TSF FILE.' >*/
	    feq_gen_io_d__504.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__504);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" CHECK SPELLING OF TSF FILE."), (ftnlen)28);
	    e_wsle();
/* SOURCE runinit.for:4063 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:4064 */
/*<       endif >*/
	}
/* SOURCE runinit.for:4065 */
/*<       if(bwfnam.eq.' ')then >*/
	if (s_cmp(namcom_1.bwfnam, const_cast<char*>(" "), (ftnlen)256, (ftnlen)1) == 0) {
/* SOURCE runinit.for:4066 */
/*<        >*/
	    feq_gen_o_d_1.oerr = 0;
	    feq_gen_o_d_1.ounit = *bwfdsn;
	    feq_gen_o_d_1.ofnmlen = 4;
	    feq_gen_o_d_1.ofnm = const_cast<char*>("BWFD");
	    feq_gen_o_d_1.orl = 8;
	    feq_gen_o_d_1.osta = const_cast<char*>("UNKNOWN");
	    feq_gen_o_d_1.oacc = const_cast<char*>("direct");
	    feq_gen_o_d_1.ofm = const_cast<char*>("UNFORMATTED");
	    feq_gen_o_d_1.oblnk = 0;
	    f_open(&feq_gen_o_d_1);
/* SOURCE runinit.for:4068 */
/*<       else >*/
	} else {
/* SOURCE runinit.for:4069 */
/*<        >*/
	    feq_gen_o_d_1.oerr = 1;
	    feq_gen_o_d_1.ounit = *bwfdsn;
	    feq_gen_o_d_1.ofnmlen = 256;
	    feq_gen_o_d_1.ofnm = namcom_1.bwfnam;
	    feq_gen_o_d_1.orl = 8;
	    feq_gen_o_d_1.osta = const_cast<char*>("UNKNOWN");
	    feq_gen_o_d_1.oacc = const_cast<char*>("direct");
	    feq_gen_o_d_1.ofm = const_cast<char*>("UNFORMATTED");
	    feq_gen_o_d_1.oblnk = 0;
	    ioflag = f_open(&feq_gen_o_d_1);
/* SOURCE runinit.for:4073 */
/*<       if(ioflag.ne.0)then >*/
	    if (ioflag != 0) {
/* SOURCE runinit.for:4074 */
/*<       write(stdout,*)' PROBLEM IN OPENING FILE: ',bwfnam >*/
		feq_gen_io_d__506.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__506);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" PROBLEM IN OPENING FILE: "), (ftnlen)26)
			;
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, namcom_1.bwfnam, (ftnlen)256);
		e_wsle();
/* SOURCE runinit.for:4075 */
/*<       write(stdout,*)' CHECK PATH FOR BACKWATER FILE.' >*/
		feq_gen_io_d__507.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__507);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" CHECK PATH FOR BACKWATER FILE."), (
			ftnlen)31);
		e_wsle();
/* SOURCE runinit.for:4076 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:4077 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:4079 */
/*<       endif >*/
	}
/* SOURCE runinit.for:4080 */
/*<       if(fffdsn.gt.0)then >*/
	if (*fffdsn > 0) {
/* SOURCE runinit.for:4081 */
/*<       if(fffnam.eq.' ')then >*/
	    if (s_cmp(namcom_1.fffnam, const_cast<char*>(" "), (ftnlen)256, (ftnlen)1) == 0) {
/* SOURCE runinit.for:4082 */
/*<       open(fffdsn,file='FFFD',form='FORMATTED',status='NEW') >*/
		feq_gen_o_d_1.oerr = 0;
		feq_gen_o_d_1.ounit = *fffdsn;
		feq_gen_o_d_1.ofnmlen = 4;
		feq_gen_o_d_1.ofnm = const_cast<char*>("FFFD");
		feq_gen_o_d_1.orl = 0;
		feq_gen_o_d_1.osta = const_cast<char*>("NEW");
		feq_gen_o_d_1.oacc = 0;
		feq_gen_o_d_1.ofm = const_cast<char*>("FORMATTED");
		feq_gen_o_d_1.oblnk = 0;
		f_open(&feq_gen_o_d_1);
/* SOURCE runinit.for:4083 */
/*<       else >*/
	    } else {
/* SOURCE runinit.for:4084 */
/*<        >*/
		feq_gen_o_d_1.oerr = 1;
		feq_gen_o_d_1.ounit = *fffdsn;
		feq_gen_o_d_1.ofnmlen = 256;
		feq_gen_o_d_1.ofnm = namcom_1.fffnam;
		feq_gen_o_d_1.orl = 0;
		feq_gen_o_d_1.osta = const_cast<char*>("UNKNOWN");
		feq_gen_o_d_1.oacc = 0;
		feq_gen_o_d_1.ofm = const_cast<char*>("FORMATTED");
		feq_gen_o_d_1.oblnk = 0;
		ioflag = f_open(&feq_gen_o_d_1);
/* SOURCE runinit.for:4087 */
/*<       if(ioflag.ne.0)then >*/
		if (ioflag != 0) {
/* SOURCE runinit.for:4088 */
/*<       write(stdout,*)' PROBLEM IN OPENING FILE: ',fffnam >*/
		    feq_gen_io_d__508.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__508);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" PROBLEM IN OPENING FILE: "), (
			    ftnlen)26);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, namcom_1.fffnam, (ftnlen)256);
		    e_wsle();
/* SOURCE runinit.for:4089 */
/*<       write(stdout,*)' IOFLAG=',ioflag >*/
		    feq_gen_io_d__509.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__509);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" IOFLAG="), (ftnlen)8);
		    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&ioflag, (ftnlen)sizeof(
			    integer));
		    e_wsle();
/* SOURCE runinit.for:4090 */
/*<       write(stdout,*)' CHECK PATH FOR EXTREME VALUE FILE.' >*/
		    feq_gen_io_d__510.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__510);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" CHECK PATH FOR EXTREME VALUE FILE.")
			    , (ftnlen)35);
		    e_wsle();
/* SOURCE runinit.for:4091 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:4092 */
/*<       endif >*/
		}
/* SOURCE runinit.for:4094 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:4095 */
/*<       endif >*/
	}
/* SOURCE runinit.for:4096 */
/*<       callreadoc >*/
	readoc_();
/* SOURCE runinit.for:4097 */
/*<       callbfinit(dt) >*/
	bfinit_(dt);
/* SOURCE runinit.for:4098 */
/*<       elseif(diffus.eq.'DSS')then >*/
    } else if (s_cmp(diffus, const_cast<char*>("DSS"), (ftnlen)4, (ftnlen)3) == 0) {
/*       Initialize the buffer for unit-area runoff intensities when */
/*       a HECDSS is used as the source. */
/* SOURCE runinit.for:4101 */
/*<       callbfinit_dss >*/
	feq_gen_bfinit_dss_d_();
/* SOURCE runinit.for:4102 */
/*<       endif >*/
    }
/*     INITIALIZE ANY OUTPUT FILES */
/* SOURCE runinit.for:4106 */
/*<       if(nfout.gt.0)then >*/
    if (wrcom_1.nfout > 0) {
/* SOURCE runinit.for:4107 */
/*<       callwropen(stdout,nbra,brpt) >*/
	wropen_(stdout, nbra, &brpt[9]);
/* SOURCE runinit.for:4109 */
/*<       endif >*/
    }
/*     SAVE STATE OF THE SYSTEM. */
/* SOURCE runinit.for:4112 */
/*<       if(ifrz.eq.0.and.diffus.eq.yes)then >*/
    if (*ifrz == 0 && s_cmp(diffus, yes, (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE runinit.for:4113 */
/*<       if(getdsn+putdsn==0)then >*/
	if (*getdsn + *putdsn == 0) {
/* SOURCE runinit.for:4114 */
/*<       bwrec=1 >*/
	    bwrec = 1;
/* SOURCE runinit.for:4115 */
/*<       callbwput(bwfdsn,wt,nbra,nbn,nex,nblk,opblk,bwrec) >*/
	    bwput_(bwfdsn, wt, nbra, nbn, nex, nblk, &opblk[1], &bwrec);
/* SOURCE runinit.for:4118 */
/*<       write(stdout,*)' BWF BEING WRITTEN. STINT' >*/
	    feq_gen_io_d__512.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__512);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" BWF BEING WRITTEN. STINT"), (ftnlen)25);
	    e_wsle();
/* SOURCE runinit.for:4119 */
/*<       endif >*/
	}
/* SOURCE runinit.for:4120 */
/*<       endif >*/
    }
/* SOURCE runinit.for:4121 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:4122 */
/*<       end >*/
} /* stint_ */




/* SOURCE runinit.for:4126 */
/*<       subroutinetabrc(stdout) >*/
/* Subroutine */ int tabrc_(integer *stdout)
{
    /* Initialized data */

    static integer cxtype[55] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
	    1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 
	    };

    /* Format strings */
    static char fmt_52[] = "(\002 *BUG:XXX* Internal tab#=\002,i10,\002 EXPE\
CTED IN TABRC BUT \002,i10,\002 FOUND.\002)";
    static char fmt_54[] = "(\002 *ERR:63* X-sect table area relative error \
> .02\002,\002 TabId=\002,a,\002 Depth=\002,f10.4)";
    static char fmt_56[] = "(\002 *WRN:46* Type 3 table integral relative er\
ror > .02\002,/,11x,\002 TABID=\002,a,\002 argument=\002,f12.4,\002.  Comput\
ed integral used.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16], feq_gen_ch_d_3[16], feq_gen_ch_d_4[16];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    doublereal feq_gen_h_d_;
    integer feq_gen_i_d_, j;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer ha, la;
    doublereal al, hh, ar, jl, jr, tl;
    real yl;
    doublereal tr;
    real yr;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer adrs, xoff, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__521 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__524 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__534 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__537 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__538 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__539 = { 0, 0, 0, fmt_56, 0 };


/*     + + + PURPOSE + + + */
/*     Recompute values in tables.  Two cases:  cross section tables */
/*     and tables of type 3 using numerical integration via the trapezoidal */
/*     rule.  In both cases the computed values replace the ones read */
/*     with the tables. */
/*     Recompute all top-width dependent values using double precision */
/*     replacing the values read from the tables.  This forces */
/*     maximum consistency and takes into account the truncation of */
/*     the top width when stored in the table. */
/* SOURCE runinit.for:4140 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE runinit.for:4142 */
/*<       integerstdout >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE runinit.for:4148 */
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
/* INCLUDE runinit.for:4149 */
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
/* INCLUDE runinit.for:4150 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + SAVED VALUES + + + */
/* SOURCE runinit.for:4153 */
/*<       integercxtype(55) >*/
/* SOURCE runinit.for:4154 */
/*<       savecxtype >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE runinit.for:4157 */
/*<       integeradrs,ha,i,j,la,type,xoff >*/
/* SOURCE runinit.for:4158 */
/*<       realyl,yr >*/
/* SOURCE runinit.for:4159 */
/*<       real*8al,ar,h,hh,jl,jr,tl,tr >*/
/*     + + + INTRINSICS + + + */
/* SOURCE runinit.for:4162 */
/*<       intrinsicabs,max >*/
/*     Called program units */
/* SOURCE runinit.for:4165 */
/*<       character*16get_tabid >*/
/* SOURCE runinit.for:4167 */
/*<       externalget_tabid >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE runinit.for:4169 */
/*<       datacxtype/19*0,6*1,30*0/ >*/
/* SOURCE runinit.for:4172 */
/*<    52  >*/
/* L52: */
/* SOURCE runinit.for:4174 */
/*<    54  >*/
/* L54: */
/* SOURCE runinit.for:4176 */
/*<    56  >*/
/* L56: */
/* *********************************************************************** */
/*     SCAN THE TABLE POINTER FOR CROSS SECTION TABLES */
/*     AND TYPE = 3 TABLES. */
/* SOURCE runinit.for:4183 */
/*<       do500i=1,mftnum >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 10002; ++feq_gen_i_d_) {
/* SOURCE runinit.for:4184 */
/*<       adrs=ftpnt(i) >*/
	adrs = ftablea_1.ftpnt[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:4185 */
/*<       if(adrs.gt.0)then >*/
	if (adrs > 0) {
/* SOURCE runinit.for:4186 */
/*<       type=itab(adrs+2) >*/
	    feq_gen_type_d_ = itab[adrs + 2];
/* SOURCE runinit.for:4187 */
/*<       if(cxtype(type).eq.1)then >*/
	    if (cxtype[feq_gen_type_d_ - 1] == 1) {
/* SOURCE runinit.for:4188 */
/*<       xoff=offvec(type) >*/
		xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE runinit.for:4189 */
/*<       if(itab(adrs+1).ne.i)then >*/
		if (itab[adrs + 1] != feq_gen_i_d_) {
/* SOURCE runinit.for:4190 */
/*<       write(stdout,52)i,itab(adrs+1) >*/
		    feq_gen_io_d__521.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__521);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, (char *)itab.lease(adrs + 1).data(), (ftnlen)sizeof(
			    integer));
		    e_wsfe();
/* SOURCE runinit.for:4191 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:4192 */
/*<       endif >*/
		}
/*           FOUND A CROSS SECTION TABLE */
/*           EXTRACT THE CONTROLLING ADDRESSES */
/* SOURCE runinit.for:4196 */
/*<       la=adrs+xtioff >*/
		la = adrs + 32;
/* SOURCE runinit.for:4197 */
/*<       ha=itab(adrs) >*/
		ha = itab[adrs];
/* SOURCE runinit.for:4199 */
/*<       goto(120,121,121,120,121,121)type-19 >*/
		switch (feq_gen_type_d_ - 19) {
		    case 1:  goto L120;
		    case 2:  goto L121;
		    case 3:  goto L121;
		    case 4:  goto L120;
		    case 5:  goto L121;
		    case 6:  goto L121;
		}
/* SOURCE runinit.for:4201 */
/*<       write(stdout,*)' *BUG:XXX INVALID TYPE IN TABRC.' >*/
		feq_gen_io_d__524.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__524);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX INVALID TYPE IN TABRC."), (
			ftnlen)32);
		e_wsle();
/* SOURCE runinit.for:4202 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:4204 */
/*<   120 continue >*/
L120:
/*             TABLES THAT DO NOT CONTAIN THE FIRST MOMENT OF AREA */
/*             GET THE FIRST ENTRIES IN THE TABLE.  THESE WILL BE */
/*             ZERO BUT BE EXPLICIT TO COVER THE GENERAL CASE */
/* SOURCE runinit.for:4210 */
/*<       yl=ftab(la) >*/
		yl = ftab[la];
/* SOURCE runinit.for:4211 */
/*<       tl=ftab(la+1) >*/
		tl = ftab[la + 1];
/* SOURCE runinit.for:4212 */
/*<       al=ftab(la+2) >*/
		al = ftab[la + 2];
/* SOURCE runinit.for:4214 */
/*<       do300j=la+xoff,ha,xoff >*/
		feq_gen_i_d_1 = ha;
		feq_gen_i_d_2 = xoff;
		for (j = la + xoff; feq_gen_i_d_2 < 0 ? j >= feq_gen_i_d_1 : j <= feq_gen_i_d_1; j += 
			feq_gen_i_d_2) {
/* SOURCE runinit.for:4215 */
/*<       yr=ftab(j) >*/
		    yr = ftab[j];
/* SOURCE runinit.for:4216 */
/*<       tr=ftab(j+1) >*/
		    tr = ftab[j + 1];
/* SOURCE runinit.for:4217 */
/*<       h=yr-yl >*/
		    feq_gen_h_d_ = static_cast<double>(yr) - yl;
/* SOURCE runinit.for:4218 */
/*<       hh=0.5*h >*/
		    hh = feq_gen_h_d_ * (float).5;
/* SOURCE runinit.for:4219 */
/*<       ar=al+hh*(tl+tr) >*/
		    ar = al + hh * (tl + tr);
/* SOURCE runinit.for:4221 */
/*<       if(abs(ar-ftab(j+2))/ar.gt.0.02.and.ar.gt.0.1)then >*/
		    if ((feq_gen_d_d_1 = ar - ftab[j + 2], abs(feq_gen_d_d_1)) / ar > (float)
			    .02 && ar > (float).1) {
/* SOURCE runinit.for:4223 */
/*<       write(stdout,54)get_tabid(i),yr >*/
			feq_gen_io_d__534.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__534);
			feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &feq_gen_i_d_);
			s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
			do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
			do_fio(&feq_gen_c_d_1, (char *)&yr, (ftnlen)sizeof(real));
			e_wsfe();
/*                  EFLAG = 1 */
/* SOURCE runinit.for:4225 */
/*<       endif >*/
		    }
/* SOURCE runinit.for:4227 */
/*<       ftab(j+2)=ar >*/
		    ftab[j + 2] = ar;
/* SOURCE runinit.for:4228 */
/*<       yl=yr >*/
		    yl = yr;
/* SOURCE runinit.for:4229 */
/*<       tl=tr >*/
		    tl = tr;
/* SOURCE runinit.for:4230 */
/*<       al=ar >*/
		    al = ar;
/* SOURCE runinit.for:4231 */
/*<   300 continue >*/
/* L300: */
		}
/* SOURCE runinit.for:4233 */
/*<       goto150 >*/
		goto L150;
/* SOURCE runinit.for:4235 */
/*<   121 continue >*/
L121:
/*             TABLES THAT DO CONTAIN THE FIRST MOMENT OF AREA */
/*             GET THE FIRST ENTRIES IN THE TABLE.  THESE WILL BE */
/*             ZERO BUT BE EXPLICIT TO COVER THE GENERAL CASE */
/* SOURCE runinit.for:4241 */
/*<       yl=ftab(la) >*/
		yl = ftab[la];
/* SOURCE runinit.for:4242 */
/*<       tl=ftab(la+1) >*/
		tl = ftab[la + 1];
/* SOURCE runinit.for:4243 */
/*<       al=ftab(la+2) >*/
		al = ftab[la + 2];
/* SOURCE runinit.for:4244 */
/*<       jl=ftab(la+5) >*/
		jl = ftab[la + 5];
/* SOURCE runinit.for:4246 */
/*<       do400j=la+xoff,ha,xoff >*/
		feq_gen_i_d_2 = ha;
		feq_gen_i_d_1 = xoff;
		for (j = la + xoff; feq_gen_i_d_1 < 0 ? j >= feq_gen_i_d_2 : j <= feq_gen_i_d_2; j += 
			feq_gen_i_d_1) {
/* SOURCE runinit.for:4247 */
/*<       yr=ftab(j) >*/
		    yr = ftab[j];
/* SOURCE runinit.for:4248 */
/*<       tr=ftab(j+1) >*/
		    tr = ftab[j + 1];
/* SOURCE runinit.for:4249 */
/*<       h=yr-yl >*/
		    feq_gen_h_d_ = static_cast<double>(yr) - yl;
/* SOURCE runinit.for:4250 */
/*<       hh=0.5*h >*/
		    hh = feq_gen_h_d_ * (float).5;
/* SOURCE runinit.for:4251 */
/*<       ar=al+hh*(tl+tr) >*/
		    ar = al + hh * (tl + tr);
/* SOURCE runinit.for:4252 */
/*<       jr=jl+hh*(ar+al-h*(tr-tl)/6.d0) >*/
		    jr = jl + hh * (ar + al - feq_gen_h_d_ * (tr - tl) / 6.);
/* SOURCE runinit.for:4254 */
/*<       if(abs(ar-ftab(j+2))/ar.gt.0.02.and.ar.gt.0.1)then >*/
		    if ((feq_gen_d_d_1 = ar - ftab[j + 2], abs(feq_gen_d_d_1)) / ar > (float)
			    .02 && ar > (float).1) {
/* SOURCE runinit.for:4256 */
/*<       write(stdout,54)get_tabid(i),yr >*/
			feq_gen_io_d__537.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__537);
			feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &feq_gen_i_d_);
			s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
			do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
			do_fio(&feq_gen_c_d_1, (char *)&yr, (ftnlen)sizeof(real));
			e_wsfe();
/*                  EFLAG = 1 */
/* SOURCE runinit.for:4258 */
/*<       endif >*/
		    }
/* SOURCE runinit.for:4260 */
/*<       ftab(j+2)=ar >*/
		    ftab[j + 2] = ar;
/* SOURCE runinit.for:4261 */
/*<       ftab(j+5)=jr >*/
		    ftab[j + 5] = jr;
/* SOURCE runinit.for:4262 */
/*<       yl=yr >*/
		    yl = yr;
/* SOURCE runinit.for:4263 */
/*<       tl=tr >*/
		    tl = tr;
/* SOURCE runinit.for:4264 */
/*<       al=ar >*/
		    al = ar;
/* SOURCE runinit.for:4265 */
/*<       jl=jr >*/
		    jl = jr;
/* SOURCE runinit.for:4266 */
/*<   400 continue >*/
/* L400: */
		}
/* SOURCE runinit.for:4267 */
/*<       goto150 >*/
		goto L150;
/* SOURCE runinit.for:4269 */
/*<   150 continue >*/
L150:
/* SOURCE runinit.for:4270 */
/*<       elseif(type.eq.3)then >*/
		;
	    } else if (feq_gen_type_d_ == 3) {
/*           RECOMPUTE THE VALUES WHICH DEPEND ON THE DERIVATIVE. */
/* SOURCE runinit.for:4273 */
/*<       if(itab(adrs+1).ne.i)then >*/
		if (itab[adrs + 1] != feq_gen_i_d_) {
/* SOURCE runinit.for:4274 */
/*<       write(stdout,52)get_tabid(i),get_tabid(itab(adrs+1)) >*/
		    feq_gen_io_d__538.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__538);
		    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &feq_gen_i_d_);
		    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
		    feq_gen_get_tabid_d_(feq_gen_ch_d_4, (ftnlen)16, itab.lease(adrs + 1).data());
		    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)16, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)16);
		    e_wsfe();
/* SOURCE runinit.for:4275 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:4276 */
/*<       endif >*/
		}
/* SOURCE runinit.for:4278 */
/*<       la=adrs+off234 >*/
		la = adrs + 22;
/* SOURCE runinit.for:4279 */
/*<       ha=itab(adrs) >*/
		ha = itab[adrs];
/* SOURCE runinit.for:4281 */
/*<       xoff=3 >*/
		xoff = 3;
/*           GET THE FIRST ENTRIES IN THE TABLE.  THE VALUE OF THE */
/*           INTEGRAND AND THE INITIAL VALUE OF THE INTEGRAL ARE */
/*           TAKEN AS CORRECT. */
/* SOURCE runinit.for:4287 */
/*<       yl=ftab(la) >*/
		yl = ftab[la];
/* SOURCE runinit.for:4288 */
/*<       tl=ftab(la+2) >*/
		tl = ftab[la + 2];
/* SOURCE runinit.for:4289 */
/*<       al=ftab(la+1) >*/
		al = ftab[la + 1];
/* SOURCE runinit.for:4291 */
/*<       do410j=la+xoff,ha,xoff >*/
		feq_gen_i_d_1 = ha;
		feq_gen_i_d_2 = xoff;
		for (j = la + xoff; feq_gen_i_d_2 < 0 ? j >= feq_gen_i_d_1 : j <= feq_gen_i_d_1; j += 
			feq_gen_i_d_2) {
/* SOURCE runinit.for:4292 */
/*<       yr=ftab(j) >*/
		    yr = ftab[j];
/* SOURCE runinit.for:4293 */
/*<       tr=ftab(j+2) >*/
		    tr = ftab[j + 2];
/* SOURCE runinit.for:4294 */
/*<       h=yr-yl >*/
		    feq_gen_h_d_ = static_cast<double>(yr) - yl;
/* SOURCE runinit.for:4295 */
/*<       ar=al+.5*h*(tl+tr) >*/
		    ar = al + feq_gen_h_d_ * (float).5 * (tl + tr);
/* SOURCE runinit.for:4297 */
/*<        >*/
/* Computing MAX */
		    feq_gen_d_d_2 = abs(ar);
		    if ((feq_gen_d_d_1 = ar - ftab[j + 1], abs(feq_gen_d_d_1)) / max(feq_gen_d_d_2,.1) > 
			    (float).02 && ar > (float).1 && ftab[j + 1] != (
			    float)0.) {
/* SOURCE runinit.for:4299 */
/*<       write(stdout,56)get_tabid(i),yr >*/
			feq_gen_io_d__539.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__539);
			feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &feq_gen_i_d_);
			s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
			do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
			do_fio(&feq_gen_c_d_1, (char *)&yr, (ftnlen)sizeof(real));
			e_wsfe();
/* SOURCE runinit.for:4300 */
/*<       endif >*/
		    }
/* SOURCE runinit.for:4302 */
/*<       ftab(j+1)=ar >*/
		    ftab[j + 1] = ar;
/* SOURCE runinit.for:4303 */
/*<       yl=yr >*/
		    yl = yr;
/* SOURCE runinit.for:4304 */
/*<       tl=tr >*/
		    tl = tr;
/* SOURCE runinit.for:4305 */
/*<       al=ar >*/
		    al = ar;
/* SOURCE runinit.for:4306 */
/*<   410 continue >*/
/* L410: */
		}
/* SOURCE runinit.for:4307 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:4309 */
/*<       endif >*/
	}
/* SOURCE runinit.for:4310 */
/*<   500 continue >*/
/* L500: */
    }
/* SOURCE runinit.for:4311 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:4312 */
/*<       end >*/
} /* tabrc_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE runinit.for:4316 */
/*<       subroutineadj_convey_in_table(stdout,adrs,kadj) >*/
/* Subroutine */ int feq_gen_adj_convey_in_table_d_(integer *stdout, integer *adrs, 
	real *kadj)
{
    /* Initialized data */

    static integer cxtype[55] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,
	    1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 
	    };

    /* Format strings */
    static char fmt_50[] = "(/,\002 *BUG* Expected TABID= \002,a,\002 to be \
cross section\002,\002 table in ADJ_CONVEY_IN_TABLE.\002)";
    static char fmt_52[] = "(\002  Tabid= \002,a16,\002 has its conveyanc\
e\002,\002 adjusted by factor=\002,f10.3)";
    static char fmt_54[] = "(\002  Tabid= \002,a16,\002 adjusted earlier.  A\
djustment\002,\002 NOT made.  Check for duplicate table use.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    double sqrt(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer j, ha, la;
    real fac;
    extern /* Character */ VOID feq_gen_get_string_from_ft_d_(char *, ftnlen, integer *
	    );
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
    integer doff;
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    char feq_gen_name_d_[16];
    integer xoff, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__552 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__553 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__554 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Adjust the conveyance in the cross-section function table given */
/*     by ITAB */
/* SOURCE runinit.for:4323 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE runinit.for:4325 */
/*<       integerstdout,adrs >*/
/* SOURCE runinit.for:4326 */
/*<       realkadj >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     ADRS     - address of the cross-section function table */
/*     KADJ     - factor on conveyance. */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE runinit.for:4334 */
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
/* INCLUDE runinit.for:4335 */
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
/* INCLUDE runinit.for:4336 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + SAVED VALUES + + + */
/* SOURCE runinit.for:4339 */
/*<       integercxtype(55) >*/
/* SOURCE runinit.for:4340 */
/*<       savecxtype >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE runinit.for:4343 */
/*<       integerdoff,ha,j,la,type,xoff >*/
/* SOURCE runinit.for:4344 */
/*<       realfac >*/
/* SOURCE runinit.for:4345 */
/*<       charactername*16 >*/
/*     Called program units */
/* SOURCE runinit.for:4348 */
/*<       character*16get_string_from_ft >*/
/* SOURCE runinit.for:4350 */
/*<       externalget_string_from_ft >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE runinit.for:4353 */
/*<       datacxtype/19*0,6*1,4*0,6*1,20*0/ >*/
/* SOURCE runinit.for:4356 */
/*<    50  >*/
/* L50: */
/* SOURCE runinit.for:4358 */
/*<    52  >*/
/* L52: */
/* SOURCE runinit.for:4360 */
/*<    54  >*/
/* L54: */
/* *********************************************************************** */
/* SOURCE runinit.for:4363 */
/*<       type=itab(adrs+2) >*/
    feq_gen_type_d_ = itab[(0 + (0 + (*adrs + 2 - 0 << 2))) / 4];
/* SOURCE runinit.for:4364 */
/*<       if(cxtype(type).eq.1)then >*/
    if (cxtype[feq_gen_type_d_ - 1] == 1) {
/*       We have a cross section table.  Note that */
/*       conveyance is always stored at offset 3 at each */
/*       depth level.   We also must have some indicator that a table */
/*       has been adjusted.  It is possible to reuse tables and we */
/*       must allow only one adjustment.  We will use the address of */
/*       the last level accessed  to do this.  This address is set to the */
/*       first level in the table when the table is input or */
/*       is created by interpolation.  If we adjust the conveyance */
/*       in the table, we will set this value to the second level */
/*       in the table.  Thus only tables that have the address to */
/*       the last level accessed point to the first level can */
/*       be adjusted. */
/* SOURCE runinit.for:4378 */
/*<       xoff=offvec(type) >*/
	xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/*       EXTRACT THE CONTROLLING ADDRESSES */
/* SOURCE runinit.for:4381 */
/*<       la=adrs+xtioff >*/
	la = *adrs + 32;
/* SOURCE runinit.for:4382 */
/*<       ha=itab(adrs) >*/
	ha = itab[*adrs];
/* SOURCE runinit.for:4383 */
/*<       doff=itab(adrs+21) >*/
	doff = itab[*adrs + 21];
/* SOURCE runinit.for:4384 */
/*<       if(itab(adrs+3).eq.la)then >*/
	if (itab[*adrs + 3] == la) {
/*         We can adjust this table. */
/* SOURCE runinit.for:4386 */
/*<       fac=sqrt(kadj) >*/
	    fac = sqrt(*kadj);
/* SOURCE runinit.for:4387 */
/*<       do300j=la,ha,xoff >*/
	    feq_gen_i_d_1 = ha;
	    feq_gen_i_d_2 = xoff;
	    for (j = la; feq_gen_i_d_2 < 0 ? j >= feq_gen_i_d_1 : j <= feq_gen_i_d_1; j += feq_gen_i_d_2) {
/* SOURCE runinit.for:4388 */
/*<       ftab(j+3)=fac*ftab(j+3) >*/
		ftab[j + 3] = static_cast<double>(fac) * ftab[j + 3];
/* SOURCE runinit.for:4389 */
/*<       if(doff.gt.0)then >*/
		if (doff > 0) {
/*             adjust the derivative of the sqrt(conveyance) */
/* SOURCE runinit.for:4391 */
/*<       ftab(j+doff)=fac*ftab(j+doff) >*/
		    ftab[j + doff] = static_cast<double>(fac) * ftab[j + doff];
/* SOURCE runinit.for:4392 */
/*<       endif >*/
		}
/* SOURCE runinit.for:4393 */
/*<   300 continue >*/
/* L300: */
	    }
/*         Change the address for last access to the 2nd level */
/* SOURCE runinit.for:4395 */
/*<       itab(adrs+3)=la+xoff >*/
	    itab[*adrs + 3] = la + xoff;
/* SOURCE runinit.for:4396 */
/*<       name=get_string_from_ft(adrs+16) >*/
	    feq_gen_i_d_2 = *adrs + 16;
	    feq_gen_get_string_from_ft_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_2);
	    s_copy(feq_gen_name_d_, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE runinit.for:4397 */
/*<       write(stdout,52)name,kadj >*/
	    feq_gen_io_d__552.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__552);
	    do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&(*kadj), (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE runinit.for:4398 */
/*<       else >*/
	} else {
/* SOURCE runinit.for:4399 */
/*<       name=get_string_from_ft(adrs+16) >*/
	    feq_gen_i_d_2 = *adrs + 16;
	    feq_gen_get_string_from_ft_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_2);
	    s_copy(feq_gen_name_d_, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE runinit.for:4400 */
/*<       write(stdout,54)name >*/
	    feq_gen_io_d__553.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__553);
	    do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)16);
	    e_wsfe();
/* SOURCE runinit.for:4401 */
/*<       endif >*/
	}
/* SOURCE runinit.for:4402 */
/*<       else >*/
    } else {
/* SOURCE runinit.for:4403 */
/*<       name=get_string_from_ft(adrs+16) >*/
	feq_gen_i_d_2 = *adrs + 16;
	feq_gen_get_string_from_ft_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_2);
	s_copy(feq_gen_name_d_, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE runinit.for:4404 */
/*<       write(stdout,50)name >*/
	feq_gen_io_d__554.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__554);
	do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)16);
	e_wsfe();
/* SOURCE runinit.for:4405 */
/*<       stop'Abnormal stop.  Bug found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Bug found."), (ftnlen)26);
/* SOURCE runinit.for:4406 */
/*<       endif >*/
    }
/* SOURCE runinit.for:4408 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:4409 */
/*<       end >*/
} /* adj_convey_in_table__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE runinit.for:4413 */
/*<       subroutineadj_convey(stdout,nbra,nbn,brpt,nsec,kadjvec,eflag) >*/
/* Subroutine */ int feq_gen_adj_convey_d_(integer *stdout, integer *nbra, integer *
	nbn, integer *feq_storage_brpt, integer *feq_storage_nsec, real *feq_storage_kadjvec, integer *eflag)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 Adjusting conveyance in the following ta\
bles:\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();

    /* Local variables */
    integer ib, nd, fn, ln;
    extern /* Subroutine */ int feq_gen_adj_convey_in_table_d_(integer *, integer *, 
	    real *);
    real kadj;
    integer adrs, outflag;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__561 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Scan the branch tables to find requests for adjustment of */
/*     conveyance and adjust the conveyance. */
/* SOURCE runinit.for:4421 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE runinit.for:4423 */
/*<       integereflag,stdout,nbn,nbra >*/
/* SOURCE runinit.for:4424 */
/*<       integerbrpt(8,nbra),nsec(nbn) >*/
/* SOURCE runinit.for:4425 */
/*<       realkadjvec(nbn) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     NBRA   - number of branches in the model */
/*     NBN    - total number on nodes on branches in the model */
/*               function table number */
/*     BRPT   - branch pointer table.  Values for each branch are: */
/*              ROW       Meaning */
/*              1         upstream user node number */
/*              2         downstream user node number */
/*              3         pointer into branch vector for upstream node */
/*              4         pointer into branch vector for downstream node */
/*              5         upstream exterior node number */
/*              6         downstream exterior node number */
/*              7         pointer to address in EMC for the branch */
/*              8         number of unknowns at a node for the branch */
/*     NSEC   - number and also address of cross section table at a node */
/*               on a branch */
/*     KADJVEC - conveyacne adjustment factor. */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE runinit.for:4448 */
/*<       integerfn,ib,adrs,ln,nd,outflag >*/
/* SOURCE runinit.for:4450 */
/*<       realkadj >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE runinit.for:4453 */
/*<    50 format(/,' Adjusting conveyance in the following tables:') >*/
/* *********************************************************************** */
/*     Clear the output flag to signal that the informational heading */
/*     HAS NOT been output. */
/* SOURCE runinit.for:4458 */
/*<       outflag=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<real> kadjvec(feq_storage_kadjvec, 1);

    feq::IndexedPointer<integer> nsec(feq_storage_nsec, 1);

    /* Function Body */
/* L50: */
    outflag = 0;
/* SOURCE runinit.for:4460 */
/*<       do200ib=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (ib = 1; ib <= feq_gen_i_d_1; ++ib) {
/* SOURCE runinit.for:4461 */
/*<       fn=brpt(3,ib) >*/
	fn = brpt[(ib << 3) + 3];
/* SOURCE runinit.for:4462 */
/*<       ln=brpt(4,ib) >*/
	ln = brpt[(ib << 3) + 4];
/* SOURCE runinit.for:4464 */
/*<       do100nd=fn,ln >*/
	feq_gen_i_d_2 = ln;
	for (nd = fn; nd <= feq_gen_i_d_2; ++nd) {
/* SOURCE runinit.for:4465 */
/*<       kadj=kadjvec(nd) >*/
	    kadj = kadjvec[nd];
/* SOURCE runinit.for:4466 */
/*<       if(kadj.ne.1.0)then >*/
	    if (kadj != (float)1.) {
/* SOURCE runinit.for:4467 */
/*<       if(outflag.eq.0)then >*/
		if (outflag == 0) {
/*             Output the heading */
/* SOURCE runinit.for:4469 */
/*<       write(stdout,50) >*/
		    feq_gen_io_d__561.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__561);
		    e_wsfe();
/* SOURCE runinit.for:4470 */
/*<       outflag=1 >*/
		    outflag = 1;
/* SOURCE runinit.for:4471 */
/*<       endif >*/
		}
/*           Adjust the conveyance for the current cross-section */
/*           function table. */
/* SOURCE runinit.for:4474 */
/*<       adrs=nsec(nd) >*/
		adrs = nsec[nd];
/* SOURCE runinit.for:4475 */
/*<       calladj_convey_in_table(stdout,adrs,kadj) >*/
		feq_gen_adj_convey_in_table_d_(stdout, &adrs, &kadj);
/* SOURCE runinit.for:4476 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:4477 */
/*<   100 continue >*/
/* L100: */
	}
/* SOURCE runinit.for:4478 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE runinit.for:4479 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:4480 */
/*<       end >*/
} /* adj_convey__ */




/* SOURCE runinit.for:4484 */
/*<       subroutinewrinit(jtime) >*/
/* Subroutine */ int wrinit_(doublereal *jtime)
{
    /* Format strings */
    static char fmt_1[] = "(\0020*BUG:XXX* INVALID FILE CODE=\002,i5,\002 IN\
 WRINIT.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wdue(cilist *), do_uio(integer *, char *, ftnlen), e_wdue();

    /* Local variables */
    extern /* Subroutine */ int feq_gen_initialize_dssout_jtime_d_(doublereal *);
    integer feq_gen_i_d_;
    extern /* Subroutine */ int feq_gen_initialize_dssout_buffer_d_(integer *, real *);
    real val;
    doublereal sum;
    integer feq_gen_is_sum_good_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__565 = { 0, 0, 0, fmt_1, 0 };
    static cilist feq_gen_io_d__567 = { 0, 0, 0, fmt_1, 0 };
    static cilist feq_gen_io_d__569 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__570 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Write initial record for current time frame(segment). */
/* SOURCE runinit.for:4490 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE runinit.for:4492 */
/*<       real*8jtime >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     JTIME  - current modified julian time in the model */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE runinit.for:4498 */
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
/* INCLUDE runinit.for:4499 */
/* *********************************************************************** */
/* SOURCE wrcom.cmn:2 */
/*<        >*/
/* SOURCE wrcom.cmn:6 */
/*<       common/wrcomc/namout >*/
/* SOURCE wrcom.cmn:7 */
/*<       common/wrcomd/runquad,oldf,quadfactor >*/
/* SOURCE wrcom.cmn:9 */
/*<       character*256namout(mnfout) >*/
/* SOURCE wrcom.cmn:11 */
/*<       integernfout,dss_out_count,irr_dt >*/
/* SOURCE wrcom.cmn:12 */
/*<        >*/
/* SOURCE wrcom.cmn:17 */
/*<       real*8runquad(mnfout),oldf(mnfout),quadfactor >*/
/* *********************************************************************** */
/* INCLUDE runinit.for:4500 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE runinit.for:4501 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE runinit.for:4502 */
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
/*     Create parameters for coding ACTION */
/* SOURCE runinit.for:4506 */
/*<       integerouta,outs,add,sub,yes,no,quad >*/
/* SOURCE runinit.for:4507 */
/*<       parameter(outa=1,outs=2,add=3,sub=4,yes=5,no=6,quad=7) >*/
/* SOURCE runinit.for:4509 */
/*<       integeri,is_sum_good >*/
/* SOURCE runinit.for:4510 */
/*<       realval >*/
/* SOURCE runinit.for:4511 */
/*<       real*8sum >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE runinit.for:4514 */
/*<     1 format('0*BUG:XXX* INVALID FILE CODE=',i5,' IN WRINIT.') >*/
/* *********************************************************************** */
/* SOURCE runinit.for:4516 */
/*<       callinitialize_dssout_jtime(jtime) >*/
/* L1: */
    feq_gen_initialize_dssout_jtime_d_(jtime);
/*     Set sum to no good */
/* SOURCE runinit.for:4519 */
/*<       is_sum_good=no >*/
    feq_gen_is_sum_good_d_ = 6;
/*     Note: We will process elevations as if they can be added and subtracted */
/*     to keep the same pattern for all.  However, the addition and subtraction */
/*     of elevations will not produce much of value.  But who knows there may */
/*     be an application that can be used- such as plotting the elevation */
/*     difference between two points! */
/* SOURCE runinit.for:4526 */
/*<       do500i=1,nfout >*/
    feq_gen_i_d_1 = wrcom_1.nfout;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE runinit.for:4527 */
/*<       if(actout(i).ne.quad)then >*/
	if (wrcom_1.actout[feq_gen_i_d_ - 1] != 7) {
/* SOURCE runinit.for:4528 */
/*<       if(braout(i).gt.0)then >*/
	    if (wrcom_1.braout[feq_gen_i_d_ - 1] > 0) {
/* SOURCE runinit.for:4529 */
/*<       goto(10,20),icdout(i)/2 >*/
		switch (wrcom_1.icdout[feq_gen_i_d_ - 1] / 2) {
		    case 1:  goto L10;
		    case 2:  goto L20;
		}
/* SOURCE runinit.for:4530 */
/*<       write(std6,1)icdout(i) >*/
		feq_gen_io_d__565.ciunit = feq_gen_stdun_com_d_1.std6;
		s_wsfe(&feq_gen_io_d__565);
		do_fio(&feq_gen_c_d_1, (char *)&wrcom_1.icdout[feq_gen_i_d_ - 1], (ftnlen)
			sizeof(integer));
		e_wsfe();
/* SOURCE runinit.for:4531 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:4533 */
/*<    10 continue >*/
L10:
/*             NEW FORM OF POINT VALUE OUTPUT FOR ELEVATION */
/* SOURCE runinit.for:4535 */
/*<       val=y1(nodout(i))+zvec(nodout(i)) >*/
		val = static_cast<double>(bnelem_1.y1[wrcom_1.nodout[feq_gen_i_d_ - 1] - 1]) + 
			bnelem_1.zvec[wrcom_1.nodout[feq_gen_i_d_ - 1] - 1];
/* SOURCE runinit.for:4536 */
/*<       goto490 >*/
		goto L490;
/* SOURCE runinit.for:4537 */
/*<    20 continue >*/
L20:
/*             NEW FORM OF POINT VALUE OUTPUT FOR FLOW RATE */
/* SOURCE runinit.for:4539 */
/*<       val=q1(nodout(i)) >*/
		val = bnelem_1.q1[wrcom_1.nodout[feq_gen_i_d_ - 1] - 1];
/* SOURCE runinit.for:4540 */
/*<       goto490 >*/
		goto L490;
/* SOURCE runinit.for:4541 */
/*<       else >*/
	    } else {
/* SOURCE runinit.for:4542 */
/*<       goto(100,200),icdout(i)/2 >*/
		switch (wrcom_1.icdout[feq_gen_i_d_ - 1] / 2) {
		    case 1:  goto L100;
		    case 2:  goto L200;
		}
/* SOURCE runinit.for:4543 */
/*<       write(std6,1)icdout(i) >*/
		feq_gen_io_d__567.ciunit = feq_gen_stdun_com_d_1.std6;
		s_wsfe(&feq_gen_io_d__567);
		do_fio(&feq_gen_c_d_1, (char *)&wrcom_1.icdout[feq_gen_i_d_ - 1], (ftnlen)
			sizeof(integer));
		e_wsfe();
/* SOURCE runinit.for:4544 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:4545 */
/*<   100 continue >*/
L100:
/*             NEW FORM OF POINT VALUE OUTPUT FOR ELEVATION */
/* SOURCE runinit.for:4548 */
/*<       val=ye1(nodout(i))+ze(nodout(i)) >*/
		val = static_cast<double>(enelem_1.ye1[wrcom_1.nodout[feq_gen_i_d_ - 1] - 1]) + enelem_1.ze[
			wrcom_1.nodout[feq_gen_i_d_ - 1] - 1];
/* SOURCE runinit.for:4549 */
/*<       goto490 >*/
		goto L490;
/* SOURCE runinit.for:4550 */
/*<   200 continue >*/
L200:
/*             NEW FORM OF POINT VALUE OUTPUT FOR FLOW RATE */
/* SOURCE runinit.for:4552 */
/*<       val=qe1(nodout(i)) >*/
		val = enelem_1.qe1[wrcom_1.nodout[feq_gen_i_d_ - 1] - 1];
/* SOURCE runinit.for:4553 */
/*<       goto490 >*/
		goto L490;
/* SOURCE runinit.for:4554 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:4555 */
/*<   490 continue >*/
L490:
/* SOURCE runinit.for:4556 */
/*<       endif >*/
	    ;
	}
/* SOURCE runinit.for:4557 */
/*<       if(unout(i).lt.1000)then >*/
	if (wrcom_1.unout[feq_gen_i_d_ - 1] < 1000) {
/*         Traditional connection file */
/* SOURCE runinit.for:4559 */
/*<       if(actout(i).eq.add.or.actout(i).eq.outa)then >*/
	    if (wrcom_1.actout[feq_gen_i_d_ - 1] == 3 || wrcom_1.actout[feq_gen_i_d_ - 1] == 1) 
		    {
/* SOURCE runinit.for:4560 */
/*<       if(is_sum_good.eq.no)then >*/
		if (feq_gen_is_sum_good_d_ == 6) {
/*             Initialize SUM */
/* SOURCE runinit.for:4562 */
/*<       sum=dble(val) >*/
		    sum = (doublereal) val;
/* SOURCE runinit.for:4563 */
/*<       is_sum_good=yes >*/
		    feq_gen_is_sum_good_d_ = 5;
/* SOURCE runinit.for:4564 */
/*<       else >*/
		} else {
/* SOURCE runinit.for:4565 */
/*<       sum=sum+dble(val) >*/
		    sum += (doublereal) val;
/* SOURCE runinit.for:4566 */
/*<       endif >*/
		}
/* SOURCE runinit.for:4567 */
/*<       elseif(actout(i).eq.sub.or.actout(i).eq.outs)then >*/
	    } else if (wrcom_1.actout[feq_gen_i_d_ - 1] == 4 || wrcom_1.actout[feq_gen_i_d_ - 1]
		     == 2) {
/* SOURCE runinit.for:4568 */
/*<       if(is_sum_good.eq.no)then >*/
		if (feq_gen_is_sum_good_d_ == 6) {
/*             Initialize SUM */
/* SOURCE runinit.for:4570 */
/*<       sum=-dble(val) >*/
		    sum = -((doublereal) val);
/* SOURCE runinit.for:4571 */
/*<       is_sum_good=yes >*/
		    feq_gen_is_sum_good_d_ = 5;
/* SOURCE runinit.for:4572 */
/*<       else >*/
		} else {
/* SOURCE runinit.for:4573 */
/*<       sum=sum-dble(val) >*/
		    sum -= (doublereal) val;
/* SOURCE runinit.for:4574 */
/*<       endif >*/
		}
/* SOURCE runinit.for:4575 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:4576 */
/*<       if(actout(i).eq.outa.or.actout(i).eq.outs)then >*/
	    if (wrcom_1.actout[feq_gen_i_d_ - 1] == 1 || wrcom_1.actout[feq_gen_i_d_ - 1] == 2) 
		    {
/* SOURCE runinit.for:4577 */
/*<       val=sngl(sum) >*/
		val = (real) sum;
/* SOURCE runinit.for:4578 */
/*<       write(unout(i),rec=wr_rec(i))jtime,val >*/
		feq_gen_io_d__569.ciunit = wrcom_1.unout[feq_gen_i_d_ - 1];
		feq_gen_io_d__569.cirec = wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
		s_wdue(&feq_gen_io_d__569);
		do_uio(&feq_gen_c_d_1, (char *)&(*jtime), (ftnlen)sizeof(doublereal));
		do_uio(&feq_gen_c_d_1, (char *)&val, (ftnlen)sizeof(real));
		e_wdue();
/* SOURCE runinit.for:4579 */
/*<       wr_rec(i)=wr_rec(i)+1 >*/
		++wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:4580 */
/*<       is_sum_good=no >*/
		feq_gen_is_sum_good_d_ = 6;
/* SOURCE runinit.for:4581 */
/*<       elseif(actout(i).eq.quad)then >*/
	    } else if (wrcom_1.actout[feq_gen_i_d_ - 1] == 7) {
/*           Clear the running quadrature value */
/* SOURCE runinit.for:4583 */
/*<       runquad(i)=0.d0 >*/
		wrcomd_1.runquad[feq_gen_i_d_ - 1] = 0.;
/*           Save the initial function value */
/* SOURCE runinit.for:4586 */
/*<       oldf(i)=sum >*/
		wrcomd_1.oldf[feq_gen_i_d_ - 1] = sum;
/*           Write the initial value of zero */
/* SOURCE runinit.for:4589 */
/*<       val=0.0 >*/
		val = (float)0.;
/* SOURCE runinit.for:4590 */
/*<       write(unout(i),rec=wr_rec(i))jtime,val >*/
		feq_gen_io_d__570.ciunit = wrcom_1.unout[feq_gen_i_d_ - 1];
		feq_gen_io_d__570.cirec = wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
		s_wdue(&feq_gen_io_d__570);
		do_uio(&feq_gen_c_d_1, (char *)&(*jtime), (ftnlen)sizeof(doublereal));
		do_uio(&feq_gen_c_d_1, (char *)&val, (ftnlen)sizeof(real));
		e_wdue();
/* SOURCE runinit.for:4591 */
/*<       wr_rec(i)=wr_rec(i)+1 >*/
		++wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:4592 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:4593 */
/*<       else >*/
	} else {
/*         Output to a HECDSS dataset */
/* SOURCE runinit.for:4595 */
/*<       callinitialize_dssout_buffer(dss_buffer_column(i),val) >*/
	    feq_gen_initialize_dssout_buffer_d_(&wrcom_1.feq_gen_dss_buffer_column_d_[feq_gen_i_d_ - 1], 
		    &val);
/* SOURCE runinit.for:4596 */
/*<       endif >*/
	}
/* SOURCE runinit.for:4598 */
/*<   500 continue >*/
/* L500: */
    }
/* SOURCE runinit.for:4600 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:4601 */
/*<       end >*/
} /* wrinit_ */




/* SOURCE runinit.for:4605 */
/*<       subroutinewropen(stdout,nbra,brpt) >*/
/* Subroutine */ int wropen_(integer *stdout, integer *nbra, integer *feq_storage_brpt)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:300* Cannot open file named:\002,/,\
5x,a,/,5x,\002 Check path for file used for time-series output.\002)";
    static char fmt_52[] = "(\002 Writing header to PTSF:\002,a)";
    static char fmt_54[] = "(/,\002***BUG*** WROPEN: record count wrong at e\
nd of header\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    char feq_gen_ch_d_1[5];
    icilist feq_gen_ici_d_1;
    olist feq_gen_o_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(), f_open(olist *), s_wsfe(cilist *), do_fio(integer *, 
	    char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wdue(cilist *), do_uio(integer *, char *, ftnlen), e_wdue();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), e_wsfi();

    /* Local variables */
    integer feq_gen_usr_bran_number_d_, feq_gen_i_d_, j, n;
    char s72[72], feq_gen_usr_nodeid_d_[8], what[1];
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);
    integer feq_gen_record_length_d_, ioflag;
    extern integer getusb_(integer *);
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);
    char unused[1];
    shortint feq_gen_file_structure_version_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__571 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__577 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__579 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__582 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__586 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__587 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__588 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__589 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__590 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__591 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__592 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__593 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__594 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__595 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__596 = { 0, 0, 0, fmt_52, 0 };


/*     + + + PURPOSE + + + */
/*     Open the output files and write headers to each. */
/* SOURCE runinit.for:4611 */
/*<       implicitnone >*/
/* SOURCE runinit.for:4612 */
/*<       integernbra,stdout,brpt(8,nbra) >*/
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE runinit.for:4615 */
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
/* INCLUDE runinit.for:4616 */
/* *********************************************************************** */
/* SOURCE wrcom.cmn:2 */
/*<        >*/
/* SOURCE wrcom.cmn:6 */
/*<       common/wrcomc/namout >*/
/* SOURCE wrcom.cmn:7 */
/*<       common/wrcomd/runquad,oldf,quadfactor >*/
/* SOURCE wrcom.cmn:9 */
/*<       character*256namout(mnfout) >*/
/* SOURCE wrcom.cmn:11 */
/*<       integernfout,dss_out_count,irr_dt >*/
/* SOURCE wrcom.cmn:12 */
/*<        >*/
/* SOURCE wrcom.cmn:17 */
/*<       real*8runquad(mnfout),oldf(mnfout),quadfactor >*/
/* *********************************************************************** */
/* INCLUDE runinit.for:4617 */
/*     String that contains a string giving the version and date */
/*     of a run.  Will use to label output files that contain */
/*     text.  Binary file will require another approach! */
/* SOURCE datetime.cmn:5 */
/*<       character*95version_run_date_time_string >*/
/* SOURCE datetime.cmn:7 */
/*<       common/datetime/version_run_date_time_string >*/
/* SOURCE datetime.cmn:9 */
/*<       save/datetime/ >*/
/* INCLUDE runinit.for:4618 */
/*     Track status of a subversion working copy.  May not */
/*     be used but should be:) */
/*     Also use to document the subversion info for the source */
/*     code */
/* SOURCE svn.cmn:6 */
/*<       integersvn_rev,svn_mod >*/
/* SOURCE svn.cmn:8 */
/*<       character*256url,revision >*/
/* SOURCE svn.cmn:10 */
/*<       common/svncom/svn_rev,svn_mod >*/
/* SOURCE svn.cmn:12 */
/*<       common/svncomc/url,revision >*/
/* SOURCE svn.cmn:14 */
/*<       save/svncom/,/svncomc/ >*/
/*     Called routines */
/* SOURCE runinit.for:4621 */
/*<       integergetusb >*/
/* SOURCE runinit.for:4622 */
/*<       charactergetusn*5 >*/
/* SOURCE runinit.for:4624 */
/*<       externalgetusb,getusn >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE runinit.for:4627 */
/*<       integer*2file_structure_version >*/
/* SOURCE runinit.for:4628 */
/*<       integeri,ioflag,j,n,record_length,usr_bran_number >*/
/* SOURCE runinit.for:4629 */
/*<       characterwhat*1,unused*1,usr_nodeid*8,s72*72,c12*12 >*/
/*     ******************************FORMATS***************************** */
/* SOURCE runinit.for:4605 */
/*<       integer feq_len_trim >*/
/* SOURCE runinit.for:4605 */
/*<       external feq_len_trim >*/
/* SOURCE runinit.for:4631 */
/*<    50  >*/
/* SOURCE runinit.for:4633 */
/*<    52 format(' Writing header to PTSF:',a) >*/
/* SOURCE runinit.for:4634 */
/*<    54 format(/,'***BUG*** WROPEN: record count wrong at end of header') >*/
/* *********************************************************************** */
/*     The standard header consists of the following as of version 10.40 */
/*     December 2006: */
/*     Note: Fortran counts records from 1 and also character positions */
/*           from 1.  We do the same here. */

/*     Record     byte   Date            Contents */
/*       #       range   type */
/*     ------    -----  -----    ---------------------------------------------- */
/*       1        1:4   I*4      Record length. Currently 12 bytes */
/*                5:6   I*2      File structure version */
/*                7:7   C*1      Z-elevation vs. time. Q-flow vs. time */
/*                8:8   C*1      Unused-currently set to a blank (space) */
/*                9:12  I*4      Record number of the first time series point */
/*                               in the file. */
/*       2        1:4   I*4      User branch number: if zero denotes that */
/*                               user node id is an exterior node. */
/*                5:12  C*8      User node id: if user branch number > 0 */
/*                                contains user node number on a branch, */
/*                                else contains the exterior node id string */
/*                                Unnnn, Dnnnn, or Fnnnn, where the number */
/*                                of digits may range from 1 through 4. */
/*       3:8      1:12  C*12      Up to 72 characters for the file name. */
/*                                No path info is stored.  If the name is */
/*                                shorter, blanks are appended at the end. */
/*                                If the name is longer, it is truncated! */
/*        9       1:12  C*12      Name of program creating the file */

/*       10       1:12  C*12      Version number/id of creating program */

/*       11       1:12  C*12      Date string for the version of the creating program */

/*       12       1:2   C*12      Date string for the run of the program creating the file */

/*       13       1:12  C*12      hh.mm.ss.ttt  Time of run to nearest millisecond! */
/*                                hh - 24-hour clock value of hour */
/*                                mm - minute */
/*                                ss - seconds */
/*                                ttt - millisconds. */

/*       14      1:12   c*12      Revision number of source code for FEQ */
/*       15      1:4    I*4       Revision number for working files */
/*               5:8    i*4       ==1 local working files are modified */
/*                                ==0 local working files are fully committed to repository */
/*               9:12   c*4       'work' */
/* SOURCE runinit.for:4680 */
/*<       write(stdout,*)' ' >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
    feq_gen_io_d__571.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__571);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE runinit.for:4681 */
/*<       record_length=12 >*/
    feq_gen_record_length_d_ = 12;
/* SOURCE runinit.for:4682 */
/*<       file_structure_version=1 >*/
    feq_gen_file_structure_version_d_ = 1;
/* SOURCE runinit.for:4683 */
/*<       unused=' ' >*/
    *(unsigned char *)unused = ' ';
/* SOURCE runinit.for:4684 */
/*<       do500i=1,nfout >*/
    feq_gen_i_d_1 = wrcom_1.nfout;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*       Open each file and create the header record for it. */
/* SOURCE runinit.for:4686 */
/*<       if(unout(i).lt.1000.and.unout(i).gt.0)then >*/
	if (wrcom_1.unout[feq_gen_i_d_ - 1] < 1000 && wrcom_1.unout[feq_gen_i_d_ - 1] > 0) {
/* SOURCE runinit.for:4687 */
/*<        >*/
	    feq_gen_o_d_1.oerr = 1;
	    feq_gen_o_d_1.ounit = wrcom_1.unout[feq_gen_i_d_ - 1];
	    feq_gen_o_d_1.ofnmlen = 256;
	    feq_gen_o_d_1.ofnm = wrcomc_1.namout + (feq_gen_i_d_ - 1 << 8);
	    feq_gen_o_d_1.orl = feq_gen_record_length_d_;
	    feq_gen_o_d_1.osta = const_cast<char*>("UNKNOWN");
	    feq_gen_o_d_1.oacc = const_cast<char*>("direct");
	    feq_gen_o_d_1.ofm = const_cast<char*>("UNFORMATTED");
	    feq_gen_o_d_1.oblnk = 0;
	    ioflag = f_open(&feq_gen_o_d_1);
/* SOURCE runinit.for:4690 */
/*<       if(ioflag.ne.0)then >*/
	    if (ioflag != 0) {
/* SOURCE runinit.for:4691 */
/*<       write(stdout,50)namout(i) >*/
		feq_gen_io_d__577.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__577);
		do_fio(&feq_gen_c_d_1, wrcomc_1.namout + (feq_gen_i_d_ - 1 << 8), (ftnlen)256);
		e_wsfe();
/* SOURCE runinit.for:4692 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE runinit.for:4693 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:4694 */
/*<       if(icdout(i)==2)then >*/
	    if (wrcom_1.icdout[feq_gen_i_d_ - 1] == 2) {
/* SOURCE runinit.for:4695 */
/*<       what='Z' >*/
		*(unsigned char *)what = 'Z';
/* SOURCE runinit.for:4696 */
/*<       else >*/
	    } else {
/* SOURCE runinit.for:4697 */
/*<       what='Q' >*/
		*(unsigned char *)what = 'Q';
/* SOURCE runinit.for:4698 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:4699 */
/*<        >*/
	    feq_gen_io_d__579.ciunit = wrcom_1.unout[feq_gen_i_d_ - 1];
	    feq_gen_io_d__579.cirec = wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
	    s_wdue(&feq_gen_io_d__579);
	    do_uio(&feq_gen_c_d_1, (char *)&feq_gen_record_length_d_, (ftnlen)sizeof(integer));
	    do_uio(&feq_gen_c_d_1, (char *)&feq_gen_file_structure_version_d_, (ftnlen)sizeof(
		    shortint));
	    do_uio(&feq_gen_c_d_1, what, (ftnlen)1);
	    do_uio(&feq_gen_c_d_1, unused, (ftnlen)1);
	    do_uio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_30, (ftnlen)sizeof(integer));
	    e_wdue();
/*         Point to the next open record for writing time-series data. */
/* SOURCE runinit.for:4704 */
/*<       wr_rec(i)=wr_rec(i)+1 >*/
	    ++wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
/*         Now set the details used to describe the data to the */
/*         user during review of the results. */
/* SOURCE runinit.for:4708 */
/*<       usr_bran_number=getusb(braout(i)) >*/
	    feq_gen_usr_bran_number_d_ = getusb_(&wrcom_1.braout[feq_gen_i_d_ - 1]);
/* SOURCE runinit.for:4709 */
/*<       if(usr_bran_number==0)then >*/
	    if (feq_gen_usr_bran_number_d_ == 0) {
/*           This is an exterior node id */
/* SOURCE runinit.for:4711 */
/*<       usr_nodeid=getusn(nodout(i)) >*/
		getusn_(feq_gen_ch_d_1, (ftnlen)5, &wrcom_1.nodout[feq_gen_i_d_ - 1]);
		s_copy(feq_gen_usr_nodeid_d_, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)5);
/* SOURCE runinit.for:4712 */
/*<       else >*/
	    } else {
/*           This is a node number on a branch.  Make a char string. */
/* SOURCE runinit.for:4714 */
/*<        >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 8;
		feq_gen_ici_d_1.iciunit = feq_gen_usr_nodeid_d_;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(i8)");
		s_wsfi(&feq_gen_ici_d_1);
		feq_gen_i_d_2 = wrcom_1.nodout[feq_gen_i_d_ - 1] + brpt[(wrcom_1.braout[feq_gen_i_d_ - 1]
			 << 3) + 1] - brpt[(wrcom_1.braout[feq_gen_i_d_ - 1] << 3) + 3]
			;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_2, (ftnlen)sizeof(integer));
		e_wsfi();
/* SOURCE runinit.for:4716 */
/*<       endif >*/
	    }
/* SOURCE runinit.for:4718 */
/*<       write(unout(i),rec=wr_rec(i))usr_bran_number,usr_nodeid >*/
	    feq_gen_io_d__582.ciunit = wrcom_1.unout[feq_gen_i_d_ - 1];
	    feq_gen_io_d__582.cirec = wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
	    s_wdue(&feq_gen_io_d__582);
	    do_uio(&feq_gen_c_d_1, (char *)&feq_gen_usr_bran_number_d_, (ftnlen)sizeof(integer))
		    ;
	    do_uio(&feq_gen_c_d_1, feq_gen_usr_nodeid_d_, (ftnlen)8);
	    e_wdue();
/* SOURCE runinit.for:4719 */
/*<       wr_rec(i)=wr_rec(i)+1 >*/
	    ++wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
/*         Find the last path name divider (/ or \) in the name for the */
/*         file. */
/* SOURCE runinit.for:4723 */
/*<       n=feq_len_trim(namout(i)) >*/
	    n = feq_gen_feq_len_trim_d_(wrcomc_1.namout + (feq_gen_i_d_ - 1 << 8), (ftnlen)256);
/* SOURCE runinit.for:4724 */
/*<       doj=n-1,1,-1 >*/
	    for (j = n - 1; j >= 1; --j) {
/* SOURCE runinit.for:4725 */
/*<       if(namout(i)(j:j)=='/'.or.namout(i)(j:j)=='\')then >*/
		if (*(unsigned char *)&wrcomc_1.namout[(feq_gen_i_d_ - 1 << 8) + (j - 
			1)] == '/' || *(unsigned char *)&wrcomc_1.namout[(feq_gen_i_d_ 
			- 1 << 8) + (j - 1)] == '\\') {
/* SOURCE runinit.for:4727 */
/*<       goto98998 >*/
		    goto L98998;
/* SOURCE runinit.for:4728 */
/*<       endif >*/
		}
/* SOURCE runinit.for:4729 */
/*<       enddo >*/
	    }
/* SOURCE runinit.for:4729 */
/*< 98998 continue >*/
L98998:
/*         Drop through is valid.  It means that no part of the path */
/*         name was given.  The name beyond 72 chars in length is */
/*         discarded.  User has to be terse in selecting names! */
/* SOURCE runinit.for:4733 */
/*<       s72=namout(i)(j+1:n) >*/
	    feq_gen_i_d_2 = j;
	    s_copy(s72, wrcomc_1.namout + ((feq_gen_i_d_ - 1 << 8) + feq_gen_i_d_2), (ftnlen)72,
		     n - feq_gen_i_d_2);
/* SOURCE runinit.for:4734 */
/*<       doj=0,5 >*/
	    for (j = 0; j <= 5; ++j) {
/* SOURCE runinit.for:4735 */
/*<       write(unout(i),rec=wr_rec(i))s72(j*12+1:12*(j+1)) >*/
		feq_gen_io_d__586.ciunit = wrcom_1.unout[feq_gen_i_d_ - 1];
		feq_gen_io_d__586.cirec = wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
		s_wdue(&feq_gen_io_d__586);
		feq_gen_i_d_2 = j * 12;
		do_uio(&feq_gen_c_d_1, s72 + feq_gen_i_d_2, (j + 1) * 12 - feq_gen_i_d_2);
		e_wdue();
/* SOURCE runinit.for:4736 */
/*<       wr_rec(i)=wr_rec(i)+1 >*/
		++wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:4737 */
/*<       enddo >*/
	    }
/* SOURCE runinit.for:4739 */
/*<       write(unout(i),rec=wr_rec(i))'Feq','         ' >*/
	    feq_gen_io_d__587.ciunit = wrcom_1.unout[feq_gen_i_d_ - 1];
	    feq_gen_io_d__587.cirec = wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
	    s_wdue(&feq_gen_io_d__587);
	    do_uio(&feq_gen_c_d_1, const_cast<char*>("Feq"), (ftnlen)3);
	    do_uio(&feq_gen_c_d_1, const_cast<char*>("         "), (ftnlen)9);
	    e_wdue();
/* SOURCE runinit.for:4740 */
/*<       wr_rec(i)=wr_rec(i)+1 >*/
	    ++wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
/*         Parse the version/run date/time string and store parts */
/*         in the header to identify the version, version date, */
/*         and the date/time of the run used to create this */
/*         file. Store the version number */
/* SOURCE runinit.for:4746 */
/*<        >*/
	    feq_gen_io_d__588.ciunit = wrcom_1.unout[feq_gen_i_d_ - 1];
	    feq_gen_io_d__588.cirec = wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
	    s_wdue(&feq_gen_io_d__588);
	    do_uio(&feq_gen_c_d_1, datetime_1.feq_gen_version_run_date_time_string_d_ + 9, (
		    ftnlen)7);
	    do_uio(&feq_gen_c_d_1, const_cast<char*>("     "), (ftnlen)5);
	    e_wdue();
/*          read(unout(i),rec=wr_rec(i)) c12 */
/*          write(stdout,*) 'In WROPEN: c12a=',c12,'rec=',wr_rec(i) */
/*         store the date of the version */
/* SOURCE runinit.for:4751 */
/*<       wr_rec(i)=wr_rec(i)+1 >*/
	    ++wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:4752 */
/*<        >*/
	    feq_gen_io_d__589.ciunit = wrcom_1.unout[feq_gen_i_d_ - 1];
	    feq_gen_io_d__589.cirec = wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
	    s_wdue(&feq_gen_io_d__589);
	    do_uio(&feq_gen_c_d_1, datetime_1.feq_gen_version_run_date_time_string_d_ + 31, (
		    ftnlen)6);
	    do_uio(&feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	    do_uio(&feq_gen_c_d_1, datetime_1.feq_gen_version_run_date_time_string_d_ + 43, (
		    ftnlen)4);
	    do_uio(&feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	    e_wdue();
/*          read(unout(i),rec=wr_rec(i)) c12 */
/*          write(stdout,*) 'In WROPEN: c12b=',c12,'rec=',wr_rec(i) */
/* SOURCE runinit.for:4757 */
/*<       wr_rec(i)=wr_rec(i)+1 >*/
	    ++wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
/*         store the date of the run */
/* SOURCE runinit.for:4759 */
/*<        >*/
	    feq_gen_io_d__590.ciunit = wrcom_1.unout[feq_gen_i_d_ - 1];
	    feq_gen_io_d__590.cirec = wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
	    s_wdue(&feq_gen_io_d__590);
	    do_uio(&feq_gen_c_d_1, datetime_1.feq_gen_version_run_date_time_string_d_ + 71, (
		    ftnlen)10);
	    do_uio(&feq_gen_c_d_1, const_cast<char*>("  "), (ftnlen)2);
	    e_wdue();
/*          read(unout(i),rec=wr_rec(i)) c12 */
/*          write(stdout,*) 'In WROPEN: c12c=',c12,'rec=',wr_rec(i) */
/*         store the time of the run */
/* SOURCE runinit.for:4764 */
/*<       wr_rec(i)=wr_rec(i)+1 >*/
	    ++wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:4765 */
/*<       write(unout(i),rec=wr_rec(i))version_run_date_time_string(84:95) >*/
	    feq_gen_io_d__591.ciunit = wrcom_1.unout[feq_gen_i_d_ - 1];
	    feq_gen_io_d__591.cirec = wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
	    s_wdue(&feq_gen_io_d__591);
	    do_uio(&feq_gen_c_d_1, datetime_1.feq_gen_version_run_date_time_string_d_ + 83, (
		    ftnlen)12);
	    e_wdue();
/*          read(unout(i),rec=wr_rec(i)) c12 */
/*          write(stdout,*) 'In WROPEN: c12d=',c12,'rec=',wr_rec(i) */
/* SOURCE runinit.for:4769 */
/*<       wr_rec(i)=wr_rec(i)+1 >*/
	    ++wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:4770 */
/*<       write(unout(i),rec=wr_rec(i))revision(1:12) >*/
	    feq_gen_io_d__592.ciunit = wrcom_1.unout[feq_gen_i_d_ - 1];
	    feq_gen_io_d__592.cirec = wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
	    s_wdue(&feq_gen_io_d__592);
	    do_uio(&feq_gen_c_d_1, svncomc_1.revision, (ftnlen)12);
	    e_wdue();
/* SOURCE runinit.for:4772 */
/*<       wr_rec(i)=wr_rec(i)+1 >*/
	    ++wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:4773 */
/*<       write(unout(i),rec=wr_rec(i))svn_rev,svn_mod,'work' >*/
	    feq_gen_io_d__593.ciunit = wrcom_1.unout[feq_gen_i_d_ - 1];
	    feq_gen_io_d__593.cirec = wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
	    s_wdue(&feq_gen_io_d__593);
	    do_uio(&feq_gen_c_d_1, (char *)&svncom_1.feq_gen_svn_rev_d_, (ftnlen)sizeof(integer)
		    );
	    do_uio(&feq_gen_c_d_1, (char *)&svncom_1.feq_gen_svn_mod_d_, (ftnlen)sizeof(integer)
		    );
	    do_uio(&feq_gen_c_d_1, const_cast<char*>("work"), (ftnlen)4);
	    e_wdue();
/* SOURCE runinit.for:4775 */
/*<       wr_rec(i)=wr_rec(i)+1 >*/
	    ++wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
/* SOURCE runinit.for:4777 */
/*<       if(wr_rec(i)/=dptsf_rec_at_lkup_tab_start)then >*/
	    if (wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1] != 16) {
/* SOURCE runinit.for:4778 */
/*<       write(stdout,54)namout(i) >*/
		feq_gen_io_d__594.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__594);
		do_fio(&feq_gen_c_d_1, wrcomc_1.namout + (feq_gen_i_d_ - 1 << 8), (ftnlen)256);
		e_wsfe();
/* SOURCE runinit.for:4779 */
/*<       stop'Abnormal stop: bug found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: bug found."), (ftnlen)25);
/* SOURCE runinit.for:4780 */
/*<       endif >*/
	    }
/*         Fill missing records with blanks */
/* SOURCE runinit.for:4783 */
/*<       doj=wr_rec(i),dptsf_rec_at_frst_ts_pnt-1 >*/
	    for (j = wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1]; j <= 29; ++j) {
/* SOURCE runinit.for:4784 */
/*<       write(unout(i),rec=j)'            ' >*/
		feq_gen_io_d__595.ciunit = wrcom_1.unout[feq_gen_i_d_ - 1];
		feq_gen_io_d__595.cirec = j;
		s_wdue(&feq_gen_io_d__595);
		do_uio(&feq_gen_c_d_1, const_cast<char*>("            "), (ftnlen)12);
		e_wdue();
/* SOURCE runinit.for:4785 */
/*<       enddo >*/
	    }
/*         Update pointer to the record for the first time-series value */
/* SOURCE runinit.for:4788 */
/*<       wr_rec(i)=dptsf_rec_at_frst_ts_pnt >*/
	    wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1] = 30;
/*         Tell the user about the successful open. */
/* SOURCE runinit.for:4792 */
/*<       write(stdout,52)namout(i) >*/
	    feq_gen_io_d__596.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__596);
	    do_fio(&feq_gen_c_d_1, wrcomc_1.namout + (feq_gen_i_d_ - 1 << 8), (ftnlen)256);
	    e_wsfe();
/* SOURCE runinit.for:4793 */
/*<       endif >*/
	}
/* SOURCE runinit.for:4794 */
/*<   500 continue >*/
/* L500: */
    }
/* SOURCE runinit.for:4796 */
/*<       return >*/
    return 0;
/* SOURCE runinit.for:4797 */
/*<       end >*/
} /* wropen_ */

#ifdef __cplusplus
	}
#endif
