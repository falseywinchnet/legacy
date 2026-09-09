/* genscn.f -- translated by f2c (version 20240504).
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

/* COMMON genscn_ is declared in common.hpp. */

#define genscn_1 genscn_

/* COMMON ftable_ is declared in common.hpp. */

#define ftable_1 ftable_

/* COMMON ftablea_ is declared in common.hpp. */

#define ftablea_1 ftablea_

/* COMMON ftablec_ is declared in common.hpp. */

#define ftablec_1 ftablec_

/* COMMON miscon_ is declared in common.hpp. */

#define miscon_1 miscon_

/* COMMON julian_ is declared in common.hpp. */

#define julian_1 julian_

/* COMMON gate1_ is declared in common.hpp. */

#define gate1_1 gate1_

/* COMMON gate2_ is declared in common.hpp. */

#define gate2_1 gate2_

/* COMMON bnothr_ is declared in common.hpp. */

#define bnothr_1 bnothr_

/* COMMON bnothc_ is declared in common.hpp. */

#define bnothc_1 bnothc_

/* COMMON enothr_ is declared in common.hpp. */

#define enothr_1 enothr_

/* COMMON enothc_ is declared in common.hpp. */

#define enothc_1 enothc_

/* COMMON bnelem_ is declared in common.hpp. */

#define bnelem_1 bnelem_

/* COMMON enelem_ is declared in common.hpp. */

#define enelem_1 enelem_

/* COMMON version_ is declared in common.hpp. */

#define version_1 version_

/* COMMON versionc_ is declared in common.hpp. */

#define versionc_1 versionc_

/* COMMON homec_ is declared in common.hpp. */

#define homec_1 homec_

/* COMMON inbr_ is declared in common.hpp. */

#define inbr_1 inbr_

/* COMMON inen_ is declared in common.hpp. */

#define inen_1 inen_

/* COMMON inenc_ is declared in common.hpp. */

#define inenc_1 inenc_

/* COMMON svncom_ is declared in common.hpp. */

#define svncom_1 svncom_

/* COMMON svncomc_ is declared in common.hpp. */

#define svncomc_1 svncomc_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_3 = 3;
static integer feq_gen_c_d_2 = 2;
static integer c_n1 = -1;
static integer feq_gen_c_d_11 = 11;




/* SOURCE genscn.for:4 */
/*<       subroutineinitialize_genscn() >*/
/* Subroutine */ int feq_gen_initialize_genscn_d_()
{
/*     Initialize various values in the GENSCN system */
/* SOURCE genscn.for:7 */
/*<       implicitnone >*/
/* INCLUDE genscn.for:9 */
/*     Common block for items needed for creating files for */
/*     GENSCN */
/* SOURCE genscn.cmn:4 */
/*<       integermngsout,mngsout2 >*/
/* SOURCE genscn.cmn:5 */
/*<       parameter(mngsout=20000,mngsout2=2*mngsout) >*/
/* SOURCE genscn.cmn:7 */
/*<       integerfeo_unit,tsd_unit,ftf_unit,genscn_nout,genscn_record_knt >*/
/* SOURCE genscn.cmn:10 */
/*<       integergenscn_pout(mngsout) >*/
/* SOURCE genscn.cmn:12 */
/*<       realgenscn_out_vec(mngsout2) >*/
/* SOURCE genscn.cmn:14 */
/*<       real*8genscn_jtime >*/
/* SOURCE genscn.cmn:16 */
/*<        >*/
/* *********************************************************************** */
/*     Clear the unit numbers, location counter, and set the record */
/*     counter to its default initial value. */
/* SOURCE genscn.for:13 */
/*<       feo_unit=0 >*/
    genscn_1.feq_gen_feo_unit_d_ = 0;
/* SOURCE genscn.for:14 */
/*<       tsd_unit=0 >*/
    genscn_1.feq_gen_tsd_unit_d_ = 0;
/* SOURCE genscn.for:15 */
/*<       ftf_unit=0 >*/
    genscn_1.feq_gen_ftf_unit_d_ = 0;
/* SOURCE genscn.for:16 */
/*<       genscn_nout=0 >*/
    genscn_1.feq_gen_genscn_nout_d_ = 0;
/* SOURCE genscn.for:17 */
/*<       genscn_record_knt=0 >*/
    genscn_1.feq_gen_genscn_record_knt_d_ = 0;
/* SOURCE genscn.for:18 */
/*<       return >*/
    return 0;
/* SOURCE genscn.for:19 */
/*<       end >*/
} /* initialize_genscn__ */




/* SOURCE genscn.for:24 */
/*<        >*/
/* Subroutine */ int feq_gen_write_ftfa_d_(integer *stdout, integer *feq_gen_ftf_unit_d_, 
	integer *ftp, integer *feq_gen_number_of_full_records_d_, integer *
	feq_gen_items_per_record_d_, integer *feq_gen_leftover_item_knt_d_)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Builtin functions */
    integer s_wdue(cilist *), do_uio(integer *, char *, ftnlen), e_wdue();

    /* Local variables */
    integer feq_gen_i_d_, j, je, js;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__7 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__9 = { 0, 0, 0, 0, 0 };


/*     Output the function table vector.  Some changes to */
/*     the original to set the zero-th element and also */
/*     correct the error in the number of full records */
/*     that results in there being an extra element written. */
/* SOURCE genscn.for:33 */
/*<       implicitnone >*/
/* SOURCE genscn.for:34 */
/*<        >*/
/* INCLUDE genscn.for:37 */
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
/* INCLUDE genscn.for:38 */
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
/* SOURCE genscn.for:42 */
/*<       integeri,j,js,je >*/
/* ****************************************************************** */
/* SOURCE genscn.for:44 */
/*<       ftab(0)=0.0 >*/
    ftab[0] = (float)0.;
/*      WRITE(STDOUT,*) ' In WRITE_FTFA: FTP=',FTP */
/* SOURCE genscn.for:46 */
/*<       items_per_record=512 >*/
    *feq_gen_items_per_record_d_ = 512;
/* SOURCE genscn.for:47 */
/*<       number_of_full_records=(ftp)/items_per_record >*/
    *feq_gen_number_of_full_records_d_ = *ftp / *feq_gen_items_per_record_d_;
/*      WRITE(STDOUT,*) ' In WRITE_FTFA: NUMBER_OF_FULL_RECORDS=', */
/*     A                  NUMBER_OF_FULL_RECORDS */
/* SOURCE genscn.for:51 */
/*<       leftover_item_knt=ftp-number_of_full_records*items_per_record >*/
    *feq_gen_leftover_item_knt_d_ = *ftp - *feq_gen_number_of_full_records_d_ * *
	    feq_gen_items_per_record_d_;
/*      WRITE(STDOUT,*) ' In WRITE_FTFA: LEFTOVER=', */
/*     A            LEFTOVER_ITEM_KNT */
/* SOURCE genscn.for:57 */
/*<       js=0 >*/
    js = 0;
/* SOURCE genscn.for:58 */
/*<       do100i=1,number_of_full_records >*/
    feq_gen_i_d_1 = *feq_gen_number_of_full_records_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE genscn.for:59 */
/*<       je=js+items_per_record-1 >*/
	je = js + *feq_gen_items_per_record_d_ - 1;
/* SOURCE genscn.for:60 */
/*<       write(ftf_unit,rec=i)(ftab(j),j=js,je) >*/
	feq_gen_io_d__7.ciunit = *feq_gen_ftf_unit_d_;
	feq_gen_io_d__7.cirec = feq_gen_i_d_;
	s_wdue(&feq_gen_io_d__7);
	feq_gen_i_d_2 = je;
	for (j = js; j <= feq_gen_i_d_2; ++j) {
	    do_uio(&feq_gen_c_d_1, (char *)ftab.lease(j).data(), (ftnlen)sizeof(real));
	}
	e_wdue();
/*        WRITE(FTF_UNIT) (FTAB(J), J=JS,JE) */
/* SOURCE genscn.for:62 */
/*<       js=je+1 >*/
	js = je + 1;
/* SOURCE genscn.for:63 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE genscn.for:64 */
/*<       if(leftover_item_knt.gt.0)then >*/
    if (*feq_gen_leftover_item_knt_d_ > 0) {
/*       Write a partial record. */
/* SOURCE genscn.for:66 */
/*<       je=js+leftover_item_knt-1 >*/
	je = js + *feq_gen_leftover_item_knt_d_ - 1;
/* SOURCE genscn.for:67 */
/*<       do110j=je+1,items_per_record >*/
	feq_gen_i_d_1 = *feq_gen_items_per_record_d_;
	for (j = je + 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE genscn.for:68 */
/*<       ftab(j)=0.0 >*/
	    ftab[j] = (float)0.;
/* SOURCE genscn.for:69 */
/*<   110 continue >*/
/* L110: */
	}
/* SOURCE genscn.for:70 */
/*<       je=js+items_per_record-1 >*/
	je = js + *feq_gen_items_per_record_d_ - 1;
/* SOURCE genscn.for:71 */
/*<       write(ftf_unit,rec=number_of_full_records+1)(ftab(j),j=js,je) >*/
	feq_gen_io_d__9.ciunit = *feq_gen_ftf_unit_d_;
	feq_gen_io_d__9.cirec = *feq_gen_number_of_full_records_d_ + 1;
	s_wdue(&feq_gen_io_d__9);
	feq_gen_i_d_1 = je;
	for (j = js; j <= feq_gen_i_d_1; ++j) {
	    do_uio(&feq_gen_c_d_1, (char *)ftab.lease(j).data(), (ftnlen)sizeof(real));
	}
	e_wdue();
/*        WRITE(FTF_UNIT) (FTAB(J), J=JS,JE) */
/* SOURCE genscn.for:73 */
/*<       endif >*/
    }
/* SOURCE genscn.for:74 */
/*<       return >*/
    return 0;
/* SOURCE genscn.for:75 */
/*<       end >*/
} /* write_ftfa__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE genscn.for:80 */
/*<        >*/
/* Subroutine */ int feq_gen_write_ftf_d_(integer *stdout, integer *feq_gen_ftf_unit_d_, 
	integer *ftp, integer *feq_gen_number_of_full_records_d_, integer *
	feq_gen_items_per_record_d_, integer *feq_gen_leftover_item_knt_d_)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Builtin functions */
    integer s_wsue(cilist *), do_uio(integer *, char *, ftnlen), e_wsue();

    /* Local variables */
    integer feq_gen_i_d_, j, je, js;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__16 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__18 = { 0, 0, 0, 0, 0 };


/*     Output the function table vector. */
/* SOURCE genscn.for:86 */
/*<       implicitnone >*/
/* SOURCE genscn.for:87 */
/*<        >*/
/* INCLUDE genscn.for:90 */
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
/* INCLUDE genscn.for:91 */
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
/* SOURCE genscn.for:95 */
/*<       integeri,j,js,je >*/
/* ****************************************************************** */
/* SOURCE genscn.for:97 */
/*<       ftab(0)=0.0 >*/
    ftab[0] = (float)0.;
/*      WRITE(STDOUT,*) ' In WRITE_FTF: FTP=',FTP */
/* SOURCE genscn.for:99 */
/*<       items_per_record=512 >*/
    *feq_gen_items_per_record_d_ = 512;
/* SOURCE genscn.for:100 */
/*<       number_of_full_records=(ftp+1)/items_per_record >*/
    *feq_gen_number_of_full_records_d_ = (*ftp + 1) / *feq_gen_items_per_record_d_;
/*      WRITE(STDOUT,*) ' In WRITE_FTF: NUMBER_OF_FULL_RECORDS=', */
/*     A                  NUMBER_OF_FULL_RECORDS */
/* SOURCE genscn.for:104 */
/*<       leftover_item_knt=ftp+1-number_of_full_records*items_per_record >*/
    *feq_gen_leftover_item_knt_d_ = *ftp + 1 - *feq_gen_number_of_full_records_d_ * *
	    feq_gen_items_per_record_d_;
/*      WRITE(STDOUT,*) ' In WRITE_FTF: LEFTOVER=', */
/*     A            LEFTOVER_ITEM_KNT */
/* SOURCE genscn.for:110 */
/*<       js=0 >*/
    js = 0;
/* SOURCE genscn.for:111 */
/*<       do100i=1,number_of_full_records >*/
    feq_gen_i_d_1 = *feq_gen_number_of_full_records_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE genscn.for:112 */
/*<       je=js+items_per_record-1 >*/
	je = js + *feq_gen_items_per_record_d_ - 1;
/* SOURCE genscn.for:113 */
/*<       write(ftf_unit)(ftab(j),j=js,je) >*/
	feq_gen_io_d__16.ciunit = *feq_gen_ftf_unit_d_;
	s_wsue(&feq_gen_io_d__16);
	feq_gen_i_d_2 = je;
	for (j = js; j <= feq_gen_i_d_2; ++j) {
	    do_uio(&feq_gen_c_d_1, (char *)ftab.lease(j).data(), (ftnlen)sizeof(real));
	}
	e_wsue();
/* SOURCE genscn.for:114 */
/*<       js=je+1 >*/
	js = je + 1;
/* SOURCE genscn.for:115 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE genscn.for:116 */
/*<       if(leftover_item_knt.gt.0)then >*/
    if (*feq_gen_leftover_item_knt_d_ > 0) {
/*       Write a partial record. */
/* SOURCE genscn.for:118 */
/*<       je=js+leftover_item_knt-1 >*/
	je = js + *feq_gen_leftover_item_knt_d_ - 1;
/* SOURCE genscn.for:119 */
/*<       write(ftf_unit)(ftab(j),j=js,je) >*/
	feq_gen_io_d__18.ciunit = *feq_gen_ftf_unit_d_;
	s_wsue(&feq_gen_io_d__18);
	feq_gen_i_d_1 = je;
	for (j = js; j <= feq_gen_i_d_1; ++j) {
	    do_uio(&feq_gen_c_d_1, (char *)ftab.lease(j).data(), (ftnlen)sizeof(real));
	}
	e_wsue();
/* SOURCE genscn.for:120 */
/*<       endif >*/
    }
/* SOURCE genscn.for:121 */
/*<       return >*/
    return 0;
/* SOURCE genscn.for:122 */
/*<       end >*/
} /* write_ftf__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE genscn.for:126 */
/*<        >*/
/* Subroutine */ int feq_gen_genscn_input_d_(integer *stdin, integer *stdout, integer *
	feq_storage_brpt, integer *feq_storage_exnodt, integer *nbra, integer *nex, integer *nrwta, 
	integer *feq_storage_rwta, integer *feq_storage_rtap, real *sfac, integer *ftp, integer *
	eflag)
{
    /* Format strings */
    static char fmt_2[] = "(a)";
    static char fmt_5[] = "(i5,a5,1x,a12)";
    static char fmt_4[] = "(\002 \002,a80)";
    static char fmt_6[] = "(\002 \002,i5,a5,1x,a12)";
    static char fmt_7[] = "(\002 *ERR:147* Output requested at too many node\
s. NOUT = \002,i5)";
    static char fmt_50[] = "(\002-VERSION\002,/,\002FEQ:\002,f5.2,//,\002-FI\
LES\002)";
    static char fmt_51[] = "(\002 *ERR:172* Exterior node\002,a5,\002 does n\
ot have trib.\002,\002 area or is not a reservoir.\002)";
    static char fmt_52[] = "(a)";
    static char fmt_54[] = "(//,\002-UNITS\002,/,\002STATION_UNIT_NAME= mile\
s               \002,/,\002ELEVATION_UNIT_NAME= feet              \002,/,\
\002FLOW_UNIT_NAME= Cubic feet per second  \002,/,\002GATE_OPENING_UNIT_NAME\
= feet           \002,/,\002STORAGE_UNIT_NAME= acre-feet           \002,/\
,\002STORAGE_UNIT_FACTOR=2.295684E-5        \002,/,\002SURFACE_AREA_UNIT_NAM\
E=square miles    \002,/,\002SURFACE_AREA_FACTOR=3.587006e-8        \002)";
    static char fmt_56[] = "(//,\002-TSD\002,/\002LOCATION_KNT=\002,i8,/,\
\002 SYR SMN SDY    SHOUR          SJTIME       SREC\002,/,i4,i4,i4,f9.5,f16\
.8,i11)";
    static char fmt_58[] = "(//,\002-TSDDIR\002,/,\002      FEQ LOCTN BRAN  \
 NODE         STATION     INVERT \002,\002       USERID\002,\002     FTAB   \
Series\002,/,\002    LABEL CLASS   #      ID                   ELEVATION\002,\
\002       STRING\002,\002    index   offset\002,/,\002 -------- ----- -----\
  ----- --------------- ----------\002,\002 ------------\002,\002 -------- -\
-------\002)";
    static char fmt_68[] = "(/,\002 *WRN:58* No home name found following HO\
ME=. \002,\002 Home name cleared.\002)";
    static char fmt_69[] = "(/,\002 Home directory/drive is: \002,a)";
    static char fmt_70[] = "(1x,a8,1x,a5,1x,i5,1x,a6,1x,1pe15.6,1x,0pf10.4,1\
x,a12,1x,i8,1x,i8)";
    static char fmt_72[] = "(1x,8x,1x,5x,1x,\002   -1\002)";
    static char fmt_74[] = "(//\002-FTF\002,/,\002NUMBER_OF_FULL_RECORDS=\
\002,i8,/,\002ITEMS_PER_RECORD=\002,i8,/,\002LEFTOVER_ITEM_KNT=\002,i8)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;
    olist feq_gen_o_d_1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), i_indx(char *, char *, 
	    ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), s_rsfi(icilist *), e_rsfi(), 
	    f_open(olist *), s_wsle(cilist *), do_lio(integer *, integer *, 
	    char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfi(icilist *), e_wsfi();

    /* Local variables */
    char feq_gen_feo_name_d_[256], feq_gen_ftf_name_d_[256], feq_gen_tsd_name_d_[256];
    extern integer feq_gen_get_unit_d_(integer *);
    integer feq_gen_items_per_record_d_, feq_gen_i_d_;
    real feq_gen_invert_elevation_d_;
    extern /* Subroutine */ int feq_gen_free_unit_d_(integer *, integer *), 
	    feq_gen_write_ftf_d_(integer *, integer *, integer *, integer *, integer *,
	     integer *);
    integer feq_gen_tsd_start_d_, fa, fn, ip, ln, it, feq_gen_leftover_item_knt_d_;
    extern /* Subroutine */ int feq_gen_clear_home_d_();
    integer feq_gen_ftab_index_d_, bra, nde;
    extern /* Subroutine */ int kil_(integer *, integer *, integer *);
    integer nxt;
    extern /* Subroutine */ int feq_gen_maybe_add_ghome_out_d_(char *, ftnlen);
    char head[80];
    integer node;
    char line[196], char5[5];
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);
    integer brain;
    extern /* Subroutine */ int feq_gen_maybe_add_ext_d_(char *, ftnlen), 
	    feq_gen_os_file_style_d_(char *, ftnlen);
    integer ioflag;
    char feq_gen_user_id_string_d_[12], feq_gen_location_class_d_[5];
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen),
	     feq_gen_strip_l_blanks_d_(char *, ftnlen), nxttok_(char *, integer *, 
	    char *, ftnlen, ftnlen), getinn_(char *, integer *, integer *, 
	    ftnlen), getinb_(integer *, integer *, integer *);
    integer feq_gen_record_length_in_bytes_d_, feq_gen_number_of_full_records_d_;
    real station;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__22 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__23 = { 0, 0, 0, fmt_69, 0 };
    static cilist feq_gen_io_d__28 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__29 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__30 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__31 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__32 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__33 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__34 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__35 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__36 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__40 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__42 = { 0, 0, 0, fmt_4, 0 };
    static cilist feq_gen_io_d__43 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__47 = { 0, 0, 0, fmt_6, 0 };
    static cilist feq_gen_io_d__48 = { 0, 0, 0, fmt_7, 0 };
    static cilist feq_gen_io_d__51 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__52 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__58 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__63 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__65 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__66 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__68 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__70 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__71 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__72 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__73 = { 0, 0, 0, 0, 0 };


/* SOURCE genscn.for:131 */
/*<       implicitnone >*/
/*     Process the specification for the GENSCN data. */
/* INCLUDE genscn.for:133 */
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
/* SOURCE genscn.for:135 */
/*<       integereflag,stdin,stdout,nbra,nrwta,ftp,nex >*/
/* SOURCE genscn.for:137 */
/*<       integerbrpt(8,nbra),exnodt(9,nex),rtap(mnfree),rwta(mnfree) >*/
/* SOURCE genscn.for:140 */
/*<       realsfac >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
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
/*     NBRA   - number of branches in the model */
/*     NRWTA  - number of reservoirs with tributary area */
/*     RWTA   - reservoirs with tributary area */
/*     RTAP   - reservoir tributary area pointer */
/*     SFAC   - station factor for branches. */
/*     FTP    - pointer to next open location in FTAB/ITAB function */
/*              table storage vector. */
/* INCLUDE genscn.for:174 */
/*     Common block for items needed for creating files for */
/*     GENSCN */
/* SOURCE genscn.cmn:4 */
/*<       integermngsout,mngsout2 >*/
/* SOURCE genscn.cmn:5 */
/*<       parameter(mngsout=20000,mngsout2=2*mngsout) >*/
/* SOURCE genscn.cmn:7 */
/*<       integerfeo_unit,tsd_unit,ftf_unit,genscn_nout,genscn_record_knt >*/
/* SOURCE genscn.cmn:10 */
/*<       integergenscn_pout(mngsout) >*/
/* SOURCE genscn.cmn:12 */
/*<       realgenscn_out_vec(mngsout2) >*/
/* SOURCE genscn.cmn:14 */
/*<       real*8genscn_jtime >*/
/* SOURCE genscn.cmn:16 */
/*<        >*/
/* INCLUDE genscn.for:175 */
/*     Miscellaneous control parameters */
/* SOURCE misccon.cmn:3 */
/*<       integerpagesp,pndflg >*/
/* SOURCE misccon.cmn:5 */
/*<        >*/
/* SOURCE misccon.cmn:8 */
/*<        >*/
/* INCLUDE genscn.for:176 */
/* ********************************************************************** */
/* SOURCE julian.cmn:3 */
/*<        >*/
/* SOURCE julian.cmn:8 */
/*<       integeryr,mn,dy,syr,smn,sdy,eyr,emn,edy,reset,leap,dmyear,dmmn >*/
/* SOURCE julian.cmn:10 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE genscn.for:177 */
/*     Common block for the names for gates.  Includes the */
/*     information needed to place the flow class and the current */
/*     gate opening in the special output file.  Start the GOPEN and */
/*     FCLASS at 0 to provide space for gates/pumps without a name. */
/*     We can then avoid an IF statement to see if we should store */
/*     something.  If no name is given the data goes into slot */
/*     zero and is never used!  FCLASS_CODE gives a unique numerical */
/*     code for each flow class string given in FCLASS. */
/*     Use slot MNGATE+1 for the McHenry gates. */
/* SOURCE gatcom.cmn:12 */
/*<       integerngate >*/
/* SOURCE gatcom.cmn:14 */
/*<       realgopen(0:mngate+1) >*/
/* SOURCE gatcom.cmn:16 */
/*<       integerfclass_code(0:mngate+1) >*/
/* SOURCE gatcom.cmn:18 */
/*<       charactergname(mngate+1)*16,fclass(0:mngate+1)*8 >*/
/*     FCLASS gives the flow class of the gate.  The meaning of this field */
/*     depends on the gate type and the kinds of flow that FEQ can report. */
/* SOURCE gatcom.cmn:24 */
/*<       common/gate1/ngate,gopen,fclass_code >*/
/* SOURCE gatcom.cmn:25 */
/*<       common/gate2/gname,fclass >*/
/* SOURCE gatcom.cmn:27 */
/*<       save/gate1/,/gate2/ >*/
/* INCLUDE genscn.for:178 */
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
/* INCLUDE genscn.for:179 */
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
/* INCLUDE genscn.for:180 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE genscn.for:181 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE genscn.for:182 */
/*     Common block to allow version and date to be output */
/*     at more than one point in the code. */
/* SOURCE version.cmn:4 */
/*<       characterversion_date*17 >*/
/* SOURCE version.cmn:6 */
/*<       realversion_number >*/
/* SOURCE version.cmn:8 */
/*<       common/version/version_number >*/
/* SOURCE version.cmn:10 */
/*<       common/versionc/version_date >*/
/* INCLUDE genscn.for:183 */
/*     Values of local and global home directory names */
/* 	7 dec 2005:  Add an output extension value */
/* SOURCE home.cmn:3 */
/*<       character*128stdext >*/
/* SOURCE home.cmn:4 */
/*<       character*128home,ghome,ghome_out >*/
/* SOURCE home.cmn:5 */
/*<       common/homec/home,ghome,ghome_out,stdext >*/
/* SOURCE home.cmn:6 */
/*<       save/homec/ >*/
/*     called subprograms */
/*     Local variables. */
/* SOURCE genscn.for:189 */
/*<        >*/
/* SOURCE genscn.for:193 */
/*<        >*/
/* SOURCE genscn.for:198 */
/*<       realstation,invert_elevation >*/
/* SOURCE genscn.for:201 */
/*<       integerget_unit >*/
/* SOURCE genscn.for:202 */
/*<       charactergettok*5 >*/
/* SOURCE genscn.for:203 */
/*<       externalget_unit,gettok,lstab,free_unit,inline >*/
/*     ***************************FORMATS*************************************** */
/* SOURCE genscn.for:126 */
/*<       integer feq_len_trim >*/
/* SOURCE genscn.for:126 */
/*<       external feq_len_trim >*/
/* SOURCE genscn.for:205 */
/*<     2 format(a) >*/
/* 3    FORMAT(A) */
/* SOURCE genscn.for:208 */
/*<     5 format(i5,a5,1x,a12) >*/
/* SOURCE genscn.for:210 */
/*<     4 format(' ',a80) >*/
/* SOURCE genscn.for:211 */
/*<     6 format(' ',i5,a5,1x,a12) >*/
/* SOURCE genscn.for:212 */
/*<     7  >*/
/* SOURCE genscn.for:215 */
/*<    50 format('-VERSION',/,'FEQ:',f5.2,//,'-FILES') >*/
/* SOURCE genscn.for:216 */
/*<    51  >*/
/* SOURCE genscn.for:218 */
/*<    52 format(a) >*/
/* SOURCE genscn.for:220 */
/*<    54  >*/
/* SOURCE genscn.for:230 */
/*<    56  >*/
/*     D       ' EYR EMN EDY    EHOUR          EJTIME       EREC',/, */
/*     E       I4,I4,I4,F9.5,F16.8,I11) */
/* SOURCE genscn.for:237 */
/*<    58  >*/
/* SOURCE genscn.for:247 */
/*<    68  >*/
/* SOURCE genscn.for:249 */
/*<    69 format(/,' Home directory/drive is: ',a) >*/
/* SOURCE genscn.for:250 */
/*<    70  >*/
/* SOURCE genscn.for:252 */
/*<    72 format(1x,8x,1x,5x,1x,'   -1') >*/
/* SOURCE genscn.for:253 */
/*<    74  >*/
/* ********************************************************************* */
/* SOURCE genscn.for:259 */
/*<       callclear_home() >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> rwta(feq_storage_rwta, 1);

    feq::IndexedPointer<integer> rtap(feq_storage_rtap, 1);

    /* Function Body */
