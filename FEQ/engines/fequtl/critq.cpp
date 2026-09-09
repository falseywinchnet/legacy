#include <feq/section_energy.hpp>
#include "callbacks.hpp"
/* critq.f -- translated by f2c (version 20240504).
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

/* COMMON isecom_ is declared in common.hpp. */

#define isecom_1 isecom_

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

static integer feq_gen_c_d_1 = 1;
static real c_b80 = (float)0.;
static integer feq_gen_c_d_9 = 9;




/* SOURCE critq.for:4 */
/*<       realfunctionfise(y) >*/
doublereal fise_(real *y)
{
    /* Initialized data */

    static integer noalp[6] = { 1,1,0,1,1,0 };

    /* System generated locals */
    real ret_val, feq_gen_r_d_1, feq_gen_r_d_2;

    /* Local variables */
    real b, j, k, t, db, dk, qc, at, dt, alp, dalp, yloc;
    extern /* Subroutine */ int xlkt20_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *), xlkt22_(integer *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *);

/*     + + + PURPOSE + + + */
/*     Compute the residual for inversion of specific energy. */
/* SOURCE critq.for:10 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE critq.for:13 */
/*<       realy >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Y      - maximum depth in a cross section */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE critq.for:19 */
/*     Common for function INVTSE */
/* SOURCE isecom.cmn:3 */
/*<       integeradrst,type,opunit >*/
/* SOURCE isecom.cmn:4 */
/*<       realqt,et,gravt >*/
/* SOURCE isecom.cmn:5 */
/*<       common/isecom/adrst,qt,et,gravt,type,opunit >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE critq.for:22 */
/*<       integernoalp(6) >*/
/* SOURCE critq.for:23 */
/*<       savenoalp >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE critq.for:26 */
/*<       realalp,at,b,dalp,db,dk,dt,j,k,qc,t,yloc >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE critq.for:29 */
/*<       externalxlkt20,xlkt22 >*/
/*     + + + DATA INITIALIZATIONS + + + */
/* *********************************************************************** */
/* SOURCE critq.for:32 */
/*<       datanoalp/1,1,0,1,1,0/ >*/
/* SOURCE critq.for:34 */
/*<       yloc=y >*/
    yloc = *y;
/* SOURCE critq.for:35 */
/*<       if(noalp(type-19).eq.1)then >*/
    if (noalp[isecom_1.feq_gen_type_d_ - 20] == 1) {
/*       NO ALPHA IN THE TABLE */
/* SOURCE critq.for:37 */
/*<       callxlkt20(adrst,yloc,at,t,dt,k,dk,b,db) >*/
	xlkt20_(&isecom_1.adrst, &yloc, &at, &t, &dt, &k, &dk, &b, &db);
        return feq::specific_energy_residual(*y,at,1.0F,isecom_1.qt,isecom_1.gravt,isecom_1.et);

/* SOURCE critq.for:43 */
/*<       else >*/
    } else {
/*       TABLE DOES HAVE ALPHA.  USE IT. */
/* SOURCE critq.for:45 */
/*<       callxlkt22(adrst,yloc,at,t,dt,j,k,dk,b,db,alp,dalp,qc) >*/
	xlkt22_(&isecom_1.adrst, &yloc, &at, &t, &dt, &j, &k, &dk, &b, &db, &
		alp, &dalp, &qc);
        return feq::specific_energy_residual(*y,at,alp,isecom_1.qt,isecom_1.gravt,isecom_1.et);

/* SOURCE critq.for:51 */
/*<       endif >*/
    }
/* SOURCE critq.for:53 */
/*<       return >*/
    
/* SOURCE critq.for:54 */
/*<       end >*/
} /* fise_ */




/* SOURCE critq.for:58 */
/*<       subroutineinvtse(grav,stdout,adrs,atype,q,e,y,eflag) >*/
/* Subroutine */ int invtse_(real *grav, integer *stdout, integer *adrs, 
	integer *atype, real *q, real *e, real *y, integer *eflag)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *BUG:503* GUESSED DEPTH IN SUB. CRITQ IS N\
