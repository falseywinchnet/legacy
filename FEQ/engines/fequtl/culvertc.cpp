#include <feq/full_barrel.hpp>
// SFPSBE retains YR after FST at 0x426aa6, energy in x87 spills, and
// wide differences/Froude ratios. Only the error diagnostic stores YR
// into a REAL temporary; normal-flow square roots store REAL before K.
#include <feq/steady_residual.hpp>
#include "callbacks.hpp"
/* culvertc.f -- translated by f2c (version 20240504).
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

/* COMMON grvcom_ is declared in common.hpp. */

#define grvcom_1 grvcom_

/* COMMON sberc_ is declared in common.hpp. */

#define sberc_1 sberc_

/* COMMON appcom_ is declared in common.hpp. */

#define appcom_1 appcom_

/* COMMON culcom_ is declared in common.hpp. */

#define culcom_1 culcom_

/* COMMON rdfcom_ is declared in common.hpp. */

#define rdfcom_1 rdfcom_

/* COMMON epscom_ is declared in common.hpp. */

#define epscom_1 epscom_

/* COMMON sperc_ is declared in common.hpp. */

#define sperc_1 sperc_

/* COMMON subcom_ is declared in common.hpp. */

#define subcom_1 subcom_

/* Table of constant values */

static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_1 = 1;
static real c_b50 = (float)0.;
static real c_b51 = (float)5e-6;




/* SOURCE culvertc.for:4 */
/*<       realfunctionsber(y) >*/
doublereal sber_(real *y)
{
    float yt = *y < sberc_1.feq_gen_d_d_ ? *y : sberc_1.feq_gen_d_d_;
    float a,t,dt,j,k,dk,bet,dbet,alp,dalp;
    extern int xlktal_(int*,float*,float*,float*,float*,float*,float*,float*,float*,float*,float*,float*);
    xlktal_(&sberc_1.adrs,&yt,&a,&t,&dt,&j,&k,&dk,&bet,&dbet,&alp,&dalp);
    // Lookup clamps the section depth, while energy uses the original Y.
    const feq::SteadyResidualInput input{*y,a,k,alp,sberc_1.qt,sberc_1.qt,
        sberc_1.kr,sberc_1.dx,sberc_1.se,sberc_1.rhs,sberc_1.kacc,sberc_1.kdec,
        sberc_1.ar,grvcom_1.grav2};
    return feq::steady_subcritical_residual(input);
} /* sber_ */




/* SOURCE culvertc.for:58 */
/*<        >*/
/* Subroutine */ int fulbar_(integer *stdout, real *a1true, real *alp1t, real 
	*k1true, real *z1true, real *a2full, real *k2full, real *a3full, real 
	*cdis, real *avh, real *z3p, real *q, real *zat2)
{
    static_cast<void>(stdout);
    const feq::FullBarrelInput input{*a1true,*alp1t,*k1true,*z1true,*a2full,*k2full,
        *a3full,*cdis,*avh,*z3p,appcom_1.applen,appcom_1.applos,grvcom_1.grav2,
        rdfcom_1.wfrd,epscom_1.epsf,culcom_1.frcfac};
    const feq::FullBarrelResult result = feq::full_barrel(input);
    *q = result.flow;
    *zat2 = result.entrance_piezometric_elevation;
    return 0;
} /* fulbar_ */




/* SOURCE culvertc.for:165 */
/*<       subroutinesfpcc(iu,id,dh,q,zdn,is,zup,sflag) >*/
/* Subroutine */ int sfpcc_(integer *iu, integer *id, real *dh, real *q, real 
	*zdn, integer *is, real *zup, integer *sflag)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2;

    /* Local variables */
    integer feq_gen_i_d_;
    real al, ar, jl, kl, se, ya, dx, jr, kr, ql, tl, qr, yl, tr, yr, dkl, dkr,
	     dtl, zbl, dtr, zbr, betl;
    integer adrs;
    real alpl, betr, alpr, dbetl, dalpl, dbetr, dalpr;
    extern /* Subroutine */ int xlktal_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *);

/*     + + + PURPOSE + + + */
/*     Compute steady flow hydraulic gradeline for a closed */
/*     conduit flowing full. ZDN gives the elevation of the */
/*     hydraulic grade line at the downstream end of the */
/*     conduit. */
/* SOURCE culvertc.for:175 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertc.for:178 */
/*<       integerid,is,iu,sflag >*/
/* SOURCE culvertc.for:179 */
/*<       realdh,q,zdn,zup >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IU     - Index for upstream node for the culvert barrel */
/*     ID     - Index for the downstream node for the culvert barrel */
/*     DH     - Entrance loss for the culvert */
/*     Q      - Flowrate */
/*     ZDN    - Water surface elevation at downstream end of barrel */
/*     IS     - Index of node for the last value computed */
/*     ZUP    - Water surface elevation at section 2 */
/*     SFLAG  - Flag describing results: */
/*                0-results incomplete.  Super critical flow encountered */
/*                  and flow is thought to be caused by a steep slope. */
/*                1-results complete */
/*               -1-results incomplete.  Super critical flow encountered */
/*                  and DX may be too large. */
/*               -2-results incomplete.  Super critical flow encountered */
/*                  and DX is too large. */
/*               -3-no solution found at the last point. */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertc.for:200 */
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
/* INCLUDE culvertc.for:201 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertc.for:202 */
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
/* SOURCE culvertc.for:205 */
/*<       integeradrs,i >*/
/* SOURCE culvertc.for:206 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertc.for:211 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertc.for:214 */
/*<       externalxlktal >*/
/* *********************************************************************** */
/*      WRITE(STDOUT,60) */
/* SOURCE culvertc.for:217 */
/*<       qr=q >*/
    qr = *q;
/* SOURCE culvertc.for:218 */
/*<       ql=q >*/
    ql = *q;
/* SOURCE culvertc.for:219 */
/*<       zbr=zbvec(id) >*/
    zbr = culcom_1.zbvec[*id - 1];
/* SOURCE culvertc.for:220 */
/*<       yr=zdn-zbr >*/
    yr = static_cast<double>(*zdn) - zbr;
/*     DH GIVES THE LOSS OF ENERGY HEAD CAUSED BY THE CULVERT IN */
/*     EXCESS OF BARREL FRICTION. DISTRIBUTE ALONG LENGTH OF THE */
/*     BARREL */
/* SOURCE culvertc.for:225 */
/*<       se=dh/abs(xvec(iu)-xvec(id)) >*/
    se = *dh / (feq_gen_r_d_1 = static_cast<double>(culcom_1.xvec[*iu - 1]) - culcom_1.xvec[*id - 1], dabs(
	    feq_gen_r_d_1));
/*      WRITE(STDOUT,*) ' SFPCC: DH=',DH,' SE=',SE,' Q=',Q */
/*      ZR = ZDN */
/* SOURCE culvertc.for:228 */
/*<       adrs=nsec(id) >*/
    adrs = culcom_1.nsec[*id - 1];
/* SOURCE culvertc.for:229 */
/*<       ya=dvec(id) >*/
    ya = culcom_1.dvec[*id - 1];
/* SOURCE culvertc.for:230 */
/*<       callxlktal(adrs,ya,ar,tr,dtr,jr,kr,dkr,betr,dbetr,alpr,dalpr) >*/
    xlktal_(&adrs, &ya, &ar, &tr, &dtr, &jr, &kr, &dkr, &betr, &dbetr, &alpr, 
	    &dalpr);
/*      WRITE(STDOUT,62) ID, XVEC(ID), YR, ZR, DVEC(ID) */
/* SOURCE culvertc.for:237 */
/*<       yvecsb(id)=yr >*/
    culcom_1.yvecsb[*id - 1] = yr;
/* SOURCE culvertc.for:238 */
/*<       do500i=id-1,iu,-1 >*/
    feq_gen_i_d_1 = *iu;
    for (feq_gen_i_d_ = *id - 1; feq_gen_i_d_ >= feq_gen_i_d_1; --feq_gen_i_d_) {
/* SOURCE culvertc.for:239 */
/*<       adrs=nsec(i) >*/
	adrs = culcom_1.nsec[feq_gen_i_d_ - 1];
/* SOURCE culvertc.for:240 */
/*<       dx=abs(xvec(i+1)-xvec(i)) >*/
	dx = (feq_gen_r_d_1 = static_cast<double>(culcom_1.xvec[feq_gen_i_d_]) - culcom_1.xvec[feq_gen_i_d_ - 1], dabs(feq_gen_r_d_1));
/* SOURCE culvertc.for:241 */
/*<       zbl=zbvec(i) >*/
	zbl = culcom_1.zbvec[feq_gen_i_d_ - 1];
/* SOURCE culvertc.for:242 */
/*<       ya=dvec(i) >*/
	ya = culcom_1.dvec[feq_gen_i_d_ - 1];
/* SOURCE culvertc.for:243 */
/*<       callxlktal(adrs,ya,al,tl,dtl,jl,kl,dkl,betl,dbetl,alpl,dalpl) >*/
	xlktal_(&adrs, &ya, &al, &tl, &dtl, &jl, &kl, &dkl, &betl, &dbetl, &
		alpl, &dalpl);
/* SOURCE culvertc.for:248 */
/*<        >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(qr) / ar;
/* Computing 2nd power */
	feq_gen_r_d_2 = static_cast<double>(ql) / al;
	yl = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(yr) + zbr) + static_cast<double>(static_cast<double>(alpr) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / grvcom_1.grav2) + static_cast<double>(dx) * (static_cast<double>(static_cast<double>(static_cast<double>(ql) * qr) 
		/ (static_cast<double>(kl) * kr)) + se)) - zbl) - static_cast<double>(static_cast<double>(alpl) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) / 
		grvcom_1.grav2;
/*        ZL = ZBL + YL */
/* SOURCE culvertc.for:251 */
/*<       zbr=zbl >*/
	zbr = zbl;
/* SOURCE culvertc.for:252 */
/*<       yr=yl >*/
	yr = yl;
/* SOURCE culvertc.for:253 */
/*<       qr=ql >*/
	qr = ql;
/* SOURCE culvertc.for:254 */
/*<       kr=kl >*/
	kr = kl;
/* SOURCE culvertc.for:255 */
/*<       ar=al >*/
	ar = al;
/* SOURCE culvertc.for:256 */
/*<       alpr=alpl >*/
	alpr = alpl;
/* SOURCE culvertc.for:257 */
/*<       yvecsb(i)=yl >*/
	culcom_1.yvecsb[feq_gen_i_d_ - 1] = yl;
/*        WRITE(STDOUT,62) I, XVEC(I), YL, ZL, DVEC(I) */
/* SOURCE culvertc.for:259 */
/*<   500 continue >*/
/* L500: */
    }
/* SOURCE culvertc.for:261 */
/*<       zup=yl+zbl >*/
    *zup = static_cast<double>(yl) + zbl;
/* SOURCE culvertc.for:262 */
/*<       is=iu >*/
    *is = *iu;
/* SOURCE culvertc.for:263 */
/*<       sflag=1 >*/
    *sflag = 1;
/* SOURCE culvertc.for:264 */
/*<       return >*/
    return 0;
/* SOURCE culvertc.for:265 */
/*<       end >*/
} /* sfpcc_ */




/* SOURCE culvertc.for:269 */
/*<       realfunctionsper(y) >*/
doublereal sper_(real *y)
{
    float yt = *y < sperc_1.feq_gen_d_d_ ? *y : sperc_1.feq_gen_d_d_;
    float a,t,dt,j,k,dk,bet,dbet,alp,dalp;
    extern int xlktal_(int*,float*,float*,float*,float*,float*,float*,float*,float*,float*,float*,float*);
    xlktal_(&sperc_1.adr,&yt,&a,&t,&dt,&j,&k,&dk,&bet,&dbet,&alp,&dalp);
    // Lookup clamps the section depth, while energy uses the original Y.
    const feq::SteadyResidualInput input{*y,a,k,alp,sperc_1.qr,sperc_1.ql,
        sperc_1.kl,sperc_1.dx,sperc_1.se,sperc_1.rhs,sperc_1.kacc,sperc_1.kdec,
        sperc_1.al,grvcom_1.grav2};
    return feq::steady_supercritical_residual(input);
} /* sper_ */




