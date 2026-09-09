#include <feq/section_energy.hpp>
extern "C" void feq_conduit_boundary(int,int,float,float,float,float,float,float,const float*,const float*,int*,float*,float*);
extern "C" int feq_arch_perimeter(int,const float*,const float*,const float*,const float*,float,float*,float*,int*,float*,float*,float*,int*,float*);
/* conduit.f -- translated by f2c (version 20240504).
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

/* COMMON offcom_ is declared in common.hpp. */

#define offcom_1 offcom_

/* COMMON grvcom_ is declared in common.hpp. */

#define grvcom_1 grvcom_

/* COMMON xscomu_ is declared in common.hpp. */

#define xscomu_1 xscomu_

/* COMMON nrdzcm_ is declared in common.hpp. */

#define nrdzcm_1 nrdzcm_

/* COMMON xtadd_ is declared in common.hpp. */

#define xtadd_1 xtadd_

/* COMMON xtaddc_ is declared in common.hpp. */

#define xtaddc_1 xtaddc_

/* COMMON epscom_ is declared in common.hpp. */

#define epscom_1 epscom_

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_10002 = 10002;
static integer feq_gen_c_d_200 = 200;
static integer feq_gen_c_d_17 = 17;
static integer feq_gen_c_d_12 = 12;
static integer feq_gen_c_d_15 = 15;
static integer feq_gen_c_d_34 = 34;
static integer feq_gen_c_d_24 = 24;
static integer feq_gen_c_d_999 = 999;
static integer feq_gen_c_d_0 = 0;




/* SOURCE conduit.for:4 */
/*<       subroutineqclim(stdin,stdout,eflag) >*/
/* Subroutine */ int qclim_(integer *stdin, integer *stdout, integer *eflag)
{
    /* Format strings */
    static char fmt_52[] = "(\002 TABID= \002,a)";
    static char fmt_56[] = "(\002 *WRN:560* Table may not be of a closed con\
duit. Slot\002,\002 width=\002,f8.4,\002 > \002,f8.4)";
    static char fmt_58[] = "(\002 *ERR:644* Table is not for closed conduit.\
 No changes\002,\002 made.\002)";
    static char fmt_72[] = "(\002 *ERR:645 Cross section table for QCLIMIT m\
ust be\002,\002 TYPE=22 or 25 but TYPE=\002,i5,\002 found.\002)";
    static char fmt_81[] = "(/,\002 LIMITING FLOWRATE=\002,f10.1)";
    static char fmt_82[] = "(\002 *ERR:540* TABID= \002,a,\002 NOT FOUND\002)"
	    ;
    static char fmt_84[] = "(/,\002 CRITICAL SLOPE=\002,f10.5)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2;
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(), 
	    s_wsfe(cilist *), e_wsfe();
    double log(doublereal), exp(doublereal);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    real k, p, y, y0, y1;
    integer ha, la;
    real sc, qc0, qc1;
    double qc;
    integer adr;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    char feq_gen_name_d_[7], line[80];
    integer xoff;
    real told, tnew;
    integer feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    char tabid[16];
    integer table;
    real factor;
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen);
    extern integer lenstr_(char *, ftnlen);
    real mxslot;
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__7 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__9 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__13 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__19 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__20 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__29 = { 0, 0, 0, fmt_81, 0 };
    static cilist feq_gen_io_d__32 = { 0, 0, 0, fmt_84, 0 };
    static cilist feq_gen_io_d__33 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__34 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Compute an arbitary limit to the critical flow values in */
/*     a cross section table of type 22 or 25 for a closed conduit. */
/*     The limit is arbitrary but none the less needed for the */
/*     computations in EXPCON for closed conduits. */
/*     QCLIM extrapolates from the last two top-widths in the table */
/*     which are before the start of the slot added to the conduit to */
/*     maintain a free surface. */
/*     QCLIM does not create any new table.  The table must exist */
/*     in the storage  system of FEQUTL.  Thus the QCLIM command appears */
/*     before the EXPCON command to modify the closed conduit tables. */
/* SOURCE conduit.for:22 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE conduit.for:25 */
/*<       integereflag,stdin,stdout >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE conduit.for:33 */
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
/* INCLUDE conduit.for:34 */
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
/* INCLUDE conduit.for:35 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/* INCLUDE conduit.for:36 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE conduit.for:39 */
/*<       integeradr,ha,la,table,type,xoff >*/
/* SOURCE conduit.for:40 */
/*<       realfactor,k,p,qc,qc0,qc1,sc,tnew,told,y,y0,y1,mxslot >*/
/* SOURCE conduit.for:42 */
/*<       characterline*80,name*7,tabid*16 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE conduit.for:45 */
/*<       intrinsicexp,log >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE conduit.for:48 */
/*<       integerlenstr >*/
/* SOURCE conduit.for:49 */
/*<       externalinline,kil,get_internal_tab_number,lenstr,strip_l_blanks >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE conduit.for:53 */
/*<    52 format(' TABID= ',a) >*/
/* SOURCE conduit.for:54 */
/*<    56  >*/
/* SOURCE conduit.for:56 */
/*<    58  >*/
/* SOURCE conduit.for:58 */
/*<    72  >*/
/* SOURCE conduit.for:60 */
/*<    81 format(/,' LIMITING FLOWRATE=',f10.1) >*/
/* SOURCE conduit.for:61 */
/*<    82 format(' *ERR:540* TABID= ',a,' NOT FOUND') >*/
/* SOURCE conduit.for:62 */
/*<    84 format(/,' CRITICAL SLOPE=',f10.5) >*/
/* *********************************************************************** */
/* SOURCE conduit.for:64 */
/*<       if(grav.gt.15.0)then >*/
/* L52: */
/* L56: */
/* L58: */
/* L72: */
/* L81: */
/* L82: */
/* L84: */
    if (grvcom_1.grav > (float)15.) {
/* SOURCE conduit.for:65 */
/*<       mxslot=0.07 >*/
	mxslot = (float).07;
/* SOURCE conduit.for:66 */
/*<       else >*/
    } else {
/* SOURCE conduit.for:67 */
/*<       mxslot=0.02134 >*/
	mxslot = (float).02134;
/* SOURCE conduit.for:68 */
/*<       endif >*/
    }
/* SOURCE conduit.for:69 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:72 */
/*<       read(line,'(7X,A)',err=991)tabid >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(7X,A)");
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE conduit.for:73 */
/*<       callstrip_l_blanks(tabid) >*/
    feq_gen_strip_l_blanks_d_(tabid, (ftnlen)16);
/* SOURCE conduit.for:75 */
/*<       write(stdout,52)tabid(1:lenstr(tabid)) >*/
    feq_gen_io_d__7.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__7);
    do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
    e_wsfe();
/* SOURCE conduit.for:76 */
/*<       callget_internal_tab_number(stdout,tabid,eflag,table) >*/
    feq_gen_get_internal_tab_number_d_(stdout, tabid, eflag, &table, (ftnlen)16);
/* SOURCE conduit.for:82 */
/*<       if(ftpnt(table).le.0)then >*/
    if (ftablea_1.ftpnt[table - 1] <= 0) {
/*       MAKE SURE TABLE EXISTS */
/* SOURCE conduit.for:84 */
/*<       write(stdout,82)tabid(1:lenstr(tabid)) >*/
	feq_gen_io_d__9.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__9);
	do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
	e_wsfe();
/* SOURCE conduit.for:85 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE conduit.for:86 */
/*<       endif >*/
    }
/*     INPUT THE ADJUSTMENT FACTOR FOR THE BUILT IN EXTRAPOLATION */
/* SOURCE conduit.for:90 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:93 */
/*<       read(line,'(A7,F10.0)',err=991)name,factor >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(A7,F10.0)");
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)7);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&factor, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE conduit.for:94 */
/*<       if(factor.eq.0.0)factor=1.0 >*/
    if (factor == (float)0.) {
	factor = (float)1.;
    }
/* SOURCE conduit.for:95 */
/*<       write(stdout,'(1X,A7,F10.3)')name,factor >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(1X,A7,F10.3)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)7);
    do_fio(&feq_gen_c_d_1, (char *)&factor, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE conduit.for:97 */
/*<       if(eflag.gt.0)return >*/
    if (*eflag > 0) {
	return 0;
    }
/*     CONVERT THE TABLE NUMBER TO TABLE ADDRESS FOR CONVENIENCE */
/* SOURCE conduit.for:101 */
/*<       table=ftpnt(table) >*/
    table = ftablea_1.ftpnt[table - 1];
/*     ENSURE THAT THE TABLES ARE OF THE CORRECT TYPE. */
/* SOURCE conduit.for:105 */
/*<       type=itab(table+2) >*/
    feq_gen_type_d_ = itab[table + 2];
/* SOURCE conduit.for:106 */
/*<       if(type.ne.22.and.type.ne.25)then >*/
    if (feq_gen_type_d_ != 22 && feq_gen_type_d_ != 25) {
/* SOURCE conduit.for:107 */
/*<       write(stdout,72)type >*/
	feq_gen_io_d__13.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__13);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE conduit.for:108 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE conduit.for:109 */
/*<       endif >*/
    }
/*     SET THE TABLE OFFSET */
/* SOURCE conduit.for:113 */
/*<       xoff=offvec(type) >*/
    xoff = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE conduit.for:115 */
/*<       if(eflag.gt.0)return >*/
    if (*eflag > 0) {
	return 0;
    }
/*     BASIC DATA HAS BEEN INPUT IN VALID FORM. */
/*     Search for the top width just before the slot is entered. */
/*     To do so start at the top of the table and search to smaller */
/*     depths until a top width 1 percent larger than the current */
/*     top width is found. */
/* SOURCE conduit.for:123 */
/*<       la=table+xtioff >*/
    la = table + 32;
/* SOURCE conduit.for:125 */
/*<       ha=itab(table) >*/
    ha = itab[table];
/* SOURCE conduit.for:127 */
/*<       adr=ha >*/
    adr = ha;
/* SOURCE conduit.for:129 */
/*<       told=ftab(ha+1) >*/
    told = ftab[ha + 1];
/* SOURCE conduit.for:130 */
/*<       if(told.gt.mxslot)then >*/
    if (told > mxslot) {
/* SOURCE conduit.for:131 */
/*<       write(stdout,56)told,mxslot >*/
	feq_gen_io_d__19.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__19);
	do_fio(&feq_gen_c_d_1, (char *)&told, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&mxslot, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE conduit.for:132 */
/*<       endif >*/
    }
/* SOURCE conduit.for:134 */
/*<   100 continue >*/
L100:
/* SOURCE conduit.for:136 */
/*<       adr=adr-xoff >*/
    adr -= xoff;
/* SOURCE conduit.for:137 */
/*<       if(adr.eq.la)then >*/
    if (adr == la) {
/* SOURCE conduit.for:138 */
/*<       write(stdout,58) >*/
	feq_gen_io_d__20.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__20);
	e_wsfe();
/* SOURCE conduit.for:139 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE conduit.for:140 */
/*<       return >*/
	return 0;
/* SOURCE conduit.for:141 */
/*<       endif >*/
    }
/* SOURCE conduit.for:143 */
/*<       tnew=ftab(adr+1) >*/
    tnew = ftab[adr + 1];
/* SOURCE conduit.for:144 */
/*<       if((tnew-told)/told.gt.0.01)then >*/
    if (static_cast<double>((static_cast<double>(tnew) - told)) / told > (float).01) {
/*         ASSUME THAT TNEW IS THE FIRST TOP WIDTH WHICH IS GREATER */
/*         THAN THE SLOT WIDTH. */
/* SOURCE conduit.for:148 */
/*<       qc1=ftab(adr+7) >*/
	qc1 = ftab[adr + 7];
/* SOURCE conduit.for:149 */
/*<       y1=ftab(adr) >*/
	y1 = ftab[adr];
/* SOURCE conduit.for:150 */
/*<       qc0=ftab(adr+7-xoff) >*/
	qc0 = ftab[adr + 7 - xoff];
/* SOURCE conduit.for:151 */
/*<       y0=ftab(adr-xoff) >*/
	y0 = ftab[adr - xoff];
/* SOURCE conduit.for:153 */
/*<       y=ftab(adr+xoff) >*/
	y = ftab[adr + xoff];
/* SOURCE conduit.for:154 */
/*<       p=log(y/y0)*log(qc1/qc0)/log(y1/y0) >*/
	// The owned extrapolation preserves every REAL logarithm store.
/* SOURCE conduit.for:155 */
/*<       qc=qc0*exp(p)*factor >*/
	qc = feq::critical_flow_limit(y,y0,y1,qc0,qc1,factor);
/* SOURCE conduit.for:157 */
/*<       write(stdout,81)qc >*/
	feq_gen_io_d__29.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__29);
	{ real reported_qc = static_cast<real>(qc);
            do_fio(&feq_gen_c_d_1, (char *)&reported_qc, (ftnlen)sizeof(real)); }
	e_wsfe();
/*          WRITE(STDOUT,*) ' Y0=',Y0,' QC0=',QC0,' Y1=',Y1,' QC1=',QC1, */
/*     A               ' Y=',Y,' QC=',QC */
/* SOURCE conduit.for:162 */
/*<       k=ftab(adr+3+xoff) >*/
	k = ftab[adr + 3 + xoff];
/* SOURCE conduit.for:163 */
/*<       sc=qc**2/k**4 >*/
/* Computing 2nd power */
	// Retain the wide limiting flow for the critical slope.
/* Computing 4th power */
	// The owned slope squares conveyance without a REAL store.
	sc = feq::critical_flow_limit_slope(qc,k);
/* SOURCE conduit.for:164 */
/*<       write(stdout,84)sc >*/
	feq_gen_io_d__32.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__32);
	do_fio(&feq_gen_c_d_1, (char *)&sc, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE conduit.for:166 */
/*<   200 continue >*/
L200:
/*           REPLACE VALUES IN THE SLOT */
/* SOURCE conduit.for:168 */
/*<       adr=adr+xoff >*/
	adr += xoff;
/* SOURCE conduit.for:169 */
/*<       ftab(adr+7)=qc >*/
	ftab[adr + 7] = qc;
/* SOURCE conduit.for:170 */
/*<       if(adr.lt.ha)goto200 >*/
	if (adr < ha) {
	    goto L200;
	}
/* SOURCE conduit.for:172 */
/*<       return >*/
	return 0;
/* SOURCE conduit.for:173 */
/*<       endif >*/
    }
/* SOURCE conduit.for:174 */
/*<       goto100 >*/
    goto L100;
