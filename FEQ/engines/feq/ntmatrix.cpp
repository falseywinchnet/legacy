/* ntmatrix.f -- translated by f2c (version 20240504).
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

/* COMMON tamcom_ is declared in common.hpp. */

#define tamcom_1 tamcom_

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* COMMON miscon_ is declared in common.hpp. */

#define miscon_1 miscon_

/* COMMON bnelem_ is declared in common.hpp. */

#define bnelem_1 bnelem_

/* COMMON bnothr_ is declared in common.hpp. */

#define bnothr_1 bnothr_

/* COMMON bnothc_ is declared in common.hpp. */

#define bnothc_1 bnothc_

/* COMMON enelem_ is declared in common.hpp. */

#define enelem_1 enelem_

/* COMMON enothr_ is declared in common.hpp. */

#define enothr_1 enothr_

/* COMMON enothc_ is declared in common.hpp. */

#define enothc_1 enothc_

/* COMMON matcom_ is declared in common.hpp. */

#define matcom_1 matcom_

/* COMMON matcom2_ is declared in common.hpp. */

#define matcom2_1 matcom2_

/* COMMON xscom_ is declared in common.hpp. */

#define xscom_1 xscom_

/* COMMON bnrslt_ is declared in common.hpp. */

#define bnrslt_1 bnrslt_

/* COMMON enrslt_ is declared in common.hpp. */

#define enrslt_1 enrslt_

/* COMMON bnpond_ is declared in common.hpp. */

#define bnpond_1 bnpond_

/* COMMON nzdcom_ is declared in common.hpp. */

#define nzdcom_1 nzdcom_

/* Table of constant values */

static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_0 = 0;
static integer feq_gen_c_d_3 = 3;

/* Routines used to create and sovle the network matrix, check convergence, */
/* update varible sets, etc */




/* SOURCE ntmatrix.for:8 */
/*<        >*/
/* Subroutine */ int bdyflw_(integer *bdynum, doublereal *dt, integer *feq_storage_exnodt,
	 integer *nex, real *feq_storage_qe1, real *feq_storage_qe2, real *wt, integer *feq_storage_bdyvec, 
	doublereal *bni, doublereal *bnq, doublereal *tai, doublereal *taq, 
	doublereal *taqbn, doublereal *wsi, doublereal *wsq)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_, it;
    // TEMP = -node_sign * (old_flow + weight * (new_flow - old_flow)).
    // Original 0x474eab-0x474ee8 accumulates without a binary32 TEMP store.
    doublereal temp;
    doublereal sumneg, sumpos;

/*     + + + PURPOSE + + + */
/*     Compute the cumulative flow into(BNI) and out of(BNQ) */
/*     the system.  Note that change in direction of flow is */
/*     included so that flow reversal will be handled reasonably. */
/*     That is, as the run progresses both BNI and BNQ can only */
/*     become larger or stay the same. */
/* SOURCE ntmatrix.for:20 */
/*<       implicitnone >*/
/* INCLUDE ntmatrix.for:22 */
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
/* INCLUDE ntmatrix.for:23 */
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
/* INCLUDE ntmatrix.for:24 */
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
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntmatrix.for:27 */
/*<       integerbdynum,nex >*/
/* SOURCE ntmatrix.for:28 */
/*<       integerbdyvec(nex),exnodt(9,nex) >*/
/* SOURCE ntmatrix.for:29 */
/*<       realqe1(nex),qe2(nex),wt >*/
/* SOURCE ntmatrix.for:30 */
/*<       real*8dt,bni,bnq,tai,taq,taqbn,wsi,wsq >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     BDYNUM - number of boundary nodes in the model */
/*     DT     - time step in seconds */
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
/*     QE1    - flow at exterior nodes at start of time step */
/*     QE2    - flow at exterior nodes at end of time step */
/*     TUNIT_KNT - number of trib-area units */
/*     TAM_GROSS_INFLOW - inflow to each trib-area unit */
/*     WT     - weight factor for approximating time integrals */
/*     BDYVEC - node numbers for the boundary nodes in the model */
/*     BNI  - total volume of inflow to the model to current time */
/*     BNQ - total volume of outflow from the model to current time */
/*     TAI - total inflow to tributary area */
/*     TAQ - total outflow from tributary area into branches */
/*           and LPR's exclusive of boundary nodes */
/*     TAQBN - total outflow to boundary nodes. */
/*     WSI   -total of inflow to water surface from rainfall */
/*     WSQ   -total of outflow from water surface from evaporation */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ntmatrix.for:65 */
/*<       integeri,it >*/
/* SOURCE ntmatrix.for:66 */
/*<       realtemp >*/
/* SOURCE ntmatrix.for:67 */
/*<       real*8sumneg,sumpos >*/
/*     + + + INTRINSICS + + + */
/* SOURCE ntmatrix.for:70 */
/*<       intrinsicfloat >*/
/* *********************************************************************** */
/*     APPROXIMATE THE INFLOW AND OUTFLOW INTEGRAL ACCOUNTING */
/*     FOR ANY FLOW REVERSALS AT THE BOUNDARIES. */
/* SOURCE ntmatrix.for:75 */
/*<       sumpos=0.d0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> bdyvec(feq_storage_bdyvec, 1);

    feq::IndexedPointer<real> qe2(feq_storage_qe2, 1);

    feq::IndexedPointer<real> qe1(feq_storage_qe1, 1);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    /* Function Body */
    sumpos = 0.;
/* SOURCE ntmatrix.for:76 */
/*<       sumneg=0.d0 >*/
    sumneg = 0.;
/* SOURCE ntmatrix.for:78 */
/*<       do206i=1,bdynum >*/
    feq_gen_i_d_1 = *bdynum;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ntmatrix.for:79 */
/*<       it=bdyvec(i) >*/
	it = bdyvec[feq_gen_i_d_];
/* SOURCE ntmatrix.for:80 */
/*<       temp=(qe1(it)+wt*(qe2(it)-qe1(it))) >*/
	temp = static_cast<double>(qe1[it]) + static_cast<double>(*wt) * (static_cast<double>(qe2[it]) - qe1[it]);
/*       TEMP*(SIGN OF THE NODE) < 0 INDICATES INFLOW TO THE */
/*       SYSTEM.  THEREFORE SWITCH SIGNS TO BE THE SAME AS THE */
/*       SIGN FOR THE LATERAL INFLOW SIGN CONVENTION. */
/* SOURCE ntmatrix.for:86 */
/*<       temp=-float(exnodt(1,it))*temp >*/
	temp = static_cast<double>(-((real) exnodt[it * 9 + 1])) * temp;
/* SOURCE ntmatrix.for:87 */
/*<       if(temp.gt.0.0)then >*/
	if (temp > (float)0.) {
/* SOURCE ntmatrix.for:88 */
/*<       sumpos=sumpos+temp >*/
	    sumpos += temp;
/* SOURCE ntmatrix.for:89 */
/*<       else >*/
	} else {
/* SOURCE ntmatrix.for:90 */
/*<       sumneg=sumneg+temp >*/
	    sumneg += temp;
/* SOURCE ntmatrix.for:91 */
/*<       endif >*/
	}
/* SOURCE ntmatrix.for:92 */
/*<   206 continue >*/
/* L206: */
    }
/*     BNI AND BNQ MUST BE > 0. CHANGE SIGN OF SUMNEG */
/* SOURCE ntmatrix.for:96 */
/*<       bni=bni+dt*sumpos >*/
    *bni += *dt * sumpos;
/* SOURCE ntmatrix.for:97 */
/*<       bnq=bnq-dt*sumneg >*/
    *bnq -= *dt * sumneg;
/* SOURCE ntmatrix.for:98 */
/*<       tai=tai+dt*l_tai >*/
    *tai += *dt * tamcom_1.feq_gen_l_tai_d_;
/* SOURCE ntmatrix.for:99 */
/*<       taq=taq+dt*l_taq >*/
    *taq += *dt * tamcom_1.feq_gen_l_taq_d_;
/* SOURCE ntmatrix.for:100 */
/*<       taqbn=taqbn+dt*l_taqbn >*/
    *taqbn += *dt * tamcom_1.feq_gen_l_taqbn_d_;
/* SOURCE ntmatrix.for:101 */
/*<       wsi=wsi+dt*l_wsi >*/
    *wsi += *dt * tamcom_1.feq_gen_l_wsi_d_;
/* SOURCE ntmatrix.for:102 */
/*<       wsq=wsq+dt*l_wsq >*/
    *wsq += *dt * tamcom_1.feq_gen_l_wsq_d_;
/* SOURCE ntmatrix.for:104 */
/*<       return >*/
    return 0;
/* SOURCE ntmatrix.for:105 */
/*<       end >*/
} /* bdyflw_ */




/* SOURCE ntmatrix.for:109 */
/*<        >*/
/* Subroutine */ int cmpcor_(integer *nbra, integer *nex, integer *feq_storage_brpt, 
	integer *feq_storage_exnodt, real *qeps, real *epssys, real *epssy2, real *abstol,
	 real *mxre, integer *bmxre, integer *nmxre, integer *feq_gen_ivar_mxre_d_, 
	integer *knt, integer *knta, integer *feq_gen_bnode_max_d_)
{
    // Relative corrections B=abs(DQ)/(abs(Q)+QEPS), or abs(DY*T/A),
    // remain wider through comparisons against the stored REAL maximum.
    // Original 0x4754de-0x47550d and 0x475599-0x4755ce.
    // Rounding B before comparing can select a different reported node.

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2, feq_gen_i_d_3;
    doublereal feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3;
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5];
    static real equiv_0[1];

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer e_wsle();

    /* Local variables */
    doublereal b;
    integer feq_gen_i_d_;
    doublereal t;
    integer nb;
    doublereal dq, dy;
    integer nad, fna, lna;
    doublereal div;
    integer ninc;
#define idum (feq::BitView<integer>(equiv_0, sizeof(equiv_0)))
    integer ivar, iknt;
#define rdum (equiv_0)
    doublereal temp;
    integer ndbas, iknta, snode;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__15 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Compute corrections to current estimate */
/* SOURCE ntmatrix.for:118 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntmatrix.for:121 */
/*<       integerbmxre,knt,knta,nbra,nex,nmxre,bnode_max,ivar_mxre >*/
/* SOURCE ntmatrix.for:123 */
/*<       integerbrpt(8,nbra),exnodt(9,nex) >*/
/* SOURCE ntmatrix.for:124 */
/*<       realabstol,epssy2,epssys,mxre,qeps >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NBRA   - number of branches in the model */
/*     NEX    - number of exterior nodes in the model */
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
/*     QEPS   - value of flow to prevent zero divide when computing */
/*               relative correction */
/*     EPSSYS - primary convergence limit */
/*     EPSSY2 - secondary convergence limit */
/*     ABSTOL - Absolute tolerance in depth that overrides relative */
/*               change in declaring convergence. */
/*     MXRE   - maximum relative correction value for any variable */
/*     BMXRE  - branch number for maximum relative correction */
/*     NMXRE  - node number at which maximum relative correction occurs */
/*     IVAR_MXRE -internal variable number at point of max relative error (correction) */
/*     KNT    - number of variables that violate the primary convergence */
/*               tolerance */
/*     KNTA   - number of variables that violate the secondary */
/*               convergence tolerance */
/*     BNODE_MAX - internal branch node number of maximum relative */
/*                 correction. */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntmatrix.for:171 */
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
/* INCLUDE ntmatrix.for:172 */
/*     Miscellaneous control parameters */
/* SOURCE misccon.cmn:3 */
/*<       integerpagesp,pndflg >*/
/* SOURCE misccon.cmn:5 */
/*<        >*/
/* SOURCE misccon.cmn:8 */
/*<        >*/
/* INCLUDE ntmatrix.for:173 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE ntmatrix.for:174 */
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
/* INCLUDE ntmatrix.for:175 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE ntmatrix.for:176 */
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
/* INCLUDE ntmatrix.for:177 */
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
/* INCLUDE ntmatrix.for:178 */
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
/* SOURCE ntmatrix.for:181 */
/*<       integerfna,i,idum,iknt,iknta,ivar,lna,nad,nb,ndbas,ninc,snode >*/
/* SOURCE ntmatrix.for:183 */
/*<       realb,div,dq,dy,rdum,t,temp >*/
/*     + + + EQUIVALENCES + + + */
/* SOURCE ntmatrix.for:186 */
/*<       equivalence(idum,rdum) >*/
/*     + + + INTRINSICS + + + */
/* SOURCE ntmatrix.for:189 */
/*<       intrinsicabs,max >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ntmatrix.for:192 */
/*<       charactergetusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntmatrix.for:195 */
/*<       externalgetusn >*/
/* *********************************************************************** */
/* SOURCE ntmatrix.for:197 */
/*<       iknt=0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    /* Function Body */
    iknt = 0;
/* SOURCE ntmatrix.for:198 */
/*<       iknta=0 >*/
    iknta = 0;
/*     RHS NOW CONTAINS CHANGES AT ALL NODES */
/* SOURCE ntmatrix.for:201 */
/*<       mxre=0.0 >*/
    *mxre = (float)0.;
/* SOURCE ntmatrix.for:202 */
/*<       bmxre=0 >*/
    *bmxre = 0;
/* SOURCE ntmatrix.for:203 */
/*<       nmxre=0 >*/
    *nmxre = 0;
