/* fequtl.f -- translated by f2c (version 20240504).
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

/* COMMON homec_ is declared in common.hpp. */

#define homec_1 homec_

/* COMMON xscomd_ is declared in common.hpp. */

#define xscomd_1 xscomd_

/* COMMON xscomu_ is declared in common.hpp. */

#define xscomu_1 xscomu_

/* COMMON xscomb_ is declared in common.hpp. */

#define xscomb_1 xscomb_

/* COMMON fldway_ is declared in common.hpp. */

#define fldway_1 fldway_

/* COMMON fldwyc_ is declared in common.hpp. */

#define fldwyc_1 fldwyc_

/* COMMON bridge_ is declared in common.hpp. */

#define bridge_1 bridge_

/* COMMON flotab_ is declared in common.hpp. */

#define flotab_1 flotab_



#define offcom_1 offcom_

/* COMMON ftable_ is declared in common.hpp. */

#define ftable_1 ftable_

/* COMMON ftablea_ is declared in common.hpp. */

#define ftablea_1 ftablea_

/* COMMON ftablec_ is declared in common.hpp. */

#define ftablec_1 ftablec_

/* COMMON gnicom_ is declared in common.hpp. */

#define gnicom_1 gnicom_

/* COMMON version_ is declared in common.hpp. */

#define version_1 version_

/* COMMON versionc_ is declared in common.hpp. */

#define versionc_1 versionc_

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* COMMON xscom_ is declared in common.hpp. */

#define xscom_1 xscom_

/* COMMON grvcom_ is declared in common.hpp. */

#define grvcom_1 grvcom_

/* COMMON epscom_ is declared in common.hpp. */

#define epscom_1 epscom_

/* COMMON clcomc_ is declared in common.hpp. */

#define clcomc_1 clcomc_

/* COMMON clcom_ is declared in common.hpp. */

#define clcom_1 clcom_

/* COMMON nrdzcm_ is declared in common.hpp. */

#define nrdzcm_1 nrdzcm_

/* COMMON julian_ is declared in common.hpp. */

#define julian_1 julian_

/* COMMON tabid_ is declared in common.hpp. */

#define tabid_1 tabid_

/* COMMON tabidc_ is declared in common.hpp. */

#define tabidc_1 tabidc_

/* COMMON upgrdc_ is declared in common.hpp. */

#define upgrdc_1 upgrdc_

/* COMMON whatos_ is declared in common.hpp. */

#define whatos_1 whatos_

/* COMMON datetime_ is declared in common.hpp. */

#define datetime_1 datetime_

/* COMMON grid_datum__ is declared in common.hpp. */

#define feq_gen_grid_datum_d_1 feq_gen_grid_datum_d_

/* COMMON mktbindxc_ is declared in common.hpp. */

#define mktbindxc_1 mktbindxc_

/* COMMON mktbindx_ is declared in common.hpp. */

#define mktbindx_1 mktbindx_

/* COMMON svncom_ is declared in common.hpp. */

#define svncom_1 svncom_

/* COMMON svncomc_ is declared in common.hpp. */

#define svncomc_1 svncomc_

/* Initialized data */

/* OFFCOM BLOCK DATA is defined in common.cpp. */


/* Table of constant values */

static integer feq_gen_c_d_2 = 2;
static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_10 = 10;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_3 = 3;
static integer feq_gen_c_d_0 = 0;
static integer feq_gen_c_d_45 = 45;
static integer feq_gen_c_d_10002 = 10002;
static integer c_b506 = 13000001;

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



/* SOURCE fequtl.for:27 */
/*<       subroutineclear_ghome() >*/
/* Subroutine */ int feq_gen_clear_ghome_d_()
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     Clear the GHOME part of file names. */
/* SOURCE fequtl.for:31 */
/*<       implicitnone >*/
/* INCLUDE fequtl.for:33 */
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
/* *********************************************************************** */
/* SOURCE fequtl.for:35 */
/*<       ghome=' ' >*/
    s_copy(homec_1.ghome, const_cast<char*>(" "), (ftnlen)128, (ftnlen)1);
/* SOURCE fequtl.for:36 */
/*<       return >*/
    return 0;
/* SOURCE fequtl.for:37 */
/*<       end >*/
} /* clear_ghome__ */




/* SOURCE fequtl.for:42 */
/*<       subroutinemake_standard_file_names(fname,fname2,fname3) >*/
/* Subroutine */ int feq_gen_make_standard_file_names_d_(char *fname, char *fname2, 
	char *fname3, ftnlen fname_len, ftnlen fname2_len, ftnlen fname3_len)
{
    /* System generated locals */
    address feq_gen_a_d_1[2];
    integer feq_gen_i_d_1[2];

    /* Builtin functions */
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, l, n;
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);

/*     Given the name for the input file to FEQUTL form the standard names for */
/*     the remaining file names. */
/* SOURCE fequtl.for:48 */
/*<       implicitnone >*/
/* SOURCE fequtl.for:50 */
/*<       character*64fname,fname2,fname3 >*/
/*     Local */
/* SOURCE fequtl.for:55 */
/*<       integeri,l,n >*/
/* *********************************************************************** */
/*     The input file name may or may not have an extension.  Also */
/*     this should work with more than one period in the file name. */
/*     The period closest to the end of the string will be taken to */
/*     be the delimiter for the extension.  If no period is found, */
/*     then the whole name is used for the base name of the remaining */
/*     file names unless the period is in the first position and is */
/*     the only period present. */
/* SOURCE fequtl.for:42 */
/*<       integer feq_len_trim >*/
/* SOURCE fequtl.for:42 */
/*<       external feq_len_trim >*/
/* SOURCE fequtl.for:66 */
/*<       n=feq_len_trim(fname) >*/
    n = feq_gen_feq_len_trim_d_(fname, (ftnlen)64);
/*     Set L for case of no period found */
/* SOURCE fequtl.for:69 */
/*<       l=n >*/
    l = n;
/* SOURCE fequtl.for:70 */
/*<       doi=n,1,-1 >*/
    for (feq_gen_i_d_ = n; feq_gen_i_d_ >= 1; --feq_gen_i_d_) {
/* SOURCE fequtl.for:72 */
/*<       if(fname(i:i).eq.'.')then >*/
	if (*(unsigned char *)&fname[feq_gen_i_d_ - 1] == '.') {
/* SOURCE fequtl.for:73 */
/*<       if(i.gt.1)then >*/
	    if (feq_gen_i_d_ > 1) {
/* SOURCE fequtl.for:74 */
/*<       l=i-1 >*/
		l = feq_gen_i_d_ - 1;
/* SOURCE fequtl.for:75 */
/*<       else >*/
	    } else {
/* SOURCE fequtl.for:76 */
/*<       l=n >*/
		l = n;
/* SOURCE fequtl.for:77 */
/*<       endif >*/
	    }
/* SOURCE fequtl.for:78 */
/*<       goto99000 >*/
	    goto L99000;
/* SOURCE fequtl.for:79 */
/*<       endif >*/
	}
/* SOURCE fequtl.for:81 */
/*<       enddo >*/
    }
/* SOURCE fequtl.for:81 */
/*< 99000 continue >*/
L99000:
/* SOURCE fequtl.for:83 */
/*<       fname2=fname(1:l)//'.out' >*/
/* Writing concatenation */
    feq_gen_i_d_1[0] = l, feq_gen_a_d_1[0] = fname;
    feq_gen_i_d_1[1] = 4, feq_gen_a_d_1[1] = const_cast<char*>(".out");
    s_cat(fname2, feq_gen_a_d_1, feq_gen_i_d_1, &feq_gen_c_d_2, (ftnlen)64);
/* SOURCE fequtl.for:84 */
/*<       fname3=fname(1:l)//'.tab' >*/
/* Writing concatenation */
    feq_gen_i_d_1[0] = l, feq_gen_a_d_1[0] = fname;
    feq_gen_i_d_1[1] = 4, feq_gen_a_d_1[1] = const_cast<char*>(".tab");
    s_cat(fname3, feq_gen_a_d_1, feq_gen_i_d_1, &feq_gen_c_d_2, (ftnlen)64);
/* SOURCE fequtl.for:85 */
/*<       return >*/
    return 0;
/* SOURCE fequtl.for:86 */
/*<       end >*/
} /* make_standard_file_names__ */




/* SOURCE fequtl.for:93 */
/*<       integerfunctiongetusb(ibn) >*/
integer getusb_(integer *ibn)
{
    /* System generated locals */
    integer ret_val;

/*     + + + PURPOSE + + + */
/*     Dummy function for calls from fequtl to routines which */
/*     refer to a branch number. */
/* SOURCE fequtl.for:99 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fequtl.for:103 */
/*<       integeribn >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IBN    - Internal branch number */
/* *********************************************************************** */
/* SOURCE fequtl.for:108 */
/*<       getusb=ibn >*/
    ret_val = *ibn;
/* SOURCE fequtl.for:109 */
/*<       return >*/
    return ret_val;
/* SOURCE fequtl.for:110 */
/*<       end >*/
} /* getusb_ */




/* SOURCE fequtl.for:114 */
/*<       subroutineinit() >*/
/* Subroutine */ int init_()
{
    /* Local variables */
    integer j, feq_gen_feql_index1_d_, feq_gen_feql_index2_d_;
#define dvec (feq::BitView<integer>(&xscomd_1, sizeof(xscomd_1)))
#define uvec (feq::BitView<integer>(&xscomu_1, sizeof(xscomu_1)))

/*     + + + PURPOSE + + + */
/*     Initialize common variables */
/* SOURCE fequtl.for:119 */
/*<       implicitnone >*/
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fequtl.for:122 */
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
/* INCLUDE fequtl.for:123 */
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
/* INCLUDE fequtl.for:124 */
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
/* INCLUDE fequtl.for:125 */
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
/* INCLUDE fequtl.for:126 */
/*     FLOOD WAY COMMON BLOCK */
/* SOURCE fldway.cmn:3 */
/*<       character*4fldopt(pmxtab) >*/
/* SOURCE fldway.cmn:5 */
/*<       integerflood >*/
/* SOURCE fldway.cmn:7 */
/*<       realglbelv,glbcon >*/
/* SOURCE fldway.cmn:9 */
/*<        >*/
/* SOURCE fldway.cmn:13 */
/*<        >*/
/* SOURCE fldway.cmn:17 */
/*<       common/fldwyc/fldopt >*/
/* SOURCE fldway.cmn:19 */
/*<       save/fldwyc/,/fldway/ >*/
/* INCLUDE fequtl.for:127 */
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
/* INCLUDE fequtl.for:128 */
/*     COMMON FOR THE FLOW TABLE */
/* SOURCE flotab.cmn:3 */
/*<       integernft,maxnft >*/
/* SOURCE flotab.cmn:4 */
/*<       realzft(25),ftable(20,20),qcritv(25) >*/
/* SOURCE flotab.cmn:6 */
/*<       common/flotab/nft,maxnft,zft,ftable,qcritv >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fequtl.for:131 */
/*<       integerj >*/
/* SOURCE fequtl.for:132 */
/*<       integerdvec(xscoml),uvec(xscoml) >*/
/*     + + + EQUIVALENCES + + + */
/* SOURCE fequtl.for:135 */
/*<       equivalence(npntd,dvec(1)),(npntu,uvec(1)) >*/
/* *********************************************************************** */
/*     zero come common blocks */
/* SOURCE fequtl.for:114 */
/*<       integer feql_index1 >*/
/* SOURCE fequtl.for:114 */
/*<       integer feql_index2 >*/
/* SOURCE fequtl.for:138 */
/*<       do100j=1,xscoml >*/
    for (j = 1; j <= 22791; ++j) {
/* SOURCE fequtl.for:139 */
/*<       dvec(j)=0 >*/
	dvec[j - 1] = 0;
/* SOURCE fequtl.for:140 */
/*<       uvec(j)=0 >*/
	uvec[j - 1] = 0;
/* SOURCE fequtl.for:141 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE fequtl.for:142 */
/*<       maxnft=20 >*/
    flotab_1.maxnft = 20;
/* SOURCE fequtl.for:143 */
/*<       mxpntu=pmxpnt >*/
    xscomu_1.mxpntu = 999;
/* SOURCE fequtl.for:144 */
/*<       mxpntd=pmxpnt >*/
    xscomd_1.mxpntd = 999;
/* SOURCE fequtl.for:145 */
/*<       mxpntb=pmxpnt >*/
    xscomb_1.mxpntb = 999;
/* SOURCE fequtl.for:146 */
/*<       npntu=0 >*/
    xscomu_1.npntu = 0;
/* SOURCE fequtl.for:147 */
/*<       maxnpz=25 >*/
    bridge_1.maxnpz = 25;
/*     SET FLOODWAY FLAG TO OFF. MUST BE TURNED ON BY USER TO */
/*     BE ACTIVE */
/* SOURCE fequtl.for:150 */
/*<       flood=0 >*/
    fldway_1.flood = 0;
/*     Zero lsnu and lsnd to avoid failures when debugging with */
/*     full checking turned on using LF95 */
/* SOURCE fequtl.for:153 */
/*<       dofeql_index1=1,pmxpnt >*/
    for (feq_gen_feql_index1_d_ = 1; feq_gen_feql_index1_d_ <= 999; ++feq_gen_feql_index1_d_) {
/* SOURCE fequtl.for:153 */
/*<       lsnu(feql_index1)=0.0 >*/
	xscomu_1.lsnu[feq_gen_feql_index1_d_ - 1] = (float)0.;
/* SOURCE fequtl.for:153 */
/*<       enddo >*/
    }
/* SOURCE fequtl.for:154 */
/*<       dofeql_index2=1,pmxpnt >*/
    for (feq_gen_feql_index2_d_ = 1; feq_gen_feql_index2_d_ <= 999; ++feq_gen_feql_index2_d_) {
/* SOURCE fequtl.for:154 */
/*<       lsnd(feql_index2)=0.0 >*/
	xscomd_1.lsnd[feq_gen_feql_index2_d_ - 1] = (float)0.;
/* SOURCE fequtl.for:154 */
/*<       enddo >*/
    }
/* SOURCE fequtl.for:155 */
/*<       return >*/
    return 0;
/* SOURCE fequtl.for:156 */
/*<       end >*/
} /* init_ */

#undef uvec
#undef dvec





/* SOURCE fequtl.for:160 */
/*<       subroutinemkfmt(xa,w,fmstrg) >*/
/* Subroutine */ int mkfmt_(real *xa, integer *w, char *fmstrg, ftnlen 
	fmstrg_len)
{
    /* System generated locals */
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double r_lg10(real *);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi();

    /* Local variables */
    integer feq_gen_d_d_;
    real x;

/*     + + + PURPOSE + + + */
/*     Make a fixed format code, excluding () where W is the field */
/*     width, and X is a defining number.  The goal is to provide */
/*     as many decimal places as will fit, leaving room for a */
/*     decimal point and possibly a sign. */
/* SOURCE fequtl.for:170 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fequtl.for:173 */
/*<       integerw >*/
/* SOURCE fequtl.for:174 */
/*<       realxa >*/
/* SOURCE fequtl.for:175 */
/*<       characterfmstrg*(*) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     XA     - Trial number to define a format */
/*     W      - Field with in characters for the format */
/*     FMSTRG - Format string */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fequtl.for:183 */
/*<       integerd >*/
/* SOURCE fequtl.for:184 */
/*<       realx >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fequtl.for:187 */
/*<       intrinsicabs,int,log10 >*/
/* *********************************************************************** */
/* SOURCE fequtl.for:189 */
/*<       fmstrg=' ' >*/
    s_copy(fmstrg, const_cast<char*>(" "), fmstrg_len, (ftnlen)1);
/* SOURCE fequtl.for:190 */
/*<       x=abs(xa) >*/
    x = dabs(*xa);
/* SOURCE fequtl.for:191 */
/*<       if(x.ne.0.0)then >*/
    if (x != (float)0.) {
/* SOURCE fequtl.for:192 */
/*<       d=w-(int(log10(x))+3) >*/
	feq_gen_d_d_ = *w - ((integer) r_lg10(&x) + 3);
/* SOURCE fequtl.for:193 */
/*<       if(d.gt.w-3)then >*/
	if (feq_gen_d_d_ > *w - 3) {
/* SOURCE fequtl.for:194 */
/*<       d=w-3 >*/
	    feq_gen_d_d_ = *w - 3;
/* SOURCE fequtl.for:195 */
/*<       elseif(d.lt.0)then >*/
	} else if (feq_gen_d_d_ < 0) {
/* SOURCE fequtl.for:196 */
/*<       d=0 >*/
	    feq_gen_d_d_ = 0;
/* SOURCE fequtl.for:197 */
/*<       endif >*/
	}
/* SOURCE fequtl.for:198 */
/*<       else >*/
    } else {
/* SOURCE fequtl.for:199 */
/*<       d=w-3 >*/
	feq_gen_d_d_ = *w - 3;
/* SOURCE fequtl.for:200 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:202 */
/*<       write(fmstrg,'(1HF,I2,1H.,I1)')w,d >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = fmstrg_len;
    feq_gen_ici_d_1.iciunit = fmstrg;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(1HF,I2,1H.,I1)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*w), (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_d_d_, (ftnlen)sizeof(integer));
    e_wsfi();
/* SOURCE fequtl.for:203 */
/*<       return >*/
    return 0;
/* SOURCE fequtl.for:204 */
/*<       end >*/
} /* mkfmt_ */




/* SOURCE fequtl.for:208 */
/*<       character*7functionput7(x) >*/
/* Character */ VOID put7_(char *ret_val, ftnlen ret_val_len, real *x)
{
    /* System generated locals */
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    char work[10], result[7];

/*     + + + PURPOSE + + + */
/*     Function to convert a real number into a special compact */
/*     form of output to retain 4 significant figures for */
/*     numbers in the range -1e12 < x < 1e12.  This range includes */
/*     all reasonable flows for any river on earth! */
/*     The smallest non-zero flow is 1e-6, again smaller than any */
/*     flow of interest in a stream. */
/* SOURCE fequtl.for:219 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fequtl.for:222 */
/*<       realx >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     X      - Value to be put */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fequtl.for:228 */
/*<       characterresult*7,work*10 >*/
/* *********************************************************************** */
/* SOURCE fequtl.for:230 */
/*<       write(work,'(4PE10.3)')x >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 10;
    feq_gen_ici_d_1.iciunit = work;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(4PE10.3)");
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*x), (ftnlen)sizeof(real));
    e_wsfi();
/* SOURCE fequtl.for:231 */
/*<       if(work(8:8).eq.'+'.and.work(9:9).ne.'0')then >*/
    if (*(unsigned char *)&work[7] == '+' && *(unsigned char *)&work[8] != 
	    '0') {
/*       OVERFLOW */
/* SOURCE fequtl.for:233 */
/*<       result=' ******' >*/
	s_copy(result, const_cast<char*>(" ******"), (ftnlen)7, (ftnlen)7);
/* SOURCE fequtl.for:234 */
/*<       elseif(work(8:8).eq.'-'.and.work(9:9).ne.'0')then >*/
    } else if (*(unsigned char *)&work[7] == '-' && *(unsigned char *)&work[8]
	     != '0') {
/*       UNDERFLOW */
/* SOURCE fequtl.for:236 */
/*<       result=' 0000+0' >*/
	s_copy(result, const_cast<char*>(" 0000+0"), (ftnlen)7, (ftnlen)7);
/* SOURCE fequtl.for:237 */
/*<       else >*/
    } else {
/* SOURCE fequtl.for:238 */
/*<       result(1:5)=work(1:5) >*/
	s_copy(result, work, (ftnlen)5, (ftnlen)5);
/* SOURCE fequtl.for:239 */
/*<       result(6:6)=work(8:8) >*/
	*(unsigned char *)&result[5] = *(unsigned char *)&work[7];
/* SOURCE fequtl.for:240 */
/*<       result(7:7)=work(10:10) >*/
	*(unsigned char *)&result[6] = *(unsigned char *)&work[9];
/* SOURCE fequtl.for:241 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:242 */
/*<       put7=result >*/
    s_copy(ret_val, result, (ftnlen)7, (ftnlen)7);
/* SOURCE fequtl.for:243 */
/*<       return >*/
    return ;
/* SOURCE fequtl.for:244 */
/*<       end >*/
} /* put7_ */




/* SOURCE fequtl.for:248 */
/*<       integerfunctionstrlen(str) >*/
integer strlen_(char *str, ftnlen str_len)
{
    /* System generated locals */
    integer ret_val;

    /* Builtin functions */
    integer i_len(char *, ftnlen);

    /* Local variables */
    integer done, lent;

/*     + + + PURPOSE + + + */
/*     Return the actual length of the character array, */
/*     excluding trailing blanks.  A string of all blanks is taken */
/*     to be empty. */
/* SOURCE fequtl.for:256 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fequtl.for:259 */
/*<       characterstr*(*) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STR    - string for length computation */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fequtl.for:265 */
/*<       integerdone,lent >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fequtl.for:268 */
/*<       intrinsiclen >*/
/* *********************************************************************** */
/* SOURCE fequtl.for:270 */
/*<       lent=len(str) >*/
    lent = i_len(str, str_len);
/* SOURCE fequtl.for:271 */
/*<       done=0 >*/
    done = 0;
/* SOURCE fequtl.for:272 */
/*<    10 continue >*/
L10:
/* SOURCE fequtl.for:273 */
/*<       if(str(lent:lent).eq.' ')then >*/
    if (*(unsigned char *)&str[lent - 1] == ' ') {
/* SOURCE fequtl.for:274 */
/*<       lent=lent-1 >*/
	--lent;
/* SOURCE fequtl.for:275 */
/*<       else >*/
    } else {
/* SOURCE fequtl.for:276 */
/*<       done=1 >*/
	done = 1;
/* SOURCE fequtl.for:277 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:278 */
/*<       if(lent.gt.0.and.done.eq.0)goto10 >*/
    if (lent > 0 && done == 0) {
	goto L10;
    }
/* SOURCE fequtl.for:280 */
/*<       strlen=lent >*/
    ret_val = lent;
/* SOURCE fequtl.for:282 */
/*<       return >*/
    return ret_val;
/* SOURCE fequtl.for:283 */
/*<       end >*/
} /* strlen_ */




/* SOURCE fequtl.for:287 */
/*<       subroutinetabchk(stdout,pmxtab,tab,tabdir,eflag) >*/
/* Subroutine */ int tabchk_(integer *stdout, integer *pmxtab, integer *tab, 
	integer *feq_storage_tabdir, integer *eflag)
{
    /* Format strings */
    static char fmt_52[] = "(\0020*ERR:510* Duplicate table id.\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__15 = { 0, 0, 0, fmt_52, 0 };


/*     + + + PURPOSE + + + */
/*     Check for valid table number */
/* SOURCE fequtl.for:294 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fequtl.for:297 */
/*<       integereflag,pmxtab,stdout,tab >*/
/* SOURCE fequtl.for:298 */
/*<       integertabdir(pmxtab) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     PMXTAB - Maximum value of function table number */
/*     TAB    - Table number */
/*     TABDIR - Table directory to remember table numbers */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fequtl.for:308 */
/*<    52 format('0*ERR:510* Duplicate table id.') >*/
/* *********************************************************************** */
/* SOURCE fequtl.for:310 */
/*<       if(tabdir(tab).eq.0)goto110 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> tabdir(feq_storage_tabdir, 1);

    /* Function Body */
/* L52: */
    if (tabdir[*tab] == 0) {
	goto L110;
    }
/* SOURCE fequtl.for:311 */
/*<       write(stdout,52) >*/
    feq_gen_io_d__15.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__15);
    e_wsfe();
/* SOURCE fequtl.for:312 */
/*<       eflag=eflag+1 >*/
    ++(*eflag);
/* SOURCE fequtl.for:313 */
/*<       return >*/
    return 0;
/* SOURCE fequtl.for:314 */
/*<   110 continue >*/
L110:
/* SOURCE fequtl.for:315 */
/*<       tabdir(tab)=tab >*/
    tabdir[*tab] = *tab;
/* SOURCE fequtl.for:316 */
/*<       return >*/
    return 0;
/* SOURCE fequtl.for:317 */
/*<       end >*/
} /* tabchk_ */




/* SOURCE fequtl.for:321 */
/*<       blockdataxoffin >*/
/* Subroutine */ int xoffin_()
{
    return 0;
} /* xoffin_ */

/*     + + + PURPOSE + + + */
/*     Initialize the offset list for cross sections. */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fequtl.for:327 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + DATA INITIALIZATIONS + + + */
/* *********************************************************************** */
/* SOURCE fequtl.for:330 */
/*<       dataoffvec/6,10*0,8,7*0,5,6,8,7,8,10,4*0,7,8,11,11,12,15/ >*/
/* SOURCE fequtl.for:333 */
/*<       end >*/




/* SOURCE fequtl.for:337 */
/*<       subroutinechkcfc(grav,stdout,adrs,wflag) >*/
/* Subroutine */ int chkcfc_(real *grav, integer *stdout, integer *adrs, 
	integer *wflag)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *BUG:XXX.  Invalid type in CHKCFC\002)";
    static char fmt_52[] = "(\002 *WRN:521* Critical flow decreases by \002,\
f7.2,\002 per cent at depth=\002,f10.3)";
    static char fmt_54[] = "(\002 Table tests OK.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    real a, feq_gen_c_d_, p, q, t, y;
    integer ha;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
    integer doff;
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ioff;
    real qold;
    integer xoff, feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    integer dtype;
    real mxslot;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__25 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__34 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__35 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__36 = { 0, 0, 0, fmt_54, 0 };


/*     + + + PURPOSE + + + */
/*     Check the critical flow and celerity in the table given by */
/*     the address, ADRS, and report regions of decrease in */
/*     critical flow or celerity. */
/* SOURCE fequtl.for:346 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fequtl.for:349 */
/*<       integeradrs,stdout,wflag >*/
/* SOURCE fequtl.for:350 */
/*<       realgrav >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     GRAV   - value of acceleration due to gravity */
/*     STDOUT - Fortran unit number for user output and messages */
/*     ADRS   - Address of function table */
/*     WFLAG  - Flag to suppress more than a single warning message */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fequtl.for:359 */
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
/* INCLUDE fequtl.for:360 */
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
/* INCLUDE fequtl.for:361 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fequtl.for:364 */
/*<       integerha,ioff,type,xoff,doff,dtype >*/
/* SOURCE fequtl.for:365 */
/*<       reala,c,p,q,qold,t,y,mxslot >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fequtl.for:368 */
/*<       intrinsicabs,sqrt >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fequtl.for:371 */
/*<    50 format(' *BUG:XXX.  Invalid type in CHKCFC') >*/
/* SOURCE fequtl.for:372 */
/*<    52  >*/
/* SOURCE fequtl.for:374 */
/*<    54 format(' Table tests OK.') >*/
/* *********************************************************************** */
/* SOURCE fequtl.for:376 */
/*<       if(grav.gt.15.0)then >*/
/* L50: */
/* L52: */
/* L54: */
    if (*grav > (float)15.) {
/* SOURCE fequtl.for:377 */
/*<       mxslot=0.07 >*/
	mxslot = (float).07;
/* SOURCE fequtl.for:378 */
/*<       else >*/
    } else {
/* SOURCE fequtl.for:379 */
/*<       mxslot=0.02134 >*/
	mxslot = (float).02134;
/* SOURCE fequtl.for:380 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:381 */
/*<       type=itab(adrs+2) >*/
    feq_gen_type_d_ = itab[*adrs + 2];
/* SOURCE fequtl.for:382 */
/*<       xoff=offvec(type) >*/
    xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE fequtl.for:383 */
/*<       ha=itab(adrs) >*/
    ha = itab[*adrs];
/* SOURCE fequtl.for:384 */
/*<       doff=itab(adrs+21) >*/
    doff = itab[*adrs + 21];
/* SOURCE fequtl.for:385 */
/*<       if(doff.gt.0)then >*/
    if (doff > 0) {
/* SOURCE fequtl.for:386 */
/*<       dtype=10 >*/
	dtype = 10;
/* SOURCE fequtl.for:387 */
/*<       else >*/
    } else {
/* SOURCE fequtl.for:388 */
/*<       dtype=0 >*/
	dtype = 0;
/* SOURCE fequtl.for:389 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:391 */
/*<       type=type-dtype >*/
    feq_gen_type_d_ -= dtype;
/* SOURCE fequtl.for:392 */
/*<       if(type.lt.20.or.type.gt.25)then >*/
    if (feq_gen_type_d_ < 20 || feq_gen_type_d_ > 25) {
/* SOURCE fequtl.for:393 */
/*<       write(stdout,50)type+dtype >*/
	feq_gen_io_d__25.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__25);
	feq_gen_i_d_1 = feq_gen_type_d_ + dtype;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE fequtl.for:394 */
/*<       stop'Abnormal stop. Bug found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Bug found."), (ftnlen)25);
/* SOURCE fequtl.for:395 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:396 */
/*<       if(type.eq.20.or.type.eq.21.or.type.eq.23.or.type.eq.24)then >*/
    if (feq_gen_type_d_ == 20 || feq_gen_type_d_ == 21 || feq_gen_type_d_ == 23 || feq_gen_type_d_ == 24) {
/*       IOFF GIVES THE OFFSET FROM THE TABLE ADDRESS TO THE FIRST */
/*       POSITIVE DEPTH  ENTRY IN THE TABLE. */
/* SOURCE fequtl.for:400 */
/*<       ioff=xtioff+xoff >*/
	ioff = xoff + 32;
/*        COLD = 0.0 */
/* SOURCE fequtl.for:403 */
/*<       qold=0.0 >*/
	qold = (float)0.;
/* SOURCE fequtl.for:404 */
/*<       wflag=0 >*/
	*wflag = 0;
/* SOURCE fequtl.for:406 */
/*<   100 continue >*/
L100:
/* SOURCE fequtl.for:408 */
/*<       y=ftab(adrs+ioff) >*/
	y = ftab[*adrs + ioff];
/* SOURCE fequtl.for:409 */
/*<       t=ftab(adrs+ioff+1) >*/
	t = ftab[*adrs + ioff + 1];
/* SOURCE fequtl.for:410 */
/*<       a=ftab(adrs+ioff+2) >*/
	a = ftab[*adrs + ioff + 2];
/* SOURCE fequtl.for:412 */
/*<       c=sqrt(grav*a/t) >*/
	feq_gen_c_d_ = sqrt(static_cast<double>(static_cast<double>(*grav) * a) / t);
/* SOURCE fequtl.for:413 */
/*<       q=a*c >*/
	q = static_cast<double>(a) * feq_gen_c_d_;
/*          IF(C.LE.COLD) THEN */
/*            P = 100.*ABS(C - COLD)/COLD */
/*            WRITE(STDOUT,50) P, Y */
/*            WFLAG = 1 */
/*          ENDIF */
/*          COLD = C */
/* SOURCE fequtl.for:423 */
/*<       if(q.le.qold.and.t.gt.mxslot)then >*/
	if (q <= qold && t > mxslot) {
/* SOURCE fequtl.for:424 */
/*<       p=100.*abs(q-qold)/qold >*/
	    p = (feq_gen_r_d_1 = static_cast<double>(q) - qold, dabs(feq_gen_r_d_1)) * (float)100. / qold;
/* SOURCE fequtl.for:425 */
/*<       write(stdout,52)p,y >*/
	    feq_gen_io_d__34.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__34);
	    do_fio(&feq_gen_c_d_1, (char *)&p, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE fequtl.for:426 */
/*<       wflag=1 >*/
	    *wflag = 1;
/* SOURCE fequtl.for:427 */
/*<       endif >*/
	}
/* SOURCE fequtl.for:429 */
/*<       qold=q >*/
	qold = q;
/* SOURCE fequtl.for:430 */
/*<       ioff=ioff+xoff >*/
	ioff += xoff;
/* SOURCE fequtl.for:432 */
/*<       if(adrs+ioff.le.ha)goto100 >*/
	if (*adrs + ioff <= ha) {
	    goto L100;
	}
/* SOURCE fequtl.for:433 */
/*<       else >*/
    } else {
/*       IOFF GIVES THE OFFSET FROM THE TABLE ADDRESS TO THE FIRST */
/*       POSITIVE DEPTH  ENTRY IN THE TABLE. */
/* SOURCE fequtl.for:437 */
/*<       ioff=xtioff+xoff >*/
	ioff = xoff + 32;
/*        COLD = 0.0 */
/* SOURCE fequtl.for:440 */
/*<       qold=0.0 >*/
	qold = (float)0.;
/* SOURCE fequtl.for:441 */
/*<       wflag=0 >*/
	*wflag = 0;
/* SOURCE fequtl.for:443 */
/*<   200 continue >*/
L200:
/* SOURCE fequtl.for:445 */
/*<       y=ftab(adrs+ioff) >*/
	y = ftab[*adrs + ioff];
/* SOURCE fequtl.for:446 */
/*<       t=ftab(adrs+ioff+1) >*/
	t = ftab[*adrs + ioff + 1];
/* SOURCE fequtl.for:447 */
/*<       a=ftab(adrs+ioff+2) >*/
	a = ftab[*adrs + ioff + 2];
/* SOURCE fequtl.for:448 */
/*<       q=ftab(adrs+ioff+7) >*/
	q = ftab[*adrs + ioff + 7];
/* SOURCE fequtl.for:449 */
/*<       c=q/a >*/
	feq_gen_c_d_ = static_cast<double>(q) / a;
/*          IF(C.LE.COLD) THEN */
/*            P = 100.*ABS(C - COLD)/COLD */
/*            WRITE(STDOUT,50) P, Y */
/*            WFLAG = 1 */
/*          ENDIF */
/*          COLD = C */
/* SOURCE fequtl.for:459 */
/*<       if(q.le.qold.and.t.gt.0.07)then >*/
	if (q <= qold && t > (float).07) {
/* SOURCE fequtl.for:460 */
/*<       p=100.*abs(q-qold)/qold >*/
	    p = (feq_gen_r_d_1 = static_cast<double>(q) - qold, dabs(feq_gen_r_d_1)) * (float)100. / qold;
/* SOURCE fequtl.for:461 */
/*<       write(stdout,52)p,y >*/
	    feq_gen_io_d__35.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__35);
	    do_fio(&feq_gen_c_d_1, (char *)&p, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE fequtl.for:462 */
/*<       wflag=1 >*/
	    *wflag = 1;
/* SOURCE fequtl.for:463 */
/*<       endif >*/
	}
/* SOURCE fequtl.for:465 */
/*<       qold=q >*/
	qold = q;
/* SOURCE fequtl.for:466 */
/*<       ioff=ioff+xoff >*/
	ioff += xoff;
/* SOURCE fequtl.for:468 */
/*<       if(adrs+ioff.le.ha)goto200 >*/
	if (*adrs + ioff <= ha) {
	    goto L200;
	}
/* SOURCE fequtl.for:469 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:470 */
/*<       if(wflag.eq.0)write(stdout,54) >*/
    if (*wflag == 0) {
	feq_gen_io_d__36.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__36);
	e_wsfe();
    }
/* SOURCE fequtl.for:471 */
/*<       return >*/
    return 0;
/* SOURCE fequtl.for:472 */
/*<       end >*/
} /* chkcfc_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fequtl.for:476 */
/*<       subroutinenxtcmd(stdin,stdout,ncmd,cmdtab,cmdval,next) >*/
/* Subroutine */ int nxtcmd_(integer *stdin, integer *stdout, integer *ncmd, 
	char *feq_storage_cmdtab, integer *feq_storage_cmdval, integer *next, ftnlen cmdtab_len)
{
    /* Initialized data */

    static char blank[8+1] = "        ";

    /* Format strings */
    static char fmt_1[] = "(10a8)";
    static char fmt_51[] = "(\002 \002,10a8)";
    static char fmt_52[] = "(/,\002 End of file before FINISH found.  FINISH\
 supplied.\002)";

    /* System generated locals */
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(), 
	    s_wsfe(cilist *), e_wsfe(), s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    char card[8*10], line[80];
    integer index;
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen),
	     binser_(char *, integer *, char *, integer *, ftnlen, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__40 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__41 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__43 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__44 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Read next command, skipping blank commands as needed, and */
/*     determine action by defining NEXT. */
/* SOURCE fequtl.for:484 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fequtl.for:487 */
/*<       integerncmd,next,stdin,stdout >*/
/* SOURCE fequtl.for:488 */
/*<       integercmdval(ncmd) >*/
/* SOURCE fequtl.for:489 */
/*<       charactercmdtab(ncmd)*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     NCMD   - Number of commands */
/*     CMDTAB - Vector holding the command names */
/*     CMDVAL - Vector holding the command value for branching */
/*     NEXT   - Code for the next command */
/*     + + + SAVED VALUES + + + */
/* SOURCE fequtl.for:500 */
/*<       characterblank*8 >*/
/* SOURCE fequtl.for:501 */
/*<       saveblank >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fequtl.for:504 */
/*<       integerindex >*/
/* SOURCE fequtl.for:505 */
/*<       charactercard(10)*8,line*80 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fequtl.for:508 */
/*<       externalbinser,inline >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + INPUT FORMATS + + + */
/* SOURCE fequtl.for:511 */
/*<       datablank/'        '/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> cmdval(feq_storage_cmdval, 1);

    feq::IndexedPointer<char> cmdtab(feq_storage_cmdtab, 8);

    /* Function Body */
/* SOURCE fequtl.for:514 */
/*<     1 format(10a8) >*/
/* L1: */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fequtl.for:517 */
/*<    51 format(' ',10a8) >*/
/* L51: */
/* SOURCE fequtl.for:518 */
/*<    52 format(/,' End of file before FINISH found.  FINISH supplied.') >*/
/* L52: */
/* *********************************************************************** */
/* SOURCE fequtl.for:520 */
/*<   100 continue >*/
L100:
/* SOURCE fequtl.for:521 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE fequtl.for:524 */
/*<       read(line,1)card >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_1;
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_10, card, (ftnlen)8);
    e_rsfi();
/* SOURCE fequtl.for:525 */
/*<       write(stdout,51)card >*/
    feq_gen_io_d__40.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__40);
    do_fio(&feq_gen_c_d_10, card, (ftnlen)8);
    e_wsfe();
/* SOURCE fequtl.for:526 */
/*<       if(card(1).eq.blank)goto100 >*/
    if (s_cmp(card, blank, (ftnlen)8, (ftnlen)8) == 0) {
	goto L100;
    }
/* SOURCE fequtl.for:528 */
/*<       if(card(1).eq.'ENDFILE')then >*/
    if (s_cmp(card, const_cast<char*>("ENDFILE"), (ftnlen)8, (ftnlen)7) == 0) {
/*       End of file found before next command.  Missing FINISH. */
/* SOURCE fequtl.for:530 */
/*<       write(stdout,52) >*/
	feq_gen_io_d__41.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__41);
	e_wsfe();
/* SOURCE fequtl.for:531 */
/*<       card(1)='FINISH' >*/
	s_copy(card, const_cast<char*>("FINISH"), (ftnlen)8, (ftnlen)6);
/* SOURCE fequtl.for:532 */
/*<       endif >*/
    }
/*     FIND COMMAND IN CMDTAB */
/* SOURCE fequtl.for:535 */
/*<       callbinser(card(1),ncmd,cmdtab,index) >*/
    binser_(card, ncmd, cmdtab + 8, &index, (ftnlen)8, (ftnlen)8);
/* SOURCE fequtl.for:539 */
/*<       if(index.le.0)then >*/
    if (index <= 0) {
/* SOURCE fequtl.for:540 */
/*<       next=0 >*/
	*next = 0;
/* SOURCE fequtl.for:541 */
/*<       elseif(index.le.ncmd)then >*/
    } else if (index <= *ncmd) {
/* SOURCE fequtl.for:542 */
/*<       next=cmdval(index) >*/
	*next = cmdval[index];
/* SOURCE fequtl.for:543 */
/*<       else >*/
    } else {
/* SOURCE fequtl.for:544 */
/*<       write(stdout,*)' ADDRESS PROBLEM IN NXTCMD' >*/
	feq_gen_io_d__43.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__43);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" ADDRESS PROBLEM IN NXTCMD"), (ftnlen)26);
	e_wsle();
