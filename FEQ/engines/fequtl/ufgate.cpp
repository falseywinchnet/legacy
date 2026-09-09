#include <feq/power_spacing.hpp>
#include <feq/gate_residual.hpp>
#include "callbacks.hpp"
/* ufgate.f -- translated by f2c (version 20240504).
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

/* COMMON ufcom_ is declared in common.hpp. */

#define ufcom_1 ufcom_

/* COMMON epscom_ is declared in common.hpp. */

#define epscom_1 epscom_

/* COMMON ftable_ is declared in common.hpp. */

#define ftable_1 ftable_

/* COMMON ftablea_ is declared in common.hpp. */

#define ftablea_1 ftablea_

/* COMMON ftablec_ is declared in common.hpp. */

#define ftablec_1 ftablec_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_10 = 10;
static integer feq_gen_c_d_10002 = 10002;
static integer feq_gen_c_d_12 = 12;
static integer feq_gen_c_d_2 = 2;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_4 = 4;
static integer feq_gen_c_d_351 = 351;
static integer feq_gen_c_d_22 = 22;
static integer feq_gen_c_d_151 = 151;
static real c_b259 = (float)1.;
static integer feq_gen_c_d_13 = 13;
static real c_b350 = (float)-1.;




/* SOURCE ufgate.for:4 */
/*<       realfunctionrsomy3(y3u) >*/
doublereal rsomy3_(real *y3u)
{
    /* System generated locals */
    real ret_val, feq_gen_r_d_1, feq_gen_r_d_2;

    /* Local variables */
    extern /* Subroutine */ int lktj_(integer *, real *, real *);

/*     + + + PURPOSE + + + */
/*     Find the unknown depth at section 3 for submerged orifice */
/*     flow from the momentum balance. */
/* SOURCE ufgate.for:11 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ufgate.for:14 */
/*<       realy3u >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Y3U    - value of unknown being sought-depth at section 3 */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ufgate.for:20 */
/*     Common block for underflow gate computations.  These values */
/*     are often used in residual functions. */
/* SOURCE ufgate.cmn:4 */
/*<       integerapptab,deptab >*/
/* SOURCE ufgate.cmn:6 */
/*<        >*/
/* SOURCE ufgate.cmn:11 */
/*<        >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ufgate.for:23 */
/*<       externallktj >*/
/* *********************************************************************** */
/* SOURCE ufgate.for:25 */
/*<       yt=y3u >*/
    ufcom_1.yt = *y3u;
/* SOURCE ufgate.for:26 */
/*<       calllktj(deptab,yt,j4aty3) >*/
    lktj_(&ufcom_1.deptab, &ufcom_1.yt, &ufcom_1.j4aty3);
    // Retain the original section lookup and every COMMON REAL store.
    const feq::GateResidualInput input{ufcom_1.y1,ufcom_1.z1b,ufcom_1.z3b,
        ufcom_1.at,ufcom_1.a1,ufcom_1.alpha1,ufcom_1.cd,ufcom_1.bg,ufcom_1.cc,
        ufcom_1.ag,ufcom_1.g,ufcom_1.twog,ufcom_1.a4,ufcom_1.beta4,ufcom_1.j4,
        ufcom_1.j4aty3,ufcom_1.qsqr,*y3u,ufcom_1.dz};
    const feq::GateResidual result = feq::gate_orifice_jet_residual(input);
    ufcom_1.qsqr = result.squared_flow;
    return result.value;
} /* rsomy3_ */




/* SOURCE ufgate.for:42 */
/*<       realfunctionrsomy4(y4u) >*/
doublereal rsomy4_(real *y4u)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
    real dt;
    extern /* Subroutine */ int xlkt22_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *);

/*     + + + PURPOSE + + + */
/*     Find the unknown depth at section 4 for submerged orifice */
/*     flow from the momentum balance. */
/* SOURCE ufgate.for:49 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ufgate.for:52 */
/*<       realy4u >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Y4U    - value of unknown being sought-depth at section 3 */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ufgate.for:58 */
/*     Common block for underflow gate computations.  These values */
/*     are often used in residual functions. */
/* SOURCE ufgate.cmn:4 */
/*<       integerapptab,deptab >*/
/* SOURCE ufgate.cmn:6 */
/*<        >*/
/* SOURCE ufgate.cmn:11 */
/*<        >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ufgate.for:61 */
/*<       realdt >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ufgate.for:64 */
/*<       externalxlkt22 >*/
/* *********************************************************************** */
/* SOURCE ufgate.for:66 */
/*<       yt=y4u >*/
    ufcom_1.yt = *y4u;
/* SOURCE ufgate.for:67 */
/*<        >*/
    xlkt22_(&ufcom_1.deptab, &ufcom_1.yt, &ufcom_1.a4, &ufcom_1.tt, &dt, &
	    ufcom_1.j4, &ufcom_1.kt, &ufcom_1.dkt, &ufcom_1.beta4, &
	    ufcom_1.dbeta, &ufcom_1.alpha4, &ufcom_1.dalpha, &ufcom_1.qct);
    // Retain the original section lookup and every COMMON REAL store.
    const feq::GateResidualInput input{ufcom_1.y1,ufcom_1.z1b,ufcom_1.z3b,
        ufcom_1.at,ufcom_1.a1,ufcom_1.alpha1,ufcom_1.cd,ufcom_1.bg,ufcom_1.cc,
        ufcom_1.ag,ufcom_1.g,ufcom_1.twog,ufcom_1.a4,ufcom_1.beta4,ufcom_1.j4,
        ufcom_1.j4aty3,ufcom_1.qsqr,ufcom_1.y3,ufcom_1.dz};
    const feq::GateResidual result = feq::gate_orifice_tailwater_residual(input);
    return result.value;
} /* rsomy4_ */




/* SOURCE ufgate.for:81 */
/*<       realfunctionrswmy3(y3u) >*/
doublereal rswmy3_(real *y3u)
{
    /* System generated locals */
    real ret_val, feq_gen_r_d_1, feq_gen_r_d_2;

    /* Local variables */
    extern /* Subroutine */ int lktj_(integer *, real *, real *);

/*     + + + PURPOSE + + + */
/*     Find the unknown depth at section 3 for submerged weir flow */
/*     from the momentum balance. */
/* SOURCE ufgate.for:88 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ufgate.for:91 */
/*<       realy3u >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Y3U    - value of unknown being sought-depth at section 3 */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ufgate.for:97 */
/*     Common block for underflow gate computations.  These values */
/*     are often used in residual functions. */
/* SOURCE ufgate.cmn:4 */
/*<       integerapptab,deptab >*/
/* SOURCE ufgate.cmn:6 */
/*<        >*/
/* SOURCE ufgate.cmn:11 */
/*<        >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ufgate.for:100 */
/*<       externallktj >*/
/* *********************************************************************** */
/* SOURCE ufgate.for:102 */
/*<       yt=y3u >*/
    ufcom_1.yt = *y3u;
/* SOURCE ufgate.for:103 */
/*<       calllktj(deptab,yt,j4aty3) >*/
    lktj_(&ufcom_1.deptab, &ufcom_1.yt, &ufcom_1.j4aty3);
    // Retain the original section lookup and every COMMON REAL store.
    const feq::GateResidualInput input{ufcom_1.y1,ufcom_1.z1b,ufcom_1.z3b,
        ufcom_1.at,ufcom_1.a1,ufcom_1.alpha1,ufcom_1.cd,ufcom_1.bg,ufcom_1.cc,
        ufcom_1.ag,ufcom_1.g,ufcom_1.twog,ufcom_1.a4,ufcom_1.beta4,ufcom_1.j4,
        ufcom_1.j4aty3,ufcom_1.qsqr,*y3u,ufcom_1.dz};
    const feq::GateResidual result = feq::gate_weir_jet_residual(input);
    ufcom_1.qsqr = result.squared_flow;
    return result.value;
} /* rswmy3_ */




/* SOURCE ufgate.for:118 */
/*<       realfunctionrswmy4(y4u) >*/
doublereal rswmy4_(real *y4u)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
    real dt;
    extern /* Subroutine */ int xlkt22_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *);

/*     + + + PURPOSE + + + */
/*     Find the value of depth at section 4 for submerged weir */
/*     flow from the momentum balance. */
/* SOURCE ufgate.for:125 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ufgate.for:128 */
/*<       realy4u >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Y4U    - value of unknown being sought-depth at section 3 */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ufgate.for:134 */
/*     Common block for underflow gate computations.  These values */
/*     are often used in residual functions. */
/* SOURCE ufgate.cmn:4 */
/*<       integerapptab,deptab >*/
/* SOURCE ufgate.cmn:6 */
/*<        >*/
/* SOURCE ufgate.cmn:11 */
/*<        >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ufgate.for:137 */
/*<       realdt >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ufgate.for:140 */
/*<       externalxlkt22 >*/
/* *********************************************************************** */
/*     On entry all constant values must be known and placed in */
/*     the common block in ufgate.cmn. The cross section elements at */
/*     section 4 are recomputed here. */
/* SOURCE ufgate.for:145 */
/*<       yt=y4u >*/
    ufcom_1.yt = *y4u;
/* SOURCE ufgate.for:146 */
/*<        >*/
    xlkt22_(&ufcom_1.deptab, &ufcom_1.yt, &ufcom_1.a4, &ufcom_1.tt, &dt, &
	    ufcom_1.j4, &ufcom_1.kt, &ufcom_1.dkt, &ufcom_1.beta4, &
	    ufcom_1.dbeta, &ufcom_1.alpha4, &ufcom_1.dalpha, &ufcom_1.qct);
    // Retain the original section lookup and every COMMON REAL store.
    const feq::GateResidualInput input{ufcom_1.y1,ufcom_1.z1b,ufcom_1.z3b,
        ufcom_1.at,ufcom_1.a1,ufcom_1.alpha1,ufcom_1.cd,ufcom_1.bg,ufcom_1.cc,
        ufcom_1.ag,ufcom_1.g,ufcom_1.twog,ufcom_1.a4,ufcom_1.beta4,ufcom_1.j4,
        ufcom_1.j4aty3,ufcom_1.qsqr,ufcom_1.y3,ufcom_1.dz};
    const feq::GateResidual result = feq::gate_weir_tailwater_residual(input);
    return result.value;
} /* rswmy4_ */




/* SOURCE ufgate.for:159 */
/*<       realfunctionfindcc(arg,concc,cctab) >*/
doublereal findcc_(real *arg, real *concc, integer *cctab)
{
    /* System generated locals */
    real ret_val;

    /* Local variables */
    real cc, df;
    integer ntab;
    extern /* Subroutine */ int lktab_(integer *, real *, integer *, real *, 
	    integer *, real *);

/*     + + + PURPOSE + + + */
/*     Find a contraction coefficient for an underflow gate. */
/* SOURCE ufgate.for:165 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ufgate.for:168 */
/*<       integercctab >*/
/* SOURCE ufgate.for:169 */
/*<       realarg,concc >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     ARG    - argument for lookup of contraction coefficient for an */
/*              underflow gate. */
/*     CONCC  - contraction coefficient */
/*     CCTAB  - address of table giving contraction coefficient */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ufgate.for:178 */
/*<       integerntab >*/
/* SOURCE ufgate.for:179 */
/*<       realcc,df >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ufgate.for:182 */
/*<       externallktab >*/
/* *********************************************************************** */
/* SOURCE ufgate.for:184 */
/*<       if(cctab.eq.0)then >*/
    if (*cctab == 0) {
/*       Take as a constant value. */
/* SOURCE ufgate.for:186 */
/*<       findcc=concc >*/
	ret_val = *concc;
/* SOURCE ufgate.for:187 */
/*<       else >*/
    } else {
/*       Lookup values in table. */
/* SOURCE ufgate.for:189 */
/*<       calllktab(cctab,arg,1,cc,ntab,df) >*/
	lktab_(cctab, arg, &feq_gen_c_d_1, &cc, &ntab, &df);
/* SOURCE ufgate.for:192 */
/*<       findcc=cc >*/
	ret_val = cc;
/* SOURCE ufgate.for:193 */
/*<       endif >*/
    }
/* SOURCE ufgate.for:194 */
/*<       return >*/
    return ret_val;
/* SOURCE ufgate.for:195 */
/*<       end >*/
} /* findcc_ */




/* SOURCE ufgate.for:199 */
/*<       subroutinefotoso(h1,q,hdatum,h4,iflag) >*/
/* Subroutine */ int fotoso_(real *h1, real *q, real *hdatum, real *h4, 
	integer *iflag)
{
    /* System generated locals */
    real feq_gen_r_d_1;

    /* Local variables */
    real hvc;
    extern /* Subroutine */ int lktj_(integer *, real *, real *);
    real yleft;
    extern doublereal rsomy4_(real *);
    extern /* Subroutine */ int regfal_(real *, real *, FeqCallback3, real *, real *, 
	    real *, integer *);
    real yright;

/*     + + + PURPOSE + + + */
/*     For a given upstream head(at section 1) find the */
/*     tailwater head(at section 4) that defines the */
/*     boundary between free orifice(FO) flow and submerged orifice(SO) */
/*     flow. */
/* SOURCE ufgate.for:209 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ufgate.for:212 */
/*<       integeriflag >*/
/* SOURCE ufgate.for:213 */
/*<       realh1,h4,hdatum,q >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     H1     - head at section 1 */
/*     Q      - Flowrate */
/*     HDATUM - Datum for measuring head */
/*     H4     - head at section 4 */
/*     IFLAG  - error flag */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ufgate.for:223 */
/*     Common block for underflow gate computations.  These values */
/*     are often used in residual functions. */
/* SOURCE ufgate.cmn:4 */
/*<       integerapptab,deptab >*/
/* SOURCE ufgate.cmn:6 */
/*<        >*/
/* SOURCE ufgate.cmn:11 */
/*<        >*/
/* INCLUDE ufgate.for:224 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ufgate.for:227 */
/*<       realhvc,yleft,yright >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ufgate.for:230 */
/*<       realrsomy4 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ufgate.for:233 */
/*<       externallktj,regfal,rsomy4 >*/
/* *********************************************************************** */
/* SOURCE ufgate.for:235 */
/*<       hvc=cc*hg+z2b-hdatum >*/
    hvc = static_cast<double>(static_cast<double>(static_cast<double>(ufcom_1.cc) * ufcom_1.hg) + ufcom_1.z2b) - *hdatum;
/* SOURCE ufgate.for:236 */
/*<       y3=hvc+hdatum-z3b >*/
    ufcom_1.y3 = static_cast<double>(static_cast<double>(hvc) + *hdatum) - ufcom_1.z3b;
/* SOURCE ufgate.for:237 */
/*<       calllktj(deptab,y3,j4aty3) >*/
    lktj_(&ufcom_1.deptab, &ufcom_1.y3, &ufcom_1.j4aty3);
/* SOURCE ufgate.for:241 */
/*<       qsqr=q**2 >*/
/* Computing 2nd power */
    feq_gen_r_d_1 = *q;
    ufcom_1.qsqr = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/*     The water surface elevation at section 4 will be */
/*     below the elevation at section 1 but above the */
/*     jet surface elevation at section 2. */
/* SOURCE ufgate.for:247 */
/*<       yleft=hvc+hdatum-z4b >*/
    yleft = static_cast<double>(static_cast<double>(hvc) + *hdatum) - ufcom_1.z4b;
/* SOURCE ufgate.for:248 */
/*<       yright=h1+hdatum-z4b >*/
    yright = static_cast<double>(static_cast<double>(*h1) + *hdatum) - ufcom_1.z4b;
/* SOURCE ufgate.for:250 */
/*<       callregfal(epsarg,epsf,rsomy4,yleft,yright,y4,iflag) >*/
    regfal_(&epscom_1.epsarg, &epscom_1.epsf, rsomy4_, &yleft, &yright, 
	    &ufcom_1.y4, iflag);
/* SOURCE ufgate.for:255 */
/*<       h4=y4+z4b-hdatum >*/
    *h4 = static_cast<double>(static_cast<double>(ufcom_1.y4) + ufcom_1.z4b) - *hdatum;
/* SOURCE ufgate.for:256 */
/*<       return >*/
    return 0;
/* SOURCE ufgate.for:257 */
/*<       end >*/
} /* fotoso_ */




/* SOURCE ufgate.for:261 */
/*<       subroutinefndfoq(h1,hdatum,q) >*/
/* Subroutine */ int fndfoq_(real *h1, real *hdatum, real *q)
{
    /* System generated locals */
    real feq_gen_r_d_1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    real dt, hvc;
    extern /* Subroutine */ int xlkt22_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *);

/*     + + + PURPOSE + + + */
/*     Find the free orifice flow.  Gate opening and contraction */
/*     coefficient are in common block */
/* SOURCE ufgate.for:269 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ufgate.for:272 */
/*<       realh1,hdatum,q >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     H1     - head at section 1 */
/*     HDATUM - Datum for measuring head */
/*     Q      - Flowrate */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ufgate.for:280 */
/*     Common block for underflow gate computations.  These values */
/*     are often used in residual functions. */
/* SOURCE ufgate.cmn:4 */
/*<       integerapptab,deptab >*/
/* SOURCE ufgate.cmn:6 */
/*<        >*/
/* SOURCE ufgate.cmn:11 */
/*<        >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ufgate.for:283 */
/*<       realdt,hvc >*/
/*     + + + INTRINSICS + + + */
/* SOURCE ufgate.for:286 */
/*<       intrinsicsqrt >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ufgate.for:289 */
/*<       externalxlkt22 >*/
/* *********************************************************************** */
/* SOURCE ufgate.for:291 */
/*<       y1=h1+hdatum-z1b >*/
    ufcom_1.y1 = static_cast<double>(static_cast<double>(*h1) + *hdatum) - ufcom_1.z1b;
/* SOURCE ufgate.for:292 */
/*<        >*/
    xlkt22_(&ufcom_1.apptab, &ufcom_1.y1, &ufcom_1.a1, &ufcom_1.tt, &dt, &
	    ufcom_1.jt, &ufcom_1.kt, &ufcom_1.dkt, &ufcom_1.beta, &
	    ufcom_1.dbeta, &ufcom_1.alpha1, &ufcom_1.dalpha, &ufcom_1.qct);
    // Keep the original upstream depth, section lookup and COMMON stores.
    const feq::GateFreeOrifice result = feq::gate_free_orifice(*h1,*hdatum,
        ufcom_1.cd,ufcom_1.cc,ufcom_1.ag,ufcom_1.hg,ufcom_1.z2b,
        ufcom_1.a1,ufcom_1.alpha1,ufcom_1.twog);
    ufcom_1.at = result.effective_area;
    *q = result.flow;
    return 0;
} /* fndfoq_ */




