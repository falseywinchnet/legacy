/* sideweir.f -- translated by f2c (version 20240504).
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

/* COMMON enelem_ is declared in common.hpp. */

#define enelem_1 enelem_

/* Table of constant values */

static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_3 = 3;

/*     Code for checking conditions at side weirs */



/* SOURCE sideweir.for:5 */
/*<       subroutineside_weir_chk(stdout,grav,nex,exnodt,ept,emc) >*/
/* Subroutine */ int feq_gen_side_weir_chk_d_(integer *stdout, real *grav, integer *
	nex, integer *feq_storage_exnodt, integer *ept, integer *feq_storage_emc)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 Starting check of Side-Weir Instruction\
s\002)";
    static char fmt_51[] = "(/,\002 End  check of Side-Weir Instructions\002)"
	    ;
    static char fmt_53[] = "(\002   Ups    Invert  Wat-Surf   Dns   Mid    I\
nvert  Wat-Surf  \002,\002Hd-Datum  Invert    Flow  Dis-  \002,/,\002  Node \
Elevation Elevation  Node  Node Elevation Elevation \002,\002Elevation    Hi\
gh NonZero   abled\002,/,\002 ----- --------- --------- ----- ----- --------\
- ---------\002,\002 --------- ------- ------- -------\002)";
    static char fmt_54[] = "(1x,a5,f10.3,f10.3,1x,a5,1x,a5,f10.3,f10.3,f10.3\
,4x,a4,4x,a4,4x,a4)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5], feq_gen_ch_d_3[5], feq_gen_ch_d_4[5], feq_gen_ch_d_5[5], feq_gen_ch_d_6[5];
    static real equiv_2[1];

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(), s_wsle(cilist *), do_lio(integer *, 
	    integer *, char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), do_fio(integer *, char *, 
	    ftnlen);

    /* Local variables */
    char disabled[4];
    real feq_gen_max_diff_d_, feq_gen_max_diff_in_feet_d_;
    integer j;
    char feq_gen_q_non_zero_d_[4];
    integer mdn, dnn, upn;
    real zup;
    char feq_gen_invert_high_d_[4];
    integer code;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer adrs;
#define idum (feq::BitView<integer>(equiv_2, sizeof(equiv_2)))
    real zmid;
#define rdum (equiv_2)
    real zbup;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real zbmid;
    integer tadrs, itype;
    extern doublereal gethdd_(integer *);
    real hdatum;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);
    extern doublereal feq_gen_get_slot_depth_d_(integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__8 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__9 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__10 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__13 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__17 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__29 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__30 = { 0, 0, 0, fmt_51, 0 };


/*     + + + PURPOSE + + + */
/*     Checks validity of side-weir configuration.  We assume that */
/*     side weirs are rarely active at the start of the run.  Thus */
/*     the initial version of this code will check to see if the */
/*     side weir is active and if its datum for head makes sense */
/*     for the given conditions in the source and desintation nodes. */
/* SOURCE sideweir.for:16 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE sideweir.for:18 */
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
/* SOURCE sideweir.for:21 */
/*<       integerept,stdout,nex >*/
/* SOURCE sideweir.for:22 */
/*<       integeremc(ept),exnodt(9,nex) >*/
/* SOURCE sideweir.for:23 */
/*<       realgrav >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     GRAV - gravitational acceleration */
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
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE sideweir.for:46 */
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
/* INCLUDE sideweir.for:47 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE sideweir.for:50 */
/*<       integeradrs,code,dnn,idum,itype,j,mdn,upn,tadrs >*/
/* SOURCE sideweir.for:52 */
/*<        >*/
/* SOURCE sideweir.for:55 */
/*<       characterinvert_high*4,q_non_zero*4,disabled*4 >*/
/*     + + + EQUIVALENCES + + + */
/* SOURCE sideweir.for:58 */
/*<       equivalence(idum,rdum) >*/
/*     + + + INTRINSICS + + + */
/* SOURCE sideweir.for:61 */
/*<       intrinsicabs,float,sign >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE sideweir.for:64 */
/*<       integergettbn >*/
/* SOURCE sideweir.for:65 */
/*<       realgethdd,get_slot_depth >*/
/* SOURCE sideweir.for:66 */
/*<       charactergetusn*5,get_tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE sideweir.for:69 */
/*<       externalgethdd,gettbn,getusn,get_slot_depth,get_tabid >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE sideweir.for:73 */
/*<    50 format(/,' Starting check of Side-Weir Instructions') >*/
/* SOURCE sideweir.for:74 */
/*<    51 format(/,' End  check of Side-Weir Instructions') >*/
/* SOURCE sideweir.for:75 */
/*<    53  >*/
/* SOURCE sideweir.for:83 */
/*<    54  >*/
/* *********************************************************************** */
/*      MAX_DIFF_IN_FEET = 0.1 */
/* SOURCE sideweir.for:87 */
/*<       max_diff_in_feet=0.75 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* L50: */
/* L51: */
/* L53: */
/* L54: */
    feq_gen_max_diff_in_feet_d_ = (float).75;
/*     Set the maximum difference allowed in water-surface elevation. */
/* SOURCE sideweir.for:89 */
/*<       if(grav.lt.16.0)then >*/
    if (*grav < (float)16.) {
/* SOURCE sideweir.for:90 */
/*<       max_diff=max_diff_in_feet*0.3048 >*/
	feq_gen_max_diff_d_ = static_cast<double>(feq_gen_max_diff_in_feet_d_) * (float).3048;
/* SOURCE sideweir.for:91 */
/*<       else >*/
    } else {
/* SOURCE sideweir.for:92 */
/*<       max_diff=max_diff_in_feet >*/
	feq_gen_max_diff_d_ = feq_gen_max_diff_in_feet_d_;
/* SOURCE sideweir.for:93 */
/*<       endif >*/
    }
/*     START THE LOOP OVER THE instructions */
/* SOURCE sideweir.for:95 */
/*<       write(stdout,50) >*/
    feq_gen_io_d__8.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__8);
    e_wsfe();