/* SOURCE fequtl.for:545 */
/*<       write(stdout,*)' INDEX=',index >*/
	feq_gen_io_d__44.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__44);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" INDEX="), (ftnlen)7);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&index, (ftnlen)sizeof(integer));
	e_wsle();
/* SOURCE fequtl.for:546 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE fequtl.for:547 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:549 */
/*<       return >*/
    return 0;
/* SOURCE fequtl.for:550 */
/*<       end >*/
} /* nxtcmd_ */




/* SOURCE fequtl.for:554 */
/*<       subroutinechktab(ctype,lout,ftpnt,mft,tab,eflag) >*/
/* Subroutine */ int chktab_(integer *ctype, integer *lout, integer *feq_storage_ftpnt, 
	integer *mft, integer *tab, integer *eflag)
{
    /* Format strings */
    static char fmt_1[] = "(/,\002 *ERR:81* TABID = \002,a,\002 does not exi\
st.\002)";
    static char fmt_2[] = "(/,\002 *ERR:82* TABLE# = \002,i5,\002 too large.\
 Set to current\002,\002 maximum of:\002,i5)";
    static char fmt_50[] = "(/,\002 *BUG:XXX* Table number mismatch: Externa\
l=\002,i5,\002 Internal=\002,i5,\002 Address=\002,i10)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_stop(char *
	    , ftnlen);

    /* Local variables */
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer adrs;
    char char16[16];
    extern integer gettbn_(integer *);
    extern /* Subroutine */ int chktyp_(integer *, integer *, integer *, 
	    integer *);
    extern integer lenstr_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__45 = { 0, 0, 0, fmt_2, 0 };
    static cilist feq_gen_io_d__48 = { 0, 0, 0, fmt_1, 0 };
    static cilist feq_gen_io_d__49 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Checks for address of a table and returns its address in place of */
/*     TAB.  Otherwise writes error and sets TAB = 1 on return. */
/*     IF TAB = 0 on entry return without doing anything. */
/* SOURCE fequtl.for:564 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fequtl.for:567 */
/*<       integerctype,eflag,lout,mft,tab >*/
/* SOURCE fequtl.for:568 */
/*<       integerftpnt(mft) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     CTYPE  - type class number for checking valid table types */
/*     LOUT   - Fortran unit number for user output and messages */
/*     FTPNT  - function table pointer giving the table address for each */
/*              table number.  If the address is zero the table does not */
/*              exist. */
/*     MFT    - Maximum allowed table number */
/*     TAB    - Table number */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     Common blocks */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fequtl.for:584 */
/*<       integeradrs >*/
/* SOURCE fequtl.for:585 */
/*<       characterchar16*16 >*/
/*     External Functions */
/* SOURCE fequtl.for:590 */
/*<       integergettbn >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fequtl.for:593 */
/*<       integerlenstr >*/
/* SOURCE fequtl.for:594 */
/*<       characterget_tabid*16 >*/
/* SOURCE fequtl.for:595 */
/*<       externalchktyp,gettbn,get_tabid,lenstr >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fequtl.for:598 */
/*<     1 format(/,' *ERR:81* TABID = ',a,' does not exist.') >*/
/* SOURCE fequtl.for:599 */
/*<     2  >*/
/* SOURCE fequtl.for:601 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE fequtl.for:604 */
/*<       if(tab.eq.0)return >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> ftpnt(feq_storage_ftpnt, 1);

    /* Function Body */
/* L1: */
/* L2: */
/* L50: */
    if (*tab == 0) {
	return 0;
    }
