#include <feq/ritter_flow.hpp>
#include "callbacks.hpp"
/* ritter.f -- translated by f2c (version 20240504).
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

/* COMMON ritcom_ is declared in common.hpp. */

#define ritcom_1 ritcom_

/* COMMON epscom_ is declared in common.hpp. */

#define epscom_1 epscom_

/* COMMON ftable_ is declared in common.hpp. */

#define ftable_1 ftable_

/* COMMON ftablea_ is declared in common.hpp. */

#define ftablea_1 ftablea_

/* COMMON ftablec_ is declared in common.hpp. */

#define ftablec_1 ftablec_

/* COMMON offcom_ is declared in common.hpp. */

#define offcom_1 offcom_

/* Table of constant values */

static integer feq_gen_c_d_0 = 0;
static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_9 = 9;




/* SOURCE ritter.for:4 */
/*<       realfunctionfrit(y) >*/
doublereal frit_(real *y)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
    real feq_gen_c_d_, t, dt, pdv;
    integer ntab;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *), xlookw_(integer *, integer *, real *, real *, 
	    real *, real *, real *, real *);

/*     + + + PURPOSE + + + */
/*     Compute the generalized ritter residual. */
/* SOURCE ritter.for:10 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ritter.for:13 */
/*<       realy >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Y      - maximum depth in a cross section */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ritter.for:19 */
/*     Common for function FRIT in FEQUTL */
/* SOURCE ritcom.cmn:3 */
/*<       integerwtab,qtab,off,ritout >*/
/* SOURCE ritcom.cmn:4 */
/*<       realw1,v1,w,a,q >*/
/* SOURCE ritcom.cmn:5 */
/*<       common/ritcom/w1,v1,w,a,q,wtab,qtab,off,ritout >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ritter.for:22 */
/*<       integerntab >*/
/* SOURCE ritter.for:23 */
/*<       realc,dt,pdv,t >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ritter.for:26 */
/*<       externallktab,xlookw >*/
/* *********************************************************************** */
/*     FIND THE ESCOFFIER VARIABLE AND THE AREA */
/* SOURCE ritter.for:31 */
/*<       callxlookw(wtab,off,y,a,t,dt,c,w) >*/
    xlookw_(&ritcom_1.wtab, &ritcom_1.off, y, &ritcom_1.a, &t, &dt, &feq_gen_c_d_, &
	    ritcom_1.w);
/*     FIND THE FLOW THROUGH THE CONSTRICTION */
/* SOURCE ritter.for:37 */
/*<       calllktab(qtab,y,0,q,ntab,pdv) >*/
    lktab_(&ritcom_1.qtab, y, &feq_gen_c_d_0, &ritcom_1.q, &ntab, &pdv);
/*     COMPUTE THE RESIDUAL */
/* SOURCE ritter.for:43 */
/*<       if(a.le.0.0)a=1.0 >*/
    return feq::ritter_flow_residual(ritcom_1.w1,ritcom_1.v1,
        ritcom_1.w,ritcom_1.q,ritcom_1.a);
} /* frit_ */