/* SOURCE ufgate.for:307 */
/*<        >*/
/* Subroutine */ int lstopf_(integer *stdout, integer *tablt, integer *tabgt, 
	real *power, real *offset, real *a, real *b, real *prec, integer *
	nmax, integer *n, real *feq_storage_xbrk, integer *eflag)
{
    // The released routine retains both bounds across the ratio lookup.
    const float spacing_first = *a;
    const float spacing_last = *b;

    /* Format strings */
    static char fmt_50[] = "(\002 *BUG:XXX* A=\002,f10.4,\002 => B=\002,f10.\
4,\002 in LSTOPF.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen);
    double log(doublereal), exp(doublereal);

    /* Local variables */
    integer feq_gen_i_d_;
    real pow;
    integer ipow;
    real dfcol;
    extern /* Subroutine */ int tdlk10_(integer *, integer *, integer *, real 
	    *, real *, real *, real *, real *);
    real rbtoa, dfrow, argrat;

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__11 = { 0, 0, 0, fmt_50, 0 };


/*     + + + PURPOSE + + + */
/*     Define the sequence of breakpoints, XBRK, between A and B */
/*     so that a linear spline on that breakpoint sequence will */
/*     interpolate a power function with power=POWER and offset= */
/*     OFFSET with a relative precision given by PREC.  There */
/*     can be no more than NMAX points.  TABLT and TABGT are */
/*     data table addresses that give the argument ratios for a range */
/*     of powers and precisions.  TABLT is for powers less than 1 */
/*     and TABGT is for powers greater than 1. */
/* SOURCE ufgate.for:322 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ufgate.for:325 */
/*<       integereflag,n,nmax,stdout,tabgt,tablt >*/
/* SOURCE ufgate.for:326 */
/*<       reala,b,offset,power,prec,xbrk(nmax) >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     TABLT  - address of function table for powers less than 1.0 */
/*     TABGT  - function table address for powers greater than 1.0 */
/*     POWER  - power in the power function */
/*     OFFSET - offset to use in the power function */
/*     A      - lower limit of range of approximation */
/*     B      - upper limit of range of approximation */
/*     PREC   - precision of the approximation */
/*     NMAX   - Maximum number of items allowed in table */
/*     N      - number of break points */
/*     XBRK   - breakpoint locations for the linear spline */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ufgate.for:343 */
/*<       integeri,ipow >*/
/* SOURCE ufgate.for:344 */
/*<       realargrat,dfcol,dfrow,pow,rbtoa >*/
/*     + + + INTRINSICS + + + */
/* SOURCE ufgate.for:347 */
/*<       intrinsicexp,float,log >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ufgate.for:350 */
/*<       externaltdlk10 >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ufgate.for:353 */
/*<    50 format(' *BUG:XXX* A=',f10.4,' => B=',f10.4,' in LSTOPF.') >*/
/* *********************************************************************** */
/*     Find the argument ratio for the current power and precision. */
/*     Note that TABLT and TABGT are addresses of the table and not */
/*     the table number. */
/* SOURCE ufgate.for:359 */
/*<       if(a.ge.b)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> xbrk(feq_storage_xbrk, 1);

    /* Function Body */
/* L50: */
    if (*a >= *b) {
/* SOURCE ufgate.for:360 */
/*<       write(stdout,50)a,b >*/
	feq_gen_io_d__11.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__11);
	do_fio(&feq_gen_c_d_1, (char *)&(*a), (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&(*b), (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE ufgate.for:361 */
/*<       stop >*/
	s_stop(const_cast<char*>(""), (ftnlen)0);
/* SOURCE ufgate.for:362 */
/*<       endif >*/
    }
/* SOURCE ufgate.for:363 */
/*<       if(power.lt.1.0)then >*/
    if (*power < (float)1.) {
/* SOURCE ufgate.for:364 */
/*<       calltdlk10(stdout,tablt,10,power,prec,argrat,dfrow,dfcol) >*/
	tdlk10_(stdout, tablt, &feq_gen_c_d_10, power, prec, &argrat, &dfrow, &dfcol);
/* SOURCE ufgate.for:367 */
/*<       else >*/
    } else {
/* SOURCE ufgate.for:368 */
/*<       calltdlk10(stdout,tabgt,10,power,prec,argrat,dfrow,dfcol) >*/
	tdlk10_(stdout, tabgt, &feq_gen_c_d_10, power, prec, &argrat, &dfrow, &dfcol);
/* SOURCE ufgate.for:371 */
/*<       endif >*/
    }
/*      WRITE(STDOUT,*) ' LSTOPF: ARGRAT=',ARGRAT */
/*      WRITE(STDOUT,*) ' LSTOPF: A=',A,' B=',B */
/*      WRITE(STDOUT,*) ' OFFSET=',OFFSET */
/*     Find the ratio of the limits */
/* SOURCE ufgate.for:379 */
/*<       rbtoa=(b+offset)/(a+offset) >*/
    // Preserve the original table selection and invalid-range diagnostic.
    *n = feq::power_breakpoints(spacing_first,spacing_last,*offset,argrat,feq_storage_xbrk,*nmax,*eflag);
    return 0;
} /* lstopf_ */




/* SOURCE ufgate.for:420 */
/*<        >*/
/* Subroutine */ int feq_gen_read_ufgate_items_d_(integer *stdout, char *line, integer 
	*nitem, integer *feq_gen_feq_storage_item_start_d_, integer *feq_gen_feq_storage_item_end_d_, integer *eflag, 
	integer *idlen, real *hg, integer *tab2d, real *ccval, real *angle, 
	ftnlen line_len)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:759* Only \002,i3,\002 items given \
in \002,\002UFGATE description line.  Need four items.\002)";

    /* System generated locals */
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe();
    /* Subroutine */ int s_stop(char *, ftnlen), s_copy(char *, char *, 
	    ftnlen, ftnlen);
    integer s_rsfi(icilist *), e_rsfi(), s_cmp(char *, char *, ftnlen, ftnlen)
	    ;

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    integer n, ie, is;
    char tpc[20], key[16];
    integer itab, lkey;
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int feq_gen_strip_l_blanks_d_(char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__19 = { 0, 0, 0, fmt_50, 0 };


/*     Get the items of data from input line in UFGATE */
/* SOURCE ufgate.for:428 */
/*<       implicitnone >*/
/* SOURCE ufgate.for:429 */
/*<        >*/
/* SOURCE ufgate.for:431 */
/*<       realhg,ccval,angle >*/
/* SOURCE ufgate.for:432 */
/*<       characterline*(*) >*/
/*     Local */
/* SOURCE ufgate.for:436 */
/*<       integerie,is,itab,lkey,n >*/
/* SOURCE ufgate.for:437 */
/*<       charactertpc*20,key*16 >*/
/*     Called program units */
/* SOURCE ufgate.for:440 */
/*<       integernonblank_nonzero,lenstr >*/
/* SOURCE ufgate.for:441 */
/*<        >*/
/*     ***********************FORMATS************************************ */
/* SOURCE ufgate.for:444 */
/*<    50  >*/
/* *********************************************************************** */
/* SOURCE ufgate.for:448 */
/*<       if(nitem.lt.4)then >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> feq_gen_item_end_d_(feq_gen_feq_storage_item_end_d_, 1);

    feq::IndexedPointer<integer> feq_gen_item_start_d_(feq_gen_feq_storage_item_start_d_, 1);

    /* Function Body */
/* L50: */
    if (*nitem < 4) {
/* SOURCE ufgate.for:449 */
/*<       write(stdout,50)nitem >*/
	feq_gen_io_d__19.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__19);
	do_fio(&feq_gen_c_d_1, (char *)&(*nitem), (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE ufgate.for:450 */
/*<       stop'Abnormal stop.  Errors found.' >*/
	s_stop(const_cast<char*>("Abnormal stop.  Errors found."), (ftnlen)29);
/* SOURCE ufgate.for:451 */
/*<       endif >*/
    }
/* SOURCE ufgate.for:453 */
/*<       n=1 >*/
    n = 1;
/*     Process the gate opening */
/* SOURCE ufgate.for:455 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE ufgate.for:456 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE ufgate.for:457 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE ufgate.for:458 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE ufgate.for:460 */
/*<       read(tpc,'(F10.0)')hg >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 20;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.0)");
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*hg), (ftnlen)sizeof(real));
    e_rsfi();
/*     Process the table id */
/* SOURCE ufgate.for:463 */
/*<       n=2 >*/
    n = 2;
/* SOURCE ufgate.for:464 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE ufgate.for:465 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE ufgate.for:466 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE ufgate.for:467 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE ufgate.for:469 */
/*<       key=tpc >*/
    s_copy(key, tpc, (ftnlen)16, (ftnlen)20);
/* SOURCE ufgate.for:470 */
/*<       lkey=lenstr(key) >*/
    lkey = lenstr_(key, (ftnlen)16);
/* SOURCE ufgate.for:471 */
/*<       idlen=max(idlen,lkey) >*/
    *idlen = max(*idlen,lkey);
/*     Convert from the table id to an internal number. */
/* SOURCE ufgate.for:473 */
/*<       if(key.ne.' ')then >*/
    if (s_cmp(key, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/* SOURCE ufgate.for:474 */
/*<       callget_internal_tab_number(stdout,key,eflag,itab) >*/
	feq_gen_get_internal_tab_number_d_(stdout, key, eflag, &itab, (ftnlen)16);
/* SOURCE ufgate.for:478 */
/*<       tab2d=itab >*/
	*tab2d = itab;
/* SOURCE ufgate.for:479 */
/*<       else >*/
    } else {
/* SOURCE ufgate.for:480 */
/*<       tab2d=0 >*/
	*tab2d = 0;
/* SOURCE ufgate.for:481 */
/*<       endif >*/
    }
/*     Process the the contraction coefficient */
/* SOURCE ufgate.for:484 */
/*<       n=3 >*/
    n = 3;
/* SOURCE ufgate.for:485 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE ufgate.for:486 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE ufgate.for:487 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE ufgate.for:488 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE ufgate.for:490 */
/*<       read(tpc,'(F10.0)')ccval >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 20;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.0)");
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*ccval), (ftnlen)sizeof(real));
    e_rsfi();
/*     Process the angle */
/* SOURCE ufgate.for:493 */
/*<       n=4 >*/
    n = 4;
/* SOURCE ufgate.for:494 */
/*<       is=item_start(n) >*/
    is = feq_gen_item_start_d_[n];
/* SOURCE ufgate.for:495 */
/*<       ie=item_end(n) >*/
    ie = feq_gen_item_end_d_[n];
/* SOURCE ufgate.for:496 */
/*<       tpc=line(is:ie) >*/
    s_copy(tpc, line + (is - 1), (ftnlen)20, ie - (is - 1));
/* SOURCE ufgate.for:497 */
/*<       callstrip_l_blanks(tpc) >*/
    feq_gen_strip_l_blanks_d_(tpc, (ftnlen)20);
/* SOURCE ufgate.for:499 */
/*<       read(tpc,'(F10.0)')angle >*/
    feq_gen_ici_d_1.icierr = 0;
    feq_gen_ici_d_1.iciend = 0;
    feq_gen_ici_d_1.icirnum = 1;
    feq_gen_ici_d_1.icirlen = 20;
    feq_gen_ici_d_1.iciunit = tpc;
    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.0)");
    s_rsfi(&feq_gen_ici_d_1);
    do_fio(&feq_gen_c_d_1, (char *)&(*angle), (ftnlen)sizeof(real));
    e_rsfi();
/* SOURCE ufgate.for:501 */
/*<       return >*/
    return 0;
/* SOURCE ufgate.for:502 */
/*<       end >*/
} /* read_ufgate_items__ */




/* SOURCE ufgate.for:506 */
/*<       subroutineufgate(grav,stdin,stdout,stdtab,eflag,tabdir) >*/
/* Subroutine */ int ufgate_(real *grav, integer *stdin, integer *stdout, 
	integer *stdtab, integer *eflag, integer *feq_storage_tabdir)
{
    feq::GateOrificeState orifice_state{};

    feq::GateCriticalSetup critical_setup{};
    feq::GateFreeWeir free_weir{};

    feq::GateTailwaterLevels tailwater_levels{};
    feq::GateSubmergedLevels submerged_levels{};
    float stored_gate_head = 0.0F, stored_gate_drop = 0.0F;
    float stored_submerged_head = 0.0F, stored_submerged_drop = 0.0F;

    /* Format strings */
    static char fmt_2[] = "(6x,a)";
    static char fmt_8[] = "(9x,f10.0)";
    static char fmt_10[] = "(10x,f10.0)";
    static char fmt_12[] = "(3x,f10.0)";
    static char fmt_16[] = "(7x,f10.0)";
    static char fmt_18[] = "(7x,f10.0)";
    static char fmt_19[] = "(9x,f10.0)";
    static char fmt_20[] = "(8x,f10.0)";
    static char fmt_21[] = "(8x,f10.0)";
    static char fmt_22[] = "(10x,f10.0)";
    static char fmt_50[] = "(/,\002 TabId= \002,a,\002 for type 15 table for\
 underflow\002,\002 gate.\002)";
    static char fmt_52[] = "(/,\002 Label=\002,a50)";
    static char fmt_54[] = "(/,\002 Approach section table id= \002,a)";
    static char fmt_56[] = "(/,\002 Departure section table id= \002,a)";
    static char fmt_58[] = "(/,\002 Elevation of gate sill=\002,f10.3)";
    static char fmt_60[] = "(/,\002 Total gate opening width=\002,f10.3)";
    static char fmt_62[] = "(/,\002 Discharge coefficient for approach to ga\
te=\002,f10.3)";
    static char fmt_64[] = "(/,\002 Contraction coefficient table id= \002,a)"
	    ;
    static char fmt_65[] = "(/,\002 *ERR:774* Must have at least two gate op\
enings.\002)";
    static char fmt_66[] = "(/,\002 Minimum partial free drop=\002,f10.5)";
    static char fmt_67[] = "(/,\002 Partial free drop at power breakpoint\
=\002,f10.5)";
    static char fmt_68[] = "(/,\002 Limiting partial free drop=\002,f10.3)";
    static char fmt_69[] = "(/,\002 Final local power for partial free dro\
ps=\002,f10.3)";
    static char fmt_70[] = "(/,\002Two-D table computations for gate openi\
ng=\002,f8.3,\002  Two-D table id= \002,a)";
    static char fmt_71[] = "(5x,\002Head at section 1 for FW/FO boundary=\
\002,f9.4,/,5x,\002Head-relative gate opening at FW/FO boundary=\002,f9.4)";
    static char fmt_72[] = "(/,\002Upstream head=\002,f9.4,\002 Elevation\
=\002,f10.4,/,2x,\002Depth at section 1=\002,f8.4,\002 Gate opening=\002,f8.\
4)";
    static char fmt_74[] = "(/,\002  Partial  Drop    Head    Head   Flow Co\
nt.  Discharge Local\002,\002  Energy\002,/,\002   free    sect.   sect.   s\
ect.  type coef.            power\002,\002   loss\002,/,\002   drop    1->4 \
    3       4           Cc  \002,17x,\002   1->4\002,/,\002 --------  ------\
  ------  ------  ---  ---- --------- -----\002,\002  ------\002)";
    static char fmt_75[] = "(1x,f8.4,f8.3,f8.3,f8.3,3x,a2,a6,1x,a10,f6.2,f8.\
3)";
    static char fmt_76[] = "(1x,f8.4,f8.3,f8.3,f8.3,3x,a2,a6,1x,a10,6x,f8.3)";
    static char fmt_77[] = "(/,\002 *WRN:592* Please review results.  One or\
 more\002,\002 cases with energy gain found.\002)";
    static char fmt_79[] = "(/,\002 Free weir to free orifice transition fra\
ction=\002,f8.2)";
    static char fmt_80[] = "(/,\002 Maximum upstream head=\002,f8.2)";
    static char fmt_81[] = "(/,\002 Minimum non-zero upstream head=\002,f8.2)"
	    ;
    static char fmt_82[] = "(/,\002 Linear interpolation precision=\002,f8.3)"
	    ;
    static char fmt_86[] = "(/,\002 Maximum relative error=\002,f6.3,\002 Ga\
te opening=\002,f8.4,/,\002   Upstream head=\002,f9.4,\002 Partial free drop=\
\002,f8.5)";
    static char fmt_87[] = "(/,\002 *ERR:607* TabId missing or negative.\002)"
	    ;
    static char fmt_88[] = "(/\002 Root-mean-squared error=\002,f6.3,\002 N \
in sample=\002,i5)";
    static char fmt_89[] = "(\002  Processing UFGATE TabId= \002,a)";
    static char fmt_90[] = "(/,\002 *ERR:712* Gate sill elevation=\002,f10\
.3,\002 <  elevation\002,\002 of floor of\002,/,11x,\002 departure reach=\
\002,f10.3)";
    static char fmt_91[] = "(/,\002 *ERR:713* Gate opening width=\002,f10.3\
,\002 <= 0.0\002)";
    static char fmt_92[] = "(/,\002 *ERR:714* Approach loss Cd <=0.0 or > \
1.0\002)";
    static char fmt_93[] = "(/,\002 *ERR:715* Contraction coef.=\002,f10.3\
,\002 <= 0.0 or > 1.0\002)";
    static char fmt_94[] = "(/,\002 *ERR:716* In UFGATE: FLAG=\002,i3,\002 N\
o solution\002,a)";
    static char fmt_95[] = "(\002TABID= \002,a,/,\002TYPE=  -15\002,/,\002RE\
FL=\002,7x,\0020.0 LABEL=\002,a50,/,\002   OPENING            TABID   H1FWUL\
R   H4FWULR H4SWSOMDR\002)";
    static char fmt_96[] = "(f10.3,1x,a16,3f10.6)";
    static char fmt_97[] = "(/,\002 *BUG:XXX* In UFGATE no root in 16 tries \
for:\002,a)";
    static char fmt_98[] = "(/,\002 *ERR:717* Gate sill elevation=\002,f10\
.3,\002 <  elevation\002,\002 of floor of\002,/,11x,\002 approach reach=\002\
,f10.3)";
    static char fmt_99[] = "(/,\002 *ERR:* Interpolation precision tables mi\
ssing.\002,\002 Check for version\002,/,11x,\002of file: TYPE5.TAB.\002)";

    /* System generated locals */
    address feq_gen_a_d_1[2];
    integer feq_gen_i_d_1, feq_gen_i_d_2[2], feq_gen_i_d_3, feq_gen_i_d_4;
    real feq_gen_r_d_1, feq_gen_r_d_2;
    char feq_gen_ch_d_1[16], feq_gen_ch_d_2[10];
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(), do_fio(integer *, char *, ftnlen), 
	    s_rsfi(icilist *), e_rsfi(), s_wsle(cilist *), do_lio(integer *, 
	    integer *, char *, ftnlen), e_wsle(), s_wsfi(icilist *), e_wsfi();
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    double sqrt(doublereal), log(doublereal);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    char deptabid[16];
    integer feq_gen_item_end_d_[4];
    char apptabid[16];
    integer colwidth;
    doublereal northing;
    integer feq_gen_i_d_, j, n;
    real p, q, y;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    double h1;
    real h3, t4;
    double h4;
    extern /* Subroutine */ int feq_gen_read_ufgate_items_d_(integer *, char *, 
	    integer *, integer *, integer *, integer *, integer *, real *, 
	    integer *, real *, real *, ftnlen);
    integer ef;
    char id[16], cq[10];
    real dt, rg;
    extern /* Subroutine */ int feq_gen_read_tabid_d_(integer *, char *, char *, 
	    integer *, char *, integer *, ftnlen, ftnlen, ftnlen);
    real tp, y4f;
    double h4f;
    integer feq_gen_item_start_d_[4];
    real zw4, fac;
    integer tab, ihg, nhg;
    real div;
    integer ihu;
    real qfo;
    char key[16];
    integer nhu;
    real rhs, rms, pow;
    char lab2[50];
    real y2fo, y2fw, zw4f, y4sw;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    integer ipfd;
    char line[80];
    real prec, qhat, herr, qmat[53001];
    double drop;
    extern /* Subroutine */ int lktj_(integer *, real *, real *);
    real xbrk[351], rerr;
    char zone[8];
    extern /* Character */ VOID put10_(char *, ftnlen, real *);
    integer nrms;
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    real work[351];
    char just[5];
    integer tab2d[40];
    char char6[6];
    real y2old, oldy3;
    integer cctab;
    char hglab[10], label[50];
    integer iflag;
    char tabid[16];
    integer jbase;
    real angle[40], concc;
    integer nfrac;
    real ccval[40];
    integer idlen;
    real fdvec[151], hgvec[40], de1to4;
    integer tabgt;
    real oldhg;
    integer tablt, tptab, nitem;
    real humax, humin, huvec[151], maxhu, minhu, power, qfree, yleft;
    double fdrop;
    char ftype[2];
    real dbeta4;
    char idout[32], hgrid[8], basis[8];
    extern /* Subroutine */ int xlkt22_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *);
    real h1foll, h4foll, h1fwul, h4fwul;
    double h1swso;
    extern doublereal findcc_(real *, real *, integer *);
    real z1fwul;
    double h4swso;
    integer elflag;
    extern doublereal rsomy3_(real *), rsomy4_(real *);
    extern /* Subroutine */ int chktab_(integer *, integer *, integer *, 
	    integer *, integer *, integer *);
    real ccfoll;
    extern /* Subroutine */ int regfal_(real *, real *, FeqCallback3, real *, real *, 
	    real *, integer *);
    extern doublereal rswmy3_(real *), rswmy4_(real *);
    integer ihgerr;
    real bigerr, brkpfd, hdatum, limpfd, finpow, fwfotr, hstuff[120]	/* 
	    was [40][3] */, liprec, lipvec[40], minpfd, mnhvec[40], offset, 
	    pfdtmp[351], pfdvec[351], y4swso, yright, rgfwul, zrhufd;
    char vdatum[8];
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int fdroot_(real *, FeqCallback3, real *, real *, integer 
	    *), fndelv_(integer *, integer *, integer *, real *), fndfoq_(
	    real *, real *, real *), fotoso_(real *, real *, real *, real *, 
	    integer *), inline_(integer *, integer *, char *, ftnlen), 
	    invtse_(real *, integer *, integer *, integer *, real *, real *, 
	    real *, integer *), lstopf_(integer *, integer *, integer *, real 
	    *, real *, real *, real *, real *, integer *, integer *, real *, 
	    integer *), tabchk_(integer *, integer *, integer *, integer *, 
	    integer *), twdout_(integer *, integer *, integer *, char *, 
	    integer *, integer *, real *, real *, real *, real *, real *, 
	    integer *, char *, real *, char *, char *, char *, char *, char *,
	     doublereal *, doublereal *, integer *, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen), feq_gen_get_lctn_items_d_(integer *, 
	    integer *, integer *), feq_gen_set_lctn_items_d_(char *, char *, char *, 
	    char *, char *, doublereal *, doublereal *, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen);
    char cctabid[16];
    doublereal easting;
    extern /* Subroutine */ int feq_gen_get_item_limits_d_(integer *, char *, integer *
	    , char *, integer *, integer *, integer *, ftnlen, ftnlen);
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__33 = { 0, 0, 0, fmt_99, 0 };
    static cilist feq_gen_io_d__37 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__38 = { 0, 6, 0, fmt_89, 0 };
    static cilist feq_gen_io_d__47 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__49 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__50 = { 0, 0, 0, fmt_87, 0 };
    static cilist feq_gen_io_d__54 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__55 = { 0, 0, 0, fmt_87, 0 };
    static cilist feq_gen_io_d__56 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__57 = { 0, 0, 0, fmt_90, 0 };
    static cilist feq_gen_io_d__58 = { 0, 0, 0, fmt_98, 0 };
    static cilist feq_gen_io_d__59 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__60 = { 0, 0, 0, fmt_91, 0 };
    static cilist feq_gen_io_d__61 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__62 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__65 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__66 = { 0, 0, 0, fmt_87, 0 };
    static cilist feq_gen_io_d__68 = { 0, 0, 0, fmt_79, 0 };
    static cilist feq_gen_io_d__70 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__72 = { 0, 0, 0, fmt_81, 0 };
    static cilist feq_gen_io_d__74 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__75 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__92 = { 0, 0, 0, fmt_93, 0 };
    static cilist feq_gen_io_d__93 = { 0, 0, 0, fmt_65, 0 };
    static cilist feq_gen_io_d__94 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__96 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__98 = { 0, 0, 0, fmt_67, 0 };
    static cilist feq_gen_io_d__100 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__102 = { 0, 0, 0, fmt_69, 0 };
    static cilist feq_gen_io_d__122 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__130 = { 0, 0, 0, fmt_71, 0 };
    static cilist feq_gen_io_d__132 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__133 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__136 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__141 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__148 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__157 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__158 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__166 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__169 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__177 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__181 = { 0, 0, 0, fmt_97, 0 };
    static cilist feq_gen_io_d__182 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__184 = { 0, 0, 0, fmt_97, 0 };
    static cilist feq_gen_io_d__185 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__186 = { 0, 0, 0, fmt_97, 0 };
    static cilist feq_gen_io_d__187 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__190 = { 0, 0, 0, fmt_75, 0 };
    static cilist feq_gen_io_d__192 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__193 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__196 = { 0, 0, 0, fmt_97, 0 };
    static cilist feq_gen_io_d__197 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__198 = { 0, 0, 0, fmt_75, 0 };
    static cilist feq_gen_io_d__207 = { 0, 0, 0, fmt_77, 0 };
    static cilist feq_gen_io_d__208 = { 0, 0, 0, fmt_86, 0 };
    static cilist feq_gen_io_d__209 = { 0, 0, 0, fmt_88, 0 };
    static cilist feq_gen_io_d__210 = { 0, 0, 0, fmt_95, 0 };
    static cilist feq_gen_io_d__211 = { 0, 0, 0, fmt_96, 0 };
    static cilist feq_gen_io_d__212 = { 0, 0, 0, fmt_96, 0 };
    static cilist feq_gen_io_d__213 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__214 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Compute the function tables needed to define the flow */
/*     for an underflow gate. */
/* SOURCE ufgate.for:514 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE ufgate.for:516 */
/*<       integereflag,stdin,stdout,stdtab >*/
/* SOURCE ufgate.for:517 */
/*<       integertabdir(*) >*/
/* SOURCE ufgate.for:518 */
/*<       realgrav >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     GRAV   - value of acceleration due to gravity */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     TABDIR - Table directory to remember table numbers */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE ufgate.for:529 */
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
/* INCLUDE ufgate.for:530 */
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
/* INCLUDE ufgate.for:531 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE ufgate.for:532 */
/*     Common block for underflow gate computations.  These values */
/*     are often used in residual functions. */
/* SOURCE ufgate.cmn:4 */
/*<       integerapptab,deptab >*/
/* SOURCE ufgate.cmn:6 */
/*<        >*/
/* SOURCE ufgate.cmn:11 */
/*<        >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE ufgate.for:535 */
/*<       integermaxn >*/
/* SOURCE ufgate.for:536 */
/*<       parameter(maxn=4) >*/
/* SOURCE ufgate.for:537 */
/*<        >*/
/* SOURCE ufgate.for:540 */
/*<       integertab2d(pmxnhg),item_start(maxn),item_end(maxn) >*/
/* SOURCE ufgate.for:541 */
/*<        >*/
/* SOURCE ufgate.for:553 */
/*<       real*8easting,northing >*/
/* SOURCE ufgate.for:554 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE ufgate.for:560 */
/*<       intrinsicabs,float,log,sqrt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE ufgate.for:563 */
/*<       integerlenstr >*/
/* SOURCE ufgate.for:564 */
/*<       realfindcc,rsomy3,rsomy4,rswmy3,rswmy4 >*/
/* SOURCE ufgate.for:565 */
/*<       characterput10*10,get_tabid*16 >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE ufgate.for:568 */
/*<        >*/
/*     + + + INPUT FORMATS + + + */
/* 1    FORMAT(7X,I5) */
/* SOURCE ufgate.for:576 */
/*<     2 format(6x,a) >*/
/* SOURCE ufgate.for:577 */
/*<     4 format(7x,i5) >*/
/* SOURCE ufgate.for:578 */
/*<     6 format(7x,i5) >*/
/* SOURCE ufgate.for:579 */
/*<     8 format(9x,f10.0) >*/
/* SOURCE ufgate.for:580 */
/*<    10 format(10x,f10.0) >*/
/* SOURCE ufgate.for:581 */
/*<    12 format(3x,f10.0) >*/
/* SOURCE ufgate.for:582 */
/*<    14 format(6x,i5) >*/
/* SOURCE ufgate.for:583 */
/*<    16 format(7x,f10.0) >*/
/* SOURCE ufgate.for:584 */
/*<    18 format(7x,f10.0) >*/
/* SOURCE ufgate.for:585 */
/*<    19 format(9x,f10.0) >*/
/* SOURCE ufgate.for:586 */
/*<    20 format(8x,f10.0) >*/
/* SOURCE ufgate.for:587 */
/*<    21 format(8x,f10.0) >*/
/* SOURCE ufgate.for:588 */
/*<    22 format(10x,f10.0) >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE ufgate.for:591 */
/*<    50 format(/,' TabId= ',a,' for type 15 table for underflow',' gate.') >*/
/* SOURCE ufgate.for:593 */
/*<    52 format(/,' Label=',a50) >*/
/* SOURCE ufgate.for:594 */
/*<    54 format(/,' Approach section table id= ',a) >*/
/* SOURCE ufgate.for:595 */
/*<    56 format(/,' Departure section table id= ',a) >*/
/* SOURCE ufgate.for:596 */
/*<    58 format(/,' Elevation of gate sill=',f10.3) >*/
/* SOURCE ufgate.for:597 */
/*<    60 format(/,' Total gate opening width=',f10.3) >*/
/* SOURCE ufgate.for:598 */
/*<    62 format(/,' Discharge coefficient for approach to gate=',f10.3) >*/
/* SOURCE ufgate.for:599 */
/*<    64 format(/,' Contraction coefficient table id= ',a) >*/
/* SOURCE ufgate.for:600 */
/*<    65 format(/,' *ERR:774* Must have at least two gate openings.') >*/
/* SOURCE ufgate.for:601 */
/*<    66 format(/,' Minimum partial free drop=',f10.5) >*/
/* SOURCE ufgate.for:602 */
/*<    67 format(/,' Partial free drop at power breakpoint=',f10.5) >*/
/* SOURCE ufgate.for:603 */
/*<    68 format(/,' Limiting partial free drop=',f10.3) >*/
/* SOURCE ufgate.for:604 */
/*<    69 format(/,' Final local power for partial free drops=',f10.3) >*/
/* SOURCE ufgate.for:605 */
/*<    70  >*/
/* SOURCE ufgate.for:607 */
/*<    71  >*/
/* SOURCE ufgate.for:609 */
/*<    72  >*/
/* SOURCE ufgate.for:612 */
/*<    74  >*/
/* SOURCE ufgate.for:620 */
/*<    75 format(1x,f8.4,f8.3,f8.3,f8.3,3x,a2,a6,1x,a10,f6.2,f8.3) >*/
/* SOURCE ufgate.for:621 */
/*<    76 format(1x,f8.4,f8.3,f8.3,f8.3,3x,a2,a6,1x,a10,6x,f8.3) >*/
/* SOURCE ufgate.for:622 */
/*<    77  >*/
/* SOURCE ufgate.for:624 */
/*<    79 format(/,' Free weir to free orifice transition fraction=',f8.2) >*/
/* SOURCE ufgate.for:625 */
/*<    80 format(/,' Maximum upstream head=',f8.2) >*/
/* SOURCE ufgate.for:626 */
/*<    81 format(/,' Minimum non-zero upstream head=',f8.2) >*/
/* SOURCE ufgate.for:627 */
/*<    82 format(/,' Linear interpolation precision=',f8.3) >*/
/* SOURCE ufgate.for:628 */
/*<    86  >*/
/* SOURCE ufgate.for:631 */
/*<    87 format(/,' *ERR:607* TabId missing or negative.') >*/
/* SOURCE ufgate.for:632 */
/*<    88 format(/' Root-mean-squared error=',f6.3,' N in sample=',i5) >*/
/* SOURCE ufgate.for:633 */
/*<    89 format('  Processing UFGATE TabId= ',a) >*/
/* SOURCE ufgate.for:634 */
/*<    90  >*/
/* SOURCE ufgate.for:636 */
/*<    91 format(/,' *ERR:713* Gate opening width=',f10.3,' <= 0.0') >*/
/* SOURCE ufgate.for:637 */
/*<    92 format(/,' *ERR:714* Approach loss Cd <=0.0 or > 1.0') >*/
/* SOURCE ufgate.for:638 */
/*<    93 format(/,' *ERR:715* Contraction coef.=',f10.3,' <= 0.0 or > 1.0') >*/
/* SOURCE ufgate.for:639 */
/*<    94 format(/,' *ERR:716* In UFGATE: FLAG=',i3,' No solution',a) >*/
/* SOURCE ufgate.for:640 */
/*<    95  >*/
/* SOURCE ufgate.for:642 */
/*<    96 format(f10.3,1x,a16,3f10.6) >*/
/* SOURCE ufgate.for:643 */
/*<    97 format(/,' *BUG:XXX* In UFGATE no root in 16 tries for:',a) >*/
/* SOURCE ufgate.for:644 */
/*<    98  >*/
/* SOURCE ufgate.for:646 */
/*<    99  >*/
/* *********************************************************************** */
/*     Define the linear interpolation precision tables. */
/* SOURCE ufgate.for:650 */
/*<       key='10001' >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> tabdir(feq_storage_tabdir, 1);

    /* Function Body */
/* L2: */
/* L4: */
/* L6: */
/* L8: */
/* L10: */
/* L12: */
/* L14: */
/* L16: */
/* L18: */
/* L19: */
/* L20: */
/* L21: */
/* L22: */
/* L50: */
/* L52: */
/* L54: */
/* L56: */
/* L58: */
/* L60: */
/* L62: */
/* L64: */
/* L65: */
/* L66: */
/* L67: */
/* L68: */
/* L69: */
/* L70: */
/* L71: */
/* L72: */
/* L74: */
/* L75: */
/* L76: */
/* L77: */
/* L79: */
/* L80: */
/* L81: */
/* L82: */
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
    s_copy(key, const_cast<char*>("10001"), (ftnlen)16, (ftnlen)5);
/* SOURCE ufgate.for:651 */
/*<       callget_internal_tab_number(stdout,key,eflag,tablt) >*/
    feq_gen_get_internal_tab_number_d_(stdout, key, eflag, &tablt, (ftnlen)16);
/* SOURCE ufgate.for:655 */
/*<       tablt=ftpnt(tablt) >*/
    tablt = ftablea_1.ftpnt[tablt - 1];
/* SOURCE ufgate.for:656 */
/*<       key='10002' >*/
    s_copy(key, const_cast<char*>("10002"), (ftnlen)16, (ftnlen)5);
/* SOURCE ufgate.for:657 */
/*<       callget_internal_tab_number(stdout,key,eflag,tabgt) >*/
    feq_gen_get_internal_tab_number_d_(stdout, key, eflag, &tabgt, (ftnlen)16);
/* SOURCE ufgate.for:661 */
/*<       tabgt=ftpnt(tabgt) >*/
    tabgt = ftablea_1.ftpnt[tabgt - 1];
/* SOURCE ufgate.for:662 */
/*<       if(tablt.lt.1.or.tabgt.lt.1)then >*/
    if (tablt < 1 || tabgt < 1) {
/* SOURCE ufgate.for:663 */
/*<       write(stdout,99) >*/
	feq_gen_io_d__33.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__33);
	e_wsfe();
/* SOURCE ufgate.for:664 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE ufgate.for:665 */
/*<       return >*/
	return 0;
/* SOURCE ufgate.for:666 */
/*<       endif >*/
    }
/* SOURCE ufgate.for:667 */
/*<       g=grav >*/
    ufcom_1.g = *grav;
/* SOURCE ufgate.for:668 */
/*<       twog=2.*grav >*/
    ufcom_1.twog = static_cast<double>(*grav) * (float)2.;
/* SOURCE ufgate.for:669 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgate.for:672 */
/*<       callread_tabid(stdout,line,'TAB',eflag,tabid,tab) >*/
    feq_gen_read_tabid_d_(stdout, line, const_cast<char*>("TAB"), eflag, tabid, &tab, (ftnlen)80, (ftnlen)
	    3, (ftnlen)16);
/* SOURCE ufgate.for:675 */
/*<       write(stdout,50)tabid(1:lenstr(tabid)) >*/
    feq_gen_io_d__37.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__37);
    do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
    e_wsfe();
