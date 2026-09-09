#include <feq/channel_rating.hpp>
#include <feq/steady_residual.hpp>
#include "callbacks.hpp"
/* chanrat.f -- translated by f2c (version 20240504).
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

/* COMMON chncom_ is declared in common.hpp. */

#define chncom_1 chncom_

/* COMMON stdun_com__ is declared in common.hpp. */

#define feq_gen_stdun_com_d_1 feq_gen_stdun_com_d_

/* COMMON epscom_ is declared in common.hpp. */

#define epscom_1 epscom_

/* COMMON ftable_ is declared in common.hpp. */

#define ftable_1 ftable_

/* COMMON ftablea_ is declared in common.hpp. */

#define ftablea_1 ftablea_

/* COMMON ftablec_ is declared in common.hpp. */

#define ftablec_1 ftablec_

/* COMMON upgrdc_ is declared in common.hpp. */

#define upgrdc_1 upgrdc_

/* COMMON chnrtitm_com__ is declared in common.hpp. */

#define feq_gen_chnrtitm_com_d_1 feq_gen_chnrtitm_com_d_

/* COMMON chnrtitm_comc__ is declared in common.hpp. */

#define feq_gen_chnrtitm_comc_d_1 feq_gen_chnrtitm_comc_d_

/* Table of constant values */

static integer feq_gen_c_d_1 = 1;
static integer feq_gen_c_d_12 = 12;
static integer feq_gen_c_d_10002 = 10002;
static integer feq_gen_c_d_151 = 151;
static integer feq_gen_c_d_351 = 351;
static integer feq_gen_c_d_9 = 9;
static integer feq_gen_c_d_10 = 10;
static real c_b249 = (float)3.5;
static real c_b258 = (float).5;
static doublereal c_b259 = 1.;
static integer feq_gen_c_d_2 = 2;
static integer feq_gen_c_d_17 = 17;
static integer feq_gen_c_d_7 = 7;
static integer feq_gen_c_d_6 = 6;




/* SOURCE chanrat.for:4 */
/*<       doubleprecisionfunctionffpres(y) >*/
doublereal ffpres_(doublereal *y)
{
    /* System generated locals */
    doublereal ret_val;

    /* Local variables */
    real qc;
    doublereal temp;
    extern /* Subroutine */ int qfun_(real *, real *, FeqCallback1, real *, 
	    doublereal *);
    extern doublereal fdxdy_(doublereal*);
    extern /* Subroutine */ int lktqc_(integer *, real *, real *);
    doublereal result;

/*     + + + PURPOSE + + + */
/*     Compute the free flow profile residual.  Flow at downstream end of */
/*     the channel is at critical depth. */
/* SOURCE chanrat.for:11 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE chanrat.for:14 */
/*<       doubleprecisiony >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Y      - maximum depth in a cross section */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE chanrat.for:20 */
/*     COMMON BLOCK FOR  CHANNEL RATING */
/* SOURCE chncom.cmn:3 */
/*<       integerxsadr >*/
/* SOURCE chncom.cmn:5 */
/*<       realq,qn,l,sbot,yl,yr,qerr,lstres,nddabs,nddrel,frfac >*/
/* SOURCE chncom.cmn:8 */
/*<        >*/
/* INCLUDE chanrat.for:21 */
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
/* SOURCE chanrat.for:24 */
/*<       realqc >*/
/* SOURCE chanrat.for:25 */
/*<       doubleprecisionresult,temp >*/
/*     + + + INTRINSICS + + + */
/* SOURCE chanrat.for:28 */
/*<       intrinsicdble >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE chanrat.for:31 */
/*<       doubleprecisionfdxdy >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE chanrat.for:34 */
/*<       externalfdxdy,lktqc,qfun >*/
/*     ***********************************FORMAT************************* */
/* SOURCE chanrat.for:36 */
/*<    50  >*/
/* *********************************************************************** */
/*      WRITE(STD6,*) ' ENTERING FFPRES: Y=',Y */
/*     FIND CRITICAL FLOW AT DOWNSTREAM END OF THE CHANNEL */
/* SOURCE chanrat.for:43 */
/*<       yr=y >*/
/* L50: */
    chncom_1.yr = *y;
/* SOURCE chanrat.for:44 */
/*<       calllktqc(xsadr,yr,qc) >*/
    lktqc_(&chncom_1.xsadr, &chncom_1.yr, &qc);
/* SOURCE chanrat.for:48 */
/*<       q=qc >*/
    chncom_1.q = qc;
/*     COMPUTE THE LENGTH OF THE PROFILE FROM DEPTH YL TO DEPTH YR */
/*     AND SUBTRACT THE CHANNEL LENGTH, L(FROM CHANCOM). */
/*     NOTE: YR < YL IN ALL CASES. */
/* SOURCE chanrat.for:54 */
/*<       callqfun(yl,yr,fdxdy,qerr,result) >*/
    qfun_(&chncom_1.yl, &chncom_1.yr, fdxdy_, &chncom_1.qerr, &result);
/* SOURCE chanrat.for:57 */
/*<       temp=result-dble(l) >*/
    temp = result - (doublereal) chncom_1.l;
/* SOURCE chanrat.for:58 */
/*<       ffpres=temp >*/
    ret_val = temp;
/* SOURCE chanrat.for:59 */
/*<       lstres=temp >*/
    chncom_1.lstres = temp;
/*      WRITE(STD6,50) YL, YR, RESULT, FFPRES, QERR, Q */
/* SOURCE chanrat.for:61 */
/*<       return >*/
    return ret_val;
/* SOURCE chanrat.for:62 */
/*<       end >*/
} /* ffpres_ */




/* SOURCE chanrat.for:66 */
/*<       doubleprecisionfunctionsbpres(flow) >*/
doublereal sbpres_(doublereal *flow)
{
    /* System generated locals */
    doublereal ret_val;

    /* Local variables */
    doublereal temp;
    extern /* Subroutine */ int qfun_(real *, real *, FeqCallback1, real *, 
	    doublereal *);
    extern doublereal fdxdy_(doublereal*);

/*     + + + PURPOSE + + + */
/*     Compute the submerged flow profile residual. */
/* SOURCE chanrat.for:72 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE chanrat.for:75 */
/*<       doubleprecisionflow >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     FLOW   - Flowrate */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE chanrat.for:81 */
/*     COMMON BLOCK FOR  CHANNEL RATING */
/* SOURCE chncom.cmn:3 */
/*<       integerxsadr >*/
/* SOURCE chncom.cmn:5 */
/*<       realq,qn,l,sbot,yl,yr,qerr,lstres,nddabs,nddrel,frfac >*/
/* SOURCE chncom.cmn:8 */
/*<        >*/
/* INCLUDE chanrat.for:82 */
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
/* SOURCE chanrat.for:85 */
/*<       doubleprecisiontemp >*/
/*     + + + INTRINSICS + + + */
/* SOURCE chanrat.for:88 */
/*<       intrinsicdble >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE chanrat.for:91 */
/*<       doubleprecisionfdxdy >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE chanrat.for:94 */
/*<       externalfdxdy,qfun >*/
/* *********************************************************************** */
/*      WRITE(STD6,*) ' ENTERING SBPRES: FLOW=',FLOW,' YL=',YL,' YR=',YR */
/*     YL AND YR ARE FIXED AND IN CHNCOM. */
/* SOURCE chanrat.for:100 */
/*<       q=flow >*/
    chncom_1.q = *flow;
/*     COMPUTE THE LENGTH OF THE PROFILE FROM DEPTH YL TO DEPTH YR */
/*     AND SUBTRACT THE CHANNEL LENGTH, L(FROM CHNCOM). */
/* SOURCE chanrat.for:105 */
/*<       callqfun(yl,yr,fdxdy,qerr,temp) >*/
    qfun_(&chncom_1.yl, &chncom_1.yr, fdxdy_, &chncom_1.qerr, &temp);
/* SOURCE chanrat.for:108 */
/*<       temp=temp-dble(l) >*/
    temp -= (doublereal) chncom_1.l;
/* SOURCE chanrat.for:109 */
/*<       sbpres=temp >*/
    ret_val = temp;
/* SOURCE chanrat.for:110 */
/*<       lstres=temp >*/
    chncom_1.lstres = temp;
/*      WRITE(STD6,*) ' SBPRES=',SBPRES */
/* SOURCE chanrat.for:113 */
/*<       return >*/
    return ret_val;
/* SOURCE chanrat.for:114 */
/*<       end >*/
} /* sbpres_ */




/* SOURCE chanrat.for:118 */
/*<       doubleprecisionfunctionfdxdy(y) >*/
doublereal fdxdy_(doublereal *y)
{
    /* System generated locals */
    doublereal ret_val, feq_gen_d_d_1, feq_gen_d_d_2;

    /* Local variables */
    real a, j, k, t, dk, qc, dt, tp, beta, dbeta, alpha;
    extern /* Subroutine */ int xlkt22_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *, 
	    real *);
    real dalpha;

/*     + + + PURPOSE + + + */
/*     Compute the inverse water surface slope for steady flow in a */
/*     prismatic channel. */
/* SOURCE chanrat.for:125 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE chanrat.for:128 */
/*<       doubleprecisiony >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     Y      - maximum depth in a cross section */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE chanrat.for:134 */
/*     COMMON BLOCK FOR  CHANNEL RATING */
/* SOURCE chncom.cmn:3 */
/*<       integerxsadr >*/
/* SOURCE chncom.cmn:5 */
/*<       realq,qn,l,sbot,yl,yr,qerr,lstres,nddabs,nddrel,frfac >*/
/* SOURCE chncom.cmn:8 */
/*<        >*/
/* INCLUDE chanrat.for:135 */
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
/* SOURCE chanrat.for:138 */
/*<       reala,alpha,beta,dalpha,dbeta,dk,dt,j,k,qc,t,tp >*/
/*     + + + INTRINSICS + + + */
/* SOURCE chanrat.for:141 */
/*<       intrinsicdble,sngl >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE chanrat.for:144 */
/*<       externalxlkt22 >*/
/* *********************************************************************** */
/* SOURCE chanrat.for:146 */
/*<       tp=sngl(y) >*/
    tp = (real) (*y);
/* SOURCE chanrat.for:147 */
/*<       callxlkt22(xsadr,tp,a,t,dt,j,k,dk,beta,dbeta,alpha,dalpha,qc) >*/
    xlkt22_(&chncom_1.xsadr, &tp, &a, &t, &dt, &j, &k, &dk, &beta, &dbeta, &
	    alpha, &dalpha, &qc);
/*      WRITE(STD6,*) 'FDXDY: Y=',Y,' Q=',Q,' QC=',QC,' SBOT=',SBOT, */
/*     A               ' K=',K */
/* SOURCE chanrat.for:155 */
/*<        >*/
/* Computing 2nd power */
    feq_gen_d_d_1 = (doublereal) chncom_1.q / (doublereal) qc;
/* Computing 2nd power */
    feq_gen_d_d_2 = (doublereal) chncom_1.q / (doublereal) k;
    ret_val = (1. - feq_gen_d_d_1 * feq_gen_d_d_1) / ((doublereal) chncom_1.sbot - feq_gen_d_d_2 * feq_gen_d_d_2);
/*     WRITE(STD6,*) ' FDXDY=', FDXDY */
/* SOURCE chanrat.for:159 */
/*<       return >*/
    return ret_val;
/* SOURCE chanrat.for:160 */
/*<       end >*/
} /* fdxdy_ */




/* SOURCE chanrat.for:164 */
/*<       subroutinefind_root_interval(stdout,f,xmin,xmax) >*/
/* Subroutine */ int feq_gen_find_root_interval_d_(integer *stdout, FeqCallback1 f, real *xmin,
	 real *xmax)
{
    /* Format strings */
    static char fmt_50[] = "(\002 NO ROOT INTERVAL FOUND!\002)";
    static char fmt_52[] = "(\002 MORE THAN ONE ROOT INTERVAL!\002,/,\002  K\
NT=\002,i5,(8f10.4))";

    /* System generated locals */
    integer feq_gen_i_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    integer feq_gen_i_d_, j, n;
    doublereal fi, fn;
    integer knt;
    doublereal fvec[5000], xvec[5000], xtmin, xtmax;
    integer feq_gen_root_interval_d_[500];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__27 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__28 = { 0, 0, 0, fmt_52, 0 };


/*     Do a detailed search for intervals containing a root. */
/*     Use for SBFCHN first and then extend. */
/* SOURCE chanrat.for:170 */
/*<       implicitnone >*/
/* SOURCE chanrat.for:171 */
/*<       integerstdout >*/
/* SOURCE chanrat.for:172 */
/*<       realxmin,xmax >*/
/* SOURCE chanrat.for:173 */
/*<       real*8f >*/
/* SOURCE chanrat.for:175 */
/*<       externalf >*/
/*     Local */
/* SOURCE chanrat.for:178 */
/*<       integeri,j,n,knt,root_interval(500) >*/
/* SOURCE chanrat.for:181 */
/*<       real*8fn,fi,xvec(5000),fvec(5000),xtmin,xtmax >*/
/*     *****************************FORMAT******************************* */
/* SOURCE chanrat.for:184 */
/*<    50 format(' NO ROOT INTERVAL FOUND!') >*/
/* SOURCE chanrat.for:185 */
/*<    52 format(' MORE THAN ONE ROOT INTERVAL!',/,'  KNT=',i5,(8f10.4)) >*/
/* *********************************************************************** */
/* SOURCE chanrat.for:188 */
/*<       xtmin=xmin >*/
/* L50: */
/* L52: */
    xtmin = *xmin;
/* SOURCE chanrat.for:189 */
/*<       xtmax=xmax*1.01 >*/
    xtmax = static_cast<double>(*xmax) * (float)1.01;
/* SOURCE chanrat.for:190 */
/*<       if(xtmin.eq.0.d0)then >*/
    if (xtmin == 0.) {
/* SOURCE chanrat.for:191 */
/*<       xtmin=0.1*xtmax >*/
	xtmin = xtmax * (float).1;
/* SOURCE chanrat.for:192 */
/*<       endif >*/
    }
/*     Argument is in cfs.  Assign a minimum of 100 points to any range */
/*     and a maximum of 2 points per  cfs. */
/* SOURCE chanrat.for:195 */
/*<       n=2.*(xtmax-xtmin) >*/
    n = (integer) ((xtmax - xtmin) * (float)2.);
/* SOURCE chanrat.for:196 */
/*<       if(n.lt.100)n=100 >*/
    if (n < 100) {
	n = 100;
    }
/* SOURCE chanrat.for:197 */
/*<       if(n.gt.5000)n=5000 >*/
    if (n > 5000) {
	n = 5000;
    }
/* SOURCE chanrat.for:198 */
/*<       fn=dble(n-1) >*/
    fn = (doublereal) (n - 1);
/* SOURCE chanrat.for:199 */
/*<       do100i=1,n >*/
    feq_gen_i_d_1 = n;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE chanrat.for:200 */
/*<       fi=dble(i-1) >*/
	fi = (doublereal) (feq_gen_i_d_ - 1);
/* SOURCE chanrat.for:201 */
/*<       xvec(i)=xtmin+fi*(xtmax-xtmin)/fn >*/
	xvec[feq_gen_i_d_ - 1] = xtmin + fi * (xtmax - xtmin) / fn;
/* SOURCE chanrat.for:202 */
/*<       fvec(i)=f(xvec(i)) >*/
	fvec[feq_gen_i_d_ - 1] = (*f)(&xvec[feq_gen_i_d_ - 1]);
/* SOURCE chanrat.for:203 */
/*<   100 continue >*/
/* L100: */
    }
/* SOURCE chanrat.for:205 */
/*<       knt=0 >*/
    knt = 0;
/* SOURCE chanrat.for:206 */
/*<       do200i=2,n >*/
    feq_gen_i_d_1 = n;
    for (feq_gen_i_d_ = 2; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE chanrat.for:207 */
/*<       if(fvec(i)*fvec(i-1).lt.0.d0)then >*/
	if (fvec[feq_gen_i_d_ - 1] * fvec[feq_gen_i_d_ - 2] < 0.) {
/* SOURCE chanrat.for:208 */
/*<       knt=knt+1 >*/
	    ++knt;
/* SOURCE chanrat.for:209 */
/*<       root_interval(knt)=i >*/
	    feq_gen_root_interval_d_[knt - 1] = feq_gen_i_d_;
/* SOURCE chanrat.for:210 */
/*<       endif >*/
	}
/* SOURCE chanrat.for:211 */
/*<   200 continue >*/
/* L200: */
    }
/* SOURCE chanrat.for:213 */
/*<       if(knt.eq.0)then >*/
    if (knt == 0) {
/* SOURCE chanrat.for:214 */
/*<       write(stdout,50) >*/
	feq_gen_io_d__27.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__27);
	e_wsfe();
/* SOURCE chanrat.for:215 */
/*<       elseif(knt.gt.1)then >*/
    } else if (knt > 1) {
/* SOURCE chanrat.for:216 */
/*<       write(stdout,52)knt,(xvec(root_interval(j)),j=1,knt) >*/
	feq_gen_io_d__28.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__28);
	do_fio(&feq_gen_c_d_1, (char *)&knt, (ftnlen)sizeof(integer));
	feq_gen_i_d_1 = knt;
	for (j = 1; j <= feq_gen_i_d_1; ++j) {
	    do_fio(&feq_gen_c_d_1, (char *)&xvec[feq_gen_root_interval_d_[j - 1] - 1], (ftnlen)
		    sizeof(doublereal));
	}
	e_wsfe();
/* SOURCE chanrat.for:217 */
/*<       endif >*/
    }
/* SOURCE chanrat.for:218 */
/*<       return >*/
    return 0;
/* SOURCE chanrat.for:219 */
/*<       end >*/
} /* find_root_interval__ */




