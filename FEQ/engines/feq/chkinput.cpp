/* chkinput.f -- translated by f2c (version 20240504).
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

/* COMMON tamcom_ is declared in common.hpp. */

#define tamcom_1 tamcom_

/* COMMON enelem_ is declared in common.hpp. */

#define enelem_1 enelem_

/* COMMON bnelem_ is declared in common.hpp. */

#define bnelem_1 bnelem_

/* COMMON enrslt_ is declared in common.hpp. */

#define enrslt_1 enrslt_

/* COMMON bnothr_ is declared in common.hpp. */

#define bnothr_1 bnothr_

/* COMMON bnothc_ is declared in common.hpp. */

#define bnothc_1 bnothc_

/* COMMON gravcm_ is declared in common.hpp. */

#define gravcm_1 gravcm_

/* COMMON inbr_ is declared in common.hpp. */

#define inbr_1 inbr_

/* COMMON inen_ is declared in common.hpp. */

#define inen_1 inen_

/* COMMON inenc_ is declared in common.hpp. */

#define inenc_1 inenc_

/* COMMON spouta_ is declared in common.hpp. */

#define spouta_1 spouta_

/* COMMON spoutc_ is declared in common.hpp. */

#define spoutc_1 spoutc_

/* COMMON xscom_ is declared in common.hpp. */

#define xscom_1 xscom_

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_31 = 31;
static integer feq_gen_c_d_7 = 7;
static integer feq_gen_c_d_10002 = 10002;
static integer feq_gen_c_d_2 = 2;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_3 = 3;
static integer feq_gen_c_d_8 = 8;
static integer feq_gen_c_d_6 = 6;
static integer feq_gen_c_d_20 = 20;
static real c_b174 = (float)0.;
static integer feq_gen_c_d_0 = 0;
static integer feq_gen_c_d_21 = 21;
static integer feq_gen_c_d_13 = 13;
static integer feq_gen_c_d_10 = 10;
static integer feq_gen_c_d_15 = 15;
static integer feq_gen_c_d_22 = 22;
static integer feq_gen_c_d_11 = 11;

/* Routines used in checking the user input */
/*     *********** */
/*     *         * */
/*     * PROCESS_SIMPLE_BLK_NUMBER */
/*     *         * */
/*     *********** */
/* SOURCE chkinput.for:10 */
/*<        >*/
/* Subroutine */ int feq_gen_process_simple_blk_number_d_(integer *stdout, integer *
	feq_storage_opblk, integer *feq_gen_blk_number_d_, integer *feq_gen_emc_adrs_d_, integer *
	feq_gen_emc_adrs_of_blk_number_d_, integer *feq_gen_active_flag_d_, integer *
	feq_gen_emc_dir_adrs_d_, integer *feq_gen_emc_dir_d_, integer *ept, integer *feq_storage_emc, 
	integer *eflag)
{
    /* Format strings */
    static char fmt_54[] = "(/,\002 *ERR:320* Operation Block#=\002,i5,\002 \
is referenced\002,\002 more than once\002,/,11x,\002or is missing.\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_blk_adrs_d_;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__5 = { 0, 0, 0, fmt_54, 0 };


/*     Set value for a simple operation block number. */
/* SOURCE chkinput.for:19 */
/*<       implicitnone >*/
/* INCLUDE chkinput.for:20 */
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
/* SOURCE chkinput.for:22 */
/*<        >*/
/* INCLUDE chkinput.for:27 */
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
/* SOURCE chkinput.for:31 */
/*<       integerblk_adrs >*/
/*     ************************Formats*********************************** */
/* SOURCE chkinput.for:34 */
/*<    54  >*/
/* *********************************************************************** */
/*      WRITE(STDOUT,*) ' PROCESS_S...:BLK NUMBER=',BLK_NUMBER */
/*     Get the address of  block in FTAB/ITAB */
/* SOURCE chkinput.for:39 */
/*<       blk_adrs=opblk(blk_number) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> opblk(feq_storage_opblk, 1);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* L54: */
    feq_gen_blk_adrs_d_ = opblk[*feq_gen_blk_number_d_];
/*      WRITE(STDOUT,*) ' BLK_ADRS=',BLK_ADRS */
/*     Set the pointer to the structure opening slot in EMC in the */
/*     Operation Control Block structure. */
/* SOURCE chkinput.for:45 */
/*<       itab(blk_adrs)=emc_adrs >*/
    itab[feq_gen_blk_adrs_d_] = *feq_gen_emc_adrs_d_;
/*     Establish the initial value of the structure setting in EMC */
/* SOURCE chkinput.for:49 */
/*<       emc(emc_adrs)=itab(blk_adrs+1) >*/
    emc[*feq_gen_emc_adrs_d_] = itab[feq_gen_blk_adrs_d_ + 1];
/*     Set the active flag  to indicate that the block is */
/*     active and is the only block used by the structure. The  active */
/*     flag is set to -2 when the operation block data is input.  If */
/*     the active flag is found to be different than -2, then */
/*     the user has requested that the same block be used for two */
/*     different structures.  This is an error. */
/*      WRITE(STDOUT,*) ' ITAB(BLK_ADRS+7)=',ITAB(BLK_ADRS+7) */
/* SOURCE chkinput.for:58 */
/*<       if(itab(blk_adrs+7).ne.-2.and.active_flag.eq.0)then >*/
    if (itab[feq_gen_blk_adrs_d_ + 7] != -2 && *feq_gen_active_flag_d_ == 0) {
/* SOURCE chkinput.for:59 */
/*<       write(stdout,54)blk_number >*/
	feq_gen_io_d__5.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__5);
	do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_blk_number_d_), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE chkinput.for:60 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chkinput.for:61 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE chkinput.for:62 */
/*<       else >*/
    } else {
/*       Ok here. If this is a multiple block for a control structure */
/*       it will be set many times as the operation block selection */
/*       table is scanned. */
/* SOURCE chkinput.for:66 */
/*<       itab(blk_adrs+7)=active_flag >*/
	itab[feq_gen_blk_adrs_d_ + 7] = *feq_gen_active_flag_d_;
/* SOURCE chkinput.for:67 */
/*<       endif >*/
    }
/*     Set the pointer to the block number location in EMC. */
/*     Used only for multiple block numbers per structure. */
/* SOURCE chkinput.for:70 */
/*<       itab(blk_adrs+8)=emc_adrs_of_blk_number >*/
    itab[feq_gen_blk_adrs_d_ + 8] = *feq_gen_emc_adrs_of_blk_number_d_;
/*     Set the values for 2-way pumps.  Set in all cases but */
/*     only used for 2-way pumps. */
/* SOURCE chkinput.for:74 */
/*<       itab(blk_adrs+9)=emc_dir >*/
    itab[feq_gen_blk_adrs_d_ + 9] = *feq_gen_emc_dir_d_;
/* SOURCE chkinput.for:75 */
/*<       itab(blk_adrs+10)=emc_dir_adrs >*/
    itab[feq_gen_blk_adrs_d_ + 10] = *feq_gen_emc_dir_adrs_d_;
/*      WRITE(STDOUT,*) ' LEAVING PROCESS_SIMPLE_BLK_NUMBER' */
/* SOURCE chkinput.for:77 */
/*<       return >*/
    return 0;
/* SOURCE chkinput.for:78 */
/*<       end >*/
} /* process_simple_blk_number__ */

#undef rtmp
#undef itab
#undef ftab


/*     *********** */
/*     *         * */
/*     * PROCESS_OPER_BLK */
/*     *         * */
/*     *********** */
/* SOURCE chkinput.for:86 */
/*<        >*/
/* Subroutine */ int feq_gen_process_oper_blk_d_(integer *stdout, integer *feq_gen_emc_base_d_, 
	integer *feq_gen_emc_offset_d_, integer *feq_gen_emc_offset_of_blk_number_d_, integer *
	feq_gen_blk_number_d_, integer *feq_storage_opblk, integer *feq_gen_number_of_blocks_d_, integer *
	ept, integer *feq_storage_emc, integer *eflag)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:321* Operation Block Table Id=\002,\
a,\002 is invalid.\002)";
    static char fmt_52[] = "(/,\002 *ERR:322* Expected table of type 7 but f\
ound\002,\002 type \002,i5)";
    static char fmt_56[] = "(/,\002 *ERR:323* Operation Block#=\002,i5,\002 \
from Table Id=\002,a,\002 is out of range.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_stop(char *
	    , ftnlen);

    /* Local variables */
    integer feq_gen_emc_adrs_d_, feq_gen_body_inc_d_, feq_gen_low_adrs_d_, feq_gen_i_d_;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer feq_gen_high_adrs_d_, feq_gen_table_adrs_d_;
    extern /* Subroutine */ int feq_gen_process_simple_blk_number_d_(integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), kil_(integer *, 
	    integer *, integer *);
    integer feq_gen_active_flag_d_;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer feq_gen_emc_dir_adrs_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    integer feq_gen_ts_blk_number_d_;
    extern /* Subroutine */ int chktab_(integer *, integer *, integer *, 
	    integer *, integer *, integer *);
    extern integer gettyp_(integer *);
    integer feq_gen_emc_adrs_of_blk_number_d_, feq_gen_emc_dir_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__15 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__16 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__22 = { 0, 0, 0, fmt_56, 0 };


/*     Process the operation block references */
/* SOURCE chkinput.for:94 */
/*<       implicitnone >*/
/* INCLUDE chkinput.for:95 */
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
/* SOURCE chkinput.for:97 */
/*<        >*/
/* INCLUDE chkinput.for:102 */
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
/* SOURCE chkinput.for:106 */
/*<        >*/
/*     External subprograms. */
/* SOURCE chkinput.for:111 */
/*<       integergettyp >*/
/* SOURCE chkinput.for:112 */
/*<       character*16get_tabid >*/
/* SOURCE chkinput.for:113 */
/*<       externalgettyp,get_tabid >*/
/*     ************************Formats*********************************** */
/* SOURCE chkinput.for:115 */
/*<    50 format(/,' *ERR:321* Operation Block Table Id=',a,' is invalid.') >*/
/* SOURCE chkinput.for:116 */
/*<    52  >*/
/* SOURCE chkinput.for:118 */
/*<    56  >*/
/* *********************************************************************** */
/* SOURCE chkinput.for:122 */
/*<       emc_adrs=emc_base+emc_offset >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> opblk(feq_storage_opblk, 1);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* L50: */
/* L52: */
/* L56: */
    feq_gen_emc_adrs_d_ = *feq_gen_emc_base_d_ + *feq_gen_emc_offset_d_;
/*      WRITE(STDOUT,*) ' EMC_ADRS=',EMC_ADRS */
/* SOURCE chkinput.for:125 */
/*<       emc_adrs_of_blk_number=emc_base+emc_offset_of_blk_number >*/
    feq_gen_emc_adrs_of_blk_number_d_ = *feq_gen_emc_base_d_ + *feq_gen_emc_offset_of_blk_number_d_;
/*     Followiing values only used if this is a 2-way pump.  However, */
/*     the value can be computed in other cases. */
/* SOURCE chkinput.for:128 */
/*<       emc_dir_adrs=emc_base+6 >*/
    feq_gen_emc_dir_adrs_d_ = *feq_gen_emc_base_d_ + 6;
/* SOURCE chkinput.for:129 */
/*<       emc_dir=emc(emc_dir_adrs) >*/
    feq_gen_emc_dir_d_ = emc[feq_gen_emc_dir_adrs_d_];
/*     See subroutine SET_CONTROL_SOURCE for the setting of the */
/*     BLK_NUMBER to understand the code here.  Special settings */
/*     are used to detect various conditions. */
/* SOURCE chkinput.for:135 */
/*<       if(blk_number.lt.mftnum+1)then >*/
    if (*feq_gen_blk_number_d_ < 10003) {
/*       In this instance the operation block is the only one used */
/*       by a structure.  In this case the ACTIVE_FLAG value is 0 */
/* SOURCE chkinput.for:138 */
/*<       if(blk_number.ge.1.and.blk_number.le.number_of_blocks)then >*/
	if (*feq_gen_blk_number_d_ >= 1 && *feq_gen_blk_number_d_ <= *feq_gen_number_of_blocks_d_) {
/* SOURCE chkinput.for:139 */
/*<       active_flag=0 >*/
	    feq_gen_active_flag_d_ = 0;
/* SOURCE chkinput.for:140 */
/*<        >*/
	    feq_gen_process_simple_blk_number_d_(stdout, &opblk[1], feq_gen_blk_number_d_, &
		    feq_gen_emc_adrs_d_, &feq_gen_emc_adrs_of_blk_number_d_, &feq_gen_active_flag_d_, &
		    feq_gen_emc_dir_adrs_d_, &feq_gen_emc_dir_d_, ept, &emc[1], eflag);
/* SOURCE chkinput.for:144 */
/*<       else >*/
	} else {
/*         Block numbers are out of proper range in the Network Matrix */
/*         input.  They must be consecutive starting at 1. */
/* SOURCE chkinput.for:147 */
/*<       callkil(31,blk_number,eflag) >*/
	    kil_(&feq_gen_c_d_31, feq_gen_blk_number_d_, eflag);
/* SOURCE chkinput.for:150 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:151 */
/*<       else >*/
    } else {
/*       If the value given is greater than MFTNUM+1 , we assume that it is */
/*       a time series table of type 7.  Thus we must verify that the */
/*       table exists and that it is a time-series table..  Once these tests */
/*       are passed, then we scan the body of the time-series table */
/*       and process all operation control blocks that are given. */
/*       Compute the actual number. */
/* SOURCE chkinput.for:158 */
/*<       table_adrs=blk_number-mftnum-1 >*/
	feq_gen_table_adrs_d_ = *feq_gen_blk_number_d_ - 10003;
/* SOURCE chkinput.for:159 */
/*<       callchktab(7,stdout,ftpnt,mftnum,table_adrs,eflag) >*/
	chktab_(&feq_gen_c_d_7, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &feq_gen_table_adrs_d_, 
		eflag);
/* SOURCE chkinput.for:163 */
/*<       if(eflag.eq.0)then >*/
	if (*eflag == 0) {
/* SOURCE chkinput.for:164 */
/*<       if(gettyp(table_adrs).ne.7)then >*/
	    if (gettyp_(&feq_gen_table_adrs_d_) != 7) {
/* SOURCE chkinput.for:165 */
/*<       write(stdout,52)gettyp(table_adrs) >*/
		feq_gen_io_d__15.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__15);
		feq_gen_i_d_1 = gettyp_(&feq_gen_table_adrs_d_);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE chkinput.for:166 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE chkinput.for:167 */
/*<       endif >*/
	    }
/* SOURCE chkinput.for:168 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:169 */
/*<       if(eflag.ne.0)then >*/
	if (*eflag != 0) {
/* SOURCE chkinput.for:170 */
/*<       write(stdout,50)get_tabid(blk_number-mftnum-1) >*/
	    feq_gen_io_d__16.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__16);
	    feq_gen_i_d_1 = *feq_gen_blk_number_d_ - 10003;
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    e_wsfe();
/* SOURCE chkinput.for:171 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE chkinput.for:172 */
/*<       endif >*/
	}
/*       At this point the table exists and is of type 7.  Set the */
/*       address points for the table. */
/* SOURCE chkinput.for:176 */
/*<       low_adrs=(table_adrs+off234)/2 >*/
	feq_gen_low_adrs_d_ = (feq_gen_table_adrs_d_ + 22) / 2;
/* SOURCE chkinput.for:177 */
/*<       high_adrs=itab(table_adrs) >*/
	feq_gen_high_adrs_d_ = itab[feq_gen_table_adrs_d_];
/* SOURCE chkinput.for:178 */
/*<       body_inc=2 >*/
	feq_gen_body_inc_d_ = 2;
/* SOURCE chkinput.for:180 */
/*<       do500i=low_adrs,high_adrs,body_inc >*/
	feq_gen_i_d_1 = feq_gen_high_adrs_d_;
	feq_gen_i_d_2 = feq_gen_body_inc_d_;
	for (feq_gen_i_d_ = feq_gen_low_adrs_d_; feq_gen_i_d_2 < 0 ? feq_gen_i_d_ >= feq_gen_i_d_1 : feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += 
		feq_gen_i_d_2) {
/*         Round the table value to the nearest integer and treat */
/*         it like a block number.  It must be in valid block number */
/*         range. */
/* SOURCE chkinput.for:184 */
/*<       ts_blk_number=int(dtab(i+1)+0.5) >*/
	    feq_gen_ts_blk_number_d_ = (integer) (ftable_1.dtab[feq_gen_i_d_ + 1] + (float).5);
/* SOURCE chkinput.for:185 */
/*<       if(ts_blk_number.lt.1.or.ts_blk_number.gt.mnblk)then >*/
	    if (feq_gen_ts_blk_number_d_ < 1 || feq_gen_ts_blk_number_d_ > 100) {
/* SOURCE chkinput.for:186 */
/*<       write(stdout,56)ts_blk_number,get_tabid(blk_number-mftnum-1) >*/
		feq_gen_io_d__22.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__22);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_ts_blk_number_d_, (ftnlen)sizeof(
			integer));
		feq_gen_i_d_3 = *feq_gen_blk_number_d_ - 10003;
		feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &feq_gen_i_d_3);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
		e_wsfe();
/* SOURCE chkinput.for:188 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE chkinput.for:189 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE chkinput.for:190 */
/*<       else >*/
	    } else {
/*           Block reference is in valid range. */
/*           In this instance the active flag is set to the address */
/*           of the time-series table containing the various blocks */
/*           to be used in the operation of the structure. */
/* SOURCE chkinput.for:195 */
/*<       active_flag=table_adrs >*/
		feq_gen_active_flag_d_ = feq_gen_table_adrs_d_;
/* SOURCE chkinput.for:196 */
/*<        >*/
		feq_gen_process_simple_blk_number_d_(stdout, &opblk[1], &
			feq_gen_ts_blk_number_d_, &feq_gen_emc_adrs_d_, &
			feq_gen_emc_adrs_of_blk_number_d_, &feq_gen_active_flag_d_, &
			feq_gen_emc_dir_adrs_d_, &feq_gen_emc_dir_d_, ept, &emc[1], eflag);
/* SOURCE chkinput.for:200 */
/*<       endif >*/
	    }
/* SOURCE chkinput.for:202 */
/*<   500 continue >*/
/* L500: */
	}
/* SOURCE chkinput.for:203 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:204 */
/*<       return >*/
    return 0;
/* SOURCE chkinput.for:205 */
/*<       end >*/
} /* process_oper_blk__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE chkinput.for:210 */
/*<        >*/
/* Subroutine */ int chkbr_(integer *stdout, integer *nbn, integer *nbra, 
	integer *nex, integer *mft, integer *feq_storage_brpt, integer *feq_storage_ftpnt, integer *
	feq_storage_geqvec, real *grav, real *sfac, real *feq_storage_xvec, integer *feq_storage_nsec, integer *
	feq_storage_hltab, integer *eflag, integer *feq_storage_exnodt)
{
    /* Initialized data */

    static integer geqtab[4] = { 20,20,23,23 };

    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:192* One or more cross section func\
tion tables\002,\002 for branch\002,i4,/,11x,\002 do not support the GEQ opt\
ion\002,\002 for this branch.\002)";
    static char fmt_52[] = "(/,\002*ERR:409* Stations match in branch numb\
er:\002,i5,\002 near station=\002,f10.4)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3;
    real feq_gen_r_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer feq_gen_i_d_, j, it, ftp, last, first, eflag1;
    extern /* Subroutine */ int chktab_(integer *, integer *, integer *, 
	    integer *, integer *, integer *);
    extern integer getusb_(integer *);
    real station;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__31 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__33 = { 0, 0, 0, fmt_52, 0 };


/*     + + + PURPOSE + + + */
/*     Check table numbers for the branch nodes. */
/* SOURCE chkinput.for:219 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE chkinput.for:221 */
/*<       integereflag,stdout,mft,nbn,nbra,nex >*/
/* SOURCE chkinput.for:222 */
/*<        >*/
/* SOURCE chkinput.for:224 */
/*<       realgrav,sfac,xvec(nbn) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     NBN    - total number on nodes on branches in the model */
/*     NBRA   - number of branches in the model */
/*     NEX    - number of exterior nodes in the model */
/*     MFT    - maximum function table pointer value.  Same as maximum */
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
/*     FTPNT  - function table pointer giving the table address for each */
/*              table number.  If the address is zero the table does not */
/*              exist. */
/*     GEQVEC - code for the governing equation option for each branch */
/*     SFAC   - stationing factor.  Used to scale check for essentially equal */
/*              stations on a branch */
/*     GRAV   - gravitational acceleration. */
/*     XVEC   - values of stations along branches.  Already in the internal */
/*              scale of feet or meters. */
/*     NSEC   - number and also address of cross section table at a node */
/*               on a branch */
/*     HLTAB  - addresses of point loss tables.  0 if none present */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
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
/*     + + + SAVED VALUES + + + */
/* SOURCE chkinput.for:271 */
/*<       integergeqtab(4) >*/
/* SOURCE chkinput.for:272 */
/*<       savegeqtab >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE chkinput.for:275 */
/*<       integereflag1,first,ftp,i,it,j,last >*/
/* SOURCE chkinput.for:276 */
/*<       realstation >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE chkinput.for:279 */
/*<       integergetusb >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE chkinput.for:282 */
/*<       externalchktab,getusb >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE chkinput.for:285 */
/*<       datageqtab/20,20,23,23/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> hltab(feq_storage_hltab, 1);

    feq::IndexedPointer<integer> nsec(feq_storage_nsec, 1);

    feq::IndexedPointer<real> xvec(feq_storage_xvec, 1);

    feq::IndexedPointer<integer> geqvec(feq_storage_geqvec, 1);

    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> ftpnt(feq_storage_ftpnt, 1);

    /* Function Body */
/* SOURCE chkinput.for:288 */
/*<    50  >*/
/* L50: */
/* SOURCE chkinput.for:291 */
/*<    52  >*/
/* L52: */
/* *********************************************************************** */
/* SOURCE chkinput.for:295 */
/*<       do5000i=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*       GET LIMITS FOR THIS BRANCH */
/* SOURCE chkinput.for:299 */
/*<       first=brpt(3,i) >*/
	first = brpt[(feq_gen_i_d_ << 3) + 3];
/* SOURCE chkinput.for:300 */
/*<       last=brpt(4,i) >*/
	last = brpt[(feq_gen_i_d_ << 3) + 4];
/* SOURCE chkinput.for:302 */
/*<       eflag1=0 >*/
	eflag1 = 0;
/* SOURCE chkinput.for:303 */
/*<       do4000j=first,last >*/
	feq_gen_i_d_2 = last;
	for (j = first; j <= feq_gen_i_d_2; ++j) {
/*         GET THE TABLE NUMBER FOR THE CROSS SECTION PROPERTIES */
/* SOURCE chkinput.for:307 */
/*<       it=nsec(j) >*/
	    it = nsec[j];
/*         CHECK FOR INTERPOLATED TABLE REQUEST */
/* SOURCE chkinput.for:309 */
/*<       if(it.gt.0)then >*/
	    if (it > 0) {
/*           REAL TABLE */
/* SOURCE chkinput.for:311 */
/*<       ftp=it >*/
		ftp = it;
/* SOURCE chkinput.for:312 */
/*<       callchktab(geqtab(geqvec(i)),stdout,ftpnt,mft,ftp,eflag1) >*/
		chktab_(&geqtab[geqvec[feq_gen_i_d_] - 1], stdout, &ftpnt[1], mft, &
			ftp, &eflag1);
/*           STORE THE TABLE ADDRESS */
/* SOURCE chkinput.for:319 */
/*<       nsec(j)=ftp >*/
		nsec[j] = ftp;
/* SOURCE chkinput.for:320 */
/*<       endif >*/
	    }
/*         CHECK POINT LOSS TABLE NUMBERS */
/* SOURCE chkinput.for:323 */
/*<       it=hltab(j) >*/
	    it = hltab[j];
/* SOURCE chkinput.for:324 */
/*<       if(it.gt.0)then >*/
	    if (it > 0) {
/*           TABLE REFERENCED */
/* SOURCE chkinput.for:326 */
/*<       ftp=it >*/
		ftp = it;
/* SOURCE chkinput.for:327 */
/*<       callchktab(2,stdout,ftpnt,mft,ftp,eflag) >*/
		chktab_(&feq_gen_c_d_2, stdout, &ftpnt[1], mft, &ftp, eflag);
/* SOURCE chkinput.for:331 */
/*<       hltab(j)=ftp >*/
		hltab[j] = ftp;
/* SOURCE chkinput.for:332 */
/*<       endif >*/
	    }
/* SOURCE chkinput.for:333 */
/*<  4000 continue >*/
/* L4000: */
	}
/* SOURCE chkinput.for:334 */
/*<       if(eflag1.gt.0)then >*/
	if (eflag1 > 0) {
/* SOURCE chkinput.for:335 */
/*<       write(stdout,50)getusb(i) >*/
	    feq_gen_io_d__31.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__31);
	    feq_gen_i_d_2 = getusb_(&feq_gen_i_d_);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_2, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE chkinput.for:336 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE chkinput.for:337 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:339 */
/*<       exnodt(4,brpt(5,i))=nsec(first) >*/
	exnodt[brpt[(feq_gen_i_d_ << 3) + 5] * 9 + 4] = nsec[first];
/* SOURCE chkinput.for:340 */
/*<       exnodt(4,brpt(6,i))=nsec(last) >*/
	exnodt[brpt[(feq_gen_i_d_ << 3) + 6] * 9 + 4] = nsec[last];
/* SOURCE chkinput.for:342 */
/*<       eflag1=0 >*/
	eflag1 = 0;
/*       Check for a computational element that has */
/*       essentially zero length. */
/* SOURCE chkinput.for:345 */
/*<       station=xvec(first) >*/
	station = xvec[first];
/* SOURCE chkinput.for:346 */
/*<       do4500j=first+1,last >*/
	feq_gen_i_d_2 = last;
	for (j = first + 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE chkinput.for:347 */
/*<       if(grav.gt.15.0)then >*/
	    if (*grav > (float)15.) {
/*           We have Customary US units. */
/* SOURCE chkinput.for:349 */
/*<       if(abs(station-xvec(j)).le.0.1)then >*/
		if ((feq_gen_r_d_1 = static_cast<double>(station) - xvec[j], dabs(feq_gen_r_d_1)) <= (float).1) {
/* SOURCE chkinput.for:350 */
/*<       eflag1=1 >*/
		    eflag1 = 1;
/* SOURCE chkinput.for:351 */
/*<       endif >*/
		}
/* SOURCE chkinput.for:352 */
/*<       else >*/
	    } else {
/*           We have metric */
/* SOURCE chkinput.for:354 */
/*<       if(abs(station-xvec(j)).le.0.1/3.28)then >*/
		if ((feq_gen_r_d_1 = static_cast<double>(station) - xvec[j], dabs(feq_gen_r_d_1)) <= (float)
			.030487804878048783) {
/* SOURCE chkinput.for:355 */
/*<       eflag1=1 >*/
		    eflag1 = 1;
/* SOURCE chkinput.for:356 */
/*<       endif >*/
		}
/* SOURCE chkinput.for:357 */
/*<       endif >*/
	    }
/* SOURCE chkinput.for:358 */
/*<       if(eflag1.gt.0)then >*/
	    if (eflag1 > 0) {
/* SOURCE chkinput.for:359 */
/*<       write(stdout,52)getusb(i),xvec(j)/sfac >*/
		feq_gen_io_d__33.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__33);
		feq_gen_i_d_3 = getusb_(&feq_gen_i_d_);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_3, (ftnlen)sizeof(integer));
		feq_gen_r_d_1 = static_cast<double>(xvec[j]) / *sfac;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE chkinput.for:360 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE chkinput.for:361 */
/*<       eflag1=0 >*/
		eflag1 = 0;
/* SOURCE chkinput.for:362 */
/*<       endif >*/
	    }
/* SOURCE chkinput.for:363 */
/*<  4500 continue >*/
/* L4500: */
	}
/* SOURCE chkinput.for:364 */
/*<  5000 continue >*/
/* L5000: */
    }
/* SOURCE chkinput.for:366 */
/*<       return >*/
    return 0;
/* SOURCE chkinput.for:367 */
/*<       end >*/
} /* chkbr_ */




/* SOURCE chkinput.for:371 */
/*<       subroutinechkdat(stdout,yr,mn,dy,eflag) >*/
/* Subroutine */ int chkdat_(integer *stdout, integer *yr, integer *mn, 
	integer *dy, integer *eflag)
{
    /* Initialized data */

    static integer dpm[24]	/* was [12][2] */ = { 31,28,31,30,31,30,31,31,
	    30,31,30,31,31,29,31,30,31,30,31,31,30,31,30,31 };

    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:243* Month=\002,i3,\002 is invalid\
.\002)";
    static char fmt_52[] = "(/,\002 *ERR:244* Day=\002,i3,\002 is invalid fo\
r month=\002,i3)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer leap;
    extern integer lpyear_(integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__36 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__37 = { 0, 0, 0, fmt_52, 0 };


/*     + + + PURPOSE + + + */
/*     Check a Gregorian calender date for validity. */
/* SOURCE chkinput.for:379 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE chkinput.for:381 */
/*<       integerdy,eflag,mn,stdout,yr >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - standard output unit for user messages */
/*     YR     - calendar year */
/*     MN     - number of month(1-12) */
/*     DY     - day in the month */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     + + + SAVED VALUES + + + */
/* SOURCE chkinput.for:391 */
/*<       integerdpm(12,2) >*/
/* SOURCE chkinput.for:392 */
/*<       savedpm >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE chkinput.for:395 */
/*<       integerleap >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE chkinput.for:398 */
/*<       integerlpyear >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE chkinput.for:401 */
/*<       externallpyear >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE chkinput.for:404 */
/*<        >*/
/* SOURCE chkinput.for:408 */
/*<    50 format(/,' *ERR:243* Month=',i3,' is invalid.') >*/
/* L50: */
/* SOURCE chkinput.for:409 */
/*<    52 format(/,' *ERR:244* Day=',i3,' is invalid for month=',i3) >*/
/* L52: */
/* *********************************************************************** */
/* SOURCE chkinput.for:411 */
/*<       leap=lpyear(yr) >*/
    leap = lpyear_(yr);
/* SOURCE chkinput.for:412 */
/*<       if(mn.gt.12.or.mn.lt.1)then >*/
    if (*mn > 12 || *mn < 1) {
/* SOURCE chkinput.for:413 */
/*<       write(stdout,50)mn >*/
	feq_gen_io_d__36.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__36);
	do_fio(&feq_gen_c_d_1, (char *)&(*mn), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE chkinput.for:414 */
/*<       mn=1 >*/
	*mn = 1;
/* SOURCE chkinput.for:415 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chkinput.for:416 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:417 */
/*<       if(dy.lt.1.or.dy.gt.dpm(mn,leap))then >*/
    if (*dy < 1 || *dy > dpm[*mn + leap * 12 - 13]) {
/* SOURCE chkinput.for:418 */
/*<       write(stdout,52)dy,mn >*/
	feq_gen_io_d__37.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__37);
	do_fio(&feq_gen_c_d_1, (char *)&(*dy), (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&(*mn), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE chkinput.for:419 */
/*<       dy=dpm(mn,leap) >*/
	*dy = dpm[*mn + leap * 12 - 13];
/* SOURCE chkinput.for:420 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chkinput.for:421 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:422 */
/*<       return >*/
    return 0;
/* SOURCE chkinput.for:423 */
/*<       end >*/
} /* chkdat_ */




/* SOURCE chkinput.for:428 */
/*<       subroutinechk_bn_with_trib_area(stdout,flow_address_in_emc,node) >*/
/* Subroutine */ int feq_gen_chk_bn_with_trib_area_d_(integer *stdout, integer *
	feq_gen_flow_address_in_emc_d_, integer *node)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *BUG:XXX CHK_BN_WITH_TRIB_AREA found eit\
her no trib\002,\002 area units or more\002,/,11x,\002 than two trib area un\
its\002,\002 attached to the BN.\002)";
    static char fmt_52[] = "(/,\002 *ERR:325* Boundary node=\002,a5,\002 has\
 neither\002,\002 detention nor delay.\002)";

    /* System generated locals */
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5];

    /* Builtin functions */
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_cat_code_d_, feq_gen_unit_pnt_d_, found;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);
    integer feq_gen_ta_node_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__42 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__43 = { 0, 0, 0, fmt_50, 0 };


/*     Find the tributary are units attached to the boundary node */
/*     given in NODE and set the pointer to the storage location in */
/*     EMC that contains the flow at the boundary. */
/* SOURCE chkinput.for:435 */
/*<       implicitnone >*/
/* SOURCE chkinput.for:436 */
/*<       integerstdout,flow_address_in_emc,node >*/
/* INCLUDE chkinput.for:438 */
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
/* INCLUDE chkinput.for:439 */
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
/*     Local */
/* SOURCE chkinput.for:443 */
/*<       integerunit_pnt,cat_code,ta_node,found >*/
/*     Called program units */
/* SOURCE chkinput.for:447 */
/*<       character*5getusn >*/
/* SOURCE chkinput.for:449 */
/*<       externalgetusn >*/
/*     ****************************Formats******************************* */
/* SOURCE chkinput.for:451 */
/*<    50  >*/
/* SOURCE chkinput.for:454 */
/*<    52  >*/
/* *********************************************************************** */
/* SOURCE chkinput.for:457 */
/*<       unit_pnt=1 >*/
/* L50: */
/* L52: */
    feq_gen_unit_pnt_d_ = 1;
/* SOURCE chkinput.for:458 */
/*<       found=0 >*/
    found = 0;
/*     Scan the linked list until the end.  Update all tributary area */
/*     units with category code of an LPR (2) that match NODE to be */
/*     category code BN (3) and set the flow storage address. */
/* SOURCE chkinput.for:464 */
/*<   100 continue >*/
L100:
/* SOURCE chkinput.for:465 */
/*<       ta_node=tam_itab(unit_pnt) >*/
    feq_gen_ta_node_d_ = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ - 1];
/* SOURCE chkinput.for:466 */
/*<       cat_code=tam_itab(unit_pnt+1) >*/
    feq_gen_cat_code_d_ = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_];
/* SOURCE chkinput.for:467 */
/*<       if(cat_code.eq.2)then >*/
    if (feq_gen_cat_code_d_ == 2) {
/*         Subroutine TRIBIN assigned trib area to a reservoir */
/* SOURCE chkinput.for:469 */
/*<       if(ta_node.eq.node)then >*/
	if (feq_gen_ta_node_d_ == *node) {
/*           We have a match.  Reset the cat code to be boundary node. */
/* SOURCE chkinput.for:471 */
/*<       tam_itab(unit_pnt+1)=3 >*/
	    tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_] = 3;
/*           Set the pointer to the flow storage location. */
/* SOURCE chkinput.for:473 */
/*<       tam_itab(unit_pnt+8)=flow_address_in_emc >*/
	    tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 7] = *feq_gen_flow_address_in_emc_d_;
/*           Make sure that there is delay or detention present. */
/* SOURCE chkinput.for:475 */
/*<       if(tam_itab(unit_pnt+5).eq.0.and.tam_itab(unit_pnt+6).eq.0)then >*/
	    if (tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 4] == 0 && 
		    tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 5] == 0) {
/*             Must have either one or both. */
/* SOURCE chkinput.for:478 */
/*<       write(stdout,52)getusn(node) >*/
		feq_gen_io_d__42.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__42);
		getusn_(feq_gen_ch_d_2, (ftnlen)5, node);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		e_wsfe();
/* SOURCE chkinput.for:479 */
/*<       stop'Abnormal stop.  Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE chkinput.for:480 */
/*<       endif >*/
	    }
/* SOURCE chkinput.for:481 */
/*<       found=found+1 >*/
	    ++found;
/* SOURCE chkinput.for:482 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:483 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:484 */
/*<       unit_pnt=tam_itab(unit_pnt+2) >*/
    feq_gen_unit_pnt_d_ = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 1];
/* SOURCE chkinput.for:485 */
/*<       if(unit_pnt.gt.0)goto100 >*/
    if (feq_gen_unit_pnt_d_ > 0) {
	goto L100;
    }