/* SOURCE ntmatrix.for:205 */
/*<       do50i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ntmatrix.for:206 */
/*<       if(exnodt(3,i).gt.0)then >*/
	if (exnodt[feq_gen_i_d_ * 9 + 3] > 0) {
/*         EXTERIOR NODES ON BRANCHES NEED NOT BE DONE */
/* SOURCE ntmatrix.for:208 */
/*<       else >*/
	} else {
/* SOURCE ntmatrix.for:209 */
/*<       ivar=exnodt(5,i)+1 >*/
	    ivar = exnodt[feq_gen_i_d_ * 9 + 5] + 1;
/* SOURCE ntmatrix.for:210 */
/*<       temp=rhs(ivar) >*/
	    temp = matcom_1.rhs[ivar - 1];
/* SOURCE ntmatrix.for:211 */
/*<       if(exnodt(3,i).lt.0)then >*/
	    if (exnodt[feq_gen_i_d_ * 9 + 3] < 0) {
/*           RESERVOIR HERE. TE2(I) CONTAINS THE CURRENT SURFACE */
/*           AREA OF THE RESERVOIR. AE2(I) CONTAINS NEGATIVE OF CURRENT */
/*           VOLUME. */
/* SOURCE ntmatrix.for:216 */
/*<       if(abs(temp).lt.reseps)then >*/
		if (dabs(temp) < miscon_1.reseps) {
/* SOURCE ntmatrix.for:217 */
/*<       b=0.0 >*/
		    b = (float)0.;
/* SOURCE ntmatrix.for:218 */
/*<       else >*/
		} else {
/* SOURCE ntmatrix.for:219 */
/*<       rdum=te2(i) >*/
		    *rdum = enelem_1.te2[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:220 */
/*<       div=max(abs(ae2(i)),lprdy*rdum,lprmin) >*/
/* Computing MAX */
		    feq_gen_r_d_2 = (feq_gen_r_d_1 = enelem_1.ae2[feq_gen_i_d_ - 1], dabs(feq_gen_r_d_1)), feq_gen_r_d_3 = 
			    static_cast<double>(miscon_1.lprdy) * *rdum, feq_gen_r_d_2 = max(feq_gen_r_d_2,feq_gen_r_d_3);
		    div = dmax(feq_gen_r_d_2,miscon_1.lprmin);
/* SOURCE ntmatrix.for:221 */
/*<       b=3.*abs(temp*rdum/div) >*/
		    b = (feq_gen_r_d_1 = static_cast<double>(static_cast<double>(temp) * *rdum) / div, dabs(feq_gen_r_d_1)) * (float)3.;
/* SOURCE ntmatrix.for:222 */
/*<       endif >*/
		}
/* SOURCE ntmatrix.for:223 */
/*<       else >*/
	    } else {
/* SOURCE ntmatrix.for:224 */
/*<       if(ye2(i).le.0.0)then >*/
		if (enelem_1.ye2[feq_gen_i_d_ - 1] <= (float)0.) {
/* SOURCE ntmatrix.for:225 */
/*<        >*/
		    feq_gen_io_d__15.ciunit = feq_gen_stdun_com_d_1.std6;
		    s_wsle(&feq_gen_io_d__15);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *WRN:51* YE2(I) <= 0.0 in CMPCOR \
at EXNODE="), (ftnlen)44);
		    getusn_(feq_gen_ch_d_2, (ftnlen)5, &feq_gen_i_d_);
		    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		    e_wsle();
/* SOURCE ntmatrix.for:228 */
/*<       if(abs(temp).lt.0.01)then >*/
		    if (dabs(temp) < (float).01) {
/* SOURCE ntmatrix.for:229 */
/*<       b=0.0 >*/
			b = (float)0.;
/* SOURCE ntmatrix.for:230 */
/*<       else >*/
		    } else {
/* SOURCE ntmatrix.for:231 */
/*<       b=1.0 >*/
			b = (float)1.;
/* SOURCE ntmatrix.for:232 */
/*<       endif >*/
		    }
/* SOURCE ntmatrix.for:233 */
/*<       else >*/
		} else {
/* SOURCE ntmatrix.for:234 */
/*<       b=abs(temp)/ye2(i) >*/
		    b = dabs(temp) / enelem_1.ye2[feq_gen_i_d_ - 1];
/*          if(ivar.eq.3062) then */
/*            write(std6,54) b, ye2(i), temp */
/* 54    format(' Debug: b=',1pe12.5,' ye22(i)=',1pe12.5,' temp=',1pe12.5) */
/*          endif */
/* SOURCE ntmatrix.for:240 */
/*<       endif >*/
		}
/* SOURCE ntmatrix.for:241 */
/*<       endif >*/
	    }
/* SOURCE ntmatrix.for:242 */
/*<       if(b.ge.mxre)then >*/
	    if (b >= *mxre) {
/* SOURCE ntmatrix.for:243 */
/*<       mxre=b >*/
		*mxre = b;
/* SOURCE ntmatrix.for:244 */
/*<       bmxre=0 >*/
		*bmxre = 0;
/* SOURCE ntmatrix.for:245 */
/*<       nmxre=-i >*/
		*nmxre = -feq_gen_i_d_;
/* SOURCE ntmatrix.for:246 */
/*<       ivar_mxre=ivar >*/
		*feq_gen_ivar_mxre_d_ = ivar;
/* SOURCE ntmatrix.for:247 */
/*<       endif >*/
	    }
/* SOURCE ntmatrix.for:248 */
/*<       if(b.gt.epssys)then >*/
	    if (b > *epssys) {
/* SOURCE ntmatrix.for:249 */
/*<       iknt=iknt+1 >*/
		++iknt;
/* SOURCE ntmatrix.for:250 */
/*<       if(b.gt.epssy2)then >*/
		if (b > *epssy2) {
/* SOURCE ntmatrix.for:251 */
/*<       iknta=iknta+1 >*/
		    ++iknta;
/* SOURCE ntmatrix.for:252 */
/*<       endif >*/
		}
/* SOURCE ntmatrix.for:253 */
/*<       hi_iq_ns_state(ivar)=0 >*/
		matcom_1.feq_gen_hi_iq_ns_state_d_[ivar - 1] = 0;
/* SOURCE ntmatrix.for:254 */
/*<       else >*/
	    } else {
/* SOURCE ntmatrix.for:255 */
/*<       hi_iq_ns_state(ivar)=1 >*/
		matcom_1.feq_gen_hi_iq_ns_state_d_[ivar - 1] = 1;
/* SOURCE ntmatrix.for:256 */
/*<       endif >*/
	    }
/* SOURCE ntmatrix.for:257 */
/*<       encory(i)=hi_iq_ns_fac(ivar)*temp >*/
	    enothr_1.encory[feq_gen_i_d_ - 1] = static_cast<double>(matcom_1.feq_gen_hi_iq_ns_fac_d_[ivar - 1]) * 
		    temp;
/* SOURCE ntmatrix.for:260 */
/*<       temp=rhs(ivar-1) >*/
	    temp = matcom_1.rhs[ivar - 2];
/* SOURCE ntmatrix.for:262 */
/*<       b=abs(temp/(abs(qe2(i))+qeps)) >*/
	    b = (feq_gen_r_d_2 = temp / ((feq_gen_r_d_1 = enelem_1.qe2[feq_gen_i_d_ - 1], dabs(feq_gen_r_d_1)) + *
		    qeps), dabs(feq_gen_r_d_2));
/*          if(ivar-1.eq.3061) then */
/*            write(std6,52) b, qe2(i), temp */
/* 52    format(' Debug: b=',1pe12.5,' qe2(i)=',1pe12.5,' temp=',1pe12.5) */
/*          endif */
/* SOURCE ntmatrix.for:268 */
/*<       if(b.ge.mxre)then >*/
	    if (b >= *mxre) {
/* SOURCE ntmatrix.for:269 */
/*<       mxre=b >*/
		*mxre = b;
/* SOURCE ntmatrix.for:270 */
/*<       bmxre=0 >*/
		*bmxre = 0;
/* SOURCE ntmatrix.for:271 */
/*<       nmxre=i >*/
		*nmxre = feq_gen_i_d_;
/* SOURCE ntmatrix.for:272 */
/*<       ivar_mxre=ivar-1 >*/
		*feq_gen_ivar_mxre_d_ = ivar - 1;
/* SOURCE ntmatrix.for:273 */
/*<       endif >*/
	    }
/* SOURCE ntmatrix.for:274 */
/*<       if(b.gt.epssys)then >*/
	    if (b > *epssys) {
/* SOURCE ntmatrix.for:275 */
/*<       iknt=iknt+1 >*/
		++iknt;
/* SOURCE ntmatrix.for:276 */
/*<       if(b.gt.epssy2)then >*/
		if (b > *epssy2) {
/* SOURCE ntmatrix.for:277 */
/*<       iknta=iknta+1 >*/
		    ++iknta;
/* SOURCE ntmatrix.for:278 */
/*<       endif >*/
		}
/* SOURCE ntmatrix.for:279 */
/*<       hi_iq_ns_state(ivar-1)=0 >*/
		matcom_1.feq_gen_hi_iq_ns_state_d_[ivar - 2] = 0;
/* SOURCE ntmatrix.for:280 */
/*<       else >*/
	    } else {
/* SOURCE ntmatrix.for:281 */
/*<       hi_iq_ns_state(ivar-1)=1 >*/
		matcom_1.feq_gen_hi_iq_ns_state_d_[ivar - 2] = 1;
/* SOURCE ntmatrix.for:282 */
/*<       endif >*/
	    }
/* SOURCE ntmatrix.for:284 */
/*<       encorq(i)=hi_iq_ns_fac(ivar-1)*temp >*/
	    enothr_1.encorq[feq_gen_i_d_ - 1] = static_cast<double>(matcom_1.feq_gen_hi_iq_ns_fac_d_[ivar - 2]) * 
		    temp;
/* SOURCE ntmatrix.for:285 */
/*<       endif >*/
	}
/* SOURCE ntmatrix.for:286 */
/*<    50 continue >*/
/* L50: */
    }
/*     DO THE NODES ON BRANCHES */
/* SOURCE ntmatrix.for:290 */
/*<       do100nb=1,nbra >*/
    feq_gen_i_d_1 = *nbra;
    for (nb = 1; nb <= feq_gen_i_d_1; ++nb) {
/* SOURCE ntmatrix.for:291 */
/*<       ivar=brpt(7,nb) >*/
	ivar = brpt[(nb << 3) + 7];
/* SOURCE ntmatrix.for:292 */
/*<       snode=brpt(1,nb) >*/
	snode = brpt[(nb << 3) + 1];
/* SOURCE ntmatrix.for:293 */
/*<       if(ivar.gt.0)then >*/
	if (ivar > 0) {
/* SOURCE ntmatrix.for:294 */
/*<       ninc=1 >*/
	    ninc = 1;
/* SOURCE ntmatrix.for:295 */
/*<       fna=brpt(3,nb) >*/
	    fna = brpt[(nb << 3) + 3];
/* SOURCE ntmatrix.for:296 */
/*<       lna=brpt(4,nb) >*/
	    lna = brpt[(nb << 3) + 4];
/* SOURCE ntmatrix.for:297 */
/*<       ndbas=fna >*/
	    ndbas = fna;
/* SOURCE ntmatrix.for:298 */
/*<       else >*/
	} else {
/* SOURCE ntmatrix.for:299 */
/*<       ninc=-1 >*/
	    ninc = -1;
/* SOURCE ntmatrix.for:300 */
/*<       fna=brpt(4,nb) >*/
	    fna = brpt[(nb << 3) + 4];
/* SOURCE ntmatrix.for:301 */
/*<       lna=brpt(3,nb) >*/
	    lna = brpt[(nb << 3) + 3];
/* SOURCE ntmatrix.for:302 */
/*<       ndbas=lna >*/
	    ndbas = lna;
/* SOURCE ntmatrix.for:303 */
/*<       ivar=-ivar >*/
	    ivar = -ivar;
/* SOURCE ntmatrix.for:304 */
/*<       endif >*/
	}
/*       DO THE NODES */
/* SOURCE ntmatrix.for:308 */
/*<       do90nad=fna,lna,ninc >*/
	feq_gen_i_d_2 = lna;
	feq_gen_i_d_3 = ninc;
	for (nad = fna; feq_gen_i_d_3 < 0 ? nad >= feq_gen_i_d_2 : nad <= feq_gen_i_d_2; nad += feq_gen_i_d_3) {
/* SOURCE ntmatrix.for:309 */
/*<       dy=rhs(ivar+1) >*/
	    dy = matcom_1.rhs[ivar];
/* SOURCE ntmatrix.for:310 */
/*<       bncory(nad)=hi_iq_ns_fac(ivar+1)*dy >*/
	    bnothr_1.bncory[nad - 1] = static_cast<double>(matcom_1.feq_gen_hi_iq_ns_fac_d_[ivar]) * dy;
/* SOURCE ntmatrix.for:311 */
/*<       if(abs(dy).lt.abstol)then >*/
	    if (dabs(dy) < *abstol) {
/* SOURCE ntmatrix.for:312 */
/*<       b=0.0 >*/
		b = (float)0.;
/* SOURCE ntmatrix.for:313 */
/*<       else >*/
	    } else {
/* SOURCE ntmatrix.for:314 */
/*<       t=t2(nad) >*/
		t = bnelem_1.t2[nad - 1];
/* SOURCE ntmatrix.for:315 */
/*<       b=abs(dy*t/a2(nad)) >*/
		b = (feq_gen_r_d_1 = static_cast<double>(static_cast<double>(dy) * t) / bnelem_1.a2[nad - 1], dabs(feq_gen_r_d_1));
/* SOURCE ntmatrix.for:316 */
/*<       endif >*/
	    }
/* SOURCE ntmatrix.for:317 */
/*<       if(b.ge.mxre)then >*/
	    if (b >= *mxre) {
/* SOURCE ntmatrix.for:318 */
/*<       mxre=b >*/
		*mxre = b;
/* SOURCE ntmatrix.for:319 */
/*<       bmxre=nb >*/
		*bmxre = nb;
/* SOURCE ntmatrix.for:320 */
/*<       ivar_mxre=ivar+1 >*/
		*feq_gen_ivar_mxre_d_ = ivar + 1;
/* SOURCE ntmatrix.for:321 */
/*<       bnode_max=nad >*/
		*feq_gen_bnode_max_d_ = nad;
/* SOURCE ntmatrix.for:322 */
/*<       nmxre=-(snode+nad-ndbas) >*/
		*nmxre = -(snode + nad - ndbas);
/* SOURCE ntmatrix.for:323 */
/*<       endif >*/
	    }
/* SOURCE ntmatrix.for:325 */
/*<       if(b.gt.epssys)then >*/
	    if (b > *epssys) {
/* SOURCE ntmatrix.for:326 */
/*<       iknt=iknt+1 >*/
		++iknt;
/* SOURCE ntmatrix.for:327 */
/*<       if(b.gt.epssy2)then >*/
		if (b > *epssy2) {
/* SOURCE ntmatrix.for:328 */
/*<       iknta=iknta+1 >*/
		    ++iknta;
/* SOURCE ntmatrix.for:329 */
/*<       endif >*/
		}
/* SOURCE ntmatrix.for:330 */
/*<       hi_iq_ns_state(ivar+1)=0 >*/
		matcom_1.feq_gen_hi_iq_ns_state_d_[ivar] = 0;
/* SOURCE ntmatrix.for:331 */
/*<       else >*/
	    } else {
/* SOURCE ntmatrix.for:332 */
/*<       hi_iq_ns_state(ivar+1)=1 >*/
		matcom_1.feq_gen_hi_iq_ns_state_d_[ivar] = 1;
/* SOURCE ntmatrix.for:333 */
/*<       endif >*/
	    }
/* SOURCE ntmatrix.for:335 */
/*<       dq=rhs(ivar) >*/
	    dq = matcom_1.rhs[ivar - 1];
/* SOURCE ntmatrix.for:336 */
/*<       bncorq(nad)=hi_iq_ns_fac(ivar)*dq >*/
	    bnothr_1.bncorq[nad - 1] = static_cast<double>(matcom_1.feq_gen_hi_iq_ns_fac_d_[ivar - 1]) * dq;
/* SOURCE ntmatrix.for:338 */
/*<       b=abs(dq/(abs(q2(nad))+qeps)) >*/
	    b = (feq_gen_r_d_2 = dq / ((feq_gen_r_d_1 = bnelem_1.q2[nad - 1], dabs(feq_gen_r_d_1)) + *
		    qeps), dabs(feq_gen_r_d_2));
/* SOURCE ntmatrix.for:339 */
/*<       if(b.ge.mxre)then >*/
	    if (b >= *mxre) {
/* SOURCE ntmatrix.for:340 */
/*<       mxre=b >*/
		*mxre = b;
/* SOURCE ntmatrix.for:341 */
/*<       bmxre=nb >*/
		*bmxre = nb;
/* SOURCE ntmatrix.for:342 */
/*<       ivar_mxre=ivar >*/
		*feq_gen_ivar_mxre_d_ = ivar;
/* SOURCE ntmatrix.for:343 */
/*<       bnode_max=nad >*/
		*feq_gen_bnode_max_d_ = nad;
/* SOURCE ntmatrix.for:344 */
/*<       nmxre=snode+nad-ndbas >*/
		*nmxre = snode + nad - ndbas;
/* SOURCE ntmatrix.for:345 */
/*<       endif >*/
	    }
/* SOURCE ntmatrix.for:346 */
/*<       if(b.gt.epssys)then >*/
	    if (b > *epssys) {
/* SOURCE ntmatrix.for:347 */
/*<       iknt=iknt+1 >*/
		++iknt;
/* SOURCE ntmatrix.for:348 */
/*<       if(b.gt.epssy2)then >*/
		if (b > *epssy2) {
/* SOURCE ntmatrix.for:349 */
/*<       iknta=iknta+1 >*/
		    ++iknta;
/* SOURCE ntmatrix.for:350 */
/*<       endif >*/
		}
/* SOURCE ntmatrix.for:351 */
/*<       hi_iq_ns_state(ivar)=0 >*/
		matcom_1.feq_gen_hi_iq_ns_state_d_[ivar - 1] = 0;
/* SOURCE ntmatrix.for:352 */
/*<       else >*/
	    } else {
/* SOURCE ntmatrix.for:353 */
/*<       hi_iq_ns_state(ivar)=1 >*/
		matcom_1.feq_gen_hi_iq_ns_state_d_[ivar - 1] = 1;
/* SOURCE ntmatrix.for:354 */
/*<       endif >*/
	    }
/* SOURCE ntmatrix.for:355 */
/*<       ivar=ivar+2 >*/
	    ivar += 2;
/* SOURCE ntmatrix.for:356 */
/*<    90 continue >*/
/* L90: */
	}
/* SOURCE ntmatrix.for:357 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE ntmatrix.for:359 */
/*<       knt=iknt >*/
    *knt = iknt;
/* SOURCE ntmatrix.for:360 */
/*<       knta=iknta >*/
    *knta = iknta;
/* SOURCE ntmatrix.for:361 */
/*<       return >*/
    return 0;
/* SOURCE ntmatrix.for:362 */
/*<       end >*/
} /* cmpcor_ */