/* SOURCE conduit.for:176 */
/*<   991 continue >*/
L991:
/* SOURCE conduit.for:177 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__33.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__33);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE conduit.for:178 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__34.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__34);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE conduit.for:179 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE conduit.for:180 */
/*<       end >*/
    return 0;
} /* qclim_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE conduit.for:184 */
/*<       subroutinemulcon(stdin,stdout,stdtab,nfac,tabdir,eflag,ftp) >*/
/* Subroutine */ int mulcon_(integer *stdin, integer *stdout, integer *stdtab,
	 real *nfac, integer *feq_storage_tabdir, integer *eflag, integer *ftp)
{
    /* Initialized data */

    static integer nurq = 11;
    static real urqx[11] = { (float)0.,(float).0960301,(float).1913097,(float)
	    .2850942,(float).3766507,(float).4464486,(float).5086755,(float)
	    .5604021,(float).5991936,(float).6232238,(float).6313616 };
    static real urqy[11] = { (float).4008645,(float).3966157,(float).3839025,(
	    float).3628242,(float).3335457,(float).3060603,(float).2641675,(
	    float).2098394,(float).1456334,(float).0745719,(float)0. };
    static real rsrc[17] = { (float)11.,(float)13.5,(float)15.5,(float)18.,(
	    float)22.5,(float)26.625,(float)31.3125,(float)36.,(float)40.,(
	    float)45.,(float)54.,(float)62.,(float)72.,(float)77.25,(float)
	    87.125,(float)96.875,(float)106.5 };
    static real sprc[17] = { (float)18.,(float)22.,(float)26.,(float)28.5,(
	    float)36.25,(float)43.75,(float)51.125,(float)58.5,(float)65.,(
	    float)73.,(float)88.,(float)102.,(float)115.,(float)122.,(float)
	    138.,(float)154.,(float)168.75 };
    static real r1rc[17] = { (float)22.875,(float)27.5,(float)35.5,(float)
	    40.6875,(float)51.,(float)62.,(float)73.,(float)84.,(float)92.5,(
	    float)105.,(float)126.,(float)162.5,(float)183.,(float)218.,(
	    float)269.,(float)301.375,(float)329. };
    static real r3rc[17] = { (float)4.0313,(float)5.25,(float)5.25,(float)
	    4.5938,(float)6.0313,(float)6.375,(float)7.5625,(float)8.75,(
	    float)9.8125,(float)11.2188,(float)12.5625,(float)13.9688,(float)
	    19.2813,(float)20.0625,(float)22.375,(float)24.,(float)26.875 };
    static real rscm[12] = { (float)13.,(float)15.,(float)18.,(float)20.,(
	    float)24.,(float)29.,(float)33.,(float)38.,(float)43.,(float)47.,(
	    float)52.,(float)57. };
    static real spcm[12] = { (float)17.,(float)21.,(float)24.,(float)28.,(
	    float)35.,(float)42.,(float)49.,(float)57.,(float)64.,(float)71.,(
	    float)77.,(float)83. };
    static real r1cm[12] = { (float)25.625,(float)33.125,(float)34.625,(float)
	    42.25,(float)55.125,(float)66.125,(float)77.25,(float)88.25,(
	    float)99.25,(float)110.25,(float)121.25,(float)132.25 };
    static real r3cm[12] = { (float)3.5,(float)4.125,(float)4.875,(float)5.5,(
	    float)6.875,(float)8.25,(float)9.625,(float)11.,(float)12.375,(
	    float)13.75,(float)15.125,(float)16.5 };
    static real rscmb[12] = { (float)11.,(float)13.,(float)16.,(float)18.,(
	    float)22.,(float)27.,(float)31.,(float)36.,(float)40.,(float)44.,(
	    float)49.,(float)54. };
    static real spcmb[12] = { (float)18.,(float)22.,(float)25.,(float)29.,(
	    float)36.,(float)43.,(float)50.,(float)58.,(float)65.,(float)72.,(
	    float)79.,(float)85. };
    static real r1cmb[12] = { (float)19.125,(float)37.0625,(float)33.5,(float)
	    55.,(float)73.25,(float)91.5625,(float)97.25,(float)115.6875,(
	    float)129.3125,(float)142.9375,(float)145.5,(float)154.5 };
    static real r3cmb[12] = { (float)3.5,(float)4.,(float)4.,(float)4.5,(
	    float)5.,(float)5.5,(float)6.,(float)7.,(float)8.,(float)9.,(
	    float)10.,(float)11. };
    static real rscm1[15] = { (float)32.75,(float)38.,(float)43.25,(float)
	    48.5,(float)54.,(float)58.25,(float)62.5,(float)67.25,(float)
	    71.75,(float)76.,(float)80.5,(float)84.75,(float)89.25,(float)
	    93.75,(float)98. };
    static real spcm1[15] = { (float)38.5,(float)45.,(float)51.75,(float)58.5,
	    (float)65.,(float)72.5,(float)79.,(float)86.5,(float)93.5,(float)
	    101.5,(float)108.5,(float)116.5,(float)123.5,(float)131.,(float)
	    138.5 };
    static real r1cm1[15] = { (float)31.375,(float)36.625,(float)43.75,(float)
	    51.125,(float)56.25,(float)63.75,(float)82.625,(float)92.25,(
	    float)100.25,(float)111.625,(float)120.25,(float)131.75,(float)
	    139.75,(float)149.5,(float)162.375 };
    static real r3cm1[15] = { (float)12.5,(float)14.5,(float)16.625,(float)
	    18.75,(float)20.75,(float)22.875,(float)20.875,(float)22.625,(
	    float)24.375,(float)26.125,(float)27.75,(float)29.5,(float)31.25,(
	    float)33.,(float)34.75 };
    static real rscm1b[15] = { (float)27.,(float)31.,(float)36.,(float)40.,(
	    float)44.,(float)55.,(float)59.,(float)63.,(float)67.,(float)71.,(
	    float)75.,(float)79.,(float)83.,(float)87.,(float)91. };
    static real spcm1b[15] = { (float)43.,(float)50.,(float)58.,(float)65.,(
	    float)72.,(float)73.,(float)81.,(float)87.,(float)95.,(float)103.,
	    (float)112.,(float)117.,(float)128.,(float)137.,(float)142. };
    static real r1cm1b[15] = { (float)54.75,(float)67.,(float)82.,(float)
	    91.25,(float)98.5,(float)76.25,(float)92.75,(float)100.5,(float)
	    116.,(float)132.25,(float)151.75,(float)160.5,(float)185.,(float)
	    201.,(float)210. };
    static real r3cm1b[15] = { (float)7.75,(float)9.,(float)10.5,(float)12.,(
	    float)13.25,(float)18.,(float)18.,(float)18.,(float)18.,(float)
	    18.,(float)18.,(float)18.,(float)18.,(float)18.,(float)18. };
    static real rssp18[34] = { (float)55.,(float)57.,(float)59.,(float)61.,(
	    float)63.,(float)65.,(float)67.,(float)69.,(float)71.,(float)73.,(
	    float)75.,(float)77.,(float)79.,(float)81.,(float)83.,(float)85.,(
	    float)87.,(float)89.,(float)91.,(float)93.,(float)95.,(float)97.,(
	    float)100.,(float)101.,(float)103.,(float)105.,(float)107.,(float)
	    109.,(float)111.,(float)113.,(float)115.,(float)118.,(float)119.,(
	    float)121. };
    static real spsp18[34] = { (float)73.,(float)76.,(float)81.,(float)84.,(
	    float)87.,(float)92.,(float)95.,(float)98.,(float)103.,(float)
	    106.,(float)112.,(float)114.,(float)117.,(float)123.,(float)128.,(
	    float)131.,(float)137.,(float)139.,(float)142.,(float)148.,(float)
	    150.,(float)152.,(float)154.,(float)161.,(float)167.,(float)169.,(
	    float)171.,(float)178.,(float)184.,(float)186.,(float)188.,(float)
	    190.,(float)197.,(float)199. };
    static real r1sp18[34] = { (float)76.32,(float)83.52,(float)83.52,(float)
	    104.16,(float)136.2,(float)109.8,(float)137.88,(float)182.88,(
	    float)141.,(float)178.68,(float)144.6,(float)177.48,(float)227.76,
	    (float)178.32,(float)153.24,(float)180.36,(float)157.92,(float)
	    183.24,(float)216.36,(float)186.48,(float)216.84,(float)257.4,(
	    float)314.76,(float)254.76,(float)220.68,(float)254.16,(float)
	    297.6,(float)254.28,(float)226.8,(float)255.72,(float)291.48,(
	    float)338.16,(float)290.88,(float)332.76 };
    static real r3sp18[34] = { (float)18.,(float)18.,(float)18.,(float)18.,(
	    float)18.,(float)18.,(float)18.,(float)18.,(float)18.,(float)18.,(
	    float)18.,(float)18.,(float)18.,(float)18.,(float)18.,(float)18.,(
	    float)18.,(float)18.,(float)18.,(float)18.,(float)18.,(float)18.,(
	    float)18.,(float)18.,(float)18.,(float)18.,(float)18.,(float)18.,(
	    float)18.,(float)18.,(float)18.,(float)18.,(float)18.,(float)18. }
	    ;
    static real rssp31[24] = { (float)112.,(float)114.,(float)116.,(float)
	    118.,(float)120.,(float)122.,(float)124.,(float)126.,(float)128.,(
	    float)130.,(float)132.,(float)134.,(float)136.,(float)138.,(float)
	    140.,(float)142.,(float)144.,(float)146.,(float)148.,(float)150.,(
	    float)152.,(float)154.,(float)156.,(float)158. };
    static real spsp31[24] = { (float)159.,(float)162.,(float)168.,(float)
	    170.,(float)173.,(float)179.,(float)184.,(float)187.,(float)190.,(
	    float)195.,(float)198.,(float)204.,(float)206.,(float)209.,(float)
	    215.,(float)217.,(float)223.,(float)225.,(float)231.,(float)234.,(
	    float)236.,(float)239.,(float)245.,(float)247. };
    static real r1sp31[24] = { (float)192.6,(float)219.96,(float)197.88,(
	    float)222.6,(float)256.56,(float)227.76,(float)208.56,(float)
	    232.08,(float)260.64,(float)236.04,(float)263.16,(float)240.96,(
	    float)266.76,(float)297.96,(float)270.6,(float)299.76,(float)
	    274.56,(float)302.28,(float)278.64,(float)305.16,(float)336.48,(
	    float)374.28,(float)338.16,(float)373.56 };
    static real r3sp31[24] = { (float)31.,(float)31.,(float)31.,(float)31.,(
	    float)31.,(float)31.,(float)31.,(float)31.,(float)31.,(float)31.,(
	    float)31.,(float)31.,(float)31.,(float)31.,(float)31.,(float)31.,(
	    float)31.,(float)31.,(float)31.,(float)31.,(float)31.,(float)31.,(
	    float)31.,(float)31. };

    /* Format strings */
    static char fmt_4[] = "(5x,6a10)";
    static char fmt_6[] = "(6x,f10.0)";
    static char fmt_7[] = "(7x,i5,a10)";
    static char fmt_8[] = "(5x,6f10.0)";
    static char fmt_9[] = "(5x,6f10.0)";
    static char fmt_10[] = "(5x,6f10.0)";
    static char fmt_12[] = "(5x,6f10.0)";
    static char fmt_14[] = "(5x,6f10.0)";
    static char fmt_50[] = "(/,\002 TABID=\002,a,2x,a)";
    static char fmt_54[] = "(\002 Type=     \002,6(a10),1x,/,(10x,6(a10)))";
    static char fmt_56[] = "(\002 Width of slot=\002,f7.3)";
    static char fmt_57[] = "(\002 Number of conduits=\002,i5,\002 Mud line E\
PS=\002,f7.3)";
    static char fmt_58[] = "(\002 Height of slot above datum=\002,f7.0)";
    static char fmt_62[] = "(\002 *ERR:573* Offset space filled in MULCON\
.\002)";
    static char fmt_64[] = "(\002 *ERR:574* SPAN <=0.0 invalid for TYPE=CI\
RC.\002)";
    static char fmt_66[] = "(\002 *ERR:528* Number of conduits=\002,i5,\002 \
> \002,i5)";
    static char fmt_70[] = "(\002 Span=     \002,6f10.3)";
    static char fmt_71[] = "(\002 Rise=     \002,6f10.3)";
    static char fmt_72[] = "(\002 Bottom=   \002,6f10.3)";
    static char fmt_74[] = "(\002 Roughness=\002,6f10.3)";
    static char fmt_76[] = "(\002 *ERR:575* RISE and SPAN are 0.0. one must \
be >0.0 \002)";
    static char fmt_78[] = "(\002 *WRN:528* EQIV. DIA. FROM SPAN=\002,f10.3\
,\002 DIA. FROM RISE=\002,f10.3,/,10x,\002 DIFFERENCE INDICATES POSSIBLE ERR\
OR.\002)";
    static char fmt_80[] = "(\002 PROCESSING  TYPE:\002,1x,a10)";
    static char fmt_82[] = "(\002 *ERR:576* TYPE=\002,a10,\002 UNKNOWN\002)";
    static char fmt_84[] = "(\002 *ERR:577* RISE AND SPAN MUST BE > 0.0 FOR \
TYPE TE\002)";
    static char fmt_86[] = "(\002     USING SPAN=\002,f7.2,\002 AND RISE=\
\002,f7.2)";
    static char fmt_92[] = "(\0020*WRN:549* BETA OPTION MUST BE \"OLDBETA\".\
  THE OPTION\002,\002 HAS BEEN RESET TO \"OLDBETA\".\002)";
    static char fmt_94[] = "(\002 *ERR:616* RISE AND SPAN MUST BE > 0.0 FOR \
TYPE: BOX\002)";
    static char fmt_96[] = "(\002 MUD LEVL=\002,6f10.3)";
    static char fmt_97[] = "(/,\002 *WRN:562* Slot height=\002,f8.2,\002 <\
 \002,\002 maximum soffit\002,\002 height=\002,f8.2,/,10x,\002Redoing with i\
ncreased slot\002,\002 height=\002,f8.2)";
    static char fmt_98[] = "(\002 MUD ROUGH=\002,6f10.3)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3;
    real feq_gen_r_d_1, feq_gen_r_d_2;
    char feq_gen_ch_d_1[10];
    icilist feq_gen_ici_d_1;
    alist feq_gen_al_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rsfi(icilist *), e_rsfi(), f_back(alist *), s_wsle(cilist *), 
	    do_lio(integer *, integer *, char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    char betaflag[1*999];
    real feq_gen_d_d_;
    integer feq_gen_i_d_, j;
    char alphaflag[1*999];
    real dh;
    integer je;
    real dv;
    integer it, js;
    real xt[23], yt[23];
    integer tab;
    char cin[64];
    integer nrh;
    real cfac;
    char line[80];
    real left, maxk, span[200], nmud[200], rise[200], xoff, yoff, zoff;
    char zone[8];
    integer npnt;
    real zmud[200], zeps;
    char feq_gen_type_d_[10*200];
    real zmud2;
    char hgrid[8], basis[8];
    extern /* Subroutine */ int rhmak_(real *, real *, real *, real *, 
	    integer *, real *, real *, real *, real *, integer *);
    integer itend;
    real hslot, right, rough[200], wslot;
    char czeps[10];
    extern /* Subroutine */ int mkbox_(real *, real *, real *, real *, real *,
	     real *, integer *, real *, real *), urqte_(real *, real *, 
	    integer *, real *, real *);
    char maflag[1*999], khflag[1*999];
    extern /* Subroutine */ int tabchk_(integer *, integer *, integer *, 
	    integer *, integer *);
    char mqflag[1*999];
    extern /* Subroutine */ int rharch_(integer *, integer *, real *, real *, 
	    real *, real *, real *, real *, real *, integer *, integer *, 
	    real *, real *, real *), inline_(integer *, integer *, char *, 
	    ftnlen);
    integer nsides;
    extern /* Subroutine */ int cxstab_(integer *, integer *, integer *, real 
	    *, integer *, real *, real *, char *, integer *, integer *, real *
	    , real *, integer *, integer *, real *, real *, real *, real *, 
	    integer *, integer *, real *, real *, real *, integer *, real *, 
	    ftnlen), mkpipe_(real *, real *, integer *, real *, real *, real *
	    , integer *, real *, real *);
    integer istart, npipes;
    real bottom[200], maxsof;
    char betopt[8], monton[8], outopt[8], savopt[8], vdatum[8];
    extern integer lenstr_(char *, ftnlen);
    extern /* Character */ VOID gettok_(char *, ftnlen, char *, ftnlen);
    extern /* Subroutine */ int setmud_(integer *, integer *, integer *, real 
	    *, real *, real *, real *, integer *, real *, real *, real *, 
	    integer *, integer *), setopt_(integer *, char *, char *, char *, 
	    char *, char *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen), setsub_(
	    integer *, integer *, integer *, real *, integer *, real *), 
	    tabout_(integer *, integer *, integer *, real *, real *, integer *
	    , char *, char *, char *, char *, char *, char *, char *, char *, 
	    char *, char *, char *, char *, char *, integer *, real *, 
	    integer *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen,
	     ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen), urqmak_(real *, 
	    real *, real *, real *, integer *, real *, real *, real *, real *,
	     integer *), feq_gen_get_lctn_items_d_(integer *, integer *, integer *), 
	    feq_gen_set_lctn_items_d_(char *, char *, char *, char *, char *, 
	    doublereal *, doublereal *, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen), inlineb_(integer *, integer *, char *, ftnlen), xsecfit_(
	    integer *, integer *, integer *, real *, char *, char *, char *, 
	    char *, char *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen), 
	    feq_gen_read_tabid_plus_d_(integer *, char *, integer *, char *, integer *,
	     char *, ftnlen, ftnlen, ftnlen);
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__70 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__75 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__82 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__84 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__88 = { 0, 0, 0, fmt_57, 0 };
    static cilist feq_gen_io_d__89 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__96 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__98 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__100 = { 0, 0, 0, fmt_71, 0 };
    static cilist feq_gen_io_d__102 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__104 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__108 = { 0, 0, 0, fmt_96, 0 };
    static cilist feq_gen_io_d__109 = { 0, 0, 0, fmt_98, 0 };
    static cilist feq_gen_io_d__111 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__115 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__117 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__118 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__122 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__124 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__125 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__129 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__130 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__131 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__132 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__134 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__135 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__136 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__137 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__138 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__139 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__140 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__141 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__142 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__143 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__144 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__145 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__146 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__147 = { 0, 0, 0, fmt_84, 0 };
    static cilist feq_gen_io_d__148 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__149 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__150 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__151 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__153 = { 0, 0, 0, fmt_97, 0 };
    static cilist feq_gen_io_d__162 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__163 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Compute a cross section for multiple conduits. */
/*     The allowed shapes are: */
/*     CIRC - circular */
/*     NHE - nominal elliptical with major axis horizontal-ASTM */
/*     NVE - nominal elliptical with major axis vertical-ASTM */
/*     RCPA - reinforced concrete pipe arch shape- ASTM */
/*     THE - true elliptical with major axis horizontal-TYPE=TE */
/*     TVE - true elliptical with major axis vertical-TYPE=TE */
/*     BOX - box culvert- true rectangular opening. */
/*     CMPA- corrugated metal pipe arch from-1980 to present */
/*     CMPAB - corrugated metal pipe arch before current sizes */
/*             were introduced. Pre-1980 */
/*     CMPA1- corrugated metal pipe arch with 1 inch corrugations-1980 */
/*            to present */
/*     CMPA1B- corrugated metal pipe arch with 1 inch corrugations */
/*            before current sizes were introduced. Pre-1980. */
/*     SPPA18- structural plate pipe arch with 18 inch corners. */
/*             6 by 2 inch corrugations */
/*     SPPA31- structural plate pipe arch with 31 inch corners. */
/*             6 by 2 inch corrugations. */
/*     Each conduit will have its own slot and the slot width for the */
/*     aggregate cross section will be the sum of the individual slot */
/*     widths. */
/*     The number of sides to use for each shape is predetermined and */
/*     is not under user control. */
/* SOURCE conduit.for:217 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE conduit.for:219 */
/*<       integereflag,ftp,stdin,stdout,stdtab >*/
/* SOURCE conduit.for:220 */
/*<       integertabdir(*) >*/
/* SOURCE conduit.for:221 */
/*<       realnfac >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     NFAC   - Factor in Manning's formula(1.49 or 1.0) */
/*     TABDIR - Table directory to remember table numbers */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     FTP    - next open location in the function table storage */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE conduit.for:233 */
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
/* INCLUDE conduit.for:234 */
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
/* INCLUDE conduit.for:235 */
/*     NEAR ZERO DEPTH AND DZ COMMON.  ALSO HAS OTHER ITEMS */
/* SOURCE nrdzcm.cmn:3 */
/*<       integerextend,gxtend,nocm,iusgs >*/
/* SOURCE nrdzcm.cmn:5 */
/*<       realnrzero,dzlim,slot >*/
/* SOURCE nrdzcm.cmn:7 */
/*<       common/nrdzcm/nrzero,dzlim,nocm,slot,iusgs,extend,gxtend >*/
/* INCLUDE conduit.for:236 */
/*     Values added to cross section tables: July 1997 */
/*     December 1999, June 2003 */
/* SOURCE xtadd.cmn:4 */
/*<       integerws_tab >*/
/* SOURCE xtadd.cmn:5 */
/*<       realslot_depth,dinvert >*/
/* SOURCE xtadd.cmn:6 */
/*<       real*8easting,northing >*/
/* SOURCE xtadd.cmn:8 */
/*<       character*16gisid,tabid,ws_tabid >*/
/* SOURCE xtadd.cmn:10 */
/*<       common/xtadd/easting,northing,slot_depth,dinvert,ws_tab >*/
/* SOURCE xtadd.cmn:11 */
/*<       common/xtaddc/gisid,tabid,ws_tabid >*/
/* SOURCE xtadd.cmn:13 */
/*<       save/xtadd/,/xtaddc/ >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE conduit.for:239 */
/*<       integernurq >*/
/* SOURCE conduit.for:240 */
/*<        >*/
/* SOURCE conduit.for:246 */
/*<        >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE conduit.for:252 */
/*<       integeri,istart,it,itend,j,je,js,npipes,npnt,nrh,nsides,tab >*/
/* SOURCE conduit.for:254 */
/*<        >*/
/* SOURCE conduit.for:258 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE conduit.for:267 */
/*<       intrinsicabs,max,min >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE conduit.for:270 */
/*<       integerlenstr >*/
/* SOURCE conduit.for:271 */
/*<       charactergettok*10 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE conduit.for:274 */
/*<        >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + INPUT FORMATS + + + */
/* SOURCE conduit.for:279 */
/*<       datanurq/11/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> tabdir(feq_storage_tabdir, 1);

    /* Function Body */
/* SOURCE conduit.for:280 */
/*<        >*/
/* SOURCE conduit.for:283 */
/*<        >*/
/* SOURCE conduit.for:286 */
/*<        >*/
/* SOURCE conduit.for:299 */
/*<        >*/
/* SOURCE conduit.for:308 */
/*<        >*/
/* SOURCE conduit.for:317 */
/*<        >*/
/* SOURCE conduit.for:330 */
/*<        >*/
/* SOURCE conduit.for:343 */
/*<        >*/
/* SOURCE conduit.for:356 */
/*<        >*/
/* SOURCE conduit.for:369 */
/*<        >*/
/* SOURCE conduit.for:388 */
/*<     1 format(7x,i5,a) >*/
/* L1: */
/* SOURCE conduit.for:389 */
/*<     4 format(5x,6a10) >*/
/* L4: */
/* SOURCE conduit.for:390 */
/*<     6 format(6x,f10.0) >*/
/* L6: */
/* SOURCE conduit.for:391 */
/*<     7 format(7x,i5,a10) >*/
/* L7: */
/* SOURCE conduit.for:392 */
/*<     8 format(5x,6f10.0) >*/
/* L8: */
/* SOURCE conduit.for:393 */
/*<     9 format(5x,6f10.0) >*/
/* L9: */
/* SOURCE conduit.for:394 */
/*<    10 format(5x,6f10.0) >*/
/* L10: */
/* SOURCE conduit.for:395 */
/*<    12 format(5x,6f10.0) >*/
/* L12: */
/* SOURCE conduit.for:396 */
/*<    14 format(5x,6f10.0) >*/
/* L14: */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE conduit.for:399 */
/*<    50 format(/,' TABID=',a,2x,a) >*/
/* L50: */
/* SOURCE conduit.for:400 */
/*<    54 format(' Type=     ',6(a10),1x,/,(10x,6(a10))) >*/
/* L54: */
/* SOURCE conduit.for:401 */
/*<    56 format(' Width of slot=',f7.3) >*/
/* L56: */
/* SOURCE conduit.for:402 */
/*<    57 format(' Number of conduits=',i5,' Mud line EPS=',f7.3) >*/
/* L57: */
/* SOURCE conduit.for:403 */
/*<    58 format(' Height of slot above datum=',f7.0) >*/
/* L58: */
/* SOURCE conduit.for:404 */
/*<    62 format(' *ERR:573* Offset space filled in MULCON.') >*/
/* L62: */
/* SOURCE conduit.for:405 */
/*<    64 format(' *ERR:574* SPAN <=0.0 invalid for TYPE=CIRC.') >*/
/* L64: */
/* SOURCE conduit.for:406 */
/*<    66 format(' *ERR:528* Number of conduits=',i5,' > ',i5) >*/
/* L66: */
/* SOURCE conduit.for:407 */
/*<    70 format(' Span=     ',6f10.3) >*/
/* L70: */
/* SOURCE conduit.for:408 */
/*<    71 format(' Rise=     ',6f10.3) >*/
/* L71: */
/* SOURCE conduit.for:409 */
/*<    72 format(' Bottom=   ',6f10.3) >*/
/* L72: */
/* SOURCE conduit.for:410 */
/*<    74 format(' Roughness=',6f10.3) >*/
/* L74: */
/* SOURCE conduit.for:411 */
/*<    76 format(' *ERR:575* RISE and SPAN are 0.0. one must be >0.0 ') >*/
/* L76: */
/* SOURCE conduit.for:412 */
/*<    78  >*/
/* L78: */
/* SOURCE conduit.for:415 */
/*<    80 format(' PROCESSING  TYPE:',1x,a10) >*/
/* L80: */
/* SOURCE conduit.for:416 */
/*<    82 format(' *ERR:576* TYPE=',a10,' UNKNOWN') >*/
/* L82: */
/* SOURCE conduit.for:417 */
/*<    84 format(' *ERR:577* RISE AND SPAN MUST BE > 0.0 FOR TYPE TE') >*/
/* L84: */
/* SOURCE conduit.for:418 */
/*<    86 format('     USING SPAN=',f7.2,' AND RISE=',f7.2) >*/
/* L86: */
/* SOURCE conduit.for:419 */
/*<    92  >*/
/* L92: */
/* SOURCE conduit.for:421 */
/*<    94 format(' *ERR:616* RISE AND SPAN MUST BE > 0.0 FOR TYPE: BOX') >*/
/* L94: */
/* SOURCE conduit.for:422 */
/*<    96 format(' MUD LEVL=',6f10.3) >*/
/* L96: */
/* SOURCE conduit.for:423 */
/*<    97  >*/
/* L97: */
/* SOURCE conduit.for:426 */
/*<    98 format(' MUD ROUGH=',6f10.3) >*/
/* L98: */
/* *********************************************************************** */
/*     ENABLE AUTOMATIC EXTENSION */
/* SOURCE conduit.for:429 */
/*<       extend=1 >*/
    nrdzcm_1.extend = 1;
/*     Set the conversion factor */
/* SOURCE conduit.for:432 */
/*<       if(abs(nfac-1.0).le.0.0001)then >*/
    if ((feq_gen_r_d_1 = static_cast<double>(*nfac) - (float)1., dabs(feq_gen_r_d_1)) <= (float)1e-4) {
/*       Dimensions in meters */
/* SOURCE conduit.for:434 */
/*<       cfac=39.37008 >*/
	cfac = (float)39.37008;
/* SOURCE conduit.for:435 */
/*<       else >*/
    } else {
/* SOURCE conduit.for:436 */
/*<       cfac=12.0 >*/
	cfac = (float)12.;
/* SOURCE conduit.for:437 */
/*<       endif >*/
    }
/* SOURCE conduit.for:438 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:441 */
/*<       callread_tabid_plus(stdout,line,eflag,tabid,tab,cin) >*/
    feq_gen_read_tabid_plus_d_(stdout, line, eflag, xtaddc_1.tabid, &tab, cin, (ftnlen)
	    80, (ftnlen)16, (ftnlen)64);
/* SOURCE conduit.for:444 */
/*<       write(stdout,50)tabid(1:lenstr(tabid)),cin >*/
    feq_gen_io_d__70.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__70);
    do_fio(&feq_gen_c_d_1, xtaddc_1.tabid, lenstr_(xtaddc_1.tabid, (ftnlen)16));
    do_fio(&feq_gen_c_d_1, cin, (ftnlen)64);
    e_wsfe();
/* SOURCE conduit.for:446 */
/*<       callsetopt(stdout,cin,savopt,outopt,monton,betopt) >*/
    setopt_(stdout, cin, savopt, outopt, monton, betopt, (ftnlen)64, (ftnlen)
	    8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE conduit.for:449 */
/*<       if(betopt.ne.'OLDBETA')then >*/
    if (s_cmp(betopt, const_cast<char*>("OLDBETA"), (ftnlen)8, (ftnlen)7) != 0) {
/* SOURCE conduit.for:450 */
/*<       write(stdout,92) >*/
	feq_gen_io_d__75.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__75);
	e_wsfe();
/* SOURCE conduit.for:451 */
/*<       betopt='OLDBETA' >*/
	s_copy(betopt, const_cast<char*>("OLDBETA"), (ftnlen)8, (ftnlen)7);
/* SOURCE conduit.for:452 */
/*<       endif >*/
    }
/* SOURCE conduit.for:454 */
/*<       if(tab.lt.0)then >*/
    if (tab < 0) {
/* SOURCE conduit.for:455 */
/*<       tab=-tab >*/
	tab = -tab;
/* SOURCE conduit.for:456 */
/*<       nocm=0 >*/
	nrdzcm_1.nocm = 0;
/* SOURCE conduit.for:457 */
/*<       else >*/
    } else {
/* SOURCE conduit.for:458 */
/*<       nocm=1 >*/
	nrdzcm_1.nocm = 1;
/* SOURCE conduit.for:459 */
/*<       endif >*/
    }
/* SOURCE conduit.for:461 */
/*<       if(tab.ge.0)calltabchk(stdout,pmxtab,tab,tabdir,eflag) >*/
    if (tab >= 0) {
	tabchk_(stdout, &feq_gen_c_d_10002, &tab, &tabdir[1], eflag);
    }
/* SOURCE conduit.for:465 */
/*<       tabu=tab >*/
    xscomu_1.tabu = tab;
/*     Get location items that may be present. If they are not present */
/*     they will be set to default values.  The default requests FEQUTL */
/*     to omit the items. */
/* SOURCE conduit.for:470 */
/*<       callget_lctn_items(stdin,stdout,eflag) >*/
    feq_gen_get_lctn_items_d_(stdin, stdout, eflag);
/* SOURCE conduit.for:472 */
/*<        >*/
    feq_gen_set_lctn_items_d_(zone, hgrid, vdatum, unitsys, basis, &xtadd_1.easting, &
	    xtadd_1.northing, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (
	    ftnlen)8);
/* SOURCE conduit.for:476 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:479 */
/*<       read(line,6,err=991)wslot >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_6;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&wslot, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE conduit.for:480 */
/*<       write(stdout,56)wslot >*/
    feq_gen_io_d__82.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__82);
    do_fio(&feq_gen_c_d_1, (char *)&wslot, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE conduit.for:482 */
/*<       slot=wslot >*/
    nrdzcm_1.slot = wslot;
/* SOURCE conduit.for:484 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:487 */
/*<       read(line,6,err=991)hslot >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_6;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&hslot, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE conduit.for:488 */
/*<       write(stdout,58)hslot >*/
    feq_gen_io_d__84.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__84);
    do_fio(&feq_gen_c_d_1, (char *)&hslot, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE conduit.for:490 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:493 */
/*<       read(line,7,err=991)npipes,czeps >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_7;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&npipes, (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, czeps, (ftnlen)10);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE conduit.for:494 */
/*<       if(czeps.eq.' ')then >*/
    if (s_cmp(czeps, const_cast<char*>(" "), (ftnlen)10, (ftnlen)1) == 0) {
/* SOURCE conduit.for:495 */
/*<       if(nfac.gt.1.0)then >*/
	if (*nfac > (float)1.) {
/*         English unit set */
/* SOURCE conduit.for:497 */
/*<       zeps=0.02 >*/
	    zeps = (float).02;
/* SOURCE conduit.for:498 */
/*<       else >*/
	} else {
/* SOURCE conduit.for:499 */
/*<       zeps=0.006096 >*/
	    zeps = (float).006096;
/* SOURCE conduit.for:500 */
/*<       endif >*/
	}
/* SOURCE conduit.for:501 */
/*<       else >*/
    } else {
/* SOURCE conduit.for:502 */
/*<       read(czeps,'(F10.0)')zeps >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 10;
	feq_gen_ici_d_1.iciunit = czeps;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.0)");
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&zeps, (ftnlen)sizeof(real));
	e_rsfi();
/* SOURCE conduit.for:503 */
/*<       endif >*/
    }
/* SOURCE conduit.for:504 */
/*<       write(stdout,57)npipes,zeps >*/
    feq_gen_io_d__88.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__88);
    do_fio(&feq_gen_c_d_1, (char *)&npipes, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&zeps, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE conduit.for:506 */
/*<       if(npipes.gt.pmxsub)then >*/
    if (npipes > 200) {
/* SOURCE conduit.for:507 */
/*<       write(stdout,66)npipes,pmxsub >*/
	feq_gen_io_d__89.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__89);
	do_fio(&feq_gen_c_d_1, (char *)&npipes, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_200, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE conduit.for:508 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE conduit.for:509 */
/*<       return >*/
	return 0;
/* SOURCE conduit.for:510 */
/*<       endif >*/
    }
/*     26 October 2006, ddf: Set the gisid to blank.  Uninitialized otherwise! */
/* SOURCE conduit.for:513 */
/*<       gisid=' ' >*/
    s_copy(xtaddc_1.gisid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/*     Compute the controlling parameter for input of the conduit */
/*     descriptions. */
/* SOURCE conduit.for:518 */
/*<       itend=(npipes-1)/6+1 >*/
    itend = (npipes - 1) / 6 + 1;
/* SOURCE conduit.for:519 */
/*<       do485it=1,itend >*/
    feq_gen_i_d_1 = itend;
    for (it = 1; it <= feq_gen_i_d_1; ++it) {
/* SOURCE conduit.for:520 */
/*<       js=1+6*(it-1) >*/
	js = (it - 1) * 6 + 1;
/* SOURCE conduit.for:521 */
/*<       je=js+5 >*/
	je = js + 5;
/* SOURCE conduit.for:522 */
/*<       je=min(je,npipes) >*/
	je = min(je,npipes);
/* SOURCE conduit.for:524 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:527 */
/*<       read(line,4,err=991)(type(j),j=js,je) >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_4;
	feq_gen_i_d_2 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_2 != 0) {
	    goto L991;
	}
	feq_gen_i_d_3 = je;
	for (j = js; j <= feq_gen_i_d_3; ++j) {
	    feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, feq_gen_type_d_ + (j - 1) * 10, (ftnlen)10);
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
	}
	feq_gen_i_d_2 = e_rsfi();
	if (feq_gen_i_d_2 != 0) {
	    goto L991;
	}
/* SOURCE conduit.for:528 */
/*<       write(stdout,54)(type(j),j=js,je) >*/
	feq_gen_io_d__96.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__96);
	feq_gen_i_d_2 = je;
	for (j = js; j <= feq_gen_i_d_2; ++j) {
	    do_fio(&feq_gen_c_d_1, feq_gen_type_d_ + (j - 1) * 10, (ftnlen)10);
	}
	e_wsfe();
/* SOURCE conduit.for:530 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:533 */
/*<       read(line,8,err=991)(span(j),j=js,je) >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_8;
	feq_gen_i_d_2 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_2 != 0) {
	    goto L991;
	}
	feq_gen_i_d_3 = je;
	for (j = js; j <= feq_gen_i_d_3; ++j) {
	    feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&span[j - 1], (ftnlen)sizeof(real));
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
	}
	feq_gen_i_d_2 = e_rsfi();
	if (feq_gen_i_d_2 != 0) {
	    goto L991;
	}
/* SOURCE conduit.for:534 */
/*<       write(stdout,70)(span(j),j=js,je) >*/
	feq_gen_io_d__98.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__98);
	feq_gen_i_d_2 = je;
	for (j = js; j <= feq_gen_i_d_2; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&span[j - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
/* SOURCE conduit.for:536 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:539 */
/*<       read(line,8,err=991)(rise(j),j=js,je) >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_8;
	feq_gen_i_d_2 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_2 != 0) {
	    goto L991;
	}
	feq_gen_i_d_3 = je;
	for (j = js; j <= feq_gen_i_d_3; ++j) {
	    feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&rise[j - 1], (ftnlen)sizeof(real));
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
	}
	feq_gen_i_d_2 = e_rsfi();
	if (feq_gen_i_d_2 != 0) {
	    goto L991;
	}
/* SOURCE conduit.for:540 */
/*<       write(stdout,71)(rise(j),j=js,je) >*/
	feq_gen_io_d__100.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__100);
	feq_gen_i_d_2 = je;
	for (j = js; j <= feq_gen_i_d_2; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&rise[j - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
/* SOURCE conduit.for:542 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:545 */
/*<       read(line,9,err=991)(bottom(j),j=js,je) >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_9;
	feq_gen_i_d_2 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_2 != 0) {
	    goto L991;
	}
	feq_gen_i_d_3 = je;
	for (j = js; j <= feq_gen_i_d_3; ++j) {
	    feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&bottom[j - 1], (ftnlen)sizeof(real))
		    ;
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
	}
	feq_gen_i_d_2 = e_rsfi();
	if (feq_gen_i_d_2 != 0) {
	    goto L991;
	}
/* SOURCE conduit.for:546 */
/*<       write(stdout,72)(bottom(j),j=js,je) >*/
	feq_gen_io_d__102.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__102);
	feq_gen_i_d_2 = je;
	for (j = js; j <= feq_gen_i_d_2; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&bottom[j - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
/* SOURCE conduit.for:548 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:551 */
/*<       read(line,10,err=991)(rough(j),j=js,je) >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_10;
	feq_gen_i_d_2 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_2 != 0) {
	    goto L991;
	}
	feq_gen_i_d_3 = je;
	for (j = js; j <= feq_gen_i_d_3; ++j) {
	    feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&rough[j - 1], (ftnlen)sizeof(real));
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
	}
	feq_gen_i_d_2 = e_rsfi();
	if (feq_gen_i_d_2 != 0) {
	    goto L991;
	}
/* SOURCE conduit.for:552 */
/*<       write(stdout,74)(rough(j),j=js,je) >*/
	feq_gen_io_d__104.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__104);
	feq_gen_i_d_2 = je;
	for (j = js; j <= feq_gen_i_d_2; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&rough[j - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
/*       Look ahead for the mudline input line.  If not there, backspace */
/*       the input file and set the mud line level to null. */
/* SOURCE conduit.for:557 */
/*<       callinlineb(stdin,stdout,line) >*/
	inlineb_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:560 */
/*<       if(line(1:4).ne.'MUDL')then >*/
	if (s_cmp(line, const_cast<char*>("MUDL"), (ftnlen)4, (ftnlen)4) != 0) {
/* SOURCE conduit.for:561 */
/*<       backspacestdin >*/
	    feq_gen_al_d_1.aerr = 0;
	    feq_gen_al_d_1.aunit = *stdin;
	    f_back(&feq_gen_al_d_1);
/* SOURCE conduit.for:562 */
/*<       do480i=js,je >*/
	    feq_gen_i_d_2 = je;
	    for (feq_gen_i_d_ = js; feq_gen_i_d_ <= feq_gen_i_d_2; ++feq_gen_i_d_) {
/* SOURCE conduit.for:563 */
/*<       zmud(i)=0.0 >*/
		zmud[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE conduit.for:564 */
/*<       nmud(i)=0.0 >*/
		nmud[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE conduit.for:565 */
/*<   480 continue >*/
/* L480: */
	    }
/* SOURCE conduit.for:566 */
/*<       else >*/
	} else {
/*         READ THE MUDLINE LEVEL */
/* SOURCE conduit.for:568 */
/*<       read(line,12,err=991)(zmud(j),j=js,je) >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 80;
	    feq_gen_ici_d_1.iciunit = line;
	    feq_gen_ici_d_1.icifmt = fmt_12;
	    feq_gen_i_d_2 = s_rsfi(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_3 = je;
	    for (j = js; j <= feq_gen_i_d_3; ++j) {
		feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&zmud[j - 1], (ftnlen)sizeof(
			real));
		if (feq_gen_i_d_2 != 0) {
		    goto L991;
		}
	    }
	    feq_gen_i_d_2 = e_rsfi();
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
/* SOURCE conduit.for:569 */
/*<       write(stdout,96)(zmud(j),j=js,je) >*/
	    feq_gen_io_d__108.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__108);
	    feq_gen_i_d_2 = je;
	    for (j = js; j <= feq_gen_i_d_2; ++j) {
		do_fio(&feq_gen_c_d_1, (char *)&zmud[j - 1], (ftnlen)sizeof(real));
	    }
	    e_wsfe();
/* SOURCE conduit.for:570 */
/*<       callinline(stdin,stdout,line) >*/
	    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:573 */
/*<       read(line,14,err=991)(nmud(j),j=js,je) >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 80;
	    feq_gen_ici_d_1.iciunit = line;
	    feq_gen_ici_d_1.icifmt = fmt_14;
	    feq_gen_i_d_2 = s_rsfi(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_3 = je;
	    for (j = js; j <= feq_gen_i_d_3; ++j) {
		feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&nmud[j - 1], (ftnlen)sizeof(
			real));
		if (feq_gen_i_d_2 != 0) {
		    goto L991;
		}
	    }
	    feq_gen_i_d_2 = e_rsfi();
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
/* SOURCE conduit.for:574 */
/*<       write(stdout,98)(nmud(j),j=js,je) >*/
	    feq_gen_io_d__109.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__109);
	    feq_gen_i_d_2 = je;
	    for (j = js; j <= feq_gen_i_d_2; ++j) {
		do_fio(&feq_gen_c_d_1, (char *)&nmud[j - 1], (ftnlen)sizeof(real));
	    }
	    e_wsfe();
/* SOURCE conduit.for:575 */
/*<       endif >*/
	}
/* SOURCE conduit.for:577 */
/*<   485 continue >*/
/* L485: */
    }
/*     STRIP LEADING BLANKS FROM THE TYPE NAMES */
/* SOURCE conduit.for:580 */
/*<       do99i=1,npipes >*/
    feq_gen_i_d_1 = npipes;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE conduit.for:581 */
/*<       type(i)=gettok(type(i)) >*/
	gettok_(feq_gen_ch_d_1, (ftnlen)10, feq_gen_type_d_ + (feq_gen_i_d_ - 1) * 10, (ftnlen)10);
	s_copy(feq_gen_type_d_ + (feq_gen_i_d_ - 1) * 10, feq_gen_ch_d_1, (ftnlen)10, (ftnlen)10);
/* SOURCE conduit.for:582 */
/*<    99 continue >*/
/* L99: */
    }
/*     CONSTRUCT THE POINTS ON THE BOUNDARY OF THE SLOTTED CONDUIT */
/*     PLACE CONDUITS SIDE BY SIDE EACH WITH A SLOT.  ASSIGN A DIFFERENT */
/*     SUBSECTION TO EACH.  XOFF WILL BE MADE LARGE ENOUGH */
/*     SO THAT THE PIPES DO NOT OVERLAP */
/*     MATCH AREA OF CONDUIT WITH A POLYGON WITH A SUITABLE NUMBER OF */
/*     SIDES. */
/*     THE ORIGIN FOR THE COORDINATES WILL BE AT THE DATUM LEVEL. THUS */
/*     THERE WILL BE SOME NEGATIVE `ELEVATIONS' IN THE DESCRIPTION */
/*     OF THE PERIMETER. */
/*     CHECK FOR SPACE- ALL SHAPES HAVE THE SAME NUMBER OF SIDES */
/*     NOT  TRUE FOR BOX CULVERTS  AND ARCH SHAPES.  TAKE MOST */
/*     DEMANDING VALUE. */
/* SOURCE conduit.for:598 */
/*<       nsides=44 >*/
    nsides = 44;
/* SOURCE conduit.for:599 */
/*<       if((nsides+4)*npipes.gt.pmxpnt)then >*/
    if ((nsides + 4) * npipes > 999) {
/* SOURCE conduit.for:600 */
/*<       write(stdout,62) >*/
	feq_gen_io_d__111.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__111);
	e_wsfe();
/* SOURCE conduit.for:601 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE conduit.for:602 */
/*<       return >*/
	return 0;
/* SOURCE conduit.for:603 */
/*<       endif >*/
    }
/*     SINUOSITY CORRECTION NOT NEEDED FOR CLOSED CONDUITS. */
/* SOURCE conduit.for:607 */
/*<       snflgu=0 >*/
    xscomu_1.snflgu = 0;
/*     Clear values not set elsewhere.  Manning's n is not a variable */
/*     with depth. */
/* SOURCE conduit.for:611 */
/*<       do490i=1,npipes >*/
    feq_gen_i_d_1 = npipes;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE conduit.for:612 */
/*<       nvaru(i)=0 >*/
	xscomu_1.nvaru[feq_gen_i_d_ - 1] = 0;
/* SOURCE conduit.for:613 */
/*<       nnyu(i)=0 >*/
	xscomu_1.nnyu[feq_gen_i_d_ - 1] = 0;
/* SOURCE conduit.for:614 */
/*<   490 continue >*/
/* L490: */
    }
/*     CLEAR THE MAXIMUM SOFFIT VALUE. */
/* SOURCE conduit.for:619 */
/*<  9000 continue >*/
L9000:
/* SOURCE conduit.for:620 */
/*<       maxsof=0.0 >*/
    maxsof = (float)0.;
/* SOURCE conduit.for:621 */
/*<       xoff=0.0 >*/
    xoff = (float)0.;
/* SOURCE conduit.for:622 */
/*<       istart=1 >*/
    istart = 1;
/* SOURCE conduit.for:623 */
/*<       npntu=0 >*/
    xscomu_1.npntu = 0;
/* SOURCE conduit.for:624 */
/*<       do500i=1,npipes >*/
    feq_gen_i_d_1 = npipes;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE conduit.for:626 */
/*<       write(stdout,80)type(i) >*/
	feq_gen_io_d__115.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__115);
	do_fio(&feq_gen_c_d_1, feq_gen_type_d_ + (feq_gen_i_d_ - 1) * 10, (ftnlen)10);
	e_wsfe();
/* SOURCE conduit.for:628 */
/*<       zoff=bottom(i) >*/
	zoff = bottom[feq_gen_i_d_ - 1];
/* SOURCE conduit.for:630 */
/*<       if(type(i).eq.'CIRC')then >*/
	if (s_cmp(feq_gen_type_d_ + (feq_gen_i_d_ - 1) * 10, const_cast<char*>("CIRC"), (ftnlen)10, (ftnlen)4) == 
		0) {
/* SOURCE conduit.for:632 */
/*<       nsides=40 >*/
	    nsides = 40;
/* SOURCE conduit.for:635 */
/*<       if(span(i).le.0.0)then >*/
	    if (span[feq_gen_i_d_ - 1] <= (float)0.) {
/* SOURCE conduit.for:636 */
/*<       write(stdout,64) >*/
		feq_gen_io_d__117.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__117);
		e_wsfe();
/* SOURCE conduit.for:637 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE conduit.for:638 */
/*<       return >*/
		return 0;
/* SOURCE conduit.for:639 */
/*<       endif >*/
	    }
/* SOURCE conduit.for:640 */
/*<       rise(i)=span(i) >*/
	    rise[feq_gen_i_d_ - 1] = span[feq_gen_i_d_ - 1];
/* SOURCE conduit.for:641 */
/*<       write(stdout,86)span(i),rise(i) >*/
	    feq_gen_io_d__118.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__118);
	    do_fio(&feq_gen_c_d_1, (char *)&span[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&rise[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE conduit.for:643 */
/*<       maxsof=max(maxsof,rise(i)+zoff) >*/
/* Computing MAX */
	    feq_gen_r_d_1 = maxsof, feq_gen_r_d_2 = static_cast<double>(rise[feq_gen_i_d_ - 1]) + zoff;
	    maxsof = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE conduit.for:644 */
/*<       if(i==1)then >*/
	    if (feq_gen_i_d_ == 1) {
/* SOURCE conduit.for:645 */
/*<       xoff=xoff+0.5*span(i)+0.25 >*/
		xoff = static_cast<double>(static_cast<double>(xoff) + static_cast<double>(span[feq_gen_i_d_ - 1]) * (float).5) + (float).25;
/* SOURCE conduit.for:646 */
/*<       else >*/
	    } else {
/* SOURCE conduit.for:647 */
/*<       xoff=xoff+0.5*(span(i-1)+span(i))+0.25 >*/
		xoff = static_cast<double>(static_cast<double>(xoff) + static_cast<double>((static_cast<double>(span[feq_gen_i_d_ - 2]) + span[feq_gen_i_d_ - 1])) * (float).5) + (
			float).25;
/* SOURCE conduit.for:648 */
/*<       endif >*/
	    }
/* SOURCE conduit.for:649 */
/*<        >*/
	    mkpipe_(&xoff, &zoff, &nsides, &span[feq_gen_i_d_ - 1], &wslot, &hslot, &
		    npnt, &xscomu_1.xu[istart - 1], &xscomu_1.zu[istart - 1]);
/* SOURCE conduit.for:653 */
/*<       elseif(type(i).eq.'NHE')then >*/
	} else if (s_cmp(feq_gen_type_d_ + (feq_gen_i_d_ - 1) * 10, const_cast<char*>("NHE"), (ftnlen)10, (ftnlen)
		3) == 0) {
/*           FIND THE EQUIVALENT DIAMETER TO USE */
/* SOURCE conduit.for:656 */
/*<       dh=span(i)/1.26 >*/
	    dh = static_cast<double>(span[feq_gen_i_d_ - 1]) / (float)1.26;
/* SOURCE conduit.for:657 */
/*<       dv=rise(i)/0.80 >*/
	    dv = static_cast<double>(rise[feq_gen_i_d_ - 1]) / (float).8;
/* SOURCE conduit.for:658 */
/*<       if(dh.le.0.0.and.dv.le.0.0)then >*/
	    if (dh <= (float)0. && dv <= (float)0.) {
/* SOURCE conduit.for:659 */
/*<       write(stdout,76) >*/
		feq_gen_io_d__122.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__122);
		e_wsfe();
/* SOURCE conduit.for:660 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE conduit.for:661 */
/*<       return >*/
		return 0;
/* SOURCE conduit.for:662 */
/*<       elseif(dh.le.0.0)then >*/
	    } else if (dh <= (float)0.) {
/* SOURCE conduit.for:663 */
/*<       d=dv >*/
		feq_gen_d_d_ = dv;
/* SOURCE conduit.for:664 */
/*<       elseif(dv.le.0.0)then >*/
	    } else if (dv <= (float)0.) {
/* SOURCE conduit.for:665 */
/*<       d=dh >*/
		feq_gen_d_d_ = dh;
/* SOURCE conduit.for:666 */
/*<       else >*/
	    } else {
/*             BOTH > 0.0 HERE- ARE THEY CONSISTENT? */
/* SOURCE conduit.for:668 */
/*<       if(abs(dh-dv)/(dh+dv).le.0.015)then >*/
		if ((feq_gen_r_d_1 = static_cast<double>(dh) - dv, dabs(feq_gen_r_d_1)) / (static_cast<double>(dh) + dv) <= (float).015) {
/* SOURCE conduit.for:669 */
/*<       d=dv >*/
		    feq_gen_d_d_ = dv;
/* SOURCE conduit.for:670 */
/*<       else >*/
		} else {
/* SOURCE conduit.for:671 */
/*<       write(stdout,78)dh,dv >*/
		    feq_gen_io_d__124.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__124);
		    do_fio(&feq_gen_c_d_1, (char *)&dh, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&dv, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE conduit.for:672 */
/*<       d=dv >*/
		    feq_gen_d_d_ = dv;
/* SOURCE conduit.for:673 */
/*<       endif >*/
		}
/* SOURCE conduit.for:674 */
/*<       endif >*/
	    }
/* SOURCE conduit.for:677 */
/*<       span(i)=1.26*d >*/
	    span[feq_gen_i_d_ - 1] = static_cast<double>(feq_gen_d_d_) * (float)1.26;
/* SOURCE conduit.for:678 */
/*<       rise(i)=0.8*d >*/
	    rise[feq_gen_i_d_ - 1] = static_cast<double>(feq_gen_d_d_) * (float).8;
/* SOURCE conduit.for:680 */
/*<       write(stdout,86)span(i),rise(i) >*/
	    feq_gen_io_d__125.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__125);
	    do_fio(&feq_gen_c_d_1, (char *)&span[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&rise[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE conduit.for:681 */
/*<       maxsof=max(maxsof,rise(i)+zoff) >*/
/* Computing MAX */
	    feq_gen_r_d_1 = maxsof, feq_gen_r_d_2 = static_cast<double>(rise[feq_gen_i_d_ - 1]) + zoff;
	    maxsof = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/*           SCALE THE STANDARD UPPER RIGHT QUADRANT TO THE CURRENT */
/*           EQUIVALENT DIAMETER */
/* SOURCE conduit.for:686 */
/*<       do100j=1,nurq >*/
	    feq_gen_i_d_2 = nurq;
	    for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE conduit.for:687 */
/*<       xt(j)=d*urqx(j) >*/
		xt[j - 1] = static_cast<double>(feq_gen_d_d_) * urqx[j - 1];
/* SOURCE conduit.for:688 */
/*<       yt(j)=d*urqy(j) >*/
		yt[j - 1] = static_cast<double>(feq_gen_d_d_) * urqy[j - 1];
/* SOURCE conduit.for:689 */
/*<   100 continue >*/
/* L100: */
	    }
/* SOURCE conduit.for:691 */
/*<       yoff=zoff+0.4*d >*/
	    yoff = static_cast<double>(zoff) + static_cast<double>(feq_gen_d_d_) * (float).4;
/* SOURCE conduit.for:692 */
/*<       if(i==1)then >*/
	    if (feq_gen_i_d_ == 1) {
/* SOURCE conduit.for:693 */
/*<       xoff=xoff+0.5*span(i)+0.25 >*/
		xoff = static_cast<double>(static_cast<double>(xoff) + static_cast<double>(span[feq_gen_i_d_ - 1]) * (float).5) + (float).25;
/* SOURCE conduit.for:694 */
/*<       else >*/
	    } else {
/* SOURCE conduit.for:695 */
/*<       xoff=xoff+0.5*(span(i-1)+span(i))+0.25 >*/
		xoff = static_cast<double>(static_cast<double>(xoff) + static_cast<double>((static_cast<double>(span[feq_gen_i_d_ - 2]) + span[feq_gen_i_d_ - 1])) * (float).5) + (
			float).25;
/* SOURCE conduit.for:696 */
/*<       endif >*/
	    }
/* SOURCE conduit.for:697 */
/*<        >*/
	    urqmak_(&wslot, &hslot, &yoff, &xoff, &nurq, xt, yt, &xscomu_1.xu[
		    istart - 1], &xscomu_1.zu[istart - 1], &npnt);
/* SOURCE conduit.for:702 */
/*<       elseif(type(i).eq.'NVE')then >*/
	} else if (s_cmp(feq_gen_type_d_ + (feq_gen_i_d_ - 1) * 10, const_cast<char*>("NVE"), (ftnlen)10, (ftnlen)
		3) == 0) {
/*           FIND THE EQUIVALENT DIAMETER TO USE */
/* SOURCE conduit.for:705 */
/*<       dh=span(i)/0.80 >*/
	    dh = static_cast<double>(span[feq_gen_i_d_ - 1]) / (float).8;
/* SOURCE conduit.for:706 */
/*<       dv=rise(i)/1.26 >*/
	    dv = static_cast<double>(rise[feq_gen_i_d_ - 1]) / (float)1.26;
/* SOURCE conduit.for:707 */
/*<       if(dh.le.0.0.and.dv.le.0.0)then >*/
	    if (dh <= (float)0. && dv <= (float)0.) {
/* SOURCE conduit.for:708 */
/*<       write(stdout,76) >*/
		feq_gen_io_d__129.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__129);
		e_wsfe();
/* SOURCE conduit.for:709 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE conduit.for:710 */
/*<       return >*/
		return 0;
/* SOURCE conduit.for:711 */
/*<       elseif(dh.le.0.0)then >*/
	    } else if (dh <= (float)0.) {
/* SOURCE conduit.for:712 */
/*<       d=dv >*/
		feq_gen_d_d_ = dv;
/* SOURCE conduit.for:713 */
/*<       elseif(dv.le.0.0)then >*/
	    } else if (dv <= (float)0.) {
/* SOURCE conduit.for:714 */
/*<       d=dh >*/
		feq_gen_d_d_ = dh;
/* SOURCE conduit.for:715 */
/*<       else >*/
	    } else {
/*             BOTH > 0.0 HERE- ARE THEY CONSISTENT? */
/* SOURCE conduit.for:717 */
/*<       if(abs(dh-dv)/(dh+dv).le.0.015)then >*/
		if ((feq_gen_r_d_1 = static_cast<double>(dh) - dv, dabs(feq_gen_r_d_1)) / (static_cast<double>(dh) + dv) <= (float).015) {
/* SOURCE conduit.for:718 */
/*<       d=dv >*/
		    feq_gen_d_d_ = dv;
/* SOURCE conduit.for:719 */
/*<       else >*/
		} else {
/* SOURCE conduit.for:720 */
/*<       write(stdout,78)dh,dv >*/
		    feq_gen_io_d__130.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__130);
		    do_fio(&feq_gen_c_d_1, (char *)&dh, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&dv, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE conduit.for:721 */
/*<       d=dv >*/
		    feq_gen_d_d_ = dv;
/* SOURCE conduit.for:722 */
/*<       endif >*/
		}
/* SOURCE conduit.for:723 */
/*<       endif >*/
	    }
/* SOURCE conduit.for:725 */
/*<       rise(i)=1.26*d >*/
	    rise[feq_gen_i_d_ - 1] = static_cast<double>(feq_gen_d_d_) * (float)1.26;
/* SOURCE conduit.for:726 */
/*<       span(i)=0.8*d >*/
	    span[feq_gen_i_d_ - 1] = static_cast<double>(feq_gen_d_d_) * (float).8;
/* SOURCE conduit.for:727 */
/*<       write(stdout,86)span(i),rise(i) >*/
	    feq_gen_io_d__131.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__131);
	    do_fio(&feq_gen_c_d_1, (char *)&span[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&rise[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE conduit.for:728 */
/*<       maxsof=max(maxsof,rise(i)+zoff) >*/
/* Computing MAX */
	    feq_gen_r_d_1 = maxsof, feq_gen_r_d_2 = static_cast<double>(rise[feq_gen_i_d_ - 1]) + zoff;
	    maxsof = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/*           SCALE THE STANDARD UPPER RIGHT QUADRANT TO THE CURRENT */
/*           EQUIVALENT DIAMETER AND ROTATE FOR VERTICAL OPTION */
/* SOURCE conduit.for:733 */
/*<       do102j=nurq,1,-1 >*/
	    for (j = nurq; j >= 1; --j) {
/* SOURCE conduit.for:734 */
/*<       xt(nurq+1-j)=d*urqy(j) >*/
		xt[nurq + 1 - j - 1] = static_cast<double>(feq_gen_d_d_) * urqy[j - 1];
/* SOURCE conduit.for:735 */
/*<       yt(nurq+1-j)=d*urqx(j) >*/
		yt[nurq + 1 - j - 1] = static_cast<double>(feq_gen_d_d_) * urqx[j - 1];
/* SOURCE conduit.for:736 */
/*<   102 continue >*/
/* L102: */
	    }
/* SOURCE conduit.for:738 */
/*<       yoff=zoff+0.63*d >*/
	    yoff = static_cast<double>(zoff) + static_cast<double>(feq_gen_d_d_) * (float).63;
/* SOURCE conduit.for:739 */
/*<       if(i==1)then >*/
	    if (feq_gen_i_d_ == 1) {
/* SOURCE conduit.for:740 */
/*<       xoff=xoff+0.5*span(i)+0.25 >*/
		xoff = static_cast<double>(static_cast<double>(xoff) + static_cast<double>(span[feq_gen_i_d_ - 1]) * (float).5) + (float).25;
/* SOURCE conduit.for:741 */
/*<       else >*/
	    } else {
/* SOURCE conduit.for:742 */
/*<       xoff=xoff+0.5*(span(i-1)+span(i))+0.25 >*/
		xoff = static_cast<double>(static_cast<double>(xoff) + static_cast<double>((static_cast<double>(span[feq_gen_i_d_ - 2]) + span[feq_gen_i_d_ - 1])) * (float).5) + (
			float).25;
/* SOURCE conduit.for:743 */
/*<       endif >*/
	    }
/* SOURCE conduit.for:744 */
/*<        >*/
	    urqmak_(&wslot, &hslot, &yoff, &xoff, &nurq, xt, yt, &xscomu_1.xu[
		    istart - 1], &xscomu_1.zu[istart - 1], &npnt);
/* SOURCE conduit.for:749 */
/*<       elseif(type(i).eq.'RCPA')then >*/
	} else if (s_cmp(feq_gen_type_d_ + (feq_gen_i_d_ - 1) * 10, const_cast<char*>("RCPA"), (ftnlen)10, (ftnlen)
		4) == 0) {
/*           Reinforced concrete pipe arch */
/* SOURCE conduit.for:752 */
/*<       if(span(i).le.0.0.and.rise(i).le.0.0)then >*/
	    if (span[feq_gen_i_d_ - 1] <= (float)0. && rise[feq_gen_i_d_ - 1] <= (float)0.) {
/* SOURCE conduit.for:753 */
/*<       write(stdout,76) >*/
		feq_gen_io_d__132.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__132);
		e_wsfe();
/* SOURCE conduit.for:754 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE conduit.for:755 */
/*<       return >*/
		return 0;
/* SOURCE conduit.for:756 */
/*<       endif >*/
	    }
/*           COMPUTE THE SEMI-PERIMETER FOR THIS SIZE ARCH PIPE */
/* SOURCE conduit.for:760 */
/*<        >*/
	    rharch_(stdout, &feq_gen_c_d_17, rsrc, sprc, r1rc, r3rc, &cfac, &rise[feq_gen_i_d_ 
		    - 1], &span[feq_gen_i_d_ - 1], eflag, &nrh, xt, yt, &yoff);
/* SOURCE conduit.for:765 */
/*<       write(stdout,86)span(i),rise(i) >*/
	    feq_gen_io_d__134.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__134);
	    do_fio(&feq_gen_c_d_1, (char *)&span[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&rise[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE conduit.for:766 */
/*<       maxsof=max(maxsof,rise(i)+zoff) >*/
/* Computing MAX */
	    feq_gen_r_d_1 = maxsof, feq_gen_r_d_2 = static_cast<double>(rise[feq_gen_i_d_ - 1]) + zoff;
	    maxsof = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE conduit.for:768 */
/*<       if(eflag.gt.0)return >*/
	    if (*eflag > 0) {
		return 0;
	    }
/* SOURCE conduit.for:769 */
/*<       yoff=yoff+zoff >*/
	    yoff += zoff;
/* SOURCE conduit.for:770 */
/*<       if(i==1)then >*/
	    if (feq_gen_i_d_ == 1) {
/* SOURCE conduit.for:771 */
/*<       xoff=xoff+0.5*span(i)+0.25 >*/
		xoff = static_cast<double>(static_cast<double>(xoff) + static_cast<double>(span[feq_gen_i_d_ - 1]) * (float).5) + (float).25;
/* SOURCE conduit.for:772 */
/*<       else >*/
	    } else {
/* SOURCE conduit.for:773 */
/*<       xoff=xoff+0.5*(span(i-1)+span(i))+0.25 >*/
		xoff = static_cast<double>(static_cast<double>(xoff) + static_cast<double>((static_cast<double>(span[feq_gen_i_d_ - 2]) + span[feq_gen_i_d_ - 1])) * (float).5) + (
			float).25;
/* SOURCE conduit.for:774 */
/*<       endif >*/
	    }
/* SOURCE conduit.for:775 */
/*<        >*/
	    rhmak_(&wslot, &hslot, &yoff, &xoff, &nrh, xt, yt, &xscomu_1.xu[
		    istart - 1], &xscomu_1.zu[istart - 1], &npnt);
/* SOURCE conduit.for:779 */
/*<       elseif(type(i).eq.'CMPA')then >*/
	} else if (s_cmp(feq_gen_type_d_ + (feq_gen_i_d_ - 1) * 10, const_cast<char*>("CMPA"), (ftnlen)10, (ftnlen)
		4) == 0) {
/*           Corrugated metal pipe arch */
/* SOURCE conduit.for:782 */
/*<       if(span(i).le.0.0.and.rise(i).le.0.0)then >*/
	    if (span[feq_gen_i_d_ - 1] <= (float)0. && rise[feq_gen_i_d_ - 1] <= (float)0.) {
/* SOURCE conduit.for:783 */
/*<       write(stdout,76) >*/
		feq_gen_io_d__135.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__135);
		e_wsfe();
/* SOURCE conduit.for:784 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE conduit.for:785 */
/*<       return >*/
		return 0;
/* SOURCE conduit.for:786 */
/*<       endif >*/
	    }
/*           COMPUTE THE SEMI-PERIMETER FOR THIS SIZE ARCH PIPE */
/* SOURCE conduit.for:790 */
/*<        >*/
	    rharch_(stdout, &feq_gen_c_d_12, rscm, spcm, r1cm, r3cm, &cfac, &rise[feq_gen_i_d_ 
		    - 1], &span[feq_gen_i_d_ - 1], eflag, &nrh, xt, yt, &yoff);
/* SOURCE conduit.for:795 */
/*<       write(stdout,86)span(i),rise(i) >*/
	    feq_gen_io_d__136.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__136);
	    do_fio(&feq_gen_c_d_1, (char *)&span[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&rise[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE conduit.for:796 */
/*<       maxsof=max(maxsof,rise(i)+zoff) >*/
/* Computing MAX */
	    feq_gen_r_d_1 = maxsof, feq_gen_r_d_2 = static_cast<double>(rise[feq_gen_i_d_ - 1]) + zoff;
	    maxsof = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE conduit.for:798 */
/*<       if(eflag.gt.0)return >*/
	    if (*eflag > 0) {
		return 0;
	    }
/* SOURCE conduit.for:799 */
/*<       yoff=yoff+zoff >*/
	    yoff += zoff;
/* SOURCE conduit.for:800 */
/*<       if(i==1)then >*/
	    if (feq_gen_i_d_ == 1) {
/* SOURCE conduit.for:801 */
/*<       xoff=xoff+0.5*span(i)+0.25 >*/
		xoff = static_cast<double>(static_cast<double>(xoff) + static_cast<double>(span[feq_gen_i_d_ - 1]) * (float).5) + (float).25;
/* SOURCE conduit.for:802 */
/*<       else >*/
	    } else {
/* SOURCE conduit.for:803 */
/*<       xoff=xoff+0.5*(span(i-1)+span(i))+0.25 >*/
		xoff = static_cast<double>(static_cast<double>(xoff) + static_cast<double>((static_cast<double>(span[feq_gen_i_d_ - 2]) + span[feq_gen_i_d_ - 1])) * (float).5) + (
			float).25;
/* SOURCE conduit.for:804 */
/*<       endif >*/
	    }
/* SOURCE conduit.for:805 */
/*<        >*/
	    rhmak_(&wslot, &hslot, &yoff, &xoff, &nrh, xt, yt, &xscomu_1.xu[
		    istart - 1], &xscomu_1.zu[istart - 1], &npnt);
/* SOURCE conduit.for:809 */
/*<       elseif(type(i).eq.'CMPAB')then >*/
	} else if (s_cmp(feq_gen_type_d_ + (feq_gen_i_d_ - 1) * 10, const_cast<char*>("CMPAB"), (ftnlen)10, (
		ftnlen)5) == 0) {
/*           Corrugated metal pipe arch before current values */
/*           were introduced.  In use in 1967 and 1971. */
/* SOURCE conduit.for:813 */
/*<       if(span(i).le.0.0.and.rise(i).le.0.0)then >*/
	    if (span[feq_gen_i_d_ - 1] <= (float)0. && rise[feq_gen_i_d_ - 1] <= (float)0.) {
/* SOURCE conduit.for:814 */
/*<       write(stdout,76) >*/
		feq_gen_io_d__137.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__137);
		e_wsfe();
/* SOURCE conduit.for:815 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE conduit.for:816 */
/*<       return >*/
		return 0;
/* SOURCE conduit.for:817 */
/*<       endif >*/
	    }
/*           COMPUTE THE SEMI-PERIMETER FOR THIS SIZE ARCH PIPE */
/* SOURCE conduit.for:821 */
/*<        >*/
	    rharch_(stdout, &feq_gen_c_d_12, rscmb, spcmb, r1cmb, r3cmb, &cfac, &rise[
		    feq_gen_i_d_ - 1], &span[feq_gen_i_d_ - 1], eflag, &nrh, xt, yt, &yoff);
/* SOURCE conduit.for:826 */
/*<       write(stdout,86)span(i),rise(i) >*/
	    feq_gen_io_d__138.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__138);
	    do_fio(&feq_gen_c_d_1, (char *)&span[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&rise[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE conduit.for:827 */
/*<       maxsof=max(maxsof,rise(i)+zoff) >*/
/* Computing MAX */
	    feq_gen_r_d_1 = maxsof, feq_gen_r_d_2 = static_cast<double>(rise[feq_gen_i_d_ - 1]) + zoff;
	    maxsof = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE conduit.for:829 */
/*<       if(eflag.gt.0)return >*/
	    if (*eflag > 0) {
		return 0;
	    }
/* SOURCE conduit.for:830 */
/*<       yoff=yoff+zoff >*/
	    yoff += zoff;
/* SOURCE conduit.for:831 */
/*<       if(i==1)then >*/
	    if (feq_gen_i_d_ == 1) {
/* SOURCE conduit.for:832 */
/*<       xoff=xoff+0.5*span(i)+0.25 >*/
		xoff = static_cast<double>(static_cast<double>(xoff) + static_cast<double>(span[feq_gen_i_d_ - 1]) * (float).5) + (float).25;
/* SOURCE conduit.for:833 */
/*<       else >*/
	    } else {
/* SOURCE conduit.for:834 */
/*<       xoff=xoff+0.5*(span(i-1)+span(i))+0.25 >*/
		xoff = static_cast<double>(static_cast<double>(xoff) + static_cast<double>((static_cast<double>(span[feq_gen_i_d_ - 2]) + span[feq_gen_i_d_ - 1])) * (float).5) + (
			float).25;
/* SOURCE conduit.for:835 */
/*<       endif >*/
	    }
/* SOURCE conduit.for:836 */
/*<        >*/
	    rhmak_(&wslot, &hslot, &yoff, &xoff, &nrh, xt, yt, &xscomu_1.xu[
		    istart - 1], &xscomu_1.zu[istart - 1], &npnt);
/* SOURCE conduit.for:840 */
/*<       elseif(type(i).eq.'CMPA1')then >*/
	} else if (s_cmp(feq_gen_type_d_ + (feq_gen_i_d_ - 1) * 10, const_cast<char*>("CMPA1"), (ftnlen)10, (
		ftnlen)5) == 0) {
/*           Corrugated metal pipe arch with 1 inch corrugations. */
/* SOURCE conduit.for:843 */
/*<       if(span(i).le.0.0.and.rise(i).le.0.0)then >*/
	    if (span[feq_gen_i_d_ - 1] <= (float)0. && rise[feq_gen_i_d_ - 1] <= (float)0.) {
/* SOURCE conduit.for:844 */
/*<       write(stdout,76) >*/
		feq_gen_io_d__139.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__139);
		e_wsfe();
/* SOURCE conduit.for:845 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE conduit.for:846 */
/*<       return >*/
		return 0;
/* SOURCE conduit.for:847 */
/*<       endif >*/
	    }
/*           COMPUTE THE SEMI-PERIMETER FOR THIS SIZE ARCH PIPE */
/* SOURCE conduit.for:851 */
/*<        >*/
	    rharch_(stdout, &feq_gen_c_d_15, rscm1, spcm1, r1cm1, r3cm1, &cfac, &rise[
		    feq_gen_i_d_ - 1], &span[feq_gen_i_d_ - 1], eflag, &nrh, xt, yt, &yoff);
/* SOURCE conduit.for:856 */
/*<       write(stdout,86)span(i),rise(i) >*/
	    feq_gen_io_d__140.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__140);
	    do_fio(&feq_gen_c_d_1, (char *)&span[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&rise[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE conduit.for:857 */
/*<       maxsof=max(maxsof,rise(i)+zoff) >*/
/* Computing MAX */
	    feq_gen_r_d_1 = maxsof, feq_gen_r_d_2 = static_cast<double>(rise[feq_gen_i_d_ - 1]) + zoff;
	    maxsof = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE conduit.for:859 */
/*<       if(eflag.gt.0)return >*/
	    if (*eflag > 0) {
		return 0;
	    }
/* SOURCE conduit.for:860 */
/*<       yoff=yoff+zoff >*/
	    yoff += zoff;
/* SOURCE conduit.for:861 */
/*<       if(i==1)then >*/
	    if (feq_gen_i_d_ == 1) {
/* SOURCE conduit.for:862 */
/*<       xoff=xoff+0.5*span(i)+0.25 >*/
		xoff = static_cast<double>(static_cast<double>(xoff) + static_cast<double>(span[feq_gen_i_d_ - 1]) * (float).5) + (float).25;
/* SOURCE conduit.for:863 */
/*<       else >*/
	    } else {
/* SOURCE conduit.for:864 */
/*<       xoff=xoff+0.5*(span(i-1)+span(i))+0.25 >*/
		xoff = static_cast<double>(static_cast<double>(xoff) + static_cast<double>((static_cast<double>(span[feq_gen_i_d_ - 2]) + span[feq_gen_i_d_ - 1])) * (float).5) + (
			float).25;
/* SOURCE conduit.for:865 */
/*<       endif >*/
	    }
/* SOURCE conduit.for:866 */
/*<        >*/
	    rhmak_(&wslot, &hslot, &yoff, &xoff, &nrh, xt, yt, &xscomu_1.xu[
		    istart - 1], &xscomu_1.zu[istart - 1], &npnt);
/* SOURCE conduit.for:870 */
/*<       elseif(type(i).eq.'CMPA1B')then >*/
	} else if (s_cmp(feq_gen_type_d_ + (feq_gen_i_d_ - 1) * 10, const_cast<char*>("CMPA1B"), (ftnlen)10, (
		ftnlen)6) == 0) {
/*           Corrugated metal pipe arch with 1 inch corrugations */
/*           before current values were introduced. */
/*           In use in 1967 and 1971. */
/* SOURCE conduit.for:875 */
/*<       if(span(i).le.0.0.and.rise(i).le.0.0)then >*/
	    if (span[feq_gen_i_d_ - 1] <= (float)0. && rise[feq_gen_i_d_ - 1] <= (float)0.) {
/* SOURCE conduit.for:876 */
/*<       write(stdout,76) >*/
		feq_gen_io_d__141.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__141);
		e_wsfe();
/* SOURCE conduit.for:877 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE conduit.for:878 */
/*<       return >*/
		return 0;
/* SOURCE conduit.for:879 */
/*<       endif >*/
	    }
/*           COMPUTE THE SEMI-PERIMETER FOR THIS SIZE ARCH PIPE */
/* SOURCE conduit.for:883 */
/*<        >*/
	    rharch_(stdout, &feq_gen_c_d_15, rscm1b, spcm1b, r1cm1b, r3cm1b, &cfac, &
		    rise[feq_gen_i_d_ - 1], &span[feq_gen_i_d_ - 1], eflag, &nrh, xt, yt, &yoff)
		    ;
/* SOURCE conduit.for:888 */
/*<       write(stdout,86)span(i),rise(i) >*/
	    feq_gen_io_d__142.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__142);
	    do_fio(&feq_gen_c_d_1, (char *)&span[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&rise[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE conduit.for:889 */
/*<       maxsof=max(maxsof,rise(i)+zoff) >*/
/* Computing MAX */
	    feq_gen_r_d_1 = maxsof, feq_gen_r_d_2 = static_cast<double>(rise[feq_gen_i_d_ - 1]) + zoff;
	    maxsof = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE conduit.for:891 */
/*<       if(eflag.gt.0)return >*/
	    if (*eflag > 0) {
		return 0;
	    }
/* SOURCE conduit.for:892 */
/*<       yoff=yoff+zoff >*/
	    yoff += zoff;
/* SOURCE conduit.for:893 */
/*<       if(i==1)then >*/
	    if (feq_gen_i_d_ == 1) {
/* SOURCE conduit.for:894 */
/*<       xoff=xoff+0.5*span(i)+0.25 >*/
		xoff = static_cast<double>(static_cast<double>(xoff) + static_cast<double>(span[feq_gen_i_d_ - 1]) * (float).5) + (float).25;
/* SOURCE conduit.for:895 */
/*<       else >*/
	    } else {
/* SOURCE conduit.for:896 */
/*<       xoff=xoff+0.5*(span(i-1)+span(i))+0.25 >*/
		xoff = static_cast<double>(static_cast<double>(xoff) + static_cast<double>((static_cast<double>(span[feq_gen_i_d_ - 2]) + span[feq_gen_i_d_ - 1])) * (float).5) + (
			float).25;
/* SOURCE conduit.for:897 */
/*<       endif >*/
	    }
/* SOURCE conduit.for:898 */
/*<        >*/
	    rhmak_(&wslot, &hslot, &yoff, &xoff, &nrh, xt, yt, &xscomu_1.xu[
		    istart - 1], &xscomu_1.zu[istart - 1], &npnt);
/* SOURCE conduit.for:902 */
/*<       elseif(type(i).eq.'SPPA18')then >*/
	} else if (s_cmp(feq_gen_type_d_ + (feq_gen_i_d_ - 1) * 10, const_cast<char*>("SPPA18"), (ftnlen)10, (
		ftnlen)6) == 0) {
/*           Structural plate pipe arch with 18 inch corners. */
/*           Has 6 inch by 2 inch corrugations. */
/* SOURCE conduit.for:906 */
/*<       if(span(i).le.0.0.and.rise(i).le.0.0)then >*/
	    if (span[feq_gen_i_d_ - 1] <= (float)0. && rise[feq_gen_i_d_ - 1] <= (float)0.) {
/* SOURCE conduit.for:907 */
/*<       write(stdout,76) >*/
		feq_gen_io_d__143.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__143);
		e_wsfe();
/* SOURCE conduit.for:908 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE conduit.for:909 */
/*<       return >*/
		return 0;
/* SOURCE conduit.for:910 */
/*<       endif >*/
	    }
/*           COMPUTE THE SEMI-PERIMETER FOR THIS SIZE ARCH PIPE */
/* SOURCE conduit.for:914 */
/*<        >*/
	    rharch_(stdout, &feq_gen_c_d_34, rssp18, spsp18, r1sp18, r3sp18, &cfac, &
		    rise[feq_gen_i_d_ - 1], &span[feq_gen_i_d_ - 1], eflag, &nrh, xt, yt, &yoff)
		    ;
/* SOURCE conduit.for:919 */
/*<       write(stdout,86)span(i),rise(i) >*/
	    feq_gen_io_d__144.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__144);
	    do_fio(&feq_gen_c_d_1, (char *)&span[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&rise[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE conduit.for:920 */
/*<       maxsof=max(maxsof,rise(i)+zoff) >*/
/* Computing MAX */
	    feq_gen_r_d_1 = maxsof, feq_gen_r_d_2 = static_cast<double>(rise[feq_gen_i_d_ - 1]) + zoff;
	    maxsof = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE conduit.for:922 */
/*<       if(eflag.gt.0)return >*/
	    if (*eflag > 0) {
		return 0;
	    }
/* SOURCE conduit.for:923 */
/*<       yoff=yoff+zoff >*/
	    yoff += zoff;
/* SOURCE conduit.for:924 */
/*<       if(i==1)then >*/
	    if (feq_gen_i_d_ == 1) {
/* SOURCE conduit.for:925 */
/*<       xoff=xoff+0.5*span(i)+0.25 >*/
		xoff = static_cast<double>(static_cast<double>(xoff) + static_cast<double>(span[feq_gen_i_d_ - 1]) * (float).5) + (float).25;
/* SOURCE conduit.for:926 */
/*<       else >*/
	    } else {
/* SOURCE conduit.for:927 */
/*<       xoff=xoff+0.5*(span(i-1)+span(i))+0.25 >*/
		xoff = static_cast<double>(static_cast<double>(xoff) + static_cast<double>((static_cast<double>(span[feq_gen_i_d_ - 2]) + span[feq_gen_i_d_ - 1])) * (float).5) + (
			float).25;
/* SOURCE conduit.for:928 */
/*<       endif >*/
	    }
/* SOURCE conduit.for:929 */
/*<        >*/
	    rhmak_(&wslot, &hslot, &yoff, &xoff, &nrh, xt, yt, &xscomu_1.xu[
		    istart - 1], &xscomu_1.zu[istart - 1], &npnt);
/* SOURCE conduit.for:933 */
/*<       elseif(type(i).eq.'SPPA31')then >*/
	} else if (s_cmp(feq_gen_type_d_ + (feq_gen_i_d_ - 1) * 10, const_cast<char*>("SPPA31"), (ftnlen)10, (
		ftnlen)6) == 0) {
/*           Structural plate pipe arch with 31 inch corners. */
/*           Has 6 inch by 2 inch corrugations. */
/* SOURCE conduit.for:937 */
/*<       if(span(i).le.0.0.and.rise(i).le.0.0)then >*/
	    if (span[feq_gen_i_d_ - 1] <= (float)0. && rise[feq_gen_i_d_ - 1] <= (float)0.) {
/* SOURCE conduit.for:938 */
/*<       write(stdout,76) >*/
		feq_gen_io_d__145.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__145);
		e_wsfe();
/* SOURCE conduit.for:939 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE conduit.for:940 */
/*<       return >*/
		return 0;
/* SOURCE conduit.for:941 */
/*<       endif >*/
	    }
/*           COMPUTE THE SEMI-PERIMETER FOR THIS SIZE ARCH PIPE */
/* SOURCE conduit.for:945 */
/*<        >*/
	    rharch_(stdout, &feq_gen_c_d_24, rssp31, spsp31, r1sp31, r3sp31, &cfac, &
		    rise[feq_gen_i_d_ - 1], &span[feq_gen_i_d_ - 1], eflag, &nrh, xt, yt, &yoff)
		    ;
/* SOURCE conduit.for:950 */
/*<       write(stdout,86)span(i),rise(i) >*/
	    feq_gen_io_d__146.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__146);
	    do_fio(&feq_gen_c_d_1, (char *)&span[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&rise[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE conduit.for:951 */
/*<       maxsof=max(maxsof,rise(i)+zoff) >*/
/* Computing MAX */
	    feq_gen_r_d_1 = maxsof, feq_gen_r_d_2 = static_cast<double>(rise[feq_gen_i_d_ - 1]) + zoff;
	    maxsof = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE conduit.for:953 */
/*<       if(eflag.gt.0)return >*/
	    if (*eflag > 0) {
		return 0;
	    }
/* SOURCE conduit.for:954 */
/*<       yoff=yoff+zoff >*/
	    yoff += zoff;
/* SOURCE conduit.for:955 */
/*<       if(i==1)then >*/
	    if (feq_gen_i_d_ == 1) {
/* SOURCE conduit.for:956 */
/*<       xoff=xoff+0.5*span(i)+0.25 >*/
		xoff = static_cast<double>(static_cast<double>(xoff) + static_cast<double>(span[feq_gen_i_d_ - 1]) * (float).5) + (float).25;
/* SOURCE conduit.for:957 */
/*<       else >*/
	    } else {
/* SOURCE conduit.for:958 */
/*<       xoff=xoff+0.5*(span(i-1)+span(i))+0.25 >*/
		xoff = static_cast<double>(static_cast<double>(xoff) + static_cast<double>((static_cast<double>(span[feq_gen_i_d_ - 2]) + span[feq_gen_i_d_ - 1])) * (float).5) + (
			float).25;
/* SOURCE conduit.for:959 */
/*<       endif >*/
	    }
/* SOURCE conduit.for:960 */
/*<        >*/
	    rhmak_(&wslot, &hslot, &yoff, &xoff, &nrh, xt, yt, &xscomu_1.xu[
		    istart - 1], &xscomu_1.zu[istart - 1], &npnt);
/* SOURCE conduit.for:964 */
/*<       elseif(type(i).eq.'TE')then >*/
	} else if (s_cmp(feq_gen_type_d_ + (feq_gen_i_d_ - 1) * 10, const_cast<char*>("TE"), (ftnlen)10, (ftnlen)2)
		 == 0) {
/* SOURCE conduit.for:966 */
/*<       if(span(i).le.0.0.or.rise(i).le.0.0)then >*/
	    if (span[feq_gen_i_d_ - 1] <= (float)0. || rise[feq_gen_i_d_ - 1] <= (float)0.) {
/* SOURCE conduit.for:967 */
/*<       write(stdout,84) >*/
		feq_gen_io_d__147.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__147);
		e_wsfe();
/* SOURCE conduit.for:968 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE conduit.for:969 */
/*<       return >*/
		return 0;
/* SOURCE conduit.for:970 */
/*<       endif >*/
	    }
/* SOURCE conduit.for:972 */
/*<       write(stdout,86)span(i),rise(i) >*/
	    feq_gen_io_d__148.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__148);
	    do_fio(&feq_gen_c_d_1, (char *)&span[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&rise[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE conduit.for:973 */
/*<       maxsof=max(maxsof,rise(i)+zoff) >*/
/* Computing MAX */
	    feq_gen_r_d_1 = maxsof, feq_gen_r_d_2 = static_cast<double>(rise[feq_gen_i_d_ - 1]) + zoff;
	    maxsof = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE conduit.for:975 */
/*<       callurqte(rise(i),span(i),nurq,xt,yt) >*/
	    urqte_(&rise[feq_gen_i_d_ - 1], &span[feq_gen_i_d_ - 1], &nurq, xt, yt);
/* SOURCE conduit.for:979 */
/*<       yoff=zoff+rise(i)/2.0 >*/
	    yoff = static_cast<double>(zoff) + static_cast<double>(rise[feq_gen_i_d_ - 1]) / (float)2.;
/* SOURCE conduit.for:980 */
/*<       if(i==1)then >*/
	    if (feq_gen_i_d_ == 1) {
/* SOURCE conduit.for:981 */
/*<       xoff=xoff+0.5*span(i)+0.25 >*/
		xoff = static_cast<double>(static_cast<double>(xoff) + static_cast<double>(span[feq_gen_i_d_ - 1]) * (float).5) + (float).25;
/* SOURCE conduit.for:982 */
/*<       else >*/
	    } else {
/* SOURCE conduit.for:983 */
/*<       xoff=xoff+0.5*(span(i-1)+span(i))+0.25 >*/
		xoff = static_cast<double>(static_cast<double>(xoff) + static_cast<double>((static_cast<double>(span[feq_gen_i_d_ - 2]) + span[feq_gen_i_d_ - 1])) * (float).5) + (
			float).25;
/* SOURCE conduit.for:984 */
/*<       endif >*/
	    }
/* SOURCE conduit.for:985 */
/*<        >*/
	    urqmak_(&wslot, &hslot, &yoff, &xoff, &nurq, xt, yt, &xscomu_1.xu[
		    istart - 1], &xscomu_1.zu[istart - 1], &npnt);
/* SOURCE conduit.for:990 */
/*<       elseif(type(i).eq.'BOX')then >*/
	} else if (s_cmp(feq_gen_type_d_ + (feq_gen_i_d_ - 1) * 10, const_cast<char*>("BOX"), (ftnlen)10, (ftnlen)
		3) == 0) {
/* SOURCE conduit.for:992 */
/*<       if(span(i).le.0.0.or.rise(i).le.0.0)then >*/
	    if (span[feq_gen_i_d_ - 1] <= (float)0. || rise[feq_gen_i_d_ - 1] <= (float)0.) {
/* SOURCE conduit.for:993 */
/*<       write(stdout,94)span(i),rise(i) >*/
		feq_gen_io_d__149.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__149);
		do_fio(&feq_gen_c_d_1, (char *)&span[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&rise[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE conduit.for:994 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE conduit.for:995 */
/*<       return >*/
		return 0;
/* SOURCE conduit.for:996 */
/*<       endif >*/
	    }
/* SOURCE conduit.for:998 */
/*<       write(stdout,86)span(i),rise(i) >*/
	    feq_gen_io_d__150.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__150);
	    do_fio(&feq_gen_c_d_1, (char *)&span[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&rise[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE conduit.for:999 */
/*<       maxsof=max(maxsof,rise(i)+zoff) >*/
/* Computing MAX */
	    feq_gen_r_d_1 = maxsof, feq_gen_r_d_2 = static_cast<double>(rise[feq_gen_i_d_ - 1]) + zoff;
	    maxsof = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE conduit.for:1001 */
/*<       if(i==1)then >*/
	    if (feq_gen_i_d_ == 1) {
/* SOURCE conduit.for:1002 */
/*<       xoff=xoff+0.5*span(i)+0.25 >*/
		xoff = static_cast<double>(static_cast<double>(xoff) + static_cast<double>(span[feq_gen_i_d_ - 1]) * (float).5) + (float).25;
/* SOURCE conduit.for:1003 */
/*<       else >*/
	    } else {
/* SOURCE conduit.for:1004 */
/*<       xoff=xoff+0.5*(span(i-1)+span(i))+0.25 >*/
		xoff = static_cast<double>(static_cast<double>(xoff) + static_cast<double>((static_cast<double>(span[feq_gen_i_d_ - 2]) + span[feq_gen_i_d_ - 1])) * (float).5) + (
			float).25;
/* SOURCE conduit.for:1005 */
/*<       endif >*/
	    }
/* SOURCE conduit.for:1006 */
/*<        >*/
	    mkbox_(&xoff, &zoff, &span[feq_gen_i_d_ - 1], &rise[feq_gen_i_d_ - 1], &wslot, &
		    hslot, &npnt, &xscomu_1.xu[istart - 1], &xscomu_1.zu[
		    istart - 1]);
/* SOURCE conduit.for:1011 */
/*<       else >*/
	} else {
/* SOURCE conduit.for:1012 */
/*<       write(stdout,82)type(i) >*/
	    feq_gen_io_d__151.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__151);
	    do_fio(&feq_gen_c_d_1, feq_gen_type_d_ + (feq_gen_i_d_ - 1) * 10, (ftnlen)10);
	    e_wsfe();
/* SOURCE conduit.for:1013 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE conduit.for:1014 */
/*<       return >*/
	    return 0;
/* SOURCE conduit.for:1015 */
/*<       endif >*/
	}
/*         COMPLETE PROCESSING: SET THE SUBSECTION NUMBER, THE LINE */
/*         SEGMENT ROUGHNESS, AND THE MUDLINE IF ANY. */
/* SOURCE conduit.for:1020 */
/*<       callsetsub(i,npnt,istart,rough(i),sbu,lsnu) >*/
	setsub_(&feq_gen_i_d_, &npnt, &istart, &rough[feq_gen_i_d_ - 1], xscomu_1.sbu, 
		xscomu_1.lsnu);
/*          write(stdout,91) i, type(i), npnt, istart, rough(i) */
/* 91    format(' i=',i5,' type=',a8,' npnt=',i5,' istart=',i5, */
/*     a        ' rough(i)=',f10.4) */
/*          do j=istart,istart+npnt-1 */
/*            write(stdout,89) j, xu(j), zu(j), lsnu(j) */
/* 89    format(i5,f10.4,f10.4,f10.3) */
/*          enddo */
/* SOURCE conduit.for:1031 */
/*<       if(zmud(i).gt.0.0)then >*/
	if (zmud[feq_gen_i_d_ - 1] > (float)0.) {
/*           ADJUST THE CROSS SECTION FOR A MUD LINE */
/* SOURCE conduit.for:1033 */
/*<       zmud2=zmud(i)+zoff >*/
	    zmud2 = static_cast<double>(zmud[feq_gen_i_d_ - 1]) + zoff;
/* SOURCE conduit.for:1034 */
/*<        >*/
	    setmud_(stdout, &istart, &feq_gen_c_d_999, &nmud[feq_gen_i_d_ - 1], &rough[feq_gen_i_d_ - 1],
		     &zmud2, &zeps, &npnt, xscomu_1.xu, xscomu_1.zu, 
		    xscomu_1.lsnu, xscomu_1.sbu, eflag);
/* SOURCE conduit.for:1038 */
/*<       if(eflag.ne.0)return >*/
	    if (*eflag != 0) {
		return 0;
	    }
/* SOURCE conduit.for:1039 */
/*<       endif >*/
	}
/* SOURCE conduit.for:1041 */
/*<       istart=istart+npnt >*/
	istart += npnt;
/* SOURCE conduit.for:1042 */
/*<       npntu=npntu+npnt >*/
	xscomu_1.npntu += npnt;
/*          IF(I.NE.NPIPES) THEN */
/*            write(stdout,8232) i, span(i), span(i+1) */
/* 8232  format('i=',i5,' span(i)=',f10.4,' span(i+1)=',f10.4) */
/*            XOFF = XOFF + MAX(SPAN(I), SPAN(I+1)) + 1.0 */
/*          ENDIF */
/* SOURCE conduit.for:1048 */
/*<   500 continue >*/
/* L500: */
    }
/* SOURCE conduit.for:1050 */
/*<       if(maxsof.gt.hslot)then >*/
    if (maxsof > hslot) {
/*       PROBLEMS.  INCREASE HSLOT AND DO AGAIN. */
/* SOURCE conduit.for:1052 */
/*<       write(stdout,97)hslot,maxsof,maxsof+5.0 >*/
	feq_gen_io_d__153.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__153);
	do_fio(&feq_gen_c_d_1, (char *)&hslot, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&maxsof, (ftnlen)sizeof(real));
	feq_gen_r_d_1 = static_cast<double>(maxsof) + (float)5.;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE conduit.for:1053 */
/*<       hslot=maxsof+5.0 >*/
	hslot = static_cast<double>(maxsof) + (float)5.;
/* SOURCE conduit.for:1054 */
/*<       goto9000 >*/
	goto L9000;
/* SOURCE conduit.for:1055 */
/*<       endif >*/
    }
/*     Set sinuosity to 1.0 everywhere */
/* SOURCE conduit.for:1058 */
/*<       doi=1,npntu >*/
    feq_gen_i_d_1 = xscomu_1.npntu;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE conduit.for:1059 */
/*<       snu(i)=1.0 >*/
	xscomu_1.snu[feq_gen_i_d_ - 1] = (float)1.;
/* SOURCE conduit.for:1060 */
/*<       enddo >*/
    }
/*      WRITE(STDOUT,*) ' ' */
/*      WRITE(STDOUT,*) ' DUMP OF CROSS-SECTION BOUNDARY' */
/*      WRITE(STDOUT,*) ' NPNTU=',npntu */
/*      DO 1000 I=1,NPNTU */
/*        WRITE(STDOUT,90) XU(I), ZU(I), SBU(I), LSNU(I) */
/* 90    FORMAT(F10.4,F10.3,I5,F10.3) */
/* 1000  CONTINUE */
/* SOURCE conduit.for:1070 */
/*<       navmu=0 >*/
    xscomu_1.navmu = 0;
/* SOURCE conduit.for:1071 */
/*<       nsubu=npipes >*/
    xscomu_1.nsubu = npipes;
/* SOURCE conduit.for:1072 */
/*<       do600i=1,npipes >*/
    feq_gen_i_d_1 = npipes;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE conduit.for:1073 */
/*<       nu(i)=rough(i) >*/
	xscomu_1.nu[feq_gen_i_d_ - 1] = rough[feq_gen_i_d_ - 1];
/* SOURCE conduit.for:1074 */
/*<   600 continue >*/
/* L600: */
    }
/* SOURCE conduit.for:1075 */
/*<       left=1.0 >*/
    left = (float)1.;
/* SOURCE conduit.for:1076 */
/*<       right=0.0 >*/
    right = (float)0.;
/* SOURCE conduit.for:1077 */
/*<       statu=0.0 >*/
    xscomu_1.statu = (float)0.;
/*     COMPUTE ELEMENTS FOR CURRENT CROSS SECTION */
/* SOURCE conduit.for:1081 */
/*<       if(npntu.gt.1)then >*/
    if (xscomu_1.npntu > 1) {
/*       FIND THE MAXIMUM AND MINIMUM ARGUMENT VALUES */
/* SOURCE conduit.for:1083 */
/*<       zminu=9999999. >*/
	xscomu_1.zminu = (float)9999999.;
/* SOURCE conduit.for:1084 */
/*<       zmaxu=-9999999. >*/
	xscomu_1.zmaxu = (float)-9999999.;
/* SOURCE conduit.for:1085 */
/*<       do150j=1,npntu >*/
	feq_gen_i_d_1 = xscomu_1.npntu;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE conduit.for:1086 */
/*<       if(zu(j).gt.zmaxu)zmaxu=zu(j) >*/
	    if (xscomu_1.zu[j - 1] > xscomu_1.zmaxu) {
		xscomu_1.zmaxu = xscomu_1.zu[j - 1];
	    }
/* SOURCE conduit.for:1087 */
/*<       if(zu(j).lt.zminu)zminu=zu(j) >*/
	    if (xscomu_1.zu[j - 1] < xscomu_1.zminu) {
		xscomu_1.zminu = xscomu_1.zu[j - 1];
	    }
/* SOURCE conduit.for:1088 */
/*<   150 continue >*/
/* L150: */
	}
/* SOURCE conduit.for:1090 */
/*<        >*/
	cxstab_(stdout, &xscomu_1.nsubu, &xscomu_1.navmu, nfac, &
		xscomu_1.mxpntu, &left, &right, betopt, &xscomu_1.snflgu, 
		xscomu_1.nvaru, xscomu_1.natyu, xscomu_1.yatnu, xscomu_1.nnyu,
		 &xscomu_1.npntu, &xscomu_1.zminu, &xscomu_1.zmaxu, 
		xscomu_1.xu, xscomu_1.zu, xscomu_1.sbu, eflag, xscomu_1.lsnu, 
		xscomu_1.snu, xscomu_1.nu, &xscomu_1.ndepu, xscomu_1.xstu, (
		ftnlen)8);
/* SOURCE conduit.for:1095 */
/*<       endif >*/
    }
/*     FORCE THE CONVEYANCE TO BE MONOTONE INCREASING. */
/*     limiting the maximum conveyance to the full-flow conveyance. */
/*     The flow near the crown of the opening is of an uncertain */
/*     character in most cases. */
/* SOURCE conduit.for:1101 */
/*<       if(nocm.eq.1)then >*/
    if (nrdzcm_1.nocm == 1) {
/*       Find start of the slot. */
/* SOURCE conduit.for:1103 */
/*<       do168j=ndepu-2,2,-1 >*/
	for (j = xscomu_1.ndepu - 2; j >= 2; --j) {
/* SOURCE conduit.for:1104 */
/*<       if(xstu(j-1,2).gt.xstu(j,2))then >*/
	    if (xscomu_1.xstu[j + 997] > xscomu_1.xstu[j + 998]) {
/*           J is the entrance to the top slot */
/* SOURCE conduit.for:1106 */
/*<       goto169 >*/
		goto L169;
/* SOURCE conduit.for:1107 */
/*<       endif >*/
	    }
/* SOURCE conduit.for:1108 */
/*<   168 continue >*/
/* L168: */
	}
/* SOURCE conduit.for:1109 */
/*<   169 continue >*/
L169:
/* SOURCE conduit.for:1110 */
/*<       maxk=xstu(j,5) >*/
	maxk = xscomu_1.xstu[j + 3995];
/* SOURCE conduit.for:1111 */
/*<       do170j=2,ndepu >*/
	feq_gen_i_d_1 = xscomu_1.ndepu;
	for (j = 2; j <= feq_gen_i_d_1; ++j) {
/* SOURCE conduit.for:1112 */
/*<       if(xstu(j-1,5).gt.maxk)then >*/
	    if (xscomu_1.xstu[j + 3994] > maxk) {
/* SOURCE conduit.for:1113 */
/*<       xstu(j-1,5)=maxk >*/
		xscomu_1.xstu[j + 3994] = maxk;
/* SOURCE conduit.for:1114 */
/*<       endif >*/
	    }
/* SOURCE conduit.for:1115 */
/*<   170 continue >*/
/* L170: */
	}
/* SOURCE conduit.for:1116 */
/*<       endif >*/
    }
/*     OUTPUT THE TABLE IF NO ERRORS AND IF OUTPUT IS REQUESTED */
/* SOURCE conduit.for:1120 */
/*<       if(eflag.ne.0.or.tabu.eq.0)goto200 >*/
    if (*eflag != 0 || xscomu_1.tabu == 0) {
	goto L200;
    }
/*        IF(ABS(ZMINU).LT.0.001) ZMINU = 0.0 */
/*       REMOVE THE TOP VALUE TO ELIMINATE THE */
/*       ERRATIC TOP WIDTH. */
/* SOURCE conduit.for:1125 */
/*<       ndepu=ndepu-1 >*/
    --xscomu_1.ndepu;
/*       FORCE ALPHA AND BETA TO BE 1.00 TO REDUCE PROBLEMS WITH */
/*       CRITICAL DEPTH.  ALPHA AND BETA ARE CLOSE TO 1.00 IN ANY */
/*       CASE. */
/* SOURCE conduit.for:1131 */
/*<       do190j=1,ndepu >*/
    feq_gen_i_d_1 = xscomu_1.ndepu;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE conduit.for:1132 */
/*<       xstu(j,6)=1.0 >*/
	xscomu_1.xstu[j + 4994] = (float)1.;
/* SOURCE conduit.for:1133 */
/*<       xstu(j,7)=1.0 >*/
	xscomu_1.xstu[j + 5993] = (float)1.;
/* SOURCE conduit.for:1134 */
/*<   190 continue >*/
/* L190: */
    }
/*     compute derivatives of square root of conveyance, alpha, beta, */
/*     da, and dq */
/* SOURCE conduit.for:1139 */
/*<        >*/
    xsecfit_(stdout, &feq_gen_c_d_0, &xscomu_1.ndepu, xscomu_1.xstu, khflag, alphaflag,
	     betaflag, maflag, mqflag, (ftnlen)1, (ftnlen)1, (ftnlen)1, (
	    ftnlen)1, (ftnlen)1);
/* SOURCE conduit.for:1144 */
/*<        >*/
    tabout_(stdout, stdtab, &xscomu_1.tabu, &xscomu_1.statu, &xscomu_1.zminu, 
	    &feq_gen_c_d_0, savopt, outopt, betopt, zone, hgrid, vdatum, unitsys, 
	    basis, khflag, alphaflag, betaflag, maflag, mqflag, &
	    xscomu_1.ndepu, xscomu_1.xstu, ftp, (ftnlen)8, (ftnlen)8, (ftnlen)
	    8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)
	    1, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
/* SOURCE conduit.for:1149 */
/*<   200 continue >*/
L200:
/* SOURCE conduit.for:1150 */
/*<       return >*/
    return 0;
/* SOURCE conduit.for:1151 */
/*<   991 continue >*/
L991:
/* SOURCE conduit.for:1152 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__162.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__162);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE conduit.for:1153 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__163.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__163);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE conduit.for:1154 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE conduit.for:1155 */
/*<       end >*/
    return 0;
} /* mulcon_ */




/* SOURCE conduit.for:1159 */
/*<       subroutinepipes(stdin,stdout,stdtab,nfac,tabdir,eflag,ftp) >*/
/* Subroutine */ int pipes_(integer *stdin, integer *stdout, integer *stdtab, 
	real *nfac, integer *feq_storage_tabdir, integer *eflag, integer *ftp)
{
    /* Format strings */
    static char fmt_4[] = "(7x,i5)";
    static char fmt_6[] = "(6x,f10.0)";
    static char fmt_7[] = "(7x,i5,a10)";
    static char fmt_8[] = "(5x,6f10.0)";
    static char fmt_9[] = "(5x,6f10.0)";
    static char fmt_10[] = "(5x,6f10.0)";
    static char fmt_12[] = "(5x,6f10.0)";
    static char fmt_14[] = "(5x,6f10.0)";
    static char fmt_50[] = "(/,\002 TABID= \002,a,2x,a)";
    static char fmt_54[] = "(\002 POLYGON APPROX HAS \002,i3,\002 SIDES\002)";
    static char fmt_56[] = "(\002 WIDTH OF SLOT=\002,f7.3)";
    static char fmt_57[] = "(\002 NUMBER OF PIPES=\002,i5,\002 MUD LINE EPS\
=\002,f7.3)";
    static char fmt_58[] = "(\002 HEIGHT OF SLOT ABOVE DATUM=\002,f7.0)";
    static char fmt_62[] = "(\0020*WRN:513* NUMBER OF SIDES=\002,i3,\002 TOO\
 SMALL.\002,\002 NSIDES RESET TO 10\002)";
    static char fmt_64[] = "(\0020*WRN:514* NUMBER OF SIDES=\002,i4,\002 TOO\
 LARGE.\002,\002 NSIDES RESET TO\002,i5)";
    static char fmt_66[] = "(\0020*ERR:528* NUMBER OF PIPES=\002,i5,\002 >\
 \002,i5)";
    static char fmt_70[] = "(\002 DIAMETERS=\002,6f7.2)";
    static char fmt_72[] = "(\002 BOTTOMS=  \002,6f7.2)";
    static char fmt_74[] = "(\002 ROUGNESS= \002,6f7.3)";
    static char fmt_76[] = "(\002 MUD LEVEL=\002,6f7.2)";
    static char fmt_78[] = "(\002 MUD ROUGH=\002,6f7.3)";
    static char fmt_92[] = "(\0020*WRN:549* BETA OPTION MUST BE \"OLDBETA\".\
  THE OPTION\002,\002 HAS BEEN RESET TO \"OLDBETA\".\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3;
    real feq_gen_r_d_1, feq_gen_r_d_2;
    icilist feq_gen_ici_d_1;
    alist feq_gen_al_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_cmp(char *, char *, ftnlen, ftnlen), s_rsfi(icilist *), e_rsfi()
	    , f_back(alist *), s_wsle(cilist *), do_lio(integer *, integer *, 
	    char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    char betaflag[1*999];
    integer feq_gen_i_d_, j;
    char alphaflag[1*999];
    integer je, it, js, tab;
    char cin[64];
    real diam[200];
    char line[80];
    real left, maxk, xoff, nmud[200], zoff;
    char zone[8];
    integer npnt;
    real zmud[200], zeps, zmud2;
    char hgrid[8], basis[8];
    integer itend;
    real right, hslot, rough[200];
    char czeps[10];
    real wslot;
    char maflag[1*999], khflag[1*999];
    extern /* Subroutine */ int tabchk_(integer *, integer *, integer *, 
	    integer *, integer *);
    char mqflag[1*999];
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen);
    integer nsides;
    extern /* Subroutine */ int cxstab_(integer *, integer *, integer *, real 
	    *, integer *, real *, real *, char *, integer *, integer *, real *
	    , real *, integer *, integer *, real *, real *, real *, real *, 
	    integer *, integer *, real *, real *, real *, integer *, real *, 
	    ftnlen);
    integer istart, npipes;
    real bottom[200], maxsof;
    char betopt[8], monton[8], outopt[8], savopt[8], vdatum[8];
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int mkpipe_(real *, real *, integer *, real *, 
	    real *, real *, integer *, real *, real *), setmud_(integer *, 
	    integer *, integer *, real *, real *, real *, real *, integer *, 
	    real *, real *, real *, integer *, integer *), setopt_(integer *, 
	    char *, char *, char *, char *, char *, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen), tabout_(integer *, integer *, integer *, real *, 
	    real *, integer *, char *, char *, char *, char *, char *, char *,
	     char *, char *, char *, char *, char *, char *, char *, integer *
	    , real *, integer *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen), 
	    feq_gen_get_lctn_items_d_(integer *, integer *, integer *), 
	    feq_gen_set_lctn_items_d_(char *, char *, char *, char *, char *, 
	    doublereal *, doublereal *, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen), inlineb_(integer *, integer *, char *, ftnlen), xsecfit_(
	    integer *, integer *, integer *, real *, char *, char *, char *, 
	    char *, char *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen), 
	    feq_gen_read_tabid_plus_d_(integer *, char *, integer *, char *, integer *,
	     char *, ftnlen, ftnlen, ftnlen);
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__167 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__172 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__179 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__181 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__183 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__187 = { 0, 0, 0, fmt_57, 0 };
    static cilist feq_gen_io_d__188 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__195 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__197 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__199 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__202 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__203 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__204 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__205 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__221 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__222 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Compute a cross section for several pipes */
/*     not all of the same diameter nor at the same invert */
/*     elevation. Each pipe will have its own slot. */
/* SOURCE conduit.for:1167 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE conduit.for:1169 */
/*<       integereflag,ftp,stdin,stdout,stdtab >*/
/* SOURCE conduit.for:1170 */
/*<       integertabdir(*) >*/
/* SOURCE conduit.for:1171 */
/*<       realnfac >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     NFAC   - Factor in Manning's formula(1.49 or 1.0) */
/*     TABDIR - Table directory to remember table numbers */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     FTP    - next open location in the function table storage */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE conduit.for:1183 */
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
/* INCLUDE conduit.for:1184 */
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
/* INCLUDE conduit.for:1185 */
/*     NEAR ZERO DEPTH AND DZ COMMON.  ALSO HAS OTHER ITEMS */
/* SOURCE nrdzcm.cmn:3 */
/*<       integerextend,gxtend,nocm,iusgs >*/
/* SOURCE nrdzcm.cmn:5 */
/*<       realnrzero,dzlim,slot >*/
/* SOURCE nrdzcm.cmn:7 */
/*<       common/nrdzcm/nrzero,dzlim,nocm,slot,iusgs,extend,gxtend >*/
/* INCLUDE conduit.for:1186 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE conduit.for:1187 */
/*     Values added to cross section tables: July 1997 */
/*     December 1999, June 2003 */
/* SOURCE xtadd.cmn:4 */
/*<       integerws_tab >*/
/* SOURCE xtadd.cmn:5 */
/*<       realslot_depth,dinvert >*/
/* SOURCE xtadd.cmn:6 */
/*<       real*8easting,northing >*/
/* SOURCE xtadd.cmn:8 */
/*<       character*16gisid,tabid,ws_tabid >*/
/* SOURCE xtadd.cmn:10 */
/*<       common/xtadd/easting,northing,slot_depth,dinvert,ws_tab >*/
/* SOURCE xtadd.cmn:11 */
/*<       common/xtaddc/gisid,tabid,ws_tabid >*/
/* SOURCE xtadd.cmn:13 */
/*<       save/xtadd/,/xtaddc/ >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE conduit.for:1190 */
/*<       integeri,istart,it,itend,j,je,js,npipes,npnt,nsides,tab >*/
/* SOURCE conduit.for:1192 */
/*<        >*/
/* SOURCE conduit.for:1195 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE conduit.for:1204 */
/*<       intrinsicabs,max,min >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE conduit.for:1207 */
/*<       integerlenstr >*/
/* SOURCE conduit.for:1208 */
/*<        >*/
/*     + + + INPUT FORMATS + + + */
/* SOURCE conduit.for:1212 */
/*<     1 format(7x,i5,a) >*/
/* SOURCE conduit.for:1213 */
/*<     4 format(7x,i5) >*/
/* SOURCE conduit.for:1214 */
/*<     6 format(6x,f10.0) >*/
/* SOURCE conduit.for:1215 */
/*<     7 format(7x,i5,a10) >*/
/* SOURCE conduit.for:1216 */
/*<     8 format(5x,6f10.0) >*/
/* SOURCE conduit.for:1217 */
/*<     9 format(5x,6f10.0) >*/
/* SOURCE conduit.for:1218 */
/*<    10 format(5x,6f10.0) >*/
/* SOURCE conduit.for:1219 */
/*<    12 format(5x,6f10.0) >*/
/* SOURCE conduit.for:1220 */
/*<    14 format(5x,6f10.0) >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE conduit.for:1223 */
/*<    50 format(/,' TABID= ',a,2x,a) >*/
/* SOURCE conduit.for:1224 */
/*<    54 format(' POLYGON APPROX HAS ',i3,' SIDES') >*/
/* SOURCE conduit.for:1225 */
/*<    56 format(' WIDTH OF SLOT=',f7.3) >*/
/* SOURCE conduit.for:1226 */
/*<    57 format(' NUMBER OF PIPES=',i5,' MUD LINE EPS=',f7.3) >*/
/* SOURCE conduit.for:1227 */
/*<    58 format(' HEIGHT OF SLOT ABOVE DATUM=',f7.0) >*/
/* SOURCE conduit.for:1228 */
/*<    62  >*/
/* SOURCE conduit.for:1230 */
/*<    64  >*/
/* SOURCE conduit.for:1232 */
/*<    66 format('0*ERR:528* NUMBER OF PIPES=',i5,' > ',i5) >*/
/* SOURCE conduit.for:1233 */
/*<    70 format(' DIAMETERS=',6f7.2) >*/
/* SOURCE conduit.for:1234 */
/*<    72 format(' BOTTOMS=  ',6f7.2) >*/
/* SOURCE conduit.for:1235 */
/*<    74 format(' ROUGNESS= ',6f7.3) >*/
/* SOURCE conduit.for:1236 */
/*<    76 format(' MUD LEVEL=',6f7.2) >*/
/* SOURCE conduit.for:1237 */
/*<    78 format(' MUD ROUGH=',6f7.3) >*/
/* SOURCE conduit.for:1238 */
/*<    92  >*/
/* *********************************************************************** */
/*     26 October 2006, ddf: Set the gisid to blank.  Uninitialized otherwise! */
/* SOURCE conduit.for:1242 */
/*<       gisid=' ' >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> tabdir(feq_storage_tabdir, 1);

    /* Function Body */
/* L1: */
/* L4: */
/* L6: */
/* L7: */
/* L8: */
/* L9: */
/* L10: */
/* L12: */
/* L14: */
/* L50: */
/* L54: */
/* L56: */
/* L57: */
/* L58: */
/* L62: */
/* L64: */
/* L66: */
/* L70: */
/* L72: */
/* L74: */
/* L76: */
/* L78: */
/* L92: */
    s_copy(xtaddc_1.gisid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/*     ALLOW AUTOMATIC EXTENSION */
/* SOURCE conduit.for:1244 */
/*<       extend=1 >*/
    nrdzcm_1.extend = 1;
/* SOURCE conduit.for:1246 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:1249 */
/*<       callread_tabid_plus(stdout,line,eflag,tabid,tab,cin) >*/
    feq_gen_read_tabid_plus_d_(stdout, line, eflag, xtaddc_1.tabid, &tab, cin, (ftnlen)
	    80, (ftnlen)16, (ftnlen)64);
/* SOURCE conduit.for:1252 */
/*<       write(stdout,50)tabid(1:lenstr(tabid)),cin >*/
    feq_gen_io_d__167.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__167);
    do_fio(&feq_gen_c_d_1, xtaddc_1.tabid, lenstr_(xtaddc_1.tabid, (ftnlen)16));
    do_fio(&feq_gen_c_d_1, cin, (ftnlen)64);
    e_wsfe();
/* SOURCE conduit.for:1253 */
/*<       callsetopt(stdout,cin,savopt,outopt,monton,betopt) >*/
    setopt_(stdout, cin, savopt, outopt, monton, betopt, (ftnlen)64, (ftnlen)
	    8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE conduit.for:1256 */
/*<       if(betopt.ne.'OLDBETA')then >*/
    if (s_cmp(betopt, const_cast<char*>("OLDBETA"), (ftnlen)8, (ftnlen)7) != 0) {
/* SOURCE conduit.for:1257 */
/*<       write(stdout,92) >*/
	feq_gen_io_d__172.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__172);
	e_wsfe();
/* SOURCE conduit.for:1258 */
/*<       betopt='OLDBETA' >*/
	s_copy(betopt, const_cast<char*>("OLDBETA"), (ftnlen)8, (ftnlen)7);
/* SOURCE conduit.for:1259 */
/*<       endif >*/
    }
/* SOURCE conduit.for:1262 */
/*<       if(tab.lt.0)then >*/
    if (tab < 0) {
/* SOURCE conduit.for:1263 */
/*<       tab=-tab >*/
	tab = -tab;
/* SOURCE conduit.for:1264 */
/*<       nocm=0 >*/
	nrdzcm_1.nocm = 0;
/* SOURCE conduit.for:1265 */
/*<       else >*/
    } else {
/* SOURCE conduit.for:1266 */
/*<       nocm=1 >*/
	nrdzcm_1.nocm = 1;
/* SOURCE conduit.for:1267 */
/*<       endif >*/
    }
/* SOURCE conduit.for:1269 */
/*<       if(tab.ge.0)calltabchk(stdout,pmxtab,tab,tabdir,eflag) >*/
    if (tab >= 0) {
	tabchk_(stdout, &feq_gen_c_d_10002, &tab, &tabdir[1], eflag);
    }
/* SOURCE conduit.for:1273 */
/*<       tabu=tab >*/
    xscomu_1.tabu = tab;
/*     Get location items that may be present. If they are not present */
/*     they will be set to default values.  The default requests FEQUTL */
/*     to omit the items. */
/* SOURCE conduit.for:1278 */
/*<       callget_lctn_items(stdin,stdout,eflag) >*/
    feq_gen_get_lctn_items_d_(stdin, stdout, eflag);
/* SOURCE conduit.for:1280 */
/*<        >*/
    feq_gen_set_lctn_items_d_(zone, hgrid, vdatum, unitsys, basis, &xtadd_1.easting, &
	    xtadd_1.northing, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (
	    ftnlen)8);
/* SOURCE conduit.for:1285 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:1288 */
/*<       read(line,4,err=991)nsides >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_4;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&nsides, (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE conduit.for:1289 */
/*<       write(stdout,54)nsides >*/
    feq_gen_io_d__179.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__179);
    do_fio(&feq_gen_c_d_1, (char *)&nsides, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE conduit.for:1291 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:1294 */
/*<       read(line,6,err=991)wslot >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_6;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&wslot, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE conduit.for:1295 */
/*<       write(stdout,56)wslot >*/
    feq_gen_io_d__181.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__181);
    do_fio(&feq_gen_c_d_1, (char *)&wslot, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE conduit.for:1297 */
/*<       slot=wslot >*/
    nrdzcm_1.slot = wslot;
/* SOURCE conduit.for:1299 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:1302 */
/*<       read(line,6,err=991)hslot >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_6;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&hslot, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE conduit.for:1303 */
/*<       write(stdout,58)hslot >*/
    feq_gen_io_d__183.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__183);
    do_fio(&feq_gen_c_d_1, (char *)&hslot, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE conduit.for:1305 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:1308 */
/*<       read(line,7,err=991)npipes,czeps >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_7;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&npipes, (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, czeps, (ftnlen)10);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE conduit.for:1309 */
/*<       if(czeps.eq.' ')then >*/
    if (s_cmp(czeps, const_cast<char*>(" "), (ftnlen)10, (ftnlen)1) == 0) {
/* SOURCE conduit.for:1310 */
/*<       zeps=epsdif >*/
	zeps = epscom_1.epsdif;
/* SOURCE conduit.for:1311 */
/*<       else >*/
    } else {
/* SOURCE conduit.for:1312 */
/*<       read(czeps,'(F10.0)')zeps >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 10;
	feq_gen_ici_d_1.iciunit = czeps;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.0)");
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&zeps, (ftnlen)sizeof(real));
	e_rsfi();
/* SOURCE conduit.for:1313 */
/*<       endif >*/
    }
/* SOURCE conduit.for:1314 */
/*<       write(stdout,57)npipes,zeps >*/
    feq_gen_io_d__187.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__187);
    do_fio(&feq_gen_c_d_1, (char *)&npipes, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&zeps, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE conduit.for:1316 */
/*<       if(npipes.gt.pmxsub)then >*/
    if (npipes > 200) {
/* SOURCE conduit.for:1317 */
/*<       write(stdout,66)npipes,pmxsub >*/
	feq_gen_io_d__188.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__188);
	do_fio(&feq_gen_c_d_1, (char *)&npipes, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_200, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE conduit.for:1318 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE conduit.for:1319 */
/*<       return >*/
	return 0;
/* SOURCE conduit.for:1320 */
/*<       endif >*/
    }
/*     Compute the control value for reading the conduit descriptions */
/* SOURCE conduit.for:1324 */
/*<       itend=(npipes-1)/6+1 >*/
    itend = (npipes - 1) / 6 + 1;
/* SOURCE conduit.for:1325 */
/*<       do485it=1,itend >*/
    feq_gen_i_d_1 = itend;
    for (it = 1; it <= feq_gen_i_d_1; ++it) {
/* SOURCE conduit.for:1326 */
/*<       js=1+6*(it-1) >*/
	js = (it - 1) * 6 + 1;
/* SOURCE conduit.for:1327 */
/*<       je=js+5 >*/
	je = js + 5;
/* SOURCE conduit.for:1328 */
/*<       je=min(je,npipes) >*/
	je = min(je,npipes);
/* SOURCE conduit.for:1330 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:1333 */
/*<       read(line,8,err=991)(diam(j),j=js,je) >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_8;
	feq_gen_i_d_2 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_2 != 0) {
	    goto L991;
	}
	feq_gen_i_d_3 = je;
	for (j = js; j <= feq_gen_i_d_3; ++j) {
	    feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&diam[j - 1], (ftnlen)sizeof(real));
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
	}
	feq_gen_i_d_2 = e_rsfi();
	if (feq_gen_i_d_2 != 0) {
	    goto L991;
	}
/* SOURCE conduit.for:1334 */
/*<       write(stdout,70)(diam(j),j=js,je) >*/
	feq_gen_io_d__195.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__195);
	feq_gen_i_d_2 = je;
	for (j = js; j <= feq_gen_i_d_2; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&diam[j - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
/* SOURCE conduit.for:1336 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:1339 */
/*<       read(line,9,err=991)(bottom(j),j=js,je) >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_9;
	feq_gen_i_d_2 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_2 != 0) {
	    goto L991;
	}
	feq_gen_i_d_3 = je;
	for (j = js; j <= feq_gen_i_d_3; ++j) {
	    feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&bottom[j - 1], (ftnlen)sizeof(real))
		    ;
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
	}
	feq_gen_i_d_2 = e_rsfi();
	if (feq_gen_i_d_2 != 0) {
	    goto L991;
	}
/* SOURCE conduit.for:1340 */
/*<       write(stdout,72)(bottom(j),j=js,je) >*/
	feq_gen_io_d__197.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__197);
	feq_gen_i_d_2 = je;
	for (j = js; j <= feq_gen_i_d_2; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&bottom[j - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
/* SOURCE conduit.for:1342 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:1345 */
/*<       read(line,10,err=991)(rough(j),j=js,je) >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_10;
	feq_gen_i_d_2 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_2 != 0) {
	    goto L991;
	}
	feq_gen_i_d_3 = je;
	for (j = js; j <= feq_gen_i_d_3; ++j) {
	    feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&rough[j - 1], (ftnlen)sizeof(real));
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
	}
	feq_gen_i_d_2 = e_rsfi();
	if (feq_gen_i_d_2 != 0) {
	    goto L991;
	}
/* SOURCE conduit.for:1346 */
/*<       write(stdout,74)(rough(j),j=js,je) >*/
	feq_gen_io_d__199.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__199);
	feq_gen_i_d_2 = je;
	for (j = js; j <= feq_gen_i_d_2; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&rough[j - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
/*       Look ahead for the mudline input line.  If not there, backspace */
/*       the input file and set the mud line level to null. */
/* SOURCE conduit.for:1351 */
/*<       callinlineb(stdin,stdout,line) >*/
	inlineb_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:1354 */
/*<       if(line(1:4).ne.'MUDL')then >*/
	if (s_cmp(line, const_cast<char*>("MUDL"), (ftnlen)4, (ftnlen)4) != 0) {
/* SOURCE conduit.for:1355 */
/*<       backspacestdin >*/
	    feq_gen_al_d_1.aerr = 0;
	    feq_gen_al_d_1.aunit = *stdin;
	    f_back(&feq_gen_al_d_1);
/* SOURCE conduit.for:1356 */
/*<       do480j=js,je >*/
	    feq_gen_i_d_2 = je;
	    for (j = js; j <= feq_gen_i_d_2; ++j) {
/* SOURCE conduit.for:1357 */
/*<       zmud(j)=0.0 >*/
		zmud[j - 1] = (float)0.;
/* SOURCE conduit.for:1358 */
/*<       nmud(j)=0.0 >*/
		nmud[j - 1] = (float)0.;
/* SOURCE conduit.for:1359 */
/*<   480 continue >*/
/* L480: */
	    }
/* SOURCE conduit.for:1360 */
/*<       else >*/
	} else {
/*         READ THE MUDLINE LEVEL */
/* SOURCE conduit.for:1362 */
/*<       read(line,12,err=991)(zmud(j),j=js,je) >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 80;
	    feq_gen_ici_d_1.iciunit = line;
	    feq_gen_ici_d_1.icifmt = fmt_12;
	    feq_gen_i_d_2 = s_rsfi(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_3 = je;
	    for (j = js; j <= feq_gen_i_d_3; ++j) {
		feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&zmud[j - 1], (ftnlen)sizeof(
			real));
		if (feq_gen_i_d_2 != 0) {
		    goto L991;
		}
	    }
	    feq_gen_i_d_2 = e_rsfi();
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
/* SOURCE conduit.for:1363 */
/*<       write(stdout,76)(zmud(j),j=js,je) >*/
	    feq_gen_io_d__202.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__202);
	    feq_gen_i_d_2 = je;
	    for (j = js; j <= feq_gen_i_d_2; ++j) {
		do_fio(&feq_gen_c_d_1, (char *)&zmud[j - 1], (ftnlen)sizeof(real));
	    }
	    e_wsfe();
/* SOURCE conduit.for:1364 */
/*<       callinline(stdin,stdout,line) >*/
	    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:1367 */
/*<       read(line,14,err=991)(nmud(j),j=js,je) >*/
	    feq_gen_ici_d_1.icierr = 1;
	    feq_gen_ici_d_1.iciend = 0;
	    feq_gen_ici_d_1.icirnum = 1;
	    feq_gen_ici_d_1.icirlen = 80;
	    feq_gen_ici_d_1.iciunit = line;
	    feq_gen_ici_d_1.icifmt = fmt_14;
	    feq_gen_i_d_2 = s_rsfi(&feq_gen_ici_d_1);
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
	    feq_gen_i_d_3 = je;
	    for (j = js; j <= feq_gen_i_d_3; ++j) {
		feq_gen_i_d_2 = do_fio(&feq_gen_c_d_1, (char *)&nmud[j - 1], (ftnlen)sizeof(
			real));
		if (feq_gen_i_d_2 != 0) {
		    goto L991;
		}
	    }
	    feq_gen_i_d_2 = e_rsfi();
	    if (feq_gen_i_d_2 != 0) {
		goto L991;
	    }
/* SOURCE conduit.for:1368 */
/*<       write(stdout,78)(nmud(j),j=js,je) >*/
	    feq_gen_io_d__203.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__203);
	    feq_gen_i_d_2 = je;
	    for (j = js; j <= feq_gen_i_d_2; ++j) {
		do_fio(&feq_gen_c_d_1, (char *)&nmud[j - 1], (ftnlen)sizeof(real));
	    }
	    e_wsfe();
/* SOURCE conduit.for:1369 */
/*<       endif >*/
	}
/* SOURCE conduit.for:1370 */
/*<   485 continue >*/
/* L485: */
    }
/* SOURCE conduit.for:1372 */
/*<       if(nsides.lt.10)then >*/
    if (nsides < 10) {
/* SOURCE conduit.for:1373 */
/*<       write(stdout,62)nsides >*/
	feq_gen_io_d__204.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__204);
	do_fio(&feq_gen_c_d_1, (char *)&nsides, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE conduit.for:1374 */
/*<       nsides=10 >*/
	nsides = 10;
/* SOURCE conduit.for:1375 */
/*<       endif >*/
    }
/* SOURCE conduit.for:1376 */
/*<       if(npipes*nsides.gt.mxpntu-npipes*4)then >*/
    if (npipes * nsides > xscomu_1.mxpntu - (npipes << 2)) {
/* SOURCE conduit.for:1377 */
/*<       write(stdout,64)nsides*npipes,nsides*(mxpntu-4) >*/
	feq_gen_io_d__205.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__205);
	feq_gen_i_d_1 = nsides * npipes;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
	feq_gen_i_d_2 = nsides * (xscomu_1.mxpntu - 4);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_2, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE conduit.for:1378 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE conduit.for:1379 */
/*<       return >*/
	return 0;
/* SOURCE conduit.for:1380 */
/*<       endif >*/
    }
/*     CONSTRUCT THE POINTS ON THE BOUNDARY OF THE SLOTTED PIPE. */
/*     PLACE PIPES SIDE BY SIDE EACH WITH A SLOT.  ASSIGN A DIFFERENT */
/*     SUBSECTION TO EACH.  XOFF WILL BE LARGE ENOUGH */
/*     SO THAT THE PIPES DO NOT OVER LAP */
/*     MATCH AREA OF PIPE WITH A POLYGON WITH NSIDES SIDES */
/* SOURCE conduit.for:1388 */
/*<       snflgu=0 >*/
    xscomu_1.snflgu = 0;
/* SOURCE conduit.for:1389 */
/*<       do490i=1,npipes >*/
    feq_gen_i_d_1 = npipes;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE conduit.for:1390 */
/*<       nnyu(i)=0 >*/
	xscomu_1.nnyu[feq_gen_i_d_ - 1] = 0;
/* SOURCE conduit.for:1391 */
/*<   490 continue >*/
/* L490: */
    }
/*     MAKE SURE THE SLOT IS HIGH ENOUGH */
/* SOURCE conduit.for:1394 */
/*<       maxsof=0.0 >*/
    maxsof = (float)0.;
/* SOURCE conduit.for:1395 */
/*<       do492i=1,npipes >*/
    feq_gen_i_d_1 = npipes;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE conduit.for:1396 */
/*<       maxsof=max(maxsof,bottom(i)+diam(i)) >*/
/* Computing MAX */
	feq_gen_r_d_1 = maxsof, feq_gen_r_d_2 = static_cast<double>(bottom[feq_gen_i_d_ - 1]) + diam[feq_gen_i_d_ - 1];
	maxsof = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE conduit.for:1397 */
/*<   492 continue >*/
/* L492: */
    }
/* SOURCE conduit.for:1398 */
/*<       if(hslot.lt.maxsof+5.0)then >*/
    if (hslot < static_cast<double>(maxsof) + (float)5.) {
/* SOURCE conduit.for:1399 */
/*<       hslot=maxsof+5.0 >*/
	hslot = static_cast<double>(maxsof) + (float)5.;
/* SOURCE conduit.for:1400 */
/*<       endif >*/
    }
/* SOURCE conduit.for:1402 */
/*<       xoff=0.0 >*/
    xoff = (float)0.;
/* SOURCE conduit.for:1403 */
/*<       istart=1 >*/
    istart = 1;
/* SOURCE conduit.for:1404 */
/*<       npntu=0 >*/
    xscomu_1.npntu = 0;
/* SOURCE conduit.for:1405 */
/*<       do500i=1,npipes >*/
    feq_gen_i_d_1 = npipes;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE conduit.for:1407 */
/*<       zoff=bottom(i) >*/
	zoff = bottom[feq_gen_i_d_ - 1];
/*       CALL MKPIPE WITH THE THE RIGHT OFFSETS USED IN THE */
/*       ARGUMENTS SO THAT THE VECTORS ARE CREATED INCREMENTALLY */
/* SOURCE conduit.for:1412 */
/*<        >*/
	mkpipe_(&xoff, &zoff, &nsides, &diam[feq_gen_i_d_ - 1], &wslot, &hslot, &npnt, 
		&xscomu_1.xu[istart - 1], &xscomu_1.zu[istart - 1]);
/* SOURCE conduit.for:1416 */
/*<       do400j=1,npnt >*/
	feq_gen_i_d_2 = npnt;
	for (j = 1; j <= feq_gen_i_d_2; ++j) {
/* SOURCE conduit.for:1417 */
/*<       sbu(istart+j-1)=i >*/
	    xscomu_1.sbu[istart + j - 2] = feq_gen_i_d_;
/* SOURCE conduit.for:1418 */
/*<       lsnu(istart+j-1)=rough(i) >*/
	    xscomu_1.lsnu[istart + j - 2] = rough[feq_gen_i_d_ - 1];
/* SOURCE conduit.for:1419 */
/*<       snu(istart+j-1)=1. >*/
	    xscomu_1.snu[istart + j - 2] = (float)1.;
/* SOURCE conduit.for:1420 */
/*<   400 continue >*/
/* L400: */
	}
/* SOURCE conduit.for:1422 */
/*<       if(zmud(i).gt.0.0)then >*/
	if (zmud[feq_gen_i_d_ - 1] > (float)0.) {
/*         ADJUST THE CROSS SECTION FOR A MUD LINE */
/* SOURCE conduit.for:1426 */
/*<       zmud2=zmud(i)+zoff >*/
	    zmud2 = static_cast<double>(zmud[feq_gen_i_d_ - 1]) + zoff;
/* SOURCE conduit.for:1427 */
/*<        >*/
	    setmud_(stdout, &istart, &feq_gen_c_d_999, &nmud[feq_gen_i_d_ - 1], &rough[feq_gen_i_d_ - 1],
		     &zmud2, &zeps, &npnt, xscomu_1.xu, xscomu_1.zu, 
		    xscomu_1.lsnu, xscomu_1.sbu, eflag);
/* SOURCE conduit.for:1431 */
/*<       if(eflag.ne.0)return >*/
	    if (*eflag != 0) {
		return 0;
	    }
/* SOURCE conduit.for:1433 */
/*<       endif >*/
	}
/* SOURCE conduit.for:1436 */
/*<       istart=istart+npnt >*/
	istart += npnt;
/* SOURCE conduit.for:1437 */
/*<       npntu=npntu+npnt >*/
	xscomu_1.npntu += npnt;
/* SOURCE conduit.for:1438 */
/*<       if(i.ne.npipes)then >*/
	if (feq_gen_i_d_ != npipes) {
/* SOURCE conduit.for:1439 */
/*<       xoff=xoff+max(diam(i),diam(i+1))+1.0 >*/
/* Computing MAX */
	    feq_gen_r_d_1 = diam[feq_gen_i_d_ - 1], feq_gen_r_d_2 = diam[feq_gen_i_d_];
	    xoff = xoff + dmax(feq_gen_r_d_1,feq_gen_r_d_2) + (float)1.;
/* SOURCE conduit.for:1440 */
/*<       endif >*/
	}
/* SOURCE conduit.for:1442 */
/*<   500 continue >*/
/* L500: */
    }
/*      WRITE(STDOUT,*) ' ' */
/*      WRITE(STDOUT,*) ' DUMP OF CROSS-SECTION BOUNDARY' */
/*      WRITE(STDOUT,*) ' ' */

/*      DO 1000 I=1,NPNTU */
/*        WRITE(STDOUT,90) XU(I), ZU(I), SBU(I), LSNU(I), SNU(I) */
/* 90    FORMAT(F10.4,F10.4,I5, F10.4,f10.2) */
/* 1000  CONTINUE */
/*      WRITE(STDOUT,*) ' ' */
/* SOURCE conduit.for:1455 */
/*<       navmu=0 >*/
    xscomu_1.navmu = 0;
/* SOURCE conduit.for:1456 */
/*<       nsubu=npipes >*/
    xscomu_1.nsubu = npipes;
/* SOURCE conduit.for:1457 */
/*<       do600i=1,npipes >*/
    feq_gen_i_d_1 = npipes;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE conduit.for:1458 */
/*<       nu(i)=rough(i) >*/
	xscomu_1.nu[feq_gen_i_d_ - 1] = rough[feq_gen_i_d_ - 1];
/* SOURCE conduit.for:1459 */
/*<       nvaru(i)=0 >*/
	xscomu_1.nvaru[feq_gen_i_d_ - 1] = 0;
/* SOURCE conduit.for:1460 */
/*<   600 continue >*/
/* L600: */
    }
/* SOURCE conduit.for:1461 */
/*<       left=1.0 >*/
    left = (float)1.;
/* SOURCE conduit.for:1462 */
/*<       right=0.0 >*/
    right = (float)0.;
/* SOURCE conduit.for:1463 */
/*<       statu=0.0 >*/
    xscomu_1.statu = (float)0.;
/*     COMPUTE ELEMENTS FOR CURRENT CROSS SECTION */
/* SOURCE conduit.for:1467 */
/*<       if(npntu.gt.1)then >*/
    if (xscomu_1.npntu > 1) {
/*       FIND THE MAXIMUM AND MINIMUM ARGUMENT VALUES */
/* SOURCE conduit.for:1469 */
/*<       zminu=9999999. >*/
	xscomu_1.zminu = (float)9999999.;
/* SOURCE conduit.for:1470 */
/*<       zmaxu=-9999999. >*/
	xscomu_1.zmaxu = (float)-9999999.;
/* SOURCE conduit.for:1471 */
/*<       do150j=1,npntu >*/
	feq_gen_i_d_1 = xscomu_1.npntu;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE conduit.for:1472 */
/*<       if(zu(j).gt.zmaxu)zmaxu=zu(j) >*/
	    if (xscomu_1.zu[j - 1] > xscomu_1.zmaxu) {
		xscomu_1.zmaxu = xscomu_1.zu[j - 1];
	    }
/* SOURCE conduit.for:1473 */
/*<       if(zu(j).lt.zminu)zminu=zu(j) >*/
	    if (xscomu_1.zu[j - 1] < xscomu_1.zminu) {
		xscomu_1.zminu = xscomu_1.zu[j - 1];
	    }
/* SOURCE conduit.for:1474 */
/*<   150 continue >*/
/* L150: */
	}
/* SOURCE conduit.for:1477 */
/*<        >*/
	cxstab_(stdout, &xscomu_1.nsubu, &xscomu_1.navmu, nfac, &
		xscomu_1.mxpntu, &left, &right, betopt, &xscomu_1.snflgu, 
		xscomu_1.nvaru, xscomu_1.natyu, xscomu_1.yatnu, xscomu_1.nnyu,
		 &xscomu_1.npntu, &xscomu_1.zminu, &xscomu_1.zmaxu, 
		xscomu_1.xu, xscomu_1.zu, xscomu_1.sbu, eflag, xscomu_1.lsnu, 
		xscomu_1.snu, xscomu_1.nu, &xscomu_1.ndepu, xscomu_1.xstu, (
		ftnlen)8);
/* SOURCE conduit.for:1483 */
/*<       endif >*/
    }
/*     FORCE THE CONVEYANCE TO BE MONOTONE INCREASING. */
/*     limiting the maximum conveyance to the full-flow conveyance. */
/*     The flow near the crown of the opening is of an uncertain */
/*     character in most cases. */
/* SOURCE conduit.for:1490 */
/*<       if(nocm.eq.1)then >*/
    if (nrdzcm_1.nocm == 1) {
/*       Find start of the slot. */
/* SOURCE conduit.for:1492 */
/*<       do168j=ndepu-2,2,-1 >*/
	for (j = xscomu_1.ndepu - 2; j >= 2; --j) {
/* SOURCE conduit.for:1493 */
/*<       if(xstu(j-1,2).gt.xstu(j,2))then >*/
	    if (xscomu_1.xstu[j + 997] > xscomu_1.xstu[j + 998]) {
/*           J is the entrance to the top slot */
/* SOURCE conduit.for:1495 */
/*<       goto169 >*/
		goto L169;
/* SOURCE conduit.for:1496 */
/*<       endif >*/
	    }
/* SOURCE conduit.for:1497 */
/*<   168 continue >*/
/* L168: */
	}
/* SOURCE conduit.for:1498 */
/*<   169 continue >*/
L169:
/* SOURCE conduit.for:1499 */
/*<       maxk=xstu(j,5) >*/
	maxk = xscomu_1.xstu[j + 3995];
/* SOURCE conduit.for:1500 */
/*<       do170j=2,ndepu >*/
	feq_gen_i_d_1 = xscomu_1.ndepu;
	for (j = 2; j <= feq_gen_i_d_1; ++j) {
/* SOURCE conduit.for:1501 */
/*<       if(xstu(j-1,5).gt.maxk)then >*/
	    if (xscomu_1.xstu[j + 3994] > maxk) {
/* SOURCE conduit.for:1502 */
/*<       xstu(j-1,5)=maxk >*/
		xscomu_1.xstu[j + 3994] = maxk;
/* SOURCE conduit.for:1503 */
/*<       endif >*/
	    }
/* SOURCE conduit.for:1504 */
/*<   170 continue >*/
/* L170: */
	}
/* SOURCE conduit.for:1505 */
/*<       endif >*/
    }
/*     OUTPUT THE TABLE IF NO ERRORS AND IF OUTPUT IS REQUESTED */
/* SOURCE conduit.for:1509 */
/*<       if(eflag.ne.0.or.tabu.eq.0)goto200 >*/
    if (*eflag != 0 || xscomu_1.tabu == 0) {
	goto L200;
    }
/*        IF(ABS(ZMINU).LT.0.001) ZMINU = 0.0 */
/*       REMOVE THE TOP VALUE TO ELIMINATE THE */
/*       ERRATIC TOP WIDTH. */
/* SOURCE conduit.for:1514 */
/*<       ndepu=ndepu-1 >*/
    --xscomu_1.ndepu;
/*       FORCE ALPHA AND BETA TO BE 1.00 TO REDUCE PROBLEMS WITH */
/*       CRITICAL DEPTH.  ALPHA AND BETA ARE CLOSE TO 1.00 IN ANY */
/*       CASE. */
/* SOURCE conduit.for:1520 */
/*<       do190j=1,ndepu >*/
    feq_gen_i_d_1 = xscomu_1.ndepu;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE conduit.for:1521 */
/*<       xstu(j,6)=1.0 >*/
	xscomu_1.xstu[j + 4994] = (float)1.;
/* SOURCE conduit.for:1522 */
/*<       xstu(j,7)=1.0 >*/
	xscomu_1.xstu[j + 5993] = (float)1.;
/* SOURCE conduit.for:1523 */
/*<   190 continue >*/
/* L190: */
    }
/*     compute derivatives of square root of conveyance, alpha, beta, */
/*     da, and dq */
/* SOURCE conduit.for:1528 */
/*<        >*/
    xsecfit_(stdout, &feq_gen_c_d_0, &xscomu_1.ndepu, xscomu_1.xstu, khflag, alphaflag,
	     betaflag, maflag, mqflag, (ftnlen)1, (ftnlen)1, (ftnlen)1, (
	    ftnlen)1, (ftnlen)1);
/* SOURCE conduit.for:1533 */
/*<        >*/
    tabout_(stdout, stdtab, &xscomu_1.tabu, &xscomu_1.statu, &xscomu_1.zminu, 
	    &feq_gen_c_d_0, savopt, outopt, betopt, zone, hgrid, vdatum, unitsys, 
	    basis, khflag, alphaflag, betaflag, maflag, mqflag, &
	    xscomu_1.ndepu, xscomu_1.xstu, ftp, (ftnlen)8, (ftnlen)8, (ftnlen)
	    8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)
	    1, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
/* SOURCE conduit.for:1538 */
/*<   200 continue >*/
L200:
/* SOURCE conduit.for:1539 */
/*<       return >*/
    return 0;
/* SOURCE conduit.for:1540 */
/*<   991 continue >*/
L991:
/* SOURCE conduit.for:1541 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__221.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__221);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE conduit.for:1542 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__222.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__222);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE conduit.for:1543 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE conduit.for:1544 */
/*<       end >*/
    return 0;
} /* pipes_ */




/* SOURCE conduit.for:1548 */
/*<       subroutinesewer(stdin,stdout,stdtab,nfac,tabdir,eflag,ftp) >*/
/* Subroutine */ int sewer_(integer *stdin, integer *stdout, integer *stdtab, 
	real *nfac, integer *feq_storage_tabdir, integer *eflag, integer *ftp)
{
    /* Format strings */
    static char fmt_2[] = "(9x,f10.0)";
    static char fmt_4[] = "(7x,i5)";
    static char fmt_6[] = "(6x,f10.0)";
    static char fmt_8[] = "(2x,f10.0)";
    static char fmt_10[] = "(5x,f10.0)";
    static char fmt_12[] = "(5x,f10.0)";
    static char fmt_50[] = "(/,\002 TABID= \002,a,2x,a)";
    static char fmt_52[] = "(\002 DIAMETER=\002,f8.3)";
    static char fmt_54[] = "(\002 POLYGON APPROX HAS\002,i3,\002 SIDES\002)";
    static char fmt_56[] = "(\002 WIDTH OF SLOT=\002,f7.4)";
    static char fmt_58[] = "(\002 HEIGHT OF SLOT=\002,f7.0)";
    static char fmt_60[] = "(\002 MANNING N=\002,f7.3)";
    static char fmt_62[] = "(/,\002*WRN:511* NUMBER OF SIDES=\002,i3,\002 TO\
O SMALL.\002,\002 NSIDES RESET TO 10\002)";
    static char fmt_64[] = "(/,\002*WRN:512* NUMBER OF SIDES=\002,i4,\002 TO\
O LARGE.\002,\002 NSIDES RESET TO\002,i5)";
    static char fmt_66[] = "(/,\002*WRN:549* BETA OPTION MUST BE \"OLDBETA\"\
.  THE OPTION\002,\002 HAS BEEN RESET TO \"OLDBETA\".\002)";
    static char fmt_68[] = "(\002 MUD LINE LEVEL=\002,f10.3)";
    static char fmt_70[] = "(\002 MUD LINE N=\002,f10.3)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    icilist feq_gen_ici_d_1;
    alist feq_gen_al_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_cmp(char *, char *, ftnlen, ftnlen), s_rsfi(icilist *), e_rsfi()
	    , f_back(alist *), s_wsle(cilist *), do_lio(integer *, integer *, 
	    char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    char betaflag[1*999];
    real feq_gen_d_d_;
    integer feq_gen_i_d_, j;
    real n;
    char alphaflag[1*999];
    integer tab;
    char cin[64], line[80];
    real left, maxk, xoff, nmud, zoff;
    char zone[8];
    real zmud, zeps;
    char hgrid[8], basis[8];
    real right, hslot, wslot;
    char maflag[1*999], khflag[1*999];
    extern /* Subroutine */ int tabchk_(integer *, integer *, integer *, 
	    integer *, integer *);
    char mqflag[1*999];
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen);
    integer nsides;
    extern /* Subroutine */ int cxstab_(integer *, integer *, integer *, real 
	    *, integer *, real *, real *, char *, integer *, integer *, real *
	    , real *, integer *, integer *, real *, real *, real *, real *, 
	    integer *, integer *, real *, real *, real *, integer *, real *, 
	    ftnlen), mkpipe_(real *, real *, integer *, real *, real *, real *
	    , integer *, real *, real *);
    integer istart;
    char betopt[8], monton[8], outopt[8], savopt[8], vdatum[8];
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int setmud_(integer *, integer *, integer *, real 
	    *, real *, real *, real *, integer *, real *, real *, real *, 
	    integer *, integer *), setopt_(integer *, char *, char *, char *, 
	    char *, char *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen), tabout_(
	    integer *, integer *, integer *, real *, real *, integer *, char *
	    , char *, char *, char *, char *, char *, char *, char *, char *, 
	    char *, char *, char *, char *, integer *, real *, integer *, 
	    ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen, ftnlen), feq_gen_get_lctn_items_d_(integer 
	    *, integer *, integer *), feq_gen_set_lctn_items_d_(char *, char *, char *,
	     char *, char *, doublereal *, doublereal *, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen), inlineb_(integer *, integer *, char *, 
	    ftnlen), xsecfit_(integer *, integer *, integer *, real *, char *,
	     char *, char *, char *, char *, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen), feq_gen_read_tabid_plus_d_(integer *, char *, integer *, char *, 
	    integer *, char *, ftnlen, ftnlen, ftnlen);
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__226 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__231 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__238 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__240 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__242 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__244 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__246 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__249 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__250 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__252 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__253 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__267 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__268 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Compute a sewer cross section complete with upper slot. */
/* SOURCE conduit.for:1554 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE conduit.for:1556 */
/*<       integereflag,ftp,stdin,stdout,stdtab >*/
/* SOURCE conduit.for:1557 */
/*<       integertabdir(*) >*/
/* SOURCE conduit.for:1558 */
/*<       realnfac >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     NFAC   - Factor in Manning's formula(1.49 or 1.0) */
/*     TABDIR - Table directory to remember table numbers */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     FTP    - next open location in the function table storage */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE conduit.for:1570 */
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
/* INCLUDE conduit.for:1571 */
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
/* INCLUDE conduit.for:1572 */
/*     NEAR ZERO DEPTH AND DZ COMMON.  ALSO HAS OTHER ITEMS */
/* SOURCE nrdzcm.cmn:3 */
/*<       integerextend,gxtend,nocm,iusgs >*/
/* SOURCE nrdzcm.cmn:5 */
/*<       realnrzero,dzlim,slot >*/
/* SOURCE nrdzcm.cmn:7 */
/*<       common/nrdzcm/nrzero,dzlim,nocm,slot,iusgs,extend,gxtend >*/
/* INCLUDE conduit.for:1573 */
/*     Values added to cross section tables: July 1997 */
/*     December 1999, June 2003 */
/* SOURCE xtadd.cmn:4 */
/*<       integerws_tab >*/
/* SOURCE xtadd.cmn:5 */
/*<       realslot_depth,dinvert >*/
/* SOURCE xtadd.cmn:6 */
/*<       real*8easting,northing >*/
/* SOURCE xtadd.cmn:8 */
/*<       character*16gisid,tabid,ws_tabid >*/
/* SOURCE xtadd.cmn:10 */
/*<       common/xtadd/easting,northing,slot_depth,dinvert,ws_tab >*/
/* SOURCE xtadd.cmn:11 */
/*<       common/xtaddc/gisid,tabid,ws_tabid >*/
/* SOURCE xtadd.cmn:13 */
/*<       save/xtadd/,/xtaddc/ >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE conduit.for:1575 */
/*<       integeri,istart,j,nsides,tab >*/
/* SOURCE conduit.for:1576 */
/*<       reald,hslot,left,maxk,n,nmud,right,wslot,xoff,zeps,zmud,zoff >*/
/* SOURCE conduit.for:1578 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE conduit.for:1586 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE conduit.for:1589 */
/*<       integerlenstr >*/
/* SOURCE conduit.for:1590 */
/*<        >*/
/*     + + + INPUT FORMATS + + + */
/* SOURCE conduit.for:1594 */
/*<     1 format(7x,i5,a) >*/
/* SOURCE conduit.for:1595 */
/*<     2 format(9x,f10.0) >*/
/* SOURCE conduit.for:1596 */
/*<     4 format(7x,i5) >*/
/* SOURCE conduit.for:1597 */
/*<     6 format(6x,f10.0) >*/
/* SOURCE conduit.for:1598 */
/*<     8 format(2x,f10.0) >*/
/* SOURCE conduit.for:1599 */
/*<    10 format(5x,f10.0) >*/
/* SOURCE conduit.for:1600 */
/*<    12 format(5x,f10.0) >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE conduit.for:1603 */
/*<    50 format(/,' TABID= ',a,2x,a) >*/
/* SOURCE conduit.for:1604 */
/*<    52 format(' DIAMETER=',f8.3) >*/
/* SOURCE conduit.for:1605 */
/*<    54 format(' POLYGON APPROX HAS',i3,' SIDES') >*/
/* SOURCE conduit.for:1606 */
/*<    56 format(' WIDTH OF SLOT=',f7.4) >*/
/* SOURCE conduit.for:1607 */
/*<    58 format(' HEIGHT OF SLOT=',f7.0) >*/
/* SOURCE conduit.for:1608 */
/*<    60 format(' MANNING N=',f7.3) >*/
/* SOURCE conduit.for:1609 */
/*<    62  >*/
/* SOURCE conduit.for:1611 */
/*<    64  >*/
/* SOURCE conduit.for:1613 */
/*<    66  >*/
/* SOURCE conduit.for:1615 */
/*<    68 format(' MUD LINE LEVEL=',f10.3) >*/
/* SOURCE conduit.for:1616 */
/*<    70 format(' MUD LINE N=',f10.3) >*/
/* *********************************************************************** */
/*     26 October 2006, ddf: Set the gisid to blank.  Uninitialized otherwise! */
/* SOURCE conduit.for:1619 */
/*<       gisid=' ' >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> tabdir(feq_storage_tabdir, 1);

    /* Function Body */
/* L1: */
/* L2: */
/* L4: */
/* L6: */
/* L8: */
/* L10: */
/* L12: */
/* L50: */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
/* L60: */
/* L62: */
/* L64: */
/* L66: */
/* L68: */
/* L70: */
    s_copy(xtaddc_1.gisid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/*     ALLOW AUTOMATIC EXTENSION */
/* SOURCE conduit.for:1622 */
/*<       extend=1 >*/
    nrdzcm_1.extend = 1;
/* SOURCE conduit.for:1624 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:1627 */
/*<       callread_tabid_plus(stdout,line,eflag,tabid,tab,cin) >*/
    feq_gen_read_tabid_plus_d_(stdout, line, eflag, xtaddc_1.tabid, &tab, cin, (ftnlen)
	    80, (ftnlen)16, (ftnlen)64);
/*      READ(LINE,1,ERR=991) TAB, CIN */
/* SOURCE conduit.for:1631 */
/*<       write(stdout,50)tabid(1:lenstr(tabid)),cin >*/
    feq_gen_io_d__226.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__226);
    do_fio(&feq_gen_c_d_1, xtaddc_1.tabid, lenstr_(xtaddc_1.tabid, (ftnlen)16));
    do_fio(&feq_gen_c_d_1, cin, (ftnlen)64);
    e_wsfe();
/* SOURCE conduit.for:1633 */
/*<       callsetopt(stdout,cin,savopt,outopt,monton,betopt) >*/
    setopt_(stdout, cin, savopt, outopt, monton, betopt, (ftnlen)64, (ftnlen)
	    8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE conduit.for:1636 */
/*<       if(betopt.ne.'OLDBETA')then >*/
    if (s_cmp(betopt, const_cast<char*>("OLDBETA"), (ftnlen)8, (ftnlen)7) != 0) {
/* SOURCE conduit.for:1637 */
/*<       write(stdout,66) >*/
	feq_gen_io_d__231.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__231);
	e_wsfe();
/* SOURCE conduit.for:1638 */
/*<       betopt='OLDBETA' >*/
	s_copy(betopt, const_cast<char*>("OLDBETA"), (ftnlen)8, (ftnlen)7);
/* SOURCE conduit.for:1639 */
/*<       endif >*/
    }
/* SOURCE conduit.for:1641 */
/*<       if(tab.lt.0)then >*/
    if (tab < 0) {
/* SOURCE conduit.for:1642 */
/*<       tab=-tab >*/
	tab = -tab;
/* SOURCE conduit.for:1643 */
/*<       nocm=0 >*/
	nrdzcm_1.nocm = 0;
/* SOURCE conduit.for:1644 */
/*<       else >*/
    } else {
/*       SUPPRESS CONVEYANCE MESSAGES AND FORCE MONOTONICITY */
/* SOURCE conduit.for:1646 */
/*<       nocm=1 >*/
	nrdzcm_1.nocm = 1;
/* SOURCE conduit.for:1647 */
/*<       endif >*/
    }
/* SOURCE conduit.for:1648 */
/*<       if(tab.ge.0)calltabchk(stdout,pmxtab,tab,tabdir,eflag) >*/
    if (tab >= 0) {
	tabchk_(stdout, &feq_gen_c_d_10002, &tab, &tabdir[1], eflag);
    }
/* SOURCE conduit.for:1651 */
/*<       tabu=tab >*/
    xscomu_1.tabu = tab;
/*     Get location items that may be present. If they are not present */
/*     they will be set to default values.  The default requests FEQUTL */
/*     to omit the items. */
/* SOURCE conduit.for:1656 */
/*<       callget_lctn_items(stdin,stdout,eflag) >*/
    feq_gen_get_lctn_items_d_(stdin, stdout, eflag);
/* SOURCE conduit.for:1658 */
/*<        >*/
    feq_gen_set_lctn_items_d_(zone, hgrid, vdatum, unitsys, basis, &xtadd_1.easting, &
	    xtadd_1.northing, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (
	    ftnlen)8);
/* SOURCE conduit.for:1662 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:1665 */
/*<       read(line,2,err=991)d >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&feq_gen_d_d_, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE conduit.for:1666 */
/*<       write(stdout,52)d >*/
    feq_gen_io_d__238.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__238);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_d_d_, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE conduit.for:1668 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:1671 */
/*<       read(line,4,err=991)nsides >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_4;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&nsides, (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE conduit.for:1672 */
/*<       write(stdout,54)nsides >*/
    feq_gen_io_d__240.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__240);
    do_fio(&feq_gen_c_d_1, (char *)&nsides, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE conduit.for:1674 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:1677 */
/*<       read(line,6,err=991)wslot >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_6;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&wslot, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE conduit.for:1678 */
/*<       write(stdout,56)wslot >*/
    feq_gen_io_d__242.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__242);
    do_fio(&feq_gen_c_d_1, (char *)&wslot, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE conduit.for:1680 */
/*<       slot=wslot >*/
    nrdzcm_1.slot = wslot;
/* SOURCE conduit.for:1682 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:1685 */
/*<       read(line,6,err=991)hslot >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_6;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&hslot, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE conduit.for:1686 */
/*<       write(stdout,58)hslot >*/
    feq_gen_io_d__244.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__244);
    do_fio(&feq_gen_c_d_1, (char *)&hslot, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE conduit.for:1688 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:1691 */
/*<       read(line,8,err=991)n >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_8;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&n, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE conduit.for:1692 */
/*<       write(stdout,60)n >*/
    feq_gen_io_d__246.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__246);
    do_fio(&feq_gen_c_d_1, (char *)&n, (ftnlen)sizeof(real));
    e_wsfe();