/* SOURCE ufgate.for:676 */
/*<       write(*,89)tabid(1:lenstr(tabid)) >*/
    s_wsfe(&feq_gen_io_d__38);
    do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
    e_wsfe();
/* SOURCE ufgate.for:678 */
/*<       calltabchk(stdout,pmxtab,tab,tabdir,eflag) >*/
    tabchk_(stdout, &feq_gen_c_d_10002, &tab, &tabdir[1], eflag);
/*     Get location items that may be present. If they are not present */
/*     they will be set to default values.  The default requests FEQUTL */
/*     to omit the items. */
/* SOURCE ufgate.for:685 */
/*<       callget_lctn_items(stdin,stdout,eflag) >*/
    feq_gen_get_lctn_items_d_(stdin, stdout, eflag);
/* SOURCE ufgate.for:687 */
/*<        >*/
    feq_gen_set_lctn_items_d_(zone, hgrid, vdatum, unitsys, basis, &easting, &northing,
	     (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE ufgate.for:691 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgate.for:694 */
/*<       read(line,2,err=991)lab2 >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, lab2, (ftnlen)50);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ufgate.for:695 */
/*<       write(stdout,52)lab2 >*/
    feq_gen_io_d__47.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__47);
    do_fio(&feq_gen_c_d_1, lab2, (ftnlen)50);
    e_wsfe();
/* SOURCE ufgate.for:697 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgate.for:700 */
/*<       callread_tabid(stdout,line,'APP',eflag,apptabid,apptab) >*/
    feq_gen_read_tabid_d_(stdout, line, const_cast<char*>("APP"), eflag, apptabid, &ufcom_1.apptab, (
	    ftnlen)80, (ftnlen)3, (ftnlen)16);
/* SOURCE ufgate.for:703 */
/*<       write(stdout,54)apptabid(1:lenstr(apptabid)) >*/
    feq_gen_io_d__49.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__49);
    do_fio(&feq_gen_c_d_1, apptabid, lenstr_(apptabid, (ftnlen)16));
    e_wsfe();
/* SOURCE ufgate.for:705 */
/*<       if(apptab.le.0)then >*/
    if (ufcom_1.apptab <= 0) {
/* SOURCE ufgate.for:706 */
/*<       write(stdout,87) >*/
	feq_gen_io_d__50.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__50);
	e_wsfe();
/* SOURCE ufgate.for:707 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE ufgate.for:708 */
/*<       else >*/
    } else {
/* SOURCE ufgate.for:709 */
/*<       ef=0 >*/
	ef = 0;
/* SOURCE ufgate.for:710 */
/*<       tptab=apptab >*/
	tptab = ufcom_1.apptab;
/* SOURCE ufgate.for:711 */
/*<       callchktab(12,stdout,ftpnt,mftnum,apptab,ef) >*/
	chktab_(&feq_gen_c_d_12, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &ufcom_1.apptab, &
		ef);
/* SOURCE ufgate.for:715 */
/*<       if(ef.eq.0)then >*/
	if (ef == 0) {
/*         Find the invert elevation from the table */
/* SOURCE ufgate.for:717 */
/*<       callfndelv(tptab,stdout,eflag,z1b) >*/
	    fndelv_(&tptab, stdout, eflag, &ufcom_1.z1b);
/* SOURCE ufgate.for:720 */
/*<       else >*/
	} else {
/* SOURCE ufgate.for:721 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE ufgate.for:722 */
/*<       endif >*/
	}
/* SOURCE ufgate.for:723 */
/*<       endif >*/
    }
/* SOURCE ufgate.for:726 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgate.for:729 */
/*<       callread_tabid(stdout,line,'DEP',eflag,deptabid,deptab) >*/
    feq_gen_read_tabid_d_(stdout, line, const_cast<char*>("DEP"), eflag, deptabid, &ufcom_1.deptab, (
	    ftnlen)80, (ftnlen)3, (ftnlen)16);