#undef rdum
#undef idum





/* SOURCE ntmatrix.for:366 */
/*<       subroutinecrset2(nbra,nex,brpt,exnodt) >*/
/* Subroutine */ int crset2_(integer *nbra, integer *nex, integer *feq_storage_brpt, 
	integer *feq_storage_exnodt)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    static real equiv_0[1];

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    real a, b, k, t, y, db, ma, dk;
    integer ii, fn, jj;
    real dt;
    integer ln;
    real dma, arg;
    integer geq;
    real dmq, pdv, vol, mqt;
    integer ntab, adrs;
#define idum (feq::BitView<integer>(equiv_0, sizeof(equiv_0)))
#define rdum (equiv_0)
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *), xlkt20_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *), xlkt23_(integer *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__35 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Establish remainder of set 2 given the values of Y2(*), */
/*     Ye2(*), and Q2(*).  On convergence Qe2(*) has not yet been */
/*     set so it must be done here also. */
/* SOURCE ntmatrix.for:375 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntmatrix.for:378 */
/*<       integernbra,nex >*/
/* SOURCE ntmatrix.for:379 */
/*<       integerbrpt(8,nbra),exnodt(9,nex) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NBRA   - number of branches in the model */
/*     NEX    - number of exterior nodes in the model */
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
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntmatrix.for:410 */
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
/* INCLUDE ntmatrix.for:411 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE ntmatrix.for:412 */
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
/* INCLUDE ntmatrix.for:413 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE ntmatrix.for:414 */
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
/* SOURCE ntmatrix.for:417 */
/*<       integeradrs,fn,geq,idum,ii,jj,ln,ntab >*/
/* SOURCE ntmatrix.for:418 */
/*<       reala,arg,b,db,dk,dma,dmq,dt,k,ma,mqt,pdv,rdum,t,vol,y >*/
/*     + + + EQUIVALENCES + + + */
/* SOURCE ntmatrix.for:422 */
/*<       equivalence(idum,rdum) >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntmatrix.for:425 */
/*<       externallktab,xlkt20,xlkt23 >*/
/* *********************************************************************** */
/* SOURCE ntmatrix.for:427 */
/*<       do200ii=1,nbra >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    /* Function Body */
    feq_gen_i_d_1 = *nbra;
    for (ii = 1; ii <= feq_gen_i_d_1; ++ii) {
/* SOURCE ntmatrix.for:428 */
/*<       fn=brpt(3,ii) >*/
	fn = brpt[(ii << 3) + 3];
/* SOURCE ntmatrix.for:429 */
/*<       ln=brpt(4,ii) >*/
	ln = brpt[(ii << 3) + 4];
/* SOURCE ntmatrix.for:430 */
/*<       geq=geqvec(ii) >*/
	geq = bnothr_1.geqvec[ii - 1];
/* SOURCE ntmatrix.for:431 */
/*<       do100jj=fn,ln >*/
	feq_gen_i_d_2 = ln;
	for (jj = fn; jj <= feq_gen_i_d_2; ++jj) {
/* SOURCE ntmatrix.for:432 */
/*<       y=y2(jj) >*/
	    y = bnelem_1.y2[jj - 1];
/* SOURCE ntmatrix.for:433 */
/*<       adrs=nsec(jj) >*/
	    adrs = bnothr_1.nsec[jj - 1];
/* SOURCE ntmatrix.for:435 */
/*<       goto(1,1,2,2),geq >*/
	    switch (geq) {
		case 1:  goto L1;
		case 2:  goto L1;
		case 3:  goto L2;
		case 4:  goto L2;
	    }
/* SOURCE ntmatrix.for:436 */
/*<       write(std6,*)' *BUG:XXX* INVALID GEQOPT IN CRSET2' >*/
	    feq_gen_io_d__35.ciunit = feq_gen_stdun_com_d_1.std6;
	    s_wsle(&feq_gen_io_d__35);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* INVALID GEQOPT IN CRSET2"), (
		    ftnlen)35);
	    e_wsle();
/* SOURCE ntmatrix.for:437 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntmatrix.for:439 */
/*<     1 continue >*/
L1:
/* SOURCE ntmatrix.for:440 */
/*<       callxlkt20(adrs,y,a,t,dt,k,dk,b,db) >*/
	    xlkt20_(&adrs, &y, &a, &t, &dt, &k, &dk, &b, &db);
/* SOURCE ntmatrix.for:444 */
/*<       a2(jj)=a >*/
	    bnelem_1.a2[jj - 1] = a;
/* SOURCE ntmatrix.for:445 */
/*<       t2(jj)=t >*/
	    bnelem_1.t2[jj - 1] = t;
/* SOURCE ntmatrix.for:446 */
/*<       k2(jj)=k >*/
	    bnelem_1.k2[jj - 1] = k;
/* SOURCE ntmatrix.for:447 */
/*<       b2(jj)=b >*/
	    bnelem_1.b2[jj - 1] = b;
/* SOURCE ntmatrix.for:448 */
/*<       goto9 >*/
	    goto L9;
/* SOURCE ntmatrix.for:450 */
/*<     2 continue >*/
L2:
/* SOURCE ntmatrix.for:451 */
/*<       callxlkt23(adrs,y,a,t,dt,k,dk,b,db,ma,dma,mqt,dmq) >*/
	    xlkt23_(&adrs, &y, &a, &t, &dt, &k, &dk, &b, &db, &ma, &dma, &mqt,
		     &dmq);
/* SOURCE ntmatrix.for:455 */
/*<       a2(jj)=a >*/
	    bnelem_1.a2[jj - 1] = a;
/* SOURCE ntmatrix.for:456 */
/*<       t2(jj)=t >*/
	    bnelem_1.t2[jj - 1] = t;
/* SOURCE ntmatrix.for:457 */
/*<       k2(jj)=k >*/
	    bnelem_1.k2[jj - 1] = k;
/* SOURCE ntmatrix.for:458 */
/*<       b2(jj)=b >*/
	    bnelem_1.b2[jj - 1] = b;
/* SOURCE ntmatrix.for:459 */
/*<       ma2(jj)=ma >*/
	    bnelem_1.ma2[jj - 1] = ma;
/* SOURCE ntmatrix.for:460 */
/*<       mq2(jj)=mqt >*/
	    bnelem_1.mq2[jj - 1] = mqt;
/* SOURCE ntmatrix.for:461 */
/*<       goto9 >*/
	    goto L9;
/* SOURCE ntmatrix.for:463 */
/*<     9 continue >*/
L9:
/* SOURCE ntmatrix.for:465 */
/*<   100 continue >*/
/* L100: */
	    ;
	}
/*       MAKE EXTERIOR NODE VALUES ON BRANCHES SAME AS THE INTERIOR */
/*       NODE SYSTEM VALUES */
/* SOURCE ntmatrix.for:470 */
/*<       ye2(brpt(5,ii))=y2(fn) >*/
	enelem_1.ye2[brpt[(ii << 3) + 5] - 1] = bnelem_1.y2[fn - 1];
/* SOURCE ntmatrix.for:471 */
/*<       te2(brpt(5,ii))=t2(fn) >*/
	enelem_1.te2[brpt[(ii << 3) + 5] - 1] = bnelem_1.t2[fn - 1];
/* SOURCE ntmatrix.for:472 */
/*<       ae2(brpt(5,ii))=a2(fn) >*/
	enelem_1.ae2[brpt[(ii << 3) + 5] - 1] = bnelem_1.a2[fn - 1];
/* SOURCE ntmatrix.for:473 */
/*<       qe2(brpt(5,ii))=q2(fn) >*/
	enelem_1.qe2[brpt[(ii << 3) + 5] - 1] = bnelem_1.q2[fn - 1];
/* SOURCE ntmatrix.for:475 */
/*<       ye2(brpt(6,ii))=y2(ln) >*/
	enelem_1.ye2[brpt[(ii << 3) + 6] - 1] = bnelem_1.y2[ln - 1];
/* SOURCE ntmatrix.for:476 */
/*<       te2(brpt(6,ii))=t2(ln) >*/
	enelem_1.te2[brpt[(ii << 3) + 6] - 1] = bnelem_1.t2[ln - 1];
/* SOURCE ntmatrix.for:477 */
/*<       ae2(brpt(6,ii))=a2(ln) >*/
	enelem_1.ae2[brpt[(ii << 3) + 6] - 1] = bnelem_1.a2[ln - 1];
/* SOURCE ntmatrix.for:478 */
/*<       qe2(brpt(6,ii))=q2(ln) >*/
	enelem_1.qe2[brpt[(ii << 3) + 6] - 1] = bnelem_1.q2[ln - 1];
/* SOURCE ntmatrix.for:480 */
/*<   200 continue >*/
/* L200: */
    }
/*     FIND VOLUMES IN RESERVOIRS */
/* SOURCE ntmatrix.for:484 */
/*<       do300ii=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (ii = 1; ii <= feq_gen_i_d_1; ++ii) {
/* SOURCE ntmatrix.for:485 */
/*<       if(exnodt(3,ii).eq.-1)then >*/
	if (exnodt[ii * 9 + 3] == -1) {
/* SOURCE ntmatrix.for:487 */
/*<       adrs=exnodt(4,ii) >*/
	    adrs = exnodt[ii * 9 + 4];
/* SOURCE ntmatrix.for:488 */
/*<       arg=ye2(ii) >*/
	    arg = enelem_1.ye2[ii - 1];
/* SOURCE ntmatrix.for:489 */
/*<       calllktab(adrs,arg,0,vol,ntab,pdv) >*/
	    lktab_(&adrs, &arg, &feq_gen_c_d_0, &vol, &ntab, &pdv);
/* SOURCE ntmatrix.for:492 */
/*<       te2(ii)=pdv >*/
	    enelem_1.te2[ii - 1] = pdv;
/* SOURCE ntmatrix.for:493 */
/*<       ae2(ii)=-vol >*/
	    enelem_1.ae2[ii - 1] = -vol;
/* SOURCE ntmatrix.for:494 */
/*<       endif >*/
	}
/* SOURCE ntmatrix.for:496 */
/*<   300 continue >*/
/* L300: */
    }
/* SOURCE ntmatrix.for:498 */
/*<       return >*/
    return 0;
/* SOURCE ntmatrix.for:499 */
/*<       end >*/
} /* crset2_ */

#undef rdum
#undef idum