/* SOURCE culvertc.for:319 */
/*<        >*/
/* Subroutine */ int sbfebc_(integer *stdout, real *eu, real *ed, integer *
	plcwtb, integer *glcwtb, integer *phcwtb, integer *ghcwtb, integer *
	psubtb, integer *gsubtb, integer *noff, char *feq_storage_surf, real *hlcrit, 
	real *feq_storage_xl, real *feq_storage_xr, real *feq_storage_hl, real *feq_storage_hm, real *feq_storage_hr, real *feq_storage_ql, real *feq_storage_qm, 
	real *feq_storage_qr, real *feq_storage_tothl, real *feq_storage_tothm, real *feq_storage_tothr, real *feq_storage_yfl, real *feq_storage_yfm,
	 real *feq_storage_yfr, real *feq_storage_appl, real *feq_storage_appm, real *feq_storage_appr, real *feq_storage_wl, real *feq_storage_wm, 
	real *feq_storage_wr, real *feq_storage_aell, real *feq_storage_aelm, real *feq_storage_aelr, real *rmffac, real *
	qroad, real *mroad, real *eroad, ftnlen surf_len)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2;
    cilist feq_gen_ci_d_1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(), s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), 
	    e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    real hd, el, em, er, dx, yc, emid, eseg, mmid;
    integer iseg;
    real qmid, mseg, qseg, sell, selm;
    doublereal esub;
    real selr;
    doublereal msub;
    real srat;
    doublereal qsub;
    real eleft, depth, mleft, qleft, crest;
    extern doublereal invse_(real *, real *, real *);
    real shtot;
    integer hcwtab, lcwtab, subtab;
    real eright, mright, qright;
    extern /* Subroutine */ int stothq_(integer *, integer *, integer *, real 
	    *, real *, real *, real *, real *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__70 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     SuBmerged Flow EmBankment with Culvert - Find the submerged flow, */
/*     estimated momentum flux, and estimated energy flux */
/*     over a submerged embankment.  The */
/*     free flow computations establish most of the argument values */
/* SOURCE culvertc.for:333 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertc.for:336 */
/*<       integerghcwtb,glcwtb,gsubtb,noff,phcwtb,plcwtb,psubtb,stdout >*/
/* SOURCE culvertc.for:338 */
/*<        >*/
/* SOURCE culvertc.for:342 */
/*<       charactersurf(*)*8 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     EU     - Water surface elevation upstream. */
/*     ED     - Downstream water surface elevation */
/*     PLCWTB - Paved low-head weir coefficient table */
/*     GLCWTB - Gravel surface low head weir coefficient table */
/*     PHCWTB - Paved high-head weir coefficient table */
/*     GHCWTB - Gravel surface high head weir coefficient table */
/*     PSUBTB - Paved submergence table */
/*     GSUBTB - Gravel surface submergence table */
/*     NOFF   - Number of offsets */
/*     SURF   - Nature of the embankment surface */
/*     HLCRIT - Ratio of piezometric head to crest breadth at boundary */
/*              between low head and high head flow */
/*     XL     - Offset at left hand end of segment */
/*     XR     - Offset at right hand end of segment */
/*     HL     - Piezometric head on left end of segment */
/*     HM     - Piezometric head on middle of segment */
/*     HR     - Piezometric head on right end of segment */
/*     QL     - Flow on left hand end of segment */
/*     QM     - Flow at middle of the segment */
/*     QR     - Flow on right hand end of segment */
/*     TOTHL  - Total head at left hand end of segment */
/*     TOTHM  - Total head at middle of segment */
/*     TOTHR  - Total head at right hand end of segment */
/*     YFL    - Estimated depth at crest at left hand end of segment */
/*     YFM    - Estimated depth at crest at middle of segment */
/*     YFR    - Estimated depth at crest at right hand end of segment */
/*     APPL   - Elevation of approach at left end of line segment */
/*     APPM   - Elevation of approach at middle of line segment */
/*     APPR   - Elevation of approach at right end of line segment */
/*     WL     - Breadth of the crest at left hand end of segment */
/*     WM     - Breadth of the crest at middle of segment */
/*     WR     - Breadth of the crest at right hand end of segment */
/*     AELL   - Estimated ratio of head loss to head loss at incipient */
/*              submergence at left end of line segment */
/*     AELM   - Estimated ratio of head loss to head loss at incipient */
/*              submergence at middle of line segment */
/*     AELR   - Estimated ratio of head loss to head loss at incipient */
/*              submergence at right end of line segment */
/*     RMFFAC - Adjustment factor for roadway momentum flux */
/*     QROAD  - Flow over the roadway */
/*     MROAD  - Momentum flux from flow over the road */
/*     EROAD  - Energy flux over the roadway */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertc.for:390 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertc.for:391 */
/*     COMMON FOR SUBMERGENCE RATIOS FOR WEIR COMPUTATIONS */
/* SOURCE subcom.cmn:3 */
/*<       common/subcom/prat,grat >*/
/* SOURCE subcom.cmn:5 */
/*<       realprat,grat >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertc.for:394 */
/*<       integerhcwtab,iseg,lcwtab,subtab >*/
/* SOURCE culvertc.for:395 */
/*<        >*/
/* SOURCE culvertc.for:398 */
/*<       doubleprecisionesub,msub,qsub >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertc.for:401 */
/*<       intrinsicabs,max,min >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertc.for:404 */
/*<       realinvse >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertc.for:407 */
/*<       externalinvse,stothq >*/
/* *********************************************************************** */
/*     COMPUTE THE SUBMERGED FLOW GIVEN THAT THE FREE FLOW VALUES */
/*     HAVE BEEN ESTABLISHED AND GIVEN A DOWNSTREAM WATER SURFACE */
/*     ELEVATION. */
/* SOURCE culvertc.for:413 */
/*<       qsub=0.d0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> aelr(feq_storage_aelr, 1);

    feq::IndexedPointer<real> aelm(feq_storage_aelm, 1);

    feq::IndexedPointer<real> aell(feq_storage_aell, 1);

    feq::IndexedPointer<real> wr(feq_storage_wr, 1);

    feq::IndexedPointer<real> wm(feq_storage_wm, 1);

    feq::IndexedPointer<real> wl(feq_storage_wl, 1);

    feq::IndexedPointer<real> appr(feq_storage_appr, 1);

    feq::IndexedPointer<real> appm(feq_storage_appm, 1);

    feq::IndexedPointer<real> appl(feq_storage_appl, 1);

    feq::IndexedPointer<real> yfr(feq_storage_yfr, 1);

    feq::IndexedPointer<real> yfm(feq_storage_yfm, 1);

    feq::IndexedPointer<real> yfl(feq_storage_yfl, 1);

    feq::IndexedPointer<real> tothr(feq_storage_tothr, 1);

    feq::IndexedPointer<real> tothm(feq_storage_tothm, 1);

    feq::IndexedPointer<real> tothl(feq_storage_tothl, 1);

    feq::IndexedPointer<real> qr(feq_storage_qr, 1);

    feq::IndexedPointer<real> qm(feq_storage_qm, 1);

    feq::IndexedPointer<real> ql(feq_storage_ql, 1);

    feq::IndexedPointer<real> hr(feq_storage_hr, 1);

    feq::IndexedPointer<real> hm(feq_storage_hm, 1);

    feq::IndexedPointer<real> hl(feq_storage_hl, 1);

    feq::IndexedPointer<real> xr(feq_storage_xr, 1);

    feq::IndexedPointer<real> xl(feq_storage_xl, 1);

    feq::IndexedPointer<char> surf(feq_storage_surf, 8);

    /* Function Body */
    qsub = 0.;
/* SOURCE culvertc.for:414 */
/*<       msub=0.d0 >*/
    msub = 0.;
/* SOURCE culvertc.for:415 */
/*<       esub=0.d0 >*/
    esub = 0.;
/*      WRITE(STDOUT,*) ' ' */
/*      WRITE(STDOUT,*) ' SBFEBC' */
/* SOURCE culvertc.for:420 */
/*<       if(ed.gt.eu)then >*/
    if (*ed > *eu) {
/* SOURCE culvertc.for:421 */
/*<       write(stdout,*)' *BUG:XXX* DOWNSTREAM ELEV > UPSTREAM ELEV.' >*/
	feq_gen_io_d__70.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__70);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* DOWNSTREAM ELEV > UPSTREAM ELEV."), (
		ftnlen)43);
	e_wsle();
/* SOURCE culvertc.for:422 */
/*<       write(stdout,'('' EU='',F10.4,'' ED='',F10.4)')eu,ed >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(' EU=',F10.4,' ED=',F10.4)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&(*eu), (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&(*ed), (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culvertc.for:423 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertc.for:424 */
/*<       elseif(ed.eq.eu)then >*/
    } else if (*ed == *eu) {
/* SOURCE culvertc.for:425 */
/*<       qroad=0.0 >*/
	*qroad = (float)0.;
/* SOURCE culvertc.for:426 */
/*<       mroad=0.0 >*/
	*mroad = (float)0.;
/* SOURCE culvertc.for:427 */
/*<       eroad=0.0 >*/
	*eroad = (float)0.;
/* SOURCE culvertc.for:428 */
/*<       return >*/
	return 0;
/* SOURCE culvertc.for:429 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,'('' EU='',F10.4,'' ED='',F10.4)') EU, ED */
/*     FOR EACH SEGMENT OF THE WEIR FIND THE EFFECT OF THIS */
/*     VALUE OF DOWNSTREAM PIEZOMETRIC HEAD */
/* SOURCE culvertc.for:436 */
/*<       do4100iseg=1,noff-1 >*/
    feq_gen_i_d_1 = *noff - 1;
    for (iseg = 1; iseg <= feq_gen_i_d_1; ++iseg) {
/*        WRITE(STDOUT,*) ' ' */
/*        WRITE(STDOUT,*) ' ISEG=',ISEG */
/*       SELECT THE TABLES FOR SUBMERGENCE AND WEIR COEF */
/* SOURCE culvertc.for:442 */
/*<       if(surf(iseg).eq.'PAVED')then >*/
	if (s_cmp(surf + (iseg << 3), const_cast<char*>("PAVED"), (ftnlen)8, (ftnlen)5) == 0) {
/* SOURCE culvertc.for:443 */
/*<       subtab=psubtb >*/
	    subtab = *psubtb;
/* SOURCE culvertc.for:444 */
/*<       hcwtab=phcwtb >*/
	    hcwtab = *phcwtb;
/* SOURCE culvertc.for:445 */
/*<       lcwtab=plcwtb >*/
	    lcwtab = *plcwtb;
/* SOURCE culvertc.for:446 */
/*<       srat=prat >*/
	    srat = subcom_1.prat;
/* SOURCE culvertc.for:447 */
/*<       else >*/
	} else {
/* SOURCE culvertc.for:448 */
/*<       subtab=gsubtb >*/
	    subtab = *gsubtb;
/* SOURCE culvertc.for:449 */
/*<       hcwtab=ghcwtb >*/
	    hcwtab = *ghcwtb;
/* SOURCE culvertc.for:450 */
/*<       lcwtab=glcwtb >*/
	    lcwtab = *glcwtb;
/* SOURCE culvertc.for:451 */
/*<       srat=grat >*/
	    srat = subcom_1.grat;
/* SOURCE culvertc.for:452 */
/*<       endif >*/
	}
/* SOURCE culvertc.for:454 */
/*<       if(hl(iseg).gt.0.0.or.hr(iseg).gt.0.0)then >*/
	if (hl[iseg] > (float)0. || hr[iseg] > (float)0.) {
/*         SEGMENT HAS NON-ZERO FREE FLOW */
/* SOURCE culvertc.for:456 */
/*<       qleft=ql(iseg) >*/
	    qleft = ql[iseg];
/* SOURCE culvertc.for:457 */
/*<       shtot=tothl(iseg) >*/
	    shtot = tothl[iseg];
/* SOURCE culvertc.for:458 */
/*<       if(qleft.gt.0.0)then >*/
	    if (qleft > (float)0.) {
/*           NOTE THAT THE UPSTREAM WATER SURFACE ELEVATION */
/*           LESS THE PIEZOMETRIC HEAD GIVES THE WEIR CREST */
/*           ELEVATION */
/* SOURCE culvertc.for:463 */
/*<       crest=eu-hl(iseg) >*/
		crest = static_cast<double>(*eu) - hl[iseg];
/* SOURCE culvertc.for:464 */
/*<       hd=ed-crest >*/
		hd = static_cast<double>(*ed) - crest;
/* SOURCE culvertc.for:466 */
/*<       if(hd.gt.srat*shtot)then >*/
		if (hd > static_cast<double>(srat) * shtot) {
/*             FLOW SUBMERGED AT THIS POINT. FIND NEW VALUES */
/* SOURCE culvertc.for:468 */
/*<       depth=eu-appl(iseg) >*/
		    depth = static_cast<double>(*eu) - appl[iseg];
/* SOURCE culvertc.for:469 */
/*<        >*/
		    stothq_(&hcwtab, &lcwtab, &subtab, hlcrit, &wl[iseg], &hl[
			    iseg], &hd, &depth, &shtot, &qleft);
/*             COMPUTE ESTIMATE OF  SUBMERGED ENERGY LOSS */
/* SOURCE culvertc.for:477 */
/*<       sell=shtot-(qleft/(hd+depth-hl(iseg)))**2/grav2-hd >*/
/* Computing 2nd power */
		    feq_gen_r_d_1 = static_cast<double>(qleft) / (static_cast<double>(static_cast<double>(hd) + depth) - hl[iseg]);
		    sell = static_cast<double>(static_cast<double>(shtot) - static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / grvcom_1.grav2) - hd;
/*             ESTIMATE CREST DEPTH ASSUMING SOME ENERGY LOSS */
/*             The over riding rule is that the crest depth used to */
/*             estimate energy and momentum fluxes cannot be less than */
/*             the depth estimated for free flow.  We assume this is */
/*             true because submergence would affect both the flow and */
/*             the crest depth. */
/* SOURCE culvertc.for:485 */
/*<       el=shtot-aell(iseg)*sell >*/
		    el = static_cast<double>(shtot) - static_cast<double>(aell[iseg]) * sell;
/* SOURCE culvertc.for:486 */
/*<       yc=invse(qleft,el,hd) >*/
		    yc = invse_(&qleft, &el, &hd);
/* SOURCE culvertc.for:487 */
/*<       yc=max(hd,yc) >*/
		    yc = dmax(hd,yc);
/* SOURCE culvertc.for:488 */
/*<       yc=max(yc,yfl(iseg)) >*/
/* Computing MAX */
		    feq_gen_r_d_1 = yc, feq_gen_r_d_2 = yfl[iseg];
		    yc = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE culvertc.for:489 */
/*<       else >*/
		} else {
/* SOURCE culvertc.for:490 */
/*<       yc=yfl(iseg) >*/
		    yc = yfl[iseg];
/* SOURCE culvertc.for:491 */
/*<       endif >*/
		}
/* SOURCE culvertc.for:492 */
/*<       mleft=qleft**2/yc >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = qleft;
		mleft = static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / yc;
/* SOURCE culvertc.for:493 */
/*<       eleft=qleft*((qleft/yc)**2/grav2+crest+yc) >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = static_cast<double>(qleft) / yc;
		eleft = static_cast<double>(qleft) * (static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / grvcom_1.grav2) + crest) + yc);
/* SOURCE culvertc.for:494 */
/*<       else >*/
	    } else {
/* SOURCE culvertc.for:495 */
/*<       qleft=0.0 >*/
		qleft = (float)0.;
/* SOURCE culvertc.for:496 */
/*<       mleft=0.0 >*/
		mleft = (float)0.;
/* SOURCE culvertc.for:497 */
/*<       eleft=0.0 >*/
		eleft = (float)0.;
/* SOURCE culvertc.for:498 */
/*<       endif >*/
	    }
/*         WRITE(STDOUT,*) ' LEFT: DEPTH=',DEPTH,' HD=',HD,' QLEFT=', */
/*     A               QLEFT,' SHTOT=',SHTOT, ' HEAD=',HL(ISEG), */
/*     B               ' SELL=', SELL,' YC=',YC */
/* SOURCE culvertc.for:504 */
/*<       qmid=qm(iseg) >*/
	    qmid = qm[iseg];
/* SOURCE culvertc.for:505 */
/*<       shtot=tothm(iseg) >*/
	    shtot = tothm[iseg];
/* SOURCE culvertc.for:506 */
/*<       if(qmid.gt.0.0)then >*/
	    if (qmid > (float)0.) {
/* SOURCE culvertc.for:507 */
/*<       crest=eu-hm(iseg) >*/
		crest = static_cast<double>(*eu) - hm[iseg];
/* SOURCE culvertc.for:508 */
/*<       hd=ed-crest >*/
		hd = static_cast<double>(*ed) - crest;
/* SOURCE culvertc.for:509 */
/*<       if(hd.gt.srat*shtot)then >*/
		if (hd > static_cast<double>(srat) * shtot) {
/* SOURCE culvertc.for:510 */
/*<       depth=eu-appm(iseg) >*/
		    depth = static_cast<double>(*eu) - appm[iseg];
/* SOURCE culvertc.for:511 */
/*<        >*/
		    stothq_(&hcwtab, &lcwtab, &subtab, hlcrit, &wm[iseg], &hm[
			    iseg], &hd, &depth, &shtot, &qmid);
/*             COMPUTE ESTIMATE OF  SUBMERGED ENERGY LOSS */
/* SOURCE culvertc.for:519 */
/*<       selm=shtot-(qmid/(hd+depth-hm(iseg)))**2/grav2-hd >*/
/* Computing 2nd power */
		    feq_gen_r_d_1 = static_cast<double>(qmid) / (static_cast<double>(static_cast<double>(hd) + depth) - hm[iseg]);
		    selm = static_cast<double>(static_cast<double>(shtot) - static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / grvcom_1.grav2) - hd;
/*             ESTIMATE CREST DEPTH ASSUMING SOME ENERGY LOSS */
/* SOURCE culvertc.for:522 */
/*<       em=shtot-aelm(iseg)*selm >*/
		    em = static_cast<double>(shtot) - static_cast<double>(aelm[iseg]) * selm;
/* SOURCE culvertc.for:523 */
/*<       yc=invse(qmid,em,hd) >*/
		    yc = invse_(&qmid, &em, &hd);
/* SOURCE culvertc.for:524 */
/*<       yc=max(hd,yc) >*/
		    yc = dmax(hd,yc);
/* SOURCE culvertc.for:525 */
/*<       yc=max(yc,yfm(iseg)) >*/
/* Computing MAX */
		    feq_gen_r_d_1 = yc, feq_gen_r_d_2 = yfm[iseg];
		    yc = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE culvertc.for:526 */
/*<       else >*/
		} else {
/* SOURCE culvertc.for:527 */
/*<       yc=yfm(iseg) >*/
		    yc = yfm[iseg];
/* SOURCE culvertc.for:528 */
/*<       endif >*/
		}
/* SOURCE culvertc.for:529 */
/*<       mmid=qmid**2/yc >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = qmid;
		mmid = static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / yc;
/* SOURCE culvertc.for:530 */
/*<       emid=qmid*((qmid/yc)**2/grav2+crest+yc) >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = static_cast<double>(qmid) / yc;
		emid = static_cast<double>(qmid) * (static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / grvcom_1.grav2) + crest) + yc);
/* SOURCE culvertc.for:531 */
/*<       else >*/
	    } else {
/* SOURCE culvertc.for:532 */
/*<       qmid=0.0 >*/
		qmid = (float)0.;
/* SOURCE culvertc.for:533 */
/*<       mmid=0.0 >*/
		mmid = (float)0.;
/* SOURCE culvertc.for:534 */
/*<       emid=0.0 >*/
		emid = (float)0.;
/* SOURCE culvertc.for:535 */
/*<       endif >*/
	    }
/*         WRITE(STDOUT,*) ' MID: DEPTH=',DEPTH,' HD=',HD,' QMID=', */
/*     A               QMID,' SHTOT=',SHTOT, ' HEAD=',HM(ISEG), */
/*     B               ' SELM=', SELM  ,' YC=',YC */
/* SOURCE culvertc.for:540 */
/*<       qright=qr(iseg) >*/
	    qright = qr[iseg];
/* SOURCE culvertc.for:541 */
/*<       shtot=tothr(iseg) >*/
	    shtot = tothr[iseg];
/* SOURCE culvertc.for:542 */
/*<       if(qright.gt.0.0)then >*/
	    if (qright > (float)0.) {
/* SOURCE culvertc.for:543 */
/*<       crest=eu-hr(iseg) >*/
		crest = static_cast<double>(*eu) - hr[iseg];
/* SOURCE culvertc.for:544 */
/*<       hd=ed-crest >*/
		hd = static_cast<double>(*ed) - crest;
/* SOURCE culvertc.for:545 */
/*<       if(hd.gt.srat*shtot)then >*/
		if (hd > static_cast<double>(srat) * shtot) {
/* SOURCE culvertc.for:546 */
/*<       depth=eu-appr(iseg) >*/
		    depth = static_cast<double>(*eu) - appr[iseg];
/* SOURCE culvertc.for:547 */
/*<        >*/
		    stothq_(&hcwtab, &lcwtab, &subtab, hlcrit, &wr[iseg], &hr[
			    iseg], &hd, &depth, &shtot, &qright);
/*             COMPUTE ESTIMATE OF  SUBMERGED ENERGY LOSS */
/* SOURCE culvertc.for:555 */
/*<       selr=shtot-(qright/(hd+depth-hr(iseg)))**2/grav2-hd >*/
/* Computing 2nd power */
		    feq_gen_r_d_1 = static_cast<double>(qright) / (static_cast<double>(static_cast<double>(hd) + depth) - hr[iseg]);
		    selr = static_cast<double>(static_cast<double>(shtot) - static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / grvcom_1.grav2) - hd;
/*             ESTIMATE CREST DEPTH ASSUMING SOME ENERGY LOSS */
/* SOURCE culvertc.for:558 */
/*<       er=shtot-aelr(iseg)*selr >*/
		    er = static_cast<double>(shtot) - static_cast<double>(aelr[iseg]) * selr;
/* SOURCE culvertc.for:559 */
/*<       yc=invse(qright,er,hd) >*/
		    yc = invse_(&qright, &er, &hd);
/* SOURCE culvertc.for:560 */
/*<       yc=max(yc,hd) >*/
		    yc = dmax(yc,hd);
/* SOURCE culvertc.for:561 */
/*<       yc=max(yc,yfr(iseg)) >*/
/* Computing MAX */
		    feq_gen_r_d_1 = yc, feq_gen_r_d_2 = yfr[iseg];
		    yc = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE culvertc.for:562 */
/*<       else >*/
		} else {
/* SOURCE culvertc.for:563 */
/*<       yc=yfr(iseg) >*/
		    yc = yfr[iseg];
/* SOURCE culvertc.for:564 */
/*<       endif >*/
		}
/* SOURCE culvertc.for:565 */
/*<       mright=qright**2/yc >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = qright;
		mright = static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / yc;
/* SOURCE culvertc.for:566 */
/*<       eright=qright*((qright/yc)**2/grav2+crest+yc) >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = static_cast<double>(qright) / yc;
		eright = static_cast<double>(qright) * (static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / grvcom_1.grav2) + crest) + yc);
/* SOURCE culvertc.for:567 */
/*<       else >*/
	    } else {
/* SOURCE culvertc.for:568 */
/*<       qright=0.0 >*/
		qright = (float)0.;
/* SOURCE culvertc.for:569 */
/*<       mright=0.0 >*/
		mright = (float)0.;
/* SOURCE culvertc.for:570 */
/*<       eright=0.0 >*/
		eright = (float)0.;
/* SOURCE culvertc.for:571 */
/*<       endif >*/
	    }
/*         WRITE(STDOUT,*) ' RIGHT: DEPTH=',DEPTH,' HD=',HD,' QRIGHT=', */
/*     A               QRIGHT,' SHTOT=',SHTOT, ' HEAD=',HR(ISEG), */
/*     B               ' SELR=',SELR,' YC=',YC */
/*         NOW COMPUTE THE FLOW AS AFFECTED BY SUBMERGENCE */
/* SOURCE culvertc.for:579 */
/*<       dx=abs(xr(iseg)-xl(iseg)) >*/
	    dx = (feq_gen_r_d_1 = static_cast<double>(xr[iseg]) - xl[iseg], dabs(feq_gen_r_d_1));
/*         INTEGRATE OVER THE WETTED LENGTH USING SIMPSON'S RULE */
/* SOURCE culvertc.for:583 */
/*<       qseg=dx*(qleft+4.*qmid+qright)/6. >*/
	    qseg = static_cast<double>(static_cast<double>(dx) * (static_cast<double>(static_cast<double>(qleft) + static_cast<double>(qmid) * (float)4.) + qright)) / (float)6.;
/* SOURCE culvertc.for:584 */
/*<       mseg=dx*(mleft+4.*mmid+mright)/6. >*/
	    mseg = static_cast<double>(static_cast<double>(dx) * (static_cast<double>(static_cast<double>(mleft) + static_cast<double>(mmid) * (float)4.) + mright)) / (float)6.;
/* SOURCE culvertc.for:585 */
/*<       eseg=dx*(eleft+4.*emid+eright)/6. >*/
	    eseg = static_cast<double>(static_cast<double>(dx) * (static_cast<double>(static_cast<double>(eleft) + static_cast<double>(emid) * (float)4.) + eright)) / (float)6.;
/*          WRITE(STDOUT,*) ' ' */
/*          WRITE(STDOUT,*) ' DX =',DX */
/*          WRITE(STDOUT,'('' SEG FLOWS:'',3F12.4)') QLEFT, QMID, */
/*     A                                  QRIGHT */
/*          WRITE(STDOUT,'('' QSEG='',F12.4)') */
/*     A                    QSEG */
/* SOURCE culvertc.for:595 */
/*<       qsub=qsub+qseg >*/
	    qsub += qseg;
/* SOURCE culvertc.for:596 */
/*<       msub=msub+mseg >*/
	    msub += mseg;
/* SOURCE culvertc.for:597 */
/*<       esub=esub+eseg >*/
	    esub += eseg;
/* SOURCE culvertc.for:598 */
/*<       endif >*/
	}
/* SOURCE culvertc.for:599 */
/*<  4100 continue >*/
/* L4100: */
    }
/*     STORE THE VALUE AT THIS FRACTION OF THE FREE DROP */
/* SOURCE culvertc.for:603 */
/*<       qroad=qsub >*/
    *qroad = qsub;
/* SOURCE culvertc.for:604 */
/*<       mroad=rmffac*msub >*/
    *mroad = *rmffac * msub;
/* SOURCE culvertc.for:605 */
/*<       eroad=esub >*/
    *eroad = esub;
/*       WRITE(STDOUT,*) ' SBFEBC: QROAD=',QROAD,' MROAD=',MROAD, */
/*     A        ' EROAD=',EROAD */
/* SOURCE culvertc.for:608 */
/*<       return >*/
    return 0;
/* SOURCE culvertc.for:609 */
/*<       end >*/
} /* sbfebc_ */