OT POSITIVE\002)";
    static char fmt_56[] = "(\002 *ERR:562* SOLUTION DOES NOT EXIST AT DEP\
TH=\002,f10.3,/,10x,\002CONSTRICTED SECTION IS NOT A CONSTRICTION!\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    real yd, yu;
    integer feq_gen_flag_d_;
    extern doublereal fise_(real *);
    extern /* Subroutine */ int regfal_(real *, real *, FeqCallback3, real *, real *, 
	    real *, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__14 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__18 = { 0, 0, 0, fmt_56, 0 };


/*     + + + PURPOSE + + + */
/*     For a given flow rate, Q, specific energy, E, and */
/*     cross section table address, ADRS, compute the depth of */
/*     water in the cross section using the initial guess, Y, */
/*     as a starting point.  The goal is to find a subcritical */
/*     solution.   There should always be at least one subcritical */
/*     solution if there is any solution at all. */
/* SOURCE critq.for:70 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE critq.for:73 */
/*<       integeradrs,atype,eflag,stdout >*/
/* SOURCE critq.for:74 */
/*<       reale,grav,q,y >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     GRAV   - value of acceleration due to gravity */
/*     STDOUT - Fortran unit number for user output and messages */
/*     ADRS   - Address of function table */
/*     ATYPE  - Type of the cross section table involved */
/*     Q      - Flowrate */
/*     E      - Specific energy value. */
/*     Y      - maximum depth in a cross section */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE critq.for:87 */
/*     Common for function INVTSE */
/* SOURCE isecom.cmn:3 */
/*<       integeradrst,type,opunit >*/
/* SOURCE isecom.cmn:4 */
/*<       realqt,et,gravt >*/
/* SOURCE isecom.cmn:5 */
/*<       common/isecom/adrst,qt,et,gravt,type,opunit >*/
/* INCLUDE critq.for:88 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE critq.for:91 */
/*<       integerflag >*/
/* SOURCE critq.for:92 */
/*<       realyd,yu >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE critq.for:95 */
/*<       externalfise,regfal >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE critq.for:98 */
/*<    50 format(' *BUG:503* GUESSED DEPTH IN SUB. CRITQ IS NOT POSITIVE') >*/
/* SOURCE critq.for:99 */
/*<    56  >*/
/* *********************************************************************** */
/* SOURCE critq.for:102 */
/*<       if(y.le.0.0)then >*/
/* L50: */
/* L56: */
    if (*y <= (float)0.) {
/* SOURCE critq.for:103 */
/*<       write(stdout,50) >*/
	feq_gen_io_d__14.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__14);
	e_wsfe();
/* SOURCE critq.for:104 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE critq.for:105 */
/*<       return >*/
	return 0;
/* SOURCE critq.for:106 */
/*<       endif >*/
    }
/* SOURCE critq.for:108 */
/*<       qt=q >*/
    isecom_1.qt = *q;
/* SOURCE critq.for:109 */
/*<       et=e >*/
    isecom_1.et = *e;
/* SOURCE critq.for:110 */
/*<       gravt=grav >*/
    isecom_1.gravt = *grav;
/* SOURCE critq.for:111 */
/*<       adrst=adrs >*/
    isecom_1.adrst = *adrs;
/* SOURCE critq.for:112 */
/*<       type=atype >*/
    isecom_1.feq_gen_type_d_ = *atype;
/* SOURCE critq.for:113 */
/*<       opunit=stdout >*/
    isecom_1.opunit = *stdout;
/* SOURCE critq.for:115 */
/*<       yd=y >*/
    yd = *y;
/* SOURCE critq.for:116 */
/*<       yu=et >*/
    yu = isecom_1.et;
/* SOURCE critq.for:117 */
/*<       callregfal(epsarg,epsf,fise,yd,yu,y,flag) >*/
    regfal_(&epscom_1.epsarg, &epscom_1.epsf, fise_, &yd, &yu, y, &
	    feq_gen_flag_d_);
/* SOURCE critq.for:122 */
/*<       if(flag.ge.1)then >*/
    if (feq_gen_flag_d_ >= 1) {
/*       SOLUTION DOES NOT EXIST */
/* SOURCE critq.for:124 */
/*<       write(stdout,56)y >*/
	feq_gen_io_d__18.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__18);
	do_fio(&feq_gen_c_d_1, (char *)&(*y), (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE critq.for:125 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE critq.for:126 */
/*<       endif >*/
    }
/* SOURCE critq.for:128 */
/*<       return >*/
    return 0;
/* SOURCE critq.for:129 */
/*<       end >*/
} /* invtse_ */