/* SOURCE ufgate.for:732 */
/*<       write(stdout,56)deptabid(1:lenstr(deptabid)) >*/
    feq_gen_io_d__54.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__54);
    do_fio(&feq_gen_c_d_1, deptabid, lenstr_(deptabid, (ftnlen)16));
    e_wsfe();
/* SOURCE ufgate.for:734 */
/*<       if(deptab.le.0)then >*/
    if (ufcom_1.deptab <= 0) {
/* SOURCE ufgate.for:735 */
/*<       write(stdout,87) >*/
	feq_gen_io_d__55.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__55);
	e_wsfe();
/* SOURCE ufgate.for:736 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE ufgate.for:737 */
/*<       else >*/
    } else {
/* SOURCE ufgate.for:738 */
/*<       ef=0 >*/
	ef = 0;
/* SOURCE ufgate.for:739 */
/*<       tptab=deptab >*/
	tptab = ufcom_1.deptab;
/* SOURCE ufgate.for:740 */
/*<       callchktab(1,stdout,ftpnt,mftnum,deptab,ef) >*/
	chktab_(&feq_gen_c_d_1, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &ufcom_1.deptab, &
		ef);
/* SOURCE ufgate.for:744 */
/*<       if(ef.eq.0)then >*/
	if (ef == 0) {
/*         Find the invert elevation from the table */
/* SOURCE ufgate.for:746 */
/*<       callfndelv(tptab,stdout,eflag,z4b) >*/
	    fndelv_(&tptab, stdout, eflag, &ufcom_1.z4b);
/* SOURCE ufgate.for:749 */
/*<       else >*/
	} else {
/* SOURCE ufgate.for:750 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE ufgate.for:751 */
/*<       endif >*/
	}
/* SOURCE ufgate.for:752 */
/*<       endif >*/
    }
/*     For the moment make Z3B the same as Z4B.  Note that */
/*     the table called the departure table will give the */
/*     cross section that defines the upstream hydrostatic pressure */
/*     force on the control volume downstream of the underflow */
/*     gate.  An optional table, to be added later will give */
/*     the table for computing the momentum flux exiting from the */
/*     control volume. */
/* SOURCE ufgate.for:762 */
/*<       z3b=z4b >*/
    ufcom_1.z3b = ufcom_1.z4b;
/* SOURCE ufgate.for:764 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgate.for:767 */
/*<       read(line,8,err=991)z2b >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.z2b, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ufgate.for:769 */
/*<       write(stdout,58)z2b >*/
    feq_gen_io_d__56.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__56);
    do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.z2b, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE ufgate.for:771 */
/*<       if(z2b.lt.z4b)then >*/
    if (ufcom_1.z2b < ufcom_1.z4b) {
/* SOURCE ufgate.for:772 */
/*<       write(stdout,90)z2b,z4b >*/
	feq_gen_io_d__57.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__57);
	do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.z2b, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.z4b, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE ufgate.for:773 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE ufgate.for:774 */
/*<       endif >*/
    }
/* SOURCE ufgate.for:775 */
/*<       if(z2b.lt.z1b)then >*/
    if (ufcom_1.z2b < ufcom_1.z1b) {
/* SOURCE ufgate.for:776 */
/*<       write(stdout,98)z2b,z1b >*/
	feq_gen_io_d__58.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__58);
	do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.z2b, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.z1b, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE ufgate.for:777 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE ufgate.for:778 */
/*<       endif >*/
    }
/* SOURCE ufgate.for:780 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgate.for:783 */
/*<       read(line,10,err=991)bg >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.bg, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ufgate.for:784 */
/*<       write(stdout,60)bg >*/
    feq_gen_io_d__59.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__59);
    do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.bg, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE ufgate.for:786 */
/*<       if(bg.le.0.0)then >*/
    if (ufcom_1.bg <= (float)0.) {
/* SOURCE ufgate.for:787 */
/*<       write(stdout,91)bg >*/
	feq_gen_io_d__60.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__60);
	do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.bg, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE ufgate.for:788 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE ufgate.for:789 */
/*<       endif >*/
    }
/* SOURCE ufgate.for:791 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgate.for:794 */
/*<       read(line,12,err=991)cd >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.cd, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ufgate.for:795 */
/*<       write(stdout,62)cd >*/
    feq_gen_io_d__61.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__61);
    do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.cd, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE ufgate.for:796 */
/*<       if(cd.le.0.0.or.cd.gt.1.0)then >*/
    if (ufcom_1.cd <= (float)0. || ufcom_1.cd > (float)1.) {
/* SOURCE ufgate.for:797 */
/*<       write(stdout,92)cd >*/
	feq_gen_io_d__62.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__62);
	do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.cd, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE ufgate.for:798 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE ufgate.for:799 */
/*<       endif >*/
    }
/* SOURCE ufgate.for:802 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgate.for:805 */
/*<       callread_tabid(stdout,line,'CCTAB',eflag,cctabid,cctab) >*/
    feq_gen_read_tabid_d_(stdout, line, const_cast<char*>("CCTAB"), eflag, cctabid, &cctab, (ftnlen)80, (
	    ftnlen)5, (ftnlen)16);
/* SOURCE ufgate.for:808 */
/*<       write(stdout,64)cctabid(1:lenstr(cctabid)) >*/
    feq_gen_io_d__65.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__65);
    do_fio(&feq_gen_c_d_1, cctabid, lenstr_(cctabid, (ftnlen)16));
    e_wsfe();
/* SOURCE ufgate.for:809 */
/*<       if(cctab.lt.0)then >*/
    if (cctab < 0) {
/* SOURCE ufgate.for:810 */
/*<       write(stdout,87) >*/
	feq_gen_io_d__66.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__66);
	e_wsfe();
/* SOURCE ufgate.for:811 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE ufgate.for:812 */
/*<       elseif(cctab.gt.0)then >*/
    } else if (cctab > 0) {
/* SOURCE ufgate.for:813 */
/*<       callchktab(2,stdout,ftpnt,mftnum,cctab,eflag) >*/
	chktab_(&feq_gen_c_d_2, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &cctab, eflag);
/* SOURCE ufgate.for:817 */
/*<       endif >*/
    }
/*     Get the size of the transition between FW and FO flow. */
/* SOURCE ufgate.for:820 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgate.for:823 */
/*<       read(line,19,err=991)fwfotr >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&fwfotr, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ufgate.for:824 */
/*<       if(fwfotr.eq.0.0)fwfotr=0.1 >*/
    if (fwfotr == (float)0.) {
	fwfotr = (float).1;
    }
/* SOURCE ufgate.for:825 */
/*<       write(stdout,79)fwfotr >*/
    feq_gen_io_d__68.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__68);
    do_fio(&feq_gen_c_d_1, (char *)&fwfotr, (ftnlen)sizeof(real));
    e_wsfe();
/*     Get the maximum upstream head */
/* SOURCE ufgate.for:828 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgate.for:831 */
/*<       read(line,20,err=991)maxhu >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&maxhu, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ufgate.for:832 */
/*<       write(stdout,80)maxhu >*/
    feq_gen_io_d__70.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__70);
    do_fio(&feq_gen_c_d_1, (char *)&maxhu, (ftnlen)sizeof(real));
    e_wsfe();
/*     Get the smallest non-zero upstream head */
/* SOURCE ufgate.for:835 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgate.for:838 */
/*<       read(line,21,err=991)minhu >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&minhu, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ufgate.for:839 */
/*<       if(minhu.eq.0.0)minhu=0.1 >*/
    if (minhu == (float)0.) {
	minhu = (float).1;
    }
/* SOURCE ufgate.for:840 */
/*<       write(stdout,81)minhu >*/
    feq_gen_io_d__72.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__72);
    do_fio(&feq_gen_c_d_1, (char *)&minhu, (ftnlen)sizeof(real));
    e_wsfe();
/*     Get the global linear interpolation precisions */
/* SOURCE ufgate.for:843 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgate.for:846 */
/*<       read(line,22,err=991)liprec >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&liprec, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ufgate.for:847 */
/*<       if(liprec.eq.0.0)liprec=0.02 >*/
    if (liprec == (float)0.) {
	liprec = (float).02;
    }
/* SOURCE ufgate.for:848 */
/*<       write(stdout,82)liprec >*/
    feq_gen_io_d__74.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__74);
    do_fio(&feq_gen_c_d_1, (char *)&liprec, (ftnlen)sizeof(real));
    e_wsfe();
/*     Process the gate opening table. */
/* SOURCE ufgate.for:851 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgate.for:854 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__75.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__75);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE ufgate.for:855 */
/*<       write(stdout,'(A)')line >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
    e_wsfe();
/* SOURCE ufgate.for:856 */
/*<       just='RIGHT' >*/
    s_copy(just, const_cast<char*>("RIGHT"), (ftnlen)5, (ftnlen)5);
/* SOURCE ufgate.for:857 */
/*<        >*/
    feq_gen_get_item_limits_d_(stdout, line, &feq_gen_c_d_4, just, &nitem, feq_gen_item_start_d_, 
	    feq_gen_item_end_d_, (ftnlen)80, (ftnlen)5);
/*     Set the  column width */
/* SOURCE ufgate.for:861 */
/*<       colwidth=item_end(2)-item_start(2)+1 >*/
    colwidth = feq_gen_item_end_d_[1] - feq_gen_item_start_d_[1] + 1;
/* SOURCE ufgate.for:864 */
/*<       oldhg=0.0 >*/
    oldhg = (float)0.;
/* SOURCE ufgate.for:865 */
/*<       nhg=1 >*/
    nhg = 1;
/* SOURCE ufgate.for:866 */
/*<       idlen=0 >*/
    idlen = 0;
/* SOURCE ufgate.for:867 */
/*<   100 continue >*/
L100:
/* SOURCE ufgate.for:868 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgate.for:871 */
/*<        >*/
    feq_gen_read_ufgate_items_d_(stdout, line, &nitem, feq_gen_item_start_d_, feq_gen_item_end_d_, eflag,
	     &idlen, &hgvec[nhg - 1], &tab2d[nhg - 1], &ccval[nhg - 1], &
	    angle[nhg - 1], (ftnlen)80);
/*        READ(LINE,'(F10.0, I10, 4F10.0)') HGVEC(NHG), TAB2D(NHG), */
/*     A                      CCVAL(NHG), ANGLE(NHG) */
/*     B                      MNHVEC(NHG), LIPVEC(NHG) */
/* SOURCE ufgate.for:879 */
/*<       mnhvec(nhg)=0.0 >*/
    mnhvec[nhg - 1] = (float)0.;
/* SOURCE ufgate.for:880 */
/*<       lipvec(nhg)=0.0 >*/
    lipvec[nhg - 1] = (float)0.;
/* SOURCE ufgate.for:881 */
/*<       if(hgvec(nhg).le.oldhg)then >*/
    if (hgvec[nhg - 1] <= oldhg) {
/*         Input complete. */
/* SOURCE ufgate.for:883 */
/*<       nhg=nhg-1 >*/
	--nhg;
/* SOURCE ufgate.for:884 */
/*<       else >*/
    } else {
/* SOURCE ufgate.for:885 */
/*<       oldhg=hgvec(nhg) >*/
	oldhg = hgvec[nhg - 1];
/* SOURCE ufgate.for:886 */
/*<       if(mnhvec(nhg).eq.0.0)then >*/
	if (mnhvec[nhg - 1] == (float)0.) {
/* SOURCE ufgate.for:887 */
/*<       mnhvec(nhg)=minhu >*/
	    mnhvec[nhg - 1] = minhu;
/* SOURCE ufgate.for:888 */
/*<       endif >*/
	}
/* SOURCE ufgate.for:889 */
/*<       if(lipvec(nhg).eq.0.0)then >*/
	if (lipvec[nhg - 1] == (float)0.) {
/* SOURCE ufgate.for:890 */
/*<       lipvec(nhg)=liprec >*/
	    lipvec[nhg - 1] = liprec;
/* SOURCE ufgate.for:891 */
/*<       endif >*/
	}
/* SOURCE ufgate.for:892 */
/*<       id=get_tabid(tab2d(nhg)) >*/
	feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &tab2d[nhg - 1]);
	s_copy(id, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE ufgate.for:893 */
/*<       idout=' ' >*/
	s_copy(idout, const_cast<char*>(" "), (ftnlen)32, (ftnlen)1);
/* SOURCE ufgate.for:894 */
/*<       idout(colwidth-idlen+1:colwidth)=id(1:idlen) >*/
	feq_gen_i_d_1 = colwidth - idlen;
	s_copy(idout + feq_gen_i_d_1, id, colwidth - feq_gen_i_d_1, idlen);
/* SOURCE ufgate.for:895 */
/*<        >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(F10.3,A,F10.3,F10.1,F10.2,F10.3)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&hgvec[nhg - 1], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, idout, colwidth);
	do_fio(&feq_gen_c_d_1, (char *)&ccval[nhg - 1], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&angle[nhg - 1], (ftnlen)sizeof(real));
	e_wsfe();
/*     C           MNHVEC(NHG), LIPVEC(NHG) */
/* SOURCE ufgate.for:899 */
/*<       calltabchk(stdout,pmxtab,tab2d(nhg),tabdir,eflag) >*/
	tabchk_(stdout, &feq_gen_c_d_10002, &tab2d[nhg - 1], &tabdir[1], eflag);
/* SOURCE ufgate.for:902 */
/*<       if(cctab.eq.0.0)then >*/
	if ((real) cctab == (float)0.) {
/*           If no table is given for contraction coefficient, then */
/*           a value must be given by the user. */
/* SOURCE ufgate.for:905 */
/*<       if(ccval(nhg).le.0.0.or.ccval(nhg).gt.1.0)then >*/
	    if (ccval[nhg - 1] <= (float)0. || ccval[nhg - 1] > (float)1.) {
/* SOURCE ufgate.for:906 */
/*<       write(stdout,93)ccval(nhg) >*/
		feq_gen_io_d__92.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__92);
		do_fio(&feq_gen_c_d_1, (char *)&ccval[nhg - 1], (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE ufgate.for:907 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE ufgate.for:908 */
/*<       endif >*/
	    }
/* SOURCE ufgate.for:909 */
/*<       endif >*/
	}
/* SOURCE ufgate.for:910 */
/*<       nhg=nhg+1 >*/
	++nhg;
/* SOURCE ufgate.for:911 */
/*<       goto100 >*/
	goto L100;
/* SOURCE ufgate.for:912 */
/*<       endif >*/
    }
/* SOURCE ufgate.for:914 */
/*<       if(nhg.lt.2)then >*/
    if (nhg < 2) {
/* SOURCE ufgate.for:915 */
/*<       write(stdout,65) >*/
	feq_gen_io_d__93.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__93);
	e_wsfe();
/* SOURCE ufgate.for:916 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE ufgate.for:917 */
/*<       endif >*/
    }
/*     INPUT THE FACTORS CONTROLLING THE DISTRIBUTION OF DROPS */
/* SOURCE ufgate.for:921 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgate.for:924 */
/*<       write(stdout,*)' ' >*/
    feq_gen_io_d__94.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__94);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" "), (ftnlen)1);
    e_wsle();
/* SOURCE ufgate.for:925 */
/*<       write(stdout,'(A)')line >*/
    feq_gen_ci_d_1.cierr = 0;
    feq_gen_ci_d_1.ciunit = *stdout;
    feq_gen_ci_d_1.cifmt = const_cast<char*>("(A)");
    s_wsfe(&feq_gen_ci_d_1);
    do_fio(&feq_gen_c_d_1, line, (ftnlen)80);
    e_wsfe();
/* SOURCE ufgate.for:927 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgate.for:930 */
/*<       read(line,16,err=991)minpfd >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&minpfd, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ufgate.for:931 */
/*<       write(stdout,66)minpfd >*/
    feq_gen_io_d__96.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__96);
    do_fio(&feq_gen_c_d_1, (char *)&minpfd, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE ufgate.for:933 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgate.for:936 */
/*<       read(line,16,err=991)brkpfd >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&brkpfd, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ufgate.for:937 */
/*<       write(stdout,67)brkpfd >*/
    feq_gen_io_d__98.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__98);
    do_fio(&feq_gen_c_d_1, (char *)&brkpfd, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE ufgate.for:939 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgate.for:942 */
/*<       read(line,18,err=991)limpfd >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&limpfd, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ufgate.for:943 */
/*<       write(stdout,68)limpfd >*/
    feq_gen_io_d__100.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__100);
    do_fio(&feq_gen_c_d_1, (char *)&limpfd, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE ufgate.for:945 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE ufgate.for:948 */
/*<       read(line,16,err=991)finpow >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&finpow, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE ufgate.for:949 */
/*<       write(stdout,69)finpow >*/
    feq_gen_io_d__102.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__102);
    do_fio(&feq_gen_c_d_1, (char *)&finpow, (ftnlen)sizeof(real));
    e_wsfe();
/*     COMPUTE THE PROPORTIONS OF FREE DROP */
/* SOURCE ufgate.for:954 */
/*<       pow=0.5 >*/
    pow = (float).5;
/* SOURCE ufgate.for:955 */
/*<       offset=0.0 >*/
    offset = (float)0.;
/* SOURCE ufgate.for:956 */
/*<        >*/
    lstopf_(stdout, &tablt, &tabgt, &pow, &offset, &minpfd, &brkpfd, &liprec, 
	    &feq_gen_c_d_351, &n, xbrk, eflag);
/* SOURCE ufgate.for:961 */
/*<       work(1)=0.0 >*/
    work[0] = (float)0.;
/* SOURCE ufgate.for:962 */
/*<       do195i=1,n >*/
    feq_gen_i_d_1 = n;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ufgate.for:963 */
/*<       work(i+1)=xbrk(i) >*/
	work[feq_gen_i_d_] = xbrk[feq_gen_i_d_ - 1];
/* SOURCE ufgate.for:964 */
/*<   195 continue >*/
/* L195: */
    }
/* SOURCE ufgate.for:965 */
/*<       nfrac=n+1 >*/
    nfrac = n + 1;
/*      OFFSET = 0.9*BRKPFD */
/* SOURCE ufgate.for:967 */
/*<       offset=0.0 >*/
    offset = (float)0.;
/* SOURCE ufgate.for:968 */
/*<        >*/
    lstopf_(stdout, &tablt, &tabgt, &finpow, &offset, &brkpfd, &limpfd, &
	    liprec, &feq_gen_c_d_351, &n, xbrk, eflag);
/* SOURCE ufgate.for:972 */
/*<       do196i=2,n >*/
    feq_gen_i_d_1 = n;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ufgate.for:973 */
/*<       work(nfrac+i-1)=xbrk(i) >*/
	work[nfrac + feq_gen_i_d_ - 2] = xbrk[feq_gen_i_d_ - 1];
/* SOURCE ufgate.for:974 */
/*<   196 continue >*/
/* L196: */
    }
/* SOURCE ufgate.for:975 */
/*<       nfrac=nfrac+n-1 >*/
    nfrac = nfrac + n - 1;
/*      WORK(N+2) = 0.95 */
/*      WORK(N+3) = 0.975 */
/*      WORK(N+4) = 0.98 */
/*      WORK(N+5) = 0.99 */
/* SOURCE ufgate.for:981 */
/*<       work(nfrac+1)=1.0 >*/
    work[nfrac] = (float)1.;
/* SOURCE ufgate.for:982 */
/*<       nfrac=nfrac+1 >*/
    ++nfrac;
/* SOURCE ufgate.for:984 */
/*<       pfdvec(1)=work(1) >*/
    pfdvec[0] = work[0];
/* SOURCE ufgate.for:985 */
/*<       pfdvec(2)=work(2) >*/
    pfdvec[1] = work[1];
/* SOURCE ufgate.for:986 */
/*<       j=2 >*/
    j = 2;