/* SOURCE culvertc.for:613 */
/*<       subroutinesfpsbe(stdout,iu,id,dh,q,zdn,is,zup,sflag) >*/
/* Subroutine */ int sfpsbe_(integer *stdout, integer *iu, integer *id, real *
	dh, real *q, real *zdn, integer *is, real *zup, integer *sflag)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *ERR:597* INITIAL DEPTH=\002,f10.2,\002 <=\
 0 IN SFPSBE.\002)";
    static char fmt_56[] = "(\002 *ERR:598* TABID=\002,a,\002 overflow seeki\
ng subcritical\002,\002 solution. MaxArg=\002,f10.2)";
    static char fmt_58[] = "(\002 *BUG:XXX* SIGN CHNG ON ENTRY BUT REGFLT CL\
AIMS NONE IN\002,\002 SFPSBE.\002)";
    static char fmt_70[] = "(\002 *BUG:XXX* REGFLT TAKES MORE THAN 100 ITERA\
TIONS:SFPSBE.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    double feq_gen_r_d_1;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real al, dl, fl, dr, fr, jl, kl, jr, qc, sb, tl, tr, xd, xl, yc, xr, yl, yt;
    double el, er, qn, yr;
    integer adl, adr;
    real dkl, qcl, dkr, dtl, qcr, zbl, dtr, zbr, ynl, ynr;
    integer feq_gen_flag_d_;
    real betl, alpl, betr;
    extern doublereal sber_(real *);
    real ymax, ysub;
    char tabid[16];
    extern /* Subroutine */ int fndnd_(integer *, integer *, real *, real *, 
	    real *, real *);
    real dbetl, dalpl, dbetr, dalpr, sbold;
    extern /* Subroutine */ int lktqc_(integer *, real *, real *), xlkt22_(
	    integer *, real *, real *, real *, real *, real *, real *, real *,
	     real *, real *, real *, real *, real *), fndcde_(integer *, 
	    integer *, real *, real *);
    integer ndside;
    double froude;
    extern integer gettbn_(integer *);
    extern doublereal fmxarg_(integer *);
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int regflt_(real *, real *, FeqCallback3, real *, real *, 
	    real *, real *, real *, integer *), xlktal_(integer *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__105 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__120 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__135 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__149 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__150 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__152 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__153 = { 0, 0, 0, fmt_70, 0 };


/*     + + + PURPOSE + + + */
/*     Compute a sub-critial steady flow profile in the channel defined */
/*     by NSEC, XVEC, ZBVEC, IU, AND ID with the starting water surface */
/*     elevation at the downstream end(ID) given in ZDN.  The sequence */
/*     of depths is contained in YVECSB.  The elevation at the upstream end */
/*     of the channel is in ZUP and IS points to the last node at which */
/*     a subcritical flow was found.  SFLAG is used to indicate the */
/*     results:  SFLAG = 1: computations completed and ZUP and YVECSB */
/*     contain the final results.  SFLAG = 0: computations not completed */
/*     supercritical flow was encountered.  It is believed that the */
/*     supercritical flow is physically caused by a steep slope. */
/*     The last valid depth is contained in YVECSB(IS).  SFLAG = -1: */
/*     computations not completed, supercritical flow was encountered */
/*     and it is believed to be caused by DX being too large. The last */
/*     valid depth is again in YVECSB(IS).  SFLAG = -2: computations */
/*     not completed supercritical flow was encountered and it */
/*     is clear that DX was too large.  The last valid depth is */
/*     in YVECSB(IS). SFLAG = -3: no solution found at the last */
/*     point.  SFLAG = 2: initial condition is super critical. */
/*     DH gives estimate of the loss in head over the reach from */
/*     other sources. */
/* SOURCE culvertc.for:639 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertc.for:642 */
/*<       integerid,is,iu,sflag,stdout >*/
/* SOURCE culvertc.for:643 */
/*<       realdh,q,zdn,zup >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     IU     - Index for upstream node for the culvert barrel */
/*     ID     - Index for the downstream node for the culvert barrel */
/*     DH     - Entrance loss for the culvert */
/*     Q      - Flowrate */
/*     ZDN    - Water surface elevation at downstream end of barrel */
/*     IS     - Index of node for the last value computed */
/*     ZUP    - Water surface elevation at section 2 */
/*     SFLAG  - Flag describing results: */
/*                0-results incomplete.  Super critical flow encountered */
/*                  and flow is thought to be caused by a steep slope. */
/*                1-results complete */
/*               -1-results incomplete.  Super critical flow encountered */
/*                  and DX may be too large. */
/*               -2-results incomplete.  Super critical flow encountered */
/*                  and DX is too large. */
/*               -3-no solution found at the last point. */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertc.for:665 */
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
/* INCLUDE culvertc.for:666 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertc.for:667 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE culvertc.for:668 */
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
/* INCLUDE culvertc.for:669 */
/*     Common for function SBER in FEQUTL */
/* SOURCE sberc.cmn:3 */
/*<       common/sberc/rhs,adrs,qt,kr,dx,se,kacc,kdec,ar,alpr,d >*/
/* SOURCE sberc.cmn:4 */
/*<       integeradrs >*/
/* SOURCE sberc.cmn:5 */
/*<       realrhs,qt,kr,dx,se,kacc,kdec,ar,alpr,d >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertc.for:672 */
/*<       integeradl,adr,flag,i,ndside >*/
/* SOURCE culvertc.for:673 */
/*<        >*/
/* SOURCE culvertc.for:677 */
/*<       charactertabid*16 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertc.for:680 */
/*<       intrinsicabs,min,sqrt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertc.for:683 */
/*<       integergettbn,lenstr >*/
/* SOURCE culvertc.for:684 */
/*<       realfmxarg,sber >*/
/* SOURCE culvertc.for:685 */
/*<       characterget_tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertc.for:688 */
/*<        >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertc.for:692 */
/*<    50 format(' *ERR:597* INITIAL DEPTH=',f10.2,' <= 0 IN SFPSBE.') >*/
/* SOURCE culvertc.for:693 */
/*<    56  >*/
/* SOURCE culvertc.for:695 */
/*<    58  >*/
/* SOURCE culvertc.for:697 */
/*<    70 format(' *BUG:XXX* REGFLT TAKES MORE THAN 100 ITERATIONS:SFPSBE.') >*/
/* *********************************************************************** */
/* SOURCE culvertc.for:699 */
/*<       if(dh.gt.0.0)then >*/
/* L50: */
/* L56: */
/* L58: */
/* L70: */
    if (*dh > (float)0.) {
/* SOURCE culvertc.for:700 */
/*<       se=dh/abs(xvec(iu)-xvec(id)) >*/
	sberc_1.se = *dh / (feq_gen_r_d_1 = static_cast<double>(culcom_1.xvec[*iu - 1]) - culcom_1.xvec[*id 
		- 1], dabs(feq_gen_r_d_1));
/* SOURCE culvertc.for:701 */
/*<       elseif(dh.eq.0.0)then >*/
    } else if (*dh == (float)0.) {
/* SOURCE culvertc.for:702 */
/*<       se=0.0 >*/
	sberc_1.se = (float)0.;
/* SOURCE culvertc.for:703 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' SFPSBE: DH=',DH,' SE=',SE */
/*      WRITE(STDOUT,60) */
/* SOURCE culvertc.for:707 */
/*<       qt=q >*/
    sberc_1.qt = *q;
/* SOURCE culvertc.for:709 */
/*<       zbr=zbvec(id) >*/
    zbr = culcom_1.zbvec[*id - 1];
/* SOURCE culvertc.for:710 */
/*<       xd=xvec(id) >*/
    xd = culcom_1.xvec[*id - 1];
/* SOURCE culvertc.for:711 */
/*<       xr=xvec(id) >*/
    xr = culcom_1.xvec[*id - 1];
/* SOURCE culvertc.for:712 */
/*<       xl=xvec(id-1) >*/
    xl = culcom_1.xvec[*id - 2];
/* SOURCE culvertc.for:713 */
/*<       yr=zdn-zbr >*/
    yr = static_cast<double>(*zdn) - zbr;
/*      WRITE(STDOUT,*) ' SFPSBE: YR=',YR */
/* SOURCE culvertc.for:715 */
/*<       yvecsb(id)=yr >*/
    culcom_1.yvecsb[*id - 1] = yr;
/*      ZR = ZDN */
/* SOURCE culvertc.for:717 */
/*<       if(yr.le.0.0)then >*/
    if (yr <= (float)0.) {
/* SOURCE culvertc.for:718 */
/*<       write(stdout,50)yr >*/
	feq_gen_io_d__105.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__105);
	float feq_profile_yr = static_cast<float>(yr);
        do_fio(&feq_gen_c_d_1, (char *)&feq_profile_yr, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culvertc.for:719 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertc.for:720 */
/*<       endif >*/
    }
/* SOURCE culvertc.for:722 */
/*<       adr=nsec(id) >*/
    adr = culcom_1.nsec[*id - 1];
/* SOURCE culvertc.for:723 */
/*<       d=dvec(id) >*/
    sberc_1.feq_gen_d_d_ = culcom_1.dvec[*id - 1];
/* SOURCE culvertc.for:724 */
/*<       yt=min(yr,d) >*/
    yt = dmin(yr,sberc_1.feq_gen_d_d_);
/* SOURCE culvertc.for:725 */
/*<       callxlkt22(adr,yt,ar,tr,dtr,jr,kr,dkr,betr,dbetr,alpr,dalpr,qcr) >*/
    xlkt22_(&adr, &yt, &sberc_1.ar, &tr, &dtr, &jr, &sberc_1.kr, &dkr, &betr, 
	    &dbetr, &sberc_1.alpr, &dalpr, &qcr);
/* SOURCE culvertc.for:731 */
/*<       avec(id)=ar >*/
    culcom_1.avec[*id - 1] = sberc_1.ar;
/* SOURCE culvertc.for:732 */
/*<       kvec(id)=kr >*/
    culcom_1.kvec[*id - 1] = sberc_1.kr;
/*     COMPUTE THE FROUDE NUMBER */
/* SOURCE culvertc.for:735 */
/*<       fr=q/qcr >*/
    fr = static_cast<double>(*q) / qcr;
/*      WRITE(STDOUT,62) ID, XVEC(ID), YR, ZR, DVEC(ID) */
/*      WRITE(STDOUT,*) ' SFPSBE: FR=',FR */
/* SOURCE culvertc.for:739 */
/*<       if(fr.gt.1.025)then >*/
    if (fr > (float)1.025) {
/* SOURCE culvertc.for:740 */
/*<       sflag=2 >*/
	*sflag = 2;
/*        WRITE(STDOUT, 54) FR */
/*        WRITE(STDOUT,*) ' Q=',Q,' AR=',AR,' YR=',YR,' TR=',TR, */
/*     A                  ' ALP4=',ALPR,' DALPR=',DALPR,' QCR=',QCR */
/*        STOP 'Abnormal stop. Errors found.' */
/* SOURCE culvertc.for:745 */
/*<       endif >*/
    }
/* SOURCE culvertc.for:747 */
/*<       dx=abs(xd-xl) >*/
    sberc_1.dx = (feq_gen_r_d_1 = static_cast<double>(xd) - xl, dabs(feq_gen_r_d_1));
/* SOURCE culvertc.for:748 */
/*<       zbl=zbvec(id-1) >*/
    zbl = culcom_1.zbvec[*id - 2];
/* SOURCE culvertc.for:749 */
/*<       sbold=(zbl-zbr)/dx >*/
    sbold = static_cast<double>((static_cast<double>(zbl) - zbr)) / sberc_1.dx;
/*      WRITE(STDOUT,*) ' SBOLD=',SBOLD */
/* SOURCE culvertc.for:751 */
/*<       if(fr.gt.0.975.and.fr.lt.1.025)then >*/
    if (fr > (float).975 && fr < (float)1.025) {
/*       COMPUTE NORMAL FLOW AT INITIAL DEPTH */
/* SOURCE culvertc.for:753 */
/*<       if(sbold.gt.0.0)then >*/
	if (sbold > (float)0.) {
/* SOURCE culvertc.for:754 */
/*<       qn=kr*sqrt(sbold) >*/
	    qn = feq::steady_normal_flow(sberc_1.kr,sbold);
/* SOURCE culvertc.for:755 */
/*<       else >*/
	} else {
/* SOURCE culvertc.for:756 */
/*<       qn=0.0 >*/
	    qn = (float)0.;
/* SOURCE culvertc.for:757 */
/*<       endif >*/
	}
/*        WRITE(STDOUT,*) ' SFPSBE: AT START QCR=',QCR,' QN=',QN */
/* SOURCE culvertc.for:759 */
/*<       if(qn.gt.qcr)then >*/
	if (qn > qcr) {
/*         INITIAL SLOPE IS SUPER CRITICAL.  NO SUB-CRITICAL SOLUTION */
/*         EXISTS WITH INITIAL CRITICAL DEPTH. */
/* SOURCE culvertc.for:762 */
/*<       write(stdout,*)' SFPSBE: Dns invert slope is super critical.' >*/
	    feq_gen_io_d__120.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__120);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" SFPSBE: Dns invert slope is super critica\
l."), (ftnlen)44);
	    e_wsle();
/*          SFLAG = 0   Change to 2 on 27 Feb. 2008. */
/* SOURCE culvertc.for:764 */
/*<       sflag=2 >*/
	    *sflag = 2;
/* SOURCE culvertc.for:765 */
/*<       is=id >*/
	    *is = *id;
/*          WRITE(STDOUT,*) ' ERROR RETURN: IS=',IS,' SFLAG=',SFLAG */
/* SOURCE culvertc.for:767 */
/*<       return >*/
	    return 0;
/* SOURCE culvertc.for:768 */
/*<       endif >*/
	}