/* SOURCE sideweir.for:96 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__9.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__9);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE sideweir.for:97 */
/*<       write(stdout,53) >*/
    feq_gen_io_d__10.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__10);
    e_wsfe();
/* SOURCE sideweir.for:98 */
/*<       j=emc(1) >*/
    j = emc[1];
/* SOURCE sideweir.for:99 */
/*<  1000 continue >*/
L1000:
/* SOURCE sideweir.for:100 */
/*<       code=emc(j) >*/
    code = emc[j];
/* SOURCE sideweir.for:101 */
/*<       if(code.eq.-1)goto2000 >*/
    if (code == -1) {
	goto L2000;
    }
/* SOURCE sideweir.for:102 */
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
/* SOURCE sideweir.for:103 */
/*<        >*/
    feq_gen_io_d__13.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__13);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:20* INVALID EMC CODE IN SIDE_WEIR_CHK. CODE="),
	     (ftnlen)50);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE sideweir.for:105 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE sideweir.for:106 */
/*<     1 continue >*/
L1:
/* SOURCE sideweir.for:107 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE sideweir.for:108 */
/*<     2 continue >*/
L2:
/* SOURCE sideweir.for:109 */
/*<       j=j+emc(j+1) >*/
    j += emc[j + 1];
/* SOURCE sideweir.for:110 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE sideweir.for:111 */
/*<     3 continue >*/
L3:
/* SOURCE sideweir.for:112 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE sideweir.for:113 */
/*<     4 continue >*/
L4:
/* SOURCE sideweir.for:115 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE sideweir.for:116 */
/*<     5 continue >*/
L5:
/* SOURCE sideweir.for:117 */
/*<       itype=emc(j+1) >*/
    itype = emc[j + 1];
/* SOURCE sideweir.for:118 */
/*<       upn=emc(j+2) >*/
    upn = emc[j + 2];
/* SOURCE sideweir.for:119 */
/*<       dnn=emc(j+3) >*/
    dnn = emc[j + 3];