/*     LOOK AHEAD FOR THE MUDLINE INPUT LINE.  IF NOT THERE, BACKSPACE THE */
/*     INPUT FILE AND SET THE MUD LINE LEVEL TO NULL. */
/* SOURCE conduit.for:1698 */
/*<       callinlineb(stdin,stdout,line) >*/
    inlineb_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:1701 */
/*<       if(line(1:4).ne.'MUDL')then >*/
    if (s_cmp(line, const_cast<char*>("MUDL"), (ftnlen)4, (ftnlen)4) != 0) {
/* SOURCE conduit.for:1702 */
/*<       backspacestdin >*/
	feq_gen_al_d_1.aerr = 0;
	feq_gen_al_d_1.aunit = *stdin;
	f_back(&feq_gen_al_d_1);
/* SOURCE conduit.for:1703 */
/*<       zmud=0.0 >*/
	zmud = (float)0.;
/* SOURCE conduit.for:1704 */
/*<       nmud=0.0 >*/
	nmud = (float)0.;
/* SOURCE conduit.for:1705 */
/*<       else >*/
    } else {
/*       READ THE MUDLINE LEVEL */
/* SOURCE conduit.for:1707 */
/*<       read(line,10,err=991)zmud >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_10;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&zmud, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE conduit.for:1708 */
/*<       write(stdout,68)zmud >*/
	feq_gen_io_d__249.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__249);
	do_fio(&feq_gen_c_d_1, (char *)&zmud, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE conduit.for:1709 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE conduit.for:1712 */
/*<       read(line,12,err=991)nmud >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_12;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&nmud, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE conduit.for:1713 */
/*<       write(stdout,70)nmud >*/
	feq_gen_io_d__250.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__250);
	do_fio(&feq_gen_c_d_1, (char *)&nmud, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE conduit.for:1714 */
/*<       zeps=0.0 >*/
	zeps = (float)0.;
/* SOURCE conduit.for:1715 */
/*<       endif >*/
    }