/* SOURCE ritter.for:52 */
/*<       subroutinefndrit(stdout,apptab,xoff,contab,y1,q1,ypeak,qpeak) >*/
/* Subroutine */ int fndrit_(integer *stdout, integer *apptab, integer *xoff, 
	integer *contab, real *y1, real *q1, real *ypeak, real *qpeak)
{
    /* Format strings */
    static char fmt_50[] = "(\0020*BUG:504* NO SOLUTION FOR COMMAND GRITTER\
.\002,/,10x,\002 UPPER DEPTH=\002,f10.3,\002 LOWER DEPTH=\002,f10.3)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    real a1, c1, t1, yd, yu, dt1;
    integer feq_gen_flag_d_;
    extern doublereal frit_(real *);
    extern /* Subroutine */ int regfal_(real *, real *, FeqCallback3, real *, real *, 
	    real *, integer *), xlookw_(integer *, integer *, real *, real *, 
	    real *, real *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__13 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Use modified regula falsi to find the generalized Ritter */
/*     flood peak for the given conditions. */
/* SOURCE ritter.for:60 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ritter.for:63 */
/*<       integerapptab,contab,stdout,xoff >*/
/* SOURCE ritter.for:64 */
/*<       realq1,qpeak,y1,ypeak >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     APPTAB - Address of table describing reservoir cross section */
/*     XOFF   - Offset between successive depth values for cross section */
/*               function table */
/*     CONTAB - Address of the table giving the flow through the */
/*               failure opening */
/*     Y1     - Initial maximum depth in reservoir */
/*     Q1     - Flowrate at section 1 */
/*     YPEAK  - Depth at peak outflow from reservoir */
/*     QPEAK  - Peak flow rate */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ritter.for:79 */
/*     Common for function FRIT in FEQUTL */
/* SOURCE ritcom.cmn:3 */
/*<       integerwtab,qtab,off,ritout >*/
/* SOURCE ritcom.cmn:4 */
/*<       realw1,v1,w,a,q >*/
/* SOURCE ritcom.cmn:5 */
/*<       common/ritcom/w1,v1,w,a,q,wtab,qtab,off,ritout >*/
/* INCLUDE ritter.for:80 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ritter.for:83 */
/*<       integerflag >*/
/* SOURCE ritter.for:84 */
/*<       reala1,c1,dt1,t1,yd,yu >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ritter.for:87 */
/*<       externalfrit,regfal,xlookw >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ritter.for:90 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE ritter.for:93 */
/*<       wtab=apptab >*/
/* L50: */
    ritcom_1.wtab = *apptab;
/* SOURCE ritter.for:94 */
/*<       qtab=contab >*/
    ritcom_1.qtab = *contab;
/* SOURCE ritter.for:95 */
/*<       off=xoff >*/
    ritcom_1.off = *xoff;
/* SOURCE ritter.for:96 */
/*<       ritout=stdout >*/
    ritcom_1.ritout = *stdout;
/*     FIND THE VALUES AT THE INITIAL DEPTH IN THE RESERVOIR */
/* SOURCE ritter.for:100 */
/*<       callxlookw(apptab,xoff,y1,a1,t1,dt1,c1,w1) >*/
    xlookw_(apptab, xoff, y1, &a1, &t1, &dt1, &c1, &ritcom_1.w1);
/* SOURCE ritter.for:104 */
/*<       v1=q1/a1 >*/
    ritcom_1.v1 = static_cast<double>(*q1) / a1;
/*     IF THE CRITICAL FLOW RELATIONSHIP IS MONOTONE INCREASING */
/*     WITH DEPTH, THEN THERE SHOULD BE ONLY ONE POSITIVE ROOT */
/*     AND IT SHOULD BE BETWEEN 0 AND Y1 */
/* SOURCE ritter.for:111 */
/*<       yd=0.2*y1 >*/
    yd = static_cast<double>(*y1) * (float).2;
/* SOURCE ritter.for:112 */
/*<       yu=y1 >*/
    yu = *y1;
/* SOURCE ritter.for:114 */
/*<       callregfal(epsarg,epsf,frit,yd,yu,ypeak,flag) >*/
    regfal_(&epscom_1.epsarg, &epscom_1.epsf, frit_, &yd, &yu, ypeak, &
	    feq_gen_flag_d_);
/* SOURCE ritter.for:118 */
/*<       if(flag.ge.1)then >*/
    if (feq_gen_flag_d_ >= 1) {
/*       NO SOLUTION */
/* SOURCE ritter.for:120 */
/*<       write(stdout,50)yd,yu >*/
	feq_gen_io_d__13.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__13);
	do_fio(&feq_gen_c_d_1, (char *)&yd, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&yu, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE ritter.for:121 */
/*<       return >*/
	return 0;
/* SOURCE ritter.for:122 */
/*<       endif >*/
    }
/* SOURCE ritter.for:123 */
/*<       qpeak=q >*/
    *qpeak = ritcom_1.q;
/* SOURCE ritter.for:124 */
/*<       return >*/
    return 0;
/* SOURCE ritter.for:126 */
/*<       end >*/
} /* fndrit_ */




/* SOURCE ritter.for:130 */
/*<       subroutineritter(grav,stdin,stdout,eflag) >*/
/* Subroutine */ int ritter_(real *grav, integer *stdin, integer *stdout, 
	integer *eflag)
{
    feq::RitterWaveStep wave_step{};

    /* Format strings */
    static char fmt_2[] = "(2f10.0)";
    static char fmt_52[] = "(/,\002      DEPTH       TOP      AREA  CELERITY\
 ESCOFFIER\002)";
    static char fmt_53[] = "(/,\002 TABLE FOR CELERITY AND ESCOFFIER VARIABL\
E FOR \002,\002RESERVOIR\002)";
    static char fmt_54[] = "(1x,f10.3,f10.1,1pe10.3,0pf10.3,1pe10.3)";
    static char fmt_56[] = "(1x,f10.3,f10.1,f10.3,1pe12.5)";
    static char fmt_58[] = "(/,\002  INITDEPTH  INITFLOW PEAKDEPTH    PEAKFL\
OW\002,a)";
    static char fmt_72[] = "(\002 *ERR:560* Approach section table id does n\
ot \002,\002 represent\002,/,\002 a cross section.\002)";
    static char fmt_74[] = "(\002 *ERR:563* Constricted flow table id is inv\
alid.\002,/,10x,\002Type must be 2.\002)";
    static char fmt_76[] = "(/,\002 Testing TABID= \002,a,\002 for monotone \
celerity and \002,\002critical flow.\002)";
    static char fmt_78[] = "(\002 *ERR:540* TABID= \002,a,\002 not found\002)"
	    ;
    static char fmt_82[] = "(/,\002 *ERR:682* Cross section type=\002,i3,\
\002 not supported\002,\002 in GRITTER. \002,/,10x,\002 Use types: 20, 21, 2\
3, or 24.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    double sqrt(doublereal);
    integer s_rsfi(icilist *), e_rsfi(), s_wsle(cilist *), do_lio(integer *, 
	    integer *, char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    char contabid[16], apptabid[16];
    real a, feq_gen_c_d_;
    integer j;
    real t, y, q1, y1;
    double w;
    integer ha;
    extern /* Subroutine */ int feq_gen_read_tabid_d_(integer *, char *, char *, 
	    integer *, char *, integer *, ftnlen, ftnlen, ftnlen);
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    real cold;
    integer ioff;
    char line[80];
    integer xoff;
    real yold;
    double wold;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    char label[79];
    integer wflag;
    real qpeak;
    integer atype;
    real ypeak;
    extern /* Subroutine */ int chkcfc_(real *, integer *, integer *, integer 
	    *);
    integer contab, apptab;
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen),
	     fndrit_(integer *, integer *, integer *, integer *, real *, real 
	    *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__20 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__23 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__25 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__26 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__27 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__28 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__32 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__33 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__34 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__45 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__47 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__52 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__53 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__54 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Compute a generalized ritter solution for the instantaneous */
/*     dam break peak flow.  The reservoir is still  assumed to be prismatic, */
/*     horizontal, and frictionless.  however, the cross section */
/*     is non-rectangular and the failure need not be complete. */
/* SOURCE ritter.for:139 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ritter.for:141 */
/*<       integereflag,stdin,stdout >*/
/* SOURCE ritter.for:142 */
/*<       realgrav >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     GRAV   - value of acceleration due to gravity */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ritter.for:151 */
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
/* INCLUDE ritter.for:152 */
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
/* INCLUDE ritter.for:153 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ritter.for:156 */
/*<       integerapptab,atype,contab,ha,ioff,j,wflag,xoff >*/
/* SOURCE ritter.for:157 */
/*<       reala,c,cold,q1,qpeak,t,w,wold,y,y1,yold,ypeak >*/
/* SOURCE ritter.for:158 */
/*<       characterlabel*79,line*80,name*8,apptabid*16,contabid*16 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE ritter.for:161 */
/*<       intrinsicsqrt >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ritter.for:164 */
/*<       externalchkcfc,fndrit,inline,kil,read_tabid >*/
/*     + + + INPUT FORMATS + + + */
/* SOURCE ritter.for:167 */
/*<     2 format(2f10.0) >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ritter.for:170 */
/*<    52 format(/,'      DEPTH       TOP      AREA  CELERITY ESCOFFIER') >*/
/* SOURCE ritter.for:171 */
/*<    53  >*/
/* SOURCE ritter.for:173 */
/*<    54 format(1x,f10.3,f10.1,1pe10.3,0pf10.3,1pe10.3) >*/
/* SOURCE ritter.for:174 */
/*<    56 format(1x,f10.3,f10.1,f10.3,1pe12.5) >*/
/* SOURCE ritter.for:175 */
/*<    58 format(/,'  INITDEPTH  INITFLOW PEAKDEPTH    PEAKFLOW',a) >*/
/* SOURCE ritter.for:176 */
/*<    72  >*/
/* SOURCE ritter.for:178 */
/*<    74  >*/
/* SOURCE ritter.for:180 */
/*<    76  >*/
/* SOURCE ritter.for:182 */
/*<    78 format(' *ERR:540* TABID= ',a,' not found') >*/
/* SOURCE ritter.for:183 */
/*<    82  >*/
/* *********************************************************************** */
/*     INPUT THE TABLE ID FOR THE APPROACH CROSS SECTION */
/* SOURCE ritter.for:188 */
/*<       callinline(stdin,stdout,line) >*/
/* L2: */
/* L52: */
/* L53: */
/* L54: */
/* L56: */
/* L58: */
/* L72: */
/* L74: */
/* L76: */
/* L78: */
/* L82: */
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ritter.for:191 */
/*<       callread_tabid(stdout,line,'APPTAB',eflag,apptabid,apptab) >*/
    feq_gen_read_tabid_d_(stdout, line, const_cast<char*>("APPTAB"), eflag, apptabid, &apptab, (ftnlen)80,
	     (ftnlen)6, (ftnlen)16);
/*      READ(LINE,'(A8,A)',ERR=991) NAME, APPTABID */
/* SOURCE ritter.for:195 */
/*<       write(stdout,'(1X,A,A)')'APPTAB= ',apptabid >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(1X,A,A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("APPTAB= "), (ftnlen)8);
    do_fio(&feq_gen_c_d_1, apptabid, (ftnlen)16);
    e_wsfe();
/* SOURCE ritter.for:197 */
/*<       if(ftpnt(apptab).le.0)then >*/
    if (ftablea_1.ftpnt[apptab - 1] <= 0) {
/* SOURCE ritter.for:198 */
/*<       write(stdout,78)apptabid >*/
	feq_gen_io_d__20.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__20);
	do_fio(&feq_gen_c_d_1, apptabid, (ftnlen)16);
	e_wsfe();
/* SOURCE ritter.for:199 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE ritter.for:200 */
/*<       endif >*/
    }
/*     INPUT THE TABLE ID FOR THE CONSTRICTED FLOW */
/* SOURCE ritter.for:204 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ritter.for:207 */
/*<       callread_tabid(stdout,line,'CONTAB',eflag,contabid,contab) >*/
    feq_gen_read_tabid_d_(stdout, line, const_cast<char*>("CONTAB"), eflag, contabid, &contab, (ftnlen)80,
	     (ftnlen)6, (ftnlen)16);
/* SOURCE ritter.for:210 */
/*<       write(stdout,'(1X,A,A)')'CONTAB= ',contabid >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(1X,A,A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("CONTAB= "), (ftnlen)8);
    do_fio(&feq_gen_c_d_1, contabid, (ftnlen)16);
    e_wsfe();
/* SOURCE ritter.for:212 */
/*<       if(ftpnt(contab).le.0)then >*/
    if (ftablea_1.ftpnt[contab - 1] <= 0) {
/* SOURCE ritter.for:213 */
/*<       write(stdout,78)contabid >*/
	feq_gen_io_d__23.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__23);
	do_fio(&feq_gen_c_d_1, contabid, (ftnlen)16);
	e_wsfe();
/* SOURCE ritter.for:214 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE ritter.for:215 */
/*<       endif >*/
    }
/*     INPUT THE BREACH OFFSET VALUE */
/*      CALL inline(STDIN, STDOUT, LINE) */
/*      READ(LINE,'(A8,F10.0)',ERR=991) NAME, Z0 */
/*      WRITE(STDOUT,'(1X,A8,F10.3)') NAME, Z0 */
/*      IF(Z0.LT.0.0) THEN */
/*        WRITE(STDOUT,50) */
/*        EFLAG = 1 */
/*      ENDIF */
/* SOURCE ritter.for:227 */
/*<       if(eflag.gt.0)return >*/
    if (*eflag > 0) {
	return 0;
    }
/*     CONVERT THE TABLE NUMBERS TO TABLE ADDRESSES FOR CONVENIENCE */
/*     TABLE NUMBERS ARE RETAINED IN THE TABLES FOR ERROR REPORTING */
/* SOURCE ritter.for:232 */
/*<       apptab=ftpnt(apptab) >*/
    apptab = ftablea_1.ftpnt[apptab - 1];
/* SOURCE ritter.for:233 */
/*<       contab=ftpnt(contab) >*/
    contab = ftablea_1.ftpnt[contab - 1];
/*     ENSURE THAT THE TABLES ARE OF THE CORRECT TYPE. */
/* SOURCE ritter.for:237 */
/*<       atype=itab(apptab+2) >*/
    atype = itab[apptab + 2];
/* SOURCE ritter.for:238 */
/*<       if(atype.lt.20.or.atype.gt.25)then >*/
    if (atype < 20 || atype > 25) {
/* SOURCE ritter.for:239 */
/*<       write(stdout,72) >*/
	feq_gen_io_d__25.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__25);
	e_wsfe();
/* SOURCE ritter.for:240 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE ritter.for:241 */
/*<       endif >*/
    }