/* SOURCE ufgate.for:987 */
/*<       do201i=3,nfrac-1 >*/
    feq_gen_i_d_1 = nfrac - 1;
    for (feq_gen_i_d_ = 3; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ufgate.for:988 */
/*<       j=j+1 >*/
	++j;
/* SOURCE ufgate.for:989 */
/*<       pfdvec(j)=0.5*(work(i)+work(i-1)) >*/
	pfdvec[j - 1] = static_cast<double>((static_cast<double>(work[feq_gen_i_d_ - 1]) + work[feq_gen_i_d_ - 2])) * (float).5;
/* SOURCE ufgate.for:990 */
/*<       j=j+1 >*/
	++j;
/* SOURCE ufgate.for:991 */
/*<       pfdvec(j)=work(i) >*/
	pfdvec[j - 1] = work[feq_gen_i_d_ - 1];
/* SOURCE ufgate.for:992 */
/*<   201 continue >*/
/* L201: */
    }
/* SOURCE ufgate.for:993 */
/*<       pfdvec(j+1)=work(nfrac) >*/
    pfdvec[j] = work[nfrac - 1];
/* SOURCE ufgate.for:994 */
/*<       nfrac=j+1 >*/
    nfrac = j + 1;
/*      DO 202 I=1,NFRAC */
/*        WRITE(STDOUT,*) ' I=',I,' PFDVEC(I)=',PFDVEC(I) */
/* 202   CONTINUE */
/* SOURCE ufgate.for:999 */
/*<       if(eflag.ne.0)return >*/
    if (*eflag != 0) {
	return 0;
    }
/*     INPUT OF DATA COMPLETE.  BEGIN THE COMPUTATIONS. */
/* SOURCE ufgate.for:1003 */
/*<       hdatum=z2b >*/
    hdatum = ufcom_1.z2b;
/* SOURCE ufgate.for:1005 */
/*<       dz=z3b-z2b >*/
    ufcom_1.dz = static_cast<double>(ufcom_1.z3b) - ufcom_1.z2b;
/* SOURCE ufgate.for:1007 */
/*<       bigerr=0.0 >*/
    bigerr = (float)0.;
/* SOURCE ufgate.for:1008 */
/*<       rms=0.0 >*/
    rms = (float)0.;
/* SOURCE ufgate.for:1009 */
/*<       nrms=0 >*/
    nrms = 0;
/* SOURCE ufgate.for:1010 */
/*<       oldhg=0.0 >*/
    oldhg = (float)0.;
/* SOURCE ufgate.for:1011 */
/*<       do1000ihg=1,nhg >*/
    feq_gen_i_d_1 = nhg;
    for (ihg = 1; ihg <= feq_gen_i_d_1; ++ihg) {
/* SOURCE ufgate.for:1012 */
/*<       elflag=0 >*/
	elflag = 0;
/* SOURCE ufgate.for:1013 */
/*<       hg=hgvec(ihg) >*/
	ufcom_1.hg = hgvec[ihg - 1];
/* SOURCE ufgate.for:1014 */
/*<       write(hglab,'(''Hg='',F6.3,'':'')')hg >*/
	feq_gen_ici_d_1.icierr = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 10;
	feq_gen_ici_d_1.iciunit = hglab;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("('Hg=',F6.3,':')");
	s_wsfi(&feq_gen_ici_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.hg, (ftnlen)sizeof(real));
	e_wsfi();
/* SOURCE ufgate.for:1015 */
/*<       label=hglab//lab2 >*/
/* Writing concatenation */
	feq_gen_i_d_2[0] = 10, feq_gen_a_d_1[0] = hglab;
	feq_gen_i_d_2[1] = 50, feq_gen_a_d_1[1] = lab2;
	s_cat(label, feq_gen_a_d_1, feq_gen_i_d_2, &feq_gen_c_d_2, (ftnlen)50);
/* SOURCE ufgate.for:1016 */
/*<       minhu=mnhvec(ihg) >*/
	minhu = mnhvec[ihg - 1];
/* SOURCE ufgate.for:1017 */
/*<       prec=lipvec(ihg) >*/
	prec = lipvec[ihg - 1];
/* SOURCE ufgate.for:1018 */
/*<       concc=ccval(ihg) >*/
	concc = ccval[ihg - 1];
/* SOURCE ufgate.for:1019 */
/*<       id=get_tabid(tab2d(ihg)) >*/
	feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &tab2d[ihg - 1]);
	s_copy(id, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE ufgate.for:1020 */
/*<       write(stdout,70)hg,id(1:lenstr(id)) >*/
	feq_gen_io_d__122.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__122);
	do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.hg, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, id, lenstr_(id, (ftnlen)16));
	e_wsfe();
/* SOURCE ufgate.for:1022 */
/*<       ag=bg*hg >*/
	// Original critical-flow setup, with explicit REAL area and speed stores.
        critical_setup = feq::gate_critical_setup(ufcom_1.hg,ufcom_1.bg,ufcom_1.g,
            ufcom_1.twog,ufcom_1.cd,ufcom_1.z2b,ufcom_1.z1b);
        ufcom_1.ag = critical_setup.area;
        ufcom_1.y2 = critical_setup.depth;
        q = critical_setup.flow;
        rhs = critical_setup.specific_energy;
        y = critical_setup.initial_depth;

/* SOURCE ufgate.for:1035 */
/*<       callinvtse(g,stdout,apptab,22,q,rhs,y,eflag) >*/
	invtse_(&ufcom_1.g, stdout, &ufcom_1.apptab, &feq_gen_c_d_22, &q, &rhs, &y, 
		eflag);
/*        Y1FWUL = Y */
/* SOURCE ufgate.for:1039 */
/*<       z1fwul=y+z1b >*/
	
/* SOURCE ufgate.for:1040 */
/*<       h1fwul=z1fwul-hdatum >*/
	h1fwul = feq::gate_upstream_head(y,ufcom_1.z1b,hdatum);
/* SOURCE ufgate.for:1041 */
/*<       hstuff(ihg,1)=h1fwul/hg >*/
	hstuff[ihg - 1] = static_cast<double>(h1fwul) / ufcom_1.hg;
/*       Compute the gate-opening ratio for the free-weir flow limit. */
/* SOURCE ufgate.for:1043 */
/*<       rgfwul=hg/h1fwul >*/
	rgfwul = static_cast<double>(ufcom_1.hg) / h1fwul;
/* SOURCE ufgate.for:1045 */
/*<       write(stdout,71)h1fwul,rgfwul >*/
	feq_gen_io_d__130.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__130);
	do_fio(&feq_gen_c_d_1, (char *)&h1fwul, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&rgfwul, (ftnlen)sizeof(real));
	e_wsfe();
/*        WRITE(STDOUT,*) ' FW/FO boundary at section 1:' */
/*        WRITE(STDOUT,*) ' Y1FWUL=',Y1FWUL, ' H1FWUL=', H1FWUL, */
/*     A                    ' Gate ratio=',RGFWUL */
/*        WRITE(STDOUT,*) ' H1FWUL/HG=',H1FWUL/HG */
/*       Find the non-standard FO flow at the upper limit of */
/*       FW flow.  This flow should be the same as the flow computed */
/*       assuming critical flow.  That is why the FO flow is called */
/*       non-standard. */
/* SOURCE ufgate.for:1058 */
/*<       cc=1.0 >*/
	ufcom_1.cc = (float)1.;
/* SOURCE ufgate.for:1059 */
/*<       callfndfoq(h1fwul,hdatum,qfo) >*/
	fndfoq_(&h1fwul, &hdatum, &qfo);
/* SOURCE ufgate.for:1063 */
/*<       write(stdout,*)' FW flow at its upper limit=',q >*/
	feq_gen_io_d__132.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__132);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" FW flow at its upper limit="), (ftnlen)28);
	do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&q, (ftnlen)sizeof(real));
	e_wsle();
/* SOURCE ufgate.for:1064 */
/*<       write(stdout,*)' Non-standard FO flow=',qfo >*/
	feq_gen_io_d__133.ciunit = *stdout;
	s_wsle(&feq_gen_io_d__133);
	do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" Non-standard FO flow="), (ftnlen)22);
	do_lio(&feq_gen_c_d_4, &feq_gen_c_d_1, (char *)&qfo, (ftnlen)sizeof(real));
	e_wsle();
/*       Compute the water level at section 4 that just initiates */
/*       submergence of the non-standard FO flow. */
/* SOURCE ufgate.for:1068 */
/*<       callfotoso(h1fwul,qfo,hdatum,h4fwul,iflag) >*/
	fotoso_(&h1fwul, &qfo, &hdatum, &h4fwul, &iflag);
/*        WRITE(STDOUT,*) ' Tailwater head for submergence of ', */
/*     A               'non-standard FO flow: H4FWUL=',H4FWUL */
/*        WRITE(STDOUT,*) ' H4FWUL/HG=',H4FWUL/HG */
/* SOURCE ufgate.for:1074 */
/*<       hstuff(ihg,2)=h4fwul/hg >*/
	hstuff[ihg + 39] = static_cast<double>(h4fwul) / ufcom_1.hg;
/* SOURCE ufgate.for:1075 */
/*<       if(iflag.ne.0)then >*/
	if (iflag != 0) {
/* SOURCE ufgate.for:1076 */
/*<       write(stdout,94)iflag,' for nonstandard FO flow tailwater limit.' >*/
	    feq_gen_io_d__136.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__136);
	    do_fio(&feq_gen_c_d_1, (char *)&iflag, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, const_cast<char*>(" for nonstandard FO flow tailwater limit."), (
		    ftnlen)41);
	    e_wsfe();
/* SOURCE ufgate.for:1078 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE ufgate.for:1079 */
/*<       endif >*/
	}
/*       Compute the assumed lower limit of  standard */
/*       FO flow, that is, FO flow with a contraction coefficient */
/*       as defined for FO flow only. */
/* SOURCE ufgate.for:1083 */
/*<       h1foll=h1fwul+fwfotr*hg >*/
	h1foll = static_cast<double>(h1fwul) + static_cast<double>(fwfotr) * ufcom_1.hg;
/*       Find the contraction coefficient at lower limit for FO flow */
/* SOURCE ufgate.for:1086 */
/*<       if(angle(ihg).eq.0.0)then >*/
	if (angle[ihg - 1] == (float)0.) {
/* SOURCE ufgate.for:1087 */
/*<       ccfoll=findcc(hg/h1foll,concc,cctab) >*/
	    feq_gen_r_d_1 = static_cast<double>(ufcom_1.hg) / h1foll;
	    ccfoll = findcc_(&feq_gen_r_d_1, &concc, &cctab);
/* SOURCE ufgate.for:1088 */
/*<       else >*/
	} else {
/* SOURCE ufgate.for:1089 */
/*<       ccfoll=findcc(angle(ihg),concc,cctab) >*/
	    ccfoll = findcc_(&angle[ihg - 1], &concc, &cctab);
/* SOURCE ufgate.for:1090 */
/*<       endif >*/
	}
/*       Find the tailwater level that just initiates submergence of */
/*       the FO flow at its lower limit */
/* SOURCE ufgate.for:1095 */
/*<       cc=ccfoll >*/
	ufcom_1.cc = ccfoll;
/* SOURCE ufgate.for:1096 */
/*<       callfndfoq(h1foll,hdatum,qfree) >*/
	fndfoq_(&h1foll, &hdatum, &qfree);
/*       Now find the level at section 4 that defines */
/*       the limit of free orifice flow. */
/* SOURCE ufgate.for:1102 */
/*<       callfotoso(h1foll,qfree,hdatum,h4foll,iflag) >*/
	fotoso_(&h1foll, &qfree, &hdatum, &h4foll, &iflag);
/* SOURCE ufgate.for:1105 */
/*<       if(iflag.ne.0)then >*/
	if (iflag != 0) {
/* SOURCE ufgate.for:1106 */
/*<       write(stdout,94)iflag,' for lower-limit FO flow tailwater limit.' >*/
	    feq_gen_io_d__141.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__141);
	    do_fio(&feq_gen_c_d_1, (char *)&iflag, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, const_cast<char*>(" for lower-limit FO flow tailwater limit."), (
		    ftnlen)41);
	    e_wsfe();
/* SOURCE ufgate.for:1108 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE ufgate.for:1109 */
/*<       endif >*/
	}
/*        WRITE(STDOUT,*) ' Lower limit of standard FO flows:' */
/*        WRITE(STDOUT,*) ' H1FOLL=',H1FOLL,' H4FOLL=',H4FOLL */
/*        WRITE(STDOUT,*) ' Standard FO flow=',QFREE */
/*       Find the level at section 4  that is at the boundary */
/*       between SW and SO when section 1 is midway between */
/*       head = HG and head = H1FWUL.  Use this level to provide for */
/*       non-linearity of the boundary between SW and SO. */
/* SOURCE ufgate.for:1120 */
/*<       h1swso=0.5*(hg+h1fwul) >*/
	h1swso = static_cast<double>((static_cast<double>(ufcom_1.hg) + h1fwul)) * (float).5;
/* SOURCE ufgate.for:1121 */
/*<       tp=h1swso+hdatum-z1b >*/
	tp = static_cast<double>(static_cast<double>(h1swso) + hdatum) - ufcom_1.z1b;
/* SOURCE ufgate.for:1122 */
/*<        >*/
	xlkt22_(&ufcom_1.apptab, &tp, &ufcom_1.a1, &ufcom_1.tt, &dt, &
		ufcom_1.jt, &ufcom_1.kt, &ufcom_1.dkt, &ufcom_1.beta, &
		ufcom_1.dbeta, &ufcom_1.alpha1, &ufcom_1.dalpha, &ufcom_1.qct)
		;
/* SOURCE ufgate.for:1127 */
/*<        >*/
/* Computing 2nd power */
	// Retain CD*AG through both the numerator and approach-velocity ratio.
            ufcom_1.qsqr = feq::gate_contact_squared_flow(ufcom_1.hg,ufcom_1.ag,ufcom_1.cd,
                h1swso,hdatum,ufcom_1.z2b,ufcom_1.a1,ufcom_1.alpha1,ufcom_1.twog);
/*       Establish the constant values in RSWMY4. */
/* SOURCE ufgate.for:1131 */
/*<       y3=hg+z2b-z3b >*/
	ufcom_1.y3 = static_cast<double>(static_cast<double>(ufcom_1.hg) + ufcom_1.z2b) - ufcom_1.z3b;
/* SOURCE ufgate.for:1132 */
/*<       calllktj(deptab,y3,j4aty3) >*/
	lktj_(&ufcom_1.deptab, &ufcom_1.y3, &ufcom_1.j4aty3);
/*       Estimate initial values to bracket the root. */
/* SOURCE ufgate.for:1137 */
/*<       yleft=z2b+hg-z4b >*/
	yleft = static_cast<double>(static_cast<double>(ufcom_1.z2b) + ufcom_1.hg) - ufcom_1.z4b;
/* SOURCE ufgate.for:1138 */
/*<       yright=h1swso+hdatum-z4b >*/
	yright = static_cast<double>(static_cast<double>(h1swso) + hdatum) - ufcom_1.z4b;
/* SOURCE ufgate.for:1139 */
/*<       callregfal(epsarg,epsf,rswmy4,yleft,yright,y4swso,iflag) >*/
	regfal_(&epscom_1.epsarg, &epscom_1.epsf, rswmy4_, &yleft, &
		yright, &y4swso, &iflag);
/* SOURCE ufgate.for:1143 */
/*<       if(iflag.ne.0)then >*/
	if (iflag != 0) {
/* SOURCE ufgate.for:1144 */
/*<       write(stdout,94)iflag,' for SW to SO boundary at midpoint.' >*/
	    feq_gen_io_d__148.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__148);
	    do_fio(&feq_gen_c_d_1, (char *)&iflag, (ftnlen)sizeof(integer));
	    do_fio(&feq_gen_c_d_1, const_cast<char*>(" for SW to SO boundary at midpoint."), (ftnlen)35);
	    e_wsfe();
/* SOURCE ufgate.for:1145 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE ufgate.for:1146 */
/*<       endif >*/
	}
/* SOURCE ufgate.for:1147 */
/*<       h4swso=y4swso+z4b-hdatum >*/
	h4swso = static_cast<double>(static_cast<double>(y4swso) + ufcom_1.z4b) - hdatum;
/* SOURCE ufgate.for:1148 */
/*<       hstuff(ihg,3)=h4swso/hg >*/
	hstuff[ihg + 79] = static_cast<double>(h4swso) / ufcom_1.hg;
/*       Assign the upstream heads for this gate opening.  The */
/*       ranges are: MINHU to HG, HG to H1FWUL, H1FWUL to H1FOLL, */
/*       and H1FOLL to MAXHU */
/* SOURCE ufgate.for:1153 */
/*<       power=1.5 >*/
	power = (float)1.5;
/* SOURCE ufgate.for:1154 */
/*<       offset=0.0 >*/
	offset = (float)0.;
/* SOURCE ufgate.for:1155 */
/*<       if(minhu.ge.hg)then >*/
	if (minhu >= ufcom_1.hg) {
/* SOURCE ufgate.for:1156 */
/*<       minhu=0.5*hg >*/
	    minhu = static_cast<double>(ufcom_1.hg) * (float).5;
/* SOURCE ufgate.for:1157 */
/*<       endif >*/
	}
/* SOURCE ufgate.for:1158 */
/*<       humin=minhu >*/
	humin = minhu;
/* SOURCE ufgate.for:1159 */
/*<        >*/
	lstopf_(stdout, &tablt, &tabgt, &power, &offset, &humin, &ufcom_1.hg, 
		&prec, &feq_gen_c_d_151, &n, xbrk, eflag);
/* SOURCE ufgate.for:1163 */
/*<       do210i=1,n >*/
	feq_gen_i_d_3 = n;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_3; ++feq_gen_i_d_) {
/* SOURCE ufgate.for:1164 */
/*<       huvec(i)=xbrk(i) >*/
	    huvec[feq_gen_i_d_ - 1] = xbrk[feq_gen_i_d_ - 1];
/* SOURCE ufgate.for:1165 */
/*<   210 continue >*/
/* L210: */
	}
/* SOURCE ufgate.for:1166 */
/*<       nhu=n >*/
	nhu = n;
/* SOURCE ufgate.for:1168 */
/*<        >*/
	lstopf_(stdout, &tablt, &tabgt, &power, &offset, &ufcom_1.hg, &h1fwul,
		 &prec, &feq_gen_c_d_151, &n, xbrk, eflag);
/* SOURCE ufgate.for:1172 */
/*<       if(n.eq.2)then >*/
	if (n == 2) {
/* SOURCE ufgate.for:1173 */
/*<       xbrk(3)=xbrk(2) >*/
	    xbrk[2] = xbrk[1];
/* SOURCE ufgate.for:1174 */
/*<       xbrk(2)=0.5*(xbrk(1)+xbrk(3)) >*/
	    xbrk[1] = static_cast<double>((static_cast<double>(xbrk[0]) + xbrk[2])) * (float).5;
/* SOURCE ufgate.for:1175 */
/*<       n=3 >*/
	    n = 3;
/* SOURCE ufgate.for:1176 */
/*<       endif >*/
	}
/* SOURCE ufgate.for:1177 */
/*<       do212i=2,n >*/
	feq_gen_i_d_3 = n;
	for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_3; ++feq_gen_i_d_) {
/* SOURCE ufgate.for:1178 */
/*<       nhu=nhu+1 >*/
	    ++nhu;
/* SOURCE ufgate.for:1179 */
/*<       huvec(nhu)=xbrk(i) >*/
	    huvec[nhu - 1] = xbrk[feq_gen_i_d_ - 1];
/* SOURCE ufgate.for:1180 */
/*<   212 continue >*/
/* L212: */
	}
/* SOURCE ufgate.for:1181 */
/*<       offset=-cc*hg >*/
	offset = static_cast<double>(-ufcom_1.cc) * ufcom_1.hg;