/* L2: */
/* L5: */
/* L4: */
/* L6: */
/* L7: */
/* L50: */
/* L51: */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
/* L68: */
/* L69: */
/* L70: */
/* L72: */
/* L74: */
    feq_gen_clear_home_d_();
/* SOURCE genscn.for:260 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)196);
/* SOURCE genscn.for:263 */
/*<       callstrip_l_blanks(line) >*/
    feq_gen_strip_l_blanks_d_(line, (ftnlen)196);
/* SOURCE genscn.for:265 */
/*<       if(line(1:4).eq.'HOME'.or.line(1:4).eq.'home')then >*/
    if (s_cmp(line, const_cast<char*>("HOME"), (ftnlen)4, (ftnlen)4) == 0 || s_cmp(line, const_cast<char*>("home"), 
	    (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE genscn.for:266 */
/*<       it=index(line,'=') >*/
	it = i_indx(line, const_cast<char*>("="), (ftnlen)196, (ftnlen)1);
/* SOURCE genscn.for:267 */
/*<       nxt=it+1 >*/
	nxt = it + 1;
/* SOURCE genscn.for:268 */
/*<       callnxttok(line,nxt,home) >*/
	nxttok_(line, &nxt, homec_1.home, (ftnlen)196, (ftnlen)128);
/* SOURCE genscn.for:272 */
/*<       if(nxt.le.0)then >*/
	if (nxt <= 0) {
/* SOURCE genscn.for:273 */
/*<       write(stdout,68) >*/
	    feq_gen_io_d__22.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__22);
	    e_wsfe();
/* SOURCE genscn.for:274 */
/*<       home=' ' >*/
	    s_copy(homec_1.home, const_cast<char*>(" "), (ftnlen)128, (ftnlen)1);
/* SOURCE genscn.for:275 */
/*<       endif >*/
	}
/* SOURCE genscn.for:276 */
/*<       callstrip_l_blanks(home) >*/
	feq_gen_strip_l_blanks_d_(homec_1.home, (ftnlen)128);
/* SOURCE genscn.for:278 */
/*<       it=feq_len_trim(home) >*/
	it = feq_gen_feq_len_trim_d_(homec_1.home, (ftnlen)128);
/* SOURCE genscn.for:279 */
/*<       write(stdout,69)home(1:it) >*/
	feq_gen_io_d__23.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__23);
	do_fio(&feq_gen_c_d_1, homec_1.home, it);
	e_wsfe();
/* SOURCE genscn.for:281 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)196);
/* SOURCE genscn.for:284 */
/*<       endif >*/
    }
/*     Input the three file names for now.  Refine later */
/*      CALL inline */
/*     I          (STDIN, STDOUT, */
/*     O           LINE) */
/* SOURCE genscn.for:290 */
/*<       read(line,2)feo_name >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 196;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_2;
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, feq_gen_feo_name_d_, (ftnlen)256);
    e_rsfi();
/* SOURCE genscn.for:291 */
/*<       callmaybe_add_ghome_out(feo_name) >*/
    feq_gen_maybe_add_ghome_out_d_(feq_gen_feo_name_d_, (ftnlen)256);
/* SOURCE genscn.for:293 */
/*<       callmaybe_add_ext(feo_name) >*/
    feq_gen_maybe_add_ext_d_(feq_gen_feo_name_d_, (ftnlen)256);
/* SOURCE genscn.for:295 */
/*<       callos_file_style(feo_name) >*/
    feq_gen_os_file_style_d_(feq_gen_feo_name_d_, (ftnlen)256);
/* SOURCE genscn.for:297 */
/*<       write(stdout,'(A)')feo_name >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, feq_gen_feo_name_d_, (ftnlen)256);
    e_wsfe();
/* SOURCE genscn.for:298 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)196);
/* SOURCE genscn.for:301 */
/*<       read(line,2)tsd_name >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 196;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_2;
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, feq_gen_tsd_name_d_, (ftnlen)256);
    e_rsfi();
/* SOURCE genscn.for:302 */
/*<       callmaybe_add_ghome_out(tsd_name) >*/
    feq_gen_maybe_add_ghome_out_d_(feq_gen_tsd_name_d_, (ftnlen)256);
/* SOURCE genscn.for:304 */
/*<       callmaybe_add_ext(tsd_name) >*/
    feq_gen_maybe_add_ext_d_(feq_gen_tsd_name_d_, (ftnlen)256);
/* SOURCE genscn.for:306 */
/*<       callos_file_style(tsd_name) >*/
    feq_gen_os_file_style_d_(feq_gen_tsd_name_d_, (ftnlen)256);
/* SOURCE genscn.for:308 */
/*<       write(stdout,'(A)')tsd_name >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, feq_gen_tsd_name_d_, (ftnlen)256);
    e_wsfe();
/* SOURCE genscn.for:309 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)196);
/* SOURCE genscn.for:312 */
/*<       read(line,2)ftf_name >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 196;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_2;
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, feq_gen_ftf_name_d_, (ftnlen)256);
    e_rsfi();
/* SOURCE genscn.for:313 */
/*<       callmaybe_add_ghome_out(ftf_name) >*/
    feq_gen_maybe_add_ghome_out_d_(feq_gen_ftf_name_d_, (ftnlen)256);
/* SOURCE genscn.for:315 */
/*<       callmaybe_add_ext(ftf_name) >*/
    feq_gen_maybe_add_ext_d_(feq_gen_ftf_name_d_, (ftnlen)256);
/* SOURCE genscn.for:317 */
/*<       callos_file_style(ftf_name) >*/
    feq_gen_os_file_style_d_(feq_gen_ftf_name_d_, (ftnlen)256);
/* SOURCE genscn.for:319 */
/*<       write(stdout,'(A)')ftf_name >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, feq_gen_ftf_name_d_, (ftnlen)256);
    e_wsfe();
/*     Open the FEO file.  Assume each case is new for now.  Add support */
/*     for update later. */
/* SOURCE genscn.for:324 */
/*<       feo_unit=get_unit(stdout) >*/
    genscn_1.feq_gen_feo_unit_d_ = feq_gen_get_unit_d_(stdout);
/* SOURCE genscn.for:325 */
/*<        >*/
    feq_gen_o_d_1.oerr = 1;
    feq_gen_o_d_1.ounit = genscn_1.feq_gen_feo_unit_d_;
    feq_gen_o_d_1.ofnmlen = 256;
    feq_gen_o_d_1.ofnm = feq_gen_feo_name_d_;
    feq_gen_o_d_1.orl = 0;
    feq_gen_o_d_1.osta = const_cast<char*>("UNKNOWN");
    feq_gen_o_d_1.oacc = 0;
    feq_gen_o_d_1.ofm = const_cast<char*>("FORMATTED");
    feq_gen_o_d_1.oblnk = 0;
    ioflag = f_open(&feq_gen_o_d_1);
/* SOURCE genscn.for:328 */
/*<       if(ioflag.ne.0)then >*/
    if (ioflag != 0) {
/* SOURCE genscn.for:329 */
/*<       write(stdout,*)' Problem in opening file: ',feo_name >*/
	feq_gen_io_d__28.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__28);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Problem in opening file: "), (ftnlen)26);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_feo_name_d_, (ftnlen)256);
	e_wsle();
/* SOURCE genscn.for:330 */
/*<       write(stdout,*)' Check path for *.feo file.' >*/
	feq_gen_io_d__29.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__29);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Check path for *.feo file."), (ftnlen)27);
	e_wsle();
/* SOURCE genscn.for:331 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE genscn.for:332 */
/*<       endif >*/
    }
/* SOURCE genscn.for:334 */
/*<       write(feo_unit,50)version_number >*/
    feq_gen_io_d__30.ciunit = genscn_1.feq_gen_feo_unit_d_;
    s_wsfe(&feq_gen_io_d__30);
    do_fio(&feq_gen_c_d_1, (char *)&version_1.feq_gen_version_number_d_, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE genscn.for:335 */
/*<       write(feo_unit,52)feo_name(1:feq_len_trim(feo_name)) >*/
    feq_gen_io_d__31.ciunit = genscn_1.feq_gen_feo_unit_d_;
    s_wsfe(&feq_gen_io_d__31);
    do_fio(&feq_gen_c_d_1, feq_gen_feo_name_d_, feq_gen_feq_len_trim_d_(feq_gen_feo_name_d_, (ftnlen)256));
    e_wsfe();
/* SOURCE genscn.for:336 */
/*<       write(feo_unit,52)tsd_name(1:feq_len_trim(tsd_name)) >*/
    feq_gen_io_d__32.ciunit = genscn_1.feq_gen_feo_unit_d_;
    s_wsfe(&feq_gen_io_d__32);
    do_fio(&feq_gen_c_d_1, feq_gen_tsd_name_d_, feq_gen_feq_len_trim_d_(feq_gen_tsd_name_d_, (ftnlen)256));
    e_wsfe();
/* SOURCE genscn.for:337 */
/*<       write(feo_unit,52)ftf_name(1:feq_len_trim(ftf_name)) >*/
    feq_gen_io_d__33.ciunit = genscn_1.feq_gen_feo_unit_d_;
    s_wsfe(&feq_gen_io_d__33);
    do_fio(&feq_gen_c_d_1, feq_gen_ftf_name_d_, feq_gen_feq_len_trim_d_(feq_gen_ftf_name_d_, (ftnlen)256));
    e_wsfe();
/*     Write the unit names and conversion factors.  Expand later. */
/* SOURCE genscn.for:341 */
/*<       write(feo_unit,54) >*/
    feq_gen_io_d__34.ciunit = genscn_1.feq_gen_feo_unit_d_;
    s_wsfe(&feq_gen_io_d__34);
    e_wsfe();
/*     Open the FTF file and store the function table vector in it. */
/* SOURCE genscn.for:345 */
/*<       ftf_unit=get_unit(stdout) >*/
    genscn_1.feq_gen_ftf_unit_d_ = feq_gen_get_unit_d_(stdout);
/* SOURCE genscn.for:346 */
/*<        >*/
    feq_gen_o_d_1.oerr = 1;
    feq_gen_o_d_1.ounit = genscn_1.feq_gen_ftf_unit_d_;
    feq_gen_o_d_1.ofnmlen = 256;
    feq_gen_o_d_1.ofnm = feq_gen_ftf_name_d_;
    feq_gen_o_d_1.orl = 0;
    feq_gen_o_d_1.osta = const_cast<char*>("UNKNOWN");
    feq_gen_o_d_1.oacc = 0;
    feq_gen_o_d_1.ofm = const_cast<char*>("UNFORMATTED");
    feq_gen_o_d_1.oblnk = 0;
    ioflag = f_open(&feq_gen_o_d_1);
/* SOURCE genscn.for:349 */
/*<       if(ioflag.ne.0)then >*/
    if (ioflag != 0) {
/* SOURCE genscn.for:350 */
/*<       write(stdout,*)' Problem in opening file: ',ftf_name >*/
	feq_gen_io_d__35.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__35);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Problem in opening file: "), (ftnlen)26);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ftf_name_d_, (ftnlen)256);
	e_wsle();
/* SOURCE genscn.for:351 */
/*<       write(stdout,*)' Check path for *.ftf file.' >*/
	feq_gen_io_d__36.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__36);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Check path for *.ftf file."), (ftnlen)27);
	e_wsle();
/* SOURCE genscn.for:352 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE genscn.for:353 */
/*<       endif >*/
    }
/* SOURCE genscn.for:354 */
/*<        >*/
    feq_gen_write_ftf_d_(stdout, &genscn_1.feq_gen_ftf_unit_d_, ftp, &feq_gen_number_of_full_records_d_, 
	    &feq_gen_items_per_record_d_, &feq_gen_leftover_item_knt_d_);
/* SOURCE genscn.for:357 */
/*<       callfree_unit(stdout,ftf_unit) >*/
    feq_gen_free_unit_d_(stdout, &genscn_1.feq_gen_ftf_unit_d_);
/*     Write description of the FTF file to the FEO file */
/* SOURCE genscn.for:360 */
/*<        >*/
    feq_gen_io_d__40.ciunit = genscn_1.feq_gen_feo_unit_d_;
    s_wsfe(&feq_gen_io_d__40);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_number_of_full_records_d_, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_items_per_record_d_, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_leftover_item_knt_d_, (ftnlen)sizeof(integer));
    e_wsfe();
/*     For initial testing adapt the special output processing code */
/*     and expand to include some generic groups of nodes later. */
/* SOURCE genscn.for:368 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)196);
/* SOURCE genscn.for:371 */
/*<       read(line,2)head >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 196;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_2;
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_rsfi();
/* SOURCE genscn.for:372 */
/*<       write(stdout,4)head >*/
    feq_gen_io_d__42.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__42);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_wsfe();
/* SOURCE genscn.for:374 */
/*<       write(feo_unit,58) >*/
    feq_gen_io_d__43.ciunit = genscn_1.feq_gen_feo_unit_d_;
    s_wsfe(&feq_gen_io_d__43);
    e_wsfe();
/* SOURCE genscn.for:375 */
/*<       genscn_nout=0 >*/
    genscn_1.feq_gen_genscn_nout_d_ = 0;
/* SOURCE genscn.for:376 */
/*<   100 continue >*/
L100:
/* SOURCE genscn.for:377 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)196);
/* SOURCE genscn.for:380 */
/*<       read(line,5,err=991)brain,char5,user_id_string >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 196;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_5;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&brain, (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, feq_gen_user_id_string_d_, (ftnlen)12);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE genscn.for:381 */
/*<       if(brain.lt.0)goto150 >*/
    if (brain < 0) {
	goto L150;
    }
/* SOURCE genscn.for:382 */
/*<       write(stdout,6)brain,char5,user_id_string >*/
    feq_gen_io_d__47.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__47);
    do_fio(&feq_gen_c_d_1, (char *)&brain, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, feq_gen_user_id_string_d_, (ftnlen)12);
    e_wsfe();
/* SOURCE genscn.for:383 */
/*<       genscn_nout=genscn_nout+1 >*/
    ++genscn_1.feq_gen_genscn_nout_d_;
/* SOURCE genscn.for:384 */
/*<       if(genscn_nout.le.mngsout)goto110 >*/
    if (genscn_1.feq_gen_genscn_nout_d_ <= 20000) {
	goto L110;
    }
/* SOURCE genscn.for:385 */
/*<       write(stdout,7)genscn_nout >*/
    feq_gen_io_d__48.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__48);
    do_fio(&feq_gen_c_d_1, (char *)&genscn_1.feq_gen_genscn_nout_d_, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE genscn.for:386 */
/*<       genscn_nout=1 >*/
    genscn_1.feq_gen_genscn_nout_d_ = 1;
/* SOURCE genscn.for:387 */
/*<       eflag=1 >*/
    *eflag = 1;
/* SOURCE genscn.for:388 */
/*<   110 continue >*/
L110:
/* SOURCE genscn.for:390 */
/*<       if(brain.ne.0)goto120 >*/
    if (brain != 0) {
	goto L120;
    }
/*       EXTERIOR NODE */
/* SOURCE genscn.for:393 */
/*<       callgetinn(char5,eflag,node) >*/
    getinn_(char5, eflag, &node, (ftnlen)5);
/* SOURCE genscn.for:396 */
/*<       if(node.gt.0)then >*/
    if (node > 0) {
/* SOURCE genscn.for:397 */
/*<       genscn_pout(genscn_nout)=-node >*/
	genscn_1.feq_gen_genscn_pout_d_[genscn_1.feq_gen_genscn_nout_d_ - 1] = -node;
/* SOURCE genscn.for:398 */
/*<       else >*/
    } else {
/*            ONLY RESERVOIR NODES WITH TRIBUTARY AREA ARE VALID */
/*            HERE. */
/* SOURCE genscn.for:401 */
/*<       node=iabs(node) >*/
	node = abs(node);
/* SOURCE genscn.for:402 */
/*<       do112i=1,nrwta >*/
	feq_gen_i_d_1 = *nrwta;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE genscn.for:403 */
/*<       if(node.eq.rwta(i))then >*/
	    if (node == rwta[feq_gen_i_d_]) {
/* SOURCE genscn.for:404 */
/*<       genscn_pout(genscn_nout)=-(rtap(i)+10000) >*/
		genscn_1.feq_gen_genscn_pout_d_[genscn_1.feq_gen_genscn_nout_d_ - 1] = -(rtap[
			feq_gen_i_d_] + 10000);
/* SOURCE genscn.for:405 */
/*<       goto100 >*/
		goto L100;
/* SOURCE genscn.for:406 */
/*<       endif >*/
	    }
/* SOURCE genscn.for:407 */
/*<   112 continue >*/
/* L112: */
	}
/* SOURCE genscn.for:408 */
/*<       write(stdout,51)char5 >*/
	feq_gen_io_d__51.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__51);
	do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
	e_wsfe();
/* SOURCE genscn.for:409 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE genscn.for:410 */
/*<       endif >*/
    }
/* SOURCE genscn.for:412 */
/*<       write(stdout,*)' Internal node #=',node >*/
    feq_gen_io_d__52.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__52);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Internal node #="), (ftnlen)17);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&node, (ftnlen)sizeof(integer));
    e_wsle();
/*          Identify the character of the exterior node. */
/* SOURCE genscn.for:415 */
/*<       if(exnodt(3,node).gt.0)then >*/
    if (exnodt[node * 9 + 3] > 0) {
/*            Exterior node for a branch. */
/* SOURCE genscn.for:417 */
/*<       ip=exnodt(2,node) >*/
	ip = exnodt[node * 9 + 2];
/* SOURCE genscn.for:418 */
/*<       station=xvec(ip)/sfac >*/
	station = static_cast<double>(bnelem_1.xvec[ip - 1]) / *sfac;
/* SOURCE genscn.for:419 */
/*<       invert_elevation=zvec(ip) >*/
	feq_gen_invert_elevation_d_ = bnelem_1.zvec[ip - 1];
/* SOURCE genscn.for:420 */
/*<       ftab_index=exnodt(4,node) >*/
	feq_gen_ftab_index_d_ = exnodt[node * 9 + 4];
/* SOURCE genscn.for:421 */
/*<       location_class='BNODE' >*/
	s_copy(feq_gen_location_class_d_, const_cast<char*>("BNODE"), (ftnlen)5, (ftnlen)5);
/* SOURCE genscn.for:422 */
/*<       elseif(exnodt(3,node).eq.0)then >*/
    } else if (exnodt[node * 9 + 3] == 0) {
/*            Exterior node not on a branch and not a LPR */
/* SOURCE genscn.for:424 */
/*<       station=-1.e30 >*/
	station = (float)-1e30;
/* SOURCE genscn.for:425 */
/*<       invert_elevation=ze(node) >*/
	feq_gen_invert_elevation_d_ = enelem_1.ze[node - 1];
/* SOURCE genscn.for:426 */
/*<       ftab_index=0 >*/
	feq_gen_ftab_index_d_ = 0;
/* SOURCE genscn.for:427 */
/*<       location_class='FNODE' >*/
	s_copy(feq_gen_location_class_d_, const_cast<char*>("FNODE"), (ftnlen)5, (ftnlen)5);
/* SOURCE genscn.for:428 */
/*<       else >*/
    } else {
/*            Has to be a LPR node. */
/* SOURCE genscn.for:430 */
/*<       station=-1.e30 >*/
	station = (float)-1e30;
/* SOURCE genscn.for:431 */
/*<       invert_elevation=ze(node) >*/
	feq_gen_invert_elevation_d_ = enelem_1.ze[node - 1];
/* SOURCE genscn.for:432 */
/*<       ftab_index=exnodt(4,node) >*/
	feq_gen_ftab_index_d_ = exnodt[node * 9 + 4];
/* SOURCE genscn.for:433 */
/*<       location_class='LPR  ' >*/
	s_copy(feq_gen_location_class_d_, const_cast<char*>("LPR  "), (ftnlen)5, (ftnlen)5);
/* SOURCE genscn.for:434 */
/*<       endif >*/
    }
/*          Write the next line to the FEO file. */
/* SOURCE genscn.for:437 */
/*<        >*/
    feq_gen_io_d__58.ciunit = genscn_1.feq_gen_feo_unit_d_;
    s_wsfe(&feq_gen_io_d__58);
    do_fio(&feq_gen_c_d_1, enothc_1.enodid + (node - 1 << 4), (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_location_class_d_, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, (char *)&brain, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, (char *)&station, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_invert_elevation_d_, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, feq_gen_user_id_string_d_, (ftnlen)12);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_ftab_index_d_, (ftnlen)sizeof(integer));
    feq_gen_i_d_1 = (genscn_1.feq_gen_genscn_nout_d_ - 1 << 1) + 1;
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE genscn.for:441 */
/*<       goto100 >*/
    goto L100;