/* SOURCE chkinput.for:486 */
/*<       if(found.eq.0.or.found.gt.3)then >*/
    if (found == 0 || found > 3) {
/* SOURCE chkinput.for:487 */
/*<       write(stdout,50)found >*/
	feq_gen_io_d__43.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__43);
	do_fio(&feq_gen_c_d_1, (char *)&found, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE chkinput.for:488 */
/*<       stop'Abnormal stop. Bugs found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Bugs found."), (ftnlen)26);
/* SOURCE chkinput.for:489 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:490 */
/*<       return >*/
    return 0;
/* SOURCE chkinput.for:491 */
/*<       end >*/
} /* chk_bn_with_trib_area__ */




/* SOURCE chkinput.for:496 */
/*<        >*/
/* Subroutine */ int chkex_(integer *stdout, integer *nex, integer *mft, 
	integer *ept, integer *feq_storage_opblk, integer *nblk, integer *nrwta, integer *
	feq_storage_rtap, integer *eflag, integer *feq_storage_emc, integer *feq_storage_exnodt, integer *ftp, 
	integer *ftknt, integer *feq_storage_rwta)
{
    /* Format strings */
    static char fmt_52[] = "(/,\002 *ERR:112* Critical depth invalid for thi\
s node: \002,a5)";
    static char fmt_55[] = "(/,\002 *ERR:113* Reservoir trib area given for \
node \002,a5,\002 but node is not a reservoir.\002)";
    static char fmt_56[] = "(\0020*BUG:06* EMC ENDS AT ELEMENT:\002,i3,\002 \
BUT SHOULD END AT:\002,i3,\002 IN CHKEX.\002)";
    static char fmt_58[] = "(/,\002 *WRN:12* Bottom elevation difference bet\
ween \002,/,5x,\002node \002,a5,\002 \002,a10,\002 and node \002,a5,\002 \
\002,a10,\002 IS\002,f7.2)";
    static char fmt_60[] = "(/,\002 *ERR:115* Node= \002,a5,\002 not on a br\
anch for code:\002,i5)";
    static char fmt_62[] = "(/,\002 *ERR:116* Cross sections not the same fo\
r code:\002,i5,\002 between nodes \002,a5,\002 and \002,a5)";
    static char fmt_64[] = "(/,\002 *ERR:117* Bottom elevations not the same\
 for code:\002,i5,\002 between nodes \002,a5,\002 and \002,a5)";
    static char fmt_72[] = "(/,\002 *ERR:66* Table type mismatch. Table Ids\
:\002,a,\002 and\002,a,\002 must be type 14.\002)";
    static char fmt_74[] = "(/,\002 *ERR:67* Table type mismatch. Table Ids\
:\002,a,\002 and \002,a,\002 must be type 6, 13, or 43.\002)";
    static char fmt_78[] = "(\002/, *ERR:120* Only one flow path permitted b\
etween node \002,a5,\002 and node \002,a5)";
    static char fmt_80[] = "(\002/, *ERR:171* File access not yet supported \
for\002,\002 controlling level.\002)";
    static char fmt_82[] = "(/,\002 *ERR:233* A cross section function table\
 at abrupt\002,\002 expansion between\002,/,10x,\002 nodes \002,a5,\002 and\
 \002,a5,\002 has wrong type.\002)";
    static char fmt_84[] = "(/,\002 *ERR:234* A cross section function table\
 for Code\002,i3,\002 between\002,/,10x,\002 nodes \002,a5,\002 and \002,a5\
,\002 has\002,\002 wrong type. Types 21, 22, 24,or 25 are OK\002)";
    static char fmt_85[] = "(/,\002 *ERR:254* Upstream node=\002,a5,\002 for\
 Code\002,i3,\002 is\002,\002 not the\002,/,10x,\002downstream node on its b\
ranch.\002)";
    static char fmt_86[] = "(/,\002 *ERR:255* Downstream node=\002,a5,\002 f\
or Code\002,i3,\002 is\002,\002 not the\002,/,10x,\002 upstream node on its \
branch.\002)";
    static char fmt_90[] = "(/,\002 *ERR:235* Outlet loss coef. not 1.0 at z\
ero\002,\002 submergence in Table Id=\002,a)";
    static char fmt_91[] = "(/,\002 *ERR:326* Boundary node=\002,a5,\002 has\
 both tributary area\002,\002 and a non-constant flow source.\002)";
    static char fmt_92[] = "(/\002*ERR:88* Number of links > NEX=\002,i6)";
    static char fmt_94[] = "(/,\002 *ERR/WRN:234* A cross section function t\
able for Code\002,i3,\002 between\002,/,10x,\002 nodes \002,a5,\002 and \002\
,a5,\002 has\002,\002 wrong type.\002,/,10x,\002 Should be Type 22 or 25. Pl\
ease\002,\002 update your model for best performance!\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3;
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[10], feq_gen_ch_d_2[5], feq_gen_ch_d_3[5], feq_gen_ch_d_4[5], feq_gen_ch_d_5[5], feq_gen_ch_d_6[16], feq_gen_ch_d_7[
	    16], feq_gen_ch_d_8[16], feq_gen_ch_d_9[16];
    static real equiv_2[1];

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int feq_gen_process_oper_blk_d_(integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *);
    integer feq_gen_i_d_, j, k;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer n1, n2, it, tab, dir, dnn, upn, feq_gen_flow_address_in_emc_d_, code;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ioff, ntab, node;
    extern /* Subroutine */ int old14_(integer *, integer *, integer *);
    integer adrs;
#define idum (feq::BitView<integer>(equiv_2, sizeof(equiv_2)))
    integer sign, itdu, itud;
#define rdum (equiv_2)
    real temp;
    extern /* Character */ VOID note_(char *, ftnlen, integer *, integer *, 
	    integer *, integer *, integer *);
    integer feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    integer iadrs, nlink, qnode, itype, eflag1;
    real dflow;
    char notea[10], noteb[10];
    extern /* Subroutine */ int ckty15_(integer *, integer *, integer *), 
	    feq_gen_chk_bn_with_trib_area_d_(integer *, integer *, integer *), chktab_(
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     mkqctb_(integer *, integer *, integer *, integer *, integer *);
    extern integer gettbn_(integer *), gettyp_(integer *);
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);
    extern /* Subroutine */ int chktyp_(integer *, integer *, integer *, 
	    integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__53 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__59 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__64 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__66 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__69 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__73 = { 0, 0, 0, fmt_90, 0 };
    static cilist feq_gen_io_d__74 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__78 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__81 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__84 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__85 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__86 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__87 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__91 = { 0, 0, 0, fmt_91, 0 };
    static cilist feq_gen_io_d__92 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__93 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__94 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__95 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__96 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__97 = { 0, 0, 0, fmt_84, 0 };
    static cilist feq_gen_io_d__98 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__99 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__100 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__101 = { 0, 0, 0, fmt_85, 0 };
    static cilist feq_gen_io_d__102 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__103 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__104 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__105 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__106 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__107 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__108 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__109 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__110 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__111 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__112 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__113 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__114 = { 0, 0, 0, fmt_55, 0 };


/*     + + + PURPOSE + + + */
/*     Checks validity of information in the network-matrix control */
/*     vector, EMC. */
/* SOURCE chkinput.for:505 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE chkinput.for:507 */
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
/* SOURCE chkinput.for:510 */
/*<       integereflag,ept,ftknt,ftp,stdout,mft,nblk,nex,nrwta >*/
/* SOURCE chkinput.for:511 */
/*<        >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     NEX    - number of exterior nodes in the model */
/*     MFT    - maximum function table pointer value.  Same as maximum */
/*               function table number */
/*     EPT    - current length of EMC(*) */
/*     OPBLK  - pointer into the function table storage(FTAB/ITAB) for */
/*               each operation block. */
/*     NBLK   - number of operation blocks */
/*     NRWTA  - number of reservoirs with tributary area */
/*     RTAP   - reservoir tributary area pointer */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
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
/*     FTP    - next open location in the function table storage */
/*     RWTA   - reservoirs with tributary area */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE chkinput.for:545 */
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
/* INCLUDE chkinput.for:546 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE chkinput.for:547 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE chkinput.for:548 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE chkinput.for:551 */
/*<        >*/
/* SOURCE chkinput.for:554 */
/*<       realdflow,rdum,temp >*/
/* SOURCE chkinput.for:555 */
/*<       characternotea*10,noteb*10 >*/
/*     + + + EQUIVALENCES + + + */
/* SOURCE chkinput.for:558 */
/*<       equivalence(idum,rdum) >*/
/*     + + + INTRINSICS + + + */
/* SOURCE chkinput.for:561 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE chkinput.for:564 */
/*<       integergettbn,gettyp >*/
/* SOURCE chkinput.for:565 */
/*<       charactergetusn*5,note*10,get_tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE chkinput.for:568 */
/*<        >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE chkinput.for:572 */
/*<    52 format(/,' *ERR:112* Critical depth invalid for this node: ',a5) >*/
/* SOURCE chkinput.for:573 */
/*<    55  >*/
/* SOURCE chkinput.for:575 */
/*<    56  >*/
/* SOURCE chkinput.for:577 */
/*<    58  >*/
/* SOURCE chkinput.for:579 */
/*<    60 format(/,' *ERR:115* Node= ',a5,' not on a branch for code:',i5) >*/
/* SOURCE chkinput.for:580 */
/*<    62  >*/
/* SOURCE chkinput.for:582 */
/*<    64  >*/
/* SOURCE chkinput.for:584 */
/*<    72  >*/
/* SOURCE chkinput.for:586 */
/*<    74  >*/
/* 75   FORMAT('/, *ERR:88* Expected',I5,' operation block references.', */
/*     A '  Only',I5,' found.') */
/* SOURCE chkinput.for:590 */
/*<    78  >*/
/* SOURCE chkinput.for:592 */
/*<    80  >*/
/* SOURCE chkinput.for:594 */
/*<    82  >*/
/* SOURCE chkinput.for:597 */
/*<    84  >*/
/* SOURCE chkinput.for:601 */
/*<    85  >*/
/* SOURCE chkinput.for:603 */
/*<    86  >*/
/* SOURCE chkinput.for:605 */
/*<    90  >*/
/* SOURCE chkinput.for:607 */
/*<    91  >*/
/* SOURCE chkinput.for:610 */
/*<    92 format(/'*ERR:88* Number of links > NEX=',i6) >*/
/* SOURCE chkinput.for:611 */
/*<    94  >*/
/* *********************************************************************** */
/*     Clear the counter for links to other node for Code 5 Type 6. */
/* SOURCE chkinput.for:618 */
/*<       nlink=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    feq::IndexedPointer<integer> opblk(feq_storage_opblk, 1);

    feq::IndexedPointer<integer> rtap(feq_storage_rtap, 1);

    feq::IndexedPointer<integer> rwta(feq_storage_rwta, 1);

    /* Function Body */
/* L52: */
/* L55: */
/* L56: */
/* L58: */
/* L60: */
/* L62: */
/* L64: */
/* L72: */
/* L74: */
/* L78: */
/* L80: */
/* L82: */
/* L84: */
/* L85: */
/* L86: */
/* L90: */
/* L91: */
/* L92: */
/* L94: */
    nlink = 0;
/*     Set the link vector to zero to indicate no link. */
/* SOURCE chkinput.for:620 */
/*<       do100i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE chkinput.for:621 */
/*<       tostore(i)=0 >*/
	enrslt_1.tostore[feq_gen_i_d_ - 1] = 0;
/* SOURCE chkinput.for:622 */
/*<   100 continue >*/
/* L100: */
    }
/*     START THE LOOP OVER THE ELEMENTS */
/* SOURCE chkinput.for:625 */
/*<       j=emc(1) >*/
    j = emc[1];
/* SOURCE chkinput.for:626 */
/*<  1000 continue >*/
L1000:
/* SOURCE chkinput.for:627 */
/*<       code=emc(j) >*/
    code = emc[j];
/* SOURCE chkinput.for:628 */
/*<       if(code.eq.-1)goto2000 >*/
    if (code == -1) {
	goto L2000;
    }
/* SOURCE chkinput.for:629 */
/*<       goto(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15),code >*/
    switch (code) {
	case 1:  goto L1;
	case 2:  goto L2;
	case 3:  goto L3;
	case 4:  goto L4;
	case 5:  goto L5;
	case 6:  goto L6;
	case 7:  goto L7;
	case 8:  goto L8;
	case 9:  goto L9;
	case 10:  goto L10;
	case 11:  goto L11;
	case 12:  goto L12;
	case 13:  goto L13;
	case 14:  goto L14;
	case 15:  goto L15;
    }
/* SOURCE chkinput.for:630 */
/*<       write(stdout,*)' *BUG:08* INVALID EMC CODE IN CHKEX. CODE=',code >*/
    feq_gen_io_d__53.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__53);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:08* INVALID EMC CODE IN CHKEX. CODE="), (
	    ftnlen)42);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE chkinput.for:632 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE chkinput.for:634 */
/*<     1 continue >*/
L1:
/* SOURCE chkinput.for:635 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:636 */
/*<     2 continue >*/
L2:
/*         MAKE SURE THAT ONLY NON-RESERVOIR FREE NODES */
/*         ARE NEGATIVE */
/*          DO 200 I=J+2,J+1+EMC(J+1) */
/*            IF(EMC(I).LT.0.AND.EXNODT(3,ABS(EMC(I))).NE.0) */
/*     A        CALL KIL */
/*     I                 (6, */
/*     M                  EMC(I), EFLAG) */
/* 200      CONTINUE */
/* SOURCE chkinput.for:646 */
/*<       j=j+emc(j+1) >*/
    j += emc[j + 1];
/* SOURCE chkinput.for:647 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:648 */
/*<     3 continue >*/
L3:
/*           If a node on a dummy branch is connected to a node */
/*           on a branch, then force the invert elevation for */
/*           both nodes on the dummy branch to match the invert */
/*           elevation of the node on a branch. */
/* SOURCE chkinput.for:654 */
/*<       n1=emc(j+1) >*/
    n1 = emc[j + 1];
/* SOURCE chkinput.for:655 */
/*<       n2=emc(j+2) >*/
    n2 = emc[j + 2];
/* SOURCE chkinput.for:656 */
/*<       if(exnodt(3,n1).gt.0.and.exnodt(3,n2).eq.0)then >*/
    if (exnodt[n1 * 9 + 3] > 0 && exnodt[n2 * 9 + 3] == 0) {
/*             N1 is on a branch and N2 is on a dummy branch */
/*             or is an inflow node to a LPR */
/* SOURCE chkinput.for:659 */
/*<       if(exnodt(4,n2).gt.0)then >*/
	if (exnodt[n2 * 9 + 4] > 0) {
/*               If a dummy branch, EXNODT(4,N2) has a pointer */
/*               to the other node.  If the inflow node to an LPR, */
/*               it is zero. */
/* SOURCE chkinput.for:663 */
/*<       temp=ze(n2) >*/
	    temp = enelem_1.ze[n2 - 1];
/* SOURCE chkinput.for:664 */
/*<       ze(n2)=zvec(exnodt(2,n1)) >*/
	    enelem_1.ze[n2 - 1] = bnelem_1.zvec[exnodt[n1 * 9 + 2] - 1];
/* SOURCE chkinput.for:665 */
/*<       ye1(n2)=ye1(n2)+temp-ze(n2) >*/
	    enelem_1.ye1[n2 - 1] = static_cast<double>(static_cast<double>(enelem_1.ye1[n2 - 1]) + temp) - enelem_1.ze[
		    n2 - 1];
/* SOURCE chkinput.for:666 */
/*<       temp=ze(exnodt(4,n2)) >*/
	    temp = enelem_1.ze[exnodt[n2 * 9 + 4] - 1];
/* SOURCE chkinput.for:667 */
/*<       ye1(exnodt(4,n2))=ye1(exnodt(4,n2))+temp-ze(n2) >*/
	    enelem_1.ye1[exnodt[n2 * 9 + 4] - 1] = static_cast<double>(static_cast<double>(enelem_1.ye1[exnodt[n2 * 9 
		    + 4] - 1]) + temp) - enelem_1.ze[n2 - 1];
/* SOURCE chkinput.for:668 */
/*<       ze(exnodt(4,n2))=ze(n2) >*/
	    enelem_1.ze[exnodt[n2 * 9 + 4] - 1] = enelem_1.ze[n2 - 1];
/* SOURCE chkinput.for:669 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:670 */
/*<       elseif(exnodt(3,n2).gt.0.and.exnodt(3,n1).eq.0)then >*/
    } else if (exnodt[n2 * 9 + 3] > 0 && exnodt[n1 * 9 + 3] == 0) {
/*             N2 is on a branch and N1 is on a dummy branch or */
/*             is an inflow node to a LPR */
/* SOURCE chkinput.for:673 */
/*<       if(exnodt(4,n1).gt.0)then >*/
	if (exnodt[n1 * 9 + 4] > 0) {
/*               N1 is on a dummy branch */
/* SOURCE chkinput.for:675 */
/*<       temp=ze(n1) >*/
	    temp = enelem_1.ze[n1 - 1];
/* SOURCE chkinput.for:676 */
/*<       ze(n1)=zvec(exnodt(2,n2)) >*/
	    enelem_1.ze[n1 - 1] = bnelem_1.zvec[exnodt[n2 * 9 + 2] - 1];
/* SOURCE chkinput.for:677 */
/*<       ye1(n1)=ye1(n1)+temp-ze(n1) >*/
	    enelem_1.ye1[n1 - 1] = static_cast<double>(static_cast<double>(enelem_1.ye1[n1 - 1]) + temp) - enelem_1.ze[
		    n1 - 1];
/* SOURCE chkinput.for:678 */
/*<       temp=ze(exnodt(4,n1)) >*/
	    temp = enelem_1.ze[exnodt[n1 * 9 + 4] - 1];
/* SOURCE chkinput.for:679 */
/*<       ye1(n1)=ye1(n1)+temp-ze(n1) >*/
	    enelem_1.ye1[n1 - 1] = static_cast<double>(static_cast<double>(enelem_1.ye1[n1 - 1]) + temp) - enelem_1.ze[
		    n1 - 1];
/* SOURCE chkinput.for:680 */
/*<       ze(exnodt(4,n1))=ze(n1) >*/
	    enelem_1.ze[exnodt[n1 * 9 + 4] - 1] = enelem_1.ze[n1 - 1];
/* SOURCE chkinput.for:681 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:682 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:684 */
/*<       temp=abs(ze(emc(j+1))-ze(emc(j+2))) >*/
    temp = (feq_gen_r_d_1 = static_cast<double>(enelem_1.ze[emc[j + 1] - 1]) - enelem_1.ze[emc[j + 2] - 1], 
	    dabs(feq_gen_r_d_1));
/* SOURCE chkinput.for:685 */
/*<       if(temp.gt.0.01)then >*/
    if (temp > (float).01) {
/* SOURCE chkinput.for:686 */
/*<       notea=note(j+1,emc,exnodt,ept,nex) >*/
	feq_gen_i_d_1 = j + 1;
	note_(feq_gen_ch_d_1, (ftnlen)10, &feq_gen_i_d_1, &emc[1], &exnodt[10], ept, nex);
	s_copy(notea, feq_gen_ch_d_1, (ftnlen)10, (ftnlen)10);
/* SOURCE chkinput.for:687 */
/*<       noteb=note(j+2,emc,exnodt,ept,nex) >*/
	feq_gen_i_d_1 = j + 2;
	note_(feq_gen_ch_d_1, (ftnlen)10, &feq_gen_i_d_1, &emc[1], &exnodt[10], ept, nex);
	s_copy(noteb, feq_gen_ch_d_1, (ftnlen)10, (ftnlen)10);
/* SOURCE chkinput.for:688 */
/*<       write(stdout,58)getusn(emc(j+1)),notea,getusn(emc(j+2)),noteb,temp >*/
	feq_gen_io_d__59.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__59);
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &emc[j + 1]);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, notea, (ftnlen)10);
	getusn_(feq_gen_ch_d_5, (ftnlen)5, &emc[j + 2]);
	s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, noteb, (ftnlen)10);
	do_fio(&feq_gen_c_d_1, (char *)&temp, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE chkinput.for:690 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:691 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:692 */
/*<     4 continue >*/
L4:
/*        SET THE FLOW SIGN */
/* SOURCE chkinput.for:695 */
/*<       dir=emc(j+3) >*/
    dir = emc[j + 3];
/*         HNODE = EMC(J+2) */
/* SOURCE chkinput.for:697 */
/*<       qnode=emc(j+4) >*/
    qnode = emc[j + 4];
/* SOURCE chkinput.for:698 */
/*<       sign=-dir*exnodt(1,qnode) >*/
    sign = -dir * exnodt[qnode * 9 + 1];
/* SOURCE chkinput.for:699 */
/*<       emc(j+3)=sign >*/
    emc[j + 3] = sign;
/*        BRANCH ON TYPE */
/* SOURCE chkinput.for:703 */
/*<       type=emc(j+1) >*/
    feq_gen_type_d_ = emc[j + 1];
/* SOURCE chkinput.for:704 */
/*<       goto(401,402,403,404,405,406),type >*/
    switch (feq_gen_type_d_) {
	case 1:  goto L401;
	case 2:  goto L402;
	case 3:  goto L403;
	case 4:  goto L404;
	case 5:  goto L405;
	case 6:  goto L406;
    }
/* SOURCE chkinput.for:705 */
/*<        >*/
    feq_gen_io_d__64.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__64);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:09* INVALID TYPE FOR CODE=4"), (ftnlen)33);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" IN CHKEX. TYPE="), (ftnlen)16);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE chkinput.for:707 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE chkinput.for:709 */
/*<   401 continue >*/
L401:
/* SOURCE chkinput.for:710 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+5),eflag) >*/
    chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + 5], eflag);
/* SOURCE chkinput.for:714 */
/*<       goto499 >*/
    goto L499;
/* SOURCE chkinput.for:715 */
/*<   402 continue >*/
L402:
/* SOURCE chkinput.for:716 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+5),eflag) >*/
    chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + 5], eflag);
/* SOURCE chkinput.for:720 */
/*<       goto499 >*/
    goto L499;
/* SOURCE chkinput.for:721 */
/*<   403 continue >*/
L403:
/* SOURCE chkinput.for:722 */
/*<       goto499 >*/
    goto L499;
/* SOURCE chkinput.for:723 */
/*<   404 continue >*/
L404:
/* SOURCE chkinput.for:724 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+5),eflag) >*/
    chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + 5], eflag);
/* SOURCE chkinput.for:728 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+6),eflag) >*/
    chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + 6], eflag);
/* SOURCE chkinput.for:732 */
/*<       goto499 >*/
    goto L499;
/* SOURCE chkinput.for:733 */
/*<   405 continue >*/
L405:
/* SOURCE chkinput.for:734 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+5),eflag) >*/
    chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + 5], eflag);
/*          SET ADDRESS FOR OPENING FRACTION */
/*          GET THE OPERATION BLOCK NUMBER */
/* SOURCE chkinput.for:742 */
/*<       it=emc(j+6) >*/
    it = emc[j + 6];
/* SOURCE chkinput.for:743 */
/*<       callprocess_oper_blk(stdout,j,8,6,it,opblk,nblk,ept,emc,eflag) >*/
    feq_gen_process_oper_blk_d_(stdout, &j, &feq_gen_c_d_8, &feq_gen_c_d_6, &it, &opblk[1], nblk, ept, &
	    emc[1], eflag);
/* SOURCE chkinput.for:746 */
/*<       goto499 >*/
    goto L499;
/* SOURCE chkinput.for:748 */
/*<   406 continue >*/
L406:
/* SOURCE chkinput.for:750 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+5),eflag) >*/
    chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + 5], eflag);
/* SOURCE chkinput.for:754 */
/*<       if(emc(j+6).gt.0)then >*/
    if (emc[j + 6] > 0) {
/* SOURCE chkinput.for:755 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+6),eflag) >*/
	chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + 6], eflag);
/* SOURCE chkinput.for:759 */
/*<       else >*/
    } else {
/* SOURCE chkinput.for:760 */
/*<       write(stdout,80) >*/
	feq_gen_io_d__66.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__66);
	e_wsfe();
/* SOURCE chkinput.for:761 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chkinput.for:762 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:763 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+7),eflag) >*/
    chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + 7], eflag);
/* SOURCE chkinput.for:767 */
/*<       goto499 >*/
    goto L499;
/* SOURCE chkinput.for:769 */
/*<   499 continue >*/
L499:
/* SOURCE chkinput.for:770 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:771 */
/*<     5 continue >*/
L5:
/*        SET THE SYSTEM SIGN-CONSISTS OF PRODUCT OF CONTROL STRUCTURE */
/*        SIGN AND FLOW NODE SIGN */
/*        FLOW NODE SIGN MAY BE SWITCHED BY INITIAL CONTENTS */
/*        OF EMC(J+5)-- EMC(J+5) is always 1. Remove from the */
/*        computations.  Used in pre-version 7 days! */
/* SOURCE chkinput.for:780 */
/*<       upn=emc(j+2) >*/
    upn = emc[j + 2];
/* SOURCE chkinput.for:781 */
/*<       dnn=emc(j+3) >*/
    dnn = emc[j + 3];
/* SOURCE chkinput.for:782 */
/*<       qnode=emc(j+4) >*/
    qnode = emc[j + 4];
/* SOURCE chkinput.for:783 */
/*<       sign=+1 >*/
    sign = 1;
/* SOURCE chkinput.for:784 */
/*<       if(qnode.eq.dnn)sign=-1 >*/
    if (qnode == dnn) {
	sign = -1;
    }
/* SOURCE chkinput.for:785 */
/*<       emc(j+5)=sign*exnodt(1,qnode) >*/
    emc[j + 5] = sign * exnodt[qnode * 9 + 1];
/*        BRANCH ON TYPE */
/* SOURCE chkinput.for:789 */
/*<       type=emc(j+1) >*/
    feq_gen_type_d_ = emc[j + 1];
/* SOURCE chkinput.for:790 */
/*<       goto(501,502,503,504,505,506,507,508,509),type >*/
    switch (feq_gen_type_d_) {
	case 1:  goto L501;
	case 2:  goto L502;
	case 3:  goto L503;
	case 4:  goto L504;
	case 5:  goto L505;
	case 6:  goto L506;
	case 7:  goto L507;
	case 8:  goto L508;
	case 9:  goto L509;
    }
/* SOURCE chkinput.for:791 */
/*<        >*/
    feq_gen_io_d__69.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__69);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:10* INVALID CODE 5 TYPE IN CHKEX."), (ftnlen)
	    39);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" TYPE="), (ftnlen)6);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE chkinput.for:793 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE chkinput.for:796 */
/*<   501 continue >*/
L501:
/* SOURCE chkinput.for:797 */
/*<       callchktab(20,stdout,ftpnt,mft,emc(j+7),eflag) >*/
    chktab_(&feq_gen_c_d_20, stdout, ftablea_1.ftpnt, mft, &emc[j + 7], eflag);
/* SOURCE chkinput.for:801 */
/*<       j=j+cd5ty1 >*/
    j += 7;
/* SOURCE chkinput.for:802 */
/*<       goto599 >*/
    goto L599;
/* SOURCE chkinput.for:803 */
/*<   502 continue >*/
L502:
/* SOURCE chkinput.for:804 */
/*<       do5020k=6,9 >*/
    for (k = 6; k <= 9; ++k) {
/* SOURCE chkinput.for:805 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+k),eflag) >*/
	chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + k], eflag);
/* SOURCE chkinput.for:809 */
/*<  5020 continue >*/
/* L5020: */
    }
/*          SET DEFAULTS */
/* SOURCE chkinput.for:813 */
/*<       if(emc(j+8).ne.0.or.emc(j+9).ne.0)goto5030 >*/
    if (emc[j + 8] != 0 || emc[j + 9] != 0) {
	goto L5030;
    }
/*            BOTH ZERO TAKE UPSTREAM VALUES */
/* SOURCE chkinput.for:816 */
/*<       emc(j+8)=emc(j+6) >*/
    emc[j + 8] = emc[j + 6];
/* SOURCE chkinput.for:817 */
/*<       emc(j+9)=emc(j+7) >*/
    emc[j + 9] = emc[j + 7];
/* SOURCE chkinput.for:818 */
/*<  5030 continue >*/
L5030:
/*          TURN OFF THE PUMP AT THE START */
/* SOURCE chkinput.for:822 */
/*<       emc(j+15)=0 >*/
    emc[j + 15] = 0;
/* SOURCE chkinput.for:824 */
/*<       j=j+cd5ty2 >*/
    j += 12;
/* SOURCE chkinput.for:825 */
/*<       goto599 >*/
    goto L599;
/* SOURCE chkinput.for:827 */
/*<   503 continue >*/
L503:
/* SOURCE chkinput.for:828 */
/*<       do5040k=7,9 >*/
    for (k = 7; k <= 9; ++k) {
/* SOURCE chkinput.for:829 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+k),eflag) >*/
	chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + k], eflag);
/* SOURCE chkinput.for:833 */
/*<  5040 continue >*/
/* L5040: */
    }
/* SOURCE chkinput.for:836 */
/*<       if(emc(j+10).gt.0)then >*/
    if (emc[j + 10] > 0) {
/*          Process the operation block reference or references */
/*          for this control structure. */
/* SOURCE chkinput.for:840 */
/*<       it=emc(j+10) >*/
	it = emc[j + 10];
/* SOURCE chkinput.for:842 */
/*<       n1=19 >*/
	n1 = 19;
/* SOURCE chkinput.for:843 */
/*<       n2=10 >*/
	n2 = 10;
/* SOURCE chkinput.for:844 */
/*<       callprocess_oper_blk(stdout,j,n1,n2,it,opblk,nblk,ept,emc,eflag) >*/
	feq_gen_process_oper_blk_d_(stdout, &j, &n1, &n2, &it, &opblk[1], nblk, ept, &
		emc[1], eflag);
/* SOURCE chkinput.for:849 */
/*<       elseif(emc(j+10).lt.0)then >*/
    } else if (emc[j + 10] < 0) {
/*           EMC(J+10) IS NEGATIVE MEANING THAT IT IS A TABLE NUMBER */
/* SOURCE chkinput.for:852 */
/*<       emc(j+10)=-emc(j+10) >*/
	emc[j + 10] = -emc[j + 10];
/*           CHECK FOR EXISTENCE OF TABLE AND REPLACE ITS NUMBER */
/*           WITH ITS ADDRESS IF IT IS FOUND */
/* SOURCE chkinput.for:856 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+10),eflag) >*/
	chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + 10], eflag);
/*           MAKE ADDRESS NEGATIVE TO ACT AS A FLAG FOR THIS CASE IN */
/*           Subroutine SETEXT */
/* SOURCE chkinput.for:864 */
/*<       emc(j+10)=-emc(j+10) >*/
	emc[j + 10] = -emc[j + 10];
/* SOURCE chkinput.for:865 */
/*<       endif >*/
    }
/*         If no errors get information from the tables. */
/* SOURCE chkinput.for:868 */
/*<       if(eflag.eq.0)then >*/
    if (*eflag == 0) {
/*           Get the shutoff head value. */
/* SOURCE chkinput.for:870 */
/*<       calllktab(emc(j+7),0.0,0,rdum,ntab,dflow) >*/
	lktab_(&emc[j + 7], &c_b174, &feq_gen_c_d_0, rdum, &ntab, &dflow);
/* SOURCE chkinput.for:873 */
/*<       emc(j+18)=idum >*/
	emc[j + 18] = *idum;
/*           Make sure that the value at zero in the outlet loss */
/*           table is 1.0. */
/* SOURCE chkinput.for:877 */
/*<       if(emc(j+9).gt.0)then >*/
	if (emc[j + 9] > 0) {
/* SOURCE chkinput.for:878 */
/*<       calllktab(emc(j+9),0.0,0,rdum,ntab,dflow) >*/
	    lktab_(&emc[j + 9], &c_b174, &feq_gen_c_d_0, rdum, &ntab, &dflow);
/* SOURCE chkinput.for:881 */
/*<       if(abs(rdum-1.0).gt.0.01)then >*/
	    if ((feq_gen_r_d_1 = static_cast<double>(*rdum) - (float)1., dabs(feq_gen_r_d_1)) > (float).01) {
/* SOURCE chkinput.for:882 */
/*<       write(stdout,90)get_tabid(ntab) >*/
		feq_gen_io_d__73.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__73);
		feq_gen_get_tabid_d_(feq_gen_ch_d_7, (ftnlen)16, &ntab);
		s_copy(feq_gen_ch_d_6, feq_gen_ch_d_7, (ftnlen)16, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_6, (ftnlen)16);
		e_wsfe();
/* SOURCE chkinput.for:883 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE chkinput.for:884 */
/*<       endif >*/
	    }
/* SOURCE chkinput.for:885 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:886 */
/*<       endif >*/
    }