/* SOURCE culvertc.for:769 */
/*<       endif >*/
    }
/*     AT THIS POINT THE INITIAL CONDITION IS VALID. START THE LOOP */
/*     MAKE FIRST ESTIMATE OF YC AND YN */
/* SOURCE culvertc.for:773 */
/*<       yc=yr >*/
    yc = yr;
/* SOURCE culvertc.for:774 */
/*<       ynr=yr >*/
    ynr = yr;
/*     COMPUTE NORMAL DEPTH FOR THE INITIAL POINT.  SBOLD IS ASSUMED */
/*     TO BE CONSTANT OVER DX. */
/*      WRITE(STDOUT,*) ' SBOLD=',SBOLD */
/* SOURCE culvertc.for:780 */
/*<       if(sbold.gt.0.0)then >*/
    if (sbold > (float)0.) {
/* SOURCE culvertc.for:781 */
/*<       callfndnd(stdout,adr,q,sbold,dvec(id),ynr) >*/
	fndnd_(stdout, &adr, q, &sbold, &culcom_1.dvec[*id - 1], &ynr);
/* SOURCE culvertc.for:785 */
/*<       else >*/
    } else {
/* SOURCE culvertc.for:786 */
/*<       ynr=0.0 >*/
	ynr = (float)0.;
/* SOURCE culvertc.for:787 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' YNR=',YNR */
/* SOURCE culvertc.for:789 */
/*<       ynvec(id)=ynr >*/
    culcom_1.ynvec[*id - 1] = ynr;
/* SOURCE culvertc.for:790 */
/*<       ynl=ynr >*/
    ynl = ynr;
/* SOURCE culvertc.for:791 */
/*<       adl=adr >*/
    adl = adr;
/*     FIND CRITICAL DEPTH AT START POINT */
/*      WRITE(STDOUT,*) ' ESTIMATED CRITICAL DEPTH=',YC,' Q=',Q */
/* SOURCE culvertc.for:795 */
/*<       callfndcde(stdout,adr,q,yc) >*/
    fndcde_(stdout, &adr, q, &yc);
/*      WRITE(STDOUT,*) ' SFPSBE: CRITICAL DEPTH AT START=',YC,' Q=',Q */
/* SOURCE culvertc.for:800 */
/*<       er=yr+alpr*(q/ar)**2/grav2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(*q) / sberc_1.ar;
    er = feq::steady_specific_energy(yr,*q,sberc_1.ar,sberc_1.alpr,grvcom_1.grav2);
/*      WRITE(STDOUT,*) ' SFPSBE: TEL at exit=', ER +  ZBR */
/*      EVEC(ID) = ER */
/*      YCVEC(ID) = YC */
/*      SFVEC(ID) = (Q/KR)**2 */
/* SOURCE culvertc.for:805 */
/*<       dr=dvec(id) >*/
    dr = culcom_1.dvec[*id - 1];
/* SOURCE culvertc.for:806 */
/*<       do500i=id-1,iu,-1 >*/
    feq_gen_i_d_1 = *iu;
    for (feq_gen_i_d_ = *id - 1; feq_gen_i_d_ >= feq_gen_i_d_1; --feq_gen_i_d_) {
/* SOURCE culvertc.for:807 */
/*<       d=dvec(i) >*/
	sberc_1.feq_gen_d_d_ = culcom_1.dvec[feq_gen_i_d_ - 1];
/* SOURCE culvertc.for:808 */
/*<       dl=d >*/
	dl = sberc_1.feq_gen_d_d_;
/* SOURCE culvertc.for:809 */
/*<       is=i >*/
	*is = feq_gen_i_d_;
/* SOURCE culvertc.for:810 */
/*<       xl=xvec(i) >*/
	xl = culcom_1.xvec[feq_gen_i_d_ - 1];
/* SOURCE culvertc.for:811 */
/*<       dx=abs(xr-xl) >*/
	sberc_1.dx = (feq_gen_r_d_1 = static_cast<double>(xr) - xl, dabs(feq_gen_r_d_1));
/* SOURCE culvertc.for:812 */
/*<       zbl=zbvec(i) >*/
	zbl = culcom_1.zbvec[feq_gen_i_d_ - 1];
/* SOURCE culvertc.for:813 */
/*<       kacc=ka(i+1) >*/
	sberc_1.kacc = culcom_1.ka[feq_gen_i_d_];
/* SOURCE culvertc.for:814 */
/*<       kdec=kd(i+1) >*/
	sberc_1.kdec = culcom_1.kd[feq_gen_i_d_];
/* SOURCE culvertc.for:815 */
/*<       sb=(zbl-zbr)/dx >*/
	sb = static_cast<double>((static_cast<double>(zbl) - zbr)) / sberc_1.dx;
/*        WRITE(STDOUT,*) ' SB=',SB */
/* SOURCE culvertc.for:818 */
/*<       adl=nsec(i) >*/
	adl = culcom_1.nsec[feq_gen_i_d_ - 1];
/*       SET ADDRESS IN COMMON BLOCK FOR RESIDUAL COMPUTATIONS */
/* SOURCE culvertc.for:821 */
/*<       adrs=adl >*/
	sberc_1.adrs = adl;
/* SOURCE culvertc.for:823 */
/*<       if(sb.gt.0.0.and.2.*abs(sb-sbold)/(sb+sbold).gt.5.e-3)then >*/
	if (sb > (float)0. && (feq_gen_r_d_1 = static_cast<double>(sb) - sbold, dabs(feq_gen_r_d_1)) * (float)2. / (
		static_cast<double>(sb) + sbold) > (float).005) {
/*         RECOMPUTE THE NORMAL DEPTH AT RIGHT END. */
/* SOURCE culvertc.for:826 */
/*<       callfndnd(stdout,adr,q,sb,dvec(i+1),ynr) >*/
	    fndnd_(stdout, &adr, q, &sb, &culcom_1.dvec[feq_gen_i_d_], &ynr);
/*          WRITE(STDOUT,*) ' RECOMPUTED YNR=',YNR */
/* SOURCE culvertc.for:831 */
/*<       else >*/
	} else {
/*         USE NORMAL DEPTH FROM UPSTREAM END OF PREVIOUS ELEMENT */
/* SOURCE culvertc.for:834 */
/*<       ynr=ynl >*/
	    ynr = ynl;
/* SOURCE culvertc.for:835 */
/*<       endif >*/
	}
/* SOURCE culvertc.for:837 */
/*<       if(adr.ne.adl)then >*/
	if (adr != adl) {
/* SOURCE culvertc.for:838 */
/*<       callfndcde(stdout,adl,q,yc) >*/
	    fndcde_(stdout, &adl, q, &yc);
/*          WRITE(STDOUT,*) ' SFPSBE: CRITICAL DEPTH=', YC */
/* SOURCE culvertc.for:842 */
/*<       if(sb.gt.0.0)then >*/
	    if (sb > (float)0.) {
/* SOURCE culvertc.for:843 */
/*<       callfndnd(stdout,adl,q,sb,dvec(i),ynl) >*/
		fndnd_(stdout, &adl, q, &sb, &culcom_1.dvec[feq_gen_i_d_ - 1], &ynl);
/*            WRITE(STDOUT,*) ' RECOMPUTED YNL=',YNL */
/* SOURCE culvertc.for:848 */
/*<       else >*/
	    } else {
/* SOURCE culvertc.for:849 */
/*<       ynl=0.0 >*/
		ynl = (float)0.;
/* SOURCE culvertc.for:850 */
/*<       endif >*/
	    }
/* SOURCE culvertc.for:851 */
/*<       else >*/
	} else {
/* SOURCE culvertc.for:852 */
/*<       ynl=ynr >*/
	    ynl = ynr;
/* SOURCE culvertc.for:853 */
/*<       endif >*/
	}
/*        WRITE(STDOUT,*) ' YNL=',YNL */
/*       SET THE SIDE OF NORMAL DEPTH FOR THE INITIAL DEPTH IN THIS */
/*       ELEMENT */
/* SOURCE culvertc.for:858 */
/*<       if(yr.ge.ynr)then >*/
	if (yr >= ynr) {
/* SOURCE culvertc.for:859 */
/*<       ndside=1 >*/
	    ndside = 1;
/* SOURCE culvertc.for:860 */
/*<       else >*/
	} else {
/* SOURCE culvertc.for:861 */
/*<       ndside=-1 >*/
	    ndside = -1;
/* SOURCE culvertc.for:862 */
/*<       endif >*/
	}
/*        WRITE(STDOUT,*) ' NDSIDE=',NDSIDE */
/*       COMPUTE THE CONSTANT PART OF THE EQUATION */
/* SOURCE culvertc.for:868 */
/*<       rhs=er+zbr-zbl >*/
	sberc_1.rhs = static_cast<double>(static_cast<double>(er) + zbr) - zbl;
/*        RHS = ER + ZBR - ZBL + DX*SE */
/*         WRITE(STDOUT,*) ' RHS=',RHS */
/* SOURCE culvertc.for:873 */
/*<       ymax=fmxarg(adl) >*/
	ymax = fmxarg_(&adl);
/* SOURCE culvertc.for:875 */
/*<       yt=yc >*/
	yt = yc;
/* SOURCE culvertc.for:876 */
/*<       fl=sber(yt) >*/
	fl = sber_(&yt);
/*        WRITE(STDOUT,*) ' YT=',YT,' FL=',FL */
/* SOURCE culvertc.for:878 */
/*<       if(fl.le.0.0)then >*/
	if (fl <= (float)0.) {
/*         SUBCRITICAL SOLUTION EXISTS.  SEARCH FOR A POSITIVE */
/*         RESIDUAL */
/* SOURCE culvertc.for:882 */
/*<       if(yr.gt.yc)then >*/
	    if (yr > yc) {
/* SOURCE culvertc.for:883 */
/*<       ysub=yr >*/
		ysub = yr;
/* SOURCE culvertc.for:884 */
/*<       else >*/
	    } else {
/* SOURCE culvertc.for:885 */
/*<       ysub=1.01*yc >*/
		ysub = static_cast<double>(yc) * (float)1.01;
/* SOURCE culvertc.for:886 */
/*<       endif >*/
	    }
/* SOURCE culvertc.for:888 */
/*<   110 continue >*/
L110:
/* SOURCE culvertc.for:889 */
/*<       fr=sber(ysub) >*/
	    fr = sber_(&ysub);
/*            WRITE(STDOUT,*) ' YSUB=',YSUB,' FR=',FR */
/* SOURCE culvertc.for:891 */
/*<       if(fr.lt.0.0)then >*/
	    if (fr < (float)0.) {
/* SOURCE culvertc.for:892 */
/*<       fl=fr >*/
		fl = fr;
/* SOURCE culvertc.for:893 */
/*<       yt=ysub >*/
		yt = ysub;
/* SOURCE culvertc.for:894 */
/*<       ysub=1.05*ysub >*/
		ysub *= static_cast<double>((float)1.05);
/* SOURCE culvertc.for:895 */
/*<       if(abs(ymax-ysub).le.epsarg)then >*/
		if ((feq_gen_r_d_1 = static_cast<double>(ymax) - ysub, dabs(feq_gen_r_d_1)) <= epscom_1.epsarg) {
/* SOURCE culvertc.for:896 */
/*<       tabid=get_tabid(gettbn(adl)) >*/
		    feq_gen_i_d_2 = gettbn_(&adl);
		    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_2);
		    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE culvertc.for:897 */
/*<       write(stdout,56)tabid(1:lenstr(tabid)),ymax >*/
		    feq_gen_io_d__135.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__135);
		    do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
		    do_fio(&feq_gen_c_d_1, (char *)&ymax, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE culvertc.for:898 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertc.for:899 */
/*<       endif >*/
		}
/* SOURCE culvertc.for:900 */
/*<       goto110 >*/
		goto L110;
/* SOURCE culvertc.for:901 */
/*<       endif >*/
	    }
/* SOURCE culvertc.for:902 */
/*<       else >*/
	} else {
/*         NO SUBCRITICAL SOLUTION */
/* SOURCE culvertc.for:904 */
/*<       if(abs(fl).lt.epsf)then >*/
	    if (dabs(fl) < epscom_1.epsf) {
/*           Take critical depth as the result. */
/* SOURCE culvertc.for:906 */
/*<       yl=yc >*/
		yl = yc;
/* SOURCE culvertc.for:907 */
/*<       callxlkt22(adl,yl,al,tl,dtl,jl,kl,dkl,betl,dbetl,alpl,dalpl,qcl) >*/
		xlkt22_(&adl, &yl, &al, &tl, &dtl, &jl, &kl, &dkl, &betl, &
			dbetl, &alpl, &dalpl, &qcl);
/* SOURCE culvertc.for:912 */
/*<       froude=1.0 >*/
		froude = (float)1.;
/* SOURCE culvertc.for:913 */
/*<       goto200 >*/
		goto L200;
/* SOURCE culvertc.for:914 */
/*<       endif >*/
	    }
/*         USE NORMAL DEPTH.  IF THE SUPERCRITICAL DEPTH IS SPURIOUS */
/*         NORMAL DEPTH SHOULD PASS THE TESTS FOR A VALID SOLUTION */
/*          WRITE(STDOUT,*) ' TAKING NORMAL DEPTH=',YNL */
/* SOURCE culvertc.for:918 */
/*<       if(ynl.eq.0.0)then >*/
	    if (ynl == (float)0.) {
/* SOURCE culvertc.for:919 */
/*<        >*/
		feq_gen_io_d__149.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__149);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:698* No subcritical solution"), (
			ftnlen)34);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" in steady flow profile."), (ftnlen)24);
		e_wsle();