/* SOURCE genscn.for:442 */
/*<   120 continue >*/
L120:
/* SOURCE genscn.for:443 */
/*<       read(char5,'(I5)',err=991)node >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 5;
    feq_gen_ici_d_1.iciunit = char5;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(I5)");
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&node, (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE genscn.for:444 */
/*<       callgetinb(brain,eflag,bra) >*/
    getinb_(&brain, eflag, &bra);
/* SOURCE genscn.for:447 */
/*<       fn=brpt(1,bra) >*/
    fn = brpt[(bra << 3) + 1];
/* SOURCE genscn.for:448 */
/*<       ln=brpt(2,bra) >*/
    ln = brpt[(bra << 3) + 2];
/* SOURCE genscn.for:449 */
/*<       fa=brpt(3,bra) >*/
    fa = brpt[(bra << 3) + 3];
/* SOURCE genscn.for:451 */
/*<       if(node.eq.0)then >*/
    if (node == 0) {
/*         Dump the whole branch option. */
/* SOURCE genscn.for:453 */
/*<       genscn_nout=genscn_nout-1 >*/
	--genscn_1.feq_gen_genscn_nout_d_;
/* SOURCE genscn.for:454 */
/*<       do130node=fn,ln >*/
	feq_gen_i_d_1 = ln;
	for (node = fn; node <= feq_gen_i_d_1; ++node) {
/* SOURCE genscn.for:455 */
/*<       genscn_nout=genscn_nout+1 >*/
	    ++genscn_1.feq_gen_genscn_nout_d_;
/* SOURCE genscn.for:456 */
/*<       ip=fa+abs(node)-fn >*/
	    ip = fa + abs(node) - fn;
/* SOURCE genscn.for:457 */
/*<       genscn_pout(genscn_nout)=ip >*/
	    genscn_1.feq_gen_genscn_pout_d_[genscn_1.feq_gen_genscn_nout_d_ - 1] = ip;
/* SOURCE genscn.for:458 */
/*<       station=xvec(ip)/sfac >*/
	    station = static_cast<double>(bnelem_1.xvec[ip - 1]) / *sfac;
/* SOURCE genscn.for:459 */
/*<       invert_elevation=zvec(ip) >*/
	    feq_gen_invert_elevation_d_ = bnelem_1.zvec[ip - 1];
/* SOURCE genscn.for:460 */
/*<       ftab_index=nsec(ip) >*/
	    feq_gen_ftab_index_d_ = bnothr_1.nsec[ip - 1];
/* SOURCE genscn.for:461 */
/*<       location_class='BNODE' >*/
	    s_copy(feq_gen_location_class_d_, const_cast<char*>("BNODE"), (ftnlen)5, (ftnlen)5);
/* SOURCE genscn.for:462 */
/*<       write(char5,'(I5)')node >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 5;
	    feq_gen_ici_d_1.iciunit = char5;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(I5)");
	    s_wsfi(&feq_gen_ici_d_1);
	    do_fio(&feq_gen_c_d_1, (char *)&node, (ftnlen)sizeof(integer));
	    e_wsfi();
/* SOURCE genscn.for:463 */
/*<        >*/
	    feq_gen_io_d__63.ciunit = genscn_1.feq_gen_feo_unit_d_;
	    s_wsfe(&feq_gen_io_d__63);
	    do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (ip - 1 << 4), (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_location_class_d_, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, (char *)&brain, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, (char *)&station, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_invert_elevation_d_, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, feq_gen_user_id_string_d_, (ftnlen)12);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_ftab_index_d_, (ftnlen)sizeof(integer));
	    feq_gen_i_d_2 = (genscn_1.feq_gen_genscn_nout_d_ - 1 << 1) + 1;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_2, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE genscn.for:466 */
/*<   130 continue >*/
/* L130: */
	}
/* SOURCE genscn.for:467 */
/*<       goto100 >*/
	goto L100;
/* SOURCE genscn.for:468 */
/*<       endif >*/
    }
/* SOURCE genscn.for:470 */
/*<       if(abs(node).lt.fn.or.abs(node).gt.ln)then >*/
    if (abs(node) < fn || abs(node) > ln) {
/* SOURCE genscn.for:471 */
/*<       nde=abs(node) >*/
	nde = abs(node);
/* SOURCE genscn.for:472 */
/*<       callkil(2,nde,eflag) >*/
	kil_(&feq_gen_c_d_2, &nde, eflag);
/* SOURCE genscn.for:475 */
/*<       node=-nde >*/
	node = -nde;
/* SOURCE genscn.for:476 */
/*<       endif >*/
    }
/*       COMPUTE ADDRESS FOR THIS BRANCH AND NODE NUMBER */
/* SOURCE genscn.for:479 */
/*<       ip=fa+abs(node)-fn >*/
    ip = fa + abs(node) - fn;
/* SOURCE genscn.for:480 */
/*<       if(node.gt.0)then >*/
    if (node > 0) {
/* SOURCE genscn.for:481 */
/*<       genscn_pout(genscn_nout)=ip >*/
	genscn_1.feq_gen_genscn_pout_d_[genscn_1.feq_gen_genscn_nout_d_ - 1] = ip;
/* SOURCE genscn.for:482 */
/*<       else >*/
    } else {
/* SOURCE genscn.for:483 */
/*<       genscn_pout(genscn_nout)=ip+10000 >*/
	genscn_1.feq_gen_genscn_pout_d_[genscn_1.feq_gen_genscn_nout_d_ - 1] = ip + 10000;
/* SOURCE genscn.for:484 */
/*<       endif >*/
    }
/*       Identify character of the node. */
/* SOURCE genscn.for:487 */
/*<       station=xvec(ip)/sfac >*/
    station = static_cast<double>(bnelem_1.xvec[ip - 1]) / *sfac;
/* SOURCE genscn.for:488 */
/*<       invert_elevation=zvec(ip) >*/
    feq_gen_invert_elevation_d_ = bnelem_1.zvec[ip - 1];
/* SOURCE genscn.for:489 */
/*<       ftab_index=nsec(ip) >*/
    feq_gen_ftab_index_d_ = bnothr_1.nsec[ip - 1];
/* SOURCE genscn.for:490 */
/*<       location_class='BNODE' >*/
    s_copy(feq_gen_location_class_d_, const_cast<char*>("BNODE"), (ftnlen)5, (ftnlen)5);
/* SOURCE genscn.for:491 */
/*<        >*/
    feq_gen_io_d__65.ciunit = genscn_1.feq_gen_feo_unit_d_;
    s_wsfe(&feq_gen_io_d__65);
    do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (ip - 1 << 4), (ftnlen)16);
    do_fio(&feq_gen_c_d_1, feq_gen_location_class_d_, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, (char *)&brain, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, (char *)&station, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_invert_elevation_d_, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, feq_gen_user_id_string_d_, (ftnlen)12);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_ftab_index_d_, (ftnlen)sizeof(integer));
    feq_gen_i_d_1 = (genscn_1.feq_gen_genscn_nout_d_ - 1 << 1) + 1;
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE genscn.for:495 */
/*<       goto100 >*/
    goto L100;
/* SOURCE genscn.for:497 */
/*<   150 continue >*/
L150:
/*     Write a terminating signal to the directory list. */
/* SOURCE genscn.for:500 */
/*<       write(feo_unit,72) >*/
    feq_gen_io_d__66.ciunit = genscn_1.feq_gen_feo_unit_d_;
    s_wsfe(&feq_gen_io_d__66);
    e_wsfe();
/*     Only write the starting values now because we do not know the */
/*     ending record at this time. */
/* SOURCE genscn.for:506 */
/*<       tsd_start=1 >*/
    feq_gen_tsd_start_d_ = 1;
/* SOURCE genscn.for:507 */
/*<       write(feo_unit,56)genscn_nout,syr,smn,sdy,sfrac,sjtime,tsd_start >*/
    feq_gen_io_d__68.ciunit = genscn_1.feq_gen_feo_unit_d_;
    s_wsfe(&feq_gen_io_d__68);
    do_fio(&feq_gen_c_d_1, (char *)&genscn_1.feq_gen_genscn_nout_d_, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&julian_1.syr, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&julian_1.smn, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&julian_1.sdy, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&julian_1.sfrac, (ftnlen)sizeof(doublereal));
    do_fio(&feq_gen_c_d_1, (char *)&julian_1.sjtime, (ftnlen)sizeof(doublereal));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tsd_start_d_, (ftnlen)sizeof(integer));
    e_wsfe();
/*     Open the TSD direct file. */
/* SOURCE genscn.for:513 */
/*<       record_length_in_bytes=8*(1+genscn_nout) >*/
    feq_gen_record_length_in_bytes_d_ = genscn_1.feq_gen_genscn_nout_d_ + 1 << 3;
/* SOURCE genscn.for:515 */
/*<       tsd_unit=get_unit(stdout) >*/
    genscn_1.feq_gen_tsd_unit_d_ = feq_gen_get_unit_d_(stdout);
/* SOURCE genscn.for:516 */
/*<        >*/
    feq_gen_o_d_1.oerr = 1;
    feq_gen_o_d_1.ounit = genscn_1.feq_gen_tsd_unit_d_;
    feq_gen_o_d_1.ofnmlen = 256;
    feq_gen_o_d_1.ofnm = feq_gen_tsd_name_d_;
    feq_gen_o_d_1.orl = feq_gen_record_length_in_bytes_d_;
    feq_gen_o_d_1.osta = const_cast<char*>("UNKNOWN");
    feq_gen_o_d_1.oacc = const_cast<char*>("DIRECT");
    feq_gen_o_d_1.ofm = const_cast<char*>("UNFORMATTED");
    feq_gen_o_d_1.oblnk = 0;
    ioflag = f_open(&feq_gen_o_d_1);
/* SOURCE genscn.for:520 */
/*<       if(ioflag.ne.0)then >*/
    if (ioflag != 0) {
/* SOURCE genscn.for:521 */
/*<       write(stdout,*)' Problem in opening file: ',tsd_name >*/
	feq_gen_io_d__70.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__70);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Problem in opening file: "), (ftnlen)26);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_tsd_name_d_, (ftnlen)256);
	e_wsle();
/* SOURCE genscn.for:522 */
/*<       write(stdout,*)' Check path for *.tsd file.' >*/
	feq_gen_io_d__71.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__71);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Check path for *.tsd file."), (ftnlen)27);
	e_wsle();
/* SOURCE genscn.for:523 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE genscn.for:524 */
/*<       endif >*/
    }
/* SOURCE genscn.for:526 */
/*<       return >*/
    return 0;
/* SOURCE genscn.for:528 */
/*<   991 continue >*/
L991:
/* SOURCE genscn.for:529 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__72.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__72);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE genscn.for:530 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__73.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__73);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)196);
    e_wsle();
/* SOURCE genscn.for:531 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE genscn.for:532 */
/*<       end >*/
    return 0;
} /* genscn_input__ */




/* SOURCE genscn.for:536 */
/*<       subroutinegenscn_close(stdout,termination) >*/
/* Subroutine */ int feq_gen_genscn_close_d_(integer *stdout, integer *termination)
{
    /* Format strings */
    static char fmt_56[] = "(\002 EYR EMN EDY    EHOUR          EJTIME      \
 EREC\002,/,i4,i4,i4,f9.5,f16.8,i11)";
    static char fmt_58[] = "(//,\002-TERMINATION\002,/,a8)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_free_unit_d_(integer *, integer *);
    real hr;
    integer mn, dy, yr, mjd;
    char feq_gen_term_nature_d_[8];
    doublereal dyfrac;
    extern /* Subroutine */ int invmjd_(integer *, integer *, integer *, 
	    integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__80 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__82 = { 0, 0, 0, fmt_58, 0 };


/*     Close the GENSCN system */
/* SOURCE genscn.for:540 */
/*<       implicitnone >*/
/* SOURCE genscn.for:541 */
/*<       integertermination,stdout >*/
/* INCLUDE genscn.for:544 */
/*     Common block for items needed for creating files for */
/*     GENSCN */
/* SOURCE genscn.cmn:4 */
/*<       integermngsout,mngsout2 >*/
/* SOURCE genscn.cmn:5 */
/*<       parameter(mngsout=20000,mngsout2=2*mngsout) >*/
/* SOURCE genscn.cmn:7 */
/*<       integerfeo_unit,tsd_unit,ftf_unit,genscn_nout,genscn_record_knt >*/
/* SOURCE genscn.cmn:10 */
/*<       integergenscn_pout(mngsout) >*/
/* SOURCE genscn.cmn:12 */
/*<       realgenscn_out_vec(mngsout2) >*/
/* SOURCE genscn.cmn:14 */
/*<       real*8genscn_jtime >*/
/* SOURCE genscn.cmn:16 */
/*<        >*/
/*     Local */
/* SOURCE genscn.for:547 */
/*<       character*8term_nature >*/
/* SOURCE genscn.for:549 */
/*<       integermjd,yr,mn,dy >*/
/* SOURCE genscn.for:551 */
/*<       realhr >*/
/* SOURCE genscn.for:553 */
/*<       real*8dyfrac >*/
/* SOURCE genscn.for:554 */
/*<       externalfree_unit,invmjd >*/
/*     **************************FORMATS********************************* */
/* SOURCE genscn.for:556 */
/*<    56  >*/
/* SOURCE genscn.for:560 */
/*<    58 format(//,'-TERMINATION',/,a8) >*/
/* *********************************************************************** */
/*     This routine will be called even if GENSCN has not been enabled. */
/* SOURCE genscn.for:564 */
/*<       if(feo_unit.gt.0)then >*/
/* L56: */
/* L58: */
    if (genscn_1.feq_gen_feo_unit_d_ > 0) {
/*       Construct the calander date from the last JTIME written to */
/*       the TSD file.  The current JTIME and date may not be the */
/*       same as the time point last written to the TSD file if */
/*       termination is abnormal. */
/* SOURCE genscn.for:571 */
/*<       mjd=int(genscn_jtime) >*/
	mjd = (integer) genscn_1.feq_gen_genscn_jtime_d_;
/* SOURCE genscn.for:572 */
/*<       dyfrac=genscn_jtime-dble(mjd) >*/
	dyfrac = genscn_1.feq_gen_genscn_jtime_d_ - (doublereal) mjd;
/* SOURCE genscn.for:573 */
/*<       hr=24.d0*dyfrac >*/
	hr = dyfrac * 24.;
/* SOURCE genscn.for:574 */
/*<       callinvmjd(mjd,yr,mn,dy) >*/
	invmjd_(&mjd, &yr, &mn, &dy);
/* SOURCE genscn.for:578 */
/*<       write(feo_unit,56)yr,mn,dy,hr,genscn_jtime,genscn_record_knt >*/
	feq_gen_io_d__80.ciunit = genscn_1.feq_gen_feo_unit_d_;
	s_wsfe(&feq_gen_io_d__80);
	do_fio(&feq_gen_c_d_1, (char *)&yr, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&mn, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&dy, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&hr, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&genscn_1.feq_gen_genscn_jtime_d_, (ftnlen)sizeof(
		doublereal));
	do_fio(&feq_gen_c_d_1, (char *)&genscn_1.feq_gen_genscn_record_knt_d_, (ftnlen)sizeof(
		integer));
	e_wsfe();
/*       Write the termination category */
/* SOURCE genscn.for:582 */
/*<       if(termination.eq.1)then >*/
	if (*termination == 1) {
/* SOURCE genscn.for:583 */
/*<       term_nature='NORMAL' >*/
	    s_copy(feq_gen_term_nature_d_, const_cast<char*>("NORMAL"), (ftnlen)8, (ftnlen)6);
/* SOURCE genscn.for:584 */
/*<       else >*/
	} else {
/* SOURCE genscn.for:585 */
/*<       term_nature='ABNORMAL' >*/
	    s_copy(feq_gen_term_nature_d_, const_cast<char*>("ABNORMAL"), (ftnlen)8, (ftnlen)8);
/* SOURCE genscn.for:586 */
/*<       endif >*/
	}
/* SOURCE genscn.for:587 */
/*<       write(feo_unit,58)term_nature >*/
	feq_gen_io_d__82.ciunit = genscn_1.feq_gen_feo_unit_d_;
	s_wsfe(&feq_gen_io_d__82);
	do_fio(&feq_gen_c_d_1, feq_gen_term_nature_d_, (ftnlen)8);
	e_wsfe();
/* SOURCE genscn.for:589 */
/*<       callfree_unit(stdout,feo_unit) >*/
	feq_gen_free_unit_d_(stdout, &genscn_1.feq_gen_feo_unit_d_);
/* SOURCE genscn.for:590 */
/*<       callfree_unit(stdout,tsd_unit) >*/
	feq_gen_free_unit_d_(stdout, &genscn_1.feq_gen_tsd_unit_d_);
/* SOURCE genscn.for:591 */
/*<       endif >*/
    }
/* SOURCE genscn.for:592 */
/*<       return >*/
    return 0;
/* SOURCE genscn.for:593 */
/*<       end >*/
} /* genscn_close__ */




/* SOURCE genscn.for:597 */
/*<       subroutineout_genscn(stdout,jtime,dz_for_output) >*/
/* Subroutine */ int feq_gen_out_genscn_d_(integer *stdout, doublereal *jtime, real *
	feq_gen_dz_for_output_d_)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wdue(cilist *), do_uio(integer *, char *, ftnlen), e_wdue();

    /* Local variables */
    integer feq_gen_i_d_, j, adr, ioff;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__86 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Write a record for the file used to define results for */
/*     later access using the GENSCN software */
/* SOURCE genscn.for:604 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE genscn.for:606 */
/*<       integerstdout >*/
/* SOURCE genscn.for:607 */
/*<       realdz_for_output >*/
/* SOURCE genscn.for:608 */
/*<       real*8jtime >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     JTIME - modified julian time. */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE genscn.for:613 */
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
/* INCLUDE genscn.for:614 */
/*     Miscellaneous control parameters */
/* SOURCE misccon.cmn:3 */
/*<       integerpagesp,pndflg >*/
/* SOURCE misccon.cmn:5 */
/*<        >*/
/* SOURCE misccon.cmn:8 */
/*<        >*/
/* INCLUDE genscn.for:615 */
/*     Common block for items needed for creating files for */
/*     GENSCN */
/* SOURCE genscn.cmn:4 */
/*<       integermngsout,mngsout2 >*/
/* SOURCE genscn.cmn:5 */
/*<       parameter(mngsout=20000,mngsout2=2*mngsout) >*/
/* SOURCE genscn.cmn:7 */
/*<       integerfeo_unit,tsd_unit,ftf_unit,genscn_nout,genscn_record_knt >*/
/* SOURCE genscn.cmn:10 */
/*<       integergenscn_pout(mngsout) >*/
/* SOURCE genscn.cmn:12 */
/*<       realgenscn_out_vec(mngsout2) >*/
/* SOURCE genscn.cmn:14 */
/*<       real*8genscn_jtime >*/
/* SOURCE genscn.cmn:16 */
/*<        >*/
/* INCLUDE genscn.for:616 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE genscn.for:617 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE genscn.for:618 */
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
/* INCLUDE genscn.for:619 */
/*     Common block for the names for gates.  Includes the */
/*     information needed to place the flow class and the current */
/*     gate opening in the special output file.  Start the GOPEN and */
/*     FCLASS at 0 to provide space for gates/pumps without a name. */
/*     We can then avoid an IF statement to see if we should store */
/*     something.  If no name is given the data goes into slot */
/*     zero and is never used!  FCLASS_CODE gives a unique numerical */
/*     code for each flow class string given in FCLASS. */
/*     Use slot MNGATE+1 for the McHenry gates. */
/* SOURCE gatcom.cmn:12 */
/*<       integerngate >*/
/* SOURCE gatcom.cmn:14 */
/*<       realgopen(0:mngate+1) >*/
/* SOURCE gatcom.cmn:16 */
/*<       integerfclass_code(0:mngate+1) >*/
/* SOURCE gatcom.cmn:18 */
/*<       charactergname(mngate+1)*16,fclass(0:mngate+1)*8 >*/
/*     FCLASS gives the flow class of the gate.  The meaning of this field */
/*     depends on the gate type and the kinds of flow that FEQ can report. */
/* SOURCE gatcom.cmn:24 */
/*<       common/gate1/ngate,gopen,fclass_code >*/
/* SOURCE gatcom.cmn:25 */
/*<       common/gate2/gname,fclass >*/
/* SOURCE gatcom.cmn:27 */
/*<       save/gate1/,/gate2/ >*/
/*      INCLUDE 'mhenry.cmn' */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE genscn.for:624 */
/*<       integeradr,i,j,ioff >*/
/*     + + + INTRINSICS + + + */
/* SOURCE genscn.for:627 */
/*<       intrinsicabs >*/
/* *********************************************************************** */
/*     Fill the vector for output. */
/* SOURCE genscn.for:631 */
/*<       do100i=1,genscn_nout >*/
    feq_gen_i_d_1 = genscn_1.feq_gen_genscn_nout_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE genscn.for:632 */
/*<       ioff=1+2*(i-1) >*/
	ioff = (feq_gen_i_d_ - 1 << 1) + 1;
/* SOURCE genscn.for:633 */
/*<       adr=genscn_pout(i) >*/
	adr = genscn_1.feq_gen_genscn_pout_d_[feq_gen_i_d_ - 1];
/* SOURCE genscn.for:634 */
/*<       if(adr.gt.0)goto90 >*/
	if (adr > 0) {
	    goto L90;
	}
/*          EXTERIOR NODE */
/* SOURCE genscn.for:636 */
/*<       adr=abs(adr) >*/
	adr = abs(adr);
/*           WRITE(STDOUT,*) ' ADR for exnode=',ADR */
/* SOURCE genscn.for:638 */
/*<       if(adr.lt.10000)then >*/
	if (adr < 10000) {
/*             WRITE(STDOUT,*) ' IOFF=',IOFF, 'Q=',QE1(ADR) */
/* SOURCE genscn.for:640 */
/*<       genscn_out_vec(ioff)=qe1(adr) >*/
	    genscn_1.feq_gen_genscn_out_vec_d_[ioff - 1] = enelem_1.qe1[adr - 1];
/* SOURCE genscn.for:641 */
/*<       genscn_out_vec(ioff+1)=ye1(adr)+ze(adr)+dz_for_output >*/
	    genscn_1.feq_gen_genscn_out_vec_d_[ioff] = static_cast<double>(static_cast<double>(enelem_1.ye1[adr - 1]) + 
		    enelem_1.ze[adr - 1]) + *feq_gen_dz_for_output_d_;
/* SOURCE genscn.for:642 */
/*<       elseif(adr.lt.20000)then >*/
	} else if (adr < 20000) {
/*            Tributary-area flow at an exterior node. */
/* SOURCE genscn.for:644 */
/*<       adr=adr-10000 >*/
	    adr += -10000;
/* SOURCE genscn.for:645 */
/*<       genscn_out_vec(ioff)=qpvec(adr) >*/
	    genscn_1.feq_gen_genscn_out_vec_d_[ioff - 1] = bnothr_1.qpvec[adr - 1];
/* SOURCE genscn.for:646 */
/*<       genscn_out_vec(ioff+1)=1.0 >*/
	    genscn_1.feq_gen_genscn_out_vec_d_[ioff] = (float)1.;
/* SOURCE genscn.for:647 */
/*<       elseif(adr.eq.20000)then >*/
	} else if (adr == 20000) {
/*            MCHENRY SLUICE GATE */
/*            REPORT FLOW TYPE AND GATE OPENING. */
/* SOURCE genscn.for:650 */
/*<       genscn_out_vec(ioff)=fclass_code(mngate+1) >*/
	    genscn_1.feq_gen_genscn_out_vec_d_[ioff - 1] = (real) 
		    gate1_1.feq_gen_fclass_code_d_[51];
/* SOURCE genscn.for:651 */
/*<       genscn_out_vec(ioff+1)=gopen(mngate+1) >*/
	    genscn_1.feq_gen_genscn_out_vec_d_[ioff] = gate1_1.gopen[51];
/* SOURCE genscn.for:652 */
/*<       else >*/
	} else {
/*            Gates/pumps other than McHenry.   Get items from standard */
/*            locations set by subroutines called in SETEXT. */
/* SOURCE genscn.for:655 */
/*<       adr=adr-20000 >*/
	    adr += -20000;
/* SOURCE genscn.for:656 */
/*<       genscn_out_vec(ioff)=fclass_code(adr) >*/
	    genscn_1.feq_gen_genscn_out_vec_d_[ioff - 1] = (real) 
		    gate1_1.feq_gen_fclass_code_d_[adr];
/* SOURCE genscn.for:657 */
/*<       genscn_out_vec(ioff+1)=gopen(adr) >*/
	    genscn_1.feq_gen_genscn_out_vec_d_[ioff] = gate1_1.gopen[adr];
/* SOURCE genscn.for:658 */
/*<       endif >*/
	}
/* SOURCE genscn.for:659 */
/*<       goto100 >*/
	goto L100;
/* SOURCE genscn.for:660 */
/*<    90 continue >*/
L90:
/* SOURCE genscn.for:661 */
/*<       if(adr.lt.10000)then >*/
	if (adr < 10000) {
/* SOURCE genscn.for:662 */
/*<       genscn_out_vec(ioff)=q1(adr) >*/
	    genscn_1.feq_gen_genscn_out_vec_d_[ioff - 1] = bnelem_1.q1[adr - 1];
/* SOURCE genscn.for:663 */
/*<       genscn_out_vec(ioff+1)=y1(adr)+zvec(adr) >*/
	    genscn_1.feq_gen_genscn_out_vec_d_[ioff] = static_cast<double>(bnelem_1.y1[adr - 1]) + 
		    bnelem_1.zvec[adr - 1];
/* SOURCE genscn.for:664 */
/*<       else >*/
	} else {
/*         Tributrary-area flow at for an element on a branch. */
/* SOURCE genscn.for:666 */
/*<       adr=adr-10000 >*/
	    adr += -10000;
/* SOURCE genscn.for:667 */
/*<       genscn_out_vec(ioff)=qpvec(adr) >*/
	    genscn_1.feq_gen_genscn_out_vec_d_[ioff - 1] = bnothr_1.qpvec[adr - 1];
/* SOURCE genscn.for:668 */
/*<       genscn_out_vec(ioff+1)=1.0 >*/
	    genscn_1.feq_gen_genscn_out_vec_d_[ioff] = (float)1.;
/* SOURCE genscn.for:669 */
/*<       endif >*/
	}
/* SOURCE genscn.for:670 */
/*<   100 continue >*/
L100:
	;
    }