/*         Set the velocity head factors to reflect the possiblity of */
/*         computing velocity head.  Velocity head only exists at */
/*         exterior nodes on branches. */
/* SOURCE chkinput.for:892 */
/*<       if(exnodt(3,upn).le.0)then >*/
    if (exnodt[upn * 9 + 3] <= 0) {
/*           Upstream node is a free node.  Velocity head does */
/*           not exist. */
/* SOURCE chkinput.for:895 */
/*<       rdum=0.0 >*/
	*rdum = (float)0.;
/* SOURCE chkinput.for:896 */
/*<       emc(j+16)=idum >*/
	emc[j + 16] = *idum;
/* SOURCE chkinput.for:897 */
/*<       emc(j+11)=0 >*/
	emc[j + 11] = 0;
/* SOURCE chkinput.for:898 */
/*<       else >*/
    } else {
/*           Set the pointer to the cross section table for finding */
/*           the kinetic energy flux correction coef. */
/* SOURCE chkinput.for:901 */
/*<       if(eflag.eq.0)then >*/
	if (*eflag == 0) {
/* SOURCE chkinput.for:902 */
/*<       emc(j+11)=exnodt(4,upn) >*/
	    emc[j + 11] = exnodt[upn * 9 + 4];
/* SOURCE chkinput.for:903 */
/*<       else >*/
	} else {
/* SOURCE chkinput.for:904 */
/*<       emc(j+11)=0 >*/
	    emc[j + 11] = 0;
/* SOURCE chkinput.for:905 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:906 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:907 */
/*<       if(exnodt(3,dnn).le.0)then >*/
    if (exnodt[dnn * 9 + 3] <= 0) {
/*           Downstream node is a free node. */
/* SOURCE chkinput.for:909 */
/*<       rdum=0.0 >*/
	*rdum = (float)0.;
/* SOURCE chkinput.for:910 */
/*<       emc(j+17)=idum >*/
	emc[j + 17] = *idum;
/* SOURCE chkinput.for:911 */
/*<       emc(j+12)=0 >*/
	emc[j + 12] = 0;
/* SOURCE chkinput.for:912 */
/*<       else >*/
    } else {
/*           Set the pointer to the cross section table for finding */
/*           the kinetic energy flux correction coef. */
/* SOURCE chkinput.for:915 */
/*<       if(eflag.eq.0)then >*/
	if (*eflag == 0) {
/* SOURCE chkinput.for:916 */
/*<       emc(j+12)=exnodt(4,dnn) >*/
	    emc[j + 12] = exnodt[dnn * 9 + 4];
/* SOURCE chkinput.for:917 */
/*<       else >*/
	} else {
/* SOURCE chkinput.for:918 */
/*<       emc(j+12)=0 >*/
	    emc[j + 12] = 0;
/* SOURCE chkinput.for:919 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:921 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:922 */
/*<       j=j+cd5ty3 >*/
    j += 17;
/* SOURCE chkinput.for:923 */
/*<       goto599 >*/
    goto L599;
/* SOURCE chkinput.for:925 */
/*<   504 continue >*/
L504:
/* SOURCE chkinput.for:926 */
/*<       do5050k=6,11 >*/
    for (k = 6; k <= 11; ++k) {
/* SOURCE chkinput.for:927 */
/*<       if(k.eq.8)then >*/
	if (k == 8) {
/* SOURCE chkinput.for:928 */
/*<       callchktab(20,stdout,ftpnt,mft,emc(j+k),eflag) >*/
	    chktab_(&feq_gen_c_d_20, stdout, ftablea_1.ftpnt, mft, &emc[j + k], eflag);
/* SOURCE chkinput.for:932 */
/*<       elseif(k.eq.7)then >*/
	} else if (k == 7) {
/* SOURCE chkinput.for:933 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+k),eflag) >*/
	    chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + k], eflag);
/* SOURCE chkinput.for:937 */
/*<       else >*/
	} else {
/* SOURCE chkinput.for:938 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+k),eflag) >*/
	    chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + k], eflag);
/* SOURCE chkinput.for:942 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:943 */
/*<  5050 continue >*/
/* L5050: */
    }
/* SOURCE chkinput.for:944 */
/*<       temp=abs(ze(emc(j+2))-ze(emc(j+3))) >*/
    temp = (feq_gen_r_d_1 = static_cast<double>(enelem_1.ze[emc[j + 2] - 1]) - enelem_1.ze[emc[j + 3] - 1], 
	    dabs(feq_gen_r_d_1));
/* SOURCE chkinput.for:945 */
/*<       if(temp.gt.0.01)then >*/
    if (temp > (float).01) {
/* SOURCE chkinput.for:946 */
/*<       notea=note(j+2,emc,exnodt,ept,nex) >*/
	feq_gen_i_d_1 = j + 2;
	note_(feq_gen_ch_d_1, (ftnlen)10, &feq_gen_i_d_1, &emc[1], &exnodt[10], ept, nex);
	s_copy(notea, feq_gen_ch_d_1, (ftnlen)10, (ftnlen)10);
/* SOURCE chkinput.for:947 */
/*<       noteb=note(j+3,emc,exnodt,ept,nex) >*/
	feq_gen_i_d_1 = j + 3;
	note_(feq_gen_ch_d_1, (ftnlen)10, &feq_gen_i_d_1, &emc[1], &exnodt[10], ept, nex);
	s_copy(noteb, feq_gen_ch_d_1, (ftnlen)10, (ftnlen)10);
/* SOURCE chkinput.for:948 */
/*<       write(stdout,58)getusn(emc(j+2)),notea,getusn(emc(j+3)),noteb,temp >*/
	feq_gen_io_d__74.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__74);
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &emc[j + 2]);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, notea, (ftnlen)10);
	getusn_(feq_gen_ch_d_5, (ftnlen)5, &emc[j + 3]);
	s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, noteb, (ftnlen)10);
	do_fio(&feq_gen_c_d_1, (char *)&temp, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE chkinput.for:951 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:953 */
/*<       j=j+cd5ty4 >*/
    j += 10;
/* SOURCE chkinput.for:954 */
/*<       goto599 >*/
    goto L599;
/* SOURCE chkinput.for:956 */
/*<   505 continue >*/
L505:
/*         Make sure the critical flow table is defined. */
/* SOURCE chkinput.for:959 */
/*<       callmkqctb(stdout,emc(j+8),ftp,ftknt,eflag) >*/
    mkqctb_(stdout, &emc[j + 8], ftp, ftknt, eflag);
/*         THE UPSTREAM AND DOWNSTREAM NODES ARE ON BRANCHES */
/*         AND MUST HAVE AT LEAST TYPE 21 CROSS SECTION TABLES. */
/* SOURCE chkinput.for:968 */
/*<       eflag1=0 >*/
    eflag1 = 0;
/* SOURCE chkinput.for:969 */
/*<       adrs=exnodt(4,upn) >*/
    adrs = exnodt[upn * 9 + 4];
/* SOURCE chkinput.for:970 */
/*<       tab=ftab(adrs+1) >*/
    tab = ftab[adrs + 1];
/* SOURCE chkinput.for:971 */
/*<       callchktab(21,stdout,ftpnt,mft,tab,eflag1) >*/
    chktab_(&feq_gen_c_d_21, stdout, ftablea_1.ftpnt, mft, &tab, &eflag1);
/* SOURCE chkinput.for:975 */
/*<       adrs=exnodt(4,dnn) >*/
    adrs = exnodt[dnn * 9 + 4];
/* SOURCE chkinput.for:976 */
/*<       callchktyp(stdout,adrs,21,eflag1) >*/
    chktyp_(stdout, &adrs, &feq_gen_c_d_21, &eflag1);
/* SOURCE chkinput.for:980 */
/*<       if(eflag1.gt.0)then >*/
    if (eflag1 > 0) {
/*          SOMETHING WRONG WITH THE TABLES */
/* SOURCE chkinput.for:982 */
/*<       eflag=eflag1 >*/
	*eflag = eflag1;
/* SOURCE chkinput.for:983 */
/*<       write(stdout,82)getusn(upn),getusn(dnn) >*/
	feq_gen_io_d__78.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__78);
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &upn);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	getusn_(feq_gen_ch_d_5, (ftnlen)5, &dnn);
	s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
	e_wsfe();
/* SOURCE chkinput.for:984 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:986 */
/*<       j=j+cd5ty5 >*/
    j += 3;
/* SOURCE chkinput.for:987 */
/*<       goto599 >*/
    goto L599;
/* SOURCE chkinput.for:989 */
/*<   506 continue >*/
L506:
/* SOURCE chkinput.for:990 */
/*<       ioff=0 >*/
    ioff = 0;
/*         SET THE TABLE TYPE FROM THE FIRST FLOW PATH.  ALL OTHER */
/*         PATHS MUST HAVE A TABLE OF THE SAME CLASS */
/* SOURCE chkinput.for:994 */
/*<       itype=emc(j+7+ioff) >*/
    itype = emc[j + 7 + ioff];
/* SOURCE chkinput.for:995 */
/*<       itype=itab(ftpnt(itype)+2) >*/
    itype = itab[ftablea_1.ftpnt[itype - 1] + 2];
/* SOURCE chkinput.for:996 */
/*<       if(itype.eq.14)then >*/
    if (itype == 14) {
/*           MUST BE ONLY ONE PATH. */
/* SOURCE chkinput.for:998 */
/*<       if(emc(j+6).ne.1)then >*/
	if (emc[j + 6] != 1) {
/* SOURCE chkinput.for:999 */
/*<       write(stdout,78)getusn(upn),getusn(dnn) >*/
	    feq_gen_io_d__81.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__81);
	    getusn_(feq_gen_ch_d_3, (ftnlen)5, &upn);
	    s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	    getusn_(feq_gen_ch_d_5, (ftnlen)5, &dnn);
	    s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
	    e_wsfe();
/* SOURCE chkinput.for:1000 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE chkinput.for:1001 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:1002 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1003 */
/*<       do5061i=1,emc(j+6) >*/
    feq_gen_i_d_1 = emc[j + 6];
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*           REPLACE TABLE NUMBERS WITH TABLE ADDRESS IN EMC(*) */
/* SOURCE chkinput.for:1006 */
/*<       itud=emc(j+7+ioff) >*/
	itud = emc[j + 7 + ioff];
/* SOURCE chkinput.for:1007 */
/*<       itdu=emc(j+8+ioff) >*/
	itdu = emc[j + 8 + ioff];
/* SOURCE chkinput.for:1008 */
/*<       callchktab(6,stdout,ftpnt,mft,itud,eflag) >*/
	chktab_(&feq_gen_c_d_6, stdout, ftablea_1.ftpnt, mft, &itud, eflag);
/* SOURCE chkinput.for:1012 */
/*<       callchktab(6,stdout,ftpnt,mft,itdu,eflag) >*/
	chktab_(&feq_gen_c_d_6, stdout, ftablea_1.ftpnt, mft, &itdu, eflag);
/* SOURCE chkinput.for:1016 */
/*<       emc(j+7+ioff)=itud >*/
	emc[j + 7 + ioff] = itud;
/* SOURCE chkinput.for:1017 */
/*<       emc(j+8+ioff)=itdu >*/
	emc[j + 8 + ioff] = itdu;
/* SOURCE chkinput.for:1018 */
/*<       if(itype.eq.14)then >*/
	if (itype == 14) {
/* SOURCE chkinput.for:1019 */
/*<       if(itab(itud+2).ne.14.or.itab(itdu+2).ne.14)then >*/
	    if (itab[itud + 2] != 14 || itab[itdu + 2] != 14) {
/*               INVALID TABLE TYPE MIX */
/* SOURCE chkinput.for:1021 */
/*<       write(stdout,72)get_tabid(gettbn(itud)),get_tabid(gettbn(itdu)) >*/
		feq_gen_io_d__84.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__84);
		feq_gen_i_d_2 = gettbn_(&itud);
		feq_gen_get_tabid_d_(feq_gen_ch_d_7, (ftnlen)16, &feq_gen_i_d_2);
		s_copy(feq_gen_ch_d_6, feq_gen_ch_d_7, (ftnlen)16, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_6, (ftnlen)16);
		feq_gen_i_d_3 = gettbn_(&itdu);
		feq_gen_get_tabid_d_(feq_gen_ch_d_9, (ftnlen)16, &feq_gen_i_d_3);
		s_copy(feq_gen_ch_d_8, feq_gen_ch_d_9, (ftnlen)16, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_8, (ftnlen)16);
		e_wsfe();
/* SOURCE chkinput.for:1023 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE chkinput.for:1024 */
/*<       endif >*/
	    }
/*             CHECK FOR OLD FORMAT TYPE 14. */
/* SOURCE chkinput.for:1026 */
/*<       callold14(itud,stdout,eflag) >*/
	    old14_(&itud, stdout, eflag);
/* SOURCE chkinput.for:1029 */
/*<       callold14(itdu,stdout,eflag) >*/
	    old14_(&itdu, stdout, eflag);
/* SOURCE chkinput.for:1032 */
/*<       else >*/
	} else {
/* SOURCE chkinput.for:1033 */
/*<        >*/
	    if (itab[itud + 2] != 6 && itab[itud + 2] != 13 && itab[itud + 2] 
		    != 43 || itab[itdu + 2] != 6 && itab[itdu + 2] != 13 && 
		    itab[itdu + 2] != 43) {
/*               INVALID TABLE TYPE MIX */
/* SOURCE chkinput.for:1038 */
/*<       write(stdout,74)get_tabid(gettbn(itud)),get_tabid(gettbn(itdu)) >*/
		feq_gen_io_d__85.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__85);
		feq_gen_i_d_2 = gettbn_(&itud);
		feq_gen_get_tabid_d_(feq_gen_ch_d_7, (ftnlen)16, &feq_gen_i_d_2);
		s_copy(feq_gen_ch_d_6, feq_gen_ch_d_7, (ftnlen)16, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_6, (ftnlen)16);
		feq_gen_i_d_3 = gettbn_(&itdu);
		feq_gen_get_tabid_d_(feq_gen_ch_d_9, (ftnlen)16, &feq_gen_i_d_3);
		s_copy(feq_gen_ch_d_8, feq_gen_ch_d_9, (ftnlen)16, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_8, (ftnlen)16);
		e_wsfe();
/* SOURCE chkinput.for:1040 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE chkinput.for:1041 */
/*<       endif >*/
	    }
/* SOURCE chkinput.for:1042 */
/*<       endif >*/
	}
/*           11 Dec 2006 ddf: Changes made.  We may have an operation */
/*           block number here as well as a table number.  Each must be */
/*           processed. */
/* SOURCE chkinput.for:1046 */
/*<       if(emc(j+9+ioff)<0)then >*/
	if (emc[j + 9 + ioff] < 0) {
/*             We have a time-series table number. */
/* SOURCE chkinput.for:1048 */
/*<       emc(j+9+ioff)=-emc(j+9+ioff) >*/
	    emc[j + 9 + ioff] = -emc[j + 9 + ioff];
/* SOURCE chkinput.for:1049 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+9+ioff),eflag) >*/
	    chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + 9 + ioff], 
		    eflag);
/*             Set the address to negative as a signal */
/* SOURCE chkinput.for:1054 */
/*<       emc(j+9+ioff)=-emc(j+9+ioff) >*/
	    emc[j + 9 + ioff] = -emc[j + 9 + ioff];
/* SOURCE chkinput.for:1055 */
/*<       elseif(emc(j+9+ioff)>0)then >*/
	} else if (emc[j + 9 + ioff] > 0) {
/*             This is an operation-block number */
/* SOURCE chkinput.for:1057 */
/*<       it=emc(j+9+ioff) >*/
	    it = emc[j + 9 + ioff];
/* SOURCE chkinput.for:1058 */
/*<        >*/
	    feq_gen_i_d_2 = ioff + 13;
	    feq_gen_i_d_3 = ioff + 9;
	    feq_gen_process_oper_blk_d_(stdout, &j, &feq_gen_i_d_2, &feq_gen_i_d_3, &it, &opblk[1], nblk,
		     ept, &emc[1], eflag);
/* SOURCE chkinput.for:1062 */
/*<       else >*/
	} else {
/*             Case of zero we do nothing because a zero value correctly */
/*             signals that we have neither an operation-block number nor */
/*             a time-series id! */
/* SOURCE chkinput.for:1066 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:1068 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+10+ioff),eflag) >*/
	chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + 10 + ioff], 
		eflag);
/* SOURCE chkinput.for:1073 */
/*<       ioff=ioff+cd5ty6 >*/
	ioff += 8;
/* SOURCE chkinput.for:1074 */
/*<  5061 continue >*/
/* L5061: */
    }
/*         DETECT 2-D TABLES WITH FLOW RATE AND DOWNSTREAM HEAD */
/*         AS ARGUMENTS.  USE NUMBER OF PATHS TO SIGNAL CASE. ALL PATHS */
/*         USE THE SAME TYPE CLASS. */
/* SOURCE chkinput.for:1078 */
/*<       if(itype.eq.14)then >*/
    if (itype == 14) {
/* SOURCE chkinput.for:1079 */
/*<       emc(j+6)=-emc(j+6) >*/
	emc[j + 6] = -emc[j + 6];
/* SOURCE chkinput.for:1080 */
/*<       endif >*/
    }
/*         For each of the ups and dns node, establish a link to storage locations */
/*         so that FEQ can remember the flow at the flow node and the */
/*         elevation at the other node when the maximum elevation occurs */
/*         at the ups or dns node.  Used for checking state of 2-D tables */
/*         at the end of a run or event. */
/*         Do the ups node */
/* SOURCE chkinput.for:1089 */
/*<       nlink=nlink+1 >*/
    ++nlink;
/* SOURCE chkinput.for:1090 */
/*<       if(nlink.gt.nex)then >*/
    if (nlink > *nex) {
/* SOURCE chkinput.for:1091 */
/*<       write(stdout,92)nex >*/
	feq_gen_io_d__86.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__86);
	do_fio(&feq_gen_c_d_1, (char *)&(*nex), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE chkinput.for:1092 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE chkinput.for:1093 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1094 */
/*<       tostore(upn)=nlink >*/
    enrslt_1.tostore[upn - 1] = nlink;
/* SOURCE chkinput.for:1095 */
/*<       flownode(upn)=qnode >*/
    enrslt_1.flownode[upn - 1] = qnode;
/* SOURCE chkinput.for:1096 */
/*<       othernode(upn)=dnn >*/
    enrslt_1.othernode[upn - 1] = dnn;
/*         Do the dns node */
/* SOURCE chkinput.for:1099 */
/*<       nlink=nlink+1 >*/
    ++nlink;
/* SOURCE chkinput.for:1100 */
/*<       if(nlink.gt.nex)then >*/
    if (nlink > *nex) {
/* SOURCE chkinput.for:1101 */
/*<       write(stdout,92)nex >*/
	feq_gen_io_d__87.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__87);
	do_fio(&feq_gen_c_d_1, (char *)&(*nex), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE chkinput.for:1102 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE chkinput.for:1103 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1104 */
/*<       tostore(dnn)=nlink >*/
    enrslt_1.tostore[dnn - 1] = nlink;
/* SOURCE chkinput.for:1105 */
/*<       flownode(dnn)=qnode >*/
    enrslt_1.flownode[dnn - 1] = qnode;
/* SOURCE chkinput.for:1106 */
/*<       othernode(dnn)=upn >*/
    enrslt_1.othernode[dnn - 1] = upn;
/* SOURCE chkinput.for:1108 */
/*<       j=j+1+ioff >*/
    j = j + 1 + ioff;
/* SOURCE chkinput.for:1109 */
/*<       goto599 >*/
    goto L599;
/* SOURCE chkinput.for:1111 */
/*<   507 continue >*/
L507:
/* SOURCE chkinput.for:1112 */
/*<       do5070k=7,10 >*/
    for (k = 7; k <= 10; ++k) {
/* SOURCE chkinput.for:1113 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+k),eflag) >*/
	chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + k], eflag);
/* SOURCE chkinput.for:1117 */
/*<  5070 continue >*/
/* L5070: */
    }
/* SOURCE chkinput.for:1119 */
/*<       if(emc(j+6).gt.0)then >*/
    if (emc[j + 6] > 0) {
/*          SET ADDRESS FOR OPENING FRACTION */
/*          GET THE OPERATION BLOCK NUMBER */
/* SOURCE chkinput.for:1123 */
/*<       it=emc(j+6) >*/
	it = emc[j + 6];
/* SOURCE chkinput.for:1124 */
/*<       callprocess_oper_blk(stdout,j,13,6,it,opblk,nblk,ept,emc,eflag) >*/
	feq_gen_process_oper_blk_d_(stdout, &j, &feq_gen_c_d_13, &feq_gen_c_d_6, &it, &opblk[1], nblk, 
		ept, &emc[1], eflag);
/* SOURCE chkinput.for:1127 */
/*<       elseif(emc(j+6).lt.0)then >*/
    } else if (emc[j + 6] < 0) {
/*           EMC(J+6) IS NEGATIVE MEANING THAT IT IS A TABLE NUMBER */
/* SOURCE chkinput.for:1130 */
/*<       emc(j+6)=-emc(j+6) >*/
	emc[j + 6] = -emc[j + 6];
/*           CHECK FOR EXISTENCE OF TABLE AND REPLACE ITS NUMBER */
/*           WITH ITS ADDRESS IF IT IS FOUND */
/* SOURCE chkinput.for:1134 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+6),eflag) >*/
	chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + 6], eflag);
/*           MAKE ADDRESS NEGATIVE TO ACT AS A FLAG FOR THE CASE IN */
/*           Subroutine SETEXT */
/* SOURCE chkinput.for:1142 */
/*<       emc(j+6)=-emc(j+6) >*/
	emc[j + 6] = -emc[j + 6];
/* SOURCE chkinput.for:1143 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1145 */
/*<       j=j+cd5ty7 >*/
    j += 10;
/* SOURCE chkinput.for:1146 */
/*<       goto599 >*/
    goto L599;
/* SOURCE chkinput.for:1148 */
/*<   508 continue >*/
L508:
/* SOURCE chkinput.for:1149 */
/*<       if(emc(j+6).gt.0)then >*/
    if (emc[j + 6] > 0) {
/*          SET ADDRESS FOR OPENING FRACTION */
/*          GET THE OPERATION BLOCK NUMBER */
/* SOURCE chkinput.for:1154 */
/*<       it=emc(j+6) >*/
	it = emc[j + 6];
/* SOURCE chkinput.for:1155 */
/*<       callprocess_oper_blk(stdout,j,10,6,it,opblk,nblk,ept,emc,eflag) >*/
	feq_gen_process_oper_blk_d_(stdout, &j, &feq_gen_c_d_10, &feq_gen_c_d_6, &it, &opblk[1], nblk, 
		ept, &emc[1], eflag);
/* SOURCE chkinput.for:1159 */
/*<       elseif(emc(j+6).lt.0)then >*/
    } else if (emc[j + 6] < 0) {
/*           EMC(J+6) IS NEGATIVE MEANING THAT IT IS A TABLE NUMBER */
/* SOURCE chkinput.for:1162 */
/*<       emc(j+6)=-emc(j+6) >*/
	emc[j + 6] = -emc[j + 6];
/*           CHECK FOR EXISTENCE OF TABLE AND REPLACE ITS NUMBER */
/*           WITH ITS ADDRESS IF IT IS FOUND */
/* SOURCE chkinput.for:1166 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+6),eflag) >*/
	chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + 6], eflag);
/*           MAKE ADDRESS NEGATIVE TO ACT AS A FLAG FOR THE CASE IN */
/*           Subroutine SETEXT */
/* SOURCE chkinput.for:1174 */
/*<       emc(j+6)=-emc(j+6) >*/
	emc[j + 6] = -emc[j + 6];
/* SOURCE chkinput.for:1175 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1177 */
/*<       j=j+cd5ty8 >*/
    j += 7;
/* SOURCE chkinput.for:1178 */
/*<       goto599 >*/
    goto L599;
/* SOURCE chkinput.for:1180 */
/*<   509 continue >*/
L509:
/*         Tables must be in type class 15. */
/* SOURCE chkinput.for:1182 */
/*<       if(emc(j+8).eq.emc(j+9))then >*/
    if (emc[j + 8] == emc[j + 9]) {
/* SOURCE chkinput.for:1183 */
/*<       callchktab(15,stdout,ftpnt,mft,emc(j+8),eflag) >*/
	chktab_(&feq_gen_c_d_15, stdout, ftablea_1.ftpnt, mft, &emc[j + 8], eflag);
/* SOURCE chkinput.for:1187 */
/*<       if(eflag.eq.0)then >*/
	if (*eflag == 0) {
/*             Check the contents of the table to make sure that */
/*             the tables referenced in the table also exist and */
/*             are of the proper type. */
/* SOURCE chkinput.for:1191 */
/*<       callckty15(emc(j+8),stdout,eflag) >*/
	    ckty15_(&emc[j + 8], stdout, eflag);
/* SOURCE chkinput.for:1194 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:1195 */
/*<       emc(j+9)=emc(j+8) >*/
	emc[j + 9] = emc[j + 8];
/* SOURCE chkinput.for:1196 */
/*<       else >*/
    } else {
/* SOURCE chkinput.for:1197 */
/*<       do5090k=8,9 >*/
	for (k = 8; k <= 9; ++k) {
/* SOURCE chkinput.for:1198 */
/*<       callchktab(15,stdout,ftpnt,mft,emc(j+k),eflag) >*/
	    chktab_(&feq_gen_c_d_15, stdout, ftablea_1.ftpnt, mft, &emc[j + k], eflag);
/* SOURCE chkinput.for:1202 */
/*<       if(eflag.eq.0)then >*/
	    if (*eflag == 0) {
/*               Check the contents of the table to make sure that */
/*               the tables referenced in the table also exist and */
/*               are of the proper type. */
/* SOURCE chkinput.for:1206 */
/*<       callckty15(emc(j+k),stdout,eflag) >*/
		ckty15_(&emc[j + k], stdout, eflag);
/* SOURCE chkinput.for:1209 */
/*<       endif >*/
	    }
/* SOURCE chkinput.for:1210 */
/*<  5090 continue >*/
/* L5090: */
	}
/* SOURCE chkinput.for:1211 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1213 */
/*<       if(emc(j+6).gt.0)then >*/
    if (emc[j + 6] > 0) {
/*          SET ADDRESS FOR OPENING FRACTION */
/*          GET THE OPERATION BLOCK NUMBER */
/* SOURCE chkinput.for:1217 */
/*<       it=emc(j+6) >*/
	it = emc[j + 6];
/* SOURCE chkinput.for:1218 */
/*<       callprocess_oper_blk(stdout,j,13,6,it,opblk,nblk,ept,emc,eflag) >*/
	feq_gen_process_oper_blk_d_(stdout, &j, &feq_gen_c_d_13, &feq_gen_c_d_6, &it, &opblk[1], nblk, 
		ept, &emc[1], eflag);
/* SOURCE chkinput.for:1222 */
/*<       elseif(emc(j+6).lt.0)then >*/
    } else if (emc[j + 6] < 0) {
/*           EMC(J+6) IS NEGATIVE MEANING THAT IT IS A TABLE NUMBER */
/* SOURCE chkinput.for:1225 */
/*<       emc(j+6)=-emc(j+6) >*/
	emc[j + 6] = -emc[j + 6];
/*           CHECK FOR EXISTENCE OF TABLE AND REPLACE ITS NUMBER */
/*           WITH ITS ADDRESS IF IT IS FOUND */
/* SOURCE chkinput.for:1229 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+6),eflag) >*/
	chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + 6], eflag);
/*           MAKE ADDRESS NEGATIVE TO ACT AS A FLAG FOR THE CASE IN */
/*           Subroutine SETEXT */
/* SOURCE chkinput.for:1237 */
/*<       emc(j+6)=-emc(j+6) >*/
	emc[j + 6] = -emc[j + 6];
/* SOURCE chkinput.for:1238 */
/*<       endif >*/
    }
/*         Check for existence of the gate-efficiency factor table. */
/* SOURCE chkinput.for:1241 */
/*<       if(emc(j+15).gt.0)then >*/
    if (emc[j + 15] > 0) {
/*           Such a table was referenced. */
/* SOURCE chkinput.for:1243 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+15),eflag) >*/
	chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + 15], eflag);
/* SOURCE chkinput.for:1247 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1249 */
/*<       j=j+cd5ty9 >*/
    j += 11;
/* SOURCE chkinput.for:1250 */
/*<       goto599 >*/
    goto L599;
/* SOURCE chkinput.for:1253 */
/*<   599 continue >*/
L599:
/* SOURCE chkinput.for:1254 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:1256 */
/*<     6 continue >*/
L6:
/*         SET FLOW SIGN */
/*         IN THIS CASE THE FLOW NODE IS THE SAME AS THE GIVEN NODE */
/* SOURCE chkinput.for:1261 */
/*<       dir=emc(j+3) >*/
    dir = emc[j + 3];
/* SOURCE chkinput.for:1262 */
/*<       node=emc(j+2) >*/
    node = emc[j + 2];
/* SOURCE chkinput.for:1263 */
/*<       emc(j+3)=-dir*exnodt(1,node) >*/
    emc[j + 3] = -dir * exnodt[node * 9 + 1];
/* SOURCE chkinput.for:1265 */
/*<       if(emc(j+4).gt.0)then >*/
    if (emc[j + 4] > 0) {
/* SOURCE chkinput.for:1266 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+4),eflag) >*/
	chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + 4], eflag);
/* SOURCE chkinput.for:1270 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1271 */
/*<       if(emc(j+10).gt.0)then >*/
    if (emc[j + 10] > 0) {
/* SOURCE chkinput.for:1272 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+10),eflag) >*/
	chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + 10], eflag);
/* SOURCE chkinput.for:1276 */
/*<       endif >*/
    }
/*         Do checking for any tributary area attached to this boundary */
/*         node.  If any is present this node will appear in the list */
/*         of reservoirs with tributary area.  The node must also be */
/*         present in the tributary area management system and it also */
/*         must have either a delay or a detention reservoir present. */
/*         Furthermore the whole tributary area must have at least */
/*         delay present. */
/* SOURCE chkinput.for:1287 */
/*<       iadrs=0 >*/
    iadrs = 0;
/* SOURCE chkinput.for:1288 */
/*<       flow_address_in_emc=j+6 >*/
    feq_gen_flow_address_in_emc_d_ = j + 6;
/* SOURCE chkinput.for:1289 */
/*<       do605i=1,nrwta >*/
    feq_gen_i_d_1 = *nrwta;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE chkinput.for:1290 */
/*<       if(node.eq.rwta(i))then >*/
	if (node == rwta[feq_gen_i_d_]) {
/* SOURCE chkinput.for:1291 */
/*<       if(emc(j+4).ne.0)then >*/
	    if (emc[j + 4] != 0) {
/*               Error-cannot have both a time series source other */
/*               than constant flow AND tributary area at the boundary */
/*               node. */
/* SOURCE chkinput.for:1295 */
/*<       write(stdout,91)getusn(node) >*/
		feq_gen_io_d__91.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__91);
		getusn_(feq_gen_ch_d_3, (ftnlen)5, &node);
		s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
		e_wsfe();
/* SOURCE chkinput.for:1296 */
/*<       stop'Abnormal stop.  Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE chkinput.for:1297 */
/*<       else >*/
	    } else {
/*               Scan the trib area management blocks to find */
/*               all occurrences of this node.  It should occur at */
/*               least once but can appear twice: once for the area */
/*               subject to detention and once for the area not */
/*               subject to detention. */
/* SOURCE chkinput.for:1303 */
/*<       callchk_bn_with_trib_area(stdout,flow_address_in_emc,node) >*/
		feq_gen_chk_bn_with_trib_area_d_(stdout, &feq_gen_flow_address_in_emc_d_, &node)
			;
/* SOURCE chkinput.for:1305 */
/*<       iadrs=rtap(i) >*/
		iadrs = rtap[feq_gen_i_d_];
/*               Set signal for final error check below to show that */
/*               this boundary node has been found in the input list. */
/* SOURCE chkinput.for:1308 */
/*<       rwta(i)=-rwta(i) >*/
		rwta[feq_gen_i_d_] = -rwta[feq_gen_i_d_];
/* SOURCE chkinput.for:1309 */
/*<       goto610 >*/
		goto L610;
/* SOURCE chkinput.for:1310 */
/*<       endif >*/
	    }
/* SOURCE chkinput.for:1311 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:1312 */
/*<   605 continue >*/
/* L605: */
    }
/* SOURCE chkinput.for:1313 */
/*<   610 continue >*/
L610:
/* SOURCE chkinput.for:1315 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:1317 */
/*<     7 continue >*/
L7:
/* SOURCE chkinput.for:1318 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+2),eflag) >*/
    chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + 2], eflag);
/* SOURCE chkinput.for:1322 */
/*<       node=emc(j+1) >*/
    node = emc[j + 1];
/*         STORE ADDRESS OF RESERVOIR TABLE IN EXNODT */
/* SOURCE chkinput.for:1326 */
/*<       exnodt(4,node)=emc(j+2) >*/
    exnodt[node * 9 + 4] = emc[j + 2];
/*         FIND tributary area inflow location if any. */
/* SOURCE chkinput.for:1330 */
/*<       iadrs=0 >*/
    iadrs = 0;
/* SOURCE chkinput.for:1331 */
/*<       do705i=1,nrwta >*/
    feq_gen_i_d_1 = *nrwta;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE chkinput.for:1332 */
/*<       if(node.eq.rwta(i))then >*/
	if (node == rwta[feq_gen_i_d_]) {
/* SOURCE chkinput.for:1333 */
/*<       iadrs=rtap(i) >*/
	    iadrs = rtap[feq_gen_i_d_];
/* SOURCE chkinput.for:1334 */
/*<       rwta(i)=-rwta(i) >*/
	    rwta[feq_gen_i_d_] = -rwta[feq_gen_i_d_];
/* SOURCE chkinput.for:1335 */
/*<       goto710 >*/
	    goto L710;
/* SOURCE chkinput.for:1336 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:1337 */
/*<   705 continue >*/
/* L705: */
    }
/* SOURCE chkinput.for:1338 */
/*<   710 continue >*/
L710:
/* SOURCE chkinput.for:1340 */
/*<       emc(j+3)=iadrs >*/
    emc[j + 3] = iadrs;
/* SOURCE chkinput.for:1341 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:1343 */
/*<     8 continue >*/
L8:
/* SOURCE chkinput.for:1344 */
/*<       it=emc(j+1) >*/
    it = emc[j + 1];
/* SOURCE chkinput.for:1345 */
/*<       if(exnodt(3,it).gt.0)goto300 >*/
    if (exnodt[it * 9 + 3] > 0) {
	goto L300;
    }
/*          ERROR -NODE IS NOT ON A BRANCH */
/* SOURCE chkinput.for:1348 */
/*<       write(stdout,52)getusn(it) >*/
    feq_gen_io_d__92.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__92);
    getusn_(feq_gen_ch_d_3, (ftnlen)5, &it);
    s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
    e_wsfe();
/* SOURCE chkinput.for:1349 */
/*<       eflag=1 >*/
    *eflag = 1;
/* SOURCE chkinput.for:1350 */
/*<       it=1 >*/
    it = 1;
/* SOURCE chkinput.for:1351 */
/*<   300 continue >*/
L300:
/*          STORE THE DIRECT ADDRESS */
/* SOURCE chkinput.for:1355 */
/*<       emc(j+1)=it >*/
    emc[j + 1] = it;
/* SOURCE chkinput.for:1356 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:1357 */
/*<     9 continue >*/
L9:
/* SOURCE chkinput.for:1358 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:1360 */
/*<    10 continue >*/
L10:
/* SOURCE chkinput.for:1361 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:1362 */
/*<    11 continue >*/
L11:
/*         SPECIAL INFLOW AND OUTFLOW POINT IN A CHANNEL. */
/*         BOTTOM ELEVATIONS MUST MATCH, BOTH NODES MUST BE ON BRANCHES */
/*         AND THE CROSS SECTIONS MUST BE THE SAME. */
/* SOURCE chkinput.for:1367 */
/*<       upn=emc(j+1) >*/
    upn = emc[j + 1];
/* SOURCE chkinput.for:1368 */
/*<       dnn=emc(j+2) >*/
    dnn = emc[j + 2];
/* SOURCE chkinput.for:1370 */
/*<       if(exnodt(3,upn).le.0)then >*/
    if (exnodt[upn * 9 + 3] <= 0) {
/* SOURCE chkinput.for:1371 */
/*<       write(stdout,60)getusn(upn),code >*/
	feq_gen_io_d__93.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__93);
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &upn);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE chkinput.for:1372 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chkinput.for:1373 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1374 */
/*<       if(exnodt(3,dnn).le.0)then >*/
    if (exnodt[dnn * 9 + 3] <= 0) {
/* SOURCE chkinput.for:1375 */
/*<       write(stdout,60)getusn(dnn),code >*/
	feq_gen_io_d__94.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__94);
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &dnn);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE chkinput.for:1376 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chkinput.for:1377 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1379 */
/*<       if(exnodt(3,upn).gt.0.and.exnodt(3,dnn).gt.0)then >*/
    if (exnodt[upn * 9 + 3] > 0 && exnodt[dnn * 9 + 3] > 0) {
/* SOURCE chkinput.for:1380 */
/*<       if(exnodt(4,upn).ne.exnodt(4,dnn))then >*/
	if (exnodt[upn * 9 + 4] != exnodt[dnn * 9 + 4]) {
/* SOURCE chkinput.for:1381 */
/*<       write(stdout,62)code,getusn(upn),getusn(dnn) >*/
	    feq_gen_io_d__95.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__95);
	    do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
	    getusn_(feq_gen_ch_d_3, (ftnlen)5, &upn);
	    s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	    getusn_(feq_gen_ch_d_5, (ftnlen)5, &dnn);
	    s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
	    e_wsfe();
/* SOURCE chkinput.for:1382 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE chkinput.for:1383 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:1384 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1386 */
/*<       if(abs(ze(upn)-ze(dnn)).gt.0.005)then >*/
    if ((feq_gen_r_d_1 = static_cast<double>(enelem_1.ze[upn - 1]) - enelem_1.ze[dnn - 1], dabs(feq_gen_r_d_1)) > (
	    float).005) {
/* SOURCE chkinput.for:1387 */
/*<       write(stdout,64)code,getusn(upn),getusn(dnn) >*/
	feq_gen_io_d__96.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__96);
	do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &upn);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	getusn_(feq_gen_ch_d_5, (ftnlen)5, &dnn);
	s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
	e_wsfe();
/* SOURCE chkinput.for:1388 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chkinput.for:1389 */
/*<       endif >*/
    }
/*         CROSS SECTION FUNCTION TABLE MUST CONTAIN THE FIRST MOMENT */
/*         OF AREA. TYPE 21, 22, 24, 25. */
/* SOURCE chkinput.for:1394 */
/*<       adrs=exnodt(4,upn) >*/
    adrs = exnodt[upn * 9 + 4];
/* SOURCE chkinput.for:1395 */
/*<       eflag1=0 >*/
    eflag1 = 0;
/* SOURCE chkinput.for:1396 */
/*<       callchktyp(stdout,adrs,21,eflag1) >*/
    chktyp_(stdout, &adrs, &feq_gen_c_d_21, &eflag1);
/* SOURCE chkinput.for:1399 */
/*<       if(eflag1.gt.0)then >*/
    if (eflag1 > 0) {
/* SOURCE chkinput.for:1400 */
/*<       write(stdout,84)code,getusn(upn),getusn(dnn) >*/
	feq_gen_io_d__97.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__97);
	do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &upn);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	getusn_(feq_gen_ch_d_5, (ftnlen)5, &dnn);
	s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
	e_wsfe();
/* SOURCE chkinput.for:1401 */
/*<       eflag=eflag1 >*/
	*eflag = eflag1;
/* SOURCE chkinput.for:1402 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1404 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:1407 */
/*<    12 continue >*/
L12:
/* SOURCE chkinput.for:1409 */
/*<       temp=abs(ze(emc(j+1))-ze(emc(j+2))) >*/
    temp = (feq_gen_r_d_1 = static_cast<double>(enelem_1.ze[emc[j + 1] - 1]) - enelem_1.ze[emc[j + 2] - 1], 
	    dabs(feq_gen_r_d_1));