/* SOURCE culvertc.for:921 */
/*<       write(stdout,*)' Try reducing step length' >*/
		feq_gen_io_d__150.ciunit = *stdout;
		s_wsle(&feq_gen_io_d__150);
		do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Try reducing step length"), (ftnlen)25);
		e_wsle();
/* SOURCE culvertc.for:922 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertc.for:923 */
/*<       endif >*/
	    }
/* SOURCE culvertc.for:924 */
/*<       yl=ynl >*/
	    yl = ynl;
/* SOURCE culvertc.for:925 */
/*<       yt=min(yl,d) >*/
	    yt = dmin(yl,sberc_1.feq_gen_d_d_);
/* SOURCE culvertc.for:926 */
/*<       callxlkt22(adl,yt,al,tl,dtl,jl,kl,dkl,betl,dbetl,alpl,dalpl,qcl) >*/
	    xlkt22_(&adl, &yt, &al, &tl, &dtl, &jl, &kl, &dkl, &betl, &dbetl, 
		    &alpl, &dalpl, &qcl);

/* SOURCE culvertc.for:932 */
/*<       froude=q/qcl >*/
	    froude = static_cast<double>(*q) / qcl;
/*          WRITE(STDOUT,*) ' NORMAL DEPTH FROUDE=',FROUDE */
/* SOURCE culvertc.for:934 */
/*<       goto200 >*/
	    goto L200;
/* SOURCE culvertc.for:935 */
/*<       endif >*/
	}
/*       WE HAVE A SIGN CHANGE IN THE INTERVAL (YC, YSUB) OR */
/*       AT LEAST ONE RESIDUAL IS ZERO */
/*        WRITE(STDOUT,*) ' ROOT BRACKETED' */
/*        WRITE(STDOUT,*) ' YLOW=',YT,' FL=',FL */
/*        WRITE(STDOUT,*) ' YHIGH=',YSUB,' FH=',FR */
/* SOURCE culvertc.for:944 */
/*<       callregflt(0.0,5.e-6,sber,yt,ysub,fl,fr,yl,flag) >*/
	regflt_(&c_b50, &c_b51, sber_, &yt, &ysub, &fl, &fr, &yl, &
		feq_gen_flag_d_);
/* SOURCE culvertc.for:948 */
/*<       if(flag.eq.1)then >*/
	if (feq_gen_flag_d_ == 1) {
/* SOURCE culvertc.for:949 */
/*<       write(stdout,58) >*/
	    feq_gen_io_d__152.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__152);
	    e_wsfe();
/* SOURCE culvertc.for:950 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertc.for:951 */
/*<       elseif(flag.eq.2)then >*/
	} else if (feq_gen_flag_d_ == 2) {
/* SOURCE culvertc.for:952 */
/*<       write(stdout,70) >*/
	    feq_gen_io_d__153.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__153);
	    e_wsfe();
/* SOURCE culvertc.for:953 */
/*<       stop'Abnormal stop. Errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertc.for:954 */
/*<       endif >*/
	}
/*        WRITE(STDOUT,*) ' YL=',YL,' FL=',FL */
/* SOURCE culvertc.for:956 */
/*<       yt=min(yl,d) >*/
	yt = dmin(yl,sberc_1.feq_gen_d_d_);
/* SOURCE culvertc.for:957 */
/*<       callxlktal(adl,yt,al,tl,dtl,jl,kl,dkl,betl,dbetl,alpl,dalpl) >*/
	xlktal_(&adl, &yt, &al, &tl, &dtl, &jl, &kl, &dkl, &betl, &dbetl, &
		alpl, &dalpl);
/*       CHECK IF THE SOLUTION IS VALID.  ALLOW SLIGHTLY SUPERCRITICAL */
/*       FLOW TO ACCOMMADATE THE DISCREPENCIES IN TABULATED CRITICAL */
/*       FLOWS. */
/* SOURCE culvertc.for:966 */
/*<       calllktqc(adl,yt,qc) >*/
	lktqc_(&adl, &yt, &qc);
/* SOURCE culvertc.for:970 */
/*<       froude=q/qc >*/
	froude = static_cast<double>(*q) / qc;
/*        WRITE(STDOUT,*) ' AT YL=',YL,' FROUDE=',FROUDE */
/* SOURCE culvertc.for:973 */
/*<   200 continue >*/
L200:
/* SOURCE culvertc.for:974 */
/*<       if(froude.gt.1.05)then >*/
	if (froude > (float)1.05) {
/*         SOLUTION IS NO LONGER VALID. */
/*         NO SUBCRITICAL SOLUTION EXISTS. */
/*          WRITE(STDOUT,*) ' AT YL=',YL,' FROUDE=',FROUDE,' IS=',IS */
/* SOURCE culvertc.for:979 */
/*<       sb=(zbl-zbr)/dx >*/
	    sb = static_cast<double>((static_cast<double>(zbl) - zbr)) / sberc_1.dx;
/* SOURCE culvertc.for:980 */
/*<       is=i+1 >*/
	    *is = feq_gen_i_d_ + 1;
/*         Store current critical depth in current node's slot. */
/* SOURCE culvertc.for:982 */
/*<       yvecsb(i)=yc >*/
	    culcom_1.yvecsb[feq_gen_i_d_ - 1] = yc;
/* SOURCE culvertc.for:983 */
/*<       if(sb.le.0.0)then >*/
	    if (sb <= (float)0.) {
/*           SUPER CRITICAL FLOW IS CLEARLY A COMPUTATIONAL ARTIFACT */
/* SOURCE culvertc.for:985 */
/*<       sflag=-2 >*/
		*sflag = -2;
/* SOURCE culvertc.for:986 */
/*<       else >*/
	    } else {
/* SOURCE culvertc.for:987 */
/*<       qn=kl*sqrt(sb) >*/
		qn = feq::steady_normal_flow(kl,sb);
/*            WRITE(STDOUT,*) ' QN AT LEFT=',QN */
/* SOURCE culvertc.for:989 */
/*<       if(qn.gt.qc)then >*/
		if (qn > qc) {
/*             SUPER CRITICAL FLOW MAY HAVE A PHYSICAL BASIS */
/* SOURCE culvertc.for:991 */
/*<       sflag=0 >*/
		    *sflag = 0;
/* SOURCE culvertc.for:992 */
/*<       else >*/
		} else {
/*             CHANNEL SLOPE IS NOT STEEP. COMPUTATIONAL ARTIFACT. */
/* SOURCE culvertc.for:994 */
/*<       sflag=-2 >*/
		    *sflag = -2;
/* SOURCE culvertc.for:995 */
/*<       endif >*/
		}
/* SOURCE culvertc.for:996 */
/*<       endif >*/
	    }
/*          WRITE(STDOUT,*) ' ERROR RETURN: IS=',IS,' SFLAG=',SFLAG */
/*          GOTO 501 */
/* SOURCE culvertc.for:999 */
/*<       zup=yl+zbl >*/
	    *zup = static_cast<double>(yl) + zbl;
/* SOURCE culvertc.for:1000 */
/*<       return >*/
	    return 0;
/* SOURCE culvertc.for:1001 */
/*<       endif >*/
	}
/* SOURCE culvertc.for:1003 */
/*<       if(ynl.lt.dl.and.ynr.lt.dr)then >*/
	if (ynl < dl && ynr < dr) {
/*         CHECK IF ESTIMATED PROFILE HAS CROSSED NORMAL DEPTH */
/*         when flow is free surface at both ends. */
/* SOURCE culvertc.for:1006 */
/*<       if(ndside.eq.1)then >*/
	    if (ndside == 1) {
/*           PROFILE WAS ABOVE NORMAL DEPTH AT START */
/* SOURCE culvertc.for:1008 */
/*<       if(yl.lt.ynl)then >*/
		if (yl < ynl) {
/*             CROSSING NORMAL DEPTH.  FORCE YL TO BE AT NORMAL DEPTH */
/* SOURCE culvertc.for:1010 */
/*<       yl=ynl >*/
		    yl = ynl;
/* SOURCE culvertc.for:1011 */
/*<       yt=min(d,yl) >*/
		    yt = dmin(sberc_1.feq_gen_d_d_,yl);
/* SOURCE culvertc.for:1012 */
/*<       callxlktal(adl,yt,al,tl,dtl,jl,kl,dkl,betl,dbetl,alpl,dalpl) >*/
		    xlktal_(&adl, &yt, &al, &tl, &dtl, &jl, &kl, &dkl, &betl, 
			    &dbetl, &alpl, &dalpl);
/* SOURCE culvertc.for:1017 */
/*<       endif >*/
		}
/* SOURCE culvertc.for:1018 */
/*<       else >*/
	    } else {
/*           PROFILE AT START WAS BELOW NORMAL DEPTH */
/* SOURCE culvertc.for:1020 */
/*<       if(yl.gt.ynl)then >*/
		if (yl > ynl) {
/*             CROSSING NORMAL DEPTH.  FORCE YL TO BE AT NORMAL DEPTH */
/* SOURCE culvertc.for:1022 */
/*<       yl=ynl >*/
		    yl = ynl;
/* SOURCE culvertc.for:1023 */
/*<       yt=min(d,yl) >*/
		    yt = dmin(sberc_1.feq_gen_d_d_,yl);
/* SOURCE culvertc.for:1024 */
/*<       callxlktal(adl,yt,al,tl,dtl,jl,kl,dkl,betl,dbetl,alpl,dalpl) >*/
		    xlktal_(&adl, &yt, &al, &tl, &dtl, &jl, &kl, &dkl, &betl, 
			    &dbetl, &alpl, &dalpl);
/* SOURCE culvertc.for:1029 */
/*<       endif >*/
		}
/* SOURCE culvertc.for:1030 */
/*<       endif >*/
	    }
/* SOURCE culvertc.for:1031 */
/*<       endif >*/
	}
/*        ZL = ZBL + YL */
/* SOURCE culvertc.for:1033 */
/*<       el=yl+alpl*(q/al)**2/grav2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(*q) / al;
	el = feq::steady_specific_energy(yl,*q,al,alpl,grvcom_1.grav2);
/* SOURCE culvertc.for:1034 */
/*<       er=el >*/
	er = el;
/* SOURCE culvertc.for:1035 */
/*<       zbr=zbl >*/
	zbr = zbl;
/* SOURCE culvertc.for:1036 */
/*<       yr=yl >*/
	yr = yl;
/* SOURCE culvertc.for:1037 */
/*<       xr=xl >*/
	xr = xl;
/* SOURCE culvertc.for:1039 */
/*<       ar=al >*/
	sberc_1.ar = al;
/* SOURCE culvertc.for:1040 */
/*<       alpr=alpl >*/
	sberc_1.alpr = alpl;
/* SOURCE culvertc.for:1041 */
/*<       kr=kl >*/
	sberc_1.kr = kl;
/* SOURCE culvertc.for:1042 */
/*<       adr=adl >*/
	adr = adl;
/* SOURCE culvertc.for:1043 */
/*<       sbold=sb >*/
	sbold = sb;
/* SOURCE culvertc.for:1044 */
/*<       dr=dl >*/
	dr = dl;
/* SOURCE culvertc.for:1045 */
/*<       avec(i)=al >*/
	culcom_1.avec[feq_gen_i_d_ - 1] = al;
/* SOURCE culvertc.for:1046 */
/*<       kvec(i)=kl >*/
	culcom_1.kvec[feq_gen_i_d_ - 1] = kl;
/*        EVEC(I) = EL */
/* SOURCE culvertc.for:1048 */
/*<       yvecsb(i)=yl >*/
	culcom_1.yvecsb[feq_gen_i_d_ - 1] = yl;
/*        YNVEC(I) = YNL */
/*        YCVEC(I) = YC */
/*        SFVEC(I) = (Q/KL)**2 */
/* SOURCE culvertc.for:1052 */
/*<   500 continue >*/
/* L500: */
    }
/* 501   CONTINUE */
/*      WRITE(STDOUT,*) ' SE=',SE,' Q=',Q */
/*      WRITE(STDOUT,60) */
/*      SUM = 0.0 */
/*      DO 700 I=IS,ID */
/*        WRITE(STDOUT,62) I, XVEC(I), YVECSB(I), YCVEC(I), YNVEC(I), */
/*     A      ZBVEC(I), YVECSB(I) + ZBVEC(I), DVEC(I), SFVEC(I), */
/*     B      EVEC(I) + ZBVEC(I) */
/*        SUM = SUM + SFVEC(I) */
/* 700   CONTINUE */
/*      SUM = SUM - .5*(SFVEC(IU) + SFVEC(ID)) - */
/*     A      (SFVEC(ID) - SFVEC(ID-1) - SFVEC(2) + SFVEC(1))/12.0 */
/*      DE = SUM*ABS(XVEC(ID) - XVEC(IU))/FLOAT(ID - IU) + DH */
/*      WRITE(STDOUT,*) ' DE BY INTEGRATION=',DE, ' DE BY SUBTRACTION=', */
/*     A       EVEC(IU) + ZBVEC(IU) - EVEC(ID) - ZBVEC(ID) */
/*      WRITE(STDOUT,*) ' SFPSBE: TEL at entrance=', EL +  ZBL */
/* SOURCE culvertc.for:1071 */
/*<       zup=yl+zbl >*/
    *zup = static_cast<double>(yl) + zbl;
/* SOURCE culvertc.for:1072 */
/*<       is=iu >*/
    *is = *iu;
/* SOURCE culvertc.for:1073 */
/*<       sflag=1 >*/
    *sflag = 1;
/* SOURCE culvertc.for:1074 */
/*<       return >*/
    return 0;
/* SOURCE culvertc.for:1075 */
/*<       end >*/
} /* sfpsbe_ */