/* SOURCE genscn.for:671 */
/*<       genscn_record_knt=genscn_record_knt+1 >*/
    ++genscn_1.feq_gen_genscn_record_knt_d_;
/* SOURCE genscn.for:672 */
/*<       genscn_jtime=jtime >*/
    genscn_1.feq_gen_genscn_jtime_d_ = *jtime;
/* SOURCE genscn.for:673 */
/*<        >*/
    feq_gen_io_d__86.ciunit = genscn_1.feq_gen_tsd_unit_d_;
    feq_gen_io_d__86.cirec = genscn_1.feq_gen_genscn_record_knt_d_;
    s_wdue(&feq_gen_io_d__86);
    do_uio(&feq_gen_c_d_1, (char *)&(*jtime), (ftnlen)sizeof(doublereal));
    feq_gen_i_d_1 = ioff + 1;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
	do_uio(&feq_gen_c_d_1, (char *)&genscn_1.feq_gen_genscn_out_vec_d_[j - 1], (ftnlen)
		sizeof(real));
    }
    e_wdue();
/* SOURCE genscn.for:675 */
/*<       return >*/
    return 0;
/* SOURCE genscn.for:676 */
/*<       end >*/
} /* out_genscn__ */




/* SOURCE genscn.for:680 */
/*<       integerfunctionget_source(adr) >*/
integer feq_gen_get_source_d_(integer *adr)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

/*     Get the source flag for the cross section table at address, ADR. */
/* SOURCE genscn.for:685 */
/*<       integeradr >*/
/* INCLUDE genscn.for:687 */
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
/* INCLUDE genscn.for:688 */
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
/* *********************************************************************** */
/* SOURCE genscn.for:690 */
/*<       get_source=itab(adr+20) >*/
    ret_val = itab[*adr + 20];
/* SOURCE genscn.for:691 */
/*<       return >*/
    return ret_val;
/* SOURCE genscn.for:692 */
/*<       end >*/
} /* get_source__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE genscn.for:697 */
/*<        >*/
/* Subroutine */ int feq_gen_genscn_input_new_d_(integer *stdin, integer *stdout, 
	integer *feq_storage_brpt, integer *feq_storage_exnodt, integer *nbra, integer *nbn, integer *
	nex, integer *nrwta, integer *feq_storage_rwta, integer *feq_storage_rtap, real *sfac, 
	integer *ftp, char *feq_gen_new_genscn_feo_d_, integer *eflag, ftnlen 
	new_genscn_feo_len)
{
    /* Initialized data */

    static char feq_gen_class_table_d_[16*11+1] = "ALL_NODES       ALL_BRANCHES    AL\
L_EXN         INTERPOLATED    INPUT_XSEC      FREE_NODES      LPR_NODES     \
  LPR_INFLOW      BRANCH_EXN      DUMMY_BRANCHES  NONE            ";
    static integer feq_gen_class_value_d_[11] = { 1,2,3,4,5,6,7,8,9,10,11 };
    static char feq_gen_gp_status_d_[8*13+1] = "SW      FW      No Flow Closed  Open \
   Max OpenOff     No H2O  FP      SP      FO      SO      OR      ";

    /* Format strings */
    static char fmt_2[] = "(a)";
    static char fmt_5[] = "(a5,i5,1x,a16)";
    static char fmt_4[] = "(\002 \002,a)";
    static char fmt_6[] = "(\002 \002,a5,i5,1x,a16)";
    static char fmt_7[] = "(\002 *ERR:147* Output requested at too many node\
s. NOUT = \002,i5)";
    static char fmt_50[] = "(\002-VERSION\002,/,\002FEQ:\002,f5.2)";
    static char fmt_51[] = "(\002 *ERR:172* Exterior node\002,a5,\002 does n\
ot have trib.\002,\002 area or is not a reservoir.\002)";
    static char fmt_52[] = "(a)";
    static char fmt_53[] = "(//,\002-FILES\002)";
    static char fmt_54[] = "(//,\002-UNITS\002,/,\002STATION_UNIT_NAME= mile\
s               \002,/,\002ELEVATION_UNIT_NAME= feet              \002,/,\
\002FLOW_UNIT_NAME= Cubic feet per second  \002,/,\002GATE_OPENING_UNIT_NAME\
= feet           \002,/,\002STORAGE_UNIT_NAME= acre-feet           \002,/\
,\002STORAGE_UNIT_FACTOR=2.295684E-5        \002,/,\002SURFACE_AREA_UNIT_NAM\
E=square miles    \002,/,\002SURFACE_AREA_FACTOR=3.587006e-8        \002)";
    static char fmt_55[] = "(//,\002-GATE_PUMP_STATUS\002,/,\002 Code String\
--\002)";
    static char fmt_56[] = "(//,\002-TSD\002,/\002LOCATION_KNT=\002,i8,/,\
\002 SYR SMN SDY    SHOUR          SJTIME       SREC\002,/,i4,i4,i4,f9.5,f16\
.8,i11)";
    static char fmt_57[] = "(i5,1x,a8)";
    static char fmt_58[] = "(//,\002-TSDDIR\002,/,\002              FEQ Loct\
n  Bran    Node         Station\002,\002     Invert           UserId     FTA\
B   Series\002,\002     Easting      Northing\002,/,\002            Label Cl\
ass   #        Id                \002,\002  Elevation           String    In\
dex   Offset\002,\002                          \002,/,\002 ---------------- \
----- ----- ------- ---------------\002,\002 ---------- ---------------- ---\
----- --------\002,\002 ------------ ------------\002)";
    static char fmt_59[] = "(//,\002-FILE_FORMAT\002,/,\002 2\002,//,\002-FI\
LES\002)";
    static char fmt_60[] = "(//,\002-SVN\002,/,\002Source code repository lo\
cation and revision are:\002)";
    static char fmt_68[] = "(/,\002 *WRN:58* No home name found following HO\
ME=. \002,\002 Home name cleared.\002)";
    static char fmt_69[] = "(/,\002 Home directory/drive is: \002,a)";
    static char fmt_70[] = "(1x,a16,1x,a5,1x,i5,1x,a7,1x,1pe15.6,1x,0pf10.4,\
1x,a16,1x,i8,1x,i8,1x,a12,1x,a12)";
    static char fmt_72[] = "(1x,8x,1x,5x,1x,\002   -1\002)";
    static char fmt_74[] = "(//\002-FTF\002,/,\002NUMBER_OF_FULL_RECORDS=\
\002,i8,/,\002ITEMS_PER_RECORD=\002,i8,/,\002LEFTOVER_ITEM_KNT=\002,i8)";
    static char fmt_75[] = "(/,\002 The file names for  GENSCN transfer are\
:\002)";
    static char fmt_76[] = "(/,\002 *ERR:372* GENSCN expected: FILE but foun\
d: \002,a4)";
    static char fmt_77[] = "(/,\002 *ERR:373* Option= \002,a3,\002 unknown\
.\002,\002  ADD and SUB are known.\002)";
    static char fmt_78[] = "(/,\002 *ERR:374* Node class= \002,a16,\002 unkn\
own in GENSCN output.\002)";
    static char fmt_79[] = "(/,\002 Node class: \002,a16,\002 not implemente\
d.\002)";
    static char fmt_80[] = "(/,\002 Adding nodes in class: \002,a,\002 to GE\
NSCN output.\002)";
    static char fmt_81[] = "(/,\002 Subtracting nodes in class: \002,a,\002 \
from \002,\002GENSCN output.\002)";
    static char fmt_82[] = "(/,\002 Node class operations completed.  \002\
,\002Seeking item-level instructions.\002)";
    static char fmt_83[] = "(/,\002 GENSCN output requested at \002,i5,\002 \
nodes.\002)";
    static char fmt_86[] = "(\002Version number is \002,i8,\002 for the Subv\
ersion working \002,\002copy\002)";
    static char fmt_87[] = "(\002*WRN:XXX* The working copy contains local\
 \002,\002modifications.\002,/,5x,\002The version number given is therefor\
e\002,\002 not current and may not properly\002,/,5x,\002provide the versio\
n\002,\002 number required to retrieve all the same files \002,\002at a late\
r time.\002)";
    static char fmt_88[] = "(//,\002-TSDDIR\002,/,\002      FEQ LOCTN BRAN  \
 NODE         STATION     INVERT \002,\002       USERID\002,\002     FTAB   \
Series\002,/,\002    LABEL CLASS   #      ID                   ELEVATION\002,\
\002       STRING\002,\002    index   offset\002,/,\002 -------- ----- -----\
  ----- --------------- ----------\002,\002 ------------\002,\002 -------- -\
-------\002)";
    static char fmt_90[] = "(1x,a8,1x,a5,1x,i5,1x,a6,1x,1pe15.6,1x,0pf10.4,1\
x,a12,1x,i8,1x,i8)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;
    olist feq_gen_o_d_1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), i_indx(char *, char *, 
	    ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), s_rsfi(icilist *), e_rsfi();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer f_open(olist *), s_wsle(cilist *), do_lio(integer *, integer *, 
	    char *, ftnlen), e_wsle(), s_wsfi(icilist *), e_wsfi();

    /* Local variables */
    char feq_gen_feo_name_d_[256], feq_gen_ftf_name_d_[256], feq_gen_tsd_name_d_[256];
    extern integer feq_gen_get_unit_d_(integer *);
    doublereal northing;
    integer feq_gen_items_per_record_d_, feq_gen_i_d_, j;
    doublereal x, y;
    integer feq_gen_bnode_bra_d_[8400];
    real feq_gen_invert_elevation_d_;
    integer feq_gen_enode_bra_d_[8400];
    char feq_gen_node_item_d_[16];
    extern /* Subroutine */ int feq_gen_free_unit_d_(integer *, integer *);
    integer feq_gen_tsd_start_d_, fa, ii, fn, ip, ln, it, feq_gen_leftover_item_knt_d_, 
	    feq_gen_bnode_flag_d_[8400], feq_gen_enode_flag_d_[8400];
    extern /* Subroutine */ int feq_gen_clear_home_d_();
    integer feq_gen_ftab_index_d_;
    char feq_gen_node_class_d_[16];
    integer feq_gen_ftab_dummy_d_;
    extern /* Subroutine */ int feq_gen_write_ftfa_d_(integer *, integer *, integer *, 
	    integer *, integer *, integer *);
    extern integer feq_gen_get_source_d_(integer *);
    char eaststring[12];
    integer bra, nde;
    extern /* Subroutine */ int kil_(integer *, integer *, integer *);
    integer nxt;
    extern /* Subroutine */ int feq_gen_maybe_add_ghome_out_d_(char *, ftnlen);
    char opt5[5], head[196];
    integer ibra;
    char northstring[12], feq_gen_name_d_[256];
    integer node;
    char line[196];
    integer null;
    char char4[4], char5[5], char7[7];
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);
    integer feq_gen_gate_pump_ip_d_[51], brain, feq_gen_class_d_;
    extern /* Subroutine */ int lstab_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), feq_gen_maybe_add_ext_d_(char *, ftnlen), feq_gen_os_file_style_d_(
	    char *, ftnlen);
    integer ioflag;
    char feq_gen_user_id_string_d_[16], feq_gen_location_class_d_[5], option[3], 
	    feq_gen_gate_pump_name_d_[16*51];
    integer addflag, feq_gen_gate_pump_flag_d_[51];
    extern integer lenstr_(char *, ftnlen);
    extern doublereal feq_gen_get_dp_from_ft_d_(integer *);
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen), inline_(
	    integer *, integer *, char *, ftnlen), nxttok_(char *, integer *, 
	    char *, ftnlen, ftnlen), getinn_(char *, integer *, integer *, 
	    ftnlen), getinb_(integer *, integer *, integer *);
    integer feq_gen_record_length_in_bytes_d_, feq_gen_number_of_full_records_d_;
    doublereal easting;
    real station;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__98 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__99 = { 0, 0, 0, fmt_69, 0 };
    static cilist feq_gen_io_d__106 = { 0, 0, 0, fmt_75, 0 };
    static cilist feq_gen_io_d__107 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__109 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__110 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__111 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__112 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__113 = { 0, 0, 0, fmt_59, 0 };
    static cilist feq_gen_io_d__114 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__115 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__116 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__117 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__118 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__119 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__120 = { 0, 0, 0, fmt_87, 0 };
    static cilist feq_gen_io_d__121 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__122 = { 0, 0, 0, fmt_57, 0 };
    static cilist feq_gen_io_d__123 = { 0, 0, 0, fmt_57, 0 };
    static cilist feq_gen_io_d__125 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__126 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__130 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__138 = { 0, 0, 0, fmt_77, 0 };
    static cilist feq_gen_io_d__141 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__142 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__143 = { 0, 0, 0, fmt_81, 0 };
    static cilist feq_gen_io_d__144 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__151 = { 0, 0, 0, fmt_79, 0 };
    static cilist feq_gen_io_d__152 = { 0, 0, 0, fmt_79, 0 };
    static cilist feq_gen_io_d__154 = { 0, 0, 0, fmt_4, 0 };
    static cilist feq_gen_io_d__155 = { 0, 0, 0, fmt_88, 0 };
    static cilist feq_gen_io_d__156 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__160 = { 0, 0, 0, fmt_6, 0 };
    static cilist feq_gen_io_d__161 = { 0, 0, 0, fmt_77, 0 };
    static cilist feq_gen_io_d__165 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__171 = { 0, 0, 0, fmt_7, 0 };
    static cilist feq_gen_io_d__182 = { 0, 0, 0, fmt_90, 0 };
    static cilist feq_gen_io_d__183 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__184 = { 0, 0, 0, fmt_7, 0 };
    static cilist feq_gen_io_d__187 = { 0, 0, 0, fmt_90, 0 };
    static cilist feq_gen_io_d__188 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__189 = { 0, 0, 0, fmt_7, 0 };
    static cilist feq_gen_io_d__190 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__191 = { 0, 0, 0, fmt_83, 0 };
    static cilist feq_gen_io_d__192 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__194 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__195 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__196 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__197 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__198 = { 0, 0, 0, 0, 0 };


/*     Process the specification for the GENSCN data. */
/*     Revised input using node classes to specify nodes in addition */
/*     to using an itemized list. */
/* SOURCE genscn.for:706 */
/*<       implicitnone >*/
/* INCLUDE genscn.for:708 */
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
/* SOURCE genscn.for:710 */
/*<       characternew_genscn_feo*4 >*/
/* SOURCE genscn.for:712 */
/*<       integereflag,stdin,stdout,nbn,nbra,nrwta,ftp,nex >*/
/* SOURCE genscn.for:714 */
/*<       integerbrpt(8,nbra),exnodt(9,nex),rtap(mnfree),rwta(mnfree) >*/
/* SOURCE genscn.for:717 */
/*<       realsfac >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
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
/*     NBRA   - number of branches in the model */
/*     NBN    - number of nodes on branches */
/*     NEX    - number of exterior nodes */
/*     NRWTA  - number of reservoirs with tributary area */
/*     RWTA   - reservoirs with tributary area */
/*     RTAP   - reservoir tributary area pointer */
/*     SFAC   - station factor for branches. */
/*     FTP    - pointer to next open location in FTAB/ITAB function */
/*              table storage vector. */
/* INCLUDE genscn.for:785 */
/*     Common block for items needed for creating files for */
/*     GENSCN */
/* SOURCE genscn.cmn:4 */
/*<       integermngsout,mngsout2 >*/
/* SOURCE genscn.cmn:5 */
/*<       parameter(mngsout=20000,mngsout2=2*mngsout) >*/
/* SOURCE genscn.cmn:7 */
/*<       integerfeo_unit,tsd_unit,ftf_unit,genscn_nout,genscn_record_knt >*/
/* SOURCE genscn.cmn:10 */
/*<       integergenscn_pout(mngsout) >*/
/* SOURCE genscn.cmn:12 */
/*<       realgenscn_out_vec(mngsout2) >*/
/* SOURCE genscn.cmn:14 */
/*<       real*8genscn_jtime >*/
/* SOURCE genscn.cmn:16 */
/*<        >*/
/* INCLUDE genscn.for:786 */
/*     Miscellaneous control parameters */
/* SOURCE misccon.cmn:3 */
/*<       integerpagesp,pndflg >*/
/* SOURCE misccon.cmn:5 */
/*<        >*/
/* SOURCE misccon.cmn:8 */
/*<        >*/
/* INCLUDE genscn.for:787 */
/* ********************************************************************** */
/* SOURCE julian.cmn:3 */
/*<        >*/
/* SOURCE julian.cmn:8 */
/*<       integeryr,mn,dy,syr,smn,sdy,eyr,emn,edy,reset,leap,dmyear,dmmn >*/
/* SOURCE julian.cmn:10 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE genscn.for:788 */
/*     Common block for the names for gates.  Includes the */
/*     information needed to place the flow class and the current */
/*     gate opening in the special output file.  Start the GOPEN and */
/*     FCLASS at 0 to provide space for gates/pumps without a name. */
/*     We can then avoid an IF statement to see if we should store */
/*     something.  If no name is given the data goes into slot */
/*     zero and is never used!  FCLASS_CODE gives a unique numerical */
/*     code for each flow class string given in FCLASS. */
/*     Use slot MNGATE+1 for the McHenry gates. */
/* SOURCE gatcom.cmn:12 */
/*<       integerngate >*/
/* SOURCE gatcom.cmn:14 */
/*<       realgopen(0:mngate+1) >*/
/* SOURCE gatcom.cmn:16 */
/*<       integerfclass_code(0:mngate+1) >*/
/* SOURCE gatcom.cmn:18 */
/*<       charactergname(mngate+1)*16,fclass(0:mngate+1)*8 >*/
/*     FCLASS gives the flow class of the gate.  The meaning of this field */
/*     depends on the gate type and the kinds of flow that FEQ can report. */
/* SOURCE gatcom.cmn:24 */
/*<       common/gate1/ngate,gopen,fclass_code >*/
/* SOURCE gatcom.cmn:25 */
/*<       common/gate2/gname,fclass >*/
/* SOURCE gatcom.cmn:27 */
/*<       save/gate1/,/gate2/ >*/
/* INCLUDE genscn.for:789 */
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
/* INCLUDE genscn.for:790 */
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
/* INCLUDE genscn.for:791 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE genscn.for:792 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE genscn.for:793 */
/*     Common block to allow version and date to be output */
/*     at more than one point in the code. */
/* SOURCE version.cmn:4 */
/*<       characterversion_date*17 >*/
/* SOURCE version.cmn:6 */
/*<       realversion_number >*/
/* SOURCE version.cmn:8 */
/*<       common/version/version_number >*/
/* SOURCE version.cmn:10 */
/*<       common/versionc/version_date >*/
/* INCLUDE genscn.for:794 */
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

/* INCLUDE genscn.for:795 */
/*     Values of local and global home directory names */
/* 	7 dec 2005:  Add an output extension value */
/* SOURCE home.cmn:3 */
/*<       character*128stdext >*/
/* SOURCE home.cmn:4 */
/*<       character*128home,ghome,ghome_out >*/
/* SOURCE home.cmn:5 */
/*<       common/homec/home,ghome,ghome_out,stdext >*/
/* SOURCE home.cmn:6 */
/*<       save/homec/ >*/
/* INCLUDE genscn.for:796 */
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
/*     Local variables. */
/* SOURCE genscn.for:799 */
/*<       integern_class,n_gp_status >*/
/* SOURCE genscn.for:800 */
/*<       parameter(n_class=11,n_gp_status=13) >*/
/* SOURCE genscn.for:802 */
/*<        >*/
/* SOURCE genscn.for:810 */
/*<        >*/
/* SOURCE genscn.for:816 */
/*<        >*/
/* SOURCE genscn.for:820 */
/*<       realstation,invert_elevation >*/
/* SOURCE genscn.for:821 */
/*<       real*8easting,northing,x,y >*/
/* SOURCE genscn.for:824 */
/*<       integerget_source,get_unit,lenstr >*/
/* SOURCE genscn.for:825 */
/*<       charactergettok*5 >*/
/* SOURCE genscn.for:826 */
/*<       real*8get_dp_from_ft >*/
/* SOURCE genscn.for:828 */
/*<        >*/
/*     Set the gate/pump status values.  Used to label points of pump speed and */
/*     gate opening or structure opening. */
/*     ***************************FORMATS******************************** */
/* SOURCE genscn.for:697 */
/*<       integer feq_len_trim >*/
/* SOURCE genscn.for:697 */
/*<       external feq_len_trim >*/
/* SOURCE genscn.for:832 */
/*<        >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> rwta(feq_storage_rwta, 1);

    feq::IndexedPointer<integer> rtap(feq_storage_rtap, 1);

    /* Function Body */