/* SOURCE ntmatrix.for:503 */
/*<        >*/
/* Subroutine */ int csmat_(doublereal *dt, doublereal *dtdy, real *wt, 
	integer *nbn, integer *nbra, integer *nex, integer *feq_storage_brpt, real *hslot,
	 integer *ept, real *feq_gen_dtmin_out_d_, integer *feq_gen_start_eq_d_, integer *
	feq_gen_end_eq_d_, doublereal *jtime, doublereal *prtime, integer *kount, real 
	*qeps, integer *feq_storage_emc, integer *feq_storage_exnodt, real *rnorm, real *mxres, 
	integer *lmxres, real *errp, real *errq, integer *berrq, integer *
	nerrq, integer *nerrp, integer *berrp)
{
    extern /* Subroutine */ int profac_(integer *), dmpeqs_(integer *, 
	    integer *, integer *, integer *, doublereal *), proslv_(integer *,
	     real *, integer *, integer *, real *), setext_(doublereal *, 
	    doublereal *, real *, integer *, integer *, integer *, integer *, 
	    real *, integer *, real *, doublereal *, integer *, integer *, 
	    real *, real *, integer *, real *, real *, integer *, integer *, 
	    integer *, integer *), savemat_(integer *, integer *, real *, 
	    real *, real *, real *);

/*     + + + PURPOSE + + + */
/*     Compute and solve the network matrix. */
/* SOURCE ntmatrix.for:514 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE ntmatrix.for:516 */
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
/* SOURCE ntmatrix.for:520 */
/*<        >*/
/* SOURCE ntmatrix.for:522 */
/*<       integerbrpt(8,nbra),emc(mremc),exnodt(9,nex) >*/
/* SOURCE ntmatrix.for:523 */
/*<       realerrp,errq,hslot,mxres,rnorm,wt,dtmin_out,qeps >*/
/* SOURCE ntmatrix.for:524 */
/*<       real*8dt,dtdy,jtime,prtime >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     DT     - time step in seconds */
/*     WT     - weight factor for approximating time integrals */
/*     NBN    - total number on nodes on branches in the model */
/*     NBRA   - number of branches in the model */
/*     NEX    - number of exterior nodes in the model */
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
/*     HSLOT  - height of bottom slot.  Currently 0.0 always */
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
/*     RNORM  - sum of squares of the residuals */
/*     MXRES  - maximum value of the residuals in the matrix */
/*     LMXRES - location of the maximum residual */
/*     ERRP   - current maximum relative change in surcharge storage */
/*     ERRQ   - maximum value of the ratio of lateral inflow to the */
/*               average flow in the element */
/*     BERRQ  - records the branch number(internal) that has the */
/*               greatest value of the ratio of lateral inflow */
/*               to average flow in an element */
/*     NERRQ  - node at which maximum relative lateral inflow occurs */
/*     NERRP  - node at which maximum correction to surcharge storage */
/*               occurs */
/*     BERRP  - records the branch number(internal) that has the */
/*               greatest absolute value of the change in surcharge */
/*               storage relative to the storage in the storm sewer */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntmatrix.for:575 */
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
/* INCLUDE ntmatrix.for:576 */
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
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntmatrix.for:579 */
/*<       externalprofac,proslv,setext >*/
/* *********************************************************************** */
/* SOURCE ntmatrix.for:581 */
/*<        >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
    setext_(dt, dtdy, wt, nbn, nbra, nex, &brpt[9], hslot, ept, qeps, jtime, &
	    emc[1], &exnodt[10], rnorm, mxres, lmxres, errp, errq, berrq, 
	    nerrq, nerrp, berrp);
/*     Save copy of matrix and rhs for later dumping */
/* SOURCE ntmatrix.for:589 */
/*<       if(start_eq.le.end_eq)then >*/
    if (*feq_gen_start_eq_d_ <= *feq_gen_end_eq_d_) {
/* SOURCE ntmatrix.for:590 */
/*<       if(jtime.ge.prtime)then >*/
	if (*jtime >= *prtime) {
/* SOURCE ntmatrix.for:591 */
/*<       callsavemat(numeq,c(numeq),pdavec,rhs,pdavec2,rhs2) >*/
	    savemat_(&matcom_1.numeq, &matcom_1.feq_gen_c_d_[matcom_1.numeq], 
		    matcom_1.pdavec, matcom_1.rhs, matcom2_1.pdavec2, 
		    matcom2_1.rhs2);
/* SOURCE ntmatrix.for:593 */
/*<       endif >*/
	}
/* SOURCE ntmatrix.for:594 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' PROFILE MATRIX AND RHS BEFORE SOLUTION' */
/*       CALL OUTPRO(STDOUT) */
/*      WRITE(STDOUT,*) ' DIAGONAL ELEMENTS IN MATRIX' */
/*      DO 100 I=1,NUMEQ */
/*        WRITE(STDOUT,'(I5,F10.3)') I,PDAVEC(C(I)) */
/* 100   CONTINUE */
/*      WRITE(STDOUT,*) ' ' */
/*     SOLVE  MATRIX */
/* SOURCE ntmatrix.for:609 */
/*<       callprofac(stdout) >*/
    profac_(&xscom_1.stdout);
/* SOURCE ntmatrix.for:612 */
/*<       callproslv(numeq,pdavec,c,r,rhs) >*/
    proslv_(&matcom_1.numeq, matcom_1.pdavec, matcom_1.feq_gen_c_d_, matcom_1.feq_gen_r_d_, 
	    matcom_1.rhs);
/* SOURCE ntmatrix.for:617 */
/*<       if(start_eq.le.end_eq)then >*/
    if (*feq_gen_start_eq_d_ <= *feq_gen_end_eq_d_) {
/* SOURCE ntmatrix.for:618 */
/*<       if(jtime.ge.prtime)then >*/
	if (*jtime >= *prtime) {
/* SOURCE ntmatrix.for:619 */
/*<       calldmpeqs(stdout,start_eq,end_eq,kount,jtime) >*/
	    dmpeqs_(&xscom_1.stdout, feq_gen_start_eq_d_, feq_gen_end_eq_d_, kount, jtime);
/* SOURCE ntmatrix.for:620 */
/*<       endif >*/
	}
/* SOURCE ntmatrix.for:621 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' SOLUTION VECTOR' */
/*      DO 100 I=1,NUMEQ */
/*        WRITE(STDOUT,'(1X,1PE11.3)') RHS(I) */
/* 100   CONTINUE */
/*      WRITE(STDOUT,*) ' PROFILE MATRIX AND RHS AFTER SOLUTION' */
/*      CALL OUTPRO(STDOUT) */
/* SOURCE ntmatrix.for:631 */
/*<       return >*/
    return 0;
/* SOURCE ntmatrix.for:632 */
/*<       end >*/
} /* csmat_ */




/* SOURCE ntmatrix.for:636 */
/*<       subroutinesavemat(n,m,pdavec,rhs,pdavec2,rhs2) >*/
/* Subroutine */ int savemat_(integer *n, integer *m, real *pdavec, real *rhs,
             real *pdavec2, real *rhs2) {
    // Released ntmatrix.for:636-647 declares these REAL*8, although the
    // shipped solver's MATCOM and MATCOM2 arrays are REAL*4. Original binary
    // RVA 0x75c00 copies 8*N bytes of RHS, then 8*M bytes of PDAVEC.
    // Preserve that observed copy, using each complete COMMON object as the
    // byte-storage boundary. No typed double pointer aliases a float array.
    if (pdavec != matcom_1.pdavec || rhs != matcom_1.rhs ||
        pdavec2 != matcom2_1.pdavec2 || rhs2 != matcom2_1.rhs2) {
        throw std::invalid_argument("SAVEMAT expected the released COMMON arrays.");
    }
    const std::size_t rhs_bytes = feq::checked_extent(*n > 0 ? *n : 0, 8);
    const std::size_t matrix_bytes = feq::checked_extent(*m > 0 ? *m : 0, 8);
    feq::copy_object_bytes(&matcom2_, sizeof(matcom2_), offsetof(Common_matcom2_, rhs2),
                           &matcom_, sizeof(matcom_), offsetof(Common_matcom_, rhs), rhs_bytes);
    feq::copy_object_bytes(&matcom2_, sizeof(matcom2_), offsetof(Common_matcom2_, pdavec2),
                           &matcom_, sizeof(matcom_), offsetof(Common_matcom_, pdavec), matrix_bytes);
    return 0;
} /* savemat_ */




/* SOURCE ntmatrix.for:654 */
/*<       subroutineestbn(dt,nbn,mre) >*/
/* Subroutine */ int estbn_(doublereal *dt, integer *nbn, real *mre)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    double r_sign(real *, real *);

    /* Local variables */
    integer feq_gen_i_d_;
    real y, dely, mxdely;

/*     + + + PURPOSE + + + */
/*     Estimate values of the dependent variables for the first */
/*     iteration of each time step for nodes on branches. */
/* SOURCE ntmatrix.for:661 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntmatrix.for:664 */
/*<       integernbn >*/
/* SOURCE ntmatrix.for:665 */
/*<       realmre >*/
/* SOURCE ntmatrix.for:666 */
/*<       real*8dt >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     DT     - time step in seconds */
/*     NBN    - total number on nodes on branches in the model */
/*     MRE    - maximum relative change permitted when estimating values */
/*               for branch nodes */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntmatrix.for:675 */
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
/* INCLUDE ntmatrix.for:676 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE ntmatrix.for:677 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ntmatrix.for:680 */
/*<       integeri >*/
/* SOURCE ntmatrix.for:681 */
/*<       realdely,mxdely,y >*/
/*     + + + INTRINSICS + + + */
/* SOURCE ntmatrix.for:684 */
/*<       intrinsicabs,sign >*/
/* *********************************************************************** */
/* SOURCE ntmatrix.for:686 */
/*<       do300i=1,nbn >*/
    feq_gen_i_d_1 = *nbn;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ntmatrix.for:687 */
/*<       q2(i)=q1(i)+mq(i)*dt >*/
	bnelem_1.q2[feq_gen_i_d_ - 1] = bnelem_1.q1[feq_gen_i_d_ - 1] + bnelem_1.mq[feq_gen_i_d_ - 1] * *
		dt;
/* SOURCE ntmatrix.for:689 */
/*<       y=y1(i) >*/
	y = bnelem_1.y1[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:690 */
/*<       mxdely=mre*y >*/
	mxdely = static_cast<double>(*mre) * y;
/* SOURCE ntmatrix.for:691 */
/*<       dely=my(i)*dt >*/
	dely = bnelem_1.my[feq_gen_i_d_ - 1] * *dt;
/* SOURCE ntmatrix.for:692 */
/*<       if(abs(dely).gt.mxdely)dely=sign(mxdely,dely) >*/
	if (dabs(dely) > mxdely) {
	    dely = r_sign(&mxdely, &dely);
	}
/* SOURCE ntmatrix.for:693 */
/*<       y2(i)=y+dely >*/
	bnelem_1.y2[feq_gen_i_d_ - 1] = static_cast<double>(y) + dely;
/* SOURCE ntmatrix.for:694 */
/*<       if(y2(i).gt.bnmaxy(i))then >*/
	if (bnelem_1.y2[feq_gen_i_d_ - 1] > bnothr_1.bnmaxy[feq_gen_i_d_ - 1]) {
/* SOURCE ntmatrix.for:695 */
/*<       y2(i)=0.5*(y+bnmaxy(i)) >*/
	    bnelem_1.y2[feq_gen_i_d_ - 1] = static_cast<double>((static_cast<double>(y) + bnothr_1.bnmaxy[feq_gen_i_d_ - 1])) * (float).5;
/* SOURCE ntmatrix.for:696 */
/*<       endif >*/
	}
/* SOURCE ntmatrix.for:697 */
/*<   300 continue >*/
/* L300: */
    }
/* SOURCE ntmatrix.for:699 */
/*<       return >*/
    return 0;
/* SOURCE ntmatrix.for:700 */
/*<       end >*/
} /* estbn_ */




/* SOURCE ntmatrix.for:704 */
/*<       subroutineesten(dt,nex,mre,exnodt) >*/
/* Subroutine */ int esten_(doublereal *dt, integer *nex, real *mre, integer *
	feq_storage_exnodt)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    double r_sign(real *, real *);

    /* Local variables */
    integer feq_gen_i_d_, j;
    real y, dely, mxdely;

/*     + + + PURPOSE + + + */
/*     Estimate values of the dependent variables for the first */
/*     iteration of each time step for exterior nodes. */
/* SOURCE ntmatrix.for:710 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntmatrix.for:713 */
/*<       integernex >*/
/* SOURCE ntmatrix.for:714 */
/*<       integerexnodt(9,nex) >*/
/* SOURCE ntmatrix.for:715 */
/*<       realmre >*/
/* SOURCE ntmatrix.for:716 */
/*<       real*8dt >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     DT     - time step in seconds */
/*     NEX    - number of exterior nodes in the model */
/*     MRE    - maximum relative change permitted when estimating values */
/*               for branch nodes */
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
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntmatrix.for:739 */
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
/* INCLUDE ntmatrix.for:740 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE ntmatrix.for:741 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE ntmatrix.for:742 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ntmatrix.for:745 */
/*<       integeri,j >*/
/* SOURCE ntmatrix.for:746 */
/*<       realdely,mxdely,y >*/
/*     + + + INTRINSICS + + + */
/* SOURCE ntmatrix.for:749 */
/*<       intrinsicabs,sign >*/
/* *********************************************************************** */
/* SOURCE ntmatrix.for:751 */
/*<       do450i=1,nex >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    /* Function Body */
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ntmatrix.for:752 */
/*<       if(exnodt(3,i).le.0)goto410 >*/
	if (exnodt[feq_gen_i_d_ * 9 + 3] <= 0) {
	    goto L410;
	}
/* SOURCE ntmatrix.for:753 */
/*<       j=exnodt(2,i) >*/
	j = exnodt[feq_gen_i_d_ * 9 + 2];
/*         NODE ON A BRANCH */
/* SOURCE ntmatrix.for:755 */
/*<       qe2(i)=q2(j) >*/
	enelem_1.qe2[feq_gen_i_d_ - 1] = bnelem_1.q2[j - 1];
/* SOURCE ntmatrix.for:756 */
/*<       ye2(i)=y2(j) >*/
	enelem_1.ye2[feq_gen_i_d_ - 1] = bnelem_1.y2[j - 1];
/* SOURCE ntmatrix.for:757 */
/*<       te2(i)=t2(j) >*/
	enelem_1.te2[feq_gen_i_d_ - 1] = bnelem_1.t2[j - 1];
/* SOURCE ntmatrix.for:758 */
/*<       goto420 >*/
	goto L420;
/* SOURCE ntmatrix.for:759 */
/*<   410 continue >*/
L410:
/*         FREE NODE-DEFINE ONLY DEPTH AND FLOW */
/* SOURCE ntmatrix.for:763 */
/*<       y=ye1(i) >*/
	y = enelem_1.ye1[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:764 */
/*<       mxdely=mre*y >*/
	mxdely = static_cast<double>(*mre) * y;
/* SOURCE ntmatrix.for:765 */
/*<       dely=mye(i)*dt >*/
	dely = enelem_1.mye[feq_gen_i_d_ - 1] * *dt;
/* SOURCE ntmatrix.for:766 */
/*<       if(abs(dely).gt.mxdely)dely=sign(mxdely,dely) >*/
	if (dabs(dely) > mxdely) {
	    dely = r_sign(&mxdely, &dely);
	}
/* SOURCE ntmatrix.for:767 */
/*<       ye2(i)=y+dely >*/
	enelem_1.ye2[feq_gen_i_d_ - 1] = static_cast<double>(y) + dely;
/* SOURCE ntmatrix.for:768 */
/*<       if(ye2(i).gt.enmaxy(i))then >*/
	if (enelem_1.ye2[feq_gen_i_d_ - 1] > enothr_1.enmaxy[feq_gen_i_d_ - 1]) {
/* SOURCE ntmatrix.for:769 */
/*<       ye2(i)=0.5*(y+enmaxy(i)) >*/
	    enelem_1.ye2[feq_gen_i_d_ - 1] = static_cast<double>((static_cast<double>(y) + enothr_1.enmaxy[feq_gen_i_d_ - 1])) * (float)
		    .5;
/* SOURCE ntmatrix.for:770 */
/*<       endif >*/
	}
/* SOURCE ntmatrix.for:771 */
/*<       qe2(i)=qe1(i)+mqe(i)*dt >*/
	enelem_1.qe2[feq_gen_i_d_ - 1] = enelem_1.qe1[feq_gen_i_d_ - 1] + enelem_1.mqe[feq_gen_i_d_ - 1] 
		* *dt;
/* SOURCE ntmatrix.for:772 */
/*<   420 continue >*/
L420:
/* SOURCE ntmatrix.for:773 */
/*<   450 continue >*/
/* L450: */
	;
    }
/* SOURCE ntmatrix.for:775 */
/*<       return >*/
    return 0;
/* SOURCE ntmatrix.for:776 */
/*<       end >*/
} /* esten_ */




/* SOURCE ntmatrix.for:780 */
/*<       subroutinefmxmn(nbn,nex,nbra,exnodt,brpt,jtime) >*/
/* Subroutine */ int fmxmn_(integer *nbn, integer *nex, integer *nbra, 
	integer *feq_storage_exnodt, integer *feq_storage_brpt, doublereal *jtime)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1, feq_gen_r_d_2;

    /* Local variables */
    integer feq_gen_i_d_, j;
    real v;
    integer ie, is, dnn, unn;
    real sum;
    integer ibra;
    real temp;