/* SOURCE ritter.for:243 */
/*<       if(atype.eq.22.or.atype.eq.25)then >*/
    if (atype == 22 || atype == 25) {
/* SOURCE ritter.for:244 */
/*<       write(stdout,82)atype >*/
	feq_gen_io_d__26.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__26);
	do_fio(&feq_gen_c_d_1, (char *)&atype, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE ritter.for:245 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE ritter.for:246 */
/*<       endif >*/
    }
/* SOURCE ritter.for:247 */
/*<       if(itab(contab+2).ne.2)then >*/
    if (itab[contab + 2] != 2) {
/* SOURCE ritter.for:248 */
/*<       write(stdout,74) >*/
	feq_gen_io_d__27.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__27);
	e_wsfe();
/* SOURCE ritter.for:249 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE ritter.for:250 */
/*<       endif >*/
    }
/*     CHECK FOR NON-MONOTONE CELERITY AND CRITICAL FLOW */
/* SOURCE ritter.for:254 */
/*<       if(eflag.gt.0)return >*/
    if (*eflag > 0) {
	return 0;
    }
/* SOURCE ritter.for:255 */
/*<       write(stdout,76)apptabid >*/
    feq_gen_io_d__28.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__28);
    do_fio(&feq_gen_c_d_1, apptabid, (ftnlen)16);
    e_wsfe();