/* SOURCE critq.for:133 */
/*<       subroutinecritq(grav,stdin,stdout,stdtab,eflag,ftp) >*/
/* Subroutine */ int critq_(real *grav, integer *stdin, integer *stdout, 
	integer *stdtab, integer *eflag, integer *ftp)
{
    /* Initialized data */

    static integer noqc[6] = { 1,1,0,1,1,0 };

    /* Format strings */
    static char fmt_50[] = "(\002 *ERR:559* COEFFICIENT OF DISCHARGE <= 0.0 \
OR > 1.0\002)";
    static char fmt_54[] = "(/,\002 TABID= \002,a)";
    static char fmt_58[] = "(\002 TYPE=    2\002)";
    static char fmt_62[] = "(\002 REFL=0.0\002)";
    static char fmt_66[] = "(\002      DEPTH DISCHARGE\002,2x,a50)";
    static char fmt_70[] = "(1x,f10.3,f10.1)";
    static char fmt_72[] = "(\002 *ERR:560* APPROACH SECTION TABLE DOES NOT\
 \002,\002 REPRESENT\002,/,\002 A CROSS SECTION.\002)";
    static char fmt_74[] = "(\002 *ERR:561* CONTRICTED SECTION TABLE DOES NO\
T \002,\002 REPRESENT\002,/,10x,\002 A CROSS SECTION.\002)";
    static char fmt_76[] = "(/,\002 TESTING TabId=\002,a,\002 FOR MONOTONE C\
ELERITY AND \002,\002CRITICAL FLOW.\002)";
    static char fmt_78[] = "(\002 *ERR:565* BOTTOM ELEV. OF APPROACH SECTION\
 ABOVE \002,\002BOTTOM ELEV.\002,/,10x,\002 OF CONSTRICTED SECTION.\002)";
    static char fmt_80[] = "(\002 *ERR:566* INSUFFICIENT SPACE IN ITAB/FTAB \
TO SAVE TABLE\002,/,10x,\002IN CRITQ. NEED\002,i6,\002 MORE ELEMENTS.\002)";
    static char fmt_82[] = "(\002 *ERR:540* TabId=\002,a,\002 NOT FOUND\002)";
    static char fmt_84[] = "(/,\002 Approach Section  Constricted Section\
\002,/,\002 Elevation  Depth  Elevation     Depth      Flow\002)";
    static char fmt_85[] = "(f10.2,f7.2,f11.2,f10.2,f10.1)";
    static char fmt_86[] = "(/,\002 TabId= \002,a,2x,\002Internal number=\
\002,i6,2x,a)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3;
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_rsfi(icilist *), e_rsfi();
    double sqrt(doublereal);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    char contabid[16], apptabid[16];
    doublereal northing;
    integer feq_gen_i_d_, j, n;
    char feq_gen_body_head_d_[30];
    real ac, ea, cd, qc, tc, ya, za, yc, zc;
    extern /* Subroutine */ int feq_gen_read_tabid_d_(integer *, char *, char *, 
	    integer *, char *, integer *, ftnlen, ftnlen, ftnlen), 
	    feq_gen_tab_in_use_d_(char *, integer *, ftnlen);
    char cin[50];
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    char feq_gen_name_d_[8];
    integer ioff;
    char line[80];
    integer xoff;
    char zone[8];
    integer feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    char label[50], tabid[16];
    real alpha;
    integer table;
    char hgrid[8];
    integer wflag;
    real qavec[999];
    char basis[8];
    real yavec[999];
    integer atype, ctype;
    extern /* Subroutine */ int chkcfc_(real *, integer *, integer *, integer 
	    *);
    integer contab, apptab;
    real factor;
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen);
    integer ndepth;
    char betopt[8], monton[8], savopt[8], vdatum[8];
    extern integer lenstr_(char *, ftnlen);
    char outopt[8];
    extern /* Subroutine */ int invtse_(real *, integer *, integer *, integer 
	    *, real *, real *, real *, integer *), setopt_(integer *, char *, 
	    char *, char *, char *, char *, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen), feq_gen_output_type_234_d_(integer *, integer *, integer *, 
	    integer *, integer *, real *, char *, char *, real *, real *, 
	    real *, char *, char *, char *, char *, char *, doublereal *, 
	    doublereal *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen), feq_gen_get_lctn_items_d_(integer *, integer *, integer *), 
	    feq_gen_set_lctn_items_d_(char *, char *, char *, char *, char *, 
	    doublereal *, doublereal *, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen);
    doublereal easting;
    extern /* Subroutine */ int feq_gen_read_tabid_plus_d_(integer *, char *, integer *
	    , char *, integer *, char *, ftnlen, ftnlen, ftnlen);
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__28 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__42 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__45 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__48 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__52 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__53 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__54 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__58 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__64 = { 0, 0, 0, fmt_84, 0 };
    static cilist feq_gen_io_d__65 = { 0, 0, 0, fmt_85, 0 };
    static cilist feq_gen_io_d__73 = { 0, 0, 0, fmt_85, 0 };
    static cilist feq_gen_io_d__75 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__77 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__78 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__79 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__80 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__81 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__82 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__84 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__87 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__88 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Compute critical flow table for flow through a constriction */