/*       Flow varies as the .5 power of the head - offset.  However, */
/*       the drop to free flow varies more nearly like the 1.5 power. */
/*       The spacing for the 1.5 power is smaller than for .5 power; */
/*       so we use 1.5 power. */
/* SOURCE ufgate.for:1186 */
/*<       power=1.5 >*/
	power = (float)1.5;
/* SOURCE ufgate.for:1187 */
/*<        >*/
	lstopf_(stdout, &tablt, &tabgt, &power, &offset, &h1fwul, &h1foll, &
		prec, &feq_gen_c_d_151, &n, xbrk, eflag);
/* SOURCE ufgate.for:1191 */
/*<       if(n.eq.2)then >*/
	if (n == 2) {
/* SOURCE ufgate.for:1192 */
/*<       xbrk(3)=xbrk(2) >*/
	    xbrk[2] = xbrk[1];
/* SOURCE ufgate.for:1193 */
/*<       xbrk(2)=0.5*(xbrk(1)+xbrk(3)) >*/
	    xbrk[1] = static_cast<double>((static_cast<double>(xbrk[0]) + xbrk[2])) * (float).5;
/* SOURCE ufgate.for:1194 */
/*<       n=3 >*/
	    n = 3;
/* SOURCE ufgate.for:1195 */
/*<       endif >*/
	}
/* SOURCE ufgate.for:1196 */
/*<       do213i=2,n >*/
	feq_gen_i_d_3 = n;
	for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_3; ++feq_gen_i_d_) {
/* SOURCE ufgate.for:1197 */
/*<       nhu=nhu+1 >*/
	    ++nhu;
/* SOURCE ufgate.for:1198 */
/*<       huvec(nhu)=xbrk(i) >*/
	    huvec[nhu - 1] = xbrk[feq_gen_i_d_ - 1];
/* SOURCE ufgate.for:1199 */
/*<   213 continue >*/
/* L213: */
	}
/* SOURCE ufgate.for:1200 */
/*<       if(oldhg.gt.0.0)then >*/
	if (oldhg > (float)0.) {
/* SOURCE ufgate.for:1201 */
/*<       humax=maxhu*hg/oldhg >*/
	    humax = static_cast<double>(static_cast<double>(maxhu) * ufcom_1.hg) / oldhg;
/* SOURCE ufgate.for:1202 */
/*<       else >*/
	} else {
/* SOURCE ufgate.for:1203 */
/*<       humax=maxhu >*/
	    humax = maxhu;
/* SOURCE ufgate.for:1204 */
/*<       endif >*/
	}
/* SOURCE ufgate.for:1205 */
/*<       if(humax.le.h1foll)then >*/
	if (humax <= h1foll) {
/*         The maximum requested head is less than the head at section */
/*         1 at the lower limit of FO flow. */
/* SOURCE ufgate.for:1208 */
/*<       humax=h1foll*1.10 >*/
	    humax = static_cast<double>(h1foll) * (float)1.1;
/* SOURCE ufgate.for:1209 */
/*<       endif >*/
	}
/* SOURCE ufgate.for:1210 */
/*<       oldhg=hg >*/
	oldhg = ufcom_1.hg;
/* SOURCE ufgate.for:1211 */
/*<        >*/
	lstopf_(stdout, &tablt, &tabgt, &power, &offset, &h1foll, &humax, &
		prec, &feq_gen_c_d_151, &n, xbrk, eflag);
/* SOURCE ufgate.for:1215 */
/*<       do214i=2,n >*/
	feq_gen_i_d_3 = n;
	for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_3; ++feq_gen_i_d_) {
/* SOURCE ufgate.for:1216 */
/*<       nhu=nhu+1 >*/
	    ++nhu;
/* SOURCE ufgate.for:1217 */
/*<       huvec(nhu)=xbrk(i) >*/
	    huvec[nhu - 1] = xbrk[feq_gen_i_d_ - 1];
/* SOURCE ufgate.for:1218 */
/*<   214 continue >*/
/* L214: */
	}
/*        WRITE(STDOUT,*) ' NHU=',NHU */
/*       One-shot modification for computing the Elmhurst Q. gate */
/*       values. */
/*        IF(IHG.EQ.1) THEN */
/* C         One head value. */
/*          NHU = 3 */
/*          HUVEC(1) = 9.52 */
/*          HUVEC(2) = 6.17 */
/*          HUVEC(3) = 8.47 */
/*        ELSEIF(IHG.EQ.2) THEN */
/* C         One head value */
/*          NHU = 4 */
/*          HUVEC(1) = 9.40 */
/*          HUVEC(2) = 6.08 */
/*          HUVEC(3) = 8.33 */
/*          HUVEC(4) = 7.5 */
/*        ENDIF */
/*       Now compute the free flow for each of the upstream heads */
/* SOURCE ufgate.for:1241 */
/*<       do900ihu=1,nhu >*/
	feq_gen_i_d_3 = nhu;
	for (ihu = 1; ihu <= feq_gen_i_d_3; ++ihu) {
/* SOURCE ufgate.for:1242 */
/*<       h1=huvec(ihu)+hdatum-z2b >*/
	    h1 = static_cast<double>(static_cast<double>(huvec[ihu - 1]) + hdatum) - ufcom_1.z2b;
/* SOURCE ufgate.for:1243 */
/*<       y1=h1+z2b-z1b >*/
	    ufcom_1.y1 = static_cast<double>(static_cast<double>(h1) + ufcom_1.z2b) - ufcom_1.z1b;
/* SOURCE ufgate.for:1244 */
/*<       write(stdout,72)huvec(ihu),h1+z2b,y1,hg >*/
	    feq_gen_io_d__157.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__157);
	    do_fio(&feq_gen_c_d_1, (char *)&huvec[ihu - 1], (ftnlen)sizeof(real));
	    feq_gen_r_d_1 = static_cast<double>(h1) + ufcom_1.z2b;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.y1, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.hg, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE ufgate.for:1245 */
/*<       write(stdout,74) >*/
	    feq_gen_io_d__158.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__158);
	    e_wsfe();
/*         Set the flow for zero partial free drop to 0.0 */
/* SOURCE ufgate.for:1247 */
/*<       qmat(ihu,1)=0.0 >*/
	    qmat[ihu - 1] = (float)0.;
/*         Find conditions at section 1 */
/* SOURCE ufgate.for:1249 */
/*<        >*/
	    xlkt22_(&ufcom_1.apptab, &ufcom_1.y1, &ufcom_1.a1, &ufcom_1.tt, &
		    dt, &ufcom_1.jt, &ufcom_1.kt, &ufcom_1.dkt, &ufcom_1.beta,
		     &ufcom_1.dbeta, &ufcom_1.alpha1, &ufcom_1.dalpha, &
		    ufcom_1.qct);
/* SOURCE ufgate.for:1254 */
/*<       if(h1.le.h1fwul)then >*/
	    if (h1 <= h1fwul) {
/*           Flow is free weir flow.   Try linear iteration. */
/* SOURCE ufgate.for:1256 */
/*<       ftype='FW' >*/
		s_copy(ftype, const_cast<char*>("FW"), (ftnlen)2, (ftnlen)2);
/* SOURCE ufgate.for:1257 */
/*<       fac=0.0 >*/
		// Original iteration retains the gate depth until convergence.
        free_weir = feq::gate_free_weir(h1,ufcom_1.cd,ufcom_1.alpha1,
            ufcom_1.bg,ufcom_1.a1,ufcom_1.g,epscom_1.epsarg);
        ufcom_1.y2 = free_weir.depth;
        qfree = free_weir.flow;
        y2fw = ufcom_1.y2;
/*            WRITE(STDOUT,*) ' H1=',H1,' FW Q=', QFREE,' Y2FW=',Y2FW */
/*           Submerged weir flow can transition to submerged orifice */
/*           flow if the water level at section 1 is above the */
/*           elevation of the gate lip. */
/* SOURCE ufgate.for:1276 */
/*<       if(y1+z1b.gt.hg+z2b)then >*/
		if (static_cast<double>(ufcom_1.y1) + ufcom_1.z1b > static_cast<double>(ufcom_1.hg) + ufcom_1.z2b) {
/*             Find the tailwater level that causes the water to */
/*             contact the lip.  That is, when Y3 + Z3B = HG + Z2B, thus */
/*             Y3 = HG + Z2B - Z3B.  Find square of the flow at this */
/*             condition. */
/* SOURCE ufgate.for:1282 */
/*<       qsqr=twog*(ag*cd)**2*(z1b+y1-hg-z2b)/(1.0-alpha1*(cd*ag/a1)**2) >*/
/* Computing 2nd power */
		    // Retain CD*AG through both the numerator and approach-velocity ratio.
            ufcom_1.qsqr = feq::gate_contact_squared_flow(ufcom_1.hg,ufcom_1.ag,ufcom_1.cd,
                ufcom_1.y1,ufcom_1.z1b,ufcom_1.z2b,ufcom_1.a1,ufcom_1.alpha1,ufcom_1.twog);
/*             Establish the constant values in RSWMY4. */
/* SOURCE ufgate.for:1286 */
/*<       y3=hg+z2b-z3b >*/
		    ufcom_1.y3 = static_cast<double>(static_cast<double>(ufcom_1.hg) + ufcom_1.z2b) - ufcom_1.z3b;
/* SOURCE ufgate.for:1287 */
/*<       calllktj(deptab,y3,j4aty3) >*/
		    lktj_(&ufcom_1.deptab, &ufcom_1.y3, &ufcom_1.j4aty3);
/*             The water-surface elevation at section 4 will be */
/*             between the water surface elevation at section 1 */
/*             and the elevation of the gate lip. */
/* SOURCE ufgate.for:1295 */
/*<       yleft=z2b+hg-z4b >*/
		    yleft = static_cast<double>(static_cast<double>(ufcom_1.z2b) + ufcom_1.hg) - ufcom_1.z4b;
/*              FLEFT = RSWMY4(YLEFT) */
/* SOURCE ufgate.for:1297 */
/*<       yright=z1b+y1-z4b >*/
		    yright = static_cast<double>(static_cast<double>(ufcom_1.z1b) + ufcom_1.y1) - ufcom_1.z4b;
/*              FRIGHT = RSWMY4(YRIGHT) */
/*              WRITE(STDOUT,*) ' YLEFT=',YLEFT,' FLEFT=',FLEFT */
/*              WRITE(STDOUT,*) ' YRIGHT=',YRIGHT,' FRIGHT=',FRIGHT */
/* SOURCE ufgate.for:1301 */
/*<       callregfal(epsarg,epsf,rswmy4,yleft,yright,y4sw,iflag) >*/
		    regfal_(&epscom_1.epsarg, &epscom_1.epsf, rswmy4_, &
			    yleft, &yright, &y4sw, &iflag);
/* SOURCE ufgate.for:1305 */
/*<       if(iflag.ne.0)then >*/
		    if (iflag != 0) {
/* SOURCE ufgate.for:1306 */
/*<       write(stdout,94)iflag,' for SW to SO boundary.' >*/
			feq_gen_io_d__166.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__166);
			do_fio(&feq_gen_c_d_1, (char *)&iflag, (ftnlen)sizeof(integer))
				;
			do_fio(&feq_gen_c_d_1, const_cast<char*>(" for SW to SO boundary."), (ftnlen)23);
			e_wsfe();
/* SOURCE ufgate.for:1307 */
/*<       eflag=1 >*/
			*eflag = 1;
/* SOURCE ufgate.for:1308 */
/*<       endif >*/
		    }
/*              RGSW = HG/H1 */
/*              WRITE(STDOUT,*) ' SW/SO boundary at section 4:' */
/*              WRITE(STDOUT,*) ' Y4SW=',Y4SW,' H4SW=',Y4SW + Z4B - Z2B, */
/*     A               ' Gate opening ratio=',RGSW */
/* SOURCE ufgate.for:1315 */
/*<       else >*/
		} else {
/* SOURCE ufgate.for:1316 */
/*<       y4sw=y1+z1b-z4b >*/
		    y4sw = static_cast<double>(static_cast<double>(ufcom_1.y1) + ufcom_1.z1b) - ufcom_1.z4b;
/* SOURCE ufgate.for:1317 */
/*<       endif >*/
		}
/*           Now find the level at section 4 that defines */
/*           the limit of free weir flow, Y4F. Define the constant */
/*           values. */
/* SOURCE ufgate.for:1322 */
/*<       y3=y2fw+z2b-z3b >*/
		ufcom_1.y3 = static_cast<double>(static_cast<double>(y2fw) + ufcom_1.z2b) - ufcom_1.z3b;
/* SOURCE ufgate.for:1323 */
/*<       oldy3=y3 >*/
		oldy3 = ufcom_1.y3;
/* SOURCE ufgate.for:1324 */
/*<       calllktj(deptab,y3,j4aty3) >*/
		lktj_(&ufcom_1.deptab, &ufcom_1.y3, &ufcom_1.j4aty3);
/* SOURCE ufgate.for:1328 */
/*<       qsqr=qfree**2 >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = qfree;
		ufcom_1.qsqr = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/*           The water surface elevation at section 4 will be */
/*           below the elevation at section 1 but above the */
/*           critical elevation at section 2. */
/* SOURCE ufgate.for:1333 */
/*<       yleft=y2fw+z2b-z4b >*/
		yleft = static_cast<double>(static_cast<double>(y2fw) + ufcom_1.z2b) - ufcom_1.z4b;
/* SOURCE ufgate.for:1334 */
/*<       yright=y1+z1b-z4b >*/
		yright = static_cast<double>(static_cast<double>(ufcom_1.y1) + ufcom_1.z1b) - ufcom_1.z4b;
/* SOURCE ufgate.for:1335 */
/*<       callregfal(epsarg,epsf,rswmy4,yleft,yright,y4f,iflag) >*/
		regfal_(&epscom_1.epsarg, &epscom_1.epsf, rswmy4_, &
			yleft, &yright, &y4f, &iflag);
/* SOURCE ufgate.for:1339 */
/*<       if(iflag.gt.0)then >*/
		if (iflag > 0) {
/* SOURCE ufgate.for:1340 */
/*<       write(stdout,94)iflag,' for FW flow tail water limit.' >*/
		    feq_gen_io_d__169.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__169);
		    do_fio(&feq_gen_c_d_1, (char *)&iflag, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, const_cast<char*>(" for FW flow tail water limit."), (ftnlen)
			    30);
		    e_wsfe();
/* SOURCE ufgate.for:1341 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE ufgate.for:1342 */
/*<       endif >*/
		}
/* SOURCE ufgate.for:1343 */
/*<       zw4f=y4f+z4b >*/
		tailwater_levels = feq::gate_tailwater_levels(ufcom_1.y1,ufcom_1.z1b,y4f,ufcom_1.z4b,hdatum);
/* SOURCE ufgate.for:1344 */
/*<       h4f=zw4f-hdatum >*/
		h4f = tailwater_levels.head;
/* SOURCE ufgate.for:1345 */
/*<       fdrop=y1+z1b-zw4f >*/
		fdrop = tailwater_levels.drop;
/*            WRITE(STDOUT,*) ' Tailwater at free weir flow limit:' */
/*            WRITE(STDOUT,*) ' Y4F=',Y4F,' H4F=',H4F */
/*            WRITE(STDOUT,*) ' Submergence ratio on total head:', */
/*     A             H4F/(H1 + ALPHA1*(QFREE/A1)**2/TWOG) */
/*           Compute a check on the energy balance from section 1 to 4. */
/* SOURCE ufgate.for:1353 */
/*<        >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = static_cast<double>(qfree) / ufcom_1.a1;
/* Computing 2nd power */
		feq_gen_r_d_2 = static_cast<double>(qfree) / ufcom_1.a4;
		de1to4 = static_cast<double>(static_cast<double>(h1) + static_cast<double>(static_cast<double>(ufcom_1.alpha1) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / ufcom_1.twog) - 
			(static_cast<double>(h4f) + static_cast<double>(static_cast<double>(ufcom_1.alpha4) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) / ufcom_1.twog);
/* SOURCE ufgate.for:1355 */
/*<       if(de1to4.lt.0.0)elflag=1 >*/
		if (de1to4 < (float)0.) {
		    elflag = 1;
		}
/* SOURCE ufgate.for:1356 */
/*<       qmat(ihu,nfrac)=qfree >*/
		qmat[ihu + nfrac * 151 - 152] = qfree;
/* SOURCE ufgate.for:1357 */
/*<       fdvec(ihu)=fdrop >*/
		fdvec[ihu - 1] = fdrop;
/* SOURCE ufgate.for:1358 */
/*<       char6='  --- ' >*/
		s_copy(char6, const_cast<char*>("  --- "), (ftnlen)6, (ftnlen)6);
/* SOURCE ufgate.for:1359 */
/*<       cq=put10(qfree) >*/
		put10_(feq_gen_ch_d_2, (ftnlen)10, &qfree);
		s_copy(cq, feq_gen_ch_d_2, (ftnlen)10, (ftnlen)10);
/* SOURCE ufgate.for:1360 */
/*<       write(stdout,76)1.00,fdrop,y3+z3b-hdatum,h4f,ftype,char6,cq,de1to4 >*/
		feq_gen_io_d__177.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__177);
		do_fio(&feq_gen_c_d_1, (char *)&c_b259, (ftnlen)sizeof(real));
		stored_gate_drop = static_cast<float>(fdrop);
        do_fio(&feq_gen_c_d_1, (char *)&stored_gate_drop, (ftnlen)sizeof(real));
		feq_gen_r_d_1 = static_cast<double>(static_cast<double>(ufcom_1.y3) + ufcom_1.z3b) - hdatum;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		stored_gate_head = static_cast<float>(h4f);
        do_fio(&feq_gen_c_d_1, (char *)&stored_gate_head, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, ftype, (ftnlen)2);
		do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
		do_fio(&feq_gen_c_d_1, cq, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, (char *)&de1to4, (ftnlen)sizeof(real));
		e_wsfe();