/* SOURCE conduit.for:1717 */
/*<       if(nsides.lt.10)then >*/
    if (nsides < 10) {
/* SOURCE conduit.for:1718 */
/*<       write(stdout,62)nsides >*/
	feq_gen_io_d__252.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__252);
	do_fio(&feq_gen_c_d_1, (char *)&nsides, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE conduit.for:1719 */
/*<       nsides=10 >*/
	nsides = 10;
/* SOURCE conduit.for:1720 */
/*<       endif >*/
    }
/* SOURCE conduit.for:1721 */
/*<       if(nsides.gt.mxpntu-4)then >*/
    if (nsides > xscomu_1.mxpntu - 4) {
/* SOURCE conduit.for:1722 */
/*<       write(stdout,64)nsides,mxpntu-4 >*/
	feq_gen_io_d__253.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__253);
	do_fio(&feq_gen_c_d_1, (char *)&nsides, (ftnlen)sizeof(integer));
	feq_gen_i_d_1 = xscomu_1.mxpntu - 4;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE conduit.for:1723 */
/*<       nsides=mxpntu-4 >*/
	nsides = xscomu_1.mxpntu - 4;
/* SOURCE conduit.for:1724 */
/*<       endif >*/
    }
/*     CONSTRUCT THE POINTS ON THE BOUNDARY OF THE SLOTTED PIPE. */
/*     MATCH AREA OF PIPE WITH A POLYGON WITH NSIDES SIDES */
/* SOURCE conduit.for:1729 */
/*<       if(hslot.lt.3.*d)then >*/
    if (hslot < static_cast<double>(feq_gen_d_d_) * (float)3.) {
/* SOURCE conduit.for:1730 */
/*<       hslot=3.*d >*/
	hslot = static_cast<double>(feq_gen_d_d_) * (float)3.;
/* SOURCE conduit.for:1731 */
/*<       endif >*/
    }