/*     when the velocity head of the approaching flow is included */
/*     in the analysis.  A user supplied discharge coefficient is */
/*     used to account for contraction losses and friction losses. */
/* SOURCE critq.for:143 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE critq.for:145 */
/*<       integereflag,ftp,stdin,stdout,stdtab >*/
/* SOURCE critq.for:146 */
/*<       realgrav >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     GRAV   - value of acceleration due to gravity */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     FTP    - next open location in the function table storage */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE critq.for:157 */
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
/* INCLUDE critq.for:158 */
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
/* INCLUDE critq.for:159 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + SAVED VALUES + + + */
/* SOURCE critq.for:162 */
/*<       integernoqc(6) >*/
/* SOURCE critq.for:163 */
/*<       savenoqc >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE critq.for:166 */
/*<        >*/
/* SOURCE critq.for:168 */
/*<        >*/
/* SOURCE critq.for:170 */
/*<       real*8easting,northing >*/
/* SOURCE critq.for:171 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE critq.for:177 */
/*<       intrinsicsqrt >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE critq.for:180 */
/*<       integerlenstr >*/
/* SOURCE critq.for:181 */
/*<        >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE critq.for:185 */
/*<       datanoqc/1,1,0,1,1,0/ >*/
/* SOURCE critq.for:188 */
/*<    50 format(' *ERR:559* COEFFICIENT OF DISCHARGE <= 0.0 OR > 1.0') >*/
/* L50: */
/* SOURCE critq.for:189 */
/*<    52 format('TABID= ',a) >*/
/* L52: */
/* SOURCE critq.for:190 */
/*<    54 format(/,' TABID= ',a) >*/
/* L54: */
/* SOURCE critq.for:191 */
/*<    56 format('TYPE=    2') >*/
/* L56: */
/* SOURCE critq.for:192 */
/*<    58 format(' TYPE=    2') >*/
/* L58: */
/* SOURCE critq.for:193 */
/*<    60 format('REFL=0.0') >*/
/* L60: */
/* SOURCE critq.for:194 */
/*<    62 format(' REFL=0.0') >*/
/* L62: */
/* SOURCE critq.for:195 */
/*<    64 format('     DEPTH DISCHARGE',2x,a50) >*/
/* L64: */
/* SOURCE critq.for:196 */
/*<    66 format('      DEPTH DISCHARGE',2x,a50) >*/
/* L66: */
/* SOURCE critq.for:197 */
/*<    68 format(f10.3,f10.1) >*/
/* L68: */
/* SOURCE critq.for:198 */
/*<    70 format(1x,f10.3,f10.1) >*/
/* L70: */
/* SOURCE critq.for:199 */
/*<    72  >*/
/* L72: */
/* SOURCE critq.for:201 */
/*<    74  >*/
/* L74: */
/* SOURCE critq.for:203 */
/*<    76  >*/
/* L76: */
/* SOURCE critq.for:205 */
/*<    78  >*/
/* L78: */
/* SOURCE critq.for:207 */
/*<    80  >*/
/* L80: */
/* SOURCE critq.for:209 */
/*<    82 format(' *ERR:540* TabId=',a,' NOT FOUND') >*/
/* L82: */
/* SOURCE critq.for:210 */
/*<    84  >*/
/* L84: */
/* SOURCE critq.for:212 */
/*<    85 format(f10.2,f7.2,f11.2,f10.2,f10.1) >*/
/* L85: */
/* SOURCE critq.for:213 */
/*<    86 format(/,' TabId= ',a,2x,'Internal number=',i6,2x,a) >*/
/* L86: */
/* *********************************************************************** */
/* SOURCE critq.for:215 */
/*<       body_head='      DEPTH DISCHARGE' >*/
    s_copy(feq_gen_body_head_d_, const_cast<char*>("      DEPTH DISCHARGE"), (ftnlen)30, (ftnlen)21);
/* SOURCE critq.for:216 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE critq.for:219 */
/*<       callread_tabid_plus(stdout,line,eflag,tabid,table,cin) >*/
    feq_gen_read_tabid_plus_d_(stdout, line, eflag, tabid, &table, cin, (ftnlen)80, (
	    ftnlen)16, (ftnlen)50);
/* SOURCE critq.for:223 */
/*<       write(stdout,86)tabid(1:lenstr(tabid)),table,cin >*/
    feq_gen_io_d__28.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__28);
    do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
    do_fio(&feq_gen_c_d_1, (char *)&table, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, cin, (ftnlen)50);
    e_wsfe();