/* SOURCE culvertc.for:1079 */
/*<       subroutinesfpspe(stdout,iu,id,q,zup,is,zdn,sflag) >*/
/* Subroutine */ int sfpspe_(integer *stdout, integer *iu, integer *id, real *
	q, real *zup, integer *is, real *zdn, integer *sflag)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *ERR:599* INITIAL DEPTH=\002,f10.2,\002 <=\
 0 IN SFPSPE.\002)";
    static char fmt_54[] = "(\002 *BUG:XXX* INITIAL CONDITION IN SFPSPE HAS \
FR=\002,f7.2,\002 < 1.\002)";
    static char fmt_56[] = "(\002 *BUG:XXX* TABID=\002,a,\002 UNDERFLOW SEEK\
ING SUPER\002,\002 CRITICAL SOLUTION.\002)";
    static char fmt_58[] = "(\002 *BUG:XXX* SIGN CHNG ON ENTRY BUT REGFLT CL\
AIMS NONE IN\002,\002 SFPSPE.\002)";
    static char fmt_60[] = "(\002 *BUG:XXX* REGFLT TAKES MORE THAN 100 ITERA\
TIONS:SFPSPE.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real ac, ec, jc, el, ar, fl, kc, jl, er, fr, sb, jr, kr, qn, tc, tl, tr, 
	    yc, yl, yr, yt, dkc, dkl, dtc, qcl, dkr, dtl, sfm, zbl, dtr, zbr;
    integer feq_gen_flag_d_;
    real betc, alpc, betl;
    integer adrs;
    real alpr, betr;
    extern doublereal sper_(real *);
    real ysup, dbetc, dalpc;
    char tabid[16];
    real dbetl, dalpl, dbetr, dalpr;
    extern /* Subroutine */ int xlkt22_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *), fndcde_(integer *, integer *, real *, real *);
    integer adrold;
    extern integer gettbn_(integer *);
    extern /* Subroutine */ int regflt_(real *, real *, FeqCallback3, real *, real *, 
	    real *, real *, real *, integer *);
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int xlktal_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__159 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__171 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__193 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__196 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__197 = { 0, 0, 0, fmt_60, 0 };


/*     + + + PURPOSE + + + */
/*     Compute a super critial steady flow profile in the channel defined */
/*     by NSEC, XVEC, ZBVEC, IU, and ID with the starting water surface */
/*     elevation at the upstream end(IU) given in ZUP.  The sequence */
/*     of depths is contained in YVECSP.  the elevation at the downstream end */
/*     of the channel is in ZDN and IS points to the last node at which */
/*     a super critical flow was found.  SFLAG is used to indicate the */
/*     results:  SFLAG = 1: computations completed and ZDN and YVECSP */
/*     contain the final results.  SFLAG = 0: computations not completed */
/*     subcritical flow was encountered.  It is believed that the */
/*     subcritical flow is physically caused by a less than steep slope. */
/*     The last valid depth is contained in YVECSP(IS).  SFLAG = -1: */
/*     computations not completed subcritical flow was encountered */
/*     and it is believed to be caused by DX being too large. The last */
/*     valid depth is again in YVECSP(IS).  SFLAG = -2: computations */
/*     not completed subcritical flow was encountered and it */
/*     is clear that DX was too large.  The last valid depth is */
/*     in YVECSP(IS). */
/* SOURCE culvertc.for:1102 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertc.for:1105 */
/*<       integerid,is,iu,sflag,stdout >*/
/* SOURCE culvertc.for:1106 */
/*<       realq,zdn,zup >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     IU     - Index for upstream node for the culvert barrel */
/*     ID     - Index for the downstream node for the culvert barrel */
/*     Q      - Flowrate */
/*     ZUP    - Water surface elevation at section 2 */
/*     IS     - Index of node for the last value computed */
/*     ZDN    - Water surface elevation at downstream end of barrel */
/*     SFLAG  - Flag describing results: */
/*                0-results incomplete.  Super critical flow encountered */
/*                  and flow is thought to be caused by a steep slope. */
/*                1-results complete */
/*               -1-results incomplete.  Super critical flow encountered */
/*                  and DX may be too large. */
/*               -2-results incomplete.  Super critical flow encountered */
/*                  and DX is too large. */
/*               -3-no solution found at the last point. */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertc.for:1127 */
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
/* INCLUDE culvertc.for:1128 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertc.for:1129 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE culvertc.for:1130 */
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
/* INCLUDE culvertc.for:1131 */
/*     Common for function SPER in FEQUTL */
/* SOURCE sperc.cmn:3 */
/*<       common/sperc/rhs,adr,qr,ql,kl,dx,al,alpl,kacc,kdec,d,se >*/
/* SOURCE sperc.cmn:5 */
/*<       integeradr >*/
/* SOURCE sperc.cmn:6 */
/*<       realrhs,qr,ql,kl,dx,al,alpl,kacc,kdec,d,se >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertc.for:1134 */
/*<       integeradrold,adrs,flag,i >*/
/* SOURCE culvertc.for:1135 */
/*<        >*/
/* SOURCE culvertc.for:1139 */
/*<       charactertabid*16 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertc.for:1142 */
/*<       intrinsicabs,min,sqrt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertc.for:1145 */
/*<       integergettbn,lenstr >*/
/* SOURCE culvertc.for:1146 */
/*<       realsper >*/
/* SOURCE culvertc.for:1147 */
/*<       characterget_tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertc.for:1150 */
/*<       externalfndcde,gettbn,regflt,sper,xlkt22,xlktal,lenstr,get_tabid >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertc.for:1154 */
/*<    50 format(' *ERR:599* INITIAL DEPTH=',f10.2,' <= 0 IN SFPSPE.') >*/
/* SOURCE culvertc.for:1155 */
/*<    54  >*/
/* SOURCE culvertc.for:1157 */
/*<    56  >*/
/* SOURCE culvertc.for:1159 */
/*<    58  >*/
/* SOURCE culvertc.for:1161 */
/*<    60 format(' *BUG:XXX* REGFLT TAKES MORE THAN 100 ITERATIONS:SFPSPE.') >*/
/* *********************************************************************** */
/* SOURCE culvertc.for:1163 */
/*<       qr=q >*/
/* L50: */
/* L54: */
/* L56: */
/* L58: */
/* L60: */
    sperc_1.qr = *q;
/* SOURCE culvertc.for:1164 */
/*<       ql=q >*/
    sperc_1.ql = *q;
/* SOURCE culvertc.for:1165 */
/*<       adrold=-1 >*/
    adrold = -1;
/* SOURCE culvertc.for:1166 */
/*<       zbl=zbvec(iu) >*/
    zbl = culcom_1.zbvec[*iu - 1];
/* SOURCE culvertc.for:1167 */
/*<       yl=zup-zbl >*/
    yl = static_cast<double>(*zup) - zbl;
/* SOURCE culvertc.for:1168 */
/*<       if(yl.le.0.0)then >*/
    if (yl <= (float)0.) {
/* SOURCE culvertc.for:1169 */
/*<       write(stdout,50)yl >*/
	feq_gen_io_d__159.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__159);
	do_fio(&feq_gen_c_d_1, (char *)&yl, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culvertc.for:1170 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertc.for:1171 */
/*<       endif >*/
    }
/* SOURCE culvertc.for:1173 */
/*<       adrs=nsec(iu) >*/
    adrs = culcom_1.nsec[*iu - 1];
/* SOURCE culvertc.for:1174 */
/*<       d=dvec(iu) >*/
    sperc_1.feq_gen_d_d_ = culcom_1.dvec[*iu - 1];
/* SOURCE culvertc.for:1175 */
/*<       yt=min(d,yl) >*/
    yt = dmin(sperc_1.feq_gen_d_d_,yl);
/* SOURCE culvertc.for:1176 */
/*<       callxlkt22(adrs,yt,al,tl,dtl,jl,kl,dkl,betl,dbetl,alpl,dalpl,qcl) >*/
    xlkt22_(&adrs, &yt, &sperc_1.al, &tl, &dtl, &jl, &sperc_1.kl, &dkl, &betl,
	     &dbetl, &sperc_1.alpl, &dalpl, &qcl);
/* SOURCE culvertc.for:1182 */
/*<       fr=(ql/qcl)**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(sperc_1.ql) / qcl;
    fr = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE culvertc.for:1183 */
/*<       if(fr.lt.0.995)then >*/
    if (fr < (float).995) {
/* SOURCE culvertc.for:1184 */
/*<       write(stdout,54)fr >*/
	feq_gen_io_d__171.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__171);
	do_fio(&feq_gen_c_d_1, (char *)&fr, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culvertc.for:1185 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertc.for:1186 */
/*<       endif >*/
    }
/*     AT THIS POINT THE INITIAL CONDITION IS VALID. START THE LOOP */
/* SOURCE culvertc.for:1190 */
/*<       el=yl+alpl*(ql/al)**2/grav2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(sperc_1.ql) / sperc_1.al;
    el = static_cast<double>(yl) + static_cast<double>(static_cast<double>(sperc_1.alpl) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / grvcom_1.grav2;
/* SOURCE culvertc.for:1191 */
/*<       yvecsp(iu)=yl >*/
    culcom_1.yvecsp[*iu - 1] = yl;
/*     MAKE FIRST ESTIMATE OF YC */
/* SOURCE culvertc.for:1193 */
/*<       yc=yl >*/
    yc = yl;
/* SOURCE culvertc.for:1194 */
/*<       do500i=iu+1,id >*/
    feq_gen_i_d_1 = *id;
    for (feq_gen_i_d_ = *iu + 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culvertc.for:1195 */
/*<       d=dvec(i) >*/
	sperc_1.feq_gen_d_d_ = culcom_1.dvec[feq_gen_i_d_ - 1];
/* SOURCE culvertc.for:1196 */
/*<       se=sevec(i) >*/
	sperc_1.se = culcom_1.sevec[feq_gen_i_d_ - 1];
/* SOURCE culvertc.for:1197 */
/*<       dx=abs(xvec(i-1)-xvec(i)) >*/
	sperc_1.dx = (feq_gen_r_d_1 = static_cast<double>(culcom_1.xvec[feq_gen_i_d_ - 2]) - culcom_1.xvec[feq_gen_i_d_ - 1], 
		dabs(feq_gen_r_d_1));
/* SOURCE culvertc.for:1198 */
/*<       zbr=zbvec(i) >*/
	zbr = culcom_1.zbvec[feq_gen_i_d_ - 1];
/* SOURCE culvertc.for:1199 */
/*<       kacc=ka(i) >*/
	sperc_1.kacc = culcom_1.ka[feq_gen_i_d_ - 1];
/* SOURCE culvertc.for:1200 */
/*<       kdec=kd(i) >*/
	sperc_1.kdec = culcom_1.kd[feq_gen_i_d_ - 1];
/*       FIND CRITICAL DEPTH AT THE CURRENT LOCATION. USE LAST */
/*       AVAILABLE DEPTH AS THE FIRST ESTIMATE. */
/* SOURCE culvertc.for:1204 */
/*<       adrs=nsec(i) >*/
	adrs = culcom_1.nsec[feq_gen_i_d_ - 1];
/* SOURCE culvertc.for:1205 */
/*<       adr=adrs >*/
	sperc_1.adr = adrs;
/* SOURCE culvertc.for:1206 */
/*<       if(adr.ne.adrold.or.ql.ne.qr)then >*/
	if (sperc_1.adr != adrold || sperc_1.ql != sperc_1.qr) {
/* SOURCE culvertc.for:1207 */
/*<       callfndcde(stdout,adrs,qr,yc) >*/
	    fndcde_(stdout, &adrs, &sperc_1.qr, &yc);
/*         COMPUTE SPECIFIC ENERGY AT CRITICAL DEPTH */
/* SOURCE culvertc.for:1213 */
/*<       callxlktal(adrs,yc,ac,tc,dtc,jc,kc,dkc,betc,dbetc,alpc,dalpc) >*/
	    xlktal_(&adrs, &yc, &ac, &tc, &dtc, &jc, &kc, &dkc, &betc, &dbetc,
		     &alpc, &dalpc);
/* SOURCE culvertc.for:1219 */
/*<       ec=yc+alpc*(qr/ac)**2/grav2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(sperc_1.qr) / ac;
	    ec = static_cast<double>(yc) + static_cast<double>(static_cast<double>(alpc) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / grvcom_1.grav2;
/* SOURCE culvertc.for:1220 */
/*<       endif >*/
	}
/*       COMPUTE THE AVERAGE FRICTION SLOPE FOR THE ELEMENT */
/*       ASSUMING CRITICAL FLOW AT THE CURRENT NODE */
/* SOURCE culvertc.for:1224 */
/*<       sfm=ql*qr/(kc*kl) >*/
	sfm = static_cast<double>(static_cast<double>(sperc_1.ql) * sperc_1.qr) / (static_cast<double>(kc) * sperc_1.kl);
/*       COMPUTE THE CONSTANT PART OF THE EQUATION */
/* SOURCE culvertc.for:1228 */
/*<       rhs=el+zbl-zbr >*/
	sperc_1.rhs = static_cast<double>(static_cast<double>(el) + zbl) - zbr;
/*       CHECK FOR EXISTENCE OF A SUPER CRITICAL SOLUTION */
/* SOURCE culvertc.for:1232 */
/*<       if(ec+dx*(sfm+se).gt.rhs)then >*/
	if (static_cast<double>(ec) + static_cast<double>(sperc_1.dx) * (static_cast<double>(sfm) + sperc_1.se) > sperc_1.rhs) {
/*         NO SUPER CRITICAL SOLUTION EXISTS. */
/*          WRITE(STDOUT,*)  ' EC + DX*(SFM+SE)=',EC + DX*(SFM+SE) */
/*          WRITE(STDOUT,*) ' RHS=',RHS */

/*         Store current value of critical depth in the current */
/*         node's position.  Needed in some applications. */
/* SOURCE culvertc.for:1239 */
/*<       yvecsp(i)=yc >*/
	    culcom_1.yvecsp[feq_gen_i_d_ - 1] = yc;
/*         Do diagnostic dump to check for existence. */
/*          WRITE(STDOUT,*) ' CHECKING FOR A SOLUTION' */
/*          DO 199 YT = 0.125*YC, 1.25*YC, YC/64.0 */
/*            FT = SPER(YT) */
/*            WRITE(STDOUT,64) YT, FT */
/* 199       CONTINUE */
/* SOURCE culvertc.for:1246 */
/*<       sb=(zbl-zbr)/dx >*/
	    sb = static_cast<double>((static_cast<double>(zbl) - zbr)) / sperc_1.dx;
/* SOURCE culvertc.for:1247 */
/*<       is=i-1 >*/
	    *is = feq_gen_i_d_ - 1;
/* SOURCE culvertc.for:1248 */
/*<       if(sb.le.0.0)then >*/
	    if (sb <= (float)0.) {
/*           SUBCRITICAL FLOW IS PHYSICALLY POSSIBLE */
/* SOURCE culvertc.for:1250 */
/*<       sflag=0 >*/
		*sflag = 0;
/* SOURCE culvertc.for:1251 */
/*<       else >*/
	    } else {
/* SOURCE culvertc.for:1252 */
/*<       qn=kc*sqrt(sb) >*/
		qn = kc * sqrt(sb);
/* SOURCE culvertc.for:1253 */
/*<       if(qn.lt.qr)then >*/
		if (qn < sperc_1.qr) {
/*             SUBCRITICAL FLOW IS PHYSICALLY POSSIBLE */
/* SOURCE culvertc.for:1255 */
/*<       sflag=0 >*/
		    *sflag = 0;
/* SOURCE culvertc.for:1256 */
/*<       else >*/
		} else {
/*             CHANNEL SLOPE IS  STEEP. SUBCRITICAL FLOW IS */
/*             A COMPUTATIONAL ARTIFACT. */
/* SOURCE culvertc.for:1259 */
/*<       sflag=-2 >*/
		    *sflag = -2;
/* SOURCE culvertc.for:1260 */
/*<       endif >*/
		}
/* SOURCE culvertc.for:1261 */
/*<       endif >*/
	    }
/* SOURCE culvertc.for:1262 */
/*<       return >*/
	    return 0;
/* SOURCE culvertc.for:1263 */
/*<       else >*/
	} else {
/*         SUPER CRITICAL SOLUTION EXISTS-- FIND IT. */
/*         AT YC THE RESIDUAL FUNCTION IS > 0. SEARCH FOR RESIDUAL */
/*         FUNCTION < 0 STARTING AT YL IF IT IS LESS THAN YC. */
/* SOURCE culvertc.for:1268 */
/*<       yt=yc >*/
	    yt = yc;
/* SOURCE culvertc.for:1269 */
/*<       fr=sper(yt) >*/
	    fr = sper_(&yt);
/* SOURCE culvertc.for:1270 */
/*<       if(fr.lt.0.0)then >*/
	    if (fr < (float)0.) {
/*            WRITE(STDOUT,*) ' SFPSPE: I=',I */
/*            WRITE(STDOUT,*) ' FR =',FR,' < 0.0 AT YC=',YC */
/*            WRITE(STDOUT,*) ' CHECKING FOR A SOLUTION' */
/*            DO 200 YT = 0.125*YC, 1.25*YC, YC/64.0 */
/*              FT = SPER(YT) */
/*              WRITE(STDOUT,64) YT, FT */
/* 200         CONTINUE */
/* SOURCE culvertc.for:1280 */
/*<       yvecsp(i)=yc >*/
		culcom_1.yvecsp[feq_gen_i_d_ - 1] = yc;
/*            IF(ABS(FR).LE.0.01) THEN */
/*              IS = I */
/*            ELSE */
/* SOURCE culvertc.for:1284 */
/*<       is=i-1 >*/
		*is = feq_gen_i_d_ - 1;
/*            ENDIF */
/* SOURCE culvertc.for:1286 */
/*<       sflag=0 >*/
		*sflag = 0;
/* SOURCE culvertc.for:1287 */
/*<       return >*/
		return 0;
/* SOURCE culvertc.for:1288 */
/*<       endif >*/
	    }
/* SOURCE culvertc.for:1289 */
/*<       if(yl.lt.yc)then >*/
	    if (yl < yc) {
/* SOURCE culvertc.for:1290 */
/*<       ysup=yl >*/
		ysup = yl;
/* SOURCE culvertc.for:1291 */
/*<       else >*/
	    } else {
/* SOURCE culvertc.for:1292 */
/*<       ysup=0.5*yc >*/
		ysup = static_cast<double>(yc) * (float).5;
/* SOURCE culvertc.for:1293 */
/*<       endif >*/
	    }
/* SOURCE culvertc.for:1295 */
/*<   100 continue >*/
L100:
/* SOURCE culvertc.for:1296 */
/*<       fl=sper(ysup) >*/
	    fl = sper_(&ysup);
/* SOURCE culvertc.for:1297 */
/*<       if(fl.lt.0.0)then >*/
	    if (fl < (float)0.) {
/* SOURCE culvertc.for:1298 */
/*<       goto110 >*/
		goto L110;
/* SOURCE culvertc.for:1299 */
/*<       else >*/
	    } else {
/* SOURCE culvertc.for:1300 */
/*<       fr=fl >*/
		fr = fl;
/* SOURCE culvertc.for:1301 */
/*<       yt=ysup >*/
		yt = ysup;
/* SOURCE culvertc.for:1302 */
/*<       ysup=0.5*ysup >*/
		ysup *= static_cast<double>((float).5);
/* SOURCE culvertc.for:1303 */
/*<       if(ysup.le.epsarg)then >*/
		if (ysup <= epscom_1.epsarg) {
/* SOURCE culvertc.for:1304 */
/*<       tabid=get_tabid(gettbn(adrs)) >*/
		    feq_gen_i_d_2 = gettbn_(&adrs);
		    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_2);
		    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE culvertc.for:1305 */
/*<       write(stdout,56)tabid(1:lenstr(tabid)) >*/
		    feq_gen_io_d__193.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__193);
		    do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
		    e_wsfe();
/* SOURCE culvertc.for:1306 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertc.for:1307 */
/*<       endif >*/
		}
/* SOURCE culvertc.for:1308 */
/*<       goto100 >*/
		goto L100;
/* SOURCE culvertc.for:1309 */
/*<       endif >*/
	    }