/* SOURCE chanrat.for:224 */
/*<       subroutinesbfchn(stdout,qratio,eflag) >*/
/* Subroutine */ int sbfchn_(integer *stdout, real *qratio, integer *eflag)
{
    /* Format strings */
    static char fmt_51[] = "(/,\002 *BUG in SBFCHN: No sign change on entry \
to DBLRGF.\002)";
    static char fmt_52[] = "(/,\002 *BUG in SBFFCHN: More than 100 iteration\
s in DBLRGF.\002)";
    static char fmt_53[] = "(/,\002 *ERR/WRN:762* in SBFCHN: Argument collap\
se with residual=\002,1pe10.3,\002 more than twice EPSINT in DBLRGF.\002)";

    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2;
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    doublereal fl, fr, lhat, qmid;
    real qmin, qmax;
    extern /* Subroutine */ int qfun_(real *, real *, FeqCallback1, real *, 
	    doublereal *);
    integer rflag;
    real ynear, qsave;
    extern doublereal fdxdy_(doublereal *);
    extern /* Subroutine */ int dblrgf_(doublereal *, doublereal *, FeqCallback1, 
	    real *, real *, doublereal *, doublereal *, doublereal *, integer 
	    *);
    extern doublereal sbpres_(doublereal *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__39 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__40 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__41 = { 0, 0, 0, fmt_53, 0 };


/*     + + + PURPOSE + + + */
/*     Compute submerged flow through a prismatic channel. */
/*     most values are in CHNCOM. */
/* SOURCE chanrat.for:232 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE chanrat.for:235 */
/*<       integerstdout,eflag >*/
/* SOURCE chanrat.for:236 */
/*<       realqratio >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     QRATIO - ratio of flows used to provide initial estimate. */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE chanrat.for:242 */
/*     COMMON BLOCK FOR  CHANNEL RATING */
/* SOURCE chncom.cmn:3 */
/*<       integerxsadr >*/
/* SOURCE chncom.cmn:5 */
/*<       realq,qn,l,sbot,yl,yr,qerr,lstres,nddabs,nddrel,frfac >*/
/* SOURCE chncom.cmn:8 */
/*<        >*/
/* INCLUDE chanrat.for:243 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE chanrat.for:246 */
/*<       integerrflag >*/
/* SOURCE chanrat.for:247 */
/*<       realqmax,qmin,qsave,ynear >*/
/* SOURCE chanrat.for:248 */
/*<       doubleprecisionlhat,fl,fr,qmid >*/
/*     + + + INTRINSICS + + + */
/* SOURCE chanrat.for:251 */
/*<       intrinsicdble,max,min >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE chanrat.for:254 */
/*<       doubleprecisionfdxdy,sbpres >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE chanrat.for:257 */
/*<       externalfdxdy,qfun,sbpres,dblrgf >*/
/*     *******************************FORMATS**************************** */
/* SOURCE chanrat.for:259 */
/*<    51 format(/,' *BUG in SBFCHN: No sign change on entry to DBLRGF.') >*/
/* SOURCE chanrat.for:260 */
/*<    52 format(/,' *BUG in SBFFCHN: More than 100 iterations in DBLRGF.') >*/
/* SOURCE chanrat.for:261 */
/*<    53  >*/
/* *********************************************************************** */
/* SOURCE chanrat.for:265 */
/*<       eflag=0 >*/
/* L51: */
/* L52: */
/* L53: */
    *eflag = 0;
/*      WRITE(STDOUT,*) ' SBFCHN: YL=',YL,' YR=',YR */
/*     INITIAL FLOWS MUST BE SELECTED WITH CARE IF SBOT > 0.0.  WE */
/*     MUST MAKE SURE THAT NO INTEGRAL CROSSES THE NORMAL FLOW LEVEL. */
/*     SINCE THE CHANNEL IS PRISMATIC, NORMAL FLOW EXISTS WHENEVER */
/*     YL = YR.  IF YR < YL, AND SBOT > 0.0 THEN THE MIMIMUM FLOW IS */
/*     NORMAL FLOW PLUS SOME SMALL TOLERANCE.  IF YR > YL AND */
/*     SBOT > 0.0 THEN THE MAXIMUM FLOW IS NORMAL FLOW LESS SOME */
/*     SMALL TOLERANCE. */
/*     IF SBOT IS <=0.0 NORMAL FLOW DOES NOT EXIST. THUS THE MIMIMUM FLOW */
/*     IS ESSENTIALLY ZERO AND THE MAXIMUM FLOW THE PREVIOUS FLOW. */
/*     December 15, 1999- allow maximum flow to be larger than the */
/*     previous flow.  Needed in some cases when the critical flow */
/*     decreases with increasing stage.  This case may require */
/*     detailed study to solve correctly-at some point in the future. */
/* SOURCE chanrat.for:281 */
/*<       qsave=q >*/
    qsave = chncom_1.q;
/* SOURCE chanrat.for:282 */
/*<       if(sbot.le.0.0)then >*/
    if (chncom_1.sbot <= (float)0.) {
/* SOURCE chanrat.for:283 */
/*<       qmin=0.0 >*/
	qmin = (float)0.;
/*       Removed Feb. 4, 2000.  Caused more problems than it solved. */
/* SOURCE chanrat.for:285 */
/*<       qmax=1.0*q >*/
	qmax = static_cast<double>(chncom_1.q) * (float)1.;
/* SOURCE chanrat.for:286 */
/*<       else >*/
    } else {
/* SOURCE chanrat.for:288 */
/*<       if(yr.lt.yl)then >*/
	if (chncom_1.yr < chncom_1.yl) {
/*         CHECK IF THE CHANNEL IS LONG ENOUGH TO ESTABLISH ESSENTIAL */
/*         NORMAL FLOW AT THE UPSTREAM END FOR THE GIVEN DOWNSTREAN DEPTH. */
/* SOURCE chanrat.for:291 */
/*<       ynear=max((1.0-nddrel)*yl,yl-nddabs) >*/
/* Computing MAX */
	    feq_gen_r_d_1 = static_cast<double>((static_cast<double>((float)1.) - chncom_1.nddrel)) * chncom_1.yl, feq_gen_r_d_2 = 
		    static_cast<double>(chncom_1.yl) - chncom_1.nddabs;
	    ynear = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE chanrat.for:292 */
/*<       q=qn >*/
	    chncom_1.q = chncom_1.qn;
/* SOURCE chanrat.for:293 */
/*<       callqfun(ynear,yr,fdxdy,qerr,lhat) >*/
	    qfun_(&ynear, &chncom_1.yr, fdxdy_, &chncom_1.qerr, &lhat);
/*          WRITE(STDOUT,*) ' SBFCHN: YNEAR=',YNEAR */
/*          WRITE(STDOUT,*) ' SBFCHN: LHAT=',LHAT,' L=',L */
/* SOURCE chanrat.for:299 */
/*<       if(lhat.lt.l)then >*/
	    if (lhat < chncom_1.l) {
/*           FLOW IS AT NORMAL RATE */
/* SOURCE chanrat.for:301 */
/*<       return >*/
		return 0;
/* SOURCE chanrat.for:302 */
/*<       endif >*/
	    }
/* SOURCE chanrat.for:303 */
/*<       q=qsave >*/
	    chncom_1.q = qsave;
/* SOURCE chanrat.for:304 */
/*<       qmin=qn+epsarg >*/
	    qmin = static_cast<double>(chncom_1.qn) + epscom_1.epsarg;
/* SOURCE chanrat.for:305 */
/*<       qmax=q >*/
	    qmax = chncom_1.q;
/* SOURCE chanrat.for:306 */
/*<       else >*/
	} else {
/*         CHECK IF THE CHANNEL IS LONG ENOUGH TO ESTABLISH ESSENTIAL */
/*         NORMAL FLOW AT THE UPSTREAM END FOR THE GIVEN DOWNSTREAN DEPTH. */
/* SOURCE chanrat.for:309 */
/*<       ynear=min((1.0+nddrel)*yl,yl+nddabs) >*/
/* Computing MIN */
	    feq_gen_r_d_1 = static_cast<double>((static_cast<double>(chncom_1.nddrel) + (float)1.)) * chncom_1.yl, feq_gen_r_d_2 = 
		    static_cast<double>(chncom_1.yl) + chncom_1.nddabs;
	    ynear = dmin(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE chanrat.for:310 */
/*<       q=qn >*/
	    chncom_1.q = chncom_1.qn;
/* SOURCE chanrat.for:311 */
/*<       callqfun(ynear,yr,fdxdy,qerr,lhat) >*/
	    qfun_(&ynear, &chncom_1.yr, fdxdy_, &chncom_1.qerr, &lhat);
/*          WRITE(STDOUT,*) ' SBFCHN: YNEAR=',YNEAR */
/*          WRITE(STDOUT,*) ' SBFCHN: LHAT=',LHAT,' L=',L */
/* SOURCE chanrat.for:317 */
/*<       if(lhat.lt.l)then >*/
	    if (lhat < chncom_1.l) {
/*           FLOW IS AT NORMAL RATE */
/* SOURCE chanrat.for:319 */
/*<       return >*/
		return 0;
/* SOURCE chanrat.for:320 */
/*<       endif >*/
	    }
/* SOURCE chanrat.for:321 */
/*<       q=qsave >*/
	    chncom_1.q = qsave;
/* SOURCE chanrat.for:322 */
/*<       if(q.gt.qn)q=qn-epsarg >*/
	    if (chncom_1.q > chncom_1.qn) {
		chncom_1.q = static_cast<double>(chncom_1.qn) - epscom_1.epsarg;
	    }
/* SOURCE chanrat.for:323 */
/*<       qmin=0.0 >*/
	    qmin = (float)0.;
/* SOURCE chanrat.for:324 */
/*<       qmax=q >*/
	    qmax = chncom_1.q;
/* SOURCE chanrat.for:325 */
/*<       endif >*/
	}
/* SOURCE chanrat.for:326 */
/*<       endif >*/
    }
/*      IF(YR.LT.YL) THEN */
/*        FL = 9.0*DBLE(L) */
/*        FR = -0.5*DBLE(L) */
/*      ELSE */
/*        FL = -0.5*DBLE(L) */
/*        FR = 9.0*DBLE(L) */
/*      ENDIF */
/*     Estimate the root based on past ratio with the previous */
/*     flow. */
/* SOURCE chanrat.for:339 */
/*<       qmid=qratio*qmax >*/
    qmid = static_cast<double>(*qratio) * qmax;
/* SOURCE chanrat.for:340 */
/*<       if(qmid.le.qmin)then >*/
    if (qmid <= qmin) {
/* SOURCE chanrat.for:341 */
/*<       qmid=0.125*qmax+0.875*qmin >*/
	qmid = static_cast<double>(static_cast<double>(qmax) * (float).125) + static_cast<double>(qmin) * (float).875;
/* SOURCE chanrat.for:342 */
/*<       elseif(qmid.ge.qmax)then >*/
    } else if (qmid >= qmax) {
/* SOURCE chanrat.for:343 */
/*<       qmid=0.125*qmin+0.875*qmax >*/
	qmid = static_cast<double>(static_cast<double>(qmin) * (float).125) + static_cast<double>(qmax) * (float).875;
/* SOURCE chanrat.for:344 */
/*<       endif >*/
    }
/*     Establish sign change for regula falsi. */
/*     Does detailed analysis for checking */
/*      CALL FIND_ROOT_INTERVAL(STDOUT, SBPRES, */
/*     M                        QMIN, QMAX, QMID, */
/*     O                        FL, FR) */
/*      CALL FIND_ROOT_INTERVAL(STDOUT, SBPRES, QMIN, QMAX) */
/*     Establish sign change for regula falsi. */
/* SOURCE chanrat.for:354 */
/*<       if(yr.lt.yl)then >*/
    if (chncom_1.yr < chncom_1.yl) {
/* SOURCE chanrat.for:355 */
/*<       fl=9.0*dble(l) >*/
	fl = (doublereal) chncom_1.l * (float)9.;
/* SOURCE chanrat.for:356 */
/*<       fr=-0.5*dble(l) >*/
	fr = (doublereal) chncom_1.l * (float)-.5;
/* SOURCE chanrat.for:357 */
/*<       else >*/
    } else {
/* SOURCE chanrat.for:358 */
/*<       fl=-0.5*dble(l) >*/
	fl = (doublereal) chncom_1.l * (float)-.5;
/* SOURCE chanrat.for:359 */
/*<       fr=9.0*dble(l) >*/
	fr = (doublereal) chncom_1.l * (float)9.;
/* SOURCE chanrat.for:360 */
/*<       endif >*/
    }
/* SOURCE chanrat.for:362 */
/*<       calldblrgf(dble(epsarg),epsint,sbpres,qmin,qmax,fl,fr,qmid,rflag) >*/
    feq_gen_d_d_1 = (doublereal) epscom_1.epsarg;
    dblrgf_(&feq_gen_d_d_1, &epscom_1.epsint, sbpres_, &qmin, &qmax, &fl, &fr, &
	    qmid, &rflag);
/* SOURCE chanrat.for:366 */
/*<       if(rflag.gt.0)then >*/
    if (rflag > 0) {
/* SOURCE chanrat.for:367 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chanrat.for:368 */
/*<       if(rflag.eq.1)then >*/
	if (rflag == 1) {
/* SOURCE chanrat.for:369 */
/*<       write(stdout,51) >*/
	    feq_gen_io_d__39.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__39);
	    e_wsfe();
/* SOURCE chanrat.for:370 */
/*<       elseif(rflag.eq.2)then >*/
	} else if (rflag == 2) {
/* SOURCE chanrat.for:371 */
/*<       write(stdout,52) >*/
	    feq_gen_io_d__40.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__40);
	    e_wsfe();
/* SOURCE chanrat.for:372 */
/*<       else >*/
	} else {
/* SOURCE chanrat.for:373 */
/*<       write(stdout,53)fl >*/
	    feq_gen_io_d__41.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__41);
	    do_fio(&feq_gen_c_d_1, (char *)&fl, (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* SOURCE chanrat.for:374 */
/*<       endif >*/
	}
/* SOURCE chanrat.for:375 */
/*<       endif >*/
    }
/*     Compute the solution ratio to use in estimating the starting */
/*     point for the next upstream head in the sequence. */
/* SOURCE chanrat.for:378 */
/*<       qratio=qmid/qmax >*/
    *qratio = qmid / qmax;
/*      IF(QRATIO.GT.0.98) QRATIO = 0.98 */
/* SOURCE chanrat.for:381 */
/*<       q=qmid >*/
    chncom_1.q = qmid;
/* SOURCE chanrat.for:383 */
/*<       return >*/
    return 0;
/* SOURCE chanrat.for:384 */
/*<       end >*/
} /* sbfchn_ */




/* SOURCE chanrat.for:388 */
/*<        >*/
/* Subroutine */ int frfchn_(integer *stdout, real *hup, real *hdatum, real *
	zbotl, real *zbotr, real *ratio, integer *eflag, real *qfree, real *
	fdrop)
{
    /* Format strings */
    static char fmt_50[] = "(/,\002 *ERR:627* SLOPE OF CHANNEL IS STEEP.\002)"
	    ;
    static char fmt_51[] = "(/,\002 *BUG in FRFCHN: No sign change on entry \
to DBLRGF.\002)";
    static char fmt_52[] = "(/,\002 *BUG in FRFCHN: More than 100 iterations\
 in DBLRGF.\002)";
    static char fmt_53[] = "(/,\002 *BUG in FRFCHN: Argument collapse with r\
esidual more\002,\002 than twice EPSINT in DBLRGF.\002)";

    /* System generated locals */
    real feq_gen_r_d_1, feq_gen_r_d_2;
    doublereal feq_gen_d_d_1;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsfe(cilist *), e_wsfe();

    /* Local variables */
    real a, j, k, t, dk;
    doublereal fl;
    real dt;
    doublereal fr;
    real zr, beta;
    double zl;
    doublereal lhat, ymid;
    extern /* Subroutine */ int qfun_(real *, real *, FeqCallback1, real *, 
	    doublereal *);
    real ymin, ymax, dbeta, alpha;
    integer rflag;
    real ynear;
    extern doublereal fdxdy_(doublereal *);
    extern /* Subroutine */ int fndcde_(integer *, integer *, real *, real *);
    real dalpha;
    extern /* Subroutine */ int dblrgf_(doublereal *, doublereal *, FeqCallback1, 
	    real *, real *, doublereal *, doublereal *, doublereal *, integer 
	    *);
    extern doublereal ffpres_(doublereal *);
    extern /* Subroutine */ int xlktal_(integer *, real *, real *, real *, 
	    real *, real *, real *, real *, real *, real *, real *, real *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__54 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__63 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__64 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__65 = { 0, 0, 0, fmt_53, 0 };


/*     + + + PURPOSE + + + */
/*     Find free flow in a prismatic channel for the CHANRAT command. */
/* SOURCE chanrat.for:396 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE chanrat.for:399 */
/*<       integereflag,stdout >*/
/* SOURCE chanrat.for:400 */
/*<       realfdrop,hdatum,hup,qfree,ratio,zbotl,zbotr >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     HUP    - Head upstream */
/*     HDATUM - Datum for measuring head */
/*     ZBOTL  - Bottom elevation at left section */
/*     ZBOTR  - Bottom elevation at right section */
/*     RATIO  - Estimated ratio of downstream depth to upstream */
/*              depth. */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     QFREE  - Free flow */
/*     FDROP  - Free drop value */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE chanrat.for:415 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE chanrat.for:416 */
/*     COMMON BLOCK FOR  CHANNEL RATING */
/* SOURCE chncom.cmn:3 */
/*<       integerxsadr >*/
/* SOURCE chncom.cmn:5 */
/*<       realq,qn,l,sbot,yl,yr,qerr,lstres,nddabs,nddrel,frfac >*/
/* SOURCE chncom.cmn:8 */
/*<        >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE chanrat.for:419 */
/*<       integerrflag >*/
/* SOURCE chanrat.for:420 */
/*<       reala,alpha,beta,dalpha,dbeta,dk,dt,j,k,t,ymax,ymin,ynear,zl,zr >*/
/* SOURCE chanrat.for:422 */
/*<       doubleprecisionlhat,fl,fr,ymid >*/
/*     + + + INTRINSICS + + + */
/* SOURCE chanrat.for:425 */
/*<       intrinsicdble,max,sqrt >*/
/*     + + + EXTERNAL FUNCTIONS + + + */
/* SOURCE chanrat.for:428 */
/*<       doubleprecisionfdxdy,ffpres >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE chanrat.for:431 */
/*<       externalfdxdy,ffpres,fndcde,qfun,dblrgf,xlktal >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE chanrat.for:434 */
/*<    50 format(/,' *ERR:627* SLOPE OF CHANNEL IS STEEP.') >*/
/* SOURCE chanrat.for:435 */
/*<    51 format(/,' *BUG in FRFCHN: No sign change on entry to DBLRGF.') >*/
/* SOURCE chanrat.for:436 */
/*<    52 format(/,' *BUG in FRFCHN: More than 100 iterations in DBLRGF.') >*/
/* SOURCE chanrat.for:437 */
/*<    53  >*/
/* *********************************************************************** */
/*     WRITE(STDOUT,*) ' ENTERING FRFCHN. HUP=',HUP */
/*     FIND DEPTH AT UPSTREAM END(LEFT END). */
/* SOURCE chanrat.for:442 */
/*<       zl=hup+hdatum >*/
/* L50: */
/* L51: */
/* L52: */
/* L53: */
    zl = feq::channel_upstream_elevation(*hup,*hdatum);
/* SOURCE chanrat.for:443 */
/*<       yl=zl-zbotl >*/
    chncom_1.yl = static_cast<double>(zl) - *zbotl;
/*     WRITE(STDOUT,*) ' FRFCHN: YL=',YL */
/*     DOES NORMAL FLOW EXIST? */
/* SOURCE chanrat.for:446 */
/*<       if(sbot.gt.0.0)then >*/
    if (chncom_1.sbot > (float)0.) {
/*       YES. */
/* SOURCE chanrat.for:449 */
/*<       callxlktal(xsadr,yl,a,t,dt,j,k,dk,beta,dbeta,alpha,dalpha) >*/
	xlktal_(&chncom_1.xsadr, &chncom_1.yl, &a, &t, &dt, &j, &k, &dk, &
		beta, &dbeta, &alpha, &dalpha);
/* SOURCE chanrat.for:454 */
/*<       qn=k*sqrt(sbot) >*/
	chncom_1.qn = feq::steady_normal_flow(k,chncom_1.sbot);
/*       FIND CRITICAL DEPTH AT QN */
/* SOURCE chanrat.for:457 */
/*<       ymin=yl >*/
	ymin = chncom_1.yl;
/* SOURCE chanrat.for:458 */
/*<       callfndcde(stdout,xsadr,qn,ymin) >*/
	fndcde_(stdout, &chncom_1.xsadr, &chncom_1.qn, &ymin);
/* SOURCE chanrat.for:462 */
/*<       if(ymin.gt.yl)then >*/
	if (ymin > chncom_1.yl) {
/* SOURCE chanrat.for:463 */
/*<       write(stdout,50) >*/
	    feq_gen_io_d__54.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__54);
	    e_wsfe();
/* SOURCE chanrat.for:464 */
/*<       eflag=1 >*/
	    *eflag = 1;
/* SOURCE chanrat.for:465 */
/*<       return >*/
	    return 0;
/* SOURCE chanrat.for:466 */
/*<       endif >*/
	}
/*       WRITE(STDOUT,*) ' FRFCHN. QN=',QN,' CRIT. DEPTH=',YMIN */
/*       DETERMINE IF THE CHANNEL IS LONG ENOUGH TO CAUSE THE */
/*       FLOW PROFILE WHEN STARTING AT YMIN(THAT IS AT CRITICAL */
/*       DEPTH FOR THE NORMAL FLOW)  TO ATTAIN CLOSELY TO */
/*       NORMAL DEPTH( YL IN THIS CASE) BEFORE THE END OF THE */
/*       CHANNEL IS REACHED. */
/* SOURCE chanrat.for:475 */
/*<       ynear=max((1.0-nddrel)*yl,yl-nddabs) >*/
/* Computing MAX */
	feq_gen_r_d_1 = static_cast<double>((static_cast<double>((float)1.) - chncom_1.nddrel)) * chncom_1.yl, feq_gen_r_d_2 = 
		static_cast<double>(chncom_1.yl) - chncom_1.nddabs;
	ynear = dmax(feq_gen_r_d_1,feq_gen_r_d_2);
/* SOURCE chanrat.for:476 */
/*<       q=qn >*/
	chncom_1.q = chncom_1.qn;
/* SOURCE chanrat.for:477 */
/*<       callqfun(ynear,ymin,fdxdy,qerr,lhat) >*/
	qfun_(&ynear, &ymin, fdxdy_, &chncom_1.qerr, &lhat);
/*        WRITE(STDOUT,*) ' FRFCHN: YNEAR=',YNEAR */
/*        WRITE(STDOUT,*) ' FRFCHN: LHAT=',LHAT,' L=',L,' QERR=',QERR */
/* SOURCE chanrat.for:483 */
/*<       if(lhat.lt.l)then >*/
	if (lhat < chncom_1.l) {
/*         THE FLOW IS THE SAME AS NORMAL FLOW. */
/* SOURCE chanrat.for:485 */
/*<       yr=ymin >*/
	    chncom_1.yr = ymin;
/* SOURCE chanrat.for:486 */
/*<       zr=yr+zbotr >*/
	    zr = static_cast<double>(chncom_1.yr) + *zbotr;
/* SOURCE chanrat.for:488 */
/*<       fdrop=zl-zr >*/
	    *fdrop = feq::channel_free_drop(zl,chncom_1.yr,*zbotr);
/* SOURCE chanrat.for:489 */
/*<       qfree=q >*/
	    *qfree = chncom_1.q;
/* SOURCE chanrat.for:490 */
/*<       return >*/
	    return 0;
/* SOURCE chanrat.for:491 */
/*<       endif >*/
	}
/*       THE ROOT IS SOMEWHERE IN YMIN < Y < YL.  IF YR = YL THEN */
/*       THE PROFILE LENGTH, LHAT, IS 0 AND IF YR = YMIN THEN */
/*       LHAT = INFINITY. */
/* SOURCE chanrat.for:496 */
/*<       else >*/
    } else {
/*       IN THIS CASE THERE IS NO NORMAL DEPTH AND THE MINIMUM DEPTH */
/*       CAN APPROACH ZERO. */
/* SOURCE chanrat.for:499 */
/*<       ymin=epsarg >*/
	ymin = epscom_1.epsarg;
/* SOURCE chanrat.for:500 */
/*<       endif >*/
    }
/*     MAXIMUM DEPTH AT THE DOWNSTREAM END IS YL. */
/* SOURCE chanrat.for:503 */
/*<       ymax=yl >*/
    ymax = chncom_1.yl;
/*     Start with rough estimates of the two extremes. */
/* SOURCE chanrat.for:505 */
/*<       fl=-dble(l) >*/
    fl = -((doublereal) chncom_1.l);
/* SOURCE chanrat.for:506 */
/*<       fr=1.5*dble(l) >*/
    fr = (doublereal) chncom_1.l * (float)1.5;
/* SOURCE chanrat.for:507 */
/*<       ymid=ratio*yl >*/
    ymid = static_cast<double>(*ratio) * chncom_1.yl;
/* SOURCE chanrat.for:508 */
/*<       if(ymid.lt.ymin)then >*/
    if (ymid < ymin) {
/* SOURCE chanrat.for:509 */
/*<       ymid=0.125*ymax+0.875*ymin >*/
	ymid = static_cast<double>(static_cast<double>(ymax) * (float).125) + static_cast<double>(ymin) * (float).875;
/* SOURCE chanrat.for:510 */
/*<       elseif(ymid.gt.ymax)then >*/
    } else if (ymid > ymax) {
/* SOURCE chanrat.for:511 */
/*<       ymid=0.125*ymin+0.875*ymax >*/
	ymid = static_cast<double>(static_cast<double>(ymin) * (float).125) + static_cast<double>(ymax) * (float).875;
/* SOURCE chanrat.for:512 */
/*<       endif >*/
    }
/* SOURCE chanrat.for:513 */
/*<       calldblrgf(dble(epsarg),epsint,ffpres,ymax,ymin,fl,fr,ymid,rflag) >*/
    feq_gen_d_d_1 = (doublereal) epscom_1.epsarg;
    dblrgf_(&feq_gen_d_d_1, &epscom_1.epsint, ffpres_, &ymax, &ymin, &fl, &fr, &
	    ymid, &rflag);
/* SOURCE chanrat.for:517 */
/*<       if(rflag.gt.0)then >*/
    if (rflag > 0) {
/* SOURCE chanrat.for:518 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chanrat.for:519 */
/*<       if(rflag.eq.1)then >*/
	if (rflag == 1) {
/* SOURCE chanrat.for:520 */
/*<       write(stdout,51) >*/
	    feq_gen_io_d__63.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__63);
	    e_wsfe();
/* SOURCE chanrat.for:521 */
/*<       elseif(rflag.eq.2)then >*/
	} else if (rflag == 2) {
/* SOURCE chanrat.for:522 */
/*<       write(stdout,52) >*/
	    feq_gen_io_d__64.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__64);
	    e_wsfe();
/* SOURCE chanrat.for:523 */
/*<       else >*/
	} else {
/* SOURCE chanrat.for:524 */
/*<       write(stdout,53) >*/
	    feq_gen_io_d__65.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__65);
	    e_wsfe();
/* SOURCE chanrat.for:525 */
/*<       endif >*/
	}