/* SOURCE critq.for:225 */
/*<       callsetopt(stdout,cin,savopt,outopt,monton,betopt) >*/
    setopt_(stdout, cin, savopt, outopt, monton, betopt, (ftnlen)50, (ftnlen)
	    8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/*     MAKE SURE TABLE NUMBER IS NOT ALREADY USED IN THIS INPUT */
/* SOURCE critq.for:231 */
/*<       if(ftpnt(table).ne.0)calltab_in_use(tabid,eflag) >*/
    if (ftablea_1.ftpnt[table - 1] != 0) {
	feq_gen_tab_in_use_d_(tabid, eflag, (ftnlen)16);
    }
/*     Get location items that may be present. If they are not present */
/*     they will be set to default values.  The default requests FEQUTL */
/*     to omit the items. */
/* SOURCE critq.for:238 */
/*<       callget_lctn_items(stdin,stdout,eflag) >*/
    feq_gen_get_lctn_items_d_(stdin, stdout, eflag);
/* SOURCE critq.for:240 */
/*<        >*/
    feq_gen_set_lctn_items_d_(zone, hgrid, vdatum, unitsys, basis, &easting, &northing,
	     (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/*     INPUT THE TABLE NUMBER FOR THE APPROACH CROSS SECTION */
/* SOURCE critq.for:246 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE critq.for:249 */
/*<       callread_tabid(stdout,line,'APPTAB',eflag,apptabid,apptab) >*/
    feq_gen_read_tabid_d_(stdout, line, const_cast<char*>("APPTAB"), eflag, apptabid, &apptab, (ftnlen)80,
	     (ftnlen)6, (ftnlen)16);
/* SOURCE critq.for:252 */
/*<       write(stdout,'(1X,A,A)')'APPTAB=',apptabid >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(1X,A,A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("APPTAB="), (ftnlen)7);
    do_fio(&feq_gen_c_d_1, apptabid, (ftnlen)16);
    e_wsfe();
/* SOURCE critq.for:254 */
/*<       if(ftpnt(apptab).le.0)then >*/
    if (ftablea_1.ftpnt[apptab - 1] <= 0) {
/* SOURCE critq.for:255 */
/*<       write(stdout,82)apptabid >*/
	feq_gen_io_d__42.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__42);
	do_fio(&feq_gen_c_d_1, apptabid, (ftnlen)16);
	e_wsfe();
/* SOURCE critq.for:256 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE critq.for:257 */
/*<       endif >*/
    }
/*     INPUT THE TABLE NUMBER FOR THE CONSTRICTED CROSS SECTION */
/* SOURCE critq.for:261 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE critq.for:264 */
/*<       callread_tabid(stdout,line,'CONTAB',eflag,contabid,contab) >*/
    feq_gen_read_tabid_d_(stdout, line, const_cast<char*>("CONTAB"), eflag, contabid, &contab, (ftnlen)80,
	     (ftnlen)6, (ftnlen)16);
/* SOURCE critq.for:267 */
/*<       write(stdout,'(1X,A,A)')'CONTAB=',contabid >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(1X,A,A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, const_cast<char*>("CONTAB="), (ftnlen)7);
    do_fio(&feq_gen_c_d_1, contabid, (ftnlen)16);
    e_wsfe();
/* SOURCE critq.for:270 */
/*<       if(ftpnt(contab).eq.0)then >*/
    if (ftablea_1.ftpnt[contab - 1] == 0) {
/* SOURCE critq.for:271 */
/*<       write(stdout,82)contabid >*/
	feq_gen_io_d__45.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__45);
	do_fio(&feq_gen_c_d_1, contabid, (ftnlen)16);
	e_wsfe();
/* SOURCE critq.for:272 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE critq.for:273 */
/*<       endif >*/
    }
/*     INPUT THE DISCHARGE COEFFICIENT FOR CONTRACTION AND APPROACH SECTION */
/*     LOSSES */
/* SOURCE critq.for:278 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE critq.for:281 */
/*<       read(line,'(A8,F10.0)',err=991)name,cd >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(A8,F10.0)");
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)8);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&cd, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE critq.for:282 */
/*<       write(stdout,'(1X,A8,F10.3)')name,cd >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(1X,A8,F10.3)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, feq_gen_name_d_, (ftnlen)8);
    do_fio(&feq_gen_c_d_1, (char *)&cd, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE critq.for:283 */
/*<       if(cd.gt.1.0.or.cd.le.0.0)then >*/
    if (cd > (float)1. || cd <= (float)0.) {
/* SOURCE critq.for:284 */
/*<       write(stdout,50) >*/
	feq_gen_io_d__48.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__48);
	e_wsfe();
/* SOURCE critq.for:285 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE critq.for:286 */
/*<       endif >*/
    }
/* SOURCE critq.for:288 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE critq.for:291 */
/*<       read(line,'(A50)',err=991)label >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(A50)");
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, label, (ftnlen)50);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE critq.for:292 */
/*<       write(stdout,'(1X,A50)')label >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(1X,A50)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, label, (ftnlen)50);
    e_wsfe();
/* SOURCE critq.for:294 */
/*<       if(eflag.gt.0)return >*/
    if (*eflag > 0) {
	return 0;
    }
/*     CONVERT THE TABLE NUMBERS TO TABLE ADDRESSES FOR CONVENIENCE */
/*     TABLE NUMBERS ARE RETAINED IN THE TABLES FOR ERROR REPORTING */
/* SOURCE critq.for:299 */
/*<       apptab=ftpnt(apptab) >*/
    apptab = ftablea_1.ftpnt[apptab - 1];
/* SOURCE critq.for:300 */
/*<       contab=ftpnt(contab) >*/
    contab = ftablea_1.ftpnt[contab - 1];
/*     ENSURE THAT THE TABLES ARE OF THE CORRECT TYPE. */
/* SOURCE critq.for:304 */
/*<       atype=itab(apptab+2) >*/
    atype = itab[apptab + 2];
/* SOURCE critq.for:305 */
/*<       ctype=itab(contab+2) >*/
    ctype = itab[contab + 2];
/* SOURCE critq.for:306 */
/*<       if(atype.lt.20.or.atype.gt.25)then >*/
    if (atype < 20 || atype > 25) {
/* SOURCE critq.for:307 */
/*<       write(stdout,72) >*/
	feq_gen_io_d__52.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__52);
	e_wsfe();
/* SOURCE critq.for:308 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE critq.for:309 */
/*<       endif >*/
    }
/* SOURCE critq.for:310 */
/*<       if(ctype.lt.20.or.ctype.gt.25)then >*/
    if (ctype < 20 || ctype > 25) {
/* SOURCE critq.for:311 */
/*<       write(stdout,74) >*/
	feq_gen_io_d__53.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__53);
	e_wsfe();
/* SOURCE critq.for:312 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE critq.for:313 */
/*<       endif >*/
    }
/*     CHECK FOR NON-MONOTONE CELERITY AND CRITICAL FLOW */
/* SOURCE critq.for:317 */
/*<       if(eflag.gt.0)return >*/
    if (*eflag > 0) {
	return 0;
    }
/* SOURCE critq.for:319 */
/*<       write(stdout,76)contabid(1:lenstr(contabid)) >*/
    feq_gen_io_d__54.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__54);
    do_fio(&feq_gen_c_d_1, contabid, lenstr_(contabid, (ftnlen)16));
    e_wsfe();
/* SOURCE critq.for:320 */
/*<       callchkcfc(grav,stdout,contab,wflag) >*/
    chkcfc_(grav, stdout, &contab, &wflag);