/* SOURCE conduit.for:1732 */
/*<       xoff=0.0 >*/
    xoff = (float)0.;
/* SOURCE conduit.for:1733 */
/*<       zoff=0.0 >*/
    zoff = (float)0.;
/* SOURCE conduit.for:1734 */
/*<       callmkpipe(xoff,zoff,nsides,d,wslot,hslot,npntu,xu,zu) >*/
    mkpipe_(&xoff, &zoff, &nsides, &feq_gen_d_d_, &wslot, &hslot, &xscomu_1.npntu, 
	    xscomu_1.xu, xscomu_1.zu);
/* SOURCE conduit.for:1738 */
/*<       navmu=0 >*/
    xscomu_1.navmu = 0;
/* SOURCE conduit.for:1739 */
/*<       nu(1)=n >*/
    xscomu_1.nu[0] = n;
/* SOURCE conduit.for:1740 */
/*<       nsubu=1 >*/
    xscomu_1.nsubu = 1;
/* SOURCE conduit.for:1741 */
/*<       left=1.0 >*/
    left = (float)1.;
/* SOURCE conduit.for:1742 */
/*<       right=0.0 >*/
    right = (float)0.;
/* SOURCE conduit.for:1743 */
/*<       statu=0.0 >*/
    xscomu_1.statu = (float)0.;
