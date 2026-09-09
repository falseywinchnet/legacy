/* block.f -- translated by f2c (version 20240504).
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

/* COMMON spouta_ is declared in common.hpp. */

#define spouta_1 spouta_

/* COMMON spoutc_ is declared in common.hpp. */

#define spoutc_1 spoutc_

/* COMMON offcom_ is declared in common.hpp. */

#define offcom_1 offcom_




/* SOURCE block.for:4 */
/*<       subroutinespout_init() >*/
/* Subroutine */ int feq_gen_spout_init_d_()
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j;

/*     + + + PURPOSE + + + */
/*     Initialize the list of names for special output item */
/*     names. */
/* SOURCE block.for:10 */
/*<       implicitnone >*/
/* SOURCE block.for:12 */
/*<       integeri,j >*/
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE block.for:15 */
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
/* INCLUDE block.for:16 */
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
/* *********************************************************************** */
/* SOURCE block.for:19 */
/*<       spout_item_name(1)='V' >*/
    s_copy(spoutc_1.feq_gen_spout_item_name_d_, const_cast<char*>("V"), (ftnlen)8, (ftnlen)1);
/* SOURCE block.for:20 */
/*<       spout_item_name(2)='MCV' >*/
    s_copy(spoutc_1.feq_gen_spout_item_name_d_ + 8, const_cast<char*>("MCV"), (ftnlen)8, (ftnlen)3);
/* SOURCE block.for:21 */
/*<       spout_item_name(3)='FPV' >*/
    s_copy(spoutc_1.feq_gen_spout_item_name_d_ + 16, const_cast<char*>("FPV"), (ftnlen)8, (ftnlen)3);
/* SOURCE block.for:22 */
/*<       spout_item_name(4)='A' >*/
    s_copy(spoutc_1.feq_gen_spout_item_name_d_ + 24, const_cast<char*>("A"), (ftnlen)8, (ftnlen)1);
/* SOURCE block.for:23 */
/*<       spout_item_name(5)='MCA' >*/
    s_copy(spoutc_1.feq_gen_spout_item_name_d_ + 32, const_cast<char*>("MCA"), (ftnlen)8, (ftnlen)3);
/* SOURCE block.for:24 */
/*<       spout_item_name(6)='FPA' >*/
    s_copy(spoutc_1.feq_gen_spout_item_name_d_ + 40, const_cast<char*>("FPA"), (ftnlen)8, (ftnlen)3);
/* SOURCE block.for:25 */
/*<       spout_item_name(7)='MCQ' >*/
    s_copy(spoutc_1.feq_gen_spout_item_name_d_ + 48, const_cast<char*>("MCQ"), (ftnlen)8, (ftnlen)3);
/* SOURCE block.for:26 */
/*<       spout_item_name(8)='FPQ' >*/
    s_copy(spoutc_1.feq_gen_spout_item_name_d_ + 56, const_cast<char*>("FPQ"), (ftnlen)8, (ftnlen)3);
/* SOURCE block.for:28 */
/*<       spout_item_label(1)='Velocity' >*/
    s_copy(spoutc_1.feq_gen_spout_item_label_d_, const_cast<char*>("Velocity"), (ftnlen)10, (ftnlen)8);
/* SOURCE block.for:29 */
/*<       spout_item_label(2)='MnChnVlcty' >*/
    s_copy(spoutc_1.feq_gen_spout_item_label_d_ + 10, const_cast<char*>("MnChnVlcty"), (ftnlen)10, (
	    ftnlen)10);
/* SOURCE block.for:30 */
/*<       spout_item_label(3)='FdPlnVlcty' >*/
    s_copy(spoutc_1.feq_gen_spout_item_label_d_ + 20, const_cast<char*>("FdPlnVlcty"), (ftnlen)10, (
	    ftnlen)10);
/* SOURCE block.for:31 */
/*<       spout_item_label(4)='Area' >*/
    s_copy(spoutc_1.feq_gen_spout_item_label_d_ + 30, const_cast<char*>("Area"), (ftnlen)10, (ftnlen)4);