/*     GET THE BOTTOM ELEVATIONS FOR EACH CROSS SECTION */
/* SOURCE critq.for:326 */
/*<       za=ftab(apptab+5) >*/
    za = ftab[apptab + 5];
/* SOURCE critq.for:327 */
/*<       zc=ftab(contab+5) >*/
    zc = ftab[contab + 5];
/* SOURCE critq.for:329 */
/*<       if(za.gt.zc)then >*/
    if (za > zc) {
/* SOURCE critq.for:330 */
/*<       write(stdout,78) >*/
	feq_gen_io_d__58.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__58);
	e_wsfe();
/* SOURCE critq.for:331 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE critq.for:332 */
/*<       endif >*/
    }
/* SOURCE critq.for:334 */
/*<       if(eflag.gt.0)return >*/
    if (*eflag > 0) {
	return 0;
    }
/*     BASIC DATA HAS BEEN INPUT IN VALID FORM.  NOW FOR EACH POSITIVE */
/*     DEPTH VALUE IN THE CONSTRICTED SECTION TABLE, COMPUTE THE */
/*     CRITICAL FLOW AND THE CORRESPONDING DEPTH IN THE APPROACH */
/*     CROSS SECTION */
/* SOURCE critq.for:341 */
/*<       ndepth=1 >*/
    ndepth = 1;
/*     Set the point at zero depth in approach section. Always present. */
/* SOURCE critq.for:343 */
/*<       yavec(ndepth)=0.0 >*/
    yavec[ndepth - 1] = (float)0.;
/* SOURCE critq.for:344 */
/*<       qavec(ndepth)=0.0 >*/
    qavec[ndepth - 1] = (float)0.;
/*     Check if zero flow persists for non-zero depth in approach section. */
/* SOURCE critq.for:347 */
/*<       if(zc.gt.za)then >*/
    if (zc > za) {
/* SOURCE critq.for:348 */
/*<       ndepth=ndepth+1 >*/
	++ndepth;
/* SOURCE critq.for:349 */
/*<       yavec(ndepth)=zc-za >*/
	yavec[ndepth - 1] = static_cast<double>(zc) - za;
/* SOURCE critq.for:350 */
/*<       qavec(ndepth)=0.0 >*/
	qavec[ndepth - 1] = (float)0.;
/* SOURCE critq.for:351 */
/*<       endif >*/
    }
/*     IOFF GIVES THE OFFSET FROM THE TABLE ADDRESS TO THE FIRST */
/*     POSITIVE DEPTH  ENTRY IN THE TABLE. */
/* SOURCE critq.for:357 */
/*<       xoff=offvec(ctype) >*/
    xoff = offcom_1.offvec[ctype - 1];
/* SOURCE critq.for:358 */
/*<       ioff=xtioff+xoff >*/
    ioff = xoff + 32;
/* SOURCE critq.for:360 */
/*<       write(stdout,84) >*/
    feq_gen_io_d__64.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__64);
    e_wsfe();
/* SOURCE critq.for:362 */
/*<       write(stdout,85)za+zc-za,zc-za,zc,0.0,0.0 >*/
    feq_gen_io_d__65.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__65);
    feq_gen_r_d_1 = static_cast<double>(static_cast<double>(za) + zc) - za;
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
    feq_gen_r_d_2 = static_cast<double>(zc) - za;
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&zc, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&c_b80, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&c_b80, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE critq.for:363 */
/*<   100 continue >*/
L100:
/* SOURCE critq.for:365 */
/*<       yc=ftab(contab+ioff) >*/
    yc = ftab[contab + ioff];
/* SOURCE critq.for:366 */
/*<       tc=ftab(contab+ioff+1) >*/
    tc = ftab[contab + ioff + 1];
/* SOURCE critq.for:367 */
/*<       ac=ftab(contab+ioff+2) >*/
    ac = ftab[contab + ioff + 2];
/* SOURCE critq.for:368 */
/*<       if(noqc(ctype-19).eq.1)then >*/
    if (noqc[ctype - 20] == 1) {
/*         TABLE DOES NOT HAVE CRITICAL FLOW.  THEREFORE COMPUTE */
/*         IT FROM THE SIMPLE FORMULA ASSUMMING UNIFORM VELOCITY */
/*         DISTRIBUTION */
/* SOURCE critq.for:373 */
/*<       qc=ac*sqrt(grav*ac/tc) >*/
	qc = ac * static_cast<float>(/* Original 0x411964 stores sqrt(g*A/T) as REAL before Q=A*speed. */ sqrt(static_cast<double>(static_cast<double>(*grav) * ac) / tc));
/* SOURCE critq.for:374 */
/*<       alpha=1.0 >*/
	alpha = (float)1.;
/* SOURCE critq.for:375 */
/*<       else >*/
    } else {
/*         TABLE DOES HAVE QC.  GET IT */
/* SOURCE critq.for:377 */
/*<       qc=ftab(contab+ioff+7) >*/
	qc = ftab[contab + ioff + 7];
/* SOURCE critq.for:378 */
/*<       alpha=ftab(contab+ioff+6) >*/
	alpha = ftab[contab + ioff + 6];
/* SOURCE critq.for:379 */
/*<       endif >*/
    }