/*     MAKE SURE TABLE NUMBER IS IN VALID RANGE */
/* SOURCE fequtl.for:608 */
/*<       if(tab.gt.mft)then >*/
    if (*tab > *mft) {
/* SOURCE fequtl.for:609 */
/*<       write(lout,2)tab,mft >*/
	feq_gen_io_d__45.ciunit = *lout;
	s_wsfe(&feq_gen_io_d__45);
	do_fio(&feq_gen_c_d_1, (char *)&(*tab), (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&(*mft), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE fequtl.for:610 */
/*<       tab=mft >*/
	*tab = *mft;
/* SOURCE fequtl.for:611 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE fequtl.for:612 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:614 */
/*<       adrs=ftpnt(tab) >*/
    adrs = ftpnt[*tab];
/* SOURCE fequtl.for:616 */
/*<       if(adrs.gt.0)goto10 >*/
    if (adrs > 0) {
	goto L10;
    }
/* SOURCE fequtl.for:617 */
/*<       char16=get_tabid(tab) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, tab);
    s_copy(char16, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE fequtl.for:618 */
/*<       write(lout,1)char16(1:lenstr(char16)) >*/
    feq_gen_io_d__48.ciunit = *lout;
    s_wsfe(&feq_gen_io_d__48);
    do_fio(&feq_gen_c_d_1, char16, lenstr_(char16, (ftnlen)16));
    e_wsfe();
/* SOURCE fequtl.for:619 */
/*<       eflag=1 >*/
    *eflag = 1;
/* SOURCE fequtl.for:620 */
/*<       tab=1 >*/
    *tab = 1;
/* SOURCE fequtl.for:621 */
/*<       return >*/
    return 0;
/* SOURCE fequtl.for:622 */
/*<    10 continue >*/
L10:
/* SOURCE fequtl.for:623 */
/*<       if(tab.ne.gettbn(adrs))then >*/
    if (*tab != gettbn_(&adrs)) {
/* SOURCE fequtl.for:624 */
/*<       write(lout,50)tab,gettbn(adrs),adrs >*/
	feq_gen_io_d__49.ciunit = *lout;
	s_wsfe(&feq_gen_io_d__49);
	do_fio(&feq_gen_c_d_1, (char *)&(*tab), (ftnlen)sizeof(integer));
	feq_gen_i_d_1 = gettbn_(&adrs);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&adrs, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE fequtl.for:625 */
/*<       stop' Abnormal stop. Bug found.' >*/
	s_stop(const_cast<char*>(" Abnormal stop. Bug found."), (ftnlen)26);
/* SOURCE fequtl.for:626 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:627 */
/*<       tab=adrs >*/
    *tab = adrs;
/* SOURCE fequtl.for:628 */
/*<       callchktyp(lout,adrs,ctype,eflag) >*/
    chktyp_(lout, &adrs, ctype, eflag);
/* SOURCE fequtl.for:631 */
/*<       return >*/
    return 0;
/* SOURCE fequtl.for:632 */
/*<       end >*/
} /* chktab_ */




/* SOURCE fequtl.for:636 */
/*<        >*/
/* Subroutine */ int insys_(integer *stdsys, integer *maxcmd, integer *narg, 
	integer *stdout, char *units, real *nfac, real *grav, integer *maxknt,
	 real *eps, integer *ncmd, char *feq_storage_cmdtab, integer *feq_storage_cmdval, ftnlen 
	units_len, ftnlen cmdtab_len)
{
    /* Initialized data */

    static char metric[8+1] = "METRIC  ";
    static char engl[8+1] = "ENGLISH ";

    /* Format strings */
    static char fmt_1[] = "(8x,2i5)";
    static char fmt_2[] = "(a8,i5)";
    static char fmt_4[] = "(8x,a8,1x,a8,f10.0,f10.0)";
    static char fmt_51[] = "(\0020*ERR:503* TOO MANY COMMANDS IN SYSTEM FILE\
. LIMIT=\002,i5)";
    static char fmt_52[] = "(\0020*ERR:613* \002,a8,\002 IS AN UNKNOWN UNITS\
 OPTION.\002)";
    static char fmt_54[] = "(/,\002 FEQUTL uses:\002,/,5x,\002 NFAC=\002,f10\
.6,\002 for Manning's equation.\002,/,5x,\002 GRAV=\002,f10.4,\002 for g.\
\002)";
    static char fmt_56[] = "(/,\002 NFAC and GRAV are nominal engineering va\
lues\002)";
    static char fmt_58[] = "(/,\002 NFAC is exact.  GRAV is for latitude \
\002,f5.1,\002 degrees and elevation \002,f6.0)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[8];
    icilist feq_gen_ici_d_1;
    alist feq_gen_al_d_1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), f_back(alist *), s_rsfi(
	    icilist *), do_fio(integer *, char *, ftnlen), e_rsfi();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double cos(doublereal);
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    real latitude;
    integer j;
    char feq_gen_nfac_flag_d_[8];
    real elevation;
    char line[80];
    extern /* Subroutine */ int sort2_(integer *, char *, integer *, ftnlen), 
	    grule_(integer *, doublereal *, doublereal *), inline_(integer *, 
	    integer *, char *, ftnlen);
    extern /* Character */ VOID gettok_(char *, ftnlen, char *, ftnlen);
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__56 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__57 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__58 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__59 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__60 = { 0, 0, 0, fmt_51, 0 };


/*     + + + PURPOSE + + + */
/*     Input the default control values for the program. */
/* SOURCE fequtl.for:644 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fequtl.for:647 */
/*<       integermaxcmd,maxknt,narg,ncmd,stdin,stdout,stdsys,stdtab >*/
/* SOURCE fequtl.for:648 */
/*<       integercmdval(maxcmd) >*/
/* SOURCE fequtl.for:649 */
/*<       realeps,grav,nfac >*/
/* SOURCE fequtl.for:650 */
/*<       charactercmdtab(maxcmd)*8,units*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDSYS - Fortran unit number for system table definition */
/*     MAXCMD - Maximum number of commands */
/*     NARG   - Number of command line arguments found */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     UNITS  - Definition of the unit system: ENGLISH or METRIC */
/*     NFAC   - Factor in Manning's formula(1.49 or 1.0) */
/*     GRAV   - value of acceleration due to gravity */
/*     MAXKNT - Iteration count limit */
/*     EPS    - Convergence tolerance */
/*     NCMD   - Number of commands */
/*     CMDTAB - Vector holding the command names */
/*     CMDVAL - Vector holding the command value for branching */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fequtl.for:669 */
/*     COMMON FOR GAUSSIAN NUMERICAL INTEGRATION RULE */
/* SOURCE gnicom.cmn:3 */
/*<       integerpmxngs >*/
/* SOURCE gnicom.cmn:4 */
/*<       parameter(pmxngs=21) >*/
/* SOURCE gnicom.cmn:6 */
/*<       integerngs >*/
/* SOURCE gnicom.cmn:8 */
/*<       doubleprecisionwgs(pmxngs),xgs(pmxngs) >*/
/* SOURCE gnicom.cmn:11 */
/*<       common/gnicom/wgs,xgs,ngs >*/
/* SOURCE gnicom.cmn:14 */
/*<       save/gnicom/ >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE fequtl.for:672 */
/*<       characterengl*8,metric*8 >*/
/* SOURCE fequtl.for:673 */
/*<       saveengl,metric >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fequtl.for:676 */
/*<       integerj >*/
/* SOURCE fequtl.for:677 */
/*<       reallatitude,elevation >*/
/* SOURCE fequtl.for:678 */
/*<       characterdummy*8,nfac_flag*8,line*80 >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE fequtl.for:681 */
/*<       charactergettok*8 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fequtl.for:684 */
/*<       externalgettok,grule,sort2,strip_l_blanks,inline >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + INPUT FORMATS + + + */
/* SOURCE fequtl.for:687 */
/*<       datametric/'METRIC'/,engl/'ENGLISH'/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> cmdval(feq_storage_cmdval, 1);

    feq::IndexedPointer<char> cmdtab(feq_storage_cmdtab, 8);

    /* Function Body */
/* SOURCE fequtl.for:690 */
/*<     1 format(8x,2i5) >*/
/* L1: */
/* SOURCE fequtl.for:691 */
/*<     2 format(a8,i5) >*/
/* L2: */
/* SOURCE fequtl.for:692 */
/*<     3 format(8x,a8) >*/
/* L3: */
/* SOURCE fequtl.for:693 */
/*<     4 format(8x,a8,1x,a8,f10.0,f10.0) >*/
/* L4: */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fequtl.for:696 */
/*<    51 format('0*ERR:503* TOO MANY COMMANDS IN SYSTEM FILE. LIMIT=',i5) >*/
/* L51: */
/* SOURCE fequtl.for:698 */
/*<    52 format('0*ERR:613* ',a8,' IS AN UNKNOWN UNITS OPTION.') >*/
/* L52: */
/* SOURCE fequtl.for:699 */
/*<    54  >*/
/* L54: */
/* SOURCE fequtl.for:702 */
/*<    56 format(/,' NFAC and GRAV are nominal engineering values') >*/
/* L56: */
/* SOURCE fequtl.for:703 */
/*<    58  >*/
/* L58: */
/* *********************************************************************** */
/*     SKIP THE NEXT THREE CARDS OF INFORMATION */
/* SOURCE fequtl.for:708 */
/*<       callinline(stdsys,stdout,line) >*/
    inline_(stdsys, stdout, line, (ftnlen)80);
/* SOURCE fequtl.for:712 */
/*<       if(line(1:5).eq.'STDIN')then >*/
    if (s_cmp(line, const_cast<char*>("STDIN"), (ftnlen)5, (ftnlen)5) == 0) {
/*       Read two more lines to skip over obselete information */
/* SOURCE fequtl.for:714 */
/*<       callinline(stdsys,stdout,line) >*/
	inline_(stdsys, stdout, line, (ftnlen)80);
/* SOURCE fequtl.for:717 */
/*<       callinline(stdsys,stdout,line) >*/
	inline_(stdsys, stdout, line, (ftnlen)80);
/* SOURCE fequtl.for:720 */
/*<       else >*/
    } else {
/* SOURCE fequtl.for:721 */
/*<       backspace(stdsys) >*/
	feq_gen_al_d_1.aerr = 0;
	feq_gen_al_d_1.aunit = *stdsys;
	f_back(&feq_gen_al_d_1);
/* SOURCE fequtl.for:722 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:724 */
/*<       callinline(stdsys,stdout,line) >*/
    inline_(stdsys, stdout, line, (ftnlen)80);
/* SOURCE fequtl.for:727 */
/*<       read(line,4)units,nfac_flag,latitude,elevation >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_4;
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, units, (ftnlen)8);
    do_fio(&feq_gen_c_d_1, feq_gen_nfac_flag_d_, (ftnlen)8);
    do_fio(&feq_gen_c_d_1, (char *)&latitude, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&elevation, (ftnlen)sizeof(real));
    e_rsfi();
/* SOURCE fequtl.for:728 */
/*<       latitude=latitude*1.7453293e-2 >*/
    latitude *= static_cast<double>((float).017453293);
/* SOURCE fequtl.for:729 */
/*<       units=gettok(units) >*/
    gettok_(feq_gen_ch_d_1, (ftnlen)8, units, (ftnlen)8);
    s_copy(units, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE fequtl.for:731 */
/*<       callstrip_l_blanks(nfac_flag) >*/
    feq_gen_strip_l_blanks_d_(feq_gen_nfac_flag_d_, (ftnlen)8);
/* SOURCE fequtl.for:734 */
/*<       if(units.eq.engl)then >*/
    if (s_cmp(units, engl, (ftnlen)8, (ftnlen)8) == 0) {
/* SOURCE fequtl.for:735 */
/*<       if(nfac_flag.eq.' '.or.nfac_flag.eq.'NOMINAL')then >*/
	if (s_cmp(feq_gen_nfac_flag_d_, const_cast<char*>(" "), (ftnlen)8, (ftnlen)1) == 0 || s_cmp(
		feq_gen_nfac_flag_d_, const_cast<char*>("NOMINAL"), (ftnlen)8, (ftnlen)7) == 0) {
/*         Use the approximate value */
/* SOURCE fequtl.for:737 */
/*<       nfac=1.49 >*/
	    *nfac = (float)1.49;
/* SOURCE fequtl.for:738 */
/*<       grav=32.2 >*/
	    *grav = (float)32.2;
/* SOURCE fequtl.for:739 */
/*<       else >*/
	} else {
/*         Use the "exact" value */
/* SOURCE fequtl.for:741 */
/*<       nfac=1.485919 >*/
	    *nfac = (float)1.485919;
/* SOURCE fequtl.for:742 */
/*<       grav=32.1726-0.08495*cos(2.*latitude)-3.09e-6*elevation >*/
	    *grav = (float)32.1726 - cos(static_cast<double>(latitude) * (float)2.) * (float)
		    .08495 - static_cast<double>(elevation) * (float)3.09e-6;
/* SOURCE fequtl.for:744 */
/*<       endif >*/
	}
/* SOURCE fequtl.for:745 */
/*<       elseif(units.eq.metric)then >*/
    } else if (s_cmp(units, metric, (ftnlen)8, (ftnlen)8) == 0) {
/* SOURCE fequtl.for:746 */
/*<       nfac=1. >*/
	*nfac = (float)1.;
/* SOURCE fequtl.for:747 */
/*<       if(nfac_flag.eq.' '.or.nfac_flag.eq.'NOMINAL')then >*/
	if (s_cmp(feq_gen_nfac_flag_d_, const_cast<char*>(" "), (ftnlen)8, (ftnlen)1) == 0 || s_cmp(
		feq_gen_nfac_flag_d_, const_cast<char*>("NOMINAL"), (ftnlen)8, (ftnlen)7) == 0) {
/*         Make GRAV consistent with 32.2! */
/* SOURCE fequtl.for:749 */
/*<       grav=9.81456 >*/
	    *grav = (float)9.81456;
/* SOURCE fequtl.for:750 */
/*<       else >*/
	} else {
/* SOURCE fequtl.for:751 */
/*<       grav=32.1726-0.08495*cos(2.*latitude)-3.09e-6*elevation/0.3048 >*/
	    *grav = (float)32.1726 - cos(static_cast<double>(latitude) * (float)2.) * (float)
		    .08495 - static_cast<double>(static_cast<double>(elevation) * (float)3.09e-6) / (float).3048;
/* SOURCE fequtl.for:753 */
/*<       grav=grav*0.3048 >*/
	    *grav *= static_cast<double>((float).3048);
/* SOURCE fequtl.for:754 */
/*<       endif >*/
	}
/* SOURCE fequtl.for:755 */
/*<       else >*/
    } else {
/* SOURCE fequtl.for:756 */
/*<       write(stdout,52)units >*/
	feq_gen_io_d__56.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__56);
	do_fio(&feq_gen_c_d_1, units, (ftnlen)8);
	e_wsfe();
/* SOURCE fequtl.for:757 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE fequtl.for:758 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:760 */
/*<       write(stdout,54)nfac,grav >*/
    feq_gen_io_d__57.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__57);
    do_fio(&feq_gen_c_d_1, (char *)&(*nfac), (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&(*grav), (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE fequtl.for:762 */
/*<       if(nfac_flag.eq.' '.or.nfac_flag.eq.'NOMINAL')then >*/
    if (s_cmp(feq_gen_nfac_flag_d_, const_cast<char*>(" "), (ftnlen)8, (ftnlen)1) == 0 || s_cmp(
	    feq_gen_nfac_flag_d_, const_cast<char*>("NOMINAL"), (ftnlen)8, (ftnlen)7) == 0) {
/* SOURCE fequtl.for:763 */
/*<       write(stdout,56) >*/
	feq_gen_io_d__58.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__58);
	e_wsfe();
/* SOURCE fequtl.for:764 */
/*<       else >*/
    } else {
/* SOURCE fequtl.for:765 */
/*<       write(stdout,58)latitude*57.29578,elevation >*/
	feq_gen_io_d__59.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__59);
	feq_gen_r_d_1 = static_cast<double>(latitude) * (float)57.29578;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&elevation, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE fequtl.for:766 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:767 */
/*<       callinline(stdsys,stdout,line) >*/
    inline_(stdsys, stdout, line, (ftnlen)80);
/* SOURCE fequtl.for:770 */
/*<       read(line,1)ncmd,ngs >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_1;
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*ncmd), (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&gnicom_1.ngs, (ftnlen)sizeof(integer));
    e_rsfi();
/* SOURCE fequtl.for:771 */
/*<       if(ngs.eq.0)ngs=5 >*/
    if (gnicom_1.ngs == 0) {
	gnicom_1.ngs = 5;
    }
/* SOURCE fequtl.for:773 */
/*<       if(ncmd.le.maxcmd)goto90 >*/
    if (*ncmd <= *maxcmd) {
	goto L90;
    }
/* SOURCE fequtl.for:774 */
/*<       write(stdout,51)maxcmd >*/
    feq_gen_io_d__60.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__60);
    do_fio(&feq_gen_c_d_1, (char *)&(*maxcmd), (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE fequtl.for:775 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE fequtl.for:776 */
/*<    90 continue >*/
L90:
/* SOURCE fequtl.for:778 */
/*<       do100j=1,ncmd >*/
    feq_gen_i_d_1 = *ncmd;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE fequtl.for:779 */
/*<       callinline(stdsys,stdout,line) >*/
	inline_(stdsys, stdout, line, (ftnlen)80);
/* SOURCE fequtl.for:782 */
/*<       read(line,2)cmdtab(j),cmdval(j) >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_2;
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, cmdtab + (j << 3), (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&cmdval[j], (ftnlen)sizeof(integer));
	e_rsfi();
/* SOURCE fequtl.for:783 */
/*<       cmdtab(j)=gettok(cmdtab(j)) >*/
	gettok_(feq_gen_ch_d_1, (ftnlen)8, cmdtab + (j << 3), (ftnlen)8);
	s_copy(cmdtab + (j << 3), feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE fequtl.for:784 */
/*<   100 continue >*/
/* L100: */
    }
/*     SORT THE COMMANDS IN ASCENDING ORDER */
/* SOURCE fequtl.for:788 */
/*<       callsort2(ncmd,cmdtab,cmdval) >*/
    sort2_(ncmd, cmdtab + 8, &cmdval[1], (ftnlen)8);
/* SOURCE fequtl.for:792 */
/*<       maxknt=10 >*/
    *maxknt = 10;
/* SOURCE fequtl.for:793 */
/*<       eps=0.005 >*/
    *eps = (float).005;
/*     COMPUTE THE RULE FOR GAUSSIAN INTEGRATION */
/* SOURCE fequtl.for:797 */
/*<       callgrule(ngs,xgs,wgs) >*/
    grule_(&gnicom_1.ngs, gnicom_1.xgs, gnicom_1.wgs);
/* SOURCE fequtl.for:801 */
/*<       return >*/
    return 0;
/* SOURCE fequtl.for:802 */
/*<       end >*/
} /* insys_ */




/* SOURCE fequtl.for:806 */
/*<       subroutineget_single_named_item(stdout,line,name,item,eflag) >*/
/* Subroutine */ int feq_gen_get_single_named_item_d_(integer *stdout, char *line, 
	char *feq_gen_name_d_, char *item, integer *eflag, ftnlen line_len, ftnlen 
	name_len, ftnlen item_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002*ERR:XXX* Equal sign missing after name\
=\002,a)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer ieq;
    extern /* Subroutine */ int feq_gen_feq_adjustl_d_(char *, char *, ftnlen, ftnlen);
    integer iend;
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__64 = { 0, 0, 0, fmt_50, 0 };


/*     Get a single named item on the line */
/* SOURCE fequtl.for:811 */
/*<       implicitnone >*/
/* SOURCE fequtl.for:813 */
/*<       integerstdout,eflag >*/
/* SOURCE fequtl.for:815 */
/*<       character*(*)line,name,item >*/
/*     Local */
/* SOURCE fequtl.for:818 */
/*<       integerieq,iend >*/
/*     ***************************formats******************************** */
/* SOURCE fequtl.for:806 */
/*<       integer feq_len_trim >*/
/* SOURCE fequtl.for:806 */
/*<       external feq_len_trim >*/
/* SOURCE fequtl.for:821 */
/*<    50 format(/,'*ERR:XXX* Equal sign missing after name=',a) >*/
/* *********************************************************************** */
/* SOURCE fequtl.for:823 */
/*<       ieq=index(line,'=') >*/
/* L50: */
    ieq = i_indx(line, const_cast<char*>("="), line_len, (ftnlen)1);
/* SOURCE fequtl.for:824 */
/*<       if(ieq==0)then >*/
    if (ieq == 0) {
/*       Missing delimiter */
/* SOURCE fequtl.for:826 */
/*<       callfeq_adjustl(line,name) >*/
	feq_gen_feq_adjustl_d_(line, feq_gen_name_d_, line_len, name_len);
/* SOURCE fequtl.for:827 */
/*<       iend=feq_len_trim(name) >*/
	iend = feq_gen_feq_len_trim_d_(feq_gen_name_d_, name_len);
/* SOURCE fequtl.for:828 */
/*<       write(stdout,50)name(1:iend) >*/
	feq_gen_io_d__64.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__64);
	do_fio(&feq_gen_c_d_1, feq_gen_name_d_, iend);
	e_wsfe();
/* SOURCE fequtl.for:829 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE fequtl.for:830 */
/*<       else >*/
    } else {
/* SOURCE fequtl.for:831 */
/*<       callfeq_adjustl(line(1:ieq-1),name) >*/
	feq_gen_feq_adjustl_d_(line, feq_gen_name_d_, ieq - 1, name_len);
/* SOURCE fequtl.for:832 */
/*<       callfeq_adjustl(line(ieq+1:),item) >*/
	feq_gen_i_d_1 = ieq;
	feq_gen_feq_adjustl_d_(line + feq_gen_i_d_1, item, line_len - feq_gen_i_d_1, item_len);
/* SOURCE fequtl.for:833 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:835 */
/*<       return >*/
    return 0;
/* SOURCE fequtl.for:836 */
/*<       end >*/
} /* get_single_named_item__ */




/* SOURCE fequtl.for:841 */
/*<       subroutineset_version() >*/
/* Subroutine */ int feq_gen_set_version_d_()
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     Sets the current version number and date in the version */
/*     common block */
/* INCLUDE fequtl.for:846 */
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
/* *********************************************************************** */
/* SOURCE fequtl.for:848 */
/*<       version_number=5.80 >*/
    version_1.feq_gen_version_number_d_ = (float)5.8;
/* SOURCE fequtl.for:849 */
/*<       version_date='6 October 2008' >*/
    s_copy(versionc_1.feq_gen_version_date_d_, const_cast<char*>("6 October 2008"), (ftnlen)17, (ftnlen)
	    14);
/* SOURCE fequtl.for:850 */
/*<       return >*/
    return 0;
/* SOURCE fequtl.for:851 */
/*<       end >*/
} /* set_version__ */




/* SOURCE fequtl.for:855 */
/*<       programfequtl >*/
/* Main program */ int feq_gen_MAIN_d_()
{
    /* Format strings */
    static char fmt_40[] = "(7x,f10.0)";
    static char fmt_41[] = "(7x,a3)";
    static char fmt_42[] = "(9x,a3)";
    static char fmt_44[] = "(7x,f10.0)";
    static char fmt_45[] = "(a64)";
    static char fmt_46[] = "(5x,f10.0,1x,7x,f10.0)";
    static char fmt_49[] = "(6x,f10.0)";
    static char fmt_51[] = "(\0020*ERR:501* Unknown command.\002)";
    static char fmt_52[] = "(\002 *NOTE* Known command found after error.\
\002)";
    static char fmt_54[] = "(\0020*WRN:518* One or more errors found. Table \
file is \002,\002incomplete or invalid.\002)";
    static char fmt_56[] = "(/,\002 Global values: ZONE=\002,a8,\002 HGRID\
=\002,a8,\002 VDATUM=\002,a8,\002 UNITSYS=\002,a8,\002 BASIS=\002,a8)";
    static char fmt_70[] = "(\002 DZLIM=\002,f10.6,\002 NRZERO=\002,f10.6\
,\002 USGSBETA=\002,a3)";
    static char fmt_72[] = "(\002 Version: \002,f6.2,\002 Version date: \002\
,a17,5x,\002Date/time of run: \002,a4,\002/\002,a2,\002/\002,a2,\002: \002,a\
2,\002.\002,a2,\002.\002,a6)";
    static char fmt_74[] = "(\002 *WRN:526* INVALID RESPONSE FOR USGSBETA. T\
AKEN AS:NO\002)";
    static char fmt_76[] = "(\002 EPSARG=\002,1pe10.4,/,\002 EPSF=\002,1pe10\
.4,\002 EPSABS=\002,1pe10.4)";
    static char fmt_77[] = "(\002*WRN:558 Vertical extension of a cross sect\
ion end in\002,\002 order to match\002,/,10x,\002 the other end's elevation \
may lead\002,\002 to nonsense results.\002)";
    static char fmt_78[] = "(/,\002 Automatic cross section extension to mat\
ch end\002,\002 elevations selected.\002)";
    static char fmt_79[] = "(/,\002 No automatic cross section extension.  C\
ross section\002,/,5x,\002 table arguments limited to minimum end elevation\
.\002)";
    static char fmt_80[] = "(\002 *WRN:559* Invalid response for EXTEND.  Ta\
ken as: NO\002)";
    static char fmt_81[] = "(/,\002 EXTEND, the cross section extension opti\
on, missing.\002,\002 Extension assumed.\002,/,4x,\002EXTEND appears after E\
SPF in the\002,\002 input.  Options are:\002,/,4x,\002EXTEND=NO- cross secti\
on table\002,\002 arguments limited to minimum\002,/,4x,\002of the two end p\
oint\002,\002 elevations.\002,/,4x,\002EXTEND=YES- lower elevation end poin\
t\002,\002 extended to higher elevation.\002,/,4x,\002Previous versions\002\
,\002 used EXTEND=YES by default.\002)";
    static char fmt_82[] = "(/,\002 Global home name is: \002,a)";
    static char fmt_83[] = "(/,\002 FEQUTL configuration from conf file: \
\002,a)";
    static char fmt_84[] = "(/,\002 FEQUTL configuration from master-input f\
ile.\002)";
    static char fmt_85[] = "(/,\002 Master-input file: \002,a,/,\002 Master-\
output file: \002,a,/,\002 Function-table file: \002,a)";
    static char fmt_86[] = "(/,\002;Version number is \002,i8,\002 for the S\
ubversion working \002,\002copy\002)";
    static char fmt_87[] = "(/,\002;*WRN:XXX* The working copy contains loca\
l \002,\002modifications.\002,/,\002;\002,5x,\002The version number given is\
 therefore\002,\002 not current and may not properly\002,/,\002;\002,5x,\002\
provide the version\002,\002 number required to retrieve all the same files\
 \002,\002at a later time.\002)";
    static char fmt_88[] = "(\002; Global home name is: \002,a)";
    static char fmt_89[] = "(\002; Local home name is: \002,a)";
    static char fmt_90[] = "(\002  Processing FTABIN\002)";
    static char fmt_91[] = "(/,\002 EPSABS is missing or zero.  Value set to\
 EPSF.\002,/,\002 Check input and add EPSABS after EPSF on the same line.\
\002)";
    static char fmt_92[] = "(/,\002 Minimum flow target for EMBANKQ and CHAN\
RAT=\002,f10.3)";
    static char fmt_93[] = "(1x,a16,1x,a16,4x,a4,f13.2,4x,a8,2x,a8,2x,a8,f10\
.3,f10.1,f10.2)";
    static char fmt_94[] = "(/,\002 Table Id-------- GISID-----------  Fld\
Opt\002,\002 BF Elevation  FEQ Invert Left----- Right---- Loss-----\002,\002\
 FldwyArea FldwyVel-\002)";
    static char fmt_95[] = "(/,\002 Invalid number of command-line agruments\
: FEQUTL\002,/,\002 expects exactly one argument or exactly three arguments\
.\002,/,\002 If one argument is given, FEQUTL strips the last extension,\002\
,/,\002 if there is one, and appends .out and .tab respectivly to\002,/,\002\
 create the second and third file names.  Otherwise give\002,/,\002 three fi\
le names: (1) user-input file, (2) user-output file,\002,/,\002 and (3) func\
tion-table file.\002)";
    static char fmt_96[] = "(/,\002 The operating system cannot open the use\
r-output\002,/,\002 file: \002,a,\002.\002,\002  Check for invalid character\
s in the\002,/,\002 name.  If part or all of the path is given with the name,\
\002,/,\002 make sure that all directories exist as spelled.\002)";
    static char fmt_97[] = "(/,\002 The operating system cannot open the fun\
ction-table\002,/,\002 file: \002,a,\002.\002,\002  Check for invalid charac\
ters in the\002,/,\002 name.  If part or all of the path is given with the n\
ame,\002,/,\002 make sure that all directories exist as spelled.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    char feq_gen_ch_d_1[16];
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;
    olist feq_gen_o_d_1;
    alist feq_gen_al_d_1;
    inlist feq_gen_ioin_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe(),
	     f_inqu(inlist *), f_open(olist *), do_fio(integer *, char *, 
	    ftnlen), s_wsfi(icilist *), e_wsfi();
    double sqrt(doublereal);
    integer s_rsfi(icilist *), e_rsfi(), f_back(alist *), i_indx(char *, char 
	    *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int mkembank_(integer *, integer *, integer *), 
	    feq_gen_inv_gate_d_(real *, integer *, integer *, integer *, integer *, 
	    integer *), feq_gen_set_home_d_(char *, ftnlen);
    extern integer feq_gen_get_unit_d_(integer *);
    extern /* Subroutine */ int riserclv_(real *, integer *, integer *, 
	    integer *, integer *, integer *), feq_gen_set_slot_d_(integer *, integer *,
	     integer *);
    real velocity;
    extern /* Subroutine */ int feq_gen_make_standard_file_names_d_(char *, char *, 
	    char *, ftnlen, ftnlen, ftnlen);
    integer j, n, feq_gen_conf_flag_d_;
    extern /* Subroutine */ int feq_gen_initialize_units_d_();
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    char feq_gen_conf_file_d_[64], feq_gen_item_name_d_[8];
    extern /* Character */ VOID feq_gen_get_gisid_d_(char *, ftnlen, integer *);
    extern /* Subroutine */ int feq_gen_free_unit_d_(integer *, integer *);
    logical feq_gen_trk_files_d_;
    extern /* Subroutine */ int feq_gen_set_slote_d_(integer *, integer *, integer *), 
	    feq_gen_wpro14_new_d_(integer *, integer *, integer *, integer *, integer *
	    ), pumpitems_(char *, real *, integer *, integer *, integer *, 
	    integer *, integer *, ftnlen), feq_gen_find_md5_for_fequtl_input_d_(
	    integer *, integer *, integer *, integer *, char *, integer *, 
	    char *, integer *, char *, char *, ftnlen, ftnlen, ftnlen, ftnlen)
	    ;
    integer is;
    extern /* Subroutine */ int feq_gen_clear_home_d_(), makelakexs_(integer *, 
	    integer *, integer *), feq_gen_clear_slot_d_(integer *), feq_gen_getsvn_rev_d_(
	    integer *, char *, integer *, integer *, ftnlen);
    integer feq_gen_feql_index3_d_;
    extern /* Subroutine */ int feq_gen_svn_report_d_(integer *, integer *);
    char bot[8];
    real eps;
    integer ftp, ios;
    extern /* Subroutine */ int feq_gen_clear_ghome_d_(), feq_gen_feq_adjustl_d_(char *, char *,
	     ftnlen, ftnlen), feq_gen_set_version_d_();
    real nfac;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
    char date[8];
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ncmd, mode;
    char line[80], left[8];
    real minq;
    extern /* Subroutine */ int feqx_(integer *, integer *, integer *, real *,
	     integer *, integer *, integer *, integer *);
    char zeit[10], zone[5];
    integer next;
    extern /* Subroutine */ int fqxe_(integer *, integer *, integer *, real *,
	     integer *, integer *, integer *), init_();
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    extern integer feq_gen_feq_len_trim_d_(char *, ftnlen);
    extern /* Subroutine */ int hec2x_(integer *, integer *, integer *, real *
	    , integer *, integer *, integer *);
    char feq_gen_current_file_d_[128], fhead[91];
    integer cflag, gflag, itaba;
    char tabid[16];
    extern integer iargc_();
    char fname[64];
    integer table;
    extern /* Subroutine */ int fldin_(integer *, integer *, integer *, 
	    integer *, char *, ftnlen);
    char gisid[16];
    integer ftknt, stdin;
    real hslot;
    char reply[3], right[8], units[8], fname2[64], fname3[64], 
	    feq_gen_cmd_line_args_d_[64*11];
    logical there;
    extern /* Subroutine */ int critq_(real *, integer *, integer *, integer *
	    , integer *, integer *), insys_(integer *, integer *, integer *, 
	    integer *, char *, real *, real *, integer *, real *, integer *, 
	    char *, integer *, ftnlen, ftnlen), pipes_(integer *, integer *, 
	    integer *, real *, integer *, integer *, integer *), qclim_(
	    integer *, integer *, integer *), sewer_(integer *, integer *, 
	    integer *, real *, integer *, integer *, integer *), wpro14_(
	    integer *, integer *, integer *, integer *, integer *), wprox_(
	    integer *, integer *, integer *, real *, integer *, integer *, 
	    integer *), setcr_(), feq_gen_date_and_time_d_(char *, char *, char *, 
	    integer *, ftnlen, ftnlen, ftnlen), feq_gen_os_file_style_d_(char *, 
	    ftnlen), feq_gen_get_single_named_item_d_(integer *, char *, char *, char *
	    , integer *, ftnlen, ftnlen, ftnlen);
    char cmdtab[8*45];
    extern /* Subroutine */ int chanel_(integer *, integer *, integer *, real 
	    *, integer *, integer *, integer *, integer *), chntab_(integer *,
	     integer *, integer *, real *, real *, integer *, integer *, 
	    integer *), embank_(integer *, integer *, integer *, real *, 
	    integer *, integer *);
    integer feq_gen_stdext_option_d_;
    extern /* Subroutine */ int ftabin_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, char *, 
	    integer *, integer *, integer *, integer *, char *, ftnlen, 
	    ftnlen);
    integer tabdir[10007], cmdval[45], maxknt, stdfld, stdsys, stdtab, stdscr,
	     values[8];
    char nxtnam[128];
    extern /* Subroutine */ int culvrt_(integer *, integer *, integer *, real 
	    *, integer *, integer *, integer *, integer *), expcon_(integer *,
	     integer *, integer *, real *, integer *, integer *), getarg_(
	    integer *, char *, ftnlen), inline_(integer *, integer *, char *, 
	    ftnlen), mulcon_(integer *, integer *, integer *, real *, integer 
	    *, integer *, integer *), nxtcmd_(integer *, integer *, integer *,
	     char *, integer *, integer *, ftnlen), ritter_(real *, integer *,
	     integer *, integer *), spbrid_(integer *, integer *, integer *, 
	    real *, integer *, integer *), ufgate_(real *, integer *, integer 
	    *, integer *, integer *, integer *), wproqz_(integer *, integer *,
	     integer *), xstmak_(integer *, integer *, integer *, integer *, 
	    integer *, integer *), feq_gen_skip_header_if_present_d_(integer *, 
	    integer *, integer *, char *, ftnlen), lprfit_(integer *, integer 
	    *, integer *, integer *, integer *), orifice_(real *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), 
	    feq_gen_copy_master_input_file_d_(integer *, integer *);
    extern integer feq_gen_what_os_d_();
    extern /* Subroutine */ int ufgculv_(real *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), 
	    feq_gen_reset_kount_of_internal_tabids_d_(), feq_gen_what_executable_d_(integer *), 
	    mkwspro_(integer *, integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__79 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__85 = { 0, 6, 0, fmt_95, 0 };
    static cilist feq_gen_io_d__89 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__90 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__91 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__94 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__95 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__96 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__98 = { 0, 6, 0, fmt_96, 0 };
    static cilist feq_gen_io_d__99 = { 0, 6, 0, fmt_97, 0 };
    static cilist feq_gen_io_d__104 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__105 = { 0, 0, 0, fmt_85, 0 };
    static cilist feq_gen_io_d__107 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__108 = { 0, 0, 0, fmt_83, 0 };
    static cilist feq_gen_io_d__109 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__110 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__111 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__112 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__113 = { 0, 0, 0, fmt_84, 0 };
    static cilist feq_gen_io_d__122 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__123 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__124 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__125 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__126 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__128 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__129 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__130 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__131 = { 0, 0, 0, fmt_91, 0 };
    static cilist feq_gen_io_d__132 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__133 = { 0, 0, 0, fmt_81, 0 };
    static cilist feq_gen_io_d__134 = { 0, 0, 0, fmt_77, 0 };
    static cilist feq_gen_io_d__135 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__136 = { 0, 0, 0, fmt_77, 0 };
    static cilist feq_gen_io_d__137 = { 0, 0, 0, fmt_79, 0 };
    static cilist feq_gen_io_d__138 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__139 = { 0, 0, 0, fmt_79, 0 };
    static cilist feq_gen_io_d__141 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__142 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__144 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__145 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__146 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__147 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__148 = { 0, 0, 0, fmt_88, 0 };
    static cilist feq_gen_io_d__149 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__150 = { 0, 0, 0, fmt_87, 0 };
    static cilist feq_gen_io_d__152 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__155 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__156 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__157 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__158 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__161 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__162 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__163 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__171 = { 0, 0, 0, fmt_93, 0 };
    static cilist feq_gen_io_d__172 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__173 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__174 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__175 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__176 = { 0, 6, 0, fmt_90, 0 };
    static cilist feq_gen_io_d__180 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__181 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__182 = { 0, 0, 0, fmt_89, 0 };
    static cilist feq_gen_io_d__183 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__184 = { 0, 0, 0, fmt_87, 0 };
    static cilist feq_gen_io_d__185 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__186 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__187 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__188 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__189 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/* SOURCE fequtl.for:859 */
/*<       implicitnone >*/
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE fequtl.for:861 */
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
/* INCLUDE fequtl.for:862 */
/*     Command-line processing offset for most Unix-like systems */
/* SOURCE morg.prm:2 */
/*<       integermorg >*/
/* SOURCE morg.prm:3 */
/*<       parameter(morg=0) >*/
/*     MORG- offset value for the first command-line argument. */
/*           On PC systems this should be 1 if the supplied */
/*           routines for retrieval of command-line arguments */
/*           are used.  If the compiler differs from Lahey, */
/*           then the value should be set to get the first */
/*           file argument.  On Unix systems MORG=0 is normally */
/*           required. */
/* INCLUDE fequtl.for:863 */
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
/* INCLUDE fequtl.for:864 */
/*     FLOOD WAY COMMON BLOCK */
/* SOURCE fldway.cmn:3 */
/*<       character*4fldopt(pmxtab) >*/
/* SOURCE fldway.cmn:5 */
/*<       integerflood >*/
/* SOURCE fldway.cmn:7 */
/*<       realglbelv,glbcon >*/
/* SOURCE fldway.cmn:9 */
/*<        >*/
/* SOURCE fldway.cmn:13 */
/*<        >*/
/* SOURCE fldway.cmn:17 */
/*<       common/fldwyc/fldopt >*/
/* SOURCE fldway.cmn:19 */
/*<       save/fldwyc/,/fldway/ >*/
/* INCLUDE fequtl.for:865 */
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
/* INCLUDE fequtl.for:866 */
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
/* INCLUDE fequtl.for:867 */
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
/* INCLUDE fequtl.for:868 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE fequtl.for:869 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE fequtl.for:870 */
/*     COMMON BLOCK FOR COMMAND LINE PROCESSING FOR LAHEY COMPILER */
/* SOURCE clcom.cmn:3 */
/*<       common/clcomc/cl,namvec >*/
/* SOURCE clcom.cmn:4 */
/*<       character*127cl >*/
/* SOURCE clcom.cmn:5 */
/*<       character*64namvec(6) >*/
/* SOURCE clcom.cmn:7 */
/*<       common/clcom/iend,nxt,narg >*/
/* SOURCE clcom.cmn:8 */
/*<       integeriend,nxt,narg >*/
/* SOURCE clcom.cmn:10 */
/*<       save/clcom/ >*/
/* SOURCE clcom.cmn:11 */
/*<       save/clcomc/ >*/
/* INCLUDE fequtl.for:871 */
/*     NEAR ZERO DEPTH AND DZ COMMON.  ALSO HAS OTHER ITEMS */
/* SOURCE nrdzcm.cmn:3 */
/*<       integerextend,gxtend,nocm,iusgs >*/
/* SOURCE nrdzcm.cmn:5 */
/*<       realnrzero,dzlim,slot >*/
/* SOURCE nrdzcm.cmn:7 */
/*<       common/nrdzcm/nrzero,dzlim,nocm,slot,iusgs,extend,gxtend >*/
/* INCLUDE fequtl.for:872 */
/* ********************************************************************** */
/* SOURCE julian.cmn:3 */
/*<        >*/
/* SOURCE julian.cmn:8 */
/*<       integeryr,mn,dy,syr,smn,sdy,eyr,emn,edy,reset,leap,dmyear,dmmn >*/
/* SOURCE julian.cmn:10 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE fequtl.for:873 */
/*     Common block for table id's.  Position such that it can be */
/*     released at the proper time. */
/* SOURCE tabid.cmn:4 */
/*<       character*16tabid_table(mftnum) >*/
/* SOURCE tabid.cmn:5 */
/*<       integernum_tabid >*/
/* SOURCE tabid.cmn:7 */
/*<       common/tabid/num_tabid >*/
/* SOURCE tabid.cmn:8 */
/*<       common/tabidc/tabid_table >*/
/* INCLUDE fequtl.for:874 */
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
/* INCLUDE fequtl.for:875 */
/*     common for passing info for table upgrading-going from one form */
/*     to one that is smoother in its representation */
/* SOURCE tabupgrade.cmn:4 */
/*<       characterty13_to_ty43*4,twod_cubic_out*4,upgrade_xsec_tab*4 >*/
/* SOURCE tabupgrade.cmn:6 */
/*<       common/upgrdc/ty13_to_ty43,twod_cubic_out,upgrade_xsec_tab >*/
/* INCLUDE fequtl.for:876 */
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
/* INCLUDE fequtl.for:877 */
/*     Common to pass the os flag */
/* SOURCE whatos.cmn:3 */
/*<       integerosis >*/
/* SOURCE whatos.cmn:4 */
/*<       common/whatos/osis >*/
/* SOURCE whatos.cmn:6 */
/*<       save/whatos/ >*/
/* INCLUDE fequtl.for:878 */
/*     String that contains a string giving the version and date */
/*     of a run.  Will use to label output files that contain */
/*     text.  Binary file will require another approach! */
/* SOURCE datetime.cmn:5 */
/*<       character*95version_run_date_time_string >*/
/* SOURCE datetime.cmn:7 */
/*<       common/datetime/version_run_date_time_string >*/
/* SOURCE datetime.cmn:9 */
/*<       save/datetime/ >*/
/* INCLUDE fequtl.for:879 */
/*     Common to hold the global value for grid and datum values. */
/* SOURCE grid_datum.cmn:3 */
/*<       character*8g_zone,g_hgrid,g_vdatum,g_unitsys,g_basis >*/
/* SOURCE grid_datum.cmn:6 */
/*<       common/grid_datum/g_zone,g_hgrid,g_vdatum,g_unitsys,g_basis >*/
/*     g_zone- zone designation for the horizontal grid to be used. */
/*             For state plaine coordinates in the US this is an */
/*             integer number.  For example: 4601 denotes the */
/*             north zone in Washington.  The value is stored as */
/*             a string so that any 8 char sequence makes sense. */
/*             Currently, 5 Sept 2007, FEQ/FEQUTL just tracks the */
/*             zone information and does not check it. */
/*     g_hgrid- name for the horizontal grid.  Again a string of up */
/*              to eight characters.  Values that make sense include: */
/*              SPCS27- state plane coordinate system based on NAD 27, */
/*              SPCS83- state plane coordinate system based on NAD 83, */
/*              UTM27- universal transverse Mercator coordinate system */
/*              based on NAD 27, and UTM83-universal transverse Mercator */
/*              coordinate system based on NAD 83, etc */
/*     g_vdatum- the vertical datum: NGVD29, NAVD88, etc. */
/*     g_unitsys- unit system: ENGLISH or METRIC */
/*     g_basis- label for the source of the data the was used */
/*              to create the table.  For example, the year of */
/*              the survey, the name or date of a DTM that was */
/*              used, etc.  This makes it possible to track */
/*              the progress of changes as a model is updated */
/*              with more recently obtained geometric data. */
/* INCLUDE fequtl.for:880 */
/* SOURCE maketabindex.cmn:2 */
/*<       character*4make_tab_index >*/
/* SOURCE maketabindex.cmn:4 */
/*<       integerftab_type(mftnum),data_pnt(mftnum),index_knt,stdindex >*/
/* SOURCE maketabindex.cmn:7 */
/*<       characterftabid(mftnum)*16,ftab_fn(mftnum)*256 >*/
/* SOURCE maketabindex.cmn:9 */
/*<       common/mktbindxc/ftab_fn,ftabid,make_tab_index >*/
/* SOURCE maketabindex.cmn:10 */
/*<       common/mktbindx/ftab_type,data_pnt,index_knt,stdindex >*/
/* INCLUDE fequtl.for:881 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fequtl.for:884 */
/*<        >*/
/* SOURCE fequtl.for:888 */
/*<       integercmdval(maxcmd),tabdir(pmxtab+5),values(8) >*/
/* SOURCE fequtl.for:889 */
/*<       realeps,hslot,nfac,minq,velocity >*/
/* SOURCE fequtl.for:890 */
/*<        >*/
/* SOURCE fequtl.for:896 */
/*<       logicalthere,trk_files >*/
/*     + + + INTRINSICS + + + */
/* SOURCE fequtl.for:899 */
/*<       intrinsiciabs,sqrt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE fequtl.for:902 */
/*<       integeriargc,get_unit,what_os >*/
/* SOURCE fequtl.for:903 */
/*<       character*16get_tabid,get_gisid >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fequtl.for:906 */
/*<        >*/
/*     + + + INPUT FORMATS + + + */
/* SOURCE fequtl.for:855 */
/*<       integer feql_index3 >*/
/* SOURCE fequtl.for:855 */
/*<       integer feq_len_trim >*/
/* SOURCE fequtl.for:855 */
/*<       external feq_len_trim >*/
/* SOURCE fequtl.for:914 */
/*<    40 format(7x,f10.0) >*/
/* SOURCE fequtl.for:915 */
/*<    41 format(7x,a3) >*/
/* SOURCE fequtl.for:916 */
/*<    42 format(9x,a3) >*/
/* SOURCE fequtl.for:917 */
/*<    44 format(7x,f10.0) >*/
/* SOURCE fequtl.for:918 */
/*<    45 format(a64) >*/
/* SOURCE fequtl.for:919 */
/*<    46 format(5x,f10.0,1x,7x,f10.0) >*/
/* SOURCE fequtl.for:920 */
/*<    49 format(6x,f10.0) >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE fequtl.for:923 */
/*<    51 format('0*ERR:501* Unknown command.') >*/
/* SOURCE fequtl.for:924 */
/*<    52 format(' *NOTE* Known command found after error.') >*/
/* SOURCE fequtl.for:925 */
/*<    54  >*/
/* SOURCE fequtl.for:927 */
/*<    56  >*/
/* SOURCE fequtl.for:929 */
/*<    58 format(16x,'VDATUM_SHIFT=',f10.4) >*/
/* SOURCE fequtl.for:930 */
/*<    70 format(' DZLIM=',f10.6,' NRZERO=',f10.6,' USGSBETA=',a3) >*/
/* SOURCE fequtl.for:931 */
/*<    72  >*/
/* SOURCE fequtl.for:934 */
/*<    74 format(' *WRN:526* INVALID RESPONSE FOR USGSBETA. TAKEN AS:NO') >*/
/* SOURCE fequtl.for:935 */
/*<    76 format(' EPSARG=',1pe10.4,/,' EPSF=',1pe10.4,' EPSABS=',1pe10.4) >*/
/* SOURCE fequtl.for:936 */
/*<    77  >*/
/* SOURCE fequtl.for:939 */
/*<    78  >*/
/* SOURCE fequtl.for:941 */
/*<    79  >*/
/* SOURCE fequtl.for:943 */
/*<    80 format(' *WRN:559* Invalid response for EXTEND.  Taken as: NO') >*/
/* SOURCE fequtl.for:944 */
/*<    81  >*/
/* SOURCE fequtl.for:951 */
/*<    82 format(/,' Global home name is: ',a) >*/
/* SOURCE fequtl.for:952 */
/*<    83 format(/,' FEQUTL configuration from conf file: ',a) >*/
/* SOURCE fequtl.for:953 */
/*<    84 format(/,' FEQUTL configuration from master-input file.') >*/
/* SOURCE fequtl.for:954 */
/*<    85  >*/
/* SOURCE fequtl.for:958 */
/*<    86  >*/
/* SOURCE fequtl.for:960 */
/*<    87  >*/
/* SOURCE fequtl.for:967 */
/*<    88 format('; Global home name is: ',a) >*/
/* SOURCE fequtl.for:968 */
/*<    89 format('; Local home name is: ',a) >*/
/* SOURCE fequtl.for:970 */
/*<    90 format('  Processing FTABIN') >*/
/* SOURCE fequtl.for:971 */
/*<    91  >*/
/* SOURCE fequtl.for:973 */
/*<    92 format(/,' Minimum flow target for EMBANKQ and CHANRAT=',f10.3) >*/
/* SOURCE fequtl.for:974 */
/*<    93  >*/
/* SOURCE fequtl.for:976 */
/*<    94  >*/
/* SOURCE fequtl.for:979 */
/*<    95  >*/
/* SOURCE fequtl.for:986 */
/*<    96  >*/
/* SOURCE fequtl.for:990 */
/*<    97  >*/
/* *********************************************************************** */
/* SOURCE fequtl.for:995 */
/*<       trk_files=.false. >*/
/* L40: */
/* L41: */
/* L42: */
/* L44: */
/* L45: */
/* L46: */
/* L49: */
/* L51: */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
/* L70: */
/* L72: */
/* L74: */
/* L76: */
/* L77: */
/* L78: */
/* L79: */
/* L80: */
/* L81: */
/* L82: */
/* L83: */
/* L84: */
/* L85: */
/* L86: */
/* L87: */
/* L88: */
/* L89: */
/* L90: */
/* L91: */
/* L92: */
/* L93: */
/* L94: */
/* L95: */
/* L96: */
/* L97: */
    feq_gen_trk_files_d_ = FALSE_;

/*     strings for Unix what command */
/* SOURCE fequtl.for:998 */
/*<        >*/
    s_copy(line, const_cast<char*>("@(#)FEQUTL - Full Equations Flow Routing Model Utility Pro\
gram"), (ftnlen)80, (ftnlen)62);
/* SOURCE fequtl.for:1000 */
/*<       line='@(#)FEQUTL - Franz, D.D., and Melching, C.S., WRIR 97-4037' >*/
    s_copy(line, const_cast<char*>("@(#)FEQUTL - Franz, D.D., and Melching, C.S., WRIR 97-4037"),
	     (ftnlen)80, (ftnlen)58);
/* SOURCE fequtl.for:1002 */
/*<       line='@(#)FEQUTL - Contact: h2osoft@usgs.gov' >*/
    s_copy(line, const_cast<char*>("@(#)FEQUTL - Contact: h2osoft@usgs.gov"), (ftnlen)80, (
	    ftnlen)38);
/* SOURCE fequtl.for:1003 */
/*<       line='@(#)FEQUTL - Version: 4.81x 1998/05/22' >*/
    s_copy(line, const_cast<char*>("@(#)FEQUTL - Version: 4.81x 1998/05/22"), (ftnlen)80, (
	    ftnlen)38);
/*     set string for use with RCS ident command */
/* SOURCE fequtl.for:1005 */
/*<        >*/
    s_copy(line, const_cast<char*>("$Id: fequtl.f,v 4.4 1996/02/28 19:16:54 rsregan Exp rsrega\
n $"), (ftnlen)80, (ftnlen)61);

/*     Create the mechanism for assignment of I/O unit numbers */
/* SOURCE fequtl.for:1010 */
/*<       callinitialize_units >*/
    feq_gen_initialize_units_d_();
/*     The argument to GET_UNIT intends to write to the console should */
/*     an error arise in assigning unit numbers.  May not work on */
/*     all systems! */
/* SOURCE fequtl.for:1016 */
/*<       std5=get_unit(0) >*/
    feq_gen_stdun_com_d_1.std5 = feq_gen_get_unit_d_(&feq_gen_c_d_0);
/* SOURCE fequtl.for:1017 */
/*<       std6=get_unit(0) >*/
    feq_gen_stdun_com_d_1.std6 = feq_gen_get_unit_d_(&feq_gen_c_d_0);
/* SOURCE fequtl.for:1018 */
/*<       std7=get_unit(0) >*/
    feq_gen_stdun_com_d_1.std7 = feq_gen_get_unit_d_(&feq_gen_c_d_0);
/* SOURCE fequtl.for:1019 */
/*<       std10=get_unit(0) >*/
    feq_gen_stdun_com_d_1.std10 = feq_gen_get_unit_d_(&feq_gen_c_d_0);
/* SOURCE fequtl.for:1020 */
/*<       std48=get_unit(0) >*/
    feq_gen_stdun_com_d_1.std48 = feq_gen_get_unit_d_(&feq_gen_c_d_0);
/* SOURCE fequtl.for:1021 */
/*<       std49=get_unit(0) >*/
    feq_gen_stdun_com_d_1.std49 = feq_gen_get_unit_d_(&feq_gen_c_d_0);
/* SOURCE fequtl.for:1022 */
/*<       std50=get_unit(0) >*/
    feq_gen_stdun_com_d_1.std50 = feq_gen_get_unit_d_(&feq_gen_c_d_0);
/* SOURCE fequtl.for:1023 */
/*<       stdscr=get_unit(0) >*/
    stdscr = feq_gen_get_unit_d_(&feq_gen_c_d_0);
/* SOURCE fequtl.for:1024 */
/*<       stdin=std5 >*/
    stdin = feq_gen_stdun_com_d_1.std5;
/* SOURCE fequtl.for:1025 */
/*<       stdout=std6 >*/
    xscom_1.stdout = feq_gen_stdun_com_d_1.std6;
/* SOURCE fequtl.for:1026 */
/*<       stdsys=stdin >*/
    stdsys = stdin;
/* SOURCE fequtl.for:1027 */
/*<       stdtab=std7 >*/
    stdtab = feq_gen_stdun_com_d_1.std7;
/* SOURCE fequtl.for:1029 */
/*<       stdfld=std10 >*/
    stdfld = feq_gen_stdun_com_d_1.std10;
/* SOURCE fequtl.for:1030 */
/*<       output=1 >*/
    xscom_1.output = 1;
/* SOURCE fequtl.for:1031 */
/*<       in=stdin >*/
    xscom_1.in = stdin;
/* SOURCE fequtl.for:1032 */
/*<       lout=stdout >*/
    xscom_1.lout = xscom_1.stdout;
/* SOURCE fequtl.for:1033 */
/*<       slot=1.e30 >*/
    nrdzcm_1.slot = (float)1e30;
/* SOURCE fequtl.for:1034 */
/*<       time=0.0d0 >*/
    xscom_1.time = 0.;
/* SOURCE fequtl.for:1035 */
/*<       ftp=1 >*/
    ftp = 1;
/* SOURCE fequtl.for:1036 */
/*<       ftknt=0 >*/
    ftknt = 0;
/* SOURCE fequtl.for:1037 */
/*<       gflag=0 >*/
    gflag = 0;
/* SOURCE fequtl.for:1038 */
/*<       narg=0 >*/
    clcom_1.narg = 0;
/* SOURCE fequtl.for:1039 */
/*<       nxt=1 >*/
    clcom_1.nxt = 1;
/*     set options for testing table fitting */
/* SOURCE fequtl.for:1043 */
/*<       ty13_to_ty43='NO' >*/
    s_copy(upgrdc_1.feq_gen_ty13_to_ty43_d_, const_cast<char*>("NO"), (ftnlen)4, (ftnlen)2);
/* SOURCE fequtl.for:1044 */
/*<       upgrade_xsec_tab='NO' >*/
    s_copy(upgrdc_1.feq_gen_upgrade_xsec_tab_d_, const_cast<char*>("NO"), (ftnlen)4, (ftnlen)2);
/*     Clear the location-status flag for function tables. */
/* SOURCE fequtl.for:1047 */
/*<       dofeql_index3=1,mftnum >*/
    for (feq_gen_feql_index3_d_ = 1; feq_gen_feql_index3_d_ <= 10002; ++feq_gen_feql_index3_d_) {
/* SOURCE fequtl.for:1047 */
/*<       ft_loc_status(feql_index3)=' ' >*/
	*(unsigned char *)&ftablec_1.feq_gen_ft_loc_status_d_[feq_gen_feql_index3_d_ - 1] = ' ';
/* SOURCE fequtl.for:1047 */
/*<       enddo >*/
    }
/*     Clear the home-name values */
/* SOURCE fequtl.for:1051 */
/*<       callclear_home() >*/
    feq_gen_clear_home_d_();
/* SOURCE fequtl.for:1052 */
/*<       callclear_ghome() >*/
    feq_gen_clear_ghome_d_();
/*     Set the code for the carriage-return character */
/* SOURCE fequtl.for:1055 */
/*<       callsetcr() >*/
    setcr_();
/*     Clear the base julian time for time series tables.  Not needed */
/*     now but will be needed if time series tables are added to FEQUTL. */
/* SOURCE fequtl.for:1059 */
/*<       tab_789_jtbase=0.d0 >*/
    julian_1.feq_gen_tab_789_jtbase_d_ = 0.;
/*     Clear the count of internal table ids */
/* SOURCE fequtl.for:1062 */
/*<       callreset_kount_of_internal_tabids() >*/
    feq_gen_reset_kount_of_internal_tabids_d_();
/*     Clear the symbol table for processing table id's */
/* SOURCE fequtl.for:1065 */
/*<       num_tabid=0 >*/
    tabid_1.feq_gen_num_tabid_d_ = 0;
/*     set the Operating System flag */
/* SOURCE fequtl.for:1068 */
/*<       osis=what_os() >*/
    whatos_1.osis = feq_gen_what_os_d_();
/*     PROCESS COMMAND LINE ARGUMENTS */
/* SOURCE fequtl.for:1072 */
/*<       narg=iargc() >*/
    clcom_1.narg = iargc_();
/*     Bring all command-line arguments into a vector and then scan for special */
/*     arguments, such as the standard-header file.  Process the special arguments, */
/*     if any, then set things so that the subsequent code will work as it did */
/*     prior to the addition of special arguments. */
/* SOURCE fequtl.for:1077 */
/*<       if(narg.gt.10)then >*/
    if (clcom_1.narg > 10) {
/* SOURCE fequtl.for:1078 */
/*<       write(*,*)' narg > 10. Too many command-line arguments.' >*/
	s_wsle(&feq_gen_io_d__79);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" narg > 10. Too many command-line arguments."), (
		ftnlen)44);
	e_wsle();
/* SOURCE fequtl.for:1079 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE fequtl.for:1080 */
/*<       else >*/
    } else {
/* SOURCE fequtl.for:1081 */
/*<       doj=1,narg-morg >*/
	feq_gen_i_d_1 = clcom_1.narg;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE fequtl.for:1082 */
/*<       callgetarg(j+morg,cmd_line_args(j)) >*/
	    feq_gen_i_d_2 = j;
	    getarg_(&feq_gen_i_d_2, feq_gen_cmd_line_args_d_ + (j << 6), (ftnlen)64);
/* SOURCE fequtl.for:1085 */
/*<       enddo >*/
	}
/*       Now scan for special arguments:  These are: */
/*        -conf  signals that a file name for the fequtl configuration */
/*               file is given. */
/* SOURCE fequtl.for:1091 */
/*<       conf_flag=0 >*/
	feq_gen_conf_flag_d_ = 0;
/* SOURCE fequtl.for:1092 */
/*<       doj=1,narg >*/
	feq_gen_i_d_1 = clcom_1.narg;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE fequtl.for:1093 */
/*<       if(cmd_line_args(j)(1:5)=='-conf')then >*/
	    if (s_cmp(feq_gen_cmd_line_args_d_ + (j << 6), const_cast<char*>("-conf"), (ftnlen)5, (ftnlen)
		    5) == 0) {
/*           found configuration-file name.  The file name */
/*           is the following argument. */
/* SOURCE fequtl.for:1096 */
/*<       conf_file=cmd_line_args(j+1) >*/
		s_copy(feq_gen_conf_file_d_, feq_gen_cmd_line_args_d_ + (j + 1 << 6), (ftnlen)
			64, (ftnlen)64);
/* SOURCE fequtl.for:1097 */
/*<       conf_flag=1 >*/
		feq_gen_conf_flag_d_ = 1;
/* SOURCE fequtl.for:1098 */
/*<       callos_file_style(conf_file) >*/
		feq_gen_os_file_style_d_(feq_gen_conf_file_d_, (ftnlen)64);
/*           reset stdsys to a unique unit number */
/* SOURCE fequtl.for:1101 */
/*<       stdsys=get_unit(0) >*/
		stdsys = feq_gen_get_unit_d_(&feq_gen_c_d_0);
/*           Adjust narg to match what would have been true had */
/*           -conf not been present. */
/* SOURCE fequtl.for:1104 */
/*<       narg=narg-2 >*/
		clcom_1.narg += -2;
/* SOURCE fequtl.for:1105 */
/*<       goto98998 >*/
		goto L98998;
/* SOURCE fequtl.for:1106 */
/*<       endif >*/
	    }
/* SOURCE fequtl.for:1107 */
/*<       enddo >*/
	}
/* SOURCE fequtl.for:1107 */
/*< 98998 continue >*/
L98998:
/* SOURCE fequtl.for:1108 */
/*<       endif >*/
	;
    }
/* SOURCE fequtl.for:1110 */
/*<       if(narg.eq.1+morg)then >*/
    if (clcom_1.narg == 1) {
/*       If only one file argument is given we assume that the */
/*       extension, if any, from the file given is stripped and the */
/*       remaining two file names are formed by adding .out and .tab */
/*       to the file name given by the user name stripped of its extension. */
/* SOURCE fequtl.for:1116 */
/*<       stdext_option=1 >*/
	feq_gen_stdext_option_d_ = 1;
/* SOURCE fequtl.for:1117 */
/*<       elseif(narg.lt.3+morg)then >*/
    } else if (clcom_1.narg < 3) {
/* SOURCE fequtl.for:1118 */
/*<       write(*,95) >*/
	s_wsfe(&feq_gen_io_d__85);
	e_wsfe();
/* SOURCE fequtl.for:1119 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE fequtl.for:1120 */
/*<       else >*/
    } else {
/* SOURCE fequtl.for:1121 */
/*<       stdext_option=0 >*/
	feq_gen_stdext_option_d_ = 0;
/* SOURCE fequtl.for:1122 */
/*<       endif >*/
    }
/*     GET THE FIRST FILE ARGUMENT */
/* SOURCE fequtl.for:1127 */
/*<       callgetarg(1+morg,fname) >*/
    getarg_(&feq_gen_c_d_1, fname, (ftnlen)64);
/*     fix common OS deviations in file names */
/* SOURCE fequtl.for:1131 */
/*<       callos_file_style(fname) >*/
    feq_gen_os_file_style_d_(fname, (ftnlen)64);
/* SOURCE fequtl.for:1133 */
/*<       inquire(file=fname,exist=there) >*/
    feq_gen_ioin_d_1.inerr = 0;
    feq_gen_ioin_d_1.infilen = 64;
    feq_gen_ioin_d_1.infile = fname;
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
/* SOURCE fequtl.for:1134 */
/*<       if(there)then >*/
    if (there) {
/* SOURCE fequtl.for:1135 */
/*<       open(stdin,file=fname,status='OLD') >*/
	feq_gen_o_d_1.oerr = 0;
	feq_gen_o_d_1.ounit = stdin;
	feq_gen_o_d_1.ofnmlen = 64;
	feq_gen_o_d_1.ofnm = fname;
	feq_gen_o_d_1.orl = 0;
	feq_gen_o_d_1.osta = const_cast<char*>("OLD");
	feq_gen_o_d_1.oacc = 0;
	feq_gen_o_d_1.ofm = 0;
	feq_gen_o_d_1.oblnk = 0;
	f_open(&feq_gen_o_d_1);
/* SOURCE fequtl.for:1136 */
/*<       else >*/
    } else {
/* SOURCE fequtl.for:1137 */
/*<       n=feq_len_trim(fname) >*/
	n = feq_gen_feq_len_trim_d_(fname, (ftnlen)64);
/* SOURCE fequtl.for:1138 */
/*<       write(*,*)' ' >*/
	s_wsle(&feq_gen_io_d__89);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	e_wsle();
/* SOURCE fequtl.for:1139 */
/*<       write(*,*)' File named: ',fname(1:n),' not found.' >*/
	s_wsle(&feq_gen_io_d__90);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" File named: "), (ftnlen)13);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, fname, n);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" not found."), (ftnlen)11);
	e_wsle();