/* SOURCE block.for:32 */
/*<       spout_item_label(5)='MnChnArea' >*/
    s_copy(spoutc_1.feq_gen_spout_item_label_d_ + 40, const_cast<char*>("MnChnArea"), (ftnlen)10, (ftnlen)
	    9);
/* SOURCE block.for:33 */
/*<       spout_item_label(6)='FdPlnArea' >*/
    s_copy(spoutc_1.feq_gen_spout_item_label_d_ + 50, const_cast<char*>("FdPlnArea"), (ftnlen)10, (ftnlen)
	    9);
/* SOURCE block.for:34 */
/*<       spout_item_label(7)='MnChnFlow' >*/
    s_copy(spoutc_1.feq_gen_spout_item_label_d_ + 60, const_cast<char*>("MnChnFlow"), (ftnlen)10, (ftnlen)
	    9);
/* SOURCE block.for:35 */
/*<       spout_item_label(8)='FdPlnFlow' >*/
    s_copy(spoutc_1.feq_gen_spout_item_label_d_ + 70, const_cast<char*>("FdPlnFlow"), (ftnlen)10, (ftnlen)
	    9);
/* SOURCE block.for:37 */
/*<       spout_item_value(1)=mean_velocity >*/
    spouta_1.feq_gen_spout_item_value_d_[0] = 2;
/* SOURCE block.for:38 */
/*<       spout_item_value(2)=main_channel_velocity >*/
    spouta_1.feq_gen_spout_item_value_d_[1] = 22;
/* SOURCE block.for:39 */
/*<       spout_item_value(3)=flood_plain_velocity >*/
    spouta_1.feq_gen_spout_item_value_d_[2] = 23;
/* SOURCE block.for:40 */
/*<       spout_item_value(4)=total_area >*/
    spouta_1.feq_gen_spout_item_value_d_[3] = 1;
/* SOURCE block.for:41 */
/*<       spout_item_value(5)=main_channel_area >*/
    spouta_1.feq_gen_spout_item_value_d_[4] = 20;
/* SOURCE block.for:42 */
/*<       spout_item_value(6)=flood_plain_area >*/
    spouta_1.feq_gen_spout_item_value_d_[5] = 21;
/* SOURCE block.for:43 */
/*<       spout_item_value(7)=main_channel_flow >*/
    spouta_1.feq_gen_spout_item_value_d_[6] = 25;
/* SOURCE block.for:44 */
/*<       spout_item_value(8)=flood_plain_flow >*/
    spouta_1.feq_gen_spout_item_value_d_[7] = 24;
/* SOURCE block.for:46 */
/*<       doi=1,mnsout >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 250; ++feq_gen_i_d_) {
/* SOURCE block.for:47 */
/*<       doj=1,mnsprow >*/
	for (j = 1; j <= 8; ++j) {
/* SOURCE block.for:48 */
/*<       extra_buffer(i,j)='        ' >*/
	    s_copy(spoutc_1.feq_gen_extra_buffer_d_ + (feq_gen_i_d_ + j * 250 - 251 << 3), 
		    const_cast<char*>("        "), (ftnlen)8, (ftnlen)8);
/* SOURCE block.for:49 */
/*<       enddo >*/
	}
/* SOURCE block.for:50 */
/*<       enddo >*/
    }
/* SOURCE block.for:51 */
/*<       end >*/
    return 0;
} /* spout_init__ */