/* SOURCE chanrat.for:526 */
/*<       endif >*/
    }
/*     Compute the solution ratio to use in estimating the starting */
/*     point for the next upstream head in the sequence. */
/* SOURCE chanrat.for:529 */
/*<       ratio=ymid/yl >*/
    *ratio = ymid / chncom_1.yl;
/* SOURCE chanrat.for:530 */
/*<       yr=ymid >*/
    chncom_1.yr = ymid;
/* SOURCE chanrat.for:531 */
/*<       zr=yr+zbotr >*/
    zr = static_cast<double>(chncom_1.yr) + *zbotr;
/* SOURCE chanrat.for:533 */
/*<       fdrop=zl-zr >*/
    *fdrop = feq::channel_free_drop(zl,chncom_1.yr,*zbotr);
/* SOURCE chanrat.for:534 */
/*<       qfree=q >*/
    *qfree = chncom_1.q;
/* SOURCE chanrat.for:536 */
/*<       return >*/
    return 0;
/* SOURCE chanrat.for:537 */
/*<       end >*/
} /* frfchn_ */




/* SOURCE chanrat.for:541 */
/*<       subroutinechntab(stdin,stdout,stdtab,grv,minq,tabdir,eflag,ftp) >*/
/* Subroutine */ int chntab_(integer *stdin, integer *stdout, integer *stdtab,
	 real *grv, real *minq, integer *feq_storage_tabdir, integer *eflag, integer *ftp)
{
    /* Initialized data */

    static doublereal dnull = -3.3e7;

    /* Format strings */
    static char fmt_2[] = "(a5,1x,a)";
    static char fmt_6[] = "(a6,1x,f10.0,1x,8x,a10)";
    static char fmt_8[] = "(a6,1x,f10.0)";
    static char fmt_16[] = "(a5,1x,f10.0)";
    static char fmt_24[] = "(a80)";
    static char fmt_26[] = "(a5,1x,i5)";
    static char fmt_50[] = "(/,\002 TABID= \002,a,\002  TYPE=\002,i5)";
    static char fmt_51[] = "(/,\002 Upstream Head=\002,f9.4,\002  Free Drop\
=\002,f9.4,\002 Normal Flow=\002,f15.3)";
    static char fmt_52[] = "(/,\002 \002,a5,\002=\002,a)";
    static char fmt_53[] = "(1x,\002 PartialFD  Dns Head      Flow    QdrErr\
  RelError\002)";
    static char fmt_54[] = "(/,\002 \002,\002XSTAB= \002,a)";
    static char fmt_55[] = "(1x,f10.6,f10.4,2x,a8,f10.4)";
    static char fmt_56[] = "(\002 \002,a6,\002=\002,f10.4)";
    static char fmt_57[] = "(1x,f10.6,f10.4,2x,a8,f10.4,f10.3)";
    static char fmt_58[] = "(\002 \002,a6,\002=\002,f10.1,\002 Middle elevat\
ion=\002,f10.4)";
    static char fmt_60[] = "(\002   Free flow interpolation between head=\
\002,f9.4,\002 and \002,f9.4,/,\002   has estimated maximum relative\002,\
\002 error of\002,f6.3)";
    static char fmt_61[] = "(/,\002 Maximum estimated relative error=\002,f8\
.3,\002 is in free\002,\002 flow\002,/,5x,\002 between heads=\002,f8.3,\002 \
and \002,f8.3)";
    static char fmt_62[] = "(/,\002 Estimated root-mean-square error=\002,f8\
.3)";
    static char fmt_63[] = "(/,\002 Maximum estimated relative error=\002,f8\
.3,\002 is in \002,\002submerged flow\002,/,5x,\002at ups. head=\002,f8.3\
,\002 between PFD=\002,f8.4,\002 and \002,f8.4)";
    static char fmt_64[] = "(/,\002 \002,f5.2,\002 of checked points had err\
or > LIPREC and\002,f5.2,\002 had error > 2*LIPREC.\002)";
    static char fmt_66[] = "(\002 \002,a5,\002=\002,f10.2)";
    static char fmt_68[] = "(\002; Flow defining minimum head=\002,f10.3)";
    static char fmt_71[] = "(/,\002  Table type 5 replaced by type 13.\002)";
    static char fmt_72[] = "(/,\002 *ERR:628* Channel length <= 0.0. must be\
 > 0.0.\002)";
    static char fmt_74[] = "(/,\002 *ERR:629* ERRKND=\002,i5,\002 invalid. r\
ange 0 through 1.\002)";
    static char fmt_76[] = "(/,\002 Adaptive Simpson's rule for steady flow\
.\002)";
    static char fmt_77[] = "(/,\002 Romberg rule deleted. Using Adaptive Sim\
pson's rule.\002)";
    static char fmt_78[] = "(/,\002 Integration error tolerance=\002,f7.3)";
    static char fmt_79[] = "(/,\002 Requested linear interpolation precisi\
on=\002,f5.3)";
    static char fmt_80[] = "(/,\002 Minimum partial free drop=\002,f8.3)";
    static char fmt_81[] = "(/,\002 Upstream Head=\002,f9.4,\002  Free Drop\
=\002,f9.4)";
    static char fmt_82[] = "(3x,\002 Ups WS Elevation=\002,f9.4)";
    static char fmt_83[] = "(/,\002 Minimum flow target=\002,f10.3)";
    static char fmt_87[] = "(/\002 *ERR:607* TABLE# <= 0\002)";
    static char fmt_88[] = "(/,\002 Checking cross section table for possibl\
e critical\002,\002 flow\002,/,5x,\002 problems.\002)";
    static char fmt_89[] = "(/,\002 *WRN:551* CHANRAT command may not conver\
ge because\002,\002 critical\002,/,10x,\002 flow decreases.\002)";
    static char fmt_91[] = "(/,\002 Normal depth deviation-absolute=\002,f8.\
4,/,1x,\002Normal depth deviation-relative=\002,f8.4)";
    static char fmt_92[] = "(/,\002 \002,a80)";
    static char fmt_94[] = "(/,\002 \002,a5,\002=\002,i5)";
    static char fmt_95[] = "(/,\002 \002,\002Input complete. begin computati\
ons\002)";
    static char fmt_96[] = "(/,\002 \002,\002Datum for heads is:\002,f10.2)";
    static char fmt_98[] = "(\002 *ERR:589* table type not 6 or 13.\002)";
    static char fmt_99[] = "(/,\002 *ERR:630* Upstream heads non-increasing \
at:\002,f10.2)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;
    char feq_gen_ch_d_1[16];
    cilist feq_gen_ci_d_1;
    icilist feq_gen_ici_d_1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rsfi(icilist *), e_rsfi(), s_cmp(char *, char *, ftnlen, ftnlen)
	    ;
    /* Subroutine */ int s_stop(char *, ftnlen);
    double pow_dd(doublereal *, doublereal *), sqrt(doublereal);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle();

    /* Local variables */
    extern /* Subroutine */ int feq_gen_set_chnrt_items_d_(integer *, integer *, 
	    integer *, integer *, integer *, real *, real *, real *, real *, 
	    char *, char *, char *, char *, char *, doublereal *, doublereal *
	    , ftnlen, ftnlen, ftnlen, ftnlen, ftnlen);
    doublereal northing;
    integer feq_gen_i_d_, j, n;
    extern /* Character */ VOID feq_gen_get_tabid_d_(char *, ftnlen, integer *);
    real feq_gen_rms_error_d_;
    char cq[8];
    extern /* Subroutine */ int feq_gen_read_tabid_d_(integer *, char *, char *, 
	    integer *, char *, integer *, ftnlen, ftnlen, ftnlen), 
	    feq_gen_tab_in_use_d_(char *, integer *, ftnlen);
    real feq_gen_local_minq_d_;
    integer feq_gen_n_gt_twice_d_, tab, nhu;
    real hup;
    extern /* Subroutine */ int feq_gen_var_decimal_d_(real *, char *, ftnlen), 
	    feq_gen_chanrat_opt_d_(integer *, real *, real *, real *, real *, real *, 
	    real *, integer *, real *, integer *, real *, integer *);
    integer feq_gen_location_hu_d_;
    char feq_gen_elev_string_d_[10];
    real feq_gen_epsint_sngl_d_;
    char head[80];
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    real fmid;
    integer feq_gen_n_gt_d_;
    char line[80];
    real elev, xmid, qmat[53001]	/* was [151][351] */, drop, rerr;
    char zone[8];
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    integer feq_gen_location_pfd_d_;
    char char5[5], char6[6];
    real feq_gen_global_error_d_;
    integer feq_gen_xstab_number_d_;
    char label[50], tabid[16];
    real fdvec[151];
    integer nfrac;
    char hgrid[8];
    integer wflag;
    char basis[8];
    real qfree;
    integer xstab;
    real fdrop, huold, huvec[151], zbotl, power;
    integer ftpup;
    real zbotr;
    extern /* Subroutine */ int chkcfc_(real *, integer *, integer *, integer 
	    *), chktab_(integer *, integer *, integer *, integer *, integer *,
	     integer *), sbfchn_(integer *, real *, integer *), frfchn_(
	    integer *, real *, real *, real *, real *, real *, integer *, 
	    real *, real *);
    real pfdvec[351], hdatum, length, liprec, minpfd;
    integer tabtyp;
    real botslp, qratio, yratio, zrhufd;
    doublereal siesqr;
    char vdatum[8];
    extern integer lenstr_(char *, ftnlen);
    extern /* Subroutine */ int inline_(integer *, integer *, char *, ftnlen),
	     twdout_(integer *, integer *, integer *, char *, integer *, 
	    integer *, real *, real *, real *, real *, real *, integer *, 
	    char *, real *, char *, char *, char *, char *, char *, 
	    doublereal *, doublereal *, integer *, ftnlen, ftnlen, ftnlen, 
	    ftnlen, ftnlen, ftnlen, ftnlen), fndelv_(integer *, integer *, 
	    integer *, real *), feq_gen_strip_l_blanks_d_(char *, ftnlen), 
	    feq_gen_get_east_north_d_(integer *, integer *, doublereal *, doublereal *)
	    ;
    real feq_gen_qd_span_d_;
    doublereal easting;
    char xstabid[16];
    integer verbose;
    extern /* Subroutine */ int twodfit_(integer *, integer *, integer *, 
	    integer *, real *, real *, real *, real *, real *, integer *, 
	    char *, real *, integer *, integer *, integer *, integer *, 
	    ftnlen), feq_gen_get_chnrt_items_d_(integer *, integer *, integer *);
    char unitsys[8];

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__83 = { 0, 0, 0, fmt_71, 0 };
    static cilist feq_gen_io_d__84 = { 0, 0, 0, fmt_98, 0 };
    static cilist feq_gen_io_d__85 = { 0, 0, 0, fmt_74, 0 };
    static cilist feq_gen_io_d__87 = { 0, 0, 0, fmt_50, 0 };
    static cilist feq_gen_io_d__88 = { 0, 0, 0, fmt_76, 0 };
    static cilist feq_gen_io_d__89 = { 0, 0, 0, fmt_77, 0 };
    static cilist feq_gen_io_d__90 = { 0, 0, 0, fmt_78, 0 };
    static cilist feq_gen_io_d__91 = { 0, 0, 0, fmt_91, 0 };
    static cilist feq_gen_io_d__92 = { 0, 0, 0, fmt_83, 0 };
    static cilist feq_gen_io_d__93 = { 0, 0, 0, fmt_68, 0 };
    static cilist feq_gen_io_d__97 = { 0, 0, 0, fmt_52, 0 };
    static cilist feq_gen_io_d__100 = { 0, 0, 0, fmt_54, 0 };
    static cilist feq_gen_io_d__102 = { 0, 0, 0, fmt_87, 0 };
    static cilist feq_gen_io_d__105 = { 0, 0, 0, fmt_56, 0 };
    static cilist feq_gen_io_d__109 = { 0, 0, 0, fmt_58, 0 };
    static cilist feq_gen_io_d__110 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__112 = { 0, 0, 0, fmt_92, 0 };
    static cilist feq_gen_io_d__114 = { 0, 0, 0, fmt_94, 0 };
    static cilist feq_gen_io_d__116 = { 0, 0, 0, fmt_66, 0 };
    static cilist feq_gen_io_d__119 = { 0, 0, 0, fmt_79, 0 };
    static cilist feq_gen_io_d__121 = { 0, 0, 0, fmt_80, 0 };
    static cilist feq_gen_io_d__124 = { 0, 0, 0, fmt_99, 0 };
    static cilist feq_gen_io_d__125 = { 0, 0, 0, fmt_88, 0 };
    static cilist feq_gen_io_d__127 = { 0, 0, 0, fmt_89, 0 };
    static cilist feq_gen_io_d__128 = { 0, 0, 0, fmt_95, 0 };
    static cilist feq_gen_io_d__133 = { 0, 0, 0, fmt_96, 0 };
    static cilist feq_gen_io_d__148 = { 0, 0, 0, fmt_60, 0 };
    static cilist feq_gen_io_d__151 = { 0, 0, 0, fmt_51, 0 };
    static cilist feq_gen_io_d__152 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__153 = { 0, 0, 0, fmt_81, 0 };
    static cilist feq_gen_io_d__154 = { 0, 0, 0, fmt_82, 0 };
    static cilist feq_gen_io_d__155 = { 0, 0, 0, fmt_53, 0 };
    static cilist feq_gen_io_d__157 = { 0, 0, 0, fmt_55, 0 };
    static cilist feq_gen_io_d__161 = { 0, 0, 0, fmt_57, 0 };
    static cilist feq_gen_io_d__162 = { 0, 0, 0, fmt_61, 0 };
    static cilist feq_gen_io_d__163 = { 0, 0, 0, fmt_63, 0 };
    static cilist feq_gen_io_d__165 = { 0, 0, 0, fmt_62, 0 };
    static cilist feq_gen_io_d__167 = { 0, 0, 0, fmt_64, 0 };
    static cilist feq_gen_io_d__170 = { 0, 0, 0, 0, 0 };
    static cilist feq_gen_io_d__171 = { 0, 0, 0, 0, 0 };


/*     + + + PURPOSE + + + */
/*     Compute a 2D table for flow through prismatic channel reach, */
/*     that is, for command CHANRAT */
/* SOURCE chanrat.for:549 */
/*<       implicitnone >*/
/*     + + + DUMMY ARGUMENTS + + + */
/* SOURCE chanrat.for:551 */
/*<       integereflag,ftp,stdin,stdout,stdtab >*/
/* SOURCE chanrat.for:552 */
/*<       integertabdir(*) >*/
/* SOURCE chanrat.for:553 */
/*<       realgrv,minq >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDIN  - Fortran unit number for user input file */
/*     STDOUT - Fortran unit number for user output and messages */
/*     STDTAB - Fortran unit number for output of function tables */
/*     GRV    - value of acceleration due to gravity */
/*     TABDIR - Table directory to remember table numbers */
/*     EFLAG  - Error flag: EFLAG=0-no errors; else one or more errors */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE chanrat.for:564 */
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
/* INCLUDE chanrat.for:565 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE chanrat.for:566 */
/*     COMMON BLOCK FOR  CHANNEL RATING */
/* SOURCE chncom.cmn:3 */
/*<       integerxsadr >*/
/* SOURCE chncom.cmn:5 */
/*<       realq,qn,l,sbot,yl,yr,qerr,lstres,nddabs,nddrel,frfac >*/
/* SOURCE chncom.cmn:8 */
/*<        >*/
/* INCLUDE chanrat.for:567 */
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
/* INCLUDE chanrat.for:568 */
/*     common for passing info for table upgrading-going from one form */
/*     to one that is smoother in its representation */
/* SOURCE tabupgrade.cmn:4 */
/*<       characterty13_to_ty43*4,twod_cubic_out*4,upgrade_xsec_tab*4 >*/
/* SOURCE tabupgrade.cmn:6 */
/*<       common/upgrdc/ty13_to_ty43,twod_cubic_out,upgrade_xsec_tab >*/
/*     + + + LOCAL VARIABLES + + + */
/* SOURCE chanrat.for:571 */
/*<        >*/
/* SOURCE chanrat.for:574 */
/*<        >*/
/* SOURCE chanrat.for:580 */
/*<       real*8siesqr,easting,northing,dnull >*/
/* SOURCE chanrat.for:581 */
/*<        >*/
/*     + + + INTRINSICS + + + */
/* SOURCE chanrat.for:587 */
/*<       intrinsicabs,float,max,min >*/
/*     + + + EXTERNAL NAMES + + + */
/* SOURCE chanrat.for:590 */
/*<       integerlenstr >*/
/* SOURCE chanrat.for:591 */
/*<       characterget_tabid*16 >*/
/* SOURCE chanrat.for:592 */
/*<        >*/
/*     + + + INPUT FORMATS + + + */
/* 1    FORMAT(7X,I5,1X,A4) */
/* SOURCE chanrat.for:596 */
/*<       datadnull/-33d6/ >*/
    /* Parameter adjustments */
    feq::IndexedPointer<integer> tabdir(feq_storage_tabdir, 1);

    /* Function Body */
/* SOURCE chanrat.for:599 */
/*<     2 format(a5,1x,a) >*/
/* L2: */
/* SOURCE chanrat.for:600 */
/*<     4 format(a6,1x,i5,2a5) >*/
/* L4: */
/* SOURCE chanrat.for:601 */
/*<     6 format(a6,1x,f10.0,1x,8x,a10) >*/
/* L6: */
/* SOURCE chanrat.for:602 */
/*<     8 format(a6,1x,f10.0) >*/
/* L8: */
/* SOURCE chanrat.for:603 */
/*<    16 format(a5,1x,f10.0) >*/
/* L16: */
/* SOURCE chanrat.for:604 */
/*<    24 format(a80) >*/
/* L24: */
/* SOURCE chanrat.for:605 */
/*<    26 format(a5,1x,i5) >*/
/* L26: */
/* SOURCE chanrat.for:606 */
/*<    27 format(a4,1x,i5,5a5) >*/
/* L27: */
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE chanrat.for:609 */
/*<    50 format(/,' TABID= ',a,'  TYPE=',i5) >*/
/* L50: */
/* SOURCE chanrat.for:610 */
/*<    51  >*/
/* L51: */
/* SOURCE chanrat.for:612 */
/*<    52 format(/,' ',a5,'=',a) >*/
/* L52: */
/* SOURCE chanrat.for:613 */
/*<    53 format(1x,' PartialFD  Dns Head      Flow    QdrErr  RelError') >*/
/* L53: */
/* SOURCE chanrat.for:614 */
/*<    54 format(/,' ','XSTAB= ',a) >*/
/* L54: */
/* SOURCE chanrat.for:615 */
/*<    55 format(1x,f10.6,f10.4,2x,a8,f10.4) >*/
/* L55: */
/* SOURCE chanrat.for:616 */
/*<    56 format(' ',a6,'=',f10.4) >*/
/* L56: */
/* SOURCE chanrat.for:617 */
/*<    57 format(1x,f10.6,f10.4,2x,a8,f10.4,f10.3) >*/
/* L57: */
/* SOURCE chanrat.for:618 */
/*<    58 format(' ',a6,'=',f10.1,' Middle elevation=',f10.4) >*/
/* L58: */
/* SOURCE chanrat.for:619 */
/*<    60  >*/
/* L60: */
/* SOURCE chanrat.for:622 */
/*<    61  >*/
/* L61: */
/* SOURCE chanrat.for:624 */
/*<    62 format(/,' Estimated root-mean-square error=',f8.3) >*/
/* L62: */
/* SOURCE chanrat.for:625 */
/*<    63  >*/
/* L63: */
/* SOURCE chanrat.for:628 */
/*<    64  >*/
/* L64: */
/* SOURCE chanrat.for:630 */
/*<    66 format(' ',a5,'=',f10.2) >*/
/* L66: */
/* SOURCE chanrat.for:631 */
/*<    68 format('; Flow defining minimum head=',f10.3) >*/
/* L68: */
/* SOURCE chanrat.for:632 */
/*<    71 format(/,'  Table type 5 replaced by type 13.') >*/
/* L71: */
/* SOURCE chanrat.for:633 */
/*<    72 format(/,' *ERR:628* Channel length <= 0.0. must be > 0.0.') >*/
/* L72: */
/* SOURCE chanrat.for:634 */
/*<    74 format(/,' *ERR:629* ERRKND=',i5,' invalid. range 0 through 1.') >*/
/* L74: */
/* SOURCE chanrat.for:635 */
/*<    76 format(/,' Adaptive Simpson''s rule for steady flow.') >*/
/* L76: */
/* SOURCE chanrat.for:636 */
/*<    77 format(/,' Romberg rule deleted. Using Adaptive Simpson''s rule.') >*/
/* L77: */
/* SOURCE chanrat.for:637 */
/*<    78 format(/,' Integration error tolerance=',f7.3) >*/
/* L78: */
/* SOURCE chanrat.for:638 */
/*<    79 format(/,' Requested linear interpolation precision=',f5.3) >*/
/* L79: */
/* SOURCE chanrat.for:639 */
/*<    80 format(/,' Minimum partial free drop=',f8.3) >*/
/* L80: */
/* SOURCE chanrat.for:640 */
/*<    81 format(/,' Upstream Head=',f9.4,'  Free Drop=',f9.4) >*/
/* L81: */
/* SOURCE chanrat.for:641 */
/*<    82 format(3x,' Ups WS Elevation=',f9.4) >*/
/* L82: */
/* SOURCE chanrat.for:642 */
/*<    83 format(/,' Minimum flow target=',f10.3) >*/
/* L83: */
/* SOURCE chanrat.for:643 */
/*<    87 format(/' *ERR:607* TABLE# <= 0') >*/
/* L87: */
/* SOURCE chanrat.for:644 */
/*<    88  >*/
/* L88: */
/* SOURCE chanrat.for:646 */
/*<    89  >*/
/* L89: */
/* SOURCE chanrat.for:648 */
/*<    90 format('  Processing CHANRAT TabId= ',a) >*/
/* L90: */
/* SOURCE chanrat.for:649 */
/*<    91  >*/
/* L91: */
/* SOURCE chanrat.for:651 */
/*<    92 format(/,' ',a80) >*/
/* L92: */
/* SOURCE chanrat.for:652 */
/*<    94 format(/,' ',a5,'=',i5) >*/
/* L94: */
/* SOURCE chanrat.for:653 */
/*<    95 format(/,' ','Input complete. begin computations') >*/
/* L95: */
/* SOURCE chanrat.for:654 */
/*<    96 format(/,' ','Datum for heads is:',f10.2) >*/
/* L96: */
/* SOURCE chanrat.for:655 */
/*<    97 format(' ',a4,'=',i5,5a5) >*/
/* L97: */
/* SOURCE chanrat.for:656 */
/*<    98 format(' *ERR:589* table type not 6 or 13.') >*/
/* L98: */
/* SOURCE chanrat.for:657 */
/*<    99 format(/,' *ERR:630* Upstream heads non-increasing at:',f10.2) >*/
/* L99: */
/* *********************************************************************** */
/*      write(stdout,*) ' chntab: ftp=',ftp,' on entry.' */
/*     Clear the global value of error. */
/* SOURCE chanrat.for:662 */
/*<       global_error=0.0 >*/
    feq_gen_global_error_d_ = (float)0.;
/*     Clear the linear interpolation precision */
/* SOURCE chanrat.for:665 */
/*<       liprec=0.0 >*/
    liprec = (float)0.;
/* SOURCE chanrat.for:667 */
/*<       callget_chnrt_items(stdin,stdout,eflag) >*/
    feq_gen_get_chnrt_items_d_(stdin, stdout, eflag);
/* SOURCE chanrat.for:669 */
/*<        >*/
    feq_gen_set_chnrt_items_d_(eflag, &tab, &tabtyp, &epscom_1.errknd, &
	    epscom_1.inthow, &feq_gen_epsint_sngl_d_, &chncom_1.nddabs, &
	    chncom_1.nddrel, &feq_gen_local_minq_d_, zone, hgrid, vdatum, unitsys, 
	    basis, &easting, &northing, (ftnlen)8, (ftnlen)8, (ftnlen)8, (
	    ftnlen)8, (ftnlen)8);
/* SOURCE chanrat.for:676 */
/*<       epsint=dble(epsint_sngl) >*/
    epscom_1.epsint = (doublereal) feq_gen_epsint_sngl_d_;
/*     Check local min flow.  Default is 0.0 to force use of global */
/*     value. */
/* SOURCE chanrat.for:680 */
/*<       if(local_minq.eq.0.0)then >*/
    if (feq_gen_local_minq_d_ == (float)0.) {
/* SOURCE chanrat.for:681 */
/*<       local_minq=minq >*/
	feq_gen_local_minq_d_ = *minq;
/* SOURCE chanrat.for:682 */
/*<       endif >*/
    }
/* SOURCE chanrat.for:684 */
/*<       if(tabtyp.eq.5)then >*/
    if (tabtyp == 5) {
/* SOURCE chanrat.for:685 */
/*<       write(stdout,71) >*/
	feq_gen_io_d__83.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__83);
	e_wsfe();
/* SOURCE chanrat.for:686 */
/*<       tabtyp=13 >*/
	tabtyp = 13;
/* SOURCE chanrat.for:687 */
/*<       endif >*/
    }