/* SOURCE fequtl.for:1140 */
/*<       write(*,*)' Please check spelling of master-input file.' >*/
	s_wsle(&feq_gen_io_d__91);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Please check spelling of master-input file."), (
		ftnlen)44);
	e_wsle();
/* SOURCE fequtl.for:1141 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE fequtl.for:1142 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:1144 */
/*<       if(stdext_option.eq.1)then >*/
    if (feq_gen_stdext_option_d_ == 1) {
/*       Form the other two file names */
/* SOURCE fequtl.for:1146 */
/*<       callmake_standard_file_names(fname,fname2,fname3) >*/
	feq_gen_make_standard_file_names_d_(fname, fname2, fname3, (ftnlen)64, (ftnlen)
		64, (ftnlen)64);
/* SOURCE fequtl.for:1148 */
/*<       else >*/
    } else {
/*       GET THE SECOND FILE ARGUMENT */
/* SOURCE fequtl.for:1152 */
/*<       callgetarg(2+morg,fname2) >*/
	getarg_(&feq_gen_c_d_2, fname2, (ftnlen)64);
/*       fix common OS deviations in file names */
/* SOURCE fequtl.for:1156 */
/*<       callos_file_style(fname2) >*/
	feq_gen_os_file_style_d_(fname2, (ftnlen)64);
/*       GET THE THIRD FILE ARGUMENT */
/* SOURCE fequtl.for:1161 */
/*<       callgetarg(3+morg,fname3) >*/
	getarg_(&feq_gen_c_d_3, fname3, (ftnlen)64);
/*       fix common OS deviations in file names */
/* SOURCE fequtl.for:1165 */
/*<       callos_file_style(fname3) >*/
	feq_gen_os_file_style_d_(fname3, (ftnlen)64);
/* SOURCE fequtl.for:1168 */
/*<       endif >*/
    }
