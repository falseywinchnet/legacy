/* output.f -- translated by f2c (version 20240504).
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

/* COMMON enothr_ is declared in common.hpp. */

#define enothr_1 enothr_

/* COMMON enothc_ is declared in common.hpp. */

#define enothc_1 enothc_

/* COMMON bnothr_ is declared in common.hpp. */

#define bnothr_1 bnothr_

/* COMMON bnothc_ is declared in common.hpp. */

#define bnothc_1 bnothc_

/* COMMON inbr_ is declared in common.hpp. */

#define inbr_1 inbr_

/* COMMON inen_ is declared in common.hpp. */

#define inen_1 inen_

/* COMMON inenc_ is declared in common.hpp. */

#define inenc_1 inenc_

/* COMMON ftable_ is declared in common.hpp. */

#define ftable_1 ftable_

/* COMMON ftablea_ is declared in common.hpp. */

#define ftablea_1 ftablea_

/* COMMON ftablec_ is declared in common.hpp. */

#define ftablec_1 ftablec_

/* COMMON bnelem_ is declared in common.hpp. */

#define bnelem_1 bnelem_

/* COMMON bnpond_ is declared in common.hpp. */

#define bnpond_1 bnpond_

/* COMMON enelem_ is declared in common.hpp. */

#define enelem_1 enelem_

/* COMMON tamcom_ is declared in common.hpp. */

#define tamcom_1 tamcom_

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* COMMON bnrslt_ is declared in common.hpp. */

#define bnrslt_1 bnrslt_

/* COMMON enrslt_ is declared in common.hpp. */

#define enrslt_1 enrslt_

/* COMMON julian_ is declared in common.hpp. */

#define julian_1 julian_

/* COMMON miscon_ is declared in common.hpp. */

#define miscon_1 miscon_

/* COMMON namcom_ is declared in common.hpp. */

#define namcom_1 namcom_

/* COMMON gate1_ is declared in common.hpp. */

#define gate1_1 gate1_

/* COMMON gate2_ is declared in common.hpp. */

#define gate2_1 gate2_

/* COMMON mhenry_ is declared in common.hpp. */

#define mhenry_1 mhenry_

/* COMMON spouta_ is declared in common.hpp. */

#define spouta_1 spouta_

/* COMMON spoutc_ is declared in common.hpp. */

#define spoutc_1 spoutc_

/* COMMON rdcom_ is declared in common.hpp. */

#define rdcom_1 rdcom_

/* COMMON rdcomc_ is declared in common.hpp. */

#define rdcomc_1 rdcomc_

/* COMMON matcom_ is declared in common.hpp. */

#define matcom_1 matcom_

/* COMMON matcom2_ is declared in common.hpp. */

#define matcom2_1 matcom2_

/* COMMON dtendef_ is declared in common.hpp. */

#define dtendef_1 dtendef_

/* COMMON dtendefc_ is declared in common.hpp. */

#define dtendefc_1 dtendefc_

/* COMMON wrcom_ is declared in common.hpp. */

#define wrcom_1 wrcom_

/* COMMON wrcomc_ is declared in common.hpp. */

#define wrcomc_1 wrcomc_

/* COMMON wrcomd_ is declared in common.hpp. */

#define wrcomd_1 wrcomd_

/* COMMON titlec_ is declared in common.hpp. */

#define titlec_1 titlec_

/* COMMON titlei_ is declared in common.hpp. */

#define titlei_1 titlei_

/* COMMON homec_ is declared in common.hpp. */

#define homec_1 homec_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_2 = 2;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_0 = 0;
static integer feq_gen_c_d_17 = 17;
static integer c_b958 = 120000;

/* Routines used in creating and checking output files of various kinds */



/* SOURCE output.for:6 */
/*<       subroutinenon_conv_summary(stdout,nex,nbn,nbra,brpt) >*/
/* Subroutine */ int feq_gen_non_conv_summary_d_(integer *stdout, integer *nex, 
	integer *nbn, integer *nbra, integer *feq_storage_brpt)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 Analysis of Non-Convergence Events\002\
,/,\002  Exterior\002,\002 nodes appearing as last location of maximum relat\
ive\002,\002 correction.\002,/,\002   Node Count Fraction\002)";
    static char fmt_52[] = "(\002 \002,1x,a5,i6,f9.2)";
    static char fmt_54[] = "(/,\002  Branch\002,\002 nodes appearing as last\
 location of maximum relative\002,\002 correction.\002,/,\002  Branch   Node\
 Count Fraction\002)";
    static char fmt_56[] = "(\002  \002,i6,i7,i6,f9.2)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    real fraction;
    integer feq_gen_i_d_, j, feq_gen_user_node_d_, knt;
    real fknt;
    integer fnode, lnode, snode, count;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__4 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__7 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__8 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__14 = { 0, 0, 0, fmt_56, 0 };


/*     Output a summary of the final location appearing when */
/*     convergence fails. */
/* SOURCE output.for:11 */
/*<       implicitnone >*/
/* SOURCE output.for:12 */
/*<       integernbra,nex,nbn,stdout >*/
/* SOURCE output.for:13 */
/*<       integerbrpt(8,nbra) >*/
/*     Common blocks */
/* INCLUDE output.for:18 */
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
/* INCLUDE output.for:19 */
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
/* INCLUDE output.for:20 */
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
/* INCLUDE output.for:21 */
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

/*     Local */
/* SOURCE output.for:25 */
/*<       integeri,j,knt,count,fnode,lnode,snode,user_node >*/
/* SOURCE output.for:27 */
/*<       realfknt,fraction >*/
/*     ******************************FORMATS***************************** */
/* SOURCE output.for:29 */
/*<    50  >*/
/* SOURCE output.for:32 */
/*<    52 format(' ',1x,a5,i6,f9.2) >*/
/* SOURCE output.for:33 */
/*<    54  >*/
/* SOURCE output.for:36 */
/*<    56 format('  ',i6,i7,i6,f9.2) >*/
/* *********************************************************************** */
/* SOURCE output.for:38 */
/*<       knt=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
/* L56: */
    knt = 0;
/* SOURCE output.for:39 */
/*<       do100i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE output.for:40 */
/*<       knt=knt+non_conv_enode(i) >*/
	knt += enothr_1.feq_gen_non_conv_enode_d_[feq_gen_i_d_ - 1];
/* SOURCE output.for:41 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE output.for:43 */
/*<       do105i=1,nbn >*/
    feq_gen_i_d_1 = *nbn;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE output.for:44 */
/*<       knt=knt+non_conv_bnode(i) >*/
	knt += bnothr_1.feq_gen_non_conv_bnode_d_[feq_gen_i_d_ - 1];
/* SOURCE output.for:45 */
/*<   105 continue >*/
/* L105: */
    }
/* SOURCE output.for:47 */
/*<       fknt=real(knt) >*/
    fknt = (real) knt;
/* SOURCE output.for:49 */
/*<       if(knt.gt.0)then >*/
    if (knt > 0) {
/* SOURCE output.for:50 */
/*<       write(stdout,50) >*/
	feq_gen_io_d__4.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__4);
	e_wsfe();
/* SOURCE output.for:51 */
/*<       do110i=1,nex >*/
	feq_gen_i_d_1 = *nex;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE output.for:52 */
/*<       count=non_conv_enode(i) >*/
	    count = enothr_1.feq_gen_non_conv_enode_d_[feq_gen_i_d_ - 1];
/* SOURCE output.for:53 */
/*<       if(count.gt.0)then >*/
	    if (count > 0) {
/* SOURCE output.for:54 */
/*<       fraction=real(count)/fknt >*/
		fraction = static_cast<double>((real) count) / fknt;
/* SOURCE output.for:55 */
/*<       if(fraction.gt.0.00)then >*/
		if (fraction > (float)0.) {
/* SOURCE output.for:56 */
/*<       write(stdout,52)inenus(i),count,fraction >*/
		    feq_gen_io_d__7.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__7);
		    do_fio(&feq_gen_c_d_1, inenc_1.inenus + (feq_gen_i_d_ - 1) * 5, (ftnlen)5);
		    do_fio(&feq_gen_c_d_1, (char *)&count, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, (char *)&fraction, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE output.for:57 */
/*<       endif >*/
		}
/* SOURCE output.for:58 */
/*<       endif >*/
	    }
/* SOURCE output.for:59 */
/*<   110 continue >*/
/* L110: */
	}
/* SOURCE output.for:61 */
/*<       write(stdout,54) >*/
	feq_gen_io_d__8.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__8);
	e_wsfe();
/* SOURCE output.for:63 */
/*<       do120i=1,nbra >*/
	feq_gen_i_d_1 = *nbra;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE output.for:64 */
/*<       fnode=brpt(3,i) >*/
	    fnode = brpt[(feq_gen_i_d_ << 3) + 3];
/* SOURCE output.for:65 */
/*<       lnode=brpt(4,i) >*/
	    lnode = brpt[(feq_gen_i_d_ << 3) + 4];
/* SOURCE output.for:66 */
/*<       snode=brpt(1,i) >*/
	    snode = brpt[(feq_gen_i_d_ << 3) + 1];
/* SOURCE output.for:67 */
/*<       do115j=fnode,lnode >*/
	    feq_gen_i_d_2 = lnode;
	    for (j = fnode; j <= feq_gen_i_d_2; ++j) {
/* SOURCE output.for:68 */
/*<       count=non_conv_bnode(j) >*/
		count = bnothr_1.feq_gen_non_conv_bnode_d_[j - 1];
/* SOURCE output.for:69 */
/*<       if(count.gt.0)then >*/
		if (count > 0) {
/* SOURCE output.for:70 */
/*<       fraction=real(count)/fknt >*/
		    fraction = static_cast<double>((real) count) / fknt;
/* SOURCE output.for:71 */
/*<       if(fraction.gt.0.00)then >*/
		    if (fraction > (float)0.) {
/* SOURCE output.for:72 */
/*<       user_node=snode+j-fnode >*/
			feq_gen_user_node_d_ = snode + j - fnode;
/* SOURCE output.for:73 */
/*<       write(stdout,56)inbrus(i),user_node,count,fraction >*/
			feq_gen_io_d__14.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__14);
			do_fio(&feq_gen_c_d_1, (char *)&inbr_1.inbrus[feq_gen_i_d_ - 1], (
				ftnlen)sizeof(integer));
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_user_node_d_, (ftnlen)sizeof(
				integer));
			do_fio(&feq_gen_c_d_1, (char *)&count, (ftnlen)sizeof(integer))
				;
			do_fio(&feq_gen_c_d_1, (char *)&fraction, (ftnlen)sizeof(real))
				;
			e_wsfe();
/* SOURCE output.for:74 */
/*<       endif >*/
		    }
/* SOURCE output.for:75 */
/*<       endif >*/
		}
/* SOURCE output.for:76 */
/*<   115 continue >*/
/* L115: */
	    }
/* SOURCE output.for:77 */
/*<   120 continue >*/
/* L120: */
	}
/* SOURCE output.for:78 */
/*<       endif >*/
    }
/* SOURCE output.for:81 */
/*<       return >*/
    return 0;
/* SOURCE output.for:82 */
/*<       end >*/
} /* non_conv_summary__ */




/* SOURCE output.for:87 */
/*<        >*/
/* Subroutine */ int feq_gen_find_gate_table_items_d_(integer *std6, integer *ipta, 
	real *feq_gen_old_lev_d_, integer *feq_gen_old_lev_offset_d_, integer *
	feq_gen_control_node_state_d_, integer *feq_gen_control_node_state_offset_d_, integer *
	done)
{
    /* Initialized data */

    static integer first = 1;

    /* Local variables */
    static integer ipt;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    integer feq_gen_control_node_d_;

/*     Find the gate_table items that need to be remembered for */
/*     forecast operation.  Give an operation block number location, repeated */
/*     calls should return need values for each control node. */
/* SOURCE output.for:96 */
/*<       implicitnone >*/
/* SOURCE output.for:97 */
/*<        >*/
/* SOURCE output.for:99 */
/*<       realold_lev >*/
/*     common blocks */
/* INCLUDE output.for:103 */
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
/* INCLUDE output.for:104 */
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
/* SOURCE output.for:108 */
/*<       integerfirst,ipt,control_node >*/
/* SOURCE output.for:110 */
/*<       savefirst,ipt >*/
/* *********************************************************************** */
/* SOURCE output.for:112 */
/*<       datafirst/1/ >*/
/* SOURCE output.for:115 */
/*<       if(first==1)then >*/
    if (first == 1) {
/*       Setup pointer for loop over control nodes */
/* SOURCE output.for:117 */
/*<       ipt=ipta >*/
	ipt = *ipta;
/* SOURCE output.for:118 */
/*<       ipt=ipt+12 >*/
	ipt += 12;
/* SOURCE output.for:119 */
/*<       first=0 >*/
	first = 0;
/* SOURCE output.for:120 */
/*<       endif >*/
    }
/*     check the next control node.  Note that when we leave the */
/*     subroutine with a value, we must set ipt to the start of */
/*     block for the next control node. */
/* SOURCE output.for:124 */
/*<       control_node=itab(ipt) >*/
    feq_gen_control_node_d_ = itab[ipt];
/* SOURCE output.for:125 */
/*<       if(control_node/=0)then >*/
    if (feq_gen_control_node_d_ != 0) {
/*       Get values and return */
/* SOURCE output.for:127 */
/*<       old_lev=ftab(ipt+4) >*/
	*feq_gen_old_lev_d_ = ftab[ipt + 4];
/* SOURCE output.for:128 */
/*<       old_lev_offset=ipt+4-ipta >*/
	*feq_gen_old_lev_offset_d_ = ipt + 4 - *ipta;
/* SOURCE output.for:130 */
/*<       control_node_state=itab(ipt+5) >*/
	*feq_gen_control_node_state_d_ = itab[ipt + 5];
/* SOURCE output.for:131 */
/*<       control_node_state_offset=ipt+5-ipta >*/
	*feq_gen_control_node_state_offset_d_ = ipt + 5 - *ipta;
/*       point to the next control node */
/* SOURCE output.for:133 */
/*<       ipt=ipt+17 >*/
	ipt += 17;
/* SOURCE output.for:134 */
/*<       done=0 >*/
	*done = 0;
/* SOURCE output.for:135 */
/*<       else >*/
    } else {
/*       all control nodes processed */
/* SOURCE output.for:137 */
/*<       done=1 >*/
	*done = 1;
/* SOURCE output.for:138 */
/*<       first=1 >*/
	first = 1;
/* SOURCE output.for:139 */
/*<       endif >*/
    }
/* SOURCE output.for:141 */
/*<       return >*/
    return 0;
/* SOURCE output.for:142 */
/*<       end >*/
} /* find_gate_table_items__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE output.for:147 */
/*<       subroutinebwput(bwfdsn,wt,nbra,nbn,nex,nblk,opblk,bwrec) >*/
/* Subroutine */ int bwput_(integer *bwfdsn, real *wt, integer *nbra, integer 
	*nbn, integer *nex, integer *nblk, integer *feq_storage_opblk, integer *bwrec)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wdue(cilist *), do_uio(integer *, char *, ftnlen), e_wdue();

    /* Local variables */
    integer feq_gen_i_d_, it, feq_gen_control_node_state_offset_d_, feq_gen_control_node_state_d_;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer done;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int feq_gen_find_gate_table_items_d_(integer *, integer *, 
	    real *, integer *, integer *, integer *, integer *);
    integer feq_gen_old_lev_offset_d_;
    real feq_gen_old_lev_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__24 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__26 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__27 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__28 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__29 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__30 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__31 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__32 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__33 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__34 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__35 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__37 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__38 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__44 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__45 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__46 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__47 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__48 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__49 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__50 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__51 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Put current state of system into dataset given by BWFDSN. */
/* SOURCE output.for:154 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE output.for:156 */
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
/* SOURCE output.for:159 */
/*<       integerbwfdsn,bwrec,nblk,nbn,nbra,nex >*/
/* SOURCE output.for:160 */
/*<       integeropblk(mnblk) >*/
/* SOURCE output.for:161 */
/*<       realwt >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     BWFDSN - unit number for the initial conditions file */
/*     WT     - weight factor for approximating time integrals */
/*     NBRA   - number of branches in the model */
/*     NBN    - total number on nodes on branches in the model */
/*     NEX    - number of exterior nodes in the model */
/*     NBLK   - number of operation blocks */
/*     OPBLK  - pointer into the function table storage(FTAB/ITAB) for */
/*               each operation block. */
/*     bwrec   - record pointer for storing the information */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE output.for:175 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE output.for:176 */
/* ********************************************************************** */
/* SOURCE bnpond.cmn:3 */
/*<       common/bnpond/coefin,pond1,pond2,ycut,bpond,bpmax >*/
/* SOURCE bnpond.cmn:5 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE output.for:177 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE output.for:178 */
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
/* INCLUDE output.for:179 */
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
/* INCLUDE output.for:180 */
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
/* SOURCE output.for:183 */
/*<        >*/
/* SOURCE output.for:185 */
/*<       realold_lev >*/
/* *********************************************************************** */
/*      SHIFT TO UNFORMATED I/O FOR PRODUCTION VERSION. */
/*      WRITE(BWFDSN)  WT */
/* SOURCE output.for:190 */
/*<       write(bwfdsn,rec=bwrec)wt >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> opblk(feq_storage_opblk, 1);

    /* Function Body */
    feq_gen_io_d__24.ciunit = *bwfdsn;
    feq_gen_io_d__24.cirec = *bwrec;
    s_wdue(&feq_gen_io_d__24);
    do_uio(&feq_gen_c_d_1, (char *)&(*wt), (ftnlen)sizeof(real));
    e_wdue();
/* SOURCE output.for:191 */
/*<       bwrec=bwrec+1 >*/
    ++(*bwrec);
/* SOURCE output.for:192 */
/*<       do100i=1,nbn >*/
    feq_gen_i_d_1 = *nbn;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*        WRITE(BWFDSN) Q1(I), Y1(I), T1(I), A1(I), K1(I),B1(I), WXVEC(I), */
/*     A    POND1(I), DXVEC(I), DZVEC(I), MY(I), MQ(I), MA1(I), MQ1(I) */
/* SOURCE output.for:195 */
/*<       write(bwfdsn,rec=bwrec)q1(i),y1(i) >*/
	feq_gen_io_d__26.ciunit = *bwfdsn;
	feq_gen_io_d__26.cirec = *bwrec;
	s_wdue(&feq_gen_io_d__26);
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.q1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.y1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_wdue();
/* SOURCE output.for:196 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE output.for:197 */
/*<       write(bwfdsn,rec=bwrec)t1(i),a1(i) >*/
	feq_gen_io_d__27.ciunit = *bwfdsn;
	feq_gen_io_d__27.cirec = *bwrec;
	s_wdue(&feq_gen_io_d__27);
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.t1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.a1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_wdue();
/* SOURCE output.for:198 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE output.for:199 */
/*<       write(bwfdsn,rec=bwrec)k1(i),b1(i) >*/
	feq_gen_io_d__28.ciunit = *bwfdsn;
	feq_gen_io_d__28.cirec = *bwrec;
	s_wdue(&feq_gen_io_d__28);
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.k1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.b1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_wdue();
/* SOURCE output.for:200 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE output.for:201 */
/*<       write(bwfdsn,rec=bwrec)wxvec(i),pond1(i) >*/
	feq_gen_io_d__29.ciunit = *bwfdsn;
	feq_gen_io_d__29.cirec = *bwrec;
	s_wdue(&feq_gen_io_d__29);
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.wxvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_uio(&feq_gen_c_d_1, (char *)&bnpond_1.pond1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_wdue();
/* SOURCE output.for:202 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE output.for:203 */
/*<       write(bwfdsn,rec=bwrec)dxvec(i),dzvec(i) >*/
	feq_gen_io_d__30.ciunit = *bwfdsn;
	feq_gen_io_d__30.cirec = *bwrec;
	s_wdue(&feq_gen_io_d__30);
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.dxvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.dzvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_wdue();
/* SOURCE output.for:204 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE output.for:205 */
/*<       write(bwfdsn,rec=bwrec)my(i),mq(i) >*/
	feq_gen_io_d__31.ciunit = *bwfdsn;
	feq_gen_io_d__31.cirec = *bwrec;
	s_wdue(&feq_gen_io_d__31);
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.my[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.mq[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_wdue();
/* SOURCE output.for:206 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE output.for:207 */
/*<       write(bwfdsn,rec=bwrec)ma1(i),mq1(i) >*/
	feq_gen_io_d__32.ciunit = *bwfdsn;
	feq_gen_io_d__32.cirec = *bwrec;
	s_wdue(&feq_gen_io_d__32);
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.ma1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_uio(&feq_gen_c_d_1, (char *)&bnelem_1.mq1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_wdue();
/* SOURCE output.for:208 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE output.for:210 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE output.for:212 */
/*<       do200i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*        WRITE(BWFDSN) QE1(I), YE1(I), AE1(I), MYE(I), MQE(I), TE1(I) */
/* SOURCE output.for:214 */
/*<       write(bwfdsn,rec=bwrec)qe1(i),ye1(i) >*/
	feq_gen_io_d__33.ciunit = *bwfdsn;
	feq_gen_io_d__33.cirec = *bwrec;
	s_wdue(&feq_gen_io_d__33);
	do_uio(&feq_gen_c_d_1, (char *)&enelem_1.qe1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_uio(&feq_gen_c_d_1, (char *)&enelem_1.ye1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_wdue();
/* SOURCE output.for:215 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE output.for:216 */
/*<       write(bwfdsn,rec=bwrec)ae1(i),mye(i) >*/
	feq_gen_io_d__34.ciunit = *bwfdsn;
	feq_gen_io_d__34.cirec = *bwrec;
	s_wdue(&feq_gen_io_d__34);
	do_uio(&feq_gen_c_d_1, (char *)&enelem_1.ae1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_uio(&feq_gen_c_d_1, (char *)&enelem_1.mye[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_wdue();
/* SOURCE output.for:217 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE output.for:218 */
/*<       write(bwfdsn,rec=bwrec)mqe(i),te1(i) >*/
	feq_gen_io_d__35.ciunit = *bwfdsn;
	feq_gen_io_d__35.cirec = *bwrec;
	s_wdue(&feq_gen_io_d__35);
	do_uio(&feq_gen_c_d_1, (char *)&enelem_1.mqe[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_uio(&feq_gen_c_d_1, (char *)&enelem_1.te1[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_wdue();
/* SOURCE output.for:219 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE output.for:221 */
/*<   200 continue >*/
/* L200: */
    }
/*     PROBLEM IN FORECASTING WITH WRITING EMC.  TRY TO GET BY WITHOUT */
/*     DOING SO.  RESETTING STATE SHOULD WORK */
/*      WRITE(BWFDSN) EMC */
/* SOURCE output.for:227 */
/*<       doi=1,nblk >*/
    feq_gen_i_d_1 = *nblk;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE output.for:228 */
/*<       it=opblk(i) >*/
	it = opblk[feq_gen_i_d_];
/* SOURCE output.for:229 */
/*<       write(bwfdsn,rec=bwrec)ftab(it+1),ftab(it+2) >*/
	feq_gen_io_d__37.ciunit = *bwfdsn;
	feq_gen_io_d__37.cirec = *bwrec;
	s_wdue(&feq_gen_io_d__37);
	do_uio(&feq_gen_c_d_1, (char *)ftab.lease(it + 1).data(), (ftnlen)sizeof(real));
	do_uio(&feq_gen_c_d_1, (char *)ftab.lease(it + 2).data(), (ftnlen)sizeof(real));
	e_wdue();
/* SOURCE output.for:230 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE output.for:231 */
/*<       write(bwfdsn,rec=bwrec)ftab(it+5) >*/
	feq_gen_io_d__38.ciunit = *bwfdsn;
	feq_gen_io_d__38.cirec = *bwrec;
	s_wdue(&feq_gen_io_d__38);
	do_uio(&feq_gen_c_d_1, (char *)ftab.lease(it + 5).data(), (ftnlen)sizeof(real));
	e_wdue();
/* SOURCE output.for:232 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/*       Blocks of type 3, GATETABL, have values for each control point */
/*       that need to be remembered as well. */
/*        write(std6,*) 'BWPUT: Block type=',itab(it+3) */
/* SOURCE output.for:236 */
/*<       if(itab(it+3)==3)then >*/
	if (itab[it + 3] == 3) {
/*         Extract and remember the offset and value for old level and */
/*         the control node state. */
/* SOURCE output.for:239 */
/*<   300 continue >*/
L300:
/* SOURCE output.for:240 */
/*<        >*/
	    feq_gen_find_gate_table_items_d_(&feq_gen_stdun_com_d_1.std6, &it, &feq_gen_old_lev_d_, &
		    feq_gen_old_lev_offset_d_, &feq_gen_control_node_state_d_, &
		    feq_gen_control_node_state_offset_d_, &done);
/* SOURCE output.for:244 */
/*<       if(done==0)then >*/
	    if (done == 0) {
/* SOURCE output.for:245 */
/*<       write(bwfdsn,rec=bwrec)old_lev_offset,old_lev >*/
		feq_gen_io_d__44.ciunit = *bwfdsn;
		feq_gen_io_d__44.cirec = *bwrec;
		s_wdue(&feq_gen_io_d__44);
		do_uio(&feq_gen_c_d_1, (char *)&feq_gen_old_lev_offset_d_, (ftnlen)sizeof(
			integer));
		do_uio(&feq_gen_c_d_1, (char *)&feq_gen_old_lev_d_, (ftnlen)sizeof(real));
		e_wdue();
/* SOURCE output.for:246 */
/*<       bwrec=bwrec+1 >*/
		++(*bwrec);
/* SOURCE output.for:247 */
/*<        >*/
		feq_gen_io_d__45.ciunit = *bwfdsn;
		feq_gen_io_d__45.cirec = *bwrec;
		s_wdue(&feq_gen_io_d__45);
		do_uio(&feq_gen_c_d_1, (char *)&feq_gen_control_node_state_offset_d_, (ftnlen)
			sizeof(integer));
		do_uio(&feq_gen_c_d_1, (char *)&feq_gen_control_node_state_d_, (ftnlen)sizeof(
			integer));
		e_wdue();
/* SOURCE output.for:249 */
/*<       bwrec=bwrec+1 >*/
		++(*bwrec);
/* SOURCE output.for:250 */
/*<       goto300 >*/
		goto L300;
/* SOURCE output.for:251 */
/*<       else >*/
	    } else {
/*             wrtie a value of zero to signal end of control-node info */
/* SOURCE output.for:253 */
/*<       done=0 >*/
		done = 0;
/* SOURCE output.for:254 */
/*<       write(bwfdsn,rec=bwrec)done,done >*/
		feq_gen_io_d__46.ciunit = *bwfdsn;
		feq_gen_io_d__46.cirec = *bwrec;
		s_wdue(&feq_gen_io_d__46);
		do_uio(&feq_gen_c_d_1, (char *)&done, (ftnlen)sizeof(integer));
		do_uio(&feq_gen_c_d_1, (char *)&done, (ftnlen)sizeof(integer));
		e_wdue();
/* SOURCE output.for:255 */
/*<       bwrec=bwrec+1 >*/
		++(*bwrec);
/* SOURCE output.for:256 */
/*<       endif >*/
	    }
/* SOURCE output.for:257 */
/*<       endif >*/
	}
/* SOURCE output.for:258 */
/*<       enddo >*/
    }
/*      WRITE(BWFDSN) (BPOND(I), I=1,NBRA) */
/* SOURCE output.for:261 */
/*<       doi=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE output.for:262 */
/*<       write(bwfdsn,rec=bwrec)bpond(i) >*/
	feq_gen_io_d__47.ciunit = *bwfdsn;
	feq_gen_io_d__47.cirec = *bwrec;
	s_wdue(&feq_gen_io_d__47);
	do_uio(&feq_gen_c_d_1, (char *)&bnpond_1.bpond[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_wdue();
/* SOURCE output.for:263 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE output.for:264 */
/*<       enddo >*/
    }
/* SOURCE output.for:265 */
/*<       doi=1,dlay_knt >*/
    feq_gen_i_d_1 = tamcom_1.feq_gen_dlay_knt_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE output.for:266 */
/*<       write(bwfdsn,rec=bwrec)dlay_q1(i) >*/
	feq_gen_io_d__48.ciunit = *bwfdsn;
	feq_gen_io_d__48.cirec = *bwrec;
	s_wdue(&feq_gen_io_d__48);
	do_uio(&feq_gen_c_d_1, (char *)&tamcom_1.feq_gen_dlay_q1_d_[feq_gen_i_d_ - 1], (ftnlen)sizeof(
		doublereal));
	e_wdue();
/* SOURCE output.for:267 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE output.for:268 */
/*<       enddo >*/
    }
/* SOURCE output.for:270 */
/*<       do400i=1,dten_knt >*/
    feq_gen_i_d_1 = tamcom_1.feq_gen_dten_knt_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*        WRITE(BWFDSN) DTEN_S1(I), DTEN_Q1(I), DTEN_Q1P(I) */
/* SOURCE output.for:272 */
/*<       write(bwfdsn,rec=bwrec)dten_s1(i) >*/
	feq_gen_io_d__49.ciunit = *bwfdsn;
	feq_gen_io_d__49.cirec = *bwrec;
	s_wdue(&feq_gen_io_d__49);
	do_uio(&feq_gen_c_d_1, (char *)&tamcom_1.feq_gen_dten_s1_d_[feq_gen_i_d_ - 1], (ftnlen)sizeof(
		real));
	e_wdue();
/* SOURCE output.for:273 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE output.for:274 */
/*<       write(bwfdsn,rec=bwrec)dten_q1(i) >*/
	feq_gen_io_d__50.ciunit = *bwfdsn;
	feq_gen_io_d__50.cirec = *bwrec;
	s_wdue(&feq_gen_io_d__50);
	do_uio(&feq_gen_c_d_1, (char *)&tamcom_1.feq_gen_dten_q1_d_[feq_gen_i_d_ - 1], (ftnlen)sizeof(
		real));
	e_wdue();
/* SOURCE output.for:275 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE output.for:276 */
/*<       write(bwfdsn,rec=bwrec)dten_q1p(i) >*/
	feq_gen_io_d__51.ciunit = *bwfdsn;
	feq_gen_io_d__51.cirec = *bwrec;
	s_wdue(&feq_gen_io_d__51);
	do_uio(&feq_gen_c_d_1, (char *)&tamcom_1.feq_gen_dten_q1p_d_[feq_gen_i_d_ - 1], (ftnlen)sizeof(
		real));
	e_wdue();
/* SOURCE output.for:277 */
/*<       bwrec=bwrec+1 >*/
	++(*bwrec);
/* SOURCE output.for:278 */
/*<   400 continue >*/
/* L400: */
    }
/* SOURCE output.for:280 */
/*<       return >*/
    return 0;
/* SOURCE output.for:281 */
/*<       end >*/
} /* bwput_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE output.for:285 */
/*<        >*/
/* Subroutine */ int get14_(integer *nex, integer *feq_storage_exnodt, integer *adr, 
	integer *node, integer *ztab, real *hdatum, real *head, integer *tabn,
	 real *qmx, real *hmax, integer *tabtyp)
{
    /* Local variables */
    integer it;
    real ti;
    doublereal jt;
    real pdv;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ntab;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);

/* SOURCE output.for:289 */
/*<       implicitnone >*/
/*     + + + PURPOSE + + + */
/*     Get data items for checking extremes for 2-D tables of type 14. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE output.for:294 */
/*<       integeradr,nex,node,tabn,tabtyp,ztab >*/
/* SOURCE output.for:295 */
/*<       integerexnodt(9,nex) >*/
/* SOURCE output.for:296 */
/*<       realhdatum,head,hmax,qmx >*/
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
/*     ADR    - address of the function table in FTAB/ITAB */
/*     NODE   - node number */
/*     ZTAB   - address of table giving variable datum level */
/*     HDATUM - datum for heads */
/*     HEAD   - maximum simulated head for this table */
/*     TABN   - table number */
/*     QMX    - maximum tabulated free flow in the table */
/*     HMAX   - maximum head tabulated in the table */
/*     TABTYP -  table type */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE output.for:325 */
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
/* INCLUDE output.for:326 */
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
/* INCLUDE output.for:327 */
/* ********************************************************************** */
/* SOURCE bnrslt.cmn:2 */
/*<       common/bnrslt/tqmax,tqmin,tzmax,qmax,qmin,zmax,vmax >*/
/* SOURCE bnrslt.cmn:5 */
/*<       realqmax(mnbn),qmin(mnbn),zmax(mnbn),vmax(mnbn) >*/
/* SOURCE bnrslt.cmn:7 */
/*<       doubleprecisiontqmax(mnbn),tqmin(mnbn),tzmax(mnbn) >*/
/* ********************************************************************** */
/* INCLUDE output.for:328 */
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
/* INCLUDE output.for:329 */
/* ********************************************************************** */
/* SOURCE julian.cmn:3 */
/*<        >*/
/* SOURCE julian.cmn:8 */
/*<       integeryr,mn,dy,syr,smn,sdy,eyr,emn,edy,reset,leap,dmyear,dmmn >*/
/* SOURCE julian.cmn:10 */
/*<        >*/
/* ********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE output.for:332 */
/*<       integerit,ntab >*/
/* SOURCE output.for:333 */
/*<       realpdv,ti >*/
/* SOURCE output.for:334 */
/*<       real*8jt >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE output.for:337 */
/*<       externallktab >*/
/* *********************************************************************** */
/* SOURCE output.for:339 */
/*<       tabn=itab(adr+1) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    /* Function Body */
    *tabn = itab[*adr + 1];
/* SOURCE output.for:340 */
/*<       tabtyp=itab(adr+2) >*/
    *tabtyp = itab[*adr + 2];
/* SOURCE output.for:341 */
/*<       qmx=ftab(adr+9) >*/
    *qmx = ftab[*adr + 9];
/* SOURCE output.for:342 */
/*<       hmax=ftab(adr+5) >*/
    *hmax = ftab[*adr + 5];
/* SOURCE output.for:343 */
/*<       it=exnodt(3,node) >*/
    it = exnodt[*node * 9 + 3];
/* SOURCE output.for:344 */
/*<       if(it.le.0)then >*/
    if (it <= 0) {
/* SOURCE output.for:345 */
/*<       head=fnzmax(node) >*/
	*head = enrslt_1.fnzmax[*node - 1];
/* SOURCE output.for:346 */
/*<       jt=ftzmax(node) >*/
	jt = enrslt_1.ftzmax[*node - 1];
/* SOURCE output.for:347 */
/*<       else >*/
    } else {
/* SOURCE output.for:348 */
/*<       it=exnodt(2,node) >*/
	it = exnodt[*node * 9 + 2];
/* SOURCE output.for:349 */
/*<       head=zmax(it) >*/
	*head = bnrslt_1.zmax[it - 1];
/* SOURCE output.for:350 */
/*<       jt=tzmax(it) >*/
	jt = bnrslt_1.tzmax[it - 1];
/* SOURCE output.for:351 */
/*<       endif >*/
    }
/* SOURCE output.for:352 */
/*<       if(ztab.gt.0)then >*/
    if (*ztab > 0) {
/* SOURCE output.for:353 */
/*<       ti=86400.*(jt-sjtime) >*/
	ti = (jt - julian_1.sjtime) * (float)86400.;
/* SOURCE output.for:354 */
/*<       calllktab(ztab,ti,1,hdatum,ntab,pdv) >*/
	lktab_(ztab, &ti, &feq_gen_c_d_1, hdatum, &ntab, &pdv);
/* SOURCE output.for:357 */
/*<       endif >*/
    }
/* SOURCE output.for:359 */
/*<       head=head-hdatum >*/
    *head -= *hdatum;
/* SOURCE output.for:361 */
/*<       return >*/
    return 0;
/* SOURCE output.for:362 */
/*<       end >*/
} /* get14_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE output.for:366 */
/*<        >*/
/* Subroutine */ int get613_(integer *nex, integer *feq_storage_exnodt, integer *adr, 
	integer *node, integer *ztab, real *hdatum, real *head, integer *tabn,
	 real *hmax, integer *tabtyp)
{
    /* Local variables */
    integer it;
    doublereal jt;
    real pdv;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ntab;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int lktstab_(integer *, doublereal *, real *, 
	    integer *, real *);

/*     + + + PURPOSE + + + */
/*     Get data items for checking extremes for 2-D tables of type 6 */
/*     and 13. */
/* SOURCE output.for:374 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE output.for:376 */
/*<       integeradr,nex,node,tabn,tabtyp,ztab >*/
/* SOURCE output.for:377 */
/*<       integerexnodt(9,nex) >*/
/* SOURCE output.for:378 */
/*<       realhdatum,head,hmax >*/
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
/*     ADR    - address of the function table in FTAB/ITAB */
/*     NODE   - node number */
/*     ZTAB   - address of table giving variable datum level */
/*     HDATUM - datum for heads */
/*     HEAD   - maximum simulated head for this table */
/*     TABN   - table number */
/*     HMAX   - maximum head tabulated in the table */
/*     TABTYP -  table type */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE output.for:406 */
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
/* INCLUDE output.for:407 */
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
/* INCLUDE output.for:408 */
/* ********************************************************************** */
/* SOURCE bnrslt.cmn:2 */
/*<       common/bnrslt/tqmax,tqmin,tzmax,qmax,qmin,zmax,vmax >*/
/* SOURCE bnrslt.cmn:5 */
/*<       realqmax(mnbn),qmin(mnbn),zmax(mnbn),vmax(mnbn) >*/
/* SOURCE bnrslt.cmn:7 */
/*<       doubleprecisiontqmax(mnbn),tqmin(mnbn),tzmax(mnbn) >*/
/* ********************************************************************** */
/* INCLUDE output.for:409 */
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
/* INCLUDE output.for:410 */
/* ********************************************************************** */
/* SOURCE julian.cmn:3 */
/*<        >*/
/* SOURCE julian.cmn:8 */
/*<       integeryr,mn,dy,syr,smn,sdy,eyr,emn,edy,reset,leap,dmyear,dmmn >*/
/* SOURCE julian.cmn:10 */
/*<        >*/
/* ********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE output.for:413 */
/*<       integerit,ntab >*/
/* SOURCE output.for:414 */
/*<       realpdv,ti >*/
/* SOURCE output.for:415 */
/*<       real*8jt >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE output.for:418 */
/*<       externallktstab >*/
/* *********************************************************************** */
/* SOURCE output.for:420 */
/*<       tabn=itab(adr+1) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    /* Function Body */
    *tabn = itab[*adr + 1];
/* SOURCE output.for:421 */
/*<       tabtyp=itab(adr+2) >*/
    *tabtyp = itab[*adr + 2];
/* SOURCE output.for:422 */
/*<       hmax=ftab(adr+9) >*/
    *hmax = ftab[*adr + 9];
/* SOURCE output.for:423 */
/*<       it=exnodt(3,node) >*/
    it = exnodt[*node * 9 + 3];
/* SOURCE output.for:424 */
/*<       if(it.le.0)then >*/
    if (it <= 0) {
/* SOURCE output.for:425 */
/*<       head=fnzmax(node) >*/
	*head = enrslt_1.fnzmax[*node - 1];
/* SOURCE output.for:426 */
/*<       jt=ftzmax(node) >*/
	jt = enrslt_1.ftzmax[*node - 1];
/* SOURCE output.for:427 */
/*<       else >*/
    } else {
/* SOURCE output.for:428 */
/*<       it=exnodt(2,node) >*/
	it = exnodt[*node * 9 + 2];
/* SOURCE output.for:429 */
/*<       head=zmax(it) >*/
	*head = bnrslt_1.zmax[it - 1];
/* SOURCE output.for:430 */
/*<       jt=tzmax(it) >*/
	jt = bnrslt_1.tzmax[it - 1];
/* SOURCE output.for:431 */
/*<       endif >*/
    }
/* SOURCE output.for:432 */
/*<       if(ztab.gt.0)then >*/
    if (*ztab > 0) {
/* SOURCE output.for:433 */
/*<       calllktstab(ztab,jt,hdatum,ntab,pdv) >*/
	lktstab_(ztab, &jt, hdatum, &ntab, &pdv);
/* SOURCE output.for:436 */
/*<       endif >*/
    }
/* SOURCE output.for:438 */
/*<       head=head-hdatum >*/
    *head -= *hdatum;
/* SOURCE output.for:440 */
/*<       return >*/
    return 0;
/* SOURCE output.for:441 */
/*<       end >*/
} /* get613_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE output.for:445 */
/*<       subroutinemarsum(nrow,ncol,maxrow,table) >*/
/* Subroutine */ int marsum_(integer *nrow, integer *ncol, integer *maxrow, 
	real *feq_storage_table)
{
    /* System generated locals */
    integer table_dim1, table_offset, feq_gen_i_d_1, feq_gen_i_d_2;

    /* Local variables */
    integer feq_gen_i_d_, j;
    real sum, sum2;

/*     + + + PURPOSE + + + */
/*     Compute marginal sums for TABLE. */
/* SOURCE output.for:452 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE output.for:454 */
/*<       integermaxrow,ncol,nrow >*/
/* SOURCE output.for:455 */
/*<       realtable(maxrow,*) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NROW   - number of rows in table */
/*     NCOL   - number of columns */
/*     MAXROW - declared number of rows in the table */
/*     TABLE  - table for which marginal sum is computed */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE output.for:464 */
/*<       integeri,j >*/
/* SOURCE output.for:465 */
/*<       realsum,sum2 >*/
/* *********************************************************************** */
/*     FIND THE ROW SUMS */
/* SOURCE output.for:469 */
/*<       do110i=1,nrow >*/
    /* Parameter adjustments */
    table_dim1 = *maxrow;
    table_offset = 1 + table_dim1;

    feq::IndexedPointer<real> table(feq_storage_table, table_offset);

    /* Function Body */
    feq_gen_i_d_1 = *nrow;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE output.for:470 */
/*<       sum=0.0 >*/
	sum = (float)0.;
/* SOURCE output.for:471 */
/*<       do100j=1,ncol >*/
	feq_gen_i_d_2 = *ncol;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE output.for:472 */
/*<       if(table(i,j).gt.0.0)then >*/
	    if (table[feq_gen_i_d_ + j * table_dim1] > (float)0.) {
/*           Negative values NOT included in row sums. */
/* SOURCE output.for:474 */
/*<       sum=sum+table(i,j) >*/
		sum += static_cast<double>(table[feq_gen_i_d_ + j * table_dim1]);
/* SOURCE output.for:475 */
/*<       endif >*/
	    }
/* SOURCE output.for:476 */
/*<   100 continue >*/
/* L100: */
	}
/* SOURCE output.for:477 */
/*<       table(i,ncol+1)=sum >*/
	table[feq_gen_i_d_ + (*ncol + 1) * table_dim1] = sum;
/* SOURCE output.for:478 */
/*<   110 continue >*/
/* L110: */
    }
/* SOURCE output.for:480 */
/*<       sum2=0.0 >*/
    sum2 = (float)0.;
/*     FIND COLUMN SUMS */
/* SOURCE output.for:483 */
/*<       do130j=1,ncol >*/
    feq_gen_i_d_1 = *ncol;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE output.for:484 */
/*<       sum=0.0 >*/
	sum = (float)0.;
/* SOURCE output.for:485 */
/*<       do120i=1,nrow >*/
	feq_gen_i_d_2 = *nrow;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_2; ++feq_gen_i_d_) {
/* SOURCE output.for:486 */
/*<       sum=sum+table(i,j) >*/
	    sum += static_cast<double>(table[feq_gen_i_d_ + j * table_dim1]);
/* SOURCE output.for:487 */
/*<   120 continue >*/
/* L120: */
	}
/* SOURCE output.for:488 */
/*<       table(nrow+1,j)=sum >*/
	table[*nrow + 1 + j * table_dim1] = sum;
/* SOURCE output.for:489 */
/*<       if(sum.gt.0.0)then >*/
	if (sum > (float)0.) {
/* SOURCE output.for:490 */
/*<       sum2=sum2+sum >*/
	    sum2 += sum;
/* SOURCE output.for:491 */
/*<       endif >*/
	}
/* SOURCE output.for:492 */
/*<   130 continue >*/
/* L130: */
    }
/* SOURCE output.for:494 */
/*<       table(nrow+1,ncol+1)=sum2 >*/
    table[*nrow + 1 + (*ncol + 1) * table_dim1] = sum2;
/* SOURCE output.for:496 */
/*<       return >*/
    return 0;
/* SOURCE output.for:497 */
/*<       end >*/
} /* marsum_ */




/* SOURCE output.for:501 */
/*<        >*/
/* Subroutine */ int outsp_(integer *feq_storage_exnodt, integer *nex, integer *yr, 
	integer *mn, integer *dy, real *hr, integer *nout, integer *unit, 
	integer *feq_storage_pout, real *feq_gen_dz_for_output_d_, char *feq_storage_qout, char *feq_storage_zout, integer 
	*lkount, ftnlen qout_len, ftnlen zout_len)
{
    /* Initialized data */

    static char slgtyp[8*5+1] = "    ZERO      FO      SO      FW      SW";
    static char items[16+1] = "  Flow    Elev  ";

    /* Format strings */
    static char fmt_10[] = "(f8.1)";
    static char fmt_11[] = "(\002 \002,f10.6,250(a8))";
    static char fmt_12[] = "(\002 \002,i4,\002/\002,i2,\002/\002,i2,250(a8))";
    static char fmt_13[] = "(f9.0)";
    static char fmt_15[] = "(\002 \002,a10,250(a8))";
    static char fmt_20[] = "(f8.3)";
    static char fmt_50[] = "(11x,250(1x,a7))";
    static char fmt_52[] = "(18x,250(2x,2a7))";
    static char fmt_54[] = "(\002YEAR MN DY    HOUR\002,250(a16))";
    static char fmt_56[] = "(i4,i3,i3,f8.4,250(a8,a8))";

    /* System generated locals */
    integer qout_dim1, zout_dim1, feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[8];
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_wsfi(icilist *), e_wsfi();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j;
    real bu;
    integer adr;
    real dbu, dtu;
    extern /* Subroutine */ int feq_gen_var_decimal_d_(real *, char *, ftnlen);
    char chr9[9];
    integer feq_gen_lookup_done_d_;
    extern /* Character */ VOID put8_(char *, ftnlen, real *);
    real dcon, amain, kmain, tmain, qmain;
    extern /* Subroutine */ int xlkt20_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *);
    integer tabadr;
    real aflood;
    integer option;
    real qflood, atotal, ttotal, ktotal, qtotal;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__73 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__75 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__76 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__77 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__80 = { 0, 0, 0, fmt_12, 0 };
    static cilist feq_gen_io_d__81 = { 0, 0, 0, fmt_11, 0 };
    static cilist feq_gen_io_d__82 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__101 = { 0, 0, 0, fmt_15, 0 };


/*     + + + PURPOSE + + + */
/*     Writes elevation and discharge at up to MNSOUT nodes. */
/*     Also writes selected gate settings.  Includes optional */
/*     output lines. */
/* SOURCE output.for:511 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE output.for:513 */
/*<       integerdy,lkount,nex,mn,nout,unit,yr >*/
/* SOURCE output.for:514 */
/*<       integerexnodt(9,nex),pout(nout) >*/
/* SOURCE output.for:515 */
/*<       realhr,dz_for_output >*/
/* SOURCE output.for:516 */
/*<       characterqout(nout)*8,zout(nout)*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     YR     - calendar year */
/*     MN     - number of month(1-12) */
/*     DY     - day in the month */
/*     HR     - hour of the day */
/*     NOUT   - number of special outputs */
/*     UNIT   - unit number */
/*     POUT   - pointer to the value to output */
/*     QOUT   - flow values to output in special output */
/*     ZOUT   - values of elevation to output */
/*     LKOUNT - number of lines on the current output page */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE output.for:531 */
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
/* INCLUDE output.for:532 */
/*     Miscellaneous control parameters */
/* SOURCE misccon.cmn:3 */
/*<       integerpagesp,pndflg >*/
/* SOURCE misccon.cmn:5 */
/*<        >*/
/* SOURCE misccon.cmn:8 */
/*<        >*/
/* INCLUDE output.for:533 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE output.for:534 */
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
/* INCLUDE output.for:535 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE output.for:536 */
/*     NAMES FOR VARIOUS OPTIONAL FILES AND SPECIAL OUTPUT FILE */
/*     HEADINGS */
/* SOURCE namcom.cmn:5 */
/*<       character*7sphead(mnsout,2) >*/
/* SOURCE namcom.cmn:7 */
/*<       character*256bwfnam,fffnam,tsfnam,putnam,getnam >*/
/* SOURCE namcom.cmn:9 */
/*<       common/namcom/bwfnam,fffnam,tsfnam,sphead,putnam,getnam >*/
/* INCLUDE output.for:537 */
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
/* INCLUDE output.for:538 */
/*     Used for output of Mc Henry gate information */
/* SOURCE mhenry.cmn:3 */
/*<       integertypmch >*/
/* SOURCE mhenry.cmn:4 */
/*<       realhgmch >*/
/* SOURCE mhenry.cmn:5 */
/*<       common/mhenry/typmch,hgmch >*/
/* INCLUDE output.for:539 */
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
/*     + + + SAVED VALUES + + + */
/* SOURCE output.for:542 */
/*<       characterslgtyp(0:4)*8 >*/
/* SOURCE output.for:543 */
/*<       saveslgtyp >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE output.for:546 */
/*<       integeradr,i,j,option,tabadr,lookup_done >*/
/* SOURCE output.for:547 */
/*<       characterchr9*9 >*/
/* SOURCE output.for:548 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE output.for:554 */
/*<       intrinsicabs,iabs >*/
/* SOURCE output.for:557 */
/*<       characterput8*8,items*16 >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE output.for:559 */
/*<        >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);
    zout_dim1 = *nout;

    feq::IndexedPointer<char> zout(feq_storage_zout, 8);
    qout_dim1 = *nout;

    feq::IndexedPointer<char> qout(feq_storage_qout, 8);

    feq::IndexedPointer<integer> pout(feq_storage_pout, 1);

    /* Function Body */
/* SOURCE output.for:563 */
/*<    10 format(f8.1) >*/
/* L10: */
/* SOURCE output.for:564 */
/*<    11 format(' ',f10.6,250(a8)) >*/
/* L11: */
/* SOURCE output.for:565 */
/*<    12 format(' ',i4,'/',i2,'/',i2,250(a8)) >*/
/* L12: */
/* SOURCE output.for:566 */
/*<    13 format(f9.0) >*/
/* L13: */
/* SOURCE output.for:567 */
/*<    15 format(' ',a10,250(a8)) >*/
/* L15: */
/* SOURCE output.for:568 */
/*<    20 format(f8.3) >*/
/* L20: */
/* SOURCE output.for:569 */
/*<    50 format(11x,250(1x,a7)) >*/
/* L50: */
/* SOURCE output.for:570 */
/*<    52 format(18x,250(2x,2a7)) >*/
/* L52: */
/* SOURCE output.for:571 */
/*<    54 format('YEAR MN DY    HOUR',250(a16)) >*/
/* L54: */
/* SOURCE output.for:572 */
/*<    56 format(i4,i3,i3,f8.4,250(a8,a8)) >*/
/* L56: */
/* *********************************************************************** */
/*     WRITE THE HEADINGS IF NEEDED */
/* SOURCE output.for:576 */
/*<       if(lkount.eq.0)then >*/
    if (*lkount == 0) {
/* SOURCE output.for:577 */
/*<       if(spout_style.eq.2)then >*/
	if (spouta_1.feq_gen_spout_style_d_ == 2) {
/* SOURCE output.for:578 */
/*<       write(stdspout,50)(sphead(i,1),i=1,nout) >*/
	    feq_gen_io_d__73.ciunit = spouta_1.stdspout;
	    s_wsfe(&feq_gen_io_d__73);
	    feq_gen_i_d_1 = *nout;
	    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
		do_fio(&feq_gen_c_d_1, namcom_1.sphead + (feq_gen_i_d_ - 1) * 7, (ftnlen)7);
	    }
	    e_wsfe();
/* SOURCE output.for:579 */
/*<       write(stdspout,50)(sphead(i,2),i=1,nout) >*/
	    feq_gen_io_d__75.ciunit = spouta_1.stdspout;
	    s_wsfe(&feq_gen_io_d__75);
	    feq_gen_i_d_1 = *nout;
	    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
		do_fio(&feq_gen_c_d_1, namcom_1.sphead + (feq_gen_i_d_ + 249) * 7, (ftnlen)7);
	    }
	    e_wsfe();
/* SOURCE output.for:580 */
/*<       lkount=2 >*/
	    *lkount = 2;
/* SOURCE output.for:581 */
/*<       else >*/
	} else {
/*         Single line style. */
/* SOURCE output.for:583 */
/*<       write(stdspout,52)(sphead(i,1),sphead(i,2),i=1,nout) >*/
	    feq_gen_io_d__76.ciunit = spouta_1.stdspout;
	    s_wsfe(&feq_gen_io_d__76);
	    feq_gen_i_d_1 = *nout;
	    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
		do_fio(&feq_gen_c_d_1, namcom_1.sphead + (feq_gen_i_d_ - 1) * 7, (ftnlen)7);
		do_fio(&feq_gen_c_d_1, namcom_1.sphead + (feq_gen_i_d_ + 249) * 7, (ftnlen)7);
	    }
	    e_wsfe();
/* SOURCE output.for:584 */
/*<       write(stdspout,54)(items,i=1,nout) >*/
	    feq_gen_io_d__77.ciunit = spouta_1.stdspout;
	    s_wsfe(&feq_gen_io_d__77);
	    feq_gen_i_d_1 = *nout;
	    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
		do_fio(&feq_gen_c_d_1, items, (ftnlen)16);
	    }
	    e_wsfe();
/* SOURCE output.for:585 */
/*<       lkount=2 >*/
	    *lkount = 2;
/* SOURCE output.for:586 */
/*<       endif >*/
	}
/* SOURCE output.for:587 */
/*<       endif >*/
    }
/*     SELECT THE VALUES */
/* SOURCE output.for:591 */
/*<       do100i=1,nout >*/
    feq_gen_i_d_1 = *nout;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE output.for:592 */
/*<       adr=pout(i) >*/
	adr = pout[feq_gen_i_d_];
/* SOURCE output.for:593 */
/*<       if(adr.gt.0)goto90 >*/
	if (adr > 0) {
	    goto L90;
	}
/*           EXTERIOR NODE */
/* SOURCE output.for:595 */
/*<       adr=iabs(adr) >*/
	adr = abs(adr);
/* SOURCE output.for:596 */
/*<       if(adr.lt.10000)then >*/
	if (adr < 10000) {
/* SOURCE output.for:597 */
/*<       if(abs(qe1(adr)).le.100000.0)then >*/
	    if ((feq_gen_r_d_1 = enelem_1.qe1[adr - 1], dabs(feq_gen_r_d_1)) <= (float)1e5) {
/* SOURCE output.for:598 */
/*<       write(qout(i),10)qe1(adr) >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 8;
		feq_gen_ici_d_1.iciunit = qout + (feq_gen_i_d_ << 3);
		feq_gen_ici_d_1.icifmt = fmt_10;
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&enelem_1.qe1[adr - 1], (ftnlen)sizeof(
			real));
		e_wsfi();
/* SOURCE output.for:599 */
/*<       else >*/
	    } else {
/* SOURCE output.for:600 */
/*<       write(chr9,13)qe1(adr) >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 9;
		feq_gen_ici_d_1.iciunit = chr9;
		feq_gen_ici_d_1.icifmt = fmt_13;
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&enelem_1.qe1[adr - 1], (ftnlen)sizeof(
			real));
		e_wsfi();
/* SOURCE output.for:601 */
/*<       qout(i)=chr9 >*/
		s_copy(qout + (feq_gen_i_d_ << 3), chr9, (ftnlen)8, (ftnlen)9);
/* SOURCE output.for:602 */
/*<       endif >*/
	    }
/* SOURCE output.for:603 */
/*<       write(zout(i),20)ye1(adr)+ze(adr)+dz_for_output >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 8;
	    feq_gen_ici_d_1.iciunit = zout + (feq_gen_i_d_ << 3);
	    feq_gen_ici_d_1.icifmt = fmt_20;
	    s_wsfi(&feq_gen_ici_d_1);
	    feq_gen_r_d_1 = static_cast<double>(static_cast<double>(enelem_1.ye1[adr - 1]) + enelem_1.ze[adr - 1]) + *
		    feq_gen_dz_for_output_d_;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    e_wsfi();
/* SOURCE output.for:604 */
/*<       elseif(adr.lt.20000)then >*/
	} else if (adr < 20000) {
/* SOURCE output.for:605 */
/*<       adr=adr-10000 >*/
	    adr += -10000;
/* SOURCE output.for:606 */
/*<       callvar_decimal(qpvec(adr),qout(i)) >*/
	    feq_gen_var_decimal_d_(&bnothr_1.qpvec[adr - 1], qout + (feq_gen_i_d_ << 3), (
		    ftnlen)8);
/*              WRITE(QOUT(I),10) QPVEC(ADR) */
/* SOURCE output.for:609 */
/*<       zout(i)=' TBAFLW ' >*/
	    s_copy(zout + (feq_gen_i_d_ << 3), const_cast<char*>(" TBAFLW "), (ftnlen)8, (ftnlen)8);
/* SOURCE output.for:610 */
/*<       elseif(adr.eq.20000)then >*/
	} else if (adr == 20000) {
/*             MCHENRY SLUICE GATE */
/*             REPORT FLOW TYPE AND GATE OPENING. */
/* SOURCE output.for:613 */
/*<       qout(i)=slgtyp(typmch) >*/
	    s_copy(qout + (feq_gen_i_d_ << 3), slgtyp + (mhenry_1.typmch << 3), (
		    ftnlen)8, (ftnlen)8);
/* SOURCE output.for:614 */
/*<       write(zout(i),20)hgmch >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 8;
	    feq_gen_ici_d_1.iciunit = zout + (feq_gen_i_d_ << 3);
	    feq_gen_ici_d_1.icifmt = fmt_20;
	    s_wsfi(&feq_gen_ici_d_1);
	    do_fio(&feq_gen_c_d_1, (char *)&mhenry_1.hgmch, (ftnlen)sizeof(real));
	    e_wsfi();
/* SOURCE output.for:615 */
/*<       else >*/
	} else {
/*             Gates other than McHenry.   Get items from standard */
/*             locations set by subroutines called in SETEXT. */
/* SOURCE output.for:618 */
/*<       adr=adr-20000 >*/
	    adr += -20000;
/* SOURCE output.for:619 */
/*<       qout(i)=fclass(adr) >*/
	    s_copy(qout + (feq_gen_i_d_ << 3), gate2_1.fclass + (adr << 3), (ftnlen)8, 
		    (ftnlen)8);
/* SOURCE output.for:620 */
/*<       write(zout(i),20)gopen(adr) >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 8;
	    feq_gen_ici_d_1.iciunit = zout + (feq_gen_i_d_ << 3);
	    feq_gen_ici_d_1.icifmt = fmt_20;
	    s_wsfi(&feq_gen_ici_d_1);
	    do_fio(&feq_gen_c_d_1, (char *)&gate1_1.gopen[adr], (ftnlen)sizeof(real));
	    e_wsfi();
/* SOURCE output.for:621 */
/*<       endif >*/
	}
/* SOURCE output.for:622 */
/*<       goto100 >*/
	goto L100;
/* SOURCE output.for:623 */
/*<    90 continue >*/
L90:
/* SOURCE output.for:624 */
/*<       if(adr.lt.10000)then >*/
	if (adr < 10000) {
/* SOURCE output.for:625 */
/*<       if(abs(q1(adr)).lt.100000.0)then >*/
	    if ((feq_gen_r_d_1 = bnelem_1.q1[adr - 1], dabs(feq_gen_r_d_1)) < (float)1e5) {
/* SOURCE output.for:626 */
/*<       write(qout(i),10)q1(adr) >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 8;
		feq_gen_ici_d_1.iciunit = qout + (feq_gen_i_d_ << 3);
		feq_gen_ici_d_1.icifmt = fmt_10;
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&bnelem_1.q1[adr - 1], (ftnlen)sizeof(
			real));
		e_wsfi();
/* SOURCE output.for:627 */
/*<       else >*/
	    } else {
/* SOURCE output.for:628 */
/*<       write(chr9,13)q1(adr) >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 9;
		feq_gen_ici_d_1.iciunit = chr9;
		feq_gen_ici_d_1.icifmt = fmt_13;
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&bnelem_1.q1[adr - 1], (ftnlen)sizeof(
			real));
		e_wsfi();
/* SOURCE output.for:629 */
/*<       qout(i)=chr9 >*/
		s_copy(qout + (feq_gen_i_d_ << 3), chr9, (ftnlen)8, (ftnlen)9);
/* SOURCE output.for:630 */
/*<       endif >*/
	    }
/* SOURCE output.for:631 */
/*<       write(zout(i),20)y1(adr)+zvec(adr)+dz_for_output >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 8;
	    feq_gen_ici_d_1.iciunit = zout + (feq_gen_i_d_ << 3);
	    feq_gen_ici_d_1.icifmt = fmt_20;
	    s_wsfi(&feq_gen_ici_d_1);
	    feq_gen_r_d_1 = static_cast<double>(static_cast<double>(bnelem_1.y1[adr - 1]) + bnelem_1.zvec[adr - 1]) + *
		    feq_gen_dz_for_output_d_;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    e_wsfi();
/* SOURCE output.for:632 */
/*<       else >*/
	} else {
/* SOURCE output.for:633 */
/*<       adr=adr-10000 >*/
	    adr += -10000;
/* SOURCE output.for:634 */
/*<       callvar_decimal(qpvec(adr),qout(i)) >*/
	    feq_gen_var_decimal_d_(&bnothr_1.qpvec[adr - 1], qout + (feq_gen_i_d_ << 3), (
		    ftnlen)8);
/*           WRITE(QOUT(I),10) QPVEC(ADR) */
/* SOURCE output.for:637 */
/*<       zout(i)=' TBAFLW ' >*/
	    s_copy(zout + (feq_gen_i_d_ << 3), const_cast<char*>(" TBAFLW "), (ftnlen)8, (ftnlen)8);
/* SOURCE output.for:638 */
/*<       endif >*/
	}
/* SOURCE output.for:639 */
/*<   100 continue >*/
L100:
	;
    }
/* SOURCE output.for:641 */
/*<       if(spout_style.eq.2)then >*/
    if (spouta_1.feq_gen_spout_style_d_ == 2) {
/* SOURCE output.for:642 */
/*<       write(stdspout,12)yr,mn,dy,zout >*/
	feq_gen_io_d__80.ciunit = spouta_1.stdspout;
	s_wsfe(&feq_gen_io_d__80);
	do_fio(&feq_gen_c_d_1, (char *)&(*yr), (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&(*mn), (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&(*dy), (ftnlen)sizeof(integer));
	feq_gen_i_d_1 = 1 * zout_dim1;
	do_fio(&feq_gen_i_d_1, zout + 8, (ftnlen)8);
	e_wsfe();
/* SOURCE output.for:643 */
/*<       write(stdspout,11)hr,qout >*/
	feq_gen_io_d__81.ciunit = spouta_1.stdspout;
	s_wsfe(&feq_gen_io_d__81);
	do_fio(&feq_gen_c_d_1, (char *)&(*hr), (ftnlen)sizeof(real));
	feq_gen_i_d_1 = 1 * qout_dim1;
	do_fio(&feq_gen_i_d_1, qout + 8, (ftnlen)8);
	e_wsfe();
/* SOURCE output.for:644 */
/*<       elseif(spout_style.eq.1)then >*/
    } else if (spouta_1.feq_gen_spout_style_d_ == 1) {
/* SOURCE output.for:645 */
/*<       write(stdspout,56)yr,mn,dy,hr,(qout(i),zout(i),i=1,nout) >*/
	feq_gen_io_d__82.ciunit = spouta_1.stdspout;
	s_wsfe(&feq_gen_io_d__82);
	do_fio(&feq_gen_c_d_1, (char *)&(*yr), (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&(*mn), (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&(*dy), (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&(*hr), (ftnlen)sizeof(real));
	feq_gen_i_d_1 = *nout;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
	    do_fio(&feq_gen_c_d_1, qout + (feq_gen_i_d_ << 3), (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, zout + (feq_gen_i_d_ << 3), (ftnlen)8);
	}
	e_wsfe();
/* SOURCE output.for:646 */
/*<       endif >*/
    }
/*     Update the count of records-taken to be a time point.  That is, there is one */
/*     record per time point. */
/* SOURCE output.for:649 */
/*<       spo_knt=spo_knt+1 >*/
    ++spouta_1.feq_gen_spo_knt_d_;
/*     Process the optional lines of output. */
/* SOURCE output.for:654 */
/*<       if(spout_knt.gt.0)then >*/
    if (spouta_1.feq_gen_spout_knt_d_ > 0) {
/* SOURCE output.for:655 */
/*<       do500i=1,nout >*/
	feq_gen_i_d_1 = *nout;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE output.for:656 */
/*<       adr=pout(i) >*/
	    adr = pout[feq_gen_i_d_];
/* SOURCE output.for:657 */
/*<       if(adr.gt.-10000.and.adr.lt.10000)then >*/
	    if (adr > -10000 && adr < 10000) {
/*           This could be a node on a branch. */
/* SOURCE output.for:659 */
/*<       if(adr.lt.0)then >*/
		if (adr < 0) {
/*             This is an exterior node.  Check if it is on */
/*             a branch. */
/* SOURCE output.for:662 */
/*<       adr=abs(adr) >*/
		    adr = abs(adr);
/* SOURCE output.for:663 */
/*<       if(exnodt(3,adr).gt.0)then >*/
		    if (exnodt[adr * 9 + 3] > 0) {
/*               Yes it is on a branch.  Get its branch-vector */
/*               address. */
/* SOURCE output.for:666 */
/*<       adr=exnodt(2,adr) >*/
			adr = exnodt[adr * 9 + 2];
/* SOURCE output.for:667 */
/*<       else >*/
		    } else {
/*               It is not on a branch or it is a special request. */
/*               Skip it. */
/* SOURCE output.for:670 */
/*<       goto500 >*/
			goto L500;
/* SOURCE output.for:671 */
/*<       endif >*/
		    }
/* SOURCE output.for:672 */
/*<       endif >*/
		}
/* SOURCE output.for:674 */
/*<       tabadr=spout_main_channel_table(i) >*/
		tabadr = spouta_1.feq_gen_spout_main_channel_table_d_[feq_gen_i_d_ - 1];
/* SOURCE output.for:675 */
/*<       lookup_done=0 >*/
		feq_gen_lookup_done_d_ = 0;
/* SOURCE output.for:676 */
/*<       if(tabadr.gt.0)then >*/
		if (tabadr > 0) {
/* SOURCE output.for:677 */
/*<       if(need_lookup.eq.1)then >*/
		    if (spouta_1.feq_gen_need_lookup_d_ == 1) {
/* SOURCE output.for:678 */
/*<       lookup_done=1 >*/
			feq_gen_lookup_done_d_ = 1;
/* SOURCE output.for:679 */
/*<       callxlkt20(tabadr,y1(adr),amain,tmain,dtu,kmain,dcon,bu,dbu) >*/
			xlkt20_(&tabadr, &bnelem_1.y1[adr - 1], &amain, &
				tmain, &dtu, &kmain, &dcon, &bu, &dbu);
/* SOURCE output.for:683 */
/*<       atotal=a1(adr) >*/
			atotal = bnelem_1.a1[adr - 1];
/* SOURCE output.for:684 */
/*<       ttotal=t1(adr) >*/
			ttotal = bnelem_1.t1[adr - 1];
/* SOURCE output.for:685 */
/*<       ktotal=k1(adr) >*/
			ktotal = bnelem_1.k1[adr - 1];
/* SOURCE output.for:686 */
/*<       qtotal=q1(adr) >*/
			qtotal = bnelem_1.q1[adr - 1];
/* SOURCE output.for:687 */
/*<       if(amain.gt.atotal)amain=atotal >*/
			if (amain > atotal) {
			    amain = atotal;
			}
/* SOURCE output.for:688 */
/*<       if(tmain.gt.ttotal)tmain=ttotal >*/
			if (tmain > ttotal) {
			    tmain = ttotal;
			}
/* SOURCE output.for:689 */
/*<       if(kmain.gt.ktotal)kmain=ktotal >*/
			if (kmain > ktotal) {
			    kmain = ktotal;
			}
/* SOURCE output.for:690 */
/*<       endif >*/
		    }
/* SOURCE output.for:691 */
/*<       endif >*/
		}
/* SOURCE output.for:693 */
/*<       do300j=1,spout_knt >*/
		feq_gen_i_d_2 = spouta_1.feq_gen_spout_knt_d_;
		for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE output.for:694 */
/*<       option=spout_item_value(spout_item(j)) >*/
		    option = spouta_1.feq_gen_spout_item_value_d_[
			    spouta_1.feq_gen_spout_item_d_[j - 1] - 1];
/*              SELECT CASE(OPTION) */
/*              CASE (TOTAL_AREA) */
/* SOURCE output.for:698 */
/*<       if(option.eq.total_area)then >*/
		    if (option == 1) {
/* SOURCE output.for:699 */
/*<       extra_buffer(i,j)=put8(a1(adr)) >*/
			put8_(feq_gen_ch_d_1, (ftnlen)8, &bnelem_1.a1[adr - 1]);
			s_copy(spoutc_1.feq_gen_extra_buffer_d_ + (feq_gen_i_d_ + j * 250 - 251 
				<< 3), feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/*              CASE (MAIN_CHANNEL_AREA) */
/* SOURCE output.for:702 */
/*<       elseif(option.eq.main_channel_area)then >*/
		    } else if (option == 20) {
/* SOURCE output.for:704 */
/*<       if(lookup_done.eq.1)then >*/
			if (feq_gen_lookup_done_d_ == 1) {
/* SOURCE output.for:705 */
/*<       extra_buffer(i,j)=put8(amain) >*/
			    put8_(feq_gen_ch_d_1, (ftnlen)8, &amain);
			    s_copy(spoutc_1.feq_gen_extra_buffer_d_ + (feq_gen_i_d_ + j * 250 - 
				    251 << 3), feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE output.for:706 */
/*<       else >*/
			} else {
/* SOURCE output.for:707 */
/*<       extra_buffer(i,j)=' ' >*/
			    s_copy(spoutc_1.feq_gen_extra_buffer_d_ + (feq_gen_i_d_ + j * 250 - 
				    251 << 3), const_cast<char*>(" "), (ftnlen)8, (ftnlen)1);
/* SOURCE output.for:708 */
/*<       endif >*/
			}
/*              CASE (FLOOD_PLAIN_AREA) */
/* SOURCE output.for:711 */
/*<       elseif(option.eq.flood_plain_area)then >*/
		    } else if (option == 21) {
/* SOURCE output.for:712 */
/*<       if(lookup_done.eq.1)then >*/
			if (feq_gen_lookup_done_d_ == 1) {
/* SOURCE output.for:713 */
/*<       extra_buffer(i,j)=put8(atotal-amain) >*/
			    feq_gen_r_d_1 = static_cast<double>(atotal) - amain;
			    put8_(feq_gen_ch_d_1, (ftnlen)8, &feq_gen_r_d_1);
			    s_copy(spoutc_1.feq_gen_extra_buffer_d_ + (feq_gen_i_d_ + j * 250 - 
				    251 << 3), feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE output.for:714 */
/*<       else >*/
			} else {
/* SOURCE output.for:715 */
/*<       extra_buffer(i,j)=' ' >*/
			    s_copy(spoutc_1.feq_gen_extra_buffer_d_ + (feq_gen_i_d_ + j * 250 - 
				    251 << 3), const_cast<char*>(" "), (ftnlen)8, (ftnlen)1);
/* SOURCE output.for:716 */
/*<       endif >*/
			}
/*              CASE (MEAN_VELOCITY) */
/* SOURCE output.for:719 */
/*<       elseif(option.eq.mean_velocity)then >*/
		    } else if (option == 2) {
/* SOURCE output.for:720 */
/*<       write(extra_buffer(i,j),'(F8.3)')q1(adr)/a1(adr) >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 8;
			feq_gen_ici_d_1.iciunit = spoutc_1.feq_gen_extra_buffer_d_ + (feq_gen_i_d_ + j * 
				250 - 251 << 3);
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.3)");
			s_wsfi(&feq_gen_ici_d_1);
			feq_gen_r_d_1 = static_cast<double>(bnelem_1.q1[adr - 1]) / bnelem_1.a1[adr - 1];
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
			e_wsfi();
/*              CASE (MAIN_CHANNEL_VELOCITY) */
/* SOURCE output.for:723 */
/*<       elseif(option.eq.main_channel_velocity)then >*/
		    } else if (option == 22) {
/* SOURCE output.for:724 */
/*<       if(lookup_done.eq.1)then >*/
			if (feq_gen_lookup_done_d_ == 1) {
/* SOURCE output.for:725 */
/*<       qmain=qtotal*kmain/ktotal >*/
			    qmain = static_cast<double>(static_cast<double>(qtotal) * kmain) / ktotal;
/* SOURCE output.for:726 */
/*<       write(extra_buffer(i,j),'(F8.3)')qmain/amain >*/
			    feq_gen_ici_d_1.icierr = 0;
			    feq_gen_ici_d_1.icirnum = 1;
			    feq_gen_ici_d_1.icirlen = 8;
			    feq_gen_ici_d_1.iciunit = spoutc_1.feq_gen_extra_buffer_d_ + (feq_gen_i_d_ + 
				    j * 250 - 251 << 3);
			    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.3)");
			    s_wsfi(&feq_gen_ici_d_1);
			    feq_gen_r_d_1 = static_cast<double>(qmain) / amain;
			    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real))
				    ;
			    e_wsfi();
/* SOURCE output.for:727 */
/*<       else >*/
			} else {
/* SOURCE output.for:728 */
/*<       extra_buffer(i,j)=' ' >*/
			    s_copy(spoutc_1.feq_gen_extra_buffer_d_ + (feq_gen_i_d_ + j * 250 - 
				    251 << 3), const_cast<char*>(" "), (ftnlen)8, (ftnlen)1);
/* SOURCE output.for:729 */
/*<       endif >*/
			}
/*              CASE (FLOOD_PLAIN_VELOCITY) */
/* SOURCE output.for:732 */
/*<       elseif(option.eq.flood_plain_velocity)then >*/
		    } else if (option == 23) {
/* SOURCE output.for:733 */
/*<       if(lookup_done.eq.1)then >*/
			if (feq_gen_lookup_done_d_ == 1) {
/* SOURCE output.for:734 */
/*<       aflood=atotal-amain >*/
			    aflood = static_cast<double>(atotal) - amain;
/* SOURCE output.for:735 */
/*<       qflood=qtotal*(1.0-kmain/ktotal) >*/
			    qflood = static_cast<double>(qtotal) * (static_cast<double>((float)1.) - static_cast<double>(kmain) / ktotal);
/* SOURCE output.for:736 */
/*<       if(aflood.gt.0.0)then >*/
			    if (aflood > (float)0.) {
/* SOURCE output.for:737 */
/*<       write(extra_buffer(i,j),'(F8.3)')qflood/aflood >*/
				feq_gen_ici_d_1.icierr = 0;
				feq_gen_ici_d_1.icirnum = 1;
				feq_gen_ici_d_1.icirlen = 8;
				feq_gen_ici_d_1.iciunit = spoutc_1.feq_gen_extra_buffer_d_ + (
					feq_gen_i_d_ + j * 250 - 251 << 3);
				feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.3)");
				s_wsfi(&feq_gen_ici_d_1);
				feq_gen_r_d_1 = static_cast<double>(qflood) / aflood;
				do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(
					real));
				e_wsfi();
/* SOURCE output.for:738 */
/*<       else >*/
			    } else {
/* SOURCE output.for:739 */
/*<       extra_buffer(i,j)=' ' >*/
				s_copy(spoutc_1.feq_gen_extra_buffer_d_ + (feq_gen_i_d_ + j * 
					250 - 251 << 3), const_cast<char*>(" "), (ftnlen)8, (
					ftnlen)1);
/* SOURCE output.for:740 */
/*<       endif >*/
			    }
/* SOURCE output.for:741 */
/*<       else >*/
			} else {
/* SOURCE output.for:742 */
/*<       extra_buffer(i,j)=' ' >*/
			    s_copy(spoutc_1.feq_gen_extra_buffer_d_ + (feq_gen_i_d_ + j * 250 - 
				    251 << 3), const_cast<char*>(" "), (ftnlen)8, (ftnlen)1);
/* SOURCE output.for:743 */
/*<       endif >*/
			}
/*              CASE (FLOOD_PLAIN_FLOW) */
/* SOURCE output.for:746 */
/*<       elseif(option.eq.flood_plain_flow)then >*/
		    } else if (option == 24) {
/* SOURCE output.for:747 */
/*<       if(lookup_done.eq.1)then >*/
			if (feq_gen_lookup_done_d_ == 1) {
/* SOURCE output.for:748 */
/*<       qflood=qtotal*(1.0-kmain/ktotal) >*/
			    qflood = static_cast<double>(qtotal) * (static_cast<double>((float)1.) - static_cast<double>(kmain) / ktotal);
/* SOURCE output.for:749 */
/*<       extra_buffer(i,j)=put8(qflood) >*/
			    put8_(feq_gen_ch_d_1, (ftnlen)8, &qflood);
			    s_copy(spoutc_1.feq_gen_extra_buffer_d_ + (feq_gen_i_d_ + j * 250 - 
				    251 << 3), feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE output.for:750 */
/*<       else >*/
			} else {
/* SOURCE output.for:751 */
/*<       extra_buffer(i,j)=' ' >*/
			    s_copy(spoutc_1.feq_gen_extra_buffer_d_ + (feq_gen_i_d_ + j * 250 - 
				    251 << 3), const_cast<char*>(" "), (ftnlen)8, (ftnlen)1);
/* SOURCE output.for:752 */
/*<       endif >*/
			}
/*              CASE (MAIN_CHANNEL_FLOW) */
/* SOURCE output.for:755 */
/*<       elseif(option.eq.main_channel_flow)then >*/
		    } else if (option == 25) {
/* SOURCE output.for:756 */
/*<       if(lookup_done.eq.1)then >*/
			if (feq_gen_lookup_done_d_ == 1) {
/* SOURCE output.for:757 */
/*<       qmain=qtotal*kmain/ktotal >*/
			    qmain = static_cast<double>(static_cast<double>(qtotal) * kmain) / ktotal;
/* SOURCE output.for:758 */
/*<       extra_buffer(i,j)=put8(qmain) >*/
			    put8_(feq_gen_ch_d_1, (ftnlen)8, &qmain);
			    s_copy(spoutc_1.feq_gen_extra_buffer_d_ + (feq_gen_i_d_ + j * 250 - 
				    251 << 3), feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE output.for:759 */
/*<       else >*/
			} else {
/* SOURCE output.for:760 */
/*<       extra_buffer(i,j)=' ' >*/
			    s_copy(spoutc_1.feq_gen_extra_buffer_d_ + (feq_gen_i_d_ + j * 250 - 
				    251 << 3), const_cast<char*>(" "), (ftnlen)8, (ftnlen)1);
/* SOURCE output.for:761 */
/*<       endif >*/
			}
/*              END SELECT */
/* SOURCE output.for:764 */
/*<       endif >*/
		    }
/* SOURCE output.for:766 */
/*<   300 continue >*/
/* L300: */
		}
/* SOURCE output.for:767 */
/*<       endif >*/
	    }
/* SOURCE output.for:768 */
/*<   500 continue >*/
L500:
	    ;
	}
/*       Output the extra lines.  All are complete. */
/* SOURCE output.for:771 */
/*<       do600j=1,spout_knt >*/
	feq_gen_i_d_1 = spouta_1.feq_gen_spout_knt_d_;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE output.for:772 */
/*<        >*/
	    feq_gen_io_d__101.ciunit = spouta_1.stdspout;
	    s_wsfe(&feq_gen_io_d__101);
	    do_fio(&feq_gen_c_d_1, spoutc_1.feq_gen_spout_item_label_d_ + (
		    spouta_1.feq_gen_spout_item_d_[j - 1] - 1) * 10, (ftnlen)10);
	    feq_gen_i_d_2 = *nout;
	    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_2; ++feq_gen_i_d_) {
		do_fio(&feq_gen_c_d_1, spoutc_1.feq_gen_extra_buffer_d_ + (feq_gen_i_d_ + j * 250 - 251 
			<< 3), (ftnlen)8);
	    }
	    e_wsfe();
/* SOURCE output.for:774 */
/*<   600 continue >*/
/* L600: */
	}
/* SOURCE output.for:775 */
/*<       endif >*/
    }
/* SOURCE output.for:776 */
/*<       lkount=lkount+line_knt >*/
    *lkount += spouta_1.feq_gen_line_knt_d_;
/* SOURCE output.for:778 */
/*<       if(lkount.eq.pagesp)lkount=0 >*/
    if (*lkount == miscon_1.pagesp) {
	*lkount = 0;
    }
/* SOURCE output.for:780 */
/*<       return >*/
    return 0;
/* SOURCE output.for:781 */
/*<       end >*/
} /* outsp_ */




/* SOURCE output.for:785 */
/*<        >*/
/* Subroutine */ int prtlog_(integer *stdout, integer *kount, real *feq_storage_mxrev, 
	integer *feq_storage_bmxrev, integer *feq_storage_nmxrev, real *feq_storage_mxrv, integer *feq_storage_lmxrv, real *
	feq_storage_mxssrv, integer *feq_storage_kntvec, integer *feq_storage_ivarv)
{
    /* Format strings */
    static char fmt_50[] = "(\002 Iter RCorect Bran   NodeV   MxRes EqNmbr  \
SumSqr\002,\002 NumGt IntrnlNum\002)";
    static char fmt_52[] = "(i5,1pe8.1,i5,a7,a1,1pe8.1,i7,1pe8.1,i6,i10)";

    /* System generated locals */
    address feq_gen_a_d_1[2];
    integer feq_gen_i_d_1, feq_gen_i_d_2[2], feq_gen_i_d_3;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi();

    /* Local variables */
    integer feq_gen_i_d_, bra, node;
    char nodout[7], vartype[1];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__102 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__108 = { 0, 0, 0, fmt_52, 0 };


/*     + + + PURPOSE + + + */
/*     Print a summary of the various error statistics. */
/* SOURCE output.for:792 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE output.for:794 */
/*<       integerkount,stdout >*/
/* SOURCE output.for:795 */
/*<        >*/
/* SOURCE output.for:797 */
/*<       realmxrev(kount),mxrv(kount),mxssrv(kount) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     KOUNT  - number of iterations to convergence or the maximum */
/*               number allowed */
/*     MXREV  - maximum relative correction value for each iteration */
/*     BMXREV - branch numbers for maximum relative corrections */
/*     NMXREV - maximum relative correction node for each iteration */
/*     MXRV   - maximum residual in the matrix for each iteration */
/*     LMXRV  - locations of the maximum residuals */
/*     MXSSRV - sum of squares of the residuals for each iteration */
/*     KNTVEC - number of variables that violate the primary convergence */
/*               tolerance for each iteration */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE output.for:813 */
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
/* INCLUDE output.for:814 */
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
/* SOURCE output.for:817 */
/*<       integerbra,i,node >*/
/* SOURCE output.for:818 */
/*<       characternodout*7,vartype*1 >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE output.for:821 */
/*<    50  >*/
/* SOURCE output.for:823 */
/*<    52 format(i5,1pe8.1,i5,a7,a1,1pe8.1,i7,1pe8.1,i6,i10) >*/
/* *********************************************************************** */
/* SOURCE output.for:825 */
/*<       write(stdout,50) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> ivarv(feq_storage_ivarv, 1);

    feq::IndexedPointer<integer> kntvec(feq_storage_kntvec, 1);

    feq::IndexedPointer<real> mxssrv(feq_storage_mxssrv, 1);

    feq::IndexedPointer<integer> lmxrv(feq_storage_lmxrv, 1);

    feq::IndexedPointer<real> mxrv(feq_storage_mxrv, 1);

    feq::IndexedPointer<integer> nmxrev(feq_storage_nmxrev, 1);

    feq::IndexedPointer<integer> bmxrev(feq_storage_bmxrev, 1);

    feq::IndexedPointer<real> mxrev(feq_storage_mxrev, 1);

    /* Function Body */
/* L50: */
/* L52: */
    feq_gen_io_d__102.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__102);
    e_wsfe();
/* SOURCE output.for:826 */
/*<       do100i=1,kount >*/
    feq_gen_i_d_1 = *kount;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE output.for:827 */
/*<       bra=bmxrev(i) >*/
	bra = bmxrev[feq_gen_i_d_];
/* SOURCE output.for:828 */
/*<       node=nmxrev(i) >*/
	node = nmxrev[feq_gen_i_d_];
/* SOURCE output.for:829 */
/*<       if(bra.eq.0)then >*/
	if (bra == 0) {
/*         EXTERIOR NODE */
/* SOURCE output.for:831 */
/*<       if(node.lt.0)then >*/
	    if (node < 0) {
/* SOURCE output.for:832 */
/*<       nodout=' '//inenus(-node) >*/
/* Writing concatenation */
		feq_gen_i_d_2[0] = 1, feq_gen_a_d_1[0] = const_cast<char*>(" ");
		feq_gen_i_d_2[1] = 5, feq_gen_a_d_1[1] = inenc_1.inenus + (-node - 1) * 5;
		s_cat(nodout, feq_gen_a_d_1, feq_gen_i_d_2, &feq_gen_c_d_2, (ftnlen)7);
/* SOURCE output.for:833 */
/*<       vartype='y' >*/
		*(unsigned char *)vartype = 'y';
/* SOURCE output.for:834 */
/*<       else >*/
	    } else {
/* SOURCE output.for:835 */
/*<       nodout=' '//inenus(node) >*/
/* Writing concatenation */
		feq_gen_i_d_2[0] = 1, feq_gen_a_d_1[0] = const_cast<char*>(" ");
		feq_gen_i_d_2[1] = 5, feq_gen_a_d_1[1] = inenc_1.inenus + (node - 1) * 5;
		s_cat(nodout, feq_gen_a_d_1, feq_gen_i_d_2, &feq_gen_c_d_2, (ftnlen)7);
/* SOURCE output.for:836 */
/*<       vartype='q' >*/
		*(unsigned char *)vartype = 'q';
/* SOURCE output.for:837 */
/*<       endif >*/
	    }
/* SOURCE output.for:838 */
/*<       else >*/
	} else {
/*         NODE ON A BRANCH */
/* SOURCE output.for:840 */
/*<       write(nodout,'(I7)')abs(node) >*/
	    feq_gen_ici_d_1.icierr = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 7;
	    feq_gen_ici_d_1.iciunit = nodout;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(I7)");
	    s_wsfi(&feq_gen_ici_d_1);
	    feq_gen_i_d_3 = abs(node);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_3, (ftnlen)sizeof(integer));
	    e_wsfi();
/* SOURCE output.for:841 */
/*<       if(node.lt.0)then >*/
	    if (node < 0) {
/* SOURCE output.for:842 */
/*<       vartype='y' >*/
		*(unsigned char *)vartype = 'y';
/* SOURCE output.for:843 */
/*<       else >*/
	    } else {
/* SOURCE output.for:844 */
/*<       vartype='q' >*/
		*(unsigned char *)vartype = 'q';
/* SOURCE output.for:845 */
/*<       endif >*/
	    }
/* SOURCE output.for:846 */
/*<       bra=inbrus(bra) >*/
	    bra = inbr_1.inbrus[bra - 1];
/* SOURCE output.for:847 */
/*<       endif >*/
	}
/* SOURCE output.for:849 */
/*<        >*/
	feq_gen_io_d__108.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__108);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&mxrev[feq_gen_i_d_], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&bra, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, nodout, (ftnlen)7);
	do_fio(&feq_gen_c_d_1, vartype, (ftnlen)1);
	do_fio(&feq_gen_c_d_1, (char *)&mxrv[feq_gen_i_d_], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&lmxrv[feq_gen_i_d_], (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&mxssrv[feq_gen_i_d_], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&kntvec[feq_gen_i_d_], (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&ivarv[feq_gen_i_d_], (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE output.for:852 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE output.for:854 */
/*<       return >*/
    return 0;
/* SOURCE output.for:855 */
/*<       end >*/
} /* prtlog_ */




/* SOURCE output.for:859 */
/*<        >*/
/* Subroutine */ int putfc_(integer *stdout, integer *putdsn, char *feq_gen_name_d_, 
	real *wt, integer *nbra, integer *nbn, integer *nex, doublereal *
	jtime, integer *nblk, integer *feq_storage_opblk, real *siter, doublereal *dt, 
	integer *bnode, integer *feq_storage_exnodt, ftnlen name_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 Final conditions saved at JTIME=\002,f20\
.10)";

    /* System generated locals */
    olist feq_gen_o_d_1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), f_open(olist *), s_wsle(
	    cilist *), do_lio(integer *, integer *, char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wdue(cilist *), do_uio(integer *, char *, ftnlen), e_wdue(), 
	    s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    extern /* Subroutine */ int feq_gen_free_unit_d_(integer *, integer *);
    integer bwrec, dummy;
    extern /* Subroutine */ int bwput_(integer *, real *, integer *, integer *
	    , integer *, integer *, integer *, integer *);
    integer ioflag;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__110 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__111 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__114 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__115 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__116 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__117 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__118 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__119 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Put current state of system into dataset given by PUTDSN. */
/* SOURCE output.for:866 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE output.for:868 */
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
/* SOURCE output.for:871 */
/*<       integerbnode,nblk,nbn,nbra,nex,putdsn,stdout >*/
/* SOURCE output.for:872 */
/*<       integerexnodt(9,nex),opblk(mnblk) >*/
/* SOURCE output.for:873 */
/*<       realsiter,wt >*/
/* SOURCE output.for:874 */
/*<       real*8dt,jtime >*/
/* SOURCE output.for:875 */
/*<       charactername*256 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - standard output unit for user messages */
/*     PUTDSN - unit number for storing final conditions */
/*     NAME   - name of the file for storing the final conditions */
/*     WT     - weight factor for approximating time integrals */
/*     NBRA   - number of branches in the model */
/*     NBN    - total number on nodes on branches in the model */
/*     NEX    - number of exterior nodes in the model */
/*     JTIME  - current modified julian time in the model */
/*     NBLK   - number of operation blocks */
/*     OPBLK  - pointer into the function table storage(FTAB/ITAB) for */
/*               each operation block. */
/*     SITER  - weighted sum of iterations to convergence */
/*     DT     - time step in seconds */
/*     BNODE  - boundary node number at which to start defining the */
/*               coefficient matrix */

/*     + + + COMMON BLOCKS + + + */
/* INCLUDE output.for:896 */
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
/* SOURCE output.for:899 */
/*<       integerioflag,bwrec,dummy >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE output.for:902 */
/*<       externalbwput,free_unit >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE output.for:905 */
/*<    50 format(/,' Final conditions saved at JTIME=',f20.10) >*/
/* *********************************************************************** */
/*     OPEN THE FILE */
/* SOURCE output.for:908 */
/*<       if(name.eq.' ')then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> opblk(feq_storage_opblk, 1);

    /* Function Body */
/* L50: */
    if (s_cmp(feq_gen_name_d_, const_cast<char*>(" "), (ftnlen)256, (ftnlen)1) == 0) {
/* SOURCE output.for:909 */
/*<        >*/
	feq_gen_o_d_1.oerr = 0;
	feq_gen_o_d_1.ounit = *putdsn;
	feq_gen_o_d_1.ofnmlen = 4;
	feq_gen_o_d_1.ofnm = const_cast<char*>("PUTD");
	feq_gen_o_d_1.orl = 8;
	feq_gen_o_d_1.osta = const_cast<char*>("NEW");
	feq_gen_o_d_1.oacc = const_cast<char*>("direct");
	feq_gen_o_d_1.ofm = const_cast<char*>("UNFORMATTED");
	feq_gen_o_d_1.oblnk = 0;
	f_open(&feq_gen_o_d_1);
/* SOURCE output.for:911 */
/*<       else >*/
    } else {
/* SOURCE output.for:912 */
/*<        >*/
	feq_gen_o_d_1.oerr = 1;
	feq_gen_o_d_1.ounit = *putdsn;
	feq_gen_o_d_1.ofnmlen = 256;
	feq_gen_o_d_1.ofnm = feq_gen_name_d_;
	feq_gen_o_d_1.orl = 8;
	feq_gen_o_d_1.osta = const_cast<char*>("UNKNOWN");
	feq_gen_o_d_1.oacc = const_cast<char*>("direct");
	feq_gen_o_d_1.ofm = const_cast<char*>("UNFORMATTED");
	feq_gen_o_d_1.oblnk = 0;
	ioflag = f_open(&feq_gen_o_d_1);
/* SOURCE output.for:915 */
/*<       if(ioflag.ne.0)then >*/
	if (ioflag != 0) {
/* SOURCE output.for:916 */
/*<       write(std6,*)' PROBLEM IN OPENING FILE: ',name >*/
	    feq_gen_io_d__110.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsle(&feq_gen_io_d__110);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" PROBLEM IN OPENING FILE: "), (ftnlen)26);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)256);
	    e_wsle();
/* SOURCE output.for:917 */
/*<       write(std6,*)' CHECK PATH FOR FINAL CONDITIONS FILE.' >*/
	    feq_gen_io_d__111.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsle(&feq_gen_io_d__111);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" CHECK PATH FOR FINAL CONDITIONS FILE."), (
		    ftnlen)38);
	    e_wsle();
/* SOURCE output.for:918 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE output.for:919 */
/*<       endif >*/
	}
/* SOURCE output.for:920 */
/*<       endif >*/
    }
/*     WRITE SIZE INFORMATION SO THAT WE CAN CHECK FOR AGREEMENT */
/*     AND CATCH MANY MISTAKES IN SPECIFYING A FILE. */
/* SOURCE output.for:925 */
/*<       bwrec=1 >*/
    bwrec = 1;
/* SOURCE output.for:926 */
/*<       dummy=0 >*/
    dummy = 0;
/*      WRITE(PUTDSN) NBRA, NBN, NEX, JTIME, SITER, DT, BNODE */
/* SOURCE output.for:928 */
/*<       write(putdsn,rec=bwrec)nbra,nbn >*/
    feq_gen_io_d__114.ciunit = *putdsn;
    feq_gen_io_d__114.cirec = bwrec;
    s_wdue(&feq_gen_io_d__114);
    do_uio(&feq_gen_c_d_1, (char *)&(*nbra), (ftnlen)sizeof(integer));
    do_uio(&feq_gen_c_d_1, (char *)&(*nbn), (ftnlen)sizeof(integer));
    e_wdue();
/* SOURCE output.for:929 */
/*<       bwrec=bwrec+1 >*/
    ++bwrec;
/* SOURCE output.for:930 */
/*<       write(putdsn,rec=bwrec)nex,siter >*/
    feq_gen_io_d__115.ciunit = *putdsn;
    feq_gen_io_d__115.cirec = bwrec;
    s_wdue(&feq_gen_io_d__115);
    do_uio(&feq_gen_c_d_1, (char *)&(*nex), (ftnlen)sizeof(integer));
    do_uio(&feq_gen_c_d_1, (char *)&(*siter), (ftnlen)sizeof(real));
    e_wdue();
/* SOURCE output.for:931 */
/*<       bwrec=bwrec+1 >*/
    ++bwrec;
/* SOURCE output.for:932 */
/*<       write(putdsn,rec=bwrec)bnode,dummy >*/
    feq_gen_io_d__116.ciunit = *putdsn;
    feq_gen_io_d__116.cirec = bwrec;
    s_wdue(&feq_gen_io_d__116);
    do_uio(&feq_gen_c_d_1, (char *)&(*bnode), (ftnlen)sizeof(integer));
    do_uio(&feq_gen_c_d_1, (char *)&dummy, (ftnlen)sizeof(integer));
    e_wdue();
/* SOURCE output.for:933 */
/*<       bwrec=bwrec+1 >*/
    ++bwrec;
/* SOURCE output.for:934 */
/*<       write(putdsn,rec=bwrec)jtime >*/
    feq_gen_io_d__117.ciunit = *putdsn;
    feq_gen_io_d__117.cirec = bwrec;
    s_wdue(&feq_gen_io_d__117);
    do_uio(&feq_gen_c_d_1, (char *)&(*jtime), (ftnlen)sizeof(doublereal));
    e_wdue();
/* SOURCE output.for:935 */
/*<       bwrec=bwrec+1 >*/
    ++bwrec;
/* SOURCE output.for:936 */
/*<       write(putdsn,rec=bwrec)dt >*/
    feq_gen_io_d__118.ciunit = *putdsn;
    feq_gen_io_d__118.cirec = bwrec;
    s_wdue(&feq_gen_io_d__118);
    do_uio(&feq_gen_c_d_1, (char *)&(*dt), (ftnlen)sizeof(doublereal));
    e_wdue();
/* SOURCE output.for:937 */
/*<       bwrec=bwrec+1 >*/
    ++bwrec;
/* SOURCE output.for:939 */
/*<       callbwput(putdsn,wt,nbra,nbn,nex,nblk,opblk,bwrec) >*/
    bwput_(putdsn, wt, nbra, nbn, nex, nblk, &opblk[1], &bwrec);
/* SOURCE output.for:943 */
/*<       callfree_unit(std6,putdsn) >*/
    feq_gen_free_unit_d_(&feq_gen_stdun_com_d_1.std6, putdsn);
/* SOURCE output.for:944 */
/*<       write(stdout,50)jtime >*/
    feq_gen_io_d__119.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__119);
    do_fio(&feq_gen_c_d_1, (char *)&(*jtime), (ftnlen)sizeof(doublereal));
    e_wsfe();
/* SOURCE output.for:945 */
/*<       return >*/
    return 0;
/* SOURCE output.for:946 */
/*<       end >*/
} /* putfc_ */

/*     *********** */
/*     *         * */
/*     * RDQUIT  * */
/*     *         * */
/*     *********** */
/* SOURCE output.for:953 */
/*<       subroutinerdquit(stdout) >*/
/* Subroutine */ int rdquit_(integer *stdout)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 Dual-source TS file: \002,a,/,5x,\002has\
 been deleted.\002)";
    static char fmt_52[] = "(/,\002 *BUG* in rdquit: Invalid value in delete\
 list.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    cllist feq_gen_cl_d_1;

    /* Builtin functions */
    integer f_clos(cllist *), s_wsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;
    extern /* Subroutine */ int feq_gen_free_unit_d_(integer *, integer *);
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__121 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__122 = { 0, 0, 0, fmt_52, 0 };


/*     Close any files used for input of flow or elevation. */
/* SOURCE output.for:957 */
/*<       implicitnone >*/
/* SOURCE output.for:958 */
/*<       integerstdout >*/
/* INCLUDE output.for:960 */
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
/* INCLUDE output.for:961 */
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
/*     Local */
/* SOURCE output.for:965 */
/*<       integeri >*/
/*     External names */
/* SOURCE output.for:969 */
/*<       externalfree_unit >*/
/*     **************************formats********************************* */
/* SOURCE output.for:953 */
/*<       integer feq_len_trim >*/
/* SOURCE output.for:953 */
/*<       external feq_len_trim >*/
/* SOURCE output.for:971 */
/*<    50 format(/,' Dual-source TS file: ',a,/,5x,'has been deleted.') >*/
/* SOURCE output.for:972 */
/*<    52 format(/,' *BUG* in rdquit: Invalid value in delete list.') >*/
/* *********************************************************************** */
/* SOURCE output.for:974 */
/*<       do100i=1,num_ts_f >*/
/* L50: */
/* L52: */
    feq_gen_i_d_1 = rdcom_1.feq_gen_num_ts_f_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE output.for:975 */
/*<       if(dss_index_in(i).eq.0)then >*/
	if (rdcom_1.feq_gen_dss_index_in_d_[feq_gen_i_d_ - 1] == 0) {
/*         This is a file and not a path in a HECDSS */
/* SOURCE output.for:977 */
/*<       if(delete_list(i)==0)then >*/
	    if (rdcom_1.feq_gen_delete_list_d_[feq_gen_i_d_ - 1] == 0) {
/* SOURCE output.for:978 */
/*<       callfree_unit(stdout,unin(i)) >*/
		feq_gen_free_unit_d_(stdout, &rdcom_1.unin[feq_gen_i_d_ - 1]);
/* SOURCE output.for:979 */
/*<       elseif(delete_list(i)==1)then >*/
	    } else if (rdcom_1.feq_gen_delete_list_d_[feq_gen_i_d_ - 1] == 1) {
/*           Request that this file be deleted on close.  Note: we do not */
/*           need to update FEQ's unit-numnber tracking system--the run */
/*           is over:) */
/* SOURCE output.for:983 */
/*<       close(unin(i),status='delete') >*/
		feq_gen_cl_d_1.cerr = 0;
		feq_gen_cl_d_1.cunit = rdcom_1.unin[feq_gen_i_d_ - 1];
		feq_gen_cl_d_1.csta = const_cast<char*>("delete");
		f_clos(&feq_gen_cl_d_1);
/* SOURCE output.for:984 */
/*<       write(stdout,50)namin(i)(1:feq_len_trim(namin(i))) >*/
		feq_gen_io_d__121.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__121);
		do_fio(&feq_gen_c_d_1, rdcomc_1.namin + (feq_gen_i_d_ - 1 << 8), feq_gen_feq_len_trim_d_(
			rdcomc_1.namin + (feq_gen_i_d_ - 1 << 8), (ftnlen)256));
		e_wsfe();
/* SOURCE output.for:985 */
/*<       else >*/
	    } else {
/* SOURCE output.for:986 */
/*<       write(stdout,52) >*/
		feq_gen_io_d__122.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__122);
		e_wsfe();
/* SOURCE output.for:987 */
/*<       stop'Abnormal stop: bug found in subroutine rdquit:(' >*/
		s_stop(const_cast<char*>("Abnormal stop: bug found in subroutine rdquit:("), (
			ftnlen)47);
/* SOURCE output.for:988 */
/*<       endif >*/
	    }
/* SOURCE output.for:989 */
/*<       endif >*/
	}
/* SOURCE output.for:990 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE output.for:991 */
/*<       return >*/
    return 0;
/* SOURCE output.for:992 */
/*<       end >*/
} /* rdquit_ */




/* SOURCE output.for:996 */
/*<        >*/
/* Subroutine */ int resout_(real *grav, real *vunit, integer *stdout, 
	integer *nbra, char *nodeid, integer *nex, doublereal *time, real *
	sfac, integer *feq_storage_brpt, integer *feq_storage_exnodt, real *qchop, real *
	feq_gen_dz_for_output_d_, ftnlen nodeid_len)
{
    /* Format strings */
    static char fmt_2000[] = "(/,\002 RESULTS at JTIME = \002,f20.10)";
    static char fmt_2010[] = "(/,\002 BRANCH NUMBER = \002,i5)";
    static char fmt_2022[] = "(\002  Node  Node Identifier     Stat    Flow \
   Area   Vel\002,\002  Depth    Elev     Top  Fr Lat Inf\002)";
    static char fmt_2040[] = "(/,\002 EXTERIOR NODES\002)";
    static char fmt_2052[] = "(\002  Node  Node Identifier\002,8x,\002QE1\
\002,5x,\002YE1\002,4x,\002Elev    Storage    Storage\002)";
    static char fmt_2062[] = "(1x,a5,1x,a16,1pe11.5e1,2(0pf8.3))";
    static char fmt_2070[] = "(/,\002       Branch ponding volume = \002,1pe\
12.4,a6,0pf10.1,a6)";
    static char fmt_2080[] = "(/,\002     Network ponding volume = \002,1pe1\
2.4,a6,0pf10.1,a6)";
    static char fmt_2092[] = "(1x,a5,1x,a16,1pe11.5e1,2(0pf8.3),2(1pe11.3))";
    static char fmt_18000[] = "(i6,1x,a16,f9.0,a8,a8,f6.2,f7.2,f8.2,a8,f4.1,\
a8)";
    static char fmt_18100[] = "(i6,1x,a16,f9.1,a8,a8,f6.2,f7.2,f8.2,a8,f4.1,\
a8)";
    static char fmt_18200[] = "(i6,1x,a16,f9.2,a8,a8,f6.2,f7.2,f8.2,a8,f4.1,\
a8)";
    static char fmt_18300[] = "(i6,1x,a16,f9.3,a8,a8,f6.2,f7.2,f8.2,a8,f4.1,\
a8)";
    static char fmt_18400[] = "(i6,1x,a16,f9.4,a8,a8,f6.2,f7.2,f8.2,a8,f4.1,\
a8)";
    static char fmt_19000[] = "(i6,1x,a16,f9.1,a8,a8,f6.3,f7.3,f8.3,a8,f4.1,\
a8)";
    static char fmt_19100[] = "(i6,1x,a16,f9.2,a8,a8,f6.3,f7.3,f8.3,a8,f4.1,\
a8)";
    static char fmt_19200[] = "(i6,1x,a16,f9.3,a8,a8,f6.3,f7.3,f8.3,a8,f4.1,\
a8)";
    static char fmt_19300[] = "(i6,1x,a16,f9.4,a8,a8,f6.3,f7.3,f8.3,a8,f4.1,\
a8)";
    static char fmt_19400[] = "(i6,1x,a16,f9.5,a8,a8,f6.3,f7.3,f8.3,a8,f4.1,\
a8)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3, feq_gen_r_d_4;
    char feq_gen_ch_d_1[8];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    real feq_gen_z_d_;
    integer fa, la, nb, ii, fn;
    real fr, st;
    integer nad, knt;
    real sum;
    extern /* Character */ VOID put8_(char *, ftnlen, real *);
    char latc[8];
    real elev, temp;
    char topc[8];
    real qput;
    char areac[8];
    real ytemp;
    char flowc[8];
    integer addflg;
    real brasum;
    extern doublereal froude_(integer *, real *, real *, real *, real *, real 
	    *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__123 = { 0, 0, 0, fmt_2000, 0 };
    static cilist feq_gen_io_d__129 = { 0, 0, 0, fmt_2010, 0 };
    static cilist feq_gen_io_d__130 = { 0, 0, 0, fmt_2022, 0 };
    static cilist feq_gen_io_d__143 = { 0, 0, 0, fmt_18000, 0 };
    static cilist feq_gen_io_d__144 = { 0, 0, 0, fmt_18100, 0 };
    static cilist feq_gen_io_d__145 = { 0, 0, 0, fmt_18200, 0 };
    static cilist feq_gen_io_d__146 = { 0, 0, 0, fmt_18300, 0 };
    static cilist feq_gen_io_d__147 = { 0, 0, 0, fmt_18400, 0 };
    static cilist feq_gen_io_d__148 = { 0, 0, 0, fmt_19000, 0 };
    static cilist feq_gen_io_d__149 = { 0, 0, 0, fmt_19100, 0 };
    static cilist feq_gen_io_d__150 = { 0, 0, 0, fmt_19200, 0 };
    static cilist feq_gen_io_d__151 = { 0, 0, 0, fmt_19300, 0 };
    static cilist feq_gen_io_d__152 = { 0, 0, 0, fmt_19400, 0 };
    static cilist feq_gen_io_d__154 = { 0, 0, 0, fmt_18000, 0 };
    static cilist feq_gen_io_d__155 = { 0, 0, 0, fmt_18100, 0 };
    static cilist feq_gen_io_d__156 = { 0, 0, 0, fmt_18200, 0 };
    static cilist feq_gen_io_d__157 = { 0, 0, 0, fmt_18300, 0 };
    static cilist feq_gen_io_d__158 = { 0, 0, 0, fmt_18400, 0 };
    static cilist feq_gen_io_d__159 = { 0, 0, 0, fmt_19000, 0 };
    static cilist feq_gen_io_d__160 = { 0, 0, 0, fmt_19100, 0 };
    static cilist feq_gen_io_d__161 = { 0, 0, 0, fmt_19200, 0 };
    static cilist feq_gen_io_d__162 = { 0, 0, 0, fmt_19300, 0 };
    static cilist feq_gen_io_d__163 = { 0, 0, 0, fmt_19400, 0 };
    static cilist feq_gen_io_d__165 = { 0, 0, 0, fmt_2070, 0 };
    static cilist feq_gen_io_d__166 = { 0, 0, 0, fmt_2070, 0 };
    static cilist feq_gen_io_d__167 = { 0, 0, 0, fmt_2080, 0 };
    static cilist feq_gen_io_d__168 = { 0, 0, 0, fmt_2080, 0 };
    static cilist feq_gen_io_d__169 = { 0, 0, 0, fmt_2040, 0 };
    static cilist feq_gen_io_d__170 = { 0, 0, 0, fmt_2052, 0 };
    static cilist feq_gen_io_d__173 = { 0, 0, 0, fmt_2092, 0 };
    static cilist feq_gen_io_d__174 = { 0, 0, 0, fmt_2062, 0 };


/*     + + + PURPOSE + + + */
/*     Output results. */
/* SOURCE output.for:1003 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE output.for:1005 */
/*<       integerstdout,nbra,nex >*/
/* SOURCE output.for:1006 */
/*<       integerbrpt(8,nbra),exnodt(9,nex) >*/
/* SOURCE output.for:1007 */
/*<       realgrav,qchop,sfac,vunit,dz_for_output >*/
/* SOURCE output.for:1008 */
/*<       real*8time >*/
/* SOURCE output.for:1009 */
/*<       characternodeid*4 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     GRAV   - value of acceleration due to gravity */
/*     VUNIT  - conversion factor for volumes on output */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     NBRA   - number of branches in the model */
/*     NODEID - user node identification string */
/*     NEX    - number of exterior nodes in the model */
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
/*     QCHOP  - chopping value for output of flow */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE output.for:1047 */
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
/* INCLUDE output.for:1048 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE output.for:1049 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE output.for:1050 */
/* ********************************************************************** */
/* SOURCE bnpond.cmn:3 */
/*<       common/bnpond/coefin,pond1,pond2,ycut,bpond,bpmax >*/
/* SOURCE bnpond.cmn:5 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE output.for:1051 */
/* ********************************************************************** */
/* SOURCE julian.cmn:3 */
/*<        >*/
/* SOURCE julian.cmn:8 */
/*<       integeryr,mn,dy,syr,smn,sdy,eyr,emn,edy,reset,leap,dmyear,dmmn >*/
/* SOURCE julian.cmn:10 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE output.for:1052 */
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
/* INCLUDE output.for:1053 */
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
/* INCLUDE output.for:1054 */
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
/* SOURCE output.for:1057 */
/*<       integeraddflg,fa,fn,ii,knt,la,nad,nb >*/
/* SOURCE output.for:1058 */
/*<       realbrasum,elev,fr,qput,st,sum,temp,ytemp,z >*/
/* SOURCE output.for:1059 */
/*<       characterareac*8,flowc*8,latc*8,topc*8 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE output.for:1062 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE output.for:1065 */
/*<       realfroude >*/
/* SOURCE output.for:1066 */
/*<       characterput8*8 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE output.for:1069 */
/*<       externalfroude,put8 >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE output.for:1072 */
/*<  2000 format(/,' RESULTS at JTIME = ',f20.10) >*/
/* 2000 FORMAT(/,' RESULTS at time ',F16.1,' JTIME = ',F20.10) */
/* SOURCE output.for:1074 */
/*<  2010 format(/,' BRANCH NUMBER = ',i5) >*/
/* SOURCE output.for:1075 */
/*<  2022  >*/
/* SOURCE output.for:1077 */
/*<  2030 format(i5,f8.3,1pe11.3,1pe10.3,0pf6.2,f7.2,f8.2,f8.1,f5.1,1pe8.1) >*/
/* SOURCE output.for:1078 */
/*<  2040 format(/,' EXTERIOR NODES') >*/
/* SOURCE output.for:1079 */
/*<  2052  >*/
/* SOURCE output.for:1081 */
/*<  2062 format(1x,a5,1x,a16,1pe11.5e1,2(0pf8.3)) >*/
/* SOURCE output.for:1082 */
/*<  2070 format(/,'       Branch ponding volume = ',1pe12.4,a6,0pf10.1,a6) >*/
/* SOURCE output.for:1084 */
/*<  2080 format(/,'     Network ponding volume = ',1pe12.4,a6,0pf10.1,a6) >*/
/* SOURCE output.for:1086 */
/*<  2092 format(1x,a5,1x,a16,1pe11.5e1,2(0pf8.3),2(1pe11.3)) >*/
/*     Formats for US standard unit set. */
/* SOURCE output.for:1088 */
/*< 18000 format(i6,1x,a16,f9.0,a8,a8,f6.2,f7.2,f8.2,a8,f4.1,a8) >*/
/* SOURCE output.for:1089 */
/*< 18100 format(i6,1x,a16,f9.1,a8,a8,f6.2,f7.2,f8.2,a8,f4.1,a8) >*/
/* SOURCE output.for:1090 */
/*< 18200 format(i6,1x,a16,f9.2,a8,a8,f6.2,f7.2,f8.2,a8,f4.1,a8) >*/
/* SOURCE output.for:1091 */
/*< 18300 format(i6,1x,a16,f9.3,a8,a8,f6.2,f7.2,f8.2,a8,f4.1,a8) >*/
/* SOURCE output.for:1092 */
/*< 18400 format(i6,1x,a16,f9.4,a8,a8,f6.2,f7.2,f8.2,a8,f4.1,a8) >*/
/*     Formats for metric unit set. */
/* SOURCE output.for:1094 */
/*< 19000 format(i6,1x,a16,f9.1,a8,a8,f6.3,f7.3,f8.3,a8,f4.1,a8) >*/
/* SOURCE output.for:1095 */
/*< 19100 format(i6,1x,a16,f9.2,a8,a8,f6.3,f7.3,f8.3,a8,f4.1,a8) >*/
/* SOURCE output.for:1096 */
/*< 19200 format(i6,1x,a16,f9.3,a8,a8,f6.3,f7.3,f8.3,a8,f4.1,a8) >*/
/* SOURCE output.for:1097 */
/*< 19300 format(i6,1x,a16,f9.4,a8,a8,f6.3,f7.3,f8.3,a8,f4.1,a8) >*/
/* SOURCE output.for:1098 */
/*< 19400 format(i6,1x,a16,f9.5,a8,a8,f6.3,f7.3,f8.3,a8,f4.1,a8) >*/
/* *********************************************************************** */
/*     TITLE */
/* SOURCE output.for:1103 */
/*<       write(stdout,2000)jtime >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    /* Function Body */
/* L2000: */
/* L2010: */
/* L2022: */
/* L2030: */
/* L2040: */
/* L2052: */
/* L2062: */
/* L2070: */
/* L2080: */
/* L2092: */
/* L18000: */
/* L18100: */
/* L18200: */
/* L18300: */
/* L18400: */
/* L19000: */
/* L19100: */
/* L19200: */
/* L19300: */
/* L19400: */
    feq_gen_io_d__123.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__123);
    do_fio(&feq_gen_c_d_1, (char *)&julian_1.jtime, (ftnlen)sizeof(doublereal));
    e_wsfe();
/*     WRITE OUT RESULTS ETC FOR INTERIOR NODES */
/* SOURCE output.for:1107 */
/*<       sum=0.0 >*/
    sum = (float)0.;
/*     I) BRANCH LOOP */
/* SOURCE output.for:1111 */
/*<       do100nb=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (nb = 1; nb <= feq_gen_i_d_1; ++nb) {
/* SOURCE output.for:1112 */
/*<       fn=brpt(1,nb)-1 >*/
	fn = brpt[(nb << 3) + 1] - 1;
/*        LN = BRPT(2,NB) */
/* SOURCE output.for:1114 */
/*<       fa=brpt(3,nb) >*/
	fa = brpt[(nb << 3) + 3];
/* SOURCE output.for:1115 */
/*<       la=brpt(4,nb) >*/
	la = brpt[(nb << 3) + 4];
/* SOURCE output.for:1116 */
/*<       write(stdout,2010)inbrus(nb) >*/
	feq_gen_io_d__129.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__129);
	do_fio(&feq_gen_c_d_1, (char *)&inbr_1.inbrus[nb - 1], (ftnlen)sizeof(integer))
		;
	e_wsfe();
/* SOURCE output.for:1117 */
/*<       write(stdout,2022) >*/
	feq_gen_io_d__130.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__130);
	e_wsfe();
/* SOURCE output.for:1119 */
/*<       if(addvec(nb).lt.0)then >*/
	if (bnothr_1.addvec[nb - 1] < 0) {
/*         DO NOT OUTPUT ADDED NODES. */
/* SOURCE output.for:1121 */
/*<       addflg=abs(addvec(nb)) >*/
	    addflg = (feq_gen_i_d_2 = bnothr_1.addvec[nb - 1], abs(feq_gen_i_d_2));
/* SOURCE output.for:1122 */
/*<       else >*/
	} else {
/* SOURCE output.for:1123 */
/*<       addflg=0 >*/
	    addflg = 0;
/* SOURCE output.for:1124 */
/*<       endif >*/
	}
/*       II) NODE LOOP */
/*       ALWAYS OUTPUT THE FIRST NODE ON THE BRANCH */
/* SOURCE output.for:1127 */
/*<       nad=fa >*/
	nad = fa;
/* SOURCE output.for:1128 */
/*<       fn=fn+1 >*/
	++fn;
/* SOURCE output.for:1129 */
/*<       fr=froude(nsec(nad),y1(nad),q1(nad),a1(nad),t1(nad),grav) >*/
	fr = froude_(&bnothr_1.nsec[nad - 1], &bnelem_1.y1[nad - 1], &
		bnelem_1.q1[nad - 1], &bnelem_1.a1[nad - 1], &bnelem_1.t1[nad 
		- 1], grav);
/* SOURCE output.for:1131 */
/*<       z=y1(nad)+zvec(nad)+dz_for_output >*/
	feq_gen_z_d_ = static_cast<double>(static_cast<double>(bnelem_1.y1[nad - 1]) + bnelem_1.zvec[nad - 1]) + *
		feq_gen_dz_for_output_d_;
/* SOURCE output.for:1132 */
/*<       st=xvec(nad)/sfac >*/
	st = static_cast<double>(bnelem_1.xvec[nad - 1]) / *sfac;
/* SOURCE output.for:1133 */
/*<       temp=0.0 >*/
	temp = (float)0.;
/* SOURCE output.for:1134 */
/*<       qput=q1(nad) >*/
	qput = bnelem_1.q1[nad - 1];
/* SOURCE output.for:1135 */
/*<       if(abs(qput).le.qchop)then >*/
	if (dabs(qput) <= *qchop) {
/* SOURCE output.for:1136 */
/*<       qput=0.0 >*/
	    qput = (float)0.;
/* SOURCE output.for:1137 */
/*<       endif >*/
	}
/*        IF(NODEID.EQ.'NO') THEN */
/*          WRITE(STDOUT,2030) FN, ST, QPUT, A1(NAD), QPUT/A1(NAD), */
/*     A              Y1(NAD), Z, T1(NAD), FR, TEMP */
/*        ELSE */
/* SOURCE output.for:1142 */
/*<       flowc=put8(qput) >*/
	put8_(feq_gen_ch_d_1, (ftnlen)8, &qput);
	s_copy(flowc, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE output.for:1143 */
/*<       areac=put8(a1(nad)) >*/
	put8_(feq_gen_ch_d_1, (ftnlen)8, &bnelem_1.a1[nad - 1]);
	s_copy(areac, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE output.for:1144 */
/*<       topc=put8(t1(nad)) >*/
	put8_(feq_gen_ch_d_1, (ftnlen)8, &bnelem_1.t1[nad - 1]);
	s_copy(topc, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE output.for:1145 */
/*<       latc=put8(temp) >*/
	put8_(feq_gen_ch_d_1, (ftnlen)8, &temp);
	s_copy(latc, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE output.for:1146 */
/*<       ytemp=y1(nad)+sdvec(nad) >*/
	ytemp = static_cast<double>(bnelem_1.y1[nad - 1]) + bnelem_1.sdvec[nad - 1];
/* SOURCE output.for:1147 */
/*<       goto(60,61,62,63,64,70,71,72,73,74),ftid >*/
	switch (bnelem_1.ftid) {
	    case 1:  goto L60;
	    case 2:  goto L61;
	    case 3:  goto L62;
	    case 4:  goto L63;
	    case 5:  goto L64;
	    case 6:  goto L70;
	    case 7:  goto L71;
	    case 8:  goto L72;
	    case 9:  goto L73;
	    case 10:  goto L74;
	}
/* SOURCE output.for:1148 */
/*<    60 continue >*/
L60:
/* SOURCE output.for:1149 */
/*<        >*/
	feq_gen_io_d__143.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__143);
	do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, flowc, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, areac, (ftnlen)8);
	feq_gen_r_d_1 = static_cast<double>(qput) / bnelem_1.a1[nad - 1];
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&ytemp, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, topc, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&fr, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, latc, (ftnlen)8);
	e_wsfe();
/* SOURCE output.for:1151 */
/*<       goto99 >*/
	goto L99;
/* SOURCE output.for:1152 */
/*<    61 continue >*/
L61:
/* SOURCE output.for:1153 */
/*<        >*/
	feq_gen_io_d__144.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__144);
	do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, flowc, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, areac, (ftnlen)8);
	feq_gen_r_d_1 = static_cast<double>(qput) / bnelem_1.a1[nad - 1];
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&ytemp, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, topc, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&fr, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, latc, (ftnlen)8);
	e_wsfe();
/* SOURCE output.for:1155 */
/*<       goto99 >*/
	goto L99;
/* SOURCE output.for:1156 */
/*<    62 continue >*/
L62:
/* SOURCE output.for:1157 */
/*<        >*/
	feq_gen_io_d__145.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__145);
	do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, flowc, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, areac, (ftnlen)8);
	feq_gen_r_d_1 = static_cast<double>(qput) / bnelem_1.a1[nad - 1];
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&ytemp, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, topc, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&fr, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, latc, (ftnlen)8);
	e_wsfe();
/* SOURCE output.for:1159 */
/*<       goto99 >*/
	goto L99;
/* SOURCE output.for:1160 */
/*<    63 continue >*/
L63:
/* SOURCE output.for:1161 */
/*<        >*/
	feq_gen_io_d__146.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__146);
	do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, flowc, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, areac, (ftnlen)8);
	feq_gen_r_d_1 = static_cast<double>(qput) / bnelem_1.a1[nad - 1];
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&ytemp, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, topc, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&fr, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, latc, (ftnlen)8);
	e_wsfe();
/* SOURCE output.for:1163 */
/*<       goto99 >*/
	goto L99;
/* SOURCE output.for:1164 */
/*<    64 continue >*/
L64:
/* SOURCE output.for:1165 */
/*<        >*/
	feq_gen_io_d__147.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__147);
	do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, flowc, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, areac, (ftnlen)8);
	feq_gen_r_d_1 = static_cast<double>(qput) / bnelem_1.a1[nad - 1];
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&ytemp, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, topc, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&fr, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, latc, (ftnlen)8);
	e_wsfe();
/* SOURCE output.for:1167 */
/*<       goto99 >*/
	goto L99;
/* SOURCE output.for:1168 */
/*<    70 continue >*/
L70:
/* SOURCE output.for:1169 */
/*<        >*/
	feq_gen_io_d__148.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__148);
	do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, flowc, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, areac, (ftnlen)8);
	feq_gen_r_d_1 = static_cast<double>(qput) / bnelem_1.a1[nad - 1];
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&ytemp, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, topc, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&fr, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, latc, (ftnlen)8);
	e_wsfe();
/* SOURCE output.for:1171 */
/*<       goto99 >*/
	goto L99;
/* SOURCE output.for:1172 */
/*<    71 continue >*/
L71:
/* SOURCE output.for:1173 */
/*<        >*/
	feq_gen_io_d__149.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__149);
	do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, flowc, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, areac, (ftnlen)8);
	feq_gen_r_d_1 = static_cast<double>(qput) / bnelem_1.a1[nad - 1];
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&ytemp, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, topc, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&fr, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, latc, (ftnlen)8);
	e_wsfe();
/* SOURCE output.for:1175 */
/*<       goto99 >*/
	goto L99;
/* SOURCE output.for:1176 */
/*<    72 continue >*/
L72:
/* SOURCE output.for:1177 */
/*<        >*/
	feq_gen_io_d__150.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__150);
	do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, flowc, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, areac, (ftnlen)8);
	feq_gen_r_d_1 = static_cast<double>(qput) / bnelem_1.a1[nad - 1];
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&ytemp, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, topc, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&fr, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, latc, (ftnlen)8);
	e_wsfe();
/* SOURCE output.for:1179 */
/*<       goto99 >*/
	goto L99;
/* SOURCE output.for:1180 */
/*<    73 continue >*/
L73:
/* SOURCE output.for:1181 */
/*<        >*/
	feq_gen_io_d__151.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__151);
	do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, flowc, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, areac, (ftnlen)8);
	feq_gen_r_d_1 = static_cast<double>(qput) / bnelem_1.a1[nad - 1];
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&ytemp, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, topc, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&fr, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, latc, (ftnlen)8);
	e_wsfe();
/* SOURCE output.for:1183 */
/*<       goto99 >*/
	goto L99;
/* SOURCE output.for:1184 */
/*<    74 continue >*/
L74:
/* SOURCE output.for:1185 */
/*<        >*/
	feq_gen_io_d__152.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__152);
	do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
	do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, flowc, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, areac, (ftnlen)8);
	feq_gen_r_d_1 = static_cast<double>(qput) / bnelem_1.a1[nad - 1];
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&ytemp, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, topc, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&fr, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, latc, (ftnlen)8);
	e_wsfe();
/* SOURCE output.for:1187 */
/*<    99 continue >*/
L99:
/*        ENDIF */
/* SOURCE output.for:1190 */
/*<       knt=addflg >*/
	knt = addflg;
/* SOURCE output.for:1191 */
/*<       do50nad=fa+1,la >*/
	feq_gen_i_d_2 = la;
	for (nad = fa + 1; nad <= feq_gen_i_d_2; ++nad) {
/* SOURCE output.for:1192 */
/*<       if(hltab(nad).eq.0.and.knt.gt.0)then >*/
	    if (bnothr_1.hltab[nad - 1] == 0 && knt > 0) {
/*           SKIP THE ADDED NODES */
/* SOURCE output.for:1194 */
/*<       knt=knt-1 >*/
		--knt;
/* SOURCE output.for:1195 */
/*<       else >*/
	    } else {
/*           OUTPUT THE NODE. RESET THE KNT AGAIN */
/* SOURCE output.for:1197 */
/*<       knt=addflg >*/
		knt = addflg;
/* SOURCE output.for:1198 */
/*<       fn=fn+1 >*/
		++fn;
/* SOURCE output.for:1199 */
/*<       fr=froude(nsec(nad),y1(nad),q1(nad),a1(nad),t1(nad),grav) >*/
		fr = froude_(&bnothr_1.nsec[nad - 1], &bnelem_1.y1[nad - 1], &
			bnelem_1.q1[nad - 1], &bnelem_1.a1[nad - 1], &
			bnelem_1.t1[nad - 1], grav);
/* SOURCE output.for:1201 */
/*<       z=y1(nad)+zvec(nad)+dz_for_output >*/
		feq_gen_z_d_ = static_cast<double>(static_cast<double>(bnelem_1.y1[nad - 1]) + bnelem_1.zvec[nad - 1]) + *
			feq_gen_dz_for_output_d_;
/* SOURCE output.for:1202 */
/*<       st=xvec(nad)/sfac >*/
		st = static_cast<double>(bnelem_1.xvec[nad - 1]) / *sfac;
/* SOURCE output.for:1203 */
/*<       temp=qpvec(nad) >*/
		temp = bnothr_1.qpvec[nad - 1];
/* SOURCE output.for:1204 */
/*<       qput=q1(nad) >*/
		qput = bnelem_1.q1[nad - 1];
/* SOURCE output.for:1205 */
/*<       if(abs(qput).le.qchop)then >*/
		if (dabs(qput) <= *qchop) {
/* SOURCE output.for:1206 */
/*<       qput=0.0 >*/
		    qput = (float)0.;
/* SOURCE output.for:1207 */
/*<       endif >*/
		}
/*            IF(NODEID.EQ.'NO') THEN */
/*              WRITE(STDOUT,2030) FN, ST, QPUT, A1(NAD), QPUT/A1(NAD), */
/*     A                  Y1(NAD), Z, T1(NAD), FR, TEMP */
/*            ELSE */
/* SOURCE output.for:1212 */
/*<       flowc=put8(qput) >*/
		put8_(feq_gen_ch_d_1, (ftnlen)8, &qput);
		s_copy(flowc, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE output.for:1213 */
/*<       areac=put8(a1(nad)) >*/
		put8_(feq_gen_ch_d_1, (ftnlen)8, &bnelem_1.a1[nad - 1]);
		s_copy(areac, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE output.for:1214 */
/*<       topc=put8(t1(nad)) >*/
		put8_(feq_gen_ch_d_1, (ftnlen)8, &bnelem_1.t1[nad - 1]);
		s_copy(topc, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE output.for:1215 */
/*<       latc=put8(temp) >*/
		put8_(feq_gen_ch_d_1, (ftnlen)8, &temp);
		s_copy(latc, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE output.for:1216 */
/*<       ytemp=y1(nad)+sdvec(nad) >*/
		ytemp = static_cast<double>(bnelem_1.y1[nad - 1]) + bnelem_1.sdvec[nad - 1];
/* SOURCE output.for:1217 */
/*<       goto(160,161,162,163,164,170,171,172,173,174),ftid >*/
		switch (bnelem_1.ftid) {
		    case 1:  goto L160;
		    case 2:  goto L161;
		    case 3:  goto L162;
		    case 4:  goto L163;
		    case 5:  goto L164;
		    case 6:  goto L170;
		    case 7:  goto L171;
		    case 8:  goto L172;
		    case 9:  goto L173;
		    case 10:  goto L174;
		}
/* SOURCE output.for:1219 */
/*<   160 continue >*/
L160:
/* SOURCE output.for:1220 */
/*<        >*/
		feq_gen_io_d__154.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__154);
		do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, flowc, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, areac, (ftnlen)8);
		feq_gen_r_d_1 = static_cast<double>(qput) / bnelem_1.a1[nad - 1];
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&ytemp, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, topc, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, (char *)&fr, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, latc, (ftnlen)8);
		e_wsfe();
/* SOURCE output.for:1222 */
/*<       goto199 >*/
		goto L199;
/* SOURCE output.for:1223 */
/*<   161 continue >*/
L161:
/* SOURCE output.for:1224 */
/*<        >*/
		feq_gen_io_d__155.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__155);
		do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, flowc, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, areac, (ftnlen)8);
		feq_gen_r_d_1 = static_cast<double>(qput) / bnelem_1.a1[nad - 1];
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&ytemp, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, topc, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, (char *)&fr, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, latc, (ftnlen)8);
		e_wsfe();
/* SOURCE output.for:1226 */
/*<       goto199 >*/
		goto L199;
/* SOURCE output.for:1227 */
/*<   162 continue >*/
L162:
/* SOURCE output.for:1228 */
/*<        >*/
		feq_gen_io_d__156.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__156);
		do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, flowc, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, areac, (ftnlen)8);
		feq_gen_r_d_1 = static_cast<double>(qput) / bnelem_1.a1[nad - 1];
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&ytemp, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, topc, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, (char *)&fr, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, latc, (ftnlen)8);
		e_wsfe();
/* SOURCE output.for:1230 */
/*<       goto199 >*/
		goto L199;
/* SOURCE output.for:1231 */
/*<   163 continue >*/
L163:
/* SOURCE output.for:1232 */
/*<        >*/
		feq_gen_io_d__157.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__157);
		do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, flowc, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, areac, (ftnlen)8);
		feq_gen_r_d_1 = static_cast<double>(qput) / bnelem_1.a1[nad - 1];
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&ytemp, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, topc, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, (char *)&fr, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, latc, (ftnlen)8);
		e_wsfe();
/* SOURCE output.for:1234 */
/*<       goto199 >*/
		goto L199;
/* SOURCE output.for:1235 */
/*<   164 continue >*/
L164:
/* SOURCE output.for:1236 */
/*<        >*/
		feq_gen_io_d__158.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__158);
		do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, flowc, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, areac, (ftnlen)8);
		feq_gen_r_d_1 = static_cast<double>(qput) / bnelem_1.a1[nad - 1];
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&ytemp, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, topc, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, (char *)&fr, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, latc, (ftnlen)8);
		e_wsfe();
/* SOURCE output.for:1238 */
/*<       goto199 >*/
		goto L199;
/* SOURCE output.for:1239 */
/*<   170 continue >*/
L170:
/* SOURCE output.for:1240 */
/*<        >*/
		feq_gen_io_d__159.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__159);
		do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, flowc, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, areac, (ftnlen)8);
		feq_gen_r_d_1 = static_cast<double>(qput) / bnelem_1.a1[nad - 1];
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&ytemp, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, topc, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, (char *)&fr, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, latc, (ftnlen)8);
		e_wsfe();
/* SOURCE output.for:1242 */
/*<       goto199 >*/
		goto L199;
/* SOURCE output.for:1243 */
/*<   171 continue >*/
L171:
/* SOURCE output.for:1244 */
/*<        >*/
		feq_gen_io_d__160.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__160);
		do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, flowc, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, areac, (ftnlen)8);
		feq_gen_r_d_1 = static_cast<double>(qput) / bnelem_1.a1[nad - 1];
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&ytemp, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, topc, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, (char *)&fr, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, latc, (ftnlen)8);
		e_wsfe();
/* SOURCE output.for:1246 */
/*<       goto199 >*/
		goto L199;
/* SOURCE output.for:1247 */
/*<   172 continue >*/
L172:
/* SOURCE output.for:1248 */
/*<        >*/
		feq_gen_io_d__161.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__161);
		do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, flowc, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, areac, (ftnlen)8);
		feq_gen_r_d_1 = static_cast<double>(qput) / bnelem_1.a1[nad - 1];
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&ytemp, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, topc, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, (char *)&fr, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, latc, (ftnlen)8);
		e_wsfe();
/* SOURCE output.for:1250 */
/*<       goto199 >*/
		goto L199;
/* SOURCE output.for:1251 */
/*<   173 continue >*/
L173:
/* SOURCE output.for:1252 */
/*<        >*/
		feq_gen_io_d__162.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__162);
		do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, flowc, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, areac, (ftnlen)8);
		feq_gen_r_d_1 = static_cast<double>(qput) / bnelem_1.a1[nad - 1];
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&ytemp, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, topc, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, (char *)&fr, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, latc, (ftnlen)8);
		e_wsfe();
/* SOURCE output.for:1254 */
/*<       goto199 >*/
		goto L199;
/* SOURCE output.for:1255 */
/*<   174 continue >*/
L174:
/* SOURCE output.for:1256 */
/*<        >*/
		feq_gen_io_d__163.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__163);
		do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)&st, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, flowc, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, areac, (ftnlen)8);
		feq_gen_r_d_1 = static_cast<double>(qput) / bnelem_1.a1[nad - 1];
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&ytemp, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, topc, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, (char *)&fr, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, latc, (ftnlen)8);
		e_wsfe();
/* SOURCE output.for:1258 */
/*<   199 continue >*/
L199:
/*            ENDIF */
/* SOURCE output.for:1260 */
/*<       endif >*/
		;
	    }
/* SOURCE output.for:1261 */
/*<    50 continue >*/
/* L50: */
	}
/* SOURCE output.for:1262 */
/*<       brasum=bpond(nb) >*/
	brasum = bnpond_1.bpond[nb - 1];
/* SOURCE output.for:1263 */
/*<       if(brasum.gt.0.0)then >*/
	if (brasum > (float)0.) {
/* SOURCE output.for:1264 */
/*<       if(grav.gt.20.0)then >*/
	    if (*grav > (float)20.) {
/* SOURCE output.for:1265 */
/*<       write(stdout,2070)brasum,' ft^3 ',brasum/vunit,' Ac-ft' >*/
		feq_gen_io_d__165.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__165);
		do_fio(&feq_gen_c_d_1, (char *)&brasum, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, const_cast<char*>(" ft^3 "), (ftnlen)6);
		feq_gen_r_d_1 = static_cast<double>(brasum) / *vunit;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, const_cast<char*>(" Ac-ft"), (ftnlen)6);
		e_wsfe();
/* SOURCE output.for:1266 */
/*<       else >*/
	    } else {
/* SOURCE output.for:1267 */
/*<       write(stdout,2070)brasum,' m^3  ',brasum/vunit,' K m^3' >*/
		feq_gen_io_d__166.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__166);
		do_fio(&feq_gen_c_d_1, (char *)&brasum, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, const_cast<char*>(" m^3  "), (ftnlen)6);
		feq_gen_r_d_1 = static_cast<double>(brasum) / *vunit;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, const_cast<char*>(" K m^3"), (ftnlen)6);
		e_wsfe();
/* SOURCE output.for:1268 */
/*<       endif >*/
	    }
/* SOURCE output.for:1269 */
/*<       endif >*/
	}
/* SOURCE output.for:1271 */
/*<       sum=sum+brasum >*/
	sum += brasum;
/* SOURCE output.for:1272 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE output.for:1273 */
/*<       if(sum.gt.0.0)then >*/
    if (sum > (float)0.) {
/* SOURCE output.for:1274 */
/*<       if(grav.gt.20.0)then >*/
	if (*grav > (float)20.) {
/* SOURCE output.for:1275 */
/*<       write(stdout,2080)sum,' ft^3 ',sum/vunit,' Ac-ft' >*/
	    feq_gen_io_d__167.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__167);
	    do_fio(&feq_gen_c_d_1, (char *)&sum, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, const_cast<char*>(" ft^3 "), (ftnlen)6);
	    feq_gen_r_d_1 = static_cast<double>(sum) / *vunit;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, const_cast<char*>(" Ac-ft"), (ftnlen)6);
	    e_wsfe();
/* SOURCE output.for:1276 */
/*<       else >*/
	} else {
/* SOURCE output.for:1277 */
/*<       write(stdout,2080)sum,' m^3  ',sum/vunit,' K m^3' >*/
	    feq_gen_io_d__168.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__168);
	    do_fio(&feq_gen_c_d_1, (char *)&sum, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, const_cast<char*>(" m^3  "), (ftnlen)6);
	    feq_gen_r_d_1 = static_cast<double>(sum) / *vunit;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, const_cast<char*>(" K m^3"), (ftnlen)6);
	    e_wsfe();
/* SOURCE output.for:1278 */
/*<       endif >*/
	}
/* SOURCE output.for:1279 */
/*<       endif >*/
    }
/*     WRITE OUT RESULTS FOR EXTERIOR NODES */
/* SOURCE output.for:1283 */
/*<       write(stdout,2040) >*/
    feq_gen_io_d__169.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__169);
    e_wsfe();
/* SOURCE output.for:1284 */
/*<       write(stdout,2052) >*/
    feq_gen_io_d__170.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__170);
    e_wsfe();
/* SOURCE output.for:1286 */
/*<       do200ii=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (ii = 1; ii <= feq_gen_i_d_1; ++ii) {
/* SOURCE output.for:1287 */
/*<       nad=usnsrt(ii) >*/
	nad = inen_1.usnsrt[ii - 1];
/* SOURCE output.for:1288 */
/*<       elev=ze(nad)+ye1(nad)+dz_for_output >*/
	elev = static_cast<double>(static_cast<double>(enelem_1.ze[nad - 1]) + enelem_1.ye1[nad - 1]) + *
		feq_gen_dz_for_output_d_;
/* SOURCE output.for:1289 */
/*<       qput=qe1(nad) >*/
	qput = enelem_1.qe1[nad - 1];
/* SOURCE output.for:1290 */
/*<       if(abs(qput).le.qchop)then >*/
	if (dabs(qput) <= *qchop) {
/* SOURCE output.for:1291 */
/*<       qput=0.0 >*/
	    qput = (float)0.;
/* SOURCE output.for:1292 */
/*<       endif >*/
	}
/* SOURCE output.for:1293 */
/*<       if(exnodt(3,nad).eq.-1)then >*/
	if (exnodt[nad * 9 + 3] == -1) {
/* SOURCE output.for:1294 */
/*<        >*/
	    feq_gen_io_d__173.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__173);
	    do_fio(&feq_gen_c_d_1, inenc_1.inenus + (nad - 1) * 5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, enothc_1.enodid + (nad - 1 << 4), (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&qput, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&enelem_1.ye1[nad - 1], (ftnlen)sizeof(real)
		    );
	    do_fio(&feq_gen_c_d_1, (char *)&elev, (ftnlen)sizeof(real));
	    feq_gen_r_d_3 = (feq_gen_r_d_2 = enelem_1.ae1[nad - 1], dabs(feq_gen_r_d_2));
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_3, (ftnlen)sizeof(real));
	    feq_gen_r_d_4 = (feq_gen_r_d_1 = enelem_1.ae1[nad - 1], dabs(feq_gen_r_d_1)) / *vunit;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_4, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE output.for:1298 */
/*<       else >*/
	} else {
/* SOURCE output.for:1299 */
/*<       if(exnodt(3,nad).gt.0)then >*/
	    if (exnodt[nad * 9 + 3] > 0) {
/* SOURCE output.for:1300 */
/*<       ytemp=ye1(nad)+sdvec(exnodt(2,nad)) >*/
		ytemp = static_cast<double>(enelem_1.ye1[nad - 1]) + bnelem_1.sdvec[exnodt[nad * 9 
			+ 2] - 1];
/* SOURCE output.for:1301 */
/*<       else >*/
	    } else {
/* SOURCE output.for:1302 */
/*<       ytemp=ye1(nad) >*/
		ytemp = enelem_1.ye1[nad - 1];
/* SOURCE output.for:1303 */
/*<       endif >*/
	    }
/*          IF(QPUT.NE.0.0) THEN */
/* SOURCE output.for:1305 */
/*<       write(stdout,2062)inenus(nad),enodid(nad),qput,ytemp,elev >*/
	    feq_gen_io_d__174.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__174);
	    do_fio(&feq_gen_c_d_1, inenc_1.inenus + (nad - 1) * 5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, enothc_1.enodid + (nad - 1 << 4), (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&qput, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&ytemp, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&elev, (ftnlen)sizeof(real));
	    e_wsfe();
/*          ENDIF */
/* SOURCE output.for:1308 */
/*<       endif >*/
	}
/* SOURCE output.for:1309 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE output.for:1310 */
/*<       return >*/
    return 0;
/* SOURCE output.for:1311 */
/*<       end >*/
} /* resout_ */




/* SOURCE output.for:1315 */
/*<       subroutinetdtchk(stdout,exnodt,nex,emc) >*/
/* Subroutine */ int tdtchk_(integer *stdout, integer *feq_storage_exnodt, integer *nex, 
	integer *feq_storage_emc)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *WRN:49* Two-D table overflows have occu\
rred:\002,/,\002 Table            Type  Maximum  Overflow  Maximum  Overflo\
w\002,/,\002 Id                     head in  amount    flow in  amount\002,/,\
\002                        table              table           \002,/,\002 -\
--------------- ----  -------  --------  -------  -------\002)";
    static char fmt_52[] = "(1x,a16,i5,f10.2,f10.2)";
    static char fmt_54[] = "(1x,a16,i5,20x,f10.2,f10.2)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen);

    /* Local variables */
    real feq_gen_h_d_;
    integer feq_gen_i_d_;
    real w;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real hd, wc;
    integer it;
    real hu;
    integer adr, mdn, dnn, qnn, unn;
    real qmx;
    integer code;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ioff, tabn;
    extern /* Subroutine */ int get14_(integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, integer *, real *, real *, 
	    integer *);
    real qneg, hmax;
    integer ztab, ipnt, hout, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real qpos;
    extern /* Subroutine */ int get613_(integer *, integer *, integer *, 
	    integer *, integer *, real *, real *, integer *, real *, integer *
	    );
    integer duadr, udadr, npair, sysgn;
    real hdatum;
    integer ientry, tabtyp;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__200 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__201 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__202 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__203 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__204 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__205 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__206 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__207 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__210 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__211 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__212 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__213 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__220 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__221 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__222 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__223 = { 0, 0, 0, fmt_52, 0 };


/*     + + + PURPOSE + + + */
/*     Check two-D tables to see if the maximum results for elevation */
/*     or flow exceeded the limit of the table. */
/* SOURCE output.for:1322 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE output.for:1324 */
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
/* SOURCE output.for:1327 */
/*<       integerstdout,nex >*/
/* SOURCE output.for:1328 */
/*<       integeremc(mremc),exnodt(9,nex) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
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
/* INCLUDE output.for:1349 */
/* ********************************************************************** */
/* SOURCE bnrslt.cmn:2 */
/*<       common/bnrslt/tqmax,tqmin,tzmax,qmax,qmin,zmax,vmax >*/
/* SOURCE bnrslt.cmn:5 */
/*<       realqmax(mnbn),qmin(mnbn),zmax(mnbn),vmax(mnbn) >*/
/* SOURCE bnrslt.cmn:7 */
/*<       doubleprecisiontqmax(mnbn),tqmin(mnbn),tzmax(mnbn) >*/
/* ********************************************************************** */
/* INCLUDE output.for:1350 */
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
/* INCLUDE output.for:1351 */
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
/* INCLUDE output.for:1352 */
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
/* SOURCE output.for:1355 */
/*<        >*/
/* SOURCE output.for:1358 */
/*<       realh,hd,hdatum,hmax,hu,qmx,qneg,qpos,w,wc >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE output.for:1361 */
/*<       characterget_tabid*16 >*/
/* SOURCE output.for:1362 */
/*<       externalget14,get613,get_tabid >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE output.for:1365 */
/*<    50  >*/
/* SOURCE output.for:1370 */
/*<    52 format(1x,a16,i5,f10.2,f10.2) >*/
/* SOURCE output.for:1371 */
/*<    54 format(1x,a16,i5,20x,f10.2,f10.2) >*/
/* *********************************************************************** */
/*     Clear the heading flag. */
/* SOURCE output.for:1374 */
/*<       hout=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
    hout = 0;
/*     START SEARCH */
/* SOURCE output.for:1376 */
/*<       ientry=0 >*/
    ientry = 0;
/* SOURCE output.for:1377 */
/*<       type=6 >*/
    feq_gen_type_d_ = 6;
/* SOURCE output.for:1378 */
/*<   100 continue >*/
L100:
/* SOURCE output.for:1379 */
/*<       ientry=ientry+1 >*/
    ++ientry;
/* SOURCE output.for:1380 */
/*<       ipnt=add(ientry) >*/
    ipnt = matcom_1.add[ientry - 1];
/* SOURCE output.for:1381 */
/*<       code=emc(ipnt) >*/
    code = emc[ipnt];
/* SOURCE output.for:1382 */
/*<       if(code.eq.5)then >*/
    if (code == 5) {
/*         CODE = 5.  Check for type. */
/* SOURCE output.for:1384 */
/*<       if(type.eq.emc(ipnt+1))then >*/
	if (feq_gen_type_d_ == emc[ipnt + 1]) {
/*           Found type 6.  Get the node numbers and the system sign. */
/* SOURCE output.for:1386 */
/*<       unn=emc(ipnt+2) >*/
	    unn = emc[ipnt + 2];
/* SOURCE output.for:1387 */
/*<       dnn=emc(ipnt+3) >*/
	    dnn = emc[ipnt + 3];
/* SOURCE output.for:1388 */
/*<       qnn=emc(ipnt+4) >*/
	    qnn = emc[ipnt + 4];
/* SOURCE output.for:1389 */
/*<       sysgn=emc(ipnt+5) >*/
	    sysgn = emc[ipnt + 5];
/*           Get the flows at the flow node. */
/* SOURCE output.for:1391 */
/*<       it=exnodt(3,qnn) >*/
	    it = exnodt[qnn * 9 + 3];
/* SOURCE output.for:1392 */
/*<       if(it.le.0)then >*/
	    if (it <= 0) {
/*             Node not on a branch. */
/* SOURCE output.for:1394 */
/*<       qpos=fnqmax(qnn) >*/
		qpos = enrslt_1.fnqmax[qnn - 1];
/* SOURCE output.for:1395 */
/*<       qneg=fnqmin(qnn) >*/
		qneg = enrslt_1.fnqmin[qnn - 1];
/* SOURCE output.for:1396 */
/*<       else >*/
	    } else {
/* SOURCE output.for:1397 */
/*<       it=exnodt(2,qnn) >*/
		it = exnodt[qnn * 9 + 2];
/* SOURCE output.for:1398 */
/*<       qpos=qmax(it) >*/
		qpos = bnrslt_1.qmax[it - 1];
/* SOURCE output.for:1399 */
/*<       qneg=qmin(it) >*/
		qneg = bnrslt_1.qmin[it - 1];
/* SOURCE output.for:1400 */
/*<       endif >*/
	    }
/* SOURCE output.for:1401 */
/*<       if(qneg.gt.0.0)then >*/
	    if (qneg > (float)0.) {
/*             No need to check.  Only check minimum flow when it is */
/*             negative. */
/* SOURCE output.for:1404 */
/*<       qneg=0.0 >*/
		qneg = (float)0.;
/* SOURCE output.for:1405 */
/*<       endif >*/
	    }
/*           If the number of flow paths is negative */
/*           then  tables of type 14 are involved. */
/* SOURCE output.for:1409 */
/*<       npair=emc(ipnt+6) >*/
	    npair = emc[ipnt + 6];
/* SOURCE output.for:1410 */
/*<       if(npair.lt.0)then >*/
	    if (npair < 0) {
/*             Tables are type 14.  At most two tables appear. */
/* SOURCE output.for:1412 */
/*<       udadr=emc(ipnt+7) >*/
		udadr = emc[ipnt + 7];
/* SOURCE output.for:1413 */
/*<       duadr=emc(ipnt+8) >*/
		duadr = emc[ipnt + 8];
/* SOURCE output.for:1414 */
/*<       ztab=emc(ipnt+10) >*/
		ztab = emc[ipnt + 10];
/* SOURCE output.for:1415 */
/*<       itmp=emc(ipnt+11) >*/
		ftablea_1.itmp = emc[ipnt + 11];
/* SOURCE output.for:1416 */
/*<       hdatum=rtmp >*/
		hdatum = *rtmp;
/*             Flows of zero are not checked. */
/* SOURCE output.for:1418 */
/*<       if(qpos*sysgn.gt.0)then >*/
		if (static_cast<double>(qpos) * sysgn > (float)0.) {
/*               Maximum flow was from U to D. */
/* SOURCE output.for:1420 */
/*<       callget14(nex,exnodt,udadr,dnn,ztab,hdatum,h,tabn,qmx,hmax,tabtyp) >*/
		    get14_(nex, &exnodt[10], &udadr, &dnn, &ztab, &hdatum, &
			    feq_gen_h_d_, &tabn, &qmx, &hmax, &tabtyp);
/* SOURCE output.for:1423 */
/*<       elseif(qpos*sysgn.lt.0)then >*/
		} else if (static_cast<double>(qpos) * sysgn < (float)0.) {
/*               Maximum flow was from D to U. */
/* SOURCE output.for:1425 */
/*<       callget14(nex,exnodt,duadr,unn,ztab,hdatum,h,tabn,qmx,hmax,tabtyp) >*/
		    get14_(nex, &exnodt[10], &duadr, &unn, &ztab, &hdatum, &
			    feq_gen_h_d_, &tabn, &qmx, &hmax, &tabtyp);
/* SOURCE output.for:1428 */
/*<       endif >*/
		}
/* SOURCE output.for:1429 */
/*<       if(qpos.gt.0.0)then >*/
		if (qpos > (float)0.) {
/* SOURCE output.for:1430 */
/*<       if(h.gt.hmax)then >*/
		    if (feq_gen_h_d_ > hmax) {
/* SOURCE output.for:1431 */
/*<       if(hout.eq.0)then >*/
			if (hout == 0) {
/* SOURCE output.for:1432 */
/*<       write(stdout,50) >*/
			    feq_gen_io_d__200.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__200);
			    e_wsfe();
/* SOURCE output.for:1433 */
/*<       hout=1 >*/
			    hout = 1;
/* SOURCE output.for:1434 */
/*<       endif >*/
			}
/*                 Final result  is above maximum  head. */
/* SOURCE output.for:1436 */
/*<       write(stdout,52)get_tabid(tabn),tabtyp,hmax,h-hmax >*/
			feq_gen_io_d__201.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__201);
			feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tabn);
			s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
			do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
			do_fio(&feq_gen_c_d_1, (char *)&tabtyp, (ftnlen)sizeof(integer)
				);
			do_fio(&feq_gen_c_d_1, (char *)&hmax, (ftnlen)sizeof(real));
			feq_gen_r_d_1 = static_cast<double>(feq_gen_h_d_) - hmax;
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
			e_wsfe();
/* SOURCE output.for:1437 */
/*<       endif >*/
		    }
/* SOURCE output.for:1438 */
/*<       if(qpos.gt.qmx)then >*/
		    if (qpos > qmx) {
/* SOURCE output.for:1439 */
/*<       if(hout.eq.0)then >*/
			if (hout == 0) {
/* SOURCE output.for:1440 */
/*<       write(stdout,50) >*/
			    feq_gen_io_d__202.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__202);
			    e_wsfe();
/* SOURCE output.for:1441 */
/*<       hout=1 >*/
			    hout = 1;
/* SOURCE output.for:1442 */
/*<       endif >*/
			}
/*                 Final flow result is above the table */
/* SOURCE output.for:1444 */
/*<       write(stdout,54)get_tabid(tabn),tabtyp,qmx,qpos-qmx >*/
			feq_gen_io_d__203.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__203);
			feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tabn);
			s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
			do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
			do_fio(&feq_gen_c_d_1, (char *)&tabtyp, (ftnlen)sizeof(integer)
				);
			do_fio(&feq_gen_c_d_1, (char *)&qmx, (ftnlen)sizeof(real));
			feq_gen_r_d_1 = static_cast<double>(qpos) - qmx;
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
			e_wsfe();
/* SOURCE output.for:1446 */
/*<       endif >*/
		    }
/* SOURCE output.for:1447 */
/*<       endif >*/
		}
/* SOURCE output.for:1449 */
/*<       if(qneg*sysgn.gt.0)then >*/
		if (static_cast<double>(qneg) * sysgn > (float)0.) {
/*               Minimum flow was from U to D. */
/* SOURCE output.for:1451 */
/*<       callget14(nex,exnodt,udadr,dnn,ztab,hdatum,h,tabn,qmx,hmax,tabtyp) >*/
		    get14_(nex, &exnodt[10], &udadr, &dnn, &ztab, &hdatum, &
			    feq_gen_h_d_, &tabn, &qmx, &hmax, &tabtyp);
/* SOURCE output.for:1454 */
/*<       elseif(qneg*sysgn.lt.0)then >*/
		} else if (static_cast<double>(qneg) * sysgn < (float)0.) {
/*               Minimum flow was from D to U. */
/* SOURCE output.for:1456 */
/*<       callget14(nex,exnodt,duadr,unn,ztab,hdatum,h,tabn,qmx,hmax,tabtyp) >*/
		    get14_(nex, &exnodt[10], &duadr, &unn, &ztab, &hdatum, &
			    feq_gen_h_d_, &tabn, &qmx, &hmax, &tabtyp);
/* SOURCE output.for:1459 */
/*<       endif >*/
		}
/* SOURCE output.for:1460 */
/*<       if(-qneg.gt.0.0)then >*/
		if (-qneg > (float)0.) {
/* SOURCE output.for:1461 */
/*<       if(h.gt.hmax)then >*/
		    if (feq_gen_h_d_ > hmax) {
/* SOURCE output.for:1462 */
/*<       if(hout.eq.0)then >*/
			if (hout == 0) {
/* SOURCE output.for:1463 */
/*<       write(stdout,50) >*/
			    feq_gen_io_d__204.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__204);
			    e_wsfe();
/* SOURCE output.for:1464 */
/*<       hout=1 >*/
			    hout = 1;
/* SOURCE output.for:1465 */
/*<       endif >*/
			}
/*                 Final result  is above maximum  head. */
/* SOURCE output.for:1467 */
/*<       write(stdout,52)get_tabid(tabn),tabtyp,hmax,h-hmax >*/
			feq_gen_io_d__205.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__205);
			feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tabn);
			s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
			do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
			do_fio(&feq_gen_c_d_1, (char *)&tabtyp, (ftnlen)sizeof(integer)
				);
			do_fio(&feq_gen_c_d_1, (char *)&hmax, (ftnlen)sizeof(real));
			feq_gen_r_d_1 = static_cast<double>(feq_gen_h_d_) - hmax;
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
			e_wsfe();
/* SOURCE output.for:1468 */
/*<       endif >*/
		    }
/* SOURCE output.for:1469 */
/*<       if(-qneg.gt.qmx)then >*/
		    if (-qneg > qmx) {
/* SOURCE output.for:1470 */
/*<       if(hout.eq.0)then >*/
			if (hout == 0) {
/* SOURCE output.for:1471 */
/*<       write(stdout,50) >*/
			    feq_gen_io_d__206.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__206);
			    e_wsfe();
/* SOURCE output.for:1472 */
/*<       hout=1 >*/
			    hout = 1;
/* SOURCE output.for:1473 */
/*<       endif >*/
			}
/*                 Final flow result is above the table */
/* SOURCE output.for:1475 */
/*<       write(stdout,54)get_tabid(tabn),tabtyp,qmx,-qneg-qmx >*/
			feq_gen_io_d__207.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__207);
			feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tabn);
			s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
			do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
			do_fio(&feq_gen_c_d_1, (char *)&tabtyp, (ftnlen)sizeof(integer)
				);
			do_fio(&feq_gen_c_d_1, (char *)&qmx, (ftnlen)sizeof(real));
			feq_gen_r_d_1 = static_cast<double>(-qneg) - qmx;
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
			e_wsfe();
/* SOURCE output.for:1477 */
/*<       endif >*/
		    }
/* SOURCE output.for:1478 */
/*<       endif >*/
		}
/* SOURCE output.for:1480 */
/*<       else >*/
	    } else {
/*             Tables of type 6 or 13 may appear and there may be */
/*             multiple pairs. */
/* SOURCE output.for:1483 */
/*<       ioff=0 >*/
		ioff = 0;
/* SOURCE output.for:1484 */
/*<       do200i=1,npair >*/
		feq_gen_i_d_1 = npair;
		for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE output.for:1485 */
/*<       udadr=emc(ipnt+ioff+7) >*/
		    udadr = emc[ipnt + ioff + 7];
/* SOURCE output.for:1486 */
/*<       duadr=emc(ipnt+ioff+8) >*/
		    duadr = emc[ipnt + ioff + 8];
/* SOURCE output.for:1487 */
/*<       ztab=emc(ipnt+ioff+10) >*/
		    ztab = emc[ipnt + ioff + 10];
/* SOURCE output.for:1489 */
/*<       itmp=emc(ipnt+ioff+11) >*/
		    ftablea_1.itmp = emc[ipnt + ioff + 11];
/* SOURCE output.for:1490 */
/*<       hdatum=rtmp >*/
		    hdatum = *rtmp;
/* SOURCE output.for:1492 */
/*<       if(qpos*sysgn.gt.0)then >*/
		    if (static_cast<double>(qpos) * sysgn > (float)0.) {
/*                 Maximum flow was from U to D. */
/* SOURCE output.for:1494 */
/*<       callget613(nex,exnodt,udadr,unn,ztab,hdatum,h,tabn,hmax,tabtyp) >*/
			get613_(nex, &exnodt[10], &udadr, &unn, &ztab, &
				hdatum, &feq_gen_h_d_, &tabn, &hmax, &tabtyp);
/* SOURCE output.for:1497 */
/*<       elseif(qpos*sysgn.lt.0)then >*/
		    } else if (static_cast<double>(qpos) * sysgn < (float)0.) {
/*                 Maximum flow was from D to U. */
/* SOURCE output.for:1499 */
/*<       callget613(nex,exnodt,duadr,dnn,ztab,hdatum,h,tabn,hmax,tabtyp) >*/
			get613_(nex, &exnodt[10], &duadr, &dnn, &ztab, &
				hdatum, &feq_gen_h_d_, &tabn, &hmax, &tabtyp);
/* SOURCE output.for:1502 */
/*<       endif >*/
		    }
/* SOURCE output.for:1503 */
/*<       if(qpos.gt.0.0)then >*/
		    if (qpos > (float)0.) {
/* SOURCE output.for:1504 */
/*<       if(h.gt.hmax)then >*/
			if (feq_gen_h_d_ > hmax) {
/* SOURCE output.for:1505 */
/*<       if(hout.eq.0)then >*/
			    if (hout == 0) {
/* SOURCE output.for:1506 */
/*<       write(stdout,50) >*/
				feq_gen_io_d__210.ciunit = *stdout;
				s_wsfe(&feq_gen_io_d__210);
				e_wsfe();
/* SOURCE output.for:1507 */
/*<       hout=1 >*/
				hout = 1;
/* SOURCE output.for:1508 */
/*<       endif >*/
			    }
/*                   Final result  is above maximum head. */
/* SOURCE output.for:1510 */
/*<       write(stdout,52)get_tabid(tabn),tabtyp,hmax,h-hmax >*/
			    feq_gen_io_d__211.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__211);
			    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tabn);
			    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
			    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
			    do_fio(&feq_gen_c_d_1, (char *)&tabtyp, (ftnlen)sizeof(
				    integer));
			    do_fio(&feq_gen_c_d_1, (char *)&hmax, (ftnlen)sizeof(real))
				    ;
			    feq_gen_r_d_1 = static_cast<double>(feq_gen_h_d_) - hmax;
			    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real))
				    ;
			    e_wsfe();
/* SOURCE output.for:1512 */
/*<       endif >*/
			}
/* SOURCE output.for:1513 */
/*<       endif >*/
		    }
/* SOURCE output.for:1515 */
/*<       if(qneg*sysgn.gt.0)then >*/
		    if (static_cast<double>(qneg) * sysgn > (float)0.) {
/*                 Minimum flow was from U to D. */
/* SOURCE output.for:1517 */
/*<       callget613(nex,exnodt,udadr,unn,ztab,hdatum,h,tabn,hmax,tabtyp) >*/
			get613_(nex, &exnodt[10], &udadr, &unn, &ztab, &
				hdatum, &feq_gen_h_d_, &tabn, &hmax, &tabtyp);
/* SOURCE output.for:1520 */
/*<       elseif(qneg*sysgn.lt.0)then >*/
		    } else if (static_cast<double>(qneg) * sysgn < (float)0.) {
/*                 Minimum flow was from D to U. */
/* SOURCE output.for:1522 */
/*<       callget613(nex,exnodt,duadr,dnn,ztab,hdatum,h,tabn,hmax,tabtyp) >*/
			get613_(nex, &exnodt[10], &duadr, &dnn, &ztab, &
				hdatum, &feq_gen_h_d_, &tabn, &hmax, &tabtyp);
/* SOURCE output.for:1525 */
/*<       endif >*/
		    }
/* SOURCE output.for:1526 */
/*<       if(-qneg.gt.0.0)then >*/
		    if (-qneg > (float)0.) {
/* SOURCE output.for:1527 */
/*<       if(h.gt.hmax)then >*/
			if (feq_gen_h_d_ > hmax) {
/* SOURCE output.for:1528 */
/*<       if(hout.eq.0)then >*/
			    if (hout == 0) {
/* SOURCE output.for:1529 */
/*<       write(stdout,50) >*/
				feq_gen_io_d__212.ciunit = *stdout;
				s_wsfe(&feq_gen_io_d__212);
				e_wsfe();
/* SOURCE output.for:1530 */
/*<       hout=1 >*/
				hout = 1;
/* SOURCE output.for:1531 */
/*<       endif >*/
			    }
/*                   Final result  is above maximum head. */
/* SOURCE output.for:1533 */
/*<       write(stdout,52)get_tabid(tabn),tabtyp,hmax,h-hmax >*/
			    feq_gen_io_d__213.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__213);
			    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tabn);
			    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
			    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
			    do_fio(&feq_gen_c_d_1, (char *)&tabtyp, (ftnlen)sizeof(
				    integer));
			    do_fio(&feq_gen_c_d_1, (char *)&hmax, (ftnlen)sizeof(real))
				    ;
			    feq_gen_r_d_1 = static_cast<double>(feq_gen_h_d_) - hmax;
			    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real))
				    ;
			    e_wsfe();
/* SOURCE output.for:1535 */
/*<       endif >*/
			}
/* SOURCE output.for:1536 */
/*<       endif >*/
		    }
/* SOURCE output.for:1537 */
/*<       ioff=ioff+cd5ty6 >*/
		    ioff += 8;
/* SOURCE output.for:1538 */
/*<   200 continue >*/
/* L200: */
		}
/* SOURCE output.for:1539 */
/*<       endif >*/
	    }
/* SOURCE output.for:1540 */
/*<       endif >*/
	}
/* SOURCE output.for:1541 */
/*<       elseif(code.eq.14)then >*/
    } else if (code == 14) {
/*         Side-weir option.  Dual tables of type 6 or 13. */
/* SOURCE output.for:1543 */
/*<       unn=emc(ipnt+1) >*/
	unn = emc[ipnt + 1];
/* SOURCE output.for:1544 */
/*<       dnn=emc(ipnt+2) >*/
	dnn = emc[ipnt + 2];
/*         THE MIDDLE NODE(MDN) IS ALWAYS THE FLOW NODE FOR A SIDE WEIR */
/* SOURCE output.for:1546 */
/*<       mdn=emc(ipnt+3) >*/
	mdn = emc[ipnt + 3];
/*         Set the system sign. If the sign of the flow node is < 0 then */
/*         a flow > 0 indicates that flow was into the flow path having */
/*         the flow node.  This means that SYSGN is of opposite sign to */
/*         the sign of the flow node. */
/* SOURCE output.for:1551 */
/*<       sysgn=-exnodt(1,mdn) >*/
	sysgn = -exnodt[mdn * 9 + 1];
/*         Get the addresses of the two 2-D tables. */
/* SOURCE output.for:1554 */
/*<       udadr=emc(ipnt+4) >*/
	udadr = emc[ipnt + 4];
/* SOURCE output.for:1555 */
/*<       duadr=emc(ipnt+5) >*/
	duadr = emc[ipnt + 5];
/*         Set the weight factor for computing head. */
/* SOURCE output.for:1558 */
/*<       itmp=emc(ipnt+8) >*/
	ftablea_1.itmp = emc[ipnt + 8];
/* SOURCE output.for:1559 */
/*<       w=rtmp >*/
	w = *rtmp;
/* SOURCE output.for:1560 */
/*<       wc=1.0-w >*/
	wc = static_cast<double>((float)1.) - w;
/* SOURCE output.for:1561 */
/*<       itmp=emc(ipnt+9) >*/
	ftablea_1.itmp = emc[ipnt + 9];
/* SOURCE output.for:1562 */
/*<       hdatum=rtmp >*/
	hdatum = *rtmp;
/*         Get the flows at the flow node. */
/* SOURCE output.for:1564 */
/*<       it=exnodt(3,mdn) >*/
	it = exnodt[mdn * 9 + 3];
/* SOURCE output.for:1565 */
/*<       if(it.le.0)then >*/
	if (it <= 0) {
/*           Node not on a branch. */
/* SOURCE output.for:1567 */
/*<       qpos=fnqmax(mdn) >*/
	    qpos = enrslt_1.fnqmax[mdn - 1];
/* SOURCE output.for:1568 */
/*<       qneg=fnqmin(mdn) >*/
	    qneg = enrslt_1.fnqmin[mdn - 1];
/* SOURCE output.for:1569 */
/*<       else >*/
	} else {
/* SOURCE output.for:1570 */
/*<       qpos=qmax(it) >*/
	    qpos = bnrslt_1.qmax[it - 1];
/* SOURCE output.for:1571 */
/*<       qneg=qmin(it) >*/
	    qneg = bnrslt_1.qmin[it - 1];
/* SOURCE output.for:1572 */
/*<       endif >*/
	}
/* SOURCE output.for:1573 */
/*<       if(qneg.gt.0.0)then >*/
	if (qneg > (float)0.) {
/*           No need to check.  Only check minimum flow when it is */
/*           negative. */
/* SOURCE output.for:1576 */
/*<       qneg=0.0 >*/
	    qneg = (float)0.;
/* SOURCE output.for:1577 */
/*<       endif >*/
	}
/* SOURCE output.for:1578 */
/*<       if(qpos*sysgn.gt.0)then >*/
	if (static_cast<double>(qpos) * sysgn > (float)0.) {
/*           Maximum flow was from U to D. */
/* SOURCE output.for:1580 */
/*<       adr=udadr >*/
	    adr = udadr;
/* SOURCE output.for:1581 */
/*<       tabn=itab(adr+1) >*/
	    tabn = itab[adr + 1];
/* SOURCE output.for:1582 */
/*<       tabtyp=itab(adr+2) >*/
	    tabtyp = itab[adr + 2];
/* SOURCE output.for:1583 */
/*<       hmax=ftab(adr+9) >*/
	    hmax = ftab[adr + 9];
/* SOURCE output.for:1584 */
/*<       it=exnodt(3,unn) >*/
	    it = exnodt[unn * 9 + 3];
/* SOURCE output.for:1585 */
/*<       if(it.le.0)then >*/
	    if (it <= 0) {
/* SOURCE output.for:1586 */
/*<       hu=fnzmax(unn) >*/
		hu = enrslt_1.fnzmax[unn - 1];
/* SOURCE output.for:1587 */
/*<       else >*/
	    } else {
/* SOURCE output.for:1588 */
/*<       it=exnodt(2,unn) >*/
		it = exnodt[unn * 9 + 2];
/* SOURCE output.for:1589 */
/*<       hu=zmax(it) >*/
		hu = bnrslt_1.zmax[it - 1];
/* SOURCE output.for:1590 */
/*<       endif >*/
	    }
/* SOURCE output.for:1591 */
/*<       it=exnodt(3,dnn) >*/
	    it = exnodt[dnn * 9 + 3];
/* SOURCE output.for:1592 */
/*<       if(it.le.0)then >*/
	    if (it <= 0) {
/* SOURCE output.for:1593 */
/*<       hd=fnzmax(dnn) >*/
		hd = enrslt_1.fnzmax[dnn - 1];
/* SOURCE output.for:1594 */
/*<       else >*/
	    } else {
/* SOURCE output.for:1595 */
/*<       it=exnodt(2,dnn) >*/
		it = exnodt[dnn * 9 + 2];
/* SOURCE output.for:1596 */
/*<       hd=zmax(it) >*/
		hd = bnrslt_1.zmax[it - 1];
/* SOURCE output.for:1597 */
/*<       endif >*/
	    }
/* SOURCE output.for:1598 */
/*<       h=w*hu+wc*hd-hdatum >*/
	    feq_gen_h_d_ = static_cast<double>(static_cast<double>(static_cast<double>(w) * hu) + static_cast<double>(wc) * hd) - hdatum;
/* SOURCE output.for:1599 */
/*<       elseif(qpos*sysgn.lt.0)then >*/
	} else if (static_cast<double>(qpos) * sysgn < (float)0.) {
/*           Maximum flow was from D to U. */
/* SOURCE output.for:1601 */
/*<       callget613(nex,exnodt,duadr,mdn,0,hdatum,h,tabn,hmax,tabtyp) >*/
	    get613_(nex, &exnodt[10], &duadr, &mdn, &feq_gen_c_d_0, &hdatum, &feq_gen_h_d_, &
		    tabn, &hmax, &tabtyp);
/* SOURCE output.for:1604 */
/*<       endif >*/
	}
/* SOURCE output.for:1605 */
/*<       if(qpos.gt.0.0)then >*/
	if (qpos > (float)0.) {
/* SOURCE output.for:1606 */
/*<       if(h.gt.hmax)then >*/
	    if (feq_gen_h_d_ > hmax) {
/* SOURCE output.for:1607 */
/*<       if(hout.eq.0)then >*/
		if (hout == 0) {
/* SOURCE output.for:1608 */
/*<       write(stdout,50) >*/
		    feq_gen_io_d__220.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__220);
		    e_wsfe();
/* SOURCE output.for:1609 */
/*<       hout=1 >*/
		    hout = 1;
/* SOURCE output.for:1610 */
/*<       endif >*/
		}
/*             Final result  is above maximum ups head. */
/* SOURCE output.for:1612 */
/*<       write(stdout,52)get_tabid(tabn),tabtyp,hmax,h-hmax >*/
		feq_gen_io_d__221.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__221);
		feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tabn);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)&tabtyp, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&hmax, (ftnlen)sizeof(real));
		feq_gen_r_d_1 = static_cast<double>(feq_gen_h_d_) - hmax;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE output.for:1613 */
/*<       endif >*/
	    }
/* SOURCE output.for:1614 */
/*<       endif >*/
	}
/* SOURCE output.for:1616 */
/*<       if(qneg*sysgn.gt.0)then >*/
	if (static_cast<double>(qneg) * sysgn > (float)0.) {
/*           Minimum flow was from U to D. */
/* SOURCE output.for:1618 */
/*<       adr=udadr >*/
	    adr = udadr;
/* SOURCE output.for:1619 */
/*<       tabn=itab(adr+1) >*/
	    tabn = itab[adr + 1];
/* SOURCE output.for:1620 */
/*<       tabtyp=itab(adr+2) >*/
	    tabtyp = itab[adr + 2];
/* SOURCE output.for:1621 */
/*<       hmax=ftab(adr+9) >*/
	    hmax = ftab[adr + 9];
/* SOURCE output.for:1622 */
/*<       it=exnodt(3,unn) >*/
	    it = exnodt[unn * 9 + 3];
/* SOURCE output.for:1623 */
/*<       if(it.le.0)then >*/
	    if (it <= 0) {
/* SOURCE output.for:1624 */
/*<       hu=fnzmax(unn) >*/
		hu = enrslt_1.fnzmax[unn - 1];
/* SOURCE output.for:1625 */
/*<       else >*/
	    } else {
/* SOURCE output.for:1626 */
/*<       hu=zmax(it) >*/
		hu = bnrslt_1.zmax[it - 1];
/* SOURCE output.for:1627 */
/*<       endif >*/
	    }
/* SOURCE output.for:1628 */
/*<       it=exnodt(3,dnn) >*/
	    it = exnodt[dnn * 9 + 3];
/* SOURCE output.for:1629 */
/*<       if(it.le.0)then >*/
	    if (it <= 0) {
/* SOURCE output.for:1630 */
/*<       hd=fnzmax(dnn) >*/
		hd = enrslt_1.fnzmax[dnn - 1];
/* SOURCE output.for:1631 */
/*<       else >*/
	    } else {
/* SOURCE output.for:1632 */
/*<       hd=zmax(it) >*/
		hd = bnrslt_1.zmax[it - 1];
/* SOURCE output.for:1633 */
/*<       endif >*/
	    }
/* SOURCE output.for:1634 */
/*<       h=w*hu+wc*hd-hdatum >*/
	    feq_gen_h_d_ = static_cast<double>(static_cast<double>(static_cast<double>(w) * hu) + static_cast<double>(wc) * hd) - hdatum;
/* SOURCE output.for:1635 */
/*<       elseif(qneg*sysgn.lt.0)then >*/
	} else if (static_cast<double>(qneg) * sysgn < (float)0.) {
/*           Minimum flow was from D to U. */
/* SOURCE output.for:1637 */
/*<       callget613(nex,exnodt,duadr,mdn,0,hdatum,h,tabn,hmax,tabtyp) >*/
	    get613_(nex, &exnodt[10], &duadr, &mdn, &feq_gen_c_d_0, &hdatum, &feq_gen_h_d_, &
		    tabn, &hmax, &tabtyp);
/* SOURCE output.for:1640 */
/*<       endif >*/
	}
/* SOURCE output.for:1641 */
/*<       if(-qneg.gt.0.0)then >*/
	if (-qneg > (float)0.) {
/* SOURCE output.for:1642 */
/*<       if(h.gt.hmax)then >*/
	    if (feq_gen_h_d_ > hmax) {
/* SOURCE output.for:1643 */
/*<       if(hout.eq.0)then >*/
		if (hout == 0) {
/* SOURCE output.for:1644 */
/*<       write(stdout,50) >*/
		    feq_gen_io_d__222.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__222);
		    e_wsfe();
/* SOURCE output.for:1645 */
/*<       hout=1 >*/
		    hout = 1;
/* SOURCE output.for:1646 */
/*<       endif >*/
		}
/*             Final result  is above maximum head. */
/* SOURCE output.for:1648 */
/*<       write(stdout,52)get_tabid(tabn),tabtyp,hmax,h-hmax >*/
		feq_gen_io_d__223.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__223);
		feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tabn);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)&tabtyp, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&hmax, (ftnlen)sizeof(real));
		feq_gen_r_d_1 = static_cast<double>(feq_gen_h_d_) - hmax;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE output.for:1649 */
/*<       endif >*/
	    }
/* SOURCE output.for:1650 */
/*<       endif >*/
	}
/* SOURCE output.for:1653 */
/*<       endif >*/
    }
/* SOURCE output.for:1655 */
/*<       if(code.gt.0)then >*/
    if (code > 0) {
/*         Continue the search. */
/* SOURCE output.for:1657 */
/*<       goto100 >*/
	goto L100;
/* SOURCE output.for:1658 */
/*<       endif >*/
    }
/* SOURCE output.for:1659 */
/*<       return >*/
    return 0;
/* SOURCE output.for:1660 */
/*<       end >*/
} /* tdtchk_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE output.for:1664 */
/*<       subroutinewrite_dlay_dten(stdout,dlay_pnt,dten_pnt) >*/
/* Subroutine */ int feq_gen_write_dlay_dten_d_(integer *stdout, integer *feq_gen_dlay_pnt_d_, 
	integer *feq_gen_dten_pnt_d_)
{
    /* Format strings */
    static char fmt_81[] = "(5x,\002Flows subject to delay and detention.\
\002)";
    static char fmt_82[] = "(5x,\002 Flows subject to detention.\002)";
    static char fmt_83[] = "(5x,\002Flows subject to delay\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__224 = { 0, 0, 0, fmt_81, 0 };
    static cilist feq_gen_io_d__225 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__226 = { 0, 0, 0, fmt_83, 0 };


/*     Write the presence of delay, detention or both */
/* SOURCE output.for:1668 */
/*<       implicitnone >*/
/* SOURCE output.for:1669 */
/*<       integerstdout,dlay_pnt,dten_pnt >*/
/*     *******************************FORMATS**************************** */
/* SOURCE output.for:1672 */
/*<    81 format(5x,'Flows subject to delay and detention.') >*/
/* SOURCE output.for:1673 */
/*<    82 format(5x,' Flows subject to detention.') >*/
/* SOURCE output.for:1674 */
/*<    83 format(5x,'Flows subject to delay') >*/
/* *********************************************************************** */
/* SOURCE output.for:1676 */
/*<       if(dten_pnt.gt.0)then >*/
/* L81: */
/* L82: */
/* L83: */
    if (*feq_gen_dten_pnt_d_ > 0) {
/* SOURCE output.for:1677 */
/*<       if(dlay_pnt.gt.0)then >*/
	if (*feq_gen_dlay_pnt_d_ > 0) {
/* SOURCE output.for:1678 */
/*<       write(stdout,81) >*/
	    feq_gen_io_d__224.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__224);
	    e_wsfe();
/* SOURCE output.for:1679 */
/*<       else >*/
	} else {
/* SOURCE output.for:1680 */
/*<       write(stdout,82) >*/
	    feq_gen_io_d__225.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__225);
	    e_wsfe();
/* SOURCE output.for:1681 */
/*<       endif >*/
	}
/* SOURCE output.for:1682 */
/*<       else >*/
    } else {
/* SOURCE output.for:1683 */
/*<       if(dlay_pnt.gt.0)then >*/
	if (*feq_gen_dlay_pnt_d_ > 0) {
/* SOURCE output.for:1684 */
/*<       write(stdout,83) >*/
	    feq_gen_io_d__226.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__226);
	    e_wsfe();
/* SOURCE output.for:1685 */
/*<       endif >*/
	}
/* SOURCE output.for:1686 */
/*<       endif >*/
    }
/* SOURCE output.for:1687 */
/*<       return >*/
    return 0;
/* SOURCE output.for:1688 */
/*<       end >*/
} /* write_dlay_dten__ */




/* SOURCE output.for:1692 */
/*<        >*/
/* Subroutine */ int feq_gen_output_dlay_dten_parameters_d_(integer *stdout, real *
	grav, integer *feq_gen_dlay_pnt_d_, integer *feq_gen_dten_pnt_d_)
{
    /* Format strings */
    static char fmt_50[] = "(/,5x,\002 The linear reservoir delay time is\
:\002,f7.2,\002 hours.\002)";
    static char fmt_52[] = "(/,5x,\002 The detention parameters are:\002,/,7\
x,\002 Design depth=\002,f7.2,\002 feet.\002,/,7x,\002 Unit area flow=\002,f\
7.3,\002 cfs/acre.\002,/,7x,\002 Pond side slope=\002,f7.2,\002 horizontal/v\
ertical\002,/,7x,\002 Average drainage area=\002,f8.2,\002 acres.\002,/,7x\
,\002 Overflow weir slope=\002,f8.2,\002 horizontal/vertical\002,/,7x,\002 D\
imensionless weir coefficient=\002,f7.3,/,7x,\002 Impervious area land-use i\
ndex=\002,i3,/,7x,\002 Table Id for detention volumes=\002,a,/,7x,\002 Table\
 Id for orifice flow=\002,a)";
    static char fmt_62[] = "(/,5x,\002 The detention parameters are:\002,/,7\
x,\002 Design depth=\002,f7.2,\002 meters.\002,/,7x,\002 Unit area flow=\002\
,f7.3,\002 cms/km^2.\002,/,7x,\002 Pond side slope=\002,f7.2,\002 horizontal\
/vertical\002,/,7x,\002 Average drainage area=\002,f10.5,\002 km^2.\002,/,7x,\
\002 Overflow weir slope=\002,f8.2,\002 horizontal/vertical\002,/,7x,\002 Di\
mensionless weir coefficient=\002,f7.3,/,7x,\002 Impervious area land-use in\
dex=\002,i3,/,7x,\002 Table Id for detention volumes=\002,a,/,7x,\002 Table \
Id for orifice flow=\002,a)";
    static char fmt_64[] = "(/,5x,\002 Linear-reservoir delay computed bel\
ow.\002)";

    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2;
    doublereal feq_gen_d_d_1;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16], feq_gen_ch_d_3[16], feq_gen_ch_d_4[16];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__227 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__228 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__229 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__230 = { 0, 0, 0, fmt_62, 0 };


/*     Output a summary of the delay and detention parameters for */
/*     a tributary-area unit. */
/* SOURCE output.for:1698 */
/*<       implicitnone >*/
/* SOURCE output.for:1699 */
/*<       integerstdout,dlay_pnt,dten_pnt >*/
/* SOURCE output.for:1700 */
/*<       realgrav >*/
/* INCLUDE output.for:1703 */
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
/* INCLUDE output.for:1704 */
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
/* INCLUDE output.for:1705 */
/*     Common block for default detention basin values. */
/* SOURCE dtendef.cmn:3 */
/*<        >*/
/* SOURCE dtendef.cmn:6 */
/*<        >*/
/* SOURCE dtendef.cmn:9 */
/*<       character*16def_dten_orif_tabid,def_dten_unit_area_vol_tabid >*/
/* SOURCE dtendef.cmn:12 */
/*<        >*/
/* SOURCE dtendef.cmn:17 */
/*<       common/dtendefc/def_dten_orif_tabid,def_dten_unit_area_vol_tabid >*/
/*     External names */
/* SOURCE output.for:1708 */
/*<       characterget_tabid*16 >*/
/* SOURCE output.for:1709 */
/*<       externalget_tabid >*/
/*     ******************************FORMATS***************************** */
/* SOURCE output.for:1711 */
/*<    50 format(/,5x,' The linear reservoir delay time is:',f7.2,' hours.') >*/
/* SOURCE output.for:1712 */
/*<    52  >*/
/* SOURCE output.for:1722 */
/*<    62  >*/
/* SOURCE output.for:1732 */
/*<    64 format(/,5x,' Linear-reservoir delay computed below.') >*/
/* *********************************************************************** */
/* SOURCE output.for:1734 */
/*<       if(dlay_pnt.gt.0)then >*/
/* L50: */
/* L52: */
/* L62: */
/* L64: */
    if (*feq_gen_dlay_pnt_d_ > 0) {
/*       We have some delay. */
/* SOURCE output.for:1736 */
/*<       if(dlay_k(dlay_pnt).gt.0.0)then >*/
	if (tamcom_1.feq_gen_dlay_k_d_[*feq_gen_dlay_pnt_d_] > (float)0.) {
/* SOURCE output.for:1737 */
/*<       write(stdout,50)dlay_k(dlay_pnt)/3600. >*/
	    feq_gen_io_d__227.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__227);
	    feq_gen_d_d_1 = tamcom_1.feq_gen_dlay_k_d_[*feq_gen_dlay_pnt_d_] / (float)3600.;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_d_d_1, (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* SOURCE output.for:1738 */
/*<       else >*/
	} else {
/* SOURCE output.for:1739 */
/*<       write(stdout,64) >*/
	    feq_gen_io_d__228.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__228);
	    e_wsfe();
/* SOURCE output.for:1740 */
/*<       endif >*/
	}
/* SOURCE output.for:1741 */
/*<       endif >*/
    }
/* SOURCE output.for:1743 */
/*<       if(dten_pnt.gt.0)then >*/
    if (*feq_gen_dten_pnt_d_ > 0) {
/*       We have detention. */
/* SOURCE output.for:1745 */
/*<       if(grav.gt.15.0)then >*/
	if (*grav > (float)15.) {
/* SOURCE output.for:1746 */
/*<        >*/
	    feq_gen_io_d__229.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__229);
	    do_fio(&feq_gen_c_d_1, (char *)&tamcom_1.feq_gen_dten_yd_d_[*feq_gen_dten_pnt_d_ - 1], (
		    ftnlen)sizeof(real));
	    feq_gen_r_d_1 = static_cast<double>(tamcom_1.feq_gen_dten_uaq_d_[*feq_gen_dten_pnt_d_ - 1]) * (float)43560.;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&tamcom_1.feq_gen_dten_bz_d_[*feq_gen_dten_pnt_d_ - 1], (
		    ftnlen)sizeof(real));
	    feq_gen_r_d_2 = static_cast<double>(tamcom_1.feq_gen_dten_avda_d_[*feq_gen_dten_pnt_d_ - 1]) / (float)43560.;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&tamcom_1.feq_gen_dten_wz_d_[*feq_gen_dten_pnt_d_ - 1], (
		    ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&tamcom_1.feq_gen_dten_wc_d_[*feq_gen_dten_pnt_d_ - 1], (
		    ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&dtendef_1.feq_gen_def_dten_lui_d_, (ftnlen)sizeof(
		    integer));
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tamcom_1.feq_gen_dten_uadv_tab_d_[*
		    feq_gen_dten_pnt_d_ - 1]);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_4, (ftnlen)16, &tamcom_1.feq_gen_dten_orf_tab_d_[*
		    feq_gen_dten_pnt_d_ - 1]);
	    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)16);
	    e_wsfe();
/* SOURCE output.for:1752 */
/*<       else >*/
	} else {
/* SOURCE output.for:1753 */
/*<        >*/
	    feq_gen_io_d__230.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__230);
	    do_fio(&feq_gen_c_d_1, (char *)&tamcom_1.feq_gen_dten_yd_d_[*feq_gen_dten_pnt_d_ - 1], (
		    ftnlen)sizeof(real));
	    feq_gen_r_d_1 = static_cast<double>(tamcom_1.feq_gen_dten_uaq_d_[*feq_gen_dten_pnt_d_ - 1]) * (float)1e6;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&tamcom_1.feq_gen_dten_bz_d_[*feq_gen_dten_pnt_d_ - 1], (
		    ftnlen)sizeof(real));
	    feq_gen_r_d_2 = static_cast<double>(tamcom_1.feq_gen_dten_avda_d_[*feq_gen_dten_pnt_d_ - 1]) / (float)1e6;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&tamcom_1.feq_gen_dten_wz_d_[*feq_gen_dten_pnt_d_ - 1], (
		    ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&tamcom_1.feq_gen_dten_wc_d_[*feq_gen_dten_pnt_d_ - 1], (
		    ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&dtendef_1.feq_gen_def_dten_lui_d_, (ftnlen)sizeof(
		    integer));
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &tamcom_1.feq_gen_dten_uadv_tab_d_[*
		    feq_gen_dten_pnt_d_ - 1]);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_4, (ftnlen)16, &tamcom_1.feq_gen_dten_orf_tab_d_[*
		    feq_gen_dten_pnt_d_ - 1]);
	    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)16);
	    e_wsfe();
/* SOURCE output.for:1759 */
/*<       endif >*/
	}
/* SOURCE output.for:1760 */
/*<       endif >*/
    }
/* SOURCE output.for:1761 */
/*<       return >*/
    return 0;
/* SOURCE output.for:1762 */
/*<       end >*/
} /* output_dlay_dten_parameters__ */




/* SOURCE output.for:1766 */
/*<        >*/
/* Subroutine */ int trbout_(real *sfac, real *sfac2, integer *stdout, 
	integer *nbra, integer *feq_storage_brpt, real *feq_storage_triba, integer *nrwta, integer *
	feq_storage_rtap, integer *feq_storage_rwta, integer *gstart, integer *gend, integer *ngage, 
	integer *glu, real *feq_storage_rtafac, real *feq_storage_tafac, real *feq_storage_xvec, real *grav)
{
    /* Initialized data */

    static char labelt[8*12+1] = "   AREA1   AREA2   AREA3   AREA4   AREA5  \
 AREA6   AREA7   AREA8   AREA9  AREA10  AREA11  AREA12";
    static char total[8+1] = "   TOTAL";
    static real feq_gen_frac_eps_d_ = (float).002;

    /* Format strings */
    static char fmt_50[] = "(/,\002 *BUG:XXX* Invalid CAT_CODE=\002,i5,\002 \
in sub. TRBOUT.\002)";
    static char fmt_64[] = "(/,\002 Tributary Area Unit flowing into Branch\
:\002,i5)";
    static char fmt_66[] = "(/,\002 Tributary Area Unit flowing into LPR/BN\
:\002,a5)";
    static char fmt_70[] = "(\002  GAGE\002,13a8)";
    static char fmt_72[] = "(\002 \002,i5,13a8)";
    static char fmt_74[] = "(\002 \002,a5,13a8)";
    static char fmt_78[] = "(\002  Node Fraction\002)";
    static char fmt_80[] = "(i6,f9.5)";
    static char fmt_81[] = "(\002 Sum of runoff allocation fractions=\002,f1\
0.4)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(), s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), 
	    e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_fill_var_decimal_vector_d_(integer *, real *, 
	    char *, ftnlen);
    integer feq_gen_cat_code_d_;
    real feq_gen_old_frac_d_;
    integer feq_gen_dten_pnt_d_, feq_gen_dlay_pnt_d_, feq_gen_unit_pnt_d_, feq_gen_i_d_, j, n, feq_gen_triba_pnt_d_, je, 
	    js;
    real tp;
    char feq_gen_sum_string_d_[8];
    real tpp, sum;
    extern /* Subroutine */ int feq_gen_var_decimal_d_(real *, char *, ftnlen);
    real sum2, afac;
    integer gage;
    real frac;
    integer ibra, item;
    real temp[9];
    char char8[8*9];
    integer feq_gen_node_convert_d_, feq_gen_fraction_pnt_d_;
    extern /* Subroutine */ int feq_gen_output_dlay_dten_parameters_d_(integer *, real 
	    *, integer *, integer *);
    char label[8*8];
    integer fnode, lnode;
    real feq_gen_standard_afac_d_;
    extern integer getusb_(integer *);
    real netsum[153]	/* was [17][9] */;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);
    extern /* Subroutine */ int marsum_(integer *, integer *, integer *, real 
	    *);
    integer feq_gen_lpr_knt_d_;
    extern /* Subroutine */ int feq_gen_write_dlay_dten_d_(integer *, integer *, 
	    integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__239 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__240 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__247 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__249 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__250 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__263 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__268 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__272 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__273 = { 0, 0, 0, fmt_81, 0 };
    static cilist feq_gen_io_d__274 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__275 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__276 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__277 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__278 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__279 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__280 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__281 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__282 = { 0, 0, 0, fmt_74, 0 };


/*     + + + PURPOSE + + + */
/*     Output the tributary areas as they exist at the end of TRIBIN */
/*     to verify that TRIBIN has processed them correctly. */
/* SOURCE output.for:1775 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE output.for:1777 */
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
/* SOURCE output.for:1780 */
/*<       integerglu,stdout,nbra,ngage,nrwta >*/
/* SOURCE output.for:1781 */
/*<        >*/
/* SOURCE output.for:1783 */
/*<        >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     SFAC   - conversion factor from user stations to internal stations */
/*     SFAC2  - conversion factor for tributary area */
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
/*     TRIBA  - tributary areas for the model */
/*     NRWTA  - number of reservoirs with tributary area */
/*     RTAP   - reservoir tributary area pointer */
/*     RWTA   - reservoirs with tributary area */
/*     GSTART - starting address for storing land uses for each gage */
/*     GEND   - ending address for storing land uses for each gage */
/*     NGAGE  - number of gages */
/*     GLU    - number of gaged land uses in the model */
/*     RTAFAC - reservoir tributary area factor */
/*     TAFAC  - factor to adjust tributary areas */
/*     XVEC   - station values for each node on a branch */
/* INCLUDE output.for:1813 */
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
/*     + + + SAVED VALUES + + + */
/* SOURCE output.for:1816 */
/*<       characterlabelt(12)*8,total*8 >*/
/* SOURCE output.for:1817 */
/*<       savelabelt,total >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE output.for:1820 */
/*<        >*/
/* SOURCE output.for:1825 */
/*<        >*/
/* SOURCE output.for:1829 */
/*<       characterchar8(mxn_lu_g+1)*8,sum_string*8,label(mxn_lu_g)*8 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE output.for:1833 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE output.for:1836 */
/*<       integergetusb >*/
/* SOURCE output.for:1837 */
/*<       charactergetusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE output.for:1840 */
/*<       externalgetusb,getusn,marsum,var_decimal,fill_var_decimal_vector >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE output.for:1844 */
/*<        >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<real> triba(feq_storage_triba, 8401);

    feq::IndexedPointer<integer> rtap(feq_storage_rtap, 1);

    feq::IndexedPointer<integer> rwta(feq_storage_rwta, 1);

    feq::IndexedPointer<real> rtafac(feq_storage_rtafac, 1);

    feq::IndexedPointer<real> tafac(feq_storage_tafac, 1);

    feq::IndexedPointer<real> xvec(feq_storage_xvec, 1);

    /* Function Body */
/* SOURCE output.for:1849 */
/*<       datafrac_eps/2.e-3/ >*/
/* SOURCE output.for:1851 */
/*<    50 format(/,' *BUG:XXX* Invalid CAT_CODE=',i5,' in sub. TRBOUT.') >*/
/* L50: */
/* SOURCE output.for:1852 */
/*<    60 format(' FNODE GAGE',14a8) >*/
/* L60: */
/* SOURCE output.for:1853 */
/*<    64 format(/,' Tributary Area Unit flowing into Branch:',i5) >*/
/* L64: */
/* SOURCE output.for:1854 */
/*<    66 format(/,' Tributary Area Unit flowing into LPR/BN:',a5) >*/
/* L66: */
/* SOURCE output.for:1855 */
/*<    68 format(' ',2i5,12a8) >*/
/* L68: */
/* SOURCE output.for:1856 */
/*<    70 format('  GAGE',13a8) >*/
/* L70: */
/* SOURCE output.for:1857 */
/*<    72 format(' ',i5,13a8) >*/
/* L72: */
/* SOURCE output.for:1858 */
/*<    74 format(' ',a5,13a8) >*/
/* L74: */
/* SOURCE output.for:1859 */
/*<    78 format('  Node Fraction') >*/
/* L78: */
/* SOURCE output.for:1860 */
/*<    80 format(i6,f9.5) >*/
/* L80: */
/* SOURCE output.for:1861 */
/*<    81 format(' Sum of runoff allocation fractions=',f10.4) >*/
/* L81: */
/* *********************************************************************** */
/*      WRITE(STDOUT,*) ' At entry to TRBOUT: GLU=',GLU */
/*     Set the labels */
/* SOURCE output.for:1865 */
/*<       do101i=1,glu >*/
    feq_gen_i_d_1 = *glu;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE output.for:1866 */
/*<       label(i)=labelt(i) >*/
	s_copy(label + (feq_gen_i_d_ - 1 << 3), labelt + (feq_gen_i_d_ - 1 << 3), (ftnlen)8, (
		ftnlen)8);
/* SOURCE output.for:1867 */
/*<   101 continue >*/
/* L101: */
    }
/*     Set the standard factor to convert internal tributary area */
/*     to square miles for English and square kilometers for Metric. */
/*     Used only for the Network summary of tributary area. */
/* SOURCE output.for:1873 */
/*<       if(grav.gt.15.0)then >*/
    if (*grav > (float)15.) {
/*       English */
/* SOURCE output.for:1875 */
/*<       standard_afac=5280.**2 >*/
	feq_gen_standard_afac_d_ = (float)27878400.;
/* SOURCE output.for:1876 */
/*<       else >*/
    } else {
/* SOURCE output.for:1877 */
/*<       standard_afac=1000.**2 >*/
	feq_gen_standard_afac_d_ = (float)1e6;
/* SOURCE output.for:1878 */
/*<       endif >*/
    }
/*     CLEAR THE NETWORK SUMMARY ARRAY */
/* SOURCE output.for:1882 */
/*<       do110i=1,ngage >*/
    feq_gen_i_d_1 = *ngage;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE output.for:1883 */
/*<       do100j=1,glu >*/
	feq_gen_i_d_2 = *glu;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE output.for:1884 */
/*<       netsum(i,j)=0.0 >*/
	    netsum[feq_gen_i_d_ + j * 17 - 18] = (float)0.;
/* SOURCE output.for:1885 */
/*<   100 continue >*/
/* L100: */
	}
/* SOURCE output.for:1886 */
/*<   110 continue >*/
/* L110: */
    }
/* SOURCE output.for:1888 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__239.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__239);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE output.for:1889 */
/*<       write(stdout,*)' DISPLAY AND SUMMARY OF TRIBUTARY AREA' >*/
    feq_gen_io_d__240.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__240);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" DISPLAY AND SUMMARY OF TRIBUTARY AREA"), (ftnlen)38)
	    ;
    e_wsle();
/*     Scan through the tributary management vector, TAM_ITAB, and */
/*     print values in the order of input. */
/* SOURCE output.for:1894 */
/*<       unit_pnt=1 >*/
    feq_gen_unit_pnt_d_ = 1;
/* SOURCE output.for:1895 */
/*<       lpr_knt=0 >*/
    feq_gen_lpr_knt_d_ = 0;
/* SOURCE output.for:1897 */
/*<  9000 continue >*/
L9000:
/* SOURCE output.for:1899 */
/*<       item=tam_itab(unit_pnt) >*/
    item = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ - 1];
/* SOURCE output.for:1900 */
/*<       cat_code=tam_itab(unit_pnt+1) >*/
    feq_gen_cat_code_d_ = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_];
/* SOURCE output.for:1901 */
/*<       dten_pnt=tam_itab(unit_pnt+5) >*/
    feq_gen_dten_pnt_d_ = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 4];
/* SOURCE output.for:1902 */
/*<       dlay_pnt=tam_itab(unit_pnt+6) >*/
    feq_gen_dlay_pnt_d_ = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 5];
/* SOURCE output.for:1904 */
/*<       goto(1000,2000,3000),cat_code >*/
    switch (feq_gen_cat_code_d_) {
	case 1:  goto L1000;
	case 2:  goto L2000;
	case 3:  goto L3000;
    }
/* SOURCE output.for:1906 */
/*<       write(stdout,50)cat_code >*/
    feq_gen_io_d__247.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__247);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_cat_code_d_, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE output.for:1907 */
/*<       stop'Abnormal stop. Bug found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Bug found."), (ftnlen)25);
/* SOURCE output.for:1910 */
/*<  1000 continue >*/
L1000:
/*         Output summary for a tributary unit on a branch. */
/* SOURCE output.for:1913 */
/*<       ibra=item >*/
    ibra = item;
/* SOURCE output.for:1914 */
/*<       write(stdout,64)getusb(ibra) >*/
    feq_gen_io_d__249.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__249);
    feq_gen_i_d_1 = getusb_(&ibra);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE output.for:1915 */
/*<       callwrite_dlay_dten(stdout,dlay_pnt,dten_pnt) >*/
    feq_gen_write_dlay_dten_d_(stdout, &feq_gen_dlay_pnt_d_, &feq_gen_dten_pnt_d_);
/* SOURCE output.for:1917 */
/*<       write(stdout,70)(label(j),j=1,glu),total >*/
    feq_gen_io_d__250.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__250);
    feq_gen_i_d_1 = *glu;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
	do_fio(&feq_gen_c_d_1, label + (j - 1 << 3), (ftnlen)8);
    }
    do_fio(&feq_gen_c_d_1, total, (ftnlen)8);
    e_wsfe();
/* SOURCE output.for:1919 */
/*<       if(tafac(ibra).lt.0.0)then >*/
    if (tafac[ibra] < (float)0.) {
/* SOURCE output.for:1920 */
/*<       afac=sfac2 >*/
	afac = *sfac2;
/* SOURCE output.for:1921 */
/*<       else >*/
    } else {
/* SOURCE output.for:1922 */
/*<       afac=sfac2*tafac(ibra) >*/
	afac = static_cast<double>(*sfac2) * tafac[ibra];
/* SOURCE output.for:1923 */
/*<       endif >*/
    }
/* SOURCE output.for:1924 */
/*<       gage=tam_itab(unit_pnt+4) >*/
    gage = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 3];
/* SOURCE output.for:1925 */
/*<       je=gend(gage) >*/
    je = gend[gage];
/* SOURCE output.for:1926 */
/*<       js=gstart(gage) >*/
    js = gstart[gage];
/* SOURCE output.for:1927 */
/*<       triba_pnt=tam_itab(unit_pnt+3) >*/
    feq_gen_triba_pnt_d_ = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 2];
/* SOURCE output.for:1928 */
/*<       n=je-js+1 >*/
    n = je - js + 1;
/* SOURCE output.for:1929 */
/*<       sum=0.0 >*/
    sum = (float)0.;
/* SOURCE output.for:1930 */
/*<       do1010j=1,n >*/
    feq_gen_i_d_1 = n;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE output.for:1931 */
/*<       tp=triba(triba_pnt,j)/afac >*/
	tp = static_cast<double>(triba[feq_gen_triba_pnt_d_ + j * 8400]) / afac;
/* SOURCE output.for:1932 */
/*<       tpp=triba(triba_pnt,j)/standard_afac >*/
	tpp = static_cast<double>(triba[feq_gen_triba_pnt_d_ + j * 8400]) / feq_gen_standard_afac_d_;
/* SOURCE output.for:1933 */
/*<       temp(j)=tp >*/
	temp[j - 1] = tp;
/* SOURCE output.for:1934 */
/*<       netsum(gage,j)=netsum(gage,j)+tpp >*/
	netsum[gage + j * 17 - 18] += tpp;
/* SOURCE output.for:1935 */
/*<       if(tp.gt.0.0)then >*/
	if (tp > (float)0.) {
/* SOURCE output.for:1936 */
/*<       sum=sum+tp >*/
	    sum += tp;
/* SOURCE output.for:1937 */
/*<       endif >*/
	}
/* SOURCE output.for:1938 */
/*<  1010 continue >*/
/* L1010: */
    }
/* SOURCE output.for:1939 */
/*<       callfill_var_decimal_vector(n,temp,char8) >*/
    feq_gen_fill_var_decimal_vector_d_(&n, temp, char8, (ftnlen)8);
/* SOURCE output.for:1941 */
/*<       callvar_decimal(sum,sum_string) >*/
    feq_gen_var_decimal_d_(&sum, feq_gen_sum_string_d_, (ftnlen)8);
/* SOURCE output.for:1943 */
/*<       write(stdout,72)gage,(char8(j),j=1,n),sum_string >*/
    feq_gen_io_d__263.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__263);
    do_fio(&feq_gen_c_d_1, (char *)&gage, (ftnlen)sizeof(integer));
    feq_gen_i_d_1 = n;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
	do_fio(&feq_gen_c_d_1, char8 + (j - 1 << 3), (ftnlen)8);
    }
    do_fio(&feq_gen_c_d_1, feq_gen_sum_string_d_, (ftnlen)8);
    e_wsfe();
/* SOURCE output.for:1945 */
/*<       if(sum.ne.0.0)then >*/
    if (sum != (float)0.) {
/*           Print the flow distribution fractions for the */
/*           computational elements on the branch. */
/* SOURCE output.for:1948 */
/*<       fnode=tam_itab(unit_pnt+7) >*/
	fnode = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 6];
/* SOURCE output.for:1949 */
/*<       lnode=tam_itab(unit_pnt+8) >*/
	lnode = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 7];
/*           Get offset to convert from internal node number to */
/*           the user node number. */
/* SOURCE output.for:1952 */
/*<       node_convert=brpt(1,ibra)-brpt(3,ibra) >*/
	feq_gen_node_convert_d_ = brpt[(ibra << 3) + 1] - brpt[(ibra << 3) + 3];
/* SOURCE output.for:1953 */
/*<       fraction_pnt=tam_itab(unit_pnt+9) >*/
	feq_gen_fraction_pnt_d_ = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 8];
/* SOURCE output.for:1954 */
/*<       write(stdout,78) >*/
	feq_gen_io_d__268.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__268);
	e_wsfe();
/*            WRITE(STDOUT,*) ' FRACTION_PNT=',FRACTION_PNT */
/*            WRITE(STDOUT,*) ' FNODE=',FNODE,' LNODE=',LNODE */
/* SOURCE output.for:1957 */
/*<       sum2=0.0 >*/
	sum2 = (float)0.;
/* SOURCE output.for:1958 */
/*<       old_frac=0.0 >*/
	feq_gen_old_frac_d_ = (float)0.;
/* SOURCE output.for:1959 */
/*<       do1020j=fnode,lnode >*/
	feq_gen_i_d_1 = lnode;
	for (j = fnode; j <= feq_gen_i_d_1; ++j) {
/* SOURCE output.for:1960 */
/*<       frac=tam_ftab(fraction_pnt+j-fnode) >*/
	    frac = tamcom_1.feq_gen_tam_ftab_d_[feq_gen_fraction_pnt_d_ + j - fnode - 1];
/* SOURCE output.for:1961 */
/*<       if(abs(frac-old_frac)/(frac+0.01).gt.frac_eps)then >*/
	    if ((feq_gen_r_d_1 = static_cast<double>(frac) - feq_gen_old_frac_d_, dabs(feq_gen_r_d_1)) / (static_cast<double>(frac) + (float).01) 
		    > feq_gen_frac_eps_d_) {
/*               The fraction has changed.  Print the changed value */
/* SOURCE output.for:1963 */
/*<       write(stdout,80)j+node_convert,frac >*/
		feq_gen_io_d__272.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__272);
		feq_gen_i_d_2 = j + feq_gen_node_convert_d_;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_2, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, (char *)&frac, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE output.for:1964 */
/*<       old_frac=frac >*/
		feq_gen_old_frac_d_ = frac;
/* SOURCE output.for:1965 */
/*<       endif >*/
	    }
/* SOURCE output.for:1966 */
/*<       sum2=sum2+tam_ftab(fraction_pnt+j-fnode) >*/
	    sum2 += tamcom_1.feq_gen_tam_ftab_d_[feq_gen_fraction_pnt_d_ + j - fnode - 1];
/* SOURCE output.for:1967 */
/*<  1020 continue >*/
/* L1020: */
	}
/* SOURCE output.for:1968 */
/*<       write(stdout,81)sum2 >*/
	feq_gen_io_d__273.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__273);
	do_fio(&feq_gen_c_d_1, (char *)&sum2, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE output.for:1969 */
/*<       endif >*/
    }
/* SOURCE output.for:1971 */
/*<       calloutput_dlay_dten_parameters(stdout,grav,dlay_pnt,dten_pnt) >*/
    feq_gen_output_dlay_dten_parameters_d_(stdout, grav, &feq_gen_dlay_pnt_d_, &feq_gen_dten_pnt_d_);
/* SOURCE output.for:1974 */
/*<       goto9999 >*/
    goto L9999;
/* SOURCE output.for:1976 */
/*<  2000 continue >*/
L2000:
/*         Output summary for tributary unit on a level-pool reservoir or a */
/*         boundary node.  At this point in input processing we cannot */
/*         tell the difference. */
/* SOURCE output.for:1980 */
/*<       lpr_knt=tam_itab(unit_pnt+8) >*/
    feq_gen_lpr_knt_d_ = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 7];
/* SOURCE output.for:1981 */
/*<       write(stdout,66)getusn(rwta(lpr_knt)) >*/
    feq_gen_io_d__274.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__274);
    getusn_(feq_gen_ch_d_2, (ftnlen)5, &rwta[feq_gen_lpr_knt_d_]);
    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
    e_wsfe();
/* SOURCE output.for:1982 */
/*<       callwrite_dlay_dten(stdout,dlay_pnt,dten_pnt) >*/
    feq_gen_write_dlay_dten_d_(stdout, &feq_gen_dlay_pnt_d_, &feq_gen_dten_pnt_d_);
/* SOURCE output.for:1983 */
/*<       write(stdout,70)(label(j),j=1,glu),total >*/
    feq_gen_io_d__275.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__275);
    feq_gen_i_d_1 = *glu;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
	do_fio(&feq_gen_c_d_1, label + (j - 1 << 3), (ftnlen)8);
    }
    do_fio(&feq_gen_c_d_1, total, (ftnlen)8);
    e_wsfe();
/* SOURCE output.for:1984 */
/*<       triba_pnt=tam_itab(unit_pnt+3) >*/
    feq_gen_triba_pnt_d_ = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 2];
/* SOURCE output.for:1985 */
/*<       gage=tam_itab(unit_pnt+4) >*/
    gage = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 3];
/* SOURCE output.for:1986 */
/*<       if(rtafac(lpr_knt).lt.0.0)then >*/
    if (rtafac[feq_gen_lpr_knt_d_] < (float)0.) {
/* SOURCE output.for:1987 */
/*<       afac=sfac2 >*/
	afac = *sfac2;
/* SOURCE output.for:1988 */
/*<       else >*/
    } else {
/* SOURCE output.for:1989 */
/*<       afac=sfac2*rtafac(lpr_knt) >*/
	afac = static_cast<double>(*sfac2) * rtafac[feq_gen_lpr_knt_d_];
/* SOURCE output.for:1990 */
/*<       endif >*/
    }
/* SOURCE output.for:1992 */
/*<       je=gend(gage) >*/
    je = gend[gage];
/* SOURCE output.for:1993 */
/*<       js=gstart(gage) >*/
    js = gstart[gage];
/* SOURCE output.for:1994 */
/*<       sum=0.0 >*/
    sum = (float)0.;
/* SOURCE output.for:1995 */
/*<       n=je-js+1 >*/
    n = je - js + 1;
/* SOURCE output.for:1996 */
/*<       do2010j=1,n >*/
    feq_gen_i_d_1 = n;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE output.for:1997 */
/*<       tp=triba(triba_pnt,j)/afac >*/
	tp = static_cast<double>(triba[feq_gen_triba_pnt_d_ + j * 8400]) / afac;
/* SOURCE output.for:1998 */
/*<       tpp=triba(triba_pnt,j)/standard_afac >*/
	tpp = static_cast<double>(triba[feq_gen_triba_pnt_d_ + j * 8400]) / feq_gen_standard_afac_d_;
/* SOURCE output.for:1999 */
/*<       temp(j)=tp >*/
	temp[j - 1] = tp;
/* SOURCE output.for:2000 */
/*<       netsum(gage,j)=netsum(gage,j)+tpp >*/
	netsum[gage + j * 17 - 18] += tpp;
/* SOURCE output.for:2001 */
/*<       if(tp.gt.0.0)then >*/
	if (tp > (float)0.) {
/* SOURCE output.for:2002 */
/*<       sum=sum+tp >*/
	    sum += tp;
/* SOURCE output.for:2003 */
/*<       endif >*/
	}
/* SOURCE output.for:2004 */
/*<  2010 continue >*/
/* L2010: */
    }
/* SOURCE output.for:2005 */
/*<       callfill_var_decimal_vector(n,temp,char8) >*/
    feq_gen_fill_var_decimal_vector_d_(&n, temp, char8, (ftnlen)8);
/* SOURCE output.for:2007 */
/*<       callvar_decimal(sum,sum_string) >*/
    feq_gen_var_decimal_d_(&sum, feq_gen_sum_string_d_, (ftnlen)8);
/* SOURCE output.for:2009 */
/*<       write(stdout,72)gage,(char8(j),j=1,n),sum_string >*/
    feq_gen_io_d__276.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__276);
    do_fio(&feq_gen_c_d_1, (char *)&gage, (ftnlen)sizeof(integer));
    feq_gen_i_d_1 = n;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
	do_fio(&feq_gen_c_d_1, char8 + (j - 1 << 3), (ftnlen)8);
    }
    do_fio(&feq_gen_c_d_1, feq_gen_sum_string_d_, (ftnlen)8);
    e_wsfe();
/* SOURCE output.for:2012 */
/*<       calloutput_dlay_dten_parameters(stdout,grav,dlay_pnt,dten_pnt) >*/
    feq_gen_output_dlay_dten_parameters_d_(stdout, grav, &feq_gen_dlay_pnt_d_, &feq_gen_dten_pnt_d_);
/* SOURCE output.for:2015 */
/*<       goto9999 >*/
    goto L9999;
/* SOURCE output.for:2017 */
/*<  3000 continue >*/
L3000:
/* SOURCE output.for:2018 */
/*<       write(stdout,*)' Should not reach here.  BN not known yet.' >*/
    feq_gen_io_d__277.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__277);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Should not reach here.  BN not known yet."), (
	    ftnlen)42);
    e_wsle();
/* SOURCE output.for:2019 */
/*<       stop'Abnormal stop: TRBOUT. Bug found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: TRBOUT. Bug found."), (ftnlen)33);
/* SOURCE output.for:2021 */
/*<  9999 continue >*/
L9999:
/*       Point to the next unit. */
/* SOURCE output.for:2023 */
/*<       unit_pnt=tam_itab(unit_pnt+2) >*/
    feq_gen_unit_pnt_d_ = tamcom_1.feq_gen_tam_itab_d_[feq_gen_unit_pnt_d_ + 1];
/* SOURCE output.for:2024 */
/*<       if(unit_pnt.ne.0)goto9000 >*/
    if (feq_gen_unit_pnt_d_ != 0) {
	goto L9000;
    }
/*     Print system wide summaries */
/* SOURCE output.for:2027 */
/*<       callmarsum(ngage,glu,mxgage+1,netsum) >*/
    marsum_(ngage, glu, &feq_gen_c_d_17, netsum);
/* SOURCE output.for:2030 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__278.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__278);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE output.for:2031 */
/*<       write(stdout,*)' NETWORK SUMMARY OF TRIBUTARY AREA' >*/
    feq_gen_io_d__279.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__279);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NETWORK SUMMARY OF TRIBUTARY AREA"), (ftnlen)34);
    e_wsle();
/* SOURCE output.for:2032 */
/*<       write(stdout,70)(label(j),j=1,glu),total >*/
    feq_gen_io_d__280.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__280);
    feq_gen_i_d_1 = *glu;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
	do_fio(&feq_gen_c_d_1, label + (j - 1 << 3), (ftnlen)8);
    }
    do_fio(&feq_gen_c_d_1, total, (ftnlen)8);
    e_wsfe();
/* SOURCE output.for:2033 */
/*<       n=glu+1 >*/
    n = *glu + 1;
/* SOURCE output.for:2034 */
/*<       do950i=1,ngage >*/
    feq_gen_i_d_1 = *ngage;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE output.for:2035 */
/*<       if(netsum(i,glu+1).gt.0.0)then >*/
	if (netsum[feq_gen_i_d_ + (*glu + 1) * 17 - 18] > (float)0.) {
/* SOURCE output.for:2036 */
/*<       do901j=1,n >*/
	    feq_gen_i_d_2 = n;
	    for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE output.for:2037 */
/*<       temp(j)=netsum(i,j) >*/
		temp[j - 1] = netsum[feq_gen_i_d_ + j * 17 - 18];
/* SOURCE output.for:2038 */
/*<   901 continue >*/
/* L901: */
	    }
/* SOURCE output.for:2039 */
/*<       callfill_var_decimal_vector(n,temp,char8) >*/
	    feq_gen_fill_var_decimal_vector_d_(&n, temp, char8, (ftnlen)8);
/* SOURCE output.for:2041 */
/*<       write(stdout,72)i,(char8(j),j=1,n) >*/
	    feq_gen_io_d__281.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__281);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_, (ftnlen)sizeof(integer));
	    feq_gen_i_d_2 = n;
	    for (j = 1; j <= feq_gen_i_d_2; ++j) {
		do_fio(&feq_gen_c_d_1, char8 + (j - 1 << 3), (ftnlen)8);
	    }
	    e_wsfe();
/* SOURCE output.for:2042 */
/*<       endif >*/
	}
/* SOURCE output.for:2043 */
/*<   950 continue >*/
/* L950: */
    }
/* SOURCE output.for:2044 */
/*<       do951j=1,n >*/
    feq_gen_i_d_1 = n;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE output.for:2045 */
/*<       temp(j)=netsum(ngage+1,j) >*/
	temp[j - 1] = netsum[*ngage + 1 + j * 17 - 18];
/* SOURCE output.for:2046 */
/*<   951 continue >*/
/* L951: */
    }
/* SOURCE output.for:2047 */
/*<       callfill_var_decimal_vector(n,temp,char8) >*/
    feq_gen_fill_var_decimal_vector_d_(&n, temp, char8, (ftnlen)8);
/* SOURCE output.for:2049 */
/*<       write(stdout,74)'TOTAL',(char8(j),j=1,n) >*/
    feq_gen_io_d__282.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__282);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("TOTAL"), (ftnlen)5);
    feq_gen_i_d_1 = n;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
	do_fio(&feq_gen_c_d_1, char8 + (j - 1 << 3), (ftnlen)8);
    }
    e_wsfe();
/* SOURCE output.for:2051 */
/*<       return >*/
    return 0;
/* SOURCE output.for:2052 */
/*<       end >*/
} /* trbout_ */




/* SOURCE output.for:2056 */
/*<       subroutinevalley(stdout,vunit,nbra,x,zw,z,brpt,nsec) >*/
/* Subroutine */ int valley_(integer *stdout, real *vunit, integer *nbra, 
	real *feq_storage_x, real *feq_storage_zw, real *feq_gen_feq_storage_z_d_, integer *feq_storage_brpt, integer *feq_storage_nsec)
{
    /* Format strings */
    static char fmt_50[] = "(\0021\002,\002ESTIMATED VALLEY STORAGE BELOW TH\
E STANDARD FLOOD\002,\002 LEVEL\002)";
    static char fmt_52[] = "(/,\002 BRANCH  STORAGE \002,/,\002 NUMBER   AC-\
FT\002)";
    static char fmt_53[] = "(/,\002 BRANCH  STORAGE \002,/,\002 NUMBER   K M\
^3\002)";
    static char fmt_54[] = "(/,\002 *ERR:149* Stand Fld Lvl at or below mini\
mum point\002,\002 in channel at branch\002,i4,\002 node\002,i6)";
    static char fmt_56[] = "(i7,f10.1)";
    static char fmt_58[] = "(\002 SYSTEM\002,f10.1)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3, feq_gen_i_d_4;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer j;
    real al, bl, ar, kl, tl, xl, yl, xr, yr, dbl, dkl, dtl;
    doublereal sum;
    integer ibra, fnode, lnode;
    extern /* Subroutine */ int xlkt20_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *);
    extern integer getusb_(integer *);
    doublereal systot;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__283 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__284 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__285 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__291 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__304 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__306 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__307 = { 0, 0, 0, fmt_58, 0 };


/*     + + + PURPOSE + + + */
/*     Compute and print valley storage. */
/* SOURCE output.for:2062 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE output.for:2064 */
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
/* SOURCE output.for:2067 */
/*<       integerstdout,nbra >*/
/* SOURCE output.for:2068 */
/*<       integerbrpt(8,nbra),nsec(mnbn) >*/
/* SOURCE output.for:2069 */
/*<       realvunit,x(mnbn),z(mnbn),zw(mnbn) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     VUNIT  - conversion factor for volumes on output */
/*     NBRA   - number of branches in the model */
/*     X      - stations for cross sections */
/*     ZW     - elevation of water surface for nodes on a branch */
/*     Z      - bottom profile elevation at each node on a branch */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE output.for:2092 */
/*<       integerfnode,ibra,j,lnode >*/
/* SOURCE output.for:2093 */
/*<       realal,ar,bl,dbl,dkl,dtl,kl,tl,xl,xr,yl,yr >*/
/* SOURCE output.for:2094 */
/*<       real*8sum,systot >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE output.for:2097 */
/*<       integergetusb >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE output.for:2100 */
/*<       externalgetusb,xlkt20 >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE output.for:2103 */
/*<    50  >*/
/* SOURCE output.for:2105 */
/*<    52 format(/,' BRANCH  STORAGE ',/,' NUMBER   AC-FT') >*/
/* SOURCE output.for:2106 */
/*<    53 format(/,' BRANCH  STORAGE ',/,' NUMBER   K M^3') >*/
/* SOURCE output.for:2107 */
/*<    54  >*/
/* SOURCE output.for:2109 */
/*<    56 format(i7,f10.1) >*/
/* SOURCE output.for:2110 */
/*<    58 format(' SYSTEM',f10.1) >*/
/* *********************************************************************** */
/* SOURCE output.for:2112 */
/*<       write(stdout,50) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    feq::IndexedPointer<real> zw(feq_storage_zw, 1);

    feq::IndexedPointer<real> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    feq::IndexedPointer<integer> nsec(feq_storage_nsec, 1);

    /* Function Body */
/* L50: */
/* L52: */
/* L53: */
/* L54: */
/* L56: */
/* L58: */
    feq_gen_io_d__283.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__283);
    e_wsfe();
/* SOURCE output.for:2113 */
/*<       if(vunit.lt.40000.0)then >*/
    if (*vunit < (float)4e4) {
/* SOURCE output.for:2114 */
/*<       write(stdout,53) >*/
	feq_gen_io_d__284.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__284);
	e_wsfe();
/* SOURCE output.for:2115 */
/*<       else >*/
    } else {
/* SOURCE output.for:2116 */
/*<       write(stdout,52) >*/
	feq_gen_io_d__285.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__285);
	e_wsfe();
/* SOURCE output.for:2117 */
/*<       endif >*/
    }
/* SOURCE output.for:2119 */
/*<       systot=0.d0 >*/
    systot = 0.;
/* SOURCE output.for:2120 */
/*<       do200ibra=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (ibra = 1; ibra <= feq_gen_i_d_1; ++ibra) {
/* SOURCE output.for:2121 */
/*<       fnode=brpt(3,ibra) >*/
	fnode = brpt[(ibra << 3) + 3];
/* SOURCE output.for:2122 */
/*<       lnode=brpt(4,ibra) >*/
	lnode = brpt[(ibra << 3) + 4];
/*       FIND AREA AT THE FIRST NODE ON THE BRANCH */
/* SOURCE output.for:2125 */
/*<       yl=zw(fnode)-z(fnode) >*/
	yl = static_cast<double>(zw[fnode]) - feq_gen_z_d_[fnode];
/* SOURCE output.for:2126 */
/*<       if(yl.le.0.0)then >*/
	if (yl <= (float)0.) {
/* SOURCE output.for:2127 */
/*<       write(stdout,54)getusb(ibra),brpt(1,ibra) >*/
	    feq_gen_io_d__291.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__291);
	    feq_gen_i_d_2 = getusb_(&ibra);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_2, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&brpt[(ibra << 3) + 1], (ftnlen)sizeof(
		    integer));
	    e_wsfe();
/* SOURCE output.for:2128 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE output.for:2129 */
/*<       endif >*/
	}
/* SOURCE output.for:2131 */
/*<       callxlkt20(nsec(ibra),yl,al,tl,dtl,kl,dkl,bl,dbl) >*/
	xlkt20_(&nsec[ibra], &yl, &al, &tl, &dtl, &kl, &dkl, &bl, &dbl);
/* SOURCE output.for:2135 */
/*<       xl=x(fnode) >*/
	xl = x[fnode];
/* SOURCE output.for:2137 */
/*<       sum=0.d0 >*/
	sum = 0.;
/* SOURCE output.for:2138 */
/*<       do100j=fnode+1,lnode >*/
	feq_gen_i_d_2 = lnode;
	for (j = fnode + 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE output.for:2139 */
/*<       xr=x(j) >*/
	    xr = x[j];
/* SOURCE output.for:2140 */
/*<       yr=zw(j)-z(j) >*/
	    yr = static_cast<double>(zw[j]) - feq_gen_z_d_[j];
/* SOURCE output.for:2141 */
/*<       if(yr.le.0.0)then >*/
	    if (yr <= (float)0.) {
/* SOURCE output.for:2142 */
/*<       write(stdout,54)getusb(ibra),brpt(1,ibra)+j-fnode >*/
		feq_gen_io_d__304.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__304);
		feq_gen_i_d_3 = getusb_(&ibra);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_3, (ftnlen)sizeof(integer));
		feq_gen_i_d_4 = brpt[(ibra << 3) + 1] + j - fnode;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_4, (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE output.for:2143 */
/*<       stop'Abnormal stop: errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE output.for:2144 */
/*<       endif >*/
	    }
/* SOURCE output.for:2146 */
/*<       callxlkt20(nsec(j),yr,ar,tl,dtl,kl,dkl,bl,dbl) >*/
	    xlkt20_(&nsec[j], &yr, &ar, &tl, &dtl, &kl, &dkl, &bl, &dbl);
/* SOURCE output.for:2150 */
/*<       sum=sum+0.5*(al+ar)*(xr-xl) >*/
	    sum += static_cast<double>(static_cast<double>((static_cast<double>(al) + ar)) * (float).5) * (static_cast<double>(xr) - xl);
/* SOURCE output.for:2152 */
/*<       xl=xr >*/
	    xl = xr;
/* SOURCE output.for:2153 */
/*<       al=ar >*/
	    al = ar;
/* SOURCE output.for:2154 */
/*<   100 continue >*/
/* L100: */
	}
/* SOURCE output.for:2155 */
/*<       sum=sum/vunit >*/
	sum /= *vunit;
/* SOURCE output.for:2156 */
/*<       write(stdout,56)getusb(ibra),sum >*/
	feq_gen_io_d__306.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__306);
	feq_gen_i_d_2 = getusb_(&ibra);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_2, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&sum, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* SOURCE output.for:2158 */
/*<       systot=systot+sum >*/
	systot += sum;
/* SOURCE output.for:2159 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE output.for:2160 */
/*<       write(stdout,58)systot >*/
    feq_gen_io_d__307.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__307);
    do_fio(&feq_gen_c_d_1, (char *)&systot, (ftnlen)sizeof(doublereal));
    e_wsfe();
/* SOURCE output.for:2162 */
/*<       end >*/
    return 0;
} /* valley_ */




/* SOURCE output.for:2166 */
/*<       subroutinewrout(jtime,stdout,qchop,dt,dz_for_output) >*/
/* Subroutine */ int wrout_(doublereal *jtime, integer *stdout, real *qchop, 
	doublereal *dt, real *feq_gen_dz_for_output_d_)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *BUG:26* INVALID VALUE OF INTERNAL CODE \
FOR OUTPUT\002,\002 FILES:\002,i5)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wdue(cilist *), do_uio(integer *, char *, ftnlen), e_wdue();

    /* Local variables */
    integer feq_gen_i_d_;
    real val;
    doublereal sum;
    integer feq_gen_is_sum_good_d_, full;
    extern /* Subroutine */ int feq_gen_update_dssout_jtime_d_(doublereal *, integer *)
	    , feq_gen_update_dssout_buffer_d_(integer *, real *), 
	    feq_gen_output_dssout_buffer_d_();

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__311 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__312 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__314 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__316 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__317 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Write curent record for all output files. */
/* SOURCE output.for:2172 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE output.for:2174 */
/*<       integerstdout >*/
/* SOURCE output.for:2175 */
/*<       realqchop,dz_for_output >*/
/* SOURCE output.for:2176 */
/*<       real*8dt,jtime >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     JTIME  - current modified julian time in the model */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     QCHOP    - value to set small flows to zero.  Avoids noise that */
/*                inevitably exists in iterative numerical computations. */
/*     DT       - time step just completed. */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE output.for:2186 */
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
/* INCLUDE output.for:2187 */
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
/* INCLUDE output.for:2188 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE output.for:2189 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/*     Create parameters for coding ACTION */
/* SOURCE output.for:2193 */
/*<       integerouta,outs,add,sub,yes,no,quad >*/
/* SOURCE output.for:2194 */
/*<       parameter(outa=1,outs=2,add=3,sub=4,yes=5,no=6,quad=7) >*/
/* SOURCE output.for:2195 */
/*<       integeri,full,is_sum_good >*/
/* SOURCE output.for:2196 */
/*<       realval >*/
/* SOURCE output.for:2197 */
/*<       real*8sum >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE output.for:2200 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE output.for:2203 */
/*<       callupdate_dssout_jtime(jtime,full) >*/
/* L50: */
    feq_gen_update_dssout_jtime_d_(jtime, &full);
/*     Set SUM to no good! */
/* SOURCE output.for:2206 */
/*<       is_sum_good=no >*/
    feq_gen_is_sum_good_d_ = 6;
/* SOURCE output.for:2207 */
/*<       do500i=1,nfout >*/
    feq_gen_i_d_1 = wrcom_1.nfout;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE output.for:2209 */
/*<       if(actout(i).ne.quad)then >*/
	if (wrcom_1.actout[feq_gen_i_d_ - 1] != 7) {
/* SOURCE output.for:2210 */
/*<       goto(1,2,3,4),icdout(i) >*/
	    switch (wrcom_1.icdout[feq_gen_i_d_ - 1]) {
		case 1:  goto L1;
		case 2:  goto L2;
		case 3:  goto L3;
		case 4:  goto L4;
	    }
/* SOURCE output.for:2211 */
/*<       write(stdout,50)icdout(i) >*/
	    feq_gen_io_d__311.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__311);
	    do_fio(&feq_gen_c_d_1, (char *)&wrcom_1.icdout[feq_gen_i_d_ - 1], (ftnlen)sizeof(
		    integer));
	    e_wsfe();
/* SOURCE output.for:2212 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE output.for:2214 */
/*<     1 continue >*/
L1:
/* SOURCE output.for:2215 */
/*<       write(stdout,50)icdout(i) >*/
	    feq_gen_io_d__312.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__312);
	    do_fio(&feq_gen_c_d_1, (char *)&wrcom_1.icdout[feq_gen_i_d_ - 1], (ftnlen)sizeof(
		    integer));
	    e_wsfe();
/* SOURCE output.for:2216 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE output.for:2218 */
/*<     2 continue >*/
L2:
/*           NEW FORM OF OUTPUT. */
/* SOURCE output.for:2220 */
/*<       if(braout(i).gt.0)then >*/
	    if (wrcom_1.braout[feq_gen_i_d_ - 1] > 0) {
/* SOURCE output.for:2221 */
/*<       val=y2(nodout(i))+zvec(nodout(i)) >*/
		val = static_cast<double>(bnelem_1.y2[wrcom_1.nodout[feq_gen_i_d_ - 1] - 1]) + 
			bnelem_1.zvec[wrcom_1.nodout[feq_gen_i_d_ - 1] - 1];
/* SOURCE output.for:2222 */
/*<       else >*/
	    } else {
/* SOURCE output.for:2223 */
/*<       val=ye2(nodout(i))+ze(nodout(i)) >*/
		val = static_cast<double>(enelem_1.ye2[wrcom_1.nodout[feq_gen_i_d_ - 1] - 1]) + enelem_1.ze[
			wrcom_1.nodout[feq_gen_i_d_ - 1] - 1];
/* SOURCE output.for:2224 */
/*<       endif >*/
	    }
/*           Apply shift for datum change on output */
/* SOURCE output.for:2226 */
/*<       val=val+dz_for_output >*/
	    val += *feq_gen_dz_for_output_d_;
/* SOURCE output.for:2227 */
/*<       goto1000 >*/
	    goto L1000;
/* SOURCE output.for:2229 */
/*<     3 continue >*/
L3:
/* SOURCE output.for:2230 */
/*<       write(stdout,50)icdout(i) >*/
	    feq_gen_io_d__314.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__314);
	    do_fio(&feq_gen_c_d_1, (char *)&wrcom_1.icdout[feq_gen_i_d_ - 1], (ftnlen)sizeof(
		    integer));
	    e_wsfe();
/* SOURCE output.for:2231 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE output.for:2233 */
/*<     4 continue >*/
L4:
/*           OUTPUT A POINT VALUED FLOW IN THE NEW FORM */
/* SOURCE output.for:2235 */
/*<       if(braout(i).gt.0)then >*/
	    if (wrcom_1.braout[feq_gen_i_d_ - 1] > 0) {
/* SOURCE output.for:2236 */
/*<       val=q2(nodout(i)) >*/
		val = bnelem_1.q2[wrcom_1.nodout[feq_gen_i_d_ - 1] - 1];
/* SOURCE output.for:2237 */
/*<       else >*/
	    } else {
/* SOURCE output.for:2238 */
/*<       val=qe2(nodout(i)) >*/
		val = enelem_1.qe2[wrcom_1.nodout[feq_gen_i_d_ - 1] - 1];
/* SOURCE output.for:2239 */
/*<       endif >*/
	    }
/* SOURCE output.for:2240 */
/*<       if(abs(val).le.qchop)val=0.0 >*/
	    if (dabs(val) <= *qchop) {
		val = (float)0.;
	    }
/* SOURCE output.for:2241 */
/*<       goto1000 >*/
	    goto L1000;
/* SOURCE output.for:2243 */
/*<  1000 continue >*/
L1000:
/* SOURCE output.for:2244 */
/*<       endif >*/
	    ;
	}
/* SOURCE output.for:2245 */
/*<       if(unout(i).lt.1000)then >*/
	if (wrcom_1.unout[feq_gen_i_d_ - 1] < 1000) {
/* SOURCE output.for:2246 */
/*<       if(actout(i).eq.add.or.actout(i).eq.outa)then >*/
	    if (wrcom_1.actout[feq_gen_i_d_ - 1] == 3 || wrcom_1.actout[feq_gen_i_d_ - 1] == 1) 
		    {
/* SOURCE output.for:2247 */
/*<       if(is_sum_good.eq.no)then >*/
		if (feq_gen_is_sum_good_d_ == 6) {
/*             Initialize SUM */
/* SOURCE output.for:2249 */
/*<       sum=dble(val) >*/
		    sum = (doublereal) val;
/* SOURCE output.for:2250 */
/*<       is_sum_good=yes >*/
		    feq_gen_is_sum_good_d_ = 5;
/* SOURCE output.for:2251 */
/*<       else >*/
		} else {
/* SOURCE output.for:2252 */
/*<       sum=sum+dble(val) >*/
		    sum += (doublereal) val;
/* SOURCE output.for:2253 */
/*<       endif >*/
		}
/* SOURCE output.for:2254 */
/*<       elseif(actout(i).eq.sub.or.actout(i).eq.outs)then >*/
	    } else if (wrcom_1.actout[feq_gen_i_d_ - 1] == 4 || wrcom_1.actout[feq_gen_i_d_ - 1]
		     == 2) {
/* SOURCE output.for:2255 */
/*<       if(is_sum_good.eq.no)then >*/
		if (feq_gen_is_sum_good_d_ == 6) {
/*             Initialize SUM */
/* SOURCE output.for:2257 */
/*<       sum=-dble(val) >*/
		    sum = -((doublereal) val);
/* SOURCE output.for:2258 */
/*<       is_sum_good=yes >*/
		    feq_gen_is_sum_good_d_ = 5;
/* SOURCE output.for:2259 */
/*<       else >*/
		} else {
/* SOURCE output.for:2260 */
/*<       sum=sum-dble(val) >*/
		    sum -= (doublereal) val;
/* SOURCE output.for:2261 */
/*<       endif >*/
		}
/* SOURCE output.for:2262 */
/*<       endif >*/
	    }
/* SOURCE output.for:2263 */
/*<       if(actout(i).eq.outa.or.actout(i).eq.outs)then >*/
	    if (wrcom_1.actout[feq_gen_i_d_ - 1] == 1 || wrcom_1.actout[feq_gen_i_d_ - 1] == 2) 
		    {
/* SOURCE output.for:2264 */
/*<       val=sngl(sum) >*/
		val = (real) sum;
/* SOURCE output.for:2265 */
/*<       write(unout(i),rec=wr_rec(i))jtime,val >*/
		feq_gen_io_d__316.ciunit = wrcom_1.unout[feq_gen_i_d_ - 1];
		feq_gen_io_d__316.cirec = wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
		s_wdue(&feq_gen_io_d__316);
		do_uio(&feq_gen_c_d_1, (char *)&(*jtime), (ftnlen)sizeof(doublereal));
		do_uio(&feq_gen_c_d_1, (char *)&val, (ftnlen)sizeof(real));
		e_wdue();
/*            write(stdout,*) 'jtime=',jtime,' wr_rec(i)=',wr_rec(i) */
/* SOURCE output.for:2268 */
/*<       wr_rec(i)=wr_rec(i)+1 >*/
		++wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
/*            WRITE(STDOUT,*) 'OUT ', NAMOUT(I) */
/*            WRITE(STDOUT,*) ' VAL=',VAL */
/* SOURCE output.for:2271 */
/*<       is_sum_good=no >*/
		feq_gen_is_sum_good_d_ = 6;
/* SOURCE output.for:2272 */
/*<       elseif(actout(i).eq.quad)then >*/
	    } else if (wrcom_1.actout[feq_gen_i_d_ - 1] == 7) {
/* SOURCE output.for:2273 */
/*<       runquad(i)=runquad(i)+0.5d0*dt*(oldf(i)+sum) >*/
		wrcomd_1.runquad[feq_gen_i_d_ - 1] += *dt * .5 * (wrcomd_1.oldf[feq_gen_i_d_ - 
			1] + sum);
/* SOURCE output.for:2274 */
/*<       oldf(i)=sum >*/
		wrcomd_1.oldf[feq_gen_i_d_ - 1] = sum;
/* SOURCE output.for:2275 */
/*<       val=sngl(runquad(i)*quadfactor) >*/
		val = (real) (wrcomd_1.runquad[feq_gen_i_d_ - 1] * wrcomd_1.quadfactor)
			;
/* SOURCE output.for:2276 */
/*<       write(unout(i),rec=wr_rec(i))jtime,val >*/
		feq_gen_io_d__317.ciunit = wrcom_1.unout[feq_gen_i_d_ - 1];
		feq_gen_io_d__317.cirec = wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
		s_wdue(&feq_gen_io_d__317);
		do_uio(&feq_gen_c_d_1, (char *)&(*jtime), (ftnlen)sizeof(doublereal));
		do_uio(&feq_gen_c_d_1, (char *)&val, (ftnlen)sizeof(real));
		e_wdue();
/* SOURCE output.for:2277 */
/*<       wr_rec(i)=wr_rec(i)+1 >*/
		++wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
/*            WRITE(STDOUT,*) 'QUAD ', NAMOUT(I) */
/*            WRITE(STDOUT,*) ' SUM=',SUM,' RUNQUAD(I)=',RUNQUAD(I) */
/* SOURCE output.for:2280 */
/*<       is_sum_good=no >*/
		feq_gen_is_sum_good_d_ = 6;
/* SOURCE output.for:2281 */
/*<       endif >*/
	    }
/* SOURCE output.for:2282 */
/*<       else >*/
	} else {
/* SOURCE output.for:2283 */
/*<       callupdate_dssout_buffer(dss_buffer_column(i),val) >*/
	    feq_gen_update_dssout_buffer_d_(&wrcom_1.feq_gen_dss_buffer_column_d_[feq_gen_i_d_ - 1], &
		    val);
/* SOURCE output.for:2284 */
/*<       endif >*/
	}
/* SOURCE output.for:2285 */
/*<   500 continue >*/
/* L500: */
    }
/* SOURCE output.for:2286 */
/*<       if(full.eq.1)then >*/
    if (full == 1) {
/*       The DSS output buffer is full.  It must be written and */
/*       reset. */
/* SOURCE output.for:2289 */
/*<       calloutput_dssout_buffer >*/
	feq_gen_output_dssout_buffer_d_();
/* SOURCE output.for:2290 */
/*<       endif >*/
    }
/* SOURCE output.for:2291 */
/*<       return >*/
    return 0;
/* SOURCE output.for:2292 */
/*<       end >*/
} /* wrout_ */




/* SOURCE output.for:2296 */
/*<       subroutinespo_close(stdout) >*/
/* Subroutine */ int feq_gen_spo_close_d_(integer *stdout)
{
    /* Format strings */
    static char fmt_50[] = "(\002spoknt=\002,i10)";

    /* System generated locals */
    cllist feq_gen_cl_d_1;

    /* Builtin functions */
    integer f_clos(cllist *), s_wsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_wsfe();

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__318 = { 0, 0, 0, fmt_50, 0 };


/*     Write final data and close any open special-output related files */
/* SOURCE output.for:2300 */
/*<       implicitnone >*/
/* SOURCE output.for:2302 */
/*<       integerstdout >*/
/*     Common blocks */
/* INCLUDE output.for:2306 */
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
/* INCLUDE output.for:2307 */
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
/*     *************************formats********************************** */
/* SOURCE output.for:2309 */
/*<    50 format('spoknt=',i10) >*/
/* *********************************************************************** */
/* SOURCE output.for:2312 */
/*<       if(stdspout.gt.0)then >*/
/* L50: */
    if (spouta_1.stdspout > 0) {
/* SOURCE output.for:2313 */
/*<       close(stdspout) >*/
	feq_gen_cl_d_1.cerr = 0;
	feq_gen_cl_d_1.cunit = spouta_1.stdspout;
	feq_gen_cl_d_1.csta = 0;
	f_clos(&feq_gen_cl_d_1);
/*       write the final record_knt to the describe file */
/* SOURCE output.for:2316 */
/*<       write(stdspo,50)spo_knt >*/
	feq_gen_io_d__318.ciunit = spouta_1.stdspo;
	s_wsfe(&feq_gen_io_d__318);
	do_fio(&feq_gen_c_d_1, (char *)&spouta_1.feq_gen_spo_knt_d_, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE output.for:2317 */
/*<       close(stdspo) >*/
	feq_gen_cl_d_1.cerr = 0;
	feq_gen_cl_d_1.cunit = spouta_1.stdspo;
	feq_gen_cl_d_1.csta = 0;
	f_clos(&feq_gen_cl_d_1);
/* SOURCE output.for:2318 */
/*<       endif >*/
    }
/* SOURCE output.for:2319 */
/*<       return >*/
    return 0;
/* SOURCE output.for:2320 */
/*<       end >*/
} /* spo_close__ */




/* SOURCE output.for:2325 */
/*<       subroutinewrquit(stdout,jtime) >*/
/* Subroutine */ int wrquit_(integer *stdout, doublereal *jtime)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;

    /* Builtin functions */
    integer s_wdue(cilist *), do_uio(integer *, char *, ftnlen), e_wdue(), 
	    s_rdue(cilist *), e_rdue();

    /* Local variables */
    integer feq_gen_i_d_;
    extern /* Subroutine */ int feq_gen_free_unit_d_(integer *, integer *);
    doublereal jt;
    real val1, value;
    extern /* Subroutine */ int feq_gen_output_dssout_buffer_d_();
    doublereal jttemp;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__322 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__323 = { 0, 0, 0, 0, 29 };
    static cilist feq_gen_io_d__324 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__327 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Write the terminating record and close output files. */
/* SOURCE output.for:2330 */
/*<       implicitnone >*/
/* SOURCE output.for:2331 */
/*<       integerstdout >*/
/* SOURCE output.for:2332 */
/*<       real*8jtime >*/
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE output.for:2335 */
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
/* INCLUDE output.for:2336 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE output.for:2339 */
/*<       integeri >*/
/* SOURCE output.for:2340 */
/*<       realval1,value >*/
/* SOURCE output.for:2341 */
/*<       real*8jt,jttemp >*/
/*     External names */
/* SOURCE output.for:2345 */
/*<       externalfree_unit >*/
/* *********************************************************************** */
/* SOURCE output.for:2347 */
/*<       val1=0.0 >*/
    val1 = (float)0.;
/* SOURCE output.for:2348 */
/*<       jt=0.d0 >*/
    jt = 0.;
/* SOURCE output.for:2349 */
/*<       do500i=1,nfout >*/
    feq_gen_i_d_1 = wrcom_1.nfout;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE output.for:2350 */
/*<       if(unout(i).lt.1000.and.unout(i).gt.0)then >*/
	if (wrcom_1.unout[feq_gen_i_d_ - 1] < 1000 && wrcom_1.unout[feq_gen_i_d_ - 1] > 0) {
/* SOURCE output.for:2351 */
/*<       write(unout(i),rec=wr_rec(i))jt,val1 >*/
	    feq_gen_io_d__322.ciunit = wrcom_1.unout[feq_gen_i_d_ - 1];
	    feq_gen_io_d__322.cirec = wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1];
	    s_wdue(&feq_gen_io_d__322);
	    do_uio(&feq_gen_c_d_1, (char *)&jt, (ftnlen)sizeof(doublereal));
	    do_uio(&feq_gen_c_d_1, (char *)&val1, (ftnlen)sizeof(real));
	    e_wdue();
/*         write the record number of the last ts point, */
/*         which is wr_rec(i) - 1 with jtime to the */
/*         DPTSF_REC_AT_FRST_TS_PNT - 1 record. */
/* SOURCE output.for:2355 */
/*<       write(unout(i),rec=dptsf_rec_at_frst_ts_pnt-1)jtime,wr_rec(i)-1 >*/
	    feq_gen_io_d__323.ciunit = wrcom_1.unout[feq_gen_i_d_ - 1];
	    s_wdue(&feq_gen_io_d__323);
	    do_uio(&feq_gen_c_d_1, (char *)&(*jtime), (ftnlen)sizeof(doublereal));
	    feq_gen_i_d_2 = wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1] - 1;
	    do_uio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_2, (ftnlen)sizeof(integer));
	    e_wdue();
/*         There is a subtle problem with noise in jtime.  The value */
/*         jtime here has been set to match the ending time exactly. */
/*         This will sometimes disagree by about 5 x e-9 day or a fraction */
/*         of a millisecond.  However, that can sometimes cause annoying */
/*         run failures because some datam point does not go far enough in */
/*         time.  Therefore, we want the jtime in hand here and recorded */
/*         as the end time, to match the time at the last record written. */
/*         The jtime here is consistent with the ending time which is often */
/*         an integral day value.  The jtime used when the last time-series */
/*         point was written may not be the same.  Therefore we will */
/*         read the last record to get the flow value, then re-write the */
/*         record with the value of jtime we have here.  This should */
/*         stop any problems that may arise from minute differences between */
/*         the two values of jtime. */
/* SOURCE output.for:2373 */
/*<       read(unout(i),rec=wr_rec(i)-1)jttemp,value >*/
	    feq_gen_io_d__324.ciunit = wrcom_1.unout[feq_gen_i_d_ - 1];
	    feq_gen_io_d__324.cirec = wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1] - 1;
	    s_rdue(&feq_gen_io_d__324);
	    do_uio(&feq_gen_c_d_1, (char *)&jttemp, (ftnlen)sizeof(doublereal));
	    do_uio(&feq_gen_c_d_1, (char *)&value, (ftnlen)sizeof(real));
	    e_rdue();
/* SOURCE output.for:2374 */
/*<       write(unout(i),rec=wr_rec(i)-1)jtime,value >*/
	    feq_gen_io_d__327.ciunit = wrcom_1.unout[feq_gen_i_d_ - 1];
	    feq_gen_io_d__327.cirec = wrcom_1.feq_gen_wr_rec_d_[feq_gen_i_d_ - 1] - 1;
	    s_wdue(&feq_gen_io_d__327);
	    do_uio(&feq_gen_c_d_1, (char *)&(*jtime), (ftnlen)sizeof(doublereal));
	    do_uio(&feq_gen_c_d_1, (char *)&value, (ftnlen)sizeof(real));
	    e_wdue();
/*          write(stdout,*) ' jttemp=',jttemp, ' value=', value */
/*          write(stdout,*) ' jtime=',jtime, ' wr_rec(i)-1=',wr_rec(i) -1 */
/* SOURCE output.for:2379 */
/*<       callfree_unit(stdout,unout(i)) >*/
	    feq_gen_free_unit_d_(stdout, &wrcom_1.unout[feq_gen_i_d_ - 1]);
/* SOURCE output.for:2380 */
/*<       endif >*/
	}
/* SOURCE output.for:2381 */
/*<   500 continue >*/
/* L500: */
    }
/* SOURCE output.for:2383 */
/*<       if(dss_out_count.gt.0)then >*/
    if (wrcom_1.feq_gen_dss_out_count_d_ > 0) {
/* SOURCE output.for:2384 */
/*<       calloutput_dssout_buffer >*/
	feq_gen_output_dssout_buffer_d_();
/* SOURCE output.for:2385 */
/*<       endif >*/
    }
/* SOURCE output.for:2387 */
/*<       return >*/
    return 0;
/* SOURCE output.for:2388 */
/*<       end >*/
} /* wrquit_ */




/* SOURCE output.for:2392 */
/*<        >*/
/* Subroutine */ int zsumry_(integer *stdout, integer *nbra, char *nodeid, 
	real *sfac, integer *feq_storage_emc, integer *feq_storage_brpt, integer *feq_storage_exnodt, integer *
	nex, real *hslot, real *vunit, real *qchop, real *feq_gen_dz_for_output_d_, 
	ftnlen nodeid_len)
{
    /* Initialized data */

    static integer null = -2147483647;
    static real lim[11] = { (float)-100.,(float)-1.,(float)-.5,(float)-.25,(
	    float)-.1,(float)0.,(float).1,(float).25,(float).5,(float)1.,(
	    float)100. };

    /* Format strings */
    static char fmt_2000[] = "(/,\002 SUMMARY OF EXTREME ELEVATIONS AND FL\
OWS\002)";
    static char fmt_2020[] = "(/,\002 BRANCH NUMBER  =\002,i5)";
    static char fmt_2021[] = "(/,\002 BRANCH NUMBER =\002,i5,\002 PONDING VO\
LUME=\002,f10.1,a6)";
    static char fmt_2032[] = "(\002   Node  Node_Identifier   Station  Mx De\
pth   Mx Elev  Mx Vel\002,8x,\002Qmax\002,8x,\002Qmin\002,\002 Time of max Z\
 Time of max Q\002,\002 Time of min Q    GIS Id String\002)";
    static char fmt_2050[] = "(/,\002  FREE NODES\002)";
    static char fmt_2052[] = "(/,\002  LEVEL-POOL RESERVOIR NODES\002)";
    static char fmt_2056[] = "(\002   Node  Node Identifier  Mx Depth   Mx E\
lev\002,\002   Storage Surf Area\002)";
    static char fmt_2058[] = "(2x,a5,1x,a16,2f10.4,2(1pe10.3))";
    static char fmt_2062[] = "(\002   Node  Node_Identifier  Mx Depth   Mx E\
lev Botm Elev\002,8x,\002Qmax\002,8x,\002Qmin\002,\002 Time of max Z Time of\
 max Q\002,\002 Time of min Q   Station    SrcElv  QCrstElv UpsNd DnsNd\002)";
    static char fmt_2072[] = "(2x,a5,1x,a16,3f10.4,2(1pe12.4),3a14,a10,a)";
    static char fmt_2074[] = "(\002 \002)";
    static char fmt_2075[] = "(1x,a)";
    static char fmt_2076[] = "(\002 *WRN:39* Depth at node:\002,i5,\002:\002\
,i7,\002 overtops \002,\002 TabId=\002,a,\002 by\002,f10.4)";
    static char fmt_2078[] = "(/,\002 Extremes achieved at \002,i5,\002/\002\
,i3,\002/\002,i3,\002/\002,f7.3)";
    static char fmt_2080[] = "(/,\002 High-Water Mark Summary\002,/,1x,\002H\
igh-Water Mark Location                \002,\002  Bran    Node Elevation  Si\
m Elev      Diff\002)";
    static char fmt_2082[] = "(1x,a40,i6,a8,f10.3,f10.3,f10.3)";
    static char fmt_2084[] = "(/,\002*ERR:413* Node number=\002,a8,\002 on b\
ranch number=\002,i5,\002 is out of range.\002)";
    static char fmt_2086[] = "(/,\002 Difference-distribution summary\002,/\
,\002 Difference range        Count  Proportion\002)";
    static char fmt_2088[] = "(f7.2,\002 < Diff <=\002,f6.2,i6,f12.2)";
    static char fmt_2090[] = "(/,\002 Analysis of \002,i5,\002 high-water ma\
rks completed.\002)";
    static char fmt_18000[] = "(1x,i6,1x,a16,f10.0,f10.3,f10.3,f8.3,2(1pe12.\
4),3a14,1x,a16,0pf8.1)";
    static char fmt_18100[] = "(1x,i6,1x,a16,f10.1,f10.3,f10.3,f8.3,2(1pe12.\
4),3a14,1x,a16,0pf8.1)";
    static char fmt_18200[] = "(1x,i6,1x,a16,f10.2,f10.3,f10.3,f8.3,2(1pe12.\
4),3a14,1x,a16,0pf8.1)";
    static char fmt_18300[] = "(1x,i6,1x,a16,f10.3,f10.3,f10.3,f8.3,2(1pe12.\
4),3a14,1x,a16,0pf8.1)";
    static char fmt_18400[] = "(1x,i6,1x,a16,f10.4,f10.3,f10.3,f8.3,2(1pe12.\
4),3a14,1x,a16,0pf8.1)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3;
    char feq_gen_ch_d_1[14], feq_gen_ch_d_2[16];
    icilist feq_gen_ici_d_1;
    olist feq_gen_o_d_1;
    inlist feq_gen_ioin_d_1;

    /* Builtin functions */
    double r_lg10(real *);
    integer i_nint(real *), s_wsfe(cilist *), e_wsfe(), do_fio(integer *, 
	    char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(), s_wsfi(icilist *), e_wsfi(), s_cmp(char *, char *, 
	    ftnlen, ftnlen), f_inqu(inlist *), f_open(olist *), s_rsfi(
	    icilist *), e_rsfi();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern integer feq_gen_get_unit_d_(integer *);
    doublereal dstation;
    integer feq_gen_i_d_;
    real x;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *), 
	    feq_gen_get_gisid_d_(char *, ftnlen, integer *);
    real elevation;
    char feq_gen_qnode_sum_d_[32];
    integer fa, id, la, nb, ii, fn;
    doublereal hr;
    integer it;
    real xl, zl, xr, zr;
    extern /* Subroutine */ int feq_gen_clear_home_d_();
    char feq_gen_hwmark_loc_d_[40];
    integer nad;
    real pdv;
    integer knt;
    real zdn, vol, zup, zmx;
    extern /* Subroutine */ int feq_gen_tdtchk_free_d_(integer *, integer *, integer *,
	     real *, integer *), feq_gen_maybe_add_ghome_out_d_(char *, ftnlen);
    real feq_gen_source_elev_d_;
    char out1[14], out2[14], out3[14], out4[10];
    real efac;
    integer feq_gen_feql_select1_d_, feq_gen_feql_select2_d_;
    real diff;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
    extern /* Subroutine */ int fnd14_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, real *, real *);
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer bran, ntab, node;
    char line[80];
    integer dexn;
    real ymax;
    integer uexn, slot[11];
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    char work[256];
    real zhwm;
    char char8[8], work8[8];
    integer eflag;
    char tabid[16];
    integer feq_gen_bran_node_pnt_d_;
    logical there;
    real feq_gen_aunit_d_;
    char gisid[16];
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    integer feq_gen_usr_bran_node_d_;
    extern /* Subroutine */ int feq_gen_os_file_style_d_(char *, ftnlen);
    integer addflg, lprflg, stdhwm, usbran;
    real qputmn, qputmx, offset, hdatum;
    char usnode[5];
    extern integer lenstr_(char *, ftnlen);
    extern /* Character */ VOID jttoct_(char *, ftnlen, doublereal *);
    extern /* Subroutine */ int tdtchk_(integer *, integer *, integer *, 
	    integer *), inline_(integer *, integer *, char *, ftnlen), 
	    feq_gen_strip_l_blanks_d_(char *, ftnlen), getinb_(integer *, integer *, 
	    integer *), getinn_(char *, integer *, integer *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__334 = { 0, 0, 0, fmt_2000, 0 };
    static cilist feq_gen_io_d__335 = { 0, 0, 0, fmt_2074, 0 };
    static cilist feq_gen_io_d__337 = { 0, 0, 0, fmt_2075, 0 };
    static cilist feq_gen_io_d__339 = { 0, 0, 0, fmt_2078, 0 };
    static cilist feq_gen_io_d__344 = { 0, 0, 0, fmt_2020, 0 };
    static cilist feq_gen_io_d__345 = { 0, 0, 0, fmt_2021, 0 };
    static cilist feq_gen_io_d__346 = { 0, 0, 0, fmt_2021, 0 };
    static cilist feq_gen_io_d__347 = { 0, 0, 0, fmt_2032, 0 };
    static cilist feq_gen_io_d__360 = { 0, 0, 0, fmt_18000, 0 };
    static cilist feq_gen_io_d__361 = { 0, 0, 0, fmt_18100, 0 };
    static cilist feq_gen_io_d__362 = { 0, 0, 0, fmt_18200, 0 };
    static cilist feq_gen_io_d__363 = { 0, 0, 0, fmt_18300, 0 };
    static cilist feq_gen_io_d__364 = { 0, 0, 0, fmt_18400, 0 };
    static cilist feq_gen_io_d__367 = { 0, 0, 0, fmt_18000, 0 };
    static cilist feq_gen_io_d__368 = { 0, 0, 0, fmt_18100, 0 };
    static cilist feq_gen_io_d__369 = { 0, 0, 0, fmt_18200, 0 };
    static cilist feq_gen_io_d__370 = { 0, 0, 0, fmt_18300, 0 };
    static cilist feq_gen_io_d__371 = { 0, 0, 0, fmt_18400, 0 };
    static cilist feq_gen_io_d__372 = { 0, 0, 0, fmt_2050, 0 };
    static cilist feq_gen_io_d__374 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__375 = { 0, 0, 0, fmt_2062, 0 };
    static cilist feq_gen_io_d__387 = { 0, 0, 0, fmt_2072, 0 };
    static cilist feq_gen_io_d__388 = { 0, 0, 0, fmt_2072, 0 };
    static cilist feq_gen_io_d__391 = { 0, 0, 0, fmt_2052, 0 };
    static cilist feq_gen_io_d__392 = { 0, 0, 0, fmt_2056, 0 };
    static cilist feq_gen_io_d__396 = { 0, 0, 0, fmt_2058, 0 };
    static cilist feq_gen_io_d__399 = { 0, 0, 0, fmt_2076, 0 };
    static cilist feq_gen_io_d__404 = { 0, 0, 0, fmt_2080, 0 };
    static cilist feq_gen_io_d__418 = { 0, 0, 0, fmt_2084, 0 };
    static cilist feq_gen_io_d__424 = { 0, 0, 0, fmt_2082, 0 };
    static cilist feq_gen_io_d__425 = { 0, 0, 0, fmt_2086, 0 };
    static cilist feq_gen_io_d__426 = { 0, 0, 0, fmt_2088, 0 };
    static cilist feq_gen_io_d__427 = { 0, 0, 0, fmt_2090, 0 };
    static cilist feq_gen_io_d__428 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__429 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Output a summary of maximum elevations and extreme flows. */
/* SOURCE output.for:2400 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE output.for:2402 */
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
/* SOURCE output.for:2405 */
/*<       integerstdout,nbra,nex >*/
/* SOURCE output.for:2406 */
/*<       integerbrpt(8,nbra),emc(mremc),exnodt(9,nex) >*/
/* SOURCE output.for:2407 */
/*<       realhslot,qchop,sfac,vunit,dz_for_output >*/
/* SOURCE output.for:2408 */
/*<       characternodeid*4 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     NBRA   - number of branches in the model */
/*     NODEID - user node identification string */
/*     SFAC   - conversion factor from user stations to internal stations */
/*     EMC    - vector containing coded form of the Matrix Control Input */
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
/*     NEX    - number of exterior nodes in the model */
/*     HSLOT  - height of bottom slot.  Currently 0.0 always */
/*     VUNIT  - conversion factor for volumes on output */
/*     QCHOP  - chopping value for output of flow */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE output.for:2446 */
/*     Miscellaneous control parameters */
/* SOURCE misccon.cmn:3 */
/*<       integerpagesp,pndflg >*/
/* SOURCE misccon.cmn:5 */
/*<        >*/
/* SOURCE misccon.cmn:8 */
/*<        >*/
/* INCLUDE output.for:2447 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE output.for:2448 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE output.for:2449 */
/* ********************************************************************** */
/* SOURCE bnrslt.cmn:2 */
/*<       common/bnrslt/tqmax,tqmin,tzmax,qmax,qmin,zmax,vmax >*/
/* SOURCE bnrslt.cmn:5 */
/*<       realqmax(mnbn),qmin(mnbn),zmax(mnbn),vmax(mnbn) >*/
/* SOURCE bnrslt.cmn:7 */
/*<       doubleprecisiontqmax(mnbn),tqmin(mnbn),tzmax(mnbn) >*/
/* ********************************************************************** */
/* INCLUDE output.for:2450 */
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
/* INCLUDE output.for:2451 */
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
/* INCLUDE output.for:2452 */
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
/* INCLUDE output.for:2453 */
/* ********************************************************************** */
/* SOURCE bnpond.cmn:3 */
/*<       common/bnpond/coefin,pond1,pond2,ycut,bpond,bpmax >*/
/* SOURCE bnpond.cmn:5 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE output.for:2454 */
/*     NAMES FOR VARIOUS OPTIONAL FILES AND SPECIAL OUTPUT FILE */
/*     HEADINGS */
/* SOURCE namcom.cmn:5 */
/*<       character*7sphead(mnsout,2) >*/
/* SOURCE namcom.cmn:7 */
/*<       character*256bwfnam,fffnam,tsfnam,putnam,getnam >*/
/* SOURCE namcom.cmn:9 */
/*<       common/namcom/bwfnam,fffnam,tsfnam,sphead,putnam,getnam >*/
/* INCLUDE output.for:2455 */
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
/* INCLUDE output.for:2456 */
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

/* INCLUDE output.for:2457 */
/*     Common blocks for handling the expanded title for output labeling */
/* SOURCE title.cmn:3 */
/*<       integertitle_n,max_title_n >*/
/* SOURCE title.cmn:4 */
/*<       parameter(max_title_n=201) >*/
/* SOURCE title.cmn:7 */
/*<       character*120title(max_title_n) >*/
/* SOURCE title.cmn:10 */
/*<       common/titlec/title >*/
/* SOURCE title.cmn:11 */
/*<       common/titlei/title_n >*/
/* SOURCE title.cmn:13 */
/*<       save/titlec/,/titlei/ >*/
/* INCLUDE output.for:2458 */
/* ********************************************************************** */
/* SOURCE julian.cmn:3 */
/*<        >*/
/* SOURCE julian.cmn:8 */
/*<       integeryr,mn,dy,syr,smn,sdy,eyr,emn,edy,reset,leap,dmyear,dmmn >*/
/* SOURCE julian.cmn:10 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE output.for:2459 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE output.for:2462 */
/*<        >*/
/* SOURCE output.for:2465 */
/*<       logicalthere >*/
/* SOURCE output.for:2466 */
/*<        >*/
/* SOURCE output.for:2470 */
/*<       real*8hr,dstation >*/
/* SOURCE output.for:2471 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE output.for:2476 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE output.for:2479 */
/*<       integerlenstr,get_unit >*/
/* SOURCE output.for:2480 */
/*<       characterjttoct*14,get_gisid*16,get_tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE output.for:2483 */
/*<        >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE output.for:2392 */
/*<       integer feql_select1 >*/
/* SOURCE output.for:2392 */
/*<       integer feql_select2 >*/
/* SOURCE output.for:2486 */
/*<       datanull/-2147483647/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    /* Function Body */
/* SOURCE output.for:2487 */
/*<       datalim/-100.,-1.0,-0.5,-0.25,-0.1,0.0,0.1,0.25,0.5,1.0,100./ >*/
/* SOURCE output.for:2489 */
/*<  2000 format(/,' SUMMARY OF EXTREME ELEVATIONS AND FLOWS') >*/
/* L2000: */
/* SOURCE output.for:2490 */
/*<  2020 format(/,' BRANCH NUMBER  =',i5) >*/
/* L2020: */
/* SOURCE output.for:2491 */
/*<  2021 format(/,' BRANCH NUMBER =',i5,' PONDING VOLUME=',f10.1,a6) >*/
/* L2021: */
/* SOURCE output.for:2492 */
/*<  2032  >*/
/* L2032: */
/* SOURCE output.for:2496 */
/*<  2040 format(1x,i5,f10.3,3f10.3,2(1pe12.4),3a14,1x,a16) >*/
/* L2040: */
/* SOURCE output.for:2497 */
/*<  2050 format(/,'  FREE NODES') >*/
/* L2050: */
/* SOURCE output.for:2498 */
/*<  2052 format(/,'  LEVEL-POOL RESERVOIR NODES') >*/
/* L2052: */
/* SOURCE output.for:2499 */
/*<  2054 format('  NODE MAX DEPTH  MAX ELEV   STORAGE SURF AREA') >*/
/* L2054: */
/* SOURCE output.for:2500 */
/*<  2056  >*/
/* L2056: */
/* 2057 FORMAT(1X,1X,A5,2F10.4,2(1PE10.3)) */
/* SOURCE output.for:2503 */
/*<  2058 format(2x,a5,1x,a16,2f10.4,2(1pe10.3)) >*/
/* L2058: */
/* SOURCE output.for:2504 */
/*<  2062  >*/
/* L2062: */
/* 2070 FORMAT(1X,1X,A5,3F10.4,2(1PE12.4),3A14) */
/* SOURCE output.for:2508 */
/*<  2072 format(2x,a5,1x,a16,3f10.4,2(1pe12.4),3a14,a10,a) >*/
/* L2072: */
/* SOURCE output.for:2509 */
/*<  2074 format(' ') >*/
/* L2074: */
/* SOURCE output.for:2510 */
/*<  2075 format(1x,a) >*/
/* L2075: */
/* SOURCE output.for:2511 */
/*<  2076  >*/
/* L2076: */
/* SOURCE output.for:2513 */
/*<  2078 format(/,' Extremes achieved at ',i5,'/',i3,'/',i3,'/',f7.3) >*/
/* L2078: */
/* SOURCE output.for:2514 */
/*<  2080  >*/
/* L2080: */
/* SOURCE output.for:2517 */
/*<  2082 format(1x,a40,i6,a8,f10.3,f10.3,f10.3) >*/
/* L2082: */
/* SOURCE output.for:2518 */
/*<  2084  >*/
/* L2084: */
/* SOURCE output.for:2520 */
/*<  2086  >*/
/* L2086: */
/* SOURCE output.for:2522 */
/*<  2088 format(f7.2,' < Diff <=',f6.2,i6,f12.2) >*/
/* L2088: */
/* SOURCE output.for:2523 */
/*<  2090 format(/,' Analysis of ',i5,' high-water marks completed.') >*/
/* L2090: */
/* SOURCE output.for:2525 */
/*< 18000  >*/
/* L18000: */
/* SOURCE output.for:2527 */
/*< 18100  >*/
/* L18100: */
/* SOURCE output.for:2529 */
/*< 18200  >*/
/* L18200: */
/* SOURCE output.for:2531 */
/*< 18300  >*/
/* L18300: */
/* SOURCE output.for:2533 */
/*< 18400  >*/
/* L18400: */
/* ********************************************************************** */
/*     Define the index for the case selection of format for output */
/* SOURCE output.for:2537 */
/*<       id=nint(log10(sfac)) >*/
    feq_gen_r_d_1 = r_lg10(sfac);
    id = i_nint(&feq_gen_r_d_1);
/* SOURCE output.for:2540 */
/*<       write(stdout,2000) >*/
    feq_gen_io_d__334.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__334);
    e_wsfe();
/* SOURCE output.for:2541 */
/*<       write(stdout,2074) >*/
    feq_gen_io_d__335.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__335);
    e_wsfe();
/* SOURCE output.for:2542 */
/*<       do90i=1,title_n >*/
    feq_gen_i_d_1 = titlei_1.feq_gen_title_n_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE output.for:2543 */
/*<       write(stdout,2075)title(i)(1:lenstr(title(i))) >*/
	feq_gen_io_d__337.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__337);
	do_fio(&feq_gen_c_d_1, titlec_1.title + (feq_gen_i_d_ - 1) * 120, lenstr_(
		titlec_1.title + (feq_gen_i_d_ - 1) * 120, (ftnlen)120));
	e_wsfe();
/* SOURCE output.for:2544 */
/*<    90 continue >*/
/* L90: */
    }
/* SOURCE output.for:2546 */
/*<       hr=24.*dyfrac >*/
    hr = julian_1.dyfrac * (float)24.;
/* SOURCE output.for:2547 */
/*<       write(stdout,2078)yr,mn,dy,hr >*/
    feq_gen_io_d__339.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__339);
    do_fio(&feq_gen_c_d_1, (char *)&julian_1.yr, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&julian_1.mn, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&julian_1.dy, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&hr, (ftnlen)sizeof(doublereal));
    e_wsfe();
/*     BRANCH LOOP */
/* SOURCE output.for:2551 */
/*<       do100nb=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (nb = 1; nb <= feq_gen_i_d_1; ++nb) {
/* SOURCE output.for:2552 */
/*<       fn=brpt(1,nb)-1 >*/
	fn = brpt[(nb << 3) + 1] - 1;
/* SOURCE output.for:2553 */
/*<       fa=brpt(3,nb) >*/
	fa = brpt[(nb << 3) + 3];
/* SOURCE output.for:2554 */
/*<       la=brpt(4,nb) >*/
	la = brpt[(nb << 3) + 4];
/* SOURCE output.for:2555 */
/*<       if(pndflg.eq.0)then >*/
	if (miscon_1.pndflg == 0) {
/* SOURCE output.for:2556 */
/*<       write(stdout,2020)inbrus(nb) >*/
	    feq_gen_io_d__344.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__344);
	    do_fio(&feq_gen_c_d_1, (char *)&inbr_1.inbrus[nb - 1], (ftnlen)sizeof(
		    integer));
	    e_wsfe();
/* SOURCE output.for:2557 */
/*<       else >*/
	} else {
/* SOURCE output.for:2558 */
/*<       if(vunit.gt.20000.0)then >*/
	    if (*vunit > (float)2e4) {
/* SOURCE output.for:2559 */
/*<       write(stdout,2021)inbrus(nb),bpmax(nb)/vunit,' AC-FT' >*/
		feq_gen_io_d__345.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__345);
		do_fio(&feq_gen_c_d_1, (char *)&inbr_1.inbrus[nb - 1], (ftnlen)sizeof(
			integer));
		feq_gen_r_d_1 = static_cast<double>(bnpond_1.bpmax[nb - 1]) / *vunit;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, const_cast<char*>(" AC-FT"), (ftnlen)6);
		e_wsfe();
/* SOURCE output.for:2560 */
/*<       else >*/
	    } else {
/* SOURCE output.for:2561 */
/*<       write(stdout,2021)inbrus(nb),bpmax(nb)/vunit,' K M^3' >*/
		feq_gen_io_d__346.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__346);
		do_fio(&feq_gen_c_d_1, (char *)&inbr_1.inbrus[nb - 1], (ftnlen)sizeof(
			integer));
		feq_gen_r_d_1 = static_cast<double>(bnpond_1.bpmax[nb - 1]) / *vunit;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, const_cast<char*>(" K M^3"), (ftnlen)6);
		e_wsfe();
/* SOURCE output.for:2562 */
/*<       endif >*/
	    }
/* SOURCE output.for:2563 */
/*<       endif >*/
	}
/* SOURCE output.for:2565 */
/*<       write(stdout,2032) >*/
	feq_gen_io_d__347.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__347);
	e_wsfe();
/* SOURCE output.for:2567 */
/*<       if(addvec(nb).lt.0)then >*/
	if (bnothr_1.addvec[nb - 1] < 0) {
/*         SUPPRESS OUTPUT OF ADDED NODES */
/* SOURCE output.for:2569 */
/*<       addflg=abs(addvec(nb)) >*/
	    addflg = (feq_gen_i_d_2 = bnothr_1.addvec[nb - 1], abs(feq_gen_i_d_2));
/* SOURCE output.for:2570 */
/*<       else >*/
	} else {
/* SOURCE output.for:2571 */
/*<       addflg=0 >*/
	    addflg = 0;
/* SOURCE output.for:2572 */
/*<       endif >*/
	}
/*       ALWAYS OUTPUT THE FIRST NODE */
/* SOURCE output.for:2575 */
/*<       nad=fa >*/
	nad = fa;
/* SOURCE output.for:2576 */
/*<       fn=fn+1 >*/
	++fn;
/* SOURCE output.for:2577 */
/*<       x=xvec(nad)/sfac >*/
	x = static_cast<double>(bnelem_1.xvec[nad - 1]) / *sfac;
/* SOURCE output.for:2578 */
/*<       ymax=zmax(nad)-zvec(nad)+sdvec(nad) >*/
	ymax = static_cast<double>(static_cast<double>(bnrslt_1.zmax[nad - 1]) - bnelem_1.zvec[nad - 1]) + 
		bnelem_1.sdvec[nad - 1];
/* SOURCE output.for:2580 */
/*<       out1=jttoct(tzmax(nad)) >*/
	jttoct_(feq_gen_ch_d_1, (ftnlen)14, &bnrslt_1.tzmax[nad - 1]);
	s_copy(out1, feq_gen_ch_d_1, (ftnlen)14, (ftnlen)14);
/* SOURCE output.for:2581 */
/*<       out2=jttoct(tqmax(nad)) >*/
	jttoct_(feq_gen_ch_d_1, (ftnlen)14, &bnrslt_1.tqmax[nad - 1]);
	s_copy(out2, feq_gen_ch_d_1, (ftnlen)14, (ftnlen)14);
/* SOURCE output.for:2582 */
/*<       out3=jttoct(tqmin(nad)) >*/
	jttoct_(feq_gen_ch_d_1, (ftnlen)14, &bnrslt_1.tqmin[nad - 1]);
	s_copy(out3, feq_gen_ch_d_1, (ftnlen)14, (ftnlen)14);
/* SOURCE output.for:2583 */
/*<       gisid=get_gisid(nsec(nad)) >*/
	feq_gen_get_gisid_d_(feq_gen_ch_d_2, (ftnlen)16, &bnothr_1.nsec[nad - 1]);
	s_copy(gisid, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
/* SOURCE output.for:2584 */
/*<       qputmx=qmax(nad) >*/
	qputmx = bnrslt_1.qmax[nad - 1];
/* SOURCE output.for:2585 */
/*<       if(abs(qputmx).le.qchop)then >*/
	if (dabs(qputmx) <= *qchop) {
/* SOURCE output.for:2586 */
/*<       qputmx=0.0 >*/
	    qputmx = (float)0.;
/* SOURCE output.for:2587 */
/*<       endif >*/
	}
/* SOURCE output.for:2588 */
/*<       qputmn=qmin(nad) >*/
	qputmn = bnrslt_1.qmin[nad - 1];
/* SOURCE output.for:2589 */
/*<       if(abs(qputmn).le.qchop)then >*/
	if (dabs(qputmn) <= *qchop) {
/* SOURCE output.for:2590 */
/*<       qputmn=0.0 >*/
	    qputmn = (float)0.;
/* SOURCE output.for:2591 */
/*<       endif >*/
	}
/*       Compute an approx to maximum shear stress */
/*        CALL XLKT20 */
/*     I        (NSEC(NAD), */
/*     M         YMAX, */
/*     O         ADUM, TDUM, DTDUM, KATMAX, DCDUM, BDUM, DBDUM) */
/*        TAUMAX = 62.4*YMAX*(QPUTMX/KATMAX)**2 */
/*       Make the datum shift for output */
/* SOURCE output.for:2602 */
/*<       zmx=zmax(nad)+dz_for_output >*/
	zmx = static_cast<double>(bnrslt_1.zmax[nad - 1]) + *feq_gen_dz_for_output_d_;
/* SOURCE output.for:2603 */
/*<       feql_select1=id >*/
	feq_gen_feql_select1_d_ = id;
/* SOURCE output.for:2603 */
/*<       if(feql_select1.eq.0)then >*/
	if (feq_gen_feql_select1_d_ == 0) {
/* SOURCE output.for:2605 */
/*<        >*/
	    feq_gen_io_d__360.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__360);
	    do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&zmx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&bnrslt_1.vmax[nad - 1], (ftnlen)sizeof(
		    real));
	    do_fio(&feq_gen_c_d_1, (char *)&qputmx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&qputmn, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, out1, (ftnlen)14);
	    do_fio(&feq_gen_c_d_1, out2, (ftnlen)14);
	    do_fio(&feq_gen_c_d_1, out3, (ftnlen)14);
	    do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
	    e_wsfe();
/* SOURCE output.for:2603 */
/*<       elseif(feql_select1.eq.1)then >*/
	} else if (feq_gen_feql_select1_d_ == 1) {
/* SOURCE output.for:2608 */
/*<        >*/
	    feq_gen_io_d__361.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__361);
	    do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&zmx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&bnrslt_1.vmax[nad - 1], (ftnlen)sizeof(
		    real));
	    do_fio(&feq_gen_c_d_1, (char *)&qputmx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&qputmn, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, out1, (ftnlen)14);
	    do_fio(&feq_gen_c_d_1, out2, (ftnlen)14);
	    do_fio(&feq_gen_c_d_1, out3, (ftnlen)14);
	    do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
	    e_wsfe();
/* SOURCE output.for:2603 */
/*<       elseif(feql_select1.eq.2)then >*/
	} else if (feq_gen_feql_select1_d_ == 2) {
/* SOURCE output.for:2611 */
/*<        >*/
	    feq_gen_io_d__362.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__362);
	    do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&zmx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&bnrslt_1.vmax[nad - 1], (ftnlen)sizeof(
		    real));
	    do_fio(&feq_gen_c_d_1, (char *)&qputmx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&qputmn, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, out1, (ftnlen)14);
	    do_fio(&feq_gen_c_d_1, out2, (ftnlen)14);
	    do_fio(&feq_gen_c_d_1, out3, (ftnlen)14);
	    do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
	    e_wsfe();
/* SOURCE output.for:2603 */
/*<       elseif(feql_select1.eq.3)then >*/
	} else if (feq_gen_feql_select1_d_ == 3) {
/* SOURCE output.for:2614 */
/*<        >*/
	    feq_gen_io_d__363.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__363);
	    do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&zmx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&bnrslt_1.vmax[nad - 1], (ftnlen)sizeof(
		    real));
	    do_fio(&feq_gen_c_d_1, (char *)&qputmx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&qputmn, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, out1, (ftnlen)14);
	    do_fio(&feq_gen_c_d_1, out2, (ftnlen)14);
	    do_fio(&feq_gen_c_d_1, out3, (ftnlen)14);
	    do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
	    e_wsfe();
/* SOURCE output.for:2603 */
/*<       else >*/
	} else {
/* SOURCE output.for:2617 */
/*<        >*/
	    feq_gen_io_d__364.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__364);
	    do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&zmx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&bnrslt_1.vmax[nad - 1], (ftnlen)sizeof(
		    real));
	    do_fio(&feq_gen_c_d_1, (char *)&qputmx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&qputmn, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, out1, (ftnlen)14);
	    do_fio(&feq_gen_c_d_1, out2, (ftnlen)14);
	    do_fio(&feq_gen_c_d_1, out3, (ftnlen)14);
	    do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
	    e_wsfe();
/* SOURCE output.for:2619 */
/*<       endif >*/
	}
/* SOURCE output.for:2622 */
/*<       knt=addflg >*/
	knt = addflg;
/*       II) NODE LOOP */
/* SOURCE output.for:2626 */
/*<       do50nad=fa+1,la >*/
	feq_gen_i_d_2 = la;
	for (nad = fa + 1; nad <= feq_gen_i_d_2; ++nad) {
/* SOURCE output.for:2627 */
/*<       if(hltab(nad).eq.0.and.knt.gt.0)then >*/
	    if (bnothr_1.hltab[nad - 1] == 0 && knt > 0) {
/*           SKIP NODES */
/* SOURCE output.for:2629 */
/*<       knt=knt-1 >*/
		--knt;
/* SOURCE output.for:2630 */
/*<       else >*/
	    } else {
/*           RESET KNT */
/* SOURCE output.for:2632 */
/*<       knt=addflg >*/
		knt = addflg;
/* SOURCE output.for:2633 */
/*<       fn=fn+1 >*/
		++fn;
/* SOURCE output.for:2634 */
/*<       x=xvec(nad)/sfac >*/
		x = static_cast<double>(bnelem_1.xvec[nad - 1]) / *sfac;
/* SOURCE output.for:2635 */
/*<       ymax=zmax(nad)-zvec(nad)+sdvec(nad) >*/
		ymax = static_cast<double>(static_cast<double>(bnrslt_1.zmax[nad - 1]) - bnelem_1.zvec[nad - 1]) + 
			bnelem_1.sdvec[nad - 1];
/* SOURCE output.for:2636 */
/*<       zmx=zmax(nad)+dz_for_output >*/
		zmx = static_cast<double>(bnrslt_1.zmax[nad - 1]) + *feq_gen_dz_for_output_d_;
/* SOURCE output.for:2638 */
/*<       out1=jttoct(tzmax(nad)) >*/
		jttoct_(feq_gen_ch_d_1, (ftnlen)14, &bnrslt_1.tzmax[nad - 1]);
		s_copy(out1, feq_gen_ch_d_1, (ftnlen)14, (ftnlen)14);
/* SOURCE output.for:2639 */
/*<       out2=jttoct(tqmax(nad)) >*/
		jttoct_(feq_gen_ch_d_1, (ftnlen)14, &bnrslt_1.tqmax[nad - 1]);
		s_copy(out2, feq_gen_ch_d_1, (ftnlen)14, (ftnlen)14);
/* SOURCE output.for:2640 */
/*<       out3=jttoct(tqmin(nad)) >*/
		jttoct_(feq_gen_ch_d_1, (ftnlen)14, &bnrslt_1.tqmin[nad - 1]);
		s_copy(out3, feq_gen_ch_d_1, (ftnlen)14, (ftnlen)14);
/* SOURCE output.for:2641 */
/*<       gisid=get_gisid(nsec(nad)) >*/
		feq_gen_get_gisid_d_(feq_gen_ch_d_2, (ftnlen)16, &bnothr_1.nsec[nad - 1]);
		s_copy(gisid, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
/* SOURCE output.for:2642 */
/*<       qputmx=qmax(nad) >*/
		qputmx = bnrslt_1.qmax[nad - 1];
/* SOURCE output.for:2643 */
/*<       if(abs(qputmx).le.qchop)then >*/
		if (dabs(qputmx) <= *qchop) {
/* SOURCE output.for:2644 */
/*<       qputmx=0.0 >*/
		    qputmx = (float)0.;
/* SOURCE output.for:2645 */
/*<       endif >*/
		}
/* SOURCE output.for:2646 */
/*<       qputmn=qmin(nad) >*/
		qputmn = bnrslt_1.qmin[nad - 1];
/* SOURCE output.for:2647 */
/*<       if(abs(qputmn).le.qchop)then >*/
		if (dabs(qputmn) <= *qchop) {
/* SOURCE output.for:2648 */
/*<       qputmn=0.0 >*/
		    qputmn = (float)0.;
/* SOURCE output.for:2649 */
/*<       endif >*/
		}
/*       Compute an approx to maximum shear stress */
/*        CALL XLKT20 */
/*     I        (NSEC(NAD), */
/*     M         YMAX, */
/*     O         ADUM, TDUM, DTDUM, KATMAX, DCDUM, BDUM, DBDUM) */
/*        TAUMAX = 62.4*YMAX*(QPUTMX/KATMAX)**2 */
/* SOURCE output.for:2657 */
/*<       feql_select2=id >*/
		feq_gen_feql_select2_d_ = id;
/* SOURCE output.for:2657 */
/*<       if(feql_select2.eq.0)then >*/
		if (feq_gen_feql_select2_d_ == 0) {
/* SOURCE output.for:2659 */
/*<        >*/
		    feq_gen_io_d__367.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__367);
		    do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)
			    16);
		    do_fio(&feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&zmx, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&bnrslt_1.vmax[nad - 1], (ftnlen)
			    sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&qputmx, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&qputmn, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, out1, (ftnlen)14);
		    do_fio(&feq_gen_c_d_1, out2, (ftnlen)14);
		    do_fio(&feq_gen_c_d_1, out3, (ftnlen)14);
		    do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
		    e_wsfe();
/* SOURCE output.for:2657 */
/*<       elseif(feql_select2.eq.1)then >*/
		} else if (feq_gen_feql_select2_d_ == 1) {
/* SOURCE output.for:2662 */
/*<        >*/
		    feq_gen_io_d__368.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__368);
		    do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)
			    16);
		    do_fio(&feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&zmx, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&bnrslt_1.vmax[nad - 1], (ftnlen)
			    sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&qputmx, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&qputmn, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, out1, (ftnlen)14);
		    do_fio(&feq_gen_c_d_1, out2, (ftnlen)14);
		    do_fio(&feq_gen_c_d_1, out3, (ftnlen)14);
		    do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
		    e_wsfe();
/* SOURCE output.for:2657 */
/*<       elseif(feql_select2.eq.2)then >*/
		} else if (feq_gen_feql_select2_d_ == 2) {
/* SOURCE output.for:2665 */
/*<        >*/
		    feq_gen_io_d__369.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__369);
		    do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)
			    16);
		    do_fio(&feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&zmx, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&bnrslt_1.vmax[nad - 1], (ftnlen)
			    sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&qputmx, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&qputmn, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, out1, (ftnlen)14);
		    do_fio(&feq_gen_c_d_1, out2, (ftnlen)14);
		    do_fio(&feq_gen_c_d_1, out3, (ftnlen)14);
		    do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
		    e_wsfe();
/* SOURCE output.for:2657 */
/*<       elseif(feql_select2.eq.3)then >*/
		} else if (feq_gen_feql_select2_d_ == 3) {
/* SOURCE output.for:2668 */
/*<        >*/
		    feq_gen_io_d__370.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__370);
		    do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)
			    16);
		    do_fio(&feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&zmx, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&bnrslt_1.vmax[nad - 1], (ftnlen)
			    sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&qputmx, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&qputmn, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, out1, (ftnlen)14);
		    do_fio(&feq_gen_c_d_1, out2, (ftnlen)14);
		    do_fio(&feq_gen_c_d_1, out3, (ftnlen)14);
		    do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
		    e_wsfe();
/* SOURCE output.for:2657 */
/*<       else >*/
		} else {
/* SOURCE output.for:2671 */
/*<        >*/
		    feq_gen_io_d__371.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__371);
		    do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)
			    16);
		    do_fio(&feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&zmx, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&bnrslt_1.vmax[nad - 1], (ftnlen)
			    sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&qputmx, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&qputmn, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, out1, (ftnlen)14);
		    do_fio(&feq_gen_c_d_1, out2, (ftnlen)14);
		    do_fio(&feq_gen_c_d_1, out3, (ftnlen)14);
		    do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
		    e_wsfe();
/* SOURCE output.for:2673 */
/*<       endif >*/
		}
/* SOURCE output.for:2674 */
/*<       endif >*/
	    }
/* SOURCE output.for:2675 */
/*<    50 continue >*/
/* L50: */
	}
/* SOURCE output.for:2676 */
/*<   100 continue >*/
/* L100: */
    }
/*     FREE NODES */
/* SOURCE output.for:2680 */
/*<       if(nex.gt.2*nbra)then >*/
    if (*nex > *nbra << 1) {
/* SOURCE output.for:2682 */
/*<       write(stdout,2050) >*/
	feq_gen_io_d__372.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__372);
	e_wsfe();
/* SOURCE output.for:2683 */
/*<       knt=0 >*/
	knt = 0;
/* SOURCE output.for:2684 */
/*<       do200ii=1,nex >*/
	feq_gen_i_d_1 = *nex;
	for (ii = 1; ii <= feq_gen_i_d_1; ++ii) {
/* SOURCE output.for:2685 */
/*<       i=usnsrt(ii) >*/
	    feq_gen_i_d_ = inen_1.usnsrt[ii - 1];
/* SOURCE output.for:2686 */
/*<       if(exnodt(3,i).le.0)then >*/
	    if (exnodt[feq_gen_i_d_ * 9 + 3] <= 0) {
/* SOURCE output.for:2687 */
/*<       if(exnodt(3,i).eq.0)then >*/
		if (exnodt[feq_gen_i_d_ * 9 + 3] == 0) {
/* SOURCE output.for:2688 */
/*<       ymax=fnzmax(i)-ze(i) >*/
		    ymax = static_cast<double>(enrslt_1.fnzmax[feq_gen_i_d_ - 1]) - enelem_1.ze[feq_gen_i_d_ - 1];
/* SOURCE output.for:2689 */
/*<       else >*/
		} else {
/* SOURCE output.for:2690 */
/*<       ymax=fnzmax(i)-ze(i) >*/
		    ymax = static_cast<double>(enrslt_1.fnzmax[feq_gen_i_d_ - 1]) - enelem_1.ze[feq_gen_i_d_ - 1];
/* SOURCE output.for:2691 */
/*<       endif >*/
		}
/* SOURCE output.for:2693 */
/*<       if(mod(knt,50).eq.0)then >*/
		if (knt % 50 == 0) {
/* SOURCE output.for:2694 */
/*<       write(stdout,*)' ' >*/
		    feq_gen_io_d__374.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__374);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
		    e_wsle();
/* SOURCE output.for:2695 */
/*<       write(stdout,2062) >*/
		    feq_gen_io_d__375.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__375);
		    e_wsfe();
/* SOURCE output.for:2696 */
/*<       endif >*/
		}
/* SOURCE output.for:2698 */
/*<       out1=jttoct(ftzmax(i)) >*/
		jttoct_(feq_gen_ch_d_1, (ftnlen)14, &enrslt_1.ftzmax[feq_gen_i_d_ - 1]);
		s_copy(out1, feq_gen_ch_d_1, (ftnlen)14, (ftnlen)14);
/* SOURCE output.for:2699 */
/*<       out2=jttoct(ftqmax(i)) >*/
		jttoct_(feq_gen_ch_d_1, (ftnlen)14, &enrslt_1.ftqmax[feq_gen_i_d_ - 1]);
		s_copy(out2, feq_gen_ch_d_1, (ftnlen)14, (ftnlen)14);
/* SOURCE output.for:2700 */
/*<       out3=jttoct(ftqmin(i)) >*/
		jttoct_(feq_gen_ch_d_1, (ftnlen)14, &enrslt_1.ftqmin[feq_gen_i_d_ - 1]);
		s_copy(out3, feq_gen_ch_d_1, (ftnlen)14, (ftnlen)14);
/*           Convert the node station, if any */
/* SOURCE output.for:2702 */
/*<       if(exnodt(8,i).ne.null)then >*/
		if (exnodt[feq_gen_i_d_ * 9 + 8] != null) {
/* SOURCE output.for:2703 */
/*<       dstation=dble(exnodt(8,i))/1.d4 >*/
		    dstation = (doublereal) exnodt[feq_gen_i_d_ * 9 + 8] / 1e4;
/* SOURCE output.for:2704 */
/*<       if(sfac.le.1.0)then >*/
		    if (*sfac <= (float)1.) {
/* SOURCE output.for:2705 */
/*<       write(out4,'(F10.0)')dstation >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 10;
			feq_gen_ici_d_1.iciunit = out4;
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.0)");
			s_wsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&dstation, (ftnlen)sizeof(
				doublereal));
			e_wsfi();
/* SOURCE output.for:2706 */
/*<       elseif(sfac.le.10.0)then >*/
		    } else if (*sfac <= (float)10.) {
/* SOURCE output.for:2707 */
/*<       write(out4,'(F10.1)')dstation >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 10;
			feq_gen_ici_d_1.iciunit = out4;
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.1)");
			s_wsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&dstation, (ftnlen)sizeof(
				doublereal));
			e_wsfi();
/* SOURCE output.for:2708 */
/*<       elseif(sfac.le.100.0)then >*/
		    } else if (*sfac <= (float)100.) {
/* SOURCE output.for:2709 */
/*<       write(out4,'(F10.2)')dstation >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 10;
			feq_gen_ici_d_1.iciunit = out4;
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.2)");
			s_wsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&dstation, (ftnlen)sizeof(
				doublereal));
			e_wsfi();
/* SOURCE output.for:2710 */
/*<       elseif(sfac.le.1000.0)then >*/
		    } else if (*sfac <= (float)1e3) {
/* SOURCE output.for:2711 */
/*<       write(out4,'(F10.3)')dstation >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 10;
			feq_gen_ici_d_1.iciunit = out4;
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.3)");
			s_wsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&dstation, (ftnlen)sizeof(
				doublereal));
			e_wsfi();
/* SOURCE output.for:2712 */
/*<       else >*/
		    } else {
/* SOURCE output.for:2713 */
/*<       write(out4,'(F10.4)')dstation >*/
			feq_gen_ici_d_1.icierr = 0;
			feq_gen_ici_d_1.icirnum = 1;
			feq_gen_ici_d_1.icirlen = 10;
			feq_gen_ici_d_1.iciunit = out4;
			feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.4)");
			s_wsfi(&feq_gen_ici_d_1);
			do_fio(&feq_gen_c_d_1, (char *)&dstation, (ftnlen)sizeof(
				doublereal));
			e_wsfi();
/* SOURCE output.for:2714 */
/*<       endif >*/
		    }
/* SOURCE output.for:2715 */
/*<       else >*/
		} else {
/* SOURCE output.for:2716 */
/*<       out4=' ' >*/
		    s_copy(out4, const_cast<char*>(" "), (ftnlen)10, (ftnlen)1);
/* SOURCE output.for:2717 */
/*<       endif >*/
		}
/* SOURCE output.for:2719 */
/*<       qputmx=fnqmax(i) >*/
		qputmx = enrslt_1.fnqmax[feq_gen_i_d_ - 1];
/* SOURCE output.for:2720 */
/*<       if(abs(qputmx).le.qchop)then >*/
		if (dabs(qputmx) <= *qchop) {
/* SOURCE output.for:2721 */
/*<       qputmx=0.0 >*/
		    qputmx = (float)0.;
/* SOURCE output.for:2722 */
/*<       endif >*/
		}
/* SOURCE output.for:2723 */
/*<       qputmn=fnqmin(i) >*/
		qputmn = enrslt_1.fnqmin[feq_gen_i_d_ - 1];
/* SOURCE output.for:2724 */
/*<       if(abs(qputmn).le.qchop)then >*/
		if (dabs(qputmn) <= *qchop) {
/* SOURCE output.for:2725 */
/*<       qputmn=0.0 >*/
		    qputmn = (float)0.;
/* SOURCE output.for:2726 */
/*<       endif >*/
		}
/*           Output additional information for flow nodes on side weirs.  We want */
/*           to add: */
/*           1. Elevation in the source channel that defines the flow.  We can only */
/*              approximate this here because it may not be true that the maximum elevations */
/*              available defined the maximum elevation used for outflow because the elevation */
/*              used for outflow is an average of the elevations at the ups and dns nodes. */
/*              Thus it is possible that we get slight differences.  Good enough for */
/*              calibration purposes-we hope! 4 Feb 2003. */
/*           2. The nodes upstream and downstream of the free node flow node. */
/*           3. The elevation of the head datum for flow at the flow node. */
/* SOURCE output.for:2742 */
/*<       callfnd14(stdout,i,emc,mremc,uexn,dexn,hdatum,efac) >*/
		fnd14_(stdout, &feq_gen_i_d_, &emc[1], &c_b958, &uexn, &dexn, &hdatum, 
			&efac);
/* SOURCE output.for:2745 */
/*<       if(uexn.gt.0)then >*/
		if (uexn > 0) {
/*             We have a flow node. Find the elevations */
/* SOURCE output.for:2747 */
/*<       it=exnodt(3,uexn) >*/
		    it = exnodt[uexn * 9 + 3];
/* SOURCE output.for:2748 */
/*<       if(it.le.0)then >*/
		    if (it <= 0) {
/* SOURCE output.for:2749 */
/*<       zup=fnzmax(uexn) >*/
			zup = enrslt_1.fnzmax[uexn - 1];
/* SOURCE output.for:2750 */
/*<       else >*/
		    } else {
/* SOURCE output.for:2751 */
/*<       it=exnodt(2,uexn) >*/
			it = exnodt[uexn * 9 + 2];
/* SOURCE output.for:2752 */
/*<       zup=zmax(it) >*/
			zup = bnrslt_1.zmax[it - 1];
/* SOURCE output.for:2753 */
/*<       endif >*/
		    }
/* SOURCE output.for:2754 */
/*<       it=exnodt(3,dexn) >*/
		    it = exnodt[dexn * 9 + 3];
/* SOURCE output.for:2755 */
/*<       if(it.le.0)then >*/
		    if (it <= 0) {
/* SOURCE output.for:2756 */
/*<       zdn=fnzmax(dexn) >*/
			zdn = enrslt_1.fnzmax[dexn - 1];
/* SOURCE output.for:2757 */
/*<       else >*/
		    } else {
/* SOURCE output.for:2758 */
/*<       it=exnodt(2,dexn) >*/
			it = exnodt[dexn * 9 + 2];
/* SOURCE output.for:2759 */
/*<       zdn=zmax(it) >*/
			zdn = bnrslt_1.zmax[it - 1];
/* SOURCE output.for:2760 */
/*<       endif >*/
		    }
/* SOURCE output.for:2762 */
/*<       source_elev=efac*zup+(1.0-efac)*zdn+dz_for_output >*/
		    feq_gen_source_elev_d_ = static_cast<double>(static_cast<double>(static_cast<double>(efac) * zup) + static_cast<double>((static_cast<double>((float)1.) - efac)) * zdn) + *
			    feq_gen_dz_for_output_d_;
/* SOURCE output.for:2763 */
/*<        >*/
		    feq_gen_ici_d_1.icierr = 0;
		    feq_gen_ici_d_1.icirnum = 1;
		    feq_gen_ici_d_1.icirlen = 32;
		    feq_gen_ici_d_1.iciunit = feq_gen_qnode_sum_d_;
		    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.4,F10.4,1X,A5,1X,A5)");
		    s_wsfi(&feq_gen_ici_d_1);
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_source_elev_d_, (ftnlen)sizeof(real)
			    );
		    do_fio(&feq_gen_c_d_1, (char *)&hdatum, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, inenc_1.inenus + (uexn - 1) * 5, (ftnlen)5);
		    do_fio(&feq_gen_c_d_1, inenc_1.inenus + (dexn - 1) * 5, (ftnlen)5);
		    e_wsfi();
/* SOURCE output.for:2766 */
/*<        >*/
		    feq_gen_io_d__387.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__387);
		    do_fio(&feq_gen_c_d_1, inenc_1.inenus + (feq_gen_i_d_ - 1) * 5, (ftnlen)5);
		    do_fio(&feq_gen_c_d_1, enothc_1.enodid + (feq_gen_i_d_ - 1 << 4), (ftnlen)
			    16);
		    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
		    feq_gen_r_d_1 = static_cast<double>(enrslt_1.fnzmax[feq_gen_i_d_ - 1]) + *feq_gen_dz_for_output_d_;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&enelem_1.ze[feq_gen_i_d_ - 1], (ftnlen)
			    sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&qputmx, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&qputmn, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, out1, (ftnlen)14);
		    do_fio(&feq_gen_c_d_1, out2, (ftnlen)14);
		    do_fio(&feq_gen_c_d_1, out3, (ftnlen)14);
		    do_fio(&feq_gen_c_d_1, out4, (ftnlen)10);
		    do_fio(&feq_gen_c_d_1, feq_gen_qnode_sum_d_, (ftnlen)32);
		    e_wsfe();
/* SOURCE output.for:2770 */
/*<       else >*/
		} else {
/* SOURCE output.for:2772 */
/*<        >*/
		    feq_gen_io_d__388.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__388);
		    do_fio(&feq_gen_c_d_1, inenc_1.inenus + (feq_gen_i_d_ - 1) * 5, (ftnlen)5);
		    do_fio(&feq_gen_c_d_1, enothc_1.enodid + (feq_gen_i_d_ - 1 << 4), (ftnlen)
			    16);
		    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
		    feq_gen_r_d_1 = static_cast<double>(enrslt_1.fnzmax[feq_gen_i_d_ - 1]) + *feq_gen_dz_for_output_d_;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&enelem_1.ze[feq_gen_i_d_ - 1], (ftnlen)
			    sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&qputmx, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&qputmn, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, out1, (ftnlen)14);
		    do_fio(&feq_gen_c_d_1, out2, (ftnlen)14);
		    do_fio(&feq_gen_c_d_1, out3, (ftnlen)14);
		    do_fio(&feq_gen_c_d_1, out4, (ftnlen)10);
		    e_wsfe();
/* SOURCE output.for:2775 */
/*<       endif >*/
		}
/* SOURCE output.for:2776 */
/*<       knt=knt+1 >*/
		++knt;
/* SOURCE output.for:2777 */
/*<       endif >*/
	    }
/* SOURCE output.for:2778 */
/*<   200 continue >*/
/* L200: */
	}
/*       SCAN EXNODT AND OUTPUT THE MAXIMUM STORAGES IF ANY LEVEL-POOL */
/*       RESERVOIRS FOUND.  MAKE A DOUBLE SCAN: THE FIRST DECIDES */
/*       IF AT LEAST ONE RESERVOIR IS PRESENT AND THE SECOND OUTPUTS */
/*       THE RESERVOIRS IF AT LEAST ONE IS PRESENT. */
/* SOURCE output.for:2785 */
/*<       lprflg=0 >*/
	lprflg = 0;
/* SOURCE output.for:2786 */
/*<       do253i=1,nex >*/
	feq_gen_i_d_1 = *nex;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE output.for:2787 */
/*<       if(exnodt(3,i).lt.0)then >*/
	    if (exnodt[feq_gen_i_d_ * 9 + 3] < 0) {
/* SOURCE output.for:2788 */
/*<       lprflg=1 >*/
		lprflg = 1;
/* SOURCE output.for:2789 */
/*<       goto254 >*/
		goto L254;
/* SOURCE output.for:2790 */
/*<       endif >*/
	    }
/* SOURCE output.for:2791 */
/*<   253 continue >*/
/* L253: */
	}
/* SOURCE output.for:2792 */
/*<   254 continue >*/
L254:
/* SOURCE output.for:2794 */
/*<       if(lprflg.eq.1)then >*/
	if (lprflg == 1) {
/* SOURCE output.for:2795 */
/*<       if(vunit.lt.20000.)then >*/
	    if (*vunit < (float)2e4) {
/* SOURCE output.for:2796 */
/*<       aunit=1.e6 >*/
		feq_gen_aunit_d_ = (float)1e6;
/* SOURCE output.for:2797 */
/*<       else >*/
	    } else {
/* SOURCE output.for:2798 */
/*<       aunit=43560. >*/
		feq_gen_aunit_d_ = (float)43560.;
/* SOURCE output.for:2799 */
/*<       endif >*/
	    }
/* SOURCE output.for:2800 */
/*<       write(stdout,2052) >*/
	    feq_gen_io_d__391.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__391);
	    e_wsfe();
/*          IF(NODEID.EQ.'NO') THEN */
/*            WRITE(STDOUT,2054) */
/*          ELSE */
/* SOURCE output.for:2804 */
/*<       write(stdout,2056) >*/
	    feq_gen_io_d__392.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__392);
	    e_wsfe();
/*          ENDIF */
/* SOURCE output.for:2807 */
/*<       do255ii=1,nex >*/
	    feq_gen_i_d_1 = *nex;
	    for (ii = 1; ii <= feq_gen_i_d_1; ++ii) {
/* SOURCE output.for:2808 */
/*<       i=usnsrt(ii) >*/
		feq_gen_i_d_ = inen_1.usnsrt[ii - 1];
/* SOURCE output.for:2809 */
/*<       if(exnodt(3,i).lt.0)then >*/
		if (exnodt[feq_gen_i_d_ * 9 + 3] < 0) {
/*             LEVEL-POOL RESERVOIR FOUND.  LOOK UP THE VOLUME. */
/* SOURCE output.for:2811 */
/*<       ymax=fnzmax(i)-ze(i) >*/
		    ymax = static_cast<double>(enrslt_1.fnzmax[feq_gen_i_d_ - 1]) - enelem_1.ze[feq_gen_i_d_ - 1];
/* SOURCE output.for:2812 */
/*<       calllktab(exnodt(4,i),ymax,0,vol,ntab,pdv) >*/
		    lktab_(&exnodt[feq_gen_i_d_ * 9 + 4], &ymax, &feq_gen_c_d_0, &vol, &ntab, &
			    pdv);
/* SOURCE output.for:2815 */
/*<        >*/
		    feq_gen_io_d__396.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__396);
		    do_fio(&feq_gen_c_d_1, inenc_1.inenus + (feq_gen_i_d_ - 1) * 5, (ftnlen)5);
		    do_fio(&feq_gen_c_d_1, enothc_1.enodid + (feq_gen_i_d_ - 1 << 4), (ftnlen)
			    16);
		    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
		    feq_gen_r_d_1 = static_cast<double>(enrslt_1.fnzmax[feq_gen_i_d_ - 1]) + *feq_gen_dz_for_output_d_;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		    feq_gen_r_d_2 = static_cast<double>(vol) / *vunit;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
		    feq_gen_r_d_3 = static_cast<double>(pdv) / feq_gen_aunit_d_;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_3, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE output.for:2817 */
/*<       endif >*/
		}
/* SOURCE output.for:2818 */
/*<   255 continue >*/
/* L255: */
	    }
/* SOURCE output.for:2819 */
/*<       endif >*/
	}
/* SOURCE output.for:2820 */
/*<       endif >*/
    }
/*     CHECK IF MAXIMA HAVE EXCEEDED THE PHYSICAL TOP OF ANY CROSS */
/*     SECTION */
/* SOURCE output.for:2825 */
/*<       do300nb=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (nb = 1; nb <= feq_gen_i_d_1; ++nb) {
/* SOURCE output.for:2826 */
/*<       fn=brpt(1,nb)-1 >*/
	fn = brpt[(nb << 3) + 1] - 1;
/* SOURCE output.for:2827 */
/*<       fa=brpt(3,nb) >*/
	fa = brpt[(nb << 3) + 3];
/* SOURCE output.for:2828 */
/*<       la=brpt(4,nb) >*/
	la = brpt[(nb << 3) + 4];
/* SOURCE output.for:2829 */
/*<       do250nad=fa,la >*/
	feq_gen_i_d_2 = la;
	for (nad = fa; nad <= feq_gen_i_d_2; ++nad) {
/* SOURCE output.for:2830 */
/*<       fn=fn+1 >*/
	    ++fn;
/* SOURCE output.for:2831 */
/*<       ymax=zmax(nad)-zvec(nad) >*/
	    ymax = static_cast<double>(bnrslt_1.zmax[nad - 1]) - bnelem_1.zvec[nad - 1];
/* SOURCE output.for:2832 */
/*<       diff=ymax-ftab(nsec(nad)+6) >*/
	    diff = static_cast<double>(ymax) - ftab[bnothr_1.nsec[nad - 1] + 6];
/* SOURCE output.for:2833 */
/*<       if(diff.gt.exttol)then >*/
	    if (diff > miscon_1.exttol) {
/* SOURCE output.for:2834 */
/*<       tabid=get_tabid(itab(nsec(nad)+1)) >*/
		feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(bnothr_1.nsec[nad - 1] + 
			1).data());
		s_copy(tabid, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
/* SOURCE output.for:2835 */
/*<       write(stdout,2076)inbrus(nb),fn,tabid(1:lenstr(tabid)),diff >*/
		feq_gen_io_d__399.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__399);
		do_fio(&feq_gen_c_d_1, (char *)&inbr_1.inbrus[nb - 1], (ftnlen)sizeof(
			integer));
		do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
		do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
		do_fio(&feq_gen_c_d_1, (char *)&diff, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE output.for:2837 */
/*<       endif >*/
	    }
/* SOURCE output.for:2838 */
/*<   250 continue >*/
/* L250: */
	}
/* SOURCE output.for:2839 */
/*<   300 continue >*/
/* L300: */
    }
/*     Check for two-D tables being overtopped */
/* SOURCE output.for:2842 */
/*<       calltdtchk(stdout,exnodt,nex,emc) >*/
    tdtchk_(stdout, &exnodt[10], nex, &emc[1]);
/*     Check for the state of two-D tables in Code 5 Type 6 */
/* SOURCE output.for:2846 */
/*<       calltdtchk_free(stdout,exnodt,nex,qchop,emc) >*/
    feq_gen_tdtchk_free_d_(stdout, &exnodt[10], nex, qchop, &emc[1]);
/*     Seek a hwmark.loc file and output comparisons if one is found */
/*     Attach the existing global home name to the file to define its */
/*     location. */
/* SOURCE output.for:2853 */
/*<       callclear_home() >*/
    feq_gen_clear_home_d_();
/* SOURCE output.for:2854 */
/*<       if(ghome_out.ne.' ')then >*/
    if (s_cmp(homec_1.feq_gen_ghome_out_d_, const_cast<char*>(" "), (ftnlen)128, (ftnlen)1) != 0) {
/*       A global home directory name exists. Seek the file there. */
/* SOURCE output.for:2856 */
/*<       work='/hwmark.loc' >*/
	s_copy(work, const_cast<char*>("/hwmark.loc"), (ftnlen)256, (ftnlen)11);
/* SOURCE output.for:2857 */
/*<       callmaybe_add_ghome_out(work) >*/
	feq_gen_maybe_add_ghome_out_d_(work, (ftnlen)256);
/* SOURCE output.for:2859 */
/*<       else >*/
    } else {
/*       No global home directory exists. Seek in current working directory */
/* SOURCE output.for:2861 */
/*<       work='hwmark.loc' >*/
	s_copy(work, const_cast<char*>("hwmark.loc"), (ftnlen)256, (ftnlen)10);
/* SOURCE output.for:2862 */
/*<       endif >*/
    }
/* SOURCE output.for:2864 */
/*<       callos_file_style(work) >*/
    feq_gen_os_file_style_d_(work, (ftnlen)256);
/* SOURCE output.for:2866 */
/*<       inquire(file=work,exist=there) >*/
    feq_gen_ioin_d_1.inerr = 0;
    feq_gen_ioin_d_1.infilen = 256;
    feq_gen_ioin_d_1.infile = work;
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
/* SOURCE output.for:2867 */
/*<       if(there)then >*/
    if (there) {
/* SOURCE output.for:2868 */
/*<       stdhwm=get_unit(stdout) >*/
	stdhwm = feq_gen_get_unit_d_(stdout);
/* SOURCE output.for:2869 */
/*<       open(stdhwm,file=work,status='OLD') >*/
	feq_gen_o_d_1.oerr = 0;
	feq_gen_o_d_1.ounit = stdhwm;
	feq_gen_o_d_1.ofnmlen = 256;
	feq_gen_o_d_1.ofnm = work;
	feq_gen_o_d_1.orl = 0;
	feq_gen_o_d_1.osta = const_cast<char*>("OLD");
	feq_gen_o_d_1.oacc = 0;
	feq_gen_o_d_1.ofm = 0;
	feq_gen_o_d_1.oblnk = 0;
	f_open(&feq_gen_o_d_1);
/*       Get the heading line. */
/* SOURCE output.for:2871 */
/*<       callinline(stdhwm,stdout,line) >*/
	inline_(&stdhwm, stdout, line, (ftnlen)80);
/*       Write new heading for the results. */
/* SOURCE output.for:2875 */
/*<       write(stdout,2080) >*/
	feq_gen_io_d__404.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__404);
	e_wsfe();
/*       Clear values for summary of differences */
/* SOURCE output.for:2878 */
/*<       knt=0 >*/
	knt = 0;
/* SOURCE output.for:2879 */
/*<       do395i=1,11 >*/
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 11; ++feq_gen_i_d_) {
/* SOURCE output.for:2880 */
/*<       slot(i)=0 >*/
	    slot[feq_gen_i_d_ - 1] = 0;
/* SOURCE output.for:2881 */
/*<   395 continue >*/
/* L395: */
	}
/*       Start reading lines from hwmark.loc */
/* SOURCE output.for:2884 */
/*<   400 continue >*/
L400:
/*       Read each line from hwmark.loc and process. */
/* SOURCE output.for:2887 */
/*<       callinline(stdhwm,stdout,line) >*/
	inline_(&stdhwm, stdout, line, (ftnlen)80);
/* SOURCE output.for:2890 */
/*<       if(line(1:3).ne.'END'.and.line(1:3).ne.'end')then >*/
	if (s_cmp(line, const_cast<char*>("END"), (ftnlen)3, (ftnlen)3) != 0 && s_cmp(line, 
		const_cast<char*>("end"), (ftnlen)3, (ftnlen)3) != 0) {
/*         We have a line to process. */
/* SOURCE output.for:2892 */
/*<        >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 80;
	    feq_gen_ici_d_1.iciunit = line;
	    feq_gen_ici_d_1.icifmt = const_cast<char*>("(A40,I6,A8,2F10.0)");
	    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_1 != 0) {
		goto L999;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, feq_gen_hwmark_loc_d_, (ftnlen)40);
	    if (feq_gen_i_d_1 != 0) {
		goto L999;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&usbran, (ftnlen)sizeof(integer));
	    if (feq_gen_i_d_1 != 0) {
		goto L999;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char8, (ftnlen)8);
	    if (feq_gen_i_d_1 != 0) {
		goto L999;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&offset, (ftnlen)sizeof(real));
	    if (feq_gen_i_d_1 != 0) {
		goto L999;
	    }
	    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&elevation, (ftnlen)sizeof(real));
	    if (feq_gen_i_d_1 != 0) {
		goto L999;
	    }
	    feq_gen_i_d_1 = e_rsfi();
	    if (feq_gen_i_d_1 != 0) {
		goto L999;
	    }
/*         Find the internal branch number */
/* SOURCE output.for:2896 */
/*<       callgetinb(usbran,eflag,bran) >*/
	    getinb_(&usbran, &eflag, &bran);
/* SOURCE output.for:2898 */
/*<       if(bran.eq.0)then >*/
	    if (bran == 0) {
/*           We have an exterior node reference.  OFFSET has no meaning. */
/*           Get the internal node number */
/* SOURCE output.for:2901 */
/*<       work8=char8 >*/
		s_copy(work8, char8, (ftnlen)8, (ftnlen)8);
/* SOURCE output.for:2902 */
/*<       callstrip_l_blanks(work8) >*/
		feq_gen_strip_l_blanks_d_(work8, (ftnlen)8);
/* SOURCE output.for:2904 */
/*<       usnode=work8 >*/
		s_copy(usnode, work8, (ftnlen)5, (ftnlen)8);
/* SOURCE output.for:2905 */
/*<       callgetinn(usnode,eflag,node) >*/
		getinn_(usnode, &eflag, &node, (ftnlen)5);
/* SOURCE output.for:2907 */
/*<       if(exnodt(3,node).le.0)then >*/
		if (exnodt[node * 9 + 3] <= 0) {
/*             Free node or LPR */
/* SOURCE output.for:2909 */
/*<       zhwm=fnzmax(node)+dz_for_output >*/
		    zhwm = static_cast<double>(enrslt_1.fnzmax[node - 1]) + *feq_gen_dz_for_output_d_;
/* SOURCE output.for:2910 */
/*<       else >*/
		} else {
/*             Node on a branch */
/* SOURCE output.for:2912 */
/*<       zhwm=zmax(exnodt(2,node))+dz_for_output >*/
		    zhwm = static_cast<double>(bnrslt_1.zmax[exnodt[node * 9 + 2] - 1]) + *
			    feq_gen_dz_for_output_d_;
/* SOURCE output.for:2913 */
/*<       endif >*/
		}
/* SOURCE output.for:2914 */
/*<       else >*/
	    } else {
/*           We have a location on a branch. Find the pointer into the */
/*           branch vectors. */
/* SOURCE output.for:2917 */
/*<       read(char8,'(I8)',err=999)usr_bran_node >*/
		feq_gen_ici_d_1.icierr = 1;
		feq_gen_ici_d_1.iciend = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 8;
		feq_gen_ici_d_1.iciunit = char8;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(I8)");
		feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
		if (feq_gen_i_d_1 != 0) {
		    goto L999;
		}
		feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&feq_gen_usr_bran_node_d_, (ftnlen)sizeof(
			integer));
		if (feq_gen_i_d_1 != 0) {
		    goto L999;
		}
		feq_gen_i_d_1 = e_rsfi();
		if (feq_gen_i_d_1 != 0) {
		    goto L999;
		}
/* SOURCE output.for:2918 */
/*<        >*/
		if (feq_gen_usr_bran_node_d_ < brpt[(bran << 3) + 1] || 
			feq_gen_usr_bran_node_d_ > brpt[(bran << 3) + 2]) {
/* SOURCE output.for:2920 */
/*<       write(stdout,2084)char8,usbran >*/
		    feq_gen_io_d__418.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__418);
		    do_fio(&feq_gen_c_d_1, char8, (ftnlen)8);
		    do_fio(&feq_gen_c_d_1, (char *)&usbran, (ftnlen)sizeof(integer));
		    e_wsfe();
/* SOURCE output.for:2921 */
/*<       stop'Abnormal stop. Error(s) found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Error(s) found."), (ftnlen)30);
/* SOURCE output.for:2922 */
/*<       endif >*/
		}
/* SOURCE output.for:2923 */
/*<       bran_node_pnt=usr_bran_node-brpt(1,bran)+brpt(3,bran) >*/
		feq_gen_bran_node_pnt_d_ = feq_gen_usr_bran_node_d_ - brpt[(bran << 3) + 1] + 
			brpt[(bran << 3) + 3];
/* SOURCE output.for:2924 */
/*<       if(offset.ge.0.0)then >*/
		if (offset >= (float)0.) {
/*             Mark is dns of the node. */
/* SOURCE output.for:2926 */
/*<       xl=xvec(bran_node_pnt) >*/
		    xl = bnelem_1.xvec[feq_gen_bran_node_pnt_d_ - 1];
/* SOURCE output.for:2927 */
/*<       zl=zmax(bran_node_pnt) >*/
		    zl = bnrslt_1.zmax[feq_gen_bran_node_pnt_d_ - 1];
/* SOURCE output.for:2928 */
/*<       xr=xvec(bran_node_pnt+1) >*/
		    xr = bnelem_1.xvec[feq_gen_bran_node_pnt_d_];
/* SOURCE output.for:2929 */
/*<       zr=zmax(bran_node_pnt+1) >*/
		    zr = bnrslt_1.zmax[feq_gen_bran_node_pnt_d_];
/* SOURCE output.for:2930 */
/*<       else >*/
		} else {
/* SOURCE output.for:2931 */
/*<       xl=xvec(bran_node_pnt) >*/
		    xl = bnelem_1.xvec[feq_gen_bran_node_pnt_d_ - 1];
/* SOURCE output.for:2932 */
/*<       zl=zmax(bran_node_pnt) >*/
		    zl = bnrslt_1.zmax[feq_gen_bran_node_pnt_d_ - 1];
/* SOURCE output.for:2933 */
/*<       xr=xvec(bran_node_pnt-1) >*/
		    xr = bnelem_1.xvec[feq_gen_bran_node_pnt_d_ - 2];
/* SOURCE output.for:2934 */
/*<       zr=zmax(bran_node_pnt-1) >*/
		    zr = bnrslt_1.zmax[feq_gen_bran_node_pnt_d_ - 2];
/* SOURCE output.for:2935 */
/*<       endif >*/
		}
/* SOURCE output.for:2936 */
/*<       zhwm=zl+abs(offset*sfac)*(zr-zl)/abs(xr-xl)+dz_for_output >*/
		zhwm = zl + (feq_gen_r_d_1 = static_cast<double>(offset) * *sfac, dabs(feq_gen_r_d_1)) * (static_cast<double>(zr) - zl) / 
			(feq_gen_r_d_2 = static_cast<double>(xr) - xl, dabs(feq_gen_r_d_2)) + *feq_gen_dz_for_output_d_;
/* SOURCE output.for:2938 */
/*<       endif >*/
	    }
/* SOURCE output.for:2939 */
/*<       diff=zhwm-elevation >*/
	    diff = static_cast<double>(zhwm) - elevation;
/* SOURCE output.for:2940 */
/*<       write(stdout,2082)hwmark_loc,usbran,char8,elevation,zhwm,diff >*/
	    feq_gen_io_d__424.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__424);
	    do_fio(&feq_gen_c_d_1, feq_gen_hwmark_loc_d_, (ftnlen)40);
	    do_fio(&feq_gen_c_d_1, (char *)&usbran, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, char8, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, (char *)&elevation, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&zhwm, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&diff, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE output.for:2942 */
/*<       knt=knt+1 >*/
	    ++knt;
/* SOURCE output.for:2943 */
/*<       do410i=2,11 >*/
	    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= 11; ++feq_gen_i_d_) {
/* SOURCE output.for:2944 */
/*<       if(diff.gt.lim(i-1).and.diff.le.lim(i))then >*/
		if (diff > lim[feq_gen_i_d_ - 2] && diff <= lim[feq_gen_i_d_ - 1]) {
/* SOURCE output.for:2945 */
/*<       slot(i)=slot(i)+1 >*/
		    ++slot[feq_gen_i_d_ - 1];
/* SOURCE output.for:2946 */
/*<       goto411 >*/
		    goto L411;
/* SOURCE output.for:2947 */
/*<       endif >*/
		}
/* SOURCE output.for:2948 */
/*<   410 continue >*/
/* L410: */
	    }
/* SOURCE output.for:2949 */
/*<   411 continue >*/
L411:
/* SOURCE output.for:2951 */
/*<       goto400 >*/
	    goto L400;
/* SOURCE output.for:2952 */
/*<       endif >*/
	}
/*       Output summary of differences. */
/* SOURCE output.for:2955 */
/*<       write(stdout,2086) >*/
	feq_gen_io_d__425.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__425);
	e_wsfe();
/* SOURCE output.for:2956 */
/*<       do420i=2,11 >*/
	for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= 11; ++feq_gen_i_d_) {
/* SOURCE output.for:2957 */
/*<        >*/
	    feq_gen_io_d__426.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__426);
	    do_fio(&feq_gen_c_d_1, (char *)&lim[feq_gen_i_d_ - 2], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&lim[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&slot[feq_gen_i_d_ - 1], (ftnlen)sizeof(integer));
	    feq_gen_r_d_1 = static_cast<double>((real) slot[feq_gen_i_d_ - 1]) / (real) knt;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE output.for:2959 */
/*<   420 continue >*/
/* L420: */
	}
/* SOURCE output.for:2961 */
/*<       write(stdout,2090)knt >*/
	feq_gen_io_d__427.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__427);
	do_fio(&feq_gen_c_d_1, (char *)&knt, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE output.for:2962 */
/*<       endif >*/
    }
/* SOURCE output.for:2964 */
/*<       return >*/
    return 0;
/* SOURCE output.for:2965 */
/*<   999 continue >*/
L999:
/* SOURCE output.for:2966 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__428.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__428);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE output.for:2967 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__429.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__429);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE output.for:2968 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE output.for:2970 */
/*<       end >*/
    return 0;
} /* zsumry_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE output.for:2974 */
/*<       character*16functionjttoct_old(jtime) >*/
/* Character */ VOID feq_gen_jttoct_old_d_(char *ret_val, ftnlen ret_val_len, 
	doublereal *jtime)
{
    /* Format strings */
    static char fmt_50[] = "(i3,\002/\002,i2,\002/\002,i2,\002:\002,f6.3)";

    /* System generated locals */
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi();

    /* Local variables */
    real hr;
    integer mn, dy, yr, mjd;
    doublereal frac;
    extern /* Subroutine */ int invmjd_(integer *, integer *, integer *, 
	    integer *);

/*     + + + PURPOSE + + + */
/*     Convert modified julian time to calendar time. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE output.for:2981 */
/*<       real*8jtime >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     JTIME  - current modified julian time in the model */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE output.for:2987 */
/*<       integerdy,mjd,mn,yr >*/
/* SOURCE output.for:2988 */
/*<       realhr >*/
/* SOURCE output.for:2989 */
/*<       real*8frac >*/
/*     + + + INTRINSICS + + + */
/* SOURCE output.for:2992 */
/*<       intrinsicdble,int >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE output.for:2995 */
/*<       externalinvmjd >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE output.for:2998 */
/*<    50 format(i3,'/',i2,'/',i2,':',f6.3) >*/
/* *********************************************************************** */
/* SOURCE output.for:3000 */
/*<       mjd=int(jtime) >*/
/* L50: */
    mjd = (integer) (*jtime);
/* SOURCE output.for:3001 */
/*<       frac=jtime-dble(mjd) >*/
    frac = *jtime - (doublereal) mjd;
/* SOURCE output.for:3002 */
/*<       callinvmjd(mjd,yr,mn,dy) >*/
    invmjd_(&mjd, &yr, &mn, &dy);
/* SOURCE output.for:3005 */
/*<       hr=sngl(24.d0*frac) >*/
    hr = (real) (frac * 24.);
/*      IF(YR.LT.2000) THEN */
/*        YR = YR - 1900 */
/*      ELSE */
/*        YR = YR - 2000 */
/*      ENDIF */
/* SOURCE output.for:3012 */
/*<       yr=mod(yr,100) >*/
    yr %= 100;
/* SOURCE output.for:3013 */
/*<       write(jttoct_old,50)yr,mn,dy,hr >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 16;
    feq_gen_ici_d_1.iciunit = ret_val;
    feq_gen_ici_d_1.icifmt = fmt_50;
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&yr, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&mn, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&dy, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&hr, (ftnlen)sizeof(real));
    e_wsfi();
/* SOURCE output.for:3014 */
/*<       return >*/
    return ;
/* SOURCE output.for:3015 */
/*<       end >*/
} /* jttoct_old__ */




/* SOURCE output.for:3019 */
/*<        >*/
/* Subroutine */ int feq_gen_zsumry_old_d_(integer *stdout, integer *nbra, char *
	nodeid, real *sfac, integer *feq_storage_emc, integer *feq_storage_brpt, integer *feq_storage_exnodt, 
	integer *nex, real *hslot, real *vunit, real *qchop, real *
	feq_gen_dz_for_output_d_, ftnlen nodeid_len)
{
    /* Format strings */
    static char fmt_2000[] = "(/,\002 SUMMARY OF EXTREME ELEVATIONS AND FL\
OWS\002)";
    static char fmt_2020[] = "(/,\002 BRANCH NUMBER  =\002,i5)";
    static char fmt_2021[] = "(/,\002 BRANCH NUMBER =\002,i5,\002 PONDING VO\
LUME=\002,f10.1,a6)";
    static char fmt_2032[] = "(\002  NODE   NODEID   STATION MAX DEPTH  MAX \
ELEV MAX VELOC\002,8x,\002QMAX\002,8x,\002QMIN\002,\002   TIME OF MAX Z   TI\
ME OF MAX Q\002,\002   TIME OF MIN Q    GIS Id String \002)";
    static char fmt_2050[] = "(/,\002  FREE NODES\002)";
    static char fmt_2052[] = "(/,\002  LEVEL-POOL RESERVOIR NODES\002)";
    static char fmt_2056[] = "(\002  NODE   NODEID MAX DEPTH  MAX ELEV   STO\
RAGE SURF AREA\002)";
    static char fmt_2058[] = "(1x,a5,1x,a8,2f10.4,2(1pe10.3))";
    static char fmt_2062[] = "(\002  NODE   NODEID MAX DEPTH  MAX ELEV BOTM \
ELEV\002,8x,\002QMAX\002,8x,\002QMIN\002,\002   TIME OF MAX Z   TIME OF MAX Q\
\002,\002   TIME OF MIN Q\002)";
    static char fmt_2072[] = "(1x,a5,1x,a8,3f10.4,2(1pe12.4),3a16)";
    static char fmt_2074[] = "(\002 \002)";
    static char fmt_2075[] = "(1x,a)";
    static char fmt_2076[] = "(\002 *WRN:39* Depth at node:\002,i5,\002:\002\
,i5,\002 overtops \002,\002 TabId=\002,a,\002 BY\002,f10.4)";
    static char fmt_18000[] = "(1x,i5,1x,a8,f10.0,f10.3,2f10.3,2(1pe12.4),3a\
16,1x,a16,0pf8.1)";
    static char fmt_18100[] = "(1x,i5,1x,a8,f10.1,f10.3,2f10.3,2(1pe12.4),3a\
16,1x,a16,0pf8.1)";
    static char fmt_18200[] = "(1x,i5,1x,a8,f10.2,f10.3,2f10.3,2(1pe12.4),3a\
16,1x,a16,0pf8.1)";
    static char fmt_18300[] = "(1x,i5,1x,a8,f10.3,f10.3,2f10.3,2(1pe12.4),3a\
16,1x,a16,0pf8.1)";
    static char fmt_18400[] = "(1x,i5,1x,a8,f10.4,f10.3,2f10.3,2(1pe12.4),3a\
16,1x,a16,0pf8.1)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];

    /* Builtin functions */
    double r_lg10(real *);
    integer i_nint(real *), s_wsfe(cilist *), e_wsfe(), do_fio(integer *, 
	    char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;
    real x;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *), 
	    feq_gen_get_gisid_d_(char *, ftnlen, integer *);
    integer fa, id, la, nb, ii, fn;
    extern /* Character */ VOID feq_gen_jttoct_old_d_(char *, ftnlen, doublereal *);
    integer nad;
    real pdv;
    integer knt;
    real vol, zmx;
    extern /* Subroutine */ int feq_gen_tdtchk_free_d_(integer *, integer *, integer *,
	     real *, integer *);
    char out1[16], out2[16], out3[16];
    integer feq_gen_feql_select3_d_;
    real diff;
    integer feq_gen_feql_select4_d_;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ntab;
    real ymax;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    char gisid[16];
    real feq_gen_aunit_d_;
    integer addflg, lprflg;
    real qputmn, qputmx;
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int tdtchk_(integer *, integer *, integer *, 
	    integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__440 = { 0, 0, 0, fmt_2000, 0 };
    static cilist feq_gen_io_d__441 = { 0, 0, 0, fmt_2074, 0 };
    static cilist feq_gen_io_d__443 = { 0, 0, 0, fmt_2075, 0 };
    static cilist feq_gen_io_d__448 = { 0, 0, 0, fmt_2020, 0 };
    static cilist feq_gen_io_d__449 = { 0, 0, 0, fmt_2021, 0 };
    static cilist feq_gen_io_d__450 = { 0, 0, 0, fmt_2021, 0 };
    static cilist feq_gen_io_d__451 = { 0, 0, 0, fmt_2032, 0 };
    static cilist feq_gen_io_d__464 = { 0, 0, 0, fmt_18000, 0 };
    static cilist feq_gen_io_d__465 = { 0, 0, 0, fmt_18100, 0 };
    static cilist feq_gen_io_d__466 = { 0, 0, 0, fmt_18200, 0 };
    static cilist feq_gen_io_d__467 = { 0, 0, 0, fmt_18300, 0 };
    static cilist feq_gen_io_d__468 = { 0, 0, 0, fmt_18400, 0 };
    static cilist feq_gen_io_d__471 = { 0, 0, 0, fmt_18000, 0 };
    static cilist feq_gen_io_d__472 = { 0, 0, 0, fmt_18100, 0 };
    static cilist feq_gen_io_d__473 = { 0, 0, 0, fmt_18200, 0 };
    static cilist feq_gen_io_d__474 = { 0, 0, 0, fmt_18300, 0 };
    static cilist feq_gen_io_d__475 = { 0, 0, 0, fmt_18400, 0 };
    static cilist feq_gen_io_d__476 = { 0, 0, 0, fmt_2050, 0 };
    static cilist feq_gen_io_d__477 = { 0, 0, 0, fmt_2062, 0 };
    static cilist feq_gen_io_d__479 = { 0, 0, 0, fmt_2072, 0 };
    static cilist feq_gen_io_d__482 = { 0, 0, 0, fmt_2052, 0 };
    static cilist feq_gen_io_d__483 = { 0, 0, 0, fmt_2056, 0 };
    static cilist feq_gen_io_d__487 = { 0, 0, 0, fmt_2058, 0 };
    static cilist feq_gen_io_d__489 = { 0, 0, 0, fmt_2076, 0 };


/*     + + + PURPOSE + + + */
/*     Output a summary of maximum elevations and extreme flows in */
/*     the pre-version 10 format. */
/* SOURCE output.for:3028 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE output.for:3030 */
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
/* SOURCE output.for:3033 */
/*<       integerstdout,nbra,nex >*/
/* SOURCE output.for:3034 */
/*<       integerbrpt(8,nbra),emc(mremc),exnodt(9,nex) >*/
/* SOURCE output.for:3035 */
/*<       realhslot,qchop,sfac,vunit,dz_for_output >*/
/* SOURCE output.for:3036 */
/*<       characternodeid*4 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     NBRA   - number of branches in the model */
/*     NODEID - user node identification string */
/*     SFAC   - conversion factor from user stations to internal stations */
/*     EMC    - vector containing coded form of the Matrix Control Input */
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
/*     NEX    - number of exterior nodes in the model */
/*     HSLOT  - height of bottom slot.  Currently 0.0 always */
/*     VUNIT  - conversion factor for volumes on output */
/*     QCHOP  - chopping value for output of flow */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE output.for:3074 */
/*     Miscellaneous control parameters */
/* SOURCE misccon.cmn:3 */
/*<       integerpagesp,pndflg >*/
/* SOURCE misccon.cmn:5 */
/*<        >*/
/* SOURCE misccon.cmn:8 */
/*<        >*/
/* INCLUDE output.for:3075 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE output.for:3076 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE output.for:3077 */
/* ********************************************************************** */
/* SOURCE bnrslt.cmn:2 */
/*<       common/bnrslt/tqmax,tqmin,tzmax,qmax,qmin,zmax,vmax >*/
/* SOURCE bnrslt.cmn:5 */
/*<       realqmax(mnbn),qmin(mnbn),zmax(mnbn),vmax(mnbn) >*/
/* SOURCE bnrslt.cmn:7 */
/*<       doubleprecisiontqmax(mnbn),tqmin(mnbn),tzmax(mnbn) >*/
/* ********************************************************************** */
/* INCLUDE output.for:3078 */
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
/* INCLUDE output.for:3079 */
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
/* INCLUDE output.for:3080 */
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
/* INCLUDE output.for:3081 */
/* ********************************************************************** */
/* SOURCE bnpond.cmn:3 */
/*<       common/bnpond/coefin,pond1,pond2,ycut,bpond,bpmax >*/
/* SOURCE bnpond.cmn:5 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE output.for:3082 */
/*     NAMES FOR VARIOUS OPTIONAL FILES AND SPECIAL OUTPUT FILE */
/*     HEADINGS */
/* SOURCE namcom.cmn:5 */
/*<       character*7sphead(mnsout,2) >*/
/* SOURCE namcom.cmn:7 */
/*<       character*256bwfnam,fffnam,tsfnam,putnam,getnam >*/
/* SOURCE namcom.cmn:9 */
/*<       common/namcom/bwfnam,fffnam,tsfnam,sphead,putnam,getnam >*/
/* INCLUDE output.for:3083 */
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
/* INCLUDE output.for:3084 */
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

/* INCLUDE output.for:3085 */
/*     Common blocks for handling the expanded title for output labeling */
/* SOURCE title.cmn:3 */
/*<       integertitle_n,max_title_n >*/
/* SOURCE title.cmn:4 */
/*<       parameter(max_title_n=201) >*/
/* SOURCE title.cmn:7 */
/*<       character*120title(max_title_n) >*/
/* SOURCE title.cmn:10 */
/*<       common/titlec/title >*/
/* SOURCE title.cmn:11 */
/*<       common/titlei/title_n >*/
/* SOURCE title.cmn:13 */
/*<       save/titlec/,/titlei/ >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE output.for:3088 */
/*<       integeraddflg,fa,fn,i,id,ii,knt,la,lprflg,nad,nb,ntab >*/
/* SOURCE output.for:3089 */
/*<        >*/
/* SOURCE output.for:3092 */
/*<       characterout1*16,out2*16,out3*16,gisid*16 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE output.for:3095 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE output.for:3098 */
/*<       integerlenstr >*/
/* SOURCE output.for:3099 */
/*<       characterjttoct_old*16,get_gisid*16,get_tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE output.for:3102 */
/*<       externaljttoct_old,lktab,tdtchk,get_gisid,get_tabid,lenstr >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE output.for:3019 */
/*<       integer feql_select3 >*/
/* SOURCE output.for:3019 */
/*<       integer feql_select4 >*/
/* SOURCE output.for:3105 */
/*<  2000 format(/,' SUMMARY OF EXTREME ELEVATIONS AND FLOWS') >*/
/* SOURCE output.for:3106 */
/*<  2020 format(/,' BRANCH NUMBER  =',i5) >*/
/* SOURCE output.for:3107 */
/*<  2021 format(/,' BRANCH NUMBER =',i5,' PONDING VOLUME=',f10.1,a6) >*/
/* SOURCE output.for:3108 */
/*<  2032  >*/
/* SOURCE output.for:3111 */
/*<  2040 format(1x,i5,f10.3,3f10.3,2(1pe12.4),3a16,1x,a16) >*/
/* SOURCE output.for:3112 */
/*<  2050 format(/,'  FREE NODES') >*/
/* SOURCE output.for:3113 */
/*<  2052 format(/,'  LEVEL-POOL RESERVOIR NODES') >*/
/* SOURCE output.for:3114 */
/*<  2054 format('  NODE MAX DEPTH  MAX ELEV   STORAGE SURF AREA') >*/
/* SOURCE output.for:3115 */
/*<  2056 format('  NODE   NODEID MAX DEPTH  MAX ELEV   STORAGE SURF AREA') >*/
/* SOURCE output.for:3116 */
/*<  2057 format(1x,1x,a4,2f10.4,2(1pe10.3)) >*/
/* SOURCE output.for:3117 */
/*<  2058 format(1x,a5,1x,a8,2f10.4,2(1pe10.3)) >*/
/* SOURCE output.for:3118 */
/*<  2062  >*/
/* SOURCE output.for:3121 */
/*<  2070 format(1x,1x,a4,3f10.4,2(1pe12.4),3a16) >*/
/* SOURCE output.for:3122 */
/*<  2072 format(1x,a5,1x,a8,3f10.4,2(1pe12.4),3a16) >*/
/* SOURCE output.for:3123 */
/*<  2074 format(' ') >*/
/* SOURCE output.for:3124 */
/*<  2075 format(1x,a) >*/
/* SOURCE output.for:3125 */
/*<  2076  >*/
/* SOURCE output.for:3127 */
/*< 18000  >*/
/* SOURCE output.for:3129 */
/*< 18100  >*/
/* SOURCE output.for:3131 */
/*< 18200  >*/
/* SOURCE output.for:3133 */
/*< 18300  >*/
/* SOURCE output.for:3135 */
/*< 18400  >*/
/* *********************************************************************** */
/*     Define the index for the case selection of format for output */
/* SOURCE output.for:3139 */
/*<       id=nint(log10(sfac)) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    /* Function Body */
/* L2000: */
/* L2020: */
/* L2021: */
/* L2032: */
/* L2040: */
/* L2050: */
/* L2052: */
/* L2054: */
/* L2056: */
/* L2057: */
/* L2058: */
/* L2062: */
/* L2070: */
/* L2072: */
/* L2074: */
/* L2075: */
/* L2076: */
/* L18000: */
/* L18100: */
/* L18200: */
/* L18300: */
/* L18400: */
    feq_gen_r_d_1 = r_lg10(sfac);
    id = i_nint(&feq_gen_r_d_1);
/*      WRITE(STDOUT,2010) TIME */
/* SOURCE output.for:3143 */
/*<       write(stdout,2000) >*/
    feq_gen_io_d__440.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__440);
    e_wsfe();
/* SOURCE output.for:3144 */
/*<       write(stdout,2074) >*/
    feq_gen_io_d__441.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__441);
    e_wsfe();
/* SOURCE output.for:3145 */
/*<       do90i=1,title_n >*/
    feq_gen_i_d_1 = titlei_1.feq_gen_title_n_d_;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE output.for:3146 */
/*<       write(stdout,2075)title(i)(1:lenstr(title(i))) >*/
	feq_gen_io_d__443.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__443);
	do_fio(&feq_gen_c_d_1, titlec_1.title + (feq_gen_i_d_ - 1) * 120, lenstr_(
		titlec_1.title + (feq_gen_i_d_ - 1) * 120, (ftnlen)120));
	e_wsfe();
/* SOURCE output.for:3147 */
/*<    90 continue >*/
/* L90: */
    }
/*     BRANCH LOOP */
/* SOURCE output.for:3152 */
/*<       do100nb=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (nb = 1; nb <= feq_gen_i_d_1; ++nb) {
/* SOURCE output.for:3153 */
/*<       fn=brpt(1,nb)-1 >*/
	fn = brpt[(nb << 3) + 1] - 1;
/* SOURCE output.for:3154 */
/*<       fa=brpt(3,nb) >*/
	fa = brpt[(nb << 3) + 3];
/* SOURCE output.for:3155 */
/*<       la=brpt(4,nb) >*/
	la = brpt[(nb << 3) + 4];
/* SOURCE output.for:3156 */
/*<       if(pndflg.eq.0)then >*/
	if (miscon_1.pndflg == 0) {
/* SOURCE output.for:3157 */
/*<       write(stdout,2020)inbrus(nb) >*/
	    feq_gen_io_d__448.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__448);
	    do_fio(&feq_gen_c_d_1, (char *)&inbr_1.inbrus[nb - 1], (ftnlen)sizeof(
		    integer));
	    e_wsfe();
/* SOURCE output.for:3158 */
/*<       else >*/
	} else {
/* SOURCE output.for:3159 */
/*<       if(vunit.gt.20000.0)then >*/
	    if (*vunit > (float)2e4) {
/* SOURCE output.for:3160 */
/*<       write(stdout,2021)inbrus(nb),bpmax(nb)/vunit,' AC-FT' >*/
		feq_gen_io_d__449.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__449);
		do_fio(&feq_gen_c_d_1, (char *)&inbr_1.inbrus[nb - 1], (ftnlen)sizeof(
			integer));
		feq_gen_r_d_1 = static_cast<double>(bnpond_1.bpmax[nb - 1]) / *vunit;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, const_cast<char*>(" AC-FT"), (ftnlen)6);
		e_wsfe();
/* SOURCE output.for:3161 */
/*<       else >*/
	    } else {
/* SOURCE output.for:3162 */
/*<       write(stdout,2021)inbrus(nb),bpmax(nb)/vunit,' K M^3' >*/
		feq_gen_io_d__450.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__450);
		do_fio(&feq_gen_c_d_1, (char *)&inbr_1.inbrus[nb - 1], (ftnlen)sizeof(
			integer));
		feq_gen_r_d_1 = static_cast<double>(bnpond_1.bpmax[nb - 1]) / *vunit;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, const_cast<char*>(" K M^3"), (ftnlen)6);
		e_wsfe();
/* SOURCE output.for:3163 */
/*<       endif >*/
	    }
/* SOURCE output.for:3164 */
/*<       endif >*/
	}
/* SOURCE output.for:3166 */
/*<       write(stdout,2032) >*/
	feq_gen_io_d__451.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__451);
	e_wsfe();
/* SOURCE output.for:3168 */
/*<       if(addvec(nb).lt.0)then >*/
	if (bnothr_1.addvec[nb - 1] < 0) {
/*         SUPPRESS OUTPUT OF ADDED NODES */
/* SOURCE output.for:3170 */
/*<       addflg=abs(addvec(nb)) >*/
	    addflg = (feq_gen_i_d_2 = bnothr_1.addvec[nb - 1], abs(feq_gen_i_d_2));
/* SOURCE output.for:3171 */
/*<       else >*/
	} else {
/* SOURCE output.for:3172 */
/*<       addflg=0 >*/
	    addflg = 0;
/* SOURCE output.for:3173 */
/*<       endif >*/
	}
/*       ALWAYS OUTPUT THE FIRST NODE */
/* SOURCE output.for:3176 */
/*<       nad=fa >*/
	nad = fa;
/* SOURCE output.for:3177 */
/*<       fn=fn+1 >*/
	++fn;
/* SOURCE output.for:3178 */
/*<       x=xvec(nad)/sfac >*/
	x = static_cast<double>(bnelem_1.xvec[nad - 1]) / *sfac;
/* SOURCE output.for:3179 */
/*<       ymax=zmax(nad)-zvec(nad)+sdvec(nad) >*/
	ymax = static_cast<double>(static_cast<double>(bnrslt_1.zmax[nad - 1]) - bnelem_1.zvec[nad - 1]) + 
		bnelem_1.sdvec[nad - 1];
/* SOURCE output.for:3181 */
/*<       out1=jttoct_old(tzmax(nad)) >*/
	feq_gen_jttoct_old_d_(feq_gen_ch_d_1, (ftnlen)16, &bnrslt_1.tzmax[nad - 1]);
	s_copy(out1, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE output.for:3182 */
/*<       out2=jttoct_old(tqmax(nad)) >*/
	feq_gen_jttoct_old_d_(feq_gen_ch_d_1, (ftnlen)16, &bnrslt_1.tqmax[nad - 1]);
	s_copy(out2, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE output.for:3183 */
/*<       out3=jttoct_old(tqmin(nad)) >*/
	feq_gen_jttoct_old_d_(feq_gen_ch_d_1, (ftnlen)16, &bnrslt_1.tqmin[nad - 1]);
	s_copy(out3, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE output.for:3184 */
/*<       gisid=get_gisid(nsec(nad)) >*/
	feq_gen_get_gisid_d_(feq_gen_ch_d_1, (ftnlen)16, &bnothr_1.nsec[nad - 1]);
	s_copy(gisid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE output.for:3185 */
/*<       qputmx=qmax(nad) >*/
	qputmx = bnrslt_1.qmax[nad - 1];
/* SOURCE output.for:3186 */
/*<       if(abs(qputmx).le.qchop)then >*/
	if (dabs(qputmx) <= *qchop) {
/* SOURCE output.for:3187 */
/*<       qputmx=0.0 >*/
	    qputmx = (float)0.;
/* SOURCE output.for:3188 */
/*<       endif >*/
	}
/* SOURCE output.for:3189 */
/*<       qputmn=qmin(nad) >*/
	qputmn = bnrslt_1.qmin[nad - 1];
/* SOURCE output.for:3190 */
/*<       if(abs(qputmn).le.qchop)then >*/
	if (dabs(qputmn) <= *qchop) {
/* SOURCE output.for:3191 */
/*<       qputmn=0.0 >*/
	    qputmn = (float)0.;
/* SOURCE output.for:3192 */
/*<       endif >*/
	}
/*       Compute an approx to maximum shear stress */
/*        CALL XLKT20 */
/*     I        (NSEC(NAD), */
/*     M         YMAX, */
/*     O         ADUM, TDUM, DTDUM, KATMAX, DCDUM, BDUM, DBDUM) */
/*        TAUMAX = 62.4*YMAX*(QPUTMX/KATMAX)**2 */
/* SOURCE output.for:3202 */
/*<       zmx=zmax(nad)+dz_for_output >*/
	zmx = static_cast<double>(bnrslt_1.zmax[nad - 1]) + *feq_gen_dz_for_output_d_;
/* SOURCE output.for:3203 */
/*<       feql_select3=id >*/
	feq_gen_feql_select3_d_ = id;
/* SOURCE output.for:3203 */
/*<       if(feql_select3.eq.0)then >*/
	if (feq_gen_feql_select3_d_ == 0) {
/* SOURCE output.for:3205 */
/*<        >*/
	    feq_gen_io_d__464.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__464);
	    do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&zmx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&bnrslt_1.vmax[nad - 1], (ftnlen)sizeof(
		    real));
	    do_fio(&feq_gen_c_d_1, (char *)&qputmx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&qputmn, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, out1, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, out2, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, out3, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
	    e_wsfe();
/* SOURCE output.for:3203 */
/*<       elseif(feql_select3.eq.1)then >*/
	} else if (feq_gen_feql_select3_d_ == 1) {
/* SOURCE output.for:3208 */
/*<        >*/
	    feq_gen_io_d__465.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__465);
	    do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&zmx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&bnrslt_1.vmax[nad - 1], (ftnlen)sizeof(
		    real));
	    do_fio(&feq_gen_c_d_1, (char *)&qputmx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&qputmn, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, out1, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, out2, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, out3, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
	    e_wsfe();
/* SOURCE output.for:3203 */
/*<       elseif(feql_select3.eq.2)then >*/
	} else if (feq_gen_feql_select3_d_ == 2) {
/* SOURCE output.for:3211 */
/*<        >*/
	    feq_gen_io_d__466.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__466);
	    do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&zmx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&bnrslt_1.vmax[nad - 1], (ftnlen)sizeof(
		    real));
	    do_fio(&feq_gen_c_d_1, (char *)&qputmx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&qputmn, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, out1, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, out2, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, out3, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
	    e_wsfe();
/* SOURCE output.for:3203 */
/*<       elseif(feql_select3.eq.3)then >*/
	} else if (feq_gen_feql_select3_d_ == 3) {
/* SOURCE output.for:3214 */
/*<        >*/
	    feq_gen_io_d__467.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__467);
	    do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&zmx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&bnrslt_1.vmax[nad - 1], (ftnlen)sizeof(
		    real));
	    do_fio(&feq_gen_c_d_1, (char *)&qputmx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&qputmn, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, out1, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, out2, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, out3, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
	    e_wsfe();
/* SOURCE output.for:3203 */
/*<       else >*/
	} else {
/* SOURCE output.for:3217 */
/*<        >*/
	    feq_gen_io_d__468.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__468);
	    do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&zmx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&bnrslt_1.vmax[nad - 1], (ftnlen)sizeof(
		    real));
	    do_fio(&feq_gen_c_d_1, (char *)&qputmx, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&qputmn, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, out1, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, out2, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, out3, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
	    e_wsfe();
/* SOURCE output.for:3219 */
/*<       endif >*/
	}
/* SOURCE output.for:3220 */
/*<       knt=addflg >*/
	knt = addflg;
/*       II) NODE LOOP */
/* SOURCE output.for:3224 */
/*<       do50nad=fa+1,la >*/
	feq_gen_i_d_2 = la;
	for (nad = fa + 1; nad <= feq_gen_i_d_2; ++nad) {
/* SOURCE output.for:3225 */
/*<       if(hltab(nad).eq.0.and.knt.gt.0)then >*/
	    if (bnothr_1.hltab[nad - 1] == 0 && knt > 0) {
/*           SKIP NODES */
/* SOURCE output.for:3227 */
/*<       knt=knt-1 >*/
		--knt;
/* SOURCE output.for:3228 */
/*<       else >*/
	    } else {
/*           RESET KNT */
/* SOURCE output.for:3230 */
/*<       knt=addflg >*/
		knt = addflg;
/* SOURCE output.for:3231 */
/*<       fn=fn+1 >*/
		++fn;
/* SOURCE output.for:3232 */
/*<       x=xvec(nad)/sfac >*/
		x = static_cast<double>(bnelem_1.xvec[nad - 1]) / *sfac;
/* SOURCE output.for:3233 */
/*<       ymax=zmax(nad)-zvec(nad) >*/
		ymax = static_cast<double>(bnrslt_1.zmax[nad - 1]) - bnelem_1.zvec[nad - 1];
/* SOURCE output.for:3235 */
/*<       out1=jttoct_old(tzmax(nad)) >*/
		feq_gen_jttoct_old_d_(feq_gen_ch_d_1, (ftnlen)16, &bnrslt_1.tzmax[nad - 1]);
		s_copy(out1, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE output.for:3236 */
/*<       out2=jttoct_old(tqmax(nad)) >*/
		feq_gen_jttoct_old_d_(feq_gen_ch_d_1, (ftnlen)16, &bnrslt_1.tqmax[nad - 1]);
		s_copy(out2, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE output.for:3237 */
/*<       out3=jttoct_old(tqmin(nad)) >*/
		feq_gen_jttoct_old_d_(feq_gen_ch_d_1, (ftnlen)16, &bnrslt_1.tqmin[nad - 1]);
		s_copy(out3, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE output.for:3238 */
/*<       gisid=get_gisid(nsec(nad)) >*/
		feq_gen_get_gisid_d_(feq_gen_ch_d_1, (ftnlen)16, &bnothr_1.nsec[nad - 1]);
		s_copy(gisid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE output.for:3239 */
/*<       qputmx=qmax(nad) >*/
		qputmx = bnrslt_1.qmax[nad - 1];
/* SOURCE output.for:3240 */
/*<       if(abs(qputmx).le.qchop)then >*/
		if (dabs(qputmx) <= *qchop) {
/* SOURCE output.for:3241 */
/*<       qputmx=0.0 >*/
		    qputmx = (float)0.;
/* SOURCE output.for:3242 */
/*<       endif >*/
		}
/* SOURCE output.for:3243 */
/*<       qputmn=qmin(nad) >*/
		qputmn = bnrslt_1.qmin[nad - 1];
/* SOURCE output.for:3244 */
/*<       if(abs(qputmn).le.qchop)then >*/
		if (dabs(qputmn) <= *qchop) {
/* SOURCE output.for:3245 */
/*<       qputmn=0.0 >*/
		    qputmn = (float)0.;
/* SOURCE output.for:3246 */
/*<       endif >*/
		}
/*       Compute an approx to maximum shear stress */
/*        CALL XLKT20 */
/*     I        (NSEC(NAD), */
/*     M         YMAX, */
/*     O         ADUM, TDUM, DTDUM, KATMAX, DCDUM, BDUM, DBDUM) */
/*        TAUMAX = 62.4*YMAX*(QPUTMX/KATMAX)**2 */
/* SOURCE output.for:3254 */
/*<       zmx=zmax(nad)+dz_for_output >*/
		zmx = static_cast<double>(bnrslt_1.zmax[nad - 1]) + *feq_gen_dz_for_output_d_;
/* SOURCE output.for:3256 */
/*<       feql_select4=id >*/
		feq_gen_feql_select4_d_ = id;
/* SOURCE output.for:3256 */
/*<       if(feql_select4.eq.0)then >*/
		if (feq_gen_feql_select4_d_ == 0) {
/* SOURCE output.for:3258 */
/*<        >*/
		    feq_gen_io_d__471.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__471);
		    do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)
			    16);
		    do_fio(&feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&zmx, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&bnrslt_1.vmax[nad - 1], (ftnlen)
			    sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&qputmx, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&qputmn, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, out1, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, out2, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, out3, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
		    e_wsfe();
/* SOURCE output.for:3256 */
/*<       elseif(feql_select4.eq.1)then >*/
		} else if (feq_gen_feql_select4_d_ == 1) {
/* SOURCE output.for:3261 */
/*<        >*/
		    feq_gen_io_d__472.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__472);
		    do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)
			    16);
		    do_fio(&feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&zmx, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&bnrslt_1.vmax[nad - 1], (ftnlen)
			    sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&qputmx, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&qputmn, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, out1, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, out2, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, out3, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
		    e_wsfe();
/* SOURCE output.for:3256 */
/*<       elseif(feql_select4.eq.2)then >*/
		} else if (feq_gen_feql_select4_d_ == 2) {
/* SOURCE output.for:3264 */
/*<        >*/
		    feq_gen_io_d__473.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__473);
		    do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)
			    16);
		    do_fio(&feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&zmx, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&bnrslt_1.vmax[nad - 1], (ftnlen)
			    sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&qputmx, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&qputmn, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, out1, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, out2, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, out3, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
		    e_wsfe();
/* SOURCE output.for:3256 */
/*<       elseif(feql_select4.eq.3)then >*/
		} else if (feq_gen_feql_select4_d_ == 3) {
/* SOURCE output.for:3267 */
/*<        >*/
		    feq_gen_io_d__474.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__474);
		    do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)
			    16);
		    do_fio(&feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&zmx, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&bnrslt_1.vmax[nad - 1], (ftnlen)
			    sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&qputmx, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&qputmn, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, out1, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, out2, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, out3, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
		    e_wsfe();
/* SOURCE output.for:3256 */
/*<       else >*/
		} else {
/* SOURCE output.for:3270 */
/*<        >*/
		    feq_gen_io_d__475.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__475);
		    do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, bnothc_1.bnodid + (nad - 1 << 4), (ftnlen)
			    16);
		    do_fio(&feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&zmx, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&bnrslt_1.vmax[nad - 1], (ftnlen)
			    sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&qputmx, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&qputmn, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, out1, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, out2, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, out3, (ftnlen)16);
		    do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
		    e_wsfe();
/* SOURCE output.for:3272 */
/*<       endif >*/
		}
/* SOURCE output.for:3273 */
/*<       endif >*/
	    }
/* SOURCE output.for:3274 */
/*<    50 continue >*/
/* L50: */
	}
/* SOURCE output.for:3275 */
/*<   100 continue >*/
/* L100: */
    }
/*     FREE NODES */
/* SOURCE output.for:3279 */
/*<       if(nex.gt.2*nbra)then >*/
    if (*nex > *nbra << 1) {
/* SOURCE output.for:3281 */
/*<       write(stdout,2050) >*/
	feq_gen_io_d__476.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__476);
	e_wsfe();
/* SOURCE output.for:3282 */
/*<       write(stdout,2062) >*/
	feq_gen_io_d__477.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__477);
	e_wsfe();
/* SOURCE output.for:3283 */
/*<       do200ii=1,nex >*/
	feq_gen_i_d_1 = *nex;
	for (ii = 1; ii <= feq_gen_i_d_1; ++ii) {
/* SOURCE output.for:3284 */
/*<       i=usnsrt(ii) >*/
	    feq_gen_i_d_ = inen_1.usnsrt[ii - 1];
/* SOURCE output.for:3285 */
/*<       if(exnodt(3,i).le.0)then >*/
	    if (exnodt[feq_gen_i_d_ * 9 + 3] <= 0) {
/* SOURCE output.for:3286 */
/*<       if(exnodt(3,i).eq.0)then >*/
		if (exnodt[feq_gen_i_d_ * 9 + 3] == 0) {
/* SOURCE output.for:3287 */
/*<       ymax=fnzmax(i)-ze(i) >*/
		    ymax = static_cast<double>(enrslt_1.fnzmax[feq_gen_i_d_ - 1]) - enelem_1.ze[feq_gen_i_d_ - 1];
/* SOURCE output.for:3288 */
/*<       else >*/
		} else {
/* SOURCE output.for:3289 */
/*<       ymax=fnzmax(i)-ze(i) >*/
		    ymax = static_cast<double>(enrslt_1.fnzmax[feq_gen_i_d_ - 1]) - enelem_1.ze[feq_gen_i_d_ - 1];
/* SOURCE output.for:3290 */
/*<       endif >*/
		}
/* SOURCE output.for:3291 */
/*<       out1=jttoct_old(ftzmax(i)) >*/
		feq_gen_jttoct_old_d_(feq_gen_ch_d_1, (ftnlen)16, &enrslt_1.ftzmax[feq_gen_i_d_ - 1]);
		s_copy(out1, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE output.for:3292 */
/*<       out2=jttoct_old(ftqmax(i)) >*/
		feq_gen_jttoct_old_d_(feq_gen_ch_d_1, (ftnlen)16, &enrslt_1.ftqmax[feq_gen_i_d_ - 1]);
		s_copy(out2, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE output.for:3293 */
/*<       out3=jttoct_old(ftqmin(i)) >*/
		feq_gen_jttoct_old_d_(feq_gen_ch_d_1, (ftnlen)16, &enrslt_1.ftqmin[feq_gen_i_d_ - 1]);
		s_copy(out3, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE output.for:3295 */
/*<       qputmx=fnqmax(i) >*/
		qputmx = enrslt_1.fnqmax[feq_gen_i_d_ - 1];
/* SOURCE output.for:3296 */
/*<       if(abs(qputmx).le.qchop)then >*/
		if (dabs(qputmx) <= *qchop) {
/* SOURCE output.for:3297 */
/*<       qputmx=0.0 >*/
		    qputmx = (float)0.;
/* SOURCE output.for:3298 */
/*<       endif >*/
		}
/* SOURCE output.for:3299 */
/*<       qputmn=fnqmin(i) >*/
		qputmn = enrslt_1.fnqmin[feq_gen_i_d_ - 1];
/* SOURCE output.for:3300 */
/*<       if(abs(qputmn).le.qchop)then >*/
		if (dabs(qputmn) <= *qchop) {
/* SOURCE output.for:3301 */
/*<       qputmn=0.0 >*/
		    qputmn = (float)0.;
/* SOURCE output.for:3302 */
/*<       endif >*/
		}
/*            IF(NODEID.EQ.'NO') THEN */
/*              WRITE(STDOUT,2070) INENUS(I), YMAX, FNZMAX(I), ZE(I), */
/*     A                         QPUTMX, QPUTMN, OUT1, OUT2, OUT3 */
/*            ELSE */
/* SOURCE output.for:3308 */
/*<        >*/
		feq_gen_io_d__479.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__479);
		do_fio(&feq_gen_c_d_1, inenc_1.inenus + (feq_gen_i_d_ - 1) * 5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, enothc_1.enodid + (feq_gen_i_d_ - 1 << 4), (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
		feq_gen_r_d_1 = static_cast<double>(enrslt_1.fnzmax[feq_gen_i_d_ - 1]) + *feq_gen_dz_for_output_d_;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&enelem_1.ze[feq_gen_i_d_ - 1], (ftnlen)sizeof(
			real));
		do_fio(&feq_gen_c_d_1, (char *)&qputmx, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&qputmn, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, out1, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, out2, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, out3, (ftnlen)16);
		e_wsfe();
/*            ENDIF */
/* SOURCE output.for:3312 */
/*<       endif >*/
	    }
/* SOURCE output.for:3313 */
/*<   200 continue >*/
/* L200: */
	}
/*       SCAN EXNODT AND OUTPUT THE MAXIMUM STORAGES IF ANY LEVEL-POOL */
/*       RESERVOIRS FOUND.  MAKE A DOUBLE SCAN: THE FIRST DECIDES */
/*       IF AT LEAST ONE RESERVOIR IS PRESENT AND THE SECOND OUTPUTS */
/*       THE RESERVOIRS IF AT LEAST ONE IS PRESENT. */
/* SOURCE output.for:3320 */
/*<       lprflg=0 >*/
	lprflg = 0;
/* SOURCE output.for:3321 */
/*<       do253i=1,nex >*/
	feq_gen_i_d_1 = *nex;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE output.for:3322 */
/*<       if(exnodt(3,i).lt.0)then >*/
	    if (exnodt[feq_gen_i_d_ * 9 + 3] < 0) {
/* SOURCE output.for:3323 */
/*<       lprflg=1 >*/
		lprflg = 1;
/* SOURCE output.for:3324 */
/*<       goto254 >*/
		goto L254;
/* SOURCE output.for:3325 */
/*<       endif >*/
	    }
/* SOURCE output.for:3326 */
/*<   253 continue >*/
/* L253: */
	}
/* SOURCE output.for:3327 */
/*<   254 continue >*/
L254:
/* SOURCE output.for:3329 */
/*<       if(lprflg.eq.1)then >*/
	if (lprflg == 1) {
/* SOURCE output.for:3330 */
/*<       if(vunit.lt.20000.)then >*/
	    if (*vunit < (float)2e4) {
/* SOURCE output.for:3331 */
/*<       aunit=1.e6 >*/
		feq_gen_aunit_d_ = (float)1e6;
/* SOURCE output.for:3332 */
/*<       else >*/
	    } else {
/* SOURCE output.for:3333 */
/*<       aunit=43560. >*/
		feq_gen_aunit_d_ = (float)43560.;
/* SOURCE output.for:3334 */
/*<       endif >*/
	    }
/* SOURCE output.for:3335 */
/*<       write(stdout,2052) >*/
	    feq_gen_io_d__482.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__482);
	    e_wsfe();
/*          IF(NODEID.EQ.'NO') THEN */
/*            WRITE(STDOUT,2054) */
/*          ELSE */
/* SOURCE output.for:3339 */
/*<       write(stdout,2056) >*/
	    feq_gen_io_d__483.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__483);
	    e_wsfe();
/*          ENDIF */
/* SOURCE output.for:3342 */
/*<       do255ii=1,nex >*/
	    feq_gen_i_d_1 = *nex;
	    for (ii = 1; ii <= feq_gen_i_d_1; ++ii) {
/* SOURCE output.for:3343 */
/*<       i=usnsrt(ii) >*/
		feq_gen_i_d_ = inen_1.usnsrt[ii - 1];
/* SOURCE output.for:3344 */
/*<       if(exnodt(3,i).lt.0)then >*/
		if (exnodt[feq_gen_i_d_ * 9 + 3] < 0) {
/*             LEVEL-POOL RESERVOIR FOUND.  LOOK UP THE VOLUME. */
/* SOURCE output.for:3346 */
/*<       ymax=fnzmax(i)-ze(i) >*/
		    ymax = static_cast<double>(enrslt_1.fnzmax[feq_gen_i_d_ - 1]) - enelem_1.ze[feq_gen_i_d_ - 1];
/* SOURCE output.for:3347 */
/*<       calllktab(exnodt(4,i),ymax,0,vol,ntab,pdv) >*/
		    lktab_(&exnodt[feq_gen_i_d_ * 9 + 4], &ymax, &feq_gen_c_d_0, &vol, &ntab, &
			    pdv);
/*              IF(NODEID.EQ.'NO') THEN */
/*                WRITE(STDOUT,2057) INENUS(I), YMAX, FNZMAX(I), */
/*     A                           VOL/VUNIT, PDV/AUNIT */
/*              ELSE */
/* SOURCE output.for:3354 */
/*<        >*/
		    feq_gen_io_d__487.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__487);
		    do_fio(&feq_gen_c_d_1, inenc_1.inenus + (feq_gen_i_d_ - 1) * 5, (ftnlen)5);
		    do_fio(&feq_gen_c_d_1, enothc_1.enodid + (feq_gen_i_d_ - 1 << 4), (ftnlen)
			    16);
		    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
		    feq_gen_r_d_1 = static_cast<double>(enrslt_1.fnzmax[feq_gen_i_d_ - 1]) + *feq_gen_dz_for_output_d_;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		    feq_gen_r_d_2 = static_cast<double>(vol) / *vunit;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
		    feq_gen_r_d_3 = static_cast<double>(pdv) / feq_gen_aunit_d_;
		    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_3, (ftnlen)sizeof(real));
		    e_wsfe();
/*              ENDIF */
/* SOURCE output.for:3357 */
/*<       endif >*/
		}
/* SOURCE output.for:3358 */
/*<   255 continue >*/
/* L255: */
	    }
/* SOURCE output.for:3359 */
/*<       endif >*/
	}
/* SOURCE output.for:3360 */
/*<       endif >*/
    }
/*     CHECK IF MAXIMA HAVE EXCEEDED THE PHYSICAL TOP OF ANY CROSS */
/*     SECTION */
/* SOURCE output.for:3365 */
/*<       do300nb=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (nb = 1; nb <= feq_gen_i_d_1; ++nb) {
/* SOURCE output.for:3366 */
/*<       fn=brpt(1,nb)-1 >*/
	fn = brpt[(nb << 3) + 1] - 1;
/* SOURCE output.for:3367 */
/*<       fa=brpt(3,nb) >*/
	fa = brpt[(nb << 3) + 3];
/* SOURCE output.for:3368 */
/*<       la=brpt(4,nb) >*/
	la = brpt[(nb << 3) + 4];
/* SOURCE output.for:3369 */
/*<       do250nad=fa,la >*/
	feq_gen_i_d_2 = la;
	for (nad = fa; nad <= feq_gen_i_d_2; ++nad) {
/* SOURCE output.for:3370 */
/*<       fn=fn+1 >*/
	    ++fn;
/* SOURCE output.for:3371 */
/*<       ymax=zmax(nad)-zvec(nad) >*/
	    ymax = static_cast<double>(bnrslt_1.zmax[nad - 1]) - bnelem_1.zvec[nad - 1];
/* SOURCE output.for:3372 */
/*<       diff=ymax-ftab(nsec(nad)+6) >*/
	    diff = static_cast<double>(ymax) - ftab[bnothr_1.nsec[nad - 1] + 6];
/* SOURCE output.for:3373 */
/*<       if(diff.gt.exttol)then >*/
	    if (diff > miscon_1.exttol) {
/* SOURCE output.for:3374 */
/*<       write(stdout,2076)inbrus(nb),fn,get_tabid(itab(nsec(nad)+1)),diff >*/
		feq_gen_io_d__489.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__489);
		do_fio(&feq_gen_c_d_1, (char *)&inbr_1.inbrus[nb - 1], (ftnlen)sizeof(
			integer));
		do_fio(&feq_gen_c_d_1, (char *)&fn, (ftnlen)sizeof(integer));
		feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, itab.lease(bnothr_1.nsec[nad - 1] + 
			1).data());
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, (char *)&diff, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE output.for:3376 */
/*<       endif >*/
	    }
/* SOURCE output.for:3377 */
/*<   250 continue >*/
/* L250: */
	}
/* SOURCE output.for:3378 */
/*<   300 continue >*/
/* L300: */
    }
/*     Check for two-D tables being overtopped */
/* SOURCE output.for:3381 */
/*<       calltdtchk(stdout,exnodt,nex,emc) >*/
    tdtchk_(stdout, &exnodt[10], nex, &emc[1]);
/*     Check for the state of two-D tables in Code 5 Type 6 */
/* SOURCE output.for:3385 */
/*<       calltdtchk_free(stdout,exnodt,nex,qchop,emc) >*/
    feq_gen_tdtchk_free_d_(stdout, &exnodt[10], nex, qchop, &emc[1]);
/* SOURCE output.for:3388 */
/*<       return >*/
    return 0;
/* SOURCE output.for:3389 */
/*<       end >*/
} /* zsumry_old__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE output.for:3394 */
/*<       subroutinefnd14(stdout,qnode,emc,ept,uexn,dexn,hdatum,efac) >*/
/* Subroutine */ int fnd14_(integer *stdout, integer *qnode, integer *feq_storage_emc, 
	integer *ept, integer *uexn, integer *dexn, real *hdatum, real *efac)
{
    /* System generated locals */
    static real equiv_0[1];

    /* Local variables */
    integer code;
#define idum (feq::BitView<integer>(equiv_0, sizeof(equiv_0)))
#define rdum (equiv_0)
    integer ipnt, ientry;

/*     + + + PURPOSE + + + */
/*     Find code = 14 with the given flow node, QNODE, and */
/*     return the upstream node, UEXN, downstream node, DEXN, */
/*     HDATUM, head datum elevation for flow tables, and EFAC, */
/*     the weight factor on elevations.   if not found, */
/*     return -1 in UEXN */
/* SOURCE output.for:3405 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE output.for:3407 */
/*<       integerdexn,ept,qnode,stdout,uexn >*/
/* SOURCE output.for:3408 */
/*<       integeremc(ept) >*/
/* SOURCE output.for:3410 */
/*<       realhdatum,efac >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     UEXN   - upstream exterior node */
/*     DEXN   - downstream exterior node number */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE output.for:3419 */
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
/* INCLUDE output.for:3420 */
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
/* SOURCE output.for:3423 */
/*<       integercode,ientry,idum,ipnt >*/
/* SOURCE output.for:3424 */
/*<       realrdum >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE output.for:3427 */
/*<       charactergetusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE output.for:3430 */
/*<       externalgetusn >*/
/* SOURCE output.for:3432 */
/*<       equivalence(rdum,idum) >*/
/*     + + + OUTPUT FORMATS + + + */
/* *********************************************************************** */
/*     START SEARCH */
/* SOURCE output.for:3437 */
/*<       ientry=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
    ientry = 0;
/* SOURCE output.for:3439 */
/*<   100 continue >*/
L100:
/* SOURCE output.for:3440 */
/*<       ientry=ientry+1 >*/
    ++ientry;
/* SOURCE output.for:3441 */
/*<       ipnt=add(ientry) >*/
    ipnt = matcom_1.add[ientry - 1];
/* SOURCE output.for:3442 */
/*<       code=emc(ipnt) >*/
    code = emc[ipnt];
/* SOURCE output.for:3443 */
/*<       if(code.eq.14)then >*/
    if (code == 14) {
/*         CODE = 14.  Check for flow node */
/* SOURCE output.for:3445 */
/*<       if(qnode.eq.emc(ipnt+3))then >*/
	if (*qnode == emc[ipnt + 3]) {
/*           Found match for flow node */
/* SOURCE output.for:3447 */
/*<       uexn=emc(ipnt+1) >*/
	    *uexn = emc[ipnt + 1];
/* SOURCE output.for:3448 */
/*<       dexn=emc(ipnt+2) >*/
	    *dexn = emc[ipnt + 2];
/* SOURCE output.for:3449 */
/*<       idum=emc(ipnt+8) >*/
	    *idum = emc[ipnt + 8];
/* SOURCE output.for:3450 */
/*<       efac=rdum >*/
	    *efac = *rdum;
/* SOURCE output.for:3451 */
/*<       idum=emc(ipnt+9) >*/
	    *idum = emc[ipnt + 9];
/* SOURCE output.for:3452 */
/*<       hdatum=rdum >*/
	    *hdatum = *rdum;
/* SOURCE output.for:3453 */
/*<       return >*/
	    return 0;
/* SOURCE output.for:3455 */
/*<       endif >*/
	}
/* SOURCE output.for:3456 */
/*<       endif >*/
    }
/* SOURCE output.for:3458 */
/*<       if(code.gt.0)then >*/
    if (code > 0) {
/*         Continue the search. */
/* SOURCE output.for:3460 */
/*<       goto100 >*/
	goto L100;
/* SOURCE output.for:3461 */
/*<       else >*/
    } else {
/*         End of Network-Matrix Control data. */
/* SOURCE output.for:3463 */
/*<       uexn=-1 >*/
	*uexn = -1;
/* SOURCE output.for:3464 */
/*<       return >*/
	return 0;
/* SOURCE output.for:3465 */
/*<       endif >*/
    }
/* SOURCE output.for:3466 */
/*<       end >*/
    return 0;
} /* fnd14_ */

#undef rdum
#undef idum


#ifdef __cplusplus
	}
#endif