/*            OLDH3 = Y3 + Z3B - HDATUM */
/*           Compute the submerged flows.  They may be of two types: */
/*           SO or SW. */
/* SOURCE ufgate.for:1365 */
/*<       do400j=nfrac-1,2,-1 >*/
		for (j = nfrac - 1; j >= 2; --j) {
/* SOURCE ufgate.for:1366 */
/*<       drop=fdrop*pfdvec(j) >*/
		    submerged_levels = feq::gate_submerged_levels(ufcom_1.y1,ufcom_1.z1b,fdrop,pfdvec[j-1],ufcom_1.z4b,hdatum);
            drop = submerged_levels.drop;
/* SOURCE ufgate.for:1367 */
/*<       zw4=z1b+y1-drop >*/
		    
/* SOURCE ufgate.for:1368 */
/*<       y4=zw4-z4b >*/
		    ufcom_1.y4 = submerged_levels.depth;
/* SOURCE ufgate.for:1369 */
/*<       h4=zw4-hdatum >*/
		    h4 = submerged_levels.head;
/* SOURCE ufgate.for:1370 */
/*<       yleft=oldy3 >*/
		    yleft = oldy3;
/* SOURCE ufgate.for:1371 */
/*<       yright=y4 >*/
		    yright = ufcom_1.y4;
/* SOURCE ufgate.for:1372 */
/*<        >*/
		    xlkt22_(&ufcom_1.deptab, &ufcom_1.y4, &ufcom_1.a4, &
			    ufcom_1.tt, &dt, &ufcom_1.j4, &ufcom_1.kt, &
			    ufcom_1.dkt, &ufcom_1.beta4, &ufcom_1.dbeta, &
			    ufcom_1.alpha4, &ufcom_1.dalpha, &ufcom_1.qct);
/* SOURCE ufgate.for:1377 */
/*<       if(y1+z1b.le.hg+z2b)then >*/
		    if (static_cast<double>(ufcom_1.y1) + ufcom_1.z1b <= static_cast<double>(ufcom_1.hg) + ufcom_1.z2b) 
			    {
/*               Flow can only be submerged weir flow. */
/* SOURCE ufgate.for:1379 */
/*<       ftype='SW' >*/
			s_copy(ftype, const_cast<char*>("SW"), (ftnlen)2, (ftnlen)2);
/* SOURCE ufgate.for:1380 */
/*<       char6='  --- ' >*/
			s_copy(char6, const_cast<char*>("  --- "), (ftnlen)6, (ftnlen)6);
/* SOURCE ufgate.for:1381 */
/*<       callfdroot(yright,rswmy3,epsf,yleft,iflag) >*/
			fdroot_(&yright, rswmy3_, &epscom_1.epsf, &
				yleft, &iflag);
/* SOURCE ufgate.for:1385 */
/*<       if(iflag.eq.1)then >*/
			if (iflag == 1) {
/* SOURCE ufgate.for:1386 */
/*<       write(stdout,97)' SW flow' >*/
			    feq_gen_io_d__181.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__181);
			    do_fio(&feq_gen_c_d_1, const_cast<char*>(" SW flow"), (ftnlen)8);
			    e_wsfe();
/* SOURCE ufgate.for:1387 */
/*<       eflag=1 >*/
			    *eflag = 1;
/* SOURCE ufgate.for:1388 */
/*<       endif >*/
			}
/* SOURCE ufgate.for:1389 */
/*<       callregfal(epsarg,epsf,rswmy3,yleft,yright,y3,iflag) >*/
			regfal_(&epscom_1.epsarg, &epscom_1.epsf, rswmy3_, &yleft, &yright, &ufcom_1.y3, &iflag)
				;
/* SOURCE ufgate.for:1393 */
/*<       if(iflag.ne.0)then >*/
			if (iflag != 0) {
/* SOURCE ufgate.for:1394 */
/*<       write(stdout,94)iflag,' for SW flow.' >*/
			    feq_gen_io_d__182.ciunit = *stdout;
			    s_wsfe(&feq_gen_io_d__182);
			    do_fio(&feq_gen_c_d_1, (char *)&iflag, (ftnlen)sizeof(
				    integer));
			    do_fio(&feq_gen_c_d_1, const_cast<char*>(" for SW flow."), (ftnlen)13);
			    e_wsfe();
/* SOURCE ufgate.for:1395 */
/*<       eflag=1 >*/
			    *eflag = 1;
/* SOURCE ufgate.for:1396 */
/*<       endif >*/
			}
/* SOURCE ufgate.for:1397 */
/*<       q=sqrt(qsqr) >*/
			q = sqrt(ufcom_1.qsqr);
/*                WRITE(STDOUT,*) ' SW Q=',Q,' Y3=',Y3,' IFLAG=',IFLAG */
/* SOURCE ufgate.for:1400 */
/*<       else >*/
		    } else {
/* SOURCE ufgate.for:1401 */
/*<       if(y4.gt.y4sw)then >*/
			if (ufcom_1.y4 > y4sw) {
/*                 Flow is submerged orifice. */
/* SOURCE ufgate.for:1403 */
/*<       rg=hg/h1 >*/
			    rg = static_cast<double>(ufcom_1.hg) / h1;
/* SOURCE ufgate.for:1404 */
/*<       cc=1.0 >*/
			    ufcom_1.cc = (float)1.;
/* SOURCE ufgate.for:1406 */
/*<       at=cd*cc*ag >*/
			    ufcom_1.at = static_cast<double>(static_cast<double>(ufcom_1.cd) * ufcom_1.cc) * ufcom_1.ag;
/* SOURCE ufgate.for:1407 */
/*<       ftype='SO' >*/
			    s_copy(ftype, const_cast<char*>("SO"), (ftnlen)2, (ftnlen)2);
/* SOURCE ufgate.for:1408 */
/*<       write(char6,'(F6.3)')cc >*/
			    feq_gen_ici_d_1.icierr = 0;
			    feq_gen_ici_d_1.icirnum = 1;
			    feq_gen_ici_d_1.icirlen = 6;
			    feq_gen_ici_d_1.iciunit = char6;
			    feq_gen_ici_d_1.icifmt = const_cast<char*>("(F6.3)");
			    s_wsfi(&feq_gen_ici_d_1);
			    do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.cc, (ftnlen)sizeof(
				    real));
			    e_wsfi();
/*                  FLEFT = RSOMY3(YLEFT) */
/*                  WRITE(STDOUT,*) ' YLEFT=',YLEFT,' FLEFT=',FLEFT */
/*                  FRIGHT = RSOMY3(YRIGHT) */
/*                  WRITE(STDOUT,*) ' YRIGHT=',YRIGHT,' FRIGHT=',FRIGHT */
/* SOURCE ufgate.for:1413 */
/*<       callfdroot(yright,rsomy3,epsf,yleft,iflag) >*/
			    fdroot_(&yright, rsomy3_, &epscom_1.epsf, &
				    yleft, &iflag);
/* SOURCE ufgate.for:1417 */
/*<       if(iflag.eq.1)then >*/
			    if (iflag == 1) {
/* SOURCE ufgate.for:1418 */
/*<       write(stdout,97)' SO flow after SW flow' >*/
				feq_gen_io_d__184.ciunit = *stdout;
				s_wsfe(&feq_gen_io_d__184);
				do_fio(&feq_gen_c_d_1, const_cast<char*>(" SO flow after SW flow"), (
					ftnlen)22);
				e_wsfe();
/* SOURCE ufgate.for:1419 */
/*<       eflag=1 >*/
				*eflag = 1;
/* SOURCE ufgate.for:1420 */
/*<       endif >*/
			    }
/* SOURCE ufgate.for:1421 */
/*<       callregfal(epsarg,epsf,rsomy3,yleft,yright,y3,iflag) >*/
			    regfal_(&epscom_1.epsarg, &epscom_1.epsf, rsomy3_, &yleft, &yright, &ufcom_1.y3, &
				    iflag);
/* SOURCE ufgate.for:1425 */
/*<       if(iflag.ne.0)then >*/
			    if (iflag != 0) {
/* SOURCE ufgate.for:1426 */
/*<       write(stdout,94)iflag,' for SO flow after SW flow.' >*/
				feq_gen_io_d__185.ciunit = *stdout;
				s_wsfe(&feq_gen_io_d__185);
				do_fio(&feq_gen_c_d_1, (char *)&iflag, (ftnlen)sizeof(
					integer));
				do_fio(&feq_gen_c_d_1, const_cast<char*>(" for SO flow after SW flow."), (
					ftnlen)27);
				e_wsfe();
/* SOURCE ufgate.for:1427 */
/*<       eflag=1 >*/
				*eflag = 1;
/* SOURCE ufgate.for:1428 */
/*<       endif >*/
			    }
/* SOURCE ufgate.for:1429 */
/*<       q=sqrt(qsqr) >*/
			    q = sqrt(ufcom_1.qsqr);
/* SOURCE ufgate.for:1430 */
/*<       else >*/
			} else {
/*                 Flow is submerged weir. */
/* SOURCE ufgate.for:1432 */
/*<       ftype='SW' >*/
			    s_copy(ftype, const_cast<char*>("SW"), (ftnlen)2, (ftnlen)2);
/* SOURCE ufgate.for:1433 */
/*<       char6='  --- ' >*/
			    s_copy(char6, const_cast<char*>("  --- "), (ftnlen)6, (ftnlen)6);
/* SOURCE ufgate.for:1434 */
/*<       callfdroot(yright,rswmy3,epsf,yleft,iflag) >*/
			    fdroot_(&yright, rswmy3_, &epscom_1.epsf, &
				    yleft, &iflag);
/* SOURCE ufgate.for:1438 */
/*<       if(iflag.eq.1)then >*/
			    if (iflag == 1) {
/* SOURCE ufgate.for:1439 */
/*<       write(stdout,97)' SW flow' >*/
				feq_gen_io_d__186.ciunit = *stdout;
				s_wsfe(&feq_gen_io_d__186);
				do_fio(&feq_gen_c_d_1, const_cast<char*>(" SW flow"), (ftnlen)8);
				e_wsfe();
/* SOURCE ufgate.for:1440 */
/*<       eflag=1 >*/
				*eflag = 1;
/* SOURCE ufgate.for:1441 */
/*<       endif >*/
			    }
/* SOURCE ufgate.for:1442 */
/*<       callregfal(epsarg,epsf,rswmy3,yleft,yright,y3,iflag) >*/
			    regfal_(&epscom_1.epsarg, &epscom_1.epsf, rswmy3_, &yleft, &yright, &ufcom_1.y3, &
				    iflag);
/* SOURCE ufgate.for:1446 */
/*<       if(iflag.ne.0)then >*/
			    if (iflag != 0) {
/* SOURCE ufgate.for:1447 */
/*<       write(stdout,94)iflag,' for SW flow.' >*/
				feq_gen_io_d__187.ciunit = *stdout;
				s_wsfe(&feq_gen_io_d__187);
				do_fio(&feq_gen_c_d_1, (char *)&iflag, (ftnlen)sizeof(
					integer));
				do_fio(&feq_gen_c_d_1, const_cast<char*>(" for SW flow."), (ftnlen)13);
				e_wsfe();
/* SOURCE ufgate.for:1448 */
/*<       eflag=1 >*/
				*eflag = 1;
/* SOURCE ufgate.for:1449 */
/*<       endif >*/
			    }
/* SOURCE ufgate.for:1450 */
/*<       q=sqrt(qsqr) >*/
			    q = sqrt(ufcom_1.qsqr);
/*                  WRITE(STDOUT,*) ' SW Q=',Q,' Y3=',Y3,' IFLAG=',IFLAG */
/* SOURCE ufgate.for:1452 */
/*<       endif >*/
			}
/* SOURCE ufgate.for:1453 */
/*<       endif >*/
		    }
/* SOURCE ufgate.for:1454 */
/*<       oldy3=y3 >*/
		    oldy3 = ufcom_1.y3;
/* SOURCE ufgate.for:1455 */
/*<       qmat(ihu,j)=q >*/
		    qmat[ihu + j * 151 - 152] = q;
/* SOURCE ufgate.for:1457 */
/*<       de1to4=h1+alpha1*(q/a1)**2/twog-(h4+alpha4*(q/a4)**2/twog) >*/
/* Computing 2nd power */
		    feq_gen_r_d_1 = static_cast<double>(q) / ufcom_1.a1;
/* Computing 2nd power */
		    feq_gen_r_d_2 = static_cast<double>(q) / ufcom_1.a4;
		    de1to4 = static_cast<double>(static_cast<double>(h1) + static_cast<double>(static_cast<double>(ufcom_1.alpha1) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / 
			    ufcom_1.twog) - (static_cast<double>(h4) + static_cast<double>(static_cast<double>(ufcom_1.alpha4) * (static_cast<double>(feq_gen_r_d_2) * 
			    feq_gen_r_d_2)) / ufcom_1.twog);
/* SOURCE ufgate.for:1459 */
/*<       if(de1to4.lt.0.0)elflag=1 >*/
		    if (de1to4 < (float)0.) {
			elflag = 1;
		    }
/* SOURCE ufgate.for:1461 */
/*<       h3=y3+z3b-hdatum >*/
		    h3 = static_cast<double>(static_cast<double>(ufcom_1.y3) + ufcom_1.z3b) - hdatum;
/*              P2 = Q/(QFREE*SQRT(PFDVEC(J))) */
/*              OLDH3 = H3 */
/* SOURCE ufgate.for:1464 */
/*<       p=log(q/qmat(ihu,j+1))/log(pfdvec(j)/pfdvec(j+1)) >*/
		    p = log(static_cast<double>(q) / qmat[ihu + (j + 1) * 151 - 152]) / log(static_cast<double>(pfdvec[
			    j - 1]) / pfdvec[j]);
/* SOURCE ufgate.for:1465 */
/*<       cq=put10(q) >*/
		    put10_(feq_gen_ch_d_2, (ftnlen)10, &q);
		    s_copy(cq, feq_gen_ch_d_2, (ftnlen)10, (ftnlen)10);
/* SOURCE ufgate.for:1466 */
/*<       write(stdout,75)pfdvec(j),drop,h3,h4,ftype,char6,cq,p,de1to4 >*/
		    feq_gen_io_d__190.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__190);
		    do_fio(&feq_gen_c_d_1, (char *)&pfdvec[j - 1], (ftnlen)sizeof(real)
			    );
		    stored_submerged_drop = static_cast<float>(drop);
        do_fio(&feq_gen_c_d_1, (char *)&stored_submerged_drop, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&h3, (ftnlen)sizeof(real));
		    stored_submerged_head = static_cast<float>(h4);
        do_fio(&feq_gen_c_d_1, (char *)&stored_submerged_head, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, ftype, (ftnlen)2);
		    do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
		    do_fio(&feq_gen_c_d_1, cq, (ftnlen)10);
		    do_fio(&feq_gen_c_d_1, (char *)&p, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&de1to4, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE ufgate.for:1468 */
/*<   400 continue >*/
/* L400: */
		}
/* SOURCE ufgate.for:1469 */
/*<       else >*/
	    } else {
/*           Flow is free orifice flow.  Find the contraction */
/*           coefficient to use.  Find the gate opening ratio for */
/*           this upstream head */
/* SOURCE ufgate.for:1474 */
/*<       ftype='FO' >*/
		s_copy(ftype, const_cast<char*>("FO"), (ftnlen)2, (ftnlen)2);
/* SOURCE ufgate.for:1475 */
/*<       rg=hg/h1 >*/
		rg = static_cast<double>(ufcom_1.hg) / h1;
/* SOURCE ufgate.for:1477 */
/*<       if(h1.lt.h1foll)then >*/
		if (h1 < h1foll) {
/* SOURCE ufgate.for:1478 */
/*<       cc=1.0+(h1-h1fwul)*(ccfoll-1.0)/(h1foll-h1fwul) >*/
		    ufcom_1.cc = static_cast<double>(static_cast<double>(static_cast<double>((static_cast<double>(h1) - h1fwul)) * (static_cast<double>(ccfoll) - (float)1.)) / (
			    static_cast<double>(h1foll) - h1fwul)) + (float)1.;
/* SOURCE ufgate.for:1479 */
/*<       else >*/
		} else {
/* SOURCE ufgate.for:1480 */
/*<       if(angle(ihg).le.0.0)then >*/
		    if (angle[ihg - 1] <= (float)0.) {
/* SOURCE ufgate.for:1481 */
/*<       cc=findcc(rg,concc,cctab) >*/
			ufcom_1.cc = findcc_(&rg, &concc, &cctab);
/* SOURCE ufgate.for:1482 */
/*<       else >*/
		    } else {
/* SOURCE ufgate.for:1483 */
/*<       cc=findcc(angle(ihg),concc,cctab) >*/
			ufcom_1.cc = findcc_(&angle[ihg - 1], &concc, &cctab);
/* SOURCE ufgate.for:1484 */
/*<       endif >*/
		    }
/* SOURCE ufgate.for:1485 */
/*<       endif >*/
		}
/*            WRITE(STDOUT,*) ' CC FOR FREE ORIFICE=',CC */
/* SOURCE ufgate.for:1487 */
/*<       write(char6,'(F6.3)')cc >*/
		feq_gen_ici_d_1.icierr = 0;
		feq_gen_ici_d_1.icirnum = 1;
		feq_gen_ici_d_1.icirlen = 6;
		feq_gen_ici_d_1.iciunit = char6;
		feq_gen_ici_d_1.icifmt = const_cast<char*>("(F6.3)");
		s_wsfi(&feq_gen_ici_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&ufcom_1.cc, (ftnlen)sizeof(real));
		e_wsfi();
/* SOURCE ufgate.for:1488 */
/*<       at=cd*cc*ag >*/
		// Preserve separate REAL stores for effective area, jet depth and speed.
        orifice_state = feq::gate_orifice_state(ufcom_1.hg,ufcom_1.ag,ufcom_1.cd,ufcom_1.cc,
            ufcom_1.y1,ufcom_1.z1b,ufcom_1.z2b,ufcom_1.a1,ufcom_1.alpha1,ufcom_1.twog);
        ufcom_1.at = orifice_state.effective_area;
        ufcom_1.y2 = orifice_state.depth;
        qfree = orifice_state.flow;
/* SOURCE ufgate.for:1492 */
/*<       y2fo=y2 >*/
		y2fo = ufcom_1.y2;
/*           Now find the level at section 4 that defines */
/*           the limit of free orifice flow, Y4F. Define the constant */
/*           values. */
/* SOURCE ufgate.for:1496 */
/*<       y3=y2fo+z2b-z3b >*/
		ufcom_1.y3 = static_cast<double>(static_cast<double>(y2fo) + ufcom_1.z2b) - ufcom_1.z3b;
/* SOURCE ufgate.for:1497 */
/*<       oldy3=y3 >*/
		oldy3 = ufcom_1.y3;
/* SOURCE ufgate.for:1498 */
/*<       calllktj(deptab,y3,j4aty3) >*/
		lktj_(&ufcom_1.deptab, &ufcom_1.y3, &ufcom_1.j4aty3);
/* SOURCE ufgate.for:1502 */
/*<       qsqr=qfree**2 >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = qfree;
		ufcom_1.qsqr = static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1;
/*           The water surface elevation at section 4 will be */
/*           below the elevation at section 1 but above the */
/*           jet surface elevation at section 2. */
/* SOURCE ufgate.for:1507 */
/*<       yleft=y2fo+z2b-z4b >*/
		yleft = static_cast<double>(static_cast<double>(y2fo) + ufcom_1.z2b) - ufcom_1.z4b;
/* SOURCE ufgate.for:1508 */
/*<       yright=y1+z1b-z4b >*/
		yright = static_cast<double>(static_cast<double>(ufcom_1.y1) + ufcom_1.z1b) - ufcom_1.z4b;
/* SOURCE ufgate.for:1509 */
/*<       callregfal(epsarg,epsf,rsomy4,yleft,yright,y4f,iflag) >*/
		regfal_(&epscom_1.epsarg, &epscom_1.epsf, rsomy4_, &
			yleft, &yright, &y4f, &iflag);
/* SOURCE ufgate.for:1513 */
/*<       if(iflag.ne.0)then >*/
		if (iflag != 0) {
/* SOURCE ufgate.for:1514 */
/*<       write(stdout,94)iflag,' for FO tailwater limit.' >*/
		    feq_gen_io_d__192.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__192);
		    do_fio(&feq_gen_c_d_1, (char *)&iflag, (ftnlen)sizeof(integer));
		    do_fio(&feq_gen_c_d_1, const_cast<char*>(" for FO tailwater limit."), (ftnlen)24);
		    e_wsfe();
/* SOURCE ufgate.for:1515 */
/*<       eflag=1 >*/
		    *eflag = 1;
/* SOURCE ufgate.for:1516 */
/*<       endif >*/
		}
/* SOURCE ufgate.for:1517 */
/*<       zw4f=y4f+z4b >*/
		tailwater_levels = feq::gate_tailwater_levels(ufcom_1.y1,ufcom_1.z1b,y4f,ufcom_1.z4b,hdatum);
/* SOURCE ufgate.for:1518 */
/*<       h4f=zw4f-hdatum >*/
		h4f = tailwater_levels.head;
/* SOURCE ufgate.for:1519 */
/*<        >*/
/* Computing 2nd power */
		feq_gen_r_d_1 = static_cast<double>(qfree) / ufcom_1.a1;