/* SOURCE conduit.for:1744 */
/*<       nvaru(1)=0 >*/
    xscomu_1.nvaru[0] = 0;
/* SOURCE conduit.for:1745 */
/*<       snflgu=0 >*/
    xscomu_1.snflgu = 0;
/* SOURCE conduit.for:1746 */
/*<       nnyu(1)=0 >*/
    xscomu_1.nnyu[0] = 0;
/* SOURCE conduit.for:1748 */
/*<       do100i=1,npntu >*/
    feq_gen_i_d_1 = xscomu_1.npntu;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE conduit.for:1749 */
/*<       sbu(i)=1 >*/
	xscomu_1.sbu[feq_gen_i_d_ - 1] = 1;
/* SOURCE conduit.for:1750 */
/*<       lsnu(i)=nu(1) >*/
	xscomu_1.lsnu[feq_gen_i_d_ - 1] = xscomu_1.nu[0];
/* SOURCE conduit.for:1751 */
/*<       snu(i)=1. >*/
	xscomu_1.snu[feq_gen_i_d_ - 1] = (float)1.;
/* SOURCE conduit.for:1752 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE conduit.for:1754 */
/*<       if(zmud.gt.0.0)then >*/
    if (zmud > (float)0.) {
/*       ADJUST THE CROSS SECTION FOR A MUD LINE */
/* SOURCE conduit.for:1757 */
/*<       istart=1 >*/
	istart = 1;
/* SOURCE conduit.for:1758 */
/*<        >*/
	setmud_(stdout, &istart, &feq_gen_c_d_999, &nmud, &n, &zmud, &zeps, &
		xscomu_1.npntu, xscomu_1.xu, xscomu_1.zu, xscomu_1.lsnu, 
		xscomu_1.sbu, eflag);
/* SOURCE conduit.for:1761 */
/*<       if(eflag.ne.0)return >*/
	if (*eflag != 0) {
	    return 0;
	}
/* SOURCE conduit.for:1763 */
/*<       endif >*/
    }