/*       NOW COMPUTE THE SPECIFIC ENERGY WHICH MUST EXIST IN THE */
/*       APPROACH SECTION IN ORDER TO PRODUCE THE CRITICAL FLOW IN */
/*       THE CONSTRICTED SECTION */
/* SOURCE critq.for:385 */
/*<       ea=zc+yc+0.5*alpha*qc**2/(grav*(ac**2)*(cd**2))-za >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = qc;
/* Computing 2nd power */
    feq_gen_r_d_2 = ac;
/* Computing 2nd power */
    feq_gen_r_d_3 = cd;
    ea = static_cast<double>(static_cast<double>(static_cast<double>(zc) + yc) + static_cast<double>(static_cast<double>(static_cast<double>(alpha) * (float).5) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / (static_cast<double>(static_cast<double>(*grav) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) 
	    * (static_cast<double>(feq_gen_r_d_3) * feq_gen_r_d_3))) - za;
/*       NOW FIND THE DEPTH IN THE APPROACH SECTION WHICH CORRESPONDS */
/*       TO THE SPECIFIC ENERGY, EA, AND THE FLOWRATE, QC. */
/*       INVTSE- INVerT Specific Energy */
/* SOURCE critq.for:391 */
/*<       ya=zc+yc-za >*/
    ya = static_cast<double>(static_cast<double>(zc) + yc) - za;
/* SOURCE critq.for:393 */
/*<       callinvtse(grav,stdout,apptab,atype,qc,ea,ya,eflag) >*/
    invtse_(grav, stdout, &apptab, &atype, &qc, &ea, &ya, eflag);
/* SOURCE critq.for:397 */
/*<       ndepth=ndepth+1 >*/
    ++ndepth;
/* SOURCE critq.for:399 */
/*<       yavec(ndepth)=ya >*/
    yavec[ndepth - 1] = ya;
/* SOURCE critq.for:400 */
/*<       qavec(ndepth)=qc >*/
    qavec[ndepth - 1] = qc;
/* SOURCE critq.for:402 */
/*<       write(stdout,85)za+ya,ya,zc+yc,yc,qc >*/
    feq_gen_io_d__73.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__73);
    feq_gen_r_d_1 = static_cast<double>(za) + ya;
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&ya, (ftnlen)sizeof(real));
    feq_gen_r_d_2 = static_cast<double>(zc) + yc;
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&yc, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&qc, (ftnlen)sizeof(real));
    e_wsfe();
/*       INCREMENT TO THE NEXT LEVEL IN THE CROSS SECTION TABLE */
/* SOURCE critq.for:405 */
/*<       ioff=ioff+xoff >*/
    ioff += xoff;
/* SOURCE critq.for:407 */
/*<       if(contab+ioff.le.itab(contab))goto100 >*/
    if (contab + ioff <= itab[contab]) {
	goto L100;
    }
/*     TABLE IS COMPLETE. OUTPUT THE TABLE TO BOTH STDOUT AND */
/*     STDTAB */
/* SOURCE critq.for:413 */
/*<       if(savopt(1:4).eq.'SAVE')then >*/
    if (s_cmp(savopt, const_cast<char*>("SAVE"), (ftnlen)4, (ftnlen)4) == 0) {
/*       CHECK ON SPACE IN THE TABLE SYSTEM */
/* SOURCE critq.for:416 */
/*<       n=off234+2*(2+ndepth) >*/
	n = (ndepth + 2 << 1) + 22;
/* SOURCE critq.for:417 */
/*<       if((n+ftp).gt.mrftab)then >*/
	if (n + *ftp > 13000001) {
/* SOURCE critq.for:418 */
/*<       write(stdout,80)n+ftp-mrftab >*/
	    feq_gen_io_d__75.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__75);
	    feq_gen_i_d_1 = n + *ftp - 13000001;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_1, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE critq.for:419 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE critq.for:420 */
/*<       endif >*/
	}
/* SOURCE critq.for:423 */
/*<       ftpnt(table)=ftp >*/
	ftablea_1.ftpnt[table - 1] = *ftp;
/* SOURCE critq.for:424 */
/*<       itab(ftp+1)=table >*/
	itab[*ftp + 1] = table;
/* SOURCE critq.for:425 */
/*<       itab(ftp+2)=2 >*/
	itab[*ftp + 2] = 2;
/* SOURCE critq.for:426 */
/*<       itab(ftp+3)=ftp+off234 >*/
	itab[*ftp + 3] = *ftp + 22;
/* SOURCE critq.for:427 */
/*<       ftab(ftp+4)=0.0 >*/
	ftab[*ftp + 4] = (float)0.;
/* SOURCE critq.for:428 */
/*<       ftab(ftp+5)=1.0 >*/
	ftab[*ftp + 5] = (float)1.;
/* SOURCE critq.for:429 */
/*<       itab(ftp+18)=0 >*/
	itab[*ftp + 18] = 0;
/* SOURCE critq.for:430 */
/*<       ftab(ftp+19)=0.0 >*/
	ftab[*ftp + 19] = (float)0.;