/* SOURCE genscn.for:837 */
/*<       dataclass_value/1,2,3,4,5,6,7,8,9,10,11/ >*/
/* SOURCE genscn.for:842 */
/*<        >*/
/* SOURCE genscn.for:846 */
/*<     2 format(a) >*/
/* L2: */
/* 3    FORMAT(A) */
/* SOURCE genscn.for:849 */
/*<     5 format(a5,i5,1x,a16) >*/
/* L5: */
/* SOURCE genscn.for:851 */
/*<     4 format(' ',a) >*/
/* L4: */
/* SOURCE genscn.for:852 */
/*<     6 format(' ',a5,i5,1x,a16) >*/
/* L6: */
/* SOURCE genscn.for:853 */
/*<     7  >*/
/* L7: */
/* SOURCE genscn.for:856 */
/*<    50 format('-VERSION',/,'FEQ:',f5.2) >*/
/* L50: */
/* SOURCE genscn.for:857 */
/*<    51  >*/
/* L51: */
/* SOURCE genscn.for:859 */
/*<    52 format(a) >*/
/* L52: */
/* SOURCE genscn.for:861 */
/*<    53 format(//,'-FILES') >*/
/* L53: */
/* SOURCE genscn.for:862 */
/*<    54  >*/
/* L54: */
/* SOURCE genscn.for:872 */
/*<    55 format(//,'-GATE_PUMP_STATUS',/,' Code String--') >*/
/* L55: */
/* SOURCE genscn.for:873 */
/*<    56  >*/
/* L56: */
/*     D       ' EYR EMN EDY    EHOUR          EJTIME       EREC',/, */
/*     E       I4,I4,I4,F9.5,F16.8,I11) */
/* SOURCE genscn.for:880 */
/*<    57 format(i5,1x,a8) >*/
/* L57: */
/* 58    FORMAT(//,'-TSDDIR',/, */
/*     A'      FEQ LOCTN BRAN   NODE         STATION     INVERT ', */
/*     A'       USERID', */
/*     B'     FTAB   Series',/, */
/*     C'    LABEL CLASS   #      ID                   ELEVATION', */
/*     C'       STRING', */
/*     D'    index   offset',/, */
/*     E' -------- ----- -----  ----- --------------- ----------', */
/*     E' ------------', */
/*     F' -------- --------') */
/* SOURCE genscn.for:891 */
/*<    58  >*/
/* L58: */
/* SOURCE genscn.for:901 */
/*<    59 format(//,'-FILE_FORMAT',/,' 2',//,'-FILES') >*/
/* L59: */
/* SOURCE genscn.for:902 */
/*<    60  >*/
/* L60: */
/* SOURCE genscn.for:904 */
/*<    68  >*/
/* L68: */
/* SOURCE genscn.for:906 */
/*<    69 format(/,' Home directory/drive is: ',a) >*/
/* L69: */
/* 70    FORMAT(1X,A8,1X,A5,1X,I5,1X,A6,1X,1PE15.6,1X,0PF10.4,1X,A12,1X, */
/*     A I8,1X,I8) */
/* SOURCE genscn.for:909 */
/*<    70  >*/
/* L70: */
/* SOURCE genscn.for:911 */
/*<    72 format(1x,8x,1x,5x,1x,'   -1') >*/
/* L72: */
/* SOURCE genscn.for:912 */
/*<    74  >*/
/* L74: */
/* SOURCE genscn.for:916 */
/*<    75 format(/,' The file names for  GENSCN transfer are:') >*/
/* L75: */
/* SOURCE genscn.for:917 */
/*<    76 format(/,' *ERR:372* GENSCN expected: FILE but found: ',a4) >*/
/* L76: */
/* SOURCE genscn.for:918 */
/*<    77  >*/
/* L77: */
/* SOURCE genscn.for:920 */
/*<    78  >*/
/* L78: */
/* SOURCE genscn.for:922 */
/*<    79 format(/,' Node class: ',a16,' not implemented.') >*/
/* L79: */
/* SOURCE genscn.for:923 */
/*<    80 format(/,' Adding nodes in class: ',a,' to GENSCN output.') >*/
/* L80: */
/* SOURCE genscn.for:924 */
/*<    81  >*/
/* L81: */
/* SOURCE genscn.for:926 */
/*<    82  >*/
/* L82: */
/* SOURCE genscn.for:928 */
/*<    83 format(/,' GENSCN output requested at ',i5,' nodes.') >*/
/* L83: */
/* SOURCE genscn.for:929 */
/*<    86  >*/
/* L86: */
/* SOURCE genscn.for:931 */
/*<    87  >*/
/* L87: */
/* SOURCE genscn.for:938 */
/*<    88  >*/
/* L88: */
/* SOURCE genscn.for:948 */
/*<    90  >*/
/* L90: */
/* ********************************************************************* */
/* SOURCE genscn.for:951 */
/*<       null=-2147483647 >*/
    null = -2147483647;
/* SOURCE genscn.for:952 */
/*<       callclear_home() >*/
    feq_gen_clear_home_d_();
/* SOURCE genscn.for:953 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)196);
/* SOURCE genscn.for:956 */
/*<       callstrip_l_blanks(line) >*/
    feq_gen_strip_l_blanks_d_(line, (ftnlen)196);
/* SOURCE genscn.for:958 */
/*<       if(line(1:4).eq.'HOME'.or.line(1:4).eq.'home')then >*/
    if (s_cmp(line, const_cast<char*>("HOME"), (ftnlen)4, (ftnlen)4) == 0 || s_cmp(line, const_cast<char*>("home"), 
	    (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE genscn.for:959 */
/*<       it=index(line,'=') >*/
	it = i_indx(line, const_cast<char*>("="), (ftnlen)196, (ftnlen)1);
/* SOURCE genscn.for:960 */
/*<       nxt=it+1 >*/
	nxt = it + 1;
/* SOURCE genscn.for:961 */
/*<       callnxttok(line,nxt,home) >*/
	nxttok_(line, &nxt, homec_1.home, (ftnlen)196, (ftnlen)128);
/* SOURCE genscn.for:965 */
/*<       if(nxt.le.0)then >*/
	if (nxt <= 0) {
/* SOURCE genscn.for:966 */
/*<       write(stdout,68) >*/
	    feq_gen_io_d__98.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__98);
	    e_wsfe();
/* SOURCE genscn.for:967 */
/*<       home=' ' >*/
	    s_copy(homec_1.home, const_cast<char*>(" "), (ftnlen)128, (ftnlen)1);
/* SOURCE genscn.for:968 */
/*<       endif >*/
	}
/* SOURCE genscn.for:969 */
/*<       callstrip_l_blanks(home) >*/
	feq_gen_strip_l_blanks_d_(homec_1.home, (ftnlen)128);
/* SOURCE genscn.for:971 */
/*<       it=feq_len_trim(home) >*/
	it = feq_gen_feq_len_trim_d_(homec_1.home, (ftnlen)128);
/* SOURCE genscn.for:972 */
/*<       write(stdout,69)home(1:it) >*/
	feq_gen_io_d__99.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__99);
	do_fio(&feq_gen_c_d_1, homec_1.home, it);
	e_wsfe();
/* SOURCE genscn.for:974 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)196);
/* SOURCE genscn.for:977 */
/*<       endif >*/
    }
/*     Input the main file name.  Extensions added here. */
/*      CALL inline */
/*     I          (STDIN, STDOUT, */
/*     O           LINE) */
/*      CALL STRIP_L_BLANKS( */
/*     M                    LINE) */
/* SOURCE genscn.for:986 */
/*<       read(line,'(A4)')char4 >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 196;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(A4)");
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, char4, (ftnlen)4);
    e_rsfi();
/* SOURCE genscn.for:987 */
/*<       if(char4.eq.'FILE')then >*/
    if (s_cmp(char4, const_cast<char*>("FILE"), (ftnlen)4, (ftnlen)4) == 0) {
/*       Looks ok */
/* SOURCE genscn.for:989 */
/*<       read(line,'(4X,A)')name >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 196;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(4X,A)");
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)256);
	e_rsfi();
/* SOURCE genscn.for:990 */
/*<       callstrip_l_blanks(name) >*/
	feq_gen_strip_l_blanks_d_(feq_gen_name_d_, (ftnlen)256);
/* SOURCE genscn.for:992 */
/*<       if(name(1:1).eq.'=')then >*/
	if (*(unsigned char *)feq_gen_name_d_ == '=') {
/* SOURCE genscn.for:993 */
/*<       name(1:1)=' ' >*/
	    *(unsigned char *)feq_gen_name_d_ = ' ';
/* SOURCE genscn.for:994 */
/*<       callstrip_l_blanks(name) >*/
	    feq_gen_strip_l_blanks_d_(feq_gen_name_d_, (ftnlen)256);
/* SOURCE genscn.for:996 */
/*<       endif >*/
	}
/* SOURCE genscn.for:997 */
/*<       i=lenstr(name) >*/
	feq_gen_i_d_ = lenstr_(feq_gen_name_d_, (ftnlen)256);
/*       Now create the three file names. */
/* SOURCE genscn.for:999 */
/*<       feo_name=name(1:i) >*/
	s_copy(feq_gen_feo_name_d_, feq_gen_name_d_, (ftnlen)256, feq_gen_i_d_);
/* SOURCE genscn.for:1000 */
/*<       feo_name(i+1:)='.feo' >*/
	feq_gen_i_d_1 = feq_gen_i_d_;
	s_copy(feq_gen_feo_name_d_ + feq_gen_i_d_1, const_cast<char*>(".feo"), 256 - feq_gen_i_d_1, (ftnlen)4);
/* SOURCE genscn.for:1001 */
/*<       tsd_name=name(1:i) >*/
	s_copy(feq_gen_tsd_name_d_, feq_gen_name_d_, (ftnlen)256, feq_gen_i_d_);
/* SOURCE genscn.for:1002 */
/*<       tsd_name(i+1:)='.tsd' >*/
	feq_gen_i_d_1 = feq_gen_i_d_;
	s_copy(feq_gen_tsd_name_d_ + feq_gen_i_d_1, const_cast<char*>(".tsd"), 256 - feq_gen_i_d_1, (ftnlen)4);
/* SOURCE genscn.for:1003 */
/*<       ftf_name=name(1:i) >*/
	s_copy(feq_gen_ftf_name_d_, feq_gen_name_d_, (ftnlen)256, feq_gen_i_d_);
/* SOURCE genscn.for:1004 */
/*<       ftf_name(i+1:)='.ftf' >*/
	feq_gen_i_d_1 = feq_gen_i_d_;
	s_copy(feq_gen_ftf_name_d_ + feq_gen_i_d_1, const_cast<char*>(".ftf"), 256 - feq_gen_i_d_1, (ftnlen)4);
/* SOURCE genscn.for:1006 */
/*<       callmaybe_add_ghome_out(feo_name) >*/
	feq_gen_maybe_add_ghome_out_d_(feq_gen_feo_name_d_, (ftnlen)256);
/* SOURCE genscn.for:1008 */
/*<       callmaybe_add_ext(feo_name) >*/
	feq_gen_maybe_add_ext_d_(feq_gen_feo_name_d_, (ftnlen)256);
/* SOURCE genscn.for:1010 */
/*<       callmaybe_add_ghome_out(tsd_name) >*/
	feq_gen_maybe_add_ghome_out_d_(feq_gen_tsd_name_d_, (ftnlen)256);
/* SOURCE genscn.for:1012 */
/*<       callmaybe_add_ext(tsd_name) >*/
	feq_gen_maybe_add_ext_d_(feq_gen_tsd_name_d_, (ftnlen)256);
/* SOURCE genscn.for:1014 */
/*<       callmaybe_add_ghome_out(ftf_name) >*/
	feq_gen_maybe_add_ghome_out_d_(feq_gen_ftf_name_d_, (ftnlen)256);
/* SOURCE genscn.for:1016 */
/*<       callmaybe_add_ext(ftf_name) >*/
	feq_gen_maybe_add_ext_d_(feq_gen_ftf_name_d_, (ftnlen)256);
/* SOURCE genscn.for:1019 */
/*<       write(stdout,75) >*/
	feq_gen_io_d__106.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__106);
	e_wsfe();
/* SOURCE genscn.for:1020 */
/*<       callos_file_style(feo_name) >*/
	feq_gen_os_file_style_d_(feq_gen_feo_name_d_, (ftnlen)256);
/* SOURCE genscn.for:1022 */
/*<       write(stdout,'(A)')feo_name(1:feq_len_trim(feo_name)) >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, feq_gen_feo_name_d_, feq_gen_feq_len_trim_d_(feq_gen_feo_name_d_, (ftnlen)256));
	e_wsfe();
/* SOURCE genscn.for:1023 */
/*<       callos_file_style(tsd_name) >*/
	feq_gen_os_file_style_d_(feq_gen_tsd_name_d_, (ftnlen)256);
/* SOURCE genscn.for:1025 */
/*<       write(stdout,'(A)')tsd_name(1:feq_len_trim(tsd_name)) >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, feq_gen_tsd_name_d_, feq_gen_feq_len_trim_d_(feq_gen_tsd_name_d_, (ftnlen)256));
	e_wsfe();
/* SOURCE genscn.for:1026 */
/*<       callos_file_style(ftf_name) >*/
	feq_gen_os_file_style_d_(feq_gen_ftf_name_d_, (ftnlen)256);
/* SOURCE genscn.for:1028 */
/*<       write(stdout,'(A)')ftf_name(1:feq_len_trim(ftf_name)) >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, feq_gen_ftf_name_d_, feq_gen_feq_len_trim_d_(feq_gen_ftf_name_d_, (ftnlen)256));
	e_wsfe();
/* SOURCE genscn.for:1029 */
/*<       else >*/
    } else {
/* SOURCE genscn.for:1030 */
/*<       write(stdout,76)char4 >*/
	feq_gen_io_d__107.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__107);
	do_fio(&feq_gen_c_d_1, char4, (ftnlen)4);
	e_wsfe();
/* SOURCE genscn.for:1031 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE genscn.for:1032 */
/*<       endif >*/
    }
/*     Open the FEO file.  Assume each case is new for now.  Add support */
/*     for update later. */
/* SOURCE genscn.for:1037 */
/*<       feo_unit=get_unit(stdout) >*/
    genscn_1.feq_gen_feo_unit_d_ = feq_gen_get_unit_d_(stdout);
/* SOURCE genscn.for:1038 */
/*<        >*/
    feq_gen_o_d_1.oerr = 1;
    feq_gen_o_d_1.ounit = genscn_1.feq_gen_feo_unit_d_;
    feq_gen_o_d_1.ofnmlen = 256;
    feq_gen_o_d_1.ofnm = feq_gen_feo_name_d_;
    feq_gen_o_d_1.orl = 0;
    feq_gen_o_d_1.osta = const_cast<char*>("UNKNOWN");
    feq_gen_o_d_1.oacc = 0;
    feq_gen_o_d_1.ofm = const_cast<char*>("FORMATTED");
    feq_gen_o_d_1.oblnk = 0;
    ioflag = f_open(&feq_gen_o_d_1);
/* SOURCE genscn.for:1041 */
/*<       if(ioflag.ne.0)then >*/
    if (ioflag != 0) {
/* SOURCE genscn.for:1042 */
/*<       write(stdout,*)' Problem in opening file: ',feo_name >*/
	feq_gen_io_d__109.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__109);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Problem in opening file: "), (ftnlen)26);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_feo_name_d_, (ftnlen)256);
	e_wsle();
/* SOURCE genscn.for:1043 */
/*<       write(stdout,*)' Check path for *.feo file.' >*/
	feq_gen_io_d__110.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__110);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Check path for *.feo file."), (ftnlen)27);
	e_wsle();
/* SOURCE genscn.for:1044 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE genscn.for:1045 */
/*<       endif >*/
    }
/* SOURCE genscn.for:1047 */
/*<       write(feo_unit,50)version_number >*/
    feq_gen_io_d__111.ciunit = genscn_1.feq_gen_feo_unit_d_;
    s_wsfe(&feq_gen_io_d__111);
    do_fio(&feq_gen_c_d_1, (char *)&version_1.feq_gen_version_number_d_, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE genscn.for:1048 */
/*<       if(new_genscn_feo.eq.'NO')then >*/
    if (s_cmp(feq_gen_new_genscn_feo_d_, const_cast<char*>("NO"), (ftnlen)4, (ftnlen)2) == 0) {
/* SOURCE genscn.for:1049 */
/*<       write(feo_unit,53) >*/
	feq_gen_io_d__112.ciunit = genscn_1.feq_gen_feo_unit_d_;
	s_wsfe(&feq_gen_io_d__112);
	e_wsfe();
/* SOURCE genscn.for:1050 */
/*<       else >*/
    } else {
/* SOURCE genscn.for:1051 */
/*<       write(feo_unit,59) >*/
	feq_gen_io_d__113.ciunit = genscn_1.feq_gen_feo_unit_d_;
	s_wsfe(&feq_gen_io_d__113);
	e_wsfe();
/* SOURCE genscn.for:1052 */
/*<       endif >*/
    }
/* SOURCE genscn.for:1053 */
/*<       write(feo_unit,52)feo_name(1:feq_len_trim(feo_name)) >*/
    feq_gen_io_d__114.ciunit = genscn_1.feq_gen_feo_unit_d_;
    s_wsfe(&feq_gen_io_d__114);
    do_fio(&feq_gen_c_d_1, feq_gen_feo_name_d_, feq_gen_feq_len_trim_d_(feq_gen_feo_name_d_, (ftnlen)256));
    e_wsfe();
/* SOURCE genscn.for:1054 */
/*<       write(feo_unit,52)tsd_name(1:feq_len_trim(tsd_name)) >*/
    feq_gen_io_d__115.ciunit = genscn_1.feq_gen_feo_unit_d_;
    s_wsfe(&feq_gen_io_d__115);
    do_fio(&feq_gen_c_d_1, feq_gen_tsd_name_d_, feq_gen_feq_len_trim_d_(feq_gen_tsd_name_d_, (ftnlen)256));
    e_wsfe();
/* SOURCE genscn.for:1055 */
/*<       write(feo_unit,52)ftf_name(1:feq_len_trim(ftf_name)) >*/
    feq_gen_io_d__116.ciunit = genscn_1.feq_gen_feo_unit_d_;
    s_wsfe(&feq_gen_io_d__116);
    do_fio(&feq_gen_c_d_1, feq_gen_ftf_name_d_, feq_gen_feq_len_trim_d_(feq_gen_ftf_name_d_, (ftnlen)256));
    e_wsfe();
/*     Write the unit names and conversion factors.  Expand later. */
/* SOURCE genscn.for:1059 */
/*<       write(feo_unit,54) >*/
    feq_gen_io_d__117.ciunit = genscn_1.feq_gen_feo_unit_d_;
    s_wsfe(&feq_gen_io_d__117);
    e_wsfe();
/*     Write the subversion related values */
/* SOURCE genscn.for:1062 */
/*<       write(feo_unit,60) >*/
    feq_gen_io_d__118.ciunit = genscn_1.feq_gen_feo_unit_d_;
    s_wsfe(&feq_gen_io_d__118);
    e_wsfe();
/* SOURCE genscn.for:1063 */
/*<       it=feq_len_trim(url) >*/
    it = feq_gen_feq_len_trim_d_(svncomc_1.url, (ftnlen)256);
/* SOURCE genscn.for:1064 */
/*<       write(feo_unit,"(a)")url(1:it) >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = genscn_1.feq_gen_feo_unit_d_;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(a)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, svncomc_1.url, it);
    e_wsfe();
/* SOURCE genscn.for:1065 */
/*<       it=feq_len_trim(revision) >*/
    it = feq_gen_feq_len_trim_d_(svncomc_1.revision, (ftnlen)256);
/* SOURCE genscn.for:1066 */
/*<       write(feo_unit,"(a)")revision(1:it) >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = genscn_1.feq_gen_feo_unit_d_;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(a)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, svncomc_1.revision, it);
    e_wsfe();
/* SOURCE genscn.for:1067 */
/*<       if(svn_rev>0)then >*/
    if (svncom_1.feq_gen_svn_rev_d_ > 0) {
/* SOURCE genscn.for:1068 */
/*<       write(feo_unit,86)svn_rev >*/
	feq_gen_io_d__119.ciunit = genscn_1.feq_gen_feo_unit_d_;
	s_wsfe(&feq_gen_io_d__119);
	do_fio(&feq_gen_c_d_1, (char *)&svncom_1.feq_gen_svn_rev_d_, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE genscn.for:1069 */
/*<       if(svn_mod>0)then >*/
	if (svncom_1.feq_gen_svn_mod_d_ > 0) {
/* SOURCE genscn.for:1070 */
/*<       write(feo_unit,87) >*/
	    feq_gen_io_d__120.ciunit = genscn_1.feq_gen_feo_unit_d_;
	    s_wsfe(&feq_gen_io_d__120);
	    e_wsfe();
/* SOURCE genscn.for:1071 */
/*<       endif >*/
	}
/* SOURCE genscn.for:1072 */
/*<       endif >*/
    }
/* SOURCE genscn.for:1075 */
/*<       if(new_genscn_feo.ne.'NO')then >*/
    if (s_cmp(feq_gen_new_genscn_feo_d_, const_cast<char*>("NO"), (ftnlen)4, (ftnlen)2) != 0) {
/*       Output the pump and gate description classes. */
/* SOURCE genscn.for:1077 */
/*<       write(feo_unit,55) >*/
	feq_gen_io_d__121.ciunit = genscn_1.feq_gen_feo_unit_d_;
	s_wsfe(&feq_gen_io_d__121);
	e_wsfe();
/* SOURCE genscn.for:1078 */
/*<       do99i=1,n_gp_status >*/
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 13; ++feq_gen_i_d_) {
/* SOURCE genscn.for:1079 */
/*<       write(feo_unit,57)i,gp_status(i) >*/
	    feq_gen_io_d__122.ciunit = genscn_1.feq_gen_feo_unit_d_;
	    s_wsfe(&feq_gen_io_d__122);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, feq_gen_gp_status_d_ + (feq_gen_i_d_ - 1 << 3), (ftnlen)8);
	    e_wsfe();
/* SOURCE genscn.for:1080 */
/*<    99 continue >*/
/* L99: */
	}
/* SOURCE genscn.for:1081 */
/*<       write(feo_unit,57)-1,' ' >*/
	feq_gen_io_d__123.ciunit = genscn_1.feq_gen_feo_unit_d_;
	s_wsfe(&feq_gen_io_d__123);
	do_fio(&feq_gen_c_d_1, (char *)&c_n1, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	e_wsfe();
/* SOURCE genscn.for:1082 */
/*<       endif >*/
    }
/*     Open the FTF file and store the function table vector in it. */
/* SOURCE genscn.for:1086 */
/*<       ftf_unit=get_unit(stdout) >*/
    genscn_1.feq_gen_ftf_unit_d_ = feq_gen_get_unit_d_(stdout);
/*      OPEN(FTF_UNIT, FILE=FTF_NAME, FORM='UNFORMATTED', */
/*     A        STATUS='UNKNOWN', IOSTAT=IOFLAG) */
/* SOURCE genscn.for:1091 */
/*<       record_length_in_bytes=4*512 >*/
    feq_gen_record_length_in_bytes_d_ = 2048;
/* SOURCE genscn.for:1092 */
/*<        >*/
    feq_gen_o_d_1.oerr = 1;
    feq_gen_o_d_1.ounit = genscn_1.feq_gen_ftf_unit_d_;
    feq_gen_o_d_1.ofnmlen = 256;
    feq_gen_o_d_1.ofnm = feq_gen_ftf_name_d_;
    feq_gen_o_d_1.orl = feq_gen_record_length_in_bytes_d_;
    feq_gen_o_d_1.osta = const_cast<char*>("UNKNOWN");
    feq_gen_o_d_1.oacc = const_cast<char*>("DIRECT");
    feq_gen_o_d_1.ofm = const_cast<char*>("UNFORMATTED");
    feq_gen_o_d_1.oblnk = 0;
    ioflag = f_open(&feq_gen_o_d_1);
/* SOURCE genscn.for:1097 */
/*<       if(ioflag.ne.0)then >*/
    if (ioflag != 0) {
/* SOURCE genscn.for:1098 */
/*<       write(stdout,*)' Problem in opening file: ',ftf_name >*/
	feq_gen_io_d__125.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__125);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Problem in opening file: "), (ftnlen)26);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ftf_name_d_, (ftnlen)256);
	e_wsle();
/* SOURCE genscn.for:1099 */
/*<       write(stdout,*)' Check path for *.FTF file.' >*/
	feq_gen_io_d__126.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__126);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Check path for *.FTF file."), (ftnlen)27);
	e_wsle();
/* SOURCE genscn.for:1100 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE genscn.for:1101 */
/*<       endif >*/
    }
/* SOURCE genscn.for:1102 */
/*<        >*/
    feq_gen_write_ftfa_d_(stdout, &genscn_1.feq_gen_ftf_unit_d_, ftp, &feq_gen_number_of_full_records_d_,
	     &feq_gen_items_per_record_d_, &feq_gen_leftover_item_knt_d_);