/*     Make sure that no file names match. */
/* SOURCE fequtl.for:1171 */
/*<       if(fname.eq.fname2.or.fname.eq.fname3.or.fname2.eq.fname3)then >*/
    if (s_cmp(fname, fname2, (ftnlen)64, (ftnlen)64) == 0 || s_cmp(fname, 
	    fname3, (ftnlen)64, (ftnlen)64) == 0 || s_cmp(fname2, fname3, (
	    ftnlen)64, (ftnlen)64) == 0) {
/*       One or more names match. */
/* SOURCE fequtl.for:1173 */
/*<       write(*,*)' ' >*/
	s_wsle(&feq_gen_io_d__94);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	e_wsle();
/* SOURCE fequtl.for:1174 */
/*<       write(*,*)' Two or more names given as command-line' >*/
	s_wsle(&feq_gen_io_d__95);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Two or more names given as command-line"), (
		ftnlen)40);
	e_wsle();
/* SOURCE fequtl.for:1175 */
/*<       write(*,*)' arguments are the same.  All names must be unique.' >*/
	s_wsle(&feq_gen_io_d__96);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" arguments are the same.  All names must be un\
ique."), (ftnlen)51);
	e_wsle();
/* SOURCE fequtl.for:1177 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE fequtl.for:1178 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:1179 */
/*<       open(stdout,file=fname2,status='UNKNOWN',iostat=ios) >*/
    feq_gen_o_d_1.oerr = 1;
    feq_gen_o_d_1.ounit = xscom_1.stdout;
    feq_gen_o_d_1.ofnmlen = 64;
    feq_gen_o_d_1.ofnm = fname2;
    feq_gen_o_d_1.orl = 0;
    feq_gen_o_d_1.osta = const_cast<char*>("UNKNOWN");
    feq_gen_o_d_1.oacc = 0;
    feq_gen_o_d_1.ofm = 0;
    feq_gen_o_d_1.oblnk = 0;
    ios = f_open(&feq_gen_o_d_1);
/* SOURCE fequtl.for:1180 */
/*<       if(ios.ne.0)then >*/
    if (ios != 0) {
/* SOURCE fequtl.for:1181 */
/*<       n=feq_len_trim(fname2) >*/
	n = feq_gen_feq_len_trim_d_(fname2, (ftnlen)64);
/* SOURCE fequtl.for:1182 */
/*<       write(*,96)fname2(1:n) >*/
	s_wsfe(&feq_gen_io_d__98);
	do_fio(&feq_gen_c_d_1, fname2, n);
	e_wsfe();
/* SOURCE fequtl.for:1183 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE fequtl.for:1184 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:1186 */
/*<       open(stdtab,file=fname3,status='UNKNOWN',iostat=ios) >*/
    feq_gen_o_d_1.oerr = 1;
    feq_gen_o_d_1.ounit = stdtab;
    feq_gen_o_d_1.ofnmlen = 64;
    feq_gen_o_d_1.ofnm = fname3;
    feq_gen_o_d_1.orl = 0;
    feq_gen_o_d_1.osta = const_cast<char*>("UNKNOWN");
    feq_gen_o_d_1.oacc = 0;
    feq_gen_o_d_1.ofm = 0;
    feq_gen_o_d_1.oblnk = 0;
    ios = f_open(&feq_gen_o_d_1);
/* SOURCE fequtl.for:1187 */
/*<       if(ios.ne.0)then >*/
    if (ios != 0) {
/* SOURCE fequtl.for:1188 */
/*<       n=feq_len_trim(fname3) >*/
	n = feq_gen_feq_len_trim_d_(fname3, (ftnlen)64);
/* SOURCE fequtl.for:1189 */
/*<       write(*,97)fname3(1:n) >*/
	s_wsfe(&feq_gen_io_d__99);
	do_fio(&feq_gen_c_d_1, fname3, n);
	e_wsfe();
/* SOURCE fequtl.for:1190 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE fequtl.for:1191 */
/*<       endif >*/
    }
/*     Make a copy of the master-input file as a scratch file here.  We may */
/*     need it if we later want to compute md5 digests of various input blocks. */

/* SOURCE fequtl.for:1196 */
/*<       if(trk_files)then >*/
    if (feq_gen_trk_files_d_) {
/* SOURCE fequtl.for:1197 */
/*<       callcopy_master_input_file(stdin,stdscr) >*/
	feq_gen_copy_master_input_file_d_(&stdin, &stdscr);
/* SOURCE fequtl.for:1198 */
/*<       endif >*/
    }
/*     Clear the cross section slot values */
/* SOURCE fequtl.for:1202 */
/*<       callclear_slot(stdtab) >*/
    feq_gen_clear_slot_d_(&stdtab);
/* SOURCE fequtl.for:1205 */
/*<       callset_version() >*/
    feq_gen_set_version_d_();
/* SOURCE fequtl.for:1206 */
/*<       calldate_and_time(date,zeit,zone,values) >*/
    feq_gen_date_and_time_d_(date, zeit, zone, values, (ftnlen)8, (ftnlen)10, (ftnlen)
	    5);
/* SOURCE fequtl.for:1207 */
/*<        >*/
    feq_gen_io_d__104.ciunit = xscom_1.stdout;
    s_wsfe(&feq_gen_io_d__104);
    do_fio(&feq_gen_c_d_1, (char *)&version_1.feq_gen_version_number_d_, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, versionc_1.feq_gen_version_date_d_, (ftnlen)17);
    do_fio(&feq_gen_c_d_1, date, (ftnlen)4);
    do_fio(&feq_gen_c_d_1, date + 4, (ftnlen)2);
    do_fio(&feq_gen_c_d_1, date + 6, (ftnlen)2);
    do_fio(&feq_gen_c_d_1, zeit, (ftnlen)2);
    do_fio(&feq_gen_c_d_1, zeit + 2, (ftnlen)2);
    do_fio(&feq_gen_c_d_1, zeit + 4, (ftnlen)6);
    e_wsfe();
/*     Save the version and run time stamps */
/* SOURCE fequtl.for:1210 */
/*<        >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 95;
    feq_gen_ici_d_1.iciunit = datetime_1.feq_gen_version_run_date_time_string_d_;
    feq_gen_ici_d_1.icifmt = fmt_72;
    s_wsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&version_1.feq_gen_version_number_d_, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, versionc_1.feq_gen_version_date_d_, (ftnlen)17);
    do_fio(&feq_gen_c_d_1, date, (ftnlen)4);
    do_fio(&feq_gen_c_d_1, date + 4, (ftnlen)2);
    do_fio(&feq_gen_c_d_1, date + 6, (ftnlen)2);
    do_fio(&feq_gen_c_d_1, zeit, (ftnlen)2);
    do_fio(&feq_gen_c_d_1, zeit + 2, (ftnlen)2);
    do_fio(&feq_gen_c_d_1, zeit + 4, (ftnlen)6);
    e_wsfi();
/* SOURCE fequtl.for:1215 */
/*<       callwhat_executable(stdout) >*/
    feq_gen_what_executable_d_(&xscom_1.stdout);
/* SOURCE fequtl.for:1218 */
/*<        >*/
    feq_gen_io_d__105.ciunit = xscom_1.stdout;
    s_wsfe(&feq_gen_io_d__105);
    do_fio(&feq_gen_c_d_1, fname, feq_gen_feq_len_trim_d_(fname, (ftnlen)64));
    do_fio(&feq_gen_c_d_1, fname2, feq_gen_feq_len_trim_d_(fname2, (ftnlen)64));
    do_fio(&feq_gen_c_d_1, fname3, feq_gen_feq_len_trim_d_(fname3, (ftnlen)64));
    e_wsfe();
/*     Write the version/run string to  the standard table file.  Make an echoing comment. */
/* SOURCE fequtl.for:1223 */
/*<       write(stdtab,'(a)')'* Created by program: fequtl' >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = stdtab;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(a)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("* Created by program: fequtl"), (ftnlen)28);
    e_wsfe();
/* SOURCE fequtl.for:1224 */
/*<       write(stdtab,'(a1,a)')'*',version_run_date_time_string >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = stdtab;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(a1,a)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("*"), (ftnlen)1);
    do_fio(&feq_gen_c_d_1, datetime_1.feq_gen_version_run_date_time_string_d_, (ftnlen)95);
    e_wsfe();
/* SOURCE fequtl.for:1225 */
/*<       callsvn_report(stdout,stdtab) >*/
    feq_gen_svn_report_d_(&xscom_1.stdout, &stdtab);
/*     SET VARIOUS VALUES */
/* SOURCE fequtl.for:1231 */
/*<       eflag=0 >*/
    xscom_1.eflag = 0;
/*     INTIALIZE SELECTED VALUES IN COMMON */
/* SOURCE fequtl.for:1235 */
/*<       callinit >*/
    init_();
/*     BE SURE TO SET NPNTD TO 0 IN BLOCK DATA SUBROUTINE */
/*     INITIALIZE TABLE DIRECTORY */
/* SOURCE fequtl.for:1241 */
/*<       do100j=1,pmxtab >*/
    for (j = 1; j <= 10002; ++j) {
/* SOURCE fequtl.for:1242 */
/*<       tabdir(j)=0 >*/
	tabdir[j - 1] = 0;
/* SOURCE fequtl.for:1243 */
/*<       ftpnt(j)=0 >*/
	ftablea_1.ftpnt[j - 1] = 0;
/* SOURCE fequtl.for:1244 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE fequtl.for:1246 */
/*<       if(conf_flag==1)then >*/
    if (feq_gen_conf_flag_d_ == 1) {
/* SOURCE fequtl.for:1247 */
/*<       inquire(file=conf_file,exist=there) >*/
	feq_gen_ioin_d_1.inerr = 0;
	feq_gen_ioin_d_1.infilen = 64;
	feq_gen_ioin_d_1.infile = feq_gen_conf_file_d_;
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
/* SOURCE fequtl.for:1248 */
/*<       n=feq_len_trim(conf_file) >*/
	n = feq_gen_feq_len_trim_d_(feq_gen_conf_file_d_, (ftnlen)64);
/* SOURCE fequtl.for:1249 */
/*<       if(there)then >*/
	if (there) {
/* SOURCE fequtl.for:1251 */
/*<       open(stdsys,file=conf_file,status='OLD') >*/
	    feq_gen_o_d_1.oerr = 0;
	    feq_gen_o_d_1.ounit = stdsys;
	    feq_gen_o_d_1.ofnmlen = 64;
	    feq_gen_o_d_1.ofnm = feq_gen_conf_file_d_;
	    feq_gen_o_d_1.orl = 0;
	    feq_gen_o_d_1.osta = const_cast<char*>("OLD");
	    feq_gen_o_d_1.oacc = 0;
	    feq_gen_o_d_1.ofm = 0;
	    feq_gen_o_d_1.oblnk = 0;
	    f_open(&feq_gen_o_d_1);
/* SOURCE fequtl.for:1252 */
/*<       write(*,*)' FEQUTL configuration from conf file.' >*/
	    s_wsle(&feq_gen_io_d__107);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FEQUTL configuration from conf file."), (
		    ftnlen)37);
	    e_wsle();
/* SOURCE fequtl.for:1253 */
/*<       write(stdout,83)conf_file(1:n) >*/
	    feq_gen_io_d__108.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__108);
	    do_fio(&feq_gen_c_d_1, feq_gen_conf_file_d_, n);
	    e_wsfe();
/* SOURCE fequtl.for:1254 */
/*<       else >*/
	} else {
/* SOURCE fequtl.for:1255 */
/*<       write(*,*)' ' >*/
	    s_wsle(&feq_gen_io_d__109);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	    e_wsle();
/* SOURCE fequtl.for:1256 */
/*<       write(*,*)' File named: ',conf_file(1:n),' not found.' >*/
	    s_wsle(&feq_gen_io_d__110);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" File named: "), (ftnlen)13);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_conf_file_d_, n);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" not found."), (ftnlen)11);
	    e_wsle();
/* SOURCE fequtl.for:1257 */
/*<       write(*,*)' Please check spelling of configuration file.' >*/
	    s_wsle(&feq_gen_io_d__111);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Please check spelling of configuration fi\
le."), (ftnlen)45);
	    e_wsle();
/* SOURCE fequtl.for:1258 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE fequtl.for:1259 */
/*<       endif >*/
	}
/* SOURCE fequtl.for:1260 */
/*<       else >*/
    } else {
/* SOURCE fequtl.for:1261 */
/*<       write(*,*)' FEQUTL configuration from master-input file.' >*/
	s_wsle(&feq_gen_io_d__112);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FEQUTL configuration from master-input file."), 
		(ftnlen)45);
	e_wsle();
/* SOURCE fequtl.for:1262 */
/*<       write(stdout,84) >*/
	feq_gen_io_d__113.ciunit = xscom_1.stdout;
	s_wsfe(&feq_gen_io_d__113);
	e_wsfe();
/* SOURCE fequtl.for:1264 */
/*<       endif >*/
    }
