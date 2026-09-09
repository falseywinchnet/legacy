#include <feq/tailwater_residual.hpp>
#include <feq/tailwater_residual.hpp>
#include "callbacks.hpp"
/* culverta.f -- translated by f2c (version 20240504).
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

/* COMMON xs3com_ is declared in common.hpp. */

#define xs3com_1 xs3com_

/* COMMON x43com_ is declared in common.hpp. */

#define x43com_1 x43com_

/* COMMON x44com_ is declared in common.hpp. */

#define x44com_1 x44com_

/* COMMON xs4com_ is declared in common.hpp. */

#define xs4com_1 xs4com_

/* COMMON grvcom_ is declared in common.hpp. */

#define grvcom_1 grvcom_

/* COMMON embcmc_ is declared in common.hpp. */

#define embcmc_1 embcmc_

/* COMMON embcom_ is declared in common.hpp. */

#define embcom_1 embcom_

/* COMMON rdfcom_ is declared in common.hpp. */

#define rdfcom_1 rdfcom_

/* COMMON typtrn_ is declared in common.hpp. */

#define typtrn_1 typtrn_

/* COMMON rty7c_ is declared in common.hpp. */

#define rty7c_1 rty7c_

/* COMMON embq_ is declared in common.hpp. */

#define embq_1 embq_

/* COMMON flapgate_ is declared in common.hpp. */

#define flapgate_1 flapgate_

/* COMMON xs1com_ is declared in common.hpp. */

#define xs1com_1 xs1com_

/* COMMON typlim_ is declared in common.hpp. */

#define typlim_1 typlim_

/* COMMON appcom_ is declared in common.hpp. */

#define appcom_1 appcom_

/* COMMON cdcom_ is declared in common.hpp. */

#define cdcom_1 cdcom_

/* COMMON y1gy2_ is declared in common.hpp. */

#define y1gy2_1 y1gy2_

/* COMMON y1gy2c_ is declared in common.hpp. */

#define y1gy2c_1 y1gy2c_

/* COMMON epscom_ is declared in common.hpp. */

#define epscom_1 epscom_

/* COMMON xs2com_ is declared in common.hpp. */

#define xs2com_1 xs2com_

/* COMMON culcom_ is declared in common.hpp. */

#define culcom_1 culcom_

/* COMMON rqvtw_ is declared in common.hpp. */

#define rqvtw_1 rqvtw_

/* COMMON rqvtc_ is declared in common.hpp. */

#define rqvtc_1 rqvtc_

/* COMMON depcom_ is declared in common.hpp. */

#define depcom_1 depcom_

/* COMMON ftable_ is declared in common.hpp. */

#define ftable_1 ftable_

/* COMMON ftablea_ is declared in common.hpp. */

#define ftablea_1 ftablea_

/* COMMON ftablec_ is declared in common.hpp. */

#define ftablec_1 ftablec_

/* COMMON offcom_ is declared in common.hpp. */

#define offcom_1 offcom_

/* COMMON xscomu_ is declared in common.hpp. */

#define xscomu_1 xscomu_

/* COMMON xs0com_ is declared in common.hpp. */

#define xs0com_1 xs0com_

/* COMMON putget_ is declared in common.hpp. */

#define putget_1 putget_

/* COMMON upgrdc_ is declared in common.hpp. */

#define upgrdc_1 upgrdc_

/* Table of constant values */

static integer feq_gen_c_d_0 = 0;
static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_9 = 9;
static real c_b41 = (float)1e-6;
static integer feq_gen_c_d_3 = 3;
static integer feq_gen_c_d_4 = 4;
static real c_b137 = (float)0.;
static integer feq_gen_c_d_2 = 2;
static doublereal c_b172 = 0.;
static integer c_n1 = -1;
static doublereal c_b308 = .666667;
static integer feq_gen_c_d_10 = 10;
static integer feq_gen_c_d_8 = 8;
static integer feq_gen_c_d_27 = 27;
static integer feq_gen_c_d_12 = 12;
static integer feq_gen_c_d_20 = 20;
static integer feq_gen_c_d_10002 = 10002;
static integer feq_gen_c_d_8400 = 8400;
static integer c_b750 = 13000001;
static integer feq_gen_c_d_151 = 151;
static real c_b996 = (float)1.;




/* SOURCE culverta.for:4 */
/*<       realfunctionrty7rf(ztail) >*/
doublereal rty7rf_(real *ztail)
{
    /* System generated locals */
    real ret_val, feq_gen_r_d_1;

    /* Builtin functions */
    double sqrt(doublereal), exp(doublereal);

    /* Local variables */
    real m44, yc, yt, feq_gen_flap_force_d_, dq3, pdv;
    double m43;
    integer ntab;
    real drop;
    extern /* Subroutine */ int f4to44_(integer *, integer *);
    real ztlow;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *), xlkt22_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *), fndcde_(integer *, integer *, real *, real *), sbfebc_(
	    integer *, real *, real *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, char *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, ftnlen);
    integer nsflag;
    real zthigh;
    extern /* Subroutine */ int xlktal_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *);

/*     + + + PURPOSE + + + */
/*     Compute the residual for all cases when the tail water location */
/*     is at section 43 for submergence of flow over the road. */
/*     Submergence for flow over the road and for flow through the */
/*     culvert conduit is taken to be at section 43.  Flapgate losses */
/*     are also estimated here using what paltry information is available. */
/* SOURCE culverta.for:14 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culverta.for:17 */
/*<       realztail >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ZTAIL  - elevation of water surface at section 43 */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culverta.for:23 */
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
/* INCLUDE culverta.for:24 */
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
/* INCLUDE culverta.for:25 */
/* SOURCE x43com.cmn:2 */
/*<        >*/
/* SOURCE x43com.cmn:6 */
/*<       integeradrs43,stat43 >*/
/* SOURCE x43com.cmn:8 */
/*<        >*/
/* INCLUDE culverta.for:26 */
/* SOURCE x44com.cmn:2 */
/*<        >*/
/* SOURCE x44com.cmn:6 */
/*<       integeradrs44,stat44 >*/
/* SOURCE x44com.cmn:8 */
/*<        >*/
/* INCLUDE culverta.for:27 */
/* SOURCE xs4com.cmn:2 */
/*<        >*/
/* SOURCE xs4com.cmn:5 */
/*<       integeradrxs4 >*/
/* SOURCE xs4com.cmn:7 */
/*<        >*/
/* INCLUDE culverta.for:28 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culverta.for:29 */
/*     COMMOM BLOCK FOR THE DESCRIPTION OF THE FLOW OVER AN EMBANKMENT */
/* SOURCE embcom.cmn:3 */
/*<       character*8surf(pmxoff) >*/
/* SOURCE embcom.cmn:5 */
/*<       integernoff,minloc,plcwtb,glcwtb,phcwtb,ghcwtb,psubtb,gsubtb >*/
/* SOURCE embcom.cmn:8 */
/*<       realmincrs,rmffac >*/
/* SOURCE embcom.cmn:10 */
/*<        >*/
/* SOURCE embcom.cmn:20 */
/*<       common/embcmc/surf >*/
/* SOURCE embcom.cmn:22 */
/*<        >*/
/* INCLUDE culverta.for:30 */
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
/* INCLUDE culverta.for:31 */
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
/* INCLUDE culverta.for:32 */
/*     Common for function RTY7C in FEQUTL */
/* SOURCE rty7c.cmn:3 */
/*<       common/rty7c/outun,ef,z1t,z4t,zsub,t7flag,q3adr,y3adr,ddn >*/
/* SOURCE rty7c.cmn:6 */
/*<       integeroutun,ef,t7flag,q3adr,y3adr >*/
/* SOURCE rty7c.cmn:7 */
/*<       realz1t,z4t,zsub,ddn >*/
/* INCLUDE culverta.for:33 */
/*     Common block for key values describing the nature of weir */
/*     flow. */
/* SOURCE embwrq.cmn:4 */
/*<       integerhlflag,hpflag >*/
/* SOURCE embwrq.cmn:6 */
/*<       realhlcrit,hlmax >*/
/* SOURCE embwrq.cmn:8 */
/*<       common/embq/hlflag,hpflag,hlcrit,hlmax >*/
/* SOURCE embwrq.cmn:10 */
/*<       save/embq/ >*/
/*     HLCRIT  Ratio of piezometric head to crest breadth at boundary */
/*             between low head and high head flow in the USGS */
/*             embankment-shaped weir methodology. */
/*     HLMAX   Maximum value of piezometric head to crest breadth ratio */
/*             above which a warning message is issued. */
/*     HLFLAG  Warning message suppression flag for warnings about the */
/*             piezometric head to crest breadth ratio becoming greater */
/*             than HLMAX */
/*     HPFLAG  Warning message suppression flag for invalid weir flow */
/* INCLUDE culverta.for:34 */
/*     Common block for flapgate on culvert. */
/* SOURCE flapgate.cmn:3 */
/*<       common/flapgate/flap >*/
/* SOURCE flapgate.cmn:5 */
/*<       realflap >*/
/* SOURCE flapgate.cmn:7 */
/*<       save/flapgate/ >*/
/*     If FLAP=0.0 then no gate is present. Otherwise FLAP is a */
/*     factor on the internal headloss coefficient. */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culverta.for:37 */
/*<       integernsflag,ntab >*/
/* SOURCE culverta.for:38 */
/*<       realdq3,drop,flap_force,kflap,m43,m44,pdv,yc,yt,ztlow,zthigh >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culverta.for:42 */
/*<       intrinsicsqrt >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culverta.for:45 */
/*<       externalf4to44,fndcde,lktab,sbfebc,xlkt22,xlktal >*/
/* *********************************************************************** */
/*      WRITE(OUTUN,*) 'ENTRY to RTY7RF: ZTAIL=',ZTAIL */
/*     Find the cross section elements at section 43. */
/* SOURCE culverta.for:50 */
/*<       z43=ztail >*/
    x43com_1.z43 = *ztail;
/* SOURCE culverta.for:51 */
/*<       y43=ztail-zb43 >*/
    x43com_1.y43 = static_cast<double>(*ztail) - x43com_1.zb43;
/* SOURCE culverta.for:52 */
/*<        >*/
    xlktal_(&x43com_1.adrs43, &x43com_1.y43, &x43com_1.a43, &x43com_1.t43, &
	    x43com_1.dt43, &x43com_1.j43, &x43com_1.k43, &x43com_1.dk43, &
	    x43com_1.bet43, &x43com_1.dbet43, &x43com_1.alp43, &
	    x43com_1.dalp43);
/*      WRITE(OUTUN,*) ' J43=',J43 */
/*     Establish the flow over the road if any.  Any submergence is */
/*     included in the final values. */
/* SOURCE culverta.for:63 */
/*<       if(ztail.gt.zsub)then >*/
    if (*ztail > rty7c_1.zsub) {
/* SOURCE culverta.for:64 */
/*<        >*/
	sbfebc_(&rty7c_1.outun, &rty7c_1.z1t, ztail, &embcom_1.plcwtb, &
		embcom_1.glcwtb, &embcom_1.phcwtb, &embcom_1.ghcwtb, &
		embcom_1.psubtb, &embcom_1.gsubtb, &embcom_1.noff, 
		embcmc_1.surf, &embq_1.hlcrit, embcom_1.xrdfl, embcom_1.xrdfr,
		 embcom_1.hrdfl, embcom_1.hrdfm, embcom_1.hrdfr, 
		embcom_1.qrdfl, embcom_1.qrdfm, embcom_1.qrdfr, 
		embcom_1.tothl, embcom_1.tothm, embcom_1.tothr, embcom_1.yfl, 
		embcom_1.yfm, embcom_1.yfr, embcom_1.appl, embcom_1.appm, 
		embcom_1.appr, embcom_1.wl, embcom_1.wm, embcom_1.wr, 
		embcom_1.aell, embcom_1.aelm, embcom_1.aelr, &embcom_1.rmffac,
		 &rdfcom_1.wfrd, &rdfcom_1.mfrd, &rdfcom_1.efrd, (ftnlen)8);
/* SOURCE culverta.for:71 */
/*<       else >*/
    } else {
/* SOURCE culverta.for:72 */
/*<       wfrd=wfrdf >*/
	rdfcom_1.wfrd = rdfcom_1.wfrdf;
/* SOURCE culverta.for:73 */
/*<       mfrd=mfrdf >*/
	rdfcom_1.mfrd = rdfcom_1.mfrdf;
/* SOURCE culverta.for:74 */
/*<       efrd=efrdf >*/
	rdfcom_1.efrd = rdfcom_1.efrdf;
/* SOURCE culverta.for:75 */
/*<       endif >*/
    }
/*     Now find the flow in the culvert for the given upstream level, */
/*     Z1T and the given tailwater, ZTAIL. */
/* SOURCE culverta.for:80 */
/*<       drop=z1t-ztail >*/
    drop = static_cast<double>(rty7c_1.z1t) - *ztail;
/*      WRITE(OUTUN,*) ' RTY7RF: DROP=',DROP */
/* SOURCE culverta.for:82 */
/*<       drop=sqrt(drop) >*/
    drop = sqrt(drop);
/*      WRITE(OUTUN,*) ' RTY7RF: SQRT(DROP)=',DROP */
/* SOURCE culverta.for:84 */
/*<       calllktab(q3adr,drop,0,q3,ntab,dq3) >*/
    lktab_(&rty7c_1.q3adr, &drop, &feq_gen_c_d_0, &xs3com_1.q3, &ntab, &dq3);
/*     Find the depth at section 3. */
/* SOURCE culverta.for:90 */
/*<       calllktab(y3adr,ztail,0,y3,ntab,pdv) >*/
    lktab_(&rty7c_1.y3adr, ztail, &feq_gen_c_d_0, &xs3com_1.y3, &ntab, &pdv);
/* SOURCE culverta.for:93 */
/*<        >*/
    xlkt22_(&xs3com_1.adrxs3, &xs3com_1.y3, &xs3com_1.a3, &xs3com_1.t3, &
	    xs3com_1.dt3, &xs3com_1.j3, &xs3com_1.k3, &xs3com_1.dk3, &
	    xs3com_1.bet3, &xs3com_1.dbet3, &xs3com_1.alp3, &xs3com_1.dalp3, &
	    xs3com_1.q3c);
/* SOURCE culverta.for:98 */
/*<       z3=y3+zb3 >*/
    xs3com_1.z3 = static_cast<double>(xs3com_1.y3) + xs3com_1.zb3;
/*      WRITE(OUTUN,*) ' RTY7RF: Y3=',Y3,' A3=',A3,' J3=',J3,' Z3=',Z3, */
/*     A                ' Q3=',Q3 */
/* SOURCE culverta.for:101 */
/*<       q4=q3+wfrd >*/
    xs4com_1.q4 = static_cast<double>(xs3com_1.q3) + rdfcom_1.wfrd;
/*     Compute the momentum flux plus impulse at section 43.  If */
/*     BETAF > 0, then we use a special value computed from ZTAIL */
/* SOURCE culverta.for:105 */
/*<       yt=ztail-zb3 >*/
    yt = static_cast<double>(*ztail) - xs3com_1.zb3;
/* SOURCE culverta.for:107 */
/*<       if(betaf.gt.0.0)then >*/
    if (typtrn_1.betaf > (float)0.) {
/* SOURCE culverta.for:108 */
/*<       if(y3pf.lt.ddn)then >*/
	if (typtrn_1.y3pf < rty7c_1.ddn) {
/* SOURCE culverta.for:109 */
/*<       if(yt.lt.ddn)then >*/
	    if (yt < rty7c_1.ddn) {
/* SOURCE culverta.for:110 */
/*<       beta3=betaf+(yt-y3pf)*(bt3atd-betaf)/(ddn-y3pf) >*/
		typtrn_1.beta3 = static_cast<double>(typtrn_1.betaf) + static_cast<double>(static_cast<double>((static_cast<double>(yt) - typtrn_1.y3pf)) * (
			static_cast<double>(xs3com_1.bt3atd) - typtrn_1.betaf)) / (static_cast<double>(rty7c_1.ddn) - 
			typtrn_1.y3pf);
/* SOURCE culverta.for:111 */
/*<       alpha3=alphaf+(yt-y3pf)*(ap3atd-alphaf)/(ddn-y3pf) >*/
		typtrn_1.alpha3 = static_cast<double>(typtrn_1.alphaf) + static_cast<double>(static_cast<double>((static_cast<double>(yt) - typtrn_1.y3pf)) * (
			static_cast<double>(xs3com_1.ap3atd) - typtrn_1.alphaf)) / (static_cast<double>(rty7c_1.ddn) - 
			typtrn_1.y3pf);
/* SOURCE culverta.for:112 */
/*<       else >*/
	    } else {
/* SOURCE culverta.for:113 */
/*<       beta3=bt3atd >*/
		typtrn_1.beta3 = xs3com_1.bt3atd;
/* SOURCE culverta.for:114 */
/*<       alpha3=ap3atd >*/
		typtrn_1.alpha3 = xs3com_1.ap3atd;
/* SOURCE culverta.for:115 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:116 */
/*<       else >*/
	} else {
/*         Special case in some cases in which the tailwater inducing */
/*         value is above the exit soffit.  Interpolate on tailwater */
/*         over 0.25 of the distance from the free flow limit elevation */
/*         of tailwater at section 3, Y3PF + ZB3, and the tailwater */
/*         level at zero flow, Z1T. */
/* SOURCE culverta.for:122 */
/*<       ztlow=y3pf+zb3 >*/
	    ztlow = static_cast<double>(typtrn_1.y3pf) + xs3com_1.zb3;
/* SOURCE culverta.for:123 */
/*<       zthigh=ztlow+0.25*(z1t-ztlow) >*/
	    zthigh = static_cast<double>(ztlow) + static_cast<double>((static_cast<double>(rty7c_1.z1t) - ztlow)) * (float).25;
/* SOURCE culverta.for:124 */
/*<       if(ztail.ge.zthigh)then >*/
	    if (*ztail >= zthigh) {
/* SOURCE culverta.for:125 */
/*<       beta3=bt3atd >*/
		typtrn_1.beta3 = xs3com_1.bt3atd;
/* SOURCE culverta.for:126 */
/*<       alpha3=ap3atd >*/
		typtrn_1.alpha3 = xs3com_1.ap3atd;
/* SOURCE culverta.for:127 */
/*<       else >*/
	    } else {
/* SOURCE culverta.for:128 */
/*<       beta3=betaf+(ztail-ztlow)*(bt3atd-betaf)/(zthigh-ztlow) >*/
		typtrn_1.beta3 = static_cast<double>(typtrn_1.betaf) + static_cast<double>(static_cast<double>((static_cast<double>(*ztail) - ztlow)) * (
			static_cast<double>(xs3com_1.bt3atd) - typtrn_1.betaf)) / (static_cast<double>(zthigh) - ztlow);
/* SOURCE culverta.for:130 */
/*<       alpha3=alphaf+(ztail-ztlow)*(ap3atd-alphaf)/(zthigh-ztlow) >*/
		typtrn_1.alpha3 = static_cast<double>(typtrn_1.alphaf) + static_cast<double>(static_cast<double>((static_cast<double>(*ztail) - ztlow)) * (
			static_cast<double>(xs3com_1.ap3atd) - typtrn_1.alphaf)) / (static_cast<double>(zthigh) - ztlow);
/* SOURCE culverta.for:132 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:133 */
/*<       endif >*/
	}
/* SOURCE culverta.for:134 */
/*<       else >*/
    } else {
/* SOURCE culverta.for:135 */
/*<       beta3=bet3 >*/
	typtrn_1.beta3 = xs3com_1.bet3;
/* SOURCE culverta.for:136 */
/*<       alpha3=alp3 >*/
	typtrn_1.alpha3 = xs3com_1.alp3;
/* SOURCE culverta.for:137 */
/*<       endif >*/
    }
/*      WRITE(OUTUN,*) ' BETAF=',BETAF,' YT=',YT,' DDN=',DDN, */
/*     A               ' BETA3=',BETA3 */
/* SOURCE culverta.for:141 */
/*<       m43=mfrd+beta3*q3*q3/a3+grav*j43 >*/
    m43 = feq::tailwater_upstream_momentum(xs3com_1.q3,typtrn_1.beta3,xs3com_1.a3,
        rdfcom_1.mfrd,x43com_1.j43,grvcom_1.grav);
/* SOURCE culverta.for:143 */
/*<       if(t7flag.eq.1)then >*/
    if (rty7c_1.t7flag == 1) {
/*       Finding the free flow for type 7 with critical flow at */
/*       section 4.  Find critical depth at section 4 */
/* SOURCE culverta.for:147 */
/*<       yc=y4 >*/
	yc = xs4com_1.y4;
/* SOURCE culverta.for:148 */
/*<       if(yc.eq.0.0)then >*/
	if (yc == (float)0.) {
/* SOURCE culverta.for:149 */
/*<       yc=0.5 >*/
	    yc = (float).5;
/* SOURCE culverta.for:150 */
/*<       endif >*/
	}
/* SOURCE culverta.for:151 */
/*<       callfndcde(outun,adrxs4,q4,yc) >*/
	fndcde_(&rty7c_1.outun, &xs4com_1.adrxs4, &xs4com_1.q4, &yc);
/* SOURCE culverta.for:154 */
/*<       y4=yc >*/
	xs4com_1.y4 = yc;
/* SOURCE culverta.for:155 */
/*<       z4=y4+zb4 >*/
	xs4com_1.z4 = static_cast<double>(xs4com_1.y4) + xs4com_1.zb4;
/* SOURCE culverta.for:156 */
/*<       flap_force=0.0 >*/
	feq_gen_flap_force_d_ = (float)0.;
/* SOURCE culverta.for:157 */
/*<       else >*/
    } else {
/*       Finding submerged flow with tailwater for road flow and */
/*       culvert flow at section 43.  Z4T gives the depth at */
/*       section 4 in this case. */
/* SOURCE culverta.for:161 */
/*<       z4=z4t >*/
	xs4com_1.z4 = rty7c_1.z4t;
/* SOURCE culverta.for:162 */
/*<       y4=z4-zb4 >*/
	xs4com_1.y4 = static_cast<double>(xs4com_1.z4) - xs4com_1.zb4;
/*       Include estimated flap gate losses if a flapgate is present. */
/*       Flapgate losses are not well established.  Only passing mention */
/*       of such losses are made in various trade literature put out */
/*       by those whose interest is in minimizing the size of the */
/*       loss.  The following equation has appeared in several locations */
/*       and is used until such time as something better is found. */
/* SOURCE culverta.for:170 */
/*<       if(flap.gt.0.0)then >*/
	if (flapgate_1.flap > (float)0.) {
/*         Compute the velocity head to use as if the conduits are */
/*         flowing full even if they are not.  It appears that the loss */
/*         equations assumed full-conduit flow with the exit completely */
/*         submerged.  However, we cannot limit the losses to those */
/*         conditions without introducing nonsense abrupt changes in */
/*         the flow.  Therefore, we must include losses for submerged */
/*         part-full flow also. */
/* SOURCE culverta.for:178 */
/*<        >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(xs3com_1.q3) / xs3com_1.a3full;
	    feq_gen_flap_force_d_ = static_cast<double>(static_cast<double>(static_cast<double>(flapgate_1.flap) * xs3com_1.a3) * (float)4.) * (static_cast<double>(feq_gen_r_d_1) *
		     feq_gen_r_d_1) * exp(static_cast<double>(xs3com_1.q3) * (float)-1.15 / (
		    xs3com_1.a3full * sqrt(rty7c_1.ddn)));
/* SOURCE culverta.for:180 */
/*<       else >*/
	} else {
/* SOURCE culverta.for:181 */
/*<       flap_force=0.0 >*/
	    feq_gen_flap_force_d_ = (float)0.;
/* SOURCE culverta.for:182 */
/*<       endif >*/
	}
/* SOURCE culverta.for:184 */
/*<       endif >*/
    }
/* SOURCE culverta.for:186 */
/*<       callxlktal(adrxs4,y4,a4,t4,dt4,j4,k4,dk4,bet4,dbet4,alp4,dalp4) >*/
    xlktal_(&xs4com_1.adrxs4, &xs4com_1.y4, &xs4com_1.a4, &xs4com_1.t4, &
	    xs4com_1.dt4, &xs4com_1.j4, &xs4com_1.k4, &xs4com_1.dk4, &
	    xs4com_1.bet4, &xs4com_1.dbet4, &xs4com_1.alp4, &xs4com_1.dalp4);
/*     Find the values at section 44 from those at section 4 */
/* SOURCE culverta.for:192 */
/*<       callf4to44(outun,nsflag) >*/
    f4to44_(&rty7c_1.outun, &nsflag);
/*      WRITE(OUTUN,*) ' NSFLAG=',NSFLAG,' Y4=',Y4,' Y44=',Y44, */
/*     A               ' J44=',J44,' A44=',A44 */
/*     Compute the momentum flux plus impulse at section 44. */
/* SOURCE culverta.for:200 */
/*<       m44=bet44*q4*q4/a44+grav*j44 >*/
    // Flap force is supplied by the preceding flow-condition branch.
    return feq::tailwater_momentum_residual(m43,feq_gen_flap_force_d_,
        x44com_1.bet44,xs4com_1.q4,x44com_1.a44,x44com_1.j44,grvcom_1.grav);
} /* rty7rf_ */




/* SOURCE culverta.for:211 */
/*<       realfunctionry1gy2(y) >*/
doublereal ry1gy2_(real *y)
{
    /* System generated locals */
    real ret_val, feq_gen_r_d_1;

    /* Local variables */
    real vh1, vh2, cdin;
    extern doublereal fcd123_(integer *, integer *, char *, real *, real *, 
	    ftnlen);
    real fdrdw, appfac;
    extern doublereal degcon_(real *, real *, real *);
    real aratio;
    extern /* Subroutine */ int getfrf_(real *, real *, real *), xlktal_(
	    integer *, real *, real *, real *, real *, real *, real *, real *,
	     real *, real *, real *, real *);

/*     + + + PURPOSE + + + */
/*     Residual function for finding type 1 conditions when the */
/*     depth at section 2 is given. */
/* SOURCE culverta.for:218 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culverta.for:221 */
/*<       realy >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Y      - value of the unknown being sought */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culverta.for:227 */
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
/* INCLUDE culverta.for:228 */
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
/* INCLUDE culverta.for:229 */
/*     Common to hold values needed for computing various limits */
/*     for culvert flow types. */
/* SOURCE typlim.cmn:4 */
/*<        >*/
/* SOURCE typlim.cmn:10 */
/*<       integerhhtype >*/
/* SOURCE typlim.cmn:12 */
/*<        >*/
/* INCLUDE culverta.for:230 */
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
/* INCLUDE culverta.for:231 */
/* SOURCE appcom.cmn:2 */
/*<       common/appcom/apptab,appelv,applen,applos,appexp,zertab,zerelv >*/
/* SOURCE appcom.cmn:5 */
/*<       integerapptab,zertab >*/
/* SOURCE appcom.cmn:7 */
/*<       realappelv,applen,applos,appexp,zerelv >*/
/* INCLUDE culverta.for:232 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culverta.for:233 */
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
/* INCLUDE culverta.for:234 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culverta.for:237 */
/*<       realappfac,aratio,cdin,fdrdw,vh1,vh2 >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culverta.for:240 */
/*<       realdegcon,fcd123 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culverta.for:243 */
/*<       externaldegcon,fcd123,getfrf,xlktal >*/
/* *********************************************************************** */
/*     Get the conditions at section 1 */
/* SOURCE culverta.for:246 */
/*<       y1l=y >*/
    typlim_1.y1l = *y;
/* SOURCE culverta.for:247 */
/*<       z1l=zb1+y1l >*/
    typlim_1.z1l = static_cast<double>(xs1com_1.zb1) + typlim_1.y1l;
/* SOURCE culverta.for:248 */
/*<        >*/
    xlktal_(&xs1com_1.adrxs1, &typlim_1.y1l, &typlim_1.a1l, &typlim_1.t1l, &
	    typlim_1.dt1l, &typlim_1.j1l, &typlim_1.k1l, &typlim_1.dk1l, &
	    typlim_1.bet1l, &typlim_1.dbet1l, &typlim_1.alp1l, &
	    typlim_1.dalp1l);
/*     Compute the free flow over the roadway.  WFRDF in embcom.cmn. */
/* SOURCE culverta.for:256 */
/*<       callgetfrf(z1l,zsbrdf,fdrdw) >*/
    getfrf_(&typlim_1.z1l, &y1gy2_1.zsbrdf, &fdrdw);
/* SOURCE culverta.for:259 */
/*<       q1l=q2l+wfrdf >*/
    typlim_1.q1l = static_cast<double>(typlim_1.q2l) + rdfcom_1.wfrdf;
/* SOURCE culverta.for:261 */
/*<       vh1=(q1l/a1l)**2/grav2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(typlim_1.q1l) / typlim_1.a1l;
    vh1 = static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / grvcom_1.grav2;
/* SOURCE culverta.for:262 */
/*<       vh2=(q2l/a2l)**2/grav2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(typlim_1.q2l) / typlim_1.a2l;
    vh2 = static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / grvcom_1.grav2;
/*     CHECK FOR EXPANSION INSTEAD OF CONTRACTION. */
/* SOURCE culverta.for:266 */
/*<       if(a1l.gt.a2l)then >*/
    if (typlim_1.a1l > typlim_1.a2l) {
/*       WE HAVE A CONTRACTION(I.E. ACCELERATION OF FLOW) */
/*       DEFINE THE COEF OF DISCHARGE */
/* SOURCE culverta.for:269 */
/*<       c123=fcd123(outun,1,class,d,z1l) >*/
	cdcom_1.c123 = fcd123_(&y1gy2_1.outun, &feq_gen_c_d_1, y1gy2c_1.feq_gen_class_d_, &
		y1gy2_1.feq_gen_d_d_, &typlim_1.z1l, (ftnlen)8);
/*       MAKE ADJUSTMENTS TO THE COEF. OF DISCHARGE FOR THE DEGREE OF */
/*       CHANNEL CONTRACTION */
/* SOURCE culverta.for:274 */
/*<       cd=degcon(c123,a1l,a2l) >*/
	cdcom_1.cd = degcon_(&cdcom_1.c123, &typlim_1.a1l, &typlim_1.a2l);
/* SOURCE culverta.for:276 */
/*<        >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = cdcom_1.cd;
	ret_val = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>(typlim_1.alp1l) - appcom_1.applos)) * vh1) - static_cast<double>((static_cast<double>(typlim_1.alp2l) 
		+ (static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - (float)1.))) * vh2) + 
		typlim_1.z1l) - typlim_1.z2l) - static_cast<double>(static_cast<double>(static_cast<double>(appcom_1.applen) * typlim_1.q1l) *
		 typlim_1.q2l) / (static_cast<double>(typlim_1.k1l) * typlim_1.k2l);
/* SOURCE culverta.for:278 */
/*<       else >*/
    } else {
/*       WE HAVE AN EXPANSION(I.E. DECELERATION OF FLOW) */
/* SOURCE culverta.for:280 */
/*<       aratio=a1l/a2l >*/
	aratio = static_cast<double>(typlim_1.a1l) / typlim_1.a2l;
/* SOURCE culverta.for:281 */
/*<       if(aratio.gt.0.95)then >*/
	if (aratio > (float).95) {
/*         Interpolate coefficients to make the transistion between */
/*         the two cases smooth.  Define the coefficient for standard */
/*         type 1 case. */
/* SOURCE culverta.for:286 */
/*<       c123=fcd123(outun,1,class,d,z1l) >*/
	    cdcom_1.c123 = fcd123_(&y1gy2_1.outun, &feq_gen_c_d_1, y1gy2c_1.feq_gen_class_d_, &
		    y1gy2_1.feq_gen_d_d_, &typlim_1.z1l, (ftnlen)8);
/*         MAKE ADJUSTMENTS TO THE COEF. OF DISCHARGE FOR THE DEGREE OF */
/*         CHANNEL CONTRACTION */
/* SOURCE culverta.for:291 */
/*<       cdin=degcon(c123,a1l,a2l) >*/
	    cdin = degcon_(&cdcom_1.c123, &typlim_1.a1l, &typlim_1.a2l);
/* SOURCE culverta.for:293 */
/*<       cd=cdin+20.0*(1.0-aratio)*(0.98-cdin) >*/
	    cdcom_1.cd = static_cast<double>(cdin) + static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - aratio)) * (float)20.) * (static_cast<double>((float)
		    .98) - cdin);
/* SOURCE culverta.for:294 */
/*<       appfac=20.0*(1.0-aratio)*appexp >*/
	    appfac = static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - aratio)) * (float)20.) * appcom_1.appexp;
/* SOURCE culverta.for:295 */
/*<       else >*/
	} else {
/* SOURCE culverta.for:296 */
/*<       cd=0.98 >*/
	    cdcom_1.cd = (float).98;
/* SOURCE culverta.for:297 */
/*<       appfac=appexp >*/
	    appfac = appcom_1.appexp;
/* SOURCE culverta.for:298 */
/*<       endif >*/
	}
/* SOURCE culverta.for:300 */
/*<        >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = cdcom_1.cd;
	ret_val = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>(typlim_1.alp1l) - appcom_1.applos)) * vh1) - static_cast<double>((static_cast<double>(typlim_1.alp2l) 
		+ (static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - (float)1.))) * vh2) + 
		typlim_1.z1l) - typlim_1.z2l) - static_cast<double>(static_cast<double>(static_cast<double>(appcom_1.applen) * typlim_1.q1l) *
		 typlim_1.q2l) / (static_cast<double>(typlim_1.k1l) * typlim_1.k2l)) - static_cast<double>(appfac) * (
		static_cast<double>(static_cast<double>(typlim_1.alp1l) * vh1) - static_cast<double>(typlim_1.alp2l) * vh2);
/* SOURCE culverta.for:304 */
/*<       endif >*/
    }
/* SOURCE culverta.for:306 */
/*<       end >*/
    return ret_val;
} /* ry1gy2_ */




/* SOURCE culverta.for:310 */
/*<        >*/
/* Subroutine */ int frft7_(integer *stdout, real *z1true, integer *id, real *
	zsbrdf, char *option, real *dz4, integer *q3vsrd, integer *y3vstw, 
	real *z4true, real *qclv, real *fdrop, ftnlen option_len)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *BUG:XXX* SIGN CHNG ON ENTRY BUT RGF CLAIM\
S NONE IN\002,\002 FRFT7.\002)";
    static char fmt_60[] = "(\002 *BUG:XXX* RGF: MORE THAN 100 ITERATIONS IN\
 FRFT7.\002)";
    static char fmt_62[] = "(\002 Low arg=\002,f10.4,\002 High arg=\002,f10.\
4,\002 Residual=\002,f10.4)";
    static char fmt_70[] = "(\002 *BUG:XXX* RGF: INVALID FLAG RETURNED IN FR\
FT7.\002)";
    static char fmt_74[] = "(\002 No solution found in FRFT7 after 100 tri\
es.\002)";
    static char fmt_75[] = "(/,\002 FRFT7: Minimum depth=\002,f8.3,\002 at s\
ection 43 found\002,\002 seeking a negative residual.\002)";
    static char fmt_76[] = "(/,\002 Accepting result with relative residual \
in impulse+\002,\002momentum=\002,1pe10.3)";

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe(),
	     do_fio(integer *, char *, ftnlen);

    /* Local variables */
    real f, fl, fr, yt, zt;
    extern /* Subroutine */ int rgf_(real *, real *, FeqCallback3, real *, real *, 
	    real *, real *, real *, integer *);
    integer knt, feq_gen_flag_d_;
    real zlow, y43min, ytail, ytmax, ytmin, zhigh, ztail;
    extern doublereal rty7rf_(real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__19 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__29 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__32 = { 0, 0, 0, fmt_75, 0 };
    static cilist feq_gen_io_d__33 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__36 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__38 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__39 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__40 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__41 = { 0, 0, 0, fmt_70, 0 };


/*     + + + PURPOSE + + + */
/*     Find the flows with the tailwater for roadway flow given */
/*     at section 43.  Used for both free flow of type 7, */
/*     OPTION=FREE, and submerged flow, OPTION=SUBMERGE. */
/* SOURCE culverta.for:321 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culverta.for:324 */
/*<       integerid,q3vsrd,stdout,y3vstw >*/
/* SOURCE culverta.for:325 */
/*<       realdz4,fdrop,qclv,z1true,z4true,zsbrdf >*/
/* SOURCE culverta.for:326 */
/*<       characteroption*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     Z1TRUE - known elevation at section 1 */
/*     ID     - Index for the downstream node for the culvert barrel */
/*     ZSBRDF - Tailwater elevation to cause submergence of flows */
/*               over the roadway */
/*     OPTION - specifies if the flow is FREE or SUBMERGE */
/*     DZ4    - estimated change in elevation at section 4 */
/*     Q3VSRD - address of function table giving flow at section 3 versus */
/*              tailwater at section 43 for a given head at section 1 */
/*     Y3VSTW - address of function table giving depth at section 3 */
/*              versus the tailwater at section 43 */
/*     Z4TRUE - known elevation of water surface at section 4 */
/*     QCLV   - Flow in the culvert */
/*     FDROP  - Free drop value */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culverta.for:345 */
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
/* INCLUDE culverta.for:346 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE culverta.for:347 */
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
/* INCLUDE culverta.for:348 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culverta.for:349 */
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
/* INCLUDE culverta.for:350 */
/* SOURCE x43com.cmn:2 */
/*<        >*/
/* SOURCE x43com.cmn:6 */
/*<       integeradrs43,stat43 >*/
/* SOURCE x43com.cmn:8 */
/*<        >*/
/* INCLUDE culverta.for:351 */
/* SOURCE xs4com.cmn:2 */
/*<        >*/
/* SOURCE xs4com.cmn:5 */
/*<       integeradrxs4 >*/
/* SOURCE xs4com.cmn:7 */
/*<        >*/
/* INCLUDE culverta.for:352 */
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
/* INCLUDE culverta.for:353 */
/*     Common for function RTY7C in FEQUTL */
/* SOURCE rty7c.cmn:3 */
/*<       common/rty7c/outun,ef,z1t,z4t,zsub,t7flag,q3adr,y3adr,ddn >*/
/* SOURCE rty7c.cmn:6 */
/*<       integeroutun,ef,t7flag,q3adr,y3adr >*/
/* SOURCE rty7c.cmn:7 */
/*<       realz1t,z4t,zsub,ddn >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culverta.for:356 */
/*<       integerflag,knt >*/
/* SOURCE culverta.for:357 */
/*<       realf,fl,fr,y43min,yt,ytail,ytmax,ytmin,zhigh,zlow,zt,ztail >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culverta.for:361 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culverta.for:364 */
/*<       realrty7rf >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culverta.for:367 */
/*<       externalrgf,rty7rf >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culverta.for:370 */
/*<    50  >*/
/* SOURCE culverta.for:372 */
/*<    60 format(' *BUG:XXX* RGF: MORE THAN 100 ITERATIONS IN FRFT7.') >*/
/* SOURCE culverta.for:373 */
/*<    62 format(' Low arg=',f10.4,' High arg=',f10.4,' Residual=',f10.4) >*/
/* SOURCE culverta.for:374 */
/*<    70 format(' *BUG:XXX* RGF: INVALID FLAG RETURNED IN FRFT7.') >*/
/* SOURCE culverta.for:375 */
/*<    74 format(' No solution found in FRFT7 after 100 tries.') >*/
/* SOURCE culverta.for:376 */
/*<    75  >*/
/* SOURCE culverta.for:378 */
/*<    76  >*/
/* *********************************************************************** */
/* SOURCE culverta.for:381 */
/*<       if(q3vsrd.eq.0.or.y3vstw.eq.0)then >*/
/* L50: */
/* L60: */
/* L62: */
/* L70: */
/* L74: */
/* L75: */
/* L76: */
    if (*q3vsrd == 0 || *y3vstw == 0) {
/* SOURCE culverta.for:382 */
/*<       write(stdout,*)' *BUG:XXX* Tailwater tables unknown in FRFT7.' >*/
	feq_gen_io_d__19.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__19);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* Tailwater tables unknown in FRFT7."), 
		(ftnlen)45);
	e_wsle();
/* SOURCE culverta.for:383 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culverta.for:384 */
/*<       endif >*/
    }
/*     SET COMMON BLOCK VALUES FOR THE RESIDUAL FUNCTION */
/* SOURCE culverta.for:388 */
/*<       outun=stdout >*/
    rty7c_1.outun = *stdout;
/* SOURCE culverta.for:389 */
/*<       z1t=z1true >*/
    rty7c_1.z1t = *z1true;
/* SOURCE culverta.for:390 */
/*<       z4t=z4true >*/
    rty7c_1.z4t = *z4true;
/* SOURCE culverta.for:391 */
/*<       zsub=zsbrdf >*/
    rty7c_1.zsub = *zsbrdf;
/* SOURCE culverta.for:392 */
/*<       q3adr=q3vsrd >*/
    rty7c_1.q3adr = *q3vsrd;
/* SOURCE culverta.for:393 */
/*<       y3adr=y3vstw >*/
    rty7c_1.y3adr = *y3vstw;
/* SOURCE culverta.for:394 */
/*<       if(option.eq.'FREE    ')then >*/
    if (s_cmp(option, const_cast<char*>("FREE    "), (ftnlen)8, (ftnlen)8) == 0) {
/* SOURCE culverta.for:395 */
/*<       t7flag=1 >*/
	rty7c_1.t7flag = 1;
/* SOURCE culverta.for:396 */
/*<       else >*/
    } else {
/* SOURCE culverta.for:397 */
/*<       t7flag=0 >*/
	rty7c_1.t7flag = 0;
/* SOURCE culverta.for:398 */
/*<       endif >*/
    }
/* SOURCE culverta.for:399 */
/*<       ddn=dvec(id) >*/
    rty7c_1.ddn = culcom_1.dvec[*id - 1];
/* SOURCE culverta.for:400 */
/*<       ytail=z43old-zb43 >*/
    ytail = static_cast<double>(x43com_1.z43old) - x43com_1.zb43;
/* SOURCE culverta.for:402 */
/*<       if(t7flag.eq.1)then >*/
    if (rty7c_1.t7flag == 1) {
/* SOURCE culverta.for:403 */
/*<       ztail=z43old >*/
	ztail = x43com_1.z43old;
/* SOURCE culverta.for:404 */
/*<       else >*/
    } else {
/*       Use change in section 4 elevation as an estimate for the change */
/*       in the elevation at section 43. */
/* SOURCE culverta.for:407 */
/*<       ztail=z43old+dz4 >*/
	ztail = static_cast<double>(x43com_1.z43old) + *dz4;
/* SOURCE culverta.for:408 */
/*<       endif >*/
    }
/* SOURCE culverta.for:409 */
/*<       ytail=ztail-zb43 >*/
    ytail = static_cast<double>(ztail) - x43com_1.zb43;
/*      WRITE(STDOUT,*) ' FRFT7: Z43OLD=',Z43OLD,' YTAIL=',YTAIL, */
/*     A              ' ZTAIL=',ZTAIL,' Z43MIN=',Z43MIN */
/*     Make a final check to avoid going above Z1T */
/* SOURCE culverta.for:415 */
/*<       ytmax=z1t-zb43 >*/
    ytmax = static_cast<double>(rty7c_1.z1t) - x43com_1.zb43;
/* SOURCE culverta.for:416 */
/*<       ytmin=z43old-zb43 >*/
    ytmin = static_cast<double>(x43com_1.z43old) - x43com_1.zb43;
/* SOURCE culverta.for:417 */
/*<       if(ytail.ge.ytmax)then >*/
    if (ytail >= ytmax) {
/* SOURCE culverta.for:418 */
/*<       ytail=0.5*(ytmax+ytmin) >*/
	ytail = static_cast<double>((static_cast<double>(ytmax) + ytmin)) * (float).5;
/* SOURCE culverta.for:419 */
/*<       endif >*/
    }
/* SOURCE culverta.for:421 */
/*<       y43min=z43min-zb43 >*/
    y43min = static_cast<double>(x43com_1.z43min) - x43com_1.zb43;
/* SOURCE culverta.for:422 */
/*<       zhigh=0.0 >*/
    zhigh = (float)0.;
/* SOURCE culverta.for:423 */
/*<       zlow=0.0 >*/
    zlow = (float)0.;
/* SOURCE culverta.for:424 */
/*<       knt=0 >*/
    knt = 0;
/* SOURCE culverta.for:425 */
/*<   100 continue >*/
L100:
/* SOURCE culverta.for:426 */
/*<       ztail=ytail+zb43 >*/
    ztail = static_cast<double>(ytail) + x43com_1.zb43;
/* SOURCE culverta.for:427 */
/*<       f=rty7rf(ztail) >*/
    f = rty7rf_(&ztail);
/* SOURCE culverta.for:428 */
/*<       knt=knt+1 >*/
    ++knt;
/* SOURCE culverta.for:429 */
/*<       if(knt.gt.100)then >*/
    if (knt > 100) {
/* SOURCE culverta.for:430 */
/*<       write(stdout,74) >*/
	feq_gen_io_d__29.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__29);
	e_wsfe();
/* SOURCE culverta.for:431 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culverta.for:432 */
/*<       endif >*/
    }
/* SOURCE culverta.for:433 */
/*<       if(f.gt.0.0)then >*/
    if (f > (float)0.) {
/*         Positive residual found. */
/* SOURCE culverta.for:435 */
/*<       zhigh=ztail >*/
	zhigh = ztail;
/* SOURCE culverta.for:436 */
/*<       fr=f >*/
	fr = f;
/* SOURCE culverta.for:437 */
/*<       if(zlow.gt.0.0)goto110 >*/
	if (zlow > (float)0.) {
	    goto L110;
	}
/*         Negative residual not yet known.  Continue to search. */
/* SOURCE culverta.for:439 */
/*<       yt=0.95*ytail >*/
	yt = static_cast<double>(ytail) * (float).95;
/* SOURCE culverta.for:440 */
/*<       if(yt.lt.y43min)then >*/
	if (yt < y43min) {
/* SOURCE culverta.for:441 */
/*<       yt=0.5*(ytail+y43min) >*/
	    yt = static_cast<double>((static_cast<double>(ytail) + y43min)) * (float).5;
/* SOURCE culverta.for:442 */
/*<       if((yt-y43min)/y43min.le.1.e-6)then >*/
	    if (static_cast<double>((static_cast<double>(yt) - y43min)) / y43min <= (float)1e-6) {
/* SOURCE culverta.for:443 */
/*<       write(stdout,75)y43min >*/
		feq_gen_io_d__32.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__32);
		do_fio(&feq_gen_c_d_1, (char *)&y43min, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE culverta.for:444 */
/*<       if(abs(f).le.0.005)then >*/
		if (dabs(f) <= (float).005) {
/* SOURCE culverta.for:445 */
/*<       write(stdout,76)f >*/
		    feq_gen_io_d__33.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__33);
		    do_fio(&feq_gen_c_d_1, (char *)&f, (ftnlen)sizeof(real));
		    e_wsfe();
/*               Values have been set in RTY7RF */
/* SOURCE culverta.for:447 */
/*<       goto120 >*/
		    goto L120;
/* SOURCE culverta.for:448 */
/*<       endif >*/
		}
/* SOURCE culverta.for:449 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culverta.for:450 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:451 */
/*<       endif >*/
	}
/* SOURCE culverta.for:452 */
/*<       ytail=yt >*/
	ytail = yt;
/* SOURCE culverta.for:453 */
/*<       goto100 >*/
	goto L100;
/* SOURCE culverta.for:454 */
/*<       else >*/
    } else {
/*         Negative residual found. */
/* SOURCE culverta.for:456 */
/*<       zlow=ztail >*/
	zlow = ztail;
/* SOURCE culverta.for:457 */
/*<       fl=f >*/
	fl = f;
/* SOURCE culverta.for:458 */
/*<       if(zhigh.gt.0.0)goto110 >*/
	if (zhigh > (float)0.) {
	    goto L110;
	}
/*         Positive residual not yet known.  Continue to search. */
/* SOURCE culverta.for:460 */
/*<       yt=1.1*ytail >*/
	yt = static_cast<double>(ytail) * (float)1.1;
/* SOURCE culverta.for:461 */
/*<       zt=yt+zb43 >*/
	zt = static_cast<double>(yt) + x43com_1.zb43;
/* SOURCE culverta.for:462 */
/*<       if(zt.ge.z1t)then >*/
	if (zt >= rty7c_1.z1t) {
/* SOURCE culverta.for:463 */
/*<       zt=0.5*(ztail+z1t) >*/
	    zt = static_cast<double>((static_cast<double>(ztail) + rty7c_1.z1t)) * (float).5;
/* SOURCE culverta.for:464 */
/*<       if(z1t-zt.le.0.0)then >*/
	    if (static_cast<double>(rty7c_1.z1t) - zt <= (float)0.) {
/* SOURCE culverta.for:465 */
/*<        >*/
		feq_gen_io_d__36.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__36);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FRFT7: Section 1 elevation reached"), (
			ftnlen)35);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" seeking a positive residual."), (ftnlen)
			29);
		e_wsle();
/* SOURCE culverta.for:467 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culverta.for:468 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:469 */
/*<       endif >*/
	}
/* SOURCE culverta.for:470 */
/*<       ztail=zt >*/
	ztail = zt;
/* SOURCE culverta.for:471 */
/*<       ytail=zt-zb43 >*/
	ytail = static_cast<double>(zt) - x43com_1.zb43;
/* SOURCE culverta.for:472 */
/*<       goto100 >*/
	goto L100;
/* SOURCE culverta.for:473 */
/*<       endif >*/
    }
/* SOURCE culverta.for:474 */
/*<   110 continue >*/
L110:
/*      WRITE(STDOUT,*) ' FRFT7 BEFORE RGF: ZLOW=',ZLOW,' ZHIGH=',ZHIGH */
/*      WRITE(STDOUT,*) ' FL=',FL,' FR=',FR */
/* SOURCE culverta.for:479 */
/*<       callrgf(1.e-6,epsf,rty7rf,zlow,zhigh,fl,fr,z43,flag) >*/
    rgf_(&c_b41, &epscom_1.epsf, rty7rf_, &zlow, &zhigh, &fl, &fr, &
	    x43com_1.z43, &feq_gen_flag_d_);
/* SOURCE culverta.for:483 */
/*<       if(flag.eq.1)then >*/
    if (feq_gen_flag_d_ == 1) {
/* SOURCE culverta.for:484 */
/*<       write(stdout,50) >*/
	feq_gen_io_d__38.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__38);
	e_wsfe();
/* SOURCE culverta.for:485 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culverta.for:486 */
/*<       elseif(flag.eq.2)then >*/
    } else if (feq_gen_flag_d_ == 2) {
/* SOURCE culverta.for:487 */
/*<       write(stdout,60) >*/
	feq_gen_io_d__39.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__39);
	e_wsfe();
/* SOURCE culverta.for:488 */
/*<       write(stdout,62)zlow,zhigh,fl >*/
	feq_gen_io_d__40.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__40);
	do_fio(&feq_gen_c_d_1, (char *)&zlow, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&zhigh, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&fl, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culverta.for:489 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culverta.for:490 */
/*<       elseif(flag.eq.3)then >*/
    } else if (feq_gen_flag_d_ == 3) {
/* SOURCE culverta.for:491 */
/*<       write(stdout,70) >*/
	feq_gen_io_d__41.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__41);
	e_wsfe();
/* SOURCE culverta.for:492 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culverta.for:493 */
/*<       endif >*/
    }
/* SOURCE culverta.for:495 */
/*<   120 continue >*/
L120:
/* SOURCE culverta.for:496 */
/*<       qclv=q3 >*/
    *qclv = xs3com_1.q3;
/* SOURCE culverta.for:497 */
/*<       q2=q3 >*/
    xs2com_1.q2 = xs3com_1.q3;
/* SOURCE culverta.for:498 */
/*<       q1=q4 >*/
    xs1com_1.q1 = xs4com_1.q4;
/* SOURCE culverta.for:499 */
/*<       if(t7flag.eq.1)then >*/
    if (rty7c_1.t7flag == 1) {
/* SOURCE culverta.for:500 */
/*<       fdrop=z1t-z4 >*/
	*fdrop = static_cast<double>(rty7c_1.z1t) - xs4com_1.z4;
/* SOURCE culverta.for:501 */
/*<       z4true=z4 >*/
	*z4true = xs4com_1.z4;
/*        Q3FREE = Q3 */
/*        Y3FREE = Y3 */
/*        Y2FREE = Y2 */
/*        WRITE(STDOUT,*) ' FRFT7: Y4=',Y4,' QCLV=',QCLV,' FDROP=',FDROP */
/*        WRITE(STDOUT,*) ' TYPE=',TYPE */
/*        WRITE(STDOUT,*) ' Q1=',Q1,' Q2=',Q2,' Q3=',Q3,' Q4=',Q4 */
/* SOURCE culverta.for:508 */
/*<       endif >*/
    }
/* SOURCE culverta.for:510 */
/*<       z3p=z43 >*/
    xs3com_1.z3p = x43com_1.z43;
/* SOURCE culverta.for:511 */
/*<       y3p=z3p-zb3 >*/
    xs3com_1.y3p = static_cast<double>(xs3com_1.z3p) - xs3com_1.zb3;
/* SOURCE culverta.for:512 */
/*<       z43old=z43 >*/
    x43com_1.z43old = x43com_1.z43;
/* SOURCE culverta.for:513 */
/*<       q43old=q3 >*/
    x43com_1.q43old = xs3com_1.q3;
/* SOURCE culverta.for:515 */
/*<       return >*/
    return 0;
/* SOURCE culverta.for:516 */
/*<       end >*/
} /* frft7_ */




/* SOURCE culverta.for:520 */
/*<        >*/
/* Subroutine */ int qvstw_(integer *stdout, real *z1true, integer *iu, 
	integer *id, integer *nfrac, real *power, real *zsbrdf, char *culcls, 
	real *ab, real *alp1t, real *k1true, real *hdatum, real *zdatum, 
	integer *frtype, integer *eflag, integer *next, integer *q3vsrd, 
	integer *y3vstw, integer *y2vsd, ftnlen culcls_len)
{
    /* Format strings */
    static char fmt_76[] = "(/,\002 Flows for water levels at section 43.\
\002,/,\002    Road flow submergence at section 43.\002,//,\002 Upstream hea\
d=\002,f9.4,\002 Elevation=\002,f10.4,/,/,1x,\002 Head at Depth at Head at D\
epth at Drop    Flow Flow   \002,\002 Flow   \002,/,1x,\002 section section \
 section section  section type through\002,\002 over   \002,/,1x,\002   2   \
    2       3 & 43    3     1 to 43      barrel \002,\002 roadway \002,/,1x\
,\002 ------- -------- ------- -------- ------- ----  ------\002,\002 -------\
\002)";
    static char fmt_77[] = "(1x,f8.3,f9.3,f8.3,f9.3,f8.4,i5,2a8)";
    static char fmt_78[] = "(1x,\002----------------------------------------\
---------------\002,\002---------\002,/,1x,\002  Notes: Barrel flows full at\
 section 3 when depth\002,\002 there=\002,f8.3,/,1x,\002         Barrel flow\
s full at section 2 when depth\002,\002 there=>\002,f8.3)";
    static char fmt_80[] = "(/,\002 Fit of flow through barrel versus square\
 root of drop\002,\002 is a piecewise\002,/,\002 cubic Hermite polynomial.  \
Cubic spline\002,\002 fit was not variation\002,/,\002 limited at the follow\
ing drop \002,\002values:\002)";
    static char fmt_82[] = "(5x,f10.4)";
    static char fmt_84[] = "(/,\002 Fit of flow through barrel versus square\
 root of drop\002,\002 is a \002/,\002 variation-limited cubic spline.\002)";
    static char fmt_86[] = "(/,\002 *WRN:567* QVSTW: Type 1 Profile problems\
 not \002,\002resolved by flow adjustment.\002,/,11x,\002 Making tailwate\
r\002,\002 adjustments.\002)";
    static char fmt_88[] = "(/,\002 *WRN:568* QVSTW: Making tailwater adjust\
ment. Old\002,\002 tailwater level=\002,f8.3)";
    static char fmt_90[] = "(/,\002 *BUG:XXX* Too many tailwater-level adjus\
tments.\002)";
    static char fmt_92[] = "(/,\002 *ERR:695* Drop from section 1 to section\
 43=\002,f7.3,\002 invalid.\002,/,11x,\002Drop must be > 0.\002)";
    static char fmt_94[] = "(/,\002 *WRN:569* Subatmospheric head=\002,f5.1\
,\002 at section 2\002,\002 may cause cavitation\002,/,\002  and loss of per\
formance.\002)";
    static char fmt_96[] = "(/,\002 *WRN:570* Subatmospheric head=\002,f5.1\
,\002 at section 2\002,\002 is impossible.\002,/,\002  Culvert will NOT perf\
orm as computed.\002)";
    static char fmt_98[] = "(/,\002 BUG:XXX* Drop <= 0.0.  Cannot continue\
.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3, feq_gen_r_d_4, feq_gen_r_d_5, feq_gen_r_d_6, feq_gen_r_d_7;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double pow_dd(doublereal *, doublereal *);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();

    /* Local variables */
    real f;
    integer feq_gen_i_d_, j;
    real f1[150], f2[150], fl, fr, dz, fac, ddn, dir, dup;
    integer knt;
    extern /* Subroutine */ int feq_gen_var_decimal_d_(real *, char *, ftnlen), rgf3_(
	    real *, real *, FeqCallback3, real *, real *, real *, real *, real *, 
	    integer *);
    integer knt2, knt3, feq_gen_flag_d_;
    real fold, qlow, qold;
    doublereal drop[150], y2vec[150];
    real y3vec[150];
    extern /* Subroutine */ int put1d_(integer *, integer *, integer *, 
	    integer *, real *, real *, real *, integer *, integer *);
    integer iflag;
    real argvec[150], qculv, qhigh, y2pmin, ztail, ztvec[150];
    doublereal mclvt[150], qclvt[150], slope, sqrtdp[150], twvec[150];
    char cqclv[8], cqroad[8], adjloc[1*150];
    extern doublereal rqvstw_(real *);
    extern /* Subroutine */ int fulbar_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *), sbfebc_(integer *, real *, real *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, char *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, ftnlen), vlchpp_(integer *, 
	    integer *, doublereal *, doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, doublereal *, char *, ftnlen), xlkt22_(
	    integer *, real *, real *, real *, real *, real *, real *, real *,
	     real *, real *, real *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__44 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__47 = { 0, 0, 0, fmt_77, 0 };
    static cilist feq_gen_io_d__57 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__69 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__71 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__72 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__73 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__74 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__75 = { 0, 0, 0, fmt_90, 0 };
    static cilist feq_gen_io_d__76 = { 0, 0, 0, fmt_88, 0 };
    static cilist feq_gen_io_d__78 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__80 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__82 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__85 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__86 = { 0, 0, 0, fmt_77, 0 };
    static cilist feq_gen_io_d__87 = { 0, 0, 0, fmt_98, 0 };
    static cilist feq_gen_io_d__88 = { 0, 0, 0, fmt_77, 0 };
    static cilist feq_gen_io_d__89 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__90 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__91 = { 0, 0, 0, fmt_96, 0 };
    static cilist feq_gen_io_d__96 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__97 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__98 = { 0, 0, 0, fmt_84, 0 };


/*     + + + PURPOSE + + + */
/*     Compute the flow for various tailwater elevations, that is, */
/*     at section 43, for a given upstream head. */
/* SOURCE culverta.for:531 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culverta.for:534 */
/*<       integereflag,frtype,id,iu,next,nfrac,q3vsrd,stdout,y3vstw,y2vsd >*/
/* SOURCE culverta.for:536 */
/*<       realab,alp1t,hdatum,k1true,power,z1true,zdatum,zsbrdf >*/
/* SOURCE culverta.for:537 */
/*<       characterculcls*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     Z1TRUE - known elevation at section 1 */
/*     IU     - Index for upstream node for the culvert barrel */
/*     ID     - Index for the downstream node for the culvert barrel */
/*     NFRAC  - Number of fractions for defining partial free drop */
/*     POWER  - power to use to define break points for function fit */
/*     ZSBRDF - water surface elevation at section 43 that begins */
/*              submergence of flow over the roadway */
/*     CULCLS - Class for culvert shape, BOX, PIPE, .. */
/*     AB     - true area at section 1 used to adjust CD for flow */
/*              types 1, 2, and 3 */
/*     ALP1T  - value of energy flux correction coefficient at section 1 */
/*     K1TRUE - conveyance at section 1 for the known elevation there */
/*     HDATUM - Datum for measuring head */
/*     ZDATUM - datum for local elevation */
/*     FRTYPE - free flow type */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     NEXT   - pointer into scratch portion of ITAB/FTAB */
/*     Q3VSRD - address of function table giving flow at section 3 versus */
/*              tailwater at section 43 for a given head at section 1 */
/*     Y3VSTW - address of function table giving depth at section 3 */
/*              versus the tailwater at section 43 */
/*     Y2VSD - address of function table giving depth at section 2 */
/*              versus the tailwater at section 43 */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culverta.for:566 */
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
/* INCLUDE culverta.for:567 */
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
/* INCLUDE culverta.for:568 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culverta.for:569 */
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
/* INCLUDE culverta.for:570 */
/* SOURCE x43com.cmn:2 */
/*<        >*/
/* SOURCE x43com.cmn:6 */
/*<       integeradrs43,stat43 >*/
/* SOURCE x43com.cmn:8 */
/*<        >*/
/* INCLUDE culverta.for:571 */
/*     COMMOM BLOCK FOR THE DESCRIPTION OF THE FLOW OVER AN EMBANKMENT */
/* SOURCE embcom.cmn:3 */
/*<       character*8surf(pmxoff) >*/
/* SOURCE embcom.cmn:5 */
/*<       integernoff,minloc,plcwtb,glcwtb,phcwtb,ghcwtb,psubtb,gsubtb >*/
/* SOURCE embcom.cmn:8 */
/*<       realmincrs,rmffac >*/
/* SOURCE embcom.cmn:10 */
/*<        >*/
/* SOURCE embcom.cmn:20 */
/*<       common/embcmc/surf >*/
/* SOURCE embcom.cmn:22 */
/*<        >*/
/* INCLUDE culverta.for:572 */
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
/* INCLUDE culverta.for:573 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE culverta.for:574 */
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
/* INCLUDE culverta.for:575 */
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
/* INCLUDE culverta.for:576 */
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
/* INCLUDE culverta.for:577 */
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
/* INCLUDE culverta.for:578 */
/*     Common block for key values describing the nature of weir */
/*     flow. */
/* SOURCE embwrq.cmn:4 */
/*<       integerhlflag,hpflag >*/
/* SOURCE embwrq.cmn:6 */
/*<       realhlcrit,hlmax >*/
/* SOURCE embwrq.cmn:8 */
/*<       common/embq/hlflag,hpflag,hlcrit,hlmax >*/
/* SOURCE embwrq.cmn:10 */
/*<       save/embq/ >*/
/*     HLCRIT  Ratio of piezometric head to crest breadth at boundary */
/*             between low head and high head flow in the USGS */
/*             embankment-shaped weir methodology. */
/*     HLMAX   Maximum value of piezometric head to crest breadth ratio */
/*             above which a warning message is issued. */
/*     HLFLAG  Warning message suppression flag for warnings about the */
/*             piezometric head to crest breadth ratio becoming greater */
/*             than HLMAX */
/*     HPFLAG  Warning message suppression flag for invalid weir flow */
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE culverta.for:581 */
/*<       integermaxn >*/
/* SOURCE culverta.for:582 */
/*<       parameter(maxn=150) >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culverta.for:585 */
/*<       integerflag,i,iflag,j,knt,knt2,knt3 >*/
/* SOURCE culverta.for:586 */
/*<        >*/
/* SOURCE culverta.for:589 */
/*<        >*/
/* SOURCE culverta.for:591 */
/*<       charactercqclv*8,cqroad*8,adjloc(maxn)*1 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culverta.for:594 */
/*<       intrinsicabs,float,min,sqrt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culverta.for:597 */
/*<       realrqvstw >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culverta.for:600 */
/*<       externalfulbar,put1d,rgf3,rqvstw,sbfebc,vlchpp,xlkt22,var_decimal >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culverta.for:604 */
/*<    76  >*/
/* SOURCE culverta.for:615 */
/*<    77 format(1x,f8.3,f9.3,f8.3,f9.3,f8.4,i5,2a8) >*/
/* SOURCE culverta.for:616 */
/*<    78  >*/
/* SOURCE culverta.for:623 */
/*<    80  >*/
/* SOURCE culverta.for:627 */
/*<    82 format(5x,f10.4) >*/
/* SOURCE culverta.for:628 */
/*<    84  >*/
/* SOURCE culverta.for:630 */
/*<    86  >*/
/* SOURCE culverta.for:633 */
/*<    88  >*/
/* SOURCE culverta.for:635 */
/*<    90 format(/,' *BUG:XXX* Too many tailwater-level adjustments.') >*/
/* SOURCE culverta.for:636 */
/*<    92  >*/
/* SOURCE culverta.for:638 */
/*<    94  >*/
/* SOURCE culverta.for:640 */
/*<    96  >*/
/* SOURCE culverta.for:642 */
/*<    98 format(/,' BUG:XXX* Drop <= 0.0.  Cannot continue.') >*/
/* *********************************************************************** */
/*      PVEC(1) = 0.D0 */
/*      PVEC(2) = 0.25D0 */
/*      PVEC(3) = 0.5D0 */
/*      PVEC(4) = 0.75D0 */
/*      PVEC(5) = 1.D0 */
/* SOURCE culverta.for:649 */
/*<       y2pmin=1.e30 >*/
/* L76: */
/* L77: */
/* L78: */
/* L80: */
/* L82: */
/* L84: */
/* L86: */
/* L88: */
/* L90: */
/* L92: */
/* L94: */
/* L96: */
/* L98: */
    y2pmin = (float)1e30;
/* SOURCE culverta.for:650 */
/*<       ddn=dvec(id) >*/
    ddn = culcom_1.dvec[*id - 1];
/* SOURCE culverta.for:651 */
/*<       fqtype=frtype >*/
    rqvtw_1.fqtype = *frtype;
/* SOURCE culverta.for:653 */
/*<       write(stdout,76)z1true-hdatum,z1true+zdatum >*/
    feq_gen_io_d__44.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__44);
    feq_gen_r_d_1 = static_cast<double>(*z1true) - *hdatum;
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
    feq_gen_r_d_2 = static_cast<double>(*z1true) + *zdatum;
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE culverta.for:655 */
/*<       callvar_decimal(q3,cqclv) >*/
    feq_gen_var_decimal_d_(&xs3com_1.q3, cqclv, (ftnlen)8);
/* SOURCE culverta.for:657 */
/*<       callvar_decimal(wfrd,cqroad) >*/
    feq_gen_var_decimal_d_(&rdfcom_1.wfrd, cqroad, (ftnlen)8);
/* SOURCE culverta.for:659 */
/*<        >*/
    feq_gen_io_d__47.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__47);
    feq_gen_r_d_1 = static_cast<double>(xs2com_1.z2) - *hdatum;
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&xs2com_1.y2, (ftnlen)sizeof(real));
    feq_gen_r_d_2 = static_cast<double>(x43com_1.z43) - *hdatum;
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
    feq_gen_r_d_3 = dmin(xs3com_1.y3,ddn);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_3, (ftnlen)sizeof(real));
    feq_gen_r_d_4 = static_cast<double>(*z1true) - x43com_1.z43;
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_4, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&(*frtype), (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, cqclv, (ftnlen)8);
    do_fio(&feq_gen_c_d_1, cqroad, (ftnlen)8);
    e_wsfe();
/*      WRITE(STDOUT,*) ' ENTRY TO QVSTW: NFRAC=',NFRAC,' POWER=',POWER */
/*      WRITE(STDOUT,*) ' Z1TRUE=',Z1TRUE */
/*      WRITE(STDOUT,*) ' Z43OLD=',Z43OLD,' Q43OLD=',Q43OLD */
/* SOURCE culverta.for:665 */
/*<       dup=dvec(iu) >*/
    dup = culcom_1.dvec[*iu - 1];
/* SOURCE culverta.for:666 */
/*<       iup=iu >*/
    rqvtw_1.iup = *iu;
/* SOURCE culverta.for:667 */
/*<       idn=id >*/
    rqvtw_1.idn = *id;
/* SOURCE culverta.for:668 */
/*<       outun=stdout >*/
    rqvtw_1.outun = *stdout;
/* SOURCE culverta.for:669 */
/*<       zsub=zsbrdf >*/
    rqvtw_1.zsub = *zsbrdf;
/* SOURCE culverta.for:670 */
/*<       class=culcls >*/
    s_copy(rqvtc_1.feq_gen_class_d_, culcls, (ftnlen)8, (ftnlen)8);
/* SOURCE culverta.for:671 */
/*<       abase=ab >*/
    rqvtw_1.abase = *ab;
/* SOURCE culverta.for:672 */
/*<       z1t=z1true >*/
    rqvtw_1.z1t = *z1true;
/* SOURCE culverta.for:674 */
/*<       twvec(1)=z43old >*/
    twvec[0] = x43com_1.z43old;
/* SOURCE culverta.for:675 */
/*<       qclvt(1)=q43old >*/
    qclvt[0] = x43com_1.q43old;
/* SOURCE culverta.for:676 */
/*<       y3=z43old-zb3 >*/
    xs3com_1.y3 = static_cast<double>(x43com_1.z43old) - xs3com_1.zb3;
/* SOURCE culverta.for:677 */
/*<       if(y3.gt.ddn)y3=ddn >*/
    if (xs3com_1.y3 > ddn) {
	xs3com_1.y3 = ddn;
    }
/* SOURCE culverta.for:678 */
/*<        >*/
    xlkt22_(&xs3com_1.adrxs3, &xs3com_1.y3, &xs3com_1.a3, &xs3com_1.t3, &
	    xs3com_1.dt3, &xs3com_1.j3, &xs3com_1.k3, &xs3com_1.dk3, &
	    xs3com_1.bet3, &xs3com_1.dbet3, &xs3com_1.alp3, &xs3com_1.dalp3, &
	    xs3com_1.q3c);
/* SOURCE culverta.for:683 */
/*<       y3vec(1)=y3free >*/
    y3vec[0] = xs3com_1.y3free;
/* SOURCE culverta.for:684 */
/*<       y2vec(1)=y2 >*/
    y2vec[0] = xs2com_1.y2;
/*      WRITE(STDOUT,*) 'QVSTW: Y3VEC(1)=',Y3VEC(1) */
/* SOURCE culverta.for:687 */
/*<       drop(1)=z1true-z43old >*/
    drop[0] = static_cast<double>(*z1true) - x43com_1.z43old;
/* SOURCE culverta.for:688 */
/*<       sqrtdp(1)=sqrt(z1true-z43old) >*/
    sqrtdp[0] = feq::culvert_sqrt_drop(*z1true,x43com_1.z43old);
/* SOURCE culverta.for:689 */
/*<       qculv=q43old >*/
    qculv = x43com_1.q43old;
/* SOURCE culverta.for:690 */
/*<       dz=z1true-z43old >*/
    dz = static_cast<double>(*z1true) - x43com_1.z43old;
/* SOURCE culverta.for:691 */
/*<       if(dz.le.0.0)then >*/
    if (dz <= (float)0.) {
/* SOURCE culverta.for:692 */
/*<       write(stdout,92)dz >*/
	feq_gen_io_d__57.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__57);
	do_fio(&feq_gen_c_d_1, (char *)&dz, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culverta.for:693 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culverta.for:694 */
/*<       endif >*/
    }
/* SOURCE culverta.for:695 */
/*<       ztvec(1)=z43old >*/
    ztvec[0] = x43com_1.z43old;
/* SOURCE culverta.for:696 */
/*<       do490i=2,nfrac-1 >*/
    feq_gen_i_d_1 = *nfrac - 1;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culverta.for:697 */
/*<       ztvec(i)=z43old+dz*(1.0-(float(nfrac-i)/(nfrac-1))**power) >*/
	feq_gen_d_d_1 = (doublereal) (static_cast<double>((real) (*nfrac - feq_gen_i_d_)) / (*nfrac - 1));
	feq_gen_d_d_2 = (doublereal) (*power);
	ztvec[feq_gen_i_d_ - 1] = feq::culvert_tailwater_level(
            x43com_1.z43old,*z1true,feq_gen_i_d_,*nfrac,*power);
/* SOURCE culverta.for:699 */
/*<   490 continue >*/
/* L490: */
    }
/* SOURCE culverta.for:700 */
/*<       ztvec(nfrac)=z1true >*/
    ztvec[*nfrac - 1] = *z1true;
/* SOURCE culverta.for:701 */
/*<       do500i=2,nfrac-1 >*/
    feq_gen_i_d_1 = *nfrac - 1;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*       Select the sequence of tail water values so that they are */
/*       more closely spaced as the upstream water level is */
/*       approached.  This puts more values in the region of rapid */
/*       variation of flow. */
/* SOURCE culverta.for:707 */
/*<       ztail=ztvec(i) >*/
	ztail = ztvec[feq_gen_i_d_ - 1];
/* SOURCE culverta.for:708 */
/*<       z3p=ztail >*/
	xs3com_1.z3p = ztail;
/* SOURCE culverta.for:709 */
/*<       y3=z3p-zb3 >*/
	xs3com_1.y3 = static_cast<double>(xs3com_1.z3p) - xs3com_1.zb3;
/* SOURCE culverta.for:710 */
/*<       y3p=y3 >*/
	xs3com_1.y3p = xs3com_1.y3;
/* SOURCE culverta.for:711 */
/*<       if(y3.gt.ddn)y3=ddn >*/
	if (xs3com_1.y3 > ddn) {
	    xs3com_1.y3 = ddn;
	}
/*       Establish the flow over the road if any.  Any submergence is */
/*       included in the final values. */
/* SOURCE culverta.for:715 */
/*<       if(ztail.gt.zsub)then >*/
	if (ztail > rqvtw_1.zsub) {
/* SOURCE culverta.for:716 */
/*<        >*/
	    sbfebc_(&rqvtw_1.outun, z1true, &ztail, &embcom_1.plcwtb, &
		    embcom_1.glcwtb, &embcom_1.phcwtb, &embcom_1.ghcwtb, &
		    embcom_1.psubtb, &embcom_1.gsubtb, &embcom_1.noff, 
		    embcmc_1.surf, &embq_1.hlcrit, embcom_1.xrdfl, 
		    embcom_1.xrdfr, embcom_1.hrdfl, embcom_1.hrdfm, 
		    embcom_1.hrdfr, embcom_1.qrdfl, embcom_1.qrdfm, 
		    embcom_1.qrdfr, embcom_1.tothl, embcom_1.tothm, 
		    embcom_1.tothr, embcom_1.yfl, embcom_1.yfm, embcom_1.yfr, 
		    embcom_1.appl, embcom_1.appm, embcom_1.appr, embcom_1.wl, 
		    embcom_1.wm, embcom_1.wr, embcom_1.aell, embcom_1.aelm, 
		    embcom_1.aelr, &embcom_1.rmffac, &rdfcom_1.wfrd, &
		    rdfcom_1.mfrd, &rdfcom_1.efrd, (ftnlen)8);
/* SOURCE culverta.for:723 */
/*<       else >*/
	} else {
/* SOURCE culverta.for:724 */
/*<       wfrd=wfrdf >*/
	    rdfcom_1.wfrd = rdfcom_1.wfrdf;
/* SOURCE culverta.for:725 */
/*<       mfrd=mfrdf >*/
	    rdfcom_1.mfrd = rdfcom_1.mfrdf;
/* SOURCE culverta.for:726 */
/*<       efrd=efrdf >*/
	    rdfcom_1.efrd = rdfcom_1.efrdf;
/* SOURCE culverta.for:727 */
/*<       endif >*/
	}
/* SOURCE culverta.for:730 */
/*<       if(lstype.eq.4)then >*/
	if (xs2com_1.lstype == 4) {
/*         Full flow with complete downstream submergence. */
/* SOURCE culverta.for:732 */
/*<       cd=c46 >*/
	    cdcom_1.cd = cdcom_1.c46;
/* SOURCE culverta.for:733 */
/*<       avh=a2full >*/
	    cdcom_1.avh = xs2com_1.a2full;
/* SOURCE culverta.for:734 */
/*<        >*/
	    fulbar_(stdout, ab, alp1t, k1true, z1true, &xs2com_1.a2full, &
		    xs2com_1.k2full, &xs3com_1.a3full, &cdcom_1.cd, &
		    cdcom_1.avh, &xs3com_1.z3p, &qculv, &xs2com_1.z2);
/* SOURCE culverta.for:738 */
/*<       y2=dup >*/
	    xs2com_1.y2 = dup;
/* SOURCE culverta.for:739 */
/*<       y3=ddn >*/
	    xs3com_1.y3 = ddn;
/* SOURCE culverta.for:740 */
/*<       y2p=z2-zb2 >*/
	    xs2com_1.y2p = static_cast<double>(xs2com_1.z2) - xs2com_1.zb2;
/* SOURCE culverta.for:741 */
/*<       elseif(lstype.eq.42)then >*/
	} else if (xs2com_1.lstype == 42) {
/*         Full flow but with possible variable CD,  and */
/*         perhaps BETA, and  ALPHA.  AVH is constant. */
/*         BETA and ALPHA are set and used when computing the */
/*         departure reach values.   The tailwater is below the */
/*         culvert soffit but about the piezometric level at the */
/*         culvert exit. */
/*         The free flow computations must create the values */
/*         in the TYPTRN common needed at the free flow end of the */
/*         tailwater range.  Type 42 ends at a tailwater equal to */
/*         the elevation of the exit soffit of the culvert barrel. */
/* SOURCE culverta.for:752 */
/*<       avh=a2full >*/
	    cdcom_1.avh = xs2com_1.a2full;
/* SOURCE culverta.for:754 */
/*<       if(y3p.ge.ddn)then >*/
	    if (xs3com_1.y3p >= ddn) {
/*           Shift to type 4. */
/* SOURCE culverta.for:756 */
/*<       cd=c46 >*/
		cdcom_1.cd = cdcom_1.c46;
/* SOURCE culverta.for:757 */
/*<       lstype=4 >*/
		xs2com_1.lstype = 4;
/* SOURCE culverta.for:758 */
/*<       cqtype=4 >*/
		rqvtw_1.cqtype = 4;
/* SOURCE culverta.for:759 */
/*<       else >*/
	    } else {
/* SOURCE culverta.for:760 */
/*<       if(lftype.eq.6)then >*/
		if (xs2com_1.lftype == 6) {
/* SOURCE culverta.for:761 */
/*<       cd=c46 >*/
		    cdcom_1.cd = cdcom_1.c46;
/* SOURCE culverta.for:762 */
/*<       else >*/
		} else {
/* SOURCE culverta.for:763 */
/*<       cd=cdf+(y3p-y3pf)*(c46-cdf)/(ddn-y3pf) >*/
		    cdcom_1.cd = static_cast<double>(typtrn_1.cdf) + static_cast<double>(static_cast<double>((static_cast<double>(xs3com_1.y3p) - typtrn_1.y3pf))
			     * (static_cast<double>(cdcom_1.c46) - typtrn_1.cdf)) / (static_cast<double>(ddn) - 
			    typtrn_1.y3pf);
/* SOURCE culverta.for:764 */
/*<       endif >*/
		}
/* SOURCE culverta.for:765 */
/*<       lstype=42 >*/
		xs2com_1.lstype = 42;
/* SOURCE culverta.for:766 */
/*<       cqtype=42 >*/
		rqvtw_1.cqtype = 42;
/* SOURCE culverta.for:767 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:768 */
/*<        >*/
	    fulbar_(stdout, ab, alp1t, k1true, z1true, &xs2com_1.a2full, &
		    xs2com_1.k2full, &xs3com_1.a3full, &cdcom_1.cd, &
		    cdcom_1.avh, &xs3com_1.z3p, &qculv, &xs2com_1.z2);
/* SOURCE culverta.for:772 */
/*<       y2=dup >*/
	    xs2com_1.y2 = dup;
/* SOURCE culverta.for:773 */
/*<       y3=ddn >*/
	    xs3com_1.y3 = ddn;
/* SOURCE culverta.for:774 */
/*<       y2p=z2-zb2 >*/
	    xs2com_1.y2p = static_cast<double>(xs2com_1.z2) - xs2com_1.zb2;
/* SOURCE culverta.for:775 */
/*<       elseif(lftype.eq.6)then >*/
	} else if (xs2com_1.lftype == 6) {
/*         Full flow with perhaps partial submergence but CD and */
/*         AVH are constant. */
/* SOURCE culverta.for:778 */
/*<       cd=c46 >*/
	    cdcom_1.cd = cdcom_1.c46;
/* SOURCE culverta.for:779 */
/*<       avh=a2full >*/
	    cdcom_1.avh = xs2com_1.a2full;
/* SOURCE culverta.for:780 */
/*<       if(y3p.ge.ddn)then >*/
	    if (xs3com_1.y3p >= ddn) {
/* SOURCE culverta.for:781 */
/*<       lstype=4 >*/
		xs2com_1.lstype = 4;
/* SOURCE culverta.for:782 */
/*<       cqtype=4 >*/
		rqvtw_1.cqtype = 4;
/* SOURCE culverta.for:783 */
/*<       else >*/
	    } else {
/* SOURCE culverta.for:784 */
/*<       lstype=42 >*/
		xs2com_1.lstype = 42;
/* SOURCE culverta.for:785 */
/*<       cqtype=42 >*/
		rqvtw_1.cqtype = 42;
/* SOURCE culverta.for:786 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:787 */
/*<        >*/
	    fulbar_(stdout, ab, alp1t, k1true, z1true, &xs2com_1.a2full, &
		    xs2com_1.k2full, &xs3com_1.a3full, &cdcom_1.cd, &
		    cdcom_1.avh, &xs3com_1.z3p, &qculv, &xs2com_1.z2);
/* SOURCE culverta.for:791 */
/*<       y2=dup >*/
	    xs2com_1.y2 = dup;
/* SOURCE culverta.for:792 */
/*<       y3=ddn >*/
	    xs3com_1.y3 = ddn;
/* SOURCE culverta.for:793 */
/*<       y2p=z2-zb2 >*/
	    xs2com_1.y2p = static_cast<double>(xs2com_1.z2) - xs2com_1.zb2;
/* SOURCE culverta.for:794 */
/*<       elseif(lftype.eq.62)then >*/
	} else if (xs2com_1.lftype == 62) {
/*         Full flow with variable values of CD, and perhaps BETA */
/*         and ALPHA.  AVH is constant.   See section for LSTYPE=42 */
/*         above. */
/* SOURCE culverta.for:798 */
/*<       avh=a2full >*/
	    cdcom_1.avh = xs2com_1.a2full;
/* SOURCE culverta.for:799 */
/*<       if(y3p.lt.ddn)then >*/
	    if (xs3com_1.y3p < ddn) {
/* SOURCE culverta.for:800 */
/*<       cd=cdf+(y3p-y3pf)*(c46-cdf)/(ddn-y3pf) >*/
		cdcom_1.cd = static_cast<double>(typtrn_1.cdf) + static_cast<double>(static_cast<double>((static_cast<double>(xs3com_1.y3p) - typtrn_1.y3pf)) * (
			static_cast<double>(cdcom_1.c46) - typtrn_1.cdf)) / (static_cast<double>(ddn) - typtrn_1.y3pf);
/* SOURCE culverta.for:801 */
/*<       lstype=42 >*/
		xs2com_1.lstype = 42;
/* SOURCE culverta.for:802 */
/*<       cqtype=42 >*/
		rqvtw_1.cqtype = 42;
/* SOURCE culverta.for:803 */
/*<       else >*/
	    } else {
/* SOURCE culverta.for:804 */
/*<       cd=c46 >*/
		cdcom_1.cd = cdcom_1.c46;
/* SOURCE culverta.for:805 */
/*<       lstype=4 >*/
		xs2com_1.lstype = 4;
/* SOURCE culverta.for:806 */
/*<       cqtype=4 >*/
		rqvtw_1.cqtype = 4;
/* SOURCE culverta.for:807 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:808 */
/*<        >*/
	    fulbar_(stdout, ab, alp1t, k1true, z1true, &xs2com_1.a2full, &
		    xs2com_1.k2full, &xs3com_1.a3full, &cdcom_1.cd, &
		    cdcom_1.avh, &xs3com_1.z3p, &qculv, &xs2com_1.z2);
/* SOURCE culverta.for:812 */
/*<       y2=dup >*/
	    xs2com_1.y2 = dup;
/* SOURCE culverta.for:813 */
/*<       y3=ddn >*/
	    xs3com_1.y3 = ddn;
/* SOURCE culverta.for:814 */
/*<       y2p=z2-zb2 >*/
	    xs2com_1.y2p = static_cast<double>(xs2com_1.z2) - xs2com_1.zb2;
/* SOURCE culverta.for:815 */
/*<       elseif(lftype.eq.61.and.y3p.ge.ddn)then >*/
	} else if (xs2com_1.lftype == 61 && xs3com_1.y3p >= ddn) {
/*         Exit is flowing full. */
/* SOURCE culverta.for:817 */
/*<       cd=c46 >*/
	    cdcom_1.cd = cdcom_1.c46;
/* SOURCE culverta.for:818 */
/*<       avh=a2full >*/
	    cdcom_1.avh = xs2com_1.a2full;
/* SOURCE culverta.for:819 */
/*<       lstype=4 >*/
	    xs2com_1.lstype = 4;
/* SOURCE culverta.for:820 */
/*<       cqtype=4 >*/
	    rqvtw_1.cqtype = 4;
/* SOURCE culverta.for:821 */
/*<        >*/
	    fulbar_(stdout, ab, alp1t, k1true, z1true, &xs2com_1.a2full, &
		    xs2com_1.k2full, &xs3com_1.a3full, &cdcom_1.cd, &
		    cdcom_1.avh, &xs3com_1.z3p, &qculv, &xs2com_1.z2);
/* SOURCE culverta.for:825 */
/*<       y2=dup >*/
	    xs2com_1.y2 = dup;
/* SOURCE culverta.for:826 */
/*<       y3=ddn >*/
	    xs3com_1.y3 = ddn;
/* SOURCE culverta.for:827 */
/*<       y2p=z2-zb2 >*/
	    xs2com_1.y2p = static_cast<double>(xs2com_1.z2) - xs2com_1.zb2;
/* SOURCE culverta.for:828 */
/*<       elseif(lftype.eq.5.or.lftype.eq.51.or.lftype.eq.52)then >*/
	} else if (xs2com_1.lftype == 5 || xs2com_1.lftype == 51 || 
		xs2com_1.lftype == 52) {
/*         Transition values computed in FRFT5.  Transition */
/*         to type 4 from type 42. */
/* SOURCE culverta.for:831 */
/*<       avh=a2full >*/
	    cdcom_1.avh = xs2com_1.a2full;
/* SOURCE culverta.for:832 */
/*<       if(y3p.lt.ddn)then >*/
	    if (xs3com_1.y3p < ddn) {
/*           Transition region for Cd. */
/* SOURCE culverta.for:834 */
/*<       cd=cdf+(y3p-y3pf)*(c46-cdf)/(ddn-y3pf) >*/
		cdcom_1.cd = static_cast<double>(typtrn_1.cdf) + static_cast<double>(static_cast<double>((static_cast<double>(xs3com_1.y3p) - typtrn_1.y3pf)) * (
			static_cast<double>(cdcom_1.c46) - typtrn_1.cdf)) / (static_cast<double>(ddn) - typtrn_1.y3pf);
/* SOURCE culverta.for:835 */
/*<       lstype=42 >*/
		xs2com_1.lstype = 42;
/* SOURCE culverta.for:836 */
/*<       cqtype=42 >*/
		rqvtw_1.cqtype = 42;
/* SOURCE culverta.for:837 */
/*<       else >*/
	    } else {
/*           Pure type 4. */
/* SOURCE culverta.for:839 */
/*<       cd=c46 >*/
		cdcom_1.cd = cdcom_1.c46;
/* SOURCE culverta.for:840 */
/*<       lstype=4 >*/
		xs2com_1.lstype = 4;
/* SOURCE culverta.for:841 */
/*<       cqtype=4 >*/
		rqvtw_1.cqtype = 4;
/* SOURCE culverta.for:842 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:843 */
/*<        >*/
	    fulbar_(stdout, ab, alp1t, k1true, z1true, &xs2com_1.a2full, &
		    xs2com_1.k2full, &xs3com_1.a3full, &cdcom_1.cd, &
		    cdcom_1.avh, &xs3com_1.z3p, &qculv, &xs2com_1.z2);
/* SOURCE culverta.for:847 */
/*<       y2=dup >*/
	    xs2com_1.y2 = dup;
/* SOURCE culverta.for:848 */
/*<       y3=ddn >*/
	    xs3com_1.y3 = ddn;
/* SOURCE culverta.for:849 */
/*<       y2p=z2-zb2 >*/
	    xs2com_1.y2p = static_cast<double>(xs2com_1.z2) - xs2com_1.zb2;
/* SOURCE culverta.for:850 */
/*<       else >*/
	} else {
/*         Do all cases that have part full flow here. */
/* SOURCE culverta.for:852 */
/*<       knt3=0 >*/
	    knt3 = 0;
/* SOURCE culverta.for:854 */
/*<   499 continue >*/
L499:
/*         Set the fixed tailwater into the common block for the */
/*         residual function, RQVSTW. */
/* SOURCE culverta.for:857 */
/*<       z43fix=ztail >*/
	    rqvtw_1.z43fix = ztail;
/* SOURCE culverta.for:858 */
/*<       y3p=ztail-zb3 >*/
	    xs3com_1.y3p = static_cast<double>(ztail) - xs3com_1.zb3;
/*         Now find the flow in the culvert for the given upstream level, */
/*         Z1T and the given tailwater, ZTAIL.  The flow in the culvert */
/*         should always be in the submerged state.  Also at this */
/*         point it should be part full at least part of the way. */
/* SOURCE culverta.for:864 */
/*<       knt=0 >*/
	    knt = 0;
/* SOURCE culverta.for:865 */
/*<       knt2=0 >*/
	    knt2 = 0;
/*          WRITE(OUTUN,*) ' STARTING SEARCH WITH QCULV=',QCULV */
/*         Search for an interval containing a root.  Set the argument */
/*         values at the limits of the root-containing interval to zero */
/*         to serve as flags for the finding of the residuals. */
/* SOURCE culverta.for:871 */
/*<       qhigh=0.0 >*/
	    qhigh = (float)0.;
/* SOURCE culverta.for:872 */
/*<       qlow=0.0 >*/
	    qlow = (float)0.;
/* SOURCE culverta.for:873 */
/*<       fac=1.05 >*/
	    fac = (float)1.05;
/* SOURCE culverta.for:874 */
/*<       qold=0.0 >*/
	    qold = (float)0.;
/* SOURCE culverta.for:875 */
/*<       fold=ztail-z1t >*/
	    fold = static_cast<double>(ztail) - rqvtw_1.z1t;
/* SOURCE culverta.for:876 */
/*<   100 continue >*/
L100:
/* SOURCE culverta.for:877 */
/*<       knt2=knt2+1 >*/
	    ++knt2;
/* SOURCE culverta.for:878 */
/*<       if(knt2.gt.100)then >*/
	    if (knt2 > 100) {
/* SOURCE culverta.for:879 */
/*<       write(outun,*)' QVSTW: More than 100 tries for root.' >*/
		feq_gen_io_d__69.ciunit = rqvtw_1.outun;
		s_wsle(&feq_gen_io_d__69);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" QVSTW: More than 100 tries for root."), 
			(ftnlen)37);
		e_wsle();
/* SOURCE culverta.for:880 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culverta.for:881 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:882 */
/*<       f=rqvstw(qculv) >*/
	    f = rqvstw_(&qculv);
/*            WRITE(OUTUN,*) ' KNT=',KNT,' KNT2=',KNT2,' SBFLAG=',SBFLAG */
/*            WRITE(OUTUN,*) ' QVSTW: QCULV=',QCULV,' F=',F,' FOLD=',FOLD, */
/*     A                    ' QOLD=',QOLD */
/* SOURCE culverta.for:887 */
/*<       if(knt.gt.6.and.sbflag.eq.-1)then >*/
	    if (knt > 6 && rqvtw_1.sbflag == -1) {
/* SOURCE culverta.for:888 */
/*<       sbflag=-2 >*/
		rqvtw_1.sbflag = -2;
/* SOURCE culverta.for:889 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:890 */
/*<       if(sbflag.eq.-1.and.lftype.ne.1.and.lftype.ne.5)then >*/
	    if (rqvtw_1.sbflag == -1 && xs2com_1.lftype != 1 && 
		    xs2com_1.lftype != 5) {
/* SOURCE culverta.for:891 */
/*<       sbflag=-2 >*/
		rqvtw_1.sbflag = -2;
/* SOURCE culverta.for:892 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:893 */
/*<       if(sbflag.eq.-1)then >*/
	    if (rqvtw_1.sbflag == -1) {
/*             Problems computing the steady flow */
/*             profile.  Make adjustment based on the free flow */
/*             type. */
/* SOURCE culverta.for:897 */
/*<       if(lftype.eq.1)then >*/
		if (xs2com_1.lftype == 1) {
/*               Free flow type was 1.  Likely problem with too large */
/*               an increase in flow.  Problem with consistent treatment */
/*               of energy losses with type 1 flow and its submergence. */
/*               Backup from the assumed increase and then increase */
/*               by a smaller amount. */
/* SOURCE culverta.for:903 */
/*<       if(fac.gt.1.0)then >*/
		    if (fac > (float)1.) {
/* SOURCE culverta.for:904 */
/*<       qculv=qculv/fac >*/
			qculv /= fac;
/* SOURCE culverta.for:905 */
/*<       endif >*/
		    }
/* SOURCE culverta.for:906 */
/*<       if(knt.eq.0)then >*/
		    if (knt == 0) {
/* SOURCE culverta.for:907 */
/*<       fac=1.01 >*/
			fac = (float)1.01;
/* SOURCE culverta.for:908 */
/*<       else >*/
		    } else {
/* SOURCE culverta.for:909 */
/*<       fac=1.+0.5*(fac-1.0) >*/
			fac = static_cast<double>(static_cast<double>((static_cast<double>(fac) - (float)1.)) * (float).5) + (float)1.;
/* SOURCE culverta.for:910 */
/*<       endif >*/
		    }
/* SOURCE culverta.for:911 */
/*<       qculv=fac*qculv >*/
		    qculv = static_cast<double>(fac) * qculv;
/* SOURCE culverta.for:912 */
/*<       write(outun,*)' QVSTW: Making Type 1 adjustment.' >*/
		    feq_gen_io_d__71.ciunit = rqvtw_1.outun;
		    s_wsle(&feq_gen_io_d__71);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" QVSTW: Making Type 1 adjustment."), 
			    (ftnlen)33);
		    e_wsle();
/* SOURCE culverta.for:913 */
/*<       write(outun,*)' KNT=',knt,' QCULV=',qculv,' FAC=',fac >*/
		    feq_gen_io_d__72.ciunit = rqvtw_1.outun;
		    s_wsle(&feq_gen_io_d__72);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" KNT="), (ftnlen)5);
		    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&knt, (ftnlen)sizeof(integer)
			    );
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" QCULV="), (ftnlen)7);
		    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&qculv, (ftnlen)sizeof(real))
			    ;
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FAC="), (ftnlen)5);
		    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&fac, (ftnlen)sizeof(real));
		    e_wsle();
/* SOURCE culverta.for:914 */
/*<       knt=knt+1 >*/
		    ++knt;
/* SOURCE culverta.for:915 */
/*<       if(knt.gt.6)then >*/
		    if (knt > 6) {
/* SOURCE culverta.for:916 */
/*<       write(outun,86) >*/
			feq_gen_io_d__73.ciunit = rqvtw_1.outun;
			s_wsfe(&feq_gen_io_d__73);
			e_wsfe();
/* SOURCE culverta.for:917 */
/*<       goto100 >*/
			goto L100;
/* SOURCE culverta.for:918 */
/*<       endif >*/
		    }
/* SOURCE culverta.for:919 */
/*<       else >*/
		} else {
/* SOURCE culverta.for:920 */
/*<       write(outun,*)' QVSTW: PROFILE PROBLEMS. LFTYPE=',lftype >*/
		    feq_gen_io_d__74.ciunit = rqvtw_1.outun;
		    s_wsle(&feq_gen_io_d__74);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" QVSTW: PROFILE PROBLEMS. LFTYPE="), 
			    (ftnlen)33);
		    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&xs2com_1.lftype, (ftnlen)
			    sizeof(integer));
		    e_wsle();
/* SOURCE culverta.for:922 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culverta.for:923 */
/*<       endif >*/
		}
/* SOURCE culverta.for:924 */
/*<       goto100 >*/
		goto L100;
/* SOURCE culverta.for:925 */
/*<       elseif(sbflag.eq.-2)then >*/
	    } else if (rqvtw_1.sbflag == -2) {
/*             Problem in subroutine APPRO or in profile computation. */
/*             Adjust the tailwater  level to find a condition that */
/*             will permit a solution. */
/* SOURCE culverta.for:930 */
/*<       knt3=knt3+1 >*/
		++knt3;
/* SOURCE culverta.for:931 */
/*<       if(knt3.gt.20)then >*/
		if (knt3 > 20) {
/* SOURCE culverta.for:932 */
/*<       write(outun,90) >*/
		    feq_gen_io_d__75.ciunit = rqvtw_1.outun;
		    s_wsfe(&feq_gen_io_d__75);
		    e_wsfe();
/* SOURCE culverta.for:933 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culverta.for:934 */
/*<       endif >*/
		}
/* SOURCE culverta.for:935 */
/*<       write(outun,88)ztail >*/
		feq_gen_io_d__76.ciunit = rqvtw_1.outun;
		s_wsfe(&feq_gen_io_d__76);
		do_fio(&feq_gen_c_d_1, (char *)&ztail, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE culverta.for:936 */
/*<       do102j=i,nfrac-1 >*/
		feq_gen_i_d_2 = *nfrac - 1;
		for (j = feq_gen_i_d_; j <= feq_gen_i_d_2; ++j) {
/*               Move each tailwater to the mid-point of the interval */
/*               above it. */
/* SOURCE culverta.for:939 */
/*<       ztvec(j)=0.5*(ztvec(j)+ztvec(j+1)) >*/
		    ztvec[j - 1] = static_cast<double>((static_cast<double>(ztvec[j - 1]) + ztvec[j])) * (float).5;
/* SOURCE culverta.for:940 */
/*<   102 continue >*/
/* L102: */
		}
/* SOURCE culverta.for:941 */
/*<       ztail=ztvec(i) >*/
		ztail = ztvec[feq_gen_i_d_ - 1];
/* SOURCE culverta.for:942 */
/*<       write(outun,*)' New tailwater level=',ztail >*/
		feq_gen_io_d__78.ciunit = rqvtw_1.outun;
		s_wsle(&feq_gen_io_d__78);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" New tailwater level="), (ftnlen)21);
		do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&ztail, (ftnlen)sizeof(real));
		e_wsle();
/* SOURCE culverta.for:943 */
/*<       goto499 >*/
		goto L499;
/* SOURCE culverta.for:944 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:945 */
/*<       if(abs(f).le.epsabs)then >*/
	    if (dabs(f) <= epscom_1.epsabs) {
/*             Already close enough.  No need to search further. */
/* SOURCE culverta.for:947 */
/*<       else >*/
	    } else {
/*             Check on direction of movement. */
/* SOURCE culverta.for:949 */
/*<       dir=(f-fold)/(qculv-qold) >*/
		dir = static_cast<double>((static_cast<double>(f) - fold)) / (static_cast<double>(qculv) - qold);
/* SOURCE culverta.for:950 */
/*<       if(dir.gt.0.0)then >*/
		if (dir > (float)0.) {
/* SOURCE culverta.for:951 */
/*<       if(fac.lt.1.0)then >*/
		    if (fac < (float)1.) {
/* SOURCE culverta.for:952 */
/*<       fac=1.0/fac >*/
			fac = static_cast<double>((float)1.) / fac;
/* SOURCE culverta.for:953 */
/*<       endif >*/
		    }
/* SOURCE culverta.for:954 */
/*<       else >*/
		} else {
/* SOURCE culverta.for:955 */
/*<       write(outun,*)' QVSTW: Unexpected direction seeking',' a root.' >*/
		    feq_gen_io_d__80.ciunit = rqvtw_1.outun;
		    s_wsle(&feq_gen_io_d__80);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" QVSTW: Unexpected direction seeki\
ng"), (ftnlen)36);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" a root."), (ftnlen)8);
		    e_wsle();
/* SOURCE culverta.for:957 */
/*<       if(qlow.eq.0.0)then >*/
		    if (qlow == (float)0.) {
/*                 Set the known negative value. */
/* SOURCE culverta.for:959 */
/*<       fl=ztail-z1t >*/
			fl = static_cast<double>(ztail) - rqvtw_1.z1t;
/* SOURCE culverta.for:960 */
/*<       if(fl.gt.-epsabs)then >*/
			if (fl > -epscom_1.epsabs) {
/* SOURCE culverta.for:961 */
/*<       fl=-2.*epsabs >*/
			    fl = static_cast<double>(epscom_1.epsabs) * (float)-2.;
/* SOURCE culverta.for:962 */
/*<       endif >*/
			}
/* SOURCE culverta.for:963 */
/*<       qlow=abs(fl) >*/
			qlow = dabs(fl);
/* SOURCE culverta.for:964 */
/*<       goto110 >*/
			goto L110;
/* SOURCE culverta.for:965 */
/*<       endif >*/
		    }
/* SOURCE culverta.for:966 */
/*<       if(qhigh.eq.0.0)then >*/
		    if (qhigh == (float)0.) {
/* SOURCE culverta.for:967 */
/*<       write(outun,*)' POSSIBLE SEARCH FAILURE IN QVSTW' >*/
			feq_gen_io_d__82.ciunit = rqvtw_1.outun;
			s_wsle(&feq_gen_io_d__82);
			do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" POSSIBLE SEARCH FAILURE IN QV\
STW"), (ftnlen)33);
			e_wsle();
/*                  STOP 'Abnormal stop. Errors found.' */
/* SOURCE culverta.for:969 */
/*<       qculv=fac*qculv >*/
			qculv = static_cast<double>(fac) * qculv;
/* SOURCE culverta.for:970 */
/*<       goto100 >*/
			goto L100;
/* SOURCE culverta.for:971 */
/*<       endif >*/
		    }
/* SOURCE culverta.for:972 */
/*<       if(fac.gt.1.0)then >*/
		    if (fac > (float)1.) {
/* SOURCE culverta.for:973 */
/*<       fac=1.0/fac >*/
			fac = static_cast<double>((float)1.) / fac;
/* SOURCE culverta.for:974 */
/*<       endif >*/
		    }
/* SOURCE culverta.for:975 */
/*<       endif >*/
		}
/*              WRITE(OUTUN,*) ' KNT2=',KNT2,' DIR=',DIR,' FAC=',FAC */
/* SOURCE culverta.for:977 */
/*<       fold=f >*/
		fold = f;
/* SOURCE culverta.for:978 */
/*<       qold=qculv >*/
		qold = qculv;
/* SOURCE culverta.for:979 */
/*<       if(f.ge.0.0)then >*/
		if (f >= (float)0.) {
/*               Positive residual found. */
/* SOURCE culverta.for:981 */
/*<       qhigh=qculv >*/
		    qhigh = qculv;
/* SOURCE culverta.for:982 */
/*<       fr=f >*/
		    fr = f;
/* SOURCE culverta.for:984 */
/*<       if(qlow.gt.0.0)goto110 >*/
		    if (qlow > (float)0.) {
			goto L110;
		    }
/* SOURCE culverta.for:985 */
/*<       fl=ztail-z1t >*/
		    fl = static_cast<double>(ztail) - rqvtw_1.z1t;
/* SOURCE culverta.for:986 */
/*<       if(fl.gt.-epsabs)then >*/
		    if (fl > -epscom_1.epsabs) {
/* SOURCE culverta.for:987 */
/*<       fl=-2.*epsabs >*/
			fl = static_cast<double>(epscom_1.epsabs) * (float)-2.;
/* SOURCE culverta.for:988 */
/*<       endif >*/
		    }
/* SOURCE culverta.for:989 */
/*<       goto110 >*/
		    goto L110;
/* SOURCE culverta.for:990 */
/*<       else >*/
		} else {
/*               Negative residual found. */
/* SOURCE culverta.for:992 */
/*<       qlow=qculv >*/
		    qlow = qculv;
/* SOURCE culverta.for:993 */
/*<       fl=f >*/
		    fl = f;
/* SOURCE culverta.for:994 */
/*<       if(qhigh.gt.0.0)goto110 >*/
		    if (qhigh > (float)0.) {
			goto L110;
		    }
/*               Positive residual not yet known.  Continue to search. */
/* SOURCE culverta.for:996 */
/*<       qculv=fac*qculv >*/
		    qculv = static_cast<double>(fac) * qculv;
/* SOURCE culverta.for:997 */
/*<       goto100 >*/
		    goto L100;
/* SOURCE culverta.for:998 */
/*<       endif >*/
		}
/* SOURCE culverta.for:1000 */
/*<   110 continue >*/
L110:
/* SOURCE culverta.for:1002 */
/*<       callrgf3(0.0,epsabs,rqvstw,qlow,qhigh,fl,fr,qculv,flag) >*/
		rgf3_(&c_b137, &epscom_1.epsabs, rqvstw_, &qlow, &qhigh,
			 &fl, &fr, &qculv, &feq_gen_flag_d_);
/* SOURCE culverta.for:1007 */
/*<       if(abs(fl).gt.epsdif)then >*/
		if (dabs(fl) > epscom_1.epsdif) {
/* SOURCE culverta.for:1008 */
/*<        >*/
		    feq_gen_io_d__85.ciunit = rqvtw_1.outun;
		    s_wsle(&feq_gen_io_d__85);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" QVSTW: Residual at convergence="), (
			    ftnlen)32);
		    feq_gen_r_d_1 = dabs(fl);
		    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" > "), (ftnlen)3);
		    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&epscom_1.epsdif, (ftnlen)
			    sizeof(real));
		    e_wsle();
/* SOURCE culverta.for:1010 */
/*<       endif >*/
		}
/* SOURCE culverta.for:1011 */
/*<       endif >*/
	    }
/*           Assign the flow type. */
/* SOURCE culverta.for:1014 */
/*<       if(y3p.lt.ddn)then >*/
	    if (xs3com_1.y3p < ddn) {
/*             Exit soffit free of water */
/* SOURCE culverta.for:1016 */
/*<       if(y2.lt.dup)then >*/
		if (xs2com_1.y2 < dup) {
/* SOURCE culverta.for:1017 */
/*<       cqtype=3 >*/
		    rqvtw_1.cqtype = 3;
/* SOURCE culverta.for:1018 */
/*<       else >*/
		} else {
/* SOURCE culverta.for:1019 */
/*<       cqtype=41 >*/
		    rqvtw_1.cqtype = 41;
/* SOURCE culverta.for:1020 */
/*<       endif >*/
		}
/* SOURCE culverta.for:1021 */
/*<       else >*/
	    } else {
/*             Exit soffit is under water */
/* SOURCE culverta.for:1023 */
/*<       if(y2.lt.dup)then >*/
		if (xs2com_1.y2 < dup) {
/* SOURCE culverta.for:1024 */
/*<       cqtype=31 >*/
		    rqvtw_1.cqtype = 31;
/* SOURCE culverta.for:1025 */
/*<       else >*/
		} else {
/* SOURCE culverta.for:1026 */
/*<       cqtype=4 >*/
		    rqvtw_1.cqtype = 4;
/* SOURCE culverta.for:1027 */
/*<       endif >*/
		}
/* SOURCE culverta.for:1028 */
/*<       endif >*/
	    }
/*            WRITE(OUTUN,*) ' RQVSTW: CQTYPE=',CQTYPE */
/* SOURCE culverta.for:1031 */
/*<       lstype=cqtype >*/
	    xs2com_1.lstype = rqvtw_1.cqtype;
/*           Free surface at section 2.  Set false value in Y2P to */
/*           prevent false warning about subatmospheric pressures. */
/* SOURCE culverta.for:1035 */
/*<       y2p=1.e30 >*/
	    xs2com_1.y2p = (float)1e30;
/* SOURCE culverta.for:1036 */
/*<       if(cqtype.eq.4)then >*/
	    if (rqvtw_1.cqtype == 4) {
/*             Flow is not part full after all.  Compute with full flow */
/*             in the culvert barrel. */
/* SOURCE culverta.for:1039 */
/*<        >*/
		fulbar_(stdout, ab, alp1t, k1true, z1true, &xs2com_1.a2full, &
			xs2com_1.k2full, &xs3com_1.a3full, &cdcom_1.c46, &
			xs2com_1.a2full, &xs3com_1.z3p, &qculv, &xs2com_1.z2);
/*              WRITE(STDOUT,*) ' FULBAR AFTER RGF3 RETURNS QCULV=',QCULV */
/* SOURCE culverta.for:1044 */
/*<       lstype=4 >*/
		xs2com_1.lstype = 4;
/* SOURCE culverta.for:1045 */
/*<       cqtype=4 >*/
		rqvtw_1.cqtype = 4;
/* SOURCE culverta.for:1046 */
/*<       y2=dup >*/
		xs2com_1.y2 = dup;
/* SOURCE culverta.for:1047 */
/*<       y3=ddn >*/
		xs3com_1.y3 = ddn;
/* SOURCE culverta.for:1048 */
/*<       y2p=z2-zb2 >*/
		xs2com_1.y2p = static_cast<double>(xs2com_1.z2) - xs2com_1.zb2;
/* SOURCE culverta.for:1049 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:1050 */
/*<       endif >*/
	}
/* SOURCE culverta.for:1052 */
/*<       q1=qculv+wfrd >*/
	xs1com_1.q1 = static_cast<double>(qculv) + rdfcom_1.wfrd;
/* SOURCE culverta.for:1053 */
/*<       q2=qculv >*/
	xs2com_1.q2 = qculv;
/* SOURCE culverta.for:1054 */
/*<       q3=qculv >*/
	xs3com_1.q3 = qculv;
/*       Find the cross section elements at section 3. */
/* SOURCE culverta.for:1057 */
/*<        >*/
	xlkt22_(&xs3com_1.adrxs3, &xs3com_1.y3, &xs3com_1.a3, &xs3com_1.t3, &
		xs3com_1.dt3, &xs3com_1.j3, &xs3com_1.k3, &xs3com_1.dk3, &
		xs3com_1.bet3, &xs3com_1.dbet3, &xs3com_1.alp3, &
		xs3com_1.dalp3, &xs3com_1.q3c);
/* SOURCE culverta.for:1062 */
/*<       z3=y3+zb3 >*/
	xs3com_1.z3 = static_cast<double>(xs3com_1.y3) + xs3com_1.zb3;
/*       Store the values for later processing */
/* SOURCE culverta.for:1066 */
/*<       twvec(i)=ztail >*/
	twvec[feq_gen_i_d_ - 1] = ztail;
/* SOURCE culverta.for:1067 */
/*<       qclvt(i)=qculv >*/
	qclvt[feq_gen_i_d_ - 1] = qculv;
/* SOURCE culverta.for:1068 */
/*<       drop(i)=z1true-ztail >*/
	drop[feq_gen_i_d_ - 1] = static_cast<double>(*z1true) - ztail;
/* SOURCE culverta.for:1069 */
/*<       sqrtdp(i)=sqrt(z1true-ztail) >*/
	sqrtdp[feq_gen_i_d_ - 1] = feq::culvert_sqrt_drop(*z1true,ztail);
/* SOURCE culverta.for:1071 */
/*<       y3vec(i)=y3 >*/
	y3vec[feq_gen_i_d_ - 1] = xs3com_1.y3;
/* SOURCE culverta.for:1072 */
/*<       y2vec(i)=y2 >*/
	y2vec[feq_gen_i_d_ - 1] = xs2com_1.y2;
/* SOURCE culverta.for:1073 */
/*<       callvar_decimal(qculv,cqclv) >*/
	feq_gen_var_decimal_d_(&qculv, cqclv, (ftnlen)8);
/* SOURCE culverta.for:1075 */
/*<       callvar_decimal(wfrd,cqroad) >*/
	feq_gen_var_decimal_d_(&rdfcom_1.wfrd, cqroad, (ftnlen)8);
/* SOURCE culverta.for:1077 */
/*<        >*/
	feq_gen_io_d__86.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__86);
	feq_gen_r_d_1 = static_cast<double>(xs2com_1.z2) - *hdatum;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&xs2com_1.y2, (ftnlen)sizeof(real));
	feq_gen_r_d_2 = static_cast<double>(ztail) - *hdatum;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.y3, (ftnlen)sizeof(real));
	feq_gen_r_d_3 = static_cast<double>(*z1true) - ztail;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_3, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&rqvtw_1.cqtype, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, cqclv, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, cqroad, (ftnlen)8);
	e_wsfe();
/* SOURCE culverta.for:1079 */
/*<       if(drop(i).le.0.0)then >*/
	if (drop[feq_gen_i_d_ - 1] <= (float)0.) {
/* SOURCE culverta.for:1080 */
/*<       write(stdout,98) >*/
	    feq_gen_io_d__87.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__87);
	    e_wsfe();
/* SOURCE culverta.for:1081 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE culverta.for:1082 */
/*<       return >*/
	    return 0;
/* SOURCE culverta.for:1083 */
/*<       endif >*/
	}
/*       Get minimum piezometric level at section 2. */
/* SOURCE culverta.for:1086 */
/*<       y2pmin=min(y2pmin,y2p) >*/
	y2pmin = dmin(y2pmin,xs2com_1.y2p);
/* SOURCE culverta.for:1087 */
/*<   500 continue >*/
/* L500: */
    }
/* SOURCE culverta.for:1089 */
/*<       callvar_decimal(0.0,cqclv) >*/
    feq_gen_var_decimal_d_(&c_b137, cqclv, (ftnlen)8);
/* SOURCE culverta.for:1091 */
/*<       callvar_decimal(0.0,cqroad) >*/
    feq_gen_var_decimal_d_(&c_b137, cqroad, (ftnlen)8);
/* SOURCE culverta.for:1093 */
/*<        >*/
    feq_gen_io_d__88.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__88);
    feq_gen_r_d_1 = static_cast<double>(*z1true) - *hdatum;
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
/* Computing MIN */
    feq_gen_r_d_3 = dup, feq_gen_r_d_4 = static_cast<double>(*z1true) - xs2com_1.zb2;
    feq_gen_r_d_2 = dmin(feq_gen_r_d_3,feq_gen_r_d_4);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
    feq_gen_r_d_5 = static_cast<double>(*z1true) - *hdatum;
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_5, (ftnlen)sizeof(real));
/* Computing MIN */
    feq_gen_r_d_7 = static_cast<double>(*z1true) - xs3com_1.zb3;
    feq_gen_r_d_6 = dmin(feq_gen_r_d_7,ddn);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_6, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&c_b137, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&rqvtw_1.cqtype, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, cqclv, (ftnlen)8);
    do_fio(&feq_gen_c_d_1, cqroad, (ftnlen)8);
    e_wsfe();
/* SOURCE culverta.for:1097 */
/*<       write(stdout,78)ddn,dup >*/
    feq_gen_io_d__89.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__89);
    do_fio(&feq_gen_c_d_1, (char *)&ddn, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&dup, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE culverta.for:1099 */
/*<       if(dup-y2pmin.gt.(22.0-0.001*(zb2+zdatum)))then >*/
    if (static_cast<double>(dup) - y2pmin > static_cast<double>((float)22.) - static_cast<double>((static_cast<double>(xs2com_1.zb2) + *zdatum)) * (float).001) {
/*       Pressure is sufficiently subatmospheric to permit cavitation */
/*       near the entrance of the conduit. */
/* SOURCE culverta.for:1102 */
/*<       write(stdout,94)dup-y2pmin >*/
	feq_gen_io_d__90.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__90);
	feq_gen_r_d_1 = static_cast<double>(dup) - y2pmin;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culverta.for:1103 */
/*<       if(dup-y2pmin.gt.(34.0-0.001*(zb2+zdatum)))then >*/
	if (static_cast<double>(dup) - y2pmin > static_cast<double>((float)34.) - static_cast<double>((static_cast<double>(xs2com_1.zb2) + *zdatum)) * (float)
		.001) {
/* SOURCE culverta.for:1104 */
/*<       write(stdout,96)dup-y2pmin >*/
	    feq_gen_io_d__91.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__91);
	    feq_gen_r_d_1 = static_cast<double>(dup) - y2pmin;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culverta.for:1105 */
/*<       endif >*/
	}
/* SOURCE culverta.for:1106 */
/*<       endif >*/
    }
/*     Store the zero flow point */
/* SOURCE culverta.for:1108 */
/*<       twvec(nfrac)=z1true >*/
    twvec[*nfrac - 1] = *z1true;
/* SOURCE culverta.for:1109 */
/*<       qclvt(nfrac)=0.0 >*/
    qclvt[*nfrac - 1] = (float)0.;
/* SOURCE culverta.for:1110 */
/*<       drop(nfrac)=0.0 >*/
    drop[*nfrac - 1] = (float)0.;
/* SOURCE culverta.for:1111 */
/*<       sqrtdp(nfrac)=0.0 >*/
    sqrtdp[*nfrac - 1] = (float)0.;
/* SOURCE culverta.for:1112 */
/*<       if(z1t-zb3.lt.ddn)then >*/
    if (static_cast<double>(rqvtw_1.z1t) - xs3com_1.zb3 < ddn) {
/* SOURCE culverta.for:1113 */
/*<       y3vec(nfrac)=z1t-zb3 >*/
	y3vec[*nfrac - 1] = static_cast<double>(rqvtw_1.z1t) - xs3com_1.zb3;
/* SOURCE culverta.for:1114 */
/*<       else >*/
    } else {
/* SOURCE culverta.for:1115 */
/*<       y3vec(nfrac)=ddn >*/
	y3vec[*nfrac - 1] = ddn;
/* SOURCE culverta.for:1116 */
/*<       endif >*/
    }
/* SOURCE culverta.for:1117 */
/*<       if(z1t-zb2.le.dup)then >*/
    if (static_cast<double>(rqvtw_1.z1t) - xs2com_1.zb2 <= dup) {
/* SOURCE culverta.for:1118 */
/*<       y2vec(nfrac)=z1t-zb2 >*/
	y2vec[*nfrac - 1] = static_cast<double>(rqvtw_1.z1t) - xs2com_1.zb2;
/* SOURCE culverta.for:1119 */
/*<       else >*/
    } else {
/* SOURCE culverta.for:1120 */
/*<       y2vec(nfrac)=dup >*/
	y2vec[*nfrac - 1] = dup;
/* SOURCE culverta.for:1121 */
/*<       endif >*/
    }
/*     Try fitting a cubic spline with square root of drop as */
/*     the argument and flow in the culvert as the function.  Use */
/*     end conditions of zero second moment at the left end and */
/*     force linear slope at the  right end.  Note: the flow at zero */
/*     drop is always zero.  Note: The "left end" is the end */
/*     with index in the vectors of 1.  In this case it is the */
/*     free-flow limit.  The "right end" is the end with */
/*     an index of NFRAC and is the submerged flow limit of */
/*     zero flow. */
/* SOURCE culverta.for:1133 */
/*<       slope=qclvt(nfrac-1)/sqrtdp(nfrac-1) >*/
    slope = qclvt[*nfrac - 2] / sqrtdp[*nfrac - 2];
/*      CALL SPLINE(STDOUT, SQRTDP, QCLVT, NFRAC, 2, 0.D0, 1, */
/*     A                      SLOPE, MCLVT) */
/* SOURCE culverta.for:1136 */
/*<       callvlchpp(stdout,nfrac,sqrtdp,qclvt,2,0.d0,1,slope,mclvt,adjloc) >*/
    vlchpp_(stdout, nfrac, sqrtdp, qclvt, &feq_gen_c_d_2, &c_b172, &feq_gen_c_d_1, &slope, 
	    mclvt, adjloc, (ftnlen)1);
/* SOURCE culverta.for:1140 */
/*<       iflag=0 >*/
    iflag = 0;
/* SOURCE culverta.for:1141 */
/*<       do502i=1,nfrac >*/
    feq_gen_i_d_1 = *nfrac;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culverta.for:1142 */
/*<       if(adjloc(i).ne.' ')then >*/
	if (*(unsigned char *)&adjloc[feq_gen_i_d_ - 1] != ' ') {
/*         At least one slope has been adjusted. */
/* SOURCE culverta.for:1144 */
/*<       if(iflag.eq.0)then >*/
	    if (iflag == 0) {
/*           Write the heading. */
/* SOURCE culverta.for:1146 */
/*<       write(stdout,80) >*/
		feq_gen_io_d__96.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__96);
		e_wsfe();
/* SOURCE culverta.for:1147 */
/*<       iflag=1 >*/
		iflag = 1;
/* SOURCE culverta.for:1148 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:1149 */
/*<       write(stdout,82)sqrtdp(i)**2 >*/
	    feq_gen_io_d__97.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__97);
/* Computing 2nd power */
	    feq_gen_d_d_2 = sqrtdp[feq_gen_i_d_ - 1];
	    feq_gen_d_d_1 = feq_gen_d_d_2 * feq_gen_d_d_2;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_d_d_1, (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* SOURCE culverta.for:1150 */
/*<       endif >*/
	}
/* SOURCE culverta.for:1151 */
/*<   502 continue >*/
/* L502: */
    }
/* SOURCE culverta.for:1152 */
/*<       if(iflag.eq.0)then >*/
    if (iflag == 0) {
/*       No point was adjusted. */
/* SOURCE culverta.for:1154 */
/*<       write(stdout,84) >*/
	feq_gen_io_d__98.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__98);
	e_wsfe();
/* SOURCE culverta.for:1155 */
/*<       endif >*/
    }
/*     Store the results into a temporary table of type 4.  Give a table */
/*     number of -1. Put values in single precision vectors and reverse */
/*     order to ascending value of argument. */
/* SOURCE culverta.for:1161 */
/*<       do510i=1,nfrac >*/
    feq_gen_i_d_1 = *nfrac;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culverta.for:1162 */
/*<       argvec(nfrac-i+1)=sqrtdp(i) >*/
	argvec[*nfrac - feq_gen_i_d_] = sqrtdp[feq_gen_i_d_ - 1];
/* SOURCE culverta.for:1163 */
/*<       f1(nfrac-i+1)=qclvt(i) >*/
	f1[*nfrac - feq_gen_i_d_] = qclvt[feq_gen_i_d_ - 1];
/* SOURCE culverta.for:1164 */
/*<       f2(nfrac-i+1)=mclvt(i) >*/
	f2[*nfrac - feq_gen_i_d_] = mclvt[feq_gen_i_d_ - 1];
/* SOURCE culverta.for:1165 */
/*<   510 continue >*/
/* L510: */
    }
/*      WRITE(STDOUT,*) ' QVSTW BEFORE PUT1D: NEXT=',NEXT */
/* SOURCE culverta.for:1167 */
/*<       callput1d(stdout,-1,4,nfrac,argvec,f1,f2,next,q3vsrd) >*/
    put1d_(stdout, &c_n1, &feq_gen_c_d_4, nfrac, argvec, f1, f2, next, q3vsrd);
/*     Store the results for Y3 in a temporary table of type 2 */
/* SOURCE culverta.for:1173 */
/*<       do520i=1,nfrac >*/
    feq_gen_i_d_1 = *nfrac;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culverta.for:1174 */
/*<       argvec(i)=twvec(i) >*/
	argvec[feq_gen_i_d_ - 1] = twvec[feq_gen_i_d_ - 1];
/* SOURCE culverta.for:1175 */
/*<       f1(i)=y3vec(i) >*/
	f1[feq_gen_i_d_ - 1] = y3vec[feq_gen_i_d_ - 1];
/* SOURCE culverta.for:1176 */
/*<       f2(i)=0.0 >*/
	f2[feq_gen_i_d_ - 1] = (float)0.;
/*        WRITE(STDOUT,*) 'I=',I,' TWVEC(I)=',TWVEC(I), */
/*     A   ' Y3VEC(I)=',Y3VEC(I) */
/* SOURCE culverta.for:1179 */
/*<   520 continue >*/
/* L520: */
    }
/* SOURCE culverta.for:1181 */
/*<       callput1d(stdout,-1,2,nfrac,argvec,f1,f2,next,y3vstw) >*/
    put1d_(stdout, &c_n1, &feq_gen_c_d_2, nfrac, argvec, f1, f2, next, y3vstw);
/*     Process the values for Y2 in same way as the flow in the */
/*     culvert except that the argument is the drop instead of */
/*     the square root of drop */
/* SOURCE culverta.for:1189 */
/*<       slope=(y2vec(nfrac-1)-y2vec(nfrac))/drop(nfrac-1) >*/
    slope = (y2vec[*nfrac - 2] - y2vec[*nfrac - 1]) / drop[*nfrac - 2];
/* SOURCE culverta.for:1190 */
/*<       callvlchpp(stdout,nfrac,drop,y2vec,2,0.d0,1,slope,mclvt,adjloc) >*/
    vlchpp_(stdout, nfrac, drop, y2vec, &feq_gen_c_d_2, &c_b172, &feq_gen_c_d_1, &slope, mclvt, 
	    adjloc, (ftnlen)1);
/*      WRITE(STDOUT,*) ' Spline for Y2:' */
/*      DO 523 I=1,NFRAC */
/*        WRITE(STDOUT,9569) I, DROP(I), Y2VEC(I), MCLVT(I) */
/* 9569  FORMAT(I5, F10.4,F10.4,1PE12.5) */
/* 523   CONTINUE */
/* SOURCE culverta.for:1200 */
/*<       do525i=1,nfrac >*/
    feq_gen_i_d_1 = *nfrac;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culverta.for:1201 */
/*<       argvec(nfrac-i+1)=drop(i) >*/
	argvec[*nfrac - feq_gen_i_d_] = drop[feq_gen_i_d_ - 1];
/* SOURCE culverta.for:1202 */
/*<       f1(nfrac-i+1)=y2vec(i) >*/
	f1[*nfrac - feq_gen_i_d_] = y2vec[feq_gen_i_d_ - 1];
/* SOURCE culverta.for:1203 */
/*<       f2(nfrac-i+1)=mclvt(i) >*/
	f2[*nfrac - feq_gen_i_d_] = mclvt[feq_gen_i_d_ - 1];
/* SOURCE culverta.for:1204 */
/*<   525 continue >*/
/* L525: */
    }
/* SOURCE culverta.for:1205 */
/*<       callput1d(stdout,-1,4,nfrac,argvec,f1,f2,next,y2vsd) >*/
    put1d_(stdout, &c_n1, &feq_gen_c_d_4, nfrac, argvec, f1, f2, next, y2vsd);
/*     Set the minimum value for tailwater elevation */
/* SOURCE culverta.for:1212 */
/*<       z43min=twvec(1) >*/
    x43com_1.z43min = twvec[0];
/*      RETURN */
/*      WRITE(STDOUT,70) */
/*      WRITE(STDOUT,74) */
/*      WRITE(STDOUT,72) TWVEC(1), QCLVT(1), */
/*     A                   MCLVT(1), Y3VEC(1), DROP(1), SQRTDP(1) */
/*      WRITE(STDOUT,*) ' ' */
/*      DO 600 I=2,NFRAC */
/*        H = SQRTDP(I) - SQRTDP(I-1) */
/*        H = TWVEC(I) - TWVEC(I-1) */
/*        DO 590 J=2,4 */
/*          P = PVEC(J) */
/*          TW = TWVEC(I-1) + P*H */
/*          DRP = Z1T - TW */
/*          CALL LKTAB(Q3VSRD, SNGL(SQRT(DRP)), F, NTAB, DF, 1) */
/*          CALL LKTAB(Y3VSTW, SNGL(TW), Y3VAL, NTAB, PDV, 1) */

/*          PC = 1.D0 - P */
/*          FP = H*P*PC*(MCLVT(I-1)*PC - MCLVT(I)*P) */
/*     A         + (P + P + 1.D0)*PC**2*QCLVT(I-1) */
/*     B         + (3.D0 - P - P)*P**2*QCLVT(I) */
/*          FPP = PC*(1.D0 - 3.D0*P)*MCLVT(I-1) */
/*     A          - P*(2.D0 - 3.D0*P)*MCLVT(I) */
/*     B          + 6.D0*P*PC*(QCLVT(I) - QCLVT(I-1))/H */
/*          WRITE(STDOUT,73)    TW, F, DF, Y3VAL */
/* 590     CONTINUE */
/*        WRITE(STDOUT,*) ' ' */
/*        WRITE(STDOUT,72) TWVEC(I), QCLVT(I), */
/*     A                   MCLVT(I), Y3VEC(I), DROP(I), SQRTDP(I) */
/*        WRITE(STDOUT,*) ' ' */
/* 600   CONTINUE */
/* SOURCE culverta.for:1247 */
/*<       return >*/
    return 0;
/* SOURCE culverta.for:1248 */
/*<       end >*/
} /* qvstw_ */




/* SOURCE culverta.for:1252 */
/*<       subroutinechktel(stdout,chk23,de34,flag,cl34,de14) >*/
/* Subroutine */ int chktel_(integer *stdout, integer *chk23, real *de34, 
	integer *feq_gen_flag_d_, real *cl34, real *de14)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *WRN:530* Estimated level of total energy \
line at\002,\002 section 2=\002,f8.3,\002 > \002,/,11x,\002Estimated level o\
f total\002,\002 energy line at section 1=\002,f8.3)";
    static char fmt_52[] = "(\002 *WRN:531* Estimated level of total energy \
line at\002,\002 section 3=\002,f8.3,\002 > \002,/,11x,\002Estimated level o\
f total\002,\002 energy line at section 2=\002,f10.2)";
    static char fmt_54[] = "(\002 *WRN:532* Estimated level of total energy \
line at\002,\002 section 4=\002,f8.3,\002 > \002,/,11x,\002Estimated level o\
f total\002,\002 energy line at section 3=\002,f8.3)";
    static char fmt_58[] = "(\002 *WRN:535* Estimated level of total energy \
line at\002,\002 section 4=\002,f8.3,\002 > \002,/,11x,\002Estimated level o\
f total\002,\002 energy line at section 1=\002,f8.3)";
    static char fmt_70[] = "(11x,\002BETA4=\002,f6.3,\002 ALPHA4=\002,f6.3\
,\002 BETA3=\002,f6.3,\002 ALPHA3=\002,f6.3)";
    static char fmt_72[] = "(11x,\002BETA4=\002,f6.3,\002 ALPHA4=\002,f6.3\
,\002 BETA1=\002,f6.3,\002 ALPHA1=\002,f6.3)";
    static char fmt_74[] = "(11x,\002 ALPHA3=\002,f6.3,\002 ALPHA2=\002,f6.3)"
	    ;

    /* System generated locals */
    real feq_gen_r_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    real dv, vh3, vh4, vh44, kef3;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__102 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__103 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__107 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__108 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__109 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__110 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__111 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__112 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__113 = { 0, 0, 0, fmt_70, 0 };


/*     + + + PURPOSE + + + */
/*     Check the change in the elevation of the total energy line */
/*     and write warning messages if there is an increase in the */
/*     downstream direction. */
/* SOURCE culverta.for:1262 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culverta.for:1265 */
/*<       integerchk23,flag,stdout >*/
/* SOURCE culverta.for:1266 */
/*<       realcl34,de14,de34 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     CHK23  - flag for checking energy balance between sections 2 and 3 */
/*     DE34   - Drop in elevation of total energy line between section */
/*               3 and 4 for a culvert */
/*     FLAG   - Result flag */
/*     CL34   - Head loss factor between sections 3 and 4 for culverts */
/*     DE14   - Drop in elevation of total energy line between section */
/*               1 and 4 for a culvert */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culverta.for:1279 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culverta.for:1280 */
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
/* INCLUDE culverta.for:1281 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culverta.for:1282 */
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
/* INCLUDE culverta.for:1283 */
/* SOURCE xs4com.cmn:2 */
/*<        >*/
/* SOURCE xs4com.cmn:5 */
/*<       integeradrxs4 >*/
/* SOURCE xs4com.cmn:7 */
/*<        >*/
/* INCLUDE culverta.for:1284 */
/* SOURCE x44com.cmn:2 */
/*<        >*/
/* SOURCE x44com.cmn:6 */
/*<       integeradrs44,stat44 >*/
/* SOURCE x44com.cmn:8 */
/*<        >*/
/* INCLUDE culverta.for:1285 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culverta.for:1288 */
/*<       realdv,kef3,vh3,vh4,vh44 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culverta.for:1291 */
/*<       intrinsicabs >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culverta.for:1294 */
/*<    50  >*/
/* SOURCE culverta.for:1297 */
/*<    52  >*/
/* SOURCE culverta.for:1300 */
/*<    54  >*/
/* SOURCE culverta.for:1303 */
/*<    58  >*/
/* SOURCE culverta.for:1306 */
/*<    70  >*/
/* SOURCE culverta.for:1308 */
/*<    72  >*/
/* SOURCE culverta.for:1310 */
/*<    74 format(11x,' ALPHA3=',f6.3,' ALPHA2=',f6.3) >*/
/* *********************************************************************** */
/* SOURCE culverta.for:1312 */
/*<       if(a1*a2*a3*a4.le.0.0)then >*/
/* L50: */
/* L52: */
/* L54: */
/* L58: */
/* L70: */
/* L72: */
/* L74: */
    if (static_cast<double>(static_cast<double>(static_cast<double>(xs1com_1.a1) * xs2com_1.a2) * xs3com_1.a3) * xs4com_1.a4 <= (float)0.) {
/* SOURCE culverta.for:1313 */
/*<       write(stdout,*)' PROBLEM IN CHKTEL: A ZERO AREA' >*/
	feq_gen_io_d__102.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__102);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" PROBLEM IN CHKTEL: A ZERO AREA"), (ftnlen)31);
	e_wsle();
/* SOURCE culverta.for:1314 */
/*<       write(stdout,*)' A1=',a1,' A2=',a2,' A3=',a3,' A4=',a4 >*/
	feq_gen_io_d__103.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__103);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" A1="), (ftnlen)4);
	do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&xs1com_1.a1, (ftnlen)sizeof(real));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" A2="), (ftnlen)4);
	do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&xs2com_1.a2, (ftnlen)sizeof(real));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" A3="), (ftnlen)4);
	do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&xs3com_1.a3, (ftnlen)sizeof(real));
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" A4="), (ftnlen)4);
	do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&xs4com_1.a4, (ftnlen)sizeof(real));
	e_wsle();
/* SOURCE culverta.for:1315 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culverta.for:1316 */
/*<       endif >*/
    }
/* SOURCE culverta.for:1317 */
/*<       flag=1 >*/
    *feq_gen_flag_d_ = 1;
/* SOURCE culverta.for:1319 */
/*<       if(q2.lt.q1)then >*/
    if (xs2com_1.q2 < xs1com_1.q1) {
/*       FLOW OVER THE ROAD IS PRESENT. */
/* SOURCE culverta.for:1322 */
/*<       if(de34.eq.0.0)then >*/
	if (*de34 == (float)0.) {
/* SOURCE culverta.for:1323 */
/*<       kef3=alp3 >*/
	    kef3 = xs3com_1.alp3;
/* SOURCE culverta.for:1324 */
/*<       else >*/
	} else {
/* SOURCE culverta.for:1325 */
/*<       kef3=de34 >*/
	    kef3 = *de34;
/* SOURCE culverta.for:1326 */
/*<       endif >*/
	}
/* SOURCE culverta.for:1327 */
/*<       vh3=kef3*(q3/a3)**2/grav2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(xs3com_1.q3) / xs3com_1.a3;
	vh3 = static_cast<double>(static_cast<double>(kef3) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / grvcom_1.grav2;
/* SOURCE culverta.for:1328 */
/*<       vh4=alp4*(q4/a4)**2/grav2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(xs4com_1.q4) / xs4com_1.a4;
	vh4 = static_cast<double>(static_cast<double>(xs4com_1.alp4) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / grvcom_1.grav2;
/* SOURCE culverta.for:1330 */
/*<       ztel1=zb1+y1+alp1*(q1/a1)**2/grav2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(xs1com_1.q1) / xs1com_1.a1;
	xs1com_1.ztel1 = static_cast<double>(static_cast<double>(xs1com_1.zb1) + xs1com_1.y1) + static_cast<double>(static_cast<double>(xs1com_1.alp1) * (static_cast<double>(feq_gen_r_d_1) * 
		feq_gen_r_d_1)) / grvcom_1.grav2;
/* SOURCE culverta.for:1331 */
/*<       ztel4=zb4+y4+vh4 >*/
	xs4com_1.ztel4 = static_cast<double>(static_cast<double>(xs4com_1.zb4) + xs4com_1.y4) + vh4;
/* SOURCE culverta.for:1333 */
/*<       de14=ztel1-ztel4 >*/
	*de14 = static_cast<double>(xs1com_1.ztel1) - xs4com_1.ztel4;
/* SOURCE culverta.for:1335 */
/*<       if(ztel4.gt.ztel1+epsdif)then >*/
	if (xs4com_1.ztel4 > static_cast<double>(xs1com_1.ztel1) + epscom_1.epsdif) {
/* SOURCE culverta.for:1336 */
/*<       write(stdout,58)ztel4,ztel1 >*/
	    feq_gen_io_d__107.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__107);
	    do_fio(&feq_gen_c_d_1, (char *)&xs4com_1.ztel4, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xs1com_1.ztel1, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culverta.for:1337 */
/*<       write(stdout,72)bet4,alp4,bet1,alp1 >*/
	    feq_gen_io_d__108.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__108);
	    do_fio(&feq_gen_c_d_1, (char *)&xs4com_1.bet4, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xs4com_1.alp4, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xs1com_1.bet1, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xs1com_1.alp1, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culverta.for:1338 */
/*<       endif >*/
	}
/* SOURCE culverta.for:1340 */
/*<       else >*/
    } else {
/* SOURCE culverta.for:1341 */
/*<       if(de34.eq.0.0)then >*/
	if (*de34 == (float)0.) {
/* SOURCE culverta.for:1342 */
/*<       kef3=alp3 >*/
	    kef3 = xs3com_1.alp3;
/* SOURCE culverta.for:1343 */
/*<       else >*/
	} else {
/* SOURCE culverta.for:1344 */
/*<       kef3=de34 >*/
	    kef3 = *de34;
/* SOURCE culverta.for:1345 */
/*<       endif >*/
	}
/* SOURCE culverta.for:1346 */
/*<       vh3=kef3*(q3/a3)**2/grav2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(xs3com_1.q3) / xs3com_1.a3;
	vh3 = static_cast<double>(static_cast<double>(kef3) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / grvcom_1.grav2;
/* SOURCE culverta.for:1347 */
/*<       vh4=alp4*(q4/a4)**2/grav2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(xs4com_1.q4) / xs4com_1.a4;
	vh4 = static_cast<double>(static_cast<double>(xs4com_1.alp4) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / grvcom_1.grav2;
/* SOURCE culverta.for:1348 */
/*<       ztel1=zb1+y1+alp1*(q1/a1)**2/grav2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(xs1com_1.q1) / xs1com_1.a1;
	xs1com_1.ztel1 = static_cast<double>(static_cast<double>(xs1com_1.zb1) + xs1com_1.y1) + static_cast<double>(static_cast<double>(xs1com_1.alp1) * (static_cast<double>(feq_gen_r_d_1) * 
		feq_gen_r_d_1)) / grvcom_1.grav2;
/* SOURCE culverta.for:1349 */
/*<       if(chk23.eq.1)then >*/
	if (*chk23 == 1) {
/* SOURCE culverta.for:1350 */
/*<       ztel2=zb2+y2+alp2*(q2/a2)**2/grav2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(xs2com_1.q2) / xs2com_1.a2;
	    xs2com_1.ztel2 = static_cast<double>(static_cast<double>(xs2com_1.zb2) + xs2com_1.y2) + static_cast<double>(static_cast<double>(xs2com_1.alp2) * (
		    static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / grvcom_1.grav2;
/* SOURCE culverta.for:1351 */
/*<       endif >*/
	}
/* SOURCE culverta.for:1352 */
/*<       ztel3=z3p+vh3 >*/
	xs3com_1.ztel3 = static_cast<double>(xs3com_1.z3p) + vh3;
/* SOURCE culverta.for:1353 */
/*<       ztel4=zb4+y4+vh4 >*/
	xs4com_1.ztel4 = static_cast<double>(static_cast<double>(xs4com_1.zb4) + xs4com_1.y4) + vh4;
/*       APPLY CHECKS */
/* SOURCE culverta.for:1358 */
/*<       if(chk23.eq.1)then >*/
	if (*chk23 == 1) {
/* SOURCE culverta.for:1359 */
/*<       if(ztel2.gt.ztel1+epsdif)then >*/
	    if (xs2com_1.ztel2 > static_cast<double>(xs1com_1.ztel1) + epscom_1.epsdif) {
/* SOURCE culverta.for:1360 */
/*<       flag=0 >*/
		*feq_gen_flag_d_ = 0;
/* SOURCE culverta.for:1361 */
/*<       write(stdout,50)ztel2,ztel1 >*/
		feq_gen_io_d__109.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__109);
		do_fio(&feq_gen_c_d_1, (char *)&xs2com_1.ztel2, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&xs1com_1.ztel1, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE culverta.for:1362 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:1363 */
/*<       if(ztel3.gt.ztel2+epsdif)then >*/
	    if (xs3com_1.ztel3 > static_cast<double>(xs2com_1.ztel2) + epscom_1.epsdif) {
/* SOURCE culverta.for:1364 */
/*<       flag=0 >*/
		*feq_gen_flag_d_ = 0;
/* SOURCE culverta.for:1365 */
/*<       write(stdout,52)ztel3,ztel2 >*/
		feq_gen_io_d__110.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__110);
		do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.ztel3, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&xs2com_1.ztel2, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE culverta.for:1366 */
/*<       write(stdout,74)kef3,alp2 >*/
		feq_gen_io_d__111.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__111);
		do_fio(&feq_gen_c_d_1, (char *)&kef3, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, (char *)&xs2com_1.alp2, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE culverta.for:1367 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:1368 */
/*<       endif >*/
	}
/* SOURCE culverta.for:1369 */
/*<       if(ztel4.gt.ztel3+epsdif)then >*/
	if (xs4com_1.ztel4 > static_cast<double>(xs3com_1.ztel3) + epscom_1.epsdif) {
/* SOURCE culverta.for:1370 */
/*<       flag=0 >*/
	    *feq_gen_flag_d_ = 0;
/* SOURCE culverta.for:1371 */
/*<       write(stdout,54)ztel4,ztel3 >*/
	    feq_gen_io_d__112.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__112);
	    do_fio(&feq_gen_c_d_1, (char *)&xs4com_1.ztel4, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.ztel3, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culverta.for:1372 */
/*<       write(stdout,70)bet4,alp4,bet3,kef3 >*/
	    feq_gen_io_d__113.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__113);
	    do_fio(&feq_gen_c_d_1, (char *)&xs4com_1.bet4, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xs4com_1.alp4, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.bet3, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&kef3, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culverta.for:1373 */
/*<       endif >*/
	}
/* SOURCE culverta.for:1375 */
/*<       de14=ztel1-ztel4 >*/
	*de14 = static_cast<double>(xs1com_1.ztel1) - xs4com_1.ztel4;
/*       COMPUTE LOSS OF VELOCITY HEAD DIFFERENCE BETWEEN SECTION 3 AND 44 */
/* SOURCE culverta.for:1378 */
/*<       vh44=alp44*(q44/a44)**2/grav2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(x44com_1.q44) / x44com_1.a44;
	vh44 = static_cast<double>(static_cast<double>(x44com_1.alp44) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / grvcom_1.grav2;
/* SOURCE culverta.for:1379 */
/*<       dv=abs(vh3-vh44) >*/
	dv = (feq_gen_r_d_1 = static_cast<double>(vh3) - vh44, dabs(feq_gen_r_d_1));
/* SOURCE culverta.for:1380 */
/*<       de34=ztel3-ztel4 >*/
	*de34 = static_cast<double>(xs3com_1.ztel3) - xs4com_1.ztel4;
/* SOURCE culverta.for:1381 */
/*<       if(de34.lt.0.0.and.abs(de34).lt.0.5*epsdif)then >*/
	if (*de34 < (float)0. && dabs(*de34) < static_cast<double>(epscom_1.epsdif) * (float).5) {
/* SOURCE culverta.for:1382 */
/*<       de34=0.0 >*/
	    *de34 = (float)0.;
/* SOURCE culverta.for:1383 */
/*<       endif >*/
	}
/* SOURCE culverta.for:1384 */
/*<       if(dv.eq.0.0)then >*/
	if (dv == (float)0.) {
/* SOURCE culverta.for:1385 */
/*<       cl34=0.0 >*/
	    *cl34 = (float)0.;
/* SOURCE culverta.for:1386 */
/*<       else >*/
	} else {
/* SOURCE culverta.for:1387 */
/*<       cl34=de34/dv >*/
	    *cl34 = static_cast<double>(*de34) / dv;
/* SOURCE culverta.for:1388 */
/*<       endif >*/
	}
/* SOURCE culverta.for:1389 */
/*<       endif >*/
    }
/* SOURCE culverta.for:1390 */
/*<       return >*/
    return 0;
/* SOURCE culverta.for:1391 */
/*<       end >*/
} /* chktel_ */




/* SOURCE culverta.for:1395 */
/*<        >*/
/* Subroutine */ int frfclv_(integer *stdout, real *hdatum, real *zdatum, 
	real *hup, real *dup, real *ddn, integer *iu, integer *id, char *
	culcls, integer *eflag, integer *feq_gen_type_d_, integer *conflg, integer *
	expflg, real *zsbrdf, real *qfree, real *freed, ftnlen culcls_len)
{
    /* Format strings */
    static char fmt_51[] = "(\002 *WRN:542* At upstream head=\002,f10.2,\002\
 free flow type\002,\002 unclear.\002,/,11x,\002 Unable to continue.\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    real zup;
    extern /* Subroutine */ int frft0_(integer *, real *, real *, integer *, 
	    integer *, char *, integer *, integer *, integer *, real *, real *
	    , real *, ftnlen), frft12_(integer *, real *, real *, real *, 
	    real *, real *, integer *, integer *, char *, real *, real *, 
	    integer *, integer *, integer *, integer *, real *, real *, 
	    ftnlen), frft56_(integer *, real *, real *, real *, integer *, 
	    integer *, char *, integer *, integer *, integer *, real *, real *
	    , ftnlen);
    real zt12up, truea1;
    extern /* Subroutine */ int xlktal_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__119 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__120 = { 0, 0, 0, fmt_51, 0 };


/*     + + + PURPOSE + + + */
/*     Find the free flow rate in the culvert given by (IU, ID). */
/*     The upstream head is HUP relative to HDATUM. */
/* SOURCE culverta.for:1405 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culverta.for:1408 */
/*<       integerconflg,eflag,expflg,id,iu,stdout,type >*/
/* SOURCE culverta.for:1409 */
/*<       realddn,dup,freed,hdatum,hup,qfree,zdatum,zsbrdf >*/
/* SOURCE culverta.for:1410 */
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
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     TYPE   - Culvert flow type */
/*     CONFLG - CONFLG=0: flow contracts as it enters the culvert and */
/*              CONFLG=1: flow expands as it enters the culver */
/*     EXPFLG - Expansion flag.  EXPFLG=1 if flow expands on exit */
/*              and EXPFLG=0 if flow does not expand on exit */
/*     ZSBRDF - water surface elevation at section 43 that begins */
/*              submergence of flow over the roadway */
/*     QFREE  - Free flow */
/*     FREED  - Free drop */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culverta.for:1434 */
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
/* INCLUDE culverta.for:1435 */
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
/* INCLUDE culverta.for:1436 */
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
/* INCLUDE culverta.for:1437 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culverta.for:1440 */
/*<       realtruea1,zt12up,zup >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culverta.for:1443 */
/*<       intrinsicmax >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culverta.for:1446 */
/*<       externalfrft0,frft12,frft56,xlktal >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culverta.for:1449 */
/*<    51  >*/
/* *********************************************************************** */
/*     CLEAR FREE DROP FOR THE CULVERT TO PREVENT CONFUSION */
/* SOURCE culverta.for:1454 */
/*<       freed=0 >*/
/* L51: */
    *freed = (float)0.;
/* SOURCE culverta.for:1455 */
/*<       zup=hup+hdatum >*/
    zup = static_cast<double>(*hup) + *hdatum;
/*     CHECK FOR CONTROL AT SECTION 0. */
/* SOURCE culverta.for:1458 */
/*<        >*/
    frft0_(stdout, hdatum, hup, iu, id, culcls, eflag, feq_gen_type_d_, expflg, zsbrdf,
	     qfree, freed, (ftnlen)8);
/* SOURCE culverta.for:1461 */
/*<       if(eflag.ne.0)return >*/
    if (*eflag != 0) {
	return 0;
    }
/* SOURCE culverta.for:1462 */
/*<       if(type.eq.0)then >*/
    if (*feq_gen_type_d_ == 0) {
/* SOURCE culverta.for:1463 */
/*<       return >*/
	return 0;
/* SOURCE culverta.for:1464 */
/*<       endif >*/
    }
/*     RESET SECTION 1 VARIABLES. FRFT0 MAY HAVE CHANGED THEM */
/* SOURCE culverta.for:1468 */
/*<       z1=hdatum+hup >*/
    xs1com_1.z1 = static_cast<double>(*hdatum) + *hup;
/*     FIND THE ELEMENTS AT SECTION 1 */
/* SOURCE culverta.for:1472 */
/*<       y1=hdatum+hup-zb1 >*/
    xs1com_1.y1 = static_cast<double>(static_cast<double>(*hdatum) + *hup) - xs1com_1.zb1;
/* SOURCE culverta.for:1473 */
/*<       callxlktal(adrxs1,y1,a1,t1,dt1,j1,k1,dk1,bet1,dbet1,alp1,dalp1) >*/
    xlktal_(&xs1com_1.adrxs1, &xs1com_1.y1, &xs1com_1.a1, &xs1com_1.t1, &
	    xs1com_1.dt1, &xs1com_1.j1, &xs1com_1.k1, &xs1com_1.dk1, &
	    xs1com_1.bet1, &xs1com_1.dbet1, &xs1com_1.alp1, &xs1com_1.dalp1);
/*     SAVE VALUE OF TRUE AREA AT SECTION 1 */
/* SOURCE culverta.for:1479 */
/*<       truea1=a1 >*/
    truea1 = xs1com_1.a1;
/*     The limits for type 1 and type 2 flow may not be computed */
/*     at entry to FRFCLV.  CD1=0.0 and CD2=0.0 if the respective */
/*     limit has not been computed.  If the limit has been sought and */
/*     does not exist then the CD value is negative.  If the limit */
/*     has been sought and does exist the CD value gives the discharge */
/*     coefficient at that limit.  The limits are computed within */
/*     FRFT1 and FRFT2 if they have not been sought earlier. */
/*      WRITE(STDOUT,*) ' CD1=',CD1,' CD2=',CD2 */
/*      WRITE(STDOUT,*) ' Z1TY1=',Z1TY1,' Z1TY2=',Z1TY2 */
/*      IF(CD1.EQ.0.0.OR.CD2.EQ.0.0) THEN */
/* SOURCE culverta.for:1491 */
/*<       if(cd1.eq.0.0.and.cd2.eq.0.0)then >*/
    if (xs3com_1.cd1 == (float)0. && xs3com_1.cd2 == (float)0.) {
/*       Compute an estimated upper limit for the limit of type */
/*       1 and 2 flow */
/* SOURCE culverta.for:1494 */
/*<       zt12up=zbvec(iu)+1.50*dup >*/
	zt12up = static_cast<double>(culcom_1.zbvec[*iu - 1]) + static_cast<double>(*dup) * (float)1.5;
/* SOURCE culverta.for:1495 */
/*<       else >*/
    } else {
/*       Take the maximum of the two limits as the upper limit */
/*       that must be exceeded before we no longer try to find */
/*       type 1 or type 2 flow. */
/* SOURCE culverta.for:1499 */
/*<       zt12up=max(z1ty1,z1ty2) >*/
	zt12up = dmax(xs1com_1.z1ty1,xs1com_1.z1ty2);
/* SOURCE culverta.for:1500 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' ZUP=',ZUP,' ZT12UP=',ZT12UP,' HUP12=', */
/*     A               ZT12UP - HDATUM */
/* SOURCE culverta.for:1505 */
/*<       if(zup.lt.zt12up)then >*/
    if (zup < zt12up) {
/*       ESTIMATED FLOW TYPE IS 1 OR 2 */
/* SOURCE culverta.for:1508 */
/*<        >*/
	frft12_(stdout, hdatum, zdatum, hup, dup, ddn, iu, id, culcls, &
		truea1, &xs3com_1.cd1, eflag, feq_gen_type_d_, conflg, expflg, qfree, 
		freed, (ftnlen)8);
/* SOURCE culverta.for:1513 */
/*<       if(type.gt.2)then >*/
	if (*feq_gen_type_d_ > 2) {
/*         FLOW TYPE MUST BE 5 OR 6 OR 7 */
/* SOURCE culverta.for:1515 */
/*<       if(zup.ge.zbvec(iu)+dup)then >*/
	    if (zup >= static_cast<double>(culcom_1.zbvec[*iu - 1]) + *dup) {
/* SOURCE culverta.for:1516 */
/*<        >*/
		frft56_(stdout, hdatum, zdatum, hup, iu, id, culcls, eflag, 
			feq_gen_type_d_, expflg, qfree, freed, (ftnlen)8);
/* SOURCE culverta.for:1519 */
/*<       else >*/
	    } else {
/*           Free flow type unclear.  Set EFLAG and return. */
/* SOURCE culverta.for:1521 */
/*<       write(stdout,51)hup >*/
		feq_gen_io_d__119.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__119);
		do_fio(&feq_gen_c_d_1, (char *)&(*hup), (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE culverta.for:1522 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE culverta.for:1523 */
/*<       return >*/
		return 0;
/* SOURCE culverta.for:1524 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:1525 */
/*<       else >*/
	} else {
/*          WRITE(STDOUT,52) HUP, Z1, Z2, Z3P, Z4, TYPE, QFREE */
/*            WRITE(STDOUT,60) ZTEL1, ZTEL2, ZTEL3, ZTEL4 */
/* SOURCE culverta.for:1528 */
/*<       endif >*/
	}
/* SOURCE culverta.for:1529 */
/*<       else >*/
    } else {
/*       ESTIMATED FLOW TYPE IS 5 OR 6 */
/* SOURCE culverta.for:1532 */
/*<        >*/
	frft56_(stdout, hdatum, zdatum, hup, iu, id, culcls, eflag, feq_gen_type_d_, 
		expflg, qfree, freed, (ftnlen)8);
/* SOURCE culverta.for:1536 */
/*<       if(type.lt.5.and.type.ne.2)then >*/
	if (*feq_gen_type_d_ < 5 && *feq_gen_type_d_ != 2) {
/*          WRITE(STDOUT,*) ' REJECTING 6. TRY TYPE 1 AND 2.' */
/*         FLOW TYPE MUST BE 1 OR 2 */
/* SOURCE culverta.for:1539 */
/*<        >*/
	    frft12_(stdout, hdatum, zdatum, hup, dup, ddn, iu, id, culcls, &
		    truea1, &xs3com_1.cd1, eflag, feq_gen_type_d_, conflg, expflg, 
		    qfree, freed, (ftnlen)8);
/* SOURCE culverta.for:1544 */
/*<       if(type.gt.2)then >*/
	    if (*feq_gen_type_d_ > 2) {
/* SOURCE culverta.for:1545 */
/*<       write(stdout,51)hup >*/
		feq_gen_io_d__120.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__120);
		do_fio(&feq_gen_c_d_1, (char *)&(*hup), (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE culverta.for:1546 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE culverta.for:1547 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:1548 */
/*<       endif >*/
	}
/* SOURCE culverta.for:1549 */
/*<       endif >*/
    }
/* SOURCE culverta.for:1551 */
/*<       return >*/
    return 0;
/* SOURCE culverta.for:1552 */
/*<       end >*/
} /* frfclv_ */




/* SOURCE culverta.for:1556 */
/*<        >*/
/* Subroutine */ int fhhtyp_(integer *stdout, char *culcls, real *nfac, real *
	hup, real *hdatum, real *dup, integer *iu, integer *id, real *qrf, 
	real *y3limu, real *y3lim, integer *hhtype, real *cct5, real *yexit, 
	ftnlen culcls_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *WRN:544* Rounding value=\002,f5.3,\002 \
> 0.03 taken as\002,\002 0.03 for Figure 16.\002)";
    static char fmt_54[] = "(/,\002 Culvert barrel is smooth.\002)";
    static char fmt_56[] = "(/,\002 Culvert barrel is rough.  Factor=\002,f8\
.2)";
    static char fmt_58[] = "(/,\002 *WRN:546* Length to diameter ratio=\002,\
f8.3,\002 > 35\002,\002 when finding\002,/,11x,\002limiting slope for type 6\
/5 boundary.\002,\002 Value is inaccurate.\002)";
    static char fmt_60[] = "(/,\002 *WRN:563* Roughness factor for limiting \
slope for\002,\002 rough pipes\002,/,11x,\002< 0.10 or > 0.30.  Value is\002,\
\002 inaccurate.\002)";
    static char fmt_61[] = "(/,\002 *WRN:596* Roughness factor for limiting \
slope for\002,\002 rough pipes > 0.60.  Set to 0.60.\002)";
    static char fmt_62[] = "(/,\002 *WRN:564* Rounding value=\002,f5.3,\002 \
> 0.06 taken as\002,\002 0.06 for Figure 15.\002)";
    static char fmt_64[] = "(/,\002 High-head flow type=6. Forced for FLARED\
 inlet.\002)";
    static char fmt_66[] = "(/,\002 High-head flow is type\002,i3,\002.  Bou\
ndary So=\002,f8.4)";
    static char fmt_68[] = "(\002 *BUG:XXX* H over D=\002,f8.3,\002 too smal\
l in FHHTYP.\002)";
    static char fmt_70[] = "(/,\002 Checking flow type 5 in the culvert.\002)"
	    ;
    static char fmt_72[] = "(/,\002 Flow type 5 rejected.  Subcritical profi\
le prevails\002,\002 in the barrel.\002)";
    static char fmt_74[] = "(/,\002 Flow type 5 rejected.  High side of jump\
 > 0.8*D\002)";
    static char fmt_76[] = "(/,\002 High-head flow type=6 after rejection of\
 type 5.\002)";
    static char fmt_78[] = "(/,\002 Seeking full-flow-inducing value for typ\
e 5 flow.\002)";
    static char fmt_80[] = "(/,\002 Flow type 5 rejected.  Profile in barrel\
 undefined.\002)";
    static char fmt_82[] = "(/,\002 Flow type 5 rejected seeking full-flow-i\
nducing\002,\002 value.  High-head flow=6.\002)";
    static char fmt_84[] = "(/,\002 User limit=\002,f8.3,\002 taken for full\
-flow-inducing\002,\002 value. R/B at maximum.\002)";
    static char fmt_85[] = "(/,\002 User limit=\002,f8.3,\002 taken for full\
-flow-inducing\002,\002 value.  Type 5 profile undefined.\002)";
    static char fmt_86[] = "(\002  Super critical end depth=\002,f8.3,\002 t\
aken for\002,\002 full-flow-inducing value.\002)";
    static char fmt_87[] = "(/,\002 Enhanced R/B yields super critical profi\
le and \002,\002 user R/B yields a jump.\002,/,\002 Taking end depth=\002,f8\
.3,\002 from enhanced R/B profile for the\002,/,\002 full-flow-\002,\002indu\
cing value.\002)";
    static char fmt_88[] = "(/,\002 Enhanced R/B yields super critical profi\
le and \002,\002 user R/B yields a jump.\002,/,\002 Enhanced R/B profile\002,\
\002 has end depth=\002,f8.3,\002 < \002,f8.3,\002, the end depth\002,/,\002\
 for the user R/B profile.  User limit=\002,f8.3,\002 taken for full-flow-in\
ducing value.\002)";
    static char fmt_89[] = "(/,\002 Flow type 5 rejected. User R/B profile h\
as jump high\002,\002 side=\002,f8.3,\002 > \002,f8.3,/,\002, the enhanced p\
rofile jump\002,\002 high side.\002)";
    static char fmt_90[] = "(/,\002 Full-flow-inducing value=\002,f8.3,\002 \
defined by\002,\002 forcing high side of\002,/,\002 jump in user R/B profile\
 to\002,\002 match high side of jump in enhanced R/B profile.\002)";
    static char fmt_98[] = "(/,\002 *BUG:XXX* Iteration count exceeded in FH\
HTYP while\002,\002 seeking jump height.\002)";
    static char fmt_99[] = "(/,\002 *BUG:XXX* Problem in FHHTYP when varying\
 jump height\002,\002 seeking full-flow-inducing value.\002)";

    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2;
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe(),
	     do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double pow_dd(doublereal *, doublereal *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    real q5, y3t, qlm, yvc, cd6l, head;
    integer ierr;
    real fknt, yend, yvcl, cd6lm;
    extern /* Subroutine */ int fndq5_(integer *, real *, real *, integer *, 
	    char *, real *, real *, real *, real *, real *, ftnlen);
    real ycat3, y3max;
    extern /* Subroutine */ int fdcd46_(integer *, char *, real *, real *, 
	    ftnlen);
    real conco;
    integer itemp;
    real rbmax, sblim, yendl, yhigh, ty6ty5, yhlim;
    extern /* Subroutine */ int frovd_(integer *, char *, real *, ftnlen), 
	    fndcde_(integer *, integer *, real *, real *);
    real ty6lss;
    integer jmploc;
    real yhighl;
    integer ijumpl;
    char protyp[8], ptypel[8];
    extern doublereal fndszl_(integer *, char *, real *, real *, real *, real 
	    *, integer *, integer *, ftnlen);
    extern /* Subroutine */ int locjmp_(integer *, integer *, integer *, real 
	    *, real *, real *, real *, real *, real *, integer *, real *, 
	    integer *, char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__121 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__123 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__124 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__125 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__126 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__127 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__128 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__129 = { 0, 0, 0, fmt_61, 0 };
    static cilist feq_gen_io_d__130 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__131 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__133 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__144 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__145 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__146 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__147 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__148 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__149 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__150 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__151 = { 0, 0, 0, fmt_84, 0 };
    static cilist feq_gen_io_d__163 = { 0, 0, 0, fmt_85, 0 };
    static cilist feq_gen_io_d__165 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__166 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__167 = { 0, 0, 0, fmt_87, 0 };
    static cilist feq_gen_io_d__168 = { 0, 0, 0, fmt_88, 0 };
    static cilist feq_gen_io_d__169 = { 0, 0, 0, fmt_89, 0 };
    static cilist feq_gen_io_d__173 = { 0, 0, 0, fmt_99, 0 };
    static cilist feq_gen_io_d__174 = { 0, 0, 0, fmt_90, 0 };
    static cilist feq_gen_io_d__175 = { 0, 0, 0, fmt_98, 0 };


/*     + + + PURPOSE + + + */
/*     Find the type of high head flow for the current upstream head. */
/*     Current method for box culverts does not depend on head but */
/*     done here anyway in anticipation of a better rule that will */
/*     depend on head. */
/* SOURCE culverta.for:1568 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culverta.for:1571 */
/*<       integerhhtype,id,iu,stdout >*/
/* SOURCE culverta.for:1572 */
/*<       realcct5,dup,hdatum,hup,nfac,qrf,y3lim,y3limu,yexit >*/
/* SOURCE culverta.for:1573 */
/*<       characterculcls*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     CULCLS - Class for culvert shape, BOX, PIPE, .. */
/*     NFAC   - Factor in Manning's formula(1.49 or 1.0) */
/*     HUP    - Head upstream */
/*     HDATUM - Datum for measuring head */
/*     DUP    - vertical diameter of culvert barrel at upstream end */
/*     IU     - Index for upstream node for the culvert barrel */
/*     ID     - Index for the downstream node for the culvert barrel */
/*     QRF    - Flow over the roadway */
/*     Y3LIMU - full-flow-inducing depth at culvert exit for type 5 flow */
/*     Y3LIM  - full-flow-inducing depth at culvert exit for type 5 flow */
/*     HHTYPE - high-head type */
/*     CCT5   - contraction coefficient for type 5 flow */
/*     YEXIT  - depth at exit of the culvert */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culverta.for:1592 */
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
/* INCLUDE culverta.for:1593 */
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
/* INCLUDE culverta.for:1594 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culverta.for:1595 */
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
/* INCLUDE culverta.for:1596 */
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
/* INCLUDE culverta.for:1597 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culverta.for:1600 */
/*<       integerierr,ijumpl,jmploc,itemp >*/
/* SOURCE culverta.for:1601 */
/*<        >*/
/* SOURCE culverta.for:1604 */
/*<       characterprotyp*8,ptypel*8 >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culverta.for:1607 */
/*<       realfndszl >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culverta.for:1610 */
/*<       externalfdcd46,fndcde,fndq5,fndszl,frovd,locjmp >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culverta.for:1613 */
/*<    50  >*/
/* SOURCE culverta.for:1615 */
/*<    54 format(/,' Culvert barrel is smooth.') >*/
/* SOURCE culverta.for:1616 */
/*<    56 format(/,' Culvert barrel is rough.  Factor=',f8.2) >*/
/* SOURCE culverta.for:1617 */
/*<    58  >*/
/* SOURCE culverta.for:1620 */
/*<    60  >*/
/* SOURCE culverta.for:1623 */
/*<    61  >*/
/* SOURCE culverta.for:1625 */
/*<    62  >*/
/* SOURCE culverta.for:1627 */
/*<    64 format(/,' High-head flow type=6. Forced for FLARED inlet.') >*/
/* SOURCE culverta.for:1628 */
/*<    66 format(/,' High-head flow is type',i3,'.  Boundary So=',f8.4) >*/
/* SOURCE culverta.for:1629 */
/*<    68 format(' *BUG:XXX* H over D=',f8.3,' too small in FHHTYP.') >*/
/* SOURCE culverta.for:1630 */
/*<    70 format(/,' Checking flow type 5 in the culvert.') >*/
/* SOURCE culverta.for:1631 */
/*<    72  >*/
/* SOURCE culverta.for:1633 */
/*<    74 format(/,' Flow type 5 rejected.  High side of jump > 0.8*D') >*/
/* SOURCE culverta.for:1634 */
/*<    76 format(/,' High-head flow type=6 after rejection of type 5.') >*/
/* SOURCE culverta.for:1635 */
/*<    78 format(/,' Seeking full-flow-inducing value for type 5 flow.') >*/
/* SOURCE culverta.for:1636 */
/*<    80 format(/,' Flow type 5 rejected.  Profile in barrel undefined.') >*/
/* SOURCE culverta.for:1637 */
/*<    82  >*/
/* SOURCE culverta.for:1639 */
/*<    84  >*/
/* SOURCE culverta.for:1641 */
/*<    85  >*/
/* SOURCE culverta.for:1643 */
/*<    86  >*/
/* SOURCE culverta.for:1645 */
/*<    87  >*/
/* SOURCE culverta.for:1649 */
/*<    88  >*/
/* SOURCE culverta.for:1654 */
/*<    89  >*/
/* SOURCE culverta.for:1657 */
/*<    90  >*/
/* SOURCE culverta.for:1660 */
/*<    98  >*/
/* SOURCE culverta.for:1662 */
/*<    99  >*/
/* *********************************************************************** */
/*      WRITE(STDOUT,*) ' FHHTYP: on entry: Y3LIM=',Y3LIM, */
/*     A               ' Y3LIMU=',Y3LIMU */
/* SOURCE culverta.for:1667 */
/*<       if(culcls.eq.'FLARED'.and.rbval.gt.0.0)then >*/
/* L50: */
/* L54: */
/* L56: */
/* L58: */
/* L60: */
/* L61: */
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
/* L85: */
/* L86: */
/* L87: */
/* L88: */
/* L89: */
/* L90: */
/* L98: */
/* L99: */
    if (s_cmp(culcls, const_cast<char*>("FLARED"), (ftnlen)8, (ftnlen)6) == 0 && cdcom_1.rbval > 
	    (float)0.) {
/*       Assume the user wants type 6 flow. */
/* SOURCE culverta.for:1669 */
/*<       hhtype=6 >*/
	*hhtype = 6;
/* SOURCE culverta.for:1670 */
/*<       write(stdout,64) >*/
	feq_gen_io_d__121.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__121);
	e_wsfe();
/* SOURCE culverta.for:1671 */
/*<       else >*/
    } else {
/* SOURCE culverta.for:1672 */
/*<       head=hup+hdatum-zb2 >*/
	head = static_cast<double>(static_cast<double>(*hup) + *hdatum) - xs2com_1.zb2;
/* SOURCE culverta.for:1673 */
/*<       hoverd=head/dup >*/
	cdcom_1.hoverd = static_cast<double>(head) / *dup;
/* SOURCE culverta.for:1674 */
/*<       if(hoverd.lt.1.5)then >*/
	if (cdcom_1.hoverd < (float)1.5) {
/*         Should not happen. */
/* SOURCE culverta.for:1676 */
/*<       write(stdout,68)hoverd >*/
	    feq_gen_io_d__123.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__123);
	    do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.hoverd, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culverta.for:1677 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culverta.for:1678 */
/*<       endif >*/
	}
/* SOURCE culverta.for:1679 */
/*<       if(culcls.eq.'BOX')then >*/
	if (s_cmp(culcls, const_cast<char*>("BOX"), (ftnlen)8, (ftnlen)3) == 0) {
/*         Assign values that will not be used. */
/* SOURCE culverta.for:1681 */
/*<       nbar=0.001 >*/
	    cdcom_1.nbar = (float).001;
/* SOURCE culverta.for:1682 */
/*<       rghfac=0.01 >*/
	    cdcom_1.rghfac = (float).01;
/* SOURCE culverta.for:1683 */
/*<       write(stdout,54) >*/
	    feq_gen_io_d__124.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__124);
	    e_wsfe();
/* SOURCE culverta.for:1684 */
/*<       else >*/
	} else {
/*         Estimate the composite n value for the conduit or conduits. */
/* SOURCE culverta.for:1686 */
/*<       nbar=nfac*a2full*(dup/4.0)**0.666667/k2full >*/
	    feq_gen_d_d_1 = (doublereal) (static_cast<double>(*dup) / (float)4.);
	    cdcom_1.nbar = static_cast<double>(*nfac) * xs2com_1.a2full * pow_dd(&feq_gen_d_d_1, &c_b308) / 
		    xs2com_1.k2full;
/*          WRITE(STDOUT,*) ' NBAR=',NBAR */
/* SOURCE culverta.for:1688 */
/*<       if(nbar.lt.0.019)then >*/
	    if (cdcom_1.nbar < (float).019) {
/*           Treat the conduit as smooth. */
/* SOURCE culverta.for:1690 */
/*<       rghfac=0.01 >*/
		cdcom_1.rghfac = (float).01;
/* SOURCE culverta.for:1691 */
/*<       write(stdout,54) >*/
		feq_gen_io_d__125.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__125);
		e_wsfe();
/* SOURCE culverta.for:1692 */
/*<       else >*/
	    } else {
/*           Treat the conduit as rough.  Compute the roughness factor. */
/* SOURCE culverta.for:1694 */
/*<       rghfac=29.0*head*(a2full*nfac/k2full)**2 >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = static_cast<double>(static_cast<double>(xs2com_1.a2full) * *nfac) / xs2com_1.k2full;
		cdcom_1.rghfac = static_cast<double>(static_cast<double>(head) * (float)29.) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE culverta.for:1695 */
/*<       write(stdout,56)rghfac >*/
		feq_gen_io_d__126.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__126);
		do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.rghfac, (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE culverta.for:1696 */
/*<       if(rbval.gt.0.03)then >*/
		if (cdcom_1.rbval > (float).03) {
/* SOURCE culverta.for:1697 */
/*<       write(stdout,50)rbval >*/
		    feq_gen_io_d__127.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__127);
		    do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.rbval, (ftnlen)sizeof(real)
			    );
		    e_wsfe();
/* SOURCE culverta.for:1698 */
/*<       endif >*/
		}
/* SOURCE culverta.for:1699 */
/*<       if(rghfac.lt.0.1.or.rghfac.gt.0.3)then >*/
		if (cdcom_1.rghfac < (float).1 || cdcom_1.rghfac > (float).3) 
			{
/* SOURCE culverta.for:1700 */
/*<       write(stdout,60) >*/
		    feq_gen_io_d__128.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__128);
		    e_wsfe();
/* SOURCE culverta.for:1701 */
/*<       endif >*/
		}
/* SOURCE culverta.for:1702 */
/*<       if(rghfac.gt.0.60)then >*/
		if (cdcom_1.rghfac > (float).6) {
/* SOURCE culverta.for:1703 */
/*<       write(stdout,61) >*/
		    feq_gen_io_d__129.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__129);
		    e_wsfe();
/* SOURCE culverta.for:1704 */
/*<       rghfac=0.60 >*/
		    cdcom_1.rghfac = (float).6;
/* SOURCE culverta.for:1705 */
/*<       endif >*/
		}
/* SOURCE culverta.for:1706 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:1707 */
/*<       endif >*/
	}
/* SOURCE culverta.for:1708 */
/*<       if(nbar.lt.0.019.and.rbval.gt.0.06)then >*/
	if (cdcom_1.nbar < (float).019 && cdcom_1.rbval > (float).06) {
/* SOURCE culverta.for:1709 */
/*<       write(stdout,62)rbval >*/
	    feq_gen_io_d__130.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__130);
	    do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.rbval, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culverta.for:1710 */
/*<       endif >*/
	}
/* SOURCE culverta.for:1711 */
/*<       if(loverd.gt.35)then >*/
	if (culcom_1.loverd > (float)35.) {
/* SOURCE culverta.for:1712 */
/*<       write(stdout,58)loverd >*/
	    feq_gen_io_d__131.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__131);
	    do_fio(&feq_gen_c_d_1, (char *)&culcom_1.loverd, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culverta.for:1713 */
/*<       endif >*/
	}
/* SOURCE culverta.for:1714 */
/*<       sblim=fndszl(stdout,culcls,loverd,nbar,rghfac,rbval,tb15ad,tb16ad) >*/
	sblim = fndszl_(stdout, culcls, &culcom_1.loverd, &cdcom_1.nbar, &
		cdcom_1.rghfac, &cdcom_1.rbval, &cdcom_1.tb15ad, 
		cdcom_1.tb16ad, (ftnlen)8);
/* SOURCE culverta.for:1716 */
/*<       if(szero.gt.sblim)then >*/
	if (culcom_1.szero > sblim) {
/* SOURCE culverta.for:1717 */
/*<       hhtype=5 >*/
	    *hhtype = 5;
/* SOURCE culverta.for:1718 */
/*<       write(stdout,70) >*/
	    feq_gen_io_d__133.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__133);
	    e_wsfe();
/*         Verify type 5 and compute the full-flow-inducing value for */
/*         it.  Type 5 flow is in a sense unstable and a transition to */
/*         type 6 may be likely.   Therefore type 6 is selected if there */
/*         is any reason to doubt type 5. */
/* SOURCE culverta.for:1723 */
/*<       callfndq5(stdout,hdatum,hup,iu,culcls,rbval,qrf,yvc,q5,cct5) >*/
	    fndq5_(stdout, hdatum, hup, iu, culcls, &cdcom_1.rbval, qrf, &yvc,
		     &q5, cct5, (ftnlen)8);
/* SOURCE culverta.for:1726 */
/*<       callfdcd46(stdout,culcls,rbval,cd6l) >*/
	    fdcd46_(stdout, culcls, &cdcom_1.rbval, &cd6l, (ftnlen)8);
/* SOURCE culverta.for:1729 */
/*<       ty6ty5=((1.0/cd6l**2-1.0))*(q5/a2full)**2/grav2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = cd6l;
/* Computing 2nd power */
	    feq_gen_r_d_2 = static_cast<double>(q5) / xs2com_1.a2full;
	    ty6ty5 = static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - (float)1.)) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) /
		     grvcom_1.grav2;
/* SOURCE culverta.for:1730 */
/*<       ycat3=0.5*dup >*/
	    ycat3 = static_cast<double>(*dup) * (float).5;
/* SOURCE culverta.for:1731 */
/*<       callfndcde(stdout,adrxs3,q5,ycat3) >*/
	    fndcde_(stdout, &xs3com_1.adrxs3, &q5, &ycat3);
/*          WRITE(STDOUT,*) ' Critical depth at exit=',YCAT3 */
/*         Find the profile in the barrel. */
/* SOURCE culverta.for:1736 */
/*<        >*/
	    locjmp_(stdout, &culcom_1.iat3d, id, &yvc, &ycat3, &q5, dup, &
		    ty6ty5, &yhigh, &jmploc, &yend, &ierr, protyp, (ftnlen)8);
/* SOURCE culverta.for:1740 */
/*<       yexit=yend >*/
	    *yexit = yend;
/* SOURCE culverta.for:1741 */
/*<       if(protyp.eq.'SUB')then >*/
	    if (s_cmp(protyp, const_cast<char*>("SUB"), (ftnlen)8, (ftnlen)3) == 0) {
/*           Reject type 5 because critical depth at the exit at the */
/*           type 5 flow yields a subcritical profile that drowns */
/*           any jump created by the supercritical flow at the vena */
/*           contracta.   Negative sign used to distinguish type 6 */
/*           after rejection of type 5 from selection of type 6 */
/*           from the figures. */
/* SOURCE culverta.for:1748 */
/*<       hhtype=-6 >*/
		*hhtype = -6;
/* SOURCE culverta.for:1749 */
/*<       write(stdout,72) >*/
		feq_gen_io_d__144.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__144);
		e_wsfe();
/* SOURCE culverta.for:1750 */
/*<       elseif(protyp.eq.'MIXED')then >*/
	    } else if (s_cmp(protyp, const_cast<char*>("MIXED"), (ftnlen)8, (ftnlen)5) == 0) {
/*           A jump exists in the barrel maintained by critical depth */
/*           at the barrel exit.  Is the jump too high?  The Froude */
/*           numbers encountered will tend to produce an undular jump. */
/*           Therefore the water surface downstream of the jump will */
/*           have waves that are a significant proportion of the depth. */
/*           These waves will tend to seal the barrel so that the */
/*           air cannot easily enter. */
/* SOURCE culverta.for:1758 */
/*<       if(yhigh.gt.0.8*dvec(jmploc))then >*/
		if (yhigh > static_cast<double>(culcom_1.dvec[jmploc - 1]) * (float).8) {
/*             Reject type 5 flow.  Unlikely to prevail with a jump */
/*             this high. */
/* SOURCE culverta.for:1761 */
/*<       hhtype=-6 >*/
		    *hhtype = -6;
/* SOURCE culverta.for:1762 */
/*<       write(stdout,74) >*/
		    feq_gen_io_d__145.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__145);
		    e_wsfe();
/* SOURCE culverta.for:1763 */
/*<       endif >*/
		}
/* SOURCE culverta.for:1764 */
/*<       elseif(ierr.ne.0)then >*/
	    } else if (ierr != 0) {
/*           Some problem found in computing the profile.  Could be */
/*           a nonsense culvert barrel.  However, try to continue */
/*           by making high-head flow type 6. */
/* SOURCE culverta.for:1768 */
/*<       hhtype=-6 >*/
		*hhtype = -6;
/* SOURCE culverta.for:1769 */
/*<       write(stdout,80) >*/
		feq_gen_io_d__146.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__146);
		e_wsfe();
/* SOURCE culverta.for:1770 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:1771 */
/*<       else >*/
	} else {
/* SOURCE culverta.for:1772 */
/*<       hhtype=6 >*/
	    *hhtype = 6;
/* SOURCE culverta.for:1773 */
/*<       endif >*/
	}
/* SOURCE culverta.for:1774 */
/*<       if(hhtype.eq.6)then >*/
	if (*hhtype == 6) {
/* SOURCE culverta.for:1775 */
/*<       write(stdout,66)hhtype,sblim >*/
	    feq_gen_io_d__147.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__147);
	    do_fio(&feq_gen_c_d_1, (char *)&(*hhtype), (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&sblim, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culverta.for:1776 */
/*<       elseif(hhtype.eq.-6)then >*/
	} else if (*hhtype == -6) {
/* SOURCE culverta.for:1777 */
/*<       hhtype=6 >*/
	    *hhtype = 6;
/* SOURCE culverta.for:1778 */
/*<       write(stdout,76) >*/
	    feq_gen_io_d__148.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__148);
	    e_wsfe();
/* SOURCE culverta.for:1779 */
/*<       else >*/
	} else {
/* SOURCE culverta.for:1780 */
/*<       write(stdout,66)hhtype,sblim >*/
	    feq_gen_io_d__149.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__149);
	    do_fio(&feq_gen_c_d_1, (char *)&(*hhtype), (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&sblim, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culverta.for:1781 */
/*<       endif >*/
	}
/* SOURCE culverta.for:1782 */
/*<       if(hhtype.eq.5)then >*/
	if (*hhtype == 5) {
/*         Seek the depth at the culvert exit that will induce full */
/*         flow in the barrel. */
/* SOURCE culverta.for:1785 */
/*<       write(stdout,78) >*/
	    feq_gen_io_d__150.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__150);
	    e_wsfe();
/*         Find the value of relative rounding/beveling that causes */
/*         the culvert slope at the boundary between type 5 and type 6 to */
/*         be the same as the culvert slope. */
/* SOURCE culverta.for:1790 */
/*<       callfrovd(stdout,culcls,rovdlm) >*/
	    frovd_(stdout, culcls, &cdcom_1.rovdlm, (ftnlen)8);
/* SOURCE culverta.for:1793 */
/*<       if(rovdlm.le.rbval)then >*/
	    if (cdcom_1.rovdlm <= cdcom_1.rbval) {
/*           The culvert already has a rounding/beveling value at the */
/*           limit for the figures.  Assign the full-flow-inducing value */
/*           to the user value. */
/* SOURCE culverta.for:1797 */
/*<       write(stdout,84)y3limu >*/
		feq_gen_io_d__151.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__151);
		do_fio(&feq_gen_c_d_1, (char *)&(*y3limu), (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE culverta.for:1798 */
/*<       y3lim=y3limu >*/
		*y3lim = *y3limu;
/* SOURCE culverta.for:1799 */
/*<       else >*/
	    } else {
/* SOURCE culverta.for:1800 */
/*<       rbmax=rovdlm >*/
		rbmax = cdcom_1.rovdlm;
/* SOURCE culverta.for:1801 */
/*<       fknt=8 >*/
		fknt = (float)8.;
/* SOURCE culverta.for:1802 */
/*<   100 continue >*/
L100:
/*           Find the type 5 flow for the enhanced rounding/beveling */
/* SOURCE culverta.for:1804 */
/*<       callfndq5(stdout,hdatum,hup,iu,culcls,rovdlm,qrf,yvcl,qlm,conco) >*/
		fndq5_(stdout, hdatum, hup, iu, culcls, &cdcom_1.rovdlm, qrf, 
			&yvcl, &qlm, &conco, (ftnlen)8);
/* SOURCE culverta.for:1807 */
/*<       ycat3=0.5*dvec(id) >*/
		ycat3 = static_cast<double>(culcom_1.dvec[*id - 1]) * (float).5;
/* SOURCE culverta.for:1808 */
/*<       callfndcde(stdout,adrxs3,qlm,ycat3) >*/
		fndcde_(stdout, &xs3com_1.adrxs3, &qlm, &ycat3);
/* SOURCE culverta.for:1811 */
/*<       callfdcd46(stdout,culcls,rovdlm,cd6lm) >*/
		fdcd46_(stdout, culcls, &cdcom_1.rovdlm, &cd6lm, (ftnlen)8);
/* SOURCE culverta.for:1814 */
/*<       ty6lss=((1.0/cd6lm**2-1.0))*(qlm/a2full)**2/grav2 >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = cd6lm;
/* Computing 2nd power */
		feq_gen_r_d_2 = static_cast<double>(qlm) / xs2com_1.a2full;
		ty6lss = static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>((float)1.) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - (float)1.)) * (static_cast<double>(feq_gen_r_d_2) * 
			feq_gen_r_d_2)) / grvcom_1.grav2;
/* SOURCE culverta.for:1815 */
/*<        >*/
		locjmp_(stdout, &culcom_1.iat3d, id, &yvcl, &ycat3, &qlm, dup,
			 &ty6lss, &yhighl, &ijumpl, &yendl, &ierr, ptypel, (
			ftnlen)8);
/* SOURCE culverta.for:1819 */
/*<       if(ierr.eq.1)then >*/
		if (ierr == 1) {
/*             Take user value. */
/* SOURCE culverta.for:1821 */
/*<       y3lim=y3limu >*/
		    *y3lim = *y3limu;
/* SOURCE culverta.for:1822 */
/*<       write(stdout,85)y3lim >*/
		    feq_gen_io_d__163.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__163);
		    do_fio(&feq_gen_c_d_1, (char *)&(*y3lim), (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE culverta.for:1823 */
/*<       else >*/
		} else {
/*             See if enhanced rounding/beveling creates a meaningful */
/*             profile. */
/* SOURCE culverta.for:1826 */
/*<       if(ptypel.eq.'MIXED'.and.yhighl.gt.0.8*dvec(ijumpl))then >*/
		    if (s_cmp(ptypel, const_cast<char*>("MIXED"), (ftnlen)8, (ftnlen)5) == 0 && 
			    yhighl > static_cast<double>(culcom_1.dvec[ijumpl - 1]) * (float).8) {
/* SOURCE culverta.for:1827 */
/*<       itemp=1 >*/
			itemp = 1;
/* SOURCE culverta.for:1828 */
/*<       else >*/
		    } else {
/* SOURCE culverta.for:1829 */
/*<       itemp=0 >*/
			itemp = 0;
/* SOURCE culverta.for:1830 */
/*<       endif >*/
		    }
/* SOURCE culverta.for:1831 */
/*<       if(ptypel.eq.'SUB'.or.itemp.eq.1)then >*/
		    if (s_cmp(ptypel, const_cast<char*>("SUB"), (ftnlen)8, (ftnlen)3) == 0 || 
			    itemp == 1) {
/*               Reduce the rounding and beveling value and try again. */
/*               The profile is not meaningful at the enhanced level. */
/* SOURCE culverta.for:1834 */
/*<       fknt=fknt-1.0 >*/
			fknt += static_cast<double>((float)-1.);
/* SOURCE culverta.for:1835 */
/*<       if(fknt.gt.0.0)then >*/
			if (fknt > (float)0.) {
/* SOURCE culverta.for:1836 */
/*<       rovdlm=rbval+fknt*(rbmax-rbval)/8.0 >*/
			    cdcom_1.rovdlm = static_cast<double>(cdcom_1.rbval) + static_cast<double>(static_cast<double>(fknt) * (static_cast<double>(rbmax) - 
				    cdcom_1.rbval)) / (float)8.;
/* SOURCE culverta.for:1837 */
/*<       goto100 >*/
			    goto L100;
/* SOURCE culverta.for:1838 */
/*<       else >*/
			} else {
/*                 No meaningful profile.  Reject type 5 */
/* SOURCE culverta.for:1840 */
/*<       hhtype=6 >*/
			    *hhtype = 6;
/* SOURCE culverta.for:1841 */
/*<       write(stdout,82) >*/
			    feq_gen_io_d__165.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__165);
			    e_wsfe();
/* SOURCE culverta.for:1842 */
/*<       endif >*/
			}
/* SOURCE culverta.for:1843 */
/*<       else >*/
		    } else {
/* SOURCE culverta.for:1844 */
/*<       if(ptypel.eq.'SUP')then >*/
			if (s_cmp(ptypel, const_cast<char*>("SUP"), (ftnlen)8, (ftnlen)3) == 0) {
/* SOURCE culverta.for:1845 */
/*<       if(protyp.eq.'SUP')then >*/
			    if (s_cmp(protyp, const_cast<char*>("SUP"), (ftnlen)8, (ftnlen)3) == 
				    0) {
/*                   The profiles are of like character.   Therefore */
/*                   take the end depth from the enhanced rounding/ */
/*                   beveling as the full-flow-inducing value. */
/* SOURCE culverta.for:1849 */
/*<       y3lim=yendl >*/
				*y3lim = yendl;
/* SOURCE culverta.for:1850 */
/*<       write(stdout,86)y3lim >*/
				feq_gen_io_d__166.ciunit = *stdout;
				s_wsfe(&feq_gen_io_d__166);
				do_fio(&feq_gen_c_d_1, (char *)&(*y3lim), (ftnlen)
					sizeof(real));
				e_wsfe();
/* SOURCE culverta.for:1851 */
/*<       else >*/
			    } else {
/*                   The profiles differ with the enhanced R/B being */
/*                   super critical and the user R/B having a jump. */
/*                   This case may not happen. */
/* SOURCE culverta.for:1855 */
/*<       if(yendl.gt.yend)then >*/
				if (yendl > yend) {
/*                     Use the enhanced R/B ending depth as the limit. */
/* SOURCE culverta.for:1857 */
/*<       y3lim=yendl >*/
				    *y3lim = yendl;
/* SOURCE culverta.for:1858 */
/*<       write(stdout,87)y3lim >*/
				    feq_gen_io_d__167.ciunit = *stdout;
				    s_wsfe(&feq_gen_io_d__167);
				    do_fio(&feq_gen_c_d_1, (char *)&(*y3lim), (ftnlen)
					    sizeof(real));
				    e_wsfe();
/* SOURCE culverta.for:1859 */
/*<       else >*/
				} else {
/*                     Result cannot be used.  Take user value. */
/* SOURCE culverta.for:1861 */
/*<       y3lim=y3limu >*/
				    *y3lim = *y3limu;
/* SOURCE culverta.for:1862 */
/*<       write(stdout,88)yendl,yend,y3lim >*/
				    feq_gen_io_d__168.ciunit = *stdout;
				    s_wsfe(&feq_gen_io_d__168);
				    do_fio(&feq_gen_c_d_1, (char *)&yendl, (ftnlen)
					    sizeof(real));
				    do_fio(&feq_gen_c_d_1, (char *)&yend, (ftnlen)
					    sizeof(real));
				    do_fio(&feq_gen_c_d_1, (char *)&(*y3lim), (ftnlen)
					    sizeof(real));
				    e_wsfe();
/* SOURCE culverta.for:1863 */
/*<       endif >*/
				}
/* SOURCE culverta.for:1864 */
/*<       endif >*/
			    }
/* SOURCE culverta.for:1865 */
/*<       else >*/
			} else {
/*                 The enhanced R/B profile has a jump.  The user R/B */
/*                 profile may or may not have a jump.  If the user R/B */
/*                 profile has a jump and it is higher than the enhanced */
/*                 profile jump, then reject type 5 flow.  Otherwise */
/*                 find the exit depth, greater than critical depth, */
/*                 that yields a close match between the high side of */
/*                 the enhanced R/B profile jump and the high side of */
/*                 the user R/B profile jump.  Note that YHIGH is */
/*                 zero if no jump exists. */
/* SOURCE culverta.for:1875 */
/*<       if(yhigh.gt.yhighl)then >*/
			    if (yhigh > yhighl) {
/*                   Reject type 5. */
/* SOURCE culverta.for:1877 */
/*<       hhtype=6 >*/
				*hhtype = 6;
/* SOURCE culverta.for:1878 */
/*<       write(stdout,89)yhigh,yhighl >*/
				feq_gen_io_d__169.ciunit = *stdout;
				s_wsfe(&feq_gen_io_d__169);
				do_fio(&feq_gen_c_d_1, (char *)&yhigh, (ftnlen)sizeof(
					real));
				do_fio(&feq_gen_c_d_1, (char *)&yhighl, (ftnlen)sizeof(
					real));
				e_wsfe();
/* SOURCE culverta.for:1879 */
/*<       else >*/
			    } else {
/*                   Both remaining cases here because YHIGH= 0 if there */
/*                   is no jump.  Find critical depth at culvert exit. */
/* SOURCE culverta.for:1882 */
/*<       ycat3=0.5*dup >*/
				ycat3 = static_cast<double>(*dup) * (float).5;
/* SOURCE culverta.for:1883 */
/*<       callfndcde(stdout,adrxs3,q5,ycat3) >*/
				fndcde_(stdout, &xs3com_1.adrxs3, &q5, &ycat3)
					;
/* SOURCE culverta.for:1886 */
/*<       yhlim=yhighl >*/
				yhlim = yhighl;
/*                   Establish the initial values for jump high side, */
/*                   YHIGHL, end depth, YENDL, and profile type, PTYPEL. */
/* SOURCE culverta.for:1890 */
/*<        >*/
				locjmp_(stdout, &culcom_1.iat3d, id, &yvc, &
					ycat3, &q5, dup, &ty6ty5, &yhighl, &
					jmploc, &yendl, &ierr, ptypel, (
					ftnlen)8);
/* SOURCE culverta.for:1894 */
/*<       y3max=0.8*dvec(id) >*/
				y3max = static_cast<double>(culcom_1.dvec[*id - 1]) * (float).8;
/* SOURCE culverta.for:1895 */
/*<       fknt=1.0 >*/
				fknt = (float)1.;
/* SOURCE culverta.for:1896 */
/*<   200 continue >*/
L200:
/* SOURCE culverta.for:1897 */
/*<       y3t=ycat3+fknt*(y3max-ycat3)/8.0 >*/
				y3t = static_cast<double>(ycat3) + static_cast<double>(static_cast<double>(fknt) * (static_cast<double>(y3max) - ycat3)) / (float)
					8.;
/* SOURCE culverta.for:1898 */
/*<        >*/
				locjmp_(stdout, &culcom_1.iat3d, id, &yvc, &
					y3t, &q5, dup, &ty6ty5, &yhigh, &
					jmploc, &yend, &ierr, protyp, (ftnlen)
					8);
/* SOURCE culverta.for:1902 */
/*<       if(ierr.ne.0)then >*/
				if (ierr != 0) {
/* SOURCE culverta.for:1903 */
/*<       write(stdout,99) >*/
				    feq_gen_io_d__173.ciunit = *stdout;
				    s_wsfe(&feq_gen_io_d__173);
				    e_wsfe();
/* SOURCE culverta.for:1904 */
/*<       stop'Abnormal stop. Errors found.' >*/
				    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (
					    ftnlen)28);
/* SOURCE culverta.for:1905 */
/*<       endif >*/
				}
/* SOURCE culverta.for:1906 */
/*<       if(protyp.eq.'MIXED'.and.ptypel.eq.'MIXED')then >*/
				if (s_cmp(protyp, const_cast<char*>("MIXED"), (ftnlen)8, (ftnlen)
					5) == 0 && s_cmp(ptypel, const_cast<char*>("MIXED"), (
					ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE culverta.for:1907 */
/*<       if(yhlim.ge.yhighl.and.yhlim.le.yhigh)then >*/
				    if (yhlim >= yhighl && yhlim <= yhigh) {
/*                         Containing interval found.  Interpolate */
/*                         for the end depth and use for the */
/*                         full-flow-inducing value. */
/* SOURCE culverta.for:1911 */
/*<       y3lim=yendl+(yhlim-yhighl)*(yend-yendl)/(yhigh-yhighl) >*/
					*y3lim = static_cast<double>(yendl) + static_cast<double>(static_cast<double>((static_cast<double>(yhlim) - yhighl)) * (
						static_cast<double>(yend) - yendl)) / (static_cast<double>(yhigh) - 
						yhighl);
/* SOURCE culverta.for:1913 */
/*<       write(stdout,90)y3lim >*/
					feq_gen_io_d__174.ciunit = *stdout;
					s_wsfe(&feq_gen_io_d__174);
					do_fio(&feq_gen_c_d_1, (char *)&(*y3lim), (
						ftnlen)sizeof(real));
					e_wsfe();
/* SOURCE culverta.for:1914 */
/*<       goto210 >*/
					goto L210;
/* SOURCE culverta.for:1915 */
/*<       endif >*/
				    }
/* SOURCE culverta.for:1916 */
/*<       endif >*/
				}
/* SOURCE culverta.for:1917 */
/*<       yhighl=yhigh >*/
				yhighl = yhigh;
/* SOURCE culverta.for:1918 */
/*<       ptypel=protyp >*/
				s_copy(ptypel, protyp, (ftnlen)8, (ftnlen)8);
/* SOURCE culverta.for:1919 */
/*<       yendl=yend >*/
				yendl = yend;
/* SOURCE culverta.for:1920 */
/*<       fknt=fknt+1.0 >*/
				fknt += static_cast<double>((float)1.);
/* SOURCE culverta.for:1921 */
/*<       if(fknt.gt.8.0)then >*/
				if (fknt > (float)8.) {
/* SOURCE culverta.for:1922 */
/*<       write(stdout,98) >*/
				    feq_gen_io_d__175.ciunit = *stdout;
				    s_wsfe(&feq_gen_io_d__175);
				    e_wsfe();
/* SOURCE culverta.for:1923 */
/*<       stop'Abnormal stop. Errors found.' >*/
				    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (
					    ftnlen)28);
/* SOURCE culverta.for:1924 */
/*<       endif >*/
				}
/* SOURCE culverta.for:1925 */
/*<       goto200 >*/
				goto L200;
/* SOURCE culverta.for:1926 */
/*<   210 continue >*/
L210:
/* SOURCE culverta.for:1927 */
/*<       endif >*/
				;
			    }
/* SOURCE culverta.for:1928 */
/*<       endif >*/
			}
/* SOURCE culverta.for:1929 */
/*<       endif >*/
		    }
/* SOURCE culverta.for:1930 */
/*<       endif >*/
		}
/* SOURCE culverta.for:1931 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:1932 */
/*<       endif >*/
	}
/* SOURCE culverta.for:1933 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' FHHTYP: on exit: Y3LIM=',Y3LIM, */
/*     A               ' Y3LIMU=',Y3LIMU */
/* SOURCE culverta.for:1936 */
/*<       return >*/
    return 0;
/* SOURCE culverta.for:1937 */
/*<       end >*/
} /* fhhtyp_ */




/* SOURCE culverta.for:1941 */
/*<       subroutinechkdep(stdout,eflag,ftp) >*/
/* Subroutine */ int chkdep_(integer *stdout, integer *eflag, integer *ftp)
{
    /* Format strings */
    static char fmt_50[] = "(/,1x,\002Analysis of the cross section at start\
 of\002,\002 departure reach\002)";
    static char fmt_51[] = "(5x,\002 Width Factor=\002,f8.2)";
    static char fmt_52[] = "(/,1x,\002 Depth in Depth in  Width factor x  Se\
ct. 43  Difference\002,/,1x,\002 sect. 3  sect. 43  culvert width   width\
\002,/,1x,\002 -------- --------  --------------  --------  ----------\002)";
    static char fmt_54[] = "(1x,f9.3,f9.3,6x,f10.3,f10.3,f12.3)";
    static char fmt_56[] = "(/,1x,\002Constructing a cross section that will\
 be wide\002,\002 enough.\002,/,\002 THIS CROSS SECTION SHOULD NOT BE USE\
D\002,\002 FOR FINAL RESULTS.\002,/,\002 You must review the departure\002\
,\002 cross section you have supplied\002,/,\002 and make informed\002,\002 \
adjustments to it to satisfy CULVERT.\002,/,\002 DO NOT\002,\002 RELIE ON TH\
E AUTOMATIC ADJUSTMENT MADE BY CULVERT.\002,/,\002 CULVERT forces a rectangu\
lar section with a width\002,\002 of WIDFAC times the\002,/,\002 maximum hor\
izontal barrel\002,\002 opening.  This section is extended\002,/,\002 vertic\
ally\002,\002 until the supplied departure cross section has\002,/,\002 a wi\
dth that exceeds the width of the rectangular\002,\002 section.\002,//,\002 \
The adjusted table has alpha and beta\002,\002 set to 1.0,\002/,\002 the cri\
tical flow is computed from\002,\002 A*SQRT(gA/T), the conveyance is ignored,\
\002/,\002 and the\002,\002 area and first moment of area are recomputed.\
\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1, feq_gen_r_d_2;
    cilist feq_gen_ci_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(), do_fio(integer *, char *, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    integer feq_gen_i_d_;
    real t, y;
    integer ie;
    doublereal hh;
    real qc;
    integer is, adr;
    extern /* Subroutine */ int kil_(integer *, integer *, integer *);
    integer feq_gen_flag_d_;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    doublereal aold;
    real mxa43, told;
    doublereal asum;
    real yold, tmax;
    doublereal jsum;
    integer feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    integer xoff3, space, xoff43;
    extern doublereal fmxarg_(integer *);
    extern /* Subroutine */ int xlktal_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__179 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__180 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__181 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__190 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__191 = { 0, 0, 0, fmt_56, 0 };


/*     + + + PURPOSE + + + */
/*     Check the cross section at section 43 against the cross section */
/*     at the culvert exit.  Section 43 must be at least a factor */
/*     of WIDFAC greater than the culvert exit section.  If it is */
/*     not, construct one that is and give the user a graphic warning */
/*     message. */
/* SOURCE culverta.for:1952 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culverta.for:1955 */
/*<       integereflag,ftp,stdout >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     FTP    - next open location in the function table storage */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culverta.for:1963 */
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
/* INCLUDE culverta.for:1964 */
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
/* INCLUDE culverta.for:1965 */
/* SOURCE x43com.cmn:2 */
/*<        >*/
/* SOURCE x43com.cmn:6 */
/*<       integeradrs43,stat43 >*/
/* SOURCE x43com.cmn:8 */
/*<        >*/
/* INCLUDE culverta.for:1966 */
/* SOURCE depcom.cmn:2 */
/*<       common/depcom/deptab,begtab,depelv,begelv,widfac,dsffac,deptyp >*/
/* SOURCE depcom.cmn:5 */
/*<       integerdeptab,begtab,deptyp >*/
/* SOURCE depcom.cmn:7 */
/*<       realdepelv,begelv,widfac,dsffac >*/
/* INCLUDE culverta.for:1967 */
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
/* INCLUDE culverta.for:1968 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culverta.for:1969 */
/*     COMMON BLOCK FOR OFFSETS FOR CROSS SECTION TABLES */
/* SOURCE offcom.cmn:3 */
/*<       common/offcom/offvec >*/
/* SOURCE offcom.cmn:5 */
/*<       integeroffvec(35) >*/
/* SOURCE offcom.cmn:7 */
/*<       save/offcom/ >*/
/*     INITIALIZED IN A BLOCK DATA UNIT AS REQUIRED BY FORTRAN */
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE culverta.for:1972 */
/*<       integerxoff22 >*/
/* SOURCE culverta.for:1973 */
/*<       parameter(xoff22=8) >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culverta.for:1976 */
/*<       integeradr,flag,i,ie,is,space,type,xoff3,xoff43 >*/
/* SOURCE culverta.for:1977 */
/*<       realmxa43,qc,t,tmax,told,y,yold >*/
/* SOURCE culverta.for:1978 */
/*<       doubleprecisionaold,asum,hh,jsum >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culverta.for:1981 */
/*<       intrinsicdble,max,sqrt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culverta.for:1984 */
/*<       realfmxarg >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culverta.for:1987 */
/*<       externalfmxarg,kil,xlktal >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culverta.for:1990 */
/*<    50  >*/
/* SOURCE culverta.for:1992 */
/*<    51 format(5x,' Width Factor=',f8.2) >*/
/* SOURCE culverta.for:1993 */
/*<    52  >*/
/* SOURCE culverta.for:1997 */
/*<    54 format(1x,f9.3,f9.3,6x,f10.3,f10.3,f12.3) >*/
/* SOURCE culverta.for:1998 */
/*<    56  >*/
/* *********************************************************************** */
/* SOURCE culverta.for:2014 */
/*<       write(stdout,50) >*/
/* L50: */
/* L51: */
/* L52: */
/* L54: */
/* L56: */
    feq_gen_io_d__179.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__179);
    e_wsfe();
/* SOURCE culverta.for:2015 */
/*<       write(stdout,51)widfac >*/
    feq_gen_io_d__180.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__180);
    do_fio(&feq_gen_c_d_1, (char *)&depcom_1.widfac, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE culverta.for:2016 */
/*<       write(stdout,52) >*/
    feq_gen_io_d__181.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__181);
    e_wsfe();
/*     FIND MAX ARGUMENT IN SECTION 43 */
/* SOURCE culverta.for:2020 */
/*<       mxa43=fmxarg(adrs43) >*/
    mxa43 = fmxarg_(&x43com_1.adrs43);
/* SOURCE culverta.for:2021 */
/*<       type=itab(adrs43+2) >*/
    feq_gen_type_d_ = itab[x43com_1.adrs43 + 2];
/* SOURCE culverta.for:2022 */
/*<       xoff43=offvec(type) >*/
    xoff43 = offcom_1.offvec[feq_gen_type_d_ - 1];
/* SOURCE culverta.for:2023 */
/*<       xoff3=offvec(itab(adrxs3+2)) >*/
    xoff3 = offcom_1.offvec[itab[xs3com_1.adrxs3 + 2] - 1];
/*     FOR EACH DEPTH TABULATED AT SECTION 3, CHECK THE TOP WIDTH */
/*     IN SECTION 43. DELETE THE LAST DEPTH SINCE THAT REPRESENTS THE */
/*     TOP OF THE SLOT IN THE CURRENT FEQUTL.  INCLUDE CHECK AGAINST */
/*     MAX ARGUMENT TO PREVENT ERRORS USING OLD FORM OF CLOSED */
/*     CONDUIT TABLES WHICH HAVE MORE THAN 2 ARGUMENTS IN THE SLOT. */
/*     Get the address of the first argument of the table at section 3 */
/* SOURCE culverta.for:2032 */
/*<       is=adrxs3+xtioff >*/
    is = xs3com_1.adrxs3 + 32;
/*     Get the address of the last argument of the table at section 3 */
/* SOURCE culverta.for:2034 */
/*<       itmp=itab(adrxs3) >*/
    ftablea_1.itmp = itab[xs3com_1.adrxs3];
/* SOURCE culverta.for:2035 */
/*<       ie=itmp-xoff3 >*/
    ie = ftablea_1.itmp - xoff3;
/* SOURCE culverta.for:2036 */
/*<       flag=0 >*/
    feq_gen_flag_d_ = 0;
/* SOURCE culverta.for:2037 */
/*<       do100i=is,ie,xoff3 >*/
    feq_gen_i_d_1 = ie;
    feq_gen_i_d_2 = xoff3;
    for (feq_gen_i_d_ = is; feq_gen_i_d_2 < 0 ? feq_gen_i_d_ >= feq_gen_i_d_1 : feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += feq_gen_i_d_2) {
/* SOURCE culverta.for:2038 */
/*<       y3=ftab(i) >*/
	xs3com_1.y3 = ftab[feq_gen_i_d_];
/* SOURCE culverta.for:2039 */
/*<       t3=widfac*ftab(i+1) >*/
	xs3com_1.t3 = static_cast<double>(depcom_1.widfac) * ftab[feq_gen_i_d_ + 1];
/* SOURCE culverta.for:2040 */
/*<       y43=y3+zb3-zb43 >*/
	x43com_1.y43 = static_cast<double>(static_cast<double>(xs3com_1.y3) + xs3com_1.zb3) - x43com_1.zb43;
/* SOURCE culverta.for:2041 */
/*<       if(y43.lt.0.0)y43=0.0 >*/
	if (x43com_1.y43 < (float)0.) {
	    x43com_1.y43 = (float)0.;
	}
/* SOURCE culverta.for:2042 */
/*<       if(y43.gt.mxa43)goto100 >*/
	if (x43com_1.y43 > mxa43) {
	    goto L100;
	}
/* SOURCE culverta.for:2043 */
/*<        >*/
	xlktal_(&x43com_1.adrs43, &x43com_1.y43, &x43com_1.a43, &x43com_1.t43,
		 &x43com_1.dt43, &x43com_1.j43, &x43com_1.k43, &x43com_1.dk43,
		 &x43com_1.bet43, &x43com_1.dbet43, &x43com_1.alp43, &
		x43com_1.dalp43);
/* SOURCE culverta.for:2048 */
/*<       write(stdout,54)y3,y43,t3,t43,t3-t43 >*/
	feq_gen_io_d__190.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__190);
	do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.y3, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&x43com_1.y43, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&xs3com_1.t3, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&x43com_1.t43, (ftnlen)sizeof(real));
	feq_gen_r_d_1 = static_cast<double>(xs3com_1.t3) - x43com_1.t43;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culverta.for:2050 */
/*<       if(0.9999*t3.gt.t43)then >*/
	if (static_cast<double>(xs3com_1.t3) * (float).9999 > x43com_1.t43) {
/*         CROSS SECTION 43 IS TOO NARROW at this elevation */
/* SOURCE culverta.for:2052 */
/*<       flag=1 >*/
	    feq_gen_flag_d_ = 1;
/* SOURCE culverta.for:2053 */
/*<       endif >*/
	}
/* SOURCE culverta.for:2054 */
/*<   100 continue >*/
L100:
	;
    }
/* SOURCE culverta.for:2056 */
/*<       if(flag.eq.0)then >*/
    if (feq_gen_flag_d_ == 0) {
/*       TABLE 43 IS OK */
/* SOURCE culverta.for:2058 */
/*<       write(stdout,'(/,A)')' BEGTAB accepted.' >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(/,A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, const_cast<char*>(" BEGTAB accepted."), (ftnlen)17);
	e_wsfe();
/* SOURCE culverta.for:2059 */
/*<       return >*/
	return 0;
/* SOURCE culverta.for:2060 */
/*<       else >*/
    } else {
/* SOURCE culverta.for:2061 */
/*<       write(stdout,'(/,A)')' BEGTAB rejected as too narrow.' >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(/,A)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, const_cast<char*>(" BEGTAB rejected as too narrow."), (ftnlen)31);
	e_wsfe();
/* SOURCE culverta.for:2062 */
/*<       write(stdout,56) >*/
	feq_gen_io_d__191.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__191);
	e_wsfe();
/*       BEGTAB REJECTED */
/*       FIND MAX WIDTH AT THE EXIT OF THE CULVERT */
/* SOURCE culverta.for:2067 */
/*<       tmax=0.0 >*/
	tmax = (float)0.;
/* SOURCE culverta.for:2068 */
/*<       do120i=is,ie,xoff3 >*/
	feq_gen_i_d_2 = ie;
	feq_gen_i_d_1 = xoff3;
	for (feq_gen_i_d_ = is; feq_gen_i_d_1 < 0 ? feq_gen_i_d_ >= feq_gen_i_d_2 : feq_gen_i_d_ <= feq_gen_i_d_2; feq_gen_i_d_ += feq_gen_i_d_1) {
/* SOURCE culverta.for:2069 */
/*<       tmax=max(tmax,ftab(i+1)) >*/
/* Computing MAX */
	    feq_gen_r_d_1 = tmax, feq_gen_r_d_2 = ftab[feq_gen_i_d_ + 1];
	    tmax = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE culverta.for:2070 */
/*<   120 continue >*/
/* L120: */
	}
/*       INCREASE TMAX */
/* SOURCE culverta.for:2074 */
/*<       tmax=tmax*widfac >*/
	tmax *= depcom_1.widfac;
/*       Construct a table and store in temporary part of the */
/*       function table system. */
/* SOURCE culverta.for:2079 */
/*<       adr=ftp >*/
	adr = *ftp;
/*       Construct the table by copying the depths and top widths */
/*       from the user supplied table.  Replace each width that */
/*       is not at least as wide as TMAX. */
/* SOURCE culverta.for:2085 */
/*<       is=adrs43+xtioff >*/
	is = x43com_1.adrs43 + 32;
/* SOURCE culverta.for:2086 */
/*<       ie=itab(adrs43) >*/
	ie = itab[x43com_1.adrs43];
/* SOURCE culverta.for:2087 */
/*<       space=i+xoff43-adrs43 >*/
	space = feq_gen_i_d_ + xoff43 - x43com_1.adrs43;
/* SOURCE culverta.for:2089 */
/*<       if(adr+space.gt.mrftab)callkil(10,adr,eflag) >*/
	if (adr + space > 13000001) {
	    kil_(&feq_gen_c_d_10, &adr, eflag);
	}
/*       Use the same table number again. */
/* SOURCE culverta.for:2094 */
/*<       ftab(adr+1)=ftab(adrs43+1) >*/
	ftab[adr + 1] = ftab[x43com_1.adrs43 + 1];
/* SOURCE culverta.for:2095 */
/*<       itab(adr+2)=22 >*/
	itab[adr + 2] = 22;
/* SOURCE culverta.for:2096 */
/*<       itab(adr+3)=adr+xtioff >*/
	itab[adr + 3] = adr + 32;
/* SOURCE culverta.for:2097 */
/*<       ftab(adr+4)=0.0 >*/
	ftab[adr + 4] = (float)0.;
/* SOURCE culverta.for:2098 */
/*<       ftab(adr+5)=begelv >*/
	ftab[adr + 5] = depcom_1.begelv;
/* SOURCE culverta.for:2099 */
/*<       ftab(adr+6)=ftab(adrs43+5) >*/
	ftab[adr + 6] = ftab[x43com_1.adrs43 + 5];
/* SOURCE culverta.for:2100 */
/*<       itab(adr+21)=0 >*/
	itab[adr + 21] = 0;
/* SOURCE culverta.for:2101 */
/*<       adr=adr+xtioff >*/
	adr += 32;
/*       Do the zero depth row. */
/* SOURCE culverta.for:2104 */
/*<       yold=ftab(is) >*/
	yold = ftab[is];
/* SOURCE culverta.for:2105 */
/*<       told=ftab(is+1) >*/
	told = ftab[is + 1];
/* SOURCE culverta.for:2106 */
/*<       if(told.lt.tmax)told=tmax >*/
	if (told < tmax) {
	    told = tmax;
	}
/* SOURCE culverta.for:2107 */
/*<       ftab(adr)=yold >*/
	ftab[adr] = yold;
/* SOURCE culverta.for:2108 */
/*<       ftab(adr+1)=told >*/
	ftab[adr + 1] = told;
/* SOURCE culverta.for:2109 */
/*<       do190i=2,7 >*/
	for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= 7; ++feq_gen_i_d_) {
/* SOURCE culverta.for:2110 */
/*<       ftab(adr+i)=0.0 >*/
	    ftab[adr + feq_gen_i_d_] = (float)0.;
/* SOURCE culverta.for:2111 */
/*<   190 continue >*/
/* L190: */
	}
/* SOURCE culverta.for:2112 */
/*<       ftab(adr+4)=1.0 >*/
	ftab[adr + 4] = (float)1.;
/* SOURCE culverta.for:2113 */
/*<       ftab(adr+6)=1.0 >*/
	ftab[adr + 6] = (float)1.;
/* SOURCE culverta.for:2114 */
/*<       asum=0.d0 >*/
	asum = 0.;
/* SOURCE culverta.for:2115 */
/*<       jsum=0.d0 >*/
	jsum = 0.;
/* SOURCE culverta.for:2116 */
/*<       aold=0.d0 >*/
	aold = 0.;
/* SOURCE culverta.for:2118 */
/*<       adr=adr+xoff22 >*/
	adr += 8;
/* SOURCE culverta.for:2119 */
/*<       is=is+xoff43 >*/
	is += xoff43;
/* SOURCE culverta.for:2120 */
/*<       do200i=is,ie,xoff43 >*/
	feq_gen_i_d_1 = ie;
	feq_gen_i_d_2 = xoff43;
	for (feq_gen_i_d_ = is; feq_gen_i_d_2 < 0 ? feq_gen_i_d_ >= feq_gen_i_d_1 : feq_gen_i_d_ <= feq_gen_i_d_1; feq_gen_i_d_ += feq_gen_i_d_2) {
/* SOURCE culverta.for:2121 */
/*<       y=ftab(i) >*/
	    y = ftab[feq_gen_i_d_];
/* SOURCE culverta.for:2122 */
/*<       t=ftab(i+1) >*/
	    t = ftab[feq_gen_i_d_ + 1];
/* SOURCE culverta.for:2123 */
/*<       if(t.lt.tmax)t=tmax >*/
	    if (t < tmax) {
		t = tmax;
	    }
/* SOURCE culverta.for:2124 */
/*<       hh=0.5d0*dble(y-yold) >*/
	    hh = (doublereal) (static_cast<double>(y) - yold) * .5;
/* SOURCE culverta.for:2125 */
/*<       asum=asum+hh*dble(t+told) >*/
	    asum += hh * (doublereal) (static_cast<double>(t) + told);
/* SOURCE culverta.for:2126 */
/*<       jsum=jsum+hh*((asum+aold)-hh*dble(t-told)/3.d0) >*/
	    jsum += hh * (asum + aold - hh * (doublereal) (static_cast<double>(t) - told) / 3.);
/* SOURCE culverta.for:2129 */
/*<       qc=asum*sqrt(grav*asum/t) >*/
	    qc = asum * sqrt(grvcom_1.grav * asum / t);
/*         Now store the values */
/* SOURCE culverta.for:2132 */
/*<       ftab(adr)=y >*/
	    ftab[adr] = y;
/* SOURCE culverta.for:2133 */
/*<       ftab(adr+1)=t >*/
	    ftab[adr + 1] = t;
/* SOURCE culverta.for:2134 */
/*<       ftab(adr+2)=asum >*/
	    ftab[adr + 2] = asum;
/* SOURCE culverta.for:2135 */
/*<       ftab(adr+3)=100. >*/
	    ftab[adr + 3] = (float)100.;
/* SOURCE culverta.for:2136 */
/*<       ftab(adr+4)=1.0 >*/
	    ftab[adr + 4] = (float)1.;
/* SOURCE culverta.for:2137 */
/*<       ftab(adr+5)=jsum >*/
	    ftab[adr + 5] = jsum;
/* SOURCE culverta.for:2138 */
/*<       ftab(adr+6)=1.0 >*/
	    ftab[adr + 6] = (float)1.;
/* SOURCE culverta.for:2139 */
/*<       ftab(adr+7)=qc >*/
	    ftab[adr + 7] = qc;
/* SOURCE culverta.for:2141 */
/*<       aold=asum >*/
	    aold = asum;
/* SOURCE culverta.for:2142 */
/*<       told=t >*/
	    told = t;
/* SOURCE culverta.for:2143 */
/*<       yold=y >*/
	    yold = y;
/* SOURCE culverta.for:2144 */
/*<       adr=adr+xoff22 >*/
	    adr += 8;
/* SOURCE culverta.for:2145 */
/*<   200 continue >*/
/* L200: */
	}
/*       Put address of last argument in the first element. */
/* SOURCE culverta.for:2147 */
/*<       itab(ftp)=adr-xoff22 >*/
	itab[*ftp] = adr - 8;
/* SOURCE culverta.for:2148 */
/*<       adr=adr+xoff22 >*/
	adr += 8;
/* SOURCE culverta.for:2150 */
/*<       adrs43=ftp >*/
	x43com_1.adrs43 = *ftp;
/* SOURCE culverta.for:2151 */
/*<       ftp=adr >*/
	*ftp = adr;
/* SOURCE culverta.for:2152 */
/*<       endif >*/
    }
/* SOURCE culverta.for:2154 */
/*<       return >*/
    return 0;
/* SOURCE culverta.for:2155 */
/*<       end >*/
} /* chkdep_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE culverta.for:2159 */
/*<       subroutinefdcd46(stdout,culcls,rbv,cdis) >*/
/* Subroutine */ int fdcd46_(integer *stdout, char *culcls, real *rbv, real *
	cdis, ftnlen culcls_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *BUG:XXX* Culvert class=\002,a8,\002 unk\
nown in FDCD46.\002)";

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    real df;
    integer ntab;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__206 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Find the discharge coefficient for flow types 4 and 6 */
/* SOURCE culverta.for:2166 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culverta.for:2169 */
/*<       integerstdout >*/
/* SOURCE culverta.for:2170 */
/*<       realcdis,rbv >*/
/* SOURCE culverta.for:2171 */
/*<       characterculcls*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     CULCLS - Class for culvert shape, BOX, PIPE, .. */
/*     RBV    - rounding/beveling value */
/*     CDIS   - discharge coefficient */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culverta.for:2180 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culverta.for:2183 */
/*<       integerntab >*/
/* SOURCE culverta.for:2184 */
/*<       realdf >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culverta.for:2187 */
/*<       externallktab >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culverta.for:2190 */
/*<    50 format(/,' *BUG:XXX* Culvert class=',a8,' unknown in FDCD46.') >*/
/* *********************************************************************** */
/* SOURCE culverta.for:2192 */
/*<       if(culcls.eq.'BOX')then >*/
/* L50: */
    if (s_cmp(culcls, const_cast<char*>("BOX"), (ftnlen)8, (ftnlen)3) == 0) {
/* SOURCE culverta.for:2193 */
/*<       if(wwangl.eq.0.0)then >*/
	if (cdcom_1.wwangl == (float)0.) {
/* SOURCE culverta.for:2194 */
/*<       calllktab(tb5adr,rbv,1,cdis,ntab,df) >*/
	    lktab_(&cdcom_1.tb5adr, rbv, &feq_gen_c_d_1, cdis, &ntab, &df);
/* SOURCE culverta.for:2197 */
/*<       else >*/
	} else {
/* SOURCE culverta.for:2198 */
/*<       if(rbv.eq.0.0)then >*/
	    if (*rbv == (float)0.) {
/* SOURCE culverta.for:2199 */
/*<       if(wwangl.le.30.0)then >*/
		if (cdcom_1.wwangl <= (float)30.) {
/*             Interpolate between .84 and .87 */
/* SOURCE culverta.for:2201 */
/*<       cdis=0.84+0.001*wwangl >*/
		    *cdis = static_cast<double>(static_cast<double>(cdcom_1.wwangl) * (float).001) + (float).84;
/* SOURCE culverta.for:2202 */
/*<       elseif(wwangl.le.75.0)then >*/
		} else if (cdcom_1.wwangl <= (float)75.) {
/* SOURCE culverta.for:2203 */
/*<       cdis=0.87 >*/
		    *cdis = (float).87;
/* SOURCE culverta.for:2204 */
/*<       else >*/
		} else {
/* SOURCE culverta.for:2205 */
/*<       cdis=.87-0.008*(wwangl-75.0) >*/
		    *cdis = static_cast<double>((float).87) - static_cast<double>((static_cast<double>(cdcom_1.wwangl) - (float)75.)) * (
			    float).008;
/* SOURCE culverta.for:2206 */
/*<       endif >*/
		}
/* SOURCE culverta.for:2207 */
/*<       else >*/
	    } else {
/* SOURCE culverta.for:2208 */
/*<       if(wwangl.le.30.0)then >*/
		if (cdcom_1.wwangl <= (float)30.) {
/* SOURCE culverta.for:2209 */
/*<       cdis=.84+0.001*wwangl >*/
		    *cdis = static_cast<double>(static_cast<double>(cdcom_1.wwangl) * (float).001) + (float).84;
/* SOURCE culverta.for:2210 */
/*<       cdis=krb*cdis >*/
		    *cdis = static_cast<double>(cdcom_1.krb) * *cdis;
/* SOURCE culverta.for:2211 */
/*<       elseif(wwangl.le.75.0)then >*/
		} else if (cdcom_1.wwangl <= (float)75.) {
/* SOURCE culverta.for:2212 */
/*<       calllktab(tb5adr,rbv,1,cdis,ntab,df) >*/
		    lktab_(&cdcom_1.tb5adr, rbv, &feq_gen_c_d_1, cdis, &ntab, &df);
/* SOURCE culverta.for:2215 */
/*<       if(cdis.lt.0.87)cdis=0.87 >*/
		    if (*cdis < (float).87) {
			*cdis = (float).87;
		    }
/* SOURCE culverta.for:2216 */
/*<       else >*/
		} else {
/* SOURCE culverta.for:2217 */
/*<       cdis=.87-0.008*(wwangl-75.0) >*/
		    *cdis = static_cast<double>((float).87) - static_cast<double>((static_cast<double>(cdcom_1.wwangl) - (float)75.)) * (
			    float).008;
/* SOURCE culverta.for:2218 */
/*<       cdis=krb*cdis >*/
		    *cdis = static_cast<double>(cdcom_1.krb) * *cdis;
/* SOURCE culverta.for:2219 */
/*<       endif >*/
		}
/* SOURCE culverta.for:2220 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:2221 */
/*<       endif >*/
	}
/* SOURCE culverta.for:2222 */
/*<       elseif(culcls.eq.'PIPE')then >*/
    } else if (s_cmp(culcls, const_cast<char*>("PIPE"), (ftnlen)8, (ftnlen)4) == 0) {
/* SOURCE culverta.for:2223 */
/*<       calllktab(tb5adr,rbv,1,cdis,ntab,df) >*/
	lktab_(&cdcom_1.tb5adr, rbv, &feq_gen_c_d_1, cdis, &ntab, &df);
/* SOURCE culverta.for:2226 */
/*<       cdis=kproj*cdis >*/
	*cdis = static_cast<double>(cdcom_1.kproj) * *cdis;
/* SOURCE culverta.for:2227 */
/*<       elseif(culcls.eq.'MITER')then >*/
    } else if (s_cmp(culcls, const_cast<char*>("MITER"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE culverta.for:2228 */
/*<       cdis=kproj*0.74 >*/
	*cdis = static_cast<double>(cdcom_1.kproj) * (float).74;
/* SOURCE culverta.for:2229 */
/*<       elseif(culcls.eq.'FLARED')then >*/
    } else if (s_cmp(culcls, const_cast<char*>("FLARED"), (ftnlen)8, (ftnlen)6) == 0) {
/* SOURCE culverta.for:2230 */
/*<       cdis=0.90 >*/
	*cdis = (float).9;
/* SOURCE culverta.for:2231 */
/*<       elseif(culcls.eq.'RCPTG')then >*/
    } else if (s_cmp(culcls, const_cast<char*>("RCPTG"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE culverta.for:2232 */
/*<       calllktab(tb5adr,rbv,1,cdis,ntab,df) >*/
	lktab_(&cdcom_1.tb5adr, rbv, &feq_gen_c_d_1, cdis, &ntab, &df);
/*        CDIS = 0.95 */
/* SOURCE culverta.for:2236 */
/*<       else >*/
    } else {
/* SOURCE culverta.for:2237 */
/*<       write(stdout,50)culcls >*/
	feq_gen_io_d__206.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__206);
	do_fio(&feq_gen_c_d_1, culcls, (ftnlen)8);
	e_wsfe();
/* SOURCE culverta.for:2238 */
/*<       endif >*/
    }
/* SOURCE culverta.for:2239 */
/*<       if(cdis.gt.1.0)then >*/
    if (*cdis > (float)1.) {
/* SOURCE culverta.for:2240 */
/*<       cdis=0.98 >*/
	*cdis = (float).98;
/* SOURCE culverta.for:2241 */
/*<       endif >*/
    }
/* SOURCE culverta.for:2242 */
/*<       cd=cdis >*/
    cdcom_1.cd = *cdis;
/* SOURCE culverta.for:2243 */
/*<       return >*/
    return 0;
/* SOURCE culverta.for:2244 */
/*<       end >*/
} /* fdcd46_ */




/* SOURCE culverta.for:2248 */
/*<        >*/
/* Subroutine */ int clvin_(real *sfac, integer *stdin, integer *stdout, 
	integer *mnbn, integer *nbra, char *nodeid, integer *mftnum, integer *
	mrftab, integer *feq_storage_ftpnt, integer *typflg, integer *eflag, integer *
	ftknt, integer *ftp, integer *nbn, integer *feq_storage_brpt, integer *feq_storage_nsec, real 
	*feq_storage_xvec, real *feq_storage_zbvec, real *feq_storage_ka, real *feq_storage_kd, integer *feq_storage_hltab, char *feq_storage_bnodid, 
	integer *feq_storage_negtab, integer *chkbar, integer *iat3d, integer *iat6d, 
	integer *bshape, integer *sbkind, ftnlen nodeid_len, ftnlen 
	bnodid_len)
{
    /* Format strings */
    static char fmt_1[] = "(a80)";
    static char fmt_18[] = "(\002 \002,i6,1x,a8,1x,a,f10.3,f10.3,2f5.2,a)";
    static char fmt_50[] = "(\002 *ERR:108* CROSS SECTION TABLE NUMBER MUST \
BE > 0\002,\002 AT FIRST NODE ON BRANCH\002)";
    static char fmt_52[] = "(/,\002 Culvert barrel length <= 3 times its ver\
tical\002,\002 diameter.  Culvert losses\002,/,\002  will be overestimated\
.\002)";
    static char fmt_54[] = "(/,\002 Culvert barrel length <= 6 times its ver\
tical\002,\002 diameter.  Culvert losses\002,/,\002  may be overestimated\
.\002)";
    static char fmt_56[] = "(/,\002 FEQUTL will use\002,i4,\002 nodes for th\
e culvert barrel.\002)";
    static char fmt_84[] = "(\002   Node  Node Id\002,a,\002TabId    Station\
 Elevation\002,\002   KA   KD\002,a,\002HL Id\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[10], feq_gen_ch_d_2[16];
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rsfi(icilist *), do_fio(integer *, char *, ftnlen), e_rsfi(), 
	    s_cmp(char *, char *, ftnlen, ftnlen), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *), e_wsfe();
    double log(doublereal), exp(doublereal);

    /* Local variables */
    integer feq_gen_item_end_d_[8];
    real feq_gen_d_d_;
    integer feq_gen_i_d_, j, k, n;
    real x, feq_gen_z_d_;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real ca, cd;
    integer hl;
    real dx;
    integer it;
    real dz, xl, xr;
    integer feq_gen_item_start_d_[8];
    real fac;
    extern /* Subroutine */ int feq_gen_read_culvert_items_d_(integer *, char *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, char *, char *, char *, char *, real *, real *, 
	    integer *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen), kil_(integer *
	    , integer *, integer *);
    char head[120], feq_gen_name_d_[8];
    extern doublereal getd_(integer *, integer *);
    extern /* Subroutine */ int scan_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, real *
	    , integer *, integer *, integer *);
    integer node;
    char line[120];
    integer nhat;
    real elev;
    integer xtab;
    real fint;
    integer bnum, last;
    real stdl, stat, stdr;
    char just[5], tabid[16];
    real dxfac;
    char blank[16];
    integer pflag, idlen, lnode;
    char xchar[10], zchar[10], tempc[16];
    integer lxtab;
    char xtabn[5];
    integer first;
    real statl;
    integer jzero;
    real statr;
    extern /* Subroutine */ int chktab_(integer *, integer *, integer *, 
	    integer *, integer *, integer *), fndelv_(integer *, integer *, 
	    integer *, real *), fndsta_(integer *, integer *, integer *, real 
	    *), inline_(integer *, integer *, char *, ftnlen);
    real clvlen, loverd;
    extern /* Character */ VOID gettok_(char *, ftnlen, char *, ftnlen);
    extern /* Subroutine */ int mkxvec_(real *, real *, integer *, real *, 
	    integer *, integer *);
    extern integer lenstr_(char *, ftnlen);
    real sdxovl;
    char hltabid[16];
    integer hlidlen;
    extern /* Subroutine */ int feq_gen_get_item_limits_d_(integer *, char *, integer *
	    , char *, integer *, integer *, integer *, ftnlen, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__221 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__231 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__241 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__242 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__243 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__261 = { 0, 0, 0, fmt_84, 0 };
    static cilist feq_gen_io_d__265 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__266 = { 0, 0, 0, fmt_18, 0 };
    static cilist feq_gen_io_d__267 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__268 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Input the culvert conduit description.  Similar to a regular */
/*     branch in FEQ but with fewer options */
/* SOURCE culverta.for:2260 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culverta.for:2262 */
/*<        >*/
/* SOURCE culverta.for:2264 */
/*<        >*/
/* SOURCE culverta.for:2266 */
/*<       realka(mnbn),kd(mnbn),sfac,xvec(mnbn),zbvec(mnbn) >*/
/* SOURCE culverta.for:2267 */
/*<       characterbnodid(mnbn)*8,nodeid*4 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     SFAC   - Scale factor for stations */
/*     STDIN     - Fortran unit number for user input file */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     MNBN   - Maximum number of nodes on branches */
/*     NBRA   - Number of branches */
/*     NODEID - Descriptor string for the culvert barrel nodes */
/*     MFTNUM - Maximum allowed table number */
/*     MRFTAB - maximum length of FTAB/ITAB */
/*     FTPNT  - function table pointer giving the table address for each */
/*              table number.  If the address is zero the table does not */
/*              exist. */
/*     TYPFLG - If TYPFLG=0 then any cross section table type is */
/*               adequate; else at least equivalent of old type 12 */
/*               (new type 22) must be supplied.  TYPFLG = 1 when called */
/*               from CULVRT and TYPFLG=0 when called from from XSTMAK. */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     FTKNT  - function table counter */
/*     FTP    - next open location in the function table storage */
/*     NBN    - Number of nodes on branches */
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
/*     NSEC   - Table number for cross section at the node */
/*     XVEC   - Stations for nodes on culvert barrel */
/*     ZBVEC  - Bottom elevations at nodes for culvert barrel */
/*     KA     - Acceleration loss. */
/*     KD     - Deceleration loss. */
/*     HLTAB  - Point head loss table number */
/*     BNODID - Id string for nodes on culvert barrel */
/*     NEGTAB - Memory for negative table ids given explicitly by the */
/*              user.  Interpolation requests given with a single - */
/*              generate a special negative internal number that is NOT */
/*              counted as a negative table id for NEGTAB. */
/*     CHKBAR - flag, if 1, requests checking user node assignments */
/*     IAT3D  - index to vena contracta location */
/*     IAT6D  - index to vena contracta location */
/*     BSHAPE - barrel shape: 0-prismatic, 1-nonprismatic */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culverta.for:2316 */
/*<       integermaxn >*/
/* SOURCE culverta.for:2317 */
/*<       parameter(maxn=8) >*/
/* SOURCE culverta.for:2318 */
/*<        >*/
/* SOURCE culverta.for:2322 */
/*<        >*/
/* SOURCE culverta.for:2325 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culverta.for:2329 */
/*<       intrinsicabs,exp,float,log >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culverta.for:2332 */
/*<       integerlenstr >*/
/* SOURCE culverta.for:2333 */
/*<       realgetd >*/
/* SOURCE culverta.for:2334 */
/*<       charactergettok*10,get_tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culverta.for:2337 */
/*<        >*/
/*     + + + INPUT FORMATS + + + */
/* SOURCE culverta.for:2342 */
/*<     1 format(a80) >*/
/* SOURCE culverta.for:2343 */
/*<    13 format(i5,a5,2a10,2f5.0,i5) >*/
/* SOURCE culverta.for:2344 */
/*<    16 format(i5,1x,a8,1x,a5,2a10,2f5.0,i5) >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culverta.for:2347 */
/*<    11 format(/,' ',a80) >*/
/* SOURCE culverta.for:2348 */
/*<    14 format(' ',i5,a5,f10.3,f10.3,2f5.2,i5) >*/
/* SOURCE culverta.for:2349 */
/*<    18 format(' ',i6,1x,a8,1x,a,f10.3,f10.3,2f5.2,a) >*/
/* SOURCE culverta.for:2350 */
/*<    50  >*/
/* SOURCE culverta.for:2352 */
/*<    52  >*/
/* SOURCE culverta.for:2354 */
/*<    54  >*/
/* SOURCE culverta.for:2356 */
/*<    56 format(/,' FEQUTL will use',i4,' nodes for the culvert barrel.') >*/
/* SOURCE culverta.for:2357 */
/*<    84  >*/
/* *********************************************************************** */
/* SOURCE culverta.for:2360 */
/*<       dxfac=0.1 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> negtab(feq_storage_negtab, 1);

    feq::IndexedPointer<char> bnodid(feq_storage_bnodid, 8);

    feq::IndexedPointer<integer> hltab(feq_storage_hltab, 1);

    feq::IndexedPointer<real> kd(feq_storage_kd, 1);

    feq::IndexedPointer<real> ka(feq_storage_ka, 1);

    feq::IndexedPointer<real> zbvec(feq_storage_zbvec, 1);

    feq::IndexedPointer<real> xvec(feq_storage_xvec, 1);

    feq::IndexedPointer<integer> nsec(feq_storage_nsec, 1);

    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> ftpnt(feq_storage_ftpnt, 1);

    /* Function Body */
/* L1: */
/* L13: */
/* L16: */
/* L11: */
/* L14: */
/* L18: */
/* L50: */
/* L52: */
/* L54: */
/* L56: */
/* L84: */
    dxfac = (float).1;
/* SOURCE culverta.for:2361 */
/*<       just='RIGHT' >*/
    s_copy(just, const_cast<char*>("RIGHT"), (ftnlen)5, (ftnlen)5);
/* SOURCE culverta.for:2362 */
/*<       idlen=0 >*/
    idlen = 0;
/* SOURCE culverta.for:2363 */
/*<       hlidlen=0 >*/
    hlidlen = 0;
/* SOURCE culverta.for:2364 */
/*<       blank=' ' >*/
    s_copy(blank, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/*     SET UP INITIAL VALUES OF POINTERS, COUNTERS, and flags. */
/*     Clear the flag used to note one or more occurrences of the */
/*     the special flag denoting location of an interpolated cross sections */
/*     using the proportion of the distance between adjacent actual cross sections. */
/* SOURCE culverta.for:2371 */
/*<       pflag=0 >*/
    pflag = 0;
/*     If TYPFLG is 0 we must clear HLTAB to keep a record of occurances of */
/*     relative location given explicitly by the user. */
/* SOURCE culverta.for:2375 */
/*<       if(typflg.eq.0)then >*/
    if (*typflg == 0) {
/* SOURCE culverta.for:2376 */
/*<       do95i=1,mnbn >*/
	feq_gen_i_d_1 = *mnbn;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culverta.for:2377 */
/*<       hltab(i)=0 >*/
	    hltab[feq_gen_i_d_] = 0;
/* SOURCE culverta.for:2378 */
/*<    95 continue >*/
/* L95: */
	}
/* SOURCE culverta.for:2379 */
/*<       endif >*/
    }
/* SOURCE culverta.for:2380 */
/*<       nbn=0 >*/
    *nbn = 0;
/* SOURCE culverta.for:2381 */
/*<       lnode=0 >*/
    lnode = 0;
/* SOURCE culverta.for:2382 */
/*<       bnum=1 >*/
    bnum = 1;
/* SOURCE culverta.for:2383 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)120);
/* SOURCE culverta.for:2386 */
/*<       callget_item_limits(stdout,line,maxn,just,n,item_start,item_end) >*/
    feq_gen_get_item_limits_d_(stdout, line, &feq_gen_c_d_8, just, &n, feq_gen_item_start_d_, feq_gen_item_end_d_,
	     (ftnlen)120, (ftnlen)5);
/* SOURCE culverta.for:2390 */
/*<       read(line,1)head >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 120;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_1;
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)120);
    e_rsfi();
/*      WRITE(STDOUT,11) HEAD */
/* SOURCE culverta.for:2392 */
/*<   100 continue >*/
L100:
/* SOURCE culverta.for:2393 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)120);
/* SOURCE culverta.for:2396 */
/*<       if(nodeid.eq.'NO')then >*/
    if (s_cmp(nodeid, const_cast<char*>("NO"), (ftnlen)4, (ftnlen)2) == 0) {
/* SOURCE culverta.for:2397 */
/*<       write(stdout,*)' CULVERT requires using NODEID=YES' >*/
	feq_gen_io_d__221.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__221);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" CULVERT requires using NODEID=YES"), (ftnlen)34)
		;
	e_wsle();
/* SOURCE culverta.for:2398 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE culverta.for:2399 */
/*<       else >*/
    } else {
/* SOURCE culverta.for:2400 */
/*<        >*/
	feq_gen_read_culvert_items_d_(stdout, line, &n, feq_gen_item_start_d_, feq_gen_item_end_d_, 
		eflag, &idlen, &hlidlen, &node, feq_gen_name_d_, xtabn, xchar, zchar, &
		ca, &cd, &hl, (ftnlen)120, (ftnlen)8, (ftnlen)5, (ftnlen)10, (
		ftnlen)10);
/*          READ(LINE,16,ERR=991) NODE, NAME, XTABN, XCHAR, ZCHAR, CA, */
/*     A                          CD, HL */
/* SOURCE culverta.for:2408 */
/*<       endif >*/
    }
/* SOURCE culverta.for:2409 */
/*<       if(node.eq.-1)goto120 >*/
    if (node == -1) {
	goto L120;
    }
/* SOURCE culverta.for:2410 */
/*<       if(lnode.ne.0)node=lnode+1 >*/
    if (lnode != 0) {
	node = lnode + 1;
    }
/* SOURCE culverta.for:2412 */
/*<       if(node.le.0)callkil(2,node,eflag) >*/
    if (node <= 0) {
	kil_(&feq_gen_c_d_2, &node, eflag);
    }
/* SOURCE culverta.for:2415 */
/*<       if(node.le.lnode)callkil(3,node,eflag) >*/
    if (node <= lnode) {
	kil_(&feq_gen_c_d_3, &node, eflag);
    }
/* SOURCE culverta.for:2418 */
/*<       if(xtabn.eq.'-')then >*/
    if (s_cmp(xtabn, const_cast<char*>("-"), (ftnlen)5, (ftnlen)1) == 0) {
/* SOURCE culverta.for:2419 */
/*<       xtab=-1000000 >*/
	xtab = -1000000;
/* SOURCE culverta.for:2420 */
/*<       else >*/
    } else {
/* SOURCE culverta.for:2421 */
/*<       read(xtabn,'(I5)')xtab >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 5;
	feq_gen_ici_d_1.iciunit = xtabn;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(I5)");
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&xtab, (ftnlen)sizeof(integer));
	e_rsfi();
/* SOURCE culverta.for:2422 */
/*<       endif >*/
    }
/*       CATCH THE FIRST NODE NUMBER AND SET THE POINTER */
/* SOURCE culverta.for:2426 */
/*<       if(lnode.ne.0)goto102 >*/
    if (lnode != 0) {
	goto L102;
    }
/* SOURCE culverta.for:2427 */
/*<       brpt(1,bnum)=node >*/
    brpt[(bnum << 3) + 1] = node;
/* SOURCE culverta.for:2428 */
/*<       brpt(3,bnum)=nbn+1 >*/
    brpt[(bnum << 3) + 3] = *nbn + 1;
/* SOURCE culverta.for:2429 */
/*<       if(xtab.le.0)then >*/
    if (xtab <= 0) {
/* SOURCE culverta.for:2430 */
/*<       write(stdout,50) >*/
	feq_gen_io_d__231.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__231);
	e_wsfe();
/* SOURCE culverta.for:2431 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE culverta.for:2432 */
/*<       xtab=1 >*/
	xtab = 1;
/* SOURCE culverta.for:2433 */
/*<       endif >*/
    }
/* SOURCE culverta.for:2434 */
/*<       lxtab=xtab >*/
    lxtab = xtab;
/* SOURCE culverta.for:2435 */
/*<   102 continue >*/
L102:
/* SOURCE culverta.for:2436 */
/*<       lnode=node >*/
    lnode = node;
/*       STORE VALUES FOR THIS NODE */
/* SOURCE culverta.for:2441 */
/*<       nbn=nbn+1 >*/
    ++(*nbn);
/* SOURCE culverta.for:2442 */
/*<       if(nbn.gt.mnbn)callkil(27,nbn,eflag) >*/
    if (*nbn > *mnbn) {
	kil_(&feq_gen_c_d_27, nbn, eflag);
    }
/* SOURCE culverta.for:2445 */
/*<       if(xtab.eq.0)then >*/
    if (xtab == 0) {
/* SOURCE culverta.for:2446 */
/*<       xtab=lxtab >*/
	xtab = lxtab;
/* SOURCE culverta.for:2447 */
/*<       else >*/
    } else {
/* SOURCE culverta.for:2448 */
/*<       lxtab=xtab >*/
	lxtab = xtab;
/* SOURCE culverta.for:2449 */
/*<       endif >*/
    }
/* SOURCE culverta.for:2450 */
/*<       nsec(nbn)=xtab >*/
    nsec[*nbn] = xtab;
/*       Remember the locations of negative table ids given */
/*       by the user. */
/* SOURCE culverta.for:2454 */
/*<       if(xtab.lt.0.and.xtab.ne.-1000000)then >*/
    if (xtab < 0 && xtab != -1000000) {
/* SOURCE culverta.for:2455 */
/*<       negtab(nbn)=1 >*/
	negtab[*nbn] = 1;
/* SOURCE culverta.for:2456 */
/*<       else >*/
    } else {
/* SOURCE culverta.for:2457 */
/*<       negtab(nbn)=0 >*/
	negtab[*nbn] = 0;
/* SOURCE culverta.for:2458 */
/*<       endif >*/
    }
/*       PROCESS THE STATION AND ELEVATION VALUES */
/* SOURCE culverta.for:2461 */
/*<       xchar=gettok(xchar) >*/
    gettok_(feq_gen_ch_d_1, (ftnlen)10, xchar, (ftnlen)10);
    s_copy(xchar, feq_gen_ch_d_1, (ftnlen)10, (ftnlen)10);
/* SOURCE culverta.for:2462 */
/*<       zchar=gettok(zchar) >*/
    gettok_(feq_gen_ch_d_1, (ftnlen)10, zchar, (ftnlen)10);
    s_copy(zchar, feq_gen_ch_d_1, (ftnlen)10, (ftnlen)10);
/* SOURCE culverta.for:2463 */
/*<       if(xchar(1:3).eq.'TAB'.or.xchar(1:3).eq.'tab')then >*/
    if (s_cmp(xchar, const_cast<char*>("TAB"), (ftnlen)3, (ftnlen)3) == 0 || s_cmp(xchar, const_cast<char*>("tab"), 
	    (ftnlen)3, (ftnlen)3) == 0) {
/*         FIND THE STATION FROM THE CROSS SECTION TABLE XTAB */
/*          X = FNDSTA(XTAB, STDOUT, EFLAG) */
/* SOURCE culverta.for:2466 */
/*<       callfndsta(xtab,stdout,eflag,x) >*/
	fndsta_(&xtab, stdout, eflag, &x);
/* SOURCE culverta.for:2469 */
/*<       elseif(xchar.eq.'          ')then >*/
    } else if (s_cmp(xchar, const_cast<char*>("          "), (ftnlen)10, (ftnlen)10) == 0) {
/* SOURCE culverta.for:2470 */
/*<       x=0.0 >*/
	x = (float)0.;
/* SOURCE culverta.for:2471 */
/*<       elseif(xchar(1:2).eq.'P='.or.xchar(1:2).eq.'p=')then >*/
    } else if (s_cmp(xchar, const_cast<char*>("P="), (ftnlen)2, (ftnlen)2) == 0 || s_cmp(xchar, 
	    const_cast<char*>("p="), (ftnlen)2, (ftnlen)2) == 0) {
/*         Read the p value. */
/* SOURCE culverta.for:2474 */
/*<       read(xchar(3:10),'(F8.0)',err=991)x >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 8;
	feq_gen_ici_d_1.iciunit = xchar + 2;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F8.0)");
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE culverta.for:2475 */
/*<       pflag=1 >*/
	pflag = 1;
/* SOURCE culverta.for:2476 */
/*<       hltab(nbn)=1 >*/
	hltab[*nbn] = 1;
/* SOURCE culverta.for:2477 */
/*<       else >*/
    } else {
/* SOURCE culverta.for:2478 */
/*<       read(xchar,'(F10.0)',err=991)x >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 10;
	feq_gen_ici_d_1.iciunit = xchar;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.0)");
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&x, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE culverta.for:2479 */
/*<       endif >*/
    }
/* SOURCE culverta.for:2480 */
/*<       if(zchar(1:3).eq.'TAB'.or.zchar(1:3).eq.'tab')then >*/
    if (s_cmp(zchar, const_cast<char*>("TAB"), (ftnlen)3, (ftnlen)3) == 0 || s_cmp(zchar, const_cast<char*>("tab"), 
	    (ftnlen)3, (ftnlen)3) == 0) {
/*         FIND THE ELEVATION FROM THE CROSS SECTION TABLE XTAB */
/*          Z = FNDELV(XTAB, STDOUT, EFLAG) */
/* SOURCE culverta.for:2483 */
/*<       callfndelv(xtab,stdout,eflag,z) >*/
	fndelv_(&xtab, stdout, eflag, &feq_gen_z_d_);
/* SOURCE culverta.for:2486 */
/*<       elseif(zchar.eq.'          ')then >*/
    } else if (s_cmp(zchar, const_cast<char*>("          "), (ftnlen)10, (ftnlen)10) == 0) {
/* SOURCE culverta.for:2487 */
/*<       z=0.0 >*/
	feq_gen_z_d_ = (float)0.;
/* SOURCE culverta.for:2488 */
/*<       else >*/
    } else {
/* SOURCE culverta.for:2489 */
/*<       read(zchar,'(F10.0)',err=991)z >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 10;
	feq_gen_ici_d_1.iciunit = zchar;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.0)");
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&feq_gen_z_d_, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE culverta.for:2490 */
/*<       endif >*/
    }
/* SOURCE culverta.for:2491 */
/*<       xvec(nbn)=x >*/
    xvec[*nbn] = x;
/* SOURCE culverta.for:2492 */
/*<       zbvec(nbn)=z >*/
    zbvec[*nbn] = feq_gen_z_d_;
/* SOURCE culverta.for:2493 */
/*<       ka(nbn)=ca >*/
    ka[*nbn] = ca;
/* SOURCE culverta.for:2494 */
/*<       kd(nbn)=cd >*/
    kd[*nbn] = cd;
/* SOURCE culverta.for:2495 */
/*<       if(typflg.eq.1)then >*/
    if (*typflg == 1) {
/* SOURCE culverta.for:2496 */
/*<       hltab(nbn)=hl >*/
	hltab[*nbn] = hl;
/* SOURCE culverta.for:2497 */
/*<       endif >*/
    }
/* SOURCE culverta.for:2498 */
/*<       if(nodeid.ne.'NO')bnodid(nbn)=name >*/
    if (s_cmp(nodeid, const_cast<char*>("NO"), (ftnlen)4, (ftnlen)2) != 0) {
	s_copy(bnodid + (*nbn << 3), feq_gen_name_d_, (ftnlen)8, (ftnlen)8);
    }
/* SOURCE culverta.for:2500 */
/*<       goto100 >*/
    goto L100;
/* SOURCE culverta.for:2501 */
/*<   120 continue >*/
L120:
/*     Check if either endpoint invert elevation is exactly zero. */
/*     If so, replace with a small positive number to prevent */
/*     interpolation problems. */
/* SOURCE culverta.for:2505 */
/*<       if(zbvec(1).eq.0.0)then >*/
    if (zbvec[1] == (float)0.) {
/* SOURCE culverta.for:2506 */
/*<       zbvec(1)=1.e-5 >*/
	zbvec[1] = (float)1e-5;
/* SOURCE culverta.for:2507 */
/*<       endif >*/
    }
/* SOURCE culverta.for:2508 */
/*<       if(zbvec(nbn).eq.0.0)then >*/
    if (zbvec[*nbn] == (float)0.) {
/* SOURCE culverta.for:2509 */
/*<       zbvec(nbn)=1.e-5 >*/
	zbvec[*nbn] = (float)1e-5;
/* SOURCE culverta.for:2510 */
/*<       endif >*/
    }
/* SOURCE culverta.for:2512 */
/*<       if(typflg.eq.1)then >*/
    if (*typflg == 1) {
/* SOURCE culverta.for:2513 */
/*<       chkbar=0 >*/
	*chkbar = 0;
/* SOURCE culverta.for:2514 */
/*<       if(nbn.gt.2)then >*/
	if (*nbn > 2) {
/*         Check if we can replace the user's definition with our own. */
/* SOURCE culverta.for:2516 */
/*<       bshape=0 >*/
	    *bshape = 0;
/* SOURCE culverta.for:2517 */
/*<       sbkind=0 >*/
	    *sbkind = 0;
/* SOURCE culverta.for:2518 */
/*<       do122i=2,nbn-1 >*/
	    feq_gen_i_d_1 = *nbn - 1;
	    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culverta.for:2519 */
/*<       if(nsec(i).gt.0)then >*/
		if (nsec[feq_gen_i_d_] > 0) {
/*             Does it differ from the first table given? */
/* SOURCE culverta.for:2521 */
/*<       if(nsec(i).ne.nsec(1))then >*/
		    if (nsec[feq_gen_i_d_] != nsec[1]) {
/*               The barrel is non-prismatic with a cross section */
/*               table given that differs from the first table and */
/*               precedes the last table. */
/* SOURCE culverta.for:2525 */
/*<       bshape=1 >*/
			*bshape = 1;
/* SOURCE culverta.for:2526 */
/*<       endif >*/
		    }
/* SOURCE culverta.for:2527 */
/*<       endif >*/
		}
/* SOURCE culverta.for:2528 */
/*<       if(zbvec(i).ne.0.0)then >*/
		if (zbvec[feq_gen_i_d_] != (float)0.) {
/*             An invert elevation has been given before the */
/*             last table.  Bottom slope may have changed. */
/* SOURCE culverta.for:2531 */
/*<       sbkind=1 >*/
		    *sbkind = 1;
/* SOURCE culverta.for:2532 */
/*<       endif >*/
		}
/* SOURCE culverta.for:2533 */
/*<   122 continue >*/
/* L122: */
	    }
/* SOURCE culverta.for:2534 */
/*<       if(sbkind.gt.0.or.bshape.gt.0)then >*/
	    if (*sbkind > 0 || *bshape > 0) {
/*           The conduit appears to have a break in slope and/or is */
/*           non-prismatic even though the final section has not been */
/*           checked.  This is too complex for the simple code below */
/*           for automatic cross section assignment.  We will have to */
/*           check later for the proper stations for type 5 flow. */
/* SOURCE culverta.for:2541 */
/*<       chkbar=1 >*/
		*chkbar = 1;
/* SOURCE culverta.for:2543 */
/*<       else >*/
	    } else {
/*           The conduit has constant slope and is prismatic before */
/*           we check the last section.  Therefore, it can be */
/*           described by two nodes. */
/* SOURCE culverta.for:2547 */
/*<       nsec(2)=nsec(nbn) >*/
		nsec[2] = nsec[*nbn];
/* SOURCE culverta.for:2548 */
/*<       xvec(2)=xvec(nbn) >*/
		xvec[2] = xvec[*nbn];
/* SOURCE culverta.for:2549 */
/*<       zbvec(2)=zbvec(nbn) >*/
		zbvec[2] = zbvec[*nbn];
/* SOURCE culverta.for:2550 */
/*<       bnodid(2)=bnodid(nbn) >*/
		s_copy(bnodid + 16, bnodid + (*nbn << 3), (ftnlen)8, (ftnlen)
			8);
/* SOURCE culverta.for:2551 */
/*<       nbn=2 >*/
		*nbn = 2;
/* SOURCE culverta.for:2552 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:2553 */
/*<       endif >*/
	}
/*       Check for the case of internally generated spacing of */
/*       cross sections. */
/* SOURCE culverta.for:2556 */
/*<       if(nbn.eq.2)then >*/
	if (*nbn == 2) {
/*         Only two nodes given.  Signals that the stations are to */
/*         be internally generated. */
/*         Also the slope is constant */
/* SOURCE culverta.for:2560 */
/*<       sbkind=0 >*/
	    *sbkind = 0;
/* SOURCE culverta.for:2561 */
/*<       clvlen=abs(xvec(1)-xvec(2)) >*/
	    clvlen = (feq_gen_r_d_1 = static_cast<double>(xvec[1]) - xvec[2], dabs(feq_gen_r_d_1));
/* SOURCE culverta.for:2562 */
/*<       it=nsec(1) >*/
	    it = nsec[1];
/* SOURCE culverta.for:2563 */
/*<       callchktab(12,stdout,ftpnt,mftnum,it,eflag) >*/
	    chktab_(&feq_gen_c_d_12, stdout, &ftpnt[1], mftnum, &it, eflag);
/* SOURCE culverta.for:2567 */
/*<       if(eflag.ne.0)then >*/
	    if (*eflag != 0) {
/* SOURCE culverta.for:2568 */
/*<       stop'Abnormal stop.  Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE culverta.for:2569 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:2571 */
/*<       d=getd(it,stdout)/sfac >*/
	    feq_gen_d_d_ = getd_(&it, stdout) / *sfac;
/* SOURCE culverta.for:2572 */
/*<       loverd=clvlen/d >*/
	    loverd = static_cast<double>(clvlen) / feq_gen_d_d_;
/* SOURCE culverta.for:2573 */
/*<       sdxovl=dxfac/loverd >*/
	    sdxovl = static_cast<double>(dxfac) / loverd;
/*         Compute the number of Gauss points needed to give the */
/*         minimum distance increment relative to the culvert opening */
/*         at its upstream end. */
/* SOURCE culverta.for:2578 */
/*<       nhat=exp(3.63759-0.505495*(log(sdxovl)+6.93304))+.4 >*/
	    nhat = exp((float)3.63759 - (log(sdxovl) + (float)6.93304) * (
		    float).505495) + (float).4;
/* SOURCE culverta.for:2580 */
/*<       callmkxvec(loverd,d,nhat,xvec,iat3d,iat6d) >*/
	    mkxvec_(&loverd, &feq_gen_d_d_, &nhat, &xvec[1], iat3d, iat6d);
/* SOURCE culverta.for:2584 */
/*<       write(stdout,56)nhat >*/
	    feq_gen_io_d__241.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__241);
	    do_fio(&feq_gen_c_d_1, (char *)&nhat, (ftnlen)sizeof(integer));
	    e_wsfe();
/*         Check for length of the culvert. */
/* SOURCE culverta.for:2587 */
/*<       if(iat3d.eq.0.or.iat3d.eq.nhat)then >*/
	    if (*iat3d == 0 || *iat3d == nhat) {
/*           Culvert is 3 D or less long.  Write message and set location */
/*           to entrance. */
/* SOURCE culverta.for:2590 */
/*<       write(stdout,52) >*/
		feq_gen_io_d__242.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__242);
		e_wsfe();
/* SOURCE culverta.for:2591 */
/*<       iat3d=1 >*/
		*iat3d = 1;
/* SOURCE culverta.for:2592 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:2593 */
/*<       if(iat6d.eq.0)then >*/
	    if (*iat6d == 0) {
/*           Culvert is less than 6 D long.  Leave IAT6D=0 to allow */
/*           for under representation of losses in short culverts. */
/* SOURCE culverta.for:2596 */
/*<       write(stdout,54) >*/
		feq_gen_io_d__243.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__243);
		e_wsfe();
/* SOURCE culverta.for:2597 */
/*<       endif >*/
	    }
/*         Create new version of the culvert barrel description */
/* SOURCE culverta.for:2601 */
/*<       if(nsec(1).eq.nsec(2))then >*/
	    if (nsec[1] == nsec[2]) {
/*            NEGTAB(1) = 0 */
/*           Prismatic barrel. */
/* SOURCE culverta.for:2604 */
/*<       bshape=0 >*/
		*bshape = 0;
/* SOURCE culverta.for:2605 */
/*<       do125i=2,nhat >*/
		feq_gen_i_d_1 = nhat;
		for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culverta.for:2606 */
/*<       nsec(i)=nsec(1) >*/
		    nsec[feq_gen_i_d_] = nsec[1];
/*              NEGTAB(I) = 0 */
/* SOURCE culverta.for:2608 */
/*<   125 continue >*/
/* L125: */
		}
/* SOURCE culverta.for:2609 */
/*<       else >*/
	    } else {
/*           Non-prismatic barrel. */
/* SOURCE culverta.for:2611 */
/*<       bshape=1 >*/
		*bshape = 1;
/* SOURCE culverta.for:2612 */
/*<       nsec(nhat)=nsec(2) >*/
		nsec[nhat] = nsec[2];
/*            NEGTAB(1) = 0 */
/*            NEGTAB(NHAT) = 0 */
/* SOURCE culverta.for:2615 */
/*<       do130i=2,nhat-1 >*/
		feq_gen_i_d_1 = nhat - 1;
		for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culverta.for:2616 */
/*<       nsec(i)=-1000000 >*/
		    nsec[feq_gen_i_d_] = -1000000;
/*              NEGTAB(I) = 1 */
/* SOURCE culverta.for:2618 */
/*<   130 continue >*/
/* L130: */
		}
/* SOURCE culverta.for:2619 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:2620 */
/*<       zbvec(nhat)=zbvec(2) >*/
	    zbvec[nhat] = zbvec[2];
/* SOURCE culverta.for:2621 */
/*<       ka(nhat)=ka(2) >*/
	    ka[nhat] = ka[2];
/* SOURCE culverta.for:2622 */
/*<       kd(nhat)=kd(2) >*/
	    kd[nhat] = kd[2];
/* SOURCE culverta.for:2623 */
/*<       bnodid(nhat)=bnodid(2) >*/
	    s_copy(bnodid + (nhat << 3), bnodid + 16, (ftnlen)8, (ftnlen)8);
/* SOURCE culverta.for:2624 */
/*<       hltab(nhat)=0 >*/
	    hltab[nhat] = 0;
/* SOURCE culverta.for:2625 */
/*<       do135i=2,nhat-1 >*/
	    feq_gen_i_d_1 = nhat - 1;
	    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culverta.for:2626 */
/*<       zbvec(i)=0.0 >*/
		zbvec[feq_gen_i_d_] = (float)0.;
/* SOURCE culverta.for:2627 */
/*<       ka(i)=ka(nhat) >*/
		ka[feq_gen_i_d_] = ka[nhat];
/* SOURCE culverta.for:2628 */
/*<       kd(i)=kd(nhat) >*/
		kd[feq_gen_i_d_] = kd[nhat];
/* SOURCE culverta.for:2629 */
/*<       bnodid(i)=' ' >*/
		s_copy(bnodid + (feq_gen_i_d_ << 3), const_cast<char*>(" "), (ftnlen)8, (ftnlen)1);
/* SOURCE culverta.for:2630 */
/*<       hltab(i)=0 >*/
		hltab[feq_gen_i_d_] = 0;
/* SOURCE culverta.for:2631 */
/*<   135 continue >*/
/* L135: */
	    }
/* SOURCE culverta.for:2633 */
/*<       nbn=nhat >*/
	    *nbn = nhat;
/* SOURCE culverta.for:2634 */
/*<       lnode=lnode+nhat-2 >*/
	    lnode = lnode + nhat - 2;
/* SOURCE culverta.for:2635 */
/*<       endif >*/
	}
/* SOURCE culverta.for:2636 */
/*<       endif >*/
    }
/* SOURCE culverta.for:2637 */
/*<       brpt(2,bnum)=lnode >*/
    brpt[(bnum << 3) + 2] = lnode;
/* SOURCE culverta.for:2638 */
/*<       brpt(4,bnum)=nbn >*/
    brpt[(bnum << 3) + 4] = *nbn;
/* SOURCE culverta.for:2639 */
/*<       last=nbn >*/
    last = *nbn;
/* SOURCE culverta.for:2640 */
/*<       first=brpt(3,bnum) >*/
    first = brpt[(bnum << 3) + 3];
/* SOURCE culverta.for:2642 */
/*<       ka(first)=0.0 >*/
    ka[first] = (float)0.;
/* SOURCE culverta.for:2643 */
/*<       kd(first)=0.0 >*/
    kd[first] = (float)0.;
/* SOURCE culverta.for:2645 */
/*<       if(typflg.eq.0)then >*/
    if (*typflg == 0) {
/*       Check for use of a p value for location */
/* SOURCE culverta.for:2647 */
/*<       if(pflag.eq.1)then >*/
	if (pflag == 1) {
/*         Scan and evaluate p values.  They appear in sequence between */
/*         known cross sections. */
/*         Clear the memory location of the first p value seen */
/*         in a potential sequence of such values. */
/* SOURCE culverta.for:2652 */
/*<       it=0 >*/
	    it = 0;
/* SOURCE culverta.for:2654 */
/*<       do2200i=first+1,last >*/
	    feq_gen_i_d_1 = last;
	    for (feq_gen_i_d_ = first + 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*            WRITE(STDOUT,*) ' IT=',IT, ' HLTAB(I)=',HLTAB(I) */
/* SOURCE culverta.for:2656 */
/*<       if(it.eq.0)then >*/
		if (it == 0) {
/* SOURCE culverta.for:2657 */
/*<       if(hltab(i).eq.1)then >*/
		    if (hltab[feq_gen_i_d_] == 1) {
/*               Set a pointer to remember location of the first p value */
/*               that needs to be evaluated.  Note: If p values are used */
/*               in an interval then all locations must be in those terms. */
/*               This makes the detection easier and does not reduce the */
/*               usefulness in our current application. */
/*                WRITE(STDOUT,*) ' Found p-value. IT=',IT */
/* SOURCE culverta.for:2665 */
/*<       it=i >*/
			it = feq_gen_i_d_;
/* SOURCE culverta.for:2666 */
/*<       endif >*/
		    }
/* SOURCE culverta.for:2667 */
/*<       else >*/
		} else {
/* SOURCE culverta.for:2668 */
/*<       if(hltab(i).eq.0)then >*/
		    if (hltab[feq_gen_i_d_] == 0) {
/*               We have seen at least one p value.  The next non-p value */
/*               should be a valid station value for interpolation. Interpolate */
/*               using XVEC(IT-1) as the first X value and XVEC(I) as the last X value. */
/* SOURCE culverta.for:2672 */
/*<       xl=xvec(it-1) >*/
			xl = xvec[it - 1];
/* SOURCE culverta.for:2673 */
/*<       xr=xvec(i) >*/
			xr = xvec[feq_gen_i_d_];
/*                WRITE(STDOUT,*) ' Interpolate with: XL=',XL,' XR=',XR */
/* SOURCE culverta.for:2675 */
/*<       do2190j=it,i-1 >*/
			feq_gen_i_d_2 = feq_gen_i_d_ - 1;
			for (j = it; j <= feq_gen_i_d_2; ++j) {
/* SOURCE culverta.for:2676 */
/*<       xvec(j)=xl+xvec(j)*(xr-xl) >*/
			    xvec[j] = static_cast<double>(xl) + static_cast<double>(xvec[j]) * (static_cast<double>(xr) - xl);
/* SOURCE culverta.for:2677 */
/*<       hltab(j)=0 >*/
			    hltab[j] = 0;
/* SOURCE culverta.for:2678 */
/*<  2190 continue >*/
/* L2190: */
			}
/*               Clear the memory flag */
/* SOURCE culverta.for:2680 */
/*<       it=0 >*/
			it = 0;
/* SOURCE culverta.for:2681 */
/*<       endif >*/
		    }
/* SOURCE culverta.for:2682 */
/*<       endif >*/
		}
/* SOURCE culverta.for:2683 */
/*<  2200 continue >*/
/* L2200: */
	    }
/* SOURCE culverta.for:2684 */
/*<       endif >*/
	}
/* SOURCE culverta.for:2685 */
/*<       endif >*/
    }
/*     CHECK FOR REQUESTS FOR INTERPOLATION OF BOTTOM PROFILE */
/*     BEFORE CHECKING FOR REQUESTS FOR STATION AND BOTTOM */
/*     PROFILE. */
/*     NOTE THAT A GIVEN PROFILE LEVEL OF 0.0 IS TAKEN TO BE A */
/*     REQUEST FOR INTERPOLATION.  A TRUE VALUE OF ZERO CANNOT */
/*     BE GIVEN BUT IF AN ESSENTIAL ZERO IS DESIRED INPUT A */
/*     SMALL NON-ZERO VALUE TO OBTAIN IT. */
/*     AT A MINIMUM THE FIRST AND LAST NODE ON THE BRANCH MUST HAVE */
/*     NON-ZERO PROFILE VALUES.  THESE ARE NOT CHECKED. */
/* SOURCE culverta.for:2699 */
/*<       if(zbvec(first).ne.0.0)then >*/
    if (zbvec[first] != (float)0.) {
/* SOURCE culverta.for:2700 */
/*<       jzero=0 >*/
	jzero = 0;
/*       SCAN ALL NODES BUT THE FIRST FOR REQUESTS */
/* SOURCE culverta.for:2702 */
/*<       do2400j=first+1,last >*/
	feq_gen_i_d_1 = last;
	for (j = first + 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE culverta.for:2703 */
/*<       if(zbvec(j).eq.0.0)then >*/
	    if (zbvec[j] == (float)0.) {
/*           REQUEST FOUND- SAVE INDEX OF FIRST REQUEST */
/* SOURCE culverta.for:2705 */
/*<       if(jzero.eq.0)then >*/
		if (jzero == 0) {
/* SOURCE culverta.for:2706 */
/*<       jzero=j >*/
		    jzero = j;
/* SOURCE culverta.for:2707 */
/*<       endif >*/
		}
/* SOURCE culverta.for:2708 */
/*<       else >*/
	    } else {
/*           NO REQUEST AT THIS POINT.  CHECK FOR PREVIOUS REQUESTS */
/* SOURCE culverta.for:2710 */
/*<       if(jzero.gt.0)then >*/
		if (jzero > 0) {
/*             ONE OR MORE INTERPOLATION REQUESTS ARE OUTSTANDING. */
/*             JZERO POINTS TO THE FIRST REQUEST. JZERO-1 POINTS */
/*             TO THE PREVIOUS VALID STATION-PROFILE PAIR AND */
/*             J POINTS TO THE CURRENT VALID PAIR. */
/*             GET THE STATION AND PROFILE FROM THE PREVIOUS VALID */
/*             PAIR */
/* SOURCE culverta.for:2719 */
/*<       statl=xvec(jzero-1) >*/
		    statl = xvec[jzero - 1];
/* SOURCE culverta.for:2720 */
/*<       stdl=zbvec(jzero-1) >*/
		    stdl = zbvec[jzero - 1];
/*             GET CURRENT VALID VALUE */
/* SOURCE culverta.for:2724 */
/*<       statr=xvec(j) >*/
		    statr = xvec[j];
/* SOURCE culverta.for:2725 */
/*<       stdr=zbvec(j) >*/
		    stdr = zbvec[j];
/* SOURCE culverta.for:2727 */
/*<       fac=(stdr-stdl)/(statr-statl) >*/
		    fac = static_cast<double>((static_cast<double>(stdr) - stdl)) / (static_cast<double>(statr) - statl);
/* SOURCE culverta.for:2728 */
/*<       do2300k=jzero,j-1 >*/
		    feq_gen_i_d_2 = j - 1;
		    for (k = jzero; k <= feq_gen_i_d_2; ++k) {
/* SOURCE culverta.for:2729 */
/*<       if(xvec(k).ne.0.0)then >*/
			if (xvec[k] != (float)0.) {
/*                 EXACT ZERO FOR STATION PRECLUDES COMPUTING */
/*                 PROFILE. WILL BE DONE BY STATION AND PROFILE */
/*                 INTERPOLATION PROCESS. */
/* SOURCE culverta.for:2734 */
/*<       zbvec(k)=stdl+(xvec(k)-statl)*fac >*/
			    zbvec[k] = static_cast<double>(stdl) + static_cast<double>((static_cast<double>(xvec[k]) - statl)) * fac;
/* SOURCE culverta.for:2735 */
/*<       endif >*/
			}
/* SOURCE culverta.for:2736 */
/*<  2300 continue >*/
/* L2300: */
		    }
/* SOURCE culverta.for:2737 */
/*<       jzero=0 >*/
		    jzero = 0;
/* SOURCE culverta.for:2738 */
/*<       endif >*/
		}
/* SOURCE culverta.for:2739 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:2740 */
/*<  2400 continue >*/
/* L2400: */
	}
/* SOURCE culverta.for:2741 */
/*<       endif >*/
    }
/*     CHECK FOR REQUESTS FOR INTERPOLATION OF STATION AND */
/*     ELEVATION AND DO THE REQUESTS. NOTE: THE FIRST AND LAST */
/*     NODES ON A BRANCH ARE ASSUMED TO HAVE VALID VALUES */
/*     OF STATION AND ELEVATION.  THESE CANNOT BE CHECKED! */
/* SOURCE culverta.for:2749 */
/*<       jzero=0 >*/
    jzero = 0;
/*     SCAN ALL NODES BUT THE FIRST FOR REQUESTS */
/* SOURCE culverta.for:2751 */
/*<       do2000j=first+1,last >*/
    feq_gen_i_d_1 = last;
    for (j = first + 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE culverta.for:2752 */
/*<       if(zbvec(j).eq.0.0.and.xvec(j).eq.0.0)then >*/
	if (zbvec[j] == (float)0. && xvec[j] == (float)0.) {
/*         REQUEST FOUND- SAVE INDEX OF FIRST REQUEST */
/* SOURCE culverta.for:2754 */
/*<       if(jzero.eq.0)then >*/
	    if (jzero == 0) {
/* SOURCE culverta.for:2755 */
/*<       jzero=j >*/
		jzero = j;
/* SOURCE culverta.for:2756 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:2757 */
/*<       else >*/
	} else {
/*         NO REQUEST AT THIS POINT.  CHECK FOR PREVIOUS REQUESTS */
/* SOURCE culverta.for:2759 */
/*<       if(jzero.gt.0)then >*/
	    if (jzero > 0) {
/*           ONE OR MORE INTERPOLATION REQUESTS ARE OUTSTANDING. */
/*           JZERO POINTS TO THE FIRST REQUEST. JZERO-1 POINTS */
/*           TO THE PREVIOUS VALID STATION-ELEVATION PAIR AND */
/*           J POINTS TO THE CURRENT VALID PAIR. */
/*           GET THE FLOAT PNT FORM OF THE NUMBER OF INTERVALS */
/* SOURCE culverta.for:2767 */
/*<       fint=float(j-jzero+1) >*/
		fint = (real) (j - jzero + 1);
/*           GET THE STATION AND ELEVATION FROM THE PREVIOUS VALID */
/*           STATION-ELEVATION PAIR */
/* SOURCE culverta.for:2772 */
/*<       stat=xvec(jzero-1) >*/
		stat = xvec[jzero - 1];
/* SOURCE culverta.for:2773 */
/*<       elev=zbvec(jzero-1) >*/
		elev = zbvec[jzero - 1];
/*           FIND THE CHANGE IN STATION AND ELEVATION */
/* SOURCE culverta.for:2777 */
/*<       dx=xvec(j)-stat >*/
		dx = static_cast<double>(xvec[j]) - stat;
/* SOURCE culverta.for:2778 */
/*<       dz=zbvec(j)-elev >*/
		dz = static_cast<double>(zbvec[j]) - elev;
/* SOURCE culverta.for:2780 */
/*<       do1000k=jzero,j-1 >*/
		feq_gen_i_d_2 = j - 1;
		for (k = jzero; k <= feq_gen_i_d_2; ++k) {
/* SOURCE culverta.for:2781 */
/*<       fac=float(k-jzero+1)/fint >*/
		    fac = static_cast<double>((real) (k - jzero + 1)) / fint;
/* SOURCE culverta.for:2782 */
/*<       xvec(k)=stat+dx*fac >*/
		    xvec[k] = static_cast<double>(stat) + static_cast<double>(dx) * fac;
/* SOURCE culverta.for:2783 */
/*<       zbvec(k)=elev+dz*fac >*/
		    zbvec[k] = static_cast<double>(elev) + static_cast<double>(dz) * fac;
/* SOURCE culverta.for:2784 */
/*<  1000 continue >*/
/* L1000: */
		}
/* SOURCE culverta.for:2785 */
/*<       jzero=0 >*/
		jzero = 0;
/* SOURCE culverta.for:2786 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:2787 */
/*<       endif >*/
	}
/* SOURCE culverta.for:2788 */
/*<  2000 continue >*/
/* L2000: */
    }
/* SOURCE culverta.for:2790 */
/*<       node=brpt(1,bnum) >*/
    node = brpt[(bnum << 3) + 1];
/* SOURCE culverta.for:2791 */
/*<       if(idlen.lt.6)idlen=6 >*/
    if (idlen < 6) {
	idlen = 6;
    }
/* SOURCE culverta.for:2792 */
/*<       if(hlidlen.lt.6)hlidlen=6 >*/
    if (hlidlen < 6) {
	hlidlen = 6;
    }
/* SOURCE culverta.for:2793 */
/*<       write(stdout,84)blank(1:idlen-5),blank(1:hlidlen-5) >*/
    feq_gen_io_d__261.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__261);
    do_fio(&feq_gen_c_d_1, blank, idlen - 5);
    do_fio(&feq_gen_c_d_1, blank, hlidlen - 5);
    e_wsfe();
/* SOURCE culverta.for:2794 */
/*<       do4000j=first,last >*/
    feq_gen_i_d_1 = last;
    for (j = first; j <= feq_gen_i_d_1; ++j) {
/* SOURCE culverta.for:2795 */
/*<       if(nsec(j).eq.-1000000)then >*/
	if (nsec[j] == -1000000) {
/* SOURCE culverta.for:2796 */
/*<       tabid=' ' >*/
	    s_copy(tabid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/* SOURCE culverta.for:2797 */
/*<       tabid(idlen:idlen)='-' >*/
	    *(unsigned char *)&tabid[idlen - 1] = '-';
/* SOURCE culverta.for:2798 */
/*<       else >*/
	} else {
/* SOURCE culverta.for:2799 */
/*<       if(nsec(j).gt.0)then >*/
	    if (nsec[j] > 0) {
/* SOURCE culverta.for:2800 */
/*<       tempc=get_tabid(nsec(j)) >*/
		feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &nsec[j]);
		s_copy(tempc, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
/* SOURCE culverta.for:2801 */
/*<       else >*/
	    } else {
/* SOURCE culverta.for:2802 */
/*<       tempc(2:)=get_tabid(-nsec(j)) >*/
		feq_gen_i_d_2 = -nsec[j];
		feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &feq_gen_i_d_2);
		s_copy(tempc + 1, feq_gen_ch_d_2, (ftnlen)15, (ftnlen)16);
/* SOURCE culverta.for:2803 */
/*<       tempc(1:1)='-' >*/
		*(unsigned char *)tempc = '-';
/* SOURCE culverta.for:2804 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:2806 */
/*<       it=lenstr(tempc) >*/
	    it = lenstr_(tempc, (ftnlen)16);
/* SOURCE culverta.for:2807 */
/*<       tabid=' ' >*/
	    s_copy(tabid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/* SOURCE culverta.for:2808 */
/*<       tabid(idlen-it+1:idlen)=tempc(1:it) >*/
	    feq_gen_i_d_2 = idlen - it;
	    s_copy(tabid + feq_gen_i_d_2, tempc, idlen - feq_gen_i_d_2, it);
/* SOURCE culverta.for:2809 */
/*<       endif >*/
	}
/* SOURCE culverta.for:2810 */
/*<       if(hltab(j).gt.0)then >*/
	if (hltab[j] > 0) {
/* SOURCE culverta.for:2811 */
/*<       tempc=get_tabid(hltab(j)) >*/
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &hltab[j]);
	    s_copy(tempc, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
/* SOURCE culverta.for:2812 */
/*<       it=lenstr(tempc) >*/
	    it = lenstr_(tempc, (ftnlen)16);
/* SOURCE culverta.for:2813 */
/*<       hltabid=' ' >*/
	    s_copy(hltabid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/* SOURCE culverta.for:2814 */
/*<       hltabid(hlidlen-it+1:hlidlen)=tempc(1:it) >*/
	    feq_gen_i_d_2 = hlidlen - it;
	    s_copy(hltabid + feq_gen_i_d_2, tempc, hlidlen - feq_gen_i_d_2, it);
/* SOURCE culverta.for:2815 */
/*<       else >*/
	} else {
/* SOURCE culverta.for:2816 */
/*<       hltabid=' ' >*/
	    s_copy(hltabid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/* SOURCE culverta.for:2817 */
/*<       endif >*/
	}
/* SOURCE culverta.for:2818 */
/*<       if(nodeid.eq.'NO')then >*/
	if (s_cmp(nodeid, const_cast<char*>("NO"), (ftnlen)4, (ftnlen)2) == 0) {
/* SOURCE culverta.for:2819 */
/*<       write(stdout,*)' *BUG*: Should not get here: CLVIN' >*/
	    feq_gen_io_d__265.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__265);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG*: Should not get here: CLVIN"), (
		    ftnlen)34);
	    e_wsle();
/* SOURCE culverta.for:2820 */
/*<       else >*/
	} else {
/* SOURCE culverta.for:2821 */
/*<        >*/
	    feq_gen_io_d__266.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__266);
	    do_fio(&feq_gen_c_d_1, (char *)&node, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, bnodid + (j << 3), (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, tabid, idlen);
	    do_fio(&feq_gen_c_d_1, (char *)&xvec[j], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&zbvec[j], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&ka[j], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&kd[j], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, hltabid, hlidlen);
	    e_wsfe();
/*          WRITE(STDOUT,18) NODE, BNODID(J), XTABN, XVEC(J), ZBVEC(J), */
/*     A                   KA(J), KD(J), HLTAB(J) */
/* SOURCE culverta.for:2825 */
/*<       endif >*/
	}
/* SOURCE culverta.for:2826 */
/*<       xvec(j)=sfac*xvec(j) >*/
	xvec[j] = static_cast<double>(*sfac) * xvec[j];
/* SOURCE culverta.for:2827 */
/*<       node=node+1 >*/
	++node;
/* SOURCE culverta.for:2828 */
/*<  4000 continue >*/
/* L4000: */
    }
/*     CHECK TABLE NUMBERS AND COMPLETE ANY CROSS SECTION INTERPOLATION */
/*     REQUESTS */
/* SOURCE culverta.for:2832 */
/*<       do5000j=first,last >*/
    feq_gen_i_d_1 = last;
    for (j = first; j <= feq_gen_i_d_1; ++j) {
/* SOURCE culverta.for:2833 */
/*<       xtab=nsec(j) >*/
	xtab = nsec[j];
/* SOURCE culverta.for:2834 */
/*<       if(xtab.gt.0)then >*/
	if (xtab > 0) {
/* SOURCE culverta.for:2835 */
/*<       if(typflg.eq.1)then >*/
	    if (*typflg == 1) {
/*           We must have at least the values in old type 12(new type 22) */
/* SOURCE culverta.for:2837 */
/*<       callchktab(12,stdout,ftpnt,mftnum,xtab,eflag) >*/
		chktab_(&feq_gen_c_d_12, stdout, &ftpnt[1], mftnum, &xtab, eflag);
/*           ON RETURN XTAB IS REPLACED BY THE ADDRESS OF THE TABLE */
/* SOURCE culverta.for:2842 */
/*<       nsec(j)=xtab >*/
		nsec[j] = xtab;
/* SOURCE culverta.for:2843 */
/*<       else >*/
	    } else {
/*           Any cross section type will do. */
/* SOURCE culverta.for:2845 */
/*<       callchktab(20,stdout,ftpnt,mftnum,xtab,eflag) >*/
		chktab_(&feq_gen_c_d_20, stdout, &ftpnt[1], mftnum, &xtab, eflag);
/*           ON RETURN XTAB IS REPLACED BY THE ADDRESS OF THE TABLE */
/* SOURCE culverta.for:2850 */
/*<       nsec(j)=xtab >*/
		nsec[j] = xtab;
/* SOURCE culverta.for:2852 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:2853 */
/*<       endif >*/
	}
/* SOURCE culverta.for:2854 */
/*<  5000 continue >*/
/* L5000: */
    }
/*     DO ANY CROSS SECTION INTERPOLATION REQUESTS */
/* SOURCE culverta.for:2858 */
/*<       if(eflag.eq.0)then >*/
    if (*eflag == 0) {
/* SOURCE culverta.for:2859 */
/*<        >*/
	scan_(stdout, nbra, nbn, mftnum, mrftab, &brpt[9], &nsec[1], &xvec[1],
		 &zbvec[1], sfac, eflag, ftp, ftknt);
/* SOURCE culverta.for:2863 */
/*<       endif >*/
    }
/* SOURCE culverta.for:2864 */
/*<       return >*/
    return 0;
/* SOURCE culverta.for:2865 */
/*<   991 continue >*/
L991:
/* SOURCE culverta.for:2866 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__267.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__267);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE culverta.for:2867 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__268.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__268);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)120);
    e_wsle();
/* SOURCE culverta.for:2868 */
/*<       stop'Abnormal stop.  Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE culverta.for:2869 */
/*<       end >*/
    return 0;
} /* clvin_ */




/* SOURCE culverta.for:2873 */
/*<       subroutineculvrt(stdin,stdout,stdtab,nfac,tabdir,eflag,ftp,ftknt) >*/
/* Subroutine */ int culvrt_(integer *stdin, integer *stdout, integer *stdtab,
	 real *nfac, integer *feq_storage_tabdir, integer *eflag, integer *ftp, integer *
	ftknt)
{
    /* Format strings */
    static char fmt_2[] = "(a5,1x,a)";
    static char fmt_6[] = "(a6,1x,f10.0)";
    static char fmt_7[] = "(a6,1x,f10.0,a10,2a5)";
    static char fmt_10[] = "(a6,1x,a8)";
    static char fmt_12[] = "(a6,1x,a8)";
    static char fmt_14[] = "(3x,1x,f10.0,1x,a4)";
    static char fmt_15[] = "(a7,1x,f10.0)";
    static char fmt_16[] = "(a5,1x,f10.0)";
    static char fmt_17[] = "(8x,f10.0)";
    static char fmt_18[] = "(a5,1x,f10.0)";
    static char fmt_19[] = "(9x,f10.0)";
    static char fmt_20[] = "(a6,1x,a4)";
    static char fmt_21[] = "(7x,f10.0)";
    static char fmt_22[] = "(a4,1x,f10.0)";
    static char fmt_23[] = "(7x,f10.3)";
    static char fmt_24[] = "(a80)";
    static char fmt_26[] = "(a5,1x,i5)";
    static char fmt_27[] = "(a4,1x,i5,1x,9x,f5.0)";
    static char fmt_1000[] = "(6x,f10.0)";
    static char fmt_3[] = "(/,\002 Adding upstream head=\002,f8.3,\002 at th\
e nominal\002,\002 lower bound for high head flow.\002)";
    static char fmt_5[] = "(/,\002 Adding upstream head=\002,f8.3,\002 at th\
e minimum\002,\002 crest elevation of roadway.\002)";
    static char fmt_8[] = "(/,\002 *WRN:584* KWING=\002,f5.3,\002 ignored.  \
Applies to BOX\002,\002 culverts only.\002)";
    static char fmt_9[] = "(/,\002 *WRN:585* KPROJ=\002,f5.3,\002 ignored.  \
Does not apply\002,\002 to BOX culverts.\002)";
    static char fmt_11[] = "(/,\002 Power for distributing partial free drop\
s=\002,f5.1)";
    static char fmt_13[] = "(/,\002 *ERR:721* Relative projection < 0.\002)";
    static char fmt_25[] = "(/,\002 Angle of inlet bevel=\002,f5.1,\002 degr\
ees.\002)";
    static char fmt_28[] = "(/,\002 Relative projection=\002,f8.3)";
    static char fmt_29[] = "(/,\002 *ERR:722* Angle of inlet bevel < 0 or > \
90 degrees.\002)";
    static char fmt_30[] = "(/,\002 Rounding/beveling value=\002,f5.3)";
    static char fmt_31[] = "(/,\002 Checking the critical flow variatio\
n\002,\002 at section 2.\002)";
    static char fmt_32[] = "(/,\002 This cross section may cause computation\
al problems\002,\002 if critical\002,/,\002 flow decreases with depth.  CULV\
ERT\002,\002 may become confused\002,/,\002 when the relationship between\
\002,\002 critical flow\002,/,\002 and depth is not unique.\002)";
    static char fmt_33[] = "(/,\002 Checking the critical flow variatio\
n\002,\002 at section 3.\002)";
    static char fmt_34[] = "(/,\002 *ERR:703* Number of upstream heads=\002,\
i5,\002 too\002,\002 small to add\002,/,11x,\002 high-head flow limit.\002)";
    static char fmt_35[] = "(/,\002 *ERR:704* Number of upstream heads=\002,\
i5,\002 too\002,\002 small to add\002,/,11x,\002 head at roadway crest.\002)";
    static char fmt_36[] = "(/,\002 Wingwall angle=\002,f5.0,\002 degrees\
.\002)";
    static char fmt_37[] = "(/,\002 Ratio of flow depth to vertical diameter\
 at culvert\002,\002 exit\002,/,\002 that causes submergence=\002,f5.2)";
    static char fmt_38[] = "(/,\002  Maximum ratio of depth to vertical diam\
eter\002,\002 for Type 1 flow=\002,f5.3)";
    static char fmt_39[] = "(/,\002 Maximum ratio of head to vertical diamet\
er for\002,\002 type 1 and 2 flow=\002,f5.3)";
    static char fmt_40[] = "(/,\002 Processing cannot continue on the curren\
t culvert because\002,/,\002 it has either a break in slope or a non-unifor\
m\002,/,\002 non-prismatic shape.  The automatic procedure to insert\002,/\
,\002 nodes will not function on culverts like this.  The CULVERT\002,/,\002\
 command expects the culvert barrel to have two nodes\002,/,\002 placed at s\
pecial locations close to its inlet.  The first\002,/,\002 special node must\
 be at a distance of 3 times the vertical\002,/,\002 diameter of the barrel \
from its inlet.   The second special\002,/,\002 node must be at a distance o\
f 6 times the  vertical\002,/,\002 diameter from the inlet.  These special n\
odes are used\002,/,\002 in computing Type 5 flow and must be present.  Culv\
erts too\002,/,\002 short for the placement of these special nodes cannot b\
e\002,/,\002 analyzed if their barrels have a break in slope or if the\002,/,\
\002 barrel is non-uniform non-prismatic.  Breaks in slope must\002,/,\002 b\
e used with caution because the analysis procedure does\002,/,\002 not find \
control points within the culvert barrel.\002)";
    static char fmt_41[] = "(/,\002 Flows for water levels at section 4.\002\
,/,\002    Road submergence at section 43.\002,//,\002 Upstream Head=\002,f9\
.4,\002  Free Drop=\002,f9.4)";
    static char fmt_42[] = "(\002  Processing CULVERT TabId= \002,a)";
    static char fmt_43[] = "(/,1x,\002Partial Depth Head  Head  Head  Drop  \
Flow   Flow   Total \002,\002 Loss Energy Energy\002,/,1x,\002free    at    \
at    at    at    sec   in     over   flow  \002,\002 coef loss   loss  \002\
,/,1x,\002drop    sec 3 sec 3 sec44 sec 4 1->4  barrel road         \002,\
\002 3->4 3->4   1->4  \002,/,1x,\002------- ----- ----- ----- ----- ----- -\
----- ------ ------\002,\002 ---- ------ ------\002)";
    static char fmt_44[] = "(1x,\002----------------------------------------\
------------------\002,\002--------------------\002)";
    static char fmt_45[] = "(1x,f7.4,4f6.2,f6.3,3a7,a5,a7,f7.3)";
    static char fmt_46[] = "(/,\002 ERR:705* Rounding/beveling value < 0.0 o\
r > 0.14\002)";
    static char fmt_47[] = "(/,\002 ERR:706* Wingwall angle < 0.0 or > 90.0 \
degrees.\002)";
    static char fmt_48[] = "(1x,\002Note: Barrel flows full at section 3 whe\
n depth\002,\002 there=\002,f8.3)";
    static char fmt_49[] = "(/,1x,\002*WRN:**** Flow Type 7 indicates that t\
he downstream\002,\002 section\002,/,11x,\002of the departure reach drowns a\
ll other\002,\002 control points. This is\002,/,11x,\002non-standard but no\
t\002,\002 unusual.  However, Type 7 flow requires\002,/,11x,\002several\002,\
\002 unverified assumptions. Please check results carefully.\002)";
    static char fmt_50[] = "(/,\002 TABID= \002,a,2x,a)";
    static char fmt_51[] = "(/,\002 *ERR:707* Type 5 submergence ratio < 0.0\
 or > 1.0\002)";
    static char fmt_52[] = "(/,\002 \002,a5,\002=\002,a)";
    static char fmt_53[] = "(/,\002 *ERR:708* Ratio of depth to vertical dia\
meter <= 0.5\002,\002 or >= 1.0\002)";
    static char fmt_54[] = "(/,\002 \002,\002 APPTAB= \002,a)";
    static char fmt_55[] = "(/,\002 *ERR:709* Ratio of head to vertical diam\
eter < 1.0 or\002,\002 >= 1.5\002)";
    static char fmt_56[] = "(\002 \002,a6,\002=\002,f10.2)";
    static char fmt_57[] = "(\002 \002,a6,\002=\002,f10.2,a10,2a5)";
    static char fmt_58[] = "(\002 \002,a6,\002=\002,f10.1)";
    static char fmt_60[] = "(\002 \002,a6,\002=\002,a8)";
    static char fmt_61[] = "(/,\002 \002,a6,\002=\002,a8)";
    static char fmt_62[] = "(/,\002 Culvert barrel length <= 3 times its ver\
tical\002,\002 diameter.  Culvert losses\002,/,\002  will be overestimated\
.\002)";
    static char fmt_63[] = "(\002 *ERR:603* ROADWAY MOMENTUM FLUX FACTOR=\
\002,f6.3,\002 < 0 OR > 1.\002)";
    static char fmt_64[] = "(/,\002 Discharge coefficient for flow types 4 a\
nd 6=\002,f5.3,/,12x,\002 Type 6 jet assumed supported.\002)";
    static char fmt_65[] = "(/,1x,\002Departure reach start elev.=\002,f10.2\
,/,1x,\002Departure reach end elev.=\002,f10.2)";
    static char fmt_66[] = "(/,\002 Wingwall angle adjustment factor=\002,f5\
.3)";
    static char fmt_67[] = "(/,\002 Discharge coefficient for flow types 4 a\
nd 6=\002,f5.3,/,12x,\002 Type 6 jet assumed unsupported.\002)";
    static char fmt_68[] = "(/,\002 Projecting-pipe adjustment factor=\002,f\
5.3)";
    static char fmt_69[] = "(/,\002 Rounding/beveling adjustment factor=\002\
,f5.3)";
    static char fmt_70[] = "(\002 *ERR:710* At least one submergence table i\
s unknown.\002,\002 Both must be known.\002)";
    static char fmt_71[] = "(/,\002  Table type 5 replaced by type 13.\002)";
    static char fmt_72[] = "(\002 *ERR:578* APPROACH REACH LENGTH=\002,f10\
.2,\002 < 0.\002)";
    static char fmt_73[] = "(\002 *ERR:579* APPROACH LOSS COEF. < 0 OR > 1\
.\002)";
    static char fmt_74[] = "(/,\002 *WRN:582* The culvert barrel has slope b\
reaks.  The\002,\002 CULVERT command may fail.\002)";
    static char fmt_75[] = "(\002 *ERR:581* APPROACH EXPANSION COEF. < 0 OR \
> 1.\002)";
    static char fmt_76[] = "(\002 *ERR:582* ROUNDING/BEVELING FACTOR < 1 OR \
> 1.5.\002)";
    static char fmt_77[] = "(\002 *ERR:583* DEPARTURE CONTRACTION COEF. < 0 \
OR > 1.\002)";
    static char fmt_78[] = "(\002 *ERR:584* WINGWALL FACTOR < 1 OR > 1.25\
.\002)";
    static char fmt_79[] = "(\002 *ERR:604* WIDTH FACTOR FOR DEPARTURE REACH\
 <= 1.0\002)";
    static char fmt_80[] = "(\002 *ERR:585* PROJECTION ADJUSTMENT < 0.90 OR \
> 1.\002)";
    static char fmt_81[] = "(\002 *ERR:605* BEGINNING ELEV. FOR DEP. RCH.\
=\002,f10.2,\002 >\002,\002 CLVRT EXIT ELEV.=\002,f10.2)";
    static char fmt_82[] = "(\002 *ERR:586* LOSS OPTION: \002,a8,\002 INVALI\
D.\002)";
    static char fmt_83[] = "(/,\002 Culvert barrel length <= 6 times its ver\
tical\002,\002 diameter.  Culvert losses\002,/,\002  may be overestimated\
.\002)";
    static char fmt_84[] = "(\002 *ERR:587* CULVERT CLASS:\002,a8,\002 INVAL\
ID.\002)";
    static char fmt_86[] = "(\002 *ERR:588* TYPE 4-6 COEF.:\002,f5.2,\002  <\
 0.60 OR > 1.\002)";
    static char fmt_87[] = "(\002 *ERR:607* TABLE# <= 0\002)";
    static char fmt_88[] = "(\002 \002,a6,\002=\002,a4)";
    static char fmt_89[] = "(\002 *ERR:608* SUBMERGED ROAD FLOW WITH FREE CU\
LVERT FLOW\002,\002 NOT YET SUPPORTED.\002)";
    static char fmt_90[] = "(\002 \002,a4,\002=\002,f10.2)";
    static char fmt_91[] = "(\002 *WRN:547* Road is lower than a culvert sof\
fit\002,\002 elevation.\002)";
    static char fmt_92[] = "(/,\002 \002,a80)";
    static char fmt_93[] = "(\002 *ERR:609* Road crest elev. < head datum in\
valid.\002)";
    static char fmt_94[] = "(/,\002 Number of partial free drops=\002,i5)";
    static char fmt_95[] = "(/,\002 \002,\002Input complete. Begin computati\
ons.\002,//,\002 \002,\002 Upstream opening=\002,f8.4,\002 Downstream openin\
g=\002,f8.4)";
    static char fmt_96[] = "(/,\002 \002,\002Datum for heads is:\002,f10.4)";
    static char fmt_97[] = "(2x,a4,\002=\002,i5,\002 Flap gate factor=\002,f\
5.2)";
    static char fmt_98[] = "(\002 *ERR:589* TABLE TYPE NOT 6 or 13.\002)";
    static char fmt_99[] = "(/,\002 *ERR:630* Upstream heads non-increasing \
at:\002,f10.4)";
    static char fmt_101[] = "(/,\002 *ERR:610* Free drop=\002,f8.4,\002 <\
 \002,f8.4,\002 not\002,\002 yet supported.\002)";
    static char fmt_102[] = "(\002 \002,\002DEPTAB= \002,a,\002  BEGTAB= \
\002,a,\002  RMFFAC=\002,f5.0)";
    static char fmt_1050[] = "(/,\002 FHWA a coefficient=\002,f5.2)";
    static char fmt_1051[] = "(/,\002 FHWA c coefficient=\002,f8.4)";
    static char fmt_1052[] = "(/,\002 FHWA Y coefficient=\002,f8.4)";
    static char fmt_1053[] = "(/,\002 FHWA barrel slope=\002,f10.4)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3, feq_gen_r_d_4;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;
    char feq_gen_ch_d_1[8], feq_gen_ch_d_2[16];
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(), 
	    s_rsfi(icilist *), e_rsfi(), s_cmp(char *, char *, ftnlen, ftnlen)
	    , s_wsfi(icilist *), e_wsfi(), s_rsli(icilist *), do_lio(integer *
	    , integer *, char *, ftnlen), e_rsli();
    double pow_dd(doublereal *, doublereal *);
    integer s_wsle(cilist *), e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    real yexit, z1true, z3psav, z3sav, z3sof, z44sav, z4old, z4sav, zdatum, 
	    zsbrdf, y2mat[53001]	/* was [151][351] */, zrhufd;
    doublereal easting;
    char bnodid[8*8400], c5vec[5*3], char10[10], char4[4], char5[5], char6[6],
	     char7[7], culcls[8], label[50], line[80], line120[120], losopt[8]
	    , nodeid[4], cqfree[7], cwfrd[7], cboth[7], cqclv[7], tabid[16], 
	    deptabid[16], begtabid[16], char16[16], apptabid[16], zone[8], 
	    hgrid[8], vdatum[8], unitsys[8], basis[8];
    extern doublereal fdfrfc_(integer *, integer *), getd_(integer *, integer 
	    *);
    extern integer lenstr_(char *, ftnlen);
    extern /* Character */ VOID gettok_(char *, ftnlen, char *, ftnlen);
    extern /* Subroutine */ int chkcfc_(real *, integer *, integer *, integer 
	    *), chkdep_(integer *, integer *, integer *), chktab_(integer *, 
	    integer *, integer *, integer *, integer *, integer *), chktel_(
	    integer *, integer *, real *, integer *, real *, real *), clvin_(
	    real *, integer *, integer *, integer *, integer *, char *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, real *, real *, real *
	    , real *, integer *, char *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, ftnlen, ftnlen), embsub_(integer 
	    *, real *, integer *, char *, real *, real *, real *, real *, 
	    doublereal *, real *, ftnlen), etabin_(integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *), fdcd46_(integer *, char *, real 
	    *, real *, ftnlen), fhhtyp_(integer *, char *, real *, real *, 
	    real *, real *, integer *, integer *, real *, real *, real *, 
	    integer *, real *, real *, ftnlen), frfclv_(integer *, real *, 
	    real *, real *, real *, real *, integer *, integer *, char *, 
	    integer *, integer *, integer *, integer *, real *, real *, real *
	    , ftnlen), frfemb_(real *, real *, integer *, integer *, integer *
	    , integer *, integer *, real *, real *, real *, real *, char *, 
	    real *, real *, real *, integer *, integer *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, ftnlen), frft7_(integer *, real *, integer *, real *, 
	    char *, real *, integer *, integer *, real *, real *, real *, 
	    ftnlen), inline_(integer *, integer *, char *, ftnlen), inprdp_(
	    integer *, integer *, real *, integer *, integer *, real *, 
	    integer *, real *, real *, real *, real *, char *, ftnlen), 
	    insert_(real *, real *, integer *, integer *, real *, integer *), 
	    lkta_(integer *, real *, real *), lktab_(integer *, real *, 
	    integer *, real *, integer *, real *);
    doublereal northing;
    extern /* Subroutine */ int lktk_(integer *, real *, real *), qvstw_(
	    integer *, real *, integer *, integer *, integer *, real *, real *
	    , char *, real *, real *, real *, real *, real *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, ftnlen), 
	    tabchk_(integer *, integer *, integer *, integer *, integer *), 
	    tdlk10_(integer *, integer *, integer *, real *, real *, real *, 
	    real *, real *), twdout_(integer *, integer *, integer *, char *, 
	    integer *, integer *, real *, real *, real *, real *, real *, 
	    integer *, char *, real *, char *, char *, char *, char *, char *,
	     doublereal *, doublereal *, integer *, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen), xlkt22_(integer *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *), xlktal_(integer *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *), 
	    feq_gen_get_internal_tab_number_d_(integer *, char *, integer *, integer *,
	     ftnlen), feq_gen_strip_l_blanks_d_(char *, ftnlen), feq_gen_read_tabid_plus_d_(
	    integer *, char *, integer *, char *, integer *, char *, ftnlen, 
	    ftnlen, ftnlen), feq_gen_get_lctn_items_d_(integer *, integer *, integer *)
	    , feq_gen_set_lctn_items_d_(char *, char *, char *, char *, char *, 
	    doublereal *, doublereal *, ftnlen, ftnlen, ftnlen, ftnlen, 
	    ftnlen), feq_gen_get_departure_items_d_(integer *, integer *, integer *), 
	    twodfit_(integer *, integer *, integer *, integer *, real *, real 
	    *, real *, real *, real *, integer *, char *, real *, integer *, 
	    integer *, integer *, integer *, ftnlen), twod13put_(integer *, 
	    integer *, integer *, integer *, real *, real *, real *, real *, 
	    real *, integer *, integer *, integer *);
    real feq_gen_h_d_;
    integer feq_gen_i_d_, j;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real df, ed;
    integer id;
    doublereal fd;
    real dq, eu;
    integer it, iu;
    real hp;
    integer nt;
    extern /* Subroutine */ int feq_gen_read_tabid_d_(integer *, char *, char *, 
	    integer *, char *, integer *, ftnlen, ftnlen, ftnlen);
    real zt, dy2, dz4, qc3, de14, de34, x3d, x6d;
    extern /* Subroutine */ int feq_gen_set_depitm_d_(integer *, integer *, real *, 
	    integer *);
    integer tab;
    real cl34, ddn;
    integer nbn;
    real dup;
    integer nhu;
    real hup;
    extern /* Subroutine */ int feq_gen_var_decimal_d_(real *, char *, ftnlen), 
	    feq_gen_get_putget_options_d_(integer *, integer *, char *, integer *, 
	    integer *, ftnlen);
    real cct5, dfdc;
    char head[80], cl34c[5];
    integer chk23;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    integer nbra, ntab;
#define pgover (feq::BitView<integer>(&putget_1, sizeof(putget_1)))
    integer bshape, chkbar, conflg, expflg, frtype, ftptmp, iflag, nfrac, 
	    q3vsrd, tabtyp, feq_gen_type_d_, typflg, wflag, y3vstw, y2vsd, ftpbase, 
	    ftpup, verbose, brpt[8]	/* was [8][1] */, negtab[8400], 
	    feq_gen_default_tabvec_d_[13];
    real a1true, alp1t, ddrop, depcon, dfdr, drop, fdrdw, fdrop, fdvec[151], 
	    freed, hcrest, hdatum, hhlim, hrdfd, hrdfu, huold, huvec[151], 
	    k1true, pfdvec[351], power, qclv, qfree, qmat[53001]	/* 
	    was [151][351] */, qold, ratio, rdflow, sfac, y3limu;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__278 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__279 = { 0, 6, 0, fmt_42, 0 };
    static cilist feq_gen_io_d__282 = { 0, 0, 0, fmt_97, 0 };
    static cilist feq_gen_io_d__283 = { 0, 0, 0, fmt_71, 0 };
    static cilist feq_gen_io_d__284 = { 0, 0, 0, fmt_98, 0 };
    static cilist feq_gen_io_d__294 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__296 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__298 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__299 = { 0, 0, 0, fmt_87, 0 };
    static cilist feq_gen_io_d__301 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__302 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__303 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__304 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__305 = { 0, 0, 0, fmt_73, 0 };
    static cilist feq_gen_io_d__306 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__307 = { 0, 0, 0, fmt_75, 0 };
    static cilist feq_gen_io_d__308 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__310 = { 0, 0, 0, fmt_88, 0 };
    static cilist feq_gen_io_d__312 = { 0, 0, 0, fmt_90, 0 };
    static cilist feq_gen_io_d__322 = { 0, 0, 0, fmt_61, 0 };
    static cilist feq_gen_io_d__323 = { 0, 0, 0, fmt_84, 0 };
    static cilist feq_gen_io_d__324 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__327 = { 0, 0, 0, fmt_102, 0 };
    static cilist feq_gen_io_d__328 = { 0, 0, 0, fmt_87, 0 };
    static cilist feq_gen_io_d__329 = { 0, 0, 0, fmt_63, 0 };
    static cilist feq_gen_io_d__332 = { 0, 0, 0, fmt_57, 0 };
    static cilist feq_gen_io_d__333 = { 0, 0, 0, fmt_81, 0 };
    static cilist feq_gen_io_d__334 = { 0, 0, 0, fmt_79, 0 };
    static cilist feq_gen_io_d__335 = { 0, 0, 0, fmt_65, 0 };
    static cilist feq_gen_io_d__339 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__340 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__342 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__343 = { 0, 0, 0, fmt_77, 0 };
    static cilist feq_gen_io_d__344 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__348 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__350 = { 0, 0, 0, fmt_46, 0 };
    static cilist feq_gen_io_d__351 = { 0, 0, 0, fmt_30, 0 };
    static cilist feq_gen_io_d__352 = { 0, 0, 0, fmt_29, 0 };
    static cilist feq_gen_io_d__353 = { 0, 0, 0, fmt_25, 0 };
    static cilist feq_gen_io_d__354 = { 0, 0, 0, fmt_36, 0 };
    static cilist feq_gen_io_d__355 = { 0, 0, 0, fmt_47, 0 };
    static cilist feq_gen_io_d__356 = { 0, 0, 0, fmt_28, 0 };
    static cilist feq_gen_io_d__357 = { 0, 0, 0, fmt_13, 0 };
    static cilist feq_gen_io_d__358 = { 0, 0, 0, fmt_37, 0 };
    static cilist feq_gen_io_d__359 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__360 = { 0, 0, 0, fmt_1050, 0 };
    static cilist feq_gen_io_d__361 = { 0, 0, 0, fmt_1051, 0 };
    static cilist feq_gen_io_d__362 = { 0, 0, 0, fmt_1052, 0 };
    static cilist feq_gen_io_d__363 = { 0, 0, 0, fmt_1053, 0 };
    static cilist feq_gen_io_d__364 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__365 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__366 = { 0, 0, 0, fmt_38, 0 };
    static cilist feq_gen_io_d__367 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__368 = { 0, 0, 0, fmt_39, 0 };
    static cilist feq_gen_io_d__369 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__374 = { 0, 0, 0, fmt_69, 0 };
    static cilist feq_gen_io_d__375 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__376 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__377 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__378 = { 0, 0, 0, fmt_8, 0 };
    static cilist feq_gen_io_d__379 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__380 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__381 = { 0, 0, 0, fmt_9, 0 };
    static cilist feq_gen_io_d__382 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__383 = { 0, 0, 0, fmt_67, 0 };
    static cilist feq_gen_io_d__384 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__385 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__386 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__387 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__389 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__391 = { 0, 0, 0, fmt_11, 0 };
    static cilist feq_gen_io_d__396 = { 0, 0, 0, fmt_99, 0 };
    static cilist feq_gen_io_d__399 = { 0, 0, 0, fmt_95, 0 };
    static cilist feq_gen_io_d__400 = { 0, 0, 0, fmt_31, 0 };
    static cilist feq_gen_io_d__402 = { 0, 0, 0, fmt_32, 0 };
    static cilist feq_gen_io_d__403 = { 0, 0, 0, fmt_33, 0 };
    static cilist feq_gen_io_d__404 = { 0, 0, 0, fmt_32, 0 };
    static cilist feq_gen_io_d__407 = { 0, 0, 0, fmt_96, 0 };
    static cilist feq_gen_io_d__408 = { 0, 0, 0, fmt_93, 0 };
    static cilist feq_gen_io_d__409 = { 0, 0, 0, fmt_91, 0 };
    static cilist feq_gen_io_d__413 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__414 = { 0, 0, 0, fmt_83, 0 };
    static cilist feq_gen_io_d__415 = { 0, 0, 0, fmt_40, 0 };
    static cilist feq_gen_io_d__416 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__420 = { 0, 0, 0, fmt_34, 0 };
    static cilist feq_gen_io_d__421 = { 0, 0, 0, fmt_3, 0 };
    static cilist feq_gen_io_d__422 = { 0, 0, 0, fmt_35, 0 };
    static cilist feq_gen_io_d__423 = { 0, 0, 0, fmt_5, 0 };
    static cilist feq_gen_io_d__450 = { 0, 0, 0, fmt_101, 0 };
    static cilist feq_gen_io_d__451 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__452 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__453 = { 0, 6, 0, 0, 0 };
    static cilist feq_gen_io_d__470 = { 0, 0, 0, fmt_49, 0 };
    static cilist feq_gen_io_d__471 = { 0, 0, 0, fmt_89, 0 };
    static cilist feq_gen_io_d__472 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__473 = { 0, 0, 0, fmt_41, 0 };
    static cilist feq_gen_io_d__474 = { 0, 0, 0, fmt_43, 0 };
    static cilist feq_gen_io_d__480 = { 0, 0, 0, fmt_45, 0 };
    static cilist feq_gen_io_d__481 = { 0, 0, 0, fmt_41, 0 };
    static cilist feq_gen_io_d__482 = { 0, 0, 0, fmt_43, 0 };
    static cilist feq_gen_io_d__483 = { 0, 0, 0, fmt_45, 0 };
    static cilist feq_gen_io_d__496 = { 0, 0, 0, fmt_45, 0 };
    static cilist feq_gen_io_d__497 = { 0, 0, 0, fmt_44, 0 };
    static cilist feq_gen_io_d__498 = { 0, 0, 0, fmt_48, 0 };
    static cilist feq_gen_io_d__502 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__503 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Compute a two-d table for flow through one or more culverts */
/*     including possible flow over the roadway. */
/* SOURCE culverta.for:2880 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culverta.for:2882 */
/*<       integereflag,ftknt,ftp,stdin,stdout,stdtab >*/
/* SOURCE culverta.for:2883 */
/*<       integertabdir(*) >*/
/* SOURCE culverta.for:2884 */
/*<       realnfac >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     NFAC   - Factor in Manning's formula(1.49 or 1.0) */
/*     TABDIR - Table directory to remember table numbers */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     FTP    - next open location in the function table storage */
/*     FTKNT  - function table counter */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culverta.for:2897 */
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
/* INCLUDE culverta.for:2898 */
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
/* INCLUDE culverta.for:2899 */
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
/* INCLUDE culverta.for:2900 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culverta.for:2901 */
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
/* INCLUDE culverta.for:2902 */
/* SOURCE appcom.cmn:2 */
/*<       common/appcom/apptab,appelv,applen,applos,appexp,zertab,zerelv >*/
/* SOURCE appcom.cmn:5 */
/*<       integerapptab,zertab >*/
/* SOURCE appcom.cmn:7 */
/*<       realappelv,applen,applos,appexp,zerelv >*/
/* INCLUDE culverta.for:2903 */
/* SOURCE xs0com.cmn:2 */
/*<        >*/
/* SOURCE xs0com.cmn:5 */
/*<       integeradrxs0 >*/
/* SOURCE xs0com.cmn:7 */
/*<        >*/
/* INCLUDE culverta.for:2904 */
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
/* INCLUDE culverta.for:2905 */
/* SOURCE xs2com.cmn:2 */
/*<        >*/
/* SOURCE xs2com.cmn:8 */
/*<       integeradrxs2,lftype,ty6opt,lstype >*/
/* SOURCE xs2com.cmn:10 */
/*<        >*/
/* INCLUDE culverta.for:2906 */
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
/* INCLUDE culverta.for:2907 */
/* SOURCE xs4com.cmn:2 */
/*<        >*/
/* SOURCE xs4com.cmn:5 */
/*<       integeradrxs4 >*/
/* SOURCE xs4com.cmn:7 */
/*<        >*/
/* INCLUDE culverta.for:2908 */
/* SOURCE x43com.cmn:2 */
/*<        >*/
/* SOURCE x43com.cmn:6 */
/*<       integeradrs43,stat43 >*/
/* SOURCE x43com.cmn:8 */
/*<        >*/
/* INCLUDE culverta.for:2909 */
/* SOURCE x44com.cmn:2 */
/*<        >*/
/* SOURCE x44com.cmn:6 */
/*<       integeradrs44,stat44 >*/
/* SOURCE x44com.cmn:8 */
/*<        >*/
/* INCLUDE culverta.for:2910 */
/*     Common to hold values needed for computing various limits */
/*     for culvert flow types. */
/* SOURCE typlim.cmn:4 */
/*<        >*/
/* SOURCE typlim.cmn:10 */
/*<       integerhhtype >*/
/* SOURCE typlim.cmn:12 */
/*<        >*/
/* INCLUDE culverta.for:2911 */
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
/* INCLUDE culverta.for:2912 */
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
/* INCLUDE culverta.for:2913 */
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
/* INCLUDE culverta.for:2914 */
/*     COMMOM BLOCK FOR THE DESCRIPTION OF THE FLOW OVER AN EMBANKMENT */
/* SOURCE embcom.cmn:3 */
/*<       character*8surf(pmxoff) >*/
/* SOURCE embcom.cmn:5 */
/*<       integernoff,minloc,plcwtb,glcwtb,phcwtb,ghcwtb,psubtb,gsubtb >*/
/* SOURCE embcom.cmn:8 */
/*<       realmincrs,rmffac >*/
/* SOURCE embcom.cmn:10 */
/*<        >*/
/* SOURCE embcom.cmn:20 */
/*<       common/embcmc/surf >*/
/* SOURCE embcom.cmn:22 */
/*<        >*/
/* INCLUDE culverta.for:2915 */
/* SOURCE depcom.cmn:2 */
/*<       common/depcom/deptab,begtab,depelv,begelv,widfac,dsffac,deptyp >*/
/* SOURCE depcom.cmn:5 */
/*<       integerdeptab,begtab,deptyp >*/
/* SOURCE depcom.cmn:7 */
/*<       realdepelv,begelv,widfac,dsffac >*/
/* INCLUDE culverta.for:2916 */
/*     Common block for key values describing the nature of weir */
/*     flow. */
/* SOURCE embwrq.cmn:4 */
/*<       integerhlflag,hpflag >*/
/* SOURCE embwrq.cmn:6 */
/*<       realhlcrit,hlmax >*/
/* SOURCE embwrq.cmn:8 */
/*<       common/embq/hlflag,hpflag,hlcrit,hlmax >*/
/* SOURCE embwrq.cmn:10 */
/*<       save/embq/ >*/
/*     HLCRIT  Ratio of piezometric head to crest breadth at boundary */
/*             between low head and high head flow in the USGS */
/*             embankment-shaped weir methodology. */
/*     HLMAX   Maximum value of piezometric head to crest breadth ratio */
/*             above which a warning message is issued. */
/*     HLFLAG  Warning message suppression flag for warnings about the */
/*             piezometric head to crest breadth ratio becoming greater */
/*             than HLMAX */
/*     HPFLAG  Warning message suppression flag for invalid weir flow */
/* INCLUDE culverta.for:2917 */
/*     Common block for flapgate on culvert. */
/* SOURCE flapgate.cmn:3 */
/*<       common/flapgate/flap >*/
/* SOURCE flapgate.cmn:5 */
/*<       realflap >*/
/* SOURCE flapgate.cmn:7 */
/*<       save/flapgate/ >*/
/*     If FLAP=0.0 then no gate is present. Otherwise FLAP is a */
/*     factor on the internal headloss coefficient. */
/* INCLUDE culverta.for:2918 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE culverta.for:2919 */
/*     Common block for the values used in putting function tables */
/*     into FTAB/ITAB and getting the same. */
/*     The following commands make use of the following values: */
/*     CULVERT: */
/*       Single valued ids: */
/*         PUTQ- Table number for flow in the culvert */
/*         PUTY2- Table number for depth at section 2 */
/*         PUTMF3- Table number for momentum flux out of culvert barrel */
/*         PUTY3- Table number for depth at section 3. */
/*       Multiple valued ids: */
/*          GETQ- one or more table numbers specifing the flow into */
/*                departure reach from overbank areas where flow was */
/*                represented using the commands EMBANKQ, CHANRAT or */
/*                similar command. */
/*          GETMF- one or more table numbers specifing the momentum */
/*                flux into the departure reach from the same sources */
/*                as GETQ */
/*     CHANRAT */
/*       PUTQ- Table number for flow in the channel */
/*       PUTMF- Table number for the momentum flux from the dns end */
/*              of the channel. */
/*     EMBANKQ */
/*       PUTQ- Table number for flow over the embankment */
/*       PUTMF-Table number for momentum flux estimated for */
/*             the crest of the embankment. */
/*     ORIFICE */
/*       PUTQ-Table number for flow through the orifice */
/*       PUTMF-Table number for the momentum flux through the */
/*             orifice. */
/* SOURCE putget.cmn:38 */
/*<       integermxget,mxover >*/
/* SOURCE putget.cmn:39 */
/*<       parameter(mxget=50,mxover=5+2*(mxget+1)) >*/
/* SOURCE putget.cmn:41 */
/*<        >*/
/* SOURCE putget.cmn:45 */
/*<       common/putget/putq,putmf,putmf3,puty2,puty3,getq,getmf >*/
/* SOURCE putget.cmn:47 */
/*<       equivalence(putq,pgover) >*/
/* SOURCE putget.cmn:49 */
/*<       save/putget/ >*/
/* INCLUDE culverta.for:2920 */
/*     common for passing info for table upgrading-going from one form */
/*     to one that is smoother in its representation */
/* SOURCE tabupgrade.cmn:4 */
/*<       characterty13_to_ty43*4,twod_cubic_out*4,upgrade_xsec_tab*4 >*/
/* SOURCE tabupgrade.cmn:6 */
/*<       common/upgrdc/ty13_to_ty43,twod_cubic_out,upgrade_xsec_tab >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culverta.for:2923 */
/*<       integerculvert >*/
/* SOURCE culverta.for:2924 */
/*<       parameter(culvert=1) >*/
/* SOURCE culverta.for:2926 */
/*<        >*/
/* SOURCE culverta.for:2930 */
/*<       integerbrpt(8,1),negtab(mnbn),default_tabvec(13) >*/
/* SOURCE culverta.for:2931 */
/*<        >*/
/* SOURCE culverta.for:2940 */
/*<       real*8fd,easting,northing >*/
/* SOURCE culverta.for:2941 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culverta.for:2949 */
/*<       intrinsicabs,dble,float,max,min >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culverta.for:2952 */
/*<       realfdfrfc,getd >*/
/* SOURCE culverta.for:2953 */
/*<       integerlenstr >*/
/* SOURCE culverta.for:2954 */
/*<       charactergettok*8,get_tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culverta.for:2957 */
/*<        >*/
/*     + + + INPUT FORMATS + + + */
/* SOURCE culverta.for:2965 */
/*<     1 format(7x,i5,1x,a80) >*/
/* SOURCE culverta.for:2966 */
/*<     2 format(a5,1x,a) >*/
/* SOURCE culverta.for:2967 */
/*<     4 format(a6,2x,i5,2a5) >*/
/* SOURCE culverta.for:2968 */
/*<     6 format(a6,1x,f10.0) >*/
/* SOURCE culverta.for:2969 */
/*<     7 format(a6,1x,f10.0,a10,2a5) >*/
/* SOURCE culverta.for:2970 */
/*<    10 format(a6,1x,a8) >*/
/* SOURCE culverta.for:2971 */
/*<    12 format(a6,1x,a8) >*/
/* SOURCE culverta.for:2972 */
/*<    14 format(3x,1x,f10.0,1x,a4) >*/
/* SOURCE culverta.for:2973 */
/*<    15 format(a7,1x,f10.0) >*/
/* SOURCE culverta.for:2974 */
/*<    16 format(a5,1x,f10.0) >*/
/* SOURCE culverta.for:2975 */
/*<    17 format(8x,f10.0) >*/
/* SOURCE culverta.for:2976 */
/*<    18 format(a5,1x,f10.0) >*/
/* SOURCE culverta.for:2977 */
/*<    19 format(9x,f10.0) >*/
/* SOURCE culverta.for:2978 */
/*<    20 format(a6,1x,a4) >*/
/* SOURCE culverta.for:2979 */
/*<    21 format(7x,f10.0) >*/
/* SOURCE culverta.for:2980 */
/*<    22 format(a4,1x,f10.0) >*/
/* SOURCE culverta.for:2981 */
/*<    23 format(7x,f10.3) >*/
/* SOURCE culverta.for:2982 */
/*<    24 format(a80) >*/
/* SOURCE culverta.for:2983 */
/*<    26 format(a5,1x,i5) >*/
/* SOURCE culverta.for:2984 */
/*<    27 format(a4,1x,i5,1x,9x,f5.0) >*/
/* SOURCE culverta.for:2985 */
/*<  1000 format(6x,f10.0) >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culverta.for:2988 */
/*<     3  >*/
/* SOURCE culverta.for:2990 */
/*<     5  >*/
/* SOURCE culverta.for:2992 */
/*<     8  >*/
/* SOURCE culverta.for:2994 */
/*<     9  >*/
/* SOURCE culverta.for:2996 */
/*<    11 format(/,' Power for distributing partial free drops=',f5.1) >*/
/* SOURCE culverta.for:2997 */
/*<    13 format(/,' *ERR:721* Relative projection < 0.') >*/
/* SOURCE culverta.for:2998 */
/*<    25 format(/,' Angle of inlet bevel=',f5.1,' degrees.') >*/
/* SOURCE culverta.for:2999 */
/*<    28 format(/,' Relative projection=',f8.3) >*/
/* SOURCE culverta.for:3000 */
/*<    29 format(/,' *ERR:722* Angle of inlet bevel < 0 or > 90 degrees.') >*/
/* SOURCE culverta.for:3001 */
/*<    30 format(/,' Rounding/beveling value=',f5.3) >*/
/* SOURCE culverta.for:3002 */
/*<    31 format(/,' Checking the critical flow variation',' at section 2.') >*/
/* SOURCE culverta.for:3004 */
/*<    32  >*/
/* SOURCE culverta.for:3008 */
/*<    33 format(/,' Checking the critical flow variation',' at section 3.') >*/
/* SOURCE culverta.for:3010 */
/*<    34  >*/
/* SOURCE culverta.for:3012 */
/*<    35  >*/
/* SOURCE culverta.for:3014 */
/*<    36 format(/,' Wingwall angle=',f5.0,' degrees.') >*/
/* SOURCE culverta.for:3015 */
/*<    37  >*/
/* SOURCE culverta.for:3017 */
/*<    38  >*/
/* SOURCE culverta.for:3019 */
/*<    39  >*/
/* SOURCE culverta.for:3021 */
/*<    40  >*/
/* SOURCE culverta.for:3038 */
/*<    41  >*/
/* SOURCE culverta.for:3041 */
/*<    42 format('  Processing CULVERT TabId= ',a) >*/
/* SOURCE culverta.for:3042 */
/*<    43  >*/
/* SOURCE culverta.for:3051 */
/*<    44  >*/
/* SOURCE culverta.for:3054 */
/*<    45 format(1x,f7.4,4f6.2,f6.3,3a7,a5,a7,f7.3) >*/
/* SOURCE culverta.for:3055 */
/*<    46 format(/,' ERR:705* Rounding/beveling value < 0.0 or > 0.14') >*/
/* SOURCE culverta.for:3056 */
/*<    47 format(/,' ERR:706* Wingwall angle < 0.0 or > 90.0 degrees.') >*/
/* SOURCE culverta.for:3057 */
/*<    48  >*/
/* SOURCE culverta.for:3059 */
/*<    49  >*/
/* SOURCE culverta.for:3064 */
/*<    50 format(/,' TABID= ',a,2x,a) >*/
/* SOURCE culverta.for:3065 */
/*<    51 format(/,' *ERR:707* Type 5 submergence ratio < 0.0 or > 1.0') >*/
/* SOURCE culverta.for:3066 */
/*<    52 format(/,' ',a5,'=',a) >*/
/* SOURCE culverta.for:3067 */
/*<    53  >*/
/* SOURCE culverta.for:3069 */
/*<    54 format(/,' ',' APPTAB= ',a) >*/
/* SOURCE culverta.for:3070 */
/*<    55  >*/
/* SOURCE culverta.for:3072 */
/*<    56 format(' ',a6,'=',f10.2) >*/
/* SOURCE culverta.for:3073 */
/*<    57 format(' ',a6,'=',f10.2,a10,2a5) >*/
/* SOURCE culverta.for:3074 */
/*<    58 format(' ',a6,'=',f10.1) >*/
/* SOURCE culverta.for:3075 */
/*<    59 format(' BEGTAB=',i5) >*/
/* SOURCE culverta.for:3076 */
/*<    60 format(' ',a6,'=',a8) >*/
/* SOURCE culverta.for:3077 */
/*<    61 format(/,' ',a6,'=',a8) >*/
/* SOURCE culverta.for:3078 */
/*<    62  >*/
/* SOURCE culverta.for:3080 */
/*<    63  >*/
/* SOURCE culverta.for:3082 */
/*<    64  >*/
/* SOURCE culverta.for:3084 */
/*<    65  >*/
/* SOURCE culverta.for:3086 */
/*<    66 format(/,' Wingwall angle adjustment factor=',f5.3) >*/
/* SOURCE culverta.for:3087 */
/*<    67  >*/
/* SOURCE culverta.for:3089 */
/*<    68 format(/,' Projecting-pipe adjustment factor=',f5.3) >*/
/* SOURCE culverta.for:3090 */
/*<    69 format(/,' Rounding/beveling adjustment factor=',f5.3) >*/
/* SOURCE culverta.for:3091 */
/*<    70  >*/
/* SOURCE culverta.for:3093 */
/*<    71 format(/,'  Table type 5 replaced by type 13.') >*/
/* SOURCE culverta.for:3094 */
/*<    72 format(' *ERR:578* APPROACH REACH LENGTH=',f10.2,' < 0.') >*/
/* SOURCE culverta.for:3095 */
/*<    73 format(' *ERR:579* APPROACH LOSS COEF. < 0 OR > 1.') >*/
/* SOURCE culverta.for:3096 */
/*<    74  >*/
/* SOURCE culverta.for:3098 */
/*<    75 format(' *ERR:581* APPROACH EXPANSION COEF. < 0 OR > 1.') >*/
/* SOURCE culverta.for:3099 */
/*<    76 format(' *ERR:582* ROUNDING/BEVELING FACTOR < 1 OR > 1.5.') >*/
/* SOURCE culverta.for:3100 */
/*<    77 format(' *ERR:583* DEPARTURE CONTRACTION COEF. < 0 OR > 1.') >*/
/* SOURCE culverta.for:3101 */
/*<    78 format(' *ERR:584* WINGWALL FACTOR < 1 OR > 1.25.') >*/
/* SOURCE culverta.for:3102 */
/*<    79 format(' *ERR:604* WIDTH FACTOR FOR DEPARTURE REACH <= 1.0') >*/
/* SOURCE culverta.for:3103 */
/*<    80 format(' *ERR:585* PROJECTION ADJUSTMENT < 0.90 OR > 1.') >*/
/* SOURCE culverta.for:3104 */
/*<    81  >*/
/* SOURCE culverta.for:3106 */
/*<    82 format(' *ERR:586* LOSS OPTION: ',a8,' INVALID.') >*/
/* SOURCE culverta.for:3107 */
/*<    83  >*/
/* SOURCE culverta.for:3109 */
/*<    84 format(' *ERR:587* CULVERT CLASS:',a8,' INVALID.') >*/
/* SOURCE culverta.for:3110 */
/*<    85 format(' ROADWAY MOMENTUM FLUX FACTOR=',f6.3) >*/
/* SOURCE culverta.for:3111 */
/*<    86 format(' *ERR:588* TYPE 4-6 COEF.:',f5.2,'  < 0.60 OR > 1.') >*/
/* SOURCE culverta.for:3112 */
/*<    87 format(' *ERR:607* TABLE# <= 0') >*/
/* SOURCE culverta.for:3113 */
/*<    88 format(' ',a6,'=',a4) >*/
/* SOURCE culverta.for:3114 */
/*<    89  >*/
/* SOURCE culverta.for:3116 */
/*<    90 format(' ',a4,'=',f10.2) >*/
/* SOURCE culverta.for:3117 */
/*<    91  >*/
/* SOURCE culverta.for:3119 */
/*<    92 format(/,' ',a80) >*/
/* SOURCE culverta.for:3120 */
/*<    93 format(' *ERR:609* Road crest elev. < head datum invalid.') >*/
/* SOURCE culverta.for:3121 */
/*<    94 format(/,' Number of partial free drops=',i5) >*/
/* SOURCE culverta.for:3122 */
/*<    95  >*/
/* SOURCE culverta.for:3125 */
/*<    96 format(/,' ','Datum for heads is:',f10.4) >*/
/* SOURCE culverta.for:3126 */
/*<    97 format(2x,a4,'=',i5,' Flap gate factor=',f5.2) >*/
/* SOURCE culverta.for:3127 */
/*<    98 format(' *ERR:589* TABLE TYPE NOT 6 or 13.') >*/
/* SOURCE culverta.for:3128 */
/*<    99 format(/,' *ERR:630* Upstream heads non-increasing at:',f10.4) >*/
/* SOURCE culverta.for:3129 */
/*<   101  >*/
/* SOURCE culverta.for:3131 */
/*<   102 format(' ','DEPTAB= ',a,'  BEGTAB= ',a,'  RMFFAC=',f5.0) >*/
/* SOURCE culverta.for:3132 */
/*<  1050 format(/,' FHWA a coefficient=',f5.2) >*/
/* SOURCE culverta.for:3133 */
/*<  1051 format(/,' FHWA c coefficient=',f8.4) >*/
/* SOURCE culverta.for:3134 */
/*<  1052 format(/,' FHWA Y coefficient=',f8.4) >*/
/* SOURCE culverta.for:3135 */
/*<  1053 format(/,' FHWA barrel slope=',f10.4) >*/
/* *********************************************************************** */
/* SOURCE culverta.for:3137 */
/*<       hlcrit=0.15 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> tabdir(feq_storage_tabdir, 1);

    /* Function Body */
/* L1: */
/* L2: */
/* L4: */
/* L6: */
/* L7: */
/* L10: */
/* L12: */
/* L14: */
/* L15: */
/* L16: */
/* L17: */
/* L18: */
/* L19: */
/* L20: */
/* L21: */
/* L22: */
/* L23: */
/* L24: */
/* L26: */
/* L27: */
/* L1000: */
/* L3: */
/* L5: */
/* L8: */
/* L9: */
/* L11: */
/* L13: */
/* L25: */
/* L28: */
/* L29: */
/* L30: */
/* L31: */
/* L32: */
/* L33: */
/* L34: */
/* L35: */
/* L36: */
/* L37: */
/* L38: */
/* L39: */
/* L40: */
/* L41: */
/* L42: */
/* L43: */
/* L44: */
/* L45: */
/* L46: */
/* L47: */
/* L48: */
/* L49: */
/* L50: */
/* L51: */
/* L52: */
/* L53: */
/* L54: */
/* L55: */
/* L56: */
/* L57: */
/* L58: */
/* L59: */
/* L60: */
/* L61: */
/* L62: */
/* L63: */
/* L64: */
/* L65: */
/* L66: */
/* L67: */
/* L68: */
/* L69: */
/* L70: */
/* L71: */
/* L72: */
/* L73: */
/* L74: */
/* L75: */
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
/* L98: */
/* L99: */
/* L101: */
/* L102: */
/* L1050: */
/* L1051: */
/* L1052: */
/* L1053: */
    embq_1.hlcrit = (float).15;
/* SOURCE culverta.for:3138 */
/*<       hlmax=0.32 >*/
    embq_1.hlmax = (float).32;
/* SOURCE culverta.for:3139 */
/*<       hlflag=0 >*/
    embq_1.hlflag = 0;
/* SOURCE culverta.for:3143 */
/*<       callinline(stdin,stdout,line120) >*/
    inline_(stdin, stdout, line120, (ftnlen)120);
/* SOURCE culverta.for:3146 */
/*<       callread_tabid_plus(stdout,line120,eflag,tabid,tab,line) >*/
    feq_gen_read_tabid_plus_d_(stdout, line120, eflag, tabid, &tab, line, (ftnlen)120, 
	    (ftnlen)16, (ftnlen)80);
/* SOURCE culverta.for:3150 */
/*<       it=lenstr(line) >*/
    it = lenstr_(line, (ftnlen)80);
/* SOURCE culverta.for:3151 */
/*<       if(it.eq.0)then >*/
    if (it == 0) {
/* SOURCE culverta.for:3152 */
/*<       it=1 >*/
	it = 1;
/* SOURCE culverta.for:3153 */
/*<       line=' ' >*/
	s_copy(line, const_cast<char*>(" "), (ftnlen)80, (ftnlen)1);
/* SOURCE culverta.for:3154 */
/*<       endif >*/
    }
/* SOURCE culverta.for:3155 */
/*<       write(stdout,50)tabid(1:lenstr(tabid)),line(1:it) >*/
    feq_gen_io_d__278.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__278);
    do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
    do_fio(&feq_gen_c_d_1, line, it);
    e_wsfe();
/* SOURCE culverta.for:3156 */
/*<       write(*,42)tabid >*/
    s_wsfe(&feq_gen_io_d__279);
    do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
    e_wsfe();
/* SOURCE culverta.for:3158 */
/*<       calltabchk(stdout,pmxtab,tab,tabdir,eflag) >*/
    tabchk_(stdout, &feq_gen_c_d_10002, &tab, &tabdir[1], eflag);
/* SOURCE culverta.for:3161 */
/*<       tabu=tab >*/
    xscomu_1.tabu = tab;
/*     Process get/put actions. */
/* SOURCE culverta.for:3165 */
/*<       callget_putget_options(stdin,stdout,line,culvert,eflag) >*/
    feq_gen_get_putget_options_d_(stdin, stdout, line, &feq_gen_c_d_1, eflag, (ftnlen)80);
/* SOURCE culverta.for:3169 */
/*<       if(putq.gt.0)then >*/
    if (putget_1.putq > 0) {
/* SOURCE culverta.for:3170 */
/*<       calltabchk(stdout,pmxtab,putq,tabdir,eflag) >*/
	tabchk_(stdout, &feq_gen_c_d_10002, &putget_1.putq, &tabdir[1], eflag);
/* SOURCE culverta.for:3173 */
/*<       endif >*/
    }
/* SOURCE culverta.for:3174 */
/*<       if(puty2.gt.0)then >*/
    if (putget_1.puty2 > 0) {
/* SOURCE culverta.for:3175 */
/*<       calltabchk(stdout,pmxtab,puty2,tabdir,eflag) >*/
	tabchk_(stdout, &feq_gen_c_d_10002, &putget_1.puty2, &tabdir[1], eflag);
/* SOURCE culverta.for:3178 */
/*<       endif >*/
    }
/* SOURCE culverta.for:3180 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3183 */
/*<       read(line,27,err=991)char4,tabtyp,flap >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_27;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char4, (ftnlen)4);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&tabtyp, (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&flapgate_1.flap, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE culverta.for:3184 */
/*<       write(stdout,97)char4,tabtyp,flap >*/
    feq_gen_io_d__282.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__282);
    do_fio(&feq_gen_c_d_1, char4, (ftnlen)4);
    do_fio(&feq_gen_c_d_1, (char *)&tabtyp, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&flapgate_1.flap, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE culverta.for:3185 */
/*<       if(tabtyp.eq.5)then >*/
    if (tabtyp == 5) {
/* SOURCE culverta.for:3186 */
/*<       write(stdout,71) >*/
	feq_gen_io_d__283.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__283);
	e_wsfe();
/* SOURCE culverta.for:3187 */
/*<       tabtyp=13 >*/
	tabtyp = 13;
/* SOURCE culverta.for:3188 */
/*<       endif >*/
    }
/* SOURCE culverta.for:3189 */
/*<       if(tabtyp.ne.13.and.tabtyp.ne.6)then >*/
    if (tabtyp != 13 && tabtyp != 6) {
/* SOURCE culverta.for:3190 */
/*<       write(stdout,98) >*/
	feq_gen_io_d__284.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__284);
	e_wsfe();
/* SOURCE culverta.for:3191 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE culverta.for:3192 */
/*<       endif >*/
    }
/*     Get location items that may be present. If they are not present */
/*     they will be set to default values.  The default requests FEQUTL */
/*     to omit the items. */
/* SOURCE culverta.for:3197 */
/*<       callget_lctn_items(stdin,stdout,eflag) >*/
    feq_gen_get_lctn_items_d_(stdin, stdout, eflag);
/* SOURCE culverta.for:3199 */
/*<        >*/
    feq_gen_set_lctn_items_d_(zone, hgrid, vdatum, unitsys, basis, &easting, &northing,
	     (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE culverta.for:3204 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3207 */
/*<       read(line,2,err=991)char5,label >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
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
/* SOURCE culverta.for:3208 */
/*<       write(stdout,52)char5,label >*/
    feq_gen_io_d__294.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__294);
    do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, label, (ftnlen)50);
    e_wsfe();
/*     INPUT THE APPROACH SECTION DESCRIPTION */
/* SOURCE culverta.for:3212 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3215 */
/*<       read(line,24,err=991)head >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_24;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE culverta.for:3216 */
/*<       write(stdout,92)head >*/
    feq_gen_io_d__296.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__296);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_wsfe();
/* SOURCE culverta.for:3218 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3221 */
/*<       callread_tabid(stdout,line,'APPTAB',eflag,apptabid,apptab) >*/
    feq_gen_read_tabid_d_(stdout, line, const_cast<char*>("APPTAB"), eflag, apptabid, &appcom_1.apptab, (
	    ftnlen)80, (ftnlen)6, (ftnlen)16);
/* SOURCE culverta.for:3224 */
/*<       write(stdout,54)apptabid(1:lenstr(apptabid)) >*/
    feq_gen_io_d__298.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__298);
    do_fio(&feq_gen_c_d_1, apptabid, lenstr_(apptabid, (ftnlen)16));
    e_wsfe();
/* SOURCE culverta.for:3226 */
/*<       if(apptab.le.0)then >*/
    if (appcom_1.apptab <= 0) {
/* SOURCE culverta.for:3227 */
/*<       write(stdout,87) >*/
	feq_gen_io_d__299.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__299);
	e_wsfe();
/* SOURCE culverta.for:3228 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE culverta.for:3229 */
/*<       else >*/
    } else {
/* SOURCE culverta.for:3230 */
/*<       callchktab(12,stdout,ftpnt,mftnum,apptab,eflag) >*/
	chktab_(&feq_gen_c_d_12, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &appcom_1.apptab, 
		eflag);
/* SOURCE culverta.for:3234 */
/*<       endif >*/
    }
/* SOURCE culverta.for:3235 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3238 */
/*<       read(line,6,err=991)char6,appelv >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&appcom_1.appelv, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE culverta.for:3240 */
/*<       write(stdout,56)char6,appelv >*/
    feq_gen_io_d__301.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__301);
    do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
    do_fio(&feq_gen_c_d_1, (char *)&appcom_1.appelv, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE culverta.for:3242 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3245 */
/*<       read(line,6,err=991)char6,applen >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&appcom_1.applen, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE culverta.for:3246 */
/*<       write(stdout,58)char6,applen >*/
    feq_gen_io_d__302.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__302);
    do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
    do_fio(&feq_gen_c_d_1, (char *)&appcom_1.applen, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE culverta.for:3248 */
/*<       if(applen.lt.0.0)then >*/
    if (appcom_1.applen < (float)0.) {
/* SOURCE culverta.for:3249 */
/*<       write(stdout,72)applen >*/
	feq_gen_io_d__303.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__303);
	do_fio(&feq_gen_c_d_1, (char *)&appcom_1.applen, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culverta.for:3250 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE culverta.for:3251 */
/*<       endif >*/
    }
/* SOURCE culverta.for:3253 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3256 */
/*<       read(line,6,err=991)char6,applos >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&appcom_1.applos, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE culverta.for:3257 */
/*<       write(stdout,56)char6,applos >*/
    feq_gen_io_d__304.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__304);
    do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
    do_fio(&feq_gen_c_d_1, (char *)&appcom_1.applos, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE culverta.for:3258 */
/*<       if(applos.lt.0.0.or.applos.gt.1.0)then >*/
    if (appcom_1.applos < (float)0. || appcom_1.applos > (float)1.) {
/* SOURCE culverta.for:3259 */
/*<       write(stdout,73) >*/
	feq_gen_io_d__305.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__305);
	e_wsfe();
/* SOURCE culverta.for:3260 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE culverta.for:3261 */
/*<       endif >*/
    }
/* SOURCE culverta.for:3263 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3266 */
/*<       read(line,6,err=991)char6,appexp >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&appcom_1.appexp, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE culverta.for:3267 */
/*<       write(stdout,56)char6,appexp >*/
    feq_gen_io_d__306.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__306);
    do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
    do_fio(&feq_gen_c_d_1, (char *)&appcom_1.appexp, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE culverta.for:3268 */
/*<       if(appexp.lt.0.0.or.appexp.gt.1.0)then >*/
    if (appcom_1.appexp < (float)0. || appcom_1.appexp > (float)1.) {
/* SOURCE culverta.for:3269 */
/*<       write(stdout,75) >*/
	feq_gen_io_d__307.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__307);
	e_wsfe();
/* SOURCE culverta.for:3270 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE culverta.for:3271 */
/*<       endif >*/
    }
/*     INPUT THE CULVERT DESCRIPTION.  TREAT LIKE A BRANCH IN FEQ AND */
/*     MAKE AS CLOSE TO A BRANCH AS POSSIBLE. */
/* SOURCE culverta.for:3277 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3280 */
/*<       read(line,24,err=991)head >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_24;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE culverta.for:3281 */
/*<       write(stdout,92)head >*/
    feq_gen_io_d__308.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__308);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_wsfe();
/* SOURCE culverta.for:3283 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3286 */
/*<       read(line,20,err=991)char6,nodeid >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_20;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, nodeid, (ftnlen)4);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE culverta.for:3287 */
/*<       nodeid=gettok(nodeid) >*/
    gettok_(feq_gen_ch_d_1, (ftnlen)8, nodeid, (ftnlen)4);
    s_copy(nodeid, feq_gen_ch_d_1, (ftnlen)4, (ftnlen)8);
/* SOURCE culverta.for:3288 */
/*<       write(stdout,88)char6,nodeid >*/
    feq_gen_io_d__310.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__310);
    do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
    do_fio(&feq_gen_c_d_1, nodeid, (ftnlen)4);
    e_wsfe();
/* SOURCE culverta.for:3290 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3293 */
/*<       read(line,22,err=991)char4,sfac >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_22;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char4, (ftnlen)4);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&sfac, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE culverta.for:3294 */
/*<       write(stdout,90)char4,sfac >*/
    feq_gen_io_d__312.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__312);
    do_fio(&feq_gen_c_d_1, char4, (ftnlen)4);
    do_fio(&feq_gen_c_d_1, (char *)&sfac, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE culverta.for:3296 */
/*<       nbra=1 >*/
    nbra = 1;
/*     TYPFLG at 1 requests automatic interpolation for cross sections */
/*     along the barrel if the user only gives 2 crossections: one at the */
/*     barrel entrance and one at the barrel exit.  NEGTAB is not used */
/*     in culvert but it is used in XSINTERP where CLVIN is called as */
/*     well. */
/* SOURCE culverta.for:3302 */
/*<       typflg=1 >*/
    typflg = 1;
/* SOURCE culverta.for:3303 */
/*<        >*/
    clvin_(&sfac, stdin, stdout, &feq_gen_c_d_8400, &nbra, nodeid, &feq_gen_c_d_10002, &c_b750, 
	    ftablea_1.ftpnt, &typflg, eflag, ftknt, ftp, &nbn, brpt, 
	    culcom_1.nsec, culcom_1.xvec, culcom_1.zbvec, culcom_1.ka, 
	    culcom_1.kd, culcom_1.hltab, bnodid, negtab, &chkbar, &
	    culcom_1.iat3d, &culcom_1.iat6d, &bshape, &culcom_1.sbkind, (
	    ftnlen)4, (ftnlen)8);
/*     INPUT THE CULVERT CLASS.  USED TO DECIDE WHAT RELATIONSHIPS TO USE. */
/*     CLASS IS ASSIGNED BY THE USER AND IS INDEPENDENT OF THE ACTUAL SHAPE */
/*     OF THE CULVERT OPENING.  NORMALLY HOWEVER, THE USER SHOULD SELECT */
/*     A CLASS WHICH IS DESCRIPTIVE OF THE SHAPE. */
/* SOURCE culverta.for:3317 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3320 */
/*<       read(line,10,err=991)char6,culcls >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, culcls, (ftnlen)8);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE culverta.for:3321 */
/*<       write(stdout,61)char6,culcls >*/
    feq_gen_io_d__322.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__322);
    do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
    do_fio(&feq_gen_c_d_1, culcls, (ftnlen)8);
    e_wsfe();
/*     SKIP LEADING BLANKS */
/* SOURCE culverta.for:3324 */
/*<       culcls=gettok(culcls) >*/
    gettok_(feq_gen_ch_d_1, (ftnlen)8, culcls, (ftnlen)8);
    s_copy(culcls, feq_gen_ch_d_1, (ftnlen)8, (ftnlen)8);
/* SOURCE culverta.for:3325 */
/*<        >*/
    if (s_cmp(culcls, const_cast<char*>("BOX"), (ftnlen)8, (ftnlen)3) != 0 && s_cmp(culcls, 
	    const_cast<char*>("PIPE"), (ftnlen)8, (ftnlen)4) != 0 && s_cmp(culcls, const_cast<char*>("MITER"), (
	    ftnlen)8, (ftnlen)5) != 0 && s_cmp(culcls, const_cast<char*>("RCPTG"), (ftnlen)8, (
	    ftnlen)5) != 0 && s_cmp(culcls, const_cast<char*>("FLARED"), (ftnlen)8, (ftnlen)6) !=
	     0) {
/* SOURCE culverta.for:3327 */
/*<       write(stdout,84)culcls >*/
	feq_gen_io_d__323.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__323);
	do_fio(&feq_gen_c_d_1, culcls, (ftnlen)8);
	e_wsfe();
/* SOURCE culverta.for:3328 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE culverta.for:3329 */
/*<       endif >*/
    }
/*     INPUT THE DEPARTURE SECTION DATA */
/* SOURCE culverta.for:3333 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3336 */
/*<       read(line,24,err=991)head >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_24;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE culverta.for:3337 */
/*<       write(stdout,92)head >*/
    feq_gen_io_d__324.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__324);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_wsfe();
/* SOURCE culverta.for:3339 */
/*<       callget_departure_items(stdin,stdout,eflag) >*/
    feq_gen_get_departure_items_d_(stdin, stdout, eflag);
/*      CALL inline */
/*     I          (STDIN, STDOUT, */
/*     O           LINE) */
/*      READ(LINE,4,ERR=991)  CHAR6, DEPTAB, CHAR5, C5VEC(1) */
/* SOURCE culverta.for:3346 */
/*<       callset_depitm(deptab,begtab,rmffac,eflag) >*/
    feq_gen_set_depitm_d_(&depcom_1.deptab, &depcom_1.begtab, &embcom_1.rmffac, eflag);
/* SOURCE culverta.for:3350 */
/*<       if(deptab.gt.0)then >*/
    if (depcom_1.deptab > 0) {
/* SOURCE culverta.for:3351 */
/*<       deptabid=get_tabid(deptab) >*/
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &depcom_1.deptab);
	s_copy(deptabid, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
/* SOURCE culverta.for:3352 */
/*<       else >*/
    } else {
/* SOURCE culverta.for:3353 */
/*<       deptabid='   ' >*/
	s_copy(deptabid, const_cast<char*>("   "), (ftnlen)16, (ftnlen)3);
/* SOURCE culverta.for:3354 */
/*<       endif >*/
    }
/* SOURCE culverta.for:3355 */
/*<       if(begtab.gt.0)then >*/
    if (depcom_1.begtab > 0) {
/* SOURCE culverta.for:3356 */
/*<       begtabid=get_tabid(begtab) >*/
	feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &depcom_1.begtab);
	s_copy(begtabid, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
/* SOURCE culverta.for:3357 */
/*<       else >*/
    } else {
/* SOURCE culverta.for:3358 */
/*<       begtabid='   ' >*/
	s_copy(begtabid, const_cast<char*>("   "), (ftnlen)16, (ftnlen)3);
/* SOURCE culverta.for:3359 */
/*<       endif >*/
    }
/* SOURCE culverta.for:3361 */
/*<        >*/
    feq_gen_io_d__327.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__327);
    do_fio(&feq_gen_c_d_1, deptabid, lenstr_(deptabid, (ftnlen)16));
    do_fio(&feq_gen_c_d_1, begtabid, lenstr_(begtabid, (ftnlen)16));
    do_fio(&feq_gen_c_d_1, (char *)&embcom_1.rmffac, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE culverta.for:3363 */
/*<       if(deptab.le.0)then >*/
    if (depcom_1.deptab <= 0) {
/* SOURCE culverta.for:3364 */
/*<       write(stdout,87) >*/
	feq_gen_io_d__328.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__328);
	e_wsfe();
/* SOURCE culverta.for:3365 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE culverta.for:3366 */
/*<       else >*/
    } else {
/* SOURCE culverta.for:3367 */
/*<       callchktab(12,stdout,ftpnt,mftnum,deptab,eflag) >*/
	chktab_(&feq_gen_c_d_12, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &depcom_1.deptab, 
		eflag);
/* SOURCE culverta.for:3371 */
/*<       endif >*/
    }
/* SOURCE culverta.for:3372 */
/*<       if(begtab.gt.0)then >*/
    if (depcom_1.begtab > 0) {
/* SOURCE culverta.for:3373 */
/*<       callchktab(12,stdout,ftpnt,mftnum,begtab,eflag) >*/
	chktab_(&feq_gen_c_d_12, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &depcom_1.begtab, 
		eflag);
/* SOURCE culverta.for:3377 */
/*<       else >*/
    } else {
/*       MAKE TABLES THE SAME */
/* SOURCE culverta.for:3379 */
/*<       begtab=deptab >*/
	depcom_1.begtab = depcom_1.deptab;
/* SOURCE culverta.for:3380 */
/*<       endif >*/
    }
/*     CHECK USER SUPPLIED ROADWAY MOMENTUM FLUX FACTOR */
/* SOURCE culverta.for:3383 */
/*<       if(rmffac.lt.0.0.or.rmffac.gt.1.0)then >*/
    if (embcom_1.rmffac < (float)0. || embcom_1.rmffac > (float)1.) {
/* SOURCE culverta.for:3384 */
/*<       write(stdout,63)rmffac >*/
	feq_gen_io_d__329.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__329);
	do_fio(&feq_gen_c_d_1, (char *)&embcom_1.rmffac, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culverta.for:3385 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE culverta.for:3386 */
/*<       endif >*/
    }
/* SOURCE culverta.for:3387 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3390 */
/*<       read(line,7,err=991)char6,depelv,char10,c5vec(1),c5vec(2) >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&depcom_1.depelv, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char10, (ftnlen)10);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, c5vec, (ftnlen)5);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, c5vec + 5, (ftnlen)5);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE culverta.for:3391 */
/*<       write(stdout,57)char6,depelv,char10,c5vec(1),c5vec(2) >*/
    feq_gen_io_d__332.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__332);
    do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
    do_fio(&feq_gen_c_d_1, (char *)&depcom_1.depelv, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, char10, (ftnlen)10);
    do_fio(&feq_gen_c_d_1, c5vec, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, c5vec + 5, (ftnlen)5);
    e_wsfe();
/* SOURCE culverta.for:3393 */
/*<       if(char10.ne.'          ')then >*/
    if (s_cmp(char10, const_cast<char*>("          "), (ftnlen)10, (ftnlen)10) != 0) {
/*       INPUT THE USER SPECIFIED BEGINNING ELEVATION FOR THE */
/*       DEPARTURE REACH. */
/* SOURCE culverta.for:3396 */
/*<       read(char10,'(F10.0)')begelv >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 10;
	feq_gen_ici_d_1.iciunit = char10;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.0)");
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&depcom_1.begelv, (ftnlen)sizeof(real));
	e_rsfi();
/* SOURCE culverta.for:3397 */
/*<       if(begelv.gt.zbvec(nbn))then >*/
	if (depcom_1.begelv > culcom_1.zbvec[nbn - 1]) {
/* SOURCE culverta.for:3398 */
/*<       write(stdout,81)begelv,zbvec(nbn) >*/
	    feq_gen_io_d__333.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__333);
	    do_fio(&feq_gen_c_d_1, (char *)&depcom_1.begelv, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&culcom_1.zbvec[nbn - 1], (ftnlen)sizeof(
		    real));
	    e_wsfe();
/* SOURCE culverta.for:3399 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE culverta.for:3400 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3401 */
/*<       else >*/
    } else {
/*       IF THE DEPELV > CULVERT EXIT ELEVATION THEN MAKE BEGELV */
/*       SAME AS CULVERT ELEVATION. OTHERWISE MAKE IT THE SAME AS */
/*       DEPELV */
/* SOURCE culverta.for:3405 */
/*<       if(depelv.gt.zbvec(nbn))then >*/
	if (depcom_1.depelv > culcom_1.zbvec[nbn - 1]) {
/* SOURCE culverta.for:3406 */
/*<       begelv=zbvec(nbn) >*/
	    depcom_1.begelv = culcom_1.zbvec[nbn - 1];
/* SOURCE culverta.for:3407 */
/*<       else >*/
	} else {
/* SOURCE culverta.for:3408 */
/*<       begelv=depelv >*/
	    depcom_1.begelv = depcom_1.depelv;
/* SOURCE culverta.for:3409 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3410 */
/*<       endif >*/
    }
/* SOURCE culverta.for:3412 */
/*<       if(c5vec(2).ne.'     ')then >*/
    if (s_cmp(c5vec + 5, const_cast<char*>("     "), (ftnlen)5, (ftnlen)5) != 0) {
/*       INPUT USER SPECIFIED CULVERT WIDTH FACTOR */
/* SOURCE culverta.for:3414 */
/*<       read(c5vec(2),'(F5.0)')widfac >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 5;
	feq_gen_ici_d_1.iciunit = c5vec + 5;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F5.0)");
	s_rsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&depcom_1.widfac, (ftnlen)sizeof(real));
	e_rsfi();
/* SOURCE culverta.for:3415 */
/*<       if(widfac.lt.1.0)then >*/
	if (depcom_1.widfac < (float)1.) {
/* SOURCE culverta.for:3416 */
/*<       write(stdout,79) >*/
	    feq_gen_io_d__334.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__334);
	    e_wsfe();
/* SOURCE culverta.for:3417 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE culverta.for:3418 */
/*<       widfac=1.02 >*/
	    depcom_1.widfac = (float)1.02;
/* SOURCE culverta.for:3419 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3420 */
/*<       else >*/
    } else {
/* SOURCE culverta.for:3421 */
/*<       widfac=1.02 >*/
	depcom_1.widfac = (float)1.02;
/* SOURCE culverta.for:3422 */
/*<       endif >*/
    }
/* SOURCE culverta.for:3424 */
/*<       write(stdout,65)begelv,depelv >*/
    feq_gen_io_d__335.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__335);
    do_fio(&feq_gen_c_d_1, (char *)&depcom_1.begelv, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&depcom_1.depelv, (ftnlen)sizeof(real));
    e_wsfe();
/*     Find the elevation datum to use to improve the precision */
/*     of residual computation. */
/* SOURCE culverta.for:3429 */
/*<       zdatum=min(appelv,zbvec(1),zbvec(nbn),depelv) >*/
/* Computing MIN */
    feq_gen_r_d_1 = min(appcom_1.appelv,culcom_1.zbvec[0]), feq_gen_r_d_2 = culcom_1.zbvec[nbn 
	    - 1], feq_gen_r_d_1 = min(feq_gen_r_d_1,feq_gen_r_d_2);
    zdatum = dmin(feq_gen_r_d_1,depcom_1.depelv);
/* SOURCE culverta.for:3430 */
/*<       appelv=dble(appelv)-dble(zdatum) >*/
    appcom_1.appelv = (doublereal) appcom_1.appelv - (doublereal) zdatum;
/* SOURCE culverta.for:3431 */
/*<       depelv=dble(depelv)-dble(zdatum) >*/
    depcom_1.depelv = (doublereal) depcom_1.depelv - (doublereal) zdatum;
/* SOURCE culverta.for:3432 */
/*<       begelv=dble(begelv)-dble(zdatum) >*/
    depcom_1.begelv = (doublereal) depcom_1.begelv - (doublereal) zdatum;
/* SOURCE culverta.for:3433 */
/*<       do100i=1,nbn >*/
    feq_gen_i_d_1 = nbn;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culverta.for:3434 */
/*<       zbvec(i)=dble(zbvec(i))-dble(zdatum) >*/
	culcom_1.zbvec[feq_gen_i_d_ - 1] = (doublereal) culcom_1.zbvec[feq_gen_i_d_ - 1] - (
		doublereal) zdatum;
/* SOURCE culverta.for:3435 */
/*<   100 continue >*/
/* L100: */
    }
/*     INPUT THE EXIT LOSS OPTIONS */
/* SOURCE culverta.for:3439 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3442 */
/*<       read(line,12,err=991)char6,losopt >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, losopt, (ftnlen)8);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE culverta.for:3443 */
/*<       if(losopt.ne.'MOMENTUM')then >*/
    if (s_cmp(losopt, const_cast<char*>("MOMENTUM"), (ftnlen)8, (ftnlen)8) != 0) {
/* SOURCE culverta.for:3444 */
/*<       write(stdout,82)losopt >*/
	feq_gen_io_d__339.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__339);
	do_fio(&feq_gen_c_d_1, losopt, (ftnlen)8);
	e_wsfe();
/* SOURCE culverta.for:3445 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE culverta.for:3446 */
/*<       endif >*/
    }
/* SOURCE culverta.for:3447 */
/*<       write(stdout,60)char6,losopt >*/
    feq_gen_io_d__340.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__340);
    do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
    do_fio(&feq_gen_c_d_1, losopt, (ftnlen)8);
    e_wsfe();
/* SOURCE culverta.for:3449 */
/*<       if(losopt.eq.'ENERGY')then >*/
    if (s_cmp(losopt, const_cast<char*>("ENERGY"), (ftnlen)8, (ftnlen)6) == 0) {
/* SOURCE culverta.for:3451 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3454 */
/*<       read(line,6,err=991)char6,depcon >*/
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
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&depcon, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE culverta.for:3455 */
/*<       write(stdout,56)char6,depcon >*/
	feq_gen_io_d__342.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__342);
	do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
	do_fio(&feq_gen_c_d_1, (char *)&depcon, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culverta.for:3457 */
/*<       if(depcon.lt.0.0.or.depcon.gt.1.0)then >*/
	if (depcon < (float)0. || depcon > (float)1.) {
/* SOURCE culverta.for:3458 */
/*<       write(stdout,77) >*/
	    feq_gen_io_d__343.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__343);
	    e_wsfe();
/* SOURCE culverta.for:3459 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE culverta.for:3460 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3461 */
/*<       endif >*/
    }
/*     INPUT THE DISCHARGE COEFFICIENT RELATED FACTORS WHICH ARE */
/*     FUNCTIONS OF GEOMETRY ONLY. */
/* SOURCE culverta.for:3465 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3468 */
/*<       read(line,24,err=991)head >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_24;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE culverta.for:3469 */
/*<       write(stdout,92)head >*/
    feq_gen_io_d__344.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__344);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_wsfe();
/* SOURCE culverta.for:3471 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3474 */
/*<       read(line,14,err=991)krb >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_14;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.krb, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE culverta.for:3476 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3479 */
/*<       read(line,16,err=991)char5,kwing >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_16;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.kwing, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE culverta.for:3481 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3484 */
/*<       read(line,18,err=991)char5,kproj >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_18;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.kproj, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE culverta.for:3486 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3489 */
/*<       read(line,14,err=991)c46,char4 >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_14;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.c46, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char4, (ftnlen)4);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE culverta.for:3490 */
/*<       if(char4.eq.'    ')then >*/
    if (s_cmp(char4, const_cast<char*>("    "), (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE culverta.for:3491 */
/*<       ty6sup=1 >*/
	cdcom_1.ty6sup = 1;
/* SOURCE culverta.for:3492 */
/*<       elseif(char4.eq.'SJET')then >*/
    } else if (s_cmp(char4, const_cast<char*>("SJET"), (ftnlen)4, (ftnlen)4) == 0) {
/* SOURCE culverta.for:3493 */
/*<       ty6sup=1 >*/
	cdcom_1.ty6sup = 1;
/* SOURCE culverta.for:3494 */
/*<       else >*/
    } else {
/* SOURCE culverta.for:3495 */
/*<       ty6sup=0 >*/
	cdcom_1.ty6sup = 0;
/* SOURCE culverta.for:3496 */
/*<       endif >*/
    }
/*     Set the default values for type 5 stuff and the */
/*     internal lookup stuff. */
/* SOURCE culverta.for:3500 */
/*<       hhtype=0 >*/
    typlim_1.hhtype = 0;
/* SOURCE culverta.for:3501 */
/*<       rbval=0.0 >*/
    cdcom_1.rbval = (float)0.;
/* SOURCE culverta.for:3502 */
/*<       ty5sbf=0.75 >*/
    culcom_1.ty5sbf = (float).75;
/* SOURCE culverta.for:3503 */
/*<       wwangl=0.0 >*/
    cdcom_1.wwangl = (float)0.;
/* SOURCE culverta.for:3504 */
/*<       it=9979 >*/
    it = 9979;
/* SOURCE culverta.for:3505 */
/*<       char16=' ' >*/
    s_copy(char16, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/*     Clear all the FHWA values. */
/* SOURCE culverta.for:3507 */
/*<       afhwa=0.0 >*/
    cdcom_1.afhwa = (float)0.;
/* SOURCE culverta.for:3508 */
/*<       cfhwa=0.0 >*/
    cdcom_1.cfhwa = (float)0.;
/* SOURCE culverta.for:3509 */
/*<       yfhwa=0.0 >*/
    cdcom_1.yfhwa = (float)0.;
/* SOURCE culverta.for:3510 */
/*<       sfhwa=0.0 >*/
    cdcom_1.sfhwa = (float)0.;
/* SOURCE culverta.for:3511 */
/*<       do250j=1,13 >*/
    for (j = 1; j <= 13; ++j) {
/* SOURCE culverta.for:3512 */
/*<       it=it+1 >*/
	++it;
/* SOURCE culverta.for:3513 */
/*<       write(char16(1:5),'(I5)')it >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 5;
	feq_gen_ici_d_1.iciunit = char16;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(I5)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&it, (ftnlen)sizeof(integer));
	e_wsfi();
/* SOURCE culverta.for:3514 */
/*<       callstrip_l_blanks(char16) >*/
	feq_gen_strip_l_blanks_d_(char16, (ftnlen)16);
/* SOURCE culverta.for:3516 */
/*<       callget_internal_tab_number(stdout,char16,eflag,default_tabvec(j)) >*/
	feq_gen_get_internal_tab_number_d_(stdout, char16, eflag, &feq_gen_default_tabvec_d_[j 
		- 1], (ftnlen)16);
/* SOURCE culverta.for:3520 */
/*<   250 continue >*/
/* L250: */
    }
/* SOURCE culverta.for:3522 */
/*<       tb6adr=default_tabvec(01) >*/
    cdcom_1.tb6adr = feq_gen_default_tabvec_d_[0];
/* SOURCE culverta.for:3523 */
/*<       tb7adr=default_tabvec(02) >*/
    cdcom_1.tb7adr = feq_gen_default_tabvec_d_[1];
/* SOURCE culverta.for:3524 */
/*<       tb8adr=default_tabvec(03) >*/
    cdcom_1.tb8adr = feq_gen_default_tabvec_d_[2];
/* SOURCE culverta.for:3525 */
/*<       tb15ad=default_tabvec(04) >*/
    cdcom_1.tb15ad = feq_gen_default_tabvec_d_[3];
/* SOURCE culverta.for:3526 */
/*<       tb16ad(1)=default_tabvec(05) >*/
    cdcom_1.tb16ad[0] = feq_gen_default_tabvec_d_[4];
/* SOURCE culverta.for:3527 */
/*<       tb16ad(2)=default_tabvec(06) >*/
    cdcom_1.tb16ad[1] = feq_gen_default_tabvec_d_[5];
/* SOURCE culverta.for:3528 */
/*<       tb16ad(3)=default_tabvec(07) >*/
    cdcom_1.tb16ad[2] = feq_gen_default_tabvec_d_[6];
/* SOURCE culverta.for:3529 */
/*<       tb16ad(4)=default_tabvec(08) >*/
    cdcom_1.tb16ad[3] = feq_gen_default_tabvec_d_[7];
/* SOURCE culverta.for:3530 */
/*<       tb5adr=default_tabvec(09) >*/
    cdcom_1.tb5adr = feq_gen_default_tabvec_d_[8];
/* SOURCE culverta.for:3531 */
/*<       tb21adr=default_tabvec(10) >*/
    cdcom_1.tb21adr = feq_gen_default_tabvec_d_[9];
/* SOURCE culverta.for:3532 */
/*<       tb22adr=default_tabvec(11) >*/
    cdcom_1.tb22adr = feq_gen_default_tabvec_d_[10];
/* SOURCE culverta.for:3533 */
/*<       tb24adr=default_tabvec(12) >*/
    cdcom_1.tb24adr = feq_gen_default_tabvec_d_[11];
/* SOURCE culverta.for:3534 */
/*<       tblpdadr=default_tabvec(13) >*/
    cdcom_1.tblpdadr = feq_gen_default_tabvec_d_[12];
/* SOURCE culverta.for:3535 */
/*<       bvangl=0.0 >*/
    cdcom_1.bvangl = (float)0.;
/* SOURCE culverta.for:3536 */
/*<       lpovd=0.0 >*/
    cdcom_1.lpovd = (float)0.;
/*     Optional type 5 input may appear here.  If not the */
/*     roadway heading appears. */
/* SOURCE culverta.for:3541 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3544 */
/*<       read(line,24,err=991)head >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_24;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE culverta.for:3546 */
/*<       if(line(1:6).eq.'TYPE 5'.or.line(1:6).eq.'Type 5')then >*/
    if (s_cmp(line, const_cast<char*>("TYPE 5"), (ftnlen)6, (ftnlen)6) == 0 || s_cmp(line, const_cast<char*>("Typ\
e 5"), (ftnlen)6, (ftnlen)6) == 0) {
/*       Type 5 flow parameters appear. */
/* SOURCE culverta.for:3548 */
/*<       write(stdout,92)head >*/
	feq_gen_io_d__348.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__348);
	do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
	e_wsfe();
/* SOURCE culverta.for:3549 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3552 */
/*<       read(line,15,err=991)char7,rbval >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_15;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char7, (ftnlen)7);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.rbval, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE culverta.for:3553 */
/*<       if(rbval.lt.0.0.or.rbval.gt.0.14)then >*/
	if (cdcom_1.rbval < (float)0. || cdcom_1.rbval > (float).14) {
/* SOURCE culverta.for:3554 */
/*<       write(stdout,46) >*/
	    feq_gen_io_d__350.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__350);
	    e_wsfe();
/* SOURCE culverta.for:3555 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE culverta.for:3556 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3557 */
/*<       write(stdout,30)rbval >*/
	feq_gen_io_d__351.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__351);
	do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.rbval, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culverta.for:3559 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3562 */
/*<       read(line,17,err=991)bvangl >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_17;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.bvangl, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE culverta.for:3563 */
/*<       if(bvangl.lt.0.0.or.bvangl.gt.90.0)then >*/
	if (cdcom_1.bvangl < (float)0. || cdcom_1.bvangl > (float)90.) {
/* SOURCE culverta.for:3564 */
/*<       write(stdout,29) >*/
	    feq_gen_io_d__352.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__352);
	    e_wsfe();
/* SOURCE culverta.for:3565 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE culverta.for:3566 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3567 */
/*<       write(stdout,25)bvangl >*/
	feq_gen_io_d__353.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__353);
	do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.bvangl, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culverta.for:3569 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3572 */
/*<       read(line,17,err=991)wwangl >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_17;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.wwangl, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE culverta.for:3573 */
/*<       write(stdout,36)wwangl >*/
	feq_gen_io_d__354.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__354);
	do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.wwangl, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culverta.for:3574 */
/*<       if(wwangl.lt.0.0.or.wwangl.gt.90.0)then >*/
	if (cdcom_1.wwangl < (float)0. || cdcom_1.wwangl > (float)90.) {
/* SOURCE culverta.for:3575 */
/*<       write(stdout,47) >*/
	    feq_gen_io_d__355.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__355);
	    e_wsfe();
/* SOURCE culverta.for:3576 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE culverta.for:3577 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3579 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3582 */
/*<       read(line,17,err=991)lpovd >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_17;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.lpovd, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE culverta.for:3583 */
/*<       write(stdout,28)lpovd >*/
	feq_gen_io_d__356.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__356);
	do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.lpovd, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culverta.for:3584 */
/*<       if(lpovd.lt.0.0)then >*/
	if (cdcom_1.lpovd < (float)0.) {
/* SOURCE culverta.for:3585 */
/*<       write(stdout,13) >*/
	    feq_gen_io_d__357.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__357);
	    e_wsfe();
/* SOURCE culverta.for:3586 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE culverta.for:3587 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3589 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3592 */
/*<       read(line,19,err=991)ty5sbf >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_19;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&culcom_1.ty5sbf, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE culverta.for:3593 */
/*<       write(stdout,37)ty5sbf >*/
	feq_gen_io_d__358.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__358);
	do_fio(&feq_gen_c_d_1, (char *)&culcom_1.ty5sbf, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culverta.for:3594 */
/*<       if(ty5sbf.le.0.0.or.ty5sbf.gt.1.0)then >*/
	if (culcom_1.ty5sbf <= (float)0. || culcom_1.ty5sbf > (float)1.) {
/* SOURCE culverta.for:3595 */
/*<       write(stdout,51) >*/
	    feq_gen_io_d__359.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__359);
	    e_wsfe();
/* SOURCE culverta.for:3596 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE culverta.for:3597 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3599 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3602 */
/*<       endif >*/
    }
/*     Insert input of FHWA information after the Type 5 block */
/* SOURCE culverta.for:3605 */
/*<       if(line(1:4).eq.'FHWA')then >*/
    if (s_cmp(line, const_cast<char*>("FHWA"), (ftnlen)4, (ftnlen)4) == 0) {
/*       Process the FHWA parameters. */
/* SOURCE culverta.for:3607 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3610 */
/*<       read(line,1000,err=991)afhwa >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_1000;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.afhwa, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/*       If AFHWA is zero we will assign a value based on */
/*       culvert class.  Otherwise retain the given value. */
/* SOURCE culverta.for:3613 */
/*<       if(afhwa.eq.0.0)then >*/
	if (cdcom_1.afhwa == (float)0.) {
/* SOURCE culverta.for:3614 */
/*<       if(culcls.eq.'MITER')then >*/
	    if (s_cmp(culcls, const_cast<char*>("MITER"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE culverta.for:3615 */
/*<       afhwa=-0.7 >*/
		cdcom_1.afhwa = (float)-.7;
/* SOURCE culverta.for:3616 */
/*<       else >*/
	    } else {
/* SOURCE culverta.for:3617 */
/*<       afhwa=0.5 >*/
		cdcom_1.afhwa = (float).5;
/* SOURCE culverta.for:3618 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:3619 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3620 */
/*<       write(stdout,1050)afhwa >*/
	feq_gen_io_d__360.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__360);
	do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.afhwa, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culverta.for:3621 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3624 */
/*<       read(line,1000,err=991)cfhwa >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_1000;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.cfhwa, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE culverta.for:3625 */
/*<       write(stdout,1051)cfhwa >*/
	feq_gen_io_d__361.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__361);
	do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.cfhwa, (ftnlen)sizeof(real));
	e_wsfe();
/*       Apply factor of 2g to CFHWA */
/* SOURCE culverta.for:3627 */
/*<       cfhwa=grav2*cfhwa >*/
	cdcom_1.cfhwa = static_cast<double>(grvcom_1.grav2) * cdcom_1.cfhwa;
/* SOURCE culverta.for:3629 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3632 */
/*<       read(line,1000,err=991)yfhwa >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_1000;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.yfhwa, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE culverta.for:3633 */
/*<       write(stdout,1052)yfhwa >*/
	feq_gen_io_d__362.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__362);
	do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.yfhwa, (ftnlen)sizeof(real));
	e_wsfe();
/*       Compute the bottom slope of the culvert near the */
/*       entrance. Slope > 0 for decline. */
/* SOURCE culverta.for:3638 */
/*<       sfhwa=(zbvec(1)-zbvec(2))/(xvec(2)-xvec(1)) >*/
	cdcom_1.sfhwa = static_cast<double>((static_cast<double>(culcom_1.zbvec[0]) - culcom_1.zbvec[1])) / (
		static_cast<double>(culcom_1.xvec[1]) - culcom_1.xvec[0]);
/* SOURCE culverta.for:3639 */
/*<       write(stdout,1053)sfhwa >*/
	feq_gen_io_d__363.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__363);
	do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.sfhwa, (ftnlen)sizeof(real));
	e_wsfe();
/*       Read next line to prepare for what follows */
/* SOURCE culverta.for:3641 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3645 */
/*<       endif >*/
    }
/* SOURCE culverta.for:3646 */
/*<       if(line(1:5).eq.'TABLE'.or.line(1:5).eq.'Table')then >*/
    if (s_cmp(line, const_cast<char*>("TABLE"), (ftnlen)5, (ftnlen)5) == 0 || s_cmp(line, const_cast<char*>("Table")
	    , (ftnlen)5, (ftnlen)5) == 0) {
/*       Get the next line and read user assigned table numbers from it. */
/* SOURCE culverta.for:3648 */
/*<       write(stdout,92)line(1:80) >*/
	feq_gen_io_d__364.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__364);
	do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
	e_wsfe();
/* SOURCE culverta.for:3649 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3652 */
/*<        >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = 0;
	feq_gen_i_d_1 = s_rsli(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&cdcom_1.tb6adr, (ftnlen)sizeof(
		integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&cdcom_1.tb7adr, (ftnlen)sizeof(
		integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&cdcom_1.tb8adr, (ftnlen)sizeof(
		integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&cdcom_1.tb15ad, (ftnlen)sizeof(
		integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&cdcom_1.tb16ad[0], (ftnlen)
		sizeof(integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&cdcom_1.tb16ad[1], (ftnlen)
		sizeof(integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&cdcom_1.tb16ad[2], (ftnlen)
		sizeof(integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&cdcom_1.tb16ad[3], (ftnlen)
		sizeof(integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&cdcom_1.tb5adr, (ftnlen)sizeof(
		integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&cdcom_1.tb21adr, (ftnlen)sizeof(
		integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&cdcom_1.tb22adr, (ftnlen)sizeof(
		integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&cdcom_1.tb24adr, (ftnlen)sizeof(
		integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&cdcom_1.tblpdadr, (ftnlen)sizeof(
		integer));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsli();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/*       Transform to internal table number */
/*       Read the next line.  Should be a heading of */
/*       some sort. */
/* SOURCE culverta.for:3660 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3663 */
/*<       endif >*/
    }
/*     Get the function table addresses. */
/* SOURCE culverta.for:3666 */
/*<       callchktab(10,stdout,ftpnt,mftnum,tb6adr,eflag) >*/
    chktab_(&feq_gen_c_d_10, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &cdcom_1.tb6adr, 
	    eflag);
/* SOURCE culverta.for:3670 */
/*<       callchktab(10,stdout,ftpnt,mftnum,tb7adr,eflag) >*/
    chktab_(&feq_gen_c_d_10, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &cdcom_1.tb7adr, 
	    eflag);
/* SOURCE culverta.for:3674 */
/*<       callchktab(2,stdout,ftpnt,mftnum,tb8adr,eflag) >*/
    chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &cdcom_1.tb8adr, eflag)
	    ;
/* SOURCE culverta.for:3678 */
/*<       callchktab(10,stdout,ftpnt,mftnum,tb15ad,eflag) >*/
    chktab_(&feq_gen_c_d_10, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &cdcom_1.tb15ad, 
	    eflag);
/* SOURCE culverta.for:3682 */
/*<       do120i=1,4 >*/
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= 4; ++feq_gen_i_d_) {
/* SOURCE culverta.for:3683 */
/*<       callchktab(10,stdout,ftpnt,mftnum,tb16ad(i),eflag) >*/
	chktab_(&feq_gen_c_d_10, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &cdcom_1.tb16ad[
		feq_gen_i_d_ - 1], eflag);
/* SOURCE culverta.for:3687 */
/*<   120 continue >*/
/* L120: */
    }
/* SOURCE culverta.for:3688 */
/*<       callchktab(2,stdout,ftpnt,mftnum,tb5adr,eflag) >*/
    chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &cdcom_1.tb5adr, eflag)
	    ;
/* SOURCE culverta.for:3692 */
/*<       callchktab(2,stdout,ftpnt,mftnum,tb21adr,eflag) >*/
    chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &cdcom_1.tb21adr, 
	    eflag);
/* SOURCE culverta.for:3696 */
/*<       callchktab(10,stdout,ftpnt,mftnum,tb22adr,eflag) >*/
    chktab_(&feq_gen_c_d_10, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &cdcom_1.tb22adr, 
	    eflag);
/* SOURCE culverta.for:3700 */
/*<       callchktab(2,stdout,ftpnt,mftnum,tb24adr,eflag) >*/
    chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &cdcom_1.tb24adr, 
	    eflag);
/* SOURCE culverta.for:3704 */
/*<       callchktab(2,stdout,ftpnt,mftnum,tblpdadr,eflag) >*/
    chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &cdcom_1.tblpdadr, 
	    eflag);
/*     Set defaults for low-head flow limits. */
/* SOURCE culverta.for:3710 */
/*<       ty1ytd=0.95 >*/
    culcom_1.ty1ytd = (float).95;
/* SOURCE culverta.for:3711 */
/*<       ty1htd=1.4 >*/
    culcom_1.ty1htd = (float)1.4;
/* SOURCE culverta.for:3713 */
/*<       if(line(1:6).eq.'TYPE 1'.or.line(1:6).eq.'Type 1')then >*/
    if (s_cmp(line, const_cast<char*>("TYPE 1"), (ftnlen)6, (ftnlen)6) == 0 || s_cmp(line, const_cast<char*>("Typ\
e 1"), (ftnlen)6, (ftnlen)6) == 0) {
/*       Process optional type 1 parameters. */
/* SOURCE culverta.for:3715 */
/*<       write(stdout,92)line(1:80) >*/
	feq_gen_io_d__365.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__365);
	do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
	e_wsfe();
/* SOURCE culverta.for:3716 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3719 */
/*<       read(line,21,err=991)ty1ytd >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_21;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&culcom_1.ty1ytd, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE culverta.for:3720 */
/*<       write(stdout,38)ty1ytd >*/
	feq_gen_io_d__366.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__366);
	do_fio(&feq_gen_c_d_1, (char *)&culcom_1.ty1ytd, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culverta.for:3721 */
/*<       if(ty1ytd.le.0.5.or.ty1ytd.gt.1.0)then >*/
	if (culcom_1.ty1ytd <= (float).5 || culcom_1.ty1ytd > (float)1.) {
/* SOURCE culverta.for:3722 */
/*<       write(stdout,53) >*/
	    feq_gen_io_d__367.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__367);
	    e_wsfe();
/* SOURCE culverta.for:3723 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE culverta.for:3724 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3725 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3728 */
/*<       read(line,23,err=991)ty1htd >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 80;
	feq_gen_ici_d_1.iciunit = line;
	feq_gen_ici_d_1.icifmt = fmt_23;
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&culcom_1.ty1htd, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE culverta.for:3729 */
/*<       write(stdout,39)ty1htd >*/
	feq_gen_io_d__368.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__368);
	do_fio(&feq_gen_c_d_1, (char *)&culcom_1.ty1htd, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culverta.for:3730 */
/*<       if(ty1htd.lt.1.0.or.ty1htd.ge.1.6)then >*/
	if (culcom_1.ty1htd < (float)1. || culcom_1.ty1htd >= (float)1.6) {
/* SOURCE culverta.for:3731 */
/*<       write(stdout,55) >*/
	    feq_gen_io_d__369.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__369);
	    e_wsfe();
/* SOURCE culverta.for:3732 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE culverta.for:3733 */
/*<       endif >*/
	}
/*       Read the next heading */
/* SOURCE culverta.for:3735 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3738 */
/*<       endif >*/
    }
/* SOURCE culverta.for:3740 */
/*<       if(eflag.eq.0)then >*/
    if (*eflag == 0) {
/*       Check for request for lookup.  Assumes that type 5 section */
/*       has been given with the parameter values.  The lookup is */
/*       done anyway because all values in that section have defaults. */
/* SOURCE culverta.for:3744 */
/*<       if(krb.eq.0.0)then >*/
	if (cdcom_1.krb == (float)0.) {
/* SOURCE culverta.for:3745 */
/*<       if(bvangl.eq.0.0)then >*/
	    if (cdcom_1.bvangl == (float)0.) {
/*           RBVAL is for rounding. */
/* SOURCE culverta.for:3747 */
/*<       calllktab(tb21adr,rbval,1,krb,ntab,df) >*/
		lktab_(&cdcom_1.tb21adr, &cdcom_1.rbval, &feq_gen_c_d_1, &cdcom_1.krb, 
			&ntab, &df);
/* SOURCE culverta.for:3750 */
/*<       else >*/
	    } else {
/*           RBVAL is for beveling.  Two-D table. */
/* SOURCE culverta.for:3752 */
/*<       calltdlk10(stdout,tb22adr,10,rbval,bvangl,krb,dfdr,dfdc) >*/
		tdlk10_(stdout, &cdcom_1.tb22adr, &feq_gen_c_d_10, &cdcom_1.rbval, &
			cdcom_1.bvangl, &cdcom_1.krb, &dfdr, &dfdc);
/* SOURCE culverta.for:3756 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:3757 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3758 */
/*<       write(stdout,69)krb >*/
	feq_gen_io_d__374.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__374);
	do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.krb, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culverta.for:3759 */
/*<       if(krb.lt.1.0.or.krb.gt.1.5)then >*/
	if (cdcom_1.krb < (float)1. || cdcom_1.krb > (float)1.5) {
/* SOURCE culverta.for:3760 */
/*<       write(stdout,76) >*/
	    feq_gen_io_d__375.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__375);
	    e_wsfe();
/* SOURCE culverta.for:3761 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE culverta.for:3762 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3765 */
/*<       if(kwing.eq.0.0)then >*/
	if (cdcom_1.kwing == (float)0.) {
/* SOURCE culverta.for:3766 */
/*<       if(culcls.eq.'BOX')then >*/
	    if (s_cmp(culcls, const_cast<char*>("BOX"), (ftnlen)8, (ftnlen)3) == 0) {
/* SOURCE culverta.for:3767 */
/*<       calllktab(tb24adr,wwangl,1,kwing,ntab,df) >*/
		lktab_(&cdcom_1.tb24adr, &cdcom_1.wwangl, &feq_gen_c_d_1, &
			cdcom_1.kwing, &ntab, &df);
/* SOURCE culverta.for:3770 */
/*<       else >*/
	    } else {
/*           Only box culverts are affected by wingwalls.  All others */
/*           are not changed. */
/* SOURCE culverta.for:3773 */
/*<       kwing=1.0 >*/
		cdcom_1.kwing = (float)1.;
/* SOURCE culverta.for:3774 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:3775 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3776 */
/*<       write(stdout,66)kwing >*/
	feq_gen_io_d__376.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__376);
	do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.kwing, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culverta.for:3777 */
/*<       if(kwing.lt.1.0.or.kwing.gt.1.25)then >*/
	if (cdcom_1.kwing < (float)1. || cdcom_1.kwing > (float)1.25) {
/* SOURCE culverta.for:3778 */
/*<       write(stdout,78) >*/
	    feq_gen_io_d__377.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__377);
	    e_wsfe();
/* SOURCE culverta.for:3779 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE culverta.for:3780 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3782 */
/*<       if(kwing.ne.1.0.and.culcls.ne.'BOX')then >*/
	if (cdcom_1.kwing != (float)1. && s_cmp(culcls, const_cast<char*>("BOX"), (ftnlen)8, (
		ftnlen)3) != 0) {
/* SOURCE culverta.for:3783 */
/*<       write(stdout,8)kwing >*/
	    feq_gen_io_d__378.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__378);
	    do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.kwing, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culverta.for:3784 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3785 */
/*<       if(kproj.eq.0.0)then >*/
	if (cdcom_1.kproj == (float)0.) {
/* SOURCE culverta.for:3786 */
/*<       if(culcls.ne.'BOX'.and.culcls.ne.'RCPTG')then >*/
	    if (s_cmp(culcls, const_cast<char*>("BOX"), (ftnlen)8, (ftnlen)3) != 0 && s_cmp(
		    culcls, const_cast<char*>("RCPTG"), (ftnlen)8, (ftnlen)5) != 0) {
/* SOURCE culverta.for:3787 */
/*<       calllktab(tblpdadr,lpovd,1,kproj,ntab,df) >*/
		lktab_(&cdcom_1.tblpdadr, &cdcom_1.lpovd, &feq_gen_c_d_1, &
			cdcom_1.kproj, &ntab, &df);
/* SOURCE culverta.for:3790 */
/*<       else >*/
	    } else {
/* SOURCE culverta.for:3791 */
/*<       kproj=1.0 >*/
		cdcom_1.kproj = (float)1.;
/* SOURCE culverta.for:3792 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:3793 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3794 */
/*<       write(stdout,68)kproj >*/
	feq_gen_io_d__379.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__379);
	do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.kproj, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culverta.for:3795 */
/*<       if(kproj.lt.0.90.or.kproj.gt.1.0)then >*/
	if (cdcom_1.kproj < (float).9 || cdcom_1.kproj > (float)1.) {
/* SOURCE culverta.for:3796 */
/*<       write(stdout,80)kproj >*/
	    feq_gen_io_d__380.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__380);
	    do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.kproj, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culverta.for:3797 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE culverta.for:3798 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3799 */
/*<       if(kproj.ne.1.0.and.(culcls.eq.'BOX'.or.culcls.eq.'RCPTG'))then >*/
	if (cdcom_1.kproj != (float)1. && (s_cmp(culcls, const_cast<char*>("BOX"), (ftnlen)8, (
		ftnlen)3) == 0 || s_cmp(culcls, const_cast<char*>("RCPTG"), (ftnlen)8, (ftnlen)5)
		 == 0)) {
/* SOURCE culverta.for:3801 */
/*<       write(stdout,9)kproj >*/
	    feq_gen_io_d__381.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__381);
	    do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.kproj, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culverta.for:3802 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3803 */
/*<       if(c46.eq.0.0)then >*/
	if (cdcom_1.c46 == (float)0.) {
/* SOURCE culverta.for:3804 */
/*<       callfdcd46(stdout,culcls,rbval,c46) >*/
	    fdcd46_(stdout, culcls, &cdcom_1.rbval, &cdcom_1.c46, (ftnlen)8);
/* SOURCE culverta.for:3807 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3808 */
/*<       if(ty6sup.eq.1)then >*/
	if (cdcom_1.ty6sup == 1) {
/* SOURCE culverta.for:3809 */
/*<       write(stdout,64)c46 >*/
	    feq_gen_io_d__382.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__382);
	    do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.c46, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culverta.for:3810 */
/*<       else >*/
	} else {
/* SOURCE culverta.for:3811 */
/*<       write(stdout,67)c46 >*/
	    feq_gen_io_d__383.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__383);
	    do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.c46, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culverta.for:3812 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3813 */
/*<       if(c46.lt.0.60.or.c46.gt.1.0)then >*/
	if (cdcom_1.c46 < (float).6 || cdcom_1.c46 > (float)1.) {
/* SOURCE culverta.for:3814 */
/*<       write(stdout,86)c46 >*/
	    feq_gen_io_d__384.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__384);
	    do_fio(&feq_gen_c_d_1, (char *)&cdcom_1.c46, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culverta.for:3815 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE culverta.for:3816 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3817 */
/*<       endif >*/
    }
/*     INPUT THE ROADWAY DESCRIPTION HERE.  STORE IN SAME MANNER AS */
/*     FOR EMBANKQ. */
/*     This LINE has been read above in process various optional */
/*     input blocks. */
/* SOURCE culverta.for:3823 */
/*<       write(stdout,92)line(1:80) >*/
    feq_gen_io_d__385.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__385);
    do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
    e_wsfe();
/* SOURCE culverta.for:3825 */
/*<        >*/
    etabin_(stdin, stdout, &feq_gen_c_d_10002, ftablea_1.ftpnt, eflag, &
	    embcom_1.plcwtb, &embcom_1.glcwtb, &embcom_1.phcwtb, &
	    embcom_1.ghcwtb, &embcom_1.psubtb, &embcom_1.gsubtb);
/* SOURCE culverta.for:3829 */
/*<       if(psubtb.eq.0.or.gsubtb.eq.0)then >*/
    if (embcom_1.psubtb == 0 || embcom_1.gsubtb == 0) {
/* SOURCE culverta.for:3830 */
/*<       write(stdout,70) >*/
	feq_gen_io_d__386.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__386);
	e_wsfe();
/* SOURCE culverta.for:3831 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE culverta.for:3832 */
/*<       endif >*/
    }
/* SOURCE culverta.for:3833 */
/*<        >*/
    inprdp_(stdin, stdout, &zdatum, eflag, &embcom_1.noff, &embcom_1.mincrs, &
	    embcom_1.minloc, embcom_1.off, embcom_1.crest, embcom_1.width, 
	    embcom_1.approc, embcmc_1.surf, (ftnlen)8);
/*     INPUT THE FACTORS CONTROLLING THE UPSTREAM HEADS AND THE */
/*     DISTRIBUTION OF DROPS */
/* SOURCE culverta.for:3842 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3845 */
/*<       read(line,24,err=991)head >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_24;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE culverta.for:3846 */
/*<       write(stdout,92)head >*/
    feq_gen_io_d__387.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__387);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_wsfe();
/* SOURCE culverta.for:3848 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3851 */
/*<       read(line,26,err=991)char5,nfrac >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_26;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&nfrac, (ftnlen)sizeof(integer));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE culverta.for:3852 */
/*<       write(stdout,94)nfrac >*/
    feq_gen_io_d__389.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__389);
    do_fio(&feq_gen_c_d_1, (char *)&nfrac, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE culverta.for:3854 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3857 */
/*<       read(line,16,err=991)char5,power >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = fmt_16;
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&power, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE culverta.for:3858 */
/*<       write(stdout,11)power >*/
    feq_gen_io_d__391.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__391);
    do_fio(&feq_gen_c_d_1, (char *)&power, (ftnlen)sizeof(real));
    e_wsfe();
/*     COMPUTE THE PROPORTIONS OF FREE DROP */
/* SOURCE culverta.for:3862 */
/*<       do200i=1,nfrac >*/
    feq_gen_i_d_1 = nfrac;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culverta.for:3863 */
/*<       pfdvec(i)=(float(i-1)/float(nfrac-1))**power >*/
	feq_gen_d_d_1 = (doublereal) (static_cast<double>((real) (feq_gen_i_d_ - 1)) / (real) (nfrac - 1));
	feq_gen_d_d_2 = (doublereal) power;
	pfdvec[feq_gen_i_d_ - 1] = pow_dd(&feq_gen_d_d_1, &feq_gen_d_d_2);
/* SOURCE culverta.for:3864 */
/*<   200 continue >*/
/* L200: */
    }
/*     INPUT THE HEAD SEQUENCE */
/* SOURCE culverta.for:3868 */
/*<       i=1 >*/
    feq_gen_i_d_ = 1;
/* SOURCE culverta.for:3869 */
/*<       huold=-1.0 >*/
    huold = (float)-1.;
/* SOURCE culverta.for:3870 */
/*<   300 continue >*/
L300:
/* SOURCE culverta.for:3871 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE culverta.for:3874 */
/*<       read(line,'(F10.0)',err=991)huvec(i) >*/
    feq_gen_ici_d_1.icierr = 1;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 80;
    feq_gen_ici_d_1.iciunit = line;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.0)");
    feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&huvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE culverta.for:3875 */
/*<       write(stdout,'(1X,F10.2)')huvec(i) >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(1X,F10.2)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&huvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE culverta.for:3876 */
/*<       if(huvec(i).le.0.0)then >*/
    if (huvec[feq_gen_i_d_ - 1] <= (float)0.) {
/* SOURCE culverta.for:3877 */
/*<       nhu=i-1 >*/
	nhu = feq_gen_i_d_ - 1;
/* SOURCE culverta.for:3878 */
/*<       goto310 >*/
	goto L310;
/* SOURCE culverta.for:3879 */
/*<       else >*/
    } else {
/* SOURCE culverta.for:3880 */
/*<       if(huvec(i).le.huold)then >*/
	if (huvec[feq_gen_i_d_ - 1] <= huold) {
/* SOURCE culverta.for:3881 */
/*<       write(stdout,99)huvec(i) >*/
	    feq_gen_io_d__396.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__396);
	    do_fio(&feq_gen_c_d_1, (char *)&huvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culverta.for:3882 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE culverta.for:3883 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3884 */
/*<       huold=huvec(i) >*/
	huold = huvec[feq_gen_i_d_ - 1];
/* SOURCE culverta.for:3885 */
/*<       i=i+1 >*/
	++feq_gen_i_d_;
/* SOURCE culverta.for:3886 */
/*<       if(i.gt.pmxnhu)then >*/
	if (feq_gen_i_d_ > 151) {
/* SOURCE culverta.for:3887 */
/*<        >*/
	    feq_gen_ci_d_1.cierr = 0;
	    feq_gen_ci_d_1.ciunit = *stdout;
	    feq_gen_ci_d_1.cifmt = const_cast<char*>("(' *ERR:548* MORE THAN ',I5,' UPSTREAM HEADS')");
	    s_wsfe(&feq_gen_ci_d_1);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_151, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE culverta.for:3890 */
/*<       i=pmxnhu >*/
	    feq_gen_i_d_ = 151;
/* SOURCE culverta.for:3891 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE culverta.for:3892 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3894 */
/*<       goto300 >*/
	goto L300;
/* SOURCE culverta.for:3895 */
/*<       endif >*/
    }
/* SOURCE culverta.for:3896 */
/*<   310 continue >*/
L310:
/* SOURCE culverta.for:3898 */
/*<       if(eflag.ne.0)return >*/
    if (*eflag != 0) {
	return 0;
    }
/*     INPUT OF DATA COMPLETE.  BEGIN THE COMPUTATIONS. */
/*     ASSIGN LABELED COMMON COPIES OF TABLE ADDRESSES AND */
/*     BOTTOM ELEVATIONS */
/*     FOR CURRENT VERSION SECTION 0 AND SECTION 1 ARE THE SAME. */
/*     THIS WILL BE CHANGED WHEN DROP INLETS ARE SUPPORTED. */
/* SOURCE culverta.for:3908 */
/*<       adrxs0=apptab >*/
    xs0com_1.adrxs0 = appcom_1.apptab;
/* SOURCE culverta.for:3909 */
/*<       adrxs1=apptab >*/
    xs1com_1.adrxs1 = appcom_1.apptab;
/* SOURCE culverta.for:3910 */
/*<       adrxs2=nsec(1) >*/
    xs2com_1.adrxs2 = culcom_1.nsec[0];
/* SOURCE culverta.for:3911 */
/*<       adrxs3=nsec(nbn) >*/
    xs3com_1.adrxs3 = culcom_1.nsec[nbn - 1];
/* SOURCE culverta.for:3912 */
/*<       adrxs4=deptab >*/
    xs4com_1.adrxs4 = depcom_1.deptab;
/* SOURCE culverta.for:3913 */
/*<       adrs43=begtab >*/
    x43com_1.adrs43 = depcom_1.begtab;
/* SOURCE culverta.for:3914 */
/*<       adrs44=begtab >*/
    x44com_1.adrs44 = depcom_1.begtab;
/* SOURCE culverta.for:3917 */
/*<       zb0=appelv >*/
    xs0com_1.zb0 = appcom_1.appelv;
/* SOURCE culverta.for:3918 */
/*<       zb1=appelv >*/
    xs1com_1.zb1 = appcom_1.appelv;
/* SOURCE culverta.for:3919 */
/*<       zb2=zbvec(1) >*/
    xs2com_1.zb2 = culcom_1.zbvec[0];
/* SOURCE culverta.for:3920 */
/*<       zb3=zbvec(nbn) >*/
    xs3com_1.zb3 = culcom_1.zbvec[nbn - 1];
/* SOURCE culverta.for:3921 */
/*<       zb4=depelv >*/
    xs4com_1.zb4 = depcom_1.depelv;
/* SOURCE culverta.for:3922 */
/*<       zb43=begelv >*/
    x43com_1.zb43 = depcom_1.begelv;
/* SOURCE culverta.for:3923 */
/*<       zb44=begelv >*/
    x44com_1.zb44 = depcom_1.begelv;
/*     VFAC WILL BE CHANGED WHEN DROP INLETS ARE SUPPORTED */
/* SOURCE culverta.for:3926 */
/*<       vfac=1.0 >*/
    xs0com_1.vfac = (float)1.;
/*     FIND THE MAXIMUM VERTICAL DIAMETER ALONG THE CULVERT */
/* SOURCE culverta.for:3930 */
/*<       do320i=1,nbn >*/
    feq_gen_i_d_1 = nbn;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culverta.for:3931 */
/*<       dvec(i)=getd(nsec(i),stdout) >*/
	culcom_1.dvec[feq_gen_i_d_ - 1] = getd_(&culcom_1.nsec[feq_gen_i_d_ - 1], stdout);
/* SOURCE culverta.for:3932 */
/*<       if(dvec(i).lt.0)then >*/
	if (culcom_1.dvec[feq_gen_i_d_ - 1] < (float)0.) {
/*         Signal an error. */
/* SOURCE culverta.for:3934 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE culverta.for:3935 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3936 */
/*<   320 continue >*/
/* L320: */
    }
/* SOURCE culverta.for:3937 */
/*<       dup=dvec(1) >*/
    dup = culcom_1.dvec[0];
/* SOURCE culverta.for:3938 */
/*<       ddn=dvec(nbn) >*/
    ddn = culcom_1.dvec[nbn - 1];
/* SOURCE culverta.for:3940 */
/*<       write(stdout,95)dup,ddn >*/
    feq_gen_io_d__399.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__399);
    do_fio(&feq_gen_c_d_1, (char *)&dup, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&ddn, (ftnlen)sizeof(real));
    e_wsfe();
/*     Check the barrel description for non-increasing critical */
/*     flow. */
/* SOURCE culverta.for:3944 */
/*<       write(stdout,31) >*/
    feq_gen_io_d__400.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__400);
    e_wsfe();
/* SOURCE culverta.for:3945 */
/*<       callchkcfc(grav,stdout,adrxs2,wflag) >*/
    chkcfc_(&grvcom_1.grav, stdout, &xs2com_1.adrxs2, &wflag);
/* SOURCE culverta.for:3948 */
/*<       if(wflag.ne.0)then >*/
    if (wflag != 0) {
/* SOURCE culverta.for:3949 */
/*<       write(stdout,32) >*/
	feq_gen_io_d__402.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__402);
	e_wsfe();
/* SOURCE culverta.for:3950 */
/*<       endif >*/
    }
/* SOURCE culverta.for:3951 */
/*<       if(adrxs3.ne.adrxs2)then >*/
    if (xs3com_1.adrxs3 != xs2com_1.adrxs2) {
/* SOURCE culverta.for:3952 */
/*<       write(stdout,33) >*/
	feq_gen_io_d__403.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__403);
	e_wsfe();
/* SOURCE culverta.for:3953 */
/*<       callchkcfc(grav,stdout,adrxs3,wflag) >*/
	chkcfc_(&grvcom_1.grav, stdout, &xs3com_1.adrxs3, &wflag);
/* SOURCE culverta.for:3956 */
/*<       if(wflag.ne.0)then >*/
	if (wflag != 0) {
/* SOURCE culverta.for:3957 */
/*<       write(stdout,32) >*/
	    feq_gen_io_d__404.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__404);
	    e_wsfe();
/* SOURCE culverta.for:3958 */
/*<       endif >*/
	}
/* SOURCE culverta.for:3959 */
/*<       endif >*/
    }
/*     Set the elevation of the soffit at culvert exit(section 3) */
/* SOURCE culverta.for:3961 */
/*<       z3sof=zb3+ddn >*/
    z3sof = static_cast<double>(xs3com_1.zb3) + ddn;
/*     SELECT THE POINT DEFINING HEAD FOR THE CULVERT. */
/* SOURCE culverta.for:3966 */
/*<       hdatum=max(appelv,zbvec(1),zbvec(nbn),depelv) >*/
/* Computing MAX */
    feq_gen_r_d_1 = max(appcom_1.appelv,culcom_1.zbvec[0]), feq_gen_r_d_2 = culcom_1.zbvec[nbn 
	    - 1], feq_gen_r_d_1 = max(feq_gen_r_d_1,feq_gen_r_d_2);
    hdatum = dmax(feq_gen_r_d_1,depcom_1.depelv);
/* SOURCE culverta.for:3968 */
/*<       write(stdout,96)hdatum+zdatum >*/
    feq_gen_io_d__407.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__407);
    feq_gen_r_d_1 = static_cast<double>(hdatum) + zdatum;
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE culverta.for:3970 */
/*<       if(mincrs.le.hdatum)then >*/
    if (embcom_1.mincrs <= hdatum) {
/*       MINIMUM ROADWAY ELEVATION MUST BE GREATER THAN THE ELEVATION */
/*       OF THE DATUM FOR HEAD */
/* SOURCE culverta.for:3974 */
/*<       write(stdout,93) >*/
	feq_gen_io_d__408.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__408);
	e_wsfe();
/* SOURCE culverta.for:3975 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE culverta.for:3976 */
/*<       return >*/
	return 0;
/* SOURCE culverta.for:3977 */
/*<       endif >*/
    }
/* SOURCE culverta.for:3979 */
/*<       if(mincrs.le.zbvec(1)+dup.or.mincrs.le.zbvec(nbn)+ddn)then >*/
    if (embcom_1.mincrs <= static_cast<double>(culcom_1.zbvec[0]) + dup || embcom_1.mincrs <= 
	    static_cast<double>(culcom_1.zbvec[nbn - 1]) + ddn) {
/*       SEND WARNING IF MINIMUM ELEVATION OF ROADWAY IS BELOW */
/*       THE CULVERT SOFFITS. */
/* SOURCE culverta.for:3982 */
/*<       write(stdout,91) >*/
	feq_gen_io_d__409.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__409);
	e_wsfe();
/* SOURCE culverta.for:3983 */
/*<       endif >*/
    }
/* SOURCE culverta.for:3985 */
/*<        >*/
    xlktal_(&xs3com_1.adrxs3, &ddn, &xs3com_1.a3full, &xs3com_1.t3, &
	    xs3com_1.dt3, &xs3com_1.j3, &xs3com_1.k3, &xs3com_1.dk3, &
	    xs3com_1.bt3atd, &xs3com_1.dbet3, &xs3com_1.ap3atd, &
	    xs3com_1.dalp3);
/* SOURCE culverta.for:3990 */
/*<       calllkta(adrxs2,dup,a2full) >*/
    lkta_(&xs2com_1.adrxs2, &dup, &xs2com_1.a2full);
/* SOURCE culverta.for:3994 */
/*<       calllktk(adrxs2,dup,k2full) >*/
    lktk_(&xs2com_1.adrxs2, &dup, &xs2com_1.k2full);
/*     Compute the length of the barrel and length related values. */
/* SOURCE culverta.for:4000 */
/*<       l23=abs(xvec(1)-xvec(nbn)) >*/
    culcom_1.l23 = (feq_gen_r_d_1 = static_cast<double>(culcom_1.xvec[0]) - culcom_1.xvec[nbn - 1], dabs(
	    feq_gen_r_d_1));
/* SOURCE culverta.for:4001 */
/*<       loverd=l23/dup >*/
    culcom_1.loverd = static_cast<double>(culcom_1.l23) / dup;
/*     Check user-specified node spacing for inclusion of the */
/*     critical locations for type 5 flow. */
/* SOURCE culverta.for:4005 */
/*<       if(chkbar.eq.1)then >*/
    if (chkbar == 1) {
/* SOURCE culverta.for:4006 */
/*<       x3d=3.*dup >*/
	x3d = static_cast<double>(dup) * (float)3.;
/* SOURCE culverta.for:4007 */
/*<       x6d=6.*dup >*/
	x6d = static_cast<double>(dup) * (float)6.;
/* SOURCE culverta.for:4009 */
/*<       iat3d=-1 >*/
	culcom_1.iat3d = -1;
/* SOURCE culverta.for:4010 */
/*<       iat6d=-1 >*/
	culcom_1.iat6d = -1;
/* SOURCE culverta.for:4011 */
/*<       do322i=2,nbn >*/
	feq_gen_i_d_1 = nbn;
	for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culverta.for:4012 */
/*<       ratio=abs(xvec(i)-xvec(1))/dup >*/
	    ratio = (feq_gen_r_d_1 = static_cast<double>(culcom_1.xvec[feq_gen_i_d_ - 1]) - culcom_1.xvec[0], dabs(
		    feq_gen_r_d_1)) / dup;
/* SOURCE culverta.for:4013 */
/*<       if(ratio.ge.2.9.and.ratio.le.3.1)then >*/
	    if (ratio >= (float)2.9 && ratio <= (float)3.1) {
/* SOURCE culverta.for:4014 */
/*<       iat3d=i >*/
		culcom_1.iat3d = feq_gen_i_d_;
/* SOURCE culverta.for:4015 */
/*<       elseif(ratio.ge.5.9.and.ratio.le.6.1)then >*/
	    } else if (ratio >= (float)5.9 && ratio <= (float)6.1) {
/* SOURCE culverta.for:4016 */
/*<       iat6d=i >*/
		culcom_1.iat6d = feq_gen_i_d_;
/* SOURCE culverta.for:4017 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:4018 */
/*<   322 continue >*/
/* L322: */
	}
/* SOURCE culverta.for:4020 */
/*<       if(l23.le.x3d)then >*/
	if (culcom_1.l23 <= x3d) {
/*         Culvert length is less than 3 times its vertical diameter. */
/* SOURCE culverta.for:4022 */
/*<       iat3d=1 >*/
	    culcom_1.iat3d = 1;
/* SOURCE culverta.for:4023 */
/*<       iat6d=0 >*/
	    culcom_1.iat6d = 0;
/* SOURCE culverta.for:4024 */
/*<       write(stdout,62) >*/
	    feq_gen_io_d__413.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__413);
	    e_wsfe();
/* SOURCE culverta.for:4025 */
/*<       elseif(l23.le.x6d)then >*/
	} else if (culcom_1.l23 <= x6d) {
/* SOURCE culverta.for:4026 */
/*<       write(stdout,83) >*/
	    feq_gen_io_d__414.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__414);
	    e_wsfe();
/* SOURCE culverta.for:4027 */
/*<       if(iat3d.gt.0)then >*/
	    if (culcom_1.iat3d > 0) {
/* SOURCE culverta.for:4028 */
/*<       iat6d=0 >*/
		culcom_1.iat6d = 0;
/* SOURCE culverta.for:4029 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:4030 */
/*<       endif >*/
	}
/* SOURCE culverta.for:4031 */
/*<       if(iat3d.lt.0.or.iat6d.lt.0)then >*/
	if (culcom_1.iat3d < 0 || culcom_1.iat6d < 0) {
/*         Cannot continue */
/* SOURCE culverta.for:4033 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE culverta.for:4034 */
/*<       write(stdout,40) >*/
	    feq_gen_io_d__415.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__415);
	    e_wsfe();
/* SOURCE culverta.for:4035 */
/*<       endif >*/
	}
/* SOURCE culverta.for:4036 */
/*<       endif >*/
    }
/* SOURCE culverta.for:4038 */
/*<       if(sbkind.eq.0)then >*/
    if (culcom_1.sbkind == 0) {
/* SOURCE culverta.for:4039 */
/*<       szero=(zb2-zb3)/l23 >*/
	culcom_1.szero = static_cast<double>((static_cast<double>(xs2com_1.zb2) - xs3com_1.zb3)) / culcom_1.l23;
/* SOURCE culverta.for:4040 */
/*<       else >*/
    } else {
/*       There are breaks in slope.  Take the bottom slope */
/*       at the entrance. */
/* SOURCE culverta.for:4043 */
/*<       szero=(zbvec(1)-zbvec(2))/abs(xvec(1)-xvec(2)) >*/
	culcom_1.szero = (static_cast<double>(culcom_1.zbvec[0]) - culcom_1.zbvec[1]) / (feq_gen_r_d_1 = 
		static_cast<double>(culcom_1.xvec[0]) - culcom_1.xvec[1], dabs(feq_gen_r_d_1));
/* SOURCE culverta.for:4044 */
/*<       write(stdout,74) >*/
	feq_gen_io_d__416.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__416);
	e_wsfe();
/* SOURCE culverta.for:4045 */
/*<       endif >*/
    }
/*     Is the barrel prismatic? */
/* SOURCE culverta.for:4048 */
/*<       if(bshape.eq.1)then >*/
    if (bshape == 1) {
/*       Non-prismatic.  Compute the factor on square of flow */
/*       to estimate the friction and eddy losses in the */
/*       culvert barrel. */
/* SOURCE culverta.for:4052 */
/*<       frcfac=fdfrfc(1,nbn) >*/
	culcom_1.frcfac = fdfrfc_(&feq_gen_c_d_1, &nbn);
/* SOURCE culverta.for:4053 */
/*<       else >*/
    } else {
/* SOURCE culverta.for:4054 */
/*<       frcfac=l23/k2full**2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = xs2com_1.k2full;
	culcom_1.frcfac = static_cast<double>(culcom_1.l23) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE culverta.for:4055 */
/*<       endif >*/
    }
/* SOURCE culverta.for:4057 */
/*<       if(eflag.ne.0)return >*/
    if (*eflag != 0) {
	return 0;
    }
/*     Add special head values to the head vector.  One is at the */
/*     nominal boundary between high-head and low-head flow.  The */
/*     other is at the crest of the roadway embankment if that crest */
/*     is within the existing head range.  This latter rule is used */
/*     because false high crests are used to disable computation of */
/*     the flow over the embankment. */
/* SOURCE culverta.for:4066 */
/*<       hhlim=1.5*dup+zb2-hdatum >*/
    hhlim = static_cast<double>(static_cast<double>(static_cast<double>(dup) * (float)1.5) + xs2com_1.zb2) - hdatum;
/* SOURCE culverta.for:4067 */
/*<       if(hhlim.le.0.0)hhlim=-1.0 >*/
    if (hhlim <= (float)0.) {
	hhlim = (float)-1.;
    }
/* SOURCE culverta.for:4068 */
/*<       if(hhlim.ge.huvec(nhu))then >*/
    if (hhlim >= huvec[nhu - 1]) {
/*       Do not add the high-head flow limit */
/* SOURCE culverta.for:4070 */
/*<       hhlim=-1.0 >*/
	hhlim = (float)-1.;
/* SOURCE culverta.for:4071 */
/*<       endif >*/
    }
/* SOURCE culverta.for:4072 */
/*<       hcrest=mincrs-hdatum >*/
    hcrest = static_cast<double>(embcom_1.mincrs) - hdatum;
/* SOURCE culverta.for:4073 */
/*<       if(hcrest.ge.huvec(nhu))then >*/
    if (hcrest >= huvec[nhu - 1]) {
/*       Do not add the road crest head */
/* SOURCE culverta.for:4075 */
/*<       hcrest=-1.0 >*/
	hcrest = (float)-1.;
/* SOURCE culverta.for:4076 */
/*<       endif >*/
    }
/* SOURCE culverta.for:4077 */
/*<       if(hhlim.gt.0.0)then >*/
    if (hhlim > (float)0.) {
/* SOURCE culverta.for:4078 */
/*<       nt=nhu >*/
	nt = nhu;
/* SOURCE culverta.for:4079 */
/*<       callinsert(hhlim,epsdif,pmxnhu,nhu,huvec,eflag) >*/
	insert_(&hhlim, &epscom_1.epsdif, &feq_gen_c_d_151, &nhu, huvec, eflag);
/* SOURCE culverta.for:4083 */
/*<       if(eflag.gt.0)then >*/
	if (*eflag > 0) {
/* SOURCE culverta.for:4084 */
/*<       write(stdout,34)pmxnhu >*/
	    feq_gen_io_d__420.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__420);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_151, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE culverta.for:4085 */
/*<       return >*/
	    return 0;
/* SOURCE culverta.for:4086 */
/*<       endif >*/
	}
/* SOURCE culverta.for:4087 */
/*<       if(nhu.gt.nt)then >*/
	if (nhu > nt) {
/* SOURCE culverta.for:4088 */
/*<       write(stdout,3)hhlim >*/
	    feq_gen_io_d__421.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__421);
	    do_fio(&feq_gen_c_d_1, (char *)&hhlim, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culverta.for:4089 */
/*<       endif >*/
	}
/* SOURCE culverta.for:4090 */
/*<       endif >*/
    }
/* SOURCE culverta.for:4091 */
/*<       if(hcrest.gt.0.0)then >*/
    if (hcrest > (float)0.) {
/* SOURCE culverta.for:4092 */
/*<       nt=nhu >*/
	nt = nhu;
/* SOURCE culverta.for:4093 */
/*<       callinsert(hcrest,epsdif,pmxnhu,nhu,huvec,eflag) >*/
	insert_(&hcrest, &epscom_1.epsdif, &feq_gen_c_d_151, &nhu, huvec, eflag);
/* SOURCE culverta.for:4097 */
/*<       if(eflag.gt.0)then >*/
	if (*eflag > 0) {
/* SOURCE culverta.for:4098 */
/*<       write(stdout,35)pmxnhu >*/
	    feq_gen_io_d__422.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__422);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_151, (ftnlen)sizeof(integer));
	    e_wsfe();
/* SOURCE culverta.for:4099 */
/*<       return >*/
	    return 0;
/* SOURCE culverta.for:4100 */
/*<       endif >*/
	}
/* SOURCE culverta.for:4101 */
/*<       if(nhu.gt.nt)then >*/
	if (nhu > nt) {
/* SOURCE culverta.for:4102 */
/*<       write(stdout,5)hcrest >*/
	    feq_gen_io_d__423.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__423);
	    do_fio(&feq_gen_c_d_1, (char *)&hcrest, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culverta.for:4103 */
/*<       endif >*/
	}
/* SOURCE culverta.for:4104 */
/*<       endif >*/
    }
/*     Establish the function table storage pointer for any temporary */
/*     tables to be constructed during the CULVERT command. */
/* SOURCE culverta.for:4108 */
/*<       ftptmp=ftp >*/
    ftptmp = *ftp;
/*     CHECK TO MAKE SURE THAT THE CROSS SECTION AT THE BEGINNING OF THE */
/*     DEPARTURE REACH IS LARGER THAN THE CULVERT EXIT SECTION BY */
/*     AT LEAST THE FACTOR WIDFAC WHEN THE WATER SURFACE IN THE TWO */
/*     SECTIONS IS AT THE SAME ELEVATION.  If not true, construct */
/*     a temporary table that does satisfy the requirements. */
/*     Put out graphic warning message to user. */
/* SOURCE culverta.for:4118 */
/*<       callchkdep(stdout,eflag,ftptmp) >*/
    chkdep_(stdout, eflag, &ftptmp);
/* SOURCE culverta.for:4122 */
/*<       if(eflag.ne.0)return >*/
    if (*eflag != 0) {
	return 0;
    }
/*     SET THE CHARACTER OF THE SECTION AT LOCATION 44.  Always the */
/*     same as the section at 43.    Section 4 may differ from these */
/*     two, however, */
/* SOURCE culverta.for:4128 */
/*<       adrs44=adrs43 >*/
    x44com_1.adrs44 = x43com_1.adrs43;
/*     Signal that the boundaries of types 1, 2, 5, 61, and 6 have not */
/*     been computed. */
/* SOURCE culverta.for:4133 */
/*<       cd1=0.0 >*/
    xs3com_1.cd1 = (float)0.;
/* SOURCE culverta.for:4134 */
/*<       z1ty1=zb1 >*/
    xs1com_1.z1ty1 = xs1com_1.zb1;
/* SOURCE culverta.for:4135 */
/*<       z1ty1l=zb1 >*/
    xs1com_1.z1ty1l = xs1com_1.zb1;
/* SOURCE culverta.for:4136 */
/*<       cd2=0.0 >*/
    xs3com_1.cd2 = (float)0.;
/* SOURCE culverta.for:4137 */
/*<       z1ty2=zb1 >*/
    xs1com_1.z1ty2 = xs1com_1.zb1;
/* SOURCE culverta.for:4138 */
/*<       cc5=0.0 >*/
    xs3com_1.cc5 = (float)0.;
/* SOURCE culverta.for:4139 */
/*<       z1ty5=zb1 >*/
    xs1com_1.z1ty5 = xs1com_1.zb1;
/* SOURCE culverta.for:4140 */
/*<       cd61=0.0 >*/
    xs3com_1.cd61 = (float)0.;
/* SOURCE culverta.for:4141 */
/*<       z1ty61=zb1 >*/
    xs1com_1.z1ty61 = xs1com_1.zb1;
/* SOURCE culverta.for:4142 */
/*<       cd6=0.0 >*/
    xs3com_1.cd6 = (float)0.;
/* SOURCE culverta.for:4143 */
/*<       z1ty6=zb1 >*/
    xs1com_1.z1ty6 = xs1com_1.zb1;
/* SOURCE culverta.for:4145 */
/*<       z1ty51=zb1 >*/
    xs1com_1.z1ty51 = xs1com_1.zb1;
/* SOURCE culverta.for:4146 */
/*<       z1ty52=zb1 >*/
    xs1com_1.z1ty52 = xs1com_1.zb1;
/* SOURCE culverta.for:4148 */
/*<       z3pest=zb3 >*/
    xs3com_1.z3pest = xs3com_1.zb3;
/*     Clear the transitional free flow coefficients of discharge. */
/* SOURCE culverta.for:4151 */
/*<       cd1t6=0.0 >*/
    xs3com_1.cd1t6 = (float)0.;
/* SOURCE culverta.for:4152 */
/*<       cd2t6=0.0 >*/
    xs3com_1.cd2t6 = (float)0.;
/* SOURCE culverta.for:4153 */
/*<       cd61t6=0.0 >*/
    xs3com_1.cd61t6 = (float)0.;
/* SOURCE culverta.for:4154 */
/*<       cc2t5=0.0 >*/
    xs3com_1.cc2t5 = (float)0.;
/* SOURCE culverta.for:4155 */
/*<       cc1t5=0.0 >*/
    xs3com_1.cc1t5 = (float)0.;
/*     Set the user full-flow-inducing value at section 3 for flow type 5 */
/*     and its relatives. */
/* SOURCE culverta.for:4159 */
/*<       y3limu=ddn*ty5sbf >*/
    y3limu = static_cast<double>(ddn) * culcom_1.ty5sbf;
/*     Initialize the flow type memories: last free type and last */
/*     submerged type.  -1 means undefined. */
/* SOURCE culverta.for:4163 */
/*<       lftype=-1 >*/
    xs2com_1.lftype = -1;
/* SOURCE culverta.for:4164 */
/*<       lstype=-1 >*/
    xs2com_1.lstype = -1;
/*     Signal that no value of free flow is known. */
/* SOURCE culverta.for:4168 */
/*<       q3free=0.0 >*/
    xs3com_1.q3free = (float)0.;
/* SOURCE culverta.for:4169 */
/*<       y3free=0.0 >*/
    xs3com_1.y3free = (float)0.;
/* SOURCE culverta.for:4170 */
/*<       y2free=0.0 >*/
    xs2com_1.y2free = (float)0.;
/* SOURCE culverta.for:4172 */
/*<       iu=1 >*/
    iu = 1;
/* SOURCE culverta.for:4173 */
/*<       id=nbn >*/
    id = nbn;
/*      IF(TABTYP.EQ.14) THEN */
/*       Compute a 2-D table of type 14. */
/*        CALL DOTY14(STDOUT, EFLAG, TAB, TABTYP, HDATUM, ZDATUM, */
/*     A              DUP, DDN, NFAC, IU, ID, CULCLS, FTPTMP, NHU, HUVEC) */
/*        RETURN */
/*      ENDIF */
/*     FOR EACH UPSTREAM HEAD IN THE LIST, COMPUTE THE FREE FLOW AND */
/*     THE SUBMERGED FLOWS AT THE INDICATED PARTIAL FREE FLOW DROPS. */
/* SOURCE culverta.for:4183 */
/*<       ftpbase=ftptmp >*/
    ftpbase = ftptmp;
/* SOURCE culverta.for:4184 */
/*<       do2000i=1,nhu >*/
    feq_gen_i_d_1 = nhu;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culverta.for:4186 */
/*<       ftptmp=ftpbase >*/
	ftptmp = ftpbase;
/*       CLEAR THE FLAG USED TO LIMIT THE NUMBER OF ERROR MESSAGES */
/*       WRITTEN FOR INVALID HEADWATER RATIO TO ONE */
/* SOURCE culverta.for:4190 */
/*<       ratflg=0 >*/
	cdcom_1.ratflg = 0;
/*       CLEAR FLAG FOR HEAD TO EMBANKMENT WIDTH RATIO WARNING */
/*       MESSAGES */
/* SOURCE culverta.for:4195 */
/*<       hlflag=0 >*/
	embq_1.hlflag = 0;
/*       CLEAR FLAG FOR PIEZOMETRIC HEAD TO WEIR HEIGHT RATIO */
/* SOURCE culverta.for:4199 */
/*<       hpflag=0 >*/
	embq_1.hpflag = 0;
/* SOURCE culverta.for:4201 */
/*<       hup=huvec(i) >*/
	hup = huvec[feq_gen_i_d_ - 1];
/*       COMPUTE THE ELEVATION IN SECTION 1(THE APPROACH SECTION) */
/* SOURCE culverta.for:4205 */
/*<       z1=hdatum+hup >*/
	xs1com_1.z1 = static_cast<double>(hdatum) + hup;
/*       FIND THE ELEMENTS AT SECTION 1 */
/* SOURCE culverta.for:4209 */
/*<       y1=hdatum+hup-zb1 >*/
	xs1com_1.y1 = static_cast<double>(static_cast<double>(hdatum) + hup) - xs1com_1.zb1;
/* SOURCE culverta.for:4210 */
/*<       callxlktal(adrxs1,y1,a1,t1,dt1,j1,k1,dk1,bet1,dbet1,alp1,dalp1) >*/
	xlktal_(&xs1com_1.adrxs1, &xs1com_1.y1, &xs1com_1.a1, &xs1com_1.t1, &
		xs1com_1.dt1, &xs1com_1.j1, &xs1com_1.k1, &xs1com_1.dk1, &
		xs1com_1.bet1, &xs1com_1.dbet1, &xs1com_1.alp1, &
		xs1com_1.dalp1);
/* SOURCE culverta.for:4214 */
/*<       a1true=a1 >*/
	a1true = xs1com_1.a1;
/* SOURCE culverta.for:4215 */
/*<       alp1t=alp1 >*/
	alp1t = xs1com_1.alp1;
/* SOURCE culverta.for:4216 */
/*<       k1true=k1 >*/
	k1true = xs1com_1.k1;
/* SOURCE culverta.for:4217 */
/*<       z1=zb1+y1 >*/
	xs1com_1.z1 = static_cast<double>(xs1com_1.zb1) + xs1com_1.y1;
/* SOURCE culverta.for:4218 */
/*<       eu=z1 >*/
	eu = xs1com_1.z1;
/* SOURCE culverta.for:4219 */
/*<       z1true=z1 >*/
	z1true = xs1com_1.z1;
/* SOURCE culverta.for:4220 */
/*<       yuptru=y1 >*/
	xs1com_1.yuptru = xs1com_1.y1;
/*        WRITE(STDOUT,*) ' CULVERT: Z1=',Z1 */
/*       COMPUTE FREE FLOW OVER THE ROADWAY IF ANY.  NOTE THAT WE */
/*       ASSUME THAT CHANGES TO THE  VELOCITY HEAD OF APPROACH */
/*       FOR THE ROADWAY CAUSED BY FLOW THROUGH THE CULVERTS CAN */
/*       BE NEGLECTED.  THIS CAN BE MODIFIED BUT MUST WAIT DEVELOPMENT */
/*       OF A METHOD FOR DISTRIBUTING THE CULVERT FLOW ACROSS THE */
/*       APPROACH SECTION TO BE CONSISTENT WITH THE METHODS USED */
/*       TO COMPUTE THE FLOW OVER THE ROADWAY. */
/* SOURCE culverta.for:4233 */
/*<       if(z1true.gt.mincrs)then >*/
	if (z1true > embcom_1.mincrs) {
/*         THERE IS FLOW OVER THE ROADWAY. FIND ITS FREE FLOW VALUE AND */
/*         THE DOWNSTREAM ELEVATION AT THE FREE FLOW BOUNDARY */
/*         FIND THE HEAD ON THE ROADWAY */
/* SOURCE culverta.for:4239 */
/*<       hrdfu=hdatum+hup-mincrs >*/
	    hrdfu = static_cast<double>(static_cast<double>(hdatum) + hup) - embcom_1.mincrs;
/* SOURCE culverta.for:4241 */
/*<        >*/
	    frfemb_(&hrdfu, &embcom_1.mincrs, &embcom_1.plcwtb, &
		    embcom_1.glcwtb, &embcom_1.phcwtb, &embcom_1.ghcwtb, &
		    embcom_1.noff, embcom_1.off, embcom_1.crest, 
		    embcom_1.width, embcom_1.approc, embcmc_1.surf, &
		    embcom_1.rmffac, &embq_1.hlcrit, &embq_1.hlmax, &
		    embq_1.hlflag, &embq_1.hpflag, &zt, embcom_1.xrdfl, 
		    embcom_1.xrdfr, embcom_1.hrdfl, embcom_1.hrdfm, 
		    embcom_1.hrdfr, embcom_1.qrdfl, embcom_1.qrdfm, 
		    embcom_1.qrdfr, embcom_1.tothl, embcom_1.tothm, 
		    embcom_1.tothr, embcom_1.yfl, embcom_1.yfm, embcom_1.yfr, 
		    embcom_1.appl, embcom_1.appm, embcom_1.appr, embcom_1.wl, 
		    embcom_1.wm, embcom_1.wr, embcom_1.aell, embcom_1.aelm, 
		    embcom_1.aelr, &rdfcom_1.wfrdf, &rdfcom_1.mfrdf, &
		    rdfcom_1.efrdf, (ftnlen)8);
/* SOURCE culverta.for:4251 */
/*<        >*/
	    embsub_(&embcom_1.minloc, &embcom_1.mincrs, &embcom_1.noff, 
		    embcmc_1.surf, embcom_1.tothl, embcom_1.tothr, &hrdfu, &
		    hrdfd, &fd, &zsbrdf, (ftnlen)8);
/* SOURCE culverta.for:4254 */
/*<       fdrdw=fd >*/
	    fdrdw = fd;
/*         ZSBRDF GIVES THE TAILWATER ELEVATION WHICH MUST BE */
/*         REACHED FOR SUBMERGENCE OF THE FLOW OVER THE ROADWAY TO OCCUR. */
/* SOURCE culverta.for:4259 */
/*<       else >*/
	} else {
/* SOURCE culverta.for:4260 */
/*<       hrdfu=0.0 >*/
	    hrdfu = (float)0.;
/* SOURCE culverta.for:4261 */
/*<       wfrdf=0.0 >*/
	    rdfcom_1.wfrdf = (float)0.;
/* SOURCE culverta.for:4262 */
/*<       mfrdf=0.0 >*/
	    rdfcom_1.mfrdf = (float)0.;
/* SOURCE culverta.for:4263 */
/*<       efrdf=0.0 >*/
	    rdfcom_1.efrdf = (float)0.;
/* SOURCE culverta.for:4264 */
/*<       zsbrdf=mincrs >*/
	    zsbrdf = embcom_1.mincrs;
/* SOURCE culverta.for:4265 */
/*<       fdrdw=0.0 >*/
	    fdrdw = (float)0.;
/* SOURCE culverta.for:4266 */
/*<       endif >*/
	}
/*       SET THE GENERIC FLUX VALUES FOR THE ROAD */
/* SOURCE culverta.for:4270 */
/*<       wfrd=wfrdf >*/
	rdfcom_1.wfrd = rdfcom_1.wfrdf;
/* SOURCE culverta.for:4271 */
/*<       mfrd=mfrdf >*/
	rdfcom_1.mfrd = rdfcom_1.mfrdf;
/* SOURCE culverta.for:4272 */
/*<       efrd=efrdf >*/
	rdfcom_1.efrd = rdfcom_1.efrdf;
/*        WRITE(STDOUT,*) '  ' */
/*        WRITE(STDOUT,*) ' HUP=',HUP,' HRDFU=',HRDFU */
/*        WRITE(STDOUT,*) ' WFRDF=',WFRDF,' FDRDW=',FDRDW */
/*        WRITE(STDOUT,*) ' MFRDF=',MFRDF */
/*        WRITE(STDOUT,*) ' ZSBRDF=',ZSBRDF */
/*       Determine what the high head flow type will be.  If the */
/*       ratio of head on the culvert opening is less than 1.5 */
/*       the high-head flow type is computed at a head ratio */
/*       of 1.5.  Above 1.5, for rough pipe culverts, the head */
/*       can change the flow type.  For smooth pipe and for box */
/*       culverts(assumed to be smooth) the high-head type is */
/*       independent of the elevation of water at section 1. */
/* SOURCE culverta.for:4287 */
/*<       if(hhtype.eq.0)then >*/
	if (typlim_1.hhtype == 0) {
/*         Establish the high-head flow type at the high-head flow */
/*         limit */
/*          HP = 1.5001*DUP + ZB2 - HDATUM */
/* SOURCE culverta.for:4291 */
/*<       hp=(ty1htd+.1001)*dup+zb2-hdatum >*/
	    hp = static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>(culcom_1.ty1htd) + (float).1001)) * dup) + xs2com_1.zb2) - 
		    hdatum;
/* SOURCE culverta.for:4292 */
/*<        >*/
	    fhhtyp_(stdout, culcls, nfac, &hp, &hdatum, &dup, &iu, &id, &
		    rdfcom_1.wfrd, &y3limu, &xs3com_1.y3lty5, &
		    typlim_1.hhtype, &cct5, &yexit, (ftnlen)8);
/* SOURCE culverta.for:4297 */
/*<       if(hhtype.eq.5)then >*/
	    if (typlim_1.hhtype == 5) {
/*           Set the elevation at section 1 at the lower limit of */
/*           type 5 flow. */
/* SOURCE culverta.for:4300 */
/*<       z1ty5=hp+hdatum >*/
		xs1com_1.z1ty5 = static_cast<double>(hp) + hdatum;
/* SOURCE culverta.for:4301 */
/*<       cc5=cct5 >*/
		xs3com_1.cc5 = cct5;
/* SOURCE culverta.for:4302 */
/*<        >*/
		xlkt22_(&xs3com_1.adrxs3, &yexit, &xs3com_1.a3, &xs3com_1.t3, 
			&xs3com_1.dt3, &xs3com_1.j3, &xs3com_1.k3, &
			xs3com_1.dk3, &xs3com_1.bet3, &xs3com_1.dbet3, &
			xs3com_1.alp3, &xs3com_1.dalp3, &qc3);
/* SOURCE culverta.for:4307 */
/*<       bt3at5=bet3 >*/
		xs3com_1.bt3at5 = xs3com_1.bet3;
/* SOURCE culverta.for:4308 */
/*<       ap3at5=alp3 >*/
		xs3com_1.ap3at5 = xs3com_1.alp3;
/* SOURCE culverta.for:4309 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:4310 */
/*<       endif >*/
	}
/* SOURCE culverta.for:4312 */
/*<       if((hup+hdatum-zb2)/dup.ge.1.5.and.hhtype.eq.5)then >*/
	if (static_cast<double>((static_cast<double>(static_cast<double>(hup) + hdatum) - xs2com_1.zb2)) / dup >= (float)1.5 && 
		typlim_1.hhtype == 5) {
/*         Review high-head type. */
/* SOURCE culverta.for:4314 */
/*<        >*/
	    fhhtyp_(stdout, culcls, nfac, &hup, &hdatum, &dup, &iu, &id, &
		    rdfcom_1.wfrd, &y3limu, &xs3com_1.y3lty5, &
		    typlim_1.hhtype, &cct5, &yexit, (ftnlen)8);
/* SOURCE culverta.for:4319 */
/*<       endif >*/
	}
/*       COMPUTE FREE FLOW THROUGH THE CULVERT.  THE FREE DROP FOR */
/*       THE CULVERT MAY BE  INFLUENCED BY THE FLOW OVER THE ROADWAY. */
/*        WRITE(STDOUT,*) ' CULVERT: BEFORE CALL TO FRFCLV Z1=',Z1 */
/* SOURCE culverta.for:4327 */
/*<        >*/
	frfclv_(stdout, &hdatum, &zdatum, &hup, &dup, &ddn, &iu, &id, culcls, 
		eflag, &feq_gen_type_d_, &conflg, &expflg, &zsbrdf, &qfree, &freed, (
		ftnlen)8);
/* SOURCE culverta.for:4332 */
/*<       if(freed.lt.epsdif.and.expflg.ne.0)then >*/
	if (freed < epscom_1.epsdif && expflg != 0) {
/* SOURCE culverta.for:4333 */
/*<       write(stdout,101)freed,epsdif >*/
	    feq_gen_io_d__450.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__450);
	    do_fio(&feq_gen_c_d_1, (char *)&freed, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&epscom_1.epsdif, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culverta.for:4334 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE culverta.for:4335 */
/*<       write(*,*)'   Free drop too small' >*/
	    s_wsle(&feq_gen_io_d__451);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("   Free drop too small"), (ftnlen)22);
	    e_wsle();
/* SOURCE culverta.for:4336 */
/*<       return >*/
	    return 0;
/* SOURCE culverta.for:4337 */
/*<       endif >*/
	}
/*       Check for drop from section 1 to section 43. */
/* SOURCE culverta.for:4339 */
/*<       if(z1true-z43old.lt.epsdif)then >*/
	if (static_cast<double>(z1true) - x43com_1.z43old < epscom_1.epsdif) {
/* SOURCE culverta.for:4340 */
/*<        >*/
	    feq_gen_io_d__452.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__452);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:711* Drop from section 1 to "), (
		    ftnlen)34);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" section 43 < "), (ftnlen)14);
	    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&epscom_1.epsdif, (ftnlen)sizeof(
		    real));
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" not yet supported."), (ftnlen)19);
	    e_wsle();
/* SOURCE culverta.for:4342 */
/*<       write(*,*)'  Drop from section 1 to 43 too small.' >*/
	    s_wsle(&feq_gen_io_d__453);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>("  Drop from section 1 to 43 too small."), (
		    ftnlen)38);
	    e_wsle();
/* SOURCE culverta.for:4343 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE culverta.for:4344 */
/*<       return >*/
	    return 0;
/* SOURCE culverta.for:4345 */
/*<       endif >*/
	}
/* SOURCE culverta.for:4346 */
/*<       if(eflag.ne.0)goto2001 >*/
	if (*eflag != 0) {
	    goto L2001;
	}
/* SOURCE culverta.for:4348 */
/*<       if(type.ne.0)then >*/
	if (feq_gen_type_d_ != 0) {
/* SOURCE culverta.for:4349 */
/*<       fdrop=max(freed,fdrdw) >*/
	    fdrop = dmax(freed,fdrdw);
/* SOURCE culverta.for:4350 */
/*<       else >*/
	} else {
/* SOURCE culverta.for:4351 */
/*<       fdrop=freed >*/
	    fdrop = freed;
/* SOURCE culverta.for:4352 */
/*<       endif >*/
	}
/*       Do the energy check on the free flow. */
/* SOURCE culverta.for:4355 */
/*<       if(expflg.ne.0)then >*/
	if (expflg != 0) {
/*         Enable checking of energy losses involving section 2 */
/* SOURCE culverta.for:4357 */
/*<       if(type.eq.1.or.type.eq.2)then >*/
	    if (feq_gen_type_d_ == 1 || feq_gen_type_d_ == 2) {
/* SOURCE culverta.for:4358 */
/*<       chk23=1 >*/
		chk23 = 1;
/* SOURCE culverta.for:4359 */
/*<       else >*/
	    } else {
/* SOURCE culverta.for:4360 */
/*<       chk23=0 >*/
		chk23 = 0;
/* SOURCE culverta.for:4361 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:4362 */
/*<       if(alpha3.eq.0.0)then >*/
	    if (typtrn_1.alpha3 == (float)0.) {
/* SOURCE culverta.for:4363 */
/*<       de34=0.0 >*/
		de34 = (float)0.;
/* SOURCE culverta.for:4364 */
/*<       else >*/
	    } else {
/* SOURCE culverta.for:4365 */
/*<       de34=alpha3 >*/
		de34 = typtrn_1.alpha3;
/* SOURCE culverta.for:4366 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:4367 */
/*<       callchktel(stdout,chk23,de34,iflag,cl34,de14) >*/
	    chktel_(stdout, &chk23, &de34, &iflag, &cl34, &de14);
/* SOURCE culverta.for:4371 */
/*<       endif >*/
	}
/*       SAVE THE TYPE OF THE FREE FLOW THROUGH THE CULVERT, */
/*       THE CRITICAL DEPTH AT THE EXIT OF THE CULVERT, AND */
/*       THE PIEZOMETRIC DEPTH AT THE EXIT OF THE CULVERT. */
/*       NEEDED TO PROPERLY COMPUTE SUBMERGED FLOW. */
/* SOURCE culverta.for:4378 */
/*<       frtype=type >*/
	frtype = feq_gen_type_d_;
/* SOURCE culverta.for:4379 */
/*<       z3sav=z3 >*/
	z3sav = xs3com_1.z3;
/* SOURCE culverta.for:4380 */
/*<       z3psav=z3p >*/
	z3psav = xs3com_1.z3p;
/* SOURCE culverta.for:4381 */
/*<       z44sav=z44 >*/
	z44sav = x44com_1.z44;
/* SOURCE culverta.for:4382 */
/*<       z4sav=z4 >*/
	z4sav = xs4com_1.z4;
/* SOURCE culverta.for:4383 */
/*<       rdflow=wfrd >*/
	rdflow = rdfcom_1.wfrd;
/*       Save free flow condition at section 2. */
/*        Y2MAT(I,NFRAC) = Z2 - ZB2 */
/* SOURCE culverta.for:4386 */
/*<       y2mat(i,nfrac)=y2 >*/
	y2mat[feq_gen_i_d_ + nfrac * 151 - 152] = xs2com_1.y2;
/*       Clear the addresses for the temporary tables created */
/*       by QVSTW to make sure that FRFT7 cannot function */
/*       if they are not computed for the same upstream head. */
/* SOURCE culverta.for:4392 */
/*<       q3vsrd=0 >*/
	q3vsrd = 0;
/* SOURCE culverta.for:4393 */
/*<       y3vstw=0 >*/
	y3vstw = 0;
/* SOURCE culverta.for:4394 */
/*<       y2vsd=0 >*/
	y2vsd = 0;
/*       Compute the flow in the culvert as a function */
/*       of tailwater at section 43.  This must also be */
/*       done for free flow type 7. */
/* SOURCE culverta.for:4398 */
/*<        >*/
	qvstw_(stdout, &z1true, &iu, &id, &nfrac, &power, &zsbrdf, culcls, &
		a1true, &alp1t, &k1true, &hdatum, &zdatum, &frtype, eflag, &
		ftptmp, &q3vsrd, &y3vstw, &y2vsd, (ftnlen)8);
/* SOURCE culverta.for:4404 */
/*<       if(expflg.eq.0)then >*/
	if (expflg == 0) {
/*         CLEAR THE FLAG USED TO LIMIT THE NUMBER OF ERROR MESSAGES */
/*         WRITTEN FOR INVALID HEADWATER RATIO TO ONE */
/* SOURCE culverta.for:4409 */
/*<       ratflg=0 >*/
	    cdcom_1.ratflg = 0;
/*         COMPUTE TYPE 7 FREE FLOW HERE */
/*         OUTPUT SPECIAL WARNING MESSAGE. */
/* SOURCE culverta.for:4415 */
/*<       write(stdout,49) >*/
	    feq_gen_io_d__470.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__470);
	    e_wsfe();
/* SOURCE culverta.for:4417 */
/*<        >*/
	    frft7_(stdout, &z1true, &id, &zsbrdf, const_cast<char*>("FREE    "), &c_b137, &
		    q3vsrd, &y3vstw, &xs4com_1.z4, &qfree, &fdrop, (ftnlen)8);
/* SOURCE culverta.for:4422 */
/*<       if(eflag.ne.0)return >*/
	    if (*eflag != 0) {
		return 0;
	    }
/* SOURCE culverta.for:4423 */
/*<       frtype=7 >*/
	    frtype = 7;
/*         Do the energy check on the free flow. */
/*         Disable checking of energy losses involving section 2 */
/* SOURCE culverta.for:4426 */
/*<       chk23=0 >*/
	    chk23 = 0;
/* SOURCE culverta.for:4427 */
/*<       if(alpha3.eq.0.0)then >*/
	    if (typtrn_1.alpha3 == (float)0.) {
/* SOURCE culverta.for:4428 */
/*<       de34=0.0 >*/
		de34 = (float)0.;
/* SOURCE culverta.for:4429 */
/*<       else >*/
	    } else {
/* SOURCE culverta.for:4430 */
/*<       de34=alpha3 >*/
		de34 = typtrn_1.alpha3;
/* SOURCE culverta.for:4431 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:4432 */
/*<       callchktel(stdout,chk23,de34,iflag,cl34,de14) >*/
	    chktel_(stdout, &chk23, &de34, &iflag, &cl34, &de14);
/* SOURCE culverta.for:4437 */
/*<       else >*/
	} else {
/*         MAKE SURE THAT FREE FLOW IN THE CULVERT HAS NOT SUBMERGED */
/*         THE FLOW OVER THE ROADWAY FOR OTHER THAN TYPE = 0. */
/* SOURCE culverta.for:4441 */
/*<       if(type.ne.0)then >*/
	    if (feq_gen_type_d_ != 0) {
/* SOURCE culverta.for:4442 */
/*<       if(freed.lt.fdrdw)then >*/
		if (freed < fdrdw) {
/* SOURCE culverta.for:4443 */
/*<       write(stdout,89) >*/
		    feq_gen_io_d__471.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__471);
		    e_wsfe();
/* SOURCE culverta.for:4444 */
/*<       write(stdout,*)' FREED=',freed,' FDRDW=',fdrdw >*/
		    feq_gen_io_d__472.ciunit = *stdout;
		    s_wsle(&feq_gen_io_d__472);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FREED="), (ftnlen)7);
		    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&freed, (ftnlen)sizeof(real))
			    ;
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FDRDW="), (ftnlen)7);
		    do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&fdrdw, (ftnlen)sizeof(real))
			    ;
		    e_wsle();
/* SOURCE culverta.for:4445 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE culverta.for:4446 */
/*<       return >*/
		    return 0;
/* SOURCE culverta.for:4447 */
/*<       endif >*/
		}
/* SOURCE culverta.for:4448 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:4449 */
/*<       endif >*/
	}
/* SOURCE culverta.for:4451 */
/*<       if(frtype.eq.7)then >*/
	if (frtype == 7) {
/* SOURCE culverta.for:4452 */
/*<       write(stdout,41)hup,fdrop >*/
	    feq_gen_io_d__473.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__473);
	    do_fio(&feq_gen_c_d_1, (char *)&hup, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&fdrop, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culverta.for:4453 */
/*<       write(stdout,43) >*/
	    feq_gen_io_d__474.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__474);
	    e_wsfe();
/* SOURCE culverta.for:4454 */
/*<       h=hdatum >*/
	    feq_gen_h_d_ = hdatum;
/* SOURCE culverta.for:4455 */
/*<       if(wfrd.eq.0.0)then >*/
	    if (rdfcom_1.wfrd == (float)0.) {
/* SOURCE culverta.for:4456 */
/*<       write(cl34c,'(F5.2)')cl34 >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 5;
		feq_gen_ici_d_1.iciunit = cl34c;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(F5.2)");
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&cl34, (ftnlen)sizeof(real));
		e_wsfi();
/* SOURCE culverta.for:4457 */
/*<       write(char7,'(F7.3)')de34 >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 7;
		feq_gen_ici_d_1.iciunit = char7;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(F7.3)");
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&de34, (ftnlen)sizeof(real));
		e_wsfi();
/* SOURCE culverta.for:4458 */
/*<       else >*/
	    } else {
/* SOURCE culverta.for:4459 */
/*<       cl34c=' ----' >*/
		s_copy(cl34c, const_cast<char*>(" ----"), (ftnlen)5, (ftnlen)5);
/* SOURCE culverta.for:4460 */
/*<       char7=' ------' >*/
		s_copy(char7, const_cast<char*>(" ------"), (ftnlen)7, (ftnlen)7);
/* SOURCE culverta.for:4461 */
/*<       endif >*/
	    }
/*         Limit Z3 to the soffit at the outlet */
/* SOURCE culverta.for:4463 */
/*<       if(z3.gt.z3sof)then >*/
	    if (xs3com_1.z3 > z3sof) {
/* SOURCE culverta.for:4464 */
/*<       zt=z3sof >*/
		zt = z3sof;
/* SOURCE culverta.for:4465 */
/*<       else >*/
	    } else {
/* SOURCE culverta.for:4466 */
/*<       zt=z3 >*/
		zt = xs3com_1.z3;
/* SOURCE culverta.for:4467 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:4468 */
/*<       callvar_decimal(qfree,cqfree) >*/
	    feq_gen_var_decimal_d_(&qfree, cqfree, (ftnlen)7);
/* SOURCE culverta.for:4470 */
/*<       callvar_decimal(wfrd,cwfrd) >*/
	    feq_gen_var_decimal_d_(&rdfcom_1.wfrd, cwfrd, (ftnlen)7);
/* SOURCE culverta.for:4472 */
/*<       callvar_decimal(qfree+wfrd,cboth) >*/
	    feq_gen_r_d_1 = static_cast<double>(qfree) + rdfcom_1.wfrd;
	    feq_gen_var_decimal_d_(&feq_gen_r_d_1, cboth, (ftnlen)7);
/* SOURCE culverta.for:4475 */
/*<        >*/
	    feq_gen_io_d__480.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__480);
	    do_fio(&feq_gen_c_d_1, (char *)&c_b996, (ftnlen)sizeof(real));
	    feq_gen_r_d_1 = static_cast<double>(zt) - xs3com_1.zb3;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    feq_gen_r_d_2 = static_cast<double>(xs3com_1.z3p) - feq_gen_h_d_;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
	    feq_gen_r_d_3 = static_cast<double>(x44com_1.z44) - feq_gen_h_d_;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_3, (ftnlen)sizeof(real));
	    feq_gen_r_d_4 = static_cast<double>(xs4com_1.z4) - feq_gen_h_d_;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_4, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&fdrop, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, cqfree, (ftnlen)7);
	    do_fio(&feq_gen_c_d_1, cwfrd, (ftnlen)7);
	    do_fio(&feq_gen_c_d_1, cboth, (ftnlen)7);
	    do_fio(&feq_gen_c_d_1, cl34c, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, char7, (ftnlen)7);
	    do_fio(&feq_gen_c_d_1, (char *)&de14, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culverta.for:4478 */
/*<       else >*/
	} else {
/* SOURCE culverta.for:4479 */
/*<       write(stdout,41)hup,fdrop >*/
	    feq_gen_io_d__481.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__481);
	    do_fio(&feq_gen_c_d_1, (char *)&hup, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&fdrop, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culverta.for:4480 */
/*<       write(stdout,43) >*/
	    feq_gen_io_d__482.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__482);
	    e_wsfe();
/* SOURCE culverta.for:4481 */
/*<       h=hdatum >*/
	    feq_gen_h_d_ = hdatum;
/* SOURCE culverta.for:4483 */
/*<       if(wfrd.eq.0.0)then >*/
	    if (rdfcom_1.wfrd == (float)0.) {
/* SOURCE culverta.for:4484 */
/*<       write(cl34c,'(F5.2)')cl34 >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 5;
		feq_gen_ici_d_1.iciunit = cl34c;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(F5.2)");
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&cl34, (ftnlen)sizeof(real));
		e_wsfi();
/* SOURCE culverta.for:4485 */
/*<       write(char7,'(F7.3)')de34 >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 7;
		feq_gen_ici_d_1.iciunit = char7;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(F7.3)");
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&de34, (ftnlen)sizeof(real));
		e_wsfi();
/* SOURCE culverta.for:4486 */
/*<       else >*/
	    } else {
/* SOURCE culverta.for:4487 */
/*<       cl34c=' ----' >*/
		s_copy(cl34c, const_cast<char*>(" ----"), (ftnlen)5, (ftnlen)5);
/* SOURCE culverta.for:4488 */
/*<       char7=' ------' >*/
		s_copy(char7, const_cast<char*>(" ------"), (ftnlen)7, (ftnlen)7);
/* SOURCE culverta.for:4489 */
/*<       endif >*/
	    }
/*         Limit Z3 to the soffit at the outlet */
/* SOURCE culverta.for:4491 */
/*<       if(z3sav.gt.z3sof)then >*/
	    if (z3sav > z3sof) {
/* SOURCE culverta.for:4492 */
/*<       zt=z3sof >*/
		zt = z3sof;
/* SOURCE culverta.for:4493 */
/*<       else >*/
	    } else {
/* SOURCE culverta.for:4494 */
/*<       zt=z3sav >*/
		zt = z3sav;
/* SOURCE culverta.for:4495 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:4496 */
/*<       callvar_decimal(qfree,cqfree) >*/
	    feq_gen_var_decimal_d_(&qfree, cqfree, (ftnlen)7);
/* SOURCE culverta.for:4498 */
/*<       callvar_decimal(rdflow,cwfrd) >*/
	    feq_gen_var_decimal_d_(&rdflow, cwfrd, (ftnlen)7);
/* SOURCE culverta.for:4500 */
/*<       callvar_decimal(qfree+rdflow,cboth) >*/
	    feq_gen_r_d_1 = static_cast<double>(qfree) + rdflow;
	    feq_gen_var_decimal_d_(&feq_gen_r_d_1, cboth, (ftnlen)7);
/* SOURCE culverta.for:4502 */
/*<        >*/
	    feq_gen_io_d__483.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__483);
	    do_fio(&feq_gen_c_d_1, (char *)&c_b996, (ftnlen)sizeof(real));
	    feq_gen_r_d_1 = static_cast<double>(zt) - xs3com_1.zb3;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    feq_gen_r_d_2 = static_cast<double>(z3psav) - feq_gen_h_d_;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
	    feq_gen_r_d_3 = static_cast<double>(z44sav) - feq_gen_h_d_;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_3, (ftnlen)sizeof(real));
	    feq_gen_r_d_4 = static_cast<double>(z4sav) - feq_gen_h_d_;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_4, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&fdrop, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, cqfree, (ftnlen)7);
	    do_fio(&feq_gen_c_d_1, cwfrd, (ftnlen)7);
	    do_fio(&feq_gen_c_d_1, cboth, (ftnlen)7);
	    do_fio(&feq_gen_c_d_1, cl34c, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, char7, (ftnlen)7);
	    do_fio(&feq_gen_c_d_1, (char *)&de14, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE culverta.for:4505 */
/*<       endif >*/
	}
/*       Set the values for zero partial free drop.  Known to be zero */
/*       therefore not computed. */
/* SOURCE culverta.for:4508 */
/*<       qmat(i,1)=0.0 >*/
	qmat[feq_gen_i_d_ - 1] = (float)0.;
/*        Y2MAT(I,1) = Z1TRUE - ZB2 */
/* SOURCE culverta.for:4511 */
/*<       y2mat(i,1)=y2 >*/
	y2mat[feq_gen_i_d_ - 1] = xs2com_1.y2;
/*       Store the free flow value. Note there is a row for each */
/*       upstream head in QMAT.  Each column then contains the */
/*       flows at a constant free drop as the upstream head */
/*       varies.  Also only the non-zero upstream heads are */
/*       present in QMAT.  The flow at zero upstream head is */
/*       always zero! */
/* SOURCE culverta.for:4519 */
/*<       qmat(i,nfrac)=qfree+rdflow >*/
	qmat[feq_gen_i_d_ + nfrac * 151 - 152] = static_cast<double>(qfree) + rdflow;
/* SOURCE culverta.for:4520 */
/*<       fdvec(i)=fdrop >*/
	fdvec[feq_gen_i_d_ - 1] = fdrop;
/* SOURCE culverta.for:4521 */
/*<       qclv=qfree >*/
	qclv = qfree;
/* SOURCE culverta.for:4522 */
/*<       ddrop=0.0 >*/
	ddrop = (float)0.;
/* SOURCE culverta.for:4523 */
/*<       z4old=z4 >*/
	z4old = xs4com_1.z4;
/* SOURCE culverta.for:4524 */
/*<       qold=qfree >*/
	qold = qfree;
/*       FOR EACH OF THE PARTIAL FREE DROPS(EXCLUDING 0.0 AND 1.0) */
/*       COMPUTE THE FLOW OVER THE ROADWAY AND THE FLOW THROUGH THE */
/*       CULVERT. */
/* SOURCE culverta.for:4530 */
/*<       dq=0.0 >*/
	dq = (float)0.;
/*        WRITE(STDOUT,*) ' CULVRT: NFRAC=',NFRAC */
/* SOURCE culverta.for:4532 */
/*<       do500j=nfrac-1,2,-1 >*/
	for (j = nfrac - 1; j >= 2; --j) {
/*         CLEAR THE FLAG USED TO LIMIT THE NUMBER OF ERROR MESSAGES */
/*         WRITTEN FOR INVALID HEADWATER RATIO TO ONE */
/* SOURCE culverta.for:4537 */
/*<       ratflg=0 >*/
	    cdcom_1.ratflg = 0;
/* SOURCE culverta.for:4539 */
/*<       drop=fdrop*pfdvec(j) >*/
	    drop = static_cast<double>(fdrop) * pfdvec[j - 1];
/* SOURCE culverta.for:4540 */
/*<       ed=eu-fdrop*pfdvec(j) >*/
	    ed = static_cast<double>(eu) - static_cast<double>(fdrop) * pfdvec[j - 1];
/*         Compute change in section 4 elevation. */
/* SOURCE culverta.for:4543 */
/*<       dz4=ed-z4old >*/
	    dz4 = static_cast<double>(ed) - z4old;
/* SOURCE culverta.for:4544 */
/*<       z4old=ed >*/
	    z4old = ed;
/*          WRITE(STDOUT,*) ' DZ4=',DZ4 */
/*          WRITE(STDOUT,*) ' EU=',EU,' ED=',ED,' FDROP=',FDROP */
/*          WRITE(STDOUT,*) ' FRTYPE=',FRTYPE */
/*         Disable checking of energy losses involving section 2 */
/* SOURCE culverta.for:4554 */
/*<       chk23=0 >*/
	    chk23 = 0;
/* SOURCE culverta.for:4555 */
/*<        >*/
	    frft7_(stdout, &eu, &id, &zsbrdf, const_cast<char*>("SUBMERGE"), &dz4, &q3vsrd, &
		    y3vstw, &ed, &qclv, &ddrop, (ftnlen)8);
/* SOURCE culverta.for:4562 */
/*<       dq=qclv-qold >*/
	    dq = static_cast<double>(qclv) - qold;
/* SOURCE culverta.for:4563 */
/*<       qold=qclv >*/
	    qold = qclv;
/*          WRITE(STDOUT,*) ' DQ=',DQ */
/* SOURCE culverta.for:4565 */
/*<       if(dq.gt.0.0)dq=0.0 >*/
	    if (dq > (float)0.) {
		dq = (float)0.;
	    }
/* SOURCE culverta.for:4566 */
/*<       if(alpha3.eq.0.0)then >*/
	    if (typtrn_1.alpha3 == (float)0.) {
/* SOURCE culverta.for:4567 */
/*<       de34=0.0 >*/
		de34 = (float)0.;
/* SOURCE culverta.for:4568 */
/*<       else >*/
	    } else {
/* SOURCE culverta.for:4569 */
/*<       de34=alpha3 >*/
		de34 = typtrn_1.alpha3;
/* SOURCE culverta.for:4570 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:4571 */
/*<       callchktel(stdout,chk23,de34,iflag,cl34,de14) >*/
	    chktel_(stdout, &chk23, &de34, &iflag, &cl34, &de14);
/* SOURCE culverta.for:4576 */
/*<       qmat(i,j)=qclv+wfrd >*/
	    qmat[feq_gen_i_d_ + j * 151 - 152] = static_cast<double>(qclv) + rdfcom_1.wfrd;
/*         Find the depth at section 2.  Given in a 1-D table */
/*         as function of drop from section 1 to section 43. */
/* SOURCE culverta.for:4579 */
/*<       calllktab(y2vsd,z1true-z43,0,y2,ntab,dy2) >*/
	    feq_gen_r_d_1 = static_cast<double>(z1true) - x43com_1.z43;
	    lktab_(&y2vsd, &feq_gen_r_d_1, &feq_gen_c_d_0, &xs2com_1.y2, &ntab, &dy2);
/* SOURCE culverta.for:4583 */
/*<       y2mat(i,j)=y2 >*/
	    y2mat[feq_gen_i_d_ + j * 151 - 152] = xs2com_1.y2;
/* SOURCE culverta.for:4584 */
/*<       if(z3.gt.z3sof)then >*/
	    if (xs3com_1.z3 > z3sof) {
/* SOURCE culverta.for:4585 */
/*<       zt=z3sof >*/
		zt = z3sof;
/* SOURCE culverta.for:4586 */
/*<       else >*/
	    } else {
/* SOURCE culverta.for:4587 */
/*<       zt=z3 >*/
		zt = xs3com_1.z3;
/* SOURCE culverta.for:4588 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:4589 */
/*<       if(wfrd.eq.0.0)then >*/
	    if (rdfcom_1.wfrd == (float)0.) {
/* SOURCE culverta.for:4590 */
/*<       write(cl34c,'(F5.2)')cl34 >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 5;
		feq_gen_ici_d_1.iciunit = cl34c;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(F5.2)");
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&cl34, (ftnlen)sizeof(real));
		e_wsfi();
/* SOURCE culverta.for:4591 */
/*<       write(char7,'(F7.3)')de34 >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 7;
		feq_gen_ici_d_1.iciunit = char7;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(F7.3)");
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&de34, (ftnlen)sizeof(real));
		e_wsfi();
/* SOURCE culverta.for:4592 */
/*<       else >*/
	    } else {
/* SOURCE culverta.for:4593 */
/*<       cl34c=' ----' >*/
		s_copy(cl34c, const_cast<char*>(" ----"), (ftnlen)5, (ftnlen)5);
/* SOURCE culverta.for:4594 */
/*<       char7=' ------' >*/
		s_copy(char7, const_cast<char*>(" ------"), (ftnlen)7, (ftnlen)7);
/* SOURCE culverta.for:4595 */
/*<       endif >*/
	    }
/* SOURCE culverta.for:4596 */
/*<       callvar_decimal(qclv,cqclv) >*/
	    feq_gen_var_decimal_d_(&qclv, cqclv, (ftnlen)7);
/* SOURCE culverta.for:4598 */
/*<       callvar_decimal(wfrd,cwfrd) >*/
	    feq_gen_var_decimal_d_(&rdfcom_1.wfrd, cwfrd, (ftnlen)7);
/* SOURCE culverta.for:4600 */
/*<       callvar_decimal(qclv+wfrd,cboth) >*/
	    feq_gen_r_d_1 = static_cast<double>(qclv) + rdfcom_1.wfrd;
	    feq_gen_var_decimal_d_(&feq_gen_r_d_1, cboth, (ftnlen)7);
/* SOURCE culverta.for:4602 */
/*<        >*/
	    feq_gen_io_d__496.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__496);
	    do_fio(&feq_gen_c_d_1, (char *)&pfdvec[j - 1], (ftnlen)sizeof(real));
	    feq_gen_r_d_1 = static_cast<double>(zt) - xs3com_1.zb3;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    feq_gen_r_d_2 = static_cast<double>(xs3com_1.z3p) - feq_gen_h_d_;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
	    feq_gen_r_d_3 = static_cast<double>(x44com_1.z44) - feq_gen_h_d_;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_3, (ftnlen)sizeof(real));
	    feq_gen_r_d_4 = static_cast<double>(xs4com_1.z4) - feq_gen_h_d_;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_4, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&drop, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, cqclv, (ftnlen)7);
	    do_fio(&feq_gen_c_d_1, cwfrd, (ftnlen)7);
	    do_fio(&feq_gen_c_d_1, cboth, (ftnlen)7);
	    do_fio(&feq_gen_c_d_1, cl34c, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, char7, (ftnlen)7);
	    do_fio(&feq_gen_c_d_1, (char *)&de14, (ftnlen)sizeof(real));
	    e_wsfe();
/*          ENDIF */
/* SOURCE culverta.for:4607 */
/*<   500 continue >*/
/* L500: */
	}
/* SOURCE culverta.for:4608 */
/*<       write(stdout,44) >*/
	feq_gen_io_d__497.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__497);
	e_wsfe();
/* SOURCE culverta.for:4609 */
/*<       write(stdout,48)ddn >*/
	feq_gen_io_d__498.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__498);
	do_fio(&feq_gen_c_d_1, (char *)&ddn, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culverta.for:4610 */
/*<  2000 continue >*/
/* L2000: */
    }
/* SOURCE culverta.for:4611 */
/*<  2001 continue >*/
L2001:
/*     OUTPUT THE TABLE */
/* SOURCE culverta.for:4613 */
/*<       if(eflag.eq.0)then >*/
    if (*eflag == 0) {
/* SOURCE culverta.for:4614 */
/*<       zrhufd=0.0 >*/
	zrhufd = (float)0.;
/* SOURCE culverta.for:4615 */
/*<        >*/
	feq_gen_r_d_1 = static_cast<double>(hdatum) + zdatum;
	twdout_(stdout, stdtab, &tab, label, &nhu, &nfrac, huvec, fdvec, 
		pfdvec, qmat, &feq_gen_r_d_1, &tabtyp, const_cast<char*>(" CULVERT"), &zrhufd, zone, 
		hgrid, vdatum, unitsys, basis, &easting, &northing, eflag, (
		ftnlen)50, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (
		ftnlen)8, (ftnlen)8);
/* SOURCE culverta.for:4623 */
/*<       if(twod_cubic_out.eq.'YES')then >*/
	if (s_cmp(upgrdc_1.feq_gen_twod_cubic_out_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3) == 
		0) {
/* SOURCE culverta.for:4624 */
/*<       verbose=1 >*/
	    verbose = 1;
/* SOURCE culverta.for:4625 */
/*<        >*/
	    feq_gen_r_d_1 = static_cast<double>(hdatum) + zdatum;
	    twodfit_(stdout, &tab, &nhu, &nfrac, huvec, fdvec, pfdvec, qmat, &
		    feq_gen_r_d_1, &tabtyp, const_cast<char*>(" CULVERT"), &zrhufd, &verbose, ftp, eflag, 
		    &ftpup, (ftnlen)8);
/* SOURCE culverta.for:4631 */
/*<       endif >*/
	}
/* SOURCE culverta.for:4633 */
/*<       if(putq.gt.0)then >*/
	if (putget_1.putq > 0) {
/* SOURCE culverta.for:4634 */
/*<        >*/
	    feq_gen_r_d_1 = static_cast<double>(hdatum) + zdatum;
	    twod13put_(stdout, &putget_1.putq, &nhu, &nfrac, huvec, fdvec, 
		    pfdvec, qmat, &feq_gen_r_d_1, &tabtyp, ftp, eflag);
/* SOURCE culverta.for:4639 */
/*<       endif >*/
	}
/* SOURCE culverta.for:4640 */
/*<       if(puty2.gt.0)then >*/
	if (putget_1.puty2 > 0) {
/*          DO 5000 I=1,NHU */
/*            WRITE(STDOUT,'(I5,25F10.3)') I, (Y2MAT(I,J), J=1,NFRAC) */
/* 5000      CONTINUE */
/* SOURCE culverta.for:4645 */
/*<        >*/
	    feq_gen_r_d_1 = static_cast<double>(hdatum) + zdatum;
	    twod13put_(stdout, &putget_1.puty2, &nhu, &nfrac, huvec, fdvec, 
		    pfdvec, y2mat, &feq_gen_r_d_1, &tabtyp, ftp, eflag);
/*          NHU = 0 */
/*          NFRAC =0 */
/*          HUVEC = 0.0 */
/*          FDROP = 0.0 */
/*          PFDVEC = 0.0 */
/*          Y2MAT = 0.0 */
/*          HDATUM = 0.0 */
/*          TABTYP = 0 */
/*          CALL TWOD13GET */
/*     I                  (STDOUT, */
/*     O                   PUTY2, NHU, NFRAC, HUVEC, FDVEC, */
/*     O                   PFDVEC, Y2MAT, HDATUM, TABTYP, */
/*     O                   EFLAG) */
/*        CALL TWDOUT */
/*     I             (STDOUT, STDOUT, PUTY2, LABEL, NHU, NFRAC, HUVEC, */
/*     I              FDVEC, PFDVEC, Y2MAT, HDATUM, */
/*     I              TABTYP,' CULVERT', */
/*     O              EFLAG) */
/* SOURCE culverta.for:4668 */
/*<       endif >*/
	}
/* SOURCE culverta.for:4670 */
/*<       endif >*/
    }
/* SOURCE culverta.for:4671 */
/*<       return >*/
    return 0;
/* SOURCE culverta.for:4672 */
/*<   991 continue >*/
L991:
/* SOURCE culverta.for:4673 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__502.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__502);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE culverta.for:4674 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__503.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__503);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE culverta.for:4675 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culverta.for:4676 */
/*<       end >*/
    return 0;
} /* culvrt_ */

#undef pgover
#undef rtmp
#undef itab
#undef ftab


#ifdef __cplusplus
	}
#endif