/* SOURCE sideweir.for:120 */
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
/* SOURCE sideweir.for:121 */
/*<        >*/
    feq_gen_io_d__17.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__17);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:21* INVALID CODE=5 TYPE IN SIDE_WEIR_CHK."), (
	    ftnlen)47);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" TYPE="), (ftnlen)6);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&itype, (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE sideweir.for:124 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE sideweir.for:125 */
/*<   501 continue >*/
L501:
/* SOURCE sideweir.for:126 */
/*<       j=j+cd5ty1 >*/
    j += 7;
/* SOURCE sideweir.for:127 */
/*<       goto599 >*/
    goto L599;
/* SOURCE sideweir.for:128 */
/*<   502 continue >*/
L502:
/* SOURCE sideweir.for:129 */
/*<       j=j+cd5ty2 >*/
    j += 12;
/* SOURCE sideweir.for:130 */
/*<       goto599 >*/
    goto L599;
/* SOURCE sideweir.for:132 */
/*<   503 continue >*/
L503:
/* SOURCE sideweir.for:134 */
/*<       j=j+cd5ty3 >*/
    j += 17;
/* SOURCE sideweir.for:135 */
/*<       goto599 >*/
    goto L599;
/* SOURCE sideweir.for:137 */
/*<   504 continue >*/
L504:
/* SOURCE sideweir.for:138 */
/*<       j=j+cd5ty4 >*/
    j += 10;
/* SOURCE sideweir.for:139 */
/*<       goto599 >*/
    goto L599;
/* SOURCE sideweir.for:141 */
/*<   505 continue >*/
L505:
/* SOURCE sideweir.for:142 */
/*<       j=j+cd5ty5 >*/
    j += 3;
/* SOURCE sideweir.for:143 */
/*<       goto599 >*/
    goto L599;
/* SOURCE sideweir.for:144 */
/*<   506 continue >*/
L506:
/* SOURCE sideweir.for:145 */
/*<       j=j+1+abs(emc(j+6))*cd5ty6 >*/
    j = j + 1 + ((feq_gen_i_d_1 = emc[j + 6], abs(feq_gen_i_d_1)) << 3);
/* SOURCE sideweir.for:146 */
/*<       goto599 >*/
    goto L599;
/* SOURCE sideweir.for:147 */
/*<   507 continue >*/
L507:
/* SOURCE sideweir.for:148 */
/*<       j=j+cd5ty7 >*/
    j += 10;
/* SOURCE sideweir.for:149 */
/*<       goto599 >*/
    goto L599;
/* SOURCE sideweir.for:150 */
/*<   508 continue >*/
L508:
/* SOURCE sideweir.for:151 */
/*<       j=j+cd5ty8 >*/
    j += 7;
/* SOURCE sideweir.for:152 */
/*<       goto599 >*/
    goto L599;
/* SOURCE sideweir.for:153 */
/*<   509 continue >*/
L509:
/* SOURCE sideweir.for:154 */
/*<       j=j+cd5ty9 >*/
    j += 11;
/* SOURCE sideweir.for:155 */
/*<       goto599 >*/
    goto L599;
/* SOURCE sideweir.for:157 */
/*<   599 continue >*/
L599:
/* SOURCE sideweir.for:158 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE sideweir.for:160 */
/*<     6 continue >*/
L6:
/* SOURCE sideweir.for:161 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE sideweir.for:163 */
/*<     7 continue >*/
L7:
/* SOURCE sideweir.for:164 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE sideweir.for:165 */
/*<     8 continue >*/
L8:
/* SOURCE sideweir.for:166 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE sideweir.for:167 */
/*<     9 continue >*/
L9:
/* SOURCE sideweir.for:168 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE sideweir.for:170 */
/*<    10 continue >*/
L10:
/* SOURCE sideweir.for:171 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE sideweir.for:172 */
/*<    14 continue >*/
L14:
/*          Check the status of the side weir to make sure it */
/*          is consistent with the computed initial condition. */
/* SOURCE sideweir.for:176 */
/*<       upn=emc(j+1) >*/
    upn = emc[j + 1];
/* SOURCE sideweir.for:177 */
/*<       dnn=emc(j+2) >*/
    dnn = emc[j + 2];
/* SOURCE sideweir.for:178 */
/*<       mdn=emc(j+3) >*/
    mdn = emc[j + 3];
/* SOURCE sideweir.for:179 */
/*<       adrs=emc(j+4) >*/
    adrs = emc[j + 4];
/*          Get the head datum from the 2-D table. */
/* SOURCE sideweir.for:181 */
/*<       hdatum=gethdd(adrs) >*/
    hdatum = gethdd_(&adrs);
/*          Get the invert elevations.  We assume that the */
/*          and free nodes have had their invert elevation set */
/*          to match the invert elevation of the node to which */
/*          they are tied.  This is done automatically for dummy */
/*          branches tied to branches via an EqZ instruction. */
/* SOURCE sideweir.for:188 */
/*<       zbup=ze(upn) >*/
    zbup = enelem_1.ze[upn - 1];
/* SOURCE sideweir.for:189 */
/*<       zbmid=ze(mdn) >*/
    zbmid = enelem_1.ze[mdn - 1];
/*          Get the water-surface elevations. */
/* SOURCE sideweir.for:192 */
/*<       zup=zbup+ye1(upn) >*/
    zup = static_cast<double>(zbup) + enelem_1.ye1[upn - 1];
/* SOURCE sideweir.for:193 */
/*<       zmid=zbmid+ye1(mdn) >*/
    zmid = static_cast<double>(zbmid) + enelem_1.ye1[mdn - 1];
/*          Adjust invert to true invert in case the cross section */
/*          has a bottom slot. */
/* SOURCE sideweir.for:197 */
/*<       tadrs=exnodt(4,upn) >*/
    tadrs = exnodt[upn * 9 + 4];
/*          Slot depth is relative to the true invert.  Thus it is */
/*          < 0 if a slot is present.  Note that the side-weir instruction */
/*          requires that the ups and dsn nodes have cross sections. */
/*          The depth already includes the slot so we  must adjust */
/*          the invert after we compute the water-surface elevation! */
/* SOURCE sideweir.for:203 */
/*<       zbup=zbup-get_slot_depth(tadrs) >*/
    zbup -= feq_gen_get_slot_depth_d_(&tadrs);
/*          Set the values to the default */
/* SOURCE sideweir.for:206 */
/*<       invert_high='NO' >*/
    s_copy(feq_gen_invert_high_d_, const_cast<char*>("NO"), (ftnlen)4, (ftnlen)2);
/* SOURCE sideweir.for:207 */
/*<       q_non_zero='NO' >*/
    s_copy(feq_gen_q_non_zero_d_, const_cast<char*>("NO"), (ftnlen)4, (ftnlen)2);
/* SOURCE sideweir.for:209 */
/*<       if(zbup.gt.hdatum.or.zbmid.gt.hdatum)then >*/
    if (zbup > hdatum || zbmid > hdatum) {
/*            Major problem.  One or both of the invert elevations */
/*            is greater than the elevation datum for head */
/* SOURCE sideweir.for:212 */
/*<       invert_high='YES' >*/
	s_copy(feq_gen_invert_high_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3);
/* SOURCE sideweir.for:213 */
/*<       endif >*/
    }
/* SOURCE sideweir.for:214 */
/*<       if(zup.gt.hdatum.or.zmid.gt.hdatum)then >*/
    if (zup > hdatum || zmid > hdatum) {
/* SOURCE sideweir.for:215 */
/*<       if(zup.ne.zmid)then >*/
	if (zup != zmid) {
/* SOURCE sideweir.for:216 */
/*<       q_non_zero='YES' >*/
	    s_copy(feq_gen_q_non_zero_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3);
/* SOURCE sideweir.for:217 */
/*<       endif >*/
	}
/* SOURCE sideweir.for:218 */
/*<       endif >*/
    }
/* SOURCE sideweir.for:219 */
/*<       if(invert_high=='YES'.or.q_non_zero=='YES')then >*/
    if (s_cmp(feq_gen_invert_high_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3) == 0 || s_cmp(
	    feq_gen_q_non_zero_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3) == 0) {
/* SOURCE sideweir.for:220 */
/*<       if(invert_high.eq.'YES')then >*/
	if (s_cmp(feq_gen_invert_high_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3) == 0) {
/*              Set datum very high. */
/* SOURCE sideweir.for:222 */
/*<       disabled='YES' >*/
	    s_copy(disabled, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3);
/* SOURCE sideweir.for:223 */
/*<       rdum=99999.0 >*/
	    *rdum = (float)99999.;
/* SOURCE sideweir.for:224 */
/*<       emc(j+9)=idum >*/
	    emc[j + 9] = *idum;
/* SOURCE sideweir.for:226 */
/*<       elseif(abs(zup-zmid)>max_diff)then >*/
	} else if ((feq_gen_r_d_1 = static_cast<double>(zup) - zmid, dabs(feq_gen_r_d_1)) > feq_gen_max_diff_d_) {
/*              Could be a problem but the datum for head */
/*              might make startup possible. */
/* SOURCE sideweir.for:229 */
/*<       if(zup-hdatum<max_diff.or.zmid-hdatum<max_diff)then >*/
	    if (static_cast<double>(zup) - hdatum < feq_gen_max_diff_d_ || static_cast<double>(zmid) - hdatum < feq_gen_max_diff_d_) {
/* SOURCE sideweir.for:231 */
/*<       disabled='NO' >*/
		s_copy(disabled, const_cast<char*>("NO"), (ftnlen)4, (ftnlen)2);
/* SOURCE sideweir.for:232 */
/*<       else >*/
	    } else {
/*                Set datum very high. */
/* SOURCE sideweir.for:234 */
/*<       disabled='YES' >*/
		s_copy(disabled, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3);
/* SOURCE sideweir.for:235 */
/*<       rdum=99999.0 >*/
		*rdum = (float)99999.;
/* SOURCE sideweir.for:236 */
/*<       emc(j+9)=idum >*/
		emc[j + 9] = *idum;
/* SOURCE sideweir.for:237 */
/*<       endif >*/
	    }
/* SOURCE sideweir.for:238 */
/*<       else >*/
	} else {
/* SOURCE sideweir.for:239 */
/*<       disabled='NO' >*/
	    s_copy(disabled, const_cast<char*>("NO"), (ftnlen)4, (ftnlen)2);
/* SOURCE sideweir.for:240 */
/*<       endif >*/
	}
/*           IF(INVERT_HIGH.NE.'NO'.OR.Q_NON_ZERO.NE.'NO') THEN */
/*             IF(ABS(ZUP - ZMID).GT.MAX_DIFF) THEN */
/* C              Set datum very high. */
/*               DISABLED = 'YES' */
/*               RDUM = 99999.0 */
/*               EMC(J+9) = IDUM */
/*             ELSE */
/*               DISABLED = 'NO' */
/*             ENDIF */
/* SOURCE sideweir.for:251 */
/*<        >*/
	feq_gen_io_d__29.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__29);
	getusn_(feq_gen_ch_d_2, (ftnlen)5, &upn);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, (char *)&zbup, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&zup, (ftnlen)sizeof(real));
	getusn_(feq_gen_ch_d_4, (ftnlen)5, &dnn);
	s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)5);
	getusn_(feq_gen_ch_d_6, (ftnlen)5, &mdn);
	s_copy(feq_gen_ch_d_5, feq_gen_ch_d_6, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, (char *)&zbmid, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&zmid, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&hdatum, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, feq_gen_invert_high_d_, (ftnlen)4);
	do_fio(&feq_gen_c_d_1, feq_gen_q_non_zero_d_, (ftnlen)4);
	do_fio(&feq_gen_c_d_1, disabled, (ftnlen)4);
	e_wsfe();
/* SOURCE sideweir.for:254 */
/*<       endif >*/
    }
/* SOURCE sideweir.for:256 */
/*<       goto1500 >*/
    goto L1500;
/* SOURCE sideweir.for:257 */
/*<  1500 continue >*/
L1500:
/* SOURCE sideweir.for:258 */
/*<       j=j+emc(code+1) >*/
    j += emc[code + 1];
/* SOURCE sideweir.for:259 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE sideweir.for:260 */
/*<  2000 continue >*/
L2000:
/* SOURCE sideweir.for:261 */
/*<       write(stdout,51) >*/
    feq_gen_io_d__30.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__30);
    e_wsfe();
/* SOURCE sideweir.for:262 */
/*<       return >*/
    return 0;
/* SOURCE sideweir.for:263 */
/*<       end >*/
} /* side_weir_chk__ */

#undef rtmp
#undef rdum
#undef idum
#undef itab
#undef ftab


#ifdef __cplusplus
	}
#endif