/* SOURCE chanrat.for:688 */
/*<       if(tabtyp.ne.13.and.tabtyp.ne.6)then >*/
    if (tabtyp != 13 && tabtyp != 6) {
/* SOURCE chanrat.for:689 */
/*<       write(stdout,98) >*/
	feq_gen_io_d__84.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__84);
	e_wsfe();
/* SOURCE chanrat.for:690 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chanrat.for:691 */
/*<       endif >*/
    }
/* SOURCE chanrat.for:693 */
/*<       if(errknd.lt.0.or.errknd.gt.1)then >*/
    if (epscom_1.errknd < 0 || epscom_1.errknd > 1) {
/* SOURCE chanrat.for:694 */
/*<       write(stdout,74)errknd >*/
	feq_gen_io_d__85.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__85);
	do_fio(&feq_gen_c_d_1, (char *)&epscom_1.errknd, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE chanrat.for:695 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chanrat.for:696 */
/*<       endif >*/
    }
/* SOURCE chanrat.for:699 */
/*<       if(epsint.le.0.0)then >*/
    if (epscom_1.epsint <= (float)0.) {
/* SOURCE chanrat.for:700 */
/*<       if(grv.gt.15.0)then >*/
	if (*grv > (float)15.) {
/*         US standard unit */
/* SOURCE chanrat.for:702 */
/*<       epsint=0.1d0 >*/
	    epscom_1.epsint = .1;
/* SOURCE chanrat.for:703 */
/*<       else >*/
	} else {
/*         SI or metric */
/* SOURCE chanrat.for:705 */
/*<       epsint=0.030480d0 >*/
	    epscom_1.epsint = .03048;
/* SOURCE chanrat.for:706 */
/*<       endif >*/
	}
/* SOURCE chanrat.for:707 */
/*<       endif >*/
    }
/* SOURCE chanrat.for:709 */
/*<       if(nddabs.le.0.0)then >*/
    if (chncom_1.nddabs <= (float)0.) {
/* SOURCE chanrat.for:710 */
/*<       if(grv.gt.15.0)then >*/
	if (*grv > (float)15.) {
/* SOURCE chanrat.for:711 */
/*<       nddabs=0.005 >*/
	    chncom_1.nddabs = (float).005;
/* SOURCE chanrat.for:712 */
/*<       else >*/
	} else {
/* SOURCE chanrat.for:713 */
/*<       nddabs=0.001524 >*/
	    chncom_1.nddabs = (float).001524;
/* SOURCE chanrat.for:714 */
/*<       endif >*/
	}
/* SOURCE chanrat.for:715 */
/*<       endif >*/
    }
/* SOURCE chanrat.for:718 */
/*<       tabid=get_tabid(tab) >*/
    feq_gen_get_tabid_d_(feq_gen_ch_d_1, (ftnlen)16, &tab);
    s_copy(tabid, feq_gen_ch_d_1, (ftnlen)16, (ftnlen)16);
/* SOURCE chanrat.for:720 */
/*<       write(stdout,50)tabid(1:lenstr(tabid)),tabtyp >*/
    feq_gen_io_d__87.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__87);
    do_fio(&feq_gen_c_d_1, tabid, lenstr_(tabid, (ftnlen)16));
    do_fio(&feq_gen_c_d_1, (char *)&tabtyp, (ftnlen)sizeof(integer));
    e_wsfe();
/*     MAKE SURE TABLE NUMBER IS NOT ALREADY USED IN THIS INPUT */
/* SOURCE chanrat.for:724 */
/*<       if(ftpnt(tab).ne.0)calltab_in_use(tabid,eflag) >*/
    if (ftablea_1.ftpnt[tab - 1] != 0) {
	feq_gen_tab_in_use_d_(tabid, eflag, (ftnlen)16);
    }
/* SOURCE chanrat.for:728 */
/*<       if(inthow.eq.1)then >*/
    if (epscom_1.inthow == 1) {
/* SOURCE chanrat.for:729 */
/*<       write(stdout,76) >*/
	feq_gen_io_d__88.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__88);
	e_wsfe();
/* SOURCE chanrat.for:730 */
/*<       else >*/
    } else {
/* SOURCE chanrat.for:731 */
/*<       write(stdout,77) >*/
	feq_gen_io_d__89.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__89);
	e_wsfe();
/* SOURCE chanrat.for:732 */
/*<       inthow=1 >*/
	epscom_1.inthow = 1;
/* SOURCE chanrat.for:733 */
/*<       endif >*/
    }
/* SOURCE chanrat.for:734 */
/*<       write(stdout,78)epsint >*/
    feq_gen_io_d__90.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__90);
    do_fio(&feq_gen_c_d_1, (char *)&epscom_1.epsint, (ftnlen)sizeof(doublereal));
    e_wsfe();
/* SOURCE chanrat.for:735 */
/*<       write(stdout,91)nddabs,nddrel >*/
    feq_gen_io_d__91.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__91);
    do_fio(&feq_gen_c_d_1, (char *)&chncom_1.nddabs, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&chncom_1.nddrel, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE chanrat.for:736 */
/*<       write(stdout,83)local_minq >*/
    feq_gen_io_d__92.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__92);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_local_minq_d_, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE chanrat.for:737 */
/*<       write(stdtab,68)local_minq >*/
    feq_gen_io_d__93.ciunit = *stdtab;
    s_wsfe(&feq_gen_io_d__93);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_local_minq_d_, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE chanrat.for:740 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE chanrat.for:743 */
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
/* SOURCE chanrat.for:744 */
/*<       write(stdout,52)char5,label >*/
    feq_gen_io_d__97.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__97);
    do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, label, (ftnlen)50);
    e_wsfe();
/*     INPUT THE CROSS SECTION TABLE FOR THE CHANNEL */
/* SOURCE chanrat.for:747 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE chanrat.for:750 */
/*<       callread_tabid(stdout,line,'XSTAB',eflag,xstabid,xstab) >*/
    feq_gen_read_tabid_d_(stdout, line, const_cast<char*>("XSTAB"), eflag, xstabid, &xstab, (ftnlen)80, (
	    ftnlen)5, (ftnlen)16);
/* SOURCE chanrat.for:753 */
/*<       write(stdout,54)xstabid(1:lenstr(xstabid)) >*/
    feq_gen_io_d__100.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__100);
    do_fio(&feq_gen_c_d_1, xstabid, lenstr_(xstabid, (ftnlen)16));
    e_wsfe();
/*     Save the table number */
/* SOURCE chanrat.for:756 */
/*<       xstab_number=xstab >*/
    feq_gen_xstab_number_d_ = xstab;
/* SOURCE chanrat.for:757 */
/*<       if(xstab.le.0)then >*/
    if (xstab <= 0) {
/* SOURCE chanrat.for:758 */
/*<       write(stdout,87) >*/
	feq_gen_io_d__102.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__102);
	e_wsfe();
/* SOURCE chanrat.for:759 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chanrat.for:760 */
/*<       else >*/
    } else {
/* SOURCE chanrat.for:761 */
/*<       callchktab(12,stdout,ftpnt,mftnum,xstab,eflag) >*/
	chktab_(&feq_gen_c_d_12, stdout, ftablea_1.ftpnt, &feq_gen_c_d_10002, &xstab, eflag);
/* SOURCE chanrat.for:765 */
/*<       if(easting<=dnull)then >*/
	if (easting <= dnull) {
/*         Get values from the cross-section table. */
/* SOURCE chanrat.for:767 */
/*<       callget_east_north(stdout,xstab,easting,northing) >*/
	    feq_gen_get_east_north_d_(stdout, &xstab, &easting, &northing);
/* SOURCE chanrat.for:770 */
/*<       endif >*/
	}
/* SOURCE chanrat.for:771 */
/*<       endif >*/
    }
/* SOURCE chanrat.for:772 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE chanrat.for:775 */
/*<       read(line,6,err=991)char6,botslp >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&botslp, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE chanrat.for:777 */
/*<       write(stdout,56)char6,botslp >*/
    feq_gen_io_d__105.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__105);
    do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
    do_fio(&feq_gen_c_d_1, (char *)&botslp, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE chanrat.for:779 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE chanrat.for:782 */
/*<       read(line,6,err=991)char6,length,elev_string >*/
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
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&length, (ftnlen)sizeof(real));
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, feq_gen_elev_string_d_, (ftnlen)10);
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
    feq_gen_i_d_1 = e_rsfi();
    if (feq_gen_i_d_1 != 0) {
	goto L991;
    }
/* SOURCE chanrat.for:783 */
/*<       callstrip_l_blanks(elev_string) >*/
    feq_gen_strip_l_blanks_d_(feq_gen_elev_string_d_, (ftnlen)10);
/* SOURCE chanrat.for:785 */
/*<       if(elev_string.eq.'TAB'.or.elev_string.eq.'tab')then >*/
    if (s_cmp(feq_gen_elev_string_d_, const_cast<char*>("TAB"), (ftnlen)10, (ftnlen)3) == 0 || s_cmp(
	    feq_gen_elev_string_d_, const_cast<char*>("tab"), (ftnlen)10, (ftnlen)3) == 0) {
/*       Get the elevation from the function table. */
/* SOURCE chanrat.for:788 */
/*<       callfndelv(xstab_number,stdout,eflag,elev) >*/
	fndelv_(&feq_gen_xstab_number_d_, stdout, eflag, &elev);
/* SOURCE chanrat.for:791 */
/*<       else >*/
    } else {
/* SOURCE chanrat.for:792 */
/*<       read(elev_string,'(F10.0)',err=991)elev >*/
	feq_gen_ici_d_1.icierr = 1;
	feq_gen_ici_d_1.iciend = 0;
	feq_gen_ici_d_1.icirnum = 1;
	feq_gen_ici_d_1.icirlen = 10;
	feq_gen_ici_d_1.iciunit = feq_gen_elev_string_d_;
	feq_gen_ici_d_1.icifmt = const_cast<char*>("(F10.0)");
	feq_gen_i_d_1 = s_rsfi(&feq_gen_ici_d_1);
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, (char *)&elev, (ftnlen)sizeof(real));
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
	feq_gen_i_d_1 = e_rsfi();
	if (feq_gen_i_d_1 != 0) {
	    goto L991;
	}