/* SOURCE chkinput.for:1410 */
/*<       if(temp.gt.0.01)then >*/
    if (temp > (float).01) {
/* SOURCE chkinput.for:1411 */
/*<       notea=note(j+1,emc,exnodt,ept,nex) >*/
	feq_gen_i_d_1 = j + 1;
	note_(feq_gen_ch_d_1, (ftnlen)10, &feq_gen_i_d_1, &emc[1], &exnodt[10], ept, nex);
	s_copy(notea, feq_gen_ch_d_1, (ftnlen)10, (ftnlen)10);
/* SOURCE chkinput.for:1412 */
/*<       noteb=note(j+2,emc,exnodt,ept,nex) >*/
	feq_gen_i_d_1 = j + 2;
	note_(feq_gen_ch_d_1, (ftnlen)10, &feq_gen_i_d_1, &emc[1], &exnodt[10], ept, nex);
	s_copy(noteb, feq_gen_ch_d_1, (ftnlen)10, (ftnlen)10);
/* SOURCE chkinput.for:1413 */
/*<       write(stdout,58)getusn(emc(j+1)),notea,getusn(emc(j+2)),noteb,temp >*/
	feq_gen_io_d__98.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__98);
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &emc[j + 1]);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, notea, (ftnlen)10);
	getusn_(feq_gen_ch_d_5, (ftnlen)5, &emc[j + 2]);
	s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, noteb, (ftnlen)10);
	do_fio(&feq_gen_c_d_1, (char *)&temp, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE chkinput.for:1415 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1416 */
/*<       temp=abs(ze(emc(j+2))-ze(emc(j+3))) >*/
    temp = (feq_gen_r_d_1 = static_cast<double>(enelem_1.ze[emc[j + 2] - 1]) - enelem_1.ze[emc[j + 3] - 1], 
	    dabs(feq_gen_r_d_1));
/* SOURCE chkinput.for:1417 */
/*<       if(temp.gt.0.01)then >*/
    if (temp > (float).01) {
/* SOURCE chkinput.for:1418 */
/*<       notea=note(j+2,emc,exnodt,ept,nex) >*/
	feq_gen_i_d_1 = j + 2;
	note_(feq_gen_ch_d_1, (ftnlen)10, &feq_gen_i_d_1, &emc[1], &exnodt[10], ept, nex);
	s_copy(notea, feq_gen_ch_d_1, (ftnlen)10, (ftnlen)10);
/* SOURCE chkinput.for:1419 */
/*<       noteb=note(j+3,emc,exnodt,ept,nex) >*/
	feq_gen_i_d_1 = j + 3;
	note_(feq_gen_ch_d_1, (ftnlen)10, &feq_gen_i_d_1, &emc[1], &exnodt[10], ept, nex);
	s_copy(noteb, feq_gen_ch_d_1, (ftnlen)10, (ftnlen)10);
/* SOURCE chkinput.for:1420 */
/*<       write(stdout,58)getusn(emc(j+2)),notea,getusn(emc(j+3)),noteb,temp >*/
	feq_gen_io_d__99.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__99);
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &emc[j + 2]);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, notea, (ftnlen)10);
	getusn_(feq_gen_ch_d_5, (ftnlen)5, &emc[j + 3]);
	s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, noteb, (ftnlen)10);
	do_fio(&feq_gen_c_d_1, (char *)&temp, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE chkinput.for:1422 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1424 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:1425 */
/*<    13 continue >*/
L13:
/*         SPECIAL INFLOW AND OUTFLOW POINT IN A CHANNEL. */
/*         BOTTOM ELEVATIONS MUST MATCH, BOTH NODES MUST BE ON BRANCHES */
/*         AND THE CROSS SECTIONS MUST BE THE SAME. */
/* SOURCE chkinput.for:1430 */
/*<       upn=emc(j+1) >*/
    upn = emc[j + 1];
/* SOURCE chkinput.for:1431 */
/*<       dnn=emc(j+2) >*/
    dnn = emc[j + 2];
/* SOURCE chkinput.for:1433 */
/*<       if(exnodt(3,upn).le.0)then >*/
    if (exnodt[upn * 9 + 3] <= 0) {
/* SOURCE chkinput.for:1434 */
/*<       write(stdout,60)getusn(upn),code >*/
	feq_gen_io_d__100.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__100);
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &upn);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE chkinput.for:1435 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chkinput.for:1436 */
/*<       else >*/
    } else {
/*           The upstream node for this structure must be the */
/*           downstream node on the branch. */
/* SOURCE chkinput.for:1439 */
/*<       if(exnodt(1,upn).ne.1)then >*/
	if (exnodt[upn * 9 + 1] != 1) {
/* SOURCE chkinput.for:1440 */
/*<       write(stdout,85)getusn(upn),code >*/
	    feq_gen_io_d__101.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__101);
	    getusn_(feq_gen_ch_d_3, (ftnlen)5, &upn);
	    s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE chkinput.for:1441 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE chkinput.for:1442 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:1443 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1444 */
/*<       if(exnodt(3,dnn).le.0)then >*/
    if (exnodt[dnn * 9 + 3] <= 0) {
/* SOURCE chkinput.for:1445 */
/*<       write(stdout,60)getusn(dnn),code >*/
	feq_gen_io_d__102.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__102);
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &dnn);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE chkinput.for:1446 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chkinput.for:1447 */
/*<       else >*/
    } else {
/*           The downstream node for this structure must be the */
/*           upstream node on the branch. */
/* SOURCE chkinput.for:1450 */
/*<       if(exnodt(1,dnn).ne.-1)then >*/
	if (exnodt[dnn * 9 + 1] != -1) {
/* SOURCE chkinput.for:1451 */
/*<       write(stdout,86)getusn(dnn),code >*/
	    feq_gen_io_d__103.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__103);
	    getusn_(feq_gen_ch_d_3, (ftnlen)5, &dnn);
	    s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE chkinput.for:1452 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE chkinput.for:1453 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:1454 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1456 */
/*<       if(exnodt(3,upn).gt.0.and.exnodt(3,dnn).gt.0)then >*/
    if (exnodt[upn * 9 + 3] > 0 && exnodt[dnn * 9 + 3] > 0) {
/* SOURCE chkinput.for:1457 */
/*<       if(exnodt(4,upn).ne.exnodt(4,dnn))then >*/
	if (exnodt[upn * 9 + 4] != exnodt[dnn * 9 + 4]) {
/* SOURCE chkinput.for:1458 */
/*<       write(stdout,62)code,getusn(upn),getusn(dnn) >*/
	    feq_gen_io_d__104.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__104);
	    do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
	    getusn_(feq_gen_ch_d_3, (ftnlen)5, &upn);
	    s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	    getusn_(feq_gen_ch_d_5, (ftnlen)5, &dnn);
	    s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
	    e_wsfe();
/* SOURCE chkinput.for:1459 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE chkinput.for:1460 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:1461 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1463 */
/*<       if(abs(ze(upn)-ze(dnn)).gt.0.005)then >*/
    if ((feq_gen_r_d_1 = static_cast<double>(enelem_1.ze[upn - 1]) - enelem_1.ze[dnn - 1], dabs(feq_gen_r_d_1)) > (
	    float).005) {
/* SOURCE chkinput.for:1464 */
/*<       write(stdout,64)code,getusn(upn),getusn(dnn) >*/
	feq_gen_io_d__105.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__105);
	do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &upn);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	getusn_(feq_gen_ch_d_5, (ftnlen)5, &dnn);
	s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
	e_wsfe();
/* SOURCE chkinput.for:1465 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chkinput.for:1466 */
/*<       endif >*/
    }
/*         CROSS SECTION FUNCTION TABLE MUST CONTAIN THE FIRST MOMENT */
/*         OF AREA. TYPE 21, 22, 24, 25.  Feb. 15, 2001: It must */
/*         also contain the critical flow! */
/* SOURCE chkinput.for:1472 */
/*<       adrs=exnodt(4,upn) >*/
    adrs = exnodt[upn * 9 + 4];
/* SOURCE chkinput.for:1473 */
/*<       eflag1=0 >*/
    eflag1 = 0;
/* SOURCE chkinput.for:1474 */
/*<       callchktyp(stdout,adrs,22,eflag1) >*/
    chktyp_(stdout, &adrs, &feq_gen_c_d_22, &eflag1);
/* SOURCE chkinput.for:1477 */
/*<       if(eflag1.gt.0)then >*/
    if (eflag1 > 0) {
/* SOURCE chkinput.for:1478 */
/*<       write(stdout,94)code,getusn(upn),getusn(dnn) >*/
	feq_gen_io_d__106.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__106);
	do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &upn);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	getusn_(feq_gen_ch_d_5, (ftnlen)5, &dnn);
	s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
	e_wsfe();
/*            EFLAG = EFLAG1 */
/* SOURCE chkinput.for:1480 */
/*<       else >*/
    } else {
/*           Set the type flag in EMC to signal availability of */
/*           tabulated values of ALPHA. */
/* SOURCE chkinput.for:1483 */
/*<       type=gettyp(adrs) >*/
	feq_gen_type_d_ = gettyp_(&adrs);
/* SOURCE chkinput.for:1484 */
/*<       if(type.eq.22.or.type.eq.25.or.type.eq.32.or.type.eq.35)then >*/
	if (feq_gen_type_d_ == 22 || feq_gen_type_d_ == 25 || feq_gen_type_d_ == 32 || feq_gen_type_d_ == 35) {
/* SOURCE chkinput.for:1486 */
/*<       emc(j+4)=1 >*/
	    emc[j + 4] = 1;
/* SOURCE chkinput.for:1487 */
/*<       else >*/
	} else {
/* SOURCE chkinput.for:1488 */
/*<       emc(j+4)=0 >*/
	    emc[j + 4] = 0;
/*              WRITE(STDOUT,*) ' BUG: Code=13 in CHKEX.' */
/*              STOP 'Abnormal stop.  Bug found.' */
/* SOURCE chkinput.for:1491 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:1492 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1494 */
/*<       if(emc(j+6).gt.0)then >*/
    if (emc[j + 6] > 0) {
/*           Check the side nodes.  Must be on a branch.  The */
/*           cross section function tables do not need first moment */
/*           in this approximation.  We will only compute momentum flux */
/*           and all cross section function tables contain area and */
/*           beta. */
/* SOURCE chkinput.for:1500 */
/*<       if(exnodt(3,emc(j+7)).le.0)then >*/
	if (exnodt[emc[j + 7] * 9 + 3] <= 0) {
/* SOURCE chkinput.for:1501 */
/*<       write(stdout,60)getusn(emc(j+7)),code >*/
	    feq_gen_io_d__107.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__107);
	    getusn_(feq_gen_ch_d_3, (ftnlen)5, &emc[j + 7]);
	    s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE chkinput.for:1502 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE chkinput.for:1503 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:1504 */
/*<       if(emc(j+6).gt.1)then >*/
	if (emc[j + 6] > 1) {
/* SOURCE chkinput.for:1505 */
/*<       if(exnodt(3,emc(j+8)).le.0)then >*/
	    if (exnodt[emc[j + 8] * 9 + 3] <= 0) {
/* SOURCE chkinput.for:1506 */
/*<       write(stdout,60)getusn(emc(j+8)),code >*/
		feq_gen_io_d__108.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__108);
		getusn_(feq_gen_ch_d_3, (ftnlen)5, &emc[j + 8]);
		s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE chkinput.for:1507 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE chkinput.for:1508 */
/*<       endif >*/
	    }
/* SOURCE chkinput.for:1509 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:1510 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1511 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:1513 */
/*<    14 continue >*/
L14:
/*         SIDE-WEIR OUTFLOW INFLOW. TO BE USED ONLY WITH CODE 13 OR */
/*         PERHAPS 11.  DO SAME CHECKS AS FOR THOSE PLUS CHECK THE */
/*         TABLE NUMBERS. */
/* SOURCE chkinput.for:1518 */
/*<       upn=emc(j+1) >*/
    upn = emc[j + 1];
/* SOURCE chkinput.for:1519 */
/*<       dnn=emc(j+2) >*/
    dnn = emc[j + 2];
/*          MDN = EMC(J+3) */
/* SOURCE chkinput.for:1522 */
/*<       if(exnodt(3,upn).le.0)then >*/
    if (exnodt[upn * 9 + 3] <= 0) {
/* SOURCE chkinput.for:1523 */
/*<       write(stdout,60)getusn(upn),code >*/
	feq_gen_io_d__109.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__109);
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &upn);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE chkinput.for:1524 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chkinput.for:1525 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1526 */
/*<       if(exnodt(3,dnn).le.0)then >*/
    if (exnodt[dnn * 9 + 3] <= 0) {
/* SOURCE chkinput.for:1527 */
/*<       write(stdout,60)getusn(dnn),code >*/
	feq_gen_io_d__110.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__110);
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &dnn);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE chkinput.for:1528 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chkinput.for:1529 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1531 */
/*<       if(exnodt(3,upn).gt.0.and.exnodt(3,dnn).gt.0)then >*/
    if (exnodt[upn * 9 + 3] > 0 && exnodt[dnn * 9 + 3] > 0) {
/* SOURCE chkinput.for:1532 */
/*<       if(exnodt(4,upn).ne.exnodt(4,dnn))then >*/
	if (exnodt[upn * 9 + 4] != exnodt[dnn * 9 + 4]) {
/* SOURCE chkinput.for:1533 */
/*<       write(stdout,62)code,getusn(upn),getusn(dnn) >*/
	    feq_gen_io_d__111.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__111);
	    do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
	    getusn_(feq_gen_ch_d_3, (ftnlen)5, &upn);
	    s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	    getusn_(feq_gen_ch_d_5, (ftnlen)5, &dnn);
	    s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
	    e_wsfe();
/* SOURCE chkinput.for:1534 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE chkinput.for:1535 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:1536 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1538 */
/*<       if(abs(ze(upn)-ze(dnn)).gt.0.005)then >*/
    if ((feq_gen_r_d_1 = static_cast<double>(enelem_1.ze[upn - 1]) - enelem_1.ze[dnn - 1], dabs(feq_gen_r_d_1)) > (
	    float).005) {
/* SOURCE chkinput.for:1539 */
/*<       write(stdout,64)code,getusn(upn),getusn(dnn) >*/
	feq_gen_io_d__112.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__112);
	do_fio(&feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &upn);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	getusn_(feq_gen_ch_d_5, (ftnlen)5, &dnn);
	s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
	e_wsfe();
/* SOURCE chkinput.for:1540 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chkinput.for:1541 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1543 */
/*<       callchktab(6,stdout,ftpnt,mft,emc(j+4),eflag) >*/
    chktab_(&feq_gen_c_d_6, stdout, ftablea_1.ftpnt, mft, &emc[j + 4], eflag);
/* SOURCE chkinput.for:1547 */
/*<       callchktab(6,stdout,ftpnt,mft,emc(j+5),eflag) >*/
    chktab_(&feq_gen_c_d_6, stdout, ftablea_1.ftpnt, mft, &emc[j + 5], eflag);
/* SOURCE chkinput.for:1551 */
/*<       if(emc(j+6).gt.0)then >*/
    if (emc[j + 6] > 0) {
/* SOURCE chkinput.for:1552 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+6),eflag) >*/
	chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + 6], eflag);
/* SOURCE chkinput.for:1556 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1557 */
/*<       if(emc(j+7).gt.0)then >*/
    if (emc[j + 7] > 0) {
/* SOURCE chkinput.for:1558 */
/*<       callchktab(2,stdout,ftpnt,mft,emc(j+7),eflag) >*/
	chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &emc[j + 7], eflag);
/* SOURCE chkinput.for:1562 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1565 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:1567 */
/*<    15 continue >*/
L15:
/*          Dummy branch. Nothing to check */
/* SOURCE chkinput.for:1569 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:1571 */
/*<  1500 continue >*/
L1500:
/* SOURCE chkinput.for:1572 */
/*<       j=j+emc(code+1) >*/
    j += emc[code + 1];
/* SOURCE chkinput.for:1573 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE chkinput.for:1574 */
/*<  2000 continue >*/
L2000:
/*     MAKE SURE THAT END OCCURRED AT THE CORRECT PLACE. */
/* SOURCE chkinput.for:1578 */
/*<       if(j.ne.ept)then >*/
    if (j != *ept) {
/* SOURCE chkinput.for:1579 */
/*<       write(stdout,56)j,ept >*/
	feq_gen_io_d__113.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__113);
	do_fio(&feq_gen_c_d_1, (char *)&j, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&(*ept), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE chkinput.for:1580 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE chkinput.for:1581 */
/*<       endif >*/
    }
/*     CHECK TO MAKE SURE THAT NODES ASSIGNED RESERVOIR TRIB AREA */
/*     WERE IN FACT RESERVOIR NODES */
/* SOURCE chkinput.for:1585 */
/*<       do6000i=1,nrwta >*/
    feq_gen_i_d_1 = *nrwta;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE chkinput.for:1586 */
/*<       if(rwta(i).gt.0)then >*/
	if (rwta[feq_gen_i_d_] > 0) {
/* SOURCE chkinput.for:1587 */
/*<       write(stdout,55)getusn(rwta(i)) >*/
	    feq_gen_io_d__114.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__114);
	    getusn_(feq_gen_ch_d_3, (ftnlen)5, &rwta[feq_gen_i_d_]);
	    s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	    e_wsfe();
/* SOURCE chkinput.for:1588 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE chkinput.for:1589 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:1590 */
/*<       rwta(i)=abs(rwta(i)) >*/
	rwta[feq_gen_i_d_] = (feq_gen_i_d_2 = rwta[feq_gen_i_d_], abs(feq_gen_i_d_2));
/* SOURCE chkinput.for:1591 */
/*<  6000 continue >*/
/* L6000: */
    }
/* SOURCE chkinput.for:1593 */
/*<       return >*/
    return 0;
/* SOURCE chkinput.for:1594 */
/*<       end >*/
} /* chkex_ */

#undef rtmp
#undef rdum
#undef idum
#undef itab
#undef ftab





/* SOURCE chkinput.for:1598 */
/*<       subroutinechkgeo(stdout,nbra,brpt) >*/
/* Subroutine */ int chkgeo_(integer *stdout, integer *nbra, integer *feq_storage_brpt)
{
    /* Initialized data */

    static real frvec[2] = { (float).1,(float).25 };
    static real stdy[12] = { (float).5,(float)1.,(float)2.,(float)4.,(float)
	    8.,(float)12.,(float)16.,(float)20.,(float)24.,(float)30.,(float)
	    40.,(float)50. };

    /* Format strings */
    static char fmt_50[] = "(\002 CHECKING GEOMETRY FOR BRANCH:\002,i5)";
    static char fmt_52[] = "(\002   RESULTS FOR COMPUTATIONAL ELEMENT ENDING\
 AT NODE:\002,i5)";
    static char fmt_54[] = "(\002   DEPTH TRATIO ARATIO KRATIO ASLOPE   EL10\
    C10\002,\002   EL25    C25\002)";
    static char fmt_56[] = "(f8.3,8a7)";
    static char fmt_58[] = "(/,\002 CHECK OF GEOMETRY COMPLETE.  PLEASE MAKE\
 CHANGES\002,\002 BEFORE ATTEMPTING\002,/,\002 EXECUTION OF FEQ.\002)";
    static char fmt_60[] = "(\002 BOTTOM SLOPE=\002,f10.4,\002  ELEMENT LENG\
TH=\002,f10.1)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3;
    real feq_gen_r_d_1, feq_gen_r_d_2;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_wsfi(icilist *), e_wsfi();
    double sqrt(doublereal);

    /* Local variables */
    real feq_gen_c_d_, f;
    integer feq_gen_i_d_, n;
    real q, y[1000], de, df, al, bl;
    char el[7*2];
    real ar;
    integer fn;
    real br, kl, fr;
    integer ln;
    real dv, dx, dy, kr, tl, vl, yl, tr, vr, yr, yt, dbl, dbr, dkl;
    integer ifr;
    real dkr, dtl, dtr;
    integer knt, ibra;
    char cvec[7*2];
    integer ioff, node;
    char arat[7], aslp[7], krat[7], trat[7];
    integer eflag, iflag;
    extern /* Subroutine */ int merge_(integer *, integer *, integer *, 
	    integer *, integer *, real *), xlkt20_(integer *, real *, real *, 
	    real *, real *, real *, real *, real *, real *);
    real aratio, aslope, kratio, tratio;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__121 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__123 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__125 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__126 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__130 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__153 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__154 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__155 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__159 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__161 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__162 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__170 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__179 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__180 = { 0, 0, 0, fmt_58, 0 };


/*     + + + PURPOSE + + + */
/*     Check for anomolous features in the stream channel geometry */
/*     subroutine does not return.  selected only at user option */
/* SOURCE chkinput.for:1605 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE chkinput.for:1607 */
/*<       integerstdout,nbra >*/
/* SOURCE chkinput.for:1608 */
/*<       integerbrpt(8,nbra) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     NBRA   - number of branches in the model */
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
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE chkinput.for:1625 */
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
/* INCLUDE chkinput.for:1626 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE chkinput.for:1627 */
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
/* INCLUDE chkinput.for:1628 */
/* ********************************************************************** */
/* SOURCE grav.cmn:2 */
/*<       realgrav,twog,halfg >*/
/* SOURCE grav.cmn:4 */
/*<       common/gravcm/grav,twog,halfg >*/
/* SOURCE grav.cmn:5 */
/*<       save/gravcm/ >*/
/* ********************************************************************** */
/*     + + + SAVED VALUES + + + */
/* SOURCE chkinput.for:1631 */
/*<       realfrvec(2),stdy(12) >*/
/* SOURCE chkinput.for:1632 */
/*<       savefrvec,stdy >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE chkinput.for:1635 */
/*<       integereflag,fn,i,ibra,iflag,ifr,ioff,knt,ln,n,node >*/
/* SOURCE chkinput.for:1636 */
/*<        >*/
/* SOURCE chkinput.for:1639 */
/*<       characterarat*7,aslp*7,cvec(2)*7,el(2)*7,krat*7,trat*7 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE chkinput.for:1642 */
/*<       intrinsicabs,sqrt >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE chkinput.for:1645 */
/*<       externalmerge,xlkt20 >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE chkinput.for:1648 */
/*<        >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    /* Function Body */
/* SOURCE chkinput.for:1652 */
/*<    50 format(' CHECKING GEOMETRY FOR BRANCH:',i5) >*/
/* L50: */
/* SOURCE chkinput.for:1653 */
/*<    52 format('   RESULTS FOR COMPUTATIONAL ELEMENT ENDING AT NODE:',i5) >*/
/* L52: */
/* SOURCE chkinput.for:1654 */
/*<    54  >*/
/* L54: */
/* SOURCE chkinput.for:1656 */
/*<    56 format(f8.3,8a7) >*/
/* L56: */
/* SOURCE chkinput.for:1657 */
/*<    58  >*/
/* L58: */
/* SOURCE chkinput.for:1659 */
/*<    60 format(' BOTTOM SLOPE=',f10.4,'  ELEMENT LENGTH=',f10.1) >*/
/* L60: */
/* *********************************************************************** */
/*     SCAN EACH BRANCHES ELEMENTS AND REPORT ANY OUT OF RANGE CONDITIONS */
/* SOURCE chkinput.for:1663 */
/*<       do1000ibra=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (ibra = 1; ibra <= feq_gen_i_d_1; ++ibra) {
/* SOURCE chkinput.for:1664 */
/*<       fn=brpt(3,ibra) >*/
	fn = brpt[(ibra << 3) + 3];
/* SOURCE chkinput.for:1665 */
/*<       ln=brpt(4,ibra) >*/
	ln = brpt[(ibra << 3) + 4];
/* SOURCE chkinput.for:1666 */
/*<       ioff=brpt(1,ibra)-fn >*/
	ioff = brpt[(ibra << 3) + 1] - fn;
/* SOURCE chkinput.for:1668 */
/*<       write(stdout,50)ibra >*/
	feq_gen_io_d__121.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__121);
	do_fio(&feq_gen_c_d_1, (char *)&ibra, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE chkinput.for:1670 */
/*<       do900node=fn+1,ln >*/
	feq_gen_i_d_2 = ln;
	for (node = fn + 1; node <= feq_gen_i_d_2; ++node) {
/* SOURCE chkinput.for:1671 */
/*<       write(stdout,52)node+ioff >*/
	    feq_gen_io_d__123.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__123);
	    feq_gen_i_d_3 = node + ioff;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_3, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE chkinput.for:1672 */
/*<       dx=abs(xvec(node)-xvec(node-1)) >*/
	    dx = (feq_gen_r_d_1 = static_cast<double>(bnelem_1.xvec[node - 1]) - bnelem_1.xvec[node - 2], 
		    dabs(feq_gen_r_d_1));
/* SOURCE chkinput.for:1673 */
/*<       if(dx.eq.0.0)then >*/
	    if (dx == (float)0.) {
/* SOURCE chkinput.for:1674 */
/*<       write(stdout,*)' *ERR:61* Element length is zero' >*/
		feq_gen_io_d__125.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__125);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:61* Element length is zero"), (
			ftnlen)32);
		e_wsle();
/* SOURCE chkinput.for:1675 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE chkinput.for:1676 */
/*<       endif >*/
	    }
/* SOURCE chkinput.for:1677 */
/*<       write(stdout,60)(zvec(node-1)-zvec(node))/dx,dx >*/
	    feq_gen_io_d__126.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__126);
	    feq_gen_r_d_1 = static_cast<double>((static_cast<double>(bnelem_1.zvec[node - 2]) - bnelem_1.zvec[node - 1])) / dx;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&dx, (ftnlen)sizeof(real));
	    e_wsfe();
/*         FIND LIST OF UNIQUE DEPTHS FOR THE TWO TABLES */
/* SOURCE chkinput.for:1681 */
/*<       callmerge(stdout,nsec(node-1),nsec(node),eflag,n,y) >*/
	    merge_(stdout, &bnothr_1.nsec[node - 2], &bnothr_1.nsec[node - 1],
		     &eflag, &n, y);
/* SOURCE chkinput.for:1687 */
/*<       write(stdout,54) >*/
	    feq_gen_io_d__130.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__130);
	    e_wsfe();
/* SOURCE chkinput.for:1689 */
/*<       do800i=1,12 >*/
	    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 12; ++feq_gen_i_d_) {
/* SOURCE chkinput.for:1690 */
/*<       yl=stdy(i) >*/
		yl = stdy[feq_gen_i_d_ - 1];
/* SOURCE chkinput.for:1691 */
/*<       if(yl.gt.y(n))goto801 >*/
		if (yl > y[n - 1]) {
		    goto L801;
		}
/* SOURCE chkinput.for:1692 */
/*<       callxlkt20(nsec(node-1),yl,al,tl,dtl,kl,dkl,bl,dbl) >*/
		xlkt20_(&bnothr_1.nsec[node - 2], &yl, &al, &tl, &dtl, &kl, &
			dkl, &bl, &dbl);
/* SOURCE chkinput.for:1697 */
/*<       yr=yl >*/
		yr = yl;
/* SOURCE chkinput.for:1698 */
/*<       callxlkt20(nsec(node),yr,ar,tr,dtr,kr,dkr,br,dbr) >*/
		xlkt20_(&bnothr_1.nsec[node - 1], &yr, &ar, &tr, &dtr, &kr, &
			dkr, &br, &dbr);
/*           MAKE RATIO AND SLOPE TESTS */
/*           ONLY THOSE VALUES OUT OF RANGE ARE PRINTED */
/* SOURCE chkinput.for:1708 */
/*<       trat=' ' >*/
		s_copy(trat, const_cast<char*>(" "), (ftnlen)7, (ftnlen)1);
/* SOURCE chkinput.for:1709 */
/*<       arat=' ' >*/
		s_copy(arat, const_cast<char*>(" "), (ftnlen)7, (ftnlen)1);
/* SOURCE chkinput.for:1710 */
/*<       krat=' ' >*/
		s_copy(krat, const_cast<char*>(" "), (ftnlen)7, (ftnlen)1);
/*            TSLP = ' ' */
/* SOURCE chkinput.for:1712 */
/*<       aslp=' ' >*/
		s_copy(aslp, const_cast<char*>(" "), (ftnlen)7, (ftnlen)1);
/*            KSLP = ' ' */
/* SOURCE chkinput.for:1715 */
/*<       iflag=0 >*/
		iflag = 0;
/* SOURCE chkinput.for:1717 */
/*<       if(tl.eq.0.0)then >*/
		if (tl == (float)0.) {
/* SOURCE chkinput.for:1718 */
/*<       write(stdout,*)' *BUG:28* TL = 0' >*/
		    feq_gen_io_d__153.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__153);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:28* TL = 0"), (ftnlen)16);
		    e_wsle();
/* SOURCE chkinput.for:1719 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE chkinput.for:1720 */
/*<       endif >*/
		}
/* SOURCE chkinput.for:1721 */
/*<       if(al.eq.0.0)then >*/
		if (al == (float)0.) {
/* SOURCE chkinput.for:1722 */
/*<       write(stdout,*)' *BUG:29* AL = 0' >*/
		    feq_gen_io_d__154.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__154);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:29* AL = 0"), (ftnlen)16);
		    e_wsle();
/* SOURCE chkinput.for:1723 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE chkinput.for:1724 */
/*<       endif >*/
		}
/* SOURCE chkinput.for:1725 */
/*<       if(kl.eq.0.0)then >*/
		if (kl == (float)0.) {
/* SOURCE chkinput.for:1726 */
/*<       write(stdout,*)' *BUG:30* KL = 0' >*/
		    feq_gen_io_d__155.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__155);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:30* KL = 0"), (ftnlen)16);
		    e_wsle();
/* SOURCE chkinput.for:1727 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE chkinput.for:1728 */
/*<       endif >*/
		}
/* SOURCE chkinput.for:1729 */
/*<       tratio=tr/tl >*/
		tratio = static_cast<double>(tr) / tl;
/* SOURCE chkinput.for:1730 */
/*<       aratio=ar/al >*/
		aratio = static_cast<double>(ar) / al;
/* SOURCE chkinput.for:1731 */
/*<       kratio=kr/kl >*/
		kratio = static_cast<double>(kr) / kl;
/* SOURCE chkinput.for:1734 */
/*<       if(yl.eq.0.0)then >*/
		if (yl == (float)0.) {
/* SOURCE chkinput.for:1735 */
/*<       write(stdout,*)' *BUG:31* YL = 0' >*/
		    feq_gen_io_d__159.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__159);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:31* YL = 0"), (ftnlen)16);
		    e_wsle();
/* SOURCE chkinput.for:1736 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE chkinput.for:1737 */
/*<       endif >*/
		}
/*            TSLOPE = (TR - TL)/DX */
/* SOURCE chkinput.for:1739 */
/*<       aslope=(ar-al)/(dx*yl) >*/
		aslope = static_cast<double>((static_cast<double>(ar) - al)) / (static_cast<double>(dx) * yl);
/* SOURCE chkinput.for:1741 */
/*<       write(trat,'(F7.2)')tratio >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 7;
		feq_gen_ici_d_1.iciunit = trat;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(F7.2)");
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&tratio, (ftnlen)sizeof(real));
		e_wsfi();
/* SOURCE chkinput.for:1742 */
/*<       if(tratio.lt.0.5.or.tratio.gt.2.0)then >*/
		if (tratio < (float).5 || tratio > (float)2.) {
/* SOURCE chkinput.for:1743 */
/*<       iflag=1 >*/
		    iflag = 1;
/* SOURCE chkinput.for:1744 */
/*<       endif >*/
		}
/* SOURCE chkinput.for:1745 */
/*<       write(arat,'(F7.2)')aratio >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 7;
		feq_gen_ici_d_1.iciunit = arat;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(F7.2)");
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&aratio, (ftnlen)sizeof(real));
		e_wsfi();
/* SOURCE chkinput.for:1746 */
/*<       if(aratio.lt.0.5.or.aratio.gt.2.0)then >*/
		if (aratio < (float).5 || aratio > (float)2.) {
/* SOURCE chkinput.for:1747 */
/*<       iflag=1 >*/
		    iflag = 1;
/* SOURCE chkinput.for:1748 */
/*<       endif >*/
		}
/* SOURCE chkinput.for:1749 */
/*<       write(krat,'(F7.2)')kratio >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 7;
		feq_gen_ici_d_1.iciunit = krat;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(F7.2)");
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&kratio, (ftnlen)sizeof(real));
		e_wsfi();
/* SOURCE chkinput.for:1750 */
/*<       if(kratio.lt.0.5.or.kratio.gt.2.0)then >*/
		if (kratio < (float).5 || kratio > (float)2.) {
/* SOURCE chkinput.for:1751 */
/*<       iflag=1 >*/
		    iflag = 1;
/* SOURCE chkinput.for:1752 */
/*<       endif >*/
		}
/*            WRITE(TSLP,'(F7.2)') TSLOPE */
/*            IF(TSLOPE.LT.-0.60.OR.TSLOPE.GT.0.30) THEN */
/*              IFLAG = 1 */
/*            ENDIF */
/* SOURCE chkinput.for:1758 */
/*<       write(aslp,'(F7.2)')aslope >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 7;
		feq_gen_ici_d_1.iciunit = aslp;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(F7.2)");
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&aslope, (ftnlen)sizeof(real));
		e_wsfi();
/* SOURCE chkinput.for:1759 */
/*<       if(aslope.lt.-0.30.or.aslope.gt.0.30)then >*/
		if (aslope < (float)-.3 || aslope > (float).3) {
/* SOURCE chkinput.for:1760 */
/*<       iflag=1 >*/
		    iflag = 1;
/* SOURCE chkinput.for:1761 */
/*<       endif >*/
		}
/* SOURCE chkinput.for:1763 */
/*<       if(iflag.eq.0)goto800 >*/
		if (iflag == 0) {
		    goto L800;
		}
/*           COMPUTE THE MODEL STEADY FLOW MOMENTUM BALANCE ASSUMING */
/*           HORIZONTAL FLOW AND ZERO BOUNDARY SHEAR */
/* SOURCE chkinput.for:1767 */
/*<       if(ar.eq.0.0)then >*/
		if (ar == (float)0.) {
/* SOURCE chkinput.for:1768 */
/*<       write(stdout,*)' *BUG:32* AR = 0' >*/
		    feq_gen_io_d__161.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__161);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:32* AR = 0"), (ftnlen)16);
		    e_wsle();
/* SOURCE chkinput.for:1769 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE chkinput.for:1770 */
/*<       endif >*/
		}
/* SOURCE chkinput.for:1771 */
/*<       if(tr.eq.0.0)then >*/
		if (tr == (float)0.) {
/* SOURCE chkinput.for:1772 */
/*<       write(stdout,*)' *BUG:33* TR = 0' >*/
		    feq_gen_io_d__162.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__162);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:33* TR = 0"), (ftnlen)16);
		    e_wsle();
/* SOURCE chkinput.for:1773 */
/*<       stop'Abnormal stop: errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE chkinput.for:1774 */
/*<       endif >*/
		}
/* SOURCE chkinput.for:1775 */
/*<       do700ifr=1,2 >*/
		for (ifr = 1; ifr <= 2; ++ifr) {
/* SOURCE chkinput.for:1776 */
/*<       fr=frvec(ifr) >*/
		    fr = frvec[ifr - 1];
/* SOURCE chkinput.for:1777 */
/*<       q=fr*ar*sqrt(grav*ar/tr) >*/
		    q = static_cast<double>(fr) * ar * sqrt(static_cast<double>(static_cast<double>(gravcm_1.grav) * ar) / tr);
/*              WRITE(STDOUT,*) 'Q=',Q */
/*             SOLVE FOR YL GIVEN THE CONDITIONS AT R */
/* SOURCE chkinput.for:1782 */
/*<       knt=0 >*/
		    knt = 0;
/* SOURCE chkinput.for:1783 */
/*<   600 continue >*/
L600:
/* SOURCE chkinput.for:1784 */
/*<       vl=q/al >*/
		    vl = static_cast<double>(q) / al;
/* SOURCE chkinput.for:1785 */
/*<       f=vl*q-q**2/ar+0.5*grav*(yl-yr)*(al+ar) >*/
/* Computing 2nd power */
		    feq_gen_r_d_1 = q;
		    f = static_cast<double>(static_cast<double>(static_cast<double>(vl) * q) - static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / ar) + static_cast<double>(static_cast<double>(static_cast<double>(gravcm_1.grav) * (float).5) 
			    * (static_cast<double>(yl) - yr)) * (static_cast<double>(al) + ar);
/* SOURCE chkinput.for:1787 */
/*<       df=(-tl)*vl**2+0.5*grav*(al+ar+(yl-yr)*tl) >*/
/* Computing 2nd power */
		    feq_gen_r_d_1 = vl;
		    df = static_cast<double>(static_cast<double>(-tl) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) + static_cast<double>(static_cast<double>(gravcm_1.grav) * (float).5) * (
			    static_cast<double>(static_cast<double>(al) + ar) + static_cast<double>((static_cast<double>(yl) - yr)) * tl);
/* SOURCE chkinput.for:1790 */
/*<       if(df.eq.0.0)then >*/
		    if (df == (float)0.) {
/* SOURCE chkinput.for:1791 */
/*<       write(stdout,*)'*WRN:25* DF = 0.0 IN CHKGEO' >*/
			feq_gen_io_d__170.ciunit = *stdout;
			s_wsle(&feq_gen_io_d__170);
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("*WRN:25* DF = 0.0 IN CHKGEO"), (
				ftnlen)27);
			e_wsle();
/* SOURCE chkinput.for:1792 */
/*<       df=1.0 >*/
			df = (float)1.;
/* SOURCE chkinput.for:1793 */
/*<       endif >*/
		    }