/* SOURCE ritter.for:256 */
/*<       callchkcfc(grav,stdout,apptab,wflag) >*/
    chkcfc_(grav, stdout, &apptab, &wflag);
/* SOURCE ritter.for:261 */
/*<       if(eflag.gt.0)return >*/
    if (*eflag > 0) {
	return 0;
    }
/*     SET THE OFFSET FOR THE CROSS SECTION TABLE */
/* SOURCE ritter.for:264 */
/*<       xoff=offvec(atype) >*/
    xoff = offcom_1.offvec[atype - 1];
/*     SET THE HIGH ADDRESS OF THE APPROACH TABLE */
/* SOURCE ritter.for:267 */
/*<       ha=itab(apptab) >*/
    ha = itab[apptab];
/*     BASIC DATA HAS BEEN INPUT IN VALID FORM. */
/*     NOW MODIFY THE APPROACH CROSS SECTION TABLE SO THAT */
/*     IT WILL REPRESENT THE CELERITY AND THE ESCOFFIER STAGE VARIABLE */
/*     IN THE RESERVOIR. WE WILL REPLACE THE SQRT OF CONVEYANCE AND */
/*     THE MOMENTUM FLUX CORRECTION FACTOR IN THE TABLE. */
/*     WRITE HEADING FOR THE ESCOFFIER TABLE PRINTOUT */
/* SOURCE ritter.for:277 */
/*<       write(stdout,53) >*/
    feq_gen_io_d__32.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__32);
    e_wsfe();