/* SOURCE block.for:55 */
/*<       subroutinexoffin() >*/
/* Subroutine */ int xoffin_()
{
/*     + + + PURPOSE + + + */
/*     Initialize the offset list for cross sections */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE block.for:61 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + DATA INITIALIZATIONS + + + */
/*     DATA OFFVEC/6,10*0,8,7*0,5, 6, 8, 7, 8, 10, */
/*    A      4*0, 7, 8, 11, 11, 12, 15/ */
/* *********************************************************************** */
/* SOURCE block.for:67 */
/*<       offvec(1)=6 >*/
    offcom_1.offvec[0] = 6;
/* SOURCE block.for:68 */
/*<       offvec(2)=0 >*/
    offcom_1.offvec[1] = 0;
/* SOURCE block.for:69 */
/*<       offvec(3)=0 >*/
    offcom_1.offvec[2] = 0;
/* SOURCE block.for:70 */
/*<       offvec(4)=0 >*/
    offcom_1.offvec[3] = 0;
/* SOURCE block.for:71 */
/*<       offvec(5)=0 >*/
    offcom_1.offvec[4] = 0;
/* SOURCE block.for:72 */
/*<       offvec(6)=0 >*/
    offcom_1.offvec[5] = 0;
/* SOURCE block.for:73 */
/*<       offvec(7)=0 >*/
    offcom_1.offvec[6] = 0;
/* SOURCE block.for:74 */
/*<       offvec(8)=0 >*/
    offcom_1.offvec[7] = 0;
/* SOURCE block.for:75 */
/*<       offvec(9)=0 >*/
    offcom_1.offvec[8] = 0;
/* SOURCE block.for:76 */
/*<       offvec(10)=0 >*/
    offcom_1.offvec[9] = 0;
/* SOURCE block.for:77 */
/*<       offvec(11)=0 >*/
    offcom_1.offvec[10] = 0;
/* SOURCE block.for:78 */
/*<       offvec(12)=8 >*/
    offcom_1.offvec[11] = 8;
/* SOURCE block.for:79 */
/*<       offvec(13)=0 >*/
    offcom_1.offvec[12] = 0;
/* SOURCE block.for:80 */
/*<       offvec(14)=0 >*/
    offcom_1.offvec[13] = 0;
/* SOURCE block.for:81 */
/*<       offvec(15)=0 >*/
    offcom_1.offvec[14] = 0;
/* SOURCE block.for:82 */
/*<       offvec(16)=0 >*/
    offcom_1.offvec[15] = 0;
/* SOURCE block.for:83 */
/*<       offvec(17)=0 >*/
    offcom_1.offvec[16] = 0;
/* SOURCE block.for:84 */
/*<       offvec(18)=0 >*/
    offcom_1.offvec[17] = 0;
/* SOURCE block.for:85 */
/*<       offvec(19)=0 >*/
    offcom_1.offvec[18] = 0;
/* SOURCE block.for:86 */
/*<       offvec(20)=5 >*/
    offcom_1.offvec[19] = 5;
/* SOURCE block.for:87 */
/*<       offvec(21)=6 >*/
    offcom_1.offvec[20] = 6;
/* SOURCE block.for:88 */
/*<       offvec(22)=8 >*/
    offcom_1.offvec[21] = 8;
/* SOURCE block.for:89 */
/*<       offvec(23)=7 >*/
    offcom_1.offvec[22] = 7;
/* SOURCE block.for:90 */
/*<       offvec(24)=8 >*/
    offcom_1.offvec[23] = 8;
/* SOURCE block.for:91 */
/*<       offvec(25)=10 >*/
    offcom_1.offvec[24] = 10;
/* SOURCE block.for:92 */
/*<       offvec(26)=0 >*/
    offcom_1.offvec[25] = 0;
/* SOURCE block.for:93 */
/*<       offvec(27)=0 >*/
    offcom_1.offvec[26] = 0;
/* SOURCE block.for:94 */
/*<       offvec(28)=0 >*/
    offcom_1.offvec[27] = 0;
/* SOURCE block.for:95 */
/*<       offvec(29)=0 >*/
    offcom_1.offvec[28] = 0;
/* SOURCE block.for:96 */
/*<       offvec(30)=7 >*/
    offcom_1.offvec[29] = 7;
/* SOURCE block.for:97 */
/*<       offvec(31)=8 >*/
    offcom_1.offvec[30] = 8;
/* SOURCE block.for:98 */
/*<       offvec(32)=11 >*/
    offcom_1.offvec[31] = 11;
/* SOURCE block.for:99 */
/*<       offvec(33)=11 >*/
    offcom_1.offvec[32] = 11;
/* SOURCE block.for:100 */
/*<       offvec(34)=12 >*/
    offcom_1.offvec[33] = 12;
/* SOURCE block.for:101 */
/*<       offvec(35)=15 >*/
    offcom_1.offvec[34] = 15;
/* SOURCE block.for:102 */
/*<       end >*/
    return 0;
} /* xoffin_ */

#ifdef __cplusplus
	}
#endif