/* SOURCE culvertc.for:1310 */
/*<   110 continue >*/
L110:
/*         WE HAVE A SIGN CHANGE IN THE INTERVAL (YSUP, YC) */
/* SOURCE culvertc.for:1314 */
/*<       callregflt(epsarg,epsf,sper,ysup,yt,fl,fr,yr,flag) >*/
	    regflt_(&epscom_1.epsarg, &epscom_1.epsf, sper_, &ysup, &yt,
		     &fl, &fr, &yr, &feq_gen_flag_d_);
/* SOURCE culvertc.for:1318 */
/*<       if(flag.eq.1)then >*/
	    if (feq_gen_flag_d_ == 1) {
/* SOURCE culvertc.for:1319 */
/*<       write(stdout,58) >*/
		feq_gen_io_d__196.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__196);
		e_wsfe();
/* SOURCE culvertc.for:1320 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertc.for:1321 */
/*<       elseif(flag.eq.2)then >*/
	    } else if (feq_gen_flag_d_ == 2) {
/* SOURCE culvertc.for:1322 */
/*<       write(stdout,60) >*/
		feq_gen_io_d__197.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__197);
		e_wsfe();
/* SOURCE culvertc.for:1323 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertc.for:1324 */
/*<       endif >*/
	    }
/* SOURCE culvertc.for:1325 */
/*<       yt=min(d,yr) >*/
	    yt = dmin(sperc_1.feq_gen_d_d_,yr);
/* SOURCE culvertc.for:1326 */
/*<       callxlktal(adrs,yt,ar,tr,dtr,jr,kr,dkr,betr,dbetr,alpr,dalpr) >*/
	    xlktal_(&adrs, &yt, &ar, &tr, &dtr, &jr, &kr, &dkr, &betr, &dbetr,
		     &alpr, &dalpr);
/* SOURCE culvertc.for:1332 */
/*<       er=yr+alpr*(qr/ar)**2/grav2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(sperc_1.qr) / ar;
	    er = static_cast<double>(yr) + static_cast<double>(static_cast<double>(alpr) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / grvcom_1.grav2;
/* SOURCE culvertc.for:1333 */
/*<       el=er >*/
	    el = er;
/* SOURCE culvertc.for:1334 */
/*<       zbl=zbr >*/
	    zbl = zbr;
/* SOURCE culvertc.for:1335 */
/*<       yl=yr >*/
	    yl = yr;
/* SOURCE culvertc.for:1336 */
/*<       ql=qr >*/
	    sperc_1.ql = sperc_1.qr;
/* SOURCE culvertc.for:1337 */
/*<       al=ar >*/
	    sperc_1.al = ar;
/* SOURCE culvertc.for:1338 */
/*<       alpl=alpr >*/
	    sperc_1.alpl = alpr;
/* SOURCE culvertc.for:1339 */
/*<       adrold=adr >*/
	    adrold = sperc_1.adr;
/* SOURCE culvertc.for:1340 */
/*<       kl=kr >*/
	    sperc_1.kl = kr;
/* SOURCE culvertc.for:1341 */
/*<       yvecsp(i)=yr >*/
	    culcom_1.yvecsp[feq_gen_i_d_ - 1] = yr;
/* SOURCE culvertc.for:1342 */
/*<       endif >*/
	}
/* SOURCE culvertc.for:1343 */
/*<   500 continue >*/
/* L500: */
    }
/* SOURCE culvertc.for:1345 */
/*<       zdn=yr+zbr >*/
    *zdn = static_cast<double>(yr) + zbr;
/* SOURCE culvertc.for:1346 */
/*<       is=id >*/
    *is = *id;
/* SOURCE culvertc.for:1347 */
/*<       sflag=1 >*/
    *sflag = 1;
/* SOURCE culvertc.for:1348 */
/*<       return >*/
    return 0;
/* SOURCE culvertc.for:1349 */
/*<       end >*/
} /* sfpspe_ */




/* SOURCE culvertc.for:1353 */
/*<       subroutinesfpty1(stdout,iu,id,dh,q,zup,is,zdn,sflag) >*/
/* Subroutine */ int sfpty1_(integer *stdout, integer *iu, integer *id, real *
	dh, real *q, real *zup, integer *is, real *zdn, integer *sflag)
{
    /* Format strings */
    static char fmt_50[] = "(\002 *BUG:XXX* INITIAL DEPTH=\002,f10.2,\002 <=\
 0 IN SFPTY1.\002)";
    static char fmt_56[] = "(\002 *BUG:XXX* TABID=\002,a,\002 OVERFLOW SEEKI\
NG \002,\002 SUBCRITICAL SOLUTION.\002)";
    static char fmt_58[] = "(\002 *BUG:XXX* SIGN CHNG ON ENTRY BUT REGFLT CL\
AIMS NONE IN\002,\002 SFPTY1.\002)";
    static char fmt_60[] = "(\002 *BUG:XXX* REGFLT TAKES MORE THAN 100 ITERA\
TIONS:SFPTY1\002)";

    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3;
    char feq_gen_ch_d_1[16];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real ac, ec, el, ar, fl, jc, jl, er, fr, kc, jr, kr, tc, tl, yc, tr, yl, 
	    yr, yt, dkc, dkl, dtc, qcl, dkr, dtl, sfm, zbl, dtr, zbr;
    integer feq_gen_flag_d_;
    real betc, alpc, betl;
    integer adrs;
    real alpr, betr;
    extern doublereal sper_(real *);
    real ymax, ysub, dbetc, dalpc;
    char tabid[16];
    real dbetl, dalpl, dbetr, dalpr;
    extern /* Subroutine */ int xlkt22_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *), fndcde_(integer *, integer *, real *, real *);
    integer adrold;
    extern integer gettbn_(integer *);
    extern doublereal fmxarg_(integer *);
    extern /* Subroutine */ int regflt_(real *, real *, FeqCallback3, real *, real *, 
	    real *, real *, real *, integer *);
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int xlktal_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__212 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__244 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__247 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__248 = { 0, 0, 0, fmt_60, 0 };


/*     + + + PURPOSE + + + */
/*     Compute a steady flow profile in a culvert with type 1 flow */
/*     starting at the critical depth at the entrance and */
/*     computing subcritical flow to the exit of the culvert. */
/*     Used to define the limit of type 1 flow. */
/*     DH gives estimated head loss  that occurs in the */
/*     submerging flow. */
/* SOURCE culvertc.for:1365 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE culvertc.for:1367 */
/*<       integerid,is,iu,sflag,stdout >*/
/* SOURCE culvertc.for:1368 */
/*<       realdh,q,zdn,zup >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     IU     - Index for upstream node for the culvert barrel */
/*     ID     - Index for the downstream node for the culvert barrel */
/*     DH     - Entrance loss for the culvert */
/*     Q      - Flowrate */
/*     ZUP    - Water surface elevation at section 2 */
/*     IS     - Index of node for the last value computed */
/*     ZDN    - Water surface elevation at downstream end of barrel */
/*     SFLAG  - Flag describing results: */
/*                0-results incomplete.  Super critical flow encountered */
/*                  and flow is thought to be caused by a steep slope. */
/*                1-results complete */
/*               -1-results incomplete.  Super critical flow encountered */
/*                  and DX may be too large. */
/*               -2-results incomplete.  Super critical flow encountered */
/*                  and DX is too large. */
/*               -3-no solution found at the last point. */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE culvertc.for:1390 */
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
/* INCLUDE culvertc.for:1391 */
/* SOURCE grvcom.cmn:2 */
/*<       common/grvcom/grav,grav2,bcwmax,sqrt_grav >*/
/* SOURCE grvcom.cmn:4 */
/*<       realgrav,grav2,bcwmax,sqrt_grav >*/
/* INCLUDE culvertc.for:1392 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE culvertc.for:1393 */
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
/* INCLUDE culvertc.for:1394 */
/*     Common for function SPER in FEQUTL */
/* SOURCE sperc.cmn:3 */
/*<       common/sperc/rhs,adr,qr,ql,kl,dx,al,alpl,kacc,kdec,d,se >*/
/* SOURCE sperc.cmn:5 */
/*<       integeradr >*/
/* SOURCE sperc.cmn:6 */
/*<       realrhs,qr,ql,kl,dx,al,alpl,kacc,kdec,d,se >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE culvertc.for:1397 */
/*<       integeradrold,adrs,flag,i >*/
/* SOURCE culvertc.for:1398 */
/*<        >*/
/* SOURCE culvertc.for:1402 */
/*<       charactertabid*16 >*/
/*     + + + INTRINSICS + + + */
/* SOURCE culvertc.for:1405 */
/*<       intrinsicabs,dble,max,min >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE culvertc.for:1408 */
/*<       integergettbn,lenstr >*/
/* SOURCE culvertc.for:1409 */
/*<       realfmxarg,sper >*/
/* SOURCE culvertc.for:1410 */
/*<       characterget_tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE culvertc.for:1413 */
/*<       externalfmxarg,fndcde,gettbn,regflt,sper,xlkt22,xlktal >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE culvertc.for:1416 */
/*<    50 format(' *BUG:XXX* INITIAL DEPTH=',f10.2,' <= 0 IN SFPTY1.') >*/
/* SOURCE culvertc.for:1417 */
/*<    56  >*/
/* SOURCE culvertc.for:1419 */
/*<    58  >*/
/* SOURCE culvertc.for:1421 */
/*<    60 format(' *BUG:XXX* REGFLT TAKES MORE THAN 100 ITERATIONS:SFPTY1') >*/
/* *********************************************************************** */
/* SOURCE culvertc.for:1423 */
/*<       sflag=1 >*/
/* L50: */
/* L56: */
/* L58: */
/* L60: */
    *sflag = 1;
/* SOURCE culvertc.for:1424 */
/*<       se=dh/abs(xvec(iu)-xvec(id)) >*/
    sperc_1.se = *dh / (feq_gen_r_d_1 = static_cast<double>(culcom_1.xvec[*iu - 1]) - culcom_1.xvec[*id - 1]
	    , dabs(feq_gen_r_d_1));
/*      WRITE(STDOUT,*) ' SFPTY1: SE=',SE */
/* SOURCE culvertc.for:1427 */
/*<       qr=q >*/
    sperc_1.qr = *q;
/* SOURCE culvertc.for:1428 */
/*<       ql=q >*/
    sperc_1.ql = *q;
/* SOURCE culvertc.for:1429 */
/*<       adrold=-1 >*/
    adrold = -1;
/* SOURCE culvertc.for:1430 */
/*<       zbl=zbvec(iu) >*/
    zbl = culcom_1.zbvec[*iu - 1];
/* SOURCE culvertc.for:1431 */
/*<       yl=dble(zup)-dble(zbl) >*/
    yl = (doublereal) (*zup) - (doublereal) zbl;
/* SOURCE culvertc.for:1432 */
/*<       if(yl.le.0.0)then >*/
    if (yl <= (float)0.) {
/* SOURCE culvertc.for:1433 */
/*<       write(stdout,50)yl >*/
	feq_gen_io_d__212.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__212);
	do_fio(&feq_gen_c_d_1, (char *)&yl, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE culvertc.for:1434 */
/*<       stop'Abnormal stop. Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertc.for:1435 */
/*<       endif >*/
    }
/* SOURCE culvertc.for:1437 */
/*<       adrs=nsec(iu) >*/
    adrs = culcom_1.nsec[*iu - 1];
/* SOURCE culvertc.for:1438 */
/*<       callxlkt22(adrs,yl,al,tl,dtl,jl,kl,dkl,betl,dbetl,alpl,dalpl,qcl) >*/
    xlkt22_(&adrs, &yl, &sperc_1.al, &tl, &dtl, &jl, &sperc_1.kl, &dkl, &betl,
	     &dbetl, &sperc_1.alpl, &dalpl, &qcl);