/* SOURCE ritter.for:278 */
/*<       write(stdout,52) >*/
    feq_gen_io_d__33.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__33);
    e_wsfe();
/*     SET THE TYPE TO ZERO TO MAKE IT UNUSABLE FOR OTHER OPERATIONS */
/* SOURCE ritter.for:282 */
/*<       itab(apptab+2)=0 >*/
    itab[apptab + 2] = 0;
/*     CLEAR THE ZERO DEPTH ENTRIES */
/* SOURCE ritter.for:286 */
/*<       ftab(apptab+xtioff+3)=0.0 >*/
    ftab[apptab + 35] = (float)0.;
/* SOURCE ritter.for:287 */
/*<       ftab(apptab+xtioff+4)=0.0 >*/
    ftab[apptab + 36] = (float)0.;
/* SOURCE ritter.for:289 */
/*<       write(stdout,54)(ftab(apptab+xtioff+j),j=0,4) >*/
    feq_gen_io_d__34.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__34);
    for (j = 0; j <= 4; ++j) {
	do_fio(&feq_gen_c_d_1, (char *)ftab.lease(apptab + 32 + j).data(), (ftnlen)sizeof(real));
    }
    e_wsfe();
/*     IOFF GIVES THE OFFSET FROM THE TABLE ADDRESS TO THE FIRST */
/*     POSITIVE DEPTH  ENTRY IN THE TABLE. */
/* SOURCE ritter.for:295 */
/*<       ioff=xtioff+xoff >*/
    ioff = xoff + 32;