/*                WRITE(STDOUT,'(3F15.4)') YL, F, DF */
/* SOURCE chkinput.for:1796 */
/*<       knt=knt+1 >*/
		    ++knt;
/* SOURCE chkinput.for:1797 */
/*<       if(knt.gt.10)then >*/
		    if (knt > 10) {
/* SOURCE chkinput.for:1798 */
/*<       cvec(ifr)='   *   ' >*/
			s_copy(cvec + (ifr - 1) * 7, const_cast<char*>("   *   "), (ftnlen)7, (
				ftnlen)7);
/* SOURCE chkinput.for:1799 */
/*<       el(ifr)='   *   ' >*/
			s_copy(el + (ifr - 1) * 7, const_cast<char*>("   *   "), (ftnlen)7, (
				ftnlen)7);
/* SOURCE chkinput.for:1800 */
/*<       goto700 >*/
			goto L700;
/* SOURCE chkinput.for:1801 */
/*<       endif >*/
		    }
/* SOURCE chkinput.for:1803 */
/*<       dy=f/df >*/
		    dy = static_cast<double>(f) / df;
/* SOURCE chkinput.for:1804 */
/*<       yt=yl-dy >*/
		    yt = static_cast<double>(yl) - dy;
/* SOURCE chkinput.for:1805 */
/*<       if(yt.le.0.0)then >*/
		    if (yt <= (float)0.) {
/* SOURCE chkinput.for:1806 */
/*<       yl=0.5*yl >*/
			yl *= static_cast<double>((float).5);
/* SOURCE chkinput.for:1807 */
/*<       goto600 >*/
			goto L600;
/* SOURCE chkinput.for:1808 */
/*<       endif >*/
		    }
/* SOURCE chkinput.for:1810 */
/*<       yl=yt >*/
		    yl = yt;
/* SOURCE chkinput.for:1811 */
/*<       if(yl.gt.y(n))yl=y(n) >*/
		    if (yl > y[n - 1]) {
			yl = y[n - 1];
		    }
/* SOURCE chkinput.for:1813 */
/*<       callxlkt20(nsec(node-1),yl,al,tl,dtl,kl,dkl,bl,dbl) >*/
		    xlkt20_(&bnothr_1.nsec[node - 2], &yl, &al, &tl, &dtl, &
			    kl, &dkl, &bl, &dbl);
/* SOURCE chkinput.for:1818 */
/*<       if(abs(dy).gt.0.0002)goto600 >*/
		    if (dabs(dy) > (float)2e-4) {
			goto L600;
		    }
/*             SOLUTION HERE */
/* SOURCE chkinput.for:1822 */
/*<       vl=q/al >*/
		    vl = static_cast<double>(q) / al;
/* SOURCE chkinput.for:1823 */
/*<       vr=q/ar >*/
		    vr = static_cast<double>(q) / ar;
/* SOURCE chkinput.for:1824 */
/*<       de=yl+vl**2/twog-yr-vr**2/twog >*/
/* Computing 2nd power */
		    feq_gen_r_d_1 = vl;
/* Computing 2nd power */
		    feq_gen_r_d_2 = vr;
		    de = static_cast<double>(static_cast<double>(static_cast<double>(yl) + static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / gravcm_1.twog) - yr) - static_cast<double>(static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2) /
			     gravcm_1.twog;
/* SOURCE chkinput.for:1825 */
/*<       if(aslope.gt.0.0)then >*/
		    if (aslope > (float)0.) {
/* SOURCE chkinput.for:1826 */
/*<       dv=vl-vr >*/
			dv = static_cast<double>(vl) - vr;
/* SOURCE chkinput.for:1827 */
/*<       if(dv.lt.0.01)then >*/
			if (dv < (float).01) {
/* SOURCE chkinput.for:1828 */
/*<       c=0.0 >*/
			    feq_gen_c_d_ = (float)0.;
/* SOURCE chkinput.for:1829 */
/*<       else >*/
			} else {
/* SOURCE chkinput.for:1830 */
/*<       c=twog*de/dv**2 >*/
/* Computing 2nd power */
			    feq_gen_r_d_1 = dv;
			    feq_gen_c_d_ = static_cast<double>(static_cast<double>(gravcm_1.twog) * de) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE chkinput.for:1831 */
/*<       endif >*/
			}
/* SOURCE chkinput.for:1832 */
/*<       else >*/
		    } else {
/* SOURCE chkinput.for:1833 */
/*<       c=twog*de/vr**2 >*/
/* Computing 2nd power */
			feq_gen_r_d_1 = vr;
			feq_gen_c_d_ = static_cast<double>(static_cast<double>(gravcm_1.twog) * de) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE chkinput.for:1834 */
/*<       endif >*/
		    }
/* SOURCE chkinput.for:1835 */
/*<       write(cvec(ifr),'(F7.2)')c >*/
		    feq_gen_ici_d_1.icierr = 0;
		    feq_gen_ici_d_1.icirnum = 1;
		    feq_gen_ici_d_1.icirlen = 7;
		    feq_gen_ici_d_1.iciunit = cvec + (ifr - 1) * 7;
		    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F7.2)");
		    s_wsfi(&feq_gen_ici_d_1);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_, (ftnlen)sizeof(real));
		    e_wsfi();
/* SOURCE chkinput.for:1836 */
/*<       write(el(ifr),'(F7.4)')de >*/
		    feq_gen_ici_d_1.icierr = 0;
		    feq_gen_ici_d_1.icirnum = 1;
		    feq_gen_ici_d_1.icirlen = 7;
		    feq_gen_ici_d_1.iciunit = el + (ifr - 1) * 7;
		    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F7.4)");
		    s_wsfi(&feq_gen_ici_d_1);
		    do_fio(&feq_gen_c_d_1, (char *)&de, (ftnlen)sizeof(real));
		    e_wsfi();
/* SOURCE chkinput.for:1837 */
/*<   700 continue >*/
L700:
		    ;
		}
/* SOURCE chkinput.for:1839 */
/*<       if(iflag.gt.0)then >*/
		if (iflag > 0) {
/* SOURCE chkinput.for:1840 */
/*<       write(stdout,56)yr,trat,arat,krat,aslp,el(1),cvec(1),el(2),cvec(2) >*/
		    feq_gen_io_d__179.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__179);
		    do_fio(&feq_gen_c_d_1, (char *)&yr, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, trat, (ftnlen)7);
		    do_fio(&feq_gen_c_d_1, arat, (ftnlen)7);
		    do_fio(&feq_gen_c_d_1, krat, (ftnlen)7);
		    do_fio(&feq_gen_c_d_1, aslp, (ftnlen)7);
		    do_fio(&feq_gen_c_d_1, el, (ftnlen)7);
		    do_fio(&feq_gen_c_d_1, cvec, (ftnlen)7);
		    do_fio(&feq_gen_c_d_1, el + 7, (ftnlen)7);
		    do_fio(&feq_gen_c_d_1, cvec + 7, (ftnlen)7);
		    e_wsfe();
/* SOURCE chkinput.for:1842 */
/*<       endif >*/
		}
/* SOURCE chkinput.for:1844 */
/*<   800 continue >*/
L800:
		;
	    }
/* SOURCE chkinput.for:1845 */
/*<   801 continue >*/
L801:
/* SOURCE chkinput.for:1846 */
/*<   900 continue >*/
/* L900: */
	    ;
	}
/* SOURCE chkinput.for:1847 */
/*<  1000 continue >*/
/* L1000: */
    }
/* SOURCE chkinput.for:1849 */
/*<       write(stdout,58) >*/
    feq_gen_io_d__180.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__180);
    e_wsfe();
/* SOURCE chkinput.for:1850 */
/*<       stop'Normal stop in CHKGEO' >*/
    s_stop(const_cast<char*>("Normal stop in CHKGEO"), (ftnlen)21);
/* SOURCE chkinput.for:1851 */
/*<       end >*/
    return 0;
} /* chkgeo_ */




/* SOURCE chkinput.for:1855 */
/*<       subroutinechkic(stdout,nbra,brpt) >*/
/* Subroutine */ int chkic_(integer *stdout, integer *nbra, integer *feq_storage_brpt)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 Intial Condition Discrepancies\002)";
    static char fmt_52[] = "(\002  BRA  NODE TYPE   DZ from   DZ from   DX f\
rom   DX from\002)";
    static char fmt_54[] = "(16x,5x,\002Input   IC file\002,5x,\002Input   I\
C file\002)";
    static char fmt_56[] = "(1x,i4,1x,i5,a5,2f10.3,2f10.1)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer ie, is;
    real dx, dz;
    integer ibra, node, usbr;
    char feq_gen_type_d_[5];
    integer inode, error;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__189 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__190 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__191 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__194 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__195 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__196 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__197 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__198 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__199 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__200 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__201 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__202 = { 0, 0, 0, fmt_56, 0 };


/*     + + + PURPOSE + + + */
/*     Check for agreement between the bottom profile and stationing */
/*     stored in the initial conditions file and from the user input. */
/*     If there is any disagreement terminate the run. */
/* SOURCE chkinput.for:1863 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE chkinput.for:1865 */
/*<       integerstdout,nbra >*/
/* SOURCE chkinput.for:1866 */
/*<       integerbrpt(8,nbra) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     NBRA   - number of branches in the model */
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
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE chkinput.for:1883 */
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
/* INCLUDE chkinput.for:1884 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE chkinput.for:1885 */
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

/*     + + + LOCAL VARIABLES + + + */
/* SOURCE chkinput.for:1888 */
/*<       integererror,ibra,ie,inode,is,node,usbr >*/
/* SOURCE chkinput.for:1889 */
/*<       realdx,dz >*/
/* SOURCE chkinput.for:1890 */
/*<       charactertype*5 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE chkinput.for:1893 */
/*<       intrinsicabs >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE chkinput.for:1896 */
/*<    50 format(/,' Intial Condition Discrepancies') >*/
/* SOURCE chkinput.for:1897 */
/*<    52 format('  BRA  NODE TYPE   DZ from   DZ from   DX from   DX from') >*/
/* SOURCE chkinput.for:1898 */
/*<    54 format(16x,5x,'Input   IC file',5x,'Input   IC file') >*/
/* SOURCE chkinput.for:1899 */
/*<    56 format(1x,i4,1x,i5,a5,2f10.3,2f10.1) >*/
/* *********************************************************************** */
/* SOURCE chkinput.for:1901 */
/*<       error=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
/* L56: */
    error = 0;
/* SOURCE chkinput.for:1902 */
/*<       do200ibra=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (ibra = 1; ibra <= feq_gen_i_d_1; ++ibra) {
/* SOURCE chkinput.for:1903 */
/*<       usbr=inbrus(ibra) >*/
	usbr = inbr_1.inbrus[ibra - 1];
/* SOURCE chkinput.for:1905 */
/*<       is=brpt(3,ibra) >*/
	is = brpt[(ibra << 3) + 3];
/* SOURCE chkinput.for:1906 */
/*<       ie=brpt(4,ibra) >*/
	ie = brpt[(ibra << 3) + 4];
/* SOURCE chkinput.for:1907 */
/*<       do100inode=is+1,ie >*/
	feq_gen_i_d_2 = ie;
	for (inode = is + 1; inode <= feq_gen_i_d_2; ++inode) {
/* SOURCE chkinput.for:1908 */
/*<       dx=abs(xvec(inode)-xvec(inode-1)) >*/
	    dx = (feq_gen_r_d_1 = static_cast<double>(bnelem_1.xvec[inode - 1]) - bnelem_1.xvec[inode - 2], 
		    dabs(feq_gen_r_d_1));
/* SOURCE chkinput.for:1909 */
/*<       dz=zvec(inode)-zvec(inode-1) >*/
	    dz = static_cast<double>(bnelem_1.zvec[inode - 1]) - bnelem_1.zvec[inode - 2];
/* SOURCE chkinput.for:1911 */
/*<       if(dz.eq.0.0)then >*/
	    if (dz == (float)0.) {
/*           REQUIRE EXACT AGREEMENT FOR ZERO BOTTOM SLOPES */
/* SOURCE chkinput.for:1913 */
/*<       if(dzvec(inode).ne.0.0)then >*/
		if (bnelem_1.dzvec[inode - 1] != (float)0.) {
/* SOURCE chkinput.for:1914 */
/*<       if(error.eq.0)then >*/
		    if (error == 0) {
/*               WRITE HEADINGS */
/* SOURCE chkinput.for:1916 */
/*<       write(stdout,50) >*/
			feq_gen_io_d__189.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__189);
			e_wsfe();
/* SOURCE chkinput.for:1917 */
/*<       write(stdout,52) >*/
			feq_gen_io_d__190.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__190);
			e_wsfe();
/* SOURCE chkinput.for:1918 */
/*<       write(stdout,54) >*/
			feq_gen_io_d__191.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__191);
			e_wsfe();
/* SOURCE chkinput.for:1919 */
/*<       endif >*/
		    }
/* SOURCE chkinput.for:1920 */
/*<       error=1 >*/
		    error = 1;
/* SOURCE chkinput.for:1921 */
/*<       type='   DZ' >*/
		    s_copy(feq_gen_type_d_, const_cast<char*>("   DZ"), (ftnlen)5, (ftnlen)5);
/* SOURCE chkinput.for:1922 */
/*<       node=brpt(1,ibra)+inode-is >*/
		    node = brpt[(ibra << 3) + 1] + inode - is;
/* SOURCE chkinput.for:1923 */
/*<       write(stdout,56)usbr,node,type,dz,dzvec(inode),dx,dxvec(inode) >*/
		    feq_gen_io_d__194.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__194);
		    do_fio(&feq_gen_c_d_1, (char *)&usbr, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, (char *)&node, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, feq_gen_type_d_, (ftnlen)5);
		    do_fio(&feq_gen_c_d_1, (char *)&dz, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&bnelem_1.dzvec[inode - 1], (ftnlen)
			    sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&dx, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&bnelem_1.dxvec[inode - 1], (ftnlen)
			    sizeof(real));
		    e_wsfe();
/* SOURCE chkinput.for:1925 */
/*<       endif >*/
		}
/* SOURCE chkinput.for:1926 */
/*<       else >*/
	    } else {
/* SOURCE chkinput.for:1927 */
/*<       if(abs((dz-dzvec(inode))/dz).gt.0.001)then >*/
		if ((feq_gen_r_d_1 = static_cast<double>((static_cast<double>(dz) - bnelem_1.dzvec[inode - 1])) / dz, dabs(feq_gen_r_d_1))
			 > (float).001) {
/* SOURCE chkinput.for:1928 */
/*<       if(error.eq.0)then >*/
		    if (error == 0) {
/*               WRITE HEADINGS */
/* SOURCE chkinput.for:1930 */
/*<       write(stdout,50) >*/
			feq_gen_io_d__195.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__195);
			e_wsfe();
/* SOURCE chkinput.for:1931 */
/*<       write(stdout,52) >*/
			feq_gen_io_d__196.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__196);
			e_wsfe();
/* SOURCE chkinput.for:1932 */
/*<       write(stdout,54) >*/
			feq_gen_io_d__197.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__197);
			e_wsfe();
/* SOURCE chkinput.for:1933 */
/*<       endif >*/
		    }
/* SOURCE chkinput.for:1934 */
/*<       error=1 >*/
		    error = 1;
/* SOURCE chkinput.for:1935 */
/*<       type='   DZ' >*/
		    s_copy(feq_gen_type_d_, const_cast<char*>("   DZ"), (ftnlen)5, (ftnlen)5);
/* SOURCE chkinput.for:1936 */
/*<       node=brpt(1,ibra)+inode-is >*/
		    node = brpt[(ibra << 3) + 1] + inode - is;
/* SOURCE chkinput.for:1937 */
/*<       write(stdout,56)usbr,node,type,dz,dzvec(inode),dx,dxvec(inode) >*/
		    feq_gen_io_d__198.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__198);
		    do_fio(&feq_gen_c_d_1, (char *)&usbr, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, (char *)&node, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, feq_gen_type_d_, (ftnlen)5);
		    do_fio(&feq_gen_c_d_1, (char *)&dz, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&bnelem_1.dzvec[inode - 1], (ftnlen)
			    sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&dx, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&bnelem_1.dxvec[inode - 1], (ftnlen)
			    sizeof(real));
		    e_wsfe();
/* SOURCE chkinput.for:1939 */
/*<       endif >*/
		}
/* SOURCE chkinput.for:1940 */
/*<       endif >*/
	    }
/* SOURCE chkinput.for:1942 */
/*<       if(abs(dx-dxvec(inode))/dx.gt.0.001)then >*/
	    if ((feq_gen_r_d_1 = static_cast<double>(dx) - bnelem_1.dxvec[inode - 1], dabs(feq_gen_r_d_1)) / dx > (
		    float).001) {
/* SOURCE chkinput.for:1943 */
/*<       if(error.eq.0)then >*/
		if (error == 0) {
/*             WRITE HEADINGS */
/* SOURCE chkinput.for:1945 */
/*<       write(stdout,50) >*/
		    feq_gen_io_d__199.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__199);
		    e_wsfe();
/* SOURCE chkinput.for:1946 */
/*<       write(stdout,52) >*/
		    feq_gen_io_d__200.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__200);
		    e_wsfe();
/* SOURCE chkinput.for:1947 */
/*<       write(stdout,54) >*/
		    feq_gen_io_d__201.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__201);
		    e_wsfe();
/* SOURCE chkinput.for:1948 */
/*<       endif >*/
		}
/* SOURCE chkinput.for:1949 */
/*<       error=1 >*/
		error = 1;
/* SOURCE chkinput.for:1950 */
/*<       type='   DX' >*/
		s_copy(feq_gen_type_d_, const_cast<char*>("   DX"), (ftnlen)5, (ftnlen)5);
/* SOURCE chkinput.for:1951 */
/*<       node=brpt(1,ibra)+inode-is >*/
		node = brpt[(ibra << 3) + 1] + inode - is;
/* SOURCE chkinput.for:1952 */
/*<       write(stdout,56)usbr,node,type,dz,dzvec(inode),dx,dxvec(inode) >*/
		feq_gen_io_d__202.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__202);
		do_fio(&feq_gen_c_d_1, (char *)&usbr, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&node, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, feq_gen_type_d_, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, (char *)&dz, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&bnelem_1.dzvec[inode - 1], (ftnlen)
			sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&dx, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&bnelem_1.dxvec[inode - 1], (ftnlen)
			sizeof(real));
		e_wsfe();
/* SOURCE chkinput.for:1954 */
/*<       endif >*/
	    }
/* SOURCE chkinput.for:1956 */
/*<   100 continue >*/
/* L100: */
	}
/* SOURCE chkinput.for:1957 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE chkinput.for:1959 */
/*<       if(error.eq.1)stop'Abnormal stop: errors found.' >*/
    if (error == 1) {
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
    }
/* SOURCE chkinput.for:1961 */
/*<       return >*/
    return 0;
/* SOURCE chkinput.for:1962 */
/*<       end >*/
} /* chkic_ */




/* SOURCE chkinput.for:1966 */
/*<       subroutinechkmjd(stdout,year,month,eflag) >*/
/* Subroutine */ int chkmjd_(integer *stdout, integer *year, integer *month, 
	integer *eflag)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:130* Month=\002,i5,\002 in date < 1\
 or > 12.\002)";
    static char fmt_52[] = "(/,\002 *ERR:137* Year=\002,i5,\002 too early fo\
r modified julian\002,\002 date computation.\002/,10x,\002 Must be 1859 or l\
ater.\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__203 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__204 = { 0, 0, 0, fmt_52, 0 };


/*     + + + PURPOSE + + + */
/*     Check YEAR and MONTH to make sure that the modified */
/*     julian date  and its inverse will be computed properly. */
/* SOURCE chkinput.for:1974 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE chkinput.for:1976 */
/*<       integereflag,month,stdout,year >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - standard output unit for user messages */
/*     YEAR   - calendar year */
/*     MONTH  - number of the month */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE chkinput.for:1985 */
/*<    50 format(/,' *ERR:130* Month=',i5,' in date < 1 or > 12.') >*/
/* SOURCE chkinput.for:1986 */
/*<    52  >*/
/* *********************************************************************** */
/*     YEAR MUST BE THE FULL YEAR DESIGNATION NOT JUST THE LAST TWO DIGITS. */
/*     On March 10, 1992 changed to be valid for any date on or following */
/*     January 1, 1859. */

/* SOURCE chkinput.for:1993 */
/*<       if(month.lt.1.or.month.gt.12)then >*/
/* L50: */
/* L52: */
    if (*month < 1 || *month > 12) {
/* SOURCE chkinput.for:1994 */
/*<       write(stdout,50)month >*/
	feq_gen_io_d__203.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__203);
	do_fio(&feq_gen_c_d_1, (char *)&(*month), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE chkinput.for:1995 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chkinput.for:1996 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:1998 */
/*<       if(year.lt.1859)then >*/
    if (*year < 1859) {
/* SOURCE chkinput.for:1999 */
/*<       write(stdout,52)year >*/
	feq_gen_io_d__204.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__204);
	do_fio(&feq_gen_c_d_1, (char *)&(*year), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE chkinput.for:2000 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chkinput.for:2001 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:2003 */
/*<       return >*/
    return 0;
/* SOURCE chkinput.for:2004 */
/*<       end >*/
} /* chkmjd_ */




/* SOURCE chkinput.for:2008 */
/*<       subroutinechkpt(stdout,lpnt,mft,ftpnt,pfpnt,eflag) >*/
/* Subroutine */ int chkpt_(integer *stdout, integer *lpnt, integer *mft, 
	integer *feq_storage_ftpnt, integer *feq_storage_pfpnt, integer *eflag)
{
    /* Format strings */
    static char fmt_52[] = "(/,\002*err:118* invalid type=\002,i5,\002 in Po\
int Flow\002,\002 Table\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer feq_gen_i_d_, ftp, itype;
    extern /* Subroutine */ int chktab_(integer *, integer *, integer *, 
	    integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__207 = { 0, 0, 0, fmt_52, 0 };


/*     + + + PURPOSE + + + */
/*     Check for valid point flow information. */
/* SOURCE chkinput.for:2016 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE chkinput.for:2018 */
/*<       integereflag,stdout,lpnt,mft >*/
/* SOURCE chkinput.for:2019 */
/*<       integerftpnt(mft),pfpnt(3,lpnt) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     LPNT   - length of the point load point load array */
/*     MFT    - maximum function table pointer value.  Same as maximum */
/*               function table number */
/*     FTPNT  - function table pointer giving the table address for each */
/*              table number.  If the address is zero the table does not */
/*              exist. */
/*     PFPNT  - point flow pointer array */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE chkinput.for:2033 */
/*<       integerftp,i,itype >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE chkinput.for:2036 */
/*<       externalchktab >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE chkinput.for:2039 */
/*<    52 format(/,'*err:118* invalid type=',i5,' in Point Flow',' Table') >*/
/* *********************************************************************** */
/* SOURCE chkinput.for:2042 */
/*<       do5000i=1,lpnt >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> pfpnt(feq_storage_pfpnt, 4);

    feq::IndexedPointer<integer> ftpnt(feq_storage_ftpnt, 1);

    /* Function Body */
/* L52: */
    feq_gen_i_d_1 = *lpnt;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE chkinput.for:2043 */
/*<       itype=pfpnt(1,i) >*/
	itype = pfpnt[feq_gen_i_d_ * 3 + 1];
/* SOURCE chkinput.for:2044 */
/*<       if(itype.gt.0.and.itype.lt.3)goto100 >*/
	if (itype > 0 && itype < 3) {
	    goto L100;
	}
/*       INVALID TYPE */
/* SOURCE chkinput.for:2048 */
/*<       write(stdout,52)itype >*/
	feq_gen_io_d__207.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__207);
	do_fio(&feq_gen_c_d_1, (char *)&itype, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE chkinput.for:2049 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chkinput.for:2050 */
/*<       pfpnt(1,i)=1 >*/
	pfpnt[feq_gen_i_d_ * 3 + 1] = 1;
/* SOURCE chkinput.for:2051 */
/*<   100 continue >*/
L100:
/*       CHECK TABLE NUMBER */
/* SOURCE chkinput.for:2055 */
/*<       ftp=pfpnt(2,i) >*/
	ftp = pfpnt[feq_gen_i_d_ * 3 + 2];
/* SOURCE chkinput.for:2057 */
/*<       callchktab(2,stdout,ftpnt,mft,ftp,eflag) >*/
	chktab_(&feq_gen_c_d_2, stdout, &ftpnt[1], mft, &ftp, eflag);
/*       STORE DIRECT ADDRESS */
/* SOURCE chkinput.for:2064 */
/*<       pfpnt(2,i)=ftp >*/
	pfpnt[feq_gen_i_d_ * 3 + 2] = ftp;
/* SOURCE chkinput.for:2065 */
/*<  5000 continue >*/
/* L5000: */
    }
/* SOURCE chkinput.for:2066 */
/*<       return >*/
    return 0;
/* SOURCE chkinput.for:2067 */
/*<       end >*/
} /* chkpt_ */

/*     *********** */
/*     *         * */
/*     * CHKSPOUT* */
/*     *         * */
/*     *********** */
/* SOURCE chkinput.for:2076 */
/*<       subroutinechkspout(stdout,nout,mft,ftpnt,eflag) >*/
/* Subroutine */ int chkspout_(integer *stdout, integer *nout, integer *mft, 
	integer *feq_storage_ftpnt, integer *eflag)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_, ftp;
    extern /* Subroutine */ int chktab_(integer *, integer *, integer *, 
	    integer *, integer *, integer *);

/*     Check table numbers and existence of tables for the */
/*     main channel definition in Special Output. */
/* SOURCE chkinput.for:2081 */
/*<       implicitnone >*/
/* SOURCE chkinput.for:2082 */
/*<       integereflag,mft,ftpnt(mft),nout,stdout >*/
/* INCLUDE chkinput.for:2084 */
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
/* INCLUDE chkinput.for:2085 */
/*     Common block for extending the special output options */
/* SOURCE spout.cmn:3 */
/*<        >*/
/* SOURCE spout.cmn:8 */
/*<        >*/
/* SOURCE spout.cmn:15 */
/*<        >*/
/* SOURCE spout.cmn:21 */
/*<        >*/
/* SOURCE spout.cmn:25 */
/*<        >*/
/* SOURCE spout.cmn:29 */
/*<       common/spoutc/spout_item_label,spout_item_name,extra_buffer >*/
/* SOURCE spout.cmn:33 */
/*<       save/spouta/,/spoutc/ >*/
/*     Local */
/* SOURCE chkinput.for:2089 */
/*<       integeri,ftp >*/
/* *********************************************************************** */
/* SOURCE chkinput.for:2092 */
/*<       do100i=1,nout >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> ftpnt(feq_storage_ftpnt, 1);

    /* Function Body */
    feq_gen_i_d_1 = *nout;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE chkinput.for:2094 */
/*<       ftp=spout_main_channel_table(i) >*/
	ftp = spouta_1.feq_gen_spout_main_channel_table_d_[feq_gen_i_d_ - 1];
/* SOURCE chkinput.for:2095 */
/*<       if(ftp.gt.0)then >*/
	if (ftp > 0) {
/*         Assume that minimum cross section table will work in most */
/*         cases.  If user requests an item in the OPTIONS list that */
/*         is not in the table, the run will fail at the first */
/*         special output with an error message about the table. */
/* SOURCE chkinput.for:2100 */
/*<       callchktab(20,stdout,ftpnt,mft,ftp,eflag) >*/
	    chktab_(&feq_gen_c_d_20, stdout, &ftpnt[1], mft, &ftp, eflag);
/*         STORE THE TABLE ADDRESS */
/* SOURCE chkinput.for:2107 */
/*<       spout_main_channel_table(i)=ftp >*/
	    spouta_1.feq_gen_spout_main_channel_table_d_[feq_gen_i_d_ - 1] = ftp;
/* SOURCE chkinput.for:2108 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:2110 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE chkinput.for:2112 */
/*<       return >*/
    return 0;
/* SOURCE chkinput.for:2113 */
/*<       end >*/
} /* chkspout_ */




/* SOURCE chkinput.for:2117 */
/*<       subroutinechktab(ctype,stdout,ftpnt,mft,tab,eflag) >*/
/* Subroutine */ int chktab_(integer *ctype, integer *stdout, integer *feq_storage_ftpnt, 
	integer *mft, integer *tab, integer *eflag)
{
    /* Format strings */
    static char fmt_1[] = "(/,\002 *ERR:81* Table Id = \002,a,\002 does not \
exist.\002)";
    static char fmt_2[] = "(/,\002 *ERR:82* Internal table number = \002,i8\
,\002 too large.\002)";

    /* System generated locals */
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();

    /* Local variables */
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer adrs;
    extern /* Subroutine */ int chktyp_(integer *, integer *, integer *, 
	    integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__211 = { 0, 0, 0, fmt_2, 0 };
    static cilist feq_gen_io_d__213 = { 0, 0, 0, fmt_1, 0 };
    static cilist feq_gen_io_d__214 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Checks for address of table and returns address in place of */
/*     TAB.  Otherwise writes error and sets TAB = 1 on return. */
/*     if TAB = 0 on entry return without doing anything. */
/* SOURCE chkinput.for:2127 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE chkinput.for:2129 */
/*<       integerctype,eflag,stdout,mft,tab >*/
/* SOURCE chkinput.for:2130 */
/*<       integerftpnt(mft) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     CTYPE  - type class number for checking valid table types */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     FTPNT  - function table pointer giving the table address for each */
/*              table number.  If the address is zero the table does not */
/*              exist. */
/*     MFT    - maximum function table pointer value.  Same as maximum */
/*               function table number */
/*     TAB    - table number */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE chkinput.for:2144 */
/*<       integeradrs >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE chkinput.for:2147 */
/*<       character*16get_tabid >*/
/* SOURCE chkinput.for:2148 */
/*<       externalchktyp,get_tabid >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE chkinput.for:2151 */
/*<     1 format(/,' *ERR:81* Table Id = ',a,' does not exist.') >*/
/* SOURCE chkinput.for:2152 */
/*<     2 format(/,' *ERR:82* Internal table number = ',i8,' too large.') >*/
/* *********************************************************************** */
/* SOURCE chkinput.for:2155 */
/*<       if(tab.eq.0)return >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> ftpnt(feq_storage_ftpnt, 1);

    /* Function Body */
/* L1: */
/* L2: */
    if (*tab == 0) {
	return 0;
    }
/*     MAKE SURE TABLE NUMBER IS IN VALID RANGE */
/* SOURCE chkinput.for:2159 */
/*<       if(tab.gt.mft)then >*/
    if (*tab > *mft) {
/* SOURCE chkinput.for:2160 */
/*<       write(stdout,2)get_tabid(tab),mft >*/
	feq_gen_io_d__211.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__211);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, tab);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&(*mft), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE chkinput.for:2161 */
/*<       tab=mft >*/
	*tab = *mft;
/* SOURCE chkinput.for:2162 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE chkinput.for:2163 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:2165 */
/*<       adrs=ftpnt(tab) >*/
    adrs = ftpnt[*tab];
/* SOURCE chkinput.for:2166 */
/*<       if(adrs.le.0)then >*/
    if (adrs <= 0) {
/* SOURCE chkinput.for:2167 */
/*<       write(stdout,1)get_tabid(tab) >*/
	feq_gen_io_d__213.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__213);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, tab);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	e_wsfe();
/* SOURCE chkinput.for:2168 */
/*<       write(stdout,*)' Internal table number=',tab >*/
	feq_gen_io_d__214.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__214);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Internal table number="), (ftnlen)23);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*tab), (ftnlen)sizeof(integer));
	e_wsle();
/* SOURCE chkinput.for:2169 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chkinput.for:2170 */
/*<       tab=1 >*/
	*tab = 1;
/* SOURCE chkinput.for:2171 */
/*<       else >*/
    } else {
/* SOURCE chkinput.for:2172 */
/*<       tab=adrs >*/
	*tab = adrs;
/* SOURCE chkinput.for:2173 */
/*<       callchktyp(stdout,adrs,ctype,eflag) >*/
	chktyp_(stdout, &adrs, ctype, eflag);
/* SOURCE chkinput.for:2176 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:2177 */
/*<       return >*/
    return 0;
/* SOURCE chkinput.for:2178 */
/*<       end >*/
} /* chktab_ */




/* SOURCE chkinput.for:2182 */
/*<       subroutinechkwin(stdout,mft,ftpnt,wintab,eflag) >*/
/* Subroutine */ int chkwin_(integer *stdout, integer *mft, integer *feq_storage_ftpnt, 
	integer *wintab, integer *eflag)
{
    extern /* Subroutine */ int chktab_(integer *, integer *, integer *, 
	    integer *, integer *, integer *);

/*     + + + PURPOSE + + + */
/*     Check table for wind loading. */
/* SOURCE chkinput.for:2190 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE chkinput.for:2192 */
/*<       integereflag,stdout,mft,wintab >*/
/* SOURCE chkinput.for:2193 */
/*<       integerftpnt(mft) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     MFT    - maximum function table pointer value.  Same as maximum */
/*               function table number */
/*     FTPNT  - function table pointer giving the table address for each */
/*              table number.  If the address is zero the table does not */
/*              exist. */
/*     WINTAB - table for the table of wind speed and direction */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE chkinput.for:2206 */
/*<       externalchktab >*/
/* *********************************************************************** */
/* SOURCE chkinput.for:2208 */
/*<       callchktab(11,stdout,ftpnt,mft,wintab,eflag) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> ftpnt(feq_storage_ftpnt, 1);

    /* Function Body */
    chktab_(&feq_gen_c_d_11, stdout, &ftpnt[1], mft, wintab, eflag);
/* SOURCE chkinput.for:2213 */
/*<       return >*/
    return 0;
/* SOURCE chkinput.for:2215 */
/*<       end >*/
} /* chkwin_ */