/*     + + + PURPOSE + + + */
/*     Find maximum and minimum flows and elevations. At this point */
/*     the set 1 variables have been reset to values of set 2 with */
/*     small flow clipping.  Use set 1 in the flow tests. */
/* SOURCE ntmatrix.for:788 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntmatrix.for:790 */
/*<       integernbn,nbra,nex >*/
/* SOURCE ntmatrix.for:791 */
/*<       integerbrpt(8,nbra),exnodt(9,nex) >*/
/* SOURCE ntmatrix.for:792 */
/*<       real*8jtime >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NBN    - total number on nodes on branches in the model */
/*     NEX    - number of exterior nodes in the model */
/*     NBRA   - number of branches in the model */
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
/*     JTIME  - current modified julian time in the model */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntmatrix.for:825 */
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
/* INCLUDE ntmatrix.for:826 */
/*     Miscellaneous control parameters */
/* SOURCE misccon.cmn:3 */
/*<       integerpagesp,pndflg >*/
/* SOURCE misccon.cmn:5 */
/*<        >*/
/* SOURCE misccon.cmn:8 */
/*<        >*/
/* INCLUDE ntmatrix.for:827 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE ntmatrix.for:828 */
/* ********************************************************************** */
/* SOURCE bnrslt.cmn:2 */
/*<       common/bnrslt/tqmax,tqmin,tzmax,qmax,qmin,zmax,vmax >*/
/* SOURCE bnrslt.cmn:5 */
/*<       realqmax(mnbn),qmin(mnbn),zmax(mnbn),vmax(mnbn) >*/
/* SOURCE bnrslt.cmn:7 */
/*<       doubleprecisiontqmax(mnbn),tqmin(mnbn),tzmax(mnbn) >*/
/* ********************************************************************** */
/* INCLUDE ntmatrix.for:829 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE ntmatrix.for:830 */
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
/* INCLUDE ntmatrix.for:831 */
/* ********************************************************************** */
/* SOURCE bnpond.cmn:3 */
/*<       common/bnpond/coefin,pond1,pond2,ycut,bpond,bpmax >*/
/* SOURCE bnpond.cmn:5 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE ntmatrix.for:832 */
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
/* SOURCE ntmatrix.for:835 */
/*<       integerdnn,i,ibra,ie,is,j,unn >*/
/* SOURCE ntmatrix.for:836 */
/*<       realsum,temp,v >*/
/*     + + + INTRINSICS + + + */
/* SOURCE ntmatrix.for:839 */
/*<       intrinsicabs,max >*/
/* *********************************************************************** */
/* SOURCE ntmatrix.for:841 */
/*<       do242ibra=1,nbra >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    /* Function Body */
    feq_gen_i_d_1 = *nbra;
    for (ibra = 1; ibra <= feq_gen_i_d_1; ++ibra) {
/* SOURCE ntmatrix.for:842 */
/*<       is=brpt(3,ibra) >*/
	is = brpt[(ibra << 3) + 3];
/* SOURCE ntmatrix.for:843 */
/*<       ie=brpt(4,ibra) >*/
	ie = brpt[(ibra << 3) + 4];
/* SOURCE ntmatrix.for:844 */
/*<       unn=brpt(5,ibra) >*/
	unn = brpt[(ibra << 3) + 5];
/* SOURCE ntmatrix.for:845 */
/*<       dnn=brpt(6,ibra) >*/
	dnn = brpt[(ibra << 3) + 6];
/*       Do upstream exterior node */
/*       Find maximum flow */
/* SOURCE ntmatrix.for:849 */
/*<       if(q1(is).gt.qmax(is))then >*/
	if (bnelem_1.q1[is - 1] > bnrslt_1.qmax[is - 1]) {
/* SOURCE ntmatrix.for:850 */
/*<       qmax(is)=q1(is) >*/
	    bnrslt_1.qmax[is - 1] = bnelem_1.q1[is - 1];
/* SOURCE ntmatrix.for:851 */
/*<       tqmax(is)=jtime >*/
	    bnrslt_1.tqmax[is - 1] = *jtime;
/* SOURCE ntmatrix.for:852 */
/*<       endif >*/
	}
/*       Find maximum absolute value of velocity */
/* SOURCE ntmatrix.for:855 */
/*<       v=abs(q1(is)/a2(is)) >*/
	v = (feq_gen_r_d_1 = static_cast<double>(bnelem_1.q1[is - 1]) / bnelem_1.a2[is - 1], dabs(feq_gen_r_d_1));
/* SOURCE ntmatrix.for:856 */
/*<       vmax(is)=max(v,vmax(is)) >*/
/* Computing MAX */
	feq_gen_r_d_1 = v, feq_gen_r_d_2 = bnrslt_1.vmax[is - 1];
	bnrslt_1.vmax[is - 1] = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/*     Find minimum flow */
/* SOURCE ntmatrix.for:859 */
/*<       if(q1(is).lt.qmin(is))then >*/
	if (bnelem_1.q1[is - 1] < bnrslt_1.qmin[is - 1]) {
/* SOURCE ntmatrix.for:860 */
/*<       qmin(is)=q1(is) >*/
	    bnrslt_1.qmin[is - 1] = bnelem_1.q1[is - 1];
/* SOURCE ntmatrix.for:861 */
/*<       tqmin(is)=jtime >*/
	    bnrslt_1.tqmin[is - 1] = *jtime;
/* SOURCE ntmatrix.for:862 */
/*<       endif >*/
	}
/*       Find maximum elevation */
/* SOURCE ntmatrix.for:865 */
/*<       temp=y1(is)+zvec(is) >*/
	temp = static_cast<double>(bnelem_1.y1[is - 1]) + bnelem_1.zvec[is - 1];
/* SOURCE ntmatrix.for:866 */
/*<       if(temp.gt.zmax(is))then >*/
	if (temp > bnrslt_1.zmax[is - 1]) {
/* SOURCE ntmatrix.for:867 */
/*<       zmax(is)=temp >*/
	    bnrslt_1.zmax[is - 1] = temp;
/* SOURCE ntmatrix.for:868 */
/*<       tzmax(is)=jtime >*/
	    bnrslt_1.tzmax[is - 1] = *jtime;
/*         Check  for associated values */
/* SOURCE ntmatrix.for:870 */
/*<       if(tostore(unn).gt.0)then >*/
	    if (enrslt_1.tostore[unn - 1] > 0) {
/*           They exist!  Store values */
/* SOURCE ntmatrix.for:872 */
/*<       zstore(tostore(unn))=ze(othernode(unn))+ye1(othernode(unn)) >*/
		enrslt_1.zstore[enrslt_1.tostore[unn - 1] - 1] = static_cast<double>(enelem_1.ze[
			enrslt_1.othernode[unn - 1] - 1]) + enelem_1.ye1[
			enrslt_1.othernode[unn - 1] - 1];
/* SOURCE ntmatrix.for:874 */
/*<       qstore(tostore(unn))=qe1(flownode(unn)) >*/
		enrslt_1.qstore[enrslt_1.tostore[unn - 1] - 1] = enelem_1.qe1[
			enrslt_1.flownode[unn - 1] - 1];
/* SOURCE ntmatrix.for:875 */
/*<       endif >*/
	    }
/* SOURCE ntmatrix.for:876 */
/*<       endif >*/
	}
/*       Do downstream exterior node */
/*       Find maximum flow */
/* SOURCE ntmatrix.for:880 */
/*<       if(q1(ie).gt.qmax(ie))then >*/
	if (bnelem_1.q1[ie - 1] > bnrslt_1.qmax[ie - 1]) {
/* SOURCE ntmatrix.for:881 */
/*<       qmax(ie)=q1(ie) >*/
	    bnrslt_1.qmax[ie - 1] = bnelem_1.q1[ie - 1];
/* SOURCE ntmatrix.for:882 */
/*<       tqmax(ie)=jtime >*/
	    bnrslt_1.tqmax[ie - 1] = *jtime;
/* SOURCE ntmatrix.for:883 */
/*<       endif >*/
	}
/*       Find maximum absolute value of velocity */
/* SOURCE ntmatrix.for:886 */
/*<       v=abs(q1(ie)/a2(ie)) >*/
	v = (feq_gen_r_d_1 = static_cast<double>(bnelem_1.q1[ie - 1]) / bnelem_1.a2[ie - 1], dabs(feq_gen_r_d_1));
/* SOURCE ntmatrix.for:887 */
/*<       vmax(ie)=max(v,vmax(ie)) >*/
/* Computing MAX */
	feq_gen_r_d_1 = v, feq_gen_r_d_2 = bnrslt_1.vmax[ie - 1];
	bnrslt_1.vmax[ie - 1] = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/*     Find minimum flow */
/* SOURCE ntmatrix.for:890 */
/*<       if(q1(ie).lt.qmin(ie))then >*/
	if (bnelem_1.q1[ie - 1] < bnrslt_1.qmin[ie - 1]) {
/* SOURCE ntmatrix.for:891 */
/*<       qmin(ie)=q1(ie) >*/
	    bnrslt_1.qmin[ie - 1] = bnelem_1.q1[ie - 1];
/* SOURCE ntmatrix.for:892 */
/*<       tqmin(ie)=jtime >*/
	    bnrslt_1.tqmin[ie - 1] = *jtime;
/* SOURCE ntmatrix.for:893 */
/*<       endif >*/
	}
/*       Find maximum elevation */
/* SOURCE ntmatrix.for:896 */
/*<       temp=y1(ie)+zvec(ie) >*/
	temp = static_cast<double>(bnelem_1.y1[ie - 1]) + bnelem_1.zvec[ie - 1];
/* SOURCE ntmatrix.for:897 */
/*<       if(temp.gt.zmax(ie))then >*/
	if (temp > bnrslt_1.zmax[ie - 1]) {
/* SOURCE ntmatrix.for:898 */
/*<       zmax(ie)=temp >*/
	    bnrslt_1.zmax[ie - 1] = temp;
/* SOURCE ntmatrix.for:899 */
/*<       tzmax(ie)=jtime >*/
	    bnrslt_1.tzmax[ie - 1] = *jtime;
/*         Check node for associated values */
/* SOURCE ntmatrix.for:902 */
/*<       if(tostore(dnn).gt.0)then >*/
	    if (enrslt_1.tostore[dnn - 1] > 0) {
/*           They exist!  Store values */
/* SOURCE ntmatrix.for:904 */
/*<       zstore(tostore(dnn))=ze(othernode(dnn))+ye1(othernode(dnn)) >*/
		enrslt_1.zstore[enrslt_1.tostore[dnn - 1] - 1] = static_cast<double>(enelem_1.ze[
			enrslt_1.othernode[dnn - 1] - 1]) + enelem_1.ye1[
			enrslt_1.othernode[dnn - 1] - 1];
/* SOURCE ntmatrix.for:906 */
/*<       qstore(tostore(dnn))=qe1(flownode(dnn)) >*/
		enrslt_1.qstore[enrslt_1.tostore[dnn - 1] - 1] = enelem_1.qe1[
			enrslt_1.flownode[dnn - 1] - 1];
/* SOURCE ntmatrix.for:907 */
/*<       endif >*/
	    }
/* SOURCE ntmatrix.for:908 */
/*<       endif >*/
	}
/* SOURCE ntmatrix.for:911 */
/*<       do240i=is+1,ie-1 >*/
	feq_gen_i_d_2 = ie - 1;
	for (feq_gen_i_d_ = is + 1; feq_gen_i_d_ <= feq_gen_i_d_2; ++feq_gen_i_d_) {
/*         Find maximum flow */
/* SOURCE ntmatrix.for:913 */
/*<       if(q1(i).gt.qmax(i))then >*/
	    if (bnelem_1.q1[feq_gen_i_d_ - 1] > bnrslt_1.qmax[feq_gen_i_d_ - 1]) {
/* SOURCE ntmatrix.for:914 */
/*<       qmax(i)=q1(i) >*/
		bnrslt_1.qmax[feq_gen_i_d_ - 1] = bnelem_1.q1[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:915 */
/*<       tqmax(i)=jtime >*/
		bnrslt_1.tqmax[feq_gen_i_d_ - 1] = *jtime;
/* SOURCE ntmatrix.for:916 */
/*<       endif >*/
	    }
/*         Find maximum absolute value of velocity */
/* SOURCE ntmatrix.for:919 */
/*<       v=abs(q1(i)/a2(i)) >*/
	    v = (feq_gen_r_d_1 = static_cast<double>(bnelem_1.q1[feq_gen_i_d_ - 1]) / bnelem_1.a2[feq_gen_i_d_ - 1], dabs(
		    feq_gen_r_d_1));
/* SOURCE ntmatrix.for:920 */
/*<       vmax(i)=max(v,vmax(i)) >*/
/* Computing MAX */
	    feq_gen_r_d_1 = v, feq_gen_r_d_2 = bnrslt_1.vmax[feq_gen_i_d_ - 1];
	    bnrslt_1.vmax[feq_gen_i_d_ - 1] = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/*         Find minimum flow */
/* SOURCE ntmatrix.for:923 */
/*<       if(q1(i).lt.qmin(i))then >*/
	    if (bnelem_1.q1[feq_gen_i_d_ - 1] < bnrslt_1.qmin[feq_gen_i_d_ - 1]) {
/* SOURCE ntmatrix.for:924 */
/*<       qmin(i)=q1(i) >*/
		bnrslt_1.qmin[feq_gen_i_d_ - 1] = bnelem_1.q1[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:925 */
/*<       tqmin(i)=jtime >*/
		bnrslt_1.tqmin[feq_gen_i_d_ - 1] = *jtime;
/* SOURCE ntmatrix.for:926 */
/*<       endif >*/
	    }
/*         Find maximum elevation */
/* SOURCE ntmatrix.for:929 */
/*<       temp=y1(i)+zvec(i) >*/
	    temp = static_cast<double>(bnelem_1.y1[feq_gen_i_d_ - 1]) + bnelem_1.zvec[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:930 */
/*<       if(temp.gt.zmax(i))then >*/
	    if (temp > bnrslt_1.zmax[feq_gen_i_d_ - 1]) {
/* SOURCE ntmatrix.for:931 */
/*<       zmax(i)=temp >*/
		bnrslt_1.zmax[feq_gen_i_d_ - 1] = temp;
/* SOURCE ntmatrix.for:932 */
/*<       tzmax(i)=jtime >*/
		bnrslt_1.tzmax[feq_gen_i_d_ - 1] = *jtime;
/* SOURCE ntmatrix.for:933 */
/*<       endif >*/
	    }
/* SOURCE ntmatrix.for:934 */
/*<   240 continue >*/
/* L240: */
	}
/* SOURCE ntmatrix.for:935 */
/*<   242 continue >*/
/* L242: */
    }
/*     Find maxima for free nodes */
/* SOURCE ntmatrix.for:939 */
/*<       do245i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ntmatrix.for:940 */
/*<       if(exnodt(3,i).le.0)then >*/
	if (exnodt[feq_gen_i_d_ * 9 + 3] <= 0) {
/* SOURCE ntmatrix.for:941 */
/*<       if(qe1(i).gt.fnqmax(i))then >*/
	    if (enelem_1.qe1[feq_gen_i_d_ - 1] > enrslt_1.fnqmax[feq_gen_i_d_ - 1]) {
/* SOURCE ntmatrix.for:942 */
/*<       fnqmax(i)=qe1(i) >*/
		enrslt_1.fnqmax[feq_gen_i_d_ - 1] = enelem_1.qe1[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:943 */
/*<       ftqmax(i)=jtime >*/
		enrslt_1.ftqmax[feq_gen_i_d_ - 1] = *jtime;
/* SOURCE ntmatrix.for:944 */
/*<       endif >*/
	    }
/* SOURCE ntmatrix.for:945 */
/*<       if(qe1(i).lt.fnqmin(i))then >*/
	    if (enelem_1.qe1[feq_gen_i_d_ - 1] < enrslt_1.fnqmin[feq_gen_i_d_ - 1]) {
/* SOURCE ntmatrix.for:946 */
/*<       fnqmin(i)=qe1(i) >*/
		enrslt_1.fnqmin[feq_gen_i_d_ - 1] = enelem_1.qe1[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:947 */
/*<       ftqmin(i)=jtime >*/
		enrslt_1.ftqmin[feq_gen_i_d_ - 1] = *jtime;
/* SOURCE ntmatrix.for:948 */
/*<       endif >*/
	    }
/* SOURCE ntmatrix.for:950 */
/*<       temp=ye2(i)+ze(i) >*/
	    temp = static_cast<double>(enelem_1.ye2[feq_gen_i_d_ - 1]) + enelem_1.ze[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:951 */
/*<       if(temp.gt.fnzmax(i))then >*/
	    if (temp > enrslt_1.fnzmax[feq_gen_i_d_ - 1]) {
/* SOURCE ntmatrix.for:952 */
/*<       fnzmax(i)=temp >*/
		enrslt_1.fnzmax[feq_gen_i_d_ - 1] = temp;
/* SOURCE ntmatrix.for:953 */
/*<       ftzmax(i)=jtime >*/
		enrslt_1.ftzmax[feq_gen_i_d_ - 1] = *jtime;
/*           Check  for associated values */
/* SOURCE ntmatrix.for:955 */
/*<       if(tostore(i).gt.0)then >*/
		if (enrslt_1.tostore[feq_gen_i_d_ - 1] > 0) {
/*             They exist!  Store values */
/* SOURCE ntmatrix.for:957 */
/*<       zstore(tostore(i))=ze(othernode(i))+ye1(othernode(i)) >*/
		    enrslt_1.zstore[enrslt_1.tostore[feq_gen_i_d_ - 1] - 1] = 
			    static_cast<double>(enelem_1.ze[enrslt_1.othernode[feq_gen_i_d_ - 1] - 1]) + 
			    enelem_1.ye1[enrslt_1.othernode[feq_gen_i_d_ - 1] - 1];
/* SOURCE ntmatrix.for:958 */
/*<       qstore(tostore(i))=qe1(flownode(i)) >*/
		    enrslt_1.qstore[enrslt_1.tostore[feq_gen_i_d_ - 1] - 1] = 
			    enelem_1.qe1[enrslt_1.flownode[feq_gen_i_d_ - 1] - 1];
/* SOURCE ntmatrix.for:959 */
/*<       endif >*/
		}
/* SOURCE ntmatrix.for:962 */
/*<       endif >*/
	    }
/* SOURCE ntmatrix.for:963 */
/*<       endif >*/
	}
/* SOURCE ntmatrix.for:964 */
/*<   245 continue >*/
/* L245: */
    }
/*     Find the branch ponding volume and its maximum if ponding is */
/*     possible */
/* SOURCE ntmatrix.for:969 */
/*<       if(pndflg.eq.1)then >*/
    if (miscon_1.pndflg == 1) {
/* SOURCE ntmatrix.for:971 */
/*<       do500i=1,nbra >*/
	feq_gen_i_d_1 = *nbra;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ntmatrix.for:972 */
/*<       sum=0.0 >*/
	    sum = (float)0.;
/* SOURCE ntmatrix.for:973 */
/*<       do400j=brpt(3,i),brpt(4,i) >*/
	    feq_gen_i_d_2 = brpt[(feq_gen_i_d_ << 3) + 4];
	    for (j = brpt[(feq_gen_i_d_ << 3) + 3]; j <= feq_gen_i_d_2; ++j) {
/* SOURCE ntmatrix.for:974 */
/*<       sum=sum+pond2(j) >*/
		sum += bnpond_1.pond2[j - 1];
/* SOURCE ntmatrix.for:975 */
/*<   400 continue >*/
/* L400: */
	    }
/* SOURCE ntmatrix.for:976 */
/*<       bpond(i)=sum >*/
	    bnpond_1.bpond[feq_gen_i_d_ - 1] = sum;
/* SOURCE ntmatrix.for:977 */
/*<       if(sum.gt.bpmax(i))bpmax(i)=sum >*/
	    if (sum > bnpond_1.bpmax[feq_gen_i_d_ - 1]) {
		bnpond_1.bpmax[feq_gen_i_d_ - 1] = sum;
	    }
/* SOURCE ntmatrix.for:978 */
/*<   500 continue >*/
/* L500: */
	}
/* SOURCE ntmatrix.for:979 */
/*<       endif >*/
    }
/* SOURCE ntmatrix.for:981 */
/*<       return >*/
    return 0;
/* SOURCE ntmatrix.for:982 */
/*<       end >*/
} /* fmxmn_ */




/* SOURCE ntmatrix.for:986 */
/*<       subroutinemakcor(nex,nbra,nbn,stdout,exnodt,brpt,lambda,qchop) >*/
/* Subroutine */ int makcor_(integer *nex, integer *nbra, integer *nbn, 
	integer *stdout, integer *feq_storage_exnodt, integer *feq_storage_brpt, real *lambda, real *
	qchop)
{
    /* Initialized data */

    static real mrd = (float).5;

    /* Format strings */
    static char fmt_50[] = "(\002 VALUE BELOW MINIMUM AT EXT. NODE=\002,a5\
,\002 VALUE=\002,f10.4,\002 MINIMUM=\002,f10.4)";
    static char fmt_52[] = "(\002 NEGATIVE DEPTH AT:\002,i4,\002:\002,i6,\
\002 DEPTH=\002,f10.4)";
    static char fmt_56[] = "(\002 *WRN:37* TABLE OVERFLOW AT EXT. NODE=\002,\
a5,\002 ARGUMENT=\002,f10.4)";
    static char fmt_58[] = "(\002 *WRN:38* TABLE OVERFLOW AT:\002,i4,\002\
:\002,i6,\002 ARGUMENT=\002,f10.2)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5];

    /* Builtin functions */
    double r_sign(real *, real *);
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    integer feq_gen_i_d_;
    real dy, dyt, frac;
    integer ibra, node;
    extern /* Subroutine */ int fbrnd_(integer *, integer *, integer *, 
	    integer *, integer *, integer *);
    extern integer getusb_(integer *);
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__77 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__78 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__81 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__82 = { 0, 0, 0, fmt_58, 0 };


/*     + + + PURPOSE + + + */
/*     Make corrections such that no area or depth will be negative. */
/*     Decrease in depth is limited so that negative depth */
/*     does not result. */
/* SOURCE ntmatrix.for:994 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntmatrix.for:997 */
/*<       integerstdout,nbn,nbra,nex >*/
/* SOURCE ntmatrix.for:998 */
/*<       integerbrpt(8,nbra),exnodt(9,nex) >*/
/* SOURCE ntmatrix.for:999 */
/*<       reallambda,qchop >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     NEX    - number of exterior nodes in the model */
/*     NBRA   - number of branches in the model */
/*     NBN    - total number on nodes on branches in the model */
/*     STDOUT   - Fortran unit number for user output and messages */
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
/*     LAMBDA - factor that defines the partial Newton correction */
/*     QCHOP  - chopping value for output of flow */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntmatrix.for:1034 */
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
/* INCLUDE ntmatrix.for:1035 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE ntmatrix.for:1036 */
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
/* INCLUDE ntmatrix.for:1037 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE ntmatrix.for:1038 */
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
/*     + + + SAVED VALUES + + + */
/* SOURCE ntmatrix.for:1041 */
/*<       realmrd >*/
/* SOURCE ntmatrix.for:1042 */
/*<       savemrd >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ntmatrix.for:1045 */
/*<       integeri,ibra,node >*/
/* SOURCE ntmatrix.for:1046 */
/*<       realdy,dyt,frac >*/
/*     + + + INTRINSICS + + + */
/* SOURCE ntmatrix.for:1049 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ntmatrix.for:1052 */
/*<       integergetusb >*/
/* SOURCE ntmatrix.for:1053 */
/*<       charactergetusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntmatrix.for:1056 */
/*<       externalfbrnd,getusb,getusn >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ntmatrix.for:1059 */
/*<       datamrd/0.5/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    /* Function Body */
/* SOURCE ntmatrix.for:1062 */
/*<    50  >*/
/* L50: */
/* SOURCE ntmatrix.for:1064 */
/*<    52 format(' NEGATIVE DEPTH AT:',i4,':',i6,' DEPTH=',f10.4) >*/
/* L52: */
/* SOURCE ntmatrix.for:1065 */
/*<    56  >*/
/* L56: */
/* SOURCE ntmatrix.for:1067 */
/*<    58  >*/
/* L58: */
/* *********************************************************************** */
/* SOURCE ntmatrix.for:1070 */
/*<       frac=lambda >*/
    frac = *lambda;
/* SOURCE ntmatrix.for:1072 */
/*<       do200i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/*       DO ONLY FREE NODES */
/* SOURCE ntmatrix.for:1074 */
/*<       if(exnodt(3,i).le.0)then >*/
	if (exnodt[feq_gen_i_d_ * 9 + 3] <= 0) {
/* SOURCE ntmatrix.for:1075 */
/*<       dy=encory(i) >*/
	    dy = enothr_1.encory[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:1076 */
/*<       dyt=mrd*ye3(i) >*/
	    dyt = static_cast<double>(mrd) * enelem_1.ye3[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:1077 */
/*<       if(abs(dy).gt.dyt)then >*/
	    if (dabs(dy) > dyt) {
/* SOURCE ntmatrix.for:1078 */
/*<       dy=sign(dyt,dy) >*/
		dy = r_sign(&dyt, &dy);
/* SOURCE ntmatrix.for:1079 */
/*<       endif >*/
	    }
/* SOURCE ntmatrix.for:1080 */
/*<       ye2(i)=ye3(i)+frac*dy >*/
	    enelem_1.ye2[feq_gen_i_d_ - 1] = static_cast<double>(enelem_1.ye3[feq_gen_i_d_ - 1]) + static_cast<double>(frac) * dy;
/* SOURCE ntmatrix.for:1081 */
/*<       if(ye2(i).lt.enminy(i))then >*/
	    if (enelem_1.ye2[feq_gen_i_d_ - 1] < enothr_1.enminy[feq_gen_i_d_ - 1]) {
/* SOURCE ntmatrix.for:1082 */
/*<       write(stdout,50)getusn(i),ye2(i),enminy(i) >*/
		feq_gen_io_d__77.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__77);
		getusn_(feq_gen_ch_d_2, (ftnlen)5, &feq_gen_i_d_);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, (char *)&enelem_1.ye2[feq_gen_i_d_ - 1], (ftnlen)sizeof(
			real));
		do_fio(&feq_gen_c_d_1, (char *)&enothr_1.enminy[feq_gen_i_d_ - 1], (ftnlen)
			sizeof(real));
		e_wsfe();
/* SOURCE ntmatrix.for:1083 */
/*<       ye2(i)=0.5*(ye3(i)+enminy(i)) >*/
		enelem_1.ye2[feq_gen_i_d_ - 1] = static_cast<double>((static_cast<double>(enelem_1.ye3[feq_gen_i_d_ - 1]) + 
			enothr_1.enminy[feq_gen_i_d_ - 1])) * (float).5;
/* SOURCE ntmatrix.for:1084 */
/*<       elseif(ye2(i).gt.enmaxy(i))then >*/
	    } else if (enelem_1.ye2[feq_gen_i_d_ - 1] > enothr_1.enmaxy[feq_gen_i_d_ - 1]) {
/* SOURCE ntmatrix.for:1085 */
/*<       write(stdout,56)getusn(i),ye2(i) >*/
		feq_gen_io_d__78.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__78);
		getusn_(feq_gen_ch_d_2, (ftnlen)5, &feq_gen_i_d_);
		s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		do_fio(&feq_gen_c_d_1, (char *)&enelem_1.ye2[feq_gen_i_d_ - 1], (ftnlen)sizeof(
			real));
		e_wsfe();
/* SOURCE ntmatrix.for:1086 */
/*<       ye2(i)=0.5*(ye3(i)+enmaxy(i)) >*/
		enelem_1.ye2[feq_gen_i_d_ - 1] = static_cast<double>((static_cast<double>(enelem_1.ye3[feq_gen_i_d_ - 1]) + 
			enothr_1.enmaxy[feq_gen_i_d_ - 1])) * (float).5;
/* SOURCE ntmatrix.for:1087 */
/*<       endif >*/
	    }
/* SOURCE ntmatrix.for:1089 */
/*<       qe2(i)=qe3(i)+frac*encorq(i) >*/
	    enelem_1.qe2[feq_gen_i_d_ - 1] = static_cast<double>(enelem_1.qe3[feq_gen_i_d_ - 1]) + static_cast<double>(frac) * 
		    enothr_1.encorq[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:1090 */
/*<       if(abs(qe2(i)).le.qchop)qe2(i)=0.0 >*/
	    if ((feq_gen_r_d_1 = enelem_1.qe2[feq_gen_i_d_ - 1], dabs(feq_gen_r_d_1)) <= *qchop) {
		enelem_1.qe2[feq_gen_i_d_ - 1] = (float)0.;
	    }
/* SOURCE ntmatrix.for:1091 */
/*<       endif >*/
	}
/* SOURCE ntmatrix.for:1092 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE ntmatrix.for:1094 */
/*<       do300i=1,nbn >*/
    feq_gen_i_d_1 = *nbn;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ntmatrix.for:1096 */
/*<       dy=bncory(i) >*/
	dy = bnothr_1.bncory[feq_gen_i_d_ - 1];
/*       Limit the relative change in depth */
/* SOURCE ntmatrix.for:1098 */
/*<       dyt=mrd*y3(i) >*/
	dyt = static_cast<double>(mrd) * bnelem_1.y3[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:1099 */
/*<       if(abs(dy).gt.dyt)then >*/
	if (dabs(dy) > dyt) {
/* SOURCE ntmatrix.for:1100 */
/*<       dy=sign(dyt,dy) >*/
	    dy = r_sign(&dyt, &dy);
/* SOURCE ntmatrix.for:1101 */
/*<       endif >*/
	}
/* SOURCE ntmatrix.for:1104 */
/*<       y2(i)=y3(i)+frac*dy >*/
	bnelem_1.y2[feq_gen_i_d_ - 1] = static_cast<double>(bnelem_1.y3[feq_gen_i_d_ - 1]) + static_cast<double>(frac) * dy;
/* SOURCE ntmatrix.for:1106 */
/*<       if(y2(i).le.0.0)then >*/
	if (bnelem_1.y2[feq_gen_i_d_ - 1] <= (float)0.) {
/* SOURCE ntmatrix.for:1107 */
/*<       y2(i)=0.95*y3(i) >*/
	    bnelem_1.y2[feq_gen_i_d_ - 1] = static_cast<double>(bnelem_1.y3[feq_gen_i_d_ - 1]) * (float).95;
/* SOURCE ntmatrix.for:1108 */
/*<       callfbrnd(i,nbra,brpt,stdout,ibra,node) >*/
	    fbrnd_(&feq_gen_i_d_, nbra, &brpt[9], stdout, &ibra, &node);
/* SOURCE ntmatrix.for:1111 */
/*<       write(stdout,52)getusb(ibra),node,y3(i) >*/
	    feq_gen_io_d__81.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__81);
	    feq_gen_i_d_2 = getusb_(&ibra);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_2, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&node, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&bnelem_1.y3[feq_gen_i_d_ - 1], (ftnlen)sizeof(real))
		    ;
	    e_wsfe();
/* SOURCE ntmatrix.for:1112 */
/*<       elseif(y2(i).gt.bnmaxy(i))then >*/
	} else if (bnelem_1.y2[feq_gen_i_d_ - 1] > bnothr_1.bnmaxy[feq_gen_i_d_ - 1]) {
/* SOURCE ntmatrix.for:1113 */
/*<       callfbrnd(i,nbra,brpt,stdout,ibra,node) >*/
	    fbrnd_(&feq_gen_i_d_, nbra, &brpt[9], stdout, &ibra, &node);
/* SOURCE ntmatrix.for:1116 */
/*<       write(stdout,58)getusb(ibra),node,y2(i) >*/
	    feq_gen_io_d__82.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__82);
	    feq_gen_i_d_2 = getusb_(&ibra);
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_i_d_2, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&node, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, (char *)&bnelem_1.y2[feq_gen_i_d_ - 1], (ftnlen)sizeof(real))
		    ;
	    e_wsfe();
/* SOURCE ntmatrix.for:1117 */
/*<       y2(i)=0.5*(y3(i)+bnmaxy(i)) >*/
	    bnelem_1.y2[feq_gen_i_d_ - 1] = static_cast<double>((static_cast<double>(bnelem_1.y3[feq_gen_i_d_ - 1]) + bnothr_1.bnmaxy[
		    feq_gen_i_d_ - 1])) * (float).5;
/* SOURCE ntmatrix.for:1118 */
/*<       endif >*/
	}
/* SOURCE ntmatrix.for:1119 */
/*<       q2(i)=q3(i)+frac*bncorq(i) >*/
	bnelem_1.q2[feq_gen_i_d_ - 1] = static_cast<double>(bnelem_1.q3[feq_gen_i_d_ - 1]) + static_cast<double>(frac) * bnothr_1.bncorq[
		feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:1121 */
/*<   300 continue >*/
/* L300: */
    }
/* SOURCE ntmatrix.for:1123 */
/*<       return >*/
    return 0;
/* SOURCE ntmatrix.for:1124 */
/*<       end >*/
} /* makcor_ */