/*     INPUT THE CONTROL INFORMATION FROM THE SYSTEM DATASET. */
/*     Info may be at the head of the master-input file, old */
/*     method, or in its own file, new method.  In the former */
/*     case, stdsys is the same as stdin.  Otherwise, stdsys */
/*     is unique. */
/* SOURCE fequtl.for:1272 */
/*<        >*/
    insys_(&stdsys, &feq_gen_c_d_45, &clcom_1.narg, &xscom_1.stdout, units, &nfac, &
	    grvcom_1.grav, &maxknt, &eps, &ncmd, cmdtab, cmdval, (ftnlen)8, (
	    ftnlen)8);
/* SOURCE fequtl.for:1277 */
/*<       grav2=grav+grav >*/
    grvcom_1.grav2 = static_cast<double>(grvcom_1.grav) + grvcom_1.grav;
/* SOURCE fequtl.for:1278 */
/*<       sqrt_grav=sqrt(grav) >*/
    grvcom_1.feq_gen_sqrt_grav_d_ = sqrt(grvcom_1.grav);
/*     SET THE VALUE FOR THE MAXIMUM WEIR COEF FOR A BROAD CRESTED WEIR */
/*     WITH CRITICAL DEPTH AT THE CREST.  USED IN EMBANKQ FOR COMPUTING */
/*     ENERGY LOSSES WHEN FLOW ON THE WEIR CREST IS CLOSE TO CRITICAL. */
/* SOURCE fequtl.for:1284 */
/*<       bcwmax=sqrt(grav)/(1.5*sqrt(1.5)) >*/
    grvcom_1.bcwmax = sqrt(grvcom_1.grav) / (sqrt((float)1.5) * (float)1.5);
/*     Set the special small difference value in epscom */
/* SOURCE fequtl.for:1287 */
/*<       if(grav.gt.15.0)then >*/
    if (grvcom_1.grav > (float)15.) {
/* SOURCE fequtl.for:1288 */
/*<       epsdif=0.01 >*/
	epscom_1.epsdif = (float).01;
/* SOURCE fequtl.for:1289 */
/*<       else >*/
    } else {
/* SOURCE fequtl.for:1290 */
/*<       epsdif=0.003048 >*/
	epscom_1.epsdif = (float).003048;
/* SOURCE fequtl.for:1291 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:1293 */
/*<       callinline(stdsys,stdout,line) >*/
    inline_(&stdsys, &xscom_1.stdout, line, (ftnlen)80);
/* SOURCE fequtl.for:1296 */
/*<       read(line,49,err=991)dzlim >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_49;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&nrdzcm_1.dzlim, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE fequtl.for:1297 */
/*<       callinline(stdsys,stdout,line) >*/
    inline_(&stdsys, &xscom_1.stdout, line, (ftnlen)80);
/* SOURCE fequtl.for:1300 */
/*<       read(line,40,err=991)nrzero >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_40;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&nrdzcm_1.nrzero, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE fequtl.for:1301 */
/*<       callinline(stdsys,stdout,line) >*/
    inline_(&stdsys, &xscom_1.stdout, line, (ftnlen)80);
/* SOURCE fequtl.for:1304 */
/*<       read(line,42,err=991)reply >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_42;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, reply, (ftnlen)3);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE fequtl.for:1307 */
/*<       write(stdout,*)'   ' >*/
    feq_gen_io_d__122.ciunit = xscom_1.stdout;
    s_wsle(&feq_gen_io_d__122);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("   "), (ftnlen)3);
    e_wsle();
/* SOURCE fequtl.for:1308 */
/*<       write(stdout,70)dzlim,nrzero,reply >*/
    feq_gen_io_d__123.ciunit = xscom_1.stdout;
    s_wsfe(&feq_gen_io_d__123);
    do_fio(&feq_gen_c_d_1, (char *)&nrdzcm_1.dzlim, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&nrdzcm_1.nrzero, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, reply, (ftnlen)3);
    e_wsfe();
/* SOURCE fequtl.for:1309 */
/*<       if(nrzero.le.0.0.or.dzlim.le.0.0)then >*/
    if (nrdzcm_1.nrzero <= (float)0. || nrdzcm_1.dzlim <= (float)0.) {
/* SOURCE fequtl.for:1310 */
/*<       write(stdout,*)'*ERR:502* INVALID VALUES FOR NRZERO OR',' DZLIM' >*/
	feq_gen_io_d__124.ciunit = xscom_1.stdout;
	s_wsle(&feq_gen_io_d__124);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("*ERR:502* INVALID VALUES FOR NRZERO OR"), (
		ftnlen)38);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" DZLIM"), (ftnlen)6);
	e_wsle();
/* SOURCE fequtl.for:1312 */
/*<       write(stdout,*)'   BOTH MUST BE > 0.0' >*/
	feq_gen_io_d__125.ciunit = xscom_1.stdout;
	s_wsle(&feq_gen_io_d__125);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("   BOTH MUST BE > 0.0"), (ftnlen)21);
	e_wsle();
/* SOURCE fequtl.for:1313 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE fequtl.for:1314 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:1315 */
/*<       if(reply.eq.'YES')then >*/
    if (s_cmp(reply, const_cast<char*>("YES"), (ftnlen)3, (ftnlen)3) == 0) {
/* SOURCE fequtl.for:1316 */
/*<       iusgs=1 >*/
	nrdzcm_1.iusgs = 1;
/* SOURCE fequtl.for:1317 */
/*<       elseif(reply.eq.'NO')then >*/
    } else if (s_cmp(reply, const_cast<char*>("NO"), (ftnlen)3, (ftnlen)2) == 0) {
/* SOURCE fequtl.for:1318 */
/*<       iusgs=0 >*/
	nrdzcm_1.iusgs = 0;
/* SOURCE fequtl.for:1319 */
/*<       else >*/
    } else {
/* SOURCE fequtl.for:1320 */
/*<       write(stdout,74) >*/
	feq_gen_io_d__126.ciunit = xscom_1.stdout;
	s_wsfe(&feq_gen_io_d__126);
	e_wsfe();
/* SOURCE fequtl.for:1321 */
/*<       iusgs=0 >*/
	nrdzcm_1.iusgs = 0;
/* SOURCE fequtl.for:1322 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:1323 */
/*<       callinline(stdsys,stdout,line) >*/
    inline_(&stdsys, &xscom_1.stdout, line, (ftnlen)80);
/* SOURCE fequtl.for:1326 */
/*<       read(line,45,err=991)nxtnam >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_45;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, nxtnam, (ftnlen)128);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE fequtl.for:1327 */
/*<       if(nxtnam(1:6).ne.'EPSARG')then >*/
    if (s_cmp(nxtnam, const_cast<char*>("EPSARG"), (ftnlen)6, (ftnlen)6) != 0) {
/* SOURCE fequtl.for:1328 */
/*<       write(stdout,*)' CHECK INPUT STREAM. THIS VERSION OF FEQUTL' >*/
	feq_gen_io_d__128.ciunit = xscom_1.stdout;
	s_wsle(&feq_gen_io_d__128);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" CHECK INPUT STREAM. THIS VERSION OF FEQUTL"), (
		ftnlen)43);
	e_wsle();
/* SOURCE fequtl.for:1329 */
/*<       write(stdout,*)' HAS ADDED EPSARG AND EPSF AFTER USGSBETA' >*/
	feq_gen_io_d__129.ciunit = xscom_1.stdout;
	s_wsle(&feq_gen_io_d__129);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" HAS ADDED EPSARG AND EPSF AFTER USGSBETA"), (
		ftnlen)41);
	e_wsle();
/* SOURCE fequtl.for:1330 */
/*<       write(stdout,*)' TRY EPSARG=5.E-4 AND EPSF=1.E-3' >*/
	feq_gen_io_d__130.ciunit = xscom_1.stdout;
	s_wsle(&feq_gen_io_d__130);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" TRY EPSARG=5.E-4 AND EPSF=1.E-3"), (ftnlen)32);
	e_wsle();
/* SOURCE fequtl.for:1331 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE fequtl.for:1332 */
/*<       else >*/
    } else {
/* SOURCE fequtl.for:1333 */
/*<       read(nxtnam,44)epsarg >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 128;
	feq_gen_ici_d_1.iciunit = nxtnam;
	feq_gen_ici_d_1.icifmt = fmt_44;
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&epscom_1.epsarg, (ftnlen)sizeof(real));
	e_rsfi();
/* SOURCE fequtl.for:1334 */
/*<       callinline(stdsys,stdout,line) >*/
	inline_(&stdsys, &xscom_1.stdout, line, (ftnlen)80);
/* SOURCE fequtl.for:1337 */
/*<       read(line,46,err=991)epsf,epsabs >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_46;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&epscom_1.epsf, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&epscom_1.epsabs, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE fequtl.for:1338 */
/*<       if(epsabs.eq.0.0)then >*/
	if (epscom_1.epsabs == (float)0.) {
/* SOURCE fequtl.for:1339 */
/*<       write(stdout,91) >*/
	    feq_gen_io_d__131.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__131);
	    e_wsfe();
/* SOURCE fequtl.for:1340 */
/*<       if(grav.gt.15.0)then >*/
	    if (grvcom_1.grav > (float)15.) {
/* SOURCE fequtl.for:1341 */
/*<       epsabs=epsf >*/
		epscom_1.epsabs = epscom_1.epsf;
/* SOURCE fequtl.for:1342 */
/*<       else >*/
	    } else {
/* SOURCE fequtl.for:1343 */
/*<       epsabs=epsf*0.3048 >*/
		epscom_1.epsabs = static_cast<double>(epscom_1.epsf) * (float).3048;
/* SOURCE fequtl.for:1344 */
/*<       endif >*/
	    }
/* SOURCE fequtl.for:1345 */
/*<       endif >*/
	}
/* SOURCE fequtl.for:1346 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:1348 */
/*<       write(stdout,76)epsarg,epsf,epsabs >*/
    feq_gen_io_d__132.ciunit = xscom_1.stdout;
    s_wsfe(&feq_gen_io_d__132);
    do_fio(&feq_gen_c_d_1, (char *)&epscom_1.epsarg, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&epscom_1.epsf, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&epscom_1.epsabs, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE fequtl.for:1350 */
/*<       callinline(stdsys,stdout,line) >*/
    inline_(&stdsys, &xscom_1.stdout, line, (ftnlen)80);
/* SOURCE fequtl.for:1353 */
/*<       read(line,45,err=991)nxtnam >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_45;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, nxtnam, (ftnlen)128);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE fequtl.for:1354 */
/*<       if(nxtnam(1:6).ne.'EXTEND')then >*/
    if (s_cmp(nxtnam, const_cast<char*>("EXTEND"), (ftnlen)6, (ftnlen)6) != 0) {
/* SOURCE fequtl.for:1355 */
/*<       write(stdout,81) >*/
	feq_gen_io_d__133.ciunit = xscom_1.stdout;
	s_wsfe(&feq_gen_io_d__133);
	e_wsfe();
/* SOURCE fequtl.for:1356 */
/*<       gxtend=1 >*/
	nrdzcm_1.gxtend = 1;
/* SOURCE fequtl.for:1357 */
/*<       write(stdout,77) >*/
	feq_gen_io_d__134.ciunit = xscom_1.stdout;
	s_wsfe(&feq_gen_io_d__134);
	e_wsfe();
/* SOURCE fequtl.for:1358 */
/*<       else >*/
    } else {
/* SOURCE fequtl.for:1359 */
/*<       read(nxtnam,41)reply >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 128;
	feq_gen_ici_d_1.iciunit = nxtnam;
	feq_gen_ici_d_1.icifmt = fmt_41;
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, reply, (ftnlen)3);
	e_rsfi();
/* SOURCE fequtl.for:1360 */
/*<       if(reply.eq.'YES')then >*/
	if (s_cmp(reply, const_cast<char*>("YES"), (ftnlen)3, (ftnlen)3) == 0) {
/* SOURCE fequtl.for:1361 */
/*<       gxtend=1 >*/
	    nrdzcm_1.gxtend = 1;
/* SOURCE fequtl.for:1362 */
/*<       write(stdout,78) >*/
	    feq_gen_io_d__135.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__135);
	    e_wsfe();
/* SOURCE fequtl.for:1363 */
/*<       write(stdout,77) >*/
	    feq_gen_io_d__136.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__136);
	    e_wsfe();
/* SOURCE fequtl.for:1364 */
/*<       elseif(reply.eq.'NO')then >*/
	} else if (s_cmp(reply, const_cast<char*>("NO"), (ftnlen)3, (ftnlen)2) == 0) {
/* SOURCE fequtl.for:1365 */
/*<       gxtend=0 >*/
	    nrdzcm_1.gxtend = 0;
/* SOURCE fequtl.for:1366 */
/*<       write(stdout,79) >*/
	    feq_gen_io_d__137.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__137);
	    e_wsfe();
/* SOURCE fequtl.for:1367 */
/*<       else >*/
	} else {
/* SOURCE fequtl.for:1368 */
/*<       write(stdout,80) >*/
	    feq_gen_io_d__138.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__138);
	    e_wsfe();
/* SOURCE fequtl.for:1369 */
/*<       gxtend=0 >*/
	    nrdzcm_1.gxtend = 0;
/* SOURCE fequtl.for:1370 */
/*<       write(stdout,79) >*/
	    feq_gen_io_d__139.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__139);
	    e_wsfe();
/* SOURCE fequtl.for:1371 */
/*<       endif >*/
	}
/* SOURCE fequtl.for:1372 */
/*<       endif >*/
    }
/*     Seek the minimum flow value.  May not be present. */
/* SOURCE fequtl.for:1375 */
/*<       callinline(stdsys,stdout,line) >*/
    inline_(&stdsys, &xscom_1.stdout, line, (ftnlen)80);
/* SOURCE fequtl.for:1378 */
/*<       if(line(1:4).ne.'MINQ')then >*/
    if (s_cmp(line, const_cast<char*>("MINQ"), (ftnlen)4, (ftnlen)4) != 0) {
/*       Put the line back! */
/* SOURCE fequtl.for:1380 */
/*<       backspace(stdsys) >*/
	feq_gen_al_d_1.aerr = 0;
	feq_gen_al_d_1.aunit = stdsys;
	f_back(&feq_gen_al_d_1);
/*       Set the default values */
/* SOURCE fequtl.for:1382 */
/*<       if(grav.gt.15.0)then >*/
	if (grvcom_1.grav > (float)15.) {
/* SOURCE fequtl.for:1383 */
/*<       minq=0.2 >*/
	    minq = (float).2;
/* SOURCE fequtl.for:1384 */
/*<       else >*/
	} else {
/* SOURCE fequtl.for:1385 */
/*<       minq=0.2/35.315 >*/
	    minq = (float).00566331587144273;
/* SOURCE fequtl.for:1386 */
/*<       endif >*/
	}
/* SOURCE fequtl.for:1387 */
/*<       else >*/
    } else {
/* SOURCE fequtl.for:1388 */
/*<       read(line(6:15),'(F10.0)')minq >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 10;
	feq_gen_ici_d_1.iciunit = line + 5;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.0)");
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&minq, (ftnlen)sizeof(real));
	e_rsfi();
/* SOURCE fequtl.for:1389 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:1391 */
/*<       write(stdout,92)minq >*/
    feq_gen_io_d__141.ciunit = xscom_1.stdout;
    s_wsfe(&feq_gen_io_d__141);
    do_fio(&feq_gen_c_d_1, (char *)&minq, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE fequtl.for:1392 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__142.ciunit = xscom_1.stdout;
    s_wsle(&feq_gen_io_d__142);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/*     seek the control value for processing tables for cubic interpolation. */
/*     May not be present. */
/* SOURCE fequtl.for:1396 */
/*<       callinline(stdsys,stdout,line) >*/
    inline_(&stdsys, &xscom_1.stdout, line, (ftnlen)80);
/* SOURCE fequtl.for:1399 */
/*<       if(line(1:5).ne.'TWOD_')then >*/
    if (s_cmp(line, const_cast<char*>("TWOD_"), (ftnlen)5, (ftnlen)5) != 0) {
/*       Put the line back! */
/* SOURCE fequtl.for:1401 */
/*<       backspace(stdsys) >*/
	feq_gen_al_d_1.aerr = 0;
	feq_gen_al_d_1.aunit = stdsys;
	f_back(&feq_gen_al_d_1);
/*       Set the default value */
/* SOURCE fequtl.for:1403 */
/*<       twod_cubic_out='NO' >*/
	s_copy(upgrdc_1.feq_gen_twod_cubic_out_d_, const_cast<char*>("NO"), (ftnlen)4, (ftnlen)2);
/* SOURCE fequtl.for:1404 */
/*<       else >*/
    } else {
/* SOURCE fequtl.for:1405 */
/*<       is=index(line,'NO') >*/
	is = i_indx(line, const_cast<char*>("NO"), (ftnlen)80, (ftnlen)2);
/* SOURCE fequtl.for:1406 */
/*<       if(is.gt.0)then >*/
	if (is > 0) {
/* SOURCE fequtl.for:1407 */
/*<       twod_cubic_out='NO' >*/
	    s_copy(upgrdc_1.feq_gen_twod_cubic_out_d_, const_cast<char*>("NO"), (ftnlen)4, (ftnlen)2);
/* SOURCE fequtl.for:1408 */
/*<       else >*/
	} else {
/* SOURCE fequtl.for:1409 */
/*<       is=index(line,'YES') >*/
	    is = i_indx(line, const_cast<char*>("YES"), (ftnlen)80, (ftnlen)3);
/* SOURCE fequtl.for:1410 */
/*<       if(is.gt.0)then >*/
	    if (is > 0) {
/* SOURCE fequtl.for:1411 */
/*<       twod_cubic_out='YES' >*/
		s_copy(upgrdc_1.feq_gen_twod_cubic_out_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3)
			;
/* SOURCE fequtl.for:1412 */
/*<       else >*/
	    } else {
/* SOURCE fequtl.for:1413 */
/*<       write(stdout,*)' Invalid response for TWOD_CUBIC_OUT' >*/
		feq_gen_io_d__144.ciunit = xscom_1.stdout;
		s_wsle(&feq_gen_io_d__144);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Invalid response for TWOD_CUBIC_OUT"), (
			ftnlen)36);
		e_wsle();
/* SOURCE fequtl.for:1414 */
/*<       write(stdout,*)' Must be : YES or NO.' >*/
		feq_gen_io_d__145.ciunit = xscom_1.stdout;
		s_wsle(&feq_gen_io_d__145);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Must be : YES or NO."), (ftnlen)21);
		e_wsle();
/* SOURCE fequtl.for:1415 */
/*<       write(stdout,*)' Setting value to NO.' >*/
		feq_gen_io_d__146.ciunit = xscom_1.stdout;
		s_wsle(&feq_gen_io_d__146);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Setting value to NO."), (ftnlen)21);
		e_wsle();
/* SOURCE fequtl.for:1416 */
/*<       twod_cubic_out='NO' >*/
		s_copy(upgrdc_1.feq_gen_twod_cubic_out_d_, const_cast<char*>("NO"), (ftnlen)4, (ftnlen)2);
/* SOURCE fequtl.for:1417 */
/*<       endif >*/
	    }
/* SOURCE fequtl.for:1418 */
/*<       endif >*/
	}
/* SOURCE fequtl.for:1419 */
/*<       endif >*/
    }
/*     seek the global home name. May not be present. */
/* SOURCE fequtl.for:1422 */
/*<       callinline(stdsys,stdout,line) >*/
    inline_(&stdsys, &xscom_1.stdout, line, (ftnlen)80);
/* SOURCE fequtl.for:1425 */
/*<       if(line(1:5).ne.'GHOME')then >*/
    if (s_cmp(line, const_cast<char*>("GHOME"), (ftnlen)5, (ftnlen)5) != 0) {
/*       Put the line back! */
/* SOURCE fequtl.for:1427 */
/*<       backspace(stdsys) >*/
	feq_gen_al_d_1.aerr = 0;
	feq_gen_al_d_1.aunit = stdsys;
	f_back(&feq_gen_al_d_1);
/*       Default value already set above */
/* SOURCE fequtl.for:1429 */
/*<       else >*/
    } else {
/*       Skip over the =, read, and then shift left to */
/*       strip leading spaces if any. */
/* SOURCE fequtl.for:1432 */
/*<       read(line(7:),'(a)')ghome >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 74;
	feq_gen_ici_d_1.iciunit = line + 6;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(a)");
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, homec_1.ghome, (ftnlen)128);
	e_rsfi();
/* SOURCE fequtl.for:1433 */
/*<       callfeq_adjustl(ghome,ghome) >*/
	feq_gen_feq_adjustl_d_(homec_1.ghome, homec_1.ghome, (ftnlen)128, (ftnlen)128);
/* SOURCE fequtl.for:1434 */
/*<       write(stdout,82)ghome(1:feq_len_trim(ghome)) >*/
	feq_gen_io_d__147.ciunit = xscom_1.stdout;
	s_wsfe(&feq_gen_io_d__147);
	do_fio(&feq_gen_c_d_1, homec_1.ghome, feq_gen_feq_len_trim_d_(homec_1.ghome, (ftnlen)
		128));
	e_wsfe();
/* SOURCE fequtl.for:1435 */
/*<       write(stdtab,88)ghome(1:feq_len_trim(ghome)) >*/
	feq_gen_io_d__148.ciunit = stdtab;
	s_wsfe(&feq_gen_io_d__148);
	do_fio(&feq_gen_c_d_1, homec_1.ghome, feq_gen_feq_len_trim_d_(homec_1.ghome, (ftnlen)
		128));
	e_wsfe();
/* SOURCE fequtl.for:1436 */
/*<       callgetsvn_rev(stdout,ghome,svn_rev,svn_mod) >*/
	feq_gen_getsvn_rev_d_(&xscom_1.stdout, homec_1.ghome, &svncom_1.feq_gen_svn_rev_d_, &
		svncom_1.feq_gen_svn_mod_d_, (ftnlen)128);
/* SOURCE fequtl.for:1438 */
/*<       if(svn_rev>0)then >*/
	if (svncom_1.feq_gen_svn_rev_d_ > 0) {
/* SOURCE fequtl.for:1439 */
/*<       write(stdtab,86)svn_rev >*/
	    feq_gen_io_d__149.ciunit = stdtab;
	    s_wsfe(&feq_gen_io_d__149);
	    do_fio(&feq_gen_c_d_1, (char *)&svncom_1.feq_gen_svn_rev_d_, (ftnlen)sizeof(integer)
		    );
	    e_wsfe();
/* SOURCE fequtl.for:1440 */
/*<       if(svn_mod>0)then >*/
	    if (svncom_1.feq_gen_svn_mod_d_ > 0) {
/* SOURCE fequtl.for:1441 */
/*<       write(stdtab,87) >*/
		feq_gen_io_d__150.ciunit = stdtab;
		s_wsfe(&feq_gen_io_d__150);
		e_wsfe();
/* SOURCE fequtl.for:1442 */
/*<       endif >*/
	    }
/* SOURCE fequtl.for:1443 */
/*<       endif >*/
	}
/* SOURCE fequtl.for:1445 */
/*<       endif >*/
    }
/*     Seek the global grid/datum/unitsys information. Consists of five lines */
/*     of input.  If the first line is present, then all five lines must be */
/*     present!  Makes life a bit simpler:) */
/* SOURCE fequtl.for:1450 */
/*<       callinline(stdsys,stdout,line) >*/
    inline_(&stdsys, &xscom_1.stdout, line, (ftnlen)80);