/*     COMPUTE ELEMENTS FOR CURRENT CROSS SECTION */
/* SOURCE conduit.for:1766 */
/*<       if(npntu.gt.1)then >*/
    if (xscomu_1.npntu > 1) {
/*       FIND THE MAXIMUM AND MINIMUM ARGUMENT VALUES */
/* SOURCE conduit.for:1768 */
/*<       zminu=9999999. >*/
	xscomu_1.zminu = (float)9999999.;
/* SOURCE conduit.for:1769 */
/*<       zmaxu=-9999999. >*/
	xscomu_1.zmaxu = (float)-9999999.;
/* SOURCE conduit.for:1770 */
/*<       do150j=1,npntu >*/
	feq_gen_i_d_1 = xscomu_1.npntu;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE conduit.for:1771 */
/*<       if(zu(j).gt.zmaxu)zmaxu=zu(j) >*/
	    if (xscomu_1.zu[j - 1] > xscomu_1.zmaxu) {
		xscomu_1.zmaxu = xscomu_1.zu[j - 1];
	    }
/* SOURCE conduit.for:1772 */
/*<       if(zu(j).lt.zminu)zminu=zu(j) >*/
	    if (xscomu_1.zu[j - 1] < xscomu_1.zminu) {
		xscomu_1.zminu = xscomu_1.zu[j - 1];
	    }
/* SOURCE conduit.for:1773 */
/*<   150 continue >*/
/* L150: */
	}
/* SOURCE conduit.for:1776 */
/*<        >*/
	cxstab_(stdout, &xscomu_1.nsubu, &xscomu_1.navmu, nfac, &
		xscomu_1.mxpntu, &left, &right, betopt, &xscomu_1.snflgu, 
		xscomu_1.nvaru, xscomu_1.natyu, xscomu_1.yatnu, xscomu_1.nnyu,
		 &xscomu_1.npntu, &xscomu_1.zminu, &xscomu_1.zmaxu, 
		xscomu_1.xu, xscomu_1.zu, xscomu_1.sbu, eflag, xscomu_1.lsnu, 
		xscomu_1.snu, xscomu_1.nu, &xscomu_1.ndepu, xscomu_1.xstu, (
		ftnlen)8);
/* SOURCE conduit.for:1781 */
/*<       endif >*/
    }
/*     FORCE THE CONVEYANCE TO BE MONOTONE INCREASING. */
/*     limiting the maximum conveyance to the full-flow conveyance. */
/*     The flow near the crown of the opening is of an uncertain */
/*     character in most cases. */
/* SOURCE conduit.for:1788 */
/*<       if(nocm.eq.1)then >*/
    if (nrdzcm_1.nocm == 1) {
/*       Find start of the slot. */
/* SOURCE conduit.for:1790 */
/*<       do168j=ndepu-2,2,-1 >*/
	for (j = xscomu_1.ndepu - 2; j >= 2; --j) {
/* SOURCE conduit.for:1791 */
/*<       if(xstu(j-1,2).gt.xstu(j,2))then >*/
	    if (xscomu_1.xstu[j + 997] > xscomu_1.xstu[j + 998]) {
/*           J is the entrance to the top slot */
/* SOURCE conduit.for:1793 */
/*<       goto169 >*/
		goto L169;
/* SOURCE conduit.for:1794 */
/*<       endif >*/
	    }
/* SOURCE conduit.for:1795 */
/*<   168 continue >*/
/* L168: */
	}
/* SOURCE conduit.for:1796 */
/*<   169 continue >*/
L169:
/* SOURCE conduit.for:1797 */
/*<       maxk=xstu(j,5) >*/
	maxk = xscomu_1.xstu[j + 3995];
/* SOURCE conduit.for:1798 */
/*<       do170j=2,ndepu >*/
	feq_gen_i_d_1 = xscomu_1.ndepu;
	for (j = 2; j <= feq_gen_i_d_1; ++j) {
/* SOURCE conduit.for:1799 */
/*<       if(xstu(j-1,5).gt.maxk)then >*/
	    if (xscomu_1.xstu[j + 3994] > maxk) {
/* SOURCE conduit.for:1800 */
/*<       xstu(j-1,5)=maxk >*/
		xscomu_1.xstu[j + 3994] = maxk;
/* SOURCE conduit.for:1801 */
/*<       endif >*/
	    }
/* SOURCE conduit.for:1802 */
/*<   170 continue >*/
/* L170: */
	}
/* SOURCE conduit.for:1803 */
/*<       endif >*/
    }
/*     OUTPUT THE TABLE IF NO ERRORS AND IF OUTPUT IS REQUESTED */
/* SOURCE conduit.for:1807 */
/*<       if(eflag.ne.0.or.tabu.eq.0)goto200 >*/
    if (*eflag != 0 || xscomu_1.tabu == 0) {
	goto L200;
    }
/*        IF(ABS(ZMINU).LT.0.001) ZMINU = 0.0 */
/*     compute derivatives of square root of conveyance, alpha, beta, */
/*     da, and dq */
/* SOURCE conduit.for:1813 */
/*<        >*/
    xsecfit_(stdout, &feq_gen_c_d_0, &xscomu_1.ndepu, xscomu_1.xstu, khflag, alphaflag,
	     betaflag, maflag, mqflag, (ftnlen)1, (ftnlen)1, (ftnlen)1, (
	    ftnlen)1, (ftnlen)1);
/* SOURCE conduit.for:1818 */
/*<        >*/
    tabout_(stdout, stdtab, &xscomu_1.tabu, &xscomu_1.statu, &xscomu_1.zminu, 
	    &feq_gen_c_d_0, savopt, outopt, betopt, zone, hgrid, vdatum, unitsys, 
	    basis, khflag, alphaflag, betaflag, maflag, mqflag, &
	    xscomu_1.ndepu, xscomu_1.xstu, ftp, (ftnlen)8, (ftnlen)8, (ftnlen)
	    8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)
	    1, (ftnlen)1, (ftnlen)1, (ftnlen)1, (ftnlen)1);
/* SOURCE conduit.for:1823 */
/*<   200 continue >*/
L200:
/* SOURCE conduit.for:1824 */
/*<       return >*/
    return 0;
/* SOURCE conduit.for:1825 */
/*<   991 continue >*/
L991:
/* SOURCE conduit.for:1826 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__267.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__267);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE conduit.for:1827 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__268.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__268);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE conduit.for:1828 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE conduit.for:1829 */
/*<       end >*/
    return 0;
} /* sewer_ */




/* SOURCE conduit.for:1833 */
/*<       subroutinemkpipe(xoff,zoff,nsides,d,wslot,hslot,npnts,x,z) >*/
/* Subroutine */ int mkpipe_(real *xoff, real *zoff, integer *nsides, real *
	feq_gen_d_d_, real *wslot, real *hslot, integer *npnts, real *feq_storage_x, real *feq_gen_feq_storage_z_d_)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    double sin(doublereal), sqrt(doublereal), cos(doublereal);

    /* Local variables */
    doublereal a;
    integer feq_gen_i_d_;
    doublereal feq_gen_r_d_;
    real xl, zl;
    doublereal theta;

/*     + + + PURPOSE + + + */
/*     Construct polygon with NSIDES with slot added.  The slot */
/*     height is measured from the same datum as is ZOFF. */
/* SOURCE conduit.for:1841 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE conduit.for:1844 */
/*<       integernpnts,nsides >*/
/* SOURCE conduit.for:1845 */
/*<       reald,hslot,wslot,x(*),xoff,z(*),zoff >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     XOFF   - Offset between conduits to prevent overlap */
/*     ZOFF   - Vertical offset of invert from culvert datum */
/*     NSIDES - Number of sides in the approximating polygon */
/*     D      - Maximum vertical extent of a closed conduit */
/*     WSLOT  - Width of slot in closed conduit to preserve free surface */
/*     HSLOT  - Height of slot for a closed conduit */
/*     NPNTS  - Number of points on boundary of a cross section */
/*     X      - Offsets of points on cross section boundary */
/*     Z      - Elevation at points on cross section boundary */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE conduit.for:1859 */
/*<       integeri >*/
/* SOURCE conduit.for:1860 */
/*<       realxl,zl >*/
/* SOURCE conduit.for:1861 */
/*<       doubleprecisiona,r,theta >*/
/*     + + + INTRINSICS + + + */
/* SOURCE conduit.for:1864 */
/*<       intrinsiccos,dble,sin,sqrt >*/
/* *********************************************************************** */
/*     FIND CENTRAL ANGLE-- 2*PI = 6.283185307179586D0 */
/* SOURCE conduit.for:1868 */
/*<       theta=6.283185307179586d0/dble(nsides) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    /* Function Body */
    // Independently verified original conduit coordinates and REAL stores.
    feq_conduit_boundary(1,*nsides,*feq_gen_d_d_,*feq_gen_d_d_,*wslot,*hslot,*xoff,*zoff,nullptr,nullptr,npnts,&x[1],&feq_gen_z_d_[1]);
    return 0;
/* SOURCE conduit.for:1908 */
/*<       end >*/
} /* mkpipe_ */




/* SOURCE conduit.for:1912 */
/*<        >*/
/* Subroutine */ int setmud_(integer *stdout, integer *istart, integer *
	maxpnt, real *nmud, real *ncon, real *zmud, real *zeps, integer *npnt,
	 real *feq_storage_x, real *feq_gen_feq_storage_z_d_, real *feq_storage_lsn, integer *feq_storage_sb, integer *eflag)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *ERR:681* Space of\002,i5,\002 points in S\
ETMUD too small.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer feq_gen_i_d_, np;
    real xl, zl, xr, zr;
    integer ileft;
    real xleft, zleft, zmudl, zmudr;
    integer exactl, exactr, iright;
    real xright, zright;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__290 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__291 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Set a mud line into a simple cross section shape.  SETMUD */
/*     assumes that there will be only two intersections: one on the */
/*     left and one on the right.  It also assumes that the mud line */
/*     is really present, i. e. it will report a bug if called */
/*     with a mudline level that matches the minimum point in the */
/*     cross section boundary. */
/* SOURCE conduit.for:1925 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE conduit.for:1928 */
/*<       integereflag,istart,maxpnt,npnt,stdout >*/
/* SOURCE conduit.for:1929 */
/*<       integersb(maxpnt) >*/
/* SOURCE conduit.for:1930 */
/*<       reallsn(maxpnt),ncon,nmud,x(maxpnt),z(maxpnt),zeps,zmud >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     ISTART - Start point for a conduit cross section description */
/*     MAXPNT - Maximum number of tabulated values in a cross section */
/*               function table */
/*     NMUD   - Manning;s n for the mud line surface */
/*     NCON   - Manning's n value for the conduit */
/*     ZMUD   - Elevation of mud line */
/*     ZEPS   - Increment in elevation used to put a slope on the */
/*               mudline */
/*     NPNT   - Number of points on boundary of a cross section */
/*     X      - Offsets of points on cross section boundary */
/*     Z      - Elevation at points on cross section boundary */
/*     LSN    - Line segment Manning's n value */
/*     SB     - Subsection numbers for the line segments */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE conduit.for:1950 */
/*<       integerexactl,exactr,i,ileft,iright,np >*/
/* SOURCE conduit.for:1951 */
/*<       realxl,xleft,xr,xright,zl,zleft,zmudl,zmudr,zr,zright >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE conduit.for:1954 */
/*<    50 format(' *ERR:681* Space of',i5,' points in SETMUD too small.') >*/
/* *********************************************************************** */
/*     PUT SOME SLOPE ON THE MUD LINE TO PREVENT LATER CODE FROM */
/*     ADJUSTING ONE END TO PREVENT A HORIZONTAL LINE IN THE CROSS */
/*     SECTION BOUNDARY THAT IS NOT AT THE MINIMUM ELEVATION IN THE */
/*     CROSS SECTION. */
/* SOURCE conduit.for:1961 */
/*<       zmudl=zmud+zeps >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> sb(feq_storage_sb, 1);

    feq::IndexedPointer<real> lsn(feq_storage_lsn, 1);

    feq::IndexedPointer<real> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    /* Function Body */
/* L50: */
    zmudl = static_cast<double>(*zmud) + *zeps;
/* SOURCE conduit.for:1962 */
/*<       zmudr=zmud-zeps >*/
    zmudr = static_cast<double>(*zmud) - *zeps;
/*     SCAN THE LINE SEGMENTS UNTIL A LEFT AND RIGHT INTERSECTION WITH */
/*     THE MUD LINE LEVEL HAVE BEEN FOUND.  THE LEFT INTERSECTION WILL */
/*     BE FOUND FIRST. */
/* SOURCE conduit.for:1968 */
/*<       xl=x(istart) >*/
    xl = x[*istart];
/* SOURCE conduit.for:1969 */
/*<       zl=z(istart) >*/
    zl = feq_gen_z_d_[*istart];
/* SOURCE conduit.for:1970 */
/*<       do100i=istart+1,istart+npnt-1 >*/
    feq_gen_i_d_1 = *istart + *npnt - 1;
    for (feq_gen_i_d_ = *istart + 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE conduit.for:1971 */
/*<       xr=x(i) >*/
	xr = x[feq_gen_i_d_];
/* SOURCE conduit.for:1972 */
/*<       zr=z(i) >*/
	zr = feq_gen_z_d_[feq_gen_i_d_];
/* SOURCE conduit.for:1973 */
/*<       if(zl.ge.zmudl.and.zr.lt.zmudl)then >*/
	if (zl >= zmudl && zr < zmudl) {
/*         FOUND LEFT INTERSECTION */
/* SOURCE conduit.for:1975 */
/*<       if(zl.eq.zmudl)then >*/
	    if (zl == zmudl) {
/* SOURCE conduit.for:1976 */
/*<       exactl=1 >*/
		exactl = 1;
/* SOURCE conduit.for:1977 */
/*<       ileft=i-1 >*/
		ileft = feq_gen_i_d_ - 1;
/* SOURCE conduit.for:1978 */
/*<       else >*/
	    } else {
/* SOURCE conduit.for:1979 */
/*<       exactl=0 >*/
		exactl = 0;
/* SOURCE conduit.for:1980 */
/*<       ileft=i-1 >*/
		ileft = feq_gen_i_d_ - 1;
/* SOURCE conduit.for:1981 */
/*<       zleft=zmudl >*/
		zleft = zmudl;
/* SOURCE conduit.for:1982 */
/*<       xleft=xl+(zleft-zl)*(xr-xl)/(zr-zl) >*/
		xleft = static_cast<double>(xl) + static_cast<double>(static_cast<double>((static_cast<double>(zleft) - zl)) * (static_cast<double>(xr) - xl)) / (static_cast<double>(zr) - zl);
/* SOURCE conduit.for:1983 */
/*<       endif >*/
	    }
/* SOURCE conduit.for:1984 */
/*<       endif >*/
	}
/* SOURCE conduit.for:1985 */
/*<       if(zr.ge.zmudr.and.zl.lt.zmudr)then >*/
	if (zr >= zmudr && zl < zmudr) {
/*         FOUND INTERSECTION ON RIGHT */
/* SOURCE conduit.for:1987 */
/*<       if(zr.eq.zmudr)then >*/
	    if (zr == zmudr) {
/* SOURCE conduit.for:1988 */
/*<       exactr=1 >*/
		exactr = 1;
/* SOURCE conduit.for:1989 */
/*<       iright=i >*/
		iright = feq_gen_i_d_;
/* SOURCE conduit.for:1990 */
/*<       else >*/
	    } else {
/* SOURCE conduit.for:1991 */
/*<       exactr=0 >*/
		exactr = 0;
/* SOURCE conduit.for:1992 */
/*<       iright=i >*/
		iright = feq_gen_i_d_;
/* SOURCE conduit.for:1993 */
/*<       zright=zmudr >*/
		zright = zmudr;
/* SOURCE conduit.for:1994 */
/*<       xright=xl+(zright-zl)*(xr-xl)/(zr-zl) >*/
		xright = static_cast<double>(xl) + static_cast<double>(static_cast<double>((static_cast<double>(zright) - zl)) * (static_cast<double>(xr) - xl)) / (static_cast<double>(zr) - zl);
/* SOURCE conduit.for:1995 */
/*<       endif >*/
	    }
/*         BOTH INTERSECTIONS HAVE BEEN FOUND. EXIT THE LOOP. */
/* SOURCE conduit.for:1997 */
/*<       goto110 >*/
	    goto L110;
/* SOURCE conduit.for:1998 */
/*<       endif >*/
	}
/* SOURCE conduit.for:1999 */
/*<       xl=xr >*/
	xl = xr;
/* SOURCE conduit.for:2000 */
/*<       zl=zr >*/
	zl = zr;
/* SOURCE conduit.for:2001 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE conduit.for:2003 */
/*<       write(stdout,*)' *BUG:XXX* Intersection failure in SETMUD.' >*/
    feq_gen_io_d__290.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__290);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* Intersection failure in SETMUD."), (
	    ftnlen)42);
    e_wsle();