/* SOURCE ntmatrix.for:1128 */
/*<       subroutinerplset(dt,fac,nbn,nex) >*/
/* Subroutine */ int rplset_(doublereal *dt, real *fac, integer *nbn, integer 
	*nex)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Local variables */
    integer feq_gen_i_d_;

/*     + + + PURPOSE + + + */
/*     Replace set 1 with set 2 values for next time step. Also */
/*     compute the slopes for estimation at the same time. */
/* SOURCE ntmatrix.for:1134 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntmatrix.for:1137 */
/*<       integernbn,nex >*/
/* SOURCE ntmatrix.for:1138 */
/*<       realfac >*/
/* SOURCE ntmatrix.for:1139 */
/*<       real*8dt >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     DT     - time step in seconds */
/*     FAC    - factor controlling the extrapolation vectors */
/*     NBN    - total number on nodes on branches in the model */
/*     NEX    - number of exterior nodes in the model */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ntmatrix.for:1148 */
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
/* INCLUDE ntmatrix.for:1149 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE ntmatrix.for:1150 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE ntmatrix.for:1151 */
/* ********************************************************************** */
/* SOURCE bnpond.cmn:3 */
/*<       common/bnpond/coefin,pond1,pond2,ycut,bpond,bpmax >*/
/* SOURCE bnpond.cmn:5 */
/*<        >*/
/* ********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ntmatrix.for:1154 */
/*<       integeri >*/
/* *********************************************************************** */
/*     I) INTERIOR NODES */
/* SOURCE ntmatrix.for:1158 */
/*<       do210i=1,nbn >*/
    feq_gen_i_d_1 = *nbn;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ntmatrix.for:1159 */
/*<       my(i)=fac*(y2(i)-y1(i))/dt >*/
	bnelem_1.my[feq_gen_i_d_ - 1] = static_cast<double>(*fac) * (static_cast<double>(bnelem_1.y2[feq_gen_i_d_ - 1]) - bnelem_1.y1[feq_gen_i_d_ 
		- 1]) / *dt;