/* SOURCE genscn.for:1105 */
/*<       callfree_unit(stdout,ftf_unit) >*/
    feq_gen_free_unit_d_(stdout, &genscn_1.feq_gen_ftf_unit_d_);
/*     Write description of the FTF file to the FEO file */
/* SOURCE genscn.for:1108 */
/*<        >*/
    feq_gen_io_d__130.ciunit = genscn_1.feq_gen_feo_unit_d_;
    s_wsfe(&feq_gen_io_d__130);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_number_of_full_records_d_, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_items_per_record_d_, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_leftover_item_knt_d_, (ftnlen)sizeof(integer));
    e_wsfe();
/*     Read lines of input expecting to find ADD and SUB requests */
/*     refering to classes of nodes by name.   Build a record of */
/*     the nodes in scratch space. */
/*     Clear the flag values */
/* SOURCE genscn.for:1117 */
/*<       do500i=1,mnbn >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 8400; ++feq_gen_i_d_) {
/* SOURCE genscn.for:1118 */
/*<       bnode_flag(i)=0 >*/
	feq_gen_bnode_flag_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE genscn.for:1119 */
/*<   500 continue >*/
/* L500: */
    }
/* SOURCE genscn.for:1120 */
/*<       do505i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE genscn.for:1121 */
/*<       enode_flag(i)=0 >*/
	feq_gen_enode_flag_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE genscn.for:1122 */
/*<       enode_bra(i)=0 >*/
	feq_gen_enode_bra_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE genscn.for:1123 */
/*<   505 continue >*/
/* L505: */
    }
/*     We must zero all possible to be able to handle McHenry gates */
/*     since they do not fit the pattern for the other gates and pumps. */
/*     McHenry will always be placed in position MNGATE+1 */
/* SOURCE genscn.for:1127 */
/*<       do507i=1,mngate+1 >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 51; ++feq_gen_i_d_) {
/* SOURCE genscn.for:1128 */
/*<       gate_pump_flag(i)=0 >*/
	feq_gen_gate_pump_flag_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE genscn.for:1129 */
/*<       gate_pump_name(i)=' ' >*/
	s_copy(feq_gen_gate_pump_name_d_ + (feq_gen_i_d_ - 1 << 4), const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/* SOURCE genscn.for:1130 */
/*<   507 continue >*/
/* L507: */
    }
/* SOURCE genscn.for:1132 */
/*<   550 continue >*/
L550:
/* SOURCE genscn.for:1133 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)196);
/* SOURCE genscn.for:1136 */
/*<       callstrip_l_blanks(line) >*/
    feq_gen_strip_l_blanks_d_(line, (ftnlen)196);
/* SOURCE genscn.for:1139 */
/*<       read(line,'(A3)')option >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 196;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(A3)");
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, option, (ftnlen)3);
    e_rsfi();
/* SOURCE genscn.for:1140 */
/*<       if(option.eq.'ADD')then >*/
    if (s_cmp(option, const_cast<char*>("ADD"), (ftnlen)3, (ftnlen)3) == 0) {
/* SOURCE genscn.for:1141 */
/*<       addflag=1 >*/
	addflag = 1;
/* SOURCE genscn.for:1143 */
/*<       elseif(option.eq.'SUB')then >*/
    } else if (s_cmp(option, const_cast<char*>("SUB"), (ftnlen)3, (ftnlen)3) == 0) {
/* SOURCE genscn.for:1144 */
/*<       addflag=-1 >*/
	addflag = -1;
/* SOURCE genscn.for:1145 */
/*<       else >*/
    } else {
/* SOURCE genscn.for:1146 */
/*<       write(stdout,77)option >*/
	feq_gen_io_d__138.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__138);
	do_fio(&feq_gen_c_d_1, option, (ftnlen)3);
	e_wsfe();
/* SOURCE genscn.for:1147 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE genscn.for:1148 */
/*<       endif >*/
    }
/*       Now get the node class response. */
/* SOURCE genscn.for:1151 */
/*<       line=line(4:) >*/
    s_copy(line, line + 3, (ftnlen)196, (ftnlen)193);
/* SOURCE genscn.for:1152 */
/*<       callstrip_l_blanks(line) >*/
    feq_gen_strip_l_blanks_d_(line, (ftnlen)196);
/* SOURCE genscn.for:1154 */
/*<       if(line(1:1).eq.'=')then >*/
    if (*(unsigned char *)line == '=') {
/* SOURCE genscn.for:1155 */
/*<       line(1:1)=' ' >*/
	*(unsigned char *)line = ' ';
/* SOURCE genscn.for:1156 */
/*<       callstrip_l_blanks(line) >*/
	feq_gen_strip_l_blanks_d_(line, (ftnlen)196);
/* SOURCE genscn.for:1158 */
/*<       endif >*/
    }
/* SOURCE genscn.for:1159 */
/*<       read(line,'(A16)')node_class >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 196;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(A16)");
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, feq_gen_node_class_d_, (ftnlen)16);
    e_rsfi();
/* SOURCE genscn.for:1161 */
/*<       ip=lenstr(node_class) >*/
    ip = lenstr_(feq_gen_node_class_d_, (ftnlen)16);
/* SOURCE genscn.for:1163 */
/*<       if(node_class(1:ip).eq.'NONE')then >*/
    if (s_cmp(feq_gen_node_class_d_, const_cast<char*>("NONE"), ip, (ftnlen)4) == 0) {
/* SOURCE genscn.for:1164 */
/*<       write(stdout,82) >*/
	feq_gen_io_d__141.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__141);
	e_wsfe();
/* SOURCE genscn.for:1165 */
/*<       elseif(addflag.eq.1)then >*/
    } else if (addflag == 1) {
/* SOURCE genscn.for:1166 */
/*<       write(stdout,80)node_class(1:ip) >*/
	feq_gen_io_d__142.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__142);
	do_fio(&feq_gen_c_d_1, feq_gen_node_class_d_, ip);
	e_wsfe();
/* SOURCE genscn.for:1167 */
/*<       else >*/
    } else {
/* SOURCE genscn.for:1168 */
/*<       write(stdout,81)node_class(1:ip) >*/
	feq_gen_io_d__143.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__143);
	do_fio(&feq_gen_c_d_1, feq_gen_node_class_d_, ip);
	e_wsfe();
/* SOURCE genscn.for:1169 */
/*<       endif >*/
    }
/* SOURCE genscn.for:1171 */
/*<       calllstab(node_class,class_table,n_class,ip) >*/
    lstab_(feq_gen_node_class_d_, feq_gen_class_table_d_, &feq_gen_c_d_11, &ip, (ftnlen)16, (ftnlen)16);
/* SOURCE genscn.for:1174 */
/*<       if(ip.eq.0)then >*/
    if (ip == 0) {
/* SOURCE genscn.for:1175 */
/*<       write(stdout,78)node_class >*/
	feq_gen_io_d__144.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__144);
	do_fio(&feq_gen_c_d_1, feq_gen_node_class_d_, (ftnlen)16);
	e_wsfe();
/* SOURCE genscn.for:1176 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE genscn.for:1177 */
/*<       endif >*/
    }
/* SOURCE genscn.for:1179 */
/*<       class=class_value(ip) >*/
    feq_gen_class_d_ = feq_gen_class_value_d_[ip - 1];
/* SOURCE genscn.for:1180 */
/*<        >*/
    switch (feq_gen_class_d_) {
	case 1:  goto L1000;
	case 2:  goto L2000;
	case 3:  goto L3000;
	case 4:  goto L4000;
	case 5:  goto L5000;
	case 6:  goto L6000;
	case 7:  goto L7000;
	case 8:  goto L8000;
	case 9:  goto L9000;
	case 10:  goto L10000;
	case 11:  goto L11000;
    }
/* SOURCE genscn.for:1183 */
/*<  1000 continue >*/
L1000:
/*         Add or subtract all nodes in the system. */
/* SOURCE genscn.for:1185 */
/*<       do1010ibra=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (ibra = 1; ibra <= feq_gen_i_d_1; ++ibra) {
/* SOURCE genscn.for:1186 */
/*<       fn=brpt(3,ibra) >*/
	fn = brpt[(ibra << 3) + 3];
/* SOURCE genscn.for:1187 */
/*<       ln=brpt(4,ibra) >*/
	ln = brpt[(ibra << 3) + 4];
/* SOURCE genscn.for:1188 */
/*<       do1005j=fn,ln >*/
	feq_gen_i_d_2 = ln;
	for (j = fn; j <= feq_gen_i_d_2; ++j) {
/* SOURCE genscn.for:1189 */
/*<       if(addflag.eq.1)then >*/
	    if (addflag == 1) {
/* SOURCE genscn.for:1190 */
/*<       bnode_flag(j)=1 >*/
		feq_gen_bnode_flag_d_[j - 1] = 1;
/* SOURCE genscn.for:1191 */
/*<       bnode_bra(j)=ibra >*/
		feq_gen_bnode_bra_d_[j - 1] = ibra;
/* SOURCE genscn.for:1192 */
/*<       else >*/
	    } else {
/* SOURCE genscn.for:1193 */
/*<       bnode_flag(j)=0 >*/
		feq_gen_bnode_flag_d_[j - 1] = 0;
/* SOURCE genscn.for:1194 */
/*<       endif >*/
	    }
/* SOURCE genscn.for:1195 */
/*<  1005 continue >*/
/* L1005: */
	}
/* SOURCE genscn.for:1196 */
/*<  1010 continue >*/
/* L1010: */
    }
/* SOURCE genscn.for:1197 */
/*<       do1020i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE genscn.for:1198 */
/*<       if(addflag.eq.1)then >*/
	if (addflag == 1) {
/* SOURCE genscn.for:1199 */
/*<       enode_flag(i)=1 >*/
	    feq_gen_enode_flag_d_[feq_gen_i_d_ - 1] = 1;
/* SOURCE genscn.for:1200 */
/*<       enode_bra(i)=exnodt(3,i) >*/
	    feq_gen_enode_bra_d_[feq_gen_i_d_ - 1] = exnodt[feq_gen_i_d_ * 9 + 3];
/* SOURCE genscn.for:1201 */
/*<       else >*/
	} else {
/* SOURCE genscn.for:1202 */
/*<       enode_flag(i)=0 >*/
	    feq_gen_enode_flag_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE genscn.for:1203 */
/*<       enode_bra(i)=0 >*/
	    feq_gen_enode_bra_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE genscn.for:1204 */
/*<       endif >*/
	}
/* SOURCE genscn.for:1205 */
/*<  1020 continue >*/
/* L1020: */
    }
/* SOURCE genscn.for:1206 */
/*<       goto20000 >*/
    goto L20000;
/* SOURCE genscn.for:1208 */
/*<  2000 continue >*/
L2000:
/*         Add or subtract all nodes on branches. */
/* SOURCE genscn.for:1210 */
/*<       do2010ibra=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (ibra = 1; ibra <= feq_gen_i_d_1; ++ibra) {
/* SOURCE genscn.for:1211 */
/*<       fn=brpt(3,ibra) >*/
	fn = brpt[(ibra << 3) + 3];
/* SOURCE genscn.for:1212 */
/*<       ln=brpt(4,ibra) >*/
	ln = brpt[(ibra << 3) + 4];
/* SOURCE genscn.for:1213 */
/*<       do2005j=fn,ln >*/
	feq_gen_i_d_2 = ln;
	for (j = fn; j <= feq_gen_i_d_2; ++j) {
/* SOURCE genscn.for:1214 */
/*<       if(addflag.eq.1)then >*/
	    if (addflag == 1) {
/* SOURCE genscn.for:1215 */
/*<       bnode_flag(j)=1 >*/
		feq_gen_bnode_flag_d_[j - 1] = 1;
/* SOURCE genscn.for:1216 */
/*<       bnode_bra(j)=ibra >*/
		feq_gen_bnode_bra_d_[j - 1] = ibra;
/* SOURCE genscn.for:1217 */
/*<       else >*/
	    } else {
/* SOURCE genscn.for:1218 */
/*<       bnode_flag(j)=0 >*/
		feq_gen_bnode_flag_d_[j - 1] = 0;
/* SOURCE genscn.for:1219 */
/*<       endif >*/
	    }
/* SOURCE genscn.for:1220 */
/*<  2005 continue >*/
/* L2005: */
	}
/* SOURCE genscn.for:1221 */
/*<  2010 continue >*/
/* L2010: */
    }
/* SOURCE genscn.for:1222 */
/*<       goto20000 >*/
    goto L20000;
/* SOURCE genscn.for:1224 */
/*<  3000 continue >*/
L3000:
/*         Add or subtract all exterior nodes */
/* SOURCE genscn.for:1226 */
/*<       do3020i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE genscn.for:1227 */
/*<       if(addflag.eq.1)then >*/
	if (addflag == 1) {
/* SOURCE genscn.for:1228 */
/*<       enode_flag(i)=1 >*/
	    feq_gen_enode_flag_d_[feq_gen_i_d_ - 1] = 1;
/* SOURCE genscn.for:1229 */
/*<       enode_bra(i)=exnodt(3,i) >*/
	    feq_gen_enode_bra_d_[feq_gen_i_d_ - 1] = exnodt[feq_gen_i_d_ * 9 + 3];
/* SOURCE genscn.for:1230 */
/*<       else >*/
	} else {
/* SOURCE genscn.for:1231 */
/*<       enode_flag(i)=0 >*/
	    feq_gen_enode_flag_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE genscn.for:1232 */
/*<       enode_bra(i)=0 >*/
	    feq_gen_enode_bra_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE genscn.for:1233 */
/*<       endif >*/
	}
/* SOURCE genscn.for:1234 */
/*<  3020 continue >*/
/* L3020: */
    }
/* SOURCE genscn.for:1235 */
/*<       goto20000 >*/
    goto L20000;
/* SOURCE genscn.for:1237 */
/*<  4000 continue >*/
L4000:
/*         Add or subtract nodes on branches at which FEQ */
/*         interpolated a cross section. */
/* SOURCE genscn.for:1240 */
/*<       do4010ibra=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (ibra = 1; ibra <= feq_gen_i_d_1; ++ibra) {
/* SOURCE genscn.for:1241 */
/*<       fn=brpt(3,ibra) >*/
	fn = brpt[(ibra << 3) + 3];
/* SOURCE genscn.for:1242 */
/*<       ln=brpt(4,ibra) >*/
	ln = brpt[(ibra << 3) + 4];
/* SOURCE genscn.for:1243 */
/*<       do4005j=fn,ln >*/
	feq_gen_i_d_2 = ln;
	for (j = fn; j <= feq_gen_i_d_2; ++j) {
/*             Check each cross section table for its source. */
/* SOURCE genscn.for:1245 */
/*<       if(get_source(nsec(j)).eq.1)then >*/
	    if (feq_gen_get_source_d_(&bnothr_1.nsec[j - 1]) == 1) {
/*               The cross-section table at this node was interpolated. */
/* SOURCE genscn.for:1247 */
/*<       if(addflag.eq.1)then >*/
		if (addflag == 1) {
/* SOURCE genscn.for:1248 */
/*<       bnode_flag(j)=1 >*/
		    feq_gen_bnode_flag_d_[j - 1] = 1;
/* SOURCE genscn.for:1249 */
/*<       bnode_bra(j)=ibra >*/
		    feq_gen_bnode_bra_d_[j - 1] = ibra;
/* SOURCE genscn.for:1250 */
/*<       else >*/
		} else {
/* SOURCE genscn.for:1251 */
/*<       bnode_flag(j)=0 >*/
		    feq_gen_bnode_flag_d_[j - 1] = 0;
/* SOURCE genscn.for:1252 */
/*<       endif >*/
		}
/* SOURCE genscn.for:1253 */
/*<       endif >*/
	    }
/* SOURCE genscn.for:1254 */
/*<  4005 continue >*/
/* L4005: */
	}
/* SOURCE genscn.for:1255 */
/*<  4010 continue >*/
/* L4010: */
    }
/* SOURCE genscn.for:1256 */
/*<       goto20000 >*/
    goto L20000;
/* SOURCE genscn.for:1258 */
/*<  5000 continue >*/
L5000:
/*         Add or subtract nodes on a branch at which FEQ */
/*         had an input cross section (NOT interpolated by FEQ). */
/* SOURCE genscn.for:1261 */
/*<       do5010ibra=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (ibra = 1; ibra <= feq_gen_i_d_1; ++ibra) {
/* SOURCE genscn.for:1262 */
/*<       fn=brpt(3,ibra) >*/
	fn = brpt[(ibra << 3) + 3];
/* SOURCE genscn.for:1263 */
/*<       ln=brpt(4,ibra) >*/
	ln = brpt[(ibra << 3) + 4];
/* SOURCE genscn.for:1264 */
/*<       do5005j=fn,ln >*/
	feq_gen_i_d_2 = ln;
	for (j = fn; j <= feq_gen_i_d_2; ++j) {
/*             Check each cross section table for its source. */
/* SOURCE genscn.for:1266 */
/*<       if(get_source(nsec(j)).eq.0)then >*/
	    if (feq_gen_get_source_d_(&bnothr_1.nsec[j - 1]) == 0) {
/*               The cross-section table at this node was NOT */
/*               interpolated by FEQ. */
/* SOURCE genscn.for:1269 */
/*<       if(addflag.eq.1)then >*/
		if (addflag == 1) {
/* SOURCE genscn.for:1270 */
/*<       bnode_flag(j)=1 >*/
		    feq_gen_bnode_flag_d_[j - 1] = 1;
/* SOURCE genscn.for:1271 */
/*<       bnode_bra(j)=ibra >*/
		    feq_gen_bnode_bra_d_[j - 1] = ibra;
/* SOURCE genscn.for:1272 */
/*<       else >*/
		} else {
/* SOURCE genscn.for:1273 */
/*<       bnode_flag(j)=0 >*/
		    feq_gen_bnode_flag_d_[j - 1] = 0;
/* SOURCE genscn.for:1274 */
/*<       endif >*/
		}
/* SOURCE genscn.for:1275 */
/*<       endif >*/
	    }
/* SOURCE genscn.for:1276 */
/*<  5005 continue >*/
/* L5005: */
	}
/* SOURCE genscn.for:1277 */
/*<  5010 continue >*/
/* L5010: */
    }
/* SOURCE genscn.for:1278 */
/*<       goto20000 >*/
    goto L20000;
/* SOURCE genscn.for:1280 */
/*<  6000 continue >*/
L6000:
/*         Add or subtract free nodes */
/* SOURCE genscn.for:1282 */
/*<       do6020i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE genscn.for:1283 */
/*<       if(exnodt(3,i).le.0)then >*/
	if (exnodt[feq_gen_i_d_ * 9 + 3] <= 0) {
/*             We have a free node */
/* SOURCE genscn.for:1285 */
/*<       if(addflag.eq.1)then >*/
	    if (addflag == 1) {
/* SOURCE genscn.for:1286 */
/*<       enode_flag(i)=1 >*/
		feq_gen_enode_flag_d_[feq_gen_i_d_ - 1] = 1;
/* SOURCE genscn.for:1287 */
/*<       enode_bra(i)=exnodt(3,i) >*/
		feq_gen_enode_bra_d_[feq_gen_i_d_ - 1] = exnodt[feq_gen_i_d_ * 9 + 3];
/* SOURCE genscn.for:1288 */
/*<       else >*/
	    } else {
/* SOURCE genscn.for:1289 */
/*<       enode_flag(i)=0 >*/
		feq_gen_enode_flag_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE genscn.for:1290 */
/*<       enode_bra(i)=0 >*/
		feq_gen_enode_bra_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE genscn.for:1291 */
/*<       endif >*/
	    }
/* SOURCE genscn.for:1292 */
/*<       endif >*/
	}
/* SOURCE genscn.for:1293 */
/*<  6020 continue >*/
/* L6020: */
    }
/* SOURCE genscn.for:1294 */
/*<       goto20000 >*/
    goto L20000;
/* SOURCE genscn.for:1296 */
/*<  7000 continue >*/
L7000:
/*         Add or subtract level-pool reservoir nodes. */
/* SOURCE genscn.for:1298 */
/*<       do7020i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE genscn.for:1299 */
/*<       if(exnodt(3,i).lt.0)then >*/
	if (exnodt[feq_gen_i_d_ * 9 + 3] < 0) {
/*             We have an LPR node */
/* SOURCE genscn.for:1301 */
/*<       if(addflag.eq.1)then >*/
	    if (addflag == 1) {
/* SOURCE genscn.for:1302 */
/*<       enode_flag(i)=1 >*/
		feq_gen_enode_flag_d_[feq_gen_i_d_ - 1] = 1;
/* SOURCE genscn.for:1303 */
/*<       enode_bra(i)=exnodt(3,i) >*/
		feq_gen_enode_bra_d_[feq_gen_i_d_ - 1] = exnodt[feq_gen_i_d_ * 9 + 3];
/* SOURCE genscn.for:1304 */
/*<       else >*/
	    } else {
/* SOURCE genscn.for:1305 */
/*<       enode_flag(i)=0 >*/
		feq_gen_enode_flag_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE genscn.for:1306 */
/*<       enode_bra(i)=0 >*/
		feq_gen_enode_bra_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE genscn.for:1307 */
/*<       endif >*/
	    }
/* SOURCE genscn.for:1308 */
/*<       endif >*/
	}
/* SOURCE genscn.for:1309 */
/*<  7020 continue >*/
/* L7020: */
    }
/* SOURCE genscn.for:1310 */
/*<       goto20000 >*/
    goto L20000;
/* SOURCE genscn.for:1312 */
/*<  8000 continue >*/
L8000:
/*         Inflow nodes to reservoirs */
/* SOURCE genscn.for:1315 */
/*<       write(stdout,79)node_class >*/
    feq_gen_io_d__151.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__151);
    do_fio(&feq_gen_c_d_1, feq_gen_node_class_d_, (ftnlen)16);
    e_wsfe();
/* SOURCE genscn.for:1316 */
/*<       goto20000 >*/
    goto L20000;
/* SOURCE genscn.for:1318 */
/*<  9000 continue >*/
L9000:
/*         Exterior nodes on branches. */
/*         Add or subtract exterior nodes on branches */
/* SOURCE genscn.for:1321 */
/*<       do9020i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE genscn.for:1322 */
/*<       if(exnodt(3,i).gt.0)then >*/
	if (exnodt[feq_gen_i_d_ * 9 + 3] > 0) {
/*             We have an LPR node */
/* SOURCE genscn.for:1324 */
/*<       if(addflag.eq.1)then >*/
	    if (addflag == 1) {
/* SOURCE genscn.for:1325 */
/*<       enode_flag(i)=1 >*/
		feq_gen_enode_flag_d_[feq_gen_i_d_ - 1] = 1;
/* SOURCE genscn.for:1326 */
/*<       enode_bra(i)=exnodt(3,i) >*/
		feq_gen_enode_bra_d_[feq_gen_i_d_ - 1] = exnodt[feq_gen_i_d_ * 9 + 3];
/* SOURCE genscn.for:1327 */
/*<       else >*/
	    } else {
/* SOURCE genscn.for:1328 */
/*<       enode_flag(i)=0 >*/
		feq_gen_enode_flag_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE genscn.for:1329 */
/*<       enode_bra(i)=0 >*/
		feq_gen_enode_bra_d_[feq_gen_i_d_ - 1] = 0;
/* SOURCE genscn.for:1330 */
/*<       endif >*/
	    }
/* SOURCE genscn.for:1331 */
/*<       endif >*/
	}
/* SOURCE genscn.for:1332 */
/*<  9020 continue >*/
/* L9020: */
    }
/* SOURCE genscn.for:1333 */
/*<       goto20000 >*/
    goto L20000;
/* SOURCE genscn.for:1335 */
/*< 10000 continue >*/
L10000:
/* SOURCE genscn.for:1336 */
/*<       write(stdout,79)node_class >*/
    feq_gen_io_d__152.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__152);
    do_fio(&feq_gen_c_d_1, feq_gen_node_class_d_, (ftnlen)16);
    e_wsfe();