/* SOURCE conduit.for:2004 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE conduit.for:2006 */
/*<   110 continue >*/
L110:
/*      WRITE(STDOUT,*) ' ILEFT=',ILEFT,' EXACTL=',EXACTL */
/*      IF(EXACTL.EQ.0) THEN */
/*        WRITE(STDOUT,*) ' XLEFT=',XLEFT,' ZLEFT=',ZLEFT */
/*      ENDIF */
/*      WRITE(STDOUT,*) ' IRIGHT=',IRIGHT,' EXACTR=',EXACTR */
/*      IF(EXACTR.EQ.0) THEN */
/*        WRITE(STDOUT,*) ' XRIGHT=',XRIGHT,' ZRIGHT=',ZRIGHT */
/*      ENDIF */
/*     ADJUST THE CROSS SECTION DESCRIPTION TO INCLUDE THE MUD LINE. */
/*     MAKE ROOM FOR ADDED POINTS. */
/* SOURCE conduit.for:2020 */
/*<       if(iright-ileft.eq.2)then >*/
    if (iright - ileft == 2) {
/*       SHIFT DATA TO MAKE ROOM FOR POSSIBLE ADDITION OF TWO POINTS */
/*       WHEN ONLY SPACE FOR ONE EXISTS. */
/* SOURCE conduit.for:2024 */
/*<       if(istart+npnt.gt.maxpnt)then >*/
	if (*istart + *npnt > *maxpnt) {
/*         NOT ENOUGH ROOM LEFT IN THE VECTORS */
/* SOURCE conduit.for:2026 */
/*<       write(stdout,50)maxpnt >*/
	    feq_gen_io_d__291.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__291);
	    do_fio(&feq_gen_c_d_1, (char *)&(*maxpnt), (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE conduit.for:2027 */
/*<       eflag=eflag+1 >*/
	    ++(*eflag);
/* SOURCE conduit.for:2028 */
/*<       return >*/
	    return 0;
/* SOURCE conduit.for:2029 */
/*<       endif >*/
	}
/* SOURCE conduit.for:2031 */
/*<       do200i=istart+npnt-1,iright,-1 >*/
	feq_gen_i_d_1 = iright;
	for (feq_gen_i_d_ = *istart + *npnt - 1; feq_gen_i_d_ >= feq_gen_i_d_1; --feq_gen_i_d_) {
/* SOURCE conduit.for:2032 */
/*<       x(i+1)=x(i) >*/
	    x[feq_gen_i_d_ + 1] = x[feq_gen_i_d_];
/* SOURCE conduit.for:2033 */
/*<       z(i+1)=z(i) >*/
	    feq_gen_z_d_[feq_gen_i_d_ + 1] = feq_gen_z_d_[feq_gen_i_d_];
/* SOURCE conduit.for:2034 */
/*<       sb(i+1)=sb(i) >*/
	    sb[feq_gen_i_d_ + 1] = sb[feq_gen_i_d_];
/* SOURCE conduit.for:2035 */
/*<       lsn(i+1)=lsn(i) >*/
	    lsn[feq_gen_i_d_ + 1] = lsn[feq_gen_i_d_];
/* SOURCE conduit.for:2036 */
/*<   200 continue >*/
/* L200: */
	}
/* SOURCE conduit.for:2037 */
/*<       iright=iright+1 >*/
	++iright;
/* SOURCE conduit.for:2038 */
/*<       endif >*/
    }
/*     SET INITIAL POINTER TO THE LAST VALID POINT */
/* SOURCE conduit.for:2042 */
/*<       np=ileft >*/
    np = ileft;
/* SOURCE conduit.for:2043 */
/*<       if(exactl.eq.0)then >*/
    if (exactl == 0) {
/*       TRANSFER THE ADDITIONAL LEFT INTERSECTION POINT */
/* SOURCE conduit.for:2045 */
/*<       np=np+1 >*/
	++np;
/* SOURCE conduit.for:2046 */
/*<       x(np)=xleft >*/
	x[np] = xleft;
/* SOURCE conduit.for:2047 */
/*<       z(np)=zleft >*/
	feq_gen_z_d_[np] = zleft;
/* SOURCE conduit.for:2048 */
/*<       sb(np)=sb(np-1) >*/
	sb[np] = sb[np - 1];
/* SOURCE conduit.for:2049 */
/*<       lsn(np)=nmud >*/
	lsn[np] = *nmud;
/* SOURCE conduit.for:2050 */
/*<       else >*/
    } else {
/*       EXACT MATCH-NO ADDITIONAL POINT TO TRANSFER. ADJUST N VALUE. */
/* SOURCE conduit.for:2052 */
/*<       lsn(np)=nmud >*/
	lsn[np] = *nmud;
/* SOURCE conduit.for:2053 */
/*<       endif >*/
    }
/* SOURCE conduit.for:2055 */
/*<       if(exactr.eq.0)then >*/
    if (exactr == 0) {
/*       TRANSFER THE ADDITIONAL RIGHT INTERSECTION POINT */
/* SOURCE conduit.for:2057 */
/*<       np=np+1 >*/
	++np;
/* SOURCE conduit.for:2058 */
/*<       x(np)=xright >*/
	x[np] = xright;
/* SOURCE conduit.for:2059 */
/*<       z(np)=zright >*/
	feq_gen_z_d_[np] = zright;
/* SOURCE conduit.for:2060 */
/*<       sb(np)=sb(np-1) >*/
	sb[np] = sb[np - 1];
/* SOURCE conduit.for:2061 */
/*<       lsn(np)=ncon >*/
	lsn[np] = *ncon;
/* SOURCE conduit.for:2062 */
/*<       endif >*/
    }
/*     TRANSFER THE REMAINING POINTS */
/* SOURCE conduit.for:2065 */
/*<       do300i=iright,istart+npnt-1 >*/
    feq_gen_i_d_1 = *istart + *npnt - 1;
    for (feq_gen_i_d_ = iright; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE conduit.for:2066 */
/*<       np=np+1 >*/
	++np;
/* SOURCE conduit.for:2067 */
/*<       x(np)=x(i) >*/
	x[np] = x[feq_gen_i_d_];
/* SOURCE conduit.for:2068 */
/*<       z(np)=z(i) >*/
	feq_gen_z_d_[np] = feq_gen_z_d_[feq_gen_i_d_];
/* SOURCE conduit.for:2069 */
/*<       sb(np)=sb(i) >*/
	sb[np] = sb[feq_gen_i_d_];
/* SOURCE conduit.for:2070 */
/*<       lsn(np)=lsn(i) >*/
	lsn[np] = lsn[feq_gen_i_d_];
/* SOURCE conduit.for:2071 */
/*<   300 continue >*/
/* L300: */
    }
/*     CHANGE THE NUMBER OF POINTS */
/* SOURCE conduit.for:2075 */
/*<       npnt=np-istart+1 >*/
    *npnt = np - *istart + 1;
/*      WRITE(STDOUT,999) */
/* 999   FORMAT('    OFFSET ELEVATION SUB# ROUGHNESS') */
/*      DO 400 I=ISTART,ISTART+NPNT-1 */
/*        WRITE(STDOUT,1000) X(I), Z(I), SB(I), LSN(I) */
/* 1000  FORMAT(F10.4,F10.3,I5,F10.3) */
/* SOURCE conduit.for:2082 */
/*<   400 continue >*/
/* L400: */
/* SOURCE conduit.for:2083 */
/*<       return >*/
    return 0;
/* SOURCE conduit.for:2084 */
/*<       end >*/
} /* setmud_ */




/* SOURCE conduit.for:2088 */
/*<       subroutinesetsub(isub,npnt,istart,n,sbu,lsn) >*/
/* Subroutine */ int setsub_(integer *isub, integer *npnt, integer *istart, 
	real *n, integer *feq_storage_sbu, real *feq_storage_lsn)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer j;

/*     + + + PURPOSE + + + */
/*     Set the subsection and line segment roughness */
/*     for a multiple conduit system. */
/* SOURCE conduit.for:2096 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE conduit.for:2099 */
/*<       integeristart,isub,npnt >*/
/* SOURCE conduit.for:2100 */
/*<       integersbu(*) >*/
/* SOURCE conduit.for:2101 */
/*<       reallsn(*),n >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ISUB   - Subsection number to assign */
/*     NPNT   - Number of points on boundary of a cross section */
/*     ISTART - Start point for a conduit cross section description */
/*     N      - Manning's n value */
/*     SBU    - Subsection numbers for the line segments-upstream */
/*               location */
/*     LSN    - Line segment Manning's n value */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE conduit.for:2113 */
/*<       integerj >*/
/* *********************************************************************** */
/* SOURCE conduit.for:2115 */
/*<       do400j=1,npnt >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> lsn(feq_storage_lsn, 1);

    feq::IndexedPointer<integer> sbu(feq_storage_sbu, 1);

    /* Function Body */
    feq_gen_i_d_1 = *npnt;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE conduit.for:2116 */
/*<       sbu(istart+j-1)=isub >*/
	sbu[*istart + j - 1] = *isub;
/* SOURCE conduit.for:2117 */
/*<       lsn(istart+j-1)=n >*/
	lsn[*istart + j - 1] = *n;
/* SOURCE conduit.for:2118 */
/*<   400 continue >*/
/* L400: */
    }
/* SOURCE conduit.for:2120 */
/*<       return >*/
    return 0;
/* SOURCE conduit.for:2121 */
/*<       end >*/
} /* setsub_ */




/* SOURCE conduit.for:2125 */
/*<       subroutinemkbox(xoff,zoff,span,rise,wslot,hslot,npnts,x,z) >*/
/* Subroutine */ int mkbox_(real *xoff, real *zoff, real *span, real *rise, 
	real *wslot, real *hslot, integer *npnts, real *feq_storage_x, real *feq_gen_feq_storage_z_d_)
{
    /* Initialized data */

    static integer n = 18;

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    real feq_gen_h_d_;
    integer feq_gen_i_d_, ii;
    real div;

/*     + + + PURPOSE + + + */
/*     Construct a box culvert of width, SPAN, and height, RISE. */
/*     RISE is measured from the bottom of the culvert.  ZOFF */
/*     gives the height of the bottom of the culvert above some */
/*     datum used to reference the other conduits in the multiple */
/*     conduit system.  Height of slot, HSLOT, is measured from the */
/*     same datum as is ZOFF. */
/* SOURCE conduit.for:2137 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE conduit.for:2140 */
/*<       integernpnts >*/
/* SOURCE conduit.for:2141 */
/*<       realhslot,rise,span,wslot,x(*),xoff,z(*),zoff >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     XOFF   - Offset between conduits to prevent overlap */
/*     ZOFF   - Vertical offset of invert from culvert datum */
/*     SPAN   - Maximum horizontal extent of a closed conduit */
/*     RISE   - Maximum vertical extent of a conduit */
/*     WSLOT  - Width of slot in closed conduit to preserve free surface */
/*     HSLOT  - Height of slot for a closed conduit */
/*     NPNTS  - Number of points on boundary of a cross section */
/*     X      - Offsets of points on cross section boundary */
/*     Z      - Elevation at points on cross section boundary */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE conduit.for:2155 */
/*<       integeri,ii,n >*/
/* SOURCE conduit.for:2157 */
/*<       realh,div,pi >*/
/*     + + + DATA INITIALIZATIONS + + + */
/* *********************************************************************** */
/*     ADD AN EXTRA POINT WHICH IS LATER DELETED TO REMOVE NOISE FROM */
/*     THE TOP OF THE SLOT */
/* SOURCE conduit.for:2160 */
/*<       datan/18/,pi/3.14159265/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> feq_gen_z_d_(feq_gen_feq_storage_z_d_, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    /* Function Body */
/* SOURCE conduit.for:2166 */
/*<       x(1)=-0.5*wslot+xoff >*/
    // Independently verified original conduit coordinates and REAL stores.
    feq_conduit_boundary(2,0,*rise,*span,*wslot,*hslot,*xoff,*zoff,nullptr,nullptr,npnts,&x[1],&feq_gen_z_d_[1]);
    return 0;
/* SOURCE conduit.for:2209 */
/*<       end >*/
} /* mkbox_ */




/* SOURCE conduit.for:2213 */
/*<        >*/
/* Subroutine */ int rharch_(integer *stdout, integer *np, real *feq_storage_rsvec, real *
	feq_storage_spvec, real *feq_storage_r1vec, real *feq_storage_r3vec, real *cfac, real *rise, real *span, 
	integer *eflag, integer *nrh, real *feq_storage_rhx, real *feq_storage_rhy, real *a)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *ERR:571* RISE=\002,f8.3,\002 < MIN RISE\
=\002,f8.3,\002 OR  > MAX RISE=\002,f8.3)";
    static char fmt_52[] = "(\002 *WRN:527* GIVEN SPAN=\002,f8.3,\002 DIFFER\
S FROM TABLE SPAN=\002,f8.3,\002 BY > 2%\002)";
    static char fmt_54[] = "(\002 *BUG:505* SPAN AND RISE=0.0 IN SUBROUTINE \
RHARCH.\002)";
    static char fmt_56[] = "(\002 *ERR:572* SPAN=\002,f8.3,\002 < MIN SPAN\
=\002,f8.3,\002 OR > MAX SPAN=\002,f8.3)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3, feq_gen_r_d_4, feq_gen_r_d_5, feq_gen_r_d_6, feq_gen_r_d_7;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal), asin(doublereal), sin(doublereal), cos(
	    doublereal);

    /* Local variables */
    real b, feq_gen_c_d_;
    integer feq_gen_i_d_;
    real p, r1, r2, r3;
    doublereal ea;
    real ta, sp, rs, fac, phi, alpha, omega, theta, dalpha;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__300 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__304 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__307 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__309 = { 0, 0, 0, fmt_54, 0 };


/*     + + + PURPOSE + + + */
/*     Compute the points on the right-hand semi-perimeter of an */
/*     arch pipe.  The nature of the arch is defined in the */
/*     four vectors that describe the standard parameters for an */
/*     arch pipe: Rise, Span, radius of the two corners, and the */
/*     radius of the bottom.  The other paramters are computed from */
/*     these to force the parameter set to be consistent with the */
/*     ideal geometry of these pipes.  Adjust the points so that the */
/*     area of the resulting ploygon approximating the perimeter matches */
/*     the area computed from the parameters describing the shape of the */
/*     arch pipe. */
/* SOURCE conduit.for:2230 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE conduit.for:2233 */
/*<       integereflag,np,nrh,stdout >*/
/* SOURCE conduit.for:2234 */
/*<        >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     NP     - number of points on the boundary */
/*     RSVEC  - vector of conduit rises */
/*     SPVEC  - vector of conduit spans */
/*     R1VEC  - vector of invert radi */
/*     R3VEC  - vector of corner radi */
/*     CFAC   - conversion factor from source units(feet or meters) */
/*              to inches, the unit used in the standard tables */
/*     RISE   - Maximum vertical extent of a conduit */
/*     SPAN   - Maximum horizontal extent of a closed conduit */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     NRH    - Number of points on the right-hand semi-perimeter */
/*     RHX    - Right hand semi-perimeter offset values */
/*     RHY    - Right hand semi-perimeter ordinate values */
/*     A      - offset of conduit soffit center from invert */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE conduit.for:2255 */
/*<       integeri >*/
/* SOURCE conduit.for:2256 */
/*<       realalpha,b,c,dalpha,fac,omega,p,phi,r1,r2,r3,rs,sp,ta,theta >*/
/* SOURCE conduit.for:2258 */
/*<       doubleprecisionea >*/
/*     + + + INTRINSICS + + + */
/* SOURCE conduit.for:2261 */
/*<       intrinsicabs,asin,cos,sin,sqrt >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE conduit.for:2264 */
/*<    50  >*/
/* SOURCE conduit.for:2266 */
/*<    52  >*/
/* SOURCE conduit.for:2268 */
/*<    54 format(' *BUG:505* SPAN AND RISE=0.0 IN SUBROUTINE RHARCH.') >*/
/* SOURCE conduit.for:2269 */
/*<    56  >*/
/* *********************************************************************** */
/*     CONVERT RISE AND SPAN TO INCHES FOR TABLE LOOKUP */
/* SOURCE conduit.for:2273 */
/*<       rise=cfac*rise >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> r3vec(feq_storage_r3vec, 1);

    feq::IndexedPointer<real> r1vec(feq_storage_r1vec, 1);

    feq::IndexedPointer<real> spvec(feq_storage_spvec, 1);

    feq::IndexedPointer<real> rsvec(feq_storage_rsvec, 1);

    feq::IndexedPointer<real> rhx(feq_storage_rhx, 1);

    feq::IndexedPointer<real> rhy(feq_storage_rhy, 1);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
/* L56: */
    
    // Original-verified standard interpolation, legacy ASIN, and arch geometry.
    if (*rise <= 0.0F && *span <= 0.0F) {
        feq_gen_io_d__309.ciunit = *stdout;
        s_wsfe(&feq_gen_io_d__309);
        e_wsfe();
        s_stop(const_cast<char*>("Abnormal stop. Errors found."),static_cast<ftnlen>(28));
        return 0;
    }
    int feq_span_warning = 0;
    float feq_warning_values[2] = {};
    const int feq_arch_error = feq_arch_perimeter(*np,&rsvec[1],&spvec[1],&r1vec[1],&r3vec[1],
        *cfac,rise,span,nrh,&rhx[1],&rhy[1],a,&feq_span_warning,feq_warning_values);
    if (feq_arch_error != 0) {
        cilist* feq_error_format = feq_arch_error == 571 ? &feq_gen_io_d__300 : &feq_gen_io_d__307;
        feq_error_format->ciunit = *stdout;
        feq_gen_r_d_1 = static_cast<double>(feq_arch_error == 571 ? *rise : *span)/ *cfac;
        feq_gen_r_d_2 = static_cast<double>(feq_arch_error == 571 ? rsvec[1] : spvec[1])/ *cfac;
        feq_gen_r_d_3 = static_cast<double>(feq_arch_error == 571 ? rsvec[*np] : spvec[*np])/ *cfac;
        s_wsfe(feq_error_format);
        do_fio(&feq_gen_c_d_1,reinterpret_cast<char*>(&feq_gen_r_d_1),static_cast<ftnlen>(sizeof(real)));
        do_fio(&feq_gen_c_d_1,reinterpret_cast<char*>(&feq_gen_r_d_2),static_cast<ftnlen>(sizeof(real)));
        do_fio(&feq_gen_c_d_1,reinterpret_cast<char*>(&feq_gen_r_d_3),static_cast<ftnlen>(sizeof(real)));
        e_wsfe();
        *eflag = 1;
        return 0;
    }
    if (feq_span_warning != 0) {
        feq_gen_io_d__304.ciunit = *stdout;
        s_wsfe(&feq_gen_io_d__304);
        do_fio(&feq_gen_c_d_1,reinterpret_cast<char*>(&feq_warning_values[0]),static_cast<ftnlen>(sizeof(real)));
        do_fio(&feq_gen_c_d_1,reinterpret_cast<char*>(&feq_warning_values[1]),static_cast<ftnlen>(sizeof(real)));
        e_wsfe();
    }
    return 0;
/* SOURCE conduit.for:2421 */
/*<       end >*/
} /* rharch_ */




/* SOURCE conduit.for:2425 */
/*<       subroutinerhmak(wslot,hslot,yoff,xoff,nrh,rhx,rhy,x,y,npnts) >*/
/* Subroutine */ int rhmak_(real *wslot, real *hslot, real *yoff, real *xoff, 
	integer *nrh, real *feq_storage_rhx, real *feq_storage_rhy, real *feq_storage_x, real *feq_storage_y, integer *npnts)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j;
    real xr, yr;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__321 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Construct a closed conduit shape given the right half of the */
/*     shape, i. e. the right hand semi-perimeter.  Use */
/*     methods similar to those in URQMAK. */
/* SOURCE conduit.for:2434 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE conduit.for:2437 */
/*<       integernpnts,nrh >*/
/* SOURCE conduit.for:2438 */
/*<       realhslot,rhx(*),rhy(*),wslot,x(*),xoff,y(*),yoff >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     WSLOT  - Width of slot in closed conduit to preserve free surface */
/*     HSLOT  - Height of slot for a closed conduit */
/*     YOFF   - Vertical offset to construct complete shape from */
/*               the right semi-perimeter */
/*     XOFF   - Offset for defining the conduit shape from the */
/*               right hand semi-perimeter */
/*     NRH    - Number of points on the right-hand semi-perimeter */
/*     RHX    - Right hand semi-perimeter offset values */
/*     RHY    - Right hand semi-perimeter ordinate values */
/*     X      - Offsets of points on cross section boundary */
/*     Y      - ordinate values on boundary of conduit */
/*     NPNTS  - Number of points on boundary of a cross section */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE conduit.for:2455 */
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
/* SOURCE conduit.for:2458 */
/*<       integeri,j >*/
/* SOURCE conduit.for:2459 */
/*<       realxr,yr >*/
/* *********************************************************************** */
/*     RHX(1) must = 0! */
/* SOURCE conduit.for:2463 */
/*<       if(rhx(2).eq.0.0)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> y(feq_storage_y, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    feq::IndexedPointer<real> rhy(feq_storage_rhy, 1);

    feq::IndexedPointer<real> rhx(feq_storage_rhx, 1);

    /* Function Body */
    if (rhx[2] == (float)0.) {
/* SOURCE conduit.for:2464 */
/*<       write(std6,*)' ZERO DIVIDE 1 IN RHMAK' >*/
	feq_gen_io_d__321.ciunit = feq_gen_stdun_com_d_1.std6;
	s_wsle(&feq_gen_io_d__321);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" ZERO DIVIDE 1 IN RHMAK"), (ftnlen)23);
	e_wsle();
/* SOURCE conduit.for:2465 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE conduit.for:2466 */
/*<       endif >*/
    }
/* SOURCE conduit.for:2467 */
/*<       xr=wslot/2.0 >*/
    // Independently verified original conduit coordinates and REAL stores.
    feq_conduit_boundary(3,*nrh,0.0F,0.0F,*wslot,*hslot,*xoff,*yoff,&rhx[1],&rhy[1],npnts,&x[1],&y[1]);
    return 0;
/* SOURCE conduit.for:2499 */
/*<       end >*/
} /* rhmak_ */




/* SOURCE conduit.for:2503 */
/*<       subroutineurqmak(wslot,hslot,yoff,xoff,nurq,urqx,urqy,x,y,npnts) >*/
/* Subroutine */ int urqmak_(real *wslot, real *hslot, real *yoff, real *xoff,
	 integer *nurq, real *feq_storage_urqx, real *feq_storage_urqy, real *feq_storage_x, real *feq_storage_y, integer *
	npnts)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_, j;
    real xr, yr;

/*     + + + PURPOSE + + + */
/*     Construct a closed conduit shape given the upper right quadrant, */
/*     the slot width, etc describing the conduit and its location */
/*     relative to other conduits and relative to the datum for the */
/*     collection of conduits. */
/* SOURCE conduit.for:2513 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE conduit.for:2516 */
/*<       integernpnts,nurq >*/
/* SOURCE conduit.for:2517 */
/*<       realhslot,urqx(*),urqy(*),wslot,x(*),xoff,y(*),yoff >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     WSLOT  - Width of slot in closed conduit to preserve free surface */
/*     HSLOT  - Height of slot for a closed conduit */
/*     YOFF   - Vertical offset to construct complete shape from */
/*               the upper right quadrant */
/*     XOFF   - Offset for defining the conduit shape from the upper */
/*               right quadrant */
/*     NURQ   - Number of points in the upper right quadrant */
/*     URQX   - Offsets for upper right quadrant of a closed conduit */
/*               shape */
/*     URQY   - Ordinates for upper right quadrant of a closed conduit */
/*               shape */
/*     X      - Offsets of points on cross section boundary */
/*     Y      - ordinate values on boundary of conduit */
/*     NPNTS  - Number of points on boundary of a cross section */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE conduit.for:2536 */
/*<       integeri,j >*/
/* SOURCE conduit.for:2537 */
/*<       realxr,yr >*/
/* *********************************************************************** */
/*     NOTE: URQX(1) must = 0! */
/* SOURCE conduit.for:2541 */
/*<       xr=wslot/2.0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> y(feq_storage_y, 1);

    feq::IndexedPointer<real> x(feq_storage_x, 1);

    feq::IndexedPointer<real> urqy(feq_storage_urqy, 1);

    feq::IndexedPointer<real> urqx(feq_storage_urqx, 1);

    /* Function Body */
    // Independently verified original conduit coordinates and REAL stores.
    feq_conduit_boundary(4,*nurq,0.0F,0.0F,*wslot,*hslot,*xoff,*yoff,&urqx[1],&urqy[1],npnts,&x[1],&y[1]);
    return 0;
/* SOURCE conduit.for:2586 */
/*<       end >*/
} /* urqmak_ */




/* SOURCE conduit.for:2590 */
/*<       subroutineurqte(rise,span,nurq,urqx,urqy) >*/
/* Subroutine */ int urqte_(real *rise, real *span, integer *nurq, real *feq_storage_urqx,
	 real *feq_storage_urqy)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3;

    /* Builtin functions */
    double sin(doublereal), cos(doublereal), sqrt(doublereal);

    /* Local variables */
    real a, b;
    integer feq_gen_i_d_;
    real feq_gen_r_d_;
    doublereal ea;
    real ta, fac, theta;

/*     + + + PURPOSE + + + */
/*     Construct the upper right quadrant from a true elliptical shape. */
/*     RISE and SPAN are any postive numbers. */
/* SOURCE conduit.for:2598 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE conduit.for:2601 */
/*<       integernurq >*/
/* SOURCE conduit.for:2602 */
/*<       realrise,span,urqx(*),urqy(*) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     RISE   - Maximum vertical extent of a conduit */
/*     SPAN   - Maximum horizontal extent of a closed conduit */
/*     NURQ   - Number of points in the upper right quadrant */
/*     URQX   - Offsets for upper right quadrant of a closed conduit */
/*               shape */
/*     URQY   - Ordinates for upper right quadrant of a closed conduit */
/*               shape */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE conduit.for:2614 */
/*<       integeri >*/
/* SOURCE conduit.for:2615 */
/*<       reala,b,fac,r,ta,theta >*/
/* SOURCE conduit.for:2616 */
/*<       doubleprecisionea >*/
/*     + + + INTRINSICS + + + */
/* SOURCE conduit.for:2619 */
/*<       intrinsiccos,sin,sqrt >*/
/* *********************************************************************** */
/* SOURCE conduit.for:2621 */
/*<       a=span/2.0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> urqy(feq_storage_urqy, 1);

    feq::IndexedPointer<real> urqx(feq_storage_urqx, 1);

    /* Function Body */
    // Independently verified original conduit coordinates and REAL stores.
    feq_conduit_boundary(0,0,*rise,*span,0.0F,0.0F,0.0F,0.0F,nullptr,nullptr,nurq,&urqx[1],&urqy[1]);
    return 0;
/* SOURCE conduit.for:2649 */
/*<       end >*/
} /* urqte_ */

#ifdef __cplusplus
	}
#endif