/* SOURCE ntmatrix.for:1160 */
/*<       a1(i)=a2(i) >*/
	bnelem_1.a1[feq_gen_i_d_ - 1] = bnelem_1.a2[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:1161 */
/*<       mq(i)=fac*(q2(i)-q1(i))/dt >*/
	bnelem_1.mq[feq_gen_i_d_ - 1] = static_cast<double>(*fac) * (static_cast<double>(bnelem_1.q2[feq_gen_i_d_ - 1]) - bnelem_1.q1[feq_gen_i_d_ 
		- 1]) / *dt;
/* SOURCE ntmatrix.for:1162 */
/*<       q1(i)=q2(i) >*/
	bnelem_1.q1[feq_gen_i_d_ - 1] = bnelem_1.q2[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:1163 */
/*<       t1(i)=t2(i) >*/
	bnelem_1.t1[feq_gen_i_d_ - 1] = bnelem_1.t2[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:1164 */
/*<       y1(i)=y2(i) >*/
	bnelem_1.y1[feq_gen_i_d_ - 1] = bnelem_1.y2[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:1165 */
/*<       k1(i)=k2(i) >*/
	bnelem_1.k1[feq_gen_i_d_ - 1] = bnelem_1.k2[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:1166 */
/*<       b1(i)=b2(i) >*/
	bnelem_1.b1[feq_gen_i_d_ - 1] = bnelem_1.b2[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:1167 */
/*<       pond1(i)=pond2(i) >*/
	bnpond_1.pond1[feq_gen_i_d_ - 1] = bnpond_1.pond2[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:1168 */
/*<       ma1(i)=ma2(i) >*/
	bnelem_1.ma1[feq_gen_i_d_ - 1] = bnelem_1.ma2[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:1169 */
/*<       mq1(i)=mq2(i) >*/
	bnelem_1.mq1[feq_gen_i_d_ - 1] = bnelem_1.mq2[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:1170 */
/*<   210 continue >*/
/* L210: */
    }
/*     II) EXTERIOR NODES */
/* SOURCE ntmatrix.for:1174 */
/*<       do220i=1,nex >*/
    feq_gen_i_d_1 = *nex;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ntmatrix.for:1175 */
/*<       mqe(i)=fac*(qe2(i)-qe1(i))/dt >*/
	enelem_1.mqe[feq_gen_i_d_ - 1] = static_cast<double>(*fac) * (static_cast<double>(enelem_1.qe2[feq_gen_i_d_ - 1]) - enelem_1.qe1[
		feq_gen_i_d_ - 1]) / *dt;
/* SOURCE ntmatrix.for:1176 */
/*<       qe1(i)=qe2(i) >*/
	enelem_1.qe1[feq_gen_i_d_ - 1] = enelem_1.qe2[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:1177 */
/*<       mye(i)=fac*(ye2(i)-ye1(i))/dt >*/
	enelem_1.mye[feq_gen_i_d_ - 1] = static_cast<double>(*fac) * (static_cast<double>(enelem_1.ye2[feq_gen_i_d_ - 1]) - enelem_1.ye1[
		feq_gen_i_d_ - 1]) / *dt;
/* SOURCE ntmatrix.for:1178 */
/*<       ye1(i)=ye2(i) >*/
	enelem_1.ye1[feq_gen_i_d_ - 1] = enelem_1.ye2[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:1179 */
/*<       te1(i)=te2(i) >*/
	enelem_1.te1[feq_gen_i_d_ - 1] = enelem_1.te2[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:1180 */
/*<       ae1(i)=ae2(i) >*/
	enelem_1.ae1[feq_gen_i_d_ - 1] = enelem_1.ae2[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:1181 */
/*<   220 continue >*/
/* L220: */
    }
/* SOURCE ntmatrix.for:1183 */
/*<       return >*/
    return 0;
/* SOURCE ntmatrix.for:1184 */
/*<       end >*/
} /* rplset_ */




/* SOURCE ntmatrix.for:1188 */
/*<       subroutinerstnzd(nbra,brpt) >*/
/* Subroutine */ int rstnzd_(integer *nbra, integer *feq_storage_brpt)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1, feq_gen_r_d_2;

    /* Local variables */
    integer feq_gen_i_d_, j;
    real p;
    integer fn, ln;
    real ym, yhaf, yone;

/*     + + + PURPOSE + + + */
/*     Reset the weight for the integrals along the channel. The value is */
/*     set by the current depth.   The weight as computed assumes that */
/*     the flow is downstream.  The weights are set at the start of */
/*     the time step and held constant throughout the time step. */
/*     The weight applies to the new time point. */
/* SOURCE ntmatrix.for:1197 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ntmatrix.for:1200 */
/*<       integernbra >*/
/* SOURCE ntmatrix.for:1201 */
/*<       integerbrpt(8,nbra) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
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
/* INCLUDE ntmatrix.for:1217 */
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
/* INCLUDE ntmatrix.for:1218 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE ntmatrix.for:1219 */
/*     COMMON FOR NEAR ZERO DEPTH CONTROL */
/* SOURCE nzdcom.cmn:3 */
/*<       common/nzdcom/nzdtyp,yatone,yathaf >*/
/* SOURCE nzdcom.cmn:5 */
/*<       integernzdtyp(mnbra) >*/
/* SOURCE nzdcom.cmn:7 */
/*<       realyatone(mnbra),yathaf(mnbra) >*/
/* INCLUDE ntmatrix.for:1220 */
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
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE ntmatrix.for:1223 */
/*<       realwmax >*/
/* SOURCE ntmatrix.for:1224 */
/*<       parameter(wmax=0.99) >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ntmatrix.for:1227 */
/*<       integerfn,i,j,ln >*/
/* SOURCE ntmatrix.for:1228 */
/*<       realp,yhaf,ym,yone >*/
/*     + + + INTRINSICS + + + */
/* SOURCE ntmatrix.for:1231 */
/*<       intrinsicmin >*/
/* *********************************************************************** */
/* SOURCE ntmatrix.for:1233 */
/*<       do110i=1,nbra >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    /* Function Body */
    feq_gen_i_d_1 = *nbra;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ntmatrix.for:1234 */
/*<       if(geqvec(i).eq.2.or.geqvec(i).eq.4)then >*/
	if (bnothr_1.geqvec[feq_gen_i_d_ - 1] == 2 || bnothr_1.geqvec[feq_gen_i_d_ - 1] == 4) {
/* SOURCE ntmatrix.for:1235 */
/*<       fn=brpt(3,i)+1 >*/
	    fn = brpt[(feq_gen_i_d_ << 3) + 3] + 1;
/* SOURCE ntmatrix.for:1236 */
/*<       ln=brpt(4,i) >*/
	    ln = brpt[(feq_gen_i_d_ << 3) + 4];
/* SOURCE ntmatrix.for:1237 */
/*<       yone=yatone(i) >*/
	    yone = nzdcom_1.yatone[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:1238 */
/*<       yhaf=yathaf(i) >*/
	    yhaf = nzdcom_1.yathaf[feq_gen_i_d_ - 1];
/* SOURCE ntmatrix.for:1239 */
/*<       do100j=fn,ln >*/
	    feq_gen_i_d_2 = ln;
	    for (j = fn; j <= feq_gen_i_d_2; ++j) {
/*           RESET THE WEIGHT FOR THE INITIAL TIME LINE. */
/* SOURCE ntmatrix.for:1242 */
/*<       wxvec1(j)=wxvec2(j) >*/
		bnelem_1.wxvec1[j - 1] = bnelem_1.wxvec2[j - 1];
/*           DEFINE THE WEIGHT FACTOR FOR EACH ELEMENT AT THE NEW TIME */
/*           LINE.  THE WEIGHT IS SET AT THE START OF A TIME STEP AND */
/*           HELD CONSTANT THROUGH ALL ITERATIONS OF THE TIME STEP. */
/*           USE MINIMUM DEPTH IN THE ELEMENT TO DEFINE THE WEIGHT */
/*           BECAUSE THE WEIGHT IS FOR THE ELEMENT AND NOT FOR A NODE. */
/* SOURCE ntmatrix.for:1250 */
/*<       ym=min(y1(j-1),y1(j)) >*/
/* Computing MIN */
		feq_gen_r_d_1 = bnelem_1.y1[j - 2], feq_gen_r_d_2 = bnelem_1.y1[j - 1];
		ym = dmin(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE ntmatrix.for:1251 */
/*<       if(ym.ge.yhaf)then >*/
		if (ym >= yhaf) {
/* SOURCE ntmatrix.for:1252 */
/*<       wxvec2(j)=.5 >*/
		    bnelem_1.wxvec2[j - 1] = (float).5;
/* SOURCE ntmatrix.for:1253 */
/*<       elseif(ym.le.yone)then >*/
		} else if (ym <= yone) {
/* SOURCE ntmatrix.for:1254 */
/*<       wxvec2(j)=wmax >*/
		    bnelem_1.wxvec2[j - 1] = (float).99;
/* SOURCE ntmatrix.for:1255 */
/*<       else >*/
		} else {
/*             INTERPOLATION REQUIRED */
/* SOURCE ntmatrix.for:1257 */
/*<       p=(ym-yone)/(yhaf-yone) >*/
		    p = static_cast<double>((static_cast<double>(ym) - yone)) / (static_cast<double>(yhaf) - yone);
/* SOURCE ntmatrix.for:1258 */
/*<       if(nzdtyp(i).eq.0)then >*/
		    if (nzdcom_1.nzdtyp[feq_gen_i_d_ - 1] == 0) {
/*               LINEAR */
/* SOURCE ntmatrix.for:1260 */
/*<       wxvec2(j)=wmax+(.5-wmax)*p >*/
			bnelem_1.wxvec2[j - 1] = static_cast<double>(static_cast<double>(p) * (float)
				-.48999999999999999) + (float).99;
/* SOURCE ntmatrix.for:1261 */
/*<       else >*/
		    } else {
/*               CUBIC HERMITE WITH ZERO DERIVATIVES AT END POINTS */
/* SOURCE ntmatrix.for:1263 */
/*<       wxvec2(j)=wmax+(wmax-.5)*(p*p*(2*p-3)) >*/
			bnelem_1.wxvec2[j - 1] = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(p) * p) * (static_cast<double>(static_cast<double>(p) * 2) - 3)) * (float)
				.48999999999999999) + (float).99;
/* SOURCE ntmatrix.for:1264 */
/*<       endif >*/
		    }
/* SOURCE ntmatrix.for:1265 */
/*<       endif >*/
		}
/* SOURCE ntmatrix.for:1266 */
/*<   100 continue >*/
/* L100: */
	    }
/* SOURCE ntmatrix.for:1267 */
/*<       endif >*/
	}
/* SOURCE ntmatrix.for:1268 */
/*<   110 continue >*/
/* L110: */
    }
/* SOURCE ntmatrix.for:1270 */
/*<       return >*/
    return 0;
/* SOURCE ntmatrix.for:1271 */
/*<       end >*/
} /* rstnzd_ */




/* SOURCE ntmatrix.for:1275 */
/*<       subroutinerststa(mode,stdout,emc) >*/
/* Subroutine */ int rststa_(integer *mode, integer *stdout, integer *feq_storage_emc)
{
    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer j, code;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__94 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__95 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Reset the state variables in emc for code 5 & 6 based on MODE: */
/*       MODE = 1     current  <-- previous */
/*       MODE <> 1    previous <-- current */
/* SOURCE ntmatrix.for:1284 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE ntmatrix.for:1286 */
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
/* SOURCE ntmatrix.for:1289 */
/*<       integerstdout,mode >*/
/* SOURCE ntmatrix.for:1290 */
/*<       integeremc(mremc) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     MODE   - mode selection for resetting state */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ntmatrix.for:1298 */
/*<       integercode,j >*/
/*     + + + INTRINSICS + + + */
/* SOURCE ntmatrix.for:1301 */
/*<       intrinsicabs >*/
/* *********************************************************************** */
/*     SEARCH EMC FOR THE PROPER CODES */
/* SOURCE ntmatrix.for:1305 */
/*<       j=emc(1) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
    j = emc[1];
/* SOURCE ntmatrix.for:1306 */
/*<    10 continue >*/
L10:
/* SOURCE ntmatrix.for:1307 */
/*<       code=emc(j) >*/
    code = emc[j];
/* SOURCE ntmatrix.for:1308 */
/*<       if(code.eq.-1)return >*/
    if (code == -1) {
	return 0;
    }
/* SOURCE ntmatrix.for:1309 */
/*<        >*/
    switch (code) {
	case 1:  goto L2000;
	case 2:  goto L2;
	case 3:  goto L2000;
	case 4:  goto L2000;
	case 5:  goto L5;
	case 6:  goto L6;
	case 7:  goto L2000;
	case 8:  goto L2000;
	case 9:  goto L2000;
	case 10:  goto L2000;
	case 11:  goto L2000;
	case 12:  goto L2000;
	case 13:  goto L2000;
	case 14:  goto L2000;
	case 15:  goto L2000;
    }
/* SOURCE ntmatrix.for:1311 */
/*<       write(stdout,*)' *BUG:25* INVALID EMC CODE IN RSTSTA. CODE=',code >*/
    feq_gen_io_d__94.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__94);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:25* INVALID EMC CODE IN RSTSTA. CODE="), (
	    ftnlen)43);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE ntmatrix.for:1313 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntmatrix.for:1315 */
/*<     2 continue >*/
L2:
/* SOURCE ntmatrix.for:1316 */
/*<       j=j+emc(j+1) >*/
    j += emc[j + 1];
/* SOURCE ntmatrix.for:1317 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE ntmatrix.for:1318 */
/*<     5 continue >*/
L5:
/* SOURCE ntmatrix.for:1321 */
/*<       goto(100,200,300,400,500,600,700,800,900),emc(j+1) >*/
    switch (emc[j + 1]) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
	case 4:  goto L400;
	case 5:  goto L500;
	case 6:  goto L600;
	case 7:  goto L700;
	case 8:  goto L800;
	case 9:  goto L900;
    }
/* SOURCE ntmatrix.for:1323 */
/*<        >*/
    feq_gen_io_d__95.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__95);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:38* INVALID CODE 5 TYPE IN RSTSTA."), (ftnlen)
	    40);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" TYPE="), (ftnlen)6);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&emc[j + 1], (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE ntmatrix.for:1325 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntmatrix.for:1327 */
/*<   100 continue >*/
L100:
/*         EXPANSION-CONTRACTION */
/* SOURCE ntmatrix.for:1330 */
/*<       if(mode.eq.1)then >*/
    if (*mode == 1) {
/* SOURCE ntmatrix.for:1331 */
/*<       emc(j+8)=emc(j+12) >*/
	emc[j + 8] = emc[j + 12];
/* SOURCE ntmatrix.for:1332 */
/*<       else >*/
    } else {
/* SOURCE ntmatrix.for:1333 */
/*<       emc(j+12)=emc(j+8) >*/
	emc[j + 12] = emc[j + 8];
/* SOURCE ntmatrix.for:1334 */
/*<       endif >*/
    }
/* SOURCE ntmatrix.for:1335 */
/*<       j=j+cd5ty1 >*/
    j += 7;
/* SOURCE ntmatrix.for:1336 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE ntmatrix.for:1337 */
/*<   200 continue >*/
L200:
/* SOURCE ntmatrix.for:1338 */
/*<       j=j+cd5ty2 >*/
    j += 12;
/* SOURCE ntmatrix.for:1339 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE ntmatrix.for:1340 */
/*<   300 continue >*/
L300:
/* SOURCE ntmatrix.for:1341 */
/*<       j=j+cd5ty3 >*/
    j += 17;
/* SOURCE ntmatrix.for:1342 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE ntmatrix.for:1343 */
/*<   400 continue >*/
L400:
/* SOURCE ntmatrix.for:1344 */
/*<       j=j+cd5ty4 >*/
    j += 10;
/* SOURCE ntmatrix.for:1345 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE ntmatrix.for:1346 */
/*<   500 continue >*/
L500:
/*         ABRUPT EXPANSION */
/* SOURCE ntmatrix.for:1348 */
/*<       if(mode.eq.1)then >*/
    if (*mode == 1) {
/* SOURCE ntmatrix.for:1349 */
/*<       emc(j+6)=emc(j+7) >*/
	emc[j + 6] = emc[j + 7];
/* SOURCE ntmatrix.for:1350 */
/*<       else >*/
    } else {
/* SOURCE ntmatrix.for:1351 */
/*<       emc(j+7)=emc(j+6) >*/
	emc[j + 7] = emc[j + 6];
/* SOURCE ntmatrix.for:1352 */
/*<       endif >*/
    }
/* SOURCE ntmatrix.for:1353 */
/*<       j=j+cd5ty5 >*/
    j += 3;
/* SOURCE ntmatrix.for:1354 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE ntmatrix.for:1355 */
/*<   600 continue >*/
L600:
/* SOURCE ntmatrix.for:1356 */
/*<       j=j+1+abs(emc(j+6))*cd5ty6 >*/
    j = j + 1 + ((feq_gen_i_d_1 = emc[j + 6], abs(feq_gen_i_d_1)) << 3);
/* SOURCE ntmatrix.for:1357 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE ntmatrix.for:1358 */
/*<   700 continue >*/
L700:
/* SOURCE ntmatrix.for:1359 */
/*<       j=j+cd5ty7 >*/
    j += 10;
/* SOURCE ntmatrix.for:1360 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE ntmatrix.for:1361 */
/*<   800 continue >*/
L800:
/* SOURCE ntmatrix.for:1362 */
/*<       j=j+cd5ty8 >*/
    j += 7;
/* SOURCE ntmatrix.for:1363 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE ntmatrix.for:1364 */
/*<   900 continue >*/
L900:
/* SOURCE ntmatrix.for:1365 */
/*<       j=j+cd5ty9 >*/
    j += 11;
/* SOURCE ntmatrix.for:1366 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE ntmatrix.for:1368 */
/*<     6 continue >*/
L6:
/* SOURCE ntmatrix.for:1369 */
/*<       if(emc(j+1).eq.2)then >*/
    if (emc[j + 1] == 2) {
/*           FORCED ELEVATION WITH POSSIBLE CRITICAL DEPTH */
/* SOURCE ntmatrix.for:1372 */
/*<       if(mode.eq.1)then >*/
	if (*mode == 1) {
/* SOURCE ntmatrix.for:1373 */
/*<       emc(j+5)=emc(j+7) >*/
	    emc[j + 5] = emc[j + 7];
/* SOURCE ntmatrix.for:1374 */
/*<       else >*/
	} else {
/* SOURCE ntmatrix.for:1375 */
/*<       emc(j+7)=emc(j+5) >*/
	    emc[j + 7] = emc[j + 5];
/* SOURCE ntmatrix.for:1376 */
/*<       endif >*/
	}
/* SOURCE ntmatrix.for:1377 */
/*<       endif >*/
    }
/* SOURCE ntmatrix.for:1378 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE ntmatrix.for:1379 */
/*<  2000 continue >*/
L2000:
/* SOURCE ntmatrix.for:1380 */
/*<       j=j+emc(code+1) >*/
    j += emc[code + 1];
/* SOURCE ntmatrix.for:1381 */
/*<       goto10 >*/
    goto L10;
/* SOURCE ntmatrix.for:1382 */
/*<       end >*/
} /* rststa_ */