/* SOURCE fequtl.for:1453 */
/*<       if(line(1:6).ne.'G_ZONE')then >*/
    if (s_cmp(line, const_cast<char*>("G_ZONE"), (ftnlen)6, (ftnlen)6) != 0) {
/*       Put the line back! */
/* SOURCE fequtl.for:1455 */
/*<       backspace(stdsys) >*/
	feq_gen_al_d_1.aerr = 0;
	feq_gen_al_d_1.aunit = stdsys;
	f_back(&feq_gen_al_d_1);
/*       Set the default values */
/* SOURCE fequtl.for:1457 */
/*<       g_zone='NONE' >*/
	s_copy(feq_gen_grid_datum_d_1.feq_gen_g_zone_d_, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE fequtl.for:1458 */
/*<       g_hgrid='NONE' >*/
	s_copy(feq_gen_grid_datum_d_1.feq_gen_g_hgrid_d_, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE fequtl.for:1459 */
/*<       g_vdatum='NONE' >*/
	s_copy(feq_gen_grid_datum_d_1.feq_gen_g_vdatum_d_, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE fequtl.for:1460 */
/*<       g_unitsys='NONE' >*/
	s_copy(feq_gen_grid_datum_d_1.feq_gen_g_unitsys_d_, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE fequtl.for:1461 */
/*<       g_basis='NONE' >*/
	s_copy(feq_gen_grid_datum_d_1.feq_gen_g_basis_d_, const_cast<char*>("NONE"), (ftnlen)8, (ftnlen)4);
/* SOURCE fequtl.for:1462 */
/*<       else >*/
    } else {
/* SOURCE fequtl.for:1463 */
/*<       callget_single_named_item(stdout,line,item_name,g_zone,eflag) >*/
	feq_gen_get_single_named_item_d_(&xscom_1.stdout, line, feq_gen_item_name_d_, 
		feq_gen_grid_datum_d_1.feq_gen_g_zone_d_, &xscom_1.eflag, (ftnlen)80, (ftnlen)8,
		 (ftnlen)8);
/* SOURCE fequtl.for:1465 */
/*<       callinline(stdsys,stdout,line) >*/
	inline_(&stdsys, &xscom_1.stdout, line, (ftnlen)80);
/* SOURCE fequtl.for:1468 */
/*<       callget_single_named_item(stdout,line,item_name,g_hgrid,eflag) >*/
	feq_gen_get_single_named_item_d_(&xscom_1.stdout, line, feq_gen_item_name_d_, 
		feq_gen_grid_datum_d_1.feq_gen_g_hgrid_d_, &xscom_1.eflag, (ftnlen)80, (ftnlen)
		8, (ftnlen)8);
/* SOURCE fequtl.for:1470 */
/*<       callinline(stdsys,stdout,line) >*/
	inline_(&stdsys, &xscom_1.stdout, line, (ftnlen)80);
/* SOURCE fequtl.for:1473 */
/*<       callget_single_named_item(stdout,line,item_name,g_vdatum,eflag) >*/
	feq_gen_get_single_named_item_d_(&xscom_1.stdout, line, feq_gen_item_name_d_, 
		feq_gen_grid_datum_d_1.feq_gen_g_vdatum_d_, &xscom_1.eflag, (ftnlen)80, (ftnlen)
		8, (ftnlen)8);
/* SOURCE fequtl.for:1475 */
/*<       callinline(stdsys,stdout,line) >*/
	inline_(&stdsys, &xscom_1.stdout, line, (ftnlen)80);
/* SOURCE fequtl.for:1478 */
/*<       callget_single_named_item(stdout,line,item_name,g_unitsys,eflag) >*/
	feq_gen_get_single_named_item_d_(&xscom_1.stdout, line, feq_gen_item_name_d_, 
		feq_gen_grid_datum_d_1.feq_gen_g_unitsys_d_, &xscom_1.eflag, (ftnlen)80, (
		ftnlen)8, (ftnlen)8);
/* SOURCE fequtl.for:1480 */
/*<       callinline(stdsys,stdout,line) >*/
	inline_(&stdsys, &xscom_1.stdout, line, (ftnlen)80);
/* SOURCE fequtl.for:1483 */
/*<       callget_single_named_item(stdout,line,item_name,g_basis,eflag) >*/
	feq_gen_get_single_named_item_d_(&xscom_1.stdout, line, feq_gen_item_name_d_, 
		feq_gen_grid_datum_d_1.feq_gen_g_basis_d_, &xscom_1.eflag, (ftnlen)80, (ftnlen)
		8, (ftnlen)8);
/* SOURCE fequtl.for:1485 */
/*<       if(eflag==0)then >*/
	if (xscom_1.eflag == 0) {
/* SOURCE fequtl.for:1486 */
/*<       write(stdout,56)g_zone,g_hgrid,g_vdatum,g_unitsys,g_basis >*/
	    feq_gen_io_d__152.ciunit = xscom_1.stdout;
	    s_wsfe(&feq_gen_io_d__152);
	    do_fio(&feq_gen_c_d_1, feq_gen_grid_datum_d_1.feq_gen_g_zone_d_, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, feq_gen_grid_datum_d_1.feq_gen_g_hgrid_d_, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, feq_gen_grid_datum_d_1.feq_gen_g_vdatum_d_, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, feq_gen_grid_datum_d_1.feq_gen_g_unitsys_d_, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, feq_gen_grid_datum_d_1.feq_gen_g_basis_d_, (ftnlen)8);
	    e_wsfe();
/* SOURCE fequtl.for:1487 */
/*<       else >*/
	} else {
/* SOURCE fequtl.for:1488 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE fequtl.for:1489 */
/*<       endif >*/
	}
/* SOURCE fequtl.for:1490 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:1493 */
/*<       if(conf_flag==1)then >*/
    if (feq_gen_conf_flag_d_ == 1) {
/* SOURCE fequtl.for:1494 */
/*<       callskip_header_if_present(stdin,stdout,ncmd,cmdtab) >*/
	feq_gen_skip_header_if_present_d_(&stdin, &xscom_1.stdout, &ncmd, cmdtab, (
		ftnlen)8);
/* SOURCE fequtl.for:1496 */
/*<       endif >*/
    }
/*     We have processed all the header values and are about to begin processing commands. */
/*     At this point we analyze the master-input file to compute various md5 digests. */
/*     This will be made optional later by user input in the standard header. */
/* SOURCE fequtl.for:1502 */
/*<       if(trk_files)then >*/
    if (feq_gen_trk_files_d_) {
/* SOURCE fequtl.for:1503 */
/*<        >*/
	feq_gen_find_md5_for_fequtl_input_d_(&stdscr, &xscom_1.stdout, &stdsys, &stdin,
		 fname, &ncmd, cmdtab, cmdval, feq_gen_conf_file_d_, homec_1.ghome, (
		ftnlen)64, (ftnlen)8, (ftnlen)64, (ftnlen)128);
/* SOURCE fequtl.for:1506 */
/*<       endif >*/
    }
/*     READ NEXT COMMAND AND DETERMINE ACTION */
/* SOURCE fequtl.for:1512 */
/*<       cflag=0 >*/
    cflag = 0;
/* SOURCE fequtl.for:1513 */
/*<   500 continue >*/
L500:
/*       RESET THE EXTEND OPTION TO RECOVER THE GLOBAL VALUE */
/* SOURCE fequtl.for:1517 */
/*<       extend=gxtend >*/
    nrdzcm_1.extend = nrdzcm_1.gxtend;
/* SOURCE fequtl.for:1519 */
/*<       callnxtcmd(stdin,stdout,ncmd,cmdtab,cmdval,next) >*/
    nxtcmd_(&stdin, &xscom_1.stdout, &ncmd, cmdtab, cmdval, &next, (ftnlen)8);
/* SOURCE fequtl.for:1523 */
/*<       if(next.gt.0)goto110 >*/
    if (next > 0) {
	goto L110;
    }
/* SOURCE fequtl.for:1524 */
/*<       eflag=1 >*/
    xscom_1.eflag = 1;
/* SOURCE fequtl.for:1525 */
/*<       if(cflag.eq.1)goto105 >*/
    if (cflag == 1) {
	goto L105;
    }
/* SOURCE fequtl.for:1526 */
/*<       write(stdout,51) >*/
    feq_gen_io_d__155.ciunit = xscom_1.stdout;
    s_wsfe(&feq_gen_io_d__155);
    e_wsfe();
/* SOURCE fequtl.for:1527 */
/*<       cflag=1 >*/
    cflag = 1;
/* SOURCE fequtl.for:1528 */
/*<   105 continue >*/
L105:
/* SOURCE fequtl.for:1529 */
/*<       goto500 >*/
    goto L500;
/* SOURCE fequtl.for:1531 */
/*<   110 continue >*/
L110:
/* SOURCE fequtl.for:1532 */
/*<       if(cflag.eq.0)goto120 >*/
    if (cflag == 0) {
	goto L120;
    }
/* SOURCE fequtl.for:1533 */
/*<       write(stdout,52) >*/
    feq_gen_io_d__156.ciunit = xscom_1.stdout;
    s_wsfe(&feq_gen_io_d__156);
    e_wsfe();
/* SOURCE fequtl.for:1534 */
/*<       cflag=0 >*/
    cflag = 0;
/* SOURCE fequtl.for:1535 */
/*<   120 continue >*/
L120:
/* SOURCE fequtl.for:1537 */
/*<       gflag=gflag+eflag >*/
    gflag += xscom_1.eflag;
/* SOURCE fequtl.for:1538 */
/*<       eflag=0 >*/
    xscom_1.eflag = 0;
/* SOURCE fequtl.for:1540 */
/*<        >*/
    switch (next) {
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
	case 16:  goto L16;
	case 17:  goto L17;
	case 18:  goto L18;
	case 19:  goto L19;
	case 20:  goto L20;
	case 21:  goto L21;
	case 22:  goto L22;
	case 23:  goto L23;
	case 24:  goto L24;
	case 25:  goto L25;
	case 26:  goto L26;
	case 27:  goto L27;
	case 28:  goto L28;
	case 29:  goto L29;
	case 30:  goto L30;
	case 31:  goto L31;
	case 32:  goto L32;
	case 33:  goto L33;
	case 34:  goto L34;
	case 35:  goto L35;
	case 36:  goto L36;
	case 37:  goto L37;
	case 38:  goto L38;
	case 39:  goto L39;
	case 40:  goto L240;
	case 41:  goto L241;
	case 42:  goto L242;
	case 43:  goto L243;
	case 44:  goto L244;
    }
/* SOURCE fequtl.for:1545 */
/*<       write(stdout,*)' *BUG:501* INVALID ADDRESS FOR A COMMAND' >*/
    feq_gen_io_d__157.ciunit = xscom_1.stdout;
    s_wsle(&feq_gen_io_d__157);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:501* INVALID ADDRESS FOR A COMMAND"), (ftnlen)
	    40);
    e_wsle();
/* SOURCE fequtl.for:1546 */
/*<       write(stdout,*)' NEXT=',next >*/
    feq_gen_io_d__158.ciunit = xscom_1.stdout;
    s_wsle(&feq_gen_io_d__158);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NEXT="), (ftnlen)6);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&next, (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE fequtl.for:1547 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE fequtl.for:1549 */
/*<     1 continue >*/
L1:
/* SOURCE fequtl.for:1550 */
/*<       mode=1 >*/
    mode = 1;
/* SOURCE fequtl.for:1551 */
/*<       snflgu=0 >*/
    xscomu_1.snflgu = 0;
/* SOURCE fequtl.for:1553 */
/*<       callfeqx(stdin,stdout,stdtab,nfac,mode,tabdir,ftp,eflag) >*/
    feqx_(&stdin, &xscom_1.stdout, &stdtab, &nfac, &mode, tabdir, &ftp, &
	    xscom_1.eflag);
/* SOURCE fequtl.for:1557 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1559 */
/*<     2 continue >*/
L2:
/* SOURCE fequtl.for:1561 */
/*<       callfldin(stdin,stdout,stdfld,eflag,fhead) >*/
    fldin_(&stdin, &xscom_1.stdout, &stdfld, &xscom_1.eflag, fhead, (ftnlen)
	    91);
/* SOURCE fequtl.for:1564 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1566 */
/*<     3 continue >*/
L3:
/* SOURCE fequtl.for:1567 */
/*<       callspbrid(stdin,stdout,stdtab,nfac,tabdir,eflag) >*/
    spbrid_(&stdin, &xscom_1.stdout, &stdtab, &nfac, tabdir, &xscom_1.eflag);
/* SOURCE fequtl.for:1570 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1572 */
/*<     4 continue >*/
L4:
/*       FIND TWO-D TABLE FOR CULVERT FLOW WITH POSSIBLE FLOW OVER */
/*       THE ROADWAY */
/* SOURCE fequtl.for:1576 */
/*<       callculvrt(stdin,stdout,stdtab,nfac,tabdir,eflag,ftp,ftknt) >*/
    culvrt_(&stdin, &xscom_1.stdout, &stdtab, &nfac, tabdir, &xscom_1.eflag, &
	    ftp, &ftknt);
/*        WRITE(STDOUT,*) ' EFLAG=',EFLAG */
/* SOURCE fequtl.for:1581 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1583 */
/*<     5 continue >*/
L5:
/*       FINISH COMMAND */
/* SOURCE fequtl.for:1585 */
/*<       if(flood.eq.1)then >*/
    if (fldway_1.flood == 1) {
/*         IF FLOODWAY OPTION IS ENABLED OUTPUT SUMMARY TABLE */
/* SOURCE fequtl.for:1588 */
/*<       write(stdout,*)' ' >*/
	feq_gen_io_d__161.ciunit = xscom_1.stdout;
	s_wsle(&feq_gen_io_d__161);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
	e_wsle();
/* SOURCE fequtl.for:1589 */
/*<       write(stdout,*)' Summary of Floodway Computation results' >*/
	feq_gen_io_d__162.ciunit = xscom_1.stdout;
	s_wsle(&feq_gen_io_d__162);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Summary of Floodway Computation results"), (
		ftnlen)40);
	e_wsle();
/* SOURCE fequtl.for:1591 */
/*<       write(stdout,94) >*/
	feq_gen_io_d__163.ciunit = xscom_1.stdout;
	s_wsfe(&feq_gen_io_d__163);
	e_wsfe();
/* SOURCE fequtl.for:1593 */
/*<       do5000itaba=1,pmxtab >*/
	for (itaba = 1; itaba <= 10002; ++itaba) {
/* SOURCE fequtl.for:1595 */
/*<       if(fldopt(itaba).ne.'    ')then >*/
	    if (s_cmp(fldwyc_1.fldopt + (itaba - 1 << 2), const_cast<char*>("    "), (ftnlen)4, (
		    ftnlen)4) != 0) {
/* SOURCE fequtl.for:1596 */
/*<       if(fldrt(itaba).eq.-1.e30)then >*/
		if (fldway_1.fldrt[itaba - 1] == (float)-1e30) {
/* SOURCE fequtl.for:1597 */
/*<       right='  -inf  ' >*/
		    s_copy(right, const_cast<char*>("  -inf  "), (ftnlen)8, (ftnlen)8);
/* SOURCE fequtl.for:1598 */
/*<       else >*/
		} else {
/* SOURCE fequtl.for:1599 */
/*<       write(right,'(F8.1)')fldrt(itaba) >*/
		    feq_gen_ici_d_1.icierr = 0;
		    feq_gen_ici_d_1.icirnum = 1;
		    feq_gen_ici_d_1.icirlen = 8;
		    feq_gen_ici_d_1.iciunit = right;
		    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.1)");
		    s_wsfi(&feq_gen_ici_d_1);
		    do_fio(&feq_gen_c_d_1, (char *)&fldway_1.fldrt[itaba - 1], (ftnlen)
			    sizeof(real));
		    e_wsfi();
/* SOURCE fequtl.for:1600 */
/*<       endif >*/
		}
/* SOURCE fequtl.for:1601 */
/*<       if(fldlt(itaba).eq.1.e30)then >*/
		if (fldway_1.fldlt[itaba - 1] == (float)1e30) {
/* SOURCE fequtl.for:1602 */
/*<       left='  +inf  ' >*/
		    s_copy(left, const_cast<char*>("  +inf  "), (ftnlen)8, (ftnlen)8);
/* SOURCE fequtl.for:1603 */
/*<       else >*/
		} else {
/* SOURCE fequtl.for:1604 */
/*<       write(left,'(F8.1)')fldlt(itaba) >*/
		    feq_gen_ici_d_1.icierr = 0;
		    feq_gen_ici_d_1.icirnum = 1;
		    feq_gen_ici_d_1.icirlen = 8;
		    feq_gen_ici_d_1.iciunit = left;
		    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.1)");
		    s_wsfi(&feq_gen_ici_d_1);
		    do_fio(&feq_gen_c_d_1, (char *)&fldway_1.fldlt[itaba - 1], (ftnlen)
			    sizeof(real));
		    e_wsfi();
/* SOURCE fequtl.for:1605 */
/*<       endif >*/
		}
/* SOURCE fequtl.for:1606 */
/*<       if(feqbot(itaba).eq.-1.e30)then >*/
		if (fldway_1.feqbot[itaba - 1] == (float)-1e30) {
/* SOURCE fequtl.for:1607 */
/*<       bot='  same  ' >*/
		    s_copy(bot, const_cast<char*>("  same  "), (ftnlen)8, (ftnlen)8);
/* SOURCE fequtl.for:1608 */
/*<       else >*/
		} else {
/* SOURCE fequtl.for:1609 */
/*<       write(bot,'(F8.2)')feqbot(itaba) >*/
		    feq_gen_ici_d_1.icierr = 0;
		    feq_gen_ici_d_1.icirnum = 1;
		    feq_gen_ici_d_1.icirlen = 8;
		    feq_gen_ici_d_1.iciunit = bot;
		    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.2)");
		    s_wsfi(&feq_gen_ici_d_1);
		    do_fio(&feq_gen_c_d_1, (char *)&fldway_1.feqbot[itaba - 1], (
			    ftnlen)sizeof(real));
		    e_wsfi();
/* SOURCE fequtl.for:1610 */
/*<       endif >*/
		}
/* SOURCE fequtl.for:1611 */
/*<       tabid=get_tabid(itaba) >*/
		feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &itaba);
		s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE fequtl.for:1612 */
/*<       gisid=get_gisid(ftpnt(itaba)) >*/
		feq_gen_get_gisid_d_(feq_gen_ch_d_1, (ftnlen)16, &ftablea_1.ftpnt[itaba - 1]);
		s_copy(gisid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE fequtl.for:1613 */
/*<       if(fldflow(itaba).gt.0.0)then >*/
		if (fldway_1.fldflow[itaba - 1] > (float)0.) {
/* SOURCE fequtl.for:1614 */
/*<       velocity=fldflow(itaba)/fldarea(itaba) >*/
		    velocity = static_cast<double>(fldway_1.fldflow[itaba - 1]) / fldway_1.fldarea[
			    itaba - 1];
/* SOURCE fequtl.for:1615 */
/*<       else >*/
		} else {
/* SOURCE fequtl.for:1616 */
/*<       velocity=0.0 >*/
		    velocity = (float)0.;
/* SOURCE fequtl.for:1617 */
/*<       endif >*/
		}
/* SOURCE fequtl.for:1618 */
/*<        >*/
		feq_gen_io_d__171.ciunit = xscom_1.stdout;
		s_wsfe(&feq_gen_io_d__171);
		do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, gisid, (ftnlen)16);
		do_fio(&feq_gen_c_d_1, fldwyc_1.fldopt + (itaba - 1 << 2), (ftnlen)4);
		do_fio(&feq_gen_c_d_1, (char *)&fldway_1.fldelv[itaba - 1], (ftnlen)
			sizeof(real));
		do_fio(&feq_gen_c_d_1, bot, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, left, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, right, (ftnlen)8);
		do_fio(&feq_gen_c_d_1, (char *)&fldway_1.fldlos[itaba - 1], (ftnlen)
			sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&fldway_1.fldarea[itaba - 1], (ftnlen)
			sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&velocity, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE fequtl.for:1621 */
/*<       endif >*/
	    }
/* SOURCE fequtl.for:1622 */
/*<  5000 continue >*/
/* L5000: */
	}
/* SOURCE fequtl.for:1624 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:1625 */
/*<       write(*,*)' FINISH found.' >*/
    s_wsle(&feq_gen_io_d__172);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FINISH found."), (ftnlen)14);
    e_wsle();
/* SOURCE fequtl.for:1626 */
/*<       if(gflag.gt.0)then >*/
    if (gflag > 0) {
/* SOURCE fequtl.for:1627 */
/*<       write(stdout,54) >*/
	feq_gen_io_d__173.ciunit = xscom_1.stdout;
	s_wsfe(&feq_gen_io_d__173);
	e_wsfe();
/* SOURCE fequtl.for:1628 */
/*<       write(*,*)' Errors reported.' >*/
	s_wsle(&feq_gen_io_d__174);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Errors reported."), (ftnlen)17);
	e_wsle();
/* SOURCE fequtl.for:1629 */
/*<       else >*/
    } else {
/* SOURCE fequtl.for:1630 */
/*<       write(*,*)' No errors reported.' >*/
	s_wsle(&feq_gen_io_d__175);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" No errors reported."), (ftnlen)20);
	e_wsle();
/* SOURCE fequtl.for:1631 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:1636 */
/*<       stop >*/
    s_stop(const_cast<char*>(""), (ftnlen)0);
/* SOURCE fequtl.for:1638 */
/*<     6 continue >*/
L6:
/*        CALL SAME(STDIN,STDOUT,EFLAG) */
/* SOURCE fequtl.for:1640 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1642 */
/*<     7 continue >*/
L7:
/*       PROCESS CROSS SECTION FROM DIGITIZER */
/*       DISABLE SINUOSITY ELEMENTS */
/* SOURCE fequtl.for:1645 */
/*<       snflgu=0 >*/
    xscomu_1.snflgu = 0;
/* SOURCE fequtl.for:1646 */
/*<       mode=3 >*/
    mode = 3;
/* SOURCE fequtl.for:1647 */
/*<       callfeqx(stdin,stdout,stdtab,nfac,mode,tabdir,ftp,eflag) >*/
    feqx_(&stdin, &xscom_1.stdout, &stdtab, &nfac, &mode, tabdir, &ftp, &
	    xscom_1.eflag);
/* SOURCE fequtl.for:1651 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1653 */
/*<     8 continue >*/
L8:
/*       PROCESS CROSS SECTION IN LIST FORMAT */
/*       DISABLE SINUOSITY ELEMENTS */
/* SOURCE fequtl.for:1657 */
/*<       snflgu=0 >*/
    xscomu_1.snflgu = 0;
/* SOURCE fequtl.for:1658 */
/*<       mode=2 >*/
    mode = 2;
/* SOURCE fequtl.for:1659 */
/*<       callfeqx(stdin,stdout,stdtab,nfac,mode,tabdir,ftp,eflag) >*/
    feqx_(&stdin, &xscom_1.stdout, &stdtab, &nfac, &mode, tabdir, &ftp, &
	    xscom_1.eflag);
/* SOURCE fequtl.for:1663 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1664 */
/*<     9 continue >*/
L9:
/*       COMPUTE FLOW OVER THE ROADWAY FROM A CROSS-SECTION TABLE */
/*       ASSUMING CRITICAL DEPTH AND THAT VELOCITY HEAD OF APPROACH */
/*       WILL BE USED FOR THE HEAD ON THE RESULTING TABLE. */
/*       THE USER SUPPLIES INFORMATION ON THE TABLE INTERVAL AS WELL */
/*       AS A FACTOR TO USE TO REDUCE CRITICAL FLOW. */
/*        CALL FNDRF(STDIN, STDOUT, STDTAB, NFAC, TABDIR, */
/*     A                 EFLAG) */
/* SOURCE fequtl.for:1673 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1675 */
/*<    10 continue >*/
L10:
/*       FIND CROSS SECTION TABLE FOR A SEWER PIPE. */
/* SOURCE fequtl.for:1677 */
/*<       callsewer(stdin,stdout,stdtab,nfac,tabdir,eflag,ftp) >*/
    sewer_(&stdin, &xscom_1.stdout, &stdtab, &nfac, tabdir, &xscom_1.eflag, &
	    ftp);
/* SOURCE fequtl.for:1680 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1682 */
/*<    11 continue >*/
L11:
/*       FIND CROSS SECTION TABLE FOR MULTIPLE SEWER PIPES */
/* SOURCE fequtl.for:1684 */
/*<       callpipes(stdin,stdout,stdtab,nfac,tabdir,eflag,ftp) >*/
    pipes_(&stdin, &xscom_1.stdout, &stdtab, &nfac, tabdir, &xscom_1.eflag, &
	    ftp);
/* SOURCE fequtl.for:1687 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1689 */
/*<    12 continue >*/
L12:
/*       INPUT FUNCTION TABLES FOR ACCESS BY SUBSEQUENT COMMANDS. */
/* SOURCE fequtl.for:1691 */
/*<       write(*,90) >*/
    s_wsfe(&feq_gen_io_d__176);
    e_wsfe();
/* SOURCE fequtl.for:1693 */
/*<       hslot=0.0 >*/
    hslot = (float)0.;
/* SOURCE fequtl.for:1694 */
/*<       is=stdin >*/
    is = stdin;
/* SOURCE fequtl.for:1695 */
/*<  1200 continue >*/
L1200:
/* SOURCE fequtl.for:1696 */
/*<       make_tab_index='NO  ' >*/
    s_copy(mktbindxc_1.feq_gen_make_tab_index_d_, const_cast<char*>("NO  "), (ftnlen)4, (ftnlen)4);
/* SOURCE fequtl.for:1697 */
/*<       current_file=' ' >*/
    s_copy(feq_gen_current_file_d_, const_cast<char*>(" "), (ftnlen)128, (ftnlen)1);
/* SOURCE fequtl.for:1698 */
/*<       index_knt=0 >*/
    mktbindx_1.feq_gen_index_knt_d_ = 0;