/* SOURCE chanrat.for:793 */
/*<       endif >*/
    }
/* SOURCE chanrat.for:795 */
/*<       write(stdout,58)char6,length,elev >*/
    feq_gen_io_d__109.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__109);
    do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
    do_fio(&feq_gen_c_d_1, (char *)&length, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&elev, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE chanrat.for:797 */
/*<       if(length.le.0.0)then >*/
    if (length <= (float)0.) {
/* SOURCE chanrat.for:798 */
/*<       write(stdout,72) >*/
	feq_gen_io_d__110.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__110);
	e_wsfe();
/* SOURCE chanrat.for:799 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chanrat.for:800 */
/*<       endif >*/
    }
/*     INITIALIZE THE CONSTANT PART OF CHNCOM */
/* SOURCE chanrat.for:804 */
/*<       sbot=botslp >*/
    chncom_1.sbot = botslp;
/* SOURCE chanrat.for:805 */
/*<       l=length >*/
    chncom_1.l = length;
/* SOURCE chanrat.for:806 */
/*<       xsadr=xstab >*/
    chncom_1.xsadr = xstab;
/*     INPUT THE FACTORS CONTROLLING THE UPSTREAM HEADS AND THE */
/*     DISTRIBUTION OF DROPS */
/* SOURCE chanrat.for:811 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE chanrat.for:814 */
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
/* SOURCE chanrat.for:815 */
/*<       write(stdout,92)head >*/
    feq_gen_io_d__112.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__112);
    do_fio(&feq_gen_c_d_1, head, (ftnlen)80);
    e_wsfe();
/* SOURCE chanrat.for:817 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE chanrat.for:820 */
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
/* SOURCE chanrat.for:821 */
/*<       write(stdout,94)char5,nfrac >*/
    feq_gen_io_d__114.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__114);
    do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, (char *)&nfrac, (ftnlen)sizeof(integer));
    e_wsfe();
/* SOURCE chanrat.for:823 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE chanrat.for:826 */
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
/* SOURCE chanrat.for:827 */
/*<       write(stdout,66)char5,power >*/
    feq_gen_io_d__116.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__116);
    do_fio(&feq_gen_c_d_1, char5, (ftnlen)5);
    do_fio(&feq_gen_c_d_1, (char *)&power, (ftnlen)sizeof(real));
    e_wsfe();
/*     INPUT THE HEAD SEQUENCE */
/* SOURCE chanrat.for:832 */
/*<       i=1 >*/
    feq_gen_i_d_ = 1;
/* SOURCE chanrat.for:833 */
/*<       huold=-1.0 >*/
    huold = (float)-1.;
/* SOURCE chanrat.for:834 */
/*<   300 continue >*/
L300:
/* SOURCE chanrat.for:835 */
/*<       callinline(stdin,stdout,line) >*/
    inline_(stdin, stdout, line, (ftnlen)80);
/*       Check for optional parameters for definition of */
/*       table optimization. */
/* SOURCE chanrat.for:840 */
/*<       if(line(1:6).eq.'LIPREC')then >*/
    if (s_cmp(line, const_cast<char*>("LIPREC"), (ftnlen)6, (ftnlen)6) == 0) {
/*         The user wants table optimization. */
/* SOURCE chanrat.for:842 */
/*<       read(line,8,err=991)char6,liprec >*/
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
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
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
/* SOURCE chanrat.for:843 */
/*<       write(stdout,79)liprec >*/
	feq_gen_io_d__119.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__119);
	do_fio(&feq_gen_c_d_1, (char *)&liprec, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE chanrat.for:844 */
/*<       callinline(stdin,stdout,line) >*/
	inline_(stdin, stdout, line, (ftnlen)80);
/* SOURCE chanrat.for:847 */
/*<       read(line,8,err=991)char6,minpfd >*/
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
	feq_gen_i_d_1 = do_fio(&feq_gen_c_d_1, char6, (ftnlen)6);
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
/* SOURCE chanrat.for:848 */
/*<       write(stdout,80)minpfd >*/
	feq_gen_io_d__121.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__121);
	do_fio(&feq_gen_c_d_1, (char *)&minpfd, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE chanrat.for:849 */
/*<       else >*/
    } else {
/* SOURCE chanrat.for:850 */
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
/* SOURCE chanrat.for:851 */
/*<       write(stdout,'(1X,F10.2)')huvec(i) >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(1X,F10.2)");
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&huvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE chanrat.for:852 */
/*<       if(huvec(i).le.0.0)then >*/
	if (huvec[feq_gen_i_d_ - 1] <= (float)0.) {
/* SOURCE chanrat.for:853 */
/*<       nhu=i-1 >*/
	    nhu = feq_gen_i_d_ - 1;
/* SOURCE chanrat.for:854 */
/*<       goto310 >*/
	    goto L310;
/* SOURCE chanrat.for:855 */
/*<       else >*/
	} else {
/* SOURCE chanrat.for:856 */
/*<       if(huvec(i).le.huold)then >*/
	    if (huvec[feq_gen_i_d_ - 1] <= huold) {
/* SOURCE chanrat.for:857 */
/*<       write(stdout,99)huvec(i) >*/
		feq_gen_io_d__124.ciunit = *stdout;
		s_wsfe(&feq_gen_io_d__124);
		do_fio(&feq_gen_c_d_1, (char *)&huvec[feq_gen_i_d_ - 1], (ftnlen)sizeof(real));
		e_wsfe();
/* SOURCE chanrat.for:858 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE chanrat.for:859 */
/*<       endif >*/
	    }
/* SOURCE chanrat.for:860 */
/*<       huold=huvec(i) >*/
	    huold = huvec[feq_gen_i_d_ - 1];
/* SOURCE chanrat.for:861 */
/*<       i=i+1 >*/
	    ++feq_gen_i_d_;
/* SOURCE chanrat.for:862 */
/*<       if(i.gt.pmxnhu)then >*/
	    if (feq_gen_i_d_ > 151) {
/* SOURCE chanrat.for:863 */
/*<        >*/
		feq_gen_ci_d_1.cierr = 0;
		feq_gen_ci_d_1.ciunit = *stdout;
		feq_gen_ci_d_1.cifmt = const_cast<char*>("(' *ERR:548* MORE THAN ',I5,' UPSTREAM HEADS')")
			;
		s_wsfe(&feq_gen_ci_d_1);
		do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_151, (ftnlen)sizeof(integer));
		e_wsfe();
/* SOURCE chanrat.for:866 */
/*<       i=pmxnhu >*/
		feq_gen_i_d_ = 151;
/* SOURCE chanrat.for:867 */
/*<       eflag=1 >*/
		*eflag = 1;
/* SOURCE chanrat.for:868 */
/*<       endif >*/
	    }
/* SOURCE chanrat.for:870 */
/*<       endif >*/
	}
/* SOURCE chanrat.for:871 */
/*<       endif >*/
    }
/* SOURCE chanrat.for:872 */
/*<       goto300 >*/
    goto L300;
/* SOURCE chanrat.for:873 */
/*<   310 continue >*/
L310:
/* SOURCE chanrat.for:876 */
/*<       if(nfrac.gt.pmxfrc-1)then >*/
    if (nfrac > 350) {
/* SOURCE chanrat.for:877 */
/*<        >*/
	feq_gen_ci_d_1.cierr = 0;
	feq_gen_ci_d_1.ciunit = *stdout;
	feq_gen_ci_d_1.cifmt = const_cast<char*>("(' *ERR:549* MORE THAN ',I5,' FRACTIONS OF FREE DROP')")
		;
	s_wsfe(&feq_gen_ci_d_1);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_c_d_351, (ftnlen)sizeof(integer));
	e_wsfe();
/* SOURCE chanrat.for:881 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chanrat.for:882 */
/*<       endif >*/
    }
/* SOURCE chanrat.for:884 */
/*<       if(eflag.ne.0)return >*/
    if (*eflag != 0) {
	return 0;
    }
/*     Adjust default value of EPSINT if table optimization */
/*     was selected. */
/* SOURCE chanrat.for:888 */
/*<       if(liprec.gt.0.0)then >*/
    if (liprec > (float)0.) {
/* SOURCE chanrat.for:889 */
/*<        >*/
	if ((feq_gen_d_d_1 = epscom_1.epsint - .1, abs(feq_gen_d_d_1)) / .1 <= 1e-6 || (feq_gen_d_d_2 = 
		epscom_1.epsint - .03048, abs(feq_gen_d_d_2)) / .03048 <= 1e-6) {
/*         Default value.  Therefore make smaller. */
/* SOURCE chanrat.for:892 */
/*<       epsint=epsint/2.d0 >*/
	    epscom_1.epsint /= 2.;
/* SOURCE chanrat.for:893 */
/*<       endif >*/
	}
/* SOURCE chanrat.for:894 */
/*<       endif >*/
    }
/*     CHECK FOR THE CRITICAL FLOW AND CELERITY IN THE TABLE. */
/* SOURCE chanrat.for:896 */
/*<       write(stdout,88) >*/
    feq_gen_io_d__125.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__125);
    e_wsfe();
/* SOURCE chanrat.for:897 */
/*<       callchkcfc(grv,stdout,xstab,wflag) >*/
    chkcfc_(grv, stdout, &xstab, &wflag);
/* SOURCE chanrat.for:900 */
/*<       if(wflag.ne.0)then >*/
    if (wflag != 0) {
/* SOURCE chanrat.for:901 */
/*<       write(stdout,89) >*/
	feq_gen_io_d__127.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__127);
	e_wsfe();
/* SOURCE chanrat.for:902 */
/*<       endif >*/
    }
/*     INPUT OF DATA COMPLETE.  BEGIN THE COMPUTATIONS. */
/* SOURCE chanrat.for:906 */
/*<       write(stdout,95) >*/
    feq_gen_io_d__128.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__128);
    e_wsfe();
/*     SELECT THE POINT DEFINING HEAD FOR THE CHANNEL. */
/* SOURCE chanrat.for:910 */
/*<       zbotl=elev+0.5*botslp*length >*/
    zbotl = static_cast<double>(elev) + static_cast<double>(static_cast<double>(botslp) * (float).5) * length;
/* SOURCE chanrat.for:911 */
/*<       zbotr=elev-0.5*botslp*length >*/
    zbotr = static_cast<double>(elev) - static_cast<double>(static_cast<double>(botslp) * (float).5) * length;
/*     Drop to free flow at zero flow is equal to the drop in */
/*     elevation on the defining plane but only if there is a drop */
/*     in elevation from ups to dns.  Otherwise it is zero. */
/* SOURCE chanrat.for:917 */
/*<       zrhufd=zbotl-zbotr >*/
    zrhufd = static_cast<double>(zbotl) - zbotr;
/* SOURCE chanrat.for:918 */
/*<       if(zrhufd.lt.0.0)zrhufd=0.0 >*/
    if (zrhufd < (float)0.) {
	zrhufd = (float)0.;
    }
/* SOURCE chanrat.for:920 */
/*<       hdatum=max(zbotl,zbotr) >*/
    hdatum = dmax(zbotl,zbotr);
/* SOURCE chanrat.for:922 */
/*<       write(stdout,96)hdatum >*/
    feq_gen_io_d__133.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__133);
    do_fio(&feq_gen_c_d_1, (char *)&hdatum, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE chanrat.for:924 */
/*<       if(liprec.gt.0.0)then >*/
    if (liprec > (float)0.) {
/*       Recompute the head and partial free drop sequence */
/* SOURCE chanrat.for:926 */
/*<        >*/
	feq_gen_chanrat_opt_d_(stdout, &liprec, &minpfd, &hdatum, &zbotl, &zbotr, &
		feq_gen_local_minq_d_, &nhu, huvec, &nfrac, pfdvec, eflag);
/* SOURCE chanrat.for:931 */
/*<       if(eflag.gt.0)then >*/
	if (*eflag > 0) {
/* SOURCE chanrat.for:932 */
/*<       stop'Abnormal stop. Error(s) found.' >*/
	    s_stop(const_cast<char*>("Abnormal stop. Error(s) found."), (ftnlen)30);
/* SOURCE chanrat.for:933 */
/*<       endif >*/
	}
/* SOURCE chanrat.for:934 */
/*<       else >*/
    } else {
/*       COMPUTE THE PROPORTIONS OF FREE DROP */
/* SOURCE chanrat.for:937 */
/*<       do200i=1,nfrac >*/
	feq_gen_i_d_1 = nfrac;
	for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE chanrat.for:938 */
/*<       pfdvec(i)=(float(i-1)/float(nfrac-1))**power >*/
	    feq_gen_d_d_1 = (doublereal) (static_cast<double>((real) (feq_gen_i_d_ - 1)) / (real) (nfrac - 1));
	    feq_gen_d_d_2 = (doublereal) power;
	    pfdvec[feq_gen_i_d_ - 1] = feq::channel_partial_free_drop(feq_gen_i_d_,nfrac,power);
/* SOURCE chanrat.for:940 */
/*<   200 continue >*/
/* L200: */
	}
/* SOURCE chanrat.for:942 */
/*<       endif >*/
    }
/*     Now compute the table using the head and PFD sequences. */
/*     Set the depth ratio to initial value for assistance */
/*     in finding root. */
/* SOURCE chanrat.for:947 */
/*<       yratio=0.5 >*/
    yratio = (float).5;
/*     Clear the sum of interpolation error squared and the quadrature */
/*     span used to compute the root-mean-squared error. */
/* SOURCE chanrat.for:950 */
/*<       siesqr=0.0d0 >*/
    siesqr = 0.;
/* SOURCE chanrat.for:951 */
/*<       qd_span=0.0 >*/
    feq_gen_qd_span_d_ = (float)0.;
/* SOURCE chanrat.for:953 */
/*<       n_gt=0 >*/
    feq_gen_n_gt_d_ = 0;
/* SOURCE chanrat.for:954 */
/*<       n_gt_twice=0 >*/
    feq_gen_n_gt_twice_d_ = 0;
/* SOURCE chanrat.for:955 */
/*<       do2000i=1,nhu >*/
    feq_gen_i_d_1 = nhu;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE chanrat.for:957 */
/*<       hup=huvec(i) >*/
	hup = huvec[feq_gen_i_d_ - 1];
/* SOURCE chanrat.for:959 */
/*<       if(i.eq.1)then >*/
	if (feq_gen_i_d_ == 1) {
/* SOURCE chanrat.for:960 */
/*<       callfrfchn(stdout,hup,hdatum,zbotl,zbotr,yratio,eflag,qfree,fdrop) >*/
	    frfchn_(stdout, &hup, &hdatum, &zbotl, &zbotr, &yratio, eflag, &
		    qfree, &fdrop);
/* SOURCE chanrat.for:964 */
/*<       qmat(i,1)=0.0 >*/
	    qmat[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE chanrat.for:965 */
/*<       qmat(i,nfrac)=qfree >*/
	    qmat[feq_gen_i_d_ + nfrac * 151 - 152] = qfree;
/* SOURCE chanrat.for:966 */
/*<       fdvec(i)=fdrop >*/
	    fdvec[feq_gen_i_d_ - 1] = fdrop;
/* SOURCE chanrat.for:967 */
/*<       else >*/
	} else {
/*         Compute the flow between adjacent heads for error */
/*         estimation. */
/* SOURCE chanrat.for:970 */
/*<       xmid=0.5*(huvec(i-1)+hup) >*/
	    xmid = static_cast<double>((static_cast<double>(huvec[feq_gen_i_d_ - 2]) + hup)) * (float).5;
/* SOURCE chanrat.for:971 */
/*<       callfrfchn(stdout,xmid,hdatum,zbotl,zbotr,yratio,eflag,fmid,fdrop) >*/
	    frfchn_(stdout, &xmid, &hdatum, &zbotl, &zbotr, &yratio, eflag, &
		    fmid, &fdrop);
/* SOURCE chanrat.for:975 */
/*<       callfrfchn(stdout,hup,hdatum,zbotl,zbotr,yratio,eflag,qfree,fdrop) >*/
	    frfchn_(stdout, &hup, &hdatum, &zbotl, &zbotr, &yratio, eflag, &
		    qfree, &fdrop);
/* SOURCE chanrat.for:979 */
/*<       qmat(i,1)=0.0 >*/
	    qmat[feq_gen_i_d_ - 1] = (float)0.;
/* SOURCE chanrat.for:980 */
/*<       qmat(i,nfrac)=qfree >*/
	    qmat[feq_gen_i_d_ + nfrac * 151 - 152] = qfree;
/* SOURCE chanrat.for:981 */
/*<       fdvec(i)=fdrop >*/
	    fdvec[feq_gen_i_d_ - 1] = fdrop;
/* SOURCE chanrat.for:983 */
/*<       if(eflag.ne.0)then >*/
	    if (*eflag != 0) {
/* SOURCE chanrat.for:984 */
/*<       return >*/
		return 0;
/* SOURCE chanrat.for:985 */
/*<       endif >*/
	    }
/* SOURCE chanrat.for:986 */
/*<       rerr=(0.5*(qfree+qmat(i-1,nfrac))-fmid)/fmid >*/
	    rerr = static_cast<double>((static_cast<double>(static_cast<double>((static_cast<double>(qfree) + qmat[feq_gen_i_d_ - 1 + nfrac * 151 - 152])) * (float).5) - 
		    fmid)) / fmid;
/* SOURCE chanrat.for:987 */
/*<       qd_span=qd_span+hup-huvec(i-1) >*/
	    feq_gen_qd_span_d_ = static_cast<double>(static_cast<double>(feq_gen_qd_span_d_) + hup) - huvec[feq_gen_i_d_ - 2];
/* SOURCE chanrat.for:988 */
/*<       siesqr=siesqr+0.6666667*rerr**2*(hup-huvec(i-1)) >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = rerr;
	    siesqr += static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * (float).6666667) * (static_cast<double>(hup) - huvec[feq_gen_i_d_ - 2]);
/* SOURCE chanrat.for:989 */
/*<       write(stdout,60)huvec(i-1),hup,rerr >*/
	    feq_gen_io_d__148.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__148);
	    do_fio(&feq_gen_c_d_1, (char *)&huvec[feq_gen_i_d_ - 2], (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&hup, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&rerr, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE chanrat.for:990 */
/*<       if(abs(rerr).gt.global_error)then >*/
	    if (dabs(rerr) > feq_gen_global_error_d_) {
/* SOURCE chanrat.for:991 */
/*<       global_error=abs(rerr) >*/
		feq_gen_global_error_d_ = dabs(rerr);
/* SOURCE chanrat.for:992 */
/*<       location_hu=i-1 >*/
		feq_gen_location_hu_d_ = feq_gen_i_d_ - 1;
/* SOURCE chanrat.for:993 */
/*<       location_pfd=nfrac >*/
		feq_gen_location_pfd_d_ = nfrac;
/* SOURCE chanrat.for:994 */
/*<       endif >*/
	    }
/* SOURCE chanrat.for:995 */
/*<       if(abs(rerr).gt.liprec.and.liprec.gt.0.0)then >*/
	    if (dabs(rerr) > liprec && liprec > (float)0.) {
/* SOURCE chanrat.for:996 */
/*<       n_gt=n_gt+1 >*/
		++feq_gen_n_gt_d_;
/* SOURCE chanrat.for:997 */
/*<       if(abs(rerr).gt.2.*liprec)then >*/
		if (dabs(rerr) > static_cast<double>(liprec) * (float)2.) {
/* SOURCE chanrat.for:998 */
/*<       n_gt_twice=n_gt_twice+1 >*/
		    ++feq_gen_n_gt_twice_d_;
/* SOURCE chanrat.for:999 */
/*<       endif >*/
		}
/* SOURCE chanrat.for:1000 */
/*<       endif >*/
	    }
/* SOURCE chanrat.for:1001 */
/*<       endif >*/
	}
/* SOURCE chanrat.for:1003 */
/*<       if(sbot.gt.0.0)then >*/
	if (chncom_1.sbot > (float)0.) {
/* SOURCE chanrat.for:1004 */
/*<       write(stdout,51)hup,fdrop,qn >*/
	    feq_gen_io_d__151.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__151);
	    do_fio(&feq_gen_c_d_1, (char *)&hup, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&fdrop, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&chncom_1.qn, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE chanrat.for:1005 */
/*<       write(stdout,82)hdatum+hup >*/
	    feq_gen_io_d__152.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__152);
	    feq_gen_r_d_1 = static_cast<double>(hdatum) + hup;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE chanrat.for:1006 */
/*<       else >*/
	} else {
/* SOURCE chanrat.for:1007 */
/*<       write(stdout,81)hup,fdrop >*/
	    feq_gen_io_d__153.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__153);
	    do_fio(&feq_gen_c_d_1, (char *)&hup, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&fdrop, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE chanrat.for:1008 */
/*<       write(stdout,82)hdatum+hup >*/
	    feq_gen_io_d__154.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__154);
	    feq_gen_r_d_1 = static_cast<double>(hdatum) + hup;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE chanrat.for:1009 */
/*<       endif >*/
	}