/* SOURCE ritter.for:297 */
/*<       cold=0.0 >*/
    cold = (float)0.;
/* SOURCE ritter.for:298 */
/*<       yold=0.0 >*/
    yold = (float)0.;
/* SOURCE ritter.for:299 */
/*<       wold=0.0 >*/
    wold = (float)0.;
/* SOURCE ritter.for:301 */
/*<   100 continue >*/
L100:
/* SOURCE ritter.for:303 */
/*<       y=ftab(apptab+ioff) >*/
    y = ftab[apptab + ioff];
/* SOURCE ritter.for:304 */
/*<       t=ftab(apptab+ioff+1) >*/
    t = ftab[apptab + ioff + 1];
/* SOURCE ritter.for:305 */
/*<       a=ftab(apptab+ioff+2) >*/
    a = ftab[apptab + ioff + 2];
/* SOURCE ritter.for:306 */
/*<       c=sqrt(grav*a/t) >*/
    wave_step = feq::advance_ritter_wave(y,yold,a,t,*grav,cold,wold);
    feq_gen_c_d_ = wave_step.celerity;
/* SOURCE ritter.for:308 */
/*<       w=wold+2.*grav*(y-yold)/(c+cold) >*/
    w = wave_step.escoffier;
/* SOURCE ritter.for:309 */
/*<       write(stdout,54)y,t,a,c,w >*/
    feq_gen_io_d__45.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__45);
    do_fio(&feq_gen_c_d_1, (char *)&y, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&t, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&a, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_, (ftnlen)sizeof(real));
    { real reported_w = static_cast<real>(w); do_fio(&feq_gen_c_d_1, (char *)&reported_w, (ftnlen)sizeof(real)); }
    e_wsfe();