/* SOURCE fequtl.for:1699 */
/*<        >*/
    ftabin_(&is, &stdin, &xscom_1.stdout, &xscom_1.output, &ftp, &feq_gen_c_d_10002, &
	    c_b506, &hslot, feq_gen_current_file_d_, &xscom_1.eflag, &ftknt, 
	    ftablea_1.ftpnt, &table, nxtnam, (ftnlen)128, (ftnlen)128);
/* SOURCE fequtl.for:1705 */
/*<       if(table.eq.-1)goto300 >*/
    if (table == -1) {
	goto L300;
    }
/* SOURCE fequtl.for:1706 */
/*<       if(is.ne.stdin)then >*/
    if (is != stdin) {
/* SOURCE fequtl.for:1707 */
/*<       callfree_unit(stdout,is) >*/
	feq_gen_free_unit_d_(&xscom_1.stdout, &is);
/* SOURCE fequtl.for:1708 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:1710 */
/*<       if(table.eq.-15)then >*/
    if (table == -15) {
/* SOURCE fequtl.for:1711 */
/*<       is=get_unit(stdout) >*/
	is = feq_gen_get_unit_d_(&xscom_1.stdout);
/* SOURCE fequtl.for:1712 */
/*<       inquire(file=nxtnam,exist=there) >*/
	feq_gen_ioin_d_1.inerr = 0;
	feq_gen_ioin_d_1.infilen = 128;
	feq_gen_ioin_d_1.infile = nxtnam;
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
/* SOURCE fequtl.for:1713 */
/*<       if(there)then >*/
	if (there) {
/* SOURCE fequtl.for:1714 */
/*<       open(unit=is,file=nxtnam,status='OLD') >*/
	    feq_gen_o_d_1.oerr = 0;
	    feq_gen_o_d_1.ounit = is;
	    feq_gen_o_d_1.ofnmlen = 128;
	    feq_gen_o_d_1.ofnm = nxtnam;
	    feq_gen_o_d_1.orl = 0;
	    feq_gen_o_d_1.osta = const_cast<char*>("OLD");
	    feq_gen_o_d_1.oacc = 0;
	    feq_gen_o_d_1.ofm = 0;
	    feq_gen_o_d_1.oblnk = 0;
	    f_open(&feq_gen_o_d_1);
/* SOURCE fequtl.for:1715 */
/*<       else >*/
	} else {
/* SOURCE fequtl.for:1716 */
/*<       write(stdout,*)' FILE NAMED:',nxtnam,' NOT FOUND.' >*/
	    feq_gen_io_d__180.ciunit = xscom_1.stdout;
	    s_wsle(&feq_gen_io_d__180);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FILE NAMED:"), (ftnlen)12);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, nxtnam, (ftnlen)128);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" NOT FOUND."), (ftnlen)11);
	    e_wsle();
/* SOURCE fequtl.for:1717 */
/*<       write(stdout,*)' CHECK FUNCTION TABLE FILE NAME.' >*/
	    feq_gen_io_d__181.ciunit = xscom_1.stdout;
	    s_wsle(&feq_gen_io_d__181);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" CHECK FUNCTION TABLE FILE NAME."), (ftnlen)
		    32);
	    e_wsle();
/* SOURCE fequtl.for:1718 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE fequtl.for:1719 */
/*<       endif >*/
	}
/* SOURCE fequtl.for:1720 */
/*<       elseif(table.eq.-16)then >*/
    } else if (table == -16) {
/*           Set the local value of the home directory */
/* SOURCE fequtl.for:1722 */
/*<       callset_home(nxtnam) >*/
	feq_gen_set_home_d_(nxtnam, (ftnlen)128);
/*           Check for version control and report */
/* SOURCE fequtl.for:1725 */
/*<       callgetsvn_rev(stdout,nxtnam,svn_rev,svn_mod) >*/
	feq_gen_getsvn_rev_d_(&xscom_1.stdout, nxtnam, &svncom_1.feq_gen_svn_rev_d_, &
		svncom_1.feq_gen_svn_mod_d_, (ftnlen)128);
/* SOURCE fequtl.for:1727 */
/*<       write(stdtab,89)nxtnam >*/
	feq_gen_io_d__182.ciunit = stdtab;
	s_wsfe(&feq_gen_io_d__182);
	do_fio(&feq_gen_c_d_1, nxtnam, (ftnlen)128);
	e_wsfe();
/* SOURCE fequtl.for:1728 */
/*<       if(svn_rev>0)then >*/
	if (svncom_1.feq_gen_svn_rev_d_ > 0) {
/* SOURCE fequtl.for:1729 */
/*<       write(stdtab,86)svn_rev >*/
	    feq_gen_io_d__183.ciunit = stdtab;
	    s_wsfe(&feq_gen_io_d__183);
	    do_fio(&feq_gen_c_d_1, (char *)&svncom_1.feq_gen_svn_rev_d_, (ftnlen)sizeof(integer)
		    );
	    e_wsfe();
/* SOURCE fequtl.for:1730 */
/*<       if(svn_mod>0)then >*/
	    if (svncom_1.feq_gen_svn_mod_d_ > 0) {
/* SOURCE fequtl.for:1731 */
/*<       write(stdtab,87) >*/
		feq_gen_io_d__184.ciunit = stdtab;
		s_wsfe(&feq_gen_io_d__184);
		e_wsfe();
/* SOURCE fequtl.for:1732 */
/*<       endif >*/
	    }
/* SOURCE fequtl.for:1733 */
/*<       endif >*/
	}
/* SOURCE fequtl.for:1736 */
/*<       else >*/
    } else {
/* SOURCE fequtl.for:1737 */
/*<       is=stdin >*/
	is = stdin;
/* SOURCE fequtl.for:1738 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:1740 */
/*<       goto1200 >*/
    goto L1200;
/* SOURCE fequtl.for:1741 */
/*<   300 continue >*/
L300:
/* SOURCE fequtl.for:1742 */
/*<       if(is.ne.stdin)then >*/
    if (is != stdin) {
/* SOURCE fequtl.for:1743 */
/*<       callfree_unit(stdout,is) >*/
	feq_gen_free_unit_d_(&xscom_1.stdout, &is);
/* SOURCE fequtl.for:1744 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:1746 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__185.ciunit = xscom_1.stdout;
    s_wsle(&feq_gen_io_d__185);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE fequtl.for:1747 */
/*<        >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = xscom_1.stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(' There are now',I7,                              ' func\
tion tables stored')");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&ftknt, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE fequtl.for:1749 */
/*<        >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = xscom_1.stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(3X, I9,' locations out of ',I9,' are used')");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&ftp, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&c_b506, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE fequtl.for:1751 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1753 */
/*<    13 continue >*/
L13:
/*       COMPUTE FLOW OVER EMBANKMENT SHAPED WEIRS USING USGS */
/*       PROCEDURE */
/* SOURCE fequtl.for:1756 */
/*<       callembank(stdin,stdout,stdtab,minq,eflag,ftp) >*/
    embank_(&stdin, &xscom_1.stdout, &stdtab, &minq, &xscom_1.eflag, &ftp);
/* SOURCE fequtl.for:1759 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1761 */
/*<    14 continue >*/
L14:
/*       COMPUTE HYDRAULIC JUMP TABLE FOR FORCED JUMP LOCATION */
/*        CALL JUMP(STDIN, STDOUT, STDTAB) */
/* SOURCE fequtl.for:1764 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1766 */
/*<    15 continue >*/
L15:
/*       COMPUTE CRITICAL FLOW TABLE FOR A CONSTRICTION ASSUMING */
/*       NO DOWNSTREAM EFFECT */
/* SOURCE fequtl.for:1769 */
/*<       callcritq(grav,stdin,stdout,stdtab,eflag,ftp) >*/
    critq_(&grvcom_1.grav, &stdin, &xscom_1.stdout, &stdtab, &xscom_1.eflag, &
	    ftp);
/* SOURCE fequtl.for:1772 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1774 */
/*<    16 continue >*/
L16:
/*       FIND THE PEAK FLOW FROM THE GENERALIZED RITTER SOLUTION */
/* SOURCE fequtl.for:1777 */
/*<       callritter(grav,stdin,stdout,eflag) >*/
    ritter_(&grvcom_1.grav, &stdin, &xscom_1.stdout, &xscom_1.eflag);
/* SOURCE fequtl.for:1780 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1782 */
/*<    17 continue >*/
L17:
/*       FIND THE FRACTION OF MAXIMUM CAPACITY AS A FUNCTION OF TIME */

/*        CALL PFIND(GRAV, STDIN, STDOUT, STDTAB, EFLAG) */
/* SOURCE fequtl.for:1786 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1788 */
/*<    18 continue >*/
L18:
/*       FIND CROSS SECTION TABLE FOR MULTIPLE CONDUITS */
/* SOURCE fequtl.for:1792 */
/*<       callmulcon(stdin,stdout,stdtab,nfac,tabdir,eflag,ftp) >*/
    mulcon_(&stdin, &xscom_1.stdout, &stdtab, &nfac, tabdir, &xscom_1.eflag, &
	    ftp);
/* SOURCE fequtl.for:1796 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1798 */
/*<    19 continue >*/
L19:
/*       FIND TWO-D TABLE FOR FLOW THROUGH A PRISMATIC CHANNEL */
/*       AT SUBCRTICAL SLOPE. */
/* SOURCE fequtl.for:1802 */
/*<       callchntab(stdin,stdout,stdtab,grav,minq,tabdir,eflag,ftp) >*/
    chntab_(&stdin, &xscom_1.stdout, &stdtab, &grvcom_1.grav, &minq, tabdir, &
	    xscom_1.eflag, &ftp);
/*        WRITE(STDOUT,*) ' EFLAG=',EFLAG */
/* SOURCE fequtl.for:1807 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1809 */
/*<    20 continue >*/
L20:
/*       FIND TWO-D TABLE FOR FLOW THROUGH A TRANSITION. */
/* SOURCE fequtl.for:1811 */
/*<       callexpcon(stdin,stdout,stdtab,grav,tabdir,eflag) >*/
    expcon_(&stdin, &xscom_1.stdout, &stdtab, &grvcom_1.grav, tabdir, &
	    xscom_1.eflag);
/* SOURCE fequtl.for:1815 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1817 */
/*<    21 continue >*/
L21:
/*       COMPUTE CROSS SECTION TABLES OR PRODUCE FEQX INPUT FROM */
/*       HEC2 INPUT FILES. */
/* SOURCE fequtl.for:1821 */
/*<       callhec2x(stdin,stdout,stdtab,nfac,tabdir,ftp,eflag) >*/
    hec2x_(&stdin, &xscom_1.stdout, &stdtab, &nfac, tabdir, &ftp, &
	    xscom_1.eflag);
/* SOURCE fequtl.for:1825 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1827 */
/*<    22 continue >*/
L22:
/*       COMPUTE A LIMIT TO THE CRITICAL FLOW IN A CLOSED CONDUIT */
/*       CROSS SECTION */
/* SOURCE fequtl.for:1830 */
/*<       callqclim(stdin,stdout,eflag) >*/
    qclim_(&stdin, &xscom_1.stdout, &xscom_1.eflag);
/* SOURCE fequtl.for:1833 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1835 */
/*<    23 continue >*/
L23:
/*       INTERPOLATE AND OUTPUT CROSS SECTIONS */
/* SOURCE fequtl.for:1838 */
/*<       callxstmak(stdin,stdout,stdtab,eflag,ftp,ftknt) >*/
    xstmak_(&stdin, &xscom_1.stdout, &stdtab, &xscom_1.eflag, &ftp, &ftknt);
/* SOURCE fequtl.for:1841 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1843 */
/*<    24 continue >*/
L24:
/*        CALL SDWEIR(GRAV, STDIN, STDOUT, STDTAB, EFLAG, FTP, FTKNT) */
/* SOURCE fequtl.for:1846 */
/*<       write(stdout,*)' SIDEWEIR NOT YET COMPLETE' >*/
    feq_gen_io_d__186.ciunit = xscom_1.stdout;
    s_wsle(&feq_gen_io_d__186);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" SIDEWEIR NOT YET COMPLETE"), (ftnlen)26);
    e_wsle();
/* SOURCE fequtl.for:1847 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1849 */
/*<    25 continue >*/
L25:
/* SOURCE fequtl.for:1850 */
/*<       mode=0 >*/
    mode = 0;
/*       DISABLE SINUOSITY ELEMENTS */
/* SOURCE fequtl.for:1852 */
/*<       snflgu=0 >*/
    xscomu_1.snflgu = 0;
/* SOURCE fequtl.for:1853 */
/*<       callfqxe(stdin,stdout,stdtab,nfac,tabdir,ftp,eflag) >*/
    fqxe_(&stdin, &xscom_1.stdout, &stdtab, &nfac, tabdir, &ftp, &
	    xscom_1.eflag);
/* SOURCE fequtl.for:1857 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1859 */
/*<    26 continue >*/
L26:
/* SOURCE fequtl.for:1860 */
/*<       callchanel(stdin,stdout,stdtab,nfac,tabdir,ftp,eflag,mode) >*/
    chanel_(&stdin, &xscom_1.stdout, &stdtab, &nfac, tabdir, &ftp, &
	    xscom_1.eflag, &mode);
/* SOURCE fequtl.for:1864 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1866 */
/*<    27 continue >*/
L27:
/* SOURCE fequtl.for:1867 */
/*<       callwprox(stdin,stdout,stdtab,nfac,tabdir,ftp,eflag) >*/
    wprox_(&stdin, &xscom_1.stdout, &stdtab, &nfac, tabdir, &ftp, &
	    xscom_1.eflag);
/* SOURCE fequtl.for:1871 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1873 */
/*<    28 continue >*/
L28:
/* SOURCE fequtl.for:1874 */
/*<       callwproqz(stdin,stdout,eflag) >*/
    wproqz_(&stdin, &xscom_1.stdout, &xscom_1.eflag);
/* SOURCE fequtl.for:1877 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1879 */
/*<    29 continue >*/
L29:
/* SOURCE fequtl.for:1880 */
/*<       callwpro14(stdin,stdout,stdtab,tabdir,eflag) >*/
    wpro14_(&stdin, &xscom_1.stdout, &stdtab, tabdir, &xscom_1.eflag);
/* SOURCE fequtl.for:1883 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1885 */
/*<    30 continue >*/
L30:
/* SOURCE fequtl.for:1886 */
/*<       callufgate(grav,stdin,stdout,stdtab,eflag,tabdir) >*/
    ufgate_(&grvcom_1.grav, &stdin, &xscom_1.stdout, &stdtab, &xscom_1.eflag, 
	    tabdir);
/* SOURCE fequtl.for:1889 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1890 */
/*<    31 continue >*/
L31:
/* SOURCE fequtl.for:1891 */
/*<       callriserclv(grav,stdin,stdout,stdtab,eflag,tabdir) >*/
    riserclv_(&grvcom_1.grav, &stdin, &xscom_1.stdout, &stdtab, &
	    xscom_1.eflag, tabdir);
/* SOURCE fequtl.for:1894 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1895 */
/*<    32 continue >*/
L32:
/* SOURCE fequtl.for:1896 */
/*<       callorifice(grav,stdin,stdout,stdtab,eflag,tabdir,ftp) >*/
    orifice_(&grvcom_1.grav, &stdin, &xscom_1.stdout, &stdtab, &xscom_1.eflag,
	     tabdir, &ftp);
/* SOURCE fequtl.for:1899 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1901 */
/*<    33 continue >*/
L33:
/* SOURCE fequtl.for:1902 */
/*<       callpumpitems('SFWMD   ',grav,stdin,stdout,stdtab,eflag,ftp) >*/
    pumpitems_(const_cast<char*>("SFWMD   "), &grvcom_1.grav, &stdin, &xscom_1.stdout, &stdtab, &
	    xscom_1.eflag, &ftp, (ftnlen)8);
/* SOURCE fequtl.for:1905 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1907 */
/*<    34 continue >*/
L34:
/* SOURCE fequtl.for:1908 */
/*<       callpumpitems('PUMPLOSS',grav,stdin,stdout,stdtab,eflag,ftp) >*/
    pumpitems_(const_cast<char*>("PUMPLOSS"), &grvcom_1.grav, &stdin, &xscom_1.stdout, &stdtab, &
	    xscom_1.eflag, &ftp, (ftnlen)8);
/* SOURCE fequtl.for:1911 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1913 */
/*<    35 continue >*/
L35:
/* SOURCE fequtl.for:1914 */
/*<       callset_slot(stdin,stdout,stdtab) >*/
    feq_gen_set_slot_d_(&stdin, &xscom_1.stdout, &stdtab);
/* SOURCE fequtl.for:1915 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1917 */
/*<    36 continue >*/
L36:
/* SOURCE fequtl.for:1918 */
/*<       callclear_slot(stdtab) >*/
    feq_gen_clear_slot_d_(&stdtab);
/* SOURCE fequtl.for:1919 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1921 */
/*<    37 continue >*/
L37:
/* SOURCE fequtl.for:1922 */
/*<       callinv_gate(grav,stdin,stdout,stdtab,eflag,tabdir) >*/
    feq_gen_inv_gate_d_(&grvcom_1.grav, &stdin, &xscom_1.stdout, &stdtab, &
	    xscom_1.eflag, tabdir);
/* SOURCE fequtl.for:1924 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1926 */
/*<    38 continue >*/
L38:
/* SOURCE fequtl.for:1927 */
/*<       callufgculv(grav,stdin,stdout,stdtab,ftp,eflag,tabdir) >*/
    ufgculv_(&grvcom_1.grav, &stdin, &xscom_1.stdout, &stdtab, &ftp, &
	    xscom_1.eflag, tabdir);
/* SOURCE fequtl.for:1930 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1932 */
/*<    39 continue >*/
L39:
/* SOURCE fequtl.for:1933 */
/*<       callmkembank(stdin,stdout,eflag) >*/
    mkembank_(&stdin, &xscom_1.stdout, &xscom_1.eflag);
/* SOURCE fequtl.for:1934 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1937 */
/*<   240 continue >*/
L240:
/* SOURCE fequtl.for:1938 */
/*<       callmkwspro(stdin,stdout,tabdir,eflag) >*/
    mkwspro_(&stdin, &xscom_1.stdout, tabdir, &xscom_1.eflag);
/* SOURCE fequtl.for:1940 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1942 */
/*<   241 continue >*/
L241:
/* SOURCE fequtl.for:1943 */
/*<       callwpro14_new(stdin,stdout,stdtab,tabdir,eflag) >*/
    feq_gen_wpro14_new_d_(&stdin, &xscom_1.stdout, &stdtab, tabdir, &xscom_1.eflag);
/* SOURCE fequtl.for:1946 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1948 */
/*<   242 continue >*/
L242:
/* SOURCE fequtl.for:1949 */
/*<       calllprfit(stdin,stdout,stdtab,ftp,eflag) >*/
    lprfit_(&stdin, &xscom_1.stdout, &stdtab, &ftp, &xscom_1.eflag);
/* SOURCE fequtl.for:1952 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1955 */
/*<   243 continue >*/
L243:
/* SOURCE fequtl.for:1956 */
/*<       callmakelakexs(stdin,stdout,eflag) >*/
    makelakexs_(&stdin, &xscom_1.stdout, &xscom_1.eflag);
/* SOURCE fequtl.for:1958 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1960 */
/*<   244 continue >*/
L244:
/* SOURCE fequtl.for:1961 */
/*<       callset_slote(stdin,stdout,stdtab) >*/
    feq_gen_set_slote_d_(&stdin, &xscom_1.stdout, &stdtab);
/* SOURCE fequtl.for:1963 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE fequtl.for:1965 */
/*<  1000 continue >*/
L1000:
/* SOURCE fequtl.for:1968 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__187.ciunit = xscom_1.stdout;
    s_wsle(&feq_gen_io_d__187);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE fequtl.for:1969 */
/*<       gflag=gflag+eflag >*/
    gflag += xscom_1.eflag;
/* SOURCE fequtl.for:1970 */
/*<       eflag=0 >*/
    xscom_1.eflag = 0;
/* SOURCE fequtl.for:1971 */
/*<       goto500 >*/
    goto L500;
/* SOURCE fequtl.for:1972 */
/*<   991 continue >*/
L991:
/* SOURCE fequtl.for:1973 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__188.ciunit = xscom_1.stdout;
    s_wsle(&feq_gen_io_d__188);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE fequtl.for:1974 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__189.ciunit = xscom_1.stdout;
    s_wsle(&feq_gen_io_d__189);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE fequtl.for:1975 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE fequtl.for:1977 */
/*<       end >*/
    return 0;
} /* MAIN__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE fequtl.for:1982 */
/*<       subroutineskip_header_if_present(stdin,stdout,ncmd,cmdtab) >*/
/* Subroutine */ int feq_gen_skip_header_if_present_d_(integer *stdin, integer *stdout,
	 integer *ncmd, char *feq_storage_cmdtab, ftnlen cmdtab_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    alist feq_gen_al_d_1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer f_back(alist *);

    /* Local variables */
    integer feq_gen_i_d_;
    char line[80];
    integer match;
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__191 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__194 = { 0, 6, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Read files from stdin, skipping any header block lines */
/*     and returning with stdin set so that it is at the first */
/*     command.  Depends on the first command, at least, not having */
/*     anything following it on its line.   That has been my practice */
/*     but it is not strictly required.  ddf 8 June 2004. */
/* SOURCE fequtl.for:1992 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE fequtl.for:1995 */
/*<       integerncmd,stdin,stdout >*/
/* SOURCE fequtl.for:1996 */
/*<       charactercmdtab(ncmd)*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     NCMD   - Number of commands */
/*     CMDTAB - Vector holding the command names */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE fequtl.for:2005 */
/*<       integeri,match >*/
/* SOURCE fequtl.for:2006 */
/*<       characterline*80 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE fequtl.for:2009 */
/*<       externalbinser,inline >*/
/* *********************************************************************** */
/*     Read first 80 chars of each line, see if the line will match */
/*     any of the commands.  If not, go get the next line, otherwise, */
/*     backspace stdin, and exit. */
/* SOURCE fequtl.for:2016 */
/*<   100 continue >*/
    /* Parameter adjustments */
    feq::IndexedPointer<char> cmdtab(feq_storage_cmdtab, 8);

    /* Function Body */
L100:
/* SOURCE fequtl.for:2018 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE fequtl.for:2022 */
/*<       if(line=='ENDFILE')then >*/
    if (s_cmp(line, const_cast<char*>("ENDFILE"), (ftnlen)80, (ftnlen)7) == 0) {
/* SOURCE fequtl.for:2023 */
/*<       write(*,*)' No commands found in master-input file.' >*/
	s_wsle(&feq_gen_io_d__191);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" No commands found in master-input file."), (
		ftnlen)40);
	e_wsle();
/* SOURCE fequtl.for:2024 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE fequtl.for:2025 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:2026 */
/*<       match=0 >*/
    match = 0;
/* SOURCE fequtl.for:2027 */
/*<       doi=1,ncmd >*/
    feq_gen_i_d_1 = *ncmd;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE fequtl.for:2028 */
/*<       if(line==cmdtab(i))then >*/
	if (s_cmp(line, cmdtab + (feq_gen_i_d_ << 3), (ftnlen)80, (ftnlen)8) == 0) {
/* SOURCE fequtl.for:2029 */
/*<       match=1 >*/
	    match = 1;
/* SOURCE fequtl.for:2030 */
/*<       goto99000 >*/
	    goto L99000;
/* SOURCE fequtl.for:2031 */
/*<       endif >*/
	}
/* SOURCE fequtl.for:2032 */
/*<       enddo >*/
    }
/* SOURCE fequtl.for:2032 */
/*< 99000 continue >*/
L99000:
/* SOURCE fequtl.for:2034 */
/*<       if(match==0)then >*/
    if (match == 0) {
/* SOURCE fequtl.for:2036 */
/*<       goto100 >*/
	goto L100;
/* SOURCE fequtl.for:2038 */
/*<       else >*/
    } else {
/* SOURCE fequtl.for:2039 */
/*<       backspace(stdin) >*/
	feq_gen_al_d_1.aerr = 0;
	feq_gen_al_d_1.aunit = *stdin;
	f_back(&feq_gen_al_d_1);
/* SOURCE fequtl.for:2040 */
/*<       return >*/
	return 0;
/* SOURCE fequtl.for:2041 */
/*<       endif >*/
    }
/* SOURCE fequtl.for:2043 */
/*<       write(*,*)'bug in handling configuration file.' >*/
    s_wsle(&feq_gen_io_d__194);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("bug in handling configuration file."), (ftnlen)35);
    e_wsle();
/* SOURCE fequtl.for:2044 */
/*<       stop'Abnormal stop. Bug found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Bug found."), (ftnlen)25);
/* SOURCE fequtl.for:2045 */
/*<       end >*/
    return 0;
} /* skip_header_if_present__ */

/* Main program alias */ int fequtl_ () { feq_gen_MAIN_d_ (); return 0; }
#ifdef __cplusplus
	}
#endif