/* SOURCE chanrat.for:1011 */
/*<       write(stdout,53) >*/
	feq_gen_io_d__155.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__155);
	e_wsfe();
/* SOURCE chanrat.for:1013 */
/*<       callvar_decimal(qfree,cq) >*/
	feq_gen_var_decimal_d_(&qfree, cq, (ftnlen)8);
/* SOURCE chanrat.for:1015 */
/*<       write(stdout,55)pfdvec(nfrac),hup-fdrop,cq,qerr >*/
	feq_gen_io_d__157.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__157);
	do_fio(&feq_gen_c_d_1, (char *)&pfdvec[nfrac - 1], (ftnlen)sizeof(real));
	feq_gen_r_d_1 = static_cast<double>(hup) - fdrop;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, cq, (ftnlen)8);
	do_fio(&feq_gen_c_d_1, (char *)&chncom_1.qerr, (ftnlen)sizeof(real));
	e_wsfe();
/*       FOR EACH OF THE PARTIAL FREE DROPS(EXCLUDING 0.00 AND 1.0) */
/*       COMPUTE THE FLOW THROUGH THE CHANNEL. */
/*       Initialize the ratio of flow rates used to provide an initial */
/*       estimate for the root. */
/* SOURCE chanrat.for:1022 */
/*<       qratio=0.98 >*/
	qratio = (float).98;
/* SOURCE chanrat.for:1023 */
/*<       do500j=nfrac-1,2,-1 >*/
	for (j = nfrac - 1; j >= 2; --j) {
/*         Compute a value midway between PFD's for error estimation. */
/* SOURCE chanrat.for:1027 */
/*<       drop=fdrop*0.5*(pfdvec(j)+pfdvec(j+1)) >*/
	    drop = static_cast<double>(static_cast<double>(fdrop) * (float).5) * (static_cast<double>(pfdvec[j - 1]) + pfdvec[j]);
/* SOURCE chanrat.for:1028 */
/*<       yr=yl+zbotl-drop-zbotr >*/
	    chncom_1.yr = static_cast<double>(static_cast<double>(static_cast<double>(chncom_1.yl) + zbotl) - drop) - zbotr;
/* SOURCE chanrat.for:1029 */
/*<        >*/
/* Computing MIN */
	    feq_gen_r_d_2 = static_cast<double>(chncom_1.nddabs) + epscom_1.epsarg, feq_gen_r_d_3 = static_cast<double>((static_cast<double>(chncom_1.nddrel) 
		    + epscom_1.epsarg)) * chncom_1.yl;
	    if (chncom_1.sbot > (float)0. && (feq_gen_r_d_1 = static_cast<double>(chncom_1.yl) - 
		    chncom_1.yr, dabs(feq_gen_r_d_1)) < dmin(feq_gen_r_d_2,feq_gen_r_d_3)) {
/*           USE NORMAL FLOW. */
/* SOURCE chanrat.for:1032 */
/*<       fmid=qn >*/
		fmid = chncom_1.qn;
/* SOURCE chanrat.for:1033 */
/*<       else >*/
	    } else {
/*            WRITE(STDOUT,*) 'Compute midway between PFD values' */
/* SOURCE chanrat.for:1035 */
/*<       callsbfchn(stdout,qratio,eflag) >*/
		sbfchn_(stdout, &qratio, eflag);
/* SOURCE chanrat.for:1038 */
/*<       fmid=q >*/
		fmid = chncom_1.q;
/* SOURCE chanrat.for:1039 */
/*<       endif >*/
	    }
/*         Compute the next tabulated value. */
/* SOURCE chanrat.for:1042 */
/*<       drop=fdrop*pfdvec(j) >*/
	    drop = static_cast<double>(fdrop) * pfdvec[j - 1];
/* SOURCE chanrat.for:1043 */
/*<       yr=yl+zbotl-drop-zbotr >*/
	    chncom_1.yr = static_cast<double>(static_cast<double>(static_cast<double>(chncom_1.yl) + zbotl) - drop) - zbotr;
/* SOURCE chanrat.for:1044 */
/*<        >*/
/* Computing MIN */
	    feq_gen_r_d_2 = static_cast<double>(chncom_1.nddabs) + epscom_1.epsarg, feq_gen_r_d_3 = static_cast<double>((static_cast<double>(chncom_1.nddrel) 
		    + epscom_1.epsarg)) * chncom_1.yl;
	    if (chncom_1.sbot > (float)0. && (feq_gen_r_d_1 = static_cast<double>(chncom_1.yl) - 
		    chncom_1.yr, dabs(feq_gen_r_d_1)) < dmin(feq_gen_r_d_2,feq_gen_r_d_3)) {
/*           USE NORMAL FLOW. */
/* SOURCE chanrat.for:1047 */
/*<       q=qn >*/
		chncom_1.q = chncom_1.qn;
/* SOURCE chanrat.for:1048 */
/*<       else >*/
	    } else {
/*           Compute submerged flow.  YL and Q in CHNCOM are at the */
/*           values they last had.  YL remains constant once set by */
/*           free flow computation.  Q will change as we submerge */
/*           the flow. Use the last value as the starting value. */
/*            WRITE(STDOUT,*) ' Compute at tabulated value.' */
/* SOURCE chanrat.for:1054 */
/*<       callsbfchn(stdout,qratio,eflag) >*/
		sbfchn_(stdout, &qratio, eflag);
/* SOURCE chanrat.for:1057 */
/*<       endif >*/
	    }
/* SOURCE chanrat.for:1058 */
/*<       qmat(i,j)=q >*/
	    qmat[feq_gen_i_d_ + j * 151 - 152] = chncom_1.q;
/* SOURCE chanrat.for:1059 */
/*<       rerr=(0.5*(q+qmat(i,j+1))-fmid)/fmid >*/
	    rerr = static_cast<double>((static_cast<double>(static_cast<double>((static_cast<double>(chncom_1.q) + qmat[feq_gen_i_d_ + (j + 1) * 151 - 152])) * (float)
		    .5) - fmid)) / fmid;
/* SOURCE chanrat.for:1060 */
/*<       if(abs(rerr).gt.global_error)then >*/
	    if (dabs(rerr) > feq_gen_global_error_d_) {
/* SOURCE chanrat.for:1061 */
/*<       global_error=abs(rerr) >*/
		feq_gen_global_error_d_ = dabs(rerr);
/* SOURCE chanrat.for:1062 */
/*<       location_hu=i >*/
		feq_gen_location_hu_d_ = feq_gen_i_d_;
/* SOURCE chanrat.for:1063 */
/*<       location_pfd=j >*/
		feq_gen_location_pfd_d_ = j;
/* SOURCE chanrat.for:1064 */
/*<       endif >*/
	    }
/* SOURCE chanrat.for:1065 */
/*<       if(abs(rerr).gt.liprec.and.liprec.gt.0.0)then >*/
	    if (dabs(rerr) > liprec && liprec > (float)0.) {
/* SOURCE chanrat.for:1066 */
/*<       n_gt=n_gt+1 >*/
		++feq_gen_n_gt_d_;
/* SOURCE chanrat.for:1067 */
/*<       if(abs(rerr).gt.2.*liprec)then >*/
		if (dabs(rerr) > static_cast<double>(liprec) * (float)2.) {
/* SOURCE chanrat.for:1068 */
/*<       n_gt_twice=n_gt_twice+1 >*/
		    ++feq_gen_n_gt_twice_d_;
/* SOURCE chanrat.for:1069 */
/*<       endif >*/
		}
/* SOURCE chanrat.for:1070 */
/*<       endif >*/
	    }
/* SOURCE chanrat.for:1071 */
/*<       siesqr=siesqr+0.666667*rerr**2*fdrop*(pfdvec(j+1)-pfdvec(j)) >*/
/* Computing 2nd power */
	    feq_gen_r_d_1 = rerr;
	    siesqr += static_cast<double>(static_cast<double>(static_cast<double>(static_cast<double>(feq_gen_r_d_1) * feq_gen_r_d_1) * (float).666667) * fdrop) * (static_cast<double>(pfdvec[j]) - 
		    pfdvec[j - 1]);
/* SOURCE chanrat.for:1073 */
/*<       qd_span=qd_span+fdrop*(pfdvec(j+1)-pfdvec(j)) >*/
	    feq_gen_qd_span_d_ += static_cast<double>(fdrop) * (static_cast<double>(pfdvec[j]) - pfdvec[j - 1]);
/* SOURCE chanrat.for:1075 */
/*<       callvar_decimal(q,cq) >*/
	    feq_gen_var_decimal_d_(&chncom_1.q, cq, (ftnlen)8);
/* SOURCE chanrat.for:1077 */
/*<       write(stdout,57)pfdvec(j),hup-drop,cq,qerr,rerr >*/
	    feq_gen_io_d__161.ciunit = *stdout;
	    s_wsfe(&feq_gen_io_d__161);
	    do_fio(&feq_gen_c_d_1, (char *)&pfdvec[j - 1], (ftnlen)sizeof(real));
	    feq_gen_r_d_1 = static_cast<double>(hup) - drop;
	    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, cq, (ftnlen)8);
	    do_fio(&feq_gen_c_d_1, (char *)&chncom_1.qerr, (ftnlen)sizeof(real));
	    do_fio(&feq_gen_c_d_1, (char *)&rerr, (ftnlen)sizeof(real));
	    e_wsfe();
/* SOURCE chanrat.for:1080 */
/*<   500 continue >*/
/* L500: */
	}
/* SOURCE chanrat.for:1081 */
/*<  2000 continue >*/
/* L2000: */
    }
/* SOURCE chanrat.for:1083 */
/*<       if(location_pfd.eq.nfrac)then >*/
    if (feq_gen_location_pfd_d_ == nfrac) {
/* SOURCE chanrat.for:1085 */
/*<        >*/
	feq_gen_io_d__162.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__162);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_global_error_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&huvec[feq_gen_location_hu_d_ - 1], (ftnlen)sizeof(real))
		;
	do_fio(&feq_gen_c_d_1, (char *)&huvec[feq_gen_location_hu_d_], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE chanrat.for:1088 */
/*<       else >*/
    } else {
/* SOURCE chanrat.for:1089 */
/*<        >*/
	feq_gen_io_d__163.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__163);
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_global_error_d_, (ftnlen)sizeof(real));
	do_fio(&feq_gen_c_d_1, (char *)&huvec[feq_gen_location_hu_d_ - 1], (ftnlen)sizeof(real))
		;
	do_fio(&feq_gen_c_d_1, (char *)&pfdvec[feq_gen_location_pfd_d_ - 1], (ftnlen)sizeof(
		real));
	do_fio(&feq_gen_c_d_1, (char *)&pfdvec[feq_gen_location_pfd_d_], (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE chanrat.for:1091 */
/*<       endif >*/
    }
/* SOURCE chanrat.for:1093 */
/*<       rms_error=sqrt(siesqr/qd_span) >*/
    feq_gen_rms_error_d_ = sqrt(siesqr / feq_gen_qd_span_d_);
/* SOURCE chanrat.for:1094 */
/*<       write(stdout,62)rms_error >*/
    feq_gen_io_d__165.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__165);
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_rms_error_d_, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE chanrat.for:1095 */
/*<       if(liprec.gt.0.0)then >*/
    if (liprec > (float)0.) {
/* SOURCE chanrat.for:1096 */
/*<       n=nhu-1+nhu*(nfrac-1) >*/
	n = nhu - 1 + nhu * (nfrac - 1);
/* SOURCE chanrat.for:1097 */
/*<       write(stdout,64)float(n_gt)/n,float(n_gt_twice)/n >*/
	feq_gen_io_d__167.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__167);
	feq_gen_r_d_1 = static_cast<double>((real) feq_gen_n_gt_d_) / n;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_1, (ftnlen)sizeof(real));
	feq_gen_r_d_2 = static_cast<double>((real) feq_gen_n_gt_twice_d_) / n;
	do_fio(&feq_gen_c_d_1, (char *)&feq_gen_r_d_2, (ftnlen)sizeof(real));
	e_wsfe();
/* SOURCE chanrat.for:1098 */
/*<       endif >*/
    }
/*     OUTPUT THE TABLE */
/* SOURCE chanrat.for:1101 */
/*<        >*/
    twdout_(stdout, stdtab, &tab, label, &nhu, &nfrac, huvec, fdvec, pfdvec, 
	    qmat, &hdatum, &tabtyp, const_cast<char*>(" CHANRAT"), &zrhufd, zone, hgrid, vdatum, 
	    unitsys, basis, &easting, &northing, eflag, (ftnlen)50, (ftnlen)8,
	     (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8, (ftnlen)8);
/* SOURCE chanrat.for:1109 */
/*<       if(twod_cubic_out.eq.'YES')then >*/
    if (s_cmp(upgrdc_1.feq_gen_twod_cubic_out_d_, const_cast<char*>("YES"), (ftnlen)4, (ftnlen)3) == 0) {
/* SOURCE chanrat.for:1110 */
/*<       verbose=1 >*/
	verbose = 1;
/* SOURCE chanrat.for:1112 */
/*<        >*/
	twodfit_(stdout, &tab, &nhu, &nfrac, huvec, fdvec, pfdvec, qmat, &
		hdatum, &tabtyp, const_cast<char*>(" CHANRAT"), &zrhufd, &verbose, ftp, eflag, &
		ftpup, (ftnlen)8);
/* SOURCE chanrat.for:1118 */
/*<       endif >*/
    }
/*      DO 890 I=1,NHU */
/*        WRITE(STDOUT,68) HUVEC(I), QMAT(I,NFRAC) */
/* 68    FORMAT(F10.6,1PE15.6) */
/* SOURCE chanrat.for:1124 */
/*<   890 continue >*/
/* L890: */
/* SOURCE chanrat.for:1126 */
/*<       return >*/
    return 0;
/* SOURCE chanrat.for:1127 */
/*<   991 continue >*/
L991:
/* SOURCE chanrat.for:1128 */
/*<       write(stdout,*)' *ERR:500* Conversion error in line:' >*/
    feq_gen_io_d__170.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__170);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, const_cast<char*>(" *ERR:500* Conversion error in line:"), (ftnlen)36);
    e_wsle();
/* SOURCE chanrat.for:1129 */
/*<       write(stdout,*)line >*/
    feq_gen_io_d__171.ciunit = *stdout;
    s_wsle(&feq_gen_io_d__171);
    do_lio(&feq_gen_c_d_9, &feq_gen_c_d_1, line, (ftnlen)80);
    e_wsle();
/* SOURCE chanrat.for:1130 */
/*<       stop'Abnormal stop. Errors found.' >*/
    s_stop(const_cast<char*>("Abnormal stop. Errors found."), (ftnlen)28);
/* SOURCE chanrat.for:1131 */
/*<       end >*/
    return 0;
} /* chntab_ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE chanrat.for:1135 */
/*<        >*/
/* Subroutine */ int feq_gen_chanrat_opt_d_(integer *stdout, real *liprec, real *
	minpfd, real *hdatum, real *zbotl, real *zbotr, real *minq, integer *
	nhu, real *feq_storage_huvec, integer *nfrac, real *feq_storage_pfdvec, integer *eflag)
{
    /* Format strings */
    static char fmt_70[] = "(/,\002 CHANRAT will use \002,i5,\002 upstream h\
eads for the 2-D\002,\002 table.\002,/,\002  The maximum estimated relative\
 \002,\002interpolation error is:\002,f10.3)";
    static char fmt_71[] = "(/,\002 CHANRAT will use \002,i5,\002 partial fr\
ee drops for \002,\002the 2-D table.\002,/,\002  The maximum estimated\002\
,\002 relative interpolation error is:\002,f10.3)";
    static char fmt_72[] = "(/,\002 Using upstream head=\002,f8.3,\002 to de\
fine partial\002,\002 free drops.\002)";
    static char fmt_73[] = "(/,\002 Minimum head revised to: \002,f10.3,\002\
 for target flow=\002,f10.3)";
    static char fmt_99[] = "(/,\002 *ERR:635* Interpolation precision tables\
 missing.\002,\002 Check for version\002,/,11x,\002of file: TYPE5.TAB.\002)";

    /* System generated locals */
    integer feq_gen_i_d_1;
    real feq_gen_r_d_1, feq_gen_r_d_2, feq_gen_r_d_3;
    doublereal feq_gen_d_d_1, feq_gen_d_d_2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), e_wsfe();
    double log(doublereal), pow_dd(doublereal *, doublereal *);
    integer do_fio(integer *, char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    doublereal feq_gen_max_rerr_d_;
    extern /* Subroutine */ int ratiopnt_(integer *, doublereal *, doublereal 
	    *, doublereal *);
    real b;
    integer feq_gen_i_d_, j, n, feq_gen_nfrac_old_d_;
    real h1, h2, q1, q2, hup;
#define ftab (feq::BitView<real>(&ftable_1, sizeof(ftable_1)))
#define itab (feq::BitView<integer>(&ftable_1, sizeof(ftable_1)))
    doublereal fvec[151];
    real drop;
    doublereal xvec[151];
#define rtmp (feq::BitView<real>(&ftablea_1.itmp, sizeof(ftablea_1.itmp)))
    doublereal feq_gen_break_points_d_[151];
    char char16[16];
    real dfcol;
    extern /* Subroutine */ int tdlk10_(integer *, integer *, integer *, real 
	    *, real *, real *, real *, real *);
    integer tabgt;
    real qfree;
    integer tablt;
    real dfrow, fdrop;
    extern /* Subroutine */ int sbfchn_(integer *, real *, integer *), 
	    frfchn_(integer *, real *, real *, real *, real *, real *, 
	    integer *, real *, real *);
    real argrat, yratio, qratio;
    extern /* Subroutine */ int findbrk_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *, 
	    doublereal *, integer *, doublereal *);

    /* Fortran I/O blocks */
    static cilist feq_gen_io_d__178 = { 0, 0, 0, fmt_99, 0 };
    static cilist feq_gen_io_d__186 = { 0, 0, 0, fmt_73, 0 };
    static cilist feq_gen_io_d__199 = { 0, 0, 0, fmt_70, 0 };
    static cilist feq_gen_io_d__200 = { 0, 0, 0, fmt_72, 0 };
    static cilist feq_gen_io_d__204 = { 0, 0, 0, fmt_71, 0 };