/* SOURCE critq.for:431 */
/*<       j=itab(ftp+3) >*/
	j = itab[*ftp + 3];
/* SOURCE critq.for:432 */
/*<       endif >*/
    }
/*      WRITE(STDTAB,52) TABID(1:LENSTR(TABID)) */
/* SOURCE critq.for:434 */
/*<       write(stdout,54)tabid(1:lenstr(tabid)) >*/
    feq_gen_io_d__77.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__77);
    do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
    e_wsfe();
/*      WRITE(STDTAB,56) */
/* SOURCE critq.for:437 */
/*<       write(stdout,58) >*/
    feq_gen_io_d__78.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__78);
    e_wsfe();
/*      WRITE(STDTAB,60) */
/* SOURCE critq.for:440 */
/*<       write(stdout,62) >*/
    feq_gen_io_d__79.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__79);
    e_wsfe();
/*      WRITE(STDTAB,64) LABEL */
/* SOURCE critq.for:443 */
/*<       write(stdout,66)label >*/
    feq_gen_io_d__80.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__80);
    do_fio(&feq_gen_c_d_1, label, (ftnlen)50);
    e_wsfe();
/*      WRITE(STDTAB,68) 0.0, 0.0 */
/* SOURCE critq.for:446 */
/*<       write(stdout,70)0.0,0.0 >*/
    feq_gen_io_d__81.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__81);
    do_fio(&feq_gen_c_d_1, (char *)&c_b80, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&c_b80, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE critq.for:447 */
/*<       if(zc.gt.za)then >*/
    if (zc > za) {
/*        WRITE(STDTAB,68) ZC - ZA, 0.0 */
/* SOURCE critq.for:449 */
/*<       write(stdout,70)zc-za,0.0 >*/
	feq_gen_io_d__82.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__82);
	feq_gen_r_d_1 = static_cast<double>(zc) - za;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&c_b80, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE critq.for:450 */
/*<       endif >*/
    }
/*      IF(SAVOPT(1:4).EQ.'SAVE') THEN */
/*        FTAB(J) = 0. */
/*        FTAB(J+1) = 0.0 */
/*        J = J + 2 */
/*        IF(ZC.GT.ZA) THEN */
/*          FTAB(J) = ZC - ZA */
/*          FTAB(J+1) = 0.0 */
/*          J = J + 2 */
/*        ENDIF */
/*      ENDIF */
/* SOURCE critq.for:463 */
/*<       do2300i=1,ndepth >*/
    feq_gen_i_d_1 = ndepth;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*        WRITE(STDTAB,68) YAVEC(I), QAVEC(I) */
/* SOURCE critq.for:465 */
/*<       write(stdout,70)yavec(i),qavec(i) >*/
	feq_gen_io_d__84.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__84);
	do_fio(&feq_gen_c_d_1, (char *)&yavec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&qavec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE critq.for:466 */
/*<       if(savopt(1:4).eq.'SAVE')then >*/
	if (s_cmp(savopt, const_cast<char*>("SAVE"), (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE critq.for:467 */
/*<       ftab(j)=yavec(i) >*/
	    ftab[j] = yavec[feq_gen_i_d_ - 1];
/* SOURCE critq.for:468 */
/*<       ftab(j+1)=qavec(i) >*/
	    ftab[j + 1] = qavec[feq_gen_i_d_ - 1];
/* SOURCE critq.for:469 */
/*<       j=j+2 >*/
	    j += 2;
/* SOURCE critq.for:470 */
/*<       endif >*/
	}
/* SOURCE critq.for:471 */
/*<  2300 continue >*/
/* L2300: */
    }
/*      WRITE(STDTAB,68) -1.0, 0.0 */
/* SOURCE critq.for:475 */
/*<       type=2 >*/
    feq_gen_type_d_ = 2;
/* SOURCE critq.for:476 */
/*<       factor=1.0 >*/
    factor = (float)1.;
/* SOURCE critq.for:477 */
/*<        >*/
    feq_gen_output_type_234_d_(stdout, stdtab, &ndepth, &table, &feq_gen_type_d_, &factor, 
	    feq_gen_body_head_d_, label, yavec, qavec, qavec, zone, hgrid, vdatum, 
	    unitsys, basis, &easting, &northing, (ftnlen)30, (ftnlen)50, (
	    ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE critq.for:484 */
/*<       if(savopt(1:4).eq.'SAVE')then >*/
    if (s_cmp(savopt, const_cast<char*>("SAVE"), (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE critq.for:485 */
/*<       itab(ftp)=j-2 >*/
	itab[*ftp] = j - 2;
/* SOURCE critq.for:486 */
/*<       ftp=j >*/
	*ftp = j;
/* SOURCE critq.for:487 */
/*<       endif >*/
    }
/* SOURCE critq.for:489 */
/*<       return >*/
    return 0;
/* SOURCE critq.for:490 */
/*<   991 continue >*/
L991:
/* SOURCE critq.for:491 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__87.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__87);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE critq.for:492 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__88.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__88);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE critq.for:493 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE critq.for:494 */
/*<       end >*/
    return 0;
} /* critq_ */

#undef rtmp
#undef itab
#undef ftab


#ifdef __cplusplus
	}
#endif