/* SOURCE genscn.for:1337 */
/*<       goto20000 >*/
    goto L20000;
/* SOURCE genscn.for:1339 */
/*< 11000 continue >*/
L11000:
/*         User is done making selections by node class. */
/*         See if node by node specification exists. */
/* SOURCE genscn.for:1343 */
/*<       goto21000 >*/
    goto L21000;
/* SOURCE genscn.for:1345 */
/*< 20000 continue >*/
L20000:
/* SOURCE genscn.for:1346 */
/*<       goto550 >*/
    goto L550;
/* SOURCE genscn.for:1348 */
/*< 21000 continue >*/
L21000:
/* SOURCE genscn.for:1350 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)196);
/* SOURCE genscn.for:1353 */
/*<       read(line,2)head >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 196;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_2;
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)196);
    e_rsfi();
/* SOURCE genscn.for:1354 */
/*<       write(stdout,4)head >*/
    feq_gen_io_d__154.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__154);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)196);
    e_wsfe();
/* SOURCE genscn.for:1356 */
/*<       if(new_genscn_feo.eq.'NO')then >*/
    if (s_cmp(feq_gen_new_genscn_feo_d_, const_cast<char*>("NO"), (ftnlen)4, (ftnlen)2) == 0) {
/* SOURCE genscn.for:1357 */
/*<       write(feo_unit,88) >*/
	feq_gen_io_d__155.ciunit = genscn_1.feq_gen_feo_unit_d_;
	s_wsfe(&feq_gen_io_d__155);
	e_wsfe();
/* SOURCE genscn.for:1358 */
/*<       else >*/
    } else {
/* SOURCE genscn.for:1359 */
/*<       write(feo_unit,58) >*/
	feq_gen_io_d__156.ciunit = genscn_1.feq_gen_feo_unit_d_;
	s_wsfe(&feq_gen_io_d__156);
	e_wsfe();
/* SOURCE genscn.for:1360 */
/*<       endif >*/
    }
/* SOURCE genscn.for:1363 */
/*<   100 continue >*/
L100:
/* SOURCE genscn.for:1364 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)196);
/* SOURCE genscn.for:1367 */
/*<       read(line,5,err=991)opt5,brain,node_item >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 196;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_5;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, opt5, (ftnlen)5);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&brain, (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, feq_gen_node_item_d_, (ftnlen)16);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE genscn.for:1368 */
/*<       callstrip_l_blanks(opt5) >*/
    feq_gen_strip_l_blanks_d_(opt5, (ftnlen)5);
/* SOURCE genscn.for:1370 */
/*<       if(opt5(1:3).eq.'END')goto150 >*/
    if (s_cmp(opt5, const_cast<char*>("END"), (ftnlen)3, (ftnlen)3) == 0) {
	goto L150;
    }
/* SOURCE genscn.for:1371 */
/*<       write(stdout,6)opt5,brain,node_item >*/
    feq_gen_io_d__160.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__160);
    do_fio(&feq_gen_c_d_1, opt5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, (char *)&brain, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, feq_gen_node_item_d_, (ftnlen)16);
    e_wsfe();
/* SOURCE genscn.for:1373 */
/*<       callstrip_l_blanks(opt5) >*/
    feq_gen_strip_l_blanks_d_(opt5, (ftnlen)5);
/* SOURCE genscn.for:1375 */
/*<       if(opt5(1:3).eq.'ADD')then >*/
    if (s_cmp(opt5, const_cast<char*>("ADD"), (ftnlen)3, (ftnlen)3) == 0) {
/* SOURCE genscn.for:1376 */
/*<       addflag=1 >*/
	addflag = 1;
/* SOURCE genscn.for:1377 */
/*<       elseif(opt5(1:3).eq.'SUB')then >*/
    } else if (s_cmp(opt5, const_cast<char*>("SUB"), (ftnlen)3, (ftnlen)3) == 0) {
/* SOURCE genscn.for:1378 */
/*<       addflag=-1 >*/
	addflag = -1;
/* SOURCE genscn.for:1379 */
/*<       else >*/
    } else {
/* SOURCE genscn.for:1380 */
/*<       write(stdout,77)opt5(1:3) >*/
	feq_gen_io_d__161.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__161);
	do_fio(&feq_gen_c_d_1, opt5, (ftnlen)3);
	e_wsfe();
/* SOURCE genscn.for:1381 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE genscn.for:1382 */
/*<       endif >*/
    }
/* SOURCE genscn.for:1384 */
/*<       if(brain.ne.0)goto120 >*/
    if (brain != 0) {
	goto L120;
    }
/*       EXTERIOR NODE or pump or gate name */
/*         Make sure the node name is left justified */
/* SOURCE genscn.for:1388 */
/*<       callstrip_l_blanks(node_item) >*/
    feq_gen_strip_l_blanks_d_(feq_gen_node_item_d_, (ftnlen)16);
/*         Is this a pump or gate name? */
/*         CATCH THE SPECIAL DESIGNATION FOR MCHENRY SLUICE GATES */
/* SOURCE genscn.for:1394 */
/*<       if(node_item.eq.'MCHN')then >*/
    if (s_cmp(feq_gen_node_item_d_, const_cast<char*>("MCHN"), (ftnlen)16, (ftnlen)4) == 0) {
/* SOURCE genscn.for:1395 */
/*<       if(addflag.eq.1)then >*/
	if (addflag == 1) {
/* SOURCE genscn.for:1396 */
/*<       gate_pump_flag(mngate+1)=1 >*/
	    feq_gen_gate_pump_flag_d_[50] = 1;
/* SOURCE genscn.for:1397 */
/*<       gate_pump_name(mngate+1)='MCHN' >*/
	    s_copy(feq_gen_gate_pump_name_d_ + 800, const_cast<char*>("MCHN"), (ftnlen)16, (ftnlen)4);
/* SOURCE genscn.for:1398 */
/*<       gate_pump_ip(mngate+1)=0 >*/
	    feq_gen_gate_pump_ip_d_[50] = 0;
/* SOURCE genscn.for:1399 */
/*<       else >*/
	} else {
/* SOURCE genscn.for:1400 */
/*<       gate_pump_flag(mngate+1)=0 >*/
	    feq_gen_gate_pump_flag_d_[50] = 0;
/* SOURCE genscn.for:1401 */
/*<       endif >*/
	}
/* SOURCE genscn.for:1402 */
/*<       goto100 >*/
	goto L100;
/* SOURCE genscn.for:1403 */
/*<       endif >*/
    }
/* SOURCE genscn.for:1404 */
/*<       if(ngate.gt.0)then >*/
    if (gate1_1.ngate > 0) {
/*           Now check if the node designation field has a name for */
/*           an adjustable gate or pump. */
/* SOURCE genscn.for:1408 */
/*<       calllstab(node_item,gname,ngate,ip) >*/
	lstab_(feq_gen_node_item_d_, gate2_1.gname, &gate1_1.ngate, &ip, (ftnlen)16, (
		ftnlen)16);
/* SOURCE genscn.for:1411 */
/*<       else >*/
    } else {
/* SOURCE genscn.for:1412 */
/*<       ip=0 >*/
	ip = 0;
/* SOURCE genscn.for:1413 */
/*<       endif >*/
    }
/* SOURCE genscn.for:1414 */
/*<       if(ip.gt.0)then >*/
    if (ip > 0) {
/*           Name found in the table. */
/* SOURCE genscn.for:1416 */
/*<       if(addflag.eq.1)then >*/
	if (addflag == 1) {
/* SOURCE genscn.for:1417 */
/*<       gate_pump_flag(ip)=1 >*/
	    feq_gen_gate_pump_flag_d_[ip - 1] = 1;
/* SOURCE genscn.for:1418 */
/*<       gate_pump_name(ip)=node_item >*/
	    s_copy(feq_gen_gate_pump_name_d_ + (ip - 1 << 4), feq_gen_node_item_d_, (ftnlen)16, 
		    (ftnlen)16);
/* SOURCE genscn.for:1419 */
/*<       gate_pump_ip(ip)=ip >*/
	    feq_gen_gate_pump_ip_d_[ip - 1] = ip;
/* SOURCE genscn.for:1420 */
/*<       else >*/
	} else {
/* SOURCE genscn.for:1421 */
/*<       gate_pump_flag(ip)=0 >*/
	    feq_gen_gate_pump_flag_d_[ip - 1] = 0;
/* SOURCE genscn.for:1422 */
/*<       endif >*/
	}
/* SOURCE genscn.for:1423 */
/*<       goto100 >*/
	goto L100;
/* SOURCE genscn.for:1424 */
/*<       endif >*/
    }
/* SOURCE genscn.for:1427 */
/*<       char5=node_item >*/
    s_copy(char5, feq_gen_node_item_d_, (ftnlen)5, (ftnlen)16);
/* SOURCE genscn.for:1428 */
/*<       callgetinn(char5,eflag,node) >*/
    getinn_(char5, eflag, &node, (ftnlen)5);
/* SOURCE genscn.for:1431 */
/*<       if(node.gt.0)then >*/
    if (node > 0) {
/* SOURCE genscn.for:1433 */
/*<       if(addflag.eq.1)then >*/
	if (addflag == 1) {
/* SOURCE genscn.for:1434 */
/*<       enode_flag(node)=1 >*/
	    feq_gen_enode_flag_d_[node - 1] = 1;
/* SOURCE genscn.for:1435 */
/*<       enode_bra(node)=exnodt(3,node) >*/
	    feq_gen_enode_bra_d_[node - 1] = exnodt[node * 9 + 3];
/* SOURCE genscn.for:1436 */
/*<       else >*/
	} else {
/* SOURCE genscn.for:1437 */
/*<       enode_flag(node)=0 >*/
	    feq_gen_enode_flag_d_[node - 1] = 0;
/* SOURCE genscn.for:1438 */
/*<       enode_bra(node)=0 >*/
	    feq_gen_enode_bra_d_[node - 1] = 0;
/* SOURCE genscn.for:1439 */
/*<       endif >*/
	}
/* SOURCE genscn.for:1441 */
/*<       else >*/
    } else {
/*           The user has prefixed the exterior node id with a - to */
/*           signal that output of tributary area flow for the reservoir */
/*           is desired. */
/* SOURCE genscn.for:1445 */
/*<       node=iabs(node) >*/
	node = abs(node);
/* SOURCE genscn.for:1446 */
/*<       do112i=1,nrwta >*/
	feq_gen_i_d_1 = *nrwta;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE genscn.for:1447 */
/*<       if(node.eq.rwta(i))then >*/
	    if (node == rwta[feq_gen_i_d_]) {
/* SOURCE genscn.for:1448 */
/*<       if(addflag.eq.1)then >*/
		if (addflag == 1) {
/* SOURCE genscn.for:1449 */
/*<       enode_flag(node)=1 >*/
		    feq_gen_enode_flag_d_[node - 1] = 1;
/* SOURCE genscn.for:1450 */
/*<       enode_bra(node)=-(rtap(i)+10000) >*/
		    feq_gen_enode_bra_d_[node - 1] = -(rtap[feq_gen_i_d_] + 10000);
/* SOURCE genscn.for:1451 */
/*<       else >*/
		} else {
/* SOURCE genscn.for:1452 */
/*<       enode_flag(node)=0 >*/
		    feq_gen_enode_flag_d_[node - 1] = 0;
/* SOURCE genscn.for:1453 */
/*<       enode_bra(node)=0 >*/
		    feq_gen_enode_bra_d_[node - 1] = 0;
/* SOURCE genscn.for:1454 */
/*<       endif >*/
		}
/* SOURCE genscn.for:1455 */
/*<       endif >*/
	    }
/* SOURCE genscn.for:1456 */
/*<   112 continue >*/
/* L112: */
	}
/* SOURCE genscn.for:1457 */
/*<       write(stdout,51)char5 >*/
	feq_gen_io_d__165.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__165);
	do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
	e_wsfe();
/* SOURCE genscn.for:1458 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE genscn.for:1459 */
/*<       endif >*/
    }
/* SOURCE genscn.for:1461 */
/*<       goto100 >*/
    goto L100;
/*       Branch number has been given */
/* SOURCE genscn.for:1464 */
/*<   120 continue >*/
L120:
/* SOURCE genscn.for:1465 */
/*<       read(node_item,'(I8)',err=991)node >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 16;
    feq_gen_ici_d_1.iciunit = feq_gen_node_item_d_;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(I8)");
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&node, (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE genscn.for:1466 */
/*<       callgetinb(brain,eflag,bra) >*/
    getinb_(&brain, eflag, &bra);
/* SOURCE genscn.for:1469 */
/*<       fn=brpt(3,bra) >*/
    fn = brpt[(bra << 3) + 3];
/* SOURCE genscn.for:1470 */
/*<       ln=brpt(4,bra) >*/
    ln = brpt[(bra << 3) + 4];
/* SOURCE genscn.for:1472 */
/*<       if(node.eq.0)then >*/
    if (node == 0) {
/*         Dump the whole branch option. */
/* SOURCE genscn.for:1474 */
/*<       do130j=fn,ln >*/
	feq_gen_i_d_1 = ln;
	for (j = fn; j <= feq_gen_i_d_1; ++j) {
/* SOURCE genscn.for:1475 */
/*<       genscn_nout=genscn_nout+1 >*/
	    ++genscn_1.feq_gen_genscn_nout_d_;
/* SOURCE genscn.for:1476 */
/*<       if(addflag.eq.1)then >*/
	    if (addflag == 1) {
/* SOURCE genscn.for:1477 */
/*<       bnode_flag(j)=1 >*/
		feq_gen_bnode_flag_d_[j - 1] = 1;
/* SOURCE genscn.for:1478 */
/*<       bnode_bra(j)=bra >*/
		feq_gen_bnode_bra_d_[j - 1] = bra;
/* SOURCE genscn.for:1479 */
/*<       else >*/
	    } else {
/* SOURCE genscn.for:1480 */
/*<       bnode_flag(j)=0 >*/
		feq_gen_bnode_flag_d_[j - 1] = 0;
/* SOURCE genscn.for:1481 */
/*<       endif >*/
	    }
/* SOURCE genscn.for:1482 */
/*<   130 continue >*/
/* L130: */
	}
/* SOURCE genscn.for:1483 */
/*<       goto100 >*/
	goto L100;
/* SOURCE genscn.for:1484 */
/*<       endif >*/
    }
/* SOURCE genscn.for:1486 */
/*<       fa=brpt(3,bra) >*/
    fa = brpt[(bra << 3) + 3];
/* SOURCE genscn.for:1487 */
/*<       fn=brpt(1,bra) >*/
    fn = brpt[(bra << 3) + 1];
/* SOURCE genscn.for:1488 */
/*<       ln=brpt(2,bra) >*/
    ln = brpt[(bra << 3) + 2];
/* SOURCE genscn.for:1490 */
/*<       if(abs(node).lt.fn.or.abs(node).gt.ln)then >*/
    if (abs(node) < fn || abs(node) > ln) {
/* SOURCE genscn.for:1491 */
/*<       nde=abs(node) >*/
	nde = abs(node);
/* SOURCE genscn.for:1492 */
/*<       callkil(2,nde,eflag) >*/
	kil_(&feq_gen_c_d_2, &nde, eflag);
/* SOURCE genscn.for:1495 */
/*<       node=-nde >*/
	node = -nde;
/* SOURCE genscn.for:1496 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE genscn.for:1497 */
/*<       endif >*/
    }
/*       COMPUTE ADDRESS FOR THIS BRANCH AND NODE NUMBER */
/* SOURCE genscn.for:1500 */
/*<       j=fa+abs(node)-fn >*/
    j = fa + abs(node) - fn;
/* SOURCE genscn.for:1501 */
/*<       if(node.gt.0)then >*/
    if (node > 0) {
/* SOURCE genscn.for:1502 */
/*<       if(addflag.eq.1)then >*/
	if (addflag == 1) {
/* SOURCE genscn.for:1503 */
/*<       bnode_flag(j)=1 >*/
	    feq_gen_bnode_flag_d_[j - 1] = 1;
/* SOURCE genscn.for:1504 */
/*<       bnode_bra(j)=bra >*/
	    feq_gen_bnode_bra_d_[j - 1] = bra;
/* SOURCE genscn.for:1505 */
/*<       else >*/
	} else {
/* SOURCE genscn.for:1506 */
/*<       bnode_flag(j)=0 >*/
	    feq_gen_bnode_flag_d_[j - 1] = 0;
/* SOURCE genscn.for:1507 */
/*<       endif >*/
	}
/* SOURCE genscn.for:1508 */
/*<       else >*/
    } else {
/* SOURCE genscn.for:1509 */
/*<       if(addflag.eq.1)then >*/
	if (addflag == 1) {
/* SOURCE genscn.for:1510 */
/*<       bnode_flag(j)=1 >*/
	    feq_gen_bnode_flag_d_[j - 1] = 1;
/* SOURCE genscn.for:1511 */
/*<       bnode_bra(j)=-bra >*/
	    feq_gen_bnode_bra_d_[j - 1] = -bra;
/* SOURCE genscn.for:1512 */
/*<       else >*/
	} else {
/* SOURCE genscn.for:1513 */
/*<       bnode_flag(j)=0 >*/
	    feq_gen_bnode_flag_d_[j - 1] = 0;
/* SOURCE genscn.for:1514 */
/*<       endif >*/
	}
/* SOURCE genscn.for:1515 */
/*<       endif >*/
    }
/* SOURCE genscn.for:1517 */
/*<       goto100 >*/
    goto L100;
/* SOURCE genscn.for:1519 */
/*<   150 continue >*/
L150:
/*     Construct and output the directory information to the FEO file. */
/*     We will output the exterior nodes first, followed by the */
/*     nodes on branches.  We will permit duplication of the exterior */
/*     nodes on branches.   The user can avoid this duplication if */
/*     they so wish. */
/*     18 June 2002:  A bug in GENSCN makes plotting of free nodes impossible */
/*     unless the free node has a non-zero FTAB index.  LPR's do have such an */
/*     index but inflow nodes for LPR's and nodes on dummy branches do not. */
/*     It is a pain to fill these in manually.  Thus we will establish a default */
/*     ftab index when we need it.  Every model must have one branch so */
/*     there will always be some nodes on a branch and thes have an ftab index */
/*     to the cross-section function table.  Therefore we take the ftab index */
/*     for the first cross section of the first branch.  Apparently GENSCN does */
/*     not use the info in the ftable-we hope because it should no look for one */
/*     when one does not exist. */
/* SOURCE genscn.for:1537 */
/*<       ftab_dummy=nsec(1) >*/
    feq_gen_ftab_dummy_d_ = bnothr_1.nsec[0];
/*     Finally we output information on pumps and gates */
/* SOURCE genscn.for:1541 */
/*<       genscn_nout=0 >*/
    genscn_1.feq_gen_genscn_nout_d_ = 0;
/* SOURCE genscn.for:1543 */
/*<       do200ii=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (ii = 1; ii <= feq_gen_i_d_1; ++ii) {
/* SOURCE genscn.for:1544 */
/*<       i=usnsrt(ii) >*/
	feq_gen_i_d_ = inen_1.usnsrt[ii - 1];
/* SOURCE genscn.for:1545 */
/*<       if(enode_flag(i).eq.1)then >*/
	if (feq_gen_enode_flag_d_[feq_gen_i_d_ - 1] == 1) {
/*         Output this item */
/* SOURCE genscn.for:1547 */
/*<       genscn_nout=genscn_nout+1 >*/
	    ++genscn_1.feq_gen_genscn_nout_d_;
/* SOURCE genscn.for:1548 */
/*<       if(genscn_nout.gt.mngsout)then >*/
	    if (genscn_1.feq_gen_genscn_nout_d_ > 20000) {
/* SOURCE genscn.for:1549 */
/*<       write(stdout,7)genscn_nout >*/
		feq_gen_io_d__171.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__171);
		do_fio(&feq_gen_c_d_1, (char *)&genscn_1.feq_gen_genscn_nout_d_, (ftnlen)sizeof(
			integer));
		e_wsfe();
/* SOURCE genscn.for:1550 */
/*<       genscn_nout=1 >*/
		genscn_1.feq_gen_genscn_nout_d_ = 1;
/* SOURCE genscn.for:1551 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE genscn.for:1552 */
/*<       endif >*/
	    }
/*         Setup the internal pointer to get the node info */
/* SOURCE genscn.for:1555 */
/*<       if(enode_bra(i).gt.-10000)then >*/
	    if (feq_gen_enode_bra_d_[feq_gen_i_d_ - 1] > -10000) {
/* SOURCE genscn.for:1556 */
/*<       genscn_pout(genscn_nout)=-i >*/
		genscn_1.feq_gen_genscn_pout_d_[genscn_1.feq_gen_genscn_nout_d_ - 1] = -feq_gen_i_d_;
/* SOURCE genscn.for:1557 */
/*<       else >*/
	    } else {
/* SOURCE genscn.for:1558 */
/*<       genscn_pout(genscn_nout)=enode_bra(i) >*/
		genscn_1.feq_gen_genscn_pout_d_[genscn_1.feq_gen_genscn_nout_d_ - 1] = 
			feq_gen_enode_bra_d_[feq_gen_i_d_ - 1];
/* SOURCE genscn.for:1559 */
/*<       endif >*/
	    }
/*         Identify the character of the exterior node. */
/* SOURCE genscn.for:1562 */
/*<       if(exnodt(3,i).gt.0)then >*/
	    if (exnodt[feq_gen_i_d_ * 9 + 3] > 0) {
/*           Exterior node for a branch. */
/* SOURCE genscn.for:1564 */
/*<       ip=exnodt(2,i) >*/
		ip = exnodt[feq_gen_i_d_ * 9 + 2];
/* SOURCE genscn.for:1565 */
/*<       station=xvec(ip)/sfac >*/
		station = static_cast<double>(bnelem_1.xvec[ip - 1]) / *sfac;
/* SOURCE genscn.for:1566 */
/*<       invert_elevation=zvec(ip) >*/
		feq_gen_invert_elevation_d_ = bnelem_1.zvec[ip - 1];
/* SOURCE genscn.for:1567 */
/*<       ftab_index=exnodt(4,i) >*/
		feq_gen_ftab_index_d_ = exnodt[feq_gen_i_d_ * 9 + 4];
/* SOURCE genscn.for:1568 */
/*<       location_class='BNODE' >*/
		s_copy(feq_gen_location_class_d_, const_cast<char*>("BNODE"), (ftnlen)5, (ftnlen)5);
/* SOURCE genscn.for:1569 */
/*<       brain=inbrus(exnodt(3,i)) >*/
		brain = inbr_1.inbrus[exnodt[feq_gen_i_d_ * 9 + 3] - 1];
/* SOURCE genscn.for:1570 */
/*<       elseif(exnodt(3,i).eq.0)then >*/
	    } else if (exnodt[feq_gen_i_d_ * 9 + 3] == 0) {
/*           Exterior node not on a branch and not a LPR */
/* SOURCE genscn.for:1572 */
/*<       if(exnodt(8,i).ne.null)then >*/
		if (exnodt[feq_gen_i_d_ * 9 + 8] != null) {
/* SOURCE genscn.for:1573 */
/*<       station=dble(exnodt(8,i))/1.d4 >*/
		    station = (doublereal) exnodt[feq_gen_i_d_ * 9 + 8] / 1e4;
/* SOURCE genscn.for:1574 */
/*<       else >*/
		} else {
/* SOURCE genscn.for:1575 */
/*<       station=-1.e30 >*/
		    station = (float)-1e30;
/* SOURCE genscn.for:1576 */
/*<       endif >*/
		}
/* SOURCE genscn.for:1577 */
/*<       invert_elevation=ze(i) >*/
		feq_gen_invert_elevation_d_ = enelem_1.ze[feq_gen_i_d_ - 1];
/* SOURCE genscn.for:1578 */
/*<       ftab_index=ftab_dummy >*/
		feq_gen_ftab_index_d_ = feq_gen_ftab_dummy_d_;
/* SOURCE genscn.for:1579 */
/*<       location_class='FNODE' >*/
		s_copy(feq_gen_location_class_d_, const_cast<char*>("FNODE"), (ftnlen)5, (ftnlen)5);
/* SOURCE genscn.for:1580 */
/*<       brain=0 >*/
		brain = 0;
/* SOURCE genscn.for:1581 */
/*<       else >*/
	    } else {
/*           Has to be a LPR node. */
/* SOURCE genscn.for:1583 */
/*<       if(exnodt(8,i).ne.null)then >*/
		if (exnodt[feq_gen_i_d_ * 9 + 8] != null) {
/* SOURCE genscn.for:1584 */
/*<       station=dble(exnodt(8,i))/1.d4 >*/
		    station = (doublereal) exnodt[feq_gen_i_d_ * 9 + 8] / 1e4;
/* SOURCE genscn.for:1585 */
/*<       else >*/
		} else {
/* SOURCE genscn.for:1586 */
/*<       station=-1.e30 >*/
		    station = (float)-1e30;
/* SOURCE genscn.for:1587 */
/*<       endif >*/
		}
/* SOURCE genscn.for:1588 */
/*<       invert_elevation=ze(i) >*/
		feq_gen_invert_elevation_d_ = enelem_1.ze[feq_gen_i_d_ - 1];
/* SOURCE genscn.for:1589 */
/*<       ftab_index=exnodt(4,i) >*/
		feq_gen_ftab_index_d_ = exnodt[feq_gen_i_d_ * 9 + 4];
/* SOURCE genscn.for:1590 */
/*<       location_class='LPR  ' >*/
		s_copy(feq_gen_location_class_d_, const_cast<char*>("LPR  "), (ftnlen)5, (ftnlen)5);
/* SOURCE genscn.for:1591 */
/*<       brain=0 >*/
		brain = 0;
/* SOURCE genscn.for:1592 */
/*<       endif >*/
	    }