/*     Compute a sequence for upstream head and partial free drops */
/*     to produce an optimized table for CHANRAT. */
/* SOURCE chanrat.for:1144 */
/*<       implicitnone >*/
/* INCLUDE chanrat.for:1146 */
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
/* SOURCE chanrat.for:1149 */
/*<       integereflag,nfrac,nhu,stdout >*/
/* SOURCE chanrat.for:1150 */
/*<        >*/
/*     + + +DUMMY ARGUMENT DEFINITIONS + + + */
/*     STDOUT - Fortran unit number for user output and messages */
/*     LIPREC - requested linear interpolation precision */
/*     MINPFD - minimum value of partial free drop in the 2-D table */
/*     HDATUM - head datum for the table */
/*     ZBOTL - bottom elev. at left end of channel */
/*     ZBOTR - bottom elev. at right end of channel */
/*     NHU - number of upstream heads. */
/*     HUVEC - upstream head sequence */
/*     NFRAC - number of partial free drops */
/*     PFDVEC - sequence of partial free drops */
/*     EFLAG - error flag */
/*     + + + COMMON BLOCKS + + + */
/* INCLUDE chanrat.for:1168 */
/* SOURCE epscom.cmn:1 */
/*<       integererrknd,inthow >*/
/* SOURCE epscom.cmn:3 */
/*<       doubleprecisionepsint >*/
/* SOURCE epscom.cmn:5 */
/*<       realepsf,epsarg,epsabs,epsdif >*/
/* SOURCE epscom.cmn:7 */
/*<       common/epscom/epsint,epsf,epsarg,errknd,inthow,epsabs,epsdif >*/
/* INCLUDE chanrat.for:1169 */
/*     COMMON BLOCK FOR  CHANNEL RATING */
/* SOURCE chncom.cmn:3 */
/*<       integerxsadr >*/
/* SOURCE chncom.cmn:5 */
/*<       realq,qn,l,sbot,yl,yr,qerr,lstres,nddabs,nddrel,frfac >*/
/* SOURCE chncom.cmn:8 */
/*<        >*/
/* INCLUDE chanrat.for:1170 */
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
/* SOURCE chanrat.for:1174 */
/*<       integeri,j,tablt,tabgt,n,nfrac_old >*/
/* SOURCE chanrat.for:1175 */
/*<        >*/
/* SOURCE chanrat.for:1178 */
/*<       real*8xvec(pmxnhu),fvec(pmxnhu),break_points(pmxnhu),max_rerr >*/
/* SOURCE chanrat.for:1180 */
/*<       characterchar16*16 >*/
/*     Called program units */
/* SOURCE chanrat.for:1183 */
/*<       externalget_internal_tab_number >*/
/*     + + + OUTPUT FORMATS + + + */
/* SOURCE chanrat.for:1186 */
/*<    70  >*/
/* SOURCE chanrat.for:1189 */
/*<    71  >*/
/* SOURCE chanrat.for:1192 */
/*<    72  >*/
/* SOURCE chanrat.for:1194 */
/*<    73  >*/
/* SOURCE chanrat.for:1196 */
/*<    99  >*/
/* *********************************************************************** */
/*     Define the power-function interpolation precision tables. */
/* SOURCE chanrat.for:1200 */
/*<       char16='10001' >*/
    /* Parameter adjustments */
    feq::IndexedPointer<real> pfdvec(feq_storage_pfdvec, 1);

    feq::IndexedPointer<real> huvec(feq_storage_huvec, 1);

    /* Function Body */
/* L70: */
/* L71: */
/* L72: */
/* L73: */
/* L99: */
    s_copy(char16, const_cast<char*>("10001"), (ftnlen)16, (ftnlen)5);
/* SOURCE chanrat.for:1201 */
/*<       callget_internal_tab_number(stdout,char16,eflag,tablt) >*/
    feq_gen_get_internal_tab_number_d_(stdout, char16, eflag, &tablt, (ftnlen)16);
/* SOURCE chanrat.for:1205 */
/*<       tablt=ftpnt(tablt) >*/
    tablt = ftablea_1.ftpnt[tablt - 1];
/* SOURCE chanrat.for:1206 */
/*<       char16='10002' >*/
    s_copy(char16, const_cast<char*>("10002"), (ftnlen)16, (ftnlen)5);
/* SOURCE chanrat.for:1207 */
/*<       callget_internal_tab_number(stdout,char16,eflag,tabgt) >*/
    feq_gen_get_internal_tab_number_d_(stdout, char16, eflag, &tabgt, (ftnlen)16);
/* SOURCE chanrat.for:1212 */
/*<       tabgt=ftpnt(tabgt) >*/
    tabgt = ftablea_1.ftpnt[tabgt - 1];
/* SOURCE chanrat.for:1214 */
/*<       if(tablt.lt.1.or.tabgt.lt.1)then >*/
    if (tablt < 1 || tabgt < 1) {
/* SOURCE chanrat.for:1215 */
/*<       write(stdout,99) >*/
	feq_gen_io_d__178.ciunit = *stdout;
	s_wsfe(&feq_gen_io_d__178);
	e_wsfe();
/* SOURCE chanrat.for:1216 */
/*<       eflag=1 >*/
	*eflag = 1;
/* SOURCE chanrat.for:1217 */
/*<       return >*/
	return 0;
/* SOURCE chanrat.for:1218 */
/*<       endif >*/
    }
/*     Define a better minimum head.  Compute free flow at .5 and 1.0 */
/*     times the user-given minimum head value.  Find the power in */
/*     a simple power-function fit to these two points.    Then compute */
/*     the min-head value that would give a desired minimum flow. */
/*     The desired minimum flow is under user control but has a */
/*     default value. */
/* SOURCE chanrat.for:1226 */
/*<       h2=huvec(1) >*/
    h2 = huvec[1];
/* SOURCE chanrat.for:1227 */
/*<       h1=0.5*h2 >*/
    h1 = static_cast<double>(h2) * (float).5;
/* SOURCE chanrat.for:1228 */
/*<       yratio=0.5 >*/
    yratio = (float).5;
/* SOURCE chanrat.for:1229 */
/*<       callfrfchn(stdout,h1,hdatum,zbotl,zbotr,yratio,eflag,q1,fdrop) >*/
    frfchn_(stdout, &h1, hdatum, zbotl, zbotr, &yratio, eflag, &q1, &fdrop);
/* SOURCE chanrat.for:1233 */
/*<       callfrfchn(stdout,h2,hdatum,zbotl,zbotr,yratio,eflag,q2,fdrop) >*/
    frfchn_(stdout, &h2, hdatum, zbotl, zbotr, &yratio, eflag, &q2, &fdrop);
/*     Compute the power of the simple power function that fits */
/*     these two points (and (0,0) as well). */
/* SOURCE chanrat.for:1240 */
/*<       b=log(q1/q2)/log(h1/h2) >*/
    b = log(static_cast<double>(q1) / q2) / log(static_cast<double>(h1) / h2);
/* SOURCE chanrat.for:1241 */
/*<       h1=h2*(minq/q2)**(1.0/b) >*/
    feq_gen_d_d_1 = (doublereal) (static_cast<double>(*minq) / q2);
    feq_gen_d_d_2 = (doublereal) (static_cast<double>((float)1.) / b);
    h1 = h2 * pow_dd(&feq_gen_d_d_1, &feq_gen_d_d_2);
/* SOURCE chanrat.for:1242 */
/*<       write(stdout,73)h1,minq >*/
    feq_gen_io_d__186.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__186);
    do_fio(&feq_gen_c_d_1, (char *)&h1, (ftnlen)sizeof(real));
    do_fio(&feq_gen_c_d_1, (char *)&(*minq), (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE chanrat.for:1243 */
/*<       huvec(1)=h1 >*/
    huvec[1] = h1;
/*     Save entry value of NFRAC for lower limit of point set. */
/* SOURCE chanrat.for:1247 */
/*<       nfrac_old=nfrac >*/
    feq_gen_nfrac_old_d_ = *nfrac;
/*     Define the point set for computing the free flows to fit with */
/*     a cubic spline. Find the argument ratio, ARGRAT, for a power */
/*     of 3.5, close to the maximum for CHANRAT. */
/* SOURCE chanrat.for:1253 */
/*<       calltdlk10(stdout,tabgt,10,3.5,liprec,argrat,dfrow,dfcol) >*/
    tdlk10_(stdout, &tabgt, &feq_gen_c_d_10, &c_b249, liprec, &argrat, &dfrow, &dfcol);
/*     Use the maximum and minimum head  and ARGRAT to */
/*     compute the number of heads to use and compute a new head */
/*     sequence. */
/* SOURCE chanrat.for:1260 */
/*<       n=int(log(huvec(nhu)/huvec(1))/log(argrat)+1.0)+1 >*/
    n = (integer) (log(static_cast<double>(huvec[*nhu]) / huvec[1]) / log(argrat) + (float)1.) + 1;
/* SOURCE chanrat.for:1261 */
/*<       if(n.lt.nfrac_old)n=nfrac_old >*/
    if (n < feq_gen_nfrac_old_d_) {
	n = feq_gen_nfrac_old_d_;
    }
/* SOURCE chanrat.for:1262 */
/*<       callratiopnt(n,dble(huvec(1)),dble(huvec(nhu)),xvec) >*/
    feq_gen_d_d_1 = (doublereal) huvec[1];
    feq_gen_d_d_2 = (doublereal) huvec[*nhu];
    ratiopnt_(&n, &feq_gen_d_d_1, &feq_gen_d_d_2, xvec);
/* SOURCE chanrat.for:1265 */
/*<       nhu=n >*/
    *nhu = n;
/*     Now compute the free flows for this sequence of heads. */
/* SOURCE chanrat.for:1267 */
/*<       yratio=0.5 >*/
    yratio = (float).5;
/* SOURCE chanrat.for:1268 */
/*<       do110i=1,nhu >*/
    feq_gen_i_d_1 = *nhu;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE chanrat.for:1270 */
/*<       hup=real(xvec(i)) >*/
	hup = (real) xvec[feq_gen_i_d_ - 1];
/* SOURCE chanrat.for:1272 */
/*<       callfrfchn(stdout,hup,hdatum,zbotl,zbotr,yratio,eflag,qfree,fdrop) >*/
	frfchn_(stdout, &hup, hdatum, zbotl, zbotr, &yratio, eflag, &qfree, &
		fdrop);
/* SOURCE chanrat.for:1277 */
/*<       if(eflag.ne.0)then >*/
	if (*eflag != 0) {
/* SOURCE chanrat.for:1278 */
/*<       return >*/
	    return 0;
/* SOURCE chanrat.for:1279 */
/*<       endif >*/
	}
/* SOURCE chanrat.for:1280 */
/*<       fvec(i)=dble(qfree) >*/
	fvec[feq_gen_i_d_ - 1] = (doublereal) qfree;
/* SOURCE chanrat.for:1281 */
/*<   110 continue >*/
/* L110: */
    }
/*     Try to find improved breakpoints. */
/* SOURCE chanrat.for:1285 */
/*<        >*/
    feq_gen_d_d_1 = (doublereal) (*liprec);
    findbrk_(stdout, nhu, xvec, fvec, &feq_gen_d_d_1, &feq_gen_c_d_1, &feq_gen_c_d_1, &n, feq_gen_break_points_d_,
	     eflag, &feq_gen_max_rerr_d_);
/* SOURCE chanrat.for:1290 */
/*<       if(eflag.ne.0)then >*/
    if (*eflag != 0) {
/* SOURCE chanrat.for:1291 */
/*<       return >*/
	return 0;
/* SOURCE chanrat.for:1292 */
/*<       endif >*/
    }
/* SOURCE chanrat.for:1293 */
/*<       nhu=n >*/
    *nhu = n;
/* SOURCE chanrat.for:1294 */
/*<       do120i=1,n >*/
    feq_gen_i_d_1 = n;
    for (feq_gen_i_d_ = 1; feq_gen_i_d_ <= feq_gen_i_d_1; ++feq_gen_i_d_) {
/* SOURCE chanrat.for:1295 */
/*<       huvec(i)=real(break_points(i)) >*/
	huvec[feq_gen_i_d_] = (real) feq_gen_break_points_d_[feq_gen_i_d_ - 1];
/* SOURCE chanrat.for:1296 */
/*<   120 continue >*/
/* L120: */
    }
/* SOURCE chanrat.for:1298 */
/*<       write(stdout,70)nhu,max_rerr >*/
    feq_gen_io_d__199.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__199);
    do_fio(&feq_gen_c_d_1, (char *)&(*nhu), (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_max_rerr_d_, (ftnlen)sizeof(doublereal));
    e_wsfe();
/*     Select a head near the middle of the vector and compute the */
/*     free and submerged flows for that head to define the */
/*     basis for finding good breakpoints for the partial free */
/*     drops. */
/* SOURCE chanrat.for:1303 */
/*<       i=int(real(2*nhu)/3.+1.) >*/
    feq_gen_i_d_ = (integer) (static_cast<double>(static_cast<double>((real) (*nhu << 1)) / (float)3.) + (float)1.);
/* SOURCE chanrat.for:1304 */
/*<       if(i.gt.nhu)i=nhu >*/
    if (feq_gen_i_d_ > *nhu) {
	feq_gen_i_d_ = *nhu;
    }
/* SOURCE chanrat.for:1305 */
/*<       hup=huvec(i) >*/
    hup = huvec[feq_gen_i_d_];
/* SOURCE chanrat.for:1306 */
/*<       write(stdout,72)hup >*/
    feq_gen_io_d__200.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__200);
    do_fio(&feq_gen_c_d_1, (char *)&hup, (ftnlen)sizeof(real));
    e_wsfe();
/* SOURCE chanrat.for:1307 */
/*<       callfrfchn(stdout,hup,hdatum,zbotl,zbotr,yratio,eflag,qfree,fdrop) >*/
    frfchn_(stdout, &hup, hdatum, zbotl, zbotr, &yratio, eflag, &qfree, &
	    fdrop);
/* SOURCE chanrat.for:1311 */
/*<       if(eflag.ne.0)then >*/
    if (*eflag != 0) {
/* SOURCE chanrat.for:1312 */
/*<       return >*/
	return 0;
/* SOURCE chanrat.for:1313 */
/*<       endif >*/
    }
/*     Define the sequence of partial free drops to use. */
/* SOURCE chanrat.for:1318 */
/*<       calltdlk10(stdout,tablt,10,0.5,liprec,argrat,dfrow,dfcol) >*/
    tdlk10_(stdout, &tablt, &feq_gen_c_d_10, &c_b258, liprec, &argrat, &dfrow, &dfcol);
/*     Use the maximum PFD, 1.0, and the MINPFD to compute */
/*     the number of PFD's. */
/* SOURCE chanrat.for:1325 */
/*<       n=int(log(1.0/minpfd)/log(argrat)+1.0)+1 >*/
    n = (integer) (log(static_cast<double>((float)1.) / *minpfd) / log(argrat) + (float)1.) + 1;
/* SOURCE chanrat.for:1326 */
/*<       if(n.lt.nfrac_old)n=nfrac_old >*/
    if (n < feq_gen_nfrac_old_d_) {
	n = feq_gen_nfrac_old_d_;
    }
/* SOURCE chanrat.for:1327 */
/*<       callratiopnt(n,dble(minpfd),1.d0,xvec) >*/
    feq_gen_d_d_1 = (doublereal) (*minpfd);
    ratiopnt_(&n, &feq_gen_d_d_1, &c_b259, xvec);
/* SOURCE chanrat.for:1330 */
/*<       qratio=0.98 >*/
    qratio = (float).98;
/* SOURCE chanrat.for:1331 */
/*<       do140j=n-1,1,-1 >*/
    for (j = n - 1; j >= 1; --j) {
/* SOURCE chanrat.for:1332 */
/*<       drop=fdrop*real(xvec(j)) >*/
	drop = static_cast<double>(fdrop) * (real) xvec[j - 1];
/* SOURCE chanrat.for:1333 */
/*<       yr=yl+zbotl-drop-zbotr >*/
	chncom_1.yr = static_cast<double>(static_cast<double>(static_cast<double>(chncom_1.yl) + *zbotl) - drop) - *zbotr;
/* SOURCE chanrat.for:1334 */
/*<        >*/
/* Computing MIN */
	feq_gen_r_d_2 = static_cast<double>(chncom_1.nddabs) + epscom_1.epsarg, feq_gen_r_d_3 = static_cast<double>((static_cast<double>(chncom_1.nddrel) + 
		epscom_1.epsarg)) * chncom_1.yl;
	if (chncom_1.sbot > (float)0. && (feq_gen_r_d_1 = static_cast<double>(chncom_1.yl) - chncom_1.yr, 
		dabs(feq_gen_r_d_1)) < dmin(feq_gen_r_d_2,feq_gen_r_d_3)) {
/*         USE NORMAL FLOW. */
/* SOURCE chanrat.for:1337 */
/*<       fvec(j)=dble(qn) >*/
	    fvec[j - 1] = (doublereal) chncom_1.qn;
/* SOURCE chanrat.for:1338 */
/*<       else >*/
	} else {
/*         COMPUTE SUBMERGED FLOW.  YL AND Q IN CHNCOM ARE AT THE */
/*         VALUES THEY LAST HAD.  YL REMAINS CONSTANT ONCE SET BY */
/*         FREE FLOW COMPUTATION.  Q WILL CHANGE AS WE SUBMERGE */
/*         THE FLOW. USE THE LAST VALUE AS THE STARTING VALUE. */
/* SOURCE chanrat.for:1344 */
/*<       callsbfchn(stdout,qratio,eflag) >*/
	    sbfchn_(stdout, &qratio, eflag);
/* SOURCE chanrat.for:1347 */
/*<       fvec(j)=dble(q) >*/
	    fvec[j - 1] = (doublereal) chncom_1.q;
/* SOURCE chanrat.for:1348 */
/*<       endif >*/
	}
/* SOURCE chanrat.for:1350 */
/*<   140 continue >*/
/* L140: */
    }
/* SOURCE chanrat.for:1351 */
/*<       fvec(n)=qfree >*/
    fvec[n - 1] = qfree;
/*     Try to find improved breakpoints. */
/* SOURCE chanrat.for:1355 */
/*<        >*/
    feq_gen_d_d_1 = (doublereal) (*liprec);
    findbrk_(stdout, &n, xvec, fvec, &feq_gen_d_d_1, &feq_gen_c_d_2, &feq_gen_c_d_2, nfrac, 
	    feq_gen_break_points_d_, eflag, &feq_gen_max_rerr_d_);
/* SOURCE chanrat.for:1359 */
/*<       if(eflag.ne.0)then >*/
    if (*eflag != 0) {
/* SOURCE chanrat.for:1360 */
/*<       return >*/
	return 0;
/* SOURCE chanrat.for:1361 */
/*<       endif >*/
    }
/* SOURCE chanrat.for:1362 */
/*<       pfdvec(1)=0.0 >*/
    pfdvec[1] = (float)0.;
/* SOURCE chanrat.for:1363 */
/*<       nfrac=nfrac+1 >*/
    ++(*nfrac);
/* SOURCE chanrat.for:1364 */
/*<       do150j=2,nfrac >*/
    feq_gen_i_d_1 = *nfrac;
    for (j = 2; j <= feq_gen_i_d_1; ++j) {
/* SOURCE chanrat.for:1365 */
/*<       pfdvec(j)=break_points(j-1) >*/
	pfdvec[j] = feq_gen_break_points_d_[j - 2];
/* SOURCE chanrat.for:1366 */
/*<   150 continue >*/
/* L150: */
    }
/* SOURCE chanrat.for:1367 */
/*<       write(stdout,71)nfrac,max_rerr >*/
    feq_gen_io_d__204.ciunit = *stdout;
    s_wsfe(&feq_gen_io_d__204);
    do_fio(&feq_gen_c_d_1, (char *)&(*nfrac), (ftnlen)sizeof(integer));
    do_fio(&feq_gen_c_d_1, (char *)&feq_gen_max_rerr_d_, (ftnlen)sizeof(doublereal));
    e_wsfe();
/* SOURCE chanrat.for:1369 */
/*<       return >*/
    return 0;
/* SOURCE chanrat.for:1370 */
/*<       end >*/
} /* chanrat_opt__ */

#undef rtmp
#undef itab
#undef ftab