/* Computing 2nd power */
		feq_gen_r_d_2 = static_cast<double>(qfree) / ufcom_1.a4;
		de1to4 = static_cast<double>(static_cast<double>(h1) + static_cast<double>(static_cast<double>(ufcom_1.alpha1) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / ufcom_1.twog) - 
			(static_cast<double>(h4f) + static_cast<double>(static_cast<double>(ufcom_1.alpha4) * (static_cast<double>(feq_gen_r_d_2) * feq_gen_r_d_2)) / ufcom_1.twog);
/* SOURCE ufgate.for:1521 */
/*<       if(de1to4.lt.0.0)elflag=1 >*/
		if (de1to4 < (float)0.) {
		    elflag = 1;
		}
/*            WRITE(STDOUT,*) ' Tailwater at free orifice flow limit:' */
/*            WRITE(STDOUT,*) ' Y4F=',Y4F,' H4F=',H4F */
/* SOURCE ufgate.for:1524 */
/*<       qmat(ihu,nfrac)=qfree >*/
		qmat[ihu + nfrac * 151 - 152] = qfree;
/* SOURCE ufgate.for:1525 */
/*<       fdrop=y1+z1b-zw4f >*/
		fdrop = tailwater_levels.drop;
/* SOURCE ufgate.for:1526 */
/*<       fdvec(ihu)=fdrop >*/
		fdvec[ihu - 1] = fdrop;
/* SOURCE ufgate.for:1527 */
/*<       cq=put10(qfree) >*/
		put10_(feq_gen_ch_d_2, (ftnlen)10, &qfree);
		s_copy(cq, feq_gen_ch_d_2, (ftnlen)10, (ftnlen)10);
/* SOURCE ufgate.for:1528 */
/*<       write(stdout,76)1.00,fdrop,y3+z3b-hdatum,h4f,ftype,char6,cq,de1to4 >*/
		feq_gen_io_d__193.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__193);
		do_fio(&feq_gen_c_d_1, (char *)&c_b259, (ftnlen)sizeof(real));
		stored_gate_drop = static_cast<float>(fdrop);
        do_fio(&feq_gen_c_d_1, (char *)&stored_gate_drop, (ftnlen)sizeof(real));
		feq_gen_r_d_1 = static_cast<double>(static_cast<double>(ufcom_1.y3) + ufcom_1.z3b) - hdatum;
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
		stored_gate_head = static_cast<float>(h4f);
        do_fio(&feq_gen_c_d_1, (char *)&stored_gate_head, (ftnlen)sizeof(real));
		do_fio(&feq_gen_c_d_1, ftype, (ftnlen)2);
		do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
		do_fio(&feq_gen_c_d_1, cq, (ftnlen)10);
		do_fio(&feq_gen_c_d_1, (char *)&de1to4, (ftnlen)sizeof(real));
		e_wsfe();
/*            OLDH3 = Y3 + Z3B - HDATUM */
/* SOURCE ufgate.for:1531 */
/*<       ftype='SO' >*/
		s_copy(ftype, const_cast<char*>("SO"), (ftnlen)2, (ftnlen)2);
/* SOURCE ufgate.for:1532 */
/*<       at=cd*cc*ag >*/
		ufcom_1.at = static_cast<double>(static_cast<double>(ufcom_1.cd) * ufcom_1.cc) * ufcom_1.ag;
/* SOURCE ufgate.for:1533 */
/*<       do500j=nfrac-1,2,-1 >*/
		for (j = nfrac - 1; j >= 2; --j) {
/* SOURCE ufgate.for:1534 */
/*<       drop=fdrop*pfdvec(j) >*/
		    submerged_levels = feq::gate_submerged_levels(ufcom_1.y1,ufcom_1.z1b,fdrop,pfdvec[j-1],ufcom_1.z4b,hdatum);
            drop = submerged_levels.drop;
/* SOURCE ufgate.for:1535 */
/*<       zw4=z1b+y1-drop >*/
		    
/* SOURCE ufgate.for:1536 */
/*<       y4=zw4-z4b >*/
		    ufcom_1.y4 = submerged_levels.depth;
/* SOURCE ufgate.for:1537 */
/*<       h4=zw4-hdatum >*/
		    h4 = submerged_levels.head;
/* SOURCE ufgate.for:1538 */
/*<       yleft=cc*hg+z2b-z4b >*/
		    yleft = static_cast<double>(static_cast<double>(static_cast<double>(ufcom_1.cc) * ufcom_1.hg) + ufcom_1.z2b) - 
			    ufcom_1.z4b;
/* SOURCE ufgate.for:1539 */
/*<       yright=y4 >*/
		    yright = ufcom_1.y4;
/* SOURCE ufgate.for:1540 */
/*<        >*/
		    xlkt22_(&ufcom_1.deptab, &ufcom_1.y4, &ufcom_1.a4, &t4, &
			    dt, &ufcom_1.j4, &ufcom_1.kt, &ufcom_1.dkt, &
			    ufcom_1.beta4, &dbeta4, &ufcom_1.alpha4, &
			    ufcom_1.dalpha, &ufcom_1.qct);
/* SOURCE ufgate.for:1545 */
/*<       callfdroot(yright,rsomy3,epsf,yleft,iflag) >*/
		    fdroot_(&yright, rsomy3_, &epscom_1.epsf, &yleft, &
			    iflag);
/* SOURCE ufgate.for:1549 */
/*<       if(iflag.eq.1)then >*/
		    if (iflag == 1) {
/* SOURCE ufgate.for:1550 */
/*<       write(stdout,97)' SO flow' >*/
			feq_gen_io_d__196.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__196);
			do_fio(&feq_gen_c_d_1, const_cast<char*>(" SO flow"), (ftnlen)8);
			e_wsfe();
/* SOURCE ufgate.for:1551 */
/*<       eflag=1 >*/
			*eflag = 1;
/* SOURCE ufgate.for:1552 */
/*<       endif >*/
		    }
/*             Flow is submerged orifice. */
/* SOURCE ufgate.for:1554 */
/*<       callregfal(epsarg,epsf,rsomy3,yleft,yright,y3,iflag) >*/
		    regfal_(&epscom_1.epsarg, &epscom_1.epsf, rsomy3_, &
			    yleft, &yright, &ufcom_1.y3, &iflag);
/* SOURCE ufgate.for:1558 */
/*<       if(iflag.ne.0)then >*/
		    if (iflag != 0) {
/* SOURCE ufgate.for:1559 */
/*<       write(stdout,94)iflag,' for SO flow.' >*/
			feq_gen_io_d__197.ciunit = *stdout;
			s_wsfe(&feq_gen_io_d__197);
			do_fio(&feq_gen_c_d_1, (char *)&iflag, (ftnlen)sizeof(integer))
				;
			do_fio(&feq_gen_c_d_1, const_cast<char*>(" for SO flow."), (ftnlen)13);
			e_wsfe();
/* SOURCE ufgate.for:1560 */
/*<       eflag=1 >*/
			*eflag = 1;
/* SOURCE ufgate.for:1561 */
/*<       endif >*/
		    }
/* SOURCE ufgate.for:1562 */
/*<       q=sqrt(qsqr) >*/
		    q = sqrt(ufcom_1.qsqr);
/* SOURCE ufgate.for:1563 */
/*<       oldy3=y3 >*/
		    oldy3 = ufcom_1.y3;
/* SOURCE ufgate.for:1564 */
/*<       qmat(ihu,j)=q >*/
		    qmat[ihu + j * 151 - 152] = q;
/* SOURCE ufgate.for:1565 */
/*<       h3=y3+z3b-hdatum >*/
		    h3 = static_cast<double>(static_cast<double>(ufcom_1.y3) + ufcom_1.z3b) - hdatum;
/*              P2 = Q/(QFREE*SQRT(PFDVEC(J))) */
/*              OLDH3 = H3 */
/* SOURCE ufgate.for:1568 */
/*<       p=log(q/qmat(ihu,j+1))/log(pfdvec(j)/pfdvec(j+1)) >*/
		    p = log(static_cast<double>(q) / qmat[ihu + (j + 1) * 151 - 152]) / log(static_cast<double>(pfdvec[
			    j - 1]) / pfdvec[j]);
/* SOURCE ufgate.for:1569 */
/*<       de1to4=h1+alpha1*(q/a1)**2/twog-(h4+alpha4*(q/a4)**2/twog) >*/
/* Computing 2nd power */
		    feq_gen_r_d_1 = static_cast<double>(q) / ufcom_1.a1;
/* Computing 2nd power */
		    feq_gen_r_d_2 = static_cast<double>(q) / ufcom_1.a4;
		    de1to4 = static_cast<double>(static_cast<double>(h1) + static_cast<double>(static_cast<double>(ufcom_1.alpha1) * (static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1)) / 
			    ufcom_1.twog) - (static_cast<double>(h4) + static_cast<double>(static_cast<double>(ufcom_1.alpha4) * (static_cast<double>(feq_gen_r_d_2) * 
			    feq_gen_r_d_2)) / ufcom_1.twog);
/* SOURCE ufgate.for:1571 */
/*<       if(de1to4.lt.0.0)elflag=1 >*/
		    if (de1to4 < (float)0.) {
			elflag = 1;
		    }
/*             Compute the rate of change of flow with respect */
/*             to change in the tailwater level. */
/*              CALL LKTA(DEPTAB, Y3, A4ATY3) */
/*              DQDY4 = (G*A4 + (DBETA4 - BETA4*T4/A4)*Q**2/A4)/ */
/*     A                 (Q*(A4ATY3*(ALPHA1/A1**2 - 1.0/(CC*CD*AG)**2) */
/*     B                  + 2.*(1.0/(CC*AG) - BETA4/A4))) */
/*              DQ = (DQDY4 + 0.5*Q/DROP)/(QFREE*SQRT(PFDVEC(J))) */
/* SOURCE ufgate.for:1581 */
/*<       cq=put10(q) >*/
		    put10_(feq_gen_ch_d_2, (ftnlen)10, &q);
		    s_copy(cq, feq_gen_ch_d_2, (ftnlen)10, (ftnlen)10);
/* SOURCE ufgate.for:1582 */
/*<       write(stdout,75)pfdvec(j),drop,h3,h4,ftype,char6,cq,p,de1to4 >*/
		    feq_gen_io_d__198.ciunit = *stdout;
		    s_wsfe(&feq_gen_io_d__198);
		    do_fio(&feq_gen_c_d_1, (char *)&pfdvec[j - 1], (ftnlen)sizeof(real)
			    );
		    stored_submerged_drop = static_cast<float>(drop);
        do_fio(&feq_gen_c_d_1, (char *)&stored_submerged_drop, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&h3, (ftnlen)sizeof(real));
		    stored_submerged_head = static_cast<float>(h4);
        do_fio(&feq_gen_c_d_1, (char *)&stored_submerged_head, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, ftype, (ftnlen)2);
		    do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
		    do_fio(&feq_gen_c_d_1, cq, (ftnlen)10);
		    do_fio(&feq_gen_c_d_1, (char *)&p, (ftnlen)sizeof(real));
		    do_fio(&feq_gen_c_d_1, (char *)&de1to4, (ftnlen)sizeof(real));
		    e_wsfe();
/* SOURCE ufgate.for:1584 */
/*<   500 continue >*/
/* L500: */
		}
/* SOURCE ufgate.for:1586 */
/*<       endif >*/
	    }
/*         Compute approximate maximum error and report */
/* SOURCE ufgate.for:1589 */
/*<       do600j=3,nfrac-2,2 >*/
	    feq_gen_i_d_4 = nfrac - 2;
	    for (j = 3; j <= feq_gen_i_d_4; j += 2) {
/* SOURCE ufgate.for:1590 */
/*<       qhat=0.5*(qmat(ihu,j-1)+qmat(ihu,j+1)) >*/
		qhat = static_cast<double>((static_cast<double>(qmat[ihu + (j - 1) * 151 - 152]) + qmat[ihu + (j + 1) *
			 151 - 152])) * (float).5;
/* SOURCE ufgate.for:1591 */
/*<       rerr=abs(qhat-qmat(ihu,j))/qmat(ihu,j) >*/
		rerr = (feq_gen_r_d_1 = static_cast<double>(qhat) - qmat[ihu + j * 151 - 152], dabs(feq_gen_r_d_1)) /
			 qmat[ihu + j * 151 - 152];
/* SOURCE ufgate.for:1592 */
/*<       rms=rms+rerr*rerr >*/
		rms += static_cast<double>(rerr) * rerr;
/* SOURCE ufgate.for:1593 */
/*<       nrms=nrms+1 >*/
		++nrms;
/* SOURCE ufgate.for:1594 */
/*<       if(rerr.gt.bigerr)then >*/
		if (rerr > bigerr) {
/* SOURCE ufgate.for:1595 */
/*<       bigerr=rerr >*/
		    bigerr = rerr;
/* SOURCE ufgate.for:1596 */
/*<       herr=h1 >*/
		    herr = h1;
/* SOURCE ufgate.for:1597 */
/*<       ipfd=j >*/
		    ipfd = j;
/* SOURCE ufgate.for:1598 */
/*<       ihgerr=ihg >*/
		    ihgerr = ihg;
/* SOURCE ufgate.for:1599 */
/*<       endif >*/
		}
/* SOURCE ufgate.for:1600 */
/*<   600 continue >*/
/* L600: */
	    }
/*         Eliminate the checking values from QMAT */
/* SOURCE ufgate.for:1603 */
/*<       jbase=3 >*/
	    jbase = 3;
/* SOURCE ufgate.for:1604 */
/*<       do700j=4,nfrac-1,2 >*/
	    feq_gen_i_d_4 = nfrac - 1;
	    for (j = 4; j <= feq_gen_i_d_4; j += 2) {
/* SOURCE ufgate.for:1605 */
/*<       qmat(ihu,jbase)=qmat(ihu,j) >*/
		qmat[ihu + jbase * 151 - 152] = qmat[ihu + j * 151 - 152];
/* SOURCE ufgate.for:1606 */
/*<       jbase=jbase+1 >*/
		++jbase;
/* SOURCE ufgate.for:1607 */
/*<   700 continue >*/
/* L700: */
	    }
/* SOURCE ufgate.for:1608 */
/*<       qmat(ihu,jbase)=qmat(ihu,nfrac) >*/
	    qmat[ihu + jbase * 151 - 152] = qmat[ihu + nfrac * 151 - 152];
/* SOURCE ufgate.for:1610 */
/*<   900 continue >*/
/* L900: */
	}
/* SOURCE ufgate.for:1611 */
/*<       pfdtmp(1)=pfdvec(1) >*/
	pfdtmp[0] = pfdvec[0];
/* SOURCE ufgate.for:1612 */
/*<       pfdtmp(2)=pfdvec(2) >*/
	pfdtmp[1] = pfdvec[1];
/* SOURCE ufgate.for:1613 */
/*<       jbase=3 >*/
	jbase = 3;
/* SOURCE ufgate.for:1614 */
/*<       do910j=4,nfrac-1,2 >*/
	feq_gen_i_d_3 = nfrac - 1;
	for (j = 4; j <= feq_gen_i_d_3; j += 2) {
/* SOURCE ufgate.for:1615 */
/*<       pfdtmp(jbase)=pfdvec(j) >*/
	    pfdtmp[jbase - 1] = pfdvec[j - 1];
/* SOURCE ufgate.for:1616 */
/*<       jbase=jbase+1 >*/
	    ++jbase;
/* SOURCE ufgate.for:1617 */
/*<   910 continue >*/
/* L910: */
	}
/* SOURCE ufgate.for:1618 */
/*<       pfdtmp(jbase)=pfdvec(nfrac) >*/
	pfdtmp[jbase - 1] = pfdvec[nfrac - 1];
/* SOURCE ufgate.for:1620 */
/*<       zrhufd=0.0 >*/
	zrhufd = (float)0.;
/* SOURCE ufgate.for:1621 */
/*<        >*/
	twdout_(stdout, stdtab, &tab2d[ihg - 1], label, &nhu, &jbase, huvec, 
		fdvec, pfdtmp, qmat, &hdatum, &feq_gen_c_d_13, const_cast<char*>("  UFGATE"), &zrhufd, 
		zone, hgrid, vdatum, unitsys, basis, &easting, &northing, 
		eflag, (ftnlen)50, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8,
		 (ftnlen)8, (ftnlen)8);
/* SOURCE ufgate.for:1629 */
/*<       if(elflag.gt.0)then >*/
	if (elflag > 0) {
/* SOURCE ufgate.for:1630 */
/*<       write(stdout,77) >*/
	    feq_gen_io_d__207.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__207);
	    e_wsfe();
/* SOURCE ufgate.for:1631 */
/*<       endif >*/
	}
/* SOURCE ufgate.for:1632 */
/*<  1000 continue >*/
/* L1000: */
    }
/* SOURCE ufgate.for:1633 */
/*<       write(stdout,86)bigerr,hgvec(ihgerr),herr,pfdvec(ipfd) >*/
    feq_gen_io_d__208.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__208);
    do_fio(&feq_gen_c_d_1, (char *)&bigerr, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&hgvec[ihgerr - 1], (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&herr, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&pfdvec[ipfd - 1], (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE ufgate.for:1636 */
/*<       rms=sqrt(rms/float(nrms)) >*/
    rms = sqrt(static_cast<double>(rms) / (real) nrms);
/* SOURCE ufgate.for:1637 */
/*<       write(stdout,88)rms,nrms >*/
    feq_gen_io_d__209.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__209);
    do_fio(&feq_gen_c_d_1, (char *)&rms, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&nrms, (ftnlen)sizeof(integer));
    e_wsfe();
/*     Output the table of type 15 to the table file */
/* SOURCE ufgate.for:1640 */
/*<       write(stdtab,95)tabid(1:lenstr(tabid)),lab2 >*/
    feq_gen_io_d__210.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__210);
    do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
    do_fio(&feq_gen_c_d_1, lab2, (ftnlen)50);
    e_wsfe();
/* SOURCE ufgate.for:1641 */
/*<       do1005i=1,nhg >*/
    feq_gen_i_d_1 = nhg;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE ufgate.for:1642 */
/*<       id=get_tabid(tab2d(i)) >*/
	feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &tab2d[feq_gen_i_d_ - 1]);
	s_copy(id, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE ufgate.for:1643 */
/*<       j=lenstr(id) >*/
	j = lenstr_(id, (ftnlen)16);
/* SOURCE ufgate.for:1644 */
/*<       tabid=' ' >*/
	s_copy(tabid, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1);
/* SOURCE ufgate.for:1645 */
/*<       tabid(16-j+1:16)=id(1:j) >*/
	feq_gen_i_d_3 = 16 - j;
	s_copy(tabid + feq_gen_i_d_3, id, 16 - feq_gen_i_d_3, j);
/* SOURCE ufgate.for:1646 */
/*<       write(stdtab,96)hgvec(i),tabid,(hstuff(i,j),j=1,3) >*/
	feq_gen_io_d__211.ciunit = *stdtab;
	s_wsfe(&feq_gen_io_d__211);
	do_fio(&feq_gen_c_d_1, (char *)&hgvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, tabid, (ftnlen)16);
	for (j = 1; j <= 3; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&hstuff[feq_gen_i_d_ + j * 40 - 41], (ftnlen)sizeof(
		    real));
	}
	e_wsfe();
/* SOURCE ufgate.for:1647 */
/*<  1005 continue >*/
/* L1005: */
    }
/* SOURCE ufgate.for:1648 */
/*<       write(stdtab,96)-1.0 >*/
    feq_gen_io_d__212.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__212);
    do_fio(&feq_gen_c_d_1, (char *)&c_b350, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE ufgate.for:1649 */
/*<       return >*/
    return 0;
/* SOURCE ufgate.for:1650 */
/*<   991 continue >*/
L991:
/* SOURCE ufgate.for:1651 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__213.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__213);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE ufgate.for:1652 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__214.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__214);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE ufgate.for:1653 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE ufgate.for:1654 */
/*<       end >*/
    return 0;
} /* ufgate_ */

#undef rtmp
#undef itab
#undef ftab


#ifdef __cplusplus
	}
#endif