/* SOURCE chkinput.for:2219 */
/*<        >*/
/* Subroutine */ int finchk_(integer *stdout, integer *nex, integer *feq_storage_exnodt, 
	real *hslot, real *qchop, integer *ept, char *feq_gen_cd14_tab_datum_d_, char *
	feq_gen_cd5t6_tab_datum_d_, integer *feq_storage_emc, ftnlen cd14_tab_datum_len, ftnlen 
	cd5t6_tab_datum_len)
{
    /* Initialized data */

    static doublereal dnull = -3.3e7;
    static integer null = -2147483647;

    /* Format strings */
    static char fmt_50[] = "(/,\002 Starting final check of Network Matrix I\
nstructions\002)";
    static char fmt_51[] = "(/,\002 End of final check of Network Matrix Ins\
tructions\002)";
    static char fmt_52[] = "(/,\002 *WRN:17* Continuity error of\002,f10.1\
,\002 in initial conditions at nodes:\002)";
    static char fmt_53[] = "(10x,a5,\002 \002,a10)";
    static char fmt_54[] = "(/,\002 *WRN:18* WS elev dif btwn\002,\002 node\
 \002,a5,\002 \002,a10,\002 & node \002,a5,\002 \002,a10,\002 :\002,f6.2)";
    static char fmt_56[] = "(\002/, *WRN:19* POSS. FLOW DISCON. AT FULL FLOW\
 AT\002,/,3x,\002 BRIDGE BETWEEN NODES \002,a5,\002 \002,a10,\002 AND \002,a\
5,\002 \002,a10)";
    static char fmt_58[] = "(10x,\002 FREE FLOW LOSS COEF. = \002,f6.3,\002 \
FROM TABLE# = \002,i5,/,3x,\002 FREE FLOW LOSS COEF IMPLIED BY SUBMERGED FLOW\
\002,\002 DISCHARGE COEF. = \002,f6.3)";
    static char fmt_60[] = "(/,\002 *WRN:20* MAX. FLOW AREA FOR BRIDGE AND A\
REA AT MAX.\002,\002 DEPTH\002,/,3x,\002DISAGREE FOR BRIDGE BETWEEN NODES\
\002,/,10x,a5,\002 \002,a10,\002 AND \002,a5,\002 \002,a10)";
    static char fmt_62[] = "(10x,\002MAXIMUM FLOW AREA = \002,f10.1,\002 ARE\
A AT MAXIMUM DEPTH = \002,f10.1)";
    static char fmt_64[] = "(\0020*WRN:21* DISCREPANCY IN MAX. ELEV. OF BRID\
GE OPENING\002,/,\002 FOR BRIDGE BETWEEN NODES \002,a5,\002 \002,a10,\002 AN\
D \002,a5,\002 \002,a10)";
    static char fmt_66[] = "(3x,\002MAX. ELEV. IN NETWORK-MATRIX = \002,f10.\
2,3x,\002MAX ELEV IN TABID \002,a,\002 IS \002,f10.2)";
    static char fmt_68[] = "(3x,\002MAX. ELEV. USED IS\002,f10.2,\002 MAKE I\
NPUT CHANGES\002,\002 IF UNSATISFACTORY\002)";
    static char fmt_70[] = "(3x,\002MAX. AREA USED IS\002,f10.1,\002 MAKE IN\
PUT CHANGE IF\002,\002 UNSATISFACTORY\002)";
    static char fmt_72[] = "(3x,\002 LAST THREE VALUES IN TABLE HAVE BEEN CH\
ANGED TO\002,\002 MATCH LOSS IMPLIED BY SUBMERGED DISCHARGE COEF.\002,/,3x\
,\002 CHECK TABLE FOR POSSIBLE ABRUPT TRANSITION.\002)";
    static char fmt_74[] = "(3x,\002 TABLE NOT CHANGED BECAUSE TABLE TYPE IS\
 NOT 2\002)";
    static char fmt_76[] = "(/,\002 *WRN:22* Flow discontinuity at constant \
flow\002,\002 boundary\002,/,3x,\002 AT NODE \002,a5,\002 \002,a10)";
    static char fmt_80[] = "(/,\002 REVISED VALES ARE:\002,/,6x,\002DEPTH LO\
SS COEF\002)";
    static char fmt_82[] = "(\002 \002,f10.3,f10.4)";
    static char fmt_84[] = "(\002 *WRN:23* FOR BRIDGE BETWEEN NODES \002,a5\
,\002 \002,a10,\002 AND \002,a5,\002 \002,a10,/,3x,\002DOWNSTREAM AREA < MAX\
 BRIDGE AREA.\002,\002 AB/AD=\002,f10.2,/,3x,\002VIOLATES BPR BRIDGE LOSS ME\
THOD\002,\002 ASSUMPTIONS\002)";
    static char fmt_86[] = "(\002 SUBMERGED BRIDGE FLOW WILL BE MIMICKED USI\
NG\002,\002 FREE FLOW RELATIONSHIP\002)";
    static char fmt_88[] = "(/,\002 *WRN:14* Head datum=\002,f10.2,\002 disa\
grees with TABID=\002,a,/,11x,\002having head datum=\002,f10.2)";
    static char fmt_90[] = "(/,\002 *WRN:56* Datums for head in 2-D tables:\
 \002,a,\002 and \002,a,11x,\002 in a Side-weir instruction differ by more t\
han 0.01\002)";
    static char fmt_92[] = "(\002 \002,\002Head datum=\002,f10.3,\002 from t\
able with TabId: \002,a,\002 replaces side-weir-instruction datum=\002,f10.3)"
	    ;

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1, feq_gen_r_d_2;
    char feq_gen_ch_d_1[10], feq_gen_ch_d_2[5], feq_gen_ch_d_3[5], feq_gen_ch_d_4[5], feq_gen_ch_d_5[5], feq_gen_ch_d_6[16], feq_gen_ch_d_7[
	    16], feq_gen_ch_d_8[16], feq_gen_ch_d_9[16];
    static real equiv_2[1];

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(), s_wsle(cilist *), do_lio(integer *, 
	    integer *, char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer i_sign(integer *, integer *), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    doublereal northing;
    real b;
    integer feq_gen_i_d_, j, k, n;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real ab, ad, db, cd;
    integer ii;
    real yb, yd, qn;
    integer dnn;
    real con, rat, pdv;
    integer num, upn;
    real top, sum, cdfl;
    integer code;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer iadr, ioff, ntab;
    real dcon, dtap;
    integer adrs;
    real emax;
#define idum (feq::BitView<integer>(equiv_2, sizeof(equiv_2)))
    real temp, dtop;
#define rdum (equiv_2)
    extern /* Character */ VOID note_(char *, ftnlen, integer *, integer *, 
	    integer *, integer *, integer *);
    real qtmp;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real hbase, abmax;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    real ybtab;
    integer qnode, nqsgn;
    real floss;
    char notea[10];
    integer itype;
    char noteb[10];
    extern /* Subroutine */ int xlkt20_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *);
    extern doublereal gethdd_(integer *);
    real hdatum;
    extern integer gettbn_(integer *);
    integer lstarg, frflow;
    real abssum;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);
    extern /* Subroutine */ int feq_gen_get_east_north_d_(integer *, integer *, 
	    doublereal *, doublereal *), feq_gen_put_east_north_d_(integer *, integer *
	    , doublereal *, doublereal *);
    integer tabadrs;
    doublereal easting;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__222 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__225 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__232 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__234 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__237 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__245 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__249 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__250 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__251 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__253 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__262 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__263 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__264 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__273 = { 0, 0, 0, fmt_84, 0 };
    static cilist feq_gen_io_d__275 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__276 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__279 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__280 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__281 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__282 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__289 = { 0, 0, 0, fmt_88, 0 };
    static cilist feq_gen_io_d__292 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__293 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__294 = { 0, 0, 0, fmt_90, 0 };
    static cilist feq_gen_io_d__295 = { 0, 0, 0, fmt_51, 0 };


/*     + + + PURPOSE + + + */
/*     Checks validity of initial conditions and other information */
/*     which could not be checked earlier.  This is the last check */
/*     before unsteady flow is simulated. */
/* SOURCE chkinput.for:2229 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE chkinput.for:2231 */
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
/* SOURCE chkinput.for:2234 */
/*<       integerept,stdout,nex >*/
/* SOURCE chkinput.for:2235 */
/*<       integeremc(ept),exnodt(9,nex) >*/
/* SOURCE chkinput.for:2236 */
/*<       realhslot,qchop >*/
/* SOURCE chkinput.for:2237 */
/*<       charactercd14_tab_datum*4,cd5t6_tab_datum*4 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
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
/*     HSLOT  - height of bottom slot.  Currently 0.0 always */
/*     QCHOP  - chopping value for output of flow */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE chkinput.for:2261 */
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
/* INCLUDE chkinput.for:2262 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE chkinput.for:2265 */
/*<        >*/
/* SOURCE chkinput.for:2267 */
/*<        >*/
/* SOURCE chkinput.for:2270 */
/*<       real*8easting,northing,dnull >*/
/* SOURCE chkinput.for:2271 */
/*<       characternotea*10,noteb*10 >*/
/*     + + + EQUIVALENCES + + + */
/* SOURCE chkinput.for:2274 */
/*<       equivalence(idum,rdum) >*/
/*     + + + INTRINSICS + + + */
/* SOURCE chkinput.for:2277 */
/*<       intrinsicabs,float,sign >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE chkinput.for:2280 */
/*<       integergettbn >*/
/* SOURCE chkinput.for:2281 */
/*<       realgethdd >*/
/* SOURCE chkinput.for:2282 */
/*<       charactergetusn*5,note*10,get_tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE chkinput.for:2285 */
/*<        >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE chkinput.for:2289 */
/*<       datadnull/-33d6/,null/-2147483647/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* SOURCE chkinput.for:2292 */
/*<    50 format(/,' Starting final check of Network Matrix Instructions') >*/
/* L50: */
/* SOURCE chkinput.for:2293 */
/*<    51 format(/,' End of final check of Network Matrix Instructions') >*/
/* L51: */
/* SOURCE chkinput.for:2294 */
/*<    52  >*/
/* L52: */
/* SOURCE chkinput.for:2296 */
/*<    53 format(10x,a5,' ',a10) >*/
/* L53: */
/* SOURCE chkinput.for:2297 */
/*<    54  >*/
/* L54: */
/* SOURCE chkinput.for:2299 */
/*<    56  >*/
/* L56: */
/* SOURCE chkinput.for:2301 */
/*<    58  >*/
/* L58: */
/* SOURCE chkinput.for:2304 */
/*<    60  >*/
/* L60: */
/* SOURCE chkinput.for:2307 */
/*<    62  >*/
/* L62: */
/* SOURCE chkinput.for:2309 */
/*<    64  >*/
/* L64: */
/* SOURCE chkinput.for:2311 */
/*<    66  >*/
/* L66: */
/* SOURCE chkinput.for:2313 */
/*<    68  >*/
/* L68: */
/* SOURCE chkinput.for:2315 */
/*<    70  >*/
/* L70: */
/* SOURCE chkinput.for:2317 */
/*<    72  >*/
/* L72: */
/* SOURCE chkinput.for:2320 */
/*<    74 format(3x,' TABLE NOT CHANGED BECAUSE TABLE TYPE IS NOT 2') >*/
/* L74: */
/* SOURCE chkinput.for:2321 */
/*<    76  >*/
/* L76: */
/* SOURCE chkinput.for:2323 */
/*<    80 format(/,' REVISED VALES ARE:',/,6x,'DEPTH LOSS COEF') >*/
/* L80: */
/* SOURCE chkinput.for:2324 */
/*<    82 format(' ',f10.3,f10.4) >*/
/* L82: */
/* SOURCE chkinput.for:2325 */
/*<    84  >*/
/* L84: */
/* SOURCE chkinput.for:2329 */
/*<    86  >*/
/* L86: */
/* SOURCE chkinput.for:2331 */
/*<    88  >*/
/* L88: */
/* SOURCE chkinput.for:2333 */
/*<    90  >*/
/* L90: */
/* SOURCE chkinput.for:2335 */
/*<    92  >*/
/* L92: */
/* *********************************************************************** */
/*     START THE LOOP OVER THE instructions */
/* SOURCE chkinput.for:2339 */
/*<       write(stdout,50) >*/
    feq_gen_io_d__222.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__222);
    e_wsfe();
/* SOURCE chkinput.for:2340 */
/*<       j=emc(1) >*/
    j = emc[1];
/* SOURCE chkinput.for:2341 */
/*<  1000 continue >*/
L1000:
/* SOURCE chkinput.for:2342 */
/*<       code=emc(j) >*/
    code = emc[j];
/* SOURCE chkinput.for:2343 */
/*<       if(code.eq.-1)goto2000 >*/
    if (code == -1) {
	goto L2000;
    }
/* SOURCE chkinput.for:2344 */
/*<       goto(1,2,3,4,5,6,7,8,9,10,10,10,10,14,10),code >*/
    switch (code) {
	case 1:  goto L1;
	case 2:  goto L2;
	case 3:  goto L3;
	case 4:  goto L4;
	case 5:  goto L5;
	case 6:  goto L6;
	case 7:  goto L7;
	case 8:  goto L8;
	case 9:  goto L9;
	case 10:  goto L10;
	case 11:  goto L10;
	case 12:  goto L10;
	case 13:  goto L10;
	case 14:  goto L14;
	case 15:  goto L10;
    }
/* SOURCE chkinput.for:2345 */
/*<       write(stdout,*)' *BUG:20* INVALID EMC CODE IN FINCHK. CODE=',code >*/
    feq_gen_io_d__225.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__225);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:20* INVALID EMC CODE IN FINCHK. CODE="), (
	    ftnlen)43);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE chkinput.for:2347 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE chkinput.for:2348 */
/*<     1 continue >*/
L1:
/* SOURCE chkinput.for:2349 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:2350 */
/*<     2 continue >*/
L2:
/*           MAKE SURE THAT CONTINUITY IS SATISFIED AT A JUNCTION */
/* SOURCE chkinput.for:2352 */
/*<       sum=0.0 >*/
    sum = (float)0.;
/*           PREVENT DIVIDE BY ZERO BY MAKING ABSSUM NON-ZERO */
/* SOURCE chkinput.for:2354 */
/*<       abssum=0.1 >*/
    abssum = (float).1;
/* SOURCE chkinput.for:2355 */
/*<       do220i=1,emc(j+1) >*/
    feq_gen_i_d_1 = emc[j + 1];
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE chkinput.for:2356 */
/*<       nqsgn=emc(j+i+1) >*/
	nqsgn = emc[j + feq_gen_i_d_ + 1];
/* SOURCE chkinput.for:2357 */
/*<       num=abs(nqsgn) >*/
	num = abs(nqsgn);
/* SOURCE chkinput.for:2358 */
/*<       nqsgn=sign(1,nqsgn)*exnodt(1,num) >*/
	nqsgn = i_sign(&feq_gen_c_d_1, &nqsgn) * exnodt[num * 9 + 1];
/* SOURCE chkinput.for:2359 */
/*<       qn=qe1(num) >*/
	qn = enelem_1.qe1[num - 1];
/* SOURCE chkinput.for:2360 */
/*<       if(nqsgn.gt.0)then >*/
	if (nqsgn > 0) {
/* SOURCE chkinput.for:2361 */
/*<       sum=sum+qn >*/
	    sum += qn;
/* SOURCE chkinput.for:2362 */
/*<       else >*/
	} else {
/* SOURCE chkinput.for:2363 */
/*<       sum=sum-qn >*/
	    sum -= qn;
/* SOURCE chkinput.for:2364 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:2365 */
/*<       abssum=abssum+abs(qn) >*/
	abssum += dabs(qn);
/* SOURCE chkinput.for:2366 */
/*<   220 continue >*/
/* L220: */
    }
/* SOURCE chkinput.for:2368 */
/*<       if(abs(sum)/abssum.gt.0.001)then >*/
    if (dabs(sum) / abssum > (float).001) {
/* SOURCE chkinput.for:2369 */
/*<       write(stdout,52)sum >*/
	feq_gen_io_d__232.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__232);
	do_fio(&feq_gen_c_d_1, (char *)&sum, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE chkinput.for:2370 */
/*<       do221i=1,emc(j+1) >*/
	feq_gen_i_d_1 = emc[j + 1];
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE chkinput.for:2371 */
/*<       notea=note(j+i+1,emc,exnodt,ept,nex) >*/
	    feq_gen_i_d_2 = j + feq_gen_i_d_ + 1;
	    note_(feq_gen_ch_d_1, (ftnlen)10, &feq_gen_i_d_2, &emc[1], &exnodt[10], ept, nex);
	    s_copy(notea, feq_gen_ch_d_1, (ftnlen)10, (ftnlen)10);
/* SOURCE chkinput.for:2372 */
/*<       write(stdout,53)getusn(emc(j+i+1)),notea >*/
	    feq_gen_io_d__234.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__234);
	    getusn_(feq_gen_ch_d_3, (ftnlen)5, &emc[j + feq_gen_i_d_ + 1]);
	    s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, notea, (ftnlen)10);
	    e_wsfe();
/* SOURCE chkinput.for:2373 */
/*<   221 continue >*/
/* L221: */
	}
/* SOURCE chkinput.for:2374 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:2375 */
/*<       j=j+emc(j+1) >*/
    j += emc[j + 1];
/* SOURCE chkinput.for:2376 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:2377 */
/*<     3 continue >*/
L3:
/*           MAKE SURE INITIAL ELEVATIONS ARE EQUAL */
/* SOURCE chkinput.for:2379 */
/*<       temp=abs(ze(emc(j+1))+ye1(emc(j+1))-(ze(emc(j+2))+ye1(emc(j+2)))) >*/
    temp = (feq_gen_r_d_1 = static_cast<double>(static_cast<double>(enelem_1.ze[emc[j + 1] - 1]) + enelem_1.ye1[emc[j + 1] - 1]) 
	    - (static_cast<double>(enelem_1.ze[emc[j + 2] - 1]) + enelem_1.ye1[emc[j + 2] - 1]), 
	    dabs(feq_gen_r_d_1));
/* SOURCE chkinput.for:2381 */
/*<       if(temp.gt.0.01)then >*/
    if (temp > (float).01) {
/* SOURCE chkinput.for:2382 */
/*<       notea=note(j+1,emc,exnodt,ept,nex) >*/
	feq_gen_i_d_1 = j + 1;
	note_(feq_gen_ch_d_1, (ftnlen)10, &feq_gen_i_d_1, &emc[1], &exnodt[10], ept, nex);
	s_copy(notea, feq_gen_ch_d_1, (ftnlen)10, (ftnlen)10);
/* SOURCE chkinput.for:2383 */
/*<       noteb=note(j+2,emc,exnodt,ept,nex) >*/
	feq_gen_i_d_1 = j + 2;
	note_(feq_gen_ch_d_1, (ftnlen)10, &feq_gen_i_d_1, &emc[1], &exnodt[10], ept, nex);
	s_copy(noteb, feq_gen_ch_d_1, (ftnlen)10, (ftnlen)10);
/* SOURCE chkinput.for:2384 */
/*<       write(stdout,54)getusn(emc(j+1)),notea,getusn(emc(j+2)),noteb,temp >*/
	feq_gen_io_d__237.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__237);
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &emc[j + 1]);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, notea, (ftnlen)10);
	getusn_(feq_gen_ch_d_5, (ftnlen)5, &emc[j + 2]);
	s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, noteb, (ftnlen)10);
	do_fio(&feq_gen_c_d_1, (char *)&temp, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE chkinput.for:2386 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:2387 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:2388 */
/*<     4 continue >*/
L4:
/* SOURCE chkinput.for:2390 */
/*<       qnode=emc(j+4) >*/
    qnode = emc[j + 4];
/*          BRANCH ON TYPE */
/* SOURCE chkinput.for:2393 */
/*<       itype=emc(j+1) >*/
    itype = emc[j + 1];
/* SOURCE chkinput.for:2394 */
/*<       goto(401,402,403,404,405,406),itype >*/
    switch (itype) {
	case 1:  goto L401;
	case 2:  goto L402;
	case 3:  goto L403;
	case 4:  goto L404;
	case 5:  goto L405;
	case 6:  goto L406;
    }
/* SOURCE chkinput.for:2396 */
/*<   401 continue >*/
L401:
/*            check for flow node having a location. */
/* SOURCE chkinput.for:2398 */
/*<       if(exnodt(6,qnode)/=null)then >*/
    if (exnodt[qnode * 9 + 6] != null) {
/*              we have a location.  Extract it and store */
/*              in the function tables if the table contains */
/*              the default null value. */
/* SOURCE chkinput.for:2402 */
/*<       tabadrs=emc(j+5) >*/
	tabadrs = emc[j + 5];
/* SOURCE chkinput.for:2403 */
/*<       callget_east_north(stdout,tabadrs,easting,northing) >*/
	feq_gen_get_east_north_d_(stdout, &tabadrs, &easting, &northing);
/* SOURCE chkinput.for:2407 */
/*<       if(easting<=dnull)then >*/
	if (easting <= dnull) {
/*                replace with the values found in FEQ */
/* SOURCE chkinput.for:2409 */
/*<       easting=dble(exnodt(6,qnode))/100.d0 >*/
	    easting = (doublereal) exnodt[qnode * 9 + 6] / 100.;
/* SOURCE chkinput.for:2410 */
/*<       northing=dble(exnodt(7,qnode))/100.d0 >*/
	    northing = (doublereal) exnodt[qnode * 9 + 7] / 100.;
/* SOURCE chkinput.for:2411 */
/*<       callput_east_north(stdout,tabadrs,easting,northing) >*/
	    feq_gen_put_east_north_d_(stdout, &tabadrs, &easting, &northing);
/* SOURCE chkinput.for:2414 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:2415 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:2416 */
/*<       goto499 >*/
    goto L499;
/* SOURCE chkinput.for:2417 */
/*<   402 continue >*/
L402:
/*            check for flow node having a location. */
/* SOURCE chkinput.for:2419 */
/*<       if(exnodt(6,qnode)/=null)then >*/
    if (exnodt[qnode * 9 + 6] != null) {
/*              we have a location.  Extract it and store */
/*              in the function tables if the table contains */
/*              the default null value. */
/* SOURCE chkinput.for:2423 */
/*<       tabadrs=emc(j+5) >*/
	tabadrs = emc[j + 5];
/* SOURCE chkinput.for:2424 */
/*<       callget_east_north(stdout,tabadrs,easting,northing) >*/
	feq_gen_get_east_north_d_(stdout, &tabadrs, &easting, &northing);
/* SOURCE chkinput.for:2428 */
/*<       if(easting<=dnull)then >*/
	if (easting <= dnull) {
/*                replace with the values found in FEQ */
/* SOURCE chkinput.for:2430 */
/*<       easting=dble(exnodt(6,qnode))/100.d0 >*/
	    easting = (doublereal) exnodt[qnode * 9 + 6] / 100.;
/* SOURCE chkinput.for:2431 */
/*<       northing=dble(exnodt(7,qnode))/100.d0 >*/
	    northing = (doublereal) exnodt[qnode * 9 + 7] / 100.;
/* SOURCE chkinput.for:2432 */
/*<       callput_east_north(stdout,tabadrs,easting,northing) >*/
	    feq_gen_put_east_north_d_(stdout, &tabadrs, &easting, &northing);
/* SOURCE chkinput.for:2435 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:2436 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:2437 */
/*<       goto499 >*/
    goto L499;
/* SOURCE chkinput.for:2438 */
/*<   403 continue >*/
L403:
/* SOURCE chkinput.for:2439 */
/*<       goto499 >*/
    goto L499;
/* SOURCE chkinput.for:2440 */
/*<   404 continue >*/
L404:
/*            check for flow node having a location. */
/* SOURCE chkinput.for:2442 */
/*<       if(exnodt(6,qnode)/=null)then >*/
    if (exnodt[qnode * 9 + 6] != null) {
/*              we have a location.  Extract it and store */
/*              in the function tables if the table contains */
/*              the default null value. */
/* SOURCE chkinput.for:2446 */
/*<       doi=5,6 >*/
	for (feq_gen_i_d_ = 5; feq_gen_i_d_ <= 6; ++feq_gen_i_d_) {
/* SOURCE chkinput.for:2447 */
/*<       tabadrs=emc(j+i) >*/
	    tabadrs = emc[j + feq_gen_i_d_];
/* SOURCE chkinput.for:2448 */
/*<       callget_east_north(stdout,tabadrs,easting,northing) >*/
	    feq_gen_get_east_north_d_(stdout, &tabadrs, &easting, &northing);
/* SOURCE chkinput.for:2452 */
/*<       if(easting<=dnull)then >*/
	    if (easting <= dnull) {
/*                  replace with the values found in FEQ */
/* SOURCE chkinput.for:2454 */
/*<       easting=dble(exnodt(6,qnode))/100.d0 >*/
		easting = (doublereal) exnodt[qnode * 9 + 6] / 100.;
/* SOURCE chkinput.for:2455 */
/*<       northing=dble(exnodt(7,qnode))/100.d0 >*/
		northing = (doublereal) exnodt[qnode * 9 + 7] / 100.;
/* SOURCE chkinput.for:2456 */
/*<       callput_east_north(stdout,tabadrs,easting,northing) >*/
		feq_gen_put_east_north_d_(stdout, &tabadrs, &easting, &northing);
/* SOURCE chkinput.for:2459 */
/*<       endif >*/
	    }
/* SOURCE chkinput.for:2460 */
/*<       enddo >*/
	}
/* SOURCE chkinput.for:2461 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:2462 */
/*<       goto499 >*/
    goto L499;
/* SOURCE chkinput.for:2463 */
/*<   405 continue >*/
L405:
/*            check for flow node having a location. */
/* SOURCE chkinput.for:2465 */
/*<       if(exnodt(6,qnode)/=null)then >*/
    if (exnodt[qnode * 9 + 6] != null) {
/*              we have a location.  Extract it and store */
/*              in the function tables if the table contains */
/*              the default null value. */
/* SOURCE chkinput.for:2469 */
/*<       tabadrs=emc(j+5) >*/
	tabadrs = emc[j + 5];
/* SOURCE chkinput.for:2470 */
/*<       callget_east_north(stdout,tabadrs,easting,northing) >*/
	feq_gen_get_east_north_d_(stdout, &tabadrs, &easting, &northing);
/* SOURCE chkinput.for:2474 */
/*<       if(easting<=dnull)then >*/
	if (easting <= dnull) {
/*                replace with the values found in FEQ */
/* SOURCE chkinput.for:2476 */
/*<       easting=dble(exnodt(6,qnode))/100.d0 >*/
	    easting = (doublereal) exnodt[qnode * 9 + 6] / 100.;
/* SOURCE chkinput.for:2477 */
/*<       northing=dble(exnodt(7,qnode))/100.d0 >*/
	    northing = (doublereal) exnodt[qnode * 9 + 7] / 100.;
/* SOURCE chkinput.for:2478 */
/*<       callput_east_north(stdout,tabadrs,easting,northing) >*/
	    feq_gen_put_east_north_d_(stdout, &tabadrs, &easting, &northing);
/* SOURCE chkinput.for:2481 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:2482 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:2483 */
/*<       goto499 >*/
    goto L499;
/* SOURCE chkinput.for:2484 */
/*<   406 continue >*/
L406:
/*            check for flow node having a location. */
/* SOURCE chkinput.for:2486 */
/*<       if(exnodt(6,qnode)/=null)then >*/
    if (exnodt[qnode * 9 + 6] != null) {
/*              we have a location.  Extract it and store */
/*              in the function tables if the table contains */
/*              the default null value. */
/* SOURCE chkinput.for:2490 */
/*<       doi=5,7 >*/
	for (feq_gen_i_d_ = 5; feq_gen_i_d_ <= 7; ++feq_gen_i_d_) {
/* SOURCE chkinput.for:2491 */
/*<       tabadrs=emc(j+i) >*/
	    tabadrs = emc[j + feq_gen_i_d_];
/* SOURCE chkinput.for:2492 */
/*<       if(tabadrs>0)then >*/
	    if (tabadrs > 0) {
/* SOURCE chkinput.for:2493 */
/*<       callget_east_north(stdout,tabadrs,easting,northing) >*/
		feq_gen_get_east_north_d_(stdout, &tabadrs, &easting, &northing);
/* SOURCE chkinput.for:2497 */
/*<       if(easting<=dnull)then >*/
		if (easting <= dnull) {
/*                    replace with the values found in FEQ */
/* SOURCE chkinput.for:2499 */
/*<       easting=dble(exnodt(6,qnode))/100.d0 >*/
		    easting = (doublereal) exnodt[qnode * 9 + 6] / 100.;
/* SOURCE chkinput.for:2500 */
/*<       northing=dble(exnodt(7,qnode))/100.d0 >*/
		    northing = (doublereal) exnodt[qnode * 9 + 7] / 100.;
/* SOURCE chkinput.for:2501 */
/*<       callput_east_north(stdout,tabadrs,easting,northing) >*/
		    feq_gen_put_east_north_d_(stdout, &tabadrs, &easting, &northing);
/* SOURCE chkinput.for:2504 */
/*<       endif >*/
		}
/* SOURCE chkinput.for:2505 */
/*<       endif >*/
	    }
/* SOURCE chkinput.for:2506 */
/*<       enddo >*/
	}
/* SOURCE chkinput.for:2507 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:2508 */
/*<       goto499 >*/
    goto L499;
/* SOURCE chkinput.for:2510 */
/*<   499 continue >*/
L499:
/* SOURCE chkinput.for:2512 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:2513 */
/*<     5 continue >*/
L5:
/* SOURCE chkinput.for:2514 */
/*<       itype=emc(j+1) >*/
    itype = emc[j + 1];
/* SOURCE chkinput.for:2515 */
/*<       upn=emc(j+2) >*/
    upn = emc[j + 2];
/* SOURCE chkinput.for:2516 */
/*<       dnn=emc(j+3) >*/
    dnn = emc[j + 3];
/* SOURCE chkinput.for:2517 */
/*<       qnode=emc(j+4) >*/
    qnode = emc[j + 4];
/* SOURCE chkinput.for:2518 */
/*<       goto(501,502,503,504,505,506,507,508,509),itype >*/
    switch (itype) {
	case 1:  goto L501;
	case 2:  goto L502;
	case 3:  goto L503;
	case 4:  goto L504;
	case 5:  goto L505;
	case 6:  goto L506;
	case 7:  goto L507;
	case 8:  goto L508;
	case 9:  goto L509;
    }
/* SOURCE chkinput.for:2519 */
/*<        >*/
    feq_gen_io_d__245.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__245);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:21* INVALID CODE=5 TYPE IN FINCHK."), (ftnlen)
	    40);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" TYPE="), (ftnlen)6);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&itype, (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE chkinput.for:2521 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE chkinput.for:2522 */
/*<   501 continue >*/
L501:
/* SOURCE chkinput.for:2523 */
/*<       j=j+cd5ty1 >*/
    j += 7;
/* SOURCE chkinput.for:2524 */
/*<       goto599 >*/
    goto L599;
/* SOURCE chkinput.for:2525 */
/*<   502 continue >*/
L502:
/*            check for flow node having a location. */
/* SOURCE chkinput.for:2527 */
/*<       if(exnodt(6,qnode)/=null)then >*/
    if (exnodt[qnode * 9 + 6] != null) {
/*              we have a location.  Extract it and store */
/*              in the function tables if the table contains */
/*              the default null value. */
/* SOURCE chkinput.for:2531 */
/*<       doi=6,9 >*/
	for (feq_gen_i_d_ = 6; feq_gen_i_d_ <= 9; ++feq_gen_i_d_) {
/* SOURCE chkinput.for:2532 */
/*<       tabadrs=emc(j+i) >*/
	    tabadrs = emc[j + feq_gen_i_d_];
/* SOURCE chkinput.for:2533 */
/*<       callget_east_north(stdout,tabadrs,easting,northing) >*/
	    feq_gen_get_east_north_d_(stdout, &tabadrs, &easting, &northing);
/* SOURCE chkinput.for:2537 */
/*<       if(easting<=dnull)then >*/
	    if (easting <= dnull) {
/*                  replace with the values found in FEQ */
/* SOURCE chkinput.for:2539 */
/*<       easting=dble(exnodt(6,qnode))/100.d0 >*/
		easting = (doublereal) exnodt[qnode * 9 + 6] / 100.;
/* SOURCE chkinput.for:2540 */
/*<       northing=dble(exnodt(7,qnode))/100.d0 >*/
		northing = (doublereal) exnodt[qnode * 9 + 7] / 100.;
/* SOURCE chkinput.for:2541 */
/*<       callput_east_north(stdout,tabadrs,easting,northing) >*/
		feq_gen_put_east_north_d_(stdout, &tabadrs, &easting, &northing);
/* SOURCE chkinput.for:2544 */
/*<       endif >*/
	    }
/* SOURCE chkinput.for:2545 */
/*<       enddo >*/
	}
/* SOURCE chkinput.for:2546 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:2548 */
/*<       j=j+cd5ty2 >*/
    j += 12;
/* SOURCE chkinput.for:2549 */
/*<       goto599 >*/
    goto L599;
/* SOURCE chkinput.for:2551 */
/*<   503 continue >*/
L503:
/*            check for flow node having a location. */
/* SOURCE chkinput.for:2553 */
/*<       if(exnodt(6,qnode)/=null)then >*/
    if (exnodt[qnode * 9 + 6] != null) {
/*              we have a location.  Extract it and store */
/*              in the function tables if the table contains */
/*              the default null value. */
/* SOURCE chkinput.for:2557 */
/*<       doi=7,9 >*/
	for (feq_gen_i_d_ = 7; feq_gen_i_d_ <= 9; ++feq_gen_i_d_) {
/* SOURCE chkinput.for:2558 */
/*<       tabadrs=emc(j+i) >*/
	    tabadrs = emc[j + feq_gen_i_d_];
/* SOURCE chkinput.for:2559 */
/*<       if(tabadrs>0)then >*/
	    if (tabadrs > 0) {
/* SOURCE chkinput.for:2560 */
/*<       callget_east_north(stdout,tabadrs,easting,northing) >*/
		feq_gen_get_east_north_d_(stdout, &tabadrs, &easting, &northing);
/* SOURCE chkinput.for:2564 */
/*<       if(easting<=dnull)then >*/
		if (easting <= dnull) {
/*                    replace with the values found in FEQ */
/* SOURCE chkinput.for:2566 */
/*<       easting=dble(exnodt(6,qnode))/100.d0 >*/
		    easting = (doublereal) exnodt[qnode * 9 + 6] / 100.;
/* SOURCE chkinput.for:2567 */
/*<       northing=dble(exnodt(7,qnode))/100.d0 >*/
		    northing = (doublereal) exnodt[qnode * 9 + 7] / 100.;
/* SOURCE chkinput.for:2568 */
/*<       callput_east_north(stdout,tabadrs,easting,northing) >*/
		    feq_gen_put_east_north_d_(stdout, &tabadrs, &easting, &northing);
/* SOURCE chkinput.for:2571 */
/*<       endif >*/
		}
/* SOURCE chkinput.for:2572 */
/*<       endif >*/
	    }
/* SOURCE chkinput.for:2573 */
/*<       enddo >*/
	}
/* SOURCE chkinput.for:2574 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:2576 */
/*<       j=j+cd5ty3 >*/
    j += 17;
/* SOURCE chkinput.for:2577 */
/*<       goto599 >*/
    goto L599;
/* SOURCE chkinput.for:2579 */
/*<   504 continue >*/
L504:
/* SOURCE chkinput.for:2580 */
/*<       idum=emc(j+13) >*/
    *idum = emc[j + 13];
/* SOURCE chkinput.for:2581 */
/*<       yb=rdum-ze(upn) >*/
    yb = static_cast<double>(*rdum) - enelem_1.ze[upn - 1];
/* SOURCE chkinput.for:2582 */
/*<       emax=rdum >*/
    emax = *rdum;
/*            CHK YB ABAINST MAX DEPTH IN THE BRIDGE OPENING TABLE */
/* SOURCE chkinput.for:2584 */
/*<       ybtab=ftab(itab(emc(j+8))) >*/
    ybtab = ftab[itab[emc[j + 8]]];
/* SOURCE chkinput.for:2585 */
/*<       if(abs(yb-ybtab).gt.0.02)then >*/
    if ((feq_gen_r_d_1 = static_cast<double>(yb) - ybtab, dabs(feq_gen_r_d_1)) > (float).02) {
/*              DISCREPANCY TOO LARGE.  USE YBTAB */
/* SOURCE chkinput.for:2587 */
/*<       notea=note(j+2,emc,exnodt,ept,nex) >*/
	feq_gen_i_d_1 = j + 2;
	note_(feq_gen_ch_d_1, (ftnlen)10, &feq_gen_i_d_1, &emc[1], &exnodt[10], ept, nex);
	s_copy(notea, feq_gen_ch_d_1, (ftnlen)10, (ftnlen)10);
/* SOURCE chkinput.for:2588 */
/*<       noteb=note(j+3,emc,exnodt,ept,nex) >*/
	feq_gen_i_d_1 = j + 3;
	note_(feq_gen_ch_d_1, (ftnlen)10, &feq_gen_i_d_1, &emc[1], &exnodt[10], ept, nex);
	s_copy(noteb, feq_gen_ch_d_1, (ftnlen)10, (ftnlen)10);
/* SOURCE chkinput.for:2589 */
/*<       write(stdout,64)getusn(upn),notea,getusn(dnn),noteb >*/
	feq_gen_io_d__249.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__249);
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &upn);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, notea, (ftnlen)10);
	getusn_(feq_gen_ch_d_5, (ftnlen)5, &dnn);
	s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, noteb, (ftnlen)10);
	e_wsfe();
/* SOURCE chkinput.for:2590 */
/*<       write(stdout,66)rdum,get_tabid(itab(emc(j+8)+1)),ybtab+ze(upn) >*/
	feq_gen_io_d__250.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__250);
	do_fio(&feq_gen_c_d_1, (char *)&(*rdum), (ftnlen)sizeof(real));
	feq_gen_get_tabid_d_(feq_gen_ch_d_7, (ftnlen)16, itab.lease(emc[j + 8] + 1).data());
	s_copy(feq_gen_ch_d_6, feq_gen_ch_d_7, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_6, (ftnlen)16);
	feq_gen_r_d_1 = static_cast<double>(ybtab) + enelem_1.ze[upn - 1];
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE chkinput.for:2592 */
/*<       if(yb.gt.ybtab+1.0)then >*/
	if (yb > static_cast<double>(ybtab) + (float)1.) {
/* SOURCE chkinput.for:2593 */
/*<       write(stdout,86) >*/
	    feq_gen_io_d__251.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__251);
	    e_wsfe();
/* SOURCE chkinput.for:2594 */
/*<       yb=ybtab >*/
	    yb = ybtab;
/* SOURCE chkinput.for:2595 */
/*<       frflow=1 >*/
	    frflow = 1;
/* SOURCE chkinput.for:2596 */
/*<       emax=yb+ze(upn) >*/
	    emax = static_cast<double>(yb) + enelem_1.ze[upn - 1];
/* SOURCE chkinput.for:2597 */
/*<       else >*/
	} else {
/* SOURCE chkinput.for:2598 */
/*<       yb=ybtab >*/
	    yb = ybtab;
/* SOURCE chkinput.for:2599 */
/*<       frflow=0 >*/
	    frflow = 0;
/* SOURCE chkinput.for:2600 */
/*<       emax=yb+ze(upn) >*/
	    emax = static_cast<double>(yb) + enelem_1.ze[upn - 1];
/* SOURCE chkinput.for:2601 */
/*<       rdum=emax >*/
	    *rdum = emax;
/* SOURCE chkinput.for:2602 */
/*<       emc(j+13)=idum >*/
	    emc[j + 13] = *idum;
/* SOURCE chkinput.for:2603 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:2604 */
/*<       write(stdout,68)rdum >*/
	feq_gen_io_d__253.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__253);
	do_fio(&feq_gen_c_d_1, (char *)&(*rdum), (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE chkinput.for:2605 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:2607 */
/*<       idum=emc(j+12) >*/
    *idum = emc[j + 12];
/* SOURCE chkinput.for:2608 */
/*<       abmax=rdum >*/
    abmax = *rdum;
/* SOURCE chkinput.for:2609 */
/*<       callxlkt20(emc(j+8),yb,ab,top,dtop,con,dcon,b,db) >*/
    xlkt20_(&emc[j + 8], &yb, &ab, &top, &dtop, &con, &dcon, &b, &db);
/* SOURCE chkinput.for:2613 */
/*<       if(ab/abmax.lt.0.98.or.ab/abmax.gt.1.02)then >*/
    if (static_cast<double>(ab) / abmax < (float).98 || static_cast<double>(ab) / abmax > (float)1.02) {
/* SOURCE chkinput.for:2614 */
/*<       notea=note(j+2,emc,exnodt,ept,nex) >*/
	feq_gen_i_d_1 = j + 2;
	note_(feq_gen_ch_d_1, (ftnlen)10, &feq_gen_i_d_1, &emc[1], &exnodt[10], ept, nex);
	s_copy(notea, feq_gen_ch_d_1, (ftnlen)10, (ftnlen)10);
/* SOURCE chkinput.for:2615 */
/*<       noteb=note(j+3,emc,exnodt,ept,nex) >*/
	feq_gen_i_d_1 = j + 3;
	note_(feq_gen_ch_d_1, (ftnlen)10, &feq_gen_i_d_1, &emc[1], &exnodt[10], ept, nex);
	s_copy(noteb, feq_gen_ch_d_1, (ftnlen)10, (ftnlen)10);
/* SOURCE chkinput.for:2616 */
/*<       write(stdout,60)getusn(upn),notea,getusn(dnn),noteb >*/
	feq_gen_io_d__262.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__262);
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &upn);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, notea, (ftnlen)10);
	getusn_(feq_gen_ch_d_5, (ftnlen)5, &dnn);
	s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, noteb, (ftnlen)10);
	e_wsfe();
/* SOURCE chkinput.for:2617 */
/*<       write(stdout,62)abmax,ab >*/
	feq_gen_io_d__263.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__263);
	do_fio(&feq_gen_c_d_1, (char *)&abmax, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&ab, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE chkinput.for:2618 */
/*<       rdum=ab >*/
	*rdum = ab;
/* SOURCE chkinput.for:2619 */
/*<       emc(j+12)=idum >*/
	emc[j + 12] = *idum;
/* SOURCE chkinput.for:2620 */
/*<       write(stdout,70)rdum >*/
	feq_gen_io_d__264.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__264);
	do_fio(&feq_gen_c_d_1, (char *)&(*rdum), (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE chkinput.for:2621 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:2622 */
/*<       ab=rdum >*/
    ab = *rdum;
/*            CHECK TRANSITION FROM FREE FLOW TO SUBMERGED FLOW */
/* SOURCE chkinput.for:2625 */
/*<       if(hslot.ge.yb)then >*/
    if (*hslot >= yb) {
/* SOURCE chkinput.for:2626 */
/*<       floss=0.005 >*/
	floss = (float).005;
/* SOURCE chkinput.for:2627 */
/*<       pdv=0.0 >*/
	pdv = (float)0.;
/* SOURCE chkinput.for:2628 */
/*<       else >*/
    } else {
/* SOURCE chkinput.for:2629 */
/*<       calllktab(emc(j+6),yb-hslot,0,floss,ntab,pdv) >*/
	feq_gen_r_d_1 = static_cast<double>(yb) - *hslot;
	lktab_(&emc[j + 6], &feq_gen_r_d_1, &feq_gen_c_d_0, &floss, &ntab, &pdv);
/* SOURCE chkinput.for:2632 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:2633 */
/*<       idum=emc(j+14) >*/
    *idum = emc[j + 14];
/*            COMPUTE THE FREE LOSS COEF. IMPLIED BY THE SUBMERGED */
/*            COEFFICIENT OF DISCHARGE AT THE BRIDGE SOFFIT. */
/* SOURCE chkinput.for:2637 */
/*<       cd=rdum >*/
    cd = *rdum;
/*            FIND DOWNSTREAM AREA CORRESPONDING TO THE TRUE MAX BRIDGE */
/*            OPENING ELEVATION */
/* SOURCE chkinput.for:2642 */
/*<       yd=emax-ze(dnn) >*/
    yd = static_cast<double>(emax) - enelem_1.ze[dnn - 1];
/*             WRITE(STDOUT,*) 'FINCHK: EMAX=',EMAX, ' ZE(DNN)=',ZE(DNN) */
/* SOURCE chkinput.for:2645 */
/*<       callxlkt20(exnodt(4,dnn),yd,ad,top,dtap,con,dcon,b,db) >*/
    xlkt20_(&exnodt[dnn * 9 + 4], &yd, &ad, &top, &dtap, &con, &dcon, &b, &db)
	    ;
/* SOURCE chkinput.for:2649 */
/*<       rat=ab/ad >*/
    rat = static_cast<double>(ab) / ad;
/* SOURCE chkinput.for:2650 */
/*<       if(rat.gt.1.0)then >*/
    if (rat > (float)1.) {
/* SOURCE chkinput.for:2651 */
/*<       notea=note(j+2,emc,exnodt,ept,nex) >*/
	feq_gen_i_d_1 = j + 2;
	note_(feq_gen_ch_d_1, (ftnlen)10, &feq_gen_i_d_1, &emc[1], &exnodt[10], ept, nex);
	s_copy(notea, feq_gen_ch_d_1, (ftnlen)10, (ftnlen)10);
/* SOURCE chkinput.for:2652 */
/*<       noteb=note(j+3,emc,exnodt,ept,nex) >*/
	feq_gen_i_d_1 = j + 3;
	note_(feq_gen_ch_d_1, (ftnlen)10, &feq_gen_i_d_1, &emc[1], &exnodt[10], ept, nex);
	s_copy(noteb, feq_gen_ch_d_1, (ftnlen)10, (ftnlen)10);
/* SOURCE chkinput.for:2653 */
/*<       write(stdout,84)getusn(upn),notea,getusn(dnn),noteb,rat >*/
	feq_gen_io_d__273.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__273);
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &upn);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, notea, (ftnlen)10);
	getusn_(feq_gen_ch_d_5, (ftnlen)5, &dnn);
	s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, noteb, (ftnlen)10);
	do_fio(&feq_gen_c_d_1, (char *)&rat, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE chkinput.for:2655 */
/*<       rat=1.0 >*/
	rat = (float)1.;
/* SOURCE chkinput.for:2656 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:2658 */
/*<       cdfl=1.0/cd**2-rat**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = cd;
/* Computing 2nd power */
    feq_gen_r_d_2 = rat;
    cdfl = static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2;
/* SOURCE chkinput.for:2659 */
/*<       if(floss/cdfl.lt.0.98.or.floss/cdfl.gt.1.02.or.frflow.eq.1)then >*/
    if (static_cast<double>(floss) / cdfl < (float).98 || static_cast<double>(floss) / cdfl > (float)1.02 || frflow == 
	    1) {
/* SOURCE chkinput.for:2661 */
/*<       notea=note(j+2,emc,exnodt,ept,nex) >*/
	feq_gen_i_d_1 = j + 2;
	note_(feq_gen_ch_d_1, (ftnlen)10, &feq_gen_i_d_1, &emc[1], &exnodt[10], ept, nex);
	s_copy(notea, feq_gen_ch_d_1, (ftnlen)10, (ftnlen)10);
/* SOURCE chkinput.for:2662 */
/*<       noteb=note(j+3,emc,exnodt,ept,nex) >*/
	feq_gen_i_d_1 = j + 3;
	note_(feq_gen_ch_d_1, (ftnlen)10, &feq_gen_i_d_1, &emc[1], &exnodt[10], ept, nex);
	s_copy(noteb, feq_gen_ch_d_1, (ftnlen)10, (ftnlen)10);
/* SOURCE chkinput.for:2663 */
/*<       write(stdout,56)getusn(upn),notea,getusn(dnn),noteb >*/
	feq_gen_io_d__275.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__275);
	getusn_(feq_gen_ch_d_3, (ftnlen)5, &upn);
	s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, notea, (ftnlen)10);
	getusn_(feq_gen_ch_d_5, (ftnlen)5, &dnn);
	s_copy(feq_gen_ch_d_4, feq_gen_ch_d_5, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_4, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, noteb, (ftnlen)10);
	e_wsfe();
/* SOURCE chkinput.for:2664 */
/*<       write(stdout,58)floss,ntab,cdfl >*/
	feq_gen_io_d__276.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__276);
	do_fio(&feq_gen_c_d_1, (char *)&floss, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&ntab, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&cdfl, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE chkinput.for:2665 */
/*<       if(frflow.eq.1)then >*/
	if (frflow == 1) {
/* SOURCE chkinput.for:2666 */
/*<       iadr=emc(j+6) >*/
	    iadr = emc[j + 6];
/* SOURCE chkinput.for:2667 */
/*<       if(itab(iadr+2).eq.2)then >*/
	    if (itab[iadr + 2] == 2) {
/*                  MODIFY THE TOP THREE VALUES IN THE TABLE */
/* SOURCE chkinput.for:2670 */
/*<       lstarg=itab(iadr) >*/
		lstarg = itab[iadr];
/* SOURCE chkinput.for:2671 */
/*<       ftab(lstarg-1)=cdfl >*/
		ftab[lstarg - 1] = cdfl;
/* SOURCE chkinput.for:2672 */
/*<       ftab(lstarg+1)=1.0/cd**2 >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = cd;
		ftab[lstarg + 1] = static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE chkinput.for:2673 */
/*<       ftab(lstarg-3)=0.5*(ftab(lstarg-3)+cdfl) >*/
		ftab[lstarg - 3] = static_cast<double>((static_cast<double>(ftab[lstarg - 3]) + cdfl)) * (float).5;
/* SOURCE chkinput.for:2674 */
/*<       write(stdout,72) >*/
		feq_gen_io_d__279.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__279);
		e_wsfe();
/* SOURCE chkinput.for:2675 */
/*<       write(stdout,80) >*/
		feq_gen_io_d__280.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__280);
		e_wsfe();
/* SOURCE chkinput.for:2676 */
/*<       do510i=-4,0,2 >*/
		for (feq_gen_i_d_ = -4; feq_gen_i_d_ <= 0; feq_gen_i_d_ += 2) {
/* SOURCE chkinput.for:2677 */
/*<       write(stdout,82)ftab(lstarg+i),ftab(lstarg+i+1) >*/
		    feq_gen_io_d__281.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__281);
		    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(lstarg + feq_gen_i_d_).data(), (ftnlen)sizeof(
			    real));
		    do_fio(&feq_gen_c_d_1, (char *)ftab.lease(lstarg + feq_gen_i_d_ + 1).data(), (ftnlen)
			    sizeof(real));
		    e_wsfe();