/* SOURCE ntmatrix.for:1386 */
/*<       subroutinesetsta(stdout,nex,grav,exnodt,ept,emc) >*/
/* Subroutine */ int setsta_(integer *stdout, integer *nex, real *grav, 
	integer *feq_storage_exnodt, integer *ept, integer *feq_storage_emc)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;
    static real equiv_0[1];

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer j;
    real feq_gen_r_d_, y, ac, bc, qc, tc, dbc, dtc;
    integer dnn;
    real con, pcv;
    integer unn, code;
    real dcon;
    integer ntab, node, adrs;
#define idum (feq::BitView<integer>(equiv_0, sizeof(equiv_0)))
#define rdum (equiv_0)
    integer feq_gen_type_d_, fnode;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *), xlkt20_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *);
    real qcsqr;
    integer sysgn;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__100 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__102 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Set state values in network-matrix control(EMC) for */
/*     code 5 type 1; code 5 type 5; and code 6, type 2 entries */
/*     based on state given by the steady flow analysis. */
/* SOURCE ntmatrix.for:1395 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE ntmatrix.for:1398 */
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
/* SOURCE ntmatrix.for:1401 */
/*<       integerept,stdout,nex >*/
/* SOURCE ntmatrix.for:1402 */
/*<       integeremc(ept),exnodt(9,nex) >*/
/* SOURCE ntmatrix.for:1403 */
/*<       realgrav >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     NEX    - number of exterior nodes in the model */
/*     GRAV   - value of acceleration due to gravity */
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
/* INCLUDE ntmatrix.for:1426 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE ntmatrix.for:1427 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ntmatrix.for:1430 */
/*<       integeradrs,code,dnn,fnode,idum,j,node,ntab,sysgn,type,unn >*/
/* SOURCE ntmatrix.for:1432 */
/*<       realac,bc,con,dbc,dcon,dtc,pcv,qc,qcsqr,r,rdum,tc,y >*/
/*     + + + EQUIVALENCES + + + */
/* SOURCE ntmatrix.for:1435 */
/*<       equivalence(rdum,idum) >*/
/*     + + + INTRINSICS + + + */
/* SOURCE ntmatrix.for:1438 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ntmatrix.for:1441 */
/*<       externallktab,xlkt20 >*/
/* *********************************************************************** */
/*     SEARCH THROUGH EMC FOR THE PROPER CODES */
/* SOURCE ntmatrix.for:1445 */
/*<       j=emc(1) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
    j = emc[1];
/* SOURCE ntmatrix.for:1446 */
/*<    10 continue >*/
L10:
/* SOURCE ntmatrix.for:1447 */
/*<       code=emc(j) >*/
    code = emc[j];
/* SOURCE ntmatrix.for:1448 */
/*<       if(code.eq.-1)return >*/
    if (code == -1) {
	return 0;
    }
/* SOURCE ntmatrix.for:1449 */
/*<        >*/
    switch (code) {
	case 1:  goto L2000;
	case 2:  goto L2;
	case 3:  goto L2000;
	case 4:  goto L2000;
	case 5:  goto L5;
	case 6:  goto L6;
	case 7:  goto L2000;
	case 8:  goto L2000;
	case 9:  goto L2000;
	case 10:  goto L2000;
	case 11:  goto L2000;
	case 12:  goto L2000;
	case 13:  goto L2000;
	case 14:  goto L2000;
	case 15:  goto L2000;
    }
/* SOURCE ntmatrix.for:1451 */
/*<       write(stdout,*)' *BUG:18* INVALID EMC CODE IN SETSTA. CODE=',code >*/
    feq_gen_io_d__100.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__100);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:18* INVALID EMC CODE IN SETSTA. CODE="), (
	    ftnlen)43);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE ntmatrix.for:1453 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntmatrix.for:1455 */
/*<     2 continue >*/
L2:
/* SOURCE ntmatrix.for:1456 */
/*<       j=j+emc(j+1) >*/
    j += emc[j + 1];
/* SOURCE ntmatrix.for:1457 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE ntmatrix.for:1459 */
/*<     5 continue >*/
L5:
/* SOURCE ntmatrix.for:1460 */
/*<       type=emc(j+1) >*/
    feq_gen_type_d_ = emc[j + 1];
/* SOURCE ntmatrix.for:1461 */
/*<       goto(100,200,300,400,500,600,700,800,900),type >*/
    switch (feq_gen_type_d_) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
	case 4:  goto L400;
	case 5:  goto L500;
	case 6:  goto L600;
	case 7:  goto L700;
	case 8:  goto L800;
	case 9:  goto L900;
    }
/* SOURCE ntmatrix.for:1463 */
/*<        >*/
    feq_gen_io_d__102.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__102);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:37* INVALID CODE 5 TYPE IN SETSTA."), (ftnlen)
	    40);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" TYPE="), (ftnlen)6);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE ntmatrix.for:1465 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE ntmatrix.for:1467 */
/*<   100 continue >*/
L100:
/* SOURCE ntmatrix.for:1468 */
/*<       adrs=emc(j+7) >*/
    adrs = emc[j + 7];
/* SOURCE ntmatrix.for:1469 */
/*<       sysgn=emc(j+5) >*/
    sysgn = emc[j + 5];
/* SOURCE ntmatrix.for:1470 */
/*<       fnode=emc(j+4) >*/
    fnode = emc[j + 4];
/* SOURCE ntmatrix.for:1471 */
/*<       unn=emc(j+2) >*/
    unn = emc[j + 2];
/* SOURCE ntmatrix.for:1472 */
/*<       dnn=emc(j+3) >*/
    dnn = emc[j + 3];
/* SOURCE ntmatrix.for:1473 */
/*<       idum=emc(j+11) >*/
    *idum = emc[j + 11];
/* SOURCE ntmatrix.for:1474 */
/*<       y=ye2(unn)+ze(unn) >*/
    y = static_cast<double>(enelem_1.ye2[unn - 1]) + enelem_1.ze[unn - 1];
/* SOURCE ntmatrix.for:1475 */
/*<       if(qe2(fnode)*sysgn.lt.0)y=ye2(dnn)+ze(dnn) >*/
    if (static_cast<double>(enelem_1.qe2[fnode - 1]) * sysgn < (float)0.) {
	y = static_cast<double>(enelem_1.ye2[dnn - 1]) + enelem_1.ze[dnn - 1];
    }
/* SOURCE ntmatrix.for:1476 */
/*<       y=y-rdum >*/
    y -= *rdum;
/* SOURCE ntmatrix.for:1477 */
/*<       if(y.gt.0.0)then >*/
    if (y > (float)0.) {
/* SOURCE ntmatrix.for:1478 */
/*<       callxlkt20(adrs,y,ac,tc,dtc,con,dcon,bc,dbc) >*/
	xlkt20_(&adrs, &y, &ac, &tc, &dtc, &con, &dcon, &bc, &dbc);
/* SOURCE ntmatrix.for:1482 */
/*<       qcsqr=grav*ac**3/tc >*/
/* Computing 3rd power */
	feq_gen_r_d_1 = ac;
	qcsqr = static_cast<double>(static_cast<double>(*grav) * (static_cast<double>(feq_gen_r_d_1) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1))) / tc;
/* SOURCE ntmatrix.for:1483 */
/*<       r=qe2(fnode)**2/qcsqr >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = enelem_1.qe2[fnode - 1];
	feq_gen_r_d_ = static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / qcsqr;
/* SOURCE ntmatrix.for:1484 */
/*<       emc(j+8)=-1 >*/
	emc[j + 8] = -1;
/* SOURCE ntmatrix.for:1485 */
/*<       if(r.gt.0.98.and.r.lt.1.02)emc(j+8)=1 >*/
	if (feq_gen_r_d_ > (float).98 && feq_gen_r_d_ < (float)1.02) {
	    emc[j + 8] = 1;
	}
/* SOURCE ntmatrix.for:1486 */
/*<       else >*/
    } else {
/* SOURCE ntmatrix.for:1487 */
/*<       emc(j+8)=-1 >*/
	emc[j + 8] = -1;
/* SOURCE ntmatrix.for:1488 */
/*<       endif >*/
    }
/*             SET PREVIOUS STATE */
/* SOURCE ntmatrix.for:1490 */
/*<       emc(j+12)=emc(j+8) >*/
    emc[j + 12] = emc[j + 8];
/* SOURCE ntmatrix.for:1492 */
/*<       j=j+cd5ty1 >*/
    j += 7;
/* SOURCE ntmatrix.for:1493 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE ntmatrix.for:1494 */
/*<   200 continue >*/
L200:
/* SOURCE ntmatrix.for:1495 */
/*<       j=j+cd5ty2 >*/
    j += 12;
/* SOURCE ntmatrix.for:1496 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE ntmatrix.for:1497 */
/*<   300 continue >*/
L300:
/* SOURCE ntmatrix.for:1498 */
/*<       j=j+cd5ty3 >*/
    j += 17;
/* SOURCE ntmatrix.for:1499 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE ntmatrix.for:1500 */
/*<   400 continue >*/
L400:
/* SOURCE ntmatrix.for:1501 */
/*<       j=j+cd5ty4 >*/
    j += 10;
/* SOURCE ntmatrix.for:1502 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE ntmatrix.for:1503 */
/*<   500 continue >*/
L500:
/*             LOOKUP CRITICAL FLOW AT THE UPSTREAM DEPTH */
/* SOURCE ntmatrix.for:1505 */
/*<       calllktab(emc(j+8),ye2(emc(j+2)),1,qc,ntab,pcv) >*/
    lktab_(&emc[j + 8], &enelem_1.ye2[emc[j + 2] - 1], &feq_gen_c_d_1, &qc, &ntab, &
	    pcv);
/* SOURCE ntmatrix.for:1508 */
/*<       if(qe2(emc(j+2)).ge.qc)then >*/
    if (enelem_1.qe2[emc[j + 2] - 1] >= qc) {
/* SOURCE ntmatrix.for:1509 */
/*<       emc(j+6)=1 >*/
	emc[j + 6] = 1;
/* SOURCE ntmatrix.for:1510 */
/*<       else >*/
    } else {
/* SOURCE ntmatrix.for:1511 */
/*<       emc(j+6)=-1 >*/
	emc[j + 6] = -1;
/* SOURCE ntmatrix.for:1512 */
/*<       endif >*/
    }
/* SOURCE ntmatrix.for:1513 */
/*<       emc(j+7)=emc(j+6) >*/
    emc[j + 7] = emc[j + 6];
/* SOURCE ntmatrix.for:1514 */
/*<       j=j+cd5ty5 >*/
    j += 3;
/* SOURCE ntmatrix.for:1515 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE ntmatrix.for:1516 */
/*<   600 continue >*/
L600:
/* SOURCE ntmatrix.for:1517 */
/*<       j=j+1+abs(emc(j+6))*cd5ty6 >*/
    j = j + 1 + ((feq_gen_i_d_1 = emc[j + 6], abs(feq_gen_i_d_1)) << 3);
/* SOURCE ntmatrix.for:1518 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE ntmatrix.for:1519 */
/*<   700 continue >*/
L700:
/* SOURCE ntmatrix.for:1520 */
/*<       j=j+cd5ty7 >*/
    j += 10;
/* SOURCE ntmatrix.for:1521 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE ntmatrix.for:1522 */
/*<   800 continue >*/
L800:
/* SOURCE ntmatrix.for:1523 */
/*<       j=j+cd5ty8 >*/
    j += 7;
/* SOURCE ntmatrix.for:1524 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE ntmatrix.for:1525 */
/*<   900 continue >*/
L900:
/* SOURCE ntmatrix.for:1526 */
/*<       j=j+cd5ty9 >*/
    j += 11;
/* SOURCE ntmatrix.for:1527 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE ntmatrix.for:1529 */
/*<     6 continue >*/
L6:
/* SOURCE ntmatrix.for:1530 */
/*<       if(emc(j+1).ne.2)goto2000 >*/
    if (emc[j + 1] != 2) {
	goto L2000;
    }
/* SOURCE ntmatrix.for:1531 */
/*<       node=emc(j+2) >*/
    node = emc[j + 2];
/* SOURCE ntmatrix.for:1532 */
/*<       if(exnodt(2,node).gt.0)then >*/
    if (exnodt[node * 9 + 2] > 0) {
/* SOURCE ntmatrix.for:1533 */
/*<       qcsqr=grav*ae2(node)**3/t2(exnodt(2,node)) >*/
/* Computing 3rd power */
	feq_gen_r_d_1 = enelem_1.ae2[node - 1];
	qcsqr = static_cast<double>(static_cast<double>(*grav) * (static_cast<double>(feq_gen_r_d_1) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1))) / bnelem_1.t2[exnodt[node * 9 
		+ 2] - 1];
/* SOURCE ntmatrix.for:1534 */
/*<       r=qe2(node)**2/qcsqr >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = enelem_1.qe2[node - 1];
	feq_gen_r_d_ = static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / qcsqr;
/* SOURCE ntmatrix.for:1535 */
/*<       emc(j+5)=-1 >*/
	emc[j + 5] = -1;
/* SOURCE ntmatrix.for:1536 */
/*<       if(r.gt.0.98.and.r.lt.1.02)emc(j+5)=1 >*/
	if (feq_gen_r_d_ > (float).98 && feq_gen_r_d_ < (float)1.02) {
	    emc[j + 5] = 1;
	}
/*               SET PREVIOUS STATE */
/* SOURCE ntmatrix.for:1538 */
/*<       emc(j+7)=emc(j+5) >*/
	emc[j + 7] = emc[j + 5];
/* SOURCE ntmatrix.for:1539 */
/*<       else >*/
    } else {
/*               Free node so that critical flow cannot exist.  Set the */
/*               state values. */
/* SOURCE ntmatrix.for:1542 */
/*<       emc(j+5)=1 >*/
	emc[j + 5] = 1;
/* SOURCE ntmatrix.for:1543 */
/*<       emc(j+7)=1 >*/
	emc[j + 7] = 1;
/* SOURCE ntmatrix.for:1544 */
/*<       endif >*/
    }
/* SOURCE ntmatrix.for:1545 */
/*<       goto2000 >*/
    goto L2000;
/* SOURCE ntmatrix.for:1547 */
/*<  2000 continue >*/
L2000:
/* SOURCE ntmatrix.for:1548 */
/*<       j=j+emc(code+1) >*/
    j += emc[code + 1];
/* SOURCE ntmatrix.for:1549 */
/*<       goto10 >*/
    goto L10;
/* SOURCE ntmatrix.for:1550 */
/*<       end >*/
} /* setsta_ */

#undef rdum
#undef idum


#ifdef __cplusplus
	}
#endif