/*     COMPUTE SQUARE OF THE FROUDE NUMBER */
/* SOURCE culvertc.for:1446 */
/*<       fr=(ql/qcl)**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(sperc_1.ql) / qcl;
    fr = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/*      IF(FR.LT.0.990) THEN */
/*        WRITE(STDOUT, 54)  FR */
/*        STOP 'Abnormal stop. Errors found.' */
/*      ENDIF */
/*     AT THIS POINT THE INITIAL CONDITION IS VALID. START THE LOOP */
/* SOURCE culvertc.for:1454 */
/*<       el=yl+alpl*(ql/al)**2/grav2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(sperc_1.ql) / sperc_1.al;
    el = static_cast<double>(yl) + static_cast<double>(static_cast<double>(sperc_1.alpl) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / grvcom_1.grav2;
/* SOURCE culvertc.for:1455 */
/*<       yvecsp(iu)=yl >*/
    culcom_1.yvecsp[*iu - 1] = yl;
/*      EVEC(IU) = EL */
/*      SFVEC(IU) = (QL/KL)**2 */
/*     MAKE FIRST ESTIMATE OF YC */
/* SOURCE culvertc.for:1459 */
/*<       yc=yl >*/
    yc = yl;
/* SOURCE culvertc.for:1460 */
/*<       do500i=iu+1,id >*/
    feq_gen_i_d_1 = *id;
    for (feq_gen_i_d_ = *iu + 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE culvertc.for:1461 */
/*<       d=dvec(i) >*/
	sperc_1.feq_gen_d_d_ = culcom_1.dvec[feq_gen_i_d_ - 1];
/* SOURCE culvertc.for:1462 */
/*<       is=i >*/
	*is = feq_gen_i_d_;
/* SOURCE culvertc.for:1463 */
/*<       dx=abs(xvec(i-1)-xvec(i)) >*/
	sperc_1.dx = (feq_gen_r_d_1 = static_cast<double>(culcom_1.xvec[feq_gen_i_d_ - 2]) - culcom_1.xvec[feq_gen_i_d_ - 1], 
		dabs(feq_gen_r_d_1));
/* SOURCE culvertc.for:1464 */
/*<       zbr=zbvec(i) >*/
	zbr = culcom_1.zbvec[feq_gen_i_d_ - 1];
/* SOURCE culvertc.for:1465 */
/*<       kacc=ka(i) >*/
	sperc_1.kacc = culcom_1.ka[feq_gen_i_d_ - 1];
/* SOURCE culvertc.for:1466 */
/*<       kdec=kd(i) >*/
	sperc_1.kdec = culcom_1.kd[feq_gen_i_d_ - 1];
/*       FIND CRITICAL DEPTH AT THE CURRENT LOCATION. USE LAST */
/*       AVAILABLE DEPTH AS THE FIRST ESTIMATE. */
/* SOURCE culvertc.for:1471 */
/*<       adrs=nsec(i) >*/
	adrs = culcom_1.nsec[feq_gen_i_d_ - 1];
/* SOURCE culvertc.for:1472 */
/*<       adr=adrs >*/
	sperc_1.adr = adrs;
/* SOURCE culvertc.for:1473 */
/*<       if(adr.ne.adrold.or.ql.ne.qr)then >*/
	if (sperc_1.adr != adrold || sperc_1.ql != sperc_1.qr) {
/* SOURCE culvertc.for:1474 */
/*<       callfndcde(stdout,adrs,qr,yc) >*/
	    fndcde_(stdout, &adrs, &sperc_1.qr, &yc);
/*         COMPUTE SPECIFIC ENERGY AT CRITICAL DEPTH */
/* SOURCE culvertc.for:1480 */
/*<       callxlktal(adrs,yc,ac,tc,dtc,jc,kc,dkc,betc,dbetc,alpc,dalpc) >*/
	    xlktal_(&adrs, &yc, &ac, &tc, &dtc, &jc, &kc, &dkc, &betc, &dbetc,
		     &alpc, &dalpc);
/* SOURCE culvertc.for:1486 */
/*<       ec=yc+alpc*(qr/ac)**2/grav2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(sperc_1.qr) / ac;
	    ec = static_cast<double>(yc) + static_cast<double>(static_cast<double>(alpc) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / grvcom_1.grav2;
/* SOURCE culvertc.for:1488 */
/*<       endif >*/
	}
/*       COMPUTE THE AVERAGE FRICTION SLOPE FOR THE ELEMENT */
/*       ASSUMING CRITICAL FLOW AT THE CURRENT NODE */
/* SOURCE culvertc.for:1492 */
/*<       sfm=ql*qr/(kc*kl) >*/
	sfm = static_cast<double>(static_cast<double>(sperc_1.ql) * sperc_1.qr) / (static_cast<double>(kc) * sperc_1.kl);
/*       COMPUTE THE CONSTANT PART OF THE EQUATION */
/* SOURCE culvertc.for:1496 */
/*<       rhs=el+zbl-zbr-dx*se >*/
	sperc_1.rhs = static_cast<double>(static_cast<double>(static_cast<double>(el) + zbl) - zbr) - static_cast<double>(sperc_1.dx) * sperc_1.se;
/*       FORCE A UNIQUE SUBCRITICAL SOLUTION.  DX MAY HAVE TO BE */
/*       REDUCED TO OBTAIN IT. */
/*        WRITE(STDOUT,*) 'SFPTY1: RHS=',RHS,' EC=',EC,' SFM=',SFM */
/*        WRITE(STDOUT,*) ' DIFF=',EC + DX*SFM - RHS */
/*        WRITE(STDOUT,*) ' EL=',EL,' ZBL-ZBR=',ZBL-ZBR */
/*        WRITE(STDOUT,*) ' YC=',YC,' YL=',YL */
/* SOURCE culvertc.for:1504 */
/*<       if(abs((ec+dx*sfm-rhs)/max(1.0,abs(rhs))).le.epsf)then >*/
/* Computing MAX */
	feq_gen_r_d_2 = (float)1., feq_gen_r_d_3 = dabs(sperc_1.rhs);
	if ((feq_gen_r_d_1 = (static_cast<double>(static_cast<double>(ec) + static_cast<double>(sperc_1.dx) * sfm) - sperc_1.rhs) / dmax(feq_gen_r_d_2,feq_gen_r_d_3), 
		dabs(feq_gen_r_d_1)) <= epscom_1.epsf) {
/*         Take the solution to be critical depth. */
/* SOURCE culvertc.for:1506 */
/*<       yr=yc >*/
	    yr = yc;
/* SOURCE culvertc.for:1507 */
/*<       elseif(ec+dx*sfm.gt.rhs)then >*/
	} else if (static_cast<double>(ec) + static_cast<double>(sperc_1.dx) * sfm > sperc_1.rhs) {
/*         NO UNIQUE SUBCRITICAL SOLUTION EXISTS OR NO SUBCRITICAL */
/*         SOLUTION EXISTS. */
/*          WRITE(STDOUT,*) ' SFPTY1: EC + DX*SFM=',EC + DX*SFM, */
/*     A                ' RHS=',RHS,' AT I=',I */
/*          WRITE(STDOUT,*) ' SFPTY1: NO SOLUTION.' */
/* SOURCE culvertc.for:1514 */
/*<       sflag=0 >*/
	    *sflag = 0;
/* SOURCE culvertc.for:1515 */
/*<       is=i-1 >*/
	    *is = feq_gen_i_d_ - 1;
/* SOURCE culvertc.for:1516 */
/*<       return >*/
	    return 0;
/* SOURCE culvertc.for:1517 */
/*<       else >*/
	} else {
/*         UNIQUE SUBCRITICAL SOLUTION EXISTS-- FIND IT. */
/*         AT YC THE RESIDUAL FUNCTION IS > 0. SEARCH FOR RESIDUAL */
/*         FUNCTION < 0 STARTING AT YL IF IT IS GREATER THAN YC. */
/* SOURCE culvertc.for:1522 */
/*<       fr=sper(yc) >*/
	    fr = sper_(&yc);
/* SOURCE culvertc.for:1523 */
/*<       if(fr.lt.0.0)then >*/
	    if (fr < (float)0.) {
/*           Treat as no solution. */
/* SOURCE culvertc.for:1525 */
/*<       sflag=0 >*/
		*sflag = 0;
/* SOURCE culvertc.for:1526 */
/*<       is=i-1 >*/
		*is = feq_gen_i_d_ - 1;
/* SOURCE culvertc.for:1527 */
/*<       return >*/
		return 0;
/* SOURCE culvertc.for:1528 */
/*<       endif >*/
	    }
/* SOURCE culvertc.for:1529 */
/*<       if(yl.gt.yc)then >*/
	    if (yl > yc) {
/* SOURCE culvertc.for:1530 */
/*<       ysub=yl >*/
		ysub = yl;
/* SOURCE culvertc.for:1531 */
/*<       else >*/
	    } else {
/* SOURCE culvertc.for:1532 */
/*<       ysub=yc >*/
		ysub = yc;
/* SOURCE culvertc.for:1533 */
/*<       endif >*/
	    }
/* SOURCE culvertc.for:1534 */
/*<       ymax=fmxarg(adrs) >*/
	    ymax = fmxarg_(&adrs);
/* SOURCE culvertc.for:1535 */
/*<   100 continue >*/
L100:
/* SOURCE culvertc.for:1536 */
/*<       fl=sper(ysub) >*/
	    fl = sper_(&ysub);
/* SOURCE culvertc.for:1537 */
/*<       if(fl.gt.0.0)then >*/
	    if (fl > (float)0.) {
/* SOURCE culvertc.for:1538 */
/*<       ysub=0.9*ysub+0.1*ymax >*/
		ysub = static_cast<double>(static_cast<double>(ysub) * (float).9) + static_cast<double>(ymax) * (float).1;
/* SOURCE culvertc.for:1539 */
/*<       if(abs(ysub-ymax).le.epsarg)then >*/
		if ((feq_gen_r_d_1 = static_cast<double>(ysub) - ymax, dabs(feq_gen_r_d_1)) <= epscom_1.epsarg) {
/* SOURCE culvertc.for:1540 */
/*<       tabid=get_tabid(gettbn(adrs)) >*/
		    feq_gen_i_d_2 = gettbn_(&adrs);
		    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &feq_gen_i_d_2);
		    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE culvertc.for:1541 */
/*<       write(stdout,56)tabid(1:lenstr(tabid)) >*/
		    feq_gen_io_d__244.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__244);
		    do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
		    e_wsfe();
/* SOURCE culvertc.for:1542 */
/*<       stop'Abnormal stop. Errors found.' >*/
		    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertc.for:1543 */
/*<       endif >*/
		}
/* SOURCE culvertc.for:1544 */
/*<       goto100 >*/
		goto L100;
/* SOURCE culvertc.for:1545 */
/*<       endif >*/
	    }
/*         WE HAVE A SIGN CHANGE IN THE INTERVAL (YSUB, YC) */
/* SOURCE culvertc.for:1549 */
/*<       yt=yc >*/
	    yt = yc;
/* SOURCE culvertc.for:1550 */
/*<       callregflt(0.0,5.e-6,sper,ysub,yt,fl,fr,yr,flag) >*/
	    regflt_(&c_b50, &c_b51, sper_, &ysub, &yt, &fl, &fr, &yr, &
		    feq_gen_flag_d_);
/* SOURCE culvertc.for:1554 */
/*<       if(flag.eq.1)then >*/
	    if (feq_gen_flag_d_ == 1) {
/* SOURCE culvertc.for:1555 */
/*<       write(stdout,58) >*/
		feq_gen_io_d__247.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__247);
		e_wsfe();
/* SOURCE culvertc.for:1556 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertc.for:1557 */
/*<       elseif(flag.eq.2)then >*/
	    } else if (feq_gen_flag_d_ == 2) {
/* SOURCE culvertc.for:1558 */
/*<       write(stdout,60) >*/
		feq_gen_io_d__248.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__248);
		e_wsfe();
/* SOURCE culvertc.for:1559 */
/*<       stop'Abnormal stop. Errors found.' >*/
		s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE culvertc.for:1560 */
/*<       endif >*/
	    }
/* SOURCE culvertc.for:1561 */
/*<       endif >*/
	}
/* SOURCE culvertc.for:1562 */
/*<       yt=min(yr,d) >*/
	yt = dmin(yr,sperc_1.feq_gen_d_d_);
/* SOURCE culvertc.for:1563 */
/*<       callxlktal(adrs,yt,ar,tr,dtr,jr,kr,dkr,betr,dbetr,alpr,dalpr) >*/
	xlktal_(&adrs, &yt, &ar, &tr, &dtr, &jr, &kr, &dkr, &betr, &dbetr, &
		alpr, &dalpr);
/* SOURCE culvertc.for:1568 */
/*<       er=yr+alpr*(qr/ar)**2/grav2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = static_cast<double>(sperc_1.qr) / ar;
	er = static_cast<double>(yr) + static_cast<double>(static_cast<double>(alpr) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / grvcom_1.grav2;
/* SOURCE culvertc.for:1569 */
/*<       el=er >*/
	el = er;
/* SOURCE culvertc.for:1570 */
/*<       zbl=zbr >*/
	zbl = zbr;
/* SOURCE culvertc.for:1571 */
/*<       yl=yr >*/
	yl = yr;
/* SOURCE culvertc.for:1572 */
/*<       ql=qr >*/
	sperc_1.ql = sperc_1.qr;
/* SOURCE culvertc.for:1573 */
/*<       al=ar >*/
	sperc_1.al = ar;
/* SOURCE culvertc.for:1574 */
/*<       alpl=alpr >*/
	sperc_1.alpl = alpr;
/* SOURCE culvertc.for:1575 */
/*<       adrold=adr >*/
	adrold = sperc_1.adr;
/* SOURCE culvertc.for:1576 */
/*<       kl=kr >*/
	sperc_1.kl = kr;
/* SOURCE culvertc.for:1577 */
/*<       yvecsp(i)=yr >*/
	culcom_1.yvecsp[feq_gen_i_d_ - 1] = yr;
/*        EVEC(I) = ER */
/*        YCVEC(I) = YC */
/*        YNVEC(I) = 0.0 */
/*        SFVEC(I) = (QR/KR)**2 */
/* SOURCE culvertc.for:1582 */
/*<   500 continue >*/
/* L500: */
    }
/*      YCVEC(IU) = YCVEC(IU+1) */
/*      YNVEC(IU) = YNVEC(IU+1) */
/*      WRITE(STDOUT,*) ' SE=',SE,' Q=',Q */
/*      WRITE(STDOUT,61) */
/*      SUM = 0.0 */
/*      DO 700 I=IU,IS */
/*        WRITE(STDOUT,62) I, XVEC(I), YVECSP(I), YCVEC(I), YNVEC(I), */
/*     A      ZBVEC(I), YVECSP(I) + ZBVEC(I), DVEC(I), SFVEC(I), */
/*     B      EVEC(I) + ZBVEC(I) */
/*        SUM = SUM + SFVEC(I) */
/* 700   CONTINUE */
/*      SUM = SUM - .5*(SFVEC(IU) + SFVEC(ID)) - */
/*     A      (SFVEC(ID) - SFVEC(ID-1) - SFVEC(2) + SFVEC(1))/12.0 */
/*      DE = SUM*ABS(XVEC(ID) - XVEC(IU))/FLOAT(ID - IU) + DH */
/*      WRITE(STDOUT,*) ' DE BY INTEGRATION=',DE, ' DE BY SUBTRACTION=', */
/*     A       EVEC(IU) + ZBVEC(IU) - EVEC(ID) - ZBVEC(ID) */
/* SOURCE culvertc.for:1602 */
/*<       zdn=yr+zbr >*/
    *zdn = static_cast<double>(yr) + zbr;
/* SOURCE culvertc.for:1603 */
/*<       is=id >*/
    *is = *id;
/* SOURCE culvertc.for:1604 */
/*<       sflag=1 >*/
    *sflag = 1;
/* SOURCE culvertc.for:1605 */
/*<       return >*/
    return 0;
/* SOURCE culvertc.for:1606 */
/*<       end >*/
} /* sfpty1_ */

#ifdef __cplusplus
	}
#endif