/* SOURCE chkinput.for:2678 */
/*<   510 continue >*/
/* L510: */
		}
/* SOURCE chkinput.for:2679 */
/*<       else >*/
	    } else {
/* SOURCE chkinput.for:2680 */
/*<       write(stdout,74) >*/
		feq_gen_io_d__282.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__282);
		e_wsfe();
/* SOURCE chkinput.for:2681 */
/*<       endif >*/
	    }
/* SOURCE chkinput.for:2682 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:2683 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:2684 */
/*<       j=j+cd5ty4 >*/
    j += 10;
/* SOURCE chkinput.for:2685 */
/*<       goto599 >*/
    goto L599;
/* SOURCE chkinput.for:2687 */
/*<   505 continue >*/
L505:
/* SOURCE chkinput.for:2688 */
/*<       j=j+cd5ty5 >*/
    j += 3;
/* SOURCE chkinput.for:2689 */
/*<       goto599 >*/
    goto L599;
/* SOURCE chkinput.for:2690 */
/*<   506 continue >*/
L506:
/*            CHECK THAT THE HEAD DATUM STORED IN THE TABLE MATCHES */
/*            THE HEAD DATUM GIVEN.  IF HEAD DATUM STORED IN THE TABLE */
/*            IS < -9000, THEN ASSUME THAT HEAD DATUM IS NOT KNOWN AND */
/*            SKIP THE CHECK FOR THAT TABLE. */
/* SOURCE chkinput.for:2696 */
/*<       ioff=0 >*/
    ioff = 0;
/* SOURCE chkinput.for:2697 */
/*<       n=abs(emc(j+6)) >*/
    n = (feq_gen_i_d_1 = emc[j + 6], abs(feq_gen_i_d_1));
/* SOURCE chkinput.for:2698 */
/*<       do5069i=1,n >*/
    feq_gen_i_d_1 = n;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE chkinput.for:2699 */
/*<       if(emc(j+ioff+10).eq.0)then >*/
	if (emc[j + ioff + 10] == 0) {
/*                NO TIME VARYING HEAD. THEREFORE DO CHECK. FIRST */
/*                EXTRACT THE HEAD FROM EMC FOR I-TH FLOW PATH. */
/* SOURCE chkinput.for:2702 */
/*<       idum=emc(j+ioff+11) >*/
	    *idum = emc[j + ioff + 11];
/* SOURCE chkinput.for:2703 */
/*<       hbase=rdum >*/
	    hbase = *rdum;
/* SOURCE chkinput.for:2704 */
/*<       if(hbase.lt.40000.)then >*/
	    if (hbase < (float)4e4) {
/*                  LARGE HBASE USED TO DISABLE FLOW WITHOUT HAVING TO */
/*                  DELETE THE RELATIONSHIP */
/* SOURCE chkinput.for:2707 */
/*<       do5068k=0,1 >*/
		for (k = 0; k <= 1; ++k) {
/*                    EXTRACT  NEXT TABLE ADRESS */
/* SOURCE chkinput.for:2709 */
/*<       adrs=emc(j+ioff+7+k) >*/
		    adrs = emc[j + ioff + 7 + k];
/* SOURCE chkinput.for:2710 */
/*<       hdatum=gethdd(adrs) >*/
		    hdatum = gethdd_(&adrs);
/* SOURCE chkinput.for:2711 */
/*<       if(hdatum.ge.-9000.)then >*/
		    if (hdatum >= (float)-9e3) {
/* SOURCE chkinput.for:2712 */
/*<       if(cd5t6_tab_datum.eq.'NO')then >*/
			if (s_cmp(feq_gen_cd5t6_tab_datum_d_, const_cast<char*>("NO"), (ftnlen)4, (ftnlen)
				2) == 0) {
/* SOURCE chkinput.for:2713 */
/*<       if(abs(hbase-hdatum).gt.0.01)then >*/
			    if ((feq_gen_r_d_1 = static_cast<double>(hbase) - hdatum, dabs(feq_gen_r_d_1)) > (float)
				    .01) {
/*                          REPORT AS A WARNING. */
/* SOURCE chkinput.for:2715 */
/*<       write(stdout,88)hbase,get_tabid(gettbn(adrs)),gethdd(adrs) >*/
				feq_gen_io_d__289.ciunit = *stdout;
				s_wsfe(&feq_gen_io_d__289);
				do_fio(&feq_gen_c_d_1, (char *)&hbase, (ftnlen)sizeof(
					real));
				feq_gen_i_d_2 = gettbn_(&adrs);
				feq_gen_get_tabid_d_(feq_gen_ch_d_7, (ftnlen)16, &feq_gen_i_d_2);
				s_copy(feq_gen_ch_d_6, feq_gen_ch_d_7, (ftnlen)16, (ftnlen)16);
				do_fio(&feq_gen_c_d_1, feq_gen_ch_d_6, (ftnlen)16);
				feq_gen_r_d_1 = gethdd_(&adrs);
				do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(
					real));
				e_wsfe();
/* SOURCE chkinput.for:2719 */
/*<       endif >*/
			    }
/* SOURCE chkinput.for:2720 */
/*<       else >*/
			} else {
/*                        Take table datum and use it. */
/* SOURCE chkinput.for:2722 */
/*<       rdum=hdatum >*/
			    *rdum = hdatum;
/* SOURCE chkinput.for:2723 */
/*<       emc(j+ioff+11)=idum >*/
			    emc[j + ioff + 11] = *idum;
/* SOURCE chkinput.for:2724 */
/*<       endif >*/
			}
/* SOURCE chkinput.for:2725 */
/*<       endif >*/
		    }
/* SOURCE chkinput.for:2726 */
/*<  5068 continue >*/
/* L5068: */
		}
/* SOURCE chkinput.for:2727 */
/*<       endif >*/
	    }
/* SOURCE chkinput.for:2728 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:2729 */
/*<       ioff=ioff+cd5ty6 >*/
	ioff += 8;
/* SOURCE chkinput.for:2730 */
/*<  5069 continue >*/
/* L5069: */
    }
/* SOURCE chkinput.for:2731 */
/*<       ioff=0 >*/
    ioff = 0;
/* SOURCE chkinput.for:2732 */
/*<       doii=1,n >*/
    feq_gen_i_d_1 = n;
    for (ii = 1; ii <= feq_gen_i_d_1; ++ii) {
/*              check for flow node having a location. */
/* SOURCE chkinput.for:2734 */
/*<       if(exnodt(6,qnode)/=null)then >*/
	if (exnodt[qnode * 9 + 6] != null) {
/*                we have a location.  Extract it and store */
/*                in the function tables if the table contains */
/*                the default null value. */
/* SOURCE chkinput.for:2738 */
/*<       doi=7,10 >*/
	    for (feq_gen_i_d_ = 7; feq_gen_i_d_ <= 10; ++feq_gen_i_d_) {
/* SOURCE chkinput.for:2739 */
/*<       tabadrs=emc(j+ioff+i) >*/
		tabadrs = emc[j + ioff + feq_gen_i_d_];
/* SOURCE chkinput.for:2740 */
/*<       if(i==9)then >*/
		if (feq_gen_i_d_ == 9) {
/* SOURCE chkinput.for:2741 */
/*<       if(tabadrs<0)then >*/
		    if (tabadrs < 0) {
/* SOURCE chkinput.for:2742 */
/*<       tabadrs=abs(tabadrs) >*/
			tabadrs = abs(tabadrs);
/* SOURCE chkinput.for:2743 */
/*<       else >*/
		    } else {
/* SOURCE chkinput.for:2744 */
/*<       tabadrs=0 >*/
			tabadrs = 0;
/* SOURCE chkinput.for:2745 */
/*<       endif >*/
		    }
/* SOURCE chkinput.for:2746 */
/*<       endif >*/
		}
/* SOURCE chkinput.for:2747 */
/*<       if(tabadrs>0)then >*/
		if (tabadrs > 0) {
/* SOURCE chkinput.for:2748 */
/*<       callget_east_north(stdout,tabadrs,easting,northing) >*/
		    feq_gen_get_east_north_d_(stdout, &tabadrs, &easting, &northing);
/* SOURCE chkinput.for:2752 */
/*<       if(easting<=dnull)then >*/
		    if (easting <= dnull) {
/*                      replace with the values found in FEQ */
/* SOURCE chkinput.for:2754 */
/*<       easting=dble(exnodt(6,qnode))/100.d0 >*/
			easting = (doublereal) exnodt[qnode * 9 + 6] / 100.;
/* SOURCE chkinput.for:2755 */
/*<       northing=dble(exnodt(7,qnode))/100.d0 >*/
			northing = (doublereal) exnodt[qnode * 9 + 7] / 100.;
/* SOURCE chkinput.for:2756 */
/*<       callput_east_north(stdout,tabadrs,easting,northing) >*/
			feq_gen_put_east_north_d_(stdout, &tabadrs, &easting, &
				northing);
/* SOURCE chkinput.for:2759 */
/*<       endif >*/
		    }
/* SOURCE chkinput.for:2760 */
/*<       endif >*/
		}
/* SOURCE chkinput.for:2761 */
/*<       enddo >*/
	    }
/* SOURCE chkinput.for:2762 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:2763 */
/*<       ioff=ioff+cd5ty6 >*/
	ioff += 8;
/* SOURCE chkinput.for:2764 */
/*<       enddo >*/
    }
/* SOURCE chkinput.for:2766 */
/*<       j=j+1+abs(emc(j+6))*cd5ty6 >*/
    j = j + 1 + ((feq_gen_i_d_1 = emc[j + 6], abs(feq_gen_i_d_1)) << 3);
/* SOURCE chkinput.for:2767 */
/*<       goto599 >*/
    goto L599;
/* SOURCE chkinput.for:2768 */
/*<   507 continue >*/
L507:
/*            check for flow node having a location. */
/* SOURCE chkinput.for:2770 */
/*<       if(exnodt(6,qnode)/=null)then >*/
    if (exnodt[qnode * 9 + 6] != null) {
/*              we have a location.  Extract it and store */
/*              in the function tables if the table contains */
/*              the default null value. */
/* SOURCE chkinput.for:2774 */
/*<       doi=7,10 >*/
	for (feq_gen_i_d_ = 7; feq_gen_i_d_ <= 10; ++feq_gen_i_d_) {
/* SOURCE chkinput.for:2775 */
/*<       tabadrs=emc(j+i) >*/
	    tabadrs = emc[j + feq_gen_i_d_];
/* SOURCE chkinput.for:2776 */
/*<       if(tabadrs>0)then >*/
	    if (tabadrs > 0) {
/* SOURCE chkinput.for:2777 */
/*<       callget_east_north(stdout,tabadrs,easting,northing) >*/
		feq_gen_get_east_north_d_(stdout, &tabadrs, &easting, &northing);
/* SOURCE chkinput.for:2781 */
/*<       if(easting<=dnull)then >*/
		if (easting <= dnull) {
/*                    replace with the values found in FEQ */
/* SOURCE chkinput.for:2783 */
/*<       easting=dble(exnodt(6,qnode))/100.d0 >*/
		    easting = (doublereal) exnodt[qnode * 9 + 6] / 100.;
/* SOURCE chkinput.for:2784 */
/*<       northing=dble(exnodt(7,qnode))/100.d0 >*/
		    northing = (doublereal) exnodt[qnode * 9 + 7] / 100.;
/* SOURCE chkinput.for:2785 */
/*<       callput_east_north(stdout,tabadrs,easting,northing) >*/
		    feq_gen_put_east_north_d_(stdout, &tabadrs, &easting, &northing);
/* SOURCE chkinput.for:2788 */
/*<       endif >*/
		}
/* SOURCE chkinput.for:2789 */
/*<       endif >*/
	    }
/* SOURCE chkinput.for:2790 */
/*<       enddo >*/
	}
/* SOURCE chkinput.for:2791 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:2793 */
/*<       j=j+cd5ty7 >*/
    j += 10;
/* SOURCE chkinput.for:2794 */
/*<       goto599 >*/
    goto L599;
/* SOURCE chkinput.for:2795 */
/*<   508 continue >*/
L508:
/* SOURCE chkinput.for:2796 */
/*<       j=j+cd5ty8 >*/
    j += 7;
/* SOURCE chkinput.for:2797 */
/*<       goto599 >*/
    goto L599;
/* SOURCE chkinput.for:2798 */
/*<   509 continue >*/
L509:
/* SOURCE chkinput.for:2799 */
/*<       j=j+cd5ty9 >*/
    j += 11;
/* SOURCE chkinput.for:2800 */
/*<       goto599 >*/
    goto L599;
/* SOURCE chkinput.for:2802 */
/*<   599 continue >*/
L599:
/* SOURCE chkinput.for:2803 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:2805 */
/*<     6 continue >*/
L6:
/* SOURCE chkinput.for:2807 */
/*<       if(emc(j+1).ne.2.and.emc(j+4).eq.0)then >*/
    if (emc[j + 1] != 2 && emc[j + 4] == 0) {
/*            CHECK THE CONSTANT FLOW RATE */
/* SOURCE chkinput.for:2809 */
/*<       idum=emc(j+8) >*/
	*idum = emc[j + 8];
/*            COMPUTE WHAT THE FLOW SHOULD BE */
/* SOURCE chkinput.for:2811 */
/*<       rdum=-float(exnodt(1,emc(j+2)))*rdum >*/
	*rdum = static_cast<double>(-((real) exnodt[emc[j + 2] * 9 + 1])) * *rdum;
/* SOURCE chkinput.for:2812 */
/*<       qtmp=qe1(emc(j+2)) >*/
	qtmp = enelem_1.qe1[emc[j + 2] - 1];
/* SOURCE chkinput.for:2813 */
/*<       if(abs(qtmp).le.qchop)qtmp=0.0 >*/
	if (dabs(qtmp) <= *qchop) {
	    qtmp = (float)0.;
	}
/* SOURCE chkinput.for:2814 */
/*<       if(abs(qtmp-rdum).gt.0.01*abs(rdum))then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(qtmp) - *rdum, dabs(feq_gen_r_d_1)) > dabs(*rdum) * (float).01) {
/* SOURCE chkinput.for:2815 */
/*<       notea=note(j+2,emc,exnodt,ept,nex) >*/
	    feq_gen_i_d_1 = j + 2;
	    note_(feq_gen_ch_d_1, (ftnlen)10, &feq_gen_i_d_1, &emc[1], &exnodt[10], ept, nex);
	    s_copy(notea, feq_gen_ch_d_1, (ftnlen)10, (ftnlen)10);
/* SOURCE chkinput.for:2816 */
/*<       write(stdout,76)getusn(emc(j+2)),notea >*/
	    feq_gen_io_d__292.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__292);
	    getusn_(feq_gen_ch_d_3, (ftnlen)5, &emc[j + 2]);
	    s_copy(feq_gen_ch_d_2, feq_gen_ch_d_3, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_2, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, notea, (ftnlen)10);
	    e_wsfe();
/* SOURCE chkinput.for:2817 */
/*<       qe1(emc(j+2))=rdum >*/
	    enelem_1.qe1[emc[j + 2] - 1] = *rdum;
/* SOURCE chkinput.for:2818 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:2819 */
/*<       endif >*/
    }
/*          check for boundary node having a location. */
/* SOURCE chkinput.for:2821 */
/*<       qnode=emc(j+2) >*/
    qnode = emc[j + 2];
/* SOURCE chkinput.for:2822 */
/*<       if(exnodt(6,qnode)/=null)then >*/
    if (exnodt[qnode * 9 + 6] != null) {
/*            we have a location.  Extract it and store */
/*            in the function tables if the table contains */
/*            the default null value. */
/* SOURCE chkinput.for:2826 */
/*<       doi=4,10,6 >*/
	for (feq_gen_i_d_ = 4; feq_gen_i_d_ <= 10; feq_gen_i_d_ += 6) {
/* SOURCE chkinput.for:2827 */
/*<       tabadrs=emc(j+i) >*/
	    tabadrs = emc[j + feq_gen_i_d_];
/* SOURCE chkinput.for:2828 */
/*<       if(tabadrs>0)then >*/
	    if (tabadrs > 0) {
/* SOURCE chkinput.for:2829 */
/*<       callget_east_north(stdout,tabadrs,easting,northing) >*/
		feq_gen_get_east_north_d_(stdout, &tabadrs, &easting, &northing);
/* SOURCE chkinput.for:2833 */
/*<       if(easting<=dnull)then >*/
		if (easting <= dnull) {
/*                  replace with the values found in FEQ */
/* SOURCE chkinput.for:2835 */
/*<       easting=dble(exnodt(6,qnode))/100.d0 >*/
		    easting = (doublereal) exnodt[qnode * 9 + 6] / 100.;
/* SOURCE chkinput.for:2836 */
/*<       northing=dble(exnodt(7,qnode))/100.d0 >*/
		    northing = (doublereal) exnodt[qnode * 9 + 7] / 100.;
/* SOURCE chkinput.for:2837 */
/*<       callput_east_north(stdout,tabadrs,easting,northing) >*/
		    feq_gen_put_east_north_d_(stdout, &tabadrs, &easting, &northing);
/* SOURCE chkinput.for:2840 */
/*<       endif >*/
		}
/* SOURCE chkinput.for:2841 */
/*<       endif >*/
	    }
/* SOURCE chkinput.for:2842 */
/*<       enddo >*/
	}
/* SOURCE chkinput.for:2843 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:2845 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:2847 */
/*<     7 continue >*/
L7:
/* SOURCE chkinput.for:2848 */
/*<       qnode=emc(j+1) >*/
    qnode = emc[j + 1];
/* SOURCE chkinput.for:2849 */
/*<       if(exnodt(6,qnode)/=null)then >*/
    if (exnodt[qnode * 9 + 6] != null) {
/* SOURCE chkinput.for:2850 */
/*<       tabadrs=emc(j+2) >*/
	tabadrs = emc[j + 2];
/* SOURCE chkinput.for:2851 */
/*<       callget_east_north(stdout,tabadrs,easting,northing) >*/
	feq_gen_get_east_north_d_(stdout, &tabadrs, &easting, &northing);
/* SOURCE chkinput.for:2855 */
/*<       if(easting<=dnull)then >*/
	if (easting <= dnull) {
/*              replace with the values found in FEQ */
/* SOURCE chkinput.for:2857 */
/*<       easting=dble(exnodt(6,qnode))/100.d0 >*/
	    easting = (doublereal) exnodt[qnode * 9 + 6] / 100.;
/* SOURCE chkinput.for:2858 */
/*<       northing=dble(exnodt(7,qnode))/100.d0 >*/
	    northing = (doublereal) exnodt[qnode * 9 + 7] / 100.;
/* SOURCE chkinput.for:2859 */
/*<       callput_east_north(stdout,tabadrs,easting,northing) >*/
	    feq_gen_put_east_north_d_(stdout, &tabadrs, &easting, &northing);
/* SOURCE chkinput.for:2862 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:2863 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:2864 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:2865 */
/*<     8 continue >*/
L8:
/* SOURCE chkinput.for:2866 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:2867 */
/*<     9 continue >*/
L9:
/* SOURCE chkinput.for:2868 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:2870 */
/*<    10 continue >*/
L10:
/* SOURCE chkinput.for:2871 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:2872 */
/*<    14 continue >*/
L14:
/*          Check for replacement of the datum for head given in the */
/*          instruction. */
/* SOURCE chkinput.for:2875 */
/*<       if(cd14_tab_datum.eq.'YES')then >*/
    if (s_cmp(feq_gen_cd14_tab_datum_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3) == 0) {
/*            Get the address of the outflow 2-D table and its datum. */
/* SOURCE chkinput.for:2877 */
/*<       adrs=emc(j+4) >*/
	adrs = emc[j + 4];
/* SOURCE chkinput.for:2878 */
/*<       hdatum=gethdd(adrs) >*/
	hdatum = gethdd_(&adrs);
/* SOURCE chkinput.for:2879 */
/*<       idum=emc(j+9) >*/
	*idum = emc[j + 9];
/* SOURCE chkinput.for:2880 */
/*<       if(abs(hdatum-rdum).gt.0.002)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(hdatum) - *rdum, dabs(feq_gen_r_d_1)) > (float).002) {
/* SOURCE chkinput.for:2881 */
/*<       write(stdout,92)hdatum,get_tabid(gettbn(adrs)),rdum >*/
	    feq_gen_io_d__293.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__293);
	    do_fio(&feq_gen_c_d_1, (char *)&hdatum, (ftnlen)sizeof(real));
	    feq_gen_i_d_1 = gettbn_(&adrs);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_7, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(feq_gen_ch_d_6, feq_gen_ch_d_7, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_6, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&(*rdum), (ftnlen)sizeof(real));
	    e_wsfe();
/*              Use it as the datum in the instruction */
/* SOURCE chkinput.for:2884 */
/*<       rdum=hdatum >*/
	    *rdum = hdatum;
/* SOURCE chkinput.for:2885 */
/*<       emc(j+9)=idum >*/
	    emc[j + 9] = *idum;
/* SOURCE chkinput.for:2886 */
/*<       endif >*/
	}
/*            Get the datum of the inflow table and check */
/* SOURCE chkinput.for:2888 */
/*<       hdatum=gethdd(emc(j+5)) >*/
	hdatum = gethdd_(&emc[j + 5]);
/* SOURCE chkinput.for:2889 */
/*<       if(abs(hdatum-rdum).gt.0.005)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(hdatum) - *rdum, dabs(feq_gen_r_d_1)) > (float).005) {
/* SOURCE chkinput.for:2890 */
/*<        >*/
	    feq_gen_io_d__294.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__294);
	    feq_gen_i_d_1 = gettbn_(&adrs);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_7, (ftnlen)16, &feq_gen_i_d_1);
	    s_copy(feq_gen_ch_d_6, feq_gen_ch_d_7, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_6, (ftnlen)16);
	    feq_gen_i_d_2 = gettbn_(&emc[j + 5]);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_9, (ftnlen)16, &feq_gen_i_d_2);
	    s_copy(feq_gen_ch_d_8, feq_gen_ch_d_9, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_8, (ftnlen)16);
	    e_wsfe();
/* SOURCE chkinput.for:2892 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:2893 */
/*<       endif >*/
    }
/*          check for middle node having a location. */
/* SOURCE chkinput.for:2895 */
/*<       qnode=emc(j+3) >*/
    qnode = emc[j + 3];
/* SOURCE chkinput.for:2896 */
/*<       if(exnodt(6,qnode)/=null)then >*/
    if (exnodt[qnode * 9 + 6] != null) {
/*            we have a location.  Extract it and store */
/*            in the function tables if the table contains */
/*            the default null value. */
/* SOURCE chkinput.for:2900 */
/*<       doi=4,7 >*/
	for (feq_gen_i_d_ = 4; feq_gen_i_d_ <= 7; ++feq_gen_i_d_) {
/* SOURCE chkinput.for:2901 */
/*<       tabadrs=emc(j+i) >*/
	    tabadrs = emc[j + feq_gen_i_d_];
/* SOURCE chkinput.for:2902 */
/*<       if(tabadrs>0)then >*/
	    if (tabadrs > 0) {
/* SOURCE chkinput.for:2903 */
/*<       callget_east_north(stdout,tabadrs,easting,northing) >*/
		feq_gen_get_east_north_d_(stdout, &tabadrs, &easting, &northing);
/* SOURCE chkinput.for:2907 */
/*<       if(easting<=dnull)then >*/
		if (easting <= dnull) {
/*                  replace with the values found in FEQ */
/* SOURCE chkinput.for:2909 */
/*<       easting=dble(exnodt(6,qnode))/100.d0 >*/
		    easting = (doublereal) exnodt[qnode * 9 + 6] / 100.;
/* SOURCE chkinput.for:2910 */
/*<       northing=dble(exnodt(7,qnode))/100.d0 >*/
		    northing = (doublereal) exnodt[qnode * 9 + 7] / 100.;
/* SOURCE chkinput.for:2911 */
/*<       callput_east_north(stdout,tabadrs,easting,northing) >*/
		    feq_gen_put_east_north_d_(stdout, &tabadrs, &easting, &northing);
/* SOURCE chkinput.for:2914 */
/*<       endif >*/
		}
/* SOURCE chkinput.for:2915 */
/*<       endif >*/
	    }
/* SOURCE chkinput.for:2916 */
/*<       enddo >*/
	}
/* SOURCE chkinput.for:2917 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:2919 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE chkinput.for:2920 */
/*<  1500 continue >*/
L1500:
/* SOURCE chkinput.for:2921 */
/*<       j=j+emc(code+1) >*/
    j += emc[code + 1];
/* SOURCE chkinput.for:2922 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE chkinput.for:2923 */
/*<  2000 continue >*/
L2000:
/* SOURCE chkinput.for:2924 */
/*<       write(stdout,51) >*/
    feq_gen_io_d__295.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__295);
    e_wsfe();