/* SOURCE ritter.for:311 */
/*<       cold=c >*/
    cold = feq_gen_c_d_;
/* SOURCE ritter.for:312 */
/*<       yold=y >*/
    yold = y;
/* SOURCE ritter.for:313 */
/*<       wold=w >*/
    wold = w;
/* SOURCE ritter.for:315 */
/*<       ftab(apptab+ioff+3)=c >*/
    ftab[apptab + ioff + 3] = feq_gen_c_d_;
/* SOURCE ritter.for:316 */
/*<       ftab(apptab+ioff+4)=w >*/
    ftab[apptab + ioff + 4] = w;
/*       INCREMENT TO THE NEXT LEVEL IN THE CROSS SECTION TABLE */
/* SOURCE ritter.for:320 */
/*<       ioff=ioff+xoff >*/
    ioff += xoff;
/* SOURCE ritter.for:322 */
/*<       if(apptab+ioff.le.ha)goto100 >*/
    if (apptab + ioff <= ha) {
	goto L100;
    }
/*     THE ESCOFFIER TABLE IS COMPLETE.  NOW COMPUTE THE PEAK FLOW */
/*     FOR EACH CASE GIVEN IN THE INPUT. */
/* SOURCE ritter.for:328 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ritter.for:331 */
/*<       read(line,'(A79)',err=991)label >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(A79)");
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, label, (ftnlen)79);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/*      WRITE(STDOUT,'(1X,A79)') LABEL */
/* SOURCE ritter.for:333 */
/*<       write(stdout,58)label(21:79) >*/
    feq_gen_io_d__47.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__47);
    do_fio(&feq_gen_c_d_1, label + 20, (ftnlen)59);
    e_wsfe();
/* SOURCE ritter.for:335 */
/*<   200 continue >*/
L200:
/* SOURCE ritter.for:336 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ritter.for:339 */
/*<       read(line,2,err=991)y1,q1 >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&y1, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&q1, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ritter.for:340 */
/*<       if(y1.le.0.0)return >*/
    if (y1 <= (float)0.) {
	return 0;
    }
/*        IF(Y1.LE.Z0) THEN */
/*          WRITE(STDOUT,80) */
/*          EFLAG =1 */
/*        ENDIF */
/* SOURCE ritter.for:347 */
/*<       callfndrit(stdout,apptab,xoff,contab,y1,q1,ypeak,qpeak) >*/
    fndrit_(stdout, &apptab, &xoff, &contab, &y1, &q1, &ypeak, &qpeak);
/* SOURCE ritter.for:352 */
/*<       write(stdout,56)y1,q1,ypeak,qpeak >*/
    feq_gen_io_d__52.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__52);
    do_fio(&feq_gen_c_d_1, (char *)&y1, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&q1, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&ypeak, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&qpeak, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE ritter.for:354 */
/*<       goto200 >*/
    goto L200;
/* SOURCE ritter.for:355 */
/*<   991 continue >*/
L991:
/* SOURCE ritter.for:356 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__53.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__53);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE ritter.for:357 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__54.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__54);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE ritter.for:358 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE ritter.for:359 */
/*<       end >*/
    return 0;
} /* ritter_ */

#undef rtmp
#undef itab
#undef ftab


#ifdef __cplusplus
	}
#endif