/* SOURCE chanrat.for:1377 */
/*<       subroutineset_chnrt_item_defaults() >*/
/* Subroutine */ int feq_gen_set_chnrt_item_defaults_d_()
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

/*     Set the default values in the vectors used to */
/* SOURCE chanrat.for:1380 */
/*<       implicitnone >*/
/* INCLUDE chanrat.for:1381 */
/* SOURCE chnrtitm.cmn:1 */
/*<       integermaxr_chnrtitm,maxc_chnrtitm,maxdp_chnrtitm >*/
/* SOURCE chnrtitm.cmn:2 */
/*<       parameter(maxr_chnrtitm=7,maxc_chnrtitm=7,maxdp_chnrtitm=6) >*/
/* SOURCE chnrtitm.cmn:3 */
/*<       integerchnrtitmitab(maxr_chnrtitm) >*/
/* SOURCE chnrtitm.cmn:4 */
/*<       realchnrtitmftab(maxr_chnrtitm) >*/
/* SOURCE chnrtitm.cmn:5 */
/*<       real*8chnrtitmdtab(maxdp_chnrtitm) >*/
/* SOURCE chnrtitm.cmn:6 */
/*<       character*64chnrtitmctab(maxc_chnrtitm) >*/
/* SOURCE chnrtitm.cmn:8 */
/*<       common/chnrtitm_com/chnrtitmdtab,chnrtitmitab,chnrtitmftab >*/
/* SOURCE chnrtitm.cmn:10 */
/*<       common/chnrtitm_comc/chnrtitmctab >*/
/* *********************************************************************** */
/*     Default for: TABID */
/* SOURCE chanrat.for:1385 */
/*<       chnrtitmctab(1)='    ' >*/
    s_copy(feq_gen_chnrtitm_comc_d_1.chnrtitmctab, const_cast<char*>("    "), (ftnlen)64, (ftnlen)4);
/*     Default for: TABLE - note # is ignored in the standard scanner */
/* SOURCE chanrat.for:1387 */
/*<       chnrtitmctab(2)='    ' >*/
    s_copy(feq_gen_chnrtitm_comc_d_1.chnrtitmctab + 64, const_cast<char*>("    "), (ftnlen)64, (ftnlen)4);
/*     Default for: TYPE */
/* SOURCE chanrat.for:1389 */
/*<       chnrtitmitab(1)=13 >*/
    feq_gen_chnrtitm_com_d_1.chnrtitmitab[0] = 13;
/*     Default for: ERRKND-absolute error */
/* SOURCE chanrat.for:1391 */
/*<       chnrtitmitab(2)=0 >*/
    feq_gen_chnrtitm_com_d_1.chnrtitmitab[1] = 0;
/*     Default for: INTHOW - simpson adaptive-only option */
/* SOURCE chanrat.for:1393 */
/*<       chnrtitmitab(3)=1 >*/
    feq_gen_chnrtitm_com_d_1.chnrtitmitab[2] = 1;
/*     Default for: EPSINT - special value to signal need for default assignment later */
/* SOURCE chanrat.for:1395 */
/*<       chnrtitmftab(4)=-1.0 >*/
    feq_gen_chnrtitm_com_d_1.chnrtitmftab[3] = (float)-1.;
/*     Default for: NDDABS - special value to signal need for default assignment later */
/* SOURCE chanrat.for:1397 */
/*<       chnrtitmftab(5)=-1.0 >*/
    feq_gen_chnrtitm_com_d_1.chnrtitmftab[4] = (float)-1.;
/*     Default for: NDDREL */
/* SOURCE chanrat.for:1399 */
/*<       chnrtitmftab(6)=0.005 >*/
    feq_gen_chnrtitm_com_d_1.chnrtitmftab[5] = (float).005;
/*     Default for: LOCAL_MINQ */
/* SOURCE chanrat.for:1401 */
/*<       chnrtitmftab(7)=0.0 >*/
    feq_gen_chnrtitm_com_d_1.chnrtitmftab[6] = (float)0.;
/*     Default for: ZONE */
/* SOURCE chanrat.for:1403 */
/*<       chnrtitmctab(3)='NONE' >*/
    s_copy(feq_gen_chnrtitm_comc_d_1.chnrtitmctab + 128, const_cast<char*>("NONE"), (ftnlen)64, (ftnlen)4)
	    ;
/*     Default for: HGRID */
/* SOURCE chanrat.for:1405 */
/*<       chnrtitmctab(4)='NONE' >*/
    s_copy(feq_gen_chnrtitm_comc_d_1.chnrtitmctab + 192, const_cast<char*>("NONE"), (ftnlen)64, (ftnlen)4)
	    ;
/*     Default for: VDATUM */
/* SOURCE chanrat.for:1407 */
/*<       chnrtitmctab(5)='NONE' >*/
    s_copy(feq_gen_chnrtitm_comc_d_1.chnrtitmctab + 256, const_cast<char*>("NONE"), (ftnlen)64, (ftnlen)4)
	    ;
/*     Default for: UNITSYS */
/* SOURCE chanrat.for:1409 */
/*<       chnrtitmctab(6)='NONE' >*/
    s_copy(feq_gen_chnrtitm_comc_d_1.chnrtitmctab + 320, const_cast<char*>("NONE"), (ftnlen)64, (ftnlen)4)
	    ;
/*     Default for: BASIS */
/* SOURCE chanrat.for:1411 */
/*<       chnrtitmctab(7)='NONE' >*/
    s_copy(feq_gen_chnrtitm_comc_d_1.chnrtitmctab + 384, const_cast<char*>("NONE"), (ftnlen)64, (ftnlen)4)
	    ;
/*     Default for: EASTING */
/* SOURCE chanrat.for:1413 */
/*<       chnrtitmdtab(5)=-33d6 >*/
    feq_gen_chnrtitm_com_d_1.chnrtitmdtab[4] = -3.3e7;
/*     Default for: NORTHING */
/* SOURCE chanrat.for:1415 */
/*<       chnrtitmdtab(6)=-33d6 >*/
    feq_gen_chnrtitm_com_d_1.chnrtitmdtab[5] = -3.3e7;
/* SOURCE chanrat.for:1418 */
/*<       return >*/
    return 0;
/* SOURCE chanrat.for:1419 */
/*<       end >*/
} /* set_chnrt_item_defaults__ */




/* SOURCE chanrat.for:1423 */
/*<        >*/
/* Subroutine */ int feq_gen_set_chnrt_items_d_(integer *eflag, integer *tab, integer *
	feq_gen_type_d_, integer *errknd, integer *inthow, real *epsint, real *nddabs, 
	real *nddrel, real *feq_gen_local_minq_d_, char *zone, char *hgrid, char *
	vdatum, char *unitsys, char *basis, doublereal *easting, doublereal *
	northing, ftnlen zone_len, ftnlen hgrid_len, ftnlen vdatum_len, 
	ftnlen unitsys_len, ftnlen basis_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int feq_gen_get_internal_tab_number_d_(integer *, char *, 
	    integer *, integer *, ftnlen);
    char key1[16], key2[16];

/*     Set items in CHANRAT */
/*     All values not set explicitly by user are at their default value. */
/* SOURCE chanrat.for:1432 */
/*<       implicitnone >*/
/* SOURCE chanrat.for:1434 */
/*<       integertab,type,getq,gety2,eflag,errknd,inthow >*/
/* SOURCE chanrat.for:1435 */
/*<       realepsint,nddabs,nddrel,local_minq >*/
/* SOURCE chanrat.for:1436 */
/*<       real*8easting,northing >*/
/* SOURCE chanrat.for:1437 */
/*<       character*8zone,hgrid,vdatum,unitsys,basis >*/
/*     Local */
/* SOURCE chanrat.for:1441 */
/*<       character*16key1,key2 >*/
/* INCLUDE chanrat.for:1443 */
/* SOURCE chnrtitm.cmn:1 */
/*<       integermaxr_chnrtitm,maxc_chnrtitm,maxdp_chnrtitm >*/
/* SOURCE chnrtitm.cmn:2 */
/*<       parameter(maxr_chnrtitm=7,maxc_chnrtitm=7,maxdp_chnrtitm=6) >*/
/* SOURCE chnrtitm.cmn:3 */
/*<       integerchnrtitmitab(maxr_chnrtitm) >*/
/* SOURCE chnrtitm.cmn:4 */
/*<       realchnrtitmftab(maxr_chnrtitm) >*/
/* SOURCE chnrtitm.cmn:5 */
/*<       real*8chnrtitmdtab(maxdp_chnrtitm) >*/
/* SOURCE chnrtitm.cmn:6 */
/*<       character*64chnrtitmctab(maxc_chnrtitm) >*/
/* SOURCE chnrtitm.cmn:8 */
/*<       common/chnrtitm_com/chnrtitmdtab,chnrtitmitab,chnrtitmftab >*/
/* SOURCE chnrtitm.cmn:10 */
/*<       common/chnrtitm_comc/chnrtitmctab >*/
/* INCLUDE chanrat.for:1444 */
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
/* *********************************************************************** */
/*     Set the table id.  There  are two strings allowed as the variable name: */
/*     TABID or TABLE */
/* SOURCE chanrat.for:1448 */
/*<       key1=chnrtitmctab(1) >*/
    s_copy(key1, feq_gen_chnrtitm_comc_d_1.chnrtitmctab, (ftnlen)16, (ftnlen)64);
/* SOURCE chanrat.for:1449 */
/*<       key2=chnrtitmctab(2) >*/
    s_copy(key2, feq_gen_chnrtitm_comc_d_1.chnrtitmctab + 64, (ftnlen)16, (ftnlen)64);
/* SOURCE chanrat.for:1450 */
/*<       if(key1.ne.' ')then >*/
    if (s_cmp(key1, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/* SOURCE chanrat.for:1451 */
/*<       callget_internal_tab_number(std6,key1,eflag,tab) >*/
	feq_gen_get_internal_tab_number_d_(&feq_gen_stdun_com_d_1.std6, key1, eflag, tab, (
		ftnlen)16);
/* SOURCE chanrat.for:1455 */
/*<       elseif(key2.ne.' ')then >*/
    } else if (s_cmp(key2, const_cast<char*>(" "), (ftnlen)16, (ftnlen)1) != 0) {
/* SOURCE chanrat.for:1456 */
/*<       callget_internal_tab_number(std6,key2,eflag,tab) >*/
	feq_gen_get_internal_tab_number_d_(&feq_gen_stdun_com_d_1.std6, key2, eflag, tab, (
		ftnlen)16);
/* SOURCE chanrat.for:1460 */
/*<       else >*/
    } else {
/* SOURCE chanrat.for:1461 */
/*<       tab=0 >*/
	*tab = 0;
/* SOURCE chanrat.for:1462 */
/*<       endif >*/
    }
/*     Set the value for TYPE */
/* SOURCE chanrat.for:1465 */
/*<       type=chnrtitmitab(1) >*/
    *feq_gen_type_d_ = feq_gen_chnrtitm_com_d_1.chnrtitmitab[0];
/*     Set the value for errknd */
/* SOURCE chanrat.for:1467 */
/*<       errknd=chnrtitmitab(2) >*/
    *errknd = feq_gen_chnrtitm_com_d_1.chnrtitmitab[1];
/*     Set the value for inthow */
/* SOURCE chanrat.for:1469 */
/*<       inthow=chnrtitmitab(3) >*/
    *inthow = feq_gen_chnrtitm_com_d_1.chnrtitmitab[2];
/*     Set the value for epsint */
/* SOURCE chanrat.for:1471 */
/*<       epsint=chnrtitmftab(4) >*/
    *epsint = feq_gen_chnrtitm_com_d_1.chnrtitmftab[3];
/*     Set the value for nddabs */
/* SOURCE chanrat.for:1473 */
/*<       nddabs=chnrtitmftab(5) >*/
    *nddabs = feq_gen_chnrtitm_com_d_1.chnrtitmftab[4];
/*     Set the value for nddrel */
/* SOURCE chanrat.for:1475 */
/*<       nddrel=chnrtitmftab(6) >*/
    *nddrel = feq_gen_chnrtitm_com_d_1.chnrtitmftab[5];
/*     Set the value for the local MINQ */
/* SOURCE chanrat.for:1477 */
/*<       local_minq=chnrtitmftab(7) >*/
    *feq_gen_local_minq_d_ = feq_gen_chnrtitm_com_d_1.chnrtitmftab[6];
/*     Set the value for ZONE */
/* SOURCE chanrat.for:1479 */
/*<       zone=chnrtitmctab(3) >*/
    s_copy(zone, feq_gen_chnrtitm_comc_d_1.chnrtitmctab + 128, (ftnlen)8, (ftnlen)64);
/*     Set the value for HGRID */
/* SOURCE chanrat.for:1481 */
/*<       hgrid=chnrtitmctab(4) >*/
    s_copy(hgrid, feq_gen_chnrtitm_comc_d_1.chnrtitmctab + 192, (ftnlen)8, (ftnlen)64);
/*     Set the value for VDATUM */
/* SOURCE chanrat.for:1483 */
/*<       vdatum=chnrtitmctab(5) >*/
    s_copy(vdatum, feq_gen_chnrtitm_comc_d_1.chnrtitmctab + 256, (ftnlen)8, (ftnlen)64)
	    ;
/*     Set the value for UNITSYS */
/* SOURCE chanrat.for:1485 */
/*<       unitsys=chnrtitmctab(6) >*/
    s_copy(unitsys, feq_gen_chnrtitm_comc_d_1.chnrtitmctab + 320, (ftnlen)8, (ftnlen)
	    64);
/*     Set the value for BASIS */
/* SOURCE chanrat.for:1487 */
/*<       basis=chnrtitmctab(7) >*/
    s_copy(basis, feq_gen_chnrtitm_comc_d_1.chnrtitmctab + 384, (ftnlen)8, (ftnlen)64);
/*     Set the value for EASTING */
/* SOURCE chanrat.for:1489 */
/*<       easting=chnrtitmdtab(5) >*/
    *easting = feq_gen_chnrtitm_com_d_1.chnrtitmdtab[4];
/*     Set the value for NORTHING */
/* SOURCE chanrat.for:1491 */
/*<       northing=chnrtitmdtab(6) >*/
    *northing = feq_gen_chnrtitm_com_d_1.chnrtitmdtab[5];
/* SOURCE chanrat.for:1493 */
/*<       return >*/
    return 0;
/* SOURCE chanrat.for:1494 */
/*<       end >*/
} /* set_chnrt_items__ */




/* SOURCE chanrat.for:1499 */
/*<       subroutineget_chnrt_items(stdin,stdout,eflag) >*/
/* Subroutine */ int feq_gen_get_chnrt_items_d_(integer *stdin, integer *stdout, 
	integer *eflag)
{
    /* Initialized data */

    static char feq_gen_symbol_table_d_[16*17+1] = "TABID           TABLE           T\
YPE            ERRKND          INTHOW          EPSINT          NDDABS       \
   NDDREL          MINQ            LABEL           ZONE            HGRID    \
       VDATUM          UNITSYS         EASTING         NORTHING        BASIS\
           ";
    static integer group[17] = { 1,1,0,0,0,0,0,0,0,2,1,1,1,1,0,0,1 };
    static integer feq_gen_group_index_d_[17] = { 1,2,1,2,3,4,5,6,7,0,3,4,5,6,9,11,7 };
    static integer feq_gen_response_type_d_[17] = { 4,4,1,1,1,2,2,2,2,0,4,4,4,4,3,3,4 }
	    ;
    static integer feq_gen_convert_rule_d_[17] = { 1,1,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1 };

    extern /* Subroutine */ int feq_gen_set_chnrt_item_defaults_d_();
    integer feq_gen_max_line_d_;
    extern /* Subroutine */ int feq_gen_get_named_items_d_(integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    char *, integer *, integer *, integer *, char *, integer *, real *
	    , doublereal *, char *, integer *, ftnlen, ftnlen, ftnlen);

/*     Get the table id and various options for CHANRAT command */
/* SOURCE chanrat.for:1504 */
/*<       implicitnone >*/
/* INCLUDE chanrat.for:1506 */
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
/* SOURCE chanrat.for:1508 */
/*<       integerstdin,stdout,eflag >*/
/* INCLUDE chanrat.for:1510 */
/* SOURCE chnrtitm.cmn:1 */
/*<       integermaxr_chnrtitm,maxc_chnrtitm,maxdp_chnrtitm >*/
/* SOURCE chnrtitm.cmn:2 */
/*<       parameter(maxr_chnrtitm=7,maxc_chnrtitm=7,maxdp_chnrtitm=6) >*/
/* SOURCE chnrtitm.cmn:3 */
/*<       integerchnrtitmitab(maxr_chnrtitm) >*/
/* SOURCE chnrtitm.cmn:4 */
/*<       realchnrtitmftab(maxr_chnrtitm) >*/
/* SOURCE chnrtitm.cmn:5 */
/*<       real*8chnrtitmdtab(maxdp_chnrtitm) >*/
/* SOURCE chnrtitm.cmn:6 */
/*<       character*64chnrtitmctab(maxc_chnrtitm) >*/
/* SOURCE chnrtitm.cmn:8 */
/*<       common/chnrtitm_com/chnrtitmdtab,chnrtitmitab,chnrtitmftab >*/
/* SOURCE chnrtitm.cmn:10 */
/*<       common/chnrtitm_comc/chnrtitmctab >*/
/*     Local */
/*     + + + LOCAL PARAMETERS + + + */
/* SOURCE chanrat.for:1515 */
/*<        >*/
/* SOURCE chanrat.for:1518 */
/*<        >*/
/* SOURCE chanrat.for:1522 */
/*<       integermax_line >*/
/* SOURCE chanrat.for:1525 */
/*<       externalget_named_items,set_chnrt_item_defaults >*/
/*     + + + SAVED VALUES + + + */
/* SOURCE chanrat.for:1528 */
/*<        >*/
/* SOURCE chanrat.for:1530 */
/*<       charactersymbol_table(n_symbol)*16 >*/
/* SOURCE chanrat.for:1532 */
/*<       savesymbol_table,group,response_type,convert_rule,group_index >*/
/* *********************************************************************** */
/*     Set Defaults */
/* SOURCE chanrat.for:1535 */
/*<        >*/
/* SOURCE chanrat.for:1540 */
/*<       datagroup/char,char,7*numeric,nxtblk,4*char,2*numeric,char/ >*/
/* SOURCE chanrat.for:1543 */
/*<       datagroup_index/1,2,1,2,3,4,5,6,7,0,3,4,5,6,9,11,7/ >*/
/* SOURCE chanrat.for:1546 */
/*<        >*/
/* SOURCE chanrat.for:1550 */
/*<        >*/
/* SOURCE chanrat.for:1556 */
/*<       callset_chnrt_item_defaults() >*/
    feq_gen_set_chnrt_item_defaults_d_();
/* SOURCE chanrat.for:1558 */
/*<       max_line=4 >*/
    feq_gen_max_line_d_ = 4;
/* SOURCE chanrat.for:1559 */
/*<        >*/
    feq_gen_get_named_items_d_(stdin, stdout, &feq_gen_max_line_d_, &feq_gen_c_d_17, group, 
	    feq_gen_response_type_d_, feq_gen_convert_rule_d_, feq_gen_group_index_d_, feq_gen_symbol_table_d_, &
	    feq_gen_c_d_7, &feq_gen_c_d_6, &feq_gen_c_d_7, const_cast<char*>("CHANRAT items"), feq_gen_chnrtitm_com_d_1.chnrtitmitab,
	     feq_gen_chnrtitm_com_d_1.chnrtitmftab, feq_gen_chnrtitm_com_d_1.chnrtitmdtab, 
	    feq_gen_chnrtitm_comc_d_1.chnrtitmctab, eflag, (ftnlen)16, (ftnlen)13, (
	    ftnlen)64);
/* SOURCE chanrat.for:1566 */
/*<       return >*/
    return 0;
/* SOURCE chanrat.for:1568 */
/*<       end >*/
} /* get_chnrt_items__ */

#ifdef __cplusplus
	}
#endif