/* SOURCE chkinput.for:2925 */
/*<       return >*/
    return 0;
/* SOURCE chkinput.for:2926 */
/*<       end >*/
} /* finchk_ */

#undef rtmp
#undef rdum
#undef idum
#undef itab
#undef ftab





/* SOURCE chkinput.for:2930 */
/*<       subroutinekilc(crh5,icode,iflag) >*/
/* Subroutine */ int kilc_(char *crh5, integer *icode, integer *iflag, ftnlen 
	crh5_len)
{
    /* Initialized data */

    static char mesg[72*51+1] = " Branch number out of range                \
                              Node on a branch outside valid range          \
                          Node on a branch out of sequence or a duplicate   \
                      Upstream exterior node number out of range            \
                  Downstream exterior node number out of range              \
              AVAILABLE MESSAGE                                             \
          Invalid device type for a control structure                       \
      Message available                                                     \
  Internal table number out of valid range                                Fu\
nction table space exceeded                                           Invali\
d code for Network Matrix Control                                 AVAILABLE \
MESSAGE                                                       Network Matrix\
 Control space exceeded                                   Number of nodes at\
 a junction > 9 or < 2                                Unknown branch number \
in Ntwrk Mtrx Cntrl input                         Type must be 1,or 2 for a \
forced boundary                               Number of reservoir inflow nod\
es must be 1                              Type for point flows > 2 or < 1   \
                                      Too many point flows given            \
                                  MESSAGE AVAILABLE                         \
                              Message available                             \
                          The nodes for head must be distinct               \
                      The node for flow must equal one of the head nodes    \
                  Reservoir node duplicates an existing node                \
              Duplicate function table number                               \
          Message available                                                 \
      Too many nodes                                                        \
  Point flow invalid for upstream node                                    To\
o many branches                                                       Too ma\
ny exterior nodes                                                 Invalid op\
eration block number in CHKEX                                 Level pool res\
ervoir inflow node is not free or is in use elsewhere.    Free node on a dum\
my branch is not free or is in use elsewhere.        AVAILABLE MESSAGE      \
                                                  Invalid print out option  \
                                              Point flows no longer supporte\
d                                         Invalid option for diffuse flows  \
                                      Invalid option for wind loading       \
                                  Message available                         \
                              Message available                             \
                          Special Operation Block number out of range       \
                      Invalid option for Special Operation Block            \
                  Exterior node used as a flow node more than once          \
              Exterior node appears on more than one branch                 \
          Invalid slope source for channel control:-1,0,1, are valid        \
      This node matches another when nodes must be distinct.                \
 Message available                                                       Mes\
sage available                                                        Messag\
e available                                                       Invalid di\
rection: 1 or -1 are valid.                                   Branch has alr\
eady appeared in Ntwrk Mtrx Cntrl input.                 ";

    /* Format strings */
    static char fmt_10000[] = "(/,\002*ERR:\002,i2,\002*\002)";
    static char fmt_10101[] = "(\002 REFERENCE VALUE=\002,a5)";
    static char fmt_10200[] = "(a)";
    static char fmt_10300[] = "(/,\002 PREVIOUS ERROR FORCES CESSATION OF PR\
OCESSING.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer icd;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__297 = { 0, 0, 0, fmt_10000, 0 };
    static cilist feq_gen_io_d__299 = { 0, 0, 0, fmt_10101, 0 };
    static cilist feq_gen_io_d__300 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__301 = { 0, 0, 0, fmt_10200, 0 };
    static cilist feq_gen_io_d__302 = { 0, 0, 0, fmt_10300, 0 };


/*     + + + PURPOSE + + + */
/*     Prints out error messages and sets a flag */
/*     and adjusts the value of N.  This is a near copy of KIL. */
/* SOURCE chkinput.for:2938 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE chkinput.for:2940 */
/*<       integericode,iflag >*/
/* SOURCE chkinput.for:2941 */
/*<       charactercrh5*5 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     CRH5   - reference value that is in error */
/*     ICODE  - code number for the error message to output */
/*     IFLAG  - error flag */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE chkinput.for:2949 */
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
/*     + + + SAVED VALUES + + + */
/* SOURCE chkinput.for:2952 */
/*<       charactermesg(51)*72 >*/
/* SOURCE chkinput.for:2953 */
/*<       savemesg >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE chkinput.for:2956 */
/*<       integericd >*/
/*     + + + INTRINSICS + + + */
/* SOURCE chkinput.for:2959 */
/*<       intrinsicabs >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE chkinput.for:2962 */
/*<       datamesg(1)/' Branch number out of range'/ >*/
/* SOURCE chkinput.for:2963 */
/*<       datamesg(2)/' Node on a branch outside valid range'/ >*/
/* SOURCE chkinput.for:2964 */
/*<       datamesg(3)/' Node on a branch out of sequence or a duplicate'/ >*/
/* SOURCE chkinput.for:2965 */
/*<       datamesg(4)/' Upstream exterior node number out of range'/ >*/
/* SOURCE chkinput.for:2966 */
/*<       datamesg(5)/' Downstream exterior node number out of range'/ >*/
/* SOURCE chkinput.for:2967 */
/*<       datamesg(6)/' AVAILABLE MESSAGE '/ >*/
/* SOURCE chkinput.for:2968 */
/*<       datamesg(7)/' Invalid device type for a control structure'/ >*/
/* SOURCE chkinput.for:2969 */
/*<       datamesg(8)/' Message available'/ >*/
/* SOURCE chkinput.for:2970 */
/*<       datamesg(9)/' Internal table number out of valid range'/ >*/
/* SOURCE chkinput.for:2971 */
/*<       datamesg(10)/' Function table space exceeded'/ >*/
/* SOURCE chkinput.for:2972 */
/*<       datamesg(11)/' Invalid code for Network Matrix Control'/ >*/
/* SOURCE chkinput.for:2973 */
/*<       datamesg(12)/' AVAILABLE MESSAGE'/ >*/
/* SOURCE chkinput.for:2974 */
/*<       datamesg(13)/' Network Matrix Control space exceeded'/ >*/
/* SOURCE chkinput.for:2975 */
/*<       datamesg(14)/' Number of nodes at a junction > 9 or < 2'/ >*/
/* SOURCE chkinput.for:2976 */
/*<       datamesg(15)/' Unknown branch number in Ntwrk Mtrx Cntrl input'/ >*/
/* SOURCE chkinput.for:2977 */
/*<       datamesg(16)/' Type must be 1,or 2 for a forced boundary'/ >*/
/* SOURCE chkinput.for:2978 */
/*<       datamesg(17)/' Number of reservoir inflow nodes must be 1'/ >*/
/* SOURCE chkinput.for:2979 */
/*<       datamesg(18)/' Type for point flows > 2 or < 1'/ >*/
/* SOURCE chkinput.for:2980 */
/*<       datamesg(19)/' Too many point flows given'/ >*/
/* SOURCE chkinput.for:2981 */
/*<       datamesg(20)/' MESSAGE AVAILABLE'/ >*/
/* SOURCE chkinput.for:2982 */
/*<       datamesg(21)/' Message available'/ >*/
/* SOURCE chkinput.for:2983 */
/*<       datamesg(22)/' The nodes for head must be distinct'/ >*/
/* SOURCE chkinput.for:2984 */
/*<        >*/
/* SOURCE chkinput.for:2986 */
/*<       datamesg(24)/' Reservoir node duplicates an existing node'/ >*/
/* SOURCE chkinput.for:2987 */
/*<       datamesg(25)/' Duplicate function table number'/ >*/
/* SOURCE chkinput.for:2988 */
/*<       datamesg(26)/' Message available'/ >*/
/* SOURCE chkinput.for:2989 */
/*<       datamesg(27)/' Too many nodes'/ >*/
/* SOURCE chkinput.for:2990 */
/*<       datamesg(28)/' Point flow invalid for upstream node'/ >*/
/* SOURCE chkinput.for:2991 */
/*<       datamesg(29)/' Too many branches'/ >*/
/* SOURCE chkinput.for:2992 */
/*<       datamesg(30)/' Too many exterior nodes'/ >*/
/* SOURCE chkinput.for:2993 */
/*<       datamesg(31)/' Invalid operation block number in CHKEX'/ >*/
/* SOURCE chkinput.for:2994 */
/*<        >*/
/* SOURCE chkinput.for:2997 */
/*<        >*/
/* SOURCE chkinput.for:3000 */
/*<       datamesg(34)/'AVAILABLE MESSAGE'/ >*/
/* SOURCE chkinput.for:3001 */
/*<       datamesg(35)/' Invalid print out option'/ >*/
/* SOURCE chkinput.for:3002 */
/*<       datamesg(36)/' Point flows no longer supported'/ >*/
/* SOURCE chkinput.for:3003 */
/*<       datamesg(37)/' Invalid option for diffuse flows'/ >*/
/* SOURCE chkinput.for:3004 */
/*<       datamesg(38)/' Invalid option for wind loading'/ >*/
/* SOURCE chkinput.for:3005 */
/*<       datamesg(39)/' Message available'/ >*/
/* SOURCE chkinput.for:3006 */
/*<       datamesg(40)/' Message available'/ >*/
/* SOURCE chkinput.for:3007 */
/*<       datamesg(41)/' Special Operation Block number out of range'/ >*/
/* SOURCE chkinput.for:3008 */
/*<       datamesg(42)/' Invalid option for Special Operation Block'/ >*/
/* SOURCE chkinput.for:3009 */
/*<       datamesg(43)/' Exterior node used as a flow node more than once'/ >*/
/* SOURCE chkinput.for:3011 */
/*<       datamesg(44)/' Exterior node appears on more than one branch'/ >*/
/* SOURCE chkinput.for:3012 */
/*<        >*/
/* SOURCE chkinput.for:3014 */
/*<        >*/
/* SOURCE chkinput.for:3016 */
/*<       datamesg(47)/'Message available'/ >*/
/* SOURCE chkinput.for:3017 */
/*<       datamesg(48)/'Message available'/ >*/
/* SOURCE chkinput.for:3018 */
/*<       datamesg(49)/' Message available'/ >*/
/* SOURCE chkinput.for:3019 */
/*<       datamesg(50)/' Invalid direction: 1 or -1 are valid.'/ >*/
/* SOURCE chkinput.for:3020 */
/*<        >*/
/* SOURCE chkinput.for:3024 */
/*< 10000 format(/,'*ERR:',i2,'*') >*/
/* L10000: */
/* SOURCE chkinput.for:3025 */
/*< 10101 format(' REFERENCE VALUE=',a5) >*/
/* L10101: */
/* SOURCE chkinput.for:3026 */
/*< 10200 format(a) >*/
/* L10200: */
/* SOURCE chkinput.for:3027 */
/*< 10300 format(/,' PREVIOUS ERROR FORCES CESSATION OF PROCESSING.') >*/
/* L10300: */
/* *********************************************************************** */
/*     NOTE: DO NOT USE ICODE GREATER THAN 60 FOR SUBROUTINE */
/*     KIL. OTHERWISE DUPLICATE NUMBERS WILL APPEAR FOR ERROR */
/*     MESSAGES. */
/* SOURCE chkinput.for:3033 */
/*<       write(stdout,10000)abs(icode) >*/
    feq_gen_io_d__297.ciunit = xscom_1.stdout;
    s_wsfe(&feq_gen_io_d__297);
    feq_gen_i_d_1 = abs(*icode);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE chkinput.for:3035 */
/*<       iflag=iflag+1 >*/
    ++(*iflag);
/* SOURCE chkinput.for:3036 */
/*<       icd=abs(icode) >*/
    icd = abs(*icode);
/* SOURCE chkinput.for:3037 */
/*<       write(stdout,10101)crh5 >*/
    feq_gen_io_d__299.ciunit = xscom_1.stdout;
    s_wsfe(&feq_gen_io_d__299);
    do_fio(&feq_gen_c_d_1, crh5, (ftnlen)5);
    e_wsfe();
/* SOURCE chkinput.for:3039 */
/*<       if(icd.lt.0.or.icd.gt.51)then >*/
    if (icd < 0 || icd > 51) {
/* SOURCE chkinput.for:3040 */
/*<       write(stdout,*)' *BUG:01* INVALID ICODE IN KILC. CODE=',icd >*/
	feq_gen_io_d__300.ciunit = xscom_1.stdout;
	s_wsle(&feq_gen_io_d__300);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:01* INVALID ICODE IN KILC. CODE="), (
		ftnlen)38);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&icd, (ftnlen)sizeof(integer));
	e_wsle();
/* SOURCE chkinput.for:3041 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE chkinput.for:3042 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:3043 */
/*<       write(stdout,10200)mesg(icd) >*/
    feq_gen_io_d__301.ciunit = xscom_1.stdout;
    s_wsfe(&feq_gen_io_d__301);
    do_fio(&feq_gen_c_d_1, mesg + (icd - 1) * 72, (ftnlen)72);
    e_wsfe();
/* SOURCE chkinput.for:3044 */
/*<       if(icd.eq.10.or.icd.eq.13)then >*/
    if (icd == 10 || icd == 13) {
/* SOURCE chkinput.for:3045 */
/*<       write(stdout,10300) >*/
	feq_gen_io_d__302.ciunit = xscom_1.stdout;
	s_wsfe(&feq_gen_io_d__302);
	e_wsfe();
/* SOURCE chkinput.for:3046 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE chkinput.for:3047 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:3048 */
/*<       return >*/
    return 0;
/* SOURCE chkinput.for:3049 */
/*<       end >*/
} /* kilc_ */




/* SOURCE chkinput.for:3053 */
/*<       subroutineold14(adr,stdout,eflag) >*/
/* Subroutine */ int old14_(integer *adr, integer *stdout, integer *eflag)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:65* Table Id=\002,a,\002 is old for\
m TYPE 14. Replace\002,\002 with new form.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer l;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer lqf;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer lpfq;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern integer gettbn_(integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__309 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Check for old form of type 14 two-d table. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE chkinput.for:3061 */
/*<       integeradr,eflag,stdout >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ADR    - address of the function table in FTAB/ITAB */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     EFLAG  - flag for errors. 0- no errors, > 0 one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE chkinput.for:3069 */
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
/* INCLUDE chkinput.for:3070 */
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
/* SOURCE chkinput.for:3073 */
/*<       integerl,lpfq,lqf >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE chkinput.for:3076 */
/*<       characterget_tabid*16 >*/
/* SOURCE chkinput.for:3077 */
/*<       integergettbn >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE chkinput.for:3080 */
/*<       externalgettbn,get_tabid >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE chkinput.for:3083 */
/*<    50  >*/
/* *********************************************************************** */
/*     GET POINTER TO THE FIRST NON-ZERO FREE FLOW */
/* SOURCE chkinput.for:3088 */
/*<       lqf=itab(adr+4)+4 >*/
/* L50: */
    lqf = itab[*adr + 4] + 4;
/*     GET POINTER TO THE PARTIAL FREE FLOW LIST */
/* SOURCE chkinput.for:3092 */
/*<       lpfq=itab(adr+6) >*/
    lpfq = itab[*adr + 6];
/*     ADD OFFSET BETWEEN START OF PARTIL FREE FLOW LIST AND START */
/*     OF THE LIST OF UPSTREAM HEADS FOR THE FIRST NON-ZERO FREE */
/*     FLOW TO THE START OF THE PARTIAL FREE FLOW LIST. */
/* SOURCE chkinput.for:3098 */
/*<       l=itab(lqf+3)+lpfq >*/
    l = itab[lqf + 3] + lpfq;
/* SOURCE chkinput.for:3100 */
/*<       if(ftab(l).eq.0.0)then >*/
    if (ftab[l] == (float)0.) {
/* SOURCE chkinput.for:3101 */
/*<       write(stdout,50)get_tabid(gettbn(adr)) >*/
	feq_gen_io_d__309.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__309);
	feq_gen_i_d_1 = gettbn_(adr);
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &feq_gen_i_d_1);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	e_wsfe();
/* SOURCE chkinput.for:3102 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chkinput.for:3103 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:3105 */
/*<       return >*/
    return 0;
/* SOURCE chkinput.for:3106 */
/*<       end >*/
} /* old14_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE chkinput.for:3110 */
/*<       subroutinepmpctb(nblk,opblk,mft,eflag) >*/
/* Subroutine */ int pmpctb_(integer *nblk, integer *feq_storage_opblk, integer *mft, 
	integer *eflag)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_, ipt;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer node;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int chktab_(integer *, integer *, integer *, 
	    integer *, integer *, integer *);
    integer tbfall, tbrise, blktyp;

/*     + + + PURPOSE + + + */
/*     Find the addresses for the pump control tables in a pump */
/*     control operation block */
/* SOURCE chkinput.for:3118 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE chkinput.for:3120 */
/*<       integereflag,mft,nblk >*/
/* SOURCE chkinput.for:3121 */
/*<       integeropblk(nblk) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NBLK   - number of operation blocks */
/*     OPBLK  - pointer into the function table storage(FTAB/ITAB) for */
/*               each operation block. */
/*     MFT    - maximum function table pointer value.  Same as maximum */
/*               function table number */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE chkinput.for:3131 */
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
/* INCLUDE chkinput.for:3132 */
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
/* INCLUDE chkinput.for:3133 */
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
/* SOURCE chkinput.for:3136 */
/*<       integerblktyp,i,ipt,node,tbfall,tbrise >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE chkinput.for:3139 */
/*<       externalchktab >*/
/* *********************************************************************** */
/* SOURCE chkinput.for:3141 */
/*<       do500i=1,nblk >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> opblk(feq_storage_opblk, 1);

    /* Function Body */
    feq_gen_i_d_1 = *nblk;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE chkinput.for:3142 */
/*<       ipt=opblk(i) >*/
	ipt = opblk[feq_gen_i_d_];
/*       Extract the operation block type. */
/* SOURCE chkinput.for:3146 */
/*<       blktyp=itab(ipt+3) >*/
	blktyp = itab[ipt + 3];
/*       Skip gate operation. */
/* SOURCE chkinput.for:3148 */
/*<       if(blktyp.eq.1.or.blktyp.eq.3)goto500 >*/
	if (blktyp == 1 || blktyp == 3) {
	    goto L500;
	}
/* SOURCE chkinput.for:3150 */
/*<       ipt=ipt+12 >*/
	ipt += 12;
/* SOURCE chkinput.for:3151 */
/*<   100 continue >*/
L100:
/* SOURCE chkinput.for:3152 */
/*<       node=itab(ipt) >*/
	node = itab[ipt];
/* SOURCE chkinput.for:3153 */
/*<       if(node.eq.0)goto410 >*/
	if (node == 0) {
	    goto L410;
	}
/* SOURCE chkinput.for:3154 */
/*<       tbrise=itab(ipt+5) >*/
	tbrise = itab[ipt + 5];
/* SOURCE chkinput.for:3155 */
/*<       callchktab(2,std6,ftpnt,mft,tbrise,eflag) >*/
	chktab_(&feq_gen_c_d_2, &feq_gen_stdun_com_d_1.std6, ftablea_1.ftpnt, mft, &tbrise, 
		eflag);
/* SOURCE chkinput.for:3159 */
/*<       itab(ipt+5)=tbrise >*/
	itab[ipt + 5] = tbrise;
/* SOURCE chkinput.for:3161 */
/*<       tbfall=itab(ipt+6) >*/
	tbfall = itab[ipt + 6];
/* SOURCE chkinput.for:3162 */
/*<       callchktab(2,std6,ftpnt,mft,tbfall,eflag) >*/
	chktab_(&feq_gen_c_d_2, &feq_gen_stdun_com_d_1.std6, ftablea_1.ftpnt, mft, &tbfall, 
		eflag);
/* SOURCE chkinput.for:3166 */
/*<       itab(ipt+6)=tbfall >*/
	itab[ipt + 6] = tbfall;
/*         Set the initial table to rising stage. */
/* SOURCE chkinput.for:3170 */
/*<       itab(ipt+7)=tbrise >*/
	itab[ipt + 7] = tbrise;
/* SOURCE chkinput.for:3172 */
/*<       ipt=ipt+17 >*/
	ipt += 17;
/* SOURCE chkinput.for:3173 */
/*<       goto100 >*/
	goto L100;
/* SOURCE chkinput.for:3174 */
/*<   410 continue >*/
L410:
/* SOURCE chkinput.for:3176 */
/*<   500 continue >*/
L500:
	;
    }
/* SOURCE chkinput.for:3177 */
/*<       return >*/
    return 0;
/* SOURCE chkinput.for:3178 */
/*<       end >*/
} /* pmpctb_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE chkinput.for:3182 */
/*<       subroutinefind_gate_table_address(stdout,nblk,opblk,mft,eflag) >*/
/* Subroutine */ int feq_gen_find_gate_table_address_d_(integer *stdout, integer *nblk,
	 integer *feq_storage_opblk, integer *mft, integer *eflag)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3;

    /* Local variables */
    integer feq_gen_neg_flag_d_, feq_gen_body_inc_d_, feq_gen_low_adrs_d_, feq_gen_i_d_, j, feq_gen_high_adrs_d_, 
	    feq_gen_tab_offset_d_, feq_gen_tab_number_d_, ipt;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer tabn, node;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int chktab_(integer *, integer *, integer *, 
	    integer *, integer *, integer *);
    integer blktyp;

/*     + + + PURPOSE + + + */
/*     Find the addresses for the control tables in a GATETABL */
/*     control operation block */
/* SOURCE chkinput.for:3190 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE chkinput.for:3192 */
/*<       integereflag,mft,nblk,stdout >*/
/* SOURCE chkinput.for:3193 */
/*<       integeropblk(nblk) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NBLK   - number of operation blocks */
/*     OPBLK  - pointer into the function table storage(FTAB/ITAB) for */
/*               each operation block. */
/*     MFT    - maximum function table pointer value.  Same as maximum */
/*               function table number */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE chkinput.for:3203 */
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
/* INCLUDE chkinput.for:3204 */
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
/* SOURCE chkinput.for:3207 */
/*<        >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE chkinput.for:3211 */
/*<       externalchktab >*/
/* *********************************************************************** */
/* SOURCE chkinput.for:3213 */
/*<       do500i=1,nblk >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> opblk(feq_storage_opblk, 1);

    /* Function Body */
    feq_gen_i_d_1 = *nblk;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE chkinput.for:3214 */
/*<       ipt=opblk(i) >*/
	ipt = opblk[feq_gen_i_d_];
/*       Extract the operation block type. */
/* SOURCE chkinput.for:3218 */
/*<       blktyp=itab(ipt+3) >*/
	blktyp = itab[ipt + 3];
/*       Skip gate operation. */
/* SOURCE chkinput.for:3220 */
/*<       if(blktyp.eq.3)then >*/
	if (blktyp == 3) {
/* SOURCE chkinput.for:3222 */
/*<       ipt=ipt+12 >*/
	    ipt += 12;
/* SOURCE chkinput.for:3223 */
/*<   100 continue >*/
L100:
/* SOURCE chkinput.for:3224 */
/*<       node=itab(ipt) >*/
	    node = itab[ipt];
/* SOURCE chkinput.for:3225 */
/*<       if(node.eq.0)goto410 >*/
	    if (node == 0) {
		goto L410;
	    }
/* SOURCE chkinput.for:3227 */
/*<       do300tab_offset=7,10,3 >*/
	    for (feq_gen_tab_offset_d_ = 7; feq_gen_tab_offset_d_ <= 10; feq_gen_tab_offset_d_ += 3) {
/* SOURCE chkinput.for:3228 */
/*<       tab_number=itab(ipt+tab_offset) >*/
		feq_gen_tab_number_d_ = itab[ipt + feq_gen_tab_offset_d_];
/* SOURCE chkinput.for:3229 */
/*<       if(tab_number.lt.0)then >*/
		if (feq_gen_tab_number_d_ < 0) {
/*               Catch flag for a selection table. */
/* SOURCE chkinput.for:3231 */
/*<       neg_flag=1 >*/
		    feq_gen_neg_flag_d_ = 1;
/* SOURCE chkinput.for:3232 */
/*<       tab_number=-tab_number >*/
		    feq_gen_tab_number_d_ = -feq_gen_tab_number_d_;
/* SOURCE chkinput.for:3233 */
/*<       else >*/
		} else {
/* SOURCE chkinput.for:3234 */
/*<       neg_flag=0 >*/
		    feq_gen_neg_flag_d_ = 0;
/* SOURCE chkinput.for:3235 */
/*<       endif >*/
		}
/* SOURCE chkinput.for:3236 */
/*<       if(neg_flag.eq.0)then >*/
		if (feq_gen_neg_flag_d_ == 0) {
/* SOURCE chkinput.for:3237 */
/*<       callchktab(10,stdout,ftpnt,mft,tab_number,eflag) >*/
		    chktab_(&feq_gen_c_d_10, stdout, ftablea_1.ftpnt, mft, &
			    feq_gen_tab_number_d_, eflag);
/* SOURCE chkinput.for:3241 */
/*<       else >*/
		} else {
/* SOURCE chkinput.for:3242 */
/*<       callchktab(2,stdout,ftpnt,mft,tab_number,eflag) >*/
		    chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, mft, &
			    feq_gen_tab_number_d_, eflag);
/* SOURCE chkinput.for:3246 */
/*<       if(eflag.eq.0)then >*/
		    if (*eflag == 0) {
/*                 Selection table exists.  Check its contents to make sure */
/*                 the tables referenced in it also exist! */
/* SOURCE chkinput.for:3249 */
/*<       low_adrs=tab_number+off234 >*/
			feq_gen_low_adrs_d_ = feq_gen_tab_number_d_ + 22;
/* SOURCE chkinput.for:3250 */
/*<       high_adrs=itab(tab_number) >*/
			feq_gen_high_adrs_d_ = itab[feq_gen_tab_number_d_];
/* SOURCE chkinput.for:3251 */
/*<       body_inc=2 >*/
			feq_gen_body_inc_d_ = 2;
/* SOURCE chkinput.for:3253 */
/*<       do200j=low_adrs,high_adrs,body_inc >*/
			feq_gen_i_d_2 = feq_gen_high_adrs_d_;
			feq_gen_i_d_3 = feq_gen_body_inc_d_;
			for (j = feq_gen_low_adrs_d_; feq_gen_i_d_3 < 0 ? j >= feq_gen_i_d_2 : j <= feq_gen_i_d_2;
				 j += feq_gen_i_d_3) {
/*                   Round the table value to the nearest integer and treat */
/*                   it like a table number. */
/* SOURCE chkinput.for:3256 */
/*<       tabn=int(ftab(j+1)+0.5) >*/
			    tabn = (integer) (static_cast<double>(ftab[j + 1]) + (float).5);
/* SOURCE chkinput.for:3257 */
/*<       callchktab(10,stdout,ftpnt,mft,tabn,eflag) >*/
			    chktab_(&feq_gen_c_d_10, stdout, ftablea_1.ftpnt, mft, &
				    tabn, eflag);
/* SOURCE chkinput.for:3261 */
/*<   200 continue >*/
/* L200: */
			}
/* SOURCE chkinput.for:3262 */
/*<       endif >*/
		    }
/* SOURCE chkinput.for:3263 */
/*<       endif >*/
		}
/* SOURCE chkinput.for:3265 */
/*<       if(neg_flag.eq.0)then >*/
		if (feq_gen_neg_flag_d_ == 0) {
/* SOURCE chkinput.for:3266 */
/*<       itab(ipt+tab_offset)=tab_number >*/
		    itab[ipt + feq_gen_tab_offset_d_] = feq_gen_tab_number_d_;
/* SOURCE chkinput.for:3267 */
/*<       else >*/
		} else {
/* SOURCE chkinput.for:3268 */
/*<       itab(ipt+tab_offset)=-tab_number >*/
		    itab[ipt + feq_gen_tab_offset_d_] = -feq_gen_tab_number_d_;
/* SOURCE chkinput.for:3269 */
/*<       endif >*/
		}
/* SOURCE chkinput.for:3271 */
/*<   300 continue >*/
/* L300: */
	    }
/* SOURCE chkinput.for:3272 */
/*<       ipt=ipt+17 >*/
	    ipt += 17;
/* SOURCE chkinput.for:3273 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE chkinput.for:3274 */
/*<   410 continue >*/
L410:
/* SOURCE chkinput.for:3275 */
/*<       endif >*/
	    ;
	}
/* SOURCE chkinput.for:3276 */
/*<   500 continue >*/
/* L500: */
    }
/* SOURCE chkinput.for:3277 */
/*<       return >*/
    return 0;
/* SOURCE chkinput.for:3278 */
/*<       end >*/
} /* find_gate_table_address__ */

#undef rtmp
#undef itab
#undef ftab


/*     *********** */
/*     *         * */
/*     * SET_SPOUT_OPTIONS */
/*     *         * */
/*     *********** */
/* SOURCE chkinput.for:3285 */
/*<       subroutineset_spout_options(stdout,cin,eflag) >*/
/* Subroutine */ int feq_gen_set_spout_options_d_(integer *stdout, char *cin, integer *
	eflag, ftnlen cin_len)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *ERR:62* \002,a8,\002 is a bad Special Out\
put option.\002)";
    static char fmt_51[] = "(\002 *ERR:68* Too many Special Output options. \
Maximum\002,\002 allowed=\002,i5)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer i_len(char *, ftnlen), s_cmp(char *, char *, ftnlen, ftnlen), 
	    s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer feq_gen_i_d_, j, is, it, iend;
    char feq_gen_name_d_[8];
    extern /* Subroutine */ int lstab_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen), getnxt_(char *, integer *, integer *, char *, 
	    ftnlen, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__339 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__340 = { 0, 0, 0, fmt_51, 0 };


/*     Set the optional special output options. */
/* SOURCE chkinput.for:3290 */
/*<       implicitnone >*/
/* SOURCE chkinput.for:3291 */
/*<       character*(*)cin >*/
/* SOURCE chkinput.for:3293 */
/*<       integereflag,stdout >*/
/* INCLUDE chkinput.for:3296 */
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
/* INCLUDE chkinput.for:3297 */
/*     Common block for extending the special output options */
/* SOURCE spout.cmn:3 */
/*<        >*/
/* SOURCE spout.cmn:8 */
/*<        >*/
/* SOURCE spout.cmn:15 */
/*<        >*/
/* SOURCE spout.cmn:21 */
/*<        >*/
/* SOURCE spout.cmn:25 */
/*<        >*/
/* SOURCE spout.cmn:29 */
/*<       common/spoutc/spout_item_label,spout_item_name,extra_buffer >*/
/* SOURCE spout.cmn:33 */
/*<       save/spouta/,/spoutc/ >*/
/*     Local */
/* SOURCE chkinput.for:3301 */
/*<       charactername*8 >*/
/* SOURCE chkinput.for:3302 */
/*<       integeri,j,iend,is,it >*/
/* SOURCE chkinput.for:3304 */
/*<       intrinsiclen >*/
/*     **************************FORMATS********************************* */
/* SOURCE chkinput.for:3306 */
/*<    50 format(' *ERR:62* ',a8,' is a bad Special Output option.') >*/
/* SOURCE chkinput.for:3307 */
/*<    51  >*/
/* *********************************************************************** */
/* SOURCE chkinput.for:3310 */
/*<       iend=len(cin) >*/
/* L50: */
/* L51: */
    iend = i_len(cin, cin_len);
/* SOURCE chkinput.for:3311 */
/*<       is=1 >*/
    is = 1;
/* SOURCE chkinput.for:3314 */
/*<   100 continue >*/
L100:
/* SOURCE chkinput.for:3315 */
/*<       callgetnxt(cin,is,it,name) >*/
    getnxt_(cin, &is, &it, feq_gen_name_d_, cin_len, (ftnlen)8);
/* SOURCE chkinput.for:3318 */
/*<       is=it >*/
    is = it;
/* SOURCE chkinput.for:3319 */
/*<       if(name.ne.' ')then >*/
    if (s_cmp(feq_gen_name_d_, const_cast<char*>(" "), (ftnlen)8, (ftnlen)1) != 0) {
/*         Find the name in the table. */
/* SOURCE chkinput.for:3322 */
/*<       calllstab(name,spout_item_name,mnsprow,i) >*/
	lstab_(feq_gen_name_d_, spoutc_1.feq_gen_spout_item_name_d_, &feq_gen_c_d_8, &feq_gen_i_d_, (ftnlen)8, (
		ftnlen)8);
/* SOURCE chkinput.for:3325 */
/*<       if(i.eq.0)then >*/
	if (feq_gen_i_d_ == 0) {
/* SOURCE chkinput.for:3326 */
/*<       write(stdout,50)name >*/
	    feq_gen_io_d__339.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__339);
	    do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)8);
	    e_wsfe();
/* SOURCE chkinput.for:3327 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE chkinput.for:3328 */
/*<       else >*/
	} else {
/* SOURCE chkinput.for:3329 */
/*<       spout_knt=spout_knt+1 >*/
	    ++spouta_1.feq_gen_spout_knt_d_;
/* SOURCE chkinput.for:3330 */
/*<       if(spout_knt.gt.mnsprow)then >*/
	    if (spouta_1.feq_gen_spout_knt_d_ > 8) {
/* SOURCE chkinput.for:3331 */
/*<       write(stdout,51)mnsprow >*/
		feq_gen_io_d__340.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__340);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_8, (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE chkinput.for:3332 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE chkinput.for:3333 */
/*<       spout_knt=mnsprow >*/
		spouta_1.feq_gen_spout_knt_d_ = 8;
/* SOURCE chkinput.for:3334 */
/*<       endif >*/
	    }
/* SOURCE chkinput.for:3335 */
/*<       spout_item(spout_knt)=i >*/
	    spouta_1.feq_gen_spout_item_d_[spouta_1.feq_gen_spout_knt_d_ - 1] = feq_gen_i_d_;
/* SOURCE chkinput.for:3337 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:3338 */
/*<       endif >*/
    }
/* SOURCE chkinput.for:3339 */
/*<       if(is.ge.iend)goto200 >*/
    if (is >= iend) {
	goto L200;
    }
/* SOURCE chkinput.for:3340 */
/*<       goto100 >*/
    goto L100;
/* SOURCE chkinput.for:3341 */
/*<   200 continue >*/
L200:
/*     Set flags for table lookup so that it is done once */
/*     if needed. */
/* SOURCE chkinput.for:3344 */
/*<       need_lookup=0 >*/
    spouta_1.feq_gen_need_lookup_d_ = 0;
/* SOURCE chkinput.for:3345 */
/*<       do490j=1,spout_knt >*/
    feq_gen_i_d_1 = spouta_1.feq_gen_spout_knt_d_;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE chkinput.for:3346 */
/*<       if(spout_item_value(spout_item(j)).gt.10)then >*/
	if (spouta_1.feq_gen_spout_item_value_d_[spouta_1.feq_gen_spout_item_d_[j - 1] - 1] > 
		10) {
/* SOURCE chkinput.for:3347 */
/*<       need_lookup=1 >*/
	    spouta_1.feq_gen_need_lookup_d_ = 1;
/* SOURCE chkinput.for:3348 */
/*<       goto491 >*/
	    goto L491;
/* SOURCE chkinput.for:3349 */
/*<       endif >*/
	}
/* SOURCE chkinput.for:3350 */
/*<   490 continue >*/
/* L490: */
    }
/* SOURCE chkinput.for:3351 */
/*<   491 continue >*/
L491:
/* SOURCE chkinput.for:3353 */
/*<       return >*/
    return 0;
/* SOURCE chkinput.for:3354 */
/*<       end >*/
} /* set_spout_options__ */

#ifdef __cplusplus
	}
#endif
