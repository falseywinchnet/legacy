/* exnmat.f -- translated by f2c (version 20240504).
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

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* COMMON gate1_ is declared in common.hpp. */

#define gate1_1 gate1_

/* COMMON gate2_ is declared in common.hpp. */

#define gate2_1 gate2_

/* COMMON cb_ is declared in common.hpp. */

#define cb_1 cb_

/* COMMON gravcm_ is declared in common.hpp. */

#define gravcm_1 gravcm_

/* COMMON ftable_ is declared in common.hpp. */

#define ftable_1 ftable_

/* COMMON ftablea_ is declared in common.hpp. */

#define ftablea_1 ftablea_

/* COMMON ftablec_ is declared in common.hpp. */

#define ftablec_1 ftablec_

/* COMMON enelem_ is declared in common.hpp. */

#define enelem_1 enelem_

/* COMMON mhenry_ is declared in common.hpp. */

#define mhenry_1 mhenry_

/* COMMON bnelem_ is declared in common.hpp. */

#define bnelem_1 bnelem_

/* COMMON rdcom_ is declared in common.hpp. */

#define rdcom_1 rdcom_

/* COMMON rdcomc_ is declared in common.hpp. */

#define rdcomc_1 rdcomc_

/* COMMON miscon_ is declared in common.hpp. */

#define miscon_1 miscon_

/* COMMON bnothr_ is declared in common.hpp. */

#define bnothr_1 bnothr_

/* COMMON bnothc_ is declared in common.hpp. */

#define bnothc_1 bnothc_

/* COMMON matcom_ is declared in common.hpp. */

#define matcom_1 matcom_

/* COMMON matcom2_ is declared in common.hpp. */

#define matcom2_1 matcom2_

/* COMMON xscom_ is declared in common.hpp. */

#define xscom_1 xscom_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_0 = 0;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_3 = 3;
static doublereal c_b170 = .91363;
static doublereal c_b171 = -.40437;
static doublereal c_b177 = .59563;
static doublereal c_b179 = .3;
static doublereal c_b180 = .7;
static doublereal c_b182 = 1.50942;
static doublereal c_b183 = .50942;
static integer feq_gen_c_d_10 = 10;
static real c_b215 = (float)1.;
static integer c_b303 = 120000;
static doublereal c_b337 = 1.5;
static integer feq_gen_c_d_14 = 14;
static integer feq_gen_c_d_43 = 43;
static integer feq_gen_c_d_13 = 13;
static integer feq_gen_c_d_6 = 6;

/* Routines used in creating network matrix entries for internal */
/* and external boundary conditions, that is those involving */
/* exterior nodes. */



/* SOURCE exnmat.for:7 */
/*<        >*/
/* Subroutine */ int abrexp_(integer *ipnt, real *grav, integer *stdout, 
	doublereal *jtime, integer *nex, integer *mremc, integer *feq_storage_exnodt, 
	real *feq_storage_qe2, real *feq_storage_ye2, real *feq_storage_ze, integer *feq_storage_emc, real *res, real *pyl, 
	real *pql, real *pyr, real *pqr)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *WRN:05* ABRUPT EXPANSION CANNOT ALLOW R\
EVERSE\002,\002 FLOW AT JTIME=\002,f14.2,/,4x,\002WITH FLOW=\002,1pe12.4,\
\002 UPS NODE=\002,a5,\002 AND DNS NODE=\002,a5)";
    static char fmt_52[] = "(/,\002 *WRN:06* INVALID CRITICAL DEPTH FACTOR A\
T UPS\002,\002 NODE=\002,a5,\002 IN ABRUPT EXPANSION.\002,/,4x,\002DEPTH=\
\002,f10.1)";
    static char fmt_54[] = "(/,\002 *WRN:07* INVALID CRITICAL DEPTH FACTOR A\
T DNS\002,\002 NODE=\002,a5,\002 IN ABRUPT EXPANSION.\002,/,4x,\002DEPTH=\
\002,f10.1)";

    /* System generated locals */
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5], feq_gen_ch_d_3[5], feq_gen_ch_d_4[5];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer e_wsfe();

    /* Local variables */
    real y, al, bl, ar, br, qc, jl, jr, ql, tl, vl, qr, yl, tr, zl, vr, yr, 
	    zr, fac, dbl;
    integer adr;
    real dbr, arl;
    integer dnn;
    real con, dtl, jrl, dtr;
    integer qnn;
    real pdv;
    integer unn;
    real dcon;
    integer ntab, fsgn, cftab;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    integer state;
    extern /* Subroutine */ int xlkt21_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *);
    integer sysgn;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__14 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__39 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__40 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__41 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__42 = { 0, 0, 0, fmt_54, 0 };


/*     + + + PURPOSE + + + */
/*     Compute flow through an abrupt expansion.  The expansion can be */
/*     caused by an increase in cross section size or a drop in the */
/*     bottom elevation. */
/*     Assumptions: */
/*     1. No reverse flow at the upstream node.  Routine will force */
/*        this requirement. */
/*     2. Nodes must be on branches in natural sense.  Error message */
/*        will be issued if not true. */
/*     3. Friction and gravity forces ignored in the control volume for */
/*        the momentum balance. */
/*     4. Flow node must be at the upstream node.  Used to detect */
/*        reverse flow--will be relaxed later as required. */
/* SOURCE exnmat.for:28 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:30 */
/*<       integeripnt,stdout,mremc,nex >*/
/* SOURCE exnmat.for:31 */
/*<       integeremc(mremc),exnodt(9,nex) >*/
/* SOURCE exnmat.for:32 */
/*<       realgrav,pql,pqr,pyl,pyr,qe2(nex),res,ye2(nex),ze(nex) >*/
/* SOURCE exnmat.for:34 */
/*<       real*8jtime >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IPNT   - pointer into EMC for description of control structure */
/*     GRAV   - value of acceleration due to gravity */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     TIME   - elapsed time in seconds from start of run */
/*     NEX    - number of exterior nodes in the model */
/*     MREMC  - maximum length of EMC(*). Same as LEMC */
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
/*     QE2    - flow at exterior nodes at end of time step */
/*     YE2    - depths at exterior nodes at end of time step */
/*     ZE     - elevation of datum for depth at exterior node */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     RES    - value of the residual function */
/*     PYL    - partial derivative of residual function wrt depth at */
/*               left node */
/*     PQL    - partial derivative of residual function wrt flow at left */
/*               node */
/*     PYR    - partial derivative of residual function wrt depth at */
/*               right node */
/*     PQR    - partial derivative of residual function wrt flow at right */
/*               node */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE exnmat.for:72 */
/*<       integeradr,cftab,dnn,fsgn,ntab,qnn,state,sysgn,unn >*/
/* SOURCE exnmat.for:73 */
/*<        >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE exnmat.for:77 */
/*<       charactergetusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE exnmat.for:80 */
/*<       externalgetusn,lktab,xlkt21 >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE exnmat.for:83 */
/*<    50  >*/
/* SOURCE exnmat.for:86 */
/*<    52  >*/
/* SOURCE exnmat.for:88 */
/*<    54  >*/
/* *********************************************************************** */
/*     GET KEY VALUES */
/* SOURCE exnmat.for:93 */
/*<       unn=emc(ipnt+2) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> ze(feq_storage_ze, 1);

    feq::IndexedPointer<real> ye2(feq_storage_ye2, 1);

    feq::IndexedPointer<real> qe2(feq_storage_qe2, 1);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* L50: */
/* L52: */
/* L54: */
    unn = emc[*ipnt + 2];
/* SOURCE exnmat.for:94 */
/*<       dnn=emc(ipnt+3) >*/
    dnn = emc[*ipnt + 3];
/* SOURCE exnmat.for:95 */
/*<       qnn=emc(ipnt+4) >*/
    qnn = emc[*ipnt + 4];
/* SOURCE exnmat.for:96 */
/*<       sysgn=emc(ipnt+5) >*/
    sysgn = emc[*ipnt + 5];
/* SOURCE exnmat.for:97 */
/*<       state=emc(ipnt+6) >*/
    state = emc[*ipnt + 6];
/* SOURCE exnmat.for:98 */
/*<       cftab=emc(ipnt+8) >*/
    cftab = emc[*ipnt + 8];
/* SOURCE exnmat.for:100 */
/*<       yl=ye2(unn) >*/
    yl = ye2[unn];
/* SOURCE exnmat.for:101 */
/*<       yr=ye2(dnn) >*/
    yr = ye2[dnn];
/* SOURCE exnmat.for:102 */
/*<       ql=qe2(unn) >*/
    ql = qe2[unn];
/* SOURCE exnmat.for:103 */
/*<       qr=qe2(dnn) >*/
    qr = qe2[dnn];
/* SOURCE exnmat.for:104 */
/*<       zl=ze(unn) >*/
    zl = ze[unn];
/* SOURCE exnmat.for:105 */
/*<       zr=ze(dnn) >*/
    zr = ze[dnn];
/* SOURCE exnmat.for:106 */
/*<       if(qe2(qnn).lt.0.0)then >*/
    if (qe2[qnn] < (float)0.) {
/* SOURCE exnmat.for:107 */
/*<       fsgn=-sysgn >*/
	fsgn = -sysgn;
/* SOURCE exnmat.for:108 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:109 */
/*<       fsgn=sysgn >*/
	fsgn = sysgn;
/* SOURCE exnmat.for:110 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:112 */
/*<       if(fsgn.lt.0)then >*/
    if (fsgn < 0) {
/*       REVERSE FLOW NOT PERMITTED */
/* SOURCE exnmat.for:115 */
/*<       write(stdout,50)jtime,qe2(qnn),getusn(unn),getusn(dnn) >*/
	feq_gen_io_d__14.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__14);
	do_fio(&feq_gen_c_d_1, (char *)&(*jtime), (ftnlen)sizeof(doublereal));
	do_fio(&feq_gen_c_d_1, (char *)&qe2[qnn], (ftnlen)sizeof(real));
	getusn_(feq_gen_ch_d_2, (ftnlen)5, &unn);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	getusn_(feq_gen_ch_d_4, (ftnlen)5, &dnn);
	s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)5);
	e_wsfe();
/*       REPRESENT AS A CLOSED BOUNDARY */
/* SOURCE exnmat.for:119 */
/*<       if(qnn.eq.unn)then >*/
	if (qnn == unn) {
/* SOURCE exnmat.for:120 */
/*<       pyl=0.0 >*/
	    *pyl = (float)0.;
/* SOURCE exnmat.for:121 */
/*<       pql=1.0 >*/
	    *pql = (float)1.;
/* SOURCE exnmat.for:122 */
/*<       pyr=0.0 >*/
	    *pyr = (float)0.;
/* SOURCE exnmat.for:123 */
/*<       pqr=0.0 >*/
	    *pqr = (float)0.;
/* SOURCE exnmat.for:124 */
/*<       res=ql >*/
	    *res = ql;
/* SOURCE exnmat.for:125 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:126 */
/*<       pyl=0.0 >*/
	    *pyl = (float)0.;
/* SOURCE exnmat.for:127 */
/*<       pql=0.0 >*/
	    *pql = (float)0.;
/* SOURCE exnmat.for:128 */
/*<       pyr=0.0 >*/
	    *pyr = (float)0.;
/* SOURCE exnmat.for:129 */
/*<       pqr=1.0 >*/
	    *pqr = (float)1.;
/* SOURCE exnmat.for:130 */
/*<       res=qr >*/
	    *res = qr;
/* SOURCE exnmat.for:131 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:133 */
/*<       else >*/
    } else {
/*       FLOW IS FROM THE UPSTREAM NODE TO THE DOWNSTREAM NODE */
/*       BASE ACTION ON THE CURRENT FLOW STATE. CHANGE STATE AS NEEDED */
/* SOURCE exnmat.for:138 */
/*<       if(state.gt.0)then >*/
	if (state > 0) {
/*         CRITICAL FLOW AT THE UPSTREAM NODE */
/*         CHECK TO SEE IF STATE SHOULD BE CHANGED TO SUBCRITICAL. */
/*         DONE IN TWO STAGES.  THE FIRST STAGE IS FAST BUT DOES NOT */
/*         COVER THE WHOLE RANGE. */
/* SOURCE exnmat.for:144 */
/*<       if(yl+zl.ge.yr+zr)then >*/
	    if (static_cast<double>(yl) + zl >= static_cast<double>(yr) + zr) {
/*           REMAIN CRITICAL. ELEVATION AT CRITICAL DEPTH > DNS ELEV */
/*           GET CRITICAL FLOW FROM THE TABLE */
/* SOURCE exnmat.for:149 */
/*<       calllktab(cftab,yl,1,qc,ntab,pdv) >*/
		lktab_(&cftab, &yl, &feq_gen_c_d_1, &qc, &ntab, &pdv);
/* SOURCE exnmat.for:153 */
/*<       res=ql-qc >*/
		*res = static_cast<double>(ql) - qc;
/* SOURCE exnmat.for:154 */
/*<       pyl=-pdv >*/
		*pyl = -pdv;
/* SOURCE exnmat.for:155 */
/*<       pql=1.0 >*/
		*pql = (float)1.;
/* SOURCE exnmat.for:156 */
/*<       pyr=0.0 >*/
		*pyr = (float)0.;
/* SOURCE exnmat.for:157 */
/*<       pqr=0.0 >*/
		*pqr = (float)0.;
/* SOURCE exnmat.for:158 */
/*<       return >*/
		return 0;
/* SOURCE exnmat.for:159 */
/*<       else >*/
	    } else {
/*           STATE MAY SWITCH. COMPUTE THE SUBCRITICAL STATE COMPONENTS */
/*           GET THE CROSS SECTION ELEMENT VALUES */
/*           GET THE AREA AND FIRST MOMENT IN THE DOWNSTREAM SECTION AT */
/*           THE UPSTREAM ELEVATION. */
/* SOURCE exnmat.for:166 */
/*<       adr=exnodt(4,dnn) >*/
		adr = exnodt[dnn * 9 + 4];
/* SOURCE exnmat.for:167 */
/*<       y=yl+zl-zr >*/
		y = static_cast<double>(static_cast<double>(yl) + zl) - zr;
/* SOURCE exnmat.for:168 */
/*<       callxlkt21(adr,y,arl,tr,dtr,jrl,con,dcon,br,dbr) >*/
		xlkt21_(&adr, &y, &arl, &tr, &dtr, &jrl, &con, &dcon, &br, &
			dbr);
/*           GET VALUES AT DOWNSTREAM SECTION AT DOWNSTREAM DEPTH */
/* SOURCE exnmat.for:174 */
/*<       callxlkt21(adr,yr,ar,tr,dtr,jr,con,dcon,br,dbr) >*/
		xlkt21_(&adr, &yr, &ar, &tr, &dtr, &jr, &con, &dcon, &br, &
			dbr);
/*           GET VALUES AT UPSTREAM SECTION AT UPSTREAM DEPTH */
/* SOURCE exnmat.for:180 */
/*<       adr=exnodt(4,unn) >*/
		adr = exnodt[unn * 9 + 4];
/* SOURCE exnmat.for:181 */
/*<       callxlkt21(adr,yl,al,tl,dtl,jl,con,dcon,bl,dbl) >*/
		xlkt21_(&adr, &yl, &al, &tl, &dtl, &jl, &con, &dcon, &bl, &
			dbl);
/*           COMPUTE RESIDUAL FOR THE MOMENTUM BALANCE */
/* SOURCE exnmat.for:188 */
/*<       vl=ql/al >*/
		vl = static_cast<double>(ql) / al;
/* SOURCE exnmat.for:189 */
/*<       vr=qr/ar >*/
		vr = static_cast<double>(qr) / ar;
/* SOURCE exnmat.for:191 */
/*<       res=grav*(jrl-jr)+bl*ql*vl-br*qr*vr >*/
		*res = static_cast<double>(static_cast<double>(static_cast<double>(*grav) * (static_cast<double>(jrl) - jr)) + static_cast<double>(static_cast<double>(bl) * ql) * vl) - static_cast<double>(static_cast<double>(br) * qr) * vr;
/* SOURCE exnmat.for:192 */
/*<       if(res.ge.0.0)then >*/
		if (*res >= (float)0.) {
/*             REMAIN IN CRITICAL STATE */
/* SOURCE exnmat.for:194 */
/*<       calllktab(cftab,yl,1,qc,ntab,pdv) >*/
		    lktab_(&cftab, &yl, &feq_gen_c_d_1, &qc, &ntab, &pdv);
/* SOURCE exnmat.for:198 */
/*<       res=ql-qc >*/
		    *res = static_cast<double>(ql) - qc;
/* SOURCE exnmat.for:199 */
/*<       pyl=-pdv >*/
		    *pyl = -pdv;
/* SOURCE exnmat.for:200 */
/*<       pql=1.0 >*/
		    *pql = (float)1.;
/* SOURCE exnmat.for:201 */
/*<       pyr=0.0 >*/
		    *pyr = (float)0.;
/* SOURCE exnmat.for:202 */
/*<       pqr=0.0 >*/
		    *pqr = (float)0.;
/* SOURCE exnmat.for:203 */
/*<       return >*/
		    return 0;
/* SOURCE exnmat.for:204 */
/*<       else >*/
		} else {
/*             SWITCH TO SUBCRITCAL STATE */
/* SOURCE exnmat.for:207 */
/*<       state=-state >*/
		    state = -state;
/* SOURCE exnmat.for:210 */
/*<       fac=al*dbl-bl*tl >*/
		    fac = static_cast<double>(static_cast<double>(al) * dbl) - static_cast<double>(bl) * tl;
/* SOURCE exnmat.for:211 */
/*<       if(fac.gt.0.0)write(stdout,52)getusn(unn),yl >*/
		    if (fac > (float)0.) {
			feq_gen_io_d__39.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__39);
			getusn_(feq_gen_ch_d_2, (ftnlen)5, &unn);
			s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
			do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
			do_fio(&feq_gen_c_d_1, (char *)&yl, (ftnlen)sizeof(real));
			e_wsfe();
		    }
/* SOURCE exnmat.for:212 */
/*<       pyl=grav*arl+vl*vl*fac >*/
		    *pyl = static_cast<double>(static_cast<double>(*grav) * arl) + static_cast<double>(static_cast<double>(vl) * vl) * fac;
/* SOURCE exnmat.for:213 */
/*<       pql=2.*bl*vl >*/
		    *pql = static_cast<double>(static_cast<double>(bl) * (float)2.) * vl;
/* SOURCE exnmat.for:214 */
/*<       fac=ar*dbr-br*tr >*/
		    fac = static_cast<double>(static_cast<double>(ar) * dbr) - static_cast<double>(br) * tr;
/* SOURCE exnmat.for:215 */
/*<       if(fac.gt.0.0)write(stdout,54)getusn(dnn),yr >*/
		    if (fac > (float)0.) {
			feq_gen_io_d__40.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__40);
			getusn_(feq_gen_ch_d_2, (ftnlen)5, &dnn);
			s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
			do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
			do_fio(&feq_gen_c_d_1, (char *)&yr, (ftnlen)sizeof(real));
			e_wsfe();
		    }
/* SOURCE exnmat.for:216 */
/*<       pyr=-grav*ar-vr*vr*fac >*/
		    *pyr = static_cast<double>(static_cast<double>(-(*grav)) * ar) - static_cast<double>(static_cast<double>(vr) * vr) * fac;
/* SOURCE exnmat.for:217 */
/*<       pqr=-2.*br*vr >*/
		    *pqr = static_cast<double>(static_cast<double>(br) * (float)-2.) * vr;
/* SOURCE exnmat.for:218 */
/*<       emc(ipnt+6)=state >*/
		    emc[*ipnt + 6] = state;
/* SOURCE exnmat.for:220 */
/*<       return >*/
		    return 0;
/* SOURCE exnmat.for:221 */
/*<       endif >*/
		}
/* SOURCE exnmat.for:222 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:223 */
/*<       else >*/
	} else {
/*         SUBCRITICAL FLOW - CHECK FOR SWITCH IN STATE */
/* SOURCE exnmat.for:226 */
/*<       calllktab(cftab,yl,1,qc,ntab,pdv) >*/
	    lktab_(&cftab, &yl, &feq_gen_c_d_1, &qc, &ntab, &pdv);
/* SOURCE exnmat.for:229 */
/*<       if(ql.ge.qc)then >*/
	    if (ql >= qc) {
/*           SWITCH TO CRITICAL */
/* SOURCE exnmat.for:232 */
/*<       state=-state >*/
		state = -state;
/* SOURCE exnmat.for:233 */
/*<       res=ql-qc >*/
		*res = static_cast<double>(ql) - qc;
/* SOURCE exnmat.for:234 */
/*<       pyl=-pdv >*/
		*pyl = -pdv;
/* SOURCE exnmat.for:235 */
/*<       pql=1.0 >*/
		*pql = (float)1.;
/* SOURCE exnmat.for:236 */
/*<       pyr=0.0 >*/
		*pyr = (float)0.;
/* SOURCE exnmat.for:237 */
/*<       pqr=0.0 >*/
		*pqr = (float)0.;
/* SOURCE exnmat.for:238 */
/*<       emc(ipnt+6)=state >*/
		emc[*ipnt + 6] = state;
/* SOURCE exnmat.for:239 */
/*<       return >*/
		return 0;
/* SOURCE exnmat.for:240 */
/*<       else >*/
	    } else {
/*           REMAIN SUBCRITICAL */
/*           GET THE CROSS SECTION ELEMENT VALUES */
/*           GET THE AREA AND FIRST MOMENT IN THE DOWNSTREAM SECTION AT */
/*           THE UPSTREAM ELEVATION. */
/* SOURCE exnmat.for:248 */
/*<       adr=exnodt(4,dnn) >*/
		adr = exnodt[dnn * 9 + 4];
/* SOURCE exnmat.for:249 */
/*<       y=yl+zl-zr >*/
		y = static_cast<double>(static_cast<double>(yl) + zl) - zr;
/* SOURCE exnmat.for:250 */
/*<       callxlkt21(adr,y,arl,tr,dtr,jrl,con,dcon,br,dbr) >*/
		xlkt21_(&adr, &y, &arl, &tr, &dtr, &jrl, &con, &dcon, &br, &
			dbr);
/*           GET VALUES AT DOWNSTREAM SECTION AT DOWNSTREAM DEPTH */
/* SOURCE exnmat.for:256 */
/*<       callxlkt21(adr,yr,ar,tr,dtr,jr,con,dcon,br,dbr) >*/
		xlkt21_(&adr, &yr, &ar, &tr, &dtr, &jr, &con, &dcon, &br, &
			dbr);
/*           GET VALUES AT UPSTREAM SECTION AT UPSTREAM DEPTH */
/* SOURCE exnmat.for:262 */
/*<       adr=exnodt(4,unn) >*/
		adr = exnodt[unn * 9 + 4];
/* SOURCE exnmat.for:263 */
/*<       callxlkt21(adr,yl,al,tl,dtl,jl,con,dcon,bl,dbl) >*/
		xlkt21_(&adr, &yl, &al, &tl, &dtl, &jl, &con, &dcon, &bl, &
			dbl);
/*           COMPUTE RESIDUAL FOR THE MOMENTUM BALANCE */
/* SOURCE exnmat.for:270 */
/*<       vl=ql/al >*/
		vl = static_cast<double>(ql) / al;
/* SOURCE exnmat.for:271 */
/*<       vr=qr/ar >*/
		vr = static_cast<double>(qr) / ar;
/* SOURCE exnmat.for:273 */
/*<       res=grav*(jrl-jr)+bl*ql*vl-br*qr*vr >*/
		*res = static_cast<double>(static_cast<double>(static_cast<double>(*grav) * (static_cast<double>(jrl) - jr)) + static_cast<double>(static_cast<double>(bl) * ql) * vl) - static_cast<double>(static_cast<double>(br) * qr) * vr;
/* SOURCE exnmat.for:275 */
/*<       fac=al*dbl-bl*tl >*/
		fac = static_cast<double>(static_cast<double>(al) * dbl) - static_cast<double>(bl) * tl;
/* SOURCE exnmat.for:276 */
/*<       if(fac.gt.0.0)write(stdout,52)getusn(unn),yl >*/
		if (fac > (float)0.) {
		    feq_gen_io_d__41.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__41);
		    getusn_(feq_gen_ch_d_2, (ftnlen)5, &unn);
		    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		    do_fio(&feq_gen_c_d_1, (char *)&yl, (ftnlen)sizeof(real));
		    e_wsfe();
		}
/* SOURCE exnmat.for:277 */
/*<       pyl=grav*arl+vl*vl*fac >*/
		*pyl = static_cast<double>(static_cast<double>(*grav) * arl) + static_cast<double>(static_cast<double>(vl) * vl) * fac;
/* SOURCE exnmat.for:278 */
/*<       pql=2.*bl*vl >*/
		*pql = static_cast<double>(static_cast<double>(bl) * (float)2.) * vl;
/* SOURCE exnmat.for:279 */
/*<       fac=ar*dbr-br*tr >*/
		fac = static_cast<double>(static_cast<double>(ar) * dbr) - static_cast<double>(br) * tr;
/* SOURCE exnmat.for:280 */
/*<       if(fac.gt.0.0)write(stdout,54)getusn(dnn),yr >*/
		if (fac > (float)0.) {
		    feq_gen_io_d__42.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__42);
		    getusn_(feq_gen_ch_d_2, (ftnlen)5, &dnn);
		    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
		    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
		    do_fio(&feq_gen_c_d_1, (char *)&yr, (ftnlen)sizeof(real));
		    e_wsfe();
		}
/* SOURCE exnmat.for:281 */
/*<       pyr=-grav*ar-vr*vr*fac >*/
		*pyr = static_cast<double>(static_cast<double>(-(*grav)) * ar) - static_cast<double>(static_cast<double>(vr) * vr) * fac;
/* SOURCE exnmat.for:282 */
/*<       pqr=-2.*br*vr >*/
		*pqr = static_cast<double>(static_cast<double>(br) * (float)-2.) * vr;
/* SOURCE exnmat.for:283 */
/*<       return >*/
		return 0;
/* SOURCE exnmat.for:284 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:285 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:286 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:288 */
/*<       end >*/
    return 0;
} /* abrexp_ */




/* SOURCE exnmat.for:292 */
/*<        >*/
/* Subroutine */ int bdftab_(integer *ipnt, integer *mlemc, real *feq_storage_ye2, real *
	feq_storage_ze, real *feq_storage_qe2, integer *nex, real *c52eps, integer *feq_storage_emc, real *res, 
	real *pyl, real *pql, real *pyr, real *pqr)
{
    // EL=YL+ZL and ER=YR+ZR retain 53-bit sums before the stored heads.
    // Original 0x4203f0-0x420423. DISCH=QF*CS also remains wider
    // until RES=Q-QF*CS is stored at 0x420d2a.

    /* System generated locals */
    real feq_gen_r_d_1;
    static real equiv_0[1];

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    real feq_gen_d_d_, feq_gen_h_d_, k, t, dk, cs, qf, sh, dx, ql, qr, yl, zl, yr, zr, zw, arg, dcs, dqf;
    doublereal el, er;
    integer dnn, key, qnn, unn;
    real qsw;
    integer ntab;
#define idum (feq::BitView<integer>(equiv_0, sizeof(equiv_0)))
#define rdum (equiv_0)
    integer tqdu, tqud, tsdu, tsud;
    real pump;
    doublereal disch;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    real elvin;
    integer sysgn, ponoff, swnode;
    real turnon;

/*     + + + PURPOSE + + + */
/*     Compute bidirectional flow using either tables giving */
/*     flow as function of head together with a submergence */
/*     correction or using a table of square root of conveyance */
/*     together with the water surface slope. */
/* SOURCE exnmat.for:303 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:305 */
/*<       integeripnt,mlemc,nex >*/
/* SOURCE exnmat.for:306 */
/*<       integeremc(mlemc) >*/
/* SOURCE exnmat.for:307 */
/*<       realc52eps,pql,pqr,pyl,pyr,qe2(nex),res,ye2(nex),ze(nex) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IPNT   - pointer into EMC for description of control structure */
/*     MLEMC  - maximum length of EMC(*) */
/*     YE2    - depths at exterior nodes at end of time step */
/*     ZE     - elevation of datum for depth at exterior node */
/*     QE2    - flow at exterior nodes at end of time step */
/*     NEX    - number of exterior nodes in the model */
/*     C52EPS - tolerance for water level to prevent cycling of pump */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     RES    - value of the residual function */
/*     PYL    - partial derivative of residual function wrt depth at */
/*               left node */
/*     PQL    - partial derivative of residual function wrt flow at left */
/*               node */
/*     PYR    - partial derivative of residual function wrt depth at */
/*               right node */
/*     PQR    - partial derivative of residual function wrt flow at right */
/*               node */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE exnmat.for:329 */
/*<        >*/
/* SOURCE exnmat.for:331 */
/*<        >*/
/* INCLUDE exnmat.for:335 */
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
/* SOURCE exnmat.for:337 */
/*<       charactergetusn*5 >*/
/*     + + + EQUIVALENCES + + + */
/* SOURCE exnmat.for:340 */
/*<       equivalence(idum,rdum) >*/
/*     + + + INTRINSICS + + + */
/* SOURCE exnmat.for:343 */
/*<       intrinsicabs,sqrt >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE exnmat.for:346 */
/*<       externallktab,getusn >*/
/* *********************************************************************** */
/*     OBTAIN BASIC INFORMATION FROM EMC */
/* SOURCE exnmat.for:350 */
/*<       unn=emc(ipnt+2) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    feq::IndexedPointer<real> qe2(feq_storage_qe2, 1);

    feq::IndexedPointer<real> ze(feq_storage_ze, 1);

    feq::IndexedPointer<real> ye2(feq_storage_ye2, 1);

    /* Function Body */
    unn = emc[*ipnt + 2];
/* SOURCE exnmat.for:351 */
/*<       dnn=emc(ipnt+3) >*/
    dnn = emc[*ipnt + 3];
/* SOURCE exnmat.for:352 */
/*<       qnn=emc(ipnt+4) >*/
    qnn = emc[*ipnt + 4];
/* SOURCE exnmat.for:353 */
/*<       sysgn=emc(ipnt+5) >*/
    sysgn = emc[*ipnt + 5];
/* SOURCE exnmat.for:354 */
/*<       tqud=emc(ipnt+6) >*/
    tqud = emc[*ipnt + 6];
/* SOURCE exnmat.for:355 */
/*<       tsud=emc(ipnt+7) >*/
    tsud = emc[*ipnt + 7];
/* SOURCE exnmat.for:356 */
/*<       tqdu=emc(ipnt+8) >*/
    tqdu = emc[*ipnt + 8];
/* SOURCE exnmat.for:357 */
/*<       tsdu=emc(ipnt+9) >*/
    tsdu = emc[*ipnt + 9];
/* SOURCE exnmat.for:358 */
/*<       idum=emc(ipnt+10) >*/
    *idum = emc[*ipnt + 10];
/* SOURCE exnmat.for:359 */
/*<       zw=rdum >*/
    zw = *rdum;
/* SOURCE exnmat.for:360 */
/*<       idum=emc(ipnt+11) >*/
    *idum = emc[*ipnt + 11];
/* SOURCE exnmat.for:361 */
/*<       dx=rdum >*/
    dx = *rdum;
/* SOURCE exnmat.for:362 */
/*<       idum=emc(ipnt+12) >*/
    *idum = emc[*ipnt + 12];
/* SOURCE exnmat.for:363 */
/*<       pump=rdum >*/
    pump = *rdum;
/* SOURCE exnmat.for:364 */
/*<       if(pump.ne.0.0)then >*/
    if (pump != (float)0.) {
/* SOURCE exnmat.for:365 */
/*<       idum=emc(ipnt+13) >*/
	*idum = emc[*ipnt + 13];
/* SOURCE exnmat.for:366 */
/*<       elvin=rdum >*/
	elvin = *rdum;
/* SOURCE exnmat.for:367 */
/*<       idum=emc(ipnt+14) >*/
	*idum = emc[*ipnt + 14];
/* SOURCE exnmat.for:368 */
/*<       turnon=rdum >*/
	turnon = *rdum;
/* SOURCE exnmat.for:369 */
/*<       ponoff=emc(ipnt+15) >*/
	ponoff = emc[*ipnt + 15];
/* SOURCE exnmat.for:370 */
/*<       key=emc(ipnt+16) >*/
	key = emc[*ipnt + 16];
/* SOURCE exnmat.for:371 */
/*<       qr=qe2(dnn) >*/
	qr = qe2[dnn];
/* SOURCE exnmat.for:372 */
/*<       ql=qe2(unn) >*/
	ql = qe2[unn];
/* SOURCE exnmat.for:373 */
/*<       swnode=emc(ipnt+17) >*/
	swnode = emc[*ipnt + 17];
/* SOURCE exnmat.for:374 */
/*<       if(swnode.gt.0)then >*/
	if (swnode > 0) {
/* SOURCE exnmat.for:375 */
/*<       qsw=qe2(swnode) >*/
	    qsw = qe2[swnode];
/* SOURCE exnmat.for:376 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:377 */
/*<       qsw=0.0 >*/
	    qsw = (float)0.;
/* SOURCE exnmat.for:378 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:379 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:381 */
/*<       yl=ye2(unn) >*/
    yl = ye2[unn];
/* SOURCE exnmat.for:382 */
/*<       yr=ye2(dnn) >*/
    yr = ye2[dnn];
/* SOURCE exnmat.for:383 */
/*<       zl=ze(unn) >*/
    zl = ze[unn];
/* SOURCE exnmat.for:384 */
/*<       zr=ze(dnn) >*/
    zr = ze[dnn];
/* SOURCE exnmat.for:385 */
/*<       el=yl+zl >*/
    el = static_cast<double>(yl) + zl;
/* SOURCE exnmat.for:386 */
/*<       er=yr+zr >*/
    er = static_cast<double>(yr) + zr;
/*     DETERMINE WHICH OPTION IS IN EFFECT */
/*     TSUD = 0 IMPLIES NO SUBMERGENCE CORRECTION TABLES AND THEREFORE */
/*      THE SLOPE DETERMINED FLOW OPTION IS SELECTED */
/* SOURCE exnmat.for:393 */
/*<       if(tsud.eq.0)goto500 >*/
    if (tsud == 0) {
	goto L500;
    }
/*       COMPUTE THE FLOW AND DERIVATIVES AS GIVEN BY THE TABLES */
/*       FOR THE TWO FLOW DIRECTIONS */
/*       ASSUME POSITIVE FLOW I. E. YL+ZL>YR+ZR */
/* SOURCE exnmat.for:400 */
/*<       h=el-zw >*/
    feq_gen_h_d_ = static_cast<double>(el) - zw;
/* SOURCE exnmat.for:401 */
/*<       d=er-zw >*/
    feq_gen_d_d_ = static_cast<double>(er) - zw;
/* SOURCE exnmat.for:402 */
/*<       if(h.lt.0.)h=0.0 >*/
    if (feq_gen_h_d_ < (float)0.) {
	feq_gen_h_d_ = (float)0.;
    }
/* SOURCE exnmat.for:403 */
/*<       if(d.lt.0.)d=0.0 >*/
    if (feq_gen_d_d_ < (float)0.) {
	feq_gen_d_d_ = (float)0.;
    }
/* SOURCE exnmat.for:405 */
/*<       if(el.lt.er)goto200 >*/
    if (el < er) {
	goto L200;
    }
/*         POSITIVE CASE HERE-FLOW FROM UPSTREAM TO DOWNSTREAM OR */
/*         ZERO FLOW. */
/*         DO TABLE LOOKUP-SUBMERGENCE CORRECTION MAY BE OPTIONAL */
/*         DEPENDING ON VALUE OF D. */
/* SOURCE exnmat.for:412 */
/*<       if(h.gt.0.0)then >*/
    if (feq_gen_h_d_ > (float)0.) {
/* SOURCE exnmat.for:413 */
/*<       calllktab(tqud,h,0,qf,ntab,dqf) >*/
	lktab_(&tqud, &feq_gen_h_d_, &feq_gen_c_d_0, &qf, &ntab, &dqf);
/* SOURCE exnmat.for:416 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:417 */
/*<       qf=0.0 >*/
	qf = (float)0.;
/* SOURCE exnmat.for:418 */
/*<       dqf=0.0 >*/
	dqf = (float)0.;
/* SOURCE exnmat.for:419 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:421 */
/*<       if(d.gt.0.)then >*/
    if (feq_gen_d_d_ > (float)0.) {
/* SOURCE exnmat.for:422 */
/*<       arg=d/h >*/
	arg = static_cast<double>(feq_gen_d_d_) / feq_gen_h_d_;
/* SOURCE exnmat.for:423 */
/*<       calllktab(tsud,arg,0,cs,ntab,dcs) >*/
	lktab_(&tsud, &arg, &feq_gen_c_d_0, &cs, &ntab, &dcs);
/* SOURCE exnmat.for:426 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:427 */
/*<       cs=1. >*/
	cs = (float)1.;
/* SOURCE exnmat.for:428 */
/*<       dcs=0. >*/
	dcs = (float)0.;
/* SOURCE exnmat.for:429 */
/*<       h=1. >*/
	feq_gen_h_d_ = (float)1.;
/* SOURCE exnmat.for:430 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:431 */
/*<       pyl=dqf*cs-qf*dcs*d/h**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = feq_gen_h_d_;
    *pyl = static_cast<double>(static_cast<double>(dqf) * cs) - static_cast<double>(static_cast<double>(static_cast<double>(qf) * dcs) * feq_gen_d_d_) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE exnmat.for:432 */
/*<       pyr=qf*dcs/h >*/
    *pyr = static_cast<double>(static_cast<double>(qf) * dcs) / feq_gen_h_d_;
/* SOURCE exnmat.for:433 */
/*<       disch=qf*cs >*/
    disch = static_cast<double>(qf) * cs;
/* SOURCE exnmat.for:434 */
/*<       goto400 >*/
    goto L400;
/* SOURCE exnmat.for:435 */
/*<   200 continue >*/
L200:
/*         NEGATIVE CASE HERE-FLOW FROM DOWNSTREAM TO UPSTREAM */
/*         SWITCH H AND D USING T AS TEMP LOCATION */
/* SOURCE exnmat.for:440 */
/*<       t=h >*/
    t = feq_gen_h_d_;
/* SOURCE exnmat.for:441 */
/*<       h=d >*/
    feq_gen_h_d_ = feq_gen_d_d_;
/* SOURCE exnmat.for:442 */
/*<       d=t >*/
    feq_gen_d_d_ = t;
/* SOURCE exnmat.for:443 */
/*<       if(h.gt.0.0)then >*/
    if (feq_gen_h_d_ > (float)0.) {
/* SOURCE exnmat.for:444 */
/*<       calllktab(tqdu,h,0,qf,ntab,dqf) >*/
	lktab_(&tqdu, &feq_gen_h_d_, &feq_gen_c_d_0, &qf, &ntab, &dqf);
/* SOURCE exnmat.for:447 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:448 */
/*<       qf=0.0 >*/
	qf = (float)0.;
/* SOURCE exnmat.for:449 */
/*<       dqf=0.0 >*/
	dqf = (float)0.;
/* SOURCE exnmat.for:450 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:451 */
/*<       if(d.gt.0)then >*/
    if (feq_gen_d_d_ > (float)0.) {
/* SOURCE exnmat.for:452 */
/*<       arg=d/h >*/
	arg = static_cast<double>(feq_gen_d_d_) / feq_gen_h_d_;
/* SOURCE exnmat.for:453 */
/*<       calllktab(tsdu,arg,0,cs,ntab,dcs) >*/
	lktab_(&tsdu, &arg, &feq_gen_c_d_0, &cs, &ntab, &dcs);
/* SOURCE exnmat.for:456 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:457 */
/*<       cs=1. >*/
	cs = (float)1.;
/* SOURCE exnmat.for:458 */
/*<       dcs=0. >*/
	dcs = (float)0.;
/* SOURCE exnmat.for:459 */
/*<       h=1. >*/
	feq_gen_h_d_ = (float)1.;
/* SOURCE exnmat.for:460 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:461 */
/*<       pyl=-(qf*dcs/h) >*/
    *pyl = -(static_cast<double>(static_cast<double>(qf) * dcs) / feq_gen_h_d_);
/* SOURCE exnmat.for:462 */
/*<       pyr=-(dqf*cs-qf*dcs*d/h**2) >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = feq_gen_h_d_;
    *pyr = -(static_cast<double>(static_cast<double>(dqf) * cs) - static_cast<double>(static_cast<double>(static_cast<double>(qf) * dcs) * feq_gen_d_d_) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1));
/* SOURCE exnmat.for:463 */
/*<       disch=-qf*cs >*/
    disch = static_cast<double>(-qf) * cs;
/* SOURCE exnmat.for:464 */
/*<   400 continue >*/
L400:
/*       CHECK IF PUMP IS PRESENT.  EL IS ELEV AT NOMINAL UPSTREAM NODE */
/*       ER IS ELEVATION AT NOMINAL DOWNSTREAM NODE */
/* SOURCE exnmat.for:469 */
/*<       if(pump.ne.0.0)then >*/
    if (pump != (float)0.) {
/*         MAKE ADJUSTMENTS FOR POSSIBLE PUMPED FLOWS.  ONLY THE FLOW IS */
/*         AFFECTED.  DERIVATIVES ARE UNCHANGED BECAUSE PUMP RATE IS */
/*         ONLY TURNED ON OR OFF BASED ON ELEVATION OR FLOW OR THE */
/*         CONDITION AT A SWITCH NODE BUT IS OTHERWISE */
/*         CONSTANT */
/* SOURCE exnmat.for:476 */
/*<       if(swnode.gt.0)then >*/
	if (swnode > 0) {
/*           DOMINANT RULE FOR CONTROL OF PUMP */
/* SOURCE exnmat.for:478 */
/*<       if(qsw.gt.0.0)then >*/
	    if (qsw > (float)0.) {
/*             SET PUMP TO OFF */
/* SOURCE exnmat.for:480 */
/*<       emc(ipnt+15)=0 >*/
		emc[*ipnt + 15] = 0;
/* SOURCE exnmat.for:481 */
/*<       goto1000 >*/
		goto L1000;
/* SOURCE exnmat.for:482 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:483 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:485 */
/*<       if(pump.gt.0.0)then >*/
	if (pump > (float)0.) {
/*           IF PUMP IS ON WATER IS TAKEN FROM THE NOMINAL UPSTREAM */
/*           NODE AND DISCHARGED TO THE NOMINAL DOWNSTREAM NODE */
/* SOURCE exnmat.for:488 */
/*<       if(ponoff.eq.0)then >*/
	    if (ponoff == 0) {
/*             PUMP IS OFF- SHALL IT BE TURNED ON? */
/* SOURCE exnmat.for:490 */
/*<       if(key.eq.0)then >*/
		if (key == 0) {
/* SOURCE exnmat.for:491 */
/*<       if(el.gt.elvin.and.er.lt.turnon)then >*/
		    if (el > elvin && er < turnon) {
/* SOURCE exnmat.for:492 */
/*<       ponoff=1 >*/
			ponoff = 1;
/* SOURCE exnmat.for:493 */
/*<       disch=disch+pump >*/
			disch += pump;
/* SOURCE exnmat.for:494 */
/*<       endif >*/
		    }
/* SOURCE exnmat.for:495 */
/*<       else >*/
		} else {
/* SOURCE exnmat.for:496 */
/*<       if(el.gt.elvin.and.qr.gt.0.0.and.qr.lt.turnon)then >*/
		    if (el > elvin && qr > (float)0. && qr < turnon) {
/* SOURCE exnmat.for:497 */
/*<       ponoff=1 >*/
			ponoff = 1;
/* SOURCE exnmat.for:498 */
/*<       disch=disch+pump >*/
			disch += pump;
/* SOURCE exnmat.for:499 */
/*<       endif >*/
		    }
/* SOURCE exnmat.for:500 */
/*<       endif >*/
		}
/* SOURCE exnmat.for:501 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:502 */
/*<       if(key.eq.0)then >*/
		if (key == 0) {
/* SOURCE exnmat.for:503 */
/*<       if(el.le.elvin-c52eps.or.er.ge.zw)then >*/
		    if (el <= static_cast<double>(elvin) - *c52eps || er >= zw) {
/* SOURCE exnmat.for:504 */
/*<       ponoff=0 >*/
			ponoff = 0;
/* SOURCE exnmat.for:505 */
/*<       else >*/
		    } else {
/* SOURCE exnmat.for:506 */
/*<       disch=disch+pump >*/
			disch += pump;
/* SOURCE exnmat.for:507 */
/*<       endif >*/
		    }
/* SOURCE exnmat.for:508 */
/*<       else >*/
		} else {
/* SOURCE exnmat.for:509 */
/*<       if(el.le.elvin-c52eps.or.qr.gt.turnon+2.*pump)then >*/
		    if (el <= static_cast<double>(elvin) - *c52eps || qr > static_cast<double>(turnon) + static_cast<double>(pump) * (float)
			    2.) {
/* SOURCE exnmat.for:510 */
/*<       ponoff=0 >*/
			ponoff = 0;
/* SOURCE exnmat.for:511 */
/*<       else >*/
		    } else {
/* SOURCE exnmat.for:512 */
/*<       disch=disch+pump >*/
			disch += pump;
/* SOURCE exnmat.for:513 */
/*<       endif >*/
		    }
/* SOURCE exnmat.for:514 */
/*<       endif >*/
		}
/* SOURCE exnmat.for:515 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:516 */
/*<       else >*/
	} else {
/*           IF PUMP IS ON WATER IS TAKEN FROM THE NOMINAL DOWNSTREAM NODE */
/*           AND DISCHARGED TO THE NOMINAL UPSTREAM NODE. */
/* SOURCE exnmat.for:520 */
/*<       if(ponoff.eq.0)then >*/
	    if (ponoff == 0) {
/*             PUMP IS OFF- SHALL IT BE TURNED ON? */
/* SOURCE exnmat.for:522 */
/*<       if(key.eq.0)then >*/
		if (key == 0) {
/* SOURCE exnmat.for:523 */
/*<       if(er.gt.elvin.and.el.lt.turnon)then >*/
		    if (er > elvin && el < turnon) {
/* SOURCE exnmat.for:524 */
/*<       ponoff=1 >*/
			ponoff = 1;
/* SOURCE exnmat.for:525 */
/*<       disch=disch+pump >*/
			disch += pump;
/* SOURCE exnmat.for:526 */
/*<       endif >*/
		    }
/* SOURCE exnmat.for:527 */
/*<       else >*/
		} else {
/* SOURCE exnmat.for:528 */
/*<       if(er.gt.elvin.and.ql.gt.0.0.and.ql.lt.turnon)then >*/
		    if (er > elvin && ql > (float)0. && ql < turnon) {
/* SOURCE exnmat.for:529 */
/*<       ponoff=1 >*/
			ponoff = 1;
/* SOURCE exnmat.for:530 */
/*<       disch=disch+pump >*/
			disch += pump;
/* SOURCE exnmat.for:531 */
/*<       endif >*/
		    }
/* SOURCE exnmat.for:532 */
/*<       endif >*/
		}
/* SOURCE exnmat.for:533 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:534 */
/*<       if(key.eq.0)then >*/
		if (key == 0) {
/* SOURCE exnmat.for:535 */
/*<       if(er.le.elvin-c52eps.or.el.ge.zw)then >*/
		    if (er <= static_cast<double>(elvin) - *c52eps || el >= zw) {
/* SOURCE exnmat.for:536 */
/*<       ponoff=0 >*/
			ponoff = 0;
/* SOURCE exnmat.for:537 */
/*<       else >*/
		    } else {
/* SOURCE exnmat.for:538 */
/*<       disch=disch+pump >*/
			disch += pump;
/* SOURCE exnmat.for:539 */
/*<       endif >*/
		    }
/* SOURCE exnmat.for:540 */
/*<       else >*/
		} else {
/* SOURCE exnmat.for:541 */
/*<       if(er.le.elvin-c52eps.or.ql.gt.turnon-2.*pump)then >*/
		    if (er <= static_cast<double>(elvin) - *c52eps || ql > static_cast<double>(turnon) - static_cast<double>(pump) * (float)
			    2.) {
/* SOURCE exnmat.for:542 */
/*<       ponoff=0 >*/
			ponoff = 0;
/* SOURCE exnmat.for:543 */
/*<       else >*/
		    } else {
/* SOURCE exnmat.for:544 */
/*<       disch=disch+pump >*/
			disch += pump;
/* SOURCE exnmat.for:545 */
/*<       endif >*/
		    }
/* SOURCE exnmat.for:546 */
/*<       endif >*/
		}
/* SOURCE exnmat.for:547 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:548 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:549 */
/*<       emc(ipnt+15)=ponoff >*/
	emc[*ipnt + 15] = ponoff;
/* SOURCE exnmat.for:550 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:551 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE exnmat.for:552 */
/*<   500 continue >*/
L500:
/*       CASE FOR WHICH CONVEYANCE AND SLOPE ARE COMPUTED TO FIND */
/*       THE FLOW */
/* SOURCE exnmat.for:557 */
/*<       h=el-er >*/
    feq_gen_h_d_ = static_cast<double>(el) - er;
/*       USE D TO DETECT ZERO FLOW CAUSED BY WATER SURFACE BEING */
/*       BELOW THE MINIMUM POINT IN THE FLOW PATH CONNECTING THE */
/*       TWO NODES. */
/* SOURCE exnmat.for:563 */
/*<       d=0.5*(el+er)-zw >*/
    feq_gen_d_d_ = static_cast<double>(static_cast<double>((static_cast<double>(el) + er)) * (float).5) - zw;
/* SOURCE exnmat.for:565 */
/*<       if(d.le.0.0.or.h.eq.0.0)goto600 >*/
    if (feq_gen_d_d_ <= (float)0. || feq_gen_h_d_ == (float)0.) {
	goto L600;
    }
/*         NON-ZERO FLOW HERE-LOOKUP SQRT OF CONVEYANCE AND */
/*         COMPUTE FLOW AND DERIVATIVE. */
/* SOURCE exnmat.for:570 */
/*<       calllktab(tqud,d,0,k,ntab,dk) >*/
    lktab_(&tqud, &feq_gen_d_d_, &feq_gen_c_d_0, &k, &ntab, &dk);
/* SOURCE exnmat.for:573 */
/*<       k=k*k >*/
    k *= k;
/* SOURCE exnmat.for:574 */
/*<       dk=2.*k*dk >*/
    dk = static_cast<double>(static_cast<double>(k) * (float)2.) * dk;
/* SOURCE exnmat.for:575 */
/*<       sh=h/dx >*/
    sh = static_cast<double>(feq_gen_h_d_) / dx;
/* SOURCE exnmat.for:576 */
/*<       if(abs(sh).le.1.e-4)then >*/
    if (dabs(sh) <= (float)1e-4) {
/*           SPECIAL CASE FOR SMALL HEADS-MAKE LINEAR */
/* SOURCE exnmat.for:579 */
/*<       disch=100.*k*sh >*/
	disch = static_cast<double>(static_cast<double>(k) * (float)100.) * sh;
/* SOURCE exnmat.for:580 */
/*<       pyl=100.*(0.5*dk*sh+k/dx) >*/
	*pyl = static_cast<double>((static_cast<double>(static_cast<double>(static_cast<double>(dk) * (float).5) * sh) + static_cast<double>(k) / dx)) * (float)100.;
/* SOURCE exnmat.for:581 */
/*<       pyr=100.*(0.5*dk*sh-k/dx) >*/
	*pyr = static_cast<double>((static_cast<double>(static_cast<double>(static_cast<double>(dk) * (float).5) * sh) - static_cast<double>(k) / dx)) * (float)100.;
/* SOURCE exnmat.for:582 */
/*<       goto1000 >*/
	goto L1000;
/* SOURCE exnmat.for:583 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:584 */
/*<       sh=sqrt(abs(sh)) >*/
    sh = sqrt((dabs(sh)));
/* SOURCE exnmat.for:585 */
/*<       disch=k*sh >*/
    disch = static_cast<double>(k) * sh;
/* SOURCE exnmat.for:586 */
/*<       if(h.lt.0.0)disch=-disch >*/
    if (feq_gen_h_d_ < (float)0.) {
	disch = -disch;
    }
/* SOURCE exnmat.for:587 */
/*<       t=0.5*dk*sh >*/
    t = static_cast<double>(static_cast<double>(dk) * (float).5) * sh;
/* SOURCE exnmat.for:588 */
/*<       if(h.lt.0.0)t=-t >*/
    if (feq_gen_h_d_ < (float)0.) {
	t = -t;
    }
/* SOURCE exnmat.for:589 */
/*<       pyl=t+0.5*k/(sh*dx) >*/
    *pyl = static_cast<double>(t) + static_cast<double>(static_cast<double>(k) * (float).5) / (static_cast<double>(sh) * dx);
/* SOURCE exnmat.for:590 */
/*<       pyr=t-0.5*k/(sh*dx) >*/
    *pyr = static_cast<double>(t) - static_cast<double>(static_cast<double>(k) * (float).5) / (static_cast<double>(sh) * dx);
/* SOURCE exnmat.for:591 */
/*<       goto1000 >*/
    goto L1000;
/* SOURCE exnmat.for:593 */
/*<   600 continue >*/
L600:
/*         ZERO FLOW CASE */
/* SOURCE exnmat.for:597 */
/*<       pyr=0. >*/
    *pyr = (float)0.;
/* SOURCE exnmat.for:598 */
/*<       pyl=0. >*/
    *pyl = (float)0.;
/* SOURCE exnmat.for:599 */
/*<       res=qe2(qnn) >*/
    *res = qe2[qnn];
/* SOURCE exnmat.for:600 */
/*<       if(qnn.eq.unn)goto602 >*/
    if (qnn == unn) {
	goto L602;
    }
/* SOURCE exnmat.for:601 */
/*<       pqr=1. >*/
    *pqr = (float)1.;
/* SOURCE exnmat.for:602 */
/*<       pql=0. >*/
    *pql = (float)0.;
/* SOURCE exnmat.for:603 */
/*<       goto605 >*/
    goto L605;
/* SOURCE exnmat.for:604 */
/*<   602 continue >*/
L602:
/* SOURCE exnmat.for:605 */
/*<       pql=1. >*/
    *pql = (float)1.;
/* SOURCE exnmat.for:606 */
/*<       pqr=0. >*/
    *pqr = (float)0.;
/* SOURCE exnmat.for:607 */
/*<   605 continue >*/
L605:
/* SOURCE exnmat.for:608 */
/*<       return >*/
    return 0;
/* SOURCE exnmat.for:610 */
/*<  1000 continue >*/
L1000:
/*         APPLY EFFECT OF SYSGN TO VALUES */
/* SOURCE exnmat.for:614 */
/*<       if(sysgn.gt.0)goto1010 >*/
    if (sysgn > 0) {
	goto L1010;
    }
/* SOURCE exnmat.for:615 */
/*<       disch=-disch >*/
    disch = -disch;
/* SOURCE exnmat.for:616 */
/*<       pyl=-pyl >*/
    *pyl = -(*pyl);
/* SOURCE exnmat.for:617 */
/*<       pyr=-pyr >*/
    *pyr = -(*pyr);
/* SOURCE exnmat.for:618 */
/*<  1010 continue >*/
L1010:
/* SOURCE exnmat.for:619 */
/*<       res=qe2(qnn)-disch >*/
    *res = static_cast<double>(qe2[qnn]) - disch;
/*         CHANGE SIGN OF DERIVATIVES TO BE CONSISTENT WITH */
/*         DISCH IN COMPUTING RES */
/* SOURCE exnmat.for:624 */
/*<       pyl=-pyl >*/
    *pyl = -(*pyl);
/* SOURCE exnmat.for:625 */
/*<       pyr=-pyr >*/
    *pyr = -(*pyr);
/*         SET FLOW DERIVATIVES */
/* SOURCE exnmat.for:629 */
/*<       if(qnn.eq.unn)goto1020 >*/
    if (qnn == unn) {
	goto L1020;
    }
/* SOURCE exnmat.for:630 */
/*<       pqr=1. >*/
    *pqr = (float)1.;
/* SOURCE exnmat.for:631 */
/*<       pql=0. >*/
    *pql = (float)0.;
/* SOURCE exnmat.for:632 */
/*<       goto1030 >*/
    goto L1030;
/* SOURCE exnmat.for:633 */
/*<  1020 continue >*/
L1020:
/* SOURCE exnmat.for:634 */
/*<       pqr=0. >*/
    *pqr = (float)0.;
/* SOURCE exnmat.for:635 */
/*<       pql=1. >*/
    *pql = (float)1.;
/* SOURCE exnmat.for:636 */
/*<  1030 continue >*/
L1030:
/*        WRITE(STDOUT,*) 'BDFTAB: RES=',RES */
/*        WRITE(STDOUT,*) ' DERV:',PYL, PQL, PYR, PQR */
/*        WRITE(STDOUT,*) 'EL=',EL,' ER=',ER */
/*        WRITE(STDOUT,*) ' QE2(QNN)=',QE2(QNN) */
/* SOURCE exnmat.for:641 */
/*<       return >*/
    return 0;
/* SOURCE exnmat.for:642 */
/*<       end >*/
} /* bdftab_ */

#undef rdum
#undef idum





/* SOURCE exnmat.for:646 */
/*<        >*/
/* Subroutine */ int bdfwr_(integer *ipnt, integer *feq_storage_emc, integer *mlemc, real 
	*feq_storage_ye2, real *feq_storage_ze, real *feq_storage_qe2, real *feq_storage_ae2, real *feq_storage_te2, integer *nex, 
	integer *stdout, doublereal *jtime, real *grav, real *res, real *pyl, 
	real *pql, real *pyr, real *pqr)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:64* Table Id=\002,a,\002 has invali\
d values for\002,\002 structure setting.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];
    static real equiv_0[1];

    /* Builtin functions */
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    real feq_gen_c_d_, feq_gen_d_d_, feq_gen_h_d_, l, p, t;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real cd, dc, el, cs, er, qf, th, yl, zl, yr, zr, zw, fac, arg, dcs;
    integer dnn, qnn, unn;
    real dzw, facq;
    integer ntab;
#define idum (feq::BitView<integer>(equiv_0, sizeof(equiv_0)))
#define rdum (equiv_0)
    real facq2, alpha;
    integer nctab, pctab;
    real disch, vhead;
    integer hptab;
    real dtime;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    integer sysgn, opcode, subtab, ispout;
    extern /* Subroutine */ int lktstab_(integer *, doublereal *, real *, 
	    integer *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__100 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Bi-directional flow over a weir of given crest length.  Both */
/*     the elevation of the crest of the weir and the weir coefficient */
/*     may be varied by the program under the control of an operation */
/*     block. */
/* SOURCE exnmat.for:657 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:659 */
/*<       integeripnt,stdout,mlemc,nex >*/
/* SOURCE exnmat.for:660 */
/*<       integeremc(mlemc) >*/
/* SOURCE exnmat.for:661 */
/*<        >*/
/* SOURCE exnmat.for:663 */
/*<       real*8jtime >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IPNT   - pointer into EMC for description of control structure */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     MLEMC  - maximum length of EMC(*) */
/*     YE2    - depths at exterior nodes at end of time step */
/*     ZE     - elevation of datum for depth at exterior node */
/*     QE2    - flow at exterior nodes at end of time step */
/*     AE2    - area at exterior nodes. */
/*     TE2    - top width at an exterior node on a branch */
/*     NEX    - number of exterior nodes in the model */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     TIME   - elapsed time in seconds from start of run */
/*     GRAV   - value of acceleration due to gravity */
/*     RES    - value of the residual function */
/*     PYL    - partial derivative of residual function wrt depth at */
/*               left node */
/*     PQL    - partial derivative of residual function wrt flow at left */
/*               node */
/*     PYR    - partial derivative of residual function wrt depth at */
/*               right node */
/*     PQR    - partial derivative of residual function wrt flow at right */
/*               node */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE exnmat.for:689 */
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
/* INCLUDE exnmat.for:690 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE exnmat.for:693 */
/*<        >*/
/* SOURCE exnmat.for:695 */
/*<        >*/
/*     + + + EQUIVALENCES + + + */
/* SOURCE exnmat.for:700 */
/*<       equivalence(idum,rdum) >*/
/*     + + + INTRINSICS + + + */
/* SOURCE exnmat.for:703 */
/*<       intrinsiciabs,sqrt >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE exnmat.for:706 */
/*<       characterget_tabid*16 >*/
/* SOURCE exnmat.for:707 */
/*<       externallktab,get_tabid >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE exnmat.for:710 */
/*<    50  >*/
/* *********************************************************************** */
/*     OBTAIN BASIC INFORMATION FROM EMC */
/* SOURCE exnmat.for:715 */
/*<       unn=emc(ipnt+2) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    feq::IndexedPointer<real> te2(feq_storage_te2, 1);

    feq::IndexedPointer<real> ae2(feq_storage_ae2, 1);

    feq::IndexedPointer<real> qe2(feq_storage_qe2, 1);

    feq::IndexedPointer<real> ze(feq_storage_ze, 1);

    feq::IndexedPointer<real> ye2(feq_storage_ye2, 1);

    /* Function Body */
/* L50: */
    unn = emc[*ipnt + 2];
/* SOURCE exnmat.for:716 */
/*<       dnn=emc(ipnt+3) >*/
    dnn = emc[*ipnt + 3];
/* SOURCE exnmat.for:717 */
/*<       qnn=emc(ipnt+4) >*/
    qnn = emc[*ipnt + 4];
/* SOURCE exnmat.for:718 */
/*<       sysgn=emc(ipnt+5) >*/
    sysgn = emc[*ipnt + 5];
/* SOURCE exnmat.for:719 */
/*<       opcode=emc(ipnt+6) >*/
    opcode = emc[*ipnt + 6];
/* SOURCE exnmat.for:720 */
/*<       hptab=emc(ipnt+7) >*/
    hptab = emc[*ipnt + 7];
/* SOURCE exnmat.for:721 */
/*<       pctab=emc(ipnt+8) >*/
    pctab = emc[*ipnt + 8];
/* SOURCE exnmat.for:722 */
/*<       nctab=emc(ipnt+9) >*/
    nctab = emc[*ipnt + 9];
/* SOURCE exnmat.for:723 */
/*<       subtab=emc(ipnt+10) >*/
    subtab = emc[*ipnt + 10];
/* SOURCE exnmat.for:724 */
/*<       idum=emc(ipnt+11) >*/
    *idum = emc[*ipnt + 11];
/* SOURCE exnmat.for:725 */
/*<       l=rdum >*/
    l = *rdum;
/* SOURCE exnmat.for:726 */
/*<       idum=emc(ipnt+12) >*/
    *idum = emc[*ipnt + 12];
/* SOURCE exnmat.for:727 */
/*<       alpha=rdum >*/
    alpha = *rdum;
/*     ISPOUT gives pointer into gate/pump table for possible later */
/*     output to special output file.  If ISPOUT = 0 no name was */
/*     given but there is a null slot so that IF statements are not */
/*     needed. */
/* SOURCE exnmat.for:732 */
/*<       ispout=emc(ipnt+15) >*/
    ispout = emc[*ipnt + 15];
/*     DEFINE THE OPENING FRACTION FOR THIS TIME SETP */
/* SOURCE exnmat.for:736 */
/*<       if(opcode.gt.0)then >*/
    if (opcode > 0) {
/*       OPERATION BLOCK HAS ALREADY SET THE OPENING FRACTION */
/* SOURCE exnmat.for:739 */
/*<       idum=emc(ipnt+13) >*/
	*idum = emc[*ipnt + 13];
/* SOURCE exnmat.for:740 */
/*<       p=rdum >*/
	p = *rdum;
/* SOURCE exnmat.for:741 */
/*<       else >*/
    } else {
/*       LOOK UP VALUE IN TABLE BASED ON TIME AT START OF THE CURRENT */
/*       STEP */
/* SOURCE exnmat.for:745 */
/*<       calllktstab(iabs(opcode),jtime,p,ntab,dtime) >*/
	feq_gen_i_d_1 = abs(opcode);
	lktstab_(&feq_gen_i_d_1, jtime, &p, &ntab, &dtime);
/* SOURCE exnmat.for:748 */
/*<       if(p.lt.0.0.or.p.gt.1.0)then >*/
	if (p < (float)0. || p > (float)1.) {
/* SOURCE exnmat.for:749 */
/*<       write(stdout,50)get_tabid(ntab) >*/
	    feq_gen_io_d__100.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__100);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &ntab);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    e_wsfe();
/* SOURCE exnmat.for:750 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE exnmat.for:751 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:752 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:754 */
/*<       yl=ye2(unn) >*/
    yl = ye2[unn];
/* SOURCE exnmat.for:755 */
/*<       yr=ye2(dnn) >*/
    yr = ye2[dnn];
/* SOURCE exnmat.for:756 */
/*<       zl=ze(unn) >*/
    zl = ze[unn];
/* SOURCE exnmat.for:757 */
/*<       zr=ze(dnn) >*/
    zr = ze[dnn];
/*     FIND CURRENT ELEVATION FOR POINT OF HEAD MEASUREMENT */
/* SOURCE exnmat.for:761 */
/*<       calllktab(hptab,p,0,zw,ntab,dzw) >*/
    lktab_(&hptab, &p, &feq_gen_c_d_0, &zw, &ntab, &dzw);
/* SOURCE exnmat.for:765 */
/*<       gopen(ispout)=zw >*/
    gate1_1.gopen[ispout] = zw;
/*     ASSUME POSITIVE FLOW */
/* SOURCE exnmat.for:769 */
/*<       el=yl+zl >*/
    el = static_cast<double>(yl) + zl;
/* SOURCE exnmat.for:770 */
/*<       er=yr+zr >*/
    er = static_cast<double>(yr) + zr;
/* SOURCE exnmat.for:771 */
/*<       h=el-zw >*/
    feq_gen_h_d_ = static_cast<double>(el) - zw;
/* SOURCE exnmat.for:772 */
/*<       d=er-zw >*/
    feq_gen_d_d_ = static_cast<double>(er) - zw;
/* SOURCE exnmat.for:774 */
/*<       if(el.ge.er)then >*/
    if (el >= er) {
/*       FLOW FROM UPSTREAM NODE TO DOWNSTREAM NODE OR ZERO */
/* SOURCE exnmat.for:776 */
/*<       if(h.gt.0.0)then >*/
	if (feq_gen_h_d_ > (float)0.) {
/* SOURCE exnmat.for:777 */
/*<       calllktab(pctab,p,0,c,ntab,dc) >*/
	    lktab_(&pctab, &p, &feq_gen_c_d_0, &feq_gen_c_d_, &ntab, &dc);
/* SOURCE exnmat.for:780 */
/*<       if(ae2(unn).gt.0.0.and.alpha.gt.0.0)then >*/
	    if (ae2[unn] > (float)0. && alpha > (float)0.) {
/*           VELOCITY HEAD CAN BE COMPUTED */
/* SOURCE exnmat.for:783 */
/*<       vhead=0.5*alpha*(qe2(unn)/ae2(unn))**2/grav >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = static_cast<double>(qe2[unn]) / ae2[unn];
		vhead = static_cast<double>(static_cast<double>(static_cast<double>(alpha) * (float).5) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / *grav;
/* SOURCE exnmat.for:785 */
/*<       facq2=alpha*qe2(unn)/(grav*ae2(unn)**2) >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = ae2[unn];
		facq2 = static_cast<double>(static_cast<double>(alpha) * qe2[unn]) / (static_cast<double>(*grav) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1));
/* SOURCE exnmat.for:786 */
/*<       facq=1.0-alpha*qe2(unn)**2*te2(unn)/(grav*ae2(unn)**3) >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = qe2[unn];
/* Computing 3rd power */
		feq_gen_r_d_2 = ae2[unn];
		facq = static_cast<double>((float)1.) - static_cast<double>(static_cast<double>(static_cast<double>(alpha) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) * te2[unn]) / (static_cast<double>(*grav) *
			 (static_cast<double>(feq_gen_r_d_2) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)));
/* SOURCE exnmat.for:787 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:788 */
/*<       vhead=0.0 >*/
		vhead = (float)0.;
/* SOURCE exnmat.for:789 */
/*<       facq=1.0 >*/
		facq = (float)1.;
/* SOURCE exnmat.for:790 */
/*<       facq2=0.0 >*/
		facq2 = (float)0.;
/* SOURCE exnmat.for:791 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:793 */
/*<       th=h+vhead >*/
	    th = static_cast<double>(feq_gen_h_d_) + vhead;
/* SOURCE exnmat.for:795 */
/*<       fac=c*l*sqrt(th) >*/
	    fac = static_cast<double>(feq_gen_c_d_) * l * sqrt(th);
/* SOURCE exnmat.for:796 */
/*<       qf=fac*th >*/
	    qf = static_cast<double>(fac) * th;
/* SOURCE exnmat.for:797 */
/*<       if(d.gt.0.0)then >*/
	    if (feq_gen_d_d_ > (float)0.) {
/* SOURCE exnmat.for:798 */
/*<       arg=d/h >*/
		arg = static_cast<double>(feq_gen_d_d_) / feq_gen_h_d_;
/* SOURCE exnmat.for:799 */
/*<       calllktab(subtab,arg,0,cs,ntab,dcs) >*/
		lktab_(&subtab, &arg, &feq_gen_c_d_0, &cs, &ntab, &dcs);
/* SOURCE exnmat.for:802 */
/*<       fclass(ispout)='      SW' >*/
		s_copy(gate2_1.fclass + (ispout << 3), const_cast<char*>("      SW"), (ftnlen)8, 
			(ftnlen)8);
/* SOURCE exnmat.for:803 */
/*<       fclass_code(ispout)=1 >*/
		gate1_1.feq_gen_fclass_code_d_[ispout] = 1;
/* SOURCE exnmat.for:804 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:805 */
/*<       arg=0.0 >*/
		arg = (float)0.;
/* SOURCE exnmat.for:806 */
/*<       cs=1.0 >*/
		cs = (float)1.;
/* SOURCE exnmat.for:807 */
/*<       dcs=0.0 >*/
		dcs = (float)0.;
/* SOURCE exnmat.for:808 */
/*<       fclass(ispout)='      FW' >*/
		s_copy(gate2_1.fclass + (ispout << 3), const_cast<char*>("      FW"), (ftnlen)8, 
			(ftnlen)8);
/* SOURCE exnmat.for:809 */
/*<       fclass_code(ispout)=2 >*/
		gate1_1.feq_gen_fclass_code_d_[ispout] = 2;
/* SOURCE exnmat.for:810 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:812 */
/*<       pyr=qf*dcs/h >*/
	    *pyr = static_cast<double>(static_cast<double>(qf) * dcs) / feq_gen_h_d_;
/* SOURCE exnmat.for:813 */
/*<       disch=qf*cs >*/
	    disch = static_cast<double>(qf) * cs;
/* SOURCE exnmat.for:814 */
/*<       pyl=1.5*fac*facq*cs-pyr*arg >*/
	    *pyl = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(fac) * (float)1.5) * facq) * cs) - static_cast<double>(*pyr) * arg;
/* SOURCE exnmat.for:815 */
/*<       pql=1.5*fac*facq2 >*/
	    *pql = static_cast<double>(static_cast<double>(fac) * (float)1.5) * facq2;
/* SOURCE exnmat.for:816 */
/*<       pqr=0.0 >*/
	    *pqr = (float)0.;
/* SOURCE exnmat.for:817 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:818 */
/*<       disch=0.0 >*/
	    disch = (float)0.;
/* SOURCE exnmat.for:819 */
/*<       pyl=0.0 >*/
	    *pyl = (float)0.;
/* SOURCE exnmat.for:820 */
/*<       pql=0.0 >*/
	    *pql = (float)0.;
/* SOURCE exnmat.for:821 */
/*<       pyr=0.0 >*/
	    *pyr = (float)0.;
/* SOURCE exnmat.for:822 */
/*<       pqr=0.0 >*/
	    *pqr = (float)0.;
/* SOURCE exnmat.for:823 */
/*<       fclass(ispout)=' NO FLOW' >*/
	    s_copy(gate2_1.fclass + (ispout << 3), const_cast<char*>(" NO FLOW"), (ftnlen)8, (
		    ftnlen)8);
/* SOURCE exnmat.for:824 */
/*<       fclass_code(ispout)=3 >*/
	    gate1_1.feq_gen_fclass_code_d_[ispout] = 3;
/* SOURCE exnmat.for:825 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:826 */
/*<       else >*/
    } else {
/*       FLOW FROM DOWN STREAM NODE TO UPSTREAM NODE */
/* SOURCE exnmat.for:829 */
/*<       t=h >*/
	t = feq_gen_h_d_;
/* SOURCE exnmat.for:830 */
/*<       h=d >*/
	feq_gen_h_d_ = feq_gen_d_d_;
/* SOURCE exnmat.for:831 */
/*<       d=t >*/
	feq_gen_d_d_ = t;
/* SOURCE exnmat.for:832 */
/*<       if(h.gt.0.0)then >*/
	if (feq_gen_h_d_ > (float)0.) {
/* SOURCE exnmat.for:833 */
/*<       calllktab(nctab,p,0,c,ntab,cd) >*/
	    lktab_(&nctab, &p, &feq_gen_c_d_0, &feq_gen_c_d_, &ntab, &cd);
/* SOURCE exnmat.for:836 */
/*<       if(ae2(dnn).gt.0.0.and.alpha.gt.0.0)then >*/
	    if (ae2[dnn] > (float)0. && alpha > (float)0.) {
/*           VELOCITY HEAD CAN BE COMPUTED */
/* SOURCE exnmat.for:839 */
/*<       vhead=0.5*alpha*(qe2(dnn)/ae2(dnn))**2/grav >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = static_cast<double>(qe2[dnn]) / ae2[dnn];
		vhead = static_cast<double>(static_cast<double>(static_cast<double>(alpha) * (float).5) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / *grav;
/* SOURCE exnmat.for:841 */
/*<       facq2=alpha*qe2(dnn)/(grav*ae2(dnn)**2) >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = ae2[dnn];
		facq2 = static_cast<double>(static_cast<double>(alpha) * qe2[dnn]) / (static_cast<double>(*grav) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1));
/* SOURCE exnmat.for:842 */
/*<       facq=1.0-alpha*qe2(dnn)**2*te2(dnn)/(grav*ae2(dnn)**3) >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = qe2[dnn];
/* Computing 3rd power */
		feq_gen_r_d_2 = ae2[dnn];
		facq = static_cast<double>((float)1.) - static_cast<double>(static_cast<double>(static_cast<double>(alpha) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) * te2[dnn]) / (static_cast<double>(*grav) *
			 (static_cast<double>(feq_gen_r_d_2) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)));
/* SOURCE exnmat.for:843 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:844 */
/*<       vhead=0.0 >*/
		vhead = (float)0.;
/* SOURCE exnmat.for:845 */
/*<       facq=1.0 >*/
		facq = (float)1.;
/* SOURCE exnmat.for:846 */
/*<       facq2=0.0 >*/
		facq2 = (float)0.;
/* SOURCE exnmat.for:847 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:849 */
/*<       th=h+vhead >*/
	    th = static_cast<double>(feq_gen_h_d_) + vhead;
/* SOURCE exnmat.for:851 */
/*<       fac=c*l*sqrt(th) >*/
	    fac = static_cast<double>(feq_gen_c_d_) * l * sqrt(th);
/* SOURCE exnmat.for:852 */
/*<       qf=fac*th >*/
	    qf = static_cast<double>(fac) * th;
/* SOURCE exnmat.for:853 */
/*<       if(d.gt.0.0)then >*/
	    if (feq_gen_d_d_ > (float)0.) {
/* SOURCE exnmat.for:854 */
/*<       arg=d/h >*/
		arg = static_cast<double>(feq_gen_d_d_) / feq_gen_h_d_;
/* SOURCE exnmat.for:855 */
/*<       calllktab(subtab,arg,0,cs,ntab,dcs) >*/
		lktab_(&subtab, &arg, &feq_gen_c_d_0, &cs, &ntab, &dcs);
/* SOURCE exnmat.for:858 */
/*<       fclass(ispout)='      SW' >*/
		s_copy(gate2_1.fclass + (ispout << 3), const_cast<char*>("      SW"), (ftnlen)8, 
			(ftnlen)8);
/* SOURCE exnmat.for:859 */
/*<       fclass_code(ispout)=1 >*/
		gate1_1.feq_gen_fclass_code_d_[ispout] = 1;
/* SOURCE exnmat.for:860 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:861 */
/*<       arg=0.0 >*/
		arg = (float)0.;
/* SOURCE exnmat.for:862 */
/*<       cs=1.0 >*/
		cs = (float)1.;
/* SOURCE exnmat.for:863 */
/*<       dcs=0.0 >*/
		dcs = (float)0.;
/* SOURCE exnmat.for:864 */
/*<       fclass(ispout)='      FW' >*/
		s_copy(gate2_1.fclass + (ispout << 3), const_cast<char*>("      FW"), (ftnlen)8, 
			(ftnlen)8);
/* SOURCE exnmat.for:865 */
/*<       fclass_code(ispout)=2 >*/
		gate1_1.feq_gen_fclass_code_d_[ispout] = 2;
/* SOURCE exnmat.for:866 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:868 */
/*<       pyl=qf*dcs/h >*/
	    *pyl = static_cast<double>(static_cast<double>(qf) * dcs) / feq_gen_h_d_;
/* SOURCE exnmat.for:869 */
/*<       disch=-qf*cs >*/
	    disch = static_cast<double>(-qf) * cs;
/* SOURCE exnmat.for:870 */
/*<       pyr=-(1.5*fac*facq*cs-pyl*arg) >*/
	    *pyr = -(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(fac) * (float)1.5) * facq) * cs) - static_cast<double>(*pyl) * arg);
/* SOURCE exnmat.for:871 */
/*<       pyl=-pyl >*/
	    *pyl = -(*pyl);
/* SOURCE exnmat.for:872 */
/*<       pqr=-1.5*fac*facq2 >*/
	    *pqr = static_cast<double>(static_cast<double>(fac) * (float)-1.5) * facq2;
/* SOURCE exnmat.for:873 */
/*<       pql=0.0 >*/
	    *pql = (float)0.;
/* SOURCE exnmat.for:874 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:875 */
/*<       disch=0.0 >*/
	    disch = (float)0.;
/* SOURCE exnmat.for:876 */
/*<       pyl=0.0 >*/
	    *pyl = (float)0.;
/* SOURCE exnmat.for:877 */
/*<       pql=0.0 >*/
	    *pql = (float)0.;
/* SOURCE exnmat.for:878 */
/*<       pyr=0.0 >*/
	    *pyr = (float)0.;
/* SOURCE exnmat.for:879 */
/*<       pqr=0.0 >*/
	    *pqr = (float)0.;
/* SOURCE exnmat.for:880 */
/*<       fclass(ispout)=' NO FLOW' >*/
	    s_copy(gate2_1.fclass + (ispout << 3), const_cast<char*>(" NO FLOW"), (ftnlen)8, (
		    ftnlen)8);
/* SOURCE exnmat.for:881 */
/*<       fclass_code(ispout)=3 >*/
	    gate1_1.feq_gen_fclass_code_d_[ispout] = 3;
/* SOURCE exnmat.for:882 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:883 */
/*<       endif >*/
    }
/*     APPLY EFFECT OF SYSGN VALUES */
/* SOURCE exnmat.for:887 */
/*<       if(sysgn.lt.0.0)then >*/
    if ((real) sysgn < (float)0.) {
/* SOURCE exnmat.for:888 */
/*<       disch=-disch >*/
	disch = -disch;
/* SOURCE exnmat.for:889 */
/*<       pyl=-pyl >*/
	*pyl = -(*pyl);
/* SOURCE exnmat.for:890 */
/*<       pyr=-pyr >*/
	*pyr = -(*pyr);
/* SOURCE exnmat.for:891 */
/*<       pql=-pql >*/
	*pql = -(*pql);
/* SOURCE exnmat.for:892 */
/*<       pqr=-pqr >*/
	*pqr = -(*pqr);
/* SOURCE exnmat.for:893 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:895 */
/*<       res=qe2(qnn)-disch >*/
    *res = static_cast<double>(qe2[qnn]) - disch;
/*     CHANGE SIGNS TO REFLECT Y AND Q DERIVATIVES OF DISCH.  WE */
/*     HAVE HERETOFOR TAKEN THE SIGN ON DISCH TO BE + */
/* SOURCE exnmat.for:900 */
/*<       pyl=-pyl >*/
    *pyl = -(*pyl);
/* SOURCE exnmat.for:901 */
/*<       pql=-pql >*/
    *pql = -(*pql);
/* SOURCE exnmat.for:902 */
/*<       pyr=-pyr >*/
    *pyr = -(*pyr);
/* SOURCE exnmat.for:903 */
/*<       pqr=-pqr >*/
    *pqr = -(*pqr);
/*     SET THE FLOW DERIVATIVES */
/* SOURCE exnmat.for:906 */
/*<       if(qnn.eq.unn)then >*/
    if (qnn == unn) {
/* SOURCE exnmat.for:907 */
/*<       pql=pql+1.0 >*/
	*pql += static_cast<double>((float)1.);
/* SOURCE exnmat.for:908 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:909 */
/*<       pqr=pqr+1.0 >*/
	*pqr += static_cast<double>((float)1.);
/* SOURCE exnmat.for:910 */
/*<       endif >*/
    }
/*        WRITE(STDOUT,*) 'BDFWR: RES=',RES */
/*        WRITE(STDOUT,*) ' DERV:',PYL, PQL, PYR, PQR */
/*        WRITE(STDOUT,*) 'EL=',EL,' ER=',ER */
/*        WRITE(STDOUT,*) ' QE2(QNN)=',QE2(QNN) */
/* SOURCE exnmat.for:917 */
/*<       return >*/
    return 0;
/* SOURCE exnmat.for:918 */
/*<       end >*/
} /* bdfwr_ */

#undef rdum
#undef idum





/* SOURCE exnmat.for:922 */
/*<        >*/
/* Subroutine */ int cbflow_(real *yu, real *zu, real *tu, real *au, real *bu,
	 real *dbu, real *qu, real *hu, real *yd, real *zd, real *td, real *
	ad, real *bd, real *dbd, real *qd, real *hd, real *hslot, real *res, 
	real *pyl, real *pql, real *pyr, real *pqr)
{
    /* System generated locals */
    real feq_gen_r_d_1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    real k, feq_gen_r_d_, dh, dk, qb, vd, qr, vu, fac, ked, dht, div, keu, qbt, dked, 
	    dkeu, dqbt, pedqd, pedyd, pqbqd, pqbyd, pqbqu, peuqu, pqbyu, 
	    pqryd, peuyu, pqrqu, pqryu, comfac;

/*     + + + PURPOSE + + + */
/*     Compute values for flow through a bridge opening */
/*     and over the roadway. */
/* SOURCE exnmat.for:931 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:933 */
/*<        >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     YU     - depth at upstream section */
/*     ZU     - bottom elevation at upstream section */
/*     TU     - top width at the upstream section */
/*     AU     - area in channel upstream of the bridge */
/*     BU     - momentum flux coefficient at upstream section */
/*     DBU    - derivative wrt depth of upstream momentum flux coef */
/*     QU     - flow at upstream section */
/*     HU     - head at upstream node */
/*     YD     - depth at downstream section */
/*     ZD     - bottom elevation at downstream section */
/*     TD     - top width at downstream section */
/*     AD     - Flow area in channel downstream of bridge opening. */
/*     BD     - momentum flux correction coefficient in downstream */
/*               section */
/*     DBD    - derivative wrt depth of downstream momentum flux coef */
/*     QD     - flow at downstream section */
/*     HD     - head downstream */
/*     HSLOT  - height of bottom slot.  Currently 0.0 always */
/*     RES    - value of the residual function */
/*     PYL    - partial derivative of residual function wrt depth at */
/*               left node */
/*     PQL    - partial derivative of residual function wrt flow at left */
/*               node */
/*     PYR    - partial derivative of residual function wrt depth at */
/*               right node */
/*     PQR    - partial derivative of residual function wrt flow at right */
/*               node */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE exnmat.for:966 */
/*     Common for subroutine CBFLOW */
/* SOURCE cbcom.cmn:3 */
/*<       integersgn >*/
/* SOURCE cbcom.cmn:5 */
/*<       realybmax,ksub,kfree,dkfree,tb,ab,maxab,qrf,dqrf,sbc,dsbc,hr,hs >*/
/* SOURCE cbcom.cmn:7 */
/*<        >*/
/* INCLUDE exnmat.for:967 */
/* ********************************************************************** */
/* SOURCE grav.cmn:2 */
/*<       realgrav,twog,halfg >*/
/* SOURCE grav.cmn:4 */
/*<       common/gravcm/grav,twog,halfg >*/
/* SOURCE grav.cmn:5 */
/*<       save/gravcm/ >*/
/* ********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE exnmat.for:970 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE exnmat.for:975 */
/*<       intrinsicsqrt >*/
/* *********************************************************************** */
/*   COMPUTE ALPHA FROM BETA VALUES */
/* SOURCE exnmat.for:979 */
/*<       keu=1.+2.884*(bu-1.) >*/
    keu = static_cast<double>(static_cast<double>((static_cast<double>(*bu) - (float)1.)) * (float)2.884) + (float)1.;
/* SOURCE exnmat.for:980 */
/*<       dkeu=2.884*dbu >*/
    dkeu = static_cast<double>(*dbu) * (float)2.884;
/* SOURCE exnmat.for:982 */
/*<       ked=1.+2.884*(bd-1.) >*/
    ked = static_cast<double>(static_cast<double>((static_cast<double>(*bd) - (float)1.)) * (float)2.884) + (float)1.;
/* SOURCE exnmat.for:983 */
/*<       dked=2.884*dbd >*/
    dked = static_cast<double>(*dbd) * (float)2.884;
/*   COMPUTE ROADWAY FLOW AND ITS DERIVATIVES */
/* SOURCE exnmat.for:987 */
/*<       qr=qrf*sbc >*/
    qr = static_cast<double>(cb_1.qrf) * cb_1.sbc;
/* SOURCE exnmat.for:988 */
/*<       vu=qu/au >*/
    vu = static_cast<double>(*qu) / *au;
/* SOURCE exnmat.for:989 */
/*<       peuyu=1.0+vu*vu*(dkeu/2.-keu*tu/au)/grav >*/
    peuyu = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(vu) * vu) * (static_cast<double>(static_cast<double>(dkeu) / (float)2.) - static_cast<double>(static_cast<double>(keu) * *tu) / *au)) / gravcm_1.grav) + (
	    float)1.;
/* SOURCE exnmat.for:990 */
/*<       peuqu=keu*qu/(grav*au*au) >*/
    peuqu = static_cast<double>(static_cast<double>(keu) * *qu) / (static_cast<double>(static_cast<double>(gravcm_1.grav) * *au) * *au);
/* SOURCE exnmat.for:991 */
/*<       if(hr.gt.0.0)goto20 >*/
    if (cb_1.hr > (float)0.) {
	goto L20;
    }
/*   ROADWAY FLOW IS ZERO HERE. */
/* SOURCE exnmat.for:995 */
/*<       pqryu=0. >*/
    pqryu = (float)0.;
/* SOURCE exnmat.for:996 */
/*<       pqryd=0. >*/
    pqryd = (float)0.;
/* SOURCE exnmat.for:997 */
/*<       pqrqu=0. >*/
    pqrqu = (float)0.;
/* SOURCE exnmat.for:998 */
/*<       goto40 >*/
    goto L40;
/* SOURCE exnmat.for:999 */
/*<    20 continue >*/
L20:
/*   ROADWAY FLOW NON-ZERO HERE */
/* SOURCE exnmat.for:1003 */
/*<       comfac=dqrf*sbc-hs*qrf*dsbc/hr**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = cb_1.hr;
    comfac = static_cast<double>(static_cast<double>(cb_1.dqrf) * cb_1.sbc) - static_cast<double>(static_cast<double>(static_cast<double>(cb_1.hs) * cb_1.qrf) * cb_1.dsbc) / (static_cast<double>(feq_gen_r_d_1) * 
	    feq_gen_r_d_1);
/* SOURCE exnmat.for:1004 */
/*<       pqryu=comfac >*/
    pqryu = comfac;
/* SOURCE exnmat.for:1005 */
/*<       pqryd=dsbc*qrf/hr >*/
    pqryd = static_cast<double>(static_cast<double>(cb_1.dsbc) * cb_1.qrf) / cb_1.hr;
/*     PQRQU = PEUQU*COMFAC */
/* SOURCE exnmat.for:1007 */
/*<       pqrqu=0.0 >*/
    pqrqu = (float)0.;
/* SOURCE exnmat.for:1008 */
/*<    40 continue >*/
L40:
/*   ADJUST SIGN OF QR AND ITS DERIVATIVES */
/* SOURCE exnmat.for:1012 */
/*<       if(sgn.gt.0)goto50 >*/
    if (cb_1.sgn > 0) {
	goto L50;
    }
/* SOURCE exnmat.for:1013 */
/*<       qr=-qr >*/
    qr = -qr;
/* SOURCE exnmat.for:1014 */
/*<       pqryu=-pqryu >*/
    pqryu = -pqryu;
/* SOURCE exnmat.for:1015 */
/*<       pqryd=-pqryd >*/
    pqryd = -pqryd;
/* SOURCE exnmat.for:1016 */
/*<       pqrqu=-pqrqu >*/
    pqrqu = -pqrqu;
/* SOURCE exnmat.for:1017 */
/*<    50 continue >*/
L50:
/* SOURCE exnmat.for:1020 */
/*<       r=(yu-hslot)/(ybmax-hslot) >*/
    feq_gen_r_d_ = static_cast<double>((static_cast<double>(*yu) - *hslot)) / (static_cast<double>(cb_1.ybmax) - *hslot);
/* SOURCE exnmat.for:1021 */
/*<       if(r.gt.1.05)goto100 >*/
    if (feq_gen_r_d_ > (float)1.05) {
	goto L100;
    }
/*   FREE FLOW THROUGH BRIDGE OPENING HERE */
/* SOURCE exnmat.for:1025 */
/*<       if(kfree.gt.0.005)goto52 >*/
    if (cb_1.kfree > (float).005) {
	goto L52;
    }
/* SOURCE exnmat.for:1026 */
/*<       k=0.005 >*/
    k = (float).005;
/* SOURCE exnmat.for:1027 */
/*<       dk=0.0 >*/
    dk = (float)0.;
/* SOURCE exnmat.for:1028 */
/*<       goto54 >*/
    goto L54;
/* SOURCE exnmat.for:1029 */
/*<    52 continue >*/
L52:
/* SOURCE exnmat.for:1030 */
/*<       k=kfree >*/
    k = cb_1.kfree;
/* SOURCE exnmat.for:1031 */
/*<       dk=dkfree >*/
    dk = cb_1.dkfree;
/* SOURCE exnmat.for:1032 */
/*<    54 continue >*/
L54:
/* SOURCE exnmat.for:1034 */
/*<       vd=qd/ad >*/
    vd = static_cast<double>(*qd) / *ad;
/* SOURCE exnmat.for:1035 */
/*<       pedyd=1.0+vd*vd*(dked/2.-ked*td/ad)/grav >*/
    pedyd = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(vd) * vd) * (static_cast<double>(static_cast<double>(dked) / (float)2.) - static_cast<double>(static_cast<double>(ked) * *td) / *ad)) / gravcm_1.grav) + (
	    float)1.;
/* SOURCE exnmat.for:1036 */
/*<       pedqd=ked*qd/(grav*ad*ad) >*/
    pedqd = static_cast<double>(static_cast<double>(ked) * *qd) / (static_cast<double>(static_cast<double>(gravcm_1.grav) * *ad) * *ad);
/* SOURCE exnmat.for:1037 */
/*<       fac=ab*ab/k >*/
    fac = static_cast<double>(static_cast<double>(cb_1.ab) * cb_1.ab) / k;
/* SOURCE exnmat.for:1038 */
/*<       dh=hu-hd >*/
    dh = static_cast<double>(*hu) - *hd;
/* SOURCE exnmat.for:1039 */
/*<       dht=0.02 >*/
    dht = (float).02;
/* SOURCE exnmat.for:1040 */
/*<       if(dh.lt.dht)goto60 >*/
    if (dh < dht) {
	goto L60;
    }
/* SOURCE exnmat.for:1041 */
/*<       qb=sqrt(twog*fac*dh) >*/
    qb = sqrt(static_cast<double>(static_cast<double>(gravcm_1.twog) * fac) * dh);
/* SOURCE exnmat.for:1042 */
/*<       div=qb >*/
    div = qb;
/* SOURCE exnmat.for:1043 */
/*<       if(div.lt.0.25)div=0.25 >*/
    if (div < (float).25) {
	div = (float).25;
    }
/* SOURCE exnmat.for:1044 */
/*<       qb=div >*/
    qb = div;
/* SOURCE exnmat.for:1045 */
/*<       pqbyu=grav*fac*peuyu/div >*/
    pqbyu = static_cast<double>(static_cast<double>(static_cast<double>(gravcm_1.grav) * fac) * peuyu) / div;
/* SOURCE exnmat.for:1046 */
/*<       pqbyd=grav*fac*((hu-hd)*(2.*tb/ab-dk/k)-pedyd)/div >*/
    pqbyd = static_cast<double>(static_cast<double>(static_cast<double>(gravcm_1.grav) * fac) * (static_cast<double>(static_cast<double>((static_cast<double>(*hu) - *hd)) * (static_cast<double>(static_cast<double>(static_cast<double>(cb_1.tb) * (float)2.) / 
	    cb_1.ab) - static_cast<double>(dk) / k)) - pedyd)) / div;
/* SOURCE exnmat.for:1047 */
/*<       pqbqu=grav*fac*peuqu/div >*/
    pqbqu = static_cast<double>(static_cast<double>(static_cast<double>(gravcm_1.grav) * fac) * peuqu) / div;
/* SOURCE exnmat.for:1049 */
/*<       pqbqd=-grav*fac*pedqd/div >*/
    pqbqd = static_cast<double>(static_cast<double>(static_cast<double>(-gravcm_1.grav) * fac) * pedqd) / div;
/* SOURCE exnmat.for:1050 */
/*<       goto65 >*/
    goto L65;
/* SOURCE exnmat.for:1051 */
/*<    60 continue >*/
L60:
/* SOURCE exnmat.for:1052 */
/*<       qbt=sqrt(twog*fac*dht) >*/
    qbt = sqrt(static_cast<double>(static_cast<double>(gravcm_1.twog) * fac) * dht);
/* SOURCE exnmat.for:1053 */
/*<       dqbt=qbt/dht >*/
    dqbt = static_cast<double>(qbt) / dht;
/* SOURCE exnmat.for:1054 */
/*<       qb=dh*dqbt >*/
    qb = static_cast<double>(dh) * dqbt;
/* SOURCE exnmat.for:1055 */
/*<       pqbyu=dqbt*peuyu >*/
    pqbyu = static_cast<double>(dqbt) * peuyu;
/* SOURCE exnmat.for:1056 */
/*<       pqbyd=-dqbt*(pedyd-dh*tb/ab+0.5*dh*dk/k) >*/
    pqbyd = static_cast<double>(-dqbt) * (static_cast<double>(static_cast<double>(pedyd) - static_cast<double>(static_cast<double>(dh) * cb_1.tb) / cb_1.ab) + static_cast<double>(static_cast<double>(static_cast<double>(dh) * (float).5) * dk) / k)
	    ;
/* SOURCE exnmat.for:1057 */
/*<       pqbqu=dqbt*peuqu >*/
    pqbqu = static_cast<double>(dqbt) * peuqu;
/* SOURCE exnmat.for:1060 */
/*<       pqbqd=-dqbt*pedqd >*/
    pqbqd = static_cast<double>(-dqbt) * pedqd;
/* SOURCE exnmat.for:1061 */
/*<    65 continue >*/
L65:
/*     ADJUST SIGNS */
/* SOURCE exnmat.for:1065 */
/*<       if(sgn.gt.0)goto75 >*/
    if (cb_1.sgn > 0) {
	goto L75;
    }
/* SOURCE exnmat.for:1066 */
/*<       qb=-qb >*/
    qb = -qb;
/* SOURCE exnmat.for:1067 */
/*<       pqbyu=-pqbyu >*/
    pqbyu = -pqbyu;
/* SOURCE exnmat.for:1068 */
/*<       pqbyd=-pqbyd >*/
    pqbyd = -pqbyd;
/* SOURCE exnmat.for:1069 */
/*<       pqbqu=-pqbqu >*/
    pqbqu = -pqbqu;
/* SOURCE exnmat.for:1070 */
/*<       pqbqd=-pqbqd >*/
    pqbqd = -pqbqd;
/* SOURCE exnmat.for:1071 */
/*<    75 continue >*/
L75:
/* SOURCE exnmat.for:1073 */
/*<       res=qd-qb-qr >*/
    *res = static_cast<double>(static_cast<double>(*qd) - qb) - qr;
/* SOURCE exnmat.for:1074 */
/*<       pyl=-(pqbyu+pqryu) >*/
    *pyl = -(static_cast<double>(pqbyu) + pqryu);
/* SOURCE exnmat.for:1075 */
/*<       pyr=-(pqbyd+pqryd) >*/
    *pyr = -(static_cast<double>(pqbyd) + pqryd);
/* SOURCE exnmat.for:1076 */
/*<       pql=-(pqbqu+pqrqu) >*/
    *pql = -(static_cast<double>(pqbqu) + pqrqu);
/* SOURCE exnmat.for:1077 */
/*<       pqr=1.0-pqbqd >*/
    *pqr = static_cast<double>((float)1.) - pqbqd;
/* SOURCE exnmat.for:1079 */
/*<       return >*/
    return 0;
/* SOURCE exnmat.for:1083 */
/*<   100 continue >*/
L100:
/* SOURCE exnmat.for:1084 */
/*<       ab=maxab >*/
    cb_1.ab = cb_1.maxab;
/* SOURCE exnmat.for:1085 */
/*<       if(yd.ge.0.0)goto200 >*/
    if (*yd >= (float)0.) {
	goto L200;
    }
/*   ONLY TWO CASES OF BRIDGE FLOW TREATED */
/*   ONLY UPSTREAM END SUBMERGED */
/* SOURCE exnmat.for:1090 */
/*<       k=0.19+0.2*r >*/
    k = static_cast<double>(static_cast<double>(feq_gen_r_d_) * (float).2) + (float).19;
/* SOURCE exnmat.for:1091 */
/*<       dk=0.2/ybmax >*/
    dk = static_cast<double>((float).2) / cb_1.ybmax;
/* SOURCE exnmat.for:1092 */
/*<       comfac=hu-(zu-yu)-0.5*ybmax >*/
    comfac = static_cast<double>(static_cast<double>(*hu) - (static_cast<double>(*zu) - *yu)) - static_cast<double>(cb_1.ybmax) * (float).5;
/* SOURCE exnmat.for:1093 */
/*<       qb=k*ab*sqrt(twog*comfac) >*/
    qb = static_cast<double>(k) * cb_1.ab * sqrt(static_cast<double>(gravcm_1.twog) * comfac);
/* SOURCE exnmat.for:1094 */
/*<       pqbyu=grav*ab*ab*(2.*k*dk*comfac+k*k*peuyu)/qb >*/
    pqbyu = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(gravcm_1.grav) * cb_1.ab) * cb_1.ab) * (static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(k) * (float)2.) * dk) * comfac) 
	    + static_cast<double>(static_cast<double>(k) * k) * peuyu)) / qb;
/* SOURCE exnmat.for:1095 */
/*<       pqbqu=grav*ab*ab*k*k*peuqu/qb >*/
    pqbqu = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(gravcm_1.grav) * cb_1.ab) * cb_1.ab) * k) * k) * peuqu) / qb;
/*   ADJUST SIGNS */
/* SOURCE exnmat.for:1099 */
/*<       if(sgn.gt.0)goto150 >*/
    if (cb_1.sgn > 0) {
	goto L150;
    }
/* SOURCE exnmat.for:1100 */
/*<       qb=-qb >*/
    qb = -qb;
/* SOURCE exnmat.for:1101 */
/*<       pqbyu=-pqbyu >*/
    pqbyu = -pqbyu;
/* SOURCE exnmat.for:1102 */
/*<       pqbqu=-pqbqu >*/
    pqbqu = -pqbqu;
/* SOURCE exnmat.for:1103 */
/*<   150 continue >*/
L150:
/* SOURCE exnmat.for:1104 */
/*<       res=qu-qb-qr >*/
    *res = static_cast<double>(static_cast<double>(*qu) - qb) - qr;
/* SOURCE exnmat.for:1105 */
/*<       pyl=-(pqbyu+pqryu) >*/
    *pyl = -(static_cast<double>(pqbyu) + pqryu);
/* SOURCE exnmat.for:1106 */
/*<       pyr=-pqryd >*/
    *pyr = -pqryd;
/* SOURCE exnmat.for:1107 */
/*<       pql=1.0-(pqbqu+pqrqu) >*/
    *pql = static_cast<double>((float)1.) - (static_cast<double>(pqbqu) + pqrqu);
/* SOURCE exnmat.for:1108 */
/*<       pqr=0.0 >*/
    *pqr = (float)0.;
/* SOURCE exnmat.for:1109 */
/*<       return >*/
    return 0;
/* SOURCE exnmat.for:1110 */
/*<   200 continue >*/
L200:
/*   SUBMERGED UPSTREAM AND DOWNSTEAM */
/* SOURCE exnmat.for:1114 */
/*<       k=ksub >*/
    k = cb_1.ksub;
/* SOURCE exnmat.for:1115 */
/*<       dh=hu-zd >*/
    dh = static_cast<double>(*hu) - *zd;
/* SOURCE exnmat.for:1116 */
/*<       dht=0.02 >*/
    dht = (float).02;
/* SOURCE exnmat.for:1117 */
/*<       if(dh.lt.dht)goto210 >*/
    if (dh < dht) {
	goto L210;
    }
/* SOURCE exnmat.for:1118 */
/*<       qb=k*ab*sqrt(twog*(hu-zd)) >*/
    qb = static_cast<double>(k) * cb_1.ab * sqrt(static_cast<double>(gravcm_1.twog) * (static_cast<double>(*hu) - *zd));
/* SOURCE exnmat.for:1119 */
/*<       comfac=grav*k*k*ab*ab/qb >*/
    comfac = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(gravcm_1.grav) * k) * k) * cb_1.ab) * cb_1.ab) / qb;
/* SOURCE exnmat.for:1120 */
/*<       pqbyu=comfac*peuyu >*/
    pqbyu = static_cast<double>(comfac) * peuyu;
/* SOURCE exnmat.for:1121 */
/*<       pqbyd=-comfac >*/
    pqbyd = -comfac;
/* SOURCE exnmat.for:1122 */
/*<       pqbqu=comfac*peuqu >*/
    pqbqu = static_cast<double>(comfac) * peuqu;
/* SOURCE exnmat.for:1123 */
/*<       goto220 >*/
    goto L220;
/* SOURCE exnmat.for:1124 */
/*<   210 continue >*/
L210:
/* SOURCE exnmat.for:1125 */
/*<       qbt=k*ab*sqrt(twog*dht) >*/
    qbt = static_cast<double>(k) * cb_1.ab * sqrt(static_cast<double>(gravcm_1.twog) * dht);
/* SOURCE exnmat.for:1126 */
/*<       dqbt=qbt/dht >*/
    dqbt = static_cast<double>(qbt) / dht;
/* SOURCE exnmat.for:1127 */
/*<       qb=dh*dqbt >*/
    qb = static_cast<double>(dh) * dqbt;
/* SOURCE exnmat.for:1128 */
/*<       pqbyu=dqbt*peuyu >*/
    pqbyu = static_cast<double>(dqbt) * peuyu;
/* SOURCE exnmat.for:1129 */
/*<       pqbyd=-dqbt >*/
    pqbyd = -dqbt;
/* SOURCE exnmat.for:1130 */
/*<       pqbqu=dqbt*peuqu >*/
    pqbqu = static_cast<double>(dqbt) * peuqu;
/* SOURCE exnmat.for:1131 */
/*<   220 continue >*/
L220:
/* SOURCE exnmat.for:1132 */
/*<       if(sgn.gt.0)goto250 >*/
    if (cb_1.sgn > 0) {
	goto L250;
    }
/* SOURCE exnmat.for:1133 */
/*<       qb=-qb >*/
    qb = -qb;
/* SOURCE exnmat.for:1134 */
/*<       pqbyu=-pqbyu >*/
    pqbyu = -pqbyu;
/* SOURCE exnmat.for:1135 */
/*<       pqbyd=-pqbyd >*/
    pqbyd = -pqbyd;
/* SOURCE exnmat.for:1136 */
/*<       pqbqu=-pqbqu >*/
    pqbqu = -pqbqu;
/* SOURCE exnmat.for:1137 */
/*<   250 continue >*/
L250:
/* SOURCE exnmat.for:1138 */
/*<       res=qd-qb-qr >*/
    *res = static_cast<double>(static_cast<double>(*qd) - qb) - qr;
/* SOURCE exnmat.for:1139 */
/*<       pyl=-(pqbyu+pqryu) >*/
    *pyl = -(static_cast<double>(pqbyu) + pqryu);
/* SOURCE exnmat.for:1140 */
/*<       pyr=-(pqbyd+pqryd) >*/
    *pyr = -(static_cast<double>(pqbyd) + pqryd);
/* SOURCE exnmat.for:1141 */
/*<       pql=-(pqbqu+pqrqu) >*/
    *pql = -(static_cast<double>(pqbqu) + pqrqu);
/* SOURCE exnmat.for:1142 */
/*<       pqr=1.0 >*/
    *pqr = (float)1.;
/* SOURCE exnmat.for:1143 */
/*<       return >*/
    return 0;
/* SOURCE exnmat.for:1144 */
/*<       end >*/
} /* cbflow_ */




/* SOURCE exnmat.for:1148 */
/*<        >*/
/* Subroutine */ int cbrid_(integer *ipnt, real *grav, integer *stdout, 
	integer *nex, integer *mlemc, integer *feq_storage_emc, integer *feq_storage_exnodt, real *
	feq_storage_qe2, real *feq_storage_ye2, real *feq_storage_ze, real *hslot, real *res, real *pyl, real *
	pql, real *pyr, real *pqr)
{
    /* Format strings */
    static char fmt_49[] = "(/\002 UNN= \002,a5,\002 DNN= \002,a5)";
    static char fmt_50[] = "(\002 *ERR:80* INVALID ROADWAY FLOW. ZU=\002,f8.\
3,\002 ZD=\002,f8.3,\002 RDELEV=\002,f8.3,\002 RS=\002,f7.3)";
    static char fmt_51[] = "(\002 YU=\002,f7.3,\002 YD=\002,f7.3)";

    /* System generated locals */
    real feq_gen_r_d_1;
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5], feq_gen_ch_d_3[5], feq_gen_ch_d_4[5];
    static real equiv_2[1];

    /* Builtin functions */
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    real b, ad, bd, db, hd, qd, au, bu, td, yb, hu, yd, zd;
    integer nt;
    real rs, qu, tu, yu, zu, dbd, ked;
    integer adr;
    real dtb, dbu, dtd;
    integer dnn;
    real con, keu, dtu;
    integer unn;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    real dcon;
    integer ntab, ptab, fsgn;
#define idum (feq::BitView<integer>(equiv_2, sizeof(equiv_2)))
#define rdum (equiv_2)
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    integer batab;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *), xlkt20_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *);
    integer sysgn, sbctab, nrftab, prftab;
    real rdelev;
    extern /* Subroutine */ int cbflow_(real *, real *, real *, real *, real *
	    , real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *);
    real maxelv;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);
    real trybmx;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__201 = { 0, 0, 0, fmt_49, 0 };
    static cilist feq_gen_io_d__202 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__203 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__204 = { 0, 0, 0, fmt_49, 0 };
    static cilist feq_gen_io_d__205 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__206 = { 0, 0, 0, fmt_51, 0 };


/*     + + + PURPOSE + + + */
/*     Subroutine to compute required values for bridge flow. */
/*     Assumed: 1) flow is always subcritical in the bridge opening */
/*              2) flow may take place over the roadway */
/* SOURCE exnmat.for:1158 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:1160 */
/*<       integeripnt,stdout,mlemc,nex >*/
/* SOURCE exnmat.for:1161 */
/*<       integeremc(mlemc),exnodt(9,nex) >*/
/* SOURCE exnmat.for:1162 */
/*<       realgrav,hslot,pql,pqr,pyl,pyr,qe2(nex),res,ye2(nex),ze(nex) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IPNT   - pointer into EMC for description of control structure */
/*     GRAV   - value of acceleration due to gravity */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     NEX    - number of exterior nodes in the model */
/*     MLEMC  - maximum length of EMC(*) */
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
/*     QE2    - flow at exterior nodes at end of time step */
/*     YE2    - depths at exterior nodes at end of time step */
/*     ZE     - elevation of datum for depth at exterior node */
/*     HSLOT  - height of bottom slot.  Currently 0.0 always */
/*     RES    - value of the residual function */
/*     PYL    - partial derivative of residual function wrt depth at */
/*               left node */
/*     PQL    - partial derivative of residual function wrt flow at left */
/*               node */
/*     PYR    - partial derivative of residual function wrt depth at */
/*               right node */
/*     PQR    - partial derivative of residual function wrt flow at right */
/*               node */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE exnmat.for:1201 */
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
/* INCLUDE exnmat.for:1202 */
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
/* INCLUDE exnmat.for:1203 */
/*     Common for subroutine CBFLOW */
/* SOURCE cbcom.cmn:3 */
/*<       integersgn >*/
/* SOURCE cbcom.cmn:5 */
/*<       realybmax,ksub,kfree,dkfree,tb,ab,maxab,qrf,dqrf,sbc,dsbc,hr,hs >*/
/* SOURCE cbcom.cmn:7 */
/*<        >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE exnmat.for:1206 */
/*<        >*/
/* SOURCE exnmat.for:1208 */
/*<        >*/
/*     + + + EQUIVALENCES + + + */
/* SOURCE exnmat.for:1213 */
/*<       equivalence(rdum,idum) >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE exnmat.for:1216 */
/*<       charactergetusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE exnmat.for:1219 */
/*<       externalcbflow,getusn,lktab,xlkt20 >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE exnmat.for:1222 */
/*<    49 format(/' UNN= ',a5,' DNN= ',a5) >*/
/* SOURCE exnmat.for:1223 */
/*<    50  >*/
/* SOURCE exnmat.for:1225 */
/*<    51 format(' YU=',f7.3,' YD=',f7.3) >*/
/* *********************************************************************** */
/*     GET KEY VALUES FROM EMC(*) */
/* SOURCE exnmat.for:1229 */
/*<       unn=emc(ipnt+2) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> ze(feq_storage_ze, 1);

    feq::IndexedPointer<real> ye2(feq_storage_ye2, 1);

    feq::IndexedPointer<real> qe2(feq_storage_qe2, 1);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* L49: */
/* L50: */
/* L51: */
    unn = emc[*ipnt + 2];
/* SOURCE exnmat.for:1230 */
/*<       dnn=emc(ipnt+3) >*/
    dnn = emc[*ipnt + 3];
/* SOURCE exnmat.for:1231 */
/*<       sysgn=emc(ipnt+5) >*/
    sysgn = emc[*ipnt + 5];
/* SOURCE exnmat.for:1232 */
/*<       ptab=emc(ipnt+6) >*/
    ptab = emc[*ipnt + 6];
/* SOURCE exnmat.for:1233 */
/*<       ntab=emc(ipnt+7) >*/
    ntab = emc[*ipnt + 7];
/* SOURCE exnmat.for:1234 */
/*<       batab=emc(ipnt+8) >*/
    batab = emc[*ipnt + 8];
/* SOURCE exnmat.for:1235 */
/*<       trybmx=ftab(itab(batab)) >*/
    trybmx = ftab[itab[batab]];
/* SOURCE exnmat.for:1236 */
/*<       prftab=emc(ipnt+9) >*/
    prftab = emc[*ipnt + 9];
/* SOURCE exnmat.for:1237 */
/*<       nrftab=emc(ipnt+10) >*/
    nrftab = emc[*ipnt + 10];
/* SOURCE exnmat.for:1238 */
/*<       sbctab=emc(ipnt+11) >*/
    sbctab = emc[*ipnt + 11];
/* SOURCE exnmat.for:1239 */
/*<       idum=emc(ipnt+12) >*/
    *idum = emc[*ipnt + 12];
/* SOURCE exnmat.for:1240 */
/*<       maxab=rdum >*/
    cb_1.maxab = *rdum;
/* SOURCE exnmat.for:1241 */
/*<       idum=emc(ipnt+13) >*/
    *idum = emc[*ipnt + 13];
/* SOURCE exnmat.for:1242 */
/*<       maxelv=rdum >*/
    maxelv = *rdum;
/* SOURCE exnmat.for:1243 */
/*<       idum=emc(ipnt+14) >*/
    *idum = emc[*ipnt + 14];
/* SOURCE exnmat.for:1244 */
/*<       ksub=rdum >*/
    cb_1.ksub = *rdum;
/* SOURCE exnmat.for:1245 */
/*<       idum=emc(ipnt+15) >*/
    *idum = emc[*ipnt + 15];
/* SOURCE exnmat.for:1246 */
/*<       rdelev=rdum >*/
    rdelev = *rdum;
/*     FIND THE UPSTREAM AND DOWNSTREAM VALUES */
/* SOURCE exnmat.for:1250 */
/*<       qu=qe2(unn) >*/
    qu = qe2[unn];
/* SOURCE exnmat.for:1251 */
/*<       yu=ye2(unn) >*/
    yu = ye2[unn];
/* SOURCE exnmat.for:1252 */
/*<       adr=exnodt(4,unn) >*/
    adr = exnodt[unn * 9 + 4];
/* SOURCE exnmat.for:1253 */
/*<       callxlkt20(adr,yu,au,tu,dtu,con,dcon,bu,dbu) >*/
    xlkt20_(&adr, &yu, &au, &tu, &dtu, &con, &dcon, &bu, &dbu);
/* SOURCE exnmat.for:1258 */
/*<       zu=yu+ze(unn) >*/
    zu = static_cast<double>(yu) + ze[unn];
/* SOURCE exnmat.for:1259 */
/*<       keu=1.+2.884*(bu-1.) >*/
    keu = static_cast<double>(static_cast<double>((static_cast<double>(bu) - (float)1.)) * (float)2.884) + (float)1.;
/* SOURCE exnmat.for:1260 */
/*<       hu=zu+0.5*keu*(qu/au)**2/grav >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(qu) / au;
    hu = static_cast<double>(zu) + static_cast<double>(static_cast<double>(static_cast<double>(keu) * (float).5) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / *grav;
/* SOURCE exnmat.for:1262 */
/*<       yd=ye2(dnn) >*/
    yd = ye2[dnn];
/* SOURCE exnmat.for:1263 */
/*<       zd=yd+ze(dnn) >*/
    zd = static_cast<double>(yd) + ze[dnn];
/* SOURCE exnmat.for:1264 */
/*<       adr=exnodt(4,dnn) >*/
    adr = exnodt[dnn * 9 + 4];
/* SOURCE exnmat.for:1265 */
/*<       callxlkt20(adr,yd,ad,td,dtd,con,dcon,bd,dbd) >*/
    xlkt20_(&adr, &yd, &ad, &td, &dtd, &con, &dcon, &bd, &dbd);
/* SOURCE exnmat.for:1269 */
/*<       qd=qe2(dnn) >*/
    qd = qe2[dnn];
/* SOURCE exnmat.for:1270 */
/*<       ked=1.+2.884*(bd-1.) >*/
    ked = static_cast<double>(static_cast<double>((static_cast<double>(bd) - (float)1.)) * (float)2.884) + (float)1.;
/* SOURCE exnmat.for:1271 */
/*<       hd=zd+0.5*ked*(qd/ad)**2/grav >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(qd) / ad;
    hd = static_cast<double>(zd) + static_cast<double>(static_cast<double>(static_cast<double>(ked) * (float).5) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / *grav;
/*     FIND THE DIRECTION OF FLOW.  THE DIRECTION MUST AGREE WITH THE */
/*     DIFFERENCE IN TOTAL ENERGY LINE.  THE SIGN OF THE FLOW WILL BE */
/*     SET PROPERLY IF THE DIRECTION IS PROPER. */
/* SOURCE exnmat.for:1278 */
/*<       fsgn=1 >*/
    fsgn = 1;
/* SOURCE exnmat.for:1279 */
/*<       if(hu.lt.hd)fsgn=-1 >*/
    if (hu < hd) {
	fsgn = -1;
    }
/*     FSGN GIVE DIRECTION OF FLOW: */
/*     FSGN > 0 FLOW FROM UPSTREAM TO DOWNSTREAM */
/*     FSGN < 0 FLOW FROM DOWNSTREAM TO UPSTREAM */
/* SOURCE exnmat.for:1285 */
/*<       if(fsgn.lt.0)goto100 >*/
    if (fsgn < 0) {
	goto L100;
    }
/*       FLOW FROM UPSTREAM NODE TO DOWNSTREAM NODE */
/* SOURCE exnmat.for:1289 */
/*<       yb=yd >*/
    yb = yd;
/* SOURCE exnmat.for:1290 */
/*<       ybmax=maxelv-ze(unn) >*/
    cb_1.ybmax = static_cast<double>(maxelv) - ze[unn];
/*       FIND FREE FLOW LOSS COEF FOR BRIDGE. */
/* SOURCE exnmat.for:1294 */
/*<       if(hslot.ge.yb)then >*/
    if (*hslot >= yb) {
/* SOURCE exnmat.for:1295 */
/*<       kfree=0.0 >*/
	cb_1.kfree = (float)0.;
/* SOURCE exnmat.for:1296 */
/*<       dkfree=0.0 >*/
	cb_1.dkfree = (float)0.;
/* SOURCE exnmat.for:1297 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:1298 */
/*<       calllktab(ptab,yb-hslot,0,kfree,nt,dkfree) >*/
	feq_gen_r_d_1 = static_cast<double>(yb) - *hslot;
	lktab_(&ptab, &feq_gen_r_d_1, &feq_gen_c_d_0, &cb_1.kfree, &nt, &cb_1.dkfree);
/* SOURCE exnmat.for:1301 */
/*<       endif >*/
    }
/*       FIND THE FLOW AREA IN BRIDGE OPENING */
/* SOURCE exnmat.for:1305 */
/*<       if(yb.ge.trybmx)goto90 >*/
    if (yb >= trybmx) {
	goto L90;
    }
/* SOURCE exnmat.for:1306 */
/*<       callxlkt20(batab,yb,ab,tb,dtb,con,dcon,b,db) >*/
    xlkt20_(&batab, &yb, &cb_1.ab, &cb_1.tb, &dtb, &con, &dcon, &b, &db);
/* SOURCE exnmat.for:1311 */
/*<       goto92 >*/
    goto L92;
/* SOURCE exnmat.for:1312 */
/*<    90 continue >*/
L90:
/* SOURCE exnmat.for:1313 */
/*<       ab=maxab >*/
    cb_1.ab = cb_1.maxab;
/* SOURCE exnmat.for:1314 */
/*<       tb=0.0 >*/
    cb_1.tb = (float)0.;
/* SOURCE exnmat.for:1315 */
/*<    92 continue >*/
L92:
/*       FIND HEAD ON ROADWAY AND SUBMERGENCE CONDITIONS. */
/* SOURCE exnmat.for:1318 */
/*<       hr=zu-rdelev >*/
    cb_1.hr = static_cast<double>(zu) - rdelev;
/* SOURCE exnmat.for:1319 */
/*<       if(hr.lt.0.0)hr=0.0 >*/
    if (cb_1.hr < (float)0.) {
	cb_1.hr = (float)0.;
    }
/* SOURCE exnmat.for:1320 */
/*<       hs=zd-rdelev >*/
    cb_1.hs = static_cast<double>(zd) - rdelev;
/* SOURCE exnmat.for:1321 */
/*<       if(hs.lt.0.0)hs=0.0 >*/
    if (cb_1.hs < (float)0.) {
	cb_1.hs = (float)0.;
    }
/* SOURCE exnmat.for:1322 */
/*<       rs=0.0 >*/
    rs = (float)0.;
/* SOURCE exnmat.for:1323 */
/*<       if(hr.gt.0.0)rs=hs/hr >*/
    if (cb_1.hr > (float)0.) {
	rs = static_cast<double>(cb_1.hs) / cb_1.hr;
    }
/*       RS GIVES RATIO OF HEAD TO DOWNSTREAM SUBMERGENCE FOR THE FLOW */
/*       OVER THE ROADWAY. */
/*       FIND FLOW OVER ROADWAY WITH NO SUBMERGENCE-FREE FLOW. */
/* SOURCE exnmat.for:1330 */
/*<       calllktab(prftab,hr,0,qrf,nt,dqrf) >*/
    lktab_(&prftab, &cb_1.hr, &feq_gen_c_d_0, &cb_1.qrf, &nt, &cb_1.dqrf);
/*       FIND THE SUBMERGENCE CORRECTION. */
/* SOURCE exnmat.for:1336 */
/*<       sbc=1. >*/
    cb_1.sbc = (float)1.;
/* SOURCE exnmat.for:1337 */
/*<       dsbc=0.0 >*/
    cb_1.dsbc = (float)0.;
/* SOURCE exnmat.for:1338 */
/*<       if(rs.gt.0.)then >*/
    if (rs > (float)0.) {
/* SOURCE exnmat.for:1339 */
/*<       if(rs.gt.1.0)then >*/
	if (rs > (float)1.) {
/* SOURCE exnmat.for:1340 */
/*<       write(stdout,49)getusn(unn),getusn(dnn) >*/
	    feq_gen_io_d__201.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__201);
	    getusn_(feq_gen_ch_d_2, (ftnlen)5, &unn);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	    getusn_(feq_gen_ch_d_4, (ftnlen)5, &dnn);
	    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)5);
	    e_wsfe();
/* SOURCE exnmat.for:1341 */
/*<       write(stdout,50)zu,zd,rdelev,rs >*/
	    feq_gen_io_d__202.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__202);
	    do_fio(&feq_gen_c_d_1, (char *)&zu, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&zd, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&rdelev, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&rs, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE exnmat.for:1342 */
/*<       write(stdout,51)yu,yd >*/
	    feq_gen_io_d__203.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__203);
	    do_fio(&feq_gen_c_d_1, (char *)&yu, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&yd, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE exnmat.for:1343 */
/*<       rs=1.0 >*/
	    rs = (float)1.;
/* SOURCE exnmat.for:1344 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:1345 */
/*<       calllktab(sbctab,rs,0,sbc,nt,dsbc) >*/
	lktab_(&sbctab, &rs, &feq_gen_c_d_0, &cb_1.sbc, &nt, &cb_1.dsbc);
/* SOURCE exnmat.for:1348 */
/*<       endif >*/
    }
/*       SET SIGN FOR QB AND QR. FLOW DIRECTION IS +1. */
/* SOURCE exnmat.for:1351 */
/*<       sgn=+1*sysgn >*/
    cb_1.sgn = sysgn;
/* SOURCE exnmat.for:1354 */
/*<        >*/
    cbflow_(&yu, &zu, &tu, &au, &bu, &dbu, &qu, &hu, &yd, &zd, &td, &ad, &bd, 
	    &dbd, &qd, &hd, hslot, res, pyl, pql, pyr, pqr);
/*        IF(NTAB.LT.0) THEN */
/*         ADJUST THE DERIVATIVES */
/*          PQL = PQL + PYL*DYRDQU */
/*          PYL = PYL*DYRDYL */
/*        ENDIF */
/* SOURCE exnmat.for:1365 */
/*<       return >*/
    return 0;
/* SOURCE exnmat.for:1366 */
/*<   100 continue >*/
L100:
/*       FLOW FROM DOWNSTREAM TO UPSTREAM NODE. */
/* SOURCE exnmat.for:1370 */
/*<       yb=yu >*/
    yb = yu;
/* SOURCE exnmat.for:1371 */
/*<       ybmax=maxelv-ze(dnn) >*/
    cb_1.ybmax = static_cast<double>(maxelv) - ze[dnn];
/*       FIND FREE FLOW LOSS COEF FOR BRIDGE. */
/* SOURCE exnmat.for:1375 */
/*<       if(hslot.ge.yb)then >*/
    if (*hslot >= yb) {
/* SOURCE exnmat.for:1376 */
/*<       kfree=0.0 >*/
	cb_1.kfree = (float)0.;
/* SOURCE exnmat.for:1377 */
/*<       dkfree=0.0 >*/
	cb_1.dkfree = (float)0.;
/* SOURCE exnmat.for:1378 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:1379 */
/*<       calllktab(ntab,yb-hslot,0,kfree,nt,dkfree) >*/
	feq_gen_r_d_1 = static_cast<double>(yb) - *hslot;
	lktab_(&ntab, &feq_gen_r_d_1, &feq_gen_c_d_0, &cb_1.kfree, &nt, &cb_1.dkfree);
/* SOURCE exnmat.for:1382 */
/*<       endif >*/
    }
/*       FIND FLOW AREA IN BRIDGE OPENING. */
/* SOURCE exnmat.for:1387 */
/*<       if(yb.ge.trybmx)goto190 >*/
    if (yb >= trybmx) {
	goto L190;
    }
/* SOURCE exnmat.for:1388 */
/*<       callxlkt20(batab,yb,ab,tb,dtb,con,dcon,b,db) >*/
    xlkt20_(&batab, &yb, &cb_1.ab, &cb_1.tb, &dtb, &con, &dcon, &b, &db);
/* SOURCE exnmat.for:1392 */
/*<       goto192 >*/
    goto L192;
/* SOURCE exnmat.for:1393 */
/*<   190 continue >*/
L190:
/* SOURCE exnmat.for:1394 */
/*<       ab=maxab >*/
    cb_1.ab = cb_1.maxab;
/* SOURCE exnmat.for:1395 */
/*<       tb=0.0 >*/
    cb_1.tb = (float)0.;
/* SOURCE exnmat.for:1396 */
/*<   192 continue >*/
L192:
/*       FIND HEAD ON ROADWAY AND SUBMERGENCE CONDITIONS. */
/* SOURCE exnmat.for:1400 */
/*<       hr=zd-rdelev >*/
    cb_1.hr = static_cast<double>(zd) - rdelev;
/* SOURCE exnmat.for:1401 */
/*<       if(hr.lt.0.0)hr=0. >*/
    if (cb_1.hr < (float)0.) {
	cb_1.hr = (float)0.;
    }
/* SOURCE exnmat.for:1402 */
/*<       hs=zu-rdelev >*/
    cb_1.hs = static_cast<double>(zu) - rdelev;
/* SOURCE exnmat.for:1403 */
/*<       if(hs.lt.0.)hs=0. >*/
    if (cb_1.hs < (float)0.) {
	cb_1.hs = (float)0.;
    }
/* SOURCE exnmat.for:1404 */
/*<       rs=0.0 >*/
    rs = (float)0.;
/* SOURCE exnmat.for:1405 */
/*<       if(hr.gt.0.0)rs=hs/hr >*/
    if (cb_1.hr > (float)0.) {
	rs = static_cast<double>(cb_1.hs) / cb_1.hr;
    }
/*       FIND FLOW OVER ROAD WITH NO SUBMERGENCE-FREE FLOW. */
/* SOURCE exnmat.for:1409 */
/*<       calllktab(nrftab,hr,0,qrf,nt,dqrf) >*/
    lktab_(&nrftab, &cb_1.hr, &feq_gen_c_d_0, &cb_1.qrf, &nt, &cb_1.dqrf);
/*       FIND SUBMERGENCE EFFECT. */
/* SOURCE exnmat.for:1415 */
/*<       sbc=1. >*/
    cb_1.sbc = (float)1.;
/* SOURCE exnmat.for:1416 */
/*<       dsbc=0.0 >*/
    cb_1.dsbc = (float)0.;
/* SOURCE exnmat.for:1417 */
/*<       if(rs.gt.0.)then >*/
    if (rs > (float)0.) {
/* SOURCE exnmat.for:1418 */
/*<       if(rs.gt.1.0)then >*/
	if (rs > (float)1.) {
/* SOURCE exnmat.for:1419 */
/*<       write(stdout,49)getusn(unn),getusn(dnn) >*/
	    feq_gen_io_d__204.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__204);
	    getusn_(feq_gen_ch_d_2, (ftnlen)5, &unn);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	    getusn_(feq_gen_ch_d_4, (ftnlen)5, &dnn);
	    s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)5, (ftnlen)5);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)5);
	    e_wsfe();
/* SOURCE exnmat.for:1420 */
/*<       write(stdout,50)zu,zd,rdelev,rs >*/
	    feq_gen_io_d__205.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__205);
	    do_fio(&feq_gen_c_d_1, (char *)&zu, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&zd, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&rdelev, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&rs, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE exnmat.for:1421 */
/*<       write(stdout,51)yu,yd >*/
	    feq_gen_io_d__206.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__206);
	    do_fio(&feq_gen_c_d_1, (char *)&yu, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&yd, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE exnmat.for:1422 */
/*<       rs=1.0 >*/
	    rs = (float)1.;
/* SOURCE exnmat.for:1423 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:1424 */
/*<       calllktab(sbctab,rs,0,sbc,nt,dsbc) >*/
	lktab_(&sbctab, &rs, &feq_gen_c_d_0, &cb_1.sbc, &nt, &cb_1.dsbc);
/* SOURCE exnmat.for:1427 */
/*<       endif >*/
    }
/*       SET SIGN FOR QB AND QR -FLOW DIRECTION IS -1. */
/* SOURCE exnmat.for:1431 */
/*<       sgn=-1*sysgn >*/
    cb_1.sgn = -sysgn;
/* SOURCE exnmat.for:1434 */
/*<        >*/
    cbflow_(&yd, &zd, &td, &ad, &bd, &dbd, &qd, &hd, &yu, &zu, &tu, &au, &bu, 
	    &dbu, &qu, &hu, hslot, res, pyr, pqr, pyl, pql);
/* SOURCE exnmat.for:1438 */
/*<       return >*/
    return 0;
/* SOURCE exnmat.for:1439 */
/*<       end >*/
} /* cbrid_ */

#undef rtmp
#undef rdum
#undef idum
#undef itab
#undef ftab





/* SOURCE exnmat.for:1443 */
/*<        >*/
/* Subroutine */ int contrl_(integer *ipnt, integer *stdout, integer *nbn, 
	integer *nex, integer *output, doublereal *jtime, integer *feq_storage_exnodt, 
	integer *feq_storage_emc, real *feq_storage_y1, real *feq_storage_zvec, real *feq_storage_dxvec, integer *ept, real *
	pdv, real *disch)
{
    // Original 0x422d03 and 0x422eb9 store REAL SQRT results as binary32.

    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:64* Table Id=\002,a,\002 has invali\
d values for\002,\002 structure setting.\002)";
    static char fmt_52[] = "(/,\002 *ERR:XXX* Slope for computing flow < 0.0\
 at node: \002,a6,\002. Cannot continue computation.\002,/,\002  Review sour\
ce for the \002,\002slope or change the nature of the control at this nod\
e\002)";
    static char fmt_2010[] = "(/,\002SUBROUTINE CONTRL RETURNS :\002,/,1x\
,\002 UNN =  \002,i5,\002 PDV =  \002,e12.5,\002 DISCH =  \002,e12.5)";

    /* System generated locals */
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5], feq_gen_ch_d_3[16], feq_gen_ch_d_4[16];
    static real equiv_2[1];

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal);
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();

    /* Local variables */
    real b, p, y;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real db;
    integer nd;
    real wc, wl, pwc;
    integer unn;
    real top, head, area;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ntab, adrs;
    real elev;
#define idum (feq::BitView<integer>(equiv_2, sizeof(equiv_2)))
    integer xsad;
    real qlim, dtop;
#define rdum (equiv_2)
    integer feq_gen_type_d_;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    integer iflag;
    real zhead;
    integer qhtab;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    real qfree;
    integer nsign;
    real slope;
    extern /* Subroutine */ int xlkt20_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *);
    integer contab, limtab;
    real conlev;
    integer ispout;
    real convey, dconvy, pdvdum;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);
    extern /* Subroutine */ int lktstab_(integer *, doublereal *, real *, 
	    integer *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__216 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__235 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__237 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__247 = { 0, 0, 0, fmt_2010, 0 };


/*     + + + PURPOSE + + + */
/*     Handles look-up of depth-discharge relationships */
/*     at control structures. */
/* SOURCE exnmat.for:1452 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:1454 */
/*<       integeripnt,stdout,ept,nbn,nex,output >*/
/* SOURCE exnmat.for:1455 */
/*<       integeremc(ept),exnodt(9,nex) >*/
/* SOURCE exnmat.for:1456 */
/*<       realdisch,dxvec(nbn),pdv,y1(nbn),zvec(nbn) >*/
/* SOURCE exnmat.for:1457 */
/*<       real*8jtime >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IPNT   - pointer into EMC for description of control structure */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     NBN    - total number on nodes on branches in the model */
/*     NEX    - number of exterior nodes in the model */
/*     OUTPUT - output level for diagnostic work */
/*     TIME   - elapsed time in seconds from start of run */
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
/*     MLEMCV - maximum length of EMC(*) */
/*     Y1     - maximum depth for nodes on a branch at start of time step */
/*     ZVEC   - bottom profile elevations for nodes on a branch */
/*     DXVEC  - distance increments along the x-axis for the channel */
/*     PDV    - partial derivative value */
/*     DISCH  - value of discharge from the control structure */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE exnmat.for:1489 */
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
/* INCLUDE exnmat.for:1490 */
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
/* INCLUDE exnmat.for:1491 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE exnmat.for:1492 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE exnmat.for:1495 */
/*<        >*/
/* SOURCE exnmat.for:1497 */
/*<        >*/
/*     + + + EQUIVALENCES + + + */
/* SOURCE exnmat.for:1501 */
/*<       equivalence(rdum,idum) >*/
/*     + + + INTRINSICS + + + */
/* SOURCE exnmat.for:1504 */
/*<       intrinsicsqrt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE exnmat.for:1507 */
/*<       charactergetusn*5,get_tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE exnmat.for:1510 */
/*<       externalgetusn,lktab,xlkt20,get_tabid >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE exnmat.for:1513 */
/*<    50  >*/
/* SOURCE exnmat.for:1515 */
/*<    52  >*/
/* SOURCE exnmat.for:1518 */
/*<  2010  >*/
/* *********************************************************************** */
/* SOURCE exnmat.for:1521 */
/*<       unn=emc(ipnt+2) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> dxvec(feq_storage_dxvec, 1);

    feq::IndexedPointer<real> zvec(feq_storage_zvec, 1);

    feq::IndexedPointer<real> y1(feq_storage_y1, 1);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* L50: */
/* L52: */
/* L2010: */
    unn = emc[*ipnt + 2];
/* SOURCE exnmat.for:1522 */
/*<       nsign=emc(ipnt+3) >*/
    nsign = emc[*ipnt + 3];
/*      QNODE = EMC(IPNT+4) */
/* SOURCE exnmat.for:1524 */
/*<       y=ye2(unn) >*/
    y = enelem_1.ye2[unn - 1];
/*      Q = QE2(QNODE) */
/* SOURCE exnmat.for:1526 */
/*<       type=emc(ipnt+1) >*/
    feq_gen_type_d_ = emc[*ipnt + 1];
/* SOURCE exnmat.for:1528 */
/*<       goto(100,200,300,400,400,600),type >*/
    switch (feq_gen_type_d_) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
	case 4:  goto L400;
	case 5:  goto L400;
	case 6:  goto L600;
    }
/* SOURCE exnmat.for:1529 */
/*<       write(stdout,*)' *BUG:02* INVALID TYPE IN CONTRL. TYPE=',type >*/
    feq_gen_io_d__216.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__216);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:02* INVALID TYPE IN CONTRL. TYPE="), (ftnlen)
	    39);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE exnmat.for:1530 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE exnmat.for:1531 */
/*<   100 continue >*/
L100:
/*       FLOW GIVEN BY WEIR EQUATION */
/* SOURCE exnmat.for:1535 */
/*<       adrs=emc(ipnt+5) >*/
    adrs = emc[*ipnt + 5];
/* SOURCE exnmat.for:1536 */
/*<       idum=emc(ipnt+6) >*/
    *idum = emc[*ipnt + 6];
/* SOURCE exnmat.for:1537 */
/*<       elev=rdum >*/
    elev = *rdum;
/* SOURCE exnmat.for:1538 */
/*<       idum=emc(ipnt+7) >*/
    *idum = emc[*ipnt + 7];
/* SOURCE exnmat.for:1539 */
/*<       wl=rdum >*/
    wl = *rdum;
/* SOURCE exnmat.for:1540 */
/*<       head=y+ze(unn)-elev >*/
    head = static_cast<double>(static_cast<double>(y) + enelem_1.ze[unn - 1]) - elev;
/* SOURCE exnmat.for:1541 */
/*<       if(head.gt.0.0)goto110 >*/
    if (head > (float)0.) {
	goto L110;
    }
/* SOURCE exnmat.for:1542 */
/*<       pdv=0.0 >*/
    *pdv = (float)0.;
/* SOURCE exnmat.for:1543 */
/*<       disch=0.0 >*/
    *disch = (float)0.;
/* SOURCE exnmat.for:1544 */
/*<       goto9000 >*/
    goto L9000;
/* SOURCE exnmat.for:1545 */
/*<   110 continue >*/
L110:
/*       FIND COEF. FOR WEIR */
/* SOURCE exnmat.for:1549 */
/*<       calllktab(adrs,head,1,wc,ntab,pwc) >*/
    lktab_(&adrs, &head, &feq_gen_c_d_1, &wc, &ntab, &pwc);
/*       COMPUTE DISCHARGE */
/* SOURCE exnmat.for:1555 */
/*<       disch=wc*wl*head*sqrt(head) >*/
    *disch = static_cast<double>(static_cast<double>(wc) * wl) * head * static_cast<float>(sqrt(head));
/* SOURCE exnmat.for:1556 */
/*<       pdv=wl*(pwc*head*sqrt(head)+1.5*wc*sqrt(head)) >*/
    *pdv = wl * (static_cast<double>(pwc) * head * static_cast<float>(sqrt(head)) + static_cast<double>(wc) * (float)1.5 * static_cast<float>(sqrt(head)));
/* SOURCE exnmat.for:1557 */
/*<       goto9000 >*/
    goto L9000;
/* SOURCE exnmat.for:1558 */
/*<   200 continue >*/
L200:
/* SOURCE exnmat.for:1559 */
/*<       adrs=emc(ipnt+5) >*/
    adrs = emc[*ipnt + 5];
/* SOURCE exnmat.for:1560 */
/*<       idum=emc(ipnt+6) >*/
    *idum = emc[*ipnt + 6];
/* SOURCE exnmat.for:1561 */
/*<       elev=rdum >*/
    elev = *rdum;
/*     HEAD OVER CONTROL STRUCTURE REFERENCE LEVEL */
/* SOURCE exnmat.for:1565 */
/*<       head=y+ze(unn)-elev >*/
    head = static_cast<double>(static_cast<double>(y) + enelem_1.ze[unn - 1]) - elev;
/*     CUT OFF NEGATIVE HEAD */
/*      IF(HEAD.GE.0.) GOTO 220 */
/*      PDV = 0. */
/*      DISCH = 0.0 */
/*      GOTO 9000 */
/* SOURCE exnmat.for:1574 */
/*<   220 continue >*/
/* L220: */
/* SOURCE exnmat.for:1575 */
/*<       calllktab(adrs,head,1,disch,ntab,pdv) >*/
    lktab_(&adrs, &head, &feq_gen_c_d_1, disch, &ntab, pdv);
/* SOURCE exnmat.for:1578 */
/*<       goto9000 >*/
    goto L9000;
/* SOURCE exnmat.for:1580 */
/*<   300 continue >*/
L300:
/*     NORMAL DEPTH */
/* SOURCE exnmat.for:1584 */
/*<       iflag=emc(ipnt+5) >*/
    iflag = emc[*ipnt + 5];
/* SOURCE exnmat.for:1585 */
/*<       idum=emc(ipnt+6) >*/
    *idum = emc[*ipnt + 6];
/* SOURCE exnmat.for:1586 */
/*<       slope=rdum >*/
    slope = *rdum;
/* SOURCE exnmat.for:1587 */
/*<       xsad=exnodt(4,unn) >*/
    xsad = exnodt[unn * 9 + 4];
/*      IF(XSAD.GT.0.) GOTO 310 */
/*      WRITE(STDOUT,2000) GETUSN(UNN) */
/*      STOP 'Abnormal stop: errors found.' */
/* 310  CONTINUE */
/* SOURCE exnmat.for:1593 */
/*<       if(iflag.eq.-1)goto305 >*/
    if (iflag == -1) {
	goto L305;
    }
/*        IF(EXNODT(1,UNN).GT.0) GOTO 302 */
/*          WRITE(STDOUT,2005) GETUSN(UNN) */
/*          STOP 'Abnormal stop: errors found.' */
/* 302    CONTINUE */
/* SOURCE exnmat.for:1598 */
/*<       nd=exnodt(2,unn) >*/
    nd = exnodt[unn * 9 + 2];
/* SOURCE exnmat.for:1599 */
/*<       if(iflag.eq.0)slope=(zvec(nd-1)-zvec(nd))/dxvec(nd) >*/
    if (iflag == 0) {
	slope = static_cast<double>((static_cast<double>(zvec[nd - 1]) - zvec[nd])) / dxvec[nd];
    }
/* SOURCE exnmat.for:1600 */
/*<        >*/
    if (iflag == 1) {
	slope = static_cast<double>((static_cast<double>(static_cast<double>(static_cast<double>(y1[nd - 1]) + zvec[nd - 1]) - y1[nd]) - zvec[nd])) / dxvec[nd];
    }
/* SOURCE exnmat.for:1602 */
/*<   305 continue >*/
L305:
/* SOURCE exnmat.for:1604 */
/*<       callxlkt20(xsad,y,area,top,dtop,convey,dconvy,b,db) >*/
    xlkt20_(&xsad, &y, &area, &top, &dtop, &convey, &dconvy, &b, &db);
/* SOURCE exnmat.for:1608 */
/*<       if(slope<=0.0)then >*/
    if (slope <= (float)0.) {
/* SOURCE exnmat.for:1609 */
/*<       write(stdout,52)getusn(unn) >*/
	feq_gen_io_d__235.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__235);
	getusn_(feq_gen_ch_d_2, (ftnlen)5, &unn);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	e_wsfe();
/* SOURCE exnmat.for:1610 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE exnmat.for:1611 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:1612 */
/*<       disch=convey*sqrt(slope) >*/
    *disch = convey * static_cast<float>(sqrt(slope));
/* SOURCE exnmat.for:1613 */
/*<       pdv=sqrt(slope)*dconvy >*/
    *pdv = static_cast<float>(sqrt(slope)) * dconvy;
/* SOURCE exnmat.for:1614 */
/*<       goto9000 >*/
    goto L9000;
/* SOURCE exnmat.for:1615 */
/*<   400 continue >*/
L400:
/*     GET ADRESS OF THE Q VS H TABLE */
/* SOURCE exnmat.for:1619 */
/*<       adrs=emc(ipnt+5) >*/
    adrs = emc[*ipnt + 5];
/* SOURCE exnmat.for:1620 */
/*<       idum=emc(ipnt+7) >*/
    *idum = emc[*ipnt + 7];
/* SOURCE exnmat.for:1621 */
/*<       elev=rdum >*/
    elev = *rdum;
/* SOURCE exnmat.for:1622 */
/*<       head=y+ze(unn)-elev >*/
    head = static_cast<double>(static_cast<double>(y) + enelem_1.ze[unn - 1]) - elev;
/* SOURCE exnmat.for:1624 */
/*<       if(head.ge.0)goto402 >*/
    if (head >= (float)0.) {
	goto L402;
    }
/* SOURCE exnmat.for:1625 */
/*<       pdv=0.0 >*/
    *pdv = (float)0.;
/* SOURCE exnmat.for:1626 */
/*<       disch=0.0 >*/
    *disch = (float)0.;
/*         IF(TYPE.EQ.5) IPNT = IPNT+1 */
/* SOURCE exnmat.for:1628 */
/*<       goto9000 >*/
    goto L9000;
/* SOURCE exnmat.for:1629 */
/*<   402 continue >*/
L402:
/* SOURCE exnmat.for:1630 */
/*<       calllktab(adrs,head,1,disch,ntab,pdv) >*/
    lktab_(&adrs, &head, &feq_gen_c_d_1, disch, &ntab, pdv);
/*     FIND THE OPENING FRACTION-USE HEAD AS A DUMMY FOR */
/*     THE PDV LOCATION */
/* SOURCE exnmat.for:1636 */
/*<       if(type.eq.5)goto403 >*/
    if (feq_gen_type_d_ == 5) {
	goto L403;
    }
/* SOURCE exnmat.for:1638 */
/*<       adrs=emc(ipnt+6) >*/
    adrs = emc[*ipnt + 6];
/* SOURCE exnmat.for:1639 */
/*<       calllktstab(adrs,jtime,p,ntab,head) >*/
    lktstab_(&adrs, jtime, &p, &ntab, &head);
/* SOURCE exnmat.for:1642 */
/*<       if(p.lt.0.0.or.p.gt.1.0)then >*/
    if (p < (float)0. || p > (float)1.) {
/* SOURCE exnmat.for:1643 */
/*<       write(stdout,50)get_tabid(ntab) >*/
	feq_gen_io_d__237.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__237);
	feq_gen_get_tabid_d_(feq_gen_ch_d_4, (ftnlen)16, &ntab);
	s_copy(feq_gen_ch_d_3, feq_gen_ch_d_4, (ftnlen)16, (ftnlen)16);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_3, (ftnlen)16);
	e_wsfe();
/* SOURCE exnmat.for:1644 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE exnmat.for:1645 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:1646 */
/*<       goto404 >*/
    goto L404;
/* SOURCE exnmat.for:1647 */
/*<   403 continue >*/
L403:
/* SOURCE exnmat.for:1648 */
/*<       idum=emc(ipnt+8) >*/
    *idum = emc[*ipnt + 8];
/* SOURCE exnmat.for:1649 */
/*<       ispout=emc(ipnt+10) >*/
    ispout = emc[*ipnt + 10];
/* SOURCE exnmat.for:1650 */
/*<       p=rdum >*/
    p = *rdum;
/* SOURCE exnmat.for:1651 */
/*<       gopen(ispout)=p >*/
    gate1_1.gopen[ispout] = p;
/* SOURCE exnmat.for:1652 */
/*<       if(p.eq.0.0)then >*/
    if (p == (float)0.) {
/* SOURCE exnmat.for:1653 */
/*<       fclass(ispout)='  Closed' >*/
	s_copy(gate2_1.fclass + (ispout << 3), const_cast<char*>("  Closed"), (ftnlen)8, (ftnlen)
		8);
/* SOURCE exnmat.for:1654 */
/*<       fclass_code(ispout)=4 >*/
	gate1_1.feq_gen_fclass_code_d_[ispout] = 4;
/* SOURCE exnmat.for:1655 */
/*<       elseif(p.lt.1.0)then >*/
    } else if (p < (float)1.) {
/* SOURCE exnmat.for:1656 */
/*<       fclass(ispout)='    Open' >*/
	s_copy(gate2_1.fclass + (ispout << 3), const_cast<char*>("    Open"), (ftnlen)8, (ftnlen)
		8);
/* SOURCE exnmat.for:1657 */
/*<       fclass_code(ispout)=5 >*/
	gate1_1.feq_gen_fclass_code_d_[ispout] = 5;
/* SOURCE exnmat.for:1658 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:1659 */
/*<       fclass(ispout)='Max Open' >*/
	s_copy(gate2_1.fclass + (ispout << 3), const_cast<char*>("Max Open"), (ftnlen)8, (ftnlen)
		8);
/* SOURCE exnmat.for:1660 */
/*<       fclass_code(ispout)=6 >*/
	gate1_1.feq_gen_fclass_code_d_[ispout] = 6;
/* SOURCE exnmat.for:1661 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:1662 */
/*<   404 continue >*/
L404:
/* SOURCE exnmat.for:1664 */
/*<       disch=p*disch >*/
    *disch = static_cast<double>(p) * *disch;
/* SOURCE exnmat.for:1665 */
/*<       pdv=p*pdv >*/
    *pdv = static_cast<double>(p) * *pdv;
/* SOURCE exnmat.for:1666 */
/*<       goto9000 >*/
    goto L9000;
/* SOURCE exnmat.for:1668 */
/*<   600 continue >*/
L600:
/*       GREEN RIVER PUMP STATION-- ONE-NODE CONTROL WITH LIMIT SET BY */
/*       FLOW OBTAINED FROM A TIME SERIES TABLE. */
/* SOURCE exnmat.for:1672 */
/*<       qhtab=emc(ipnt+5) >*/
    qhtab = emc[*ipnt + 5];
/* SOURCE exnmat.for:1673 */
/*<       contab=emc(ipnt+6) >*/
    contab = emc[*ipnt + 6];
/* SOURCE exnmat.for:1674 */
/*<       limtab=emc(ipnt+7) >*/
    limtab = emc[*ipnt + 7];
/* SOURCE exnmat.for:1675 */
/*<       idum=emc(ipnt+8) >*/
    *idum = emc[*ipnt + 8];
/* SOURCE exnmat.for:1676 */
/*<       zhead=rdum >*/
    zhead = *rdum;
/*       COMPUTE THE HEAD AVAILABLE */
/* SOURCE exnmat.for:1680 */
/*<       head=y+ze(unn)-zhead >*/
    head = static_cast<double>(static_cast<double>(y) + enelem_1.ze[unn - 1]) - zhead;
/* SOURCE exnmat.for:1681 */
/*<       if(head.lt.0.0)head=0.0 >*/
    if (head < (float)0.) {
	head = (float)0.;
    }
/* SOURCE exnmat.for:1682 */
/*<       calllktab(qhtab,head,1,qfree,ntab,pdv) >*/
    lktab_(&qhtab, &head, &feq_gen_c_d_1, &qfree, &ntab, pdv);
/*       FIND THE CONTROLLING VALUE. */
/* SOURCE exnmat.for:1688 */
/*<       calllktstab(contab,jtime,conlev,ntab,pdvdum) >*/
    lktstab_(&contab, jtime, &conlev, &ntab, &pdvdum);
/*       FIND THE LIMITING FLOWRATE */
/* SOURCE exnmat.for:1694 */
/*<       calllktab(limtab,conlev,1,qlim,ntab,pdvdum) >*/
    lktab_(&limtab, &conlev, &feq_gen_c_d_1, &qlim, &ntab, &pdvdum);
/* SOURCE exnmat.for:1698 */
/*<       if(qfree.le.qlim)then >*/
    if (qfree <= qlim) {
/* SOURCE exnmat.for:1699 */
/*<       disch=qfree >*/
	*disch = qfree;
/* SOURCE exnmat.for:1700 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:1701 */
/*<       disch=qlim >*/
	*disch = qlim;
/* SOURCE exnmat.for:1702 */
/*<       pdv=0.0 >*/
	*pdv = (float)0.;
/* SOURCE exnmat.for:1703 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:1706 */
/*<       goto9000 >*/
    goto L9000;
/* SOURCE exnmat.for:1708 */
/*<  9000 continue >*/
L9000:
/*     SET THE PROPER SIGN FOR THE RETURNED VALUES */
/* SOURCE exnmat.for:1710 */
/*<       if(nsign.lt.0)then >*/
    if (nsign < 0) {
/* SOURCE exnmat.for:1711 */
/*<       disch=-disch >*/
	*disch = -(*disch);
/* SOURCE exnmat.for:1712 */
/*<       pdv=-pdv >*/
	*pdv = -(*pdv);
/* SOURCE exnmat.for:1713 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:1715 */
/*<       if(output.gt.4)write(stdout,2010)unn,pdv,disch >*/
    if (*output > 4) {
	feq_gen_io_d__247.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__247);
	do_fio(&feq_gen_c_d_1, (char *)&unn, (ftnlen)sizeof(integer));
	do_fio(&feq_gen_c_d_1, (char *)&(*pdv), (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&(*disch), (ftnlen)sizeof(real));
	e_wsfe();
    }
/* SOURCE exnmat.for:1716 */
/*<       return >*/
    return 0;
/* SOURCE exnmat.for:1717 */
/*<       end >*/
} /* contrl_ */

#undef rtmp
#undef rdum
#undef idum
#undef itab
#undef ftab





/* SOURCE exnmat.for:1721 */
/*<        >*/
/* Subroutine */ int excon_(integer *ipnt, integer *stdout, doublereal *jtime,
	 integer *nex, integer *mlemcv, integer *feq_storage_exnodt, real *feq_storage_qe2, real *feq_storage_ye2,
	 real *feq_storage_ze, integer *feq_storage_emc, real *res, real *pyl, real *pql, real *pyr, 
	real *pqr)
{
    /* Format strings */
    static char fmt_10[] = "(/,\002 *ERR:85*  Numeric problem in SUBROUTINE \
EXCON.\002,/,3i5,f14.2,6(1pe13.5))";

    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2;
    static real equiv_0[1];

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    real k, q, ac, bc, al, bl, ar, br, tc, yc, zc, tl, pq, vl, yl, tr, zl, vr,
	     yr, zr, dbc, fac, dbl;
    integer adr;
    real dbr, dtc;
    integer dnn;
    real con, dtl, lhs, ycl, dtr;
    integer qnn;
    real rhs, vhl;
    integer unn;
    real vhr, ycr, dcon, kneg;
    integer sadr, fsgn;
#define idum (feq::BitView<integer>(equiv_0, sizeof(equiv_0)))
    real qcsq;
#define rdum (equiv_0)
    real kpos, alphl, alphr;
    integer state;
    extern /* Subroutine */ int xlkt20_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *);
    integer sysgn;
    real dalphl, dalphr;
    integer trnsgn;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__299 = { 0, 0, 0, fmt_10, 0 };


/*     + + + PURPOSE + + + */
/*     Subroutine to compute required values for generalized */
/*     expansion-contraction.  Transition between subcritical and */
/*     critical flow is monitored and the critical depth control */
/*     can be drowned by changing conditions downstream. */
/* SOURCE exnmat.for:1733 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:1735 */
/*<       integeripnt,stdout,mlemcv,nex >*/
/* SOURCE exnmat.for:1736 */
/*<       integeremc(mlemcv),exnodt(9,nex) >*/
/* SOURCE exnmat.for:1737 */
/*<       realpql,pqr,pyl,pyr,qe2(nex),res,ye2(nex),ze(nex) >*/
/* SOURCE exnmat.for:1739 */
/*<       real*8jtime >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IPNT   - pointer into EMC for description of control structure */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     TIME   - elapsed time in seconds from start of run */
/*     NEX    - number of exterior nodes in the model */
/*     MLEMCV - maximum length of EMC(*) */
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
/*     QE2    - flow at exterior nodes at end of time step */
/*     YE2    - depths at exterior nodes at end of time step */
/*     ZE     - elevation of datum for depth at exterior node */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     RES    - value of the residual function */
/*     PYL    - partial derivative of residual function wrt depth at */
/*               left node */
/*     PQL    - partial derivative of residual function wrt flow at left */
/*               node */
/*     PYR    - partial derivative of residual function wrt depth at */
/*               right node */
/*     PQR    - partial derivative of residual function wrt flow at right */
/*               node */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE exnmat.for:1776 */
/* ********************************************************************** */
/* SOURCE grav.cmn:2 */
/*<       realgrav,twog,halfg >*/
/* SOURCE grav.cmn:4 */
/*<       common/gravcm/grav,twog,halfg >*/
/* SOURCE grav.cmn:5 */
/*<       save/gravcm/ >*/
/* ********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE exnmat.for:1779 */
/*<       integeradr,dnn,fsgn,idum,qnn,sadr,state,sysgn,trnsgn,unn >*/
/* SOURCE exnmat.for:1781 */
/*<        >*/
/*     + + + EQUIVALENCES + + + */
/* SOURCE exnmat.for:1787 */
/*<       equivalence(rdum,idum) >*/
/*     + + + INTRINSICS + + + */
/* SOURCE exnmat.for:1790 */
/*<       intrinsicfloat,max >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE exnmat.for:1793 */
/*<       externalxlkt20 >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE exnmat.for:1796 */
/*<    10  >*/
/* *********************************************************************** */
/*     GET KEY VALUES FROM EMC.  IPNT POINTS */
/*     TO CODE. */
/* SOURCE exnmat.for:1801 */
/*<       unn=emc(ipnt+2) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> ze(feq_storage_ze, 1);

    feq::IndexedPointer<real> ye2(feq_storage_ye2, 1);

    feq::IndexedPointer<real> qe2(feq_storage_qe2, 1);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* L10: */
    unn = emc[*ipnt + 2];
/* SOURCE exnmat.for:1802 */
/*<       dnn=emc(ipnt+3) >*/
    dnn = emc[*ipnt + 3];
/* SOURCE exnmat.for:1803 */
/*<       qnn=emc(ipnt+4) >*/
    qnn = emc[*ipnt + 4];
/* SOURCE exnmat.for:1804 */
/*<       trnsgn=emc(ipnt+6) >*/
    trnsgn = emc[*ipnt + 6];
/* SOURCE exnmat.for:1805 */
/*<       state=emc(ipnt+8) >*/
    state = emc[*ipnt + 8];
/* SOURCE exnmat.for:1806 */
/*<       sadr=emc(ipnt+7) >*/
    sadr = emc[*ipnt + 7];
/* SOURCE exnmat.for:1807 */
/*<       sysgn=emc(ipnt+5) >*/
    sysgn = emc[*ipnt + 5];
/* SOURCE exnmat.for:1808 */
/*<       idum=emc(ipnt+9) >*/
    *idum = emc[*ipnt + 9];
/* SOURCE exnmat.for:1809 */
/*<       kpos=rdum >*/
    kpos = *rdum;
/* SOURCE exnmat.for:1810 */
/*<       idum=emc(ipnt+10) >*/
    *idum = emc[*ipnt + 10];
/* SOURCE exnmat.for:1811 */
/*<       kneg=rdum >*/
    kneg = *rdum;
/* SOURCE exnmat.for:1812 */
/*<       idum=emc(ipnt+11) >*/
    *idum = emc[*ipnt + 11];
/* SOURCE exnmat.for:1813 */
/*<       zc=rdum >*/
    zc = *rdum;
/* SOURCE exnmat.for:1814 */
/*<       yl=ye2(unn) >*/
    yl = ye2[unn];
/* SOURCE exnmat.for:1815 */
/*<       yr=ye2(dnn) >*/
    yr = ye2[dnn];
/* SOURCE exnmat.for:1816 */
/*<       zl=ze(unn) >*/
    zl = ze[unn];
/* SOURCE exnmat.for:1817 */
/*<       zr=ze(dnn) >*/
    zr = ze[dnn];
/*     GET FLOW RELATED VALUES */
/* SOURCE exnmat.for:1821 */
/*<       q=qe2(qnn) >*/
    q = qe2[qnn];
/*     SET DIRECTION OF FLOW */
/* SOURCE exnmat.for:1825 */
/*<       fsgn=sysgn >*/
    fsgn = sysgn;
/* SOURCE exnmat.for:1826 */
/*<       if(q.lt.0.0)fsgn=-sysgn >*/
    if (q < (float)0.) {
	fsgn = -sysgn;
    }
/*     CHECK FOR INVALID REVERSE FLOW */
/*      IF(FSGN.GT.0) GOTO 50 */

/*       FLOW FROM DOWNSTREAM TO UPSTREAM MAY NOT BE POSSIBLE */
/*        IF(YR+ZR.GT.ZC) GOTO 40 */
/*         REVERSE FLOW IMPOSSIBLE-CHANGE SIGN OF Q AND FSGN */
/*          FSGN = -FSGN */
/*          Q = -Q */
/*          QE2(QNN) = Q */
/*          WRITE(STDOUT,2000) GETUSN(QNN), TIME, Q, YL, YR */
/* 40      CONTINUE */
/* 50    CONTINUE */
/*     COMPUTE COMPONENTS OF FREE FLOWING RELATIONSHIP */
/*     LOOKUP VALUES NEEDED AT UNN AND DNN */
/* SOURCE exnmat.for:1849 */
/*<       tl=0. >*/
    tl = (float)0.;
/* SOURCE exnmat.for:1850 */
/*<       al=-1. >*/
    al = (float)-1.;
/* SOURCE exnmat.for:1851 */
/*<       bl=1.0 >*/
    bl = (float)1.;
/* SOURCE exnmat.for:1852 */
/*<       dbl=0.0 >*/
    dbl = (float)0.;
/* SOURCE exnmat.for:1853 */
/*<       if(exnodt(3,unn).le.0)goto100 >*/
    if (exnodt[unn * 9 + 3] <= 0) {
	goto L100;
    }
/*     CROSS SECTION INFORMATION EXISTS */
/* SOURCE exnmat.for:1857 */
/*<       adr=exnodt(4,unn) >*/
    adr = exnodt[unn * 9 + 4];
/* SOURCE exnmat.for:1858 */
/*<       callxlkt20(adr,yl,al,tl,dtl,con,dcon,bl,dbl) >*/
    xlkt20_(&adr, &yl, &al, &tl, &dtl, &con, &dcon, &bl, &dbl);
/* SOURCE exnmat.for:1862 */
/*<   100 continue >*/
L100:
/* SOURCE exnmat.for:1863 */
/*<       tr=0.0 >*/
    tr = (float)0.;
/* SOURCE exnmat.for:1864 */
/*<       ar=-1. >*/
    ar = (float)-1.;
/* SOURCE exnmat.for:1865 */
/*<       br=1.0 >*/
    br = (float)1.;
/* SOURCE exnmat.for:1866 */
/*<       dbr=0.0 >*/
    dbr = (float)0.;
/* SOURCE exnmat.for:1867 */
/*<       if(exnodt(3,dnn).le.0)goto200 >*/
    if (exnodt[dnn * 9 + 3] <= 0) {
	goto L200;
    }
/* SOURCE exnmat.for:1868 */
/*<       adr=exnodt(4,dnn) >*/
    adr = exnodt[dnn * 9 + 4];
/* SOURCE exnmat.for:1869 */
/*<       callxlkt20(adr,yr,ar,tr,dtr,con,dcon,br,dbr) >*/
    xlkt20_(&adr, &yr, &ar, &tr, &dtr, &con, &dcon, &br, &dbr);
/* SOURCE exnmat.for:1873 */
/*<   200 continue >*/
L200:
/*     DETERMINE THE VELOCITY AT EACH SECTION */
/* SOURCE exnmat.for:1877 */
/*<       vl=0.0 >*/
    vl = (float)0.;
/* SOURCE exnmat.for:1878 */
/*<       if(al.gt.0.0)vl=q/al >*/
    if (al > (float)0.) {
	vl = static_cast<double>(q) / al;
    }
/* SOURCE exnmat.for:1879 */
/*<       vr=0.0 >*/
    vr = (float)0.;
/* SOURCE exnmat.for:1881 */
/*<       if(ar.gt.0.0)vr=q/ar >*/
    if (ar > (float)0.) {
	vr = static_cast<double>(q) / ar;
    }
/*     DETERMINE VELOCITY HEAD COEFFICIENTS AND DERIVATIVES OF THE */
/*     COEFFICIENTS */
/* SOURCE exnmat.for:1886 */
/*<       alphl=-2.+3.*bl >*/
    alphl = static_cast<double>(static_cast<double>(bl) * (float)3.) - (float)2.;
/* SOURCE exnmat.for:1887 */
/*<       dalphl=3.*dbl >*/
    dalphl = static_cast<double>(dbl) * (float)3.;
/* SOURCE exnmat.for:1888 */
/*<       alphr=-2.+3.*br >*/
    alphr = static_cast<double>(static_cast<double>(br) * (float)3.) - (float)2.;
/* SOURCE exnmat.for:1889 */
/*<       dalphr=3.*dbr >*/
    dalphr = static_cast<double>(dbr) * (float)3.;
/* SOURCE exnmat.for:1891 */
/*<       vhl=alphl*vl**2/(twog) >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = vl;
    vhl = static_cast<double>(static_cast<double>(alphl) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / gravcm_1.twog;
/* SOURCE exnmat.for:1892 */
/*<       vhr=alphr*vr**2/(twog) >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = vr;
    vhr = static_cast<double>(static_cast<double>(alphr) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / gravcm_1.twog;
/*     SET VALUE OF K */
/* SOURCE exnmat.for:1897 */
/*<       k=kpos >*/
    k = kpos;
/* SOURCE exnmat.for:1898 */
/*<       if(fsgn.lt.0)k=kneg >*/
    if (fsgn < 0) {
	k = kneg;
    }
/*     SET SIGN OF K */
/* SOURCE exnmat.for:1902 */
/*<       k=float(fsgn*trnsgn)*k >*/
    k = static_cast<double>((real) (fsgn * trnsgn)) * k;
/* SOURCE exnmat.for:1904 */
/*<       lhs=zl+yl+(1.-k)*vhl >*/
    lhs = static_cast<double>(static_cast<double>(zl) + yl) + static_cast<double>((static_cast<double>((float)1.) - k)) * vhl;
/* SOURCE exnmat.for:1905 */
/*<       rhs=zr+yr+(1.-k)*vhr >*/
    rhs = static_cast<double>(static_cast<double>(zr) + yr) + static_cast<double>((static_cast<double>((float)1.) - k)) * vhr;
/*     ESTABLISH CRITICAL CONTROL VALUES */
/*     COMPUTE DEPTH AT THE CRITICAL SECTION */
/* SOURCE exnmat.for:1911 */
/*<       ycl=yl+zl-zc >*/
    ycl = static_cast<double>(static_cast<double>(yl) + zl) - zc;
/* SOURCE exnmat.for:1912 */
/*<       ycr=yr+zr-zc >*/
    ycr = static_cast<double>(static_cast<double>(yr) + zr) - zc;
/* SOURCE exnmat.for:1913 */
/*<       yc=max(ycl,ycr) >*/
    yc = dmax(ycl,ycr);
/* SOURCE exnmat.for:1914 */
/*<       if(yc.le.0.0)then >*/
    if (yc <= (float)0.) {
/*       SPECIAL CASE--WATER SURFACE BELOW CONTROL ON BOTH SIDES */
/*       FORCE FLOW AT FLOW NODE TO BE ZERO */
/* SOURCE exnmat.for:1918 */
/*<       res=q >*/
	*res = q;
/* SOURCE exnmat.for:1919 */
/*<       pyl=0.0 >*/
	*pyl = (float)0.;
/* SOURCE exnmat.for:1920 */
/*<       pyr=0.0 >*/
	*pyr = (float)0.;
/* SOURCE exnmat.for:1921 */
/*<       if(unn.eq.qnn)then >*/
	if (unn == qnn) {
/* SOURCE exnmat.for:1922 */
/*<       pql=1.0 >*/
	    *pql = (float)1.;
/* SOURCE exnmat.for:1923 */
/*<       pqr=0.0 >*/
	    *pqr = (float)0.;
/* SOURCE exnmat.for:1924 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:1925 */
/*<       pql=0.0 >*/
	    *pql = (float)0.;
/* SOURCE exnmat.for:1926 */
/*<       pqr=1.0 >*/
	    *pqr = (float)1.;
/* SOURCE exnmat.for:1927 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:1929 */
/*<       return >*/
	return 0;
/* SOURCE exnmat.for:1930 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:1931 */
/*<       callxlkt20(sadr,yc,ac,tc,dtc,con,dcon,bc,dbc) >*/
	xlkt20_(&sadr, &yc, &ac, &tc, &dtc, &con, &dcon, &bc, &dbc);
/* SOURCE exnmat.for:1935 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:1937 */
/*<       if(q.eq.0.0)then >*/
    if (q == (float)0.) {
/*       MAKE SURE FSGN IS CORRECT IN THE INDETERMINATE CASE */
/* SOURCE exnmat.for:1941 */
/*<       if(ycl.ge.ycr)then >*/
	if (ycl >= ycr) {
/* SOURCE exnmat.for:1942 */
/*<       fsgn=1 >*/
	    fsgn = 1;
/* SOURCE exnmat.for:1943 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:1944 */
/*<       fsgn=-1 >*/
	    fsgn = -1;
/* SOURCE exnmat.for:1945 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:1946 */
/*<       endif >*/
    }
/*     CHECK FOR VALIDITY OF CRITICAL SECTION VALUES */
/*     FOR INITIAL WORK SET BETA AND DBETA/DY */
/* SOURCE exnmat.for:1950 */
/*<       bc=1.0 >*/
    bc = (float)1.;
/* SOURCE exnmat.for:1951 */
/*<       dbc=0.0 >*/
    dbc = (float)0.;
/* SOURCE exnmat.for:1952 */
/*<       fac=ac*dbc-bc*tc >*/
    fac = static_cast<double>(static_cast<double>(ac) * dbc) - static_cast<double>(bc) * tc;
/*     FAC MUST BE LESS THAN ZERO.  OTHERWISE THE CRITICAL FLOW BECOMES */
/*      IMAGINARY...... */
/* SOURCE exnmat.for:1956 */
/*<       if(fac.lt.0.0)goto250 >*/
    if (fac < (float)0.) {
	goto L250;
    }
/*       ERROR HERE */
/* SOURCE exnmat.for:1959 */
/*<       write(stdout,10)unn,dnn,fsgn,jtime,yc,tc,ac,bc,dbc >*/
    feq_gen_io_d__299.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__299);
    do_fio(&feq_gen_c_d_1, (char *)&unn, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&dnn, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&fsgn, (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&(*jtime), (ftnlen)sizeof(doublereal));
    do_fio(&feq_gen_c_d_1, (char *)&yc, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&tc, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&ac, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&bc, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&dbc, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE exnmat.for:1960 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE exnmat.for:1961 */
/*<   250 continue >*/
L250:
/*     NOW COMPUTE DERIVATIVES FOR FREE FLOWING CONDITION */
/* SOURCE exnmat.for:1965 */
/*<       pyl=1.-(1.-k)*vl**2*(alphl*tl/al-0.5*dalphl)/grav >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = vl;
    *pyl = static_cast<double>((float)1.) - static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - k)) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) * (static_cast<double>(static_cast<double>(static_cast<double>(alphl) * tl) / al) - 
	    static_cast<double>(dalphl) * (float).5)) / gravcm_1.grav;
/* SOURCE exnmat.for:1966 */
/*<       pql=alphl*(1.-k)*vl/(grav*al) >*/
    *pql = static_cast<double>(static_cast<double>(static_cast<double>(alphl) * (static_cast<double>((float)1.) - k)) * vl) / (static_cast<double>(gravcm_1.grav) * al);
/* SOURCE exnmat.for:1967 */
/*<       pyr=-1.-(1.-k)*vr**2*(-alphr*tr/ar+0.5*dalphr)/grav >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = vr;
    *pyr = static_cast<double>((float)-1.) - static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - k)) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) * (static_cast<double>(static_cast<double>(static_cast<double>(-alphr) * tr) / ar) + 
	    static_cast<double>(dalphr) * (float).5)) / gravcm_1.grav;
/* SOURCE exnmat.for:1968 */
/*<       pqr=-alphr*(1.-k)*vr/(grav*ar) >*/
    *pqr = static_cast<double>(static_cast<double>(static_cast<double>(-alphr) * (static_cast<double>((float)1.) - k)) * vr) / (static_cast<double>(gravcm_1.grav) * ar);
/*     COMPUTE RESIDUAL FOR FREE FLOWING CONDITION */
/* SOURCE exnmat.for:1972 */
/*<       res=lhs-rhs >*/
    *res = static_cast<double>(lhs) - rhs;
/*     NOW BEGIN THE PROCESS OF DETERMINING THE FLOW STATE AND THE */
/*     NEED FOR CHANGING THE STATE. */
/* SOURCE exnmat.for:1978 */
/*<       if(fsgn.lt.0)goto1000 >*/
    if (fsgn < 0) {
	goto L1000;
    }
/*       FLOW IS FROM UPSTREAM NODE TO DOWNSTREAM NODE OF THE STRUCTURE */
/* SOURCE exnmat.for:1982 */
/*<       if(state.ne.1)goto400 >*/
    if (state != 1) {
	goto L400;
    }
/*         STATE IS CRITICAL HERE */
/* SOURCE exnmat.for:1985 */
/*<       if(rhs.lt.lhs)goto300 >*/
    if (rhs < lhs) {
	goto L300;
    }
/*           THE CRITICAL SECTION HAS BEEN DROWNED FROM DOWNSTREAM. */
/*           CHANGE STATE TO REFLECT THE LOSS OF CRITICAL FLOW */
/* SOURCE exnmat.for:1990 */
/*<       state=-state >*/
    state = -state;
/* SOURCE exnmat.for:1991 */
/*<       goto5000 >*/
    goto L5000;
/* SOURCE exnmat.for:1992 */
/*<   300 continue >*/
L300:
/*         FLOW IS STILL CRITICAL. RECOMPUTE RESIDUAL AND DERIVIATIVES */
/*         FOR CRITICAL CONTROL EXISTING AT UPSTREAM NODE. */
/* SOURCE exnmat.for:1996 */
/*<       res=q**2*fac+grav*ac**3 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = q;
/* Computing 3rd power */
    feq_gen_r_d_2 = ac;
    *res = static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * fac) + static_cast<double>(gravcm_1.grav) * (static_cast<double>(feq_gen_r_d_2) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2));
/* SOURCE exnmat.for:1997 */
/*<       pyl=q**2*(-bc*dtc)+3.*grav*ac**2*tc >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = q;
/* Computing 2nd power */
    feq_gen_r_d_2 = ac;
    *pyl = static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * (static_cast<double>(-bc) * dtc)) + static_cast<double>(static_cast<double>(static_cast<double>(gravcm_1.grav) * (float)3.) * (static_cast<double>(feq_gen_r_d_2) * 
	    feq_gen_r_d_2)) * tc;
/* SOURCE exnmat.for:1998 */
/*<       pq=2.*q*fac >*/
    pq = static_cast<double>(static_cast<double>(q) * (float)2.) * fac;
/* SOURCE exnmat.for:1999 */
/*<       if(unn.eq.qnn)then >*/
    if (unn == qnn) {
/* SOURCE exnmat.for:2000 */
/*<       pql=pq >*/
	*pql = pq;
/* SOURCE exnmat.for:2001 */
/*<       pqr=0.0 >*/
	*pqr = (float)0.;
/* SOURCE exnmat.for:2002 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:2003 */
/*<       pqr=pq >*/
	*pqr = pq;
/* SOURCE exnmat.for:2004 */
/*<       pql=0 >*/
	*pql = (float)0.;
/* SOURCE exnmat.for:2005 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:2006 */
/*<       pyr=0.0 >*/
    *pyr = (float)0.;
/* SOURCE exnmat.for:2007 */
/*<       goto5000 >*/
    goto L5000;
/* SOURCE exnmat.for:2008 */
/*<   400 continue >*/
L400:

/*         STATE IS NON-CRITICAL.  CHECK IF IT SHOULD BECOME CRITICAL */
/*         FIND THE SQUARE OF THE CRITICAL FLOW AT THE CONTROLLING SECTION. */
/* SOURCE exnmat.for:2013 */
/*<       qcsq=-grav*ac**3/fac >*/
/* Computing 3rd power */
    feq_gen_r_d_1 = ac;
    qcsq = static_cast<double>(static_cast<double>(-gravcm_1.grav) * (static_cast<double>(feq_gen_r_d_1) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1))) / fac;
/* SOURCE exnmat.for:2014 */
/*<       if(qcsq.gt.q**2)goto500 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = q;
    if (qcsq > static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) {
	goto L500;
    }
/*           SHIFT CONTROL TO CRITICAL DEPTH AT UPSTREAM NODE */
/* SOURCE exnmat.for:2018 */
/*<       state=-state >*/
    state = -state;
/* SOURCE exnmat.for:2019 */
/*<       res=q**2*fac+grav*ac**3 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = q;
/* Computing 3rd power */
    feq_gen_r_d_2 = ac;
    *res = static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * fac) + static_cast<double>(gravcm_1.grav) * (static_cast<double>(feq_gen_r_d_2) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2));
/* SOURCE exnmat.for:2020 */
/*<       pyl=q**2*(-bc*dtc)+3.*grav*ac**2*tc >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = q;
/* Computing 2nd power */
    feq_gen_r_d_2 = ac;
    *pyl = static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * (static_cast<double>(-bc) * dtc)) + static_cast<double>(static_cast<double>(static_cast<double>(gravcm_1.grav) * (float)3.) * (static_cast<double>(feq_gen_r_d_2) * 
	    feq_gen_r_d_2)) * tc;
/* SOURCE exnmat.for:2021 */
/*<       pq=2.*q*fac >*/
    pq = static_cast<double>(static_cast<double>(q) * (float)2.) * fac;
/* SOURCE exnmat.for:2022 */
/*<       if(unn.eq.qnn)then >*/
    if (unn == qnn) {
/* SOURCE exnmat.for:2023 */
/*<       pql=pq >*/
	*pql = pq;
/* SOURCE exnmat.for:2024 */
/*<       pqr=0.0 >*/
	*pqr = (float)0.;
/* SOURCE exnmat.for:2025 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:2026 */
/*<       pqr=pq >*/
	*pqr = pq;
/* SOURCE exnmat.for:2027 */
/*<       pql=0 >*/
	*pql = (float)0.;
/* SOURCE exnmat.for:2028 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:2029 */
/*<       pyr=0.0 >*/
    *pyr = (float)0.;
/* SOURCE exnmat.for:2030 */
/*<       goto5000 >*/
    goto L5000;
/* SOURCE exnmat.for:2031 */
/*<   500 continue >*/
L500:
/*           REMAIN IN NON-CRITICAL STATE */
/* SOURCE exnmat.for:2035 */
/*<       goto5000 >*/
    goto L5000;
/* SOURCE exnmat.for:2036 */
/*<  1000 continue >*/
L1000:
/*       FLOW IS NEGATIVE.  THAT IS FROM DOWNSTREAM NODE TO UPSTREAM NODE. */
/*       NOTE: THE SIGN OF Q IS NOT NECESSARILY NEGATIVE...... */
/* SOURCE exnmat.for:2041 */
/*<       if(state.ne.1)goto1400 >*/
    if (state != 1) {
	goto L1400;
    }
/*         FLOW IS AT CRITICAL DEPTH */
/* SOURCE exnmat.for:2045 */
/*<       if(rhs.ge.lhs)goto1300 >*/
    if (rhs >= lhs) {
	goto L1300;
    }
/*           RESET STATE TO NON-CRITICAL */
/* SOURCE exnmat.for:2049 */
/*<       state=-state >*/
    state = -state;
/* SOURCE exnmat.for:2050 */
/*<       goto5000 >*/
    goto L5000;
/* SOURCE exnmat.for:2051 */
/*<  1300 continue >*/
L1300:
/*           RETAIN CRITICAL FLOW STATE */
/* SOURCE exnmat.for:2055 */
/*<       res=q**2*fac+grav*ac**3 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = q;
/* Computing 3rd power */
    feq_gen_r_d_2 = ac;
    *res = static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * fac) + static_cast<double>(gravcm_1.grav) * (static_cast<double>(feq_gen_r_d_2) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2));
/* SOURCE exnmat.for:2056 */
/*<       pyr=q**2*(-bc*dtc)+3.*grav*ac**2*tc >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = q;
/* Computing 2nd power */
    feq_gen_r_d_2 = ac;
    *pyr = static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * (static_cast<double>(-bc) * dtc)) + static_cast<double>(static_cast<double>(static_cast<double>(gravcm_1.grav) * (float)3.) * (static_cast<double>(feq_gen_r_d_2) * 
	    feq_gen_r_d_2)) * tc;
/* SOURCE exnmat.for:2057 */
/*<       pq=2.*q*fac >*/
    pq = static_cast<double>(static_cast<double>(q) * (float)2.) * fac;
/* SOURCE exnmat.for:2058 */
/*<       pyl=0.0 >*/
    *pyl = (float)0.;
/* SOURCE exnmat.for:2059 */
/*<       if(unn.eq.qnn)then >*/
    if (unn == qnn) {
/* SOURCE exnmat.for:2060 */
/*<       pql=pq >*/
	*pql = pq;
/* SOURCE exnmat.for:2061 */
/*<       pqr=0.0 >*/
	*pqr = (float)0.;
/* SOURCE exnmat.for:2062 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:2063 */
/*<       pqr=pq >*/
	*pqr = pq;
/* SOURCE exnmat.for:2064 */
/*<       pql=0 >*/
	*pql = (float)0.;
/* SOURCE exnmat.for:2065 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:2066 */
/*<       goto5000 >*/
    goto L5000;
/* SOURCE exnmat.for:2067 */
/*<  1400 continue >*/
L1400:
/*         STATE IS NON-CRITICAL */
/* SOURCE exnmat.for:2071 */
/*<       qcsq=-grav*ac**3/fac >*/
/* Computing 3rd power */
    feq_gen_r_d_1 = ac;
    qcsq = static_cast<double>(static_cast<double>(-gravcm_1.grav) * (static_cast<double>(feq_gen_r_d_1) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1))) / fac;
/* SOURCE exnmat.for:2072 */
/*<       if(qcsq.gt.q**2)goto1500 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = q;
    if (qcsq > static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) {
	goto L1500;
    }
/*           SHIFT CONTROL TO CRITICAL DEPTH AT DOWNSTREAM NODE */
/* SOURCE exnmat.for:2076 */
/*<       state=-state >*/
    state = -state;
/* SOURCE exnmat.for:2077 */
/*<       res=q**2*fac+grav*ac**3 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = q;
/* Computing 3rd power */
    feq_gen_r_d_2 = ac;
    *res = static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * fac) + static_cast<double>(gravcm_1.grav) * (static_cast<double>(feq_gen_r_d_2) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2));
/* SOURCE exnmat.for:2078 */
/*<       pyr=q**2*(-bc*dtc)+3.*grav**2*tc >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = q;
/* Computing 2nd power */
    feq_gen_r_d_2 = gravcm_1.grav;
    *pyr = static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * (static_cast<double>(-bc) * dtc)) + static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2) * (float)3.) * tc;
/* SOURCE exnmat.for:2079 */
/*<       pq=2.*q*fac >*/
    pq = static_cast<double>(static_cast<double>(q) * (float)2.) * fac;
/* SOURCE exnmat.for:2080 */
/*<       if(unn.eq.qnn)then >*/
    if (unn == qnn) {
/* SOURCE exnmat.for:2081 */
/*<       pql=pq >*/
	*pql = pq;
/* SOURCE exnmat.for:2082 */
/*<       pqr=0.0 >*/
	*pqr = (float)0.;
/* SOURCE exnmat.for:2083 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:2084 */
/*<       pqr=pq >*/
	*pqr = pq;
/* SOURCE exnmat.for:2085 */
/*<       pql=0 >*/
	*pql = (float)0.;
/* SOURCE exnmat.for:2086 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:2087 */
/*<       pyl=0.0 >*/
    *pyl = (float)0.;
/* SOURCE exnmat.for:2088 */
/*<       goto5000 >*/
    goto L5000;
/* SOURCE exnmat.for:2089 */
/*<  1500 continue >*/
L1500:
/* SOURCE exnmat.for:2092 */
/*<  5000 continue >*/
L5000:
/* SOURCE exnmat.for:2093 */
/*<       emc(ipnt+8)=state >*/
    emc[*ipnt + 8] = state;
/* SOURCE exnmat.for:2094 */
/*<       return >*/
    return 0;
/* SOURCE exnmat.for:2095 */
/*<       end >*/
} /* excon_ */

#undef rdum
#undef idum





/* SOURCE exnmat.for:2099 */
/*<       subroutinefindcf(stdout,a,t,q,head,cf,dcfy,dcfq) >*/
/* Subroutine */ int findcf_(integer *stdout, real *a, real *t, real *q, real 
	*head, real *cf, real *dcfy, real *dcfq)
{
    /* System generated locals */
    real feq_gen_r_d_1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    real tp, tp2, tp3, frw2;

/*     + + + PURPOSE + + + */
/*     Compute HAGER'S side weir function with its derivatives. */
/* SOURCE exnmat.for:2106 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:2108 */
/*<       integerstdout >*/
/* SOURCE exnmat.for:2109 */
/*<       reala,cf,dcfq,dcfy,q,t,head >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     A      - Area of flow in source channel */
/*     T      - top width of the cross section in source channel */
/*     Q      - flow rate in the source channel */
/*     HEAD - piezometric head on weir crest */
/*     CF     - Hager's side weir function value */
/*     DCFY   - derivative of Hager's weir function wrt depth */
/*     DCFQ   - derivative of Hager's weir function wrt flow */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE exnmat.for:2121 */
/* ********************************************************************** */
/* SOURCE grav.cmn:2 */
/*<       realgrav,twog,halfg >*/
/* SOURCE grav.cmn:4 */
/*<       common/gravcm/grav,twog,halfg >*/
/* SOURCE grav.cmn:5 */
/*<       save/gravcm/ >*/
/* ********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE exnmat.for:2124 */
/*<       realfrw2,tp,tp2,tp3 >*/
/* *********************************************************************** */
/* SOURCE exnmat.for:2126 */
/*<       tp=a*a*head >*/
    tp = static_cast<double>(static_cast<double>(*a) * *a) * *head;
/* SOURCE exnmat.for:2127 */
/*<       frw2=q*q/(grav*tp) >*/
    frw2 = static_cast<double>(static_cast<double>(*q) * *q) / (static_cast<double>(gravcm_1.grav) * tp);
/* SOURCE exnmat.for:2128 */
/*<       tp2=2.+3.*frw2 >*/
    tp2 = static_cast<double>(static_cast<double>(frw2) * (float)3.) + (float)2.;
/* SOURCE exnmat.for:2129 */
/*<       cf=sqrt((2.+frw2)/tp2) >*/
    *cf = sqrt(static_cast<double>((static_cast<double>(frw2) + (float)2.)) / tp2);
/* SOURCE exnmat.for:2130 */
/*<       tp3=(1.-3.*cf**2)/(cf*tp*tp2) >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = *cf;
    tp3 = static_cast<double>((static_cast<double>((float)1.) - static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * (float)3.)) / (static_cast<double>(static_cast<double>(*cf) * tp) * tp2);
/* SOURCE exnmat.for:2132 */
/*<       dcfy=-0.5*frw2*(2.*a*t*head+a**2)*tp3 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = *a;
    *dcfy = static_cast<double>(static_cast<double>(static_cast<double>(frw2) * (float)-.5) * (static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(*a) * (float)2.) * *t) * *head) + static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) * 
	    tp3;
/* SOURCE exnmat.for:2133 */
/*<       dcfq=q*tp3/grav >*/
    *dcfq = static_cast<double>(static_cast<double>(*q) * tp3) / gravcm_1.grav;
/*      WRITE(STDOUT,50) HEAD, A, T, Q, FRW2, CF, DCFY, DCFQ */
/* 50    FORMAT(' FINDCF: HEAD=',F10.5,' A=',F10.4, */
/*     A   ' T=',F10.4,' Q=',F10.4,' FRW2=',1PE12.5, */
/*     B   ' CF=',F10.4,' DCFY=',1PE12.4,' DCFQ=',1PE12.4) */
/* SOURCE exnmat.for:2140 */
/*<       return >*/
    return 0;
/* SOURCE exnmat.for:2141 */
/*<       end >*/
} /* findcf_ */




/* SOURCE exnmat.for:2145 */
/*<       realfunctionfnddq(y1,hg) >*/
doublereal fnddq_(real *y1, real *hg)
{
    /* System generated locals */
    real ret_val;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *);

/*     + + + PURPOSE + + + */
/*     Compute the derivative for free orifice flow. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:2152 */
/*<       realhg,y1 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Y1     - maximum depth upstream of sluice gates */
/*     HG     - sluice gate opening */
/* *********************************************************************** */
/* SOURCE exnmat.for:2158 */
/*<       fnddq=157.89*hg**.91363*(y1-1.)**(-.40437) >*/
    feq_gen_d_d_1 = (doublereal) (*hg);
    feq_gen_d_d_2 = (doublereal) (static_cast<double>(*y1) - (float)1.);
    ret_val = pow_dd(&feq_gen_d_d_1, &c_b170) * (float)157.89 * pow_dd(&feq_gen_d_d_2, &c_b171);
/* SOURCE exnmat.for:2159 */
/*<       return >*/
    return ret_val;
/* SOURCE exnmat.for:2160 */
/*<       end >*/
} /* fnddq_ */




/* SOURCE exnmat.for:2164 */
/*<       realfunctionfndnzm(ipt) >*/
doublereal fndnzm_(integer *ipt)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    real ret_val;

    /* Local variables */
    integer j, n;
    real sum;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))

/*     + + + PURPOSE + + + */
/*     Find the midpoint of the null zone when KEY=QVAR for */
/*     an operation block sense point.  Computes weighted sum of the */
/*     source nodes for the null-zone midpoint given by the */
/*     user. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:2174 */
/*<       integeript >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IPT    - pointer to operation block values in FTAB/ITAB */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE exnmat.for:2180 */
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
/* INCLUDE exnmat.for:2181 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE exnmat.for:2182 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE exnmat.for:2185 */
/*<       integerj,n >*/
/* SOURCE exnmat.for:2186 */
/*<       realsum >*/
/* *********************************************************************** */
/* SOURCE exnmat.for:2188 */
/*<       sum=0.0 >*/
    sum = (float)0.;
/* SOURCE exnmat.for:2189 */
/*<       n=itab(ipt+14) >*/
    n = itab[*ipt + 14];
/* SOURCE exnmat.for:2190 */
/*<       do100j=1,n >*/
    feq_gen_i_d_1 = n;
    for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE exnmat.for:2191 */
/*<       itmp=itab(ipt+13+2*j) >*/
	ftablea_1.itmp = itab[*ipt + 13 + (j << 1)];
/* SOURCE exnmat.for:2192 */
/*<       sum=sum+qe2(itmp)*ftab(ipt+14+2*j) >*/
	sum += static_cast<double>(static_cast<double>(enelem_1.qe2[ftablea_1.itmp - 1]) * ftab[*ipt + 14 + (j << 1)]);
/* SOURCE exnmat.for:2193 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE exnmat.for:2195 */
/*<       fndnzm=sum >*/
    ret_val = sum;
/* SOURCE exnmat.for:2196 */
/*<       return >*/
    return ret_val;
/* SOURCE exnmat.for:2197 */
/*<       end >*/
} /* fndnzm_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE exnmat.for:2201 */
/*<       subroutinefndso(y1,y3,hg,q,dqh1,dqh3) >*/
/* Subroutine */ int fndso_(real *y1, real *y3, real *hg, real *q, real *dqh1,
	 real *dqh3)
{
    /* Initialized data */

    static real eps = (float).01;

    /* System generated locals */
    real feq_gen_r_d_1;

    /* Local variables */
    real dx, ql;
    extern doublereal so_(real *, real *, real *);
    real qr;

/*     + + + PURPOSE + + + */
/*     Find submerged orifice flow and its derivatives. */
/* SOURCE exnmat.for:2208 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:2210 */
/*<       realdqh1,dqh3,hg,q,y1,y3 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Y1     - maximum depth upstream of sluice gates */
/*     Y3     - maximum depth upstream of sluice gates */
/*     HG     - sluice gate opening */
/*     Q      - flow rate */
/*     DQH1   - derivative of flow wrt to upstream head */
/*     DQH3   - derivative of flow wrt to downstream head */
/*     + + + SAVED VALUES + + + */
/* SOURCE exnmat.for:2221 */
/*<       realeps >*/
/* SOURCE exnmat.for:2222 */
/*<       saveeps >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE exnmat.for:2225 */
/*<       realdx,ql,qr >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE exnmat.for:2228 */
/*<       realso >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE exnmat.for:2231 */
/*<       externalso >*/
/*     + + + DATA INITIALIZATIONS + + + */
/* *********************************************************************** */
/* SOURCE exnmat.for:2234 */
/*<       dataeps/.01/ >*/
/* SOURCE exnmat.for:2236 */
/*<       dx=eps*(y1-1.) >*/
    dx = static_cast<double>(eps) * (static_cast<double>(*y1) - (float)1.);
/* SOURCE exnmat.for:2238 */
/*<       q=so(y1,y3,hg) >*/
    *q = so_(y1, y3, hg);
/*     IF THE  GATE OPENING AND TAILWATER ARE HELD CONSTANT AND */
/*     WE ALREADY HAVE SUBMERGED ORIFICE FLOW, THEN A DECREASE IN */
/*     HEADWATER HEAD MAINTAINS SUBMERGED ORIFICE FLOW. */
/* SOURCE exnmat.for:2244 */
/*<       if(y1-dx.le.y3)then >*/
    if (static_cast<double>(*y1) - dx <= *y3) {
/* SOURCE exnmat.for:2245 */
/*<       dx=.7*(y1-y3) >*/
	dx = static_cast<double>((static_cast<double>(*y1) - *y3)) * (float).7;
/* SOURCE exnmat.for:2246 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:2248 */
/*<       ql=so(y1-dx,y3,hg) >*/
    feq_gen_r_d_1 = static_cast<double>(*y1) - dx;
    ql = so_(&feq_gen_r_d_1, y3, hg);
/* SOURCE exnmat.for:2249 */
/*<       dqh1=(q-ql)/dx >*/
    *dqh1 = static_cast<double>((static_cast<double>(*q) - ql)) / dx;
/* SOURCE exnmat.for:2251 */
/*<       dx=eps*(y3-1.) >*/
    dx = static_cast<double>(eps) * (static_cast<double>(*y3) - (float)1.);
/*     IF THE GATE OPENING AND THE HEADWATER HEAD ARE CONSTANT AND */
/*     WE  ALREADY HAVE SUBMERGED ORIFICE FLOW, THEN AN INCREASE IN */
/*     THE TAILWATER HEAD MAINTAINS SUBMERGED ORIFICE FLOW. */
/* SOURCE exnmat.for:2257 */
/*<       if(y3+dx.ge.y1)then >*/
    if (static_cast<double>(*y3) + dx >= *y1) {
/* SOURCE exnmat.for:2258 */
/*<       dx=.7*(y1-y3) >*/
	dx = static_cast<double>((static_cast<double>(*y1) - *y3)) * (float).7;
/* SOURCE exnmat.for:2259 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:2261 */
/*<       qr=so(y1,y3+dx,hg) >*/
    feq_gen_r_d_1 = static_cast<double>(*y3) + dx;
    qr = so_(y1, &feq_gen_r_d_1, hg);
/* SOURCE exnmat.for:2263 */
/*<       dqh3=(qr-q)/dx >*/
    *dqh3 = static_cast<double>((static_cast<double>(qr) - *q)) / dx;
/* SOURCE exnmat.for:2265 */
/*<       return >*/
    return 0;
/* SOURCE exnmat.for:2266 */
/*<       end >*/
} /* fndso_ */




/* SOURCE exnmat.for:2270 */
/*<       realfunctionfo(h1,hg) >*/
doublereal fo_(real *h1, real *hg)
{
    /* System generated locals */
    real ret_val;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *);

/*     + + + PURPOSE + + + */
/*     Compute free orifice flow. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:2277 */
/*<       realh1,hg >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     H1     - upstream head */
/*     HG     - sluice gate opening */
/* *********************************************************************** */
/*      DISABLED STATEMENT FUNCTIONS. */
/*      A(Y) = 403.5 + Y*(144. + Y*2.75) */
/*      C(HH,HHG) = .66516 + (HHG/HH)*(-.4525 + .70985*(HHG/HH)) */
/*      CON = C(H1,HG) */
/*      D = 1.0/(CON*HG*BG)**2 - ALPHA/A(H1 + 1)**2 */
/*      FO = SQRT(2.*G*(H1 - CON*HG)/D) */
/* SOURCE exnmat.for:2292 */
/*<       fo=265.082*hg**.91363*h1**.59563 >*/
    feq_gen_d_d_1 = (doublereal) (*hg);
    feq_gen_d_d_2 = (doublereal) (*h1);
    ret_val = pow_dd(&feq_gen_d_d_1, &c_b170) * (float)265.082 * pow_dd(&feq_gen_d_d_2, &c_b177)
	    ;
/* SOURCE exnmat.for:2294 */
/*<       return >*/
    return ret_val;
/* SOURCE exnmat.for:2295 */
/*<       end >*/
} /* fo_ */




/* SOURCE exnmat.for:2299 */
/*<       realfunctionfobdy(qfo,y1,hg) >*/
doublereal fobdy_(real *qfo, real *y1, real *hg)
{
    /* Initialized data */

    static real w = (float)96.;
    static real bg = (float)68.75;
    static real a0 = (float)299.5;
    static real g = (float)32.2;
    static real beta = (float)1.2373;

    /* System generated locals */
    real ret_val, feq_gen_r_d_1, feq_gen_r_d_2;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *), sqrt(doublereal);

    /* Local variables */
    real p, a3, y2, ag, div, res, y1lim, y3est;

/*     + + + PURPOSE + + + */
/*     Find the value of Y3, Y3STAR, giving the depth at the end of the */
/*     exit reach when the flow is at the boundary between free and */
/*     submerged flow. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:2308 */
/*<       realhg,qfo,y1 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     QFO    - free orifice flow */
/*     Y1     - maximum depth upstream of sluice gates */
/*     HG     - sluice gate opening */
/*     + + + SAVED VALUES + + + */
/* SOURCE exnmat.for:2316 */
/*<       reala0,beta,bg,g,w >*/
/* SOURCE exnmat.for:2317 */
/*<       savea0,beta,bg,g,w >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE exnmat.for:2320 */
/*<       reala3,ag,div,hh,hhg,p,res,x,y1lim,y2,y3est >*/
/*     + + + INTRINSICS + + + */
/* SOURCE exnmat.for:2323 */
/*<       intrinsicsqrt >*/
/*     + + + STATEMENT FUNCTION TYPES + + + */
/* SOURCE exnmat.for:2326 */
/*<       realc,fl,fm,fr >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + STATEMENT FUNCTION DEFINITIONS + + + */
/* SOURCE exnmat.for:2329 */
/*<       dataw/96.0/,bg/68.75/,a0/299.5/,g/32.2/beta/1.2373/ >*/
/* SOURCE exnmat.for:2333 */
/*<       c(hh,hhg)=.66516+(hhg/hh)*(-.4525+.70985*(hhg/hh)) >*/
/* SOURCE exnmat.for:2334 */
/*<       fl(x)=1.1391+x*(1.2673-.0131*x)-.3682*x**.3 >*/
/* SOURCE exnmat.for:2335 */
/*<       fm(x)=.6352+x*(.2094+.0159*x)+2.1218*sqrt(x) >*/
/* SOURCE exnmat.for:2336 */
/*<       fr(x)=.9778+x*(-1.6271+.0268*x)+4.422*x**.7 >*/
/* *********************************************************************** */
/*     STATEMENT FUNCTIONS */
/*      FL(X) = 1.141 + X*(1.2569 - .0128*X) - .3668*X**.3 */
/*      FM(X) = .7184 + X*(.2805 + .0116*X) + 1.97*SQRT(X) */
/*      FR(X) = .8279 + X*(-2.1345 + .052*X) + 5.0789*X**.7 */
/*     COMPUTE THE LOWER LIMIT FOR Y1 FOR FREE ORIFICE FLOW */
/*     USED IN FITTING THE EQUATIONS */
/* SOURCE exnmat.for:2349 */
/*<       y1lim=1.3*hg+1 >*/
    y1lim = static_cast<double>(static_cast<double>((float)1.3) * *hg) + 1;
/*     COMPUTE RELATIVE POSITION RELATIVE TO THE MIDDLE FUNCTION OF */
/*     GATE OPENING.  MAXIMUM VALUE OF Y1 USED IN DEFINING THE */
/*     FUNCTIONS WAS 9 FEET. */
/* SOURCE exnmat.for:2355 */
/*<       p=2.*(y1-y1lim)/(9.-y1lim)-1 >*/
    p = static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>(*y1) - y1lim)) * (float)2.) / (static_cast<double>((float)9.) - y1lim)) - 1;
/*     COMPUTE ESTIMATE FOR Y3STAR USING THE FITTED FUNCTIONS */
/* SOURCE exnmat.for:2359 */
/*<       y3est=.5*p*(p-1)*fl(hg)+(1-p*p)*fm(hg)+.5*p*(p+1)*fr(hg) >*/
    feq_gen_d_d_1 = (doublereal) (*hg);
    feq_gen_d_d_2 = (doublereal) (*hg);
    y3est = static_cast<double>(static_cast<double>(p) * (float).5) * (static_cast<double>(p) - 1) * (static_cast<double>((float)1.1391) + static_cast<double>(*hg) * (static_cast<double>((float)1.2673) - 
	    static_cast<double>((float).0131) * *hg) - (float).3682 * pow_dd(&feq_gen_d_d_1, &c_b179)) + (static_cast<double>(1) 
	    - static_cast<double>(p) * p) * (static_cast<double>((float).6352) + static_cast<double>(*hg) * (static_cast<double>((float).2094) + static_cast<double>((float).0159) * *
	    hg) + (float)2.1218 * sqrt(*hg)) + static_cast<double>(static_cast<double>(p) * (float).5) * (static_cast<double>(p) + 1) * (static_cast<double>((
	    float).9778) + static_cast<double>(*hg) * (static_cast<double>((float)-1.6271) + static_cast<double>((float).0268) * *hg) + (
	    float)4.422 * pow_dd(&feq_gen_d_d_2, &c_b180));
/*     APPLY TWO ITERATIONS OF NEWTON'S METHOD TO REFINE THE ESTIMATE. */
/* SOURCE exnmat.for:2364 */
/*<       a3=a0+w*y3est >*/
    a3 = static_cast<double>(a0) + static_cast<double>(w) * y3est;
/* SOURCE exnmat.for:2365 */
/*<       y2=c(y1-1,hg)*hg >*/
    feq_gen_r_d_1 = static_cast<double>(*y1) - 1;
    y2 = static_cast<double>((static_cast<double>((float).66516) + static_cast<double>(static_cast<double>(*hg) / feq_gen_r_d_1) * (static_cast<double>((float)-.4525) + static_cast<double>((float).70985) * (static_cast<double>(*hg) /
	     feq_gen_r_d_1)))) * *hg;
/* SOURCE exnmat.for:2366 */
/*<       ag=y2*bg >*/
    ag = static_cast<double>(y2) * bg;
/* SOURCE exnmat.for:2367 */
/*<       y2=y2+1 >*/
    y2 += 1;
/* SOURCE exnmat.for:2369 */
/*<       res=qfo**2*(1/ag-beta/a3)+.5*g*w*(y2-y3est)*(y2+y3est) >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = *qfo;
    res = static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * (static_cast<double>(static_cast<double>(1) / ag) - static_cast<double>(beta) / a3)) + static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(g) * (float).5) * w) * (static_cast<double>(y2) - 
	    y3est)) * (static_cast<double>(y2) + y3est);
/* SOURCE exnmat.for:2371 */
/*<       div=w*(beta*qfo**2/a3**2-g*y3est) >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = *qfo;
/* Computing 2nd power */
    feq_gen_r_d_2 = a3;
    div = static_cast<double>(w) * (static_cast<double>(static_cast<double>(static_cast<double>(beta) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) - static_cast<double>(g) * y3est);
/* SOURCE exnmat.for:2373 */
/*<       y3est=y3est-res/div >*/
    y3est -= static_cast<double>(res) / div;
/* SOURCE exnmat.for:2375 */
/*<       a3=a0+w*y3est >*/
    a3 = static_cast<double>(a0) + static_cast<double>(w) * y3est;
/* SOURCE exnmat.for:2376 */
/*<       res=qfo**2*(1/ag-beta/a3)+.5*g*w*(y2-y3est)*(y2+y3est) >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = *qfo;
    res = static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * (static_cast<double>(static_cast<double>(1) / ag) - static_cast<double>(beta) / a3)) + static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(g) * (float).5) * w) * (static_cast<double>(y2) - 
	    y3est)) * (static_cast<double>(y2) + y3est);
/* SOURCE exnmat.for:2378 */
/*<       fobdy=y3est-res/div >*/
    ret_val = static_cast<double>(y3est) - static_cast<double>(res) / div;
/* SOURCE exnmat.for:2380 */
/*<       return >*/
    return ret_val;
/* SOURCE exnmat.for:2381 */
/*<       end >*/
} /* fobdy_ */




/* SOURCE exnmat.for:2385 */
/*<       subroutinefw(h1,qfw,dqfw) >*/
/* Subroutine */ int fw_(real *h1, real *qfw, real *dqfw)
{
    /* System generated locals */
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *);

/*     + + + PURPOSE + + + */
/*     Compute free weir flow. */
/* SOURCE exnmat.for:2392 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:2394 */
/*<       realdqfw,h1,qfw >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     H1     - upstream head */
/*     QFW    - free weir flow */
/*     DQFW   - derivative of flow wrt to head for free weir flow */
/* *********************************************************************** */
/* SOURCE exnmat.for:2401 */
/*<       qfw=213.82*h1**1.50942 >*/
    feq_gen_d_d_1 = (doublereal) (*h1);
    *qfw = pow_dd(&feq_gen_d_d_1, &c_b182) * (float)213.82;
/* SOURCE exnmat.for:2403 */
/*<       dqfw=322.74*h1**(.50942) >*/
    feq_gen_d_d_1 = (doublereal) (*h1);
    *dqfw = pow_dd(&feq_gen_d_d_1, &c_b183) * (float)322.74;
/* SOURCE exnmat.for:2405 */
/*<       return >*/
    return 0;
/* SOURCE exnmat.for:2406 */
/*<       end >*/
} /* fw_ */




/* SOURCE exnmat.for:2410 */
/*<       realfunctionfwbdy(h,hg) >*/
doublereal fwbdy_(real *feq_gen_h_d_, real *hg)
{
    /* System generated locals */
    real ret_val, feq_gen_r_d_1;

    /* Local variables */
    extern doublereal fo_(real *, real *);
    real qfo, h1lim;
    extern doublereal fobdy_(real *, real *, real *);
    real h3star;

/*     + + + PURPOSE + + + */
/*     Compute the boundary between free weir and submerged weir flow. */
/*     Base on the orifice submergence relationship because they are */
/*     so close.  Eliminates some abrupt transitions. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:2419 */
/*<       realh,hg >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     H      - head */
/*     HG     - sluice gate opening */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE exnmat.for:2426 */
/*<       realh1lim,h3star,qfo >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE exnmat.for:2429 */
/*<       realfo,fobdy >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE exnmat.for:2432 */
/*<       externalfo,fobdy >*/
/* *********************************************************************** */
/*      FWBDY = H*(.6963918 + H*(.1831125 + H*(-.0636758 + */
/*     A          H*(.0096066 + H*(-.000527))))) */
/* SOURCE exnmat.for:2437 */
/*<       h1lim=1.265*hg >*/
    h1lim = static_cast<double>(*hg) * (float)1.265;
/* SOURCE exnmat.for:2438 */
/*<       qfo=fo(h1lim,hg) >*/
    qfo = fo_(&h1lim, hg);
/* SOURCE exnmat.for:2439 */
/*<       h3star=fobdy(qfo,h1lim+1,hg)-1 >*/
    feq_gen_r_d_1 = static_cast<double>(h1lim) + 1;
    h3star = fobdy_(&qfo, &feq_gen_r_d_1, hg) - 1;
/* SOURCE exnmat.for:2441 */
/*<       fwbdy=h*h3star/h1lim >*/
    ret_val = static_cast<double>(static_cast<double>(*feq_gen_h_d_) * h3star) / h1lim;
/* SOURCE exnmat.for:2443 */
/*<       return >*/
    return ret_val;
/* SOURCE exnmat.for:2444 */
/*<       end >*/
} /* fwbdy_ */




/* SOURCE exnmat.for:2448 */
/*<       subroutinemchen(h1,h3,hg,q,dqh1,dqh3) >*/
/* Subroutine */ int mchen_(real *h1, real *h3, real *hg, real *q, real *dqh1,
	 real *dqh3)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    real y1, y2, y3;
    extern doublereal fo_(real *, real *);
    extern /* Subroutine */ int fw_(real *, real *, real *), sw_(real *, real 
	    *, real *, real *, real *, real *, real *, real *);
    real qfo, qfw;
    extern doublereal soy2_(real *, real *, real *);
    real dqfw;
    extern doublereal fnddq_(real *, real *), fobdy_(real *, real *, real *), 
	    fwbdy_(real *, real *);
    extern /* Subroutine */ int fndso_(real *, real *, real *, real *, real *,
	     real *);
    real h1star, h3star, y3star;

/*     + + + PURPOSE + + + */
/*     Compute the flow at the McHenry sluice gates. */
/* SOURCE exnmat.for:2455 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:2457 */
/*<       realdqh1,dqh3,h1,h3,hg,q >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     H1     - upstream head */
/*     H3     - head immediately below sluice gates */
/*     HG     - sluice gate opening */
/*     Q      - flow rate */
/*     DQH1   - derivative of flow wrt to upstream head */
/*     DQH3   - derivative of flow wrt to downstream head */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE exnmat.for:2468 */
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
/* INCLUDE exnmat.for:2469 */
/*     Used for output of Mc Henry gate information */
/* SOURCE mhenry.cmn:3 */
/*<       integertypmch >*/
/* SOURCE mhenry.cmn:4 */
/*<       realhgmch >*/
/* SOURCE mhenry.cmn:5 */
/*<       common/mhenry/typmch,hgmch >*/
/* INCLUDE exnmat.for:2470 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE exnmat.for:2474 */
/*<       realdqfw,h1star,h3star,qfo,qfw,y1,y2,y3,y3star >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE exnmat.for:2477 */
/*<       realfnddq,fo,fobdy,fwbdy,soy2 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE exnmat.for:2480 */
/*<       externalfnddq,fndso,fo,fobdy,fw,fwbdy,soy2,sw >*/
/* *********************************************************************** */
/*      TYPMCH          FLOW TYPE */
/*          0            Q=0 */
/*          1            FO */
/*          2            SO */
/*          3            FW */
/*          4            SW */
/* SOURCE exnmat.for:2489 */
/*<       typmch=0 >*/
    mhenry_1.typmch = 0;
/* SOURCE exnmat.for:2490 */
/*<       hgmch=hg >*/
    mhenry_1.hgmch = *hg;
/* SOURCE exnmat.for:2491 */
/*<       gopen(mngate+1)=hg >*/
    gate1_1.gopen[51] = *hg;
/*     CATCH LIMITING CASES */
/* SOURCE exnmat.for:2493 */
/*<       if(h1.le.0.0)then >*/
    if (*h1 <= (float)0.) {
/* SOURCE exnmat.for:2494 */
/*<       q=0.0 >*/
	*q = (float)0.;
/* SOURCE exnmat.for:2495 */
/*<       dqh1=0.0 >*/
	*dqh1 = (float)0.;
/* SOURCE exnmat.for:2496 */
/*<       dqh3=0.0 >*/
	*dqh3 = (float)0.;
/* SOURCE exnmat.for:2497 */
/*<       fclass(mngate+1)='No Flow' >*/
	s_copy(gate2_1.fclass + 408, const_cast<char*>("No Flow"), (ftnlen)8, (ftnlen)7);
/* SOURCE exnmat.for:2498 */
/*<       fclass_code(mngate+1)=3 >*/
	gate1_1.feq_gen_fclass_code_d_[51] = 3;
/* SOURCE exnmat.for:2499 */
/*<       return >*/
	return 0;
/* SOURCE exnmat.for:2500 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:2501 */
/*<       if(h3.ge.h1)then >*/
    if (*h3 >= *h1) {
/* SOURCE exnmat.for:2502 */
/*<       q=0.0 >*/
	*q = (float)0.;
/* SOURCE exnmat.for:2503 */
/*<       dqh1=0.0 >*/
	*dqh1 = (float)0.;
/* SOURCE exnmat.for:2504 */
/*<       dqh3=0.0 >*/
	*dqh3 = (float)0.;
/* SOURCE exnmat.for:2505 */
/*<       fclass(mngate+1)='No Flow' >*/
	s_copy(gate2_1.fclass + 408, const_cast<char*>("No Flow"), (ftnlen)8, (ftnlen)7);
/* SOURCE exnmat.for:2506 */
/*<       fclass_code(mngate+1)=3 >*/
	gate1_1.feq_gen_fclass_code_d_[51] = 3;
/* SOURCE exnmat.for:2507 */
/*<       return >*/
	return 0;
/* SOURCE exnmat.for:2508 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:2510 */
/*<       if(hg.le.0.0)then >*/
    if (*hg <= (float)0.) {
/* SOURCE exnmat.for:2511 */
/*<       q=0.0 >*/
	*q = (float)0.;
/* SOURCE exnmat.for:2512 */
/*<       dqh1=0.0 >*/
	*dqh1 = (float)0.;
/* SOURCE exnmat.for:2513 */
/*<       dqh3=0.0 >*/
	*dqh3 = (float)0.;
/* SOURCE exnmat.for:2514 */
/*<       hgmch=0.0 >*/
	mhenry_1.hgmch = (float)0.;
/* SOURCE exnmat.for:2515 */
/*<       fclass(mngate+1)='Closed' >*/
	s_copy(gate2_1.fclass + 408, const_cast<char*>("Closed"), (ftnlen)8, (ftnlen)6);
/* SOURCE exnmat.for:2516 */
/*<       fclass_code(mngate+1)=3 >*/
	gate1_1.feq_gen_fclass_code_d_[51] = 3;
/* SOURCE exnmat.for:2517 */
/*<       return >*/
	return 0;
/* SOURCE exnmat.for:2518 */
/*<       endif >*/
    }
/*     DEFINE DEPTHS FOR LATER USE */
/* SOURCE exnmat.for:2523 */
/*<       y1=h1+1. >*/
    y1 = static_cast<double>(*h1) + (float)1.;
/* SOURCE exnmat.for:2524 */
/*<       y3=h3+1. >*/
    y3 = static_cast<double>(*h3) + (float)1.;
/*     IS THE FLOW ORIFICE OR WEIR? */
/* SOURCE exnmat.for:2528 */
/*<       h1star=1.265*hg >*/
    h1star = static_cast<double>(*hg) * (float)1.265;
/* SOURCE exnmat.for:2529 */
/*<       if(h1.gt.h1star)then >*/
    if (*h1 > h1star) {
/*       FLOW IS ORIFICE.  ASSUME FLOW IS FREE. */
/* SOURCE exnmat.for:2533 */
/*<       qfo=fo(h1,hg) >*/
	qfo = fo_(h1, hg);
/*       COMPUTE THE VALUE OF Y3 WHICH IS AT THE FREE FLOW BOUNDARY */
/* SOURCE exnmat.for:2537 */
/*<       y3star=fobdy(qfo,y1,hg) >*/
	y3star = fobdy_(&qfo, &y1, hg);
/* SOURCE exnmat.for:2539 */
/*<       if(y3.gt.y3star)then >*/
	if (y3 > y3star) {
/*         SUBMERGED ORIFICE */
/* SOURCE exnmat.for:2541 */
/*<       callfndso(y1,y3,hg,q,dqh1,dqh3) >*/
	    fndso_(&y1, &y3, hg, q, dqh1, dqh3);
/*          TYPE = '  SO' */
/* SOURCE exnmat.for:2545 */
/*<       typmch=2 >*/
	    mhenry_1.typmch = 2;
/* SOURCE exnmat.for:2546 */
/*<       fclass(mngate+1)='SO' >*/
	    s_copy(gate2_1.fclass + 408, const_cast<char*>("SO"), (ftnlen)8, (ftnlen)2);
/* SOURCE exnmat.for:2547 */
/*<       fclass_code(mngate+1)=12 >*/
	    gate1_1.feq_gen_fclass_code_d_[51] = 12;
/* SOURCE exnmat.for:2548 */
/*<       else >*/
	} else {
/*         FREE ORIFICE */
/*          TYPE = '  FO' */
/* SOURCE exnmat.for:2551 */
/*<       typmch=1 >*/
	    mhenry_1.typmch = 1;
/* SOURCE exnmat.for:2552 */
/*<       fclass(mngate+1)='FO' >*/
	    s_copy(gate2_1.fclass + 408, const_cast<char*>("FO"), (ftnlen)8, (ftnlen)2);
/* SOURCE exnmat.for:2553 */
/*<       fclass_code(mngate+1)=11 >*/
	    gate1_1.feq_gen_fclass_code_d_[51] = 11;
/* SOURCE exnmat.for:2554 */
/*<       q=qfo >*/
	    *q = qfo;
/* SOURCE exnmat.for:2555 */
/*<       dqh3=0.0 >*/
	    *dqh3 = (float)0.;
/* SOURCE exnmat.for:2556 */
/*<       dqh1=fnddq(y1,hg) >*/
	    *dqh1 = fnddq_(&y1, hg);
/* SOURCE exnmat.for:2557 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:2558 */
/*<       else >*/
    } else {
/*       WEIR FLOW. */
/*       WEIR FLOW */
/* SOURCE exnmat.for:2562 */
/*<       callfw(h1,qfw,dqfw) >*/
	fw_(h1, &qfw, &dqfw);
/* SOURCE exnmat.for:2565 */
/*<       q=qfw >*/
	*q = qfw;
/* SOURCE exnmat.for:2566 */
/*<       dqh1=dqfw >*/
	*dqh1 = dqfw;
/* SOURCE exnmat.for:2567 */
/*<       dqh3=0.0 >*/
	*dqh3 = (float)0.;
/*        TYPE = '  FW' */
/* SOURCE exnmat.for:2569 */
/*<       typmch=3 >*/
	mhenry_1.typmch = 3;
/* SOURCE exnmat.for:2570 */
/*<       fclass(mngate+1)='FW' >*/
	s_copy(gate2_1.fclass + 408, const_cast<char*>("FW"), (ftnlen)8, (ftnlen)2);
/* SOURCE exnmat.for:2571 */
/*<       fclass_code(mngate+1)=2 >*/
	gate1_1.feq_gen_fclass_code_d_[51] = 2;
/*       CHECK FOR SUBMERGENCE */
/* SOURCE exnmat.for:2574 */
/*<       h3star=fwbdy(h1,hg) >*/
	h3star = fwbdy_(h1, hg);
/* SOURCE exnmat.for:2576 */
/*<       if(h3.gt.h3star)then >*/
	if (*h3 > h3star) {
/* SOURCE exnmat.for:2577 */
/*<       if(h1.gt.hg.and.h3.gt.hg)then >*/
	    if (*h1 > *hg && *h3 > *hg) {
/*           FLOW MIGHT BE SUBMERGED ORIFICE.  SOY2 COMPUTES THE DEPTH */
/*           AT SECTION 2 ASSUMING SUBMERGED ORIFICE FLOW AND CHECKS */
/*           TO SEE IF IT IS VALID.  IF VALID, SOY2 RETURNS Y2 > 0 */
/*           GIVING THE DEPTH. */
/* SOURCE exnmat.for:2583 */
/*<       y2=soy2(y1,y3,hg) >*/
		y2 = soy2_(&y1, &y3, hg);
/* SOURCE exnmat.for:2584 */
/*<       if(y2.gt.0.0)then >*/
		if (y2 > (float)0.) {
/*             ASSUME THAT THE FLOW IS SUBMERGED ORIFICE. */
/* SOURCE exnmat.for:2586 */
/*<       callfndso(y1,y3,hg,q,dqh1,dqh3) >*/
		    fndso_(&y1, &y3, hg, q, dqh1, dqh3);
/*              TYPE = '  SO' */
/* SOURCE exnmat.for:2590 */
/*<       typmch=2 >*/
		    mhenry_1.typmch = 2;
/* SOURCE exnmat.for:2591 */
/*<       fclass(mngate+1)='SO' >*/
		    s_copy(gate2_1.fclass + 408, const_cast<char*>("SO"), (ftnlen)8, (ftnlen)2);
/* SOURCE exnmat.for:2592 */
/*<       fclass_code(mngate+1)=12 >*/
		    gate1_1.feq_gen_fclass_code_d_[51] = 12;
/* SOURCE exnmat.for:2593 */
/*<       else >*/
		} else {
/*             ASSUME SUBMERGED WEIR FLOW */
/*              TYPE = '  SW' */
/* SOURCE exnmat.for:2596 */
/*<       typmch=4 >*/
		    mhenry_1.typmch = 4;
/* SOURCE exnmat.for:2597 */
/*<       fclass(mngate+1)='SW' >*/
		    s_copy(gate2_1.fclass + 408, const_cast<char*>("SW"), (ftnlen)8, (ftnlen)2);
/* SOURCE exnmat.for:2598 */
/*<       fclass_code(mngate+1)=1 >*/
		    gate1_1.feq_gen_fclass_code_d_[51] = 1;
/* SOURCE exnmat.for:2599 */
/*<       callsw(h1,qfw,dqfw,h3,h3star,q,dqh1,dqh3) >*/
		    sw_(h1, &qfw, &dqfw, h3, &h3star, q, dqh1, dqh3);
/* SOURCE exnmat.for:2602 */
/*<       endif >*/
		}
/* SOURCE exnmat.for:2603 */
/*<       else >*/
	    } else {
/*           FLOW IS SUBMERGED WEIR */
/*            TYPE = '  SW' */
/* SOURCE exnmat.for:2606 */
/*<       typmch=4 >*/
		mhenry_1.typmch = 4;
/* SOURCE exnmat.for:2607 */
/*<       fclass(mngate+1)='SW' >*/
		s_copy(gate2_1.fclass + 408, const_cast<char*>("SW"), (ftnlen)8, (ftnlen)2);
/* SOURCE exnmat.for:2608 */
/*<       fclass_code(mngate+1)=1 >*/
		gate1_1.feq_gen_fclass_code_d_[51] = 1;
/* SOURCE exnmat.for:2609 */
/*<       callsw(h1,qfw,dqfw,h3,h3star,q,dqh1,dqh3) >*/
		sw_(h1, &qfw, &dqfw, h3, &h3star, q, dqh1, dqh3);
/* SOURCE exnmat.for:2612 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:2613 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:2614 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:2616 */
/*<       return >*/
    return 0;
/* SOURCE exnmat.for:2617 */
/*<       end >*/
} /* mchen_ */




/* SOURCE exnmat.for:2621 */
/*<        >*/
/* Subroutine */ int mchgat_(integer *ipnt, integer *feq_storage_emc, integer *mlemc, 
	real *feq_storage_ye2, real *feq_storage_ze, real *feq_storage_qe2, integer *nex, integer *stdout, 
	doublereal *jtime, real *res, real *pyl, real *pql, real *pyr, real *
	pqr)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:64* Table Id=\002,a,\002 has invali\
d values for\002,\002 structure setting.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];
    static real equiv_0[1];

    /* Builtin functions */
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    real feq_gen_d_d_, feq_gen_h_d_;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real hg;
    integer dnn, qnn, unn;
    real qfac;
    integer ntab;
#define idum (feq::BitView<integer>(equiv_0, sizeof(equiv_0)))
#define rdum (equiv_0)
    real disch, zhead;
    extern /* Subroutine */ int mchen_(real *, real *, real *, real *, real *,
	     real *);
    real dtime;
    integer sysgn, opcode;
    real maxgat;
    extern /* Subroutine */ int lktstab_(integer *, doublereal *, real *, 
	    integer *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__354 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Sluice gates at McHenry dam Fox River Illinois.  Flow is */
/*     always downstream.  No reverse flow permitted. */
/* SOURCE exnmat.for:2630 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:2632 */
/*<       integeripnt,stdout,mlemc,nex >*/
/* SOURCE exnmat.for:2633 */
/*<       integeremc(mlemc) >*/
/* SOURCE exnmat.for:2634 */
/*<       realpql,pqr,pyl,pyr,qe2(nex),res,ye2(nex),ze(nex) >*/
/* SOURCE exnmat.for:2635 */
/*<       real*8jtime >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IPNT   - pointer into EMC for description of control structure */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     MLEMC  - maximum length of EMC(*) */
/*     YE2    - depths at exterior nodes at end of time step */
/*     ZE     - elevation of datum for depth at exterior node */
/*     QE2    - flow at exterior nodes at end of time step */
/*     NEX    - number of exterior nodes in the model */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     TIME   - elapsed time in seconds from start of run */
/*     RES    - value of the residual function */
/*     PYL    - partial derivative of residual function wrt depth at */
/*               left node */
/*     PQL    - partial derivative of residual function wrt flow at left */
/*               node */
/*     PYR    - partial derivative of residual function wrt depth at */
/*               right node */
/*     PQR    - partial derivative of residual function wrt flow at right */
/*               node */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE exnmat.for:2658 */
/*<       integerdnn,idum,ntab,opcode,qnn,sysgn,unn >*/
/* SOURCE exnmat.for:2659 */
/*<       reald,disch,dtime,h,hg,maxgat,qfac,rdum,zhead >*/
/*     + + + EQUIVALENCES + + + */
/* SOURCE exnmat.for:2662 */
/*<       equivalence(idum,rdum) >*/
/*     + + + INTRINSICS + + + */
/* SOURCE exnmat.for:2665 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE exnmat.for:2668 */
/*<       characterget_tabid*16 >*/
/* SOURCE exnmat.for:2669 */
/*<       externallktab,mchen,get_tabid >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE exnmat.for:2672 */
/*<    50  >*/
/* *********************************************************************** */
/*     OBTAIN BASIC INFORMATION FROM EMC */
/* SOURCE exnmat.for:2677 */
/*<       unn=emc(ipnt+2) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    feq::IndexedPointer<real> qe2(feq_storage_qe2, 1);

    feq::IndexedPointer<real> ze(feq_storage_ze, 1);

    feq::IndexedPointer<real> ye2(feq_storage_ye2, 1);

    /* Function Body */
/* L50: */
    unn = emc[*ipnt + 2];
/* SOURCE exnmat.for:2678 */
/*<       dnn=emc(ipnt+3) >*/
    dnn = emc[*ipnt + 3];
/* SOURCE exnmat.for:2679 */
/*<       qnn=emc(ipnt+4) >*/
    qnn = emc[*ipnt + 4];
/* SOURCE exnmat.for:2680 */
/*<       sysgn=emc(ipnt+5) >*/
    sysgn = emc[*ipnt + 5];
/* SOURCE exnmat.for:2681 */
/*<       opcode=emc(ipnt+6) >*/
    opcode = emc[*ipnt + 6];
/* SOURCE exnmat.for:2682 */
/*<       idum=emc(ipnt+8) >*/
    *idum = emc[*ipnt + 8];
/* SOURCE exnmat.for:2683 */
/*<       zhead=rdum >*/
    zhead = *rdum;
/* SOURCE exnmat.for:2684 */
/*<       idum=emc(ipnt+9) >*/
    *idum = emc[*ipnt + 9];
/* SOURCE exnmat.for:2685 */
/*<       maxgat=rdum >*/
    maxgat = *rdum;
/* SOURCE exnmat.for:2686 */
/*<       idum=emc(ipnt+12) >*/
    *idum = emc[*ipnt + 12];
/* SOURCE exnmat.for:2687 */
/*<       qfac=rdum >*/
    qfac = *rdum;
/*     DEFINE THE GATE OPENING FOR THIS TIME SETP */
/* SOURCE exnmat.for:2691 */
/*<       if(opcode.gt.0)then >*/
    if (opcode > 0) {
/*       OPERATION BLOCK HAS ALREADY SET THE OPENING FRACTION */
/* SOURCE exnmat.for:2694 */
/*<       idum=emc(ipnt+10) >*/
	*idum = emc[*ipnt + 10];
/* SOURCE exnmat.for:2695 */
/*<       hg=maxgat*rdum >*/
	hg = static_cast<double>(maxgat) * *rdum;
/* SOURCE exnmat.for:2696 */
/*<       else >*/
    } else {
/*       LOOK UP VALUE IN TABLE BASED ON TIME AT START OF THE CURRENT */
/*       STEP */
/* SOURCE exnmat.for:2700 */
/*<       calllktstab(abs(opcode),jtime,hg,ntab,dtime) >*/
	feq_gen_i_d_1 = abs(opcode);
	lktstab_(&feq_gen_i_d_1, jtime, &hg, &ntab, &dtime);
/* SOURCE exnmat.for:2703 */
/*<       if(hg.lt.0.0.or.hg.gt.maxgat)then >*/
	if (hg < (float)0. || hg > maxgat) {
/* SOURCE exnmat.for:2704 */
/*<       write(stdout,50)get_tabid(ntab) >*/
	    feq_gen_io_d__354.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__354);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &ntab);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    e_wsfe();
/* SOURCE exnmat.for:2705 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE exnmat.for:2706 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:2707 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:2709 */
/*<       h=ye2(unn)+ze(unn)-zhead >*/
    feq_gen_h_d_ = static_cast<double>(static_cast<double>(ye2[unn]) + ze[unn]) - zhead;
/* SOURCE exnmat.for:2710 */
/*<       d=ye2(dnn)+ze(dnn)-zhead >*/
    feq_gen_d_d_ = static_cast<double>(static_cast<double>(ye2[dnn]) + ze[dnn]) - zhead;
/*     VELOCITY HEAD IS IMPLICIT IN THE RELATIONSHIPS INTERNAL TO */
/*     SUBROUTINE MCHEN().  MCHEN ALSO SETS THE DERIVATIVES FOR */
/*     REVERSE FLOW. */
/* SOURCE exnmat.for:2716 */
/*<       pqr=0.0 >*/
    *pqr = (float)0.;
/* SOURCE exnmat.for:2717 */
/*<       pql=0.0 >*/
    *pql = (float)0.;
/* SOURCE exnmat.for:2719 */
/*<       callmchen(h,d,hg,disch,pyl,pyr) >*/
    mchen_(&feq_gen_h_d_, &feq_gen_d_d_, &hg, &disch, pyl, pyr);
/* SOURCE exnmat.for:2722 */
/*<       if(qfac.ne.1.0)then >*/
    if (qfac != (float)1.) {
/* SOURCE exnmat.for:2723 */
/*<       disch=qfac*disch >*/
	disch = static_cast<double>(qfac) * disch;
/* SOURCE exnmat.for:2724 */
/*<       pyl=qfac*pyl >*/
	*pyl = static_cast<double>(qfac) * *pyl;
/* SOURCE exnmat.for:2725 */
/*<       pyr=qfac*pyr >*/
	*pyr = static_cast<double>(qfac) * *pyr;
/* SOURCE exnmat.for:2726 */
/*<       endif >*/
    }
/*     APPLY EFFECT OF SYSGN VALUES */
/* SOURCE exnmat.for:2730 */
/*<       if(sysgn.lt.0.0)then >*/
    if ((real) sysgn < (float)0.) {
/* SOURCE exnmat.for:2731 */
/*<       disch=-disch >*/
	disch = -disch;
/* SOURCE exnmat.for:2732 */
/*<       pyl=-pyl >*/
	*pyl = -(*pyl);
/* SOURCE exnmat.for:2733 */
/*<       pyr=-pyr >*/
	*pyr = -(*pyr);
/* SOURCE exnmat.for:2734 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:2736 */
/*<       res=qe2(qnn)-disch >*/
    *res = static_cast<double>(qe2[qnn]) - disch;
/*     CHANGE SIGNS TO REFLECT Y AND Q DERIVATIVES OF DISCH.  WE */
/*     HAVE HERETOFOR TAKEN THE SIGN ON DISCH TO BE + */
/* SOURCE exnmat.for:2741 */
/*<       pyl=-pyl >*/
    *pyl = -(*pyl);
/* SOURCE exnmat.for:2742 */
/*<       pyr=-pyr >*/
    *pyr = -(*pyr);
/*     SET THE FLOW DERIVATIVES */
/* SOURCE exnmat.for:2745 */
/*<       if(qnn.eq.unn)then >*/
    if (qnn == unn) {
/* SOURCE exnmat.for:2746 */
/*<       pql=pql+1.0 >*/
	*pql += static_cast<double>((float)1.);
/* SOURCE exnmat.for:2747 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:2748 */
/*<       pqr=pqr+1.0 >*/
	*pqr += static_cast<double>((float)1.);
/* SOURCE exnmat.for:2749 */
/*<       endif >*/
    }
/*        WRITE(STDOUT,*) 'MCHGAT: RES=',RES */
/*        WRITE(STDOUT,*) ' DERV:',PYL, PQL, PYR, PQR */
/*        WRITE(STDOUT,*) 'HG=',HG */
/*        WRITE(STDOUT,*) ' H=',H,' D=',D,' DISCH=',DISCH */
/*        WRITE(STDOUT,*) ' QE2(QNN)=',QE2(QNN) */
/* SOURCE exnmat.for:2758 */
/*<       return >*/
    return 0;
/* SOURCE exnmat.for:2759 */
/*<       end >*/
} /* mchgat_ */

#undef rdum
#undef idum





/* SOURCE exnmat.for:2763 */
/*<       subroutinedo_gatetabl(stdout,jtime,ipt,emc) >*/
/* Subroutine */ int feq_gen_do_gatetabl_d_(integer *stdout, doublereal *jtime, 
	integer *ipt, integer *feq_storage_emc)
{
    /* System generated locals */
    static real equiv_2[1];

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer feq_gen_aux_rule_d_;
    real feq_gen_h_d_, p, ha, pt;
    integer feq_gen_table_adrs_d_;
    real feq_gen_dominant_p_d_;
    integer feq_gen_control_node_state_d_;
    real dfdc;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    real dfdr;
    integer ntab;
    real levc, levd;
#define idum (feq::BitView<integer>(equiv_2, sizeof(equiv_2)))
    integer role, dnsn;
    real levu;
#define rdum (equiv_2)
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    integer upsn, feq_gen_table_offset_d_, feq_gen_control_node_d_;
    extern /* Subroutine */ int tdlk10_(integer *, integer *, integer *, real 
	    *, real *, real *, real *, real *);
    real dtime;
    integer padrs;
    real feq_gen_aux_p_d_, value, feq_gen_direction_eps_d_;
    integer feq_gen_dominant_rule_d_;
    extern doublereal gethdd_(integer *);
    real hdatum, feq_gen_old_lev_d_, feq_gen_aux_min_d_, feq_gen_aux_max_d_;
    extern /* Subroutine */ int lktstab_(integer *, doublereal *, real *, 
	    integer *, real *);
    integer feq_gen_aux_knt_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__368 = { 0, 0, 0, 0, 0 };


/*     Find the gate opening for the GATETABL control of gates. */
/* SOURCE exnmat.for:2768 */
/*<       implicitnone >*/
/* INCLUDE exnmat.for:2769 */
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
/* SOURCE exnmat.for:2770 */
/*<       integerstdout,ipt,emc(mremc) >*/
/* SOURCE exnmat.for:2772 */
/*<       real*8jtime >*/
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE exnmat.for:2775 */
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
/* INCLUDE exnmat.for:2776 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE exnmat.for:2777 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE exnmat.for:2778 */
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
/* SOURCE exnmat.for:2782 */
/*<        >*/
/* SOURCE exnmat.for:2786 */
/*<        >*/
/*     IDUM and RDUM are used to store a floating point number(REAL */
/*     mumber) in an integer location and vice versa. */
/* SOURCE exnmat.for:2792 */
/*<       equivalence(idum,rdum) >*/
/*     Called program units. */
/* SOURCE exnmat.for:2795 */
/*<       realgethdd >*/
/* SOURCE exnmat.for:2797 */
/*<       externalgethdd,lktab >*/
/* *********************************************************************** */
/*     Clear the auxilliary gate openings.  We will use it to find */
/*     the user selected extreme value of all auxillary gate tables. */
/* SOURCE exnmat.for:2802 */
/*<       aux_max=0.0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
    feq_gen_aux_max_d_ = (float)0.;
/* SOURCE exnmat.for:2803 */
/*<       aux_min=1.0 >*/
    feq_gen_aux_min_d_ = (float)1.;
/*     We must count the auxilliary tables to detect their absence. */
/* SOURCE exnmat.for:2806 */
/*<       aux_knt=0 >*/
    feq_gen_aux_knt_d_ = 0;
/*     Get the pointer into EMC where the gate opening is stored. */
/* SOURCE exnmat.for:2808 */
/*<       padrs=itab(ipt) >*/
    padrs = itab[*ipt];
/*     Increment to the first sense point. */
/* SOURCE exnmat.for:2811 */
/*<       ipt=ipt+12 >*/
    *ipt += 12;
/* SOURCE exnmat.for:2812 */
/*<   100 continue >*/
L100:
/*       Node gives the location to sense. If it is zero it signals the */
/*       end of this block.  All sense points have then been processed. */
/* SOURCE exnmat.for:2815 */
/*<       control_node=itab(ipt) >*/
    feq_gen_control_node_d_ = itab[*ipt];
/* SOURCE exnmat.for:2816 */
/*<       if(control_node.ne.0)then >*/
    if (feq_gen_control_node_d_ != 0) {
/* SOURCE exnmat.for:2817 */
/*<       if(control_node.gt.0)then >*/
	if (feq_gen_control_node_d_ > 0) {
/* SOURCE exnmat.for:2818 */
/*<       write(stdout,*)' Problem in DO_GATETABL. NODE > 0' >*/
	    feq_gen_io_d__368.ciunit = *stdout;
	    s_wsle(&feq_gen_io_d__368);
	    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Problem in DO_GATETABL. NODE > 0"), (ftnlen)
		    33);
	    e_wsle();
/* SOURCE exnmat.for:2819 */
/*<       stop' Abnormal stop.  Bug found.' >*/
	    s_stop(const_cast<char*>(" Abnormal stop.  Bug found."), (ftnlen)27);
/* SOURCE exnmat.for:2820 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:2821 */
/*<       control_node=abs(control_node) >*/
	    feq_gen_control_node_d_ = abs(feq_gen_control_node_d_);
/* SOURCE exnmat.for:2822 */
/*<       endif >*/
	}
/*         Get elevation at control node */
/* SOURCE exnmat.for:2824 */
/*<       levc=ze(control_node)+ye1(control_node) >*/
	levc = static_cast<double>(enelem_1.ze[feq_gen_control_node_d_ - 1]) + enelem_1.ye1[feq_gen_control_node_d_ 
		- 1];
/*         The control node may not be a node involved with the */
/*         operation of the structure.  Get the node upstream of */
/*         the structure. */
/* SOURCE exnmat.for:2829 */
/*<       upsn=itab(ipt+2) >*/
	upsn = itab[*ipt + 2];
/*         Get the elevation at the upstream node */
/* SOURCE exnmat.for:2831 */
/*<       levu=ze(upsn)+ye1(upsn) >*/
	levu = static_cast<double>(enelem_1.ze[upsn - 1]) + enelem_1.ye1[upsn - 1];
/*         Get the node dns of the structure and its elevation. */
/* SOURCE exnmat.for:2833 */
/*<       dnsn=itab(ipt+3) >*/
	dnsn = itab[*ipt + 3];
/* SOURCE exnmat.for:2834 */
/*<       if(dnsn.gt.0)then >*/
	if (dnsn > 0) {
/* SOURCE exnmat.for:2835 */
/*<       levd=ze(dnsn)+ye1(dnsn) >*/
	    levd = static_cast<double>(enelem_1.ze[dnsn - 1]) + enelem_1.ye1[dnsn - 1];
/* SOURCE exnmat.for:2836 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:2837 */
/*<       levd=0.0 >*/
	    levd = (float)0.;
/* SOURCE exnmat.for:2838 */
/*<       endif >*/
	}
/*         Get the items we need to decide what to do about the two */
/*         water levels. */
/* SOURCE exnmat.for:2842 */
/*<       old_lev=ftab(ipt+4) >*/
	feq_gen_old_lev_d_ = ftab[*ipt + 4];
/* SOURCE exnmat.for:2843 */
/*<       direction_eps=ftab(ipt+6) >*/
	feq_gen_direction_eps_d_ = ftab[*ipt + 6];
/* SOURCE exnmat.for:2844 */
/*<       control_node_state=itab(ipt+5) >*/
	feq_gen_control_node_state_d_ = itab[*ipt + 5];
/*          WRITE(STDOUT,*) ' CONTROL_NODE_STATE=', CONTROL_NODE_STATE */
/* SOURCE exnmat.for:2847 */
/*<       if(control_node_state.gt.0)then >*/
	if (feq_gen_control_node_state_d_ > 0) {
/*           State is rising.  Check to see if we */
/*           have declined enough from the last update of the gate */
/*           opening to change the state. */
/*            WRITE(STDOUT,*) ' ' */
/*            WRITE(STDOUT,*) ' Current state is rising.' */
/*            WRITE(STDOUT,*) ' LEVC=',LEVC,' OLD_LEV=',OLD_LEV */
/*            WRITE(STDOUT,*) ' DIRECTION_EPS=',DIRECTION_EPS */
/* SOURCE exnmat.for:2855 */
/*<       if(levc.le.old_lev-direction_eps)then >*/
	    if (levc <= static_cast<double>(feq_gen_old_lev_d_) - feq_gen_direction_eps_d_) {
/*             Change state to falling */
/*              WRITE(STDOUT,*) ' Changing state to falling.' */
/* SOURCE exnmat.for:2858 */
/*<       itab(ipt+5)=-1 >*/
		itab[*ipt + 5] = -1;
/*             Table offset selects the table for the */
/*             just detected direction of motion. */
/* SOURCE exnmat.for:2861 */
/*<       table_offset=10 >*/
		feq_gen_table_offset_d_ = 10;
/* SOURCE exnmat.for:2862 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:2863 */
/*<       table_offset=7 >*/
		feq_gen_table_offset_d_ = 7;
/* SOURCE exnmat.for:2864 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:2865 */
/*<       else >*/
	} else {
/*           State is falling.  Check to see if we have risen enough from */
/*           the last update  to change the state. */
/*            WRITE(STDOUT,*) ' ' */
/*            WRITE(STDOUT,*) ' Current state is falling.' */
/*            WRITE(STDOUT,*) ' LEVC=',LEVC,' OLD_LEV=',OLD_LEV */
/*            WRITE(STDOUT,*) ' DIRECTION_EPS=',DIRECTION_EPS */
/* SOURCE exnmat.for:2872 */
/*<       if(levc.gt.old_lev+direction_eps)then >*/
	    if (levc > static_cast<double>(feq_gen_old_lev_d_) + feq_gen_direction_eps_d_) {
/*             Change state to rising. */
/*              WRITE(STDOUT,*) ' Changing state to rising.' */
/* SOURCE exnmat.for:2875 */
/*<       itab(ipt+5)=1 >*/
		itab[*ipt + 5] = 1;
/*             Table offset selects the table for the */
/*             just detected direction of motion. */
/* SOURCE exnmat.for:2878 */
/*<       table_offset=7 >*/
		feq_gen_table_offset_d_ = 7;
/* SOURCE exnmat.for:2879 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:2880 */
/*<       table_offset=10 >*/
		feq_gen_table_offset_d_ = 10;
/* SOURCE exnmat.for:2881 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:2882 */
/*<       endif >*/
	}
/*          WRITE(STDOUT,*) ' TABLE_OFFSET=',TABLE_OFFSET */
/* SOURCE exnmat.for:2884 */
/*<       table_adrs=itab(ipt+table_offset) >*/
	feq_gen_table_adrs_d_ = itab[*ipt + feq_gen_table_offset_d_];
/*          WRITE(STDOUT,*) ' TABLE_ADRS=',TABLE_ADRS */
/* SOURCE exnmat.for:2886 */
/*<       if(table_adrs.lt.0)then >*/
	if (feq_gen_table_adrs_d_ < 0) {
/*           We have a selection table.  Look up the table number */
/*           in the selection table and get the address of the */
/*           control table from the table number and FTPNT. */
/* SOURCE exnmat.for:2891 */
/*<       table_adrs=-table_adrs >*/
	    feq_gen_table_adrs_d_ = -feq_gen_table_adrs_d_;
/* SOURCE exnmat.for:2892 */
/*<       calllktstab(table_adrs,jtime,value,ntab,dtime) >*/
	    lktstab_(&feq_gen_table_adrs_d_, jtime, &value, &ntab, &dtime);
/* SOURCE exnmat.for:2895 */
/*<       ntab=int(value+0.5) >*/
	    ntab = (integer) (static_cast<double>(value) + (float).5);
/* SOURCE exnmat.for:2896 */
/*<       table_adrs=ftpnt(ntab) >*/
	    feq_gen_table_adrs_d_ = ftablea_1.ftpnt[ntab - 1];
/* SOURCE exnmat.for:2897 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:2899 */
/*<       hdatum=gethdd(table_adrs) >*/
	hdatum = gethdd_(&feq_gen_table_adrs_d_);
/* SOURCE exnmat.for:2900 */
/*<       h=levc-hdatum >*/
	feq_gen_h_d_ = static_cast<double>(levc) - hdatum;
/* SOURCE exnmat.for:2901 */
/*<       if(dnsn.gt.0)then >*/
	if (dnsn > 0) {
/* SOURCE exnmat.for:2902 */
/*<       ha=levu-levd >*/
	    ha = static_cast<double>(levu) - levd;
/* SOURCE exnmat.for:2903 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:2904 */
/*<       ha=levu-hdatum >*/
	    ha = static_cast<double>(levu) - hdatum;
/* SOURCE exnmat.for:2905 */
/*<       endif >*/
	}
/*          WRITE(STDOUT,*) ' DO_GATE...: LEVC=',LEVC, */
/*     A            ' LEVU=',LEVU, ' LEVD=',LEVD */
/*          WRITE(STDOUT,*) ' H=',H,' HA=',HA */
/*         Get the gate opening from the current table. */
/* SOURCE exnmat.for:2911 */
/*<       calltdlk10(stdout,table_adrs,10,h,ha,pt,dfdr,dfdc) >*/
	tdlk10_(stdout, &feq_gen_table_adrs_d_, &feq_gen_c_d_10, &feq_gen_h_d_, &ha, &pt, &dfdr, &dfdc);
/*          WRITE(STDOUT,*) ' TABLE GIVES PT=',PT */
/* SOURCE exnmat.for:2915 */
/*<       role=itab(ipt+table_offset+1) >*/
	role = itab[*ipt + feq_gen_table_offset_d_ + 1];
/* SOURCE exnmat.for:2916 */
/*<       if(role.eq.1)then >*/
	if (role == 1) {
/*           This is the dominant table. */
/* SOURCE exnmat.for:2918 */
/*<       dominant_rule=itab(ipt+table_offset+2) >*/
	    feq_gen_dominant_rule_d_ = itab[*ipt + feq_gen_table_offset_d_ + 2];
/* SOURCE exnmat.for:2919 */
/*<       dominant_p=pt >*/
	    feq_gen_dominant_p_d_ = pt;
/*            WRITE(STDOUT,*) ' DOMINANT_P=',DOMINANT_P */
/* SOURCE exnmat.for:2921 */
/*<       else >*/
	} else {
/*           This is an auxilliary table. */
/* SOURCE exnmat.for:2923 */
/*<       aux_knt=aux_knt+1 >*/
	    ++feq_gen_aux_knt_d_;
/* SOURCE exnmat.for:2924 */
/*<       aux_rule=itab(ipt+table_offset+2) >*/
	    feq_gen_aux_rule_d_ = itab[*ipt + feq_gen_table_offset_d_ + 2];
/* SOURCE exnmat.for:2925 */
/*<       if(aux_rule.eq.1)then >*/
	    if (feq_gen_aux_rule_d_ == 1) {
/*             Sense is minimum value.  Seek the smallest value of */
/*             all the aux tables. */
/* SOURCE exnmat.for:2928 */
/*<       aux_min=min(aux_min,pt) >*/
		feq_gen_aux_min_d_ = dmin(feq_gen_aux_min_d_,pt);
/* SOURCE exnmat.for:2929 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:2930 */
/*<       aux_max=max(aux_max,pt) >*/
		feq_gen_aux_max_d_ = dmax(feq_gen_aux_max_d_,pt);
/* SOURCE exnmat.for:2931 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:2932 */
/*<       endif >*/
	}
/*         Go get the next sensing point. */
/* SOURCE exnmat.for:2935 */
/*<       ipt=ipt+17 >*/
	*ipt += 17;
/* SOURCE exnmat.for:2936 */
/*<       goto100 >*/
	goto L100;
/* SOURCE exnmat.for:2937 */
/*<       endif >*/
    }
/*     At this point make the final selection of the gate opening to use. */
/*     The AUX_RULE is the same for all AUX_TABLES.  Thus the last value set */
/*     is the same as the value for all. */
/* SOURCE exnmat.for:2943 */
/*<       if(aux_knt.gt.0)then >*/
    if (feq_gen_aux_knt_d_ > 0) {
/* SOURCE exnmat.for:2944 */
/*<       if(aux_rule.eq.1)then >*/
	if (feq_gen_aux_rule_d_ == 1) {
/* SOURCE exnmat.for:2945 */
/*<       aux_p=aux_min >*/
	    feq_gen_aux_p_d_ = feq_gen_aux_min_d_;
/* SOURCE exnmat.for:2946 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:2947 */
/*<       aux_p=aux_max >*/
	    feq_gen_aux_p_d_ = feq_gen_aux_max_d_;
/* SOURCE exnmat.for:2948 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:2949 */
/*<       if(dominant_rule.eq.1)then >*/
	if (feq_gen_dominant_rule_d_ == 1) {
/*         The dominant table's opening represents the minimum opening in */
/*         in any case.  Therefore, any opening that is larger will be taken */
/*         as THE opening. */
/* SOURCE exnmat.for:2953 */
/*<       if(aux_p.gt.dominant_p)then >*/
	    if (feq_gen_aux_p_d_ > feq_gen_dominant_p_d_) {
/* SOURCE exnmat.for:2954 */
/*<       p=aux_p >*/
		p = feq_gen_aux_p_d_;
/* SOURCE exnmat.for:2955 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:2956 */
/*<       p=dominant_p >*/
		p = feq_gen_dominant_p_d_;
/* SOURCE exnmat.for:2957 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:2958 */
/*<       else >*/
	} else {
/*         The dominant table's opening represents the maximum opening */
/*         in any case.  Therefore, any opening that is smaller will be */
/*         taken as THE opening. */
/* SOURCE exnmat.for:2962 */
/*<       if(aux_p.lt.dominant_p)then >*/
	    if (feq_gen_aux_p_d_ < feq_gen_dominant_p_d_) {
/* SOURCE exnmat.for:2963 */
/*<       p=aux_p >*/
		p = feq_gen_aux_p_d_;
/* SOURCE exnmat.for:2964 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:2965 */
/*<       p=dominant_p >*/
		p = feq_gen_dominant_p_d_;
/* SOURCE exnmat.for:2966 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:2967 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:2968 */
/*<       else >*/
    } else {
/*       Only one table is present. */
/* SOURCE exnmat.for:2970 */
/*<       p=dominant_p >*/
	p = feq_gen_dominant_p_d_;
/* SOURCE exnmat.for:2971 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' Relative gate opening=',P */
/*     Now put the opening its proper location in EMC */
/* SOURCE exnmat.for:2974 */
/*<       rdum=p >*/
    *rdum = p;
/* SOURCE exnmat.for:2975 */
/*<       emc(padrs)=idum >*/
    emc[padrs] = *idum;
/* SOURCE exnmat.for:2976 */
/*<       return >*/
    return 0;
/* SOURCE exnmat.for:2977 */
/*<       end >*/
} /* do_gatetabl__ */

#undef rtmp
#undef rdum
#undef idum
#undef itab
#undef ftab





/* SOURCE exnmat.for:2981 */
/*<       subroutineoper(jtime,nblk,opblk,dthr,emc) >*/
/* Subroutine */ int oper_(doublereal *jtime, integer *nblk, integer *feq_storage_opblk, 
	real *dthr, integer *feq_storage_emc)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2;
    icilist feq_gen_ici_d_1;
    static real equiv_2[1];

    /* Builtin functions */
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi();
    double r_sign(real *, real *);

    /* Local variables */
    integer feq_gen_i_d_, nd;
    real ll, et, ml, lu, mu;
    integer feq_gen_table_adrs_d_;
    real lml, lev, spd;
    integer key;
    real pdv;
    integer pri, ipt;
    real lmu, lup;
    extern /* Subroutine */ int feq_gen_do_gatetabl_d_(integer *, doublereal *, 
	    integer *, integer *);
    integer feq_gen_emc_dir_pnt_d_, ipt5;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer mode, node, ntab;
    real dlev, dpdt;
#define idum (feq::BitView<integer>(equiv_2, sizeof(equiv_2)))
    real pold;
    integer prig;
    real pdot;
#define rdum (equiv_2)
    real llow;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    integer nflag;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    integer padrs, tbuse;
    real dpdot, nzmid, pdotg, value;
    char dummy[10];
    integer feq_gen_ts_blk_number_d_, tbfall, speeds, tbrise, iptold, blktyp;
    real levold, mnrate;
    extern doublereal fndnzm_(integer *);
    integer feq_gen_old_blk_d_, feq_gen_emc_pnt_d_, feq_gen_old_ipt_d_;
    extern /* Subroutine */ int lktstab_(integer *, doublereal *, real *, 
	    integer *, real *);

/*     + + + PURPOSE + + + */
/*     Compute the opening for dynamically varied control structures. */
/* SOURCE exnmat.for:2988 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE exnmat.for:2990 */
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
/* INCLUDE exnmat.for:2991 */
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
/* SOURCE exnmat.for:2994 */
/*<       integernblk >*/
/* SOURCE exnmat.for:2995 */
/*<       integeremc(mremc),opblk(nblk) >*/
/* SOURCE exnmat.for:2996 */
/*<       realdthr >*/
/* SOURCE exnmat.for:2997 */
/*<       real*8jtime >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     TIME   - time in seconds from run start */
/*     NBLK   - number of operation blocks */
/*     OPBLK  - pointer into the function table storage(FTAB/ITAB) for */
/*               each operation block. */
/*     DTHR   - time step in hours */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE exnmat.for:3008 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE exnmat.for:3009 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE exnmat.for:3010 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE exnmat.for:3013 */
/*<        >*/
/* SOURCE exnmat.for:3017 */
/*<        >*/
/*     Try to solve bug in LF90 compiler */
/* SOURCE exnmat.for:3022 */
/*<       character*10dummy >*/
/* SOURCE exnmat.for:3024 */
/*<       parameter(pump_eps=0.01,pump_eps_tol=0.00001) >*/
/*     + + + EQUIVALENCES + + + */
/* SOURCE exnmat.for:3027 */
/*<       equivalence(idum,rdum) >*/
/*     + + + INTRINSICS + + + */
/* SOURCE exnmat.for:3030 */
/*<       intrinsicabs,iabs,sign >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE exnmat.for:3033 */
/*<       realfndnzm >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE exnmat.for:3036 */
/*<       externalfndnzm,lktab >*/
/* *********************************************************************** */
/* SOURCE exnmat.for:3038 */
/*<       if(dthr.lt.0.0)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> opblk(feq_storage_opblk, 1);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
    if (*dthr < (float)0.) {
/*       RESTORE PREVIOUS VALUE OF P SO THAT WE CAN TAKE A SHORTER */
/*       TIME STEP */
/* SOURCE exnmat.for:3042 */
/*<       do200i=1,nblk >*/
	feq_gen_i_d_1 = *nblk;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE exnmat.for:3043 */
/*<       ipt=opblk(i) >*/
	    ipt = opblk[feq_gen_i_d_];
/* SOURCE exnmat.for:3044 */
/*<       table_adrs=itab(ipt+7) >*/
	    feq_gen_table_adrs_d_ = itab[ipt + 7];
/* SOURCE exnmat.for:3045 */
/*<       if(table_adrs.lt.0)goto200 >*/
	    if (feq_gen_table_adrs_d_ < 0) {
		goto L200;
	    }
/* SOURCE exnmat.for:3046 */
/*<       ftab(ipt+1)=ftab(ipt+2) >*/
	    ftab[ipt + 1] = ftab[ipt + 2];
/*         Correct the elapsed time */
/* SOURCE exnmat.for:3048 */
/*<       ftab(ipt+5)=ftab(ipt+5)+dthr >*/
	    ftab[ipt + 5] += *dthr;
/* SOURCE exnmat.for:3049 */
/*<       if(ftab(ipt+5).lt.0.0)ftab(ipt+5)=0.0 >*/
	    if (ftab[ipt + 5] < (float)0.) {
		ftab[ipt + 5] = (float)0.;
	    }
/* SOURCE exnmat.for:3050 */
/*<   200 continue >*/
L200:
	    ;
	}
/* SOURCE exnmat.for:3051 */
/*<       return >*/
	return 0;
/* SOURCE exnmat.for:3052 */
/*<       endif >*/
    }
/*      WRITE(STD6,*) ' NBLK=',NBLK */
/* SOURCE exnmat.for:3055 */
/*<       do500i=1,nblk >*/
    feq_gen_i_d_1 = *nblk;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE exnmat.for:3056 */
/*<       prig=999999 >*/
	prig = 999999;
/* SOURCE exnmat.for:3057 */
/*<       ipt=opblk(i) >*/
	ipt = opblk[feq_gen_i_d_];
/* SOURCE exnmat.for:3058 */
/*<       ipt5=ipt+5 >*/
	ipt5 = ipt + 5;
/*       WRITE(STD6,*) ' Current Blk#=',I, ' IPT=',IPT */
/* SOURCE exnmat.for:3060 */
/*<       table_adrs=itab(ipt+7) >*/
	feq_gen_table_adrs_d_ = itab[ipt + 7];
/*        write(std6,*) 'In OPER: table_adrs=',table_adrs */
/* SOURCE exnmat.for:3063 */
/*<       if(table_adrs.eq.0)then >*/
	if (feq_gen_table_adrs_d_ == 0) {
/*         Fall through.  This is the current most frequent instance. */
/*         therefore, chk it first to reduce overhead. */
/* SOURCE exnmat.for:3066 */
/*<       elseif(table_adrs.lt.0)then >*/
	} else if (feq_gen_table_adrs_d_ < 0) {
/*         Skip the block. It is inactive. */
/* SOURCE exnmat.for:3068 */
/*<       goto500 >*/
	    goto L500;
/* SOURCE exnmat.for:3069 */
/*<       elseif(table_adrs.gt.0)then >*/
	} else if (feq_gen_table_adrs_d_ > 0) {
/*         Check if this block should be used now. */
/* SOURCE exnmat.for:3071 */
/*<       calllktstab(table_adrs,jtime,value,ntab,pdv) >*/
	    lktstab_(&feq_gen_table_adrs_d_, jtime, &value, &ntab, &pdv);
/* SOURCE exnmat.for:3074 */
/*<       ts_blk_number=int(value+0.5) >*/
	    feq_gen_ts_blk_number_d_ = (integer) (static_cast<double>(value) + (float).5);
/*          write(std6,9123) i, ts_blk_number, jtime */
/* 9123  format('In OPER: i=',i5,' ts_blk_number=',i5,' jtime=',f20.7) */
/* SOURCE exnmat.for:3077 */
/*<       if(ts_blk_number.eq.i)then >*/
	    if (feq_gen_ts_blk_number_d_ == feq_gen_i_d_) {
/*           This block should be used now.  Is it at its first */
/*           time step? */
/* SOURCE exnmat.for:3080 */
/*<       emc_pnt=itab(ipt+8) >*/
		feq_gen_emc_pnt_d_ = itab[ipt + 8];
/* SOURCE exnmat.for:3081 */
/*<       old_blk=emc(emc_pnt) >*/
		feq_gen_old_blk_d_ = emc[feq_gen_emc_pnt_d_];
/* SOURCE exnmat.for:3082 */
/*<       if(ts_blk_number.ne.old_blk)then >*/
		if (feq_gen_ts_blk_number_d_ != feq_gen_old_blk_d_) {
/*             This is first time step. Set the structure setting */
/*             to be the same as the block last used.  Also must */
/*             transfer elapsed time since last change. */
/* SOURCE exnmat.for:3086 */
/*<       old_ipt=opblk(old_blk) >*/
		    feq_gen_old_ipt_d_ = opblk[feq_gen_old_blk_d_];
/* SOURCE exnmat.for:3087 */
/*<       ftab(ipt+1)=ftab(old_ipt+1) >*/
		    ftab[ipt + 1] = ftab[feq_gen_old_ipt_d_ + 1];
/* SOURCE exnmat.for:3088 */
/*<       ftab(ipt+2)=ftab(old_ipt+2) >*/
		    ftab[ipt + 2] = ftab[feq_gen_old_ipt_d_ + 2];
/* SOURCE exnmat.for:3089 */
/*<       ftab(ipt+5)=ftab(old_ipt+5) >*/
		    ftab[ipt + 5] = ftab[feq_gen_old_ipt_d_ + 5];
/* SOURCE exnmat.for:3090 */
/*<       emc(emc_pnt)=i >*/
		    emc[feq_gen_emc_pnt_d_] = feq_gen_i_d_;
/* SOURCE exnmat.for:3091 */
/*<       endif >*/
		}
/* SOURCE exnmat.for:3092 */
/*<       else >*/
	    } else {
/*           This block is not selected by the time series table. */
/*           Skip it.  The various levels are kept current in */
/*           subroutine OPINIT */
/* SOURCE exnmat.for:3096 */
/*<       goto500 >*/
		goto L500;
/* SOURCE exnmat.for:3097 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:3098 */
/*<       endif >*/
	}

/* SOURCE exnmat.for:3100 */
/*<       padrs=itab(ipt) >*/
	padrs = itab[ipt];
/* SOURCE exnmat.for:3101 */
/*<       pold=ftab(ipt+1) >*/
	pold = ftab[ipt + 1];
/* SOURCE exnmat.for:3102 */
/*<       iptold=ipt+1 >*/
	iptold = ipt + 1;
/*       Update the elapsed time since the last adjustment was */
/*       attempted. */
/*        WRITE(STD6,*) ' Old elapsed time=',FTAB(IPT+5) */
/*        FTAB(IPT+5) = FTAB(IPT+5) + DTHR */
/* SOURCE exnmat.for:3108 */
/*<       ftab(ipt5)=ftab(ipt5)+dthr >*/
	ftab[ipt5] += *dthr;
/*       The statement below is present to force the old Lahey F90 compiler */
/*       to produce proper code.  If the statement is not present */
/*       then the elapsed time is not updated properly. */
/* SOURCE exnmat.for:3112 */
/*<       write(dummy,'(F10.4)')ftab(ipt5) >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 10;
	feq_gen_ici_d_1.iciunit = dummy;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.4)");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)ftab.lease(ipt5).data(), (ftnlen)sizeof(real));
	e_wsfi();
/*        WRITE(STD6,*) ' New elapsed time=',FTAB(IPT+5) */
/* SOURCE exnmat.for:3114 */
/*<       et=ftab(ipt5) >*/
	et = ftab[ipt5];
/* SOURCE exnmat.for:3115 */
/*<       if(et.lt.ftab(ipt+4))then >*/
	if (et < ftab[ipt + 4]) {
/*         Insufficient time elapsed since we last attempted an */
/*         adjustment of operation. */
/* SOURCE exnmat.for:3118 */
/*<       goto500 >*/
	    goto L500;
/* SOURCE exnmat.for:3119 */
/*<       endif >*/
	}
/*       Extract the operation block type. */
/* SOURCE exnmat.for:3123 */
/*<       blktyp=itab(ipt+3) >*/
	blktyp = itab[ipt + 3];
/*        write(std6,*) 'OPER: BLKTYP=',blktyp */
/*        write(std6,*) ' old P=',ftab(ipt+1),' current P=',ftab(ipt+2) */
/*        write(std6,*) ' Elapsed time=',ftab(ipt+5) */
/* SOURCE exnmat.for:3127 */
/*<       if(blktyp.eq.3)then >*/
	if (blktyp == 3) {
/*         This is GATETABL.  Based on different rules than any */
/*         other.  Therefore, it sets its gate opening internally. */
/* SOURCE exnmat.for:3130 */
/*<       calldo_gatetabl(std6,jtime,ipt,emc) >*/
	    feq_gen_do_gatetabl_d_(&feq_gen_stdun_com_d_1.std6, jtime, &ipt, &emc[1]);
/*         Branch to the end of the loop over control blocks. */
/* SOURCE exnmat.for:3133 */
/*<       goto500 >*/
	    goto L500;
/* SOURCE exnmat.for:3134 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:3136 */
/*<       speeds=itab(ipt+11) >*/
	speeds = itab[ipt + 11];
/*        WRITE(STD6,*) ' SPEEDS=',SPEEDS */
/* SOURCE exnmat.for:3138 */
/*<       ipt=ipt+12 >*/
	ipt += 12;
/* SOURCE exnmat.for:3139 */
/*<   100 continue >*/
L100:
/* SOURCE exnmat.for:3140 */
/*<       node=itab(ipt) >*/
	node = itab[ipt];
/* SOURCE exnmat.for:3141 */
/*<       if(node.eq.0)goto410 >*/
	if (node == 0) {
	    goto L410;
	}
/* SOURCE exnmat.for:3142 */
/*<       key=itab(ipt+1) >*/
	key = itab[ipt + 1];
/* SOURCE exnmat.for:3143 */
/*<       mode=itab(ipt+2) >*/
	mode = itab[ipt + 2];
/* SOURCE exnmat.for:3144 */
/*<       mnrate=ftab(ipt+3) >*/
	mnrate = ftab[ipt + 3];
/* SOURCE exnmat.for:3145 */
/*<       levold=ftab(ipt+4) >*/
	levold = ftab[ipt + 4];
/* SOURCE exnmat.for:3146 */
/*<       if(blktyp.eq.1)then >*/
	if (blktyp == 1) {
/* SOURCE exnmat.for:3147 */
/*<       ml=ftab(ipt+5) >*/
	    ml = ftab[ipt + 5];
/* SOURCE exnmat.for:3148 */
/*<       ll=ftab(ipt+6) >*/
	    ll = ftab[ipt + 6];
/* SOURCE exnmat.for:3149 */
/*<       lu=ftab(ipt+7) >*/
	    lu = ftab[ipt + 7];
/* SOURCE exnmat.for:3150 */
/*<       mu=ftab(ipt+8) >*/
	    mu = ftab[ipt + 8];
/* SOURCE exnmat.for:3151 */
/*<       dpdt=ftab(ipt+12) >*/
	    dpdt = ftab[ipt + 12];
/* SOURCE exnmat.for:3152 */
/*<       llow=ftab(ipt+13) >*/
	    llow = ftab[ipt + 13];
/* SOURCE exnmat.for:3153 */
/*<       lml=ftab(ipt+14) >*/
	    lml = ftab[ipt + 14];
/* SOURCE exnmat.for:3154 */
/*<       lmu=ftab(ipt+15) >*/
	    lmu = ftab[ipt + 15];
/* SOURCE exnmat.for:3155 */
/*<       lup=ftab(ipt+16) >*/
	    lup = ftab[ipt + 16];
/* SOURCE exnmat.for:3156 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:3157 */
/*<       tbrise=itab(ipt+5) >*/
	    tbrise = itab[ipt + 5];
/* SOURCE exnmat.for:3158 */
/*<       tbfall=itab(ipt+6) >*/
	    tbfall = itab[ipt + 6];
/* SOURCE exnmat.for:3159 */
/*<       tbuse=itab(ipt+7) >*/
	    tbuse = itab[ipt + 7];
/* SOURCE exnmat.for:3160 */
/*<       endif >*/
	}
/*            WRITE(STD6,*) '  ' */
/*            WRITE(STD6,*) '  ' */
/*            WRITE(STD6,*) ' KEY=',KEY,' MODE=',MODE,' MNRATE=',MNRATE */
/*            IF(BLKTYP.EQ.1) THEN */
/*              WRITE(STD6,*) ' LEVOLD=',LEVOLD,' ML=',ML,' LL=',LL */
/*              WRITE(STD6,*) ' LU=',LU,' MU=',MU */
/*            ELSE */
/*              WRITE(STD6,*) ' LEVOLD=',LEVOLD, ' TBRISE=', */
/*     A             ITAB(TBRISE+1),' TBFALL=',ITAB(TBFALL+1), */
/*     B             ' TBUSE=',ITAB(TBUSE+1) */
/*            ENDIF */
/* SOURCE exnmat.for:3174 */
/*<       if(node.gt.0)then >*/
	if (node > 0) {
/*             INTERIOR NODE */
/* SOURCE exnmat.for:3176 */
/*<       if(key.eq.0)then >*/
	    if (key == 0) {
/* SOURCE exnmat.for:3177 */
/*<       lev=zvec(node)+y1(node) >*/
		lev = static_cast<double>(bnelem_1.zvec[node - 1]) + bnelem_1.y1[node - 1];
/* SOURCE exnmat.for:3178 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:3179 */
/*<       lev=q1(node) >*/
		lev = bnelem_1.q1[node - 1];
/* SOURCE exnmat.for:3180 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:3181 */
/*<       else >*/
	} else {
/*             EXTERIOR NODE */
/* SOURCE exnmat.for:3183 */
/*<       node=iabs(node) >*/
	    node = abs(node);
/* SOURCE exnmat.for:3184 */
/*<       if(key.lt.0)then >*/
	    if (key < 0) {
/*               Elevation difference */
/* SOURCE exnmat.for:3186 */
/*<       nd=abs(key) >*/
		nd = abs(key);
/* SOURCE exnmat.for:3187 */
/*<       lev=ze(node)+ye1(node)-(ze(nd)+ye1(nd)) >*/
		lev = static_cast<double>(static_cast<double>(enelem_1.ze[node - 1]) + enelem_1.ye1[node - 1]) - (
			static_cast<double>(enelem_1.ze[nd - 1]) + enelem_1.ye1[nd - 1]);
/* SOURCE exnmat.for:3189 */
/*<       elseif(key.eq.0)then >*/
	    } else if (key == 0) {
/* SOURCE exnmat.for:3190 */
/*<       lev=ze(node)+ye1(node) >*/
		lev = static_cast<double>(enelem_1.ze[node - 1]) + enelem_1.ye1[node - 1];
/* SOURCE exnmat.for:3191 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:3192 */
/*<       lev=qe1(node) >*/
		lev = enelem_1.qe1[node - 1];
/* SOURCE exnmat.for:3193 */
/*<       if(key.eq.2)then >*/
		if (key == 2) {
/*                 RECOMPUTE THE NULL ZONE LIMITS. */
/* SOURCE exnmat.for:3196 */
/*<       nzmid=fndnzm(ipt) >*/
		    nzmid = fndnzm_(&ipt);
/*                 SET THE NULL ZONE LIMITS */
/* SOURCE exnmat.for:3199 */
/*<       ll=nzmid-ftab(ipt+13) >*/
		    ll = static_cast<double>(nzmid) - ftab[ipt + 13];
/* SOURCE exnmat.for:3200 */
/*<       lu=nzmid+ftab(ipt+13) >*/
		    lu = static_cast<double>(nzmid) + ftab[ipt + 13];
/*      WRITE(STD6,*) ' QVAR LIMITS: NZMID=',NZMID,' LL=',LL,' LU=',LU */
/* SOURCE exnmat.for:3202 */
/*<       endif >*/
		}
/* SOURCE exnmat.for:3203 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:3204 */
/*<       endif >*/
	}
/*            WRITE(STD6,*) '  ' */
/*            WRITE(STD6,*) ' LEV=',LEV */
/* SOURCE exnmat.for:3209 */
/*<       if(blktyp.eq.1)then >*/
	if (blktyp == 1) {
/*             Gate mode of operation.  Compute the rate of opening. */
/*             Set flag as if we are in the null zone.  If we are not */
/*             clear the flag. */
/* SOURCE exnmat.for:3214 */
/*<       nflag=1 >*/
	    nflag = 1;
/* SOURCE exnmat.for:3215 */
/*<       if(lev.lt.ll)then >*/
	    if (lev < ll) {
/*               WE ARE BELOW THE NULL ZONE-- WE WANT TO MOVE TOWARD THE */
/*               NULL ZONE */
/* SOURCE exnmat.for:3219 */
/*<       nflag=0 >*/
		nflag = 0;
/*               Set the lower end of the null zone to the */
/*               middle value.  Also set the upper end to the */
/*               mormal value.  Note that these changes are actually */
/*               equivalent to X = X if option is GATE and not GATEVNZ. */
/* SOURCE exnmat.for:3225 */
/*<       ll=lml >*/
		ll = lml;
/* SOURCE exnmat.for:3226 */
/*<       lu=lup >*/
		lu = lup;
/* SOURCE exnmat.for:3228 */
/*<       pri=itab(ipt+9) >*/
		pri = itab[ipt + 9];
/* SOURCE exnmat.for:3229 */
/*<       if(mode.eq.1)then >*/
		if (mode == 1) {
/*                 CHECK ON DIRECTION OF MOVEMENT SINCE THE END OF THE */
/*                 LAST TIME STEP */
/* SOURCE exnmat.for:3233 */
/*<       if(lev.le.levold)then >*/
		    if (lev <= levold) {
/*                   MOVING IN WRONG DIRECTION */
/* SOURCE exnmat.for:3236 */
/*<       pdot=(lev-ll)*ml >*/
			pdot = static_cast<double>((static_cast<double>(lev) - ll)) * ml;
/* SOURCE exnmat.for:3237 */
/*<       else >*/
		    } else {
/*                   MOVING IN THE CORRECT DIRECTION */
/* SOURCE exnmat.for:3239 */
/*<       if(lev-levold.le.dthr*mnrate)then >*/
			if (static_cast<double>(lev) - levold <= static_cast<double>(*dthr) * mnrate) {
/*                     MOVING TOO SLOWLY */
/* SOURCE exnmat.for:3241 */
/*<       pdot=(lev-ll)*ml >*/
			    pdot = static_cast<double>((static_cast<double>(lev) - ll)) * ml;
/* SOURCE exnmat.for:3242 */
/*<       else >*/
			} else {
/* SOURCE exnmat.for:3243 */
/*<       pdot=0.0 >*/
			    pdot = (float)0.;
/* SOURCE exnmat.for:3244 */
/*<       endif >*/
			}
/* SOURCE exnmat.for:3245 */
/*<       endif >*/
		    }
/* SOURCE exnmat.for:3246 */
/*<       else >*/
		} else {
/* SOURCE exnmat.for:3247 */
/*<       pdot=(lev-ll)*ml >*/
		    pdot = static_cast<double>((static_cast<double>(lev) - ll)) * ml;
/* SOURCE exnmat.for:3248 */
/*<       endif >*/
		}
/* SOURCE exnmat.for:3249 */
/*<       else >*/
	    } else {
/*               Reset lower limit to normal value because we have gone above */
/*               the middle value. */
/* SOURCE exnmat.for:3252 */
/*<       ll=llow >*/
		ll = llow;
/* SOURCE exnmat.for:3253 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:3255 */
/*<       if(lev.gt.lu)then >*/
	    if (lev > lu) {
/*               WE ARE ABOVE THE NULL ZONE AND WE WANT TO MOVE TOWARD IT */
/*               Set the upper end of the null zone to the middle value. */
/*               Also set the lower end to its normal value.  Note */
/*               that these changes are equivalent to X=X if option is GATE */
/*               and not GATEVNZ. */
/* SOURCE exnmat.for:3262 */
/*<       nflag=0 >*/
		nflag = 0;
/* SOURCE exnmat.for:3263 */
/*<       lu=lmu >*/
		lu = lmu;
/* SOURCE exnmat.for:3264 */
/*<       ll=llow >*/
		ll = llow;
/* SOURCE exnmat.for:3266 */
/*<       pri=itab(ipt+11) >*/
		pri = itab[ipt + 11];
/* SOURCE exnmat.for:3268 */
/*<       if(mode.eq.1)then >*/
		if (mode == 1) {
/*                 CHECK DIRECTION OF MOVEMENT */
/* SOURCE exnmat.for:3270 */
/*<       if(lev.ge.levold)then >*/
		    if (lev >= levold) {
/*                   MOVING IN THE WRONG DIRECTION */
/* SOURCE exnmat.for:3272 */
/*<       pdot=(lev-lu)*mu >*/
			pdot = static_cast<double>((static_cast<double>(lev) - lu)) * mu;
/* SOURCE exnmat.for:3273 */
/*<       else >*/
		    } else {
/*                   MOVING IN CORRECT DIRECTION */
/* SOURCE exnmat.for:3275 */
/*<       if(levold-lev.le.dthr*mnrate)then >*/
			if (static_cast<double>(levold) - lev <= static_cast<double>(*dthr) * mnrate) {
/*                     MOVING TOO SLOWLY */
/* SOURCE exnmat.for:3277 */
/*<       pdot=(lev-lu)*mu >*/
			    pdot = static_cast<double>((static_cast<double>(lev) - lu)) * mu;
/* SOURCE exnmat.for:3278 */
/*<       else >*/
			} else {
/* SOURCE exnmat.for:3279 */
/*<       pdot=0.0 >*/
			    pdot = (float)0.;
/* SOURCE exnmat.for:3280 */
/*<       endif >*/
			}
/* SOURCE exnmat.for:3281 */
/*<       endif >*/
		    }
/* SOURCE exnmat.for:3282 */
/*<       else >*/
		} else {
/* SOURCE exnmat.for:3283 */
/*<       pdot=(lev-lu)*mu >*/
		    pdot = static_cast<double>((static_cast<double>(lev) - lu)) * mu;
/* SOURCE exnmat.for:3284 */
/*<       endif >*/
		}
/* SOURCE exnmat.for:3285 */
/*<       else >*/
	    } else {
/*               Set upper limit to the standard value because we have */
/*               gone below even the middle value. */
/* SOURCE exnmat.for:3288 */
/*<       lu=lup >*/
		lu = lup;
/* SOURCE exnmat.for:3289 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:3290 */
/*<       if(nflag.eq.1)then >*/
	    if (nflag == 1) {
/*               We are in the current null zone.  Keep gate at */
/*               its current position. */
/*                PDOT = 0.5*(LEV - LEVOLD)/DTHR */
/* SOURCE exnmat.for:3294 */
/*<       pdot=0.0 >*/
		pdot = (float)0.;
/* SOURCE exnmat.for:3295 */
/*<       pri=itab(ipt+10) >*/
		pri = itab[ipt + 10];
/* SOURCE exnmat.for:3296 */
/*<       endif >*/
	    }
/*             Save the current values of LL and LU. */
/* SOURCE exnmat.for:3299 */
/*<       ftab(ipt+6)=ll >*/
	    ftab[ipt + 6] = ll;
/* SOURCE exnmat.for:3300 */
/*<       ftab(ipt+7)=lu >*/
	    ftab[ipt + 7] = lu;
/*             RETAIN THE ACTION WITH THE HIGHER PRIORITY */
/*             CHECK FOR PDOT BEING TOO LARGE */
/* SOURCE exnmat.for:3306 */
/*<       if(abs(pdot).gt.dpdt)then >*/
	    if (dabs(pdot) > dpdt) {
/* SOURCE exnmat.for:3307 */
/*<       pdot=sign(dpdt,pdot) >*/
		pdot = r_sign(&dpdt, &pdot);
/* SOURCE exnmat.for:3308 */
/*<       endif >*/
	    }
/*              WRITE(STD6,*) ' ' */
/*              WRITE(STD6,*) ' PRI=',PRI,' PDOT=',PDOT */
/* SOURCE exnmat.for:3313 */
/*<       if(pri.lt.prig)then >*/
	    if (pri < prig) {
/* SOURCE exnmat.for:3314 */
/*<       prig=pri >*/
		prig = pri;
/* SOURCE exnmat.for:3315 */
/*<       pdotg=pdot >*/
		pdotg = pdot;
/* SOURCE exnmat.for:3316 */
/*<       endif >*/
	    }
/*              WRITE(STD6,*) ' RETAINED SETTING: PRIG=',PRIG, */
/*     A                     ' PDOTG=',PDOT */
/* SOURCE exnmat.for:3320 */
/*<       if(key.le.1)then >*/
	    if (key <= 1) {
/* SOURCE exnmat.for:3321 */
/*<       ipt=ipt+17 >*/
		ipt += 17;
/* SOURCE exnmat.for:3322 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:3323 */
/*<       itmp=itab(ipt+14) >*/
		ftablea_1.itmp = itab[ipt + 14];
/* SOURCE exnmat.for:3324 */
/*<       ipt=ipt+15+2*itmp >*/
		ipt = ipt + 15 + (ftablea_1.itmp << 1);
/* SOURCE exnmat.for:3325 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:3326 */
/*<       elseif(blktyp.eq.2.or.blktyp.eq.4)then >*/
	} else if (blktyp == 2 || blktyp == 4) {
/*             Pump control model here.  Decide which table to */
/*             use.  Look at change of water level since the */
/*             last time an adjustment was attempted. */
/* SOURCE exnmat.for:3331 */
/*<       dlev=lev-levold >*/
	    dlev = static_cast<double>(lev) - levold;
/* SOURCE exnmat.for:3332 */
/*<       if(dlev.gt.0.0)then >*/
	    if (dlev > (float)0.) {
/*               Level is rising but has it risen enough. */
/* SOURCE exnmat.for:3334 */
/*<       if(abs(dlev).gt.et*mnrate)then >*/
		if (dabs(dlev) > static_cast<double>(et) * mnrate) {
/*                 Use the rising stage table */
/* SOURCE exnmat.for:3336 */
/*<       tbuse=tbrise >*/
		    tbuse = tbrise;
/* SOURCE exnmat.for:3337 */
/*<       endif >*/
		}
/* SOURCE exnmat.for:3338 */
/*<       else >*/
	    } else {
/*               Level is falling but has it fallen enough. */
/* SOURCE exnmat.for:3340 */
/*<       if(abs(dlev).gt.et*mnrate)then >*/
		if (dabs(dlev) > static_cast<double>(et) * mnrate) {
/*                 Use the falling stage table */
/* SOURCE exnmat.for:3342 */
/*<       tbuse=tbfall >*/
		    tbuse = tbfall;
/* SOURCE exnmat.for:3343 */
/*<       endif >*/
		}
/* SOURCE exnmat.for:3344 */
/*<       endif >*/
	    }
/*             Save the table used.  May have changed. */
/* SOURCE exnmat.for:3347 */
/*<       itab(ipt+7)=tbuse >*/
	    itab[ipt + 7] = tbuse;
/*              WRITE(STD6,*) ' Using table#=',ITAB(TBUSE+1) */
/*             Find the speed given by the table for the current level. */
/* SOURCE exnmat.for:3352 */
/*<       calllktab(tbuse,lev,1,pdot,ntab,dpdot) >*/
	    lktab_(&tbuse, &lev, &feq_gen_c_d_1, &pdot, &ntab, &dpdot);
/*              WRITE(STD6,*) ' Table speed=',PDOT */
/* SOURCE exnmat.for:3357 */
/*<       if(blktyp.eq.2)then >*/
	    if (blktyp == 2) {
/*               One-way pump. */
/*               Select the action for this control point */
/* SOURCE exnmat.for:3360 */
/*<       if(pdot.lt.0.0)then >*/
		if (pdot < (float)0.) {
/*                 Turn off the pump */
/* SOURCE exnmat.for:3362 */
/*<       spd=0 >*/
		    spd = (float)0.;
/* SOURCE exnmat.for:3363 */
/*<       elseif(pdot.eq.0.0)then >*/
		} else if (pdot == (float)0.) {
/*                 Leave the pump at its current setting */
/* SOURCE exnmat.for:3365 */
/*<       spd=pold >*/
		    spd = pold;
/* SOURCE exnmat.for:3366 */
/*<       else >*/
		} else {
/*                 Turn pump on at relative speed PDOT */
/* SOURCE exnmat.for:3368 */
/*<       spd=pdot >*/
		    spd = pdot;
/* SOURCE exnmat.for:3369 */
/*<       endif >*/
		}
/* SOURCE exnmat.for:3371 */
/*<       else >*/
	    } else {
/*               Two-way pump */
/*               When speed is > PUMP_EPS the direction remains the same */
/*               as originally given by the user.  When speed < -PUMP_EPS */
/*               the direction is opposite to that first given by the user. */
/*               If the speed is = + or - PUMP_EPS then the existing speed */
/*               is retained.  If the speed is within (-PUMP_EPS, PUMP_EPS) */
/*               then the pump is turned off. */
/*               Select the action for this control point */
/* SOURCE exnmat.for:3380 */
/*<        >*/
		if (pdot < (float).0099900000000000006 && pdot > (float)
			-.0099900000000000006) {
/*                 Turn off the pump */
/* SOURCE exnmat.for:3383 */
/*<       spd=0 >*/
		    spd = (float)0.;
/* SOURCE exnmat.for:3384 */
/*<        >*/
		} else if ((feq_gen_r_d_1 = static_cast<double>(pdot) - (float).01, dabs(feq_gen_r_d_1)) < (float)
			1e-5 || (feq_gen_r_d_2 = static_cast<double>(pdot) + (float).01, dabs(feq_gen_r_d_2)) < (
			float)1e-5) {
/*                 Leave the pump at its current setting.  We must make */
/*                 sure to set the sign.  POLD only remembers the */
/*                 absolute value of the speed. */
/* SOURCE exnmat.for:3389 */
/*<       spd=pold >*/
		    spd = pold;
/* SOURCE exnmat.for:3390 */
/*<       if(pdot.lt.0.0)spd=-spd >*/
		    if (pdot < (float)0.) {
			spd = -spd;
		    }
/* SOURCE exnmat.for:3391 */
/*<       else >*/
		} else {
/*                 Turn pump on at relative speed PDOT */
/* SOURCE exnmat.for:3393 */
/*<       spd=pdot >*/
		    spd = pdot;
/* SOURCE exnmat.for:3394 */
/*<       endif >*/
		}
/*               Set the direction in EMC and then make speed positive. */
/* SOURCE exnmat.for:3396 */
/*<       emc_dir_pnt=itab(iptold+9) >*/
		feq_gen_emc_dir_pnt_d_ = itab[iptold + 9];
/*               ITAB(IPTOLD+8) contains the original pump direction */
/*               as given by the user.  The directions in the pump-speed */
/*               tables are relative to the original direction: SPD>0 */
/*               means keep the same direction; SPD<0 means change to */
/*               other direction. */
/* SOURCE exnmat.for:3402 */
/*<       emc(emc_dir_pnt)=itab(iptold+8)*sign(1.0,spd) >*/
		emc[feq_gen_emc_dir_pnt_d_] = itab[iptold + 8] * r_sign(&c_b215, &spd);
/* SOURCE exnmat.for:3404 */
/*<       spd=abs(spd) >*/
		spd = dabs(spd);
/*                WRITE(STD6,*) ' Direction in EMC=',EMC(EMC_DIR_PNT) */
/* SOURCE exnmat.for:3406 */
/*<       endif >*/
	    }
/*              WRITE(STD6,*) ' Speed used=',SPD */
/*             Select the priority for this control point.  Based on */
/*             state of the action requested. */
/* SOURCE exnmat.for:3410 */
/*<       if(spd.gt.0.0)then >*/
	    if (spd > (float)0.) {
/*               Select the pump-on priority */
/* SOURCE exnmat.for:3412 */
/*<       pri=itab(ipt+9) >*/
		pri = itab[ipt + 9];
/*               Make the speed value discrete. */
/* SOURCE exnmat.for:3414 */
/*<       spd=speeds*spd+0.99 >*/
		spd = static_cast<double>(static_cast<double>(speeds) * spd) + (float).99;
/* SOURCE exnmat.for:3415 */
/*<       spd=int(spd) >*/
		spd = (real) ((integer) spd);
/* SOURCE exnmat.for:3416 */
/*<       spd=spd/speeds >*/
		spd /= speeds;
/* SOURCE exnmat.for:3417 */
/*<       if(spd.gt.1.0)spd=1.0 >*/
		if (spd > (float)1.) {
		    spd = (float)1.;
		}
/* SOURCE exnmat.for:3418 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:3419 */
/*<       pri=itab(ipt+10) >*/
		pri = itab[ipt + 10];
/* SOURCE exnmat.for:3420 */
/*<       endif >*/
	    }
/*              WRITE(STD6,*) ' PRI=',PRI,' Discretized SPD=',SPD */
/*             Retain the speed that has the highest priority. */
/* SOURCE exnmat.for:3424 */
/*<       if(pri.lt.prig)then >*/
	    if (pri < prig) {
/* SOURCE exnmat.for:3425 */
/*<       prig=pri >*/
		prig = pri;
/* SOURCE exnmat.for:3426 */
/*<       pdotg=spd >*/
		pdotg = spd;
/*                WRITE(STD6,*) ' RETAINED SETTING: PRIG=',PRIG, */
/*     A                     ' PDOTG=',SPD */
/* SOURCE exnmat.for:3429 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:3430 */
/*<       ipt=ipt+17 >*/
	    ipt += 17;
/* SOURCE exnmat.for:3432 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:3434 */
/*<       goto100 >*/
	goto L100;
/* SOURCE exnmat.for:3436 */
/*<   410 continue >*/
L410:
/*          WRITE(STD6,*) ' ' */
/*          WRITE(STD6,*) ' PRIG=',PRIG,' PDOTG=',PDOTG */
/*          WRITE(STD6,*) ' POLD=',POLD */
/*         SAVE THE OLD VALUE FOR BACKUP OF TIME */
/* SOURCE exnmat.for:3442 */
/*<       ftab(iptold+1)=pold >*/
	ftab[iptold + 1] = pold;
/* SOURCE exnmat.for:3443 */
/*<       if(blktyp.eq.1)then >*/
	if (blktyp == 1) {
/* SOURCE exnmat.for:3444 */
/*<       if(pdot.gt.0.0)then >*/
	    if (pdot > (float)0.) {
/*             If the action is to open the gate and the gate is out of */
/*             the water, then ignore the request and reset the gate */
/*             using values left in EMC by UFGATE.  Note: Only UFGATE */
/*             sets this location in EMC to a non-zero value.  The location */
/*             is always relative to the opening fraction. */
/* SOURCE exnmat.for:3450 */
/*<       idum=emc(padrs+1) >*/
		*idum = emc[padrs + 1];
/* SOURCE exnmat.for:3451 */
/*<       if(rdum.gt.0.0)then >*/
		if (*rdum > (float)0.) {
/*               Gate was out of the water at end of last time step. */
/* SOURCE exnmat.for:3453 */
/*<       ftab(iptold)=rdum >*/
		    ftab[iptold] = *rdum;
/* SOURCE exnmat.for:3454 */
/*<       emc(padrs)=idum >*/
		    emc[padrs] = *idum;
/* SOURCE exnmat.for:3455 */
/*<       goto500 >*/
		    goto L500;
/* SOURCE exnmat.for:3456 */
/*<       endif >*/
		}
/* SOURCE exnmat.for:3457 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:3458 */
/*<       pold=pold+pdotg*dthr >*/
	    pold += static_cast<double>(pdotg) * *dthr;
/* SOURCE exnmat.for:3459 */
/*<       if(pold.lt.0.0)pold=0.0 >*/
	    if (pold < (float)0.) {
		pold = (float)0.;
	    }
/* SOURCE exnmat.for:3460 */
/*<       if(pold.gt.1.0)pold=1.0 >*/
	    if (pold > (float)1.) {
		pold = (float)1.;
	    }
/* SOURCE exnmat.for:3461 */
/*<       ftab(iptold)=pold >*/
	    ftab[iptold] = pold;
/* SOURCE exnmat.for:3462 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:3463 */
/*<       pold=pdotg >*/
	    pold = pdotg;
/* SOURCE exnmat.for:3464 */
/*<       ftab(iptold)=pdotg >*/
	    ftab[iptold] = pdotg;
/* SOURCE exnmat.for:3465 */
/*<       endif >*/
	}
/*         Put the current setting in the control structure */
/*         description. */
/* SOURCE exnmat.for:3469 */
/*<       rdum=pold >*/
	*rdum = pold;
/* SOURCE exnmat.for:3470 */
/*<       emc(padrs)=idum >*/
	emc[padrs] = *idum;
/*          WRITE(STD6,*) ' Value set in EMC=', POLD */
/*          WRITE(STD6,*) ' ' */
/* SOURCE exnmat.for:3474 */
/*<   500 continue >*/
L500:
	;
    }
/* SOURCE exnmat.for:3475 */
/*<       return >*/
    return 0;
/* SOURCE exnmat.for:3476 */
/*<       end >*/
} /* oper_ */

#undef rtmp
#undef rdum
#undef idum
#undef itab
#undef ftab





/* SOURCE exnmat.for:3480 */
/*<        >*/
/* Subroutine */ int pump_(integer *ipnt, integer *feq_storage_emc, integer *mlemc, real *
	grav, real *twog, real *feq_storage_ye2, real *feq_storage_ze, real *feq_storage_qe2, integer *nex, 
	doublereal *jtime, integer *stdout, real *res, real *pyl, real *pql, 
	real *pyr, real *pqr)
{
    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1;
    static real equiv_0[1];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double r_sign(real *, real *);

    /* Local variables */
    real b, j, k, db, dh, al, dk, el, ar, er, dt, ql, tl, qp, qr, yl, tr, yr, 
	    dhn;
    integer dir, dnn;
    real dqp, kvh, vhl;
    integer qnn;
    real vhr;
    integer unn;
    real zin, zwl, zwr;
    integer ntab;
    real alpl, dspd, dkvh;
#define idum (feq::BitView<integer>(equiv_0, sizeof(equiv_0)))
    real alpr, hsub;
#define rdum (equiv_0)
    real dalpl, ddhql, dalpr, aexit, ddhqr, ddhyl, ddhyr, dqpls, lforq, qforh;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    integer sysgn;
    real zexit, vhdfac;
    integer spdtab;
    real vhufac, dqforh, dlforq, dvheqp, dvhlql;
    integer ispout, tbexit, tbflow, tbloss;
    real dvhlyl, dvhrqr, dvhryr, relspd, vhexit;
    extern /* Subroutine */ int xlktal_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *), 
	    lktstab_(integer *, doublereal *, real *, integer *, real *);

/*     + + + PURPOSE + + + */
/*     Compute flow through a variable-head variable-speed pump.  Only */
/*     pumps with a unique value of flow for each head are valid. */
/* SOURCE exnmat.for:3489 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:3491 */
/*<       integeripnt,mlemc,nex,stdout >*/
/* SOURCE exnmat.for:3492 */
/*<       integeremc(mlemc) >*/
/* SOURCE exnmat.for:3493 */
/*<       realgrav,pql,pqr,pyl,pyr,qe2(nex),res,twog,ye2(nex),ze(nex) >*/
/* SOURCE exnmat.for:3495 */
/*<       real*8jtime >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IPNT   - pointer into EMC for description of control structure */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     MLEMC  - maximum length of EMC(*) */
/*     GRAV   - value of acceleration due to gravity */
/*     TWOG   - twice gravitational acceleration */
/*     YE2    - depths at exterior nodes at start of time step */
/*     ZE     - elevation of datum for depth at exterior node */
/*     QE2    - flow at exterior nodes at end of time step */
/*     NEX    - number of exterior nodes in the model */
/*     TIME   - elapsed time in seconds from start of run */
/*     RES    - value of the residual function */
/*     PYL    - partial derivative of residual function wrt depth at */
/*               left node */
/*     PQL    - partial derivative of residual function wrt flow at left */
/*               node */
/*     PYR    - partial derivative of residual function wrt depth at */
/*               right node */
/*     PQR    - partial derivative of residual function wrt flow at right */
/*               node */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE exnmat.for:3519 */
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
/* INCLUDE exnmat.for:3520 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE exnmat.for:3523 */
/*<        >*/
/* SOURCE exnmat.for:3525 */
/*<        >*/
/*     + + + EQUIVALENCES + + + */
/* SOURCE exnmat.for:3533 */
/*<       equivalence(idum,rdum) >*/
/*     + + + INTRINSICS + + + */
/* SOURCE exnmat.for:3536 */
/*<       intrinsicabs,sign >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE exnmat.for:3539 */
/*<       externallktab,xlktal >*/
/* *********************************************************************** */
/*     OBTAIN BASIC INFORMATION FROM EMC */
/* SOURCE exnmat.for:3543 */
/*<       unn=emc(ipnt+2) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    feq::IndexedPointer<real> qe2(feq_storage_qe2, 1);

    feq::IndexedPointer<real> ze(feq_storage_ze, 1);

    feq::IndexedPointer<real> ye2(feq_storage_ye2, 1);

    /* Function Body */
    unn = emc[*ipnt + 2];
/* SOURCE exnmat.for:3544 */
/*<       dnn=emc(ipnt+3) >*/
    dnn = emc[*ipnt + 3];
/* SOURCE exnmat.for:3545 */
/*<       qnn=emc(ipnt+4) >*/
    qnn = emc[*ipnt + 4];
/*     ISPOUT gives the pointer into the gate/pump name table for */
/*     possible output to the special output file.  If no name */
/*     is given ISPOUT is zero.  However slots exist for zero subscript */
/*     in the vectors.  Therefore no testing need be done. */
/* SOURCE exnmat.for:3551 */
/*<       ispout=emc(ipnt+21) >*/
    ispout = emc[*ipnt + 21];
/* SOURCE exnmat.for:3553 */
/*<       idum=emc(ipnt+19) >*/
    *idum = emc[*ipnt + 19];
/* SOURCE exnmat.for:3554 */
/*<       relspd=rdum >*/
    relspd = *rdum;
/*      WRITE(STDOUT,*) ' Entering PUMP: RELSPD=',RELSPD */
/* SOURCE exnmat.for:3556 */
/*<       spdtab=emc(ipnt+10) >*/
    spdtab = emc[*ipnt + 10];
/* SOURCE exnmat.for:3557 */
/*<       if(spdtab.lt.0)then >*/
    if (spdtab < 0) {
/*       Pump speed given directly by a time series table. */
/* SOURCE exnmat.for:3559 */
/*<       calllktstab(-spdtab,jtime,relspd,ntab,dspd) >*/
	feq_gen_i_d_1 = -spdtab;
	lktstab_(&feq_gen_i_d_1, jtime, &relspd, &ntab, &dspd);
/* SOURCE exnmat.for:3562 */
/*<       elseif(spdtab.eq.0)then >*/
    } else if (spdtab == 0) {
/*       Force pump to operate at normal speed at all times. */
/* SOURCE exnmat.for:3564 */
/*<       relspd=1.0 >*/
	relspd = (float)1.;
/*       SPDTAB < 0 means that the relative speed has been set by */
/*       an operation control block.  The current value is already */
/*       in RELSPD */
/* SOURCE exnmat.for:3568 */
/*<       endif >*/
    }
/*     Get the current flow through the pump */
/* SOURCE exnmat.for:3572 */
/*<       qp=qe2(qnn) >*/
    qp = qe2[qnn];
/*      WRITE(STDOUT,*) ' Entering PUMP: QP=',QP */
/*     Is the pump on? */
/* SOURCE exnmat.for:3576 */
/*<       if(relspd.eq.0.0)then >*/
    if (relspd == (float)0.) {
/*       No.  Force flow at the flow node to be zero. */
/*       Store the current speed for possible reporting in Special */
/*       Output.  Set the sign to reflect the changes in flow */
/*       direction. */
/* SOURCE exnmat.for:3581 */
/*<       gopen(ispout)=relspd >*/
	gate1_1.gopen[ispout] = relspd;
/* SOURCE exnmat.for:3582 */
/*<       res=qp >*/
	*res = qp;
/* SOURCE exnmat.for:3583 */
/*<       pql=0.0 >*/
	*pql = (float)0.;
/* SOURCE exnmat.for:3584 */
/*<       pyl=0.0 >*/
	*pyl = (float)0.;
/* SOURCE exnmat.for:3585 */
/*<       pqr=0.0 >*/
	*pqr = (float)0.;
/* SOURCE exnmat.for:3586 */
/*<       pyr=0.0 >*/
	*pyr = (float)0.;
/* SOURCE exnmat.for:3587 */
/*<       if(qnn.eq.unn)then >*/
	if (qnn == unn) {
/* SOURCE exnmat.for:3588 */
/*<       pql=1.0 >*/
	    *pql = (float)1.;
/* SOURCE exnmat.for:3589 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:3590 */
/*<       pqr=1.0 >*/
	    *pqr = (float)1.;
/* SOURCE exnmat.for:3591 */
/*<       endif >*/
	}
/*        WRITE(STDOUT,*) ' PUMP IS OFF' */
/* SOURCE exnmat.for:3593 */
/*<       fclass(ispout)='     OFF' >*/
	s_copy(gate2_1.fclass + (ispout << 3), const_cast<char*>("     OFF"), (ftnlen)8, (ftnlen)
		8);
/* SOURCE exnmat.for:3594 */
/*<       fclass_code(ispout)=7 >*/
	gate1_1.feq_gen_fclass_code_d_[ispout] = 7;
/* SOURCE exnmat.for:3595 */
/*<       else >*/
    } else {
/*       Yes, the pump is on. */
/* SOURCE exnmat.for:3597 */
/*<       dir=emc(ipnt+6) >*/
	dir = emc[*ipnt + 6];
/*       Store the current speed for possible reporting in Special */
/*       Output.  Set the sign to reflect the changes in flow */
/*       direction. */
/* SOURCE exnmat.for:3601 */
/*<       if(dir*emc(ipnt+22).gt.0)then >*/
	if (dir * emc[*ipnt + 22] > 0) {
/* SOURCE exnmat.for:3602 */
/*<       gopen(ispout)=relspd >*/
	    gate1_1.gopen[ispout] = relspd;
/* SOURCE exnmat.for:3603 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:3604 */
/*<       gopen(ispout)=-relspd >*/
	    gate1_1.gopen[ispout] = -relspd;
/* SOURCE exnmat.for:3605 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:3607 */
/*<       idum=emc(ipnt+15) >*/
	*idum = emc[*ipnt + 15];
/* SOURCE exnmat.for:3608 */
/*<       zin=rdum >*/
	zin = *rdum;
/* SOURCE exnmat.for:3609 */
/*<       yl=ye2(unn) >*/
	yl = ye2[unn];
/* SOURCE exnmat.for:3610 */
/*<       yr=ye2(dnn) >*/
	yr = ye2[dnn];
/* SOURCE exnmat.for:3611 */
/*<       zwl=ze(unn)+yl >*/
	zwl = static_cast<double>(ze[unn]) + yl;
/* SOURCE exnmat.for:3612 */
/*<       zwr=ze(dnn)+yr >*/
	zwr = static_cast<double>(ze[dnn]) + yr;
/*       Is the intake under water? */
/* SOURCE exnmat.for:3614 */
/*<       if((dir.gt.0.and.zwl.lt.zin).or.(dir.lt.0.and.zwr.lt.zin))then >*/
	if (dir > 0 && zwl < zin || dir < 0 && zwr < zin) {
/*         No, the intake is not under water.  Force the flow to zero. */
/* SOURCE exnmat.for:3617 */
/*<       res=qp >*/
	    *res = qp;
/* SOURCE exnmat.for:3618 */
/*<       pql=0.0 >*/
	    *pql = (float)0.;
/* SOURCE exnmat.for:3619 */
/*<       pyl=0.0 >*/
	    *pyl = (float)0.;
/* SOURCE exnmat.for:3620 */
/*<       pqr=0.0 >*/
	    *pqr = (float)0.;
/* SOURCE exnmat.for:3621 */
/*<       pyr=0.0 >*/
	    *pyr = (float)0.;
/* SOURCE exnmat.for:3622 */
/*<       fclass(ispout)='  NO H2O' >*/
	    s_copy(gate2_1.fclass + (ispout << 3), const_cast<char*>("  NO H2O"), (ftnlen)8, (
		    ftnlen)8);
/* SOURCE exnmat.for:3623 */
/*<       fclass_code(ispout)=8 >*/
	    gate1_1.feq_gen_fclass_code_d_[ispout] = 8;
/* SOURCE exnmat.for:3624 */
/*<       if(qnn.eq.unn)then >*/
	    if (qnn == unn) {
/* SOURCE exnmat.for:3625 */
/*<       pql=1.0 >*/
		*pql = (float)1.;
/* SOURCE exnmat.for:3626 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:3627 */
/*<       pqr=1.0 >*/
		*pqr = (float)1.;
/* SOURCE exnmat.for:3628 */
/*<       endif >*/
	    }
/*          WRITE(STDOUT,*) ' Intake above water!' */
/*          WRITE(STDOUT,*) ' DIR=',DIR,' ZWL=',ZWL,' ZWR=',ZWR,' ZIN=' */
/*     A                     ,ZIN */
/* SOURCE exnmat.for:3632 */
/*<       else >*/
	} else {
/*          WRITE(STDOUT,*) ' PUMP SPEED=',RELSPD */
/*         Here the pump is on and water is available to pump. */
/* SOURCE exnmat.for:3636 */
/*<       sysgn=emc(ipnt+5) >*/
	    sysgn = emc[*ipnt + 5];
/* SOURCE exnmat.for:3637 */
/*<       tbflow=emc(ipnt+7) >*/
	    tbflow = emc[*ipnt + 7];
/* SOURCE exnmat.for:3638 */
/*<       tbloss=emc(ipnt+8) >*/
	    tbloss = emc[*ipnt + 8];
/* SOURCE exnmat.for:3639 */
/*<       tbexit=emc(ipnt+9) >*/
	    tbexit = emc[*ipnt + 9];
/*         Offsets 11 and 12 used directly for velocity head computation. */
/* SOURCE exnmat.for:3641 */
/*<       idum=emc(ipnt+13) >*/
	    *idum = emc[*ipnt + 13];
/* SOURCE exnmat.for:3642 */
/*<       zexit=rdum >*/
	    zexit = *rdum;
/* SOURCE exnmat.for:3643 */
/*<       idum=emc(ipnt+14) >*/
	    *idum = emc[*ipnt + 14];
/* SOURCE exnmat.for:3644 */
/*<       aexit=rdum >*/
	    aexit = *rdum;
/* SOURCE exnmat.for:3645 */
/*<       idum=emc(ipnt+16) >*/
	    *idum = emc[*ipnt + 16];
/* SOURCE exnmat.for:3646 */
/*<       vhufac=rdum >*/
	    vhufac = *rdum;
/* SOURCE exnmat.for:3647 */
/*<       idum=emc(ipnt+17) >*/
	    *idum = emc[*ipnt + 17];
/* SOURCE exnmat.for:3648 */
/*<       vhdfac=rdum >*/
	    vhdfac = *rdum;
/*          WRITE(STDOUT,*) ' VHUFAC=',VHUFAC,' VHDFAC=',VHDFAC */
/*         At this point the pump speed has already been normalized rel- */
/*         ative to the pumps standard speed.  Thus if the pump is */
/*         constant speed, RELSPD=1.0 if the pump is on, and zero */
/*         otherwise.  A pump at half standard speed has RELSPD = 0.5. */
/*         In this routine the designations of U and L refer to the */
/*         upstream node as given by the user and D and R refer to */
/*         the downstream node.  The direction of flow is independent */
/*         of these designations.  Thus the outlet of the pump could */
/*         be at the upstream node.  The sign of the flow at the flow */
/*         node may be negative.   This does not mean reverse flow */
/*         through the pump. */
/* SOURCE exnmat.for:3663 */
/*<       ql=qe2(unn) >*/
	    ql = qe2[unn];
/* SOURCE exnmat.for:3664 */
/*<       qr=qe2(dnn) >*/
	    qr = qe2[dnn];
/* SOURCE exnmat.for:3665 */
/*<       el=zwl >*/
	    el = zwl;
/* SOURCE exnmat.for:3666 */
/*<       er=zwr >*/
	    er = zwr;
/*         Compute the velocity heads if required. */
/* SOURCE exnmat.for:3668 */
/*<       if(vhufac.gt.0.0)then >*/
	    if (vhufac > (float)0.) {
/* SOURCE exnmat.for:3669 */
/*<       callxlktal(emc(ipnt+11),yl,al,tl,dt,j,k,dk,b,db,alpl,dalpl) >*/
		xlktal_(&emc[*ipnt + 11], &yl, &al, &tl, &dt, &j, &k, &dk, &b,
			 &db, &alpl, &dalpl);
/* SOURCE exnmat.for:3673 */
/*<       vhl=(ql/al)**2/twog >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = static_cast<double>(ql) / al;
		vhl = static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / *twog;
/*           Compute the derivatives of the velocity head with respect */
/*           to the depth on the left and the flow on the left. */
/* SOURCE exnmat.for:3676 */
/*<       dvhlyl=vhufac*vhl*(dalpl-2.*alpl*tl/al) >*/
		dvhlyl = static_cast<double>(static_cast<double>(vhufac) * vhl) * (static_cast<double>(dalpl) - static_cast<double>(static_cast<double>(static_cast<double>(alpl) * (float)2.) * tl) / al);
/* SOURCE exnmat.for:3677 */
/*<       dvhlql=vhufac*alpl*ql/(grav*al**2) >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = al;
		dvhlql = static_cast<double>(static_cast<double>(static_cast<double>(vhufac) * alpl) * ql) / (static_cast<double>(*grav) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1));
/* SOURCE exnmat.for:3678 */
/*<       vhl=vhufac*alpl*vhl >*/
		vhl = static_cast<double>(static_cast<double>(vhufac) * alpl) * vhl;
/* SOURCE exnmat.for:3679 */
/*<       el=el+vhl >*/
		el += vhl;
/* SOURCE exnmat.for:3680 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:3681 */
/*<       dvhlyl=0.0 >*/
		dvhlyl = (float)0.;
/* SOURCE exnmat.for:3682 */
/*<       dvhlql=0.0 >*/
		dvhlql = (float)0.;
/* SOURCE exnmat.for:3683 */
/*<       vhl=0.0 >*/
		vhl = (float)0.;
/* SOURCE exnmat.for:3684 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:3685 */
/*<       if(vhdfac.gt.0.0)then >*/
	    if (vhdfac > (float)0.) {
/* SOURCE exnmat.for:3686 */
/*<       callxlktal(emc(ipnt+12),yr,ar,tr,dt,j,k,dk,b,db,alpr,dalpr) >*/
		xlktal_(&emc[*ipnt + 12], &yr, &ar, &tr, &dt, &j, &k, &dk, &b,
			 &db, &alpr, &dalpr);
/* SOURCE exnmat.for:3690 */
/*<       vhr=(qr/ar)**2/twog >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = static_cast<double>(qr) / ar;
		vhr = static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / *twog;
/* SOURCE exnmat.for:3691 */
/*<       dvhryr=vhdfac*vhr*(dalpr-2.*alpr*tr/ar) >*/
		dvhryr = static_cast<double>(static_cast<double>(vhdfac) * vhr) * (static_cast<double>(dalpr) - static_cast<double>(static_cast<double>(static_cast<double>(alpr) * (float)2.) * tr) / ar);
/* SOURCE exnmat.for:3692 */
/*<       dvhrqr=vhdfac*alpr*qr/(grav*ar**2) >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = ar;
		dvhrqr = static_cast<double>(static_cast<double>(static_cast<double>(vhdfac) * alpr) * qr) / (static_cast<double>(*grav) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1));
/* SOURCE exnmat.for:3693 */
/*<       vhr=vhdfac*alpr*vhr >*/
		vhr = static_cast<double>(static_cast<double>(vhdfac) * alpr) * vhr;
/* SOURCE exnmat.for:3694 */
/*<       er=er+vhr >*/
		er += vhr;
/* SOURCE exnmat.for:3695 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:3696 */
/*<       dvhryr=0.0 >*/
		dvhryr = (float)0.;
/* SOURCE exnmat.for:3697 */
/*<       dvhrqr=0.0 >*/
		dvhrqr = (float)0.;
/* SOURCE exnmat.for:3698 */
/*<       vhr=0.0 >*/
		vhr = (float)0.;
/* SOURCE exnmat.for:3699 */
/*<       endif >*/
	    }
/*         Find the losses from entrance and conduits if given. */
/* SOURCE exnmat.for:3702 */
/*<       if(tbloss.gt.0)then >*/
	    if (tbloss > 0) {
/* SOURCE exnmat.for:3703 */
/*<       calllktab(tbloss,abs(qp),1,lforq,ntab,dlforq) >*/
		feq_gen_r_d_1 = dabs(qp);
		lktab_(&tbloss, &feq_gen_r_d_1, &feq_gen_c_d_1, &lforq, &ntab, &dlforq);
/* SOURCE exnmat.for:3706 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:3707 */
/*<       lforq=0.0 >*/
		lforq = (float)0.;
/* SOURCE exnmat.for:3708 */
/*<       dlforq=0.0 >*/
		dlforq = (float)0.;
/* SOURCE exnmat.for:3709 */
/*<       endif >*/
	    }
/*         Compute the exit velocity head. */
/* SOURCE exnmat.for:3713 */
/*<       vhexit=(qp/aexit)**2/twog >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(qp) / aexit;
	    vhexit = static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / *twog;
/*         Compute derivative with respect to the pump flow */
/*         excluding exit losses */
/* SOURCE exnmat.for:3717 */
/*<       dvheqp=qp/(grav*aexit**2) >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = aexit;
	    dvheqp = static_cast<double>(qp) / (static_cast<double>(*grav) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1));
/* SOURCE exnmat.for:3718 */
/*<       dqp=sign(1.0,qp)*dlforq+dvheqp >*/
	    dqp = r_sign(&c_b215, &qp) * dlforq + dvheqp;
/* SOURCE exnmat.for:3720 */
/*<       if(dir.gt.0)then >*/
	    if (dir > 0) {
/*           Pumping from upstream node to downstream node.  Compute */
/*           the head difference on the pump using the current estimate */
/*           of pump flow for any flow dependent terms. */
/* SOURCE exnmat.for:3725 */
/*<       if(zwr.lt.zexit)then >*/
		if (zwr < zexit) {
/*             Discharge is unsubmerged. */
/* SOURCE exnmat.for:3727 */
/*<       fclass(ispout)='      FP' >*/
		    s_copy(gate2_1.fclass + (ispout << 3), const_cast<char*>("      FP"), (
			    ftnlen)8, (ftnlen)8);
/* SOURCE exnmat.for:3728 */
/*<       fclass_code(ispout)=9 >*/
		    gate1_1.feq_gen_fclass_code_d_[ispout] = 9;
/* SOURCE exnmat.for:3730 */
/*<       dh=lforq+zexit+vhexit-vhl-zwl >*/
		    dh = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(lforq) + zexit) + vhexit) - vhl) - zwl;
/*              WRITE(STDOUT,*) ' U to D free: LFORQ=',LFORQ,' ZEXIT=', */
/*     A           ZEXIT,' VHEXIT=',VHEXIT,' VHL=',VHL,' ZWL=',ZWL, */
/*     B           ' DH=',DH */
/* SOURCE exnmat.for:3734 */
/*<       ddhyl=-dvhlyl-1.0 >*/
		    ddhyl = static_cast<double>(-dvhlyl) - (float)1.;
/* SOURCE exnmat.for:3735 */
/*<       ddhql=-dvhlql >*/
		    ddhql = -dvhlql;
/* SOURCE exnmat.for:3736 */
/*<       ddhyr=0.0 >*/
		    ddhyr = (float)0.;
/* SOURCE exnmat.for:3737 */
/*<       ddhqr=0.0 >*/
		    ddhqr = (float)0.;
/* SOURCE exnmat.for:3738 */
/*<       if(qnn.eq.unn)then >*/
		    if (qnn == unn) {
/* SOURCE exnmat.for:3739 */
/*<       ddhql=ddhql+dqp >*/
			ddhql += dqp;
/* SOURCE exnmat.for:3740 */
/*<       else >*/
		    } else {
/* SOURCE exnmat.for:3741 */
/*<       ddhqr=ddhqr+dqp >*/
			ddhqr += dqp;
/* SOURCE exnmat.for:3742 */
/*<       endif >*/
		    }
/* SOURCE exnmat.for:3743 */
/*<       else >*/
		} else {
/*             Discharge is submerged. */
/* SOURCE exnmat.for:3745 */
/*<       fclass(ispout)='      SP' >*/
		    s_copy(gate2_1.fclass + (ispout << 3), const_cast<char*>("      SP"), (
			    ftnlen)8, (ftnlen)8);
/* SOURCE exnmat.for:3746 */
/*<       fclass_code(ispout)=10 >*/
		    gate1_1.feq_gen_fclass_code_d_[ispout] = 10;
/* SOURCE exnmat.for:3747 */
/*<       hsub=zwr-zexit >*/
		    hsub = static_cast<double>(zwr) - zexit;
/* SOURCE exnmat.for:3748 */
/*<       if(tbexit.gt.0)then >*/
		    if (tbexit > 0) {
/* SOURCE exnmat.for:3749 */
/*<       calllktab(tbexit,hsub,1,kvh,ntab,dkvh) >*/
			lktab_(&tbexit, &hsub, &feq_gen_c_d_1, &kvh, &ntab, &dkvh);
/* SOURCE exnmat.for:3752 */
/*<       else >*/
		    } else {
/* SOURCE exnmat.for:3753 */
/*<       kvh=1.0 >*/
			kvh = (float)1.;
/* SOURCE exnmat.for:3754 */
/*<       dkvh=0.0 >*/
			dkvh = (float)0.;
/* SOURCE exnmat.for:3755 */
/*<       endif >*/
		    }
/*             Compute derivative with respect to pump flow */
/*             including the loss term on the exit velocity head */
/* SOURCE exnmat.for:3758 */
/*<       dqpls=sign(1.0,qp)*dlforq+kvh*dvheqp >*/
		    dqpls = r_sign(&c_b215, &qp) * dlforq + static_cast<double>(kvh) * dvheqp;
/* SOURCE exnmat.for:3760 */
/*<       dh=lforq+zwr+vhr+kvh*(vhexit-vhr)-vhl-zwl >*/
		    dh = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(lforq) + zwr) + vhr) + static_cast<double>(kvh) * (static_cast<double>(vhexit) - vhr)) - vhl) - zwl;
/*              WRITE(STDOUT,*) ' U to D sub: LFORQ=',LFORQ,' ZWR=', */
/*     A           ZWR,' VHR=',VHR, ' VHEXIT=',VHEXIT,' VHL=',VHL, */
/*     B           ' ZWL=',ZWL,' DH=',DH */
/* SOURCE exnmat.for:3766 */
/*<       ddhyl=-dvhlyl-1.0 >*/
		    ddhyl = static_cast<double>(-dvhlyl) - (float)1.;
/* SOURCE exnmat.for:3767 */
/*<       ddhql=-dvhlql >*/
		    ddhql = -dvhlql;
/* SOURCE exnmat.for:3768 */
/*<       ddhyr=1.0+dvhryr*(1.0-kvh)+dkvh*(vhexit-vhr) >*/
		    ddhyr = static_cast<double>(static_cast<double>(static_cast<double>(dvhryr) * (static_cast<double>((float)1.) - kvh)) + (float)1.) + static_cast<double>(dkvh) * (
			    static_cast<double>(vhexit) - vhr);
/* SOURCE exnmat.for:3769 */
/*<       ddhqr=dvhrqr*(1.-kvh) >*/
		    ddhqr = static_cast<double>(dvhrqr) * (static_cast<double>((float)1.) - kvh);
/* SOURCE exnmat.for:3770 */
/*<       if(qnn.eq.unn)then >*/
		    if (qnn == unn) {
/* SOURCE exnmat.for:3771 */
/*<       ddhql=ddhql+dqpls >*/
			ddhql += dqpls;
/* SOURCE exnmat.for:3772 */
/*<       else >*/
		    } else {
/* SOURCE exnmat.for:3773 */
/*<       ddhqr=ddhqr+dqpls >*/
			ddhqr += dqpls;
/* SOURCE exnmat.for:3774 */
/*<       endif >*/
		    }
/* SOURCE exnmat.for:3775 */
/*<       endif >*/
		}
/* SOURCE exnmat.for:3776 */
/*<       else >*/
	    } else {
/*           Pumping from downstream node to upstream node. */
/* SOURCE exnmat.for:3778 */
/*<       if(zwl.lt.zexit)then >*/
		if (zwl < zexit) {
/*             Discharge is unsubmerged. */
/* SOURCE exnmat.for:3780 */
/*<       fclass(ispout)='      FP' >*/
		    s_copy(gate2_1.fclass + (ispout << 3), const_cast<char*>("      FP"), (
			    ftnlen)8, (ftnlen)8);
/* SOURCE exnmat.for:3781 */
/*<       fclass_code(ispout)=9 >*/
		    gate1_1.feq_gen_fclass_code_d_[ispout] = 9;
/* SOURCE exnmat.for:3782 */
/*<       dh=lforq+zexit+vhexit-vhr-zwr >*/
		    dh = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(lforq) + zexit) + vhexit) - vhr) - zwr;
/*              WRITE(STDOUT,*) ' D to U free: LFORQ=',LFORQ,' ZEXIT=', */
/*     A           ZEXIT,' VHEXIT=',VHEXIT,' VHR=',VHR,' ZWR=',ZWR, */
/*     B           ' DH=',DH */
/* SOURCE exnmat.for:3788 */
/*<       ddhyr=-dvhryr-1.0 >*/
		    ddhyr = static_cast<double>(-dvhryr) - (float)1.;
/* SOURCE exnmat.for:3789 */
/*<       ddhqr=-dvhrqr >*/
		    ddhqr = -dvhrqr;
/* SOURCE exnmat.for:3790 */
/*<       ddhyl=0 >*/
		    ddhyl = (float)0.;
/* SOURCE exnmat.for:3791 */
/*<       ddhql=0 >*/
		    ddhql = (float)0.;
/* SOURCE exnmat.for:3792 */
/*<       if(qnn.eq.unn)then >*/
		    if (qnn == unn) {
/* SOURCE exnmat.for:3793 */
/*<       ddhql=ddhql+dqp >*/
			ddhql += dqp;
/* SOURCE exnmat.for:3794 */
/*<       else >*/
		    } else {
/* SOURCE exnmat.for:3795 */
/*<       ddhqr=ddhqr+dqp >*/
			ddhqr += dqp;
/* SOURCE exnmat.for:3796 */
/*<       endif >*/
		    }
/* SOURCE exnmat.for:3797 */
/*<       else >*/
		} else {
/*             Discharge is submerged. */
/* SOURCE exnmat.for:3799 */
/*<       fclass(ispout)='      SP' >*/
		    s_copy(gate2_1.fclass + (ispout << 3), const_cast<char*>("      SP"), (
			    ftnlen)8, (ftnlen)8);
/* SOURCE exnmat.for:3800 */
/*<       fclass_code(ispout)=10 >*/
		    gate1_1.feq_gen_fclass_code_d_[ispout] = 10;
/* SOURCE exnmat.for:3801 */
/*<       hsub=zwl-zexit >*/
		    hsub = static_cast<double>(zwl) - zexit;
/* SOURCE exnmat.for:3802 */
/*<       if(tbexit.gt.0)then >*/
		    if (tbexit > 0) {
/* SOURCE exnmat.for:3803 */
/*<       calllktab(tbexit,hsub,1,kvh,ntab,dkvh) >*/
			lktab_(&tbexit, &hsub, &feq_gen_c_d_1, &kvh, &ntab, &dkvh);
/* SOURCE exnmat.for:3806 */
/*<       else >*/
		    } else {
/* SOURCE exnmat.for:3807 */
/*<       kvh=1.0 >*/
			kvh = (float)1.;
/* SOURCE exnmat.for:3808 */
/*<       dkvh=0.0 >*/
			dkvh = (float)0.;
/* SOURCE exnmat.for:3809 */
/*<       endif >*/
		    }
/*             Compute derivative with respect to pump flow */
/*             including the loss term on the exit velocity head */
/* SOURCE exnmat.for:3812 */
/*<       dqpls=sign(1.0,qp)*dlforq+kvh*dvheqp >*/
		    dqpls = r_sign(&c_b215, &qp) * dlforq + static_cast<double>(kvh) * dvheqp;
/* SOURCE exnmat.for:3814 */
/*<       dh=lforq+zwl+vhl+kvh*(vhexit-vhl)-vhr-zwr >*/
		    dh = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(lforq) + zwl) + vhl) + static_cast<double>(kvh) * (static_cast<double>(vhexit) - vhl)) - vhr) - zwr;
/*              WRITE(STDOUT,*) ' D to U sub: LFORQ=',LFORQ,' ZWR=', */
/*     A           ZWR,' VHR=',VHR, ' VHEXIT=',VHEXIT,' VHL=',VHL, */
/*     B           ' ZWL=',ZWL,' DH=',DH */
/* SOURCE exnmat.for:3821 */
/*<       ddhyr=-dvhryr-1.0 >*/
		    ddhyr = static_cast<double>(-dvhryr) - (float)1.;
/* SOURCE exnmat.for:3822 */
/*<       ddhqr=-dvhrqr >*/
		    ddhqr = -dvhrqr;
/* SOURCE exnmat.for:3823 */
/*<       ddhyl=1.0+dvhlyl*(1.0-kvh)+dkvh*(vhexit-vhl) >*/
		    ddhyl = static_cast<double>(static_cast<double>(static_cast<double>(dvhlyl) * (static_cast<double>((float)1.) - kvh)) + (float)1.) + static_cast<double>(dkvh) * (
			    static_cast<double>(vhexit) - vhl);
/* SOURCE exnmat.for:3824 */
/*<       ddhql=dvhlql*(1.-kvh) >*/
		    ddhql = static_cast<double>(dvhlql) * (static_cast<double>((float)1.) - kvh);
/* SOURCE exnmat.for:3825 */
/*<       if(qnn.eq.unn)then >*/
		    if (qnn == unn) {
/* SOURCE exnmat.for:3826 */
/*<       ddhql=ddhql+dqpls >*/
			ddhql += dqpls;
/* SOURCE exnmat.for:3827 */
/*<       else >*/
		    } else {
/* SOURCE exnmat.for:3828 */
/*<       ddhqr=ddhqr+dqpls >*/
			ddhqr += dqpls;
/* SOURCE exnmat.for:3829 */
/*<       endif >*/
		    }
/* SOURCE exnmat.for:3830 */
/*<       endif >*/
		}
/* SOURCE exnmat.for:3831 */
/*<       endif >*/
	    }
/*         Now find the residual and its derivatives.  Find the */
/*         flow for the current speed and head difference. */
/*          WRITE(STDOUT,*) ' PUMP: DH=',DH, ' RELSPD=',RELSPD */
/* SOURCE exnmat.for:3837 */
/*<       dhn=dh/relspd**2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = relspd;
	    dhn = static_cast<double>(dh) / (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE exnmat.for:3838 */
/*<       calllktab(tbflow,dhn,1,qforh,ntab,dqforh) >*/
	    lktab_(&tbflow, &dhn, &feq_gen_c_d_1, &qforh, &ntab, &dqforh);
/*          WRITE(STDOUT,*) ' PUMP:at rescaled head=',DHN,' Flow=',QFORH, */
/*     A       ' DQFORH=',DQFORH */
/*         Use the relative speed to set the sign for values. */
/* SOURCE exnmat.for:3845 */
/*<       if(dir*sysgn.gt.0)then >*/
	    if (dir * sysgn > 0) {
/*           Pump flow > 0 at the flow node. */
/* SOURCE exnmat.for:3847 */
/*<       relspd=-relspd >*/
		relspd = -relspd;
/* SOURCE exnmat.for:3848 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:3850 */
/*<       res=qp+relspd*qforh >*/
	    *res = static_cast<double>(qp) + static_cast<double>(relspd) * qforh;
/* SOURCE exnmat.for:3851 */
/*<       dqforh=dqforh/relspd >*/
	    dqforh /= relspd;
/* SOURCE exnmat.for:3852 */
/*<       pyl=ddhyl*dqforh >*/
	    *pyl = static_cast<double>(ddhyl) * dqforh;
/* SOURCE exnmat.for:3853 */
/*<       pql=ddhql*dqforh >*/
	    *pql = static_cast<double>(ddhql) * dqforh;
/* SOURCE exnmat.for:3854 */
/*<       pyr=ddhyr*dqforh >*/
	    *pyr = static_cast<double>(ddhyr) * dqforh;
/* SOURCE exnmat.for:3855 */
/*<       pqr=ddhqr*dqforh >*/
	    *pqr = static_cast<double>(ddhqr) * dqforh;
/* SOURCE exnmat.for:3856 */
/*<       if(qnn.eq.unn)then >*/
	    if (qnn == unn) {
/* SOURCE exnmat.for:3857 */
/*<       pql=pql+1.0 >*/
		*pql += static_cast<double>((float)1.);
/* SOURCE exnmat.for:3858 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:3859 */
/*<       pqr=pqr+1.0 >*/
		*pqr += static_cast<double>((float)1.);
/* SOURCE exnmat.for:3860 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:3861 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:3862 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) 'Exit from PUMP:' */
/*      WRITE(STDOUT,*) ' RES=',RES */
/*      WRITE(STDOUT,*) ' PQL=',PQL,' PYL=',PYL,' PQR=',PQR,' PYR=',PYR */
/* SOURCE exnmat.for:3866 */
/*<       return >*/
    return 0;
/* SOURCE exnmat.for:3867 */
/*<       end >*/
} /* pump_ */

#undef rdum
#undef idum





/* SOURCE exnmat.for:3871 */
/*<       subroutinerdget(i,stdout,jt,dt,val) >*/
/* Subroutine */ int rdget_(integer *feq_gen_i_d_, integer *stdout, doublereal *jt, 
	doublereal *dt, real *val)
{
    /* Initialized data */

    static doublereal teps = 1e-6;
    static doublereal feq_gen_dss_eps_d_ = 5.2e-4;

    /* Format strings */
    static char fmt_50[] = "(/,\002 *BUG:XXX Need to backspace file attached\
 to unit=\002,i5,/,11x,\002Probable cause is a read buffer that is too small.\
\002)";
    static char fmt_51[] = "(\002 Above message issued while searching buffe\
r for HECDSS\002,\002 access in RDGET.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    integer s_rdue(cilist *), do_uio(integer *, char *, ftnlen), e_rdue(), 
	    s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_hecdss_block_d_(integer *, char *, integer 
	    *, integer *, char *, doublereal *, integer *, integer *, 
	    doublereal *, real *, integer *, ftnlen, ftnlen);
    integer j, l;
    doublereal p;
    integer feq_gen_desired_n_d_, lh, ll, lr, lt, lm1, lp1, knt, feq_gen_tmpvec_size_d_, minr, 
	    maxr;
    doublereal jtbase;
    integer nvalues;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__520 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__524 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__525 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__531 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Get value from the I-th connection file or HECDSS pathname. */
/* SOURCE exnmat.for:3878 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:3880 */
/*<       integeri,stdout >*/
/* SOURCE exnmat.for:3881 */
/*<       realval >*/
/* SOURCE exnmat.for:3882 */
/*<       real*8jt,dt >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     I      - index of the file in the time-series file data structure */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     JT     - modified julian time */
/*     DT     - current time step */
/*     VAL    - return value found in the file */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE exnmat.for:3892 */
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
/* INCLUDE exnmat.for:3893 */
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
/*     + + + SAVED VALUES + + + */
/* SOURCE exnmat.for:3896 */
/*<       real*8teps,dss_eps >*/
/* SOURCE exnmat.for:3897 */
/*<       saveteps,dss_eps >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE exnmat.for:3900 */
/*<        >*/
/* SOURCE exnmat.for:3902 */
/*<       real*8p,jtbase >*/
/*     + + + INTRINSICS + + + */
/* SOURCE exnmat.for:3905 */
/*<       intrinsicabs >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     ******************************formats***************************** */
/* SOURCE exnmat.for:3908 */
/*<       datateps/1.d-6/,dss_eps/5.2e-4/ >*/
/* SOURCE exnmat.for:3910 */
/*<    50  >*/
/* L50: */
/* SOURCE exnmat.for:3912 */
/*<    51  >*/
/* L51: */
/* *********************************************************************** */
/* SOURCE exnmat.for:3915 */
/*<       tmpvec_size=mrrbuf+5 >*/
    feq_gen_tmpvec_size_d_ = 6005;
/*      WRITE(STDOUT,*) 'FILE POINTER = ', I */
/* SOURCE exnmat.for:3917 */
/*<       minr=minrow(i) >*/
    minr = rdcom_1.minrow[*feq_gen_i_d_ - 1];
/* SOURCE exnmat.for:3918 */
/*<       maxr=maxrow(i) >*/
    maxr = rdcom_1.maxrow[*feq_gen_i_d_ - 1];
/* SOURCE exnmat.for:3919 */
/*<       l=ltry(i) >*/
    l = rdcom_1.ltry[*feq_gen_i_d_ - 1];
/* SOURCE exnmat.for:3920 */
/*<       lh=lsthd(i) >*/
    lh = rdcom_1.lsthd[*feq_gen_i_d_ - 1];
/*      WRITE(STDOUT,*) 'IN RDGET:' */
/*      WRITE(STDOUT,*) 'VALAIN = ',VALAIN(L) */
/*      WRITE(STDOUT,*) 'JT = ',JT,' JTIN(L) = ',JTIN(L) */
/*      WRITE(STDOUT,*) 'L = ',L,' LH = ',LH */
/* SOURCE exnmat.for:3927 */
/*<       if(jt.ge.jtin(l)-teps)then >*/
    if (*jt >= rdcom_1.jtin[l - 1] - teps) {
/* SOURCE exnmat.for:3928 */
/*<       if(abs(jt-jtin(l)).le.teps)then >*/
	if ((feq_gen_d_d_1 = *jt - rdcom_1.jtin[l - 1], abs(feq_gen_d_d_1)) <= teps) {
/*         Special case here to avoid boundary problems. */
/*         Equality is taken to be true if the match is within */
/*         TEPS day. */
/* SOURCE exnmat.for:3932 */
/*<       val=valain(l) >*/
	    *val = rdcom_1.valain[l - 1];
/* SOURCE exnmat.for:3933 */
/*<       return >*/
	    return 0;
/* SOURCE exnmat.for:3934 */
/*<       endif >*/
	}
/*       Search clockwise */
/* SOURCE exnmat.for:3937 */
/*<   100 continue >*/
L100:
/* SOURCE exnmat.for:3938 */
/*<       lp1=l+1 >*/
	lp1 = l + 1;
/* SOURCE exnmat.for:3939 */
/*<       if(lp1.gt.maxr)lp1=minr >*/
	if (lp1 > maxr) {
	    lp1 = minr;
	}
/* SOURCE exnmat.for:3941 */
/*<       if(lp1.eq.lh)then >*/
	if (lp1 == lh) {
/*           Passing list head pointer clockwise means we have */
/*           caught the buffer head, that is, the data in the */
/*           buffer does not span enough time. */
/* SOURCE exnmat.for:3945 */
/*<       if(dss_index_in(i).eq.0)then >*/
	    if (rdcom_1.feq_gen_dss_index_in_d_[*feq_gen_i_d_ - 1] == 0) {
/*             Traditional connection file. */
/* SOURCE exnmat.for:3947 */
/*<       read(unin(i),rec=rd_rec(i))jtin(lh),valain(lh) >*/
		feq_gen_io_d__520.ciunit = rdcom_1.unin[*feq_gen_i_d_ - 1];
		feq_gen_io_d__520.cirec = rdcom_1.feq_gen_rd_rec_d_[*feq_gen_i_d_ - 1];
		s_rdue(&feq_gen_io_d__520);
		do_uio(&feq_gen_c_d_1, (char *)&rdcom_1.jtin[lh - 1], (ftnlen)sizeof(
			doublereal));
		do_uio(&feq_gen_c_d_1, (char *)&rdcom_1.valain[lh - 1], (ftnlen)sizeof(
			real));
		e_rdue();
/* SOURCE exnmat.for:3948 */
/*<       rd_rec(i)=rd_rec(i)+1 >*/
		++rdcom_1.feq_gen_rd_rec_d_[*feq_gen_i_d_ - 1];
/* SOURCE exnmat.for:3949 */
/*<       lh=lh+1 >*/
		++lh;
/* SOURCE exnmat.for:3950 */
/*<       if(lh.gt.maxr)lh=minr >*/
		if (lh > maxr) {
		    lh = minr;
		}
/* SOURCE exnmat.for:3951 */
/*<       else >*/
	    } else {
/*             Path name in HECDSS.  Find out how many */
/*             values need to be retained in the buffer so that */
/*             time step reductions due to convergence difficulties */
/*             do not require reading data already past. */
/*              WRITE(STDOUT,*) ' JT FOLLOWS' */
/*              CALL JTIME_OUT(STDOUT, JT) */
/* SOURCE exnmat.for:3959 */
/*<       jtbase=jt-dt/86400.d0-teps >*/
		jtbase = *jt - *dt / 86400. - teps;
/*              WRITE(STDOUT,*) ' JTBASE FOLLOWS' */
/*              CALL JTIME_OUT(STDOUT, JTBASE) */
/*              WRITE(STDOUT,*) ' State of buffer before refresh' */
/*              CALL DUMP_STATE(MINR, MAXR, LH, L) */
/* SOURCE exnmat.for:3965 */
/*<       lt=lh-1 >*/
		lt = lh - 1;
/* SOURCE exnmat.for:3966 */
/*<       if(lt.lt.minr)lt=maxr >*/
		if (lt < minr) {
		    lt = maxr;
		}
/*             LT gives index to the last item placed in the */
/*             buffer. */
/* SOURCE exnmat.for:3969 */
/*<       knt=1 >*/
		knt = 1;
/* SOURCE exnmat.for:3970 */
/*<   110 continue >*/
L110:
/* SOURCE exnmat.for:3971 */
/*<       if(jtin(lt).ge.jtbase)then >*/
		if (rdcom_1.jtin[lt - 1] >= jtbase) {
/*                 Continue searching backwards. */
/* SOURCE exnmat.for:3973 */
/*<       lt=lt-1 >*/
		    --lt;
/* SOURCE exnmat.for:3974 */
/*<       if(lt.lt.minr)lt=maxr >*/
		    if (lt < minr) {
			lt = maxr;
		    }
/* SOURCE exnmat.for:3975 */
/*<       if(lt.eq.lh)then >*/
		    if (lt == lh) {
/* SOURCE exnmat.for:3976 */
/*<       write(stdout,50)unin(i) >*/
			feq_gen_io_d__524.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__524);
			do_fio(&feq_gen_c_d_1, (char *)&rdcom_1.unin[*feq_gen_i_d_ - 1], (
				ftnlen)sizeof(integer));
			e_wsfe();
/* SOURCE exnmat.for:3977 */
/*<       write(stdout,51) >*/
			feq_gen_io_d__525.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__525);
			e_wsfe();
/* SOURCE exnmat.for:3978 */
/*<       stop'Abnormal stop: errors found.' >*/
			s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE exnmat.for:3979 */
/*<       endif >*/
		    }
/* SOURCE exnmat.for:3981 */
/*<       knt=knt+1 >*/
		    ++knt;
/* SOURCE exnmat.for:3982 */
/*<       goto110 >*/
		    goto L110;
/* SOURCE exnmat.for:3983 */
/*<       endif >*/
		}
/*             KNT  gives the number of values in the buffer that */
/*             must be retained. */
/* SOURCE exnmat.for:3986 */
/*<       desired_n=maxr-minr+1-knt >*/
		feq_gen_desired_n_d_ = maxr - minr + 1 - knt;
/*              WRITE(STDOUT,*) ' RDGET: KNT=',KNT,' DESIRED_N=', */
/*     A                     DESIRED_N */
/*             Set the desired julian time so that we do not */
/*             get a value twice.  JTIN(L) gives the last */
/*             value in the buffer.  DSS_EPS adds 0.75 minute */
/*             to force getting the value following the one */
/*             already in the buffer at index L. */
/* SOURCE exnmat.for:3994 */
/*<       jtbase=jtin(l)+dss_eps >*/
		jtbase = rdcom_1.jtin[l - 1] + feq_gen_dss_eps_d_;
/*              WRITE(STDOUT,*) ' JTBASE  FOR HECDSS LOOKUP FOLLOWS' */
/*              CALL JTIME_OUT(STDOUT, JTBASE) */
/* SOURCE exnmat.for:3997 */
/*<        >*/
		feq_gen_get_hecdss_block_d_(stdout, rdcomc_1.namin + (*feq_gen_i_d_ - 1 << 8), &
			rdcom_1.feq_gen_dss_index_in_d_[*feq_gen_i_d_ - 1], &
			rdcom_1.feq_gen_time_step_in_d_[*feq_gen_i_d_ - 1], const_cast<char*>("INST-VAL"), &jtbase,
			 &feq_gen_desired_n_d_, &nvalues, rdcom_1.jtvec, 
			rdcom_1.tmpvec, &feq_gen_tmpvec_size_d_, (ftnlen)256, (ftnlen)
			8);
/*             Transfer to the buffer. Slot at LH is the start */
/*             point. */
/* SOURCE exnmat.for:4004 */
/*<       do120j=1,nvalues >*/
		feq_gen_i_d_1 = nvalues;
		for (j = 1; j <= feq_gen_i_d_1; ++j) {
/* SOURCE exnmat.for:4005 */
/*<       jtin(lh)=jtvec(j) >*/
		    rdcom_1.jtin[lh - 1] = rdcom_1.jtvec[j - 1];
/* SOURCE exnmat.for:4006 */
/*<       valain(lh)=tmpvec(j) >*/
		    rdcom_1.valain[lh - 1] = rdcom_1.tmpvec[j - 1];
/* SOURCE exnmat.for:4007 */
/*<       lh=lh+1 >*/
		    ++lh;
/* SOURCE exnmat.for:4008 */
/*<       if(lh.gt.maxr)lh=minr >*/
		    if (lh > maxr) {
			lh = minr;
		    }
/* SOURCE exnmat.for:4009 */
/*<   120 continue >*/
/* L120: */
		}
/*             At completion of loop LH will point to the first */
/*             invalid value as the loop is searched clockwise. */
/*              WRITE(STDOUT,*) ' State of buffer after refresh' */
/*              CALL DUMP_STATE(MINR, MAXR, LH, L) */
/* SOURCE exnmat.for:4016 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:4017 */
/*<       endif >*/
	}
/*          WRITE(STDOUT,*) 'LP1 = ',LP1,' JTIN(LP1) = ',JTIN(LP1) */
/* SOURCE exnmat.for:4019 */
/*<       if(jt.le.jtin(lp1)+teps)then >*/
	if (*jt <= rdcom_1.jtin[lp1 - 1] + teps) {
/*           Found interval */
/* SOURCE exnmat.for:4021 */
/*<       ll=l >*/
	    ll = l;
/* SOURCE exnmat.for:4022 */
/*<       lr=lp1 >*/
	    lr = lp1;
/* SOURCE exnmat.for:4023 */
/*<       goto1000 >*/
	    goto L1000;
/* SOURCE exnmat.for:4024 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:4025 */
/*<       l=lp1 >*/
	    l = lp1;
/* SOURCE exnmat.for:4026 */
/*<       goto100 >*/
	    goto L100;
/* SOURCE exnmat.for:4027 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:4028 */
/*<       else >*/
    } else {
/*         Search counter clockwise.  Note:buffer will be filled */
/*         at start of run. */
/* SOURCE exnmat.for:4031 */
/*<   200 continue >*/
L200:
/* SOURCE exnmat.for:4032 */
/*<       if(l.eq.lh)then >*/
	if (l == lh) {
/* SOURCE exnmat.for:4033 */
/*<       write(stdout,50)unin(i) >*/
	    feq_gen_io_d__531.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__531);
	    do_fio(&feq_gen_c_d_1, (char *)&rdcom_1.unin[*feq_gen_i_d_ - 1], (ftnlen)sizeof(
		    integer));
	    e_wsfe();
/* SOURCE exnmat.for:4034 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE exnmat.for:4035 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:4037 */
/*<       lm1=l-1 >*/
	lm1 = l - 1;
/* SOURCE exnmat.for:4038 */
/*<       if(lm1.lt.minr)lm1=maxr >*/
	if (lm1 < minr) {
	    lm1 = maxr;
	}
/* SOURCE exnmat.for:4040 */
/*<       if(jt.ge.jtin(lm1)+teps)then >*/
	if (*jt >= rdcom_1.jtin[lm1 - 1] + teps) {
/*             Found interval. */
/* SOURCE exnmat.for:4043 */
/*<       ll=lm1 >*/
	    ll = lm1;
/* SOURCE exnmat.for:4044 */
/*<       lr=l >*/
	    lr = l;
/* SOURCE exnmat.for:4045 */
/*<       goto1000 >*/
	    goto L1000;
/* SOURCE exnmat.for:4046 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:4047 */
/*<       l=lm1 >*/
	    l = lm1;
/* SOURCE exnmat.for:4048 */
/*<       goto200 >*/
	    goto L200;
/* SOURCE exnmat.for:4049 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:4050 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4052 */
/*<  1000 continue >*/
L1000:
/* SOURCE exnmat.for:4054 */
/*<       ltry(i)=l >*/
    rdcom_1.ltry[*feq_gen_i_d_ - 1] = l;
/* SOURCE exnmat.for:4055 */
/*<       lsthd(i)=lh >*/
    rdcom_1.lsthd[*feq_gen_i_d_ - 1] = lh;
/*       Interpolate for the value */
/* SOURCE exnmat.for:4059 */
/*<       p=(jt-jtin(ll))/(jtin(lr)-jtin(ll)) >*/
    p = (*jt - rdcom_1.jtin[ll - 1]) / (rdcom_1.jtin[lr - 1] - rdcom_1.jtin[
	    ll - 1]);
/* SOURCE exnmat.for:4061 */
/*<       val=valain(ll)+p*(valain(lr)-valain(ll)) >*/
    *val = rdcom_1.valain[ll - 1] + p * (static_cast<double>(rdcom_1.valain[lr - 1]) - 
	    rdcom_1.valain[ll - 1]);
/* SOURCE exnmat.for:4063 */
/*<       val=val*ts_conversion_factor(i) >*/
    *val *= rdcom_1.feq_gen_ts_conversion_factor_d_[*feq_gen_i_d_ - 1];
/*     WRITE(STDOUT,*) 'RDGET RETURNS VALUE = ', VAL */
/* SOURCE exnmat.for:4065 */
/*<       return >*/
    return 0;
/* SOURCE exnmat.for:4066 */
/*<       end >*/
} /* rdget_ */




/* SOURCE exnmat.for:4070 */
/*<        >*/
/* Subroutine */ int setext_(doublereal *dt, doublereal *dtdy, real *wt, 
	integer *nbn, integer *nbra, integer *nex, integer *feq_storage_brpt, real *hslot,
	 integer *ept, real *qeps, doublereal *jtime, integer *feq_storage_emc, integer *
	feq_storage_exnodt, real *rnorm, real *mxres, integer *lmxres, real *errp, real *
	errq, integer *berrq, integer *nerrq, integer *nerrp, integer *berrp)
{
    // Code 13 retains V=Q/A and its square in 53-bit registers.
    // Original 0x429fe2-0x42a03a. Q/Qcritical is squared without
    // a binary32 intermediate at 0x42a109-0x42a147.
    // Qcritical=A*sqrt(g*A/T): the original stores sqrt as REAL before
    // multiplication, at 0x4299ae, 0x4299d8, 0x429ee0, and 0x429f0a.

    /* Format strings */
    static char fmt_57[] = "(/,\002 *ERR:196* Reservoir at node=\002,a5,\002\
 has surf. area =\002,f10.2,\002 at elev.=\002,f10.2,/,11x,\002Unable to con\
tinue \002,\002 computations with surf. area <= 0.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    doublereal feq_gen_r_d_1, feq_gen_r_d_2;
    char feq_gen_ch_d_1[5], feq_gen_ch_d_2[5];
    static real equiv_0[1];

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();
    double sqrt(doublereal);

    /* Local variables */
    integer feq_gen_i_d_;
    real w, dc, al, bl, bn;
    integer ii;
    real ar, br;
    integer nl;
    real wc, ql;
    integer nr;
    real qn, tl, qr, tp, tr, yl, yr, fac, dbl, dbn, dbr, arg;
    doublereal vl, vr;
    integer ieq, dnn, mdn, nbr, nnd;
    real con, div, dtl, qcr, dtr, pdv, pql;
    integer num, unn;
    real pqm, pqr, qcl, pyl, pym, res, top, wtc, ybl, pyr, ybr;
    integer adr1, adr2, adr3, adr4, num1, num2;
    real kfac, area;
    integer code, ntab, jcol, adrs;
    real alpl, func, ybal;
#define idum (feq::BitView<integer>(equiv_0, sizeof(equiv_0)))
    real alpr, ybar, dtop;
    integer ipnt;
    real asur;
#define rdum (equiv_0)
    integer irow, feq_gen_type_d_;
    real rsgn, temp;
    extern /* Subroutine */ int pump_(integer *, integer *, integer *, real *,
	     real *, real *, real *, real *, integer *, doublereal *, integer 
	    *, real *, real *, real *, real *, real *), twod6_(integer *, 
	    integer *, doublereal *, integer *, integer *, integer *, real *, 
	    real *, real *, real *, real *, real *, real *, real *);
    integer aflag;
    extern /* Subroutine */ int cbrid_(integer *, real *, integer *, integer *
	    , integer *, integer *, integer *, real *, real *, real *, real *,
	     real *, real *, real *, real *, real *);
    integer iatdf;
    real disch, dalpl, qbase, dalpr;
    integer itype, nsign;
    real qcsqr, inout, feq_gen_fb_adj_factor_d_;
    extern /* Subroutine */ int bdfwr_(integer *, integer *, integer *, real *
	    , real *, real *, real *, real *, integer *, integer *, 
	    doublereal *, real *, real *, real *, real *, real *, real *), 
	    excon_(integer *, integer *, doublereal *, integer *, integer *, 
	    integer *, real *, real *, real *, integer *, real *, real *, 
	    real *, real *, real *), lktab_(integer *, real *, integer *, 
	    real *, integer *, real *), twod14_(integer *, integer *, 
	    doublereal *, integer *, integer *, integer *, real *, real *, 
	    real *, real *, real *, real *, real *, real *), xlkt20_(integer *
	    , real *, real *, real *, real *, real *, real *, real *, real *),
	     xlkt21_(integer *, real *, real *, real *, real *, real *, real *
	    , real *, real *, real *), xlkt22_(integer *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *, real *), bdftab_(integer *, integer *, real *, real *, 
	    real *, integer *, real *, integer *, real *, real *, real *, 
	    real *, real *), mchgat_(integer *, integer *, integer *, real *, 
	    real *, real *, integer *, integer *, doublereal *, real *, real *
	    , real *, real *, real *);
    integer ientry;
    real convey, dconvy;
    doublereal tptime;
    extern /* Character */ VOID getusn_(char *, ftnlen, integer *);
    extern /* Subroutine */ int abrexp_(integer *, real *, integer *, 
	    doublereal *, integer *, integer *, integer *, real *, real *, 
	    real *, integer *, real *, real *, real *, real *, real *), 
	    contrl_(integer *, integer *, integer *, integer *, integer *, 
	    doublereal *, integer *, integer *, real *, real *, real *, 
	    integer *, real *, real *), seticw_(doublereal *, integer *, 
	    integer *, real *, integer *, integer *, real *, real *, integer *
	    , integer *, integer *, integer *), seticx_(doublereal *, integer 
	    *, integer *, real *, integer *, integer *, real *, real *, 
	    integer *, integer *, integer *, integer *), setinw_(doublereal *,
	     integer *, integer *, real *, integer *, integer *, real *, real 
	    *, integer *, integer *, integer *, integer *), setinx_(
	    doublereal *, integer *, integer *, real *, integer *, integer *, 
	    real *, real *, integer *, integer *, integer *, integer *), 
	    sidewr_(integer *, integer *, doublereal *, integer *, integer *, 
	    integer *, integer *, real *, real *, real *, real *, real *, 
	    real *, real *, real *, real *, real *), ufgate_(integer *, 
	    integer *, integer *, real *, real *, real *, integer *, integer *
	    , doublereal *, real *, real *, real *, real *, real *, real *), 
	    lktstab_(integer *, doublereal *, real *, integer *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__542 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__544 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__557 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__568 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__583 = { 0, 0, 0, fmt_57, 0 };
    static cilist feq_gen_io_d__585 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     This subroutine creates the matrix for the jacobian. */
/* SOURCE exnmat.for:4079 */
/*<       implicitnone >*/
/*     + + + PARAMETERS + + + */
/* INCLUDE exnmat.for:4081 */
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
/* SOURCE exnmat.for:4084 */
/*<       integerberrp,berrq,lmxres,nbn,nbra,nerrp,nerrq,nex,ept >*/
/* SOURCE exnmat.for:4085 */
/*<       integerbrpt(8,nbra),emc(mremc),exnodt(9,nex) >*/
/* SOURCE exnmat.for:4086 */
/*<       realerrp,errq,hslot,mxres,qeps,rnorm,wt >*/
/* SOURCE exnmat.for:4087 */
/*<       real*8dt,dtdy,jtime >*/
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
/* INCLUDE exnmat.for:4138 */
/*     Miscellaneous control parameters */
/* SOURCE misccon.cmn:3 */
/*<       integerpagesp,pndflg >*/
/* SOURCE misccon.cmn:5 */
/*<        >*/
/* SOURCE misccon.cmn:8 */
/*<        >*/
/* INCLUDE exnmat.for:4139 */
/* ********************************************************************** */
/* SOURCE enelem.cmn:3 */
/*<       common/enelem/ae1,ae2,mye,mqe,qe1,qe2,qe3,ye1,ye2,ye3,ze,te1,te2 >*/
/* SOURCE enelem.cmn:6 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE exnmat.for:4140 */
/* ********************************************************************** */
/* SOURCE bnelem.cmn:3 */
/*<        >*/
/* SOURCE bnelem.cmn:11 */
/*<       integerstflag,ftid >*/
/* SOURCE bnelem.cmn:13 */
/*<        >*/
/* ********************************************************************** */
/* INCLUDE exnmat.for:4141 */
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
/* INCLUDE exnmat.for:4142 */
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
/* INCLUDE exnmat.for:4143 */
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
/* INCLUDE exnmat.for:4144 */
/* ********************************************************************** */
/* SOURCE grav.cmn:2 */
/*<       realgrav,twog,halfg >*/
/* SOURCE grav.cmn:4 */
/*<       common/gravcm/grav,twog,halfg >*/
/* SOURCE grav.cmn:5 */
/*<       save/gravcm/ >*/
/* ********************************************************************** */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE exnmat.for:4147 */
/*<        >*/
/* SOURCE exnmat.for:4150 */
/*<        >*/
/* SOURCE exnmat.for:4157 */
/*<       real*8tptime >*/
/*     + + + EQUIVALENCES + + + */
/* SOURCE exnmat.for:4160 */
/*<       equivalence(idum,rdum) >*/
/*     + + + INTRINSICS + + + */
/* SOURCE exnmat.for:4163 */
/*<       intrinsicabs,sngl,sqrt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE exnmat.for:4166 */
/*<       charactergetusn*5 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE exnmat.for:4169 */
/*<        >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE exnmat.for:4174 */
/*<    57  >*/
/* *********************************************************************** */
/*     EXPLORE MATRIX FOR SPECIAL PROBLEM AT NEAR ZERO DEPTH */
/*      WRITE(STD6,9245) */
/* 9245  FORMAT(1X,8X,'dQL',8X,'dYL',8X,'dQR',8X,'dYR',8X,'RES') */
/*     INITIALIZE VARIABLES */
/*     SET THE ERROR MONITORS FOR BRANCHES. */
/*        ERRP--POND TERM. ERRQ-LATERAL INFLOW */
/* SOURCE exnmat.for:4187 */
/*<       errp=0.0 >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> brpt(feq_storage_brpt, 9);

    feq::IndexedPointer<integer> exnodt(feq_storage_exnodt, 10);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
/* L57: */
    *errp = (float)0.;
/* SOURCE exnmat.for:4188 */
/*<       errq=0.0 >*/
    *errq = (float)0.;
/* SOURCE exnmat.for:4189 */
/*<       berrq=0 >*/
    *berrq = 0;
/* SOURCE exnmat.for:4190 */
/*<       nerrq=0 >*/
    *nerrq = 0;
/* SOURCE exnmat.for:4191 */
/*<       nerrp=0 >*/
    *nerrp = 0;
/* SOURCE exnmat.for:4192 */
/*<       berrp=0 >*/
    *berrp = 0;
/*     SET THE RESIDUAL NORMS */
/* SOURCE exnmat.for:4195 */
/*<       mxres=-1.e25 >*/
    *mxres = (float)-1e25;
/*     SET THE ARRAY OF PARTIAL DERIVATIVES VECTOR TO ZERO */
/* SOURCE exnmat.for:4198 */
/*<       do10i=1,c(numeq) >*/
    feq_gen_i_d_1 = matcom_1.feq_gen_c_d_[matcom_1.numeq];
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE exnmat.for:4199 */
/*<       pdavec(i)=0. >*/
	matcom_1.pdavec[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE exnmat.for:4200 */
/*<    10 continue >*/
/* L10: */
    }
/* SOURCE exnmat.for:4202 */
/*<       ipnt=emc(1) >*/
    ipnt = emc[1];
/* SOURCE exnmat.for:4203 */
/*<       ieq=0 >*/
    ieq = 0;
/* SOURCE exnmat.for:4204 */
/*<       ientry=1 >*/
    ientry = 1;
/* SOURCE exnmat.for:4205 */
/*<       res=0.0 >*/
    res = (float)0.;
/*     GET NEXT CODE */
/* SOURCE exnmat.for:4210 */
/*<    20 continue >*/
L20:
/* SOURCE exnmat.for:4211 */
/*<       ipnt=add(ientry) >*/
    ipnt = matcom_1.add[ientry - 1];
/* SOURCE exnmat.for:4212 */
/*<       ientry=ientry+1 >*/
    ++ientry;
/* SOURCE exnmat.for:4213 */
/*<       code=emc(ipnt) >*/
    code = emc[ipnt];
/* SOURCE exnmat.for:4214 */
/*<       if(code.eq.-1)goto9000 >*/
    if (code == -1) {
	goto L9000;
    }
/* SOURCE exnmat.for:4215 */
/*<        >*/
    switch (code) {
	case 1:  goto L100;
	case 2:  goto L200;
	case 3:  goto L300;
	case 4:  goto L400;
	case 5:  goto L500;
	case 6:  goto L600;
	case 7:  goto L700;
	case 8:  goto L800;
	case 9:  goto L900;
	case 10:  goto L1000;
	case 11:  goto L1100;
	case 12:  goto L1200;
	case 13:  goto L1300;
	case 14:  goto L1400;
	case 15:  goto L1500;
    }
/* SOURCE exnmat.for:4217 */
/*<       write(stdout,*)' *BUG:16*INVALID EMC CODE IN SETEXT. CODE=',code >*/
    feq_gen_io_d__542.ciunit = xscom_1.stdout;
    s_wsle(&feq_gen_io_d__542);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:16*INVALID EMC CODE IN SETEXT. CODE="), (
	    ftnlen)42);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&code, (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE exnmat.for:4219 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/*     CODE 1 GIVES BRANCH NUMBERS */
/* SOURCE exnmat.for:4223 */
/*<   100 continue >*/
L100:
/* SOURCE exnmat.for:4224 */
/*<       nbr=emc(ipnt+1) >*/
    nbr = emc[ipnt + 1];
/* SOURCE exnmat.for:4227 */
/*<       goto(1,2,3,4),geqvec(nbr) >*/
    switch (bnothr_1.geqvec[nbr - 1]) {
	case 1:  goto L1;
	case 2:  goto L2;
	case 3:  goto L3;
	case 4:  goto L4;
    }
/* SOURCE exnmat.for:4229 */
/*<       write(stdout,*)' *BUG:XXX* INVALID GEQOPT IN SETEXT' >*/
    feq_gen_io_d__544.ciunit = xscom_1.stdout;
    s_wsle(&feq_gen_io_d__544);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:XXX* INVALID GEQOPT IN SETEXT"), (ftnlen)35);
    e_wsle();
/* SOURCE exnmat.for:4230 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE exnmat.for:4231 */
/*<     1 continue >*/
L1:
/* SOURCE exnmat.for:4232 */
/*<        >*/
    setinx_(dt, &nbr, nbra, wt, &brpt[9], &ieq, errp, errq, berrp, nerrp, 
	    berrq, nerrq);
/* SOURCE exnmat.for:4236 */
/*<       goto9 >*/
    goto L9;
/* SOURCE exnmat.for:4237 */
/*<     2 continue >*/
L2:
/* SOURCE exnmat.for:4238 */
/*<        >*/
    setinw_(dt, &nbr, nbra, wt, &brpt[9], &ieq, errp, errq, berrp, nerrp, 
	    berrq, nerrq);
/* SOURCE exnmat.for:4242 */
/*<       goto9 >*/
    goto L9;
/* SOURCE exnmat.for:4244 */
/*<     3 continue >*/
L3:
/* SOURCE exnmat.for:4245 */
/*<        >*/
    seticx_(dt, &nbr, nbra, wt, &brpt[9], &ieq, errp, errq, berrp, nerrp, 
	    berrq, nerrq);
/* SOURCE exnmat.for:4249 */
/*<       goto9 >*/
    goto L9;
/* SOURCE exnmat.for:4251 */
/*<     4 continue >*/
L4:
/* SOURCE exnmat.for:4252 */
/*<        >*/
    seticw_(dt, &nbr, nbra, wt, &brpt[9], &ieq, errp, errq, berrp, nerrp, 
	    berrq, nerrq);
/* SOURCE exnmat.for:4256 */
/*<       goto9 >*/
    goto L9;
/* SOURCE exnmat.for:4258 */
/*<     9 continue >*/
L9:
/* SOURCE exnmat.for:4260 */
/*<       goto8000 >*/
    goto L8000;
/*     CODE 2 GIVES DISCHARGE CONTINUITY AT JUNCTIONS */
/* SOURCE exnmat.for:4264 */
/*<   200 continue >*/
L200:
/* SOURCE exnmat.for:4265 */
/*<       nnd=emc(ipnt+1) >*/
    nnd = emc[ipnt + 1];
/* SOURCE exnmat.for:4266 */
/*<       res=0. >*/
    res = (float)0.;
/* SOURCE exnmat.for:4267 */
/*<       ieq=ieq+1 >*/
    ++ieq;
/*        WRITE(STD6,*) ' DOING CODE=2 NND=',NND */
/* SOURCE exnmat.for:4269 */
/*<       do220i=1,nnd >*/
    feq_gen_i_d_1 = nnd;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE exnmat.for:4270 */
/*<       num=emc(ipnt+i+1) >*/
	num = emc[ipnt + feq_gen_i_d_ + 1];
/*          FAC = SIGN(1.0, FLOAT(NUM)) */
/*          NUM = ABS(NUM) */
/* SOURCE exnmat.for:4273 */
/*<       rsgn=exnodt(1,num) >*/
	rsgn = (real) exnodt[num * 9 + 1];
/* SOURCE exnmat.for:4274 */
/*<       qn=qe2(num) >*/
	qn = enelem_1.qe2[num - 1];
/* SOURCE exnmat.for:4275 */
/*<       res=res+rsgn*qn >*/
	res += static_cast<double>(rsgn) * qn;
/* SOURCE exnmat.for:4276 */
/*<       jcol=exnodt(5,num) >*/
	jcol = exnodt[num * 9 + 5];
/*          WRITE(STD6,*) ' JCOL=',JCOL */
/* SOURCE exnmat.for:4278 */
/*<       ii=ieq-jcol >*/
	ii = ieq - jcol;
/* SOURCE exnmat.for:4279 */
/*<       if(ii.gt.0)then >*/
	if (ii > 0) {
/* SOURCE exnmat.for:4280 */
/*<       pdavec(r(ieq)-ii+1)=rsgn >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = rsgn;
/* SOURCE exnmat.for:4281 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:4282 */
/*<       pdavec(c(jcol)+ii)=rsgn >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = rsgn;
/* SOURCE exnmat.for:4283 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:4284 */
/*<   220 continue >*/
/* L220: */
    }
/* SOURCE exnmat.for:4285 */
/*<       rhs(ieq)=-res >*/
    matcom_1.rhs[ieq - 1] = -res;
/* SOURCE exnmat.for:4286 */
/*<       ipnt=ipnt+nnd >*/
    ipnt += nnd;
/* SOURCE exnmat.for:4287 */
/*<       goto8000 >*/
    goto L8000;
/*     CODE 3 GIVES ELEVATION EQUALITY */
/* SOURCE exnmat.for:4291 */
/*<   300 continue >*/
L300:
/* SOURCE exnmat.for:4292 */
/*<       unn=emc(ipnt+1) >*/
    unn = emc[ipnt + 1];
/* SOURCE exnmat.for:4293 */
/*<       dnn=emc(ipnt+2) >*/
    dnn = emc[ipnt + 2];
/* SOURCE exnmat.for:4294 */
/*<       res=ye2(unn)+ze(unn) >*/
    res = static_cast<double>(enelem_1.ye2[unn - 1]) + enelem_1.ze[unn - 1];
/* SOURCE exnmat.for:4295 */
/*<       ieq=ieq+1 >*/
    ++ieq;
/* SOURCE exnmat.for:4296 */
/*<       jcol=exnodt(5,unn)+1 >*/
    jcol = exnodt[unn * 9 + 5] + 1;
/* SOURCE exnmat.for:4297 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4298 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4299 */
/*<       pdavec(r(ieq)-ii+1)=1. >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = (float)1.;
/* SOURCE exnmat.for:4300 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4301 */
/*<       pdavec(c(jcol)+ii)=1. >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = (float)1.;
/* SOURCE exnmat.for:4302 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4303 */
/*<       res=res-ye2(dnn)-ze(dnn) >*/
    res = static_cast<double>(static_cast<double>(res) - enelem_1.ye2[dnn - 1]) - enelem_1.ze[dnn - 1];
/* SOURCE exnmat.for:4304 */
/*<       jcol=exnodt(5,dnn)+1 >*/
    jcol = exnodt[dnn * 9 + 5] + 1;
/*        WRITE(STD6,*) ' JCOL=',JCOL */
/* SOURCE exnmat.for:4306 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4307 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4308 */
/*<       pdavec(r(ieq)-ii+1)=-1. >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = (float)-1.;
/* SOURCE exnmat.for:4309 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4310 */
/*<       pdavec(c(jcol)+ii)=-1. >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = (float)-1.;
/* SOURCE exnmat.for:4311 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4312 */
/*<       rhs(ieq)=-res >*/
    matcom_1.rhs[ieq - 1] = -res;
/* SOURCE exnmat.for:4313 */
/*<       goto8000 >*/
    goto L8000;
/*     CODE 4 CONTROL STRUCTURE 1 NODE HEAD DISCHARGE */
/*     FLOW IS A FUNCTION OF HEAD */
/* SOURCE exnmat.for:4318 */
/*<   400 continue >*/
L400:
/* SOURCE exnmat.for:4319 */
/*<       unn=emc(ipnt+2) >*/
    unn = emc[ipnt + 2];
/* SOURCE exnmat.for:4320 */
/*<       dnn=emc(ipnt+4) >*/
    dnn = emc[ipnt + 4];
/* SOURCE exnmat.for:4321 */
/*<       nsign=emc(ipnt+3) >*/
    nsign = emc[ipnt + 3];
/* SOURCE exnmat.for:4322 */
/*<        >*/
    contrl_(&ipnt, &xscom_1.stdout, nbn, nex, &xscom_1.output, jtime, &exnodt[
	    10], &emc[1], bnelem_1.y1, bnelem_1.zvec, bnelem_1.dxvec, ept, &
	    pdv, &disch);
/* SOURCE exnmat.for:4326 */
/*<       ieq=ieq+1 >*/
    ++ieq;
/* SOURCE exnmat.for:4327 */
/*<       res=qe2(dnn)-disch >*/
    res = static_cast<double>(enelem_1.qe2[dnn - 1]) - disch;
/* SOURCE exnmat.for:4328 */
/*<       jcol=exnodt(5,dnn) >*/
    jcol = exnodt[dnn * 9 + 5];
/* SOURCE exnmat.for:4329 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4330 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4331 */
/*<       pdavec(r(ieq)-ii+1)=1. >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = (float)1.;
/* SOURCE exnmat.for:4332 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4333 */
/*<       pdavec(c(jcol)+ii)=1. >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = (float)1.;
/* SOURCE exnmat.for:4334 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4335 */
/*<       jcol=exnodt(5,unn)+1 >*/
    jcol = exnodt[unn * 9 + 5] + 1;
/* SOURCE exnmat.for:4336 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4337 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4338 */
/*<       pdavec(r(ieq)-ii+1)=-pdv >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = -pdv;
/* SOURCE exnmat.for:4339 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4340 */
/*<       pdavec(c(jcol)+ii)=-pdv >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = -pdv;
/* SOURCE exnmat.for:4341 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4343 */
/*<       rhs(ieq)=-res >*/
    matcom_1.rhs[ieq - 1] = -res;
/*        WRITE(STD6,9246) 1.0, -PDV,RES */
/* 9246    FORMAT(1X,22X,3(1PE11.3)) */
/* SOURCE exnmat.for:4347 */
/*<       goto8000 >*/
    goto L8000;
/*     TWO NODE CONTROL */
/* SOURCE exnmat.for:4351 */
/*<   500 continue >*/
L500:
/* SOURCE exnmat.for:4352 */
/*<       type=emc(ipnt+1) >*/
    feq_gen_type_d_ = emc[ipnt + 1];
/* SOURCE exnmat.for:4353 */
/*<       unn=emc(ipnt+2) >*/
    unn = emc[ipnt + 2];
/* SOURCE exnmat.for:4354 */
/*<       dnn=emc(ipnt+3) >*/
    dnn = emc[ipnt + 3];
/*       BRANCH ON TYPE */
/* SOURCE exnmat.for:4358 */
/*<       goto(501,502,503,504,505,506,507,508,509),type >*/
    switch (feq_gen_type_d_) {
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
/* SOURCE exnmat.for:4359 */
/*<        >*/
    feq_gen_io_d__557.ciunit = xscom_1.stdout;
    s_wsle(&feq_gen_io_d__557);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *BUG:17* INVALID CODE=5 TYPE IN SETEXT."), (ftnlen)
	    40);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" TYPE="), (ftnlen)6);
    do_lio(&feq_gen_c_d_3, &feq_gen_c_d_1, (char *)&feq_gen_type_d_, (ftnlen)sizeof(integer));
    e_wsle();
/* SOURCE exnmat.for:4361 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE exnmat.for:4363 */
/*<   501 continue >*/
L501:
/*         EXPANSION/CONTRACTION WITH CRITICAL DEPTH POSSIBLE */
/* SOURCE exnmat.for:4367 */
/*<        >*/
    excon_(&ipnt, &xscom_1.stdout, jtime, nex, &c_b303, &exnodt[10], 
	    enelem_1.qe2, enelem_1.ye2, enelem_1.ze, &emc[1], &res, &pyl, &
	    pql, &pyr, &pqr);
/* SOURCE exnmat.for:4372 */
/*<       goto599 >*/
    goto L599;
/* SOURCE exnmat.for:4374 */
/*<   502 continue >*/
L502:
/*         BIDIRECTIONAL FLOW WITH TABLES AND SLOPE */
/* SOURCE exnmat.for:4378 */
/*<        >*/
    bdftab_(&ipnt, &c_b303, enelem_1.ye2, enelem_1.ze, enelem_1.qe2, nex, &
	    miscon_1.c52eps, &emc[1], &res, &pyl, &pql, &pyr, &pqr);
/* SOURCE exnmat.for:4383 */
/*<       goto599 >*/
    goto L599;
/* SOURCE exnmat.for:4385 */
/*<   503 continue >*/
L503:
/* SOURCE exnmat.for:4386 */
/*<        >*/
    pump_(&ipnt, &emc[1], &c_b303, &gravcm_1.grav, &gravcm_1.twog, 
	    enelem_1.ye2, enelem_1.ze, enelem_1.qe2, nex, jtime, &
	    xscom_1.stdout, &res, &pyl, &pql, &pyr, &pqr);
/* SOURCE exnmat.for:4391 */
/*<       goto599 >*/
    goto L599;
/* SOURCE exnmat.for:4393 */
/*<   504 continue >*/
L504:
/* SOURCE exnmat.for:4394 */
/*<        >*/
    cbrid_(&ipnt, &gravcm_1.grav, &xscom_1.stdout, nex, &c_b303, &emc[1], &
	    exnodt[10], enelem_1.qe2, enelem_1.ye2, enelem_1.ze, hslot, &res, 
	    &pyl, &pql, &pyr, &pqr);
/* SOURCE exnmat.for:4399 */
/*<       goto599 >*/
    goto L599;
/* SOURCE exnmat.for:4400 */
/*<   505 continue >*/
L505:
/* SOURCE exnmat.for:4401 */
/*<        >*/
    abrexp_(&ipnt, &gravcm_1.grav, &xscom_1.stdout, jtime, nex, &c_b303, &
	    exnodt[10], enelem_1.qe2, enelem_1.ye2, enelem_1.ze, &emc[1], &
	    res, &pyl, &pql, &pyr, &pqr);
/* SOURCE exnmat.for:4407 */
/*<       goto599 >*/
    goto L599;
/* SOURCE exnmat.for:4408 */
/*<   506 continue >*/
L506:
/*         BRANCH ON THE SIGN OF THE NUMBER OF PATHS */
/* SOURCE exnmat.for:4410 */
/*<       if(emc(ipnt+6).gt.0)then >*/
    if (emc[ipnt + 6] > 0) {
/* SOURCE exnmat.for:4411 */
/*<        >*/
	twod6_(&ipnt, &xscom_1.stdout, jtime, nex, ept, &emc[1], enelem_1.qe2,
		 enelem_1.ye2, enelem_1.ze, &res, &pyl, &pql, &pyr, &pqr);
/* SOURCE exnmat.for:4415 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4416 */
/*<        >*/
	twod14_(&ipnt, &xscom_1.stdout, jtime, nex, ept, &emc[1], 
		enelem_1.qe2, enelem_1.ye2, enelem_1.ze, &res, &pyl, &pql, &
		pyr, &pqr);
/* SOURCE exnmat.for:4420 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4422 */
/*<       goto599 >*/
    goto L599;
/* SOURCE exnmat.for:4424 */
/*<   507 continue >*/
L507:
/* SOURCE exnmat.for:4425 */
/*<       tptime=jtime-dtdy >*/
    tptime = *jtime - *dtdy;
/* SOURCE exnmat.for:4426 */
/*<        >*/
    bdfwr_(&ipnt, &emc[1], &c_b303, enelem_1.ye2, enelem_1.ze, enelem_1.qe2, 
	    enelem_1.ae2, enelem_1.te2, nex, &xscom_1.stdout, &tptime, &
	    gravcm_1.grav, &res, &pyl, &pql, &pyr, &pqr);
/* SOURCE exnmat.for:4431 */
/*<       goto599 >*/
    goto L599;
/* SOURCE exnmat.for:4433 */
/*<   508 continue >*/
L508:
/* SOURCE exnmat.for:4434 */
/*<       tptime=jtime-dtdy >*/
    tptime = *jtime - *dtdy;
/* SOURCE exnmat.for:4435 */
/*<        >*/
    mchgat_(&ipnt, &emc[1], &c_b303, enelem_1.ye2, enelem_1.ze, enelem_1.qe2, 
	    nex, &xscom_1.stdout, &tptime, &res, &pyl, &pql, &pyr, &pqr);
/* SOURCE exnmat.for:4440 */
/*<       goto599 >*/
    goto L599;
/* SOURCE exnmat.for:4442 */
/*<   509 continue >*/
L509:
/* SOURCE exnmat.for:4443 */
/*<       tptime=jtime-dtdy >*/
    tptime = *jtime - *dtdy;
/* SOURCE exnmat.for:4444 */
/*<        >*/
    ufgate_(&ipnt, &emc[1], &c_b303, enelem_1.ye2, enelem_1.ze, enelem_1.qe2, 
	    nex, &xscom_1.stdout, &tptime, enelem_1.qe1, &res, &pyl, &pql, &
	    pyr, &pqr);
/* SOURCE exnmat.for:4449 */
/*<       goto599 >*/
    goto L599;
/* SOURCE exnmat.for:4451 */
/*<   599 continue >*/
L599:
/* SOURCE exnmat.for:4453 */
/*<       ieq=ieq+1 >*/
    ++ieq;
/* SOURCE exnmat.for:4454 */
/*<       rhs(ieq)=-res >*/
    matcom_1.rhs[ieq - 1] = -res;
/* SOURCE exnmat.for:4455 */
/*<       jcol=exnodt(5,unn) >*/
    jcol = exnodt[unn * 9 + 5];
/* SOURCE exnmat.for:4456 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4457 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4458 */
/*<       pdavec(r(ieq)-ii+1)=pql >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = pql;
/* SOURCE exnmat.for:4459 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4460 */
/*<       pdavec(c(jcol)+ii)=pql >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = pql;
/* SOURCE exnmat.for:4461 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4462 */
/*<       jcol=jcol+1 >*/
    ++jcol;
/* SOURCE exnmat.for:4463 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4464 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4465 */
/*<       pdavec(r(ieq)-ii+1)=pyl >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = pyl;
/* SOURCE exnmat.for:4466 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4467 */
/*<       pdavec(c(jcol)+ii)=pyl >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = pyl;
/* SOURCE exnmat.for:4468 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4469 */
/*<       jcol=exnodt(5,dnn) >*/
    jcol = exnodt[dnn * 9 + 5];
/* SOURCE exnmat.for:4470 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4471 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4472 */
/*<       pdavec(r(ieq)-ii+1)=pqr >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = pqr;
/* SOURCE exnmat.for:4473 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4474 */
/*<       pdavec(c(jcol)+ii)=pqr >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = pqr;
/* SOURCE exnmat.for:4475 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4476 */
/*<       jcol=jcol+1 >*/
    ++jcol;
/* SOURCE exnmat.for:4477 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4478 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4479 */
/*<       pdavec(r(ieq)-ii+1)=pyr >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = pyr;
/* SOURCE exnmat.for:4480 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4481 */
/*<       pdavec(c(jcol)+ii)=pyr >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = pyr;
/* SOURCE exnmat.for:4482 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4484 */
/*<       goto8000 >*/
    goto L8000;
/*     CODE 6 FORCED BOUNDARY */
/* SOURCE exnmat.for:4488 */
/*<   600 continue >*/
L600:
/*        WRITE(STD6,*) ' DOING CODE=6 IN SETEXT' */
/* SOURCE exnmat.for:4490 */
/*<       type=emc(ipnt+1) >*/
    feq_gen_type_d_ = emc[ipnt + 1];
/* SOURCE exnmat.for:4491 */
/*<       itype=type >*/
    itype = feq_gen_type_d_;
/* SOURCE exnmat.for:4492 */
/*<       if(type.eq.3)itype=1 >*/
    if (feq_gen_type_d_ == 3) {
	itype = 1;
    }
/* SOURCE exnmat.for:4493 */
/*<       num=emc(ipnt+2) >*/
    num = emc[ipnt + 2];
/* SOURCE exnmat.for:4494 */
/*<       nsign=emc(ipnt+3) >*/
    nsign = emc[ipnt + 3];
/* SOURCE exnmat.for:4495 */
/*<       ntab=emc(ipnt+4) >*/
    ntab = emc[ipnt + 4];
/* SOURCE exnmat.for:4496 */
/*<       idum=emc(ipnt+6) >*/
    *idum = emc[ipnt + 6];
/* SOURCE exnmat.for:4497 */
/*<       func=rdum >*/
    func = *rdum;
/* SOURCE exnmat.for:4498 */
/*<       idum=emc(ipnt+8) >*/
    *idum = emc[ipnt + 8];
/* SOURCE exnmat.for:4499 */
/*<       qbase=rdum >*/
    qbase = *rdum;
/*       APPLY THE MULTIPLIER TO BOTH BASE AND TIME VARIABLE VALUE-Changed April 26, 2002 */
/* SOURCE exnmat.for:4501 */
/*<       idum=emc(ipnt+9) >*/
    *idum = emc[ipnt + 9];
/*        QBASE = QBASE*RDUM */
/* SOURCE exnmat.for:4503 */
/*<       func=func*rdum >*/
    func *= *rdum;
/* SOURCE exnmat.for:4505 */
/*<       if(emc(ipnt+10).gt.0)then >*/
    if (emc[ipnt + 10] > 0) {
/* SOURCE exnmat.for:4506 */
/*<       calllktstab(emc(ipnt+10),jtime,fb_adj_factor,ntab,pdv) >*/
	lktstab_(&emc[ipnt + 10], jtime, &feq_gen_fb_adj_factor_d_, &ntab, &pdv);
/*          QBASE = FB_ADJ_FACTOR*QBASE */
/* SOURCE exnmat.for:4511 */
/*<       func=fb_adj_factor*func >*/
	func = static_cast<double>(feq_gen_fb_adj_factor_d_) * func;
/* SOURCE exnmat.for:4512 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4514 */
/*<       ieq=ieq+1 >*/
    ++ieq;
/* SOURCE exnmat.for:4515 */
/*<       jcol=exnodt(5,num)+itype-1 >*/
    jcol = exnodt[num * 9 + 5] + itype - 1;
/*        WRITE(STD6,*) ' CODE=6: IEQ=',IEQ,' JCOL=',JCOL,' RDUM=',RDUM */
/* SOURCE exnmat.for:4517 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4518 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4519 */
/*<       pdavec(r(ieq)-ii+1)=1. >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = (float)1.;
/* SOURCE exnmat.for:4520 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4521 */
/*<       pdavec(c(jcol)+ii)=1. >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = (float)1.;
/* SOURCE exnmat.for:4522 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4524 */
/*<       if(type.eq.3)then >*/
    if (feq_gen_type_d_ == 3) {
/* SOURCE exnmat.for:4525 */
/*<       write(stdout,*)' CODE 6 TYPE 3 NO LONGER SUPPORTED' >*/
	feq_gen_io_d__568.ciunit = xscom_1.stdout;
	s_wsle(&feq_gen_io_d__568);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" CODE 6 TYPE 3 NO LONGER SUPPORTED"), (ftnlen)34)
		;
	e_wsle();
/* SOURCE exnmat.for:4526 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE exnmat.for:4527 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4529 */
/*<       if(type.eq.2)goto601 >*/
    if (feq_gen_type_d_ == 2) {
	goto L601;
    }
/* SOURCE exnmat.for:4530 */
/*<       if(func.lt.qbase)then >*/
    if (func < qbase) {
/*           IF THE FLOW IS LESS THAN THE USER SUPPLIED STEADY FLOW VALUE */
/*           THEN USE THE STEADY FLOW VALUE AS THE LOWER LIMIT.  OTHERWISE */
/*           USE THE VALUE AS DEFINED BY THE TABLE OR FILE. */
/* SOURCE exnmat.for:4534 */
/*<       func=qbase >*/
	func = qbase;
/* SOURCE exnmat.for:4535 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4536 */
/*<       if(nsign.lt.0)func=-func >*/
    if (nsign < 0) {
	func = -func;
    }
/* SOURCE exnmat.for:4537 */
/*<       if(type.eq.1)then >*/
    if (feq_gen_type_d_ == 1) {
/* SOURCE exnmat.for:4538 */
/*<       res=qe2(num)-func >*/
	res = static_cast<double>(enelem_1.qe2[num - 1]) - func;
/*            WRITE(STD6,*) ' CODE 6: NUM=',NUM,' QE2(NUM)=',QE2(NUM), */
/*     A             ' FUNC=',FUNC */
/* SOURCE exnmat.for:4541 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4542 */
/*<       goto602 >*/
    goto L602;
/* SOURCE exnmat.for:4543 */
/*<   601 continue >*/
L601:
/* SOURCE exnmat.for:4545 */
/*<       if(func.lt.qbase)then >*/
    if (func < qbase) {
/* SOURCE exnmat.for:4546 */
/*<       func=qbase >*/
	func = qbase;
/* SOURCE exnmat.for:4547 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4548 */
/*<       if(exnodt(3,num).le.0)then >*/
    if (exnodt[num * 9 + 3] <= 0) {
/*         FREE NODE- FLOW CANNOT BE CRITICAL. NO AREA KNOWN */
/* SOURCE exnmat.for:4551 */
/*<       res=ye2(num)+ze(num)-func >*/
	res = static_cast<double>(static_cast<double>(enelem_1.ye2[num - 1]) + enelem_1.ze[num - 1]) - func;
/* SOURCE exnmat.for:4552 */
/*<       goto650 >*/
	goto L650;
/* SOURCE exnmat.for:4553 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4555 */
/*<       if(emc(ipnt+5).gt.0)goto620 >*/
    if (emc[ipnt + 5] > 0) {
	goto L620;
    }
/*         FORCED VALUE VALID HERE-FLOW IS SUBCRITICAL */
/*         CHECK IF CHANGE OF STATE IS NEEDED */
/* SOURCE exnmat.for:4561 */
/*<       top=t2(exnodt(2,num)) >*/
    top = bnelem_1.t2[exnodt[num * 9 + 2] - 1];
/* SOURCE exnmat.for:4562 */
/*<       qcsqr=grav*ae2(num)**3/top >*/
/* Computing 3rd power */
    feq_gen_r_d_1 = enelem_1.ae2[num - 1];
    qcsqr = static_cast<double>(static_cast<double>(gravcm_1.grav) * (static_cast<double>(feq_gen_r_d_1) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1))) / top;
/* SOURCE exnmat.for:4563 */
/*<       if(qe2(num)**2.gt.qcsqr)goto610 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = enelem_1.qe2[num - 1];
    if (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1 > qcsqr) {
	goto L610;
    }
/* SOURCE exnmat.for:4564 */
/*<       res=ye2(num)+ze(num)-func >*/
    res = static_cast<double>(static_cast<double>(enelem_1.ye2[num - 1]) + enelem_1.ze[num - 1]) - func;
/* SOURCE exnmat.for:4565 */
/*<       goto650 >*/
    goto L650;
/* SOURCE exnmat.for:4566 */
/*<   610 continue >*/
L610:
/* SOURCE exnmat.for:4567 */
/*<       emc(ipnt+5)=1 >*/
    emc[ipnt + 5] = 1;
/* SOURCE exnmat.for:4568 */
/*<       adrs=exnodt(4,num) >*/
    adrs = exnodt[num * 9 + 4];
/* SOURCE exnmat.for:4569 */
/*<       callxlkt20(adrs,ye2(num),area,top,dtop,convey,dconvy,bn,dbn) >*/
    xlkt20_(&adrs, &enelem_1.ye2[num - 1], &area, &top, &dtop, &convey, &
	    dconvy, &bn, &dbn);
/* SOURCE exnmat.for:4573 */
/*<       res=qe2(num)**2-grav*area**3/top >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = enelem_1.qe2[num - 1];
/* Computing 3rd power */
    feq_gen_r_d_2 = area;
    res = static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) - static_cast<double>(static_cast<double>(gravcm_1.grav) * (static_cast<double>(feq_gen_r_d_2) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2))) / top;
/* SOURCE exnmat.for:4574 */
/*<       tp=-(grav*area**2)*(3.-area*dtop/top**2) >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = area;
/* Computing 2nd power */
    feq_gen_r_d_2 = top;
    tp = static_cast<double>(-(static_cast<double>(gravcm_1.grav) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1))) * (static_cast<double>((float)3.) - static_cast<double>(static_cast<double>(area) * dtop) / (static_cast<double>(feq_gen_r_d_2) *
	     feq_gen_r_d_2));
/* SOURCE exnmat.for:4575 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4576 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4577 */
/*<       pdavec(r(ieq)-ii+1)=tp >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = tp;
/* SOURCE exnmat.for:4578 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4579 */
/*<       pdavec(c(jcol)+ii)=tp >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = tp;
/* SOURCE exnmat.for:4580 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4581 */
/*<       jcol=jcol-1 >*/
    --jcol;
/* SOURCE exnmat.for:4582 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4583 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4584 */
/*<       pdavec(r(ieq)-ii+1)=2.*qe2(num) >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = static_cast<double>(enelem_1.qe2[num - 1]) * 
		(float)2.;
/* SOURCE exnmat.for:4585 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4586 */
/*<       pdavec(c(jcol)+ii)=2.*qe2(num) >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = static_cast<double>(enelem_1.qe2[num - 1]) *
		 (float)2.;
/* SOURCE exnmat.for:4587 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4588 */
/*<       goto650 >*/
    goto L650;
/* SOURCE exnmat.for:4589 */
/*<   620 continue >*/
L620:
/*         CRITICAL STATE HERE */
/*         CHECK IF CHANGE IN STATE IS NEEDED */
/* SOURCE exnmat.for:4595 */
/*<       if(func.gt.ye2(num)+ze(num))goto630 >*/
    if (func > static_cast<double>(enelem_1.ye2[num - 1]) + enelem_1.ze[num - 1]) {
	goto L630;
    }
/*           STAY IN CRITICAL STATE HERE */
/* SOURCE exnmat.for:4599 */
/*<       adrs=exnodt(4,num) >*/
    adrs = exnodt[num * 9 + 4];
/* SOURCE exnmat.for:4600 */
/*<       callxlkt20(adrs,ye2(num),area,top,dtop,convey,dconvy,bn,dbn) >*/
    xlkt20_(&adrs, &enelem_1.ye2[num - 1], &area, &top, &dtop, &convey, &
	    dconvy, &bn, &dbn);
/* SOURCE exnmat.for:4604 */
/*<       res=qe2(num)**2-grav*area**3/top >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = enelem_1.qe2[num - 1];
/* Computing 3rd power */
    feq_gen_r_d_2 = area;
    res = static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) - static_cast<double>(static_cast<double>(gravcm_1.grav) * (static_cast<double>(feq_gen_r_d_2) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2))) / top;
/* SOURCE exnmat.for:4605 */
/*<       tp=-(grav*area**2)*(3.-area*dtop/top**2) >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = area;
/* Computing 2nd power */
    feq_gen_r_d_2 = top;
    tp = static_cast<double>(-(static_cast<double>(gravcm_1.grav) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1))) * (static_cast<double>((float)3.) - static_cast<double>(static_cast<double>(area) * dtop) / (static_cast<double>(feq_gen_r_d_2) *
	     feq_gen_r_d_2));
/* SOURCE exnmat.for:4606 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4607 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4608 */
/*<       pdavec(r(ieq)-ii+1)=tp >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = tp;
/* SOURCE exnmat.for:4609 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4610 */
/*<       pdavec(c(jcol)+ii)=tp >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = tp;
/* SOURCE exnmat.for:4611 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4612 */
/*<       jcol=jcol-1 >*/
    --jcol;
/* SOURCE exnmat.for:4613 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4614 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4615 */
/*<       pdavec(r(ieq)-ii+1)=2.*qe2(num) >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = static_cast<double>(enelem_1.qe2[num - 1]) * 
		(float)2.;
/* SOURCE exnmat.for:4616 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4617 */
/*<       pdavec(c(jcol)+ii)=2.*qe2(num) >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = static_cast<double>(enelem_1.qe2[num - 1]) *
		 (float)2.;
/* SOURCE exnmat.for:4618 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4619 */
/*<       goto650 >*/
    goto L650;
/* SOURCE exnmat.for:4620 */
/*<   630 continue >*/
L630:
/*           SWITICH STATE HERE */
/* SOURCE exnmat.for:4624 */
/*<       emc(ipnt+5)=-1 >*/
    emc[ipnt + 5] = -1;
/* SOURCE exnmat.for:4625 */
/*<       res=ye2(num)+ze(num)-func >*/
    res = static_cast<double>(static_cast<double>(enelem_1.ye2[num - 1]) + enelem_1.ze[num - 1]) - func;
/* SOURCE exnmat.for:4626 */
/*<       goto650 >*/
    goto L650;
/* SOURCE exnmat.for:4627 */
/*<   650 continue >*/
L650:
/* SOURCE exnmat.for:4629 */
/*<   602 continue >*/
L602:
/* SOURCE exnmat.for:4630 */
/*<       rhs(ieq)=-res >*/
    matcom_1.rhs[ieq - 1] = -res;
/*      WRITE(STD6,9247) 1.0, 0.0, RES */
/* 9247  FORMAT(1X,2(1PE11.3),22X,1PE11.3) */
/* SOURCE exnmat.for:4634 */
/*<       goto8000 >*/
    goto L8000;
/*     CODE 7 - LEVEL POOL RESERVOIR */
/* SOURCE exnmat.for:4638 */
/*<   700 continue >*/
L700:
/* SOURCE exnmat.for:4639 */
/*<       dnn=emc(ipnt+1) >*/
    dnn = emc[ipnt + 1];
/* SOURCE exnmat.for:4640 */
/*<       ntab=emc(ipnt+2) >*/
    ntab = emc[ipnt + 2];
/* SOURCE exnmat.for:4641 */
/*<       unn=emc(ipnt+5) >*/
    unn = emc[ipnt + 5];
/* SOURCE exnmat.for:4642 */
/*<       idum=emc(ipnt+7) >*/
    *idum = emc[ipnt + 7];
/* SOURCE exnmat.for:4643 */
/*<       kfac=rdum >*/
    kfac = *rdum;
/*       DO THE LINEAR KINEMATIC EQUATION */
/* SOURCE exnmat.for:4646 */
/*<       ieq=ieq+1 >*/
    ++ieq;
/* SOURCE exnmat.for:4647 */
/*<       jcol=exnodt(5,unn) >*/
    jcol = exnodt[unn * 9 + 5];
/* SOURCE exnmat.for:4648 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4649 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4650 */
/*<       pdavec(r(ieq)-ii+1)=-kfac >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = -kfac;
/* SOURCE exnmat.for:4651 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4652 */
/*<       pdavec(c(jcol)+ii)=-kfac >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = -kfac;
/* SOURCE exnmat.for:4653 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4654 */
/*<       jcol=jcol+1 >*/
    ++jcol;
/* SOURCE exnmat.for:4655 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4656 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4657 */
/*<       pdavec(r(ieq)-ii+1)=1.0 >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = (float)1.;
/* SOURCE exnmat.for:4658 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4659 */
/*<       pdavec(c(jcol)+ii)=1.0 >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = (float)1.;
/* SOURCE exnmat.for:4660 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4661 */
/*<       jcol=exnodt(5,dnn) >*/
    jcol = exnodt[dnn * 9 + 5];
/* SOURCE exnmat.for:4662 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4663 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4664 */
/*<       pdavec(r(ieq)-ii+1)=-kfac >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = -kfac;
/* SOURCE exnmat.for:4665 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4666 */
/*<       pdavec(c(jcol)+ii)=-kfac >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = -kfac;
/* SOURCE exnmat.for:4667 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4668 */
/*<       jcol=jcol+1 >*/
    ++jcol;
/* SOURCE exnmat.for:4669 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4670 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4671 */
/*<       pdavec(r(ieq)-ii+1)=-1.0 >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = (float)-1.;
/* SOURCE exnmat.for:4672 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4673 */
/*<       pdavec(c(jcol)+ii)=-1.0 >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = (float)-1.;
/* SOURCE exnmat.for:4674 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4675 */
/*<        >*/
    matcom_1.rhs[ieq - 1] = -(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(enelem_1.ye2[unn - 1]) + enelem_1.ze[unn - 1]) - 
	    enelem_1.ye2[dnn - 1]) - enelem_1.ze[dnn - 1]) - static_cast<double>((static_cast<double>(enelem_1.qe2[unn 
	    - 1]) + enelem_1.qe2[dnn - 1])) * kfac);
/* SOURCE exnmat.for:4678 */
/*<       res=0.0 >*/
    res = (float)0.;
/* SOURCE exnmat.for:4679 */
/*<       wtc=1.-wt >*/
    wtc = static_cast<double>((float)1.) - *wt;
/*       ONLY ONE INFLOW NODE IN CURRENT VERSION. */
/* SOURCE exnmat.for:4683 */
/*<       ieq=ieq+1 >*/
    ++ieq;
/* SOURCE exnmat.for:4684 */
/*<       jcol=exnodt(5,unn) >*/
    jcol = exnodt[unn * 9 + 5];
/* SOURCE exnmat.for:4686 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4687 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4688 */
/*<       pdavec(r(ieq)-ii+1)=wt*dt >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = *wt * *dt;
/* SOURCE exnmat.for:4689 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4690 */
/*<       pdavec(c(jcol)+ii)=wt*dt >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = *wt * *dt;
/* SOURCE exnmat.for:4691 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4692 */
/*<       res=res+(wtc*qe1(unn)+wt*qe2(unn)) >*/
    res += static_cast<double>(static_cast<double>(wtc) * enelem_1.qe1[unn - 1]) + static_cast<double>(*wt) * enelem_1.qe2[unn - 1];
/*       INCLUDE THE RESERVOIR NODE. OUTFLOW BY SIGN CONVENTION */
/* SOURCE exnmat.for:4697 */
/*<       jcol=exnodt(5,dnn) >*/
    jcol = exnodt[dnn * 9 + 5];
/* SOURCE exnmat.for:4698 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4699 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4700 */
/*<       pdavec(r(ieq)-ii+1)=-wt*dt >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = -(*wt) * *dt;
/* SOURCE exnmat.for:4701 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4702 */
/*<       pdavec(c(jcol)+ii)=-wt*dt >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = -(*wt) * *dt;
/* SOURCE exnmat.for:4703 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4704 */
/*<       res=res-(wtc*qe1(dnn)+wt*qe2(dnn)) >*/
    res -= static_cast<double>(static_cast<double>(wtc) * enelem_1.qe1[dnn - 1]) + static_cast<double>(*wt) * enelem_1.qe2[dnn - 1];
/*       INCLUDE TIME DEPENDENT FLOWS AS COMPUTED IN SUBROUTINE LOAD */
/* SOURCE exnmat.for:4708 */
/*<       iatdf=emc(ipnt+3) >*/
    iatdf = emc[ipnt + 3];
/* SOURCE exnmat.for:4709 */
/*<       if(iatdf.gt.0)then >*/
    if (iatdf > 0) {
/* SOURCE exnmat.for:4710 */
/*<       res=res+qpvec(iatdf) >*/
	res += bnothr_1.qpvec[iatdf - 1];
/* SOURCE exnmat.for:4711 */
/*<       endif >*/
    }
/*       Include the rainfall and evaporation on the water surface.  Computed */
/*       in LOAD and stuffed into fixed slots in EMC. */
/*       RES NOW GIVES THE ALGEBRAIC SUM OF THE FLOWS INTO THE RESERVOIR */
/*       Rainfall on the surface.  Set using the surface area at start of time step. */
/* SOURCE exnmat.for:4717 */
/*<       idum=emc(ipnt+8) >*/
    *idum = emc[ipnt + 8];
/* SOURCE exnmat.for:4718 */
/*<       res=res+rdum >*/
    res += *rdum;
/*       Evaporation on the surface. Set using the surface area at start of time step. */
/* SOURCE exnmat.for:4720 */
/*<       idum=emc(ipnt+9) >*/
    *idum = emc[ipnt + 9];
/* SOURCE exnmat.for:4721 */
/*<       res=res-rdum >*/
    res -= *rdum;
/* SOURCE exnmat.for:4724 */
/*<       res=res*dt >*/
    res *= *dt;
/*       USE THE ARITHMETIC AVERAGE OF THE UPSTREAM AND DOWNSTREAM */
/*       ARGUMENTS. */
/* SOURCE exnmat.for:4727 */
/*<       arg=0.5*(ye2(unn)+ye2(dnn)) >*/
    arg = static_cast<double>((static_cast<double>(enelem_1.ye2[unn - 1]) + enelem_1.ye2[dnn - 1])) * (float).5;
/* SOURCE exnmat.for:4728 */
/*<       calllktab(ntab,arg,0,func,num,pdv) >*/
    lktab_(&ntab, &arg, &feq_gen_c_d_0, &func, &num, &pdv);
/* SOURCE exnmat.for:4731 */
/*<       if(pdv.lt.lprmin)pdv=lprmin >*/
    if (pdv < miscon_1.lprmin) {
	pdv = miscon_1.lprmin;
    }
/* SOURCE exnmat.for:4732 */
/*<       jcol=jcol+1 >*/
    ++jcol;
/* SOURCE exnmat.for:4733 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4734 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4735 */
/*<       pdavec(r(ieq)-ii+1)=-0.5*pdv >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = static_cast<double>(pdv) * (float)-.5;
/* SOURCE exnmat.for:4736 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4737 */
/*<       pdavec(c(jcol)+ii)=-0.5*pdv >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = static_cast<double>(pdv) * (float)-.5;
/* SOURCE exnmat.for:4738 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4739 */
/*<       jcol=exnodt(5,unn)+1 >*/
    jcol = exnodt[unn * 9 + 5] + 1;
/* SOURCE exnmat.for:4740 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4741 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4742 */
/*<       pdavec(r(ieq)-ii+1)=-0.5*pdv >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = static_cast<double>(pdv) * (float)-.5;
/* SOURCE exnmat.for:4743 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4744 */
/*<       pdavec(c(jcol)+ii)=-0.5*pdv >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = static_cast<double>(pdv) * (float)-.5;
/* SOURCE exnmat.for:4745 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4747 */
/*<       if(pdv.le.0.0)then >*/
    if (pdv <= (float)0.) {
/* SOURCE exnmat.for:4748 */
/*<       write(stdout,57)getusn(dnn),pdv,arg >*/
	feq_gen_io_d__583.ciunit = xscom_1.stdout;
	s_wsfe(&feq_gen_io_d__583);
	getusn_(feq_gen_ch_d_2, (ftnlen)5, &dnn);
	s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)5, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)5);
	do_fio(&feq_gen_c_d_1, (char *)&pdv, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&arg, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE exnmat.for:4749 */
/*<       stop'Abnormal stop: errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE exnmat.for:4750 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4751 */
/*<       res=res-func+abs(ae1(dnn)) >*/
    res = static_cast<double>(res) - func + (feq_gen_r_d_1 = enelem_1.ae1[dnn - 1], dabs(feq_gen_r_d_1));
/* SOURCE exnmat.for:4752 */
/*<       ae2(dnn)=-func >*/
    enelem_1.ae2[dnn - 1] = -func;
/*       STORE THE SURFACE AREA IN TE2. */
/* SOURCE exnmat.for:4754 */
/*<       te2(dnn)=pdv >*/
    enelem_1.te2[dnn - 1] = pdv;
/* SOURCE exnmat.for:4756 */
/*<       rhs(ieq)=-res >*/
    matcom_1.rhs[ieq - 1] = -res;
/* SOURCE exnmat.for:4758 */
/*<       goto8000 >*/
    goto L8000;
/*     CODE 8 - CRITICAL DEPTH */
/* SOURCE exnmat.for:4762 */
/*<   800 continue >*/
L800:
/* SOURCE exnmat.for:4763 */
/*<       num=emc(ipnt+1) >*/
    num = emc[ipnt + 1];
/* SOURCE exnmat.for:4764 */
/*<       ieq=ieq+1 >*/
    ++ieq;
/* SOURCE exnmat.for:4765 */
/*<       jcol=exnodt(5,num) >*/
    jcol = exnodt[num * 9 + 5];
/* SOURCE exnmat.for:4766 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4767 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4768 */
/*<       pdavec(r(ieq)-ii+1)=1. >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = (float)1.;
/* SOURCE exnmat.for:4769 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4770 */
/*<       pdavec(c(jcol)+ii)=1. >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = (float)1.;
/* SOURCE exnmat.for:4771 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4772 */
/*<       adrs=exnodt(4,num) >*/
    adrs = exnodt[num * 9 + 4];
/* SOURCE exnmat.for:4773 */
/*<       callxlkt20(adrs,ye2(num),area,top,dtop,convey,dconvy,bn,dbn) >*/
    xlkt20_(&adrs, &enelem_1.ye2[num - 1], &area, &top, &dtop, &convey, &
	    dconvy, &bn, &dbn);
/* SOURCE exnmat.for:4777 */
/*<       con=sqrt(grav*area/top) >*/
    con = sqrt(static_cast<double>(static_cast<double>(gravcm_1.grav) * area) / top);
/* SOURCE exnmat.for:4778 */
/*<       if(exnodt(1,num).lt.0)con=-con >*/
    if (exnodt[num * 9 + 1] < 0) {
	con = -con;
    }
/* SOURCE exnmat.for:4779 */
/*<       res=qe2(num)-area*con >*/
    res = static_cast<double>(enelem_1.qe2[num - 1]) - static_cast<double>(area) * con;
/* SOURCE exnmat.for:4780 */
/*<       rhs(ieq)=-res >*/
    matcom_1.rhs[ieq - 1] = -res;
/* SOURCE exnmat.for:4781 */
/*<       jcol=jcol+1 >*/
    ++jcol;
/* SOURCE exnmat.for:4782 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4783 */
/*<       tp=con*(0.5*area*dtop/top-1.5*top) >*/
    tp = static_cast<double>(con) * (static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(area) * (float).5) * dtop) / top) - static_cast<double>(top) * (float)1.5);
/* SOURCE exnmat.for:4784 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4785 */
/*<       pdavec(r(ieq)-ii+1)=tp >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = tp;
/* SOURCE exnmat.for:4786 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4787 */
/*<       pdavec(c(jcol)+ii)=tp >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = tp;
/* SOURCE exnmat.for:4788 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4789 */
/*<       goto8000 >*/
    goto L8000;
/*     CODE 9- MOMENTUM JUNCTION */
/* SOURCE exnmat.for:4793 */
/*<   900 continue >*/
L900:
/* SOURCE exnmat.for:4794 */
/*<       write(stdout,*)' SHOULD NOT REACH HERE- SETEXT' >*/
    feq_gen_io_d__585.ciunit = xscom_1.stdout;
    s_wsle(&feq_gen_io_d__585);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" SHOULD NOT REACH HERE- SETEXT"), (ftnlen)30);
    e_wsle();
/* SOURCE exnmat.for:4795 */
/*<       stop'Abnormal stop: errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/*        GOTO 8000 */
/*     CODE 10 - EQUALITY OF TOTAL ENERGY LINE ELEVATION */
/* SOURCE exnmat.for:4800 */
/*<  1000 continue >*/
L1000:
/* SOURCE exnmat.for:4801 */
/*<       num1=emc(ipnt+1) >*/
    num1 = emc[ipnt + 1];
/* SOURCE exnmat.for:4802 */
/*<       num2=emc(ipnt+2) >*/
    num2 = emc[ipnt + 2];
/* SOURCE exnmat.for:4803 */
/*<       ieq=ieq+1 >*/
    ++ieq;
/* SOURCE exnmat.for:4804 */
/*<       res=-ye2(num1)-ze(num1)+ye2(num2)+ze(num2) >*/
    res = static_cast<double>(static_cast<double>(static_cast<double>(-enelem_1.ye2[num1 - 1]) - enelem_1.ze[num1 - 1]) + enelem_1.ye2[num2 
	    - 1]) + enelem_1.ze[num2 - 1];
/* SOURCE exnmat.for:4805 */
/*<       rhs(ieq)=res >*/
    matcom_1.rhs[ieq - 1] = res;
/* SOURCE exnmat.for:4806 */
/*<       jcol=exnodt(5,num1) >*/
    jcol = exnodt[num1 * 9 + 5];
/* SOURCE exnmat.for:4807 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4808 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4809 */
/*<       adr1=r(ieq)-ii+1 >*/
	adr1 = matcom_1.feq_gen_r_d_[ieq - 1] - ii + 1;
/* SOURCE exnmat.for:4810 */
/*<       pdavec(adr1)=0. >*/
	matcom_1.pdavec[adr1 - 1] = (float)0.;
/* SOURCE exnmat.for:4811 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4812 */
/*<       adr1=c(jcol)+ii >*/
	adr1 = matcom_1.feq_gen_c_d_[jcol] + ii;
/* SOURCE exnmat.for:4813 */
/*<       pdavec(adr1)=0. >*/
	matcom_1.pdavec[adr1 - 1] = (float)0.;
/* SOURCE exnmat.for:4814 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4815 */
/*<       jcol=jcol+1 >*/
    ++jcol;
/* SOURCE exnmat.for:4816 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4817 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4818 */
/*<       adr2=r(ieq)-ii+1 >*/
	adr2 = matcom_1.feq_gen_r_d_[ieq - 1] - ii + 1;
/* SOURCE exnmat.for:4819 */
/*<       pdavec(adr2)=1. >*/
	matcom_1.pdavec[adr2 - 1] = (float)1.;
/* SOURCE exnmat.for:4820 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4821 */
/*<       adr2=c(jcol)+ii >*/
	adr2 = matcom_1.feq_gen_c_d_[jcol] + ii;
/* SOURCE exnmat.for:4822 */
/*<       pdavec(adr2)=1. >*/
	matcom_1.pdavec[adr2 - 1] = (float)1.;
/* SOURCE exnmat.for:4823 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4825 */
/*<       jcol=exnodt(5,num2) >*/
    jcol = exnodt[num2 * 9 + 5];
/* SOURCE exnmat.for:4826 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4827 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4828 */
/*<       adr3=r(ieq)-ii+1 >*/
	adr3 = matcom_1.feq_gen_r_d_[ieq - 1] - ii + 1;
/* SOURCE exnmat.for:4829 */
/*<       pdavec(adr3)=0. >*/
	matcom_1.pdavec[adr3 - 1] = (float)0.;
/* SOURCE exnmat.for:4830 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4831 */
/*<       adr3=c(jcol)+ii >*/
	adr3 = matcom_1.feq_gen_c_d_[jcol] + ii;
/* SOURCE exnmat.for:4832 */
/*<       pdavec(adr3)=0. >*/
	matcom_1.pdavec[adr3 - 1] = (float)0.;
/* SOURCE exnmat.for:4833 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4834 */
/*<       jcol=jcol+1 >*/
    ++jcol;
/* SOURCE exnmat.for:4835 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4836 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4837 */
/*<       adr4=r(ieq)-ii+1 >*/
	adr4 = matcom_1.feq_gen_r_d_[ieq - 1] - ii + 1;
/* SOURCE exnmat.for:4838 */
/*<       pdavec(adr4)=-1. >*/
	matcom_1.pdavec[adr4 - 1] = (float)-1.;
/* SOURCE exnmat.for:4839 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4840 */
/*<       adr4=c(jcol)+ii >*/
	adr4 = matcom_1.feq_gen_c_d_[jcol] + ii;
/* SOURCE exnmat.for:4841 */
/*<       pdavec(adr4)=-1. >*/
	matcom_1.pdavec[adr4 - 1] = (float)-1.;
/* SOURCE exnmat.for:4842 */
/*<       endif >*/
    }
/*       IF NODE IS NOT ON A BRANCH AREA UNDEFINED - SKIP NEXT SECT. */
/* SOURCE exnmat.for:4847 */
/*<       if(ae2(num1).gt.0.)then >*/
    if (enelem_1.ae2[num1 - 1] > (float)0.) {
/* SOURCE exnmat.for:4848 */
/*<       con=qe2(num1)*qe2(num1)/(grav*ae2(num1)*ae2(num1)) >*/
	con = static_cast<double>(static_cast<double>(enelem_1.qe2[num1 - 1]) * enelem_1.qe2[num1 - 1]) / (
		static_cast<double>(static_cast<double>(gravcm_1.grav) * enelem_1.ae2[num1 - 1]) * enelem_1.ae2[num1 - 
		1]);
/* SOURCE exnmat.for:4849 */
/*<       res=rhs(ieq)-0.5*con >*/
	res = static_cast<double>(matcom_1.rhs[ieq - 1]) - static_cast<double>(con) * (float).5;
/* SOURCE exnmat.for:4850 */
/*<       rhs(ieq)=res >*/
	matcom_1.rhs[ieq - 1] = res;
/* SOURCE exnmat.for:4851 */
/*<       div=qe2(num1) >*/
	div = enelem_1.qe2[num1 - 1];
/* SOURCE exnmat.for:4852 */
/*<       if(div.eq.0.0)div=1.0 >*/
	if (div == (float)0.) {
	    div = (float)1.;
	}
/* SOURCE exnmat.for:4854 */
/*<       pdavec(adr1)=con/div >*/
	matcom_1.pdavec[adr1 - 1] = static_cast<double>(con) / div;
/* SOURCE exnmat.for:4855 */
/*<       pdavec(adr2)=1.-con*t2(exnodt(2,num1))/ae2(num1) >*/
	matcom_1.pdavec[adr2 - 1] = static_cast<double>((float)1.) - static_cast<double>(static_cast<double>(con) * bnelem_1.t2[exnodt[num1 
		* 9 + 2] - 1]) / enelem_1.ae2[num1 - 1];
/* SOURCE exnmat.for:4856 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4858 */
/*<       if(ae2(num2).gt.0.)then >*/
    if (enelem_1.ae2[num2 - 1] > (float)0.) {
/* SOURCE exnmat.for:4859 */
/*<       con=qe2(num2)*qe2(num2)/(grav*ae2(num2)*ae2(num2)) >*/
	con = static_cast<double>(static_cast<double>(enelem_1.qe2[num2 - 1]) * enelem_1.qe2[num2 - 1]) / (
		static_cast<double>(static_cast<double>(gravcm_1.grav) * enelem_1.ae2[num2 - 1]) * enelem_1.ae2[num2 - 
		1]);
/* SOURCE exnmat.for:4860 */
/*<       res=rhs(ieq)+0.5*con >*/
	res = static_cast<double>(matcom_1.rhs[ieq - 1]) + static_cast<double>(con) * (float).5;
/* SOURCE exnmat.for:4861 */
/*<       rhs(ieq)=res >*/
	matcom_1.rhs[ieq - 1] = res;
/* SOURCE exnmat.for:4862 */
/*<       div=qe2(num2) >*/
	div = enelem_1.qe2[num2 - 1];
/* SOURCE exnmat.for:4863 */
/*<       if(div.eq.0.0)div=1.0 >*/
	if (div == (float)0.) {
	    div = (float)1.;
	}
/* SOURCE exnmat.for:4864 */
/*<       pdavec(adr3)=-con/div >*/
	matcom_1.pdavec[adr3 - 1] = static_cast<double>(-con) / div;
/* SOURCE exnmat.for:4865 */
/*<       pdavec(adr4)=con*t2(exnodt(2,num2))/ae2(num2)-1. >*/
	matcom_1.pdavec[adr4 - 1] = static_cast<double>(static_cast<double>(static_cast<double>(con) * bnelem_1.t2[exnodt[num2 * 9 + 2] - 
		1]) / enelem_1.ae2[num2 - 1]) - (float)1.;
/* SOURCE exnmat.for:4866 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4867 */
/*<       goto8000 >*/
    goto L8000;
/* SOURCE exnmat.for:4869 */
/*<  1100 continue >*/
L1100:
/*       IMPULSE + MOMENTUM  CONSERVATION IGNORING BOTTOM SLOPE AND */
/*       FRICTION.  CROSS SECTIONS MUST EXIST AT BOTH NODES AND */
/*       THEY MUST BE THE SAME SIZE.  BOTTOM ELEVATIONS MUST BE THE */
/*       SAME.  FLOW IS ASSUMED TO BE ADDED OR ABSTRACTED AT RIGHT */
/*       ANGLES TO THE CHANNEL. */
/* SOURCE exnmat.for:4876 */
/*<       nl=emc(ipnt+1) >*/
    nl = emc[ipnt + 1];
/* SOURCE exnmat.for:4877 */
/*<       nr=emc(ipnt+2) >*/
    nr = emc[ipnt + 2];
/* SOURCE exnmat.for:4879 */
/*<       yl=ye2(nl) >*/
    yl = enelem_1.ye2[nl - 1];
/* SOURCE exnmat.for:4880 */
/*<       yr=ye2(nr) >*/
    yr = enelem_1.ye2[nr - 1];
/* SOURCE exnmat.for:4881 */
/*<       ql=qe2(nl) >*/
    ql = enelem_1.qe2[nl - 1];
/* SOURCE exnmat.for:4882 */
/*<       qr=qe2(nr) >*/
    qr = enelem_1.qe2[nr - 1];
/* SOURCE exnmat.for:4884 */
/*<       ieq=ieq+1 >*/
    ++ieq;
/*       IS THERE INFLOW OR OUTFLOW TO THE JUNTION? */
/* SOURCE exnmat.for:4888 */
/*<       if(ql*exnodt(1,nl)+qr*exnodt(1,nr).lt.0.0)then >*/
    if (static_cast<double>(static_cast<double>(ql) * exnodt[nl * 9 + 1]) + static_cast<double>(qr) * exnodt[nr * 9 + 1] < (float)0.) {
/*         INFLOW TO THE JUNCTION FROM THE UNKNOWN EXTERIOR NODE */
/*         APPLY MOMENTUM BALANCE */
/* SOURCE exnmat.for:4893 */
/*<       callxlkt21(exnodt(4,nl),yl,al,tl,dtl,ybal,convey,dc,bl,dbl) >*/
	xlkt21_(&exnodt[nl * 9 + 4], &yl, &al, &tl, &dtl, &ybal, &convey, &dc,
		 &bl, &dbl);
/* SOURCE exnmat.for:4897 */
/*<       callxlkt21(exnodt(4,nr),yr,ar,tr,dtr,ybar,convey,dc,br,dbr) >*/
	xlkt21_(&exnodt[nr * 9 + 4], &yr, &ar, &tr, &dtr, &ybar, &convey, &dc,
		 &br, &dbr);
/* SOURCE exnmat.for:4903 */
/*<       vl=ql/al >*/
	vl = static_cast<double>(ql) / al;
/* SOURCE exnmat.for:4904 */
/*<       vr=qr/ar >*/
	vr = static_cast<double>(qr) / ar;
/* SOURCE exnmat.for:4906 */
/*<       rhs(ieq)=-(bl*vl*ql+grav*(ybal-ybar)-br*vr*qr) >*/
	matcom_1.rhs[ieq - 1] = -(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(bl) * vl) * ql) + static_cast<double>(gravcm_1.grav) * (static_cast<double>(ybal) - ybar))
		 - static_cast<double>(static_cast<double>(br) * vr) * qr);
/* SOURCE exnmat.for:4909 */
/*<       jcol=exnodt(5,nl) >*/
	jcol = exnodt[nl * 9 + 5];
/* SOURCE exnmat.for:4910 */
/*<       ii=ieq-jcol >*/
	ii = ieq - jcol;
/* SOURCE exnmat.for:4911 */
/*<       if(ii.gt.0)then >*/
	if (ii > 0) {
/* SOURCE exnmat.for:4912 */
/*<       pdavec(r(ieq)-ii+1)=2.*bl*vl >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = static_cast<double>(static_cast<double>(bl) * (float)2.) * vl;
/* SOURCE exnmat.for:4913 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:4914 */
/*<       pdavec(c(jcol)+ii)=2.*bl*vl >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = static_cast<double>(static_cast<double>(bl) * (float)2.) * 
		    vl;
/* SOURCE exnmat.for:4915 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:4916 */
/*<       jcol=jcol+1 >*/
	++jcol;
/* SOURCE exnmat.for:4917 */
/*<       ii=ieq-jcol >*/
	ii = ieq - jcol;
/* SOURCE exnmat.for:4918 */
/*<       if(ii.gt.0)then >*/
	if (ii > 0) {
/* SOURCE exnmat.for:4919 */
/*<       pdavec(r(ieq)-ii+1)=(al*dbl-bl*tl)*vl**2+grav*al >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = vl;
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>(al) * dbl) - static_cast<double>(bl) * tl))
		     * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) + static_cast<double>(gravcm_1.grav) * al;
/* SOURCE exnmat.for:4920 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:4921 */
/*<       pdavec(c(jcol)+ii)=(al*dbl-bl*tl)*vl**2+grav*al >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = vl;
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>(al) * dbl) - static_cast<double>(bl) * 
		    tl)) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) + static_cast<double>(gravcm_1.grav) * al;
/* SOURCE exnmat.for:4922 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:4925 */
/*<       jcol=exnodt(5,nr) >*/
	jcol = exnodt[nr * 9 + 5];
/* SOURCE exnmat.for:4926 */
/*<       ii=ieq-jcol >*/
	ii = ieq - jcol;
/* SOURCE exnmat.for:4927 */
/*<       if(ii.gt.0)then >*/
	if (ii > 0) {
/* SOURCE exnmat.for:4928 */
/*<       pdavec(r(ieq)-ii+1)=-2.*br*vr >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = static_cast<double>(static_cast<double>(br) * (float)-2.) * 
		    vr;
/* SOURCE exnmat.for:4929 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:4930 */
/*<       pdavec(c(jcol)+ii)=-2.*br*vr >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = static_cast<double>(static_cast<double>(br) * (float)-2.) * 
		    vr;
/* SOURCE exnmat.for:4931 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:4932 */
/*<       jcol=jcol+1 >*/
	++jcol;
/* SOURCE exnmat.for:4933 */
/*<       ii=ieq-jcol >*/
	ii = ieq - jcol;
/* SOURCE exnmat.for:4934 */
/*<       if(ii.gt.0)then >*/
	if (ii > 0) {
/* SOURCE exnmat.for:4935 */
/*<       pdavec(r(ieq)-ii+1)=-(ar*dbr-br*tr)*vr**2-grav*ar >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = vr;
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = static_cast<double>(static_cast<double>(-(static_cast<double>(static_cast<double>(ar) * dbr) - static_cast<double>(br) * 
		    tr)) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - static_cast<double>(gravcm_1.grav) * ar;
/* SOURCE exnmat.for:4936 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:4937 */
/*<       pdavec(c(jcol)+ii)=-(ar*dbr-br*tr)*vr**2-grav*ar >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = vr;
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = static_cast<double>(static_cast<double>(-(static_cast<double>(static_cast<double>(ar) * dbr) - static_cast<double>(br) * 
		    tr)) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - static_cast<double>(gravcm_1.grav) * ar;
/* SOURCE exnmat.for:4938 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:4942 */
/*<       else >*/
    } else {
/*         FORCE EQUALITY OF DEPTH.  BOTTOM ELEVATIONS FORCED TO BE THE */
/*         SAME IN CHECKING */
/* SOURCE exnmat.for:4946 */
/*<       rhs(ieq)=-(yl-yr) >*/
	matcom_1.rhs[ieq - 1] = -(static_cast<double>(yl) - yr);
/* SOURCE exnmat.for:4949 */
/*<       jcol=exnodt(5,nl) >*/
	jcol = exnodt[nl * 9 + 5];
/* SOURCE exnmat.for:4950 */
/*<       ii=ieq-jcol >*/
	ii = ieq - jcol;
/* SOURCE exnmat.for:4951 */
/*<       if(ii.gt.0)then >*/
	if (ii > 0) {
/* SOURCE exnmat.for:4952 */
/*<       pdavec(r(ieq)-ii+1)=0. >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = (float)0.;
/* SOURCE exnmat.for:4953 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:4954 */
/*<       pdavec(c(jcol)+ii)=0. >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = (float)0.;
/* SOURCE exnmat.for:4955 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:4956 */
/*<       jcol=jcol+1 >*/
	++jcol;
/* SOURCE exnmat.for:4957 */
/*<       ii=ieq-jcol >*/
	ii = ieq - jcol;
/* SOURCE exnmat.for:4958 */
/*<       if(ii.gt.0)then >*/
	if (ii > 0) {
/* SOURCE exnmat.for:4959 */
/*<       pdavec(r(ieq)-ii+1)=1. >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = (float)1.;
/* SOURCE exnmat.for:4960 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:4961 */
/*<       pdavec(c(jcol)+ii)=1. >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = (float)1.;
/* SOURCE exnmat.for:4962 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:4965 */
/*<       jcol=exnodt(5,nr) >*/
	jcol = exnodt[nr * 9 + 5];
/* SOURCE exnmat.for:4966 */
/*<       ii=ieq-jcol >*/
	ii = ieq - jcol;
/* SOURCE exnmat.for:4967 */
/*<       if(ii.gt.0)then >*/
	if (ii > 0) {
/* SOURCE exnmat.for:4968 */
/*<       pdavec(r(ieq)-ii+1)=0. >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = (float)0.;
/* SOURCE exnmat.for:4969 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:4970 */
/*<       pdavec(c(jcol)+ii)=0. >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = (float)0.;
/* SOURCE exnmat.for:4971 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:4972 */
/*<       jcol=jcol+1 >*/
	++jcol;
/* SOURCE exnmat.for:4973 */
/*<       ii=ieq-jcol >*/
	ii = ieq - jcol;
/* SOURCE exnmat.for:4974 */
/*<       if(ii.gt.0)then >*/
	if (ii > 0) {
/* SOURCE exnmat.for:4975 */
/*<       pdavec(r(ieq)-ii+1)=-1. >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = (float)-1.;
/* SOURCE exnmat.for:4976 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:4977 */
/*<       pdavec(c(jcol)+ii)=-1. >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = (float)-1.;
/* SOURCE exnmat.for:4978 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:4979 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:4980 */
/*<       goto8000 >*/
    goto L8000;
/*     MATCH AVERAGE ELEVATION */
/* SOURCE exnmat.for:4984 */
/*<  1200 continue >*/
L1200:
/* SOURCE exnmat.for:4985 */
/*<       unn=emc(ipnt+1) >*/
    unn = emc[ipnt + 1];
/* SOURCE exnmat.for:4986 */
/*<       dnn=emc(ipnt+2) >*/
    dnn = emc[ipnt + 2];
/* SOURCE exnmat.for:4987 */
/*<       mdn=emc(ipnt+3) >*/
    mdn = emc[ipnt + 3];
/* SOURCE exnmat.for:4988 */
/*<       idum=emc(ipnt+4) >*/
    *idum = emc[ipnt + 4];
/* SOURCE exnmat.for:4989 */
/*<       w=rdum >*/
    w = *rdum;
/* SOURCE exnmat.for:4991 */
/*<       ieq=ieq+1 >*/
    ++ieq;
/* SOURCE exnmat.for:4992 */
/*<       res=w*(ye2(unn)+ze(unn)) >*/
    res = static_cast<double>(w) * (static_cast<double>(enelem_1.ye2[unn - 1]) + enelem_1.ze[unn - 1]);
/* SOURCE exnmat.for:4994 */
/*<       jcol=exnodt(5,unn)+1 >*/
    jcol = exnodt[unn * 9 + 5] + 1;
/* SOURCE exnmat.for:4995 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:4996 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:4997 */
/*<       pdavec(r(ieq)-ii+1)=w >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = w;
/* SOURCE exnmat.for:4998 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:4999 */
/*<       pdavec(c(jcol)+ii)=w >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = w;
/* SOURCE exnmat.for:5000 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:5002 */
/*<       res=res+(1.0-w)*(ye2(dnn)+ze(dnn)) >*/
    res += static_cast<double>(static_cast<double>((static_cast<double>((float)1.) - w)) * (static_cast<double>(enelem_1.ye2[dnn - 1]) + enelem_1.ze[dnn - 1]));
/* SOURCE exnmat.for:5004 */
/*<       jcol=exnodt(5,dnn)+1 >*/
    jcol = exnodt[dnn * 9 + 5] + 1;
/* SOURCE exnmat.for:5005 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:5006 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:5007 */
/*<       pdavec(r(ieq)-ii+1)=1.-w >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = static_cast<double>((float)1.) - w;
/* SOURCE exnmat.for:5008 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:5009 */
/*<       pdavec(c(jcol)+ii)=1.-w >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = static_cast<double>((float)1.) - w;
/* SOURCE exnmat.for:5010 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:5012 */
/*<       res=res-(ye2(mdn)+ze(mdn)) >*/
    res -= static_cast<double>(enelem_1.ye2[mdn - 1]) + enelem_1.ze[mdn - 1];
/* SOURCE exnmat.for:5013 */
/*<       rhs(ieq)=-res >*/
    matcom_1.rhs[ieq - 1] = -res;
/* SOURCE exnmat.for:5015 */
/*<       jcol=exnodt(5,mdn)+1 >*/
    jcol = exnodt[mdn * 9 + 5] + 1;
/* SOURCE exnmat.for:5016 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:5017 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:5018 */
/*<       pdavec(r(ieq)-ii+1)=-1. >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = (float)-1.;
/* SOURCE exnmat.for:5019 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:5020 */
/*<       pdavec(c(jcol)+ii)=-1. >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = (float)-1.;
/* SOURCE exnmat.for:5021 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:5022 */
/*<       goto8000 >*/
    goto L8000;
/* SOURCE exnmat.for:5025 */
/*<  1300 continue >*/
L1300:
/*       CONSERVATION OF MOMENTUM DURING INFLOW AND CONSERVATION OF */
/*       SPECIFIC ENERGY DURING OUTFLOW.  BOTTOM ELEVATIONS AND */
/*       CROSS SECTIONS MUST BE THE SAME AND THE NODES MUST BE ON */
/*       BRANCHES IN NATURAL SENSE. */
/* SOURCE exnmat.for:5031 */
/*<       nl=emc(ipnt+1) >*/
    nl = emc[ipnt + 1];
/* SOURCE exnmat.for:5032 */
/*<       nr=emc(ipnt+2) >*/
    nr = emc[ipnt + 2];
/* SOURCE exnmat.for:5034 */
/*<       yl=ye2(nl) >*/
    yl = enelem_1.ye2[nl - 1];
/* SOURCE exnmat.for:5035 */
/*<       yr=ye2(nr) >*/
    yr = enelem_1.ye2[nr - 1];
/* SOURCE exnmat.for:5036 */
/*<       ql=qe2(nl) >*/
    ql = enelem_1.qe2[nl - 1];
/* SOURCE exnmat.for:5037 */
/*<       qr=qe2(nr) >*/
    qr = enelem_1.qe2[nr - 1];
/* SOURCE exnmat.for:5039 */
/*<       aflag=emc(ipnt+4) >*/
    aflag = emc[ipnt + 4];
/* SOURCE exnmat.for:5041 */
/*<       ieq=ieq+1 >*/
    ++ieq;
/*       IS THERE INFLOW OR OUTFLOW TO THE JUNCTION? */
/* SOURCE exnmat.for:5044 */
/*<       inout=(ql*exnodt(1,nl)+qr*exnodt(1,nr))/(abs(ql)+abs(qr)+qeps) >*/
    inout = (static_cast<double>(static_cast<double>(ql) * exnodt[nl * 9 + 1]) + static_cast<double>(qr) * exnodt[nr * 9 + 1]) / (dabs(ql) + 
	    dabs(qr) + *qeps);
/* SOURCE exnmat.for:5047 */
/*<       if(abs(inout).le.1.e-4)then >*/
    if (dabs(inout) <= (float)1e-4) {
/*         Ignore inflow and outflow and force equality of */
/*         elevation. Code 13 already requires matching inverts */
/*         so we need only work with depth */
/* SOURCE exnmat.for:5052 */
/*<       rhs(ieq)=-(yl-yr) >*/
	matcom_1.rhs[ieq - 1] = -(static_cast<double>(yl) - yr);
/* SOURCE exnmat.for:5054 */
/*<       jcol=exnodt(5,nl) >*/
	jcol = exnodt[nl * 9 + 5];
/* SOURCE exnmat.for:5055 */
/*<       ii=ieq-jcol >*/
	ii = ieq - jcol;
/* SOURCE exnmat.for:5056 */
/*<       if(ii.gt.0)then >*/
	if (ii > 0) {
/* SOURCE exnmat.for:5057 */
/*<       pdavec(r(ieq)-ii+1)=0.0 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = (float)0.;
/* SOURCE exnmat.for:5058 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:5059 */
/*<       pdavec(c(jcol)+ii)=0.0 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = (float)0.;
/* SOURCE exnmat.for:5060 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:5061 */
/*<       jcol=jcol+1 >*/
	++jcol;
/* SOURCE exnmat.for:5062 */
/*<       ii=ieq-jcol >*/
	ii = ieq - jcol;
/* SOURCE exnmat.for:5063 */
/*<       if(ii.gt.0)then >*/
	if (ii > 0) {
/* SOURCE exnmat.for:5064 */
/*<       pdavec(r(ieq)-ii+1)=1.0 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = (float)1.;
/* SOURCE exnmat.for:5065 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:5066 */
/*<       pdavec(c(jcol)+ii)=1.0 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = (float)1.;
/* SOURCE exnmat.for:5067 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:5069 */
/*<       jcol=exnodt(5,nr) >*/
	jcol = exnodt[nr * 9 + 5];
/* SOURCE exnmat.for:5070 */
/*<       ii=ieq-jcol >*/
	ii = ieq - jcol;
/* SOURCE exnmat.for:5071 */
/*<       if(ii.gt.0)then >*/
	if (ii > 0) {
/* SOURCE exnmat.for:5072 */
/*<       pdavec(r(ieq)-ii+1)=0.0 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = (float)0.;
/* SOURCE exnmat.for:5073 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:5074 */
/*<       pdavec(c(jcol)+ii)=0.0 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = (float)0.;
/* SOURCE exnmat.for:5075 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:5076 */
/*<       jcol=jcol+1 >*/
	++jcol;
/* SOURCE exnmat.for:5077 */
/*<       ii=ieq-jcol >*/
	ii = ieq - jcol;
/* SOURCE exnmat.for:5078 */
/*<       if(ii.gt.0)then >*/
	if (ii > 0) {
/* SOURCE exnmat.for:5079 */
/*<       pdavec(r(ieq)-ii+1)=-1.0 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = (float)-1.;
/* SOURCE exnmat.for:5080 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:5081 */
/*<       pdavec(c(jcol)+ii)=-1.0 >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = (float)-1.;
/* SOURCE exnmat.for:5082 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:5084 */
/*<       elseif(inout.lt.0.0)then >*/
    } else if (inout < (float)0.) {
/*         INFLOW TO THE JUNCTION FROM THE UNKNOWN EXTERIOR NODE(S) */
/*         APPLY MOMENTUM BALANCE. Feb. 15, 2001: require critical flow */
/*         be tablulated */
/* SOURCE exnmat.for:5090 */
/*<       if(aflag.gt.0)then >*/
	if (aflag > 0) {
/* SOURCE exnmat.for:5091 */
/*<        >*/
	    xlkt22_(&exnodt[nl * 9 + 4], &yl, &al, &tl, &dtl, &ybal, &convey, 
		    &dc, &bl, &dbl, &alpl, &dalpl, &qcl);
/* SOURCE exnmat.for:5096 */
/*<        >*/
	    xlkt22_(&exnodt[nr * 9 + 4], &yr, &ar, &tr, &dtr, &ybar, &convey, 
		    &dc, &br, &dbr, &alpr, &dalpr, &qcr);
/* SOURCE exnmat.for:5102 */
/*<       else >*/
	} else {
/*            stop 'setext: should not be here!' */
/* SOURCE exnmat.for:5104 */
/*<       callxlkt21(exnodt(4,nl),yl,al,tl,dtl,ybal,convey,dc,bl,dbl) >*/
	    xlkt21_(&exnodt[nl * 9 + 4], &yl, &al, &tl, &dtl, &ybal, &convey, 
		    &dc, &bl, &dbl);
/* SOURCE exnmat.for:5108 */
/*<       callxlkt21(exnodt(4,nr),yr,ar,tr,dtr,ybar,convey,dc,br,dbr) >*/
	    xlkt21_(&exnodt[nr * 9 + 4], &yr, &ar, &tr, &dtr, &ybar, &convey, 
		    &dc, &br, &dbr);
/* SOURCE exnmat.for:5112 */
/*<       alpl=1.0 >*/
	    alpl = (float)1.;
/* SOURCE exnmat.for:5113 */
/*<       alpr=1.0 >*/
	    alpr = (float)1.;
/* SOURCE exnmat.for:5114 */
/*<       dalpl=0.0 >*/
	    dalpl = (float)0.;
/* SOURCE exnmat.for:5115 */
/*<       dalpr=0.0 >*/
	    dalpr = (float)0.;
/* SOURCE exnmat.for:5116 */
/*<       qcl=al*sqrt(grav*al/tl) >*/
	    qcl = al * static_cast<float>(sqrt(static_cast<double>(static_cast<double>(gravcm_1.grav) * al) / tl));
/* SOURCE exnmat.for:5117 */
/*<       qcr=ar*sqrt(grav*ar/tr) >*/
	    qcr = ar * static_cast<float>(sqrt(static_cast<double>(static_cast<double>(gravcm_1.grav) * ar) / tr));
/* SOURCE exnmat.for:5118 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:5119 */
/*<       vl=ql/al >*/
	vl = static_cast<double>(ql) / al;
/* SOURCE exnmat.for:5120 */
/*<       vr=qr/ar >*/
	vr = static_cast<double>(qr) / ar;
/* SOURCE exnmat.for:5122 */
/*<       rhs(ieq)=-(bl*vl*ql+grav*(ybal-ybar)-br*vr*qr) >*/
	matcom_1.rhs[ieq - 1] = -(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(bl) * vl) * ql) + static_cast<double>(gravcm_1.grav) * (static_cast<double>(ybal) - ybar))
		 - static_cast<double>(static_cast<double>(br) * vr) * qr);
/* SOURCE exnmat.for:5124 */
/*<       jcol=exnodt(5,nl) >*/
	jcol = exnodt[nl * 9 + 5];
/* SOURCE exnmat.for:5125 */
/*<       ii=ieq-jcol >*/
	ii = ieq - jcol;
/* SOURCE exnmat.for:5126 */
/*<       if(ii.gt.0)then >*/
	if (ii > 0) {
/* SOURCE exnmat.for:5127 */
/*<       pdavec(r(ieq)-ii+1)=bl*(vl+vl) >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = static_cast<double>(bl) * (static_cast<double>(vl) + vl);
/* SOURCE exnmat.for:5128 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:5129 */
/*<       pdavec(c(jcol)+ii)=bl*(vl+vl) >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = static_cast<double>(bl) * (static_cast<double>(vl) + vl);
/* SOURCE exnmat.for:5130 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:5131 */
/*<       jcol=jcol+1 >*/
	++jcol;
/* SOURCE exnmat.for:5132 */
/*<       ii=ieq-jcol >*/
	ii = ieq - jcol;
/* SOURCE exnmat.for:5133 */
/*<       if(ii.gt.0)then >*/
	if (ii > 0) {
/* SOURCE exnmat.for:5134 */
/*<       pdavec(r(ieq)-ii+1)=grav*al*(1.-(ql/qcl)**2) >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(ql) / qcl;
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = static_cast<double>(static_cast<double>(gravcm_1.grav) * al) *
		     (static_cast<double>((float)1.) - static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE exnmat.for:5135 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:5136 */
/*<       pdavec(c(jcol)+ii)=grav*al*(1.-(ql/qcl)**2) >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(ql) / qcl;
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = static_cast<double>(static_cast<double>(gravcm_1.grav) * al) 
		    * (static_cast<double>((float)1.) - static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE exnmat.for:5137 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:5139 */
/*<       jcol=exnodt(5,nr) >*/
	jcol = exnodt[nr * 9 + 5];
/* SOURCE exnmat.for:5140 */
/*<       ii=ieq-jcol >*/
	ii = ieq - jcol;
/* SOURCE exnmat.for:5141 */
/*<       if(ii.gt.0)then >*/
	if (ii > 0) {
/* SOURCE exnmat.for:5142 */
/*<       pdavec(r(ieq)-ii+1)=-br*(vr+vr) >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = static_cast<double>(-br) * (static_cast<double>(vr) + vr);
/* SOURCE exnmat.for:5143 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:5144 */
/*<       pdavec(c(jcol)+ii)=-br*(vr+vr) >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = static_cast<double>(-br) * (static_cast<double>(vr) + vr);
/* SOURCE exnmat.for:5145 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:5146 */
/*<       jcol=jcol+1 >*/
	++jcol;
/* SOURCE exnmat.for:5147 */
/*<       ii=ieq-jcol >*/
	ii = ieq - jcol;
/* SOURCE exnmat.for:5148 */
/*<       if(ii.gt.0)then >*/
	if (ii > 0) {
/* SOURCE exnmat.for:5149 */
/*<       pdavec(r(ieq)-ii+1)=-grav*ar*(1.-(qr/qcr)**2) >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(qr) / qcr;
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = static_cast<double>(static_cast<double>(-gravcm_1.grav) * ar) 
		    * (static_cast<double>((float)1.) - static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE exnmat.for:5150 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:5151 */
/*<       pdavec(c(jcol)+ii)=-grav*ar*(1.-(qr/qcr)**2) >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(qr) / qcr;
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = static_cast<double>(static_cast<double>(-gravcm_1.grav) * 
		    ar) * (static_cast<double>((float)1.) - static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1);
/* SOURCE exnmat.for:5152 */
/*<       endif >*/
	}
/*         Do values for any side nodes that were given. */
/* SOURCE exnmat.for:5155 */
/*<       do1301i=1,emc(ipnt+6) >*/
	feq_gen_i_d_1 = emc[ipnt + 6];
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE exnmat.for:5156 */
/*<       nl=emc(ipnt+6+i) >*/
	    nl = emc[ipnt + 6 + feq_gen_i_d_];
/* SOURCE exnmat.for:5157 */
/*<       yl=ye2(nl) >*/
	    yl = enelem_1.ye2[nl - 1];
/* SOURCE exnmat.for:5158 */
/*<       callxlkt20(exnodt(4,nl),yl,al,tl,dtl,convey,dc,bl,dbl) >*/
	    xlkt20_(&exnodt[nl * 9 + 4], &yl, &al, &tl, &dtl, &convey, &dc, &
		    bl, &dbl);
/* SOURCE exnmat.for:5162 */
/*<       ql=qe2(nl) >*/
	    ql = enelem_1.qe2[nl - 1];
/* SOURCE exnmat.for:5163 */
/*<       vl=ql/al >*/
	    vl = static_cast<double>(ql) / al;
/*           Get the cosine of the entry angle for this side node. */
/* SOURCE exnmat.for:5165 */
/*<       idum=emc(ipnt+8+i) >*/
	    *idum = emc[ipnt + 8 + feq_gen_i_d_];
/* SOURCE exnmat.for:5166 */
/*<       tp=vl*rdum >*/
	    tp = static_cast<double>(vl) * *rdum;
/* SOURCE exnmat.for:5167 */
/*<       rhs(ieq)=rhs(ieq)-bl*ql*tp >*/
	    matcom_1.rhs[ieq - 1] -= static_cast<double>(static_cast<double>(bl) * ql) * tp;
/* SOURCE exnmat.for:5168 */
/*<       jcol=exnodt(5,nl) >*/
	    jcol = exnodt[nl * 9 + 5];
/* SOURCE exnmat.for:5169 */
/*<       ii=ieq-jcol >*/
	    ii = ieq - jcol;
/* SOURCE exnmat.for:5170 */
/*<       if(ii.gt.0)then >*/
	    if (ii > 0) {
/* SOURCE exnmat.for:5171 */
/*<       pdavec(r(ieq)-ii+1)=bl*(tp+tp) >*/
		matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = static_cast<double>(bl) * (static_cast<double>(tp) + tp);
/* SOURCE exnmat.for:5172 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:5173 */
/*<       pdavec(c(jcol)+ii)=bl*(tp+tp) >*/
		matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = static_cast<double>(bl) * (static_cast<double>(tp) + tp);
/* SOURCE exnmat.for:5174 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:5175 */
/*<       jcol=jcol+1 >*/
	    ++jcol;
/* SOURCE exnmat.for:5176 */
/*<       ii=ieq-jcol >*/
	    ii = ieq - jcol;
/* SOURCE exnmat.for:5177 */
/*<       if(ii.gt.0)then >*/
	    if (ii > 0) {
/* SOURCE exnmat.for:5178 */
/*<       pdavec(r(ieq)-ii+1)=(al*dbl-bl*tl)*vl*tp >*/
		matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>(al) * dbl) - static_cast<double>(bl) *
			 tl)) * vl) * tp;
/* SOURCE exnmat.for:5179 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:5180 */
/*<       pdavec(c(jcol)+ii)=(al*dbl-bl*tl)*vl*tp >*/
		matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = static_cast<double>(static_cast<double>((static_cast<double>(static_cast<double>(al) * dbl) - static_cast<double>(bl) 
			* tl)) * vl) * tp;
/* SOURCE exnmat.for:5181 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:5182 */
/*<  1301 continue >*/
/* L1301: */
	}
/* SOURCE exnmat.for:5183 */
/*<       else >*/
    } else {
/*         CONSERVATION OF SPECIFIC ENERGY. Find the cross section */
/*         elements. */
/*         Get the complement of the loss coefficient. */
/* SOURCE exnmat.for:5188 */
/*<       idum=emc(ipnt+5) >*/
	*idum = emc[ipnt + 5];
/* SOURCE exnmat.for:5189 */
/*<       wc=1.0-rdum >*/
	wc = static_cast<double>((float)1.) - *rdum;
/* SOURCE exnmat.for:5191 */
/*<       if(aflag.eq.0)then >*/
	if (aflag == 0) {
/*           ALPHA not tabulated. */
/*           No longer supported */
/*            WRITE(STDOUT,*) */
/*     A         ' Bug found. SETEXT: Code 13- should not get here' */
/*            STOP 'Abnormal stop. Bug found.' */
/* SOURCE exnmat.for:5197 */
/*<       callxlkt21(exnodt(4,nl),yl,al,tl,dtl,ybal,convey,dc,bl,dbl) >*/
	    xlkt21_(&exnodt[nl * 9 + 4], &yl, &al, &tl, &dtl, &ybal, &convey, 
		    &dc, &bl, &dbl);
/* SOURCE exnmat.for:5201 */
/*<       callxlkt21(exnodt(4,nr),yr,ar,tr,dtr,ybar,convey,dc,br,dbr) >*/
	    xlkt21_(&exnodt[nr * 9 + 4], &yr, &ar, &tr, &dtr, &ybar, &convey, 
		    &dc, &br, &dbr);
/* SOURCE exnmat.for:5205 */
/*<       alpl=1.0 >*/
	    alpl = (float)1.;
/* SOURCE exnmat.for:5206 */
/*<       alpr=1.0 >*/
	    alpr = (float)1.;
/* SOURCE exnmat.for:5207 */
/*<       dalpl=0.0 >*/
	    dalpl = (float)0.;
/* SOURCE exnmat.for:5208 */
/*<       dalpr=0.0 >*/
	    dalpr = (float)0.;
/* SOURCE exnmat.for:5209 */
/*<       qcl=al*sqrt(grav*al/tl) >*/
	    qcl = al * static_cast<float>(sqrt(static_cast<double>(static_cast<double>(gravcm_1.grav) * al) / tl));
/* SOURCE exnmat.for:5210 */
/*<       qcr=ar*sqrt(grav*ar/tr) >*/
	    qcr = ar * static_cast<float>(sqrt(static_cast<double>(static_cast<double>(gravcm_1.grav) * ar) / tr));
/* SOURCE exnmat.for:5211 */
/*<       else >*/
	} else {
/*           ALPHA is tabulated. */
/* SOURCE exnmat.for:5213 */
/*<        >*/
	    xlkt22_(&exnodt[nl * 9 + 4], &yl, &al, &tl, &dtl, &ybl, &convey, &
		    dc, &bl, &dbl, &alpl, &dalpl, &qcl);
/* SOURCE exnmat.for:5218 */
/*<        >*/
	    xlkt22_(&exnodt[nr * 9 + 4], &yr, &ar, &tr, &dtr, &ybr, &convey, &
		    dc, &br, &dbr, &alpr, &dalpr, &qcr);
/* SOURCE exnmat.for:5223 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:5225 */
/*<       vl=ql/al >*/
	vl = static_cast<double>(ql) / al;
/* SOURCE exnmat.for:5226 */
/*<       vr=qr/ar >*/
	vr = static_cast<double>(qr) / ar;
/* SOURCE exnmat.for:5228 */
/*<       rhs(ieq)=-(yl-yr+wc*(alpl*vl**2-alpr*vr**2)/twog) >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = vl;
/* Computing 2nd power */
	feq_gen_r_d_2 = vr;
	matcom_1.rhs[ieq - 1] = -(static_cast<double>(static_cast<double>(yl) - yr) + static_cast<double>(static_cast<double>(wc) * (static_cast<double>(static_cast<double>(alpl) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) - static_cast<double>(alpr) 
		* (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2))) / gravcm_1.twog);
/*          IF(IEQ.EQ.2453) THEN */
/*            WRITE(STDOUT,60) IEQ, WC, TWOG */
/* 60    FORMAT(/,' EQ=',I5,' WC=',F10.3,' TWOG=',F10.4) */
/*            WRITE(STDOUT,61)'left :', QL, VL, YL, TL, AL, ALPL, DALPL, */
/*     A              QCL */
/*            WRITE(STDOUT,61)'right:', QR, VR, YR, TR, AR, ALPR, DALPR, */
/*     A              QCR */
/* 61    FORMAT(A6,1X,' Q=',F10.3,' V=',F10.3,' Y=',F10.4,' T=',F10.3, */
/*     A      ' A=',F10.3,' ALPL=',F10.3,' DALPL=',F10.5,' QC=',F10.3) */
/*          ENDIF */
/* SOURCE exnmat.for:5241 */
/*<       jcol=exnodt(5,nl) >*/
	jcol = exnodt[nl * 9 + 5];
/* SOURCE exnmat.for:5242 */
/*<       ii=ieq-jcol >*/
	ii = ieq - jcol;
/* SOURCE exnmat.for:5243 */
/*<       if(ii.gt.0)then >*/
	if (ii > 0) {
/* SOURCE exnmat.for:5244 */
/*<       pdavec(r(ieq)-ii+1)=wc*alpl*vl/(grav*al) >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = static_cast<double>(static_cast<double>(static_cast<double>(wc) * alpl) * vl) / (
		    static_cast<double>(gravcm_1.grav) * al);
/* SOURCE exnmat.for:5245 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:5246 */
/*<       pdavec(c(jcol)+ii)=wc*alpl*vl/(grav*al) >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = static_cast<double>(static_cast<double>(static_cast<double>(wc) * alpl) * vl) / (
		    static_cast<double>(gravcm_1.grav) * al);
/* SOURCE exnmat.for:5247 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:5248 */
/*<       jcol=jcol+1 >*/
	++jcol;
/* SOURCE exnmat.for:5249 */
/*<       ii=ieq-jcol >*/
	ii = ieq - jcol;
/* SOURCE exnmat.for:5250 */
/*<       if(ii.gt.0)then >*/
	if (ii > 0) {
/*            PDAVEC(R(IEQ) - II +1) = 1.0 + WC*VL**2*(0.5*DALPL - */
/*     A                                    ALPL*TL/AL)/GRAV */
/* SOURCE exnmat.for:5253 */
/*<       pdavec(r(ieq)-ii+1)=1.0-(ql/qcl)**2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(ql) / qcl;
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = static_cast<double>((float)1.) - static_cast<double>(feq_gen_r_d_1) * 
		    feq_gen_r_d_1;
/* SOURCE exnmat.for:5254 */
/*<       else >*/
	} else {
/*            PDAVEC(C(JCOL) + II) = 1.0 + WC*VL**2*(0.5*DALPL - */
/*     A                                  ALPL*TL/AL)/GRAV */
/* SOURCE exnmat.for:5257 */
/*<       pdavec(c(jcol)+ii)=1.0-(ql/qcl)**2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(ql) / qcl;
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = static_cast<double>((float)1.) - static_cast<double>(feq_gen_r_d_1) * 
		    feq_gen_r_d_1;
/* SOURCE exnmat.for:5258 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:5261 */
/*<       jcol=exnodt(5,nr) >*/
	jcol = exnodt[nr * 9 + 5];
/* SOURCE exnmat.for:5262 */
/*<       ii=ieq-jcol >*/
	ii = ieq - jcol;
/* SOURCE exnmat.for:5263 */
/*<       if(ii.gt.0)then >*/
	if (ii > 0) {
/* SOURCE exnmat.for:5264 */
/*<       pdavec(r(ieq)-ii+1)=-wc*alpr*vr/(grav*ar) >*/
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = static_cast<double>(static_cast<double>(static_cast<double>(-wc) * alpr) * vr) / (
		    static_cast<double>(gravcm_1.grav) * ar);
/* SOURCE exnmat.for:5265 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:5266 */
/*<       pdavec(c(jcol)+ii)=-wc*alpr*vr/(grav*ar) >*/
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = static_cast<double>(static_cast<double>(static_cast<double>(-wc) * alpr) * vr) / (
		    static_cast<double>(gravcm_1.grav) * ar);
/* SOURCE exnmat.for:5267 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:5268 */
/*<       jcol=jcol+1 >*/
	++jcol;
/* SOURCE exnmat.for:5269 */
/*<       ii=ieq-jcol >*/
	ii = ieq - jcol;
/* SOURCE exnmat.for:5270 */
/*<       if(ii.gt.0)then >*/
	if (ii > 0) {
/*            PDAVEC(R(IEQ) - II +1) = -1.0 - WC*VR**2*(0.5*DALPR - */
/*     A                                    ALPR*TR/AR)/GRAV */
/* SOURCE exnmat.for:5273 */
/*<       pdavec(r(ieq)-ii+1)=-1.0+(qr/qcr)**2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(qr) / qcr;
	    matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) - (
		    float)1.;
/* SOURCE exnmat.for:5274 */
/*<       else >*/
	} else {
/*            PDAVEC(C(JCOL) + II) = -1.0 - WC*VR**2*(0.5*DALPR - */
/*     A                                  ALPR*TR/AR)/GRAV */
/* SOURCE exnmat.for:5277 */
/*<       pdavec(c(jcol)+ii)=-1.0+(qr/qcr)**2 >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = static_cast<double>(qr) / qcr;
	    matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) - (
		    float)1.;
/* SOURCE exnmat.for:5278 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:5279 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:5280 */
/*<       goto8000 >*/
    goto L8000;
/* SOURCE exnmat.for:5282 */
/*<  1400 continue >*/
L1400:
/* SOURCE exnmat.for:5284 */
/*<        >*/
    sidewr_(&ipnt, &xscom_1.stdout, jtime, nex, &c_b303, &emc[1], &exnodt[10],
	     enelem_1.qe2, enelem_1.ye2, enelem_1.ze, &res, &pyl, &pql, &pyr, 
	    &pqr, &pym, &pqm);
/* SOURCE exnmat.for:5289 */
/*<       nl=emc(ipnt+1) >*/
    nl = emc[ipnt + 1];
/* SOURCE exnmat.for:5290 */
/*<       nr=emc(ipnt+2) >*/
    nr = emc[ipnt + 2];
/* SOURCE exnmat.for:5291 */
/*<       mdn=emc(ipnt+3) >*/
    mdn = emc[ipnt + 3];
/* SOURCE exnmat.for:5293 */
/*<       ieq=ieq+1 >*/
    ++ieq;
/* SOURCE exnmat.for:5295 */
/*<       rhs(ieq)=-res >*/
    matcom_1.rhs[ieq - 1] = -res;
/* SOURCE exnmat.for:5297 */
/*<       jcol=exnodt(5,nl) >*/
    jcol = exnodt[nl * 9 + 5];
/* SOURCE exnmat.for:5298 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:5299 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:5300 */
/*<       pdavec(r(ieq)-ii+1)=pql >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = pql;
/* SOURCE exnmat.for:5301 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:5302 */
/*<       pdavec(c(jcol)+ii)=pql >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = pql;
/* SOURCE exnmat.for:5303 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:5304 */
/*<       jcol=jcol+1 >*/
    ++jcol;
/* SOURCE exnmat.for:5305 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:5306 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:5307 */
/*<       pdavec(r(ieq)-ii+1)=pyl >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = pyl;
/* SOURCE exnmat.for:5308 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:5309 */
/*<       pdavec(c(jcol)+ii)=pyl >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = pyl;
/* SOURCE exnmat.for:5310 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:5312 */
/*<       jcol=exnodt(5,nr) >*/
    jcol = exnodt[nr * 9 + 5];
/* SOURCE exnmat.for:5313 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:5314 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:5315 */
/*<       pdavec(r(ieq)-ii+1)=pqr >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = pqr;
/* SOURCE exnmat.for:5316 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:5317 */
/*<       pdavec(c(jcol)+ii)=pqr >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = pqr;
/* SOURCE exnmat.for:5318 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:5319 */
/*<       jcol=jcol+1 >*/
    ++jcol;
/* SOURCE exnmat.for:5320 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:5321 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:5322 */
/*<       pdavec(r(ieq)-ii+1)=pyr >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = pyr;
/* SOURCE exnmat.for:5323 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:5324 */
/*<       pdavec(c(jcol)+ii)=pyr >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = pyr;
/* SOURCE exnmat.for:5325 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:5327 */
/*<       jcol=exnodt(5,mdn) >*/
    jcol = exnodt[mdn * 9 + 5];
/* SOURCE exnmat.for:5328 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:5329 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:5330 */
/*<       pdavec(r(ieq)-ii+1)=pqm >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = pqm;
/* SOURCE exnmat.for:5331 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:5332 */
/*<       pdavec(c(jcol)+ii)=pqm >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = pqm;
/* SOURCE exnmat.for:5333 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:5334 */
/*<       jcol=jcol+1 >*/
    ++jcol;
/* SOURCE exnmat.for:5335 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:5336 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:5337 */
/*<       pdavec(r(ieq)-ii+1)=pym >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = pym;
/* SOURCE exnmat.for:5338 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:5339 */
/*<       pdavec(c(jcol)+ii)=pym >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = pym;
/* SOURCE exnmat.for:5340 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:5341 */
/*<       goto8000 >*/
    goto L8000;
/* SOURCE exnmat.for:5343 */
/*<  1500 continue >*/
L1500:
/*         DUMMY BRANCH. TWO EQUATIONS. */
/* SOURCE exnmat.for:5345 */
/*<       unn=emc(ipnt+1) >*/
    unn = emc[ipnt + 1];
/* SOURCE exnmat.for:5346 */
/*<       dnn=emc(ipnt+2) >*/
    dnn = emc[ipnt + 2];
/* SOURCE exnmat.for:5347 */
/*<       idum=emc(ipnt+4) >*/
    *idum = emc[ipnt + 4];
/* SOURCE exnmat.for:5348 */
/*<       kfac=rdum >*/
    kfac = *rdum;
/* SOURCE exnmat.for:5349 */
/*<       idum=emc(ipnt+5) >*/
    *idum = emc[ipnt + 5];
/* SOURCE exnmat.for:5350 */
/*<       asur=rdum >*/
    asur = *rdum;
/*         DO THE LINEAR KINEMATIC EQUATION */
/* SOURCE exnmat.for:5353 */
/*<       ieq=ieq+1 >*/
    ++ieq;
/* SOURCE exnmat.for:5354 */
/*<       jcol=exnodt(5,unn) >*/
    jcol = exnodt[unn * 9 + 5];
/* SOURCE exnmat.for:5355 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:5356 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:5357 */
/*<       pdavec(r(ieq)-ii+1)=-kfac >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = -kfac;
/* SOURCE exnmat.for:5358 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:5359 */
/*<       pdavec(c(jcol)+ii)=-kfac >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = -kfac;
/* SOURCE exnmat.for:5360 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:5361 */
/*<       jcol=jcol+1 >*/
    ++jcol;
/* SOURCE exnmat.for:5362 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:5363 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:5364 */
/*<       pdavec(r(ieq)-ii+1)=1.0 >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = (float)1.;
/* SOURCE exnmat.for:5365 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:5366 */
/*<       pdavec(c(jcol)+ii)=1.0 >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = (float)1.;
/* SOURCE exnmat.for:5367 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:5368 */
/*<       jcol=exnodt(5,dnn) >*/
    jcol = exnodt[dnn * 9 + 5];
/* SOURCE exnmat.for:5369 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:5370 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:5371 */
/*<       pdavec(r(ieq)-ii+1)=-kfac >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = -kfac;
/* SOURCE exnmat.for:5372 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:5373 */
/*<       pdavec(c(jcol)+ii)=-kfac >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = -kfac;
/* SOURCE exnmat.for:5374 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:5375 */
/*<       jcol=jcol+1 >*/
    ++jcol;
/* SOURCE exnmat.for:5376 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:5377 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:5378 */
/*<       pdavec(r(ieq)-ii+1)=-1.0 >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = (float)-1.;
/* SOURCE exnmat.for:5379 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:5380 */
/*<       pdavec(c(jcol)+ii)=-1.0 >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = (float)-1.;
/* SOURCE exnmat.for:5381 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:5382 */
/*<        >*/
    matcom_1.rhs[ieq - 1] = -(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(enelem_1.ye2[unn - 1]) + enelem_1.ze[unn - 1]) - 
	    enelem_1.ye2[dnn - 1]) - enelem_1.ze[dnn - 1]) - static_cast<double>((static_cast<double>(enelem_1.qe2[unn 
	    - 1]) + enelem_1.qe2[dnn - 1])) * kfac);
/*         DO CONTINUITY EQUATION NEXT.  USE FULLY FORWARD WEIGHTING. */
/* SOURCE exnmat.for:5387 */
/*<       fac=-asur/dt >*/
    fac = -asur / *dt;
/* SOURCE exnmat.for:5389 */
/*<       ieq=ieq+1 >*/
    ++ieq;
/* SOURCE exnmat.for:5390 */
/*<       jcol=exnodt(5,unn) >*/
    jcol = exnodt[unn * 9 + 5];
/* SOURCE exnmat.for:5391 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:5392 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:5393 */
/*<       pdavec(r(ieq)-ii+1)=1.0 >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = (float)1.;
/* SOURCE exnmat.for:5394 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:5395 */
/*<       pdavec(c(jcol)+ii)=1.0 >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = (float)1.;
/* SOURCE exnmat.for:5396 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:5397 */
/*<       jcol=jcol+1 >*/
    ++jcol;
/* SOURCE exnmat.for:5398 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:5399 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:5400 */
/*<       pdavec(r(ieq)-ii+1)=fac >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = fac;
/* SOURCE exnmat.for:5401 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:5402 */
/*<       pdavec(c(jcol)+ii)=fac >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = fac;
/* SOURCE exnmat.for:5403 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:5404 */
/*<       jcol=exnodt(5,dnn) >*/
    jcol = exnodt[dnn * 9 + 5];
/* SOURCE exnmat.for:5405 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:5406 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:5407 */
/*<       pdavec(r(ieq)-ii+1)=-1.0 >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = (float)-1.;
/* SOURCE exnmat.for:5408 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:5409 */
/*<       pdavec(c(jcol)+ii)=-1.0 >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = (float)-1.;
/* SOURCE exnmat.for:5410 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:5411 */
/*<       jcol=jcol+1 >*/
    ++jcol;
/* SOURCE exnmat.for:5412 */
/*<       ii=ieq-jcol >*/
    ii = ieq - jcol;
/* SOURCE exnmat.for:5413 */
/*<       if(ii.gt.0)then >*/
    if (ii > 0) {
/* SOURCE exnmat.for:5414 */
/*<       pdavec(r(ieq)-ii+1)=fac >*/
	matcom_1.pdavec[matcom_1.feq_gen_r_d_[ieq - 1] - ii] = fac;
/* SOURCE exnmat.for:5415 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:5416 */
/*<       pdavec(c(jcol)+ii)=fac >*/
	matcom_1.pdavec[matcom_1.feq_gen_c_d_[jcol] + ii - 1] = fac;
/* SOURCE exnmat.for:5417 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:5419 */
/*<        >*/
    matcom_1.rhs[ieq - 1] = -(static_cast<double>(static_cast<double>(enelem_1.qe2[unn - 1]) - enelem_1.qe2[dnn - 1]) + 
	    static_cast<double>(fac) * (static_cast<double>(static_cast<double>(static_cast<double>(enelem_1.ye2[dnn - 1]) + enelem_1.ye2[unn - 1]) - 
	    enelem_1.ye1[dnn - 1]) - enelem_1.ye1[unn - 1]));
/* SOURCE exnmat.for:5422 */
/*<       goto8000 >*/
    goto L8000;
/* SOURCE exnmat.for:5424 */
/*<  8000 continue >*/
L8000:
/* SOURCE exnmat.for:5425 */
/*<       goto20 >*/
    goto L20;
/* SOURCE exnmat.for:5426 */
/*<  9000 continue >*/
L9000:
/* SOURCE exnmat.for:5428 */
/*<       rnorm=0.0 >*/
    *rnorm = (float)0.;
/* SOURCE exnmat.for:5429 */
/*<       do9500irow=1,numeq >*/
    feq_gen_i_d_1 = matcom_1.numeq;
    for (irow = 1; irow <= feq_gen_i_d_1; ++irow) {
/* SOURCE exnmat.for:5430 */
/*<       temp=rhs(irow) >*/
	temp = matcom_1.rhs[irow - 1];
/* SOURCE exnmat.for:5431 */
/*<       if(abs(temp).gt.1.e15)temp=1.e15 >*/
	if (dabs(temp) > (float)1e15) {
	    temp = (float)1e15;
	}
/* SOURCE exnmat.for:5432 */
/*<       rnorm=rnorm+temp**2 >*/
/* Computing 2nd power */
	feq_gen_r_d_1 = temp;
	*rnorm += static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/* SOURCE exnmat.for:5433 */
/*<       if(abs(temp).gt.mxres)then >*/
	if (dabs(temp) > *mxres) {
/* SOURCE exnmat.for:5434 */
/*<       mxres=abs(temp) >*/
	    *mxres = dabs(temp);
/* SOURCE exnmat.for:5435 */
/*<       lmxres=irow >*/
	    *lmxres = irow;
/* SOURCE exnmat.for:5436 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:5437 */
/*<  9500 continue >*/
/* L9500: */
    }
/* SOURCE exnmat.for:5438 */
/*<       return >*/
    return 0;
/* SOURCE exnmat.for:5439 */
/*<       end >*/
} /* setext_ */

#undef rdum
#undef idum





/* SOURCE exnmat.for:5443 */
/*<       realfunctionso(y1,y3,hg) >*/
doublereal so_(real *y1, real *y3, real *hg)
{
    /* Initialized data */

    static real w = (float)96.;
    static real bg = (float)68.75;
    static real a0 = (float)299.5;
    static real g = (float)32.2;
    static real alpha = (float)1.55;
    static real beta = (float)1.2373;

    /* System generated locals */
    real ret_val, feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    real feq_gen_d_d_, e, a1, a3, y2, ag, temp;

/*     + + + PURPOSE + + + */
/*     Compute submerged orifice flow. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:5450 */
/*<       realhg,y1,y3 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Y1     - maximum depth upstream of sluice gates */
/*     Y3     - maximum depth immediately downstream of sluice gates */
/*     HG     - sluice gate opening */
/* INCLUDE exnmat.for:5457 */
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
/*     + + + SAVED VALUES + + + */
/* SOURCE exnmat.for:5460 */
/*<       reala0,alpha,beta,bg,g,w >*/
/* SOURCE exnmat.for:5461 */
/*<       savea0,alpha,beta,bg,g,w >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE exnmat.for:5464 */
/*<       reala1,a3,ag,d,e,hh,hhg,y,y2,temp >*/
/*     + + + INTRINSICS + + + */
/* SOURCE exnmat.for:5467 */
/*<       intrinsicsqrt >*/
/*     + + + STATEMENT FUNCTION TYPES + + + */
/* SOURCE exnmat.for:5470 */
/*<       reala,c >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + STATEMENT FUNCTION DEFINITIONS + + + */
/* SOURCE exnmat.for:5473 */
/*<       dataw/96.0/,bg/68.75/,a0/299.5/,g/32.2/,alpha/1.55/,beta/1.2373/ >*/
/* SOURCE exnmat.for:5477 */
/*<       a(y)=403.5+y*(144.+y*2.75) >*/
/* SOURCE exnmat.for:5478 */
/*<       c(hh,hhg)=.66516+(hhg/hh)*(-.4525+.70985*(hhg/hh)) >*/
/* *********************************************************************** */
/* SOURCE exnmat.for:5480 */
/*<       ag=c(y1-1,hg)*hg*bg >*/
    feq_gen_r_d_1 = static_cast<double>(*y1) - 1;
    ag = static_cast<double>(static_cast<double>((static_cast<double>((float).66516) + static_cast<double>(static_cast<double>(*hg) / feq_gen_r_d_1) * (static_cast<double>((float)-.4525) + static_cast<double>((float).70985) * (static_cast<double>(*hg) /
	     feq_gen_r_d_1)))) * *hg) * bg;
/* SOURCE exnmat.for:5481 */
/*<       a1=a(y1) >*/
    a1 = static_cast<double>((float)403.5) + static_cast<double>(*y1) * (static_cast<double>((float)144.) + static_cast<double>(*y1) * (float)2.75);
/* SOURCE exnmat.for:5483 */
/*<       e=(ag*a1)**2/(a1**2-alpha*ag**2) >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(ag) * a1;
/* Computing 2nd power */
    feq_gen_r_d_2 = a1;
/* Computing 2nd power */
    feq_gen_r_d_3 = ag;
    e = static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / (static_cast<double>(static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2) - static_cast<double>(alpha) * (static_cast<double>(feq_gen_r_d_3) * feq_gen_r_d_3));
/* SOURCE exnmat.for:5485 */
/*<       a3=a0+w*y3 >*/
    a3 = static_cast<double>(a0) + static_cast<double>(w) * *y3;
/* SOURCE exnmat.for:5487 */
/*<       d=(ag*a3)/(a3-beta*ag) >*/
    feq_gen_d_d_ = static_cast<double>(static_cast<double>(ag) * a3) / (static_cast<double>(a3) - static_cast<double>(beta) * ag);
/* SOURCE exnmat.for:5489 */
/*<       temp=4.*e**2/(w*d)**2-(4.*e*y1)/(w*d)+y3**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = e;
/* Computing 2nd power */
    feq_gen_r_d_2 = static_cast<double>(w) * feq_gen_d_d_;
/* Computing 2nd power */
    feq_gen_r_d_3 = *y3;
    temp = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * (float)4.) / (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) - static_cast<double>(static_cast<double>(static_cast<double>(e) * (float)4.) * *y1) / (static_cast<double>(w) 
	    * feq_gen_d_d_)) + static_cast<double>(feq_gen_r_d_3) * feq_gen_r_d_3;
/*      IF(TEMP.LT.0.0) THEN */
/*        WRITE(STD6,50) TEMP */
/* 50    FORMAT(' NEGATIVE ARGUMENT TO SQRT IN FUNCTION SO=',1PE15.6) */
/*        TEMP = 0.0 */
/*      ENDIF */
/* SOURCE exnmat.for:5496 */
/*<       y2=2.*e/(w*d)+sqrt(temp) >*/
    y2 = static_cast<double>(static_cast<double>(e) * (float)2.) / (static_cast<double>(w) * feq_gen_d_d_) + sqrt(temp);
/* SOURCE exnmat.for:5498 */
/*<       so=sqrt(2.*g*(y1-y2)*e) >*/
    ret_val = sqrt(static_cast<double>(static_cast<double>(static_cast<double>(g) * (float)2.) * (static_cast<double>(*y1) - y2)) * e);
/* SOURCE exnmat.for:5500 */
/*<       return >*/
    return ret_val;
/* SOURCE exnmat.for:5501 */
/*<       end >*/
} /* so_ */




/* SOURCE exnmat.for:5505 */
/*<       realfunctionsoy2(y1,y3,hg) >*/
doublereal soy2_(real *y1, real *y3, real *hg)
{
    /* Initialized data */

    static real w = (float)96.;
    static real bg = (float)68.75;
    static real a0 = (float)299.5;
    static real alpha = (float)1.55;
    static real beta = (float)1.2373;

    /* System generated locals */
    real ret_val, feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    real feq_gen_d_d_, e, a1, a3, y2, ag, dd, y2lim;

/*     + + + PURPOSE + + + */
/*     Compute the depth at section 2 assuming submerged orifice flow */
/*     and a constant contraction coefficient and signal if */
/*     submerged orifice flow is valid.  If valid, returns depth at */
/*     section 2 as a positive number.  Otherwise returns a -1. */
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:5515 */
/*<       realhg,y1,y3 >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Y1     - maximum depth upstream of sluice gates */
/*     Y3     - maximum depth immediately downstream of sluice gates */
/*     HG     - sluice gate opening */
/*     + + + SAVED VALUES + + + */
/* SOURCE exnmat.for:5523 */
/*<       reala0,alpha,beta,bg,w >*/
/* SOURCE exnmat.for:5524 */
/*<       savea0,alpha,beta,bg,w >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE exnmat.for:5527 */
/*<       reala1,a3,ag,d,dd,e,hh,hhg,y,y2,y2lim >*/
/*     + + + INTRINSICS + + + */
/* SOURCE exnmat.for:5530 */
/*<       intrinsicsqrt >*/
/*     + + + STATEMENT FUNCTION TYPES + + + */
/* SOURCE exnmat.for:5533 */
/*<       reala,c >*/
/*     + + + DATA INITIALIZATIONS + + + */
/*     + + + STATEMENT FUNCTION DEFINITIONS + + + */
/* SOURCE exnmat.for:5536 */
/*<       dataw/96.0/,bg/68.75/,a0/299.5/,alpha/1.55/,beta/1.2373/ >*/
/* SOURCE exnmat.for:5540 */
/*<       a(y)=403.5+y*(144.+y*2.75) >*/
/* SOURCE exnmat.for:5541 */
/*<       c(hh,hhg)=.66516+(hhg/hh)*(-.4525+.70985*(hhg/hh)) >*/
/* *********************************************************************** */
/* SOURCE exnmat.for:5543 */
/*<       y2lim=c(y1-1,hg)*hg >*/
    feq_gen_r_d_1 = static_cast<double>(*y1) - 1;
    y2lim = static_cast<double>((static_cast<double>((float).66516) + static_cast<double>(static_cast<double>(*hg) / feq_gen_r_d_1) * (static_cast<double>((float)-.4525) + static_cast<double>((float).70985) * (static_cast<double>(*
	    hg) / feq_gen_r_d_1)))) * *hg;
/* SOURCE exnmat.for:5544 */
/*<       ag=y2lim*bg >*/
    ag = static_cast<double>(y2lim) * bg;
/* SOURCE exnmat.for:5545 */
/*<       a1=a(y1) >*/
    a1 = static_cast<double>((float)403.5) + static_cast<double>(*y1) * (static_cast<double>((float)144.) + static_cast<double>(*y1) * (float)2.75);
/* SOURCE exnmat.for:5546 */
/*<       y2lim=y2lim+1. >*/
    y2lim += static_cast<double>((float)1.);
/* SOURCE exnmat.for:5548 */
/*<       e=(ag*a1)**2/(a1**2-alpha*ag**2) >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = static_cast<double>(ag) * a1;
/* Computing 2nd power */
    feq_gen_r_d_2 = a1;
/* Computing 2nd power */
    feq_gen_r_d_3 = ag;
    e = static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) / (static_cast<double>(static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2) - static_cast<double>(alpha) * (static_cast<double>(feq_gen_r_d_3) * feq_gen_r_d_3));
/* SOURCE exnmat.for:5550 */
/*<       a3=a0+w*y3 >*/
    a3 = static_cast<double>(a0) + static_cast<double>(w) * *y3;
/* SOURCE exnmat.for:5552 */
/*<       d=(ag*a3)/(a3-beta*ag) >*/
    feq_gen_d_d_ = static_cast<double>(static_cast<double>(ag) * a3) / (static_cast<double>(a3) - static_cast<double>(beta) * ag);
/* SOURCE exnmat.for:5554 */
/*<       dd=4.*e**2/(w*d)**2-(4.*e*y1)/(w*d)+y3**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = e;
/* Computing 2nd power */
    feq_gen_r_d_2 = static_cast<double>(w) * feq_gen_d_d_;
/* Computing 2nd power */
    feq_gen_r_d_3 = *y3;
    dd = static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * (float)4.) / (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) - static_cast<double>(static_cast<double>(static_cast<double>(e) * (float)4.) * *y1) / (static_cast<double>(w) * 
	    feq_gen_d_d_)) + static_cast<double>(feq_gen_r_d_3) * feq_gen_r_d_3;
/* SOURCE exnmat.for:5555 */
/*<       if(dd.lt.0.0)then >*/
    if (dd < (float)0.) {
/* SOURCE exnmat.for:5556 */
/*<       soy2=-1. >*/
	ret_val = (float)-1.;
/* SOURCE exnmat.for:5557 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:5558 */
/*<       y2=2.*e/(w*d)+sqrt(dd) >*/
	y2 = static_cast<double>(static_cast<double>(e) * (float)2.) / (static_cast<double>(w) * feq_gen_d_d_) + sqrt(dd);
/* SOURCE exnmat.for:5559 */
/*<       if(y2.gt.y2lim)then >*/
	if (y2 > y2lim) {
/* SOURCE exnmat.for:5560 */
/*<       soy2=y2 >*/
	    ret_val = y2;
/* SOURCE exnmat.for:5561 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:5562 */
/*<       soy2=-1.0 >*/
	    ret_val = (float)-1.;
/* SOURCE exnmat.for:5563 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:5564 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:5566 */
/*<       return >*/
    return ret_val;
/* SOURCE exnmat.for:5567 */
/*<       end >*/
} /* soy2_ */




/* SOURCE exnmat.for:5571 */
/*<       subroutinesw(h1,qfw,dqfw,h3,h3star,q,dqh1,dqh3) >*/
/* Subroutine */ int sw_(real *h1, real *qfw, real *dqfw, real *h3, real *
	h3star, real *q, real *dqh1, real *dqh3)
{
    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2;
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *);

    /* Local variables */
    real fac, subfac;

/*     + + + PURPOSE + + + */
/*     Find submerged weir flow given the free flow and its derivative */
/*     with respect to H1. */
/* SOURCE exnmat.for:5579 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:5581 */
/*<       realdqfw,dqh1,dqh3,h1,h3,h3star,q,qfw >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     H1     - upstream head */
/*     QFW    - free weir flow */
/*     DQFW   - derivative of flow wrt to head for free weir flow */
/*     H3     - head immediately below sluice gates */
/*     H3STAR - value of head immediately below sluice gates */
/*               at boundary of free orifice flow */
/*     Q      - flow rate */
/*     DQH1   - derivative of flow wrt to upstream head */
/*     DQH3   - derivative of flow wrt to downstream head */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE exnmat.for:5595 */
/*<       realfac,subfac >*/
/* *********************************************************************** */
/* SOURCE exnmat.for:5597 */
/*<       fac=(h3-h3star)/(h1-h3star) >*/
    fac = static_cast<double>((static_cast<double>(*h3) - *h3star)) / (static_cast<double>(*h1) - *h3star);
/* SOURCE exnmat.for:5598 */
/*<       subfac=1.-fac**1.5 >*/
    feq_gen_d_d_1 = (doublereal) fac;
    subfac = (float)1. - pow_dd(&feq_gen_d_d_1, &c_b337);
/* SOURCE exnmat.for:5600 */
/*<       q=qfw*subfac >*/
    *q = static_cast<double>(*qfw) * subfac;
/* SOURCE exnmat.for:5602 */
/*<       dqh1=dqfw*subfac+3.*qfw*h3/(h1**2-h1*h3star)*fac**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = *h1;
/* Computing 2nd power */
    feq_gen_r_d_2 = fac;
    *dqh1 = static_cast<double>(static_cast<double>(*dqfw) * subfac) + static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(*qfw) * (float)3.) * *h3) / (static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) - static_cast<double>(*h1) * *
	    h3star)) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2);
/* SOURCE exnmat.for:5604 */
/*<       dqh3=-3.*qfw*fac**2/(h1-h3star) >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = fac;
    *dqh3 = static_cast<double>(static_cast<double>(static_cast<double>(*qfw) * (float)-3.) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / (static_cast<double>(*h1) - *h3star);
/* SOURCE exnmat.for:5606 */
/*<       return >*/
    return 0;
/* SOURCE exnmat.for:5607 */
/*<       end >*/
} /* sw_ */




/* SOURCE exnmat.for:5611 */
/*<        >*/
/* Subroutine */ int twod14_(integer *ipnt, integer *stdout, doublereal *
	jtime, integer *nex, integer *ept, integer *feq_storage_emc, real *feq_storage_qe2, real *feq_storage_ye2,
	 real *feq_storage_ze, real *res, real *pyl, real *pql, real *pyr, real *pqr)
{
    /* System generated locals */
    static real equiv_0[1];

    /* Local variables */
    real q, ed, hd, hu, qt;
    integer dnn;
    real pdv;
    integer qnn, unn, free, ntab, fsgn;
#define idum (feq::BitView<integer>(equiv_0, sizeof(equiv_0)))
    integer ztab;
    real dhuq;
#define rdum (equiv_0)
    real hbase, dhued;
    integer dutab, udtab;
    real hutab, dqthu;
    extern /* Subroutine */ int tdlk14_(integer *, integer *, integer *, real 
	    *, real *, real *, real *, real *, real *, integer *);
    integer sysgn;
    extern /* Subroutine */ int lktstab_(integer *, doublereal *, real *, 
	    integer *, real *);

/*     + + + PURPOSE + + + */
/*     Compute flow for a 2-d table when the arguments */
/*     are downstream water level and the flow rate. */
/* SOURCE exnmat.for:5620 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:5622 */
/*<       integeripnt,stdout,ept,nex >*/
/* SOURCE exnmat.for:5623 */
/*<       integeremc(ept) >*/
/* SOURCE exnmat.for:5624 */
/*<       realpql,pqr,pyl,pyr,qe2(nex),res,ye2(nex),ze(nex) >*/
/* SOURCE exnmat.for:5625 */
/*<       real*8jtime >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IPNT   - pointer into EMC for description of control structure */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     TIME   - elapsed time in seconds from start of run */
/*     NEX    - number of exterior nodes in the model */
/*     EPT    - length of EMC(*) */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     QE2    - flow at exterior nodes at end of time step */
/*     YE2    - depths at exterior nodes at end of time step */
/*     ZE     - elevation of datum for depth at exterior node */
/*     RES    - value of the residual function */
/*     PYL    - partial derivative of residual function wrt depth at */
/*               left node */
/*     PQL    - partial derivative of residual function wrt flow at left */
/*               node */
/*     PYR    - partial derivative of residual function wrt depth at */
/*               right node */
/*     PQR    - partial derivative of residual function wrt flow at right */
/*               node */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE exnmat.for:5648 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE exnmat.for:5651 */
/*<       integerdnn,dutab,free,fsgn,idum,ntab,qnn,sysgn,udtab,unn,ztab >*/
/* SOURCE exnmat.for:5653 */
/*<       realdhued,dhuq,dqthu,ed,hbase,hd,hu,hutab,pdv,q,qt,rdum >*/
/* SOURCE exnmat.for:5656 */
/*<       character*5getusn,unn_char*5,dnn_char*5 >*/
/*      integer verbose */
/*      common/debug/ verbose */
/*     + + + EQUIVALENCES + + + */
/* SOURCE exnmat.for:5661 */
/*<       equivalence(idum,rdum) >*/
/*     + + + INTRINSICS + + + */
/* SOURCE exnmat.for:5664 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE exnmat.for:5667 */
/*<       externallktab,tdlk14 >*/
/* *********************************************************************** */
/*     GET KEY VALUES */
/* SOURCE exnmat.for:5671 */
/*<       unn=emc(ipnt+2) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> ze(feq_storage_ze, 1);

    feq::IndexedPointer<real> ye2(feq_storage_ye2, 1);

    feq::IndexedPointer<real> qe2(feq_storage_qe2, 1);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
    unn = emc[*ipnt + 2];
/* SOURCE exnmat.for:5672 */
/*<       dnn=emc(ipnt+3) >*/
    dnn = emc[*ipnt + 3];
/*     extract user node labels for debug output to appear later */
/*      unn_char = getusn(unn) */
/*      if(unn_char.eq.'F3998') then */
/*        dnn_char = getusn(dnn) */
/*        verbose = 1 */
/*      else */
/*        verbose = 0 */
/*      endif */
/*      if(verbose.eq.1) then */
/*        write(stdout,91) unn_char, dnn_char */
/* 91      format(/,' Debug type 14 table btwn: Ups Node=',A5, */
/*     a          ' and Dns Node=',A5) */
/*      endif */
/* SOURCE exnmat.for:5689 */
/*<       qnn=emc(ipnt+4) >*/
    qnn = emc[*ipnt + 4];
/* SOURCE exnmat.for:5690 */
/*<       sysgn=emc(ipnt+5) >*/
    sysgn = emc[*ipnt + 5];
/* SOURCE exnmat.for:5691 */
/*<       q=qe2(qnn) >*/
    q = qe2[qnn];
/* SOURCE exnmat.for:5692 */
/*<       if(q.lt.0.0)then >*/
    if (q < (float)0.) {
/* SOURCE exnmat.for:5693 */
/*<       fsgn=-sysgn >*/
	fsgn = -sysgn;
/* SOURCE exnmat.for:5694 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:5695 */
/*<       fsgn=sysgn >*/
	fsgn = sysgn;
/* SOURCE exnmat.for:5696 */
/*<       endif >*/
    }
/*      if(verbose.eq.1) then */
/*        WRITE(STDOUT,*) 'First: SYSGN=',SYSGN, ' FSGN=',FSGN */
/*      endif */
/*     GET TABLE ADDRESSES */
/* SOURCE exnmat.for:5703 */
/*<       udtab=emc(ipnt+7) >*/
    udtab = emc[*ipnt + 7];
/* SOURCE exnmat.for:5704 */
/*<       dutab=emc(ipnt+8) >*/
    dutab = emc[*ipnt + 8];
/* SOURCE exnmat.for:5705 */
/*<       ztab=emc(ipnt+10) >*/
    ztab = emc[*ipnt + 10];
/* SOURCE exnmat.for:5707 */
/*<       idum=emc(ipnt+11) >*/
    *idum = emc[*ipnt + 11];
/* SOURCE exnmat.for:5708 */
/*<       hbase=rdum >*/
    hbase = *rdum;
/*     ESTABLISH THE BASE ELEVATION FOR HEAD */
/* SOURCE exnmat.for:5711 */
/*<       if(ztab.gt.0)then >*/
    if (ztab > 0) {
/* SOURCE exnmat.for:5712 */
/*<       calllktstab(ztab,jtime,hbase,ntab,pdv) >*/
	lktstab_(&ztab, jtime, &hbase, &ntab, &pdv);
/* SOURCE exnmat.for:5715 */
/*<       endif >*/
    }
/*     TRAP THE SPECIAL CASE WHEN BOTH HEADS ARE LESS THAN ZERO.  THERE */
/*     IS NO FLOW AND THERE IS NO RELATIONSHIP BETWEEN THE HEADS NOR */
/*     BETWEEN HEAD AND FLOW. */
/* SOURCE exnmat.for:5721 */
/*<       hu=ye2(unn)+ze(unn)-hbase >*/
    hu = static_cast<double>(static_cast<double>(ye2[unn]) + ze[unn]) - hbase;
/* SOURCE exnmat.for:5722 */
/*<       hd=ye2(dnn)+ze(dnn)-hbase >*/
    hd = static_cast<double>(static_cast<double>(ye2[dnn]) + ze[dnn]) - hbase;
/*      if(verbose.eq.1) then */
/*        WRITE(STDOUT,*) ' TWOD14-from args: HU=', HU, ' HD=',HD,' Q=',Q */
/*      endif */
/* SOURCE exnmat.for:5728 */
/*<       if(hu.le.0.0.and.hd.le.0.0)then >*/
    if (hu <= (float)0. && hd <= (float)0.) {
/*       SPECIAL CASE.  FORCE FLOW AT FLOW NODE TO BE ZERO. */
/* SOURCE exnmat.for:5731 */
/*<       res=qe2(qnn) >*/
	*res = qe2[qnn];
/* SOURCE exnmat.for:5733 */
/*<       pyl=0.0 >*/
	*pyl = (float)0.;
/* SOURCE exnmat.for:5734 */
/*<       pyr=0.0 >*/
	*pyr = (float)0.;
/* SOURCE exnmat.for:5735 */
/*<       if(unn.eq.qnn)then >*/
	if (unn == qnn) {
/*         FLOW NODE AT NOMINAL UPSTREAM NODE */
/* SOURCE exnmat.for:5737 */
/*<       pqr=0.0 >*/
	    *pqr = (float)0.;
/* SOURCE exnmat.for:5738 */
/*<       pql=1.0 >*/
	    *pql = (float)1.;
/* SOURCE exnmat.for:5739 */
/*<       else >*/
	} else {
/*         FLOW NODE AT NOMINAL DOWNSTREAM NODE */
/* SOURCE exnmat.for:5741 */
/*<       pqr=1.0 >*/
	    *pqr = (float)1.;
/* SOURCE exnmat.for:5742 */
/*<       pql=0.0 >*/
	    *pql = (float)0.;
/* SOURCE exnmat.for:5743 */
/*<       endif >*/
	}
/*        if(verbose.eq.1) then */
/*          WRITE(STDOUT,*) ' TWOD14 SPECIAL CASE Q forced to 0: RES=',RES */
/*          WRITE(STDOUT,*) ' PYL=',PYL,' PQL=',PQL,' PYR=',PYR, */
/*     a                    ' PQR=',PQR */
/*        endif */
/* SOURCE exnmat.for:5749 */
/*<       return >*/
	return 0;
/* SOURCE exnmat.for:5750 */
/*<       endif >*/
    }
/*     We must check to make sure that Q not zero is consistent with the */
/*     heads.  Roundoff and convergence noise can result in a Q in a direction */
/*     contrary to the head pattern.  Here we will check for the physical */
/*     upstream head being positive before we accept the flow as valid. */
/*     There may be cases in which both heads are positive but the flow */
/*     is inconsistent with the head difference.  That case should be */
/*     handled properly below.  Typically the flows are quite small, */
/*     negligible in fact, that cause the problems detected in testing */
/*     so far.  We will see if this additional code solves the severe */
/*     convergence problems enountered when tables of type 14 operate */
/*     on flows that vary between zero and non-zero. */
/*     The FSGN gives the physical direction of flow.  If FSGN > 0 */
/*     then the flow is moving from the nominal upstream node */
/*     to the nominal dns node, no matter what those nodes are. */
/* SOURCE exnmat.for:5767 */
/*<       if(fsgn.gt.0)then >*/
    if (fsgn > 0) {
/*       flow from unn to dnn.  HU must be > 0 in this case. */
/* SOURCE exnmat.for:5769 */
/*<       if(hu.le.0.0)then >*/
	if (hu <= (float)0.) {
/*         force the flow to zero and set FSGN to SYSGN */
/* SOURCE exnmat.for:5771 */
/*<       q=0.0 >*/
	    q = (float)0.;
/* SOURCE exnmat.for:5772 */
/*<       qe2(qnn)=q >*/
	    qe2[qnn] = q;
/* SOURCE exnmat.for:5774 */
/*<       fsgn=sysgn >*/
	    fsgn = sysgn;
/*          if(verbose.eq.1) then */
/*            write(stdout,*) 'Q inconsistent with heads a. forced to 0.' */
/*          endif */
/* SOURCE exnmat.for:5778 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:5779 */
/*<       else >*/
    } else {
/*       flow from dnn  to unn.  HD must be > 0 in this case. */
/* SOURCE exnmat.for:5781 */
/*<       if(hd.le.0.0)then >*/
	if (hd <= (float)0.) {
/*         force flow to zero and set fsgn to sysgn */
/* SOURCE exnmat.for:5783 */
/*<       q=0.0 >*/
	    q = (float)0.;
/* SOURCE exnmat.for:5784 */
/*<       qe2(qnn)=q >*/
	    qe2[qnn] = q;
/* SOURCE exnmat.for:5785 */
/*<       fsgn=sysgn >*/
	    fsgn = sysgn;
/*          if(verbose.eq.1) then */
/*            write(stdout,*) 'Q inconsistent with heads b. forced to 0.' */
/*          endif */
/* SOURCE exnmat.for:5789 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:5790 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:5792 */
/*<       if(q.eq.0.0.and.hu.ne.hd)then >*/
    if (q == (float)0. && hu != hd) {
/*       SECOND SPECIAL CASE.  STANDARD LOOKUP DOES NOT WORK. */
/* SOURCE exnmat.for:5795 */
/*<       if(hu.gt.hd)then >*/
	if (hu > hd) {
/*         ASSUME FREE FLOW AT HU FROM NOMINAL UPSTREAM TO NOMINAL */
/*         DOWNSTREAM NODE. */
/* SOURCE exnmat.for:5799 */
/*<       hutab=hu >*/
	    hutab = hu;
/* SOURCE exnmat.for:5800 */
/*<       qt=0.0 >*/
	    qt = (float)0.;
/* SOURCE exnmat.for:5801 */
/*<       ed=ze(dnn)+ye2(dnn) >*/
	    ed = static_cast<double>(ze[dnn]) + ye2[dnn];
/* SOURCE exnmat.for:5802 */
/*<       calltdlk14(stdout,udtab,14,ed,hbase,qt,hutab,dqthu,dhuq,free) >*/
	    tdlk14_(stdout, &udtab, &feq_gen_c_d_14, &ed, &hbase, &qt, &hutab, &dqthu, 
		    &dhuq, &free);
/*         NOTE: ON RETURN QT IS THE FREE FLOW at HUTAB. */
/* SOURCE exnmat.for:5809 */
/*<       pyl=dhuq >*/
	    *pyl = dhuq;
/* SOURCE exnmat.for:5810 */
/*<       pyr=0.0 >*/
	    *pyr = (float)0.;
/* SOURCE exnmat.for:5811 */
/*<       if(qnn.eq.unn)then >*/
	    if (qnn == unn) {
/* SOURCE exnmat.for:5812 */
/*<       pql=-1.0 >*/
		*pql = (float)-1.;
/* SOURCE exnmat.for:5813 */
/*<       pqr=0.0 >*/
		*pqr = (float)0.;
/* SOURCE exnmat.for:5814 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:5815 */
/*<       pql=0.0 >*/
		*pql = (float)0.;
/* SOURCE exnmat.for:5816 */
/*<       pqr=-1.0 >*/
		*pqr = (float)-1.;
/* SOURCE exnmat.for:5817 */
/*<       endif >*/
	    }
/*         SET THE SIGN TO WHAT THE FLOW AT THE FLOW NODE SHOULD HAVE. */
/*         FOR FLOW FROM NOMINAL UP TO NOMINAL DOWN, THE FLOW AT THE */
/*         FLOW NODE HAS THE SAME SIGN AS SYSGN. */
/* SOURCE exnmat.for:5823 */
/*<       if(sysgn.lt.0)then >*/
	    if (sysgn < 0) {
/* SOURCE exnmat.for:5824 */
/*<       res=-qt >*/
		*res = -qt;
/* SOURCE exnmat.for:5825 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:5826 */
/*<       res=qt >*/
		*res = qt;
/* SOURCE exnmat.for:5827 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:5829 */
/*<       else >*/
	} else {
/*         ASSUME FREE FLOW AT HD FROM NOMINAL DOWNSTREAM TO NOMINAL */
/*         UPSTREAM */
/* SOURCE exnmat.for:5833 */
/*<       hutab=hd >*/
	    hutab = hd;
/* SOURCE exnmat.for:5834 */
/*<       qt=0.0 >*/
	    qt = (float)0.;
/* SOURCE exnmat.for:5835 */
/*<       ed=ze(unn)+ye2(unn) >*/
	    ed = static_cast<double>(ze[unn]) + ye2[unn];
/* SOURCE exnmat.for:5836 */
/*<       calltdlk14(stdout,dutab,14,ed,hbase,qt,hutab,dqthu,dhuq,free) >*/
	    tdlk14_(stdout, &dutab, &feq_gen_c_d_14, &ed, &hbase, &qt, &hutab, &dqthu, 
		    &dhuq, &free);
/* SOURCE exnmat.for:5841 */
/*<       pyr=dhuq >*/
	    *pyr = dhuq;
/* SOURCE exnmat.for:5842 */
/*<       pyl=0.0 >*/
	    *pyl = (float)0.;
/* SOURCE exnmat.for:5843 */
/*<       if(qnn.eq.unn)then >*/
	    if (qnn == unn) {
/* SOURCE exnmat.for:5844 */
/*<       pql=-1.0 >*/
		*pql = (float)-1.;
/* SOURCE exnmat.for:5845 */
/*<       pqr=0.0 >*/
		*pqr = (float)0.;
/* SOURCE exnmat.for:5846 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:5847 */
/*<       pql=0.0 >*/
		*pql = (float)0.;
/* SOURCE exnmat.for:5848 */
/*<       pqr=-1.0 >*/
		*pqr = (float)-1.;
/* SOURCE exnmat.for:5849 */
/*<       endif >*/
	    }
/*         SET THE SIGN THAT THE FLOW AT THE FLOW NODE SHOULD HAVE */
/*         HERE THE FLOW AT THE FLOW NODE SHOULD HAVE A SIGN OPPOSITE */
/*         FROM THE SYSGN */
/* SOURCE exnmat.for:5854 */
/*<       if(sysgn.gt.0)then >*/
	    if (sysgn > 0) {
/* SOURCE exnmat.for:5855 */
/*<       res=-qt >*/
		*res = -qt;
/* SOURCE exnmat.for:5856 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:5857 */
/*<       res=qt >*/
		*res = qt;
/* SOURCE exnmat.for:5858 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:5859 */
/*<       endif >*/
	}
/*        if(verbose.eq.1) then */
/*          write(stdout,*) ' Second special case: HU ne HD and Q=0' */
/*          write(stdout,*) ' QT=',qt,' PYL=',pyl,' PQL=',pql,' PYR=',pyr, */
/*     a                   ' PQR=',pqr */
/*          write(stdout,*) ' RES=',res */
/*        endif */
/* SOURCE exnmat.for:5867 */
/*<       return >*/
	return 0;
/* SOURCE exnmat.for:5868 */
/*<       endif >*/
    }
/*     THERE ARE FOUR DIFFERENT CASES IF AT LEAST ONE OF THE HEADS IS */
/*     POSITIVE AND THE FLOW IS NON-ZERO.  The flow argument is */
/*     not changed in TDLK14 in this case. */
/* SOURCE exnmat.for:5874 */
/*<       if(fsgn.gt.0)then >*/
    if (fsgn > 0) {
/*       FLOW FROM UNN -> DNN. */
/*       COMPUTE VALUE FROM THE TABLE */
/* SOURCE exnmat.for:5878 */
/*<       ed=ye2(dnn)+ze(dnn) >*/
	ed = static_cast<double>(ye2[dnn]) + ze[dnn];
/* SOURCE exnmat.for:5879 */
/*<       qt=abs(q) >*/
	qt = dabs(q);
/* SOURCE exnmat.for:5880 */
/*<       calltdlk14(stdout,udtab,14,ed,hbase,qt,hutab,dhued,dhuq,free) >*/
	tdlk14_(stdout, &udtab, &feq_gen_c_d_14, &ed, &hbase, &qt, &hutab, &dhued, &
		dhuq, &free);
/* SOURCE exnmat.for:5884 */
/*<       res=hutab-ye2(unn)-ze(unn)+hbase >*/
	*res = static_cast<double>(static_cast<double>(static_cast<double>(hutab) - ye2[unn]) - ze[unn]) + hbase;
/* SOURCE exnmat.for:5886 */
/*<       if(qnn.eq.unn)then >*/
	if (qnn == unn) {
/*         FLOW NODE AT PHYSICAL UPSTREAM LOCATION */
/* SOURCE exnmat.for:5889 */
/*<       pyl=-1.0 >*/
	    *pyl = (float)-1.;
/* SOURCE exnmat.for:5890 */
/*<       if(q.gt.0.0)then >*/
	    if (q > (float)0.) {
/* SOURCE exnmat.for:5891 */
/*<       pql=dhuq >*/
		*pql = dhuq;
/* SOURCE exnmat.for:5892 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:5893 */
/*<       pql=-dhuq >*/
		*pql = -dhuq;
/* SOURCE exnmat.for:5894 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:5895 */
/*<       pyr=dhued >*/
	    *pyr = dhued;
/* SOURCE exnmat.for:5896 */
/*<       pqr=0.0 >*/
	    *pqr = (float)0.;
/* SOURCE exnmat.for:5897 */
/*<       else >*/
	} else {
/*         FLOW NODE AT PHYSICAL DOWNSTREAM LOCATION */
/* SOURCE exnmat.for:5900 */
/*<       pyl=-1.0 >*/
	    *pyl = (float)-1.;
/* SOURCE exnmat.for:5901 */
/*<       pql=0.0 >*/
	    *pql = (float)0.;
/* SOURCE exnmat.for:5902 */
/*<       pyr=dhued >*/
	    *pyr = dhued;
/* SOURCE exnmat.for:5903 */
/*<       if(q.gt.0.0)then >*/
	    if (q > (float)0.) {
/* SOURCE exnmat.for:5904 */
/*<       pqr=dhuq >*/
		*pqr = dhuq;
/* SOURCE exnmat.for:5905 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:5906 */
/*<       pqr=-dhuq >*/
		*pqr = -dhuq;
/* SOURCE exnmat.for:5907 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:5908 */
/*<       endif >*/
	}
/*        if(verbose.eq.1) then */
/*          write(stdout,*) 'unn->dnn',' Q=',Q,' RES=',RES */
/*          write(stdout,*) ' PYL=',pyl,' PQL=',pql,' PYR=',pyr, */
/*     a                   ' PQL=',pql */
/*        endif */
/* SOURCE exnmat.for:5914 */
/*<       else >*/
    } else {
/*       FLOW FROM DNN -> UNN. */
/* SOURCE exnmat.for:5917 */
/*<       ed=ye2(unn)+ze(unn) >*/
	ed = static_cast<double>(ye2[unn]) + ze[unn];
/* SOURCE exnmat.for:5918 */
/*<       qt=abs(q) >*/
	qt = dabs(q);
/* SOURCE exnmat.for:5919 */
/*<       calltdlk14(stdout,dutab,14,ed,hbase,qt,hutab,dhued,dhuq,free) >*/
	tdlk14_(stdout, &dutab, &feq_gen_c_d_14, &ed, &hbase, &qt, &hutab, &dhued, &
		dhuq, &free);
/* SOURCE exnmat.for:5923 */
/*<       res=hutab-ye2(dnn)-ze(dnn)+hbase >*/
	*res = static_cast<double>(static_cast<double>(static_cast<double>(hutab) - ye2[dnn]) - ze[dnn]) + hbase;
/* SOURCE exnmat.for:5925 */
/*<       if(qnn.eq.unn)then >*/
	if (qnn == unn) {
/* SOURCE exnmat.for:5927 */
/*<       pyl=dhued >*/
	    *pyl = dhued;
/* SOURCE exnmat.for:5928 */
/*<       if(q.gt.0.0)then >*/
	    if (q > (float)0.) {
/* SOURCE exnmat.for:5929 */
/*<       pql=dhuq >*/
		*pql = dhuq;
/* SOURCE exnmat.for:5930 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:5931 */
/*<       pql=-dhuq >*/
		*pql = -dhuq;
/* SOURCE exnmat.for:5932 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:5933 */
/*<       pyr=-1.0 >*/
	    *pyr = (float)-1.;
/* SOURCE exnmat.for:5934 */
/*<       pqr=0.0 >*/
	    *pqr = (float)0.;
/* SOURCE exnmat.for:5935 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:5937 */
/*<       pyl=dhued >*/
	    *pyl = dhued;
/* SOURCE exnmat.for:5938 */
/*<       pql=0.0 >*/
	    *pql = (float)0.;
/* SOURCE exnmat.for:5939 */
/*<       pyr=-1.0 >*/
	    *pyr = (float)-1.;
/* SOURCE exnmat.for:5940 */
/*<       if(q.gt.0.0)then >*/
	    if (q > (float)0.) {
/* SOURCE exnmat.for:5941 */
/*<       pqr=dhuq >*/
		*pqr = dhuq;
/* SOURCE exnmat.for:5942 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:5943 */
/*<       pqr=-dhuq >*/
		*pqr = -dhuq;
/* SOURCE exnmat.for:5944 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:5945 */
/*<       endif >*/
	}
/*        if(verbose.eq.1) then */
/*          write(stdout,*) 'dnn->unn',' Q=',Q,' RES=',RES */
/*          write(stdout,*) ' PYL=',pyl,' PQL=',pql,' PYR=',pyr, */
/*     a                   ' PQL=',pql */
/*        endif */
/* SOURCE exnmat.for:5951 */
/*<       endif >*/
    }
/*      if(verbose.eq.1) then */
/*        WRITE(STDOUT,*) ' TWOD14: RES=',RES,' HUTAB=',HUTAB, 'Q=',Q */
/*        WRITE(STDOUT,*) ' PYL=',PYL,' PQL=',PQL,' PYR=',PYR,' PQR=',PQR */
/*      endif */
/* SOURCE exnmat.for:5958 */
/*<       return >*/
    return 0;
/* SOURCE exnmat.for:5959 */
/*<       end >*/
} /* twod14_ */

#undef rdum
#undef idum





/* SOURCE exnmat.for:5963 */
/*<        >*/
/* Subroutine */ int twod6_(integer *ipnt, integer *stdout, doublereal *jtime,
	 integer *nex, integer *ept, integer *feq_storage_emc, real *feq_storage_qe2, real *feq_storage_ye2, real 
	*feq_storage_ze, real *res, real *pyl, real *pql, real *pyr, real *pqr)
{
    /* System generated locals */
    integer feq_gen_i_d_1, feq_gen_i_d_2;
    static real equiv_0[1];

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_;
    real q, el, er, yl, yr;
    integer dnn;
    real pdv;
    integer qnn, unn;
    real dqed;
    integer free, ioff, ntab;
#define idum (feq::BitView<integer>(equiv_0, sizeof(equiv_0)))
    real dqeu;
    integer ztab;
#define rdum (equiv_0)
    integer feq_gen_type_d_;
    extern /* Subroutine */ int tdlk6_(integer *, integer *, integer *, 
	    integer *, doublereal *, real *, real *, real *, real *, real *, 
	    real *, integer *);
    real hbase;
    integer mftab, dutab, udtab;
    extern /* Subroutine */ int tdlk13_(integer *, integer *, integer *, 
	    integer *, doublereal *, real *, real *, real *, real *, real *, 
	    real *, integer *), tdlk43_(integer *, integer *, integer *, 
	    integer *, doublereal *, real *, real *, real *, real *, real *, 
	    real *, integer *);
    integer sysgn, ispout;
    extern integer gettyp_(integer *);
    real feq_gen_cap_fac_d_;
    extern /* Subroutine */ int lktstab_(integer *, doublereal *, real *, 
	    integer *, real *);

/*     + + + PURPOSE + + + */
/*     Compute flow for a 2-D table when the arguments */
/*     to the table are elevation. */
/* SOURCE exnmat.for:5972 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:5974 */
/*<       integeripnt,stdout,ept,nex >*/
/* SOURCE exnmat.for:5975 */
/*<       integeremc(ept) >*/
/* SOURCE exnmat.for:5976 */
/*<       realpql,pqr,pyl,pyr,qe2(nex),res,ye2(nex),ze(nex) >*/
/* SOURCE exnmat.for:5977 */
/*<       real*8jtime >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IPNT   - pointer into EMC for description of control structure */
/*     STDOUT   - Fortran unit number for user output and messages */
/*     TIME   - elapsed time in seconds from start of run */
/*     NEX    - number of exterior nodes in the model */
/*     EPT    - length of EMC(*) */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     QE2    - flow at exterior nodes at end of time step */
/*     YE2    - depths at exterior nodes at end of time step */
/*     ZE     - elevation of datum for depth at exterior node */
/*     RES    - value of the residual function */
/*     PYL    - partial derivative of residual function wrt depth at */
/*               left node */
/*     PQL    - partial derivative of residual function wrt flow at left */
/*               node */
/*     PYR    - partial derivative of residual function wrt depth at */
/*               right node */
/*     PQR    - partial derivative of residual function wrt flow at right */
/*               node */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE exnmat.for:6000 */
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
/* INCLUDE exnmat.for:6001 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE exnmat.for:6004 */
/*<        >*/
/* SOURCE exnmat.for:6006 */
/*<       realdqed,dqeu,el,er,hbase,pdv,q,rdum,yl,yr,cap_fac >*/
/*     + + + EQUIVALENCES + + + */
/* SOURCE exnmat.for:6009 */
/*<       equivalence(idum,rdum) >*/
/*     + + + INTRINSICS + + + */
/* SOURCE exnmat.for:6012 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE exnmat.for:6015 */
/*<       integergettyp >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE exnmat.for:6018 */
/*<       externalgettyp,lktab,tdlk13,tdlk6,tdlk43 >*/
/* *********************************************************************** */
/*     GET KEY VALUES */
/* SOURCE exnmat.for:6022 */
/*<       unn=emc(ipnt+2) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> ze(feq_storage_ze, 1);

    feq::IndexedPointer<real> ye2(feq_storage_ye2, 1);

    feq::IndexedPointer<real> qe2(feq_storage_qe2, 1);

    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    /* Function Body */
    unn = emc[*ipnt + 2];
/* SOURCE exnmat.for:6023 */
/*<       dnn=emc(ipnt+3) >*/
    dnn = emc[*ipnt + 3];
/* SOURCE exnmat.for:6024 */
/*<       qnn=emc(ipnt+4) >*/
    qnn = emc[*ipnt + 4];
/* SOURCE exnmat.for:6025 */
/*<       sysgn=emc(ipnt+5) >*/
    sysgn = emc[*ipnt + 5];
/* SOURCE exnmat.for:6027 */
/*<       yl=ye2(unn) >*/
    yl = ye2[unn];
/* SOURCE exnmat.for:6028 */
/*<       yr=ye2(dnn) >*/
    yr = ye2[dnn];
/* SOURCE exnmat.for:6029 */
/*<       el=yl+ze(unn) >*/
    el = static_cast<double>(yl) + ze[unn];
/* SOURCE exnmat.for:6030 */
/*<       er=yr+ze(dnn) >*/
    er = static_cast<double>(yr) + ze[dnn];
/*     SET THE DERIVATIVE WRT FLOW. */
/* SOURCE exnmat.for:6034 */
/*<       if(qnn.eq.unn)then >*/
    if (qnn == unn) {
/* SOURCE exnmat.for:6035 */
/*<       pql=1.0 >*/
	*pql = (float)1.;
/* SOURCE exnmat.for:6036 */
/*<       pqr=0.0 >*/
	*pqr = (float)0.;
/* SOURCE exnmat.for:6037 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:6038 */
/*<       pql=0.0 >*/
	*pql = (float)0.;
/* SOURCE exnmat.for:6039 */
/*<       pqr=1.0 >*/
	*pqr = (float)1.;
/* SOURCE exnmat.for:6040 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:6042 */
/*<       ioff=0 >*/
    ioff = 0;
/* SOURCE exnmat.for:6043 */
/*<       res=0.0 >*/
    *res = (float)0.;
/* SOURCE exnmat.for:6044 */
/*<       pyl=0.0 >*/
    *pyl = (float)0.;
/* SOURCE exnmat.for:6045 */
/*<       pyr=0.0 >*/
    *pyr = (float)0.;
/* SOURCE exnmat.for:6046 */
/*<       do1000i=1,abs(emc(ipnt+6)) >*/
    feq_gen_i_d_2 = (feq_gen_i_d_1 = emc[*ipnt + 6], abs(feq_gen_i_d_1));
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_2; ++feq_gen_i_d_) {
/* SOURCE exnmat.for:6047 */
/*<       udtab=emc(ipnt+ioff+7) >*/
	udtab = emc[*ipnt + ioff + 7];
/* SOURCE exnmat.for:6048 */
/*<       dutab=emc(ipnt+ioff+8) >*/
	dutab = emc[*ipnt + ioff + 8];
/* SOURCE exnmat.for:6049 */
/*<       mftab=emc(ipnt+ioff+9) >*/
	mftab = emc[*ipnt + ioff + 9];
/* SOURCE exnmat.for:6050 */
/*<       ztab=emc(ipnt+ioff+10) >*/
	ztab = emc[*ipnt + ioff + 10];
/* SOURCE exnmat.for:6052 */
/*<       idum=emc(ipnt+ioff+11) >*/
	*idum = emc[*ipnt + ioff + 11];
/* SOURCE exnmat.for:6053 */
/*<       hbase=rdum >*/
	hbase = *rdum;
/*        write(stdout,*) ' In TWOD6: HBASE=',HBASE,' IDUM=',IDUM, */
/*     a                  ' ipnt+ioff+11=',ipnt+ioff+11 */
/* SOURCE exnmat.for:6056 */
/*<       ispout=emc(ipnt+ioff+12) >*/
	ispout = emc[*ipnt + ioff + 12];
/*       ESTABLISH THE BASE ELEVATION FOR HEAD */
/* SOURCE exnmat.for:6060 */
/*<       if(ztab.gt.0)then >*/
	if (ztab > 0) {
/* SOURCE exnmat.for:6061 */
/*<       calllktstab(ztab,jtime,hbase,ntab,pdv) >*/
	    lktstab_(&ztab, jtime, &hbase, &ntab, &pdv);
/* SOURCE exnmat.for:6064 */
/*<       endif >*/
	}
/*       Process possible capacity factors */
/* SOURCE exnmat.for:6067 */
/*<       if(mftab>0)then >*/
	if (mftab > 0) {
/*         this structure is controled by an operation block */
/* SOURCE exnmat.for:6069 */
/*<       idum=emc(ipnt+ioff+13) >*/
	    *idum = emc[*ipnt + ioff + 13];
/* SOURCE exnmat.for:6070 */
/*<       cap_fac=rdum >*/
	    feq_gen_cap_fac_d_ = *rdum;
/* SOURCE exnmat.for:6071 */
/*<       gopen(ispout)=cap_fac >*/
	    gate1_1.gopen[ispout] = feq_gen_cap_fac_d_;
/* SOURCE exnmat.for:6072 */
/*<       if(cap_fac==1.0)then >*/
	    if (feq_gen_cap_fac_d_ == (float)1.) {
/* SOURCE exnmat.for:6073 */
/*<       fclass(ispout)='  FllOpn' >*/
		s_copy(gate2_1.fclass + (ispout << 3), const_cast<char*>("  FllOpn"), (ftnlen)8, 
			(ftnlen)8);
/* SOURCE exnmat.for:6074 */
/*<       fclass_code(ispout)=13 >*/
		gate1_1.feq_gen_fclass_code_d_[ispout] = 13;
/* SOURCE exnmat.for:6075 */
/*<       elseif(cap_fac==0.0)then >*/
	    } else if (feq_gen_cap_fac_d_ == (float)0.) {
/* SOURCE exnmat.for:6076 */
/*<       fclass(ispout)='  Closed' >*/
		s_copy(gate2_1.fclass + (ispout << 3), const_cast<char*>("  Closed"), (ftnlen)8, 
			(ftnlen)8);
/* SOURCE exnmat.for:6077 */
/*<       fclass_code(ispout)=14 >*/
		gate1_1.feq_gen_fclass_code_d_[ispout] = 14;
/* SOURCE exnmat.for:6078 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:6079 */
/*<       fclass(ispout)='  PrtOpn' >*/
		s_copy(gate2_1.fclass + (ispout << 3), const_cast<char*>("  PrtOpn"), (ftnlen)8, 
			(ftnlen)8);
/* SOURCE exnmat.for:6080 */
/*<       fclass_code(ispout)=15 >*/
		gate1_1.feq_gen_fclass_code_d_[ispout] = 15;
/* SOURCE exnmat.for:6081 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:6082 */
/*<       elseif(mftab<0)then >*/
	} else if (mftab < 0) {
/*         Capacity factor given in a time series table. */
/* SOURCE exnmat.for:6084 */
/*<       calllktstab(-mftab,jtime,cap_fac,ntab,pdv) >*/
	    feq_gen_i_d_1 = -mftab;
	    lktstab_(&feq_gen_i_d_1, jtime, &feq_gen_cap_fac_d_, &ntab, &pdv);
/* SOURCE exnmat.for:6087 */
/*<       gopen(ispout)=cap_fac >*/
	    gate1_1.gopen[ispout] = feq_gen_cap_fac_d_;
/* SOURCE exnmat.for:6088 */
/*<       fclass(ispout)='   FrmTS' >*/
	    s_copy(gate2_1.fclass + (ispout << 3), const_cast<char*>("   FrmTS"), (ftnlen)8, (
		    ftnlen)8);
/* SOURCE exnmat.for:6089 */
/*<       fclass_code(ispout)=16 >*/
	    gate1_1.feq_gen_fclass_code_d_[ispout] = 16;
/* SOURCE exnmat.for:6091 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:6092 */
/*<       cap_fac=1.0 >*/
	    feq_gen_cap_fac_d_ = (float)1.;
/* SOURCE exnmat.for:6093 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:6095 */
/*<       ioff=ioff+cd5ty6 >*/
	ioff += 8;
/*       BASE FLOW DIRECTION ON WATER SURFACE ELEVATION FOR NOW. */
/*       EXTEND LATER IF NEEDED */
/* SOURCE exnmat.for:6100 */
/*<       if(el.ge.er)then >*/
	if (el >= er) {
/*         FLOW FROM NOMINAL UPSTREAM NODE TO DOWNSTREAM NODE */
/* SOURCE exnmat.for:6103 */
/*<       type=gettyp(udtab) >*/
	    feq_gen_type_d_ = gettyp_(&udtab);
/* SOURCE exnmat.for:6104 */
/*<       if(type.eq.43)then >*/
	    if (feq_gen_type_d_ == 43) {
/* SOURCE exnmat.for:6105 */
/*<        >*/
		tdlk43_(stdout, &udtab, &feq_gen_c_d_43, &mftab, jtime, &er, &el, &
			hbase, &q, &dqed, &dqeu, &free);
/*      write(stdout,9143) er, el, Q, DQED, DQEU, FREE */
/* 9143  format(' tdlk43 on return: EDA=',f10.3,' EUA=',f10.3,' Q=',f10.3, */
/*     a       ' DQED=',f10.3,'DQEU=',f10.3,' FREE=',i5) */
/* SOURCE exnmat.for:6112 */
/*<       elseif(type.eq.13)then >*/
	    } else if (feq_gen_type_d_ == 13) {
/* SOURCE exnmat.for:6113 */
/*<        >*/
		tdlk13_(stdout, &udtab, &feq_gen_c_d_13, &mftab, jtime, &er, &el, &
			hbase, &q, &dqed, &dqeu, &free);
/* SOURCE exnmat.for:6116 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:6117 */
/*<       calltdlk6(stdout,udtab,6,mftab,jtime,er,el,hbase,q,dqed,dqeu,free) >*/
		tdlk6_(stdout, &udtab, &feq_gen_c_d_6, &mftab, jtime, &er, &el, &hbase,
			 &q, &dqed, &dqeu, &free);
/* SOURCE exnmat.for:6120 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:6122 */
/*<       if(cap_fac.ne.1.0)then >*/
	    if (feq_gen_cap_fac_d_ != (float)1.) {
/* SOURCE exnmat.for:6123 */
/*<       q=cap_fac*q >*/
		q = static_cast<double>(feq_gen_cap_fac_d_) * q;
/* SOURCE exnmat.for:6124 */
/*<       dqeu=cap_fac*dqeu >*/
		dqeu = static_cast<double>(feq_gen_cap_fac_d_) * dqeu;
/* SOURCE exnmat.for:6125 */
/*<       dqed=cap_fac*dqed >*/
		dqed = static_cast<double>(feq_gen_cap_fac_d_) * dqed;
/* SOURCE exnmat.for:6126 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:6127 */
/*<       if(sysgn.gt.0)then >*/
	    if (sysgn > 0) {
/* SOURCE exnmat.for:6128 */
/*<       res=res-q >*/
		*res -= q;
/* SOURCE exnmat.for:6129 */
/*<       pyl=pyl-dqeu >*/
		*pyl -= dqeu;
/* SOURCE exnmat.for:6130 */
/*<       pyr=pyr-dqed >*/
		*pyr -= dqed;
/* SOURCE exnmat.for:6131 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:6132 */
/*<       res=res+q >*/
		*res += q;
/* SOURCE exnmat.for:6133 */
/*<       pyl=pyl+dqeu >*/
		*pyl += dqeu;
/* SOURCE exnmat.for:6134 */
/*<       pyr=pyr+dqed >*/
		*pyr += dqed;
/* SOURCE exnmat.for:6135 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:6136 */
/*<       else >*/
	} else {
/*         FLOW FROM NOMINAL DOWNSTREAM NODE TO UPSTREAM NODE */
/* SOURCE exnmat.for:6138 */
/*<       type=gettyp(dutab) >*/
	    feq_gen_type_d_ = gettyp_(&dutab);
/* SOURCE exnmat.for:6139 */
/*<       if(type.eq.43)then >*/
	    if (feq_gen_type_d_ == 43) {
/* SOURCE exnmat.for:6140 */
/*<        >*/
		tdlk43_(stdout, &dutab, &feq_gen_c_d_43, &mftab, jtime, &el, &er, &
			hbase, &q, &dqed, &dqeu, &free);
/*      write(stdout,9143) er, el, Q, DQED, DQEU, FREE */
/* SOURCE exnmat.for:6144 */
/*<       elseif(type.eq.13)then >*/
	    } else if (feq_gen_type_d_ == 13) {
/* SOURCE exnmat.for:6145 */
/*<        >*/
		tdlk13_(stdout, &dutab, &feq_gen_c_d_13, &mftab, jtime, &el, &er, &
			hbase, &q, &dqed, &dqeu, &free);
/* SOURCE exnmat.for:6148 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:6149 */
/*<       calltdlk6(stdout,dutab,6,mftab,jtime,el,er,hbase,q,dqed,dqeu,free) >*/
		tdlk6_(stdout, &dutab, &feq_gen_c_d_6, &mftab, jtime, &el, &er, &hbase,
			 &q, &dqed, &dqeu, &free);
/* SOURCE exnmat.for:6152 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:6153 */
/*<       if(cap_fac.ne.1.0)then >*/
	    if (feq_gen_cap_fac_d_ != (float)1.) {
/* SOURCE exnmat.for:6154 */
/*<       q=cap_fac*q >*/
		q = static_cast<double>(feq_gen_cap_fac_d_) * q;
/* SOURCE exnmat.for:6155 */
/*<       dqeu=cap_fac*dqeu >*/
		dqeu = static_cast<double>(feq_gen_cap_fac_d_) * dqeu;
/* SOURCE exnmat.for:6156 */
/*<       dqed=cap_fac*dqed >*/
		dqed = static_cast<double>(feq_gen_cap_fac_d_) * dqed;
/* SOURCE exnmat.for:6157 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:6158 */
/*<       if(sysgn.gt.0)then >*/
	    if (sysgn > 0) {
/* SOURCE exnmat.for:6159 */
/*<       res=res+q >*/
		*res += q;
/* SOURCE exnmat.for:6160 */
/*<       pyl=pyl+dqed >*/
		*pyl += dqed;
/* SOURCE exnmat.for:6161 */
/*<       pyr=pyr+dqeu >*/
		*pyr += dqeu;
/* SOURCE exnmat.for:6162 */
/*<       else >*/
	    } else {
/* SOURCE exnmat.for:6163 */
/*<       res=res-q >*/
		*res -= q;
/* SOURCE exnmat.for:6164 */
/*<       pyl=pyl-dqed >*/
		*pyl -= dqed;
/* SOURCE exnmat.for:6165 */
/*<       pyr=pyr-dqeu >*/
		*pyr -= dqeu;
/* SOURCE exnmat.for:6166 */
/*<       endif >*/
	    }
/* SOURCE exnmat.for:6167 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:6169 */
/*<  1000 continue >*/
/* L1000: */
    }
/* SOURCE exnmat.for:6171 */
/*<       res=res+qe2(qnn) >*/
    *res += static_cast<double>(qe2[qnn]);
/* SOURCE exnmat.for:6173 */
/*<       return >*/
    return 0;
/* SOURCE exnmat.for:6174 */
/*<       end >*/
} /* twod6_ */

#undef rdum
#undef idum





/* SOURCE exnmat.for:6178 */
/*<        >*/
/* Subroutine */ int ufgate_(integer *ipnt, integer *feq_storage_emc, integer *mlemc, 
	real *feq_storage_ye2, real *feq_storage_ze, real *feq_storage_qe2, integer *nex, integer *stdout, 
	doublereal *jtime, real *feq_storage_qe1, real *res, real *pyl, real *pql, real *
	pyr, real *pqr)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:64* Table Id=\002,a,\002 has invali\
d values for\002,\002 structure setting.\002)";
    static char fmt_52[] = "(\002 Gate opening in ufgate=\002,f8.2,\002 Max.\
 opening=\002,f8.2)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[16];
    static real equiv_0[1];

    /* Builtin functions */
    integer s_wsfe(cilist *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    real q;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    integer feq_gen_gate_factor_table_d_;
    real hg, el, er, yl, yr;
    integer feq_gen_ftype_code_d_, dnn;
    real pdv;
    integer qnn, unn;
    real feq_gen_gate_factor_d_, dqed;
    integer ntab;
#define idum (feq::BitView<integer>(equiv_0, sizeof(equiv_0)))
    real dqeu;
#define rdum (equiv_0)
    real hbase;
    integer mftab, dutab, udtab;
    real dtime, newhg;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);
    char ftype[8];
    extern /* Subroutine */ int tdlk15_(integer *, integer *, integer *, 
	    doublereal *, real *, real *, real *, real *, real *, real *, 
	    real *, real *, char *, integer *, ftnlen);
    integer sysgn, opcode;
    real maxgat;
    integer ispout;
    extern /* Subroutine */ int lktstab_(integer *, doublereal *, real *, 
	    integer *, real *);
    integer feq_gen_gate_factor_exn_d_;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__730 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__731 = { 0, 0, 0, fmt_52, 0 };


/*     + + + PURPOSE + + + */
/*     Underflow gate. */
/* SOURCE exnmat.for:6186 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE exnmat.for:6188 */
/*<       integeripnt,mlemc,nex,stdout >*/
/* SOURCE exnmat.for:6189 */
/*<       integeremc(mlemc) >*/
/* SOURCE exnmat.for:6190 */
/*<       realpql,pqr,pyl,pyr,qe2(nex),qe1(nex),res,ye2(nex),ze(nex) >*/
/* SOURCE exnmat.for:6192 */
/*<       real*8jtime >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     IPNT   - pointer into EMC for description of control structure */
/*     EMC    - vector containing coded form of the Matrix Control Input */
/*     MLEMC  - maximum length of EMC(*) */
/*     YE2    - depths at exterior nodes at end of time step */
/*     ZE     - elevation of datum for depth at exterior node */
/*     QE2    - flow at exterior nodes at end of time step */
/*     NEX    - number of exterior nodes in the model */
/*     STDOUT - standard output unit for user messages */
/*     TIME   - elapsed time in seconds from start of run */
/*     QE1    - flow at exterior nodes at start of time step. */
/*     RES    - value of the residual function */
/*     PYL    - partial derivative of residual function wrt depth at */
/*               left node */
/*     PQL    - partial derivative of residual function wrt flow at left */
/*               node */
/*     PYR    - partial derivative of residual function wrt depth at */
/*               right node */
/*     PQR    - partial derivative of residual function wrt flow at right */
/*               node */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE exnmat.for:6216 */
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
/* INCLUDE exnmat.for:6217 */
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
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE exnmat.for:6220 */
/*<        >*/
/* SOURCE exnmat.for:6223 */
/*<        >*/
/* SOURCE exnmat.for:6225 */
/*<       characterftype*8 >*/
/*     + + + EQUIVALENCES + + + */
/* SOURCE exnmat.for:6228 */
/*<       equivalence(idum,rdum) >*/
/*     + + + INTRINSICS + + + */
/* SOURCE exnmat.for:6231 */
/*<       intrinsicabs >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE exnmat.for:6234 */
/*<       characterget_tabid*16 >*/
/* SOURCE exnmat.for:6235 */
/*<       externallktab,tdlk15,get_tabid >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE exnmat.for:6238 */
/*<    50  >*/
/* SOURCE exnmat.for:6240 */
/*<    52 format(' Gate opening in ufgate=',f8.2,' Max. opening=',f8.2) >*/
/* *********************************************************************** */
/*     OBTAIN BASIC INFORMATION FROM EMC */
/* SOURCE exnmat.for:6244 */
/*<       unn=emc(ipnt+2) >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> emc(feq_storage_emc, 1);

    feq::IndexedPointer<real> qe1(feq_storage_qe1, 1);

    feq::IndexedPointer<real> qe2(feq_storage_qe2, 1);

    feq::IndexedPointer<real> ze(feq_storage_ze, 1);

    feq::IndexedPointer<real> ye2(feq_storage_ye2, 1);

    /* Function Body */
/* L50: */
/* L52: */
    unn = emc[*ipnt + 2];
/* SOURCE exnmat.for:6245 */
/*<       dnn=emc(ipnt+3) >*/
    dnn = emc[*ipnt + 3];
/* SOURCE exnmat.for:6246 */
/*<       qnn=emc(ipnt+4) >*/
    qnn = emc[*ipnt + 4];
/* SOURCE exnmat.for:6247 */
/*<       sysgn=emc(ipnt+5) >*/
    sysgn = emc[*ipnt + 5];
/* SOURCE exnmat.for:6248 */
/*<       opcode=emc(ipnt+6) >*/
    opcode = emc[*ipnt + 6];
/* SOURCE exnmat.for:6249 */
/*<       udtab=emc(ipnt+8) >*/
    udtab = emc[*ipnt + 8];
/* SOURCE exnmat.for:6250 */
/*<       dutab=emc(ipnt+9) >*/
    dutab = emc[*ipnt + 9];
/*     ISPOUT is the pointer into the vectors used to allow output */
/*     of the gate opening and the flow class to the special output file. */
/* SOURCE exnmat.for:6253 */
/*<       ispout=emc(ipnt+10) >*/
    ispout = emc[*ipnt + 10];
/* SOURCE exnmat.for:6254 */
/*<       idum=emc(ipnt+11) >*/
    *idum = emc[*ipnt + 11];
/* SOURCE exnmat.for:6255 */
/*<       hbase=rdum >*/
    hbase = *rdum;
/* SOURCE exnmat.for:6256 */
/*<       idum=emc(ipnt+12) >*/
    *idum = emc[*ipnt + 12];
/* SOURCE exnmat.for:6257 */
/*<       maxgat=rdum >*/
    maxgat = *rdum;
/* SOURCE exnmat.for:6258 */
/*<       mftab=0 >*/
    mftab = 0;
/* SOURCE exnmat.for:6259 */
/*<       gate_factor_table=emc(ipnt+15) >*/
    feq_gen_gate_factor_table_d_ = emc[*ipnt + 15];
/* SOURCE exnmat.for:6261 */
/*<       if(gate_factor_table.gt.0)then >*/
    if (feq_gen_gate_factor_table_d_ > 0) {
/*       Lookup the factor. */
/* SOURCE exnmat.for:6263 */
/*<       gate_factor_exn=emc(ipnt+16) >*/
	feq_gen_gate_factor_exn_d_ = emc[*ipnt + 16];
/* SOURCE exnmat.for:6264 */
/*<        >*/
	lktab_(&feq_gen_gate_factor_table_d_, &qe1[feq_gen_gate_factor_exn_d_], &feq_gen_c_d_0, &
		feq_gen_gate_factor_d_, &ntab, &pdv);
/* SOURCE exnmat.for:6267 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:6268 */
/*<       gate_factor=1.0 >*/
	feq_gen_gate_factor_d_ = (float)1.;
/* SOURCE exnmat.for:6269 */
/*<       endif >*/
    }
/*     DEFINE THE GATE OPENING FOR THIS TIME STEP */
/* SOURCE exnmat.for:6273 */
/*<       if(opcode.gt.0)then >*/
    if (opcode > 0) {
/*       OPERATION BLOCK HAS ALREADY SET THE OPENING FRACTION */
/* SOURCE exnmat.for:6276 */
/*<       idum=emc(ipnt+13) >*/
	*idum = emc[*ipnt + 13];
/* SOURCE exnmat.for:6277 */
/*<       hg=maxgat*rdum >*/
	hg = static_cast<double>(maxgat) * *rdum;
/* SOURCE exnmat.for:6278 */
/*<       else >*/
    } else {
/*       LOOK UP VALUE IN TABLE BASED ON TIME AT START OF THE CURRENT */
/*       STEP */
/* SOURCE exnmat.for:6282 */
/*<       calllktstab(abs(opcode),jtime,hg,ntab,dtime) >*/
	feq_gen_i_d_1 = abs(opcode);
	lktstab_(&feq_gen_i_d_1, jtime, &hg, &ntab, &dtime);
/* SOURCE exnmat.for:6285 */
/*<       if(hg.lt.0.0.or.hg.gt.maxgat)then >*/
	if (hg < (float)0. || hg > maxgat) {
/* SOURCE exnmat.for:6286 */
/*<       write(stdout,50)get_tabid(ntab) >*/
	    feq_gen_io_d__730.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__730);
	    feq_gen_get_tabid_d_(feq_gen_ch_d_2, (ftnlen)16, &ntab);
	    s_copy(feq_gen_ch_d_1, feq_gen_ch_d_2, (ftnlen)16, (ftnlen)16);
	    do_fio(&feq_gen_c_d_1, feq_gen_ch_d_1, (ftnlen)16);
	    e_wsfe();
/* SOURCE exnmat.for:6287 */
/*<       write(stdout,52)hg,maxgat >*/
	    feq_gen_io_d__731.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__731);
	    do_fio(&feq_gen_c_d_1, (char *)&hg, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&maxgat, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE exnmat.for:6288 */
/*<       stop'Abnormal stop: errors found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop: errors found."), (ftnlen)28);
/* SOURCE exnmat.for:6289 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:6290 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:6292 */
/*<       gopen(ispout)=hg >*/
    gate1_1.gopen[ispout] = hg;
/* SOURCE exnmat.for:6294 */
/*<       yl=ye2(unn) >*/
    yl = ye2[unn];
/* SOURCE exnmat.for:6295 */
/*<       yr=ye2(dnn) >*/
    yr = ye2[dnn];
/* SOURCE exnmat.for:6296 */
/*<       el=yl+ze(unn) >*/
    el = static_cast<double>(yl) + ze[unn];
/* SOURCE exnmat.for:6297 */
/*<       er=yr+ze(dnn) >*/
    er = static_cast<double>(yr) + ze[dnn];
/*     SET THE DERIVATIVE WRT FLOW. */
/* SOURCE exnmat.for:6301 */
/*<       if(qnn.eq.unn)then >*/
    if (qnn == unn) {
/* SOURCE exnmat.for:6302 */
/*<       pql=1.0 >*/
	*pql = (float)1.;
/* SOURCE exnmat.for:6303 */
/*<       pqr=0.0 >*/
	*pqr = (float)0.;
/* SOURCE exnmat.for:6304 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:6305 */
/*<       pql=0.0 >*/
	*pql = (float)0.;
/* SOURCE exnmat.for:6306 */
/*<       pqr=1.0 >*/
	*pqr = (float)1.;
/* SOURCE exnmat.for:6307 */
/*<       endif >*/
    }
/*     BASE FLOW DIRECTION ON WATER SURFACE ELEVATION FOR NOW. */
/*     EXTEND LATER IF NEEDED */
/* SOURCE exnmat.for:6313 */
/*<       if(el.ge.er)then >*/
    if (el >= er) {
/*       FLOW FROM NOMINAL UPSTREAM NODE TO DOWNSTREAM NODE */
/* SOURCE exnmat.for:6316 */
/*<        >*/
	tdlk15_(stdout, &udtab, &mftab, jtime, &er, &el, &hg, &hbase, &q, &
		dqed, &dqeu, &newhg, ftype, &feq_gen_ftype_code_d_, (ftnlen)8);
/* SOURCE exnmat.for:6319 */
/*<       q=gate_factor*q >*/
	q = static_cast<double>(feq_gen_gate_factor_d_) * q;
/* SOURCE exnmat.for:6320 */
/*<       dqeu=gate_factor*dqeu >*/
	dqeu = static_cast<double>(feq_gen_gate_factor_d_) * dqeu;
/* SOURCE exnmat.for:6321 */
/*<       dqed=gate_factor*dqed >*/
	dqed = static_cast<double>(feq_gen_gate_factor_d_) * dqed;
/* SOURCE exnmat.for:6322 */
/*<       if(sysgn.gt.0)then >*/
	if (sysgn > 0) {
/* SOURCE exnmat.for:6323 */
/*<       res=-q >*/
	    *res = -q;
/* SOURCE exnmat.for:6324 */
/*<       pyl=-dqeu >*/
	    *pyl = -dqeu;
/* SOURCE exnmat.for:6325 */
/*<       pyr=-dqed >*/
	    *pyr = -dqed;
/* SOURCE exnmat.for:6326 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:6327 */
/*<       res=q >*/
	    *res = q;
/* SOURCE exnmat.for:6328 */
/*<       pyl=dqeu >*/
	    *pyl = dqeu;
/* SOURCE exnmat.for:6329 */
/*<       pyr=dqed >*/
	    *pyr = dqed;
/* SOURCE exnmat.for:6330 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:6332 */
/*<       else >*/
    } else {
/*       FLOW FROM NOMINAL DOWNSTREAM NODE TO UPSTREAM NODE */
/* SOURCE exnmat.for:6335 */
/*<        >*/
	tdlk15_(stdout, &dutab, &mftab, jtime, &el, &er, &hg, &hbase, &q, &
		dqed, &dqeu, &newhg, ftype, &feq_gen_ftype_code_d_, (ftnlen)8);
/* SOURCE exnmat.for:6338 */
/*<       q=gate_factor*q >*/
	q = static_cast<double>(feq_gen_gate_factor_d_) * q;
/* SOURCE exnmat.for:6339 */
/*<       dqeu=gate_factor*dqeu >*/
	dqeu = static_cast<double>(feq_gen_gate_factor_d_) * dqeu;
/* SOURCE exnmat.for:6340 */
/*<       dqed=gate_factor*dqed >*/
	dqed = static_cast<double>(feq_gen_gate_factor_d_) * dqed;
/* SOURCE exnmat.for:6341 */
/*<       if(sysgn.gt.0)then >*/
	if (sysgn > 0) {
/* SOURCE exnmat.for:6342 */
/*<       res=q >*/
	    *res = q;
/* SOURCE exnmat.for:6343 */
/*<       pyl=dqed >*/
	    *pyl = dqed;
/* SOURCE exnmat.for:6344 */
/*<       pyr=dqeu >*/
	    *pyr = dqeu;
/* SOURCE exnmat.for:6345 */
/*<       else >*/
	} else {
/* SOURCE exnmat.for:6346 */
/*<       res=-q >*/
	    *res = -q;
/* SOURCE exnmat.for:6347 */
/*<       pyl=-dqed >*/
	    *pyl = -dqed;
/* SOURCE exnmat.for:6348 */
/*<       pyr=-dqeu >*/
	    *pyr = -dqeu;
/* SOURCE exnmat.for:6349 */
/*<       endif >*/
	}
/* SOURCE exnmat.for:6350 */
/*<       endif >*/
    }
/* SOURCE exnmat.for:6352 */
/*<       res=res+qe2(qnn) >*/
    *res += static_cast<double>(qe2[qnn]);
/* SOURCE exnmat.for:6353 */
/*<       fclass(ispout)=ftype >*/
    s_copy(gate2_1.fclass + (ispout << 3), ftype, (ftnlen)8, (ftnlen)8);
/* SOURCE exnmat.for:6354 */
/*<       fclass_code(ispout)=ftype_code >*/
    gate1_1.feq_gen_fclass_code_d_[ispout] = feq_gen_ftype_code_d_;
/* SOURCE exnmat.for:6355 */
/*<       if(ftype.eq.'      FW'.or.ftype.eq.'      SW')then >*/
    if (s_cmp(ftype, const_cast<char*>("      FW"), (ftnlen)8, (ftnlen)8) == 0 || s_cmp(ftype, 
	    const_cast<char*>("      SW"), (ftnlen)8, (ftnlen)8) == 0) {
/*       Set the special gate opening to the weir condition so that */
/*       the gate opening will not be larger than needed. */
/* SOURCE exnmat.for:6358 */
/*<       rdum=newhg/maxgat >*/
	*rdum = static_cast<double>(newhg) / maxgat;
/* SOURCE exnmat.for:6359 */
/*<       if(rdum.gt.1.0)rdum=1.0 >*/
	if (*rdum > (float)1.) {
	    *rdum = (float)1.;
	}
/* SOURCE exnmat.for:6360 */
/*<       emc(ipnt+14)=idum >*/
	emc[*ipnt + 14] = *idum;
/* SOURCE exnmat.for:6361 */
/*<       else >*/
    } else {
/* SOURCE exnmat.for:6362 */
/*<       rdum=0.0 >*/
	*rdum = (float)0.;
/* SOURCE exnmat.for:6363 */
/*<       emc(ipnt+14)=idum >*/
	emc[*ipnt + 14] = *idum;
/* SOURCE exnmat.for:6364 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' UFGATE: EL=',EL,' ER=',ER */
/*      WRITE(STDOUT,*) ' HG=',HG,' FTYPE=',FTYPE,' RES=',RES */
/*      WRITE(STDOUT,*) ' PYL=',PYL,' PYR=',PYR */
/*      WRITE(STDOUT,*) ' ' */
/* SOURCE exnmat.for:6369 */
/*<       return >*/
    return 0;
/* SOURCE exnmat.for:6370 */
/*<       end >*/
} /* ufgate_ */

#undef rdum
#undef idum


#ifdef __cplusplus
	}
#endif
