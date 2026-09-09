#include "callbacks.hpp"
/* culvertb.f -- translated by f2c (version 20240504).
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

/* COMMON xs1com_ is declared in common.hpp. */

#define xs1com_1 xs1com_

/* COMMON xs2com_ is declared in common.hpp. */

#define xs2com_1 xs2com_

/* COMMON xs3com_ is declared in common.hpp. */

#define xs3com_1 xs3com_

/* COMMON grvcom_ is declared in common.hpp. */

#define grvcom_1 grvcom_

/* COMMON cdcom_ is declared in common.hpp. */

#define cdcom_1 cdcom_

/* COMMON culcom_ is declared in common.hpp. */

#define culcom_1 culcom_

/* COMMON rdfcom_ is declared in common.hpp. */

#define rdfcom_1 rdfcom_

/* COMMON appcom_ is declared in common.hpp. */

#define appcom_1 appcom_

/* COMMON epscom_ is declared in common.hpp. */

#define epscom_1 epscom_

/* COMMON typlim_ is declared in common.hpp. */

#define typlim_1 typlim_

/* COMMON rty6c_ is declared in common.hpp. */

#define rty6c_1 rty6c_

/* COMMON rty6cc_ is declared in common.hpp. */

#define rty6cc_1 rty6cc_

/* COMMON rty1c_ is declared in common.hpp. */

#define rty1c_1 rty1c_

/* COMMON rty1cc_ is declared in common.hpp. */

#define rty1cc_1 rty1cc_

/* COMMON x43com_ is declared in common.hpp. */

#define x43com_1 x43com_

/* COMMON xs4com_ is declared in common.hpp. */

#define xs4com_1 xs4com_

/* COMMON rty0c_ is declared in common.hpp. */

#define rty0c_1 rty0c_

/* COMMON rty0cc_ is declared in common.hpp. */

#define rty0cc_1 rty0cc_

/* COMMON rqvtw_ is declared in common.hpp. */

#define rqvtw_1 rqvtw_

/* COMMON rqvtc_ is declared in common.hpp. */

#define rqvtc_1 rqvtc_

/* COMMON typtrn_ is declared in common.hpp. */

#define typtrn_1 typtrn_

/* COMMON y1gy2_ is declared in common.hpp. */

#define y1gy2_1 y1gy2_

/* COMMON y1gy2c_ is declared in common.hpp. */

#define y1gy2c_1 y1gy2c_

/* COMMON rty2c_ is declared in common.hpp. */

#define rty2c_1 rty2c_

/* COMMON rty2cc_ is declared in common.hpp. */

#define rty2cc_1 rty2cc_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_2 = 2;
static real c_b52 = (float)0.;
static real c_b59 = (float)1e-6;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_3 = 3;
static integer feq_gen_c_d_4 = 4;
static integer feq_gen_c_d_61 = 61;




/* SOURCE culvertb.for:4 */
/*<       realfunctionrty61(z) >*/
doublereal rty61_(real *feq_gen_z_d_)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *BUG:XXX* No convergence on flow in fun.\
 RTY61\002)";
    static char fmt_52[] = "(/,\002 *ERR:696* Initial submergence of roadway\
 flow starts\002,\002 at elev.=\002,f10.3,/11x,\002but critical-flow elev.\
=\002,f10.3,\002 in culvert exit.\002,/,11x,\002Flow over the road cannot b\
e\002,\002 combined with culvert flow when\002,/,11x,\002critical flow in\
\002,\002 the culvert exit causes submergence of flow over the road.\002)";

    /* System generated locals */
    real ret_val, feq_gen_r_d_1, feq_gen_r_d_2;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer do_fio(integer *, char *, ftnlen);

    /* Local variables */
    real q, dh, qt, yt, zt;
    integer isb;
    real div, dup;
    integer knt;
    real num;
    extern /* Subroutine */ int lkta_(integer *, real *, real *);
    extern doublereal fcd123_(integer *, integer *, char *, real *, real *, 
	    ftnlen);
    integer sflag;
    real fdrdw;
    extern /* Subroutine */ int fndcde_(integer *, integer *, real *, real *);
    extern doublereal degcon_(real *, real *, real *);
    real expfac, aratio, zsbrdf;
    extern /* Subroutine */ int getfrf_(real *, real *, real *), sfpsbe_(
	    integer *, integer *, integer *, real *, real *, real *, integer *
	    , real *, integer *), xlktal_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__10 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__12 = { 0, 0, 0, fmt_52, 0 };


/*     + + + PURPOSE + + + */
/*     Compute residual funtion for finding the boundary of type 2 and */
/*     type 61 flow. */
/* SOURCE culvertb.for:11 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertb.for:14 */
/*<       realz >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Z      - water surface elevation being sought */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertb.for:20 */
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
/* INCLUDE culvertb.for:21 */
/* SOURCE xs1com.cmn:2 */
/*<        >*/
/* SOURCE xs1com.cmn:7 */
/*<       integeradrxs1 >*/
/* SOURCE xs1com.cmn:9 */
/*<        >*/
/*     Z1TY1- elevation at section 1 at type 1 limit if it exists */
/*     Z1TY1L-elevation at section 1 at lower limit of type 1 if it exists */
/*     Z1TY6- elevation at section 1 at start of type 6 if it exists */
/*     Z1TY2- elevation at upper limit of type 2 flow if it exists */
/*     Z1TY61- elevation at upper limt of type 61 if it exists */
/*     Z1TY5- elevation at section at start of type 5 if it exists */
/*     Z1TY52- elevation at section 1 at lower limit of type 52( */
/*             type 2 to type 5 flow) */
/*     Z1TY51- elevation at section 1 at lower limit of type 51( */
/*             type 1 to type 5 flow) */
/* INCLUDE culvertb.for:22 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culvertb.for:23 */
/* SOURCE xs3com.cmn:2 */
/*<        >*/
/* SOURCE xs3com.cmn:11 */
/*<       integeradrxs3 >*/
/* SOURCE xs3com.cmn:13 */
/*<        >*/
/*     CD1- if 0.0 type 1 flow has not been checked, if > 0 type 1 */
/*          flow has been checked and found to exist and its limit */
/*          values have been found, if < 0 type 1 flow does not exist. */
/*     CD2T6- coef. of discharge forcing full flow to match flow */
/*            at the type 2 flow limit. */
/*     AP2T6 - kinetic energy flux coefficient forcing the full */
/*             flow kinetic energy flux to match the flux */
/*             at the type 2 limit. */
/*     BT2T6- momentum flux coefficient forcing the full flow */
/*            momentum flux to match the flux at the type 2 limit. */
/*     CD61T6- coef. of discharge forcing full flow to match flow */
/*             at the type 61 limit. */
/*     CD1T6- coef. of discharge forcing full flow to match flow */
/*            at the type 1 limit */

/*     AP61T6- same as AP2T6 for type 61. */
/*     BT61T6- same as AP2T6 for type 61. */
/*     CD2- coef. of discharge for type 2 flow at the type 2 limit. */
/*     CD61- coef. of discharge for type 61 flow at the type 61 limit. */
/*     CD6- coef. of discharge for type 6 flow. */
/*     Z3PTY6- piezometric level at section 3 at the type 6 limit. */
/*     AVH2- area for velocity head at the type 2 limit. */
/*     AVH61- area for velocity head at the type 61 limit. */
/*     BT3ATD- beta at section 3 when barrel is full(at D!) */
/*     AP3ATD- alpha at section 3 when the barrel is full(at D!) */
/*     CC2T5 - contraction coefficient for type 5 at the type 2 flow */
/*             limit. */
/*     CC1T5 - contraction coefficient for type 5 at the type 1 flow */
/*             limit. */
/*     CC5- contraction coefficient for type 5 at its lower limit */
/*          and above. */
/*     Y3TY52- depth at section 3 at the lower limit of type 52 flow */
/*             giving the transistion between type 2 and type 5. */
/*     Y3TY51- depth at section 3 at the lower limit of type 51 flow */
/*             giving the transistion between type 1 and type 5. */
/*     BT2T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 52 and */
/*             upper limit of type 2. */
/*     BT1T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 51 and */
/*             upper limit of type 1. */
/*     AP2T5-  alpha analogous to BT2T5 */
/*     AP1T5-  alpha analogous to BT1T5 */
/*     Y3TY5-  depth at section 3 at the lower limit of type 5 flow */
/*     BT3AT5- beta for type 5 flow limit */
/*     AP3AT5- alpha for type 5 flow limit */
/*     CD5T4- coefficient of discharge that forces a type 4 equation */
/*            to match the type 5, 51, or 52 flow at the full-flow- */
/*            inducing level at section 43. */
/*     Y3LTY2- depth at section 3 at the type 2 limit, that is, */
/*             critical depth. */
/*     Y3LTY1- submergence depth at section 3  at the limit of */
/*             type 1 flow. */
/*     Y3LTY5- the full-flow-inducing value of piezometric level */
/*             relative to the invert at section 3 for flow types */
/*             5, 51, and 52. */
/* INCLUDE culvertb.for:24 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertb.for:25 */
/* SOURCE cdcom.cmn:2 */
/*<        >*/
/* SOURCE cdcom.cmn:10 */
/*<        >*/
/* SOURCE cdcom.cmn:14 */
/*<        >*/
/*     Add values for support of FHWA type 5 scheme. Oct. 3, 2001 */
/* SOURCE cdcom.cmn:20 */
/*<       realafhwa,cfhwa,yfhwa,sfhwa >*/
/*     AFHWA - value of a */
/*     CFHWA - value of c */
/*     YFHWA - value of Y */
/*     SFHWA - slope of culvert near entrance. */
/* INCLUDE culvertb.for:26 */
/* SOURCE culcom.cmn:2 */
/*<        >*/
/* SOURCE culcom.cmn:8 */
/*<       integernsec(mnbn),hltab(mnbn),iat3d,iat6d,sbkind,sbshape >*/
/* SOURCE culcom.cmn:10 */
/*<        >*/
/* SOURCE culcom.cmn:16 */
/*<       doubleprecisionfrcfac >*/
/*     FRCFAC- friction factor to give factor for friction losses */
/*             in barrel for non-prismatic full-flow that as well */
/*             as prismatic full flow. */
/*     TY1YTD- maximum ratio of depth to vertical diameter for */
/*             type 1 flow. */
/*     TY1HTD- maximum ratio of head at section 1 relative to */
/*             culvert invert at culvert inlet to the vertical */
/*             diamter of the culvert.  Must be less than 1.5. */
/*     SBKIND- if 0 the slope of the culvert barrel is a constant, */
/*             if 1 the slope of the culvert barrel varies. */
/*     BSHAPE- if 0 the barrel shape is constant, that is, prismatic, */
/*             if 1 the barrel shape is nonprismatic. */
/*     TY5SBF- ratio of depth to vertical diameter of the culvert */
/*             at the exit which causes submergence. */
/* Note:  25 August 2004:  SBSHAPE is apparently not used.  BSHAPE */
/* is but outside of a common block. */
/* INCLUDE culvertb.for:27 */
/* SOURCE rdfcom.cmn:2 */
/*<       common/rdfcom/wfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/* SOURCE rdfcom.cmn:4 */
/*<       realwfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/*     WFRDF-WATER FLUX OVER ROAD FREE CONDITION. */
/*     MFRDF-MOMENTUM FLUX OVER THE ROAD FREE CONDITION. */
/*     EFRDF-ENERGY FLUX OVER THE ROAD FREE CONDITION. */
/*     WFRD- WATER FLUX OVER THE ROAD ANY CONDITION. */
/*     MFRD- MOMENTUM FLUX OVER THE ROAD ANY CONDITION. */
/*     EFRD- ENERGY FLUX OVER THE ROAD ANY CONDITION. */
/* INCLUDE culvertb.for:28 */
/* SOURCE appcom.cmn:2 */
/*<       common/appcom/apptab,appelv,applen,applos,appexp,zertab,zerelv >*/
/* SOURCE appcom.cmn:5 */
/*<       integerapptab,zertab >*/
/* SOURCE appcom.cmn:7 */
/*<       realappelv,applen,applos,appexp,zerelv >*/
/* INCLUDE culvertb.for:29 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE culvertb.for:30 */
/*     Common to hold values needed for computing various limits */
/*     for culvert flow types. */
/* SOURCE typlim.cmn:4 */
/*<        >*/
/* SOURCE typlim.cmn:10 */
/*<       integerhhtype >*/
/* SOURCE typlim.cmn:12 */
/*<        >*/
/* INCLUDE culvertb.for:31 */
/*     Commons for function RTY6 in FEQUTL */
/* SOURCE rty6c.cmn:3 */
/*<        >*/
/* SOURCE rty6c.cmn:6 */
/*<       integeriup,idn,outun,ef,conf,ftype,nsf,sbflag >*/
/* SOURCE rty6c.cmn:7 */
/*<       realz1true,aclv,yc,z3pt,aexit,ta1,dht,yat2,zdat >*/
/* SOURCE rty6c.cmn:9 */
/*<       common/rty6cc/class >*/
/* SOURCE rty6c.cmn:10 */
/*<       character*8class >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertb.for:34 */
/*<       integerisb,knt,sflag >*/
/* SOURCE culvertb.for:35 */
/*<       realaratio,dh,div,dup,expfac,fdrdw,num,q,qt,yt,zsbrdf,zt >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertb.for:39 */
/*<       intrinsicabs,sqrt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertb.for:42 */
/*<       realdegcon,fcd123 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertb.for:45 */
/*<       externaldegcon,fcd123,fndcde,getfrf,lkta,sfpsbe,xlktal >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertb.for:48 */
/*<    50 format(/,' *BUG:XXX* No convergence on flow in fun. RTY61') >*/
/* SOURCE culvertb.for:49 */
/*<    52  >*/
/* *********************************************************************** */
/*     Compute the flow in the culvert.  Flow over the road may be */
/*     involved. */
/* SOURCE culvertb.for:57 */
/*<       callgetfrf(z,zsbrdf,fdrdw) >*/
/* L50: */
/* L52: */
    getfrf_(feq_gen_z_d_, &zsbrdf, &fdrdw);
/* SOURCE culvertb.for:60 */
/*<       y1l=z-zb1 >*/
    typlim_1.y1l = static_cast<double>(*feq_gen_z_d_) - xs1com_1.zb1;
/* SOURCE culvertb.for:61 */
/*<       z1l=z >*/
    typlim_1.z1l = *feq_gen_z_d_;
/* SOURCE culvertb.for:62 */
/*<        >*/
    xlktal_(&xs1com_1.adrxs1, &typlim_1.y1l, &typlim_1.a1l, &typlim_1.t1l, &
	    typlim_1.dt1l, &typlim_1.j1l, &typlim_1.k1l, &typlim_1.dk1l, &
	    typlim_1.bet1l, &typlim_1.dbet1l, &typlim_1.alp1l, &
	    typlim_1.dalp1l);
/* SOURCE culvertb.for:68 */
/*<       if(a1l.ge.a2full)then >*/
    if (typlim_1.a1l >= xs2com_1.a2full) {
/* SOURCE culvertb.for:69 */
/*<       expfac=0.0 >*/
	expfac = (float)0.;
/* SOURCE culvertb.for:70 */
/*<       else >*/
    } else {
/* SOURCE culvertb.for:71 */
/*<       aratio=a1l/a2full >*/
	aratio = static_cast<double>(typlim_1.a1l) / xs2com_1.a2full;
/* SOURCE culvertb.for:72 */
/*<       if(aratio.gt.0.95)then >*/
	if (aratio > (float).95) {
/* SOURCE culvertb.for:73 */
/*<       expfac=20.0*(1.0-aratio)*appexp >*/
	    expfac = static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - aratio)) * (float)20.) * appcom_1.appexp;
/* SOURCE culvertb.for:74 */
/*<       else >*/
	} else {
/* SOURCE culvertb.for:75 */
/*<       expfac=appexp >*/
	    expfac = appcom_1.appexp;
/* SOURCE culvertb.for:76 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:77 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:78 */
/*<       q=0 >*/
    q = (float)0.;
/* SOURCE culvertb.for:79 */
/*<       knt=0 >*/
    knt = 0;
/* SOURCE culvertb.for:80 */
/*<        >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(xs2com_1.a2full) / typlim_1.a1l;
/* Computing 2nd power */
    feq_gen_r_d_2 = xs2com_1.a2full;
    div = static_cast<double>(static_cast<double>(static_cast<double>((float)1.) - expfac) - static_cast<double>((static_cast<double>(static_cast<double>(typlim_1.alp1l) * (static_cast<double>((float)1.) - expfac)) - 
	    appcom_1.applos)) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) + static_cast<double>(static_cast<double>(static_cast<double>(appcom_1.applen) * 
	    grvcom_1.grav2) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) / (static_cast<double>(typlim_1.k1l) * xs2com_1.k2full);
/*      WRITE(OUTUN,*) ' RTY61: DIV=',DIV,' Z=',Z,' A1L=',A1L, */
/*     A               ' EXPFAC=',EXPFAC,' A2FULL=',A2FULL, */
/*     B               ' WFRDF=',WFRDF */
/* SOURCE culvertb.for:85 */
/*<       if(div.le.0.0)then >*/
    if (div <= (float)0.) {
/* SOURCE culvertb.for:86 */
/*<       sbflag=-2 >*/
	rty6c_1.sbflag = -2;
/* SOURCE culvertb.for:87 */
/*<       return >*/
	return ret_val;
/* SOURCE culvertb.for:88 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:89 */
/*<   100 continue >*/
L100:
/* SOURCE culvertb.for:90 */
/*<        >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = typlim_1.a1l;
    num = static_cast<double>(grvcom_1.grav2) * (static_cast<double>(static_cast<double>(static_cast<double>(*feq_gen_z_d_) - rty6c_1.yat2) - xs2com_1.zb2) - 
	    static_cast<double>(rdfcom_1.wfrdf) * (static_cast<double>(static_cast<double>(static_cast<double>(q) * appcom_1.applen) / (static_cast<double>(typlim_1.k1l) * 
	    xs2com_1.k2full)) - static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>(q) * (float)2.) + rdfcom_1.wfrdf)) / (
	    static_cast<double>(grvcom_1.grav2) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1))) * (static_cast<double>(static_cast<double>(typlim_1.alp1l) * (static_cast<double>((float)1.) - 
	    expfac)) - appcom_1.applos)));
/*        WRITE(OUTUN,*) ' RTY61: YAT2=',YAT2,' ZB2=',ZB2,' K1L=',K1L, */
/*     A                 ' K2FULL=',K2FULL,' APPLOS=',APPLOS */
/*        WRITE(OUTUN,*) ' NUM=',NUM */
/* SOURCE culvertb.for:96 */
/*<       if(num.lt.0.0)then >*/
    if (num < (float)0.) {
/* SOURCE culvertb.for:97 */
/*<       sbflag=-1 >*/
	rty6c_1.sbflag = -1;
/* SOURCE culvertb.for:98 */
/*<       return >*/
	return ret_val;
/* SOURCE culvertb.for:99 */
/*<       endif >*/
    }
/*        WRITE(OUTUN,*) 'RTY61: A2FULL=',A2FULL,' NUM=',NUM,' DIV=',DIV */
/*        WRITE(OUTUN,*) ' Z=',Z,' YAT2+ZB2=',YAT2+ZB2,' WFRDF=',WFRDF, */
/*     A          ' A1L=',A1L,' K1L=',K1L,' K2FULL=',K2FULL, */
/*     B          ' ALP1L=',ALP1L,' APPLOS=',APPLOS,' GRAV2=',GRAV2, */
/*     C          ' APPLEN=',APPLEN,' Q=',Q */
/* SOURCE culvertb.for:105 */
/*<       qt=a2full*sqrt(num/div) >*/
    qt = xs2com_1.a2full * sqrt(static_cast<double>(num) / div);
/* SOURCE culvertb.for:106 */
/*<       if(wfrdf.gt.0.0)then >*/
    if (rdfcom_1.wfrdf > (float)0.) {
/* SOURCE culvertb.for:107 */
/*<       knt=knt+1 >*/
	++knt;
/* SOURCE culvertb.for:108 */
/*<       if(knt.gt.100)then >*/
	if (knt > 100) {
/* SOURCE culvertb.for:109 */
/*<       write(outun,50) >*/
	    feq_gen_io_d__10.ciunit = rty6c_1.outun;
	    s_wsfe(&feq_gen_io_d__10);
	    e_wsfe();
/* SOURCE culvertb.for:110 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:111 */
/*<       endif >*/
	}
/*         Iterate to find the effect of roadflow. */
/* SOURCE culvertb.for:113 */
/*<       if(abs(q-qt)/qt.gt.epsf)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(q) - qt, dabs(feq_gen_r_d_1)) / qt > epscom_1.epsf) {
/* SOURCE culvertb.for:114 */
/*<       q=qt >*/
	    q = qt;
/* SOURCE culvertb.for:115 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE culvertb.for:116 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:117 */
/*<       endif >*/
    }
/*      WRITE(OUTUN,*) ' QT=',QT */
/* SOURCE culvertb.for:119 */
/*<       q1l=qt+wfrdf >*/
    typlim_1.q1l = static_cast<double>(qt) + rdfcom_1.wfrdf;
/* SOURCE culvertb.for:120 */
/*<       q2l=qt >*/
    typlim_1.q2l = qt;
/* SOURCE culvertb.for:121 */
/*<       q3l=qt >*/
    typlim_1.q3l = qt;
/* SOURCE culvertb.for:123 */
/*<       dup=dvec(iup) >*/
    dup = culcom_1.dvec[rty6c_1.iup - 1];
/*     COMPUTE CRITICAL DEPTH AT SECTION 3 */
/* SOURCE culvertb.for:126 */
/*<       y3part=0.6*dup >*/
    typlim_1.y3part = static_cast<double>(dup) * (float).6;
/* SOURCE culvertb.for:127 */
/*<       callfndcde(outun,adrxs3,q3l,y3part) >*/
    fndcde_(&rty6c_1.outun, &xs3com_1.adrxs3, &typlim_1.q3l, &typlim_1.y3part)
	    ;
/* SOURCE culvertb.for:130 */
/*<       z3part=zb3+y3part >*/
    typlim_1.z3part = static_cast<double>(xs3com_1.zb3) + typlim_1.y3part;
/* SOURCE culvertb.for:131 */
/*<       if(z3part.gt.zsbrdf)then >*/
    if (typlim_1.z3part > zsbrdf) {
/*       Critical depth in the culvert exit drowns free flow */
/*       over the road.  Cannot handle at this time. */
/* SOURCE culvertb.for:134 */
/*<       write(outun,52)zsbrdf+zdat,z3part+zdat >*/
	feq_gen_io_d__12.ciunit = rty6c_1.outun;
	s_wsfe(&feq_gen_io_d__12);
	feq_gen_r_d_1 = static_cast<double>(zsbrdf) + rty6c_1.zdat;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	feq_gen_r_d_2 = static_cast<double>(typlim_1.z3part) + rty6c_1.zdat;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culvertb.for:135 */
/*<       ef=1 >*/
	rty6c_1.ef = 1;
/* SOURCE culvertb.for:136 */
/*<       return >*/
	return ret_val;
/* SOURCE culvertb.for:137 */
/*<       endif >*/
    }
/*      WRITE(OUTUN,*) ' RTY61:  Q2L=',Q2L,' Y3PART=',Y3PART */
/* SOURCE culvertb.for:141 */
/*<       calllkta(adrxs3,y3part,a3part) >*/
    lkta_(&xs3com_1.adrxs3, &typlim_1.y3part, &typlim_1.a3part);
/* SOURCE culvertb.for:145 */
/*<       if(ftype.eq.2)then >*/
    if (rty6c_1.ftype == 2) {
/* SOURCE culvertb.for:146 */
/*<       c123=fcd123(outun,2,class,dup,z) >*/
	cdcom_1.c123 = fcd123_(&rty6c_1.outun, &feq_gen_c_d_2, rty6cc_1.feq_gen_class_d_, &dup, 
		feq_gen_z_d_, (ftnlen)8);
/* SOURCE culvertb.for:147 */
/*<       cd=degcon(c123,a1l,a3part) >*/
	cdcom_1.cd = degcon_(&cdcom_1.c123, &typlim_1.a1l, &typlim_1.a3part);
/* SOURCE culvertb.for:148 */
/*<       avh=a3part >*/
	cdcom_1.avh = typlim_1.a3part;
/* SOURCE culvertb.for:149 */
/*<       else >*/
    } else {
/* SOURCE culvertb.for:150 */
/*<       cd=c46 >*/
	cdcom_1.cd = cdcom_1.c46;
/* SOURCE culvertb.for:151 */
/*<       avh=a2full >*/
	cdcom_1.avh = xs2com_1.a2full;
/* SOURCE culvertb.for:152 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:154 */
/*<       dh=(1.0/cd**2-1.0)*(q3l/avh)**2/grav2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = cdcom_1.cd;
/* Computing 2nd power */
    feq_gen_r_d_2 = static_cast<double>(typlim_1.q3l) / cdcom_1.avh;
    dh = static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - (float)1.)) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) / 
	    grvcom_1.grav2;
/*      WRITE(OUTUN,*) ' RTY61: A1=',A1L,' Z3PART=',Z3PART, */
/*     A              ' CD=',CD,' A3PART=',A3PART,' DH=',DH */
/* SOURCE culvertb.for:159 */
/*<       callsfpsbe(outun,iup,idn,dh,qt,z3part,isb,zt,sflag) >*/
    sfpsbe_(&rty6c_1.outun, &rty6c_1.iup, &rty6c_1.idn, &dh, &qt, &
	    typlim_1.z3part, &isb, &zt, &sflag);
/* SOURCE culvertb.for:162 */
/*<       if(sflag.eq.1)then >*/
    if (sflag == 1) {
/* SOURCE culvertb.for:163 */
/*<       yt=zt-zb2 >*/
	yt = static_cast<double>(zt) - xs2com_1.zb2;
/* SOURCE culvertb.for:164 */
/*<       sbflag=0 >*/
	rty6c_1.sbflag = 0;
/* SOURCE culvertb.for:165 */
/*<       else >*/
    } else {
/* SOURCE culvertb.for:166 */
/*<       sbflag=-1 >*/
	rty6c_1.sbflag = -1;
/*        WRITE(OUTUN,*) ' SFP FAILED: ISB=',ISB */
/* SOURCE culvertb.for:168 */
/*<       return >*/
	return ret_val;
/* SOURCE culvertb.for:169 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:171 */
/*<       rty61=(yt-yat2)/yat2 >*/
    ret_val = static_cast<double>((static_cast<double>(yt) - rty6c_1.yat2)) / rty6c_1.yat2;
/*      WRITE(OUTUN,*) ' RTY61 EXIT: RTY61=',RTY61,' FTYPE=',FTYPE, */
/*     A               ' Q=',QT,' Z=',Z,' SFLAG=',SFLAG */
/* SOURCE culvertb.for:175 */
/*<       return >*/
    return ret_val;
/* SOURCE culvertb.for:176 */
/*<       end >*/
} /* rty61_ */




/* SOURCE culvertb.for:180 */
/*<       realfunctionrty1(y) >*/
doublereal rty1_(real *y)
{
    /* System generated locals */
    real ret_val, feq_gen_r_d_1;

    /* Local variables */
    real q1c, q2c, vh1, vh2, cdin;
    extern doublereal fcd123_(integer *, integer *, char *, real *, real *, 
	    ftnlen);
    extern /* Subroutine */ int lktqc_(integer *, real *, real *), xlkt22_(
	    integer *, real *, real *, real *, real *, real *, real *, real *,
	     real *, real *, real *, real *, real *);
    real appfac;
    extern doublereal degcon_(real *, real *, real *);
    real aratio;

/*     + + + PURPOSE + + + */
/*     Compute the residual function for type 1 flow */
/* SOURCE culvertb.for:186 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertb.for:189 */
/*<       realy >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Y      - maximum depth in a cross section */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertb.for:195 */
/* SOURCE xs1com.cmn:2 */
/*<        >*/
/* SOURCE xs1com.cmn:7 */
/*<       integeradrxs1 >*/
/* SOURCE xs1com.cmn:9 */
/*<        >*/
/*     Z1TY1- elevation at section 1 at type 1 limit if it exists */
/*     Z1TY1L-elevation at section 1 at lower limit of type 1 if it exists */
/*     Z1TY6- elevation at section 1 at start of type 6 if it exists */
/*     Z1TY2- elevation at upper limit of type 2 flow if it exists */
/*     Z1TY61- elevation at upper limt of type 61 if it exists */
/*     Z1TY5- elevation at section at start of type 5 if it exists */
/*     Z1TY52- elevation at section 1 at lower limit of type 52( */
/*             type 2 to type 5 flow) */
/*     Z1TY51- elevation at section 1 at lower limit of type 51( */
/*             type 1 to type 5 flow) */
/* INCLUDE culvertb.for:196 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culvertb.for:197 */
/* SOURCE appcom.cmn:2 */
/*<       common/appcom/apptab,appelv,applen,applos,appexp,zertab,zerelv >*/
/* SOURCE appcom.cmn:5 */
/*<       integerapptab,zertab >*/
/* SOURCE appcom.cmn:7 */
/*<       realappelv,applen,applos,appexp,zerelv >*/
/* INCLUDE culvertb.for:198 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertb.for:199 */
/* SOURCE cdcom.cmn:2 */
/*<        >*/
/* SOURCE cdcom.cmn:10 */
/*<        >*/
/* SOURCE cdcom.cmn:14 */
/*<        >*/
/*     Add values for support of FHWA type 5 scheme. Oct. 3, 2001 */
/* SOURCE cdcom.cmn:20 */
/*<       realafhwa,cfhwa,yfhwa,sfhwa >*/
/*     AFHWA - value of a */
/*     CFHWA - value of c */
/*     YFHWA - value of Y */
/*     SFHWA - slope of culvert near entrance. */
/* INCLUDE culvertb.for:200 */
/* SOURCE rdfcom.cmn:2 */
/*<       common/rdfcom/wfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/* SOURCE rdfcom.cmn:4 */
/*<       realwfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/*     WFRDF-WATER FLUX OVER ROAD FREE CONDITION. */
/*     MFRDF-MOMENTUM FLUX OVER THE ROAD FREE CONDITION. */
/*     EFRDF-ENERGY FLUX OVER THE ROAD FREE CONDITION. */
/*     WFRD- WATER FLUX OVER THE ROAD ANY CONDITION. */
/*     MFRD- MOMENTUM FLUX OVER THE ROAD ANY CONDITION. */
/*     EFRD- ENERGY FLUX OVER THE ROAD ANY CONDITION. */
/* INCLUDE culvertb.for:201 */
/*     Common for function RTY1 in FEQUTL */
/* SOURCE rty1c.cmn:3 */
/*<       common/rty1c/du,ftype,outun1,frsq,dhty1 >*/
/* SOURCE rty1c.cmn:4 */
/*<       character*8class1 >*/
/* SOURCE rty1c.cmn:5 */
/*<       integerftype,outun1 >*/
/* SOURCE rty1c.cmn:6 */
/*<       realdu,frsq,dhty1 >*/
/* SOURCE rty1c.cmn:8 */
/*<       common/rty1cc/class1 >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertb.for:204 */
/*<       realappfac,aratio,cdin,q1c,q2c,vh1,vh2 >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertb.for:207 */
/*<       realdegcon,fcd123 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertb.for:210 */
/*<       externaldegcon,fcd123,lktqc,xlkt22 >*/
/* *********************************************************************** */
/*     GET VALUES AT SECTION 2 */
/* SOURCE culvertb.for:213 */
/*<       y2=y >*/
    xs2com_1.y2 = *y;
/* SOURCE culvertb.for:214 */
/*<        >*/
    xlkt22_(&xs2com_1.adrxs2, &xs2com_1.y2, &xs2com_1.a2, &xs2com_1.t2, &
	    xs2com_1.dt2, &xs2com_1.j2, &xs2com_1.k2, &xs2com_1.dk2, &
	    xs2com_1.bet2, &xs2com_1.dbet2, &xs2com_1.alp2, &xs2com_1.dalp2, &
	    q2c);
/* SOURCE culvertb.for:220 */
/*<       q2=q2c >*/
    xs2com_1.q2 = q2c;
/*     ADD IN THE FREE FLOW OVER THE ROADWAY */
/* SOURCE culvertb.for:223 */
/*<       q1=q2+wfrdf >*/
    xs1com_1.q1 = static_cast<double>(xs2com_1.q2) + rdfcom_1.wfrdf;
/*     COMPUTE SQUARE OF FROUDE NUMBER IN APPROACH SECTION */
/* SOURCE culvertb.for:226 */
/*<       calllktqc(adrxs1,y1,q1c) >*/
    lktqc_(&xs1com_1.adrxs1, &xs1com_1.y1, &q1c);
/* SOURCE culvertb.for:231 */
/*<       frsq=(q1/q1c)**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(xs1com_1.q1) / q1c;
    rty1c_1.frsq = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE culvertb.for:233 */
/*<       z2=zb2+y2 >*/
    xs2com_1.z2 = static_cast<double>(xs2com_1.zb2) + xs2com_1.y2;
/* SOURCE culvertb.for:235 */
/*<       vh1=(q1/a1)**2/grav2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(xs1com_1.q1) / xs1com_1.a1;
    vh1 = static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / grvcom_1.grav2;
/* SOURCE culvertb.for:236 */
/*<       vh2=(q2/a2)**2/grav2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(xs2com_1.q2) / xs2com_1.a2;
    vh2 = static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / grvcom_1.grav2;
/*      WRITE(OUTUN1,*) ' VH1=',VH1,' VH2=',VH2 */
/*      WRITE(OUTUN1,*) ' A1=',A1,' A2=',A2,' GRAV2=',GRAV2 */
/*     CHECK FOR EXPANSION INSTEAD OF CONTRACTION. */
/*      IF(VH2.GT.VH1) THEN */
/* SOURCE culvertb.for:242 */
/*<       if(a1.gt.a2)then >*/
    if (xs1com_1.a1 > xs2com_1.a2) {
/*       WE HAVE A CONTRACTION(I.E. ACCELERATION OF FLOW) */
/*       DEFINE THE COEF OF DISHCHARGE */
/*        CONF = 1 */
/* SOURCE culvertb.for:246 */
/*<       c123=fcd123(outun1,ftype,class1,du,z1) >*/
	cdcom_1.c123 = fcd123_(&rty1c_1.outun1, &rty1c_1.ftype, 
		rty1cc_1.class1, &rty1c_1.du, &xs1com_1.z1, (ftnlen)8);
/*        WRITE(OUTUN1,*) ' RTY1: C123=',C123,' FTYPE=',FTYPE */
/*       MAKE ADJUSTMENTS TO THE COEF. OF DISCHARGE FOR THE DEGREE OF */
/*       CHANNEL CONTRACTION */
/* SOURCE culvertb.for:251 */
/*<       cd=degcon(c123,a1,a2) >*/
	cdcom_1.cd = degcon_(&cdcom_1.c123, &xs1com_1.a1, &xs2com_1.a2);
/*        WRITE(OUTUN1,*) ' RTY1: CD=',CD,' A1=',A1,' A2=',A2 */
/* SOURCE culvertb.for:253 */
/*<        >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = cdcom_1.cd;
	ret_val = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>(xs1com_1.alp1) - appcom_1.applos)) * vh1) - static_cast<double>((static_cast<double>(xs2com_1.alp2) + (
		static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - (float)1.))) * vh2) + xs1com_1.z1) - 
		xs2com_1.z2) - static_cast<double>(static_cast<double>(static_cast<double>(appcom_1.applen) * xs1com_1.q1) * xs2com_1.q2) / (
		static_cast<double>(xs1com_1.k1) * xs2com_1.k2);
/* SOURCE culvertb.for:255 */
/*<       else >*/
    } else {
/*        CONF = 0 */
/*       WE HAVE AN EXPANSION(I.E. DECELERATION OF FLOW) */
/* SOURCE culvertb.for:258 */
/*<       aratio=a1/a2 >*/
	aratio = static_cast<double>(xs1com_1.a1) / xs2com_1.a2;
/* SOURCE culvertb.for:259 */
/*<       if(aratio.gt.0.95)then >*/
	if (aratio > (float).95) {
/*         Interpolate coefficients to make the transistion between */
/*         the two cases smooth.  Define the coefficient for standard */
/*         type 1 case. */
/* SOURCE culvertb.for:264 */
/*<       c123=fcd123(outun1,ftype,class1,du,z1) >*/
	    cdcom_1.c123 = fcd123_(&rty1c_1.outun1, &rty1c_1.ftype, 
		    rty1cc_1.class1, &rty1c_1.du, &xs1com_1.z1, (ftnlen)8);
/*         MAKE ADJUSTMENTS TO THE COEF. OF DISCHARGE FOR THE DEGREE OF */
/*         CHANNEL CONTRACTION */
/* SOURCE culvertb.for:269 */
/*<       cdin=degcon(c123,a1,a2) >*/
	    cdin = degcon_(&cdcom_1.c123, &xs1com_1.a1, &xs2com_1.a2);
/* SOURCE culvertb.for:271 */
/*<       cd=cdin+20.0*(1.0-aratio)*(0.98-cdin) >*/
	    cdcom_1.cd = static_cast<double>(cdin) + static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - aratio)) * (float)20.) * (static_cast<double>((float)
		    .98) - cdin);
/* SOURCE culvertb.for:272 */
/*<       appfac=20.0*(1.0-aratio)*appexp >*/
	    appfac = static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - aratio)) * (float)20.) * appcom_1.appexp;
/* SOURCE culvertb.for:273 */
/*<       else >*/
	} else {
/* SOURCE culvertb.for:274 */
/*<       cd=0.98 >*/
	    cdcom_1.cd = (float).98;
/* SOURCE culvertb.for:275 */
/*<       appfac=appexp >*/
	    appfac = appcom_1.appexp;
/* SOURCE culvertb.for:276 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:278 */
/*<        >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = cdcom_1.cd;
	ret_val = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>(xs1com_1.alp1) - appcom_1.applos)) * vh1) - static_cast<double>((static_cast<double>(xs2com_1.alp2) + (
		static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - (float)1.))) * vh2) + xs1com_1.z1) - 
		xs2com_1.z2) - static_cast<double>(static_cast<double>(static_cast<double>(appcom_1.applen) * xs1com_1.q1) * xs2com_1.q2) / (
		static_cast<double>(xs1com_1.k1) * xs2com_1.k2)) - static_cast<double>(appfac) * (static_cast<double>(static_cast<double>(xs1com_1.alp1) * vh1) - 
		static_cast<double>(xs2com_1.alp2) * vh2);
/* SOURCE culvertb.for:282 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:283 */
/*<       dhty1=(1./cd**2-1.)*vh2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = cdcom_1.cd;
    rty1c_1.dhty1 = static_cast<double>((static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - (float)1.)) * vh2;
/*      WRITE(OUTUN1,*) ' AT Y=',Y,' RTY1=',RTY1,' CD=',CD */
/*      WRITE(OUTUN1,*) ' Q1=',Q1,' Q2=',Q2,' FRSQ=',FRSQ */
/*      WRITE(OUTUN1,*) ' TYPE1 LOSS =',DHTY1,' CONF=',CONF */
/* SOURCE culvertb.for:288 */
/*<       return >*/
    return ret_val;
/* SOURCE culvertb.for:289 */
/*<       end >*/
} /* rty1_ */




/* SOURCE culvertb.for:293 */
/*<       realfunctionry2gy1(y) >*/
doublereal ry2gy1_(real *y)
{
    /* System generated locals */
    real ret_val, feq_gen_r_d_1;

    /* Local variables */
    real q1c, q2c, vh1, vh2, cdin;
    extern doublereal fcd123_(integer *, integer *, char *, real *, real *, 
	    ftnlen);
    extern /* Subroutine */ int lktqc_(integer *, real *, real *), xlkt22_(
	    integer *, real *, real *, real *, real *, real *, real *, real *,
	     real *, real *, real *, real *, real *);
    real appfac;
    extern doublereal degcon_(real *, real *, real *);
    real aratio;

/*     + + + PURPOSE + + + */
/*     Compute the residual function for type 1 flow */
/* SOURCE culvertb.for:299 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertb.for:302 */
/*<       realy >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Y      - value of the unknown being sought */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertb.for:308 */
/* SOURCE xs1com.cmn:2 */
/*<        >*/
/* SOURCE xs1com.cmn:7 */
/*<       integeradrxs1 >*/
/* SOURCE xs1com.cmn:9 */
/*<        >*/
/*     Z1TY1- elevation at section 1 at type 1 limit if it exists */
/*     Z1TY1L-elevation at section 1 at lower limit of type 1 if it exists */
/*     Z1TY6- elevation at section 1 at start of type 6 if it exists */
/*     Z1TY2- elevation at upper limit of type 2 flow if it exists */
/*     Z1TY61- elevation at upper limt of type 61 if it exists */
/*     Z1TY5- elevation at section at start of type 5 if it exists */
/*     Z1TY52- elevation at section 1 at lower limit of type 52( */
/*             type 2 to type 5 flow) */
/*     Z1TY51- elevation at section 1 at lower limit of type 51( */
/*             type 1 to type 5 flow) */
/* INCLUDE culvertb.for:309 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culvertb.for:310 */
/*     Common to hold values needed for computing various limits */
/*     for culvert flow types. */
/* SOURCE typlim.cmn:4 */
/*<        >*/
/* SOURCE typlim.cmn:10 */
/*<       integerhhtype >*/
/* SOURCE typlim.cmn:12 */
/*<        >*/
/* INCLUDE culvertb.for:311 */
/* SOURCE appcom.cmn:2 */
/*<       common/appcom/apptab,appelv,applen,applos,appexp,zertab,zerelv >*/
/* SOURCE appcom.cmn:5 */
/*<       integerapptab,zertab >*/
/* SOURCE appcom.cmn:7 */
/*<       realappelv,applen,applos,appexp,zerelv >*/
/* INCLUDE culvertb.for:312 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertb.for:313 */
/* SOURCE cdcom.cmn:2 */
/*<        >*/
/* SOURCE cdcom.cmn:10 */
/*<        >*/
/* SOURCE cdcom.cmn:14 */
/*<        >*/
/*     Add values for support of FHWA type 5 scheme. Oct. 3, 2001 */
/* SOURCE cdcom.cmn:20 */
/*<       realafhwa,cfhwa,yfhwa,sfhwa >*/
/*     AFHWA - value of a */
/*     CFHWA - value of c */
/*     YFHWA - value of Y */
/*     SFHWA - slope of culvert near entrance. */
/* INCLUDE culvertb.for:314 */
/* SOURCE rdfcom.cmn:2 */
/*<       common/rdfcom/wfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/* SOURCE rdfcom.cmn:4 */
/*<       realwfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/*     WFRDF-WATER FLUX OVER ROAD FREE CONDITION. */
/*     MFRDF-MOMENTUM FLUX OVER THE ROAD FREE CONDITION. */
/*     EFRDF-ENERGY FLUX OVER THE ROAD FREE CONDITION. */
/*     WFRD- WATER FLUX OVER THE ROAD ANY CONDITION. */
/*     MFRD- MOMENTUM FLUX OVER THE ROAD ANY CONDITION. */
/*     EFRD- ENERGY FLUX OVER THE ROAD ANY CONDITION. */
/* INCLUDE culvertb.for:315 */
/*     Common for function RTY1 in FEQUTL */
/* SOURCE rty1c.cmn:3 */
/*<       common/rty1c/du,ftype,outun1,frsq,dhty1 >*/
/* SOURCE rty1c.cmn:4 */
/*<       character*8class1 >*/
/* SOURCE rty1c.cmn:5 */
/*<       integerftype,outun1 >*/
/* SOURCE rty1c.cmn:6 */
/*<       realdu,frsq,dhty1 >*/
/* SOURCE rty1c.cmn:8 */
/*<       common/rty1cc/class1 >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertb.for:318 */
/*<       realappfac,aratio,cdin,q1c,q2c,vh1,vh2 >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertb.for:321 */
/*<       realdegcon,fcd123 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertb.for:324 */
/*<       externaldegcon,fcd123,lktqc,xlkt22 >*/
/* *********************************************************************** */
/*     GET VALUES AT SECTION 2 */
/* SOURCE culvertb.for:327 */
/*<       y2l=y >*/
    typlim_1.y2l = *y;
/* SOURCE culvertb.for:328 */
/*<        >*/
    xlkt22_(&xs2com_1.adrxs2, &typlim_1.y2l, &typlim_1.a2l, &typlim_1.t2l, &
	    typlim_1.dt2l, &typlim_1.j2l, &typlim_1.k2l, &typlim_1.dk2l, &
	    typlim_1.bet2l, &typlim_1.dbet2l, &typlim_1.alp2l, &
	    typlim_1.dalp2l, &q2c);
/* SOURCE culvertb.for:334 */
/*<       q2l=q2c >*/
    typlim_1.q2l = q2c;
/*     ADD IN THE FREE FLOW OVER THE ROADWAY */
/* SOURCE culvertb.for:337 */
/*<       q1l=q2l+wfrdf >*/
    typlim_1.q1l = static_cast<double>(typlim_1.q2l) + rdfcom_1.wfrdf;
/*     COMPUTE SQUARE OF FROUDE NUMBER IN APPROACH SECTION */
/* SOURCE culvertb.for:340 */
/*<       calllktqc(adrxs1,y1l,q1c) >*/
    lktqc_(&xs1com_1.adrxs1, &typlim_1.y1l, &q1c);
/* SOURCE culvertb.for:345 */
/*<       frsq=(q1l/q1c)**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(typlim_1.q1l) / q1c;
    rty1c_1.frsq = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE culvertb.for:347 */
/*<       z2l=zb2+y2l >*/
    typlim_1.z2l = static_cast<double>(xs2com_1.zb2) + typlim_1.y2l;
/* SOURCE culvertb.for:349 */
/*<       vh1=(q1l/a1l)**2/grav2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(typlim_1.q1l) / typlim_1.a1l;
    vh1 = static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / grvcom_1.grav2;
/* SOURCE culvertb.for:350 */
/*<       vh2=(q2l/a2l)**2/grav2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(typlim_1.q2l) / typlim_1.a2l;
    vh2 = static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / grvcom_1.grav2;
/*      WRITE(OUTUN1,*) ' RY2GY1: VH1=',VH1,' VH2=',VH2 */
/*      WRITE(OUTUN1,*) ' RY2GY1; A1L=',A1L,' A2L=',A2L,' GRAV2=',GRAV2 */
/*     CHECK FOR EXPANSION INSTEAD OF CONTRACTION. */
/* SOURCE culvertb.for:355 */
/*<       if(a1l.gt.a2l)then >*/
    if (typlim_1.a1l > typlim_1.a2l) {
/*       WE HAVE A CONTRACTION(I.E. ACCELERATION OF FLOW) */
/*       DEFINE THE COEF OF DISHCHARGE */
/* SOURCE culvertb.for:358 */
/*<       c123=fcd123(outun1,ftype,class1,du,z1l) >*/
	cdcom_1.c123 = fcd123_(&rty1c_1.outun1, &rty1c_1.ftype, 
		rty1cc_1.class1, &rty1c_1.du, &typlim_1.z1l, (ftnlen)8);
/*       MAKE ADJUSTMENTS TO THE COEF. OF DISCHARGE FOR THE DEGREE OF */
/*       CHANNEL CONTRACTION */
/* SOURCE culvertb.for:363 */
/*<       cd=degcon(c123,a1l,a2l) >*/
	cdcom_1.cd = degcon_(&cdcom_1.c123, &typlim_1.a1l, &typlim_1.a2l);
/* SOURCE culvertb.for:365 */
/*<        >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = cdcom_1.cd;
	ret_val = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>(typlim_1.alp1l) - appcom_1.applos)) * vh1) - static_cast<double>((static_cast<double>(typlim_1.alp2l) 
		+ (static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - (float)1.))) * vh2) + 
		typlim_1.z1l) - typlim_1.z2l) - static_cast<double>(static_cast<double>(static_cast<double>(appcom_1.applen) * typlim_1.q1l) *
		 typlim_1.q2l) / (static_cast<double>(typlim_1.k1l) * typlim_1.k2l);
/* SOURCE culvertb.for:367 */
/*<       else >*/
    } else {
/*       WE HAVE AN EXPANSION(I.E. DECELERATION OF FLOW) */
/* SOURCE culvertb.for:369 */
/*<       aratio=a1l/a2l >*/
	aratio = static_cast<double>(typlim_1.a1l) / typlim_1.a2l;
/* SOURCE culvertb.for:370 */
/*<       if(aratio.gt.0.95)then >*/
	if (aratio > (float).95) {
/*         Interpolate coefficients to make the transistion between */
/*         the two cases smooth.  Define the coefficient for standard */
/*         type 1 case. */
/* SOURCE culvertb.for:375 */
/*<       c123=fcd123(outun1,ftype,class1,du,z1l) >*/
	    cdcom_1.c123 = fcd123_(&rty1c_1.outun1, &rty1c_1.ftype, 
		    rty1cc_1.class1, &rty1c_1.du, &typlim_1.z1l, (ftnlen)8);
/*         MAKE ADJUSTMENTS TO THE COEF. OF DISCHARGE FOR THE DEGREE OF */
/*         CHANNEL CONTRACTION */
/* SOURCE culvertb.for:380 */
/*<       cdin=degcon(c123,a1l,a2l) >*/
	    cdin = degcon_(&cdcom_1.c123, &typlim_1.a1l, &typlim_1.a2l);
/* SOURCE culvertb.for:382 */
/*<       cd=cdin+20.0*(1.0-aratio)*(0.98-cdin) >*/
	    cdcom_1.cd = static_cast<double>(cdin) + static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - aratio)) * (float)20.) * (static_cast<double>((float)
		    .98) - cdin);
/* SOURCE culvertb.for:383 */
/*<       appfac=20.0*(1.0-aratio)*appexp >*/
	    appfac = static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - aratio)) * (float)20.) * appcom_1.appexp;
/* SOURCE culvertb.for:384 */
/*<       else >*/
	} else {
/* SOURCE culvertb.for:385 */
/*<       cd=0.98 >*/
	    cdcom_1.cd = (float).98;
/* SOURCE culvertb.for:386 */
/*<       appfac=appexp >*/
	    appfac = appcom_1.appexp;
/* SOURCE culvertb.for:387 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:389 */
/*<        >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = cdcom_1.cd;
	ret_val = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>(typlim_1.alp1l) - appcom_1.applos)) * vh1) - static_cast<double>((static_cast<double>(typlim_1.alp2l) 
		+ (static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - (float)1.))) * vh2) + 
		typlim_1.z1l) - typlim_1.z2l) - static_cast<double>(static_cast<double>(static_cast<double>(appcom_1.applen) * typlim_1.q1l) *
		 typlim_1.q2l) / (static_cast<double>(typlim_1.k1l) * typlim_1.k2l)) - static_cast<double>(appfac) * (
		static_cast<double>(static_cast<double>(typlim_1.alp1l) * vh1) - static_cast<double>(typlim_1.alp2l) * vh2);
/* SOURCE culvertb.for:393 */
/*<       endif >*/
    }
/*      WRITE(OUTUN1,*) ' AT Y=',Y,' RY2GY1=',RY2GY1,' CD=',CD */
/*      WRITE(OUTUN1,*) ' Q1L=',Q1L,' Q2L=',Q2L,' FRSQ=',FRSQ */
/* SOURCE culvertb.for:398 */
/*<       return >*/
    return ret_val;
/* SOURCE culvertb.for:399 */
/*<       end >*/
} /* ry2gy1_ */




/* SOURCE culvertb.for:403 */
/*<        >*/
/* Subroutine */ int frft0_(integer *stdout, real *hdatum, real *hup, integer 
	*iu, integer *id, char *culcls, integer *eflag, integer *feq_gen_type_d_, 
	integer *expflg, real *zsbrdf, real *qfree, real *freed, ftnlen 
	culcls_len)
{
    /* Format strings */
    static char fmt_54[] = "(\002 *BUG:XXX* SIGN CHNG ON ENTRY BUT RGF3 CLAI\
MS NONE IN\002,\002 FRFT0.\002)";
    static char fmt_60[] = "(\002 *BUG:XXX* RGF3: MORE THAN 100 ITERATIONS I\
N FRFT0.\002)";
    static char fmt_66[] = "(/,\002 Type 0 flow drowned by control at sectio\
n 2.\002)";
    static char fmt_68[] = "(/,\002 Type 0 flow drowned by control at sectio\
n 3.\002)";
    static char fmt_70[] = "(/,\002 Flow is type 0. Flow in barrel=\002,f10.\
2,\002 Road flow=\002,f10.2)";
    static char fmt_72[] = "(/,\002 *ERR:699* No result at section 2 for flo\
w type 0\002,\002 after 100 tries.\002)";
    static char fmt_76[] = "(/,\002 *WRN:575* Minimum depth at section 2=\
\002,f8.2,\002 reached\002,\002 and no\002,/,11x,\002positive residual for f\
low type 0\002,/,11x,\002when holding road flow fixed.\002)";
    static char fmt_78[] = "(/,\002 *WRN:576* Type 0 flow has tailwater at s\
ection 43\002,\002 higher\002,/,11x,\002than road crest or submergence limit\
 by\002,f8.3)";
    static char fmt_80[] = "(/,\002 *WRN:577* Type 0 flow also has tailwater\
 at section\002,\002 43 higher\002,/,11x,\002than elevation at section 1.  T\
his is\002,\002 peculiar\002,/,11x,\002 but not impossible.  Please revie\
w\002,\002 input carefully.\002)";
    static char fmt_82[] = "(/,\002 *WRN:578 Unable to complete profile when\
 roadflow\002,\002 is constant.\002)";
    static char fmt_84[] = "(/,\002*ERR:700* Barrel flows full with type 0 f\
low. \002,\002 Culvert representation MUST be\002,/,11x,\002 changed.  Type \
0 flow\002,\002 invalid at this flow level.\002,/,11x,\002  See error messag\
e summary.\002)";
    static char fmt_86[] = "(/,\002 Elev. of energy grade line at section 1\
=\002,f7.3,\002 > \002,f7.3,\002, elev. at section 2.\002)";
    static char fmt_88[] = "(\002 Elev. of energy grade line at section 1\
=\002,f7.3,\002 > \002,f7.3,\002, elev. at section 3.\002)";
    static char fmt_90[] = "(/,\002 *ERR:701* Flow over the road=\002,f10.1\
,\002 > critical \002,\002flow at section 1=\002,f10.1,/,11x,\002 for type 0\
 flow.  Culvert \002,\002 representation MUST be changed.\002,/,11x,\002  Se\
e error message summary.\002)";
    static char fmt_92[] = "(/,\002 Testing for flow type 0 at upstream head\
 =\002,f8.3)";

    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();

    /* Local variables */
    real f, y, dh, fl, fr;
    integer is;
    real tp, yt, qc1, a1t, ddn, dup, res;
    integer knt;
    extern /* Subroutine */ int rgf3_(real *, real *, FeqCallback3, real *, real *, 
	    real *, real *, real *, integer *);
    real tel1, tel2, tel3;
    extern doublereal rty0_(real *), rty1_(real *);
    integer feq_gen_flag_d_;
    extern doublereal fcd123_(integer *, integer *, char *, real *, real *, 
	    ftnlen);
    extern /* Subroutine */ int dpm26_(integer *, real *, real *, real *, 
	    integer *);
    real ylow;
    extern /* Subroutine */ int lktj_(integer *, real *, real *);
    real y2min;
    integer sflag;
    real qcmax, yhigh;
    extern /* Subroutine */ int appro_(integer *, real *, real *, real *, 
	    integer *, integer *), lktqc_(integer *, real *, real *), xlkt22_(
	    integer *, real *, real *, real *, real *, real *, real *, real *,
	     real *, real *, real *, real *, real *), fndcde_(integer *, 
	    integer *, real *, real *);
    extern doublereal degcon_(real *, real *, real *);
    integer conflg, nsflag;
    extern /* Subroutine */ int sfpsbe_(integer *, integer *, integer *, real 
	    *, real *, real *, integer *, real *, integer *), xlktal_(integer 
	    *, real *, real *, real *, real *, real *, real *, real *, real *,
	     real *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__37 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__38 = { 0, 0, 0, fmt_90, 0 };
    static cilist feq_gen_io_d__43 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__45 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__47 = { 0, 0, 0, fmt_88, 0 };
    static cilist feq_gen_io_d__53 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__54 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__60 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__64 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__66 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__67 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__68 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__69 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__70 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__71 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__72 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__73 = { 0, 0, 0, fmt_84, 0 };


/*     + + + PURPOSE + + + */
/*     Compute a flow of type 0 for the given upstream head, HUP. */
/*     Primary purpose of type 0 is to eliminate computational */
/*     problems with subsequent types. */
/* SOURCE culvertb.for:412 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertb.for:414 */
/*<       integereflag,expflg,id,iu,stdout,type >*/
/* SOURCE culvertb.for:415 */
/*<       realfreed,hdatum,hup,qfree,zsbrdf >*/
/* SOURCE culvertb.for:416 */
/*<       characterculcls*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     HDATUM - Datum for measuring head */
/*     HUP    - Head upstream */
/*     IU     - Index for upstream node for the culvert barrel */
/*     ID     - Index for the downstream node for the culvert barrel */
/*     CULCLS - Class for culvert shape, BOX, PIPE, .. */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     TYPE   - Culvert flow type */
/*     EXPFLG - Expansion flag.  EXPFLG=1 if flow expands on exit */
/*              and EXPFLG=0 if flow does not expand on exit */
/*     ZSBRDF - water surface elevation at section 43 that begins */
/*              submergence of flow over the roadway */
/*     QFREE  - Free flow */
/*     FREED  - Free drop */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertb.for:435 */
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
/* INCLUDE culvertb.for:436 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE culvertb.for:437 */
/* SOURCE xs1com.cmn:2 */
/*<        >*/
/* SOURCE xs1com.cmn:7 */
/*<       integeradrxs1 >*/
/* SOURCE xs1com.cmn:9 */
/*<        >*/
/*     Z1TY1- elevation at section 1 at type 1 limit if it exists */
/*     Z1TY1L-elevation at section 1 at lower limit of type 1 if it exists */
/*     Z1TY6- elevation at section 1 at start of type 6 if it exists */
/*     Z1TY2- elevation at upper limit of type 2 flow if it exists */
/*     Z1TY61- elevation at upper limt of type 61 if it exists */
/*     Z1TY5- elevation at section at start of type 5 if it exists */
/*     Z1TY52- elevation at section 1 at lower limit of type 52( */
/*             type 2 to type 5 flow) */
/*     Z1TY51- elevation at section 1 at lower limit of type 51( */
/*             type 1 to type 5 flow) */
/* INCLUDE culvertb.for:438 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culvertb.for:439 */
/* SOURCE xs3com.cmn:2 */
/*<        >*/
/* SOURCE xs3com.cmn:11 */
/*<       integeradrxs3 >*/
/* SOURCE xs3com.cmn:13 */
/*<        >*/
/*     CD1- if 0.0 type 1 flow has not been checked, if > 0 type 1 */
/*          flow has been checked and found to exist and its limit */
/*          values have been found, if < 0 type 1 flow does not exist. */
/*     CD2T6- coef. of discharge forcing full flow to match flow */
/*            at the type 2 flow limit. */
/*     AP2T6 - kinetic energy flux coefficient forcing the full */
/*             flow kinetic energy flux to match the flux */
/*             at the type 2 limit. */
/*     BT2T6- momentum flux coefficient forcing the full flow */
/*            momentum flux to match the flux at the type 2 limit. */
/*     CD61T6- coef. of discharge forcing full flow to match flow */
/*             at the type 61 limit. */
/*     CD1T6- coef. of discharge forcing full flow to match flow */
/*            at the type 1 limit */

/*     AP61T6- same as AP2T6 for type 61. */
/*     BT61T6- same as AP2T6 for type 61. */
/*     CD2- coef. of discharge for type 2 flow at the type 2 limit. */
/*     CD61- coef. of discharge for type 61 flow at the type 61 limit. */
/*     CD6- coef. of discharge for type 6 flow. */
/*     Z3PTY6- piezometric level at section 3 at the type 6 limit. */
/*     AVH2- area for velocity head at the type 2 limit. */
/*     AVH61- area for velocity head at the type 61 limit. */
/*     BT3ATD- beta at section 3 when barrel is full(at D!) */
/*     AP3ATD- alpha at section 3 when the barrel is full(at D!) */
/*     CC2T5 - contraction coefficient for type 5 at the type 2 flow */
/*             limit. */
/*     CC1T5 - contraction coefficient for type 5 at the type 1 flow */
/*             limit. */
/*     CC5- contraction coefficient for type 5 at its lower limit */
/*          and above. */
/*     Y3TY52- depth at section 3 at the lower limit of type 52 flow */
/*             giving the transistion between type 2 and type 5. */
/*     Y3TY51- depth at section 3 at the lower limit of type 51 flow */
/*             giving the transistion between type 1 and type 5. */
/*     BT2T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 52 and */
/*             upper limit of type 2. */
/*     BT1T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 51 and */
/*             upper limit of type 1. */
/*     AP2T5-  alpha analogous to BT2T5 */
/*     AP1T5-  alpha analogous to BT1T5 */
/*     Y3TY5-  depth at section 3 at the lower limit of type 5 flow */
/*     BT3AT5- beta for type 5 flow limit */
/*     AP3AT5- alpha for type 5 flow limit */
/*     CD5T4- coefficient of discharge that forces a type 4 equation */
/*            to match the type 5, 51, or 52 flow at the full-flow- */
/*            inducing level at section 43. */
/*     Y3LTY2- depth at section 3 at the type 2 limit, that is, */
/*             critical depth. */
/*     Y3LTY1- submergence depth at section 3  at the limit of */
/*             type 1 flow. */
/*     Y3LTY5- the full-flow-inducing value of piezometric level */
/*             relative to the invert at section 3 for flow types */
/*             5, 51, and 52. */
/* INCLUDE culvertb.for:440 */
/* SOURCE x43com.cmn:2 */
/*<        >*/
/* SOURCE x43com.cmn:6 */
/*<       integeradrs43,stat43 >*/
/* SOURCE x43com.cmn:8 */
/*<        >*/
/* INCLUDE culvertb.for:441 */
/* SOURCE xs4com.cmn:2 */
/*<        >*/
/* SOURCE xs4com.cmn:5 */
/*<       integeradrxs4 >*/
/* SOURCE xs4com.cmn:7 */
/*<        >*/
/* INCLUDE culvertb.for:442 */
/* SOURCE rdfcom.cmn:2 */
/*<       common/rdfcom/wfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/* SOURCE rdfcom.cmn:4 */
/*<       realwfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/*     WFRDF-WATER FLUX OVER ROAD FREE CONDITION. */
/*     MFRDF-MOMENTUM FLUX OVER THE ROAD FREE CONDITION. */
/*     EFRDF-ENERGY FLUX OVER THE ROAD FREE CONDITION. */
/*     WFRD- WATER FLUX OVER THE ROAD ANY CONDITION. */
/*     MFRD- MOMENTUM FLUX OVER THE ROAD ANY CONDITION. */
/*     EFRD- ENERGY FLUX OVER THE ROAD ANY CONDITION. */
/* INCLUDE culvertb.for:443 */
/* SOURCE culcom.cmn:2 */
/*<        >*/
/* SOURCE culcom.cmn:8 */
/*<       integernsec(mnbn),hltab(mnbn),iat3d,iat6d,sbkind,sbshape >*/
/* SOURCE culcom.cmn:10 */
/*<        >*/
/* SOURCE culcom.cmn:16 */
/*<       doubleprecisionfrcfac >*/
/*     FRCFAC- friction factor to give factor for friction losses */
/*             in barrel for non-prismatic full-flow that as well */
/*             as prismatic full flow. */
/*     TY1YTD- maximum ratio of depth to vertical diameter for */
/*             type 1 flow. */
/*     TY1HTD- maximum ratio of head at section 1 relative to */
/*             culvert invert at culvert inlet to the vertical */
/*             diamter of the culvert.  Must be less than 1.5. */
/*     SBKIND- if 0 the slope of the culvert barrel is a constant, */
/*             if 1 the slope of the culvert barrel varies. */
/*     BSHAPE- if 0 the barrel shape is constant, that is, prismatic, */
/*             if 1 the barrel shape is nonprismatic. */
/*     TY5SBF- ratio of depth to vertical diameter of the culvert */
/*             at the exit which causes submergence. */
/* Note:  25 August 2004:  SBSHAPE is apparently not used.  BSHAPE */
/* is but outside of a common block. */
/* INCLUDE culvertb.for:444 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertb.for:445 */
/* SOURCE cdcom.cmn:2 */
/*<        >*/
/* SOURCE cdcom.cmn:10 */
/*<        >*/
/* SOURCE cdcom.cmn:14 */
/*<        >*/
/*     Add values for support of FHWA type 5 scheme. Oct. 3, 2001 */
/* SOURCE cdcom.cmn:20 */
/*<       realafhwa,cfhwa,yfhwa,sfhwa >*/
/*     AFHWA - value of a */
/*     CFHWA - value of c */
/*     YFHWA - value of Y */
/*     SFHWA - slope of culvert near entrance. */
/* INCLUDE culvertb.for:446 */
/*     Common for function RTY1 in FEQUTL */
/* SOURCE rty1c.cmn:3 */
/*<       common/rty1c/du,ftype,outun1,frsq,dhty1 >*/
/* SOURCE rty1c.cmn:4 */
/*<       character*8class1 >*/
/* SOURCE rty1c.cmn:5 */
/*<       integerftype,outun1 >*/
/* SOURCE rty1c.cmn:6 */
/*<       realdu,frsq,dhty1 >*/
/* SOURCE rty1c.cmn:8 */
/*<       common/rty1cc/class1 >*/
/* INCLUDE culvertb.for:447 */
/*     Common for function RTY0 in FEQUTL */
/* SOURCE rty0c.cmn:3 */
/*<       common/rty0c/outun0,dup0,a1t0,ddn0,z1t0,iup0,idn0,sflag0 >*/
/* SOURCE rty0c.cmn:4 */
/*<       integeroutun0,iup0,idn0,sflag0 >*/
/* SOURCE rty0c.cmn:5 */
/*<       realdup0,a1t0,ddn0,z1t0 >*/
/* SOURCE rty0c.cmn:6 */
/*<       common/rty0cc/class0 >*/
/* SOURCE rty0c.cmn:7 */
/*<       character*8class0 >*/
/* INCLUDE culvertb.for:448 */
/* SOURCE rqvstw.cmn:2 */
/*<       integeriup,idn,sbflag,outun,cqtype,fqtype >*/
/* SOURCE rqvstw.cmn:3 */
/*<       realzsub,z43fix,abase,z1t,qfixed >*/
/* SOURCE rqvstw.cmn:5 */
/*<       character*8class >*/
/* SOURCE rqvstw.cmn:8 */
/*<        >*/
/* SOURCE rqvstw.cmn:11 */
/*<       common/rqvtc/class >*/
/* INCLUDE culvertb.for:449 */
/*     Common block for various parameters to handle transitional */
/*     flow type behavior for the departure reach computations. */
/* SOURCE typtrn.cmn:4 */
/*<       common/typtrn/avhf,cdf,betaf,alphaf,y3pf,beta3,alpha3 >*/
/* SOURCE typtrn.cmn:6 */
/*<       realavhf,cdf,betaf,alphaf,y3pf,beta3,alpha3 >*/
/*     AVHF- area used for velocity head in computing losses for the */
/*           transitional free flow */
/*     CDF- coef. of discharge for computing losses for the transitional */
/*          free flow. */
/*     BETAF- value of beta to compensate for false area in the computation */
/*            of the momentum flux from some free flows.  If this */
/*            value is zero it means that the beta from the cross section */
/*            function table should be used.  If it is non-zero it means */
/*            that the free flow type was used as a transition and that */
/*            the flow area of the culvert barrel outlet was falsified in */
/*            the process. */
/*     ALPHAF- value of alpha to use in computing velocity head for */
/*             energy loss computations. */
/*     Y3PF- depth to the piezometric level at the culvert barrel outlet */
/*           for free flow limit. */
/*     BETA3- actual value at section 3 used in departure reach */
/*     ALPHA3- actual value at section 3.  Crudely estimated in some */
/*             cases because better alternative is not available. */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertb.for:452 */
/*<       integerconflg,flag,is,knt,nsflag,sflag >*/
/* SOURCE culvertb.for:453 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertb.for:457 */
/*<       intrinsicabs,min >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertb.for:460 */
/*<       realdegcon,fcd123,rty0,rty1 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertb.for:463 */
/*<        >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertb.for:467 */
/*<    54  >*/
/* SOURCE culvertb.for:469 */
/*<    60 format(' *BUG:XXX* RGF3: MORE THAN 100 ITERATIONS IN FRFT0.') >*/
/* SOURCE culvertb.for:470 */
/*<    66 format(/,' Type 0 flow drowned by control at section 2.') >*/
/* SOURCE culvertb.for:471 */
/*<    68 format(/,' Type 0 flow drowned by control at section 3.') >*/
/* SOURCE culvertb.for:472 */
/*<    70  >*/
/* SOURCE culvertb.for:474 */
/*<    72  >*/
/* SOURCE culvertb.for:476 */
/*<    76  >*/
/* SOURCE culvertb.for:479 */
/*<    78  >*/
/* SOURCE culvertb.for:482 */
/*<    80  >*/
/* SOURCE culvertb.for:486 */
/*<    82  >*/
/* SOURCE culvertb.for:488 */
/*<    84  >*/
/* SOURCE culvertb.for:492 */
/*<    86  >*/
/* SOURCE culvertb.for:494 */
/*<    88  >*/
/* SOURCE culvertb.for:496 */
/*<    90  >*/
/* SOURCE culvertb.for:500 */
/*<    92 format(/,' Testing for flow type 0 at upstream head =',f8.3) >*/
/* *********************************************************************** */
/*     DEFINE THE SPECIAL COMMON BLOCK VALUES */
/* SOURCE culvertb.for:503 */
/*<       outun1=stdout >*/
/* L54: */
/* L60: */
/* L66: */
/* L68: */
/* L70: */
/* L72: */
/* L76: */
/* L78: */
/* L80: */
/* L82: */
/* L84: */
/* L86: */
/* L88: */
/* L90: */
/* L92: */
    rty1c_1.outun1 = *stdout;
/* SOURCE culvertb.for:504 */
/*<       outun=stdout >*/
    rqvtw_1.outun = *stdout;
/* SOURCE culvertb.for:505 */
/*<       outun0=stdout >*/
    rty0c_1.outun0 = *stdout;
/* SOURCE culvertb.for:506 */
/*<       du=dvec(iu) >*/
    rty1c_1.du = culcom_1.dvec[*iu - 1];
/* SOURCE culvertb.for:507 */
/*<       dup=du >*/
    dup = rty1c_1.du;
/* SOURCE culvertb.for:508 */
/*<       dup0=du >*/
    rty0c_1.dup0 = rty1c_1.du;
/* SOURCE culvertb.for:509 */
/*<       class0=culcls >*/
    s_copy(rty0cc_1.class0, culcls, (ftnlen)8, (ftnlen)8);
/* SOURCE culvertb.for:510 */
/*<       class1=culcls >*/
    s_copy(rty1cc_1.class1, culcls, (ftnlen)8, (ftnlen)8);
/* SOURCE culvertb.for:511 */
/*<       class=culcls >*/
    s_copy(rqvtc_1.feq_gen_class_d_, culcls, (ftnlen)8, (ftnlen)8);
/* SOURCE culvertb.for:512 */
/*<       iup=iu >*/
    rqvtw_1.iup = *iu;
/* SOURCE culvertb.for:513 */
/*<       idn=id >*/
    rqvtw_1.idn = *id;
/* SOURCE culvertb.for:514 */
/*<       iup0=iu >*/
    rty0c_1.iup0 = *iu;
/* SOURCE culvertb.for:515 */
/*<       idn0=id >*/
    rty0c_1.idn0 = *id;
/* SOURCE culvertb.for:516 */
/*<       ddn=dvec(id) >*/
    ddn = culcom_1.dvec[*id - 1];
/* SOURCE culvertb.for:517 */
/*<       ddn0=ddn >*/
    rty0c_1.ddn0 = ddn;
/*     Clear the flag for special departure reach treatment */
/* SOURCE culvertb.for:520 */
/*<       betaf=0.0 >*/
    typtrn_1.betaf = (float)0.;
/* SOURCE culvertb.for:521 */
/*<       beta3=0.0 >*/
    typtrn_1.beta3 = (float)0.;
/* SOURCE culvertb.for:522 */
/*<       alpha3=0.0 >*/
    typtrn_1.alpha3 = (float)0.;
/* SOURCE culvertb.for:523 */
/*<       expflg=1 >*/
    *expflg = 1;
/* SOURCE culvertb.for:524 */
/*<       type=0 >*/
    *feq_gen_type_d_ = 0;
/*     FIND FLOW RATE AT SECTION 1 */
/* SOURCE culvertb.for:527 */
/*<       y1=hdatum+hup-zb1 >*/
    xs1com_1.y1 = static_cast<double>(static_cast<double>(*hdatum) + *hup) - xs1com_1.zb1;
/* SOURCE culvertb.for:528 */
/*<       z1t=y1+zb1 >*/
    rqvtw_1.z1t = static_cast<double>(xs1com_1.y1) + xs1com_1.zb1;
/* SOURCE culvertb.for:529 */
/*<        >*/
    xlkt22_(&xs1com_1.adrxs1, &xs1com_1.y1, &xs1com_1.a1, &xs1com_1.t1, &
	    xs1com_1.dt1, &xs1com_1.j1, &xs1com_1.k1, &xs1com_1.dk1, &
	    xs1com_1.bet1, &xs1com_1.dbet1, &xs1com_1.alp1, &xs1com_1.dalp1, &
	    qc1);
/* SOURCE culvertb.for:534 */
/*<       tel1=z1t+alp1*(qc1/a1)**2/grav2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(qc1) / xs1com_1.a1;
    tel1 = static_cast<double>(rqvtw_1.z1t) + static_cast<double>(static_cast<double>(xs1com_1.alp1) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / grvcom_1.grav2;
/* SOURCE culvertb.for:535 */
/*<       a1t=a1 >*/
    a1t = xs1com_1.a1;
/* SOURCE culvertb.for:536 */
/*<       z1t0=z1t >*/
    rty0c_1.z1t0 = rqvtw_1.z1t;
/*     Set approach area in common blocks */
/* SOURCE culvertb.for:538 */
/*<       abase=a1t >*/
    rqvtw_1.abase = a1t;
/* SOURCE culvertb.for:539 */
/*<       a1t0=a1t >*/
    rty0c_1.a1t0 = a1t;
/* SOURCE culvertb.for:540 */
/*<       qfixed=qc1 >*/
    rqvtw_1.qfixed = qc1;
/*      Z43MAX = 0.0 */
/*      WRITE(STDOUT,*) ' FRFT0: Y1=',Y1,' QC1=',QC1,' WFRD=',WFRD */
/* SOURCE culvertb.for:543 */
/*<       write(stdout,92)hup >*/
    feq_gen_io_d__37.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__37);
    do_fio(&feq_gen_c_d_1, (char *)&(*hup), (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE culvertb.for:544 */
/*<       q2=qc1-wfrd >*/
    xs2com_1.q2 = static_cast<double>(qc1) - rdfcom_1.wfrd;
/* SOURCE culvertb.for:545 */
/*<       if(q2.le.0.0)then >*/
    if (xs2com_1.q2 <= (float)0.) {
/* SOURCE culvertb.for:546 */
/*<       write(stdout,90)wfrd,qc1 >*/
	feq_gen_io_d__38.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__38);
	do_fio(&feq_gen_c_d_1, (char *)&rdfcom_1.wfrd, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&qc1, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culvertb.for:547 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE culvertb.for:548 */
/*<       return >*/
	return 0;
/* SOURCE culvertb.for:549 */
/*<       else >*/
    } else {
/* SOURCE culvertb.for:551 */
/*<       q1=qc1 >*/
	xs1com_1.q1 = qc1;
/* SOURCE culvertb.for:552 */
/*<       q3=q2 >*/
	xs3com_1.q3 = xs2com_1.q2;
/* SOURCE culvertb.for:553 */
/*<       q4=q1 >*/
	xs4com_1.q4 = xs1com_1.q1;
/*       TEST 1 */
/*       Compute critical depth at the culvert entrance.  Test for */
/*       possibility of flow type 1. */
/* SOURCE culvertb.for:559 */
/*<       tp=ty1ytd*dup >*/
	tp = static_cast<double>(culcom_1.ty1ytd) * dup;
/* SOURCE culvertb.for:560 */
/*<       calllktqc(adrxs2,tp,qcmax) >*/
	lktqc_(&xs2com_1.adrxs2, &tp, &qcmax);
/* SOURCE culvertb.for:564 */
/*<       if(q2.ge.qcmax)then >*/
	if (xs2com_1.q2 >= qcmax) {
/* SOURCE culvertb.for:565 */
/*<       type=1 >*/
	    *feq_gen_type_d_ = 1;
/* SOURCE culvertb.for:566 */
/*<       else >*/
	} else {
/*          Y2MAX = DUP */
/* SOURCE culvertb.for:568 */
/*<       y2=0.5*dup >*/
	    xs2com_1.y2 = static_cast<double>(dup) * (float).5;
/* SOURCE culvertb.for:569 */
/*<       callfndcde(stdout,adrxs2,q2,y2) >*/
	    fndcde_(stdout, &xs2com_1.adrxs2, &xs2com_1.q2, &xs2com_1.y2);
/* SOURCE culvertb.for:572 */
/*<       callxlktal(adrxs2,y2,a2,t2,dt2,j2,k2,dk2,bet2,dbet2,alp2,dalp2) >*/
	    xlktal_(&xs2com_1.adrxs2, &xs2com_1.y2, &xs2com_1.a2, &
		    xs2com_1.t2, &xs2com_1.dt2, &xs2com_1.j2, &xs2com_1.k2, &
		    xs2com_1.dk2, &xs2com_1.bet2, &xs2com_1.dbet2, &
		    xs2com_1.alp2, &xs2com_1.dalp2);
/* SOURCE culvertb.for:577 */
/*<       y2min=y2 >*/
	    y2min = xs2com_1.y2;
/* SOURCE culvertb.for:578 */
/*<       tel2=zb2+y2+alp2*(q2/a2)**2/grav2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(xs2com_1.q2) / xs2com_1.a2;
	    tel2 = static_cast<double>(static_cast<double>(xs2com_1.zb2) + xs2com_1.y2) + static_cast<double>(static_cast<double>(xs2com_1.alp2) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) 
		    / grvcom_1.grav2;
/* SOURCE culvertb.for:579 */
/*<       if(tel2.ge.tel1)then >*/
	    if (tel2 >= tel1) {
/*            Type 0 flow is drowned by control at section 2. */
/* SOURCE culvertb.for:581 */
/*<       type=1 >*/
		*feq_gen_type_d_ = 1;
/* SOURCE culvertb.for:582 */
/*<       else >*/
	    } else {
/* SOURCE culvertb.for:583 */
/*<       write(stdout,86)tel1,tel2 >*/
		feq_gen_io_d__43.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__43);
		do_fio(&feq_gen_c_d_1, (char *)&tel1, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&tel2, (ftnlen)sizeof(real));
		e_wsfe();
/*           Type 0 flow may be drowned by control at section 2. */
/* SOURCE culvertb.for:585 */
/*<       z1=z1t >*/
		xs1com_1.z1 = rqvtw_1.z1t;
/* SOURCE culvertb.for:587 */
/*<       res=rty1(y2) >*/
		res = rty1_(&xs2com_1.y2);
/* SOURCE culvertb.for:588 */
/*<       if(res.lt.0.0)then >*/
		if (res < (float)0.) {
/*             Control at section 2 does drown control at section 1. */
/* SOURCE culvertb.for:590 */
/*<       type=1 >*/
		    *feq_gen_type_d_ = 1;
/* SOURCE culvertb.for:591 */
/*<       else >*/
		} else {
/* SOURCE culvertb.for:592 */
/*<       type=0 >*/
		    *feq_gen_type_d_ = 0;
/* SOURCE culvertb.for:593 */
/*<       endif >*/
		}
/* SOURCE culvertb.for:594 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:595 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:596 */
/*<       if(type.eq.1)then >*/
	if (*feq_gen_type_d_ == 1) {
/*         Type 0 flow drowned by control at section 2. */
/* SOURCE culvertb.for:598 */
/*<       write(stdout,66) >*/
	    feq_gen_io_d__45.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__45);
	    e_wsfe();
/* SOURCE culvertb.for:599 */
/*<       return >*/
	    return 0;
/* SOURCE culvertb.for:600 */
/*<       endif >*/
	}
/*       TYPE 0 PASSED TEST 1. */
/*       TEST 2.  Compute critical depth at section 3 and check for */
/*       flow type 2. */
/* SOURCE culvertb.for:606 */
/*<       y3=0.5*ddn >*/
	xs3com_1.y3 = static_cast<double>(ddn) * (float).5;
/* SOURCE culvertb.for:607 */
/*<       callfndcde(stdout,adrxs3,q3,y3) >*/
	fndcde_(stdout, &xs3com_1.adrxs3, &xs3com_1.q3, &xs3com_1.y3);
/* SOURCE culvertb.for:610 */
/*<       callxlktal(adrxs3,y3,a3,t3,dt3,j3,k3,dk3,bet3,dbet3,alp3,dalp3) >*/
	xlktal_(&xs3com_1.adrxs3, &xs3com_1.y3, &xs3com_1.a3, &xs3com_1.t3, &
		xs3com_1.dt3, &xs3com_1.j3, &xs3com_1.k3, &xs3com_1.dk3, &
		xs3com_1.bet3, &xs3com_1.dbet3, &xs3com_1.alp3, &
		xs3com_1.dalp3);
/* SOURCE culvertb.for:614 */
/*<       z3=zb3+y3 >*/
	xs3com_1.z3 = static_cast<double>(xs3com_1.zb3) + xs3com_1.y3;
/* SOURCE culvertb.for:616 */
/*<       tel3=z3+alp3*(q3/a3)**2/grav2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(xs3com_1.q3) / xs3com_1.a3;
	tel3 = static_cast<double>(xs3com_1.z3) + static_cast<double>(static_cast<double>(xs3com_1.alp3) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / grvcom_1.grav2;
/* SOURCE culvertb.for:617 */
/*<       if(tel3.ge.tel1)then >*/
	if (tel3 >= tel1) {
/*         Type 0 flow is drowned by control at section 3. */
/* SOURCE culvertb.for:619 */
/*<       type=1 >*/
	    *feq_gen_type_d_ = 1;
/* SOURCE culvertb.for:620 */
/*<       else >*/
	} else {
/* SOURCE culvertb.for:621 */
/*<       write(stdout,88)tel1,tel3 >*/
	    feq_gen_io_d__47.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__47);
	    do_fio(&feq_gen_c_d_1, (char *)&tel1, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&tel3, (ftnlen)sizeof(real));
	    e_wsfe();
/*         Type 0 flow may be drowned by control at section 3. */
/*         Find the water level at section 2 */
/*         DEFINE THE COEF OF DISCHARGE */
/* SOURCE culvertb.for:627 */
/*<       c123=fcd123(stdout,2,culcls,dvec(iup),z1t) >*/
	    cdcom_1.c123 = fcd123_(stdout, &feq_gen_c_d_2, culcls, &culcom_1.dvec[
		    rqvtw_1.iup - 1], &rqvtw_1.z1t, (ftnlen)8);
/* SOURCE culvertb.for:629 */
/*<       cd=degcon(c123,a1t,a3) >*/
	    cdcom_1.cd = degcon_(&cdcom_1.c123, &a1t, &xs3com_1.a3);
/* SOURCE culvertb.for:630 */
/*<       dh=(1.0/cd**2-1.0)*(q3/a3)**2/grav2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = cdcom_1.cd;
/* Computing 2nd power */
	    feq_gen_r_d_2 = static_cast<double>(xs3com_1.q3) / xs3com_1.a3;
	    dh = static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - (float)1.)) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) / 
		    grvcom_1.grav2;
/* SOURCE culvertb.for:631 */
/*<       vhl=0.0 >*/
	    cdcom_1.vhl = (float)0.;
/* SOURCE culvertb.for:633 */
/*<       callsfpsbe(stdout,iu,id,dh,q3,z3,is,z2,sflag) >*/
	    sfpsbe_(stdout, iu, id, &dh, &xs3com_1.q3, &xs3com_1.z3, &is, &
		    xs2com_1.z2, &sflag);
/* SOURCE culvertb.for:637 */
/*<       if(sflag.ne.1)then >*/
	    if (sflag != 1) {
/*           Subcritical profile could not be completed.  Take this */
/*           to mean that the barrel slope is steep for the given */
/*           flow and that control at section 3 is not possible. */
/* SOURCE culvertb.for:641 */
/*<       type=0 >*/
		*feq_gen_type_d_ = 0;
/* SOURCE culvertb.for:642 */
/*<       else >*/
	    } else {
/*           Check the energy line values. */
/* SOURCE culvertb.for:644 */
/*<       y2=z2-zb2 >*/
		xs2com_1.y2 = static_cast<double>(xs2com_1.z2) - xs2com_1.zb2;
/* SOURCE culvertb.for:645 */
/*<       callxlktal(adrxs2,y2,a2,t2,dt2,j2,k2,dk2,bet2,dbet2,alp2,dalp2) >*/
		xlktal_(&xs2com_1.adrxs2, &xs2com_1.y2, &xs2com_1.a2, &
			xs2com_1.t2, &xs2com_1.dt2, &xs2com_1.j2, &
			xs2com_1.k2, &xs2com_1.dk2, &xs2com_1.bet2, &
			xs2com_1.dbet2, &xs2com_1.alp2, &xs2com_1.dalp2);
/* SOURCE culvertb.for:650 */
/*<       tel2=zb2+y2+alp2*(q2/a2)**2/grav2 >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = static_cast<double>(xs2com_1.q2) / xs2com_1.a2;
		tel2 = static_cast<double>(static_cast<double>(xs2com_1.zb2) + xs2com_1.y2) + static_cast<double>(static_cast<double>(xs2com_1.alp2) * (static_cast<double>(feq_gen_r_d_1) * 
			feq_gen_r_d_1)) / grvcom_1.grav2;
/* SOURCE culvertb.for:651 */
/*<       if(tel2.gt.tel1)then >*/
		if (tel2 > tel1) {
/*             Control at section 3 is possible and drowns type 0 */
/* SOURCE culvertb.for:653 */
/*<       if(y2.gt.dup)then >*/
		    if (xs2com_1.y2 > dup) {
/* SOURCE culvertb.for:654 */
/*<       type=6 >*/
			*feq_gen_type_d_ = 6;
/* SOURCE culvertb.for:655 */
/*<       else >*/
		    } else {
/* SOURCE culvertb.for:656 */
/*<       type=1 >*/
			*feq_gen_type_d_ = 1;
/* SOURCE culvertb.for:657 */
/*<       endif >*/
		    }
/* SOURCE culvertb.for:658 */
/*<       else >*/
		} else {
/*             Control at section 3 is possible and may drown type 0. */
/*             Return values  are in XS1COM set of variables. */
/* SOURCE culvertb.for:661 */
/*<       callappro(stdout,cd,vhl,0.0,conflg,nsflag) >*/
		    appro_(stdout, &cdcom_1.cd, &cdcom_1.vhl, &c_b52, &conflg,
			     &nsflag);
/* SOURCE culvertb.for:664 */
/*<       if(nsflag.eq.1)then >*/
		    if (nsflag == 1) {
/*               No solution in the approach reach if the flow at */
/*               section 3 is critical and the flow is critical flow at */
/*               section 1. */
/* SOURCE culvertb.for:668 */
/*<       type=0 >*/
			*feq_gen_type_d_ = 0;
/* SOURCE culvertb.for:669 */
/*<       else >*/
		    } else {
/*               Solution possible for section 1 elevation.  Does it */
/*               drown the control at section 1? */
/* SOURCE culvertb.for:672 */
/*<       if(z1.gt.z1t)then >*/
			if (xs1com_1.z1 > rqvtw_1.z1t) {
/* SOURCE culvertb.for:673 */
/*<       if(y2.gt.dup)then >*/
			    if (xs2com_1.y2 > dup) {
/* SOURCE culvertb.for:674 */
/*<       type=6 >*/
				*feq_gen_type_d_ = 6;
/* SOURCE culvertb.for:675 */
/*<       else >*/
			    } else {
/* SOURCE culvertb.for:676 */
/*<       type=1 >*/
				*feq_gen_type_d_ = 1;
/* SOURCE culvertb.for:677 */
/*<       endif >*/
			    }
/* SOURCE culvertb.for:678 */
/*<       else >*/
			} else {
/* SOURCE culvertb.for:679 */
/*<       type=0 >*/
			    *feq_gen_type_d_ = 0;
/* SOURCE culvertb.for:680 */
/*<       endif >*/
			}
/* SOURCE culvertb.for:681 */
/*<       endif >*/
		    }
/* SOURCE culvertb.for:682 */
/*<       endif >*/
		}
/* SOURCE culvertb.for:683 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:684 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:687 */
/*<       if(type.ne.0)then >*/
	if (*feq_gen_type_d_ != 0) {
/*         Type 0 flow drowned by control at section 3. */
/* SOURCE culvertb.for:689 */
/*<       write(stdout,68) >*/
	    feq_gen_io_d__53.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__53);
	    e_wsfe();
/* SOURCE culvertb.for:690 */
/*<       return >*/
	    return 0;
/* SOURCE culvertb.for:691 */
/*<       endif >*/
	}
/*       TYPE 0 PASSED TEST 2.  The only control left is at section 4. */
/*       However, this is type 7, computed only after a truly free flow */
/*       type has been found.  Therefore, we find the level at section */
/*       43, the immediate tailwater location for flow through */
/*       the culvert, that for the given flow, QC1, will cause */
/*       the upstream water level to be matched.  This will be */
/*       taken to drown the control at section 1.  Once this level */
/*       is determined, the drop to free flow is computed using */
/*       DPM26.  At this time it is possible that there is no */
/*       expansion in the departure reach.   This identifies flow */
/*       type 7 just as for the other flow types. */
/* SOURCE culvertb.for:705 */
/*<       write(stdout,70)q2,wfrd >*/
	feq_gen_io_d__54.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__54);
	do_fio(&feq_gen_c_d_1, (char *)&xs2com_1.q2, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&rdfcom_1.wfrd, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culvertb.for:706 */
/*<       type=0 >*/
	*feq_gen_type_d_ = 0;
/* SOURCE culvertb.for:708 */
/*<       f=-1.0 >*/
	f = (float)-1.;
/* SOURCE culvertb.for:709 */
/*<       if(f.le.0.0)then >*/
	if (f <= (float)0.) {
/*         There is a solution. */
/* SOURCE culvertb.for:712 */
/*<       ylow=0.0 >*/
	    ylow = (float)0.;
/* SOURCE culvertb.for:713 */
/*<       yhigh=0.0 >*/
	    yhigh = (float)0.;
/* SOURCE culvertb.for:714 */
/*<       y=y2min >*/
	    y = y2min;
/* SOURCE culvertb.for:715 */
/*<       knt=0 >*/
	    knt = 0;
/* SOURCE culvertb.for:716 */
/*<   100 continue >*/
L100:
/* SOURCE culvertb.for:717 */
/*<       knt=knt+1 >*/
	    ++knt;
/* SOURCE culvertb.for:718 */
/*<       if(knt.gt.100)then >*/
	    if (knt > 100) {
/* SOURCE culvertb.for:719 */
/*<       write(outun,72) >*/
		feq_gen_io_d__60.ciunit = rqvtw_1.outun;
		s_wsfe(&feq_gen_io_d__60);
		e_wsfe();
/* SOURCE culvertb.for:720 */
/*<       goto800 >*/
		goto L800;
/* SOURCE culvertb.for:721 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:723 */
/*<       f=rty0(y) >*/
	    f = rty0_(&y);
/*            WRITE(STDOUT,*) ' FRFT0: RTY0=',F,' AT Y=',Y */
/* SOURCE culvertb.for:726 */
/*<       if(abs(f).le.epsabs)then >*/
	    if (dabs(f) <= epscom_1.epsabs) {
/*             Close enough.  Results in XS2COM */
/* SOURCE culvertb.for:729 */
/*<       else >*/
	    } else {
/* SOURCE culvertb.for:730 */
/*<       if(f.gt.0.0)then >*/
		if (f > (float)0.) {
/* SOURCE culvertb.for:731 */
/*<       yhigh=y >*/
		    yhigh = y;
/* SOURCE culvertb.for:732 */
/*<       fr=f >*/
		    fr = f;
/* SOURCE culvertb.for:733 */
/*<       if(ylow.eq.0.0)then >*/
		    if (ylow == (float)0.) {
/*                 Seek a negative residual. */
/* SOURCE culvertb.for:735 */
/*<       yt=1.1*y >*/
			yt = static_cast<double>(y) * (float)1.1;
/*                  IF(YT.GT.Y2MAX) THEN */
/*                    YT = 0.5*(Y + Y2MAX) */
/*                    IF(YT.EQ.Y2MAX) THEN */
/*                      WRITE(OUTUN,74) Y2MAX */
/*                      STOP 'Abnormal stop. Errors found.' */
/*                    ENDIF */
/*                  ENDIF */
/* SOURCE culvertb.for:743 */
/*<       y=yt >*/
			y = yt;
/* SOURCE culvertb.for:744 */
/*<       goto100 >*/
			goto L100;
/* SOURCE culvertb.for:745 */
/*<       else >*/
		    } else {
/* SOURCE culvertb.for:746 */
/*<       goto110 >*/
			goto L110;
/* SOURCE culvertb.for:747 */
/*<       endif >*/
		    }
/* SOURCE culvertb.for:748 */
/*<       else >*/
		} else {
/* SOURCE culvertb.for:749 */
/*<       ylow=y >*/
		    ylow = y;
/* SOURCE culvertb.for:750 */
/*<       fl=f >*/
		    fl = f;
/* SOURCE culvertb.for:751 */
/*<       if(yhigh.eq.0.0)then >*/
		    if (yhigh == (float)0.) {
/*                 Seek a positive residual. */
/* SOURCE culvertb.for:753 */
/*<       yt=0.9*y >*/
			yt = static_cast<double>(y) * (float).9;
/* SOURCE culvertb.for:754 */
/*<       if(yt.lt.y2min)then >*/
			if (yt < y2min) {
/* SOURCE culvertb.for:755 */
/*<       yt=0.5*(y+y2min) >*/
			    yt = static_cast<double>((static_cast<double>(y) + y2min)) * (float).5;
/* SOURCE culvertb.for:756 */
/*<       if(yt.eq.y2min)then >*/
			    if (yt == y2min) {
/* SOURCE culvertb.for:757 */
/*<       write(outun,76)y2min >*/
				feq_gen_io_d__64.ciunit = rqvtw_1.outun;
				s_wsfe(&feq_gen_io_d__64);
				do_fio(&feq_gen_c_d_1, (char *)&y2min, (ftnlen)sizeof(
					real));
				e_wsfe();
/* SOURCE culvertb.for:758 */
/*<       goto800 >*/
				goto L800;
/* SOURCE culvertb.for:759 */
/*<       endif >*/
			    }
/* SOURCE culvertb.for:760 */
/*<       endif >*/
			}
/* SOURCE culvertb.for:761 */
/*<       y=yt >*/
			y = yt;
/* SOURCE culvertb.for:762 */
/*<       goto100 >*/
			goto L100;
/* SOURCE culvertb.for:763 */
/*<       else >*/
		    } else {
/* SOURCE culvertb.for:764 */
/*<       goto110 >*/
			goto L110;
/* SOURCE culvertb.for:765 */
/*<       endif >*/
		    }
/* SOURCE culvertb.for:766 */
/*<       endif >*/
		}
/* SOURCE culvertb.for:767 */
/*<   110 continue >*/
L110:
/*             A sign change exists here. */
/* SOURCE culvertb.for:770 */
/*<       callrgf3(1.e-6,epsabs,rty0,ylow,yhigh,fl,fr,y2,flag) >*/
		rgf3_(&c_b59, &epscom_1.epsabs, rty0_, &ylow, &yhigh, &
			fl, &fr, &xs2com_1.y2, &feq_gen_flag_d_);
/* SOURCE culvertb.for:774 */
/*<       if(flag.eq.1)then >*/
		if (feq_gen_flag_d_ == 1) {
/* SOURCE culvertb.for:775 */
/*<       write(stdout,54) >*/
		    feq_gen_io_d__66.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__66);
		    e_wsfe();
/* SOURCE culvertb.for:776 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:777 */
/*<       elseif(flag.eq.2)then >*/
		} else if (feq_gen_flag_d_ == 2) {
/* SOURCE culvertb.for:778 */
/*<       write(stdout,60) >*/
		    feq_gen_io_d__67.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__67);
		    e_wsfe();
/* SOURCE culvertb.for:779 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:780 */
/*<       endif >*/
		}
/* SOURCE culvertb.for:781 */
/*<       endif >*/
	    }
/*          WRITE(STDOUT,*) ' FRFT0: Y2=',Y2 */
/* SOURCE culvertb.for:784 */
/*<       if(sflag0.eq.0)then >*/
	    if (rty0c_1.sflag0 == 0) {
/*           Profile problems in RTY0 */
/* SOURCE culvertb.for:786 */
/*<       write(stdout,82) >*/
		feq_gen_io_d__68.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__68);
		e_wsfe();
/* SOURCE culvertb.for:787 */
/*<       if(wfrd.eq.0.0)then >*/
		if (rdfcom_1.wfrd == (float)0.) {
/* SOURCE culvertb.for:788 */
/*<       zsbrdf=z43 >*/
		    *zsbrdf = x43com_1.z43;
/* SOURCE culvertb.for:789 */
/*<       endif >*/
		}
/* SOURCE culvertb.for:790 */
/*<       goto800 >*/
		goto L800;
/* SOURCE culvertb.for:791 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:792 */
/*<       z43=z3 >*/
	    x43com_1.z43 = xs3com_1.z3;
/*          WRITE(STDOUT,*) ' Z43=',Z43,' ZSBRDF=',ZSBRDF,' Z1T=',Z1T */
/* SOURCE culvertb.for:794 */
/*<       if(z43.gt.zsbrdf)then >*/
	    if (x43com_1.z43 > *zsbrdf) {
/*           Tailwater is higher than the roadway crest. */
/* SOURCE culvertb.for:796 */
/*<       write(stdout,78)z43-zsbrdf >*/
		feq_gen_io_d__69.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__69);
		feq_gen_r_d_1 = static_cast<double>(x43com_1.z43) - *zsbrdf;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE culvertb.for:797 */
/*<       if(z43.gt.z1t)then >*/
		if (x43com_1.z43 > rqvtw_1.z1t) {
/*             Tailwater is higher than the upstream head */
/* SOURCE culvertb.for:799 */
/*<       write(stdout,80) >*/
		    feq_gen_io_d__70.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__70);
		    e_wsfe();
/* SOURCE culvertb.for:800 */
/*<       endif >*/
		}
/*            Z43MAX = Z43 */
/* SOURCE culvertb.for:802 */
/*<       goto800 >*/
		goto L800;
/* SOURCE culvertb.for:803 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:804 */
/*<       goto900 >*/
	    goto L900;
/* SOURCE culvertb.for:805 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:806 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:808 */
/*<       if(type.eq.1)return >*/
    if (*feq_gen_type_d_ == 1) {
	return 0;
    }
/* SOURCE culvertb.for:810 */
/*<   800 continue >*/
L800:
/* SOURCE culvertb.for:811 */
/*<       if(wfrd.gt.0.0)then >*/
    if (rdfcom_1.wfrd > (float)0.) {
/* SOURCE culvertb.for:812 */
/*<       write(stdout,*)'  Type 0 fails with flow over the road.' >*/
	feq_gen_io_d__71.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__71);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("  Type 0 fails with flow over the road."), (
		ftnlen)39);
	e_wsle();
/* SOURCE culvertb.for:813 */
/*<       else >*/
    } else {
/* SOURCE culvertb.for:814 */
/*<       write(stdout,*)'  Type 0 fails with no flow over the road.' >*/
	feq_gen_io_d__72.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__72);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("  Type 0 fails with no flow over the road."), (
		ftnlen)42);
	e_wsle();
/* SOURCE culvertb.for:815 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:816 */
/*<       return >*/
    return 0;
/* SOURCE culvertb.for:818 */
/*<   900 continue >*/
L900:
/* SOURCE culvertb.for:821 */
/*<       y43=z43-zb43 >*/
    x43com_1.y43 = static_cast<double>(x43com_1.z43) - x43com_1.zb43;
/* SOURCE culvertb.for:822 */
/*<       z43old=z43 >*/
    x43com_1.z43old = x43com_1.z43;
/* SOURCE culvertb.for:823 */
/*<       z3p=z43 >*/
    xs3com_1.z3p = x43com_1.z43;
/* SOURCE culvertb.for:824 */
/*<       z3=z3p >*/
    xs3com_1.z3 = xs3com_1.z3p;
/* SOURCE culvertb.for:825 */
/*<       y3=z3-zb3 >*/
    xs3com_1.y3 = static_cast<double>(xs3com_1.z3) - xs3com_1.zb3;
/* SOURCE culvertb.for:826 */
/*<       if(y2.ge.dup.and.y3.ge.ddn)then >*/
    if (xs2com_1.y2 >= dup && xs3com_1.y3 >= ddn) {
/* SOURCE culvertb.for:827 */
/*<       write(stdout,84) >*/
	feq_gen_io_d__73.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__73);
	e_wsfe();
/* SOURCE culvertb.for:828 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE culvertb.for:829 */
/*<       return >*/
	return 0;
/* SOURCE culvertb.for:830 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:831 */
/*<       tp=min(y3,ddn) >*/
    tp = dmin(xs3com_1.y3,ddn);
/* SOURCE culvertb.for:832 */
/*<       callxlktal(adrxs3,tp,a3,t3,dt3,j3,k3,dk3,bet3,dbet3,alp3,dalp3) >*/
    xlktal_(&xs3com_1.adrxs3, &tp, &xs3com_1.a3, &xs3com_1.t3, &xs3com_1.dt3, 
	    &xs3com_1.j3, &xs3com_1.k3, &xs3com_1.dk3, &xs3com_1.bet3, &
	    xs3com_1.dbet3, &xs3com_1.alp3, &xs3com_1.dalp3);
/* SOURCE culvertb.for:836 */
/*<       calllktj(adrxs3,y3,j3) >*/
    lktj_(&xs3com_1.adrxs3, &xs3com_1.y3, &xs3com_1.j3);
/*      WRITE(STDOUT,*) ' FRFT0: Z43=',Z43,' Q3=',Q3 */
/* SOURCE culvertb.for:842 */
/*<       qfree=q3 >*/
    *qfree = xs3com_1.q3;
/* SOURCE culvertb.for:843 */
/*<       q3free=q3 >*/
    xs3com_1.q3free = xs3com_1.q3;
/* SOURCE culvertb.for:844 */
/*<       y2free=y2 >*/
    xs2com_1.y2free = xs2com_1.y2;
/* SOURCE culvertb.for:845 */
/*<       y3free=y3 >*/
    xs3com_1.y3free = xs3com_1.y3;
/* SOURCE culvertb.for:846 */
/*<       lftype=0 >*/
    xs2com_1.lftype = 0;
/* SOURCE culvertb.for:847 */
/*<       lstype=-1 >*/
    xs2com_1.lstype = -1;
/*     Now find the drop to the water level at section 4. */
/* SOURCE culvertb.for:852 */
/*<       calldpm26(stdout,wfrd,mfrd,z3,expflg) >*/
    dpm26_(stdout, &rdfcom_1.wfrd, &rdfcom_1.mfrd, &xs3com_1.z3, expflg);
/* SOURCE culvertb.for:855 */
/*<       if(expflg.eq.0)then >*/
    if (*expflg == 0) {
/* SOURCE culvertb.for:856 */
/*<       freed=0.0 >*/
	*freed = (float)0.;
/* SOURCE culvertb.for:857 */
/*<       return >*/
	return 0;
/* SOURCE culvertb.for:858 */
/*<       endif >*/
    }
/*     DEPARTURE SECTION VALUES ARE IN XS4COM */
/* SOURCE culvertb.for:862 */
/*<       freed=z1t-z4 >*/
    *freed = static_cast<double>(rqvtw_1.z1t) - xs4com_1.z4;
/*      WRITE(OUTUN,*) ' FRFT0: FREED=',FREED */
/* SOURCE culvertb.for:864 */
/*<       return >*/
    return 0;
/* SOURCE culvertb.for:866 */
/*<       end >*/
} /* frft0_ */




/* SOURCE culvertb.for:870 */
/*<       subroutinety1gy2(stdout,iu,id,dup,culcls,yat2,truea1,eflag) >*/
/* Subroutine */ int ty1gy2_(integer *stdout, integer *iu, integer *id, real *
	dup, char *culcls, real *yat2, real *truea1, integer *eflag, ftnlen 
	culcls_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:570* Zero depth before negative res\
idual while\002,\002 seeking Type 1 limit.\002)";
    static char fmt_52[] = "(/,\002 *ERR:594* Maximum depth before positive \
residual\002,\002 while seeking Type 1 limit.\002)";
    static char fmt_54[] = "(\002 *BUG:XXX* SIGN CHNG ON ENTRY BUT REGFLT CL\
AIMS NONE IN\002,\002 TY1GY2.\002)";
    static char fmt_60[] = "(\002 *BUG:XXX* REGFLT: MORE THAN 100 ITERATIONS\
 IN TY1GY2.\002)";
    static char fmt_62[] = "(/,\002 *ERR:683* Flow at section 1 has Froude n\
umber=\002,f8.3,/,11x,\002seeking Type 1 flow limit.\002)";
    static char fmt_72[] = "(\002  Initial loss for type 3 submergence=\002,\
1pe10.3)";
    static char fmt_74[] = "(\002  Final loss for type 3 submergence=\002,1p\
e10.3)";

    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer do_fio(integer *, char *, ftnlen), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle();

    /* Local variables */
    real f, y, cd, dh, fh, fl;
    integer is;
    real yt, c123, y3l, avh, zdn, q1cl, q2cl;
    integer feq_gen_flag_d_;
    real zbeg;
    extern /* Subroutine */ int lkta_(integer *, real *, real *);
    extern doublereal fcd123_(integer *, integer *, char *, real *, real *, 
	    ftnlen);
    real ylow;
    integer sflag;
    real yhigh;
    extern /* Subroutine */ int xlkt22_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *);
    extern doublereal ry1gy2_(real *);
    extern /* Subroutine */ int sfpty1_(integer *, integer *, integer *, real 
	    *, real *, real *, integer *, real *, integer *);
    extern doublereal degcon_(real *, real *, real *);
    real maxarg;
    extern /* Subroutine */ int regflt_(real *, real *, FeqCallback3, real *, real *, 
	    real *, real *, real *, integer *);
    extern doublereal fmxarg_(integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__81 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__84 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__86 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__87 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__89 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__94 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__95 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__96 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__101 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__103 = { 0, 0, 0, fmt_74, 0 };


/*     + + + PURPOSE + + + */
/*     Compute results for flow type 1 when the depth at section 2 */
/*     is given.  Compute the conditions to section 3 as well. */
/*     Used to establish limits for type 1 flow. */
/* SOURCE culvertb.for:879 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertb.for:882 */
/*<       integereflag,id,iu,stdout >*/
/* SOURCE culvertb.for:883 */
/*<       realdup,truea1,yat2 >*/
/* SOURCE culvertb.for:884 */
/*<       characterculcls*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     IU     - Index for upstream node for the culvert barrel */
/*     ID     - Index for the downstream node for the culvert barrel */
/*     DUP    - vertical diameter of culvert barrel at upstream end */
/*     CULCLS - Class for culvert shape, BOX, PIPE, .. */
/*     YAT2   - depth at section 2 */
/*     TRUEA1 - area at section 1 */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertb.for:897 */
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
/* INCLUDE culvertb.for:898 */
/* SOURCE xs1com.cmn:2 */
/*<        >*/
/* SOURCE xs1com.cmn:7 */
/*<       integeradrxs1 >*/
/* SOURCE xs1com.cmn:9 */
/*<        >*/
/*     Z1TY1- elevation at section 1 at type 1 limit if it exists */
/*     Z1TY1L-elevation at section 1 at lower limit of type 1 if it exists */
/*     Z1TY6- elevation at section 1 at start of type 6 if it exists */
/*     Z1TY2- elevation at upper limit of type 2 flow if it exists */
/*     Z1TY61- elevation at upper limt of type 61 if it exists */
/*     Z1TY5- elevation at section at start of type 5 if it exists */
/*     Z1TY52- elevation at section 1 at lower limit of type 52( */
/*             type 2 to type 5 flow) */
/*     Z1TY51- elevation at section 1 at lower limit of type 51( */
/*             type 1 to type 5 flow) */
/* INCLUDE culvertb.for:899 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culvertb.for:900 */
/*     Common to hold values needed for computing various limits */
/*     for culvert flow types. */
/* SOURCE typlim.cmn:4 */
/*<        >*/
/* SOURCE typlim.cmn:10 */
/*<       integerhhtype >*/
/* SOURCE typlim.cmn:12 */
/*<        >*/
/* INCLUDE culvertb.for:901 */
/* SOURCE xs3com.cmn:2 */
/*<        >*/
/* SOURCE xs3com.cmn:11 */
/*<       integeradrxs3 >*/
/* SOURCE xs3com.cmn:13 */
/*<        >*/
/*     CD1- if 0.0 type 1 flow has not been checked, if > 0 type 1 */
/*          flow has been checked and found to exist and its limit */
/*          values have been found, if < 0 type 1 flow does not exist. */
/*     CD2T6- coef. of discharge forcing full flow to match flow */
/*            at the type 2 flow limit. */
/*     AP2T6 - kinetic energy flux coefficient forcing the full */
/*             flow kinetic energy flux to match the flux */
/*             at the type 2 limit. */
/*     BT2T6- momentum flux coefficient forcing the full flow */
/*            momentum flux to match the flux at the type 2 limit. */
/*     CD61T6- coef. of discharge forcing full flow to match flow */
/*             at the type 61 limit. */
/*     CD1T6- coef. of discharge forcing full flow to match flow */
/*            at the type 1 limit */

/*     AP61T6- same as AP2T6 for type 61. */
/*     BT61T6- same as AP2T6 for type 61. */
/*     CD2- coef. of discharge for type 2 flow at the type 2 limit. */
/*     CD61- coef. of discharge for type 61 flow at the type 61 limit. */
/*     CD6- coef. of discharge for type 6 flow. */
/*     Z3PTY6- piezometric level at section 3 at the type 6 limit. */
/*     AVH2- area for velocity head at the type 2 limit. */
/*     AVH61- area for velocity head at the type 61 limit. */
/*     BT3ATD- beta at section 3 when barrel is full(at D!) */
/*     AP3ATD- alpha at section 3 when the barrel is full(at D!) */
/*     CC2T5 - contraction coefficient for type 5 at the type 2 flow */
/*             limit. */
/*     CC1T5 - contraction coefficient for type 5 at the type 1 flow */
/*             limit. */
/*     CC5- contraction coefficient for type 5 at its lower limit */
/*          and above. */
/*     Y3TY52- depth at section 3 at the lower limit of type 52 flow */
/*             giving the transistion between type 2 and type 5. */
/*     Y3TY51- depth at section 3 at the lower limit of type 51 flow */
/*             giving the transistion between type 1 and type 5. */
/*     BT2T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 52 and */
/*             upper limit of type 2. */
/*     BT1T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 51 and */
/*             upper limit of type 1. */
/*     AP2T5-  alpha analogous to BT2T5 */
/*     AP1T5-  alpha analogous to BT1T5 */
/*     Y3TY5-  depth at section 3 at the lower limit of type 5 flow */
/*     BT3AT5- beta for type 5 flow limit */
/*     AP3AT5- alpha for type 5 flow limit */
/*     CD5T4- coefficient of discharge that forces a type 4 equation */
/*            to match the type 5, 51, or 52 flow at the full-flow- */
/*            inducing level at section 43. */
/*     Y3LTY2- depth at section 3 at the type 2 limit, that is, */
/*             critical depth. */
/*     Y3LTY1- submergence depth at section 3  at the limit of */
/*             type 1 flow. */
/*     Y3LTY5- the full-flow-inducing value of piezometric level */
/*             relative to the invert at section 3 for flow types */
/*             5, 51, and 52. */
/* INCLUDE culvertb.for:902 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE culvertb.for:903 */
/*     Common for RT1GY2 residual function. */
/* SOURCE y1gy2.cmn:3 */
/*<       common/y1gy2/zsbrdf,conf,outun,d >*/
/* SOURCE y1gy2.cmn:5 */
/*<       integerconf,outun >*/
/* SOURCE y1gy2.cmn:7 */
/*<       realzsbrdf,d >*/
/* SOURCE y1gy2.cmn:9 */
/*<       character*8class >*/
/* SOURCE y1gy2.cmn:11 */
/*<       common/y1gy2c/class >*/
/* INCLUDE culvertb.for:904 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertb.for:907 */
/*<       integerflag,is,sflag >*/
/* SOURCE culvertb.for:908 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertb.for:912 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertb.for:915 */
/*<       realdegcon,fcd123,fmxarg,ry1gy2 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertb.for:918 */
/*<       externaldegcon,fcd123,fmxarg,lkta,regflt,ry1gy2,sfpty1,xlkt22 >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertb.for:922 */
/*<    50  >*/
/* SOURCE culvertb.for:924 */
/*<    52  >*/
/* SOURCE culvertb.for:926 */
/*<    54  >*/
/* SOURCE culvertb.for:928 */
/*<    60 format(' *BUG:XXX* REGFLT: MORE THAN 100 ITERATIONS IN TY1GY2.') >*/
/* SOURCE culvertb.for:929 */
/*<    62  >*/
/* SOURCE culvertb.for:931 */
/*<    72 format('  Initial loss for type 3 submergence=',1pe10.3) >*/
/* SOURCE culvertb.for:932 */
/*<    74 format('  Final loss for type 3 submergence=',1pe10.3) >*/
/* *********************************************************************** */
/*     Place values in common block for residual function. */
/* SOURCE culvertb.for:935 */
/*<       class=culcls >*/
/* L50: */
/* L52: */
/* L54: */
/* L60: */
/* L62: */
/* L72: */
/* L74: */
    s_copy(y1gy2c_1.feq_gen_class_d_, culcls, (ftnlen)8, (ftnlen)8);
/* SOURCE culvertb.for:936 */
/*<       outun=stdout >*/
    y1gy2_1.outun = *stdout;
/* SOURCE culvertb.for:937 */
/*<       d=dup >*/
    y1gy2_1.feq_gen_d_d_ = *dup;
/*     Define values at section 2.  The flow is critical at this */
/*     section, so define flow in the culvert as well. */
/* SOURCE culvertb.for:941 */
/*<       y2l=yat2 >*/
    typlim_1.y2l = *yat2;
/* SOURCE culvertb.for:942 */
/*<       z2l=zb2+y2l >*/
    typlim_1.z2l = static_cast<double>(xs2com_1.zb2) + typlim_1.y2l;
/* SOURCE culvertb.for:943 */
/*<        >*/
    xlkt22_(&xs2com_1.adrxs2, &typlim_1.y2l, &typlim_1.a2l, &typlim_1.t2l, &
	    typlim_1.dt2l, &typlim_1.j2l, &typlim_1.k2l, &typlim_1.dk2l, &
	    typlim_1.bet2l, &typlim_1.dbet2l, &typlim_1.alp2l, &
	    typlim_1.dalp2l, &q2cl);
/* SOURCE culvertb.for:949 */
/*<       q2l=q2cl >*/
    typlim_1.q2l = q2cl;
/*     Make first estimate of the elevation at section 1 */
/* SOURCE culvertb.for:952 */
/*<       z1l=zb2+1.5*y2l >*/
    typlim_1.z1l = static_cast<double>(xs2com_1.zb2) + static_cast<double>(typlim_1.y2l) * (float)1.5;
/* SOURCE culvertb.for:953 */
/*<       y1l=z1l-zb1 >*/
    typlim_1.y1l = static_cast<double>(typlim_1.z1l) - xs1com_1.zb1;
/* SOURCE culvertb.for:954 */
/*<       if(y1l.lt.0.0)then >*/
    if (typlim_1.y1l < (float)0.) {
/* SOURCE culvertb.for:955 */
/*<       y1l=0.2*dup >*/
	typlim_1.y1l = static_cast<double>(*dup) * (float).2;
/* SOURCE culvertb.for:956 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:957 */
/*<       y=y1l >*/
    y = typlim_1.y1l;
/* SOURCE culvertb.for:958 */
/*<       maxarg=fmxarg(adrxs1) >*/
    maxarg = fmxarg_(&xs1com_1.adrxs1);
/*     Search for a sign change in the residual function. */
/* SOURCE culvertb.for:960 */
/*<       ylow=0.0 >*/
    ylow = (float)0.;
/* SOURCE culvertb.for:961 */
/*<       yhigh=0.0 >*/
    yhigh = (float)0.;
/* SOURCE culvertb.for:963 */
/*<   100 continue >*/
L100:
/* SOURCE culvertb.for:964 */
/*<       f=ry1gy2(y) >*/
    f = ry1gy2_(&y);
/* SOURCE culvertb.for:965 */
/*<       if(abs(f).gt.epsabs)then >*/
    if (dabs(f) > epscom_1.epsabs) {
/*         Residual is too large.  Search for a sign change. */
/* SOURCE culvertb.for:967 */
/*<       if(f.gt.0.0)then >*/
	if (f > (float)0.) {
/* SOURCE culvertb.for:968 */
/*<       yhigh=y >*/
	    yhigh = y;
/* SOURCE culvertb.for:969 */
/*<       fh=f >*/
	    fh = f;
/* SOURCE culvertb.for:970 */
/*<       if(ylow.eq.0.0)then >*/
	    if (ylow == (float)0.) {
/*             Make depth at section 1 smaller to find a negative */
/*             residual. */
/* SOURCE culvertb.for:973 */
/*<       y=0.95*y >*/
		y *= static_cast<double>((float).95);
/* SOURCE culvertb.for:974 */
/*<       if(y.le.epsabs)then >*/
		if (y <= epscom_1.epsabs) {
/* SOURCE culvertb.for:975 */
/*<       write(stdout,50) >*/
		    feq_gen_io_d__81.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__81);
		    e_wsfe();
/* SOURCE culvertb.for:976 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:977 */
/*<       endif >*/
		}
/* SOURCE culvertb.for:978 */
/*<       goto100 >*/
		goto L100;
/* SOURCE culvertb.for:979 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:980 */
/*<       else >*/
	} else {
/* SOURCE culvertb.for:981 */
/*<       ylow=y >*/
	    ylow = y;
/* SOURCE culvertb.for:982 */
/*<       fl=f >*/
	    fl = f;
/* SOURCE culvertb.for:983 */
/*<       if(yhigh.eq.0.0)then >*/
	    if (yhigh == (float)0.) {
/*             Make depth at section 1 larger to find a positive */
/*             residual. */
/* SOURCE culvertb.for:986 */
/*<       yt=1.05*y >*/
		yt = static_cast<double>(y) * (float)1.05;
/* SOURCE culvertb.for:987 */
/*<       if(yt.gt.maxarg)then >*/
		if (yt > maxarg) {
/* SOURCE culvertb.for:988 */
/*<       yt=0.5*(y+maxarg) >*/
		    yt = static_cast<double>((static_cast<double>(y) + maxarg)) * (float).5;
/* SOURCE culvertb.for:989 */
/*<       if(maxarg-yt.le.epsabs)then >*/
		    if (static_cast<double>(maxarg) - yt <= epscom_1.epsabs) {
/* SOURCE culvertb.for:990 */
/*<       write(stdout,52) >*/
			feq_gen_io_d__84.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__84);
			e_wsfe();
/* SOURCE culvertb.for:991 */
/*<       stop'Abnormal stop. Errors found.' >*/
			s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:992 */
/*<       endif >*/
		    }
/* SOURCE culvertb.for:993 */
/*<       endif >*/
		}
/* SOURCE culvertb.for:994 */
/*<       y=yt >*/
		y = yt;
/* SOURCE culvertb.for:995 */
/*<       goto100 >*/
		goto L100;
/* SOURCE culvertb.for:996 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:997 */
/*<       endif >*/
	}
/*         We have a sign change in the residual at this point. */
/*         Find a root. */
/* SOURCE culvertb.for:1002 */
/*<       callregflt(0.0,epsabs,ry1gy2,ylow,yhigh,fl,fh,y,flag) >*/
	regflt_(&c_b52, &epscom_1.epsabs, ry1gy2_, &ylow, &yhigh, &fl, &
		fh, &y, &feq_gen_flag_d_);
/* SOURCE culvertb.for:1007 */
/*<       if(flag.eq.1)then >*/
	if (feq_gen_flag_d_ == 1) {
/* SOURCE culvertb.for:1008 */
/*<       write(stdout,54) >*/
	    feq_gen_io_d__86.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__86);
	    e_wsfe();
/* SOURCE culvertb.for:1009 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:1010 */
/*<       elseif(flag.eq.2)then >*/
	} else if (feq_gen_flag_d_ == 2) {
/* SOURCE culvertb.for:1011 */
/*<       write(stdout,60) >*/
	    feq_gen_io_d__87.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__87);
	    e_wsfe();
/* SOURCE culvertb.for:1012 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:1013 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:1014 */
/*<       endif >*/
    }
/*     Find the final values at section 1. */
/* SOURCE culvertb.for:1016 */
/*<       y1l=y >*/
    typlim_1.y1l = y;
/* SOURCE culvertb.for:1017 */
/*<       z1l=zb1+y1l >*/
    typlim_1.z1l = static_cast<double>(xs1com_1.zb1) + typlim_1.y1l;
/* SOURCE culvertb.for:1018 */
/*<        >*/
    xlkt22_(&xs1com_1.adrxs1, &typlim_1.y1l, &typlim_1.a1l, &typlim_1.t1l, &
	    typlim_1.dt1l, &typlim_1.j1l, &typlim_1.k1l, &typlim_1.dk1l, &
	    typlim_1.bet1l, &typlim_1.dbet1l, &typlim_1.alp1l, &
	    typlim_1.dalp1l, &q1cl);
/*     Check for supercritical flow at section 1 */
/* SOURCE culvertb.for:1024 */
/*<       if(q1l/q1cl.gt.1.02)then >*/
    if (static_cast<double>(typlim_1.q1l) / q1cl > (float)1.02) {
/* SOURCE culvertb.for:1025 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE culvertb.for:1026 */
/*<       write(stdout,62)q1l/q1cl >*/
	feq_gen_io_d__89.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__89);
	feq_gen_r_d_1 = static_cast<double>(typlim_1.q1l) / q1cl;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culvertb.for:1027 */
/*<       return >*/
	return 0;
/* SOURCE culvertb.for:1028 */
/*<       endif >*/
    }
/*     Find the submergence conditions at section 3.  Same method */
/*     as in FRFT1. */
/*     Find the depth at the first distance step using direct */
/*     integration to try to avoid continuing problems with */
/*     finding free drop for type 1 flow. */
/*      OFFSET = ABS(XVEC(IU+1) - XVEC(IU)) */
/*      SB = (ZBVEC(IU) - ZBVEC(IU+1))/OFFSET */
/*      FFAC = 1.0 - KD(IU+1) */
/*      CALL BEGSFP(NSEC(IU), FFAC, Y2L, Q2L, OFFSET, SB, YSTART) */
/*      WRITE(STDOUT,*) ' TY1GY2: OFFSET=',OFFSET,' YSTART=',YSTART, */
/*     A                ' Y2=',Y2 */
/*      ZBEG = YSTART + ZBVEC(IU+1) */
/* SOURCE culvertb.for:1044 */
/*<       zbeg=z2l >*/
    zbeg = typlim_1.z2l;
/* SOURCE culvertb.for:1045 */
/*<       dh=0.0 >*/
    dh = (float)0.;
/* SOURCE culvertb.for:1046 */
/*<       callsfpty1(stdout,iu,id,dh,q2l,zbeg,is,zdn,flag) >*/
    sfpty1_(stdout, iu, id, &dh, &typlim_1.q2l, &zbeg, &is, &zdn, &feq_gen_flag_d_);
/* SOURCE culvertb.for:1049 */
/*<       if(flag.eq.0)then >*/
    if (feq_gen_flag_d_ == 0) {
/* SOURCE culvertb.for:1050 */
/*<       write(stdout,*)' TY1GY2: Problem in SFPTY1 with DH=0.0' >*/
	feq_gen_io_d__94.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__94);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" TY1GY2: Problem in SFPTY1 with DH=0.0"), (
		ftnlen)38);
	e_wsle();
/* SOURCE culvertb.for:1051 */
/*<       write(stdout,*)' IU=',iu,' ID=',id,' IS=',is >*/
	feq_gen_io_d__95.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__95);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" IU="), (ftnlen)4);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*iu), (ftnlen)sizeof(integer));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" ID="), (ftnlen)4);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*id), (ftnlen)sizeof(integer));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" IS="), (ftnlen)4);
	do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&is, (ftnlen)sizeof(integer));
	e_wsle();
/* SOURCE culvertb.for:1052 */
/*<       write(stdout,*)' Z2L=',z2l,' Y2L=',y2l,' Q2L=',q2l >*/
	feq_gen_io_d__96.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__96);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Z2L="), (ftnlen)5);
	do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&typlim_1.z2l, (ftnlen)sizeof(real));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Y2L="), (ftnlen)5);
	do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&typlim_1.y2l, (ftnlen)sizeof(real));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Q2L="), (ftnlen)5);
	do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&typlim_1.q2l, (ftnlen)sizeof(real));
	e_wsle();
/* SOURCE culvertb.for:1053 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE culvertb.for:1054 */
/*<       else >*/
    } else {
/*       Now that we have an estimate of the conditions at section */
/*       3 when the critical control at section 2 is just being */
/*       submerged, estimate the type 3 losses that should take */
/*       place. */
/* SOURCE culvertb.for:1059 */
/*<       y3l=zdn-zb3 >*/
	y3l = static_cast<double>(zdn) - xs3com_1.zb3;
/* SOURCE culvertb.for:1060 */
/*<       calllkta(adrxs3,y3l,avh) >*/
	lkta_(&xs3com_1.adrxs3, &y3l, &avh);
/*       Select the losses as in RQVSTW. */
/* SOURCE culvertb.for:1065 */
/*<       c123=fcd123(stdout,3,culcls,dup,z1l) >*/
	c123 = fcd123_(stdout, &feq_gen_c_d_3, culcls, dup, &typlim_1.z1l, (ftnlen)8);
/* SOURCE culvertb.for:1066 */
/*<       cd=degcon(c123,truea1,avh) >*/
	cd = degcon_(&c123, truea1, &avh);
/* SOURCE culvertb.for:1067 */
/*<       dh=(1.0/cd**2-1.0)*(q2l/avh)**2/grav2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = cd;
/* Computing 2nd power */
	feq_gen_r_d_2 = static_cast<double>(typlim_1.q2l) / avh;
	dh = static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - (float)1.)) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) / 
		grvcom_1.grav2;
/* SOURCE culvertb.for:1068 */
/*<       write(stdout,72)dh >*/
	feq_gen_io_d__101.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__101);
	do_fio(&feq_gen_c_d_1, (char *)&dh, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culvertb.for:1069 */
/*<   200 continue >*/
L200:
/* SOURCE culvertb.for:1070 */
/*<       callsfpty1(stdout,iu,id,dh,q2l,zbeg,is,zdn,sflag) >*/
	sfpty1_(stdout, iu, id, &dh, &typlim_1.q2l, &zbeg, &is, &zdn, &sflag);
/* SOURCE culvertb.for:1073 */
/*<       if(sflag.eq.0)then >*/
	if (sflag == 0) {
/*           If estimated losses cause computational problems, reduce */
/*           the losses and try again until the computations are */
/*           successful. */
/* SOURCE culvertb.for:1077 */
/*<       dh=0.9*dh >*/
	    dh *= static_cast<double>((float).9);
/* SOURCE culvertb.for:1078 */
/*<       goto200 >*/
	    goto L200;
/* SOURCE culvertb.for:1079 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:1080 */
/*<       write(stdout,74)dh >*/
	feq_gen_io_d__103.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__103);
	do_fio(&feq_gen_c_d_1, (char *)&dh, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culvertb.for:1081 */
/*<       y3lty1=zdn-zb3 >*/
	xs3com_1.y3lty1 = static_cast<double>(zdn) - xs3com_1.zb3;
/* SOURCE culvertb.for:1082 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:1084 */
/*<       return >*/
    return 0;
/* SOURCE culvertb.for:1085 */
/*<       end >*/
} /* ty1gy2_ */




/* SOURCE culvertb.for:1089 */
/*<       subroutinety1bdy(stdout,dup,ddn,iu,id,culcls,truea1,eflag) >*/
/* Subroutine */ int ty1bdy_(integer *stdout, real *dup, real *ddn, integer *
	iu, integer *id, char *culcls, real *truea1, integer *eflag, ftnlen 
	culcls_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:684* Negative depth at section 1 fo\
r type 1 flow\002,\002 when head ratio limit\002,/,11x,\002there=\002,f8.3\
,\002 and the\002,\002 culvert vertical diameter=\002,f8.3)";
    static char fmt_52[] = "(/,\002 *ERR:685* Culvert soffit reached in TY1B\
DY seeking\002,\002 a negative residual.\002)";
    static char fmt_54[] = "(/,\002 *ERR:686* Culvert invert reached in TY1B\
DY seeking\002,\002 a positive residual.\002)";
    static char fmt_56[] = "(\002 *BUG:XXX* SIGN CHNG ON ENTRY BUT REGFLT CL\
AIMS NONE IN\002,\002 TY1BDY.\002)";
    static char fmt_60[] = "(\002 *BUG:XXX* REGFLT: MORE THAN 100 ITERATIONS\
 IN TY1BDY.\002)";
    static char fmt_62[] = "(/,\002 The depth limit at section 2 causes th\
e\002,\002 limiting head ratio=\002,f8.3,/,\002  to exceed the\002,\002 limi\
ting ratio for type 1 flow=\002,f8.3)";
    static char fmt_64[] = "(/,\002 The depth limit at section 2 causes the \
limiting\002,\002 head ratio to be:\002,f8.3)";
    static char fmt_66[] = "(/,\002 *BUG:XXX* More than 100 iterations and n\
o sign change\002,\002 in TY1BDY.\002)";
    static char fmt_68[] = "(/,\002 Type 1 depth limit at section 2=\002,f8.\
3,\002, taken at\002,\002 maximum value allowed.\002)";
    static char fmt_70[] = "(/,\002 Type 1 depth limit at section 2=\002,f8.\
3,\002, defined by\002,\002 match of bottom\002,/,\002   slope and critical \
slope.\002)";
    static char fmt_72[] = "(/,\002 Lower limit for type 1 flow at section\
 1=\002,f8.3)";
    static char fmt_74[] = "(/,\002 Lower limit for type 1 flow does not exi\
st.\002)";
    static char fmt_76[] = "(/,\002 *WRN:534* Unable to force type 6 Cd to m\
atch type 1\002,\002 flow at its limit.\002,/,11x,\002 Using type 6 Cd. \002,\
\002Manual adjustment of 2-D table may be needed.\002)";
    static char fmt_78[] = "(/,\002 *ERR:687* Upper limit for type 1 flow do\
es not\002,\002 exist.  Type 0 flow found.\002,/,11x,\002Culvert representat\
ion\002,\002 MUST be changed.  See error message summary.\002)";
    static char fmt_80[] = "(/,\002 Type 1 limits:\002,/,4x,\002Depth at sec\
tion 1 for lower type 1=\002,f8.3,/,4x,\002Depth at section 1 for upper type\
 1=\002,f8.3,/,4x,\002Depth at section 3 for upper type 1=\002,f8.3)";
    static char fmt_82[] = "(/,\002 Parameters for transition from type 1 to\
 type 5:\002,/,4x,\002Contraction coefficient=\002,f8.3,/,4x,\002Momentum-fl\
ux coefficient=\002,f8.3,/,4x,\002Kinetic-energy flux coefficient=\002,f8.3)";
    static char fmt_84[] = "(/,\002 Parameters for transition from type 1 to\
 type 6:\002,/,4x,\002Coefficient of discharge=\002,f8.3,/,4x,\002Momentum-f\
lux coefficient=\002,f8.3,/,4x,\002Kinetic-energy flux coefficient=\002,f8.3)"
	    ;
    static char fmt_86[] = "(\002  Initial loss for type 3 submergence=\002,\
1pe10.3)";
    static char fmt_88[] = "(\002  Final loss for type 3 submergence=\002,1p\
e10.3)";
    static char fmt_89[] = "(\002 Minimum depth at section 2 for critical fl\
ow match >\002,\002 limit at section 2=\002,f8.3,\002.\002,/,\002  Type 1 fl\
ow not possible.\002)";
    static char fmt_90[] = "(/,\002 Warning: Sequence of conditions to this \
point\002,/,\002indicates possible computational failure.  If computation\
s\002,/,\002fail, be sure to read all descriptions of error messages\002,/\
,\002that appear.  Representation of the culvert may need\002,/,\002adjustme\
nt to allow flow computations to continue.\002)";

    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3, feq_gen_r_d_4;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(), s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), 
	    e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    real a, f, y, dh, fh, fl, qc;
    integer is;
    real tp, yt, y3l, htd, zdn;
    integer knt;
    real yvc, q2lc, yat2, zat3;
    integer feq_gen_flag_d_;
    real zat43, zbeg;
    extern /* Subroutine */ int lkta_(integer *, real *, real *);
    extern doublereal fcd123_(integer *, integer *, char *, real *, real *, 
	    ftnlen);
    real ylow, ycat3, y2lim;
    integer sflag;
    real fdrdw, yhigh;
    extern doublereal ry2gy1_(real *);
    extern /* Subroutine */ int fndcc2_(integer *, real *, real *, real *), 
	    lktqc_(integer *, real *, real *), ty1gy2_(integer *, integer *, 
	    integer *, real *, char *, real *, real *, integer *, ftnlen), 
	    xlkt22_(integer *, real *, real *, real *, real *, real *, real *,
	     real *, real *, real *, real *, real *, real *), fndcde_(integer 
	    *, integer *, real *, real *), sfpty1_(integer *, integer *, 
	    integer *, real *, real *, real *, integer *, real *, integer *);
    extern doublereal degcon_(real *, real *, real *);
    real ty6lss;
    integer nscmat;
    real satmat[8], yatmat[8], zsbrdf;
    char jmploc[32];
    extern doublereal yoverd_(integer *, real *, real *, real *);
    extern /* Subroutine */ int fscmat_(integer *, integer *, real *, integer 
	    *, integer *, real *, real *), getfrf_(real *, real *, real *), 
	    regflt_(real *, real *, FeqCallback3, real *, real *, real *, real *, 
	    real *, integer *), supsub_(integer *, integer *, integer *, real 
	    *, real *, real *, real *, real *, real *, real *, real *, char *,
	     ftnlen), xlktal_(integer *, real *, real *, real *, real *, real 
	    *, real *, real *, real *, real *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__108 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__110 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__111 = { 0, 0, 0, fmt_89, 0 };
    static cilist feq_gen_io_d__112 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__113 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__114 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__115 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__116 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__117 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__118 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__120 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__121 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__129 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__132 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__134 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__136 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__137 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__143 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__144 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__146 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__148 = { 0, 0, 0, fmt_88, 0 };
    static cilist feq_gen_io_d__149 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__151 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__160 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__161 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__162 = { 0, 0, 0, fmt_84, 0 };
    static cilist feq_gen_io_d__163 = { 0, 0, 0, fmt_90, 0 };


/*     + + + PURPOSE + + + */
/*     Find the type 1 boundary, if it exists, and the values */
/*     needed for transition from type 1 to type 5 or from type 1 to */
/*     type 6. */
/* SOURCE culvertb.for:1098 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertb.for:1101 */
/*<       integereflag,id,iu,stdout >*/
/* SOURCE culvertb.for:1102 */
/*<       realddn,dup,truea1 >*/
/* SOURCE culvertb.for:1103 */
/*<       characterculcls*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     DUP    - vertical diameter of culvert barrel at upstream end */
/*     DDN    - vertical diameter of culvert barrel at downstream end */
/*     IU     - Index for upstream node for the culvert barrel */
/*     ID     - Index for the downstream node for the culvert barrel */
/*     CULCLS - Class for culvert shape, BOX, PIPE, .. */
/*     TRUEA1 - area at section 1 */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertb.for:1116 */
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
/* INCLUDE culvertb.for:1117 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertb.for:1118 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE culvertb.for:1119 */
/* SOURCE cdcom.cmn:2 */
/*<        >*/
/* SOURCE cdcom.cmn:10 */
/*<        >*/
/* SOURCE cdcom.cmn:14 */
/*<        >*/
/*     Add values for support of FHWA type 5 scheme. Oct. 3, 2001 */
/* SOURCE cdcom.cmn:20 */
/*<       realafhwa,cfhwa,yfhwa,sfhwa >*/
/*     AFHWA - value of a */
/*     CFHWA - value of c */
/*     YFHWA - value of Y */
/*     SFHWA - slope of culvert near entrance. */
/* INCLUDE culvertb.for:1120 */
/* SOURCE xs1com.cmn:2 */
/*<        >*/
/* SOURCE xs1com.cmn:7 */
/*<       integeradrxs1 >*/
/* SOURCE xs1com.cmn:9 */
/*<        >*/
/*     Z1TY1- elevation at section 1 at type 1 limit if it exists */
/*     Z1TY1L-elevation at section 1 at lower limit of type 1 if it exists */
/*     Z1TY6- elevation at section 1 at start of type 6 if it exists */
/*     Z1TY2- elevation at upper limit of type 2 flow if it exists */
/*     Z1TY61- elevation at upper limt of type 61 if it exists */
/*     Z1TY5- elevation at section at start of type 5 if it exists */
/*     Z1TY52- elevation at section 1 at lower limit of type 52( */
/*             type 2 to type 5 flow) */
/*     Z1TY51- elevation at section 1 at lower limit of type 51( */
/*             type 1 to type 5 flow) */
/* INCLUDE culvertb.for:1121 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culvertb.for:1122 */
/*     Common to hold values needed for computing various limits */
/*     for culvert flow types. */
/* SOURCE typlim.cmn:4 */
/*<        >*/
/* SOURCE typlim.cmn:10 */
/*<       integerhhtype >*/
/* SOURCE typlim.cmn:12 */
/*<        >*/
/* INCLUDE culvertb.for:1123 */
/* SOURCE xs3com.cmn:2 */
/*<        >*/
/* SOURCE xs3com.cmn:11 */
/*<       integeradrxs3 >*/
/* SOURCE xs3com.cmn:13 */
/*<        >*/
/*     CD1- if 0.0 type 1 flow has not been checked, if > 0 type 1 */
/*          flow has been checked and found to exist and its limit */
/*          values have been found, if < 0 type 1 flow does not exist. */
/*     CD2T6- coef. of discharge forcing full flow to match flow */
/*            at the type 2 flow limit. */
/*     AP2T6 - kinetic energy flux coefficient forcing the full */
/*             flow kinetic energy flux to match the flux */
/*             at the type 2 limit. */
/*     BT2T6- momentum flux coefficient forcing the full flow */
/*            momentum flux to match the flux at the type 2 limit. */
/*     CD61T6- coef. of discharge forcing full flow to match flow */
/*             at the type 61 limit. */
/*     CD1T6- coef. of discharge forcing full flow to match flow */
/*            at the type 1 limit */

/*     AP61T6- same as AP2T6 for type 61. */
/*     BT61T6- same as AP2T6 for type 61. */
/*     CD2- coef. of discharge for type 2 flow at the type 2 limit. */
/*     CD61- coef. of discharge for type 61 flow at the type 61 limit. */
/*     CD6- coef. of discharge for type 6 flow. */
/*     Z3PTY6- piezometric level at section 3 at the type 6 limit. */
/*     AVH2- area for velocity head at the type 2 limit. */
/*     AVH61- area for velocity head at the type 61 limit. */
/*     BT3ATD- beta at section 3 when barrel is full(at D!) */
/*     AP3ATD- alpha at section 3 when the barrel is full(at D!) */
/*     CC2T5 - contraction coefficient for type 5 at the type 2 flow */
/*             limit. */
/*     CC1T5 - contraction coefficient for type 5 at the type 1 flow */
/*             limit. */
/*     CC5- contraction coefficient for type 5 at its lower limit */
/*          and above. */
/*     Y3TY52- depth at section 3 at the lower limit of type 52 flow */
/*             giving the transistion between type 2 and type 5. */
/*     Y3TY51- depth at section 3 at the lower limit of type 51 flow */
/*             giving the transistion between type 1 and type 5. */
/*     BT2T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 52 and */
/*             upper limit of type 2. */
/*     BT1T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 51 and */
/*             upper limit of type 1. */
/*     AP2T5-  alpha analogous to BT2T5 */
/*     AP1T5-  alpha analogous to BT1T5 */
/*     Y3TY5-  depth at section 3 at the lower limit of type 5 flow */
/*     BT3AT5- beta for type 5 flow limit */
/*     AP3AT5- alpha for type 5 flow limit */
/*     CD5T4- coefficient of discharge that forces a type 4 equation */
/*            to match the type 5, 51, or 52 flow at the full-flow- */
/*            inducing level at section 43. */
/*     Y3LTY2- depth at section 3 at the type 2 limit, that is, */
/*             critical depth. */
/*     Y3LTY1- submergence depth at section 3  at the limit of */
/*             type 1 flow. */
/*     Y3LTY5- the full-flow-inducing value of piezometric level */
/*             relative to the invert at section 3 for flow types */
/*             5, 51, and 52. */
/* INCLUDE culvertb.for:1124 */
/* SOURCE culcom.cmn:2 */
/*<        >*/
/* SOURCE culcom.cmn:8 */
/*<       integernsec(mnbn),hltab(mnbn),iat3d,iat6d,sbkind,sbshape >*/
/* SOURCE culcom.cmn:10 */
/*<        >*/
/* SOURCE culcom.cmn:16 */
/*<       doubleprecisionfrcfac >*/
/*     FRCFAC- friction factor to give factor for friction losses */
/*             in barrel for non-prismatic full-flow that as well */
/*             as prismatic full flow. */
/*     TY1YTD- maximum ratio of depth to vertical diameter for */
/*             type 1 flow. */
/*     TY1HTD- maximum ratio of head at section 1 relative to */
/*             culvert invert at culvert inlet to the vertical */
/*             diamter of the culvert.  Must be less than 1.5. */
/*     SBKIND- if 0 the slope of the culvert barrel is a constant, */
/*             if 1 the slope of the culvert barrel varies. */
/*     BSHAPE- if 0 the barrel shape is constant, that is, prismatic, */
/*             if 1 the barrel shape is nonprismatic. */
/*     TY5SBF- ratio of depth to vertical diameter of the culvert */
/*             at the exit which causes submergence. */
/* Note:  25 August 2004:  SBSHAPE is apparently not used.  BSHAPE */
/* is but outside of a common block. */
/* INCLUDE culvertb.for:1125 */
/* SOURCE appcom.cmn:2 */
/*<       common/appcom/apptab,appelv,applen,applos,appexp,zertab,zerelv >*/
/* SOURCE appcom.cmn:5 */
/*<       integerapptab,zertab >*/
/* SOURCE appcom.cmn:7 */
/*<       realappelv,applen,applos,appexp,zerelv >*/
/* INCLUDE culvertb.for:1126 */
/*     Common for function RTY1 in FEQUTL */
/* SOURCE rty1c.cmn:3 */
/*<       common/rty1c/du,ftype,outun1,frsq,dhty1 >*/
/* SOURCE rty1c.cmn:4 */
/*<       character*8class1 >*/
/* SOURCE rty1c.cmn:5 */
/*<       integerftype,outun1 >*/
/* SOURCE rty1c.cmn:6 */
/*<       realdu,frsq,dhty1 >*/
/* SOURCE rty1c.cmn:8 */
/*<       common/rty1cc/class1 >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertb.for:1129 */
/*<       integerflag,is,knt,nscmat,sflag >*/
/* SOURCE culvertb.for:1130 */
/*<        >*/
/* SOURCE culvertb.for:1133 */
/*<       characterjmploc*32 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertb.for:1136 */
/*<       intrinsicabs,min,sqrt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertb.for:1139 */
/*<       realdegcon,fcd123,ry2gy1,yoverd >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertb.for:1142 */
/*<        >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertb.for:1147 */
/*<    50  >*/
/* SOURCE culvertb.for:1150 */
/*<    52  >*/
/* SOURCE culvertb.for:1152 */
/*<    54  >*/
/* SOURCE culvertb.for:1154 */
/*<    56  >*/
/* SOURCE culvertb.for:1156 */
/*<    60 format(' *BUG:XXX* REGFLT: MORE THAN 100 ITERATIONS IN TY1BDY.') >*/
/* SOURCE culvertb.for:1157 */
/*<    62  >*/
/* SOURCE culvertb.for:1160 */
/*<    64  >*/
/* SOURCE culvertb.for:1162 */
/*<    66  >*/
/* SOURCE culvertb.for:1164 */
/*<    68  >*/
/* SOURCE culvertb.for:1166 */
/*<    70  >*/
/* SOURCE culvertb.for:1168 */
/*<    72 format(/,' Lower limit for type 1 flow at section 1=',f8.3) >*/
/* SOURCE culvertb.for:1169 */
/*<    74 format(/,' Lower limit for type 1 flow does not exist.') >*/
/* SOURCE culvertb.for:1170 */
/*<    76  >*/
/* SOURCE culvertb.for:1173 */
/*<    78  >*/
/* SOURCE culvertb.for:1176 */
/*<    80  >*/
/* SOURCE culvertb.for:1180 */
/*<    82  >*/
/* SOURCE culvertb.for:1184 */
/*<    84  >*/
/* SOURCE culvertb.for:1188 */
/*<    86 format('  Initial loss for type 3 submergence=',1pe10.3) >*/
/* SOURCE culvertb.for:1189 */
/*<    88 format('  Final loss for type 3 submergence=',1pe10.3) >*/
/* SOURCE culvertb.for:1190 */
/*<    89  >*/
/* SOURCE culvertb.for:1193 */
/*<    90  >*/
/* *********************************************************************** */
/* SOURCE culvertb.for:1199 */
/*<       eflag=0 >*/
/* L50: */
/* L52: */
/* L54: */
/* L56: */
/* L60: */
/* L62: */
/* L64: */
/* L66: */
/* L68: */
/* L70: */
/* L72: */
/* L74: */
/* L76: */
/* L78: */
/* L80: */
/* L82: */
/* L84: */
/* L86: */
/* L88: */
/* L89: */
/* L90: */
    *eflag = 0;
/*     Find if type 1 flow even exists and if so find values */
/*     for type 1 at its limit. */
/* SOURCE culvertb.for:1203 */
/*<       callfscmat(stdout,adrxs2,szero,eflag,nscmat,yatmat,satmat) >*/
    fscmat_(stdout, &xs2com_1.adrxs2, &culcom_1.szero, eflag, &nscmat, yatmat,
	     satmat);
/* SOURCE culvertb.for:1207 */
/*<       y2lim=dup*ty1ytd >*/
    y2lim = static_cast<double>(*dup) * culcom_1.ty1ytd;
/* SOURCE culvertb.for:1208 */
/*<       if(nscmat.eq.0)then >*/
    if (nscmat == 0) {
/*       Type 1 flow does not exist for this culvert.  This should not */
/*       happen often because we are called from FRFT1. */
/* SOURCE culvertb.for:1211 */
/*<       cd1=-1.0 >*/
	xs3com_1.cd1 = (float)-1.;
/* SOURCE culvertb.for:1212 */
/*<       write(stdout,*)' Type 1 flow not possible.' >*/
	feq_gen_io_d__108.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__108);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Type 1 flow not possible."), (ftnlen)26);
	e_wsle();
/* SOURCE culvertb.for:1213 */
/*<       return >*/
	return 0;
/* SOURCE culvertb.for:1214 */
/*<       elseif(nscmat.lt.0)then >*/
    } else if (nscmat < 0) {
/*       The bottom slope is so large that any flow will be */
/*       type 1.  Set the depth at section 2 to the limit allowed */
/*       for type 1 flow. */
/* SOURCE culvertb.for:1218 */
/*<       yat2=y2lim >*/
	yat2 = y2lim;
/* SOURCE culvertb.for:1219 */
/*<       write(stdout,68)yat2 >*/
	feq_gen_io_d__110.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__110);
	do_fio(&feq_gen_c_d_1, (char *)&yat2, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culvertb.for:1220 */
/*<       else >*/
    } else {
/* SOURCE culvertb.for:1221 */
/*<       if(nscmat.gt.1)then >*/
	if (nscmat > 1) {
/*         More than one depth.  Assume the first one is the lower */
/*         limit for type 1 flow.  Find the value of elevation at section */
/*         1 for this limit to provide a basis for controlling computation */
/*         of type 2 flow at shallow depths. */
/* SOURCE culvertb.for:1226 */
/*<       yat2=yatmat(1) >*/
	    yat2 = yatmat[0];
/* SOURCE culvertb.for:1227 */
/*<       if(yat2.gt.y2lim)then >*/
	    if (yat2 > y2lim) {
/* SOURCE culvertb.for:1228 */
/*<       cd1=-1.0 >*/
		xs3com_1.cd1 = (float)-1.;
/* SOURCE culvertb.for:1229 */
/*<       write(stdout,89)y2lim >*/
		feq_gen_io_d__111.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__111);
		do_fio(&feq_gen_c_d_1, (char *)&y2lim, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE culvertb.for:1230 */
/*<       return >*/
		return 0;
/* SOURCE culvertb.for:1231 */
/*<       else >*/
	    } else {
/* SOURCE culvertb.for:1232 */
/*<       if(satmat(1).gt.0.0)then >*/
		if (satmat[0] > (float)0.) {
/*             Something wrong somewhere. */
/* SOURCE culvertb.for:1234 */
/*<        >*/
		    feq_gen_io_d__112.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__112);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* Inconsistent slope for "),
			     (ftnlen)34);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("lower critical slope in TY1BDY."), (
			    ftnlen)31);
		    e_wsle();
/* SOURCE culvertb.for:1236 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:1237 */
/*<       else >*/
		} else {
/* SOURCE culvertb.for:1238 */
/*<       callty1gy2(stdout,iu,id,dup,culcls,yat2,truea1,eflag) >*/
		    ty1gy2_(stdout, iu, id, dup, culcls, &yat2, truea1, eflag,
			     (ftnlen)8);
/* SOURCE culvertb.for:1241 */
/*<       if(eflag.eq.0)then >*/
		    if (*eflag == 0) {
/* SOURCE culvertb.for:1242 */
/*<       z1ty1l=z1l >*/
			xs1com_1.z1ty1l = typlim_1.z1l;
/* SOURCE culvertb.for:1243 */
/*<       write(stdout,72)z1ty1l >*/
			feq_gen_io_d__113.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__113);
			do_fio(&feq_gen_c_d_1, (char *)&xs1com_1.z1ty1l, (ftnlen)
				sizeof(real));
			e_wsfe();
/* SOURCE culvertb.for:1244 */
/*<       else >*/
		    } else {
/* SOURCE culvertb.for:1245 */
/*<       eflag=0 >*/
			*eflag = 0;
/* SOURCE culvertb.for:1246 */
/*<       write(stdout,74) >*/
			feq_gen_io_d__114.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__114);
			e_wsfe();
/* SOURCE culvertb.for:1247 */
/*<       endif >*/
		    }
/* SOURCE culvertb.for:1248 */
/*<       endif >*/
		}
/* SOURCE culvertb.for:1249 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:1250 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:1251 */
/*<       endif >*/
    }
/*     Take the maximum depth, check the slope */
/*     and then check against the maximum allowed. */
/* SOURCE culvertb.for:1254 */
/*<       yat2=yatmat(nscmat) >*/
    yat2 = yatmat[nscmat - 1];
/* SOURCE culvertb.for:1255 */
/*<       if(satmat(nscmat).lt.0.0)then >*/
    if (satmat[nscmat - 1] < (float)0.) {
/*       Something wrong somewhere. */
/* SOURCE culvertb.for:1257 */
/*<        >*/
	feq_gen_io_d__115.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__115);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* Inconsistent slope for critical"), (
		ftnlen)42);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" slope in TY1BDY."), (ftnlen)17);
	e_wsle();
/* SOURCE culvertb.for:1259 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:1260 */
/*<       else >*/
    } else {
/* SOURCE culvertb.for:1261 */
/*<       if(yat2.gt.y2lim)then >*/
	if (yat2 > y2lim) {
/*         The uppermost match with critical slope is above */
/*         the maximum depth permitted for type 1. */
/* SOURCE culvertb.for:1264 */
/*<       yat2=y2lim >*/
	    yat2 = y2lim;
/* SOURCE culvertb.for:1265 */
/*<       write(stdout,68)yat2 >*/
	    feq_gen_io_d__116.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__116);
	    do_fio(&feq_gen_c_d_1, (char *)&yat2, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culvertb.for:1266 */
/*<       else >*/
	} else {
/* SOURCE culvertb.for:1267 */
/*<       write(stdout,70)yat2 >*/
	    feq_gen_io_d__117.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__117);
	    do_fio(&feq_gen_c_d_1, (char *)&yat2, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culvertb.for:1268 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:1269 */
/*<       endif >*/
    }
/*     Find the type 1 conditions that apply when the depth at section */
/*     2 is given. */
/* SOURCE culvertb.for:1274 */
/*<       callty1gy2(stdout,iu,id,dup,culcls,yat2,truea1,eflag) >*/
    ty1gy2_(stdout, iu, id, dup, culcls, &yat2, truea1, eflag, (ftnlen)8);
/* SOURCE culvertb.for:1278 */
/*<       if(eflag.ne.0)then >*/
    if (*eflag != 0) {
/*       Invalid result. */
/* SOURCE culvertb.for:1280 */
/*<       write(stdout,78) >*/
	feq_gen_io_d__118.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__118);
	e_wsfe();
/* SOURCE culvertb.for:1281 */
/*<       return >*/
	return 0;
/* SOURCE culvertb.for:1282 */
/*<       endif >*/
    }
/*     Results are in section 1.  Check to make sure that the */
/*     limit on depth at section 2 does not lead to an elevation at */
/*     section 1 that exceeds the limit set there. */
/* SOURCE culvertb.for:1287 */
/*<       htd=(z1l-zb2)/dup >*/
    htd = static_cast<double>((static_cast<double>(typlim_1.z1l) - xs2com_1.zb2)) / *dup;
/* SOURCE culvertb.for:1288 */
/*<       if(htd.gt.ty1htd)then >*/
    if (htd > culcom_1.ty1htd) {
/*       The limit imposed at section 2 does exceed the limit imposed at */
/*       section 1 for type 1 flow.  Set the head at section 1 to its */
/*       limit and compute type 1 flow for that condition.  We cannot */
/*       use FRFT1 because we are called from FRFT1. */
/* SOURCE culvertb.for:1294 */
/*<       write(stdout,62)htd,ty1htd >*/
	feq_gen_io_d__120.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__120);
	do_fio(&feq_gen_c_d_1, (char *)&htd, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&culcom_1.ty1htd, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culvertb.for:1295 */
/*<       z1l=dup*ty1htd+zb2 >*/
	typlim_1.z1l = static_cast<double>(static_cast<double>(*dup) * culcom_1.ty1htd) + xs2com_1.zb2;
/* SOURCE culvertb.for:1296 */
/*<       y1l=z1l-zb1 >*/
	typlim_1.y1l = static_cast<double>(typlim_1.z1l) - xs1com_1.zb1;
/* SOURCE culvertb.for:1297 */
/*<       if(y1.lt.0.0)then >*/
	if (xs1com_1.y1 < (float)0.) {
/* SOURCE culvertb.for:1298 */
/*<       write(stdout,50)ty1htd,dup >*/
	    feq_gen_io_d__121.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__121);
	    do_fio(&feq_gen_c_d_1, (char *)&culcom_1.ty1htd, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&(*dup), (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culvertb.for:1299 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:1300 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:1301 */
/*<        >*/
	xlktal_(&xs1com_1.adrxs1, &typlim_1.y1l, &typlim_1.a1l, &typlim_1.t1l,
		 &typlim_1.dt1l, &typlim_1.j1l, &typlim_1.k1l, &typlim_1.dk1l,
		 &typlim_1.bet1l, &typlim_1.dbet1l, &typlim_1.alp1l, &
		typlim_1.dalp1l);
/*       Compute the free flow over the roadway. */
/* SOURCE culvertb.for:1308 */
/*<       callgetfrf(z1l,zsbrdf,fdrdw) >*/
	getfrf_(&typlim_1.z1l, &zsbrdf, &fdrdw);
/*       Set values in the common block for the type 1 residual function. */
/* SOURCE culvertb.for:1313 */
/*<       class1=culcls >*/
	s_copy(rty1cc_1.class1, culcls, (ftnlen)8, (ftnlen)8);
/* SOURCE culvertb.for:1314 */
/*<       du=dup >*/
	rty1c_1.du = *dup;
/* SOURCE culvertb.for:1315 */
/*<       ftype=1 >*/
	rty1c_1.ftype = 1;
/* SOURCE culvertb.for:1316 */
/*<       outun1=stdout >*/
	rty1c_1.outun1 = *stdout;
/* SOURCE culvertb.for:1318 */
/*<       ylow=0.0 >*/
	ylow = (float)0.;
/* SOURCE culvertb.for:1319 */
/*<       yhigh=0.0 >*/
	yhigh = (float)0.;
/* SOURCE culvertb.for:1320 */
/*<       y=yat2 >*/
	y = yat2;
/* SOURCE culvertb.for:1321 */
/*<       knt=0 >*/
	knt = 0;
/* SOURCE culvertb.for:1322 */
/*<   100 continue >*/
L100:
/* SOURCE culvertb.for:1323 */
/*<       f=ry2gy1(y) >*/
	f = ry2gy1_(&y);
/*          WRITE(STDOUT,*) ' TY1BDY: Y=',Y,' F=',F */
/* SOURCE culvertb.for:1325 */
/*<       knt=knt+1 >*/
	++knt;
/* SOURCE culvertb.for:1326 */
/*<       if(knt.gt.100)then >*/
	if (knt > 100) {
/* SOURCE culvertb.for:1327 */
/*<       write(stdout,66) >*/
	    feq_gen_io_d__129.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__129);
	    e_wsfe();
/* SOURCE culvertb.for:1328 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:1329 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:1330 */
/*<       if(abs(f).gt.epsabs)then >*/
	if (dabs(f) > epscom_1.epsabs) {
/*           Residual too large.  Seek a change in sign for the */
/*           residual function. */
/* SOURCE culvertb.for:1333 */
/*<       if(f.gt.0.0)then >*/
	    if (f > (float)0.) {
/* SOURCE culvertb.for:1334 */
/*<       yhigh=y >*/
		yhigh = y;
/* SOURCE culvertb.for:1335 */
/*<       fh=f >*/
		fh = f;
/* SOURCE culvertb.for:1336 */
/*<       if(ylow.eq.0.0)then >*/
		if (ylow == (float)0.) {
/*               Make depth at section 2 larger to find a negative */
/*               residual. */
/* SOURCE culvertb.for:1339 */
/*<       yt=1.05*y >*/
		    yt = static_cast<double>(y) * (float)1.05;
/* SOURCE culvertb.for:1340 */
/*<       if(yt.ge.dup)then >*/
		    if (yt >= *dup) {
/* SOURCE culvertb.for:1341 */
/*<       yt=0.5*(y+dup) >*/
			yt = static_cast<double>((static_cast<double>(y) + *dup)) * (float).5;
/* SOURCE culvertb.for:1342 */
/*<       if(dup-yt.le.epsabs)then >*/
			if (static_cast<double>(*dup) - yt <= epscom_1.epsabs) {
/* SOURCE culvertb.for:1343 */
/*<       write(stdout,52) >*/
			    feq_gen_io_d__132.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__132);
			    e_wsfe();
/* SOURCE culvertb.for:1344 */
/*<       stop'Abnormal stop. Errors found.' >*/
			    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28)
				    ;
/* SOURCE culvertb.for:1345 */
/*<       endif >*/
			}
/* SOURCE culvertb.for:1346 */
/*<       endif >*/
		    }
/* SOURCE culvertb.for:1347 */
/*<       y=yt >*/
		    y = yt;
/* SOURCE culvertb.for:1348 */
/*<       goto100 >*/
		    goto L100;
/* SOURCE culvertb.for:1349 */
/*<       endif >*/
		}
/* SOURCE culvertb.for:1350 */
/*<       else >*/
	    } else {
/* SOURCE culvertb.for:1351 */
/*<       ylow=y >*/
		ylow = y;
/* SOURCE culvertb.for:1352 */
/*<       fl=f >*/
		fl = f;
/* SOURCE culvertb.for:1353 */
/*<       if(yhigh.eq.0.0)then >*/
		if (yhigh == (float)0.) {
/*               Make depth at section 2 smaller to find a positive */
/*               residual. */
/* SOURCE culvertb.for:1356 */
/*<       y=0.95*y >*/
		    y *= static_cast<double>((float).95);
/* SOURCE culvertb.for:1357 */
/*<       if(y.le.epsabs)then >*/
		    if (y <= epscom_1.epsabs) {
/* SOURCE culvertb.for:1358 */
/*<       write(stdout,54) >*/
			feq_gen_io_d__134.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__134);
			e_wsfe();
/* SOURCE culvertb.for:1359 */
/*<       stop'Abnormal stop. Errors found.' >*/
			s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:1360 */
/*<       endif >*/
		    }
/* SOURCE culvertb.for:1361 */
/*<       goto100 >*/
		    goto L100;
/* SOURCE culvertb.for:1362 */
/*<       endif >*/
		}
/* SOURCE culvertb.for:1363 */
/*<       endif >*/
	    }
/*           We have a change in sign of the residual function here. */
/*           Find a root. */
/* SOURCE culvertb.for:1366 */
/*<       callregflt(epsarg,epsabs,ry2gy1,ylow,yhigh,fl,fh,y,flag) >*/
	    regflt_(&epscom_1.epsarg, &epscom_1.epsabs, ry2gy1_, &ylow, 
		    &yhigh, &fl, &fh, &y, &feq_gen_flag_d_);
/* SOURCE culvertb.for:1370 */
/*<       if(flag.eq.1)then >*/
	    if (feq_gen_flag_d_ == 1) {
/* SOURCE culvertb.for:1371 */
/*<       write(stdout,56) >*/
		feq_gen_io_d__136.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__136);
		e_wsfe();
/* SOURCE culvertb.for:1372 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:1373 */
/*<       elseif(flag.eq.2)then >*/
	    } else if (feq_gen_flag_d_ == 2) {
/* SOURCE culvertb.for:1374 */
/*<       write(stdout,60) >*/
		feq_gen_io_d__137.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__137);
		e_wsfe();
/* SOURCE culvertb.for:1375 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:1376 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:1377 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:1378 */
/*<       y2l=y >*/
	typlim_1.y2l = y;
/* SOURCE culvertb.for:1379 */
/*<       z2l=y2l+zb2 >*/
	typlim_1.z2l = static_cast<double>(typlim_1.y2l) + xs2com_1.zb2;
/* SOURCE culvertb.for:1380 */
/*<        >*/
	xlkt22_(&xs2com_1.adrxs2, &typlim_1.y2l, &typlim_1.a2l, &typlim_1.t2l,
		 &typlim_1.dt2l, &typlim_1.j2l, &typlim_1.k2l, &typlim_1.dk2l,
		 &typlim_1.bet2l, &typlim_1.dbet2l, &typlim_1.alp2l, &
		typlim_1.dalp2l, &q2lc);
/*       Find the submergence conditions at section 3.  Same method */
/*       as in FRFT1. */
/*       Find the depth at the first distance step using direct */
/*       integration to try to avoid continuing problems with */
/*       finding free drop for type 1 flow. */
/*        OFFSET = ABS(XVEC(IU+1) - XVEC(IU)) */
/*        SB = (ZBVEC(IU) - ZBVEC(IU+1))/OFFSET */
/*        FFAC = 1.0 - KD(IU+1) */
/*        CALL BEGSFP(NSEC(IU), FFAC, Y2L, Q2L, OFFSET, SB, YSTART) */

/*        WRITE(STDOUT,*) ' TY1GY2: OFFSET=',OFFSET,' YSTART=',YSTART, */
/*     A                  ' Y2=',Y2 */
/*        ZBEG = YSTART + ZBVEC(IU+1) */
/* SOURCE culvertb.for:1399 */
/*<       zbeg=z2l >*/
	zbeg = typlim_1.z2l;
/* SOURCE culvertb.for:1400 */
/*<       dh=0.0 >*/
	dh = (float)0.;
/* SOURCE culvertb.for:1401 */
/*<       callsfpty1(stdout,iu,id,dh,q2l,zbeg,is,zdn,flag) >*/
	sfpty1_(stdout, iu, id, &dh, &typlim_1.q2l, &zbeg, &is, &zdn, &feq_gen_flag_d_)
		;
/* SOURCE culvertb.for:1405 */
/*<       if(flag.eq.0)then >*/
	if (feq_gen_flag_d_ == 0) {
/* SOURCE culvertb.for:1406 */
/*<       write(stdout,*)' TY1BDY: Problem in SFPTY1 with DH=0.0' >*/
	    feq_gen_io_d__143.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__143);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" TY1BDY: Problem in SFPTY1 with DH=0.0"), (
		    ftnlen)38);
	    e_wsle();
/* SOURCE culvertb.for:1407 */
/*<       write(stdout,*)' ID=',id,' IS=',is >*/
	    feq_gen_io_d__144.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__144);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" ID="), (ftnlen)4);
	    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&(*id), (ftnlen)sizeof(integer));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" IS="), (ftnlen)4);
	    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&is, (ftnlen)sizeof(integer));
	    e_wsle();
/* SOURCE culvertb.for:1408 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:1409 */
/*<       else >*/
	} else {
/*         Now that we have an estimate of the conditions at section */
/*         3 when the critical control at section 2 is just being */
/*         submerged, estimate the type 3 losses that should take */
/*         place. */
/* SOURCE culvertb.for:1414 */
/*<       y3l=zdn-zb3 >*/
	    y3l = static_cast<double>(zdn) - xs3com_1.zb3;
/* SOURCE culvertb.for:1415 */
/*<       calllkta(adrxs3,y3l,avh) >*/
	    lkta_(&xs3com_1.adrxs3, &y3l, &cdcom_1.avh);
/*         Select the losses as in RQVSTW. */
/* SOURCE culvertb.for:1420 */
/*<       c123=fcd123(stdout,3,culcls,dup,z1l) >*/
	    cdcom_1.c123 = fcd123_(stdout, &feq_gen_c_d_3, culcls, dup, &typlim_1.z1l, 
		    (ftnlen)8);
/* SOURCE culvertb.for:1421 */
/*<       cd=degcon(c123,truea1,avh) >*/
	    cdcom_1.cd = degcon_(&cdcom_1.c123, truea1, &cdcom_1.avh);
/* SOURCE culvertb.for:1422 */
/*<       dh=(1.0/cd**2-1.0)*(q2l/avh)**2/grav2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = cdcom_1.cd;
/* Computing 2nd power */
	    feq_gen_r_d_2 = static_cast<double>(typlim_1.q2l) / cdcom_1.avh;
	    dh = static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - (float)1.)) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) / 
		    grvcom_1.grav2;
/* SOURCE culvertb.for:1423 */
/*<       write(stdout,86)dh >*/
	    feq_gen_io_d__146.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__146);
	    do_fio(&feq_gen_c_d_1, (char *)&dh, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culvertb.for:1424 */
/*<   200 continue >*/
L200:
/* SOURCE culvertb.for:1425 */
/*<       callsfpty1(stdout,iu,id,dh,q2l,zbeg,is,zdn,sflag) >*/
	    sfpty1_(stdout, iu, id, &dh, &typlim_1.q2l, &zbeg, &is, &zdn, &
		    sflag);
/* SOURCE culvertb.for:1428 */
/*<       if(sflag.eq.0)then >*/
	    if (sflag == 0) {
/*             If estimated losses cause computational problems, reduce */
/*             the losses and try again until the computations are */
/*             successful. */
/* SOURCE culvertb.for:1432 */
/*<       dh=0.9*dh >*/
		dh *= static_cast<double>((float).9);
/* SOURCE culvertb.for:1433 */
/*<       goto200 >*/
		goto L200;
/* SOURCE culvertb.for:1434 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:1435 */
/*<       write(stdout,88)dh >*/
	    feq_gen_io_d__148.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__148);
	    do_fio(&feq_gen_c_d_1, (char *)&dh, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culvertb.for:1437 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:1438 */
/*<       y3lty1=zdn-zb3 >*/
	xs3com_1.y3lty1 = static_cast<double>(zdn) - xs3com_1.zb3;
/* SOURCE culvertb.for:1439 */
/*<       else >*/
    } else {
/* SOURCE culvertb.for:1440 */
/*<       write(stdout,64)htd >*/
	feq_gen_io_d__149.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__149);
	do_fio(&feq_gen_c_d_1, (char *)&htd, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culvertb.for:1441 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:1443 */
/*<       z1ty1=z1l >*/
    xs1com_1.z1ty1 = typlim_1.z1l;
/* SOURCE culvertb.for:1444 */
/*<       cd1=cd >*/
    xs3com_1.cd1 = cdcom_1.cd;
/* SOURCE culvertb.for:1445 */
/*<       tp=min(y3lty1,ddn) >*/
    tp = dmin(xs3com_1.y3lty1,*ddn);
/* SOURCE culvertb.for:1446 */
/*<       calllkta(adrxs3,tp,a3part) >*/
    lkta_(&xs3com_1.adrxs3, &tp, &typlim_1.a3part);
/* SOURCE culvertb.for:1450 */
/*<       z3part=y3lty1+zb3 >*/
    typlim_1.z3part = static_cast<double>(xs3com_1.y3lty1) + xs3com_1.zb3;
/* SOURCE culvertb.for:1451 */
/*<       q3l=q2l >*/
    typlim_1.q3l = typlim_1.q2l;
/* SOURCE culvertb.for:1452 */
/*<       write(stdout,80)z1ty1l-zb1,z1ty1-zb1,y3lty1 >*/
    feq_gen_io_d__151.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__151);
    feq_gen_r_d_1 = static_cast<double>(xs1com_1.z1ty1l) - xs1com_1.zb1;
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
    feq_gen_r_d_2 = static_cast<double>(xs1com_1.z1ty1) - xs1com_1.zb1;
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.y3lty1, (ftnlen)sizeof(real));
    e_wsfe();
/*     Now we have finally established a limit for type 1 flow and */
/*     the conditions that exist at that limit.  Now try to */
/*     establish the values needed for the transition to type 5 or */
/*     type 6 flow. */
/* SOURCE culvertb.for:1460 */
/*<       if(htd.gt.1.0)then >*/
    if (htd > (float)1.) {
/*       Compute transition parameters only when head to opening */
/*       height ratio is greater than 1.0.  When the ratio is */
/*       small then type 2 is likely the predominant type and */
/*       its parameters will be used in the transition. */
/* SOURCE culvertb.for:1465 */
/*<       if(hhtype.eq.5)then >*/
	if (typlim_1.hhtype == 5) {
/*         High head type is type 5.  Compute parameters for */
/*         transition from type 1 to type 5.  Force the type 5 */
/*         flow equation to match the limiting type 1 flow by */
/*         computing a contraction coefficient for that purpose. */
/* SOURCE culvertb.for:1471 */
/*<       callfndcc2(stdout,dup,zbvec(iat3d),cc1t5) >*/
	    fndcc2_(stdout, dup, &culcom_1.zbvec[culcom_1.iat3d - 1], &
		    xs3com_1.cc1t5);
/*          WRITE(STDOUT,*) ' TY1BDY: CC1T5=',CC1T5 */
/*         Compute the profile to the end of the barrel */
/* SOURCE culvertb.for:1478 */
/*<       yvc=dup*yoverd(nsec(iat3d),dup,a2full,cc1t5) >*/
	    yvc = *dup * yoverd_(&culcom_1.nsec[culcom_1.iat3d - 1], dup, &
		    xs2com_1.a2full, &xs3com_1.cc1t5);
/* SOURCE culvertb.for:1480 */
/*<       ty6lss=((1.0/c46**2-1.0))*(q2l/a2full)**2/grav2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = cdcom_1.c46;
/* Computing 2nd power */
	    feq_gen_r_d_2 = static_cast<double>(typlim_1.q2l) / xs2com_1.a2full;
	    ty6lss = static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - (float)1.)) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) /
		     grvcom_1.grav2;
/* SOURCE culvertb.for:1482 */
/*<       calllktqc(nsec(iat3d),yvc,qc) >*/
	    lktqc_(&culcom_1.nsec[culcom_1.iat3d - 1], &yvc, &qc);
/*          WRITE(STDOUT,*) ' TY1BDY: DEPTH AT VC=',YVC,' FROUDE=',Q2L/QC */
/*         Estimate the critical depth. */
/* SOURCE culvertb.for:1488 */
/*<       ycat3=yvc >*/
	    ycat3 = yvc;
/* SOURCE culvertb.for:1489 */
/*<       callfndcde(stdout,adrxs3,q2l,ycat3) >*/
	    fndcde_(stdout, &xs3com_1.adrxs3, &typlim_1.q2l, &ycat3);
/*          WRITE(STDOUT,*) ' CRITICAL DEPTH AT SEC. 3=',YCAT3 */
/* SOURCE culvertb.for:1493 */
/*<        >*/
	    supsub_(stdout, &culcom_1.iat3d, id, &yvc, &xs3com_1.y3lty1, &
		    typlim_1.q2l, dup, &ycat3, &ty6lss, &zat3, &zat43, jmploc,
		     (ftnlen)32);
/*          WRITE(STDOUT,*) ' JMPLOC=',JMPLOC */
/* SOURCE culvertb.for:1499 */
/*<       z1ty51=z1ty1 >*/
	    xs1com_1.z1ty51 = xs1com_1.z1ty1;
/*          Y3LTY5 = DDN*TY5SBF */
/* SOURCE culvertb.for:1501 */
/*<       y3ty51=zat3-zb3 >*/
	    xs3com_1.y3ty51 = static_cast<double>(zat3) - xs3com_1.zb3;
/*         Compute a value of beta to apply to the type 5 equation */
/*         results that will closely match the type 1 equation */
/*         at the boundary between them. */
/* SOURCE culvertb.for:1506 */
/*<       calllkta(adrxs3,y3ty51,a) >*/
	    lkta_(&xs3com_1.adrxs3, &xs3com_1.y3ty51, &a);
/* SOURCE culvertb.for:1510 */
/*<       bt1t5=a/a3part >*/
	    xs3com_1.bt1t5 = static_cast<double>(a) / typlim_1.a3part;
/* SOURCE culvertb.for:1511 */
/*<       ap1t5=(a/a3part)**2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(a) / typlim_1.a3part;
	    xs3com_1.ap1t5 = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE culvertb.for:1512 */
/*<       write(stdout,82)cc1t5,bt1t5,ap1t5 >*/
	    feq_gen_io_d__160.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__160);
	    do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.cc1t5, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.bt1t5, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.ap1t5, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culvertb.for:1514 */
/*<       else >*/
	} else {
/*         Find parameters for transition from type 1 to type 6. */
/* SOURCE culvertb.for:1516 */
/*<        >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(typlim_1.q1l) / typlim_1.a1l;
/* Computing 2nd power */
	    feq_gen_r_d_2 = static_cast<double>(typlim_1.q3l) / xs3com_1.a3full;
/* Computing 2nd power */
	    feq_gen_r_d_3 = static_cast<double>(typlim_1.q2l) / xs2com_1.k2full;
/* Computing 2nd power */
	    feq_gen_r_d_4 = static_cast<double>(xs2com_1.a2full) / typlim_1.q2l;
	    tp = static_cast<double>((static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>(typlim_1.alp1l) - appcom_1.applos)) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / 
		    grvcom_1.grav2) + typlim_1.z1l) - (static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2) / 
		    grvcom_1.grav2) + typlim_1.z3part)) - static_cast<double>(culcom_1.l23) * (static_cast<double>(feq_gen_r_d_3) *
		     feq_gen_r_d_3)) - static_cast<double>(static_cast<double>(appcom_1.applen) * (static_cast<double>(typlim_1.q1l) * typlim_1.q2l)) /
		     (static_cast<double>(typlim_1.k1l) * xs2com_1.k2full))) * (static_cast<double>(grvcom_1.grav2) * (
		    static_cast<double>(feq_gen_r_d_4) * feq_gen_r_d_4));
/* SOURCE culvertb.for:1519 */
/*<       if(tp.lt.0.0)then >*/
	    if (tp < (float)0.) {
/*           Problem.  Cannot find a Cd that matches type 1 flow. */
/* SOURCE culvertb.for:1521 */
/*<       write(stdout,76) >*/
		feq_gen_io_d__161.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__161);
		e_wsfe();
/* SOURCE culvertb.for:1522 */
/*<       cd1t6=c46 >*/
		xs3com_1.cd1t6 = cdcom_1.c46;
/* SOURCE culvertb.for:1523 */
/*<       else >*/
	    } else {
/* SOURCE culvertb.for:1524 */
/*<       cd1t6=sqrt(1.0/(1.0+tp)) >*/
		xs3com_1.cd1t6 = sqrt(static_cast<double>((float)1.) / (static_cast<double>(tp) + (float)1.));
/* SOURCE culvertb.for:1525 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:1526 */
/*<       bt1t6=a3full/a3part >*/
	    xs3com_1.bt1t6 = static_cast<double>(xs3com_1.a3full) / typlim_1.a3part;
/* SOURCE culvertb.for:1527 */
/*<       ap1t6=(bt1t6)**2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = xs3com_1.bt1t6;
	    xs3com_1.ap1t6 = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE culvertb.for:1528 */
/*<       write(stdout,84)cd1t6,bt1t6,ap1t6 >*/
	    feq_gen_io_d__162.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__162);
	    do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.cd1t6, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.bt1t6, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.ap1t6, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culvertb.for:1530 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:1531 */
/*<       else >*/
    } else {
/*       CULVERT has computed the free-flow limits for type 1 flow.  However, the */
/*       limiting condition for the water-surface elevation at section 1 is such that */
/*       the ratio of approach head to vertical diameter is < 1.0! */
/* SOURCE culvertb.for:1535 */
/*<       write(stdout,90) >*/
	feq_gen_io_d__163.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__163);
	e_wsfe();
/* SOURCE culvertb.for:1537 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:1538 */
/*<       return >*/
    return 0;
/* SOURCE culvertb.for:1539 */
/*<       end >*/
} /* ty1bdy_ */




/* SOURCE culvertb.for:1543 */
/*<        >*/
/* Subroutine */ int frft1_(integer *stdout, real *hdatum, real *hup, real *
	dup, real *ddn, integer *iu, integer *id, char *culcls, real *truea1, 
	integer *eflag, real *fg, integer *feq_gen_type_d_, integer *conflg, integer *
	expflg, real *qfree, real *freed, ftnlen culcls_len)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *BUG:XXX* SIGN CHNG ON ENTRY BUT REGFLT CL\
AIMS NONE IN\002,\002 FRFT1.\002)";
    static char fmt_56[] = "(\002 *WRN:539* NO ROOT FOR TYPE 1 FLOW. TRYING \
TYPE 2.\002)";
    static char fmt_60[] = "(\002 *BUG:XXX* REGFLT: MORE THAN 100 ITERATIONS\
 IN FRFT1.\002)";
    static char fmt_62[] = "(/,\002 Type 1 rejected.\002,/,\002  Normal flow\
 in barrel at critical\002,\002 depth=\002,f8.2,\002 <  critical flow=\002,f\
8.2)";
    static char fmt_64[] = "(/,\002 Type 1 accepted.\002,/,\002  Normal flow\
 in barrel at critical\002,\002 depth=\002,f8.2,\002 > critical flow=\002,f8\
.2)";
    static char fmt_66[] = "(/,\002 *WRN:579* Type 1 flow drowned assuming f\
low is type\002,\002 2.\002,/,11x,\002 Slope reduction in culvert barrel.\
\002)";
    static char fmt_68[] = "(/,\002 *BUG:XXX* FRFT1: Type 2 flow successful \
when it\002,\002 should be impossible. \002,/,5x,\002 Barrel slope at entran\
ce=\002,f10.4,\002 Barrel slope at exit=\002,f10.4)";
    static char fmt_70[] = "(/,\002 *WRN:589* Flows are within 1 per cent.  \
Unavoidable\002,\002 convergence differences\002,/,11x,\002may cause CULVERT\
 to make\002,\002 the wrong branch and fail.  If this\002,/,11x,\002occurs c\
hange\002,\002 the upstream head to avoid the near flow match.\002)";
    static char fmt_72[] = "(\002  Initial loss for type 3 submergence=\002,\
1pe10.3)";
    static char fmt_74[] = "(\002  Final loss for type 3 submergence=\002,1p\
e10.3)";

    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal);
    integer do_fio(integer *, char *, ftnlen);

    /* Local variables */
    real f, dh, fh, fl, sb;
    integer is;
    real qn, ye, tp, yl, yr, fac, sbe;
    integer isb;
    real frh, frl, zup;
    extern doublereal rty1_(real *);
    integer feq_gen_flag_d_;
    real yarg, zbeg;
    extern doublereal fcd123_(integer *, integer *, char *, real *, real *, 
	    ftnlen);
    extern /* Subroutine */ int dpm26_(integer *, real *, real *, real *, 
	    integer *), lktj_(integer *, real *, real *);
    real ylow;
    integer sflag;
    real fdrdw, yhigh;
    extern /* Subroutine */ int ty1bdy_(integer *, real *, real *, integer *, 
	    integer *, char *, real *, integer *, ftnlen), fndcde_(integer *, 
	    integer *, real *, real *), sfpty1_(integer *, integer *, integer 
	    *, real *, real *, real *, integer *, real *, integer *);
    extern doublereal degcon_(real *, real *, real *);
    real zsbrdf;
    extern /* Subroutine */ int getfrf_(real *, real *, real *), regflt_(real 
	    *, real *, FeqCallback3, real *, real *, real *, real *, real *, integer *
	    ), sfpsbe_(integer *, integer *, integer *, real *, real *, real *
	    , integer *, real *, integer *), xlktal_(integer *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__166 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__167 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__177 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__178 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__180 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__181 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__182 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__183 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__186 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__187 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__188 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__189 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__196 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__197 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__202 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__204 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__205 = { 0, 0, 0, fmt_74, 0 };


/*     + + + PURPOSE + + + */
/*     Compute flow type 1 for the given upstream head, HUP, and */
/*     the approach and hydraulic data are given in the */
/*     labelled common blocks. */
/*     FG gives the first guess of the depth for type 2 if */
/*     it follows. */
/* SOURCE culvertb.for:1555 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertb.for:1558 */
/*<       integerconflg,eflag,expflg,id,iu,stdout,type >*/
/* SOURCE culvertb.for:1559 */
/*<       realddn,dup,fg,freed,hdatum,hup,qfree,truea1 >*/
/* SOURCE culvertb.for:1560 */
/*<       characterculcls*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     HDATUM - Datum for measuring head */
/*     HUP    - Head upstream */
/*     DUP    - vertical diameter of culvert barrel at upstream end */
/*     DDN    - vertical diameter of culvert barrel at downstream end */
/*     IU     - Index for upstream node for the culvert barrel */
/*     ID     - Index for the downstream node for the culvert barrel */
/*     CULCLS - Class for culvert shape, BOX, PIPE, .. */
/*     TRUEA1 - area at section 1 */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     FG     - First guess */
/*     TYPE   - Culvert flow type */
/*     CONFLG - CONFLG=0: flow contracts as it enters the culvert and */
/*              CONFLG=1: flow expands as it enters the culver */
/*     EXPFLG - Expansion flag.  EXPFLG=1 if flow expands on exit */
/*              and EXPFLG=0 if flow does not expand on exit */
/*     QFREE  - Free flow */
/*     FREED  - Free drop */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertb.for:1583 */
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
/* INCLUDE culvertb.for:1584 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertb.for:1585 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE culvertb.for:1586 */
/* SOURCE cdcom.cmn:2 */
/*<        >*/
/* SOURCE cdcom.cmn:10 */
/*<        >*/
/* SOURCE cdcom.cmn:14 */
/*<        >*/
/*     Add values for support of FHWA type 5 scheme. Oct. 3, 2001 */
/* SOURCE cdcom.cmn:20 */
/*<       realafhwa,cfhwa,yfhwa,sfhwa >*/
/*     AFHWA - value of a */
/*     CFHWA - value of c */
/*     YFHWA - value of Y */
/*     SFHWA - slope of culvert near entrance. */
/* INCLUDE culvertb.for:1587 */
/* SOURCE xs1com.cmn:2 */
/*<        >*/
/* SOURCE xs1com.cmn:7 */
/*<       integeradrxs1 >*/
/* SOURCE xs1com.cmn:9 */
/*<        >*/
/*     Z1TY1- elevation at section 1 at type 1 limit if it exists */
/*     Z1TY1L-elevation at section 1 at lower limit of type 1 if it exists */
/*     Z1TY6- elevation at section 1 at start of type 6 if it exists */
/*     Z1TY2- elevation at upper limit of type 2 flow if it exists */
/*     Z1TY61- elevation at upper limt of type 61 if it exists */
/*     Z1TY5- elevation at section at start of type 5 if it exists */
/*     Z1TY52- elevation at section 1 at lower limit of type 52( */
/*             type 2 to type 5 flow) */
/*     Z1TY51- elevation at section 1 at lower limit of type 51( */
/*             type 1 to type 5 flow) */
/* INCLUDE culvertb.for:1588 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culvertb.for:1589 */
/* SOURCE xs3com.cmn:2 */
/*<        >*/
/* SOURCE xs3com.cmn:11 */
/*<       integeradrxs3 >*/
/* SOURCE xs3com.cmn:13 */
/*<        >*/
/*     CD1- if 0.0 type 1 flow has not been checked, if > 0 type 1 */
/*          flow has been checked and found to exist and its limit */
/*          values have been found, if < 0 type 1 flow does not exist. */
/*     CD2T6- coef. of discharge forcing full flow to match flow */
/*            at the type 2 flow limit. */
/*     AP2T6 - kinetic energy flux coefficient forcing the full */
/*             flow kinetic energy flux to match the flux */
/*             at the type 2 limit. */
/*     BT2T6- momentum flux coefficient forcing the full flow */
/*            momentum flux to match the flux at the type 2 limit. */
/*     CD61T6- coef. of discharge forcing full flow to match flow */
/*             at the type 61 limit. */
/*     CD1T6- coef. of discharge forcing full flow to match flow */
/*            at the type 1 limit */

/*     AP61T6- same as AP2T6 for type 61. */
/*     BT61T6- same as AP2T6 for type 61. */
/*     CD2- coef. of discharge for type 2 flow at the type 2 limit. */
/*     CD61- coef. of discharge for type 61 flow at the type 61 limit. */
/*     CD6- coef. of discharge for type 6 flow. */
/*     Z3PTY6- piezometric level at section 3 at the type 6 limit. */
/*     AVH2- area for velocity head at the type 2 limit. */
/*     AVH61- area for velocity head at the type 61 limit. */
/*     BT3ATD- beta at section 3 when barrel is full(at D!) */
/*     AP3ATD- alpha at section 3 when the barrel is full(at D!) */
/*     CC2T5 - contraction coefficient for type 5 at the type 2 flow */
/*             limit. */
/*     CC1T5 - contraction coefficient for type 5 at the type 1 flow */
/*             limit. */
/*     CC5- contraction coefficient for type 5 at its lower limit */
/*          and above. */
/*     Y3TY52- depth at section 3 at the lower limit of type 52 flow */
/*             giving the transistion between type 2 and type 5. */
/*     Y3TY51- depth at section 3 at the lower limit of type 51 flow */
/*             giving the transistion between type 1 and type 5. */
/*     BT2T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 52 and */
/*             upper limit of type 2. */
/*     BT1T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 51 and */
/*             upper limit of type 1. */
/*     AP2T5-  alpha analogous to BT2T5 */
/*     AP1T5-  alpha analogous to BT1T5 */
/*     Y3TY5-  depth at section 3 at the lower limit of type 5 flow */
/*     BT3AT5- beta for type 5 flow limit */
/*     AP3AT5- alpha for type 5 flow limit */
/*     CD5T4- coefficient of discharge that forces a type 4 equation */
/*            to match the type 5, 51, or 52 flow at the full-flow- */
/*            inducing level at section 43. */
/*     Y3LTY2- depth at section 3 at the type 2 limit, that is, */
/*             critical depth. */
/*     Y3LTY1- submergence depth at section 3  at the limit of */
/*             type 1 flow. */
/*     Y3LTY5- the full-flow-inducing value of piezometric level */
/*             relative to the invert at section 3 for flow types */
/*             5, 51, and 52. */
/* INCLUDE culvertb.for:1590 */
/* SOURCE xs4com.cmn:2 */
/*<        >*/
/* SOURCE xs4com.cmn:5 */
/*<       integeradrxs4 >*/
/* SOURCE xs4com.cmn:7 */
/*<        >*/
/* INCLUDE culvertb.for:1591 */
/* SOURCE culcom.cmn:2 */
/*<        >*/
/* SOURCE culcom.cmn:8 */
/*<       integernsec(mnbn),hltab(mnbn),iat3d,iat6d,sbkind,sbshape >*/
/* SOURCE culcom.cmn:10 */
/*<        >*/
/* SOURCE culcom.cmn:16 */
/*<       doubleprecisionfrcfac >*/
/*     FRCFAC- friction factor to give factor for friction losses */
/*             in barrel for non-prismatic full-flow that as well */
/*             as prismatic full flow. */
/*     TY1YTD- maximum ratio of depth to vertical diameter for */
/*             type 1 flow. */
/*     TY1HTD- maximum ratio of head at section 1 relative to */
/*             culvert invert at culvert inlet to the vertical */
/*             diamter of the culvert.  Must be less than 1.5. */
/*     SBKIND- if 0 the slope of the culvert barrel is a constant, */
/*             if 1 the slope of the culvert barrel varies. */
/*     BSHAPE- if 0 the barrel shape is constant, that is, prismatic, */
/*             if 1 the barrel shape is nonprismatic. */
/*     TY5SBF- ratio of depth to vertical diameter of the culvert */
/*             at the exit which causes submergence. */
/* Note:  25 August 2004:  SBSHAPE is apparently not used.  BSHAPE */
/* is but outside of a common block. */
/* INCLUDE culvertb.for:1592 */
/* SOURCE rdfcom.cmn:2 */
/*<       common/rdfcom/wfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/* SOURCE rdfcom.cmn:4 */
/*<       realwfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/*     WFRDF-WATER FLUX OVER ROAD FREE CONDITION. */
/*     MFRDF-MOMENTUM FLUX OVER THE ROAD FREE CONDITION. */
/*     EFRDF-ENERGY FLUX OVER THE ROAD FREE CONDITION. */
/*     WFRD- WATER FLUX OVER THE ROAD ANY CONDITION. */
/*     MFRD- MOMENTUM FLUX OVER THE ROAD ANY CONDITION. */
/*     EFRD- ENERGY FLUX OVER THE ROAD ANY CONDITION. */
/* INCLUDE culvertb.for:1593 */
/*     Common block for various parameters to handle transitional */
/*     flow type behavior for the departure reach computations. */
/* SOURCE typtrn.cmn:4 */
/*<       common/typtrn/avhf,cdf,betaf,alphaf,y3pf,beta3,alpha3 >*/
/* SOURCE typtrn.cmn:6 */
/*<       realavhf,cdf,betaf,alphaf,y3pf,beta3,alpha3 >*/
/*     AVHF- area used for velocity head in computing losses for the */
/*           transitional free flow */
/*     CDF- coef. of discharge for computing losses for the transitional */
/*          free flow. */
/*     BETAF- value of beta to compensate for false area in the computation */
/*            of the momentum flux from some free flows.  If this */
/*            value is zero it means that the beta from the cross section */
/*            function table should be used.  If it is non-zero it means */
/*            that the free flow type was used as a transition and that */
/*            the flow area of the culvert barrel outlet was falsified in */
/*            the process. */
/*     ALPHAF- value of alpha to use in computing velocity head for */
/*             energy loss computations. */
/*     Y3PF- depth to the piezometric level at the culvert barrel outlet */
/*           for free flow limit. */
/*     BETA3- actual value at section 3 used in departure reach */
/*     ALPHA3- actual value at section 3.  Crudely estimated in some */
/*             cases because better alternative is not available. */
/* INCLUDE culvertb.for:1594 */
/*     Common to hold values needed for computing various limits */
/*     for culvert flow types. */
/* SOURCE typlim.cmn:4 */
/*<        >*/
/* SOURCE typlim.cmn:10 */
/*<       integerhhtype >*/
/* SOURCE typlim.cmn:12 */
/*<        >*/
/* INCLUDE culvertb.for:1595 */
/*     Common for function RTY1 in FEQUTL */
/* SOURCE rty1c.cmn:3 */
/*<       common/rty1c/du,ftype,outun1,frsq,dhty1 >*/
/* SOURCE rty1c.cmn:4 */
/*<       character*8class1 >*/
/* SOURCE rty1c.cmn:5 */
/*<       integerftype,outun1 >*/
/* SOURCE rty1c.cmn:6 */
/*<       realdu,frsq,dhty1 >*/
/* SOURCE rty1c.cmn:8 */
/*<       common/rty1cc/class1 >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertb.for:1598 */
/*<       integerflag,is,isb,sflag >*/
/* SOURCE culvertb.for:1599 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertb.for:1603 */
/*<       intrinsicabs,min,sqrt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertb.for:1606 */
/*<       realdegcon,fcd123,rty1 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertb.for:1609 */
/*<        >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertb.for:1613 */
/*<    50  >*/
/* SOURCE culvertb.for:1615 */
/*<    56 format(' *WRN:539* NO ROOT FOR TYPE 1 FLOW. TRYING TYPE 2.') >*/
/* SOURCE culvertb.for:1616 */
/*<    60 format(' *BUG:XXX* REGFLT: MORE THAN 100 ITERATIONS IN FRFT1.') >*/
/* SOURCE culvertb.for:1617 */
/*<    62  >*/
/* SOURCE culvertb.for:1620 */
/*<    64  >*/
/* SOURCE culvertb.for:1623 */
/*<    66  >*/
/* SOURCE culvertb.for:1625 */
/*<    68  >*/
/* SOURCE culvertb.for:1628 */
/*<    70  >*/
/* SOURCE culvertb.for:1632 */
/*<    72 format('  Initial loss for type 3 submergence=',1pe10.3) >*/
/* SOURCE culvertb.for:1633 */
/*<    74 format('  Final loss for type 3 submergence=',1pe10.3) >*/
/* *********************************************************************** */
/* SOURCE culvertb.for:1635 */
/*<       betaf=0.0 >*/
/* L50: */
/* L56: */
/* L60: */
/* L62: */
/* L64: */
/* L66: */
/* L68: */
/* L70: */
/* L72: */
/* L74: */
    typtrn_1.betaf = (float)0.;
/* SOURCE culvertb.for:1636 */
/*<       beta3=0.0 >*/
    typtrn_1.beta3 = (float)0.;
/* SOURCE culvertb.for:1637 */
/*<       alpha3=0.0 >*/
    typtrn_1.alpha3 = (float)0.;
/*      write(stdout,*) 'TY1BDY: CD1=',cd1 */
/* SOURCE culvertb.for:1639 */
/*<       if(cd1.eq.0.0)then >*/
    if (xs3com_1.cd1 == (float)0.) {
/*       Type 1 limit not set yet.  Try to find it. */
/* SOURCE culvertb.for:1641 */
/*<       callty1bdy(stdout,dup,ddn,iu,id,culcls,truea1,eflag) >*/
	ty1bdy_(stdout, dup, ddn, iu, id, culcls, truea1, eflag, (ftnlen)8);
/*       Recompute flow over the roadway because TY1BDY may have */
/*       computed it for a different upstream head. */
/* SOURCE culvertb.for:1647 */
/*<       callgetfrf(hup+hdatum,zsbrdf,fdrdw) >*/
	feq_gen_r_d_1 = static_cast<double>(*hup) + *hdatum;
	getfrf_(&feq_gen_r_d_1, &zsbrdf, &fdrdw);
/* SOURCE culvertb.for:1651 */
/*<       if(cd1.lt.0.0)then >*/
	if (xs3com_1.cd1 < (float)0.) {
/* SOURCE culvertb.for:1652 */
/*<       type=2 >*/
	    *feq_gen_type_d_ = 2;
/* SOURCE culvertb.for:1653 */
/*<       fg=0.0 >*/
	    *fg = (float)0.;
/* SOURCE culvertb.for:1654 */
/*<       return >*/
	    return 0;
/* SOURCE culvertb.for:1655 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:1656 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:1657 */
/*<       if(hup+hdatum.gt.z1ty1)then >*/
    if (static_cast<double>(*hup) + *hdatum > xs1com_1.z1ty1) {
/*        WRITE(STDOUT,*) ' FRFT1: Limit elevation=',Z1TY1,' exceeded.' */
/*        WRITE(STDOUT,*) ' Current elevation=',HUP + HDATUM */
/* SOURCE culvertb.for:1660 */
/*<       if(cd2.gt.0.0)then >*/
	if (xs3com_1.cd2 > (float)0.) {
/* SOURCE culvertb.for:1661 */
/*<       if(hup+hdatum.gt.z1ty2)then >*/
	    if (static_cast<double>(*hup) + *hdatum > xs1com_1.z1ty2) {
/* SOURCE culvertb.for:1662 */
/*<       if(hhtype.eq.5)then >*/
		if (typlim_1.hhtype == 5) {
/* SOURCE culvertb.for:1663 */
/*<       type=5 >*/
		    *feq_gen_type_d_ = 5;
/* SOURCE culvertb.for:1664 */
/*<       else >*/
		} else {
/* SOURCE culvertb.for:1665 */
/*<       type=6 >*/
		    *feq_gen_type_d_ = 6;
/* SOURCE culvertb.for:1666 */
/*<       endif >*/
		}
/* SOURCE culvertb.for:1667 */
/*<       else >*/
	    } else {
/* SOURCE culvertb.for:1668 */
/*<       type=2 >*/
		*feq_gen_type_d_ = 2;
/* SOURCE culvertb.for:1669 */
/*<       if(z1ty2.gt.zb1)then >*/
		if (xs1com_1.z1ty2 > xs1com_1.zb1) {
/*             We have a type 1 limit that  has a type 2 flow above it. */
/*             This means that the type 1 limit is critical flow over the */
/*             length of the culvert.   Thus the submergence level for */
/*             type 1 flow at this limit is critical depth.  In this case */
/*             the value of Y3LTY1 is critical depth.   Start the */
/*             process at a slightly higher depth. */
/* SOURCE culvertb.for:1676 */
/*<       write(stdout,*)' Y3LTY1=',y3lty1 >*/
		    feq_gen_io_d__166.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__166);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Y3LTY1="), (ftnlen)8);
		    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&xs3com_1.y3lty1, (ftnlen)
			    sizeof(real));
		    e_wsle();
/* SOURCE culvertb.for:1677 */
/*<       fg=y3lty1+0.1*(hup+hdatum-z1ty2) >*/
		    *fg = static_cast<double>(xs3com_1.y3lty1) + static_cast<double>((static_cast<double>(static_cast<double>(*hup) + *hdatum) - xs1com_1.z1ty2)) 
			    * (float).1;
/* SOURCE culvertb.for:1678 */
/*<       else >*/
		} else {
/* SOURCE culvertb.for:1679 */
/*<       fg=0.0 >*/
		    *fg = (float)0.;
/* SOURCE culvertb.for:1680 */
/*<       endif >*/
		}
/* SOURCE culvertb.for:1681 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:1682 */
/*<       else >*/
	} else {
/*         We have not tried type 2 yet.  Do so to check on the */
/*         type 2 limit. */
/* SOURCE culvertb.for:1685 */
/*<       write(stdout,*)' FRFT1: Trying to find type 2 limit.' >*/
	    feq_gen_io_d__167.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__167);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FRFT1: Trying to find type 2 limit."), (
		    ftnlen)36);
	    e_wsle();
/* SOURCE culvertb.for:1686 */
/*<       type=2 >*/
	    *feq_gen_type_d_ = 2;
/* SOURCE culvertb.for:1687 */
/*<       fg=y3lty1*1.01 >*/
	    *fg = static_cast<double>(xs3com_1.y3lty1) * (float)1.01;
/* SOURCE culvertb.for:1688 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:1689 */
/*<       return >*/
	return 0;
/* SOURCE culvertb.for:1690 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' FRFT1: Z1=',Z1 */
/* SOURCE culvertb.for:1692 */
/*<       class1=culcls >*/
    s_copy(rty1cc_1.class1, culcls, (ftnlen)8, (ftnlen)8);
/* SOURCE culvertb.for:1693 */
/*<       du=dup >*/
    rty1c_1.du = *dup;
/* SOURCE culvertb.for:1694 */
/*<       ftype=1 >*/
    rty1c_1.ftype = 1;
/* SOURCE culvertb.for:1695 */
/*<       conflg=1 >*/
    *conflg = 1;
/* SOURCE culvertb.for:1696 */
/*<       outun1=stdout >*/
    rty1c_1.outun1 = *stdout;
/* SOURCE culvertb.for:1698 */
/*<       y3free=0.0 >*/
    xs3com_1.y3free = (float)0.;
/* SOURCE culvertb.for:1699 */
/*<       y2free=0.0 >*/
    xs2com_1.y2free = (float)0.;
/* SOURCE culvertb.for:1700 */
/*<       q3free=0.0 >*/
    xs3com_1.q3free = (float)0.;
/*     FIND AN INTERVAL CONTAINING A ROOT. */
/* SOURCE culvertb.for:1703 */
/*<       fac=0.01 >*/
    fac = (float).01;
/* SOURCE culvertb.for:1704 */
/*<       yhigh=0.0 >*/
    yhigh = (float)0.;
/* SOURCE culvertb.for:1705 */
/*<       ylow=0.0 >*/
    ylow = (float)0.;
/* SOURCE culvertb.for:1707 */
/*<       frl=-1.0 >*/
    frl = (float)-1.;
/* SOURCE culvertb.for:1708 */
/*<       frh=-1.0 >*/
    frh = (float)-1.;
/* SOURCE culvertb.for:1709 */
/*<   100 continue >*/
L100:
/* SOURCE culvertb.for:1710 */
/*<       yarg=fac*(z1-zb2) >*/
    yarg = static_cast<double>(fac) * (static_cast<double>(xs1com_1.z1) - xs2com_1.zb2);
/* SOURCE culvertb.for:1711 */
/*<       f=rty1(yarg) >*/
    f = rty1_(&yarg);
/* SOURCE culvertb.for:1712 */
/*<       if(f.le.0.0)then >*/
    if (f <= (float)0.) {
/* SOURCE culvertb.for:1713 */
/*<       ylow=yarg >*/
	ylow = yarg;
/* SOURCE culvertb.for:1714 */
/*<       fl=f >*/
	fl = f;
/* SOURCE culvertb.for:1715 */
/*<       frl=frsq >*/
	frl = rty1c_1.frsq;
/* SOURCE culvertb.for:1716 */
/*<       else >*/
    } else {
/* SOURCE culvertb.for:1717 */
/*<       yhigh=yarg >*/
	yhigh = yarg;
/* SOURCE culvertb.for:1718 */
/*<       fh=f >*/
	fh = f;
/* SOURCE culvertb.for:1719 */
/*<       frh=frsq >*/
	frh = rty1c_1.frsq;
/* SOURCE culvertb.for:1720 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:1721 */
/*<       if(yhigh.eq.0.0.or.ylow.eq.0.0)then >*/
    if (yhigh == (float)0. || ylow == (float)0.) {
/* SOURCE culvertb.for:1722 */
/*<       fac=1.1*fac >*/
	fac *= static_cast<double>((float)1.1);
/* SOURCE culvertb.for:1723 */
/*<       if(fac.ge.1.0)then >*/
	if (fac >= (float)1.) {
/*           TRY TYPE 2 */
/* SOURCE culvertb.for:1725 */
/*<       write(stdout,56) >*/
	    feq_gen_io_d__177.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__177);
	    e_wsfe();
/* SOURCE culvertb.for:1726 */
/*<       freed=0.0 >*/
	    *freed = (float)0.;
/* SOURCE culvertb.for:1727 */
/*<       qfree=q2 >*/
	    *qfree = xs2com_1.q2;
/* SOURCE culvertb.for:1728 */
/*<       type=2 >*/
	    *feq_gen_type_d_ = 2;
/* SOURCE culvertb.for:1729 */
/*<       fg=0.0 >*/
	    *fg = (float)0.;
/* SOURCE culvertb.for:1730 */
/*<       return >*/
	    return 0;
/* SOURCE culvertb.for:1731 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:1732 */
/*<       if(frl.gt.0.0.and.frh.gt.0.0)then >*/
	if (frl > (float)0. && frh > (float)0.) {
/* SOURCE culvertb.for:1733 */
/*<       if(min(frl,frh).gt.2.0)then >*/
	    if (dmin(frl,frh) > (float)2.) {
/*             ASSUME NO SUBCRITICAL SOLUTION EXISTS */
/* SOURCE culvertb.for:1735 */
/*<        >*/
		feq_gen_io_d__178.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__178);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Type 1 rejected while seeking root. "), 
			(ftnlen)37);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Minimum FRSQ="), (ftnlen)14);
		feq_gen_r_d_1 = dmin(frl,frh);
		do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		e_wsle();
/* SOURCE culvertb.for:1737 */
/*<       type=2 >*/
		*feq_gen_type_d_ = 2;
/* SOURCE culvertb.for:1738 */
/*<       freed=0.0 >*/
		*freed = (float)0.;
/* SOURCE culvertb.for:1739 */
/*<       qfree=q2 >*/
		*qfree = xs2com_1.q2;
/* SOURCE culvertb.for:1740 */
/*<       fg=0.0 >*/
		*fg = (float)0.;
/* SOURCE culvertb.for:1741 */
/*<       return >*/
		return 0;
/* SOURCE culvertb.for:1742 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:1743 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:1744 */
/*<       goto100 >*/
	goto L100;
/* SOURCE culvertb.for:1745 */
/*<       endif >*/
    }
/*     AT THIS POINT WE HAVE A SIGN CHANGE IN THE RESIDUAL.  FIND THE */
/*     ROOT IN THE INTERVAL. CHECK THE FROUDE NUMBER IN THE APPROACH */
/*     SECTION. */
/* SOURCE culvertb.for:1751 */
/*<       callregflt(epsarg,epsabs,rty1,ylow,yhigh,fl,fh,y2,flag) >*/
    regflt_(&epscom_1.epsarg, &epscom_1.epsabs, rty1_, &ylow, &yhigh, &
	    fl, &fh, &xs2com_1.y2, &feq_gen_flag_d_);
/* SOURCE culvertb.for:1755 */
/*<       if(flag.eq.1)then >*/
    if (feq_gen_flag_d_ == 1) {
/* SOURCE culvertb.for:1756 */
/*<       write(stdout,50) >*/
	feq_gen_io_d__180.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__180);
	e_wsfe();
/* SOURCE culvertb.for:1757 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:1758 */
/*<       elseif(flag.eq.2)then >*/
    } else if (feq_gen_flag_d_ == 2) {
/* SOURCE culvertb.for:1759 */
/*<       write(stdout,60) >*/
	feq_gen_io_d__181.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__181);
	e_wsfe();
/* SOURCE culvertb.for:1760 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:1761 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:1762 */
/*<       if(abs(fl).gt.epsdif)then >*/
    if (dabs(fl) > epscom_1.epsdif) {
/* SOURCE culvertb.for:1763 */
/*<        >*/
	feq_gen_io_d__182.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__182);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Flow type 1 residual at convergence="), (ftnlen)
		37);
	feq_gen_r_d_1 = dabs(fl);
	do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" > "), (ftnlen)3);
	do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&epscom_1.epsdif, (ftnlen)sizeof(real));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("  Result may be invalid."), (ftnlen)24);
	e_wsle();
/* SOURCE culvertb.for:1765 */
/*<       endif >*/
    }
/*     THE FINAL VALUES ARE IN XS2COM VARIABLES */
/* SOURCE culvertb.for:1768 */
/*<       qfree=q2 >*/
    *qfree = xs2com_1.q2;
/* SOURCE culvertb.for:1769 */
/*<       z2=zb2+y2 >*/
    xs2com_1.z2 = static_cast<double>(xs2com_1.zb2) + xs2com_1.y2;
/* SOURCE culvertb.for:1770 */
/*<       fg=y2 >*/
    *fg = xs2com_1.y2;
/* SOURCE culvertb.for:1771 */
/*<       y2ty1=y2 >*/
    xs2com_1.y2ty1 = xs2com_1.y2;
/*     CHECK FOR VALIDITY OF TYPE 1 FLOW AND IF VALID DETERMINE THE */
/*     DROP TO FREE FLOW.  FLOW MUST PASS 4 TESTS BEFORE IT IS */
/*     TYPE 1. */
/*      WRITE(STDOUT,*) ' FRFT1: CD=',CD,' for Type 1 flow' */
/*      WRITE(STDOUT,*) ' FRFT1: A2=',A2,' A1=',A1 */
/* SOURCE culvertb.for:1778 */
/*<       if(frsq.gt.1.0)then >*/
    if (rty1c_1.frsq > (float)1.) {
/*       Flow at section 1 is supercritical.  Flow type not 1. */
/* SOURCE culvertb.for:1780 */
/*<       write(stdout,*)' Type 1 rejected after solution: FRSQ=',frsq >*/
	feq_gen_io_d__183.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__183);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Type 1 rejected after solution: FRSQ="), (
		ftnlen)38);
	do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&rty1c_1.frsq, (ftnlen)sizeof(real));
	e_wsle();
/* SOURCE culvertb.for:1781 */
/*<       type=2 >*/
	*feq_gen_type_d_ = 2;
/* SOURCE culvertb.for:1782 */
/*<       freed=0.0 >*/
	*freed = (float)0.;
/* SOURCE culvertb.for:1783 */
/*<       qfree=q2 >*/
	*qfree = xs2com_1.q2;
/* SOURCE culvertb.for:1784 */
/*<       fg=0.0 >*/
	*fg = (float)0.;
/* SOURCE culvertb.for:1785 */
/*<       return >*/
	return 0;
/* SOURCE culvertb.for:1786 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:1788 */
/*<       sb=(zbvec(iu)-zbvec(iu+1))/abs(xvec(iu)-xvec(iu+1)) >*/
    sb = (static_cast<double>(culcom_1.zbvec[*iu - 1]) - culcom_1.zbvec[*iu]) / (feq_gen_r_d_1 = 
	    static_cast<double>(culcom_1.xvec[*iu - 1]) - culcom_1.xvec[*iu], dabs(feq_gen_r_d_1));
/* SOURCE culvertb.for:1789 */
/*<       if(sb.le.0.0)then >*/
    if (sb <= (float)0.) {
/*        WRITE(STDOUT,*) ' TYPE 1 REJECTED. SB=',SB */
/* SOURCE culvertb.for:1791 */
/*<       type=2 >*/
	*feq_gen_type_d_ = 2;
/* SOURCE culvertb.for:1792 */
/*<       else >*/
    } else {
/* SOURCE culvertb.for:1793 */
/*<       qn=k2*sqrt(sb) >*/
	qn = xs2com_1.k2 * sqrt(sb);
/* SOURCE culvertb.for:1794 */
/*<       if(qn.lt.q2)then >*/
	if (qn < xs2com_1.q2) {
/*         Slope is mild.  Super critical flow not supported. */
/* SOURCE culvertb.for:1796 */
/*<       write(stdout,62)qn,q2 >*/
	    feq_gen_io_d__186.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__186);
	    do_fio(&feq_gen_c_d_1, (char *)&qn, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xs2com_1.q2, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culvertb.for:1797 */
/*<       if(abs(qn-q2)/qn.le.0.01)then >*/
	    if ((feq_gen_r_d_1 = static_cast<double>(qn) - xs2com_1.q2, dabs(feq_gen_r_d_1)) / qn <= (float).01) {
/* SOURCE culvertb.for:1798 */
/*<       write(stdout,70) >*/
		feq_gen_io_d__187.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__187);
		e_wsfe();
/* SOURCE culvertb.for:1799 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:1800 */
/*<       type=2 >*/
	    *feq_gen_type_d_ = 2;
/* SOURCE culvertb.for:1801 */
/*<       else >*/
	} else {
/* SOURCE culvertb.for:1802 */
/*<       write(stdout,64)qn,q2 >*/
	    feq_gen_io_d__188.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__188);
	    do_fio(&feq_gen_c_d_1, (char *)&qn, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xs2com_1.q2, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culvertb.for:1803 */
/*<       if(abs(qn-q2)/qn.le.0.01)then >*/
	    if ((feq_gen_r_d_1 = static_cast<double>(qn) - xs2com_1.q2, dabs(feq_gen_r_d_1)) / qn <= (float).01) {
/* SOURCE culvertb.for:1804 */
/*<       write(stdout,70) >*/
		feq_gen_io_d__189.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__189);
		e_wsfe();
/* SOURCE culvertb.for:1805 */
/*<       endif >*/
	    }
/*         COMPUTE PROFILES TO CHECK FOR SLOPE CHANGES */
/*         FIND CRITICAL DEPTH AT EXIT AND COMPUTE SUBCRITICAL */
/*         PROFILE */
/* SOURCE culvertb.for:1812 */
/*<       ye=y2 >*/
	    ye = xs2com_1.y2;
/* SOURCE culvertb.for:1813 */
/*<       callfndcde(stdout,adrxs3,q2,ye) >*/
	    fndcde_(stdout, &xs3com_1.adrxs3, &xs2com_1.q2, &ye);
/* SOURCE culvertb.for:1816 */
/*<       y3=ye >*/
	    xs3com_1.y3 = ye;
/* SOURCE culvertb.for:1817 */
/*<       z3=zb3+y3 >*/
	    xs3com_1.z3 = static_cast<double>(xs3com_1.zb3) + xs3com_1.y3;
/* SOURCE culvertb.for:1818 */
/*<       callxlktal(adrxs3,y3,a3,t3,dt3,j3,k3,dk3,bet3,dbet3,alp3,dalp3) >*/
	    xlktal_(&xs3com_1.adrxs3, &xs3com_1.y3, &xs3com_1.a3, &
		    xs3com_1.t3, &xs3com_1.dt3, &xs3com_1.j3, &xs3com_1.k3, &
		    xs3com_1.dk3, &xs3com_1.bet3, &xs3com_1.dbet3, &
		    xs3com_1.alp3, &xs3com_1.dalp3);
/*         DEFINE THE COEF OF DISCHARGE */
/* SOURCE culvertb.for:1826 */
/*<       c123=fcd123(stdout,2,culcls,dvec(iu),z1) >*/
	    cdcom_1.c123 = fcd123_(stdout, &feq_gen_c_d_2, culcls, &culcom_1.dvec[*iu 
		    - 1], &xs1com_1.z1, (ftnlen)8);
/*         MAKE ADJUSTMENTS TO THE COEF. OF DISCHARGE FOR THE DEGREE OF */
/*         CHANNEL CONTRACTION */
/* SOURCE culvertb.for:1831 */
/*<       cd=degcon(c123,a1,a3) >*/
	    cdcom_1.cd = degcon_(&cdcom_1.c123, &xs1com_1.a1, &xs3com_1.a3);
/* SOURCE culvertb.for:1833 */
/*<       q3=q2 >*/
	    xs3com_1.q3 = xs2com_1.q2;
/* SOURCE culvertb.for:1834 */
/*<       dh=(1.0/cd**2-1.0)*(q3/a3)**2/grav2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = cdcom_1.cd;
/* Computing 2nd power */
	    feq_gen_r_d_2 = static_cast<double>(xs3com_1.q3) / xs3com_1.a3;
	    dh = static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - (float)1.)) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) / 
		    grvcom_1.grav2;
/* SOURCE culvertb.for:1835 */
/*<       callsfpsbe(stdout,iu,id,dh,q2,z3,isb,zup,sflag) >*/
	    sfpsbe_(stdout, iu, id, &dh, &xs2com_1.q2, &xs3com_1.z3, &isb, &
		    zup, &sflag);
/* SOURCE culvertb.for:1839 */
/*<       if(isb.eq.iu)then >*/
	    if (isb == *iu) {
/*           SUB CRITICAL PROFILE HAS REACHED THE ENTRANCE.  THUS */
/*           CRITICAL DEPTH AT THE ENTRANCE IS DROWNED */
/*           BECAUSE THE CULVERT CANNOT SUSTAIN SUPERCRITICAL */
/*           FLOW THROUGHOUT ITS LENGTH */
/* SOURCE culvertb.for:1844 */
/*<       sbe=(zbvec(id-1)-zbvec(id))/abs(xvec(id-1)-xvec(id)) >*/
		sbe = (static_cast<double>(culcom_1.zbvec[*id - 2]) - culcom_1.zbvec[*id - 1]) / (
			feq_gen_r_d_1 = static_cast<double>(culcom_1.xvec[*id - 2]) - culcom_1.xvec[*id - 1]
			, dabs(feq_gen_r_d_1));
/* SOURCE culvertb.for:1845 */
/*<       if(sbe.lt.sb)then >*/
		if (sbe < sb) {
/* SOURCE culvertb.for:1846 */
/*<       write(stdout,66) >*/
		    feq_gen_io_d__196.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__196);
		    e_wsfe();
/* SOURCE culvertb.for:1847 */
/*<       type=2 >*/
		    *feq_gen_type_d_ = 2;
/* SOURCE culvertb.for:1848 */
/*<       fg=ye >*/
		    *fg = ye;
/* SOURCE culvertb.for:1849 */
/*<       else >*/
		} else {
/* SOURCE culvertb.for:1850 */
/*<       write(stdout,68)sb,sbe >*/
		    feq_gen_io_d__197.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__197);
		    do_fio(&feq_gen_c_d_1, (char *)&sb, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&sbe, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE culvertb.for:1851 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:1852 */
/*<       endif >*/
		}
/* SOURCE culvertb.for:1853 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:1854 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:1855 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:1856 */
/*<       if(type.eq.2)then >*/
    if (*feq_gen_type_d_ == 2) {
/* SOURCE culvertb.for:1857 */
/*<       return >*/
	return 0;
/* SOURCE culvertb.for:1858 */
/*<       else >*/
    } else {
/*       DETERMINE THE DROP TO FREE FLOW. */
/*       COMPUTE SPECIAL STEADY FLOW PROFILE FROM ENTRANCE TO */
/*       EXIT AND THEN USE THE DEPARTURE REACH FROM EXIT TO SECTION */
/*       4 TO DETERMINE THE LEVEL IN SECTION 4 REQUIRED TO */
/*       DROWN TYPE 1 FLOW */
/*       Find the elevation of water surface at section 3 that */
/*       just drowns critical flow at section 2.  ZBEG gives the */
/*       elevation at the entrance for critical flow. */
/* SOURCE culvertb.for:1871 */
/*<       zbeg=z2 >*/
	zbeg = xs2com_1.z2;
/* SOURCE culvertb.for:1873 */
/*<       if(1.eq.2)then >*/
	if (FALSE_) {
/*       Use bisection to find the tailwater that comes close to drowning */
/*       critical flow at the entrance. */
/*       Search for a sign change.  We know that critical flow at the */
/*       culvert exit does not drown critical flow at the entrance. */
/*       Therefore, the subcritical profile from the exit to the entrance */
/*       did not complete. */
/* SOURCE culvertb.for:1883 */
/*<       yl=ye >*/
	    yl = ye;
/* SOURCE culvertb.for:1884 */
/*<       y3=ye >*/
	    xs3com_1.y3 = ye;
/* SOURCE culvertb.for:1886 */
/*<       q3=q2 >*/
	    xs3com_1.q3 = xs2com_1.q2;
/* SOURCE culvertb.for:1887 */
/*<   300 continue >*/
L300:
/* SOURCE culvertb.for:1888 */
/*<       y3=1.1*y3 >*/
	    xs3com_1.y3 *= static_cast<double>((float)1.1);
/* SOURCE culvertb.for:1889 */
/*<       z3=zb3+y3 >*/
	    xs3com_1.z3 = static_cast<double>(xs3com_1.zb3) + xs3com_1.y3;
/* SOURCE culvertb.for:1890 */
/*<       callxlktal(adrxs3,y3,a3,t3,dt3,j3,k3,dk3,bet3,dbet3,alp3,dalp3) >*/
	    xlktal_(&xs3com_1.adrxs3, &xs3com_1.y3, &xs3com_1.a3, &
		    xs3com_1.t3, &xs3com_1.dt3, &xs3com_1.j3, &xs3com_1.k3, &
		    xs3com_1.dk3, &xs3com_1.bet3, &xs3com_1.dbet3, &
		    xs3com_1.alp3, &xs3com_1.dalp3);
/*         DEFINE THE COEF OF DISCHARGE */
/* SOURCE culvertb.for:1898 */
/*<       c123=fcd123(stdout,3,culcls,dvec(iu),z1) >*/
	    cdcom_1.c123 = fcd123_(stdout, &feq_gen_c_d_3, culcls, &culcom_1.dvec[*iu 
		    - 1], &xs1com_1.z1, (ftnlen)8);
/* SOURCE culvertb.for:1899 */
/*<       cd=degcon(c123,a1,a3) >*/
	    cdcom_1.cd = degcon_(&cdcom_1.c123, &xs1com_1.a1, &xs3com_1.a3);
/* SOURCE culvertb.for:1900 */
/*<       dh=(1.0/cd**2-1.0)*(q3/a3)**2/grav2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = cdcom_1.cd;
/* Computing 2nd power */
	    feq_gen_r_d_2 = static_cast<double>(xs3com_1.q3) / xs3com_1.a3;
	    dh = static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - (float)1.)) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) / 
		    grvcom_1.grav2;
/* SOURCE culvertb.for:1901 */
/*<       callsfpsbe(stdout,iu,id,dh,q2,z3,isb,zup,sflag) >*/
	    sfpsbe_(stdout, iu, id, &dh, &xs2com_1.q2, &xs3com_1.z3, &isb, &
		    zup, &sflag);
/*          WRITE(STDOUT,*) ' FRFT1: In search of bracket Y3=',Y3 */
/* SOURCE culvertb.for:1905 */
/*<       if(isb.ne.iu)then >*/
	    if (isb != *iu) {
/*           Profile did not reach entrance. */
/* SOURCE culvertb.for:1907 */
/*<       yl=y3 >*/
		yl = xs3com_1.y3;
/* SOURCE culvertb.for:1908 */
/*<       goto300 >*/
		goto L300;
/* SOURCE culvertb.for:1909 */
/*<       endif >*/
	    }
/*       Profile did reach the entrance.  Set YR and start the */
/*       bisection process. */
/* SOURCE culvertb.for:1913 */
/*<       yr=y3 >*/
	    yr = xs3com_1.y3;
/* SOURCE culvertb.for:1914 */
/*<   310 continue >*/
L310:
/* SOURCE culvertb.for:1915 */
/*<       y3=0.5*(yl+yr) >*/
	    xs3com_1.y3 = static_cast<double>((static_cast<double>(yl) + yr)) * (float).5;
/* SOURCE culvertb.for:1916 */
/*<       z3=zb3+y3 >*/
	    xs3com_1.z3 = static_cast<double>(xs3com_1.zb3) + xs3com_1.y3;
/* SOURCE culvertb.for:1917 */
/*<       callxlktal(adrxs3,y3,a3,t3,dt3,j3,k3,dk3,bet3,dbet3,alp3,dalp3) >*/
	    xlktal_(&xs3com_1.adrxs3, &xs3com_1.y3, &xs3com_1.a3, &
		    xs3com_1.t3, &xs3com_1.dt3, &xs3com_1.j3, &xs3com_1.k3, &
		    xs3com_1.dk3, &xs3com_1.bet3, &xs3com_1.dbet3, &
		    xs3com_1.alp3, &xs3com_1.dalp3);
/*         DEFINE THE COEF OF DISCHARGE */
/* SOURCE culvertb.for:1925 */
/*<       c123=fcd123(stdout,3,culcls,dvec(iu),z1) >*/
	    cdcom_1.c123 = fcd123_(stdout, &feq_gen_c_d_3, culcls, &culcom_1.dvec[*iu 
		    - 1], &xs1com_1.z1, (ftnlen)8);
/* SOURCE culvertb.for:1926 */
/*<       cd=degcon(c123,a1,a3) >*/
	    cdcom_1.cd = degcon_(&cdcom_1.c123, &xs1com_1.a1, &xs3com_1.a3);
/* SOURCE culvertb.for:1927 */
/*<       dh=(1.0/cd**2-1.0)*(q3/a3)**2/grav2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = cdcom_1.cd;
/* Computing 2nd power */
	    feq_gen_r_d_2 = static_cast<double>(xs3com_1.q3) / xs3com_1.a3;
	    dh = static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - (float)1.)) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) / 
		    grvcom_1.grav2;
/* SOURCE culvertb.for:1928 */
/*<       callsfpsbe(stdout,iu,id,dh,q2,z3,isb,zup,sflag) >*/
	    sfpsbe_(stdout, iu, id, &dh, &xs2com_1.q2, &xs3com_1.z3, &isb, &
		    zup, &sflag);
/* SOURCE culvertb.for:1931 */
/*<       if(isb.ne.iu)then >*/
	    if (isb != *iu) {
/*           Profile did not reach entrance. */
/* SOURCE culvertb.for:1933 */
/*<       yl=y3 >*/
		yl = xs3com_1.y3;
/* SOURCE culvertb.for:1934 */
/*<       else >*/
	    } else {
/*           Profile did reach entrance. */
/* SOURCE culvertb.for:1936 */
/*<       yr=y3 >*/
		yr = xs3com_1.y3;
/* SOURCE culvertb.for:1937 */
/*<       endif >*/
	    }
/*          WRITE(STDOUT,*) ' FRFT1: Sqeezing YL=',YL,' YR=',YR */
/* SOURCE culvertb.for:1939 */
/*<       if(abs(yl-yr)/yr.gt.epsf)goto310 >*/
	    if ((feq_gen_r_d_1 = static_cast<double>(yl) - yr, dabs(feq_gen_r_d_1)) / yr > epscom_1.epsf) {
		goto L310;
	    }
/* SOURCE culvertb.for:1941 */
/*<       else >*/
	} else {
/* SOURCE culvertb.for:1943 */
/*<       dh=0.0 >*/
	    dh = (float)0.;
/* SOURCE culvertb.for:1944 */
/*<       callsfpty1(stdout,iu,id,dh,q2,zbeg,is,z3,sflag) >*/
	    sfpty1_(stdout, iu, id, &dh, &xs2com_1.q2, &zbeg, &is, &
		    xs3com_1.z3, &sflag);
/* SOURCE culvertb.for:1947 */
/*<       if(sflag.eq.0)then >*/
	    if (sflag == 0) {
/* SOURCE culvertb.for:1948 */
/*<       write(stdout,*)' FRFT1: Problem in SFPTY1 with DH=0.0' >*/
		feq_gen_io_d__202.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__202);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FRFT1: Problem in SFPTY1 with DH=0.0"), 
			(ftnlen)37);
		e_wsle();
/* SOURCE culvertb.for:1949 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:1950 */
/*<       endif >*/
	    }
/*       Now that we have an estimate of the conditions at section */
/*       3 when the critical control at section 2 is just being */
/*       submerged, estimate the type 3 losses that should take */
/*       place. */
/* SOURCE culvertb.for:1957 */
/*<       y3=z3-zb3 >*/
	    xs3com_1.y3 = static_cast<double>(xs3com_1.z3) - xs3com_1.zb3;
/* SOURCE culvertb.for:1958 */
/*<       tp=min(y3,ddn) >*/
	    tp = dmin(xs3com_1.y3,*ddn);
/* SOURCE culvertb.for:1959 */
/*<       callxlktal(adrxs3,tp,a3,t3,dt3,j3,k3,dk3,bet3,dbet3,alp3,dalp3) >*/
	    xlktal_(&xs3com_1.adrxs3, &tp, &xs3com_1.a3, &xs3com_1.t3, &
		    xs3com_1.dt3, &xs3com_1.j3, &xs3com_1.k3, &xs3com_1.dk3, &
		    xs3com_1.bet3, &xs3com_1.dbet3, &xs3com_1.alp3, &
		    xs3com_1.dalp3);
/*       Select the losses as in RQVSTW. */
/* SOURCE culvertb.for:1965 */
/*<       c123=fcd123(stdout,3,culcls,dup,hdatum+hup) >*/
	    feq_gen_r_d_1 = static_cast<double>(*hdatum) + *hup;
	    cdcom_1.c123 = fcd123_(stdout, &feq_gen_c_d_3, culcls, dup, &feq_gen_r_d_1, (ftnlen)
		    8);
/*        WRITE(STDOUT,*) ' FRFT1: C123=',C123 */
/* SOURCE culvertb.for:1967 */
/*<       avh=a3 >*/
	    cdcom_1.avh = xs3com_1.a3;
/*        AVH = A2 */
/* SOURCE culvertb.for:1969 */
/*<       cd=degcon(c123,truea1,avh) >*/
	    cdcom_1.cd = degcon_(&cdcom_1.c123, truea1, &cdcom_1.avh);
/*        WRITE(STDOUT,*) ' FRFT1: CD=',CD */
/* SOURCE culvertb.for:1971 */
/*<       dh=(1.0/cd**2-1.0)*(q2/avh)**2/grav2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = cdcom_1.cd;
/* Computing 2nd power */
	    feq_gen_r_d_2 = static_cast<double>(xs2com_1.q2) / cdcom_1.avh;
	    dh = static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - (float)1.)) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) / 
		    grvcom_1.grav2;
/* SOURCE culvertb.for:1972 */
/*<       write(stdout,72)dh >*/
	    feq_gen_io_d__204.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__204);
	    do_fio(&feq_gen_c_d_1, (char *)&dh, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culvertb.for:1973 */
/*<   200 continue >*/
L200:
/* SOURCE culvertb.for:1974 */
/*<       callsfpty1(stdout,iu,id,dh,q2,zbeg,is,z3,sflag) >*/
	    sfpty1_(stdout, iu, id, &dh, &xs2com_1.q2, &zbeg, &is, &
		    xs3com_1.z3, &sflag);
/* SOURCE culvertb.for:1977 */
/*<       if(sflag.eq.0)then >*/
	    if (sflag == 0) {
/*           If estimated losses cause computational problems, reduce */
/*           the losses and try again until the computations are */
/*           successful. */
/* SOURCE culvertb.for:1981 */
/*<       dh=0.9*dh >*/
		dh *= static_cast<double>((float).9);
/* SOURCE culvertb.for:1982 */
/*<       goto200 >*/
		goto L200;
/* SOURCE culvertb.for:1983 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:1985 */
/*<       write(stdout,74)dh >*/
	    feq_gen_io_d__205.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__205);
	    do_fio(&feq_gen_c_d_1, (char *)&dh, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culvertb.for:1987 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:1988 */
/*<       y3=z3-zb3 >*/
	xs3com_1.y3 = static_cast<double>(xs3com_1.z3) - xs3com_1.zb3;
/* SOURCE culvertb.for:1989 */
/*<       tp=min(y3,ddn) >*/
	tp = dmin(xs3com_1.y3,*ddn);
/* SOURCE culvertb.for:1990 */
/*<       callxlktal(adrxs3,tp,a3,t3,dt3,j3,k3,dk3,bet3,dbet3,alp3,dalp3) >*/
	xlktal_(&xs3com_1.adrxs3, &tp, &xs3com_1.a3, &xs3com_1.t3, &
		xs3com_1.dt3, &xs3com_1.j3, &xs3com_1.k3, &xs3com_1.dk3, &
		xs3com_1.bet3, &xs3com_1.dbet3, &xs3com_1.alp3, &
		xs3com_1.dalp3);
/* SOURCE culvertb.for:1994 */
/*<       calllktj(adrxs3,y3,j3) >*/
	lktj_(&xs3com_1.adrxs3, &xs3com_1.y3, &xs3com_1.j3);
/* SOURCE culvertb.for:1998 */
/*<       q3free=q3 >*/
	xs3com_1.q3free = xs3com_1.q3;
/* SOURCE culvertb.for:1999 */
/*<       y3free=y3 >*/
	xs3com_1.y3free = xs3com_1.y3;
/* SOURCE culvertb.for:2000 */
/*<       y2free=y2 >*/
	xs2com_1.y2free = xs2com_1.y2;
/* SOURCE culvertb.for:2001 */
/*<       lftype=1 >*/
	xs2com_1.lftype = 1;
/* SOURCE culvertb.for:2002 */
/*<       lstype=-1 >*/
	xs2com_1.lstype = -1;
/*       FIND ELEVATION IN THE DEPARTURE REACH */
/* SOURCE culvertb.for:2005 */
/*<       z3p=z3 >*/
	xs3com_1.z3p = xs3com_1.z3;
/* SOURCE culvertb.for:2007 */
/*<       calldpm26(stdout,wfrdf,mfrdf,z3,expflg) >*/
	dpm26_(stdout, &rdfcom_1.wfrdf, &rdfcom_1.mfrdf, &xs3com_1.z3, expflg)
		;
/* SOURCE culvertb.for:2011 */
/*<       if(expflg.eq.0)then >*/
	if (*expflg == 0) {
/* SOURCE culvertb.for:2012 */
/*<       freed=0.0 >*/
	    *freed = (float)0.;
/* SOURCE culvertb.for:2013 */
/*<       else >*/
	} else {
/* SOURCE culvertb.for:2014 */
/*<       freed=z1-z4 >*/
	    *freed = static_cast<double>(xs1com_1.z1) - xs4com_1.z4;
/* SOURCE culvertb.for:2015 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:2016 */
/*<       return >*/
	return 0;
/* SOURCE culvertb.for:2017 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:2018 */
/*<       end >*/
    return 0;
} /* frft1_ */




/* SOURCE culvertb.for:2022 */
/*<        >*/
/* Subroutine */ int frft2_(integer *stdout, real *hdatum, real *zdatum, real 
	*hup, integer *iu, integer *id, char *culcls, integer *eflag, real *
	fg, integer *feq_gen_type_d_, integer *expflg, real *qfree, real *freed, 
	ftnlen culcls_len)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *BUG:XXX* SIGN CHNG ON ENTRY BUT RGF CLAIM\
S NONE IN\002,\002 FRFT2.\002)";
    static char fmt_52[] = "(/,\002 Lower type 1 limit does not exist.  Type\
 2 limit \002,\002does not exist.\002,/,\002 Increasing the approach length\
 \002,\002may help if the approach\002,/,\002 area is about the same \002\
,\002size as the culvert flow area,\002,/,\002 or if the kinetic-\002,\002en\
ergy-flux coefficient in the\002,/,\002 approach section \002,\002is signifi\
cantly > 1.0.\002,//,\002 Trying high-head option.\002)";
    static char fmt_56[] = "(\002 *WRN:540* No positive residual for type 2 \
flow.\002)";
    static char fmt_58[] = "(\002 *WRN:541* No negative residual for type 2 \
flow.\002)";
    static char fmt_60[] = "(\002 *BUG:XXX* RGF: More than 100 iterations in\
 FRFT2.\002)";
    static char fmt_66[] = "(/,\002 *WRN:552* Residual at convergence=\002,f\
10.3,\002 > \002,f8.4)";
    static char fmt_67[] = "(/,\002  Type 2 may not be possible.  Trying hig\
h head.\002)";
    static char fmt_68[] = "(\002  Current residual=\002,1pe10.3,\002 trying\
 to continue.\002)";
    static char fmt_70[] = "(/,\002 Type 2 flow no longer possible.  Trying \
high-head\002,\002 flow.\002)";
    static char fmt_76[] = "(/,\002 *WRN:580* Unable to force type 6 Cd to m\
atch type 2\002,\002 flow at its limit.\002,/,11x,\002 Using type 6 Cd. \002,\
\002Manual adjustment of 2-D table may be needed.\002)";
    static char fmt_78[] = "(/,\002 *WRN:581* Unable to force type 61 Cd to \
match type 2\002,\002 flow at its limit.\002,/,11x,\002 Using type 6 Cd. \
\002,\002Manual adjustment of 2-D table may be needed.\002)";
    static char fmt_80[] = "(/,\002*WRN:590* Type 2 failure at ups head=\002\
,f8.3,\002 <= head\002,\002 at lower limit\002,/,11x,\002of Type 1=\002,f8.3,\
\002  If heads are\002,\002 close, increase ups head to\002,/,11x,\002exceed\
 Type 1 lower limit.\002)";
    static char fmt_82[] = "(/,\002 *WRN:591* Type 2 failure at ups head=\
\002,f8.3,\002 => head\002,\002 at lower limit\002,/,11x,\002of Type 1=\002,\
f8.3,\002  If heads are\002,\002 close, increase ups head to\002,/,11x,\002e\
xceed Type 1 lower\002,\002 limit by a larger amount.\002)";
    static char fmt_84[] = "(/,\002 Type 2 limits:\002,/,4x,\002Local elevat\
ion at section 1=\002,f8.3,/,4x,\002Head/vertical diameter ratio at section \
2=\002,f8.3,/,4x,\002Depth at section 3=\002,f8.3)";
    static char fmt_86[] = "(/,\002 Parameters for transition from type 2 to\
 type 6:\002,/,4x,\002Coefficient of discharge=\002,f8.3,/,4x,\002Momentum-f\
lux coefficient=\002,f8.3,/,4x,\002Kinetic-energy flux coefficient=\002,f8.3)"
	    ;
    static char fmt_88[] = "(/,\002 Type 61 limits:\002,/,4x,\002Local eleva\
tion at section 1=\002,f8.3,/,4x,\002Head/vertical diameter ratio at sec. 2\
=\002,f8.3)";
    static char fmt_90[] = "(/,\002 Parameters for transition from type 61 t\
o type 6:\002,/,4x,\002Coefficient of discharge=\002,f8.3,/,4x,\002Momentum-\
flux coefficient=\002,f8.3,/,4x,\002Kinetic-energy flux coefficient=\002,f8.\
3)";
    static char fmt_92[] = "(/,\002 Parameters for transition from type 2 to\
 type 5:\002,/,4x,\002Contraction coefficient=\002,f8.3,/,4x,\002Momentum-fl\
ux coefficient=\002,f8.3,/,4x,\002Kinetic-energy flux coefficient=\002,f8.3,\
/,4x,\002Depth at section 3=\002,f8.3)";

    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3, feq_gen_r_d_4;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(), s_wsfe(cilist *), e_wsfe(), do_fio(integer *, char *, 
	    ftnlen);
    double sqrt(doublereal);
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);

    /* Local variables */
    real a, feq_gen_r_d_, qc, hw, qn, tp, yt, ddn;
    extern /* Subroutine */ int rgf_(real *, real *, FeqCallback3, real *, real *, 
	    real *, real *, real *, integer *);
    real dup;
    integer knt;
    real yvc, yat2, zat3;
    extern doublereal rty2_(real *);
    integer feq_gen_flag_d_;
    real flow, zat43;
    extern /* Subroutine */ int dpm26_(integer *, real *, real *, real *, 
	    integer *), lkta_(integer *, real *, real *);
    real ylow, ycat3;
    integer icase, iflag;
    real fhigh, yhigh;
    extern /* Subroutine */ int f61bdy_(integer *, integer *, real *, real *, 
	    real *, integer *, integer *, char *, real *, integer *, ftnlen), 
	    fndcc2_(integer *, real *, real *, real *), lktqc_(integer *, 
	    real *, real *), xlkt22_(integer *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *);
    real ty6lss;
    char jmploc[32];
    extern doublereal fmxarg_(integer *), yoverd_(integer *, real *, real *, 
	    real *);
    extern /* Subroutine */ int supsub_(integer *, integer *, integer *, real 
	    *, real *, real *, real *, real *, real *, real *, real *, char *,
	     ftnlen), xlktal_(integer *, real *, real *, real *, real *, real 
	    *, real *, real *, real *, real *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__208 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__209 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__210 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__211 = { 0, 0, 0, fmt_84, 0 };
    static cilist feq_gen_io_d__213 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__214 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__217 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__218 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__219 = { 0, 0, 0, fmt_88, 0 };
    static cilist feq_gen_io_d__220 = { 0, 0, 0, fmt_90, 0 };
    static cilist feq_gen_io_d__229 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__231 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__232 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__233 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__234 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__235 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__236 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__237 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__238 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__239 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__240 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__245 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__246 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__251 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__252 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__254 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__255 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__256 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__257 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__258 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__259 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__260 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__261 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__262 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__263 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__264 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__265 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__266 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__268 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__269 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__270 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__271 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__272 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__273 = { 0, 0, 0, fmt_67, 0 };


/*     + + + PURPOSE + + + */
/*     Compute flow of type 2 for the given upsteam head, HUP */
/*     FG is a first guess passed from type 1 flow or 0.0 */
/*     if type 1 was not computed */
/* SOURCE culvertb.for:2032 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertb.for:2035 */
/*<       integereflag,expflg,id,iu,stdout,type >*/
/* SOURCE culvertb.for:2036 */
/*<       realfg,freed,hdatum,hup,qfree,zdatum >*/
/* SOURCE culvertb.for:2037 */
/*<       characterculcls*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     HDATUM - Datum for measuring head */
/*     ZDATUM - datum for local elevation */
/*     HUP    - Head upstream */
/*     IU     - Index for upstream node for the culvert barrel */
/*     ID     - Index for the downstream node for the culvert barrel */
/*     CULCLS - Class for culvert shape, BOX, PIPE, .. */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     FG     - First guess */
/*     TYPE   - Culvert flow type */
/*     EXPFLG - Expansion flag.  EXPFLG=1 if flow expands on exit */
/*              and EXPFLG=0 if flow does not expand on exit */
/*     QFREE  - Free flow */
/*     FREED  - Free drop */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertb.for:2056 */
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
/* INCLUDE culvertb.for:2057 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE culvertb.for:2058 */
/* SOURCE xs1com.cmn:2 */
/*<        >*/
/* SOURCE xs1com.cmn:7 */
/*<       integeradrxs1 >*/
/* SOURCE xs1com.cmn:9 */
/*<        >*/
/*     Z1TY1- elevation at section 1 at type 1 limit if it exists */
/*     Z1TY1L-elevation at section 1 at lower limit of type 1 if it exists */
/*     Z1TY6- elevation at section 1 at start of type 6 if it exists */
/*     Z1TY2- elevation at upper limit of type 2 flow if it exists */
/*     Z1TY61- elevation at upper limt of type 61 if it exists */
/*     Z1TY5- elevation at section at start of type 5 if it exists */
/*     Z1TY52- elevation at section 1 at lower limit of type 52( */
/*             type 2 to type 5 flow) */
/*     Z1TY51- elevation at section 1 at lower limit of type 51( */
/*             type 1 to type 5 flow) */
/* INCLUDE culvertb.for:2059 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culvertb.for:2060 */
/* SOURCE xs3com.cmn:2 */
/*<        >*/
/* SOURCE xs3com.cmn:11 */
/*<       integeradrxs3 >*/
/* SOURCE xs3com.cmn:13 */
/*<        >*/
/*     CD1- if 0.0 type 1 flow has not been checked, if > 0 type 1 */
/*          flow has been checked and found to exist and its limit */
/*          values have been found, if < 0 type 1 flow does not exist. */
/*     CD2T6- coef. of discharge forcing full flow to match flow */
/*            at the type 2 flow limit. */
/*     AP2T6 - kinetic energy flux coefficient forcing the full */
/*             flow kinetic energy flux to match the flux */
/*             at the type 2 limit. */
/*     BT2T6- momentum flux coefficient forcing the full flow */
/*            momentum flux to match the flux at the type 2 limit. */
/*     CD61T6- coef. of discharge forcing full flow to match flow */
/*             at the type 61 limit. */
/*     CD1T6- coef. of discharge forcing full flow to match flow */
/*            at the type 1 limit */

/*     AP61T6- same as AP2T6 for type 61. */
/*     BT61T6- same as AP2T6 for type 61. */
/*     CD2- coef. of discharge for type 2 flow at the type 2 limit. */
/*     CD61- coef. of discharge for type 61 flow at the type 61 limit. */
/*     CD6- coef. of discharge for type 6 flow. */
/*     Z3PTY6- piezometric level at section 3 at the type 6 limit. */
/*     AVH2- area for velocity head at the type 2 limit. */
/*     AVH61- area for velocity head at the type 61 limit. */
/*     BT3ATD- beta at section 3 when barrel is full(at D!) */
/*     AP3ATD- alpha at section 3 when the barrel is full(at D!) */
/*     CC2T5 - contraction coefficient for type 5 at the type 2 flow */
/*             limit. */
/*     CC1T5 - contraction coefficient for type 5 at the type 1 flow */
/*             limit. */
/*     CC5- contraction coefficient for type 5 at its lower limit */
/*          and above. */
/*     Y3TY52- depth at section 3 at the lower limit of type 52 flow */
/*             giving the transistion between type 2 and type 5. */
/*     Y3TY51- depth at section 3 at the lower limit of type 51 flow */
/*             giving the transistion between type 1 and type 5. */
/*     BT2T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 52 and */
/*             upper limit of type 2. */
/*     BT1T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 51 and */
/*             upper limit of type 1. */
/*     AP2T5-  alpha analogous to BT2T5 */
/*     AP1T5-  alpha analogous to BT1T5 */
/*     Y3TY5-  depth at section 3 at the lower limit of type 5 flow */
/*     BT3AT5- beta for type 5 flow limit */
/*     AP3AT5- alpha for type 5 flow limit */
/*     CD5T4- coefficient of discharge that forces a type 4 equation */
/*            to match the type 5, 51, or 52 flow at the full-flow- */
/*            inducing level at section 43. */
/*     Y3LTY2- depth at section 3 at the type 2 limit, that is, */
/*             critical depth. */
/*     Y3LTY1- submergence depth at section 3  at the limit of */
/*             type 1 flow. */
/*     Y3LTY5- the full-flow-inducing value of piezometric level */
/*             relative to the invert at section 3 for flow types */
/*             5, 51, and 52. */
/* INCLUDE culvertb.for:2061 */
/* SOURCE xs4com.cmn:2 */
/*<        >*/
/* SOURCE xs4com.cmn:5 */
/*<       integeradrxs4 >*/
/* SOURCE xs4com.cmn:7 */
/*<        >*/
/* INCLUDE culvertb.for:2062 */
/* SOURCE cdcom.cmn:2 */
/*<        >*/
/* SOURCE cdcom.cmn:10 */
/*<        >*/
/* SOURCE cdcom.cmn:14 */
/*<        >*/
/*     Add values for support of FHWA type 5 scheme. Oct. 3, 2001 */
/* SOURCE cdcom.cmn:20 */
/*<       realafhwa,cfhwa,yfhwa,sfhwa >*/
/*     AFHWA - value of a */
/*     CFHWA - value of c */
/*     YFHWA - value of Y */
/*     SFHWA - slope of culvert near entrance. */
/* INCLUDE culvertb.for:2063 */
/* SOURCE rdfcom.cmn:2 */
/*<       common/rdfcom/wfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/* SOURCE rdfcom.cmn:4 */
/*<       realwfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/*     WFRDF-WATER FLUX OVER ROAD FREE CONDITION. */
/*     MFRDF-MOMENTUM FLUX OVER THE ROAD FREE CONDITION. */
/*     EFRDF-ENERGY FLUX OVER THE ROAD FREE CONDITION. */
/*     WFRD- WATER FLUX OVER THE ROAD ANY CONDITION. */
/*     MFRD- MOMENTUM FLUX OVER THE ROAD ANY CONDITION. */
/*     EFRD- ENERGY FLUX OVER THE ROAD ANY CONDITION. */
/* INCLUDE culvertb.for:2064 */
/*     Common to hold values needed for computing various limits */
/*     for culvert flow types. */
/* SOURCE typlim.cmn:4 */
/*<        >*/
/* SOURCE typlim.cmn:10 */
/*<       integerhhtype >*/
/* SOURCE typlim.cmn:12 */
/*<        >*/
/* INCLUDE culvertb.for:2065 */
/* SOURCE culcom.cmn:2 */
/*<        >*/
/* SOURCE culcom.cmn:8 */
/*<       integernsec(mnbn),hltab(mnbn),iat3d,iat6d,sbkind,sbshape >*/
/* SOURCE culcom.cmn:10 */
/*<        >*/
/* SOURCE culcom.cmn:16 */
/*<       doubleprecisionfrcfac >*/
/*     FRCFAC- friction factor to give factor for friction losses */
/*             in barrel for non-prismatic full-flow that as well */
/*             as prismatic full flow. */
/*     TY1YTD- maximum ratio of depth to vertical diameter for */
/*             type 1 flow. */
/*     TY1HTD- maximum ratio of head at section 1 relative to */
/*             culvert invert at culvert inlet to the vertical */
/*             diamter of the culvert.  Must be less than 1.5. */
/*     SBKIND- if 0 the slope of the culvert barrel is a constant, */
/*             if 1 the slope of the culvert barrel varies. */
/*     BSHAPE- if 0 the barrel shape is constant, that is, prismatic, */
/*             if 1 the barrel shape is nonprismatic. */
/*     TY5SBF- ratio of depth to vertical diameter of the culvert */
/*             at the exit which causes submergence. */
/* Note:  25 August 2004:  SBSHAPE is apparently not used.  BSHAPE */
/* is but outside of a common block. */
/* INCLUDE culvertb.for:2066 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertb.for:2067 */
/* SOURCE appcom.cmn:2 */
/*<       common/appcom/apptab,appelv,applen,applos,appexp,zertab,zerelv >*/
/* SOURCE appcom.cmn:5 */
/*<       integerapptab,zertab >*/
/* SOURCE appcom.cmn:7 */
/*<       realappelv,applen,applos,appexp,zerelv >*/
/* INCLUDE culvertb.for:2068 */
/*     Common block for various parameters to handle transitional */
/*     flow type behavior for the departure reach computations. */
/* SOURCE typtrn.cmn:4 */
/*<       common/typtrn/avhf,cdf,betaf,alphaf,y3pf,beta3,alpha3 >*/
/* SOURCE typtrn.cmn:6 */
/*<       realavhf,cdf,betaf,alphaf,y3pf,beta3,alpha3 >*/
/*     AVHF- area used for velocity head in computing losses for the */
/*           transitional free flow */
/*     CDF- coef. of discharge for computing losses for the transitional */
/*          free flow. */
/*     BETAF- value of beta to compensate for false area in the computation */
/*            of the momentum flux from some free flows.  If this */
/*            value is zero it means that the beta from the cross section */
/*            function table should be used.  If it is non-zero it means */
/*            that the free flow type was used as a transition and that */
/*            the flow area of the culvert barrel outlet was falsified in */
/*            the process. */
/*     ALPHAF- value of alpha to use in computing velocity head for */
/*             energy loss computations. */
/*     Y3PF- depth to the piezometric level at the culvert barrel outlet */
/*           for free flow limit. */
/*     BETA3- actual value at section 3 used in departure reach */
/*     ALPHA3- actual value at section 3.  Crudely estimated in some */
/*             cases because better alternative is not available. */
/* INCLUDE culvertb.for:2069 */
/*     Commons for function RTY2 in FEQUTL */
/* SOURCE rty2c.cmn:3 */
/*<        >*/
/* SOURCE rty2c.cmn:5 */
/*<       integeroutun,iup,idn,ef,conf,ns,sbflag >*/
/* SOURCE rty2c.cmn:6 */
/*<       realz1true,a1true,sbot,alp1tr,maxarg >*/
/* SOURCE rty2c.cmn:7 */
/*<       common/rty2cc/class >*/
/* SOURCE rty2c.cmn:8 */
/*<       character*8class >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertb.for:2072 */
/*<       integerflag,icase,iflag,knt >*/
/* SOURCE culvertb.for:2073 */
/*<        >*/
/* SOURCE culvertb.for:2075 */
/*<       characterjmploc*32 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertb.for:2078 */
/*<       intrinsicabs,min,sqrt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertb.for:2081 */
/*<       realfmxarg,rty2,yoverd >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertb.for:2084 */
/*<        >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertb.for:2088 */
/*<    50  >*/
/* SOURCE culvertb.for:2090 */
/*<    52  >*/
/* SOURCE culvertb.for:2096 */
/*<    56 format(' *WRN:540* No positive residual for type 2 flow.') >*/
/* SOURCE culvertb.for:2097 */
/*<    58 format(' *WRN:541* No negative residual for type 2 flow.') >*/
/* SOURCE culvertb.for:2098 */
/*<    60 format(' *BUG:XXX* RGF: More than 100 iterations in FRFT2.') >*/
/* SOURCE culvertb.for:2099 */
/*<    66 format(/,' *WRN:552* Residual at convergence=',f10.3,' > ',f8.4) >*/
/* SOURCE culvertb.for:2100 */
/*<    67 format(/,'  Type 2 may not be possible.  Trying high head.') >*/
/* SOURCE culvertb.for:2101 */
/*<    68 format('  Current residual=',1pe10.3,' trying to continue.') >*/
/* SOURCE culvertb.for:2102 */
/*<    70  >*/
/* SOURCE culvertb.for:2104 */
/*<    76  >*/
/* SOURCE culvertb.for:2107 */
/*<    78  >*/
/* SOURCE culvertb.for:2110 */
/*<    80  >*/
/* SOURCE culvertb.for:2114 */
/*<    82  >*/
/* SOURCE culvertb.for:2118 */
/*<    84  >*/
/* SOURCE culvertb.for:2122 */
/*<    86  >*/
/* SOURCE culvertb.for:2126 */
/*<    88  >*/
/* SOURCE culvertb.for:2129 */
/*<    90  >*/
/* SOURCE culvertb.for:2133 */
/*<    92  >*/
/* *********************************************************************** */
/* SOURCE culvertb.for:2139 */
/*<       betaf=0.0 >*/
/* L50: */
/* L52: */
/* L56: */
/* L58: */
/* L60: */
/* L66: */
/* L67: */
/* L68: */
/* L70: */
/* L76: */
/* L78: */
/* L80: */
/* L82: */
/* L84: */
/* L86: */
/* L88: */
/* L90: */
/* L92: */
    typtrn_1.betaf = (float)0.;
/* SOURCE culvertb.for:2140 */
/*<       beta3=0.0 >*/
    typtrn_1.beta3 = (float)0.;
/* SOURCE culvertb.for:2141 */
/*<       alpha3=0.0 >*/
    typtrn_1.alpha3 = (float)0.;
/* SOURCE culvertb.for:2142 */
/*<       dup=dvec(iu) >*/
    dup = culcom_1.dvec[*iu - 1];
/* SOURCE culvertb.for:2143 */
/*<       ddn=dvec(id) >*/
    ddn = culcom_1.dvec[*id - 1];
/*      WRITE(STDOUT,*) ' FRFT2: CD2=',CD2 */
/* SOURCE culvertb.for:2146 */
/*<       if(cd2.eq.0.0)then >*/
    if (xs3com_1.cd2 == (float)0.) {
/*       Type 2 limit has not been computed.  Try to find the limit */
/*       here. */
/* SOURCE culvertb.for:2149 */
/*<       callf61bdy(stdout,2,hdatum,zdatum,hup,iu,id,culcls,dup,eflag) >*/
	f61bdy_(stdout, &feq_gen_c_d_2, hdatum, zdatum, hup, iu, id, culcls, &dup, 
		eflag, (ftnlen)8);
/*        WRITE(STDOUT,*) ' FRF2: AFTER F61BDY: EFLAG=',EFLAG */
/* SOURCE culvertb.for:2153 */
/*<       if(eflag.eq.-1)then >*/
	if (*eflag == -1) {
/*         Type 2 limit does not exist.  Set a value in CD2 to show */
/*         that the limit does not exist. */
/* SOURCE culvertb.for:2156 */
/*<        >*/
	    feq_gen_io_d__208.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__208);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FRFT2: Type 2 limit above upper Type 1"), (
		    ftnlen)39);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" limit does not exist."), (ftnlen)22);
	    e_wsle();
/* SOURCE culvertb.for:2158 */
/*<       cd2=-1.0 >*/
	    xs3com_1.cd2 = (float)-1.;
/* SOURCE culvertb.for:2159 */
/*<       eflag=0 >*/
	    *eflag = 0;
/* SOURCE culvertb.for:2160 */
/*<       cd2t6=-1.0 >*/
	    xs3com_1.cd2t6 = (float)-1.;
/* SOURCE culvertb.for:2161 */
/*<       if(z1ty1l.gt.zb1)then >*/
	    if (xs1com_1.z1ty1l > xs1com_1.zb1) {
/*           Lower type 1 limit exists.  Therefore, type 2 flow */
/*           may exist below the lower type 1 limit. */
/* SOURCE culvertb.for:2164 */
/*<        >*/
		feq_gen_io_d__209.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__209);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Lower type 1 limit exists.  Will"), (
			ftnlen)33);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" attempt Type 2 computations."), (ftnlen)
			29);
		e_wsle();
/* SOURCE culvertb.for:2167 */
/*<       else >*/
	    } else {
/*           Type 2 limit above type 1 limit does not exist. Lower */
/*           type 1 limit does not exist.  Not clear what is */
/*           happening here.  Try a  high-head option. */
/* SOURCE culvertb.for:2171 */
/*<       write(stdout,52) >*/
		feq_gen_io_d__210.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__210);
		e_wsfe();
/* SOURCE culvertb.for:2172 */
/*<       type=6 >*/
		*feq_gen_type_d_ = 6;
/* SOURCE culvertb.for:2173 */
/*<       return >*/
		return 0;
/* SOURCE culvertb.for:2174 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:2175 */
/*<       else >*/
	} else {
/* SOURCE culvertb.for:2176 */
/*<       cd2=cd >*/
	    xs3com_1.cd2 = cdcom_1.cd;
/* SOURCE culvertb.for:2177 */
/*<       avh2=avh >*/
	    xs3com_1.avh2 = cdcom_1.avh;
/* SOURCE culvertb.for:2178 */
/*<       y3lty2=y3part >*/
	    xs3com_1.y3lty2 = typlim_1.y3part;
/* SOURCE culvertb.for:2179 */
/*<       write(stdout,84)z1ty2,(z1ty2-zb2)/dup,y3lty2 >*/
	    feq_gen_io_d__211.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__211);
	    do_fio(&feq_gen_c_d_1, (char *)&xs1com_1.z1ty2, (ftnlen)sizeof(real));
	    feq_gen_r_d_1 = static_cast<double>((static_cast<double>(xs1com_1.z1ty2) - xs2com_1.zb2)) / dup;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.y3lty2, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culvertb.for:2180 */
/*<       if(hhtype.eq.6)then >*/
	    if (typlim_1.hhtype == 6) {
/* SOURCE culvertb.for:2181 */
/*<       if(zb2.ge.zb3)then >*/
		if (xs2com_1.zb2 >= xs3com_1.zb3) {
/*             Type 61 limit does not exist but type 2 limit does. */
/*             Find parameters for transition from type 2 to type 6. */
/* SOURCE culvertb.for:2184 */
/*<        >*/
/* Computing 2nd power */
		    feq_gen_r_d_1 = static_cast<double>(typlim_1.q1l) / typlim_1.a1l;
/* Computing 2nd power */
		    feq_gen_r_d_2 = static_cast<double>(typlim_1.q3l) / xs3com_1.a3full;
/* Computing 2nd power */
		    feq_gen_r_d_3 = static_cast<double>(typlim_1.q2l) / xs2com_1.k2full;
/* Computing 2nd power */
		    feq_gen_r_d_4 = static_cast<double>(xs2com_1.a2full) / typlim_1.q2l;
		    tp = static_cast<double>((static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>(typlim_1.alp1l) - appcom_1.applos)) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) /
			     grvcom_1.grav2) + typlim_1.z1l) - (static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2) / 
			    grvcom_1.grav2) + typlim_1.z3part)) - static_cast<double>(culcom_1.l23) *
			     (static_cast<double>(feq_gen_r_d_3) * feq_gen_r_d_3)) - static_cast<double>(static_cast<double>(appcom_1.applen) * (static_cast<double>(typlim_1.q1l) *
			     typlim_1.q2l)) / (static_cast<double>(typlim_1.k1l) * xs2com_1.k2full)))
			     * (static_cast<double>(grvcom_1.grav2) * (static_cast<double>(feq_gen_r_d_4) * feq_gen_r_d_4));
/* SOURCE culvertb.for:2187 */
/*<       if(tp.lt.0.0)then >*/
		    if (tp < (float)0.) {
/* SOURCE culvertb.for:2188 */
/*<       write(stdout,76) >*/
			feq_gen_io_d__213.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__213);
			e_wsfe();
/* SOURCE culvertb.for:2189 */
/*<       cd2t6=c46 >*/
			xs3com_1.cd2t6 = cdcom_1.c46;
/* SOURCE culvertb.for:2190 */
/*<       else >*/
		    } else {
/* SOURCE culvertb.for:2191 */
/*<       cd2t6=sqrt(1.0/(1.0+tp)) >*/
			xs3com_1.cd2t6 = sqrt(static_cast<double>((float)1.) / (static_cast<double>(tp) + (float)1.));
/* SOURCE culvertb.for:2192 */
/*<       endif >*/
		    }
/* SOURCE culvertb.for:2193 */
/*<       bt2t6=a3full/a3part >*/
		    xs3com_1.bt2t6 = static_cast<double>(xs3com_1.a3full) / typlim_1.a3part;
/* SOURCE culvertb.for:2194 */
/*<       ap2t6=(bt2t6)**2 >*/
/* Computing 2nd power */
		    feq_gen_r_d_1 = xs3com_1.bt2t6;
		    xs3com_1.ap2t6 = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE culvertb.for:2195 */
/*<       write(stdout,86)cd2t6,bt2t6,ap2t6 >*/
		    feq_gen_io_d__214.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__214);
		    do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.cd2t6, (ftnlen)sizeof(
			    real));
		    do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.bt2t6, (ftnlen)sizeof(
			    real));
		    do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.ap2t6, (ftnlen)sizeof(
			    real));
		    e_wsfe();
/* SOURCE culvertb.for:2196 */
/*<       cd61=-1.0 >*/
		    xs3com_1.cd61 = (float)-1.;
/* SOURCE culvertb.for:2197 */
/*<       else >*/
		} else {
/*             Type 2 flow exists and the barrel slope is adverse. */
/*             Therefore, type 61 exists! */
/* SOURCE culvertb.for:2200 */
/*<       yat2=zb3+ddn-zb2 >*/
		    yat2 = static_cast<double>(static_cast<double>(xs3com_1.zb3) + ddn) - xs2com_1.zb2;
/* SOURCE culvertb.for:2201 */
/*<       callf61bdy(stdout,61,hdatum,zdatum,hup,iu,id,culcls,yat2,iflag) >*/
		    f61bdy_(stdout, &feq_gen_c_d_61, hdatum, zdatum, hup, iu, id, 
			    culcls, &yat2, &iflag, (ftnlen)8);
/* SOURCE culvertb.for:2205 */
/*<       if(iflag.eq.-1)then >*/
		    if (iflag == -1) {
/* SOURCE culvertb.for:2206 */
/*<       write(stdout,*)' Type 61 limit not found when it must',' exist.' >*/
			feq_gen_io_d__217.ciunit = *stdout;
			s_wsle(&feq_gen_io_d__217);
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Type 61 limit not found when \
it must"), (ftnlen)37);
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" exist."), (ftnlen)7);
			e_wsle();
/* SOURCE culvertb.for:2208 */
/*<       stop'Abnormal stop. Errors found.' >*/
			s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:2209 */
/*<       else >*/
		    } else {
/* SOURCE culvertb.for:2210 */
/*<       cd61=cd >*/
			xs3com_1.cd61 = cdcom_1.cd;
/* SOURCE culvertb.for:2211 */
/*<       avh61=avh >*/
			xs3com_1.avh61 = cdcom_1.avh;
/*               Type 61 exists.  Therefore transition is between 61 */
/*               and 6. */
/* SOURCE culvertb.for:2215 */
/*<        >*/
/* Computing 2nd power */
			feq_gen_r_d_1 = static_cast<double>(typlim_1.q1l) / typlim_1.a1l;
/* Computing 2nd power */
			feq_gen_r_d_2 = static_cast<double>(typlim_1.q3l) / xs3com_1.a3full;
/* Computing 2nd power */
			feq_gen_r_d_3 = static_cast<double>(typlim_1.q2l) / xs2com_1.k2full;
/* Computing 2nd power */
			feq_gen_r_d_4 = static_cast<double>(xs2com_1.a2full) / typlim_1.q2l;
			tp = static_cast<double>((static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>(typlim_1.alp1l) - appcom_1.applos)) * (static_cast<double>(feq_gen_r_d_1) * 
				feq_gen_r_d_1)) / grvcom_1.grav2) + typlim_1.z1l) - (static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_2) 
				* feq_gen_r_d_2) / grvcom_1.grav2) + typlim_1.z3part)) - 
				static_cast<double>(culcom_1.l23) * (static_cast<double>(feq_gen_r_d_3) * feq_gen_r_d_3)) - 
				static_cast<double>(static_cast<double>(appcom_1.applen) * (static_cast<double>(typlim_1.q1l) * 
				typlim_1.q2l)) / (static_cast<double>(typlim_1.k1l) * 
				xs2com_1.k2full))) * (static_cast<double>(grvcom_1.grav2) * (static_cast<double>(feq_gen_r_d_4) * 
				feq_gen_r_d_4));
/* SOURCE culvertb.for:2218 */
/*<       if(tp.lt.0.0)then >*/
			if (tp < (float)0.) {
/* SOURCE culvertb.for:2219 */
/*<       write(stdout,78) >*/
			    feq_gen_io_d__218.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__218);
			    e_wsfe();
/* SOURCE culvertb.for:2220 */
/*<       cd61t6=c46 >*/
			    xs3com_1.cd61t6 = cdcom_1.c46;
/* SOURCE culvertb.for:2221 */
/*<       else >*/
			} else {
/* SOURCE culvertb.for:2222 */
/*<       cd61t6=sqrt(1.0/(1.0+tp)) >*/
			    xs3com_1.cd61t6 = sqrt(static_cast<double>((float)1.) / (static_cast<double>(tp) + (float)
				    1.));
/* SOURCE culvertb.for:2223 */
/*<       endif >*/
			}
/* SOURCE culvertb.for:2224 */
/*<       bt61t6=a3full/a3part >*/
			xs3com_1.bt61t6 = static_cast<double>(xs3com_1.a3full) / typlim_1.a3part;
/* SOURCE culvertb.for:2225 */
/*<       ap61t6=(bt61t6)**2 >*/
/* Computing 2nd power */
			feq_gen_r_d_1 = xs3com_1.bt61t6;
			xs3com_1.ap61t6 = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE culvertb.for:2226 */
/*<       write(stdout,88)z1ty61,(z1ty61-zb2)/dup >*/
			feq_gen_io_d__219.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__219);
			do_fio(&feq_gen_c_d_1, (char *)&xs1com_1.z1ty61, (ftnlen)
				sizeof(real));
			feq_gen_r_d_1 = static_cast<double>((static_cast<double>(xs1com_1.z1ty61) - xs2com_1.zb2)) / dup;
			do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
			e_wsfe();
/* SOURCE culvertb.for:2227 */
/*<       write(stdout,90)cd61t6,bt61t6,ap61t6 >*/
			feq_gen_io_d__220.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__220);
			do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.cd61t6, (ftnlen)
				sizeof(real));
			do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.bt61t6, (ftnlen)
				sizeof(real));
			do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.ap61t6, (ftnlen)
				sizeof(real));
			e_wsfe();
/* SOURCE culvertb.for:2228 */
/*<       endif >*/
		    }
/* SOURCE culvertb.for:2229 */
/*<       endif >*/
		}
/* SOURCE culvertb.for:2230 */
/*<       else >*/
	    } else {
/*           High head type is type 5.  Compute parameters for */
/*           transition from type 2 to type 5.  Force the type 5 */
/*           flow equation to match the limiting type 2 flow by */
/*           computing a contraction coefficient for that purpose. */
/* SOURCE culvertb.for:2236 */
/*<       callfndcc2(stdout,dup,zbvec(iat3d),cc2t5) >*/
		fndcc2_(stdout, &dup, &culcom_1.zbvec[culcom_1.iat3d - 1], &
			xs3com_1.cc2t5);
/*            WRITE(STDOUT,*) ' FRFT2: CC2T5=',CC2T5 */
/*           Compute the profile to the end of the barrel */
/* SOURCE culvertb.for:2243 */
/*<       yvc=dup*yoverd(nsec(iat3d),dup,a2full,cc2t5) >*/
		yvc = dup * yoverd_(&culcom_1.nsec[culcom_1.iat3d - 1], &dup, 
			&xs2com_1.a2full, &xs3com_1.cc2t5);
/* SOURCE culvertb.for:2245 */
/*<       ty6lss=((1.0/c46**2-1.0))*(q2l/a2full)**2/grav2 >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = cdcom_1.c46;
/* Computing 2nd power */
		feq_gen_r_d_2 = static_cast<double>(typlim_1.q2l) / xs2com_1.a2full;
		ty6lss = static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - (float)1.)) * (static_cast<double>(feq_gen_r_d_2) * 
			feq_gen_r_d_2)) / grvcom_1.grav2;
/* SOURCE culvertb.for:2247 */
/*<       calllktqc(nsec(iat3d),yvc,qc) >*/
		lktqc_(&culcom_1.nsec[culcom_1.iat3d - 1], &yvc, &qc);
/*            WRITE(STDOUT,*) ' FRFT2: DEPTH AT VC=',YVC,' FROUDE=',Q2L/QC */
/* SOURCE culvertb.for:2252 */
/*<       ycat3=y3lty2 >*/
		ycat3 = xs3com_1.y3lty2;
/*            WRITE(STDOUT,*) ' CRITICAL DEPTH AT SEC. 3=',YCAT3 */
/* SOURCE culvertb.for:2254 */
/*<        >*/
		supsub_(stdout, &culcom_1.iat3d, id, &yvc, &xs3com_1.y3lty2, &
			typlim_1.q2l, &dup, &ycat3, &ty6lss, &zat3, &zat43, 
			jmploc, (ftnlen)32);
/*            WRITE(STDOUT,*) ' JMPLOC=',JMPLOC */
/* SOURCE culvertb.for:2260 */
/*<       z1ty52=z1ty2 >*/
		xs1com_1.z1ty52 = xs1com_1.z1ty2;
/*            Y3LTY5 = DDN*TY5SBF */
/* SOURCE culvertb.for:2262 */
/*<       y3ty52=zat3-zb3 >*/
		xs3com_1.y3ty52 = static_cast<double>(zat3) - xs3com_1.zb3;
/*           Compute a value of beta to apply to the type 5 equation */
/*           results that will closely match the type 2 equation */
/*           at the boundary between them. */
/* SOURCE culvertb.for:2267 */
/*<       calllkta(adrxs3,y3ty52,a) >*/
		lkta_(&xs3com_1.adrxs3, &xs3com_1.y3ty52, &a);
/* SOURCE culvertb.for:2271 */
/*<       bt2t5=a/a3part >*/
		xs3com_1.bt2t5 = static_cast<double>(a) / typlim_1.a3part;
/* SOURCE culvertb.for:2272 */
/*<       ap2t5=(a/a3part)**2 >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = static_cast<double>(a) / typlim_1.a3part;
		xs3com_1.ap2t5 = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE culvertb.for:2274 */
/*<       write(stdout,92)cc2t5,bt2t5,ap2t5,y3ty52 >*/
		feq_gen_io_d__229.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__229);
		do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.cc2t5, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.bt2t5, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.ap2t5, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.y3ty52, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE culvertb.for:2275 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:2276 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:2277 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:2280 */
/*<       maxarg=fmxarg(adrxs2) >*/
    rty2c_1.maxarg = fmxarg_(&xs2com_1.adrxs2);
/*     DEFINE THE TRUE VALUES AT SECTION 1 */
/* SOURCE culvertb.for:2283 */
/*<       z1true=hdatum+hup >*/
    rty2c_1.z1true = static_cast<double>(*hdatum) + *hup;
/*     Type 2 flow may occur under a variety of cases.  There */
/*     are three levels at section 1 that are involved.  Z1TY1L */
/*     gives the lower limit for type 1 flow.  This is taken */
/*     to be the upper limit for type 2 flow.  Z1TY1 gives the */
/*     upper limt for type 1 flow.  Between Z1TY1L and Z1TY1 the */
/*     flow is type 1.  The last level is Z1TY2 giving the upper */
/*     limit for type 2 flow.  The upper level for type 1 flow is */
/*     complex.  If it is defined by critical slope, then there */
/*     may be type 2 flow at levels above it.  However, the critical */
/*     slope definition can lead to nonsense for pipe culverts */
/*     because the depth in the barrel is so close to the soffit */
/*     and the critical flow is so large that the water surface */
/*     elevation at section 1 becomes so large that the entrance */
/*     will be flowing full.  This happens because critical flow */
/*     loses its physical meaning as the soffit is approached in */
/*     a closed conduit that has converging walls.  The mathematical */
/*     meaning still exists and with the slot in the top, FEQUTL */
/*     should always be able to find a critical slope that will */
/*     exceed any bottom slope encounted in the field. */
/*     In principle the lower limit for type 1 flow should always */
/*     exist also because the critical slope approaches infinity */
/*     as the depth in the barrel approaches zero.  The minimum */
/*     depth tabulated for a closed conduit is 0.08 or less. */
/*     Flow depths this small are of little interest.  Therefore, */
/*     the lower limit for type 1 flow may not always be computed */
/*     even though it may exist.  The lower limit may not */
/*     exist because the flow at that level is type 0 and not */
/*     type 1.  Thus non-existence of the lower level is not */
/*     an error! */
/* SOURCE culvertb.for:2315 */
/*<       icase=0 >*/
    icase = 0;
/* SOURCE culvertb.for:2316 */
/*<       if(z1ty1l.gt.zb1)then >*/
    if (xs1com_1.z1ty1l > xs1com_1.zb1) {
/*       Lower limit for type 1 flow exists. */
/* SOURCE culvertb.for:2318 */
/*<       icase=icase+1 >*/
	++icase;
/* SOURCE culvertb.for:2319 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:2320 */
/*<       if(z1ty1.gt.zb1)then >*/
    if (xs1com_1.z1ty1 > xs1com_1.zb1) {
/*       Upper limit for type 1 flow exists. */
/* SOURCE culvertb.for:2322 */
/*<       icase=icase+2 >*/
	icase += 2;
/* SOURCE culvertb.for:2323 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:2324 */
/*<       if(z1ty2.gt.zb1)then >*/
    if (xs1com_1.z1ty2 > xs1com_1.zb1) {
/*       Upper limit for type 2 flow exists. */
/* SOURCE culvertb.for:2326 */
/*<       icase=icase+4 >*/
	icase += 4;
/* SOURCE culvertb.for:2327 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' FRFT2: CASE=',ICASE */
/*     There are 8 outcomes: 0 through 7.  Not all are possible here */
/*     but check for them all to find bugs. */
/* SOURCE culvertb.for:2331 */
/*<       if(icase.eq.0)then >*/
    if (icase == 0) {
/*       None of the limits exist. */
/* SOURCE culvertb.for:2333 */
/*<       type=6 >*/
	*feq_gen_type_d_ = 6;
/* SOURCE culvertb.for:2334 */
/*<       return >*/
	return 0;
/* SOURCE culvertb.for:2335 */
/*<       elseif(icase.eq.1)then >*/
    } else if (icase == 1) {
/*       Should not happen.  No upper limit for type 1 but there */
/*       is a lower limit.  Nonsense! */
/* SOURCE culvertb.for:2338 */
/*<       write(stdout,*)' *BUG:XXX* ICASE=1 IN FRFT2.' >*/
	feq_gen_io_d__231.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__231);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* ICASE=1 IN FRFT2."), (ftnlen)28);
	e_wsle();
/* SOURCE culvertb.for:2339 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:2340 */
/*<       elseif(icase.eq.2)then >*/
    } else if (icase == 2) {
/*       Should not happen.  Only upper limit for type 1 exists. */
/*       Type 2 flow should not occur but here we are in FRFT2! */
/* SOURCE culvertb.for:2343 */
/*<       write(stdout,*)' *BUG:XXX* ICASE=2 IN FRFT2.' >*/
	feq_gen_io_d__232.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__232);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* ICASE=2 IN FRFT2."), (ftnlen)28);
	e_wsle();
/* SOURCE culvertb.for:2344 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:2345 */
/*<       elseif(icase.eq.3)then >*/
    } else if (icase == 3) {
/*       Both type 1 limits exist. Type 2 upper limit does not. */
/* SOURCE culvertb.for:2347 */
/*<       if(z1true.gt.z1ty1l)then >*/
	if (rty2c_1.z1true > xs1com_1.z1ty1l) {
/*         Type 1 elevation in FRFT2!  Happens if we go above */
/*         the upper limit for type 1 but we cannot find a type 2 */
/*         limit above the upper type 1 and a lower type 1 limit */
/*         exists. */
/* SOURCE culvertb.for:2352 */
/*<       write(stdout,82)hup,z1ty1l-hdatum >*/
	    feq_gen_io_d__233.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__233);
	    do_fio(&feq_gen_c_d_1, (char *)&(*hup), (ftnlen)sizeof(real));
	    feq_gen_r_d_1 = static_cast<double>(xs1com_1.z1ty1l) - *hdatum;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culvertb.for:2353 */
/*<        >*/
	    feq_gen_io_d__234.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__234);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FRFT2: Type 2 appears impossible."), (
		    ftnlen)34);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("   Trying high-head option"), (ftnlen)26);
	    e_wsle();
/* SOURCE culvertb.for:2355 */
/*<       type=6 >*/
	    *feq_gen_type_d_ = 6;
/* SOURCE culvertb.for:2356 */
/*<       return >*/
	    return 0;
/* SOURCE culvertb.for:2357 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:2358 */
/*<       elseif(icase.eq.4)then >*/
    } else if (icase == 4) {
/*       Only type 2 upper limit exists. */
/* SOURCE culvertb.for:2360 */
/*<       if(z1true.gt.z1ty2)then >*/
	if (rty2c_1.z1true > xs1com_1.z1ty2) {
/* SOURCE culvertb.for:2361 */
/*<       type=6 >*/
	    *feq_gen_type_d_ = 6;
/* SOURCE culvertb.for:2362 */
/*<       return >*/
	    return 0;
/* SOURCE culvertb.for:2363 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:2364 */
/*<       elseif(icase.eq.5)then >*/
    } else if (icase == 5) {
/*       Should not happen.  No upper limit for type 1 but there is */
/*       a lower limit. */
/* SOURCE culvertb.for:2367 */
/*<       write(stdout,*)' *BUG:XXX* ICASE=5 IN FRFT2.' >*/
	feq_gen_io_d__235.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__235);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* ICASE=5 IN FRFT2."), (ftnlen)28);
	e_wsle();
/* SOURCE culvertb.for:2368 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:2369 */
/*<       elseif(icase.eq.6)then >*/
    } else if (icase == 6) {
/*       Both the type 1 upper limit and the type 2 upper limit exist. */
/*       The lower type 1 limit does not. */
/* SOURCE culvertb.for:2372 */
/*<       if(z1ty2.lt.z1ty1)then >*/
	if (xs1com_1.z1ty2 < xs1com_1.z1ty1) {
/*         Should not happen. */
/* SOURCE culvertb.for:2374 */
/*<       write(stdout,*)' Z1TY2=',z1ty2,' Z1TY1=',z1ty1 >*/
	    feq_gen_io_d__236.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__236);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Z1TY2="), (ftnlen)7);
	    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&xs1com_1.z1ty2, (ftnlen)sizeof(real)
		    );
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Z1TY1="), (ftnlen)7);
	    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&xs1com_1.z1ty1, (ftnlen)sizeof(real)
		    );
	    e_wsle();
/* SOURCE culvertb.for:2375 */
/*<        >*/
	    feq_gen_io_d__237.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__237);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* ICASE=6 IN FRFT2. INVALID"), (
		    ftnlen)36);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" LIMIT RELATIONSHIP."), (ftnlen)20);
	    e_wsle();
/* SOURCE culvertb.for:2377 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/*        ELSEIF(Z1TRUE.LT.Z1TY1) THEN */
/*         WRITE(STDOUT,*) ' *BUG:XXX* ICASE=6 IN FRFT2. INVALID', */
/*     A           ' ELEVATION.' */
/*         STOP 'Abnormal stop. Errors found.' */
/* SOURCE culvertb.for:2382 */
/*<       elseif(z1true.ge.z1ty2)then >*/
	} else if (rty2c_1.z1true >= xs1com_1.z1ty2) {
/* SOURCE culvertb.for:2383 */
/*<       type=6 >*/
	    *feq_gen_type_d_ = 6;
/* SOURCE culvertb.for:2384 */
/*<       return >*/
	    return 0;
/* SOURCE culvertb.for:2385 */
/*<       endif >*/
	}
/*       If the current Z1 is between type1 and type 2 limits change */
/*       the first guess. */
/* SOURCE culvertb.for:2388 */
/*<       if(z1true.ge.z1ty1.and.z1true.le.z1ty2)then >*/
	if (rty2c_1.z1true >= xs1com_1.z1ty1 && rty2c_1.z1true <= 
		xs1com_1.z1ty2) {
/* SOURCE culvertb.for:2389 */
/*<       fg=y3lty1+(z1true-z1ty1)*(y3lty2-y3lty1)/(z1ty2-z1ty1) >*/
	    *fg = static_cast<double>(xs3com_1.y3lty1) + static_cast<double>(static_cast<double>((static_cast<double>(rty2c_1.z1true) - xs1com_1.z1ty1)) * (
		    static_cast<double>(xs3com_1.y3lty2) - xs3com_1.y3lty1)) / (static_cast<double>(xs1com_1.z1ty2) - 
		    xs1com_1.z1ty1);
/* SOURCE culvertb.for:2391 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:2392 */
/*<       elseif(icase.eq.7)then >*/
    } else if (icase == 7) {
/*       All three limits exist. */
/* SOURCE culvertb.for:2394 */
/*<       if(z1ty2.lt.z1ty1)then >*/
	if (xs1com_1.z1ty2 < xs1com_1.z1ty1) {
/*         Should not happen. */
/* SOURCE culvertb.for:2396 */
/*<        >*/
	    feq_gen_io_d__238.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__238);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* ICASE=7 IN FRFT2. INVALID"), (
		    ftnlen)36);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" LIMIT RELATIONSHIP."), (ftnlen)20);
	    e_wsle();
/* SOURCE culvertb.for:2398 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:2399 */
/*<       elseif(z1true.gt.z1ty1l.and.z1true.le.z1ty1)then >*/
	} else if (rty2c_1.z1true > xs1com_1.z1ty1l && rty2c_1.z1true <= 
		xs1com_1.z1ty1) {
/*         Should not be here.  Type 1 exists and the elevation */
/*         is in type 1 range. */
/* SOURCE culvertb.for:2402 */
/*<        >*/
	    feq_gen_io_d__239.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__239);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* ICASE=7 IN FRFT2. TYPE 1"), (
		    ftnlen)35);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" ELEVATION APPEARS."), (ftnlen)19);
	    e_wsle();
/* SOURCE culvertb.for:2404 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:2405 */
/*<       elseif(z1true.gt.z1ty2)then >*/
	} else if (rty2c_1.z1true > xs1com_1.z1ty2) {
/* SOURCE culvertb.for:2406 */
/*<       type=6 >*/
	    *feq_gen_type_d_ = 6;
/* SOURCE culvertb.for:2407 */
/*<       return >*/
	    return 0;
/* SOURCE culvertb.for:2408 */
/*<       endif >*/
	}
/*       If the current Z1 is between type1 and type 2 limits change */
/*       the first guess. */
/* SOURCE culvertb.for:2411 */
/*<       if(z1true.ge.z1ty1.and.z1true.le.z1ty2)then >*/
	if (rty2c_1.z1true >= xs1com_1.z1ty1 && rty2c_1.z1true <= 
		xs1com_1.z1ty2) {
/* SOURCE culvertb.for:2412 */
/*<       fg=y3lty1+(z1true-z1ty1)*(y3lty2-y3lty1)/(z1ty2-z1ty1) >*/
	    *fg = static_cast<double>(xs3com_1.y3lty1) + static_cast<double>(static_cast<double>((static_cast<double>(rty2c_1.z1true) - xs1com_1.z1ty1)) * (
		    static_cast<double>(xs3com_1.y3lty2) - xs3com_1.y3lty1)) / (static_cast<double>(xs1com_1.z1ty2) - 
		    xs1com_1.z1ty1);
/* SOURCE culvertb.for:2414 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:2415 */
/*<       else >*/
    } else {
/* SOURCE culvertb.for:2416 */
/*<       write(stdout,*)' *BUG:XXX* ICASE ERROR. OUTSIDE RANGE 0:7' >*/
	feq_gen_io_d__240.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__240);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* ICASE ERROR. OUTSIDE RANGE 0:7"), (
		ftnlen)41);
	e_wsle();
/* SOURCE culvertb.for:2417 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:2418 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:2420 */
/*<       hw=z1true-zb2 >*/
    hw = static_cast<double>(rty2c_1.z1true) - xs2com_1.zb2;
/* SOURCE culvertb.for:2421 */
/*<       r=hw/dup >*/
    feq_gen_r_d_ = static_cast<double>(hw) / dup;
/* SOURCE culvertb.for:2422 */
/*<       if(r.gt.1.5)then >*/
    if (feq_gen_r_d_ > (float)1.5) {
/*       HEAD WATER RATIO TOO LARGE FOR TYPE 2 */
/*        WRITE(STDOUT,*) ' FRFT2: HEAD WATER RATIO=',R,' > 1.5' */
/* SOURCE culvertb.for:2425 */
/*<       type=6 >*/
	*feq_gen_type_d_ = 6;
/* SOURCE culvertb.for:2426 */
/*<       return >*/
	return 0;
/* SOURCE culvertb.for:2427 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:2428 */
/*<       y1=z1true-zb1 >*/
    xs1com_1.y1 = static_cast<double>(rty2c_1.z1true) - xs1com_1.zb1;
/* SOURCE culvertb.for:2429 */
/*<        >*/
    xlktal_(&xs1com_1.adrxs1, &xs1com_1.y1, &rty2c_1.a1true, &xs1com_1.t1, &
	    xs1com_1.dt1, &xs1com_1.j1, &xs1com_1.k1, &xs1com_1.dk1, &
	    xs1com_1.bet1, &xs1com_1.dbet1, &rty2c_1.alp1tr, &xs1com_1.dalp1);
/*     SET THE SPECIAL COMMON BLOCK VALUES */
/* SOURCE culvertb.for:2436 */
/*<       outun=stdout >*/
    rty2c_1.outun = *stdout;
/* SOURCE culvertb.for:2437 */
/*<       iup=iu >*/
    rty2c_1.iup = *iu;
/* SOURCE culvertb.for:2438 */
/*<       idn=id >*/
    rty2c_1.idn = *id;
/* SOURCE culvertb.for:2439 */
/*<       class=culcls >*/
    s_copy(rty2cc_1.feq_gen_class_d_, culcls, (ftnlen)8, (ftnlen)8);
/* SOURCE culvertb.for:2440 */
/*<       sbot=(zbvec(id-1)-zbvec(id))/abs(xvec(id-1)-xvec(id)) >*/
    rty2c_1.sbot = (static_cast<double>(culcom_1.zbvec[*id - 2]) - culcom_1.zbvec[*id - 1]) / (
	    feq_gen_r_d_1 = static_cast<double>(culcom_1.xvec[*id - 2]) - culcom_1.xvec[*id - 1], dabs(feq_gen_r_d_1)
	    );
/*     ESTIMATE THE CRITICAL DEPTH AT SECTION 3 AND THEN SEARCH FOR */
/*     A SIGN CHANGE IN THE RESIDUAL. IF Y3 IS TOO LARGE THEN */
/*     THE RESIDUAL IS POSITIVE. */
/* SOURCE culvertb.for:2447 */
/*<       hw=min(z1true-zb2,z1true-zb3) >*/
/* Computing MIN */
    feq_gen_r_d_1 = static_cast<double>(rty2c_1.z1true) - xs2com_1.zb2, feq_gen_r_d_2 = static_cast<double>(rty2c_1.z1true) - 
	    xs3com_1.zb3;
    hw = dmin(feq_gen_r_d_1,feq_gen_r_d_2);
/*      WRITE(STDOUT,*) ' FRFT2: FG=',FG,' Y3FREE=',Y3FREE */
/*     SEARCH FOR A NEGATIVE RESIDUAL */
/* SOURCE culvertb.for:2450 */
/*<       if(fg.gt.0.0)then >*/
    if (*fg > (float)0.) {
/* SOURCE culvertb.for:2451 */
/*<       ylow=fg >*/
	ylow = *fg;
/* SOURCE culvertb.for:2452 */
/*<       else >*/
    } else {
/* SOURCE culvertb.for:2453 */
/*<       if(y3free.gt.0.0)then >*/
	if (xs3com_1.y3free > (float)0.) {
/* SOURCE culvertb.for:2454 */
/*<       ylow=y3free >*/
	    ylow = xs3com_1.y3free;
/* SOURCE culvertb.for:2455 */
/*<       else >*/
	} else {
/* SOURCE culvertb.for:2456 */
/*<       ylow=.3*hw >*/
	    ylow = static_cast<double>(hw) * (float).3;
/* SOURCE culvertb.for:2457 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:2458 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:2459 */
/*<       if(ylow.ge.ddn)then >*/
    if (ylow >= ddn) {
/* SOURCE culvertb.for:2460 */
/*<       ylow=0.8*ddn >*/
	ylow = static_cast<double>(ddn) * (float).8;
/* SOURCE culvertb.for:2461 */
/*<       endif >*/
    }
/*     CHK TO MAKE SURE THAT THIS VALUE OF DEPTH CAN SUSTAIN A */
/*     CRITICAL FLOW */
/* SOURCE culvertb.for:2465 */
/*<       if(sbot.gt.0.0)then >*/
    if (rty2c_1.sbot > (float)0.) {
/* SOURCE culvertb.for:2466 */
/*<       sbot=sqrt(sbot) >*/
	rty2c_1.sbot = sqrt(rty2c_1.sbot);
/*       WRITE(STDOUT,*) ' SQRT(SBOT)=',SBOT */
/* SOURCE culvertb.for:2468 */
/*<   105 continue >*/
L105:
/*         FIND CRITICAL FLOW AT SECTION 3 */
/*         GET VALUES AT SECTION 3 */
/* SOURCE culvertb.for:2471 */
/*<        >*/
	xlkt22_(&xs3com_1.adrxs3, &ylow, &xs3com_1.a3, &xs3com_1.t3, &
		xs3com_1.dt3, &xs3com_1.j3, &xs3com_1.k3, &xs3com_1.dk3, &
		xs3com_1.bet3, &xs3com_1.dbet3, &xs3com_1.alp3, &
		xs3com_1.dalp3, &xs3com_1.q3c);
/*         COMPUTE THE NORMAL FLOW AT THIS DEPTH. */
/* SOURCE culvertb.for:2478 */
/*<       qn=k3*sbot >*/
	qn = static_cast<double>(xs3com_1.k3) * rty2c_1.sbot;
/*         WRITE(STDOUT,*) ' YLOW=',YLOW,' Q3C=',Q3C,' QN=',QN */
/* SOURCE culvertb.for:2481 */
/*<       if(qn.gt.q3c)then >*/
	if (qn > xs3com_1.q3c) {
/* SOURCE culvertb.for:2482 */
/*<       ylow=0.9*ylow >*/
	    ylow *= static_cast<double>((float).9);
/* SOURCE culvertb.for:2483 */
/*<       if(ylow.lt.epsarg)then >*/
	    if (ylow < epscom_1.epsarg) {
/* SOURCE culvertb.for:2484 */
/*<       write(stdout,*)' CRITICAL FLOW IMPOSSIBLE FOR TYPE 2.' >*/
		feq_gen_io_d__245.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__245);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" CRITICAL FLOW IMPOSSIBLE FOR TYPE 2."), 
			(ftnlen)37);
		e_wsle();
/* SOURCE culvertb.for:2485 */
/*<       write(stdout,*)' POSSIBLE ERROR IN TYPE 1 CHK.' >*/
		feq_gen_io_d__246.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__246);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" POSSIBLE ERROR IN TYPE 1 CHK."), (
			ftnlen)30);
		e_wsle();
/* SOURCE culvertb.for:2486 */
/*<       type=1 >*/
		*feq_gen_type_d_ = 1;
/* SOURCE culvertb.for:2487 */
/*<       return >*/
		return 0;
/* SOURCE culvertb.for:2488 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:2489 */
/*<       goto105 >*/
	    goto L105;
/* SOURCE culvertb.for:2490 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:2491 */
/*<       fg=ylow >*/
	*fg = ylow;
/* SOURCE culvertb.for:2492 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:2494 */
/*<       yhigh=0.0 >*/
    yhigh = (float)0.;
/* SOURCE culvertb.for:2495 */
/*<       fhigh=1000. >*/
    fhigh = (float)1e3;
/* SOURCE culvertb.for:2496 */
/*<       knt=0 >*/
    knt = 0;
/* SOURCE culvertb.for:2497 */
/*<   100 continue >*/
L100:
/* SOURCE culvertb.for:2498 */
/*<       flow=rty2(ylow) >*/
    flow = rty2_(&ylow);
/* SOURCE culvertb.for:2499 */
/*<       if(sbflag.eq.3)then >*/
    if (rty2c_1.sbflag == 3) {
/* SOURCE culvertb.for:2500 */
/*<       write(stdout,70) >*/
	feq_gen_io_d__251.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__251);
	e_wsfe();
/* SOURCE culvertb.for:2501 */
/*<       if(z1true.le.z1ty1l)then >*/
	if (rty2c_1.z1true <= xs1com_1.z1ty1l) {
/*           We are below the lower limit for the type 1 flow */
/*           region.  We may be close to that limit and no */
/*           solution may exist for type 2 flow close to this */
/*           limit. */
/* SOURCE culvertb.for:2506 */
/*<       write(stdout,80)hup,z1ty1l-hdatum >*/
	    feq_gen_io_d__252.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__252);
	    do_fio(&feq_gen_c_d_1, (char *)&(*hup), (ftnlen)sizeof(real));
	    feq_gen_r_d_1 = static_cast<double>(xs1com_1.z1ty1l) - *hdatum;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culvertb.for:2507 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:2508 */
/*<       type=6 >*/
	*feq_gen_type_d_ = 6;
/* SOURCE culvertb.for:2509 */
/*<       return >*/
	return 0;
/* SOURCE culvertb.for:2510 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:2511 */
/*<       if(sbflag.eq.2)then >*/
    if (rty2c_1.sbflag == 2) {
/*         Profile failure.  Assume that the flow has been made too */
/*         small. */
/* SOURCE culvertb.for:2514 */
/*<       if(yhigh.gt.0.0)then >*/
	if (yhigh > (float)0.) {
/*           A residual has already been found and it is positive. */
/* SOURCE culvertb.for:2516 */
/*<       yt=0.5*(yhigh+ylow) >*/
	    yt = static_cast<double>((static_cast<double>(yhigh) + ylow)) * (float).5;
/* SOURCE culvertb.for:2517 */
/*<       else >*/
	} else {
/* SOURCE culvertb.for:2518 */
/*<       yt=1.05*ylow >*/
	    yt = static_cast<double>(ylow) * (float)1.05;
/* SOURCE culvertb.for:2519 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:2520 */
/*<       if(yt.gt.ddn)then >*/
	if (yt > ddn) {
/* SOURCE culvertb.for:2521 */
/*<       yt=.5*(ylow+ddn) >*/
	    yt = static_cast<double>((static_cast<double>(ylow) + ddn)) * (float).5;
/* SOURCE culvertb.for:2522 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:2523 */
/*<       ylow=yt >*/
	ylow = yt;
/* SOURCE culvertb.for:2524 */
/*<       knt=knt+1 >*/
	++knt;
/* SOURCE culvertb.for:2525 */
/*<       if(knt.gt.100)then >*/
	if (knt > 100) {
/* SOURCE culvertb.for:2526 */
/*<       write(stdout,*)' Profile failure for Type 2 flow.' >*/
	    feq_gen_io_d__254.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__254);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Profile failure for Type 2 flow."), (ftnlen)
		    33);
	    e_wsle();
/* SOURCE culvertb.for:2527 */
/*<       write(stdout,*)' While increasing critical depth.' >*/
	    feq_gen_io_d__255.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__255);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" While increasing critical depth."), (ftnlen)
		    33);
	    e_wsle();
/* SOURCE culvertb.for:2528 */
/*<       if(yhigh.gt.0.0.and.abs(fhigh).lt.epsdif)then >*/
	    if (yhigh > (float)0. && dabs(fhigh) < epscom_1.epsdif) {
/* SOURCE culvertb.for:2529 */
/*<       write(outun,68)fhigh >*/
		feq_gen_io_d__256.ciunit = rty2c_1.outun;
		s_wsfe(&feq_gen_io_d__256);
		do_fio(&feq_gen_c_d_1, (char *)&fhigh, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE culvertb.for:2530 */
/*<       goto200 >*/
		goto L200;
/* SOURCE culvertb.for:2531 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:2532 */
/*<       if(z1true.le.z1ty1l)then >*/
	    if (rty2c_1.z1true <= xs1com_1.z1ty1l) {
/*             We are below the lower limit for the type 1 flow */
/*             region.  We may be close to that limit and no */
/*             solution may exist for type 2 flow close to this */
/*             limit. */
/* SOURCE culvertb.for:2537 */
/*<       write(stdout,80)hup,z1ty1l-hdatum >*/
		feq_gen_io_d__257.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__257);
		do_fio(&feq_gen_c_d_1, (char *)&(*hup), (ftnlen)sizeof(real));
		feq_gen_r_d_1 = static_cast<double>(xs1com_1.z1ty1l) - *hdatum;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE culvertb.for:2538 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:2539 */
/*<       if(y2.ge.dup)then >*/
	    if (xs2com_1.y2 >= dup) {
/* SOURCE culvertb.for:2540 */
/*<       write(stdout,70) >*/
		feq_gen_io_d__258.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__258);
		e_wsfe();
/* SOURCE culvertb.for:2541 */
/*<       type=6 >*/
		*feq_gen_type_d_ = 6;
/* SOURCE culvertb.for:2542 */
/*<       return >*/
		return 0;
/* SOURCE culvertb.for:2543 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:2544 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:2545 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:2546 */
/*<       goto100 >*/
	goto L100;
/* SOURCE culvertb.for:2547 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:2548 */
/*<       if(flow.ge.0.0)then >*/
    if (flow >= (float)0.) {
/* SOURCE culvertb.for:2549 */
/*<       yhigh=ylow >*/
	yhigh = ylow;
/* SOURCE culvertb.for:2550 */
/*<       fhigh=flow >*/
	fhigh = flow;
/* SOURCE culvertb.for:2551 */
/*<       ylow=0.95*ylow >*/
	ylow *= static_cast<double>((float).95);
/* SOURCE culvertb.for:2552 */
/*<       if(ylow.le.epsarg)then >*/
	if (ylow <= epscom_1.epsarg) {
/*           A NEGATIVE RESIDUAL SHOULD BE FOUND. */
/* SOURCE culvertb.for:2554 */
/*<       write(stdout,58) >*/
	    feq_gen_io_d__259.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__259);
	    e_wsfe();
/* SOURCE culvertb.for:2555 */
/*<       freed=0.0 >*/
	    *freed = (float)0.;
/* SOURCE culvertb.for:2556 */
/*<       qfree=q3 >*/
	    *qfree = xs3com_1.q3;
/* SOURCE culvertb.for:2557 */
/*<       type=5 >*/
	    *feq_gen_type_d_ = 5;
/* SOURCE culvertb.for:2558 */
/*<       return >*/
	    return 0;
/* SOURCE culvertb.for:2559 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:2560 */
/*<       goto100 >*/
	goto L100;
/* SOURCE culvertb.for:2561 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:2562 */
/*<       if(yhigh.eq.0.0)then >*/
    if (yhigh == (float)0.) {
/*       MUST SEARCH FOR POSTIVE RESIDUAL BECAUSE NONE FOUND WHEN */
/*       SEARCHING FOR A NEGATIVE RESIDUAL.  YLOW is defined here */
/*       so start with it. */
/* SOURCE culvertb.for:2567 */
/*<       yhigh=1.05*ylow >*/
	yhigh = static_cast<double>(ylow) * (float)1.05;
/* SOURCE culvertb.for:2568 */
/*<       if(yhigh.gt.ddn)then >*/
	if (yhigh > ddn) {
/* SOURCE culvertb.for:2569 */
/*<       yhigh=0.5*(ylow+yhigh) >*/
	    yhigh = static_cast<double>((static_cast<double>(ylow) + yhigh)) * (float).5;
/* SOURCE culvertb.for:2570 */
/*<       endif >*/
	}
/*        WRITE(STDOUT,*) ' FRFT2: SEARCH FOR POSITIVE RESID. YHIGH=', */
/*     A                   YHIGH */
/* SOURCE culvertb.for:2573 */
/*<       knt=0 >*/
	knt = 0;
/* SOURCE culvertb.for:2574 */
/*<   110 continue >*/
L110:
/* SOURCE culvertb.for:2575 */
/*<       fhigh=rty2(yhigh) >*/
	fhigh = rty2_(&yhigh);
/* SOURCE culvertb.for:2576 */
/*<       if(sbflag.eq.3)then >*/
	if (rty2c_1.sbflag == 3) {
/* SOURCE culvertb.for:2577 */
/*<       write(stdout,70) >*/
	    feq_gen_io_d__260.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__260);
	    e_wsfe();
/* SOURCE culvertb.for:2578 */
/*<       if(z1true.le.z1ty1l)then >*/
	    if (rty2c_1.z1true <= xs1com_1.z1ty1l) {
/*             We are below the lower limit for the type 1 flow */
/*             region.  We may be close to that limit and no */
/*             solution may exist for type 2 flow close to this */
/*             limit. */
/* SOURCE culvertb.for:2583 */
/*<       write(stdout,80)hup,z1ty1l-hdatum >*/
		feq_gen_io_d__261.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__261);
		do_fio(&feq_gen_c_d_1, (char *)&(*hup), (ftnlen)sizeof(real));
		feq_gen_r_d_1 = static_cast<double>(xs1com_1.z1ty1l) - *hdatum;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE culvertb.for:2584 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:2585 */
/*<       type=6 >*/
	    *feq_gen_type_d_ = 6;
/* SOURCE culvertb.for:2586 */
/*<       return >*/
	    return 0;
/* SOURCE culvertb.for:2587 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:2588 */
/*<       if(sbflag.eq.2)then >*/
	if (rty2c_1.sbflag == 2) {
/*           Profile failure.  Assume that flow is still too small. */
/* SOURCE culvertb.for:2590 */
/*<       yt=1.05*yhigh >*/
	    yt = static_cast<double>(yhigh) * (float)1.05;
/* SOURCE culvertb.for:2591 */
/*<       if(yt.gt.ddn)then >*/
	    if (yt > ddn) {
/* SOURCE culvertb.for:2592 */
/*<       yt=0.5*(yhigh+ddn) >*/
		yt = static_cast<double>((static_cast<double>(yhigh) + ddn)) * (float).5;
/* SOURCE culvertb.for:2593 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:2594 */
/*<       yhigh=yt >*/
	    yhigh = yt;
/* SOURCE culvertb.for:2595 */
/*<       knt=knt+1 >*/
	    ++knt;
/* SOURCE culvertb.for:2596 */
/*<       if(yhigh-ddn.ge.epsabs.or.knt.gt.100)then >*/
	    if (static_cast<double>(yhigh) - ddn >= epscom_1.epsabs || knt > 100) {
/* SOURCE culvertb.for:2597 */
/*<       write(stdout,*)' Profile failure for Type 2 flow.' >*/
		feq_gen_io_d__262.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__262);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Profile failure for Type 2 flow."), (
			ftnlen)33);
		e_wsle();
/* SOURCE culvertb.for:2598 */
/*<       write(stdout,*)' While increasing critical depth' >*/
		feq_gen_io_d__263.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__263);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" While increasing critical depth"), (
			ftnlen)32);
		e_wsle();
/* SOURCE culvertb.for:2599 */
/*<       write(stdout,*)' searching for positive residual.' >*/
		feq_gen_io_d__264.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__264);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" searching for positive residual."), (
			ftnlen)33);
		e_wsle();
/* SOURCE culvertb.for:2600 */
/*<       write(stdout,*)' Probable program failure.' >*/
		feq_gen_io_d__265.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__265);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Probable program failure."), (ftnlen)26)
			;
		e_wsle();
/* SOURCE culvertb.for:2601 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:2602 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:2603 */
/*<       goto110 >*/
	    goto L110;
/* SOURCE culvertb.for:2604 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:2605 */
/*<       if(fhigh.le.0.0)then >*/
	if (fhigh <= (float)0.) {
/* SOURCE culvertb.for:2606 */
/*<       flow=fhigh >*/
	    flow = fhigh;
/* SOURCE culvertb.for:2607 */
/*<       ylow=yhigh >*/
	    ylow = yhigh;
/* SOURCE culvertb.for:2608 */
/*<       yhigh=0.98*yhigh+0.02*ddn >*/
	    yhigh = static_cast<double>(static_cast<double>(yhigh) * (float).98) + static_cast<double>(ddn) * (float).02;
/* SOURCE culvertb.for:2609 */
/*<       if(abs(yhigh-ddn).le.epsarg)then >*/
	    if ((feq_gen_r_d_1 = static_cast<double>(yhigh) - ddn, dabs(feq_gen_r_d_1)) <= epscom_1.epsarg) {
/* SOURCE culvertb.for:2610 */
/*<       write(stdout,56) >*/
		feq_gen_io_d__266.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__266);
		e_wsfe();
/* SOURCE culvertb.for:2611 */
/*<       freed=0.0 >*/
		*freed = (float)0.;
/* SOURCE culvertb.for:2612 */
/*<       qfree=q3 >*/
		*qfree = xs3com_1.q3;
/* SOURCE culvertb.for:2613 */
/*<       type=5 >*/
		*feq_gen_type_d_ = 5;
/* SOURCE culvertb.for:2614 */
/*<       return >*/
		return 0;
/* SOURCE culvertb.for:2615 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:2616 */
/*<       goto110 >*/
	    goto L110;
/* SOURCE culvertb.for:2617 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:2618 */
/*<       endif >*/
    }
/*     WE NOW HAVE A SIGN CHANGE IN (YLOW, YHIGH) */
/*      WRITE(STDOUT,*) ' YLOW=',YLOW,' FLOW=',FLOW */
/*      WRITE(STDOUT,*) ' YHIGH=',YHIGH,' FHIGH=',FHIGH */
/* SOURCE culvertb.for:2625 */
/*<       callrgf(epsarg,epsabs,rty2,ylow,yhigh,flow,fhigh,y3,flag) >*/
    rgf_(&epscom_1.epsarg, &epscom_1.epsabs, rty2_, &ylow, &yhigh, &
	    flow, &fhigh, &xs3com_1.y3, &feq_gen_flag_d_);
/* SOURCE culvertb.for:2629 */
/*<       if(flag.eq.1)then >*/
    if (feq_gen_flag_d_ == 1) {
/* SOURCE culvertb.for:2630 */
/*<       write(stdout,50) >*/
	feq_gen_io_d__268.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__268);
	e_wsfe();
/* SOURCE culvertb.for:2631 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:2632 */
/*<       elseif(flag.eq.2)then >*/
    } else if (feq_gen_flag_d_ == 2) {
/* SOURCE culvertb.for:2633 */
/*<       write(stdout,60) >*/
	feq_gen_io_d__269.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__269);
	e_wsfe();
/* SOURCE culvertb.for:2634 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:2635 */
/*<       elseif(flag.eq.3)then >*/
    } else if (feq_gen_flag_d_ == 3) {
/*       SUBCRITICAL PROFILE NOT POSSIBLE. THUS TRY TYPE 6 */
/* SOURCE culvertb.for:2637 */
/*<       write(stdout,70) >*/
	feq_gen_io_d__270.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__270);
	e_wsfe();
/* SOURCE culvertb.for:2638 */
/*<       if(z1true.le.z1ty1l)then >*/
	if (rty2c_1.z1true <= xs1com_1.z1ty1l) {
/*         We are below the lower limit for the type 1 flow */
/*         region.  We may be close to that limit and no */
/*         solution may exist for type 2 flow close to this */
/*         limit. */
/* SOURCE culvertb.for:2643 */
/*<       write(stdout,80)hup,z1ty1l-hdatum >*/
	    feq_gen_io_d__271.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__271);
	    do_fio(&feq_gen_c_d_1, (char *)&(*hup), (ftnlen)sizeof(real));
	    feq_gen_r_d_1 = static_cast<double>(xs1com_1.z1ty1l) - *hdatum;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culvertb.for:2644 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:2645 */
/*<       type=6 >*/
	*feq_gen_type_d_ = 6;
/* SOURCE culvertb.for:2646 */
/*<       return >*/
	return 0;
/* SOURCE culvertb.for:2647 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:2649 */
/*<   200 continue >*/
L200:
/* SOURCE culvertb.for:2650 */
/*<       qfree=q3 >*/
    *qfree = xs3com_1.q3;
/* SOURCE culvertb.for:2651 */
/*<       q3free=q3 >*/
    xs3com_1.q3free = xs3com_1.q3;
/* SOURCE culvertb.for:2652 */
/*<       y2free=y2 >*/
    xs2com_1.y2free = xs2com_1.y2;
/* SOURCE culvertb.for:2653 */
/*<       z2=zb2+y2 >*/
    xs2com_1.z2 = static_cast<double>(xs2com_1.zb2) + xs2com_1.y2;
/* SOURCE culvertb.for:2654 */
/*<       y3free=y3 >*/
    xs3com_1.y3free = xs3com_1.y3;
/* SOURCE culvertb.for:2655 */
/*<       lftype=2 >*/
    xs2com_1.lftype = 2;
/* SOURCE culvertb.for:2656 */
/*<       lstype=-1 >*/
    xs2com_1.lstype = -1;
/*      WRITE(STDOUT,*) ' FRFT2: Y3=',Y3,' Q3=',Q3 */
/*     CHK THAT THE RESIDUAL AT POINT OF CONVERGENCE IS SMALL.  RESIDUAL */
/*     IS A DIFFERENCE IN ELEVATION AT SECTION 1 AND IS GIVEN BY FLOW. */
/* SOURCE culvertb.for:2661 */
/*<       if(abs(flow).gt.epsdif)then >*/
    if (dabs(flow) > epscom_1.epsdif) {
/* SOURCE culvertb.for:2662 */
/*<       write(stdout,66)abs(flow),epsdif >*/
	feq_gen_io_d__272.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__272);
	feq_gen_r_d_1 = dabs(flow);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&epscom_1.epsdif, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culvertb.for:2663 */
/*<       if(z1ty1.gt.zb1)then >*/
	if (xs1com_1.z1ty1 > xs1com_1.zb1) {
/* SOURCE culvertb.for:2664 */
/*<       write(stdout,67) >*/
	    feq_gen_io_d__273.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__273);
	    e_wsfe();
/*         Try a high head flow.  We may be trapped near the soffit of */
/*         the conduit where a narrow band of type 2 flow may exist. */
/* SOURCE culvertb.for:2667 */
/*<       type=6 >*/
	    *feq_gen_type_d_ = 6;
/* SOURCE culvertb.for:2668 */
/*<       return >*/
	    return 0;
/* SOURCE culvertb.for:2669 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:2670 */
/*<       endif >*/
    }
/*     NOW COMPUTE THE ELEVATION IN THE DEPARTURE SECTION REQUIRED */
/*     TO DROWN CRITICAL DEPTH AT THE CULVERT EXIT. */
/* SOURCE culvertb.for:2675 */
/*<       z3p=z3 >*/
    xs3com_1.z3p = xs3com_1.z3;
/* SOURCE culvertb.for:2676 */
/*<       z3pest=z3p >*/
    xs3com_1.z3pest = xs3com_1.z3p;
/* SOURCE culvertb.for:2677 */
/*<       calldpm26(stdout,wfrdf,mfrdf,z3,expflg) >*/
    dpm26_(stdout, &rdfcom_1.wfrdf, &rdfcom_1.mfrdf, &xs3com_1.z3, expflg);
/* SOURCE culvertb.for:2682 */
/*<       if(expflg.eq.0)then >*/
    if (*expflg == 0) {
/* SOURCE culvertb.for:2683 */
/*<       return >*/
	return 0;
/* SOURCE culvertb.for:2684 */
/*<       endif >*/
    }
/*     DEPARTURE SECTION VALUES ARE IN XS4COM */
/* SOURCE culvertb.for:2688 */
/*<       freed=z1true-z4 >*/
    *freed = static_cast<double>(rty2c_1.z1true) - xs4com_1.z4;
/* SOURCE culvertb.for:2690 */
/*<       return >*/
    return 0;
/* SOURCE culvertb.for:2692 */
/*<       end >*/
} /* frft2_ */




/* SOURCE culvertb.for:2696 */
/*<       subroutinefndq5(stdout,hdatum,hup,iu,culcls,rbval,qrf,yvc,q5,cc) >*/
/* Subroutine */ int fndq5_(integer *stdout, real *hdatum, real *hup, integer 
	*iu, char *culcls, real *rbval, real *qrf, real *yvc, real *q5, real *
	cc, ftnlen culcls_len)
{
    /* Format strings */
    static char fmt_54[] = "(/,\002 *BUG:XXX* No convergence on Q in subrout\
ine FNDQ5.\002)";

    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    real q, cd, qt, qc1, qc2, den, avc, dup;
    integer knt;
    real num, head, dzvc;
    extern /* Subroutine */ int fndcc_(integer *, real *, real *, integer *, 
	    real *, real *, real *, real *, real *);
    real hdrat;
    extern /* Subroutine */ int xlkt22_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *), fndcd5_(integer *, char *, real *, real *, real *, 
	    ftnlen);
    real headvc, z1true, numfac;
    extern doublereal yoverd_(integer *, real *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__290 = { 0, 0, 0, fmt_54, 0 };


/*     + + + PURPOSE + + + */
/*     Find the type 5 flow rate for the culvert. */
/* SOURCE culvertb.for:2703 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertb.for:2706 */
/*<       integeriu,stdout >*/
/* SOURCE culvertb.for:2707 */
/*<       realcc,hdatum,hup,q5,qrf,rbval,yvc >*/
/* SOURCE culvertb.for:2708 */
/*<       characterculcls*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     HDATUM - Datum for measuring head */
/*     HUP    - Head upstream */
/*     IU     - Index for upstream node for the culvert barrel */
/*     CULCLS - Class for culvert shape, BOX, PIPE, .. */
/*     RBVAL  - rounding/beveling value */
/*     QRF    - Flow over the roadway */
/*     YVC    - depth at vena contracta */
/*     Q5     - free flow of type 5 */
/*     CC     - contraction coefficient */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertb.for:2723 */
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
/* INCLUDE culvertb.for:2724 */
/* SOURCE xs1com.cmn:2 */
/*<        >*/
/* SOURCE xs1com.cmn:7 */
/*<       integeradrxs1 >*/
/* SOURCE xs1com.cmn:9 */
/*<        >*/
/*     Z1TY1- elevation at section 1 at type 1 limit if it exists */
/*     Z1TY1L-elevation at section 1 at lower limit of type 1 if it exists */
/*     Z1TY6- elevation at section 1 at start of type 6 if it exists */
/*     Z1TY2- elevation at upper limit of type 2 flow if it exists */
/*     Z1TY61- elevation at upper limt of type 61 if it exists */
/*     Z1TY5- elevation at section at start of type 5 if it exists */
/*     Z1TY52- elevation at section 1 at lower limit of type 52( */
/*             type 2 to type 5 flow) */
/*     Z1TY51- elevation at section 1 at lower limit of type 51( */
/*             type 1 to type 5 flow) */
/* INCLUDE culvertb.for:2725 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culvertb.for:2726 */
/* SOURCE culcom.cmn:2 */
/*<        >*/
/* SOURCE culcom.cmn:8 */
/*<       integernsec(mnbn),hltab(mnbn),iat3d,iat6d,sbkind,sbshape >*/
/* SOURCE culcom.cmn:10 */
/*<        >*/
/* SOURCE culcom.cmn:16 */
/*<       doubleprecisionfrcfac >*/
/*     FRCFAC- friction factor to give factor for friction losses */
/*             in barrel for non-prismatic full-flow that as well */
/*             as prismatic full flow. */
/*     TY1YTD- maximum ratio of depth to vertical diameter for */
/*             type 1 flow. */
/*     TY1HTD- maximum ratio of head at section 1 relative to */
/*             culvert invert at culvert inlet to the vertical */
/*             diamter of the culvert.  Must be less than 1.5. */
/*     SBKIND- if 0 the slope of the culvert barrel is a constant, */
/*             if 1 the slope of the culvert barrel varies. */
/*     BSHAPE- if 0 the barrel shape is constant, that is, prismatic, */
/*             if 1 the barrel shape is nonprismatic. */
/*     TY5SBF- ratio of depth to vertical diameter of the culvert */
/*             at the exit which causes submergence. */
/* Note:  25 August 2004:  SBSHAPE is apparently not used.  BSHAPE */
/* is but outside of a common block. */
/* INCLUDE culvertb.for:2727 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE culvertb.for:2728 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertb.for:2729 */
/* SOURCE appcom.cmn:2 */
/*<       common/appcom/apptab,appelv,applen,applos,appexp,zertab,zerelv >*/
/* SOURCE appcom.cmn:5 */
/*<       integerapptab,zertab >*/
/* SOURCE appcom.cmn:7 */
/*<       realappelv,applen,applos,appexp,zerelv >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertb.for:2732 */
/*<       integerknt >*/
/* SOURCE culvertb.for:2733 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertb.for:2737 */
/*<       intrinsicabs,sqrt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertb.for:2740 */
/*<       realyoverd >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertb.for:2743 */
/*<       externalfndcc,fndcd5,xlkt22,yoverd >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertb.for:2746 */
/*<    54 format(/,' *BUG:XXX* No convergence on Q in subroutine FNDQ5.') >*/
/* *********************************************************************** */
/* SOURCE culvertb.for:2748 */
/*<       dup=dvec(iu) >*/
/* L54: */
    dup = culcom_1.dvec[*iu - 1];
/* SOURCE culvertb.for:2749 */
/*<        >*/
    xlkt22_(&xs2com_1.adrxs2, &dup, &xs2com_1.a2, &xs2com_1.t2, &xs2com_1.dt2,
	     &xs2com_1.j2, &xs2com_1.k2, &xs2com_1.dk2, &xs2com_1.bet2, &
	    xs2com_1.dbet2, &xs2com_1.alp2, &xs2com_1.dalp2, &qc2);
/* SOURCE culvertb.for:2754 */
/*<       z1true=hdatum+hup >*/
    z1true = static_cast<double>(*hdatum) + *hup;
/* SOURCE culvertb.for:2755 */
/*<       y1=z1true-zb1 >*/
    xs1com_1.y1 = static_cast<double>(z1true) - xs1com_1.zb1;
/* SOURCE culvertb.for:2756 */
/*<        >*/
    xlkt22_(&xs1com_1.adrxs1, &xs1com_1.y1, &xs1com_1.a1, &xs1com_1.t1, &
	    xs1com_1.dt1, &xs1com_1.j1, &xs1com_1.k1, &xs1com_1.dk1, &
	    xs1com_1.bet1, &xs1com_1.dbet1, &xs1com_1.alp1, &xs1com_1.dalp1, &
	    qc1);
/* SOURCE culvertb.for:2761 */
/*<       head=hup+hdatum-zb2 >*/
    head = static_cast<double>(static_cast<double>(*hup) + *hdatum) - xs2com_1.zb2;
/* SOURCE culvertb.for:2763 */
/*<       hdrat=head/dup >*/
    hdrat = static_cast<double>(head) / dup;
/*     Find the discharge coefficient for type 5 flow. */
/* SOURCE culvertb.for:2766 */
/*<       callfndcd5(stdout,culcls,hdrat,rbval,cd) >*/
    fndcd5_(stdout, culcls, &hdrat, rbval, &cd, (ftnlen)8);
/*     Deduce the contraction coefficient from the CD given by */
/*     the USGS tables.  These appear to ignore approach velocity, */
/*     approach reach friction, and approach contraction losses. */
/*     Do the same in estimating the contraction coefficient.  The */
/*     change in bottom elevation to the approximate vena contracta */
/*     location is included because it was likely present in the */
/*     model studies. */
/* SOURCE culvertb.for:2778 */
/*<       dzvc=zb2-zbvec(iat3d) >*/
    dzvc = static_cast<double>(xs2com_1.zb2) - culcom_1.zbvec[culcom_1.iat3d - 1];
/* SOURCE culvertb.for:2779 */
/*<       callfndcc(stdout,cd,dup,adrxs2,a2,hdrat,head,dzvc,cc) >*/
    fndcc_(stdout, &cd, &dup, &xs2com_1.adrxs2, &xs2com_1.a2, &hdrat, &head, &
	    dzvc, cc);
/* SOURCE culvertb.for:2783 */
/*<       yvc=dup*yoverd(nsec(iat3d),dup,a2,cc) >*/
    *yvc = dup * yoverd_(&culcom_1.nsec[culcom_1.iat3d - 1], &dup, &
	    xs2com_1.a2, cc);
/* SOURCE culvertb.for:2785 */
/*<       headvc=hup+hdatum-zbvec(iat3d) >*/
    headvc = static_cast<double>(static_cast<double>(*hup) + *hdatum) - culcom_1.zbvec[culcom_1.iat3d - 1];
/*      WRITE(STDOUT,*) ' YVC=',YVC,' YRATIO=',YVC/DUP,' QRF=',QRF */
/*      WRITE(STDOUT,*) ' HEADVC=',HEADVC */
/* SOURCE culvertb.for:2789 */
/*<       avc=cc*a2 >*/
    avc = static_cast<double>(*cc) * xs2com_1.a2;
/* SOURCE culvertb.for:2790 */
/*<       den=1.0+(avc)**2*(applen*grav2/(k1*k2)-(alp1-applos)/a1**2) >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = avc;
/* Computing 2nd power */
    feq_gen_r_d_2 = xs1com_1.a1;
    den = static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * (static_cast<double>(static_cast<double>(static_cast<double>(appcom_1.applen) * grvcom_1.grav2) / (static_cast<double>(xs1com_1.k1) * 
	    xs2com_1.k2)) - static_cast<double>((static_cast<double>(xs1com_1.alp1) - appcom_1.applos)) / (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2))) 
	    + (float)1.;
/*      WRITE(STDOUT,*) 'AVC=',AVC,' APPLEN=',APPLEN,' GRAV2=',GRAV2, */
/*     A             ' K1=',K1,' K2=',K2,' ALP1=',ALP1,' APPLOS=',APPLOS, */
/*     B             ' A1=',A1 */
/* SOURCE culvertb.for:2795 */
/*<       num=grav2*(headvc-yvc)+(alp1-applos)*(qrf/a1)**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(*qrf) / xs1com_1.a1;
    num = static_cast<double>(static_cast<double>(grvcom_1.grav2) * (static_cast<double>(headvc) - *yvc)) + static_cast<double>((static_cast<double>(xs1com_1.alp1) - appcom_1.applos))
	     * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/*      WRITE(STDOUT,*) ' NUM=',NUM, ' DEN=',DEN,' CC=',CC */
/*     Starting estimate ignores the cross product terms. This estimate */
/*     is correct if QRF = 0. */
/* SOURCE culvertb.for:2801 */
/*<       q=avc*sqrt(num/den) >*/
    q = avc * sqrt(static_cast<double>(num) / den);
/* SOURCE culvertb.for:2802 */
/*<       if(qrf.gt.0.0)then >*/
    if (*qrf > (float)0.) {
/* SOURCE culvertb.for:2803 */
/*<       knt=0 >*/
	knt = 0;
/* SOURCE culvertb.for:2804 */
/*<       numfac=qrf*((alp1-applos)/a1**2-grav2*applen/(k1*k2)) >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = xs1com_1.a1;
	numfac = static_cast<double>(*qrf) * (static_cast<double>(static_cast<double>((static_cast<double>(xs1com_1.alp1) - appcom_1.applos)) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - 
		static_cast<double>(static_cast<double>(grvcom_1.grav2) * appcom_1.applen) / (static_cast<double>(xs1com_1.k1) * xs2com_1.k2)
		);
/* SOURCE culvertb.for:2805 */
/*<   100 continue >*/
L100:
/* SOURCE culvertb.for:2806 */
/*<       qt=avc*sqrt((num+q*numfac)/den) >*/
	qt = avc * sqrt(static_cast<double>((static_cast<double>(num) + static_cast<double>(q) * numfac)) / den);
/* SOURCE culvertb.for:2807 */
/*<       if(abs(q-qt)/qt.ge.epsf)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(q) - qt, dabs(feq_gen_r_d_1)) / qt >= epscom_1.epsf) {
/* SOURCE culvertb.for:2808 */
/*<       q=qt >*/
	    q = qt;
/* SOURCE culvertb.for:2809 */
/*<       knt=knt+1 >*/
	    ++knt;
/* SOURCE culvertb.for:2810 */
/*<       if(knt.gt.100)then >*/
	    if (knt > 100) {
/* SOURCE culvertb.for:2811 */
/*<       write(stdout,54) >*/
		feq_gen_io_d__290.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__290);
		e_wsfe();
/* SOURCE culvertb.for:2812 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:2813 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:2814 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE culvertb.for:2815 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:2816 */
/*<       q=qt >*/
	q = qt;
/* SOURCE culvertb.for:2817 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' FNDQ5: TYPE 5 FLOW=',Q,' with CC=',CC */
/* SOURCE culvertb.for:2820 */
/*<       q5=q >*/
    *q5 = q;
/* SOURCE culvertb.for:2821 */
/*<       return >*/
    return 0;
/* SOURCE culvertb.for:2822 */
/*<       end >*/
} /* fndq5_ */




/* SOURCE culvertb.for:2826 */
/*<        >*/
/* Subroutine */ int frft5_(integer *stdout, real *hdatum, real *hup, integer 
	*iu, integer *id, char *culcls, integer *feq_gen_type_d_, integer *expflg, 
	real *qfree, real *freed, ftnlen culcls_len)
{
    /* Format strings */
    static char fmt_54[] = "(/,\002 *BUG:XXX* No convergence on Q in subrout\
ine FRFT5.\002)";
    static char fmt_56[] = "(/,\002 *WRN:583* BETAF < 0.0 for type 5 flow\
.\002)";
    static char fmt_58[] = "(/,\002 Parameters for transition from type=\002\
,i3,\002 to type 4:\002,/,4x,\002Coefficient of discharge=\002,f8.3,/,4x,\
\002Piezometric depth at section 3=\002,f8.3,/,4x,\002Momentum-flux coeffici\
ent=\002,f8.3,/,4x,\002Kinetic-energy flux coefficient=\002,f8.3)";
    static char fmt_60[] = "(/,\002 Jump location:\002,a)";
    static char fmt_62[] = "(\002  Note: With the jump in the barrel exit, t\
he depth at\002,\002 section 3\002,/,2x,\002given in the summary tables is t\
he \002,\002 depth upstream of the jump.\002,/,2x,\002The value for the\002\
,\002 head at section 3 & 43 is the piezometric\002,/,2x,\002level in the ex\
it that causes full flow.  These water\002,\002 levels differ.\002)";

    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3, feq_gen_r_d_4;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal);
    integer s_wsfe(cilist *), e_wsfe(), do_fio(integer *, char *, ftnlen), 
	    s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    real q, qc, yc, tp, qt, qc1, qc2, qc3, ddn, den, avc, dup, qrf;
    integer knt;
    real num, yvc, z43t, head, beta, dzvc;
    extern /* Subroutine */ int dpm26_(integer *, real *, real *, real *, 
	    integer *), lktj_(integer *, real *, real *);
    real y3lim, hdrat;
    extern /* Subroutine */ int fndcc_(integer *, real *, real *, integer *, 
	    real *, real *, real *, real *, real *), fndcd5_(integer *, char *
	    , real *, real *, real *, ftnlen), lktqc_(integer *, real *, real 
	    *), xlkt22_(integer *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *), fndcde_(
	    integer *, integer *, real *, real *);
    real headvc, z1true, ty6lss, numfac;
    char jmploc[32];
    extern doublereal yoverd_(integer *, real *, real *, real *);
    extern /* Subroutine */ int supsub_(integer *, integer *, integer *, real 
	    *, real *, real *, real *, real *, real *, real *, real *, char *,
	     ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__300 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__301 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__302 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__303 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__304 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__305 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__316 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__324 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__325 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__327 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__328 = { 0, 0, 0, fmt_58, 0 };


/*     + + + PURPOSE + + + */
/*     Compute the free flow and the drop to free flow for */
/*     type 5 flow. */
/* SOURCE culvertb.for:2834 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertb.for:2837 */
/*<       integerexpflg,id,iu,stdout,type >*/
/* SOURCE culvertb.for:2838 */
/*<       realfreed,hdatum,hup,qfree >*/
/* SOURCE culvertb.for:2839 */
/*<       characterculcls*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     HDATUM - Datum for measuring head */
/*     HUP    - Head upstream */
/*     IU     - Index for upstream node for the culvert barrel */
/*     CULCLS - Class for culvert shape, BOX, PIPE, .. */
/*     TYPE   - Culvert flow type */
/*     EXPFLG - Expansion flag.  EXPFLG=1 if flow expands on exit */
/*              and EXPFLG=0 if flow does not expand on exit */
/*     QFREE  - Free flow */
/*     FREED  - Free drop */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertb.for:2854 */
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
/* INCLUDE culvertb.for:2855 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertb.for:2856 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE culvertb.for:2857 */
/* SOURCE cdcom.cmn:2 */
/*<        >*/
/* SOURCE cdcom.cmn:10 */
/*<        >*/
/* SOURCE cdcom.cmn:14 */
/*<        >*/
/*     Add values for support of FHWA type 5 scheme. Oct. 3, 2001 */
/* SOURCE cdcom.cmn:20 */
/*<       realafhwa,cfhwa,yfhwa,sfhwa >*/
/*     AFHWA - value of a */
/*     CFHWA - value of c */
/*     YFHWA - value of Y */
/*     SFHWA - slope of culvert near entrance. */
/* INCLUDE culvertb.for:2858 */
/* SOURCE xs1com.cmn:2 */
/*<        >*/
/* SOURCE xs1com.cmn:7 */
/*<       integeradrxs1 >*/
/* SOURCE xs1com.cmn:9 */
/*<        >*/
/*     Z1TY1- elevation at section 1 at type 1 limit if it exists */
/*     Z1TY1L-elevation at section 1 at lower limit of type 1 if it exists */
/*     Z1TY6- elevation at section 1 at start of type 6 if it exists */
/*     Z1TY2- elevation at upper limit of type 2 flow if it exists */
/*     Z1TY61- elevation at upper limt of type 61 if it exists */
/*     Z1TY5- elevation at section at start of type 5 if it exists */
/*     Z1TY52- elevation at section 1 at lower limit of type 52( */
/*             type 2 to type 5 flow) */
/*     Z1TY51- elevation at section 1 at lower limit of type 51( */
/*             type 1 to type 5 flow) */
/* INCLUDE culvertb.for:2859 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culvertb.for:2860 */
/* SOURCE xs3com.cmn:2 */
/*<        >*/
/* SOURCE xs3com.cmn:11 */
/*<       integeradrxs3 >*/
/* SOURCE xs3com.cmn:13 */
/*<        >*/
/*     CD1- if 0.0 type 1 flow has not been checked, if > 0 type 1 */
/*          flow has been checked and found to exist and its limit */
/*          values have been found, if < 0 type 1 flow does not exist. */
/*     CD2T6- coef. of discharge forcing full flow to match flow */
/*            at the type 2 flow limit. */
/*     AP2T6 - kinetic energy flux coefficient forcing the full */
/*             flow kinetic energy flux to match the flux */
/*             at the type 2 limit. */
/*     BT2T6- momentum flux coefficient forcing the full flow */
/*            momentum flux to match the flux at the type 2 limit. */
/*     CD61T6- coef. of discharge forcing full flow to match flow */
/*             at the type 61 limit. */
/*     CD1T6- coef. of discharge forcing full flow to match flow */
/*            at the type 1 limit */

/*     AP61T6- same as AP2T6 for type 61. */
/*     BT61T6- same as AP2T6 for type 61. */
/*     CD2- coef. of discharge for type 2 flow at the type 2 limit. */
/*     CD61- coef. of discharge for type 61 flow at the type 61 limit. */
/*     CD6- coef. of discharge for type 6 flow. */
/*     Z3PTY6- piezometric level at section 3 at the type 6 limit. */
/*     AVH2- area for velocity head at the type 2 limit. */
/*     AVH61- area for velocity head at the type 61 limit. */
/*     BT3ATD- beta at section 3 when barrel is full(at D!) */
/*     AP3ATD- alpha at section 3 when the barrel is full(at D!) */
/*     CC2T5 - contraction coefficient for type 5 at the type 2 flow */
/*             limit. */
/*     CC1T5 - contraction coefficient for type 5 at the type 1 flow */
/*             limit. */
/*     CC5- contraction coefficient for type 5 at its lower limit */
/*          and above. */
/*     Y3TY52- depth at section 3 at the lower limit of type 52 flow */
/*             giving the transistion between type 2 and type 5. */
/*     Y3TY51- depth at section 3 at the lower limit of type 51 flow */
/*             giving the transistion between type 1 and type 5. */
/*     BT2T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 52 and */
/*             upper limit of type 2. */
/*     BT1T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 51 and */
/*             upper limit of type 1. */
/*     AP2T5-  alpha analogous to BT2T5 */
/*     AP1T5-  alpha analogous to BT1T5 */
/*     Y3TY5-  depth at section 3 at the lower limit of type 5 flow */
/*     BT3AT5- beta for type 5 flow limit */
/*     AP3AT5- alpha for type 5 flow limit */
/*     CD5T4- coefficient of discharge that forces a type 4 equation */
/*            to match the type 5, 51, or 52 flow at the full-flow- */
/*            inducing level at section 43. */
/*     Y3LTY2- depth at section 3 at the type 2 limit, that is, */
/*             critical depth. */
/*     Y3LTY1- submergence depth at section 3  at the limit of */
/*             type 1 flow. */
/*     Y3LTY5- the full-flow-inducing value of piezometric level */
/*             relative to the invert at section 3 for flow types */
/*             5, 51, and 52. */
/* INCLUDE culvertb.for:2861 */
/* SOURCE x43com.cmn:2 */
/*<        >*/
/* SOURCE x43com.cmn:6 */
/*<       integeradrs43,stat43 >*/
/* SOURCE x43com.cmn:8 */
/*<        >*/
/* INCLUDE culvertb.for:2862 */
/* SOURCE xs4com.cmn:2 */
/*<        >*/
/* SOURCE xs4com.cmn:5 */
/*<       integeradrxs4 >*/
/* SOURCE xs4com.cmn:7 */
/*<        >*/
/* INCLUDE culvertb.for:2863 */
/* SOURCE rdfcom.cmn:2 */
/*<       common/rdfcom/wfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/* SOURCE rdfcom.cmn:4 */
/*<       realwfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/*     WFRDF-WATER FLUX OVER ROAD FREE CONDITION. */
/*     MFRDF-MOMENTUM FLUX OVER THE ROAD FREE CONDITION. */
/*     EFRDF-ENERGY FLUX OVER THE ROAD FREE CONDITION. */
/*     WFRD- WATER FLUX OVER THE ROAD ANY CONDITION. */
/*     MFRD- MOMENTUM FLUX OVER THE ROAD ANY CONDITION. */
/*     EFRD- ENERGY FLUX OVER THE ROAD ANY CONDITION. */
/* INCLUDE culvertb.for:2864 */
/* SOURCE appcom.cmn:2 */
/*<       common/appcom/apptab,appelv,applen,applos,appexp,zertab,zerelv >*/
/* SOURCE appcom.cmn:5 */
/*<       integerapptab,zertab >*/
/* SOURCE appcom.cmn:7 */
/*<       realappelv,applen,applos,appexp,zerelv >*/
/* INCLUDE culvertb.for:2865 */
/*     Common block for various parameters to handle transitional */
/*     flow type behavior for the departure reach computations. */
/* SOURCE typtrn.cmn:4 */
/*<       common/typtrn/avhf,cdf,betaf,alphaf,y3pf,beta3,alpha3 >*/
/* SOURCE typtrn.cmn:6 */
/*<       realavhf,cdf,betaf,alphaf,y3pf,beta3,alpha3 >*/
/*     AVHF- area used for velocity head in computing losses for the */
/*           transitional free flow */
/*     CDF- coef. of discharge for computing losses for the transitional */
/*          free flow. */
/*     BETAF- value of beta to compensate for false area in the computation */
/*            of the momentum flux from some free flows.  If this */
/*            value is zero it means that the beta from the cross section */
/*            function table should be used.  If it is non-zero it means */
/*            that the free flow type was used as a transition and that */
/*            the flow area of the culvert barrel outlet was falsified in */
/*            the process. */
/*     ALPHAF- value of alpha to use in computing velocity head for */
/*             energy loss computations. */
/*     Y3PF- depth to the piezometric level at the culvert barrel outlet */
/*           for free flow limit. */
/*     BETA3- actual value at section 3 used in departure reach */
/*     ALPHA3- actual value at section 3.  Crudely estimated in some */
/*             cases because better alternative is not available. */
/* INCLUDE culvertb.for:2866 */
/* SOURCE culcom.cmn:2 */
/*<        >*/
/* SOURCE culcom.cmn:8 */
/*<       integernsec(mnbn),hltab(mnbn),iat3d,iat6d,sbkind,sbshape >*/
/* SOURCE culcom.cmn:10 */
/*<        >*/
/* SOURCE culcom.cmn:16 */
/*<       doubleprecisionfrcfac >*/
/*     FRCFAC- friction factor to give factor for friction losses */
/*             in barrel for non-prismatic full-flow that as well */
/*             as prismatic full flow. */
/*     TY1YTD- maximum ratio of depth to vertical diameter for */
/*             type 1 flow. */
/*     TY1HTD- maximum ratio of head at section 1 relative to */
/*             culvert invert at culvert inlet to the vertical */
/*             diamter of the culvert.  Must be less than 1.5. */
/*     SBKIND- if 0 the slope of the culvert barrel is a constant, */
/*             if 1 the slope of the culvert barrel varies. */
/*     BSHAPE- if 0 the barrel shape is constant, that is, prismatic, */
/*             if 1 the barrel shape is nonprismatic. */
/*     TY5SBF- ratio of depth to vertical diameter of the culvert */
/*             at the exit which causes submergence. */
/* Note:  25 August 2004:  SBSHAPE is apparently not used.  BSHAPE */
/* is but outside of a common block. */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertb.for:2869 */
/*<       integerknt >*/
/* SOURCE culvertb.for:2870 */
/*<        >*/
/* SOURCE culvertb.for:2873 */
/*<       characterjmploc*32 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertb.for:2876 */
/*<       intrinsicabs,min,sqrt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertb.for:2879 */
/*<       realyoverd >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertb.for:2882 */
/*<       externaldpm26,fndcc,fndcd5,fndcde,lktj,lktqc,supsub,xlkt22,yoverd >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertb.for:2886 */
/*<    54 format(/,' *BUG:XXX* No convergence on Q in subroutine FRFT5.') >*/
/* SOURCE culvertb.for:2887 */
/*<    56 format(/,' *WRN:583* BETAF < 0.0 for type 5 flow.') >*/
/* SOURCE culvertb.for:2888 */
/*<    58  >*/
/* SOURCE culvertb.for:2894 */
/*<    60 format(/,' Jump location:',a) >*/
/* SOURCE culvertb.for:2895 */
/*<    62  >*/
/* *********************************************************************** */
/*      WRITE(STDOUT,*) ' FRFT5: Z1TY51=',Z1TY51,' Z1TY52=',Z1TY52, */
/*     A                ' Z1TY5=',Z1TY5 */
/* SOURCE culvertb.for:2905 */
/*<       dup=dvec(iu) >*/
/* L54: */
/* L56: */
/* L58: */
/* L60: */
/* L62: */
    dup = culcom_1.dvec[*iu - 1];
/* SOURCE culvertb.for:2906 */
/*<       ddn=dvec(id) >*/
    ddn = culcom_1.dvec[*id - 1];
/* SOURCE culvertb.for:2907 */
/*<        >*/
    xlkt22_(&xs2com_1.adrxs2, &dup, &xs2com_1.a2, &xs2com_1.t2, &xs2com_1.dt2,
	     &xs2com_1.j2, &xs2com_1.k2, &xs2com_1.dk2, &xs2com_1.bet2, &
	    xs2com_1.dbet2, &xs2com_1.alp2, &xs2com_1.dalp2, &qc2);
/* SOURCE culvertb.for:2912 */
/*<       z1true=hdatum+hup >*/
    z1true = static_cast<double>(*hdatum) + *hup;
/*      WRITE(STDOUT,*) ' FRFT5: Z1TRUE=',Z1TRUE */
/* SOURCE culvertb.for:2914 */
/*<       y1=z1true-zb1 >*/
    xs1com_1.y1 = static_cast<double>(z1true) - xs1com_1.zb1;
/* SOURCE culvertb.for:2915 */
/*<        >*/
    xlkt22_(&xs1com_1.adrxs1, &xs1com_1.y1, &xs1com_1.a1, &xs1com_1.t1, &
	    xs1com_1.dt1, &xs1com_1.j1, &xs1com_1.k1, &xs1com_1.dk1, &
	    xs1com_1.bet1, &xs1com_1.dbet1, &xs1com_1.alp1, &xs1com_1.dalp1, &
	    qc1);
/* SOURCE culvertb.for:2920 */
/*<       head=hup+hdatum-zb2 >*/
    head = static_cast<double>(static_cast<double>(*hup) + *hdatum) - xs2com_1.zb2;
/* SOURCE culvertb.for:2922 */
/*<       if(z1true.ge.z1ty5)then >*/
    if (z1true >= xs1com_1.z1ty5) {
/* SOURCE culvertb.for:2923 */
/*<       type=5 >*/
	*feq_gen_type_d_ = 5;
/* SOURCE culvertb.for:2924 */
/*<       lftype=5 >*/
	xs2com_1.lftype = 5;
/* SOURCE culvertb.for:2925 */
/*<       lstype=-1 >*/
	xs2com_1.lstype = -1;
/* SOURCE culvertb.for:2926 */
/*<       betaf=0.0 >*/
	typtrn_1.betaf = (float)0.;
/* SOURCE culvertb.for:2927 */
/*<       beta3=0.0 >*/
	typtrn_1.beta3 = (float)0.;
/* SOURCE culvertb.for:2928 */
/*<       alpha3=0.0 >*/
	typtrn_1.alpha3 = (float)0.;
/* SOURCE culvertb.for:2929 */
/*<       y3lim=y3lty5 >*/
	y3lim = xs3com_1.y3lty5;
/* SOURCE culvertb.for:2930 */
/*<       hdrat=head/dup >*/
	hdrat = static_cast<double>(head) / dup;
/*        WRITE(STDOUT,*) ' FRFT5: HDRAT=',HDRAT */
/*       Find the discharge coefficient for type 5 flow. */
/* SOURCE culvertb.for:2934 */
/*<       callfndcd5(stdout,culcls,hdrat,rbval,cd) >*/
	fndcd5_(stdout, culcls, &hdrat, &cdcom_1.rbval, &cdcom_1.cd, (ftnlen)
		8);
/*        WRITE(STDOUT,*) ' FRFT5: CD=',CD */
/*        Deduce the contraction coefficient from the CD given by */
/*       the USGS tables.  These appear to ignore approach velocity, */
/*       approach reach friction, and approach contraction losses. */
/*       Do the same in estimating the contraction coefficient.  The */
/*       change in bottom elevation to the approximate vena contracta */
/*       location is included because it was likely present in the */
/*       model studies. */
/* SOURCE culvertb.for:2949 */
/*<       dzvc=zb2-zbvec(iat3d) >*/
	dzvc = static_cast<double>(xs2com_1.zb2) - culcom_1.zbvec[culcom_1.iat3d - 1];
/* SOURCE culvertb.for:2950 */
/*<       callfndcc(stdout,cd,dup,adrxs2,a2,hdrat,head,dzvc,cc) >*/
	fndcc_(stdout, &cdcom_1.cd, &dup, &xs2com_1.adrxs2, &xs2com_1.a2, &
		hdrat, &head, &dzvc, &cdcom_1.cc);
/* SOURCE culvertb.for:2953 */
/*<       y3lim=y3lty5 >*/
	y3lim = xs3com_1.y3lty5;
/* SOURCE culvertb.for:2954 */
/*<       else >*/
    } else {
/* SOURCE culvertb.for:2955 */
/*<       if(z1ty52.gt.z1ty51)then >*/
	if (xs1com_1.z1ty52 > xs1com_1.z1ty51) {
/* SOURCE culvertb.for:2956 */
/*<       type=52 >*/
	    *feq_gen_type_d_ = 52;
/* SOURCE culvertb.for:2957 */
/*<       lftype=52 >*/
	    xs2com_1.lftype = 52;
/* SOURCE culvertb.for:2958 */
/*<       lstype=-1 >*/
	    xs2com_1.lstype = -1;
/* SOURCE culvertb.for:2959 */
/*<       if(z1true.ge.z1ty52.and.z1true.lt.z1ty5)then >*/
	    if (z1true >= xs1com_1.z1ty52 && z1true < xs1com_1.z1ty5) {
/* SOURCE culvertb.for:2960 */
/*<       if(cc2t5.le.0.0)then >*/
		if (xs3com_1.cc2t5 <= (float)0.) {
/* SOURCE culvertb.for:2961 */
/*<       write(stdout,*)' *BUG:XXX FRFT5: CC2T5=',cc2t5 >*/
		    feq_gen_io_d__300.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__300);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX FRFT5: CC2T5="), (ftnlen)
			    23);
		    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&xs3com_1.cc2t5, (ftnlen)
			    sizeof(real));
		    e_wsle();
/* SOURCE culvertb.for:2962 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:2963 */
/*<       endif >*/
		}
/* SOURCE culvertb.for:2964 */
/*<       if(cc5.le.0.0)then >*/
		if (xs3com_1.cc5 <= (float)0.) {
/* SOURCE culvertb.for:2965 */
/*<       write(stdout,*)' *BUG:XXX FRFT5: CC5=',cc5 >*/
		    feq_gen_io_d__301.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__301);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX FRFT5: CC5="), (ftnlen)21);
		    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&xs3com_1.cc5, (ftnlen)
			    sizeof(real));
		    e_wsle();
/* SOURCE culvertb.for:2966 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:2967 */
/*<       endif >*/
		}
/*           No discharge coefficient used.   Compute the contraction */
/*           coefficient by linear interpolation. */
/* SOURCE culvertb.for:2970 */
/*<       cc=cc2t5+(z1true-z1ty52)*(cc5-cc2t5)/(z1ty5-z1ty52) >*/
		cdcom_1.cc = static_cast<double>(xs3com_1.cc2t5) + static_cast<double>(static_cast<double>((static_cast<double>(z1true) - xs1com_1.z1ty52)) * (
			static_cast<double>(xs3com_1.cc5) - xs3com_1.cc2t5)) / (static_cast<double>(xs1com_1.z1ty5) - 
			xs1com_1.z1ty52);
/* SOURCE culvertb.for:2972 */
/*<       betaf=bt2t5+(z1true-z1ty52)*(bt3at5-bt2t5)/(z1ty5-z1ty52) >*/
		typtrn_1.betaf = static_cast<double>(xs3com_1.bt2t5) + static_cast<double>(static_cast<double>((static_cast<double>(z1true) - xs1com_1.z1ty52)) *
			 (static_cast<double>(xs3com_1.bt3at5) - xs3com_1.bt2t5)) / (static_cast<double>(xs1com_1.z1ty5) 
			- xs1com_1.z1ty52);
/* SOURCE culvertb.for:2974 */
/*<       alphaf=ap2t5+(z1true-z1ty52)*(ap3at5-ap2t5)/(z1ty5-z1ty52) >*/
		typtrn_1.alphaf = static_cast<double>(xs3com_1.ap2t5) + static_cast<double>(static_cast<double>((static_cast<double>(z1true) - xs1com_1.z1ty52)) 
			* (static_cast<double>(xs3com_1.ap3at5) - xs3com_1.ap2t5)) / (
			static_cast<double>(xs1com_1.z1ty5) - xs1com_1.z1ty52);
/* SOURCE culvertb.for:2976 */
/*<       y3lim=y3lty2+(z1true-z1ty52)*(y3lty5-y3lty2)/(z1ty5-z1ty52) >*/
		y3lim = static_cast<double>(xs3com_1.y3lty2) + static_cast<double>(static_cast<double>((static_cast<double>(z1true) - xs1com_1.z1ty52)) * (
			static_cast<double>(xs3com_1.y3lty5) - xs3com_1.y3lty2)) / (static_cast<double>(xs1com_1.z1ty5) 
			- xs1com_1.z1ty52);
/* SOURCE culvertb.for:2978 */
/*<       else >*/
	    } else {
/* SOURCE culvertb.for:2979 */
/*<        >*/
		feq_gen_io_d__302.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__302);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* WRONG ELEVATION FOR TYPE 52"),
			 (ftnlen)38);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" IN FRFT5."), (ftnlen)10);
		e_wsle();
/* SOURCE culvertb.for:2981 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:2982 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:2983 */
/*<       else >*/
	} else {
/* SOURCE culvertb.for:2984 */
/*<       type=51 >*/
	    *feq_gen_type_d_ = 51;
/* SOURCE culvertb.for:2985 */
/*<       lftype=51 >*/
	    xs2com_1.lftype = 51;
/* SOURCE culvertb.for:2986 */
/*<       lstype=-1 >*/
	    xs2com_1.lstype = -1;
/*          WRITE(STDOUT,*) ' Z1TY51=',Z1TY51,' Z1TY5=',Z1TY51 */
/*          WRITE(STDOUT,*) ' Z1TRUE=',Z1TRUE */
/* SOURCE culvertb.for:2990 */
/*<       if(z1true.ge.z1ty51.and.z1true.lt.z1ty5)then >*/
	    if (z1true >= xs1com_1.z1ty51 && z1true < xs1com_1.z1ty5) {
/* SOURCE culvertb.for:2991 */
/*<       if(cc1t5.le.0.0)then >*/
		if (xs3com_1.cc1t5 <= (float)0.) {
/* SOURCE culvertb.for:2992 */
/*<       write(stdout,*)' *BUG:XXX FRFT5: CC1T5=',cc1t5 >*/
		    feq_gen_io_d__303.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__303);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX FRFT5: CC1T5="), (ftnlen)
			    23);
		    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&xs3com_1.cc1t5, (ftnlen)
			    sizeof(real));
		    e_wsle();
/* SOURCE culvertb.for:2993 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:2994 */
/*<       endif >*/
		}
/* SOURCE culvertb.for:2995 */
/*<       if(cc5.le.0.0)then >*/
		if (xs3com_1.cc5 <= (float)0.) {
/* SOURCE culvertb.for:2996 */
/*<       write(stdout,*)' *BUG:XXX FRFT5: CC5=',cc5 >*/
		    feq_gen_io_d__304.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__304);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX FRFT5: CC5="), (ftnlen)21);
		    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&xs3com_1.cc5, (ftnlen)
			    sizeof(real));
		    e_wsle();
/* SOURCE culvertb.for:2997 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:2998 */
/*<       endif >*/
		}
/*           No discharge coefficient used.   Compute the contraction */
/*           coefficient by linear interpolation. */
/* SOURCE culvertb.for:3001 */
/*<       cc=cc1t5+(z1true-z1ty51)*(cc5-cc1t5)/(z1ty5-z1ty51) >*/
		cdcom_1.cc = static_cast<double>(xs3com_1.cc1t5) + static_cast<double>(static_cast<double>((static_cast<double>(z1true) - xs1com_1.z1ty51)) * (
			static_cast<double>(xs3com_1.cc5) - xs3com_1.cc1t5)) / (static_cast<double>(xs1com_1.z1ty5) - 
			xs1com_1.z1ty51);
/* SOURCE culvertb.for:3003 */
/*<       betaf=bt1t5+(z1true-z1ty51)*(bt3at5-bt1t5)/(z1ty5-z1ty51) >*/
		typtrn_1.betaf = static_cast<double>(xs3com_1.bt1t5) + static_cast<double>(static_cast<double>((static_cast<double>(z1true) - xs1com_1.z1ty51)) *
			 (static_cast<double>(xs3com_1.bt3at5) - xs3com_1.bt1t5)) / (static_cast<double>(xs1com_1.z1ty5) 
			- xs1com_1.z1ty51);
/* SOURCE culvertb.for:3005 */
/*<       alphaf=ap1t5+(z1true-z1ty51)*(ap3at5-ap1t5)/(z1ty5-z1ty51) >*/
		typtrn_1.alphaf = static_cast<double>(xs3com_1.ap1t5) + static_cast<double>(static_cast<double>((static_cast<double>(z1true) - xs1com_1.z1ty51)) 
			* (static_cast<double>(xs3com_1.ap3at5) - xs3com_1.ap1t5)) / (
			static_cast<double>(xs1com_1.z1ty5) - xs1com_1.z1ty51);
/* SOURCE culvertb.for:3007 */
/*<       y3lim=y3lty1+(z1true-z1ty51)*(y3lty5-y3lty1)/(z1ty5-z1ty51) >*/
		y3lim = static_cast<double>(xs3com_1.y3lty1) + static_cast<double>(static_cast<double>((static_cast<double>(z1true) - xs1com_1.z1ty51)) * (
			static_cast<double>(xs3com_1.y3lty5) - xs3com_1.y3lty1)) / (static_cast<double>(xs1com_1.z1ty5) 
			- xs1com_1.z1ty51);
/*            WRITE(STDOUT,*) ' FRFT5: BT1T5=',BT1T5,' BT3AT5=',BT3AT5, */
/*     A            ' Z1TY5=',Z1TY5,' Z1TY51=',Z1TY51, ' Z1TRUE=',Z1TRUE, */
/*     B            ' Y3LTY5=',Y3LTY5,' Y3LTY1=',Y3LTY1,' Y3LIM=',Y3LIM */
/* SOURCE culvertb.for:3012 */
/*<       else >*/
	    } else {
/* SOURCE culvertb.for:3013 */
/*<        >*/
		feq_gen_io_d__305.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__305);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* WRONG ELEVATION FOR TYPE 51"),
			 (ftnlen)38);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" IN FRFT5."), (ftnlen)10);
		e_wsle();
/* SOURCE culvertb.for:3015 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:3016 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:3017 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:3018 */
/*<       endif >*/
    }
/*     Now estimate the flow using the contraction coefficient as */
/*     the estimate of depth at the vena contracta. */
/* SOURCE culvertb.for:3022 */
/*<       yvc=dup*yoverd(nsec(iat3d),dup,a2,cc) >*/
    yvc = dup * yoverd_(&culcom_1.nsec[culcom_1.iat3d - 1], &dup, &
	    xs2com_1.a2, &cdcom_1.cc);
/* SOURCE culvertb.for:3025 */
/*<       headvc=hup+hdatum-zbvec(iat3d) >*/
    headvc = static_cast<double>(static_cast<double>(*hup) + *hdatum) - culcom_1.zbvec[culcom_1.iat3d - 1];
/* SOURCE culvertb.for:3026 */
/*<       qrf=wfrdf >*/
    qrf = rdfcom_1.wfrdf;
/*      WRITE(STDOUT,*) ' YVC=',YVC,' YRATIO=',YVC/DUP,' QRF=',QRF */
/* SOURCE culvertb.for:3028 */
/*<       avc=cc*a2 >*/
    avc = static_cast<double>(cdcom_1.cc) * xs2com_1.a2;
/* SOURCE culvertb.for:3029 */
/*<       den=1.0+(avc)**2*(applen*grav2/(k1*k2)-(alp1-applos)/a1**2) >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = avc;
/* Computing 2nd power */
    feq_gen_r_d_2 = xs1com_1.a1;
    den = static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * (static_cast<double>(static_cast<double>(static_cast<double>(appcom_1.applen) * grvcom_1.grav2) / (static_cast<double>(xs1com_1.k1) * 
	    xs2com_1.k2)) - static_cast<double>((static_cast<double>(xs1com_1.alp1) - appcom_1.applos)) / (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2))) 
	    + (float)1.;
/* SOURCE culvertb.for:3031 */
/*<       num=grav2*(headvc-yvc)+(alp1-applos)*(qrf/a1)**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(qrf) / xs1com_1.a1;
    num = static_cast<double>(static_cast<double>(grvcom_1.grav2) * (static_cast<double>(headvc) - yvc)) + static_cast<double>((static_cast<double>(xs1com_1.alp1) - appcom_1.applos)) 
	    * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/*     Starting estimate  ignores the cross product terms. This estimate */
/*     is correct if QRF = 0. */
/* SOURCE culvertb.for:3035 */
/*<       q=avc*sqrt(num/den) >*/
    q = avc * sqrt(static_cast<double>(num) / den);
/* SOURCE culvertb.for:3036 */
/*<       if(qrf.gt.0.0)then >*/
    if (qrf > (float)0.) {
/* SOURCE culvertb.for:3037 */
/*<       knt=0 >*/
	knt = 0;
/* SOURCE culvertb.for:3038 */
/*<       numfac=qrf*((alp1-applos)/a1**2-grav2*applen/(k1*k2)) >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = xs1com_1.a1;
	numfac = static_cast<double>(qrf) * (static_cast<double>(static_cast<double>((static_cast<double>(xs1com_1.alp1) - appcom_1.applos)) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - 
		static_cast<double>(static_cast<double>(grvcom_1.grav2) * appcom_1.applen) / (static_cast<double>(xs1com_1.k1) * xs2com_1.k2)
		);
/* SOURCE culvertb.for:3039 */
/*<   100 continue >*/
L100:
/* SOURCE culvertb.for:3040 */
/*<       qt=avc*sqrt((num+q*numfac)/den) >*/
	qt = avc * sqrt(static_cast<double>((static_cast<double>(num) + static_cast<double>(q) * numfac)) / den);
/* SOURCE culvertb.for:3041 */
/*<       if(abs(q-qt)/qt.ge.epsf)then >*/
	if ((feq_gen_r_d_1 = static_cast<double>(q) - qt, dabs(feq_gen_r_d_1)) / qt >= epscom_1.epsf) {
/* SOURCE culvertb.for:3042 */
/*<       q=qt >*/
	    q = qt;
/* SOURCE culvertb.for:3043 */
/*<       knt=knt+1 >*/
	    ++knt;
/* SOURCE culvertb.for:3044 */
/*<       if(knt.gt.100)then >*/
	    if (knt > 100) {
/* SOURCE culvertb.for:3045 */
/*<       write(stdout,54) >*/
		feq_gen_io_d__316.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__316);
		e_wsfe();
/* SOURCE culvertb.for:3046 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:3047 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:3048 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE culvertb.for:3049 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:3050 */
/*<       q=qt >*/
	q = qt;
/* SOURCE culvertb.for:3051 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:3053 */
/*<       qfree=q >*/
    *qfree = q;
/*      WRITE(STDOUT,*) ' FRFT5: TYPE 5 FLOW=',Q,' with CC=',CC */
/* SOURCE culvertb.for:3057 */
/*<       q2=q >*/
    xs2com_1.q2 = q;
/* SOURCE culvertb.for:3058 */
/*<       q1=q2+qrf >*/
    xs1com_1.q1 = static_cast<double>(xs2com_1.q2) + qrf;
/* SOURCE culvertb.for:3059 */
/*<       q3=q >*/
    xs3com_1.q3 = q;
/* SOURCE culvertb.for:3061 */
/*<       ty6lss=((1.0/c46**2-1.0))*(q/a2)**2/grav2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = cdcom_1.c46;
/* Computing 2nd power */
    feq_gen_r_d_2 = static_cast<double>(q) / xs2com_1.a2;
    ty6lss = static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - (float)1.)) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) / 
	    grvcom_1.grav2;
/*      WRITE(STDOUT,*) ' TYPE 6 LOSS =',TY6LSS */
/*      EUP = ZB1 + Y1 + ALP1*(Q/A1)**2/GRAV2 */
/*     Section 2 is always full.  Therefore Y2 is always DUP. */
/*     The piezometric pressure is atmospheric at the water surface */
/*     just downstream of the entrance soffit.  This assumes perfect */
/*     venilation. */
/* SOURCE culvertb.for:3071 */
/*<       z2=dup+zb2 >*/
    xs2com_1.z2 = static_cast<double>(dup) + xs2com_1.zb2;
/* SOURCE culvertb.for:3072 */
/*<       y2=dup >*/
    xs2com_1.y2 = dup;
/*      WRITE(STDOUT,*) ' TOTAL ENERGY ELEV AT SEC. 1=',EUP */
/* SOURCE culvertb.for:3074 */
/*<       calllktqc(nsec(iat3d),yvc,qc) >*/
    lktqc_(&culcom_1.nsec[culcom_1.iat3d - 1], &yvc, &qc);
/*      WRITE(STDOUT,*) ' FRFT5: DEPTH AT VC=',YVC,' FROUDE=',Q/QC */
/*      VC = Q/(CC*A2) */
/*      WRITE(STDOUT,*) ' VELOCITY AT VC =',VC */
/*     Find critical depth at exit. */
/* SOURCE culvertb.for:3082 */
/*<       y3=0.5*ddn >*/
    xs3com_1.y3 = static_cast<double>(ddn) * (float).5;
/* SOURCE culvertb.for:3083 */
/*<       callfndcde(stdout,adrxs3,q,y3) >*/
    fndcde_(stdout, &xs3com_1.adrxs3, &q, &xs3com_1.y3);
/* SOURCE culvertb.for:3086 */
/*<       yc=y3 >*/
    yc = xs3com_1.y3;

/*     Find the depth at the exit from the culvert barrel.  A hydraulic */
/*     jump  may exist in the barrel, part way in the barrel, or */
/*     in some problem cases not at all. */
/* SOURCE culvertb.for:3093 */
/*<        >*/
    supsub_(stdout, &culcom_1.iat3d, id, &yvc, &y3lim, &q, &dup, &yc, &ty6lss,
	     &xs3com_1.z3, &z43t, jmploc, (ftnlen)32);
/*     Compute values at section 3.  Not done in SUPSUB */
/* SOURCE culvertb.for:3099 */
/*<       y3=z3-zb3 >*/
    xs3com_1.y3 = static_cast<double>(xs3com_1.z3) - xs3com_1.zb3;
/* SOURCE culvertb.for:3100 */
/*<       z3p=z43t >*/
    xs3com_1.z3p = z43t;
/* SOURCE culvertb.for:3101 */
/*<       tp=min(y3,ddn) >*/
    tp = dmin(xs3com_1.y3,ddn);
/* SOURCE culvertb.for:3102 */
/*<        >*/
    xlkt22_(&xs3com_1.adrxs3, &tp, &xs3com_1.a3, &xs3com_1.t3, &xs3com_1.dt3, 
	    &xs3com_1.j3, &xs3com_1.k3, &xs3com_1.dk3, &xs3com_1.bet3, &
	    xs3com_1.dbet3, &xs3com_1.alp3, &xs3com_1.dalp3, &qc3);
/* SOURCE culvertb.for:3107 */
/*<       calllktj(adrxs3,y3,j3) >*/
    lktj_(&xs3com_1.adrxs3, &xs3com_1.y3, &xs3com_1.j3);
/*     Type 5 flow at submergence limit passes to full flow */
/*     immediately upon submergence.  Y3FREE is used to remember the */
/*     area defining depth that is to be associated with the */
/*     submergence limit tailwater at section 43.  Thus for type 5 */
/*     flow the proper value for Y3FREE is DDN. */
/* SOURCE culvertb.for:3116 */
/*<       y3free=ddn >*/
    xs3com_1.y3free = ddn;
/* SOURCE culvertb.for:3117 */
/*<       q3free=q3 >*/
    xs3com_1.q3free = xs3com_1.q3;
/* SOURCE culvertb.for:3118 */
/*<       z43t=y3lim+zb3 >*/
    z43t = static_cast<double>(y3lim) + xs3com_1.zb3;
/*      WRITE(STDOUT,*) ' FRFT5: Y3LIM=',Y3LIM,' Z43T=',Z43T, */
/*     A                ' BETAF=',BETAF */
/* SOURCE culvertb.for:3121 */
/*<       calldpm26(stdout,wfrdf,mfrdf,z43t,expflg) >*/
    dpm26_(stdout, &rdfcom_1.wfrdf, &rdfcom_1.mfrdf, &z43t, expflg);
/* SOURCE culvertb.for:3124 */
/*<       write(stdout,60)jmploc >*/
    feq_gen_io_d__324.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__324);
    do_fio(&feq_gen_c_d_1, jmploc, (ftnlen)32);
    e_wsfe();
/* SOURCE culvertb.for:3125 */
/*<       if(jmploc.eq.'Jump in the barrel exit')then >*/
    if (s_cmp(jmploc, const_cast<char*>("Jump in the barrel exit"), (ftnlen)32, (ftnlen)23) == 0)
	     {
/* SOURCE culvertb.for:3126 */
/*<       write(stdout,62) >*/
	feq_gen_io_d__325.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__325);
	e_wsfe();
/* SOURCE culvertb.for:3127 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' Z3=',Z3,' Z43=',Z43,' Z4=',Z4,' Z44=',Z44 */
/* SOURCE culvertb.for:3129 */
/*<       if(expflg.eq.1)then >*/
    if (*expflg == 1) {
/*       Expansion of flow in departure reach. */
/* SOURCE culvertb.for:3131 */
/*<       freed=z1true-z4 >*/
	*freed = static_cast<double>(z1true) - xs4com_1.z4;
/*        WRITE(STDOUT,*) ' FREED=',FREED */
/*       Compute the discharge coefficient that is needed for */
/*       full flow to match the type 5, 51, or 52 flow.  Tailwater */
/*       is at Z43OLD, set in DPM26. */
/* SOURCE culvertb.for:3137 */
/*<        >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(xs1com_1.q1) / xs1com_1.a1;
/* Computing 2nd power */
	feq_gen_r_d_2 = static_cast<double>(xs3com_1.q3) / xs3com_1.a3full;
/* Computing 2nd power */
	feq_gen_r_d_3 = static_cast<double>(xs2com_1.q2) / xs2com_1.k2full;
/* Computing 2nd power */
	feq_gen_r_d_4 = static_cast<double>(xs2com_1.a2full) / xs2com_1.q2;
	tp = static_cast<double>((static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>(xs1com_1.alp1) - appcom_1.applos)) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / 
		grvcom_1.grav2) + xs1com_1.z1) - (static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2) / grvcom_1.grav2) 
		+ x43com_1.z43old)) - static_cast<double>(culcom_1.l23) * (static_cast<double>(feq_gen_r_d_3) * feq_gen_r_d_3)) - 
		static_cast<double>(static_cast<double>(appcom_1.applen) * (static_cast<double>(xs1com_1.q1) * xs2com_1.q2)) / (static_cast<double>(xs1com_1.k1) *
		 xs2com_1.k2full))) * (static_cast<double>(grvcom_1.grav2) * (static_cast<double>(feq_gen_r_d_4) * feq_gen_r_d_4));
/* SOURCE culvertb.for:3140 */
/*<       cd5t4=sqrt(1.0/(1.0+tp)) >*/
	xs3com_1.cd5t4 = sqrt(static_cast<double>((float)1.) / (static_cast<double>(tp) + (float)1.));
/* SOURCE culvertb.for:3141 */
/*<       cdf=cd5t4 >*/
	typtrn_1.cdf = xs3com_1.cd5t4;
/* SOURCE culvertb.for:3142 */
/*<       y3pf=z43old-zb3 >*/
	typtrn_1.y3pf = static_cast<double>(x43com_1.z43old) - xs3com_1.zb3;
/* SOURCE culvertb.for:3143 */
/*<       else >*/
    } else {
/* SOURCE culvertb.for:3144 */
/*<       freed=0.0 >*/
	*freed = (float)0.;
/* SOURCE culvertb.for:3145 */
/*<       y3pf=z43old-zb3 >*/
	typtrn_1.y3pf = static_cast<double>(x43com_1.z43old) - xs3com_1.zb3;
/* SOURCE culvertb.for:3146 */
/*<       endif >*/
    }
/*     Now make sure that the M43 as computed in DPM26 for type 5 will */
/*     be closely approximated in FRFT7.  In DPM26 the momentum flux */
/*     was at part full and super critical.  Also the pressure force */
/*     terms include the force at the culvert exit headwall at some */
/*     point in the jump.   That is, Z3 and Z43 may differ even if */
/*     the barrel is part full. */
/* SOURCE culvertb.for:3157 */
/*<       if(betaf.gt.0.0)then >*/
    if (typtrn_1.betaf > (float)0.) {
/* SOURCE culvertb.for:3158 */
/*<       beta=betaf >*/
	beta = typtrn_1.betaf;
/* SOURCE culvertb.for:3159 */
/*<       else >*/
    } else {
/* SOURCE culvertb.for:3160 */
/*<       beta=1.0 >*/
	beta = (float)1.;
/* SOURCE culvertb.for:3161 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' A3FULL=',A3FULL,' BETA=',BETA,' Q3=',Q3, */
/*     A         ' A3=',A3,' GRAV=',GRAV,' J3=',J3,' J3Z43=',J3Z43 */
/* SOURCE culvertb.for:3165 */
/*<       betaf=a3full*(beta*q3**2/a3+grav*(j3-j3z43))/q3**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = xs3com_1.q3;
/* Computing 2nd power */
    feq_gen_r_d_2 = xs3com_1.q3;
    typtrn_1.betaf = static_cast<double>(static_cast<double>(xs3com_1.a3full) * (static_cast<double>(static_cast<double>(static_cast<double>(beta) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / xs3com_1.a3) + 
	    static_cast<double>(grvcom_1.grav) * (static_cast<double>(xs3com_1.j3) - xs3com_1.j3z43))) / (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2);
/* SOURCE culvertb.for:3166 */
/*<       if(betaf.lt.0.0)then >*/
    if (typtrn_1.betaf < (float)0.) {
/* SOURCE culvertb.for:3167 */
/*<       write(stdout,56) >*/
	feq_gen_io_d__327.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__327);
	e_wsfe();
/* SOURCE culvertb.for:3168 */
/*<       betaf=0.0 >*/
	typtrn_1.betaf = (float)0.;
/* SOURCE culvertb.for:3169 */
/*<       endif >*/
    }
/*     No direct way to estimate ALPHAF.  Make a rough estimate */
/* SOURCE culvertb.for:3171 */
/*<       if(betaf.gt.1.0)then >*/
    if (typtrn_1.betaf > (float)1.) {
/* SOURCE culvertb.for:3172 */
/*<       alphaf=1.0+3.0*(betaf-1.0) >*/
	typtrn_1.alphaf = static_cast<double>(static_cast<double>((static_cast<double>(typtrn_1.betaf) - (float)1.)) * (float)3.) + (float)
		1.;
/* SOURCE culvertb.for:3173 */
/*<       else >*/
    } else {
/* SOURCE culvertb.for:3174 */
/*<       alphaf=1.0 >*/
	typtrn_1.alphaf = (float)1.;
/* SOURCE culvertb.for:3175 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:3176 */
/*<       write(stdout,58)type,cd5t4,y3pf,betaf,alphaf >*/
    feq_gen_io_d__328.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__328);
    do_fio(&feq_gen_c_d_1, (char *)&(*feq_gen_type_d_), (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.cd5t4, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&typtrn_1.y3pf, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&typtrn_1.betaf, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&typtrn_1.alphaf, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE culvertb.for:3178 */
/*<       return >*/
    return 0;
/* SOURCE culvertb.for:3179 */
/*<       end >*/
} /* frft5_ */




/* SOURCE culvertb.for:3183 */
/*<        >*/
/* Subroutine */ int doty6_(integer *stdout, char *culcls, real *a1true, real 
	*alp1t, real *k1true, real *z1true, real *a2full, real *k2full, real *
	a3full, real *ddn, real *zb, real *cdis, real *z3p, real *q, real *
	zat2, ftnlen culcls_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *BUG:XXX* No convergence on Q in subrout\
ine DOTY6.\002)";

    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3, feq_gen_r_d_4;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    real qt, y3p, div;
    integer knt;
    real num, ccon;
    extern doublereal ty6rat_(real *, char *, real *, real *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__332 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Compute type 6 flow in the culvert. */
/* SOURCE culvertb.for:3191 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertb.for:3194 */
/*<       integerstdout >*/
/* SOURCE culvertb.for:3195 */
/*<        >*/
/* SOURCE culvertb.for:3197 */
/*<       characterculcls*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     CULCLS - Class for culvert shape, BOX, PIPE, .. */
/*     A1TRUE - area at section 1 for the known water surface elevation */
/*     ALP1T  - value of energy flux correction coefficient at section 1 */
/*     K1TRUE - conveyance at section 1 for the known elevation there */
/*     Z1TRUE - known elevation at section 1 */
/*     A2FULL - area at section 2 with full flow in barrel */
/*     K2FULL - full barrel conveyance at section 2 */
/*     A3FULL - area at section 3 with full flow in barrel */
/*     DDN    - vertical diameter of culvert barrel at downstream end */
/*     ZB     - bottom elevation at section 3 */
/*     CDIS   - discharge coefficient */
/*     Z3P    - elevation of piezometric surface at section 3 */
/*     Q      - Flowrate */
/*     ZAT2   - elevation of water surface at section 2 */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertb.for:3217 */
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
/* INCLUDE culvertb.for:3218 */
/* SOURCE appcom.cmn:2 */
/*<       common/appcom/apptab,appelv,applen,applos,appexp,zertab,zerelv >*/
/* SOURCE appcom.cmn:5 */
/*<       integerapptab,zertab >*/
/* SOURCE appcom.cmn:7 */
/*<       realappelv,applen,applos,appexp,zerelv >*/
/* INCLUDE culvertb.for:3219 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertb.for:3220 */
/* SOURCE culcom.cmn:2 */
/*<        >*/
/* SOURCE culcom.cmn:8 */
/*<       integernsec(mnbn),hltab(mnbn),iat3d,iat6d,sbkind,sbshape >*/
/* SOURCE culcom.cmn:10 */
/*<        >*/
/* SOURCE culcom.cmn:16 */
/*<       doubleprecisionfrcfac >*/
/*     FRCFAC- friction factor to give factor for friction losses */
/*             in barrel for non-prismatic full-flow that as well */
/*             as prismatic full flow. */
/*     TY1YTD- maximum ratio of depth to vertical diameter for */
/*             type 1 flow. */
/*     TY1HTD- maximum ratio of head at section 1 relative to */
/*             culvert invert at culvert inlet to the vertical */
/*             diamter of the culvert.  Must be less than 1.5. */
/*     SBKIND- if 0 the slope of the culvert barrel is a constant, */
/*             if 1 the slope of the culvert barrel varies. */
/*     BSHAPE- if 0 the barrel shape is constant, that is, prismatic, */
/*             if 1 the barrel shape is nonprismatic. */
/*     TY5SBF- ratio of depth to vertical diameter of the culvert */
/*             at the exit which causes submergence. */
/* Note:  25 August 2004:  SBSHAPE is apparently not used.  BSHAPE */
/* is but outside of a common block. */
/* INCLUDE culvertb.for:3221 */
/* SOURCE rdfcom.cmn:2 */
/*<       common/rdfcom/wfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/* SOURCE rdfcom.cmn:4 */
/*<       realwfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/*     WFRDF-WATER FLUX OVER ROAD FREE CONDITION. */
/*     MFRDF-MOMENTUM FLUX OVER THE ROAD FREE CONDITION. */
/*     EFRDF-ENERGY FLUX OVER THE ROAD FREE CONDITION. */
/*     WFRD- WATER FLUX OVER THE ROAD ANY CONDITION. */
/*     MFRD- MOMENTUM FLUX OVER THE ROAD ANY CONDITION. */
/*     EFRD- ENERGY FLUX OVER THE ROAD ANY CONDITION. */
/* INCLUDE culvertb.for:3222 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertb.for:3225 */
/*<       integerknt >*/
/* SOURCE culvertb.for:3226 */
/*<       realccon,div,num,qt,y3p >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertb.for:3229 */
/*<       intrinsicabs,sqrt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertb.for:3232 */
/*<       realty6rat >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertb.for:3235 */
/*<       externalty6rat >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertb.for:3238 */
/*<    50 format(/,' *BUG:XXX* No convergence on Q in subroutine DOTY6.') >*/
/* *********************************************************************** */
/*     Make the first estimate as if roadflow were zero.  If it is */
/*     zero, the result is valid.  Otherwise, iterate */
/*     to include the effect of velocity head of approach from the */
/*     flow over the road. */
/*     Estimate piezometric level at section 3 to start the iterations. */
/* SOURCE culvertb.for:3246 */
/*<       z3p=zb+0.75*ddn >*/
/* L50: */
    *z3p = static_cast<double>(*zb) + static_cast<double>(*ddn) * (float).75;
/* SOURCE culvertb.for:3247 */
/*<       num=grav2*(z1true-z3p) >*/
    num = static_cast<double>(grvcom_1.grav2) * (static_cast<double>(*z1true) - *z3p);
/*      IF(FRCFAC.EQ.0.0) THEN */
/*       Prismatic barrel. */
/*        DIV = (1.0 + GRAV2*(CDIS*A2FULL)**2*(APPLEN/(K1TRUE*K2FULL) */
/*     B       + L23/K2FULL**2 - (ALP1T - APPLOS)/(GRAV2*A1TRUE**2))) */
/*      ELSE */
/* SOURCE culvertb.for:3253 */
/*<        >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = *cdis;
/* Computing 2nd power */
    feq_gen_r_d_2 = static_cast<double>(*a2full) / *a3full;
/* Computing 2nd power */
    feq_gen_r_d_3 = *a2full;
/* Computing 2nd power */
    feq_gen_r_d_4 = *a1true;
    div = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1 * (static_cast<double>(static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2) - (float)1. + static_cast<double>(grvcom_1.grav2) * (static_cast<double>(feq_gen_r_d_3) * 
	    feq_gen_r_d_3) * (static_cast<double>(appcom_1.applen) / (static_cast<double>(*k1true) * *k2full) + culcom_1.frcfac 
	    - static_cast<double>((static_cast<double>(*alp1t) - appcom_1.applos)) / (static_cast<double>(grvcom_1.grav2) * (static_cast<double>(feq_gen_r_d_4) * feq_gen_r_d_4)))) 
	    + (float)1.;
/*      ENDIF */
/* SOURCE culvertb.for:3257 */
/*<       knt=0 >*/
    knt = 0;
/* SOURCE culvertb.for:3258 */
/*<   100 continue >*/
L100:
/* SOURCE culvertb.for:3259 */
/*<       knt=knt+1 >*/
    ++knt;
/* SOURCE culvertb.for:3260 */
/*<       if(knt.gt.100)then >*/
    if (knt > 100) {
/* SOURCE culvertb.for:3261 */
/*<       write(stdout,50) >*/
	feq_gen_io_d__332.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__332);
	e_wsfe();
/* SOURCE culvertb.for:3262 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:3263 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:3266 */
/*<       q=cdis*a2full*sqrt(num/div) >*/
    *q = static_cast<double>(*cdis) * *a2full * sqrt(static_cast<double>(num) / div);
/*       Adjust the piezometric level at 3 for the latest flow. */
/* SOURCE culvertb.for:3269 */
/*<       y3p=ddn*ty6rat(q,culcls,ddn,a3full) >*/
    y3p = *ddn * ty6rat_(q, culcls, ddn, a3full, (ftnlen)8);
/* SOURCE culvertb.for:3270 */
/*<       z3p=zb+y3p >*/
    *z3p = static_cast<double>(*zb) + y3p;
/* SOURCE culvertb.for:3271 */
/*<       num=grav2*(z1true-z3p) >*/
    num = static_cast<double>(grvcom_1.grav2) * (static_cast<double>(*z1true) - *z3p);
/* SOURCE culvertb.for:3273 */
/*<       if(wfrdf.gt.0.0)then >*/
    if (rdfcom_1.wfrdf > (float)0.) {
/*         Add terms to the numerator to represent values affected */
/*         by flow over the road. */
/* SOURCE culvertb.for:3276 */
/*<        >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = *a1true;
	num += static_cast<double>(rdfcom_1.wfrdf) * (static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>(*alp1t) - appcom_1.applos)) * (static_cast<double>(static_cast<double>(rdfcom_1.wfrdf) 
		+ *q) + *q)) / (static_cast<double>(grvcom_1.grav2) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1))) - 
		static_cast<double>(static_cast<double>(appcom_1.applen) * *q) / (static_cast<double>(*k1true) * *k2full));
/* SOURCE culvertb.for:3279 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:3280 */
/*<       qt=cdis*a2full*sqrt(num/div) >*/
    qt = static_cast<double>(*cdis) * *a2full * sqrt(static_cast<double>(num) / div);
/*        WRITE(STDOUT,*) ' DOTY6: KNT=',KNT,' Q=',Q,' QT=',QT */
/* SOURCE culvertb.for:3283 */
/*<       if(abs(qt-q)/q.gt.epsf)then >*/
    if ((feq_gen_r_d_1 = static_cast<double>(qt) - *q, dabs(feq_gen_r_d_1)) / *q > epscom_1.epsf) {
/* SOURCE culvertb.for:3284 */
/*<       q=qt >*/
	*q = qt;
/* SOURCE culvertb.for:3285 */
/*<       goto100 >*/
	goto L100;
/* SOURCE culvertb.for:3286 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:3287 */
/*<       q=qt >*/
    *q = qt;
/*     Compute estimate of the piezometric level at section 2.   Estimate */
/*     the coefficient of contraction from the discharge coefficient. */
/*     Includes effect of vena contracta near entrance. */
/* SOURCE culvertb.for:3292 */
/*<       ccon=1.0/(sqrt(1.0/cdis**2-1.0)+1.0) >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = *cdis;
    ccon = (float)1. / (sqrt(static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - (float)1.) + (float)
	    1.);
/* SOURCE culvertb.for:3293 */
/*<        >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>((static_cast<double>(*q) + rdfcom_1.wfrdf)) / *a1true;
/* Computing 2nd power */
    feq_gen_r_d_2 = static_cast<double>(*q) / (static_cast<double>(ccon) * *a2full);
    *zat2 = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(*alp1t) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / grvcom_1.grav2) + *z1true) - static_cast<double>(static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2) / 
	    grvcom_1.grav2;
/*      WRITE(STDOUT,*) ' DOTY6: ZAT2=',ZAT2,' CCON=',CCON */
/* SOURCE culvertb.for:3296 */
/*<       return >*/
    return 0;
/* SOURCE culvertb.for:3297 */
/*<       end >*/
} /* doty6_ */




/* SOURCE culvertb.for:3301 */
/*<        >*/
/* Subroutine */ int doty61_(integer *stdout, real *a1true, real *alp1t, real 
	*k1true, real *z1true, integer *iu, integer *id, real *zb, real *cdis,
	 real *avh, real *zp, real *q, real *zat2)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *BUG:XXX* No convergence on Q in subrout\
ine DOTY61.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3, feq_gen_r_d_4;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    integer feq_gen_i_d_;
    real al, dh, ar, kl;
    integer is;
    real kr;
    doublereal dx;
    real qt, zt, div;
    integer knt;
    real num;
    doublereal sum;
    real ccon;
    extern /* Subroutine */ int lkta_(integer *, real *, real *);
    integer sflag;
    extern /* Subroutine */ int lktqc_(integer *, real *, real *), fndcde_(
	    integer *, integer *, real *, real *), sfpsbe_(integer *, integer 
	    *, integer *, real *, real *, real *, integer *, real *, integer *
	    );

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__337 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Compute type 61 flow in the culvert. On entry ZP has */
/*     estimated part-full piezometric level at section 3. */
/* SOURCE culvertb.for:3311 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertb.for:3314 */
/*<       integerid,iu,stdout >*/
/* SOURCE culvertb.for:3315 */
/*<       reala1true,alp1t,avh,cdis,k1true,q,z1true,zat2,zb,zp >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     A1TRUE - area at section 1 for the known water surface elevation */
/*     ALP1T  - value of energy flux correction coefficient at section 1 */
/*     K1TRUE - conveyance at section 1 for the known elevation there */
/*     Z1TRUE - known elevation at section 1 */
/*     IU     - Index for upstream node for the culvert barrel */
/*     ID     - Index for the downstream node for the culvert barrel */
/*     ZB     - bottom elevation at section 3 */
/*     CDIS   - discharge coefficient */
/*     AVH    - area for computing velocity head */
/*     ZP     - elevation of the piezometric surface at section 3 */
/*     Q      - Flowrate */
/*     ZAT2   - elevation of water surface at section 2 */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertb.for:3333 */
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
/* INCLUDE culvertb.for:3334 */
/* SOURCE appcom.cmn:2 */
/*<       common/appcom/apptab,appelv,applen,applos,appexp,zertab,zerelv >*/
/* SOURCE appcom.cmn:5 */
/*<       integerapptab,zertab >*/
/* SOURCE appcom.cmn:7 */
/*<       realappelv,applen,applos,appexp,zerelv >*/
/* INCLUDE culvertb.for:3335 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertb.for:3336 */
/* SOURCE xs3com.cmn:2 */
/*<        >*/
/* SOURCE xs3com.cmn:11 */
/*<       integeradrxs3 >*/
/* SOURCE xs3com.cmn:13 */
/*<        >*/
/*     CD1- if 0.0 type 1 flow has not been checked, if > 0 type 1 */
/*          flow has been checked and found to exist and its limit */
/*          values have been found, if < 0 type 1 flow does not exist. */
/*     CD2T6- coef. of discharge forcing full flow to match flow */
/*            at the type 2 flow limit. */
/*     AP2T6 - kinetic energy flux coefficient forcing the full */
/*             flow kinetic energy flux to match the flux */
/*             at the type 2 limit. */
/*     BT2T6- momentum flux coefficient forcing the full flow */
/*            momentum flux to match the flux at the type 2 limit. */
/*     CD61T6- coef. of discharge forcing full flow to match flow */
/*             at the type 61 limit. */
/*     CD1T6- coef. of discharge forcing full flow to match flow */
/*            at the type 1 limit */

/*     AP61T6- same as AP2T6 for type 61. */
/*     BT61T6- same as AP2T6 for type 61. */
/*     CD2- coef. of discharge for type 2 flow at the type 2 limit. */
/*     CD61- coef. of discharge for type 61 flow at the type 61 limit. */
/*     CD6- coef. of discharge for type 6 flow. */
/*     Z3PTY6- piezometric level at section 3 at the type 6 limit. */
/*     AVH2- area for velocity head at the type 2 limit. */
/*     AVH61- area for velocity head at the type 61 limit. */
/*     BT3ATD- beta at section 3 when barrel is full(at D!) */
/*     AP3ATD- alpha at section 3 when the barrel is full(at D!) */
/*     CC2T5 - contraction coefficient for type 5 at the type 2 flow */
/*             limit. */
/*     CC1T5 - contraction coefficient for type 5 at the type 1 flow */
/*             limit. */
/*     CC5- contraction coefficient for type 5 at its lower limit */
/*          and above. */
/*     Y3TY52- depth at section 3 at the lower limit of type 52 flow */
/*             giving the transistion between type 2 and type 5. */
/*     Y3TY51- depth at section 3 at the lower limit of type 51 flow */
/*             giving the transistion between type 1 and type 5. */
/*     BT2T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 52 and */
/*             upper limit of type 2. */
/*     BT1T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 51 and */
/*             upper limit of type 1. */
/*     AP2T5-  alpha analogous to BT2T5 */
/*     AP1T5-  alpha analogous to BT1T5 */
/*     Y3TY5-  depth at section 3 at the lower limit of type 5 flow */
/*     BT3AT5- beta for type 5 flow limit */
/*     AP3AT5- alpha for type 5 flow limit */
/*     CD5T4- coefficient of discharge that forces a type 4 equation */
/*            to match the type 5, 51, or 52 flow at the full-flow- */
/*            inducing level at section 43. */
/*     Y3LTY2- depth at section 3 at the type 2 limit, that is, */
/*             critical depth. */
/*     Y3LTY1- submergence depth at section 3  at the limit of */
/*             type 1 flow. */
/*     Y3LTY5- the full-flow-inducing value of piezometric level */
/*             relative to the invert at section 3 for flow types */
/*             5, 51, and 52. */
/* INCLUDE culvertb.for:3337 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culvertb.for:3338 */
/* SOURCE culcom.cmn:2 */
/*<        >*/
/* SOURCE culcom.cmn:8 */
/*<       integernsec(mnbn),hltab(mnbn),iat3d,iat6d,sbkind,sbshape >*/
/* SOURCE culcom.cmn:10 */
/*<        >*/
/* SOURCE culcom.cmn:16 */
/*<       doubleprecisionfrcfac >*/
/*     FRCFAC- friction factor to give factor for friction losses */
/*             in barrel for non-prismatic full-flow that as well */
/*             as prismatic full flow. */
/*     TY1YTD- maximum ratio of depth to vertical diameter for */
/*             type 1 flow. */
/*     TY1HTD- maximum ratio of head at section 1 relative to */
/*             culvert invert at culvert inlet to the vertical */
/*             diamter of the culvert.  Must be less than 1.5. */
/*     SBKIND- if 0 the slope of the culvert barrel is a constant, */
/*             if 1 the slope of the culvert barrel varies. */
/*     BSHAPE- if 0 the barrel shape is constant, that is, prismatic, */
/*             if 1 the barrel shape is nonprismatic. */
/*     TY5SBF- ratio of depth to vertical diameter of the culvert */
/*             at the exit which causes submergence. */
/* Note:  25 August 2004:  SBSHAPE is apparently not used.  BSHAPE */
/* is but outside of a common block. */
/* INCLUDE culvertb.for:3339 */
/* SOURCE rdfcom.cmn:2 */
/*<       common/rdfcom/wfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/* SOURCE rdfcom.cmn:4 */
/*<       realwfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/*     WFRDF-WATER FLUX OVER ROAD FREE CONDITION. */
/*     MFRDF-MOMENTUM FLUX OVER THE ROAD FREE CONDITION. */
/*     EFRDF-ENERGY FLUX OVER THE ROAD FREE CONDITION. */
/*     WFRD- WATER FLUX OVER THE ROAD ANY CONDITION. */
/*     MFRD- MOMENTUM FLUX OVER THE ROAD ANY CONDITION. */
/*     EFRD- ENERGY FLUX OVER THE ROAD ANY CONDITION. */
/* INCLUDE culvertb.for:3340 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertb.for:3343 */
/*<       integeri,is,knt,sflag >*/
/* SOURCE culvertb.for:3344 */
/*<       realal,ar,ccon,dh,div,kl,kr,num,qt,zt >*/
/* SOURCE culvertb.for:3345 */
/*<       doubleprecisiondx,sum >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertb.for:3348 */
/*<       intrinsicabs,sqrt >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertb.for:3351 */
/*<       externalfndcde,lkta,lktqc,sfpsbe >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertb.for:3354 */
/*<    50 format(/,' *BUG:XXX* No convergence on Q in subroutine DOTY61.') >*/
/* *********************************************************************** */
/* SOURCE culvertb.for:3356 */
/*<       y3=zp-zb >*/
/* L50: */
    xs3com_1.y3 = static_cast<double>(*zp) - *zb;
/* SOURCE culvertb.for:3357 */
/*<       calllktqc(adrxs3,y3,q) >*/
    lktqc_(&xs3com_1.adrxs3, &xs3com_1.y3, q);
/* SOURCE culvertb.for:3361 */
/*<       knt=0 >*/
    knt = 0;
/* SOURCE culvertb.for:3362 */
/*<   100 continue >*/
L100:
/* SOURCE culvertb.for:3363 */
/*<       knt=knt+1 >*/
    ++knt;
/* SOURCE culvertb.for:3364 */
/*<       if(knt.gt.100)then >*/
    if (knt > 100) {
/* SOURCE culvertb.for:3365 */
/*<       write(stdout,50) >*/
	feq_gen_io_d__337.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__337);
	e_wsfe();
/* SOURCE culvertb.for:3366 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:3367 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:3368 */
/*<       calllkta(adrxs3,y3,a3) >*/
    lkta_(&xs3com_1.adrxs3, &xs3com_1.y3, &xs3com_1.a3);
/* SOURCE culvertb.for:3373 */
/*<       dh=(1.0/cdis**2-1.0)*(q/avh)**2/grav2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = *cdis;
/* Computing 2nd power */
    feq_gen_r_d_2 = static_cast<double>(*q) / *avh;
    dh = static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - (float)1.)) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) / 
	    grvcom_1.grav2;
/*        WRITE(STDOUT,*) ' DOTY61: DH=',DH,' CDIS=',CDIS,' AVH=',AVH, */
/*     A                  ' ZP=',ZP */
/* SOURCE culvertb.for:3376 */
/*<       callsfpsbe(stdout,iu,id,dh,q,zp,is,zt,sflag) >*/
    sfpsbe_(stdout, iu, id, &dh, q, zp, &is, &zt, &sflag);
/*        IF(ZT.LT.ZB2 + DUP) THEN */
/*          WRITE(STDOUT,*) ' PROBLEM IN DOTY61' */
/*          WRITE(STDOUT,*) ' Invalid values from SFPSBE.  ZT < ZB2 + DUP' */
/*          WRITE(STDOUT,*) ' ZT=',ZT,' ZB2 + DUP=',ZB2 + DUP */
/*        ENDIF */
/* SOURCE culvertb.for:3384 */
/*<       sum=0.d0 >*/
    sum = 0.;
/* SOURCE culvertb.for:3385 */
/*<       al=avec(iu) >*/
    al = culcom_1.avec[*iu - 1];
/* SOURCE culvertb.for:3386 */
/*<       kl=kvec(iu) >*/
    kl = culcom_1.kvec[*iu - 1];
/* SOURCE culvertb.for:3387 */
/*<       do200i=iu+1,id >*/
    feq_gen_i_d_1 = *id;
    for (feq_gen_i_d_ = *iu + 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culvertb.for:3388 */
/*<       ar=avec(i) >*/
	ar = culcom_1.avec[feq_gen_i_d_ - 1];
/* SOURCE culvertb.for:3389 */
/*<       kr=kvec(i) >*/
	kr = culcom_1.kvec[feq_gen_i_d_ - 1];
/* SOURCE culvertb.for:3390 */
/*<       dx=abs(xvec(i)-xvec(i-1)) >*/
	dx = (feq_gen_r_d_1 = static_cast<double>(culcom_1.xvec[feq_gen_i_d_ - 1]) - culcom_1.xvec[feq_gen_i_d_ - 2], dabs(
		feq_gen_r_d_1));
/* SOURCE culvertb.for:3391 */
/*<       if(al.le.ar)then >*/
	if (al <= ar) {
/*           The flow is expanding. */
/* SOURCE culvertb.for:3393 */
/*<       sum=sum+dx/(kl*kr)+kd(i)*(1.0/al**2-1.0/ar**2)/grav2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = al;
/* Computing 2nd power */
	    feq_gen_r_d_2 = ar;
	    sum = sum + dx / (static_cast<double>(kl) * kr) + static_cast<double>(static_cast<double>(culcom_1.kd[feq_gen_i_d_ - 1]) * (static_cast<double>(static_cast<double>((float)1.) / (
		    static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2))) / 
		    grvcom_1.grav2;
/* SOURCE culvertb.for:3395 */
/*<       else >*/
	} else {
/*           The flow is contracting. */
/* SOURCE culvertb.for:3397 */
/*<       sum=sum+dx/(kl*kr)+ka(i)*(1.0/ar**2-1.0/al**2)/grav2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = ar;
/* Computing 2nd power */
	    feq_gen_r_d_2 = al;
	    sum = sum + dx / (static_cast<double>(kl) * kr) + static_cast<double>(static_cast<double>(culcom_1.ka[feq_gen_i_d_ - 1]) * (static_cast<double>(static_cast<double>((float)1.) / (
		    static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2))) / 
		    grvcom_1.grav2;
/* SOURCE culvertb.for:3399 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:3400 */
/*<       kl=kr >*/
	kl = kr;
/* SOURCE culvertb.for:3401 */
/*<       al=ar >*/
	al = ar;
/* SOURCE culvertb.for:3402 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE culvertb.for:3403 */
/*<       num=grav2*(z1true-zp) >*/
    num = static_cast<double>(grvcom_1.grav2) * (static_cast<double>(*z1true) - *zp);
/* SOURCE culvertb.for:3404 */
/*<        >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = *cdis;
/* Computing 2nd power */
    feq_gen_r_d_2 = static_cast<double>(*avh) / xs3com_1.a3;
/* Computing 2nd power */
    feq_gen_r_d_3 = *avh;
/* Computing 2nd power */
    feq_gen_r_d_4 = *a1true;
    div = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1 * (static_cast<double>(static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2) - (float)1. + static_cast<double>(grvcom_1.grav2) * (static_cast<double>(feq_gen_r_d_3) * 
	    feq_gen_r_d_3) * (static_cast<double>(appcom_1.applen) / (static_cast<double>(*k1true) * xs2com_1.k2full) + sum - static_cast<double>((static_cast<double>(*
	    alp1t) - appcom_1.applos)) / (static_cast<double>(grvcom_1.grav2) * (static_cast<double>(feq_gen_r_d_4) * feq_gen_r_d_4)))) + (
	    float)1.;
/*        WRITE(STDOUT,*) ' DIV=',DIV,' SUM=',FRCFAC,' ZT=',ZT */
/*        WRITE(STDOUT,*) 'DOTY61: AVH=',AVH,' NUM=',NUM */
/*        WRITE(STDOUT,*) ' Z1TRUE=',Z1TRUE,' ZP=',ZP,' WFRDF=',WFRDF, */
/*     A       ' A1TRUE=',A1TRUE,' K1TRUE=',K1TRUE,' K2FULL=',K2FULL, */
/*     B       ' ALP1T=',ALP1T,' APPLOS=',APPLOS,' GRAV2=',GRAV2, */
/*     C       ' APPLEN=',APPLEN */
/*        WRITE(STDOUT,*) ' A3=',A3 */
/* SOURCE culvertb.for:3414 */
/*<       if(wfrdf.gt.0.0)then >*/
    if (rdfcom_1.wfrdf > (float)0.) {
/*         Add terms to the numerator to represent values affected */
/*         by flow over the road. */
/* SOURCE culvertb.for:3417 */
/*<        >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = *a1true;
	num += static_cast<double>(rdfcom_1.wfrdf) * (static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>(*alp1t) - appcom_1.applos)) * (static_cast<double>(static_cast<double>(rdfcom_1.wfrdf) 
		+ *q) + *q)) / (static_cast<double>(grvcom_1.grav2) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1))) - 
		static_cast<double>(static_cast<double>(appcom_1.applen) * *q) / (static_cast<double>(*k1true) * xs2com_1.k2full));
/* SOURCE culvertb.for:3420 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:3421 */
/*<       qt=cdis*avh*sqrt(num/div) >*/
    qt = static_cast<double>(*cdis) * *avh * sqrt(static_cast<double>(num) / div);
/*       Adjust the piezometric level at 3 for the latest flow. */
/* SOURCE culvertb.for:3424 */
/*<       callfndcde(stdout,adrxs3,qt,y3) >*/
    fndcde_(stdout, &xs3com_1.adrxs3, &qt, &xs3com_1.y3);
/* SOURCE culvertb.for:3428 */
/*<       zp=zb+y3 >*/
    *zp = static_cast<double>(*zb) + xs3com_1.y3;
/*        WRITE(STDOUT,*) ' DOTY61: KNT=',KNT,' Q=',Q,' QT=',QT */
/* SOURCE culvertb.for:3431 */
/*<       if(abs(qt-q)/q.gt.epsf)then >*/
    if ((feq_gen_r_d_1 = static_cast<double>(qt) - *q, dabs(feq_gen_r_d_1)) / *q > epscom_1.epsf) {
/* SOURCE culvertb.for:3432 */
/*<       q=qt >*/
	*q = qt;
/* SOURCE culvertb.for:3433 */
/*<       goto100 >*/
	goto L100;
/* SOURCE culvertb.for:3434 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:3435 */
/*<       q=qt >*/
    *q = qt;
/*     Compute estimate of the piezometric level at section 2.   Estimate */
/*     the coefficient of contraction from the discharge coefficient. */
/*     Includes effect of vena contracta near entrance. */
/* SOURCE culvertb.for:3440 */
/*<       ccon=1.0/(sqrt(1.0/cdis**2-1.0)+1.0) >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = *cdis;
    ccon = (float)1. / (sqrt(static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - (float)1.) + (float)
	    1.);
/* SOURCE culvertb.for:3441 */
/*<        >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>((static_cast<double>(*q) + rdfcom_1.wfrdf)) / *a1true;
/* Computing 2nd power */
    feq_gen_r_d_2 = static_cast<double>(*q) / (static_cast<double>(ccon) * xs2com_1.a2full);
    *zat2 = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(*alp1t) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / grvcom_1.grav2) + *z1true) - static_cast<double>(static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2) / 
	    grvcom_1.grav2;
/*      WRITE(STDOUT,*) ' DOTY61: ZAT2=',ZAT2,' CCON=',CCON */
/* SOURCE culvertb.for:3444 */
/*<       return >*/
    return 0;
/* SOURCE culvertb.for:3445 */
/*<       end >*/
} /* doty61_ */




/* SOURCE culvertb.for:3449 */
/*<       subroutinef6bdy(stdout,hdatum,hup,iu,id,culcls,eflag,zp,q6,zat2) >*/
/* Subroutine */ int f6bdy_(integer *stdout, real *hdatum, real *hup, integer 
	*iu, integer *id, char *culcls, integer *eflag, real *zp, real *q6, 
	real *zat2, ftnlen culcls_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:689* Flow type 6 limit not defined.\
 Approach\002,\002 and/or\002,/,11x,\002departure elevation unrealistic.\002)"
	    ;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe();

    /* Local variables */
    real feq_gen_z_d_, ddn, dup;
    extern /* Subroutine */ int doty6_(integer *, char *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, ftnlen);
    real fdrdw;
    extern /* Subroutine */ int getfrf_(real *, real *, real *);
    real zsbrdf;
    extern /* Subroutine */ int xlktal_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__356 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Find the flow and piezometric level at the type 6 flow boundary. */
/* SOURCE culvertb.for:3456 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertb.for:3459 */
/*<       integereflag,id,iu,stdout >*/
/* SOURCE culvertb.for:3460 */
/*<       realhdatum,hup,q6,zat2,zp >*/
/* SOURCE culvertb.for:3461 */
/*<       characterculcls*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     HDATUM - Datum for measuring head */
/*     HUP    - Head upstream */
/*     IU     - Index for upstream node for the culvert barrel */
/*     ID     - Index for the downstream node for the culvert barrel */
/*     CULCLS - Class for culvert shape, BOX, PIPE, .. */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     ZP     - elevation of the piezometric surface at section 3 */
/*     Q6     - free flow of type 6 */
/*     ZAT2   - elevation of water surface at section 2 */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertb.for:3476 */
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
/* INCLUDE culvertb.for:3477 */
/* SOURCE cdcom.cmn:2 */
/*<        >*/
/* SOURCE cdcom.cmn:10 */
/*<        >*/
/* SOURCE cdcom.cmn:14 */
/*<        >*/
/*     Add values for support of FHWA type 5 scheme. Oct. 3, 2001 */
/* SOURCE cdcom.cmn:20 */
/*<       realafhwa,cfhwa,yfhwa,sfhwa >*/
/*     AFHWA - value of a */
/*     CFHWA - value of c */
/*     YFHWA - value of Y */
/*     SFHWA - slope of culvert near entrance. */
/* INCLUDE culvertb.for:3478 */
/* SOURCE xs1com.cmn:2 */
/*<        >*/
/* SOURCE xs1com.cmn:7 */
/*<       integeradrxs1 >*/
/* SOURCE xs1com.cmn:9 */
/*<        >*/
/*     Z1TY1- elevation at section 1 at type 1 limit if it exists */
/*     Z1TY1L-elevation at section 1 at lower limit of type 1 if it exists */
/*     Z1TY6- elevation at section 1 at start of type 6 if it exists */
/*     Z1TY2- elevation at upper limit of type 2 flow if it exists */
/*     Z1TY61- elevation at upper limt of type 61 if it exists */
/*     Z1TY5- elevation at section at start of type 5 if it exists */
/*     Z1TY52- elevation at section 1 at lower limit of type 52( */
/*             type 2 to type 5 flow) */
/*     Z1TY51- elevation at section 1 at lower limit of type 51( */
/*             type 1 to type 5 flow) */
/* INCLUDE culvertb.for:3479 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culvertb.for:3480 */
/* SOURCE xs3com.cmn:2 */
/*<        >*/
/* SOURCE xs3com.cmn:11 */
/*<       integeradrxs3 >*/
/* SOURCE xs3com.cmn:13 */
/*<        >*/
/*     CD1- if 0.0 type 1 flow has not been checked, if > 0 type 1 */
/*          flow has been checked and found to exist and its limit */
/*          values have been found, if < 0 type 1 flow does not exist. */
/*     CD2T6- coef. of discharge forcing full flow to match flow */
/*            at the type 2 flow limit. */
/*     AP2T6 - kinetic energy flux coefficient forcing the full */
/*             flow kinetic energy flux to match the flux */
/*             at the type 2 limit. */
/*     BT2T6- momentum flux coefficient forcing the full flow */
/*            momentum flux to match the flux at the type 2 limit. */
/*     CD61T6- coef. of discharge forcing full flow to match flow */
/*             at the type 61 limit. */
/*     CD1T6- coef. of discharge forcing full flow to match flow */
/*            at the type 1 limit */

/*     AP61T6- same as AP2T6 for type 61. */
/*     BT61T6- same as AP2T6 for type 61. */
/*     CD2- coef. of discharge for type 2 flow at the type 2 limit. */
/*     CD61- coef. of discharge for type 61 flow at the type 61 limit. */
/*     CD6- coef. of discharge for type 6 flow. */
/*     Z3PTY6- piezometric level at section 3 at the type 6 limit. */
/*     AVH2- area for velocity head at the type 2 limit. */
/*     AVH61- area for velocity head at the type 61 limit. */
/*     BT3ATD- beta at section 3 when barrel is full(at D!) */
/*     AP3ATD- alpha at section 3 when the barrel is full(at D!) */
/*     CC2T5 - contraction coefficient for type 5 at the type 2 flow */
/*             limit. */
/*     CC1T5 - contraction coefficient for type 5 at the type 1 flow */
/*             limit. */
/*     CC5- contraction coefficient for type 5 at its lower limit */
/*          and above. */
/*     Y3TY52- depth at section 3 at the lower limit of type 52 flow */
/*             giving the transistion between type 2 and type 5. */
/*     Y3TY51- depth at section 3 at the lower limit of type 51 flow */
/*             giving the transistion between type 1 and type 5. */
/*     BT2T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 52 and */
/*             upper limit of type 2. */
/*     BT1T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 51 and */
/*             upper limit of type 1. */
/*     AP2T5-  alpha analogous to BT2T5 */
/*     AP1T5-  alpha analogous to BT1T5 */
/*     Y3TY5-  depth at section 3 at the lower limit of type 5 flow */
/*     BT3AT5- beta for type 5 flow limit */
/*     AP3AT5- alpha for type 5 flow limit */
/*     CD5T4- coefficient of discharge that forces a type 4 equation */
/*            to match the type 5, 51, or 52 flow at the full-flow- */
/*            inducing level at section 43. */
/*     Y3LTY2- depth at section 3 at the type 2 limit, that is, */
/*             critical depth. */
/*     Y3LTY1- submergence depth at section 3  at the limit of */
/*             type 1 flow. */
/*     Y3LTY5- the full-flow-inducing value of piezometric level */
/*             relative to the invert at section 3 for flow types */
/*             5, 51, and 52. */
/* INCLUDE culvertb.for:3481 */
/*     Common to hold values needed for computing various limits */
/*     for culvert flow types. */
/* SOURCE typlim.cmn:4 */
/*<        >*/
/* SOURCE typlim.cmn:10 */
/*<       integerhhtype >*/
/* SOURCE typlim.cmn:12 */
/*<        >*/
/* INCLUDE culvertb.for:3482 */
/* SOURCE culcom.cmn:2 */
/*<        >*/
/* SOURCE culcom.cmn:8 */
/*<       integernsec(mnbn),hltab(mnbn),iat3d,iat6d,sbkind,sbshape >*/
/* SOURCE culcom.cmn:10 */
/*<        >*/
/* SOURCE culcom.cmn:16 */
/*<       doubleprecisionfrcfac >*/
/*     FRCFAC- friction factor to give factor for friction losses */
/*             in barrel for non-prismatic full-flow that as well */
/*             as prismatic full flow. */
/*     TY1YTD- maximum ratio of depth to vertical diameter for */
/*             type 1 flow. */
/*     TY1HTD- maximum ratio of head at section 1 relative to */
/*             culvert invert at culvert inlet to the vertical */
/*             diamter of the culvert.  Must be less than 1.5. */
/*     SBKIND- if 0 the slope of the culvert barrel is a constant, */
/*             if 1 the slope of the culvert barrel varies. */
/*     BSHAPE- if 0 the barrel shape is constant, that is, prismatic, */
/*             if 1 the barrel shape is nonprismatic. */
/*     TY5SBF- ratio of depth to vertical diameter of the culvert */
/*             at the exit which causes submergence. */
/* Note:  25 August 2004:  SBSHAPE is apparently not used.  BSHAPE */
/* is but outside of a common block. */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertb.for:3485 */
/*<       realddn,dup,fdrdw,z,zsbrdf >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertb.for:3488 */
/*<       externaldoty6,getfrf,xlktal >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertb.for:3491 */
/*<    50  >*/
/* *********************************************************************** */
/*     The type 6 flow boundary is set at an approach head ratio */
/*     of 1.5.  We need to know the piezometric level at the outlet */
/*     for some of the transitions. */
/* SOURCE culvertb.for:3497 */
/*<       dup=dvec(iu) >*/
/* L50: */
    dup = culcom_1.dvec[*iu - 1];
/* SOURCE culvertb.for:3498 */
/*<       ddn=dvec(id) >*/
    ddn = culcom_1.dvec[*id - 1];
/* SOURCE culvertb.for:3499 */
/*<       if(zb2.ge.zb3)then >*/
    if (xs2com_1.zb2 >= xs3com_1.zb3) {
/*       Barrel slope is >= 0. */
/* SOURCE culvertb.for:3501 */
/*<       z=zb2+1.5*dup >*/
	feq_gen_z_d_ = static_cast<double>(xs2com_1.zb2) + static_cast<double>(dup) * (float)1.5;
/* SOURCE culvertb.for:3502 */
/*<       else >*/
    } else {
/*       Barrel slope is adverse, that is, < 0. */
/* SOURCE culvertb.for:3504 */
/*<       z=zb3+1.5*ddn >*/
	feq_gen_z_d_ = static_cast<double>(xs3com_1.zb3) + static_cast<double>(ddn) * (float)1.5;
/* SOURCE culvertb.for:3505 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:3506 */
/*<       if(z.le.hdatum)then >*/
    if (feq_gen_z_d_ <= *hdatum) {
/* SOURCE culvertb.for:3507 */
/*<       write(stdout,50) >*/
	feq_gen_io_d__356.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__356);
	e_wsfe();
/* SOURCE culvertb.for:3508 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE culvertb.for:3509 */
/*<       return >*/
	return 0;
/* SOURCE culvertb.for:3510 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:3511 */
/*<       callgetfrf(z,zsbrdf,fdrdw) >*/
    getfrf_(&feq_gen_z_d_, &zsbrdf, &fdrdw);
/* SOURCE culvertb.for:3514 */
/*<       y1l=z-zb1 >*/
    typlim_1.y1l = static_cast<double>(feq_gen_z_d_) - xs1com_1.zb1;
/* SOURCE culvertb.for:3515 */
/*<        >*/
    xlktal_(&xs1com_1.adrxs1, &typlim_1.y1l, &typlim_1.a1l, &typlim_1.t1l, &
	    typlim_1.dt1l, &typlim_1.j1l, &typlim_1.k1l, &typlim_1.dk1l, &
	    typlim_1.bet1l, &typlim_1.dbet1l, &typlim_1.alp1l, &
	    typlim_1.dalp1l);
/* SOURCE culvertb.for:3520 */
/*<       cd6=c46 >*/
    xs3com_1.cd6 = cdcom_1.c46;
/* SOURCE culvertb.for:3521 */
/*<        >*/
    doty6_(stdout, culcls, &typlim_1.a1l, &typlim_1.alp1l, &typlim_1.k1l, &
	    feq_gen_z_d_, &xs2com_1.a2full, &xs2com_1.k2full, &xs3com_1.a3full, &ddn, &
	    xs3com_1.zb3, &xs3com_1.cd6, zp, q6, zat2, (ftnlen)8);
/* SOURCE culvertb.for:3526 */
/*<       z1ty6=z >*/
    xs1com_1.z1ty6 = feq_gen_z_d_;
/*     Compute the free flow values for the current upstream */
/*     level. */
/* SOURCE culvertb.for:3530 */
/*<       z=hup+hdatum >*/
    feq_gen_z_d_ = static_cast<double>(*hup) + *hdatum;
/* SOURCE culvertb.for:3531 */
/*<       callgetfrf(z,zsbrdf,fdrdw) >*/
    getfrf_(&feq_gen_z_d_, &zsbrdf, &fdrdw);
/* SOURCE culvertb.for:3535 */
/*<       return >*/
    return 0;
/* SOURCE culvertb.for:3536 */
/*<       end >*/
} /* f6bdy_ */




/* SOURCE culvertb.for:3540 */
/*<        >*/
/* Subroutine */ int f61bdy_(integer *stdout, integer *feq_gen_type_d_, real *hdatum, 
	real *zdatum, real *hup, integer *iu, integer *id, char *culcls, real 
	*y2val, integer *eflag, ftnlen culcls_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *BUG:XXX* Maximum argument=\002,f10.3\
,\002 reached and no\002,\002 sign change in F61BDY\002)";
    static char fmt_54[] = "(\002 *BUG:XXX* SIGN CHNG ON ENTRY BUT RGF CLAIM\
S NONE IN\002,\002 F61BDY.\002)";
    static char fmt_60[] = "(\002 *BUG:XXX* RGF: MORE THAN 100 ITERATIONS IN\
 F61BDY.\002)";

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(), s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), 
	    e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_mess_out_d_;
    real f, y, feq_gen_z_d_, zt, ddn;
    extern /* Subroutine */ int rgf_(real *, real *, FeqCallback3, real *, real *, 
	    real *, real *, real *, integer *);
    real dup;
    integer knt, knt2, feq_gen_flag_d_;
    real flow, ymax, zmin;
    extern doublereal rty61_(real *);
    real zlow, fhigh, fdrdw, zhigh, zsbrdf;
    extern doublereal fmxarg_(integer *);
    extern /* Subroutine */ int getfrf_(real *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__370 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__372 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__376 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__378 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__379 = { 0, 0, 0, fmt_60, 0 };


/*     + + + PURPOSE + + + */
/*     Find the elevation at section 1 such that the computed water */
/*     level at section 2 matches the value, Y2VAL.  The flow is */
/*     always part full and at critical depth at section 3. */
/* SOURCE culvertb.for:3550 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertb.for:3553 */
/*<       integereflag,id,iu,stdout,type >*/
/* SOURCE culvertb.for:3554 */
/*<       realhdatum,hup,y2val,zdatum >*/
/* SOURCE culvertb.for:3555 */
/*<       characterculcls*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     TYPE   - culvert flow type */
/*     HDATUM - Datum for measuring head */
/*     ZDATUM - datum for local elevation */
/*     HUP    - Head upstream */
/*     IU     - Index for upstream node for the culvert barrel */
/*     ID     - Index for the downstream node for the culvert barrel */
/*     CULCLS - Class for culvert shape, BOX, PIPE, .. */
/*     Y2VAL  - value of depth at section 2 */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertb.for:3570 */
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
/* INCLUDE culvertb.for:3571 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE culvertb.for:3572 */
/* SOURCE cdcom.cmn:2 */
/*<        >*/
/* SOURCE cdcom.cmn:10 */
/*<        >*/
/* SOURCE cdcom.cmn:14 */
/*<        >*/
/*     Add values for support of FHWA type 5 scheme. Oct. 3, 2001 */
/* SOURCE cdcom.cmn:20 */
/*<       realafhwa,cfhwa,yfhwa,sfhwa >*/
/*     AFHWA - value of a */
/*     CFHWA - value of c */
/*     YFHWA - value of Y */
/*     SFHWA - slope of culvert near entrance. */
/* INCLUDE culvertb.for:3573 */
/* SOURCE xs1com.cmn:2 */
/*<        >*/
/* SOURCE xs1com.cmn:7 */
/*<       integeradrxs1 >*/
/* SOURCE xs1com.cmn:9 */
/*<        >*/
/*     Z1TY1- elevation at section 1 at type 1 limit if it exists */
/*     Z1TY1L-elevation at section 1 at lower limit of type 1 if it exists */
/*     Z1TY6- elevation at section 1 at start of type 6 if it exists */
/*     Z1TY2- elevation at upper limit of type 2 flow if it exists */
/*     Z1TY61- elevation at upper limt of type 61 if it exists */
/*     Z1TY5- elevation at section at start of type 5 if it exists */
/*     Z1TY52- elevation at section 1 at lower limit of type 52( */
/*             type 2 to type 5 flow) */
/*     Z1TY51- elevation at section 1 at lower limit of type 51( */
/*             type 1 to type 5 flow) */
/* INCLUDE culvertb.for:3574 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culvertb.for:3575 */
/* SOURCE xs3com.cmn:2 */
/*<        >*/
/* SOURCE xs3com.cmn:11 */
/*<       integeradrxs3 >*/
/* SOURCE xs3com.cmn:13 */
/*<        >*/
/*     CD1- if 0.0 type 1 flow has not been checked, if > 0 type 1 */
/*          flow has been checked and found to exist and its limit */
/*          values have been found, if < 0 type 1 flow does not exist. */
/*     CD2T6- coef. of discharge forcing full flow to match flow */
/*            at the type 2 flow limit. */
/*     AP2T6 - kinetic energy flux coefficient forcing the full */
/*             flow kinetic energy flux to match the flux */
/*             at the type 2 limit. */
/*     BT2T6- momentum flux coefficient forcing the full flow */
/*            momentum flux to match the flux at the type 2 limit. */
/*     CD61T6- coef. of discharge forcing full flow to match flow */
/*             at the type 61 limit. */
/*     CD1T6- coef. of discharge forcing full flow to match flow */
/*            at the type 1 limit */

/*     AP61T6- same as AP2T6 for type 61. */
/*     BT61T6- same as AP2T6 for type 61. */
/*     CD2- coef. of discharge for type 2 flow at the type 2 limit. */
/*     CD61- coef. of discharge for type 61 flow at the type 61 limit. */
/*     CD6- coef. of discharge for type 6 flow. */
/*     Z3PTY6- piezometric level at section 3 at the type 6 limit. */
/*     AVH2- area for velocity head at the type 2 limit. */
/*     AVH61- area for velocity head at the type 61 limit. */
/*     BT3ATD- beta at section 3 when barrel is full(at D!) */
/*     AP3ATD- alpha at section 3 when the barrel is full(at D!) */
/*     CC2T5 - contraction coefficient for type 5 at the type 2 flow */
/*             limit. */
/*     CC1T5 - contraction coefficient for type 5 at the type 1 flow */
/*             limit. */
/*     CC5- contraction coefficient for type 5 at its lower limit */
/*          and above. */
/*     Y3TY52- depth at section 3 at the lower limit of type 52 flow */
/*             giving the transistion between type 2 and type 5. */
/*     Y3TY51- depth at section 3 at the lower limit of type 51 flow */
/*             giving the transistion between type 1 and type 5. */
/*     BT2T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 52 and */
/*             upper limit of type 2. */
/*     BT1T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 51 and */
/*             upper limit of type 1. */
/*     AP2T5-  alpha analogous to BT2T5 */
/*     AP1T5-  alpha analogous to BT1T5 */
/*     Y3TY5-  depth at section 3 at the lower limit of type 5 flow */
/*     BT3AT5- beta for type 5 flow limit */
/*     AP3AT5- alpha for type 5 flow limit */
/*     CD5T4- coefficient of discharge that forces a type 4 equation */
/*            to match the type 5, 51, or 52 flow at the full-flow- */
/*            inducing level at section 43. */
/*     Y3LTY2- depth at section 3 at the type 2 limit, that is, */
/*             critical depth. */
/*     Y3LTY1- submergence depth at section 3  at the limit of */
/*             type 1 flow. */
/*     Y3LTY5- the full-flow-inducing value of piezometric level */
/*             relative to the invert at section 3 for flow types */
/*             5, 51, and 52. */
/* INCLUDE culvertb.for:3576 */
/* SOURCE culcom.cmn:2 */
/*<        >*/
/* SOURCE culcom.cmn:8 */
/*<       integernsec(mnbn),hltab(mnbn),iat3d,iat6d,sbkind,sbshape >*/
/* SOURCE culcom.cmn:10 */
/*<        >*/
/* SOURCE culcom.cmn:16 */
/*<       doubleprecisionfrcfac >*/
/*     FRCFAC- friction factor to give factor for friction losses */
/*             in barrel for non-prismatic full-flow that as well */
/*             as prismatic full flow. */
/*     TY1YTD- maximum ratio of depth to vertical diameter for */
/*             type 1 flow. */
/*     TY1HTD- maximum ratio of head at section 1 relative to */
/*             culvert invert at culvert inlet to the vertical */
/*             diamter of the culvert.  Must be less than 1.5. */
/*     SBKIND- if 0 the slope of the culvert barrel is a constant, */
/*             if 1 the slope of the culvert barrel varies. */
/*     BSHAPE- if 0 the barrel shape is constant, that is, prismatic, */
/*             if 1 the barrel shape is nonprismatic. */
/*     TY5SBF- ratio of depth to vertical diameter of the culvert */
/*             at the exit which causes submergence. */
/* Note:  25 August 2004:  SBSHAPE is apparently not used.  BSHAPE */
/* is but outside of a common block. */
/* INCLUDE culvertb.for:3577 */
/*     Commons for function RTY6 in FEQUTL */
/* SOURCE rty6c.cmn:3 */
/*<        >*/
/* SOURCE rty6c.cmn:6 */
/*<       integeriup,idn,outun,ef,conf,ftype,nsf,sbflag >*/
/* SOURCE rty6c.cmn:7 */
/*<       realz1true,aclv,yc,z3pt,aexit,ta1,dht,yat2,zdat >*/
/* SOURCE rty6c.cmn:9 */
/*<       common/rty6cc/class >*/
/* SOURCE rty6c.cmn:10 */
/*<       character*8class >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertb.for:3580 */
/*<       integerflag,knt,knt2,mess_out >*/
/* SOURCE culvertb.for:3581 */
/*<       realddn,dup,f,fdrdw,fhigh,flow,y,ymax,z,zhigh,zlow,zmin,zsbrdf,zt >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertb.for:3585 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertb.for:3588 */
/*<       realfmxarg,rty61 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertb.for:3591 */
/*<       externalfmxarg,getfrf,rgf,rty61 >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertb.for:3594 */
/*<    50  >*/
/* SOURCE culvertb.for:3596 */
/*<    54  >*/
/* SOURCE culvertb.for:3598 */
/*<    60 format(' *BUG:XXX* RGF: MORE THAN 100 ITERATIONS IN F61BDY.') >*/
/* *********************************************************************** */
/*     Allow five residual problem mesages */
/* SOURCE culvertb.for:3601 */
/*<       mess_out=5 >*/
/* L50: */
/* L54: */
/* L60: */
    feq_gen_mess_out_d_ = 5;
/*     Clear the error flag */
/* SOURCE culvertb.for:3604 */
/*<       eflag=0 >*/
    *eflag = 0;
/* SOURCE culvertb.for:3605 */
/*<       iup=iu >*/
    rty6c_1.iup = *iu;
/* SOURCE culvertb.for:3606 */
/*<       idn=id >*/
    rty6c_1.idn = *id;
/* SOURCE culvertb.for:3607 */
/*<       outun=stdout >*/
    rty6c_1.outun = *stdout;
/* SOURCE culvertb.for:3608 */
/*<       ef=0 >*/
    rty6c_1.ef = 0;
/* SOURCE culvertb.for:3609 */
/*<       ftype=type >*/
    rty6c_1.ftype = *feq_gen_type_d_;
/* SOURCE culvertb.for:3610 */
/*<       class=culcls >*/
    s_copy(rty6cc_1.feq_gen_class_d_, culcls, (ftnlen)8, (ftnlen)8);
/* SOURCE culvertb.for:3611 */
/*<       yat2=y2val >*/
    rty6c_1.yat2 = *y2val;
/* SOURCE culvertb.for:3612 */
/*<       zdat=zdatum >*/
    rty6c_1.zdat = *zdatum;
/* SOURCE culvertb.for:3613 */
/*<       ddn=dvec(idn) >*/
    ddn = culcom_1.dvec[rty6c_1.idn - 1];
/* SOURCE culvertb.for:3614 */
/*<       dup=dvec(iup) >*/
    dup = culcom_1.dvec[rty6c_1.iup - 1];
/* SOURCE culvertb.for:3615 */
/*<       zmin=yat2+zb2 >*/
    zmin = static_cast<double>(rty6c_1.yat2) + xs2com_1.zb2;
/*      WRITE(STDOUT,*) ' F61BDY: ZMIN=',ZMIN */
/*     Search for a change in sign of the residual. */
/* SOURCE culvertb.for:3618 */
/*<       if(type.eq.2)then >*/
    if (*feq_gen_type_d_ == 2) {
/* SOURCE culvertb.for:3619 */
/*<       if(cd1.gt.0.0)then >*/
	if (xs3com_1.cd1 > (float)0.) {
/* SOURCE culvertb.for:3620 */
/*<       z=z1ty1+0.01*dup >*/
	    feq_gen_z_d_ = static_cast<double>(xs1com_1.z1ty1) + static_cast<double>(dup) * (float).01;
/* SOURCE culvertb.for:3621 */
/*<       zmin=z1ty1 >*/
	    zmin = xs1com_1.z1ty1;
/*          WRITE(STDOUT,*)' F61BDY: Z SET BY Z1TY1=',Z */
/* SOURCE culvertb.for:3623 */
/*<       if(z.lt.zb2+1.1*dup)then >*/
	    if (feq_gen_z_d_ < static_cast<double>(xs2com_1.zb2) + static_cast<double>(dup) * (float)1.1) {
/* SOURCE culvertb.for:3624 */
/*<       z=zb2+zb2+1.1*dup >*/
		feq_gen_z_d_ = static_cast<double>(static_cast<double>(xs2com_1.zb2) + xs2com_1.zb2) + static_cast<double>(dup) * (float)1.1;
/*            WRITE(STDOUT,*) ' F61BDY: Z RESET TO:',Z */
/* SOURCE culvertb.for:3626 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:3627 */
/*<       else >*/
	} else {
/* SOURCE culvertb.for:3628 */
/*<       if(zb2.lt.zb3)then >*/
	    if (xs2com_1.zb2 < xs3com_1.zb3) {
/*           Adverse barrel slope */
/* SOURCE culvertb.for:3630 */
/*<       if(zb3.ge.zb2+dup)then >*/
		if (xs3com_1.zb3 >= static_cast<double>(xs2com_1.zb2) + dup) {
/*             Type 2 flow does not exist.  Zero head has entrance */
/*             soffit at or below water surface. */
/* SOURCE culvertb.for:3633 */
/*<       eflag=-1 >*/
		    *eflag = -1;
/* SOURCE culvertb.for:3634 */
/*<       return >*/
		    return 0;
/* SOURCE culvertb.for:3635 */
/*<       else >*/
		} else {
/* SOURCE culvertb.for:3636 */
/*<       z=zb2+dup+0.1*(zb2+dup-zb3) >*/
		    feq_gen_z_d_ = static_cast<double>(static_cast<double>(xs2com_1.zb2) + dup) + static_cast<double>((static_cast<double>(static_cast<double>(xs2com_1.zb2) + dup) - 
			    xs3com_1.zb3)) * (float).1;
/* SOURCE culvertb.for:3637 */
/*<       endif >*/
		}
/* SOURCE culvertb.for:3638 */
/*<       else >*/
	    } else {
/* SOURCE culvertb.for:3639 */
/*<       z=1.2*dup+zb2 >*/
		feq_gen_z_d_ = static_cast<double>(static_cast<double>(dup) * (float)1.2) + xs2com_1.zb2;
/* SOURCE culvertb.for:3640 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:3641 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:3642 */
/*<       y=z-zb1 >*/
	y = static_cast<double>(feq_gen_z_d_) - xs1com_1.zb1;
/* SOURCE culvertb.for:3643 */
/*<       if(y.lt.0.0)then >*/
	if (y < (float)0.) {
/* SOURCE culvertb.for:3644 */
/*<       y=0.1*dup >*/
	    y = static_cast<double>(dup) * (float).1;
/* SOURCE culvertb.for:3645 */
/*<       z=zb1+y >*/
	    feq_gen_z_d_ = static_cast<double>(xs1com_1.zb1) + y;
/* SOURCE culvertb.for:3646 */
/*<       if(z.gt.1.5*dup+zb2)then >*/
	    if (feq_gen_z_d_ > static_cast<double>(static_cast<double>(dup) * (float)1.5) + xs2com_1.zb2) {
/*           Type 2 limit does not exist. */
/* SOURCE culvertb.for:3648 */
/*<       eflag=-1 >*/
		*eflag = -1;
/* SOURCE culvertb.for:3649 */
/*<       return >*/
		return 0;
/* SOURCE culvertb.for:3650 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:3651 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:3652 */
/*<       else >*/
    } else {
/* SOURCE culvertb.for:3653 */
/*<       z=1.2*ddn+zb3 >*/
	feq_gen_z_d_ = static_cast<double>(static_cast<double>(ddn) * (float)1.2) + xs3com_1.zb3;
/* SOURCE culvertb.for:3654 */
/*<       y=z-zb1 >*/
	y = static_cast<double>(feq_gen_z_d_) - xs1com_1.zb1;
/* SOURCE culvertb.for:3655 */
/*<       if(y.lt.0.0)then >*/
	if (y < (float)0.) {
/* SOURCE culvertb.for:3656 */
/*<       y=0.1*ddn >*/
	    y = static_cast<double>(ddn) * (float).1;
/* SOURCE culvertb.for:3657 */
/*<       z=zb1+y >*/
	    feq_gen_z_d_ = static_cast<double>(xs1com_1.zb1) + y;
/* SOURCE culvertb.for:3658 */
/*<       if(z.gt.1.5*ddn+zb3)then >*/
	    if (feq_gen_z_d_ > static_cast<double>(static_cast<double>(ddn) * (float)1.5) + xs3com_1.zb3) {
/*           Type 61 limit does not exist. */
/* SOURCE culvertb.for:3660 */
/*<       eflag=-1 >*/
		*eflag = -1;
/* SOURCE culvertb.for:3661 */
/*<       return >*/
		return 0;
/* SOURCE culvertb.for:3662 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:3663 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:3664 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:3666 */
/*<       ymax=fmxarg(adrxs1) >*/
    ymax = fmxarg_(&xs1com_1.adrxs1);
/* SOURCE culvertb.for:3667 */
/*<       zlow=0.0 >*/
    zlow = (float)0.;
/* SOURCE culvertb.for:3668 */
/*<       zhigh=0.0 >*/
    zhigh = (float)0.;
/* SOURCE culvertb.for:3669 */
/*<       knt=0 >*/
    knt = 0;
/* SOURCE culvertb.for:3670 */
/*<       knt2=0 >*/
    knt2 = 0;
/* SOURCE culvertb.for:3672 */
/*<   100 continue >*/
L100:
/* SOURCE culvertb.for:3673 */
/*<       knt=knt+1 >*/
    ++knt;
/* SOURCE culvertb.for:3674 */
/*<       if(knt.gt.100)then >*/
    if (knt > 100) {
/* SOURCE culvertb.for:3675 */
/*<       write(outun,*)' No sign change in F61BDY after 100 tries.' >*/
	feq_gen_io_d__370.ciunit = rty6c_1.outun;
	s_wsle(&feq_gen_io_d__370);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" No sign change in F61BDY after 100 tries."), (
		ftnlen)42);
	e_wsle();
/* SOURCE culvertb.for:3676 */
/*<       eflag=-1 >*/
	*eflag = -1;
/* SOURCE culvertb.for:3677 */
/*<       goto999 >*/
	goto L999;
/* SOURCE culvertb.for:3678 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:3679 */
/*<       f=rty61(z) >*/
    f = rty61_(&feq_gen_z_d_);
/*        WRITE(OUTUN,*) ' F61BDY: Z=',Z,' Y1=',Z-ZB1,' F=',F */
/*        WRITE(OUTUN,*) ' ZMIN=',ZMIN,' SBFLAG=',SBFLAG */
/* SOURCE culvertb.for:3683 */
/*<       if(sbflag.eq.-1)then >*/
    if (rty6c_1.sbflag == -1) {
/*         Special action required.  Steady flow profile from critical */
/*         depth failed to complete or sqrt of negative number. */
/*         Increase Z and try again. */
/* SOURCE culvertb.for:3687 */
/*<       knt2=knt2+1 >*/
	++knt2;
/* SOURCE culvertb.for:3688 */
/*<       if(knt2.gt.100)then >*/
	if (knt2 > 100) {
/*           Apparently type 2 limit does not exist. */
/* SOURCE culvertb.for:3690 */
/*<       eflag=-1 >*/
	    *eflag = -1;
/* SOURCE culvertb.for:3691 */
/*<       goto999 >*/
	    goto L999;
/* SOURCE culvertb.for:3692 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:3693 */
/*<       if(mess_out.gt.0)then >*/
	if (feq_gen_mess_out_d_ > 0) {
/* SOURCE culvertb.for:3694 */
/*<       write(outun,*)' RTY61: Residual problem. Z=',z >*/
	    feq_gen_io_d__372.ciunit = rty6c_1.outun;
	    s_wsle(&feq_gen_io_d__372);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" RTY61: Residual problem. Z="), (ftnlen)28);
	    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&feq_gen_z_d_, (ftnlen)sizeof(real));
	    e_wsle();
/* SOURCE culvertb.for:3695 */
/*<       mess_out=mess_out-1 >*/
	    --feq_gen_mess_out_d_;
/* SOURCE culvertb.for:3696 */
/*<       endif >*/
	}
/*         Upstream elevation and flow are related.  If the */
/*         profile failed at this elevation it will fail at any */
/*         lower elevation.  Upgrade the minimum elevation. */
/* SOURCE culvertb.for:3700 */
/*<       if(z.gt.zmin)zmin=z >*/
	if (feq_gen_z_d_ > zmin) {
	    zmin = feq_gen_z_d_;
	}
/* SOURCE culvertb.for:3701 */
/*<       z=z+0.01*dup >*/
	feq_gen_z_d_ += static_cast<double>(static_cast<double>(dup) * (float).01);
/* SOURCE culvertb.for:3702 */
/*<       goto100 >*/
	goto L100;
/* SOURCE culvertb.for:3703 */
/*<       elseif(sbflag.eq.-2)then >*/
    } else if (rty6c_1.sbflag == -2) {
/*         Assume solution does not exist. */
/* SOURCE culvertb.for:3705 */
/*<       eflag=-1 >*/
	*eflag = -1;
/* SOURCE culvertb.for:3706 */
/*<       goto999 >*/
	goto L999;
/* SOURCE culvertb.for:3707 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:3708 */
/*<       if(abs(f).gt.epsf)then >*/
    if (dabs(f) > epscom_1.epsf) {
/*         Continue looking for change in sign of residual. */
/* SOURCE culvertb.for:3710 */
/*<       if(f.gt.0.0)then >*/
	if (f > (float)0.) {
/* SOURCE culvertb.for:3711 */
/*<       zhigh=z >*/
	    zhigh = feq_gen_z_d_;
/* SOURCE culvertb.for:3712 */
/*<       fhigh=f >*/
	    fhigh = f;
/* SOURCE culvertb.for:3713 */
/*<       if(zlow.eq.0.0)then >*/
	    if (zlow == (float)0.) {
/* SOURCE culvertb.for:3714 */
/*<       y=z-zb1 >*/
		y = static_cast<double>(feq_gen_z_d_) - xs1com_1.zb1;
/* SOURCE culvertb.for:3715 */
/*<       y=0.99*y >*/
		y *= static_cast<double>((float).99);
/* SOURCE culvertb.for:3716 */
/*<       if(y.lt.epsabs)then >*/
		if (y < epscom_1.epsabs) {
/*               Negative residual not found.  Take to mean that */
/*               the limit does not exist. */
/* SOURCE culvertb.for:3719 */
/*<       eflag=-1 >*/
		    *eflag = -1;
/* SOURCE culvertb.for:3720 */
/*<       goto999 >*/
		    goto L999;
/* SOURCE culvertb.for:3721 */
/*<       endif >*/
		}
/* SOURCE culvertb.for:3722 */
/*<       zt=zb1+y >*/
		zt = static_cast<double>(xs1com_1.zb1) + y;
/* SOURCE culvertb.for:3723 */
/*<       if(zt.le.zmin)then >*/
		if (zt <= zmin) {
/* SOURCE culvertb.for:3724 */
/*<       z=0.5*(zmin+z) >*/
		    feq_gen_z_d_ = static_cast<double>((static_cast<double>(zmin) + feq_gen_z_d_)) * (float).5;
/* SOURCE culvertb.for:3725 */
/*<       if((z-zmin)/zmin.lt.1.e-7)then >*/
		    if (static_cast<double>((static_cast<double>(feq_gen_z_d_) - zmin)) / zmin < (float)1e-7) {
/*                 Conclude that the limit does not exist. */
/* SOURCE culvertb.for:3727 */
/*<       eflag=-1 >*/
			*eflag = -1;
/* SOURCE culvertb.for:3728 */
/*<       goto999 >*/
			goto L999;
/* SOURCE culvertb.for:3729 */
/*<       endif >*/
		    }
/* SOURCE culvertb.for:3730 */
/*<       else >*/
		} else {
/* SOURCE culvertb.for:3731 */
/*<       z=zt >*/
		    feq_gen_z_d_ = zt;
/* SOURCE culvertb.for:3732 */
/*<       endif >*/
		}
/* SOURCE culvertb.for:3733 */
/*<       goto100 >*/
		goto L100;
/* SOURCE culvertb.for:3734 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:3735 */
/*<       else >*/
	} else {
/* SOURCE culvertb.for:3736 */
/*<       zlow=z >*/
	    zlow = feq_gen_z_d_;
/* SOURCE culvertb.for:3737 */
/*<       flow=f >*/
	    flow = f;
/* SOURCE culvertb.for:3738 */
/*<       if(zhigh.eq.0.0)then >*/
	    if (zhigh == (float)0.) {
/* SOURCE culvertb.for:3739 */
/*<       y=z-zb1 >*/
		y = static_cast<double>(feq_gen_z_d_) - xs1com_1.zb1;
/* SOURCE culvertb.for:3740 */
/*<       y=1.05*y >*/
		y *= static_cast<double>((float)1.05);
/* SOURCE culvertb.for:3741 */
/*<       if(y.gt.ymax)then >*/
		if (y > ymax) {
/*               Should not happen but flag just in case. */
/* SOURCE culvertb.for:3743 */
/*<       write(outun,50)ymax >*/
		    feq_gen_io_d__376.ciunit = rty6c_1.outun;
		    s_wsfe(&feq_gen_io_d__376);
		    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE culvertb.for:3744 */
/*<       stop'Abnormal stop.  Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE culvertb.for:3745 */
/*<       endif >*/
		}
/* SOURCE culvertb.for:3746 */
/*<       z=zb1+y >*/
		feq_gen_z_d_ = static_cast<double>(xs1com_1.zb1) + y;
/* SOURCE culvertb.for:3747 */
/*<       goto100 >*/
		goto L100;
/* SOURCE culvertb.for:3748 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:3749 */
/*<       endif >*/
	}
/*         Sign change here. */
/*          WRITE(STDOUT,*) ' F61BDY: ZLOW=',ZLOW,' FLOW=',FLOW, */
/*     A                   ' ZHIGH=',ZHIGH,' FHIGH=',FHIGH */
/* SOURCE culvertb.for:3754 */
/*<       callrgf(1.e-6,epsf,rty61,zlow,zhigh,flow,fhigh,z,flag) >*/
	rgf_(&c_b59, &epscom_1.epsf, rty61_, &zlow, &zhigh, &flow, &
		fhigh, &feq_gen_z_d_, &feq_gen_flag_d_);
/* SOURCE culvertb.for:3758 */
/*<       if(flag.eq.1)then >*/
	if (feq_gen_flag_d_ == 1) {
/* SOURCE culvertb.for:3759 */
/*<       write(stdout,54) >*/
	    feq_gen_io_d__378.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__378);
	    e_wsfe();
/* SOURCE culvertb.for:3760 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE culvertb.for:3761 */
/*<       elseif(flag.eq.2)then >*/
	} else if (feq_gen_flag_d_ == 2) {
/* SOURCE culvertb.for:3762 */
/*<       write(stdout,60) >*/
	    feq_gen_io_d__379.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__379);
	    e_wsfe();
/* SOURCE culvertb.for:3763 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE culvertb.for:3764 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:3765 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:3767 */
/*<       if(type.eq.2)then >*/
    if (*feq_gen_type_d_ == 2) {
/* SOURCE culvertb.for:3768 */
/*<       z1ty2=z >*/
	xs1com_1.z1ty2 = feq_gen_z_d_;
/* SOURCE culvertb.for:3769 */
/*<       cd2=cd >*/
	xs3com_1.cd2 = cdcom_1.cd;
/* SOURCE culvertb.for:3770 */
/*<       else >*/
    } else {
/* SOURCE culvertb.for:3771 */
/*<       z1ty61=z >*/
	xs1com_1.z1ty61 = feq_gen_z_d_;
/* SOURCE culvertb.for:3772 */
/*<       cd61=cd >*/
	xs3com_1.cd61 = cdcom_1.cd;
/* SOURCE culvertb.for:3773 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:3775 */
/*<   999 continue >*/
L999:
/*     Compute the free flow values for the current upstream */
/*     level. */
/* SOURCE culvertb.for:3778 */
/*<       z=hup+hdatum >*/
    feq_gen_z_d_ = static_cast<double>(*hup) + *hdatum;
/* SOURCE culvertb.for:3779 */
/*<       callgetfrf(z,zsbrdf,fdrdw) >*/
    getfrf_(&feq_gen_z_d_, &zsbrdf, &fdrdw);
/* SOURCE culvertb.for:3783 */
/*<       return >*/
    return 0;
/* SOURCE culvertb.for:3784 */
/*<       end >*/
} /* f61bdy_ */




/* SOURCE culvertb.for:3788 */
/*<        >*/
/* Subroutine */ int frft6_(integer *stdout, real *hdatum, real *zdatum, real 
	*hup, integer *iu, integer *id, char *culcls, integer *eflag, integer 
	*feq_gen_type_d_, integer *expflg, real *qfree, real *freed, ftnlen culcls_len)
{
    /* Format strings */
    static char fmt_76[] = "(/,\002 *WRN:574* Unable to force type 6 Cd to m\
atch type 61\002,\002 flow at its limit.\002,/,11x,\002 Using type 6 Cd. \
\002,\002Manual adjustment of 2-D table may be needed.\002)";
    static char fmt_78[] = "(/,\002 Type 6 limits:\002,/,4x,\002Depth at sec\
tion 1=\002,f8.3,/,4x,\002Piezometric depth at section 3=\002,f8.3)";

    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3, feq_gen_r_d_4;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    real q6, tp, tp2, ddn, dup, yat2, zat2;
    extern /* Subroutine */ int dpm26_(integer *, real *, real *, real *, 
	    integer *), lktj_(integer *, real *, real *), f6bdy_(integer *, 
	    real *, real *, integer *, integer *, char *, integer *, real *, 
	    real *, real *, ftnlen), doty6_(integer *, char *, real *, real *,
	     real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, ftnlen);
    integer iflag;
    extern /* Subroutine */ int f61bdy_(integer *, integer *, real *, real *, 
	    real *, integer *, integer *, char *, real *, integer *, ftnlen), 
	    doty61_(integer *, real *, real *, real *, real *, integer *, 
	    integer *, real *, real *, real *, real *, real *, real *), 
	    fulbar_(integer *, real *, real *, real *, real *, real *, real *,
	     real *, real *, real *, real *, real *, real *), xlktal_(integer 
	    *, real *, real *, real *, real *, real *, real *, real *, real *,
	     real *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__386 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__389 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__391 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__392 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__393 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__394 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__395 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Compute free flow of type 6 and its relatives. */
/* SOURCE culvertb.for:3795 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertb.for:3797 */
/*<       integereflag,expflg,id,iu,stdout,type >*/
/* SOURCE culvertb.for:3798 */
/*<       realfreed,hdatum,hup,qfree,zdatum >*/
/* SOURCE culvertb.for:3799 */
/*<       characterculcls*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     HDATUM - Datum for measuring head */
/*     ZDATUM - datum for local elevation */
/*     HUP    - Head upstream */
/*     IU     - Index for upstream node for the culvert barrel */
/*     ID     - Index for the downstream node for the culvert barrel */
/*     CULCLS - Class for culvert shape, BOX, PIPE, .. */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     TYPE   - Culvert flow type */
/*     EXPFLG - Expansion flag.  EXPFLG=1 if flow expands on exit */
/*              and EXPFLG=0 if flow does not expand on exit */
/*     QFREE  - Free flow */
/*     FREED  - Free drop */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertb.for:3817 */
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
/* INCLUDE culvertb.for:3818 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertb.for:3819 */
/* SOURCE cdcom.cmn:2 */
/*<        >*/
/* SOURCE cdcom.cmn:10 */
/*<        >*/
/* SOURCE cdcom.cmn:14 */
/*<        >*/
/*     Add values for support of FHWA type 5 scheme. Oct. 3, 2001 */
/* SOURCE cdcom.cmn:20 */
/*<       realafhwa,cfhwa,yfhwa,sfhwa >*/
/*     AFHWA - value of a */
/*     CFHWA - value of c */
/*     YFHWA - value of Y */
/*     SFHWA - slope of culvert near entrance. */
/* INCLUDE culvertb.for:3820 */
/* SOURCE xs1com.cmn:2 */
/*<        >*/
/* SOURCE xs1com.cmn:7 */
/*<       integeradrxs1 >*/
/* SOURCE xs1com.cmn:9 */
/*<        >*/
/*     Z1TY1- elevation at section 1 at type 1 limit if it exists */
/*     Z1TY1L-elevation at section 1 at lower limit of type 1 if it exists */
/*     Z1TY6- elevation at section 1 at start of type 6 if it exists */
/*     Z1TY2- elevation at upper limit of type 2 flow if it exists */
/*     Z1TY61- elevation at upper limt of type 61 if it exists */
/*     Z1TY5- elevation at section at start of type 5 if it exists */
/*     Z1TY52- elevation at section 1 at lower limit of type 52( */
/*             type 2 to type 5 flow) */
/*     Z1TY51- elevation at section 1 at lower limit of type 51( */
/*             type 1 to type 5 flow) */
/* INCLUDE culvertb.for:3821 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culvertb.for:3822 */
/* SOURCE xs3com.cmn:2 */
/*<        >*/
/* SOURCE xs3com.cmn:11 */
/*<       integeradrxs3 >*/
/* SOURCE xs3com.cmn:13 */
/*<        >*/
/*     CD1- if 0.0 type 1 flow has not been checked, if > 0 type 1 */
/*          flow has been checked and found to exist and its limit */
/*          values have been found, if < 0 type 1 flow does not exist. */
/*     CD2T6- coef. of discharge forcing full flow to match flow */
/*            at the type 2 flow limit. */
/*     AP2T6 - kinetic energy flux coefficient forcing the full */
/*             flow kinetic energy flux to match the flux */
/*             at the type 2 limit. */
/*     BT2T6- momentum flux coefficient forcing the full flow */
/*            momentum flux to match the flux at the type 2 limit. */
/*     CD61T6- coef. of discharge forcing full flow to match flow */
/*             at the type 61 limit. */
/*     CD1T6- coef. of discharge forcing full flow to match flow */
/*            at the type 1 limit */

/*     AP61T6- same as AP2T6 for type 61. */
/*     BT61T6- same as AP2T6 for type 61. */
/*     CD2- coef. of discharge for type 2 flow at the type 2 limit. */
/*     CD61- coef. of discharge for type 61 flow at the type 61 limit. */
/*     CD6- coef. of discharge for type 6 flow. */
/*     Z3PTY6- piezometric level at section 3 at the type 6 limit. */
/*     AVH2- area for velocity head at the type 2 limit. */
/*     AVH61- area for velocity head at the type 61 limit. */
/*     BT3ATD- beta at section 3 when barrel is full(at D!) */
/*     AP3ATD- alpha at section 3 when the barrel is full(at D!) */
/*     CC2T5 - contraction coefficient for type 5 at the type 2 flow */
/*             limit. */
/*     CC1T5 - contraction coefficient for type 5 at the type 1 flow */
/*             limit. */
/*     CC5- contraction coefficient for type 5 at its lower limit */
/*          and above. */
/*     Y3TY52- depth at section 3 at the lower limit of type 52 flow */
/*             giving the transistion between type 2 and type 5. */
/*     Y3TY51- depth at section 3 at the lower limit of type 51 flow */
/*             giving the transistion between type 1 and type 5. */
/*     BT2T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 52 and */
/*             upper limit of type 2. */
/*     BT1T5-  beta at section 3 to correct for difference between */
/*             exit momentum flux at lower limit of type 51 and */
/*             upper limit of type 1. */
/*     AP2T5-  alpha analogous to BT2T5 */
/*     AP1T5-  alpha analogous to BT1T5 */
/*     Y3TY5-  depth at section 3 at the lower limit of type 5 flow */
/*     BT3AT5- beta for type 5 flow limit */
/*     AP3AT5- alpha for type 5 flow limit */
/*     CD5T4- coefficient of discharge that forces a type 4 equation */
/*            to match the type 5, 51, or 52 flow at the full-flow- */
/*            inducing level at section 43. */
/*     Y3LTY2- depth at section 3 at the type 2 limit, that is, */
/*             critical depth. */
/*     Y3LTY1- submergence depth at section 3  at the limit of */
/*             type 1 flow. */
/*     Y3LTY5- the full-flow-inducing value of piezometric level */
/*             relative to the invert at section 3 for flow types */
/*             5, 51, and 52. */
/* INCLUDE culvertb.for:3823 */
/* SOURCE xs4com.cmn:2 */
/*<        >*/
/* SOURCE xs4com.cmn:5 */
/*<       integeradrxs4 >*/
/* SOURCE xs4com.cmn:7 */
/*<        >*/
/* INCLUDE culvertb.for:3824 */
/* SOURCE rdfcom.cmn:2 */
/*<       common/rdfcom/wfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/* SOURCE rdfcom.cmn:4 */
/*<       realwfrdf,mfrdf,efrdf,wfrd,mfrd,efrd >*/
/*     WFRDF-WATER FLUX OVER ROAD FREE CONDITION. */
/*     MFRDF-MOMENTUM FLUX OVER THE ROAD FREE CONDITION. */
/*     EFRDF-ENERGY FLUX OVER THE ROAD FREE CONDITION. */
/*     WFRD- WATER FLUX OVER THE ROAD ANY CONDITION. */
/*     MFRD- MOMENTUM FLUX OVER THE ROAD ANY CONDITION. */
/*     EFRD- ENERGY FLUX OVER THE ROAD ANY CONDITION. */
/* INCLUDE culvertb.for:3825 */
/*     Common to hold values needed for computing various limits */
/*     for culvert flow types. */
/* SOURCE typlim.cmn:4 */
/*<        >*/
/* SOURCE typlim.cmn:10 */
/*<       integerhhtype >*/
/* SOURCE typlim.cmn:12 */
/*<        >*/
/* INCLUDE culvertb.for:3826 */
/* SOURCE appcom.cmn:2 */
/*<       common/appcom/apptab,appelv,applen,applos,appexp,zertab,zerelv >*/
/* SOURCE appcom.cmn:5 */
/*<       integerapptab,zertab >*/
/* SOURCE appcom.cmn:7 */
/*<       realappelv,applen,applos,appexp,zerelv >*/
/* INCLUDE culvertb.for:3827 */
/*     Common block for various parameters to handle transitional */
/*     flow type behavior for the departure reach computations. */
/* SOURCE typtrn.cmn:4 */
/*<       common/typtrn/avhf,cdf,betaf,alphaf,y3pf,beta3,alpha3 >*/
/* SOURCE typtrn.cmn:6 */
/*<       realavhf,cdf,betaf,alphaf,y3pf,beta3,alpha3 >*/
/*     AVHF- area used for velocity head in computing losses for the */
/*           transitional free flow */
/*     CDF- coef. of discharge for computing losses for the transitional */
/*          free flow. */
/*     BETAF- value of beta to compensate for false area in the computation */
/*            of the momentum flux from some free flows.  If this */
/*            value is zero it means that the beta from the cross section */
/*            function table should be used.  If it is non-zero it means */
/*            that the free flow type was used as a transition and that */
/*            the flow area of the culvert barrel outlet was falsified in */
/*            the process. */
/*     ALPHAF- value of alpha to use in computing velocity head for */
/*             energy loss computations. */
/*     Y3PF- depth to the piezometric level at the culvert barrel outlet */
/*           for free flow limit. */
/*     BETA3- actual value at section 3 used in departure reach */
/*     ALPHA3- actual value at section 3.  Crudely estimated in some */
/*             cases because better alternative is not available. */
/* INCLUDE culvertb.for:3828 */
/* SOURCE culcom.cmn:2 */
/*<        >*/
/* SOURCE culcom.cmn:8 */
/*<       integernsec(mnbn),hltab(mnbn),iat3d,iat6d,sbkind,sbshape >*/
/* SOURCE culcom.cmn:10 */
/*<        >*/
/* SOURCE culcom.cmn:16 */
/*<       doubleprecisionfrcfac >*/
/*     FRCFAC- friction factor to give factor for friction losses */
/*             in barrel for non-prismatic full-flow that as well */
/*             as prismatic full flow. */
/*     TY1YTD- maximum ratio of depth to vertical diameter for */
/*             type 1 flow. */
/*     TY1HTD- maximum ratio of head at section 1 relative to */
/*             culvert invert at culvert inlet to the vertical */
/*             diamter of the culvert.  Must be less than 1.5. */
/*     SBKIND- if 0 the slope of the culvert barrel is a constant, */
/*             if 1 the slope of the culvert barrel varies. */
/*     BSHAPE- if 0 the barrel shape is constant, that is, prismatic, */
/*             if 1 the barrel shape is nonprismatic. */
/*     TY5SBF- ratio of depth to vertical diameter of the culvert */
/*             at the exit which causes submergence. */
/* Note:  25 August 2004:  SBSHAPE is apparently not used.  BSHAPE */
/* is but outside of a common block. */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertb.for:3831 */
/*<       integeriflag >*/
/* SOURCE culvertb.for:3832 */
/*<       realddn,dup,q6,tp,tp2,yat2,zat2 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertb.for:3835 */
/*<       intrinsicmin,sqrt >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertb.for:3838 */
/*<       externaldoty6,doty61,dpm26,f61bdy,f6bdy,fulbar,lktj,xlktal >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertb.for:3842 */
/*<    76  >*/
/* SOURCE culvertb.for:3845 */
/*<    78  >*/
/* *********************************************************************** */
/* SOURCE culvertb.for:3849 */
/*<       ddn=dvec(id) >*/
/* L76: */
/* L78: */
    ddn = culcom_1.dvec[*id - 1];
/* SOURCE culvertb.for:3850 */
/*<       dup=dvec(iu) >*/
    dup = culcom_1.dvec[*iu - 1];
/* SOURCE culvertb.for:3851 */
/*<       a2=a2full >*/
    xs2com_1.a2 = xs2com_1.a2full;
/* SOURCE culvertb.for:3852 */
/*<       if(cd6.eq.0.0)then >*/
    if (xs3com_1.cd6 == (float)0.) {
/*       The limit for type 6 flow has not been computed.  Find it. */
/* SOURCE culvertb.for:3854 */
/*<       callf6bdy(stdout,hdatum,hup,iu,id,culcls,eflag,z3pty6,q6,zat2) >*/
	f6bdy_(stdout, hdatum, hup, iu, id, culcls, eflag, &xs3com_1.z3pty6, &
		q6, &zat2, (ftnlen)8);
/* SOURCE culvertb.for:3857 */
/*<       write(stdout,78)z1ty6-zb1,z3pty6-zb3 >*/
	feq_gen_io_d__386.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__386);
	feq_gen_r_d_1 = static_cast<double>(xs1com_1.z1ty6) - xs1com_1.zb1;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	feq_gen_r_d_2 = static_cast<double>(xs3com_1.z3pty6) - xs3com_1.zb3;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culvertb.for:3858 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:3860 */
/*<       if(cd61.eq.0.0)then >*/
    if (xs3com_1.cd61 == (float)0.) {
/*       Type 61 limit has not been computed.  See if limit exists */
/*       and if it does, find it. */
/* SOURCE culvertb.for:3863 */
/*<       if(zb2.ge.zb3)then >*/
	if (xs2com_1.zb2 >= xs3com_1.zb3) {
/*         Type 61 flow does not exist.  Therefore limit does not exist. */
/* SOURCE culvertb.for:3865 */
/*<       cd61=-1.0 >*/
	    xs3com_1.cd61 = (float)-1.;
/* SOURCE culvertb.for:3866 */
/*<       else >*/
	} else {
/*         Type 2 flow exists and the barrel slope is adverse. */
/*         Therefore, type 61 exists! */
/* SOURCE culvertb.for:3869 */
/*<       yat2=zb3+ddn-zb2 >*/
	    yat2 = static_cast<double>(static_cast<double>(xs3com_1.zb3) + ddn) - xs2com_1.zb2;
/* SOURCE culvertb.for:3870 */
/*<       callf61bdy(stdout,61,hdatum,zdatum,hup,iu,id,culcls,yat2,iflag) >*/
	    f61bdy_(stdout, &feq_gen_c_d_61, hdatum, zdatum, hup, iu, id, culcls, &
		    yat2, &iflag, (ftnlen)8);
/* SOURCE culvertb.for:3874 */
/*<       if(iflag.eq.-1)then >*/
	    if (iflag == -1) {
/* SOURCE culvertb.for:3875 */
/*<       write(stdout,*)' Type 61 limit not found when it must',' exist.' >*/
		feq_gen_io_d__389.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__389);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Type 61 limit not found when it must"), 
			(ftnlen)37);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" exist."), (ftnlen)7);
		e_wsle();
/* SOURCE culvertb.for:3877 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:3878 */
/*<       else >*/
	    } else {
/* SOURCE culvertb.for:3879 */
/*<       cd61=cd >*/
		xs3com_1.cd61 = cdcom_1.cd;
/* SOURCE culvertb.for:3880 */
/*<       avh61=avh >*/
		xs3com_1.avh61 = cdcom_1.avh;
/*           Type 61 exists.  Therefore transition is between 61 and 6. */
/* SOURCE culvertb.for:3883 */
/*<        >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = static_cast<double>(typlim_1.q1l) / typlim_1.a1l;
/* Computing 2nd power */
		feq_gen_r_d_2 = static_cast<double>(typlim_1.q3l) / xs3com_1.a3full;
/* Computing 2nd power */
		feq_gen_r_d_3 = static_cast<double>(typlim_1.q2l) / xs2com_1.k2full;
/* Computing 2nd power */
		feq_gen_r_d_4 = static_cast<double>(xs2com_1.a2full) / typlim_1.q2l;
		tp = static_cast<double>((static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>(typlim_1.alp1l) - appcom_1.applos)) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / 
			grvcom_1.grav2) + typlim_1.z1l) - (static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2) / 
			grvcom_1.grav2) + typlim_1.z3part)) - static_cast<double>(culcom_1.l23) * (
			static_cast<double>(feq_gen_r_d_3) * feq_gen_r_d_3)) - static_cast<double>(static_cast<double>(appcom_1.applen) * (static_cast<double>(typlim_1.q1l) * 
			typlim_1.q2l)) / (static_cast<double>(typlim_1.k1l) * xs2com_1.k2full))) * (
			static_cast<double>(grvcom_1.grav2) * (static_cast<double>(feq_gen_r_d_4) * feq_gen_r_d_4));
/* SOURCE culvertb.for:3886 */
/*<       if(tp.lt.0.0)then >*/
		if (tp < (float)0.) {
/* SOURCE culvertb.for:3887 */
/*<       write(stdout,76) >*/
		    feq_gen_io_d__391.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__391);
		    e_wsfe();
/* SOURCE culvertb.for:3888 */
/*<       cd61t6=c46 >*/
		    xs3com_1.cd61t6 = cdcom_1.c46;
/* SOURCE culvertb.for:3889 */
/*<       else >*/
		} else {
/* SOURCE culvertb.for:3890 */
/*<       cd61t6=sqrt(1.0/(1.0+tp)) >*/
		    xs3com_1.cd61t6 = sqrt(static_cast<double>((float)1.) / (static_cast<double>(tp) + (float)1.));
/* SOURCE culvertb.for:3891 */
/*<       endif >*/
		}
/* SOURCE culvertb.for:3892 */
/*<       bt61t6=a3full/a3part >*/
		xs3com_1.bt61t6 = static_cast<double>(xs3com_1.a3full) / typlim_1.a3part;
/* SOURCE culvertb.for:3893 */
/*<       ap61t6=(bt61t6)**2 >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = xs3com_1.bt61t6;
		xs3com_1.ap61t6 = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE culvertb.for:3894 */
/*<        >*/
		feq_gen_io_d__392.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__392);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" CD61T6="), (ftnlen)8);
		do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&xs3com_1.cd61t6, (ftnlen)sizeof(
			real));
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" BT61T6="), (ftnlen)8);
		do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&xs3com_1.bt61t6, (ftnlen)sizeof(
			real));
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" AP61T6="), (ftnlen)8);
		do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&xs3com_1.ap61t6, (ftnlen)sizeof(
			real));
		e_wsle();
/* SOURCE culvertb.for:3896 */
/*<       write(stdout,*)' Z1TY61=',z1ty61,' CD61=',cd61 >*/
		feq_gen_io_d__393.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__393);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Z1TY61="), (ftnlen)8);
		do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&xs1com_1.z1ty61, (ftnlen)sizeof(
			real));
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" CD61="), (ftnlen)6);
		do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&xs3com_1.cd61, (ftnlen)sizeof(
			real));
		e_wsle();
/* SOURCE culvertb.for:3897 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:3898 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:3899 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:3901 */
/*<       z1=hdatum+hup >*/
    xs1com_1.z1 = static_cast<double>(*hdatum) + *hup;
/* SOURCE culvertb.for:3902 */
/*<       y1=z1-zb1 >*/
    xs1com_1.y1 = static_cast<double>(xs1com_1.z1) - xs1com_1.zb1;
/* SOURCE culvertb.for:3903 */
/*<       callxlktal(adrxs1,y1,a1,t1,dt1,j1,k1,dk1,bet1,dbet1,alp1,dalp1) >*/
    xlktal_(&xs1com_1.adrxs1, &xs1com_1.y1, &xs1com_1.a1, &xs1com_1.t1, &
	    xs1com_1.dt1, &xs1com_1.j1, &xs1com_1.k1, &xs1com_1.dk1, &
	    xs1com_1.bet1, &xs1com_1.dbet1, &xs1com_1.alp1, &xs1com_1.dalp1);
/* SOURCE culvertb.for:3908 */
/*<       if(z1.ge.z1ty6)then >*/
    if (xs1com_1.z1 >= xs1com_1.z1ty6) {
/*       This is type 6 flow */
/* SOURCE culvertb.for:3910 */
/*<       type=6 >*/
	*feq_gen_type_d_ = 6;
/* SOURCE culvertb.for:3911 */
/*<        >*/
	doty6_(stdout, culcls, &xs1com_1.a1, &xs1com_1.alp1, &xs1com_1.k1, &
		xs1com_1.z1, &xs2com_1.a2full, &xs2com_1.k2full, &
		xs3com_1.a3full, &ddn, &xs3com_1.zb3, &xs3com_1.cd6, &
		xs3com_1.z3p, &xs3com_1.q3, &xs2com_1.z2p, (ftnlen)8);
/* SOURCE culvertb.for:3915 */
/*<       y2p=z2p-zb2 >*/
	xs2com_1.y2p = static_cast<double>(xs2com_1.z2p) - xs2com_1.zb2;
/* SOURCE culvertb.for:3916 */
/*<       y3=ddn >*/
	xs3com_1.y3 = ddn;
/* SOURCE culvertb.for:3917 */
/*<       z2=z2p >*/
	xs2com_1.z2 = xs2com_1.z2p;
/* SOURCE culvertb.for:3918 */
/*<       y2=dup >*/
	xs2com_1.y2 = dup;
/* SOURCE culvertb.for:3919 */
/*<       betaf=0.0 >*/
	typtrn_1.betaf = (float)0.;
/* SOURCE culvertb.for:3920 */
/*<       beta3=0.0 >*/
	typtrn_1.beta3 = (float)0.;
/* SOURCE culvertb.for:3921 */
/*<       alpha3=0.0 >*/
	typtrn_1.alpha3 = (float)0.;
/* SOURCE culvertb.for:3922 */
/*<       elseif(cd1t6.gt.0.0)then >*/
    } else if (xs3com_1.cd1t6 > (float)0.) {
/*       We are between type 1 and type 6.  This is type 62. Full. */
/*       Interpolate the CD and for Z3P. */
/* SOURCE culvertb.for:3925 */
/*<       type=62 >*/
	*feq_gen_type_d_ = 62;
/* SOURCE culvertb.for:3926 */
/*<       if(z1.gt.z1ty1.and.z1.lt.z1ty6)then >*/
	if (xs1com_1.z1 > xs1com_1.z1ty1 && xs1com_1.z1 < xs1com_1.z1ty6) {
/*         Proper interval. */
/* SOURCE culvertb.for:3928 */
/*<       cd=cd1t6+(z1-z1ty1)*(cd6-cd1t6)/(z1ty6-z1ty1) >*/
	    cdcom_1.cd = static_cast<double>(xs3com_1.cd1t6) + static_cast<double>(static_cast<double>((static_cast<double>(xs1com_1.z1) - xs1com_1.z1ty1)) * (
		    static_cast<double>(xs3com_1.cd6) - xs3com_1.cd1t6)) / (static_cast<double>(xs1com_1.z1ty6) - 
		    xs1com_1.z1ty1);
/* SOURCE culvertb.for:3929 */
/*<       z3p=z3part+(z1-z1ty1)*(z3pty6-z3part)/(z1ty6-z1ty1) >*/
	    xs3com_1.z3p = static_cast<double>(typlim_1.z3part) + static_cast<double>(static_cast<double>((static_cast<double>(xs1com_1.z1) - xs1com_1.z1ty1)) * 
		    (static_cast<double>(xs3com_1.z3pty6) - typlim_1.z3part)) / (static_cast<double>(xs1com_1.z1ty6) - 
		    xs1com_1.z1ty1);
/* SOURCE culvertb.for:3930 */
/*<        >*/
	    fulbar_(stdout, &xs1com_1.a1, &xs1com_1.alp1, &xs1com_1.k1, &
		    xs1com_1.z1, &xs2com_1.a2full, &xs2com_1.k2full, &
		    xs3com_1.a3full, &cdcom_1.cd, &xs2com_1.a2full, &
		    xs3com_1.z3p, &xs3com_1.q3, &xs2com_1.z2p);
/* SOURCE culvertb.for:3934 */
/*<       z2=z2p >*/
	    xs2com_1.z2 = xs2com_1.z2p;
/* SOURCE culvertb.for:3935 */
/*<       y2=dup >*/
	    xs2com_1.y2 = dup;
/* SOURCE culvertb.for:3936 */
/*<       betaf=bt1t6+(z1-z1ty1)*(bt3atd-bt1t6)/(z1ty6-z1ty1) >*/
	    typtrn_1.betaf = static_cast<double>(xs3com_1.bt1t6) + static_cast<double>(static_cast<double>((static_cast<double>(xs1com_1.z1) - xs1com_1.z1ty1)) *
		     (static_cast<double>(xs3com_1.bt3atd) - xs3com_1.bt1t6)) / (static_cast<double>(xs1com_1.z1ty6) - 
		    xs1com_1.z1ty1);
/* SOURCE culvertb.for:3938 */
/*<       alphaf=ap1t6+(z1-z1ty1)*(ap3atd-ap1t6)/(z1ty6-z1ty1) >*/
	    typtrn_1.alphaf = static_cast<double>(xs3com_1.ap1t6) + static_cast<double>(static_cast<double>((static_cast<double>(xs1com_1.z1) - xs1com_1.z1ty1)) 
		    * (static_cast<double>(xs3com_1.ap3atd) - xs3com_1.ap1t6)) / (static_cast<double>(xs1com_1.z1ty6) - 
		    xs1com_1.z1ty1);
/* SOURCE culvertb.for:3940 */
/*<       cdf=cd >*/
	    typtrn_1.cdf = cdcom_1.cd;
/* SOURCE culvertb.for:3941 */
/*<       avh=a2full >*/
	    cdcom_1.avh = xs2com_1.a2full;
/* SOURCE culvertb.for:3942 */
/*<       y3pf=z3p-zb3 >*/
	    typtrn_1.y3pf = static_cast<double>(xs3com_1.z3p) - xs3com_1.zb3;
/* SOURCE culvertb.for:3943 */
/*<       else >*/
	} else {
/* SOURCE culvertb.for:3944 */
/*<       write(stdout,*)' PROBLEM WHEN CD1T6 > 0 IN FRFT6' >*/
	    feq_gen_io_d__394.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__394);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" PROBLEM WHEN CD1T6 > 0 IN FRFT6"), (ftnlen)
		    32);
	    e_wsle();
/* SOURCE culvertb.for:3945 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:3946 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:3947 */
/*<       else >*/
    } else {
/* SOURCE culvertb.for:3948 */
/*<       if(cd2t6.gt.0.0)then >*/
	if (xs3com_1.cd2t6 > (float)0.) {
/*         No type 61 in this case.  Between type 2 and type 6. Full. */
/* SOURCE culvertb.for:3950 */
/*<       type=62 >*/
	    *feq_gen_type_d_ = 62;
/* SOURCE culvertb.for:3951 */
/*<       if(z1.gt.z1ty1.and.z1.lt.z1ty6)then >*/
	    if (xs1com_1.z1 > xs1com_1.z1ty1 && xs1com_1.z1 < xs1com_1.z1ty6) 
		    {
/* SOURCE culvertb.for:3952 */
/*<       cd=cd2t6+(z1-z1ty2)*(cd6-cd2t6)/(z1ty6-z1ty2) >*/
		cdcom_1.cd = static_cast<double>(xs3com_1.cd2t6) + static_cast<double>(static_cast<double>((static_cast<double>(xs1com_1.z1) - xs1com_1.z1ty2)) *
			 (static_cast<double>(xs3com_1.cd6) - xs3com_1.cd2t6)) / (static_cast<double>(xs1com_1.z1ty6) - 
			xs1com_1.z1ty2);
/* SOURCE culvertb.for:3953 */
/*<       z3p=z3part+(z1-z1ty2)*(z3pty6-z3part)/(z1ty6-z1ty2) >*/
		xs3com_1.z3p = static_cast<double>(typlim_1.z3part) + static_cast<double>(static_cast<double>((static_cast<double>(xs1com_1.z1) - 
			xs1com_1.z1ty2)) * (static_cast<double>(xs3com_1.z3pty6) - typlim_1.z3part)) 
			/ (static_cast<double>(xs1com_1.z1ty6) - xs1com_1.z1ty2);
/* SOURCE culvertb.for:3955 */
/*<        >*/
		fulbar_(stdout, &xs1com_1.a1, &xs1com_1.alp1, &xs1com_1.k1, &
			xs1com_1.z1, &xs2com_1.a2full, &xs2com_1.k2full, &
			xs3com_1.a3full, &cdcom_1.cd, &xs2com_1.a2full, &
			xs3com_1.z3p, &xs3com_1.q3, &xs2com_1.z2p);
/* SOURCE culvertb.for:3959 */
/*<       z2=z2p >*/
		xs2com_1.z2 = xs2com_1.z2p;
/* SOURCE culvertb.for:3960 */
/*<       y2=dup >*/
		xs2com_1.y2 = dup;
/* SOURCE culvertb.for:3961 */
/*<       betaf=bt2t6+(z1-z1ty2)*(bt3atd-bt2t6)/(z1ty6-z1ty2) >*/
		typtrn_1.betaf = static_cast<double>(xs3com_1.bt2t6) + static_cast<double>(static_cast<double>((static_cast<double>(xs1com_1.z1) - 
			xs1com_1.z1ty2)) * (static_cast<double>(xs3com_1.bt3atd) - xs3com_1.bt2t6)) /
			 (static_cast<double>(xs1com_1.z1ty6) - xs1com_1.z1ty2);
/* SOURCE culvertb.for:3963 */
/*<       alphaf=ap2t6+(z1-z1ty2)*(ap3atd-ap2t6)/(z1ty6-z1ty2) >*/
		typtrn_1.alphaf = static_cast<double>(xs3com_1.ap2t6) + static_cast<double>(static_cast<double>((static_cast<double>(xs1com_1.z1) - 
			xs1com_1.z1ty2)) * (static_cast<double>(xs3com_1.ap3atd) - xs3com_1.ap2t6)) /
			 (static_cast<double>(xs1com_1.z1ty6) - xs1com_1.z1ty2);
/* SOURCE culvertb.for:3965 */
/*<       cdf=cd >*/
		typtrn_1.cdf = cdcom_1.cd;
/* SOURCE culvertb.for:3966 */
/*<       avh=a2full >*/
		cdcom_1.avh = xs2com_1.a2full;
/* SOURCE culvertb.for:3967 */
/*<       y3pf=z3p-zb3 >*/
		typtrn_1.y3pf = static_cast<double>(xs3com_1.z3p) - xs3com_1.zb3;
/* SOURCE culvertb.for:3968 */
/*<       else >*/
	    } else {
/* SOURCE culvertb.for:3969 */
/*<       write(stdout,*)' PROBLEM WHEN CD2T6 > 0 IN FRFT6.' >*/
		feq_gen_io_d__395.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__395);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" PROBLEM WHEN CD2T6 > 0 IN FRFT6."), (
			ftnlen)33);
		e_wsle();
/* SOURCE culvertb.for:3970 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertb.for:3971 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:3972 */
/*<       elseif(cd61t6.gt.0.0)then >*/
	} else if (xs3com_1.cd61t6 > (float)0.) {
/* SOURCE culvertb.for:3973 */
/*<       if(z1.gt.z1ty61.and.z1.lt.z1ty6)then >*/
	    if (xs1com_1.z1 > xs1com_1.z1ty61 && xs1com_1.z1 < xs1com_1.z1ty6)
		     {
/*           Between type 61 and 6.  Full. */
/* SOURCE culvertb.for:3975 */
/*<       type=62 >*/
		*feq_gen_type_d_ = 62;
/* SOURCE culvertb.for:3976 */
/*<       cd=cd61t6+(z1-z1ty61)*(cd6-cd61t6)/(z1ty6-z1ty61) >*/
		cdcom_1.cd = static_cast<double>(xs3com_1.cd61t6) + static_cast<double>(static_cast<double>((static_cast<double>(xs1com_1.z1) - xs1com_1.z1ty61))
			 * (static_cast<double>(xs3com_1.cd6) - xs3com_1.cd61t6)) / (static_cast<double>(xs1com_1.z1ty6) 
			- xs1com_1.z1ty61);
/* SOURCE culvertb.for:3978 */
/*<       z3p=z3part+(z1-z1ty61)*(z3pty6-z3part)/(z1ty6-z1ty61) >*/
		xs3com_1.z3p = static_cast<double>(typlim_1.z3part) + static_cast<double>(static_cast<double>((static_cast<double>(xs1com_1.z1) - 
			xs1com_1.z1ty61)) * (static_cast<double>(xs3com_1.z3pty6) - typlim_1.z3part))
			 / (static_cast<double>(xs1com_1.z1ty6) - xs1com_1.z1ty61);
/* SOURCE culvertb.for:3980 */
/*<        >*/
		fulbar_(stdout, &xs1com_1.a1, &xs1com_1.alp1, &xs1com_1.k1, &
			xs1com_1.z1, &xs2com_1.a2full, &xs2com_1.k2full, &
			xs3com_1.a3full, &cdcom_1.cd, &xs2com_1.a2full, &
			xs3com_1.z3p, &xs3com_1.q3, &xs2com_1.z2p);
/* SOURCE culvertb.for:3984 */
/*<       z2=z2p >*/
		xs2com_1.z2 = xs2com_1.z2p;
/* SOURCE culvertb.for:3985 */
/*<       y2=dup >*/
		xs2com_1.y2 = dup;
/* SOURCE culvertb.for:3986 */
/*<       betaf=bt61t6+(z1-z1ty61)*(bt3atd-bt61t6)/(z1ty6-z1ty61) >*/
		typtrn_1.betaf = static_cast<double>(xs3com_1.bt61t6) + static_cast<double>(static_cast<double>((static_cast<double>(xs1com_1.z1) - 
			xs1com_1.z1ty61)) * (static_cast<double>(xs3com_1.bt3atd) - xs3com_1.bt61t6))
			 / (static_cast<double>(xs1com_1.z1ty6) - xs1com_1.z1ty61);
/* SOURCE culvertb.for:3988 */
/*<       alphaf=ap61t6+(z1-z1ty61)*(ap3atd-ap61t6)/(z1ty6-z1ty61) >*/
		typtrn_1.alphaf = static_cast<double>(xs3com_1.ap61t6) + static_cast<double>(static_cast<double>((static_cast<double>(xs1com_1.z1) - 
			xs1com_1.z1ty61)) * (static_cast<double>(xs3com_1.ap3atd) - xs3com_1.ap61t6))
			 / (static_cast<double>(xs1com_1.z1ty6) - xs1com_1.z1ty61);
/* SOURCE culvertb.for:3990 */
/*<       cdf=cd >*/
		typtrn_1.cdf = cdcom_1.cd;
/* SOURCE culvertb.for:3991 */
/*<       avh=a2full >*/
		cdcom_1.avh = xs2com_1.a2full;
/* SOURCE culvertb.for:3992 */
/*<       y3pf=z3p-zb3 >*/
		typtrn_1.y3pf = static_cast<double>(xs3com_1.z3p) - xs3com_1.zb3;
/* SOURCE culvertb.for:3993 */
/*<       else >*/
	    } else {
/*           Z1 < Z1TY61 here. */
/* SOURCE culvertb.for:3996 */
/*<       if(cd2.lt.0.0)then >*/
		if (xs3com_1.cd2 < (float)0.) {
/*             There is no type 2.  Therefore, type 61 flow has */
/*             a constant CD. */
/* SOURCE culvertb.for:3999 */
/*<       cd=cd6 >*/
		    cdcom_1.cd = xs3com_1.cd6;
/* SOURCE culvertb.for:4000 */
/*<       z3p=zb3+0.5*(z1-zb3) >*/
		    xs3com_1.z3p = static_cast<double>(xs3com_1.zb3) + static_cast<double>((static_cast<double>(xs1com_1.z1) - xs3com_1.zb3))
			     * (float).5;
/* SOURCE culvertb.for:4001 */
/*<       avh=a2full >*/
		    cdcom_1.avh = xs2com_1.a2full;
/* SOURCE culvertb.for:4002 */
/*<       betaf=-2.0 >*/
		    typtrn_1.betaf = (float)-2.;
/* SOURCE culvertb.for:4003 */
/*<       else >*/
		} else {
/*             There is type 2.  Type 61 flow has a CD that varies */
/*             from type 2 value at its limit to the CD at the */
/*             Type 61 limit. */
/* SOURCE culvertb.for:4008 */
/*<       cd=cd2+(z1-z1ty2)*(cd61-cd2)/(z1ty61-z1ty2) >*/
		    cdcom_1.cd = static_cast<double>(xs3com_1.cd2) + static_cast<double>(static_cast<double>((static_cast<double>(xs1com_1.z1) - xs1com_1.z1ty2))
			     * (static_cast<double>(xs3com_1.cd61) - xs3com_1.cd2)) / (
			    static_cast<double>(xs1com_1.z1ty61) - xs1com_1.z1ty2);
/* SOURCE culvertb.for:4009 */
/*<       avh=avh2+(z1-z1ty2)*(avh61-avh2)/(z1ty61-z1ty2) >*/
		    cdcom_1.avh = static_cast<double>(xs3com_1.avh2) + static_cast<double>(static_cast<double>((static_cast<double>(xs1com_1.z1) - 
			    xs1com_1.z1ty2)) * (static_cast<double>(xs3com_1.avh61) - xs3com_1.avh2))
			     / (static_cast<double>(xs1com_1.z1ty61) - xs1com_1.z1ty2);
/* SOURCE culvertb.for:4010 */
/*<       if(z3pest.eq.zb3)then >*/
		    if (xs3com_1.z3pest == xs3com_1.zb3) {
/*               Type 2 is possible but the head range given by the */
/*               user did not invoke it. */
/* SOURCE culvertb.for:4013 */
/*<       z3p=zb3+0.5*(z1-zb3) >*/
			xs3com_1.z3p = static_cast<double>(xs3com_1.zb3) + static_cast<double>((static_cast<double>(xs1com_1.z1) - 
				xs3com_1.zb3)) * (float).5;
/* SOURCE culvertb.for:4014 */
/*<       else >*/
		    } else {
/* SOURCE culvertb.for:4015 */
/*<       z3p=z3pest >*/
			xs3com_1.z3p = xs3com_1.z3pest;
/* SOURCE culvertb.for:4016 */
/*<       endif >*/
		    }
/* SOURCE culvertb.for:4017 */
/*<       betaf=-1.0 >*/
		    typtrn_1.betaf = (float)-1.;
/* SOURCE culvertb.for:4018 */
/*<       endif >*/
		}
/* SOURCE culvertb.for:4019 */
/*<       type=61 >*/
		*feq_gen_type_d_ = 61;
/*            WRITE(STDOUT,*) ' TYPE 61 CD=',CD,' Z3P=',Z3P,' Z1=',Z1, */
/*     A                        ' Z3PEST=',Z3PEST */
/* SOURCE culvertb.for:4022 */
/*<       calldoty61(stdout,a1,alp1,k1,z1,iu,id,zb3,cd,avh,z3p,q3,z2p) >*/
		doty61_(stdout, &xs1com_1.a1, &xs1com_1.alp1, &xs1com_1.k1, &
			xs1com_1.z1, iu, id, &xs3com_1.zb3, &cdcom_1.cd, &
			cdcom_1.avh, &xs3com_1.z3p, &xs3com_1.q3, &
			xs2com_1.z2p);
/* SOURCE culvertb.for:4026 */
/*<       z3pest=z3p >*/
		xs3com_1.z3pest = xs3com_1.z3p;
/* SOURCE culvertb.for:4027 */
/*<       z2=z2p >*/
		xs2com_1.z2 = xs2com_1.z2p;
/* SOURCE culvertb.for:4028 */
/*<       y2=dup >*/
		xs2com_1.y2 = dup;
/* SOURCE culvertb.for:4029 */
/*<       cdf=cd >*/
		typtrn_1.cdf = cdcom_1.cd;
/* SOURCE culvertb.for:4030 */
/*<       avhf=avh >*/
		typtrn_1.avhf = cdcom_1.avh;
/* SOURCE culvertb.for:4031 */
/*<       y3pf=z3p-zb3 >*/
		typtrn_1.y3pf = static_cast<double>(xs3com_1.z3p) - xs3com_1.zb3;
/* SOURCE culvertb.for:4032 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:4033 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:4034 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:4036 */
/*<       q1=wfrdf+q3 >*/
    xs1com_1.q1 = static_cast<double>(rdfcom_1.wfrdf) + xs3com_1.q3;
/* SOURCE culvertb.for:4037 */
/*<       q2=q3 >*/
    xs2com_1.q2 = xs3com_1.q3;
/* SOURCE culvertb.for:4039 */
/*<       qfree=q3 >*/
    *qfree = xs3com_1.q3;
/*     MAKE SURE THE PROPER AREA IS USED FOR DEPARTURE REACH */
/* SOURCE culvertb.for:4042 */
/*<       if(type.eq.61)then >*/
    if (*feq_gen_type_d_ == 61) {
/* SOURCE culvertb.for:4043 */
/*<       y3=z3p-zb3 >*/
	xs3com_1.y3 = static_cast<double>(xs3com_1.z3p) - xs3com_1.zb3;
/* SOURCE culvertb.for:4044 */
/*<       else >*/
    } else {
/* SOURCE culvertb.for:4045 */
/*<       y3=ddn >*/
	xs3com_1.y3 = ddn;
/* SOURCE culvertb.for:4046 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:4047 */
/*<       z3=y3+zb3 >*/
    xs3com_1.z3 = static_cast<double>(xs3com_1.y3) + xs3com_1.zb3;
/* SOURCE culvertb.for:4048 */
/*<       y3free=y3 >*/
    xs3com_1.y3free = xs3com_1.y3;
/* SOURCE culvertb.for:4049 */
/*<       y2free=y2 >*/
    xs2com_1.y2free = xs2com_1.y2;
/* SOURCE culvertb.for:4050 */
/*<       q3free=q3 >*/
    xs3com_1.q3free = xs3com_1.q3;
/* SOURCE culvertb.for:4051 */
/*<       lftype=type >*/
    xs2com_1.lftype = *feq_gen_type_d_;
/* SOURCE culvertb.for:4052 */
/*<       lstype=-1 >*/
    xs2com_1.lstype = -1;
/* SOURCE culvertb.for:4053 */
/*<       tp2=min(y3,ddn) >*/
    tp2 = dmin(xs3com_1.y3,ddn);
/* SOURCE culvertb.for:4054 */
/*<       callxlktal(adrxs3,tp2,a3,t3,dt3,j3,k3,dk3,bet3,dbet3,alp3,dalp3) >*/
    xlktal_(&xs3com_1.adrxs3, &tp2, &xs3com_1.a3, &xs3com_1.t3, &xs3com_1.dt3,
	     &xs3com_1.j3, &xs3com_1.k3, &xs3com_1.dk3, &xs3com_1.bet3, &
	    xs3com_1.dbet3, &xs3com_1.alp3, &xs3com_1.dalp3);
/*     First moment of area should be at piezometric level-not the water */
/*     surface level.   These levels differ for type 6 flow. */
/* SOURCE culvertb.for:4060 */
/*<       tp2=z3p-zb3 >*/
    tp2 = static_cast<double>(xs3com_1.z3p) - xs3com_1.zb3;
/* SOURCE culvertb.for:4061 */
/*<       calllktj(adrxs3,tp2,j3) >*/
    lktj_(&xs3com_1.adrxs3, &tp2, &xs3com_1.j3);
/*     DETERMINE DEPARTURE SECTION VALUES AND FREED */
/*      WRITE(STDOUT,*) 'FRFT6: Z3P=',Z3P,' Y3=',Y3,' Z3=',Z3 */
/* SOURCE culvertb.for:4071 */
/*<       calldpm26(stdout,wfrdf,mfrdf,z3p,expflg) >*/
    dpm26_(stdout, &rdfcom_1.wfrdf, &rdfcom_1.mfrdf, &xs3com_1.z3p, expflg);
/* SOURCE culvertb.for:4074 */
/*<       if(expflg.eq.0)then >*/
    if (*expflg == 0) {
/* SOURCE culvertb.for:4075 */
/*<       return >*/
	return 0;
/* SOURCE culvertb.for:4076 */
/*<       endif >*/
    }
/*     DEPARTURE SECTION VALUES ARE IN XS4COM */
/* SOURCE culvertb.for:4080 */
/*<       freed=z1-z4 >*/
    *freed = static_cast<double>(xs1com_1.z1) - xs4com_1.z4;
/* SOURCE culvertb.for:4082 */
/*<       return >*/
    return 0;
/* SOURCE culvertb.for:4083 */
/*<       end >*/
} /* frft6_ */




/* SOURCE culvertb.for:4087 */
/*<        >*/
/* Subroutine */ int frft56_(integer *stdout, real *hdatum, real *zdatum, 
	real *hup, integer *iu, integer *id, char *culcls, integer *eflag, 
	integer *feq_gen_type_d_, integer *expflg, real *qfree, real *freed, ftnlen 
	culcls_len)
{
    extern /* Subroutine */ int frft5_(integer *, real *, real *, integer *, 
	    integer *, char *, integer *, integer *, real *, real *, ftnlen), 
	    frft6_(integer *, real *, real *, real *, integer *, integer *, 
	    char *, integer *, integer *, integer *, real *, real *, ftnlen);

/*     + + + PURPOSE + + + */
/*     Compute a flow of type 5 or type 6. */
/* SOURCE culvertb.for:4094 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertb.for:4097 */
/*<       integereflag,expflg,id,iu,stdout,type >*/
/* SOURCE culvertb.for:4098 */
/*<       realfreed,hdatum,hup,qfree,zdatum >*/
/* SOURCE culvertb.for:4099 */
/*<       characterculcls*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     HDATUM - Datum for measuring head */
/*     ZDATUM - datum for local elevation */
/*     HUP    - Head upstream */
/*     IU     - Index for upstream node for the culvert barrel */
/*     ID     - Index for the downstream node for the culvert barrel */
/*     CULCLS - Class for culvert shape, BOX, PIPE, .. */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     TYPE   - Culvert flow type */
/*     EXPFLG - Expansion flag.  EXPFLG=1 if flow expands on exit */
/*              and EXPFLG=0 if flow does not expand on exit */
/*     QFREE  - Free flow */
/*     FREED  - Free drop */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertb.for:4117 */
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
/* INCLUDE culvertb.for:4118 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culvertb.for:4119 */
/*     Common to hold values needed for computing various limits */
/*     for culvert flow types. */
/* SOURCE typlim.cmn:4 */
/*<        >*/
/* SOURCE typlim.cmn:10 */
/*<       integerhhtype >*/
/* SOURCE typlim.cmn:12 */
/*<        >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertb.for:4122 */
/*<       externalfrft5,frft6 >*/
/* *********************************************************************** */
/* SOURCE culvertb.for:4124 */
/*<       if(hhtype.eq.5)then >*/
    if (typlim_1.hhtype == 5) {
/*       Culvert is steep enough to have type 5 flow. */
/* SOURCE culvertb.for:4126 */
/*<       type=5 >*/
	*feq_gen_type_d_ = 5;
/* SOURCE culvertb.for:4127 */
/*<       lftype=5 >*/
	xs2com_1.lftype = 5;
/* SOURCE culvertb.for:4128 */
/*<       lstype=-1 >*/
	xs2com_1.lstype = -1;
/* SOURCE culvertb.for:4130 */
/*<       callfrft5(stdout,hdatum,hup,iu,id,culcls,type,expflg,qfree,freed) >*/
	frft5_(stdout, hdatum, hup, iu, id, culcls, feq_gen_type_d_, expflg, qfree, 
		freed, (ftnlen)8);
/* SOURCE culvertb.for:4133 */
/*<       else >*/
    } else {
/* SOURCE culvertb.for:4134 */
/*<       type=6 >*/
	*feq_gen_type_d_ = 6;
/* SOURCE culvertb.for:4135 */
/*<        >*/
	frft6_(stdout, hdatum, zdatum, hup, iu, id, culcls, eflag, feq_gen_type_d_, 
		expflg, qfree, freed, (ftnlen)8);
/* SOURCE culvertb.for:4138 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:4140 */
/*<       return >*/
    return 0;
/* SOURCE culvertb.for:4141 */
/*<       end >*/
} /* frft56_ */




/* SOURCE culvertb.for:4145 */
/*<        >*/
/* Subroutine */ int frft12_(integer *stdout, real *hdatum, real *zdatum, 
	real *hup, real *dup, real *ddn, integer *iu, integer *id, char *
	culcls, real *truea1, real *cd1, integer *eflag, integer *feq_gen_type_d_, 
	integer *conflg, integer *expflg, real *qfree, real *freed, ftnlen 
	culcls_len)
{
    /* System generated locals */
    real feq_gen_r_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();

    /* Local variables */
    real fg, sb;
    extern /* Subroutine */ int frft1_(integer *, real *, real *, real *, 
	    real *, integer *, integer *, char *, real *, integer *, real *, 
	    integer *, integer *, integer *, real *, real *, ftnlen), frft2_(
	    integer *, real *, real *, real *, integer *, integer *, char *, 
	    integer *, real *, integer *, integer *, real *, real *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__399 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__400 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__401 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Compute flow for type 1 or 2 in a culvert. */
/* SOURCE culvertb.for:4154 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertb.for:4157 */
/*<       integerconflg,eflag,expflg,id,iu,stdout,type >*/
/* SOURCE culvertb.for:4158 */
/*<       realcd1,ddn,dup,freed,hdatum,hup,qfree,truea1,zdatum >*/
/* SOURCE culvertb.for:4159 */
/*<       characterculcls*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     HDATUM - Datum for measuring head */
/*     ZDATUM - datum for local elevation */
/*     HUP    - Head upstream */
/*     DUP    - vertical diameter of culvert barrel at upstream end */
/*     DDN    - vertical diameter of culvert barrel at downstream end */
/*     IU     - Index for upstream node for the culvert barrel */
/*     ID     - Index for the downstream node for the culvert barrel */
/*     CULCLS - Class for culvert shape, BOX, PIPE, .. */
/*     TRUEA1 - area at section 1 */
/*     CD1 - Type 1 discharge coef.  -1 if type 1 not possible. 0 if */
/*              not tested yet, > 0 if known. */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     TYPE   - Culvert flow type */
/*     CONFLG - CONFLG=0: flow contracts as it enters the culvert and */
/*              CONFLG=1: flow expands as it enters the culver */
/*     EXPFLG - Expansion flag.  EXPFLG=1 if flow expands on exit */
/*              and EXPFLG=0 if flow does not expand on exit */
/*     QFREE  - Free flow */
/*     FREED  - Free drop */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertb.for:4184 */
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
/* INCLUDE culvertb.for:4185 */
/* SOURCE culcom.cmn:2 */
/*<        >*/
/* SOURCE culcom.cmn:8 */
/*<       integernsec(mnbn),hltab(mnbn),iat3d,iat6d,sbkind,sbshape >*/
/* SOURCE culcom.cmn:10 */
/*<        >*/
/* SOURCE culcom.cmn:16 */
/*<       doubleprecisionfrcfac >*/
/*     FRCFAC- friction factor to give factor for friction losses */
/*             in barrel for non-prismatic full-flow that as well */
/*             as prismatic full flow. */
/*     TY1YTD- maximum ratio of depth to vertical diameter for */
/*             type 1 flow. */
/*     TY1HTD- maximum ratio of head at section 1 relative to */
/*             culvert invert at culvert inlet to the vertical */
/*             diamter of the culvert.  Must be less than 1.5. */
/*     SBKIND- if 0 the slope of the culvert barrel is a constant, */
/*             if 1 the slope of the culvert barrel varies. */
/*     BSHAPE- if 0 the barrel shape is constant, that is, prismatic, */
/*             if 1 the barrel shape is nonprismatic. */
/*     TY5SBF- ratio of depth to vertical diameter of the culvert */
/*             at the exit which causes submergence. */
/* Note:  25 August 2004:  SBSHAPE is apparently not used.  BSHAPE */
/* is but outside of a common block. */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertb.for:4188 */
/*<       realfg,sb >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertb.for:4191 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertb.for:4194 */
/*<       externalfrft1,frft2 >*/
/* *********************************************************************** */
/*     CHECK FOR BOTTOM SLOPE AT ENTRANCE AND ELIMINATE OBVIOUS */
/*     NON-TYPE 1 FLOW */
/* SOURCE culvertb.for:4199 */
/*<       sb=(zbvec(iu)-zbvec(iu+1))/abs(xvec(iu)-xvec(iu+1)) >*/
    sb = (static_cast<double>(culcom_1.zbvec[*iu - 1]) - culcom_1.zbvec[*iu]) / (feq_gen_r_d_1 = 
	    static_cast<double>(culcom_1.xvec[*iu - 1]) - culcom_1.xvec[*iu], dabs(feq_gen_r_d_1));
/* SOURCE culvertb.for:4200 */
/*<       if(sb.gt.0.0.and.cd1>=0.0)then >*/
    if (sb > (float)0. && *cd1 >= (float)0.) {
/*       TRY TYPE 1 FLOW */
/* SOURCE culvertb.for:4202 */
/*<       type=1 >*/
	*feq_gen_type_d_ = 1;
/* SOURCE culvertb.for:4203 */
/*<        >*/
	frft1_(stdout, hdatum, hup, dup, ddn, iu, id, culcls, truea1, eflag, &
		fg, feq_gen_type_d_, conflg, expflg, qfree, freed, (ftnlen)8);
/* SOURCE culvertb.for:4208 */
/*<       if(type.ne.1)then >*/
	if (*feq_gen_type_d_ != 1) {
/* SOURCE culvertb.for:4209 */
/*<       write(stdout,*)' Rejecting Type 1. Trying Type 2.' >*/
	    feq_gen_io_d__399.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__399);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Rejecting Type 1. Trying Type 2."), (ftnlen)
		    33);
	    e_wsle();
/*         TRY FLOW TYPE 2 */
/* SOURCE culvertb.for:4211 */
/*<       if(type.eq.2)then >*/
	    if (*feq_gen_type_d_ == 2) {
/* SOURCE culvertb.for:4212 */
/*<        >*/
		frft2_(stdout, hdatum, zdatum, hup, iu, id, culcls, eflag, &
			fg, feq_gen_type_d_, expflg, qfree, freed, (ftnlen)8);
/* SOURCE culvertb.for:4215 */
/*<       else >*/
	    } else {
/* SOURCE culvertb.for:4216 */
/*<       write(stdout,*)' Rejecting Type 2. Trying Type 5.' >*/
		feq_gen_io_d__400.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__400);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Rejecting Type 2. Trying Type 5."), (
			ftnlen)33);
		e_wsle();
/*           FORCE COMPUTATION OF TYPE 5 OR 6 AND MAYBE 7. */
/* SOURCE culvertb.for:4218 */
/*<       type=5 >*/
		*feq_gen_type_d_ = 5;
/* SOURCE culvertb.for:4219 */
/*<       endif >*/
	    }
/* SOURCE culvertb.for:4220 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:4221 */
/*<       else >*/
    } else {
/*       TRY FLOW TYPE 2 */
/* SOURCE culvertb.for:4223 */
/*<       type=2 >*/
	*feq_gen_type_d_ = 2;
/* SOURCE culvertb.for:4224 */
/*<       fg=0.0 >*/
	fg = (float)0.;
/* SOURCE culvertb.for:4225 */
/*<        >*/
	frft2_(stdout, hdatum, zdatum, hup, iu, id, culcls, eflag, &fg, 
		feq_gen_type_d_, expflg, qfree, freed, (ftnlen)8);
/* SOURCE culvertb.for:4228 */
/*<       if(type.ne.2)then >*/
	if (*feq_gen_type_d_ != 2) {
/* SOURCE culvertb.for:4229 */
/*<       write(stdout,*)' Rejecting Type 2. Trying Type 5.' >*/
	    feq_gen_io_d__401.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__401);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Rejecting Type 2. Trying Type 5."), (ftnlen)
		    33);
	    e_wsle();
/*         FORCE COMPUTATION OF TYPE 5 OR 6 AND MAYBE 7. */
/* SOURCE culvertb.for:4231 */
/*<       type=5 >*/
	    *feq_gen_type_d_ = 5;
/* SOURCE culvertb.for:4232 */
/*<       endif >*/
	}
/* SOURCE culvertb.for:4233 */
/*<       endif >*/
    }
/* SOURCE culvertb.for:4235 */
/*<       return >*/
    return 0;
/* SOURCE culvertb.for:4236 */
/*<       end >*/
} /* frft12_ */

#ifdef __cplusplus
	}
#endif