/*         Write the next line to the FEO file. */
/* SOURCE genscn.for:1595 */
/*<       if(exnodt(6,i).ne.null)then >*/
	    if (exnodt[feq_gen_i_d_ * 9 + 6] != null) {
/*           We have (x,y) location */
/* SOURCE genscn.for:1597 */
/*<       easting=dble(exnodt(6,i))/100.d0 >*/
		easting = (doublereal) exnodt[feq_gen_i_d_ * 9 + 6] / 100.;
/* SOURCE genscn.for:1598 */
/*<       northing=dble(exnodt(7,i))/100.d0 >*/
		northing = (doublereal) exnodt[feq_gen_i_d_ * 9 + 7] / 100.;
/* SOURCE genscn.for:1599 */
/*<       else >*/
	    } else {
/* SOURCE genscn.for:1600 */
/*<       easting=0.d0 >*/
		easting = 0.;
/* SOURCE genscn.for:1601 */
/*<       northing=0.d0 >*/
		northing = 0.;
/* SOURCE genscn.for:1602 */
/*<       endif >*/
	    }
/* SOURCE genscn.for:1603 */
/*<       write(eaststring,'(F12.2)')easting >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 12;
	    feq_gen_ici_d_1.iciunit = eaststring;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F12.2)");
	    s_wsfi(&feq_gen_ici_d_1);
	    do_fio(&feq_gen_c_d_1, (char *)&easting, (ftnlen)sizeof(doublereal));
	    e_wsfi();
/* SOURCE genscn.for:1604 */
/*<       write(northstring,'(F12.2)')northing >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 12;
	    feq_gen_ici_d_1.iciunit = northstring;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F12.2)");
	    s_wsfi(&feq_gen_ici_d_1);
	    do_fio(&feq_gen_c_d_1, (char *)&northing, (ftnlen)sizeof(doublereal));
	    e_wsfi();
/* SOURCE genscn.for:1605 */
/*<       char7=inenus(i) >*/
	    s_copy(char7, inenc_1.inenus + (feq_gen_i_d_ - 1) * 5, (ftnlen)7, (ftnlen)
		    5);
/* SOURCE genscn.for:1606 */
/*<       user_id_string=enodid(i) >*/
	    s_copy(feq_gen_user_id_string_d_, enothc_1.enodid + (feq_gen_i_d_ - 1 << 4), (
		    ftnlen)16, (ftnlen)16);
/* SOURCE genscn.for:1607 */
/*<       if(new_genscn_feo.eq.'NO')then >*/
	    if (s_cmp(feq_gen_new_genscn_feo_d_, const_cast<char*>("NO"), (ftnlen)4, (ftnlen)2) == 0) {
/* SOURCE genscn.for:1608 */
/*<       callstrip_l_blanks(char7) >*/
		feq_gen_strip_l_blanks_d_(char7, (ftnlen)7);
/* SOURCE genscn.for:1610 */
/*<       char5=char7 >*/
		s_copy(char5, char7, (ftnlen)5, (ftnlen)7);
/* SOURCE genscn.for:1611 */
/*<        >*/
		feq_gen_io_d__182.ciunit = genscn_1.feq_gen_feo_unit_d_;
		s_wsfe(&feq_gen_io_d__182);
		do_fio(&feq_gen_c_d_1, enothc_1.enodid + (feq_gen_i_d_ - 1 << 4), (ftnlen)16);
		do_fio(&feq_gen_c_d_1, feq_gen_location_class_d_, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, (char *)&brain, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, (char *)&station, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_invert_elevation_d_, (ftnlen)sizeof(
			real));
		do_fio(&feq_gen_c_d_1, feq_gen_user_id_string_d_, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_ftab_index_d_, (ftnlen)sizeof(integer));
		feq_gen_i_d_2 = (genscn_1.feq_gen_genscn_nout_d_ - 1 << 1) + 1;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_2, (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE genscn.for:1615 */
/*<       else >*/
	    } else {
/* SOURCE genscn.for:1616 */
/*<        >*/
		feq_gen_io_d__183.ciunit = genscn_1.feq_gen_feo_unit_d_;
		s_wsfe(&feq_gen_io_d__183);
		do_fio(&feq_gen_c_d_1, enothc_1.enodid + (feq_gen_i_d_ - 1 << 4), (ftnlen)16);
		do_fio(&feq_gen_c_d_1, feq_gen_location_class_d_, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, (char *)&brain, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, char7, (ftnlen)7);
		do_fio(&feq_gen_c_d_1, (char *)&station, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_invert_elevation_d_, (ftnlen)sizeof(
			real));
		do_fio(&feq_gen_c_d_1, feq_gen_user_id_string_d_, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_ftab_index_d_, (ftnlen)sizeof(integer));
		feq_gen_i_d_2 = (genscn_1.feq_gen_genscn_nout_d_ - 1 << 1) + 1;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_2, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, eaststring, (ftnlen)12);
		do_fio(&feq_gen_c_d_1, northstring, (ftnlen)12);
		e_wsfe();
/* SOURCE genscn.for:1620 */
/*<       endif >*/
	    }
/* SOURCE genscn.for:1621 */
/*<       endif >*/
	}
/* SOURCE genscn.for:1622 */
/*<   200 continue >*/
/* L200: */
    }
/*     Do the nodes on branches next */
/* SOURCE genscn.for:1625 */
/*<       do300i=1,nbn >*/
    feq_gen_i_d_1 = *nbn;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE genscn.for:1626 */
/*<       if(bnode_flag(i).eq.1)then >*/
	if (feq_gen_bnode_flag_d_[feq_gen_i_d_ - 1] == 1) {
/* SOURCE genscn.for:1627 */
/*<       genscn_nout=genscn_nout+1 >*/
	    ++genscn_1.feq_gen_genscn_nout_d_;
/* SOURCE genscn.for:1628 */
/*<       if(genscn_nout.gt.mngsout)then >*/
	    if (genscn_1.feq_gen_genscn_nout_d_ > 20000) {
/* SOURCE genscn.for:1629 */
/*<       write(stdout,7)genscn_nout >*/
		feq_gen_io_d__184.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__184);
		do_fio(&feq_gen_c_d_1, (char *)&genscn_1.feq_gen_genscn_nout_d_, (ftnlen)sizeof(
			integer));
		e_wsfe();
/* SOURCE genscn.for:1630 */
/*<       genscn_nout=1 >*/
		genscn_1.feq_gen_genscn_nout_d_ = 1;
/* SOURCE genscn.for:1631 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE genscn.for:1632 */
/*<       endif >*/
	    }
/*         Output this node on a branch */
/* SOURCE genscn.for:1634 */
/*<       ibra=bnode_bra(i) >*/
	    ibra = feq_gen_bnode_bra_d_[feq_gen_i_d_ - 1];
/* SOURCE genscn.for:1635 */
/*<       if(ibra.gt.0)then >*/
	    if (ibra > 0) {
/* SOURCE genscn.for:1636 */
/*<       genscn_pout(genscn_nout)=i >*/
		genscn_1.feq_gen_genscn_pout_d_[genscn_1.feq_gen_genscn_nout_d_ - 1] = feq_gen_i_d_;
/* SOURCE genscn.for:1637 */
/*<       else >*/
	    } else {
/* SOURCE genscn.for:1638 */
/*<       genscn_pout(genscn_nout)=i+10000 >*/
		genscn_1.feq_gen_genscn_pout_d_[genscn_1.feq_gen_genscn_nout_d_ - 1] = feq_gen_i_d_ + 
			10000;
/* SOURCE genscn.for:1639 */
/*<       ibra=abs(ibra) >*/
		ibra = abs(ibra);
/* SOURCE genscn.for:1640 */
/*<       endif >*/
	    }
/* SOURCE genscn.for:1641 */
/*<       station=xvec(i)/sfac >*/
	    station = static_cast<double>(bnelem_1.xvec[feq_gen_i_d_ - 1]) / *sfac;
/* SOURCE genscn.for:1642 */
/*<       invert_elevation=zvec(i) >*/
	    feq_gen_invert_elevation_d_ = bnelem_1.zvec[feq_gen_i_d_ - 1];
/* SOURCE genscn.for:1643 */
/*<       ftab_index=nsec(i) >*/
	    feq_gen_ftab_index_d_ = bnothr_1.nsec[feq_gen_i_d_ - 1];
/* SOURCE genscn.for:1644 */
/*<       location_class='BNODE' >*/
	    s_copy(feq_gen_location_class_d_, const_cast<char*>("BNODE"), (ftnlen)5, (ftnlen)5);
/*         Compute the user node number on the branch. */
/* SOURCE genscn.for:1646 */
/*<       fn=brpt(1,ibra) >*/
	    fn = brpt[(ibra << 3) + 1];
/* SOURCE genscn.for:1647 */
/*<       fa=brpt(3,ibra) >*/
	    fa = brpt[(ibra << 3) + 3];
/* SOURCE genscn.for:1648 */
/*<       write(char7,'(I7)')i-fa+fn >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 7;
	    feq_gen_ici_d_1.iciunit = char7;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(I7)");
	    s_wsfi(&feq_gen_ici_d_1);
	    feq_gen_i_d_2 = feq_gen_i_d_ - fa + fn;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_2, (ftnlen)sizeof(integer));
	    e_wsfi();
/* SOURCE genscn.for:1649 */
/*<       brain=inbrus(bnode_bra(i)) >*/
	    brain = inbr_1.inbrus[feq_gen_bnode_bra_d_[feq_gen_i_d_ - 1] - 1];
/* SOURCE genscn.for:1650 */
/*<       user_id_string=bnodid(i) >*/
	    s_copy(feq_gen_user_id_string_d_, bnothc_1.bnodid + (feq_gen_i_d_ - 1 << 4), (
		    ftnlen)16, (ftnlen)16);
/* SOURCE genscn.for:1651 */
/*<       x=get_dp_from_ft(ftab_index+8) >*/
	    feq_gen_i_d_2 = feq_gen_ftab_index_d_ + 8;
	    x = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_2);
/* SOURCE genscn.for:1652 */
/*<       y=get_dp_from_ft(ftab_index+10) >*/
	    feq_gen_i_d_2 = feq_gen_ftab_index_d_ + 10;
	    y = feq_gen_get_dp_from_ft_d_(&feq_gen_i_d_2);
/* SOURCE genscn.for:1654 */
/*<       write(eaststring,'(F12.2)')x >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 12;
	    feq_gen_ici_d_1.iciunit = eaststring;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F12.2)");
	    s_wsfi(&feq_gen_ici_d_1);
	    do_fio(&feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(doublereal));
	    e_wsfi();
/* SOURCE genscn.for:1655 */
/*<       write(northstring,'(F12.2)')y >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 12;
	    feq_gen_ici_d_1.iciunit = northstring;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F12.2)");
	    s_wsfi(&feq_gen_ici_d_1);
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(doublereal));
	    e_wsfi();
/* SOURCE genscn.for:1656 */
/*<       if(new_genscn_feo.eq.'NO')then >*/
	    if (s_cmp(feq_gen_new_genscn_feo_d_, const_cast<char*>("NO"), (ftnlen)4, (ftnlen)2) == 0) {
/* SOURCE genscn.for:1657 */
/*<       callstrip_l_blanks(char7) >*/
		feq_gen_strip_l_blanks_d_(char7, (ftnlen)7);
/* SOURCE genscn.for:1659 */
/*<       char5=char7 >*/
		s_copy(char5, char7, (ftnlen)5, (ftnlen)7);
/* SOURCE genscn.for:1660 */
/*<        >*/
		feq_gen_io_d__187.ciunit = genscn_1.feq_gen_feo_unit_d_;
		s_wsfe(&feq_gen_io_d__187);
		do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (feq_gen_i_d_ - 1 << 4), (ftnlen)16);
		do_fio(&feq_gen_c_d_1, feq_gen_location_class_d_, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, (char *)&brain, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, (char *)&station, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_invert_elevation_d_, (ftnlen)sizeof(
			real));
		do_fio(&feq_gen_c_d_1, feq_gen_user_id_string_d_, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_ftab_index_d_, (ftnlen)sizeof(integer));
		feq_gen_i_d_2 = (genscn_1.feq_gen_genscn_nout_d_ - 1 << 1) + 1;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_2, (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE genscn.for:1665 */
/*<       else >*/
	    } else {
/* SOURCE genscn.for:1666 */
/*<        >*/
		feq_gen_io_d__188.ciunit = genscn_1.feq_gen_feo_unit_d_;
		s_wsfe(&feq_gen_io_d__188);
		do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (feq_gen_i_d_ - 1 << 4), (ftnlen)16);
		do_fio(&feq_gen_c_d_1, feq_gen_location_class_d_, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, (char *)&brain, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, char7, (ftnlen)7);
		do_fio(&feq_gen_c_d_1, (char *)&station, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_invert_elevation_d_, (ftnlen)sizeof(
			real));
		do_fio(&feq_gen_c_d_1, feq_gen_user_id_string_d_, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_ftab_index_d_, (ftnlen)sizeof(integer));
		feq_gen_i_d_2 = (genscn_1.feq_gen_genscn_nout_d_ - 1 << 1) + 1;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_2, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, eaststring, (ftnlen)12);
		do_fio(&feq_gen_c_d_1, northstring, (ftnlen)12);
		e_wsfe();
/* SOURCE genscn.for:1670 */
/*<       endif >*/
	    }
/* SOURCE genscn.for:1671 */
/*<       endif >*/
	}
/* SOURCE genscn.for:1673 */
/*<   300 continue >*/
/* L300: */
    }
/* SOURCE genscn.for:1675 */
/*<       if(new_genscn_feo.eq.'YES')then >*/
    if (s_cmp(feq_gen_new_genscn_feo_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3) == 0) {
/* SOURCE genscn.for:1676 */
/*<       do400i=1,mngate+1 >*/
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 51; ++feq_gen_i_d_) {
/* SOURCE genscn.for:1677 */
/*<       if(gate_pump_flag(i).gt.0)then >*/
	    if (feq_gen_gate_pump_flag_d_[feq_gen_i_d_ - 1] > 0) {
/* SOURCE genscn.for:1678 */
/*<       genscn_nout=genscn_nout+1 >*/
		++genscn_1.feq_gen_genscn_nout_d_;
/* SOURCE genscn.for:1679 */
/*<       if(genscn_nout.gt.mngsout)then >*/
		if (genscn_1.feq_gen_genscn_nout_d_ > 20000) {
/* SOURCE genscn.for:1680 */
/*<       write(stdout,7)genscn_nout >*/
		    feq_gen_io_d__189.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__189);
		    do_fio(&feq_gen_c_d_1, (char *)&genscn_1.feq_gen_genscn_nout_d_, (ftnlen)
			    sizeof(integer));
		    e_wsfe();
/* SOURCE genscn.for:1681 */
/*<       genscn_nout=1 >*/
		    genscn_1.feq_gen_genscn_nout_d_ = 1;
/* SOURCE genscn.for:1682 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE genscn.for:1683 */
/*<       endif >*/
		}
/* SOURCE genscn.for:1684 */
/*<       genscn_pout(genscn_nout)=-(20000+gate_pump_ip(i)) >*/
		genscn_1.feq_gen_genscn_pout_d_[genscn_1.feq_gen_genscn_nout_d_ - 1] = -(
			feq_gen_gate_pump_ip_d_[feq_gen_i_d_ - 1] + 20000);
/* SOURCE genscn.for:1685 */
/*<       station=-1.e30 >*/
		station = (float)-1e30;
/* SOURCE genscn.for:1686 */
/*<       invert_elevation=-3000.0 >*/
		feq_gen_invert_elevation_d_ = (float)-3e3;
/* SOURCE genscn.for:1687 */
/*<       ftab_index=ftab_dummy >*/
		feq_gen_ftab_index_d_ = feq_gen_ftab_dummy_d_;
/* SOURCE genscn.for:1688 */
/*<       location_class='PMPGT' >*/
		s_copy(feq_gen_location_class_d_, const_cast<char*>("PMPGT"), (ftnlen)5, (ftnlen)5);
/* SOURCE genscn.for:1689 */
/*<       char7=' ' >*/
		s_copy(char7, const_cast<char*>(" "), (ftnlen)7, (ftnlen)1);
/* SOURCE genscn.for:1690 */
/*<       brain=0 >*/
		brain = 0;
/* SOURCE genscn.for:1691 */
/*<       user_id_string=gate_pump_name(i) >*/
		s_copy(feq_gen_user_id_string_d_, feq_gen_gate_pump_name_d_ + (feq_gen_i_d_ - 1 << 4), (
			ftnlen)16, (ftnlen)16);
/* SOURCE genscn.for:1692 */
/*<       eaststring=' ' >*/
		s_copy(eaststring, const_cast<char*>(" "), (ftnlen)12, (ftnlen)1);
/* SOURCE genscn.for:1693 */
/*<       northstring=' ' >*/
		s_copy(northstring, const_cast<char*>(" "), (ftnlen)12, (ftnlen)1);
/* SOURCE genscn.for:1694 */
/*<        >*/
		feq_gen_io_d__190.ciunit = genscn_1.feq_gen_feo_unit_d_;
		s_wsfe(&feq_gen_io_d__190);
		do_fio(&feq_gen_c_d_1, feq_gen_gate_pump_name_d_ + (feq_gen_i_d_ - 1 << 4), (ftnlen)16);
		do_fio(&feq_gen_c_d_1, feq_gen_location_class_d_, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, (char *)&brain, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, char7, (ftnlen)7);
		do_fio(&feq_gen_c_d_1, (char *)&station, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_invert_elevation_d_, (ftnlen)sizeof(
			real));
		do_fio(&feq_gen_c_d_1, feq_gen_user_id_string_d_, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_ftab_index_d_, (ftnlen)sizeof(integer));
		feq_gen_i_d_1 = (genscn_1.feq_gen_genscn_nout_d_ - 1 << 1) + 1;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, eaststring, (ftnlen)12);
		do_fio(&feq_gen_c_d_1, northstring, (ftnlen)12);
		e_wsfe();
/* SOURCE genscn.for:1699 */
/*<       endif >*/
	    }
/* SOURCE genscn.for:1700 */
/*<   400 continue >*/
/* L400: */
	}
/* SOURCE genscn.for:1701 */
/*<       endif >*/
    }
/* SOURCE genscn.for:1703 */
/*<       write(stdout,83)genscn_nout >*/
    feq_gen_io_d__191.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__191);
    do_fio(&feq_gen_c_d_1, (char *)&genscn_1.feq_gen_genscn_nout_d_, (ftnlen)sizeof(integer));
    e_wsfe();
/*     Write a terminating signal to the directory list. */
/* SOURCE genscn.for:1705 */
/*<       write(feo_unit,72) >*/
    feq_gen_io_d__192.ciunit = genscn_1.feq_gen_feo_unit_d_;
    s_wsfe(&feq_gen_io_d__192);
    e_wsfe();
/*     Only write the starting values now because we do not know the */
/*     ending record at this time. */
/* SOURCE genscn.for:1711 */
/*<       tsd_start=1 >*/
    feq_gen_tsd_start_d_ = 1;
/* SOURCE genscn.for:1712 */
/*<       write(feo_unit,56)genscn_nout,syr,smn,sdy,sfrac,sjtime,tsd_start >*/
    feq_gen_io_d__194.ciunit = genscn_1.feq_gen_feo_unit_d_;
    s_wsfe(&feq_gen_io_d__194);
    do_fio(&feq_gen_c_d_1, (char *)&genscn_1.feq_gen_genscn_nout_d_, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&julian_1.syr, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&julian_1.smn, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&julian_1.sdy, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&julian_1.sfrac, (ftnlen)sizeof(doublereal));
    do_fio(&feq_gen_c_d_1, (char *)&julian_1.sjtime, (ftnlen)sizeof(doublereal));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_tsd_start_d_, (ftnlen)sizeof(integer));
    e_wsfe();
/*     Open the TSD direct file. */
/* SOURCE genscn.for:1718 */
/*<       record_length_in_bytes=8*(1+genscn_nout) >*/
    feq_gen_record_length_in_bytes_d_ = genscn_1.feq_gen_genscn_nout_d_ + 1 << 3;
/* SOURCE genscn.for:1720 */
/*<       tsd_unit=get_unit(stdout) >*/
    genscn_1.feq_gen_tsd_unit_d_ = feq_gen_get_unit_d_(stdout);
/* SOURCE genscn.for:1721 */
/*<        >*/
    feq_gen_o_d_1.oerr = 1;
    feq_gen_o_d_1.ounit = genscn_1.feq_gen_tsd_unit_d_;
    feq_gen_o_d_1.ofnmlen = 256;
    feq_gen_o_d_1.ofnm = feq_gen_tsd_name_d_;
    feq_gen_o_d_1.orl = feq_gen_record_length_in_bytes_d_;
    feq_gen_o_d_1.osta = const_cast<char*>("UNKNOWN");
    feq_gen_o_d_1.oacc = const_cast<char*>("DIRECT");
    feq_gen_o_d_1.ofm = const_cast<char*>("UNFORMATTED");
    feq_gen_o_d_1.oblnk = 0;
    ioflag = f_open(&feq_gen_o_d_1);
/* SOURCE genscn.for:1725 */
/*<       if(ioflag.ne.0)then >*/
    if (ioflag != 0) {
/* SOURCE genscn.for:1726 */
/*<       write(stdout,*)' Problem in opening file: ',tsd_name >*/
	feq_gen_io_d__195.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__195);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Problem in opening file: "), (ftnlen)26);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_tsd_name_d_, (ftnlen)256);
	e_wsle();
/* SOURCE genscn.for:1727 */
/*<       write(stdout,*)' Check path for *.tsd file.' >*/
	feq_gen_io_d__196.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__196);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Check path for *.tsd file."), (ftnlen)27);
	e_wsle();
/* SOURCE genscn.for:1728 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE genscn.for:1729 */
/*<       endif >*/
    }
/* SOURCE genscn.for:1731 */
/*<       return >*/
    return 0;
/* SOURCE genscn.for:1733 */
/*<   991 continue >*/
L991:
/* SOURCE genscn.for:1734 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__197.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__197);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE genscn.for:1735 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__198.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__198);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)196);
    e_wsle();
/* SOURCE genscn.for:1736 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE genscn.for:1737 */
/*<       end >*/
    return 0;
} /* genscn_input_new__ */

#ifdef __cplusplus
	}
#endif
